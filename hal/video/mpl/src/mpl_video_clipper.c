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

/*******************************************************************************
 * Filename:
 * ---------
 * mpl_video_clipper.c
 *
 * Project:
 * --------
 * Maui
 *
 * Description:
 * ------------
 * This file implements the Media Porting Layer of video clipper.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by CQ. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 07 02 2012 tofar.huang
 * removed!
 * .
 *
 * 04 24 2012 tofar.huang
 * removed!
 * .
 *
 * 04 17 2012 tofar.huang
 * removed!
 * .
 *
 * 04 16 2012 tofar.huang
 * removed!
 * .
 *
 * 04 06 2012 tofar.huang
 * removed!
 * .
 *
 * 04 03 2012 tofar.huang
 * removed!
 * .
 *
 * 04 02 2012 tofar.huang
 * removed!
 * .
 *
 * 04 02 2012 tofar.huang
 * removed!
 * .
 *
 * 04 02 2012 tofar.huang
 * removed!
 * .
 *
 * 04 02 2012 tofar.huang
 * removed!
 * .
 *
 * 03 26 2012 tofar.huang
 * removed!
 * .
 *
 * 03 26 2012 tofar.huang
 * removed!
 * .
 *
 * 03 05 2012 tofar.huang
 * removed!
 * .
 *
 * 12 16 2011 tofar.huang
 * removed!
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by CQ. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "drv_features_video.h"

#pragma O0
#if defined(__VE_VIDEO_ARCHI_V2__)
#if defined(__VE_VIDEO_CLIPPER_SUPPORT__)

#include "kal_trace.h"

#include "video_types_v2.h"
#include "vcodec_v2_trc.h"
#include "video_comm_component_v2.h"

#include "visual_comm.h"
#include "mpl_common.h" // mpl common type definition
#include "mpl_clipper.h"
#include "mpl_video_clipper.h"
#include "mpl_session_mem.h"

#include "source_provider_if.h"
#include "video_muxer_if_v2.h"

/**
 * Macro for utility function
 */
#define MPLVR_DEVELOPMENT
#if defined(MPLVR_DEVELOPMENT)
#define MPLVC_TRACE(x, ...)             kal_trace(x, __VA_ARGS__)
#else
#define MPLVC_TRACE(x, ...)             { /* empty */ }
#endif  // defined(MPLVR_DEVELOPMENT)

#define _MPLVC_ASSERT(exp) if(!(exp)) {ASSERT(0);}
#define _MPLVC_ALLOC_EXT_MEM(client, size, type) (((mpl_clipper_client_t*)client)->mem_alloc_func(client, size, type, 0, 0))
#define _MPLVC_FREE_EXT_MEM(client, p, type) (((mpl_clipper_client_t*)client)->mem_free_func(client, p, type, 0, 0))
#define _MPLVC_INC_AND_WRAP_AROUND(value, size) \
            {   \
                value++;    \
                if (value >= size) {value = 0;} \
            }

#define OFFSET_OF(s,m) ((int)&(((s*)0)->m))
#define SELF(p, parent, member) (parent*)(((int)p) - OFFSET_OF(parent,member))
#define SWAP_4(x)    (((x & 0x000000FF) << 24) |    \
                     ((x & 0x0000FF00) <<  8) |     \
                     ((x & 0x00FF0000) >>  8) |     \
                     ((x & 0xFF000000) >> 24))
#define ZERO_MEMORY(addr, len)  kal_mem_set(addr, 0, len)

// Global manager
static MPLVC_MANAGER_T _rMplvcMgr;
static MPLVC_BUFFER_MGR_T *_prMplvcBufferMgr;

/**
 * Function Prototype
 */
extern kal_uint32 SaveAndSetIRQMask( void );
extern void   RestoreIRQMask( kal_uint32 );
void* _MPLVC_AllocMem(void *prClient, kal_uint32 u4Size, med_mem_type_enum eType);
void _MPLVC_FreeMem(void *prClient, void* p, med_mem_type_enum eType);
VIDEO_ERROR_TYPE_T _MPLVC_VIDEO_EmptyThisBuffer(void *pHandle, VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader);
VIDEO_ERROR_TYPE_T _MPLVC_AUDIO_EmptyThisBuffer(void *pHandle, VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader);
static void _MPLVC_DoFileMerge(void *const pParam1, void *const pParam2, void *const pParam3);
static void _MPLVC_MUXER_CloseFileMergeAsync(void *const pParam1, void *const pParam2, void *const pParam3);
static void _MPLVC_DoNotify(void *const pParam1, void *const pParam2, void *const pParam3);
static void _MPLVC_StopAndNotify(const mpl_clipper_event_t eEvent, const media_error_t eMError);
static void _MPLVC_WakeUp(const MPLVC_MESSAGE_T eMsgType);
static void _MPLVC_SendMessage(const module_type dest, const msg_type u4MessageType, const PFN_MPLVC_REDIRECTION_T pfnProc, void *const pParam1,
                                void *const pParam2, void *const pParam3);
static void _MPLVC_MakeAsyncCall(const module_type dest, const PFN_MPLVC_REDIRECTION_T pfnProc, void *const pParam1,
            void * const pParam2, void * const pParam3);
static void _MPLVC_SetParam2Comp(VIDEO_COMPONENT_TYPE_T *const prComponentHandle,
            const VIDEO_PARAM_TYPE_T eParamType, void *const pvParam);
typedef VIDEO_ERROR_TYPE_T (*PFN_PROCESSBUFFER)(VIDEO_BUFFERHEADER_TYPE_T *const prBuffHeader);

// The structure only is used by source
static const MPL_SESSION_MEM_API_T _rMPLVC_MemAPI =
{
    _MPLVC_AllocMem,
    _MPLVC_FreeMem
};

// The structure only is used by source
static const MPL_SESSION_EMPTY_BUFFER_API_T _rMPLVC_EmptyBufferAPI =
{
    _MPLVC_AUDIO_EmptyThisBuffer,
    _MPLVC_VIDEO_EmptyThisBuffer,
    NULL
};

#pragma arm section code = "SECONDARY_ROCODE"

/**
 *
 */
__inline static kal_bool _MPLVC_SetProcessing()
{
    kal_bool fgRet = KAL_FALSE;
    MPLVC_MANAGER_T *const prMplvcMgr = (MPLVC_MANAGER_T *)&_rMplvcMgr;
    kal_uint32 u4SavedMask;

    u4SavedMask = SaveAndSetIRQMask();  // TODO:
    if (prMplvcMgr->fgProcessing == KAL_FALSE)
    {
        prMplvcMgr->fgProcessing = KAL_TRUE;
        fgRet = KAL_TRUE;
    }
    RestoreIRQMask(u4SavedMask);
    return fgRet;
}

/**
 *
 */
__inline void _MPLVC_ClrProcessing()
{
    kal_uint32 u4SavedMask;
    MPLVC_MANAGER_T *const prMplvcMgr = (MPLVC_MANAGER_T *)&_rMplvcMgr;

    u4SavedMask = SaveAndSetIRQMask();
    if (prMplvcMgr->fgProcessing == KAL_FALSE)
    {
        _MPLVC_ASSERT(0);
    }
    prMplvcMgr->fgProcessing = KAL_FALSE;
    RestoreIRQMask(u4SavedMask);
}


/**
 *
 */
static void _MPLVC_SendMessage(const module_type dest, const msg_type u4MessageType, const PFN_MPLVC_REDIRECTION_T pfnProc, void *const pParam1,
                                void *const pParam2, void *const pParam3)
{
    MPLVC_ASYNC_CALL_T *prMsg = NULL;
    ilm_struct *prIlm = NULL;
    module_type eActiveModuleId = kal_get_active_module_id();

    prMsg = (MPLVC_ASYNC_CALL_T*) construct_local_para(sizeof(MPLVC_ASYNC_CALL_T), TD_CTRL);
    prMsg->pfnRedirect = pfnProc;
    prMsg->pParam1 = pParam1;
    prMsg->pParam2 = pParam2;
    prMsg->pParam3 = pParam3;

    prIlm = allocate_ilm(eActiveModuleId);
    prIlm->src_mod_id = eActiveModuleId;

    prIlm->dest_mod_id = dest;
    prIlm->sap_id = MED_SAP;

    prIlm->msg_id = (msg_type) u4MessageType;
    prIlm->local_para_ptr = (local_para_struct*) prMsg;
    prIlm->peer_buff_ptr = NULL;

    msg_send_ext_queue(prIlm);
}


/**
 *
 */
static void _MPLVC_WakeUp(const MPLVC_MESSAGE_T eMsgType)
{
    kal_bool fgSendMsg = KAL_FALSE;
    fgSendMsg = _MPLVC_SetProcessing();
    if (fgSendMsg == KAL_TRUE)
    {
        _MPLVC_SendMessage(MOD_VCODEC_V2, MSG_ID_MPLVC_DATA_IND, NULL, (void*)eMsgType, NULL, NULL);
    }
}


/**
 *
 */
static void _MPLVC_BUFFERMGR_WakeUp(void* pu1Void)
{
    _MPLVC_WakeUp(MSG_MPLVC_WAKEUP);
}

#pragma arm section code


/**
 *
 */
static void _MPLVC_StartTimer(MPLVC_MANAGER_T *const prMplvcMgr)
{
    const kal_uint16 u2TimeOutTick = 10;
    kal_mutexid rTimerMutexID = prMplvcMgr->rTimerMutexID;

    kal_take_mutex(rTimerMutexID);
    if (prMplvcMgr->fgStartWakeUpTimer == KAL_FALSE)
    {
        MPLVC_TRACE(TRACE_GROUP_5, MPLVC_TRC_SET_TIMER);
        kal_set_timer(prMplvcMgr->rTimerID, _MPLVC_BUFFERMGR_WakeUp, NULL, u2TimeOutTick, 0);
        prMplvcMgr->fgStartWakeUpTimer = KAL_TRUE;
    }
    kal_give_mutex(rTimerMutexID);
}

/**
 *
 */
static void _MPLVC_CancelTimer(MPLVC_MANAGER_T *const prMplvcMgr)
{
    kal_mutexid rTimerMutexID = prMplvcMgr->rTimerMutexID;

    kal_take_mutex(rTimerMutexID);
    if (prMplvcMgr->fgStartWakeUpTimer == KAL_TRUE)
    {
        kal_cancel_timer(prMplvcMgr->rTimerID);
        prMplvcMgr->fgStartWakeUpTimer = KAL_FALSE;
    }
    kal_give_mutex(rTimerMutexID);
}


/**
 * Send buffer to front-end (Source Component)
 */
__inline static VIDEO_ERROR_TYPE_T _MPLVC_BUFFERMGR_Send2FrontEnd(MPLVC_MANAGER_T *const prMplvcMgr, VIDEO_BUFFERHEADER_TYPE_T *const prBuffHeader)
{
    VIDEO_COMPONENT_MI_TYPE_T *prSourceHandle = prMplvcMgr->prSourceHandle;
    if (prSourceHandle != NULL)
    {
        return prSourceHandle->pfnFillThisBuffer(prMplvcMgr->prSourceCntx, prBuffHeader);
    }
    return VIDEO_ERROR_NONE;
}

/**
 * Send buffer to back-end (Muxer)
 */
static VIDEO_ERROR_TYPE_T _MPLVC_BUFFERMGR_Send2BackEnd(MPLVC_MANAGER_T *const prMplvcMgr,
                                                VIDEO_BUFFERHEADER_TYPE_T *const prBuffHeader,
                                                kal_uint8 *const pu1Buffer,
                                                const kal_uint32 u4BuffSize,
                                                const kal_uint64 *const pu8TimeStamp,
                                                const VIDEO_BUFFERFLAG_TYPE_T eFlags,
                                                const kal_uint32 u4InputPort,
                                                const kal_uint32 u4OutputPort)
{
    VIDEO_COMPONENT_TYPE_T *prMuxerHandle = prMplvcMgr->prMuxerHandle;
    if (prMuxerHandle != NULL)
    {
        // prBuffHeader might not yet be initialized.
        prBuffHeader->pu1Buffer = pu1Buffer;
        prBuffHeader->u4BuffSize = u4BuffSize;
        prBuffHeader->u8TimeStamp = *pu8TimeStamp;
        prBuffHeader->eFlags = eFlags;
        prBuffHeader->u4InputPort = u4InputPort;
        prBuffHeader->u4OutputPort = u4OutputPort;
        return prMplvcMgr->prMuxerHandle->pfnEmptyThisBuffer(prBuffHeader);
    }
    else
    {
        _MPLVC_ASSERT(0);
    }

    return VIDEO_ERROR_NONE;
}

/**
 * A utility function to get InputQ/ReturnQ/Bitstream Mgr according to port type.
 * If pointer is null, ignore it.
 */
static void _MPLVC_BUFFERMGR_GetMgr(const VIDEO_PORT_TYPE_T ePort,
                                    VIDEO_CORE_RING_BUFFER_MGR_T **const pprInputQMgr,
                                    VIDEO_CORE_RING_BUFFER_MGR_T **const pprReturnQMgr,
                                    MPLVC_BITSTEAM_MGR **const pprBitStreamMgr)
{
    if (ePort == VIDEO_PORT_VIDEO_DATA)
    {
        MPLVC_VIDEO_BUFFER_MGR_T *prVideoBufferMgr = &_prMplvcBufferMgr->rVideoBufferMgr;

        if (pprInputQMgr != NULL)
        {
            *pprInputQMgr = &prVideoBufferMgr->rInputQMgr;
        }

        if (pprReturnQMgr != NULL)
        {
            *pprReturnQMgr = &prVideoBufferMgr->rReturnQMgr;
        }

        if (pprBitStreamMgr != NULL)
        {
            *pprBitStreamMgr = &prVideoBufferMgr->rBitStreamMgr;
        }
    }
    else if (ePort == VIDEO_PORT_AUDIO_DATA)
    {
        MPLVC_AUDIO_BUFFER_MGR_T *prAudioBufferMgr = &_prMplvcBufferMgr->rAudioBufferMgr;

        if (pprInputQMgr != NULL)
        {
            *pprInputQMgr = &prAudioBufferMgr->rInputQMgr;
        }

        if (pprReturnQMgr != NULL)
        {
            *pprReturnQMgr = &prAudioBufferMgr->rReturnQMgr;
        }

        if (pprBitStreamMgr != NULL)
        {
            *pprBitStreamMgr = &prAudioBufferMgr->rBitStreamMgr;
        }
    }
}

/**
 * Check whether bitstream is almost full
 */
static kal_bool _MPLVC_BUFFERMGR_IsBitstreamFull(MPLVC_BITSTEAM_MGR *const prBitStreamMgr, const kal_uint32 u4BufferSize)
{
    if (u4BufferSize > (prBitStreamMgr->u4BitstreamSize - prBitStreamMgr->u4Used))
    {
        return KAL_TRUE;
    }
    return KAL_FALSE;
}

/**
 * Add new buffer to bitstream
 */
__inline static void _MPLVC_BUFFERMGR_AddBuffer2Bitstream(MPLVC_BITSTEAM_MGR *const prBitStreamMgr, kal_uint8 *const pu1Buffer, const kal_uint32 u4BufferSize)
{
    // the buffer have not yet wrap around, memcpy it directly.
    if ((prBitStreamMgr->u4WritePos + u4BufferSize) <= prBitStreamMgr->u4BitstreamSize)
    {
        kal_mem_cpy((prBitStreamMgr->pau1Buffer + prBitStreamMgr->u4WritePos), pu1Buffer, u4BufferSize);
        prBitStreamMgr->u4WritePos += u4BufferSize;

        if (prBitStreamMgr->u4WritePos == prBitStreamMgr->u4BitstreamSize)
        {
            prBitStreamMgr->u4WritePos = 0;
        }
    }
    else
    {
        // buffer wraps arcound
        kal_uint32 u4CopyPart1Size = prBitStreamMgr->u4BitstreamSize - prBitStreamMgr->u4WritePos;
        kal_uint32 u4CopyPart2Size = u4BufferSize - u4CopyPart1Size;

        kal_mem_cpy(prBitStreamMgr->pau1Buffer + prBitStreamMgr->u4WritePos, pu1Buffer, u4CopyPart1Size);
        kal_mem_cpy(prBitStreamMgr->pau1Buffer, pu1Buffer + u4CopyPart1Size, u4CopyPart2Size);

        prBitStreamMgr->u4WritePos = u4CopyPart2Size;
    }

    prBitStreamMgr->u4Used += u4BufferSize;
    prBitStreamMgr->u4CollectingSize += u4BufferSize;
}


/**
 *  Check whether buffer reachs threshold. If yes, return buffer address/size
 */
__inline static kal_bool _MPLVC_BUFFERMGR_GetBitstream(MPLVC_BITSTEAM_MGR *const prBitStreamMgr, const kal_bool fgEOS, kal_uint8 **const pu1Buffer, kal_uint32 *const pu4BufferSize)
{
    kal_bool fgFound = KAL_FALSE;
    const kal_uint32 u4Threshold = prBitStreamMgr->u4BitstreamThreshold;

    // If buffer reach threshold or EOS have got from source.
    if (prBitStreamMgr->u4CollectingSize >= u4Threshold || fgEOS == KAL_TRUE)
    {
        *pu1Buffer = prBitStreamMgr->pau1Buffer + prBitStreamMgr->u4ReadPos;
        if (fgEOS == KAL_TRUE)
        {
            *pu4BufferSize = prBitStreamMgr->u4CollectingSize;
        }
        else
        {
            *pu4BufferSize = u4Threshold;
        }

        prBitStreamMgr->u4ReadPos += *pu4BufferSize;
        prBitStreamMgr->u4CollectingSize -= *pu4BufferSize;

        if (prBitStreamMgr->u4ReadPos > prBitStreamMgr->u4BitstreamSize)
        {
            _MPLVC_ASSERT(0);   // TODO: Remove
        }
        else if (prBitStreamMgr->u4ReadPos == prBitStreamMgr->u4BitstreamSize)
        {
            prBitStreamMgr->u4ReadPos = 0;
        }

        fgFound = KAL_TRUE;
    }
    return fgFound;
}


/**
 * Add new buffer header to queue
 */
static void _MPLVC_BUFFERMGR_AddBuffer2Queue(VIDEO_CORE_RING_BUFFER_MGR_T *const prQMgr,
                                            VIDEO_BUFFERHEADER_TYPE_T *const prBuffHeader)
{
    VideoCoreInsertToHeadofRingBuffer(prQMgr, (kal_uint8 *)prBuffHeader);
}

/**
 *
 */
static VIDEO_ERROR_TYPE_T _MPLVC_BUFFERMGR_ReturnBufferFromReturnQ(const VIDEO_PORT_TYPE_T ePort, MPLVC_BUFFER_MGR_T *const prMplvcBufferMgr)
{
    VIDEO_ERROR_TYPE_T eVError = VIDEO_ERROR_NONE;
    VIDEO_CORE_RING_BUFFER_MGR_T *prReturnQMgr;
    MPLVC_MANAGER_T *const prMplvcMgr = prMplvcBufferMgr->prMplvcMgr;

    // We must wait parameter set return because parameter set contains private data
    if (prMplvcBufferMgr->rVideoBufferMgr.fgWaitForPS == KAL_TRUE)
    {
        return VIDEO_ERROR_NONE;
    }

    _MPLVC_BUFFERMGR_GetMgr(ePort, NULL, &prReturnQMgr, NULL);

    MPLVC_TRACE(TRACE_GROUP_5, MPLVC_TRC_RETURN_BUFFER_FROM_RETURN_QUEUE,
            ePort, prMplvcBufferMgr->rVideoBufferMgr.fgWaitForPS);
    do
    {
        VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader = (VIDEO_BUFFERHEADER_TYPE_T *)VideoCoreGetTailofRingBufferAddr(prReturnQMgr);

        if (prBuffHeader == NULL)
        {
            break;
        }

        // Front end output queue might be full
        eVError = _MPLVC_BUFFERMGR_Send2FrontEnd(prMplvcMgr, prBuffHeader);
        if (eVError != VIDEO_ERROR_NONE)
        {
            return eVError;
        }

        if (VideoCoreConsumeTailofRingBuffer(prReturnQMgr) == KAL_FALSE)
        {
            _MPLVC_ASSERT(0);
        }
    }while(1);

    return VIDEO_ERROR_NONE;

}


/**
 * Process parameter set
 */
__inline static VIDEO_ERROR_TYPE_T _MPLVC_BUFFERMGR_ProcessVideoParameterSet(VIDEO_BUFFERHEADER_TYPE_T *const prBuffHeader)
{
    VIDEO_ERROR_TYPE_T eVError = VIDEO_ERROR_NONE;
    VIDEO_BUFFERHEADER_TYPE_T rLocalBuffHeader;
    MPLVC_MANAGER_T *const prMplvcMgr = _prMplvcBufferMgr->prMplvcMgr;
    VIDEO_COMPONENT_TYPE_T *const prMuxerHandle = prMplvcMgr->prMuxerHandle;
    MPLVC_VIDEO_BUFFER_MGR_T *const prVideoBufferMgr = &_prMplvcBufferMgr->rVideoBufferMgr;

    rLocalBuffHeader = *prBuffHeader;
    rLocalBuffHeader.u4InputPort = 0; // TODO: workaround

    prVideoBufferMgr->fgWaitForPS = KAL_TRUE;

    // For H.264, extra effort to handle SPS/PPS
    if (prMplvcMgr->rSPVideoStream.eCodecType == MEDIA_CODEC_VID_H264)
    {
        SPIF_DECODE_PAYLOAD_T *prDecodePayload = prBuffHeader->pPrivateData;

        kal_uint32 nIdx = 0;
        const kal_uint32 nNum = prDecodePayload->u4PayloadNumber;
        kal_uint32 u4BufferOffset = 0;
        kal_uint8 *const pau1VOSBuffer = _prMplvcBufferMgr->au1VOSBuffer;
        H264_ENC_CONF_REC *const prH264Configuration = &_prMplvcBufferMgr->rH264Configuration;

        for(;nIdx < nNum; nIdx++)
        {
            SPIF_H264_DECODER_PAYLOAD_INFO_T *prH264DecoderPayload = &((SPIF_H264_DECODER_PAYLOAD_INFO_T *)(prDecodePayload->pu1PayloadAddress))[nIdx];
            kal_uint32 u4Data = SWAP_4(prH264DecoderPayload->u4Length);
            MPLVC_TRACE(TRACE_GROUP_4, MPLVC_TRC_H264_PAYLOAD, nIdx, nNum,
                    prH264DecoderPayload->u4Address, prH264DecoderPayload->u4Length);

            kal_mem_cpy(pau1VOSBuffer + u4BufferOffset, &u4Data, 4);
            u4BufferOffset += 4;
            kal_mem_cpy(pau1VOSBuffer + u4BufferOffset, (void *)prH264DecoderPayload->u4Address, prH264DecoderPayload->u4Length);
            u4BufferOffset += prH264DecoderPayload->u4Length;
        }

        {
            SPIF_AVC_CONF_RECORD_T rSPIFAvcConf;
            VIDEO_COMPONENT_MI_TYPE_T *const prSourceHandle = prMplvcMgr->prSourceHandle;
            eVError = prSourceHandle->pfnGetParameter(prMplvcMgr->prSourceCntx, VIDEO_PARAM_SOURCE_PROVIDER_AVC_CONF_RECORD, &rSPIFAvcConf);
            if (eVError != VIDEO_ERROR_NONE)
            {
                _MPLVC_ASSERT(0);
            }
            ZERO_MEMORY(prH264Configuration, sizeof(*prH264Configuration));
            prH264Configuration->u1LevelIDC = rSPIFAvcConf.AVCLevelIndication;
            prH264Configuration->u1ProfileComp = rSPIFAvcConf.profile_compatibility;
            prH264Configuration->u1ProfileIDC = rSPIFAvcConf.AVCProfileIndication;
            prH264Configuration->u1LengthMinusOne = rSPIFAvcConf.lengthSizeMinusOne;
            prH264Configuration->u1NumOfPPS = 1;    // TODO:
            prH264Configuration->u1NumOfSPS = 1;
        }

        rLocalBuffHeader.pPrivateData = (void *)prH264Configuration;
        rLocalBuffHeader.pu1Buffer = pau1VOSBuffer;
        rLocalBuffHeader.u4BuffSize = u4BufferOffset;
    }

    eVError = prMuxerHandle->pfnEmptyThisBuffer(&rLocalBuffHeader);
    if (eVError != VIDEO_ERROR_NONE)
    {
        _MPLVC_ASSERT(0);
    }

    return eVError;
}


/**
 * Process video end-of-stream
 */
__inline static VIDEO_ERROR_TYPE_T _MPLVC_BUFFERMGR_ProcessVideoEOS(VIDEO_BUFFERHEADER_TYPE_T *const prBuffHeader)
{
    VIDEO_ERROR_TYPE_T eVError = VIDEO_ERROR_NONE;
    VIDEO_BUFFERHEADER_TYPE_T rLocalBuffHeader;

    MPLVC_MANAGER_T *const prMplvcMgr = _prMplvcBufferMgr->prMplvcMgr;
    VIDEO_COMPONENT_TYPE_T *const prMuxerHandle = prMplvcMgr->prMuxerHandle;
    MPLVC_VIDEO_BUFFER_MGR_T *const prVideoBufferMgr = &_prMplvcBufferMgr->rVideoBufferMgr;

    // Send unfinsihed buffer
    if (prVideoBufferMgr->fgNeed2Resend == KAL_TRUE)
    {
        eVError = prMuxerHandle->pfnEmptyThisBuffer(&prVideoBufferMgr->rResendBufferHeader);
        if (eVError != VIDEO_ERROR_NONE)
        {
            return VIDEO_ERROR_BUFF_FULL;
        }

        prVideoBufferMgr->fgNeed2Resend = KAL_FALSE;
    }

    rLocalBuffHeader = *prBuffHeader;
    rLocalBuffHeader.u4InputPort = 0; // TODO: workaround

    eVError = prMuxerHandle->pfnEmptyThisBuffer(&rLocalBuffHeader);
    if (eVError != VIDEO_ERROR_NONE)
    {
        //_MPLVC_ASSERT(0);
    }

    return eVError;
}


/**
 * Process video stream
 */
__inline static VIDEO_ERROR_TYPE_T _MPLVC_BUFFERMGR_ProcessVideoStream(VIDEO_BUFFERHEADER_TYPE_T *const prBuffHeader)
{
    VIDEO_ERROR_TYPE_T eVError = VIDEO_ERROR_NONE;
    MPLVC_MANAGER_T *const prMplvcMgr = _prMplvcBufferMgr->prMplvcMgr;
    VIDEO_COMPONENT_TYPE_T *const prMuxerHandle = prMplvcMgr->prMuxerHandle;
    MPLVC_VIDEO_BUFFER_MGR_T *const prVideoBufferMgr = &_prMplvcBufferMgr->rVideoBufferMgr;
    MPLVC_BITSTEAM_MGR *const prBitStreamMgr = &prVideoBufferMgr->rBitStreamMgr;
    VIDEO_BUFFERHEADER_TYPE_T rLocalBuffHeader;
    kal_uint8 *const pu1Buffer = prBuffHeader->pu1Buffer;
    const kal_uint32 u4BufferSize = prBuffHeader->u4BuffSize;
    const kal_uint64 u8AdjustedTimeStamp = prBuffHeader->u8TimeStamp - prMplvcMgr->u8BaseFrameTime;

    if (_MPLVC_BUFFERMGR_IsBitstreamFull(prBitStreamMgr, u4BufferSize) == KAL_TRUE)
    {
        MPLVC_TRACE(TRACE_GROUP_5, MPLVC_TRC_BITSTREAM_FULL,
                VIDEO_PORT_VIDEO_DATA, u4BufferSize, prBitStreamMgr->u4BitstreamSize - prBitStreamMgr->u4Used);

        return VIDEO_ERROR_BUFF_FULL;
    }


    // Send unfinsihed buffer
    if (prVideoBufferMgr->fgNeed2Resend == KAL_TRUE)
    {
        eVError = prMuxerHandle->pfnEmptyThisBuffer(&prVideoBufferMgr->rResendBufferHeader);
        if (eVError != VIDEO_ERROR_NONE)
        {
            return VIDEO_ERROR_BUFF_FULL;
        }

        prVideoBufferMgr->fgNeed2Resend = KAL_FALSE;
    }

    // Buffer don't wrap around
    if ((prBitStreamMgr->u4WritePos + u4BufferSize) <= prBitStreamMgr->u4BitstreamSize)
    {
        kal_mem_cpy((prBitStreamMgr->pau1Buffer + prBitStreamMgr->u4WritePos), pu1Buffer, u4BufferSize);
        eVError = _MPLVC_BUFFERMGR_Send2BackEnd(prMplvcMgr,
                                                &rLocalBuffHeader,
                                                prBitStreamMgr->pau1Buffer + prBitStreamMgr->u4WritePos,
                                                u4BufferSize,
                                                &u8AdjustedTimeStamp,
                                                prBuffHeader->eFlags,
                                                0, // TODO: workaround
                                                prBuffHeader->u4OutputPort);


        if (eVError != VIDEO_ERROR_NONE)
        {
            return VIDEO_ERROR_BUFF_FULL;
        }

        prBitStreamMgr->u4WritePos += u4BufferSize;
        if (prBitStreamMgr->u4WritePos == prBitStreamMgr->u4BitstreamSize)
        {
            prBitStreamMgr->u4WritePos = 0;
        }
    }
    else
    {
        const kal_uint32 u4CopyPart1Size = prBitStreamMgr->u4BitstreamSize - prBitStreamMgr->u4WritePos;
        const kal_uint32 u4CopyPart2Size = u4BufferSize - u4CopyPart1Size;

        kal_mem_cpy(prBitStreamMgr->pau1Buffer + prBitStreamMgr->u4WritePos, pu1Buffer, u4CopyPart1Size);
        kal_mem_cpy(prBitStreamMgr->pau1Buffer, pu1Buffer + u4CopyPart1Size, u4CopyPart2Size);

        // Buffer is divided into two partition
        // First partition
        eVError = _MPLVC_BUFFERMGR_Send2BackEnd(prMplvcMgr,
                                    &rLocalBuffHeader,
                                    prBitStreamMgr->pau1Buffer + prBitStreamMgr->u4WritePos,
                                    u4CopyPart1Size,
                                    &u8AdjustedTimeStamp,
                                    (VIDEO_BUFFERFLAG_TYPE_T)(prBuffHeader->eFlags & (~(VIDEO_BUFFERFLAG_END_OF_FRAME))),
                                    0, // TODO: workaround
                                    prBuffHeader->u4OutputPort);

        if (eVError != VIDEO_ERROR_NONE)
        {
            return VIDEO_ERROR_BUFF_FULL;
        }

        // Second partition, if we can't send the buffer, queue it to resend buffer
        eVError = _MPLVC_BUFFERMGR_Send2BackEnd(prMplvcMgr,
                                    &rLocalBuffHeader,
                                    prBitStreamMgr->pau1Buffer,
                                    u4CopyPart2Size,
                                    &u8AdjustedTimeStamp,
                                    (VIDEO_BUFFERFLAG_TYPE_T)(prBuffHeader->eFlags | VIDEO_BUFFERFLAG_END_OF_FRAME),
                                    0, // TODO: workaround
                                    prBuffHeader->u4OutputPort);


        if (eVError != VIDEO_ERROR_NONE)
        {
            VIDEO_BUFFERHEADER_TYPE_T *prResendBufferHeader = &prVideoBufferMgr->rResendBufferHeader;
            *prResendBufferHeader = rLocalBuffHeader;
            prVideoBufferMgr->fgNeed2Resend = KAL_TRUE;;
        }

        prBitStreamMgr->u4WritePos = u4CopyPart2Size;
    }

    prBitStreamMgr->u4Used += u4BufferSize;
    prBitStreamMgr->u4CollectingSize += u4BufferSize;
    _prMplvcBufferMgr->u4VProgress = (u8AdjustedTimeStamp / 1000) * 100 / prMplvcMgr->u4ClipDuration;

    return eVError;
}

/**
 * Process video depending on buffer type
 */
static VIDEO_ERROR_TYPE_T _MPLVC_BUFFERMGR_ProcessVideo(VIDEO_BUFFERHEADER_TYPE_T *const prBuffHeader)
{
    VIDEO_ERROR_TYPE_T eVError = VIDEO_ERROR_NONE;

    MPLVC_TRACE(TRACE_GROUP_5, MPLVC_TRC_PROCESS_VIDEO_BUFFER, (kal_uint32)prBuffHeader->pu1Buffer, prBuffHeader->u4BuffSize, prBuffHeader->eFlags, (kal_uint32)(prBuffHeader->u8TimeStamp >> 32), (kal_uint32)(prBuffHeader->u8TimeStamp & 0xFFFFFFFF));

    if (prBuffHeader->eFlags & VIDEO_BUFFERFLAG_PARAMETERSET)
    {
        eVError = _MPLVC_BUFFERMGR_ProcessVideoParameterSet(prBuffHeader);
    }

    else if (prBuffHeader->eFlags & VIDEO_BUFFERFLAG_EOF)
    {
        eVError = _MPLVC_BUFFERMGR_ProcessVideoEOS(prBuffHeader);
    }
    else
    {
        eVError = _MPLVC_BUFFERMGR_ProcessVideoStream(prBuffHeader);
    }

    return eVError;
}

/**
 *
 */
static VIDEO_ERROR_TYPE_T _MPLVC_BUFFERMGR_SendAudioStream(const kal_bool fgEOS)
{
    VIDEO_ERROR_TYPE_T eVError = VIDEO_ERROR_NONE;
    MPLVC_MANAGER_T *const prMplvcMgr = _prMplvcBufferMgr->prMplvcMgr;
    MPLVC_BITSTEAM_MGR *const prBitStreamMgr = &_prMplvcBufferMgr->rAudioBufferMgr.rBitStreamMgr;

    VIDEO_BUFFERHEADER_TYPE_T rLocalBuffHeader;
    ZERO_MEMORY(&rLocalBuffHeader, sizeof(rLocalBuffHeader));

    // Query whether bitstream is reached to threshold
    if (_MPLVC_BUFFERMGR_GetBitstream(prBitStreamMgr,
        fgEOS, &rLocalBuffHeader.pu1Buffer, &rLocalBuffHeader.u4BuffSize) == KAL_TRUE)
    {
        rLocalBuffHeader.u4InputPort = 1; // TODO: workaround
        eVError = prMplvcMgr->prMuxerHandle->pfnEmptyThisBuffer(&rLocalBuffHeader);
        if (eVError != VIDEO_ERROR_NONE)
        {
            _MPLVC_ASSERT(0);
        }
        prBitStreamMgr->u4BitstreamThreshold = MPLVC_ONE_AUDIO_BUFFER_SIZE;
    }

    return eVError;
}

/**
 * Process audio
 */
static VIDEO_ERROR_TYPE_T _MPLVC_BUFFERMGR_ProcessAudio(VIDEO_BUFFERHEADER_TYPE_T *const prBuffHeader)
{
    VIDEO_ERROR_TYPE_T eVError = VIDEO_ERROR_NONE;
    MPLVC_MANAGER_T *const prMplvcMgr = _prMplvcBufferMgr->prMplvcMgr;
    MPLVC_BITSTEAM_MGR *const prBitStreamMgr = &_prMplvcBufferMgr->rAudioBufferMgr.rBitStreamMgr;
    const kal_uint32 u4BufferSize = prBuffHeader->u4BuffSize;
    kal_uint8 * const pu1Buffer = prBuffHeader->pu1Buffer;
    const kal_uint64 u8AdjustedTimeStamp = prBuffHeader->u8TimeStamp - prMplvcMgr->u8BaseFrameTime;

    if (_MPLVC_BUFFERMGR_IsBitstreamFull(prBitStreamMgr, u4BufferSize) == KAL_TRUE)
    {
        MPLVC_TRACE(TRACE_GROUP_5, MPLVC_TRC_BITSTREAM_FULL,
                VIDEO_PORT_AUDIO_DATA, u4BufferSize, prBitStreamMgr->u4BitstreamSize - prBitStreamMgr->u4Used);

        return VIDEO_ERROR_BUFF_FULL;
    }

    if (prBuffHeader->eFlags & VIDEO_BUFFERFLAG_EOF)
    {
        _MPLVC_BUFFERMGR_SendAudioStream(KAL_TRUE);

        // Send EOS
        {
            const kal_uint32 u4OriInputPort = prBuffHeader->u4InputPort;
            prBuffHeader->u4InputPort = 1; // TODO: workaround
            eVError = prMplvcMgr->prMuxerHandle->pfnEmptyThisBuffer(prBuffHeader);
            if (eVError != VIDEO_ERROR_NONE)
            {
                _MPLVC_ASSERT(0);
            }
            prBuffHeader->u4InputPort = u4OriInputPort;
        }
    }
    else
    {
        // Add buffer to bitstream
        _MPLVC_BUFFERMGR_AddBuffer2Bitstream(prBitStreamMgr, pu1Buffer, u4BufferSize);
        _MPLVC_BUFFERMGR_SendAudioStream(KAL_FALSE);
    }

    _prMplvcBufferMgr->u4AProgress = (u8AdjustedTimeStamp / 1000) * 100 / prMplvcMgr->u4ClipDuration;

    return eVError;
}

/**
 *
 */
static VIDEO_ERROR_TYPE_T _MPLVC_BUFFERMGR_DoNothing(VIDEO_BUFFERHEADER_TYPE_T *const prBuffHeader)
{
    return VIDEO_ERROR_NONE;
}


/**
 *
 */
static VIDEO_ERROR_TYPE_T _MPLVC_BUFFERMGR_ProcessInputQ(const VIDEO_PORT_TYPE_T ePort, MPLVC_BUFFER_MGR_T *const prMplvcBufferMgr, PFN_PROCESSBUFFER pfnProcessData)
{
    VIDEO_ERROR_TYPE_T eVError = VIDEO_ERROR_NONE;

    kal_mutexid rMutexID = prMplvcBufferMgr->rMutexID;
    VIDEO_CORE_RING_BUFFER_MGR_T *prReturnQMgr;
    VIDEO_CORE_RING_BUFFER_MGR_T *prInputQMgr;

    _MPLVC_BUFFERMGR_GetMgr(ePort, &prInputQMgr, &prReturnQMgr, NULL);

    do
    {
        VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader = NULL;

        kal_take_mutex(rMutexID);
        _MPLVC_BUFFERMGR_ReturnBufferFromReturnQ(ePort, prMplvcBufferMgr);

        if (VideoCoreIsRingBufferFull(prReturnQMgr) == KAL_TRUE)
        {
            kal_give_mutex(rMutexID);
            break;
        }

        prBuffHeader = (VIDEO_BUFFERHEADER_TYPE_T *)VideoCoreGetTailofRingBufferAddr(prInputQMgr);
        if (prBuffHeader == NULL)
        {
            kal_give_mutex(rMutexID);
            break;
        }
        kal_give_mutex(rMutexID);

        eVError = pfnProcessData(prBuffHeader);
        if (eVError != VIDEO_ERROR_NONE)
        {
            break;
        }

        kal_take_mutex(rMutexID);
        if (VideoCoreConsumeTailofRingBuffer(prInputQMgr) == KAL_FALSE)
        {
            _MPLVC_ASSERT(0);
        }

        // Add buffer to return queue
        _MPLVC_BUFFERMGR_AddBuffer2Queue(prReturnQMgr, prBuffHeader);
        kal_give_mutex(rMutexID);
    }while(1);


    return eVError;
}


/**
 *
 */
static kal_bool _MPLVC_BUFFERMGR_IsAnyQNotEmpty(MPLVC_BUFFER_MGR_T *const prMplvcBufferMgr)
{
    VIDEO_CORE_RING_BUFFER_MGR_T *const prVInputQMgr = &prMplvcBufferMgr->rVideoBufferMgr.rInputQMgr;
    VIDEO_CORE_RING_BUFFER_MGR_T *const prVReturnQMgr = &prMplvcBufferMgr->rVideoBufferMgr.rReturnQMgr;
    VIDEO_CORE_RING_BUFFER_MGR_T *const prAInputQMgr = &prMplvcBufferMgr->rAudioBufferMgr.rInputQMgr;
    VIDEO_CORE_RING_BUFFER_MGR_T *const prAReturnQMgr = &prMplvcBufferMgr->rAudioBufferMgr.rReturnQMgr;

    if (VideoCoreIsRingBufferEmpty(prVInputQMgr) == KAL_FALSE ||
        VideoCoreIsRingBufferEmpty(prVReturnQMgr) == KAL_FALSE ||
        VideoCoreIsRingBufferEmpty(prAInputQMgr) == KAL_FALSE ||
        VideoCoreIsRingBufferEmpty(prAReturnQMgr) == KAL_FALSE)
    {
        return KAL_TRUE;
    }

    return KAL_FALSE;
}

/**
 *
 */
__inline static VIDEO_ERROR_TYPE_T _MPLVC_BUFFERMGR_AddBuffer(const VIDEO_PORT_TYPE_T ePort, VIDEO_BUFFERHEADER_TYPE_T *const prBuffHeader)
{
    VIDEO_CORE_RING_BUFFER_MGR_T *prInputQMgr;
    VIDEO_CORE_RING_BUFFER_MGR_T *prReturnQMgr;
    kal_mutexid rMutexID = _prMplvcBufferMgr->rMutexID;
    kal_bool fgInputQFull = KAL_FALSE, fgReturnQFull = KAL_FALSE;

    _MPLVC_BUFFERMGR_GetMgr(ePort, &prInputQMgr, &prReturnQMgr, NULL);

    kal_take_mutex(rMutexID);
    fgInputQFull = VideoCoreIsRingBufferFull(prInputQMgr);
    //fgReturnQFull = VideoCoreIsRingBufferFull(prReturnQMgr);
    //if (fgInputQFull || fgReturnQFull)
    if (fgInputQFull == KAL_TRUE)
    {
        MPLVC_TRACE(TRACE_GROUP_5, MPLVC_TRC_QUEUE_FULL, fgInputQFull, fgReturnQFull);
        kal_give_mutex(rMutexID);
        return VIDEO_ERROR_BUFF_FULL;
    }

    _MPLVC_BUFFERMGR_AddBuffer2Queue(prInputQMgr, prBuffHeader);

    kal_give_mutex(rMutexID);

    return VIDEO_ERROR_NONE;
}

/**
 *
 */
__inline static VIDEO_ERROR_TYPE_T _MPLVC_BUFFERMGR_FreeBuffer(const VIDEO_PORT_TYPE_T ePort, VIDEO_BUFFERHEADER_TYPE_T *const prBuffHeader)
{
    MPLVC_BUFFER_MGR_T *const prMplvcBufferMgr = _prMplvcBufferMgr;
    kal_mutexid rMutexID = prMplvcBufferMgr->rMutexID;
    MPLVC_BITSTEAM_MGR *prBitStreamMgr;
    VIDEO_CORE_RING_BUFFER_MGR_T *prReturnQMgr;
    const kal_bool fgIsEOS = (prBuffHeader->eFlags & VIDEO_BUFFERFLAG_EOF) ? KAL_TRUE : KAL_FALSE;
    const kal_bool fgIsPS = (prBuffHeader->eFlags & VIDEO_BUFFERFLAG_PARAMETERSET) ? KAL_TRUE : KAL_FALSE;

    _MPLVC_BUFFERMGR_GetMgr(ePort, NULL, &prReturnQMgr, &prBitStreamMgr);

    kal_take_mutex(rMutexID);

    if (ePort == VIDEO_PORT_VIDEO_DATA)
    {
        if (fgIsEOS == KAL_FALSE && fgIsPS == KAL_FALSE)
        {
            prBitStreamMgr->u4Used -= prBuffHeader->u4BuffSize;
        }
        else if(fgIsPS == KAL_TRUE)
        {
            prMplvcBufferMgr->rVideoBufferMgr.fgWaitForPS = KAL_FALSE;
        }
    }
    else if(ePort == VIDEO_PORT_AUDIO_DATA)
    {
        prBitStreamMgr->u4Used -= prBuffHeader->u4BuffSize;
    }
    else
    {
        _MPLVC_ASSERT(0);
    }
    _MPLVC_WakeUp(MSG_MPLVC_FILLBUFFER);
    //_MPLVC_BUFFERMGR_ReturnBufferFromReturnQ(ePort, prMplvcBufferMgr);
    kal_give_mutex(rMutexID);

    return VIDEO_ERROR_NONE;
}

/**
 *
 */
__inline static void _MPLVC_BUFFERMGR_Main(void)
{
    MPLVC_MANAGER_T *const prMplvcMgr = _prMplvcBufferMgr->prMplvcMgr;

    if (prMplvcMgr->fgDiskFull == KAL_FALSE &&
        prMplvcMgr->fgStopped == KAL_FALSE)
    {
        _MPLVC_BUFFERMGR_ProcessInputQ(VIDEO_PORT_VIDEO_DATA, _prMplvcBufferMgr, _MPLVC_BUFFERMGR_ProcessVideo);
        _MPLVC_BUFFERMGR_ProcessInputQ(VIDEO_PORT_AUDIO_DATA, _prMplvcBufferMgr, _MPLVC_BUFFERMGR_ProcessAudio);
    }
    else
    {
        _MPLVC_BUFFERMGR_ProcessInputQ(VIDEO_PORT_VIDEO_DATA, _prMplvcBufferMgr, _MPLVC_BUFFERMGR_DoNothing);
        _MPLVC_BUFFERMGR_ProcessInputQ(VIDEO_PORT_AUDIO_DATA, _prMplvcBufferMgr, _MPLVC_BUFFERMGR_DoNothing);
    }

    // If any queue is not empty, we must set timer to do unfinished work.
    if (_MPLVC_BUFFERMGR_IsAnyQNotEmpty(_prMplvcBufferMgr) == KAL_TRUE &&
        prMplvcMgr->fgStopped == KAL_FALSE)
    {
        _MPLVC_StartTimer(prMplvcMgr);
    }
}

/**
 *
 */
__inline static void _MPLVC_BUFFERMGR_SetLeftover(const MUXER_CONTAINER_TYPE_T eMuxerContainerType)
{
    MuxerSetVideoWriteThreshold(eMuxerContainerType, MPLVC_ONE_VIDEO_BUFFER_SIZE);
    {
        MPLVC_BITSTEAM_MGR *const prVBitStreamMgr = &_prMplvcBufferMgr->rVideoBufferMgr.rBitStreamMgr;
        const kal_uint32 u4LeftoverOfFirstThreshold = MuxerGetLeftOverOfVideoBitstream(eMuxerContainerType);

        prVBitStreamMgr->u4ReadPos = prVBitStreamMgr->u4BitstreamSize - u4LeftoverOfFirstThreshold;
        prVBitStreamMgr->u4WritePos = prVBitStreamMgr->u4ReadPos;
    }

    {
        MPLVC_BITSTEAM_MGR *const prABitStreamMgr = &_prMplvcBufferMgr->rAudioBufferMgr.rBitStreamMgr;
        const kal_uint32 u4AudioHeaderSize = MuxerGetHeaderSizeOfAudioFile(eMuxerContainerType);

        prABitStreamMgr->u4ReadPos = u4AudioHeaderSize;
        prABitStreamMgr->u4WritePos = u4AudioHeaderSize;
        prABitStreamMgr->u4BitstreamThreshold = (MPLVC_ONE_AUDIO_BUFFER_SIZE) - u4AudioHeaderSize;
    }
    MuxerSetVideoWriteThreshold(eMuxerContainerType, 0); // Restore
}

/**
 *
 */
__inline static kal_uint32 _MPLVC_BUFFERMGR_GetProgress(void)
{
    return (_prMplvcBufferMgr->u4AProgress + _prMplvcBufferMgr->u4VProgress) >> 1;
}

/**
 *
 */
__inline static void _MPLVC_BUFFERMGR_Init(MPLVC_MANAGER_T *const prMplvcMgr)
{
    MPLVC_BITSTEAM_MGR   *prBitStreamMgr;
    VIDEO_CORE_RING_BUFFER_MGR_T    *prReturnQMgr;
    VIDEO_CORE_RING_BUFFER_MGR_T    *prInputQMgr;

    _prMplvcBufferMgr = (MPLVC_BUFFER_MGR_T *)_MPLVC_AllocMem(prMplvcMgr, sizeof(MPLVC_BUFFER_MGR_T), MED_MEM_CACHE);

    if (_prMplvcBufferMgr == NULL)
    {
        _MPLVC_ASSERT(0);
    }

    ZERO_MEMORY(_prMplvcBufferMgr, sizeof(*_prMplvcBufferMgr));

    // Initialize video buffer manager
    _MPLVC_BUFFERMGR_GetMgr(VIDEO_PORT_VIDEO_DATA, &prInputQMgr, &prReturnQMgr, &prBitStreamMgr);
    prBitStreamMgr->pau1Buffer = (kal_uint8 *)_MPLVC_AllocMem(prMplvcMgr, MAX_VIDEO_BITSTREAM_SIZE, MED_MEM_CACHE);
    _MPLVC_ASSERT(prBitStreamMgr->pau1Buffer != NULL);

    prBitStreamMgr->u4BitstreamSize = MAX_VIDEO_BITSTREAM_SIZE;

    VideoCoreInitRingBuffer(prInputQMgr,
                            (kal_uint8 *)_prMplvcBufferMgr->arVideoInputQ,
                            MAX_VIDEO_INPUT_QUEUE_SIZE,
                            sizeof(VIDEO_BUFFERHEADER_TYPE_T));

    VideoCoreInitRingBuffer(prReturnQMgr,
                            (kal_uint8 *)_prMplvcBufferMgr->arVideoReturnQ,
                            MAX_VIDEO_RETURN_QUEUE_SIZE,
                            sizeof(VIDEO_BUFFERHEADER_TYPE_T));


    // Initialize audio buffer manager
    _MPLVC_BUFFERMGR_GetMgr(VIDEO_PORT_AUDIO_DATA, &prInputQMgr, &prReturnQMgr, &prBitStreamMgr);
    prBitStreamMgr->pau1Buffer = (kal_uint8 *)_MPLVC_AllocMem(prMplvcMgr, MAX_AUDIO_BITSTREAM_SIZE, MED_MEM_CACHE);
    _MPLVC_ASSERT(prBitStreamMgr->pau1Buffer != NULL);

    prBitStreamMgr->u4BitstreamSize = MAX_AUDIO_BITSTREAM_SIZE;

    VideoCoreInitRingBuffer(prInputQMgr,
                            (kal_uint8 *)_prMplvcBufferMgr->arAudioInputQ,
                            MAX_AUDIO_INPUT_QUEUE_SIZE,
                            sizeof(VIDEO_BUFFERHEADER_TYPE_T));

    VideoCoreInitRingBuffer(prReturnQMgr,
                            (kal_uint8 *)_prMplvcBufferMgr->arAudioReturnQ,
                            MAX_AUDIO_RETURN_QUEUE_SIZE,
                            sizeof(VIDEO_BUFFERHEADER_TYPE_T));

    _prMplvcBufferMgr->prMplvcMgr = prMplvcMgr;
    _prMplvcBufferMgr->rMutexID = VideoGetMutex(MUTEX_USER_CLIPPERMPL);
}

/**
 *
 */
__inline static void _MPLVC_BUFFERMGR_Deinit(void)
{
    VideoFreeMutex(MUTEX_USER_CLIPPERMPL, _prMplvcBufferMgr->rMutexID);

    {
        MPLVC_BITSTEAM_MGR *prBitStreamMgr;
        MPLVC_MANAGER_T *prMplvcMgr = _prMplvcBufferMgr->prMplvcMgr;

        _MPLVC_BUFFERMGR_GetMgr(VIDEO_PORT_VIDEO_DATA, NULL, NULL, &prBitStreamMgr);
        if (prBitStreamMgr->pau1Buffer != NULL)
        {
            _MPLVC_FreeMem((void *)prMplvcMgr, prBitStreamMgr->pau1Buffer, MED_MEM_CACHE);
            prBitStreamMgr->pau1Buffer = NULL;
        }

        _MPLVC_BUFFERMGR_GetMgr(VIDEO_PORT_AUDIO_DATA, NULL, NULL, &prBitStreamMgr);
        if (prBitStreamMgr->pau1Buffer != NULL)
        {
            _MPLVC_FreeMem((void *)prMplvcMgr, prBitStreamMgr->pau1Buffer, MED_MEM_CACHE);
            prBitStreamMgr->pau1Buffer = NULL;
        }

        _MPLVC_FreeMem((void *)prMplvcMgr, _prMplvcBufferMgr, MED_MEM_CACHE);
        _prMplvcBufferMgr = NULL;
    }
}

/**
 *
 */
static VIDEO_ERROR_TYPE_T _MPLVC_AUDIO_EmptyThisBuffer(void *const pHandle, VIDEO_BUFFERHEADER_TYPE_T *const prBuffHeader)
{
    MPLVC_TRACE(TRACE_GROUP_5, MPLVC_TRC_AUDIO_EMPTY_BUFFER,
        prBuffHeader->u4InputPort, prBuffHeader->u4OutputPort, (kal_uint32)prBuffHeader->pu1Buffer, prBuffHeader->u4BuffSize, prBuffHeader->eFlags, (kal_uint32)(prBuffHeader->u8TimeStamp >> 32), (kal_uint32)(prBuffHeader->u8TimeStamp & 0xFFFFFFFF));

    if (prBuffHeader->eFlags & VIDEO_BUFFERFLAG_TRIGGER_AUDIO)
    {
        return VIDEO_ERROR_NONE;
    }

    return _rMplvcMgr.pfnEmptyThisBuffer(VIDEO_PORT_AUDIO_DATA, prBuffHeader);
}

/**
 *
 */
static VIDEO_ERROR_TYPE_T _MPLVC_AUDIO_FillThisBuffer(VIDEO_BUFFERHEADER_TYPE_T *const prBuffHeader)
{
    MPLVC_TRACE(TRACE_GROUP_5, MPLVC_TRC_AUDIO_FILL_BUFFER,
            (kal_uint32)prBuffHeader->pu1Buffer, prBuffHeader->u4BuffSize, prBuffHeader->eFlags, (kal_uint32)(prBuffHeader->u8TimeStamp >> 32), (kal_uint32)(prBuffHeader->u8TimeStamp & 0xFFFFFFFF));

    return _rMplvcMgr.pfnFillThisBuffer(VIDEO_PORT_AUDIO_DATA, prBuffHeader);
}


/**
 *
 */
static VIDEO_ERROR_TYPE_T _MPLVC_VIDEO_EmptyThisBuffer(void *const pHandle, VIDEO_BUFFERHEADER_TYPE_T *const prBuffHeader)
{
    MPLVC_TRACE(TRACE_GROUP_5, MPLVC_TRC_VIDEO_EMPTY_BUFFER,
        prBuffHeader->u4InputPort, prBuffHeader->u4OutputPort, (kal_uint32)prBuffHeader->pu1Buffer, prBuffHeader->u4BuffSize, prBuffHeader->eFlags, (kal_uint32)(prBuffHeader->u8TimeStamp >> 32), (kal_uint32)(prBuffHeader->u8TimeStamp & 0xFFFFFFFF));

    return _rMplvcMgr.pfnEmptyThisBuffer(VIDEO_PORT_VIDEO_DATA, prBuffHeader);
}

/**
 *
 */
static VIDEO_ERROR_TYPE_T _MPLVC_VIDEO_FillThisBuffer(VIDEO_BUFFERHEADER_TYPE_T *const prBuffHeader)
{
    MPLVC_TRACE(TRACE_GROUP_5, MPLVC_TRC_VIDEO_FILL_BUFFER,
            (kal_uint32)prBuffHeader->pu1Buffer, prBuffHeader->u4BuffSize, prBuffHeader->eFlags, (kal_uint32)(prBuffHeader->u8TimeStamp >> 32), (kal_uint32)(prBuffHeader->u8TimeStamp & 0xFFFFFFFF));

    return _rMplvcMgr.pfnFillThisBuffer(VIDEO_PORT_VIDEO_DATA, prBuffHeader);
}

/**
 *
 */
static VIDEO_ERROR_TYPE_T _MPLVC_AVI_EmptyThisBuffer(const VIDEO_PORT_TYPE_T ePort, VIDEO_BUFFERHEADER_TYPE_T *const prBuffHeader)
{
#ifdef _AVI_BYPASS_
    VIDEO_ERROR_TYPE_T eVError = VIDEO_ERROR_NONE;
    kal_uint32 u4OriInputPort = prBuffHeader->u4InputPort;

    if (ePort == VIDEO_PORT_VIDEO_DATA)
    {
        prBuffHeader->u4InputPort = 0; // TODO:Workaround
    }
    else if (ePort == VIDEO_PORT_AUDIO_DATA)
    {
        prBuffHeader->u4InputPort = 1; // TODO:Workaround
    }
    eVError =  _rMplvcMgr.prMuxerHandle->pfnEmptyThisBuffer(prBuffHeader);
    prBuffHeader->u4InputPort = u4OriInputPort;

    return eVError;
#endif
    VIDEO_ERROR_TYPE_T eVError = VIDEO_ERROR_NONE;
    eVError = _MPLVC_BUFFERMGR_AddBuffer(ePort, prBuffHeader);

    if (eVError == VIDEO_ERROR_NONE)
    {
        _MPLVC_WakeUp(MSG_MPLVC_EMPTYBUFFER);
    }

    return eVError;
}

/**
 *
 */
static VIDEO_ERROR_TYPE_T _MPLVC_AVI_FillThisBuffer(const VIDEO_PORT_TYPE_T ePort, VIDEO_BUFFERHEADER_TYPE_T *const prBuffHeader)
{
#ifdef _AVI_BYPASS_
    prBuffHeader->u4InputPort = 0; // TODO:Workaround
    return _rMplvcMgr.prSourceHandle->pfnFillThisBuffer(_rMplvcMgr.prSourceCntx, prBuffHeader);
#endif
    return _MPLVC_BUFFERMGR_FreeBuffer(ePort, prBuffHeader);
}


/**
 *
 */
static VIDEO_ERROR_TYPE_T _MPLVC_MP4_EmptyThisBuffer(const VIDEO_PORT_TYPE_T ePort, VIDEO_BUFFERHEADER_TYPE_T *const prBuffHeader)
{
    VIDEO_ERROR_TYPE_T eVError = VIDEO_ERROR_NONE;
    eVError = _MPLVC_BUFFERMGR_AddBuffer(ePort, prBuffHeader);

    if (eVError == VIDEO_ERROR_NONE)
    {
        _MPLVC_WakeUp(MSG_MPLVC_EMPTYBUFFER);
    }

    return eVError;
}

/**
 *
 */
static VIDEO_ERROR_TYPE_T _MPLVC_MP4_FillThisBuffer(const VIDEO_PORT_TYPE_T ePort, VIDEO_BUFFERHEADER_TYPE_T *const prBuffHeader)
{
    return _MPLVC_BUFFERMGR_FreeBuffer(ePort, prBuffHeader);
}



/**
 *
 */
static media_error_t _MPLVC_SOURCE_WaitForStateChange(MPLVC_MANAGER_T *const prMplvcMgr,
        const VIDEO_STATE_TYPE_T eState, const kal_uint32 u4RequestedEvents,
        const kal_uint32 u4MaskOfErrorEvent)
{
    VIDEO_ERROR_TYPE_T eVError = VIDEO_ERROR_NONE;
    kal_uint32 u4EventGroup = 0;
    const PFN_MI_SEND_COMMAND_T pfnSendCommand = prMplvcMgr->prSourceHandle->pfnSendCommand;

    kal_trace(TRACE_GROUP_4, MPLVC_TRC_WAIT_STATE_CHANGE, _ENTER_, eState);

    eVError = pfnSendCommand(prMplvcMgr->prSourceCntx, VIDEO_COMMAND_STATESET, eState);

    if (eVError != VIDEO_ERROR_NONE)
    {
        return MED_E_FAIL;
    }

    kal_retrieve_eg_events(prMplvcMgr->eEvent, u4RequestedEvents,
        KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);

    if ((u4EventGroup & u4MaskOfErrorEvent) != 0)
    {
        if (u4EventGroup & MPLVC_EG_SOURCE_MEM_LACK)
        {
            return MED_E_OUT_OF_MEMORY;
        }
        else
        {
            return MED_E_FAIL;
        }
    }
    MPLVC_TRACE(TRACE_GROUP_4, MPLVC_TRC_WAIT_STATE_CHANGE, _EXIT_, eState);

    return MED_S_OK;
}


/**
 * The function is source callback
 */
static VIDEO_ERROR_TYPE_T _MPLVC_SOURCE_EventHandler(
                            void *const pContext,
                            const VIDEO_EVENT_TYPE_T eEvent,
                            const kal_uint32 u4data1,
                            const kal_uint32 u4data2,
                            void *const pDataPtr)
{
    MPLVC_MANAGER_T *const prMplvcMgr = (MPLVC_MANAGER_T*)pContext;

    kal_trace(TRACE_GROUP_4, MPLVC_TRC_SOURCE_CALLBACK, eEvent, u4data1, u4data2);

    switch(eEvent)
    {
    case VIDEO_EVENT_COMPLETE:
        {
            if(u4data1 == VIDEO_COMMAND_STATESET)
            {
                kal_set_eg_events(prMplvcMgr->eEvent, MPLVC_EG_SOURCE_COMPLETE, KAL_OR);
            }
        }
        break;
    case VIDEO_EVENT_MEM_LACK:
        {
            kal_set_eg_events(prMplvcMgr->eEvent, MPLVC_EG_SOURCE_MEM_LACK, KAL_OR);
        }
        break;
    case VIDEO_EVENT_SEEK_TIME:
        {
            // u4data2: kal_false => error, kal_true: OK
            kal_uint32 u4Events;
            if ((kal_bool)u4data2)
            {
                u4Events = MPLVC_EG_SOURCE_SEEK_TIME_DONE;
            }
            else
            {
                u4Events = MPLVC_EG_SOURCE_ERROR;
            }
            kal_set_eg_events(prMplvcMgr->eEvent, u4Events, KAL_OR);
        }
        break;
    case VIDEO_EVENT_SET_PORT:
        {
            // u4data2: kal_false => error, kal_true: OK
            kal_uint32 u4Events;
            if ((kal_bool)u4data2)
            {
                u4Events = MPLVC_EG_SOURCE_PORT_DONE;
            }
            else
            {
                u4Events = MPLVC_EG_SOURCE_ERROR;
            }
            kal_set_eg_events(prMplvcMgr->eEvent, u4Events, KAL_OR);
        }
        break;
    case VIDEO_EVENT_GET_KEY_FRAME_TIME:
        {
            // data2: kal_false => error, kal_true: OK
            kal_uint32 u4Events;
            if ((kal_bool)u4data2)
            {
                u4Events = MPLVC_EG_SOURCE_KEY_FRAME_DONE;
            }
            else
            {
                u4Events = MPLVC_EG_SOURCE_ERROR;
            }
            kal_set_eg_events(prMplvcMgr->eEvent, u4Events, KAL_OR);
        }
        break;
    case VIDEO_EVENT_PARSER_DELAY_ERROR:
        {
            _MPLVC_StopAndNotify(MPL_CLIPPER_EVENT_SAVE, MED_E_FAIL);
        }
        break;
    case VIDEO_EVENT_ERROR:
    case VIDEO_EVENT_TIMEOUT:
        {
            switch (prMplvcMgr->eState)
            {
            case MPLVC_STATE_RUNNING:
            case MPLVC_STATE_SAVING_FILE:
                {
                    _MPLVC_StopAndNotify(MPL_CLIPPER_EVENT_SAVE, MED_E_FAIL);
                }
                break;
            case MPLVC_STATE_CLOSED:
            case MPLVC_STATE_READY:
            case MPLVC_STATE_STOPPED:
                {
                    kal_set_eg_events(prMplvcMgr->eEvent, MPLVC_EG_SOURCE_ERROR, KAL_OR);
                }
                break;
            default:
                break;
            }
        }
        break;
    default:
        _MPLVC_ASSERT(0);
        break;
    };

    return VIDEO_ERROR_NONE;
}


/**
 * This function is to stop
 */
static media_error_t _MPLVC_SOURCE_SetStream(MPLVC_MANAGER_T *const prMplvcMgr, const SP_PORT_TYPE_T ePort, const kal_uint8 u1Stream)
{
    VIDEO_ERROR_TYPE_T eVError;
    SPIF_STREAM_T rStream;
    VIDEO_COMPONENT_MI_TYPE_T *const prSourceHandle = prMplvcMgr->prSourceHandle;

    if ((prMplvcMgr->u1AudioStreamIdx == MPLVC_INVALID_INDEX && ePort == SOURCE_PROVIDER_PORT_AUDIO))
    {
        return MED_S_OK;
    }
    else if ((prMplvcMgr->u1VideoStreamIdx == MPLVC_INVALID_INDEX && ePort == SOURCE_PROVIDER_PORT_VIDEO))
    {
        return MED_E_VIDEO_ERROR;
    }

    // set seek time
    rStream.eType = ePort;
    rStream.u1Track = u1Stream;
    eVError = prSourceHandle->pfnSetParameter(prMplvcMgr->prSourceCntx, VIDEO_PARAM_SOURCE_PROVIDER_SELECT_STREAM, &rStream);
    if (eVError != VIDEO_ERROR_NONE)
    {
        return MED_E_FAIL;
    }

    return MED_S_OK;
}


/**
 *  Set audio/video seek time
 */
static media_error_t _MPLVC_SOURCE_SetSeekTime(MPLVC_MANAGER_T *const prMplvcMgr, const SP_PORT_TYPE_T ePort, const kal_uint32 u4StartTime, const kal_uint32 u4EndTime)
{
    VIDEO_ERROR_TYPE_T eError;
    kal_uint32 u4EventGroup = 0;
    SPIF_SEEK_TIME_T rSeekTime;
    VIDEO_COMPONENT_MI_TYPE_T *const prSourceHandle = prMplvcMgr->prSourceHandle;

    kal_trace(TRACE_GROUP_4, MPLVC_TRC_SET_SEEK_TIME, ePort, u4StartTime, u4EndTime);
    if ((prMplvcMgr->u1AudioStreamIdx == MPLVC_INVALID_INDEX && ePort == SOURCE_PROVIDER_PORT_AUDIO) ||
        (prMplvcMgr->u1VideoStreamIdx == MPLVC_INVALID_INDEX && ePort == SOURCE_PROVIDER_PORT_VIDEO))
    {
        return MED_S_OK;
    }

    // set seek time
    rSeekTime.eType = ePort;
    rSeekTime.fgOnlyUpdateTime = KAL_FALSE;
    rSeekTime.fgEndTimeSendEof = KAL_TRUE;
    rSeekTime.u8StartTime = u4StartTime;
    rSeekTime.u8EndTime = u4EndTime;

    eError = prSourceHandle->pfnSetParameter(prMplvcMgr->prSourceCntx, VIDEO_PARAM_SOURCE_PROVIDER_SEEK_TIME, &rSeekTime);
    if (eError == VIDEO_ERROR_ASYNC_OPERATION)
    {
        // Wait until the port operation is done
        kal_retrieve_eg_events(prMplvcMgr->eEvent, (MPLVC_EG_SOURCE_SEEK_TIME_DONE | MPLVC_EG_SOURCE_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
        if (u4EventGroup & MPLVC_EG_SOURCE_ERROR)
        {
            return MED_E_FAIL;
        }
    }
    else if (eError != VIDEO_ERROR_NONE)
    {
        return MED_E_FAIL;
    }

    return MED_S_OK;
}


/**
 *
 */
static media_error_t _MPLVC_SOURCE_GetKeyFrameTime(MPLVC_MANAGER_T *const prMplvcMgr, const SP_PORT_TYPE_T ePort, kal_uint64 *const pu8Time, kal_uint64 *pu8KeyTime)
{
    VIDEO_ERROR_TYPE_T eVError;
    SPIF_KEY_FRAME_TIME_T rKeyTime;
    kal_uint32 u4EventGroup = 0;
    VIDEO_COMPONENT_MI_TYPE_T *const prSourceHandle = prMplvcMgr->prSourceHandle;

    // set seek time
    rKeyTime.u8StartTime = *pu8Time;
    rKeyTime.ePort = ePort;
    rKeyTime.eDirect = SOURCE_PROVIDER_SEARCH_BACKWARD;

    eVError = prSourceHandle->pfnGetParameter(prMplvcMgr->prSourceCntx, VIDEO_PARAM_SOURCE_PROVIDER_KEY_FRAME_TIME, &rKeyTime);
    if (eVError == VIDEO_ERROR_ASYNC_OPERATION)
    {
        // Wait until the port operation is done
        kal_retrieve_eg_events(prMplvcMgr->eEvent, (MPLVC_EG_SOURCE_KEY_FRAME_DONE | MPLVC_EG_SOURCE_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
        if (u4EventGroup & MPLVC_EG_SOURCE_ERROR)
        {
            return MED_E_FAIL;
        }
    }
    else if (eVError != VIDEO_ERROR_NONE)
    {
        return MED_E_FAIL;
    }

    *pu8KeyTime = rKeyTime.u8KeyFrameTime;

    kal_trace(TRACE_GROUP_4, MPLVC_TRC_GET_KEYFRAME_TIME, ePort,
        (kal_uint32)(*pu8Time >> 32), (kal_uint32)(*pu8Time & 0xFFFFFFFF),
        (kal_uint32)(*pu8KeyTime >> 32), (kal_uint32)(*pu8KeyTime & 0xFFFFFFFF));

    return MED_S_OK;
}


/**
 *  Set source component port state
 */
static media_error_t _MPLVC_SOURCE_SetPort(MPLVC_MANAGER_T *const prMplvcMgr, const SP_PORT_TYPE_T ePort, const kal_bool fgEnable)
{
    SPIF_PORT_T rSourcePort;
    VIDEO_ERROR_TYPE_T eVError;
    kal_uint32 u4EventGroup = 0;
    VIDEO_COMPONENT_MI_TYPE_T *const prSourceHandle = prMplvcMgr->prSourceHandle;

    if ((prMplvcMgr->u1AudioStreamIdx == MPLVC_INVALID_INDEX && ePort == SOURCE_PROVIDER_PORT_AUDIO) ||
        (prMplvcMgr->u1VideoStreamIdx == MPLVC_INVALID_INDEX && ePort == SOURCE_PROVIDER_PORT_VIDEO))
    {
        return MED_S_OK;
    }

    rSourcePort.eType = ePort;
    rSourcePort.fgEnable= fgEnable;
    eVError = prSourceHandle->pfnSetParameter(prMplvcMgr->prSourceCntx, VIDEO_PARAM_SOURCE_PROVIDER_SELECT_PORT, &rSourcePort);
    if (eVError == VIDEO_ERROR_UNUSED_OPERATION)
    {
        return MED_S_OK;
    }
    else if (eVError == VIDEO_ERROR_ASYNC_OPERATION)
    {
        // Wait until the port operation is done
        kal_retrieve_eg_events(prMplvcMgr->eEvent, (MPLVC_EG_SOURCE_PORT_DONE | MPLVC_EG_SOURCE_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
        if (u4EventGroup & MPLVC_EG_SOURCE_ERROR)
        {
            return MED_E_FAIL;
        }
    }
    else if (eVError != VIDEO_ERROR_NONE)
    {
        return MED_E_FAIL;
    }

    return MED_S_OK;
}


/**
 * The function is to initialize video component
 */
__inline static media_error_t _MPLVC_SOURCE_InitParam(MPLVC_MANAGER_T *const prMplvcMgr)
{
    SPIF_STREAM_INFO_T rStreamInfo;
    SPIF_VIDEO_STREAM_INFO_T *prSPVideoInfo;
    SPIF_AUDIO_STREAM_INFO_T *prSPAudioInfo;
    SP_CAPABILITY_T rCap;
    media_error_t eMError;
    kal_bool fgSupported = KAL_FALSE;
    VIDEO_COMPONENT_MI_TYPE_T *const prSourceHandle = prMplvcMgr->prSourceHandle;

    // query whether recorded file is supported
    prSourceHandle->pfnGetParameter(prMplvcMgr->prSourceCntx, VIDEO_PARAM_SOURCE_PROVIDER_MTK_FILE, &fgSupported);
    if (fgSupported == KAL_FALSE)
    {
        kal_trace(TRACE_GROUP_4, MPLVC_TRC_NO_MTKBOX);
        return MED_E_UNSUPPORTED_FORMAT;
    }

    // Set hook function
    prSourceHandle->pfnSetParameter(prMplvcMgr->prSourceCntx, VIDEO_PARAM_SOURCE_PROVIDER_EMPTY_FUNC, (void*)&_rMPLVC_EmptyBufferAPI);

    // video: query stream info
    prSourceHandle->pfnGetParameter(prMplvcMgr->prSourceCntx, VIDEO_PARAM_SOURCE_PROVIDER_VID_STREAM_INFO, &rStreamInfo);
    if (rStreamInfo.fgSupport == KAL_TRUE)
    {
        prSPVideoInfo = (SPIF_VIDEO_STREAM_INFO_T*)rStreamInfo.pvStreamInfo;
        prMplvcMgr->u1VideoStreamIdx = prSPVideoInfo->u4StreamIndex;
        prMplvcMgr->rSPVideoStream = *prSPVideoInfo;
    }
    else
    {
        prMplvcMgr->u1VideoStreamIdx = MPLVC_INVALID_INDEX;
    }

    // audio: query stream info
    prSourceHandle->pfnGetParameter(prMplvcMgr->prSourceCntx, VIDEO_PARAM_SOURCE_PROVIDER_AUD_STREAM_INFO, &rStreamInfo);
    if (rStreamInfo.fgSupport == KAL_TRUE)
    {
        prSPAudioInfo = (SPIF_AUDIO_STREAM_INFO_T*)rStreamInfo.pvStreamInfo;
        prMplvcMgr->u1AudioStreamIdx = prSPAudioInfo->u4StreamIndex;
        prMplvcMgr->rSPAudioStream = *prSPAudioInfo;
        prMplvcMgr->fgRecordAudio = KAL_TRUE;

    }
    else
    {
        prMplvcMgr->u1AudioStreamIdx = MPLVC_INVALID_INDEX;
        prMplvcMgr->fgRecordAudio = KAL_FALSE;
    }

    // Calculate clipped file duration
    if (prMplvcMgr->rOpenInfo.u4EndTime == 0xFFFFFFFF)
    {
        prMplvcMgr->u4ClipDuration = prMplvcMgr->rSPVideoStream.u8Duration - prMplvcMgr->rOpenInfo.u4StartTime;
    }
    else
    {
        prMplvcMgr->u4ClipDuration = prMplvcMgr->rOpenInfo.u4EndTime - prMplvcMgr->rOpenInfo.u4StartTime;
    }

    kal_trace(TRACE_GROUP_4, MPLVC_TRC_CLIP_DURATION, prMplvcMgr->u4ClipDuration);

    // Check whether file is seekable?
    prSourceHandle->pfnGetParameter(prMplvcMgr->prSourceCntx, VIDEO_PARAM_SOURCE_PROVIDER_CAPABILITY, &rCap);
    prMplvcMgr->fgSeekable = (rCap & SOURCE_PROVIDER_SEEK)? KAL_TRUE : KAL_FALSE;

    if (prMplvcMgr->fgSeekable == KAL_FALSE)
    {
        return MED_E_UNSUPPORTED_FORMAT;
    }

    // check is a valid file (with aud / vid stream)
    if (prMplvcMgr->u1AudioStreamIdx == MPLVC_INVALID_INDEX && prMplvcMgr->u1VideoStreamIdx == MPLVC_INVALID_INDEX)
    {
        return MED_E_UNSUPPORTED_FORMAT;
    }

    //
#if defined(__VE_TRANSFORMATION_INFO__)
    prSourceHandle->pfnGetParameter(prMplvcMgr->prSourceCntx, VIDEO_PARAM_SOURCE_PROVIDER_TRANSFORMATION_INFO, &prMplvcMgr->rTransformInfo);
#endif

    // Wait for complete notification on event handler
    MEDIA_ERR_RTN(_MPLVC_SOURCE_WaitForStateChange(prMplvcMgr,
        VIDEO_STATE_IDLE, MPLVC_EG_SOURCE_ALL, MPLVC_EG_SOURCE_ERR));

    // select video/audio stream
    MEDIA_ERR_RTN(_MPLVC_SOURCE_SetStream(prMplvcMgr, SOURCE_PROVIDER_PORT_VIDEO, prMplvcMgr->u1VideoStreamIdx));
    MEDIA_ERR_RTN(_MPLVC_SOURCE_SetStream(prMplvcMgr, SOURCE_PROVIDER_PORT_AUDIO, prMplvcMgr->u1AudioStreamIdx));

    return MED_S_OK;
}


/**
 * The function is to initialize source component
 */
__inline static media_error_t _MPLVC_SOURCE_Init(MPLVC_MANAGER_T *const prMplvcMgr, mpl_clipper_open_t *const open_struct)
{
    SPIF_MEDIA_INFO_T rSourceMediaInfo;
    VIDEO_COMPONENT_MI_TYPE_T *prSourceHandle;
    VIDEO_ERROR_TYPE_T eVError;
    media_error_t eMError;

    rSourceMediaInfo.pvHandle = prMplvcMgr;
    rSourceMediaInfo.eFileType = prMplvcMgr->eSourceContainerType;
    rSourceMediaInfo.eTrack = SOURCE_PROVIDER_TRACK_AUDIO;
    rSourceMediaInfo.eTrack |= SOURCE_PROVIDER_TRACK_VIDEO;
    rSourceMediaInfo.eOpenType = MED_MODE_EDITOR_FILE; // TODO: work fine?
    rSourceMediaInfo.pu1Data = (kal_uint8*)open_struct->pau2SrcPath;
    rSourceMediaInfo.u4Size= kal_wstrlen(open_struct->pau2SrcPath);
    rSourceMediaInfo.prAPI = (MPL_SESSION_MEM_API_T *)&_rMPLVC_MemAPI;

    eVError = GetSourceProviderHandle(&rSourceMediaInfo, &prMplvcMgr->prSourceCntx, &prMplvcMgr->prSourceHandle);
    if (eVError != VIDEO_ERROR_NONE)
    {
        // If source componet get handle failed, it should release resource by itprMplvcMgr.
        if (eVError == VIDEO_ERROR_NO_MEMORY)
        {
            return MED_E_OUT_OF_MEMORY;
        }
        else
        {
            return MED_E_FAIL;
        }
    }

    // Source component opened
    prSourceHandle = prMplvcMgr->prSourceHandle;
    if (prSourceHandle == NULL)
    {
        return MED_E_FAIL;
    }

    // Set callback function
    prMplvcMgr->rSourceCallback.pfnMIEventHandler = _MPLVC_SOURCE_EventHandler;
    prSourceHandle->pfnSetCallbacks(prMplvcMgr->prSourceCntx, &prMplvcMgr->rSourceCallback);

    // Wait for complete notification on event handler
    eMError = _MPLVC_SOURCE_WaitForStateChange(prMplvcMgr,
                VIDEO_STATE_INIT, MPLVC_EG_SOURCE_ALL, MPLVC_EG_SOURCE_ERR);

    if (eMError != MED_S_OK)
    {
        ReleaseSourceProviderHandle(prMplvcMgr->prSourceCntx);
        prMplvcMgr->prSourceHandle = NULL;
        prMplvcMgr->prSourceCntx = NULL;
        return eMError;
    }

    return MED_S_OK;
}


/**
 * This function is to close source component
 */
static media_error_t _MPLVC_SOURCE_Close(MPLVC_MANAGER_T *const prMplvcMgr)
{
    media_error_t eMError;

    switch (prMplvcMgr->eSourceState)
    {
    case MPLVC_COMP_STATE_CLOSED:
        // Do nothing.
        break;
    case MPLVC_COMP_STATE_INITIALIZED:
    case MPLVC_COMP_STATE_IDLE:
    case MPLVC_COMP_STATE_STOPPED:
        {
            // Wait for complete notification on event handler
            MEDIA_ERR_RTN(_MPLVC_SOURCE_WaitForStateChange(prMplvcMgr,
                    VIDEO_STATE_CLOSE, MPLVC_EG_SOURCE_ALL, MPLVC_EG_SOURCE_ERR));

            ReleaseSourceProviderHandle(prMplvcMgr->prSourceCntx);
            prMplvcMgr->prSourceHandle = NULL;
            prMplvcMgr->prSourceCntx = NULL;

            prMplvcMgr->eSourceState = MPLVC_COMP_STATE_CLOSED;
        }
        break;
    default:
        return MED_E_WRONG_STATE;
        //break;
    }

    return MED_S_OK;
}


/**
 *
 */
__inline static media_error_t _MPLVC_SOURCE_Open(MPLVC_MANAGER_T *const prMplvcMgr, mpl_clipper_open_t *const prOpenStruct)
{
    switch (prMplvcMgr->eSourceState)
    {
    case MPLVC_COMP_STATE_CLOSED:
        {
            media_error_t eMError = MED_S_OK;

            // Open source component first
            MEDIA_ERRLOG_RTN(_MPLVC_SOURCE_Init(prMplvcMgr, prOpenStruct))

            prMplvcMgr->eSourceState = MPLVC_COMP_STATE_INITIALIZED;

            eMError = _MPLVC_SOURCE_InitParam(prMplvcMgr);
            if (eMError != MED_S_OK)
            {
                // Open video path failed, then Close source
                _MPLVC_SOURCE_Close(prMplvcMgr);
                return eMError;
            }

            prMplvcMgr->eSourceState = MPLVC_COMP_STATE_IDLE;
        }
        break;
    default:
        return MED_E_WRONG_STATE;
        //break;
    }

    return MED_S_OK;
}


/**
 *
 */
__inline static media_error_t _MPLVC_SOURCE_Start(MPLVC_MANAGER_T *const prMplvcMgr)
{
    media_error_t eMError = MED_S_OK;

    // Source Control
    switch (prMplvcMgr->eSourceState)
    {
    case MPLVC_COMP_STATE_IDLE:
        {
            // Wait for complete notification on event handler
            MEDIA_ERR_RTN(_MPLVC_SOURCE_WaitForStateChange(prMplvcMgr,
                        VIDEO_STATE_RUN, MPLVC_EG_SOURCE_ALL, MPLVC_EG_SOURCE_ERR));

            prMplvcMgr->eSourceState = MPLVC_COMP_STATE_RUNNING;
        }
        break;
    default:
        return MED_E_WRONG_STATE;
        //break;
    }
    return MED_S_OK;
}


/**
 *
 */
__inline static media_error_t _MPLVC_SOURCE_Stop(MPLVC_MANAGER_T *const prMplvcMgr)
{
    media_error_t eMError;

    switch (prMplvcMgr->eSourceState)
    {
    case MPLVC_COMP_STATE_CLOSED:
    case MPLVC_COMP_STATE_IDLE:
    case MPLVC_COMP_STATE_STOPPED:
        break;
    case MPLVC_COMP_STATE_RUNNING:
        {
            // disable audio port
            MEDIA_ERR_RTN(_MPLVC_SOURCE_SetPort(prMplvcMgr, SOURCE_PROVIDER_PORT_AUDIO, KAL_FALSE));

            // disable video port
            MEDIA_ERR_RTN(_MPLVC_SOURCE_SetPort(prMplvcMgr, SOURCE_PROVIDER_PORT_VIDEO, KAL_FALSE));

            // Wait for complete notification on event handler
            MEDIA_ERR_RTN(_MPLVC_SOURCE_WaitForStateChange(prMplvcMgr,
                    VIDEO_STATE_STOP, MPLVC_EG_SOURCE_ALL, MPLVC_EG_SOURCE_ERR));

            prMplvcMgr->eSourceState = MPLVC_COMP_STATE_STOPPED;
        }
        break;
    default:
        return MED_E_WRONG_STATE;
        //break;
    }

    return MED_S_OK;
}


/**
 *
 */
static void _MPLVC_MUXER_WaitForStateChange(MPLVC_MANAGER_T *const prMplvcMgr,
        const VIDEO_STATE_TYPE_T eState, const kal_uint32 u4RequestedEvents,
        const kal_uint32 u4MaskOfErrorEvent)
{
    VIDEO_ERROR_TYPE_T eVError = VIDEO_ERROR_NONE;
    kal_uint32 u4EventGroup = 0;
    const PFN_SEND_COMMAND_T pfnSendCommand = prMplvcMgr->prMuxerHandle->pfnSendCommand;

    kal_trace(TRACE_GROUP_4, MPLVC_TRC_WAIT_STATE_CHANGE, _ENTER_, eState);

    eVError = pfnSendCommand(VIDEO_COMMAND_STATESET, eState);
    if (eVError != VIDEO_ERROR_NONE)
    {
        _MPLVC_ASSERT(0);
    }

    kal_retrieve_eg_events(prMplvcMgr->eEvent, u4RequestedEvents,
        KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);

    MPLVC_TRACE(TRACE_GROUP_4, MPLVC_TRC_WAIT_STATE_CHANGE, _EXIT_, eState);
}


/**
 *
 */
__inline static media_error_t _MPLVC_MUXER_SetupMemory(MPLVC_MANAGER_T *const prMplvcMgr)
{
    media_error_t eMError = MED_S_OK ;
    const MUXER_CONTAINER_TYPE_T eMuxerContainerType = prMplvcMgr->eMuxerContainerType;
    const kal_uint32 u4MuxerMemSize = GetMuxerMemorySize(eMuxerContainerType, MUXER_SCENARIO_RECORD);
    void *const pvMem = _MPLVC_AllocMem(prMplvcMgr, u4MuxerMemSize, MED_MEM_CACHE);

    if (pvMem == NULL)
    {
        return MED_E_OUT_OF_MEMORY;
    }

    prMplvcMgr->pu1MuxerMemAddr = pvMem;
    prMplvcMgr->u4MuxerMemSize = u4MuxerMemSize;
    prMplvcMgr->prExtMemInfo = VideoInitExtBuffer((kal_uint32)prMplvcMgr->pu1MuxerMemAddr, prMplvcMgr->u4MuxerMemSize, VIDEO_SCENARIO_MERGE_FILE);

    return eMError;
}


/**
 *
 */
__inline static void _MPLVC_MUXER_ReleaseMemory(MPLVC_MANAGER_T *const prMplvcMgr)
{
    VideoDeInitExtBuffer(prMplvcMgr->prExtMemInfo);

    if (prMplvcMgr->pu1MuxerMemAddr)
    {
        _MPLVC_FreeMem(prMplvcMgr, prMplvcMgr->pu1MuxerMemAddr, MED_MEM_CACHE);
        prMplvcMgr->pu1MuxerMemAddr = NULL;
        prMplvcMgr->u4MuxerMemSize = 0;
    }
}


/**
 *
 */
__inline static void _MPLVC_MUXER_DeleteTemporaryFiles(MPLVC_MANAGER_T *const prMplvcMgr)
{
    MuxerDeleteTempFile(prMplvcMgr->eMuxerContainerType, prMplvcMgr->rOpenInfo.pau2WorkingPath);
}


/**
 *
 */
static VIDEO_ERROR_TYPE_T _MPLVC_MUXER_EventHandler(const VIDEO_EVENT_TYPE_T eEvent,
        const kal_uint32 u4Data1, const kal_uint32 u4Data2, void *const pData)
{
    MPLVC_MANAGER_T *const prMplvcMgr = (MPLVC_MANAGER_T *)&_rMplvcMgr;

    kal_trace(TRACE_GROUP_4, MPLVC_TRC_MUXER_EVENT_HANDLER, prMplvcMgr->eState, eEvent, u4Data1, u4Data2);

    switch (eEvent)
    {
    case VIDEO_EVENT_COMPLETE:
        {
            kal_set_eg_events(prMplvcMgr->eEvent, MPLVC_EG_MUXER_COMPLETE, KAL_OR);
        }
        break;
    case VIDEO_EVENT_ERROR:
        {
            switch (prMplvcMgr->eState)
            {
            case MPLVC_STATE_RUNNING:
            case MPLVC_STATE_SAVING_FILE:
                {
                    media_error_t eMError = MED_E_ERROR;
                    if (prMplvcMgr->fgDiskFull == KAL_TRUE)
                    {
                        eMError = MED_E_DISC_FULL;
                    }

                    _MPLVC_StopAndNotify(MPL_CLIPPER_EVENT_SAVE, eMError);
                }
                break;
            case MPLVC_STATE_CLOSED:
            case MPLVC_STATE_READY:
            case MPLVC_STATE_STOPPED:
                {
                    kal_set_eg_events(prMplvcMgr->eEvent, MPLVC_EG_MUXER_ERROR, KAL_OR);
                }
                break;
            default:
                break;
            }
        }
        break;
    case VIDEO_EVENT_NO_DISK:
        {
            _MPLVC_ASSERT(0);   // TODO:
        }
        break;
    case VIDEO_EVENT_DISK_IS_FULL:
        {
            //media_error_t eMError = MED_E_DISC_FULL;
            prMplvcMgr->fgDiskFull = KAL_TRUE;
            _MPLVC_DoFileMerge((void *)prMplvcMgr, NULL, NULL);
            //_MPLVC_MakeAsyncCall(MOD_MED, _MPLVC_DoNotify, prMplvcMgr, (void*)MPL_CLIPPER_EVENT_SAVE, (void*)eMError);
        }
        break;
    case VIDEO_EVENT_VIDEO_EOS:
    case VIDEO_EVENT_AUDIO_EOS:
        {
            kal_uint32 u4EventGroup;
            kal_uint32 u4RequestedEvents;
            kal_uint32 u4Events;
            if (eEvent == VIDEO_EVENT_VIDEO_EOS)
            {
                u4Events = MPLVC_EG_VIDEO_EOS;
            }
            else
            {
                u4Events = MPLVC_EG_AUDIO_EOS;
            }
            kal_set_eg_events(prMplvcMgr->eEvent, u4Events, KAL_OR);


            if (prMplvcMgr->fgRecordAudio == KAL_FALSE)
            {
                // Only wait video EOS
                u4RequestedEvents = MPLVC_EG_VIDEO_EOS;
            }
            else
            {
                // Wait video/audio EOS
                u4RequestedEvents = (MPLVC_EG_VIDEO_EOS | MPLVC_EG_AUDIO_EOS);
            }

            kal_retrieve_eg_events(prMplvcMgr->eEvent, u4RequestedEvents, KAL_AND_CONSUME, &u4EventGroup, KAL_NO_SUSPEND);
            if (u4EventGroup & u4RequestedEvents)
            {
                _MPLVC_DoFileMerge((void *)prMplvcMgr, NULL, NULL);
            }
        }
        break;
    case VIDEO_EVENT_MUXER_FILE_CREATED:
    case VIDEO_EVENT_NO_VIDEO_FRAME_ENCODED:
        {
            media_error_t eMError = MED_S_OK;
            if (prMplvcMgr->fgDiskFull == KAL_TRUE)
            {
                eMError = MED_E_DISC_FULL;
            }

            _MPLVC_MakeAsyncCall(MOD_MED, _MPLVC_MUXER_CloseFileMergeAsync, prMplvcMgr, (void*)MPL_CLIPPER_EVENT_SAVE, (void*)eMError);
        }
        break;
    default:
        _MPLVC_ASSERT(0);
        break;
    }

    return VIDEO_ERROR_NONE;
}


/**
 *
 */
const static VIDEO_CALLBACK_TYPE_T _MPLVC_MUXER_CallbackStruct =
{
    _MPLVC_MUXER_EventHandler
};


/**
 * Set Audio Properties
 */
__inline static void _MPLVC_MUXER_SetAudioProperties(MPLVC_MANAGER_T *const prMplvcMgr)
{
    MUXER_AUDIO_CONFIG_T rAudioProperties;

    ZERO_MEMORY((void*)&rAudioProperties, sizeof(rAudioProperties));

    if (prMplvcMgr->fgRecordAudio == KAL_TRUE)
    {
        SPIF_AUDIO_STREAM_INFO_T *prSPAudioStream = &prMplvcMgr->rSPAudioStream;

        // Audio Codec
        switch(prSPAudioStream->eCodecType)
        {
        case MEDIA_CODEC_AUD_AMR:
            {
                rAudioProperties.eAudioFormat = MEDIA_FORMAT_AMR;
            }
            break;
        case MEDIA_CODEC_AUD_PCM:
            {
                rAudioProperties.eAudioFormat = MEDIA_FORMAT_PCM_8K; // TODO:FIXME
            }
            break;
        default:
            _MPLVC_ASSERT(0);
            break;
        }

        rAudioProperties.fgRecordAudio = KAL_TRUE;
        rAudioProperties.u4AudioFrameSize = prSPAudioStream->u2BitsPerSample / 8; // in byte
        rAudioProperties.u4AudioFrameDuration = prSPAudioStream->u4FrameDuration / 1000; // in millisecond
        rAudioProperties.u4AudioBitRate = prSPAudioStream->u4SampleRate * prSPAudioStream->u2BitsPerSample;
        rAudioProperties.u4AudioSampleRate = prSPAudioStream->u4SampleRate;
        rAudioProperties.u4AudioChannelNum = prSPAudioStream->u2Channels;
        rAudioProperties.u4AudioBitPerSample = prSPAudioStream->u2BitsPerSample;
    }
    else
    {
        // Do nothing
    }

    _MPLVC_SetParam2Comp(prMplvcMgr->prMuxerHandle,
        MUXER_SET_AUDIO_CONFIG, (void*)&rAudioProperties);
}


/**
 * Set Video Properties
 */
__inline static void _MPLVC_MUXER_SetVideoProperties(MPLVC_MANAGER_T *const prMplvcMgr)
{
    MUXER_VIDEO_CONFIG_T rVideoProperties;
    SPIF_VIDEO_STREAM_INFO_T *const prSPVideoStream = &prMplvcMgr->rSPVideoStream;

    ZERO_MEMORY((void*)&rVideoProperties, sizeof(rVideoProperties));

    // Video Codec
    switch(prSPVideoStream->eCodecType)
    {
    case MEDIA_CODEC_VID_MPEG4:
        {
            rVideoProperties.eEncoderType = VIDEO_ENCODER_MPEG4;
        }
        break;
    case MEDIA_CODEC_VID_H263:
        {
            rVideoProperties.eEncoderType = VIDEO_ENCODER_H263;
        }
        break;
    case MEDIA_CODEC_VID_H264:
        {
            rVideoProperties.eEncoderType = VIDEO_ENCODER_H264;
        }
        break;
    case MEDIA_CODEC_VID_MJPG:
        {
            rVideoProperties.eEncoderType = VIDEO_ENCODER_MJPEG;
        }
        break;
    default:
        _MPLVC_ASSERT(0);
        break;
    }

#if defined(__VE_TRANSFORMATION_INFO__)
    switch(prMplvcMgr->rTransformInfo.u2Rotation)
    {
    case 90:
        {
            rVideoProperties.eRotateAngle = MUXER_ROTATE_90_CW;
        }
        break;
    case 180:
        {
            rVideoProperties.eRotateAngle = MUXER_ROTATE_180_CW;
        }
        break;
    case 270:
        {
            rVideoProperties.eRotateAngle = MUXER_ROTATE_270_CW;
        }
        break;
    default:
        break;
    }

    rVideoProperties.fgHorizontallyMirror = (kal_bool)prMplvcMgr->rTransformInfo.u1HorizontalMirror;
#endif

    rVideoProperties.u4FrameWidth = prSPVideoStream->u4Width;
    rVideoProperties.u4FrameHeight = prSPVideoStream->u4Height;
    rVideoProperties.u4VideoFrameRate = prSPVideoStream->u4Fps;
    rVideoProperties.u4VideoBitRate = prSPVideoStream->u4AvgBitrate;

    _MPLVC_SetParam2Comp(prMplvcMgr->prMuxerHandle,
        MUXER_SET_VIDEO_CONFIG, (void*)&rVideoProperties);
}


/**
 * Set Container Properties
 */
static void _MPLVC_MUXER_SetContainerProperties(MPLVC_MANAGER_T *const prMplvcMgr)
{
    _MPLVC_SetParam2Comp(prMplvcMgr->prMuxerHandle,
        MUXER_SET_SCENARIO, (void*)&prMplvcMgr->eMuxerScenario);

    _MPLVC_SetParam2Comp(prMplvcMgr->prMuxerHandle,
        MUXER_SET_CONTAINER_TYPE, (void*)&prMplvcMgr->eMuxerContainerType);

    _MPLVC_SetParam2Comp(prMplvcMgr->prMuxerHandle,
        MUXER_SET_WORKING_PATH, (void*)prMplvcMgr->rOpenInfo.pau2WorkingPath);

    _MPLVC_SetParam2Comp(prMplvcMgr->prMuxerHandle,
        MUXER_SET_FILE_NAME_PATH, (void*)prMplvcMgr->rOpenInfo.pau2DstPath);

    {
        kal_uint32 u4WriteThreshold = MPLVC_ONE_VIDEO_BUFFER_SIZE;
        _MPLVC_SetParam2Comp(prMplvcMgr->prMuxerHandle,
            MUXER_SET_VIDEO_WRITE_THRESHOLD, (void*)&u4WriteThreshold);
    }
}


/**
 *
 */
__inline static void _MPLVC_MUXER_ReleaseHandle(MPLVC_MANAGER_T *const prMplvcMgr)
{
    if (prMplvcMgr->prMuxerHandle != NULL)
    {
        VIDEO_ERROR_TYPE_T eVideoError = VIDEO_ERROR_NONE;
        eVideoError = ReleaseMuxerHandle(prMplvcMgr->prMuxerHandle);
        if (eVideoError != VIDEO_ERROR_NONE)
        {
            _MPLVC_ASSERT(0);
        }
        prMplvcMgr->prMuxerHandle = NULL;
    }
}

/**
 *
 */
static media_error_t _MPLVC_MUXER_Open(MPLVC_MANAGER_T *const prMplvcMgr, const MUXER_SCENARIO_T eMuxerScenario)
{
    PFN_SET_CALLBACK_T pfnSetCallbacks;
    media_error_t eMError = MED_S_OK;
    VIDEO_ERROR_TYPE_T eVError = VIDEO_ERROR_NONE;

    if (prMplvcMgr->eMuxerState != MPLVC_COMP_STATE_CLOSED)
    {
        return MED_E_WRONG_STATE;
    }

    prMplvcMgr->eMuxerScenario = eMuxerScenario;

    MEDIA_ERRLOG_RTN(_MPLVC_MUXER_SetupMemory(prMplvcMgr));

    prMplvcMgr->prMuxerHandle = GetMuxerHandle(prMplvcMgr->prExtMemInfo);
    if (prMplvcMgr->prMuxerHandle == NULL)
    {
        _MPLVC_ASSERT(0);
    }

    pfnSetCallbacks = prMplvcMgr->prMuxerHandle->pfnSetCallbacks;
    eVError = pfnSetCallbacks((VIDEO_CALLBACK_TYPE_T*)&_MPLVC_MUXER_CallbackStruct);
    if (eVError != VIDEO_ERROR_NONE)
    {
        _MPLVC_ASSERT(0);
    }

    _MPLVC_MUXER_WaitForStateChange(prMplvcMgr,
        VIDEO_STATE_INIT, MPLVC_EG_MUXER_COMPLETE, MPLVC_EG_MUXER_ERR);

    _MPLVC_MUXER_WaitForStateChange(prMplvcMgr,
        VIDEO_STATE_IDLE, MPLVC_EG_MUXER_COMPLETE, MPLVC_EG_MUXER_ERR);

    prMplvcMgr->eMuxerState = MPLVC_COMP_STATE_IDLE;

    return MED_S_OK;
}


/**
 *
 */
static void _MPLVC_MUXER_Start(MPLVC_MANAGER_T *const prMplvcMgr)
{
    switch (prMplvcMgr->eMuxerState)
    {
    case MPLVC_COMP_STATE_IDLE:
        {
            _MPLVC_MUXER_WaitForStateChange(prMplvcMgr,
                VIDEO_STATE_RUN, MPLVC_EG_MUXER_COMPLETE, MPLVC_EG_MUXER_ERR);
            prMplvcMgr->eMuxerState = MPLVC_COMP_STATE_RUNNING;
        }
        break;
    default:
        _MPLVC_ASSERT(0);
        break;
    }
}


/**
 *
 */
static media_error_t _MPLVC_MUXER_Stop(MPLVC_MANAGER_T *const prMplvcMgr)
{

    switch (prMplvcMgr->eMuxerState)
    {
    case MPLVC_COMP_STATE_RUNNING:
        {
            _MPLVC_MUXER_WaitForStateChange(prMplvcMgr,
                        VIDEO_STATE_STOP, MPLVC_EG_MUXER_COMPLETE, MPLVC_EG_MUXER_ERR);
            prMplvcMgr->eMuxerState = MPLVC_COMP_STATE_STOPPED;
        }
        break;

    case MPLVC_COMP_STATE_STOPPED:
        break;

    default:
        return MED_E_WRONG_STATE;
        //break;
    }

    return MED_S_OK;
}


/**
 *
 */
__inline static media_error_t _MPLVC_MUXER_Close(MPLVC_MANAGER_T *const prMplvcMgr)
{
    switch (prMplvcMgr->eMuxerState)
    {
    case MPLVC_COMP_STATE_CLOSED:
        // Do nothing.
        break;
    case MPLVC_COMP_STATE_INITIALIZED:
        // TODO:
        break;
    case MPLVC_COMP_STATE_IDLE:
    case MPLVC_COMP_STATE_STOPPED:
        {
            _MPLVC_MUXER_WaitForStateChange(prMplvcMgr,
                    VIDEO_STATE_CLOSE, MPLVC_EG_MUXER_COMPLETE, MPLVC_EG_MUXER_ERR);
            _MPLVC_MUXER_ReleaseHandle(prMplvcMgr);
            _MPLVC_MUXER_ReleaseMemory(prMplvcMgr);
            prMplvcMgr->eMuxerState = MPLVC_COMP_STATE_CLOSED;
        }
        break;
    default:
        return MED_E_WRONG_STATE;
        //break;
    }

    return MED_S_OK;
}


/**
 *
 */
__inline static media_error_t _MPLVC_MUXER_CreateFinalFile(MPLVC_MANAGER_T *const prMplvcMgr)
{
    switch (prMplvcMgr->eState)
    {
    case MPLVC_STATE_CLOSED:
        {
            _MPLVC_MUXER_Open(prMplvcMgr, MUXER_SCENARIO_CREATE_FILE);
            _MPLVC_MUXER_SetContainerProperties(prMplvcMgr);
            _MPLVC_MUXER_Start(prMplvcMgr);
            prMplvcMgr->eState = MPLVC_STATE_SAVING_FILE;
        }
        break;
    default:
        _MPLVC_ASSERT(0);
        break;
    }

    return MED_S_OK;
}


/**
 *
 */
static void _MPLVC_MUXER_CloseFileMergeAsync(void *const pParam1, void *const pParam2, void *const pParam3)
{
    MPLVC_MANAGER_T *const prMplvcMgr = (MPLVC_MANAGER_T *)pParam1;

    _MPLVC_MUXER_Stop(prMplvcMgr);
    prMplvcMgr->eState = MPLVC_STATE_STOPPED;

    // If cancel is trigged, but file have been created, delete it
    if (prMplvcMgr->fgCanceled == KAL_TRUE)
    {
        // TODO:
        FS_Delete(prMplvcMgr->rOpenInfo.pau2DstPath);
    }
    else
    {
        _MPLVC_MakeAsyncCall(MOD_MED, _MPLVC_DoNotify, prMplvcMgr, pParam2, pParam3);
    }
}


/**
 * This function is to allocate player memory
 */
static void* _MPLVC_AllocMem(void *const prClient, const kal_uint32 u4Size, const med_mem_type_enum eType)
{
    MPLVC_MANAGER_T * const prMplvcMgr = (MPLVC_MANAGER_T *)prClient;
    void * const ptr = _MPLVC_ALLOC_EXT_MEM(&prMplvcMgr->rMplClient, u4Size, eType);

    return ptr;
}


/**
 * This function is to free player memory
 */
static void _MPLVC_FreeMem(void *prClient, void *p, med_mem_type_enum eType)
{
    MPLVC_MANAGER_T * const prMplvcMgr = (MPLVC_MANAGER_T *)prClient;

    _MPLVC_FREE_EXT_MEM(&prMplvcMgr->rMplClient, &p, eType);
}

__inline static void _MPLVC_WaitForTaskDone(void)
{
    MPLVC_MANAGER_T *const prMplvcMgr = (MPLVC_MANAGER_T *)&_rMplvcMgr;
    kal_mutexid rMutexID = prMplvcMgr->rMainMutexID;

    kal_trace(TRACE_GROUP_4, MPLVC_TRC_WAIT_FOR_TASK_DONE, _ENTER_);
    do
    {
        kal_take_mutex(rMutexID);
        if (KAL_FALSE == prMplvcMgr->fgProcessing)
        {
            kal_give_mutex(rMutexID);
            break;
        }
        kal_give_mutex(rMutexID);
        kal_sleep_task(1);
    } while(1);
    kal_trace(TRACE_GROUP_4, MPLVC_TRC_WAIT_FOR_TASK_DONE, _EXIT_);
}

/**
 *
 */
static void _MPLVC_MakeAsyncCall(const module_type dest, const PFN_MPLVC_REDIRECTION_T pfnProc, void *const pParam1,
            void *const pParam2, void * const pParam3)
{
    _MPLVC_SendMessage(dest, MSG_ID_MEDIA_VIDEO_CLIPPER_ASYNC_CALLBACK_REQ, pfnProc, pParam1, pParam2, pParam3);
}

/**
 *
 */
static void _MPLVC_AsyncCallDispatcher(ilm_struct *const prIlm)
{
    MPLVC_ASYNC_CALL_T *const req_p = (MPLVC_ASYNC_CALL_T*)prIlm->local_para_ptr;

    req_p->pfnRedirect(req_p->pParam1, req_p->pParam2, req_p->pParam3);
}


/**
 *
 */
static void _MPLVC_SetParam2Comp(VIDEO_COMPONENT_TYPE_T *const prComponentHandle,
        const VIDEO_PARAM_TYPE_T eParamType, void *const pvParam)
{
    PFN_SET_PARAMETER_T const pfnSetParameter = prComponentHandle->pfnSetParameter;
    VIDEO_ERROR_TYPE_T eVError;

    eVError = pfnSetParameter(eParamType, pvParam);
    if (eVError != VIDEO_ERROR_NONE)
    {
        _MPLVC_ASSERT(0);
    }
}


/**
 * This function runs in the context of the V2DEC
 */
__inline static void _MPLVC_Main(ilm_struct *prIlm)
{
    MPLVC_MANAGER_T *const prMplvcMgr = (MPLVC_MANAGER_T *)&_rMplvcMgr;
    kal_mutexid rMutexID = prMplvcMgr->rMainMutexID;
    MPLVC_TRACE(TRACE_GROUP_5, MPLVC_TRC_MAIN, _ENTER_);
    kal_take_mutex(rMutexID);
    _MPLVC_CancelTimer(prMplvcMgr);
    _MPLVC_ClrProcessing();
    _MPLVC_BUFFERMGR_Main();
    kal_give_mutex(rMutexID);
    MPLVC_TRACE(TRACE_GROUP_5, MPLVC_TRC_MAIN, _EXIT_);
}


/**
 *
 */
__inline static void _MPLVC_InitContainer(MPLVC_MANAGER_T *const prMplvcMgr)
{
    prMplvcMgr->eSourceContainerType = SourceProviderContainerType(MED_MODE_EDITOR_FILE, (kal_uint8 *)prMplvcMgr->rOpenInfo.pau2SrcPath, kal_wstrlen(prMplvcMgr->rOpenInfo.pau2SrcPath));

    kal_trace(TRACE_GROUP_4, MPLVC_TRC_CONTAINER_TYPE, prMplvcMgr->eSourceContainerType);

    switch(prMplvcMgr->eSourceContainerType)
    {
    case SOURCE_PROVIDER_MP4:
        {
            prMplvcMgr->eMuxerContainerType = MUXER_CONTAINER_MP4;
            prMplvcMgr->pfnEmptyThisBuffer = _MPLVC_MP4_EmptyThisBuffer;
            prMplvcMgr->pfnFillThisBuffer = _MPLVC_MP4_FillThisBuffer;
        }
        break;
    case SOURCE_PROVIDER_AVI:
        {
            prMplvcMgr->eMuxerContainerType = MUXER_CONTAINER_AVI;
            prMplvcMgr->pfnEmptyThisBuffer = _MPLVC_AVI_EmptyThisBuffer;
            prMplvcMgr->pfnFillThisBuffer = _MPLVC_AVI_FillThisBuffer;
        }
        break;
    default:
        _MPLVC_ASSERT(0);
        break;
    }
}

/**
 *
 */
__inline static media_error_t _MPLVC_DoOpen(MPLVC_MANAGER_T *const prMplvcMgr, mpl_clipper_open_t *const prOpenStruct)
{
    media_error_t eMError = MED_S_OK;
    VIDEO_ERROR_TYPE_T eVError = VIDEO_ERROR_NONE;

    // Check whether src path and dest path is the same?
    if (kal_wstrcmp(prOpenStruct->pau2SrcPath, prOpenStruct->pau2DstPath) == 0)
    {
        return MED_E_INVALID_PARAM;
    }

    if (FS_CheckFileName(prOpenStruct->pau2DstPath) != FS_NO_ERROR)
    {
        return MED_E_INVALID_PARAM;
    }

    prMplvcMgr->rOpenInfo = *prOpenStruct;

    _MPLVC_InitContainer(prMplvcMgr);

    // Open source component
    MEDIA_ERR_RTN(_MPLVC_SOURCE_Open(prMplvcMgr, prOpenStruct))

    // Open muxer component
    MEDIA_ERR_RTN(_MPLVC_MUXER_Open(prMplvcMgr, MUXER_SCENARIO_RECORD));

    // Setup tunnel
    eVError = VideoConfigComp(prMplvcMgr->prMuxerHandle,
                                KAL_TRUE,
                                VIDEO_PORT_VIDEO_DATA,
                                _MPLVC_VIDEO_FillThisBuffer);
    if (eVError != VIDEO_ERROR_NONE)
    {
        return MED_E_FAIL;
    }

    eVError = VideoConfigComp(prMplvcMgr->prMuxerHandle,
                                KAL_TRUE,
                                VIDEO_PORT_AUDIO_DATA,
                                _MPLVC_AUDIO_FillThisBuffer);

    if (eVError != VIDEO_ERROR_NONE)
    {
        return MED_E_FAIL;
    }

    _MPLVC_BUFFERMGR_SetLeftover(prMplvcMgr->eMuxerContainerType);

    prMplvcMgr->eState = MPLVC_STATE_READY;

    return MED_S_OK;
}


/**
 * This function is to play
 */
__inline static media_error_t _MPLVC_DoStart(MPLVC_MANAGER_T *const prMplvcMgr)
{
    media_error_t eMError = MED_S_OK;
    kal_uint64 u8VideoKeyFrameTime, u8AudioKeyFrameTime;
    kal_uint64 u8SeekTime = prMplvcMgr->rOpenInfo.u4StartTime;

    // Config Muxer Properties
    _MPLVC_MUXER_SetAudioProperties(prMplvcMgr);
    _MPLVC_MUXER_SetVideoProperties(prMplvcMgr);
    _MPLVC_MUXER_SetContainerProperties(prMplvcMgr);

    // Make sure Muxer is running before any data is generated.
    _MPLVC_MUXER_Start(prMplvcMgr);

    // Get Audio/Video key frame time
    _MPLVC_SOURCE_GetKeyFrameTime(prMplvcMgr, SOURCE_PROVIDER_PORT_VIDEO, &u8SeekTime, &u8VideoKeyFrameTime);

    // Cofing Source Audio
    if (prMplvcMgr->u1AudioStreamIdx != MPLVC_INVALID_INDEX)
    {
        _MPLVC_SOURCE_GetKeyFrameTime(prMplvcMgr, SOURCE_PROVIDER_PORT_AUDIO, &u8VideoKeyFrameTime, &u8AudioKeyFrameTime);
        MEDIA_ERR_RTN(_MPLVC_SOURCE_SetSeekTime(prMplvcMgr, SOURCE_PROVIDER_PORT_AUDIO, u8AudioKeyFrameTime, prMplvcMgr->rOpenInfo.u4EndTime));
        MEDIA_ERR_RTN(_MPLVC_SOURCE_SetPort(prMplvcMgr, SOURCE_PROVIDER_PORT_AUDIO, KAL_TRUE));

        if (u8AudioKeyFrameTime > u8VideoKeyFrameTime)
        {
            _MPLVC_ASSERT(0);
        }
        prMplvcMgr->u8BaseFrameTime = u8AudioKeyFrameTime * 1000;
    }
    else
    {
        prMplvcMgr->u8BaseFrameTime = u8VideoKeyFrameTime * 1000;
    }

    // Config Source Video
    if (prMplvcMgr->u1VideoStreamIdx != MPLVC_INVALID_INDEX)
    {
        // TODO:
        //MEDIA_ERR_RTN(_MPLVC_SOURCE_SetSeekTime(prMplvcMgr, SOURCE_PROVIDER_PORT_VIDEO, u8VideoKeyFrameTime, prMplvcMgr->rOpenInfo.u4EndTime));
        MEDIA_ERR_RTN(_MPLVC_SOURCE_SetSeekTime(prMplvcMgr, SOURCE_PROVIDER_PORT_VIDEO, u8SeekTime, prMplvcMgr->rOpenInfo.u4EndTime));
        // dont' need to set video seek time to source again.
        MEDIA_ERR_RTN(_MPLVC_SOURCE_SetPort(prMplvcMgr, SOURCE_PROVIDER_PORT_VIDEO, KAL_TRUE));
    }

    MEDIA_ERR_RTN(_MPLVC_SOURCE_Start(prMplvcMgr));

    prMplvcMgr->eState = MPLVC_STATE_RUNNING;
    visual_disable_sleep();

    return MED_S_OK;
}


/**
 * Stop source component and muxer, and wait for their completion later
 */
static void _MPLVC_DoStop(MPLVC_MANAGER_T *const prMplvcMgr)
{
    // Stop timer
    _MPLVC_CancelTimer(prMplvcMgr);
    _MPLVC_SOURCE_Stop(prMplvcMgr);
    _MPLVC_MUXER_Stop(prMplvcMgr);

    prMplvcMgr->fgStopped = KAL_TRUE;
    _MPLVC_WaitForTaskDone();
    prMplvcMgr->eState = MPLVC_STATE_STOPPED;
    visual_enable_sleep();
}


/**
 *
 */
static media_error_t _MPLVC_DoClose(MPLVC_MANAGER_T *const prMplvcMgr, const kal_bool fgDeleteTempFiles)
{
    media_error_t eMError = MED_S_OK;

    if (prMplvcMgr->eState == MPLVC_STATE_CLOSED)
    {
        return MED_S_OK;
    }

    _MPLVC_MUXER_Close(prMplvcMgr);
    if (fgDeleteTempFiles == KAL_TRUE)
    {
        _MPLVC_MUXER_DeleteTemporaryFiles(prMplvcMgr);
    }

    MEDIA_ERR_RTN(_MPLVC_SOURCE_Close(prMplvcMgr));
    prMplvcMgr->eState = MPLVC_STATE_CLOSED;

    return MED_S_OK;
}


/**
 *
 */
static void _MPLVC_DoFileMergeAsync(void *const pParam1, void *const pParam2, void *const pParam3)
{
    MPLVC_MANAGER_T *const prMplvcMgr = (MPLVC_MANAGER_T *)pParam1;

    kal_trace(TRACE_GROUP_4, MPLVC_TRC_FILE_MERGE);
    //_MPLVC_BUFFERMGR_WaitForWorkDone();
    _MPLVC_DoStop(prMplvcMgr);
    _MPLVC_DoClose(prMplvcMgr, KAL_FALSE);

    {
        // Check whether muxer callbacks error
        // Ignore the error and continue to create file
        kal_uint32 u4EventGroup;
        kal_retrieve_eg_events(prMplvcMgr->eEvent, MPLVC_EG_MUXER_ERROR,
            KAL_OR_CONSUME, &u4EventGroup, KAL_NO_SUSPEND);


        if (u4EventGroup & MPLVC_EG_MUXER_ERROR)
        {

        }
        // Create file
        _MPLVC_MUXER_CreateFinalFile(prMplvcMgr);
    }
}

/**
 *
 */
static void _MPLVC_DoFileMerge(void *const pParam1, void *const pParam2, void *const pParam3)
{
    MPLVC_MANAGER_T *const prMplvcMgr = (MPLVC_MANAGER_T *)pParam1;

    // Avoid EOS and disk full callback in the same time
    if (prMplvcMgr->fgDoFileMerge == KAL_FALSE)
    {
        prMplvcMgr->fgDoFileMerge = KAL_TRUE;
        _MPLVC_MakeAsyncCall(MOD_MED, _MPLVC_DoFileMergeAsync, prMplvcMgr, NULL, NULL);
    }
}


/**
 *
 */
static void _MPLVC_DoNotify(void *const pParam1, void *const pParam2, void *const pParam3)
{
    media_error_t eMError = MED_S_OK;
    mpl_clipper_event_t eEvent;
    MPLVC_MANAGER_T *const prMplvcMgr = (MPLVC_MANAGER_T *)pParam1;
    mpl_clipper_client_t * const prClient = &prMplvcMgr->rMplClient;

    eEvent = (mpl_clipper_event_t)pParam2;
    eMError = (media_error_t)pParam3;

    kal_trace(TRACE_GROUP_4, MPLVC_TRC_NOTIFY_EVENT, eEvent, eMError);
    prClient->on_event((mpl_clipper_client_t*)prClient, eEvent, eMError);
}

/**
 *
 */
static void _MPLVC_CheckAsyncError(void *const pParam1, void *const pParam2, void *const pParam3)
{
    MPLVC_MANAGER_T *const prMplvcMgr = (MPLVC_MANAGER_T *)pParam1;
    media_error_t eMError = MED_S_OK;
    kal_uint32 u4EventGroup;

    kal_retrieve_eg_events(prMplvcMgr->eEvent, MPLVC_EG_MUXER_ERROR,
        KAL_OR_CONSUME, &u4EventGroup, KAL_NO_SUSPEND);

    // Check whether muxer callbacks error
    if (u4EventGroup & MPLVC_EG_MUXER_ERROR)
    {
       eMError = MED_E_FAIL;
    }

    _MPLVC_DoNotify(pParam1, pParam2, (void *)eMError);
}

/**
 *
 */
static void _MPLVC_DoStopAndNotify(void *const pParam1, void *const pParam2, void *const pParam3)
{
    MPLVC_MANAGER_T *const prMplvcMgr = (MPLVC_MANAGER_T *)pParam1;

    switch (prMplvcMgr->eState)
    {
    case MPLVC_STATE_RUNNING:
        _MPLVC_DoStop(prMplvcMgr);
        break;

    case MPLVC_STATE_SAVING_FILE:
        _MPLVC_MUXER_Stop(prMplvcMgr);
        // TODO: MMI should call close()
        // _MPLVC_MUXER_Close(prMplvcMgr);
        prMplvcMgr->eState = MPLVC_STATE_STOPPED;
        break;
    default:
        break;
    }

    _MPLVC_DoNotify(pParam1, pParam2, pParam3);

}

/**
 *
 */
static void _MPLVC_StopAndNotify(const mpl_clipper_event_t eEvent, const media_error_t eMError)
{
    kal_bool fgReportError = KAL_FALSE;
    MPLVC_MANAGER_T *const prMplvcMgr = (MPLVC_MANAGER_T *)&_rMplvcMgr;

    switch (eEvent)
    {
    case MPL_CLIPPER_EVENT_SAVE:
        {
            if (prMplvcMgr->fgErrorOfSaveCommandReported == KAL_FALSE)
            {
                prMplvcMgr->fgErrorOfSaveCommandReported = KAL_TRUE;
                fgReportError = KAL_TRUE;
            }
        }
        break;
    default:
        _MPLVC_ASSERT(0);
        break;

    }

    if (fgReportError == KAL_TRUE)
    {
        _MPLVC_MakeAsyncCall(MOD_MED, _MPLVC_DoStopAndNotify, prMplvcMgr, (void*)eEvent,
                (void*)eMError);
    }
}

/**
 * This function is to open video clipper
 */
static media_error_t MPLVC_Open(mpl_clipper_t *prItf,
                                mpl_clipper_open_t *prOpenStruct)
{
    media_error_t eMError = MED_S_OK;
    MPLVC_MANAGER_T *const prMplvcMgr = SELF(prItf, MPLVC_MANAGER_T, rItf);

    kal_trace(TRACE_GROUP_4, MPLVC_TRC_OPEN, _ENTER_, prOpenStruct->u4StartTime, prOpenStruct->u4EndTime);
    switch (prMplvcMgr->eState)
    {
    case MPLVC_STATE_CLOSED:
        {
            eMError = _MPLVC_DoOpen(prMplvcMgr, prOpenStruct);
            if (eMError != MED_S_OK)
            {
                _MPLVC_DoClose(prMplvcMgr, KAL_TRUE);
                return eMError;
            }
        }
        break;
    default:
        {
            return MED_E_WRONG_STATE;
        }
        //break;
    }

    _MPLVC_MakeAsyncCall(MOD_MED, _MPLVC_CheckAsyncError, prMplvcMgr, (void*)MPL_CLIPPER_EVENT_OPEN, NULL);

    MPLVC_TRACE(TRACE_GROUP_4, MPLVC_TRC_OPEN, _EXIT_, prOpenStruct->u4StartTime, prOpenStruct->u4EndTime);
    return MED_S_ASYNC;
}


/**
 * This function is to start remux
 */
static media_error_t MPLVC_Start(mpl_clipper_t *prItf)
{
    media_error_t eMError = MED_S_OK;
    MPLVC_MANAGER_T *const prMplvcMgr = SELF(prItf, MPLVC_MANAGER_T, rItf);

    kal_trace(TRACE_GROUP_4, MPLVC_TRC_START, _ENTER_);

    switch (prMplvcMgr->eState)
    {
    case MPLVC_STATE_READY:
        eMError = _MPLVC_DoStart(prMplvcMgr);
        if (eMError != MED_S_OK)
        {
            _MPLVC_DoStop(prMplvcMgr);
            return eMError;
        }
        break;

    default:
        return MED_E_WRONG_STATE;
        //break;
    }

    _MPLVC_MakeAsyncCall(MOD_MED, _MPLVC_CheckAsyncError, prMplvcMgr, (void*)MPL_CLIPPER_EVENT_START, NULL);

    MPLVC_TRACE(TRACE_GROUP_4, MPLVC_TRC_START, _EXIT_);

    return MED_S_ASYNC;
}


/**
 * This function is to cancel remux
 */
static media_error_t MPLVC_Cancel(mpl_clipper_t *prItf)
{
    MPLVC_MANAGER_T *const prMplvcMgr = SELF(prItf, MPLVC_MANAGER_T, rItf);

    kal_trace(TRACE_GROUP_4, MPLVC_TRC_CANCEL, _ENTER_);

    switch (prMplvcMgr->eState)
    {
    case MPLVC_STATE_RUNNING:
    case MPLVC_STATE_SAVING_FILE:
        {
            prMplvcMgr->fgCanceled = KAL_TRUE;
            _MPLVC_DoStop(prMplvcMgr);
        }
        break;
    case MPLVC_STATE_STOPPED:
        break;
    default:
        return MED_E_WRONG_STATE;
        //break;
    }

    _MPLVC_MakeAsyncCall(MOD_MED, _MPLVC_CheckAsyncError, prMplvcMgr, (void*)MPL_CLIPPER_EVENT_STOP, NULL);

    MPLVC_TRACE(TRACE_GROUP_4, MPLVC_TRC_CANCEL, _EXIT_);

    return MED_S_ASYNC;
}


/**
 * This function is to close video clipper
 */
static media_error_t MPLVC_Close(mpl_clipper_t *prItf)
{
    media_error_t eMError = MED_S_OK;
    MPLVC_MANAGER_T *const prMplvcMgr = SELF(prItf, MPLVC_MANAGER_T, rItf);

    kal_trace(TRACE_GROUP_4, MPLVC_TRC_CLOSE, _ENTER_);

    switch (prMplvcMgr->eState)
    {
    case MPLVC_STATE_CLOSED:
        break;
    case MPLVC_STATE_READY:
    case MPLVC_STATE_STOPPED:
        {
            MEDIA_ERR_RTN(_MPLVC_DoClose(prMplvcMgr, KAL_TRUE));
        }
        break;
    default:
        return MED_E_WRONG_STATE;
        //break;
    }

    _MPLVC_MakeAsyncCall(MOD_MED, _MPLVC_CheckAsyncError, prMplvcMgr, (void*)MPL_CLIPPER_EVENT_CLOSE, NULL);

    MPLVC_TRACE(TRACE_GROUP_4, MPLVC_TRC_CLOSE, _EXIT_);
    return MED_S_ASYNC;
}


/**
 * This function is to get information from video clipper
 */
static media_error_t MPLVC_GetParam(mpl_clipper_t *prItf, mpl_clipper_param_enum eParam, void *pValue)
{
    switch (eParam)
    {
    case MPL_CLIPPER_PARAM_CURR_PROGRESS:
        {
            *((kal_uint32*)pValue) = _MPLVC_BUFFERMGR_GetProgress();
        }
        break;
    default:
        return MED_E_INVALID_PARAM;
    }
    return MED_S_OK;
}


/**
 * This function is to set parameter to video clipper
 */
static media_error_t MPLVC_SetParam(mpl_clipper_t *prItf, mpl_clipper_param_enum eParam, void *pValue)
{
    // Do Nothing
    return MED_S_OK;
}


/**
 * This function is to destroy video clipper
 */
static void MPLVC_Destroy(mpl_clipper_t* prItf)
{
    kal_trace(TRACE_GROUP_4, MPLVC_TRC_CLIPPER_DESTROY);

    if (prItf == NULL)
    {
        _MPLVC_ASSERT(0);
    }
    else
    {
        MPLVC_MANAGER_T *const prMplvcMgr = SELF(prItf, MPLVC_MANAGER_T, rItf);
        _MPLVC_BUFFERMGR_Deinit();

        // Release resource
        _VideoFreeEventGroup(EVG_USER_MPL_CLIPPER, prMplvcMgr->eEvent);

        VideoFreeTimer(TIMER_USER_CLIPPERMPL, prMplvcMgr->rTimerID);
        prMplvcMgr->rTimerID = NULL;

        VideoFreeMutex(MUTEX_USER_CLIPPERMPL_TIMER, prMplvcMgr->rTimerMutexID);
        prMplvcMgr->rTimerMutexID = NULL;

        VideoFreeMutex(MUTEX_USER_CLIPPERMPL_MAIN, prMplvcMgr->rMainMutexID);
        prMplvcMgr->rMainMutexID = NULL;
    }
}


/**
 *
 */
static media_error_t MPLVC_GetDefault(mpl_clipper_t *prItf, mpl_clipper_param_type_enum eParamType,
                                        void *prParam, kal_int32 u4Size)
{
    switch (eParamType)
    {
    case MPL_CLIPPER_OPEN_PARAM:
        {
            mpl_clipper_open_t *prOpenParam;

            if (sizeof(mpl_clipper_open_t) != u4Size)
            {
                _MPLVC_ASSERT(0);
            }
            ZERO_MEMORY(prParam, u4Size);
            prOpenParam = (mpl_clipper_open_t*)prParam;
            prOpenParam->u4EndTime = 0xFFFFFFFF;
        }
        break;
    default:
        {
            _MPLVC_ASSERT(0);
        }
        break;
    }
    return MED_S_OK;
}


/**
 * The function is runned in MED or V2DEC Task
 */
void video_clipper_main(ilm_struct *prIlm)
{
    switch (prIlm->msg_id)
    {
    case MSG_ID_MEDIA_VIDEO_CLIPPER_ASYNC_CALLBACK_REQ: // MED Task
        _MPLVC_AsyncCallDispatcher(prIlm);
        break;
    case MSG_ID_MPLVC_DATA_IND: // V2DEC Task
        _MPLVC_Main(prIlm);
        break;
    default:
        _MPLVC_ASSERT(0);
        break;
    }
}

const static mpl_clipper_t _rInterface =
{
    MPLVC_Open,     // open
    MPLVC_Start,    // start
    MPLVC_Cancel,   // cancel
    MPLVC_Close,    // close
    MPLVC_GetParam, // get_param
    MPLVC_SetParam, // set_param
    MPLVC_Destroy,  // destroy
    MPLVC_GetDefault // get_default
};

/**
 * This function is to construct video clipper
 */
mpl_clipper_t* construct_media_clipper(mpl_clipper_client_t *prClient)
{
    MPLVC_MANAGER_T *const prMplvcMgr = (MPLVC_MANAGER_T *)&_rMplvcMgr;

    kal_trace(TRACE_GROUP_4, MPLVC_TRC_CLIPPER_CONSTRUCT);

    ZERO_MEMORY(prMplvcMgr, sizeof(*prMplvcMgr));
    prMplvcMgr->rMplClient = *prClient;
    prMplvcMgr->rItf = _rInterface;

    _MPLVC_BUFFERMGR_Init(prMplvcMgr);

    prMplvcMgr->eEvent = _VideoGetEventGroup(EVG_USER_MPL_CLIPPER);
    prMplvcMgr->rTimerID = VideoGetTimer(TIMER_USER_CLIPPERMPL);
    prMplvcMgr->rTimerMutexID = VideoGetMutex(MUTEX_USER_CLIPPERMPL_TIMER);
    prMplvcMgr->rMainMutexID = VideoGetMutex(MUTEX_USER_CLIPPERMPL_MAIN);

    return &prMplvcMgr->rItf;
}

#endif // defined (__VE_VIDEO_CLIPPER_SUPPORT__)
#endif // defined (__VE_VIDEO_ARCHI_V2__)
