/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
 *   video_comm.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Video common definitions
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef VIDEO_COMM_V2_H
#define VIDEO_COMM_V2_H

#include "drv_features_video.h"

/* The following files are newly added for RHR. */
// #include "kal_non_specific_general_types.h"
#include "kal_general_types.h"
#include "med_status.h"
#include "kal_release.h"


#define VIDEO_COMMON_TIME_BASE          1000000

#define VIDEO_ANYBASE_TO_ANYBASE(_TIME_SRC, _TIME_BASE_SRC, _TIME_BASE_DST)    ((kal_uint64)_TIME_SRC*(kal_uint64)_TIME_BASE_DST/(kal_uint64)_TIME_BASE_SRC)
#define VIDEO_MAX(a,b)                 ( ((a)>(b))? a : b )
#define VIDEO_MIN(a,b)                 ( ((a)<(b))? a : b )

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
      VIDEO_SCENARIO_DECODE=0,
      VIDEO_SCENARIO_ENCODE,
      VIDEO_SCENARIO_MERGE_FILE,
      VIDEO_SCENARIO_VCALL,
      VIDEO_SCENARIO_SRC_PROVIDER,
      VIDEO_TOTAL_SCENARIO
} VIDEO_SCENARIO_T;

#ifdef __VE_VIDEO_COMMON__
extern kal_uint32 video_get_current_time(void);
extern MED_STATUS VIDEO_GetLastError(void);
extern kal_uint32 video_get_current_time(void);
extern kal_uint32 video_get_duration_tick(kal_uint32 previous_time, kal_uint32 current_time);
extern kal_uint32 video_get_duration_ms(kal_uint32 previous_time);
#endif /* __VE_VIDEO_COMMON__ */

/********************************
*
*   Resource management
*
********************************/
#define VRES_DISABLE    (1)
#define VRES_ENABLE     (0)

#ifndef VE_UNUSED
    #define VE_UNUSED(x)   (void)x
#endif

/*********************************************
*   Mutex users
*   - Player
*     - Source: 6 under streaming or 1 otherwise
*     - Decoder: 1
*     - Scheduler: 1
*     - Renderer: 1
*   - Recorder
*     - Encoder: 2
*     - Muxer: 3
*   - VT
*     - VT IL: 1
*
*   Note that the data has to update if we g-
*   oing to reduce the number of Mutex
*********************************************/
#define _VIDEO_MUTEX_NUMBER   16
typedef enum
{
    MUTEX_USER_NONE   =   0,
    MUTEX_USER_CTRL,
    MUTEX_USER_DECODER_FCM,    //FLUSH_CALLBACK_MUTEX
    MUTEX_USER_DECODER_SFM,    //SYNC_FRAME_MUTEX
    MUTEX_USER_DECODER_V2COMMON,  //Decoder common component usage
    MUTEX_USER_SCHEDULER,
    MUTEX_USER_RM_PROVIDER,
    MUTEX_USER_SOURCE_COMMON,
    MUTEX_USER_SOURCE_VBUF,
    MUTEX_USER_SOURCE_VBS,
    MUTEX_USER_SOURCE_VPRI,
    MUTEX_USER_SOURCE_ABUF,
    MUTEX_USER_SOURCE_ABS,
    MUTEX_USER_SUBTITLE_DECODER,
    MUTEX_USER_ENCODER,
    MUTEX_USER_RECORDER_SOURCE,
    MUTEX_USER_MUXER_V2COMMON,
    MUTEX_USER_MUXER,
    MUTEX_USER_MUXER2,
    MUTEX_USER_PLAYERMPL,
    MUTEX_USER_CLIPPERMPL,
    MUTEX_USER_CLIPPERMPL_TIMER,
    MUTEX_USER_DCM,
    MUTEX_USER_ENCODER_V2COMMON,
    MUTEX_USER_VTMPL,
    MUTEX_USER_VIDEO_RENDERER,
    MUTEX_USER_VIDEO_RECORDERMPL,
    MUTEX_USER_CLIPPERMPL_MAIN
} VIDEO_MUTEX_USER_T;

kal_mutexid _VideoGetMutex(VIDEO_MUTEX_USER_T eUserID);
void _VideoFreeMutex(VIDEO_MUTEX_USER_T eUserID, kal_mutexid rMutexID);
#define VideoGetMutex(UserID)   _VideoGetMutex(UserID)
#define VideoFreeMutex(UserID, MutexID)  _VideoFreeMutex(UserID, MutexID)

#define _VIDEO_EVG_NUMBER   6
typedef enum
{
    EVG_USER_NONE = 0,
    EVG_USER_DECODER,
    EVG_USER_MUXER,
    EVG_USER_MPL_PLAYER,
    EVG_USER_MPL_CLIPPER,
    EVG_USER_RECORDER_SRC
} VIDEO_EVENT_GROUP_USER_T;

kal_eventgrpid _VideoGetEventGroup(VIDEO_EVENT_GROUP_USER_T eUserID);
void _VideoFreeEventGroup(VIDEO_EVENT_GROUP_USER_T eUserID, kal_eventgrpid rEVGID);
#define VideoGetEventGroup(UserID)   _VideoGetEventGroup(UserID)
#define VideoFreeEventGroup(UserID, EVGID)  _VideoFreeEventGroup(UserID, EVGID)

#define _VIDEO_TIMER_NUMBER   8
typedef enum
{
    TIMER_USER_NONE = 0,
    TIMER_USER_SOURCE,
    TIMER_USER_DECODER,
    TIMER_USER_SCHEDULER,
    TIMER_USER_PLAYERMPL,
    TIMER_USER_ENCODER,
    TIMER_USER_CLIPPERMPL,
    TIMER_USER_MUXER
} VIDEO_TIMER_USER_T;

kal_timerid _VideoGetTimer(VIDEO_TIMER_USER_T eUserID);
void _VideoFreeTimer(VIDEO_TIMER_USER_T eUserID, kal_timerid rTimerID);
#define VideoGetTimer(UserID)   _VideoGetTimer(UserID)
#define VideoFreeTimer(UserID, TimerID)  _VideoFreeTimer(UserID, TimerID)

#ifdef __VE_VIDEO_COMMON__
void VideoInitSource(void);
#endif /* __VE_VIDEO_COMMON__ */

#ifdef __VE_DCM_WITH_COMPRESSION__
void VideoDCMLoad(kal_uint32 u4DCMUser);
void VideoDCMUnLoad(kal_uint32 u4DCMUser);
#endif

/********************************
*
*   Video Trace
*
********************************/
#if defined(__VE_SLIM_PROJECT__)
    #define VIDEO_DEBUG_LV1
#else
    #define VIDEO_DEBUG_LV1
    #define VIDEO_DEBUG_LV2
    #define VIDEO_DEBUG_LV3
#endif

#if defined(VIDEO_DEBUG_LV1)
#define VIDEO_TRACE0_G10(trc) drv_trace0(TRACE_GROUP_10, trc)
#define VIDEO_TRACE1_G10(trc, v1) drv_trace1(TRACE_GROUP_10, trc, v1)
#define VIDEO_TRACE2_G10(trc, v1, v2) drv_trace2(TRACE_GROUP_10, trc, v1, v2)
#define VIDEO_TRACE4_G10(trc, v1, v2, v3, v4) drv_trace4(TRACE_GROUP_10, trc, v1, v2, v3, v4)
#define VIDEO_TRACE8_G10(trc, v1, v2, v3, v4, v5, v6, v7, v8) drv_trace8(TRACE_GROUP_10, trc, v1, v2, v3, v4, v5, v6, v7, v8)
#else
#define VIDEO_TRACE0_G10(trc) do {} while (0)
#define VIDEO_TRACE1_G10(trc, v1) do {} while (0)
#define VIDEO_TRACE2_G10(trc, v1, v2) do {} while (0)
#define VIDEO_TRACE4_G10(trc, v1, v2, v3, v4) do {} while (0)
#define VIDEO_TRACE8_G10(trc, v1, v2, v3, v4, v5, v6, v7, v8) do {} while (0)
#endif  //(VIDEO_DEBUG_LV1)

#if defined(VIDEO_DEBUG_LV2)
#define VIDEO_TRACE0_G9(trc) drv_trace0(TRACE_GROUP_9, trc)
#define VIDEO_TRACE1_G9(trc, v1) drv_trace1(TRACE_GROUP_9, trc, v1)
#define VIDEO_TRACE2_G9(trc, v1, v2) drv_trace2(TRACE_GROUP_9, trc, v1, v2)
#define VIDEO_TRACE4_G9(trc, v1, v2, v3, v4) drv_trace4(TRACE_GROUP_9, trc, v1, v2, v3, v4)
#define VIDEO_TRACE8_G9(trc, v1, v2, v3, v4, v5, v6, v7, v8) drv_trace8(TRACE_GROUP_9, trc, v1, v2, v3, v4, v5, v6, v7, v8)
#else
#define VIDEO_TRACE0_G9(trc) do {} while (0)
#define VIDEO_TRACE1_G9(trc, v1) do {} while (0)
#define VIDEO_TRACE2_G9(trc, v1, v2) do {} while (0)
#define VIDEO_TRACE4_G9(trc, v1, v2, v3, v4) do {} while (0)
#define VIDEO_TRACE8_G9(trc, v1, v2, v3, v4, v5, v6, v7, v8) do {} while (0)
#endif  //(VIDEO_DEBUG_LV2)

#if defined(VIDEO_DEBUG_LV3)
#define VIDEO_TRACE0_G8(trc) drv_trace0(TRACE_GROUP_8, trc)
#define VIDEO_TRACE1_G8(trc, v1) drv_trace1(TRACE_GROUP_8, trc, v1)
#define VIDEO_TRACE2_G8(trc, v1, v2) drv_trace2(TRACE_GROUP_8, trc, v1, v2)
#define VIDEO_TRACE4_G8(trc, v1, v2, v3, v4) drv_trace4(TRACE_GROUP_8, trc, v1, v2, v3, v4)
#define VIDEO_TRACE8_G8(trc, v1, v2, v3, v4, v5, v6, v7, v8) drv_trace8(TRACE_GROUP_8, trc, v1, v2, v3, v4, v5, v6, v7, v8)
#else
#define VIDEO_TRACE0_G8(trc) do {} while (0)
#define VIDEO_TRACE1_G8(trc, v1) do {} while (0)
#define VIDEO_TRACE2_G8(trc, v1, v2) do {} while (0)
#define VIDEO_TRACE4_G8(trc, v1, v2, v3, v4) do {} while (0)
#define VIDEO_TRACE8_G8(trc, v1, v2, v3, v4, v5, v6, v7, v8) do {} while (0)
#endif  //(VIDEO_DEBUG_LV3)

#ifdef __cplusplus
}
#endif

#endif /*VIDEO_COMM_V2_H*/
