/***********************************************************************
*   This software/firmware and related documentation ("MediaTek Software") 
*   are protected under relevant copyright laws. The information contained 
*   herein is confidential and proprietary to MediaTek Inc. and/or its licensors.
*
*   Without the prior written permission of MediaTek Inc. and/or its licensors, 
*   any reproduction, modification, use or disclosure of MediaTek Software, and 
*   information contained herein, in whole or in part, shall be strictly prohibited.
*
*   MediaTek Inc. (C) [2008]. All rights reserved.
*
*************************************************************************/ 
/*****************************************************************************
 *
 * Filename:
 * ---------
 *   mtk_gps_task.h
 *
 * Project:
 * --------
 * 
 *
 * Description:
 * ------------
 *   This file implements gps_mt3326 component task type
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/

#ifndef _MTK_GPS_TASK_
#define _MTK_GPS_TASK_

#include "kal_public_api.h"
#include "kal_general_types.h"
    
/*******************************************************************************
 * Type Definitions
 *******************************************************************************/
typedef enum 
{
  PORTING_FALSE,
  PORTING_TRUE
} proting_bool;


/*******************************************************************************
 * Task related Definitions
 *******************************************************************************/

typedef enum
{
    MTK_GPS_SLEEP_MODE_TIMER = 0,
//    MTK_GPS_RTC_INIT_TIMER,
    MAX_NUM_OF_MTK_GPS_TIMER
} mtk_gps_timer_enum;


typedef struct
{
    eventid event_id;
    kal_timer_func_ptr callback_func;
    void *arg;
} mtk_gps_timer_table_struct;


typedef enum
{
    MNL_POWERON = 0,
    MNL_POWEROFF,
    MNL_RUNNING,
    MNL_RESTART,
    MNL_TERMINATE,
    MNL_STATE_TOTAL
} mtk_gps_state_enum;


typedef struct
{
    mtk_gps_state_enum gps_state;
    event_scheduler *event_scheduler_ptr;
} mtk_gps_task_struct;

extern void mtk_gps_start_timer(kal_uint8 timer_id, kal_uint32 period, kal_timer_func_ptr timer_expiry, void *arg);
extern void mtk_gps_stop_timer(kal_uint8 timer_id);
/*******************************************************************************
 * Constant definition
 *******************************************************************************/
#ifndef NULL
#define NULL               0
#endif

#define MTK_GPS_UART_READ_SIZE 30


/*************************************************************************
* GPS Definition
 *************************************************************************/
#define PMTK_MAX_FIELD_NUM 32
#define PMTK_MAX_FIELD_LENGTH 32
#define PMTK_MAX_PKT_LENGTH 256

#define PMTK_ACK                     1
#define PMTK_AGPS_MODE               290
#define PMTK_SET_AGPS_ACCEPT_MAP     292
#define PMTK_API_GET_AGPS_FTIME      484
#define PMTK_API_GET_AGPS_LOC        485
#define PMTK_API_GET_AGPS_MEAS       486
#define PMTK_API_GET_AGPS_ASS_BIT    487
#define PMTK_API_GET_AGPS_LAST_LOC   488
#define PMTK_DT_EPH                  710
#define PMTK_DT_ALM                  711
#define PMTK_DT_TIME                 712
#define PMTK_DT_LOC                  713
#define PMTK_DT_CLK                  714
#define PMTK_DT_KLB                  715
#define PMTK_DT_UCP                  716
#define PMTK_DT_BSV                  717
#define PMTK_DT_ACQ                  718
#define PMTK_DT_FTIME                719
#define PMTK_DT_RTCM                 720
#define PMTK_DT_AGPS_REQ_ASSIST      730
#define PMTK_DT_AGPS_LOC_EST         731
#define PMTK_DT_AGPS_GPS_MEAS        732
#define PMTK_DT_AGPS_LOC_ERR         733
#define PMTK_DT_AGPS_FTIME           734
#define PMTK_DT_AGPS_FTIME_ERR       735


#define GPS_INIT_FINISH_EVENT           (0x0001)
#define GPS_SHUTDOWN_FINISH_EVENT       (0x0002)
#if defined(__GPS_ADAPTOR_SUPPORT__) && !defined(__GPS_EPO_DOWNLOAD__)
#define MAUI_EPO_PATCH
#endif

#endif  /* _MTK_GPS_TASK_ */
