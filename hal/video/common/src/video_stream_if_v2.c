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
 *   video_stream_if_v2.c
 *
 * Project:
 * --------
 *	MAUI - Video Architecture 2
 *
 * Description:
 * ------------
 *   Streaming APIs
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
 *
 *
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "drv_comm.h"

#ifdef __VIDEO_ARCHI_V2__

#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "stack_ltlcom.h"
#include "syscomp_config.h"
#include "task_config.h"
#include "gpt_sw.h"

#include "video_buffer_management_v2.h"
#include "video_comm_component_v2.h"
#include "video_decoder_component_v2.h"
#include "video_codec_if_v2.h"
#include "video_scheduler_component_if_v2.h"
#include "video_clock_component_if_v2.h"
#include "va2_comp_video_renderer.h"
#include "video_render_component_v2.h"
#include "video_stream_if_v2.h"
#include "h264_decore.h"

extern MEDIA_STATUS_CODE video_dec_set_video_renderer_handle(VIDEO_COMPONENT_TYPE_T *handle);
extern MEDIA_STATUS_CODE video_dec_config_render(VIDEO_RENDER_MODE_T eMode, void* pParam);

VIDEO_STREAM_STRUCT_T rGVideoStream;

#define H264_BASELINE_PROFILE_IDC  66
VIDEO_STREAM_MPEG4_CAP_T sMPEG4Cap = {90000,3,NULL};    // 3: simple profile level 3 from Table G-1, 14496-2
VIDEO_STREAM_H263_CAP_T  sH263Cap  = {90000,0,10};      // baseline profile level 10
#ifdef DRV_H264_DEC_SUPPORT
VIDEO_STREAM_H264_CAP_T  sH264Cap  = {90000,H264_RTP_SINGLE_NALU_MODE,H264_BASELINE_PROFILE_IDC,30,0,0};
#else
VIDEO_STREAM_H264_CAP_T  sH264Cap;
#endif

#ifdef VIDEO_STREAM_UNIT_TEST
extern VIDEO_COMPONENT_TYPE_T *prFileReaderHdlr;
VIDEO_STREAM_HANDLER_T *prGHdlr;
extern kal_eventgrpid MEDeEvent;
#endif

static kal_uint32 _VideoStreamCehckHdlrType(VIDEO_STREAM_COMPONENT_T eComponent, VIDEO_EVENT_TYPE_T eEvent)
{
    switch(eComponent)
    {
    case VIDEO_STREAM_COMPONENT_DECODER:
        switch(eEvent)
        {
        case VIDEO_EVENT_WAIT_BUFFER:
            return VIDEO_STREAM_DECODER_WAIT_BUFFER;
        	break;
        case VIDEO_EVENT_COMPLETE:
            return VIDEO_STREAM_DECODER_COMPLETE;
            break;
        case VIDEO_EVENT_ERROR:
            return VIDEO_STREAM_DECODER_ERROR;
            break;
        default:
            AOT(1);
            break;
        }
    	break;
    case VIDEO_STREAM_COMPONENT_SCHEDULER:
        switch(eEvent)
        {
        case VIDEO_EVENT_COMPLETE:
            return VIDEO_STREAM_SCHEDULER_COMPLETE;
        	break;
        case VIDEO_EVENT_RECOVER:
            return VIDEO_STREAM_SCHEDULER_RECOVER;
            break;
        default:
            AOT(1);
            break;
        }
    	break;
    case VIDEO_STREAM_COMPONENT_CLOCK:
        switch(eEvent)
        {
        case VIDEO_EVENT_START:
            return VIDEO_STREAM_CLOCK_START;
        	break;
        default:
            AOT(1);
            break;
        }
        break;
    case VIDEO_STREAM_COMPONENT_RENDER:
        switch(eEvent)
        {
        case VIDEO_EVENT_ERROR:
            return VIDEO_STREAM_RENDER_ERROR;
            break;
        default:
            AOT(1);
            break;
        }
        break;
    default:
        AOT(1);
        break;
    }
}

static void _VideoStreamHdlrInit(VIDEO_STREAM_COMPONENT_T eComponent, VIDEO_EVENT_TYPE_T eEvent)
{
    //VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    //kal_uint32 u4EventGroup;

    rGVideoStream.u4HdlrType |= _VideoStreamCehckHdlrType(eComponent, eEvent);

    if(rGVideoStream.u4HdlrType&VIDEO_STREAM_DECODER_WAIT_BUFFER || rGVideoStream.u4HdlrType&VIDEO_STREAM_DECODER_COMPLETE)
        rGVideoStream.fgIsDecoderReady = KAL_TRUE;

    if(rGVideoStream.u4HdlrType&VIDEO_STREAM_CLOCK_START)
        rGVideoStream.fgIsClockReady = KAL_TRUE;

    if(rGVideoStream.fgIsDecoderReady && rGVideoStream.fgIsClockReady)
    {
        rGVideoStream.fgIsReadyStart = KAL_TRUE;
        /*
        VIDEO_COMPONENT_TYPE_T *prDecoderHdlr = rGVideoStream.prDecoderHdlr;
        eError = prDecoderHdlr->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_STOP);
        AOT(eError != VIDEO_ERROR_NONE);
        kal_retrieve_eg_events(rGVideoStream.eEvent, (VIDEO_STREAM_EVENT_DECODER_COMPLETE|VIDEO_STREAM_EVENT_DECODER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
        AOT((u4EventGroup&VIDEO_STREAM_EVENT_DECODER_ERROR) !=0);
        rGVideoStream.fgChangeDecoderToRun = KAL_FALSE;
        rGVideoStream.fgIsReadyStart = KAL_TRUE;
        */
    }
}

static void _VideoStreamHdlrPlaying(VIDEO_STREAM_COMPONENT_T eComponent, VIDEO_EVENT_TYPE_T eEvent)
{
    rGVideoStream.u4HdlrType |= _VideoStreamCehckHdlrType(eComponent, eEvent);

    if(rGVideoStream.u4HdlrType&VIDEO_STREAM_DECODER_COMPLETE)
    {
        rGVideoStream.fgDecoderComplete = KAL_TRUE;
        kal_set_eg_events(rGVideoStream.eEvent, VIDEO_STREAM_EVENT_DECODER_NOTIFY_COMPLETE, KAL_OR);
    }

    if(rGVideoStream.u4HdlrType&VIDEO_STREAM_DECODER_WAIT_BUFFER)
    {
        kal_set_eg_events(rGVideoStream.eEvent, VIDEO_STREAM_EVENT_DECODER_NOTIFY_WAIT_BUFFER, KAL_OR);
    }

    if(rGVideoStream.u4HdlrType&VIDEO_STREAM_CLOCK_START)
    {
        kal_set_eg_events(rGVideoStream.eEvent, VIDEO_STREAM_EVENT_CLOCK_NOTIFY_START, KAL_OR);
    }

    if(rGVideoStream.u4HdlrType&VIDEO_STREAM_SCHEDULER_RECOVER)
    {
        rGVideoStream.u4HdlrType&=(~VIDEO_STREAM_SCHEDULER_RECOVER);
    }

}

static void _VideoStreamHdlrPlayed(VIDEO_STREAM_COMPONENT_T eComponent, VIDEO_EVENT_TYPE_T eEvent)
{
    rGVideoStream.u4HdlrType |= _VideoStreamCehckHdlrType(eComponent, eEvent);

    if(rGVideoStream.u4HdlrType&VIDEO_STREAM_DECODER_COMPLETE)
    {
        rGVideoStream.fgDecoderComplete = KAL_TRUE;
    }

    if(rGVideoStream.u4HdlrType&VIDEO_STREAM_SCHEDULER_COMPLETE)
    {
        //play done
        rGVideoStream.fgSchedulerComplete = KAL_TRUE;
        rGVideoStream.pfnVideoStreamCallback(VIDEO_RTP_EVENT_UNDERFLOW);
    }

    if(rGVideoStream.u4HdlrType&VIDEO_STREAM_SCHEDULER_RECOVER)
    {
        //underflow
        rGVideoStream.pfnVideoStreamCallback(VIDEO_RTP_EVENT_UNDERFLOW);
    }
}

#ifdef VIDEO_STREAM_UNIT_TEST
static VIDEO_ERROR_TYPE_T _VideoStreamFileReaderEventHandler(VIDEO_EVENT_TYPE_T eEvent, kal_uint32 u4Data1, kal_uint32 u4Data2, void* pData)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    switch(u4Data1)
    {
    case VIDEO_COMMAND_STATESET:
        switch(eEvent)
        {
        case VIDEO_EVENT_COMPLETE:
            kal_set_eg_events(rGVideoStream.eEvent, VIDEO_STREAM_EVENT_FILEREADER_COMPLETE, KAL_OR);
        	break;
        default:
            EXT_ASSERT(0, u4Data1, eEvent, 0);
            break;
        }
    	break;

    case VIDEO_COMMAND_NOTIFY:
    default:
        EXT_ASSERT(0, u4Data1, eEvent, 0);
        break;
    }

    return eError;
}
#endif

static VIDEO_ERROR_TYPE_T _VideoStreamDecoderEventHandler(VIDEO_EVENT_TYPE_T eEvent, kal_uint32 u4Data1, kal_uint32 u4Data2, void* pData)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    switch(u4Data1)
    {
    case VIDEO_COMMAND_STATESET:
        switch(eEvent)
        {
        case VIDEO_EVENT_COMPLETE:
            kal_set_eg_events(rGVideoStream.eEvent, VIDEO_STREAM_EVENT_DECODER_COMPLETE, KAL_OR);
        	break;
        default:
            EXT_ASSERT(0, u4Data1, eEvent, 0);
            break;
        }
    	break;

    case VIDEO_COMMAND_NOTIFY:
        switch(rGVideoStream.eState)
        {
        case VIDEO_STREAM_STATE_INIT:
            _VideoStreamHdlrInit(VIDEO_STREAM_COMPONENT_DECODER, eEvent);
            break;
        case VIDEO_STREAM_STATE_PLAYING:
            _VideoStreamHdlrPlaying(VIDEO_STREAM_COMPONENT_DECODER, eEvent);
        	break;
        case VIDEO_STREAM_STATE_PLAYED:
            _VideoStreamHdlrPlayed(VIDEO_STREAM_COMPONENT_DECODER, eEvent);
        	break;
        default:
            EXT_ASSERT(0, u4Data1, eEvent, 0);
            break;
        }
        break;

    default:
        EXT_ASSERT(0, u4Data1, eEvent, 0);
        break;
    }

    return eError;
}

static VIDEO_ERROR_TYPE_T _VideoStreamSchedulerEventHandler(VIDEO_EVENT_TYPE_T eEvent, kal_uint32 u4Data1, kal_uint32 u4Data2, void* pData)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    switch(u4Data1)
    {
    case VIDEO_COMMAND_STATESET:
        switch(eEvent)
        {
        case VIDEO_EVENT_COMPLETE:
            kal_set_eg_events(rGVideoStream.eEvent, VIDEO_STREAM_EVENT_SCHEDULER_COMPLETE, KAL_OR);
        	break;
        default:
            EXT_ASSERT(0, u4Data1, eEvent, 0);
            break;
        }
    	break;

    case VIDEO_COMMAND_NOTIFY:
        switch(rGVideoStream.eState)
        {
        case VIDEO_STREAM_STATE_PLAYING:
            _VideoStreamHdlrPlaying(VIDEO_STREAM_COMPONENT_SCHEDULER, eEvent);
        	break;
        case VIDEO_STREAM_STATE_PLAYED:
            _VideoStreamHdlrPlayed(VIDEO_STREAM_COMPONENT_SCHEDULER, eEvent);
        	break;
        case VIDEO_STREAM_STATE_STOP:
            break;
        default:
            EXT_ASSERT(0, u4Data1, eEvent, 0);
            break;
        }
        break;

    default:
        EXT_ASSERT(0, u4Data1, eEvent, 0);
        break;
    }

    return eError;
}

static VIDEO_ERROR_TYPE_T _VideoStreamClockEventHandler(VIDEO_EVENT_TYPE_T eEvent, kal_uint32 u4Data1, kal_uint32 u4Data2, void* pData)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    switch(u4Data1)
    {
    case VIDEO_COMMAND_STATESET:
        switch(eEvent)
        {
        case VIDEO_EVENT_COMPLETE:
            kal_set_eg_events(rGVideoStream.eEvent, VIDEO_STREAM_EVENT_CLOCK_COMPLETE, KAL_OR);
        	break;
        default:
            EXT_ASSERT(0, u4Data1, eEvent, 0);
            break;
        }
    	break;

    case VIDEO_COMMAND_NOTIFY:
        switch(rGVideoStream.eState)
        {
        case VIDEO_STREAM_STATE_INIT:
            _VideoStreamHdlrInit(VIDEO_STREAM_COMPONENT_CLOCK, eEvent);
            break;
        case VIDEO_STREAM_STATE_PLAYING:
            _VideoStreamHdlrPlaying(VIDEO_STREAM_COMPONENT_CLOCK, eEvent);
        	break;
        case VIDEO_STREAM_STATE_PLAYED:
            _VideoStreamHdlrPlayed(VIDEO_STREAM_COMPONENT_CLOCK, eEvent);
        	break;
        case VIDEO_STREAM_STATE_STOP:
            break;
        default:
            EXT_ASSERT(0, u4Data1, eEvent, 0);
            break;
        }
        break;

    default:
        EXT_ASSERT(0, u4Data1, eEvent, 0);
        break;
    }

    return eError;
}

static VIDEO_ERROR_TYPE_T _VideoStreamRenderEventHandler(VIDEO_EVENT_TYPE_T eEvent, kal_uint32 u4Data1, kal_uint32 u4Data2, void* pData)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    switch(u4Data1)
    {
    case VIDEO_COMMAND_STATESET:
        switch(eEvent)
        {
        case VIDEO_EVENT_COMPLETE:
            kal_set_eg_events(rGVideoStream.eEvent, VIDEO_STREAM_EVENT_RENDER_COMPLETE, KAL_OR);
        	break;
        default:
            EXT_ASSERT(0, u4Data1, eEvent, 0);
            break;
        }
    	break;

    case VIDEO_COMMAND_NOTIFY:
    default:
        EXT_ASSERT(0, u4Data1, eEvent, 0);
        break;
    }

    return eError;
}

#ifdef VIDEO_STREAM_UNIT_TEST
VIDEO_CALLBACK_TYPE_T _VideoStreamFileReaderCallback =
{
    _VideoStreamFileReaderEventHandler
};
#endif

static VIDEO_CALLBACK_TYPE_T _VideoStreamDecoderCallback =
{
    _VideoStreamDecoderEventHandler
};

static VIDEO_CALLBACK_TYPE_T _VideoStreamSchedulerCallback =
{
    _VideoStreamSchedulerEventHandler
};

static VIDEO_CALLBACK_TYPE_T _VideoStreamClockCallback =
{
    _VideoStreamClockEventHandler
};

static VIDEO_CALLBACK_TYPE_T _VideoStreamRenderCallback =
{
    _VideoStreamRenderEventHandler
};

VIDEO_ERROR_TYPE_T _VideoStreamFreeBitstream(VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    VIDEO_STREAM_BUFFERHEADER_TYPE_T rStreamBuffHeader;

    #ifndef VIDEO_STREAM_UNIT_TEST
    if(!rGVideoStream.fgFreeHeaderData)
    {
        rGVideoStream.fgFreeHeaderData = KAL_TRUE;
        return VIDEO_ERROR_NONE;
    }
    #endif

    rStreamBuffHeader.pu1Buffer = prBuffHeader->pu1Buffer;
    rStreamBuffHeader.u4BuffSize = prBuffHeader->u4BuffSize;
    rStreamBuffHeader.u8TimeStamp = prBuffHeader->u8TimeStamp;
    rStreamBuffHeader.pPrivateData = prBuffHeader->pPrivateData;

    drv_trace2(TRACE_GROUP_9, V2STREAM_FREE_BITSTREAM, (kal_uint32)rStreamBuffHeader.pu1Buffer, rStreamBuffHeader.u4BuffSize);
    return rGVideoStream.pfnVideoStreamFreeBitstream(rGVideoStream.pUserData, &rStreamBuffHeader);
}

#ifdef VIDEO_STREAM_UNIT_TEST
VIDEO_STREAM_STATUS_T VideoStreamPutFrame(VIDEO_STREAM_HANDLER_T *prHdlr, VIDEO_STREAM_BUFFERHEADER_TYPE_T *prBuffHeader);
VIDEO_ERROR_TYPE_T _VideoStreamSendBitstream(VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    VIDEO_STREAM_STATUS_T eError;
    VIDEO_STREAM_BUFFERHEADER_TYPE_T rStreamBuffHeader;

    rStreamBuffHeader.pu1Buffer = prBuffHeader->pu1Buffer;
    rStreamBuffHeader.u4BuffSize = prBuffHeader->u4BuffSize;
    rStreamBuffHeader.u8TimeStamp = prBuffHeader->u8TimeStamp;
    rStreamBuffHeader.pPrivateData = prBuffHeader->pPrivateData;

    switch(prBuffHeader->eFlags)
    {
    case VIDEO_BUFFERFLAG_NONE:
        rStreamBuffHeader.eFlags = VIDEO_STREAM_BUFFERFLAG_NONE;
    	break;
    case VIDEO_BUFFERFLAG_EOF:
        rStreamBuffHeader.eFlags = VIDEO_STREAM_BUFFERFLAG_EOF;
    	break;
    case VIDEO_BUFFERFLAG_STARTTIME:
        rStreamBuffHeader.eFlags = VIDEO_STREAM_BUFFERFLAG_STARTTIME;
        break;
    default:
        break;
    }

    eError = VideoStreamPutFrame(prGHdlr, &rStreamBuffHeader);

    if (eError != VIDEO_RTP_OK)
    {
        return VIDEO_ERROR_BUFF_FULL;
    }
    else
    {
        return VIDEO_ERROR_NONE;
    }
}
#endif

VIDEO_STREAM_CODEC_TYPE_T VideoStreamGetAvailableCodecs(VIDEO_STREAM_HANDLER_T *prHdlr)
{
    kal_uint32 u4AvailableCodec = 0;
    kal_uint32 u4Available = 0;

    // ask decoder component
    u4AvailableCodec = VideoDecoderGetAvialableCodec();

    if (u4AvailableCodec & CODEC_MPEG4)
        u4Available |= video_rtp_codec_mp4;

    if (u4AvailableCodec & CODEC_H263)
        u4Available |= video_rtp_codec_h263;

    if (u4AvailableCodec & CODEC_H264)
        u4Available |= video_rtp_codec_h264;

    drv_trace1(TRACE_GROUP_8, V2STREAM_GET_AVAILABLE_CODECS, u4Available);

    return (VIDEO_STREAM_CODEC_TYPE_T)u4Available;
}

VIDEO_STREAM_STATUS_T VideoStreamSetActiveCodec(VIDEO_STREAM_HANDLER_T *prHdlr, VIDEO_STREAM_CODEC_TYPE_T eType)
{
    AOF(prHdlr);
    /*lint -e613 */
    switch (eType)
    {
    case video_rtp_codec_mp4:
        prHdlr->g_stream_type = VIDEO_DEC_STREAM_MPEG4;
        rGVideoStream.eCodecType = VIDEO_DECODER_MPEG4;
        drv_trace0(TRACE_GROUP_8, V2STREAM_SET_ACTIVE_CODEC_MPEG4);
        break;
    case video_rtp_codec_h263:
        prHdlr->g_stream_type = VIDEO_DEC_STREAM_H263;
        rGVideoStream.eCodecType = VIDEO_DECODER_H263;
        drv_trace0(TRACE_GROUP_8, V2STREAM_SET_ACTIVE_CODEC_H263);
        break;
    case video_rtp_codec_h264:
        prHdlr->g_stream_type = VIDEO_DEC_STREAM_H264;
        rGVideoStream.eCodecType = VIDEO_DECODER_H264;
        drv_trace0(TRACE_GROUP_8, V2STREAM_SET_ACTIVE_CODEC_H264);
        break;
    default:
        return VIDEO_RTP_ERROR;
    }
    /*lint +e613 */

    rGVideoStream.fgIsDecoderReady = KAL_FALSE;
    rGVideoStream.fgIsClockReady = KAL_FALSE;
    rGVideoStream.fgIsReadyStart = KAL_FALSE;
    rGVideoStream.fgChangeDecoderToRun = KAL_FALSE;
    return VIDEO_RTP_OK;
}

VIDEO_STREAM_STATUS_T VideoStreamGetCapability(VIDEO_STREAM_HANDLER_T *prHdlr, void *pCodecCap)
{
    AOF(prHdlr);
    AOF(pCodecCap);

    drv_trace0(TRACE_GROUP_8, V2STREAM_GET_CAPABILITY);

    /*lint -e613 -e534 */
    switch (prHdlr->g_stream_type)
    {
    case VIDEO_DEC_STREAM_MPEG4:
        kal_mem_cpy((VIDEO_STREAM_MPEG4_CAP_T*)pCodecCap, &sMPEG4Cap, sizeof(VIDEO_STREAM_MPEG4_CAP_T));
        return VIDEO_RTP_OK;
    case VIDEO_DEC_STREAM_H263:
        kal_mem_cpy((VIDEO_STREAM_H263_CAP_T*)pCodecCap, &sH263Cap, sizeof(VIDEO_STREAM_H263_CAP_T));
        return VIDEO_RTP_OK;
    case VIDEO_DEC_STREAM_H264:
        kal_mem_cpy((VIDEO_STREAM_H264_CAP_T*)pCodecCap, &sH264Cap, sizeof(VIDEO_STREAM_H264_CAP_T));
        return VIDEO_RTP_OK;
    default:
        ASSERT(0);
        return VIDEO_RTP_ERROR;
    }
    /*lint +e613 +e534 */
}

VIDEO_STREAM_STATUS_T VideoStreamQueryCapability(VIDEO_STREAM_DEC_TYPE_T eType, void *pCodecCap)
{
    AOF(pCodecCap);

    drv_trace0(TRACE_GROUP_8, V2STREAM_QUERY_CAPABILITY);

    switch (eType)
    {
    case VIDEO_DEC_STREAM_MPEG4:
        kal_mem_cpy((VIDEO_STREAM_MPEG4_CAP_T*)pCodecCap, &sMPEG4Cap, sizeof(VIDEO_STREAM_MPEG4_CAP_T));
        return VIDEO_RTP_OK;
    case VIDEO_DEC_STREAM_H263:
        kal_mem_cpy((VIDEO_STREAM_H263_CAP_T*)pCodecCap, &sH263Cap, sizeof(VIDEO_STREAM_H263_CAP_T));
        return VIDEO_RTP_OK;
    case VIDEO_DEC_STREAM_H264:
        kal_mem_cpy((VIDEO_STREAM_H264_CAP_T*)pCodecCap, &sH264Cap, sizeof(VIDEO_STREAM_H264_CAP_T));
        return VIDEO_RTP_OK;
    default:
        ASSERT(0);
        return VIDEO_RTP_ERROR;
    }
}

VIDEO_STREAM_STATUS_T VideoStreamConfig(VIDEO_STREAM_HANDLER_T *prHdlr, VIDEO_STREAM_CONFIG_T *prVideoStreamConfig)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    VIDEO_COMPONENT_TYPE_T *prDecoderHdlr = NULL;
    VIDEO_COMPONENT_TYPE_T *prSchedulerHdlr = NULL;
    VIDEO_COMPONENT_TYPE_T *prClockHdlr = NULL;
    VIDEO_COMPONENT_TYPE_T *prRenderHdlr = NULL;
    kal_uint32 u4EventGroup;
    kal_uint32 u4PlaySpeed = 100;
    kal_bool fgAudioOn = KAL_FALSE; //KAL_TRUE;
    Media_Format eAudioFormat = MEDIA_FORMAT_AMR;

    AOF(prHdlr);
    //AOF(prVideoStreamConfig->p_codec_cap);
    AOF(prVideoStreamConfig->video_rtp_callback);
    AOF(prVideoStreamConfig->pfnVideoStreamFreeBitstream);
    drv_trace0(TRACE_GROUP_8, V2STREAM_CONFIG);

    rGVideoStream.pfnVideoStreamCallback = prVideoStreamConfig->video_rtp_callback;
    rGVideoStream.pfnVideoStreamFreeBitstream = prVideoStreamConfig->pfnVideoStreamFreeBitstream;
    rGVideoStream.pUserData = prVideoStreamConfig->pUserData;

    // initialize event used to synchronize component behavior
    if(rGVideoStream.eEvent==0)
    {
        rGVideoStream.eEvent = kal_create_event_group("VIDEO_STREAM_EVEVT");
    }

    #ifndef VIDEO_STREAM_UNIT_TEST
    VideoInitExtBuffer(prVideoStreamConfig->extmem_start_address, prVideoStreamConfig->extmem_size);
    drv_trace2(TRACE_GROUP_8, V2STREAM_INTERNAL_MEMORY, prVideoStreamConfig->extmem_start_address, prVideoStreamConfig->extmem_size);
    VideoInitIntBuffer(prVideoStreamConfig->intmem_start_address, prVideoStreamConfig->intmem_size, VIDEO_SCENARIO_DECODE);
    drv_trace2(TRACE_GROUP_8, V2STREAM_EXTERNAL_MEMORY, prVideoStreamConfig->intmem_start_address, prVideoStreamConfig->intmem_size);
    #endif

    #ifdef VIDEO_STREAM_UNIT_TEST
    AOT(rGVideoStream.eCodecType == VIDEO_DECODER_UNKNOWN);
    //set related parameters to file reader
    eError = prFileReaderHdlr->pfnSetParameter(VIDEO_PARAM_TIME_POS, &u8StartTime);
    prGHdlr = prHdlr;
    #endif

    // get decoder handler
    prDecoderHdlr = rGVideoStream.prDecoderHdlr = GetVideoDecoderHandle(rGVideoStream.eCodecType);
    AOF(prDecoderHdlr);
    eError = prDecoderHdlr->pfnSetCallbacks(&_VideoStreamDecoderCallback);
    AOT(eError != VIDEO_ERROR_NONE);
    drv_trace0(TRACE_GROUP_8, V2STREAM_CONFIG_GET_DECODER_COM);

    // get scheduler handler
    prSchedulerHdlr = rGVideoStream.prSchedulerHdlr = GetVideoSchedulerHandle(VIDEO_SCHEDULER_COMM);
    AOF(prSchedulerHdlr);
    eError = prSchedulerHdlr->pfnSetCallbacks(&_VideoStreamSchedulerCallback);
    AOT(eError != VIDEO_ERROR_NONE);
    drv_trace0(TRACE_GROUP_8, V2STREAM_CONFIG_GET_SCHEDULER_COM);

    // get clock handler
    prClockHdlr = rGVideoStream.prClockHdlr = GetVideoClockHandle(VIDEO_CLOCK_DECORDER);
    AOF(prClockHdlr);
    eError = prClockHdlr->pfnSetCallbacks(&_VideoStreamClockCallback);
    AOT(eError != VIDEO_ERROR_NONE);
    drv_trace0(TRACE_GROUP_8, V2STREAM_CONFIG_GET_CLOCK_COM);

    // get render handler
    //prRenderHdlr = rGVideoStream.prRenderHdlr = GetVideoRenderHandle(VIDEO_RENDER_COMM);
    prRenderHdlr = rGVideoStream.prRenderHdlr = GetVideoRendererHandle(VIDEO_RENDERER_VIDEO_PLAYBACK);
    AOF(prRenderHdlr);
    eError = prRenderHdlr->pfnSetCallbacks(&_VideoStreamRenderCallback);
    AOT(eError != VIDEO_ERROR_NONE);
    drv_trace0(TRACE_GROUP_8, V2STREAM_CONFIG_GET_RENDER_COM);

    rGVideoStream.eComponentState = VIDEO_STATE_INIT;

    // setup tunnel
    #ifdef VIDEO_STREAM_UNIT_TEST
    eError = VideoConfigComp(prFileReaderHdlr, KAL_FALSE, VIDEO_PORT_VIDEO_DATA, &_VideoStreamSendBitstream);
    AOT(eError != VIDEO_ERROR_NONE);
    #endif
    eError = VideoConfigComp(prDecoderHdlr, KAL_TRUE, VIDEO_PORT_VIDEO_DATA, &_VideoStreamFreeBitstream);
    AOT(eError != VIDEO_ERROR_NONE);
    eError = VideoSetupTunnel(prDecoderHdlr, prSchedulerHdlr, VIDEO_PORT_VIDEO_DATA);
    AOT(eError != VIDEO_ERROR_NONE);
    eError = VideoSetupTunnel(prSchedulerHdlr, prClockHdlr, VIDEO_PORT_TIME);
    AOT(eError != VIDEO_ERROR_NONE);
    eError = VideoSetupTunnel(prSchedulerHdlr, prRenderHdlr, VIDEO_PORT_VIDEO_DATA);
    AOT(eError != VIDEO_ERROR_NONE);
    drv_trace0(TRACE_GROUP_8, V2STREAM_CONFIG_SETUP_TUNNEL);

    switch(prVideoStreamConfig->audio_type) {
    case RTP_AUDIO_NONE:
    case RTP_AUDIO_AMR:
        eAudioFormat = MEDIA_FORMAT_AMR;
        break;
    case RTP_AUDIO_MP4A_LATM_AAC:
    case RTP_AUDIO_MPEG4_GENERIC_AAC:
    case RTP_AUDIO_ACCESS_UNIT_AAC:
        eAudioFormat = MEDIA_FORMAT_AAC;
        break;
    case RTP_AUDIO_AWB:
        eAudioFormat = MEDIA_FORMAT_AMR_WB;
        break;
    case RTP_AUDIO_BSAC:
        eAudioFormat = MEDIA_FORMAT_BSAC;
        break;
    default:
        eAudioFormat = MEDIA_FORMAT_AMR;
        break;
    }

    #ifndef VIDEO_STREAM_UNIT_TEST
    if(prVideoStreamConfig->uSampleRate)
    {
        fgAudioOn = KAL_TRUE;
        Media_A2V_SetMediaFormat(eAudioFormat);
        drv_trace1(TRACE_GROUP_8, V2STREAM_CONFIG_SET_MEDIA_FORMAT, eAudioFormat);
        Media_A2V_SetFreq(prVideoStreamConfig->uSampleRate);
        drv_trace1(TRACE_GROUP_8, V2STREAM_CONFIG_SET_SAMPLING_RATE, prVideoStreamConfig->uSampleRate);
    }
    #endif

    // set related parameters to clock
    eError = prClockHdlr->pfnSetParameter(VIDEO_PARAM_AUDIO_ON, &fgAudioOn);
    AOT(eError != VIDEO_ERROR_NONE);
    drv_trace1(TRACE_GROUP_8, V2STREAM_CONFIG_SET_CLOCK_PARA_AUDIO_ON, fgAudioOn);
    eError = prClockHdlr->pfnSetParameter(VIDEO_PARAM_PLAY_SPEED, &u4PlaySpeed);
    AOT(eError != VIDEO_ERROR_NONE);
    drv_trace1(TRACE_GROUP_8, V2STREAM_CONFIG_SET_CLOCK_PARA_PLAY_SPEED, u4PlaySpeed);


    //copy header
    /*lint -e613 -e534 */
    switch (prHdlr->g_stream_type)
    {
    case VIDEO_DEC_STREAM_MPEG4:
        {
            VIDEO_STREAM_MPEG4_CAP_T* prMPEG4Cap = (VIDEO_STREAM_MPEG4_CAP_T*)prVideoStreamConfig->p_codec_cap;
            kal_uint32 u4Size = rGVideoStream.u4HeaderDataSize = prMPEG4Cap->vos_length;
            AOT(u4Size>MAX_HEADER_DATA_SIZE);
            kal_mem_cpy(rGVideoStream.au1HeaderData, prMPEG4Cap->pconfig, u4Size);
            drv_trace1(TRACE_GROUP_8, V2STREAM_CONFIG_COPY_HEADER_DATA_MPEG4, u4Size);
            break;
        }
    case VIDEO_DEC_STREAM_H264:
        {
            VIDEO_STREAM_H264_CAP_T* prH264Cap = (VIDEO_STREAM_H264_CAP_T*)prVideoStreamConfig->p_codec_cap;
            kal_uint32 u4Size = rGVideoStream.u4HeaderDataSize = prH264Cap->AVC_config_record_size;
            AOT(u4Size>MAX_HEADER_DATA_SIZE);
            kal_mem_cpy(rGVideoStream.au1HeaderData, prH264Cap->AVC_config_record, u4Size);
            drv_trace1(TRACE_GROUP_8, V2STREAM_CONFIG_COPY_HEADER_DATA_H264, u4Size);
            break;
        }
    default:
        break;
    }
    /*lint +e613 +e534 */

    //command all component to idle state
    eError = prRenderHdlr->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_IDLE);
    AOT(eError != VIDEO_ERROR_NONE);
    eError = prClockHdlr->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_IDLE);
    AOT(eError != VIDEO_ERROR_NONE);
    eError = prSchedulerHdlr->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_IDLE);
    AOT(eError != VIDEO_ERROR_NONE);
    eError = prDecoderHdlr->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_IDLE);
    AOT(eError != VIDEO_ERROR_NONE);
    #ifdef VIDEO_STREAM_UNIT_TEST
    eError = prFileReaderHdlr->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_IDLE);
    AOT(eError != VIDEO_ERROR_NONE);
    #endif
    drv_trace0(TRACE_GROUP_8, V2STREAM_CONFIG_CHANGE_TO_IDLE_STATE);

    kal_retrieve_eg_events(rGVideoStream.eEvent, (VIDEO_STREAM_EVENT_RENDER_COMPLETE|VIDEO_STREAM_EVENT_RENDER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if((u4EventGroup&VIDEO_STREAM_EVENT_RENDER_ERROR) !=0)
        return VIDEO_RTP_ERROR;
    kal_retrieve_eg_events(rGVideoStream.eEvent, (VIDEO_STREAM_EVENT_CLOCK_COMPLETE|VIDEO_STREAM_EVENT_CLOCK_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if((u4EventGroup&VIDEO_STREAM_EVENT_CLOCK_ERROR) !=0)
        return VIDEO_RTP_ERROR;
    kal_retrieve_eg_events(rGVideoStream.eEvent, (VIDEO_STREAM_EVENT_SCHEDULER_COMPLETE|VIDEO_STREAM_EVENT_SCHEDULER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if((u4EventGroup&VIDEO_STREAM_EVENT_SCHEDULER_ERROR) !=0)
        return VIDEO_RTP_ERROR;
    kal_retrieve_eg_events(rGVideoStream.eEvent, (VIDEO_STREAM_EVENT_DECODER_COMPLETE|VIDEO_STREAM_EVENT_DECODER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if((u4EventGroup&VIDEO_STREAM_EVENT_DECODER_ERROR) !=0)
        return VIDEO_RTP_ERROR;
    #ifdef VIDEO_STREAM_UNIT_TEST
    kal_retrieve_eg_events(rGVideoStream.eEvent, (VIDEO_STREAM_EVENT_FILEREADER_COMPLETE|VIDEO_STREAM_EVENT_FILEREADER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if((u4EventGroup&VIDEO_STREAM_EVENT_FILEREADER_ERROR) !=0)
        return VIDEO_RTP_ERROR;
    #endif
    rGVideoStream.eComponentState = VIDEO_STATE_IDLE;
    drv_trace0(TRACE_GROUP_8, V2STREAM_CONFIG_CHANGE_TO_IDLE_STATE_DONE);

    rGVideoStream.eState = VIDEO_STREAM_STATE_INIT;
    rGVideoStream.u4Width = 0;
    rGVideoStream.u4Height = 0;
    rGVideoStream.fgDecoderComplete = KAL_FALSE;
    rGVideoStream.fgSchedulerComplete = KAL_FALSE;
    rGVideoStream.fgPutHeaderData = KAL_FALSE;
    rGVideoStream.fgFreeHeaderData = KAL_TRUE;
    rGVideoStream.eQueryResolutionResult = VIDEO_ERROR_MAX;

    return VIDEO_RTP_OK;
}

VIDEO_STREAM_STATUS_T VideoStreamGetImageResolution(VIDEO_STREAM_HANDLER_T *prHdlr, kal_uint32 *pu4Width, kal_uint32 *pu4Height, void (*pfnCallback)(VIDEO_STREAM_EVENT_T eEvent))
{
    AOF(prHdlr);

    //drv_trace0(TRACE_GROUP_8, V2STREAM_GET_IMAGE_RESOLUTION);
    if(rGVideoStream.eQueryResolutionResult == VIDEO_ERROR_MAX)
    {
        drv_trace0(TRACE_GROUP_8, V2STREAM_GET_IMAGE_RESOLUTION_NOT_READY);
        return VIDEO_RTP_RESOLUTION_NOT_READY;
    }
    else if(rGVideoStream.eQueryResolutionResult == VIDEO_ERROR_NONE)
    {
        *pu4Width = rGVideoStream.u4Width;
        *pu4Height = rGVideoStream.u4Height;
        drv_trace2(TRACE_GROUP_8, V2STREAM_GET_IMAGE_RESOLUTION_OK, *pu4Width, *pu4Height);
        return VIDEO_RTP_OK;
    }
    else
    {
        drv_trace0(TRACE_GROUP_8, V2STREAM_GET_IMAGE_RESOLUTION_FAIL);
        return VIDEO_RTP_RESOLUTION_ERR;
    }
}

VIDEO_STREAM_STATUS_T VideoStreamPutFrame(VIDEO_STREAM_HANDLER_T *prHdlr, VIDEO_STREAM_BUFFERHEADER_TYPE_T *prStreamBuffHeader)
{
    VIDEO_BUFFERHEADER_TYPE_T rBuffHeader;
    VIDEO_QUERY_FRAME_SIZE_TYPE_T rQueryFrameSizeData;
    VIDEO_COMPONENT_TYPE_T *prDecoderHdlr = NULL;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    kal_uint32 u4EventGroup;

    AOF(prHdlr);

    prDecoderHdlr = rGVideoStream.prDecoderHdlr;

    if(rGVideoStream.eState== VIDEO_STREAM_STATE_STOP)
    {
        return VIDEO_RTP_ERROR;
    }

    //if(!rGVideoStream.fgPutHeaderData && prHdlr->scenario != VIDEO_DEC_STREAM_MTV_SCENARIO)
    if(!rGVideoStream.fgPutHeaderData)
    {
        switch (rGVideoStream.eCodecType)
        {
        case VIDEO_DEC_STREAM_MPEG4:
            {
                rQueryFrameSizeData.pu1ParamStream = rGVideoStream.au1HeaderData;
                rQueryFrameSizeData.u4ParamLength = rGVideoStream.u4HeaderDataSize;
                drv_trace2(TRACE_GROUP_8, V2STREAM_PUT_FRAME_MPEG4_HEADER_DATA, (kal_uint32)rQueryFrameSizeData.pu1ParamStream, rQueryFrameSizeData.u4ParamLength);

                rBuffHeader.pu1Buffer = rGVideoStream.au1HeaderData;
                rBuffHeader.u4BuffSize = rGVideoStream.u4HeaderDataSize;
                rBuffHeader.u8TimeStamp = 0;
                rGVideoStream.fgFreeHeaderData = KAL_FALSE;

                break;
            }

        case VIDEO_DEC_STREAM_H263:
            {
                rQueryFrameSizeData.pu1ParamStream = prStreamBuffHeader->pu1Buffer;
                rQueryFrameSizeData.u4ParamLength = prStreamBuffHeader->u4BuffSize;
                drv_trace2(TRACE_GROUP_8, V2STREAM_PUT_FRAME_H263_HEADER_DATA, (kal_uint32)rQueryFrameSizeData.pu1ParamStream, rQueryFrameSizeData.u4ParamLength);

                rBuffHeader.pu1Buffer = prStreamBuffHeader->pu1Buffer;
                rBuffHeader.u4BuffSize = prStreamBuffHeader->u4BuffSize;
                rBuffHeader.u8TimeStamp = prStreamBuffHeader->u8TimeStamp;

                break;
            }

        case VIDEO_DEC_STREAM_H264:
            {
                H264_DECODER_INPUT_PARAM_T *prPrivateData;
                H264_DECODER_PAYLOAD_INFO_T *parNALCTRLBuff;
                kal_uint8 u1SPSNum, u1PPSNum, u1Idx, u1PSIdx, u1DataIdx;
                kal_uint8 *pu1Buff;

                prPrivateData = &rGVideoStream.rPrivateData;
                parNALCTRLBuff = &rGVideoStream.arNALCTRLBuff[0];
                pu1Buff = (kal_uint8*)&rGVideoStream.au1HeaderData[0];
                prPrivateData->pu1PayloadAddress = parNALCTRLBuff;

                #ifndef VIDEO_STREAM_UNIT_TEST
                pu1Buff+=5;
                #endif
                u1SPSNum = (pu1Buff[0] & 0x1F);
                pu1Buff++;

                u1PSIdx = 0;
                u1DataIdx = 0;
                for(u1Idx=0; u1Idx<u1SPSNum; u1Idx++)
                {
                    parNALCTRLBuff->u4Length = (kal_uint32) ( (pu1Buff[u1DataIdx] & 0xFF)<<8 | (pu1Buff[u1DataIdx+1] & 0xFF) );
                    u1DataIdx+=2;
                    parNALCTRLBuff->u4Address = (kal_uint32) &pu1Buff[u1DataIdx];
                    u1DataIdx += parNALCTRLBuff->u4Length;
                    parNALCTRLBuff++;
                }

                u1PPSNum = pu1Buff[u1DataIdx++];
                for(u1Idx=0; u1Idx<u1PPSNum; u1Idx++)
                {
                    parNALCTRLBuff->u4Length = (kal_uint32) ( (pu1Buff[u1DataIdx] & 0xFF)<<8 | (pu1Buff[u1DataIdx+1] & 0xFF) );
                    u1DataIdx+=2;
                    parNALCTRLBuff->u4Address = (kal_uint32) &pu1Buff[u1DataIdx];
                    u1DataIdx += parNALCTRLBuff->u4Length;
                    parNALCTRLBuff++;
                }

                rQueryFrameSizeData.pu1ParamStream = (kal_uint8*)(rGVideoStream.arNALCTRLBuff[0].u4Address);
                rQueryFrameSizeData.u4ParamLength = rGVideoStream.arNALCTRLBuff[0].u4Length;
                drv_trace2(TRACE_GROUP_8, V2STREAM_PUT_FRAME_H264_HEADER_DATA, (kal_uint32)rQueryFrameSizeData.pu1ParamStream, rQueryFrameSizeData.u4ParamLength);

                prPrivateData->u4PayloadNumber = u1SPSNum + u1PPSNum;
                rBuffHeader.pPrivateData = (void *)prPrivateData;
                rGVideoStream.fgFreeHeaderData = KAL_FALSE;

                break;
            }

        default:
            AOF(0);
            break;
        }

        rGVideoStream.eQueryResolutionResult = prDecoderHdlr->pfnGetParameter(VIDEO_PARAM_QUERY_RESOLUTION_AHEAD, &rQueryFrameSizeData);
        rGVideoStream.u4Width = rQueryFrameSizeData.u4Width;
        rGVideoStream.u4Height = rQueryFrameSizeData.u4Height;
        drv_trace2(TRACE_GROUP_8, V2STREAM_PUT_FRAME_QUERY_RESOLUTION, rGVideoStream.u4Width, rGVideoStream.u4Height);

        rBuffHeader.eFlags = VIDEO_BUFFERFLAG_PARAMETERSET;
        rBuffHeader.u4InputPort = rBuffHeader.u4OutputPort = 0;
        eError = prDecoderHdlr->pfnEmptyThisBuffer(&rBuffHeader);
        AOT(eError != VIDEO_ERROR_NONE); // the very first data, Decoder's input queue should not be full
        drv_trace0(TRACE_GROUP_8, V2STREAM_PUT_FRAME_PUT_HEADER_DATA_TO_DECODER);
        drv_trace4(TRACE_GROUP_9, V2STREAM_PUT_FRAME_OK, (kal_uint32)rBuffHeader.pu1Buffer, rBuffHeader.u4BuffSize, rBuffHeader.u8TimeStamp, rBuffHeader.eFlags);
        rGVideoStream.fgPutHeaderData = KAL_TRUE;

        rGVideoStream.fgChangeDecoderToRun = KAL_TRUE;
        eError = prDecoderHdlr->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_RUN);
        AOT(eError != VIDEO_ERROR_NONE);
        kal_retrieve_eg_events(rGVideoStream.eEvent, (VIDEO_STREAM_EVENT_DECODER_COMPLETE|VIDEO_STREAM_EVENT_DECODER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
        AOT((u4EventGroup&VIDEO_STREAM_EVENT_DECODER_ERROR) !=0)

    #ifdef VIDEO_STREAM_UNIT_TEST
        kal_set_eg_events(MEDeEvent, VIDEO_STREAM_PUTFRAME_EVENT_COMPLETE, KAL_OR);
    #endif

        if (rGVideoStream.eCodecType == VIDEO_DEC_STREAM_H263)
            return VIDEO_RTP_OK;
    }

    rBuffHeader.pu1Buffer = prStreamBuffHeader->pu1Buffer;
    rBuffHeader.u4BuffSize = prStreamBuffHeader->u4BuffSize;
    rBuffHeader.u8TimeStamp = prStreamBuffHeader->u8TimeStamp;
    rBuffHeader.pPrivateData = prStreamBuffHeader->pPrivateData;
    rBuffHeader.u4InputPort = rBuffHeader.u4OutputPort = 0;

    switch(prStreamBuffHeader->eFlags)
    {
    case VIDEO_STREAM_BUFFERFLAG_NONE:
        rBuffHeader.eFlags = VIDEO_BUFFERFLAG_NONE;
        break;
    case VIDEO_STREAM_BUFFERFLAG_EOF:
        rBuffHeader.eFlags = VIDEO_BUFFERFLAG_EOF;
    	break;
    case VIDEO_STREAM_BUFFERFLAG_STARTTIME:
        rBuffHeader.eFlags = VIDEO_BUFFERFLAG_STARTTIME;
    	break;
    default:
        ASSERT(0)
        break;
    }

    eError = prDecoderHdlr->pfnEmptyThisBuffer(&rBuffHeader);

    if (eError == VIDEO_ERROR_NONE)
    {
        drv_trace4(TRACE_GROUP_9, V2STREAM_PUT_FRAME_OK, (kal_uint32)rBuffHeader.pu1Buffer, rBuffHeader.u4BuffSize, rBuffHeader.u8TimeStamp, rBuffHeader.eFlags);
        return VIDEO_RTP_OK;
    }
    else
    {
        drv_trace4(TRACE_GROUP_9, V2STREAM_PUT_FRAME_FAIL, (kal_uint32)rBuffHeader.pu1Buffer, rBuffHeader.u4BuffSize, rBuffHeader.u8TimeStamp, rBuffHeader.eFlags);
        return VIDEO_RTP_ERROR;
    }
}

VIDEO_STREAM_STATUS_T VideoStreamGetPlayTime(VIDEO_STREAM_HANDLER_T *prHdlr, kal_uint32 *pu4CurrTime)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    kal_uint64 u8CurTime = 0;

    AOF(prHdlr);

    if(rGVideoStream.eState== VIDEO_STREAM_STATE_CLOSE)
    {
        return VIDEO_RTP_ERROR;
    }

    eError = rGVideoStream.prClockHdlr->pfnGetParameter(VIDEO_PARAM_CURR_TIME, &u8CurTime);
    AOT(eError != VIDEO_ERROR_NONE);

    *pu4CurrTime = (kal_uint32)VIDEO_ANYBASE_TO_ANYBASE(u8CurTime,1000000,1000);
    drv_trace1(TRACE_GROUP_9, V2STREAM_GET_PLAY_TIME, *pu4CurrTime);

    return VIDEO_RTP_OK;
}

kal_bool VideoStreamQueryStart(void)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    kal_uint32 u4EventGroup;

    //if(rGVideoStream.fgIsReadyStart)
    if(rGVideoStream.fgIsDecoderReady)
    {
        VIDEO_COMPONENT_TYPE_T *prDecoderHdlr = rGVideoStream.prDecoderHdlr;
        eError = prDecoderHdlr->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_STOP);
        AOT(eError != VIDEO_ERROR_NONE);
        kal_retrieve_eg_events(rGVideoStream.eEvent, (VIDEO_STREAM_EVENT_DECODER_COMPLETE|VIDEO_STREAM_EVENT_DECODER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
        AOT((u4EventGroup&VIDEO_STREAM_EVENT_DECODER_ERROR) !=0);
        rGVideoStream.fgChangeDecoderToRun = KAL_FALSE;
    }
    //return rGVideoStream.fgIsReadyStart;
    return rGVideoStream.fgIsDecoderReady;
}

VIDEO_STREAM_STATUS_T VideoStreamStart(VIDEO_STREAM_HANDLER_T *prHdlr, kal_uint32 u4StartTime, void (*pfnCallback)(VIDEO_STREAM_EVENT_T eEvent))
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    VIDEO_COMPONENT_TYPE_T *prDecoderHdlr = NULL;
    VIDEO_COMPONENT_TYPE_T *prSchedulerHdlr = NULL;
    VIDEO_COMPONENT_TYPE_T *prClockHdlr = NULL;
    VIDEO_COMPONENT_TYPE_T *prRenderHdlr = NULL;
    kal_uint32 u4EventGroup;
    kal_uint64 u8StartTime = 0;

    AOF(prHdlr);
    //AOF(rGVideoStream.fgIsReadyStart);
    AOF(rGVideoStream.fgIsDecoderReady);
    drv_trace0(TRACE_GROUP_8, V2STREAM_START);

    prDecoderHdlr = rGVideoStream.prDecoderHdlr;
    prSchedulerHdlr = rGVideoStream.prSchedulerHdlr;
    prClockHdlr = rGVideoStream.prClockHdlr;
    prRenderHdlr = rGVideoStream.prRenderHdlr;

    rGVideoStream.u4HdlrType = 0;
    rGVideoStream.eState = VIDEO_STREAM_STATE_PLAYING;
    drv_trace0(TRACE_GROUP_9, V2STREAM_START_STATE_PLAYING);

    u8StartTime = (kal_uint64)u4StartTime;
    eError = prClockHdlr->pfnSetParameter(VIDEO_PARAM_START_TIME, &u8StartTime);
    AOT(eError != VIDEO_ERROR_NONE);
    drv_trace1(TRACE_GROUP_8, V2STREAM_START_SET_CLOCK_PARA_START_TIME, u8StartTime);

    //command all component to run state
    eError = prRenderHdlr->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_RUN);
    AOT(eError != VIDEO_ERROR_NONE);
    eError = prClockHdlr->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_RUN);
    AOT(eError != VIDEO_ERROR_NONE);
    eError = prSchedulerHdlr->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_RUN);
    AOT(eError != VIDEO_ERROR_NONE);
    eError = prDecoderHdlr->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_RUN);
    AOT(eError != VIDEO_ERROR_NONE);
    drv_trace0(TRACE_GROUP_9, V2STREAM_START_CHANGE_ALL_COMS_TO_RUN_STATE);

    kal_retrieve_eg_events(rGVideoStream.eEvent, (VIDEO_STREAM_EVENT_RENDER_COMPLETE|VIDEO_STREAM_EVENT_RENDER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if((u4EventGroup&VIDEO_STREAM_EVENT_RENDER_ERROR) !=0)
        return VIDEO_RTP_ERROR;
    kal_retrieve_eg_events(rGVideoStream.eEvent, (VIDEO_STREAM_EVENT_CLOCK_COMPLETE|VIDEO_STREAM_EVENT_CLOCK_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if((u4EventGroup&VIDEO_STREAM_EVENT_CLOCK_ERROR) !=0)
        return VIDEO_RTP_ERROR;
    kal_retrieve_eg_events(rGVideoStream.eEvent, (VIDEO_STREAM_EVENT_SCHEDULER_COMPLETE|VIDEO_STREAM_EVENT_SCHEDULER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if((u4EventGroup&VIDEO_STREAM_EVENT_SCHEDULER_ERROR) !=0)
        return VIDEO_RTP_ERROR;
    kal_retrieve_eg_events(rGVideoStream.eEvent, (VIDEO_STREAM_EVENT_DECODER_COMPLETE|VIDEO_STREAM_EVENT_DECODER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if((u4EventGroup&VIDEO_STREAM_EVENT_DECODER_ERROR) !=0)
        return VIDEO_RTP_ERROR;
    rGVideoStream.eComponentState = VIDEO_STATE_RUN;
    drv_trace0(TRACE_GROUP_9, V2STREAM_START_CHANGE_ALL_COMS_TO_RUN_STATE_DONE);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    if(rGVideoStream.fgDecoderComplete == KAL_FALSE)
    {
        kal_retrieve_eg_events(rGVideoStream.eEvent, VIDEO_STREAM_EVENT_CLOCK_NOTIFY_START, KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    }

    if(rGVideoStream.eState == VIDEO_STREAM_STATE_PLAYING)
    {
        kal_bool fgEnableClock = KAL_TRUE;

        rGVideoStream.eState = VIDEO_STREAM_STATE_PLAYED;
        drv_trace0(TRACE_GROUP_9, V2STREAM_START_STATE_PLAYED);
        rGVideoStream.u4HdlrType = 0;
        //enable clock
        eError = prClockHdlr->pfnSetParameter(VIDEO_PARAM_CLOCK_ENABLE, &fgEnableClock);
        drv_trace0(TRACE_GROUP_8, V2STREAM_START_ENABLE_CLOCK);
        AOT(eError != VIDEO_ERROR_NONE);
    }

    return VIDEO_RTP_OK;
}

VIDEO_STREAM_STATUS_T VideoStreamStop(VIDEO_STREAM_HANDLER_T *prHdlr)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    VIDEO_COMPONENT_TYPE_T *prDecoderHdlr = NULL;
    VIDEO_COMPONENT_TYPE_T *prSchedulerHdlr = NULL;
    VIDEO_COMPONENT_TYPE_T *prClockHdlr = NULL;
    VIDEO_COMPONENT_TYPE_T *prRenderHdlr = NULL;
    kal_uint32 u4EventGroup;
    kal_bool fgEnableClock = KAL_FALSE;

    AOF(prHdlr);
    drv_trace0(TRACE_GROUP_8, V2STREAM_STOP);

    prDecoderHdlr = rGVideoStream.prDecoderHdlr;
    prSchedulerHdlr = rGVideoStream.prSchedulerHdlr;
    prClockHdlr = rGVideoStream.prClockHdlr;
    prRenderHdlr = rGVideoStream.prRenderHdlr;

    //disable clock
    eError = prClockHdlr->pfnSetParameter(VIDEO_PARAM_CLOCK_ENABLE, &fgEnableClock);
    AOT(eError != VIDEO_ERROR_NONE);
    drv_trace0(TRACE_GROUP_8, V2STREAM_STOP_DISABLE_CLOCK);

    //command all component to stop state
    #ifdef VIDEO_STREAM_UNIT_TEST
    eError = prFileReaderHdlr->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_STOP);
    AOT(eError != VIDEO_ERROR_NONE);
    #endif
    eError = prDecoderHdlr->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_STOP);
    AOT(eError != VIDEO_ERROR_NONE);
    eError = prSchedulerHdlr->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_STOP);
    AOT(eError != VIDEO_ERROR_NONE);
    eError = prClockHdlr->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_STOP);
    AOT(eError != VIDEO_ERROR_NONE);
    eError = prRenderHdlr->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_STOP);
    AOT(eError != VIDEO_ERROR_NONE);
    drv_trace0(TRACE_GROUP_9, V2STREAM_STOP_CHANGE_ALL_COMS_TO_STOP_STATE);

    #ifdef VIDEO_STREAM_UNIT_TEST
    kal_retrieve_eg_events(rGVideoStream.eEvent, (VIDEO_STREAM_EVENT_FILEREADER_COMPLETE|VIDEO_STREAM_EVENT_FILEREADER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if((u4EventGroup&VIDEO_STREAM_EVENT_FILEREADER_ERROR) !=0)
        return VIDEO_RTP_ERROR;
    #endif
    kal_retrieve_eg_events(rGVideoStream.eEvent, (VIDEO_STREAM_EVENT_DECODER_COMPLETE|VIDEO_STREAM_EVENT_DECODER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if((u4EventGroup&VIDEO_STREAM_EVENT_DECODER_ERROR) !=0)
        return VIDEO_RTP_ERROR;
    kal_retrieve_eg_events(rGVideoStream.eEvent, (VIDEO_STREAM_EVENT_SCHEDULER_COMPLETE|VIDEO_STREAM_EVENT_SCHEDULER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if((u4EventGroup&VIDEO_STREAM_EVENT_SCHEDULER_ERROR) !=0)
        return VIDEO_RTP_ERROR;
    kal_retrieve_eg_events(rGVideoStream.eEvent, (VIDEO_STREAM_EVENT_CLOCK_COMPLETE|VIDEO_STREAM_EVENT_CLOCK_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if((u4EventGroup&VIDEO_STREAM_EVENT_CLOCK_ERROR) !=0)
        return VIDEO_RTP_ERROR;
    kal_retrieve_eg_events(rGVideoStream.eEvent, (VIDEO_STREAM_EVENT_RENDER_COMPLETE|VIDEO_STREAM_EVENT_RENDER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if((u4EventGroup&VIDEO_STREAM_EVENT_RENDER_ERROR) !=0)
        return VIDEO_RTP_ERROR;
    rGVideoStream.eComponentState = VIDEO_STATE_STOP;
    drv_trace0(TRACE_GROUP_9, V2STREAM_STOP_CHANGE_ALL_COMS_TO_STOP_STATE_DONE);

    rGVideoStream.eState = VIDEO_STREAM_STATE_STOP;

    return VIDEO_RTP_OK;
}

VIDEO_STREAM_STATUS_T VideoStreamClose(VIDEO_STREAM_HANDLER_T *prHdlr)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    VIDEO_COMPONENT_TYPE_T *prDecoderHdlr = NULL;
    VIDEO_COMPONENT_TYPE_T *prSchedulerHdlr = NULL;
    VIDEO_COMPONENT_TYPE_T *prClockHdlr = NULL;
    VIDEO_COMPONENT_TYPE_T *prRenderHdlr = NULL;
    kal_uint32 u4EventGroup;

    AOF(prHdlr);
    AOT(rGVideoStream.eState == VIDEO_STREAM_STATE_PLAYING);
    AOT(rGVideoStream.eState == VIDEO_STREAM_STATE_CLOSE);
    drv_trace0(TRACE_GROUP_8, V2STREAM_CLOSE);

    prDecoderHdlr = rGVideoStream.prDecoderHdlr;
    prSchedulerHdlr = rGVideoStream.prSchedulerHdlr;
    prClockHdlr = rGVideoStream.prClockHdlr;
    prRenderHdlr = rGVideoStream.prRenderHdlr;

    if(rGVideoStream.fgChangeDecoderToRun)
    {
        eError = prDecoderHdlr->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_STOP);
        AOT(eError != VIDEO_ERROR_NONE);
        kal_retrieve_eg_events(rGVideoStream.eEvent, (VIDEO_STREAM_EVENT_DECODER_COMPLETE|VIDEO_STREAM_EVENT_DECODER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
        if((u4EventGroup&VIDEO_STREAM_EVENT_DECODER_ERROR) !=0)
            return VIDEO_RTP_ERROR;
    }

    //command all component to close state
    #ifdef VIDEO_STREAM_UNIT_TEST
    eError = prFileReaderHdlr->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_CLOSE);
    AOT(eError != VIDEO_ERROR_NONE);
    #endif
    eError = prDecoderHdlr->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_CLOSE);
    AOT(eError != VIDEO_ERROR_NONE);
    eError = prSchedulerHdlr->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_CLOSE);
    AOT(eError != VIDEO_ERROR_NONE);
    eError = prClockHdlr->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_CLOSE);
    AOT(eError != VIDEO_ERROR_NONE);
    eError = prRenderHdlr->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_CLOSE);
    AOT(eError != VIDEO_ERROR_NONE);
    drv_trace0(TRACE_GROUP_9, V2STREAM_STOP_CHANGE_ALL_COMS_TO_CLOSE_STATE);

    #ifdef VIDEO_STREAM_UNIT_TEST
    kal_retrieve_eg_events(rGVideoStream.eEvent, (VIDEO_STREAM_EVENT_FILEREADER_COMPLETE|VIDEO_STREAM_EVENT_FILEREADER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if((u4EventGroup&VIDEO_STREAM_EVENT_FILEREADER_ERROR) !=0)
        return VIDEO_RTP_ERROR;
    #endif
    kal_retrieve_eg_events(rGVideoStream.eEvent, (VIDEO_STREAM_EVENT_DECODER_COMPLETE|VIDEO_STREAM_EVENT_DECODER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if((u4EventGroup&VIDEO_STREAM_EVENT_DECODER_ERROR) !=0)
        return VIDEO_RTP_ERROR;
    kal_retrieve_eg_events(rGVideoStream.eEvent, (VIDEO_STREAM_EVENT_SCHEDULER_COMPLETE|VIDEO_STREAM_EVENT_SCHEDULER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if((u4EventGroup&VIDEO_STREAM_EVENT_SCHEDULER_ERROR) !=0)
        return VIDEO_RTP_ERROR;
    kal_retrieve_eg_events(rGVideoStream.eEvent, (VIDEO_STREAM_EVENT_CLOCK_COMPLETE|VIDEO_STREAM_EVENT_CLOCK_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if((u4EventGroup&VIDEO_STREAM_EVENT_CLOCK_ERROR) !=0)
        return VIDEO_RTP_ERROR;
    kal_retrieve_eg_events(rGVideoStream.eEvent, (VIDEO_STREAM_EVENT_RENDER_COMPLETE|VIDEO_STREAM_EVENT_RENDER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    if((u4EventGroup&VIDEO_STREAM_EVENT_RENDER_ERROR) !=0)
        return VIDEO_RTP_ERROR;
    rGVideoStream.eComponentState = VIDEO_STATE_CLOSE;
    drv_trace0(TRACE_GROUP_9, V2STREAM_STOP_CHANGE_ALL_COMS_TO_CLOSE_STATE_DONE);

    //release handle
    #ifdef VIDEO_STREAM_UNIT_TEST
    eError = ReleaseVideoFileReaderHandle(prFileReaderHdlr);
    AOT(eError != VIDEO_ERROR_NONE);
    #endif
    eError = ReleaseVideoDecoderHandle(rGVideoStream.prDecoderHdlr);
    AOT(eError != VIDEO_ERROR_NONE);
    eError = ReleaseVideoSchedulerHandle(rGVideoStream.prSchedulerHdlr);
    AOT(eError != VIDEO_ERROR_NONE);
    eError = ReleaseVideoClockHandle(rGVideoStream.prClockHdlr);
    AOT(eError != VIDEO_ERROR_NONE);
    //eError = ReleaseVideoRenderHandle(rGVideoStream.prRenderHdlr);
    eError = ReleaseVideoRendererHandle(rGVideoStream.prRenderHdlr);
    AOT(eError != VIDEO_ERROR_NONE);
    drv_trace0(TRACE_GROUP_8, V2STREAM_CLOSE_RELEASE_ALL_COMS);

    rGVideoStream.eState = VIDEO_STREAM_STATE_CLOSE;

    free_ctrl_buffer((void*)prHdlr);

    return VIDEO_RTP_OK;
}

VIDEO_STREAM_STATUS_T VideoStreamRenderConfig(VIDEO_STREAM_IMAGEDMA_CONFIG_T *prImageDMAConfig)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    MP4DEC_IMGPATH_STRUCT rHWDataInput;
    VIDEO_COMPONENT_TYPE_T *prRenderHdlr = NULL;
    MEDIA_STATUS_CODE eRenderRet;
    kal_uint32 u4EventGroup;

    #ifdef VIDEO_STREAM_UNIT_TEST
    VIDEO_COMPONENT_TYPE_T *prRenderHdlr = NULL;
    kal_bool fgEnable = KAL_TRUE;

    prRenderHdlr = rGVideoStream.prRenderHdlr;
    prRenderHdlr->pfnSetParameter(VIDEO_PARAM_ENABLE_DISPLAY, &fgEnable);
    #endif

    AOF(prImageDMAConfig);

    prRenderHdlr = rGVideoStream.prRenderHdlr;

    if(rGVideoStream.eComponentState == VIDEO_STATE_RUN)
    {
        eError = prRenderHdlr->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_STOP);
        AOT(eError != VIDEO_ERROR_NONE);
        kal_retrieve_eg_events(rGVideoStream.eEvent, (VIDEO_STREAM_EVENT_RENDER_COMPLETE|VIDEO_STREAM_EVENT_RENDER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
        AOT((u4EventGroup&VIDEO_STREAM_EVENT_RENDER_ERROR) !=0)
    }

    rHWDataInput.brightness_level = prImageDMAConfig->brightness_level;
    rHWDataInput.contrast_level = prImageDMAConfig->contrast_level;
    rHWDataInput.disp_height = prImageDMAConfig->disp_height;
    rHWDataInput.disp_width = prImageDMAConfig->disp_width;
    rHWDataInput.force_lcd_hw_trigger = prImageDMAConfig->force_lcd_hw_trigger;
    rHWDataInput.image_data_format = prImageDMAConfig->image_data_format;
    rHWDataInput.image_pitch_bytes = prImageDMAConfig->image_pitch_bytes;
    rHWDataInput.image_pitch_mode = prImageDMAConfig->image_pitch_mode;
    rHWDataInput.lcd_buf_addr = prImageDMAConfig->lcd_buf_addr;
    rHWDataInput.lcd_buf_addr_2 = prImageDMAConfig->lcd_buf_addr_2;
    rHWDataInput.lcd_data = prImageDMAConfig->lcd_data;
    rHWDataInput.rotate_angle = prImageDMAConfig->rotate_angle;
    rHWDataInput.tv_output = prImageDMAConfig->tv_output;
    rHWDataInput.tv_output_frame_buffer1_address = prImageDMAConfig->tv_output_frame_buffer1_address;
    rHWDataInput.tv_output_frame_buffer2_address = prImageDMAConfig->tv_output_frame_buffer2_address;
    rHWDataInput.tv_output_frame_buffer_size = prImageDMAConfig->tv_output_frame_buffer_size;
    rHWDataInput.video_display_offset_x = prImageDMAConfig->video_display_offset_x;
    rHWDataInput.video_display_offset_y = prImageDMAConfig->video_display_offset_y;

    eRenderRet = video_dec_set_video_renderer_handle(rGVideoStream.prRenderHdlr);
    if(eRenderRet != MEDIA_STATUS_OK)
        return VIDEO_RTP_ERROR;

    eRenderRet = video_dec_config_render(VIDEO_RENDER_MODE_HW, & rHWDataInput);
    if(eRenderRet != MEDIA_STATUS_OK)
        return VIDEO_RTP_ERROR;

    if(rGVideoStream.eComponentState == VIDEO_STATE_RUN)
    {
        eError = prRenderHdlr->pfnSendCommand(VIDEO_COMMAND_STATESET, VIDEO_STATE_RUN);
        AOT(eError != VIDEO_ERROR_NONE);
        kal_retrieve_eg_events(rGVideoStream.eEvent, (VIDEO_STREAM_EVENT_RENDER_COMPLETE|VIDEO_STREAM_EVENT_RENDER_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
        AOT((u4EventGroup&VIDEO_STREAM_EVENT_RENDER_ERROR) !=0)
    }

    return VIDEO_RTP_OK;
}

VIDEO_STREAM_STATUS_T VideoStreamImagePathOpen(VIDEO_STREAM_HANDLER_T *prHdlr, VIDEO_STREAM_IMAGEDMA_CONFIG_T *prImageDMAConfig)
{
    return VideoStreamRenderConfig(prImageDMAConfig);
}

VIDEO_STREAM_STATUS_T VideoStreamImagePathClose(VIDEO_STREAM_HANDLER_T *prHdlr)
{
    return VIDEO_RTP_OK;
}

VIDEO_STREAM_STATUS_T VideoStreamSwitchScreenVideoStop(VIDEO_STREAM_HANDLER_T *prHdlr)
{
    return VIDEO_RTP_OK;
}

VIDEO_STREAM_STATUS_T VideoStreamSwitchScreenVideoStart(VIDEO_STREAM_HANDLER_T *prHdlr, VIDEO_STREAM_IMAGEDMA_CONFIG_T *prImageDMAConfig)
{
    return VideoStreamRenderConfig(prImageDMAConfig);
}

VIDEO_STREAM_STATUS_T VideoStreamSetSwitchScreenVideoStop(VIDEO_STREAM_HANDLER_T *prHdlr, kal_bool fgValue)
{
    return VIDEO_RTP_OK;
}

// no use V1 functions
VIDEO_STREAM_STATUS_T VideoStreamNull(void)
{
    // This function should not be called
    ASSERT(0);
    return VIDEO_RTP_ERROR;
}

VIDEO_STREAM_STATUS_T VideoStreamPutPacket(VIDEO_STREAM_HANDLER_T *prHdlr, kal_uint8 *pu1Buff, kal_uint32 u4BuffSize)
{
    VideoStreamNull();
    return VIDEO_RTP_ERROR;
}

VIDEO_STREAM_STATUS_T VideoStreamGetBufferDuration(VIDEO_STREAM_HANDLER_T *prHdlr, kal_uint32 *pu4BuffDura)
{
    VideoStreamNull();
    return VIDEO_RTP_ERROR;
}

VIDEO_STREAM_STATUS_T VideoStreamGetBufferStatus(VIDEO_STREAM_HANDLER_T *prHdlr, kal_uint32 *pu4Percentage, kal_uint32 *pu4FreeSpace)
{
    VideoStreamNull();
    return VIDEO_RTP_ERROR;
}

VIDEO_STREAM_STATUS_T VideoStreamGetAvailableNumberOfFrame(VIDEO_STREAM_HANDLER_T *prHdlr, kal_uint32 *pu4FrameNo, kal_uint32 *pu4RequiredFrameNo)
{
    VideoStreamNull();
    return VIDEO_RTP_ERROR;
}

VIDEO_STREAM_STATUS_T VideoStreamCheckPkts(VIDEO_STREAM_HANDLER_T *prHdlr, kal_uint32 u4StartSeq, kal_uint32 u4Thre)
{
    VideoStreamNull();
    return VIDEO_RTP_ERROR;
}

VIDEO_STREAM_HANDLER_T* VideoStreamGetHandle(VIDEO_STREAM_SCENARIO_T eScenario)
{
    VIDEO_STREAM_HANDLER_T *prHdlr;

    #ifdef DRV_MP4_V1
    ASSERT(0);
    #endif

    prHdlr=get_ctrl_buffer(sizeof(VIDEO_STREAM_HANDLER_T));

    AOF(prHdlr);
    /*lint -e613 */
    prHdlr->scenario=eScenario;

    prHdlr->GetAvailableCodecs = VideoStreamGetAvailableCodecs;
    prHdlr->SetActiveCodec = VideoStreamSetActiveCodec;
    prHdlr->GetCapability = VideoStreamGetCapability;
    prHdlr->Config = VideoStreamConfig;
    prHdlr->GetImageResolution = VideoStreamGetImageResolution;
    //prHdlr->PutFrame = VideoStreamPutFrame;
    prHdlr->PutFrameV2 = VideoStreamPutFrame;
    prHdlr->GetPlayTime = VideoStreamGetPlayTime;
    prHdlr->Start = VideoStreamStart;
    prHdlr->Stop = VideoStreamStop;
    prHdlr->Close = VideoStreamClose;

    prHdlr->ImagePathOpen = VideoStreamImagePathOpen;
    prHdlr->ImagePathClose = VideoStreamImagePathClose;
    prHdlr->SwitchScreen_VideoStop = VideoStreamSwitchScreenVideoStop;
    prHdlr->SwitchScreen_VideoStart = VideoStreamSwitchScreenVideoStart;
    prHdlr->SetSwitchScreenVideoStop = VideoStreamSetSwitchScreenVideoStop;

    prHdlr->PutPacket = VideoStreamPutPacket;
    prHdlr->GetBufferDuration = VideoStreamGetBufferDuration;
    prHdlr->GetBufferStatus = VideoStreamGetBufferStatus;
    prHdlr->GetAvailableNumberOfFrames = VideoStreamGetAvailableNumberOfFrame;
    prHdlr->CheckPkts = VideoStreamCheckPkts;

    //prHdlr->is_SwitchScreen_VideoStop = KAL_FALSE;
    /*lint +e613 */

    return prHdlr;
}

#endif /* __VIDEO_ARCHI_V2__ */
