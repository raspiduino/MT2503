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
 *  video_decscheduler_component_v2.c
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
#include "drv_features_video.h"
#ifdef __VE_VIDEO_ARCHI_V2__

#include "visualhisr.h"
#include "vcodec_v2_trc.h"

#include "video_types_v2.h"
#include "video_comm_component_v2.h"
#include "video_decscheduler_component_v2.h"
#include "video_comm_v2.h"

#include "kal_general_types.h"
#include "kal_public_api.h"

#include "l1audio.h"

#include "video_fluency_if.h"

#ifdef __VDS_DURATION_MODE__
#include "video_smooth_display.h"
#endif

#ifdef __VE_DCM_WITH_COMPRESSION__
#include "dcmgr.h" //DCM

#pragma arm section code = "DYNAMIC_CODE_VEDEC_ROCODE", rodata = "DYNAMIC_CODE_VEDEC_RODATA"
#endif

static VIDEO_DECSCHEDULER_STATE_T* prVideoDecSchedulerState;

#if 0
#if defined(__MTK_INTERNAL__) && defined(__VE_MTK_TARGET__)
/* under construction !*/
#endif
#endif

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
#endif

/*****************************************************************************
 *
 * Internal Function
 *
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *    _VideoDecSchComputeFrameDuration
 * DESCRIPTION
 *  This function is use to compute frame duration.
 *  1) Compute frame duration by the old frame timestamp subtract current time.
 *  2) If duration large than TIME_MAX_DURATION, set TIME_MAX_DURATION.
 * PARAMETERS
 *  None.
 * RETURNS
 *  kal_uint32.
 *  The time duration computed by frame timestamp
 ****************************************************************************/
static __inline kal_uint32 _VideoDecSchComputeFrameDuration()
{
    kal_uint32 u4Duration = 0;
    VIDEO_COMM_STATE_T *prCommState = &prVideoDecSchedulerState->rCommState;
    kal_uint64 u8TimeStamp = 0;
    kal_uint32 index = 0 ;	
#ifndef __VDS_SECONDPORT__	
    VIDEO_BUFFERHEADER_TYPE_T rBuffHeader[1];
#else
    VIDEO_BUFFERHEADER_TYPE_T rBuffHeader[2];
    for(index = 0; index < 2; index++)
#endif
    {
        if(VideoCommGetInputBuffDataExt(prCommState, &rBuffHeader[index], index))
        {
            u8TimeStamp = rBuffHeader[index].u8TimeStamp;
#ifdef __VDS_SECONDPORT__				
            if(index == 1 && u8TimeStamp > rBuffHeader[0].u8TimeStamp && rBuffHeader[0].u8TimeStamp != 0)
            {
                // second queue smallest timestamp > fisrt queue smallest timestamp
                if(u8TimeStamp > rBuffHeader[0].u8TimeStamp + TIME_MIN_DURATION)
                {
                    u8TimeStamp = rBuffHeader[0].u8TimeStamp;                
                }
            }
#endif
        }
    }
    if(u8TimeStamp > prVideoDecSchedulerState->u8CurrTime)
    {
        u4Duration = (kal_uint32)(u8TimeStamp - prVideoDecSchedulerState->u8CurrTime);
    }

    return u4Duration;
}

/*****************************************************************************
 * FUNCTION
 *    _VideoDecSchTimeoutHdlr
 * DESCRIPTION
 *  This function is Timeout handler function.
 *  Context: LISR
 *  1) Check timeout before set duration. (Maybe other HISR run too long)
 *  2) Active visuhisr
 * PARAMETERS
 *  None.
 * RETURNS
 *  None.
 ****************************************************************************/
static void _VideoDecSchTimeoutHdlr(void)
{
#ifdef __VDS_DBG__
    video_dbg_trace(VIDEO_DBG_OWNER_DECSCHEDULER, VIDEO_DBG_DECSCHEDULER_LISR_TIMEOUT, video_get_current_time());	
#endif

    /* fgDurationSet check */
#if 0
#if defined(__MTK_INTERNAL__) && defined(__VE_MTK_TARGET__)
/* under construction !*/
#endif    	
#endif
    {
        if(prVideoDecSchedulerState->fgDurationSet != KAL_TRUE)    
        {
            ASSERT(0);
        }
    }

    prVideoDecSchedulerState->fgDurationSet = KAL_FALSE;

    visual_active_hisr(VISUAL_DECSCH_TIMEOUT_HISR_ID);

}

/*****************************************************************************
 * FUNCTION
 *    _VideoDecSchSetFrameDuration
 * DESCRIPTION
 *  This function is used to set frame duration.
 *  Context: VISU HISR or MED
 *  1) If the duration small than TIME_INTERVAL_CHECK, set TIME_INTERVAL_CHECK.
 *  2) Compute the duration according to timebase. (Audio on: 1000, Audio off: 4615)
 *  3) Call Media_A2V_SetInterruptTime or kal_set_timer to set.
 * PARAMETERS
 *  None.
 * RETURNS
 *  None.
 ****************************************************************************/
static void _VideoDecSchSetFrameDuration()
{
    kal_uint32 u4Duration_us = 0;
    kal_uint32 u4SetDuration = 0;
    kal_uint32 u4Timescale = 0;

    VDS_START_LOGGING("VST");

#ifdef __VDS_DURATION_MODE__
    u4Duration_us = VideoSmoothComputeFrameDuration(prVideoDecSchedulerState, VDS_PORT_COUNT);
#else
    u4Duration_us = _VideoDecSchComputeFrameDuration();
#endif

    if(u4Duration_us == 0)
    {
        u4Duration_us = TIME_INTERVAL_CHECK;    
    }
    else if(u4Duration_us < TIME_MIN_DURATION)
    {
        u4Duration_us = TIME_MIN_DURATION;
    }
    else if(u4Duration_us > TIME_MAX_DURATION)
    {
#ifdef __VDS_DURATION_MODE__    
        if(KAL_FALSE == prVideoDecSchedulerState->fgJumpAdjustParam)    
#endif			
        {
            u4Duration_us = TIME_MAX_DURATION;
        }
#ifdef __VDS_DURATION_MODE__    
        else if(u4Duration_us > TIME_MAX_JUMP_DURATION)
        {
            u4Duration_us = TIME_MAX_JUMP_DURATION;        
        }			
#endif		
    }	
#ifdef __VDS_SECONDPORT__
    if(NULL != VideoCommGetInputProcessBufferFunc(&prVideoDecSchedulerState->rCommState, 1))
    {
        if(u4Duration_us > TIME_INTERVAL_CHECK)
        {
            u4Duration_us = TIME_INTERVAL_CHECK;
        }
    }
#endif	

    if (prVideoDecSchedulerState->fgAudioOn)
    {
        u4Timescale = VDS_TIMEBASE_DSP;
    }
    else
    {
        u4Timescale = VDS_TIMEBASE_KAL;
    }

    prVideoDecSchedulerState->u4VideoFrameDuration = u4Duration_us;	
    u4SetDuration = prVideoDecSchedulerState->u4VideoFrameDuration / u4Timescale;
#ifdef __VDS_SPEEDPLAY__
    u4SetDuration = u4SetDuration * 100 / prVideoDecSchedulerState->u4PlaySpeed;
#endif

    drv_trace4(TRACE_GROUP_10, VDS_SET_DURATION, u4SetDuration, u4Duration_us, (kal_uint32)prVideoDecSchedulerState->u8CurrTime, NULL);

#ifdef __VDS_DBG__
    if(u4SetDuration == 0)
    {
        ASSERT(0);
    }
#endif	

    prVideoDecSchedulerState->fgDurationSet = KAL_TRUE;	

#ifdef __VDS_DBG__
    video_dbg_trace(VIDEO_DBG_OWNER_DECSCHEDULER, VIDEO_DBG_DECSCHEDULER_SETDURATION, u4SetDuration);	
#endif	

    if (prVideoDecSchedulerState->fgAudioOn)
    {
        Media_A2V_SetInterruptTime(u4SetDuration);
    }
    else
    {
        kal_set_timer(prVideoDecSchedulerState->rTimerID, (kal_timer_func_ptr)_VideoDecSchTimeoutHdlr, NULL, u4SetDuration, 0);
    }

    VDS_STOP_LOGGING("VST");
}

/*****************************************************************************
 * FUNCTION
 *    _VideoDecSchStartAVSync
 * DESCRIPTION
 *  Enable AV sync by call Media_A2V_EnableInterrupt and set frame duration
 *  Context: MED
 *
 * PARAMETERS
 *  None.
 * RETURNS
 *  None.
 ****************************************************************************/
static void _VideoDecSchStartAVSync(void)
{
    if(prVideoDecSchedulerState->fgAudioOn)
    {
        Media_A2V_DisableDspSleep(KAL_TRUE); //disable DSP sleep mode
            	
        Media_A2V_HookInterrupt(_VideoDecSchTimeoutHdlr);
        /* The initial delay is handled by audio */
        Media_A2V_EnableInterrupt(KAL_TRUE, 0);
    }
	
	prVideoDecSchedulerState->u4DrvTime = video_get_current_time();
	
    /* Compute next duration and set timeout */
    _VideoDecSchSetFrameDuration();

}

/*****************************************************************************
 * FUNCTION
 *    _VideoDecSchStopAVSync
 * DESCRIPTION
 *  Disable AV sync by call Media_A2V_EnableInterrupt or kal_cancel_timer
 *  Context: MED
 *
 * PARAMETERS
 *  None.
 * RETURNS
 *  None.
 ****************************************************************************/
static void _VideoDecSchStopAVSync(void)
{
    if (prVideoDecSchedulerState->fgAudioOn)
    {
        Media_A2V_EnableInterrupt(KAL_FALSE, 0);
        Media_A2V_HookInterrupt(NULL);		
        Media_A2V_DisableDspSleep(KAL_FALSE); //enable DSP sleep mode
    }
    else
    {
        kal_cancel_timer(prVideoDecSchedulerState->rTimerID);
    }
}

/*****************************************************************************
 * FUNCTION
 *    _VideoDecSchEvent
 * DESCRIPTION
 *  Send event to ILClient.
 * PARAMETERS
 *  param1 : [IN]  VIDEO_EVENT_TYPE_T eEvent
 *                 Event to send.  
 *  param2 : [IN]  VIDEO_DBG_ID_T eID
 *                 Event ID for video_dbg_trace.  (debug use)
 *  param3 : [IN]  kal_uint32 u4Param
 *                 Param for debug use
 *  param4 : [IN]  kal_uint32 u4Line
 *                 call this function line.  
 * RETURNS
 *  None.
 ****************************************************************************/
static void _VideoDecSchEvent(VIDEO_EVENT_TYPE_T eEvent,VIDEO_DBG_ID_T eID, kal_uint32 u4Param, kal_uint32 u4Line)
{
    video_dbg_trace(VIDEO_DBG_OWNER_DECSCHEDULER, eID, *(kal_uint32*)u4Param);
    drv_trace4(TRACE_GROUP_10, VDS_ACK_EVENT, eEvent, *(kal_uint32*)u4Param, prVideoDecSchedulerState->u8CurrTime, u4Line);

    prVideoDecSchedulerState->rCommState.prCallback->pfnEventHandler(eEvent, VIDEO_COMMAND_NOTIFY, u4Param, NULL);
}

/*****************************************************************************
 * FUNCTION
 *    _VideoDecSchCheckEndEvent
 * DESCRIPTION
 *  Check end condition reach or not. (buffer header flag)
 *  Context: VISU HISR or V2DEC
 * PARAMETERS
 *  param1 : [IN]  kal_uint64 u8Timestamp
 *                 The video playback timestamp differece with current time. 
 *  param2 : [IN]  kal_uint32 u4Line
 *                 call this function line.  
 * RETURNS
 *  kal_bool
 *  If the end condition reach return KAL_TRUE, else return KAL_FALSE
 ****************************************************************************/
static __inline kal_bool _VideoDecSchCheckEndEvent(VIDEO_BUFFERHEADER_TYPE_T* prBuffHeader)
{
#ifdef __VDS_STOPTIME__
    if(prBuffHeader->u8TimeStamp >= prVideoDecSchedulerState->u8StopTime) //lint !e655
    {
    	_VideoDecSchEvent(VIDEO_EVENT_STOP, VIDEO_DBG_DECSCHEDULER_COMPLETE, (kal_uint32)&prVideoDecSchedulerState->u8CurrTime, NULL);    
#ifdef __MTK_TARGET__
        prVideoDecSchedulerState->u8StopTime = (kal_uint64)0xFFFFFFFFFFFFFFFFULL; // Unsigned Long Long
#else
        prVideoDecSchedulerState->u8StopTime = (kal_uint64)0xFFFFFFFFFFFFFFFF; // Unsigned Long Long
#endif
    }
#endif // __VDS_STOPTIME__

    if(prBuffHeader->eFlags & VIDEO_BUFFERFLAG_EOF) //lint !e655
    {
        VDS_LABEL_LOGGING("VSO");
        prVideoDecSchedulerState->fgComplete = KAL_TRUE;
    	_VideoDecSchEvent(VIDEO_EVENT_COMPLETE, VIDEO_DBG_DECSCHEDULER_COMPLETE, (kal_uint32)&prVideoDecSchedulerState->u8CurrTime, NULL);
#ifdef __VDS_RECOVER__
#ifdef __VDS_DBG__
        drv_trace2(TRACE_GROUP_10, VDS_RECOVER_REPORT, prVideoDecSchedulerState->rRecover[0].u4RecoverCount, prVideoDecSchedulerState->rRecover[1].u4RecoverCount);
#endif
#endif
	    return KAL_TRUE;
    }
	return KAL_FALSE;	

}

/*****************************************************************************
 * FUNCTION
 *    _VideoDecSchSendToRender
 * DESCRIPTION
 *  Send buffer header to Render
 *  Context: VISU HISR or V2DEC
 *  Render always can receive it, and always return VIDEO_ERROR_NONE.
 * PARAMETERS
 *  param1 : [IN]  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader
 *                 The bufferheader to render. 
 * RETURNS
 *  None.
 ****************************************************************************/
static __inline void _VideoDecSchSendToRender(VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader, kal_uint32 u4Port)
{
    VIDEO_COMM_STATE_T *prCommState = &prVideoDecSchedulerState->rCommState;

    VDS_START_LOGGING("VSR");

    video_dbg_trace(VIDEO_DBG_OWNER_DECSCHEDULER, VIDEO_DBG_DECSCHEDULER_SENDTORENDER, (kal_uint32)prBuffHeader->u8TimeStamp);
    drv_trace4(TRACE_GROUP_10, VDS_BUFFER_OUT, (kal_uint32)prBuffHeader->pu1Buffer, (kal_uint32)prBuffHeader->u8TimeStamp, VideoCommGetInputBuffQUsedNum(prCommState, u4Port), (kal_uint32)prVideoDecSchedulerState->u8CurrTime);

#ifdef __VDS_RECOVER__
    if(prVideoDecSchedulerState->fgClockEnable)
    {
        prVideoDecSchedulerState->u8LatestTimeStamp[u4Port] = prBuffHeader->u8TimeStamp;
    }
#endif // __VDS_RECOVER__	


//#ifdef __VDS_DBG__
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    VideoCommGetOutputProcessBufferFunc(prCommState, prBuffHeader->u4OutputPort)(prBuffHeader);
#endif

    VDS_STOP_LOGGING("VSR");

}

/*****************************************************************************
 * FUNCTION
 *    _VideoDecSchCheckRecoverEvent
 * DESCRIPTION
 *  Check AV sync time, if the time difference large than tolerance, ack the RecoverEvent to IL Client.
 *  Context: VISU HISR
 * PARAMETERS
 *  param1 : [IN]  kal_uint64 u8Timediff
 *                 The video playback timestamp differece with current time. 
 * RETURNS
 *  None.
 ****************************************************************************/
#ifdef __VDS_RECOVER__

#if 1 //#ifdef __VE_FLUENCY_CONTROL_ENABLE__ 
static void _VideoDecSchCheckRecoverEvent(VFC_OP_DATA_CHECK_RECOVER_RESULT_T* prCheckRecoverResult)
{
    kal_uint32 index;
    
    for(index = 0; index < RECOVER_NUM; index++)
    {
        VIDEO_DECSCH_RECOVERINFO_T* rRecover = &prVideoDecSchedulerState->rRecover[index];
    	if(KAL_TRUE == prCheckRecoverResult->afgCheckResult[index])
    	{
    	    _VideoDecSchEvent(rRecover->eRecoverEvent, rRecover->eRecoverID, (kal_uint32)&prCheckRecoverResult->u8JumpEndTime, NULL);	
       
            rRecover->u4RecoverCount++;
    	}
    }
}


#else
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
#endif //__VE_FLUENCY_CONTROL_ENABLE__

#endif //__VDS_RECOVER__

/*****************************************************************************
 * FUNCTION
 *    _VideoDecSchTriggerJumpEvent
 * DESCRIPTION
 *  Check AV sync, if CCU want to jump, ack the RecoverEvent to IL Client.
 *  Context: VISU HISR or med
 * PARAMETERS
 *  param1 : [IN]  kal_bool fgNeed2Jump
 *                 Jump flag set by CCU. 
 *  param2 : [IN]  kal_uint32 u4Line
 *                 check jump event line.
 * RETURNS
 *  None.
 ****************************************************************************/
#ifdef __VDS_RECOVER__
#if 1 //#ifdef __VE_FLUENCY_CONTROL_ENABLE__ 
static void _VideoDecSchTriggerJumpEvent(kal_bool fgNeed2Jump, kal_uint32 u4Line)
{
#ifdef __MTK_TARGET__
    if(prVideoDecSchedulerState->u8JumpTime != (kal_uint64)0xFFFFFFFFFFFFFFFFULL)
#else
    if(prVideoDecSchedulerState->u8JumpTime != (kal_uint64)0xFFFFFFFFFFFFFFFF)
#endif    
    {
        drv_trace2(TRACE_GROUP_10, VDS_JUMP_RESULT, 1, fgNeed2Jump);    
        if(KAL_TRUE == fgNeed2Jump)
        {
            _VideoDecSchEvent(VIDEO_EVENT_RECOVER_JUMPI, VIDEO_DBG_DECSCHEDULER_RECOVER0, (kal_uint32)&prVideoDecSchedulerState->u8JumpTime, u4Line); 

#ifdef __MTK_TARGET__
            prVideoDecSchedulerState->u8JumpTime = (kal_uint64)0xFFFFFFFFFFFFFFFFULL; // Unsigned Long Long
#else
            prVideoDecSchedulerState->u8JumpTime = (kal_uint64)0xFFFFFFFFFFFFFFFF; // Unsigned Long Long
#endif	                    
        }
    }
}

#endif //__VE_FLUENCY_CONTROL_ENABLE__
#endif //__VDS_RECOVER__

/*****************************************************************************
 * FUNCTION
 *    _VideoDecSchProcessBufferToRender
 * DESCRIPTION
 *  Send buffer header to Render
 *  Context: VISU HISR or V2DEC
 *  1) Send all timestamp small than current time buffer header to Render.
 *  2) Check End event.
 *  3) Update LastestTimeStamp
 *  4) Check Recover event.
 * PARAMETERS
 *  None.
 * RETURNS
 *  None.
 ****************************************************************************/
static void _VideoDecSchProcessBufferToRender(kal_uint32 u4Port)
{
    VIDEO_COMM_STATE_T *prCommState = &prVideoDecSchedulerState->rCommState;
    VIDEO_BUFFERHEADER_TYPE_T rBuffHeader;
    kal_bool fgSendOneFrame = KAL_FALSE;

    VFC_OP_DATA_JUMP_EVENT_T  rSetJumpResult;
    kal_bool fgNeed2Jump = KAL_FALSE;    
#ifdef __VDS_DURATION_MODE__	
    kal_bool fgBreak = KAL_TRUE;
#endif //__VDS_DURATION_MODE__


#ifdef __VDS_SECONDPORT__
    if(KAL_TRUE == prVideoDecSchedulerState->fgResetSubtitle && eVDSPortType[u4Port] == VIDEO_PORT_SUBTITLE)
    {
       return; 
    }
#endif		

    do
    {

//#ifdef __VE_FLUENCY_CONTROL_ENABLE__
#if 1
        {			   
            VFC_OP_DATA_PLAYBACK_STAT_T rPlaybackStat;
            rPlaybackStat.u8CurrTime 	   = prVideoDecSchedulerState->u8CurrTime;
#ifdef __VDS_SECONDPORT__
            if(eVDSPortType[u4Port] == VIDEO_PORT_VIDEO_DATA)
#endif				
            {
                rPlaybackStat.u8LatestTimeStamp = prVideoDecSchedulerState->u8LatestTimeStamp[u4Port];				  
                kal_mem_set(&rSetJumpResult, 0, sizeof(VFC_OP_DATA_JUMP_EVENT_T));
                VFC_IOCtrl(VFC_OP_SCH_UPDATE_AV_SYNC_TIME, &rPlaybackStat, &rSetJumpResult, NULL);

                if(KAL_TRUE == rSetJumpResult.fgNeed2Jump)
                {
                    fgNeed2Jump = KAL_TRUE;
#ifdef __VDS_DURATION_MODE__
                    VideoSmoothComputeJumpDuration(prVideoDecSchedulerState, &rSetJumpResult, u4Port);
#endif //__VDS_DURATION_MODE__					
                }		
            }
        }
#endif // __VE_FLUENCY_CONTROL_ENABLE__

	
       if(VideoCommGetInputBuffDataExt(prCommState, &rBuffHeader, u4Port))
       {
           if(rBuffHeader.u8TimeStamp <= prVideoDecSchedulerState->u8CurrTime)
           {
               if (VideoCommPopInputBuffExt(prCommState, &rBuffHeader, u4Port))
               {
                // Check End Event
#ifdef __VDS_SECONDPORT__                          	
                    if(eVDSPortType[u4Port] == VIDEO_PORT_VIDEO_DATA)
#endif								
                    {
                        if(_VideoDecSchCheckEndEvent(&rBuffHeader))
                        {
                            break;
                        }					
                    }
                    _VideoDecSchSendToRender(&rBuffHeader, u4Port);
					

#ifdef __VDS_DURATION_MODE__
                    if(VideoCommGetInputBuffDataExt(prCommState, &rBuffHeader, u4Port))
                    {

#ifdef __VDS_SECONDPORT__
                        if(eVDSPortType[u4Port] == VIDEO_PORT_VIDEO_DATA && rBuffHeader.u8TimeStamp < prVideoDecSchedulerState->u8LatestTimeStamp[u4Port] + TIME_DIFF_30FPS)
#else							
                        if(rBuffHeader.u8TimeStamp < prVideoDecSchedulerState->u8LatestTimeStamp[u4Port] + TIME_DIFF_30FPS)
#endif							
                        {
                            fgBreak = KAL_FALSE;
                        }	 
                    }
				
#endif //__VDS_DURATION_MODE__


                }
#ifdef __VDS_DBG__				
                else
                {
                    ASSERT(0);
                }
#endif // __VDS_DBG__				
            }
            else // timestamp > current time
            {
                break;
            }
        }
#ifdef __VDS_DURATION_MODE__
        else
        {		
            break;
        }
#else //__VDS_DURATION_MODE__
#ifdef __VDS_SECONDPORT__
        else if(eVDSPortType[u4Port] == VIDEO_PORT_VIDEO_DATA)  //only check video track for recover
#else
        else // no frame in input queue
#endif			
        {
        // AV sync check
#ifdef __VDS_RECOVER__
            if(prVideoDecSchedulerState->fgClockEnable)
            {    			    
                VFC_OP_DATA_CHECK_RECOVER_RESULT_T  rCheckRecoverResult;                
                kal_mem_set(&rCheckRecoverResult, 0, sizeof(VFC_OP_DATA_CHECK_RECOVER_RESULT_T));
                VFC_IOCtrl(VFC_OP_SCH_CHECK_AV_SYNC_STAT, NULL, &rCheckRecoverResult, NULL);
                _VideoDecSchCheckRecoverEvent(&rCheckRecoverResult);
            }            

            // Check Jump event
            _VideoDecSchTriggerJumpEvent(fgNeed2Jump, __LINE__);
    
#endif // __VDS_RECOVER__
            break;
        }	
#ifdef __VDS_SECONDPORT__
        else
        {
            break;
        }
#endif
#endif //__VDS_DURATION_MODE__
    }
#ifdef __VDS_DURATION_MODE__
    while(KAL_FALSE == fgBreak);

// AV sync check
#ifdef __VDS_RECOVER__
#ifdef __VDS_SECONDPORT__
    if(eVDSPortType[u4Port] == VIDEO_PORT_VIDEO_DATA)  //only check video track for recover
#endif
    {
        // Check Jump event
        _VideoDecSchTriggerJumpEvent(fgNeed2Jump, __LINE__);
			    
        if(KAL_TRUE == prVideoDecSchedulerState->fgClockEnable && prVideoDecSchedulerState->u8MaxVideoTime < prVideoDecSchedulerState->u8CurrTime)
        {					
            VFC_OP_DATA_CHECK_RECOVER_RESULT_T	rCheckRecoverResult;				
            kal_mem_set(&rCheckRecoverResult, 0, sizeof(VFC_OP_DATA_CHECK_RECOVER_RESULT_T));
            VFC_IOCtrl(VFC_OP_SCH_CHECK_AV_SYNC_STAT, NULL, &rCheckRecoverResult, NULL);
            _VideoDecSchCheckRecoverEvent(&rCheckRecoverResult);
        }			    
    }
#endif // __VDS_RECOVER__

#else
    while(1);
#endif //__VDS_DURATION_MODE__

}

/*****************************************************************************
 * FUNCTION
 *    _VideoDecSchCheckStartEvent
 * DESCRIPTION
 *  Check start condition reach or not.
 *  Context: V2DEC or MED
 * PARAMETERS
 *  param1 : [IN]  kal_uint32 u4Line
 *                 call this function line.  
 * RETURNS
 *  None.
 ****************************************************************************/
static void _VideoDecSchCheckStartEvent(kal_uint32 u4Line)
{
    VIDEO_COMM_STATE_T *prCommState = &prVideoDecSchedulerState->rCommState;
    kal_uint32 index = 0;

    // check start event not send yet
    if(prVideoDecSchedulerState->fgClockEnable)
    { 
        return;
    }
#ifdef __VDS_SECONDPORT__
    for(index = 0; index < 2; index++)
#endif
    {
        _VideoDecSchProcessBufferToRender(index);

#ifdef __VDS_SECONDPORT__
        if(eVDSPortType[index] == VIDEO_PORT_VIDEO_DATA)
#endif
        {
            VIDEO_BUFFERHEADER_TYPE_T rBuffHeader;
            kal_uint64 u8TimeStamp = 0;        
     
            if(VideoCommGetInputBuffDataExt(prCommState, &rBuffHeader, index))
            {
    	    	u8TimeStamp = rBuffHeader.u8TimeStamp;
            }

            // 1) The oldest buffer in input queue timestamp >= starttime
            // 2) Input queue frame >= expected buffer number
    
            if(u8TimeStamp >= prVideoDecSchedulerState->u8StartTime && VideoCommGetInputBuffQUsedNum(prCommState, index) >= VDS_DEFAULT_EXPECTED_BUF_NUM)
            {
                prVideoDecSchedulerState->fgStartEvent = KAL_TRUE;
                VDS_LABEL_LOGGING("VSS");
                _VideoDecSchEvent(VIDEO_EVENT_EXPECTED_BUF_NUM_RDY, VIDEO_DBG_DECSCHEDULER_START, (kal_uint32)&u8TimeStamp, u4Line);
            }
        }
    }
}	


/*****************************************************************************
 * FUNCTION
 *    _VideoDecSchFlushOutputQ
 * DESCRIPTION
 *  Send buffer header to Decoder
 *  Context: VISU HISR
 *  Decoder may return VIDEO_ERROR_BUFF_FULL, so if return value is not VIDEO_ERROR_NONE, repush this buffer header to output Q.
 * PARAMETERS
 *  None. 
 * RETURNS
 *  None.
 ****************************************************************************/
static void _VideoDecSchFlushOutputQ()
{
    VIDEO_COMM_STATE_T *prCommState = &prVideoDecSchedulerState->rCommState;
    VIDEO_BUFFERHEADER_TYPE_T rBuffHeader;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    kal_uint32 index = 0;

    VDS_START_LOGGING("VSF");

#ifdef __VDS_SECONDPORT__
    for(index = 0; index < 2; index++)
#endif
    {
        while(1)
        {
            if(VideoCommGetOutputBuffDataExt(prCommState, &rBuffHeader, index))
            {
                eError = VideoCommGetInputProcessBufferFunc(prCommState, index)(&rBuffHeader);
                if(eError == VIDEO_ERROR_NONE)
                {
                    VideoCommPopOutputBuffExt(prCommState, &rBuffHeader, index);
                }            
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
        
    }
    VDS_STOP_LOGGING("VSF");	
}

/*****************************************************************************
 * FUNCTION
 *    _VideoDecSchResetPort
 * DESCRIPTION
 *  Reset input and output quque in specified port
 *  Context: MED
 *  For subtitle port enable use, due to subtitle decoder may need to reset YUV buffer in same case.
 * PARAMETERS
 *  None. 
 * RETURNS
 *  None.
 ****************************************************************************/
#ifdef __VDS_SECONDPORT__
static void _VideoDecSchResetPort(VIDEO_PORT_TYPE_T u4PortType)
{
    VIDEO_COMM_STATE_T *prCommState = &prVideoDecSchedulerState->rCommState;
    kal_uint32 index;

    prVideoDecSchedulerState->fgResetSubtitle = KAL_TRUE;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	

    for(index = 0; index < 2 ;index++)
    {    
        if(eVDSPortType[index] == u4PortType)
        {
            VideoCommClrQ(&prCommState->rInputBuffQ[index]);
            VideoCommClrQ(&prCommState->rOutputBuffQ[index]);	
        }
    }
    prVideoDecSchedulerState->fgResetSubtitle = KAL_FALSE;	
}
#endif

/*****************************************************************************
 * FUNCTION
 *    _VideoDecSchHISR
 * DESCRIPTION
 *  Timeout handler of LISR
 *  Context: VISU HISR
 *  0) Update current time
 *  1  Flush output Q, return to Decoder
 *  2) Send YUV buffer to Render
 *  3) Compute next duration and set timeout
 *  4) AV sync check
 * PARAMETERS
 *  None.
 * RETURNS
 *  None.
 ****************************************************************************/
static void _VideoDecSchHISR(void)
{
    kal_uint32 index = 0;
    kal_uint32 uTimeInc = 0;	
#if 1
    VFC_OP_DATA_JUMP_EVENT_T  rSetJumpResult;
    kal_mem_set(&rSetJumpResult, 0, sizeof(VFC_OP_DATA_JUMP_EVENT_T));

#endif
	
    VDS_START_LOGGING("VSH");

    /* Update current time */
    if(prVideoDecSchedulerState->fgAudioOn)
    {
        uTimeInc = prVideoDecSchedulerState->u4VideoFrameDuration;
    }
    else
    {
        uTimeInc = video_get_duration_ms(prVideoDecSchedulerState->u4DrvTime)*1000;
    }

    prVideoDecSchedulerState->u4DrvTime = video_get_current_time();
    prVideoDecSchedulerState->u8CurrTime += uTimeInc;
	
    drv_trace1(TRACE_GROUP_10, VDS_HISR_ACTIVATE, (kal_uint32)prVideoDecSchedulerState->u8CurrTime);

#if 0
/* under construction !*/
/* under construction !*/
#ifdef __VDS_RECOVER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __VDS_SECONDPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // __VE_FLUENCY_CONTROL_ENABLE__	
#endif

#ifdef __VDS_DBG__
    AOF(prVideoDecSchedulerState->fgClockEnable);
#endif

    /* Send YUV buffer to Render */
#ifdef __VDS_SECONDPORT__
    for(index = 0; index < 2; index++)
#endif
    {
	_VideoDecSchProcessBufferToRender(index);
    }

    /* Compute next duration and set timeout */
    _VideoDecSchSetFrameDuration();
    VDS_STOP_LOGGING("VSH");

}



/*****************************************************************************
 *
 * Component API
 *
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *    VideoDecSchedulerInit
 * DESCRIPTION
 *  This function is used to init decode scheduler component.
 *  Context: MED
 *  1) Set component init variable.
 *  2) Call VideoCommInit.
 *  3) Set decode scheduler component defalt value.
 *  4) Register VISUAL_DECSCH_HISR_ID handler function
 * PARAMETERS
 *   None.
 * RETURNS
 *   VIDEO_ERROR_TYPE_T.
 ****************************************************************************/
static VIDEO_ERROR_TYPE_T VideoDecSchedulerInit(void)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
#ifndef __VDS_SECONDPORT__	
    VIDEO_PORT_CONFIG_T rIPortDec, rOPortRdr;    
#else    
    VIDEO_PORT_CONFIG_T rIPortDec[2], rOPortRdr[2]; 
#endif    
    VIDEO_COMPONENT_INIT_T rInitConfig;
    VIDEO_COMM_STATE_T *prCommState = &prVideoDecSchedulerState->rCommState;

#ifndef __VDS_SECONDPORT__
    // input port
    rIPortDec.ePortType = VIDEO_PORT_VIDEO_DATA;
    rIPortDec.fgSupplier = KAL_FALSE;
    rIPortDec.u4BuffSize = 0;
    // ~input port

    // output ports
    rOPortRdr.ePortType = VIDEO_PORT_VIDEO_DATA;
    rOPortRdr.fgSupplier = KAL_TRUE;
    rOPortRdr.u4BuffSize = 0;
    // ~output ports

#else
    kal_uint32 index;

    for(index = 0; index < 2; index++)
    {
        // input port
        rIPortDec[index].ePortType = eVDSPortType[index];
        rIPortDec[index].fgSupplier = KAL_FALSE;
        rIPortDec[index].u4BuffSize = 0;
        // ~input port
    
        // output ports
        rOPortRdr[index].ePortType = eVDSPortType[index];
        rOPortRdr[index].fgSupplier = KAL_TRUE;
        rOPortRdr[index].u4BuffSize = 0;
        // ~output ports
    }
#endif

    kal_mem_set(&rInitConfig, 0, sizeof(VIDEO_COMPONENT_INIT_T));

#ifdef __VDS_SECONDPORT__
    rInitConfig.prInputPort1 = &rIPortDec[0];
    rInitConfig.prOutputPort1 = &rOPortRdr[0];

    rInitConfig.prInputPort2= &rIPortDec[1];
    rInitConfig.prOutputPort2= &rOPortRdr[1];	

    rInitConfig.u4InputBuffQSize2 = VIDEO_DECSCHEDULER_INPUT_QUEUE_SIZE;
    rInitConfig.u4OutputBuffQSize2 = VIDEO_DECSCHEDULER_OUTPUT_QUEUE_SIZE;
#else
    rInitConfig.prInputPort1 = &rIPortDec;
    rInitConfig.prOutputPort1 = &rOPortRdr;
#endif	
    rInitConfig.u4InputBuffQSize = VIDEO_DECSCHEDULER_INPUT_QUEUE_SIZE;
    rInitConfig.u4OutputBuffQSize = VIDEO_DECSCHEDULER_OUTPUT_QUEUE_SIZE;

    rInitConfig.prExtMemHdlr = prVideoDecSchedulerState->pExtMemHdr;

    prVideoDecSchedulerState->eMutex = rInitConfig.eMutex = VideoGetMutex(MUTEX_USER_SCHEDULER);

    eError = VideoCommInit(prCommState, &rInitConfig, "VDS");
    AOF(eError == VIDEO_ERROR_NONE);

    prVideoDecSchedulerState->rTimerID = VideoGetTimer(TIMER_USER_SCHEDULER);

#ifdef __VDS_STOPTIME__ 
#ifdef __MTK_TARGET__
    prVideoDecSchedulerState->u8StopTime = (kal_uint64)0xFFFFFFFFFFFFFFFFULL; // Unsigned Long Long
#else
    prVideoDecSchedulerState->u8StopTime = (kal_uint64)0xFFFFFFFFFFFFFFFF; // Unsigned Long Long
#endif
#endif

#ifdef __VDS_RECOVER__			
    prVideoDecSchedulerState->rRecover[0].eRecoverEvent = VIDEO_EVENT_GET_JUMPTIME;			
    prVideoDecSchedulerState->rRecover[1].eRecoverEvent = VIDEO_EVENT_RECOVER_STOPAUDIO;			
    prVideoDecSchedulerState->rRecover[0].eRecoverID = VIDEO_DBG_DECSCHEDULER_GET_JUMPTIME;			
    prVideoDecSchedulerState->rRecover[1].eRecoverID = VIDEO_DBG_DECSCHEDULER_RECOVER1;

#ifdef __MTK_TARGET__
    prVideoDecSchedulerState->u8JumpTime = (kal_uint64)0xFFFFFFFFFFFFFFFFULL; // Unsigned Long Long
#else
    prVideoDecSchedulerState->u8JumpTime = (kal_uint64)0xFFFFFFFFFFFFFFFF; // Unsigned Long Long
#endif	
#endif		

#ifdef __VDS_DURATION_MODE__
    prVideoDecSchedulerState->u4DurationStep = VDS_DURATIONSTEP; 
    prVideoDecSchedulerState->i4DurationParam = 0;
#endif //__VDS_DURATION_MODE__

    VISUAL_Register_HISR(VISUAL_DECSCH_TIMEOUT_HISR_ID, _VideoDecSchHISR);

    return eError;
}

/*****************************************************************************
 * FUNCTION
 *    VideoDecSchedulerGetParameter
 * DESCRIPTION
 *  GetParameter function of DecScheduler component
 *  Context: MED
 *  Get decode scheduler component parameter.
 * PARAMETERS
 *  param1 : [IN]  VIDEO_PARAM_TYPE_T eCmd
 *                 The parameter which want to get. 
 *  param2 : [IN]  void *pParam
 *                 The parameter value . 
 * RETURNS
 *   VIDEO_ERROR_TYPE_T.
 ****************************************************************************/
static VIDEO_ERROR_TYPE_T VideoDecSchedulerGetParameter(VIDEO_PARAM_TYPE_T eCmd, void *pParam)
{
    const VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    VIDEO_COMM_STATE_T *prCommState = &prVideoDecSchedulerState->rCommState;
    kal_bool fgAudioOn;

    fgAudioOn = prVideoDecSchedulerState->fgAudioOn;

    switch(eCmd)
    {
    case VIDEO_PARAM_OUTPUT_BUFFER_PARAM:
        VideoCommGetOutputPortParam(prCommState, pParam);
        break;
    case VIDEO_PARAM_INPUT_BUFFER_PARAM:
        VideoCommGetInputPortParam(prCommState, pParam);
        break;
    case VIDEO_PARAM_CURR_TIME:
        {
            kal_uint64 u8CurrTime;// = 0;
            if (fgAudioOn)
            {
                Media_A2V_Video_GetPlayTime_S(&u8CurrTime);
                u8CurrTime *= 1000;
            }
            else
            {
                u8CurrTime = prVideoDecSchedulerState->u8CurrTime;
            }

            *(kal_uint64*)pParam = u8CurrTime;
            drv_trace2(TRACE_GROUP_10, VDS_GETPAR_CURRENT_TIME, u8CurrTime, fgAudioOn);
        }

        break;
    default:
//        ASSERT(0);
        break;
    }

    return eError;
}

/*****************************************************************************
 * FUNCTION
 *    VideoDecSchedulerSetParameter
 * DESCRIPTION
 *  SetParameter function of DecScheduler component
 *  Context: MED
 *  Change decode scheduler component parameter.
 * PARAMETERS
 *  param1 : [IN]  VIDEO_PARAM_TYPE_T eCmd
 *                 The parameter which want to set. 
 *  param2 : [IN]  void *pParam
 *                 The value which want to set. 
 * RETURNS
 *   VIDEO_ERROR_TYPE_T.
 ****************************************************************************/
static VIDEO_ERROR_TYPE_T VideoDecSchedulerSetParameter(VIDEO_PARAM_TYPE_T eCmd, void *pParam)
{
    const VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    VIDEO_COMM_STATE_T *prCommState = &prVideoDecSchedulerState->rCommState;

    drv_trace2(TRACE_GROUP_10, VDS_SET_PARAM, eCmd, *(kal_uint32*)pParam);
    switch(eCmd)
    {
    case VIDEO_PARAM_OUTPUT_BUFFER_PARAM:
        VideoCommSetOutputPortParam(prCommState, pParam);
        break;

    case VIDEO_PARAM_INPUT_BUFFER_PARAM:
        VideoCommSetInputPortParam(prCommState, pParam);
        break;

    case VIDEO_PARAM_CLOCK_ENABLE: // Init (reset to KAL_FALSE)
        {
            kal_bool fgClockEnable = *(kal_bool*)pParam;			
            video_dbg_trace(VIDEO_DBG_OWNER_DECSCHEDULER, VIDEO_DBG_DECSCHEDULER_ENABLE, fgClockEnable);

            if(fgClockEnable)
            {
                prVideoDecSchedulerState->fgClockEnable = fgClockEnable;
                _VideoDecSchStartAVSync();
            }
            else
            {
                _VideoDecSchStopAVSync();
                prVideoDecSchedulerState->fgClockEnable = fgClockEnable;
            }
        }
        break;

    case VIDEO_PARAM_AUDIO_ON: // Init (reset to KAL_FALSE)
        prVideoDecSchedulerState->fgAudioOn = *(kal_bool*)pParam;       
        break;

    case VIDEO_PARAM_START_TIME: // Init (reset to 0)
        {
            kal_uint64 u8StartTime;
            u8StartTime = *(kal_uint64*)pParam;
            prVideoDecSchedulerState->u8StartTime = u8StartTime;
            prVideoDecSchedulerState->u8CurrTime= u8StartTime;
            prVideoDecSchedulerState->u8MaxVideoTime = 0;			
            
            VDS_LABEL_LOGGING("VSP");
#if 1
            VFC_IOCtrl(VFC_OP_SCH_SET_START_TIME, &u8StartTime, NULL, NULL);
#endif
        }
        break;
			
    case VIDEO_PARAM_AV_TIMEBASE:
        {
            kal_uint64 u8TimeBase;
            u8TimeBase = *(kal_uint64*)pParam;        
            Media_A2V_SetPlaybackTimerBase(u8TimeBase/1000, KAL_TRUE);
        }
        break;

    case VIDEO_PARAM_PLAY_SPEED: // No reset value
    
#ifdef __VDS_SPEEDPLAY__    
        prVideoDecSchedulerState->u4PlaySpeed = *(kal_uint32*)pParam;
        Media_A2V_SetSpeedScale(prVideoDecSchedulerState->u4PlaySpeed);
#else

#ifdef __VDS_DBG__		
    	AOF(*(kal_uint32*)pParam == CLOCK_1X_SPEED);
#endif  //__VDS_DBG__

        Media_A2V_SetSpeedScale(CLOCK_1X_SPEED);
#endif  //__VDS_SPEEDPLAY__

        break;

#ifdef __VDS_RECOVER__
    case VIDEO_PARAM_JUMP_TIMESTAMP:  	
//#ifdef __VE_FLUENCY_CONTROL_ENABLE__    		
//#ifdef __VE_VFC_RECOVER_SUPPORT__
#if 1
	{	
        VFC_OP_DATA_JUMP_EVENT_T  rSetJumpResult;	
        VFC_GET_KEYFRAME_TIME_T rKeyframeTime = *(VFC_GET_KEYFRAME_TIME_T*)pParam;
#ifdef __VDS_DURATION_MODE__
        ((VFC_GET_KEYFRAME_TIME_T*)pParam)->fgEnableDurationMode = KAL_TRUE;
#else
        ((VFC_GET_KEYFRAME_TIME_T*)pParam)->fgEnableDurationMode = KAL_FALSE;
#endif

        kal_mem_set(&rSetJumpResult, 0, sizeof(VFC_OP_DATA_JUMP_EVENT_T));
          		
        if(rKeyframeTime.fgSuccess)      
        {
            prVideoDecSchedulerState->u8JumpTime = rKeyframeTime.u8KeyframeTime;
        }
        drv_trace2(TRACE_GROUP_10, VDS_JUMP_RESULT, 2, rKeyframeTime.fgSuccess);
          		
        VFC_IOCtrl(VFC_OP_SCH_SET_KEY_FRAME_TIME, pParam, &rSetJumpResult, NULL);
#if 0		
/* under construction !*/
/* under construction !*/
#ifdef __VDS_DURATION_MODE__
/* under construction !*/
#ifdef __VDS_SECONDPORT__
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
/* under construction !*/
/* under construction !*/
#endif //__VDS_DURATION_MODE__	        
/* under construction !*/
/* under construction !*/
#endif		
    }
#endif

    break;

#endif // __VDS_RECOVER__

#ifdef __VDS_STOPTIME__				
    case VIDEO_PARAM_STOP_TIME: // Init (reset to 64 bit max.)
        {
            prVideoDecSchedulerState->u8StopTime= *(kal_uint64*)pParam;
        }
        break;
#endif  //__VDS_STOPTIME__			

#ifdef __VDS_SECONDPORT__
    case VIDEO_PARAM_RESET_QUEUE:  // RUN (reset to KAL_FALSE)
        _VideoDecSchResetPort(*(VIDEO_PORT_TYPE_T*)pParam);
	break;	
#endif  //__VDS_SECONDPORT__	

    default:
//        ASSERT(0);
        break;
    }

    return eError;
}

/*****************************************************************************
 * FUNCTION
 *    VideoDecSchedulerSendCommand
 * DESCRIPTION
 *  SendCommand function of DecScheduler component
 *  Context: MED
 *  Change decode scheduler component state.
 * PARAMETERS
 *  param1 : [IN]  VIDEO_COMMAND_TYPE_T eCmd
 *                 The command type. 
 *  param2 : [IN]  kal_uint32 u4Param
 *                 The state want to change. 
 * RETURNS
 *   VIDEO_ERROR_TYPE_T.
 ****************************************************************************/
static VIDEO_ERROR_TYPE_T VideoDecSchedulerSendCommand(VIDEO_COMMAND_TYPE_T eCmd, kal_uint32 u4Param)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    VIDEO_COMM_STATE_T *prCommState = &prVideoDecSchedulerState->rCommState;

    video_dbg_trace(VIDEO_DBG_OWNER_DECSCHEDULER, VIDEO_DBG_DECSCHEDULER_STATE_SET, u4Param);
    drv_trace1(TRACE_GROUP_10, VDS_CHANGE_STATE, u4Param);

    switch(u4Param)
    {
        case VIDEO_STATE_IDLE:
        {
            prVideoDecSchedulerState->u8CurrTime = prVideoDecSchedulerState->u8StartTime;
            VideoCommClrAllQ(prCommState);
            prVideoDecSchedulerState->fgComplete = KAL_FALSE;
        }
    	break;

        case VIDEO_STATE_RUN:
        {
#ifdef __VDS_RECOVER__			
            prVideoDecSchedulerState->u8LatestTimeStamp[0] = prVideoDecSchedulerState->u8CurrTime;
#ifdef __VDS_SECONDPORT__
            prVideoDecSchedulerState->u8LatestTimeStamp[1] = prVideoDecSchedulerState->u8CurrTime;
#endif
#endif			
            prVideoDecSchedulerState->fgStartEvent = KAL_FALSE;
            prVideoDecSchedulerState->fgDurationSet = KAL_FALSE;	

            if(prVideoDecSchedulerState->fgComplete)
            {
                _VideoDecSchEvent(VIDEO_EVENT_COMPLETE, VIDEO_DBG_DECSCHEDULER_COMPLETE, (kal_uint32)&prVideoDecSchedulerState->u8CurrTime, __LINE__);
            }
            _VideoDecSchCheckStartEvent(__LINE__);

        }
    	break;

        case VIDEO_STATE_STOP:
#ifdef __VDS_DBG__
            AOF(prVideoDecSchedulerState->fgClockEnable == KAL_FALSE);
#endif
        break;
    }
    eError = VideoCommChangeState(prCommState, (VIDEO_STATE_TYPE_T)u4Param);

    return eError;
}

/*****************************************************************************
 * FUNCTION
 *    VideoDecSchedulerUseBuffer
 * DESCRIPTION
 *  UseBuffer function of DecScheduler component
 *  Context: None
 *  No use in decode scheduler component.
 * PARAMETERS
 *  param1 : [IN]  kal_uint8* pu1Buff
 *                 The buffer pointer.
 *  param2 : [IN]  kal_uint32 u4Size
 *                 The buffer size. 
 * RETURNS
 *   VIDEO_ERROR_TYPE_T.
 ****************************************************************************/
static VIDEO_ERROR_TYPE_T VideoDecSchedulerUseBuffer(kal_uint8* pu1Buff, kal_uint32 u4Size)
{
    // no use in this component
    ASSERT(0);

    return VIDEO_ERROR_NONE;
}

/*****************************************************************************
 * FUNCTION
 *    VideoDecSchedulerEmptyThisBuffer
 * DESCRIPTION
 *  EmptyThisBuffer function of DecScheduler component
 *  Context: V2DEC
 *  0) Return frame in output Q to Decoder (clock disable case)
 *  1) Check output Q has entry (make sure this buffer header can be inserted to output Q)
 *  2) Check End Event
 *  3) Send Out-of-date frame to Render (clock disable case)
 *  4) Push buffer header to input Q 
 *  5) Check Start Event 
 * PARAMETERS
 *  param1 : [IN]  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader
 *                 The empty buffer header.
 * RETURNS
 *   VIDEO_ERROR_TYPE_T.
 ****************************************************************************/
static VIDEO_ERROR_TYPE_T VideoDecSchedulerEmptyThisBuffer(VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    const VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    VIDEO_COMM_STATE_T *prCommState = &prVideoDecSchedulerState->rCommState;
    kal_uint64 u8TimeStamp;
    kal_bool fgPushBuff;
    kal_uint32 u4Port = prBuffHeader->u4InputPort;
    kal_uint32 u4OutputQCount = VideoCommGetOutputBuffQUsedNum(prCommState, u4Port);	
    kal_uint32 u4InputQCount = VideoCommGetInputBuffQUsedNum(prCommState, u4Port);

    VDS_START_LOGGING("VSE");

#ifdef __VDS_DBG__
    if (prCommState->eState == VIDEO_STATE_CLOSE)
    {
        ASSERT(0);
		VDS_STOP_LOGGING("VSE");
        return VIDEO_ERROR_BUFF_FULL;
    }
#endif  //__VDS_DBG__

//    if(!prVideoDecSchedulerState->fgClockEnable)
    {
		_VideoDecSchFlushOutputQ();
    }

    if(u4InputQCount + u4OutputQCount > (VIDEO_DECSCHEDULER_OUTPUT_QUEUE_SIZE - 2))
    {
        VDS_STOP_LOGGING("VSE");
#ifdef __VDS_DBG__		
        drv_trace2(TRACE_GROUP_10, VDS_MSG, (kal_uint32)__LINE__, u4OutputQCount);		
#endif		
        return VIDEO_ERROR_BUFF_FULL;
    }
    if(KAL_FALSE == prVideoDecSchedulerState->fgClockEnable && u4OutputQCount > 0)
    {
        VDS_STOP_LOGGING("VSE");
#ifdef __VDS_DBG__		
        drv_trace2(TRACE_GROUP_10, VDS_MSG, (kal_uint32)__LINE__, u4OutputQCount);		
#endif
        return VIDEO_ERROR_BUFF_FULL;
    }

    u8TimeStamp = prBuffHeader->u8TimeStamp;
		
#ifdef __VDS_SECONDPORT__	
    if(eVDSPortType[u4Port] == VIDEO_PORT_VIDEO_DATA)	
#endif
    {
        if(u8TimeStamp >= prVideoDecSchedulerState->u8MaxVideoTime)    
        {
            prVideoDecSchedulerState->u8MaxVideoTime = u8TimeStamp;
        }
    }
		
    video_dbg_trace(VIDEO_DBG_OWNER_DECSCHEDULER, VIDEO_DBG_DECSCHEDULER_EMPTY, (kal_uint32)u8TimeStamp);

    drv_trace4(TRACE_GROUP_10, VDS_BUFFER_IN, (kal_uint32)prBuffHeader->pu1Buffer, (kal_uint32)u8TimeStamp, u4Port, (kal_uint32)prVideoDecSchedulerState->u8CurrTime);

#if 1 //#ifdef __VE_FLUENCY_CONTROL_ENABLE__
    {
        VFC_OP_DATA_CHECK_FLUENCY_T rCheckFluency;
        rCheckFluency.prBuffHeader = prBuffHeader;
        rCheckFluency.u8CurrTime   = prVideoDecSchedulerState->u8CurrTime;        
        VFC_IOCtrl(VFC_OP_SCH_CHECK_RCV_FRAME, (void*)&rCheckFluency, NULL, NULL);                
    }
#endif

#ifdef __VDS_SECONDPORT__    
	//buffer header port setting
    {
        VIDEO_PORT_TYPE_T ePortType = VideoCommGetInputPortType(prCommState, u4Port);
        kal_uint32 u4OutputPortIndex = VideoCommGetOutputPortIndex(prCommState,ePortType);
        prBuffHeader->u4InputPort	= VideoCommGetOutputComp(prCommState, u4OutputPortIndex)->u4PortIndex;
        prBuffHeader->u4OutputPort	= u4OutputPortIndex;
    }
#endif

    fgPushBuff = VideoCommPushInputBuffExt(prCommState, prBuffHeader, u4Port);
#ifdef __VDS_DBG__
    if(KAL_FALSE == fgPushBuff)
    {
        ASSERT(0);
    }
#endif

#ifdef __VDS_DURATION_MODE__
//    drv_trace2(TRACE_GROUP_10, VDS_MSG, __LINE__, prVideoDecSchedulerState->u4EmptyTimeIndex);

    prVideoDecSchedulerState->u4EmptyTime[prVideoDecSchedulerState->u4EmptyTimeIndex] = video_get_current_time();
    prVideoDecSchedulerState->u4EmptyTimeIndex = (prVideoDecSchedulerState->u4EmptyTimeIndex + 1)%VDSSLICEWINDOW; 
/*
    drv_trace4(TRACE_GROUP_10, VDS_MSG_4, prVideoDecSchedulerState->u4EmptyTime[0], prVideoDecSchedulerState->u4EmptyTime[1],
               prVideoDecSchedulerState->u4EmptyTime[2], prVideoDecSchedulerState->u4EmptyTime[3]);
*/
#endif //__VDS_DURATION_MODE__
    // Send Out-of-date frame			
    if(KAL_FALSE == prVideoDecSchedulerState->fgClockEnable)
    {
    	_VideoDecSchProcessBufferToRender(u4Port);
    }

    // Check Start Event
    _VideoDecSchCheckStartEvent(NULL);

    VDS_STOP_LOGGING("VSE");

    return eError;
}

/*****************************************************************************
 * FUNCTION
 *	  VideoDecSchedulerFillThisBuffer
 * DESCRIPTION
 *	FillThisBuffer function of DecScheduler component.
 *    Context: VISU HISR or V2DEC
 *	1) Try to call Decoder FillThisBuffer
 *    2) If return fail, push to output Q
 * PARAMETERS
 *	param1 : [IN]  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader
 *				 The fill buffer header.
 * RETURNS
 *	VIDEO_ERROR_TYPE_T.
 ****************************************************************************/
static VIDEO_ERROR_TYPE_T VideoDecSchedulerFillThisBuffer(VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    VIDEO_COMM_STATE_T *prCommState = &prVideoDecSchedulerState->rCommState;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;	

    VDS_START_LOGGING("VSD");

    video_dbg_trace(VIDEO_DBG_OWNER_DECSCHEDULER, VIDEO_DBG_DECSCHEDULER_RENDERRETURN, prBuffHeader->u8TimeStamp);
#ifdef __VDS_DBG__	
    drv_trace4(TRACE_GROUP_10, VDS_RENDERER_RETURN, (prBuffHeader->eFlags & VIDEO_BUFFERFLAG_RENDER_DISPLAY), (kal_uint32)prBuffHeader->u8TimeStamp, prBuffHeader->u4InputPort, (kal_uint32)prVideoDecSchedulerState->u8CurrTime);	
#endif

    // For CCU to check frame display duration    
    VFC_IOCtrl(VFC_OP_SCH_CHECK_DISPLAY_DURATION, (void*)prBuffHeader, NULL, NULL);

#ifdef __VDS_SECONDPORT__    
	//buffer header port setting
    {
        VIDEO_PORT_TYPE_T ePortType = VideoCommGetOutputPortType(prCommState, prBuffHeader->u4InputPort);
        kal_uint32 u4OutputPortIndex = VideoCommGetInputPortIndex(prCommState,ePortType);

#ifdef __VDS_DBG__
        if(KAL_TRUE == prVideoDecSchedulerState->fgResetSubtitle)
        {
            if(VIDEO_PORT_SUBTITLE == ePortType)
            {
                ASSERT(0);
            }
        }
#endif		
		
        prBuffHeader->u4InputPort	= VideoCommGetInputComp(prCommState, u4OutputPortIndex)->u4PortIndex;
        prBuffHeader->u4OutputPort	= u4OutputPortIndex;
    }
#endif	

    eError = VideoCommGetInputProcessBufferFunc(prCommState, prBuffHeader->u4OutputPort)(prBuffHeader);
    if(eError != VIDEO_ERROR_NONE)
    {
        kal_bool fgPushBuff;    
        fgPushBuff = VideoCommPushOutputBuffExt(prCommState, prBuffHeader, prBuffHeader->u4OutputPort);
#ifdef __VDS_DBG__
        if(KAL_FALSE == fgPushBuff)
        {
            ASSERT(0);
        }
#endif		
    }

    VDS_STOP_LOGGING("VSD");

    return VIDEO_ERROR_NONE;
}

/*****************************************************************************
 * FUNCTION
 *	  VideoDecSchedulerSetCallbacks
 * DESCRIPTION
 *	This function is used to set decode scheduler component callback funtion.
 *    Context: MED 
 *	1) Call VideoCommSetCallbacks
 * PARAMETERS
 *	param1 : [IN]  VIDEO_CALLBACK_TYPE_T *prCallback
 *				 callback function pointer.
 * RETURNS
 *	VIDEO_ERROR_TYPE_T.
 ****************************************************************************/
static VIDEO_ERROR_TYPE_T VideoDecSchedulerSetCallbacks(VIDEO_CALLBACK_TYPE_T *prCallback)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    eError = VideoCommSetCallbacks(&prVideoDecSchedulerState->rCommState, prCallback);

    return eError;
}

/*****************************************************************************
 * FUNCTION
 *	  VideoDecSchedulerDeInit
 * DESCRIPTION
 *	This function is used to deinit decode scheduler component.
 *    Context: MED 
 *	1) Call VideoCommDeInit
 * PARAMETERS
 *    None.
 * RETURNS
 *	VIDEO_ERROR_TYPE_T.
 ****************************************************************************/
static VIDEO_ERROR_TYPE_T VideoDecSchedulerDeInit(void)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    VideoFreeTimer(TIMER_USER_SCHEDULER, prVideoDecSchedulerState->rTimerID);
    VideoFreeMutex(MUTEX_USER_SCHEDULER, prVideoDecSchedulerState->eMutex);
    eError = VideoCommDeInit(&prVideoDecSchedulerState->rCommState);

    return eError;
}

const VIDEO_COMPONENT_TYPE_T rVideoDecSchedulerComp =
{
    VideoDecSchedulerInit,
    VideoDecSchedulerSendCommand,
    VideoDecSchedulerGetParameter,
    VideoDecSchedulerSetParameter,
    NULL,//VideoDecSchedulerUseBuffer,
    VideoDecSchedulerEmptyThisBuffer,
    VideoDecSchedulerFillThisBuffer,
    VideoDecSchedulerSetCallbacks,
    VideoDecSchedulerDeInit
};

/*****************************************************************************
 *
 * External Function
 *
 ****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *	  GetVideoDecSchedulerHandle
 * DESCRIPTION
 *	This function is used to get decode scheduler component handle.
 *    Context: MED 
 *	1) Save external memory handler
 *	2) Call component init function
 * PARAMETERS
 *	param1 : [IN]  VIDEO_SCHEDULER_TYPE_T eType
 *				 Decode scheduler component type. (currently only VIDEO_SCHEDULER_COMM)
 *	param2 : [IN]  VIDEO_EXTMEM_HANDLER_T* prExtMemHdr
 *				 external memory handler. (use for VideoCommInit)
 * RETURNS
 *	return component API.
 ****************************************************************************/
VIDEO_COMPONENT_TYPE_T* GetVideoDecSchedulerHandle(VIDEO_SCHEDULER_TYPE_T eType, VIDEO_EXTMEM_HANDLER_T* prExtMemHdr)
{
    VIDEO_COMPONENT_TYPE_T *prVideoComp = NULL;
    prVideoDecSchedulerState = (VIDEO_DECSCHEDULER_STATE_T *)VideoGetExtBuffer(prExtMemHdr, sizeof(VIDEO_DECSCHEDULER_STATE_T));
    kal_mem_set(prVideoDecSchedulerState, 0, sizeof(VIDEO_DECSCHEDULER_STATE_T));

#ifdef __VE_SLIM_PROJECT__
    prVideoComp = (VIDEO_COMPONENT_TYPE_T *)&rVideoDecSchedulerComp;
#else
    switch(eType)
    {
    case VIDEO_SCHEDULER_COMM:
        prVideoComp = (VIDEO_COMPONENT_TYPE_T *)&rVideoDecSchedulerComp;
        break;
    default:
        ASSERT(0);
        break;
    }
    AOF(prVideoComp);
#endif	

    prVideoDecSchedulerState->pExtMemHdr = prExtMemHdr;

    prVideoComp->pfnInit(); //VideoDecSchedulerInit ONLY return VIDEO_ERROR_NONE, or ASSERT

    return prVideoComp;
}

/*****************************************************************************
 * FUNCTION
 *	  ReleaseVideoDecSchedulerHandle
 * DESCRIPTION
 *	This function is used to release decode scheduler component handle.
 *    Context: MED
 *	1) Check handle
 *	2) Call component deinit function
 * PARAMETERS
 *	param1 : [IN]  VIDEO_COMPONENT_TYPE_T *prHandle
 *				 Component handle.
 * RETURNS
 *	VIDEO_ERROR_TYPE_T.
 ****************************************************************************/
VIDEO_ERROR_TYPE_T ReleaseVideoDecSchedulerHandle(VIDEO_COMPONENT_TYPE_T *prHandle)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

#ifdef __VDS_DBG__
    AOF(prHandle);
#endif
 
    eError = prHandle->pfnDeInit();

    return eError;
}

#ifdef __VE_DCM_WITH_COMPRESSION__
#pragma arm section code, rodata
#endif

#endif /* __VE_VIDEO_ARCHI_V2__ */
