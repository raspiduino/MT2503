#include "kal_release.h"
#include "touch_panel.h"
#include "us_timer.h"
#include "gpio_sw.h"
#include <Capacitive_TP_Goodix_GT818.h>
#include <Capacitive_TP_I2C.h>
#include "fs_type.h"
#include "fs_func.h"
#include "app_buff_alloc.h"
#include "kal_trace.h"

//static kal_uint8 inbuf[256];
//static kal_uint8 outbuf[256];
//static kal_char  dbgbuf[256];
static kal_uint8 *inbuf;
static kal_uint8 *outbuf;
static kal_char  *dbgbuf;

#define  guitar_i2c_address 0xBA

#define TPD_CONFIG_REG_BASE           0x6A2
#define TPD_VERSION_INFO_REG          0x713
#define TPD_NVRAM_LEN                 0x0FF0   // nvram total space

#define TPD_CHIP_VERSION_C_FIRMWARE_BASE 0x5A
#define TPD_CHIP_VERSION_D1_FIRMWARE_BASE 0x7A
#define TPD_CHIP_VERSION_E_FIRMWARE_BASE 0x9A
#define TPD_CHIP_VERSION_D2_FIRMWARE_BASE 0xBA

#define NVRAM_BOOT_SECTOR_LEN   0x0100 // boot sector
#define NVRAM_UPDATE_START_ADDR 0x4100
#define I2C_FRAME_MAX_LENGTH    6   //IIC buffer length

#define BIT_NVRAM_LOCK              2
#define REG_WCHWK              0x1303
#define BIT_STD_STD_PIN        0
#define BIT_STD_I2C            1
#define BIT_STD_GPIO0          2
#define BIT_STD_GPIO_EDG       3
#define REG_I2CSHDN            0x1404
#define REG_NVRCS              0x1201
#define BIT_NVRAM_STROE        0
#define BIT_NVRAM_RECALL       1
#define BIT_NVRAM_LOCK         2
#define REG_ANY                0x0000
#define REG_ADDRESSED          0x00FF
#define MAX_BUFFER_LEN         10
#define MAX_NVRAM_SIZE         4096


#ifdef __MTK_TARGET__
#define TPD_DOWNLOADER_DEBUG(format,args...) kal_prompt_trace(MOD_TP_TASK, format, ##args)
#define TPD_DOWNLOADER_LOG(format,args...) kal_prompt_trace( MOD_TP_TASK, format, ##args)
#else
#define TPD_DOWNLOADER_DEBUG(format,__VA_ARGS__) do {} while (0);
#define TPD_DOWNLOADER_LOG(format,__VA_ARGS__) do {} while (0);
#endif

//#define GT818_FW_STRING L"C:\\GT818\\fwupd.bin"
#define GT818_FW_STRING  "ctp_firmware_rusklmeoxkwjadfjnklruo3"

#define GT818_SET_INT_PIN(output) DclGPIO_Control(int_handle, (output?GPIO_CMD_WRITE_HIGH:GPIO_CMD_WRITE_LOW), NULL);

#define ctp_i2c_receive_ext(a,b,c,d)  ctp_i2c_receive( CTP_SLAVE_ADDR, b, c, d)
#define ctp_i2c_send_ext(a,b,c,d)      ctp_i2c_send( CTP_SLAVE_ADDR, b, c, d)

kal_bool gt818_i2c_read(kal_uint8 id, kal_uint16 reg, kal_uint8 *data, kal_uint16 len)
{
    kal_bool ret;
    
    //ctp_i2c_send_ext(id, CTP_HANDSHAKING_START_REG, NULL, 0);
    ret = ctp_i2c_receive_ext(id, reg, data, len );
   // ctp_i2c_send_ext(id, CTP_HANDSHAKING_END_REG, NULL, 0);
    
    return ret;
}

kal_bool gt818_i2c_write(kal_uint8 id, kal_uint16 reg, kal_uint8 *data, kal_uint16 len)
{
    kal_bool ret;
    
    //ctp_i2c_send_ext(id, CTP_HANDSHAKING_START_REG, NULL, 0);
    ret = ctp_i2c_send_ext(id, reg, data, len);
    //ctp_i2c_send_ext(id, CTP_HANDSHAKING_END_REG, NULL, 0);
    
    return ret;
}

extern const char gpio_ctp_eint_pin;
extern const char gpio_ctp_reset_pin;

static DCL_HANDLE rst_handle, int_handle;
static kal_uint8 downloader_errno = 0;

typedef struct 
{
    kal_int32 magic_number_1;
    kal_int32 magic_number_2;
    kal_uint16 version;
    kal_uint16 length;
    kal_uint16 checksum;
    kal_uint8 data;
} ctp_firmware_info_t;

enum
{
    TPD_GT818_VERSION_B,
    TPD_GT818_VERSION_C,
    TPD_GT818_VERSION_D1,
    TPD_GT818_VERSION_E,
    TPD_GT818_VERSION_D2
};

static kal_uint16 get_chip_version( kal_uint16 sw_ver )
{
 if ( sw_ver < TPD_CHIP_VERSION_C_FIRMWARE_BASE )
        return TPD_GT818_VERSION_B;
    else if ( sw_ver < TPD_CHIP_VERSION_D1_FIRMWARE_BASE )
        return TPD_GT818_VERSION_C;
    else if(sw_ver < TPD_CHIP_VERSION_E_FIRMWARE_BASE)
        return TPD_GT818_VERSION_D1;
    else if(sw_ver < TPD_CHIP_VERSION_D2_FIRMWARE_BASE)
        return TPD_GT818_VERSION_E;
    else
        return TPD_GT818_VERSION_D2;}

static kal_uint8 is_equal( kal_uint8 *src , kal_uint8 *dst , kal_int32 len )
{
    kal_int32 i;
    
    for( i = 0 ; i < len ; i++ )
    {
        if ( src[i] != dst[i] )
        {
            TPD_DOWNLOADER_DEBUG("[%x:%x]", src[i], dst[i]);
            return 0;
        }
    }
    
    return 1;
}

static kal_uint8 gt818_nvram_store( void )
{
    kal_uint8 ret;
    int i = 0;
        
do_store:        
    ret = gt818_i2c_read( guitar_i2c_address, REG_NVRCS, inbuf, 1 );
    
    if ( ret == 0 )
    {
        return 0;
    }
    
    if ( ( inbuf[0] & BIT_NVRAM_LOCK ) == BIT_NVRAM_LOCK )
    {
        return 0;
    }
    
    outbuf[0] = (1<<BIT_NVRAM_STROE);		//store command
	  	    
    ret = gt818_i2c_write( guitar_i2c_address, REG_NVRCS, outbuf, 1 );
    
    if ( i < 300 )
    {
        i++;
        goto do_store;
    }
        
            
    return ret;
}

static kal_uint8 gt818_nvram_recall( void )
{
    kal_uint8 ret;
    
    ret = gt818_i2c_read( guitar_i2c_address, REG_NVRCS, inbuf, 1 );
    
    if ( ret == 0 )
    {
        return 0;
    }
    
    if ( ( inbuf[0]&BIT_NVRAM_LOCK) == BIT_NVRAM_LOCK )
    {
        return 0;
    }
    
    outbuf[0] = ( 1 << BIT_NVRAM_RECALL );		//recall command
    ret = gt818_i2c_write( guitar_i2c_address , REG_NVRCS , outbuf, 1);
    return ret;
}

static kal_uint8 gt818_reset( void )
{
    kal_uint8 ret = 1;

    outbuf[0] = 1;
    outbuf[1] = 1;

    DclGPIO_Control(rst_handle, GPIO_CMD_WRITE_HIGH, NULL);
    kal_sleep_task(5);
    DclGPIO_Control(rst_handle, GPIO_CMD_WRITE_LOW, NULL);
    kal_sleep_task(5);
    DclGPIO_Control(rst_handle, GPIO_CMD_WRITE_HIGH, NULL);
    kal_sleep_task(120);

search_i2c:
    //gt818_i2c_write( guitar_i2c_address, 0x00FF, outbuf, 1 );

    //kal_sleep_task( 12 );

    gt818_i2c_read( guitar_i2c_address, 0x00FF, inbuf, 1 );

    if ( inbuf[0] != 0x55 )
    {
        TPD_DOWNLOADER_DEBUG("res %x", inbuf[0] );
        kal_sleep_task(10);
        goto search_i2c;
    }

    outbuf[0]=0;
    gt818_i2c_write( guitar_i2c_address, 0x00FF, outbuf, 1 );

    TPD_DOWNLOADER_DEBUG("Detect address %x", guitar_i2c_address );
    kal_sleep_task(120);
    return ret;	
}

static kal_uint8 gt818_reset2( void )
{
    kal_uint8 ret = 1;

    outbuf[0] = 1;
    outbuf[1] = 1;

    DclGPIO_Control(rst_handle, GPIO_CMD_WRITE_HIGH, NULL);
    kal_sleep_task(5);
    DclGPIO_Control(rst_handle, GPIO_CMD_WRITE_LOW, NULL);
    kal_sleep_task(5);
    DclGPIO_Control(rst_handle, GPIO_CMD_WRITE_HIGH, NULL);
    kal_sleep_task(120);

search_i2c2:
    ret = gt818_i2c_read( guitar_i2c_address, 0x00FF, inbuf, 1 );

    if ( ret == 0 )
    {
        TPD_DOWNLOADER_DEBUG("res %x", inbuf[0] );
        kal_sleep_task(10);
        goto search_i2c2;
    }

    TPD_DOWNLOADER_DEBUG("Detect address %x", guitar_i2c_address );
    kal_sleep_task(120);
    return ret;	
}



static kal_uint8 gt818_set_address_2( kal_uint8 addr )
{
    kal_uint8 in;
    kal_int32 i;

    for ( i = 0 ; i < 12 ; i++ )
    {
        if ( gt818_i2c_read( addr, REG_ANY, &in, 1 ) )
        {
            TPD_DOWNLOADER_DEBUG("Got response");
            return 1;
        }
        TPD_DOWNLOADER_DEBUG("wait for retry");
        //msleep(50);
    } 
    return 0;
}

static kal_uint8 gt818_update_firmware( kal_uint8 *nvram, kal_uint16 length )
{
    kal_uint8 ret,err,retry_time;
    kal_uint16 cur_code_addr;
    kal_uint16 cur_frame_num, total_frame_num;
	
    if( length > TPD_NVRAM_LEN - NVRAM_BOOT_SECTOR_LEN )
    {
        TPD_DOWNLOADER_DEBUG("length too big %d %d", length, TPD_NVRAM_LEN - NVRAM_BOOT_SECTOR_LEN );
        downloader_errno = 1;
        return 0;
    }
    	  
    retry_time = 5;
             
    TPD_DOWNLOADER_DEBUG("Do update start");  
    do
    {
        err = 0;

        //ret = gt818_i2c_write( guitar_i2c_address, NVRAM_UPDATE_START_ADDR, nvram, length );
        ret = gt818_i2c_write( guitar_i2c_address, NVRAM_UPDATE_START_ADDR, nvram, length );	

        if ( ret == 0 )
        {
            TPD_DOWNLOADER_DEBUG("write fail");
            err = 1;
        }
			
    } while ( err == 1 && (--retry_time) > 0 );
    //} while ( 1 );        		        

    if( err == 1 )
    {
        downloader_errno = 2;
        TPD_DOWNLOADER_DEBUG("write nvram fail");
        return 0;
    }
    
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/////////////////////kuuga change start////////////////////////
    ret = gt818_nvram_store();
    
    kal_sleep_task( 10);

    if( ret == 0 )
    {
        downloader_errno = 4;
        TPD_DOWNLOADER_DEBUG("nvram store fail \n\r");
        return 0;
    }
    
    ret = gt818_nvram_recall();

    kal_sleep_task( 10 );
    
    if( ret == 0 )
    {
        downloader_errno = 5;
        TPD_DOWNLOADER_DEBUG("nvram recall fail \n\r");
        return 0;
    }
//////////////////////end///////////////////////////////

    total_frame_num = length;

    for ( cur_frame_num = 0 ; cur_frame_num < total_frame_num ; cur_frame_num++ )        // read out all the code
    {

        cur_code_addr = NVRAM_UPDATE_START_ADDR + cur_frame_num;
        retry_time=5;
   
        do
        {
            err = 0;
            ret = gt818_i2c_read( guitar_i2c_address, cur_code_addr, inbuf, 1);
        
            if ( ret == 0 )
            {
                err = 1;
            }
        
            if( is_equal( &nvram[cur_frame_num], inbuf, 1 ) == 0 )
            {
                err = 1;
            }
        } while ( err == 1 && (--retry_time) > 0 );
    
        if( err == 1 )
        {
            break;
        }    
    }

#endif
    TPD_DOWNLOADER_DEBUG("Do update end");  
    
    if( err == 1 )
    {
        downloader_errno = 3;
        TPD_DOWNLOADER_DEBUG("nvram validate fail");
        return 0;
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    return 1;
}

static kal_uint8 gt818_update_proc( kal_uint8 *nvram, kal_uint16 length )
{
    kal_uint8 ret;
    kal_uint8 error = 0;
    ctp_info_t ctp_info;
    
    GT818_SET_INT_PIN( 0 );
    kal_sleep_task( 5 );

    ret = gt818_reset();

    if ( ret == 0 )
    {
        error = 1;
        downloader_errno = 6;
        TPD_DOWNLOADER_DEBUG("reset fail");
        goto end;
    }
    ret = gt818_set_address_2( guitar_i2c_address );

    if ( ret == 0 )
    {
        error = 1;
        downloader_errno = 7;
        TPD_DOWNLOADER_DEBUG("set address fail");
        goto end;
    }

    ret = gt818_update_firmware( nvram, length );

    if ( ret == 0 )
    {
        error=1;
        downloader_errno = 8;
        TPD_DOWNLOADER_DEBUG("firmware update fail");
        goto end;
    }

end:
    GT818_SET_INT_PIN( 1 );
    kal_sleep_task( 1 );

    ret = gt818_reset2();

    if ( ret == 0 )
    {
        error=1;
        downloader_errno = 9;
        TPD_DOWNLOADER_DEBUG("final reset fail");
        goto end;
    }
    if ( error == 1 )
    {
        return 0; 
    }
    
    while ( gt818_i2c_read( guitar_i2c_address, TPD_VERSION_INFO_REG, (kal_uint8 *)&ctp_info, sizeof( ctp_info_t ) ) == 0 ) ;

    TPD_DOWNLOADER_LOG( "version %x %x", ctp_info.version_1, ctp_info.version_2 );

    //while ( gt818_i2c_write( guitar_i2c_address, TPD_CONFIG_REG_BASE, cfg_data, sizeof(cfg_data)) == 0 );
    
    return 1;
}
static kal_int32 gt818_downloader_probe( kal_uint16 cur_ver, kal_uint8 *firmware_ptr )
{
	  //TODO: process file
    //struct file *fp;
    kal_uint32 rlen;	
    kal_uint16 length;
    kal_uint16 retry = 0;
    FS_HANDLE handle;
    int ret = 0;
    ctp_firmware_info_t *fw_info = (ctp_firmware_info_t *)firmware_ptr;    
    unsigned char *data_ptr = &(fw_info->data);
    kal_wchar   CTP_FIRMWARE_PATH[64];
    kal_int16   drv_letter;
    kal_bool    delete_firmware = KAL_FALSE;
    
    TPD_DOWNLOADER_LOG("gt818_downloader_probe");
    
    length = 0;

    drv_letter = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_I_SYSTEM | FS_DRIVE_V_NORMAL); // phone memory
    kal_wsprintf( CTP_FIRMWARE_PATH, "%c:\\%s", drv_letter, GT818_FW_STRING );
    ret = FS_CheckFile(CTP_FIRMWARE_PATH);
    if(ret < 0)
    {
        drv_letter = FS_GetDrive( FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE );  //SD Card
        kal_wsprintf( CTP_FIRMWARE_PATH, "%c:\\%s", drv_letter, GT818_FW_STRING );
    }
    else
    {
        delete_firmware = KAL_TRUE; // need delete firmware after update
    }

    handle = FS_Open( CTP_FIRMWARE_PATH, FS_READ_ONLY );

    if ( handle >= 0 ) // file system first
    {        	
        do
        {
            rlen  = 0;

            ret = FS_Read( handle, &data_ptr[length], 256, &rlen );

            length += rlen;

            if ( rlen != 256 )
            {
                TPD_DOWNLOADER_LOG("read complete");
                break;
            } 
            else
            {
                TPD_DOWNLOADER_DEBUG("read len %d", rlen);
            }

        } while ( 1 );

        FS_Close( handle );
    }
    else
    {
        const int MAGIC_NUMBER_1 = 0x4D454449;
        const int MAGIC_NUMBER_2 = 0x4154454B;
        unsigned short checksum = 0;
        int i;
        
        TPD_DOWNLOADER_DEBUG( "magic number %x %x", fw_info->magic_number_1, fw_info->magic_number_2 );
        TPD_DOWNLOADER_DEBUG( "magic number %x %x", MAGIC_NUMBER_1, MAGIC_NUMBER_2 );
        TPD_DOWNLOADER_DEBUG( "current version %x, target verion %x", cur_ver, fw_info->version );
        TPD_DOWNLOADER_DEBUG( "size %d", fw_info->length );
        TPD_DOWNLOADER_DEBUG( "checksum %d", fw_info->checksum );
        
        if ( fw_info->magic_number_1 != MAGIC_NUMBER_1 && fw_info->magic_number_2 != MAGIC_NUMBER_2 )
        {
            TPD_DOWNLOADER_DEBUG("Magic number not match");
            goto exit_downloader;
        }
       // if ( cur_ver >= fw_info->version )
      //  {
      //      TPD_DOWNLOADER_DEBUG("No need to upgrade");
     //       goto exit_downloader;
       // }
#if 0       
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

	if( ((cur_ver&0xff) > (fw_info->version&0xff)) )   // current low byte higher than back-up low byte		
	{		        			
		TPD_DOWNLOADER_DEBUG("No need to upgrade\n");        			
		goto exit_downloader;			 		
	}	
	else if(((cur_ver&0xff) == (fw_info->version&0xff)))		
		{			
			if(((cur_ver&0xff00) < (fw_info->version&0xff00)))				
			{					
				TPD_DOWNLOADER_DEBUG("Need to upgrade\n");				
			}			
			else				
			{					
				TPD_DOWNLOADER_DEBUG("No need to upgrade\n");        				
				goto exit_downloader;				
			}		
		}	
		else		
		{			
			TPD_DOWNLOADER_DEBUG("Need to upgrade\n");		
		}

		
        // check if it is the same chip version
        if ( get_chip_version( cur_ver&0xff ) != get_chip_version( fw_info->version&0xff ) )
        {
            TPD_DOWNLOADER_DEBUG("Chip version incorrect");
            goto exit_downloader;        
        }
        
        for ( i = 0 ; i < fw_info->length ; i++ )
            checksum += data_ptr[i];
        
        checksum = checksum%0xFFFF;

        if ( checksum != fw_info->checksum )
        {
            ASSERT(0);
            TPD_DOWNLOADER_DEBUG("Checksum not match 0x%04X", checksum);
            goto exit_downloader;
        }

        length = fw_info->length;

    }
 
    while ( gt818_update_proc( data_ptr, length ) == 0 && retry < 2 ) retry++;

    if ( (handle >= 0)  && delete_firmware) //delete firmware when firmware in phone memory
        FS_Delete( CTP_FIRMWARE_PATH );
    //free_ctrl_buffer( nvram );
    ret = 1;

exit_downloader:

    return ret;
}

kal_int32 init_gt818_download_module( kal_uint16 cur_ver, kal_uint8 *firmware_ptr )
{
    kal_int32 ret = 0;
//	DCL_HANDLE eint_handle;

    outbuf = (kal_uint8 *)get_ctrl_buffer( MAX_BUFFER_LEN );
    inbuf  = (kal_uint8 *)get_ctrl_buffer( MAX_BUFFER_LEN );
    dbgbuf = (kal_char *)get_ctrl_buffer( MAX_BUFFER_LEN );
    
    
    if ( ( outbuf == NULL ) ||
         ( inbuf == NULL ) ||
         ( dbgbuf == NULL ) )
    {
        EXT_ASSERT(0, (kal_uint32)outbuf, (kal_uint32)inbuf, (kal_uint32)dbgbuf);
        return 0;
    }

    TPD_DOWNLOADER_LOG( "init_module() called");
 
    //rst_handle = DclGPIO_Open(DCL_GPIO, GPIO_CTP_SHUTDN_PIN);
    //int_handle = DclGPIO_Open(DCL_GPIO, GPIO_CTP_INT_PIN);
    int_handle = DclGPIO_Open(DCL_GPIO, gpio_ctp_eint_pin);
    rst_handle = DclGPIO_Open(DCL_GPIO, gpio_ctp_reset_pin);
	
    DclGPIO_Control(rst_handle, GPIO_CMD_SET_MODE_0, NULL);
    DclGPIO_Control(int_handle, GPIO_CMD_SET_MODE_0, NULL);
    DclGPIO_Control(int_handle, GPIO_CMD_SET_DIR_OUT, NULL);
    ret = gt818_downloader_probe( cur_ver, firmware_ptr );

 //  eint_handle = DclGPIO_Open(DCL_GPIO, gpio_ctp_eint_pin);
    DclGPIO_Control(int_handle, GPIO_CMD_SET_DIR_IN, NULL);
    DclGPIO_Control(int_handle, GPIO_CMD_SET_MODE_1, NULL);
    //DclGPIO_Control(int_handle, GPIO_CMD_SET_DIR_IN, NULL);
    //DclGPIO_Control(int_handle, GPIO_CMD_SET_MODE_1, NULL);
   // DclGPIO_Control(int_handle, GPIO_CMD_WRITE_HIGH, NULL);

   // DclGPIO_Control(rst_handle, GPIO_CMD_WRITE_HIGH, NULL);
   // kal_sleep_task(5);
   // DclGPIO_Control(rst_handle, GPIO_CMD_WRITE_LOW, NULL);
  //  kal_sleep_task(5);
  //  DclGPIO_Control(rst_handle, GPIO_CMD_WRITE_HIGH, NULL);
    kal_sleep_task(120);

    free_ctrl_buffer( outbuf );
    free_ctrl_buffer( inbuf );
    free_ctrl_buffer( dbgbuf );

    if ( downloader_errno )
        EXT_ASSERT( 0, downloader_errno, 0, 0 );

    return ret;
}
 
