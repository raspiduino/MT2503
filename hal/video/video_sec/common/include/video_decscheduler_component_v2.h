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
 *  video_decscheduler_com.h
 *
 * Project:
 * --------
 *	MAUI - Video Architecture 2
 *
 * Description:
 * ------------
 *
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
 *
 *
 *
 ****************************************************************************/
#define __VDS_RECOVER__

#ifndef VIDEO_DECSCHEDULER_COMPONENT_H
#define VIDEO_DECSCHEDULER_COMPONENT_H

#include "video_types_v2.h"
#include "video_comm_component_v2.h"

#include "video_decscheduler_component_if_v2.h"

#include "kal_general_types.h"
#include "video_buffer_management_v2.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"

#include "drv_features_video.h"

#ifndef __VE_SLIM_PROJECT__
#define __VDS_DBG__
#define __VDS_SWLA__
#endif

#ifdef __VE_STOPTIME_SUPPORT__
#define __VDS_STOPTIME__
#endif

#ifdef __VE_BES_TS_SUPPORT__    
#define __VDS_SPEEDPLAY__
#endif

#ifdef __VE_SUBTITLE_SUPPORT__
#define __VDS_SECONDPORT__
#define VDS_PORT_COUNT 2
#else
#define VDS_PORT_COUNT 1
#endif

#ifdef __VE_DURATION_MODE__
#define __VDS_DURATION_MODE__
#define VDS_DURATIONSTEP 5  // 0; 5; 10; 15;
#endif

#define VDSSLICEWINDOW 1  // Olny 1 slice

#ifdef __VE_VIDEO_ARCHI_V2__

#pragma arm section rodata="SECONDARY_ROCODE"
const static VIDEO_PORT_TYPE_T eVDSPortType[2] = {VIDEO_PORT_VIDEO_DATA, VIDEO_PORT_SUBTITLE};
#pragma arm section rodata

#define TIME_DIFF_30FPS 30000

#define TIME_INTERVAL_CHECK 10000  // The time interval for clock to periodically check
#define TIME_MIN_DURATION   10000  // 10 ms
#define TIME_MAX_DURATION   100000    // 100 ms
#ifdef __VDS_DURATION_MODE__
#define TIME_MAX_JUMP_DURATION   500000    // 500 ms
#endif

#define VDS_TIMEBASE_DSP 1000
#define VDS_TIMEBASE_KAL 4615    // 1 KAL TIMER unit == 4.615 ms

#define CLOCK_1X_SPEED 100
#define VDS_DEFAULT_EXPECTED_BUF_NUM 1

#define RECOVER_NUM 2

typedef struct
{
    kal_uint32 u4RecoverCount;
    VIDEO_EVENT_TYPE_T eRecoverEvent;
	VIDEO_DBG_ID_T eRecoverID;	
}VIDEO_DECSCH_RECOVERINFO_T;

typedef struct
{
    VIDEO_COMM_STATE_T rCommState;
    kal_uint32 u4VideoFrameDuration;  // us
    kal_uint32 u4DrvTime;  // for fgAudioOn false use

    kal_uint64 u8StartTime;
    kal_uint64 u8CurrTime;
    kal_uint64 u8StopTime;

    kal_uint32 u4PlaySpeed;  // 100 = 1x

    kal_uint64 u8MaxVideoTime;
    kal_uint64 u8LatestTimeStamp[2];
	
    VIDEO_DECSCH_RECOVERINFO_T rRecover[RECOVER_NUM];
    kal_uint64 u8JumpTime;	//candidate jump time
    kal_uint64 u8JumpTargetTime; //target jump time	
    kal_uint32 u4JumpFixDuration; // us	    

    kal_int32 i4DurationParam;
    kal_uint32 u4DurationStep;
    kal_uint32 u4VideoDuration;
    kal_uint32 u4EmptyTime[VDSSLICEWINDOW];		
    kal_uint32 u4EmptyTimeIndex;
    kal_bool fgJumpAdjustParam;

    kal_timerid rTimerID;
    kal_mutexid eMutex;  // for VideoComm

    VIDEO_EXTMEM_HANDLER_T *pExtMemHdr;	

    kal_bool fgStartEvent; // false: Notify Start Event Not Yet, true: Already Notify Start Event
    kal_bool fgClockEnable; // true: clock enable
    kal_bool fgAudioOn;  // true: use aduio DSP timer, false: use kal_timer
    kal_bool fgDurationSet;  //true: clock has set duration; false: clock not set duration
    kal_bool fgComplete;
    kal_bool fgResetSubtitle;

}VIDEO_DECSCHEDULER_STATE_T;

// To check whether memory allocation is sufficient or not
// If build error occurred here, please enlarge memory allocation of VIDEO_DECSCHEDULER_MGR_LEN
typedef char VDSMgrCheckSize[(VIDEO_DECSCHEDULER_MGR_LEN > sizeof(VIDEO_DECSCHEDULER_STATE_T)) ? 1 : -1];


#define AOF( exp )          \
{                           \
    if( !( exp ) )          \
    {ASSERT(0);}          \
}

#ifdef __VDS_SWLA__
#define VDS_START_LOGGING(sym)  VIDEO_START_LOGGING(sym)
#define VDS_STOP_LOGGING(sym) VIDEO_STOP_LOGGING(sym)
#define VDS_LABEL_LOGGING(sym) VIDEO_LABEL_LOGGING(sym)
#else
#define VDS_START_LOGGING(sym)  do{}while(0);
#define VDS_STOP_LOGGING(sym) do{}while(0);
#define VDS_LABEL_LOGGING(sym) do{}while(0);
#endif

#endif /* __VE_VIDEO_ARCHI_V2__ */
#endif //VIDEO_DECSCHEDULER_COMPONENT_H
