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
#include "touch_panel_custom.h"
#include "us_timer.h"
#include "dcl.h"
#include "eint.h"
#include "kal_trace.h"
#include "Capacitive_TP_trc.h"

#ifdef __CTP_GOODIX_GT818_TRUE_MULTIPLE__
	
#ifdef __MTK_TARGET__
#include "GT818_firmware.h"
#endif

#if !defined(IC_MODULE_TEST)
extern kal_uint32 /*lint -e(526)*/L1I_GetTimeStamp(void);
#endif

#define TPD_RESET_ISSUE_WORDAROUND
//#define TPD_BYTE_READ_WORKAROUND
#define CTP_MAX_RESET_COUNT 3

#ifdef __MTK_TARGET__
#define CTP_DEBUG_LINE_TRACE() drv_trace1(TRACE_GROUP_7, CTP_GOODIX_DRV_LINE_TRACE, __LINE__)
#else
#define CTP_DEBUG_LINE_TRACE() do {} while (0);
#endif

extern const char gpio_ctp_power_enable_pin;
extern const char gpio_ctp_i2c_sda_pin;
extern const char gpio_ctp_i2c_scl_pin;
extern const char gpio_ctp_eint_pin;
extern const char gpio_ctp_reset_pin;
extern const char gpio_ctp_eint_pin_M_EINT;

extern kal_int32 init_gt818_download_module( kal_uint16 cur_ver, kal_uint8 *firmware_ptr );

kal_uint32 CTP_DELAY_TIME = 400;

CTP_custom_information_struct  ctp_custom_information_def = 
{
    "Goodix ",
    "GT818",
    "UNKNOWN ",	
};

#ifdef __PXS_GOODIX_GT818__

#define PXS_SENSING_DETECTED_FLAG    (1)
#define PXS_LARGE_AREA_DETECTED_FLAG (2)
#define PXS_DEFAULT_TOP_DEBOUNCE_TICK         400
#define PXS_DEFAULT_LARGE_AREA_DEBOUNCE_TICK  100

typedef struct _gt818_pxs_context
{
    DCL_BOOL gt818_pxs_enable_flag;
    DCL_BOOL current_ps_status;
    kal_uint32   top_debounce;
    kal_uint32   ts_top_detected;
    kal_uint32   large_area_debounce;
    kal_uint32   ts_large_area_detected;
    PXS_CONFIG_T HPXSConfig;
    kal_uint8    pxs_flag;
} gt818_pxs_context_t;

static gt818_pxs_context_t gt818_pxs_context;

static DCL_BOOL gt818_get_ps_value( void );

#endif

kal_bool CTP_I2C_write_byte(kal_uint16 ucBufferIndex, kal_uint8 pucData)
{
    return ctp_i2c_send( CTP_SLAVE_ADDR, ucBufferIndex, &pucData, 1);
}

#define CTP_I2C_read(a,b,c) ctp_i2c_receive_ext( CTP_SLAVE_ADDR, a, b, c)
#define CTP_I2C_send(a,b,c) ctp_i2c_send_ext( CTP_SLAVE_ADDR, a, b, c)

static kal_bool ctp_goodix_gt818_set_device_mode(ctp_device_mode_enum mode);

static void ctp_goodix_gt818_power(kal_bool ON)
{
    static kal_bool power_status = KAL_TRUE;
    DCL_HANDLE enable_handle;

    CTP_DEBUG_LINE_TRACE();

    if(ON == power_status)
        return;

#ifdef __PXS_GOODIX_GT818__
    // If PXS on, just ignore the power on/off request
    if ( gt818_pxs_context.gt818_pxs_enable_flag == DCL_TRUE )
        return;
#endif

    power_status = ON;

    if ( ON )
        ctp_goodix_gt818_set_device_mode( CTP_ACTIVE_MODE );
    else
        ctp_goodix_gt818_set_device_mode( CTP_SLEEP_MODE );
        
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
    
    drv_trace4( TRACE_GROUP_7, CTP_GOODIX_DRV_VERION_TRACE ,ctp_info->version_1, ctp_info->version_2,ctp_info->vendor_id_1,ctp_info->vendor_id_2);

    ctp_custom_information_def.FirmwareVersion[0] = ctp_info->version_1%100;
    ctp_custom_information_def.FirmwareVersion[1] = ctp_info->version_1/100;
    
    return ret;
}

static kal_bool ctp_goodix_gt818_set_configuration( void )
{
    kal_bool ret;
    kal_int16 cfg_idx = CTP_CONFIG_NORMAL;
    kal_uint8 *cfg_p;
    ctp_info_t ctp_info;
    
    if ( ctp_goodix_gt818_get_information(&ctp_info) != KAL_TRUE )
        return KAL_FALSE;
    
#ifdef __PXS_GOODIX_GT818__
    if ( ctp_info.version_1 == 0x80 && ctp_info.version_2 == 0xF0 )
        cfg_idx = CTP_CONFIG_PROXIMITY;
#endif

#ifdef APOLLO55N_V2_DEMO_BB    
    if ( ctp_info.version_1 == 0x7F && ctp_info.version_2 == 0x00 ) 
        cfg_idx = CTP_CONFIG_FM_DESENCE;
                
    if ( ctp_info.version_1 == 0x80 && ctp_info.version_2 == 0x00 ) 
        cfg_idx = CTP_CONFIG_FM_DESENCE; 
#endif        
    
    drv_trace1( TRACE_GROUP_7, CTP_GOODIX_DRV_SET_CFG_TRACE, cfg_idx );
    CTP_I2C_send( CTP_HANDSHAKING_START_REG, NULL, 0 );
    
    // set frame rate as 70Hz        
    cfg_p = GET_CTP_CONFIG(cfg_idx);
    cfg_p[ CTP_CONFIG_FPS_REG - CTP_CONFIG_REG_BASE ] = 70;
    
    ret = CTP_I2C_send( CTP_CONFIG_REG_BASE, GET_CTP_CONFIG(cfg_idx) , CTP_CONFIG_LENGTH );
    //ret = CTP_I2C_send( CTP_CONFIG_REG_BASE, cfg_data , sizeof(cfg_data) );
    CTP_I2C_send( CTP_HANDSHAKING_END_REG, NULL, 0 );
    
    return ret;
}

static Touch_Panel_PenState_enum ctp_goodix_gt818_hisr(void)
{
    kal_uint8 lvalue;

    CTP_I2C_read(CTP_TOUCH_INFO_REG_BASE, &lvalue, 1);
    
    if(lvalue & CTP_STAT_NUMBER_TOUCH)
        return DOWN;
    else
        return UP;
}

static kal_bool ctp_goodix_gt818_init(void)
{
    DCL_HANDLE sda_handle, scl_handle;
    DCL_HANDLE eint_handle, reset_handle;
    kal_bool ack;
    ctp_info_t ctp_info;
#ifdef TPD_RESET_ISSUE_WORDAROUND
    kal_uint8 reset_count = 0;
#endif
    CTP_DEBUG_LINE_TRACE();
    
    //gpio_ctp_reset_pin
    ctp_goodix_gt818_power(KAL_TRUE);

    // init i2c 
    if(gpio_ctp_i2c_sda_pin != 0xFF)
    {
    sda_handle = DclGPIO_Open(DCL_GPIO, gpio_ctp_i2c_sda_pin);
    scl_handle = DclGPIO_Open(DCL_GPIO, gpio_ctp_i2c_scl_pin);

    DclGPIO_Control(sda_handle, GPIO_CMD_SET_MODE_0, NULL);
    DclGPIO_Control(scl_handle, GPIO_CMD_SET_MODE_0, NULL);
    CTP_DELAY_TIME = 3;
    }

    ctp_i2c_configure(CTP_SLAVE_ADDR, CTP_DELAY_TIME);

    eint_handle = DclGPIO_Open(DCL_GPIO, gpio_ctp_eint_pin);
    reset_handle = DclGPIO_Open(DCL_GPIO, gpio_ctp_reset_pin);

    // resume CTP from suspend mode
    ctp_goodix_gt818_set_device_mode( CTP_ACTIVE_MODE );
    
#ifdef TPD_RESET_ISSUE_WORDAROUND
reset_proc:    
#endif  
    DclGPIO_Control(eint_handle, GPIO_CMD_SET_DIR_IN, NULL);
    DclGPIO_Control(eint_handle, gpio_ctp_eint_pin_M_EINT, NULL);
    
    DclGPIO_Control(reset_handle, GPIO_CMD_SET_MODE_0, NULL);	
    DclGPIO_Control(reset_handle, GPIO_CMD_SET_DIR_OUT, NULL);    
    DclGPIO_Control(reset_handle, GPIO_CMD_SET_DIR_IN, NULL);
    kal_sleep_task(5);
    DclGPIO_Control(reset_handle, GPIO_CMD_SET_DIR_OUT, NULL);
    kal_sleep_task(5);	
    DclGPIO_Control(reset_handle, GPIO_CMD_WRITE_HIGH, NULL);
#ifdef __MTK_TARGET__    
    EINT_Set_Sensitivity(custom_eint_get_channel(touch_panel_eint_chann), EDGE_SENSITIVE);
#endif    

#ifdef TPD_RESET_ISSUE_WORDAROUND

    ack = ctp_goodix_gt818_get_information( &ctp_info );
    
    if ( ack == KAL_FALSE )
    {
        if ( reset_count < CTP_MAX_RESET_COUNT )
        {
            CTP_DEBUG_LINE_TRACE();
            reset_count++;
            goto reset_proc;
        }
        
        //ASSERT(0);
        return KAL_FALSE;
    }
#endif

    // load init table    
    if ( ctp_goodix_gt818_set_configuration() )
    {
        CTP_DEBUG_LINE_TRACE();
    }
    else
    {
        CTP_DEBUG_LINE_TRACE();
        //ASSERT(0);
        return KAL_FALSE;
    }

    return KAL_TRUE;

}

static kal_bool ctp_goodix_gt818_parameters(CTP_parameters_struct *para, kal_uint32 get_para, kal_uint32 set_para)
{
    return KAL_TRUE;
}

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
    drv_trace2( TRACE_GROUP_7, CTP_COORDINATE1, event->x, event->y);

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
    }	

    return KAL_TRUE;
}

static kal_bool ctp_goodix_gt818_get_data(TouchPanelMultipleEventStruct *tpes)
{
    kal_uint8 lvalue = 0;
    kal_uint32 model = 0;
    kal_bool ret = KAL_TRUE;
    ASSERT(tpes);
		
    tpes->time_stamp = (kal_uint16)L1I_GetTimeStamp();
    tpes->padding = CTP_PATTERN;
    CTP_I2C_send( CTP_HANDSHAKING_START_REG, NULL, 0 );

    CTP_I2C_read( CTP_TOUCH_INFO_REG_BASE, &lvalue, 1);

    model = (kal_uint32)(lvalue & CTP_STAT_NUMBER_TOUCH);
	
    if(model > 5) //goodix only support 5 fingers
    {
        ret = KAL_FALSE;
        goto exit_get_data;
    }

    tpes->model = (kal_uint16)model;  //read out all touch points coordinates.

    if (model == 0)
    {
        ret = KAL_FALSE;
        CTP_I2C_read( CTP_POINT_INFO_REG_BASE + 1 , &lvalue, 1);
        goto exit_get_data;
    }
    ctp_read_all_point(tpes, model);
	
 exit_get_data:   
 
    CTP_I2C_send( CTP_HANDSHAKING_END_REG, NULL, 0 );
#ifdef __PXS_GOODIX_GT818__
    if ( gt818_pxs_context.gt818_pxs_enable_flag == KAL_TRUE )
    {
        DCL_BOOL object_detected = gt818_get_ps_value();

        if ( object_detected != gt818_pxs_context.current_ps_status )
        {
            drv_trace1( TRACE_GROUP_7, CTP_GOODIX_DRV_PXS_CHANGE_TRACE, object_detected );
            if ( gt818_pxs_context.HPXSConfig.fgNotify && gt818_pxs_context.HPXSConfig.NotifyCallback )
            {
                CTP_DEBUG_LINE_TRACE();
                gt818_pxs_context.HPXSConfig.NotifyCallback( object_detected );
            }

            gt818_pxs_context.current_ps_status = object_detected;
        }          
    }
    
    // If object detected, ignore all touch point
    if ( gt818_pxs_context.current_ps_status == DCL_TRUE )
        return KAL_FALSE;
#endif    
    
    if ( model == 0xF )
    {
        CTP_DEBUG_LINE_TRACE();
        ctp_goodix_gt818_set_configuration();
    }    
    
    return ret;
}

static kal_bool ctp_goodix_gt818_set_device_mode(ctp_device_mode_enum mode)
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
        DclGPIO_Control(eint_handle, GPIO_CMD_WRITE_HIGH, NULL);
        kal_sleep_task(1);
        DclGPIO_Control(eint_handle, gpio_ctp_eint_pin_M_EINT, NULL);
        DclGPIO_Control(eint_handle, GPIO_CMD_SET_DIR_IN, NULL);
#endif
        CTP_I2C_send( CTP_HANDSHAKING_END_REG, NULL, 0 );
        CTP_DEBUG_LINE_TRACE();
    }    
    else if(mode == CTP_SLEEP_MODE)
    {
        CTP_I2C_send( CTP_HANDSHAKING_START_REG, NULL, 0 );
        CTP_I2C_send( CTP_POWER_MODE_REG, &suspend_command, 1 );
        CTP_I2C_send( CTP_HANDSHAKING_END_REG, NULL, 0 );
        CTP_DEBUG_LINE_TRACE();
    }
    else if (mode == CTP_FIRMWARE_UPDATE )
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

static kal_uint32 ctp_goodix_gt818_command(kal_uint32 cmd, void* p1, void* p2) // p1: input p2: output
{
    #define TPD_SYNC_REG                  0x711
    #define TPD_DIFF_DATA_REG             0xD80
    #define TPD_CHANNEL_CONFIG_REG        0x6D5
    #define TPD_RAW_DATA_1_REG            0x880
    #define TPD_RAW_DATA_2_REG            0x9C0

    #define MAX_DRIVING_CHANNEL 16
    #define MAX_SENSING_CHANNLE 10
    #define MAX_DIFF_DATA_SIZE   (MAX_DRIVING_CHANNEL*MAX_SENSING_CHANNLE*2)
    #define MAX_RAW_DATA_SIZE    MAX_DIFF_DATA_SIZE

    char **dst = (char **)p2;
    ctp_info_t ctp_info;
    kal_bool ret = KAL_TRUE;
    kal_uint8 *cfg = (kal_uint8 *)p1;
    kal_uint8 mode;
    kal_uint8 *tpd_raw_data;
    kal_uint8 tmp[MAX_DIFF_DATA_SIZE];
    kal_uint8 *ptr;
    kal_uint8 row;
    
    *dst = NULL;

#ifdef __MTK_TARGET__
    tpd_raw_data = goodix_gt818_firmware;
#endif
      
    switch ( cmd )
    {
    	case DCL_CTP_COMMAND_GET_VERSION: // get firmware version
    	    if ( ctp_goodix_gt818_get_information(&ctp_info) )
    	    {
    	        memcpy( tpd_raw_data, (kal_uint8 *)&ctp_info, sizeof( ctp_info_t ) );
    	        *dst = (char *)tpd_raw_data;
    	    }
    	    else
              ret = KAL_FALSE;
          break;
      case DCL_CTP_COMMAND_GET_CONFIG:
          CTP_I2C_send( CTP_HANDSHAKING_START_REG, NULL, 0 );
          if ( 	CTP_I2C_read( CTP_CONFIG_REG_BASE, tpd_raw_data, CTP_CONFIG_LENGTH ) )
          {
              *dst = (char *)tpd_raw_data;
          }
          else
              ret = KAL_FALSE;
          CTP_I2C_send( CTP_HANDSHAKING_END_REG, NULL, 0 );
          break;
      case DCL_CTP_COMMAND_LOAD_INT_CONFIG:
          ctp_goodix_gt818_set_configuration();
          break;
      case DCL_CTP_COMMAND_LOAD_EXT_CONFIG:
          cfg[105] = 1;
          CTP_I2C_send( CTP_HANDSHAKING_START_REG, NULL, 0 );
          CTP_I2C_send( CTP_CONFIG_REG_BASE, cfg, CTP_CONFIG_LENGTH );
          CTP_I2C_send( CTP_HANDSHAKING_END_REG, NULL, 0 );
          break;
      case DCL_CTP_COMMAND_GET_DIFF_DATA:
          CTP_I2C_send( CTP_HANDSHAKING_START_REG, NULL, 0 );
          CTP_I2C_read( TPD_CHANNEL_CONFIG_REG, tpd_raw_data, 2 );
          mode = 1;
          CTP_I2C_send( TPD_SYNC_REG, &mode, 1 );
          CTP_I2C_read( TPD_DIFF_DATA_REG, tmp, MAX_DIFF_DATA_SIZE );
          mode = 0;
          CTP_I2C_send( TPD_SYNC_REG, &mode, 1 );
          CTP_I2C_send( CTP_HANDSHAKING_END_REG, NULL, 0 );

          ptr = &tpd_raw_data[2];
          
          for ( row = 0 ; row < MAX_DRIVING_CHANNEL ; row++ )
          {
              memcpy( ptr, &tmp[row*MAX_SENSING_CHANNLE*2], MAX_SENSING_CHANNLE );
              ptr += MAX_SENSING_CHANNLE;
          }
          *dst = (char *)tpd_raw_data;
          break;
      case DCL_CTP_COMMAND_GET_FW_BUFFER:
#ifdef __MTK_TARGET__      
          *dst = (char *)goodix_gt818_firmware;
#endif          
          break;
      case DCL_CTP_COMMAND_DO_FW_UPDATE:
#ifdef __MTK_TARGET__      
          init_gt818_download_module( 0, goodix_gt818_firmware);
#endif          
          ctp_goodix_gt818_init();
          break;
      default:
          ret = KAL_FALSE;        
    	    
    }
    
    return ret;	
}

CTP_custom_information_struct *ctp_Get_Data(void) 
{
    return (&ctp_custom_information_def);
}

static CTP_customize_function_struct ctp_custom_func=
{
    ctp_goodix_gt818_init,
    ctp_goodix_gt818_set_device_mode,
    ctp_goodix_gt818_hisr,
    ctp_goodix_gt818_get_data,
    ctp_goodix_gt818_parameters,
    ctp_goodix_gt818_power,
    ctp_goodix_gt818_command
};

CTP_customize_function_struct *ctp_GetFunc(void)
{
    return (&ctp_custom_func);  
}

#ifdef __PXS_GOODIX_GT818__
static DCL_STATUS gt818_ps_enable( PXS_CTRL_ENABLE_T *pEnable )
{
    kal_uint8 pwr_mode;
    
    drv_trace2( TRACE_GROUP_7, CTP_GOODIX_DRV_PXS_ENABLE_TRACE, pEnable->fgEnable, gt818_pxs_context.gt818_pxs_enable_flag );
    
    if (gt818_pxs_context.gt818_pxs_enable_flag == pEnable->fgEnable)
    {
        return STATUS_OK;
    }
	    
    CTP_I2C_send( CTP_HANDSHAKING_START_REG, NULL, 0 );
    CTP_I2C_read( CTP_POWER_MODE_REG , &pwr_mode, 1);
    
    if ( pEnable->fgEnable == DCL_TRUE )
    {
        pwr_mode |= 0x80;
        gt818_pxs_context.top_debounce = PXS_DEFAULT_TOP_DEBOUNCE_TICK;
        gt818_pxs_context.large_area_debounce = PXS_DEFAULT_LARGE_AREA_DEBOUNCE_TICK;            
    }
    else
    {
        gt818_pxs_context.large_area_debounce = 0;
        gt818_pxs_context.top_debounce = 0;    
        pwr_mode &= 0x7F;
    }
        
    CTP_I2C_send( CTP_POWER_MODE_REG, &pwr_mode, 1 );
    CTP_I2C_send( CTP_HANDSHAKING_END_REG, NULL, 0 );
    
    gt818_pxs_context.gt818_pxs_enable_flag = pEnable->fgEnable;
    gt818_pxs_context.current_ps_status = DCL_FALSE;
    	    
    return STATUS_OK;	
}

static DCL_BOOL gt818_get_ps_value( void )
{
    kal_uint8 value;
    kal_bool ret;
    DCL_BOOL pxs_status = DCL_FALSE;
    kal_uint32 time_stamp = L1I_GetTimeStamp();
    
    value = 0;
    CTP_I2C_send( CTP_HANDSHAKING_START_REG, NULL, 0 );
    ret = CTP_I2C_read( TPD_LARGE_OBJECT_DETECT_REG , &value, 1);
    CTP_I2C_send( CTP_HANDSHAKING_END_REG, NULL, 0 );

    if ( ret )
    {
        drv_trace4( TRACE_GROUP_7, CTP_GOODIX_DRV_PXS_REGISTER_TRACE, TPD_LARGE_OBJECT_DETECT_REG, value, time_stamp, 0 );
        
        if ( value&0x0F )
        {
            if ( gt818_pxs_context.pxs_flag & PXS_LARGE_AREA_DETECTED_FLAG )
            {
                drv_trace2( TRACE_GROUP_7, CTP_GOODIX_DRV_PXS_TOP_DEBOUNDCE_TRACE, gt818_pxs_context.ts_large_area_detected, gt818_pxs_context.large_area_debounce );
                if ( (time_stamp - gt818_pxs_context.ts_large_area_detected) > gt818_pxs_context.large_area_debounce )
                    pxs_status = DCL_TRUE; 
            }
            else
            {
                drv_trace1( TRACE_GROUP_7, CTP_GOODIX_DRV_PXS_TOP_TS_TRACE, time_stamp );
                gt818_pxs_context.pxs_flag |= PXS_LARGE_AREA_DETECTED_FLAG;
                gt818_pxs_context.ts_large_area_detected = time_stamp;
            }
        }
        else
        {
            gt818_pxs_context.pxs_flag &= ~( PXS_LARGE_AREA_DETECTED_FLAG );
            gt818_pxs_context.ts_large_area_detected = 0;
        }

        if ( value & 0x10 )
        {
            if ( gt818_pxs_context.pxs_flag & PXS_SENSING_DETECTED_FLAG )
            {
                drv_trace2( TRACE_GROUP_7, CTP_GOODIX_DRV_PXS_LA_DEBOUNDCE_TRACE, gt818_pxs_context.ts_top_detected, gt818_pxs_context.top_debounce );
                if ( (time_stamp - gt818_pxs_context.ts_top_detected) > gt818_pxs_context.top_debounce )
                    pxs_status = DCL_TRUE;  
            }
            else
            {
                drv_trace1( TRACE_GROUP_7, CTP_GOODIX_DRV_PXS_TOP_TS_TRACE, time_stamp );
                gt818_pxs_context.pxs_flag |= PXS_SENSING_DETECTED_FLAG;
                gt818_pxs_context.ts_top_detected = time_stamp;
            }
                
        }
        else
        {
            gt818_pxs_context.pxs_flag &= ~( PXS_SENSING_DETECTED_FLAG );
            gt818_pxs_context.ts_top_detected = 0;
        }               
    }
    else
    	CTP_DEBUG_LINE_TRACE();

    return pxs_status;
}


static DCL_STATUS gt818_get_pxs_raw_data(PXS_CTRL_RAW_DATA_T *pRawData)
{
    return STATUS_OK;
}

static DCL_STATUS gt818_set_debounce(PXS_CTRL_SET_DEBOUNCE_T *pDebounce)
{
    gt818_pxs_context.top_debounce = pDebounce->u4TopAreaDebounce;
    gt818_pxs_context.large_area_debounce = pDebounce->u4LargerAreaDebounce;

    return STATUS_OK;
}
// DclHPXS_XXX interface
DCL_STATUS DclHPXS_Initialize(void)
{
    gt818_pxs_context.gt818_pxs_enable_flag = KAL_FALSE;
    gt818_pxs_context.current_ps_status = DCL_FALSE;
    gt818_pxs_context.pxs_flag = 0;
    return STATUS_OK;
}

DCL_HANDLE DclHPXS_Open(DCL_DEV dev, DCL_FLAGS flags)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclHPXS_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclHPXS_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclHPXS_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
    PXS_CONFIG_T *pPXSConfig;

    ASSERT(configure);
    pPXSConfig = (PXS_CONFIG_T *)(configure);

    gt818_pxs_context.HPXSConfig.fgNotify = pPXSConfig->fgNotify;
    gt818_pxs_context.HPXSConfig.NotifyCallback = pPXSConfig->NotifyCallback;
	
    return STATUS_OK;
}

DCL_STATUS DclHPXS_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclHPXS_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
    drv_trace1( TRACE_GROUP_7, CTP_GOODIX_DRV_PXS_COMMAND_TRACE, cmd );
	
    switch (cmd)
    {
        case PXS_CMD_ENABLE:
        {
            return gt818_ps_enable((PXS_CTRL_ENABLE_T *)((data)));
        }
        case PXS_CMD_EM_READ:
        {
            return STATUS_OK;
        }
        case PXS_CMD_EM_WRITE:
        {
            return STATUS_OK;
        }
        case PXS_CMD_GET_RAW_DATA:
        {
            return gt818_get_pxs_raw_data((PXS_CTRL_RAW_DATA_T *)((data)));
        }
        case PXS_CMD_GET_ADV_ALGO_WINDOWING:
        {
            return STATUS_OK;
        }
        case PXS_CMD_GET_ADV_ALGO_THRESHOLD:
        {
            return STATUS_OK;
        }
        case PXS_CMD_MODIFY_CONFIG:
        {
            return STATUS_OK;
        }
        case PXS_CMD_GET_SENSITIVITY_LEVEL_NUM:
        {
            return STATUS_OK;
        }
        case PXS_CMD_SET_SENSITIVITY_LEVEL:
        {
            return STATUS_OK;
        }
        case PXS_CMD_SET_DEBOUNCE:
        {
            return gt818_set_debounce((PXS_CTRL_SET_DEBOUNCE_T *)data);
        }
        default:
        //ASSERT(0);
            return STATUS_INVALID_CMD;
    }
}

DCL_STATUS DclHPXS_Close(DCL_HANDLE handle)
{
    return STATUS_INVALID_CMD;
}

#endif // #if defined(__PXS_GOODIX_GT818__)

#else
DCL_STATUS DclHPXS_Initialize(void)
{
    return STATUS_UNSUPPORTED;
}

DCL_HANDLE DclHPXS_Open(DCL_DEV dev, DCL_FLAGS flags)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclHPXS_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclHPXS_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclHPXS_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclHPXS_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclHPXS_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclHPXS_Close(DCL_HANDLE handle)
{
    return STATUS_UNSUPPORTED;
}
#endif //#ifdef __CTP_GOODIX_GT818_TRUE_MULTIPLE__