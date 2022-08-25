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
 *   video_recorder_source_component_v2.c
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
 ****************************************************************************/


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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // 0


#include "drv_features_video.h"             // for __VE_SLIM_RECORDER_SOURCE__


#ifdef __VE_VIDEO_ARCHI_V2__


#ifdef __VE_DCM_WITH_COMPRESSION__
#include "dcmgr.h"  // for DCM

#pragma arm section code = "DYNAMIC_CODE_VEENC_ROCODE", rodata = "DYNAMIC_CODE_VEENC_RODATA"
#endif  // __VE_DCM_WITH_COMPRESSION__


/*****************************************************************************
* Definition of macros
*****************************************************************************/
#ifndef UNUSED
#define UNUSED(x)               ((void)(x))
#endif  // UNUSED


#if defined(__VE_SLIM_PROJECT__) && !defined(VRSRC_DEVELOPMENT)
#define _VRSRC_LABEL_LOG(x)                 do { /* empty */ } while (0)
#define _VRSRC_ASSERT(x)                    do { /* empty */ } while (0)
#define _VRSRC_ASSERT_IF_EQUAL(x, y)        do { UNUSED(x);  } while (0)
#define _VRSRC_ASSERT_IF_NOT_EQUAL(x, y)    do { UNUSED(x);  } while (0)
#else
#define _VRSRC_LABEL_LOG(x)         VIDEO_LABEL_LOGGING(x)
#define _VRSRC_ASSERT(x)            ASSERT(x)
#define _VRSRC_ASSERT_IF_EQUAL(x, y)                                \
    do {                                                            \
        if ((x) == (y))                                             \
        {                                                           \
            ASSERT(0);                                              \
        }                                                           \
    } while (0)
#define _VRSRC_ASSERT_IF_NOT_EQUAL(x, y)                            \
    do {                                                            \
        if ((x) != (y))                                             \
        {                                                           \
            ASSERT(0);                                              \
        }                                                           \
    } while (0)
#endif  // defined (__VE_SLIM_PROJECT__)


#if !defined(__VE_SLIM_RECORDER_SOURCE__)


/******************************************************************************
*******************************************************************************
* Here begins the non-slim version of Source.
*******************************************************************************
******************************************************************************/


#if defined(__VE_MPEG4_ENC_SUPPORT__) || defined(__VE_H264_ENC_SW_SUPPORT__) || defined(__VE_AVI_ENC_SUPPORT__)


#include "dcl.h"                            // for new HAL GPT of type DCL_HANDLE
#include "drv_comm.h"                       // for drv_trace1(), drv_trace8()
#include "vcodec_v2_trc.h"
#include "video_types_v2.h"
#include "video_recorder_source_component_v2.h"
#include "kal_trace.h"
#include "video_dbg_v2.h"
#include "video_comm_component_v2.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "video_recorder_source_component_if_v2.h"
#include "video_buffer_management_v2.h"
#include "video_recorder_clock_utility_if_v2.h"
#include "visualhisr.h"


#define VRSRC_GET_STATE()       VideoCommGetState(&_rVideoRecorderSourceState.rCommState)


#if 1  // [MAUI_02996107]
static kal_uint64 _u8LastTimeStamp;
#endif  // [MAUI_02996107]


/******************************************************************************
*
******************************************************************************/
static VIDEO_RECORDER_SOURCE_STATE_T _rVideoRecorderSourceState;


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoRecorderInitSourceBuffer(void)
{
    VIDEO_RECORDER_INPUT_BUFFER_T* const prInBuffer = &_rVideoRecorderSourceState.rInputBuffer;
    kal_mem_set(prInBuffer, 0, sizeof(*prInBuffer));

    drv_trace1(TRACE_GROUP_10, VREC_SOURCE_BUFFER_INIT, 0);
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoRecorderConfigSourceBuffer(kal_uint8 *pu1BuffAddr, kal_uint32 u4BuffSize)
{
    VIDEO_RECORDER_INPUT_BUFFER_T* const prInBuffer = &_rVideoRecorderSourceState.rInputBuffer;

    // component use this function to config buffer
    if(prInBuffer->u4BuffNum >= VIDEO_RECORDER_MAX_INPUT_BUFFER_NUM)
    {
        return;
    }
    if(prInBuffer->u4EachBuffSize == 0)
    {
        prInBuffer->u4EachBuffSize = u4BuffSize;
    }
    if(prInBuffer->u4EachBuffSize != u4BuffSize)
    {
        ASSERT(0);
    }

    prInBuffer->pu1BuffAddr[prInBuffer->u4BuffNum] = pu1BuffAddr;
    // the last one always be dummy buffer for preview and drop (encode too slow)
    prInBuffer->u4DummyIdx = prInBuffer->u4BuffNum;
    prInBuffer->u4BuffNum++;
    drv_trace4(TRACE_GROUP_10, VREC_SOURCE_BUFFER_CONFIG, prInBuffer->u4BuffNum-1,
        (kal_uint32)pu1BuffAddr, prInBuffer->u4DummyIdx, prInBuffer->u4BuffNum);
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoRecorderSetSourceBuffer(kal_uint8 *pu1BuffAddr)
{
    VIDEO_RECORDER_INPUT_BUFFER_T* const prInBuffer = &_rVideoRecorderSourceState.rInputBuffer;
    kal_uint32 u4Index;

    for (u4Index = 0; u4Index < prInBuffer->u4BuffNum; u4Index++)
    {
        kal_mem_cpy((void*)prInBuffer->pu1BuffAddr[u4Index], (void*)pu1BuffAddr,
            prInBuffer->u4EachBuffSize);
    }
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoRecorderEncodeDoneSourceBuffer(kal_uint8* pu1BuffAddr)
{
    VIDEO_RECORDER_INPUT_BUFFER_T* const prInBuffer = &_rVideoRecorderSourceState.rInputBuffer;

    if (pu1BuffAddr != prInBuffer->pu1BuffAddr[prInBuffer->u4ReadIdx])
    {
        ASSERT(0);
    }

    if (prInBuffer->u1BuffStatus[prInBuffer->u4ReadIdx] != VRSRC_BUFFER_STATUS_IN_USE_WITH_TIMESTAMP)
    {
        ASSERT(0);
    }

    drv_trace2(TRACE_GROUP_10, VREC_SOURCE_COMPLETE_BUFFER, (kal_uint32)pu1BuffAddr, prInBuffer->u4ReadIdx);
    prInBuffer->u1BuffStatus[prInBuffer->u4ReadIdx] = VRSRC_BUFFER_STATUS_FREE;
    prInBuffer->u4ReadIdx = (prInBuffer->u4ReadIdx + 1) % prInBuffer->u4DummyIdx;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoRecorderSource_AttachTimeStamp(kal_uint32 u4YUVReadIdx)
{
    kal_uint64 u8TimeStamp;
    VIDEO_RECORDER_INPUT_BUFFER_T* const prInBuff = &_rVideoRecorderSourceState.rInputBuffer;

    if (u4YUVReadIdx >= VIDEO_RECORDER_MAX_INPUT_BUFFER_NUM)
    {
        ASSERT(0);
    }

    if (prInBuff->u1BuffStatus[u4YUVReadIdx] == VRSRC_BUFFER_STATUS_IN_USE_WITHOUT_TIMESTAMP)
    {
        VRCLK_GetCurrentTime(&u8TimeStamp);

        drv_trace2(TRACE_GROUP_10, VREC_SOURCE_GET_TIME_STAMP,
            (kal_uint32)((u8TimeStamp >> 32) & 0xFFFFFFFF),
            (kal_uint32)(u8TimeStamp & 0xFFFFFFFF));
#if 1  // [MAUI_02996107]
        if (_u8LastTimeStamp < u8TimeStamp)
        {
            _u8LastTimeStamp = u8TimeStamp;
        }
        else
        {
            drv_trace2(TRACE_GROUP_10, VREC_SOURCE_CHANGE_TIME_STAMP,
                (kal_uint32)u8TimeStamp, (kal_uint32)_u8LastTimeStamp);
            u8TimeStamp = _u8LastTimeStamp;
        }
#endif  // [MAUI_02996107]
        prInBuff->au8TimeStamp[u4YUVReadIdx] = u8TimeStamp;
        prInBuff->u1BuffStatus[u4YUVReadIdx] = VRSRC_BUFFER_STATUS_IN_USE_WITH_TIMESTAMP;
    }
    else
    {
        ASSERT(0);
    }
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoRecorderSource_SendEofToEncoder(void)
{
    PFN_EMPTY_THIS_BUFFER_T const pfnEncoderEmptyThisBuffer = _rVideoRecorderSourceState.pfnEncoderEmptyThisBuffer;
    VIDEO_BUFFERHEADER_TYPE_T rBufferHeader;

    if (_rVideoRecorderSourceState.fgEofSent == KAL_TRUE)
    {
        return;
    }

    // If the STOP command has been received and the internal state has changed
    // to STOP state, send EOF to encoder.
    rBufferHeader.u4OutputPort = _rVideoRecorderSourceState.u4DataPortIdx;
    rBufferHeader.u4InputPort = _rVideoRecorderSourceState.u4DataPortConnectedIdx;
    rBufferHeader.u8TimeStamp = 0;
    rBufferHeader.pu1Buffer = 0;
    rBufferHeader.u4BuffSize = 0;
    rBufferHeader.eFlags = VIDEO_BUFFERFLAG_EOF;

    if (pfnEncoderEmptyThisBuffer(&rBufferHeader) != VIDEO_ERROR_NONE)
    {
        drv_trace0(TRACE_GROUP_10, VREC_SOURCE_ENCODER_REJECTS_EOF);
    }
    else
    {
        drv_trace0(TRACE_GROUP_10, VREC_SOURCE_ENCODER_ACCEPTS_EOF);
        _rVideoRecorderSourceState.fgEofSent = KAL_TRUE;
    }
}


/******************************************************************************
* Store information of connected modules/components.
*
* Context: MED
*
* Side effect:
******************************************************************************/
__inline static void _VideoRecorderSource_StoreInfoOfConnectedModules(void)
{
    VIDEO_COMPONENT_PARAM_T *prDataPortComp;

    // Store Encoder's information.
    _rVideoRecorderSourceState.u4DataPortIdx = VideoCommGetOutputPortIndex(&_rVideoRecorderSourceState.rCommState, VIDEO_PORT_VIDEO_DATA);
    prDataPortComp = VideoCommGetOutputComp(&_rVideoRecorderSourceState.rCommState, _rVideoRecorderSourceState.u4DataPortIdx);
    if (prDataPortComp == NULL)
    {
        ASSERT(0);
    }
    _rVideoRecorderSourceState.pfnEncoderEmptyThisBuffer = prDataPortComp->prComp->pfnEmptyThisBuffer;
    _rVideoRecorderSourceState.u4DataPortConnectedIdx = prDataPortComp->u4PortIndex;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static kal_bool _VideoRecorderEncodeSourceBuffer(kal_uint32 u4WriteIdx)
{
    kal_uint64 u8TimeStamp;
    VIDEO_RECORDER_INPUT_BUFFER_T* const prInBuff = &_rVideoRecorderSourceState.rInputBuffer;
    PFN_EMPTY_THIS_BUFFER_T const pfnEncoderEmptyThisBuffer = _rVideoRecorderSourceState.pfnEncoderEmptyThisBuffer;
    kal_uint8 *pu1BuffAddr;
    VIDEO_BUFFERHEADER_TYPE_T rBufferHeader;
    kal_bool fgRet = KAL_TRUE;

    if ((u4WriteIdx >= VIDEO_RECORDER_MAX_INPUT_BUFFER_NUM) ||
        (pfnEncoderEmptyThisBuffer == NULL) ||
        (prInBuff->u1BuffStatus[u4WriteIdx] != VRSRC_BUFFER_STATUS_IN_USE_WITH_TIMESTAMP))
    {
        ASSERT(0);
    }

    pu1BuffAddr = prInBuff->pu1BuffAddr[u4WriteIdx];
    u8TimeStamp = prInBuff->au8TimeStamp[u4WriteIdx];
// #ifdef __VE_ENCODE_WITH_MOTION_SENSOR_SUPPORT__
    switch (prInBuff->u1EncodeFlag[u4WriteIdx])
    {
    case VRSRC_BUFFER_STATUS_VALID:
        rBufferHeader.eFlags = VIDEO_BUFFERFLAG_NONE;
        break;

    case VRSRC_BUFFER_STATUS_INVALID:
        rBufferHeader.eFlags = VIDEO_BUFFERFLAG_INVALID_FRAME;
        break;

    default:
        ASSERT(0);
        break;
    }
// #endif  // __VE_ENCODE_WITH_MOTION_SENSOR_SUPPORT__

    // Call encoder's EmptyThisBuffer() in image DMA HISR.
    rBufferHeader.u4OutputPort = _rVideoRecorderSourceState.u4DataPortIdx;
    rBufferHeader.u4InputPort = _rVideoRecorderSourceState.u4DataPortConnectedIdx;
    rBufferHeader.u8TimeStamp = u8TimeStamp;
    rBufferHeader.pu1Buffer = pu1BuffAddr;
    rBufferHeader.u4BuffSize = _rVideoRecorderSourceState.rInputBuffer.u4EachBuffSize;
// #ifndef __VE_ENCODE_WITH_MOTION_SENSOR_SUPPORT__
//     rBufferHeader.eFlags = VIDEO_BUFFERFLAG_NONE;
// #endif  // __VE_ENCODE_WITH_MOTION_SENSOR_SUPPORT__
    if (pfnEncoderEmptyThisBuffer(&rBufferHeader) != VIDEO_ERROR_NONE)
    {
        drv_trace2(TRACE_GROUP_10, VREC_SOURCE_ENCODER_REJECTS_FRAME_BUFFER,
            (kal_uint32)((u8TimeStamp >> 32) & 0xFFFFFFFF),
            (kal_uint32)(u8TimeStamp & 0xFFFFFFFF));
        fgRet = KAL_FALSE;
    }
    else
    {
        drv_trace2(TRACE_GROUP_10, VREC_SOURCE_ENCODER_ACCEPTS_FRAME_BUFFER,
            (kal_uint32)((u8TimeStamp >> 32) & 0xFFFFFFFF),
            (kal_uint32)(u8TimeStamp & 0xFFFFFFFF));
        video_dbg_trace(VIDEO_DBG_OWNER_ENCSRC, VIDEO_DBG_ENCSRC_ENCODER_GET_BUFFER, (kal_uint32)pu1BuffAddr);
    }

    return fgRet;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoRecorderSourceTimeoutHdlr(void *pTimerParam)
{
    MPL_BUFFER_INFO_T rBufferInfo;
    SGPT_CTRL_START_T rGptInfo;

    if(VideoCommGetState(&_rVideoRecorderSourceState.rCommState) != VIDEO_STATE_RUN)
    {
        ASSERT(0);
    }

    kal_mem_set((void*)&rBufferInfo, 0, sizeof(rBufferInfo));

    // get buffer
    rBufferInfo = VideoRecorderGetSourceBuffer();

    // start GPT again
    kal_mem_set((void*)&rGptInfo, 0, sizeof(rGptInfo));
    rGptInfo.pfCallback = _VideoRecorderSourceTimeoutHdlr;
    rGptInfo.u2Tick = (DCL_UINT16)_rVideoRecorderSourceState.u4YUVInterval;
    // rGptInfo.vPara = NULL;
    DclSGPT_Control(_rVideoRecorderSourceState.rGptHandle, SGPT_CMD_START, (DCL_CTRL_DATA_T*)&rGptInfo);

    rBufferInfo.eStatus = MPL_OK;
    VideoRecorderCompleteSourceBuffer(rBufferInfo);
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoRecorderSourceBufferTag(kal_uint32 u4YUVIdx, kal_uint32 u4ReadIdx, kal_uint32 u4TotalIdx)
{
    kal_uint32 u4TotalNum;

    if(u4YUVIdx >= u4ReadIdx)
    {
        u4TotalNum = u4YUVIdx - u4ReadIdx;
    }
    else
    {
        u4TotalNum = u4YUVIdx + u4TotalIdx - u4ReadIdx;
    }

    switch(u4TotalNum)
    {
    case 0:
        _VRSRC_LABEL_LOG("SB0");
        break;
    case 1:
        _VRSRC_LABEL_LOG("SB1");
        break;
    case 2:
        _VRSRC_LABEL_LOG("SB2");
       break;
    case 3:
        _VRSRC_LABEL_LOG("SB3");
        break;
    case 4:
        _VRSRC_LABEL_LOG("SB4");
        break;
    case 5:
        _VRSRC_LABEL_LOG("SB5");
       break;
    case 6:
        _VRSRC_LABEL_LOG("SB6");
        break;
    case 7:
        _VRSRC_LABEL_LOG("SB7");
        break;
    default:
        _VRSRC_LABEL_LOG("SB8");
       break;
    }
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static VIDEO_ERROR_TYPE_T _VideoRecorderSourceInit(void)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    VIDEO_PORT_CONFIG_T rOutputPort1, rOutputPort2;
    VIDEO_COMPONENT_INIT_T rInitConfig;
    kal_mutexid eMutex = VideoGetMutex(MUTEX_USER_RECORDER_SOURCE);
    VIDEO_EXTMEM_HANDLER_T *prExtMemInfo = _rVideoRecorderSourceState.prExtMemInfo;  // backup
    // DCL_STATUS eStatus;
    DCL_HANDLE rGptHandle = _rVideoRecorderSourceState.rGptHandle;

#if 1  // [MAUI_02996107]
    _u8LastTimeStamp = 0;
#endif  // [MAUI_02996107]

    // Note that Mutex will be cleared by the following kal_mem_set()!!!
    kal_mem_set(&_rVideoRecorderSourceState, 0, sizeof(_rVideoRecorderSourceState));
    _rVideoRecorderSourceState.rCommState.eMutex = eMutex;
    _rVideoRecorderSourceState.prExtMemInfo = prExtMemInfo;  // restore

    // eStatus = DclSGPT_Initialize();
    // if (eStatus != STATUS_OK)
    // {
    //     ASSERT(0);
    // }
    _rVideoRecorderSourceState.rGptHandle = rGptHandle;
    if (rGptHandle == NULL)
    {
        _rVideoRecorderSourceState.rGptHandle = DclSGPT_Open(DCL_GPT_CB, FLAGS_NONE);
        if (_rVideoRecorderSourceState.rGptHandle == DCL_HANDLE_INVALID)
        {
            ASSERT(0);
        }
    }

    // frame buffer to encoder component
    rOutputPort1.ePortType = VIDEO_PORT_VIDEO_DATA;
    rOutputPort1.fgSupplier = KAL_FALSE;
    rOutputPort1.u4BuffSize = 0;

    // Clock has become a set of utility functions. Set port type to NONE.
    rOutputPort2.ePortType = VIDEO_PORT_NONE;
    rOutputPort2.fgSupplier = KAL_FALSE;
    rOutputPort2.u4BuffSize = 0;

    kal_mem_set((void*)&rInitConfig, 0, sizeof(rInitConfig));
    rInitConfig.prOutputPort1 = &rOutputPort1;
    rInitConfig.prOutputPort2 = &rOutputPort2;
    rInitConfig.prExtMemHdlr = _rVideoRecorderSourceState.prExtMemInfo;
    rInitConfig.eMutex = eMutex;

    eError = VideoCommInit(&_rVideoRecorderSourceState.rCommState, &rInitConfig, "VRSRC");
    if(eError != VIDEO_ERROR_NONE)
    {
        ASSERT(0);
    }

    _VideoRecorderInitSourceBuffer();

    _rVideoRecorderSourceState.eIntState = VIDEO_RECORDER_SOURCE_INIT;
    drv_trace2(TRACE_GROUP_10, VREC_SOURCE_CHANGE_STATE, _rVideoRecorderSourceState.eIntState, __LINE__);
    _rVideoRecorderSourceState.u4KeepInterval = 1;
    _rVideoRecorderSourceState.u4CurrInterval = 1;
    _rVideoRecorderSourceState.fgEofSent = KAL_FALSE;

    drv_trace0(TRACE_GROUP_10, VREC_SOURCE_INIT);

    return eError;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static VIDEO_ERROR_TYPE_T _VideoRecorderSourceSendCommand(VIDEO_COMMAND_TYPE_T eCmd, kal_uint32 u4Param)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    kal_uint32 u4Mask;
    kal_uint32 u4Line = 0;

    if (eCmd != VIDEO_COMMAND_STATESET)
    {
        ASSERT(0);
    }

    switch (u4Param)
    {
    case VIDEO_STATE_INIT:
        VideoCommChangeState(&_rVideoRecorderSourceState.rCommState, VIDEO_STATE_INIT);
        break;

    case VIDEO_STATE_IDLE:
        drv_trace0(TRACE_GROUP_10, VREC_SOURCE_RECV_CMD_IDLE);
        VideoCommClrAllQ(&_rVideoRecorderSourceState.rCommState);
        // really change to IDLE until (1)receive IDLE cmd (2)Recieve all frame buffers from encoder component by UseBuffer
        u4Mask = SaveAndSetIRQMask();
        if(_rVideoRecorderSourceState.eIntState == VIDEO_RECORDER_SOURCE_INIT)
        {
            _rVideoRecorderSourceState.eIntState = VIDEO_RECORDER_SOURCE_INIT_RECV_IDLE_CMD;
            u4Line = __LINE__;
        }
        else if ((_rVideoRecorderSourceState.eIntState == VIDEO_RECORDER_SOURCE_INIT_COMPLETE_BUFF) ||
                 (_rVideoRecorderSourceState.eIntState == VIDEO_RECORDER_SOURCE_STOP) )
        {
            _rVideoRecorderSourceState.eIntState = VIDEO_RECORDER_SOURCE_IDLE;
            _rVideoRecorderSourceState.u4CurrInterval = 1;
            u4Line = __LINE__;
        }
        else
        {
            ASSERT(0);
        }
        RestoreIRQMask(u4Mask);
        drv_trace2(TRACE_GROUP_10, VREC_SOURCE_CHANGE_STATE, _rVideoRecorderSourceState.eIntState, u4Line);
        _rVideoRecorderSourceState.pu1YUVBuffer = NULL;
        _rVideoRecorderSourceState.u4YUVInterval = 0;
        // _rVideoRecorderSourceState.fgGetSourceBuffer = KAL_FALSE;
        if(_rVideoRecorderSourceState.eIntState == VIDEO_RECORDER_SOURCE_IDLE)
        {
            VideoCommChangeState(&_rVideoRecorderSourceState.rCommState, VIDEO_STATE_IDLE);
            drv_trace0(TRACE_GROUP_10, VREC_SOURCE_CHANGE_IDLE);
        }
        break;

    case VIDEO_STATE_RUN:
        drv_trace0(TRACE_GROUP_10, VREC_SOURCE_RECV_CMD_RUN);
        _VideoRecorderSource_StoreInfoOfConnectedModules();
        if ((_rVideoRecorderSourceState.eIntState != VIDEO_RECORDER_SOURCE_IDLE) &&
            (_rVideoRecorderSourceState.eIntState != VIDEO_RECORDER_SOURCE_STOP))
        {
            ASSERT(0);
        }
        if ((_rVideoRecorderSourceState.pu1YUVBuffer != NULL) &&
            (_rVideoRecorderSourceState.u4YUVInterval != 0))
        {
            SGPT_CTRL_START_T rGptInfo;
            _rVideoRecorderSourceState.eIntState = VIDEO_RECORDER_SOURCE_PRE_YUV_RUN;
            // copy all YUV buffer
            _VideoRecorderSetSourceBuffer(_rVideoRecorderSourceState.pu1YUVBuffer);
            // start GPT
            kal_mem_set((void*)&rGptInfo, 0, sizeof(rGptInfo));
            rGptInfo.pfCallback = _VideoRecorderSourceTimeoutHdlr;
            rGptInfo.u2Tick = (DCL_UINT16)_rVideoRecorderSourceState.u4YUVInterval;
            // rGptInfo.vPara = NULL;
            DclSGPT_Control(_rVideoRecorderSourceState.rGptHandle, SGPT_CMD_START, (DCL_CTRL_DATA_T*)&rGptInfo);
        }
        else
        {
            _rVideoRecorderSourceState.eIntState = VIDEO_RECORDER_SOURCE_PRE_RUN;
        }
#if 1
        {
            VIDEO_RECORDER_INPUT_BUFFER_T* const prInBuff = &_rVideoRecorderSourceState.rInputBuffer;
            // check whether encoder returns all YUV buffer after STOP state

            // Encoder may not return the addresses between prInBuff->u4ReadIdx
            // and prInBuff->u4WriteIdx to Souce component.  Clear the
            // status flags inbetween and update prInBuff->u4ReadIdx.
            if (_rVideoRecorderSourceState.fgStopInstantly == KAL_TRUE)
            {
                drv_trace4(TRACE_GROUP_10, VREC_SOURCE_STOP_INSTANTLY_WITH_INDEX, prInBuff->u4YUVWriteIdx, prInBuff->u4YUVReadIdx, prInBuff->u4WriteIdx, prInBuff->u4ReadIdx);
                if (prInBuff->u4WriteIdx != prInBuff->u4YUVReadIdx)
                {
                    prInBuff->u4WriteIdx = prInBuff->u4YUVReadIdx;
                }
                else
                {
                    if ((prInBuff->u4WriteIdx == prInBuff->u4YUVWriteIdx) &&
                        (prInBuff->u4WriteIdx == prInBuff->u4ReadIdx) &&
                        (prInBuff->u1BuffStatus[prInBuff->u4ReadIdx] == VRSRC_BUFFER_STATUS_IN_USE_WITH_TIMESTAMP))
                    {
                        _VideoRecorderEncodeDoneSourceBuffer(prInBuff->pu1BuffAddr[prInBuff->u4ReadIdx]);
                    }
                }
                while (prInBuff->u4ReadIdx != prInBuff->u4WriteIdx)
                {
                    _VideoRecorderEncodeDoneSourceBuffer(prInBuff->pu1BuffAddr[prInBuff->u4ReadIdx]);
                }
                _rVideoRecorderSourceState.fgStopInstantly = KAL_FALSE;
            }

            if(prInBuff->u4WriteIdx != prInBuff->u4ReadIdx)
            {
                ASSERT(0);
            }
            // return all the YUV buffer returned from IDP and queued in source component after changing to STOP state
            while (prInBuff->u4WriteIdx != prInBuff->u4YUVReadIdx)
            {
                // returned all queued buffers
                _VideoRecorderEncodeDoneSourceBuffer(prInBuff->pu1BuffAddr[prInBuff->u4WriteIdx]);
                prInBuff->u4WriteIdx = (prInBuff->u4WriteIdx + 1) % prInBuff->u4DummyIdx;
            }
        }
#endif
        drv_trace2(TRACE_GROUP_10, VREC_SOURCE_CHANGE_STATE, _rVideoRecorderSourceState.eIntState, __LINE__);
        _rVideoRecorderSourceState.fgEofSent = KAL_FALSE;
        VideoCommChangeState(&_rVideoRecorderSourceState.rCommState, VIDEO_STATE_RUN);
        drv_trace0(TRACE_GROUP_10, VREC_SOURCE_CHANGE_RUN);
        break;

    case VIDEO_STATE_STOP:
        drv_trace0(TRACE_GROUP_10, VREC_SOURCE_RECV_CMD_STOP);
        if ((_rVideoRecorderSourceState.eIntState != VIDEO_RECORDER_SOURCE_IDLE) &&
            (_rVideoRecorderSourceState.eIntState != VIDEO_RECORDER_SOURCE_PRE_RUN) &&
            (_rVideoRecorderSourceState.eIntState != VIDEO_RECORDER_SOURCE_RUN) &&
            (_rVideoRecorderSourceState.eIntState != VIDEO_RECORDER_SOURCE_PRE_YUV_RUN) &&
            (_rVideoRecorderSourceState.eIntState != VIDEO_RECORDER_SOURCE_YUV_RUN))
        {
            ASSERT(0);
        }
        if ((_rVideoRecorderSourceState.eIntState == VIDEO_RECORDER_SOURCE_PRE_YUV_RUN) ||
            (_rVideoRecorderSourceState.eIntState == VIDEO_RECORDER_SOURCE_YUV_RUN))
        {
            // FIXME: What is the third parameter in DclSGPT_Control()???
            DclSGPT_Control(_rVideoRecorderSourceState.rGptHandle, SGPT_CMD_STOP, NULL);
        }
        _rVideoRecorderSourceState.eIntState = VIDEO_RECORDER_SOURCE_STOP;
        _rVideoRecorderSourceState.u4CurrInterval = 1;
        drv_trace2(TRACE_GROUP_10, VREC_SOURCE_CHANGE_STATE, _rVideoRecorderSourceState.eIntState, __LINE__);
        //wait for all commands complete
        VideoCommChangeState(&_rVideoRecorderSourceState.rCommState, VIDEO_STATE_STOP);
        _VideoRecorderSource_SendEofToEncoder();  // This line must be called after Source enters STOP.
        drv_trace0(TRACE_GROUP_10, VREC_SOURCE_CHANGE_STOP);
        break;

    case VIDEO_STATE_CLOSE:
        drv_trace0(TRACE_GROUP_10, VREC_SOURCE_RECV_CMD_CLOSE);
        //wait for all commands complete
        VideoCommChangeState(&_rVideoRecorderSourceState.rCommState, VIDEO_STATE_CLOSE);
        drv_trace0(TRACE_GROUP_10, VREC_SOURCE_CHANGE_CLOSE);
        break;

    default:
        ASSERT(0);
        break;
    }

    return eError;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static VIDEO_ERROR_TYPE_T _VideoRecorderSourceGetParameter(VIDEO_PARAM_TYPE_T eCmd, void *pvParam)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    switch(eCmd)
    {
    case VIDEO_PARAM_OUTPUT_BUFFER_PARAM:
        VideoCommGetOutputPortParam(&_rVideoRecorderSourceState.rCommState, pvParam);
        break;

    case VIDEO_PARAM_INPUT_BUFFER_PARAM:
        VideoCommGetInputPortParam(&_rVideoRecorderSourceState.rCommState, pvParam);
        break;

    default:
        ASSERT(0);
        break;
    }

    return eError;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static VIDEO_ERROR_TYPE_T _VideoRecorderSourceSetParameter(VIDEO_PARAM_TYPE_T eCmd, void *pvParam)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    kal_uint32 *pu4Param;
    kal_uint8 *pu1Param;

    switch(eCmd)
    {
    case VIDEO_PARAM_OUTPUT_BUFFER_PARAM:
        VideoCommSetOutputPortParam(&_rVideoRecorderSourceState.rCommState, pvParam);
        break;

    case VIDEO_PARAM_INPUT_BUFFER_PARAM:
        VideoCommSetInputPortParam(&_rVideoRecorderSourceState.rCommState, pvParam);
        break;

    case VIDEO_PARAM_RECODER_SOURCE_KEEP_INTERVAL:
        pu4Param = (kal_uint32*)pvParam;
        _rVideoRecorderSourceState.u4KeepInterval = *pu4Param;
        drv_trace1(TRACE_GROUP_10, VREC_SOURCE_SET_INTERVAL, _rVideoRecorderSourceState.u4KeepInterval);
        break;

    case VIDEO_PARAM_RECODER_SOURCE_YUV_BUFFER:
        pu1Param = (kal_uint8*)pvParam;
        _rVideoRecorderSourceState.pu1YUVBuffer = pu1Param;  // FIXME: No size information!
        break;

    case VIDEO_PARAM_RECODER_SOURCE_YUV_INTERVAL:
        pu4Param = (kal_uint32*)pvParam;
        _rVideoRecorderSourceState.u4YUVInterval = (*pu4Param) / 10000;  // Convert time in 1us to time in 10ms.
        if(_rVideoRecorderSourceState.u4YUVInterval == 0)
        {
            ASSERT(0);
        }
        break;

    case VIDEO_PARAM_RECORDER_SOURCE_STOP_INSTANTLY:
        {
            kal_bool fgStopInstantly;
            fgStopInstantly = *(kal_bool*)pvParam;
            _rVideoRecorderSourceState.fgStopInstantly = fgStopInstantly;
            drv_trace1(TRACE_GROUP_10, VREC_SOURCE_STOP_INSTANTLY, fgStopInstantly);
        }
        break;

    default:
        ASSERT(0);
        break;
    }

    return eError;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static VIDEO_ERROR_TYPE_T _VideoRecorderSourceUseBuffer(kal_uint8* pu1Buff, kal_uint32 u4Size)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    kal_uint32 u4Mask;
    kal_uint32 u4Line = 0;

    drv_trace2(TRACE_GROUP_10, VREC_SOURCE_USE_BUFFER, (kal_uint32)pu1Buff, u4Size);

    if(u4Size!=0)
    {
        _VideoRecorderConfigSourceBuffer(pu1Buff, u4Size);
    }
    else
    {
        // complete config source buffer until receive a buffer with size 0
        u4Mask = SaveAndSetIRQMask();
        if(_rVideoRecorderSourceState.eIntState == VIDEO_RECORDER_SOURCE_INIT)
        {
            _rVideoRecorderSourceState.eIntState = VIDEO_RECORDER_SOURCE_INIT_COMPLETE_BUFF;
            u4Line = __LINE__;
        }
        else if(_rVideoRecorderSourceState.eIntState == VIDEO_RECORDER_SOURCE_INIT_RECV_IDLE_CMD)
        {
            _rVideoRecorderSourceState.eIntState = VIDEO_RECORDER_SOURCE_IDLE;
            _rVideoRecorderSourceState.u4CurrInterval = 1;
            u4Line = __LINE__;
        }
        else if (_rVideoRecorderSourceState.eIntState == VIDEO_RECORDER_SOURCE_IDLE)
        {
            drv_trace0(TRACE_GROUP_10, VREC_SOURCE_REINIT_USE_BUFFER);
        }
        else
        {
            ASSERT(0);
        }
        RestoreIRQMask(u4Mask);
        drv_trace2(TRACE_GROUP_10, VREC_SOURCE_CHANGE_STATE, _rVideoRecorderSourceState.eIntState, u4Line);
        if ((_rVideoRecorderSourceState.eIntState == VIDEO_RECORDER_SOURCE_IDLE) &&
            (_rVideoRecorderSourceState.rCommState.eState != VIDEO_STATE_IDLE))
        {
            VideoCommChangeState(&_rVideoRecorderSourceState.rCommState, VIDEO_STATE_IDLE);
            drv_trace0(TRACE_GROUP_10, VREC_SOURCE_CHANGE_IDLE);
        }
    }
    return eError;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static VIDEO_ERROR_TYPE_T _VideoRecorderSourceEmptyThisBuffer(VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    ASSERT(0);

    return eError;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static VIDEO_ERROR_TYPE_T _VideoRecorderSourceFillThisBuffer(VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    //only for checking
    if(_rVideoRecorderSourceState.u4DataPortIdx != prBuffHeader->u4OutputPort)
    {
        ASSERT(0);
    }
    if(_rVideoRecorderSourceState.u4DataPortConnectedIdx != prBuffHeader->u4InputPort)
    {
        ASSERT(0);
    }

    // encoder has complete the buffer usage
    drv_trace2(TRACE_GROUP_10, VREC_SOURCE_FILL_BUFFER, (kal_uint32)prBuffHeader->pu1Buffer, (kal_uint32)prBuffHeader->u8TimeStamp);
    video_dbg_trace(VIDEO_DBG_OWNER_ENCSRC, VIDEO_DBG_ENCSRC_ENCODER_RETURN_BUFFER, (kal_uint32)prBuffHeader->pu1Buffer);
    _VideoRecorderEncodeDoneSourceBuffer(prBuffHeader->pu1Buffer);

    return eError;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static VIDEO_ERROR_TYPE_T _VideoRecorderSourceSetCallbacks(VIDEO_CALLBACK_TYPE_T *prCallback)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    drv_trace0(TRACE_GROUP_10, VREC_SOURCE_SET_CALLBACK);
    eError = VideoCommSetCallbacks(&_rVideoRecorderSourceState.rCommState, prCallback);

    return eError;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static VIDEO_ERROR_TYPE_T _VideoRecorderSourceDeInit(void)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    drv_trace0(TRACE_GROUP_10, VREC_SOURCE_DEINIT);
    eError = VideoCommDeInit(&_rVideoRecorderSourceState.rCommState);

    VideoFreeMutex(MUTEX_USER_RECORDER_SOURCE, _rVideoRecorderSourceState.rCommState.eMutex);

    // DclSGPT_Close(&_rVideoRecorderSourceState.rGptHandle);  // Do not close GPT unless it is opened again at initialization.

    return eError;
}


/******************************************************************************
* Source component
******************************************************************************/
const static VIDEO_COMPONENT_TYPE_T _rVideoRecorderSourceComp =
{
    _VideoRecorderSourceInit,
    _VideoRecorderSourceSendCommand,
    _VideoRecorderSourceGetParameter,
    _VideoRecorderSourceSetParameter,
    _VideoRecorderSourceUseBuffer,
    _VideoRecorderSourceEmptyThisBuffer,
    _VideoRecorderSourceFillThisBuffer,
    _VideoRecorderSourceSetCallbacks,
    _VideoRecorderSourceDeInit
};


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
VIDEO_COMPONENT_TYPE_T* GetVideoRecorderSourceHandle(VIDEO_RECORDER_SOURCE_TYPE_T eType,
        VIDEO_EXTMEM_HANDLER_T *prExtMemInfo)
{
    VIDEO_COMPONENT_TYPE_T *prVideoRecorderSourceComp = NULL;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    switch(eType)
    {
    case VIDEO_RECORDER_SOURCE_COMM:
        prVideoRecorderSourceComp = (VIDEO_COMPONENT_TYPE_T*)&_rVideoRecorderSourceComp;
        break;

    default:
        break;
    }

    _rVideoRecorderSourceState.prExtMemInfo = prExtMemInfo;

    // FIXME: Call pfnInit() when changing to INIT state.
    if (prVideoRecorderSourceComp != NULL)
    {
        eError = prVideoRecorderSourceComp->pfnInit();
        if (eError != VIDEO_ERROR_NONE)
        {
            prVideoRecorderSourceComp = NULL;
        }
    }

    return prVideoRecorderSourceComp;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
VIDEO_ERROR_TYPE_T ReleaseVideoRecorderSourceHandle(VIDEO_COMPONENT_TYPE_T *prHandle)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    if(prHandle == NULL)
    {
        ASSERT(0);
    }
    else
    {
        eError = prHandle->pfnDeInit();
    }
    return eError;
}


/******************************************************************************
* The IDP invokes this function to get a buffer for storing the YUV data of a
* frame.  When this function is called again by IDP, it implies that the last
* buffer given to IDP has been written successfully with the data of a frame.
*
* Context: xxx
*
* Side effect: variables related to buffer management
******************************************************************************/
MPL_BUFFER_INFO_T VideoRecorderGetSourceBuffer(void)
{
    VIDEO_RECORDER_INPUT_BUFFER_T* const prInBuff = &_rVideoRecorderSourceState.rInputBuffer;
    kal_uint8 *pu1BuffAddr = NULL;
    MPL_BUFFER_INFO_T rBufferInfo;

    if (_rVideoRecorderSourceState.fgGetSourceBuffer == KAL_TRUE)
    {
        ASSERT(0);
    }
    _rVideoRecorderSourceState.fgGetSourceBuffer = KAL_TRUE;

    //IDP use this function to get buffer
    if ((VideoCommGetState(&_rVideoRecorderSourceState.rCommState) == VIDEO_STATE_IDLE) ||
        (VideoCommGetState(&_rVideoRecorderSourceState.rCommState) == VIDEO_STATE_STOP))
    {
        pu1BuffAddr = prInBuff->pu1BuffAddr[prInBuff->u4DummyIdx];
        drv_trace1(TRACE_GROUP_10, VREC_SOURCE_GET_BUFFER_IN_STOP, (kal_uint32)pu1BuffAddr);
    }
    else if (VideoCommGetState(&_rVideoRecorderSourceState.rCommState) == VIDEO_STATE_RUN)
    {
        if ((_rVideoRecorderSourceState.eIntState != VIDEO_RECORDER_SOURCE_PRE_YUV_RUN) &&
            (_rVideoRecorderSourceState.eIntState != VIDEO_RECORDER_SOURCE_YUV_RUN))
        {
            _rVideoRecorderSourceState.eIntState = VIDEO_RECORDER_SOURCE_RUN;
        }
        else
        {
            _rVideoRecorderSourceState.eIntState = VIDEO_RECORDER_SOURCE_YUV_RUN;
        }
        drv_trace2(TRACE_GROUP_10, VREC_SOURCE_CHANGE_STATE, _rVideoRecorderSourceState.eIntState, __LINE__);

        if ((_rVideoRecorderSourceState.u4CurrInterval % _rVideoRecorderSourceState.u4KeepInterval) == 0)
        {
            _VRSRC_LABEL_LOG("SBK"); // keep the buffer
            if ((((prInBuff->u4YUVWriteIdx + 0) % prInBuff->u4DummyIdx) == prInBuff->u4ReadIdx) &&
                (! ((prInBuff->u4ReadIdx == prInBuff->u4WriteIdx) &&
                    (prInBuff->u4YUVReadIdx == prInBuff->u4YUVWriteIdx) &&
                    (prInBuff->u4ReadIdx == prInBuff->u4YUVReadIdx) &&
                    (prInBuff->u1BuffStatus[prInBuff->u4YUVWriteIdx] == VRSRC_BUFFER_STATUS_FREE)))
        	  )
            {
                // full, return dummy one
                pu1BuffAddr = prInBuff->pu1BuffAddr[prInBuff->u4DummyIdx];
                // this frame will be dropped
                drv_trace4(TRACE_GROUP_10, VREC_SOURCE_GET_BUFFER_IN_RUN_WARNING,
                    (kal_uint32)pu1BuffAddr, prInBuff->u4YUVWriteIdx,
                    prInBuff->u4ReadIdx, prInBuff->u4DummyIdx);
                _VRSRC_LABEL_LOG("SBD");
                _rVideoRecorderSourceState.u4MaxInsufficientFrames++;
            }
            else
            {
                pu1BuffAddr = prInBuff->pu1BuffAddr[prInBuff->u4YUVWriteIdx];
                if (prInBuff->u1BuffStatus[prInBuff->u4YUVWriteIdx] != VRSRC_BUFFER_STATUS_FREE)
                {
                    ASSERT(0);
                }
                drv_trace2(TRACE_GROUP_10, VREC_SOURCE_GET_BUFFER_IN_RUN, (kal_uint32)pu1BuffAddr, prInBuff->u4YUVWriteIdx);
                prInBuff->u1BuffStatus[prInBuff->u4YUVWriteIdx] = VRSRC_BUFFER_STATUS_IN_USE_WITHOUT_TIMESTAMP;
                prInBuff->u4YUVWriteIdx = (prInBuff->u4YUVWriteIdx + 1) % prInBuff->u4DummyIdx;
                if (_rVideoRecorderSourceState.u4MaxInsufficientFrames != 0)
                {
                    drv_trace1(TRACE_GROUP_10, VREC_SOURCE_MAX_INSUFFICIENT_FRAMES, _rVideoRecorderSourceState.u4MaxInsufficientFrames);
                    _rVideoRecorderSourceState.u4MaxInsufficientFrames = 0;
                }
            }
        }
        else
        {
            _VRSRC_LABEL_LOG("SBI"); // ignore the buffer
            pu1BuffAddr = prInBuff->pu1BuffAddr[prInBuff->u4DummyIdx];
        }
        _rVideoRecorderSourceState.u4CurrInterval = (_rVideoRecorderSourceState.u4CurrInterval + 1) % _rVideoRecorderSourceState.u4KeepInterval;
    }
    else
    {
        ASSERT(0);
    }

    _VideoRecorderSourceBufferTag(prInBuff->u4YUVWriteIdx, prInBuff->u4ReadIdx, prInBuff->u4DummyIdx);
    video_dbg_trace(VIDEO_DBG_OWNER_ENCSRC, VIDEO_DBG_ENCSRC_IDP_GET_BUFFER, (kal_uint32)pu1BuffAddr);

    _rVideoRecorderSourceState.fgGetSourceBuffer = KAL_FALSE;

    kal_mem_set((void*)&rBufferInfo, 0, sizeof(rBufferInfo));
    rBufferInfo.pu1Address = pu1BuffAddr;
    // rBufferInfo.u4Size = _rVideoRecorderSourceState.rInputBuffer.u4EachBuffSize;

    return rBufferInfo;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
void VideoRecorderCompleteSourceBuffer(MPL_BUFFER_INFO_T rBufferInfo)
{
    VIDEO_RECORDER_INPUT_BUFFER_T* const prInBuff = &_rVideoRecorderSourceState.rInputBuffer;
    kal_uint8 * const pu1BuffAddr = rBufferInfo.pu1Address;
    kal_bool fgEncode = KAL_TRUE;
    static kal_bool _fgTrespass = KAL_FALSE;

    if (_fgTrespass == KAL_FALSE)
    {
        _fgTrespass = KAL_TRUE;
    }
    else
    {
        ASSERT(0);
    }

    // encode previous buffer
    if (pu1BuffAddr == NULL)
    {
        ASSERT(0);
    }

    video_dbg_trace(VIDEO_DBG_OWNER_ENCSRC, VIDEO_DBG_ENCSRC_IDP_RETURN_BUFFER, (kal_uint32)pu1BuffAddr);

    if (pu1BuffAddr != prInBuff->pu1BuffAddr[prInBuff->u4DummyIdx])
    {
        if (pu1BuffAddr != prInBuff->pu1BuffAddr[prInBuff->u4YUVReadIdx])
        {
            // This assertion implies that IDP/MDP does not return buffer in correct order.
            ASSERT(0);
        }
        _VideoRecorderSource_AttachTimeStamp(prInBuff->u4YUVReadIdx);
// #ifdef __VE_ENCODE_WITH_MOTION_SENSOR_SUPPORT__
        // The following if-else block is for motion sensor.
        if (rBufferInfo.eStatus == MPL_OK)
        {
            prInBuff->u1EncodeFlag[prInBuff->u4YUVReadIdx] = VRSRC_BUFFER_STATUS_VALID;
        }
        else /*** if (rBufferInfo.eStatus == MPL_INVALID_FRAME) ***/
        {
            drv_trace2(TRACE_GROUP_10, VREC_SOURCE_INVALID_FRAME, prInBuff->u4YUVReadIdx, (kal_uint32)pu1BuffAddr);
            prInBuff->u1EncodeFlag[prInBuff->u4YUVReadIdx] = VRSRC_BUFFER_STATUS_INVALID;
        }
// #endif  // __VE_ENCODE_WITH_MOTION_SENSOR_SUPPORT__
        prInBuff->u4YUVReadIdx = (prInBuff->u4YUVReadIdx + 1) % prInBuff->u4DummyIdx;
    }

    if ((_rVideoRecorderSourceState.eIntState == VIDEO_RECORDER_SOURCE_RUN) ||
        (_rVideoRecorderSourceState.eIntState == VIDEO_RECORDER_SOURCE_YUV_RUN))
    {
        while (prInBuff->u4WriteIdx != prInBuff->u4YUVReadIdx)
        {
            // For copying icon image in VT.
            if (_rVideoRecorderSourceState.eIntState == VIDEO_RECORDER_SOURCE_YUV_RUN)
            {
                // For debugging...
                drv_trace8(TRACE_GROUP_9, VREC_SOURCE_COPY_FROM_DUMMY,
                    prInBuff->u4YUVReadIdx, prInBuff->u4YUVWriteIdx,
                    prInBuff->u4ReadIdx, prInBuff->u4WriteIdx,
                    (kal_uint32)prInBuff->pu1BuffAddr[prInBuff->u4WriteIdx],
                    (kal_uint32)prInBuff->pu1BuffAddr[prInBuff->u4DummyIdx],
                    (kal_uint32)_rVideoRecorderSourceState.rCommState.eState,
                    (kal_uint32)_rVideoRecorderSourceState.eIntState);
                kal_mem_cpy((void*)prInBuff->pu1BuffAddr[prInBuff->u4WriteIdx],
                    (void*)prInBuff->pu1BuffAddr[prInBuff->u4DummyIdx],
                    prInBuff->u4EachBuffSize);
            }
            // encode all queued buffers
            //drv_trace4(TRACE_GROUP_10, VREC_SOURCE_ENCODE_BUFFER_WARNING, prInBuff->u4ReadIdx,
            //                prInBuff->u4WriteIdx, prInBuff->u4YUVIdx, prInBuff->u4DummyIdx);
            drv_trace1(TRACE_GROUP_10, VREC_SOURCE_ENCODE, (kal_uint32)prInBuff->pu1BuffAddr[prInBuff->u4WriteIdx]);
            fgEncode = _VideoRecorderEncodeSourceBuffer(prInBuff->u4WriteIdx);
            if (fgEncode == KAL_TRUE)
            {
                prInBuff->u4WriteIdx = (prInBuff->u4WriteIdx + 1) % prInBuff->u4DummyIdx;
            }
            else
            {
                break;
            }
        }
    }

    _fgTrespass = KAL_FALSE;
}


#endif  // defined(__VE_MPEG4_ENC_SUPPORT__) || defined(__VE_H264_ENC_SW_SUPPORT__) || defined(__VE_AVI_ENC_SUPPORT__)


#else  // !defined(__VE_SLIM_RECORDER_SOURCE__)


/******************************************************************************
*******************************************************************************
* Here begins the slim version of Source.
*******************************************************************************
******************************************************************************/


#if defined(__VE_MPEG4_ENC_SUPPORT__) || defined(__VE_AVI_ENC_SUPPORT__)

#include "dcl.h"                            // for new HAL GPT of type DCL_HANDLE
#include "drv_comm.h"                       // for drv_trace1(), drv_trace8()
#include "vcodec_v2_trc.h"
#include "video_types_v2.h"
#include "video_recorder_source_component_v2.h"
#include "kal_trace.h"
#include "video_dbg_v2.h"
#include "video_comm_component_v2.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "video_recorder_source_component_if_v2.h"
#include "video_buffer_management_v2.h"
#include "visualhisr.h"                     // for VISUAL_Register_HISR();
#include "video_recorder_clock_utility_if_v2.h"


#define VRSRC_GET_STATE()           VideoCommGetState(&_rVrsrcMgr.rCommState)
#define VRSRC_EVENT_HISR_FINISH 0x00000001

#if 1  // [MAUI_02996107]
static kal_uint64 _u8LastTimeStamp;
#endif  // [MAUI_02996107]

/******************************************************************************
*
******************************************************************************/
static VRSRC_MANAGER_T _rVrsrcMgr;


/******************************************************************************
*
* Context: MED
*
* Side effect:
******************************************************************************/
static void _VRSRC_ResetFrameBuffer(void)
{
    VRSRC_FRAME_BUFFER_T* const prFrameBuffer = &_rVrsrcMgr.rFrameBuffer;

    // Consider after changing to IDLE state. IDP still returns all frame buffer.

    kal_mem_set(prFrameBuffer->au1Status, 0, VRSRC_MAX_NUM_OF_FRAME_BUFFER*sizeof(*(prFrameBuffer->au1Status)));
    //kal_mem_set(prFrameBuffer->au1RefCount, 0, VRSRC_MAX_NUM_OF_FRAME_BUFFER*sizeof(*(prFrameBuffer->au1RefCount)));
    //prFrameBuffer->u4IdxIdpGet = 0;
    //prFrameBuffer->u4IdxIdpRet = 0;
    //prFrameBuffer->u4PeakRefCount = 0;
    prFrameBuffer->u4Detention = 0;
    prFrameBuffer->u4IdxEncRet = prFrameBuffer->u4IdxIdpGet;
    //kal_mem_set(prFrameBuffer, 0, sizeof(*prFrameBuffer));
    // drv_trace0(TRACE_GROUP_10, VREC_SOURCE_SLIM_RESET_FRAME_BUFFER);
}


/******************************************************************************
* This function is used to configure frame buffer passed from Encoder.
*
* Context: V2DEC
*
* Side effect:
******************************************************************************/
static void _VRSRC_AddFrameBuffer(kal_uint8 *pu1Address, kal_uint32 u4BuffSize)
{
    VRSRC_FRAME_BUFFER_T* const prFrameBuffer = &_rVrsrcMgr.rFrameBuffer;
    const kal_uint32 u4TotalBuffer = prFrameBuffer->u4TotalBuffer;

    if (u4TotalBuffer >= VRSRC_MAX_NUM_OF_FRAME_BUFFER)
    {
        // Do not assert here because Encoder pass may "slice" its memory
        // into more slices than what Source can accommodate.
        return;
    }
    if (prFrameBuffer->u4EachBufferSize == 0)
    {
        prFrameBuffer->u4EachBufferSize = u4BuffSize;
    }
    if (prFrameBuffer->u4EachBufferSize != u4BuffSize)
    {
        ASSERT(0);
    }

    prFrameBuffer->apu1Address[u4TotalBuffer] = pu1Address;
    prFrameBuffer->u4TotalBuffer = u4TotalBuffer + 1;

    drv_trace2(TRACE_GROUP_10, VREC_SOURCE_SLIM_BUFFER_CONFIG,
        (kal_uint32)pu1Address, prFrameBuffer->u4TotalBuffer);
}


/******************************************************************************
* If the STOP command has been received and the internal state has changed
* to STOP state, send EOF to Encoder.
*
* Context: HISR
*
* Side effect:
******************************************************************************/
static kal_bool _VRSRC_DoSendEofToEncoder(void)
{
    PFN_EMPTY_THIS_BUFFER_T const pfnEncoderEmptyThisBuffer = _rVrsrcMgr.pfnEncoderEmptyThisBuffer;
    VIDEO_BUFFERHEADER_TYPE_T rBufferHeader;

    kal_mem_set((void*)&rBufferHeader, 0, sizeof(rBufferHeader));
    rBufferHeader.u4OutputPort = _rVrsrcMgr.u4DataPortIdx;
    rBufferHeader.u4InputPort = _rVrsrcMgr.u4DataPortConnectedIdx;
    rBufferHeader.eFlags = VIDEO_BUFFERFLAG_EOF;

    if (pfnEncoderEmptyThisBuffer(&rBufferHeader) != VIDEO_ERROR_NONE)
    {
        drv_trace0(TRACE_GROUP_10, VREC_SOURCE_ENCODER_REJECTS_EOF);
        return KAL_FALSE;
    }
    else
    {
        drv_trace0(TRACE_GROUP_10, VREC_SOURCE_ENCODER_ACCEPTS_EOF);
        return KAL_TRUE;
    }
}


/******************************************************************************
*
* Context: HISR
*
* Side effect:
******************************************************************************/
static void _VRSRC_DoSendFrameBufferToEncoder(void)
{
    kal_uint64 u8TimeStamp;
    PFN_EMPTY_THIS_BUFFER_T const pfnEncoderEmptyThisBuffer = _rVrsrcMgr.pfnEncoderEmptyThisBuffer;
    VRSRC_FRAME_BUFFER_T* const prFrameBuffer = &_rVrsrcMgr.rFrameBuffer;
    // const kal_uint32 u4IdxIdpRet = prFrameBuffer->u4IdxIdpRet;
    const kal_uint32 u4IdxEncGet = (prFrameBuffer->u4IdxEncRet + prFrameBuffer->u4Detention)%prFrameBuffer->u4TotalBuffer;
    kal_uint8 *pu1Address = NULL;
    VIDEO_ERROR_TYPE_T eVideoError;
    VIDEO_BUFFERHEADER_TYPE_T rBufferHeader;
    kal_bool fgResult;

    pu1Address = prFrameBuffer->apu1Address[u4IdxEncGet];
    u8TimeStamp = prFrameBuffer->au8TimeStamp[u4IdxEncGet];

    // Call encoder's EmptyThisBuffer() in image DMA HISR.
    rBufferHeader.u4OutputPort = _rVrsrcMgr.u4DataPortIdx;
    rBufferHeader.u4InputPort = _rVrsrcMgr.u4DataPortConnectedIdx;
    rBufferHeader.u8TimeStamp = u8TimeStamp;
    rBufferHeader.pu1Buffer = pu1Address;
    rBufferHeader.u4BuffSize = _rVrsrcMgr.rFrameBuffer.u4EachBufferSize;
    rBufferHeader.eFlags = VIDEO_BUFFERFLAG_NONE;

    eVideoError = pfnEncoderEmptyThisBuffer(&rBufferHeader);
    if (eVideoError == VIDEO_ERROR_NONE)
    {
        prFrameBuffer->u4Detention++;
        video_dbg_trace(VIDEO_DBG_OWNER_ENCSRC, VIDEO_DBG_ENCSRC_ENCODER_GET_BUFFER,
            (kal_uint32)pu1Address);
        fgResult = KAL_TRUE;
    }
    else
    {
        fgResult = KAL_FALSE;
    }

    drv_trace4(TRACE_GROUP_10, VREC_SOURCE_SLIM_SEND_FRAME_BUFFER_TO_ENCODER,
        (kal_uint32)fgResult, (kal_uint32)pu1Address, u4IdxEncGet,
        (kal_uint32)u8TimeStamp);
}


/******************************************************************************
*
* Context: HISR
*
* Side effect:
******************************************************************************/
static void _VRSRC_TryToSendFrameBufferToEncoder(void)
{
    VRSRC_FRAME_BUFFER_T* const prFrameBuffer = &_rVrsrcMgr.rFrameBuffer;
    const kal_uint32 u4TotalBuffer = prFrameBuffer->u4TotalBuffer;
    const kal_uint32 u4IdxIdpGet = prFrameBuffer->u4IdxIdpGet;
    const kal_uint32 u4IdxIdpRet = prFrameBuffer->u4IdxIdpRet;
    kal_uint32 u4IdxEncGet = (prFrameBuffer->u4IdxEncRet + prFrameBuffer->u4Detention)%u4TotalBuffer;
    kal_bool fgResult;

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else
    if (prFrameBuffer->u4Detention >= 2)
    {
        // HW encoder pipleline 1 buffer keep case.
        // Encoder starts to output bitstream after 2 frames feeding
        return;
    }
    #endif

    if (u4IdxEncGet != u4IdxIdpRet)
    {
        // The value of reference count is implied in the status flag.
        switch (prFrameBuffer->au1Status[u4IdxEncGet])
        {
        case VRSRC_BUFFER_STATUS_JEWEL:
            _VRSRC_DoSendFrameBufferToEncoder();
            break;

        case VRSRC_BUFFER_STATUS_JUNK:
            if(prFrameBuffer->u4Detention == 0)
            {
            do {
                // EncGet needs to catch up IdpRet as much as possible.
                kal_uint32 u4DiscardedIdx = u4IdxEncGet;
                u4IdxEncGet = (u4IdxEncGet + 1) % u4TotalBuffer;
                    prFrameBuffer->u4IdxEncRet = u4IdxEncGet;
                drv_trace4(TRACE_GROUP_10, VREC_SOURCE_SLIM_DISCARD_JUNK_BUFFER,
                    u4IdxIdpGet, u4IdxIdpRet, u4IdxEncGet, u4DiscardedIdx);
            } while (u4IdxEncGet != u4IdxIdpRet &&
                prFrameBuffer->au1Status[u4IdxEncGet] == VRSRC_BUFFER_STATUS_JUNK);
            }
            break;

        default:
            break;
        }
    }
    else
    {
        switch (_rVrsrcMgr.eEnding)
        {
        case VRSRC_ENDING_GOT_STOP_BUT_EOF_NOT_SENT:
            fgResult = _VRSRC_DoSendEofToEncoder();
            if (fgResult == KAL_TRUE)
            {
                _rVrsrcMgr.eEnding = VRSRC_ENDING_GOT_STOP_AND_EOF_SENT;
            }
            break;

        default:
            // Do nothing.
            break;
        }
    }
}


/******************************************************************************
* This function performs basic check, print some log, and then return the
* specified YUV buffer back to Source.
*
* Context: HISR
*
* Side effect:
******************************************************************************/
static void _VRSRC_EncoderReturnsFrameBuffer(kal_uint8* pu1Address)
{
    kal_uint64 u8TimeStamp;
    VRSRC_FRAME_BUFFER_T* const prFrameBuffer = &_rVrsrcMgr.rFrameBuffer;
    const kal_uint32 u4TotalBuffer = prFrameBuffer->u4TotalBuffer;
    const kal_uint32 u4IdxEncRet = prFrameBuffer->u4IdxEncRet;

    if ((pu1Address != prFrameBuffer->apu1Address[u4IdxEncRet]) ||
        (prFrameBuffer->au1Status[u4IdxEncRet] != VRSRC_BUFFER_STATUS_JEWEL))
    {
        ASSERT(0);
    }

    u8TimeStamp = prFrameBuffer->au8TimeStamp[u4IdxEncRet];

    video_dbg_trace(VIDEO_DBG_OWNER_ENCSRC, VIDEO_DBG_ENCSRC_ENCODER_RETURN_BUFFER,
        (kal_uint32)pu1Address);
    drv_trace2(TRACE_GROUP_10, VREC_SOURCE_SLIM_FINISH_USING_BUFFER,
        (kal_uint32)pu1Address, (kal_uint32)u8TimeStamp);

    prFrameBuffer->au1Status[u4IdxEncRet] = VRSRC_BUFFER_STATUS_FREE;
    prFrameBuffer->u4IdxEncRet = (u4IdxEncRet + 1) % u4TotalBuffer;
    prFrameBuffer->u4Detention--;
}

#ifdef __VE_VIDEO_VT_SUPPORT__
/******************************************************************************
*
* Context: Timer timeout HISR
*
* Side effect:
******************************************************************************/
static void _VRSRC_TimeoutHdlr(void *pTimerParam)
{
    MPL_BUFFER_INFO_T rBufferInfo;
    SGPT_CTRL_START_T rGptInfo;

    if(VideoCommGetState(&_rVrsrcMgr.rCommState) != VIDEO_STATE_RUN)
    {
        ASSERT(0);
    }

    kal_mem_set((void*)&rBufferInfo, 0, sizeof(rBufferInfo));

    // get buffer
    rBufferInfo = VideoRecorderGetSourceBuffer();

    // start GPT again
    kal_mem_set((void*)&rGptInfo, 0, sizeof(rGptInfo));
    rGptInfo.pfCallback = _VRSRC_TimeoutHdlr;
    rGptInfo.u2Tick = (DCL_UINT16)_rVrsrcMgr.u4YUVInterval;
    // rGptInfo.vPara = NULL;
    DclSGPT_Control(_rVrsrcMgr.rGptHandle, SGPT_CMD_START, (DCL_CTRL_DATA_T*)&rGptInfo);

    rBufferInfo.eStatus = MPL_OK;
    VideoRecorderCompleteSourceBuffer(rBufferInfo);
}

#endif

/******************************************************************************
*
* Context: HISR
*
* Side effect:
******************************************************************************/
static void _VRSRC_FillThisBufferInHisr(void)
{
    kal_uint8 *pu1BufferAddress = _rVrsrcMgr.pu1BufferAddressFromEncoder;
    VRSRC_FRAME_BUFFER_T* const prFrameBuffer = &_rVrsrcMgr.rFrameBuffer;
    const kal_uint32 u4IdxIdpGet = prFrameBuffer->u4IdxIdpGet;
    const kal_uint32 u4IdxIdpRet = prFrameBuffer->u4IdxIdpRet;
    const kal_uint32 u4TotalBuffer = prFrameBuffer->u4TotalBuffer;
    const kal_uint32 u4NextIdxIdpGet = (u4IdxIdpGet + 1) % u4TotalBuffer;
    const kal_uint32 u4NextIdxIdpRet = (u4IdxIdpRet + 1) % u4TotalBuffer;
    kal_uint32 u4IdxEncRet;

    _VRSRC_EncoderReturnsFrameBuffer(pu1BufferAddress);
    _VRSRC_TryToSendFrameBufferToEncoder();

    u4IdxEncRet = prFrameBuffer->u4IdxEncRet;
    // To handle if MDP did not get new frame case
    if (_rVrsrcMgr.u4MaxInsufficientFrames != 0)
    {
        // Encoder returned frame. There should be frame for IDP to get.
        ASSERT(u4NextIdxIdpGet != u4IdxEncRet);

        // u4IdxIdpRet is not moving forward in VideoRecorderCompleteSourceBuffer
        // if u4IdxIdpGet is not leading u4IdxIdpRet. (MDP will get the same frame for full case)
        // But in this case, we move u4IdxIdpGet.
        if ((prFrameBuffer->au1RefCount[u4IdxIdpRet] == 0) &&
            (u4IdxIdpGet == u4IdxIdpRet))
        {
            prFrameBuffer->u4IdxIdpRet = u4NextIdxIdpRet;
        }
        prFrameBuffer->u4IdxIdpGet = u4NextIdxIdpGet;

        drv_trace4(TRACE_GROUP_10, VREC_SOURCE_SLIM_ENCODER_RET_EARLY,
            prFrameBuffer->u4IdxIdpGet, u4IdxIdpRet, u4IdxEncRet, _rVrsrcMgr.u4MaxInsufficientFrames);

        _rVrsrcMgr.u4MaxInsufficientFrames = 0;
    }

    kal_set_eg_events(_rVrsrcMgr.eActivateSrcHisrEvent, VRSRC_EVENT_HISR_FINISH, KAL_OR);
}


/******************************************************************************
*
* Context: HISR
*
* Side effect:
******************************************************************************/
__inline static void _VRSRC_AttachTimeStamp(kal_uint32 u4IdxIdpRet)
{
    kal_uint64 u8TimeStamp;
    VRSRC_FRAME_BUFFER_T* const prFrameBuffer = &_rVrsrcMgr.rFrameBuffer;

    VRCLK_GetCurrentTime(&u8TimeStamp);
    drv_trace2(TRACE_GROUP_10, VREC_SOURCE_GET_TIME_STAMP,
        (kal_uint32)((u8TimeStamp >> 32) & 0xFFFFFFFF),
        (kal_uint32)(u8TimeStamp & 0xFFFFFFFF));

#if 1  // [MAUI_02996107]
    if (_u8LastTimeStamp < u8TimeStamp)
    {
        _u8LastTimeStamp = u8TimeStamp;
    }
    else
    {
        drv_trace2(TRACE_GROUP_10, VREC_SOURCE_CHANGE_TIME_STAMP,
            (kal_uint32)u8TimeStamp, (kal_uint32)_u8LastTimeStamp);
        u8TimeStamp = _u8LastTimeStamp;
    }
#endif  // [MAUI_02996107]

    prFrameBuffer->au8TimeStamp[u4IdxIdpRet] = u8TimeStamp;
}


/******************************************************************************
* Store information of connected modules/components.
*
* Context: MED
*
* Side effect:
******************************************************************************/
__inline static void _VRSRC_StoreInfoOfConnectedModules(void)
{
    VIDEO_COMPONENT_PARAM_T *prDataPortComp;

    // Store Encoder's information.
    _rVrsrcMgr.u4DataPortIdx = VideoCommGetOutputPortIndex(&_rVrsrcMgr.rCommState, VIDEO_PORT_VIDEO_DATA);
    prDataPortComp = VideoCommGetOutputComp(&_rVrsrcMgr.rCommState, _rVrsrcMgr.u4DataPortIdx);
    if (prDataPortComp == NULL)
    {
        ASSERT(0);
    }
    _rVrsrcMgr.pfnEncoderEmptyThisBuffer = prDataPortComp->prComp->pfnEmptyThisBuffer;
    _rVrsrcMgr.u4DataPortConnectedIdx = prDataPortComp->u4PortIndex;
}


/******************************************************************************
*
* Context: MED
*
* Side effect:
******************************************************************************/
static void _VRSRC_ProcessIdleCommand(void)
{
    VideoCommClrAllQ(&_rVrsrcMgr.rCommState);

    _VRSRC_StoreInfoOfConnectedModules();

#ifdef __VE_VIDEO_VT_SUPPORT__
    _rVrsrcMgr.pu1YUVBuffer = NULL;
    _rVrsrcMgr.u4YUVInterval = 0;
#endif
    _VRSRC_ResetFrameBuffer();

    if (_rVrsrcMgr.fgFrameBufferConfigured == KAL_TRUE)
    {
        VideoCommChangeState(&_rVrsrcMgr.rCommState, VIDEO_STATE_IDLE);
        drv_trace0(TRACE_GROUP_10, VREC_SOURCE_CHANGE_IDLE);
    }
    else
    {
        _rVrsrcMgr.fgSetToIdleState = KAL_TRUE;
    }
}


/******************************************************************************
*
* Context: MED
*
* Side effect:
******************************************************************************/
static void _VRSRC_ProcessRunCommand(void)
{
    _rVrsrcMgr.eEnding = VRSRC_ENDING_NONE;

#ifdef __VE_VIDEO_VT_SUPPORT__
    if ((_rVrsrcMgr.pu1YUVBuffer != NULL) &&
        (_rVrsrcMgr.u4YUVInterval != 0))
    {
        SGPT_CTRL_START_T rGptInfo;

        // start GPT
        kal_mem_set((void*)&rGptInfo, 0, sizeof(rGptInfo));
        rGptInfo.pfCallback = _VRSRC_TimeoutHdlr;
        rGptInfo.u2Tick = (DCL_UINT16)_rVrsrcMgr.u4YUVInterval;
        // rGptInfo.vPara = NULL;
        DclSGPT_Control(_rVrsrcMgr.rGptHandle, SGPT_CMD_START, (DCL_CTRL_DATA_T*)&rGptInfo);
    }
#endif

    VideoCommChangeState(&_rVrsrcMgr.rCommState, VIDEO_STATE_RUN);
}

/******************************************************************************
*
* Context: MED
*
* Side effect:
******************************************************************************/
static void _VRSRC_ProcessStopCommand(void)
{
#ifdef __VE_VIDEO_VT_SUPPORT__
    if ((_rVrsrcMgr.pu1YUVBuffer != NULL) &&
        (_rVrsrcMgr.u4YUVInterval != 0))
    {
        DclSGPT_Control(_rVrsrcMgr.rGptHandle, SGPT_CMD_STOP, NULL);
    }
#endif
    VideoCommChangeState(&_rVrsrcMgr.rCommState, VIDEO_STATE_STOP);
    // The next line must be located after Source enters STOP.
    _rVrsrcMgr.eEnding = VRSRC_ENDING_GOT_STOP_BUT_EOF_NOT_SENT;
}

/******************************************************************************
*
* Context: MED
*
* Side effect:
******************************************************************************/
static VIDEO_ERROR_TYPE_T _VRSRC_Init(void)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    VIDEO_PORT_CONFIG_T rOutputPort1, rOutputPort2;
    VIDEO_COMPONENT_INIT_T rInitConfig;
    kal_mutexid eMutex = VideoGetMutex(MUTEX_USER_RECORDER_SOURCE);
    kal_eventgrpid eEvenGrpId = VideoGetEventGroup(EVG_USER_RECORDER_SRC);
    VIDEO_EXTMEM_HANDLER_T *prExtMemInfo = _rVrsrcMgr.prExtMemInfo;  // backup
    #ifdef __VE_VIDEO_VT_SUPPORT__
    DCL_HANDLE rGptHandle = _rVrsrcMgr.rGptHandle;
    #endif

#if 1  // [MAUI_02996107]
    _u8LastTimeStamp = 0;
#endif  // [MAUI_02996107]

    // Note that Mutex will be cleared by the following kal_mem_set()!!!
    kal_mem_set((void*)&_rVrsrcMgr, 0, sizeof(_rVrsrcMgr));
    _rVrsrcMgr.rCommState.eMutex = eMutex;
    _rVrsrcMgr.prExtMemInfo = prExtMemInfo;  // restore
    _rVrsrcMgr.eActivateSrcHisrEvent = eEvenGrpId;

    // Connect to the Encoder component.
    rOutputPort1.ePortType = VIDEO_PORT_VIDEO_DATA;
    rOutputPort1.fgSupplier = KAL_FALSE;
    rOutputPort1.u4BuffSize = 0;

    // Clock has become a set of utility functions. Set port type to NONE.
    rOutputPort2.ePortType = VIDEO_PORT_NONE;
    rOutputPort2.fgSupplier = KAL_FALSE;
    rOutputPort2.u4BuffSize = 0;

    kal_mem_set((void*)&rInitConfig, 0, sizeof(rInitConfig));
    rInitConfig.prOutputPort1 = &rOutputPort1;
    rInitConfig.prOutputPort2 = &rOutputPort2;
    rInitConfig.prExtMemHdlr = _rVrsrcMgr.prExtMemInfo;
    rInitConfig.eMutex = eMutex;

    #ifdef __VE_VIDEO_VT_SUPPORT__
    _rVrsrcMgr.rGptHandle = rGptHandle;
    if (rGptHandle == NULL)
    {
        _rVrsrcMgr.rGptHandle = DclSGPT_Open(DCL_GPT_CB, FLAGS_NONE);
        if (_rVrsrcMgr.rGptHandle == DCL_HANDLE_INVALID)
        {
            ASSERT(0);
        }
    }
    #endif

    eError = VideoCommInit(&_rVrsrcMgr.rCommState, &rInitConfig, "VRSRC");
    if(eError != VIDEO_ERROR_NONE)
    {
        ASSERT(0);
    }

    //_VRSRC_ResetFrameBuffer();

    VISUAL_Register_HISR(VISUAL_RECORDER_SOURCE_HISR_ID, _VRSRC_FillThisBufferInHisr);

    drv_trace0(TRACE_GROUP_10, VREC_SOURCE_INIT);

    return eError;
}


/******************************************************************************
*
* Context: MED
*
* Side effect:
******************************************************************************/
static VIDEO_ERROR_TYPE_T _VRSRC_SendCommand(VIDEO_COMMAND_TYPE_T eCmd, kal_uint32 u4Param)
{
    VIDEO_STATE_TYPE_T eState = (VIDEO_STATE_TYPE_T)u4Param;

    _VRSRC_ASSERT_IF_NOT_EQUAL(eCmd, VIDEO_COMMAND_STATESET);

    drv_trace1(TRACE_GROUP_10, VREC_SOURCE_PROCESS_CMD, eState);
    video_dbg_trace(VIDEO_DBG_OWNER_ENCSRC, VIDEO_DBG_ENCSRC_SET_STATE,
        eState);

    switch (eState)
    {
    case VIDEO_STATE_INIT:
    case VIDEO_STATE_CLOSE:
        VideoCommChangeState(&_rVrsrcMgr.rCommState, eState);
        break;

    case VIDEO_STATE_IDLE:
        _VRSRC_ProcessIdleCommand();
        break;

    case VIDEO_STATE_RUN:
        _VRSRC_ProcessRunCommand();
        break;

    case VIDEO_STATE_STOP:
        _VRSRC_ProcessStopCommand();
        break;

    default:
        _VRSRC_ASSERT(0);
        break;
    }

    return VIDEO_ERROR_NONE;
}


/******************************************************************************
*
* Context: MED
*
* Side effect:
******************************************************************************/
static VIDEO_ERROR_TYPE_T _VRSRC_GetParameter(VIDEO_PARAM_TYPE_T eCmd, void *pvParam)
{
    switch (eCmd)
    {
    case VIDEO_PARAM_OUTPUT_BUFFER_PARAM:
        VideoCommGetOutputPortParam(&_rVrsrcMgr.rCommState, pvParam);
        break;

    case VIDEO_PARAM_INPUT_BUFFER_PARAM:
        VideoCommGetInputPortParam(&_rVrsrcMgr.rCommState, pvParam);
        break;

    default:
        _VRSRC_ASSERT(0);
        break;
    }

    return VIDEO_ERROR_NONE;
}


/******************************************************************************
*
* Context: MED
*
* Side effect:
******************************************************************************/
static VIDEO_ERROR_TYPE_T _VRSRC_SetParameter(VIDEO_PARAM_TYPE_T eCmd, void *pvParam)
{
    switch (eCmd)
    {
    case VIDEO_PARAM_OUTPUT_BUFFER_PARAM:
        VideoCommSetOutputPortParam(&_rVrsrcMgr.rCommState, pvParam);
        break;

    case VIDEO_PARAM_INPUT_BUFFER_PARAM:
        VideoCommSetInputPortParam(&_rVrsrcMgr.rCommState, pvParam);
        break;

#ifdef __VE_VIDEO_VT_SUPPORT__
    case VIDEO_PARAM_RECODER_SOURCE_YUV_BUFFER:
        {
            kal_uint8 *pu1Param;
            pu1Param = (kal_uint8*)pvParam;
            _rVrsrcMgr.pu1YUVBuffer = pu1Param;  // FIXME: No size information!
        }
        break;

    case VIDEO_PARAM_RECODER_SOURCE_YUV_INTERVAL:
        {
            kal_uint32 *pu4Param;
            pu4Param = (kal_uint32*)pvParam;
            _rVrsrcMgr.u4YUVInterval = (*pu4Param) / 10000;  // Convert time in 1us to time in 10ms.
            if(_rVrsrcMgr.u4YUVInterval == 0)
            {
                ASSERT(0);
            }
        }
        break;

    case VIDEO_PARAM_RECORDER_SOURCE_STOP_INSTANTLY:
        // Need to to anything?
        break;
#endif

    default:
        _VRSRC_ASSERT(0);
        break;
    }

    return VIDEO_ERROR_NONE;
}


/******************************************************************************
*
* Context: V2DEC
*
* Side effect:
******************************************************************************/
static VIDEO_ERROR_TYPE_T _VRSRC_UseBuffer(kal_uint8* pu1Buff, kal_uint32 u4Size)
{
    drv_trace2(TRACE_GROUP_10, VREC_SOURCE_USE_BUFFER, (kal_uint32)pu1Buff, u4Size);

    if (u4Size != 0)
    {
        _VRSRC_AddFrameBuffer(pu1Buff, u4Size);
    }
    else
    {
        VRSRC_FRAME_BUFFER_T* const prFrameBuffer = &_rVrsrcMgr.rFrameBuffer;
        if (prFrameBuffer->u4TotalBuffer < VRSRC_MIN_NUM_OF_FRAME_BUFFER)
        {
            ASSERT(0);
        }

        _rVrsrcMgr.fgFrameBufferConfigured = KAL_TRUE;
        if ((VRSRC_GET_STATE() != VIDEO_STATE_IDLE) &&
            (_rVrsrcMgr.fgSetToIdleState == KAL_TRUE))
        {
            VideoCommChangeState(&_rVrsrcMgr.rCommState, VIDEO_STATE_IDLE);
            drv_trace0(TRACE_GROUP_10, VREC_SOURCE_CHANGE_IDLE);
            _rVrsrcMgr.fgSetToIdleState = KAL_FALSE;
        }
    }
    return VIDEO_ERROR_NONE;
}


/******************************************************************************
*
* Context: none
*
* Side effect:
******************************************************************************/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // 0


/******************************************************************************
* Encoder has finished using the frame buffer so that the frame buffer can be
* recycled for use by IDP.
*
* Context: V2DEC (called by Encoder component)
*
* Side effect:
******************************************************************************/
static VIDEO_ERROR_TYPE_T _VRSRC_FillThisBuffer(VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    kal_uint32 u4Flags = 0;

    if ((_rVrsrcMgr.u4DataPortIdx != prBuffHeader->u4OutputPort) ||
        (_rVrsrcMgr.u4DataPortConnectedIdx != prBuffHeader->u4InputPort))
    {
        ASSERT(0);
    }

    _rVrsrcMgr.pu1BufferAddressFromEncoder = prBuffHeader->pu1Buffer;
    visual_active_hisr(VISUAL_RECORDER_SOURCE_HISR_ID);  // Call _VRSRC_FillThisBufferInHisr() in HISR.

    // To sync HISR is finished
    kal_retrieve_eg_events(_rVrsrcMgr.eActivateSrcHisrEvent, VRSRC_EVENT_HISR_FINISH, KAL_AND_CONSUME, &u4Flags, KAL_SUSPEND);

    return VIDEO_ERROR_NONE;
}


/******************************************************************************
*
* Context: MED
*
* Side effect:
******************************************************************************/
static VIDEO_ERROR_TYPE_T _VRSRC_SetCallbacks(VIDEO_CALLBACK_TYPE_T *prCallback)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    drv_trace0(TRACE_GROUP_10, VREC_SOURCE_SET_CALLBACK);
    eError = VideoCommSetCallbacks(&_rVrsrcMgr.rCommState, prCallback);

    return eError;
}


/******************************************************************************
*
* Context: MED
*
* Side effect:
******************************************************************************/
static VIDEO_ERROR_TYPE_T _VRSRC_DeInit(void)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    drv_trace0(TRACE_GROUP_10, VREC_SOURCE_DEINIT);
    eError = VideoCommDeInit(&_rVrsrcMgr.rCommState);

    VideoFreeMutex(MUTEX_USER_RECORDER_SOURCE, _rVrsrcMgr.rCommState.eMutex);
    VideoFreeEventGroup(EVG_USER_RECORDER_SRC, _rVrsrcMgr.eActivateSrcHisrEvent);

    return eError;
}


/******************************************************************************
* Source component
******************************************************************************/
const static VIDEO_COMPONENT_TYPE_T _rVrsrcComponent =
{
    _VRSRC_Init,
    _VRSRC_SendCommand,
    _VRSRC_GetParameter,
    _VRSRC_SetParameter,
    _VRSRC_UseBuffer,
    NULL,                           // _VRSRC_EmptyThisBuffer,
    _VRSRC_FillThisBuffer,
    _VRSRC_SetCallbacks,
    _VRSRC_DeInit
};


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
VIDEO_COMPONENT_TYPE_T* GetVideoRecorderSourceHandle(VIDEO_RECORDER_SOURCE_TYPE_T eType,
        VIDEO_EXTMEM_HANDLER_T *prExtMemInfo)
{
    VIDEO_COMPONENT_TYPE_T *prVrsrcComponent = (VIDEO_COMPONENT_TYPE_T*)&_rVrsrcComponent;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    _rVrsrcMgr.prExtMemInfo = prExtMemInfo;
    eError = prVrsrcComponent->pfnInit();
    if (eError != VIDEO_ERROR_NONE)
    {
        prVrsrcComponent = NULL;
    }

    return prVrsrcComponent;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
VIDEO_ERROR_TYPE_T ReleaseVideoRecorderSourceHandle(VIDEO_COMPONENT_TYPE_T *prHandle)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    if (prHandle == NULL)
    {
        ASSERT(0);
    }
    else
    {
        eError = prHandle->pfnDeInit();
    }

    return eError;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
#if defined(__VE_SLIM_PROJECT__) && !defined(VRSRC_DEVELOPMENT)
__inline static void _VRSRT_LogWaterMark(void)
{
    /* empty */
}
#else
__inline static void _VRSRT_LogWaterMark(void)
{
    const kal_uint32 u4PeakRefCount = _rVrsrcMgr.rFrameBuffer.u4PeakRefCount;
    kal_char au1WaterMark[] = "SB_";

    if (u4PeakRefCount < 10)
    {
        au1WaterMark[sizeof(au1WaterMark) - 2] = (kal_char)u4PeakRefCount + '0';
    }
    else
    {
        au1WaterMark[sizeof(au1WaterMark) - 2] = (kal_char)(u4PeakRefCount - 10) + 'A';
    }

    _VRSRC_LABEL_LOG(au1WaterMark);
}
#endif  // !defined(__VE_SLIM_PROJECT__)


/******************************************************************************
* The IDP invokes this function to get a buffer for storing the YUV data of a
* frame.  When this function is called again by IDP, it implies that the last
* buffer given to IDP has been written successfully with the data of a frame.
*
* Context: xxx
*
* Side effect: variables related to buffer management
******************************************************************************/
MPL_BUFFER_INFO_T VideoRecorderGetSourceBuffer(void)
{
    VRSRC_FRAME_BUFFER_T* const prFrameBuffer = &_rVrsrcMgr.rFrameBuffer;
    const kal_uint32 u4IdxIdpGet = prFrameBuffer->u4IdxIdpGet;
    const kal_uint32 u4IdxIdpRet = prFrameBuffer->u4IdxIdpRet;
    const kal_uint32 u4IdxEncRet = prFrameBuffer->u4IdxEncRet;
    const kal_uint32 u4TotalBuffer = prFrameBuffer->u4TotalBuffer;
    const kal_uint32 u4NextIdxIdpGet = (u4IdxIdpGet + 1) % u4TotalBuffer;
    const VIDEO_STATE_TYPE_T eState = VRSRC_GET_STATE();
    kal_uint8 *pu1Address = NULL;
    MPL_BUFFER_INFO_T rBufferInfo;
    kal_uint8 u1RefCount;

    if (_rVrsrcMgr.fgTrespass == KAL_FALSE)
    {
        _rVrsrcMgr.fgTrespass = KAL_TRUE;
    }
    else
    {
        ASSERT(0);
    }

    _rVrsrcMgr.rFrameBuffer.u4PeakRefCount++;

#if 0  // Mainly for debugging
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // 0

    // Always increment reference count.
    u1RefCount = prFrameBuffer->au1RefCount[u4IdxIdpGet];
    if (u1RefCount > VRSRC_MAX_REF_COUNT) { ASSERT(0); }
    u1RefCount++;
    prFrameBuffer->au1RefCount[u4IdxIdpGet] = u1RefCount;
    pu1Address = prFrameBuffer->apu1Address[u4IdxIdpGet];

    // Buffer status is unknown when IDP gets the buffer.
    // Its status is determined only when a buffer is returned from IDP.
    prFrameBuffer->au1Status[u4IdxIdpGet] = VRSRC_BUFFER_STATUS_UNKNOWN;

    switch (eState)
    {
    case VIDEO_STATE_IDLE:
    case VIDEO_STATE_STOP:
        // Get unknown buffer.
        _VRSRC_LABEL_LOG("SBJ");  // Junk buffer
        break;

    case VIDEO_STATE_RUN:
        if (u4NextIdxIdpGet == u4IdxEncRet)
        {
            // Memory is not enough.  Do not move IdpGet index pointer.
            _VRSRC_LABEL_LOG("SBD");  // Junk buffer
            _rVrsrcMgr.u4MaxInsufficientFrames++;
        }
        else
        {
            // Memory is enough.  Move IdpGet index pointer forward.
            prFrameBuffer->u4IdxIdpGet = u4NextIdxIdpGet;
            _VRSRC_LABEL_LOG("SBK");  // Use the buffer
            if (_rVrsrcMgr.u4MaxInsufficientFrames != 0)
            {
                drv_trace1(TRACE_GROUP_10, VREC_SOURCE_MAX_INSUFFICIENT_FRAMES,
                    _rVrsrcMgr.u4MaxInsufficientFrames);
                _rVrsrcMgr.u4MaxInsufficientFrames = 0;
            }
        #ifdef __VE_VIDEO_VT_SUPPORT__
            if ((_rVrsrcMgr.pu1YUVBuffer != NULL) &&
                (_rVrsrcMgr.u4YUVInterval != 0))
            {
                // VT image view case
                kal_mem_cpy((void*)pu1Address, (void*)_rVrsrcMgr.pu1YUVBuffer,
                    prFrameBuffer->u4EachBufferSize);
            }
        #endif
        }
        break;

    default:
        ASSERT(0);
        break;
    }

    _VRSRT_LogWaterMark();
    video_dbg_trace(VIDEO_DBG_OWNER_ENCSRC, VIDEO_DBG_ENCSRC_IDP_GET_BUFFER,
        (kal_uint32)pu1Address);
    drv_trace4(TRACE_GROUP_10, VREC_SOURCE_SLIM_GET_BUFFER,
        prFrameBuffer->u4IdxIdpGet, u4IdxIdpRet, u4IdxEncRet, (kal_uint32)u1RefCount);

    _rVrsrcMgr.fgTrespass = KAL_FALSE;

    kal_mem_set((void*)&rBufferInfo, 0, sizeof(rBufferInfo));
    rBufferInfo.pu1Address = pu1Address;
    // rBufferInfo.u4Size = _rVrsrcMgr.rFrameBuffer.u4EachBufferSize;

    return rBufferInfo;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
void VideoRecorderCompleteSourceBuffer(MPL_BUFFER_INFO_T rBufferInfo)
{
    VRSRC_FRAME_BUFFER_T* const prFrameBuffer = &_rVrsrcMgr.rFrameBuffer;
    const kal_uint32 u4TotalBuffer = prFrameBuffer->u4TotalBuffer;
    const kal_uint32 u4IdxIdpGet = prFrameBuffer->u4IdxIdpGet;
    const kal_uint32 u4IdxIdpRet = prFrameBuffer->u4IdxIdpRet;
    const kal_uint32 u4IdxEncRet = prFrameBuffer->u4IdxEncRet;
    const kal_uint32 u4NextIdxIdpRet = (u4IdxIdpRet + 1) % u4TotalBuffer;
    kal_uint8 * const pu1Address = rBufferInfo.pu1Address;
    const VIDEO_STATE_TYPE_T eState = VRSRC_GET_STATE();
    kal_uint8 u1RefCount;

    if (pu1Address == NULL) { ASSERT(0); }

    if (_rVrsrcMgr.fgTrespass == KAL_FALSE)
    {
        _rVrsrcMgr.fgTrespass = KAL_TRUE;
    }
    else
    {
        ASSERT(0);
    }

    _rVrsrcMgr.rFrameBuffer.u4PeakRefCount--;

    u1RefCount = prFrameBuffer->au1RefCount[u4IdxIdpRet];
    if (u1RefCount == 0)
    {
        // This assertion implies that IDP/MDP does not return buffer in correct order.
        ASSERT(0);
    }

    video_dbg_trace(VIDEO_DBG_OWNER_ENCSRC, VIDEO_DBG_ENCSRC_IDP_RETURN_BUFFER,
        (kal_uint32)pu1Address);
    drv_trace4(TRACE_GROUP_10, VREC_SOURCE_SLIM_RETURN_BUFFER,
        u4IdxIdpGet, u4IdxIdpRet, u4IdxEncRet, (kal_uint32)u1RefCount);

    if (pu1Address != prFrameBuffer->apu1Address[u4IdxIdpRet])
    {
        // This assertion implies that IDP/MDP does not return buffer in correct order.
        ASSERT(0);
    }

    u1RefCount--;
    prFrameBuffer->au1RefCount[u4IdxIdpRet] = u1RefCount;
    if (u1RefCount == 0)
    {
        prFrameBuffer->au1Status[u4IdxIdpRet] = VRSRC_BUFFER_STATUS_JUNK;
        if(eState == VIDEO_STATE_RUN)
        {
            // Only get time from A/V sync counter at RUN state. 6250 separate MCU/DSP sleep mode
            _VRSRC_AttachTimeStamp(u4IdxIdpRet);
            if(rBufferInfo.eStatus == MPL_OK)
            {
                // Mainly for motion sensor. This flag (from MDP) indicates the frame is ready for encoding
                prFrameBuffer->au1Status[u4IdxIdpRet] = VRSRC_BUFFER_STATUS_JEWEL;
            }
        }

        if (u4IdxIdpRet != u4IdxIdpGet)
        {
            prFrameBuffer->u4IdxIdpRet = u4NextIdxIdpRet;
        }
    }

    _VRSRC_TryToSendFrameBufferToEncoder();

    _rVrsrcMgr.fgTrespass = KAL_FALSE;
}


#endif  // defined(__VE_MPEG4_ENC_SUPPORT__) || defined(__VE_AVI_ENC_SUPPORT__)


#endif  // !defined(__VE_SLIM_RECORDER_SOURCE__)


#ifdef __VE_DCM_WITH_COMPRESSION__
#pragma arm section code, rodata
#endif  // __VE_DCM_WITH_COMPRESSION__


#endif  // __VE_VIDEO_ARCHI_V2__

