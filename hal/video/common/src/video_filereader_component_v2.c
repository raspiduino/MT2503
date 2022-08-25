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
 *   video_filereader_component_v2.c
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
 ****************************************************************************/
 #include "drv_comm.h"
#ifdef __VIDEO_ARCHI_V2__
#if defined(__MPEG4_DEC_SUPPORT__) || defined(__H264_DEC_SUPPORT__)
#include "kal_release.h"      /* Basic data type */
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"      /* Task creation */
#include "stacklib.h"         /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h"       /* Event scheduler */
#include "stack_timer.h"      /* Stack timer */

#include "med_status.h"
#include "mp4_parser.h"
#include "intrCtrl.h"
#include "video_types_v2.h"
#include "video_comm_v2.h"
#include "video_bitstream_buffer_management_v2.h"
#include "video_comm_component_v2.h"
#include "video_buffer_management_v2.h"
#include "video_filereader_component_v2.h"
#include "video_filereader_component_if_v2.h"
#include "video_decoder_demuxer_if_v2.h"
#include "vfile_struct.h"
#include "SST_sla.h"

static VIDEO_FILEREADER_STATE_T _rVideoFileReaderState;

static void _VideoFileReaderSendMessage(kal_uint32 nMessage, kal_uint32 nParam1, kal_uint32 nParam2);
static VIDEO_ERROR_TYPE_T _VideoFileReaderGetBasicInfo(VIDEO_FILEREADER_STATE_T *prVideoFileReaderState);
/*********************************************************
*
* Extern function
*
*********************************************************/


/*********************************************************
*
* Static function
*
*********************************************************/

static void _VideoFileReaderControlBlockInit(VIDEO_FILEREADER_STATE_T *prVideoFileReaderState)
{
    if (!prVideoFileReaderState)
    {
        ASSERT(0);
        return;
    }

    prVideoFileReaderState->prFileReaderFSAL = NULL;
    prVideoFileReaderState->prFileReaderMp4Parser = NULL;

    // Seek component
    prVideoFileReaderState->u8SeekTime = 0;
    prVideoFileReaderState->u4SeekFrame = 0;
    prVideoFileReaderState->u4SeekPrevIFrame = 0;

    // Allocate memory for struct VIDEO_FILEREADER_FILE_ADAPTATION_STRUCT_T
    //
    prVideoFileReaderState->prReadFileAdaptationInfo = (VIDEO_FILEREADER_FILE_ADAPTATION_STRUCT_T *)VideoGetExtBuffer(sizeof(VIDEO_FILEREADER_FILE_ADAPTATION_STRUCT_T));
    if (prVideoFileReaderState->prReadFileAdaptationInfo != NULL)
    {
        // File system adaptation
        kal_mem_set(prVideoFileReaderState->prReadFileAdaptationInfo, 0, sizeof(VIDEO_FILEREADER_FILE_ADAPTATION_STRUCT_T));
    }
    else
    {
        ASSERT(0);
    }

    // Control information
    prVideoFileReaderState->fgIsFatalError = KAL_FALSE;
    prVideoFileReaderState->fgClosingComp = KAL_FALSE;
    prVideoFileReaderState->fgIsDeliverParamSet = KAL_FALSE;
    prVideoFileReaderState->fgIsDeliverEOF = KAL_FALSE;
    prVideoFileReaderState->fgWaitForFreeAnyFrame = KAL_FALSE;
    prVideoFileReaderState->u4DeliverFrame = 0; // Indicate to the next deliver frame number
    prVideoFileReaderState->u4FreeFrame = 0; // Indicate to the next free frame number
    prVideoFileReaderState->fgEmptyThisBufferFail = KAL_FALSE;

    // Container information
    prVideoFileReaderState->u4VideoDecodeType = VIDEO_DECODER_UNKNOWN;
    prVideoFileReaderState->u8VideoDuration = 0; // Get media file total duration
    prVideoFileReaderState->u4VideoTimeScale = 0;
    prVideoFileReaderState->u4VideoTotalFrame = 0;

    // Video width & height
    prVideoFileReaderState->u4VideoWidth = 0;
    prVideoFileReaderState->u4VideoHeight = 0;

    // Parameter Set data
    // Allocate memory for struct VIDEO_FILEREADER_PARAM_SET_STRUCT_T
    //
    prVideoFileReaderState->prVideoParamSetData = (VIDEO_FILEREADER_PARAM_SET_STRUCT_T *)VideoGetExtBuffer(sizeof(VIDEO_FILEREADER_PARAM_SET_STRUCT_T));

    if (prVideoFileReaderState->prVideoParamSetData != NULL)
    {
        kal_mem_set(prVideoFileReaderState->prVideoParamSetData, 0, sizeof(VIDEO_FILEREADER_PARAM_SET_STRUCT_T));
    }
    else
    {
        ASSERT(0);
    }

    // NAL Control buffer
    // Allocate memory for struct VIDEO_FILEREADER_NAL_CTRL_BUFF_T
    //
    prVideoFileReaderState->prNALCTRLBuffer = (VIDEO_FILEREADER_NAL_CTRL_BUFF_T *)VideoGetExtBuffer(sizeof(VIDEO_FILEREADER_NAL_CTRL_BUFF_T));

    if (prVideoFileReaderState->prNALCTRLBuffer != NULL)
    {
        kal_mem_set(prVideoFileReaderState->prNALCTRLBuffer, 0, sizeof(VIDEO_FILEREADER_NAL_CTRL_BUFF_T));
    }
    else
    {
        ASSERT(0);
    }

    #ifdef __VIDEO_FILEREADER_PROFILE_ENABLE__
    // For Profile
    //
    kal_mem_set(&prVideoFileReaderState->rProfileData, 0, sizeof(VIDEO_FILEREADER_PROFILE_T));
    #endif /* __VIDEO_FILEREADER_PROFILE_ENABLE__ */
}

static void _VideoFileReaderControlBlockReset(VIDEO_FILEREADER_STATE_T *prVideoFileReaderState)
{
    VIDEO_BITSTREM_BUFF_STATUS_T *prBitstreamBuffStatus;
    VIDEO_FILEREADER_NAL_CTRL_BUFF_T *prNALCTRLBuffer;

    if (!prVideoFileReaderState)
    {
        ASSERT(0);
        return;
    }

    // Bitstream Buffer Control structure
    prBitstreamBuffStatus = prVideoFileReaderState->prBitstreamBuffStatus;

    prBitstreamBuffStatus->rBitstreamBuff.u4ReadOffset = 0;
    prBitstreamBuffStatus->rBitstreamBuff.u4WriteOffset = 0;
    prBitstreamBuffStatus->rBitstreamBuff.fgIsFull = KAL_FALSE;

    prBitstreamBuffStatus->rBuffHeader.u4ReadIndex = 0;
    prBitstreamBuffStatus->rBuffHeader.u4WriteIndex = 0;
    prBitstreamBuffStatus->rBuffHeader.u4DeliverIndex = 0;
    prBitstreamBuffStatus->rBuffHeader.fgIsFull = KAL_FALSE;

    // Control information

    // Reset fgIsDeliverParamSet
    // In order to re send parameter set
    //
    prVideoFileReaderState->fgIsFatalError = KAL_FALSE;
    prVideoFileReaderState->fgIsDeliverParamSet = KAL_FALSE;
    prVideoFileReaderState->fgIsDeliverEOF = KAL_FALSE;
    prVideoFileReaderState->fgWaitForFreeAnyFrame = KAL_FALSE;
    prVideoFileReaderState->u4DeliverFrame = 0;
    prVideoFileReaderState->u4FreeFrame = 0;
    prVideoFileReaderState->fgEmptyThisBufferFail = KAL_FALSE;

    // NAL control buffer
    prNALCTRLBuffer = prVideoFileReaderState->prNALCTRLBuffer;

    prNALCTRLBuffer->u4ReadIndex = 0;
    prNALCTRLBuffer->u4WriteIndex = 0;
    prNALCTRLBuffer->fgIsFull = KAL_FALSE;

}

static void _VideoFileReaderConfigFillBuffInfo(VIDEO_FILEREADER_FILE_ADAPTATION_STRUCT_T *prReadFileAdaptationInfo, kal_uint32 u4StartFrame, kal_uint32 u4EndFrame)
{
    if (!prReadFileAdaptationInfo)
    {
        ASSERT(0);
        return;
    }

    // Configure file system information to get bitstream data
    prReadFileAdaptationInfo->u4StartFrame = u4StartFrame;
    prReadFileAdaptationInfo->u4EndFrame = u4EndFrame;
    prReadFileAdaptationInfo->u4TargetFrame = u4EndFrame;
}

/* Obtain the decode type from media file
* @param None
* @return DECODE_TYPE_MPEG4 or DECODE_TYPE_H263
*/
static void _VideoFileReaderGetDecoderType(STMp4Parser *prSTMp4Parser, VIDEO_DECODER_TYPE_T *peType)
{
    MP4_Video_Type eVideoType;

    if (!prSTMp4Parser || !peType)
    {
        ASSERT(0);
        return;
    }

    // Get decoder type from MP4 parser
    //
    eVideoType = MP4_GetVideoType(prSTMp4Parser);

    switch (eVideoType)
    {
    case MP4_VIDEO_MPEG4:
        *peType = VIDEO_DECODER_MPEG4;
        break;
    case MP4_VIDEO_H263:
        *peType = VIDEO_DECODER_H263;
        break;
    case MP4_VIDEO_H264:
        *peType = VIDEO_DECODER_H264;
        break;
    default:
        *peType = VIDEO_DECODER_UNKNOWN;
        break;
    }
}

static VIDEO_ERROR_TYPE_T _VideoFileReaderGetFrameRate(VIDEO_FILEREADER_STATE_T *prVideoFileReaderState, kal_uint32 *pu4FPS)
{
    kal_uint32 u4AvgDuration;

    if (!prVideoFileReaderState || !pu4FPS)
    {
        ASSERT(0);
        return VIDEO_ERROR_INPUT_PARAM_ERROR;
    }

    if ((prVideoFileReaderState->u8VideoDuration == 0)||(prVideoFileReaderState->u4VideoTimeScale == 0))
    {
        return VIDEO_ERROR_INPUT_PARAM_ERROR;
    }
    else
    {
        if(prVideoFileReaderState->u4VideoTotalFrame == 0)
        {
            *pu4FPS = 0;
        }
        else
        {
            //*uFPS = uSampleCount / (duration_ms/1000);
            u4AvgDuration = prVideoFileReaderState->u8VideoDuration / prVideoFileReaderState->u4VideoTotalFrame;
            u4AvgDuration = VIDEO_MAX(u4AvgDuration, 1);
            *pu4FPS = VIDEO_FILEREADER_SCALE_UNIT / u4AvgDuration;
        }
    }

    return VIDEO_ERROR_NONE;
}
/* Objective:
*  Return the frame number according to a given parameter time
*/
static VIDEO_ERROR_TYPE_T _VideoFileReaderQueryFrameNum(STMp4Parser *prSTMp4Parser, kal_uint64 u8QueryFrameTime, kal_uint32 *pu4FrameNum)
{
    MP4_Parser_Status eStatus;
    kal_uint64 u8FrameTime;

    if (!prSTMp4Parser || !pu4FrameNum)
    {
        ASSERT(0);
        return VIDEO_ERROR_INPUT_PARAM_ERROR;
    }

    // In order to query file parser, we must transfer time base to video time base
    //
    u8FrameTime = TIMEBASE_MICROS_TO_VIDEO(u8QueryFrameTime);

    eStatus = MP4_GetSampleNumber(prSTMp4Parser, pu4FrameNum, u8FrameTime, MP4_TRACK_VIDEO);

    if (eStatus != MP4_PARSER_OK)
    {
        if (eStatus == MP4_PARSER_NO_SUCH_SAMPLE)
        {
            // Query time is larger than video duration
            // Set the query frame number to the last one
            //
            *pu4FrameNum = _rVideoFileReaderState.u4VideoTotalFrame - 1;
            return VIDEO_ERROR_NONE;
        }
        else
        {
            drv_trace1(TRACE_GROUP_8, VFILE_PARSER_ERROR, eStatus);
            return VIDEO_ERROR_PARSER_ERROR;
        }
    }
    else
    {
        if (*pu4FrameNum >= _rVideoFileReaderState.u4VideoTotalFrame)
        {
            *pu4FrameNum = _rVideoFileReaderState.u4VideoTotalFrame - 1;
        }
    }

    return VIDEO_ERROR_NONE;
}


/* Objective:
*  Return the previous I frame number according to a given parameter time
*/
static VIDEO_ERROR_TYPE_T _VideoFileReaderQueryPrevIFrameNum(STMp4Parser *prSTMp4Parser, kal_uint64 u8QueryFrameTime, kal_uint32 *pu4PrevIFrameNum)
{
    MP4_Parser_Status eStatus;
    VIDEO_ERROR_TYPE_T eError;
    kal_uint32 u4FrameNum;
    kal_uint64 u8FrameTime;

    if (!prSTMp4Parser || !pu4PrevIFrameNum)
    {
        ASSERT(0);
        return VIDEO_ERROR_INPUT_PARAM_ERROR;
    }

    if (u8QueryFrameTime > _rVideoFileReaderState.u8VideoDuration)
    {
        u8FrameTime = _rVideoFileReaderState.u8VideoDuration;
    }
    else
    {
        u8FrameTime = u8QueryFrameTime;
    }

    // To find out previous I frame
    //
    eError = _VideoFileReaderQueryFrameNum(prSTMp4Parser, u8FrameTime, &u4FrameNum);

    if (eError != VIDEO_ERROR_NONE)
    {
        drv_trace1(TRACE_GROUP_8, VFILE_PARSER_ERROR, eError);
        return VIDEO_ERROR_PARSER_ERROR;
    }

    eStatus = MP4_GetPrevSyncSampleNo(prSTMp4Parser, u4FrameNum, pu4PrevIFrameNum, MP4_TRACK_VIDEO);
    if (eStatus != MP4_PARSER_OK)
    {
        drv_trace1(TRACE_GROUP_8, VFILE_PARSER_ERROR, eStatus);
        return VIDEO_ERROR_PARSER_ERROR;
    }

    drv_trace1(TRACE_GROUP_8, VFILE_PREV_I_FRAME_NUM, *pu4PrevIFrameNum);

    return VIDEO_ERROR_NONE;
}


/* Objective:
*  Return the previous I frame time prior to current decode frame.
*/
static VIDEO_ERROR_TYPE_T _VideoFileReaderQueryPrevIFrameTime(STMp4Parser *prSTMp4Parser, kal_uint64 *pu8PrevIFrameTime)
{
    MP4_Parser_Status eStatus;
    VIDEO_ERROR_TYPE_T eError;
    kal_uint32 u4ReadIndexPrevIFrameNum;

    if (!prSTMp4Parser || !pu8PrevIFrameTime)
    {
        ASSERT(0);
        return VIDEO_ERROR_INPUT_PARAM_ERROR;
    }

    // To find out previous I frame.
    //
    eError = _VideoFileReaderQueryPrevIFrameNum(prSTMp4Parser,  *pu8PrevIFrameTime, &u4ReadIndexPrevIFrameNum);
    if (eError != VIDEO_ERROR_NONE)
    {
        drv_trace1(TRACE_GROUP_8, VFILE_PARSER_ERROR, eError);
        return eError;
    }

    eStatus = MP4_GetCompositionTime(prSTMp4Parser, u4ReadIndexPrevIFrameNum, pu8PrevIFrameTime, MP4_TRACK_VIDEO);
    if (eStatus != MP4_PARSER_OK)
    {
        drv_trace1(TRACE_GROUP_8, VFILE_PARSER_ERROR, eStatus);
        return VIDEO_ERROR_PARSER_ERROR;
    }
    *pu8PrevIFrameTime = TIMEBASE_VIDEO_TO_MICROS(*pu8PrevIFrameTime);

    drv_trace1(TRACE_GROUP_8, VFILE_PREV_I_FRAME_TIME, *pu8PrevIFrameTime);

    return VIDEO_ERROR_NONE;
}

static kal_bool _VideoFileReaderQueryNeedDeliverParamSet(void)
{
/*
    if (VIDEO_DECODER_H263 != _rVideoFileReaderState.u4VideoDecodeType)
    {
        if (_rVideoFileReaderState.fgIsDeliverParamSet == KAL_TRUE)
        {
            drv_trace1(TRACE_GROUP_8, VFILE_QUERY_NEED_DELIVER_PARAM, 0);
            return KAL_FALSE;
        }
        else
        {
            //drv_trace1(TRACE_GROUP_8, VFILE_QUERY_NEED_DELIVER_PARAM, 1);
            return KAL_TRUE;
        }
    }
    else
    {
        drv_trace1(TRACE_GROUP_8, VFILE_QUERY_NEED_DELIVER_PARAM, 0);
        return KAL_FALSE;
    }
*/
    if ((VIDEO_DECODER_H263 != _rVideoFileReaderState.u4VideoDecodeType) &&
        (_rVideoFileReaderState.fgIsDeliverParamSet == KAL_FALSE))
    {
        //drv_trace1(TRACE_GROUP_8, VFILE_QUERY_NEED_DELIVER_PARAM, 1);
        return KAL_TRUE;
    }
    else
    {
        drv_trace1(TRACE_GROUP_8, VFILE_QUERY_NEED_DELIVER_PARAM, 0);
        return KAL_FALSE;
    }
}

static kal_bool _VideoFileReaderQueryNeedFetch(kal_uint32 *pu4AvailableSize)
{
    VIDEO_FILEREADER_FILE_ADAPTATION_STRUCT_T *prReadFileAdaptationInfo;

    prReadFileAdaptationInfo = _rVideoFileReaderState.prReadFileAdaptationInfo;

    // If we fetch no frame last time, _rVideoFileReaderState.fgWaitForFreeAnyFrame will be set to KAL_TRUE
    // While any frame returned, we will start to check if we can fetch frame again
    //

    if (_rVideoFileReaderState.fgWaitForFreeAnyFrame == KAL_TRUE)
    {
        drv_trace1(TRACE_GROUP_8, VFILE_QUERY_NEED_FETCH_FRAME, 0);
        return KAL_FALSE;
    }
/*
    if (prReadFileAdaptationInfo->u4StartFrame > prReadFileAdaptationInfo->u4TargetFrame)
    {
        drv_trace1(TRACE_GROUP_8, VFILE_QUERY_NEED_FETCH_FRAME, 0);
        return KAL_FALSE;
    }
    else
    {
        if (KAL_TRUE == VideoBitstreamBuffCheckFillThreshold(_rVideoFileReaderState.prBitstreamBuffStatus, pu4AvailableSize))
        {
            // TRUE means the empty space is larger than threshold
            // We can start to fill bitstream buffer
            //
            //drv_trace1(TRACE_GROUP_8, VFILE_QUERY_NEED_FETCH_FRAME, 1);
            return KAL_TRUE;
        }
        else
        {
            drv_trace1(TRACE_GROUP_8, VFILE_QUERY_NEED_FETCH_FRAME, 0);
            return KAL_FALSE;
        }
    }
*/
    if ((prReadFileAdaptationInfo->u4StartFrame <= prReadFileAdaptationInfo->u4TargetFrame) &&
        (KAL_TRUE == VideoBitstreamBuffCheckFillThreshold(_rVideoFileReaderState.prBitstreamBuffStatus, pu4AvailableSize)))
    {
        // TRUE means the empty space is larger than threshold
        // We can start to fill bitstream buffer
        //
        //drv_trace1(TRACE_GROUP_8, VFILE_QUERY_NEED_FETCH_FRAME, 1);
        return KAL_TRUE;
    }
    else
    {
        drv_trace1(TRACE_GROUP_8, VFILE_QUERY_NEED_FETCH_FRAME, 0);
        return KAL_FALSE;
    }
}

static kal_bool _VideoFileReaderQueryNeedDeliver(void)
{
    VIDEO_FILEREADER_FILE_ADAPTATION_STRUCT_T *prReadFileAdaptationInfo;

    prReadFileAdaptationInfo = _rVideoFileReaderState.prReadFileAdaptationInfo;

    if ((_rVideoFileReaderState.u4DeliverFrame > _rVideoFileReaderState.u4VideoTotalFrame) ||
        (_rVideoFileReaderState.u4DeliverFrame > prReadFileAdaptationInfo->u4StartFrame) ||
        ((_rVideoFileReaderState.u4DeliverFrame == prReadFileAdaptationInfo->u4StartFrame)&&(prReadFileAdaptationInfo->u4StartFrame != _rVideoFileReaderState.u4VideoTotalFrame)) ||
        _rVideoFileReaderState.fgIsDeliverEOF)
    {
        drv_trace1(TRACE_GROUP_8, VFILE_QUERY_NEED_DELIVER_FRAME, 0);
        return KAL_FALSE;
    }
    else
    {
        if (KAL_TRUE == VideoBitstreamBuffQueryHeaderEmpty(_rVideoFileReaderState.prBitstreamBuffStatus))
        {
            if (!_rVideoFileReaderState.fgIsDeliverEOF)
            {
                return KAL_TRUE;
            }
            else
            {
                // TRUE means there is no data to deliver
                //
                drv_trace1(TRACE_GROUP_8, VFILE_QUERY_NEED_DELIVER_FRAME, 0);
                return KAL_FALSE;
            }
        }
        else
        {
            //drv_trace1(TRACE_GROUP_8, VFILE_QUERY_NEED_DELIVER_FRAME, 1);
            return KAL_TRUE;
        }
    }

}

static VIDEO_ERROR_TYPE_T _VideoFileReaderFillFrameSizeStruct(VIDEO_FILEREADER_STATE_T *prVideoFileReaderState, VIDEO_QUERY_FRAME_SIZE_TYPE_T *prFrameSizeStruct)
{
    VIDEO_BITSTREM_BUFF_STATUS_T *prBitstreamBuffStatus;

    if (!prVideoFileReaderState || !prFrameSizeStruct)
    {
        ASSERT(0);
        return VIDEO_ERROR_INPUT_PARAM_ERROR;
    }

    prBitstreamBuffStatus = prVideoFileReaderState->prBitstreamBuffStatus;

    if (VIDEO_DECODER_H264 == prVideoFileReaderState->u4VideoDecodeType)
    {
        prFrameSizeStruct->pu1ParamStream = (kal_uint8 *)prVideoFileReaderState->prVideoParamSetData->au4NALuOfParamSetAddr[0];
        prFrameSizeStruct->u4ParamLength = prVideoFileReaderState->prVideoParamSetData->au4NALuOfParamSetLength[0];
    }
    else if (VIDEO_DECODER_MPEG4 == prVideoFileReaderState->u4VideoDecodeType)
    {
        prFrameSizeStruct->pu1ParamStream = (kal_uint8 *)prVideoFileReaderState->prVideoParamSetData->au1ParamSetBuff;
        prFrameSizeStruct->u4ParamLength = prVideoFileReaderState->prVideoParamSetData->u4ParamSetTotalSize;
    }
    else if (VIDEO_DECODER_H263 == prVideoFileReaderState->u4VideoDecodeType)
    {
        prFrameSizeStruct->pu1ParamStream = (kal_uint8 *)prBitstreamBuffStatus->rBuffHeader.au4Address[0];
        prFrameSizeStruct->u4ParamLength = prBitstreamBuffStatus->rBuffHeader.au4Length[0];
    }
    else
    {
        ASSERT(0);
        return VIDEO_ERROR_QUERY_FRAME_SIZE;
    }

    return VIDEO_ERROR_NONE;
}

static void _VideoFileReaderFailHdlr(void)
{
    VIDEO_ERROR_TYPE_T eRet;
    VIDEO_CALLBACK_TYPE_T *prCallback;
    //VIDEO_WARNING(0);

    // Callback with error
    //
    prCallback = VideoCommGetCallback(&_rVideoFileReaderState.rCommState);
    eRet = prCallback->pfnEventHandler(VIDEO_EVENT_ERROR, VIDEO_COMMAND_NOTIFY, NULL, NULL);
    if(eRet!=VIDEO_ERROR_NONE)
    {
        ASSERT(0);
    }

    _rVideoFileReaderState.fgIsFatalError = KAL_TRUE;
}

/*********************************************************
*
* Common function
*
*********************************************************/

VIDEO_COMPONENT_TYPE_T* GetVideoFileReaderHandle(VIDEO_FILEREADER_TYPE_T nType)
{
    VIDEO_COMPONENT_TYPE_T *pVideoFileReaderComp = NULL;
    VIDEO_ERROR_TYPE_T eError;

    switch(nType)
    {
    case VIDEO_FILEREADER_MP4:
        pVideoFileReaderComp = &gVideoFileReaderComp;
        break;
    default:
        break;
    }

    if(pVideoFileReaderComp != NULL)
    {
        eError = pVideoFileReaderComp->pfnInit();
        if(eError!= VIDEO_ERROR_NONE)
        {
            pVideoFileReaderComp = NULL;
        }
    }

    drv_trace0(TRACE_GROUP_8, VFILE_GET_HANDLER);

    return pVideoFileReaderComp;
}

VIDEO_ERROR_TYPE_T ReleaseVideoFileReaderHandle(VIDEO_COMPONENT_TYPE_T *pHandle)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    if(pHandle == NULL)
    {
        eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
        ASSERT(0);
        return eError;
    }

    if (pHandle != &gVideoFileReaderComp)
    {
        eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
        ASSERT(0);
        return eError;
    }

    eError = pHandle->pfnDeInit();

    return eError;
}

static VIDEO_ERROR_TYPE_T _VideoFileReaderInit(void)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    kal_uint8 *pu1CurrAddr;
    // For port configuration
    VIDEO_PORT_CONFIG_T sOutputPort;
    VIDEO_COMPONENT_INIT_T sInitConfig;
    kal_uint32 u4Index;

    // Init control block
    //
    _VideoFileReaderControlBlockInit(&_rVideoFileReaderState);

    // Component buffer init
    //

    sOutputPort.ePortType = VIDEO_PORT_VIDEO_DATA;
    sOutputPort.fgSupplier = KAL_TRUE;
    sOutputPort.u4BuffSize = VIDEO_FILEREADER_BITSTREAM_BUFF_SIZE; // uint: byte

    sInitConfig.prInputPort1 = NULL;
    sInitConfig.prInputPort2 = NULL;
    sInitConfig.prOutputPort1 = &sOutputPort;
    sInitConfig.prOutputPort2 = NULL;
    sInitConfig.u4CmdQSize = VIDEO_FILEREADER_CMD_BUFFER_QUEUE_NUM;
    sInitConfig.u4InputBuffQSize= VIDEO_FILEREADER_INPUT_BUFFER_QUEUE_NUM;
    sInitConfig.u4OutputBuffQSize= VIDEO_FILEREADER_OUTPUT_BUFFER_QUEUE_NUM;

    eError = VideoCommInit(&_rVideoFileReaderState.rCommState, &sInitConfig, "VIDEO_FIELREADER");
    if(eError != VIDEO_ERROR_NONE)
    {
        drv_trace1(TRACE_GROUP_8, VFILE_INIT_ERROR, eError);
        return eError;
    }

    drv_trace1(TRACE_GROUP_8, VFILE_STATE_TRANSFER, VIDEO_STATE_INIT);

    // Init buffer resource
    pu1CurrAddr = VideoCommGetOutputBuff(&_rVideoFileReaderState.rCommState, VIDEO_PORT_VIDEO_DATA, &u4Index);

    // The bitstream buffer should be non-cacheable for H/W read/write effectively
    // Check this buffer in non-cacheable eara or not
    //
    if (VideoCommIsExtBufferCacheable((kal_uint32) pu1CurrAddr, sOutputPort.u4BuffSize) == KAL_TRUE)
    {
        pu1CurrAddr = (kal_uint8 *)VideoCommExtBufferCacheableSwitch((kal_uint32) pu1CurrAddr, sOutputPort.u4BuffSize, VIDEO_NON_CACHEABLE);
    }

    // Allocate memory for struct VIDEO_BITSTREM_BUFF_STATUS_T
    //
    _rVideoFileReaderState.prBitstreamBuffStatus = (VIDEO_BITSTREM_BUFF_STATUS_T *)VideoGetExtBuffer(sizeof(VIDEO_BITSTREM_BUFF_STATUS_T));

    VideoBitstreamBuffInit(_rVideoFileReaderState.prBitstreamBuffStatus, pu1CurrAddr, sOutputPort.u4BuffSize, VIDEO_BITSTREAM_BUFF_MAX_NUM);

    // Init other resource
    //
    VideoBitstreamBuffSetFillThreshold(_rVideoFileReaderState.prBitstreamBuffStatus, VIDEO_FILEREADER_BITSTREAM_BUFF_FILL_THRESHOLD);

    #ifdef __VIDEO_FILEREADER_PROFILE_ENABLE__
    _rVideoFileReaderState.rProfileData.u4FetchThreshold = VIDEO_FILEREADER_BITSTREAM_BUFF_FILL_THRESHOLD;
    #endif /*__VIDEO_FILEREADER_PROFILE_ENABLE__*/

    return eError;
}

static VIDEO_ERROR_TYPE_T _VideoFileReaderSendCommand(VIDEO_COMMAND_TYPE_T eCmd, kal_uint32 u4Param)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    kal_bool fgSendMsg = KAL_FALSE;
    kal_bool fgRet = KAL_FALSE;
    VIDEO_STATE_TYPE_T eState;

    eState = (VIDEO_STATE_TYPE_T)u4Param;

    if(eCmd == VIDEO_COMMAND_STATESET)
    {
        fgRet = VideoCommPushCommand(&_rVideoFileReaderState.rCommState, eCmd, u4Param);
        if(fgRet == KAL_FALSE)
        {
            // Error handling
            eError = VIDEO_ERROR_BUFF_FULL;
        }
        
        //bSendMsg = VideoCommSetProcessing(&_rVideoFileReaderState.rCommState);
        if (eState != VIDEO_STATE_CLOSE)
        {
            fgSendMsg = VideoCommSetProcessingNew(&_rVideoFileReaderState.rCommState, KAL_FALSE);
        }
        else
        {
            fgSendMsg = VideoCommSetProcessingNew(&_rVideoFileReaderState.rCommState, KAL_TRUE);
        }

        if(fgSendMsg == KAL_TRUE)
        {
            _VideoFileReaderSendMessage(MSG_ID_VFILE_TEST, 0, 0);
        }
    }
    else
    {
        ASSERT(0);
        eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
    }

    return eError;
}

static VIDEO_ERROR_TYPE_T _VideoFileReaderGetParameter(VIDEO_PARAM_TYPE_T eCmd, void *pu4Param)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    VIDEO_QUERY_FRAME_SIZE_TYPE_T *prFrameSizeStruct;

    if (!pu4Param)
    {
        ASSERT(0);
        return VIDEO_ERROR_INPUT_PARAM_ERROR;
    }

    switch(eCmd)
    {
    case VIDEO_PARAM_OUTPUT_BUFFER_PARAM:
        VideoCommGetOutputPortParam(&_rVideoFileReaderState.rCommState, pu4Param);
        break;

    case VIDEO_PARAM_INPUT_BUFFER_PARAM:
        VideoCommGetInputPortParam(&_rVideoFileReaderState.rCommState, pu4Param);
        break;

    case VIDEO_PARAM_CODEC_TYPE:
        // Before get decoder type, we need to get video basic information
        // Get basic information if we get both of hnadler
        //
        if (_rVideoFileReaderState.prFileReaderFSAL && _rVideoFileReaderState.prFileReaderMp4Parser)
        {
            eError = _VideoFileReaderGetBasicInfo(&_rVideoFileReaderState);
            if (eError != VIDEO_ERROR_NONE)
            {
                return eError;
            }
        }

        if (_rVideoFileReaderState.u4VideoDecodeType == VIDEO_DECODER_UNKNOWN)
        {
            _VideoFileReaderGetDecoderType(_rVideoFileReaderState.prFileReaderMp4Parser, &_rVideoFileReaderState.u4VideoDecodeType);
        }
        *(VIDEO_DECODER_TYPE_T *)pu4Param = _rVideoFileReaderState.u4VideoDecodeType;

        drv_trace1(TRACE_GROUP_8, VFILE_GET_DECODER_TYPE, _rVideoFileReaderState.u4VideoDecodeType);
        break;

    case VIDEO_PARAM_PREV_I_TIME:
        eError = _VideoFileReaderQueryPrevIFrameTime(_rVideoFileReaderState.prFileReaderMp4Parser, pu4Param);
        break;

    case VIDEO_PARAM_TRACK_DURATION:
        *(kal_uint64 *)pu4Param = _rVideoFileReaderState.u8VideoDuration;
        break;

    case VIDEO_PARAM_FRAME_WIDTH:

        *(kal_uint32*)pu4Param = _rVideoFileReaderState.u4VideoWidth;
        break;

    case VIDEO_PARAM_FRAME_HEIGHT:

        *(kal_uint32*)pu4Param = _rVideoFileReaderState.u4VideoHeight;
        break;

    case VIDEO_PARAM_FRAME_SIZE_STRUCT:
        prFrameSizeStruct = (VIDEO_QUERY_FRAME_SIZE_TYPE_T *)pu4Param;

        // To fill up the parameter set data address & length
        //
        eError = _VideoFileReaderFillFrameSizeStruct(&_rVideoFileReaderState, prFrameSizeStruct);
        break;
    case VIDEO_PARAM_CODEC_FRAMERATE:

        eError = _VideoFileReaderGetFrameRate(&_rVideoFileReaderState, pu4Param);
        break;
    default:
        ASSERT(0);
        break;
    }

    return eError;
}

static VIDEO_ERROR_TYPE_T _VideoFileReaderSetParameter(VIDEO_PARAM_TYPE_T eCmd, void *pu4Param)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    kal_uint64 u8SeekTime = 0;

    if (!pu4Param)
    {
        ASSERT(0);
        return VIDEO_ERROR_INPUT_PARAM_ERROR;
    }

    switch(eCmd)
    {
    case VIDEO_PARAM_OUTPUT_BUFFER_PARAM:
        VideoCommSetOutputPortParam(&_rVideoFileReaderState.rCommState, pu4Param);
        break;
    case VIDEO_PARAM_INPUT_BUFFER_PARAM:
        VideoCommSetInputPortParam(&_rVideoFileReaderState.rCommState, pu4Param);
        break;
    case VIDEO_PARAM_FILE_HANDLER:
        _rVideoFileReaderState.prFileReaderFSAL = (STFSAL *)pu4Param;

        break;
    case VIDEO_PARAM_PARSER_HANDLER:
        _rVideoFileReaderState.prFileReaderMp4Parser = (STMp4Parser *)pu4Param;

        break;
    case VIDEO_PARAM_TIME_POS:
        u8SeekTime = *((kal_uint64 *)(pu4Param));

        // Boundary check, if time is large than total duration
        // set it as total duration
        //
        if (u8SeekTime > _rVideoFileReaderState.u8VideoDuration)
        {
            u8SeekTime = _rVideoFileReaderState.u8VideoDuration;
        }

        _rVideoFileReaderState.u8SeekTime = u8SeekTime;

        eError = _VideoFileReaderQueryFrameNum(_rVideoFileReaderState.prFileReaderMp4Parser, u8SeekTime, &_rVideoFileReaderState.u4SeekFrame);
        if (eError != VIDEO_ERROR_NONE)
        {
            drv_trace1(TRACE_GROUP_8, VFILE_PARSER_ERROR, eError);
            return VIDEO_ERROR_PARSER_ERROR;
        }

        eError = _VideoFileReaderQueryPrevIFrameNum(_rVideoFileReaderState.prFileReaderMp4Parser, u8SeekTime, &_rVideoFileReaderState.u4SeekPrevIFrame);
        if (eError != VIDEO_ERROR_NONE)
        {
            drv_trace1(TRACE_GROUP_8, VFILE_PARSER_ERROR, eError);
            return VIDEO_ERROR_PARSER_ERROR;
        }

        drv_trace2(TRACE_GROUP_8, VFILE_SEEK_INFO, _rVideoFileReaderState.u4SeekFrame, u8SeekTime);
        break;

    case VIDEO_PARAM_FRAME_WIDTH:

        _rVideoFileReaderState.u4VideoWidth = *(kal_uint32*)pu4Param;
        break;

    case VIDEO_PARAM_FRAME_HEIGHT:

        _rVideoFileReaderState.u4VideoHeight = *(kal_uint32*)pu4Param;
        break;

    default:
        ASSERT(0);
        break;
    }

    return eError;
}

static VIDEO_ERROR_TYPE_T _VideoFileReaderUseBuffer(kal_uint8* pu1Buff, kal_uint32 u4Size)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    ASSERT(0);

    return eError;
}

static VIDEO_ERROR_TYPE_T _VideoFileReaderEmptyThisBuffer(VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    ASSERT(0);

    return eError;
}

static VIDEO_ERROR_TYPE_T _VideoFileReaderFillThisBuffer(VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    kal_uint32 u4PortIndex;
    kal_bool fgRet, bSendMsg = KAL_TRUE;
    VIDEO_COMPONENT_PARAM_T *pTunneledComponent;

    if (!prBuffHeader)
    {
        ASSERT(0);
        return VIDEO_ERROR_INPUT_PARAM_ERROR;
    }

    // If component in close state, it doesn't handle any buffer header process
    //
    if (_rVideoFileReaderState.fgClosingComp== KAL_TRUE)
    {
        eError = VIDEO_ERROR_BUFF_FULL;
        return eError;
    }

    // Check port index
    //
    u4PortIndex = VideoCommGetOutputPortIndex(&_rVideoFileReaderState.rCommState, VIDEO_PORT_VIDEO_DATA);
    if(u4PortIndex != prBuffHeader->u4OutputPort)
    {
        ASSERT(0);
    }


    pTunneledComponent = VideoCommGetOutputComp(&_rVideoFileReaderState.rCommState, u4PortIndex);
    if (!pTunneledComponent)
    {
        ASSERT(0);
    }
    else
    {
        if(pTunneledComponent->u4PortIndex != prBuffHeader->u4InputPort)
        {
            ASSERT(0);
        }
    }

    fgRet = VideoCommPushOutputBuff(&_rVideoFileReaderState.rCommState, prBuffHeader);
    if(fgRet == KAL_FALSE)
    {
        // should do error handling
        drv_trace0(TRACE_GROUP_10, VFILE_OUTPUT_BUFF_FULL);
        eError = VIDEO_ERROR_BUFF_FULL;
    }

    if (bSendMsg == KAL_TRUE)
    {
        //if(KAL_TRUE == VideoCommSetProcessing(&_rVideoFileReaderState.rCommState))
        if(KAL_TRUE == VideoCommSetProcessingNew(&_rVideoFileReaderState.rCommState, KAL_FALSE))
        {
            _VideoFileReaderSendMessage(MSG_ID_VFILE_TEST, 0, 0);
        }
    }

    return eError;
}

static VIDEO_ERROR_TYPE_T _VideoFileReaderSetCallbacks( VIDEO_CALLBACK_TYPE_T *prCallback)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    eError = VideoCommSetCallbacks(&_rVideoFileReaderState.rCommState, prCallback);

    return eError;
}

static VIDEO_ERROR_TYPE_T _VideoFileReaderDeInit(void)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    eError = VideoCommDeInit(&_rVideoFileReaderState.rCommState);

    return eError;
}

VIDEO_COMPONENT_TYPE_T gVideoFileReaderComp =
{
    _VideoFileReaderInit,
    _VideoFileReaderSendCommand,
    _VideoFileReaderGetParameter,
    _VideoFileReaderSetParameter,
    _VideoFileReaderUseBuffer,
    _VideoFileReaderEmptyThisBuffer,
    _VideoFileReaderFillThisBuffer,
    _VideoFileReaderSetCallbacks,
    _VideoFileReaderDeInit
};


//////////////////////////////////////////////////////////
//                Control functions
//////////////////////////////////////////////////////////

static void _VideoFileReaderSendMessage(kal_uint32 nMessage, kal_uint32 nParam1, kal_uint32 nParam2)
{
    video_file_reader_ind_struct *prMsg = NULL;
    ilm_struct *prIlm = NULL;

    if (kal_if_hisr())
    {
        ASSERT(0);
    }

    prMsg = (video_file_reader_ind_struct*) construct_local_para(sizeof(video_file_reader_ind_struct), TD_CTRL);
    prMsg->nParam1 = nParam1;
    prMsg->nParam2 = nParam2;

    //prIlm = allocate_ilm(MOD_MED);
    //prIlm->src_mod_id = MOD_MED;
    prIlm = allocate_ilm(stack_get_active_module_id());
    prIlm->src_mod_id = stack_get_active_module_id();
    prIlm->dest_mod_id = MOD_VFILE;
    prIlm->sap_id = MED_SAP;

    prIlm->msg_id = (msg_type) nMessage;
    prIlm->local_para_ptr = (local_para_struct*) prMsg;
    prIlm->peer_buff_ptr = NULL;

    msg_send_ext_queue(prIlm);
}

static MEDIA_STATUS_CODE _VideoFileReaderGetBitstreamData(STFSAL *prSTFSAL, kal_uint32 current_pos, kal_uint32 current_size, kal_uint32 current_buffer_addr,kal_uint32 u4MaxFileAccessSize)
{
    kal_uint32 read_size = 0;
    FSAL_Status eStatus;

    // Add profile information
    #ifdef __VIDEO_FILEREADER_PROFILE_ENABLE__
    kal_uint32 u4StartTime;
    kal_uint32 u4Duration;

    u4StartTime = video_get_current_time();

    #endif /* __VIDEO_FILEREADER_PROFILE_ENABLE__ */

    VIDEO_START_LOGGING("VFFF");

    // If more than 512 bytes, we will read the data rirectly to the current_buffer_addr.
    if (current_size > 512)
    {
        if(u4MaxFileAccessSize == 0)
        {
            u4MaxFileAccessSize = 0xFFFFFFFF; //no limit
        }

        eStatus = FSAL_Direct_Seek(prSTFSAL, current_pos);
        if (eStatus != FSAL_OK)
        {
            drv_trace4(TRACE_GROUP_8, VFILE_FSAL_ERROR_READ_BITSTREAM, eStatus, current_pos, current_size, current_buffer_addr);
            return FSAL_ERROR;
        }

        // Ttear down the read size to let Audio driver refill its buffer
        while (current_size > 0)
        {
            if(u4MaxFileAccessSize > current_size)
            {
                read_size = current_size;
            }
            else
            {
                read_size = u4MaxFileAccessSize;
            }

            eStatus = FSAL_Direct_Read(prSTFSAL, (kal_uint8 *)current_buffer_addr, read_size);
            if (eStatus != FSAL_OK)
            {
                drv_trace4(TRACE_GROUP_8, VFILE_FSAL_ERROR_READ_BITSTREAM, eStatus, current_pos, current_size, current_buffer_addr);
                return FSAL_ERROR;
            }

            current_size -= read_size;
            current_buffer_addr += read_size;
        }
    }
    // If the data is smaller than 512 bytes, we will use the FSAL Buffer
    else
    {
        eStatus = FSAL_Seek(prSTFSAL, current_pos);
        if (eStatus != FSAL_OK)
        {
            drv_trace4(TRACE_GROUP_8, VFILE_FSAL_ERROR_READ_BITSTREAM, eStatus, current_pos, current_size, current_buffer_addr);
            return FSAL_ERROR;
        }

        eStatus = FSAL_Read(prSTFSAL, (kal_uint8 *)current_buffer_addr,current_size);
        if (eStatus != FSAL_OK)
        {
            drv_trace4(TRACE_GROUP_8, VFILE_FSAL_ERROR_READ_BITSTREAM, eStatus, current_pos, current_size, current_buffer_addr);
            return FSAL_ERROR;
        }
    }

    VIDEO_STOP_LOGGING("VFFF");

    // Add profile information
    #ifdef __VIDEO_FILEREADER_PROFILE_ENABLE__
    u4Duration = video_get_duration_ms(u4StartTime);
    drv_trace2(TRACE_GROUP_10, VFILE_PROFILE_FETCH_TIME, u4Duration, read_size);

    _rVideoFileReaderState.rProfileData.u4AccumulatedCount++;
    _rVideoFileReaderState.rProfileData.u4TotalFetchSize += read_size;
    _rVideoFileReaderState.rProfileData.u4AvgFetchSize = _rVideoFileReaderState.rProfileData.u4TotalFetchSize / _rVideoFileReaderState.rProfileData.u4AccumulatedCount;

    _rVideoFileReaderState.rProfileData.u4TotalFetchTime += u4Duration;
    _rVideoFileReaderState.rProfileData.u4AvgFetchTime = _rVideoFileReaderState.rProfileData.u4TotalFetchTime / _rVideoFileReaderState.rProfileData.u4AccumulatedCount;

    #endif /* __VIDEO_FILEREADER_PROFILE_ENABLE__ */

    return MEDIA_STATUS_OK;
}

static MEDIA_STATUS_CODE _VideoFileReaderGetSampleData(STMp4Parser *prSTMp4Parser, VIDEO_FILEREADER_FILE_ADAPTATION_STRUCT_T *pFileInfo)
{
    kal_uint32 current_pos = 0;
    kal_uint32 current_size = 0;
    kal_uint32 current_buffer_addr = 0;
    kal_uint32 nSum = 0;
    kal_uint32 index;
    kal_uint32 u4ResultCount;
    kal_uint32 nResultCountCheck;
    kal_uint32 nStartRead;
    MEDIA_STATUS_CODE eResult;
    MP4_Parser_Status eStatus;

    pFileInfo->u4ResultCount = 0;
    pFileInfo->u4ResultSize = 0;

    // Decide how much frame to fetch
    //
    u4ResultCount =  pFileInfo->u4EndFrame - pFileInfo->u4StartFrame + 1;
    nStartRead = 0;

    // Assign frame number
    for (index = 0; index < u4ResultCount; index++)
    {
        pFileInfo->pu4FrameNum[index] = pFileInfo->u4StartFrame + index;
    }

    // Get each sample size
    // Assume that we can fetch the total frame
    // First to scan the maximum index that we can fetch
    // Frame number start from 0, end at nResultFram - 1
    // Ex: u4StartFrame:0 , u4EndFrame:4 , u4ResultCount:5
    // We will fetch frame number: 0, 1, 2, 3, 4 (exclude 5)

    for (index = 0; index < u4ResultCount; index++)
    {
        eStatus = MP4_GetSampleSize( prSTMp4Parser,
                                    (pFileInfo->u4StartFrame + index),
                                    &pFileInfo->pu4FrameLength[index],
                                    MP4_TRACK_VIDEO);

        // Record down the result frame.
        //
        if (eStatus != MP4_PARSER_OK)
        {
            u4ResultCount = index;
            break;
        }
    }

    // Get sample time
    //
    nResultCountCheck = u4ResultCount;
    eStatus = MP4_GetCompositionTime_Array(prSTMp4Parser,
                                pFileInfo->u4StartFrame,
                                pFileInfo->pu4FrameTime,
                                &u4ResultCount,
                                MP4_TRACK_VIDEO);

    if (eStatus != MP4_PARSER_OK)
    {
        if((nResultCountCheck == u4ResultCount) && (nResultCountCheck!=0))
        {
            /* since it is error, result frame no must be different from original */
            //EXT_ASSERT(0, nResultCountCheck, 0, 0);
            return MP4_PARSER_ERROR;
        }
    }

    /* get sample offset */
    nResultCountCheck = u4ResultCount;
    eStatus = MP4_GetSampleOffset_Array(prSTMp4Parser,
                                pFileInfo->u4StartFrame,
                                pFileInfo->au4TempFileOffset,
                                &u4ResultCount,
                                MP4_TRACK_VIDEO);

    if (eStatus != MP4_PARSER_OK)
    {
        if((nResultCountCheck==u4ResultCount) && (nResultCountCheck!=0))
        {
            /* since it is error, result frame no must be different from original */
            //EXT_ASSERT(0, nResultCountCheck, 0, 0);
            return MP4_PARSER_ERROR;
        }
    }

    // Count start address
    // if empty space from write offset to the end of line buffer is not enough for a first frame length
    // Reassign start address to the begin of line buffer
    //
    if (pFileInfo->u4ReadOffset <= pFileInfo->u4WriteOffset)
    {
        if (pFileInfo->u4EndOfBuffAddr - pFileInfo->pu4FrameAddr[0] < pFileInfo->pu4FrameLength[0])
        {
            pFileInfo->u4MaxFetchSize -= (pFileInfo->u4EndOfBuffAddr - pFileInfo->pu4FrameAddr[0]);
            pFileInfo->pu4FrameAddr[0] = pFileInfo->u4BeginOfBuffAddr;

            // Update write offset to begin of buffer line
            // The pFileInfo->u4WriteOffset will be used after return this function
            // To update write offset of bitstream
            //
            pFileInfo->u4WriteOffset = 0;
        }
        else
        {
            // Fix up maximum fetch size
            //
            pFileInfo->u4MaxFetchSize = (pFileInfo->u4EndOfBuffAddr - pFileInfo->u4BeginOfBuffAddr) - pFileInfo->u4WriteOffset;
        }
    }

    /* set the last one offset as 0 */
    pFileInfo->au4TempFileOffset[u4ResultCount] = 0;

    /* calculate smaple sizes and read from file to buffer */
    current_pos = pFileInfo->au4TempFileOffset[0];
    current_size = 0;
    current_buffer_addr = pFileInfo->pu4FrameAddr[0];
    nSum = 0;

    for (index = 0; index < u4ResultCount; index++)
    {
        /*Search the max frame data to be prepared to buffer*/
        if ((index + 1) < u4ResultCount)
        {
            pFileInfo->pu4FrameAddr[index + 1] = pFileInfo->pu4FrameAddr[index] + pFileInfo->pu4FrameLength[index];
        }

        nSum += pFileInfo->pu4FrameLength[index];

        if (nSum > pFileInfo->u4MaxFetchSize)
        {
            if(index > 0)
            {
                /* reach frame buffer size limit */
                #ifdef __VIDEO_FILEREADER_PROFILE_ENABLE__
                _rVideoFileReaderState.rProfileData.u4ContinuousReachMaxCount++;

                if (current_size < _rVideoFileReaderState.rProfileData.u4FetchThreshold)
                {
                    _rVideoFileReaderState.rProfileData.u4FetchCountUnderThreshold++;
                }
                #endif /*__VIDEO_FILEREADER_PROFILE_ENABLE__*/

                eResult = _VideoFileReaderGetBitstreamData(pFileInfo->prSTFSAL, current_pos, current_size, current_buffer_addr,pFileInfo->u4MaxFileAccessSize);

                if (eResult != MEDIA_STATUS_OK)
                {
                    //ASSERT(0);
                    return eResult;
                }

                index--;
                pFileInfo->u4ResultSize += current_size;
                pFileInfo->u4ResultCount += (index - nStartRead + 1);
                nStartRead = index + 1;
            }
            break;
        }

        current_size += pFileInfo->pu4FrameLength[index];
        if ((current_pos + current_size) != pFileInfo->au4TempFileOffset[index + 1])
        {
            /* not continous data */
            #ifdef __VIDEO_FILEREADER_PROFILE_ENABLE__
            _rVideoFileReaderState.rProfileData.u4NotContinuousCount++;
            #endif /*__VIDEO_FILEREADER_PROFILE_ENABLE__*/

            eResult = _VideoFileReaderGetBitstreamData(pFileInfo->prSTFSAL, current_pos, current_size, current_buffer_addr,pFileInfo->u4MaxFileAccessSize);

            if (eResult != MEDIA_STATUS_OK)
            {
                //ASSERT(0);
                return eResult;
            }

            pFileInfo->u4ResultSize += current_size;
            pFileInfo->u4ResultCount += (index - nStartRead + 1);
            nStartRead = index + 1;
            current_buffer_addr = pFileInfo->pu4FrameAddr[index+1];
            current_pos = pFileInfo->au4TempFileOffset[index + 1];
            current_size = 0;
        }
    }

    return  MEDIA_STATUS_OK;
}

static VIDEO_ERROR_TYPE_T _VideoFileReaderFillBitstreamBuffHdlr(kal_uint32 u4MaxFetchSize)
{
    kal_bool fgIsFull;
    kal_uint32 nNextFetchCount, nRealFetchCount;
    kal_uint32 u4WriteOffset;
    kal_uint32 u4ReadOffset;
    kal_uint32 u4TotalSize;
    kal_uint32 u4ReadIndex;
    kal_uint32 u4WriteIndex;
    kal_uint32 u4MaxHeaderCount;
    kal_uint32 u4TargetFrame;
    kal_uint32 u4StartFrame;
    kal_uint32 u4EndFrame;
    MEDIA_STATUS_CODE eResult;
    VIDEO_FILEREADER_FILE_ADAPTATION_STRUCT_T *prReadFileAdaptationInfo;
    VIDEO_BITSTREM_BUFF_STATUS_T *prBitstreamBuffStatus;

    if (_rVideoFileReaderState.prBitstreamBuffStatus != NULL)
    {
        prBitstreamBuffStatus = _rVideoFileReaderState.prBitstreamBuffStatus;
    }
    else
    {
        ASSERT(0);
        return VIDEO_ERROR_NONE;
    }

    if (_rVideoFileReaderState.prReadFileAdaptationInfo != NULL)
    {
        prReadFileAdaptationInfo = _rVideoFileReaderState.prReadFileAdaptationInfo;
    }
    else
    {
        ASSERT(0);
        return VIDEO_ERROR_NONE;
    }

    u4WriteOffset = prBitstreamBuffStatus->rBitstreamBuff.u4WriteOffset;
    u4ReadOffset = prBitstreamBuffStatus->rBitstreamBuff.u4ReadOffset;
    u4TotalSize = prBitstreamBuffStatus->rBitstreamBuff.u4TotalSize;
    u4ReadIndex = prBitstreamBuffStatus->rBuffHeader.u4ReadIndex;
    u4WriteIndex = prBitstreamBuffStatus->rBuffHeader.u4WriteIndex;
    u4MaxHeaderCount = prBitstreamBuffStatus->rBuffHeader.u4MaxHeaderCount;
    u4TargetFrame = prReadFileAdaptationInfo->u4TargetFrame;
    u4StartFrame = prReadFileAdaptationInfo->u4StartFrame;
    u4EndFrame = prReadFileAdaptationInfo->u4EndFrame;

    // Check if fetching action reaches the target frame
    //
    if (u4StartFrame > u4TargetFrame)
        return VIDEO_ERROR_NONE;

    fgIsFull = VideoBitstreamBuffQueryHeaderFull(prBitstreamBuffStatus);
    if (fgIsFull == KAL_TRUE)
    {
        nNextFetchCount = 0;

        // This means that bitstream buffer is available but header arrary is full
        //ASSERT(0);
        return VIDEO_ERROR_NONE;
    }
    // The following check will guarantee that fetch result won't exceed the access boundary
    //
    else if (u4WriteIndex >= u4ReadIndex)
    {
        nNextFetchCount = u4MaxHeaderCount - u4WriteIndex;
    }
    else /* u4WriteIndex < u4ReadIndex*/
    {
        nNextFetchCount = u4ReadIndex - u4WriteIndex;
    }

    // Be careful to control fetch count. If the fetch count is larger than arrary size
    // the memory will be ocrrupted.
    //
    if (nNextFetchCount <= u4MaxHeaderCount)
    {
        // Update u4EndFrame
        u4EndFrame = u4StartFrame + nNextFetchCount - 1;
        prReadFileAdaptationInfo->u4EndFrame = u4EndFrame;

        prReadFileAdaptationInfo->u4MaxFetchSize  = u4MaxFetchSize;

        // Assign next write address
        prBitstreamBuffStatus->rBuffHeader.au4Address[u4WriteIndex] = (kal_uint32)prBitstreamBuffStatus->rBitstreamBuff.pu1BuffStartAddr + u4WriteOffset;

        // Assign an empty space address of buffer array
        //
        prReadFileAdaptationInfo->pu4FrameNum = &prBitstreamBuffStatus->rBuffHeader.au4FrameNum[u4WriteIndex];
        prReadFileAdaptationInfo->pu4FrameAddr = &prBitstreamBuffStatus->rBuffHeader.au4Address[u4WriteIndex];
        prReadFileAdaptationInfo->pu4FrameLength= &prBitstreamBuffStatus->rBuffHeader.au4Length[u4WriteIndex];
        prReadFileAdaptationInfo->pu4FrameTime = &prBitstreamBuffStatus->rBuffHeader.au8Timestamp[u4WriteIndex];
        prReadFileAdaptationInfo->u4ReadOffset = prBitstreamBuffStatus->rBitstreamBuff.u4ReadOffset;
        prReadFileAdaptationInfo->u4WriteOffset = prBitstreamBuffStatus->rBitstreamBuff.u4WriteOffset;
    }
    else
    {
        ASSERT(0);
    }

    // To fetch bitstream data into buffer, include header information
    // address, length, timescale for each frame
    eResult = _VideoFileReaderGetSampleData(_rVideoFileReaderState.prFileReaderMp4Parser, prReadFileAdaptationInfo);
    if (eResult != MEDIA_STATUS_OK)
    {
        _VideoFileReaderFailHdlr();
        return VIDEO_ERROR_FSAL_ERROR;
    }

    // Check fetch result
    // If fetch result is equal to start frame:
    // 1. we don't fetch any frame
    //
    nRealFetchCount = prReadFileAdaptationInfo->u4ResultCount;
    if (nRealFetchCount == 0)
    {
        if ((u4WriteOffset == 0) && (u4ReadOffset == 0))
        {
            // In ths case, we don't have enough buffer for first frame.
            //
            ASSERT(0);
        }

        // In this case, we don't fetch any frame.
        // We will set _rVideoFileReaderState.fgWaitForFreeAnyFrame up
        // When there are any frame free, we will try fetch again.
        //
        _rVideoFileReaderState.fgWaitForFreeAnyFrame = KAL_TRUE;
    }
    // Check u4ResultCount boundary
    else if (nRealFetchCount > nNextFetchCount)
    {
        ASSERT(0);
    }
    else // nRealFetchCount <= nNextFetchCount
    {
        // 2. Update bitstream header arrary point
        //
        // Assign next u4StartFrame and update u4WriteIndex
        // u4StartFrame + nRealFetchCount <= buffer boundary should be guaranteed.
        //
        prReadFileAdaptationInfo->u4StartFrame += nRealFetchCount;
        prBitstreamBuffStatus->rBuffHeader.u4WriteIndex = (prBitstreamBuffStatus->rBuffHeader.u4WriteIndex + nRealFetchCount) % u4MaxHeaderCount;

        // 3. Update bitstream offset
        //
        // TODO: check more
        // If u4MaxFetchSize is updated, that means
        // the empty space from write offset to the end of line buffer is not enough for a first frame length
        // Reassign start address to the begin of line buffer
        //
        if (prReadFileAdaptationInfo->u4ResultSize <= u4MaxFetchSize)
        {
            if (prReadFileAdaptationInfo->u4WriteOffset + prReadFileAdaptationInfo->u4ResultSize > u4TotalSize)
            {
                ASSERT(0);
            }
            else
            {
                prBitstreamBuffStatus->rBitstreamBuff.u4WriteOffset = (prReadFileAdaptationInfo->u4WriteOffset + prReadFileAdaptationInfo->u4ResultSize) % u4TotalSize;
            }
        }
        else
        {
            ASSERT(0);
        }

        // Check buffer full condition
        //
        if (prBitstreamBuffStatus->rBuffHeader.u4ReadIndex == prBitstreamBuffStatus->rBuffHeader.u4WriteIndex)
        {
            prBitstreamBuffStatus->rBuffHeader.fgIsFull = KAL_TRUE;
        }
        else
        {
            prBitstreamBuffStatus->rBuffHeader.fgIsFull = KAL_FALSE;
        }

        if (prBitstreamBuffStatus->rBitstreamBuff.u4ReadOffset == prBitstreamBuffStatus->rBitstreamBuff.u4WriteOffset)
        {
            prBitstreamBuffStatus->rBitstreamBuff.fgIsFull = KAL_TRUE;
        }
        else
        {
            prBitstreamBuffStatus->rBitstreamBuff.fgIsFull = KAL_FALSE;
        }
    }
    return VIDEO_ERROR_NONE;
}

static void _VideoFileReaderGetAVCConfigData(STMp4Parser *prSTMp4Parser, STFSAL *prSTFSAL, kal_uint32 *pu4NALuSizeInfo)
{
    FSAL_Status eStatus;
    kal_uint32 u4ConfigPosition;
    kal_uint32 u4ConfigSize;
    kal_uint8 au1ConfigData[VIDEO_FILEREADER_AVC_CONFIG_LENGTH];

    /* Get AVC configuration information */
    u4ConfigPosition = MP4_Video_GetAVCConfigOffset(prSTMp4Parser);
    u4ConfigSize = MP4_Video_GetAVCConfigSize(prSTMp4Parser);
    if(u4ConfigSize != VIDEO_FILEREADER_AVC_CONFIG_LENGTH)
    {
        ASSERT(0);
    }

    /* Read AVC configuration from file system*/
    eStatus = FSAL_Seek(prSTFSAL, u4ConfigPosition);
    if (eStatus != FSAL_OK)
    {
        drv_trace1(TRACE_GROUP_8, VFILE_FSAL_ERROR, eStatus);
        _VideoFileReaderFailHdlr();
        return;
    }

    eStatus = FSAL_Read(prSTFSAL, au1ConfigData, u4ConfigSize);
    if (eStatus != FSAL_OK)
    {
        drv_trace1(TRACE_GROUP_8, VFILE_FSAL_ERROR, eStatus);
        _VideoFileReaderFailHdlr();
        return;
    }

    *pu4NALuSizeInfo = (au1ConfigData[VIDEO_FILEREADER_AVC_CONFIG_LENGTH - 1] & 0x3) + 1;

    if((*pu4NALuSizeInfo!=4) && (*pu4NALuSizeInfo!=2) && (*pu4NALuSizeInfo!=1))
    {
        ASSERT(0);
    }
}

static void VideoFileReaderGetParamSetNALUnits(VIDEO_FILEREADER_PARAM_SET_STRUCT_T *prVideoParamSetData)
{
    kal_uint32 u4NumOfSPS;
    kal_uint32 u4SPSLength;
    kal_uint32 u4NumOfPPS;
    kal_uint32 u4PPSLength;
    kal_uint32 u4DataIndex, u4ParamSetIndex, u4Sum;
    kal_uint32 i;
    kal_uint32 *au4NALuOfParamSetAddr;
    kal_uint32 *au4NALuOfParamSetLength;
    kal_uint8 *pu4ParamSetDataBuff;

    if (!prVideoParamSetData)
    {
        ASSERT(0);
        return;
    }

    // The following code is to obtain sps, pps information {address, length} of each NALu
    //
    au4NALuOfParamSetAddr = prVideoParamSetData->au4NALuOfParamSetAddr;
    au4NALuOfParamSetLength = prVideoParamSetData->au4NALuOfParamSetLength;
    pu4ParamSetDataBuff = prVideoParamSetData->au1ParamSetBuff;

    ASSERT(au4NALuOfParamSetAddr);
    ASSERT(au4NALuOfParamSetLength);

    u4DataIndex = 0;
    u4ParamSetIndex = 0;
    u4Sum = 0;
    // Pack parameter set
    // Remove length information
    //

    // SPS stream
    //
    u4NumOfSPS = (kal_uint32)(pu4ParamSetDataBuff[u4DataIndex++] & 0x1F);

    for (i = 0; i < u4NumOfSPS; i++)
    {
        u4SPSLength = (kal_uint32)(((pu4ParamSetDataBuff[u4DataIndex] & 0xFF) << 8) | (pu4ParamSetDataBuff[u4DataIndex + 1] & 0xFF));

        // Make sure total length is less than real buffer length
        // or it will occur memory curruption
        u4Sum += u4SPSLength;
        if (u4Sum > prVideoParamSetData->u4ParamSetTotalSize)
        {
            ASSERT(0);
        }
        u4DataIndex += 2;

        // Fill up parameter set information arrary
        //
        au4NALuOfParamSetAddr[u4ParamSetIndex] = (kal_uint32)&pu4ParamSetDataBuff[u4DataIndex];
        au4NALuOfParamSetLength[u4ParamSetIndex] = (kal_uint32)u4SPSLength;

        // update index
        //
        u4DataIndex += u4SPSLength;
        u4ParamSetIndex++;
    }

    // PPS stream
    //
    u4NumOfPPS = (kal_uint32)(pu4ParamSetDataBuff[u4DataIndex++] & 0xFF);

    for (i = 0; i < u4NumOfPPS; i++)
    {
        u4PPSLength = (kal_uint32)(((pu4ParamSetDataBuff[u4DataIndex] & 0xFF) << 8) | (pu4ParamSetDataBuff[u4DataIndex + 1] & 0xFF));

        // Make sure total length is less than real buffer length
        // or it will occur memory curruption
        u4Sum += u4PPSLength;
        if (u4Sum > prVideoParamSetData->u4ParamSetTotalSize)
        {
            ASSERT(0);
        }
        u4DataIndex += 2;

        // Fill up parameter set information arrary
        //
        au4NALuOfParamSetAddr[u4ParamSetIndex] = (kal_uint32)&pu4ParamSetDataBuff[u4DataIndex];
        au4NALuOfParamSetLength[u4ParamSetIndex] = (kal_uint32)u4PPSLength;

        // update index
        //
        u4DataIndex += u4PPSLength;
        u4ParamSetIndex++;
    }

    // Check boundary
    //
    if (u4DataIndex > prVideoParamSetData->u4ParamSetTotalSize)
    {
        ASSERT(0);
    }

    // parameter array index should be less than VIDEO_FILEREADER_MAX_PARAMSET_NUM
    //
    if (u4ParamSetIndex > VIDEO_FILEREADER_MAX_PARAMSET_NUM)
    {
        ASSERT(0);
    }
    else
    {
        // Assign number of Parameter Set NALu here
        //
        prVideoParamSetData->u4NumOfNALuParamSet = u4ParamSetIndex;
    }
}

static void _VideoFileReaderGetParameterSetData(STMp4Parser *prSTMp4Parser, STFSAL *prSTFSAL, VIDEO_DECODER_TYPE_T u4VideoDecodeType, VIDEO_FILEREADER_PARAM_SET_STRUCT_T *prVideoParamSetData)
{
    FSAL_Status eStatus;
    kal_uint32 u4ParamPosition;

    if (!prSTMp4Parser || !prSTFSAL || !prVideoParamSetData)
    {
        ASSERT(0);
        return;
    }

    // Get parameter set information
    // MPEG-4 or H.264
    //
    if (VIDEO_DECODER_H264 == u4VideoDecodeType)
    {
        // Get AVC information, size info of NAL
        _VideoFileReaderGetAVCConfigData(
            prSTMp4Parser,
            prSTFSAL,
            &prVideoParamSetData->u4NALuSizeInfo
        );

        u4ParamPosition = MP4_Video_GetParameterSetOffset(prSTMp4Parser, 0);
        prVideoParamSetData->u4ParamSetTotalSize= MP4_Video_GetParameterSetSize(prSTMp4Parser, 0);

        if (prVideoParamSetData->u4ParamSetTotalSize > VIDEO_FILEREADER_PARAMSET_LENGTH)
        {
            EXT_ASSERT(0, prVideoParamSetData->u4ParamSetTotalSize, VIDEO_FILEREADER_PARAMSET_LENGTH, 0);
        }

        // Read parameter sets from file system
        //
        eStatus = FSAL_Seek(prSTFSAL, u4ParamPosition);
        if (eStatus != FSAL_OK)
        {
            drv_trace1(TRACE_GROUP_8, VFILE_FSAL_ERROR, eStatus);
            _VideoFileReaderFailHdlr();
            return;
        }

        eStatus = FSAL_Read(prSTFSAL, prVideoParamSetData->au1ParamSetBuff, prVideoParamSetData->u4ParamSetTotalSize);
        if (eStatus != FSAL_OK)
        {
            drv_trace1(TRACE_GROUP_8, VFILE_FSAL_ERROR, eStatus);
            _VideoFileReaderFailHdlr();
            return;
        }

        // Obtain Parameter set NAL units
        //
        VideoFileReaderGetParamSetNALUnits(prVideoParamSetData);

    }
    else if (VIDEO_DECODER_MPEG4 == u4VideoDecodeType)
    {
        u4ParamPosition = MP4_Video_GetVOSOffset(prSTMp4Parser);
        prVideoParamSetData->u4ParamSetTotalSize = MP4_Video_GetVOSSize(prSTMp4Parser);

        if (prVideoParamSetData->u4ParamSetTotalSize > VIDEO_FILEREADER_PARAMSET_LENGTH)
        {
            ASSERT(0);
        }

        // Read parameter sets from file system
        //
        eStatus = FSAL_Seek(prSTFSAL, u4ParamPosition);
        if (eStatus != FSAL_OK)
        {
            drv_trace1(TRACE_GROUP_8, VFILE_FSAL_ERROR, eStatus);
            _VideoFileReaderFailHdlr();
            return;
        }

        eStatus = FSAL_Read(prSTFSAL, prVideoParamSetData->au1ParamSetBuff, prVideoParamSetData->u4ParamSetTotalSize);
        if (eStatus != FSAL_OK)
        {
            drv_trace1(TRACE_GROUP_8, VFILE_FSAL_ERROR, eStatus);
            _VideoFileReaderFailHdlr();
            return;
        }
    }
    else
    {
        ASSERT(0);
    }

}

static void VideoFileReaderPackH264PrivateData(VIDEO_FILEREADER_PARAM_SET_STRUCT_T *prVideoParamSetData)
{
    kal_uint32 u4ParamSetIndex;
    kal_uint32 u4NumOfNALuParamSet;
    kal_uint32 u4TotalLength;
    kal_uint32 i;
    H264_DECODER_INPUT_PARAM_T *prPrivateData;
    H264_DECODER_PAYLOAD_INFO_T *parNALCTRLBuff;

    if (!prVideoParamSetData)
    {
        ASSERT(0);
        return;
    }

    u4NumOfNALuParamSet = prVideoParamSetData->u4NumOfNALuParamSet;
    prPrivateData = &prVideoParamSetData->rPrivateData;
    parNALCTRLBuff = prVideoParamSetData->arNALCTRLBuff;

    // Pack DECODER_INPUT_PARAM_T
    //
    prPrivateData->u4PayloadNumber = u4NumOfNALuParamSet;
    prPrivateData->pu1PayloadAddress = parNALCTRLBuff;

    u4ParamSetIndex = 0;
    u4TotalLength = 0;
    for (i = 0;i < u4NumOfNALuParamSet;i++)
    {
        parNALCTRLBuff->u4Address = prVideoParamSetData->au4NALuOfParamSetAddr[u4ParamSetIndex];
        parNALCTRLBuff->u4Length = prVideoParamSetData->au4NALuOfParamSetLength[u4ParamSetIndex];

        // Update read index and accumulate total length
        //
        u4TotalLength += parNALCTRLBuff->u4Length;
        u4ParamSetIndex++;
        parNALCTRLBuff++;
    }

    prVideoParamSetData->u4TotalNALSize = u4TotalLength;

}

static kal_bool _VideoFileReaderGetNextParamSetUint(VIDEO_BUFFERHEADER_TYPE_T *psOutBufferHeader)
{
    VIDEO_FILEREADER_PARAM_SET_STRUCT_T *prVideoParamSetData;

    if (!psOutBufferHeader)
    {
        ASSERT(0);
        return KAL_FALSE;
    }

    prVideoParamSetData = _rVideoFileReaderState.prVideoParamSetData;

    if (VIDEO_DECODER_H264 == _rVideoFileReaderState.u4VideoDecodeType)
    {
        // Pack private data for H.264
        //
        VideoFileReaderPackH264PrivateData(prVideoParamSetData);
        psOutBufferHeader->pPrivateData = (void *)&prVideoParamSetData->rPrivateData;

        psOutBufferHeader->pu1Buffer = (kal_uint8 *)prVideoParamSetData->au4NALuOfParamSetAddr[0];
        psOutBufferHeader->u4BuffSize = prVideoParamSetData->u4TotalNALSize;
        psOutBufferHeader->u4FillSize = prVideoParamSetData->u4TotalNALSize;
    }
    else if (VIDEO_DECODER_MPEG4 == _rVideoFileReaderState.u4VideoDecodeType)
    {
        psOutBufferHeader->pu1Buffer = prVideoParamSetData->au1ParamSetBuff;
        psOutBufferHeader->u4BuffSize = prVideoParamSetData->u4ParamSetTotalSize;
        psOutBufferHeader->u4FillSize = prVideoParamSetData->u4ParamSetTotalSize;
        psOutBufferHeader->pPrivateData = NULL;
    }
    else
    {
        ASSERT(0);
    }

    return KAL_TRUE;
}

static kal_bool _VideoFileReaderGetNextDeliverUint(VIDEO_BUFFERHEADER_TYPE_T *psOutBufferHeader)
{
    kal_uint32 u4ReadIndex;
    kal_uint32 u4WriteIndex;
    kal_uint32 u4DeliverIndex;
    kal_uint32 u4MaxHeaderCount;
    kal_uint32 u4PadLoadAddr;  // this address will remove length information
    kal_uint32 u4PadLoadLength;  // this address will remove length information
    kal_uint32 u4FrameStartAddr;  // this address will remove length information
    kal_uint32 u4FrameLength;  // this address will remove length information
    kal_uint8 *pu1PadNALuStartAddr;
    kal_uint32 u4PadNALuLength = 0;
    kal_uint32 u4CurrentLength;
    kal_uint32 u4PayLoadNALCount = 0;
    kal_uint32 u4NALCTRLBuffWriteIndex;
    H264_DECODER_PAYLOAD_INFO_T *prCurrentNALPayload = NULL;
    H264_DECODER_INPUT_PARAM_T *pPrivateData = NULL;
    kal_bool fgIsFull;
    VIDEO_BITSTREM_BUFF_STATUS_T *prBitstreamBuff;
    VIDEO_FILEREADER_FILE_ADAPTATION_STRUCT_T *prReadFileAdaptationInfo;
    VIDEO_BITSTREM_BUFF_STATUS_T *prBitstreamBuffStatus;
    VIDEO_FILEREADER_PARAM_SET_STRUCT_T *prVideoParamSetData;
    VIDEO_FILEREADER_NAL_CTRL_BUFF_T *prNALCTRLBuffer;

    if (!psOutBufferHeader)
    {
        ASSERT(0);
        return KAL_FALSE;
    }

    prBitstreamBuffStatus = _rVideoFileReaderState.prBitstreamBuffStatus;
    prReadFileAdaptationInfo = _rVideoFileReaderState.prReadFileAdaptationInfo;
    prVideoParamSetData = _rVideoFileReaderState.prVideoParamSetData;
    prNALCTRLBuffer = _rVideoFileReaderState.prNALCTRLBuffer;

    prBitstreamBuff = prBitstreamBuffStatus;
    u4ReadIndex = prBitstreamBuffStatus->rBuffHeader.u4ReadIndex;
    u4WriteIndex = prBitstreamBuffStatus->rBuffHeader.u4WriteIndex;
    u4DeliverIndex = prBitstreamBuffStatus->rBuffHeader.u4DeliverIndex;
    u4MaxHeaderCount = prBitstreamBuffStatus->rBuffHeader.u4MaxHeaderCount;
    fgIsFull = prBitstreamBuff->rBuffHeader.fgIsFull;

    if ((_rVideoFileReaderState.u4DeliverFrame > _rVideoFileReaderState.u4VideoTotalFrame) ||
        (_rVideoFileReaderState.u4DeliverFrame > prReadFileAdaptationInfo->u4StartFrame) ||
        ((_rVideoFileReaderState.u4DeliverFrame == prReadFileAdaptationInfo->u4StartFrame) && (prReadFileAdaptationInfo->u4StartFrame != _rVideoFileReaderState.u4VideoTotalFrame)) ||
        (_rVideoFileReaderState.fgIsDeliverEOF == KAL_TRUE)/* If we have deliver EOF frame, just return. */)
    {
        return KAL_FALSE;
    }

    // Generate Dummy Frame for EOF
    //
    if ((_rVideoFileReaderState.u4DeliverFrame == _rVideoFileReaderState.u4VideoTotalFrame))
    {
        // pack a frame information
        //
        psOutBufferHeader->pu1Buffer    = 0;
        psOutBufferHeader->u4BuffSize   = 0;
        psOutBufferHeader->u4FillSize   = 0;
        psOutBufferHeader->u4Offset     = 0;
        psOutBufferHeader->u8TimeStamp  = _rVideoFileReaderState.u8VideoDuration;
        psOutBufferHeader->eFlags = VIDEO_BUFFERFLAG_EOF;
        return KAL_TRUE;
    }

    if (u4DeliverIndex > u4MaxHeaderCount)
    {
        ASSERT(0);
    }

    if (u4ReadIndex < u4WriteIndex)
    {
        if ((u4DeliverIndex < u4ReadIndex) || (u4DeliverIndex >= u4WriteIndex))
        {
            return KAL_FALSE;
        }
    }
    else if (u4ReadIndex > u4WriteIndex)
    {
        if ((u4DeliverIndex < u4ReadIndex) && (u4DeliverIndex >= u4WriteIndex))
        {
            return KAL_FALSE;
        }

    }
    // Check if buffer is empty
    //
    else if ((u4ReadIndex == u4WriteIndex) && !fgIsFull)
    {
        return KAL_FALSE;
    }

    // buffer is not empty
    // Configure deliver buffer header information
    //
    if (!prBitstreamBuff->rBuffHeader.au4Address[u4DeliverIndex])
    {
        ASSERT(0);
    }

    // This is only for H.264
    // Skip length information
    // 4 or 2 or 1 bytes
    //
    if (VIDEO_DECODER_H264 == _rVideoFileReaderState.u4VideoDecodeType)
    {
        // If control buffer is full
        // just return
        //
        if (prNALCTRLBuffer->fgIsFull == KAL_TRUE)
        {
            return KAL_FALSE;
        }

        // Get basic information
        // We should pack frame information here
        // Pack NALu start address and NALu length
        //
        u4NALCTRLBuffWriteIndex = prNALCTRLBuffer->u4WriteIndex;
        u4FrameStartAddr = prBitstreamBuff->rBuffHeader.au4Address[u4DeliverIndex];
        u4FrameLength = prBitstreamBuff->rBuffHeader.au4Length[u4DeliverIndex];
        psOutBufferHeader->pPrivateData = (void *)(&prNALCTRLBuffer->arPrivateData[u4DeliverIndex]);

        u4CurrentLength = 0;
        u4PayLoadNALCount = 0;
        while (u4CurrentLength < u4FrameLength)
        {
            u4PayLoadNALCount++;
            pu1PadNALuStartAddr = (kal_uint8 *)(u4FrameStartAddr + u4CurrentLength);
            prCurrentNALPayload = &prNALCTRLBuffer->arNALCTRLBuff[u4NALCTRLBuffWriteIndex];

            if (AVC_NALU_LENGTH_4 == prVideoParamSetData->u4NALuSizeInfo)
            {
                u4PadNALuLength = (((pu1PadNALuStartAddr[0] & 0xFF) << 24) |
                                   ((pu1PadNALuStartAddr[1] & 0xFF) << 16) |
                                   ((pu1PadNALuStartAddr[2] & 0xFF) << 8) |
                                   (pu1PadNALuStartAddr[3] & 0xFF));

            }
            else if (AVC_NALU_LENGTH_2 == prVideoParamSetData->u4NALuSizeInfo)
            {
                u4PadNALuLength = (((pu1PadNALuStartAddr[0] & 0xFF) << 8) |
                                   (pu1PadNALuStartAddr[1] & 0xFF));
            }
            else if (AVC_NALU_LENGTH_1 == prVideoParamSetData->u4NALuSizeInfo)
            {
                u4PadNALuLength = (pu1PadNALuStartAddr[0] & 0xFF);
            }
            else
            {
                ASSERT(0);
            }

            // Check boundary
            //
            if ((kal_uint32)pu1PadNALuStartAddr < u4FrameStartAddr)
            {
                ASSERT(0);
            }

            // In case of this, the container information may be not equal to bitstream
            //
            if (u4PadNALuLength > u4FrameLength)
            {
                //ASSERT(0);
                drv_trace0(TRACE_GROUP_8, VFILE_CONTIANER_INFO_ERROR);
                u4PadNALuLength = u4FrameLength - u4CurrentLength;
            }

            // Assign NAL information
            //
            prCurrentNALPayload->u4Address = (kal_uint32)pu1PadNALuStartAddr + prVideoParamSetData->u4NALuSizeInfo;
            prCurrentNALPayload->u4Length = u4PadNALuLength;

            // For test
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif

            // Update control variable
            //
            u4CurrentLength += u4PadNALuLength + prVideoParamSetData->u4NALuSizeInfo;

            // Compute next write index
            // If it is larger than VIDEO_FILEREADER_NAL_CTRL_BUFF_NUM
            // We need to break this fill up action
            // This is because NAL unit control buffer should be contineous memory space
            //
            u4NALCTRLBuffWriteIndex = (u4NALCTRLBuffWriteIndex + 1) % VIDEO_FILEREADER_NAL_CTRL_BUFF_NUM;

            // If write index == 0, this means wrap around to the head of buffer
            // In this case, we should break loop due to keep memory space is continuous.
            //
            if (u4NALCTRLBuffWriteIndex == 0)
            {
                break;
            }

            // Check full case
            //
            if (u4NALCTRLBuffWriteIndex == prNALCTRLBuffer->u4ReadIndex)
            {
                // If u4WriteIndex reaches u4ReadIndex, it means that we have no empty buffer
                // We don't set fgIsFull = KAL_TRUE becasue we will discard this pack action
                //
                break;
            }
            
            // Check  sample size > file size ?
            //
            if (prCurrentNALPayload->u4Length > _rVideoFileReaderState.prFileReaderFSAL->uFileSize)
            {
                u4CurrentLength = u4FrameLength;
                prCurrentNALPayload->u4Length = 0;
                break;
            }
        }

        if (u4FrameLength == u4CurrentLength)
        {
            // It's normal case, buffer is enough
            // Pack private data first
            //
            pPrivateData = (H264_DECODER_INPUT_PARAM_T *)psOutBufferHeader->pPrivateData;
            pPrivateData->u4PayloadNumber = u4PayLoadNALCount;
            pPrivateData->pu1PayloadAddress = &prNALCTRLBuffer->arNALCTRLBuff[prNALCTRLBuffer->u4WriteIndex];

            //kal_prompt_trace(MOD_MED, "[Debug561] %08x", *pPrivateData->pu1PayloadAddress->u4Address);
        }
        else if (u4FrameLength < u4CurrentLength)
        {
            // Something wrong here...
            /*
            drv_trace0(TRACE_GROUP_8, VFILE_CONTIANER_INFO_ERROR);
            return KAL_FALSE;
            */

            // In the implementation, just let is pass the pack action
            // Maybe we can bring this error detection notification to the tunneled component.
            // TODO

            pPrivateData = (H264_DECODER_INPUT_PARAM_T *)psOutBufferHeader->pPrivateData;
            pPrivateData->u4PayloadNumber = u4PayLoadNALCount;
            pPrivateData->pu1PayloadAddress = &prNALCTRLBuffer->arNALCTRLBuff[prNALCTRLBuffer->u4WriteIndex];

        }
        else
        {
            // u4FrameLength > u4CurrentLength
            // In this case, the pack action is breaked due to no empty buffer or reach buffer end
            // Roll back Write Index or jump to the begin of buffer
            //
            if (u4NALCTRLBuffWriteIndex == 0)
            {
                if (prNALCTRLBuffer->u4WriteIndex == 0)
                {
                    // If goes here, this means that VIDEO_FILEREADER_NAL_CTRL_BUFF_NUM is too small.
                    // Need to add buffer number
                    //
                    //ASSERT(0);
                    //return KAL_FALSE;
                }
                else
                {
                    prNALCTRLBuffer->u4WriteIndex = 0;
                }
            }

            // The following code is used to prevent file reader sleep deeply ...(never wake up)
            //
            //if(KAL_TRUE == VideoCommSetProcessing(&_rVideoFileReaderState.rCommState))
            if(KAL_TRUE == VideoCommSetProcessingNew(&_rVideoFileReaderState.rCommState, KAL_FALSE))
            {
                _VideoFileReaderSendMessage(MSG_ID_VFILE_TEST, 0, 0);
            }

            return KAL_FALSE;
        }

    }
    else
    {
        // For MPEG-4 & H.263
        //
        psOutBufferHeader->pPrivateData = NULL;
    }

    // All codec
    //
    u4PadLoadAddr = prBitstreamBuff->rBuffHeader.au4Address[u4DeliverIndex];
    u4PadLoadLength = prBitstreamBuff->rBuffHeader.au4Length[u4DeliverIndex];

    // Always assign first frame's timestamp to 0
    //
    if ((prBitstreamBuff->rBuffHeader.au4FrameNum[u4DeliverIndex] == 0) && (prBitstreamBuff->rBuffHeader.au8Timestamp[u4DeliverIndex] > 0))
    {
        prBitstreamBuff->rBuffHeader.au8Timestamp[u4DeliverIndex] = 0;
    }

    // pack a frame information
    //
    psOutBufferHeader->pu1Buffer = (kal_uint8 *)u4PadLoadAddr;
    psOutBufferHeader->u4BuffSize   = u4PadLoadLength;
    psOutBufferHeader->u4FillSize   = u4PadLoadLength;
    psOutBufferHeader->u4Offset     = 0;
    psOutBufferHeader->u8TimeStamp  = TIMEBASE_VIDEO_TO_MICROS(prBitstreamBuff->rBuffHeader.au8Timestamp[u4DeliverIndex]);

    // TODO: check detail flag usage
    // TODO: check display order != decode order case

    // Assume that display order == decode order
    // Assign buffer flag
    if (prBitstreamBuff->rBuffHeader.au4FrameNum[u4DeliverIndex] < _rVideoFileReaderState.u4SeekFrame)
    {
        psOutBufferHeader->eFlags = VIDEO_BUFFERFLAG_DECODEONLY;
    }
    else if (prBitstreamBuff->rBuffHeader.au4FrameNum[u4DeliverIndex] == _rVideoFileReaderState.u4SeekFrame)
    {
        psOutBufferHeader->eFlags = VIDEO_BUFFERFLAG_STARTTIME;
    }
    else
    {
        psOutBufferHeader->eFlags = VIDEO_BUFFERFLAG_NONE;
    }

    return KAL_TRUE;
}

static void _VideoFileReaderDeliverParamSetHdlr(void)
{
    VIDEO_BUFFERHEADER_TYPE_T sOutBufferHeader;
    VIDEO_COMPONENT_PARAM_T *pTunneledComponent;
    VIDEO_ERROR_TYPE_T nErrorType;
    kal_bool fgRet = KAL_TRUE;

    if ((VIDEO_DECODER_H264 != _rVideoFileReaderState.u4VideoDecodeType) && (VIDEO_DECODER_MPEG4 != _rVideoFileReaderState.u4VideoDecodeType))
    {
        ASSERT(0);
    }

    // Fill up deliver buffer structure
    // Common information
    //
    sOutBufferHeader.u4OutputPort = VideoCommGetOutputPortIndex(&_rVideoFileReaderState.rCommState, VIDEO_PORT_VIDEO_DATA);
    pTunneledComponent = VideoCommGetOutputComp(&_rVideoFileReaderState.rCommState, sOutBufferHeader.u4OutputPort);
    if (!pTunneledComponent)
    {
        ASSERT(0);
        return;
    }
    else
    {
        sOutBufferHeader.u4InputPort = pTunneledComponent->u4PortIndex;
    }
    sOutBufferHeader.u4Offset = 0;
    sOutBufferHeader.u8TimeStamp = 0;
    sOutBufferHeader.eFlags = VIDEO_BUFFERFLAG_PARAMETERSET;

    // Get next parameter set and call tunneled component's pfnEmptyThisBuffer()
    // while loop will break if pfnEmptyThisBuffer() return error
    while (fgRet)
    {
        fgRet = _VideoFileReaderGetNextParamSetUint(&sOutBufferHeader);
        if (fgRet)
        {
            nErrorType = pTunneledComponent->prComp->pfnEmptyThisBuffer(&sOutBufferHeader);
#if 0  //Rita test
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            if (nErrorType != VIDEO_ERROR_NONE)
            {
                drv_trace2(TRACE_GROUP_8, VFILE_EMPTY_THIS_BUFFER_FAILED,
                    0,
                    (kal_uint32)sOutBufferHeader.pu1Buffer
                );
                break;
            }
            else
            {
                // We have send a deliver unit to next tunneled component successfully.
                //
                _rVideoFileReaderState.fgIsDeliverParamSet = KAL_TRUE;
                drv_trace4(TRACE_GROUP_9, VFILE_EMPTY_THIS_BUFFER_OK,
                    (kal_uint32)sOutBufferHeader.pu1Buffer,
                    sOutBufferHeader.u4BuffSize,
                    sOutBufferHeader.eFlags,
                    sOutBufferHeader.u8TimeStamp
                );
                break;
            }
        }
    }

}

static void _VideoFileReaderDeliverDecodeUnitHdlr(void)
{
    kal_bool fgRet = KAL_TRUE;
    VIDEO_BUFFERHEADER_TYPE_T sOutBufferHeader;
    VIDEO_ERROR_TYPE_T nErrorType;
    VIDEO_COMPONENT_PARAM_T *pTunneledComponent;
    kal_uint32 u4DeliverIndex;
    kal_uint32 u4NALCTRLBuffWriteIndex;
    H264_DECODER_INPUT_PARAM_T *prPrivateData;
    VIDEO_BITSTREM_BUFF_STATUS_T *prBitstreamBuffStatus;
    kal_uint32 u4MaxHeaderCount;
    VIDEO_FILEREADER_NAL_CTRL_BUFF_T *prNALCTRLBuffer;

    prBitstreamBuffStatus = _rVideoFileReaderState.prBitstreamBuffStatus;
    prNALCTRLBuffer = _rVideoFileReaderState.prNALCTRLBuffer;

    u4MaxHeaderCount = prBitstreamBuffStatus->rBuffHeader.u4MaxHeaderCount;

    // Get port index
    //
    sOutBufferHeader.u4OutputPort = VideoCommGetOutputPortIndex(&_rVideoFileReaderState.rCommState, VIDEO_PORT_VIDEO_DATA);
    pTunneledComponent = VideoCommGetOutputComp(&_rVideoFileReaderState.rCommState, sOutBufferHeader.u4OutputPort);
    if (!pTunneledComponent)
    {
        ASSERT(0);
        return;
    }
    else
        sOutBufferHeader.u4InputPort = pTunneledComponent->u4PortIndex;

    // Get next frame from bitstream buffer and call tunneled component's pfnEmptyThisBuffer()
    // while loop will break if pfnEmptyThisBuffer() return error
    while (fgRet)
    {
        fgRet = _VideoFileReaderGetNextDeliverUint(&sOutBufferHeader);
        video_dbg_trace(VIDEO_DBG_OWNER_FILEWRITER, VIDEO_DBG_FILEREADER_GET_NEXT_UNIT, video_get_current_time());
        if (fgRet)
        {
            u4DeliverIndex = prBitstreamBuffStatus->rBuffHeader.u4DeliverIndex;

            nErrorType = pTunneledComponent->prComp->pfnEmptyThisBuffer(&sOutBufferHeader);
#if 0 //Rita test
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            if (nErrorType != VIDEO_ERROR_NONE)
            {
                // We can't send frame header to tunneled component.
                // In this case, we should roll back write index of NAL control buffer
                // due to write index is updated.
                //
                _rVideoFileReaderState.fgEmptyThisBufferFail = KAL_TRUE;
                drv_trace2(TRACE_GROUP_8, VFILE_EMPTY_THIS_BUFFER_FAILED,
                    prBitstreamBuffStatus->rBuffHeader.au4FrameNum[u4DeliverIndex],
                    prBitstreamBuffStatus->rBuffHeader.au4Address[u4DeliverIndex]
                );
                break;
            }
            else
            {
                drv_trace4(TRACE_GROUP_9, VFILE_EMPTY_THIS_BUFFER_OK,
                    (kal_uint32)sOutBufferHeader.pu1Buffer,
                    sOutBufferHeader.u4BuffSize,
                    sOutBufferHeader.eFlags,
                    sOutBufferHeader.u8TimeStamp
                );

                // If the EOF frame is send, should break the sending loop
                //
                if (sOutBufferHeader.eFlags == VIDEO_BUFFERFLAG_EOF)
                {
                    _rVideoFileReaderState.fgIsDeliverEOF = KAL_TRUE;
                    break;
                }

                // If goes here, we have send a deliver unit to next tunneled component successfully.
                // Update buffer u4DeliverIndex unless target is reached.
                //

                if (VIDEO_DECODER_H264 == _rVideoFileReaderState.u4VideoDecodeType)
                {
                    u4NALCTRLBuffWriteIndex = prNALCTRLBuffer->u4WriteIndex;
                    prPrivateData = (H264_DECODER_INPUT_PARAM_T *)sOutBufferHeader.pPrivateData;

                    if ((u4NALCTRLBuffWriteIndex + prPrivateData->u4PayloadNumber) > VIDEO_FILEREADER_NAL_CTRL_BUFF_NUM)
                    {
                        ASSERT(0);
                    }
                    else
                    {
                        u4NALCTRLBuffWriteIndex = (u4NALCTRLBuffWriteIndex + prPrivateData->u4PayloadNumber) % VIDEO_FILEREADER_NAL_CTRL_BUFF_NUM;
                    }

                    // Update u4WriteIndex here
                    //
                    prNALCTRLBuffer->u4WriteIndex = u4NALCTRLBuffWriteIndex;

                    if (u4NALCTRLBuffWriteIndex == prNALCTRLBuffer->u4ReadIndex)
                    {
                        prNALCTRLBuffer->fgIsFull = KAL_TRUE;
                    }
                }

                _rVideoFileReaderState.u4DeliverFrame = prBitstreamBuffStatus->rBuffHeader.au4FrameNum[u4DeliverIndex] + 1;
                prBitstreamBuffStatus->rBuffHeader.u4DeliverIndex = (u4DeliverIndex + 1) % u4MaxHeaderCount;

                drv_trace1(TRACE_GROUP_9, VFILE_SEND_FRAME_COMPLETE, prBitstreamBuffStatus->rBuffHeader.au4FrameNum[u4DeliverIndex]);

                #ifdef __VIDEO_FILEREADER_PROFILE_ENABLE__
                // Log bitstream buffer usage here
                //
                {

                    kal_uint32 u4AvailFrameStart;
                    kal_uint32 u4AvailFrameEnd;
                    kal_uint32 u4AvailFrameTotal;

                    u4AvailFrameEnd = prBitstreamBuffStatus->rBuffHeader.au4FrameNum[prBitstreamBuffStatus->rBuffHeader.u4WriteIndex];
                    u4AvailFrameStart = _rVideoFileReaderState.u4DeliverFrame;

                    u4AvailFrameTotal = u4AvailFrameEnd - u4AvailFrameStart;
                    _rVideoFileReaderState.rProfileData.au4AvailFrameWindow[_rVideoFileReaderState.rProfileData.u4AvailFrameIndex] = u4AvailFrameTotal;
                    _rVideoFileReaderState.rProfileData.u4AvailFrameIndex = (_rVideoFileReaderState.rProfileData.u4AvailFrameIndex + 1) % VIDEO_FILEREADER_AVAIL_FRAME_WINDOW;

                    if (u4AvailFrameTotal > 10)
                    {
                        VIDEO_STOP_LOGGING("VF10");
                        VIDEO_STOP_LOGGING("VF5");
                    }
                    else if (u4AvailFrameTotal > 5)
                    {
                        VIDEO_START_LOGGING("VF10");
                        VIDEO_STOP_LOGGING("VF5");
                    }
                    else
                    {
                        VIDEO_START_LOGGING("VF10");
                        VIDEO_START_LOGGING("VF5");
                    }
                }
                #endif /* __VIDEO_FILEREADER_PROFILE_ENABLE__ */

                // Send one decode unit and break
                break;

            }
        }
        else
        {
            drv_trace0(TRACE_GROUP_8, VFILE_GET_NEXT_UNIT_FAIL);
        }
    }

}

static VIDEO_ERROR_TYPE_T _VideoFileReaderGetVideoFileInfo(VIDEO_FILEREADER_STATE_T *prVideoFileReaderState)
{
    MP4_Parser_Status eStatus;
    kal_uint32 nTimeScale;//with meta data time scale
    kal_uint32 nDuration;
    kal_uint32 u4TotalNum;

    if (!prVideoFileReaderState)
    {
        ASSERT(0);
        return VIDEO_ERROR_INPUT_PARAM_ERROR;
    }

    // Get video decoder type from META data
    //
    _VideoFileReaderGetDecoderType(prVideoFileReaderState->prFileReaderMp4Parser, &prVideoFileReaderState->u4VideoDecodeType);

    if (prVideoFileReaderState->u4VideoDecodeType == VIDEO_DECODER_UNKNOWN)
    {
        if (prVideoFileReaderState->prFileReaderMp4Parser->bVideoTrack == MP4_RESERVED_TRACK_NO)
        {
            return VIDEO_ERROR_NO_VISUAL_TRACK;
        }
        else
        {
            return VIDEO_ERROR_INIT_ERROR;
        }
    }

    // Get video timescale
    //
    eStatus = MP4_GetMediaTimeScale(prVideoFileReaderState->prFileReaderMp4Parser, &nTimeScale, MP4_TRACK_VIDEO);
    if(eStatus != MP4_PARSER_OK)
    {
        drv_trace1(TRACE_GROUP_8, VFILE_PARSER_ERROR, eStatus);
        return VIDEO_ERROR_PARSER_ERROR;
    }
    else
    {
        prVideoFileReaderState->u4VideoTimeScale = nTimeScale;
        drv_trace1(TRACE_GROUP_8, VFILE_VIDEO_TIMESCALE, nTimeScale);
    }

    // Get video total duration
    //
    eStatus = MP4_GetMediaDuration(prVideoFileReaderState->prFileReaderMp4Parser, &nDuration, MP4_TRACK_VIDEO);
    if(eStatus != MP4_PARSER_OK)
    {
        drv_trace1(TRACE_GROUP_8, VFILE_PARSER_ERROR, eStatus);
        return VIDEO_ERROR_PARSER_ERROR;
    }
    else
    {
        // Translate the duration into common timescale us(10^6)
        prVideoFileReaderState->u8VideoDuration = VIDEO_ANYBASE_TO_ANYBASE(nDuration, nTimeScale, VIDEO_FILEREADER_SCALE_UNIT);
        drv_trace1(TRACE_GROUP_8, VFILE_VIDEO_TOTAL_DURATION, prVideoFileReaderState->u8VideoDuration);
    }

    /* Get total frame number information from file and check it*/
    eStatus = MP4_GetSampleCount(prVideoFileReaderState->prFileReaderMp4Parser, MP4_TRACK_VIDEO, &u4TotalNum);
    if (eStatus != MP4_PARSER_OK)
    {
        drv_trace1(TRACE_GROUP_8, VFILE_PARSER_ERROR, eStatus);
        return VIDEO_ERROR_PARSER_ERROR;
    }
    else
    {
        prVideoFileReaderState->u4VideoTotalFrame = u4TotalNum;
        drv_trace1(TRACE_GROUP_8, VFILE_VIDEO_TOTAL_FRAME, prVideoFileReaderState->u4VideoTotalFrame);

    }

    // The following information retrieve is codec dependence
    //

    // Get parameter set data
    // Only for MPEG-4 & H.264, excluding H.263
    //
    if (VIDEO_DECODER_H264 == prVideoFileReaderState->u4VideoDecodeType || VIDEO_DECODER_MPEG4 == prVideoFileReaderState->u4VideoDecodeType)
    {
        _VideoFileReaderGetParameterSetData(
            prVideoFileReaderState->prFileReaderMp4Parser,
            prVideoFileReaderState->prFileReaderFSAL,
            prVideoFileReaderState->u4VideoDecodeType,
            prVideoFileReaderState->prVideoParamSetData
        );
    }
    return VIDEO_ERROR_NONE;
}

static VIDEO_ERROR_TYPE_T _VideoFileReaderGetBasicInfo(VIDEO_FILEREADER_STATE_T *prVideoFileReaderState)
{
    VIDEO_ERROR_TYPE_T eError;
    kal_uint8 *pu1CurrAddr;
    //kal_uint32 u4Index;
    kal_uint32 u4AvailableSize;
    VIDEO_FILEREADER_FILE_ADAPTATION_STRUCT_T *prReadFileAdaptationInfo;
    VIDEO_BITSTREM_BUFF_STATUS_T *prBitstreamBuffStatus;

    if (!prVideoFileReaderState)
    {
        ASSERT(0);
        return VIDEO_ERROR_INPUT_PARAM_ERROR;
    }

    prBitstreamBuffStatus = prVideoFileReaderState->prBitstreamBuffStatus;
    prReadFileAdaptationInfo = prVideoFileReaderState->prReadFileAdaptationInfo;

    // From init to idle
    //
    if (VIDEO_STATE_INIT == VideoCommGetState(&prVideoFileReaderState->rCommState))
    {
        // Check the basic information from file container
        //
        if (!prVideoFileReaderState->prFileReaderFSAL || !prVideoFileReaderState->prFileReaderMp4Parser)
        {
            drv_trace0(TRACE_GROUP_8, VFILE_REQUIRED_HANDLER_ERROR);
            ASSERT(0);
        }
        else
        {
            eError = _VideoFileReaderGetVideoFileInfo(prVideoFileReaderState);
            if (eError != VIDEO_ERROR_NONE)
            {
                drv_trace1(TRACE_GROUP_8, VFILE_GET_BASIC_INFO_ERROR, eError);
                return eError;
            }
        }

        // Init Filesystem adaptation layer
        // Configure the file system adaptation information
        //
        // TODO: check parameter u4Index usage.
        pu1CurrAddr = prBitstreamBuffStatus->rBitstreamBuff.pu1BuffStartAddr;

        prReadFileAdaptationInfo->u4BeginOfBuffAddr = (kal_uint32)pu1CurrAddr;
        prReadFileAdaptationInfo->u4EndOfBuffAddr = (kal_uint32)pu1CurrAddr + prBitstreamBuffStatus->rBitstreamBuff.u4TotalSize;
        prReadFileAdaptationInfo->u4MaxFileAccessSize = 0; // Value o: no size limit for file system to read data
        // Assign file handler to file system adaptation layer
        //
        prReadFileAdaptationInfo->prSTFSAL = prVideoFileReaderState->prFileReaderFSAL;

        // File reader needs provide width & height information
        // In case of H.263, we fetch first frame here
        //
        if (VIDEO_DECODER_H263 == prVideoFileReaderState->u4VideoDecodeType)
        {
            _VideoFileReaderConfigFillBuffInfo(prReadFileAdaptationInfo, 0, 0);

            // Get first frame for H.263
            //
            if (KAL_TRUE == _VideoFileReaderQueryNeedFetch(&u4AvailableSize))
            {
                // To fill bitstream buffer
                //
                eError = _VideoFileReaderFillBitstreamBuffHdlr(u4AvailableSize);
                if (eError != VIDEO_ERROR_NONE)
                {
                    return eError;
                }
            }
        }
    }
    return VIDEO_ERROR_NONE;
}

//////////////////////////////////////////////////////////
//                Main function
//////////////////////////////////////////////////////////
static void _VideoFileReaderFreeBuffHdlr(VIDEO_BUFFERHEADER_TYPE_T *psBufferHeader)
{
    kal_uint32 u4ReadIndex;
    kal_uint32 u4DeliverIndex;
    kal_uint32 u4MaxHeaderCount;
    kal_uint32 u4BuffReadOffset;
    kal_uint32 u4BuffTotalSize;
    kal_uint32 u4RealAddr;
    kal_uint32 u4RealLength;
    kal_uint32 u4NALCTRLBuffReadIndex;
    H264_DECODER_INPUT_PARAM_T *prPrivateData;
    H264_DECODER_PAYLOAD_INFO_T *prPayloadAddr;
    VIDEO_FILEREADER_FILE_ADAPTATION_STRUCT_T *prReadFileAdaptationInfo;
    VIDEO_BITSTREM_BUFF_STATUS_T *prBitstreamBuffStatus;
    VIDEO_FILEREADER_PARAM_SET_STRUCT_T *prVideoParamSetData;
    VIDEO_FILEREADER_NAL_CTRL_BUFF_T *prNALCTRLBuffer;
    kal_uint32 i;

    if (!psBufferHeader)
    {
        ASSERT(0);
        return;
    }

    prBitstreamBuffStatus = _rVideoFileReaderState.prBitstreamBuffStatus;
    prReadFileAdaptationInfo = _rVideoFileReaderState.prReadFileAdaptationInfo;
    prVideoParamSetData = _rVideoFileReaderState.prVideoParamSetData;
    prNALCTRLBuffer = _rVideoFileReaderState.prNALCTRLBuffer;

    // Verify buffer header data
    // We assume the return buffer is in order sequence
    //
    u4ReadIndex = prBitstreamBuffStatus->rBuffHeader.u4ReadIndex;
    u4DeliverIndex = prBitstreamBuffStatus->rBuffHeader.u4DeliverIndex;
    u4MaxHeaderCount = prBitstreamBuffStatus->rBuffHeader.u4MaxHeaderCount;
    u4BuffReadOffset = prBitstreamBuffStatus->rBitstreamBuff.u4ReadOffset;
    u4BuffTotalSize = prBitstreamBuffStatus->rBitstreamBuff.u4TotalSize;
    u4NALCTRLBuffReadIndex = prNALCTRLBuffer->u4ReadIndex;

    // Check if free frame is larger than target frame number
    // If Free frame is equal to target frame, it must be EOF
    //
    if (_rVideoFileReaderState.u4FreeFrame >= prReadFileAdaptationInfo->u4TargetFrame)
    {
        return;
    }

    // If free frame is EOF frame
    // There must be some wrong
    //
    if (psBufferHeader->eFlags == VIDEO_BUFFERFLAG_EOF)
    {
        ASSERT(0);
        return;
    }

    // If this is parameter set
    // We don't reuse this buffer so there is no necessary to update anything
    //
    if (psBufferHeader->eFlags == VIDEO_BUFFERFLAG_PARAMETERSET)
    {
        if (VIDEO_DECODER_H264 == _rVideoFileReaderState.u4VideoDecodeType)
        {
            if (psBufferHeader->pu1Buffer == (kal_uint8 *)prVideoParamSetData->au4NALuOfParamSetAddr[0])
            {
                return;
            }
            else
            {
                ASSERT(0);
            }
        }
        else if (VIDEO_DECODER_MPEG4 == _rVideoFileReaderState.u4VideoDecodeType)
        {
            if (psBufferHeader->pu1Buffer == prVideoParamSetData->au1ParamSetBuff)
            {
                return;
            }
            else
            {
                ASSERT(0);
            }

        }
    }

    u4RealAddr = (kal_uint32)psBufferHeader->pu1Buffer;
    u4RealLength = psBufferHeader->u4BuffSize;

    // Check free buffer address & size information
    //
    if (prBitstreamBuffStatus->rBuffHeader.au4Address[u4ReadIndex] != u4RealAddr)
    {
        ASSERT(0);
    }

    if (prBitstreamBuffStatus->rBuffHeader.au4Length[u4ReadIndex] != u4RealLength)
    {
        ASSERT(0);
    }

    if (u4ReadIndex > u4MaxHeaderCount)
    {
        ASSERT(0);
    }

    // If there are many NAL units in one frame
    // Update NAL read index here
    //
    if (VIDEO_DECODER_H264 == _rVideoFileReaderState.u4VideoDecodeType)
    {
        if (!psBufferHeader->pPrivateData)
        {
            ASSERT(0);
        }
        else
        {
            prPrivateData = (H264_DECODER_INPUT_PARAM_T *)psBufferHeader->pPrivateData;
            prPayloadAddr = (H264_DECODER_PAYLOAD_INFO_T *)prPrivateData->pu1PayloadAddress;

            // Update NAL control buffer read index
            // Free those buffers
            //
            if ((u4NALCTRLBuffReadIndex + prPrivateData->u4PayloadNumber) > VIDEO_FILEREADER_NAL_CTRL_BUFF_NUM)
            {
                // If reach boundary, we should free NAL header from begin of the buffer.
                //
                u4NALCTRLBuffReadIndex = 0;
            }

            for (i = 0; i < prPrivateData->u4PayloadNumber; i++)
            {
                // For each NAL, check free address and length information
                //
                if (prPayloadAddr->u4Address != prNALCTRLBuffer->arNALCTRLBuff[u4NALCTRLBuffReadIndex].u4Address)
                {
                    ASSERT(0);
                }

                if (prPayloadAddr->u4Length != prNALCTRLBuffer->arNALCTRLBuff[u4NALCTRLBuffReadIndex].u4Length)
                {
                    ASSERT(0);
                }

                u4NALCTRLBuffReadIndex = (u4NALCTRLBuffReadIndex + 1) % VIDEO_FILEREADER_NAL_CTRL_BUFF_NUM;

                prPayloadAddr++;
            }

            // Update read index
            //
            prNALCTRLBuffer->u4ReadIndex = u4NALCTRLBuffReadIndex;
            prNALCTRLBuffer->fgIsFull = KAL_FALSE;
        }

    }

    // Bitstream buffer header
    // Try to free return buffer by updating u4ReadIndex and the next free frame number
    //
    _rVideoFileReaderState.u4FreeFrame = prBitstreamBuffStatus->rBuffHeader.au4FrameNum[u4ReadIndex] + 1;
    prBitstreamBuffStatus->rBuffHeader.u4ReadIndex = (u4ReadIndex + 1) % u4MaxHeaderCount;
    drv_trace1(TRACE_GROUP_9, VFILE_FREE_FRAME, prBitstreamBuffStatus->rBuffHeader.au4FrameNum[u4ReadIndex]);


    // Check full condition
    //
    prBitstreamBuffStatus->rBuffHeader.fgIsFull = KAL_FALSE;

    // Bitstream buffer
    // Only support return one buffer each time
    if ((u4BuffReadOffset + psBufferHeader->u4BuffSize) <= u4BuffTotalSize)
    {
        prBitstreamBuffStatus->rBitstreamBuff.u4ReadOffset = (u4BuffReadOffset + psBufferHeader->u4BuffSize) % u4BuffTotalSize;
    }
    else
    {
        // If reach the end of the buffer line
        // Move to the begin of buffer line
        //
        prBitstreamBuffStatus->rBitstreamBuff.u4ReadOffset = psBufferHeader->u4BuffSize;
    }
    prBitstreamBuffStatus->rBitstreamBuff.fgIsFull = KAL_FALSE;

    // Reset R & W index for empty case
    //
    if (prBitstreamBuffStatus->rBitstreamBuff.u4ReadOffset == prBitstreamBuffStatus->rBitstreamBuff.u4WriteOffset)
    {
        prBitstreamBuffStatus->rBitstreamBuff.u4ReadOffset = 0;
        prBitstreamBuffStatus->rBitstreamBuff.u4WriteOffset = 0;
        drv_trace0(TRACE_GROUP_10, VFILE_DBG_HANDLE_CASE);
    }

    // Set _rVideoFileReaderState.fgWaitForFreeAnyFrame to KAL_FALSE here
    // This notes that there is one frame returned
    //
    _rVideoFileReaderState.fgWaitForFreeAnyFrame = KAL_FALSE;

}

static void _VideoFileReaderStateSetHdlr(kal_uint32 u4Param)
{
    VIDEO_STATE_TYPE_T u4State = (VIDEO_STATE_TYPE_T)u4Param;

    if(u4State == VIDEO_STATE_IDLE)
    {
        // Reset control variable
        //
        _VideoFileReaderControlBlockReset(&_rVideoFileReaderState);

        // Clear internal queue data (cmd/input/output)
        //
        VideoCommClrAllQ(&_rVideoFileReaderState.rCommState);

        // Transition to VIDEO_STATE_IDLE state
        VideoCommChangeState(&_rVideoFileReaderState.rCommState, VIDEO_STATE_IDLE);

        drv_trace1(TRACE_GROUP_8, VFILE_STATE_TRANSFER, VIDEO_STATE_IDLE);
    }
    else if(u4State == VIDEO_STATE_RUN)
    {
        if (VIDEO_STATE_STOP == VideoCommGetState(&_rVideoFileReaderState.rCommState))
        {
            // Clear EOF information
            _rVideoFileReaderState.fgIsDeliverEOF = KAL_FALSE;
        }
        else if (VIDEO_STATE_IDLE == VideoCommGetState(&_rVideoFileReaderState.rCommState))
        {
            _VideoFileReaderConfigFillBuffInfo(_rVideoFileReaderState.prReadFileAdaptationInfo, _rVideoFileReaderState.u4SeekPrevIFrame, _rVideoFileReaderState.u4VideoTotalFrame - 1);
        }

        VideoCommChangeState(&_rVideoFileReaderState.rCommState, VIDEO_STATE_RUN);
        drv_trace1(TRACE_GROUP_8, VFILE_STATE_TRANSFER, VIDEO_STATE_RUN);
    }
    else if(u4State == VIDEO_STATE_STOP)
    {
        //wait for all commands complete
        VideoCommChangeState(&_rVideoFileReaderState.rCommState, VIDEO_STATE_STOP);
        drv_trace1(TRACE_GROUP_8, VFILE_STATE_TRANSFER, VIDEO_STATE_STOP);
    }
    else if(u4State == VIDEO_STATE_CLOSE)
    {
        //VideoCommChangeState(&_rVideoFileReaderState.rCommState, VIDEO_STATE_CLOSE);
        _rVideoFileReaderState.fgClosingComp = KAL_TRUE;
        drv_trace1(TRACE_GROUP_8, VFILE_STATE_TRANSFER, VIDEO_STATE_CLOSE);
    }
    else
    {
        ASSERT(0);
    }
}

void VideoFileReaderDataHdlr(ilm_struct *prIlm)
{
    VIDEO_COMMAND_TYPE_T nType;
    kal_uint32 u4Param;
    kal_uint32 u4AvailableSize;
    VIDEO_BUFFERHEADER_TYPE_T sBufferHeader;

    // Release eMutex or no one can't send message
    //
    VideoCommClrProcessing(&_rVideoFileReaderState.rCommState);

    while (KAL_TRUE)
    {
        // Process command queue list
        //
        if (KAL_TRUE == VideoCommPopCommand(&_rVideoFileReaderState.rCommState, &nType, &u4Param))
        {
            if(nType == VIDEO_COMMAND_STATESET)
            {
                _VideoFileReaderStateSetHdlr(u4Param);
            }
        }
        // Process output queue list
        //
        else if (KAL_TRUE == VideoCommPopOutputBuff(&_rVideoFileReaderState.rCommState, &sBufferHeader))
        {
            _VideoFileReaderFreeBuffHdlr(&sBufferHeader);
        }
        // Process routine jobs
        //
        else
        {
            // There are two jobs: one is checking bitstream buffer threshold to get bitstreams
            // the other is that put decode unit(frame or nal) to tunneled component
            // The two jobs must run in VIDEO_STATE_RUN state.
            //
            if (VIDEO_STATE_RUN != VideoCommGetState(&_rVideoFileReaderState.rCommState))
            {
                break;
            }

            // If there are something happened that file reader can't handle
            // if fgIsFatalError == KAL_TRUE, we will break loop here.
            //
            if (_rVideoFileReaderState.fgIsFatalError)
            {
                //break; // DO nothing
            }

            // If file reader is going to CLOSE sate, we don't process any input/output buffer
            //
            if (_rVideoFileReaderState.fgClosingComp)
            {
                break;
            }

            // TODO: check two jobs priority

            // Check if needed to send parameter set data
            if (KAL_TRUE == _VideoFileReaderQueryNeedDeliverParamSet())
            {
                // If we never send parameter set before send it first
                // For the H.263, we don't need to send any parameter information before decode
                //
                _VideoFileReaderDeliverParamSetHdlr();
            }
            // If check bitstream fill threshold is KAL_TRUE, means that we can start to trigger
            // filling process.
            //
            else if (KAL_TRUE == _VideoFileReaderQueryNeedFetch(&u4AvailableSize))
            {
                // To fill bitstream buffer
                //
                _VideoFileReaderFillBitstreamBuffHdlr(u4AvailableSize);
            }
            // To deliver the decoding unit to the tunneled component
            //
            else if (KAL_TRUE == _VideoFileReaderQueryNeedDeliver())
            {
                // TODO: check break condition!

                // Not empty eStatus; to deliver a decode unit to tunneled component
                // _VideoFileReaderDeliverDecodeUnitHdlr() will deliver frame as possible as it can
                //
                _VideoFileReaderDeliverDecodeUnitHdlr();
                // Can't deliver frame no more
                // break while loop
                //
                if (_rVideoFileReaderState.fgEmptyThisBufferFail == KAL_TRUE)
                {
                    _rVideoFileReaderState.fgEmptyThisBufferFail = KAL_FALSE;
                    break;
                }
            }
            else
            {
                // break while loop & task will suspend ..... good night
                //
                break;
            }
        }

        // Test for get vos
        // _VideoFileReaderGetVOSData(_rVideoFileReaderState.prFileReaderMp4Parser, _rVideoFileReaderState.prFileReaderFSAL, VOSParameter.VOSData, &VOSParameter.VOSSize);

    }

    // Delay closing...
    // File reader runs in task level. File reader should guarantee run out main loop in order to transfer state.
    // When fgClosingComp is set, it means that file reader receives a transfer to close command.
    //
    if (_rVideoFileReaderState.fgClosingComp== KAL_TRUE)
    {
        if (KAL_FALSE == VideoCommCheckProcessing(&_rVideoFileReaderState.rCommState))
        {
            VideoCommChangeState(&_rVideoFileReaderState.rCommState, VIDEO_STATE_CLOSE);
        }
    }
}

void video_filereader_main(ilm_struct *prIlm)
{
    switch (prIlm->msg_id)
    {
    case MSG_ID_VFILE_TEST:
        VideoFileReaderDataHdlr(prIlm);
        break;
    default:
        break;
    }
}
#endif /*#if defined(__MPEG4_DEC_SUPPORT__) || defined(__H264_DEC_SUPPORT__)*/
#endif /* __VIDEO_ARCHI_V2__ */
