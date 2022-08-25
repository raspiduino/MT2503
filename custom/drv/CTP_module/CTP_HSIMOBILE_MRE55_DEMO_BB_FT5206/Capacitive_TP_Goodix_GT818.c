/*****************************************************************************
*  Copyright Statement: 
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   Capacitive_TP_Goodix_GT818.c
 *
 *
 * Description:
 * ------------
 *   Capacitive Touch Panel I2C read/write Driver
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#include "kal_release.h"
#include "touch_panel.h"
#include "Capacitive_TP_Goodix_GT818.h"
#include "Capacitive_TP_I2C.h"
#include "us_timer.h"
#include "dcl.h"
#include "eint.h"
#include "kal_trace.h"

	
#ifdef __MTK_TARGET__
#include "GT818_firmware.h"
#endif


#if !defined(IC_MODULE_TEST)
extern kal_uint32 /*lint -e(526)*/L1I_GetTimeStamp(void);
#endif

#define TPD_RESET_ISSUE_WORDAROUND
//#define TPD_COF_MODULE
//#define TPD_BYTE_READ_WORKAROUND
#define CTP_MAX_RESET_COUNT 3

#ifdef __MTK_TARGET__
#define CTP_DEBUG(format,args...) do {} while (0);
#else
#define CTP_DEBUG(format, __VA_ARGS__) do {} while (0);
#endif

extern const char gpio_ctp_power_enable_pin;
extern const char gpio_ctp_i2c_sda_pin;
extern const char gpio_ctp_i2c_scl_pin;
extern const char gpio_ctp_eint_pin;
extern const char gpio_ctp_reset_pin;

extern kal_int32 init_gt818_download_module( kal_uint16 cur_ver, kal_uint8 *firmware_ptr );
extern void ctp_i2c_configure(kal_uint32 slave_addr, kal_uint32 speed);

kal_uint32 CTP_DELAY_TIME_GT818 = 400;

CTP_custom_information_struct  ctp_custom_information_def_gt818 = 
{
    "Goodix ",
    "GT818",
    "UNKNOWN ",	
};


#define USE_SW_I2C


//ÄÁ¶« sesorID 0
#define SENSOR_ID_MUTTO               0x00

static kal_uint8 cfg_data_mutto[] ={	
	0x12,0x10,0x0E,0x0C,0x0A,0x08,0x06,0x04,
	0x02,0x00,0x02,0x22,0x12,0x22,0x22,0x22,	
	0x32,0x22,0x42,0x22,0x52,0x22,0x62,0x22,	
	0x72,0x22,0xF2,0x22,0xE2,0x22,0xD2,0x22,	
	0xC2,0x22,0xB2,0x22,0xA2,0x22,0x92,0x22,	
	0x82,0x22,0x17,0x03,0x48,0x48,0x48,0x1A,
	0x1A,0x1A,0x10,0x0F,0x0A,0x40,0x28,0x05,
	0x03,0x3C,0x05,0xE0,0x01,0x20,0x03,0x00,
	0x00,0x54,0x57,0x58,0x5A,0x00,0x00,0x23,
	0x14,0x25,0x05,0x00,0x00,0x00,0x00,0x00,
	0x14,0x10,0xAC,0x03,0x00,0x00,0x00,0x00,
	0x00,0x00,0x20,0x40,0x70,0x90,0x0C,0x40,
	0x30,0x30,0x20,0x00,0x00,0x00,0x00,0x00,
	0x00,0x01
};

//Íú²© sensorID 2
#define SENSOR_ID_WANGBO              0x02

static kal_uint8 cfg_data_wangbo[] ={
	0x12,0x10,0x0E,0x0C,0x0A,0x08,0x06,0x04,
	0x02,0x00,0xE1,0x11,0xD1,0x11,0xC1,0x11,
	0xB1,0x11,0xA1,0x11,0x91,0x11,0x81,0x11,
	0x71,0x11,0xF1,0x11,0x61,0x11,0x51,0x11,
	0x41,0x11,0x31,0x11,0x21,0x11,0x11,0x11,
	0x01,0x11,0x07,0x03,0x30,0x30,0x30,0x23,
	0x23,0x23,0x10,0x0F,0x0A,0x40,0x30,0x05,
	0x03,0x00,0x05,0xE0,0x01,0x20,0x03,0x00,
	0x00,0x56,0x54,0x5A,0x58,0x00,0x00,0x14,
	0x14,0x25,0x06,0x00,0x00,0x00,0x00,0x00,
	0x14,0x10,0xAC,0x03,0x00,0x00,0x00,0x00,
	0x00,0x00,0x1B,0x43,0x6D,0x95,0x0B,0x40,
	0x30,0x28,0x20,0x00,0x00,0x00,0x00,0x00,
	0x00,0x01
};
  
#define TPD_WARP_X( x ) ( x )              
#define TPD_WARP_Y( y )	( y  )
              

#ifndef USE_SW_I2C
#define USE_SW_I2C
#endif



void ctp_i2c_init( void )
{
    ctp_i2c_configure( 0, 0 );
}

kal_bool CTP_I2C_write_byte(kal_uint16 ucBufferIndex, kal_uint8 pucData)
{
    return ctp_i2c_send( CTP_SLAVE_ADDR, ucBufferIndex, &pucData, 1);
}

#define CTP_I2C_read(a,b,c) ctp_i2c_receive( CTP_SLAVE_ADDR, a, b, c)
#define CTP_I2C_send(a,b,c) ctp_i2c_send( CTP_SLAVE_ADDR, a, b, c)


static void ctp_goodix_gt818_power(kal_bool ON)
{
    static kal_bool power_status = KAL_FALSE;
    DCL_HANDLE enable_handle;

    CTP_DEBUG(  __func__ );
#if 1
	kal_prompt_trace(MOD_ENG, "enter ctp_goodix_gt818_power ");
    if(ON == power_status)
        return;

    power_status = ON;

    enable_handle = DclGPIO_Open(DCL_GPIO, gpio_ctp_power_enable_pin);
    DclGPIO_Control(enable_handle, GPIO_CMD_SET_MODE_0, NULL);
    DclGPIO_Control(enable_handle, GPIO_CMD_SET_DIR_OUT, NULL);

    if ( ON )
    {
        DclGPIO_Control(enable_handle, GPIO_CMD_WRITE_HIGH, NULL);
    }
    else
    {
        DclGPIO_Control(enable_handle, GPIO_CMD_WRITE_LOW, NULL);
    }   
    #endif
}

//If controller has the register store these informations
//Read out the informations from controller through I2C
static kal_bool ctp_goodix_gt818_get_information(ctp_info_t *ctp_info)
{
    kal_bool ret;

    CTP_I2C_send( CTP_HANDSHAKING_START_REG, NULL, 0 );
    
#ifdef TPD_BYTE_READ_WORKAROUND
    int i;
    kal_uint8 *ptr = (kal_uint8 *)ctp_info;

    for ( i = 0 ; i < sizeof(ctp_info_t) ; i++ )
        CTP_I2C_read( CTP_VERSION_INFO_REG+i, (kal_uint8 *)&ptr[i], 1 );
#else
    ret = CTP_I2C_read( CTP_VERSION_INFO_REG, (kal_uint8 *)ctp_info, sizeof( ctp_info_t ) );
#endif
  
    CTP_I2C_send( CTP_HANDSHAKING_END_REG, NULL, 0 );
    
    CTP_DEBUG( "%s %2x%2x%2x%2x%2x%2x", __func__,ctp_info->version_1, ctp_info->version_2,ctp_info->vendor_id_1,ctp_info->vendor_id_2,ctp_info->product_id_1,ctp_info->product_id_2);

 kal_prompt_trace(MOD_ENG,  " %2x %2x%2x%2x%2x%2x", ctp_info->version_1, ctp_info->version_2,ctp_info->vendor_id_1,ctp_info->vendor_id_2,ctp_info->product_id_1,ctp_info->product_id_2);

    ctp_custom_information_def_gt818.FirmwareVersion[0] = ctp_info->version_1;
    ctp_custom_information_def_gt818.FirmwareVersion[1] = ctp_info->version_2;
    
    return ret;
}

static kal_bool ctp_goodix_gt818_set_configuration( void )
{
    kal_bool ret;
    kal_uint8 *cfg_data;
	kal_uint8 lvalue = 0;
	kal_uint8 sensor_ID = 0;

	CTP_I2C_send( CTP_HANDSHAKING_START_REG, NULL, 0 );
	CTP_I2C_read( CTP_TOUCH_CHI_ID_REG_BASE, &lvalue, 1);
	CTP_I2C_send( CTP_HANDSHAKING_END_REG, NULL, 0 );

	sensor_ID = lvalue & 0x03;

	switch (sensor_ID)
	{
		case SENSOR_ID_MUTTO:
			cfg_data = cfg_data_mutto;
			break;
		case SENSOR_ID_WANGBO:
			cfg_data = cfg_data_wangbo;
			break;
		default:
			cfg_data =cfg_data_mutto;
			break;
	}
	
   // cfg_data[55]|=0x08;//for modify  eint direction 
    #if 0 //for modify of  lcd size 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
    CTP_I2C_send( CTP_HANDSHAKING_START_REG, NULL, 0 );
    ret = CTP_I2C_send( CTP_CONFIG_REG_BASE, cfg_data, 106 );
    CTP_I2C_send( CTP_HANDSHAKING_END_REG, NULL, 0 );
    
    return ret;
}

static Touch_Panel_PenState_enum ctp_goodix_gt818_hisr(void)
{
    kal_uint8 lvalue;

    CTP_I2C_read(CTP_TOUCH_INFO_REG_BASE, &lvalue, 1);
    
    kal_prompt_trace(MOD_ENG, "ctp_goodix_gt818_hisr info %d", lvalue);

    if(lvalue & CTP_STAT_NUMBER_TOUCH)
        return DOWN;
    else
        return UP;
}
void GT818_Delayms(kal_uint16 data)
{
	kal_uint32 i;
	while(data--)
	{
		for(i=0;i<220000;i++){}// 1ms=220000 TIMES	
	}
}
static kal_bool ctp_goodix_gt818_init(void)
{
#ifdef USE_SW_I2C
    DCL_HANDLE sda_handle, scl_handle;
#endif    
    DCL_HANDLE eint_handle, reset_handle;
    kal_bool ack;
    ctp_info_t ctp_info;
#ifdef TPD_RESET_ISSUE_WORDAROUND
    kal_uint8 reset_count = 0;
#endif
    CTP_DEBUG( __func__ );
    
    //gpio_ctp_reset_pin
    ctp_goodix_gt818_power(KAL_TRUE);
	
#ifdef USE_SW_I2C
	ctp_i2c_init();
 	//CTP_DELAY_TIME_GT818 = 3;
#else
    // init i2c 
    /*
    sda_handle = DclGPIO_Open(DCL_GPIO, gpio_ctp_i2c_sda_pin);
    scl_handle = DclGPIO_Open(DCL_GPIO, gpio_ctp_i2c_scl_pin);

    DclGPIO_Control(sda_handle, GPIO_CMD_SET_MODE_0, NULL);
    DclGPIO_Control(scl_handle, GPIO_CMD_SET_MODE_0, NULL);
    */
    
    //CTP_DELAY_TIME_GT818 = 3;
#endif    

    ctp_i2c_configure(0xBA/*CTP_SLAVE_ADDR*/, CTP_DELAY_TIME_GT818);

    eint_handle = DclGPIO_Open(DCL_GPIO, gpio_ctp_eint_pin);
    //reset_handle = DclGPIO_Open(DCL_GPIO, gpio_ctp_reset_pin);

#ifdef TPD_RESET_ISSUE_WORDAROUND
reset_proc:    
#endif  

//    EINT_Set_Sensitivity(custom_eint_get_channel(touch_panel_eint_chann), EDGE_SENSITIVE);
#if 1
	DclGPIO_Control(eint_handle, GPIO_CMD_SET_DIR_IN, NULL);         //  kuuga add 
	//DclGPIO_Control(eint_handle, GPIO_CMD_SET_MODE_2, NULL);       //  kuuga add for set int gpio_mode to int_mode
	DclGPIO_Control(eint_handle, GPIO_CMD_SET_MODE_1, NULL);
// EINT_Set_HW_Debounce(custom_eint_get_channel(touch_panel_eint_chann), 2);
    EINT_SW_Debounce_Modify(custom_eint_get_channel(touch_panel_eint_chann),0);
	EINT_Set_Sensitivity(custom_eint_get_channel(touch_panel_eint_chann), EDGE_SENSITIVE);
	 CTP_SET_RESET_PIN_LOW;
     GT818_Delayms(5);
	 CTP_SET_RESET_PIN_HIGH;
#endif
	kal_prompt_trace(MOD_ENG, "do ctp_goodix_gt818_init");
#ifdef TPD_RESET_ISSUE_WORDAROUND
	GT818_Delayms(200);
    ack = ctp_goodix_gt818_get_information( &ctp_info );
    
    if ( ack == KAL_FALSE )
    {
        if ( reset_count < CTP_MAX_RESET_COUNT )
        {
            CTP_DEBUG("reset fail");
	     kal_prompt_trace(MOD_ENG, "ctp_goodix_gt818_init lijunbo reset fail ");
		 reset_count++;
            goto reset_proc;
        }
        
       // ASSERT(0);
        return KAL_FALSE;
    }
#endif

    // load init table    
    if ( ctp_goodix_gt818_set_configuration() )
    {
        CTP_DEBUG("load init success");
		kal_prompt_trace(MOD_ENG, "ctp_goodix_gt818_init lijunbo load init success ");
    }
    else
    {
        CTP_DEBUG("load init fail");
		kal_prompt_trace(MOD_ENG, "ctp_goodix_gt818_init lijunbo load init fail ");
    }

    return KAL_TRUE;

}

static kal_bool ctp_goodix_gt818_parameters(CTP_parameters_struct *para, kal_uint32 get_para, kal_uint32 set_para)
{
    return KAL_TRUE;
}

#if 1
kal_bool gt818_get_chip_id(void)
{	
   kal_bool ret;
    kal_uint8 lvalue = 0;  
   kal_uint8 i,j;

   ctp_goodix_gt818_init();
   i=0;
   ret=KAL_FALSE;
    CTP_I2C_send( CTP_HANDSHAKING_START_REG, NULL, 0 );
  //  ret = CTP_I2C_send( CTP_CONFIG_REG_BASE, cfg_data, sizeof( cfg_data ) );

 //   CTP_I2C_read( CTP_TOUCH_CHI_ID_REG_BASE, &lvalue, 1);
   do{
   	 	//ret=ctp_i2c_receive( CTP_SLAVE_ADDR, CTP_TOUCH_CHI_ID_REG_BASE, &lvalue, 1);
   	 	ret=CTP_I2C_read( CTP_TOUCH_CHI_ID_REG_BASE, &lvalue, 1);
		i++;
   	}
   while((i>4)||(ret==KAL_TRUE));

    kal_prompt_trace(MOD_ENG, "gt818_get_chip_id lijunbo ddd: %d",ret);
   
    CTP_I2C_send( CTP_HANDSHAKING_END_REG, NULL, 0 );

    return ret;
    
 
	
}
#endif

static kal_bool ctp_read_one_point(kal_uint32 x_base, TP_SINGLE_EVENT_T *event)
{

    kal_uint8 point_info[CTP_POINT_INFO_LEN];
#ifdef TPD_BYTE_READ_WORKAROUND
    int i;
    
    for ( i = 1 ; i < CTP_POINT_INFO_LEN ; i++ )
        CTP_I2C_read(x_base+i, &point_info[i], 1);
#else
    CTP_I2C_read(x_base, point_info, CTP_POINT_INFO_LEN);
#endif

    event->x = TPD_WARP_X(( point_info[1] + ( point_info[2] << 8 ) ));
    event->y = TPD_WARP_Y(( point_info[3] + ( point_info[4] << 8 ) ));
    //event->z = point_info[5] + ( point_info[6] << 8 );
    event->z = 32;
   // kal_prompt_trace(MOD_ENG, "ctp_read_one_point: %d %d", event->x, event->y);

    return KAL_TRUE;
}

static kal_bool ctp_read_all_point(TouchPanelMultipleEventStruct *tpes, kal_uint32 points)
{
    kal_uint32 i=0;
    TP_SINGLE_EVENT_T get_one_point;	
	
    ASSERT(tpes);

    if((points<1) || (points>5))
        return KAL_FALSE;
		
    for(i=0;i<points;i++)
    {
        ctp_read_one_point( CTP_POINT_INFO_REG_BASE + CTP_POINT_INFO_LEN*i , &get_one_point);
        tpes->points[i].x = get_one_point.x;
        tpes->points[i].y = get_one_point.y;
        tpes->points[i].z = get_one_point.z;
        kal_prompt_trace(MOD_ENG, "ctp_read_all_point: %d, x=%d, y=%d", i,tpes->points[i].x,tpes->points[i].y);
    }	

    return KAL_TRUE;
}

static kal_bool ctp_goodix_gt818_get_data(TouchPanelMultipleEventStruct *tpes)
{
    kal_uint8 lvalue = 0;
    kal_uint32 model = 0;
    kal_bool ret = KAL_TRUE;
    ASSERT(tpes);

	kal_prompt_trace(MOD_ENG, "ctp_goodix_gt818_get_data lijunbo aaas ");
		
    tpes->time_stamp = (kal_uint16)L1I_GetTimeStamp();
    tpes->padding = CTP_PATTERN;
    CTP_I2C_send( CTP_HANDSHAKING_START_REG, NULL, 0 );

    CTP_I2C_read( CTP_TOUCH_INFO_REG_BASE, &lvalue, 1);

    model = (kal_uint32)(lvalue & CTP_STAT_NUMBER_TOUCH);

	 kal_prompt_trace(MOD_ENG, "ctp_goodix_gt818_get_data: %d",model);
	
    
////////////////////////////////kuuga modify start/////////////////////////////////////////////
     if((lvalue&0x30) != 0x20)        
    {
        ret = KAL_FALSE;
        goto exit_get_data;
    }
////////////////////////////////kuuga modify end/////////////////////////////////////////////
	
    if(model > 5) //goodix only support 5 fingers
    {
        ret = KAL_FALSE;
        goto exit_get_data;
    }

    tpes->model = (kal_uint16)model;  //read out all touch points coordinates.

    if (model == 0)
    {
	/*touch key*/
	{
		  CTP_I2C_read( CTP_TOUCH_KEY_REG_BASE, &lvalue, 1);
		  kal_prompt_trace(MOD_ENG, "ctp_goodix_gt818_get_data 22222:lvalue= %d",lvalue);
		  if(lvalue==1)
		  {
			ret = KAL_TRUE;
			tpes->points[0].x=60;
			tpes->points[0].y=840;
			tpes->points[0].z=32;
			   tpes->model=1;
			goto exit_get_data;
		  }
		  else if(lvalue==2)
		  {
			ret = KAL_TRUE;
			tpes->points[0].x=180;
			tpes->points[0].y=840;
			tpes->points[0].z=32;
			 tpes->model=1;
			goto exit_get_data;
		  }
		  else if(lvalue==4)
		  {
			ret = KAL_TRUE;
			tpes->points[0].x=300;
			tpes->points[0].y=840;
			tpes->points[0].z=32;
			 tpes->model=1;
			goto exit_get_data;
		  }
		  else if(lvalue==8)
		  {
			ret = KAL_TRUE;
			tpes->points[0].x=420;
			tpes->points[0].y=840;
			tpes->points[0].z=32;
			 tpes->model=1;
			goto exit_get_data;
		  }
		  else
		  {
			ret = KAL_FALSE;	
		  }
	}
        ret = KAL_FALSE;	
	
        CTP_I2C_read( CTP_POINT_INFO_REG_BASE + 1 , &lvalue, 1);
        goto exit_get_data;
    }
    ctp_read_all_point(tpes, model);
	
 exit_get_data:   
 
    CTP_I2C_send( CTP_HANDSHAKING_END_REG, NULL, 0 );
    
    if ( model == 0xF )
    {
        kal_prompt_trace(MOD_ENG, "do recovery");
        ctp_goodix_gt818_set_configuration();
    }    
    
    return ret;
}

 kal_bool ctp_goodix_gt818_set_device_mode(ctp_device_mode_enum mode)
{
    kal_uint8 suspend_command = 0x01;
    DCL_HANDLE eint_handle;
    ctp_info_t ctp_info;

    if( mode == CTP_ACTIVE_MODE )
    {      
#ifdef TPD_RESET_ISSUE_WORDAROUND
        eint_handle = DclGPIO_Open(DCL_GPIO, gpio_ctp_eint_pin);
        DclGPIO_Control(eint_handle, GPIO_CMD_SET_MODE_0, NULL);
        DclGPIO_Control(eint_handle, GPIO_CMD_SET_DIR_OUT, NULL);
        DclGPIO_Control(eint_handle, GPIO_CMD_WRITE_LOW, NULL);
        kal_sleep_task(1);
////////////////////////////////kuuga modify start/////////////////////////////////////////////
        DclGPIO_Control(eint_handle, GPIO_CMD_WRITE_HIGH, NULL); 
        kal_sleep_task(1);       // no need 
        DclGPIO_Control(eint_handle, GPIO_CMD_WRITE_LOW, NULL);
        kal_sleep_task(1);
////////////////////////////////kuuga modify end/////////////////////////////////////////////
        DclGPIO_Control(eint_handle, GPIO_CMD_SET_MODE_1, NULL);
        DclGPIO_Control(eint_handle, GPIO_CMD_SET_DIR_IN, NULL);
#endif
        CTP_I2C_send( CTP_HANDSHAKING_END_REG, NULL, 0 );
        CTP_DEBUG( "resume!" );
    }    
    else if(mode == CTP_SLEEP_MODE)
    {
        CTP_I2C_send( CTP_HANDSHAKING_START_REG, NULL, 0 );
        CTP_I2C_send( CTP_POWER_MODE_REG, &suspend_command, 1 );
		CTP_I2C_send( CTP_HANDSHAKING_END_REG, NULL, 0 );
        CTP_DEBUG( "suspend!" );
    }   
   // else if (mode == CTP_FIRMWARE_UPDATE )
   
   else if (mode == CTP_FIRMWARE_UPDATE )//lijunbo
    {
#ifdef __MTK_TARGET__    
        // update firmware
        if ( ctp_goodix_gt818_get_information( &ctp_info ) )
        {
            init_gt818_download_module( ctp_info.version_2*256 + ctp_info.version_1, goodix_gt818_firmware);
        }
        ctp_goodix_gt818_init();
#endif        
    } 
    return KAL_FALSE;
}

 static kal_uint32 ctp_focaltech_gt818_command(kal_uint32 cmd, void* p1, void* p2)
{
    return KAL_TRUE;
}

CTP_custom_information_struct *ctp_Get_Data_gt818(void) 
{
    return (&ctp_custom_information_def_gt818);
}

 CTP_customize_function_struct ctp_custom_func_gt818=
{
    ctp_goodix_gt818_init,
    ctp_goodix_gt818_set_device_mode,
    ctp_goodix_gt818_hisr,
    ctp_goodix_gt818_get_data,
    ctp_goodix_gt818_parameters,
    ctp_goodix_gt818_power,
    ctp_focaltech_gt818_command
};

CTP_customize_function_struct *ctp_GetFunc_gt818(void)
{
    return (&ctp_custom_func_gt818);  
}

