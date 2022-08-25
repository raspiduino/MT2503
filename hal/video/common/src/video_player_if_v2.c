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
 *   vv2_main_v2.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Visual codec main procedure
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "drv_comm.h"

#ifdef __VIDEO_ARCHI_V2__

/* system */
#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "stack_ltlcom.h"
#include "syscomp_config.h"
#include "task_config.h"

#include "gpt_sw.h"
#include "video_comm_v2.h"
#include "video_buffer_management_v2.h"
#include "video_comm_component_v2.h"
#include "video_filereader_component_if_v2.h"
#include "video_decoder_component_v2.h"
#include "video_scheduler_component_if_v2.h"
#include "video_clock_component_if_v2.h"
#include "video_render_component_v2.h"
#include "va2_comp_video_renderer.h" // [6236_video_renderer]
//#include "vv2_v2.h"
#include "video_player_if_v2.h"

VIDEO_PLAY_STRUCT_T rVideoPlay;

static VIDEO_PLAY_HDLR_STRUCT_T _rVideoPlayHdlr[] =
{
    {VIDEO_PLAY_DECODER_WAIT_BUFFER, VIDEO_PLAY_COMPONENT_DECODER, VIDEO_EVENT_WAIT_BUFFER},
    {VIDEO_PLAY_DECODER_COMPLETE, VIDEO_PLAY_COMPONENT_DECODER, VIDEO_EVENT_COMPLETE},
    {VIDEO_PLAY_DECODER_ERROR, VIDEO_PLAY_COMPONENT_DECODER, VIDEO_EVENT_ERROR},
    {VIDEO_PLAY_CLOCK_START, VIDEO_PLAY_COMPONENT_CLOCK, VIDEO_EVENT_START},
    {VIDEO_PLAY_SCHEDULER_RECOVER, VIDEO_PLAY_COMPONENT_SCHEDULER, VIDEO_EVENT_RECOVER},
    {VIDEO_PLAY_SCHEDULER_COMPLETE, VIDEO_PLAY_COMPONENT_SCHEDULER, VIDEO_EVENT_COMPLETE},
    {VIDEO_PLAY_FILEREADER_ERROR, VIDEO_PLAY_COMPONENT_FILEREADER, VIDEO_EVENT_ERROR}
};

static void _VideoControlStructInit(VIDEO_PLAY_STRUCT_T *prVideoPlay)
{
    // Comment this part, this will result create multievent
    //prVideoPlay->eEvent = NULL;
    prVideoPlay->prVideoFileReaderHandle = NULL;
    prVideoPlay->prVideoDecoderHandle = NULL;
    prVideoPlay->prVideoSchedulerHandle = NULL;
    prVideoPlay->prVideoClockHandle = NULL;
    prVideoPlay->prVideoRenderHandle = NULL;

    prVideoPlay->pfnVideoDecCB = NULL;
    prVideoPlay->eState = VIDEO_PLAY_STATE_CLOSE;
    prVideoPlay->u4HdlrType = 0;
    prVideoPlay->fgDecoderComplete = KAL_FALSE;
    prVideoPlay->fgSchedulerComplete = KAL_FALSE;

    prVideoPlay->fgRecover = KAL_FALSE;
    prVideoPlay->u4RecoverCount = 0;
    prVideoPlay->u8RecoverTolerance = 0;

    // Mp4 video parser
    prVideoPlay->prMp4Parser = NULL;
    // File system abstration layer
    prVideoPlay->prFSAL = NULL;
    prVideoPlay->eParserStatus = MP4_PARSER_OK;

    // For the audio only control information
    // Video Control information
    prVideoPlay->fgHasVisualTrack = KAL_FALSE;
    prVideoPlay->u4PlaySpeed = 100;

}

static void _VideoDecSeekingV2Hdlr(VIDEO_PLAY_COMPONENT_TYPE_T eComponent, VIDEO_EVENT_TYPE_T eEvent)
{
    kal_uint32 u4Index;
    kal_uint32 u4Total = sizeof(_rVideoPlayHdlr) / sizeof(VIDEO_PLAY_HDLR_STRUCT_T);

    for (u4Index = 0; u4Index<u4Total; u4Index++)
    {
        if ((eComponent == _rVideoPlayHdlr[u4Index].eComponent) && (eEvent == _rVideoPlayHdlr[u4Index].eEvent))
        {
            rVideoPlay.u4HdlrType |= _rVideoPlayHdlr[u4Index].eHdlr;
            break;
        }
    }

    if (rVideoPlay.fgDecoderComplete == KAL_TRUE)
    {
        // may decode done before this time action
        rVideoPlay.u4HdlrType |= VIDEO_PLAY_DECODER_COMPLETE;
    }

    if ((rVideoPlay.u4HdlrType & VIDEO_PLAY_DECODER_ERROR) || (rVideoPlay.u4HdlrType & VIDEO_PLAY_FILEREADER_ERROR))
    {
        // Callback event fail to MED
        drv_trace1(TRACE_GROUP_8, IL_ERROR_EVENT, __LINE__);
        rVideoPlay.pfnVideoDecCB(VIDEO_DEC_EVENT_FAIL);
    }

    if ( ((rVideoPlay.u4HdlrType & VIDEO_PLAY_DECODER_WAIT_BUFFER) || (rVideoPlay.u4HdlrType & VIDEO_PLAY_DECODER_COMPLETE))
         && ((rVideoPlay.u4HdlrType & VIDEO_PLAY_CLOCK_START) || (rVideoPlay.u4HdlrType & VIDEO_PLAY_SCHEDULER_COMPLETE)))
    {
        if (rVideoPlay.u4HdlrType & VIDEO_PLAY_DECODER_COMPLETE)
        {
            rVideoPlay.fgDecoderComplete = KAL_TRUE;
        }

        // Callback seek done event
        //
        drv_trace1(TRACE_GROUP_8, IL_SEEK_DONE_EVENT, __LINE__);

        rVideoPlay.pfnVideoDecCB(VIDEO_DEC_EVENT_SEEK_DONE);
    }

    if (((rVideoPlay.u4HdlrType & VIDEO_PLAY_SCHEDULER_COMPLETE) != 0))
    {
        // Callback video play complete event
        //
        drv_trace1(TRACE_GROUP_8, IL_PLAY_COMPLETE_EVENT, __LINE__);

        rVideoPlay.pfnVideoDecCB(VIDEO_DEC_EVENT_COMPLETE);
        rVideoPlay.fgSchedulerComplete = KAL_TRUE;
    }

}

static void _VideoDecPlayingV2Hdlr(VIDEO_PLAY_COMPONENT_TYPE_T eComponent, VIDEO_EVENT_TYPE_T eEvent)
{
    kal_uint32 u4Index;
    kal_uint32 u4Total = sizeof(_rVideoPlayHdlr) / sizeof(VIDEO_PLAY_HDLR_STRUCT_T);

    for (u4Index = 0; u4Index<u4Total; u4Index++)
    {
        if ((eComponent == _rVideoPlayHdlr[u4Index].eComponent) && (eEvent == _rVideoPlayHdlr[u4Index].eEvent))
        {
            rVideoPlay.u4HdlrType |= _rVideoPlayHdlr[u4Index].eHdlr;
            break;
        }
    }

    if ((rVideoPlay.u4HdlrType & VIDEO_PLAY_DECODER_ERROR) || (rVideoPlay.u4HdlrType & VIDEO_PLAY_FILEREADER_ERROR))
    {
        // Callback event fail to MED
        drv_trace1(TRACE_GROUP_8, IL_ERROR_EVENT, __LINE__);
        kal_set_eg_events(rVideoPlay.eEvent, VIDEO_PLAY_EVENT_FILEREADER_ERROR, KAL_OR);
        kal_set_eg_events(rVideoPlay.eEvent, VIDEO_PLAY_EVENT_DECODER_ERROR, KAL_OR);
        rVideoPlay.pfnVideoDecCB(VIDEO_DEC_EVENT_FAIL);
    }

    // waiting for decoder buffer full before goo into play done state (queue enough frames)
    if (rVideoPlay.u4HdlrType & VIDEO_PLAY_DECODER_COMPLETE)
    {
        rVideoPlay.fgDecoderComplete = KAL_TRUE;
        kal_set_eg_events(rVideoPlay.eEvent, VIDEO_PLAY_EVENT_DECODER_NOTIFY_COMPLETE, KAL_OR);
    }

    if (rVideoPlay.u4HdlrType & VIDEO_PLAY_DECODER_WAIT_BUFFER)
    {
        kal_set_eg_events(rVideoPlay.eEvent, VIDEO_PLAY_EVENT_DECODER_NOTIFY_WAIT_BUFFER, KAL_OR);
    }

    if (rVideoPlay.u4HdlrType & VIDEO_PLAY_CLOCK_START)
    {
        kal_set_eg_events(rVideoPlay.eEvent, VIDEO_PLAY_EVENT_CLOCK_START, KAL_OR);
    }

    if (rVideoPlay.u4HdlrType & VIDEO_PLAY_SCHEDULER_RECOVER)
    {
        // ignore it in recover case
        rVideoPlay.u4HdlrType &= (~VIDEO_PLAY_SCHEDULER_RECOVER);
    }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    if (rVideoPlay.u4HdlrType & VIDEO_PLAY_SCHEDULER_COMPLETE)
    {
        //EXT_ASSERT(0, eComponent, eEvent, rVideoPlay.u4HdlrType);
    }
}


static void _VideoDecPlayDoneV2Hdlr(VIDEO_PLAY_COMPONENT_TYPE_T eComponent, VIDEO_EVENT_TYPE_T eEvent)
{
    kal_uint32 u4Index;
    kal_uint32 u4Total = sizeof(_rVideoPlayHdlr)/sizeof(VIDEO_PLAY_HDLR_STRUCT_T);

    for (u4Index = 0; u4Index<u4Total; u4Index++)
    {
        if ((eComponent == _rVideoPlayHdlr[u4Index].eComponent) && (eEvent == _rVideoPlayHdlr[u4Index].eEvent))
        {
            rVideoPlay.u4HdlrType|= _rVideoPlayHdlr[u4Index].eHdlr;
            break;
        }
    }

    // If decoder callback event error, this means that decoder can't handle error by itself
    // In such case, IL Client will callback VIDEO_DEC_EVENT_FAIL to MED
    //
    if ((rVideoPlay.u4HdlrType & VIDEO_PLAY_DECODER_ERROR) || (rVideoPlay.u4HdlrType & VIDEO_PLAY_FILEREADER_ERROR))
    {
        // Callback event fail to MED
        drv_trace1(TRACE_GROUP_8, IL_ERROR_EVENT, __LINE__);
        rVideoPlay.pfnVideoDecCB(VIDEO_DEC_EVENT_FAIL);
    }

    if (rVideoPlay.u4HdlrType & VIDEO_PLAY_DECODER_COMPLETE)
    {
        rVideoPlay.fgDecoderComplete = KAL_TRUE;
    }

    if (((rVideoPlay.u4HdlrType & VIDEO_PLAY_SCHEDULER_COMPLETE)!=0))
    {
        // Callback video play complete event
        //
        drv_trace1(TRACE_GROUP_8, IL_PLAY_COMPLETE_EVENT, __LINE__);

        rVideoPlay.pfnVideoDecCB(VIDEO_DEC_EVENT_COMPLETE);
        rVideoPlay.fgSchedulerComplete = KAL_TRUE;
        //rVideoPlay.eState = VIDEO_PLAY_STATE_COMPLETE;
    }

    if (((rVideoPlay.u4HdlrType & VIDEO_PLAY_SCHEDULER_RECOVER) != 0))
    {
        //recover
        drv_trace1(TRACE_GROUP_8, IL_RECOVER_EVENT, __LINE__);
        rVideoPlay.pfnVideoDecCB(VIDEO_DEC_RECOVER);
    }
}

static void _VideoDecSeekDoneV2Hdlr(VIDEO_PLAY_COMPONENT_TYPE_T eComponent, VIDEO_EVENT_TYPE_T eEvent)
{
    kal_uint32 u4Index;
    kal_uint32 u4Total = sizeof(_rVideoPlayHdlr)/sizeof(VIDEO_PLAY_HDLR_STRUCT_T);

    for (u4Index = 0; u4Index<u4Total; u4Index++)
    {
        if ((eComponent == _rVideoPlayHdlr[u4Index].eComponent) && (eEvent == _rVideoPlayHdlr[u4Index].eEvent))
        {
            rVideoPlay.u4HdlrType|= _rVideoPlayHdlr[u4Index].eHdlr;
            break;
        }
    }

    if ((rVideoPlay.u4HdlrType & VIDEO_PLAY_DECODER_ERROR) || (rVideoPlay.u4HdlrType & VIDEO_PLAY_FILEREADER_ERROR))
    {
        // Callback event fail to MED
        drv_trace1(TRACE_GROUP_8, IL_ERROR_EVENT, __LINE__);
        rVideoPlay.pfnVideoDecCB(VIDEO_DEC_EVENT_FAIL);
    }

    // Seeking state may be complete one either one match, so seek done should handle this
    //
    if (rVideoPlay.u4HdlrType & VIDEO_PLAY_DECODER_COMPLETE)
    {
        rVideoPlay.fgDecoderComplete = KAL_TRUE;
    }

    if (rVideoPlay.u4HdlrType & VIDEO_PLAY_SCHEDULER_COMPLETE)
    {
        // Callback video play complete event
        //
        drv_trace1(TRACE_GROUP_8, IL_PLAY_COMPLETE_EVENT, __LINE__);

        rVideoPlay.pfnVideoDecCB(VIDEO_DEC_EVENT_COMPLETE);
        rVideoPlay.fgSchedulerComplete = KAL_TRUE;
    }
}



static VIDEO_ERROR_TYPE_T _VideoFileReaderEventHandler(VIDEO_EVENT_TYPE_T eEvent, kal_uint32 u4Data1, kal_uint32 u4Data2, void* pData)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    drv_trace2(TRACE_GROUP_8, IL_FILEREADER_CALLBACK_HANDLER, u4Data1, eEvent);

    if (u4Data1 == VIDEO_COMMAND_STATESET)
    {
        if (eEvent == VIDEO_EVENT_COMPLETE)
        {
            kal_set_eg_events(rVideoPlay.eEvent, VIDEO_PLAY_EVENT_FILEREADER_COMPLETE, KAL_OR);
        }
        else
        {
            EXT_ASSERT(0, u4Data1, eEvent, 0);
        }
    }
    else if (u4Data1 == VIDEO_COMMAND_NOTIFY)
    {
        if (rVideoPlay.eState == VIDEO_PLAY_STATE_SEEKING)
        {
            _VideoDecSeekingV2Hdlr(VIDEO_PLAY_COMPONENT_FILEREADER, eEvent);
        }
        else if (rVideoPlay.eState == VIDEO_PLAY_STATE_SEEK_DONE)
        {
            _VideoDecSeekDoneV2Hdlr(VIDEO_PLAY_COMPONENT_FILEREADER, eEvent);
        }
        else if (rVideoPlay.eState == VIDEO_PLAY_STATE_PLAYING)
        {
            _VideoDecPlayingV2Hdlr(VIDEO_PLAY_COMPONENT_FILEREADER, eEvent);
        }
        else if (rVideoPlay.eState == VIDEO_PLAY_STATE_PLAY_DONE)
        {
            _VideoDecPlayDoneV2Hdlr(VIDEO_PLAY_COMPONENT_FILEREADER, eEvent);
        }
        else
        {
            //EXT_ASSERT(0, u4Data1, eEvent, 0);
            // The file reader will read data at video_dec_initialize
        }
    }
    else
    {
        EXT_ASSERT(0, u4Data1, eEvent, 0);
    }

    return eError;
}

static VIDEO_ERROR_TYPE_T _VideoDecoderEventHandler(VIDEO_EVENT_TYPE_T eEvent, kal_uint32 u4Data1, kal_uint32 u4Data2, void* pData)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    drv_trace2(TRACE_GROUP_8, IL_DECODER_CALLBACK_HANDLER, u4Data1, eEvent);

    if (u4Data1 == VIDEO_COMMAND_STATESET)
    {
        if (eEvent == VIDEO_EVENT_COMPLETE)
        {
            kal_set_eg_events(rVideoPlay.eEvent, VIDEO_PLAY_EVENT_DECODER_COMPLETE, KAL_OR);
        }
        else
        {
            EXT_ASSERT(0, u4Data1, eEvent, 0);
        }
    }
    else if (u4Data1 == VIDEO_COMMAND_NOTIFY)
    {
        if (rVideoPlay.eState == VIDEO_PLAY_STATE_SEEKING)
        {
            _VideoDecSeekingV2Hdlr(VIDEO_PLAY_COMPONENT_DECODER, eEvent);
        }
        else if (rVideoPlay.eState == VIDEO_PLAY_STATE_SEEK_DONE)
        {
            _VideoDecSeekDoneV2Hdlr(VIDEO_PLAY_COMPONENT_DECODER, eEvent);
        }
        else if (rVideoPlay.eState == VIDEO_PLAY_STATE_PLAYING)
        {
            _VideoDecPlayingV2Hdlr(VIDEO_PLAY_COMPONENT_DECODER, eEvent);
        }
        else if (rVideoPlay.eState == VIDEO_PLAY_STATE_PLAY_DONE)
        {
            _VideoDecPlayDoneV2Hdlr(VIDEO_PLAY_COMPONENT_DECODER, eEvent);
        }
        else
        {
            EXT_ASSERT(0, u4Data1, eEvent, 0);
        }
    }
    else
    {
        EXT_ASSERT(0, u4Data1, eEvent, 0);
    }

    return eError;
}

static VIDEO_ERROR_TYPE_T _VideoClockEventHandler(VIDEO_EVENT_TYPE_T eEvent, kal_uint32 u4Data1, kal_uint32 u4Data2, void* pData)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    drv_trace2(TRACE_GROUP_8, IL_CLOCK_CALLBACK_HANDLER, u4Data1, eEvent);

    if (u4Data1 == VIDEO_COMMAND_STATESET)
    {
        if (eEvent == VIDEO_EVENT_COMPLETE)
        {
            kal_set_eg_events(rVideoPlay.eEvent, VIDEO_PLAY_EVENT_CLOCK_COMPLETE, KAL_OR);
        }
        else
        {
            EXT_ASSERT(0, u4Data1, eEvent, 0);
        }
    }
    else if (u4Data1 == VIDEO_COMMAND_NOTIFY)
    {
        if (rVideoPlay.eState == VIDEO_PLAY_STATE_SEEKING)
        {
            _VideoDecSeekingV2Hdlr(VIDEO_PLAY_COMPONENT_CLOCK, eEvent);
        }
        else if (rVideoPlay.eState == VIDEO_PLAY_STATE_PLAYING)
        {
            _VideoDecPlayingV2Hdlr(VIDEO_PLAY_COMPONENT_CLOCK, eEvent);
        }
        else if (rVideoPlay.eState == VIDEO_PLAY_STATE_PLAY_DONE)
        {
            _VideoDecPlayDoneV2Hdlr(VIDEO_PLAY_COMPONENT_CLOCK, eEvent);
        }
        else
        {
            EXT_ASSERT(0, u4Data1, eEvent, 0);
        }
    }
    else
    {
        EXT_ASSERT(0, u4Data1, eEvent, 0);
    }

    return eError;

}

static VIDEO_ERROR_TYPE_T _VideoSchedulerEventHandler(VIDEO_EVENT_TYPE_T eEvent, kal_uint32 u4Data1, kal_uint32 u4Data2, void* pData)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    drv_trace2(TRACE_GROUP_8, IL_SCHEDULER_CALLBACK_HANDLER, u4Data1, eEvent);

    if (u4Data1 == VIDEO_COMMAND_STATESET)
    {
        if (eEvent == VIDEO_EVENT_COMPLETE)
        {
            kal_set_eg_events(rVideoPlay.eEvent, VIDEO_PLAY_EVENT_SCHEDULER_COMPLETE, KAL_OR);
        }
        else
        {
            EXT_ASSERT(0, u4Data1, eEvent, 0);
        }
    }
    else if (u4Data1 == VIDEO_COMMAND_NOTIFY)
    {
        if (rVideoPlay.eState == VIDEO_PLAY_STATE_SEEKING)
        {
            _VideoDecSeekingV2Hdlr(VIDEO_PLAY_COMPONENT_SCHEDULER, eEvent);
        }
        else if (rVideoPlay.eState == VIDEO_PLAY_STATE_SEEK_DONE)
        {
            _VideoDecSeekDoneV2Hdlr(VIDEO_PLAY_COMPONENT_SCHEDULER, eEvent);
        }
        else if (rVideoPlay.eState == VIDEO_PLAY_STATE_PLAYING)
        {
            _VideoDecPlayingV2Hdlr(VIDEO_PLAY_COMPONENT_SCHEDULER, eEvent);
        }
        else if (rVideoPlay.eState == VIDEO_PLAY_STATE_PLAY_DONE)
        {
            _VideoDecPlayDoneV2Hdlr(VIDEO_PLAY_COMPONENT_SCHEDULER, eEvent);
        }
        else
        {
            EXT_ASSERT(0, u4Data1, eEvent, 0);
        }
    }
    else
    {
        EXT_ASSERT(0, u4Data1, eEvent, 0);
    }

    return eError;
}

static VIDEO_ERROR_TYPE_T _VideoRenderEventHandler(VIDEO_EVENT_TYPE_T eEvent, kal_uint32 u4Data1, kal_uint32 u4Data2, void* pData)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    drv_trace2(TRACE_GROUP_8, IL_RENDER_CALLBACK_HANDLER, u4Data1, eEvent);

    if (u4Data1 == VIDEO_COMMAND_STATESET)
    {
        if (eEvent == VIDEO_EVENT_COMPLETE)
        {
            kal_set_eg_events(rVideoPlay.eEvent, VIDEO_PLAY_EVENT_RENDER_COMPLETE, KAL_OR);
        }
        else
        {
            EXT_ASSERT(0, u4Data1, eEvent, 0);
        }
    }
    else if (u4Data1 == VIDEO_COMMAND_NOTIFY)
    {
        EXT_ASSERT(0, u4Data1, eEvent, 0);
    }
    else
    {
        EXT_ASSERT(0, u4Data1, eEvent, 0);
    }

    return eError;
}

static VIDEO_CALLBACK_TYPE_T _VideoFileReaderCallback =
{
    _VideoFileReaderEventHandler
};

static VIDEO_CALLBACK_TYPE_T _VideoDecoderCallback =
{
    _VideoDecoderEventHandler
};

static VIDEO_CALLBACK_TYPE_T _VideoSchedulerCallback =
{
    _VideoSchedulerEventHandler
};

static VIDEO_CALLBACK_TYPE_T _VideoClockCallback =
{
    _VideoClockEventHandler
};

static VIDEO_CALLBACK_TYPE_T _VideoRenderCallback =
{
    _VideoRenderEventHandler
};

//dummy functions
void video_seek_action(void)
{
    // only used for V1
    ASSERT(0);
}
MEDIA_STATUS_CODE video_dec_put_frame_to_buffer(void)
{
    ASSERT(0);
    return VIDEO_ERROR;
}

static VIDEO_ERROR_TYPE_T _VideoDecoderQueryFrameSize(void)
{
    VIDEO_ERROR_TYPE_T eError;
    VIDEO_QUERY_FRAME_SIZE_TYPE_T rQueryFrameSizeData;

    // Get query width & height from decoder
    //
    eError = rVideoPlay.prVideoFileReaderHandle->pfnGetParameter(VIDEO_PARAM_FRAME_SIZE_STRUCT, &rQueryFrameSizeData);
    if (eError != VIDEO_ERROR_NONE)
    {
        if (VIDEO_ERROR_QUERY_FRAME_SIZE == eError)
        {
            drv_trace0(TRACE_GROUP_8, IL_ERROR_GET_FRAME_SIZE_STRUCT);
            return eError;
        }
        else
        {
            EXT_ASSERT(0, eError, 0, 0);
        }
    }

    eError = rVideoPlay.prVideoDecoderHandle->pfnGetParameter(VIDEO_PARAM_QUERY_RESOLUTION_AHEAD, &rQueryFrameSizeData);
    if (eError != VIDEO_ERROR_NONE)
    {
        if (eError == VIDEO_ERROR_CODEC_NOT_SUPPORT)
        {
            drv_trace1(TRACE_GROUP_8, IL_ERROR_DECODER_TYPE, __LINE__);
            return eError;
        }
        else
        {
            EXT_ASSERT(0, eError, 0, 0);
        }
    }

    // Check width & height
    //
    if (rQueryFrameSizeData.u4Width == 0 || rQueryFrameSizeData.u4Height == 0)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
    drv_trace2(TRACE_GROUP_8, IL_QUERY_FRAME_SIZE, rQueryFrameSizeData.u4Width, rQueryFrameSizeData.u4Height);

    // Set back to file reader component
    //
    eError = rVideoPlay.prVideoFileReaderHandle->pfnSetParameter(VIDEO_PARAM_FRAME_WIDTH, &rQueryFrameSizeData.u4Width);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
    eError = rVideoPlay.prVideoFileReaderHandle->pfnSetParameter(VIDEO_PARAM_FRAME_HEIGHT, &rQueryFrameSizeData.u4Height);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }

    return eError;
}

MEDIA_STATUS_CODE video_dec_initialize(MP4DEC_INIT_STRUCT * prInitInput)
{
    VIDEO_ERROR_TYPE_T eError;
    VIDEO_DECODER_TYPE_T eCodecType;
    kal_uint32 u4EventGroup;
    VIDEO_RENDER_MODE_T eRenderMode = VIDEO_RENDER_MODE_NONE;
    kal_uint64 u8StartTime = 0;
    kal_uint32 u4FPS;
    //kal_bool fgWithStartCode = KAL_FALSE;

    video_dbg_trace(VIDEO_DBG_OWNER_CONTROL, VIDEO_DBG_CONTROL_INIT, video_get_current_time());
    drv_trace0(TRACE_GROUP_8, IL_VIDEO_DEC_INITIALIZATION);

    _VideoControlStructInit(&rVideoPlay);

    if (rVideoPlay.eState != VIDEO_PLAY_STATE_CLOSE)
    {
        EXT_ASSERT(0, rVideoPlay.eState, 0, 0);
    }

    // Initialize event used to syncronize component behavior
    //
    if (rVideoPlay.eEvent==0)
    {
        rVideoPlay.eEvent = kal_create_event_group("VIDEO_PLY_EVEVT");
    }

    // Initialize external/internal memory management
    //
    VideoInitExtBuffer(prInitInput->extmem_start_address, prInitInput->extmem_size);
    VideoInitIntBuffer(prInitInput->intmem_start_address, prInitInput->intmem_size, VIDEO_SCENARIO_DECODE);

    rVideoPlay.prMp4Parser = prInitInput->pstMp4Parser;
    rVideoPlay.prFSAL = prInitInput->pstFSAL;

    // Set audio related information
    //
    Media_A2V_SetFreq(MP4_Audio_GetSamplingFreq(prInitInput->pstMp4Parser));

    // Get file reader handle & set callback function
    //
    rVideoPlay.prVideoFileReaderHandle = GetVideoFileReaderHandle(VIDEO_FILEREADER_MP4);
    if (rVideoPlay.prVideoFileReaderHandle == NULL)
    {
        EXT_ASSERT(0, 0, 0, 0);
    }
    eError = rVideoPlay.prVideoFileReaderHandle->pfnSetCallbacks(&_VideoFileReaderCallback);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }

    // Get decoder type from file reader
    //
    eError = rVideoPlay.prVideoFileReaderHandle->pfnSetParameter(VIDEO_PARAM_PARSER_HANDLER, prInitInput->pstMp4Parser);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }

    eError = rVideoPlay.prVideoFileReaderHandle->pfnSetParameter(VIDEO_PARAM_FILE_HANDLER, prInitInput->pstFSAL);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }

    eError = rVideoPlay.prVideoFileReaderHandle->pfnGetParameter(VIDEO_PARAM_CODEC_TYPE, &eCodecType);
    if (eError != VIDEO_ERROR_NONE)
    {
        // We will check if there is visual track here after get decoder type
        //
        if (VIDEO_ERROR_NO_VISUAL_TRACK == eError)
        {
            rVideoPlay.fgHasVisualTrack = KAL_FALSE;
            // If there is no visual track, we should set play speed by IL client itself, not via clock component
            //
            Media_A2V_SetSpeedScale(rVideoPlay.u4PlaySpeed);

            drv_trace0(TRACE_GROUP_8, IL_NO_VISUAL);
            return NO_VISUAL_TRACK;
        }
        else if (VIDEO_ERROR_PARSER_ERROR == eError)
        {
            drv_trace1(TRACE_GROUP_8, IL_ERROR_PARSER, __LINE__);
            return MP4_PARSER_ERROR;
        }
        else
        {
            //EXT_ASSERT(0, eError, 0, 0);
            return VIDEO_ERROR;
        }
    }

    // If codec type is unknown, return VIDEO_ERROR
    //
    if (eCodecType == VIDEO_DECODER_UNKNOWN)
    {
        drv_trace1(TRACE_GROUP_8, IL_ERROR_DECODER_TYPE, __LINE__);
        return VIDEO_ERROR;
    }

    // Check frame rate
    //
    eError = rVideoPlay.prVideoFileReaderHandle->pfnGetParameter(VIDEO_PARAM_CODEC_FRAMERATE, &u4FPS);
    if (eError != VIDEO_ERROR_NONE)
    {
        if (VIDEO_ERROR_PARSER_ERROR == eError)
        {
            drv_trace1(TRACE_GROUP_8, IL_ERROR_PARSER, __LINE__);
            return MP4_PARSER_ERROR;
        }
        else
        {
            // For CR - MAUI_02363962
            //EXT_ASSERT(0, eError, 0, 0);
            return VIDEO_ERROR;
        }
    }

    if (VIDEO_PLAY_SUPPORT_MAX_FRAME < u4FPS)
    {
        drv_trace1(TRACE_GROUP_8, IL_ERROR_FPS, u4FPS);
        return VIDEO_ERROR;
    }

    // We have visual track
    //
    rVideoPlay.fgHasVisualTrack = KAL_TRUE;

    // Get decoder handle
    //
    rVideoPlay.prVideoDecoderHandle = GetVideoDecoderHandle(eCodecType);
    if (rVideoPlay.prVideoDecoderHandle == NULL)
    {
        EXT_ASSERT(0, 0, 0, 0);
    }

    eError = rVideoPlay.prVideoDecoderHandle->pfnSetCallbacks(&_VideoDecoderCallback);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }

    // Get scheduler handle
    //
    rVideoPlay.prVideoSchedulerHandle = GetVideoSchedulerHandle(VIDEO_SCHEDULER_COMM);
    if (rVideoPlay.prVideoSchedulerHandle == NULL)
    {
        EXT_ASSERT(0, 0, 0, 0);
    }
    eError = rVideoPlay.prVideoSchedulerHandle->pfnSetCallbacks(&_VideoSchedulerCallback);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }

    // Get clock handle
    //
    rVideoPlay.prVideoClockHandle = GetVideoClockHandle(VIDEO_CLOCK_DECORDER);
    if (rVideoPlay.prVideoClockHandle == NULL)
    {
        EXT_ASSERT(0, 0, 0, 0);
    }
    eError = rVideoPlay.prVideoClockHandle->pfnSetCallbacks(&_VideoClockCallback);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }

    // Get render handle
    // [6236_video_renderer]
#if (KAL_TRUE == VA2_COMP_VIDEO_RENDERER_SUPPORTED)
    rVideoPlay.prVideoRenderHandle = GetVideoRendererHandle(VIDEO_RENDERER_VIDEO_PLAYBACK);
#else
    rVideoPlay.prVideoRenderHandle = GetVideoRenderHandle(VIDEO_RENDER_COMM);
#endif

    if (rVideoPlay.prVideoRenderHandle == NULL)
    {
        EXT_ASSERT(0, 0, 0, 0);
    }
    eError = rVideoPlay.prVideoRenderHandle->pfnSetCallbacks(&_VideoRenderCallback);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
#if (KAL_TRUE == VA2_COMP_VIDEO_RENDERER_SUPPORTED)
    video_dec_set_video_renderer_handle(rVideoPlay.prVideoRenderHandle);
#endif

    // Setup tunnel
    //
    eError = VideoSetupTunnel(rVideoPlay.prVideoFileReaderHandle, rVideoPlay.prVideoDecoderHandle, VIDEO_PORT_VIDEO_DATA);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
    eError = VideoSetupTunnel(rVideoPlay.prVideoDecoderHandle, rVideoPlay.prVideoSchedulerHandle, VIDEO_PORT_VIDEO_DATA);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
    eError = VideoSetupTunnel(rVideoPlay.prVideoSchedulerHandle, rVideoPlay.prVideoClockHandle, VIDEO_PORT_TIME);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
    eError = VideoSetupTunnel(rVideoPlay.prVideoSchedulerHandle, rVideoPlay.prVideoRenderHandle, VIDEO_PORT_VIDEO_DATA);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }

    // Set related parameters to file reader
    //
    eError = rVideoPlay.prVideoFileReaderHandle->pfnSetParameter(VIDEO_PARAM_TIME_POS, &u8StartTime);
    if (eError != VIDEO_ERROR_NONE)
    {
        if (VIDEO_ERROR_PARSER_ERROR == eError)
        {
            drv_trace1(TRACE_GROUP_8, IL_ERROR_PARSER, __LINE__);
            return MP4_PARSER_ERROR;
        }
        else
        {
            EXT_ASSERT(0, eError, 0, 0);
        }
    }

    // Set related parameters to scheduler
    //
    rVideoPlay.u8RecoverTolerance = 0;
    eError = rVideoPlay.prVideoSchedulerHandle->pfnSetParameter(VIDEO_PARAM_AVSYNC_TOLERANCE, &rVideoPlay.u8RecoverTolerance);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }

    // Set related parameters to clock
    //
    prInitInput->audio_enable = KAL_FALSE;
    eError = rVideoPlay.prVideoClockHandle->pfnSetParameter(VIDEO_PARAM_AUDIO_ON, &prInitInput->audio_enable);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }

    eError = rVideoPlay.prVideoClockHandle->pfnSetParameter(VIDEO_PARAM_PLAY_SPEED, &rVideoPlay.u4PlaySpeed);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }

    eError = rVideoPlay.prVideoClockHandle->pfnSetParameter(VIDEO_PARAM_START_TIME, &u8StartTime);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }

    // Set related parameters to render
    // TODO: [6236_video_renderer] check what should be set at this stage...
#if (KAL_TRUE == VA2_COMP_VIDEO_RENDERER_SUPPORTED)
    {
        kal_bool bypass = KAL_TRUE;
        eError = rVideoPlay.prVideoRenderHandle->pfnSetParameter(VIDEO_PARAM_RENDERER_BYPASS, (void*) &bypass);
        if (eError != VIDEO_ERROR_NONE)
        {
            EXT_ASSERT(0, eError, 0, 0);
        }
    }
#else
    eError = rVideoPlay.prVideoRenderHandle->pfnSetParameter(VIDEO_PARAM_RENDER_MODE, (void*)&eRenderMode);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
#endif

    // Query frame width & height here
    //
    eError = _VideoDecoderQueryFrameSize();
    if (eError != VIDEO_ERROR_NONE)
    {
        if ((VIDEO_ERROR_CODEC_NOT_SUPPORT == eError) || (VIDEO_ERROR_QUERY_FRAME_SIZE == eError))
        {
            return VIDEO_ERROR;
        }
        else
        {
            EXT_ASSERT(0, eError, 0, 0);
        }
    }

    // Command all component to idle state
    //
    eError = rVideoPlay.prVideoRenderHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_IDLE);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
    eError = rVideoPlay.prVideoClockHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_IDLE);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
    eError = rVideoPlay.prVideoSchedulerHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_IDLE);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
    eError = rVideoPlay.prVideoDecoderHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_IDLE);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
    eError = rVideoPlay.prVideoFileReaderHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_IDLE);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
    kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_RENDER_COMPLETE|VIDEO_PLAY_EVENT_RENDER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if ((u4EventGroup&VIDEO_PLAY_EVENT_RENDER_ERROR) !=0)
    {
        return VIDEO_ERROR;
    }
    kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_CLOCK_COMPLETE|VIDEO_PLAY_EVENT_CLOCK_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if ((u4EventGroup&VIDEO_PLAY_EVENT_CLOCK_ERROR) !=0)
    {
        return VIDEO_ERROR;
    }
    kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_SCHEDULER_COMPLETE|VIDEO_PLAY_EVENT_SCHEDULER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if ((u4EventGroup&VIDEO_PLAY_EVENT_SCHEDULER_ERROR) !=0)
    {
        return VIDEO_ERROR;
    }
    kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_DECODER_COMPLETE|VIDEO_PLAY_EVENT_DECODER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if ((u4EventGroup&VIDEO_PLAY_EVENT_DECODER_ERROR) !=0)
    {
        return VIDEO_ERROR;
    }
    kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_FILEREADER_COMPLETE|VIDEO_PLAY_EVENT_FILEREADER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if ((u4EventGroup&VIDEO_PLAY_EVENT_FILEREADER_ERROR) !=0)
    {
        return VIDEO_ERROR;
    }

    rVideoPlay.eState = VIDEO_PLAY_STATE_INIT;
    rVideoPlay.fgDecoderComplete = KAL_FALSE;
    rVideoPlay.fgSchedulerComplete = KAL_FALSE;

    return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE video_dec_seek(kal_uint64 u8SeekTime, void (*pfnCallback)(kal_uint8 u1Event))
{
    VIDEO_ERROR_TYPE_T eError;
    kal_uint32 u4EventGroup;
    kal_bool fgAudioOn;
    kal_uint32 u4AudioFrameNo;
    kal_uint64 u8AudioDecodeTime;
    kal_uint32 u4AudioTimeScale;
    kal_uint64 u8Time = u8SeekTime*1000; // translate to us
    kal_uint64 u8CurrTime;
    kal_uint64 u8PrevITime = u8Time;

    video_dbg_trace(VIDEO_DBG_OWNER_CONTROL, VIDEO_DBG_CONTROL_SEEK, u8SeekTime);
    drv_trace0(TRACE_GROUP_8, IL_VIDEO_DEC_SEEK);

    rVideoPlay.pfnVideoDecCB = pfnCallback;

    // If there is no visual track, we just set back audio frame related seek time
    // And then callback seek done event
    //
    if (rVideoPlay.fgHasVisualTrack == KAL_FALSE)
    {
        // Set play back time base, if audio enable, play time is got from this time base
        //
        Media_A2V_SetPlaybackTimerBase(u8SeekTime, KAL_TRUE);

        // Callback seek done event
        //
        drv_trace1(TRACE_GROUP_8, IL_SEEK_DONE_EVENT, __LINE__);

        rVideoPlay.pfnVideoDecCB(VIDEO_DEC_EVENT_SEEK_DONE);

        return MEDIA_STATUS_OK;
    }

    // Decide whether seek from current frame or not
    //
    eError = rVideoPlay.prVideoClockHandle->pfnGetParameter(VIDEO_PARAM_CURR_TIME, &u8CurrTime);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
    eError = rVideoPlay.prVideoFileReaderHandle->pfnGetParameter(VIDEO_PARAM_PREV_I_TIME, &u8PrevITime);
    if (eError != VIDEO_ERROR_NONE)
    {
        if (VIDEO_ERROR_PARSER_ERROR == eError)
        {
            drv_trace1(TRACE_GROUP_8, IL_ERROR_PARSER, __LINE__);
            return MP4_PARSER_ERROR;
        }
        else
        {
            EXT_ASSERT(0, eError, 0, 0);
        }
    }

    if ((u8PrevITime <= u8CurrTime) && (u8CurrTime <= u8Time) && (u8Time != 0))
    {
        // Seek from current decode frame
        // Do not command to IDLE state, trasnit to RUN state directly
        drv_trace4(TRACE_GROUP_8, IL_SEEK_FROM_CURRENT_FRAME, u8PrevITime, u8CurrTime, u8Time, video_get_current_time());
        // test only
        VIDEO_WARNING(VIDEO_DBG_OWNER_CONTROL);
    }
    else
    {
        // Not seek from current frame, seek from previous I related to current time
        //
        drv_trace4(TRACE_GROUP_8, IL_SEEK_NOT_FROM_CURRENT_FRAME, u8PrevITime, u8CurrTime, u8Time, video_get_current_time());

        rVideoPlay.fgDecoderComplete = KAL_FALSE;
        rVideoPlay.fgSchedulerComplete = KAL_FALSE;

        // Command all component to idle state
        //
        eError = rVideoPlay.prVideoRenderHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_IDLE);
        if (eError != VIDEO_ERROR_NONE)
        {
            EXT_ASSERT(0, eError, 0, 0);
        }
        eError = rVideoPlay.prVideoClockHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_IDLE);
        if (eError != VIDEO_ERROR_NONE)
        {
            EXT_ASSERT(0, eError, 0, 0);
        }
        eError = rVideoPlay.prVideoSchedulerHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_IDLE);
        if (eError != VIDEO_ERROR_NONE)
        {
            EXT_ASSERT(0, eError, 0, 0);
        }
        eError = rVideoPlay.prVideoDecoderHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_IDLE);
        if (eError != VIDEO_ERROR_NONE)
        {
            EXT_ASSERT(0, eError, 0, 0);
        }
        eError = rVideoPlay.prVideoFileReaderHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_IDLE);
        if (eError != VIDEO_ERROR_NONE)
        {
            EXT_ASSERT(0, eError, 0, 0);
        }
        kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_RENDER_COMPLETE|VIDEO_PLAY_EVENT_RENDER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
        if ((u4EventGroup&VIDEO_PLAY_EVENT_RENDER_ERROR) !=0)
        {
            return VIDEO_ERROR;
        }
        kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_CLOCK_COMPLETE|VIDEO_PLAY_EVENT_CLOCK_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
        if ((u4EventGroup&VIDEO_PLAY_EVENT_CLOCK_ERROR) !=0)
        {
            return VIDEO_ERROR;
        }
        kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_SCHEDULER_COMPLETE|VIDEO_PLAY_EVENT_SCHEDULER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
        if ((u4EventGroup&VIDEO_PLAY_EVENT_SCHEDULER_ERROR) !=0)
        {
            return VIDEO_ERROR;
        }

        kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_DECODER_COMPLETE|VIDEO_PLAY_EVENT_DECODER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
        if ((u4EventGroup&VIDEO_PLAY_EVENT_DECODER_ERROR) !=0)
        {
            return VIDEO_ERROR;
        }

        kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_FILEREADER_COMPLETE|VIDEO_PLAY_EVENT_FILEREADER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
        if ((u4EventGroup&VIDEO_PLAY_EVENT_FILEREADER_ERROR) !=0)
        {
            return VIDEO_ERROR;
        }

    }

    eError = rVideoPlay.prVideoFileReaderHandle->pfnSetParameter(VIDEO_PARAM_TIME_POS, &u8Time);
    if (eError != VIDEO_ERROR_NONE)
    {
        if (VIDEO_ERROR_PARSER_ERROR == eError)
        {
            drv_trace1(TRACE_GROUP_8, IL_ERROR_PARSER, __LINE__);
            return MP4_PARSER_ERROR;
        }
        else
        {
            EXT_ASSERT(0, eError, 0, 0);
        }
    }
    //align to audio frame num and set to clock
    eError = rVideoPlay.prVideoClockHandle->pfnGetParameter(VIDEO_PARAM_AUDIO_ON, &fgAudioOn);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
    if (fgAudioOn == KAL_TRUE)
    {
        rVideoPlay.eParserStatus = MP4_Audio_TimeToSampleNo(rVideoPlay.prMp4Parser, u8SeekTime, &u4AudioFrameNo);

        if (rVideoPlay.eParserStatus == MP4_PARSER_NO_SUCH_TRACK)
        {
            /* no audio track */
            u4AudioFrameNo = 0;
            eError = rVideoPlay.prVideoClockHandle->pfnSetParameter(VIDEO_PARAM_START_TIME, &u8Time);
            if (eError != VIDEO_ERROR_NONE)
            {
                EXT_ASSERT(0, eError, 0, 0);
            }
        }
        else if (rVideoPlay.eParserStatus == MP4_PARSER_NO_SUCH_SAMPLE)
        {
            /* audio end */
            u4AudioFrameNo = 0;
            eError = rVideoPlay.prVideoClockHandle->pfnSetParameter(VIDEO_PARAM_START_TIME, &u8Time);
            if (eError != VIDEO_ERROR_NONE)
            {
                EXT_ASSERT(0, eError, 0, 0);
            }
        }
        else
        {
            //align to audio start time
            rVideoPlay.eParserStatus =MP4_GetDecodeTime(rVideoPlay.prMp4Parser, u4AudioFrameNo, &u8AudioDecodeTime, MP4_TRACK_AUDIO);
            if (rVideoPlay.eParserStatus != MP4_PARSER_OK)
            {
                EXT_ASSERT(0, rVideoPlay.eParserStatus, 0, 0);
            }
            rVideoPlay.eParserStatus =MP4_GetMediaTimeScale(rVideoPlay.prMp4Parser, &u4AudioTimeScale, MP4_TRACK_AUDIO);
            if (rVideoPlay.eParserStatus != MP4_PARSER_OK)
            {
                EXT_ASSERT(0, rVideoPlay.eParserStatus, 0, 0);
            }
            //translate to us
            u8Time = VIDEO_ANYBASE_TO_ANYBASE(u8AudioDecodeTime, u4AudioTimeScale, 1000000);
            eError = rVideoPlay.prVideoClockHandle->pfnSetParameter(VIDEO_PARAM_START_TIME, &u8Time);
            if (eError != VIDEO_ERROR_NONE)
            {
                EXT_ASSERT(0, eError, 0, 0);
            }
        }
    }
    else
    {
        /* no audio */
        u4AudioFrameNo = 0;
        eError = rVideoPlay.prVideoClockHandle->pfnSetParameter(VIDEO_PARAM_START_TIME, &u8Time);
        if (eError != VIDEO_ERROR_NONE)
        {
            EXT_ASSERT(0, eError, 0, 0);
        }
    }

    rVideoPlay.u4HdlrType = 0;
    rVideoPlay.eState = VIDEO_PLAY_STATE_SEEKING;

    // transit to RUN state
    eError = rVideoPlay.prVideoRenderHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_RUN);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
#if 0
#if (KAL_TRUE == VA2_COMP_VIDEO_RENDERER_SUPPORTED)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // #if (KAL_TRUE == VA2_COMP_VIDEO_RENDERER_SUPPORTED)
#endif  // #if 0
    eError = rVideoPlay.prVideoClockHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_RUN);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
    eError = rVideoPlay.prVideoSchedulerHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_RUN);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
    eError = rVideoPlay.prVideoDecoderHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_RUN);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
    eError = rVideoPlay.prVideoFileReaderHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_RUN);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
    kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_RENDER_COMPLETE|VIDEO_PLAY_EVENT_RENDER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if ((u4EventGroup&VIDEO_PLAY_EVENT_RENDER_ERROR) !=0)
    {
        return VIDEO_ERROR;
    }
    kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_CLOCK_COMPLETE|VIDEO_PLAY_EVENT_CLOCK_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if ((u4EventGroup&VIDEO_PLAY_EVENT_CLOCK_ERROR) !=0)
    {
        return VIDEO_ERROR;
    }
    kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_SCHEDULER_COMPLETE|VIDEO_PLAY_EVENT_SCHEDULER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if ((u4EventGroup&VIDEO_PLAY_EVENT_SCHEDULER_ERROR) !=0)
    {
        return VIDEO_ERROR;
    }
    kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_DECODER_COMPLETE|VIDEO_PLAY_EVENT_DECODER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if ((u4EventGroup&VIDEO_PLAY_EVENT_DECODER_ERROR) !=0)
    {
        return VIDEO_ERROR;
    }
    kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_FILEREADER_COMPLETE|VIDEO_PLAY_EVENT_FILEREADER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if ((u4EventGroup&VIDEO_PLAY_EVENT_FILEREADER_ERROR) !=0)
    {
        return VIDEO_ERROR;
    }

    return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE video_dec_seek_done(void)
{
    VIDEO_ERROR_TYPE_T eError;
    kal_uint32 u4EventGroup;

    drv_trace0(TRACE_GROUP_8, IL_VIDEO_DEC_SEEK_DONE);

    // If there is no visual track, we will ignore this call
    // We don't need to operate any components
    //
    if (rVideoPlay.fgHasVisualTrack == KAL_FALSE)
    {
        return MEDIA_STATUS_OK;
    }

    if (rVideoPlay.eState != VIDEO_PLAY_STATE_SEEKING)
    {
        EXT_ASSERT(0, rVideoPlay.eState, 0, 0);
    }

    rVideoPlay.eState = VIDEO_PLAY_STATE_SEEK_DONE;

    // transit to stop
    eError = rVideoPlay.prVideoFileReaderHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_STOP);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
    eError = rVideoPlay.prVideoDecoderHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_STOP);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
    eError = rVideoPlay.prVideoSchedulerHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_STOP);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
    eError = rVideoPlay.prVideoClockHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_STOP);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
#if (KAL_TRUE == VA2_COMP_VIDEO_RENDERER_SUPPORTED)
    eError = rVideoPlay.prVideoRenderHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_STOP);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
#else   // #if (KAL_TRUE == VA2_COMP_VIDEO_RENDERER_SUPPORTED)
    eError = rVideoPlay.prVideoRenderHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_STOP);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
#endif  // #if (KAL_TRUE == VA2_COMP_VIDEO_RENDERER_SUPPORTED)

    kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_FILEREADER_COMPLETE|VIDEO_PLAY_EVENT_FILEREADER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if ((u4EventGroup&VIDEO_PLAY_EVENT_FILEREADER_ERROR) !=0)
    {
        EXT_ASSERT(0, u4EventGroup, 0, 0);
    }
    kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_DECODER_COMPLETE|VIDEO_PLAY_EVENT_DECODER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if ((u4EventGroup&VIDEO_PLAY_EVENT_DECODER_ERROR) !=0)
    {
        EXT_ASSERT(0, u4EventGroup, 0, 0);
    }
    kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_SCHEDULER_COMPLETE|VIDEO_PLAY_EVENT_SCHEDULER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if ((u4EventGroup&VIDEO_PLAY_EVENT_SCHEDULER_ERROR) !=0)
    {
        EXT_ASSERT(0, u4EventGroup, 0, 0);
    }
    kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_CLOCK_COMPLETE|VIDEO_PLAY_EVENT_CLOCK_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if ((u4EventGroup&VIDEO_PLAY_EVENT_CLOCK_ERROR) !=0)
    {
        EXT_ASSERT(0, u4EventGroup, 0, 0);
    }
#if (KAL_TRUE == VA2_COMP_VIDEO_RENDERER_SUPPORTED)
    kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_RENDER_COMPLETE|VIDEO_PLAY_EVENT_RENDER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if ((u4EventGroup&VIDEO_PLAY_EVENT_RENDER_ERROR) !=0)
    {
        EXT_ASSERT(0, u4EventGroup, 0, 0);
    }
#else   // #if (KAL_TRUE == VA2_COMP_VIDEO_RENDERER_SUPPORTED)
    kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_RENDER_COMPLETE|VIDEO_PLAY_EVENT_RENDER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if ((u4EventGroup&VIDEO_PLAY_EVENT_RENDER_ERROR) !=0)
    {
        EXT_ASSERT(0, u4EventGroup, 0, 0);
    }
#endif  // #if (KAL_TRUE == VA2_COMP_VIDEO_RENDERER_SUPPORTED)
    return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE video_dec_play(kal_uint32 * pu4AudioFrameNo, void (*pfnCallback)(kal_uint8 u1Event))
{
    VIDEO_ERROR_TYPE_T eError;
    kal_uint32 u4EventGroup;
    kal_bool fgAudioOn;
    kal_uint32 u4AudioFrameNo;
    kal_uint32 u4AudioTimeScale;
    kal_uint64 u8AudioDecodeTime;
    kal_uint64 u8CurrTime;
    kal_uint64 u8Time;
    kal_bool fgEnableClock = KAL_TRUE;
    kal_bool fgIsAudioEnd = KAL_FALSE;

    video_dbg_trace(VIDEO_DBG_OWNER_CONTROL, VIDEO_DBG_CONTROL_PLAY, video_get_current_time());
    drv_trace0(TRACE_GROUP_8, IL_VIDEO_DEC_PLAY);

    if (rVideoPlay.eState != VIDEO_PLAY_STATE_SEEK_DONE &&
        rVideoPlay.eState != VIDEO_PLAY_STATE_PLAY_DONE &&
        rVideoPlay.eState != VIDEO_PLAY_STATE_STOP)
    {
        EXT_ASSERT(0, rVideoPlay.eState, 0, 0);
    }

    // Set callback
    //
    rVideoPlay.pfnVideoDecCB = pfnCallback;

    // Before video play, we should align A & V
    //
    eError = rVideoPlay.prVideoClockHandle->pfnGetParameter(VIDEO_PARAM_CURR_TIME, &u8CurrTime);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }

    // Align to audio frame num and set to clock
    //
    eError = rVideoPlay.prVideoClockHandle->pfnGetParameter(VIDEO_PARAM_AUDIO_ON, &fgAudioOn);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }

    if (fgAudioOn == KAL_TRUE)
    {
        rVideoPlay.eParserStatus = MP4_Audio_TimeToSampleNo(rVideoPlay.prMp4Parser, u8CurrTime/1000, &u4AudioFrameNo);

        if (rVideoPlay.eParserStatus == MP4_PARSER_NO_SUCH_TRACK)
        {
            /* no audio track */
            u4AudioFrameNo = 0;
            eError = rVideoPlay.prVideoClockHandle->pfnSetParameter(VIDEO_PARAM_START_TIME, &u8CurrTime);
            if (eError != VIDEO_ERROR_NONE)
            {
                EXT_ASSERT(0, eError, 0, 0);
            }
        }
        else if (rVideoPlay.eParserStatus == MP4_PARSER_NO_SUCH_SAMPLE)
        {
            /* audio end */
            u4AudioFrameNo = 0;
            fgIsAudioEnd = KAL_TRUE;
            eError = rVideoPlay.prVideoClockHandle->pfnSetParameter(VIDEO_PARAM_START_TIME, &u8CurrTime);
            if (eError != VIDEO_ERROR_NONE)
            {
                EXT_ASSERT(0, eError, 0, 0);
            }
        }
        else
        {
            //align to audio start time
            rVideoPlay.eParserStatus = MP4_GetDecodeTime(rVideoPlay.prMp4Parser, u4AudioFrameNo, &u8AudioDecodeTime, MP4_TRACK_AUDIO);
            if (rVideoPlay.eParserStatus != MP4_PARSER_OK)
            {
                EXT_ASSERT(0, rVideoPlay.eParserStatus, 0, 0);
            }

            rVideoPlay.eParserStatus = MP4_GetMediaTimeScale(rVideoPlay.prMp4Parser, &u4AudioTimeScale, MP4_TRACK_AUDIO);
            if (rVideoPlay.eParserStatus != MP4_PARSER_OK)
            {
                EXT_ASSERT(0, rVideoPlay.eParserStatus, 0, 0);
            }

            //translate to us
            u8Time = VIDEO_ANYBASE_TO_ANYBASE(u8AudioDecodeTime, u4AudioTimeScale, 1000000);
            eError = rVideoPlay.prVideoClockHandle->pfnSetParameter(VIDEO_PARAM_START_TIME, &u8Time);
            if (eError != VIDEO_ERROR_NONE)
            {
                EXT_ASSERT(0, eError, 0, 0);
            }
        }
        *pu4AudioFrameNo = u4AudioFrameNo;
    }
    else
    {
        *pu4AudioFrameNo = 0;
        eError = rVideoPlay.prVideoClockHandle->pfnSetParameter(VIDEO_PARAM_START_TIME, &u8CurrTime);
        if (eError != VIDEO_ERROR_NONE)
        {
            EXT_ASSERT(0, eError, 0, 0);
        }
    }

    rVideoPlay.u4HdlrType = 0;
    rVideoPlay.eState = VIDEO_PLAY_STATE_PLAYING;

    // transit to RUN state
    eError = rVideoPlay.prVideoRenderHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_RUN);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
    eError = rVideoPlay.prVideoClockHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_RUN);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
    eError = rVideoPlay.prVideoSchedulerHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_RUN);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
    eError = rVideoPlay.prVideoDecoderHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_RUN);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
    eError = rVideoPlay.prVideoFileReaderHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_RUN);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
    kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_RENDER_COMPLETE|VIDEO_PLAY_EVENT_RENDER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if ((u4EventGroup&VIDEO_PLAY_EVENT_RENDER_ERROR) !=0)
    {
        return VIDEO_ERROR;
    }
    kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_CLOCK_COMPLETE|VIDEO_PLAY_EVENT_CLOCK_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if ((u4EventGroup&VIDEO_PLAY_EVENT_CLOCK_ERROR) !=0)
    {
        return VIDEO_ERROR;
    }
    kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_SCHEDULER_COMPLETE|VIDEO_PLAY_EVENT_SCHEDULER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if ((u4EventGroup&VIDEO_PLAY_EVENT_SCHEDULER_ERROR) !=0)
    {
        return VIDEO_ERROR;
    }
    kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_DECODER_COMPLETE|VIDEO_PLAY_EVENT_DECODER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if ((u4EventGroup&VIDEO_PLAY_EVENT_DECODER_ERROR) !=0)
    {
        return VIDEO_ERROR;
    }
    kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_FILEREADER_COMPLETE|VIDEO_PLAY_EVENT_FILEREADER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if ((u4EventGroup&VIDEO_PLAY_EVENT_FILEREADER_ERROR) !=0)
    {
        return VIDEO_ERROR;
    }

    if (rVideoPlay.fgDecoderComplete == KAL_FALSE)
    {
        video_dbg_trace(VIDEO_DBG_OWNER_CONTROL, VIDEO_DBG_CONTROL_DECODER_WAITBUFFER, video_get_current_time());
        kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_FILEREADER_ERROR|VIDEO_PLAY_EVENT_DECODER_NOTIFY_COMPLETE|VIDEO_PLAY_EVENT_DECODER_NOTIFY_WAIT_BUFFER), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    }

    if (rVideoPlay.fgDecoderComplete == KAL_FALSE)
    {
        video_dbg_trace(VIDEO_DBG_OWNER_CONTROL, VIDEO_DBG_CONTROL_CLOCK_START, video_get_current_time());
        kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_FILEREADER_ERROR|VIDEO_PLAY_EVENT_CLOCK_START), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    }

    // may complete at this time
    if (rVideoPlay.eState == VIDEO_PLAY_STATE_PLAYING)
    {
        rVideoPlay.eState = VIDEO_PLAY_STATE_PLAY_DONE;
        //enable clock
        eError = rVideoPlay.prVideoClockHandle->pfnSetParameter(VIDEO_PARAM_CLOCK_ENABLE, &fgEnableClock);
        if (eError != VIDEO_ERROR_NONE)
        {
            EXT_ASSERT(0, eError, 0, 0);
        }
    }

    // After all components go run, the video may be finished.
    // If video is completed, we will callback VIDEO_DEC_EVENT_COMPLETE
    //
    if (rVideoPlay.fgDecoderComplete == KAL_TRUE && rVideoPlay.fgSchedulerComplete == KAL_TRUE)
    {
        // Callback video play complete event
        //
        drv_trace1(TRACE_GROUP_8, IL_PLAY_COMPLETE_EVENT, __LINE__);

        rVideoPlay.pfnVideoDecCB(VIDEO_DEC_EVENT_COMPLETE);
    }
    
    // If there is no audio or audio reach end
    //
    if (fgIsAudioEnd == KAL_TRUE)
    {
        return MEDIA_DEC_SEEK_AUDIO_END;
    }


    return MEDIA_STATUS_OK;

}

MEDIA_STATUS_CODE video_dec_recover(kal_uint32 * pu4AudioFrameNo, void (*pfnCallback)(kal_uint8 u1Event))
{
    MEDIA_STATUS_CODE eRet;

    video_dbg_trace(VIDEO_DBG_OWNER_CONTROL, VIDEO_DBG_CONTROL_RECOVER, video_get_current_time());
    drv_trace0(TRACE_GROUP_8, IL_VIDEO_DEC_RECOVER);

    if (rVideoPlay.eState != VIDEO_PLAY_STATE_PLAY_DONE)
    {
        EXT_ASSERT(0, rVideoPlay.eState, 0, 0);
    }

    rVideoPlay.fgRecover = KAL_TRUE;
    rVideoPlay.u4RecoverCount++;

    VIDEO_START_LOGGING("RCOV");

    video_dec_stop();
    eRet = video_dec_play(pu4AudioFrameNo, pfnCallback);

    VIDEO_STOP_LOGGING("RCOV");

    rVideoPlay.fgRecover = KAL_FALSE;

    return eRet;
}

void video_dec_stop(void)
{
    VIDEO_ERROR_TYPE_T eError;
    kal_uint32 u4EventGroup;
    kal_bool fgEnableClock = KAL_FALSE;

    video_dbg_trace(VIDEO_DBG_OWNER_CONTROL, VIDEO_DBG_CONTROL_STOP, video_get_current_time());
    drv_trace0(TRACE_GROUP_8, IL_VIDEO_DEC_STOP);

    // If there is no visual track, we will ignore this call for stop transfer
    // We don't need to operate any components
    //
    if (rVideoPlay.fgHasVisualTrack == KAL_FALSE)
    {
        return;
    }

    if ((rVideoPlay.eState == VIDEO_PLAY_STATE_CLOSE))
    {
        EXT_ASSERT(0, rVideoPlay.eState, 0, 0);
    }

    // Disable clock
    //
    eError = rVideoPlay.prVideoClockHandle->pfnSetParameter(VIDEO_PARAM_CLOCK_ENABLE, &fgEnableClock);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }

    eError = rVideoPlay.prVideoFileReaderHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_STOP);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
    eError = rVideoPlay.prVideoDecoderHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_STOP);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
    eError = rVideoPlay.prVideoSchedulerHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_STOP);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
    eError = rVideoPlay.prVideoClockHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_STOP);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
    eError = rVideoPlay.prVideoRenderHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_STOP);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }

    kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_FILEREADER_COMPLETE|VIDEO_PLAY_EVENT_FILEREADER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if ((u4EventGroup&VIDEO_PLAY_EVENT_FILEREADER_ERROR) !=0)
    {
        EXT_ASSERT(0, u4EventGroup, 0, 0);
    }
    kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_DECODER_COMPLETE|VIDEO_PLAY_EVENT_DECODER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if ((u4EventGroup&VIDEO_PLAY_EVENT_DECODER_ERROR) !=0)
    {
        EXT_ASSERT(0, u4EventGroup, 0, 0);
    }
    kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_SCHEDULER_COMPLETE|VIDEO_PLAY_EVENT_SCHEDULER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if ((u4EventGroup&VIDEO_PLAY_EVENT_SCHEDULER_ERROR) !=0)
    {
        EXT_ASSERT(0, u4EventGroup, 0, 0);
    }
    kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_CLOCK_COMPLETE|VIDEO_PLAY_EVENT_CLOCK_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if ((u4EventGroup&VIDEO_PLAY_EVENT_CLOCK_ERROR) !=0)
    {
        EXT_ASSERT(0, u4EventGroup, 0, 0);
    }
    kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_RENDER_COMPLETE|VIDEO_PLAY_EVENT_RENDER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if ((u4EventGroup&VIDEO_PLAY_EVENT_RENDER_ERROR) !=0)
    {
        EXT_ASSERT(0, u4EventGroup, 0, 0);
    }

    rVideoPlay.eState = VIDEO_PLAY_STATE_STOP;
}

void video_dec_close(void)
{
    VIDEO_ERROR_TYPE_T eError;
    kal_uint32 u4EventGroup;

    video_dbg_trace(VIDEO_DBG_OWNER_CONTROL, VIDEO_DBG_CONTROL_CLOSE, video_get_current_time());
    drv_trace0(TRACE_GROUP_8, IL_VIDEO_DEC_CLOSE);

    if ((rVideoPlay.eState == VIDEO_PLAY_STATE_PLAYING) || (rVideoPlay.eState == VIDEO_PLAY_STATE_PLAY_DONE))
    {
        EXT_ASSERT(0, rVideoPlay.eState, 0, 0);
    }

    // Switch all components to CLOSE
    //
    if (rVideoPlay.prVideoFileReaderHandle != NULL)
    {
        eError = rVideoPlay.prVideoFileReaderHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_CLOSE);
        if (eError != VIDEO_ERROR_NONE)
        {
            EXT_ASSERT(0, eError, 0, 0);
        }
    }
    if (rVideoPlay.prVideoDecoderHandle != NULL)
    {
        eError = rVideoPlay.prVideoDecoderHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_CLOSE);
        if (eError != VIDEO_ERROR_NONE)
        {
            EXT_ASSERT(0, eError, 0, 0);
        }
    }
    if (rVideoPlay.prVideoSchedulerHandle != NULL)
    {
        eError = rVideoPlay.prVideoSchedulerHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_CLOSE);
        if (eError != VIDEO_ERROR_NONE)
        {
            EXT_ASSERT(0, eError, 0, 0);
        }
    }
    if (rVideoPlay.prVideoClockHandle != NULL)
    {
        eError = rVideoPlay.prVideoClockHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_CLOSE);
        if (eError != VIDEO_ERROR_NONE)
        {
            EXT_ASSERT(0, eError, 0, 0);
        }
    }

    if (rVideoPlay.prVideoRenderHandle != NULL)
    {
        eError = rVideoPlay.prVideoRenderHandle->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_CLOSE);
        if (eError != VIDEO_ERROR_NONE)
        {
            EXT_ASSERT(0, eError, 0, 0);
        }
    }

    if (rVideoPlay.prVideoFileReaderHandle != NULL)
    {
        kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_FILEREADER_COMPLETE|VIDEO_PLAY_EVENT_FILEREADER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
        if ((u4EventGroup&VIDEO_PLAY_EVENT_FILEREADER_ERROR) !=0)
        {
            EXT_ASSERT(0, u4EventGroup, 0, 0);
        }
    }
    if (rVideoPlay.prVideoDecoderHandle != NULL)
    {
        kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_DECODER_COMPLETE|VIDEO_PLAY_EVENT_DECODER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
        if ((u4EventGroup&VIDEO_PLAY_EVENT_DECODER_ERROR) !=0)
        {
            EXT_ASSERT(0, u4EventGroup, 0, 0);
        }
    }
    if (rVideoPlay.prVideoSchedulerHandle != NULL)
    {
        kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_SCHEDULER_COMPLETE|VIDEO_PLAY_EVENT_SCHEDULER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
        if ((u4EventGroup&VIDEO_PLAY_EVENT_SCHEDULER_ERROR) !=0)
        {
            EXT_ASSERT(0, u4EventGroup, 0, 0);
        }
    }
    if (rVideoPlay.prVideoClockHandle != NULL)
    {
        kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_CLOCK_COMPLETE|VIDEO_PLAY_EVENT_CLOCK_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
        if ((u4EventGroup&VIDEO_PLAY_EVENT_CLOCK_ERROR) !=0)
        {
            EXT_ASSERT(0, u4EventGroup, 0, 0);
        }
    }

    if (rVideoPlay.prVideoRenderHandle != NULL)
    {
        kal_retrieve_eg_events(rVideoPlay.eEvent, (VIDEO_PLAY_EVENT_RENDER_COMPLETE|VIDEO_PLAY_EVENT_RENDER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
        if ((u4EventGroup&VIDEO_PLAY_EVENT_RENDER_ERROR) !=0)
        {
            EXT_ASSERT(0, u4EventGroup, 0, 0);
        }
    }

    //release handle
    if (rVideoPlay.prVideoFileReaderHandle)
    {
        eError = ReleaseVideoFileReaderHandle(rVideoPlay.prVideoFileReaderHandle);
        if (eError != VIDEO_ERROR_NONE)
        {
            ASSERT(0);
        }
    }

    if (rVideoPlay.prVideoDecoderHandle)
    {
        eError = ReleaseVideoDecoderHandle(rVideoPlay.prVideoDecoderHandle);
        if (eError != VIDEO_ERROR_NONE)
        {
            ASSERT(0);
        }
    }

    if (rVideoPlay.prVideoSchedulerHandle)
    {
        eError = ReleaseVideoSchedulerHandle(rVideoPlay.prVideoSchedulerHandle);
        if (eError != VIDEO_ERROR_NONE)
        {
            ASSERT(0);
        }
    }

    if (rVideoPlay.prVideoClockHandle)
    {
        eError = ReleaseVideoClockHandle(rVideoPlay.prVideoClockHandle);
        if (eError != VIDEO_ERROR_NONE)
        {
            ASSERT(0);
        }
    }

    if (rVideoPlay.prVideoRenderHandle)
    {
        // [6236_video_renderer]
#if (KAL_TRUE == VA2_COMP_VIDEO_RENDERER_SUPPORTED)
        eError = ReleaseVideoRendererHandle(rVideoPlay.prVideoRenderHandle);
#else
        eError = ReleaseVideoRenderHandle(rVideoPlay.prVideoRenderHandle);
#endif
        if (eError != VIDEO_ERROR_NONE)
        {
            ASSERT(0);
        }
    }

    VideoDeInitExtBuffer();
    VideoDeInitIntBuffer(VIDEO_SCENARIO_DECODE);

    rVideoPlay.eState = VIDEO_PLAY_STATE_CLOSE;
}

void video_dec_set_play_speed(kal_uint16 u2PlaySpeed)
{
    VIDEO_ERROR_TYPE_T eError;

    if ((rVideoPlay.eState != VIDEO_PLAY_STATE_INIT) && (rVideoPlay.eState != VIDEO_PLAY_STATE_SEEK_DONE)
        && (rVideoPlay.eState != VIDEO_PLAY_STATE_COMPLETE) && (rVideoPlay.eState != VIDEO_PLAY_STATE_STOP))
    {
        EXT_ASSERT(0, (kal_uint32)rVideoPlay.eState, 0, 0);
    }

    rVideoPlay.u4PlaySpeed = (kal_uint32)u2PlaySpeed;
    
    // If there is no visual track
    // Don't config clock component
    //
    if (rVideoPlay.fgHasVisualTrack == KAL_TRUE)
    {
        eError = rVideoPlay.prVideoClockHandle->pfnSetParameter(VIDEO_PARAM_PLAY_SPEED, &rVideoPlay.u4PlaySpeed);
        if (eError != VIDEO_ERROR_NONE)
        {
            EXT_ASSERT(0, eError, 0, 0);
        }
    }
    else
    {
        Media_A2V_SetSpeedScale(rVideoPlay.u4PlaySpeed);
    }

}

void video_dec_get_total_time(kal_uint64 * pu8AudioTime, kal_uint64 * pu8VideoTime)
{
    kal_uint32 u4VideoDuraion, u4VideoTimeScale;
    kal_uint32 u4AudioDuration, u4AudioTimeScale;

    if (pu8AudioTime == NULL || pu8VideoTime == NULL)
    {
        ASSERT(0);
        return;
    }

    if ((MP4_GetMediaDuration(rVideoPlay.prMp4Parser, &u4AudioDuration, MP4_TRACK_AUDIO) != MP4_PARSER_OK) ||
        (MP4_GetMediaTimeScale(rVideoPlay.prMp4Parser, &u4AudioTimeScale, MP4_TRACK_AUDIO) != MP4_PARSER_OK) )
    {
        //check why first
        //ASSERT(0);

        // If MP4 parser function can not get any information
        // Assume that this file has no such track
        *pu8AudioTime = 0;
    }
    else
    {
        *pu8AudioTime = VIDEO_ANYBASE_TO_ANYBASE(u4AudioDuration, u4AudioTimeScale, 1000);
    }

    if ((MP4_GetMediaDuration(rVideoPlay.prMp4Parser, &u4VideoDuraion, MP4_TRACK_VIDEO) != MP4_PARSER_OK) ||
        (MP4_GetMediaTimeScale(rVideoPlay.prMp4Parser, &u4VideoTimeScale, MP4_TRACK_VIDEO) != MP4_PARSER_OK) )
    {
        //check why first
        //ASSERT(0);

        // If MP4 parser function can not get any information
        // Assume that this file has no such track
        *pu8VideoTime = 0;
    }
    else
    {
        *pu8VideoTime = VIDEO_ANYBASE_TO_ANYBASE(u4VideoDuraion, u4VideoTimeScale,1000);
    }
}


MEDIA_STATUS_CODE video_dec_get_total_play_time(kal_uint64 * pu8TotalPlayTime)
{
    kal_uint64 u8VideoTime, u8AudioTime;

    if (pu8TotalPlayTime == NULL)
    {
        ASSERT(0);
        return VIDEO_ERROR;
    }

    video_dec_get_total_time(&u8AudioTime, &u8VideoTime);

    if (u8AudioTime < u8VideoTime)
    {
        *pu8TotalPlayTime = u8VideoTime;
    }
    else
    {
        *pu8TotalPlayTime = u8AudioTime;
    }

    return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE video_dec_get_play_time(kal_uint64 * pu8CurrentTime)
{
    kal_uint64 u8CurTime;
    MEDIA_STATUS_CODE eResult = MEDIA_STATUS_OK;
    VIDEO_ERROR_TYPE_T eError;

    // If there is no visual track
    // Audio is enabled. The timing information get from audio ticks
    if (rVideoPlay.fgHasVisualTrack == KAL_FALSE)
    {
        // Get play time by IL Client itself because there is no clock component
        //
        Media_A2V_Video_GetPlayTime_S(pu8CurrentTime);
    }
    else
    {
        // In legacy API implementation, we will do AV alignment again while video is not end.
        // In V2, we just skip this.
        // AV alignment happens only at SetParameter(VIDEO_PARAM_CURR_TIME) to clock component
        //

        eError = rVideoPlay.prVideoClockHandle->pfnGetParameter(VIDEO_PARAM_CURR_TIME, &u8CurTime);
        if (eError != VIDEO_ERROR_NONE)
        {
            EXT_ASSERT(0, eError, 0, 0);
        }

        if (pu8CurrentTime != NULL)
        {
            *pu8CurrentTime = VIDEO_ANYBASE_TO_ANYBASE(u8CurTime, 1000000, 1000);
        }
    }

    return eResult;
}

void video_dec_get_frame_size(kal_uint16* pu2Width, kal_uint16* pu2Height)
{
    kal_uint32 u4Width, u4Height;
    //VIDEO_RENDER_CONFIG_DATA_T rRenderConfigData;
    VIDEO_ERROR_TYPE_T eError;

    if (rVideoPlay.eState == VIDEO_PLAY_STATE_CLOSE)
    {
        EXT_ASSERT(0, rVideoPlay.eState, 0, 0);
    }

//to be checked with MA
#if 1
    eError = rVideoPlay.prVideoFileReaderHandle->pfnGetParameter(VIDEO_PARAM_FRAME_WIDTH, &u4Width);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
    eError = rVideoPlay.prVideoFileReaderHandle->pfnGetParameter(VIDEO_PARAM_FRAME_HEIGHT, &u4Height);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
#else
/* under construction !*/
/* under construction !*/
#endif

    *pu2Width = (kal_uint16)u4Width;
    *pu2Height = (kal_uint16)u4Height;

    // For test only
    // Set up render width & height
    // TODO: [6236_video_renderer] set video frame size?
#if (KAL_TRUE == VA2_COMP_VIDEO_RENDERER_SUPPORTED)
    {
      VA2_FRAME_SIZE_T video_frame_size;
      video_frame_size.u4_width = u4Width;
      video_frame_size.u4_height = u4Height;
      eError = rVideoPlay.prVideoRenderHandle->pfnSetParameter(VIDEO_CONFIG_RENDERER_SRC_SIZE, (void*) &video_frame_size);
      if (eError != VIDEO_ERROR_NONE)
      {
          EXT_ASSERT(0, eError, 0, 0);
      }
    }
#else
    rRenderConfigData.u4VideoWidth = u4Width;
    rRenderConfigData.u4VideoHeight= u4Height;
    eError = rVideoPlay.prVideoRenderHandle->pfnSetParameter(VIDEO_PARAM_RENDER_SETTING, (void*)&rRenderConfigData);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
#endif
}


void video_dec_set_audio(kal_bool fgEnable)
{
    VIDEO_ERROR_TYPE_T eError;

    if (rVideoPlay.eState == VIDEO_PLAY_STATE_CLOSE)
    {
        EXT_ASSERT(0, rVideoPlay.eState, 0, 0);
    }

    if (rVideoPlay.prVideoClockHandle == NULL)
    {
        ASSERT(0);
    }
    else
    {
        eError = rVideoPlay.prVideoClockHandle->pfnSetParameter(VIDEO_PARAM_AUDIO_ON, &fgEnable);
        if (eError != VIDEO_ERROR_NONE)
        {
            EXT_ASSERT(0, eError, 0, 0);
        }
    }
}


void video_dec_set_display(kal_bool fgEnable)
{
    VIDEO_ERROR_TYPE_T eError;

    if (rVideoPlay.eState == VIDEO_PLAY_STATE_CLOSE)
    {
        EXT_ASSERT(0, rVideoPlay.eState, 0, 0);
    }

#if (KAL_TRUE == VA2_COMP_VIDEO_RENDERER_SUPPORTED)
    eError = rVideoPlay.prVideoRenderHandle->pfnSetParameter(VIDEO_PARAM_RENDERER_TRIGGER_DISPLAY, (void*) &fgEnable);
#else
    eError = rVideoPlay.prVideoRenderHandle->pfnSetParameter(VIDEO_PARAM_ENABLE_DISPLAY, &fgEnable);
#endif
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
}

void video_dec_change_display_size(kal_uint32 u4Width, kal_uint32 u4Height)
{
    //VIDEO_ERROR_TYPE_T eError;
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
#endif
}

MEDIA_STATUS_CODE video_dec_frame2time(kal_uint32 u4Frame, kal_uint32 * pu4Time)
{
    kal_uint64 u8VideoTime;
    kal_uint32 u4VideoTimeScale;
    MP4_Parser_Status eStatus;

    if (rVideoPlay.eState== VIDEO_PLAY_STATE_CLOSE)
    {
        return VIDEO_ERROR;
    }

    eStatus = MP4_GetCompositionTime(rVideoPlay.prMp4Parser, u4Frame, &u8VideoTime, MP4_TRACK_VIDEO);
    if (eStatus != MP4_PARSER_OK)
    {
        drv_trace1(TRACE_GROUP_8, IL_ERROR_PARSER, __LINE__);
        return MP4_PARSER_ERROR;
    }
    eStatus = MP4_GetMediaTimeScale(rVideoPlay.prMp4Parser, &u4VideoTimeScale, MP4_TRACK_VIDEO);
    if (eStatus != MP4_PARSER_OK)
    {
        drv_trace1(TRACE_GROUP_8, IL_ERROR_PARSER, __LINE__);
        return MP4_PARSER_ERROR;
    }

    /* translate to ms */
    *pu4Time = VIDEO_ANYBASE_TO_ANYBASE(u8VideoTime, u4VideoTimeScale, 1000);
    return MEDIA_STATUS_OK;
}


MEDIA_STATUS_CODE video_dec_time2frame(kal_uint32 u4Time, kal_uint32 * pu4Frame)
{
    kal_uint64 u8VideoTime;
    kal_uint32 u4VideoTimeScale;
    MP4_Parser_Status eStatus;

    if (rVideoPlay.eState == VIDEO_PLAY_STATE_CLOSE)
    {
        return VIDEO_ERROR;
    }

    eStatus = MP4_GetMediaTimeScale(rVideoPlay.prMp4Parser, &u4VideoTimeScale, MP4_TRACK_VIDEO);
    if (eStatus != MP4_PARSER_OK)
    {
        drv_trace1(TRACE_GROUP_8, IL_ERROR_PARSER, __LINE__);
        return MP4_PARSER_ERROR;
    }

     /* translate to video time base */
    u8VideoTime = VIDEO_ANYBASE_TO_ANYBASE(u4Time, 1000, u4VideoTimeScale);

    eStatus = MP4_GetSampleNumber(rVideoPlay.prMp4Parser, pu4Frame, u8VideoTime, MP4_TRACK_VIDEO);
    if (eStatus != MP4_PARSER_OK)
    {
        drv_trace1(TRACE_GROUP_8, IL_ERROR_PARSER, __LINE__);
        return MP4_PARSER_ERROR;
    }

    return MEDIA_STATUS_OK;
}


VIDEO_DECODER_TYPE_T video_dec_get_decoder_type(void)
{
    VIDEO_DECODER_TYPE_T eDecoderType = VIDEO_DECODER_UNKNOWN;
    VIDEO_ERROR_TYPE_T eError;

    if (rVideoPlay.eState == VIDEO_PLAY_STATE_CLOSE)
    {
        return eDecoderType;
    }

    eError = rVideoPlay.prVideoFileReaderHandle->pfnSetParameter(VIDEO_PARAM_CODEC_TYPE, &eDecoderType);
    if (eError != VIDEO_ERROR_NONE)
    {
        if (eError == VIDEO_ERROR_NO_VISUAL_TRACK)
        {
            drv_trace0(TRACE_GROUP_8, IL_NO_VISUAL);
            return VIDEO_DECODER_UNKNOWN;
        }
        else if (VIDEO_ERROR_PARSER_ERROR == eError)
        {
            drv_trace1(TRACE_GROUP_8, IL_ERROR_PARSER, __LINE__);
            return VIDEO_DECODER_UNKNOWN;
        }
        else
        {
            EXT_ASSERT(0, eError, 0, 0);
        }
    }

    return eDecoderType;
}

// only for old IDP test
kal_uint32 video_dec_get_display_addr(void)
{
    VIDEO_ERROR_TYPE_T eError;
    kal_uint32 u4Addr;

    if (rVideoPlay.eState == VIDEO_PLAY_STATE_CLOSE)
    {
        ASSERT(0);
    }

    // TODO: [6236_video_renderer] check if this is what video_player_if_v2 wants...
#if (KAL_TRUE == VA2_COMP_VIDEO_RENDERER_SUPPORTED)
    {
      va2_video_renderer_dst_fb_t dst_fb;
      kal_mem_set(&dst_fb, 0x0, sizeof(va2_video_renderer_dst_fb_t));
      eError = rVideoPlay.prVideoRenderHandle->pfnGetParameter(VIDEO_PARAM_RENDERER_DST_FB_ADDR, &dst_fb);
      if (eError != VIDEO_ERROR_NONE)
      {
          EXT_ASSERT(0, eError, 0, 0);
      }
      u4Addr = dst_fb.r_fb_addr.u4_fb_addr_plane0;
    }
#else
    eError = rVideoPlay.prVideoRenderHandle->pfnGetParameter(VIDEO_PARAM_RENDER_DISPLY_ADDR, &u4Addr);
    if (eError != VIDEO_ERROR_NONE)
    {
        EXT_ASSERT(0, eError, 0, 0);
    }
#endif
    return u4Addr;
}

#ifdef PGDL_SUPPORT
//MP4_Parser_Status MP4_Video_GetAvailableDur(STMp4Parser *pstMp4Parser, kal_uint32 *puVideoDuration){return MP4_PARSER_OK;}
MEDIA_STATUS_CODE video_dec_PDL_initialize(MP4DEC_INIT_STRUCT * init_input){return MEDIA_STATUS_OK;}
MEDIA_STATUS_CODE MP4_Video_FrameAvailable(STMp4Parser * pstMp4Parser){return MEDIA_STATUS_OK;}
#endif

#endif /* __VIDEO_ARCHI_V2__ */

