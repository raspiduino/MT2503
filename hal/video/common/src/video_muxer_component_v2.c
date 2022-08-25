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
 *   video_muxer_component_v2.c
 *
 * Project:
 * --------
 *   MAUI
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 ****************************************************************************/
#include "drv_comm.h"
#include "drv_features_video.h"

#ifdef __VE_DCM_WITH_COMPRESSION__
#include "dcmgr.h" //DCM

#pragma arm section code = "DYNAMIC_CODE_VEENC_ROCODE", rodata = "DYNAMIC_CODE_VEENC_RODATA"
#endif

#if defined(__VE_VIDEO_ARCHI_V2__)
#if defined(__VE_SUPPORT_MUXER__)

#include "kal_public_api.h"
#include "stack_ltlcom.h"
#include "video_types_v2.h"
#include "Video_comm_component_v2.h"
#include "video_buffer_management_v2.h"
#include "video_muxer_mem_req_v2.h"
#include "video_muxer_component_v2.h"
#include "vcodec_v2_trc.h"
#include "video_muxer_if_v2.h"
#include "video_memory_usage_v2.h"

#if 0
/* under construction !*/
/* under construction !*/
#endif


#if defined(__VE_SUPPORT_AVI_MUXER__)
    #include "avi_muxer_if_v2.h"
#endif

#if defined(__VE_SUPPORT_MP4_MUXER_ADAPTER__)
    #include "mp4_muxer_adapter_if_v2.h"
#endif

#if defined(__VE_SUPPORT_RTP_MUXER_ADAPTER__)
    #include "rtp_muxer_adapter_if_v2.h"
#endif


static const PFN_GET_HANDLE _afnGetHandle[] =
{
    NULL,
#if defined(__VE_SUPPORT_MP4_MUXER_ADAPTER__)
    MP4MuxerAdapterGetHandle,
#else
    NULL,
#endif
#if defined(__VE_SUPPORT_AVI_MUXER__)
    AVIMuxerGetHandle,
#else
    NULL,
#endif

#if defined(__VE_SUPPORT_RTP_MUXER_ADAPTER__)
	RTPMuxerAdapterGetHandle,
#else
	NULL,
#endif
// Please add your function above
    NULL
};

//#define __DEBUG_MUXER__

#if defined(__DEBUG_MUXER__)
    #define _MUXER_ASSERT() do{ASSERT(0);}while(0)
#else
    #define _MUXER_ASSERT() do{}while(0)
#endif

static MUXER_MGR_T _rMuxerMgr;
static kal_mutexid eMutex;

// This macro works only when "x" is 2^n.
#define MUXER_ROUND_UP_TO_POWER_OF_TWO(data,x)        \
        (((kal_uint32)(data) + (kal_uint32)(x) - 1) & ~((kal_uint32)(x) - 1))

static void _MuxerWakeUpTask(void* pu1Void);

/************************************************************************
*   MuxerGetMemory
*   User:
*       Muxer/adapter
*   Description:
*       1.  Get external memory
*       2.  Memory type (cache/non-cache) can be specified
*       3.  For the memory switchable, u4MemSize would be extend to be c-
*           acheline-aligned
*
************************************************************************/
void* MuxerGetMemory(const kal_uint32 u4MemSize, const kal_bool fgCacheable)
{
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;
    kal_uint32  u4TmpSize;
    void *pVoid = NULL;

    u4TmpSize = MUXER_ROUND_UP_TO_POWER_OF_TWO(u4MemSize, CPU_CACHE_LINE_SIZE);
    if (fgCacheable == KAL_TRUE)
    {
        pVoid =  kal_adm_alloc_cacheable(_prMgr->rADMID, u4TmpSize, CPU_CACHE_LINE_SIZE);
    }
    else
    {
        pVoid =  kal_adm_alloc_nc_align(_prMgr->rADMID, u4TmpSize, CPU_CACHE_LINE_SIZE);
    }
    drv_trace4(TRACE_GROUP_10, MUX_ALLOC_MEM, (kal_uint32)pVoid, u4TmpSize, u4MemSize, fgCacheable);

    if (NULL == pVoid)
    {
        _MUXER_ASSERT();
    }

    return (void*)(pVoid);
}

/************************************************************************
*   MuxerFreeMemory
*   User:
*       Muxer/adapter
*   Description:
*       1.  Free external memory
*
************************************************************************/
void MuxerFreeMemory(void* const pMemoryAddr)
{
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;

    drv_trace1(TRACE_GROUP_10, MUX_FREE_MEM, (kal_uint32)pMemoryAddr);
    kal_adm_free(_prMgr->rADMID, (kal_uint8*)pMemoryAddr);
}

static void _MuxerResendQ_Init(MUXER_RESENDQ_MGR_T *const prMgr, kal_uint8* const pu1Memory, const kal_uint32 u4QueueNumber)
{
    kal_mem_set(prMgr, 0, sizeof(*prMgr));
    prMgr->pu1BufferAddr = pu1Memory;
    prMgr->u4QueueNumber = u4QueueNumber;
    VideoCoreInitRingBuffer(&prMgr->rCoreMgr, prMgr->pu1BufferAddr, prMgr->u4QueueNumber, sizeof(MUXER_RESENDQ_ITEM_T));

    prMgr->fgInit = KAL_TRUE;
}

static void _MuxerResendQ_DeInit(MUXER_RESENDQ_MGR_T *const prMgr)
{
    if (KAL_TRUE == prMgr->fgInit)
    {
        VideoCoreDeInitRingBuffer(&prMgr->rCoreMgr);
        prMgr->fgInit = KAL_FALSE;
    }
}

static void _MuxerResendQ_Enqueue(MUXER_RESENDQ_MGR_T *const prMgr, MUXER_RESENDQ_ITEM_T * const prItem)
{
    if (KAL_TRUE == prMgr->fgInit)
    {
        if (KAL_FALSE == VideoCoreInsertToTailofRingBuffer(&prMgr->rCoreMgr, (kal_uint8 *)prItem))
        {
            _MUXER_ASSERT();
        }
    }
}

static MUXER_RESENDQ_ITEM_T* _MuxerResendQ_GetFirstQ(MUXER_RESENDQ_MGR_T * const prMgr)
{
    if (KAL_TRUE == prMgr->fgInit)
    {
        return (MUXER_RESENDQ_ITEM_T*)VideoCoreGetHeadofRingBufferAddr(&prMgr->rCoreMgr);
    }
    else
    {
        return NULL;
    }
}

static void _MuxerResendQ_Dequeue(MUXER_RESENDQ_MGR_T *const prMgr)
{
    if (KAL_TRUE == prMgr->fgInit)
    {
        if (KAL_FALSE == VideoCoreConsumeHeadofRingBuffer(&prMgr->rCoreMgr))
        {
            ASSERT(0);
        }
    }
}

static kal_bool _MuxerResendQ_IsQFull(MUXER_RESENDQ_MGR_T *const prMgr)
{
    if (KAL_TRUE == prMgr->fgInit)
    {
        return VideoCoreIsRingBufferFull(&prMgr->rCoreMgr);
    }
    else
    {
        return KAL_FALSE;
    }
}

static kal_bool _MuxerResendQ_IsQAbout2Full(MUXER_RESENDQ_MGR_T *const prMgr, const kal_uint32 u4Ready2Enqueue)
{
    if (KAL_TRUE == prMgr->fgInit)
    {
        kal_uint32 u4MaxItemNum =  VideoCoreRingGetBufferMaxNum(&prMgr->rCoreMgr);
        kal_uint32 u4UsedItemNum = VideoCoreRingBufferUsedNum(&prMgr->rCoreMgr);

        if (u4UsedItemNum >= (u4MaxItemNum - u4Ready2Enqueue))
        {
            return KAL_TRUE;
        }
        return KAL_FALSE;
    }
    else
    {
        return KAL_FALSE;
    }

}

/************************************************************************
*   _MuxerChangeState
*   User:
*       Muxer
*   Description:
*       1. Change both internal and external states
*
************************************************************************/
static void _MuxerChangeState(MUXER_STATE_T eState)
{
    MUXER_MGR_T* _prMgr = &_rMuxerMgr;
    VIDEO_COMM_STATE_T* const prCommState = &_prMgr->rCommState;

    _prMgr->eInternalState = eState;
    switch (eState)
    {
    case MUXER_CLOSED:
        VideoCommChangeState(prCommState, VIDEO_STATE_CLOSE);
        break;

    case MUXER_CLOSING:
        break;

    case MUXER_IDLING:
        VideoCommChangeState(prCommState, VIDEO_STATE_IDLE);
        break;

    case MUXER_INITIALIZED:
        VideoCommChangeState(prCommState, VIDEO_STATE_INIT);
        break;

    case MUXER_RUNNING:
        VideoCommChangeState(prCommState, VIDEO_STATE_RUN);
        break;

    case MUXER_STOPPING:
        break;

    case MUXER_STOPPED:
        VideoCommChangeState(prCommState, VIDEO_STATE_STOP);
        break;

    default:
        _MUXER_ASSERT();
        break;
    }
}


/************************************************************************
*   _MuxerInitComponent
*   User:
*       Muxer
*   Description:
*       1.  Initialize the component-related parameters of the Muxer
*
************************************************************************/
static VIDEO_ERROR_TYPE_T _MuxerInitComponent(void)
{
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;
    VIDEO_PORT_CONFIG_T rVideoConfig;
    VIDEO_PORT_CONFIG_T rAudioConfig;
    VIDEO_COMPONENT_INIT_T rConfig;

    //kal_mem_set((void*)&rVideoConfig, 0, sizeof(rVideoConfig));
    rVideoConfig.ePortType    = VIDEO_PORT_VIDEO_DATA;
    rVideoConfig.fgSupplier   = KAL_FALSE;
    rVideoConfig.u4BuffSize   = 0;

    //kal_mem_set((void*)&rAudioConfig, 0, sizeof(rAudioConfig));
    rAudioConfig.ePortType    = VIDEO_PORT_AUDIO_DATA;
    rAudioConfig.fgSupplier   = KAL_FALSE;
    rAudioConfig.u4BuffSize   = 0;

    kal_mem_set((void*)&rConfig, 0, sizeof(rConfig));
    rConfig.prInputPort1        = &rVideoConfig;
    rConfig.prInputPort2        = &rAudioConfig;
    rConfig.u4CmdQSize          = MUXER_COMMAND_Q_NUM;
    rConfig.u4InputBuffQSize    = MUXER_AUDIO_INPUT_BUFFER_Q_NUM;
    rConfig.u4InputBuffQSize2   = MUXER_VIDEO_INPUT_BUFFER_Q_NUM;
    rConfig.prExtMemHdlr        = _prMgr->prExtMemHdlr;

    rConfig.eMutex = eMutex = VideoGetMutex(MUTEX_USER_MUXER_V2COMMON);

    return VideoCommInit(&_prMgr->rCommState, &rConfig, "NA");
}

/************************************************************************
*   _MuxerDeInitComponent
*   User:
*       Muxer
*   Description:
*       1.  De-initialize the component-related parameters of the Muxer
*
************************************************************************/
static VIDEO_ERROR_TYPE_T _MuxerDeInitComponent(void)
{
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;

    VideoFreeMutex(MUTEX_USER_MUXER_V2COMMON, eMutex);

    return VideoCommDeInit(&_prMgr->rCommState);
}

/************************************************************************
*   _MuxerGetAdaptMemSize
*   User:
*       Muxer
*   Description:
*       1.  Calculate the memory size needed by an adapatation
*           layer
*       2.  Returns 0 when the scenario is not specified
*
*   Remark:
*       1.  Assumed to be called after Muxer assigned prAdaptAPI. Would
*           cause fatal error otherwise.
*
************************************************************************/
static kal_uint32 _MuxerGetAdaptMemSize(void)
{
    const MUXER_MGR_T* const _prMgr = &_rMuxerMgr;
    const MUXER_ADAPT_API_T* const prAPI = _prMgr->prAdaptAPI;
    const MUXER_ADAPT_SETTING_T* const prSetting = &_prMgr->rAdaptSettings;
    kal_uint32  u4TotalMemorySize = 0;
    kal_uint32  u4WriterMemorySize = 0;

    if (MUXER_SCENARIO_UNKNOWN == prSetting->eScenario)
    {
        ASSERT(0);
    }

    if (VIDEO_ERROR_NONE  != prAPI->pfnSetParam(MUXER_SET_SCENARIO, (void*)(&prSetting->eScenario)))
    {
        _MUXER_ASSERT();
    }

    if (VIDEO_ERROR_NONE  != prAPI->pfnGetParam(MUXER_GET_MEMORY_SIZE, (void*)&u4WriterMemorySize))
    {
        _MUXER_ASSERT();
    }

    u4TotalMemorySize += u4WriterMemorySize;
    return u4TotalMemorySize;
}

/************************************************************************
*   _MuxerCallback2IL
*   User:
*       Muxer
*   Description:
*       1.  Callback IL
*
************************************************************************/
static void _MuxerCallback2IL(const VIDEO_EVENT_TYPE_T eEvent, const kal_uint32 u4Line)
{
    const MUXER_MGR_T* const _prMgr = &_rMuxerMgr;
    VIDEO_ERROR_TYPE_T eRet;
    VIDEO_CALLBACK_TYPE_T *prCallback;

    drv_trace1(TRACE_GROUP_10, MUX_CALLBACK_IL, eEvent);

    prCallback = VideoCommGetCallback(&_prMgr->rCommState);
    eRet = prCallback->pfnEventHandler(eEvent, VIDEO_COMMAND_NOTIFY, u4Line, NULL);
    if (VIDEO_ERROR_NONE != eRet)
    {
        _MUXER_ASSERT();
    }
}

static void _MuxerCheckReturnCode(const VIDEO_ERROR_TYPE_T eRet)
{
    VIDEO_EVENT_TYPE_T eEvent = VIDEO_EVENT_ERROR;

    drv_trace1(TRACE_GROUP_10, MUX_CHECK_RET_CODE, eRet);

    switch(eRet)
    {
        case VIDEO_ERROR_NONE:
            return;

        case VIDEO_ERROR_MUXER_REACH_SIZE_LIMIT:
            eEvent = VIDEO_EVENT_MUXER_REACH_SIZE_LIMIT;
            break;

        case VIDEO_ERROR_MUXER_DISK_FULL:
            eEvent = VIDEO_EVENT_DISK_IS_FULL;
            break;

        case VIDEO_ERROR_MUXER_NO_VIDEO_FRAME_ENCODED:
            eEvent = VIDEO_EVENT_NO_VIDEO_FRAME_ENCODED;
            break;

        case VIDEO_ERROR_MUXER_FS_ERROR:
        default:
            eEvent = VIDEO_EVENT_ERROR;
            break;
    }

    _MuxerCallback2IL(eEvent, __LINE__);
}

static void _MuxerAbortSavingCB(void)
{
    // Run in caller Task
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;
    VIDEO_EVENT_TYPE_T eVEvent = VIDEO_EVENT_MUXER_ABORT_SAVING_FAIL;

    if (_prMgr->fgAbortSaving == KAL_FALSE || _prMgr->fgCreatedFile == KAL_FALSE)
    {
        return;
    }

    if (_prMgr->fgAbortSavingOk == KAL_TRUE)
    {
        eVEvent = VIDEO_EVENT_MUXER_ABORT_SAVING_DONE;
    }

    _MuxerCallback2IL(eVEvent, __LINE__);
    _prMgr->fgAbortSaving = KAL_FALSE;
}

static kal_bool _MuxerReturnBuffer(const VIDEO_PORT_TYPE_T eType, kal_uint64 *const pu8TimeStamp, kal_uint8 * const pu1Buffer, const kal_uint32 u4Size, const VIDEO_BUFFERFLAG_TYPE_T eFlags)
{
    VIDEO_ERROR_TYPE_T eError;
    VIDEO_COMM_STATE_T *const prCommState = &_rMuxerMgr.rCommState;
    kal_uint32 u4DataPortIdx = VideoCommGetInputPortIndex(prCommState, eType);
    const VIDEO_COMPONENT_PARAM_T *const prDataPortComp = VideoCommGetInputComp(prCommState, u4DataPortIdx);
    PFN_FILL_THIS_BUFFER_T pfnFillThisBuffer;
    VIDEO_BUFFERHEADER_TYPE_T rBufferHeader;

    if (prDataPortComp == NULL)
    {
        _MUXER_ASSERT();
    }

    pfnFillThisBuffer = VideoCommGetInputProcessBufferFunc(prCommState, u4DataPortIdx);

    //kal_mem_set(&rBufferHeader, 0, sizeof(rBufferHeader));
    rBufferHeader.u8TimeStamp = *pu8TimeStamp;
    rBufferHeader.u4OutputPort = prDataPortComp->u4PortIndex;
    rBufferHeader.u4InputPort = u4DataPortIdx;
    rBufferHeader.pu1Buffer = pu1Buffer;
    rBufferHeader.u4BuffSize = u4Size;
    rBufferHeader.eFlags = eFlags;
    rBufferHeader.pPrivateData = NULL;

    drv_trace4(TRACE_GROUP_10, MUX_RETURN_BS, eType, (kal_uint32)pu1Buffer, u4Size, 0);

    eError = pfnFillThisBuffer(&rBufferHeader);
    if (eError != VIDEO_ERROR_NONE)
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}

static void _MuxerReturnFromResendQ(const VIDEO_PORT_TYPE_T eType)
{
    MUXER_RESENDQ_MGR_T* prMgr = NULL;

    if (eType == VIDEO_PORT_VIDEO_DATA)
    {
        prMgr = &_rMuxerMgr.rVideoResendQMgr;
    }
    else if (eType == VIDEO_PORT_AUDIO_DATA)
    {
        prMgr = &_rMuxerMgr.rAudioResendQMgr;
    }

    do
    {
        MUXER_RESENDQ_ITEM_T* const prItem = _MuxerResendQ_GetFirstQ(prMgr);
        if (NULL != prItem)
        {
            if (KAL_TRUE == _MuxerReturnBuffer(eType, &prItem->u8TimeStamp, prItem->pu1BufferAddr, prItem->u4Size, prItem->eFlag))
            {
                _MuxerResendQ_Dequeue(prMgr);
            }
            else
            {
                const kal_uint16 u2TimeOutTick = 10;
                if (_rMuxerMgr.fgStartWakeUpTimer == KAL_FALSE)
                {
                    kal_set_timer(_rMuxerMgr.rTimerID, _MuxerWakeUpTask, NULL, u2TimeOutTick, 0);
                    _rMuxerMgr.fgStartWakeUpTimer = KAL_TRUE;
                }

                break;
            }
        }
        else
        {
            break;
        }
    }while(1);
}

/************************************************************************
*   _MuxerAdaptCallback
*   User:
*       Adaptation layers
*   Description:
*       1.  Handle the callback event from adaptation layers
*
*
Remark:
*
************************************************************************/
static void _MuxerAdaptCallback(kal_uint32 u4Event, void* pVoid)
{
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;
    kal_eventgrpid rID = _prMgr->rEventGroupID;

    drv_trace1(TRACE_GROUP_10, MUX_ADAPT_CALLBACK, u4Event);

    switch(u4Event)
    {
    case MUXER_EVNET_0:
        _prMgr->au4EventDataType[0] = *(kal_uint32*)pVoid;
        break;
    case MUXER_EVNET_1:
        _prMgr->au4EventDataType[1] = *(kal_uint32*)pVoid;
        break;
    case MP4_EVENT_RETURN_BUFFER:
        {
            MUXER_PROCESS_PARAM_T *prParam = (MUXER_PROCESS_PARAM_T*)pVoid;
            MUXER_RESENDQ_ITEM_T rResendItem;

            //kal_mem_set(&rResendItem, 0, sizeof(rResendItem));
            if (prParam->u4DataType == MX_DATATYPE_AUDIO)
            {
                if (prParam->arData[0].fgValid == KAL_TRUE)
                {
                    rResendItem.u8TimeStamp = prParam->u8TimeStamp;
                    rResendItem.pu1BufferAddr = prParam->arData[0].pu1Addr;
                    rResendItem.u4Size = prParam->arData[0].u4Size;
                    rResendItem.eFlag = VIDEO_BUFFERFLAG_NONE;
                    _MuxerResendQ_Enqueue(&_prMgr->rAudioResendQMgr, &rResendItem);
                }
                _MuxerReturnFromResendQ(VIDEO_PORT_AUDIO_DATA);

                return;
            }
            else if ((prParam->u4DataType == MX_DATATYPE_VIDEO) ||
                     (prParam->u4DataType == MX_DATATYPE_VIDEO_SEQUENCE_HEADER))
            {
                kal_uint32 i = 0;

                for(; i < MAX_BUFFER_PARTITION; i++)
                {
                    if (prParam->arData[i].fgValid == KAL_TRUE)
                    {
                        rResendItem.u8TimeStamp = prParam->u8TimeStamp;
                        rResendItem.pu1BufferAddr = prParam->arData[i].pu1Addr;
                        rResendItem.u4Size = prParam->arData[i].u4Size;
                        rResendItem.eFlag = VIDEO_BUFFERFLAG_NONE;
                        if (prParam->u4DataType == MX_DATATYPE_VIDEO)
                        {
                            rResendItem.eFlag |= VIDEO_BUFFERFLAG_NONE;
                        }
                        else
                        {
                            rResendItem.eFlag |= VIDEO_BUFFERFLAG_PARAMETERSET;
                        }
                        _MuxerResendQ_Enqueue(&_prMgr->rVideoResendQMgr, &rResendItem);
                    }
                }
            }
            else
            {
                _MUXER_ASSERT();
            }
        }
        break;
    default:
        _MUXER_ASSERT();
        break;
    }

    if (KAL_SUCCESS != kal_set_eg_events(rID, u4Event, KAL_OR))
    {
        _MUXER_ASSERT();
    }
}

static void _MuxerWriteData2File(MUXER_WRITE_PARAM_T * const prParam)
{
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;
    VIDEO_ERROR_TYPE_T eRet = VIDEO_ERROR_NONE;
    kal_uint32 u4StartTime = 0;
    kal_uint32 u4WriteTime = 0;

    u4StartTime = video_get_current_time();
    VIDEO_START_LOGGING("WBI");
    eRet = _prMgr->prAdaptAPI->pfnWriteData2File(prParam);
    VIDEO_STOP_LOGGING("WBI");
    u4WriteTime = video_get_duration_ms(u4StartTime);

    drv_trace1(TRACE_GROUP_10, MUX_PROFILE_WRITING_TIME, u4WriteTime);

    _MuxerCheckReturnCode(eRet);
}

static kal_uint32 _MuxerGetReturningBufferNumber(const VIDEO_PARAM_TYPE_T eParam)
{
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;
    MUXER_ADAPT_API_T*  const prAdaptAPI = _prMgr->prAdaptAPI;
    kal_uint32 u4Ready2Enqueue = 0;

    if (VIDEO_ERROR_NONE != prAdaptAPI->pfnGetParam(eParam, (void*)&u4Ready2Enqueue))
    {
        _MUXER_ASSERT();
    }

    return u4Ready2Enqueue;
}

/************************************************************************
*   _MuxerProcessCallbackEvent
*   User:
*       Muxer
*   Description:
*       1. Process the callback events
*
************************************************************************/
#define _AVI_DONT_WAIT_EG   (0)
static void _MuxerCheckAndWriteData2File(const kal_uint32 u4DataType, const kal_uint32 u4CheckedEvent, const VIDEO_PARAM_TYPE_T eVideoParam, MUXER_RESENDQ_MGR_T *const prResendMgr)
{
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;
    kal_eventgrpid rID = _prMgr->rEventGroupID;
    kal_uint32 u4Ready2Enqueue = 0;
    kal_uint32 u4RetrievedEvent = 0;

    u4Ready2Enqueue = _MuxerGetReturningBufferNumber(eVideoParam);
    if (KAL_FALSE == _MuxerResendQ_IsQAbout2Full(prResendMgr, u4Ready2Enqueue))
    {
        do
        {
            if (KAL_SUCCESS == kal_retrieve_eg_events(rID, u4CheckedEvent, KAL_OR_CONSUME, &u4RetrievedEvent, _AVI_DONT_WAIT_EG))
            {
                MUXER_WRITE_PARAM_T rParam;
                rParam.u4DataType = u4DataType;
                rParam.fgFlush = KAL_FALSE;
                _MuxerWriteData2File(&rParam);

                // Return video
                if (KAL_SUCCESS == kal_retrieve_eg_events(rID, MP4_EVENT_RETURN_BUFFER, KAL_OR_CONSUME, &u4RetrievedEvent, _AVI_DONT_WAIT_EG))
                {
                    _MuxerReturnFromResendQ(VIDEO_PORT_VIDEO_DATA);
                }
            }
            else
            {
                break;
            }
        }while(1);
    }
}

static void _MuxerProcessCallbackEvent(void)
{
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;
    kal_eventgrpid rID = _prMgr->rEventGroupID;
    kal_uint32 u4RetrievedEvent = 0;

    // Check and write audio
    _MuxerCheckAndWriteData2File(_prMgr->au4EventDataType[0], MUXER_EVNET_0, MUXER_GET_RETURNING_AUDIO_BUFFER_NUMBER, &_prMgr->rAudioResendQMgr);

    // Check and write video
    _MuxerCheckAndWriteData2File(_prMgr->au4EventDataType[1], MUXER_EVNET_1, MUXER_GET_RETURNING_VIDEO_BUFFER_NUMBER, &_prMgr->rVideoResendQMgr);

    // Return video
    if (KAL_SUCCESS == kal_retrieve_eg_events(rID, MP4_EVENT_RETURN_BUFFER, KAL_OR_CONSUME, &u4RetrievedEvent, _AVI_DONT_WAIT_EG))
    {
        _MuxerReturnFromResendQ(VIDEO_PORT_VIDEO_DATA);
    }
}

/************************************************************************
*   _MuxerSetupAdapter
*   User:
*       Muxer
*   Description:
*       1.  Setup the adaptation layer
*
*
Remark:
*       1. This function should be called between pfnOpen and pfnInit
*
************************************************************************/
static void _MuxerSetupAdapter(void)
{
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;
    MUXER_ADAPT_API_T* const prAPI = _prMgr->prAdaptAPI;
    MUXER_ADAPT_SETTING_T* const prSetting = &_prMgr->rAdaptSettings;

    prAPI->pfnSetParam(MUXER_SET_SCENARIO, (void*)(&prSetting->eScenario));
    prAPI->pfnSetParam(MUXER_SET_CALLBACK, (void*)_MuxerAdaptCallback);
    prAPI->pfnSetParam(MUXER_SET_VIDEO_CONFIG, (void*)(&prSetting->rVideoConfig));
    prAPI->pfnSetParam(MUXER_SET_AUDIO_CONFIG, (void*)(&prSetting->rAudioConfig));
    prAPI->pfnSetParam(MUXER_SET_SIZE_LIMIT, (void*)(&prSetting->u8SizeLimit));
    prAPI->pfnSetParam(MUXER_SET_TIME_LIMIT, (void*)(&prSetting->u4TimeLimit));
    prAPI->pfnSetParam(MUXER_SET_WORKING_PATH, (void*)(prSetting->pawszWorkingPath));
    prAPI->pfnSetParam(MUXER_SET_FILE_NAME_PATH, (void*)(prSetting->pawszFileNamePath));
    prAPI->pfnSetParam(MUXER_SET_VIDEO_WRITE_THRESHOLD, (void*)(&prSetting->u4VideoWriteThreshold));

#if defined(__VE_TIME_LAPSE_VIDEO_RECORDER__)
    prAPI->pfnSetParam(MUXER_SET_TIME_LAPSE_FRAME_RATE, (void*)(&prSetting->u4TLFrameRate));
#endif

#ifdef __VE_SUPPORT_RTP_MUXER_ADAPTER__
	prAPI->pfnSetParam(MUXER_SET_VIDEO_RTP_HANDLE, (void*)(&prSetting->u1VidRTPHandle));
	prAPI->pfnSetParam(MUXER_SET_AUDIO_RTP_HANDLE, (void*)(&prSetting->u1AudRTPHandle));
#endif


}

static VIDEO_ERROR_TYPE_T _MuxerAllocateResource(void)
{
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;

    _prMgr->rEventGroupID = VideoGetEventGroup(EVG_USER_MUXER);
    _prMgr->u4MemSize = _MuxerGetAdaptMemSize();
    if (0 == _prMgr->u4MemSize)
    {
        _MUXER_ASSERT();
    }

    _prMgr->u4MemAddr = VideoGetExtBuffer(_prMgr->prExtMemHdlr, _prMgr->u4MemSize);
    if (NULL == _prMgr->u4MemAddr)
    {
        return VIDEO_ERROR_MUXER_ERROR;
    }

    // ADM and ResendQ must be allocated firstly
    // because "return audio" need to use the queue.
    _prMgr->rADMID = kal_adm_create((void *)_prMgr->u4MemAddr, _prMgr->u4MemSize, NULL, KAL_TRUE);

    _MuxerResendQ_Init(&_prMgr->rVideoResendQMgr,
                        (kal_uint8 *)VideoGetExtBuffer(_prMgr->prExtMemHdlr, MUXER_VIDEO_RESENT_Q_NUMBER * MUXER_RESENT_Q_SIZE),
                        MUXER_VIDEO_RESENT_Q_NUMBER);

    _MuxerResendQ_Init(&_prMgr->rAudioResendQMgr,
                        (kal_uint8 *)VideoGetExtBuffer(_prMgr->prExtMemHdlr, MUXER_AUDIO_RESENT_Q_NUMBER * MUXER_RESENT_Q_SIZE),
                        MUXER_AUDIO_RESENT_Q_NUMBER);

    _prMgr->rTimerID = VideoGetTimer(TIMER_USER_MUXER);
    _prMgr->rMuxerMutex = VideoGetMutex(MUTEX_USER_MUXER);
    _prMgr->rMuxerMutex2 = VideoGetMutex(MUTEX_USER_MUXER);

    return VIDEO_ERROR_NONE;
}

static void _MuxerReleaseResource(void)
{
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;

    _MuxerResendQ_DeInit(&_prMgr->rVideoResendQMgr);
    _MuxerResendQ_DeInit(&_prMgr->rAudioResendQMgr);

    if (_prMgr->rADMID != NULL)
    {
        kal_adm_delete(_prMgr->rADMID);
    }

    if (_prMgr->fgStartWakeUpTimer == KAL_TRUE)
    {
        kal_cancel_timer(_prMgr->rTimerID);
    }

    if (_prMgr->rTimerID != NULL)
    {
        VideoFreeTimer(TIMER_USER_MUXER, _prMgr->rTimerID);
    }

    if (_prMgr->rEventGroupID != NULL)
    {
        VideoFreeEventGroup(EVG_USER_MUXER, _prMgr->rEventGroupID);
    }

    if (_prMgr->rMuxerMutex != NULL)
    {
        VideoFreeMutex(MUTEX_USER_MUXER, _prMgr->rMuxerMutex);
    }

    if (_prMgr->rMuxerMutex2 != NULL)
    {
        VideoFreeMutex(MUTEX_USER_MUXER, _prMgr->rMuxerMutex2);
    }
}


/************************************************************************
*   _MuxerInitDriver
*   User:
*       Muxer
*   Description:
*       1.  Initialize the driver-related parameters of the Muxer
*
************************************************************************/
static VIDEO_ERROR_TYPE_T _MuxerInitDriver(void)
{
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_INIT_ERROR;

    if (KAL_FALSE == _prMgr->fgInitDriver)
    {
        if (MUXER_CONTAINER_TYPE_UNKNOWN == _prMgr->eAdaptType)
        {
            _MUXER_ASSERT();
        }

        _prMgr->prAdaptAPI = _afnGetHandle[_prMgr->eAdaptType]();
        if (NULL == _prMgr->prAdaptAPI)
        {
            goto ERROR_HANDLNG;
        }
        _prMgr->fgInitAdaptation = KAL_TRUE;

        eError = _MuxerAllocateResource();
        if (VIDEO_ERROR_NONE != eError)
        {
            goto ERROR_HANDLNG;
        }

        eError = _prMgr->prAdaptAPI->pfnOpen();
        if (VIDEO_ERROR_NONE != eError)
        {
            goto ERROR_HANDLNG;
        }
        _MuxerSetupAdapter();

        eError = _prMgr->prAdaptAPI->pfnInit();
        if (VIDEO_ERROR_NONE != eError)
        {
            goto ERROR_HANDLNG;
        }

        _prMgr->fgInitDriver = KAL_TRUE;
    }
    return VIDEO_ERROR_NONE;

ERROR_HANDLNG:
    return eError;
}

/************************************************************************
*   _MuxerDeInitDriver
*   User:
*       Muxer
*   Description:
*       1.  De-initialize the driver-related parameters of the Muxer
*
************************************************************************/
static VIDEO_ERROR_TYPE_T _MuxerDeInitDriver(void)
{
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;
    MUXER_ADAPT_API_T* const prAPI = _prMgr->prAdaptAPI;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    do
    {
        if (KAL_TRUE == _prMgr->fgInitDriver)
        {
            eError = prAPI->pfnDeInit();
            if (VIDEO_ERROR_NONE != eError)
            {
                break;
            }

            eError = prAPI->pfnClose();
            if (VIDEO_ERROR_NONE != eError)
            {
                break;
            }
            _prMgr->fgInitAdaptation = KAL_FALSE;
        }
    }while(0);
    _MuxerReleaseResource();
    _prMgr->fgInitDriver = KAL_FALSE;
    return eError;
}

/************************************************************************
*   _MuxerWakeUpTask
*   User:
*       Muxer
*   Description:
*       1.  Decide whether to send a message to wake up the Muxer
*           according to component setting
*
*   Remark:
*       1.  Since Muexr is designed to running in a while loop, a message
*           in external queue of VFILE to wake up the Muxer is enough. No
*           need to send another one
*
************************************************************************/
#pragma arm section code = "SECONDARY_ROCODE"
static void _MuxerWakeUpTask(void* pu1Void)
{
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;
    kal_bool fgSendMsg = KAL_FALSE;

    fgSendMsg = VideoCommSetProcessing(&_prMgr->rCommState);
    if (fgSendMsg == KAL_TRUE)
    {
        MUXER_IND_T *prMsg = NULL;
        ilm_struct *prIlm = NULL;
        module_type eActiveModuleId = stack_get_active_module_id();

        prMsg = (MUXER_IND_T*) construct_local_para(sizeof(MUXER_IND_T), TD_CTRL);

        prIlm = allocate_ilm(eActiveModuleId);
        prIlm->src_mod_id = eActiveModuleId;
        prIlm->dest_mod_id = MOD_VFILE;
        prIlm->sap_id = MED_SAP;
        prIlm->msg_id = (msg_type) MSG_ID_MP4_FILE_WRITER_DATA_IND;//MSG_ID_MUXER_DATA_IND;
        prIlm->local_para_ptr = (local_para_struct*) prMsg;
        prIlm->peer_buff_ptr = NULL;

        drv_trace0(TRACE_GROUP_10, MUX_WAKE_UP_TASK);
        msg_send_ext_queue(prIlm);
    }
}
#pragma arm section code
/************************************************************************
*   _MuxerInit
*   User:
*       Muxer
*   Description:
*       1.  Initialize the Muxer
*
*   Remark:
*       1.  All parameters related to resource allocation should be set
*           by IL before this function is called
*
************************************************************************/
static void _MuxerInit(void)
{
    _MuxerChangeState(MUXER_INITIALIZED);
}

/************************************************************************
*   _MuxerSendCommand
*   User:
*       IL
*   Description:
*       1.  Store the command from IL
*       2.  Send external message to wake up Muxer when necessary
*
*   Remark:
*
************************************************************************/
static VIDEO_ERROR_TYPE_T _MuxerSendCommand(VIDEO_COMMAND_TYPE_T rCmd, kal_uint32 u4Param)
{
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;
    VIDEO_COMM_STATE_T* const prCommState = &_prMgr->rCommState;

    if (rCmd == VIDEO_COMMAND_STATESET)
    {
        if (KAL_FALSE == VideoCommPushCommand(prCommState, rCmd, u4Param))
        {
            return VIDEO_ERROR_BUFF_FULL;
        }
        else
        {
            _MuxerWakeUpTask(NULL);
            return VIDEO_ERROR_NONE;
        }
    }
    else
    {
        return VIDEO_ERROR_INPUT_PARAM_ERROR;
    }
}

/************************************************************************
*   _MuxerGetParameter
*   User:
*       IL
*   Description:
*       1.  Used by IL to query information
*
*   Remark:
*
************************************************************************/
static VIDEO_ERROR_TYPE_T _MuxerGetParameter(VIDEO_PARAM_TYPE_T eParam, void *pvParam)
{
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;
    VIDEO_COMM_STATE_T* const prCommState = &_prMgr->rCommState;
    VIDEO_ERROR_TYPE_T eRet = VIDEO_ERROR_NONE;

    switch (eParam)
    {
    case VIDEO_PARAM_INPUT_BUFFER_PARAM:
        VideoCommGetInputPortParam(prCommState, pvParam);
        break;

    case VIDEO_PARAM_OUTPUT_BUFFER_PARAM:
        VideoCommGetOutputPortParam(prCommState, pvParam);
        break;


    case MUXER_GET_CURRENT_FILE_SIZE:
    case MUXER_GET_MIN_SPACE_TO_RECORD:
    case MUXER_IS_TEMP_FILE_EXISTED:
    case MUXER_GET_RTP_SEQ_HEADER:    
        {
            MUXER_ADAPT_API_T* const prAPI = _prMgr->prAdaptAPI;
            return prAPI->pfnGetParam(eParam, pvParam);
        }
    default:
        eRet = VIDEO_ERROR_INPUT_PARAM_ERROR;
        drv_trace1(TRACE_GROUP_10, MUX_GET_PARAM_ERR, eParam);
        break;
    }

    return eRet;
}

/************************************************************************
*   _MuxerSetParameter
*   User:
*       IL
*   Description:
*       1.  Used by IL to set configurations
*
*   Remark:
*
************************************************************************/
static VIDEO_ERROR_TYPE_T _MuxerSetParameter(VIDEO_PARAM_TYPE_T eCmd, void *pvParam)
{
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;
    VIDEO_COMM_STATE_T* const prCommState = &_prMgr->rCommState;
    MUXER_ADAPT_SETTING_T* const prSetting = &_prMgr->rAdaptSettings;

    switch (eCmd)
    {
    case VIDEO_PARAM_INPUT_BUFFER_PARAM:
        VideoCommSetInputPortParam(prCommState, pvParam);
        break;

    case VIDEO_PARAM_OUTPUT_BUFFER_PARAM:
        VideoCommSetOutputPortParam(prCommState, pvParam);
        break;

    case MUXER_SET_SCENARIO:
        prSetting->eScenario = *(MUXER_SCENARIO_T*)(pvParam);
        break;

    case MUXER_SET_VIDEO_CONFIG:
        prSetting->rVideoConfig = *(MUXER_VIDEO_CONFIG_T*)(pvParam);
        break;

    case MUXER_SET_AUDIO_CONFIG:
        prSetting->rAudioConfig = *(MUXER_AUDIO_CONFIG_T*)(pvParam);
        break;

    case MUXER_SET_CONTAINER_TYPE:
        _prMgr->eAdaptType = *(MUXER_CONTAINER_TYPE_T*)(pvParam);
        break;

    case MUXER_SET_SIZE_LIMIT:
        prSetting->u8SizeLimit = *(kal_uint64*)(pvParam);
        break;

    case MUXER_SET_TIME_LIMIT:
        prSetting->u4TimeLimit = *(kal_uint32*)(pvParam);
        break;

    case MUXER_SET_WORKING_PATH:
        kal_wstrcpy((void*)(prSetting->pawszWorkingPath), pvParam);
        break;

    case MUXER_SET_FILE_NAME_PATH:
        kal_wstrcpy((void*)prSetting->pawszFileNamePath, pvParam);
        break;

    case MUXER_SET_VIDEO_WRITE_THRESHOLD:
        prSetting->u4VideoWriteThreshold = *(kal_uint32*)(pvParam);
        break;
#if defined(__VE_TIME_LAPSE_VIDEO_RECORDER__)
    case MUXER_SET_TIME_LAPSE_FRAME_RATE:
        prSetting->u4TLFrameRate = *(kal_uint32*)(pvParam);
        break;
#endif

#ifdef __VE_SUPPORT_RTP_MUXER_ADAPTER__
	case MUXER_SET_VIDEO_RTP_HANDLE:
		prSetting->u1VidRTPHandle = *(kal_uint8*)(pvParam);
		break;
	case MUXER_SET_AUDIO_RTP_HANDLE:
		prSetting->u1AudRTPHandle = *(kal_uint8*)(pvParam);
		break;
    case MUXER_SET_RTP_INSTANT_STOP:
        _prMgr->fgGotStopCommand = KAL_TRUE;
        break;
#endif

    default:
        return VIDEO_ERROR_INPUT_PARAM_ERROR;
    };

    return VIDEO_ERROR_NONE;
}

static VIDEO_ERROR_TYPE_T _MuxerPush2InputQ(const kal_uint32 u4DataType, VIDEO_BUFFERHEADER_TYPE_T *const prBuffHeader)
{
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;
    VIDEO_COMM_STATE_T* const prCommState = &_prMgr->rCommState;

    if (!(prBuffHeader->eFlags & VIDEO_BUFFERFLAG_EOF))
    {
        kal_bool fgRet = KAL_FALSE;

        fgRet = VideoCommPushInputBuffExt(prCommState, prBuffHeader, u4DataType);
        if (fgRet == KAL_FALSE)
        {
            return VIDEO_ERROR_BUFF_FULL;
        }

        drv_trace4(TRACE_GROUP_10, MUX_GOT_BS, u4DataType == MUXER_AUDIO_PORT? VIDEO_PORT_AUDIO_DATA : VIDEO_PORT_VIDEO_DATA
                                , (kal_uint32)(prBuffHeader->pu1Buffer)
                                , prBuffHeader->u4BuffSize, 0);
        _MuxerWakeUpTask(NULL);
    }
    else
    {
        _MuxerCallback2IL(u4DataType == MUXER_AUDIO_PORT? VIDEO_EVENT_AUDIO_EOS : VIDEO_EVENT_VIDEO_EOS, __LINE__);
    }

    return VIDEO_ERROR_NONE;
}

/************************************************************************
*   _MuxerEmptyThisBuffer
*   User:
*       IL and video encoder
*   Description:
*       1.  Store the audio data sent from IL
*       2.  Store the video data sent from video encoder
*       3.  Send external message to wake up Muxer when necessary
*
*   Remark:
*       1. Protection of race condition is necessary since IL and Encoder
*       run in different tasks
*
************************************************************************/
static VIDEO_ERROR_TYPE_T _MuxerEmptyThisBuffer(VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;
    kal_mutexid const rMutex = _prMgr->rMuxerMutex2;

    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    MUXER_ADAPT_SETTING_T* const prSetting = &_prMgr->rAdaptSettings;

    kal_take_mutex(rMutex);

    if ((MUXER_RUNNING != _prMgr->eInternalState) ||
        (MUXER_SCENARIO_RECORD != prSetting->eScenario))
    {
        if (_prMgr->u4AudioPort == prBuffHeader->u4InputPort)
        {
            _MuxerReturnBuffer(VIDEO_PORT_AUDIO_DATA, &prBuffHeader->u8TimeStamp, prBuffHeader->pu1Buffer, prBuffHeader->u4BuffSize, VIDEO_BUFFERFLAG_NONE);
        }
        else
        {
            kal_give_mutex(rMutex);
            return VIDEO_ERROR_BUFF_FULL;
        }
    }

    if(_prMgr->u4AudioPort == prBuffHeader->u4InputPort)
    {
        eError = _MuxerPush2InputQ(MUXER_AUDIO_PORT, prBuffHeader);
    }
    else if (_prMgr->u4VideoPort == prBuffHeader->u4InputPort)
    {
        eError = _MuxerPush2InputQ(MUXER_VIDEO_PORT, prBuffHeader);
    }
    else
    {
        eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
    }

    kal_give_mutex(rMutex);
    return eError;
}

/************************************************************************
*   _MuxerSetCallbacks
*   User:
*       IL
*   Description:
*       1.  Set callback function
*
*   Remark:
*
************************************************************************/
static VIDEO_ERROR_TYPE_T _MuxerSetCallbacks(VIDEO_CALLBACK_TYPE_T *prCallback)
{
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    eError = VideoCommSetCallbacks(&_prMgr->rCommState, prCallback);

    return eError;
}

/************************************************************************
*   _MuxerDeInit
*   User:
*       Muxer
*   Description:
*       1.  Deinitialize the Muxer
*
*   Remark:
*
************************************************************************/
static void _MuxerDeInit(void)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    eError = _MuxerDeInitDriver();
    if (VIDEO_ERROR_NONE != eError)
    {
        _MUXER_ASSERT();
    }

    eError = _MuxerDeInitComponent();
    if (VIDEO_ERROR_NONE != eError)
    {
        _MUXER_ASSERT();
    }
}

static const VIDEO_COMPONENT_TYPE_T _rMuxerComp =
{
    NULL,
    _MuxerSendCommand,
    _MuxerGetParameter,
    _MuxerSetParameter,
    NULL,
    _MuxerEmptyThisBuffer,
    NULL,
    _MuxerSetCallbacks,
    NULL
};

/************************************************************************
*   _MuxerProcessOneCommand
*   User:
*       Muxer
*   Description:
*       1.  Pop out one and only one command to process
*       2.  Return KAL_TRUE if any command has been processed
*       3.  Return KAL_FALSE otherwise
*
************************************************************************/
static kal_bool _MuxerProcessOneCommand(void)
{
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;
    VIDEO_COMM_STATE_T* const prCommState = &_prMgr->rCommState;
    VIDEO_COMMAND_TYPE_T eCmd = VIDEO_COMMAND_MAX;
    kal_uint32 u4CmdState;

    if (KAL_TRUE == VideoCommPopCommand(prCommState, &eCmd, &u4CmdState))
    {
        if (VIDEO_COMMAND_STATESET == eCmd)
        {
            switch (u4CmdState)
            {
            case VIDEO_STATE_INIT:
                _MuxerInit();
                break;

            case VIDEO_STATE_IDLE:
                _MuxerChangeState(MUXER_IDLING);
                _prMgr->u4VideoPort = VideoCommGetInputPortIndex(prCommState, VIDEO_PORT_VIDEO_DATA);
                _prMgr->u4AudioPort = VideoCommGetInputPortIndex(prCommState, VIDEO_PORT_AUDIO_DATA);
                break;

            case VIDEO_STATE_RUN:
                if (MUXER_IDLING == _prMgr->eInternalState)
                {
                    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

                    eError = _MuxerInitDriver();
                    _MuxerCheckReturnCode(eError);
                }
                _MuxerChangeState(MUXER_RUNNING);
                break;

            case VIDEO_STATE_STOP:
                _MuxerChangeState(MUXER_STOPPING);
                break;

            case VIDEO_STATE_CLOSE:
                _MuxerChangeState(MUXER_CLOSING);
                break;

            default:
                _MUXER_ASSERT();
                break;
            }
        }
        else
        {
            _MUXER_ASSERT();
        }

        return KAL_TRUE;
    }
    return KAL_FALSE;
}

/************************************************************************
*   _MuxerPackData
*   User:
*       Muxer
*   Description:
*       1.  Pack data to specific format for adaptation layer
*
************************************************************************/
static void _MuxerPackData(
    MUXER_PROCESS_PARAM_T* prData,
    kal_uint32 u4Section,
    MUXER_BUFFER_T * prBuffer)
{
    MUXER_BUFFER_T* prTmp= &prData->arData[u4Section];

    if (KAL_TRUE == prBuffer->fgValid)
    {
        prTmp->fgValid = prBuffer->fgValid;
        prTmp->pu1Addr = prBuffer->pu1Addr;
        prTmp->u4Size  = prBuffer->u4Size;
    }
    else
    {
        kal_mem_set((void*)prTmp, 0, sizeof(*prTmp));
    }
}

/************************************************************************
*   _MuxerSendData2Adapt
*   User:
*       Muxer
*   Description:
*       1.  Send packed data to adaptation layer
*
************************************************************************/
static void _MuxerSendData2Adapt(
    kal_uint32 u4FrameType,
    kal_uint32 u4DataType,
    MUXER_BUFFER_T* parBuffer0,
    MUXER_BUFFER_T* parBuffer1,
    void *pPrivateData,
    kal_uint64 u8TimeStamp
    )
{
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;
    MUXER_ADAPT_API_T*  const prAPI = _prMgr->prAdaptAPI;
    MUXER_PROCESS_PARAM_T rParam;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_MUXER_ERROR;

    rParam.u4DataType = u4DataType;
    rParam.u4FrameType = u4FrameType;
    rParam.u8TimeStamp = u8TimeStamp;
    rParam.pPrivateData = pPrivateData;

    _MuxerPackData(&rParam, 0, parBuffer0);
    _MuxerPackData(&rParam, 1, parBuffer1);

    drv_trace2(TRACE_GROUP_10, MUX_SEND_DATA_2_ADAPT, u4FrameType, u4DataType);
    eError = prAPI->pfnProcessData(&rParam);
    _MuxerCheckReturnCode(eError);
}

/************************************************************************
*   _MuxerStoreVideoData
*   User:
*       Muxer
*   Description:
*       1.  Store data address and size from buffer header
*
*   Remark:
*       1.  Assumed that one video frame could only be separated into tw-
*           o sections
*
************************************************************************/
static void _MuxerStoreVideoData(VIDEO_BUFFERHEADER_TYPE_T* prBuffer)
{
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;
    MUXER_BUFFER_T* prVideoData0 = &_prMgr->arVideoData[0];
    MUXER_BUFFER_T* prVideoData1 = &_prMgr->arVideoData[1];

    if (0 == prVideoData1->u4Size)
    {
        if (0 == prVideoData0->u4Size)
        {
            prVideoData0->fgValid = KAL_TRUE;
            prVideoData0->pu1Addr = prBuffer->pu1Buffer;
            prVideoData0->u4Size = prBuffer->u4BuffSize;
        }
        else if ((prVideoData0->pu1Addr + prVideoData0->u4Size) == prBuffer->pu1Buffer)
        {
            prVideoData0->u4Size += prBuffer->u4BuffSize;
        }
        else
        {
            prVideoData1->fgValid = KAL_TRUE;
            prVideoData1->pu1Addr = prBuffer->pu1Buffer;
            prVideoData1->u4Size = prBuffer->u4BuffSize;
        }
    }
    else
    {
        if ((prVideoData1->pu1Addr + prVideoData1->u4Size) == prBuffer->pu1Buffer)
        {
            prVideoData1->u4Size += prBuffer->u4BuffSize;
        }
        else
        {
            _MUXER_ASSERT();
        }
    }
}

/************************************************************************
*   _MuxerGetAudioBistream2Adapt
*   User:
*       Muxer
*   Description:
*       1.  Pop out one and only one buffer from audio input buffer to adapter
*
************************************************************************/
static kal_bool _MuxerGetAudioBistream2Adapt(void)
{
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;
    VIDEO_COMM_STATE_T* const prCommState = &_prMgr->rCommState;
    VIDEO_BUFFERHEADER_TYPE_T   rBuffer;
    MUXER_BUFFER_T arBuffer[2];
    kal_bool fgHasData = KAL_TRUE;

    arBuffer[0].fgValid = KAL_FALSE;
    arBuffer[1].fgValid = KAL_FALSE;

    if (KAL_TRUE == VideoCommPopInputBuffExt(prCommState, &rBuffer, MUXER_AUDIO_PORT))
    {
        if (_prMgr->u4AudioPort == rBuffer.u4InputPort)
        {
            arBuffer[0].fgValid = KAL_TRUE;
            arBuffer[0].pu1Addr = rBuffer.pu1Buffer;
            arBuffer[0].u4Size  = rBuffer.u4BuffSize;

            _MuxerSendData2Adapt(MX_FRAMETYPE_INTRA, MX_DATATYPE_AUDIO, &arBuffer[0], &arBuffer[1], NULL, rBuffer.u8TimeStamp);
        }
        else
        {
            _MUXER_ASSERT();
        }
    }
    else
    {
        fgHasData = KAL_FALSE;
    }

    return fgHasData;
}

/************************************************************************
*   _MuxerGetVideoBistream2Adapt
*   User:
*       Muxer
*   Description:
*       1.  Pop out one and only one buffer from video input buffer to adapter
*
************************************************************************/
static kal_bool _MuxerGetVideoBistream2Adapt(void)
{
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;
    VIDEO_COMM_STATE_T* const prCommState = &_prMgr->rCommState;
    VIDEO_BUFFERHEADER_TYPE_T   rBuffer;
    MUXER_BUFFER_T arBuffer[2];
    kal_bool fgHasData = KAL_TRUE;

    arBuffer[0].fgValid = KAL_FALSE;
    arBuffer[1].fgValid = KAL_FALSE;

    if (KAL_TRUE == VideoCommPopInputBuffExt(prCommState, &rBuffer, MUXER_VIDEO_PORT))
    {
        if (_prMgr->u4VideoPort == rBuffer.u4InputPort)
        {
            if (VIDEO_BUFFERFLAG_PARAMETERSET & rBuffer.eFlags)
            {
                arBuffer[0].fgValid = KAL_TRUE;
                arBuffer[0].pu1Addr = rBuffer.pu1Buffer;
                arBuffer[0].u4Size = rBuffer.u4BuffSize;
                _MuxerSendData2Adapt(MX_FRAMETYPE_INTER, MX_DATATYPE_VIDEO_SEQUENCE_HEADER, &arBuffer[0], &arBuffer[1], rBuffer.pPrivateData, 0);
            }
            else
            {
                _MuxerStoreVideoData(&rBuffer);
            }

            if (VIDEO_BUFFERFLAG_END_OF_FRAME & rBuffer.eFlags)
            {
                kal_uint32 u4FrameType;
                kal_uint64 u8TimeStamp = rBuffer.u8TimeStamp;

                kal_mem_cpy((void*)&arBuffer[0], (void*)&_prMgr->arVideoData[0], MAX_BUFFER_PARTITION * sizeof(_prMgr->arVideoData[0]));
                kal_mem_set((void*)&_prMgr->arVideoData[0], 0, MAX_BUFFER_PARTITION * sizeof(_prMgr->arVideoData[0]));
                if (VIDEO_BUFFERFLAG_SYNCFRAME & rBuffer.eFlags)
                {
                    u4FrameType = MX_FRAMETYPE_INTRA;
                }
                else
                {
                    u4FrameType = MX_FRAMETYPE_INTER;
                }
                _MuxerSendData2Adapt(u4FrameType, MX_DATATYPE_VIDEO, &arBuffer[0], &arBuffer[1], NULL, u8TimeStamp);
            }
        }
        else
        {
            _MUXER_ASSERT();
        }
    }
    else
    {
        fgHasData = KAL_FALSE;
    }

    return fgHasData;
}

/************************************************************************
*   _MuxerFlushBistream
*   User:
*       Muxer
*   Description:
*       1. Request adapter to flush specific data type
*
************************************************************************/
static void _MuxerFlushBistream(kal_uint32 u4DataType)
{
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;
    MUXER_WRITE_PARAM_T rWriteParam;

    if (NULL != _prMgr->prAdaptAPI)
    {
        rWriteParam.fgFlush = KAL_TRUE;
        rWriteParam.u4DataType = u4DataType;

        drv_trace0(TRACE_GROUP_10, MUX_FLUSH_BITSTREAM);
        _MuxerWriteData2File(&rWriteParam);
    }
}

/************************************************************************
*   _MuxerIsExternalQueueNotClear
*   User:
*       Muxer
*   Description:
*       1.  Check whether there's ILM in external queue
*       2.  Return KAL_FALSE if there is none
*
************************************************************************/
#define _MuxerIsExternalQueueNotClear(prCommState) VideoCommCheckProcessing(prCommState)

/************************************************************************
*
*   Exported Interface
*
************************************************************************/


/************************************************************************
*   GetVideoMuxerHandle
*   User:
*       IL
*   Description:
*       1.  Return Muxer's API to IL
*       2.  Initialize the context of Muxer
*
*   Remark:
*       1. Note that themutex cannot be clear
*
************************************************************************/
VIDEO_COMPONENT_TYPE_T* GetMuxerHandle(VIDEO_EXTMEM_HANDLER_T* prExtMemHdlr)
{
    MUXER_MGR_T* _prMgr = &_rMuxerMgr;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    drv_trace2(TRACE_GROUP_10, MUX_GETHDLR, (kal_uint32)prExtMemHdlr, (kal_uint32)_prMgr);

    kal_mem_set((void*)_prMgr, 0, sizeof(*_prMgr));
    _prMgr->prExtMemHdlr    =   prExtMemHdlr;
    _prMgr->rAdaptSettings.pawszFileNamePath = (kal_wchar *)VideoGetExtBuffer(_prMgr->prExtMemHdlr, FILE_NAME_PATH_SIZE);
    _prMgr->rAdaptSettings.pawszWorkingPath = (kal_wchar *)VideoGetExtBuffer(_prMgr->prExtMemHdlr, FILE_WORKING_PATH_SIZE);
    _prMgr->rAdaptSettings.pawszFileNamePath[0] = 0;
    _prMgr->rAdaptSettings.pawszWorkingPath[0] = 0;
    // Initialize component-wise parameters
    eError = _MuxerInitComponent();
    if (VIDEO_ERROR_NONE != eError)
    {
        _MUXER_ASSERT();
    }

    return (VIDEO_COMPONENT_TYPE_T*)&_rMuxerComp;
}

/************************************************************************
*   ReleaseVideoMuxerHandle
*   User:
*       IL
*   Description:
*       1.  Release the memory allocated in GetVideoMuxerHandle()
*           if there was any
*
************************************************************************/
VIDEO_ERROR_TYPE_T ReleaseMuxerHandle(VIDEO_COMPONENT_TYPE_T *prHandle)
{
    MUXER_MGR_T* _prMgr = &_rMuxerMgr;

    drv_trace2(TRACE_GROUP_10, MUX_RELEASEHDLR, (kal_uint32)prHandle, (kal_uint32)_prMgr);
    _MuxerDeInit();

    return VIDEO_ERROR_NONE;
}

/************************************************************************
*   GetMuxerMemorySize
*   User:
*       IL/Encoder
*   Description:
*       1. User calls this function to get memory size
*
************************************************************************/
kal_uint32  GetMuxerMemorySize(const MUXER_CONTAINER_TYPE_T eType, MUXER_SCENARIO_T eScenario)
{
    switch(eType)
    {
    case MUXER_CONTAINER_MP4:
        return VIDEO_V2_ENC_FW_EXT_MEMORY;
    case MUXER_CONTAINER_AVI:
        if (eScenario == MUXER_SCENARIO_RECORD)
        {
            return (VIDEO_V2_RECORDER_AVI_FW_EXT_MEM_SIZE);
        }
        else
        {
            return (__VE_VIDEO_V2_AVI_FW_EXT_MEMORY__);   // For file merge
        }
#if defined(__VE_SUPPORT_RTP_MUXER_ADAPTER__)		
	case MUXER_CONTAINER_RTP:
		return 	VIDEO_V2_ENC_FW_EXT_MEMORY;
#endif
    default:
        return 0;
    }
}


/************************************************************************
*   FillMuxerAudioBuffer
*   User:
*       IL
*   Description:
*       1. User calls this function to send audio data to Muxer
*
************************************************************************/
VIDEO_ERROR_TYPE_T FillMuxerAudioBuffer(kal_uint8 *pu1AudioBuf, kal_uint32 u4AudioSize)
{
    VIDEO_BUFFERHEADER_TYPE_T rBufferHeader;
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;

    // Fill buffer header
    kal_mem_set(&rBufferHeader, 0, sizeof(rBufferHeader));
    rBufferHeader.eFlags = VIDEO_BUFFERFLAG_NONE;
    rBufferHeader.u4InputPort = _prMgr->u4AudioPort;
    rBufferHeader.pu1Buffer = pu1AudioBuf;
    rBufferHeader.u4BuffSize = u4AudioSize;

    _MuxerEmptyThisBuffer(&rBufferHeader);

    return VIDEO_ERROR_NONE;
}

static MUXER_ACTIVITY_T _MuxerDecideActivity(void)
{
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;
    MUXER_ADAPT_SETTING_T* const prSetting = &_prMgr->rAdaptSettings;
    MUXER_STATE_T eState = _prMgr->eInternalState;
    MUXER_ACTIVITY_T eRet = MUXER_ACT_SUSPENDING;

    if (MUXER_SCENARIO_RECORD == prSetting->eScenario)
    {
        if (MUXER_RUNNING == eState)
        {
            if ((KAL_FALSE == _MuxerResendQ_IsQFull(&_prMgr->rAudioResendQMgr))
               ||(KAL_FALSE == _MuxerResendQ_IsQFull(&_prMgr->rVideoResendQMgr)))
            {
                eRet = MUXER_ACT_PROCESS_DATA;
            }
            else
            {
                eRet = MUXER_ACT_SUSPENDING;
            }
        }
        else
        {
            eRet = MUXER_ACT_SUSPENDING;
        }
    }
    else if (MUXER_SCENARIO_CREATE_FILE == prSetting->eScenario)
    {
        if (MUXER_RUNNING == eState)
        {
            if (KAL_FALSE == _prMgr->fgCreatedFile)
            {
                eRet = MUXER_ACT_CREATE_FILE;
            }
            else
            {
                eRet = MUXER_ACT_SUSPENDING;
            }
        }
    }

    return eRet;
}

/************************************************************************
*   MuxerMain
*   User:
*       VFILE task
*   Description:
*       1. Deal with the data-processing flow of the Muxer
*
************************************************************************/
void MuxerMain(ilm_struct *prILM)
{
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;
    VIDEO_COMM_STATE_T* const prCommState = &_prMgr->rCommState;
    MUXER_ADAPT_SETTING_T* const prSetting = &_prMgr->rAdaptSettings;
    if (_prMgr->fgStartWakeUpTimer == KAL_TRUE)
    {
        kal_cancel_timer(_prMgr->rTimerID);
        _prMgr->fgStartWakeUpTimer = KAL_FALSE;
    }

    VideoCommClrProcessing(prCommState);
    do
    {
        MUXER_STATE_T eState = _prMgr->eInternalState;
        MUXER_ADAPT_API_T*  const prAdaptAPI = _prMgr->prAdaptAPI;
        MUXER_ACTIVITY_T eAct = MUXER_ACT_SUSPENDING;
        kal_bool fgBreakLoop = KAL_FALSE;

        if (KAL_TRUE == _MuxerProcessOneCommand())
        {
            continue;
        }

        eAct = _MuxerDecideActivity();

        switch(eAct)
        {
            case MUXER_ACT_PROCESS_DATA:
            {
                kal_uint32 u4Ready2Enqueue = 0;
                kal_bool fgProcessedAudio = KAL_FALSE;
                kal_bool fgProcessedVideo = KAL_FALSE;

                u4Ready2Enqueue = _MuxerGetReturningBufferNumber(MUXER_GET_RETURNING_AUDIO_BUFFER_NUMBER);
                if (KAL_FALSE == _MuxerResendQ_IsQAbout2Full(&_prMgr->rAudioResendQMgr, u4Ready2Enqueue))
                {
                    fgProcessedAudio = _MuxerGetAudioBistream2Adapt();
                }
                _MuxerProcessCallbackEvent();

                if (KAL_FALSE == fgProcessedAudio)
                {
                    u4Ready2Enqueue = _MuxerGetReturningBufferNumber(MUXER_GET_RETURNING_VIDEO_BUFFER_NUMBER);
                    if (KAL_FALSE == _MuxerResendQ_IsQAbout2Full(&_prMgr->rVideoResendQMgr, u4Ready2Enqueue))
                    {
                        fgProcessedVideo = _MuxerGetVideoBistream2Adapt();
                    }
                    _MuxerProcessCallbackEvent();

                    if (KAL_FALSE == fgProcessedVideo)
                    {
                        fgBreakLoop = KAL_TRUE;
                        _MuxerReturnFromResendQ(VIDEO_PORT_VIDEO_DATA);
                        _MuxerReturnFromResendQ(VIDEO_PORT_AUDIO_DATA);
                    }
                }
            }
            break;
            case MUXER_ACT_CREATE_FILE:
            {
                VIDEO_ERROR_TYPE_T eRet = prAdaptAPI->pfnCreateFile();

                if (VIDEO_ERROR_NONE == eRet)
                {
                    _MuxerCallback2IL(VIDEO_EVENT_MUXER_FILE_CREATED, __LINE__);
                }
                else
                {
                    _MuxerCheckReturnCode(eRet);
                }

                if (eRet == VIDEO_ERROR_MUXER_ABORT_SAVING_DONE)
                {
                    _prMgr->fgAbortSavingOk = KAL_TRUE;
                }

                kal_take_mutex(_prMgr->rMuxerMutex);
                _prMgr->fgCreatedFile = KAL_TRUE;
                _MuxerAbortSavingCB();
                kal_give_mutex(_prMgr->rMuxerMutex);
            }
            break;
            case MUXER_ACT_SUSPENDING:
            {
                _MuxerReturnFromResendQ(VIDEO_PORT_VIDEO_DATA);
                _MuxerReturnFromResendQ(VIDEO_PORT_AUDIO_DATA);

                if (MUXER_STOPPING == eState)
                {
                    _MuxerChangeState(MUXER_STOPPED);
                }
                else if (MUXER_CLOSING == eState)
                {
                    if (KAL_FALSE == _MuxerIsExternalQueueNotClear(&_prMgr->rCommState))
                    {
                        if (MUXER_SCENARIO_RECORD == prSetting->eScenario)
                        {
                            if (KAL_TRUE == _prMgr->fgInitAdaptation)
                            {
                                _MuxerFlushBistream(MX_DATATYPE_ALL);
                            }
                        }
                        _prMgr->eInternalState = MUXER_CLOSED;
                        _prMgr->fgCompClosed = KAL_TRUE;
                        //_MuxerChangeState(MUXER_CLOSED);
                    }
                }
                fgBreakLoop = KAL_TRUE;
            }
            break;
            default:
                _MUXER_ASSERT();
            break;
        };

        if (KAL_TRUE == fgBreakLoop)
        {
            break;
        }

    } while(1);
}

/************************************************************************
*   _MuxerGetAdaptAPI
*   User:
*       Muxer
*   Description:
*       1.  Muxer calls this function to get API of adapatation layer wi-
*           th the container type specified
*
************************************************************************/
static MUXER_ADAPT_API_T* _MuxerGetAdaptAPI(MUXER_CONTAINER_TYPE_T eType)
{
    MUXER_ADAPT_API_T* prAdaptAPI = NULL;

    prAdaptAPI = _afnGetHandle[eType]();
    if (NULL == prAdaptAPI)
    {
        _MUXER_ASSERT();
    }
    return prAdaptAPI;
}

/************************************************************************
*   _MuxerGetInfoDirectly
*   User:
*       Muxer
*   Description:
*       1.  Muxer calls this function to get information from adaptation
*           direcrtly
*
************************************************************************/
static VIDEO_ERROR_TYPE_T _MuxerGetInfoDirectly(
    MUXER_CONTAINER_TYPE_T eContainer,
    VIDEO_PARAM_TYPE_T eType,
    void* pParam
    )
{
    MUXER_ADAPT_API_T* prAdaptAPI = _MuxerGetAdaptAPI(eContainer);
    return  prAdaptAPI->pfnDirectlyGetParam(eType, pParam);
}

/************************************************************************
*   MuxerIsTempFileExisted
*   User:
*       IL
*   Description:
*       1.  User calls this function to query whether temporary files al-
*           ready existed
************************************************************************/
kal_bool MuxerIsTempFileExisted(MUXER_CONTAINER_TYPE_T eType, kal_wchar* pwszWorkingPath)
{
    VIDEO_ERROR_TYPE_T rRet = VIDEO_ERROR_NONE;

    rRet = _MuxerGetInfoDirectly(eType, MUXER_IS_TEMP_FILE_EXISTED, (void*)pwszWorkingPath);
    if (VIDEO_ERROR_MUXER_EXIST_TEMP_FILE == rRet)
    {
        return KAL_TRUE;
    }
    else //should be VIDEO_ERROR_MUXER_EXIST_TEMP_FILE, but anyway
    {
        return KAL_FALSE;
    }
}

/************************************************************************
*   MuxerDeleteTempFile
*   User:
*       IL
*   Description:
*       1.  User calls this function to deleter temporary files
************************************************************************/
void MuxerDeleteTempFile(MUXER_CONTAINER_TYPE_T eType, kal_wchar* pwszWorkingPath)
{
    MUXER_ADAPT_API_T* prAdaptAPI = _MuxerGetAdaptAPI(eType);
    VIDEO_ERROR_TYPE_T rRet = VIDEO_ERROR_NONE;

    rRet = prAdaptAPI->pfnDirectlySetParam(MUXER_CLEAR_TEMP_FILE, (void*)pwszWorkingPath);
    if (VIDEO_ERROR_NONE != rRet)
    {
        _MUXER_ASSERT();
    }
}

/************************************************************************
*   MuxerGetMinSpaceToRecord
*   User:
*       IL
*   Description:
*       1.  User calls this function to get the minimum space to start r-
*           ecording
************************************************************************/
kal_uint32 MuxerGetMinSpaceToRecord(MUXER_CONTAINER_TYPE_T eType, kal_uint32 u4EncodeWidth, kal_uint32 u4EncodeHeight)
{
    MUXER_GET_MIN_SPACE_T rParam;

    rParam.u4Width = u4EncodeWidth;
    rParam.u4Height = u4EncodeHeight;
    _MuxerGetInfoDirectly(eType, MUXER_GET_MIN_SPACE_TO_RECORD, (void*)&rParam);
    return rParam.u4MinSpace;
}

void MuxerSetVideoWriteThreshold(MUXER_CONTAINER_TYPE_T eType, kal_uint32 u4WriteThreshold)
{
    MUXER_ADAPT_API_T* prAdaptAPI = _MuxerGetAdaptAPI(eType);
    VIDEO_ERROR_TYPE_T rRet = VIDEO_ERROR_NONE;

    rRet = prAdaptAPI->pfnDirectlySetParam(MUXER_SET_VIDEO_WRITE_THRESHOLD, (void*)&u4WriteThreshold);
    if (VIDEO_ERROR_NONE != rRet)
    {
        _MUXER_ASSERT();
    }
}

void MuxerSetAbortSaving(void)
{
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;

    kal_take_mutex(_prMgr->rMuxerMutex);
    _prMgr->fgAbortSaving = KAL_TRUE;
    _MuxerAbortSavingCB();
    kal_give_mutex(_prMgr->rMuxerMutex);
}


/************************************************************************
*   MuxerGetLeftOverOfVideoBitstream
*   User:
*       IL
*   Description:
*       1.  User calls this function to get the leftover of video bitstr-
*           eam
************************************************************************/
kal_uint32 MuxerGetLeftOverOfVideoBitstream(MUXER_CONTAINER_TYPE_T eType)
{
    kal_uint32 u4LeftOver= 0;

    _MuxerGetInfoDirectly(eType, MUXER_GET_VIDEO_BITSTREAM_LEFTOVER, (void*)&u4LeftOver);
    return u4LeftOver;
}

/************************************************************************
*   MuxerGetHeaderSizeOfAudioFile
*   User:
*       IL
*   Description:
*       1.  User calls this function to get the leftover of audio bitstr-
*           eam
************************************************************************/
kal_uint32 MuxerGetHeaderSizeOfAudioFile(MUXER_CONTAINER_TYPE_T eType)
{
    kal_uint32 u4AudioHeaderSize = 0;

    _MuxerGetInfoDirectly(eType, MUXER_GET_AUDIO_HEADERSIZE, (void*)&u4AudioHeaderSize);
    return u4AudioHeaderSize;
}

void MuxerRemoveFileName(kal_wchar *pu2FileName)
{
    kal_wchar *pu2Pos;

    pu2Pos = pu2FileName + kal_wstrlen(pu2FileName);
    while (pu2Pos > pu2FileName)
    {
        if (*pu2Pos == L'\\')
        {
            *(pu2Pos + 1) = 0;
            break;
        }
        pu2Pos--;
    }
}

kal_bool MuxerQueryAbortSaving(void)
{
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;
    return _prMgr->fgAbortSaving;
}

void MuxerGetDiskInfo(const kal_wchar * const pau2WorkingPath, kal_uint32 * const pu4ClusterSize, kal_uint64 * const pu8FreeDiskSize)
{
    // Get cluster size
    FS_DiskInfo rDiscInfo;
    kal_wchar   au2Drive[4] = L" :\\";
    au2Drive[0] = pau2WorkingPath[0];
    FS_GetDiskInfo(au2Drive, &rDiscInfo, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
    *pu4ClusterSize = rDiscInfo.BytesPerSector * rDiscInfo.SectorsPerCluster;
    *pu8FreeDiskSize = (kal_uint64)rDiscInfo.FreeClusters * (*pu4ClusterSize);
}

#ifdef __VE_SUPPORT_RTP_MUXER_ADAPTER__
kal_bool MuxerQueryStopState(void)
{
    MUXER_MGR_T* const _prMgr = &_rMuxerMgr;
    return _prMgr->fgGotStopCommand;
}
#endif


#ifdef __VE_DCM_WITH_COMPRESSION__
#pragma arm section code, rodata
#endif

void MuxerMainNonDCM(ilm_struct *prIlm)
{
    // Process Decoder normal jobs
    MuxerMain(prIlm);

    // Check if we should close Muxer
    // Split 'normal jobs' and 'close' to avoid DCM page fault issues
    {
        MUXER_MGR_T* const _prMgr =  &_rMuxerMgr;
        if (KAL_TRUE == _prMgr->fgCompClosed)
        {
            VideoCommChangeState(&_prMgr->rCommState, VIDEO_STATE_CLOSE);
        }
    }
}

#endif // __VE_SUPPORT_MUXER__
#endif // __VE_VIDEO_ARCHI_V2__
