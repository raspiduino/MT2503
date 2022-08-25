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
 *   video_recorder_clock_utility_v2.c
 *
 * Project:
 * --------
 *	MTK
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
 *
 ****************************************************************************/


#include "drv_features_video.h"


#ifdef __VE_DCM_WITH_COMPRESSION__
#include "dcmgr.h"  // for DCM


#pragma arm section code = "DYNAMIC_CODE_VEENC_ROCODE", rodata = "DYNAMIC_CODE_VEENC_RODATA"
#endif  // __VE_DCM_WITH_COMPRESSION__


#ifdef __VE_VIDEO_ARCHI_V2__


#if defined(__VE_MPEG4_ENC_SUPPORT__) || defined(__VE_H264_ENC_SW_SUPPORT__) || defined(__VE_AVI_ENC_SUPPORT__)

#include "drv_comm.h"                       // for drv_trace1(), drv_trace8(),
#include "video_comm_component_v2.h"        // for VideoCommGetState()
#include "video_types_v2.h"
#include "video_recorder_clock_utility_if_v2.h"
#include "video_recorder_clock_utility_v2.h"


/******************************************************************************
* Static global variable(s)
******************************************************************************/
static VRCLK_MGR _rVrclkMgr;


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VRCLK_UpdateTimer(void)
{
    kal_uint32 u4TimeScale = _rVrclkMgr.u4TimeScale;

    if(_rVrclkMgr.fgUseAudioClock == KAL_FALSE)
    {
        kal_uint64 u8TimeInterval;
        kal_uint64 u8PrevSysTime = _rVrclkMgr.u8SysTime;

        _rVrclkMgr.u8SysTime = video_get_current_time();
        u8TimeInterval = video_get_duration_tick((kal_uint32)u8PrevSysTime, (kal_uint32)(_rVrclkMgr.u8SysTime));
        _rVrclkMgr.u8CurrentTimeStamp += u8TimeInterval;
    }
    else
    {
        _rVrclkMgr.u8CurrentTimeStamp = Media_A2V_GetInterruptCount();
    }

    _rVrclkMgr.u8CurrentTime =
        VIDEO_ANYBASE_TO_ANYBASE(_rVrclkMgr.u8CurrentTimeStamp,
        u4TimeScale, VRCLK_TIME_SCALE_MICRO_SECOND);
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
void VRCLK_SetClockProperties(kal_bool fgUseAudioClock, Media_Format eAudioFormat)
{
    _rVrclkMgr.fgUseAudioClock = fgUseAudioClock;
    if (fgUseAudioClock == KAL_FALSE)
    {
        _rVrclkMgr.eAudioFormat = MEDIA_FORMAT_UNKNOWN;
        _rVrclkMgr.u4TimeScale = VRCLK_32K_CLOCK;
    }
    else
    {
        _rVrclkMgr.eAudioFormat = eAudioFormat;
        _rVrclkMgr.u4TimeScale = Media_A2V_GetRecInterruptTimeScale(_rVrclkMgr.eAudioFormat,
            VRCLK_SAMPLING_RATE_8000);
    }
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
void VRCLK_ResetAll(void)
{
    kal_mem_set((void*)&_rVrclkMgr, 0, sizeof(_rVrclkMgr));
    _rVrclkMgr.eAudioFormat = MEDIA_FORMAT_UNKNOWN;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // 0
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
void VRCLK_ResetTime(void)
{
    _rVrclkMgr.u8CurrentTime = 0;
    _rVrclkMgr.u8CurrentTimeStamp = 0;
    _rVrclkMgr.u8SysTime = 0;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
void VRCLK_StartClock(void)
{
    _rVrclkMgr.u8SysTime = video_get_current_time();
    _rVrclkMgr.fgUpdateTimer = KAL_TRUE;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
void VRCLK_StopClock(void)
{
    _VRCLK_UpdateTimer();
    _rVrclkMgr.u8SysTime = 0;   // reset to 0 at stop
    _rVrclkMgr.fgUpdateTimer = KAL_FALSE;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
void VRCLK_GetCurrentTime(kal_uint64 *pu8Param)
{
    if (_rVrclkMgr.fgUpdateTimer == KAL_TRUE)
    {
        _VRCLK_UpdateTimer();
    }
    *pu8Param = _rVrclkMgr.u8CurrentTime;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
void VRCLK_GetCurrentTimeStamp(kal_uint64 *pu8Param)
{
    if (_rVrclkMgr.fgUpdateTimer == KAL_TRUE)
    {
        _VRCLK_UpdateTimer();
    }
    *pu8Param = _rVrclkMgr.u8CurrentTimeStamp;
}


#endif  // __VE_VIDEO_ARCHI_V2__


#endif  // defined(__VE_MPEG4_ENC_SUPPORT__) || defined(__VE_H264_ENC_SW_SUPPORT__) || defined(__VE_AVI_ENC_SUPPORT__)


#ifdef __VE_DCM_WITH_COMPRESSION__
#pragma arm section code, rodata
#endif  // __VE_DCM_WITH_COMPRESSION__

