/***********************************************************************
*   This software/firmware and related documentation ("MediaTek Software") 
*   are protected under relevant copyright laws. The information contained 
*   herein is confidential and proprietary to MediaTek Inc. and/or its licensors.
*
*   Without the prior written permission of MediaTek Inc. and/or its licensors, 
*   any reproduction, modification, use or disclosure of MediaTek Software, and 
*   information contained herein, in whole or in part, shall be strictly prohibited.
*
*   MediaTek Inc. (C) [2007]. All rights reserved.
*
*************************************************************************/ 
/*******************************************************************************
 * Filename:
 * ---------
 *  gps_sm.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GPS task
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
/***************************************************************************** 
 * Include
 *****************************************************************************/ 
#ifdef __GPS_SUPPORT__
#include "kal_trace.h"
#include "stack_common.h"       /* message and module IDs */
#include "stack_msgs.h"         /* enum for message IDs */
#include "app_ltlcom.h"         /* Task message communiction */
#include "l1sm_public.h"        /* GSM sleep mode */
#include "eint.h"
#include "dcl.h"            /* uart APIs*/
/* GPS module definition */
#include "gps_main.h"
#include "gps_init.h"
#include "gps_trc.h"
#include "mtk_gps_task.h"
#include "stack_config.h"
#include "stack_ltlcom.h"
#include "kal_general_types.h"
    
/* GPS Time for Sleep Mode, Time Uint = 4.615 ms */
kal_uint32 gpsPowerOnTime;
kal_uint32 gpsPowerOffTime;
kal_uint32 gpsDataStartTime;
kal_uint32 gpsDataRXTime;
kal_uint32 gpsDataTXTime;
kal_uint32 gpsDataEndTime;
kal_uint32 gpsFixTime;
kal_uint32 gpsWakeUpTime;
kal_uint32 gpsWakeUpTimeOutTime;
kal_uint32 gpsPowerOnStablePeriod = 3250;
kal_uint32 gpsDataTimeoutPeriod = 2;
kal_uint32 gpsDataGuardTime = 25;
kal_uint32 gpsDataPeriod = 216;
kal_uint8  gps_sleep_enable_flag = 1;
kal_uint8  gps_wakeup_cmd_flag = 1;

/* GPS power saving mode parameters*/
kal_uint8 gps_power_saving_mode_flag = 0;
kal_uint8 gps_power_saving_mode_type = 0;
kal_uint32 gpsPSNoFixLimit = 30;
kal_uint32 gpsPSNormalFixLimit = 60;
kal_uint32 gpsPSEphemerisLimit = 7200;
kal_uint32 gpsPSPowerSavingTimeCount = 6;
kal_uint32 gpsPSNormalTimeCount = 3;
kal_uint32 gpsPSSpeedLimit = 10;

extern kal_uint8 gps_sleep_handle;
extern kal_uint8 mtk_gps_sleep_handle;
extern kal_uint32 L1I_GetTimeStamp( void );
extern kal_uint8 gps_eint_channel;
extern kal_uint8 gps_eint_debounce_enable;
extern kal_uint8 gps_uart_port;
extern gps_context_struct *gps_context_p;

#ifdef __MNL_SUPPORT__  
extern mtk_gps_task_struct *mtk_gps_context_p;
#endif
extern gps_context_struct *gps_context_p;
extern void gps_set_power_saving_mode(kal_uint8 mode);

/* The macro to check for the expiration */
#define GPS_CHECK_EXPIRATION(_currentTime, _expirationTime) \
        ((kal_uint32)(_currentTime) - (kal_uint32)(_expirationTime) <= 0x7fffffffUL)

/* The macro to check for the timeout */
#define GPS_CHECK_TIMEOUT(_currentTime, _timeoutStartingTime, _timeout) \
    GPS_CHECK_EXPIRATION((_currentTime), ((_timeoutStartingTime) + (_timeout)))

#ifdef __GPS_MT3326__
	#define GPS_WAKE_UP_ACK_COMMAND_NUM   34 /* MT3326 use command 34 */
#else 
	#define GPS_WAKE_UP_ACK_COMMAND_NUM   44 /* MT3336 use command 44 */
#endif

/*****************************************************************************
 * FUNCTION
 *  gps_uart_wakeup_handler
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gps_uart_wakeup_handler(void)
{

#ifdef __MNL_SUPPORT__

    gpsWakeUpTimeOutTime = L1I_GetTimeStamp();
    if (mtk_gps_context_p->gps_state == MNL_RUNNING)
    { 
        L1SM_SleepDisable(mtk_gps_sleep_handle);             
        GPS_TRACE((TRACE_GROUP_4, GPS_SLEEP_TRC_DISABLE_SLEEP,
                   gpsWakeUpTimeOutTime));  
        if (gps_eint_channel != 0xFF)
        {
            EINT_UnMask(gps_eint_channel);      
        }
    } 

#else  /* NOT __MNL_SUPPORT__ */


    gpsWakeUpTimeOutTime = L1I_GetTimeStamp();
    if (gps_context_p->gps_state == GPS_POWERON_STATE)
    {
        //For MT3333, if received EINT, but not UART data following, enable sleep mode
        #ifdef __GPS_MT3333__
        L1SM_SleepEnable(gps_sleep_handle);              
        GPS_TRACE((TRACE_GROUP_4, GPS_SLEEP_TRC_ENABLE_SLEEP,
                   gpsWakeUpTimeOutTime));
        #else
        L1SM_SleepDisable(gps_sleep_handle);             
        GPS_TRACE((TRACE_GROUP_4, GPS_SLEEP_TRC_DISABLE_SLEEP,
                   gpsWakeUpTimeOutTime));      
        #endif
        
        if (gps_eint_channel != 0xFF)
        {
            EINT_UnMask(gps_eint_channel);      
        }
    }  

#endif  /* __MNL_SUPPORT__ */

}


/*****************************************************************************
 * FUNCTION
 *  gps_uart_rx_timeout_handler
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gps_uart_rx_timeout_handler(void)
{

#ifdef __MNL_SUPPORT__

    kal_uint16 real_count;   
    DCL_HANDLE handle;
	UART_CTRL_RX_AVAIL_T data;
    
    handle = DclSerialPort_Open(gps_uart_port, 0);
    DclSerialPort_Control(handle, SIO_CMD_GET_RX_AVAIL, (DCL_CTRL_DATA_T*)&data);
	real_count = data.u2RetSize;

    // If there is no data in UART, we can't enable sleep mode
    if ((real_count > 0) &&
        (mtk_gps_context_p->gps_state == MNL_RUNNING))
    {
        GPS_TRACE((TRACE_GROUP_4, GPS_SLEEP_TRC_UART_DATA));      
        mtk_gps_start_timer(MTK_GPS_SLEEP_MODE_TIMER, gpsDataTimeoutPeriod * 60 / 13, (kal_timer_func_ptr)gps_uart_rx_timeout_handler, 0); 
        GPS_TRACE((TRACE_GROUP_4, GPS_SLEEP_TRC_START_TIMER,                     
                  gpsDataRXTime, MTK_GPS_SLEEP_MODE_TIMER, gpsDataTimeoutPeriod));      
    }
    else
    { 
        gpsDataEndTime = L1I_GetTimeStamp();     
        if ((gps_eint_channel != 0xFF) &&
            (gps_eint_debounce_enable == 1))
        {
            if ((gpsDataEndTime - gpsDataStartTime) < gpsDataPeriod)
            {
                gpsWakeUpTime =  gpsDataPeriod * 3 / 2 - (gpsDataEndTime - gpsDataStartTime) - gpsDataGuardTime;
            }
            else
            {
                gpsWakeUpTime =  gpsDataPeriod * 3 / 2 - (0xFFFFFFFF - gpsDataStartTime + gpsDataEndTime) - gpsDataGuardTime;
            }
        }
        else
        {
            if ((gpsDataEndTime - gpsDataStartTime) < gpsDataPeriod)
            {
                gpsWakeUpTime = gpsDataPeriod - (gpsDataEndTime - gpsDataStartTime) - gpsDataGuardTime;    
            }
            else
            {
                gpsWakeUpTime = gpsDataPeriod - (0xFFFFFFFF - gpsDataStartTime + gpsDataEndTime) - gpsDataGuardTime;    
            }

            mtk_gps_start_timer(MTK_GPS_SLEEP_MODE_TIMER, gpsWakeUpTime * 60 / 13, (kal_timer_func_ptr)gps_uart_wakeup_handler, 0);
            GPS_TRACE((TRACE_INFO, GPS_TRC_INF_SLEEP_START_WAKEUP_TIMER, 
                gpsWakeUpTime, gps_sleep_enable_flag));
            GPS_TRACE((TRACE_GROUP_4, GPS_SLEEP_TRC_START_TIMER,
                       gpsDataEndTime, MTK_GPS_SLEEP_MODE_TIMER, gpsWakeUpTime)); 

        }

        if ((1 == gps_sleep_enable_flag) &&
            (GPS_CHECK_TIMEOUT(gpsDataEndTime, gpsDataTXTime, gpsDataPeriod)))
        {
            if ((gps_eint_channel != 0xFF) ||    
                ((GPS_CHECK_TIMEOUT(gpsDataEndTime, gpsPowerOnTime, gpsPowerOnStablePeriod)) &&
                 (GPS_CHECK_TIMEOUT(gpsDataEndTime, gpsFixTime, gpsPowerOnStablePeriod))))        
            {   
                L1SM_SleepEnable(mtk_gps_sleep_handle);              
                GPS_TRACE((TRACE_GROUP_4, GPS_SLEEP_TRC_ENABLE_SLEEP,
                           gpsDataEndTime));
            }
        }    
    }

#else  /* NOT __MNL_SUPPORT__ */

    kal_uint16 real_count;    
    DCL_HANDLE handle;
	UART_CTRL_RX_AVAIL_T data;
	
    // We need to check if there is any data in UART
    handle = DclSerialPort_Open(gps_uart_port, 0);
    DclSerialPort_Control(handle, SIO_CMD_GET_RX_AVAIL, (DCL_CTRL_DATA_T*)&data);
	real_count = data.u2RetSize;

    // If there is no data in UART, we can't enable sleep mode
    if ((real_count > 0) &&
        (gps_context_p->gps_state == GPS_POWERON_STATE))
    {
        GPS_TRACE((TRACE_GROUP_4, GPS_SLEEP_TRC_UART_DATA));      
        gps_start_timer(GPS_SLEEP_MODE_TIMER, gpsDataTimeoutPeriod * 60 / 13, (kal_timer_func_ptr)gps_uart_rx_timeout_handler, 0); 
        GPS_TRACE((TRACE_GROUP_4, GPS_SLEEP_TRC_START_TIMER,                     
                  gpsDataRXTime, GPS_SLEEP_MODE_TIMER, gpsDataTimeoutPeriod));      
    }
    else
    { 
        gpsDataEndTime = L1I_GetTimeStamp();     
        if ((gps_eint_channel != 0xFF) &&
            (gps_eint_debounce_enable == 1))
        {
            if ((gpsDataEndTime - gpsDataStartTime) < gpsDataPeriod)
            {
                gpsWakeUpTime =  gpsDataPeriod * 3 / 2 - (gpsDataEndTime - gpsDataStartTime) - gpsDataGuardTime;
            }
            else
            {
                gpsWakeUpTime =  gpsDataPeriod * 3 / 2 - (0xFFFFFFFF - gpsDataStartTime + gpsDataEndTime) - gpsDataGuardTime;
            }
        }
        else
        {
            if ((gpsDataEndTime - gpsDataStartTime) < gpsDataPeriod)
            {
                gpsWakeUpTime = gpsDataPeriod - (gpsDataEndTime - gpsDataStartTime) - gpsDataGuardTime;    
            }
            else
            {
                gpsWakeUpTime = gpsDataPeriod - (0xFFFFFFFF - gpsDataStartTime + gpsDataEndTime) - gpsDataGuardTime;    
            }

            gps_start_timer(GPS_SLEEP_MODE_TIMER, gpsWakeUpTime * 60 / 13, (kal_timer_func_ptr)gps_uart_wakeup_handler, 0);
            GPS_TRACE((TRACE_INFO, GPS_TRC_INF_SLEEP_START_WAKEUP_TIMER, 
            gpsWakeUpTime, gps_sleep_enable_flag));
            GPS_TRACE((TRACE_GROUP_4, GPS_SLEEP_TRC_START_TIMER,
                   gpsDataEndTime, GPS_SLEEP_MODE_TIMER, gpsWakeUpTime)); 

        }

        if ((1 == gps_sleep_enable_flag) &&
            (GPS_CHECK_TIMEOUT(gpsDataEndTime, gpsDataTXTime, gpsDataPeriod)))
        {
            if ((gps_eint_channel != 0xFF) ||    
                ((GPS_CHECK_TIMEOUT(gpsDataEndTime, gpsPowerOnTime, gpsPowerOnStablePeriod)) &&
                 (GPS_CHECK_TIMEOUT(gpsDataEndTime, gpsFixTime, gpsPowerOnStablePeriod))))        
            {   
                L1SM_SleepEnable(gps_sleep_handle);              
                GPS_TRACE((TRACE_GROUP_4, GPS_SLEEP_TRC_ENABLE_SLEEP,
                           gpsDataEndTime));
            }
        }    
    }

#endif  /* __MNL_SUPPORT__ */

}


/*****************************************************************************
 * FUNCTION
 *  gps_uart_rx_sleep_handler
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gps_uart_rx_sleep_handler(void)
{

#ifdef __MNL_SUPPORT__
    
    gpsDataRXTime = L1I_GetTimeStamp();
    if ((GPS_CHECK_TIMEOUT(gpsDataRXTime, gpsDataStartTime, gpsDataPeriod/2)))
    {
        gpsDataStartTime = gpsDataRXTime;
    }
    mtk_gps_stop_timer(MTK_GPS_SLEEP_MODE_TIMER);
    GPS_TRACE((TRACE_GROUP_4, GPS_SLEEP_TRC_STOP_TIMER,
               gpsDataRXTime, MTK_GPS_SLEEP_MODE_TIMER));  
         
    mtk_gps_start_timer(MTK_GPS_SLEEP_MODE_TIMER, gpsDataTimeoutPeriod * 60 / 13, (kal_timer_func_ptr)gps_uart_rx_timeout_handler, 0);
    GPS_TRACE((TRACE_GROUP_4, GPS_SLEEP_TRC_START_TIMER,
               gpsDataRXTime, MTK_GPS_SLEEP_MODE_TIMER, gpsDataTimeoutPeriod));    
    if (1 == gps_wakeup_cmd_flag)
    {    
        EINT_UnMask(gps_eint_channel);            
        gps_wakeup_cmd_flag = 0;
    }
    
#else  /* NOT __MNL_SUPPORT__ */

    gpsDataRXTime = L1I_GetTimeStamp();
    if ((gpsDataStartTime == 0 && gpsDataRXTime == 0) ||
        (GPS_CHECK_TIMEOUT(gpsDataRXTime, gpsDataStartTime, gpsDataPeriod/2)))
    {
        gpsDataStartTime = gpsDataRXTime;
    }
    gps_stop_timer(GPS_SLEEP_MODE_TIMER);
    GPS_TRACE((TRACE_GROUP_4, GPS_SLEEP_TRC_STOP_TIMER,
               gpsDataRXTime, GPS_SLEEP_MODE_TIMER));  
         
    gps_start_timer(GPS_SLEEP_MODE_TIMER, gpsDataTimeoutPeriod * 60 / 13, (kal_timer_func_ptr)gps_uart_rx_timeout_handler, 0);
    GPS_TRACE((TRACE_GROUP_4, GPS_SLEEP_TRC_START_TIMER,
               gpsDataRXTime, GPS_SLEEP_MODE_TIMER, gpsDataTimeoutPeriod));    
    if (1 == gps_wakeup_cmd_flag)
    {    
        EINT_UnMask(gps_eint_channel);            
        gps_wakeup_cmd_flag = 0;
    }

#endif  /* __MNL_SUPPORT__ */

}


/*****************************************************************************
 * FUNCTION
 *  void gps_uart_enable_sleep_handle(void)
 * DESCRIPTION
 *  enable gps sleep mechanism, default  enable
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gps_uart_enable_sleep_handle(void)
{
    gps_sleep_enable_flag = 1;
}

/*****************************************************************************
 * FUNCTION
 *  void gps_uart_disable_sleep_handle(void)
 * DESCRIPTION
 *  disable gps sleep mechanism
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gps_uart_disable_sleep_handle(void)
{
    gps_sleep_enable_flag = 0;
}

/*****************************************************************************
 * FUNCTION
 *  gps_uart_tx_sleep_handler
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gps_uart_tx_sleep_handler(void)
{

#ifdef __MNL_SUPPORT__
    
    gpsDataTXTime = L1I_GetTimeStamp();
    if (mtk_gps_context_p->gps_state == MNL_RUNNING)
    {                   
        L1SM_SleepDisable(mtk_gps_sleep_handle); 
        mtk_gps_stop_timer(MTK_GPS_SLEEP_MODE_TIMER);
        GPS_TRACE((TRACE_GROUP_4, GPS_SLEEP_TRC_STOP_TIMER,
                   gpsDataRXTime, MTK_GPS_SLEEP_MODE_TIMER));  
    
    } 
    
#else  /* NOT __MNL_SUPPORT__ */

    gpsDataTXTime = L1I_GetTimeStamp();
    if (gps_context_p->gps_state == GPS_POWERON_STATE)
    {                   
        L1SM_SleepDisable(gps_sleep_handle); 
        gps_stop_timer(GPS_SLEEP_MODE_TIMER);
        GPS_TRACE((TRACE_GROUP_4, GPS_SLEEP_TRC_STOP_TIMER,
                   gpsDataRXTime, GPS_SLEEP_MODE_TIMER));  
    
    } 
                                 
#endif  /* __MNL_SUPPORT__ */

}

/*****************************************************************************
 * FUNCTION
 *  GPS_EINT_Handler
 * DESCRIPTION
 *  Handle EINT HISR
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/    
void GPS_EINT_Handler(void)
{ 
#ifdef __MNL_SUPPORT__
    if(mtk_gps_context_p->gps_state != MNL_POWEROFF) 
    {
        ilm_struct *ilm_ptr;   

        if (gps_eint_channel != 0xFF)
        {    
            EINT_Mask(gps_eint_channel);
        }
        L1SM_SleepDisable(mtk_gps_sleep_handle);        
        
        ilm_ptr = allocate_ilm(MOD_DRV_HISR);
        ilm_ptr->msg_id = MSG_ID_MNL_HOST_WAKE_UP_IND;
        ilm_ptr->local_para_ptr = NULL;
        ilm_ptr->peer_buff_ptr = NULL;
        ilm_ptr->src_mod_id = MOD_DRV_HISR;
        ilm_ptr->dest_mod_id = MOD_MNL;
        ilm_ptr->sap_id = GPS_MNL_SAP;		
        msg_send_ext_queue( ilm_ptr);    
    }
#else  /* NOT __MNL_SUPPORT__ */
    if (gps_context_p->gps_state != GPS_POWEROFF_STATE)
    {
        ilm_struct *ilm_ptr;   
        if (gps_eint_channel != 0xFF)
        {    
            EINT_Mask(gps_eint_channel);
        }
        L1SM_SleepDisable(gps_sleep_handle); 
        
        ilm_ptr = allocate_ilm(MOD_DRV_HISR);
        ilm_ptr->msg_id = MSG_ID_GPS_HOST_WAKE_UP_IND;
        ilm_ptr->local_para_ptr = NULL;
        ilm_ptr->peer_buff_ptr = NULL;
        ilm_ptr->src_mod_id = MOD_DRV_HISR;
        ilm_ptr->dest_mod_id = MOD_GPS;
        ilm_ptr->sap_id = GPS_MNL_SAP;		
        msg_send_ext_queue( ilm_ptr);    
    }
#endif  /* __MNL_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  gps_host_wake_up_ind_handler
 * DESCRIPTION
 *  Handle EINT HISR
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/ 
void gps_host_wake_up_ind_handler(void)
{ 
    
#ifdef __MNL_SUPPORT__

    if (mtk_gps_context_p->gps_state == MNL_RUNNING)
    {
        extern mtk_gps_vrd_command(void *buff, const char *str, int argu);
        mtk_gps_vrd_command( NULL, "COMD", GPS_WAKE_UP_ACK_COMMAND_NUM );
        GPS_TRACE((TRACE_GROUP_4, GPS_SLEEP_TRC_SEND_ACK));              
        gps_wakeup_cmd_flag = 1;
        mtk_gps_stop_timer(MTK_GPS_SLEEP_MODE_TIMER);
        mtk_gps_start_timer(MTK_GPS_SLEEP_MODE_TIMER, gpsDataPeriod / 2 * 60 / 13, (kal_timer_func_ptr)gps_uart_wakeup_handler, 0);    
        GPS_TRACE((TRACE_GROUP_4, GPS_SLEEP_TRC_START_TIMER,
                   gpsDataRXTime, MTK_GPS_SLEEP_MODE_TIMER, gpsDataPeriod / 2)); 
    }

#else  /* NOT __MNL_SUPPORT__ */

    if (gps_context_p->gps_state == GPS_POWERON_STATE)
    {
        DCL_HANDLE handle;
	    UART_CTRL_PUT_BYTES_T data;
        
        data.u4OwenrId = MOD_GPS;
    	data.u2Length = 13;
    	data.puBuffaddr = "$PMTK850*3F\x0d\x0a";
    	handle = DclSerialPort_Open(gps_uart_port, 0);
    	DclSerialPort_Control(handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*)&data);
	  
        GPS_TRACE((TRACE_GROUP_4, GPS_SLEEP_TRC_SEND_ACK));                      
        gps_wakeup_cmd_flag = 1;
        gps_stop_timer(GPS_SLEEP_MODE_TIMER);
        gps_start_timer(GPS_SLEEP_MODE_TIMER, gpsDataPeriod / 2 * 60 / 13, (kal_timer_func_ptr)gps_uart_wakeup_handler, 0);    
        GPS_TRACE((TRACE_GROUP_4, GPS_SLEEP_TRC_START_TIMER,
                   gpsDataRXTime, GPS_SLEEP_MODE_TIMER, gpsDataPeriod / 2)); 
    }    

#endif

}

/*****************************************************************************
 * FUNCTION
 *  gps_enter_power_saving_mode
 * DESCRIPTION
 *  Enter Power Saving Mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/ 
void gps_enter_power_saving_mode(void)
{ 
    
#ifdef __MNL_SUPPORT__
    if (1 == gps_power_saving_mode_type)
    {    
        gps_set_power_saving_mode(1);
    }
    else
    {
        GPS_Shutdown();
    }
#else  /* __MNL_SUPPORT__ */
    GPS_Shutdown();
#endif
    GPS_TRACE((TRACE_FUNC,GPS_TRC_GPS_ENTER_POWER_SAVEING_MODE));
}

/*****************************************************************************
 * FUNCTION
 *  gps_enter_normal_fix_mode
 * DESCRIPTION
 *  Enter Normal Fix Mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/ 
void gps_enter_normal_fix_mode(void)
{ 

#ifdef __MNL_SUPPORT__    
    if (1 == gps_power_saving_mode_type)
    {
        gps_set_power_saving_mode(0);
    }
    else
    {
        GPS_Init(NULL);
    }
#else  /* __MNL_SUPPORT__ */
    GPS_Init(NULL);    
#endif  /* NOT __MNL_SUPPORT__ */
    GPS_TRACE((TRACE_FUNC,GPS_TRC_GPS_ENTER_NORMAL_FIX_MODE));

}


/*****************************************************************************
 * FUNCTION
 *  gps_enter_automatic_power_saving_mode
 * DESCRIPTION
 *  Enter Automatic Power Saving Mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/ 
void gps_enter_automatic_power_saving_mode(kal_uint8 fix_flag, float speed)
{
    static kal_uint32 gps_ps_no_fix_count = 0;
    static kal_uint32 gps_ps_normal_fix_count = 0;
    static kal_uint32 gps_ps_ephemeris_count = 0;
    static kal_uint32 gps_ps_ephemeris_flag = 0;

    if (0 == fix_flag)    /* fix_flag = 0 : No Fix */
    {
        gps_ps_normal_fix_count = 0;
        gps_ps_no_fix_count++;
        if (gps_ps_no_fix_count > gpsPSNoFixLimit)
        {
            gps_ps_ephemeris_flag = 0;
        }
        GPS_TRACE((TRACE_FUNC,GPS_TRC_GPS_NO_FIX_COUNT, gps_ps_no_fix_count));
    }
    else /* 2D or 3D fix*/
    {
        gps_ps_no_fix_count = 0;
        gps_ps_normal_fix_count++;
        gps_ps_ephemeris_count++;
        // It needs 30 seconds to receive all ephemeris data
        if (gps_ps_normal_fix_count > gpsPSNormalFixLimit)
        {
            gps_ps_normal_fix_count = 0;
            gps_ps_ephemeris_flag = 1;
        }
        // It we receive all ephemeris data over 2 hour, we need to reset the counter
        if (gps_ps_ephemeris_count > gpsPSEphemerisLimit)
        {
            gps_ps_ephemeris_count = 0;
            gps_ps_normal_fix_count = 0; 
            gps_ps_no_fix_count = 0;
            gps_ps_ephemeris_flag = 0;
        }
        GPS_TRACE((TRACE_FUNC,GPS_TRC_GPS_NORMAL_FIX_COUNT, gps_ps_normal_fix_count));
    }
    
    /* Receive all ephemeris data */
    if ((1 == gps_ps_ephemeris_flag) &&
        (gps_ps_normal_fix_count != 0))    
    {
        kal_print_string_trace(MOD_GPS, TRACE_FUNC, "[APSM] speed = %f", speed);    
                
        if (speed < gpsPSSpeedLimit)
        {
            GPS_TRACE((TRACE_FUNC,GPS_TRC_GPS_SPEED_LOW_NORMAL_FIX_COUNT, gps_ps_normal_fix_count));
        }
        else
        {
            gps_ps_normal_fix_count = 0;
            GPS_TRACE((TRACE_FUNC,GPS_TRC_GPS_SPEED_HIGHNORMAL_FIX_COUNT, gps_ps_normal_fix_count));
        }
        if (gps_ps_normal_fix_count >= gpsPSNormalTimeCount)
        {
            gps_ps_normal_fix_count = 0;                                                 
            gps_stop_timer(GPS_SLEEP_MODE_TIMER);
            GPS_TRACE((TRACE_INFO, GPS_TRC_INF_SLEEP_AUTO_POWER_SAVING, 1000 * gpsPSPowerSavingTimeCount));
            gps_enter_power_saving_mode();                     
            gps_start_timer(GPS_SLEEP_MODE_TIMER, 1000 * gpsPSPowerSavingTimeCount, (kal_timer_func_ptr)gps_enter_normal_fix_mode, 0);            
        }  
    }                              

}
#endif /* __GPS_SUPPORT__ */
