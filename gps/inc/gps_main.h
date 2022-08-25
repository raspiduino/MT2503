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
 *  gps_main.h
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifndef _GPS_MAIN_H_
#define _GPS_MAIN_H_

#include "kal_public_api.h"
#include "kal_general_types.h"
        
#define GPS_AGPS_POS_REQ_TIMER_MAX 3 
#define GPS_AGPS_MEAS_REQ_TIMER_MAX 3 

#ifdef __AGPS_SUPPORT__ //mtk04096
extern kal_mutexid g_agps_supl_mutex;
#endif


typedef enum
{
    GPS_SLEEP_MODE_TIMER = 0,
    GPS_UART_RING_BUFFER_EXP_TIMER,
    GPS_UART_POWER_ON_CHECK_VERSION_TIMER,
    GPS_UART_POWER_ON_CHECK_CHIP_ID_TIMER,
    GPS_UART_ENABLE_DEBUG_INFO_TIMER,
    GPS_UART_AUTHENTICATION_TIMER,
    GPS_UART_SWITCH_MODE_TIMER,
    GPS_AGPS_ASSIST_CMD_WRITE_TIMER,
    GPS_AGPS_ASSIST_CMD_WRITE_EXP_TIMER,
    GPS_AGPS_QUERY_TIMER,
    GPS_AGPS_POS_REQ_BASE_TIME,
    GPS_AGPS_POS_REQ_TIME_END = GPS_AGPS_POS_REQ_BASE_TIME + GPS_AGPS_POS_REQ_TIMER_MAX - 1,
    GPS_AGPS_MEAS_REQ_BASE_TIME,
    GPS_AGPS_MEAS_REQ_TIME_END =GPS_AGPS_MEAS_REQ_BASE_TIME + GPS_AGPS_MEAS_REQ_TIMER_MAX - 1,
    GPS_FRAME_SYNC_REQ_TIMER,
    GPS_UART_NMEA_SIMULATE_TIMER,
    GPS_POWER_ON_OFF_TIMER,
    GPS_TIME_SYNC_TIMER,
    GPS_EPO_AIDING_TIMER,
    GPS_EPO_DOWNLOAD_TIMER,
    GPS_EPO_DOWNLOAD_QEOP_TIMEOUT_TIMER,
    GPS_EPO_DOWNLOAD_3DAY_TIMEOUT_TIMER,
    MAX_NUM_OF_GPS_TIMER
} gps_timer_enum;

typedef struct
{
    eventid event_id;
    kal_timer_func_ptr callback_func;
    void *arg;
} gps_timer_table_struct;

typedef enum
{
    GPS_POWERON_STATE = 0,
    GPS_POWEROFF_STATE,
    GPS_STATE_TOTAL
} gps_state_enum;

typedef struct
{
    gps_state_enum gps_state;
    event_scheduler *event_scheduler_ptr;
} gps_context_struct;

extern void gps_start_timer(kal_uint8 timer_id, kal_uint32 period, kal_timer_func_ptr timer_expiry, void *arg);
extern void gps_stop_timer(kal_uint8 timer_id);

void agps_assist_ref_location_finished_callback(void);
void agps_assist_ref_time_finished_callback(void);
void agps_assist_epo_finished_callback(void);

#endif /* _GPS_MAIN_H_ */


