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
 *   source_provider_component_v2.c
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
 * removed!
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
 ****************************************************************************/


#include "drv_comm.h"
#ifdef __VE_SOURCE_PROVIDER__
#include "fsal.h"
//#include "app_ltlcom.h"       /* Task message communiction */
#include "stack_ltlcom.h"
//#include "stack_config.h"
#include "mpl_common.h"
//#include "mpl_session_mem.h"
#include "media_provider_mem_usage.h"
#include "video_buffer_management_v2.h"
#include "vcodec_v2_trc.h"
#include "source_provider_component.h"
#include "source_provider_isolation.h"
#include "source_provider_if.h"
//#include "drm_gprot.h"
#include "kal_trace.h"

#include "video_fluency_if.h"

#ifndef VIDEO_DECODER_DEMUXER_IF_V2_H
#include "video_decoder_demuxer_if_v2.h"
#endif

#ifdef __VE_DCM_WITH_COMPRESSION__
#include "dcmgr.h" //DCM

#pragma arm section code = "DYNAMIC_CODE_VEDEC_ROCODE", rodata = "DYNAMIC_CODE_VEDEC_RODATA"
#endif

#if 0
/* under construction !*/
/* under construction !*/
#endif

SRC_PRIVDER_CONTEXT_T *_prSrcProviderMgr = NULL, *_prSrcProviderMgr2 = NULL, *_prSrcProviderMgr3 = NULL;

extern const SP_API_T rAPIsForPrv;

#ifdef __VE_STREAM_SUPPORT__
static kal_bool _SourceProviderStreamingBufferStatus(SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr, SP_PORT_TYPE_T ePort);
#endif

#ifdef __VE_DUMP_PROVIDER_BITSTREAM__
static const kal_uint8 au1H264Start[4] = { 0x0, 0x0, 0x0, 0x1};
static const kal_uint8 au1H264StartCode[3] = { 0x0, 0x0, 0x1};
static kal_bool fgFirst = KAL_FALSE;
#endif

static SP_ERROR_TYPE_T _SourceProviderBaseFileOpen(kal_bool fgSource, SPIF_OPEN_INFO_T *rOpenInfo)
{
    FSAL_Status eFsalRet;
    kal_int32 i4DrmRet;

    if (rOpenInfo->fgBufMode == KAL_FALSE) // from file
    {
            eFsalRet = FSAL_Open(rOpenInfo->prFileHandle, (void*)rOpenInfo->pu1Data, FSAL_READ);
            if (eFsalRet != FSAL_OK)
            {
                SP_TRACE_FSAL_ERROR(eFsalRet, 0, fgSource);
                return SOURCE_PROVIDER_ERROR;
            }

            if (rOpenInfo->fgSetBuffer == KAL_TRUE)
            {
                FSAL_SetBuffer(rOpenInfo->prFileHandle, rOpenInfo->u4SetBufSize, rOpenInfo->pu1SetBuf);
            }

            if (rOpenInfo->fgSetSeekHint == KAL_TRUE)
            {
                #ifndef __LOW_COST_SUPPORT_ULC__
                i4DrmRet = FSAL_SetSeekHint(rOpenInfo->prFileHandle, rOpenInfo->u4SetHintSize, (void *)rOpenInfo->prSeekHint);
                //u4DrmRet = DRM_set_seek_hint(rOpenInfo->prFileHandle->hFile, rOpenInfo->u4SetHintSize, rOpenInfo->prSeekHint);
                if (i4DrmRet < 0)
                {
                    SP_TRACE_FSAL_ERROR(i4DrmRet, 0, fgSource);
                    FSAL_Close(rOpenInfo->prFileHandle);
                    return SOURCE_PROVIDER_ERROR;
                }
                #endif
            }
    }
    else
    {
            FSAL_Direct_SetRamFileSize(rOpenInfo->prFileHandle, rOpenInfo->u4Size);
            eFsalRet = FSAL_Open(rOpenInfo->prFileHandle, (void*)rOpenInfo->pu1Data, FSAL_ROMFILE);
            if (eFsalRet != FSAL_OK)
            {
                SP_TRACE_FSAL_ERROR(eFsalRet, 0, fgSource);
                return SOURCE_PROVIDER_ERROR;
            }
    }

    return SOURCE_PROVIDER_ERROR_NONE;
}

static void _SourceProviderTakeMutex(kal_mutexid ext_mutex_id_ptr)
{
#ifdef __VE_STREAM_SUPPORT__
    if (ext_mutex_id_ptr != NULL)
    {
        kal_take_mutex(ext_mutex_id_ptr);
    }
#endif
}

static void _SourceProviderGiveMutex(kal_mutexid ext_mutex_id_ptr)
{
#ifdef __VE_STREAM_SUPPORT__
    if (ext_mutex_id_ptr != NULL)
    {
        kal_give_mutex(ext_mutex_id_ptr);
    }
#endif
}


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

static void _SourceProviderBufferHeaderInit(SP_BUFFER_HEADER_T *prMgr, kal_uint8 *pu1Buffer, kal_uint32 u4MaxNumberofAtoms, kal_uint32 u4UnitSize, kal_mutexid rMutex)
{
    _SourceProviderTakeMutex(rMutex);
    VideoCoreInitRingBuffer(&prMgr->rMgr, pu1Buffer, u4MaxNumberofAtoms, u4UnitSize);
    prMgr->rMutex = rMutex; // obtain mutex
    prMgr->u4Send = 1;
    prMgr->u4UnSendNum = 0;
    #if (defined(__VE_SP_SEEK_SPEED_UP__) || defined(__VE_SP_STREAM_JUMP__))
    prMgr->u8MaxTime = 0;
    prMgr->u8MinTime = 0;
    #endif
    _SourceProviderGiveMutex(rMutex);
}

static void _SourceProviderBufferHeaderDeInit(SP_BUFFER_HEADER_T *prMgr)
{
    _SourceProviderTakeMutex(prMgr->rMutex);
    VideoCoreDeInitRingBuffer(&prMgr->rMgr);
    // release mutex
    prMgr->u4Send = 1;
    prMgr->u4UnSendNum = 0;
    #if (defined(__VE_SP_SEEK_SPEED_UP__) || defined(__VE_SP_STREAM_JUMP__))
    prMgr->u8MaxTime = 0;
    prMgr->u8MinTime = 0;
    #endif
    _SourceProviderGiveMutex(prMgr->rMutex);
}

static void _SourceProviderBufferHeaderReset(SP_BUFFER_HEADER_T *prMgr)
{
    _SourceProviderTakeMutex(prMgr->rMutex);
    VideoCoreCleanRingBuffer(&prMgr->rMgr);
    prMgr->u4Send = 1;
    prMgr->u4UnSendNum = 0;
    #if (defined(__VE_SP_SEEK_SPEED_UP__) || defined(__VE_SP_STREAM_JUMP__))
    prMgr->u8MaxTime = 0;
    prMgr->u8MinTime = 0;
    #endif
    _SourceProviderGiveMutex(prMgr->rMutex);
}

static kal_bool _SourceProviderBufferHeaderFull(SP_BUFFER_HEADER_T *prMgr)
{
    kal_bool fgRet;

    _SourceProviderTakeMutex(prMgr->rMutex);
    fgRet = VideoCoreIsRingBufferFull(&prMgr->rMgr);
    _SourceProviderGiveMutex(prMgr->rMutex);

    return fgRet;
}

static kal_uint32 _SourceProviderBufferHeaderUsedNum(SP_BUFFER_HEADER_T *prMgr)
{
    kal_uint32 u4Num;

    _SourceProviderTakeMutex(prMgr->rMutex);
    u4Num = VideoCoreRingBufferUsedNum(&prMgr->rMgr);
    _SourceProviderGiveMutex(prMgr->rMutex);

    return u4Num;
}

#if defined(__VE_STREAM_SUPPORT__) || defined(__VE_SP_PROFILE__)
static kal_uint32 _SourceProviderBufferHeaderFreeNum(SP_BUFFER_HEADER_T *prMgr)
{
    VIDEO_CORE_RING_BUFFER_MGR_T *prCoreMgr = &prMgr->rMgr;
    kal_uint32 u4Num;

    _SourceProviderTakeMutex(prMgr->rMutex);
    u4Num = VideoCoreRingGetBufferMaxNum(prCoreMgr) - VideoCoreRingBufferUsedNum(prCoreMgr);
    _SourceProviderGiveMutex(prMgr->rMutex);

    return u4Num;
}
#endif

static kal_uint32 _SourceProviderBufferHeaderSendNum(SP_BUFFER_HEADER_T *prMgr)
{
    kal_uint32 u4Num;

    _SourceProviderTakeMutex(prMgr->rMutex);
    u4Num = VideoCoreRingBufferUsedNum(&prMgr->rMgr) - prMgr->u4UnSendNum;
    _SourceProviderGiveMutex(prMgr->rMutex);

    return u4Num;
}

static SP_ERROR_TYPE_T _SourceProviderBufferHeaderCheckSendBuf(SP_BUFFER_HEADER_T *prMgr)
{
    VIDEO_CORE_RING_BUFFER_MGR_T *prCoreMgr = &prMgr->rMgr;

    _SourceProviderTakeMutex(prMgr->rMutex);
    if (VideoCoreIsRingBufferEmpty(prCoreMgr) == KAL_FALSE)
    {
        if ((prMgr->u4UnSendNum>VideoCoreRingBufferUsedNum(prCoreMgr)) ||
             (prMgr->u4UnSendNum != 0 &&
               ((prMgr->u4Send>prCoreMgr->u4Head && prMgr->u4Send<prCoreMgr->u4Tail) ||
                 (prCoreMgr->u4Head>prCoreMgr->u4Tail && (prMgr->u4Send>prCoreMgr->u4Head || prMgr->u4Send<prCoreMgr->u4Tail))))
            )
        {
            _SourceProviderGiveMutex(prMgr->rMutex);
            ASSERT(0);
            return SOURCE_PROVIDER_ASSERT_ERROR;
        }
    }
    else
    {
        if (prCoreMgr->u4Tail!= prMgr->u4Send || prMgr->u4UnSendNum != 0)
        {
            _SourceProviderGiveMutex(prMgr->rMutex);
            ASSERT(0);
            return SOURCE_PROVIDER_ASSERT_ERROR;
        }
    }
    _SourceProviderGiveMutex(prMgr->rMutex);

    return SOURCE_PROVIDER_ERROR_NONE;
}

static kal_uint8* _SourceProviderBufferHeaderGetWriteBuf(SP_BUFFER_HEADER_T *prMgr)
{
    kal_uint8 *pu1Buffer;

    _SourceProviderTakeMutex(prMgr->rMutex);
    pu1Buffer = VideoCoreGetNextHeadofRingBufferAddr(&prMgr->rMgr);
    _SourceProviderGiveMutex(prMgr->rMutex);

    return pu1Buffer;
}

static SP_ERROR_TYPE_T _SourceProviderBufferHeaderAddWriteBuf(SP_BUFFER_HEADER_T *prMgr, kal_bool fgUpdateTime, kal_uint64 u8Time)
{
    kal_bool fgRet;

    _SourceProviderTakeMutex(prMgr->rMutex);
    fgRet = VideoCoreAddHeadofRingBuffer(&prMgr->rMgr);
    #if (defined(__VE_SP_SEEK_SPEED_UP__) || defined(__VE_SP_STREAM_JUMP__))
    if (fgUpdateTime == KAL_TRUE)
    {
        prMgr->u8MaxTime = u8Time;
    }
    #endif
    prMgr->u4UnSendNum++;
    _SourceProviderGiveMutex(prMgr->rMutex);

    if (fgRet == KAL_FALSE)
    {
        ASSERT(0);
        return SOURCE_PROVIDER_ASSERT_ERROR;
    }
    else
    {
        return SOURCE_PROVIDER_ERROR_NONE;
    }
}

static kal_uint8* _SourceProviderBufferHeaderGetReadBuf(SP_BUFFER_HEADER_T *prMgr)
{
    kal_uint8 *pu1Buffer;

    _SourceProviderTakeMutex(prMgr->rMutex);
    pu1Buffer = VideoCoreGetTailofRingBufferAddr(&prMgr->rMgr);
    _SourceProviderGiveMutex(prMgr->rMutex);

    return pu1Buffer;
}


static SP_ERROR_TYPE_T _SourceProviderBufferHeaderAddReadBuf(SP_BUFFER_HEADER_T *prMgr, kal_bool fgUpdateTime, kal_uint64 u8Time)
{
    kal_bool fgRet;

    _SourceProviderTakeMutex(prMgr->rMutex);
    fgRet = VideoCoreConsumeTailofRingBuffer(&prMgr->rMgr);
    #if (defined(__VE_SP_SEEK_SPEED_UP__) || defined(__VE_SP_STREAM_JUMP__))
    if (fgUpdateTime == KAL_TRUE)
    {
        prMgr->u8MinTime = u8Time;
    }
    #endif
    _SourceProviderGiveMutex(prMgr->rMutex);
    if (fgRet == KAL_FALSE)
    {
        ASSERT(0);
        return SOURCE_PROVIDER_ASSERT_ERROR;
    }

    return _SourceProviderBufferHeaderCheckSendBuf(prMgr);
}

static kal_uint8* _SourceProviderBufferHeaderGetSendBuf(SP_BUFFER_HEADER_T *prMgr)
{
    VIDEO_CORE_RING_BUFFER_MGR_T *prCoreMgr = &prMgr->rMgr;
    kal_uint8 *pu1Buffer;

    if (prMgr->u4UnSendNum != 0)
    {
        _SourceProviderTakeMutex(prMgr->rMutex);
        pu1Buffer = (prCoreMgr->pu1Start + (prMgr->u4Send*prCoreMgr->u4SizeOfAnAtom));
        _SourceProviderGiveMutex(prMgr->rMutex);

        if (_SourceProviderBufferHeaderCheckSendBuf(prMgr) != SOURCE_PROVIDER_ERROR_NONE)
        {
            return NULL;
        }

        return pu1Buffer;
    }
    else
    {
        return NULL;
    }
}

static SP_ERROR_TYPE_T _SourceProviderBufferHeaderAddSendBuf(SP_BUFFER_HEADER_T *prMgr)
{
    kal_uint32 u4Temp;
    if (prMgr->u4UnSendNum != 0)
    {
        _SourceProviderTakeMutex(prMgr->rMutex);
        u4Temp = prMgr->u4Send+1;
        if (u4Temp == VideoCoreRingGetBufferMaxNum(&prMgr->rMgr))
        {
            u4Temp = 0;
        }
        prMgr->u4Send = u4Temp;
        prMgr->u4UnSendNum--;
        _SourceProviderGiveMutex(prMgr->rMutex);

        if (_SourceProviderBufferHeaderCheckSendBuf(prMgr) != SOURCE_PROVIDER_ERROR_NONE)
        {
            return SOURCE_PROVIDER_ASSERT_ERROR;
        }

        return SOURCE_PROVIDER_ERROR_NONE;
    }
    else
    {
        ASSERT(0);
        return SOURCE_PROVIDER_ASSERT_ERROR;
    }
}

static kal_bool _SourceProviderBufferHeaderSendBufFull(SP_BUFFER_HEADER_T *prMgr)
{
    VIDEO_CORE_RING_BUFFER_MGR_T *prCoreMgr = &prMgr->rMgr;
    kal_bool fgRet = KAL_FALSE;

    _SourceProviderTakeMutex(prMgr->rMutex);
    if (VideoCoreIsRingBufferFull(prCoreMgr) == KAL_TRUE)
    {
        if (prMgr->u4Send == prCoreMgr->u4Tail && prMgr->u4UnSendNum != 0)
        {
            fgRet = KAL_TRUE;
        }
    }
    _SourceProviderGiveMutex(prMgr->rMutex);

    return fgRet;
}

#ifdef __VE_PGDL_SUPPORT__
static kal_uint32 _SourceProviderBufferHeaderUnsendBufNum(SP_BUFFER_HEADER_T *prMgr)
{
    kal_uint32 u4Num;

    _SourceProviderTakeMutex(prMgr->rMutex);
    u4Num = prMgr->u4UnSendNum;
    _SourceProviderGiveMutex(prMgr->rMutex);

    return u4Num;
}
#endif

#if (defined(__VE_SP_SEEK_SPEED_UP__) || defined(__VE_SP_STREAM_JUMP__))
static void _SourceProviderBufferHeaderSetSendBuf(SP_BUFFER_HEADER_T *prMgr, kal_bool fgFull)
{
    VIDEO_CORE_RING_BUFFER_MGR_T *prCoreMgr = &prMgr->rMgr;

     _SourceProviderTakeMutex(prMgr->rMutex);
     if (fgFull == KAL_TRUE)
     {
         prMgr->u4Send = prCoreMgr->u4Tail;
         prMgr->u4UnSendNum = VideoCoreRingBufferUsedNum(prCoreMgr);
     }
     else
     {
         // set to write pointer
         prMgr->u4Send = prCoreMgr->u4Head + 1;
         if (prMgr->u4Send == VideoCoreRingGetBufferMaxNum(prCoreMgr))
         {
            prMgr->u4Send = 0;
         }
         prMgr->u4UnSendNum = 0;
     }
     _SourceProviderGiveMutex(prMgr->rMutex);
}
#endif

#ifdef __VE_SP_SEEK_SPEED_UP__
static kal_bool _SourceProviderBufferHeaderTimeInBuff(SP_BUFFER_HEADER_T *prMgr, kal_uint64 u8Time)
{
    kal_bool fgRet;
    
    _SourceProviderTakeMutex(prMgr->rMutex);
    if (u8Time > prMgr->u8MinTime && u8Time <= prMgr->u8MaxTime && VideoCoreRingBufferUsedNum(&prMgr->rMgr) != 0)
    {
        fgRet = KAL_TRUE;
    }
    else
    {
        fgRet = KAL_FALSE;
    }
    _SourceProviderGiveMutex(prMgr->rMutex);
    return fgRet;
}
#endif

#ifdef __VE_SP_STREAM_JUMP__
static kal_bool _SourceProviderBufferHeaderMaxKeyTime(SP_BUFFER_HEADER_T *prMgr, kal_uint64 u8StartTime, kal_uint64 *pu8TargetTime)
{
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr = &prMgr->rMgr;
    VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader;
    kal_uint32 u4Head, u4Num, u4MaxNum;
    kal_uint64 u8ProcessTime;

    _SourceProviderTakeMutex(prMgr->rMutex);
    if (u8StartTime <= prMgr->u8MinTime && VideoCoreIsRingBufferEmpty(prBufferMgr) == KAL_TRUE)
    {
        _SourceProviderGiveMutex(prMgr->rMutex);
        return KAL_FALSE;
    }

    u4Head = prBufferMgr->u4Head;
    u4Num = prBufferMgr->u4NumberOfAtoms;
    u4MaxNum = prBufferMgr->u4MaxNumberofAtoms;

    while (u4Num != 0)
    {
        prBuffHeader = (VIDEO_BUFFERHEADER_TYPE_T *)(prBufferMgr->pu1Start + (u4Head*prBufferMgr->u4SizeOfAnAtom));
        u8ProcessTime = prBuffHeader->u8TimeStamp/1000;
    
        if (((kal_uint32)(prBuffHeader->eFlags) & (kal_uint32)(VIDEO_BUFFERFLAG_SYNCFRAME)) != NULL &&
             (u8ProcessTime <= u8StartTime)
            )
        {
            *pu8TargetTime = u8ProcessTime;
            _SourceProviderGiveMutex(prMgr->rMutex);

            #ifdef __VE_SP_LOG_HIGH__
            drv_trace2(SP_TRACE_HIGH_GROUP, SP_GET_KEY_TIME, u8StartTime, u8ProcessTime); 
            #endif
            return KAL_TRUE;
        }

        if (u4Head == 0)
        {
            u4Head = u4MaxNum-1;
        }
        else
        {
            u4Head--;
        }

        u4Num--;
    }

    _SourceProviderGiveMutex(prMgr->rMutex);
    return KAL_FALSE;
}
#endif

static void _SourceProviderCheckAvailable(SP_BITSTREAM_BUF_T *prMgr, kal_bool fgCheckInit, kal_bool fgError1, kal_bool fgError2)
{
    kal_bool fgAssert = KAL_FALSE;
    
    if (prMgr == NULL || fgError1 == KAL_TRUE || fgError1 == KAL_TRUE)
    {    
        fgAssert = KAL_TRUE;
    }
    else if (fgCheckInit == KAL_TRUE)
    {
        if (prMgr->fgInitialized == KAL_FALSE)
        {
            fgAssert = KAL_TRUE;
        }
    }

    if (fgAssert == KAL_TRUE)
    {
        ASSERT(0);
    }
}

static void _SourceProviderBitstreamBufInit(SP_BITSTREAM_BUF_T *prMgr, kal_uint32 u4Buffer, kal_uint32 u4BufSize, kal_mutexid rMutex)
{
    kal_uint32 u4Addr, u4Offset, u4Szie; // u4Offset for addrss alignment, u4Szie for size alignment

    _SourceProviderCheckAvailable(prMgr, KAL_FALSE, (kal_bool)(u4Buffer==0), (kal_bool)(u4BufSize==0));

    u4Addr = SP_ROUND_UP_TO_POWER_OF_TWO(u4Buffer, SP_CPU_CACHE_LINE_SIZE);
    u4Offset = u4Addr - u4Buffer;

    u4Szie = (u4BufSize-u4Offset) & ~((kal_uint32)SP_CPU_CACHE_LINE_SIZE-1);

    _SourceProviderTakeMutex(rMutex);
    kal_mem_set((void*)prMgr, 0, sizeof(SP_BITSTREAM_BUF_T));
    prMgr->u4StartAdd= u4Buffer;
    prMgr->u4RealStartAdd = u4Addr;
    prMgr->u4WriteAdd = u4Addr;
    prMgr->u4ReadAdd = u4Addr;
    prMgr->u4RealSize = u4Szie;
    prMgr->u4LeftSize2 = u4Szie;
    prMgr->fgInitialized = KAL_TRUE;
    prMgr->rMutex = rMutex; // obtain mutex
    _SourceProviderGiveMutex(rMutex);
}

static void _SourceProviderBitstreamBufDeInit(SP_BITSTREAM_BUF_T *prMgr)
{
    kal_mutexid rMutex = prMgr->rMutex;
    _SourceProviderCheckAvailable(prMgr, KAL_TRUE, KAL_FALSE, KAL_FALSE);

    _SourceProviderTakeMutex(rMutex);
    kal_mem_set((void*)prMgr, 0, sizeof(SP_BITSTREAM_BUF_T));
    prMgr->fgInitialized = KAL_FALSE;
    _SourceProviderGiveMutex(rMutex);
}

static void _SourceProviderBitstreamBufReset(SP_BITSTREAM_BUF_T *prMgr)
{
    _SourceProviderCheckAvailable(prMgr, KAL_TRUE, KAL_FALSE, KAL_FALSE);

    _SourceProviderTakeMutex(prMgr->rMutex);
    prMgr->u4WriteAdd = prMgr->u4RealStartAdd;
    prMgr->u4ReadAdd = prMgr->u4RealStartAdd;
    prMgr->u4LeftSize2 = prMgr->u4RealSize;
    prMgr->u4LeftSize1 = 0;
    prMgr->u4LockSize = 0;
    _SourceProviderGiveMutex(prMgr->rMutex);
}

static kal_uint32 _SourceProviderBitstreamBufAllocatedSize(SP_BITSTREAM_BUF_T *prMgr)
{
    _SourceProviderCheckAvailable(prMgr, KAL_TRUE, KAL_FALSE, KAL_FALSE);
    return prMgr->u4RealSize;
}

static kal_uint32 _SourceProviderBitstreamBufUsedSize(SP_BITSTREAM_BUF_T *prMgr)
{
    kal_uint32 u4Size;

    _SourceProviderCheckAvailable(prMgr, KAL_TRUE, KAL_FALSE, KAL_FALSE);

    _SourceProviderTakeMutex(prMgr->rMutex);
    u4Size = (prMgr->u4RealSize -prMgr->u4LeftSize1 - prMgr->u4LeftSize2);
    _SourceProviderGiveMutex(prMgr->rMutex);

    return u4Size;
}

static kal_uint32 _SourceProviderBitstreamBufTotalLeftSize(SP_BITSTREAM_BUF_T *prMgr)
{
    kal_uint32 u4Size;

    _SourceProviderCheckAvailable(prMgr, KAL_TRUE, KAL_FALSE, KAL_FALSE);

    _SourceProviderTakeMutex(prMgr->rMutex);
    u4Size = (prMgr->u4LeftSize1 + prMgr->u4LeftSize2);
    _SourceProviderGiveMutex(prMgr->rMutex);

    return u4Size;
}

static void _SourceProviderBitstreamBufUpdataSize(SP_BITSTREAM_BUF_T *prMgr, kal_bool fgWrite)
{
    _SourceProviderTakeMutex(prMgr->rMutex);
    if (prMgr->u4WriteAdd >= prMgr->u4ReadAdd)
    {
        if (prMgr->u4WriteAdd ==  prMgr->u4ReadAdd && fgWrite == KAL_TRUE)
        {
            prMgr->u4LeftSize1 = 0;
            prMgr->u4LeftSize2 = 0;
        }
        else
        {
            prMgr->u4LeftSize1 = prMgr->u4ReadAdd - prMgr->u4RealStartAdd;
            prMgr->u4LeftSize2 = prMgr->u4RealStartAdd+prMgr->u4RealSize-prMgr->u4WriteAdd;
        }
    }
    else
    {
        prMgr->u4LeftSize1 = 0;
        prMgr->u4LeftSize2 = prMgr->u4ReadAdd - prMgr->u4WriteAdd;
    }
    _SourceProviderGiveMutex(prMgr->rMutex);
}

static kal_uint32 _SourceProviderBitstreamBufGetBuf(SP_BITSTREAM_BUF_T *prMgr, kal_uint32 u4RequiredSize, kal_uint32 *u4AvailableSize)
{
    _SourceProviderCheckAvailable(prMgr, KAL_TRUE, (kal_bool)(u4AvailableSize==NULL), (kal_bool)(u4RequiredSize==0));

    _SourceProviderTakeMutex(prMgr->rMutex);
    if (prMgr->u4LeftSize2>=u4RequiredSize)
    {
        *u4AvailableSize = prMgr->u4LeftSize2;
    }
    else
    {
        if (prMgr->u4LeftSize1>=u4RequiredSize)
        {
            *u4AvailableSize = prMgr->u4LeftSize1;
            // skip left size 2 memory
            prMgr->u4LeftSize2 = 0;
            prMgr->u4WriteAdd = prMgr->u4RealStartAdd;
        }
        else
        {
            *u4AvailableSize = 0;
            _SourceProviderGiveMutex(prMgr->rMutex);
            return NULL;
        }
    }

    prMgr->u4LockSize = *u4AvailableSize;
    _SourceProviderGiveMutex(prMgr->rMutex);

    return prMgr->u4WriteAdd;
}

static SP_ERROR_TYPE_T _SourceProviderBitstreamBufUpdataAdd(SP_BITSTREAM_BUF_T *prMgr, kal_uint32 u4Add)
{
    kal_uint32 u4TempAdd;

    _SourceProviderCheckAvailable(prMgr, KAL_TRUE, (kal_bool)(u4Add == 0), KAL_FALSE);

    u4TempAdd = SP_ROUND_UP_TO_POWER_OF_TWO(u4Add, SP_CPU_CACHE_LINE_SIZE);

    if((prMgr->u4LockSize == 0 && prMgr->u4WriteAdd != u4TempAdd) ||
        (u4TempAdd > prMgr->u4WriteAdd+prMgr->u4LockSize) ||
        (prMgr->u4ReadAdd > prMgr->u4WriteAdd && u4TempAdd>prMgr->u4ReadAdd))
    {
        ASSERT(0);
        return SOURCE_PROVIDER_ASSERT_ERROR;
    }

    _SourceProviderTakeMutex(prMgr->rMutex);
    prMgr->u4LockSize = prMgr->u4WriteAdd + prMgr->u4LockSize - u4TempAdd;
    prMgr->u4WriteAdd = u4TempAdd;
    _SourceProviderGiveMutex(prMgr->rMutex);

    _SourceProviderBitstreamBufUpdataSize(prMgr, KAL_TRUE);

    return SOURCE_PROVIDER_ERROR_NONE;
}

static SP_ERROR_TYPE_T _SourceProviderBitstreamBufReleaseBuf(SP_BITSTREAM_BUF_T *prMgr, kal_uint32 u4Add, kal_uint32 u4Size)
{
    kal_uint32 u4LastAdd;

    _SourceProviderCheckAvailable(prMgr, KAL_TRUE, (kal_bool)(u4Add == 0), (kal_bool)(u4Size == 0));

    u4LastAdd = u4Add+u4Size;

    _SourceProviderTakeMutex(prMgr->rMutex);
    if ((u4LastAdd>prMgr->u4WriteAdd && u4LastAdd< prMgr->u4ReadAdd) ||
        (prMgr->u4WriteAdd>prMgr->u4ReadAdd && (u4LastAdd>prMgr->u4WriteAdd ||u4LastAdd< prMgr->u4ReadAdd)))
    {
        ASSERT(0);
        return SOURCE_PROVIDER_ASSERT_ERROR;
    }
    else
    {
        prMgr->u4ReadAdd = u4LastAdd & (~((kal_uint32)SP_CPU_CACHE_LINE_SIZE-1));
    }

    _SourceProviderGiveMutex(prMgr->rMutex);

    _SourceProviderBitstreamBufUpdataSize(prMgr, KAL_FALSE);

    return SOURCE_PROVIDER_ERROR_NONE;
}

static void _SourceProviderPrivateBufinit(SP_PRIVATE_BUF_T *prMgr, void *pvBuffer, kal_uint32 u4BufSize, kal_mutexid rMutexId)
{
    _SourceProviderTakeMutex(rMutexId);
    prMgr->rAdmID = kal_adm_create(pvBuffer, u4BufSize, NULL, KAL_TRUE);
    prMgr->rMutex = rMutexId;
    _SourceProviderGiveMutex(rMutexId);
}

static void _SourceProviderPrivateBufDeInit(SP_PRIVATE_BUF_T *prMgr)
{
    if (prMgr->rAdmID != NULL)
    {
        _SourceProviderTakeMutex(prMgr->rMutex);
        kal_adm_delete(prMgr->rAdmID);
        _SourceProviderGiveMutex(prMgr->rMutex);
    }
}

static void* _SourceProviderPrivateBufGetBuf(SP_PRIVATE_BUF_T *prMgr, kal_uint32 u4RequiredSize)
{
    void *pvAddress;
    
    _SourceProviderTakeMutex(prMgr->rMutex);
    pvAddress = kal_adm_alloc_noncacheable(prMgr->rAdmID, u4RequiredSize, SP_CPU_CACHE_LINE_SIZE);
    _SourceProviderGiveMutex(prMgr->rMutex);

    return pvAddress;
}

static SP_ERROR_TYPE_T _SourceProviderPrivateBufReleaseBuf(SP_PRIVATE_BUF_T *prMgr, void* pvAddress)
{
    _SourceProviderTakeMutex(prMgr->rMutex);
    kal_adm_free(prMgr->rAdmID, pvAddress);
    _SourceProviderGiveMutex(prMgr->rMutex);

    return SOURCE_PROVIDER_ERROR_NONE;
}

static kal_uint32 _SourceProviderPrivateBufLeftSize(SP_PRIVATE_BUF_T *prMgr)
{
    kal_uint32 u4Size = 0;
    if (prMgr->rAdmID != NULL)   
    {  
        _SourceProviderTakeMutex(prMgr->rMutex);
        u4Size = kal_adm_get_total_left_size(prMgr->rAdmID);        
        _SourceProviderGiveMutex(prMgr->rMutex);
    }
    return u4Size;
}

static void _SourceProviderFreeStreamBuf(SP_MEM_INFO_T *prMemInfo, SP_MED_HANDLE_T *prMedHandle, SP_PORT_TYPE_T eType)
{
    MPL_SESSION_MEM_API_T *prMedAPI = prMedHandle->prAPI;
    void *pvTemp;
    
    pvTemp = prMemInfo->pvBufHeader[eType];
    if(pvTemp != NULL)
    {
        _SourceProviderBufferHeaderDeInit(&prMemInfo->rBufHeader[eType]);
        prMedAPI->pMemFree(prMedHandle->pvHandle, pvTemp, MED_MEM_NONCACHE);
        prMemInfo->pvBufHeader[eType] = NULL;
    }

    pvTemp = prMemInfo->pvPrivateData[eType];
    if(pvTemp != NULL)
    {
        _SourceProviderPrivateBufDeInit(&prMemInfo->rPrivateData[eType]);
        prMedAPI->pMemFree(prMedHandle->pvHandle, pvTemp, MED_MEM_NONCACHE);
        prMemInfo->pvPrivateData[eType] = NULL;
    }

    pvTemp = prMemInfo->pvBitstreamBuf[eType];
    if(pvTemp != NULL)
    {
        _SourceProviderBitstreamBufDeInit(&prMemInfo->rBitstreamBuf[eType]);
        prMedAPI->pMemFree(prMedHandle->pvHandle, pvTemp, MED_MEM_NONCACHE);
        prMemInfo->pvBitstreamBuf[eType] = NULL;
    }
}    

static void _SourceProviderResetAllBuf(SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr, SP_PORT_TYPE_T eType)
{
    SP_MEM_INFO_T *prMemInfo = (SP_MEM_INFO_T *) &prSrcProviderMgr->rMemInfo;

    if(prSrcProviderMgr->eTrack & SOURCE_PROVIDER_TRACK_META)
    {
        // Meta case doesn't allocate memory
        ASSERT(0); 
    }

    if (prSrcProviderMgr->rStreamInfo[eType].fgSupport == KAL_TRUE)
    {
        // reset private data
        _SourceProviderPrivateBufDeInit(&prMemInfo->rPrivateData[eType]);   
        _SourceProviderBitstreamBufReset(&prMemInfo->rBitstreamBuf[eType]);
        _SourceProviderBufferHeaderReset(&prMemInfo->rBufHeader[eType]);

        if (eType == SOURCE_PROVIDER_PORT_VIDEO)
        {
                        #ifdef __VE_STREAM_SUPPORT__
            if (prSrcProviderMgr->rSrcInfo.eOpenType == MED_MODE_STREAM)
            {
                _SourceProviderPrivateBufinit(&prMemInfo->rPrivateData[eType], 
                                              prMemInfo->pvPrivateData[eType], 
                                              SOURCE_PROVIDER_STREAMING_V_PRIVATE_DATA_SIZE, 
                                              prSrcProviderMgr->rSrcVPrivateDataMutex);
            }
            else
            #endif
            {
                _SourceProviderPrivateBufinit(&prMemInfo->rPrivateData[eType], 
                                              prMemInfo->pvPrivateData[eType], 
                                              SOURCE_PROVIDER_V_PRIVATE_DATA_SIZE, 
                                              prSrcProviderMgr->rSrcVPrivateDataMutex);
            } 


            // Reset VFC Frame Record
            {
                kal_bool fgResetAll = KAL_TRUE;
                VFC_IOCtrl(VFC_OP_SRC_FRAME_REMOVED, NULL, NULL, (void*)&fgResetAll);
            }           
        }
        #ifdef __VE_SUBTITLE_SUPPORT__
        else if (eType == SOURCE_PROVIDER_PORT_SUBTITLE)
        {
            _SourceProviderPrivateBufinit(&prMemInfo->rPrivateData[eType], 
                                              prMemInfo->pvPrivateData[eType], 
                                              SOURCE_PROVIDER_S_PRIVATE_DATA_SIZE, 
                                              NULL);
        }
        #endif
    }

}

static SP_ERROR_TYPE_T _SourceProviderPartialInit(SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr)
{
    //SP_MEM_INFO_T *prMemInfo = (SP_MEM_INFO_T *) &prSrcProviderMgr->rMemInfo;
    kal_uint32 u4I;

    kal_mem_set((void *)&prSrcProviderMgr->rPlayInfo, 0, sizeof(SP_PLAYBACK_INFO_T));
//    prSrcProviderMgr->rPlayInfo.u1Track[SOURCE_PROVIDER_PORT_VIDEO] = SP_TRACK_DEFAULT;
//    prSrcProviderMgr->rPlayInfo.u1Track[SOURCE_PROVIDER_PORT_AUDIO] = SP_TRACK_DEFAULT;
//#ifdef __VE_SUBTITLE_SUPPORT__
//    prSrcProviderMgr->rPlayInfo.u1Track[SOURCE_PROVIDER_PORT_SUBTITLE] = SP_TRACK_DEFAULT;
//#endif

    prSrcProviderMgr->rControlInfo.fgWaitClose = KAL_FALSE;

#ifdef __VE_SP_DBG__
    kal_mem_set((void *)&prSrcProviderMgr->rDebugInfo, 0, sizeof(SP_DEBUG_INFO_T));
#endif

    // memory
    for(u4I=0; u4I<SOURCE_PROVIDER_PORT_MAX; u4I++)
    {
        prSrcProviderMgr->rPlayInfo.u1Track[u4I] = SP_TRACK_DEFAULT;
        _SourceProviderResetAllBuf(prSrcProviderMgr, (SP_PORT_TYPE_T)u4I);
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
    }

    return SOURCE_PROVIDER_ERROR_NONE;
}

static SP_ERROR_TYPE_T _SourceProviderPartialDeInit(SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr)
{
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
#endif
    return SOURCE_PROVIDER_ERROR_NONE;
}

static void _SourceProviderSendMessage(module_type eDstModId, kal_uint32 u4Message, void *prHandle, kal_uint32 u4Param1)
{
    SP_IND_T *prMsg = NULL;
    ilm_struct *prIlm = NULL;
    module_type eActiveModuleId = stack_get_active_module_id();

    prMsg = (SP_IND_T*) construct_local_para(sizeof(SP_IND_T), TD_CTRL);
    prMsg->prHandle = prHandle;
    prMsg->u4Param1 = u4Param1;

    prIlm = allocate_ilm(eActiveModuleId);
    prIlm->src_mod_id = eActiveModuleId;

    prIlm->dest_mod_id = eDstModId;
    prIlm->sap_id = INVALID_SAP;

    prIlm->msg_id = (msg_type) u4Message;
    prIlm->local_para_ptr = (local_para_struct*) prMsg;
    prIlm->peer_buff_ptr = NULL;

#ifdef __VE_SP_PROFILE__
    _prSrcProviderMgr->rProfile.u4Tirgger[u4Param1]++;
#endif

#ifdef __VE_SP_LOG_HIGH__
    drv_trace4(SP_TRACE_HIGH_GROUP, SP_SEND_MSG, u4Param1, eDstModId, u4Message, (kal_uint32)prHandle);
#endif

    msg_send_ext_queue(prIlm);
}

static void _SourceProviderTriggerTask(SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr, kal_bool fgCompClosing, SP_MESSAGE_T eMessage)
{
    SP_TASK_INFO_T *prTaskInfo = &prSrcProviderMgr->rTaskInfo;
    kal_bool fgSendMsg = KAL_FALSE;

    fgSendMsg = VideoCommSetProcessingNew(&prSrcProviderMgr->rCommState, fgCompClosing);

    if (fgSendMsg == KAL_TRUE)
    {
        _SourceProviderSendMessage(prTaskInfo->eRunTask, prTaskInfo->u4TaskMessageID, (void *)prSrcProviderMgr, eMessage);
    }
}

static void _SourceProviderWakeUp(void *pParam)
{
    _SourceProviderTriggerTask((SRC_PRIVDER_CONTEXT_T *)pParam, KAL_FALSE, SOURCE_PROVIDER_MSG_WAKEUP);   
}


static void _SourceProviderSendCallback(SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr, VIDEO_EVENT_TYPE_T eEvent, kal_uint32 u4Data, kal_uint32 u4Line)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

#ifdef __VE_SP_LOG_HIGH__
    drv_trace4(SP_TRACE_HIGH_GROUP, SP_CALLBACK, eEvent, u4Data, u4Line, eError);
#endif

    eError = prSrcProviderMgr->rCommState.prCallback->pfnMIEventHandler(prSrcProviderMgr->rMedHandle.pvHandle, eEvent, VIDEO_COMMAND_NOTIFY, u4Data, NULL);

    if (eError != VIDEO_ERROR_NONE)
    {
        ASSERT(0);
    }
}

#if (defined(__VE_SP_SEEK_SPEED_UP__) || defined(__VE_SP_STREAM_JUMP__))
static void _SourceProviderFlushBufferHeader(SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr, SP_PORT_TYPE_T ePort, kal_uint64 u8FlushTime)
{
    SP_MEM_INFO_T *prMemInfo = (SP_MEM_INFO_T *) &prSrcProviderMgr->rMemInfo;
    SP_BUFFER_HEADER_T *prBufHeaderMgr = &prMemInfo->rBufHeader[ePort];
    VIDEO_BUFFERHEADER_TYPE_T *prBufHeader;
    kal_uint64 u8ProcessTime;
    kal_bool fgKeyFrame;

    // reset resend pointer
    _SourceProviderBufferHeaderSetSendBuf(prBufHeaderMgr, KAL_FALSE);
    
    while (1)
    {
        prBufHeader = (VIDEO_BUFFERHEADER_TYPE_T *)_SourceProviderBufferHeaderGetReadBuf(prBufHeaderMgr);
        u8ProcessTime = prBufHeader->u8TimeStamp/1000;
        fgKeyFrame = (NULL == ((kal_uint32)(prBufHeader->eFlags) & (kal_uint32)(VIDEO_BUFFERFLAG_SYNCFRAME)))?(KAL_FALSE):(KAL_TRUE);

        if ((u8ProcessTime >= u8FlushTime) && fgKeyFrame == KAL_TRUE)
        {
            break;
        }

        // release bitstream buffer
        if (prBufHeader->pu1Buffer != NULL)
        {
            _SourceProviderBitstreamBufReleaseBuf(&prMemInfo->rBitstreamBuf[ePort],
                                                                               (kal_uint32)prBufHeader->pu1Buffer, prBufHeader->u4BuffSize);
        }
        
        // release private data
        if ((ePort == SOURCE_PROVIDER_PORT_VIDEO
            #ifdef __VE_SUBTITLE_SUPPORT__
            || ePort == SOURCE_PROVIDER_PORT_SUBTITLE
            #endif
            ) && prBufHeader->pPrivateData != NULL)
        {
            _SourceProviderPrivateBufReleaseBuf(&prMemInfo->rPrivateData[ePort], prBufHeader->pPrivateData);
        }
        
        // release buffer header
        _SourceProviderBufferHeaderAddReadBuf(prBufHeaderMgr, fgKeyFrame, u8ProcessTime);
    }

    _SourceProviderBufferHeaderSetSendBuf(prBufHeaderMgr, KAL_TRUE);
}
#endif

static void _SourceProviderSetAbortParam(SP_PLAYBACK_INFO_T *prPlayInfo,
                                                              PROVIDER_API_T *prProviderAPI, 
                                                              void *pvProviderHandle, 
                                                              SP_PORT_TYPE_T ePortType, 
                                                              kal_bool fgEnable)
{
    SPIF_ABORT_INFO_T rAbortInfo;

    prPlayInfo->fgAbort[ePortType] = fgEnable;
 
    if (prProviderAPI != NULL)
    {
        rAbortInfo.eType = ePortType;
        rAbortInfo.fgEnable = fgEnable; 
        prProviderAPI->PFN_SET_PARAMETER(pvProviderHandle, PROVIDER_PARAM_ABORT_PROCESS, &rAbortInfo);
    }
}

static SP_ERROR_TYPE_T _SourceProviderProcessFlag(SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr)
{
    SP_PLAYBACK_INFO_T *prPlayInfo = &prSrcProviderMgr->rPlayInfo;
    VIDEO_COMM_STATE_T *prCommState = &prSrcProviderMgr->rCommState;
    SPIF_PROVIDER_HANDLE_T *prPrvHandle = &prSrcProviderMgr->rPrvHandle;
    #if (defined(__VE_SP_SEEK_SPEED_UP__) || defined(__VE_SP_STREAM_JUMP__))    
    SP_MEM_INFO_T *prMemInfo = (SP_MEM_INFO_T *) &prSrcProviderMgr->rMemInfo;    
    #endif
    #ifdef __VE_STREAM_SUPPORT__
    SP_SOURCE_INFO_T *prSrcInfo = &prSrcProviderMgr->rSrcInfo;
    #endif
    SP_CONTROL_FLAG_T *prControlFlag = &prPlayInfo->u4ControlFlag[0];
    kal_uint32 u4I;
    kal_bool fgOk;
    PROVIDER_ERROR_T ePrvRet;

    for (u4I=0; u4I<SOURCE_PROVIDER_PORT_MAX; u4I++)
    {
        if (prControlFlag[u4I] != 0)
        {
            if (prControlFlag[u4I]&SOURCE_PROVIDER_FLAG_OUTPUT_PORT)
            {
                fgOk = KAL_TRUE;
                prPlayInfo->fgSelect[u4I] = (prPlayInfo->fgSelect[u4I] == KAL_TRUE)?(KAL_FALSE):(KAL_TRUE);

                prControlFlag[u4I] &= (~SOURCE_PROVIDER_FLAG_OUTPUT_PORT);
                _SourceProviderSendCallback(prSrcProviderMgr, VIDEO_EVENT_SET_PORT, (kal_uint32)fgOk, __LINE__);
            }

            if (prControlFlag[u4I]&SOURCE_PROVIDER_FLAG_SEEK_TIME)
            {
                SPIF_SEEK_TIME_T *prSeekTime = (SPIF_SEEK_TIME_T *)prPlayInfo->pvControlData[u4I];
                kal_bool fgUpdateFlag = KAL_TRUE;
                fgOk = KAL_TRUE;

                prPlayInfo->u8StartTime[u4I] = prSeekTime->u8StartTime;
                prPlayInfo->u8EndTime[u4I] = prSeekTime->u8EndTime;   

                if (prSeekTime->fgOnlyUpdateTime == KAL_TRUE)
                {
                     kal_uint64 u8TrackEndTime = 0;
                     
                     if (prPlayInfo->fgEof[u4I] == KAL_TRUE)
                     {
                         fgUpdateFlag = KAL_FALSE;
                     }                    

                     if (u4I == SOURCE_PROVIDER_PORT_AUDIO)
                     {
                         u8TrackEndTime = prPlayInfo->prAudioStreamInfo->u8Duration;
                     }
                     else if (u4I == SOURCE_PROVIDER_PORT_VIDEO)
                     {
                         u8TrackEndTime = prPlayInfo->prVideoStreamInfo->u8Duration;
                     }
                     #ifdef __VE_SUBTITLE_SUPPORT__
                     else if (u4I == SOURCE_PROVIDER_PORT_SUBTITLE)
                     {
                         u8TrackEndTime = prPlayInfo->prSubtitleStreamInfo->u8Duration;
                     }
                     #endif

                     if (prPlayInfo->fgParserError[u4I] == KAL_TRUE || prSeekTime->u8StartTime > u8TrackEndTime)
                     {
                         SP_TRACE_PARAMETER_ERROR(prPlayInfo->fgParserError[u4I], u4I, u8TrackEndTime);
                         fgOk = KAL_FALSE;
                     }                                       

                     #ifdef __VE_SP_LOG_HIGH__
                     drv_trace8(SP_TRACE_HIGH_GROUP, SP_SET_SEEK_TIME, u4I, prSeekTime->u8StartTime, prSeekTime->u8EndTime, prSeekTime->fgEndTimeSendEof, prSeekTime->fgOnlyUpdateTime, 
                                                                                                                         0, 0, 0);
                      #endif
                }
                else
                {
                    #if (defined(__VE_SP_SEEK_SPEED_UP__) || defined(__VE_SP_STREAM_JUMP__))
                    SPIF_KEY_FRAME_TIME_T rKeyFrameTime;
             
                    rKeyFrameTime.u8StartTime = prSeekTime->u8StartTime;
                    rKeyFrameTime.ePort = (SP_PORT_TYPE_T)u4I;
                    rKeyFrameTime.eDirect = SOURCE_PROVIDER_SEARCH_BACKWARD;
                    #endif

                    #ifdef __VE_STREAM_SUPPORT__
                    if (prSrcInfo->eOpenType == MED_MODE_STREAM)
                    {
                        #ifdef __VE_SP_STREAM_JUMP__
                        fgOk = _SourceProviderBufferHeaderMaxKeyTime(&prMemInfo->rBufHeader[u4I],prSeekTime->u8StartTime, &rKeyFrameTime.u8KeyFrameTime);
                        #ifdef __VE_SP_LOG_HIGH__
                        drv_trace8(SP_TRACE_HIGH_GROUP, SP_SET_SEEK_TIME, u4I, prSeekTime->u8StartTime, prSeekTime->u8EndTime, prSeekTime->fgEndTimeSendEof, prSeekTime->fgOnlyUpdateTime, 
                                                                                  rKeyFrameTime.u8KeyFrameTime, prMemInfo->rBufHeader[u4I].u8MaxTime, prMemInfo->rBufHeader[u4I].u8MinTime);
                        #endif
                        if (fgOk == KAL_TRUE)
                        {
                            _SourceProviderFlushBufferHeader(prSrcProviderMgr, (SP_PORT_TYPE_T)u4I, rKeyFrameTime.u8KeyFrameTime);
                        }
                        #else
                        fgOk = KAL_FALSE;
                        #endif //__VE_SP_STREAM_JUMP__
                    }
                    else
                    #endif
                    {                     
                        // get key frame time
                        #ifdef __VE_SP_SEEK_SPEED_UP__ 
                        ePrvRet = prPrvHandle->prAPI->PFN_GET_PARAMETER(prPrvHandle->pvHandle, PROVIDER_PARAM_KEY_FRAME_TIME, (void *)&rKeyFrameTime);
                        if (PROVIDER_ERROR_NONE != ePrvRet)
                        {
                            fgOk = KAL_FALSE;
                            SP_TRACE_PRV_FUNCTION_ERROR(ePrvRet, PROVIDER_PARAM_SEEK_TIME, (kal_uint32)prSrcProviderMgr);
                        }
                        else
                        #endif
                        {          
                            #ifdef __VE_SP_SEEK_SPEED_UP__
                            kal_bool fgSpeedUp = KAL_TRUE;
                            #endif
                            
                            #ifdef __VE_SP_LOG_HIGH__
                            #ifdef __VE_SP_SEEK_SPEED_UP__
                            drv_trace8(SP_TRACE_HIGH_GROUP, SP_SET_SEEK_TIME, u4I, prSeekTime->u8StartTime, prSeekTime->u8EndTime, prSeekTime->fgEndTimeSendEof, prSeekTime->fgOnlyUpdateTime, 
                                                                                                                         rKeyFrameTime.u8KeyFrameTime, prMemInfo->rBufHeader[u4I].u8MaxTime, prMemInfo->rBufHeader[u4I].u8MinTime);
                            #else
                            drv_trace8(SP_TRACE_HIGH_GROUP, SP_SET_SEEK_TIME, u4I, prSeekTime->u8StartTime, prSeekTime->u8EndTime, prSeekTime->fgEndTimeSendEof, prSeekTime->fgOnlyUpdateTime, 
                                                                                                                         0, 0, 0);
                            #endif
                            #endif
                        
                            // check in buffer or not
                            #ifdef __VE_SP_SEEK_SPEED_UP__
                            if (u4I == SOURCE_PROVIDER_PORT_AUDIO)
                            {
                                SPIF_PROVIDER_HEADER_INFO_T rHeaderInfo = {SOURCE_PROVIDER_PORT_AUDIO, KAL_FALSE};
                                prPrvHandle->prAPI->PFN_GET_PARAMETER(prPrvHandle->pvHandle, PROVIDER_PARAM_HEADER_INFO, &rHeaderInfo);
                                fgSpeedUp = (kal_bool)(rHeaderInfo.fgHeader == KAL_FALSE); 
                            }                        
                        
                            if (_SourceProviderBufferHeaderTimeInBuff(&prMemInfo->rBufHeader[u4I], rKeyFrameTime.u8KeyFrameTime) == KAL_TRUE &&
                                fgSpeedUp == KAL_TRUE)
                            {
                                _SourceProviderFlushBufferHeader(prSrcProviderMgr, (SP_PORT_TYPE_T)u4I, rKeyFrameTime.u8KeyFrameTime);
                            
                                if (prPlayInfo->fgEof[u4I] == KAL_TRUE)
                                {
                                    fgUpdateFlag = KAL_FALSE;
                                }
                            }
                            else
                            #endif
                            {                                                    
                                // reset error status       
                                prSrcProviderMgr->rPlayInfo.fgParserError[u4I] = KAL_FALSE;                                          
                            
                                ePrvRet = prPrvHandle->prAPI->PFN_SET_PARAMETER(prPrvHandle->pvHandle, PROVIDER_PARAM_SEEK_TIME, prPlayInfo->pvControlData[u4I]);
                                if (PROVIDER_ERROR_NONE != ePrvRet)
                                {
                                    fgOk = KAL_FALSE;
                                    SP_TRACE_PRV_FUNCTION_ERROR(ePrvRet, PROVIDER_PARAM_SEEK_TIME, (kal_uint32)prSrcProviderMgr);
                                }

                                // make sure 1. don't process bitstream 2. output queue empty
                                // flush bitstream related buffer
                                _SourceProviderResetAllBuf(prSrcProviderMgr, (SP_PORT_TYPE_T)u4I);
                            
                                if (u4I == SOURCE_PROVIDER_PORT_AUDIO)
                                {
                                    if (prSrcProviderMgr->rPlayInfo.u1Track[SOURCE_PROVIDER_PORT_AUDIO] != SP_TRACK_DEFAULT)
                                    {
                                        SPIF_SNED_HEADER_T rSendHeader;
						                    
                                        kal_mem_set((void *)&rSendHeader, 0, sizeof(SPIF_SNED_HEADER_T));
                                        rSendHeader.fgAudio = KAL_TRUE;
						
                                        ePrvRet = prPrvHandle->prAPI->PFN_SET_PARAMETER(prPrvHandle->pvHandle, PROVIDER_PARAM_SEND_HEADER, (void *)&rSendHeader);
                                        if (ePrvRet != PROVIDER_ERROR_NONE)
                                        {
                                            SP_TRACE_PRV_FUNCTION_ERROR(ePrvRet, 0, (kal_uint32)prSrcProviderMgr);
                                            fgOk = KAL_FALSE;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    // output queue empty
                    VideoCommClrQ(&prCommState->rOutputBuffQ[u4I]);
                }

                if (fgUpdateFlag == KAL_TRUE)
                {
	                prPlayInfo->fgEof[u4I] = KAL_FALSE;
	              }
	                prPlayInfo->fgSeekDone[u4I] = KAL_FALSE;  

                prControlFlag[u4I] &= (~SOURCE_PROVIDER_FLAG_SEEK_TIME);
                prPlayInfo->pvControlData[u4I] = NULL;
           
                _SourceProviderSendCallback(prSrcProviderMgr, VIDEO_EVENT_SEEK_TIME, (kal_uint32)fgOk, __LINE__);
                
                if (fgOk == KAL_FALSE)
                {
                    prSrcProviderMgr->rPlayInfo.fgParserError[u4I] = KAL_TRUE;
                    return SOURCE_PROVIDER_ERROR;
                }
            }

            if (prControlFlag[u4I] & SOURCE_PROVIDER_FLAG_GET_KEY_FRAME_TIME)
            {
                fgOk = KAL_TRUE;

                #ifdef __VE_STREAM_SUPPORT__
                if (prSrcInfo->eOpenType == MED_MODE_STREAM)
                {
                    #ifdef __VE_SP_STREAM_JUMP__
                    SPIF_KEY_FRAME_TIME_T *prKeyFrameTime = (SPIF_KEY_FRAME_TIME_T *)prPlayInfo->pvControlData[u4I];
                    fgOk = _SourceProviderBufferHeaderMaxKeyTime(&prMemInfo->rBufHeader[u4I],prKeyFrameTime->u8StartTime, &prKeyFrameTime->u8KeyFrameTime);
                    #else
                    fgOk = KAL_FALSE;
                    #endif
                }
                else
                #endif
                {
                    ePrvRet = prPrvHandle->prAPI->PFN_GET_PARAMETER(prPrvHandle->pvHandle, PROVIDER_PARAM_KEY_FRAME_TIME, prPlayInfo->pvControlData[u4I]);
                    if (PROVIDER_ERROR_NONE != ePrvRet)
                    {
                        fgOk = KAL_FALSE;
                        SP_TRACE_PRV_FUNCTION_ERROR(ePrvRet, PROVIDER_PARAM_KEY_FRAME_TIME, (kal_uint32)prSrcProviderMgr);
                    }
                }

                prControlFlag[u4I] &= (~SOURCE_PROVIDER_FLAG_GET_KEY_FRAME_TIME);
                prPlayInfo->pvControlData[u4I] = NULL;
           
                _SourceProviderSendCallback(prSrcProviderMgr, VIDEO_EVENT_GET_KEY_FRAME_TIME, (kal_uint32)fgOk, __LINE__);                             
                
                if (fgOk == KAL_FALSE 
                    #ifdef __VE_STREAM_SUPPORT__
                    && (prSrcInfo->eOpenType != MED_MODE_STREAM)
                    #endif
                    )
                {
                    return SOURCE_PROVIDER_ERROR;
                }                       
            }

            #ifdef __VE_STREAM_SUPPORT__
            if (prControlFlag[u4I] & SOURCE_PROVIDER_FLAG_FLUSH_STREAM_BUFFER)
            {
                fgOk = KAL_TRUE;
                
                prSrcProviderMgr->rStreamInfo[u4I].fgSupport = KAL_FALSE;
                
                // output queue empty
                VideoCommClrQ(&prCommState->rOutputBuffQ[u4I]);

                _SourceProviderFreeStreamBuf(&prSrcProviderMgr->rMemInfo, &prSrcProviderMgr->rMedHandle, (SP_PORT_TYPE_T)u4I);

                prControlFlag[u4I] &= (~SOURCE_PROVIDER_FLAG_FLUSH_STREAM_BUFFER);
                _SourceProviderSendCallback(prSrcProviderMgr, VIDEO_EVENT_FLUSH_STREAM_BUFFER, (kal_uint32)fgOk, __LINE__);
            }
            #endif

            #ifdef __VE_PGDL_SUPPORT__
            if (prControlFlag[u4I] & SOURCE_PROVIDER_FLAG_QUERY_FRAME_BUF)
            {
                fgOk = KAL_TRUE;

                if(prPrvHandle->prAPI->PFN_GET_PARAMETER(prPrvHandle->pvHandle, PROVIDER_PARAM_QURERY_FRAME_BUF, prPlayInfo->pvControlData[u4I]) != PROVIDER_ERROR_NONE)
                {
                    fgOk = KAL_FALSE;
                }                

                prControlFlag[u4I] &= (~SOURCE_PROVIDER_FLAG_QUERY_FRAME_BUF);
                prPlayInfo->pvControlData[u4I] = NULL;
                
                _SourceProviderSendCallback(prSrcProviderMgr, VIDEO_EVENT_QUERY_FRAME_BUFFER_DONE, (kal_uint32)fgOk, __LINE__);
            }
            #endif
            
        }

        if (prControlFlag[u4I] == 0 && prPlayInfo->fgAbort[u4I] == KAL_TRUE)
        {
            // clear terminate flag
            _SourceProviderSetAbortParam(prPlayInfo, prPrvHandle->prAPI, prPrvHandle->pvHandle, (SP_PORT_TYPE_T)u4I, KAL_FALSE);           
        }
    }

    return SOURCE_PROVIDER_ERROR_NONE;
}

static SP_ERROR_TYPE_T _SourceProviderSendBufferOut(SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr, SP_PORT_TYPE_T ePortType)
{
     //VIDEO_ERROR_TYPE_T (*pfnSourceProviderProcessThisBuffer)(VIDEO_BUFFERHEADER_TYPE_T *);
     SP_PLAYBACK_INFO_T *prPlayInfo = (SP_PLAYBACK_INFO_T *)&prSrcProviderMgr->rPlayInfo;
     SP_BUFFER_HEADER_T *prBufHeader = &prSrcProviderMgr->rMemInfo.rBufHeader[ePortType];
     void *prMedHandle = prSrcProviderMgr->rMedHandle.pvHandle;
     MPL_SESSION_EMPTY_BUFFER_API_T *prEmptyBuffer = prSrcProviderMgr->rMedHandle.prEmptyAPI;
     VIDEO_BUFFERHEADER_TYPE_T *prBufferHeader;
     VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
     SP_ERROR_TYPE_T eRet = SOURCE_PROVIDER_ERROR_NONE;

    prBufferHeader = (VIDEO_BUFFERHEADER_TYPE_T *)_SourceProviderBufferHeaderGetSendBuf(prBufHeader);
    while(prBufferHeader != NULL)
    {
        if (ePortType == SOURCE_PROVIDER_PORT_VIDEO)
        {
            // modify flag
            if (((kal_uint32)(prBufferHeader->eFlags) & (kal_uint32)(VIDEO_BUFFERFLAG_PARAMETERSET)) == NULL)
            {
                if (prPlayInfo->fgSeekDone[SOURCE_PROVIDER_PORT_VIDEO] == KAL_TRUE)
                {
                    prBufferHeader->eFlags |= VIDEO_BUFFERFLAG_NONE;
                }
                else
                {
                    if (prBufferHeader->u8TimeStamp >= (prPlayInfo->u8StartTime[SOURCE_PROVIDER_PORT_VIDEO]*1000))
                    {
                        prBufferHeader->eFlags |= VIDEO_BUFFERFLAG_STARTTIME;
                    }
                    else
                    {
                        prBufferHeader->eFlags |= VIDEO_BUFFERFLAG_DECODEONLY;
                    }
                }
            }
        
            eError = prEmptyBuffer->pVideoEmptyBuffer(prMedHandle, prBufferHeader);
        }
        else if (ePortType == SOURCE_PROVIDER_PORT_AUDIO)
        {
            eError = prEmptyBuffer->pAudioEmptyBuffer(prMedHandle, prBufferHeader);
        }
        #ifdef __VE_SUBTITLE_SUPPORT__
        else if (ePortType == SOURCE_PROVIDER_PORT_SUBTITLE)
        {
            eError = prEmptyBuffer->pSubtitleEmptyBuffer(prMedHandle, prBufferHeader);
        }
        #endif

        if (eError == VIDEO_ERROR_BUFF_FULL)
        {
            return SOURCE_PROVIDER_ERROR_BUF_FULL;
        }
        else
       {
           #ifdef __VE_SP_LOG_HIGH__
           drv_trace4(SP_TRACE_HIGH_GROUP, SP_SEND_OUT, ePortType, (kal_uint32)prBufferHeader, prBufferHeader->u8TimeStamp, (kal_uint32)prSrcProviderMgr);
           #endif
           
           if (prPlayInfo->fgSeekDone[ePortType] == KAL_FALSE)
           {
               if (prBufferHeader->u8TimeStamp >= (prPlayInfo->u8StartTime[ePortType]*1000))
               {
                   prPlayInfo->fgSeekDone[ePortType] = KAL_TRUE;
               }
           }
           
           eRet = _SourceProviderBufferHeaderAddSendBuf(prBufHeader);
           if (eRet != SOURCE_PROVIDER_ERROR_NONE)
           {
               break;
           }
           prBufferHeader = (VIDEO_BUFFERHEADER_TYPE_T *)_SourceProviderBufferHeaderGetSendBuf(prBufHeader);
       }
    }

    return eRet;
}

static SP_ERROR_TYPE_T _SourceProviderStateSetToInit(SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr)
{
     void *pvProviderHandle = prSrcProviderMgr->rPrvHandle.pvHandle;
     PROVIDER_API_T *prProviderAPI = prSrcProviderMgr->rPrvHandle.prAPI;
     SP_MED_HANDLE_T *prMedHandle = &prSrcProviderMgr->rMedHandle;
     SP_MEM_INFO_T *prMemInfo = &prSrcProviderMgr->rMemInfo;
     SP_CONTROL_INFO_T *prControlInfo = &prSrcProviderMgr->rControlInfo;
     SP_SOURCE_INFO_T *prSrcInfo = &prSrcProviderMgr->rSrcInfo;

     SP_ERROR_TYPE_T eRet = SOURCE_PROVIDER_ERROR_NONE;
     PROVIDER_ERROR_T ePrvRet = PROVIDER_ERROR_NONE;
     
#ifdef __VE_STREAM_SUPPORT__
    if (prSrcInfo->eOpenType == MED_MODE_STREAM)
    {
         if (prSrcProviderMgr->eTrack & SOURCE_PROVIDER_TRACK_AUDIO)
         {
             prSrcProviderMgr->rStreamInfo[SOURCE_PROVIDER_PORT_AUDIO].fgSupport = KAL_TRUE;
         }

         if (prSrcProviderMgr->eTrack & SOURCE_PROVIDER_TRACK_VIDEO)
         {
             prSrcProviderMgr->rStreamInfo[SOURCE_PROVIDER_PORT_VIDEO].fgSupport = KAL_TRUE;
         }
    }
    else
#endif
    {
        kal_uint32 u4CoreMemSize = prSrcProviderMgr->rPrvReqMem.u4CoreMem;
        SPIF_PROVIDER_OPEN_INFO_T rOpenInfo;

        // terminate by MED
        if (prControlInfo->fgQuickClose == KAL_TRUE)
        {
            SP_TRACE_PRV_FUNCTION_ERROR(0, 0, (kal_uint32)prSrcProviderMgr);
            return SOURCE_PROVIDER_ERROR_TIMEOUT;
        }

        // obtain core memory and use ADM to management
        prMemInfo->pvSrcPrvAdm = prMedHandle->prAPI->pMemAlloc(prMedHandle->pvHandle, u4CoreMemSize, MED_MEM_NONCACHE);
        if (prMemInfo->pvSrcPrvAdm == NULL)
        {
            SP_TRACE_MEMORY_ERROR(u4CoreMemSize, 0,(kal_uint32)prSrcProviderMgr);
            return SOURCE_PROVIDER_ERROR_MEM_LACK;            
        }
        prMemInfo->rSrcPrvAdmId = kal_adm_create(prMemInfo->pvSrcPrvAdm, u4CoreMemSize, NULL,KAL_TRUE);

        // obtain mapping provider API and handle, and send source handle and function
        if (_SourceProviderObtainProviderHandle(prSrcProviderMgr, (SP_API_T *)&rAPIsForPrv) != SOURCE_PROVIDER_ERROR_NONE)
        {
            eRet = SOURCE_PROVIDER_ERROR;
            goto INIT_ERR_HANDLE_1;
        }

        prProviderAPI = prSrcProviderMgr->rPrvHandle.prAPI;
        pvProviderHandle = prSrcProviderMgr->rPrvHandle.pvHandle;

        // open provider
        rOpenInfo.eOpenTrack = prSrcProviderMgr->eTrack;
        rOpenInfo.eOpenType= prSrcInfo->eOpenType;
        if (rOpenInfo.eOpenType == MED_MODE_BUFFER)
        {
            rOpenInfo.pu1Data = (kal_uint8 *)prSrcInfo->u_src.rBuf.u4Addr;
            rOpenInfo.u4DataSize = prSrcInfo->u_src.rBuf.u4Size;
        }
        else
        {
            rOpenInfo.pu1Data = (kal_uint8 *)&prSrcInfo->u_src.file_name;
            rOpenInfo.u4DataSize = 0;
        }
#ifdef __VE_PGDL_SUPPORT__
        do{
            ePrvRet = prProviderAPI->PFN_OPEN(pvProviderHandle, &rOpenInfo);
            if (ePrvRet == PROVIDER_ERROR_WAIT_DATA)
            {
                kal_sleep_task(SP_DPL_OPEN_SLEEP_TICK);
                if (prControlInfo->fgQuickClose == KAL_TRUE)
                {
                    SP_TRACE_PRV_FUNCTION_ERROR(ePrvRet, 0, (kal_uint32)prSrcProviderMgr);
                    eRet =  SOURCE_PROVIDER_ERROR_TIMEOUT;
                    // Timeout times exceeds or MPL quick close. MP4 provider did not free resources. Need to close it.
                    goto INIT_ERR_HANDLE_2;
                }
            }
            else if (ePrvRet != PROVIDER_ERROR_NONE)
            {
                SP_TRACE_PRV_FUNCTION_ERROR(ePrvRet, 0, (kal_uint32)prSrcProviderMgr);
                eRet =  SOURCE_PROVIDER_ERROR;
                goto INIT_ERR_HANDLE_1;
            }
        } while(ePrvRet != PROVIDER_ERROR_NONE);
#else
        ePrvRet = prProviderAPI->PFN_OPEN(pvProviderHandle, &rOpenInfo);
        if (ePrvRet != PROVIDER_ERROR_NONE)
        {
            SP_TRACE_PRV_FUNCTION_ERROR(ePrvRet, 0, (kal_uint32)prSrcProviderMgr);
            eRet =  SOURCE_PROVIDER_ERROR;
            goto INIT_ERR_HANDLE_1;
        }
#endif
        prControlInfo->fgQuickClose = KAL_FALSE;

        // init provider
        ePrvRet = prProviderAPI->PFN_INIT(pvProviderHandle);
        if (ePrvRet != PROVIDER_ERROR_NONE)
        {
            SP_TRACE_PRV_FUNCTION_ERROR(ePrvRet, 0, (kal_uint32)prSrcProviderMgr);
            eRet =  SOURCE_PROVIDER_ERROR;
            goto INIT_ERR_HANDLE_2;
        }

        // obtain file information
        prProviderAPI->PFN_GET_PARAMETER(pvProviderHandle,
                                                                 PROVIDER_PARAM_VID_STREAM_INFO,
                                                                 (void *)&prSrcProviderMgr->rStreamInfo[SOURCE_PROVIDER_PORT_VIDEO]);
        prProviderAPI->PFN_GET_PARAMETER(pvProviderHandle,
                                                                 PROVIDER_PARAM_AUD_STREAM_INFO,
                                                                 (void *)&prSrcProviderMgr->rStreamInfo[SOURCE_PROVIDER_PORT_AUDIO]);
#ifdef __VE_SUBTITLE_SUPPORT__        
        prProviderAPI->PFN_GET_PARAMETER(pvProviderHandle,
                                                                 PROVIDER_PARAM_SUBS_STREAM_INFO,
                                                                 (void *)&prSrcProviderMgr->rStreamInfo[SOURCE_PROVIDER_PORT_SUBTITLE]);
#endif
        prProviderAPI->PFN_GET_PARAMETER(pvProviderHandle,
                                                                 PROVIDER_PARAM_META_CAPABILITY,
                                                                 (void *)&prSrcProviderMgr->eCapabiltiy);
      
    }

    // obtain parser parameter
    prSrcProviderMgr->prPrvParserParam = _SourceProviderObtainParserParam(prSrcInfo->eFileType);
    if (prSrcProviderMgr->prPrvParserParam == NULL)
    {
        eRet = SOURCE_PROVIDER_ERROR;
        goto INIT_ERR_HANDLE_3;
    }  

    //VideoCommChangeState(&prSrcProviderMgr->rCommState, VIDEO_STATE_INIT);

    return SOURCE_PROVIDER_ERROR_NONE;

INIT_ERR_HANDLE_3:
    // De-init provider
    prProviderAPI->PFN_DE_INIT(pvProviderHandle);

INIT_ERR_HANDLE_2:
    // Close provider
    prProviderAPI->PFN_CLOSE(pvProviderHandle) ;

INIT_ERR_HANDLE_1:
    _SourceProviderReleaseProviderHandle(prSrcProviderMgr);
    prSrcProviderMgr->rPrvHandle.prAPI = NULL;
    prSrcProviderMgr->rPrvHandle.pvHandle = NULL;
    if (prMemInfo->rSrcPrvAdmId != 0)
    {
        kal_adm_delete(prMemInfo->rSrcPrvAdmId);
        prMemInfo->rSrcPrvAdmId = 0;
        prMedHandle->prAPI->pMemFree(prMedHandle->pvHandle, prMemInfo->pvSrcPrvAdm, MED_MEM_NONCACHE);
    }

    return eRet;

}

static SP_ERROR_TYPE_T _SourceProviderStateSetHdlr(SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr, kal_uint32 u4Param)
{
    void *pvProviderHandle = prSrcProviderMgr->rPrvHandle.pvHandle;
    PROVIDER_API_T *prProviderAPI = prSrcProviderMgr->rPrvHandle.prAPI;
    SP_MED_HANDLE_T *prMedHandle = (SP_MED_HANDLE_T *)&prSrcProviderMgr->rMedHandle;
    SP_MEM_INFO_T *prMemInfo = (SP_MEM_INFO_T *) &prSrcProviderMgr->rMemInfo;

    SP_ERROR_TYPE_T eRet = SOURCE_PROVIDER_ERROR_NONE;
    PROVIDER_ERROR_T ePrvRet = PROVIDER_ERROR_NONE;
    VIDEO_STATE_TYPE_T eState;   
    #ifdef __VE_STREAM_SUPPORT__
    med_mode_enum eMode = prSrcProviderMgr->rSrcInfo.eOpenType;
    #endif

    eState = VideoCommGetState(&prSrcProviderMgr->rCommState);

    switch(u4Param)
    {
    case VIDEO_STATE_INIT:
        eRet = _SourceProviderStateSetToInit(prSrcProviderMgr);

        break;

    case VIDEO_STATE_IDLE:
        if ( VIDEO_STATE_STOP == eState)
        {
            #ifdef __VE_STREAM_SUPPORT__
            if (eMode != MED_MODE_STREAM)
            #endif
            {
                // de-init provider
                ePrvRet = prProviderAPI->PFN_DE_INIT(pvProviderHandle);
                if (ePrvRet != PROVIDER_ERROR_NONE)
                {
                    SP_TRACE_PRV_FUNCTION_ERROR(ePrvRet, 0, (kal_uint32)prSrcProviderMgr);
                    eRet = SOURCE_PROVIDER_ERROR;
                    break;
                }
            }

            VideoCommClrAllQ(&prSrcProviderMgr->rCommState);

            if (SOURCE_PROVIDER_ERROR_NONE != _SourceProviderPartialDeInit(prSrcProviderMgr))
            {
                eRet = SOURCE_PROVIDER_ERROR;
                break;
            }

            if ( SOURCE_PROVIDER_ERROR_NONE != _SourceProviderPartialInit(prSrcProviderMgr))
            {
                eRet = SOURCE_PROVIDER_ERROR;
                break;
            }

            #ifdef __VE_STREAM_SUPPORT__
            if (eMode != MED_MODE_STREAM)
            #endif
            {
                // init provider
                ePrvRet = prProviderAPI->PFN_INIT(pvProviderHandle);
                if (ePrvRet != PROVIDER_ERROR_NONE)
                {
                    SP_TRACE_PRV_FUNCTION_ERROR(ePrvRet, 0, (kal_uint32)prSrcProviderMgr);
                    eRet = SOURCE_PROVIDER_ERROR;
                    break;
                }
            }
        }
        else if (VIDEO_STATE_INIT == eState)
        {
            kal_uint32 u4I;
            kal_uint32 u4BufLen = 0, u4PrivateSize = 0, u4BitstreamSize = 0;
            kal_mutexid rHeaderMutex = NULL, rBitstreamMutex = NULL, rPrivateMutex = NULL;
            MPL_SESSION_MEM_API_T *prMedAPI = prMedHandle->prAPI;

            if (prSrcProviderMgr->eTrack & SOURCE_PROVIDER_TRACK_META)
            {
                SP_TRACE_PARAMETER_ERROR(prSrcProviderMgr->eTrack, 0, (kal_uint32)prSrcProviderMgr);
                eRet = SOURCE_PROVIDER_ERROR;
                break;
            }

            // allocate video/aduio memory
            for(u4I=0; u4I<SOURCE_PROVIDER_PORT_MAX; u4I++)
            {
                if (prSrcProviderMgr->rStreamInfo[u4I].fgSupport == KAL_TRUE)
                {
                    // Help to do:
                    // checking
                    if (u4I == SOURCE_PROVIDER_PORT_AUDIO)
                    {
                        if (!(prSrcProviderMgr->eTrack & SOURCE_PROVIDER_TRACK_AUDIO))
                        {
                            SP_TRACE_PARAMETER_ERROR(prSrcProviderMgr->eTrack, 0, (kal_uint32)prSrcProviderMgr);
                            eRet = SOURCE_PROVIDER_ERROR;
                            break;
                        }

                        #ifdef __VE_STREAM_SUPPORT__
                        if (eMode == MED_MODE_STREAM)
                        {
                            u4BufLen = SOURCE_PROVIDER_STREAMING_A_BUF_HEADER_LEN;
                            u4PrivateSize = SOURCE_PROVIDER_STREAMING_A_PRIVATE_DATA_SIZE;
                        }                        
                        else
                        #endif
                        {
                            u4BufLen = SOURCE_PROVIDER_A_BUF_HEADER_LEN;
                            u4PrivateSize = SOURCE_PROVIDER_A_PRIVATE_DATA_SIZE;
                        }
                        
                        rHeaderMutex = prSrcProviderMgr->rSrcABufHeaderMutex;   
                        rBitstreamMutex = prSrcProviderMgr->rSrcABitstreamMutex;
                        rPrivateMutex = NULL;
                        u4BitstreamSize = prSrcProviderMgr->rPrvReqMem.u4AudioMem;
                    }
                    else if (u4I == SOURCE_PROVIDER_PORT_VIDEO)
                    {
                        if (!(prSrcProviderMgr->eTrack & SOURCE_PROVIDER_TRACK_VIDEO))
                        {
                            SP_TRACE_PARAMETER_ERROR(prSrcProviderMgr->eTrack, 0, (kal_uint32)prSrcProviderMgr);
                            eRet = SOURCE_PROVIDER_ERROR;
                            break;
                        }

                        #ifdef __VE_STREAM_SUPPORT__
                        if (eMode == MED_MODE_STREAM)
                        {
                            u4BufLen = SOURCE_PROVIDER_STREAMING_V_BUF_HEADER_LEN;
                            u4PrivateSize = SOURCE_PROVIDER_STREAMING_V_PRIVATE_DATA_SIZE;
                        }                        
                        else
                        #endif
                        {
                            u4BufLen = SOURCE_PROVIDER_V_BUF_HEADER_LEN;
                            u4PrivateSize = SOURCE_PROVIDER_V_PRIVATE_DATA_SIZE;
                        }
                        
                        rHeaderMutex = prSrcProviderMgr->rSrcVBufHeaderMutex;                        
                        rBitstreamMutex = prSrcProviderMgr->rSrcVBitstreamMutex;
                        rPrivateMutex = prSrcProviderMgr->rSrcVPrivateDataMutex;
                        u4BitstreamSize = prSrcProviderMgr->rPrvReqMem.u4VideoMem;
                    }
                    #ifdef __VE_SUBTITLE_SUPPORT__
                    else if (u4I == SOURCE_PROVIDER_PORT_SUBTITLE)
                    {
                        if (!(prSrcProviderMgr->eTrack & SOURCE_PROVIDER_TRACK_SUBTITLE))
                        {
                            SP_TRACE_PARAMETER_ERROR(prSrcProviderMgr->eTrack, 0, (kal_uint32)prSrcProviderMgr);
                            eRet = SOURCE_PROVIDER_ERROR;
                            break;
                        }

                        u4BufLen = SOURCE_PROVIDER_S_BUF_HEADER_LEN;
                        u4PrivateSize = SOURCE_PROVIDER_S_PRIVATE_DATA_SIZE;

                        rHeaderMutex = NULL;
                        rBitstreamMutex = NULL;
                        rPrivateMutex = NULL;
                        u4BitstreamSize = prSrcProviderMgr->rPrvReqMem.u4SubtitleMem;
                    }
                    #endif

                    // obtain memory
                    prMemInfo->pvBufHeader[u4I] = prMedAPI->pMemAlloc(prMedHandle->pvHandle,
                                                                                                                      (u4BufLen*SOURCE_PROVIDER_BUFFERHEADER_SIZE),
                                                                                                                      MED_MEM_NONCACHE);
                    if (prMemInfo->pvBufHeader[u4I] == NULL)
                    {
                        SP_TRACE_MEMORY_ERROR((u4BufLen*SOURCE_PROVIDER_BUFFERHEADER_SIZE), u4I,(kal_uint32)prSrcProviderMgr);
                        eRet = SOURCE_PROVIDER_ERROR_MEM_LACK;
                        break;
                    }
                    
                    // initize buffer header
                    _SourceProviderBufferHeaderInit(&prMemInfo->rBufHeader[u4I], prMemInfo->pvBufHeader[u4I] ,
                                                                            u4BufLen, SOURCE_PROVIDER_BUFFERHEADER_SIZE,
                                                                            rHeaderMutex);

                    // initize private data
                    if (u4PrivateSize != 0)
                    {
                        prMemInfo->pvPrivateData[u4I] = prMedAPI->pMemAlloc(prMedHandle->pvHandle,
                                                                                                                       u4PrivateSize,
                                                                                                                       MED_MEM_NONCACHE);
                        if (prMemInfo->pvPrivateData[u4I] == NULL)
                        {
                            SP_TRACE_MEMORY_ERROR(u4PrivateSize, u4I,(kal_uint32)prSrcProviderMgr);
                            eRet = SOURCE_PROVIDER_ERROR_MEM_LACK;
                            break;
                        }
                        _SourceProviderPrivateBufinit(&prMemInfo->rPrivateData[u4I], prMemInfo->pvPrivateData[u4I], u4PrivateSize, rPrivateMutex);
                    }

                    // initize bitstream buffer
                    prMemInfo->pvBitstreamBuf[u4I] = prMedAPI->pMemAlloc(prMedHandle->pvHandle,
                                                                                                                         u4BitstreamSize,
                                                                                                                         MED_MEM_NONCACHE);
                    if (prMemInfo->pvBitstreamBuf[u4I] == NULL)
                    {
                        SP_TRACE_MEMORY_ERROR(u4BitstreamSize, u4I,(kal_uint32)prSrcProviderMgr);
                        eRet = SOURCE_PROVIDER_ERROR_MEM_LACK;
                        break;
                    }
                    _SourceProviderBitstreamBufInit(&prMemInfo->rBitstreamBuf[u4I],
                                                                           (kal_uint32)prMemInfo->pvBitstreamBuf[u4I],
                                                                           u4BitstreamSize,
                                                                           rBitstreamMutex);  // help
                    #ifdef __VE_SP_PROFILE__
                    {       
                        SP_PROFILE_INFO_T *prProfile = &prSrcProviderMgr->rProfile;                 
                        prProfile->u4MixLeftBitstream[u4I] = _SourceProviderBitstreamBufTotalLeftSize(&(prMemInfo->rBitstreamBuf[u4I]));
                        prProfile->u4MixLeftHeader[u4I] = _SourceProviderBufferHeaderFreeNum(&prMemInfo->rBufHeader[u4I]);                        
                        prProfile->u4MixLeftPrivate[u4I] = _SourceProviderPrivateBufLeftSize(&prMemInfo->rPrivateData[u4I]);
                    }
                    #endif                                                                                 
                }
            }

            if (eRet == SOURCE_PROVIDER_ERROR_NONE)
            {
                if ( SOURCE_PROVIDER_ERROR_NONE != _SourceProviderPartialInit(prSrcProviderMgr))
                {
                    eRet = SOURCE_PROVIDER_ERROR;
                    break;
                }
            }
        }

        //VideoCommChangeState(&prSrcProviderMgr->rCommState, VIDEO_STATE_IDLE);
        break;

    case VIDEO_STATE_RUN:
        if ( VIDEO_STATE_IDLE == eState)
        {
            #ifdef __VE_STREAM_SUPPORT__
            if (eMode != MED_MODE_STREAM)            
            #endif
            {
                SP_PLAYBACK_INFO_T *prPlayInfo = (SP_PLAYBACK_INFO_T *)&prSrcProviderMgr->rPlayInfo;
                if ((prPlayInfo->u1Track[SOURCE_PROVIDER_PORT_VIDEO] != SP_TRACK_DEFAULT)
                    #ifdef __VE_SUBTITLE_SUPPORT__
                    || (prPlayInfo->u1Track[SOURCE_PROVIDER_PORT_SUBTITLE] != SP_TRACK_DEFAULT)
                    #endif
                    )
                {
                    SPIF_SNED_HEADER_T rSendHeader;
                    rSendHeader.fgVideo = (prPlayInfo->u1Track[SOURCE_PROVIDER_PORT_VIDEO] != SP_TRACK_DEFAULT)?(KAL_TRUE):(KAL_FALSE);
                    rSendHeader.fgAudio = KAL_FALSE;
                    #ifdef __VE_SP_SUBTITLE__
                    rSendHeader.fgSubtitle = (prPlayInfo->u1Track[SOURCE_PROVIDER_PORT_SUBTITLE] != SP_TRACK_DEFAULT)?(KAL_TRUE):(KAL_FALSE);
                    #endif

                    ePrvRet = prProviderAPI->PFN_SET_PARAMETER(pvProviderHandle, PROVIDER_PARAM_SEND_HEADER, (void *)&rSendHeader);
                    if (ePrvRet != PROVIDER_ERROR_NONE)
                    {
                        SP_TRACE_PRV_FUNCTION_ERROR(ePrvRet, 0, (kal_uint32)prSrcProviderMgr);
                        eRet = SOURCE_PROVIDER_ERROR;
                        break;
                    }
                }

                // check video/audio start time setting
                #if 0
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
        }

        //VideoCommChangeState(&prSrcProviderMgr->rCommState, VIDEO_STATE_RUN);
        break;

    case VIDEO_STATE_STOP:
        //VideoCommChangeState(&prSrcProviderMgr->rCommState, VIDEO_STATE_STOP);
        break;

    case VIDEO_STATE_CLOSE:
        {
            MPL_SESSION_MEM_API_T *prMedAPI = prMedHandle->prAPI;
            kal_uint32 u4I;

            prSrcProviderMgr->rControlInfo.fgWaitClose = KAL_TRUE;

            // Help to do
            // free video/audio buffer
            for(u4I=0; u4I<SOURCE_PROVIDER_PORT_MAX; u4I++)
            {
                _SourceProviderFreeStreamBuf(prMemInfo, prMedHandle, (SP_PORT_TYPE_T)u4I);
            }

            if (prProviderAPI != NULL && prMedHandle != NULL)
            {
                // De-init provider
                ePrvRet = prProviderAPI->PFN_DE_INIT(pvProviderHandle);
                if (ePrvRet != PROVIDER_ERROR_NONE)
                {
                    SP_TRACE_PRV_FUNCTION_ERROR(ePrvRet, 0, (kal_uint32)prSrcProviderMgr);
                    eRet = SOURCE_PROVIDER_ERROR;
                    break;
                }

                // Close provider
                ePrvRet = prProviderAPI->PFN_CLOSE(pvProviderHandle) ;
                if (ePrvRet != PROVIDER_ERROR_NONE)
                {
                    SP_TRACE_PRV_FUNCTION_ERROR(ePrvRet, 0, (kal_uint32)prSrcProviderMgr);
                    eRet = SOURCE_PROVIDER_ERROR;
                    break;
                }

                if (_SourceProviderReleaseProviderHandle(prSrcProviderMgr) != SOURCE_PROVIDER_ERROR_NONE)
                {
                    eRet = SOURCE_PROVIDER_ERROR;
                    break;
                }

                // free API and handle of provider
                prSrcProviderMgr->rPrvHandle.pvHandle = NULL;
                prSrcProviderMgr->rPrvHandle.prAPI = NULL;
            }

            // free core ADM
            if (prMemInfo->rSrcPrvAdmId != 0)
            {
                kal_adm_delete(prMemInfo->rSrcPrvAdmId);
                prMemInfo->rSrcPrvAdmId = 0;
                prMedAPI->pMemFree(prMedHandle->pvHandle, prMemInfo->pvSrcPrvAdm, MED_MEM_NONCACHE);
            }
        }
        break;

    default:
        SP_TRACE_PARAMETER_ERROR(u4Param, 0, (kal_uint32)prSrcProviderMgr);
        eRet = SOURCE_PROVIDER_ERROR;
        break;
    };

    if (eRet == SOURCE_PROVIDER_ERROR_NONE && u4Param != VIDEO_STATE_CLOSE)
    {
        VideoCommChangeState(&prSrcProviderMgr->rCommState, (VIDEO_STATE_TYPE_T)u4Param);
    }
    return eRet;
}

static kal_bool _SourceProviderPopOutputBuff(SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr,
                                                                                    VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader,
                                                                                    SP_PROCESS_ACTION_T *peAction,
                                                                                    SP_PORT_TYPE_T *pePortType)
{
    VIDEO_COMM_STATE_T * prCommState = &prSrcProviderMgr->rCommState;
    //kal_uint32 u4AudioOutputPort = VideoCommGetOutputPortIndex(&prSrcProviderMgr->rCommState, VIDEO_PORT_AUDIO_DATA);

    // Help to do: audio, video queue process
    if (VideoCommPopOutputBuff(prCommState, prBuffHeader))
    {
        *peAction = SOURCE_PROVIDER_ACTION_OUTPUT_BUFFER;
        *pePortType = SOURCE_PROVIDER_PORT_AUDIO;

        #ifdef __VE_SP_DBG__
        prSrcProviderMgr->rDebugInfo.u4ItemOutputQ--;
        #endif
        return KAL_TRUE;
    }
    else if (VideoCommPopOutputBuffExt(prCommState, prBuffHeader, SOURCE_PROVIDER_PORT_VIDEO))
    {
        *peAction = SOURCE_PROVIDER_ACTION_OUTPUT_BUFFER;
        *pePortType = SOURCE_PROVIDER_PORT_VIDEO;
        return KAL_TRUE;
    }
#ifdef __VE_SUBTITLE_SUPPORT__
    #ifdef __VE_STREAM_SUPPORT__
    else if (prSrcProviderMgr->rSrcInfo.eOpenType != MED_MODE_STREAM)
    #endif
    {     
        if (VideoCommPopOutputBuffExt(prCommState, prBuffHeader, SOURCE_PROVIDER_PORT_SUBTITLE))
        {
            *peAction = SOURCE_PROVIDER_ACTION_OUTPUT_BUFFER;
            *pePortType = SOURCE_PROVIDER_PORT_SUBTITLE;
            return KAL_TRUE;
        }
    }
#endif
   
    *peAction = SOURCE_PROVIDER_ACTION_NONE;
    return KAL_FALSE;
}

static kal_bool _SourceProviderCheckResource(SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr,
                                                                                      SP_PROCESS_ACTION_T *peAction,
                                                                                      SP_PORT_TYPE_T *pePortType)
{
    SP_PLAYBACK_INFO_T *prPlayInfo = &prSrcProviderMgr->rPlayInfo;
    kal_uint32 u4I;

    // check bitstream output
    for (u4I=0; u4I<SOURCE_PROVIDER_PORT_MAX; u4I++)
    {
        if (prPlayInfo->fgSelect[u4I] == KAL_TRUE)
        {
            if (_SourceProviderBufferHeaderSendBufFull(&prSrcProviderMgr->rMemInfo.rBufHeader[u4I]) == KAL_TRUE)
            {
                *peAction = SOURCE_PROVIDER_ACTION_OUTPUT_BITSTREAM_FULL;
                *pePortType = (SP_PORT_TYPE_T)u4I;
                return KAL_TRUE;
            }
        }
    }

    return KAL_FALSE;
}

static kal_bool _SourceProviderCheckInputSource(SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr,
                                                           SP_PROCESS_ACTION_T *peAction,
                                                           kal_bool *pfgProcess,
                                                           SP_PORT_TYPE_T ePortType)
{
    SP_PLAYBACK_INFO_T *prPlayInfo = &prSrcProviderMgr->rPlayInfo;
    SP_MEM_INFO_T *prMemInfo = &prSrcProviderMgr->rMemInfo;    

    if ((prPlayInfo->fgSelect[ePortType] == KAL_TRUE) &&
         (prPlayInfo->fgEof[ePortType] == KAL_FALSE) &&
         (prPlayInfo->fgParserError[ePortType] == KAL_FALSE) &&
         (*pfgProcess == KAL_FALSE))
    {
        SP_PARSER_PARAM_T *prPrvParserParam = prSrcProviderMgr->prPrvParserParam;
        kal_uint32 u4LeftBitstreamBuf = 0, u4LeftPrivateData = 0, u4LeftBufferHeader = 0;
        SP_PROCESS_ACTION_T eAction = SOURCE_PROVIDER_ACTION_NONE;
        
        if (ePortType == SOURCE_PROVIDER_PORT_AUDIO)
        {
            u4LeftBitstreamBuf = prPrvParserParam->u4ALeftBitstreamBuf;
            u4LeftPrivateData = prPrvParserParam->u4ALeftPrivateData;
            u4LeftBufferHeader = 1; 
            eAction = SOURCE_PROVIDER_ACTION_AUDIO_PARSER;
        }
        else if (ePortType == SOURCE_PROVIDER_PORT_VIDEO)
        {
            u4LeftBitstreamBuf = prPrvParserParam->u4VLeftBitstreamBuf;
            u4LeftPrivateData = prPrvParserParam->u4VLeftPrivateData;
            #ifdef __VE_SP_HW_DEC_PIPELINE__
            u4LeftBufferHeader = 3; // h264 HW could keep two frame
            #else
            // make sure that video decoder keep two frames for good performance
            u4LeftBufferHeader = 3 + VideoCommQueryOutputBuffExt(&prSrcProviderMgr->rCommState, SOURCE_PROVIDER_PORT_VIDEO);         
            #endif
            eAction = SOURCE_PROVIDER_ACTION_VIDEO_PARSER;
        }
        #ifdef __VE_SUBTITLE_SUPPORT__
        else if (ePortType == SOURCE_PROVIDER_PORT_SUBTITLE)
        {
            u4LeftBitstreamBuf = prPrvParserParam->u4SLeftBitstreamBuf;
            u4LeftPrivateData = prPrvParserParam->u4SLeftPrivateData;
            u4LeftBufferHeader = 1; 
            eAction = SOURCE_PROVIDER_ACTION_SUBTITLE_PARSER;
        }
        #endif
    
        if(((_SourceProviderBitstreamBufTotalLeftSize(&prMemInfo->rBitstreamBuf[ePortType]) > u4LeftBitstreamBuf) &&    //for read performance
            (_SourceProviderBufferHeaderFull(&prMemInfo->rBufHeader[ePortType]) == KAL_FALSE) &&
            (_SourceProviderPrivateBufLeftSize(&prMemInfo->rPrivateData[ePortType]) >= u4LeftPrivateData)) || // at least one private data
           (_SourceProviderBufferHeaderUsedNum(&prMemInfo->rBufHeader[ePortType]) < u4LeftBufferHeader) //query buffer size and skip u4LeftSize2 size
          )
        {
            *peAction = eAction;
            return KAL_TRUE;
        }
    }

    return KAL_FALSE;
}

static void _SourceProviderDataParser(SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr,
                                         kal_bool *pfgProcess, // Set TRUE, it mean this stream don't process during this run
                                         kal_bool *pfgTriggerTask, // set TRUE, exit loop will trigger timer to wake up task
                                         kal_uint32 *pu4ParseTotalTime,
                                         SP_PORT_TYPE_T ePortType)
{
    SP_MEM_INFO_T *prMemInfo = &prSrcProviderMgr->rMemInfo;
    SP_PARSER_PARAM_T *prPrvParserParam = prSrcProviderMgr->prPrvParserParam;
    void *pvProviderHandle = prSrcProviderMgr->rPrvHandle.pvHandle;
    PROVIDER_API_T *prProviderAPI = prSrcProviderMgr->rPrvHandle.prAPI;
    #ifdef __VE_SP_PROFILE__
    SP_PROFILE_INFO_T *prProfile = &prSrcProviderMgr->rProfile;
    #endif    

    PFN_PROVIDER_PARSE_T pfn_provider_parser = NULL;
    PROVIDER_ERROR_T rRet;
    kal_uint32 u4TotalData, u4Data;
    kal_uint32 u4ParseStartTime = 0, u4ParseTime = 0;
    kal_uint32 u4ExitValue = 0, u4MinBitstreamBuf = 0, u4MinBufHeader = 0, u4LeftBufferHeader = 0;

#ifdef __VE_SP_LOG_HIGH__
    drv_trace2(SP_TRACE_HIGH_GROUP, SP_PROCESS_PARSER, ePortType, (kal_uint32)prSrcProviderMgr);
#endif

    #ifdef __VE_SP_PROFILE__
    prProfile->u4ExitEntry[ePortType]++;
    #endif

    if (ePortType == SOURCE_PROVIDER_PORT_AUDIO)
    {
        u4ExitValue = prPrvParserParam->u4AExitValue;
        u4MinBitstreamBuf = prPrvParserParam->u4AMinBitstreamBuf;
        u4MinBufHeader = prPrvParserParam->u4AMinBufHeader;
        u4LeftBufferHeader = 1;
        pfn_provider_parser = prProviderAPI->PFN_PARSE_AUDIO;
    }
    else if (ePortType == SOURCE_PROVIDER_PORT_VIDEO)
    {
        u4ExitValue = prPrvParserParam->u4VExitValue;
        u4MinBitstreamBuf = prPrvParserParam->u4VMinBitstreamBuf;
        u4MinBufHeader = prPrvParserParam->u4VMinBufHeader;
        #ifdef __VE_SP_HW_DEC_PIPELINE__
        u4LeftBufferHeader = 3;   // h264 HW could keep two frame
        #else
        u4LeftBufferHeader = 1;   // system requriement 
        #endif
        pfn_provider_parser = prProviderAPI->PFN_PARSE_VIDEO;
    }
    #ifdef __VE_SUBTITLE_SUPPORT__
    else if (ePortType == SOURCE_PROVIDER_PORT_SUBTITLE)
    {
        u4ExitValue = prPrvParserParam->u4SExitValue;
        u4MinBitstreamBuf = prPrvParserParam->u4SMinBitstreamBuf;
        u4MinBufHeader = prPrvParserParam->u4SMinBufHeader;
        u4LeftBufferHeader = 0;
        pfn_provider_parser = prProviderAPI->PFN_PARSE_SUBTITLE;
    }
    #endif

    *pfgProcess = KAL_TRUE;
    u4TotalData = 0;
    do{
        u4Data = 0;

        #ifdef __VE_SP_PROFILE__
        prProfile->u4ExitCount[ePortType]++;
        #endif

        if (*pu4ParseTotalTime>SP_TASK_MAX_PARSER_TIME || u4TotalData>u4ExitValue)
        {
            // keep minimax data buffer
            if (((_SourceProviderBitstreamBufUsedSize(&prMemInfo->rBitstreamBuf[ePortType]) < u4MinBitstreamBuf) &&    //for read performance
                 (_SourceProviderBufferHeaderUsedNum(&prMemInfo->rBufHeader[ePortType])<u4MinBufHeader)) ||  // for high bitrate case
                ((_SourceProviderBitstreamBufUsedSize(&prMemInfo->rBitstreamBuf[ePortType]) >= u4MinBitstreamBuf) &&
                 (_SourceProviderBufferHeaderUsedNum(&prMemInfo->rBufHeader[ePortType])<u4LeftBufferHeader) // h264 HW could keep two frame
                )
               )
            {
                #ifdef __VE_SP_PROFILE__
                prProfile->u4ExitBufferlow[ePortType]++;
                #endif

                *pfgProcess = KAL_FALSE;
                *pu4ParseTotalTime = 0;
            }
            break;
        }

        u4ParseStartTime = video_get_current_time();
        rRet = pfn_provider_parser(pvProviderHandle, &u4Data);
        u4ParseTime = video_get_duration_ms(u4ParseStartTime);

        if (rRet == PROVIDER_ERROR_NONE || rRet == PROVIDER_ERROR_NOT_FINISH)
        {
            *pu4ParseTotalTime += u4ParseTime;
            u4TotalData += u4Data;
            
            #ifdef __VE_SP_PROFILE__
            if (*pu4ParseTotalTime>SP_TASK_MAX_PARSER_TIME)
            {
                prProfile->u4ExitTimer[ePortType]++;
            }
            else
            {
                prProfile->u4ExitData[ePortType]++;
            }
            #endif
        }
        else
        {
            #ifdef __VE_SP_LOG_HIGH__
            drv_trace4(SP_TRACE_HIGH_GROUP, SP_PROCESS_PARSER_RESULT, ePortType, rRet, 0, (kal_uint32)prSrcProviderMgr);
            #endif

            #ifdef __VE_SP_PROFILE__
            prProfile->u4ExitOther[ePortType]++;
            #endif

            if (rRet == PROVIDER_ERROR_EOF)
            {
                prSrcProviderMgr->rPlayInfo.fgEof[ePortType] = KAL_TRUE;
                break;
            }
            else if (rRet == PROVIDER_ERROR_WAIT_RESOURCE)
            {
                #ifdef __VE_SP_PROFILE__
                prProfile->u4ExitOtherWaitRes[ePortType]++;
                #endif

                //fgExitLoop = KAL_TRUE;
                *pfgTriggerTask = KAL_TRUE;
                break;
            }
#ifdef __VE_PGDL_SUPPORT__
            else if (rRet == PROVIDER_ERROR_WAIT_DATA)
            {
                //fgExitLoop = KAL_TRUE;
                *pfgTriggerTask = KAL_TRUE;

                if (_SourceProviderBufferHeaderUnsendBufNum(&prMemInfo->rBufHeader[ePortType])==0)
                {
                    _SourceProviderSendCallback(prSrcProviderMgr, VIDEO_EVENT_PARSER_PGDL_UNDERFLOW, ePortType, __LINE__);
                }
                break;
            }
#endif
            else if (rRet == PROVIDER_ERROR_DELAY_REPORT_WITH_EOF)
            {
                prSrcProviderMgr->rPlayInfo.fgEof[ePortType] = KAL_TRUE;
                _SourceProviderSendCallback(prSrcProviderMgr, VIDEO_EVENT_PARSER_DELAY_ERROR, ePortType, __LINE__);
                break;
            }
            else
            {
                prSrcProviderMgr->rPlayInfo.fgParserError[ePortType] = KAL_TRUE;
                _SourceProviderSendCallback(prSrcProviderMgr, VIDEO_EVENT_PARSER_ERROR, ePortType, __LINE__);
                break;
            }
        }
    } while (1);

}


static kal_bool _SourceProviderDataHdlr(SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr)
{
    kal_bool fgRetClose = KAL_FALSE;
    SP_MEM_INFO_T *prMemInfo = &prSrcProviderMgr->rMemInfo;
    SP_PLAYBACK_INFO_T *prPlayInfo = &prSrcProviderMgr->rPlayInfo;

    VIDEO_BUFFERHEADER_TYPE_T rBufferHeader;
    SP_PROCESS_ACTION_T eAction;
    VIDEO_COMMAND_TYPE_T eType;
    SP_ERROR_TYPE_T eError;
    SP_PORT_TYPE_T ePortType;
    kal_uint32 u4Param, u4I;
    kal_uint32 u4ParseTotalTime =0;
    kal_bool fgExitLoop = KAL_FALSE;
    kal_bool fgTriggerTask = KAL_FALSE;
    kal_bool fgAProcessSource = KAL_FALSE;
#ifdef __VE_SUBTITLE_SUPPORT__
    kal_bool fgSProcessSource = KAL_FALSE;
#endif
    kal_bool fgVProcessSource = KAL_FALSE;  

    if (prSrcProviderMgr->fgSetWakeupTimer == KAL_TRUE)
    {
        kal_cancel_timer(prSrcProviderMgr->rTimerID);
        prSrcProviderMgr->fgSetWakeupTimer = KAL_FALSE;
    }

    VideoCommClrProcessing(&prSrcProviderMgr->rCommState);

    /****************
      1. reset variable
      2. choice processing action
      3. run the action
      ****************/
    do{
        eAction = SOURCE_PROVIDER_ACTION_MAX;
        eType = VIDEO_COMMAND_MAX;
        eError = SOURCE_PROVIDER_ERROR_NONE;
        ePortType = SOURCE_PROVIDER_PORT_MAX;

        if (VideoCommPopCommand(&prSrcProviderMgr->rCommState, &eType, &u4Param))
        {
            eAction = SOURCE_PROVIDER_ACTION_COMMAND;
        }
        else
        {
            // process flag
            if (_SourceProviderProcessFlag(prSrcProviderMgr) != SOURCE_PROVIDER_ERROR_NONE)
            {
                return fgRetClose;
            }

            if (VideoCommGetState(&prSrcProviderMgr->rCommState) == VIDEO_STATE_RUN)
            {
                if(_SourceProviderPopOutputBuff(prSrcProviderMgr, &rBufferHeader, &eAction, &ePortType) == KAL_FALSE)
                {
                    #ifdef __VE_STREAM_SUPPORT__
                    if (prSrcProviderMgr->rSrcInfo.eOpenType == MED_MODE_STREAM)
                    {
                         eAction = SOURCE_PROVIDER_ACTION_NONE;
                    }
                    else
                    #endif
                    {
                        if (_SourceProviderCheckResource(prSrcProviderMgr, &eAction, &ePortType) == KAL_FALSE)
                        {
                            if (_SourceProviderCheckInputSource(prSrcProviderMgr, &eAction, &fgAProcessSource, SOURCE_PROVIDER_PORT_AUDIO) == KAL_FALSE) // check Audio
                            {
                                #ifdef __VE_SUBTITLE_SUPPORT__
                                if (_SourceProviderCheckInputSource(prSrcProviderMgr, &eAction, &fgSProcessSource, SOURCE_PROVIDER_PORT_SUBTITLE) == KAL_FALSE) // check Subtitle
                                #endif
                                {
                                    if (_SourceProviderCheckInputSource(prSrcProviderMgr, &eAction, &fgVProcessSource, SOURCE_PROVIDER_PORT_VIDEO) == KAL_FALSE) // check Video
                                    {
                                        eAction = SOURCE_PROVIDER_ACTION_NONE;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                eAction = SOURCE_PROVIDER_ACTION_NONE;
            }
        }

        switch (eAction)
        {
        case SOURCE_PROVIDER_ACTION_NONE:
            {
#ifdef __VE_SP_LOG_HIGH__
                drv_trace1(SP_TRACE_HIGH_GROUP, SP_PROCESS_NONE, (kal_uint32)prSrcProviderMgr);
#endif

                fgExitLoop = KAL_TRUE;
            }
            break;

        case SOURCE_PROVIDER_ACTION_COMMAND:
            {
#ifdef __VE_SP_LOG_HIGH__
                drv_trace4(SP_TRACE_HIGH_GROUP, SP_PROCESS_COMMAND, u4Param, eType, 0, (kal_uint32)prSrcProviderMgr);
#endif

                if (eType != VIDEO_COMMAND_STATESET)
                {
                    ASSERT(0);
                }

                eError = _SourceProviderStateSetHdlr(prSrcProviderMgr, u4Param);

                if (eError == SOURCE_PROVIDER_ERROR)
                {
                    _SourceProviderSendCallback(prSrcProviderMgr, VIDEO_EVENT_ERROR, 0, __LINE__);
                    return fgRetClose;
                }
                else if (eError == SOURCE_PROVIDER_ERROR_MEM_LACK)
                {
                    _SourceProviderSendCallback(prSrcProviderMgr, VIDEO_EVENT_MEM_LACK, 0, __LINE__);
                    return fgRetClose;
                }
#ifdef __VE_PGDL_SUPPORT__
                else if (eError == SOURCE_PROVIDER_ERROR_TIMEOUT)
                {
                    _SourceProviderSendCallback(prSrcProviderMgr, VIDEO_EVENT_TIMEOUT, 0, __LINE__);
                    return fgRetClose;
                }
#endif
            }
            break;

        case SOURCE_PROVIDER_ACTION_OUTPUT_BUFFER:
            {
                VIDEO_BUFFERHEADER_TYPE_T *prBufHeader;
                kal_bool fgKeyFrame;

#ifdef __VE_SP_LOG_HIGH__
                drv_trace4(SP_TRACE_HIGH_GROUP, SP_PROCESS_OUTPUT, ePortType, rBufferHeader.u8TimeStamp, (kal_uint32)rBufferHeader.pu1Buffer, (kal_uint32)prSrcProviderMgr);
#endif

                prBufHeader = (VIDEO_BUFFERHEADER_TYPE_T *)_SourceProviderBufferHeaderGetReadBuf(&prMemInfo->rBufHeader[ePortType]);

                // checking
                if ((prBufHeader->pu1Buffer != rBufferHeader.pu1Buffer) ||
                     (prBufHeader->u4BuffSize!= rBufferHeader.u4BuffSize) ||
                     (prBufHeader->u8TimeStamp != rBufferHeader.u8TimeStamp) ||
                     (prBufHeader->u4OutputPort != rBufferHeader.u4OutputPort))
                {
                    ASSERT(0);
                }

                // release bitstream buffer
                if (rBufferHeader.pu1Buffer != NULL)
                {
                    _SourceProviderBitstreamBufReleaseBuf(&prMemInfo->rBitstreamBuf[ePortType],
                                                                                       (kal_uint32)rBufferHeader.pu1Buffer, rBufferHeader.u4BuffSize);
                }

                // release private data
                if ((ePortType == SOURCE_PROVIDER_PORT_VIDEO
                     #ifdef __VE_SUBTITLE_SUPPORT__
                     || ePortType == SOURCE_PROVIDER_PORT_SUBTITLE
                     #endif
                     ) && rBufferHeader.pPrivateData != NULL)
                {
                    _SourceProviderPrivateBufReleaseBuf(&prMemInfo->rPrivateData[ePortType], rBufferHeader.pPrivateData);
                }

                // release buffer header
                fgKeyFrame = (NULL == ((kal_uint32)(rBufferHeader.eFlags) & (kal_uint32)(VIDEO_BUFFERFLAG_SYNCFRAME)))?(KAL_FALSE):(KAL_TRUE);
                _SourceProviderBufferHeaderAddReadBuf(&prMemInfo->rBufHeader[ePortType], fgKeyFrame, (rBufferHeader.u8TimeStamp/1000));
                
                // trigger Audio
                if (ePortType == SOURCE_PROVIDER_PORT_AUDIO)
                {
                    if (VideoCommQueryOutputBuff(&prSrcProviderMgr->rCommState) == 0)
                    {
                        VIDEO_BUFFERHEADER_TYPE_T rBufferHeader;
                        kal_mem_set((void *)&rBufferHeader, 0, sizeof(VIDEO_BUFFERHEADER_TYPE_T));
                        rBufferHeader.eFlags |= VIDEO_BUFFERFLAG_TRIGGER_AUDIO;
                        #ifdef __VE_SP_LOG_HIGH__
                        drv_trace4(SP_TRACE_HIGH_GROUP, SP_SEND_OUT, ePortType, (kal_uint32)&rBufferHeader, 123456789, (kal_uint32)prSrcProviderMgr);
                        #endif
                        prSrcProviderMgr->rMedHandle.prEmptyAPI->pAudioEmptyBuffer(prSrcProviderMgr->rMedHandle.pvHandle, &rBufferHeader);
                    }
                }
            }
            break;

        case SOURCE_PROVIDER_ACTION_OUTPUT_BITSTREAM_FULL:
            {
#ifdef __VE_SP_LOG_HIGH__
                drv_trace2(SP_TRACE_HIGH_GROUP, SP_PROCESS_OUTPUT_BS_FULL, ePortType, (kal_uint32)prSrcProviderMgr);
#endif

                eError = _SourceProviderSendBufferOut(prSrcProviderMgr, ePortType);
                /*if (SOURCE_PROVIDER_ERROR == eError)
                {
                    // callback error
                    _SourceProviderSendCallback(prSrcProviderMgr, VIDEO_EVENT_ERROR, 0, __LINE__);
                }
                else*/
                if (SOURCE_PROVIDER_ERROR_BUF_FULL == eError)
                {
                    fgExitLoop = KAL_TRUE;
                    fgTriggerTask = KAL_TRUE;
                }
            }
            break;

        case SOURCE_PROVIDER_ACTION_AUDIO_PARSER:
            {
                _SourceProviderDataParser(prSrcProviderMgr, &fgAProcessSource, &fgTriggerTask, &u4ParseTotalTime, SOURCE_PROVIDER_PORT_AUDIO);
            }
            break;

#ifdef __VE_SUBTITLE_SUPPORT__
        case SOURCE_PROVIDER_ACTION_SUBTITLE_PARSER:
            {
                _SourceProviderDataParser(prSrcProviderMgr, &fgSProcessSource, &fgTriggerTask, &u4ParseTotalTime, SOURCE_PROVIDER_PORT_SUBTITLE);
            }
            break;
#endif

        case SOURCE_PROVIDER_ACTION_VIDEO_PARSER:
            {
                _SourceProviderDataParser(prSrcProviderMgr, &fgVProcessSource, &fgTriggerTask, &u4ParseTotalTime, SOURCE_PROVIDER_PORT_VIDEO);
            }
            break;

        default:
            ASSERT(0);
            break;
        }

        if (fgExitLoop == KAL_TRUE)
        {
            if (VideoCommGetState(&prSrcProviderMgr->rCommState) == VIDEO_STATE_RUN)
            {
                for(u4I=0; u4I<SOURCE_PROVIDER_PORT_MAX; u4I++)
                {
                    if(prPlayInfo->fgSelect[u4I] == KAL_TRUE)
                    {
                        eError = _SourceProviderSendBufferOut(prSrcProviderMgr, (SP_PORT_TYPE_T)u4I);

                        if (SOURCE_PROVIDER_ERROR_BUF_FULL == eError)
                        {                
                            fgTriggerTask = KAL_TRUE;
                        }
                    }
                }
            }

            if (fgTriggerTask == KAL_TRUE)
            {
               kal_set_timer(prSrcProviderMgr->rTimerID, _SourceProviderWakeUp, (void *)prSrcProviderMgr, SP_TASK_WAKE_UP_TICK, 0);
               prSrcProviderMgr->fgSetWakeupTimer= KAL_TRUE;
#ifdef __VE_SP_LOG_HIGH__
               drv_trace1(SP_TRACE_HIGH_GROUP, SP_ACTIVATE_TIMER, (kal_uint32)prSrcProviderMgr);
#endif
            }
            break;
        }

    } while(1);

    // make sure that there are no message in task's queue
    if (prSrcProviderMgr->rControlInfo.fgWaitClose== KAL_TRUE)
    {
        if (VideoCommCheckProcessing(&prSrcProviderMgr->rCommState) == KAL_FALSE)
        {
            fgRetClose = KAL_TRUE;
            //VideoCommChangeState(&prSrcProviderMgr->rCommState, VIDEO_STATE_CLOSE);
        }
    }

    return fgRetClose;
}

/********************************************************
*
*   Component interfaces
*
********************************************************/
VIDEO_ERROR_TYPE_T SourceProviderInit(void* pvHandle)
{
    SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr = (SRC_PRIVDER_CONTEXT_T *)pvHandle;
    SP_MED_HANDLE_T *prMedHandle = (SP_MED_HANDLE_T *)&prSrcProviderMgr->rMedHandle;
    SP_MEM_INFO_T *prMemInfo = (SP_MEM_INFO_T *) &prSrcProviderMgr->rMemInfo;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
#ifdef __VE_STREAM_SUPPORT__    
    SP_SOURCE_INFO_T *prSrcInfo = &prSrcProviderMgr->rSrcInfo;
    VIDEO_PORT_CONFIG_T rInputPort1, rInputPort2;
#endif    
    VIDEO_PORT_CONFIG_T rOutputPort1, rOutputPort2;
    VIDEO_COMPONENT_INIT_T rInitConfig;
    kal_uint32 u4ComponentSize;

#ifdef __VE_SP_LOG_FUNC__
    drv_trace1(SP_TRACE_FUNC_GROUP, SP_INIT, (kal_uint32)pvHandle);
#endif

    // Common API initialization
    // Help to do: 1. input/output port need two queue, 2. port type support too few
    kal_mem_set(&rInitConfig, 0, sizeof(VIDEO_COMPONENT_INIT_T));

#ifdef __VE_STREAM_SUPPORT__
    if (prSrcInfo->eOpenType == MED_MODE_STREAM)
    {
        rInputPort1.ePortType = VIDEO_PORT_AUDIO_DATA;
        rInputPort1.fgSupplier = KAL_FALSE;
        rInputPort1.u4BuffSize = 0;

        rInputPort2.ePortType = VIDEO_PORT_VIDEO_DATA;
        rInputPort2.fgSupplier = KAL_FALSE;
        rInputPort2.u4BuffSize = 0;

        rInitConfig.prInputPort1 = &rInputPort1;
        rInitConfig.prInputPort2 = &rInputPort2;
        rInitConfig.u4InputBuffQSize = SOURCE_PROVIDER_STREAMING_INPUT_BUFFER_Q_1_LEN;
        rInitConfig.u4InputBuffQSize2 = SOURCE_PROVIDER_STREAMING_INPUT_BUFFER_Q_2_LEN;
        
        rInitConfig.u4OutputBuffQSize = SOURCE_PROVIDER_STREAMING_OUTPUT_BUFFER_Q_1_LEN;
        rInitConfig.u4OutputBuffQSize2 = SOURCE_PROVIDER_STREAMING_OUTPUT_BUFFER_Q_2_LEN;

        u4ComponentSize = SOURCE_PROVIDER_STREAMING_COMPONENT_SIZE;
    }
    else
#endif
    {
        /*
        rInitConfig.prInputPort1 = NULL;
        rInitConfig.prInputPort2 = NULL;
        rInitConfig.u4InputBuffQSize = 0;
        rInitConfig.u4InputBuffQSize2 = 0;
        */
        rInitConfig.u4OutputBuffQSize = SOURCE_PROVIDER_OUTPUT_BUFFER_Q_1_LEN;
        rInitConfig.u4OutputBuffQSize2 = SOURCE_PROVIDER_OUTPUT_BUFFER_Q_2_LEN;

        u4ComponentSize = SOURCE_PROVIDER_COMPONENT_SIZE;        
    }

    rOutputPort1.ePortType = VIDEO_PORT_AUDIO_DATA;
    rOutputPort1.fgSupplier = KAL_FALSE;
    rOutputPort1.u4BuffSize = 0;

    rOutputPort2.ePortType = VIDEO_PORT_VIDEO_DATA;
    rOutputPort2.fgSupplier = KAL_FALSE;
    rOutputPort2.u4BuffSize = 0;

    rInitConfig.prOutputPort1 = &rOutputPort1;
    rInitConfig.prOutputPort2 = &rOutputPort2;
    rInitConfig.u4CmdQSize = SOURCE_PROVIDER_CMD_Q_LEN;

    // obtain component memory handle
    // Help to do: 1. add one scenario 2. memory size
    prMemInfo->pvExtMemComponent = prMedHandle->prAPI->pMemAlloc(prMedHandle->pvHandle, u4ComponentSize, MED_MEM_NONCACHE);
    if (prMemInfo->pvExtMemComponent == NULL)
    {
        SP_TRACE_MEMORY_ERROR(u4ComponentSize, 0,(kal_uint32)prSrcProviderMgr);
        return VIDEO_ERROR_NO_MEMORY;
    }
    prMemInfo->prComponentHandle= VideoInitExtBuffer((kal_uint32)prMemInfo->pvExtMemComponent, u4ComponentSize, VIDEO_SCENARIO_SRC_PROVIDER);
    rInitConfig.prExtMemHdlr = prMemInfo->prComponentHandle;

    rInitConfig.eMutex = VideoGetMutex(MUTEX_USER_SOURCE_COMMON);    

    eError = VideoCommInit(&prSrcProviderMgr->rCommState, & rInitConfig, "SOURCE");
    if(eError != VIDEO_ERROR_NONE)
    {
        SP_TRACE_COMPONENT_ERROR(eError, 0, (kal_uint32)prSrcProviderMgr);
        goto INIT_ERR_HANDLE;
    }

    #ifdef __VE_SUBTITLE_SUPPORT__
    #ifdef __VE_STREAM_SUPPORT__
    if (prSrcInfo->eOpenType != MED_MODE_STREAM)
    #endif
    {
        VIDEO_COMPONENT_INIT_PORT_T rSubtitlePortInit;

        rSubtitlePortInit.ePort = VIDEO_PORT_OUTPUT;
        rSubtitlePortInit.rConfig.ePortType = VIDEO_PORT_SUBTITLE;
        rSubtitlePortInit.rConfig.fgSupplier = KAL_FALSE;
        rSubtitlePortInit.rConfig.u4BuffSize = 0;
        rSubtitlePortInit.u4BuffQSize = SOURCE_PROVIDER_OUTPUT_BUFFER_Q_3_LEN;
        rSubtitlePortInit.u4PortIndex = SOURCE_PROVIDER_PORT_SUBTITLE;
        rSubtitlePortInit.prExtMemHdlr = prMemInfo->prComponentHandle;

        eError = VideoCommConfigPorts(&prSrcProviderMgr->rCommState, &rSubtitlePortInit);
        if(eError != VIDEO_ERROR_NONE)
        {
            SP_TRACE_COMPONENT_ERROR(eError, 0, (kal_uint32)prSrcProviderMgr);
            goto INIT_ERR_HANDLE;
        }
    }
    #endif

    VideoMICommSetClient(&prSrcProviderMgr->rCommState, prMedHandle->pvHandle);

    // assign resource
    // Help to do: resource need from il client
    #ifdef __VE_STREAM_SUPPORT__
    if (prSrcInfo->eOpenType == MED_MODE_STREAM)
    {
        prSrcProviderMgr->rSrcVBufHeaderMutex = VideoGetMutex(MUTEX_USER_SOURCE_VBUF);
        prSrcProviderMgr->rSrcVBitstreamMutex = VideoGetMutex(MUTEX_USER_SOURCE_VBS);
        prSrcProviderMgr->rSrcVPrivateDataMutex = VideoGetMutex(MUTEX_USER_SOURCE_VPRI);
        prSrcProviderMgr->rSrcABufHeaderMutex = VideoGetMutex(MUTEX_USER_SOURCE_ABUF);
        prSrcProviderMgr->rSrcABitstreamMutex = VideoGetMutex(MUTEX_USER_SOURCE_ABS);
    }
    else
    #endif        
    {
        prSrcProviderMgr->rSrcVBufHeaderMutex = NULL;
        prSrcProviderMgr->rSrcVBitstreamMutex = NULL;
        prSrcProviderMgr->rSrcVPrivateDataMutex = NULL;
        prSrcProviderMgr->rSrcABufHeaderMutex = NULL;
        prSrcProviderMgr->rSrcABitstreamMutex = NULL;
    }    

    prSrcProviderMgr->rTimerID = VideoGetTimer(TIMER_USER_SOURCE);
    prSrcProviderMgr->fgSetWakeupTimer = KAL_FALSE;

    return eError;

INIT_ERR_HANDLE:
    // release mutux
    VideoFreeMutex(MUTEX_USER_SOURCE_COMMON, prSrcProviderMgr->rCommState.eMutex);

    // release component memory
    VideoDeInitExtBuffer(prMemInfo->prComponentHandle);
    prMedHandle->prAPI->pMemFree(prMedHandle->pvHandle, prMemInfo->pvExtMemComponent, MED_MEM_NONCACHE);

    return eError;

}

VIDEO_ERROR_TYPE_T SourceProviderSendCommand(void* pvHandle, VIDEO_COMMAND_TYPE_T rCmd, kal_uint32 u4Param)
{
    SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr = (SRC_PRIVDER_CONTEXT_T *)pvHandle;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    kal_bool fgCompClosing;
    kal_bool fgRet = KAL_FALSE;

#ifdef __VE_SP_LOG_FUNC__
    drv_trace2(SP_TRACE_FUNC_GROUP, SP_SEND_CMMD, u4Param, (kal_uint32)pvHandle);
#endif

    if(rCmd == VIDEO_COMMAND_STATESET)
    {
        fgRet = VideoCommPushCommand(&prSrcProviderMgr->rCommState, rCmd, u4Param);
        if (fgRet == KAL_FALSE)
        {
            // error handling
            eError = VIDEO_ERROR_BUFF_FULL;
        }

        if (u4Param != VIDEO_STATE_CLOSE)
        {
            fgCompClosing = KAL_FALSE;
        }
        else
        {
            fgCompClosing = KAL_TRUE;
        }
        _SourceProviderTriggerTask(prSrcProviderMgr, fgCompClosing, SOURCE_PROVIDER_MSG_COMMAND);
    }
    else
    {
        SP_TRACE_PARAMETER_ERROR(rCmd, (kal_uint32)pvHandle, 0);
        eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
    }
    return eError;
}

VIDEO_ERROR_TYPE_T SourceProviderGetParameter(void* pvHandle, VIDEO_PARAM_TYPE_T eCmd, void *pParam)
{
    SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr = (SRC_PRIVDER_CONTEXT_T *)pvHandle;
    SP_PLAYBACK_INFO_T *prPlayInfo = (SP_PLAYBACK_INFO_T *)&prSrcProviderMgr->rPlayInfo;
    void *pvProviderHandle = prSrcProviderMgr->rPrvHandle.pvHandle;
    PROVIDER_API_T *prProviderAPI = prSrcProviderMgr->rPrvHandle.prAPI;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    kal_bool fgRightState = KAL_FALSE;
    VIDEO_STATE_TYPE_T eState;
#ifdef __VE_STREAM_SUPPORT__
    SP_SOURCE_INFO_T *prSrcInfo = &prSrcProviderMgr->rSrcInfo;
#endif

    eState = VideoCommGetState(&prSrcProviderMgr->rCommState);

    switch(eCmd)
    {
    case VIDEO_PARAM_INPUT_BUFFER_PARAM:
        if (eState == VIDEO_STATE_INIT)
        {
            VideoCommGetInputPortParam(&prSrcProviderMgr->rCommState, pParam);
            fgRightState = KAL_TRUE;
        }
        break;

    case VIDEO_PARAM_OUTPUT_BUFFER_PARAM:
        if (eState == VIDEO_STATE_INIT)
        {
            VideoCommGetOutputPortParam(&prSrcProviderMgr->rCommState, pParam);
            fgRightState = KAL_TRUE;
        }
        break;

    case VIDEO_PARAM_SOURCE_PROVIDER_VID_STREAM_INFO:
        if (eState != VIDEO_STATE_CLOSE)
        {
            fgRightState = KAL_TRUE;
            
            #ifdef __VE_STREAM_SUPPORT__
            if (prSrcInfo->eOpenType == MED_MODE_STREAM)
            {
                eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
                break;
            }
            #endif 
            
            kal_mem_cpy((void *)pParam, (void *)&prSrcProviderMgr->rStreamInfo[SOURCE_PROVIDER_PORT_VIDEO], sizeof(SPIF_STREAM_INFO_T));
        }
        break;

    case VIDEO_PARAM_SOURCE_PROVIDER_AUD_STREAM_INFO:
        if (eState != VIDEO_STATE_CLOSE)
        {
            fgRightState = KAL_TRUE;
            
            #ifdef __VE_STREAM_SUPPORT__
            if (prSrcInfo->eOpenType == MED_MODE_STREAM)        
            {
                eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
                break;
            }
            #endif    
            
            kal_mem_cpy((void *)pParam, (void *)&prSrcProviderMgr->rStreamInfo[SOURCE_PROVIDER_PORT_AUDIO], sizeof(SPIF_STREAM_INFO_T));
        }
        break;

#ifdef __VE_SUBTITLE_SUPPORT__
    case VIDEO_PARAM_SOURCE_PROVIDER_SUBT_STREAM_INFO:
        if (eState != VIDEO_STATE_CLOSE)
        {
            fgRightState = KAL_TRUE;
            
            #ifdef __VE_STREAM_SUPPORT__
            if (prSrcInfo->eOpenType == MED_MODE_STREAM)
            {
                eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
                break;
            }
            #endif

            kal_mem_cpy((void *)pParam, (void *)&prSrcProviderMgr->rStreamInfo[SOURCE_PROVIDER_PORT_SUBTITLE], sizeof(SPIF_STREAM_INFO_T));
        }
        break;
#endif

    case VIDEO_PARAM_SOURCE_PROVIDER_METADATA_INFO:
        if (eState != VIDEO_STATE_CLOSE)
        {
            fgRightState = KAL_TRUE;
            
            #ifdef __VE_STREAM_SUPPORT__
            if (prSrcInfo->eOpenType == MED_MODE_STREAM)        
            {
                eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
                break;
            }
            #endif         
            
            if (prProviderAPI->PFN_GET_PARAMETER(pvProviderHandle, PROVIDER_PARAM_META_DATA, pParam) != PROVIDER_ERROR_NONE)
            {
                eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
            }
        }
        break;

    case VIDEO_PARAM_SOURCE_PROVIDER_CAPABILITY:
        if (eState == VIDEO_STATE_INIT)
        {
            fgRightState = KAL_TRUE;
            
            #ifdef __VE_STREAM_SUPPORT__
            if (prSrcInfo->eOpenType == MED_MODE_STREAM)        
            {
                eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
                break;
            }
            #endif    
        
            kal_mem_cpy((void *)pParam, (void *)&prSrcProviderMgr->eCapabiltiy, sizeof(SP_CAPABILITY_T));
        }
        break;

    case VIDEO_PARAM_SOURCE_PROVIDER_KEY_FRAME_TIME:
        if (eState == VIDEO_STATE_IDLE || eState == VIDEO_STATE_RUN || eState == VIDEO_STATE_STOP)
        {
             SP_PORT_TYPE_T ePort = ((SPIF_KEY_FRAME_TIME_T *)pParam)->ePort;
                       
            fgRightState = KAL_TRUE;                      
        
            if ((prPlayInfo->u1Track[ePort] != SP_TRACK_DEFAULT) 
               #if defined(__VE_SP_STREAM_JUMP__)  
               || (prSrcInfo->eOpenType == MED_MODE_STREAM)
               #endif
               )
            {
                //prProviderAPI->PFN_GET_PARAMETER(pvProviderHandle, PROVIDER_PARAM_KEY_FRAME_TIME, pParam);
                prPlayInfo->pvControlData[ePort] = pParam;

                prPlayInfo->u4ControlFlag[ePort] |= SOURCE_PROVIDER_FLAG_GET_KEY_FRAME_TIME;

                // clear abort value
                _SourceProviderSetAbortParam(prPlayInfo, prProviderAPI, pvProviderHandle, ePort, KAL_FALSE);

                _SourceProviderTriggerTask(prSrcProviderMgr, KAL_FALSE, SOURCE_PROVIDER_MSG_GET_PARAM);

                eError = VIDEO_ERROR_ASYNC_OPERATION;
            }
            else
            {
                eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
            }
        }
        break;

    case VIDEO_PARAM_SOURCE_PROVIDER_TIME_TO_FRAME:
        if (eState != VIDEO_STATE_CLOSE)
        {
            fgRightState = KAL_TRUE;
            
            #ifdef __VE_STREAM_SUPPORT__
            if (prSrcInfo->eOpenType == MED_MODE_STREAM)        
            {
                eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
                break;
            }
            #endif  
        
            if (prProviderAPI->PFN_GET_PARAMETER(pvProviderHandle, PROVIDER_PARAM_TIME_TO_FRAME, pParam) != PROVIDER_ERROR_NONE)
            {
                eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
            }
        }
        break;

    case VIDEO_PARAM_SOURCE_PROVIDER_FRAME_TO_TIME:
        if (eState != VIDEO_STATE_CLOSE)
        {
            fgRightState = KAL_TRUE;
            
            #ifdef __VE_STREAM_SUPPORT__
            if (prSrcInfo->eOpenType == MED_MODE_STREAM)        
            {
                eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
                break;
            }
            #endif          
            
            if (prProviderAPI->PFN_GET_PARAMETER(pvProviderHandle, PROVIDER_PARAM_FRAME_TO_TIME, pParam) != PROVIDER_ERROR_NONE)
            {
                eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
            }
        }
        break;

#ifdef __VE_PGDL_SUPPORT__
    case VIDEO_PARAM_SOURCE_PROVIDER_QUERY_FRAME_BUF:
        if (eState != VIDEO_STATE_CLOSE)
        {
            SP_PORT_TYPE_T ePort = SOURCE_PROVIDER_PORT_AUDIO; // set for pass parameter
            fgRightState = KAL_TRUE;
            
            #ifdef __VE_STREAM_SUPPORT__
            if (prSrcInfo->eOpenType == MED_MODE_STREAM)        
            {
                eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
                break;
            }
            #endif  
        
            prPlayInfo->pvControlData[ePort] = pParam;

            prPlayInfo->u4ControlFlag[ePort] |= SOURCE_PROVIDER_FLAG_QUERY_FRAME_BUF;

            _SourceProviderTriggerTask(prSrcProviderMgr, KAL_FALSE, SOURCE_PROVIDER_MSG_GET_PARAM);

            eError = VIDEO_ERROR_ASYNC_OPERATION;            
        }
        break;
#endif        

    case VIDEO_PARAM_SOURCE_PROVIDER_DRM_FSAL:
        {
            fgRightState = KAL_TRUE;
            
            #ifdef __VE_STREAM_SUPPORT__
            if (prSrcInfo->eOpenType == MED_MODE_STREAM)        
            {
                eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
                break;
            }
            #endif  
            
            if(prProviderAPI->PFN_GET_PARAMETER(pvProviderHandle, PROVIDER_PARAM_DRM_FSAL, pParam) != PROVIDER_ERROR_NONE)
            {
                eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
            }
        }
        break;

#ifdef __VE_STREAM_SUPPORT__
    case VIDEO_PARAM_SOURCE_PROVIDER_STREAMING_BUF:
        if (eState == VIDEO_STATE_IDLE || eState == VIDEO_STATE_RUN || eState == VIDEO_STATE_STOP)
        {
            SPIF_STREAMING_BUF_INFO_T * prBufInfo = (SPIF_STREAMING_BUF_INFO_T *)pParam;
            SP_BITSTREAM_BUF_T *prBitstreamBuf = &prSrcProviderMgr->rMemInfo.rBitstreamBuf[prBufInfo->ePort];
            
            prBufInfo->u4FreeBuf = _SourceProviderBitstreamBufTotalLeftSize(prBitstreamBuf);
            prBufInfo->u4TotalBuf = prBitstreamBuf->u4RealSize;
            prBufInfo->fgBufferHigh = _SourceProviderStreamingBufferStatus(prSrcProviderMgr, prBufInfo->ePort);
            #ifdef __VE_SP_LOG_LOW__
            drv_trace4(SP_TRACE_LOW_GROUP, SP_GET_STREAMING_INFO, prBufInfo->ePort, prBufInfo->u4FreeBuf, prBufInfo->u4TotalBuf, prBufInfo->fgBufferHigh);
            #endif    
            fgRightState = KAL_TRUE;
        }
        break;
#endif        

#ifdef __VE_VIDEO_CLIPPER_SUPPORT__
    case VIDEO_PARAM_SOURCE_PROVIDER_MTK_FILE:
        if (eState != VIDEO_STATE_CLOSE)
        {
            kal_bool *pfgMtkFile = (kal_bool *)pParam;
            fgRightState = KAL_TRUE;
            
            #ifdef __VE_STREAM_SUPPORT__
            if (prSrcInfo->eOpenType == MED_MODE_STREAM)        
            {
                eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
                break;
            }
            #endif 
            
            // set default value
            *pfgMtkFile = KAL_FALSE;
            
            if(prProviderAPI->PFN_GET_PARAMETER(pvProviderHandle, PROVIDER_PARAM_MTK_FILE, pParam) != PROVIDER_ERROR_NONE)
            {
                eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
            }    
        }
        break;
#endif        

#ifdef __VE_PARSE_TRANSFORMATION_INFO__
    case VIDEO_PARAM_SOURCE_PROVIDER_TRANSFORMATION_INFO:
        if (eState != VIDEO_STATE_CLOSE)
        {
            fgRightState = KAL_TRUE;
            
            #ifdef __VE_STREAM_SUPPORT__
            if (prSrcInfo->eOpenType == MED_MODE_STREAM)        
            {
                eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
                break;
            }
            #endif 
            
            //set default value
            kal_mem_set(pParam, 0, sizeof(SPIF_TRANSFORMATION_INFO_T));
            
            if (prProviderAPI->PFN_GET_PARAMETER(pvProviderHandle, PROVIDER_PARAM_TRANSFORMATION_INFO, pParam) != PROVIDER_ERROR_NONE)
            {
                eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
            }
        }
        break;
#endif     

#ifdef __VE_VIDEO_CLIPPER_SUPPORT__
    case VIDEO_PARAM_SOURCE_PROVIDER_AVC_CONF_RECORD:
        if (eState != VIDEO_STATE_CLOSE)
        {
            fgRightState = KAL_TRUE;
            
            #ifdef __VE_STREAM_SUPPORT__
            if (prSrcInfo->eOpenType == MED_MODE_STREAM)        
            {
                eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
                break;
            }
            #endif 
            
            if(prProviderAPI->PFN_GET_PARAMETER(pvProviderHandle, PROVIDER_PARAM_AVC_CONF_RECORD, pParam) != PROVIDER_ERROR_NONE)
            {
                eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
            }
        }
        break;
#endif   

#ifdef __VE_3D_SIDE_BY_SIDE__
    case VIDEO_PARAM_SOURCE_PROVIDER_3D_SBS:
        if (eState != VIDEO_STATE_CLOSE)
        {
            kal_bool *pfg3DSBS = (kal_bool *)pParam;
            
            fgRightState = KAL_TRUE;
            
            #ifdef __VE_STREAM_SUPPORT__
            if (prSrcInfo->eOpenType == MED_MODE_STREAM)        
            {
                eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
                break;
            }
            #endif 
            
            // set default value
            *pfg3DSBS = KAL_FALSE;
            
            if (prProviderAPI->PFN_GET_PARAMETER(pvProviderHandle, PROVIDER_PARAM_3D_SBS, pParam) != PROVIDER_ERROR_NONE)
            {
                eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
            }
        }
        break;   
#endif  

    case VIDEO_PARAM_SOURCE_PROVIDER_PORT_INFO:
        if (eState != VIDEO_STATE_CLOSE)
        {
            SPIF_PORT_INFO_T *prPortInfo = (SPIF_PORT_INFO_T *)pParam;
            prPortInfo->u4ControlFlag = prPlayInfo->u4ControlFlag[prPortInfo->eType];
            prPortInfo->fgParserError = prPlayInfo->fgParserError[prPortInfo->eType];
            fgRightState = KAL_TRUE;
        }
        break;

    default:
        fgRightState = KAL_TRUE;
        eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
        break;
    }

    if (fgRightState == KAL_FALSE)
    {
        //ASSERT(0);
        eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
    }

#ifdef __VE_SP_LOG_FUNC__
    drv_trace4(SP_TRACE_FUNC_GROUP, SP_GET_PARAM, eCmd, eError,  eState, (kal_uint32)prSrcProviderMgr);
#endif
    return eError;
}

VIDEO_ERROR_TYPE_T SourceProviderSetParameter(void* pvHandle, VIDEO_PARAM_TYPE_T eCmd, void *pParam)
{
    SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr = (SRC_PRIVDER_CONTEXT_T *)pvHandle;
    SP_PLAYBACK_INFO_T *prPlayInfo = (SP_PLAYBACK_INFO_T *)&prSrcProviderMgr->rPlayInfo;
    void *pvProviderHandle = prSrcProviderMgr->rPrvHandle.pvHandle;
    PROVIDER_API_T *prProviderAPI = prSrcProviderMgr->rPrvHandle.prAPI;
    //SP_MEM_INFO_T *prMemInfo = (SP_MEM_INFO_T *) &prSrcProviderMgr->rMemInfo;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    kal_bool fgRightState = KAL_FALSE;
    VIDEO_STATE_TYPE_T eState;
#ifdef __VE_STREAM_SUPPORT__
    SP_SOURCE_INFO_T *prSrcInfo = &prSrcProviderMgr->rSrcInfo;
#endif

    eState = VideoCommGetState(&prSrcProviderMgr->rCommState);

    switch(eCmd)
    {
    case VIDEO_PARAM_INPUT_BUFFER_PARAM:
        if (eState == VIDEO_STATE_INIT)
        {
            VideoCommSetInputPortParam(&prSrcProviderMgr->rCommState, pParam);
            fgRightState = KAL_TRUE;
        }
        break;

    case VIDEO_PARAM_OUTPUT_BUFFER_PARAM:
        if (eState == VIDEO_STATE_INIT)
        {
            VideoCommSetOutputPortParam(&prSrcProviderMgr->rCommState, pParam);
            fgRightState = KAL_TRUE;
        }
        break;

    case VIDEO_PARAM_SOURCE_PROVIDER_SEEK_TIME:
        if (eState == VIDEO_STATE_IDLE ||eState == VIDEO_STATE_RUN || eState == VIDEO_STATE_STOP)
        {
            SP_PORT_TYPE_T eType;
            SPIF_SEEK_TIME_T *prSeekTime = (SPIF_SEEK_TIME_T *)pParam;           

            eType = prSeekTime->eType;

            if (prPlayInfo->fgSelect[eType] == KAL_TRUE || // make sure provider is not run
                (prSeekTime->u8StartTime >= prSeekTime->u8EndTime) // parameter error
                )
            {
                SP_TRACE_PARAMETER_ERROR(prPlayInfo->fgSelect[eType], prSeekTime->u8StartTime, prSeekTime->u8EndTime);
                eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
                break;
            }

            prPlayInfo->pvControlData[eType] = pParam;

            prPlayInfo->u4ControlFlag[eType] |= SOURCE_PROVIDER_FLAG_SEEK_TIME;

            // clear abort value
            _SourceProviderSetAbortParam(prPlayInfo, prProviderAPI, pvProviderHandle, eType, KAL_FALSE);

            _SourceProviderTriggerTask(prSrcProviderMgr, KAL_FALSE, SOURCE_PROVIDER_MSG_SET_PARAM);

            eError = VIDEO_ERROR_ASYNC_OPERATION;

            fgRightState = KAL_TRUE;
        }
        break;

#if 0
/* under construction !*/
#if 0//__VE_SP_DIRECT_SEEK__
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
#endif

    case VIDEO_PARAM_SOURCE_PROVIDER_SELECT_PORT:
        if (eState == VIDEO_STATE_IDLE ||eState == VIDEO_STATE_RUN || eState == VIDEO_STATE_STOP)
        {
            SPIF_PORT_T *prPort = (SPIF_PORT_T *)pParam;

#ifdef __VE_SP_LOG_HIGH__
            drv_trace2(SP_TRACE_HIGH_GROUP, SP_SET_PORT, prPort->eType, prPort->fgEnable);
#endif

            if (prPlayInfo->fgSelect[prPort->eType] != prPort->fgEnable)
            {
                prPlayInfo->u4ControlFlag[prPort->eType] |= SOURCE_PROVIDER_FLAG_OUTPUT_PORT;

                _SourceProviderTriggerTask(prSrcProviderMgr, KAL_FALSE, SOURCE_PROVIDER_MSG_SET_PARAM);

                eError = VIDEO_ERROR_ASYNC_OPERATION;
            }
            else
            {
                eError = VIDEO_ERROR_UNUSED_OPERATION;
            }
            fgRightState = KAL_TRUE;
        }
        break;

    case VIDEO_PARAM_SOURCE_PROVIDER_SELECT_STREAM:
        if (eState == VIDEO_STATE_IDLE || eState == VIDEO_STATE_STOP)
        {
            SPIF_STREAM_T *prStream = (SPIF_STREAM_T *)pParam;
            SP_PORT_TYPE_T eType = prStream->eType;
            kal_uint32 u4I;
            SPIF_STREAM_INFO_T *prStreamInfo;

            fgRightState = KAL_TRUE;

            #ifdef __VE_STREAM_SUPPORT__
            if (prSrcInfo->eOpenType == MED_MODE_STREAM)        
            {
                eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
                break;
            }
            #endif  

            if (prPlayInfo->fgSelect[eType] == KAL_TRUE || eType >= SOURCE_PROVIDER_PORT_MAX)
            {
                SP_TRACE_PARAMETER_ERROR(prPlayInfo->fgSelect[eType], eType, 0);
                eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
                break;;
            }

#ifdef __VE_SP_LOG_HIGH__
            drv_trace2(SP_TRACE_HIGH_GROUP, SP_SET_STREAM, eType, prStream->u1Track);
#endif

            if (prProviderAPI->PFN_SET_PARAMETER(pvProviderHandle, PROVIDER_PARAM_SELECT_STREAM, pParam)!= PROVIDER_ERROR_NONE)
            {
                eError = VIDEO_ERROR_INPUT_PARAM_ERROR; 
                break;
            }

            prPlayInfo->u1Track[eType] = prStream->u1Track;

            // obtain stream info
            prStreamInfo = &prSrcProviderMgr->rStreamInfo[eType];
            if (eType == SOURCE_PROVIDER_PORT_VIDEO)
            {                
                prPlayInfo->prVideoStreamInfo = (SPIF_VIDEO_STREAM_INFO_T *)prStreamInfo->pvStreamInfo;
                for (u4I=0; u4I<prStreamInfo->u4Num; u4I++)
                {
                    if (prPlayInfo->prVideoStreamInfo->u4StreamIndex == prStream->u1Track)
                    {
                        break;
                    }
                    prPlayInfo->prVideoStreamInfo += 1;
                }
                
                VFC_IOCtrl(VFC_OP_SRC_SET_VIDEO_CODEC_TYPE, &(prPlayInfo->prVideoStreamInfo->eCodecType), NULL, NULL);
            }
            else if (eType == SOURCE_PROVIDER_PORT_AUDIO)
            {
                prPlayInfo->prAudioStreamInfo = (SPIF_AUDIO_STREAM_INFO_T *)prStreamInfo->pvStreamInfo;
                 for (u4I=0; u4I<prStreamInfo->u4Num; u4I++)
                {
                    if (prPlayInfo->prAudioStreamInfo->u4StreamIndex == prStream->u1Track)
                    {
                        break;
                    }
                    prPlayInfo->prAudioStreamInfo += 1;
                }
            }
#ifdef __VE_SUBTITLE_SUPPORT__
            else if (eType == SOURCE_PROVIDER_PORT_SUBTITLE)
            {
                prPlayInfo->prSubtitleStreamInfo = (SPIF_SUBTITLE_STREAM_INFO_T *)prStreamInfo->pvStreamInfo;
                for (u4I=0; u4I<prStreamInfo->u4Num; u4I++)
                {
                    if (prPlayInfo->prSubtitleStreamInfo->u4StreamIndex == prStream->u1Track)
                    {
                        break;
                    }
                    prPlayInfo->prSubtitleStreamInfo += 1;
                }
            }
#endif
        }
        break;
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __VE_SUBTITLE_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif        

    case VIDEO_PARAM_SOURCE_PROVIDER_QUICK_CLOSE:
        if (eState == VIDEO_STATE_CLOSE)
        {
            prSrcProviderMgr->rControlInfo.fgQuickClose = KAL_TRUE;
            if (prProviderAPI != NULL)
            {
                if (prProviderAPI->PFN_SET_PARAMETER(pvProviderHandle, PROVIDER_PARAM_QUICK_CLOSE, pParam) != PROVIDER_ERROR_NONE)
                {
                    eError = VIDEO_ERROR_INPUT_PARAM_ERROR; 
                }
            }
            fgRightState = KAL_TRUE;
        }
        break;

    case VIDEO_PARAM_SOURCE_PROVIDER_ABORT_PROCESS:
        if (eState == VIDEO_STATE_IDLE || eState == VIDEO_STATE_STOP || eState == VIDEO_STATE_RUN)
        {
            SP_PORT_TYPE_T eType = *(SP_PORT_TYPE_T*)pParam;

            if (prPlayInfo->u4ControlFlag[eType] != 0)
            {
               _SourceProviderSetAbortParam(prPlayInfo, prProviderAPI, pvProviderHandle, *(SP_PORT_TYPE_T*)pParam, KAL_TRUE);
            }
            fgRightState = KAL_TRUE;
        }
        break;

    case VIDEO_PARAM_SOURCE_PROVIDER_CHANGE_HIGH_TASK_PRIORITY:
        prSrcProviderMgr->rTaskInfo.eRunTask = SP_V2SRC2;
        prSrcProviderMgr->rTaskInfo.u4TaskMessageID = SP_MESSAGE_ID_2;

        #ifdef __VE_SP_LOG_HIGH__
        drv_trace4(SP_TRACE_HIGH_GROUP, SP_SET_TASK, prSrcProviderMgr->rTaskInfo.eRunTask, prSrcProviderMgr->rTaskInfo.u4TaskMessageID, __LINE__, (kal_uint32)prSrcProviderMgr);
        #endif    
        //Trigger task
        _SourceProviderTriggerTask(prSrcProviderMgr, KAL_FALSE, SOURCE_PROVIDER_MSG_SET_PARAM);

        fgRightState = KAL_TRUE;
        break;

    case VIDEO_PARAM_SOURCE_PROVIDER_EMPTY_FUNC:
        if (eState == VIDEO_STATE_IDLE || eState == VIDEO_STATE_STOP || eState == VIDEO_STATE_INIT)
        {
            prSrcProviderMgr->rMedHandle.prEmptyAPI = (MPL_SESSION_EMPTY_BUFFER_API_T *)pParam;
            fgRightState = KAL_TRUE;
        }
        break;

    case VIDEO_PARAM_SOURCE_PROVIDER_FREE_STREAM_BUFFER:
        if (eState == VIDEO_STATE_STOP || eState == VIDEO_STATE_RUN)
        {
            SP_PORT_TYPE_T eType = *(SP_PORT_TYPE_T*)pParam;
            
            fgRightState = KAL_TRUE;

            if (prPlayInfo->fgSelect[eType] == KAL_TRUE || eType >= SOURCE_PROVIDER_PORT_MAX)
            {
                SP_TRACE_PARAMETER_ERROR(prPlayInfo->fgSelect[eType], eType, 0);
                eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
                break;;
            }
            
            #ifdef __VE_STREAM_SUPPORT__
            if (prSrcInfo->eOpenType == MED_MODE_STREAM)        
            {
                //_SourceProviderFreeStreamBuf(&prSrcProviderMgr->rMemInfo, &prSrcProviderMgr->rMedHandle, eType);

                prPlayInfo->u4ControlFlag[eType] |= SOURCE_PROVIDER_FLAG_FLUSH_STREAM_BUFFER;

                _SourceProviderTriggerTask(prSrcProviderMgr, KAL_FALSE, SOURCE_PROVIDER_MSG_SET_PARAM);

                eError = VIDEO_ERROR_ASYNC_OPERATION;
            }
            else
            #endif  
            {
                eError = VIDEO_ERROR_INPUT_PARAM_ERROR; 
            }
        }
        break;

    default:
        fgRightState = KAL_TRUE;
        eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
        break;
    }

    if (fgRightState == KAL_FALSE)
    {
        //ASSERT(0);
        eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
    }

#ifdef __VE_SP_LOG_FUNC__
    drv_trace4(SP_TRACE_FUNC_GROUP, SP_SET_PARAM, eCmd, eError, eState, (kal_uint32)prSrcProviderMgr);
#endif
    return eError;
}

VIDEO_ERROR_TYPE_T SourceProviderUseBuffer(void* pvHandle, kal_uint8* pBuff, kal_uint32 u4Size)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_DECODER_ERROR;

    return eError;
}

VIDEO_ERROR_TYPE_T SourceProviderEmptyThisBuffer(void* pvHandle, VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
#ifdef __VE_STREAM_SUPPORT__
    SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr = (SRC_PRIVDER_CONTEXT_T *)pvHandle;
    SP_MEM_INFO_T *prSrcProviderMemInfo = (SP_MEM_INFO_T *)&prSrcProviderMgr->rMemInfo; 
    SP_PLAYBACK_INFO_T *prPlayInfo = &prSrcProviderMgr->rPlayInfo;
    #ifdef __VE_SP_PROFILE__
    SP_PROFILE_INFO_T *prProfile = &prSrcProviderMgr->rProfile;
    #endif
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    //kal_bool fgSendMsg = KAL_FALSE;
    //kal_bool fgRet = KAL_FALSE;
    kal_uint32 u4AudioInputPort = VideoCommGetInputPortIndex(&prSrcProviderMgr->rCommState, VIDEO_PORT_AUDIO_DATA);
    kal_uint32 u4VideoInputPort = VideoCommGetInputPortIndex(&prSrcProviderMgr->rCommState, VIDEO_PORT_VIDEO_DATA);
    SP_PORT_TYPE_T ePort = SOURCE_PROVIDER_PORT_MAX;
    VIDEO_BUFFERHEADER_TYPE_T *prNewBufHeader;    
    void *pvNewPayload;
    kal_uint32 u4AllocatedSize, u4Num;
    
    //VIDEO_COMPONENT_PARAM_T *prComParam = VideoCommGetInputComp(&prSrcProviderMgr->rCommState, u4InputPort);
    //kal_uint32 u4TunnelOutputPort = prComParam->u4PortIndex;
#ifdef __VE_SP_LOG_LOW__
    drv_trace8(SP_TRACE_HIGH_GROUP, SP_EMPTY_BUF, prBuffHeader->u4InputPort, (kal_uint32)(prBuffHeader->pu1Buffer), prBuffHeader->u4BuffSize, prBuffHeader->u8TimeStamp, 
                                                                                      prBuffHeader->eFlags, (kal_uint32)prBuffHeader->pPrivateData, 0, (kal_uint32)prSrcProviderMgr);
#endif    

    // when close state, we don't receive buffer
    if (prSrcProviderMgr->rCommState.fgCompClosing == KAL_TRUE)
    {
        return VIDEO_ERROR_BUFF_FULL;
    }

    // Help to do : add header to bitstream buffer and bitstream header
    // audio stream
    if (prBuffHeader->u4InputPort == u4AudioInputPort)
    {
        ePort = SOURCE_PROVIDER_PORT_AUDIO;
    }
    else if (prBuffHeader->u4InputPort == u4VideoInputPort)
    {
        ePort = SOURCE_PROVIDER_PORT_VIDEO;
    }
    else
    {
          ASSERT(0);
          return VIDEO_ERROR_INPUT_PARAM_ERROR;
    }

    if (prSrcProviderMgr->rStreamInfo[ePort].fgSupport == KAL_FALSE)
    {
        return VIDEO_ERROR_INPUT_PARAM_ERROR;
    }

    #ifdef __VE_SP_PROFILE__
    prProfile->u4EmptyCount[ePort]++;
    #endif

     // obtain one buffer header
    prNewBufHeader = (VIDEO_BUFFERHEADER_TYPE_T *)_SourceProviderBufferHeaderGetWriteBuf(&prSrcProviderMemInfo->rBufHeader[ePort]);
    if (prNewBufHeader == NULL)
    {
        #ifdef __VE_SP_PROFILE__
        prProfile->u4HeaderFull[ePort]++;
        #endif
    
#ifdef __VE_SP_LOG_HIGH__
        drv_trace2(SP_TRACE_HIGH_GROUP, SP_EMPTY_BUF_FULL, 1, (kal_uint32)prSrcProviderMgr);
#endif    
        return VIDEO_ERROR_BUFF_FULL;
    }
    kal_mem_cpy(prNewBufHeader, prBuffHeader, sizeof(VIDEO_BUFFERHEADER_TYPE_T));
    prNewBufHeader->u4InputPort = SP_VIDEO_AUDIO_INPUT_PORT;

    if (((kal_uint32)prBuffHeader->eFlags & (kal_uint32)VIDEO_BUFFERFLAG_SILENT) == NULL &&
         ((kal_uint32)prBuffHeader->eFlags & (kal_uint32)VIDEO_BUFFERFLAG_EOF) == NULL)
    {
        u4Num = _SourceProviderBufferHeaderUsedNum(&prSrcProviderMemInfo->rBufHeader[ePort]);

        // clear buffer garbage
        if (u4Num == 0)
        {
            _SourceProviderBitstreamBufReset(&prSrcProviderMemInfo->rBitstreamBuf[ePort]);
        }
        
        // obtain bitstream buffer
        prNewBufHeader->pu1Buffer = (kal_uint8 *)_SourceProviderBitstreamBufGetBuf(&prSrcProviderMemInfo->rBitstreamBuf[ePort], prBuffHeader->u4BuffSize, &u4AllocatedSize);
        if (u4AllocatedSize == 0)
        {
            #ifdef __VE_SP_PROFILE__
            prProfile->u4BitstreamFull[ePort]++;
            #endif
        
#ifdef __VE_SP_LOG_HIGH__
            drv_trace2(SP_TRACE_HIGH_GROUP, SP_EMPTY_BUF_FULL, 2, (kal_uint32)prSrcProviderMgr);
#endif         
            return VIDEO_ERROR_BUFF_FULL;
        }

        // obtain private data buffer
        if (prBuffHeader->pPrivateData != NULL)
        {
            kal_uint32 u4I, u4NewAddr, u4PayloadSize;
            SPIF_H264_DECODER_PAYLOAD_INFO_T *prH264Payload, *prH264NewPayload;     
            SPIF_DECODE_PAYLOAD_T *prPayload,*prDecPayload;
            
            if (ePort == SOURCE_PROVIDER_PORT_AUDIO)
            {
                ASSERT(0);
            }

            prPayload = (SPIF_DECODE_PAYLOAD_T *)prBuffHeader->pPrivateData;
            u4PayloadSize = prPayload->u4PayloadNumber*sizeof(SPIF_H264_DECODER_PAYLOAD_INFO_T);

            pvNewPayload = _SourceProviderPrivateBufGetBuf(&prSrcProviderMemInfo->rPrivateData[ePort], 
                                                           (u4PayloadSize + sizeof(SPIF_DECODE_PAYLOAD_T)));

            if (pvNewPayload == NULL)
            {
                #ifdef __VE_SP_PROFILE__
                prProfile->u4PrivateFull[ePort]++;
                #endif
                
#ifdef __VE_SP_LOG_HIGH__
                 drv_trace2(SP_TRACE_HIGH_GROUP, SP_EMPTY_BUF_FULL, 3, (kal_uint32)prSrcProviderMgr);
#endif             
                return VIDEO_ERROR_BUFF_FULL;
            }

            prDecPayload = (SPIF_DECODE_PAYLOAD_T *)pvNewPayload;
            prDecPayload->u4PayloadNumber = prPayload->u4PayloadNumber;
            prDecPayload->pu1PayloadAddress = (void *)((kal_uint32)pvNewPayload+sizeof(SPIF_DECODE_PAYLOAD_T));
            //kal_mem_cpy(prDecPayload->pu1PayloadAddress, prPayload->pu1PayloadAddress, u4PayloadSize);
            
            prH264Payload = (SPIF_H264_DECODER_PAYLOAD_INFO_T *)prPayload->pu1PayloadAddress;
            prH264NewPayload = (SPIF_H264_DECODER_PAYLOAD_INFO_T *)prDecPayload->pu1PayloadAddress;
            u4NewAddr = (kal_uint32)prNewBufHeader->pu1Buffer;

            for (u4I=prDecPayload->u4PayloadNumber; u4I !=0; u4I--)
            {
                prH264NewPayload->u4Length = prH264Payload->u4Length;
                prH264NewPayload->u4Address = u4NewAddr;                
                kal_mem_cpy((void *)prH264NewPayload->u4Address, (void *)prH264Payload->u4Address, prH264Payload->u4Length);
                u4NewAddr += prH264NewPayload->u4Length;
#ifdef __VE_DUMP_PROVIDER_BITSTREAM__
                if(KAL_FALSE == fgFirst)
                {
                    VEBufferTrace(TRACE_GROUP_1, VE_TRC_VIDEO_BITSTREAM, 4, (kal_uint8 *)au1H264Start);														
                    fgFirst = KAL_TRUE;
                }
                else
                {
                    VEBufferTrace(TRACE_GROUP_1, VE_TRC_VIDEO_BITSTREAM, 3, (kal_uint8 *)au1H264StartCode);									
                }
                VEBufferTrace(TRACE_GROUP_1, VE_TRC_VIDEO_BITSTREAM, prH264NewPayload->u4Length, (kal_uint8 *)prH264NewPayload->u4Address);				
#endif				
                prH264NewPayload++;
                prH264Payload++;
            }

            prNewBufHeader->pPrivateData = pvNewPayload;
        }
        else
        {       
            // copy bitstream
            kal_mem_cpy(prNewBufHeader->pu1Buffer, prBuffHeader->pu1Buffer, prBuffHeader->u4BuffSize);

#ifdef __VE_DUMP_PROVIDER_BITSTREAM__
            if (ePort == SOURCE_PROVIDER_PORT_AUDIO)
            {
                VEBufferTrace(TRACE_GROUP_2, VE_TRC_AUDIO_BITSTREAM, prBuffHeader->u4BuffSize, prBuffHeader->pu1Buffer);				            
            }
            else
            {
                VEBufferTrace(TRACE_GROUP_1, VE_TRC_VIDEO_BITSTREAM, prBuffHeader->u4BuffSize, prBuffHeader->pu1Buffer);				
            }				
#endif 
			
        }
        
        _SourceProviderBitstreamBufUpdataAdd(&prSrcProviderMemInfo->rBitstreamBuf[ePort], (kal_uint32)(prNewBufHeader->pu1Buffer+prBuffHeader->u4BuffSize));
    }

    // updata buffer header
    _SourceProviderBufferHeaderAddWriteBuf(&prSrcProviderMemInfo->rBufHeader[ePort], KAL_TRUE, (prNewBufHeader->u8TimeStamp/1000));

    prPlayInfo->u8CurrentTime[ePort] = prBuffHeader->u8TimeStamp;

    #ifdef __VE_SP_PROFILE__
    {
        kal_uint32 u4Left;
        u4Left = _SourceProviderBitstreamBufTotalLeftSize(&prSrcProviderMemInfo->rBitstreamBuf[ePort]);
        if (u4Left < prProfile->u4MixLeftBitstream[ePort])
        {
            prProfile->u4MixLeftBitstream[ePort] = u4Left;
        }
        u4Left = _SourceProviderBufferHeaderFreeNum(&prSrcProviderMemInfo->rBufHeader[ePort]);
        if (u4Left < prProfile->u4MixLeftHeader[ePort])
        {
            prProfile->u4MixLeftHeader[ePort] = u4Left;
        }
        u4Left = _SourceProviderPrivateBufLeftSize(&prSrcProviderMemInfo->rPrivateData[ePort]);
        if (u4Left < prProfile->u4MixLeftPrivate[ePort])
        {
            prProfile->u4MixLeftPrivate[ePort] = u4Left;
        }
    }
    #endif

    // check buffer full
    if (_SourceProviderStreamingBufferStatus(prSrcProviderMgr, ePort) == KAL_TRUE)
    {
#ifdef __VE_SP_LOG_HIGH__
        drv_trace2(SP_TRACE_HIGH_GROUP, SP_EMPTY_BUF_FULL, 4, (kal_uint32)prSrcProviderMgr);
#endif        
        return VIDEO_ERROR_BUFF_HIGH;
    }

    _SourceProviderTriggerTask(prSrcProviderMgr, KAL_FALSE, SOURCE_PROVIDER_MSG_EMPTYBUFFER);
    
    return eError;
    
#else
    //ASSERT(0);
    return VIDEO_ERROR_INPUT_PARAM_ERROR;
#endif    
}


VIDEO_ERROR_TYPE_T SourceProviderFillThisBuffer(void* pvHandle, VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr = (SRC_PRIVDER_CONTEXT_T *)pvHandle;
    kal_bool fgRet = KAL_FALSE;
    kal_uint32 u4AudioOutputPort = VideoCommGetOutputPortIndex(&prSrcProviderMgr->rCommState, VIDEO_PORT_AUDIO_DATA);
    kal_uint32 u4VideoOutputPort = VideoCommGetOutputPortIndex(&prSrcProviderMgr->rCommState, VIDEO_PORT_VIDEO_DATA);
#ifdef __VE_SUBTITLE_SUPPORT__
    kal_uint32 u4SubtitleOutputPort = VIDEO_PORT_MAX_NUM;
#endif
    //VIDEO_COMPONENT_PARAM_T *prComParam = VideoCommGetOutputComp(&prSrcProviderMgr->rCommState, u4OutputPortIndex);
    //kal_uint32 u4TunneInputPort = prComParam->u4PortIndex;
    kal_bool fgTrigger = KAL_FALSE;

#ifdef __VE_SUBTITLE_SUPPORT__
    #ifdef __VE_STREAM_SUPPORT__
    if (prSrcProviderMgr->rSrcInfo.eOpenType != MED_MODE_STREAM)
    #endif
    {
        u4SubtitleOutputPort = VideoCommGetOutputPortIndex(&prSrcProviderMgr->rCommState, VIDEO_PORT_SUBTITLE);
    }    
#endif

    // when close state, we don't receive buffer
    if (prSrcProviderMgr->rCommState.fgCompClosing == KAL_TRUE)
    {
        return VIDEO_ERROR_BUFF_FULL;
    }

#ifdef __VE_SP_LOG_LOW__
    drv_trace4(SP_TRACE_LOW_GROUP, SP_FILL_BUF, prBuffHeader->u4OutputPort, (kal_uint32)(prBuffHeader->pu1Buffer), prBuffHeader->u8TimeStamp, (kal_uint32)prSrcProviderMgr);
#endif

    // Help to do
    //  from audio or video component
    if (prBuffHeader->u4OutputPort == u4AudioOutputPort)
    {
        if (prBuffHeader->eFlags != VIDEO_BUFFERFLAG_TRIGGER_AUDIO)
        {
            fgRet = VideoCommPushOutputBuff(&prSrcProviderMgr->rCommState, prBuffHeader);        

            // to do: protect by mutux
            #ifdef __VE_SP_DBG__
            prSrcProviderMgr->rDebugInfo.u4ItemOutputQ++;
            #endif
        }
        else
        {
            fgRet = KAL_TRUE;
        }
        fgTrigger = KAL_TRUE;
    }
    else if (prBuffHeader->u4OutputPort == u4VideoOutputPort)
    {
        fgRet = VideoCommPushOutputBuffExt(&prSrcProviderMgr->rCommState, prBuffHeader, SOURCE_PROVIDER_PORT_VIDEO);
        
        if (prBuffHeader->eFlags == VIDEO_BUFFERFLAG_EOF || 
            #ifndef __VE_SP_PROFILE_V_MIN_BUFFER__ 
            #ifdef __VE_SP_HW_DEC_PIPELINE__
            VideoCommQueryOutputBuffExt(&prSrcProviderMgr->rCommState, SOURCE_PROVIDER_PORT_VIDEO)+2 >= _SourceProviderBufferHeaderSendNum(&prSrcProviderMgr->rMemInfo.rBufHeader[SOURCE_PROVIDER_PORT_VIDEO]) || //+2:two frame keep in decode when HW codec
            #else
            VideoCommQueryOutputBuffExt(&prSrcProviderMgr->rCommState, SOURCE_PROVIDER_PORT_VIDEO)+2 >= _SourceProviderBufferHeaderSendNum(&prSrcProviderMgr->rMemInfo.rBufHeader[SOURCE_PROVIDER_PORT_VIDEO]) || //+2: mkae sure that video keep two frame for good performance
            #endif
            VideoCommQueryOutputBuffExt(&prSrcProviderMgr->rCommState, SOURCE_PROVIDER_PORT_VIDEO) == (SOURCE_PROVIDER_OUTPUT_BUFFER_Q_2_LEN-1)
            #else
            KAL_TRUE
            #endif
            )
        {
            fgTrigger = KAL_TRUE;
        }
    }
#ifdef __VE_SUBTITLE_SUPPORT__
    else if (prBuffHeader->u4OutputPort == u4SubtitleOutputPort)
    {
        fgRet = VideoCommPushOutputBuffExt(&prSrcProviderMgr->rCommState, prBuffHeader, SOURCE_PROVIDER_PORT_SUBTITLE);

        if (prBuffHeader->eFlags == VIDEO_BUFFERFLAG_EOF ||
            VideoCommQueryOutputBuffExt(&prSrcProviderMgr->rCommState, SOURCE_PROVIDER_PORT_SUBTITLE) >= _SourceProviderBufferHeaderSendNum(&prSrcProviderMgr->rMemInfo.rBufHeader[SOURCE_PROVIDER_PORT_SUBTITLE]))
        {
            fgTrigger = KAL_TRUE;
        }
    }
#endif
    else
    {
        //ASSERT(0);
        return VIDEO_ERROR_INPUT_PARAM_ERROR;
    }

    if( fgRet == KAL_FALSE)
    {
        // Error handling
#ifdef __VE_SP_LOG_HIGH__
        drv_trace1(SP_TRACE_HIGH_GROUP, SP_FILL_BUF_FULL, (kal_uint32)prSrcProviderMgr);
#endif
        return VIDEO_ERROR_BUFF_FULL;
    }
    else if (fgTrigger == KAL_TRUE)
    {
        _SourceProviderTriggerTask(prSrcProviderMgr, KAL_FALSE, SOURCE_PROVIDER_MSG_FILLBUFFER);
    }

    return VIDEO_ERROR_NONE;
}


VIDEO_ERROR_TYPE_T SourceProviderSetCallbacks(void* pvHandle, VIDEO_CALLBACK_TYPE_T *prCallback)
{
    SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr = (SRC_PRIVDER_CONTEXT_T *)pvHandle;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    eError = VideoCommSetCallbacks(&prSrcProviderMgr->rCommState, prCallback);

#ifdef __VE_SP_LOG_FUNC__
    drv_trace2(SP_TRACE_FUNC_GROUP, SP_SET_CALLBACK, eError, (kal_uint32)pvHandle);
#endif
    return eError;
}


VIDEO_ERROR_TYPE_T SourceProviderDeInit(void* pvHandle)
{
    SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr = (SRC_PRIVDER_CONTEXT_T *)pvHandle;
    //SPIF_PROVIDER_HANDLE_T rPrvHandle = prSrcProviderMgr->rPrvHandle;
    SP_MED_HANDLE_T *prMedHandle = (SP_MED_HANDLE_T *)&prSrcProviderMgr->rMedHandle;
    SP_MEM_INFO_T *prMemInfo = (SP_MEM_INFO_T *) &prSrcProviderMgr->rMemInfo;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

#ifdef __VE_SP_LOG_FUNC__
    drv_trace1(SP_TRACE_FUNC_GROUP, SP_DEINIT, (kal_uint32)pvHandle);
#endif

    // release event
    #ifdef __VE_STREAM_SUPPORT__
    if (prSrcProviderMgr->rSrcInfo.eOpenType == MED_MODE_STREAM)
    {
        VideoFreeMutex(MUTEX_USER_SOURCE_VBUF, prSrcProviderMgr->rSrcVBufHeaderMutex);
        VideoFreeMutex(MUTEX_USER_SOURCE_VBS, prSrcProviderMgr->rSrcVBitstreamMutex);
        VideoFreeMutex(MUTEX_USER_SOURCE_VPRI, prSrcProviderMgr->rSrcVPrivateDataMutex);
        VideoFreeMutex(MUTEX_USER_SOURCE_ABUF, prSrcProviderMgr->rSrcABufHeaderMutex);
        VideoFreeMutex(MUTEX_USER_SOURCE_ABS, prSrcProviderMgr->rSrcABitstreamMutex);
    }
    #endif

    VideoFreeMutex(MUTEX_USER_SOURCE_COMMON, prSrcProviderMgr->rCommState.eMutex);

    // release timer
    VideoFreeTimer(TIMER_USER_SOURCE, prSrcProviderMgr->rTimerID);

    // Common API de-initialization
    eError = VideoCommDeInit(&prSrcProviderMgr->rCommState);
    if(eError != VIDEO_ERROR_NONE)
    {
        SP_TRACE_COMPONENT_ERROR(eError, 0, (kal_uint32)prSrcProviderMgr);
        return eError;
    }

    // release component memory
    VideoDeInitExtBuffer(prMemInfo->prComponentHandle);
    prMedHandle->prAPI->pMemFree(prMedHandle->pvHandle, prMemInfo->pvExtMemComponent, MED_MEM_NONCACHE);

    return eError;
}


static const VIDEO_COMPONENT_MI_TYPE_T rAPIsForMed =
{
    SourceProviderInit,
    SourceProviderSendCommand,
    SourceProviderGetParameter,
    SourceProviderSetParameter,
    SourceProviderUseBuffer,
    SourceProviderEmptyThisBuffer,
    SourceProviderFillThisBuffer,
    SourceProviderSetCallbacks,
    SourceProviderDeInit
};

/*********************************************************
 * External function for MED
 *********************************************************/
VIDEO_ERROR_TYPE_T GetSourceProviderHandle(SPIF_MEDIA_INFO_T *prMediaInfo, void *pvSrcHandle, VIDEO_COMPONENT_MI_TYPE_T **prSrcType)
{
    SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr;
    //VIDEO_EXTMEM_HANDLER_T *prExtHandle;
    SP_MED_HANDLE_T *prMedHandle;
    SP_SOURCE_INFO_T *prSourceInfo;
    SP_TASK_INFO_T *prTaskInfo;
    kal_uint32 *pu4HandleAdd = (kal_uint32 *)pvSrcHandle;
    VIDEO_ERROR_TYPE_T eRet = VIDEO_ERROR_NONE;

#ifdef __VE_SP_LOG_FUNC__
    drv_trace8(SP_TRACE_FUNC_GROUP, SP_GET_HANDLE, prMediaInfo->eTrack, prMediaInfo->eOpenType, prMediaInfo->eFileType, prMediaInfo->u4Size,
                                                                                        SOURCE_PROVIDER_CONTEXT_SIZE, sizeof(SRC_PRIVDER_CONTEXT_T), 0, 0);
#endif

    // obtain context memory
    prSrcProviderMgr = (SRC_PRIVDER_CONTEXT_T *)prMediaInfo->prAPI->pMemAlloc(prMediaInfo->pvHandle, sizeof(SRC_PRIVDER_CONTEXT_T), MED_MEM_CACHE);
    if (prSrcProviderMgr  == NULL)
    {
        SP_TRACE_MEMORY_ERROR(sizeof(SRC_PRIVDER_CONTEXT_T), 0,(kal_uint32)prSrcProviderMgr);
        return VIDEO_ERROR_NO_MEMORY;
    }
    kal_mem_set(prSrcProviderMgr, 0, sizeof(SRC_PRIVDER_CONTEXT_T));

    if (_prSrcProviderMgr == NULL)
    {
        _prSrcProviderMgr = prSrcProviderMgr;
    }
    else if (_prSrcProviderMgr2 == NULL)
    {
        _prSrcProviderMgr2 = prSrcProviderMgr;
    }
    else if (_prSrcProviderMgr3 == NULL)
    {
        _prSrcProviderMgr3 = prSrcProviderMgr;
    }
    else
    {
       ASSERT(0);
    }

    prMedHandle = &prSrcProviderMgr->rMedHandle;
    prSourceInfo = &prSrcProviderMgr->rSrcInfo;

    // obtain MED information
    prMedHandle->pvHandle = prMediaInfo->pvHandle;
    prMedHandle->prAPI = prMediaInfo->prAPI;
    //prMedHandle->prEmptyAPI = prMediaInfo->prEmptyAPI;
    prSrcProviderMgr->eTrack = prMediaInfo->eTrack;

#ifdef __VE_STREAM_CMMB_SUPPORT__
    if (prMediaInfo->eOpenType == MED_MODE_CMMB)
    {
        prSourceInfo->eOpenType = MED_MODE_STREAM;
    }
    else
#endif     
    {
        prSourceInfo->eOpenType = prMediaInfo->eOpenType;
    }    

#ifdef __VE_STREAM_SUPPORT__
    if (prSrcProviderMgr->rSrcInfo.eOpenType == MED_MODE_STREAM)
    {
        prSourceInfo->eFileType = SOURCE_PROVIDER_STREAMING;
    }
    else
#endif
    {        
        prSourceInfo->eFileType = prMediaInfo->eFileType;
    
        if (prSourceInfo->eOpenType == MED_MODE_BUFFER)
        {
            prSourceInfo->u_src.rBuf.u4Addr = (kal_uint32)prMediaInfo->pu1Data;
            prSourceInfo->u_src.rBuf.u4Size = prMediaInfo->u4Size;
        }
        else
        {
            if (prMediaInfo->u4Size > SP_MAX_FILE_NAME_LEN )
            {
                eRet = VIDEO_ERROR_GET_HANDLE_ERROR;
                goto GET_HANDLE_ERROR;
            }
            else
            {
                //#if (defined(__VE_SP_LOG_FUNC__) && !defined(__VE_SP_SLIM__))
                char *pu1FileName;
                //#endif
                
                kal_mem_cpy(prSourceInfo->u_src.file_name, prMediaInfo->pu1Data, (prMediaInfo->u4Size * sizeof(kal_wchar)));

                //#if (defined(__VE_SP_LOG_FUNC__) && !defined(__VE_SP_SLIM__))
                pu1FileName = (char *)prMediaInfo->prAPI->pMemAlloc(prMediaInfo->pvHandle, SP_MAX_FILE_NAME_LEN, MED_MEM_NONCACHE);
                if (pu1FileName  == NULL)
                {
                    SP_TRACE_MEMORY_ERROR(SP_MAX_FILE_NAME_LEN, 0,(kal_uint32)prSrcProviderMgr);
                    goto GET_HANDLE_ERROR;
                }
                kal_dchar2char((WCHAR *)prMediaInfo->pu1Data, pu1FileName);
                kal_print_string_trace(MOD_VIDEO, TRACE_FUNC, "[SP][FILE NAME] %s", pu1FileName);
                prMediaInfo->prAPI->pMemFree(prMediaInfo->pvHandle, pu1FileName, MED_MEM_NONCACHE);
                //#endif
            }
        }

        // check file data is match with file extension
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
#else
        //prSrcProviderMgr->eRealFileType = prSrcProviderMgr->rSrcInfo.eFileType;
#endif
    }

    //  change task to high priority
    prTaskInfo = &prSrcProviderMgr->rTaskInfo;
    if (prSrcProviderMgr->eTrack == SOURCE_PROVIDER_TRACK_AUDIO)
    {
        prTaskInfo->eRunTask = SP_V2SRC2;
        prTaskInfo->u4TaskMessageID = SP_MESSAGE_ID_2;
    }
    else
    {
        prTaskInfo->eRunTask = SP_V2SRC1;
        prTaskInfo->u4TaskMessageID = SP_MESSAGE_ID_1;
    }
    #ifdef __VE_SP_LOG_HIGH__
    drv_trace4(SP_TRACE_HIGH_GROUP, SP_SET_TASK, prTaskInfo->eRunTask, prTaskInfo->u4TaskMessageID, __LINE__, (kal_uint32)prSrcProviderMgr);
    #endif    

    // query memory requirement
    if (_SourceProviderObtainMemInfo(prSourceInfo->eFileType, &prSrcProviderMgr->rPrvReqMem, prSourceInfo->eOpenType, prMediaInfo->eTrack) != SOURCE_PROVIDER_ERROR_NONE)
    {
        eRet = VIDEO_ERROR_GET_HANDLE_ERROR;
        goto GET_HANDLE_ERROR;
    }

    // component init
    eRet = rAPIsForMed.pfnInit(prSrcProviderMgr);
    if (eRet != VIDEO_ERROR_NONE)
    {
        goto GET_HANDLE_ERROR;
    }

    // set output value
    //prSrcHandle->prComp = (VIDEO_COMPONENT_MI_TYPE_T*)&rAPIsForMed;
    *pu4HandleAdd = (kal_uint32)prSrcProviderMgr;
    *prSrcType = (VIDEO_COMPONENT_MI_TYPE_T *)&rAPIsForMed;

    return eRet;

GET_HANDLE_ERROR:
    // reset global variable
    if (_prSrcProviderMgr == prSrcProviderMgr)
    {
        _prSrcProviderMgr = NULL;
    }
    else if (_prSrcProviderMgr2 == prSrcProviderMgr)
    {
        _prSrcProviderMgr2 = NULL;
    }
    else if (_prSrcProviderMgr3 == prSrcProviderMgr)
    {
        _prSrcProviderMgr3 = NULL;
    }    
    else
    {
       ASSERT(0);
    }
    
    // release handle memory
    prMediaInfo->prAPI->pMemFree(prMediaInfo->pvHandle, prSrcProviderMgr, MED_MEM_CACHE);
            
    return eRet;
}

VIDEO_ERROR_TYPE_T ReleaseSourceProviderHandle(void *pvHandle)
{
    SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr = (SRC_PRIVDER_CONTEXT_T *)pvHandle;
    SP_MED_HANDLE_T *prMedHandle = (SP_MED_HANDLE_T *)&prSrcProviderMgr->rMedHandle;

#ifdef __VE_SP_LOG_FUNC__
    drv_trace1(SP_TRACE_FUNC_GROUP, SP_RELEASE_HANDLE, (kal_uint32)pvHandle);
#endif

    // component init
    if (rAPIsForMed.pfnDeInit(prSrcProviderMgr) != VIDEO_ERROR_NONE)
    {
        return VIDEO_ERROR_DEINIT_ERROR;
    }

    if (_prSrcProviderMgr == prSrcProviderMgr)
    {
        _prSrcProviderMgr = NULL;
    }
    else if (_prSrcProviderMgr2 == prSrcProviderMgr)
    {
        _prSrcProviderMgr2 = NULL;
    }
    else if (_prSrcProviderMgr3 == prSrcProviderMgr)
    {
        _prSrcProviderMgr3 = NULL;
    }    
    else
    {
       ASSERT(0);
    }

    #ifdef __VE_SP_PROFILE__
    {
        SP_PROFILE_INFO_T *prProfile = &prSrcProviderMgr->rProfile;
        kal_uint32 u4I;
        for (u4I=0; u4I<SOURCE_PROVIDER_PORT_MAX; u4I++)
        {
            drv_trace8(SP_TRACE_FUNC_GROUP, SP_STREAM_PROFILE, u4I, prProfile->u4EmptyCount[u4I], prProfile->u4HeaderFull[u4I], prProfile->u4PrivateFull[u4I], prProfile->u4BitstreamFull[u4I],
                                                                                                   prProfile->u4MixLeftHeader[u4I], prProfile->u4MixLeftPrivate[u4I], prProfile->u4MixLeftBitstream[u4I]);
            drv_trace8(SP_TRACE_FUNC_GROUP, SP_PARSER_PROFILE, u4I, prProfile->u4ExitEntry[u4I], prProfile->u4ExitCount[u4I], prProfile->u4ExitTimer[u4I], prProfile->u4ExitData[u4I],
                                                                                                   prProfile->u4ExitBufferlow[u4I], prProfile->u4ExitOther[u4I], prProfile->u4ExitOtherWaitRes[u4I]);                                                                                                   
        }

        drv_trace8(SP_TRACE_FUNC_GROUP, SP_TRIGGER_PROFILE, prProfile->u4Tirgger[0], prProfile->u4Tirgger[1], prProfile->u4Tirgger[2],  prProfile->u4Tirgger[3],
                                                            prProfile->u4Tirgger[4], prProfile->u4Tirgger[5], 0, 0);
    }
    #endif 

    // release handle memory
    prMedHandle->prAPI->pMemFree(prMedHandle->pvHandle, pvHandle, MED_MEM_CACHE);

    return VIDEO_ERROR_NONE;
}

/*********************************************************
 * function for provider
 *********************************************************/

void *SourceProviderMemSet(void *pVoid, kal_int32 u4Value, kal_uint32 u4Size)
{
    void *pDest = NULL;

    if (pVoid != NULL)
    {
        pDest = kal_mem_set(pVoid,u4Value,u4Size);
    }
    return pDest;
}

void SourceProviderMemCopy(void *pDest, void *pSrc, kal_uint32 u4Size)
{
    kal_mem_cpy(pDest, pSrc, u4Size);
}

void* SourceProviderMallocCacheLineAlign(void * pvHandle, kal_uint32 u4Size, kal_bool fgCacheable)
{
    SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr = (SRC_PRIVDER_CONTEXT_T *)pvHandle;
    void *pVoid;
    kal_uint32 u4MemSize = 0;

    //Make sure all the allocation chche line aligned
    u4MemSize = SP_ROUND_UP_TO_POWER_OF_TWO(u4Size, SP_CPU_CACHE_LINE_SIZE);

    if (fgCacheable == KAL_TRUE)
    {
        pVoid =  kal_adm_alloc_cacheable(prSrcProviderMgr->rMemInfo.rSrcPrvAdmId, u4MemSize, SP_CPU_CACHE_LINE_SIZE);
    }
    else
    {
        pVoid =  kal_adm_alloc_noncacheable(prSrcProviderMgr->rMemInfo.rSrcPrvAdmId, u4MemSize, SP_CPU_CACHE_LINE_SIZE);
    }

    if (pVoid == NULL)
    {
        kal_uint32 u4LeftSize = kal_adm_get_total_left_size(prSrcProviderMgr->rMemInfo.rSrcPrvAdmId);
#ifdef __VE_SP_LOG_LOW__
        drv_trace4(SP_TRACE_LOW_GROUP, SP_CORE_ERROR, u4Size, fgCacheable, u4LeftSize, (kal_uint32)prSrcProviderMgr);
#endif
        //ASSERT(0);
    }

#ifdef __VE_SP_LOG_LOW__
    drv_trace4(SP_TRACE_LOW_GROUP, SP_CORE_MALLOC, u4Size, fgCacheable, (kal_uint32)pVoid, (kal_uint32)prSrcProviderMgr);
#endif

    return (void*)(pVoid);
}

void SourceProviderFreeCacheLineAlign(void * pvHandle, void *pVoid)
{
    SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr = (SRC_PRIVDER_CONTEXT_T *)pvHandle;

#ifdef __VE_SP_LOG_LOW__
    drv_trace2(SP_TRACE_LOW_GROUP, SP_CORE_MFREE, (kal_uint32)pVoid,  (kal_uint32)prSrcProviderMgr);
#endif

    if (NULL != pVoid)
    {
        kal_adm_free(prSrcProviderMgr->rMemInfo.rSrcPrvAdmId, (kal_uint8*)pVoid);
    }
}

kal_uint32 SourceProviderBitstreamBufSize(void * pvHandle, SP_PORT_TYPE_T ePort)
{
/*
    SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr = (SRC_PRIVDER_CONTEXT_T *)pvHandle;

    if (ePort == SOURCE_PROVIDER_PORT_AUDIO)
    {
        return prSrcProviderMgr->rPrvReqMem.u4AudioMem;
    }
    else
    {
        return prSrcProviderMgr->rPrvReqMem.u4VideoMem;
    }
*/
    SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr = (SRC_PRIVDER_CONTEXT_T *)pvHandle;

    return _SourceProviderBitstreamBufAllocatedSize(&prSrcProviderMgr->rMemInfo.rBitstreamBuf[ePort]);
}

kal_uint32 SourceProviderBitstreamBufQueryAvailableSize(void * pvHandle, SP_PORT_TYPE_T ePort, kal_uint32 u4RequiredSize, kal_uint32 *u4AllocatedSize)
{
    kal_uint32 u4Addr, u4Num;   

    SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr = (SRC_PRIVDER_CONTEXT_T *)pvHandle;
    SP_MEM_INFO_T *prMemInfo = &prSrcProviderMgr->rMemInfo;

    u4Num = _SourceProviderBufferHeaderUsedNum(&prMemInfo->rBufHeader[ePort]);

    // clear buffer garbage
    if (u4Num == 0)
    {
        _SourceProviderBitstreamBufReset(&prMemInfo->rBitstreamBuf[ePort]);
    }

    u4Addr = _SourceProviderBitstreamBufGetBuf(&prMemInfo->rBitstreamBuf[ePort], u4RequiredSize, u4AllocatedSize);

#ifdef __VE_SP_PROFILE__
    if (u4Addr == 0)
    {
        prSrcProviderMgr->rProfile.u4BitstreamFull[ePort]++;
    }
#endif

#ifdef __VE_SP_LOG_LOW__
    drv_trace8(SP_TRACE_LOW_GROUP, SP_BS_BUF_Q_SIZE, ePort, u4RequiredSize, *u4AllocatedSize, u4Addr, 0, 0, 0, (kal_uint32)prSrcProviderMgr);
#endif

    return u4Addr;
}

void SourceProviderBitstreamBufUpdataAdd(void * pvHandle, SP_PORT_TYPE_T ePort, kal_uint32 u4Add)
{
    SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr = (SRC_PRIVDER_CONTEXT_T *)pvHandle;

#ifdef __VE_SP_LOG_LOW__
    drv_trace4(SP_TRACE_LOW_GROUP, SP_BS_BUF_UPDATA_ADD, ePort, u4Add, 0, (kal_uint32)prSrcProviderMgr);
#endif

    _SourceProviderBitstreamBufUpdataAdd(&prSrcProviderMgr->rMemInfo.rBitstreamBuf[ePort], u4Add);
}

PROVIDER_ERROR_T SourceProviderAddOneData(void * pvHandle, SP_PORT_TYPE_T ePort, SPIF_PROVIDER_FRAME_INFO_T *prFrameInfo)
{
    SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr = (SRC_PRIVDER_CONTEXT_T *)pvHandle;
    SP_MEM_INFO_T *prSrcProviderMemInfo = (SP_MEM_INFO_T *)&prSrcProviderMgr->rMemInfo;
    SP_PLAYBACK_INFO_T *prPlayInfo = &prSrcProviderMgr->rPlayInfo;
    VIDEO_BUFFERHEADER_TYPE_T *pr1BufHeader;
    void *pvPayload;
    SPIF_DECODE_PAYLOAD_T *prDecPayload;
    #ifdef __VE_SP_PROFILE__
    SP_PROFILE_INFO_T *prProfile = &prSrcProviderMgr->rProfile;
    #endif

    // obtain one buffer header
    pr1BufHeader = (VIDEO_BUFFERHEADER_TYPE_T *)_SourceProviderBufferHeaderGetWriteBuf(&prSrcProviderMemInfo->rBufHeader[ePort]);
    if (pr1BufHeader == NULL)
    {
        #ifdef __VE_SP_PROFILE__
        prProfile->u4HeaderFull[ePort]++;
        #endif
        return PROVIDER_ERROR_WAIT_RESOURCE;
    }

    kal_mem_set((void *)pr1BufHeader, 0, sizeof(VIDEO_BUFFERHEADER_TYPE_T));

    // obtain private data buffer
#ifdef __VE_KMV_SUPPORT__ 
    if (prFrameInfo->u4PayloadSize != 0 || prFrameInfo->u4KMVPayloadSize != 0)
    {
        if (ePort == SOURCE_PROVIDER_PORT_AUDIO)
        {
            ASSERT(0);
        }

		pvPayload = _SourceProviderPrivateBufGetBuf(&prSrcProviderMemInfo->rPrivateData[ePort], (prFrameInfo->u4PayloadSize +
                                                                                                 prFrameInfo->u4KMVPayloadSize +
		                                                                                         sizeof(SPIF_DECODE_PAYLOAD_T)));
		if (pvPayload == NULL)
        {
            #ifdef __VE_SP_PROFILE__
            prProfile->u4PrivateFull[ePort]++;
            #endif
            return PROVIDER_ERROR_WAIT_RESOURCE;
        }

        prDecPayload = (SPIF_DECODE_PAYLOAD_T *)pvPayload;
		prDecPayload->u4PayloadNumber = prFrameInfo->u4PayloadNum;
		if(prFrameInfo->u4PayloadSize != 0)
		{	        
	        prDecPayload->pu1PayloadAddress = (void *)((kal_uint32)pvPayload+sizeof(SPIF_DECODE_PAYLOAD_T));
	        kal_mem_cpy(prDecPayload->pu1PayloadAddress, prFrameInfo->pu1Payload, prFrameInfo->u4PayloadSize);
		}
		else
	    {
	        prDecPayload->pu1PayloadAddress = NULL;
	    }

        prDecPayload->u4KMVSize = prFrameInfo->u4KMVPayloadSize;
		if (prFrameInfo->u4KMVPayloadSize != 0)
		{
		    prDecPayload->pu1KMVPayloadAddress = (void *)((kal_uint32)pvPayload+sizeof(SPIF_DECODE_PAYLOAD_T)+prFrameInfo->u4PayloadSize);
			kal_mem_cpy(prDecPayload->pu1KMVPayloadAddress, prFrameInfo->pu1KMVPayload, prFrameInfo->u4KMVPayloadSize);
	    }
		else
		{
		    prDecPayload->pu1KMVPayloadAddress = NULL;
		}

		pr1BufHeader->pPrivateData = pvPayload;
    }
#else
    if (prFrameInfo->u4PayloadSize != 0)
    {
        if (ePort == SOURCE_PROVIDER_PORT_AUDIO)
        {
            ASSERT(0);
        }

        pvPayload = _SourceProviderPrivateBufGetBuf(&prSrcProviderMemInfo->rPrivateData[ePort], (prFrameInfo->u4PayloadSize+sizeof(SPIF_DECODE_PAYLOAD_T)));

        if (pvPayload == NULL)
        {
            #ifdef __VE_SP_PROFILE__
            prProfile->u4PrivateFull[ePort]++;
            #endif
            return PROVIDER_ERROR_WAIT_RESOURCE;
        }

        prDecPayload = (SPIF_DECODE_PAYLOAD_T *)pvPayload;
        prDecPayload->u4PayloadNumber = prFrameInfo->u4PayloadNum;
        prDecPayload->pu1PayloadAddress = (void *)((kal_uint32)pvPayload+sizeof(SPIF_DECODE_PAYLOAD_T));
        kal_mem_cpy(prDecPayload->pu1PayloadAddress, prFrameInfo->pu1Payload, prFrameInfo->u4PayloadSize);

        pr1BufHeader->pPrivateData = pvPayload;
    }
#endif

    #ifdef __VE_SP_PROFILE__
    prProfile->u4EmptyCount[ePort]++;
    #endif

    pr1BufHeader->pu1Buffer = prFrameInfo->pu1Addr;
    pr1BufHeader->u4BuffSize = prFrameInfo->u4FrameSize;
    pr1BufHeader->u8TimeStamp = prFrameInfo->u8Timestamp * 1000;

#ifdef __VE_SP_LOG_HIGH__
        drv_trace8(SP_TRACE_HIGH_GROUP, SP_ADD_ONE_DATA1, ePort, (kal_uint32)pr1BufHeader, pr1BufHeader->u8TimeStamp, 
                                                                                                   prFrameInfo->fgKeyFrame, prFrameInfo->fgHeader,
                                                                                                   prFrameInfo->fgEof, prFrameInfo->fgSilent, (kal_uint32)prSrcProviderMgr);
#endif
#ifdef __VE_SP_AVI_LOG_LOW__
        drv_trace4(SP_TRACE_LOW_GROUP, SP_ADD_ONE_DATA2, (kal_uint32)prFrameInfo->pu1Addr, prFrameInfo->u4FrameSize,
                                                                                                   prFrameInfo->u4PayloadNum, prFrameInfo->u4PayloadSize);
#endif


    switch (ePort)
    {
    case SOURCE_PROVIDER_PORT_AUDIO:
        {
            pr1BufHeader->u4InputPort = SP_VIDEO_AUDIO_INPUT_PORT;
            pr1BufHeader->u4OutputPort = SOURCE_PROVIDER_PORT_AUDIO;

            // set flag
            if (prFrameInfo->fgEof == KAL_TRUE)
            {
                pr1BufHeader->eFlags |= VIDEO_BUFFERFLAG_EOF;
            }
            else
            {
                if (prFrameInfo->fgSilent == KAL_TRUE)
                {
                    pr1BufHeader->eFlags |= VIDEO_BUFFERFLAG_SILENT;
                }
                if (prFrameInfo->fgKeyFrame == KAL_TRUE)
                {
                    pr1BufHeader->eFlags |= VIDEO_BUFFERFLAG_SYNCFRAME;
                }
            }
#ifdef __VE_DUMP_PROVIDER_BITSTREAM__
            VEBufferTrace(TRACE_GROUP_2, VE_TRC_AUDIO_BITSTREAM, pr1BufHeader->u4BuffSize, pr1BufHeader->pu1Buffer);
#endif 	
        }
        break;

    case SOURCE_PROVIDER_PORT_VIDEO:
        {
            pr1BufHeader->u4InputPort = SP_VIDEO_AUDIO_INPUT_PORT;
            pr1BufHeader->u4OutputPort = SOURCE_PROVIDER_PORT_VIDEO;

            // set flag
            if (prFrameInfo->fgEof == KAL_TRUE)
            {
                pr1BufHeader->eFlags |= VIDEO_BUFFERFLAG_EOF;
            }
            else
            {
                if (prFrameInfo->fgKeyFrame == KAL_TRUE)
                {
                    pr1BufHeader->eFlags |= VIDEO_BUFFERFLAG_SYNCFRAME;                
                }

                if (prFrameInfo->fgHeader == KAL_TRUE)
                {
                    pr1BufHeader->eFlags |= VIDEO_BUFFERFLAG_PARAMETERSET;
                }
                else // for video clipper
                {
                    pr1BufHeader->eFlags |= VIDEO_BUFFERFLAG_END_OF_FRAME;
                }
            }

            // notify VFC for a new frame found                    
            VFC_IOCtrl(VFC_OP_SRC_FRAME_ADDED, pr1BufHeader, NULL, NULL);
#ifdef __VE_DUMP_PROVIDER_BITSTREAM__
            VEBufferTrace(TRACE_GROUP_1, VE_TRC_VIDEO_BITSTREAM, pr1BufHeader->u4BuffSize, pr1BufHeader->pu1Buffer);
#endif            
        }
        break;

#ifdef __VE_SUBTITLE_SUPPORT__
    case SOURCE_PROVIDER_PORT_SUBTITLE:
        {
            pr1BufHeader->u4InputPort = SP_VIDEO_AUDIO_INPUT_PORT;
            pr1BufHeader->u4OutputPort = SOURCE_PROVIDER_PORT_SUBTITLE;

            // set flag
            if (prFrameInfo->fgKeyFrame == KAL_TRUE)
            {
                pr1BufHeader->eFlags |= VIDEO_BUFFERFLAG_SYNCFRAME;
            }
            else if (prFrameInfo->fgEof == KAL_TRUE)
            {
                pr1BufHeader->eFlags |= VIDEO_BUFFERFLAG_EOF;
            }
            else if (prFrameInfo->fgSilent == KAL_TRUE)
            {
                pr1BufHeader->eFlags |= VIDEO_BUFFERFLAG_SILENT;
            }
            else if (prFrameInfo->fgHeader == KAL_TRUE)
            {
                pr1BufHeader->eFlags |= VIDEO_BUFFERFLAG_PARAMETERSET;
            }
#ifdef __VE_DUMP_PROVIDER_BITSTREAM__
            VEBufferTrace(TRACE_GROUP_3, VE_TRC_SUBTITLE_BITSTREAM, pr1BufHeader->u4BuffSize, pr1BufHeader->pu1Buffer);
#endif 
			
        }
        break;
#endif

    default:
        ASSERT(0);
        break;
    }

    // updata buffer header
    _SourceProviderBufferHeaderAddWriteBuf(&prSrcProviderMemInfo->rBufHeader[ePort], prFrameInfo->fgKeyFrame, prFrameInfo->u8Timestamp);
    
    prPlayInfo->u8CurrentTime[ePort] = prFrameInfo->u8Timestamp;

    #ifdef __VE_SP_PROFILE__
    {
        kal_uint32 u4Left;
        u4Left = _SourceProviderBitstreamBufTotalLeftSize(&prSrcProviderMemInfo->rBitstreamBuf[ePort]);
        if (u4Left < prProfile->u4MixLeftBitstream[ePort])
        {
            prProfile->u4MixLeftBitstream[ePort] = u4Left;
        }
        u4Left = _SourceProviderBufferHeaderFreeNum(&prSrcProviderMemInfo->rBufHeader[ePort]);
        if (u4Left < prProfile->u4MixLeftHeader[ePort])
        {
            prProfile->u4MixLeftHeader[ePort] = u4Left;
        }
        u4Left = _SourceProviderPrivateBufLeftSize(&prSrcProviderMemInfo->rPrivateData[ePort]);
        if (u4Left < prProfile->u4MixLeftPrivate[ePort])
        {
            prProfile->u4MixLeftPrivate[ePort] = u4Left;
        }
    }
    #endif

    return PROVIDER_ERROR_NONE;
}

PROVIDER_ERROR_T SourceProviderBaseFileOpen(SPIF_OPEN_INFO_T *rOpenInfo)
{
   if ( _SourceProviderBaseFileOpen(KAL_FALSE, rOpenInfo) != SOURCE_PROVIDER_ERROR_NONE)
   {
       return PROVIDER_ERROR;
   }

   return PROVIDER_ERROR_NONE;
}

static const SP_API_T rAPIsForPrv =
{
    SourceProviderMemSet,
    SourceProviderMemCopy,
    SourceProviderMallocCacheLineAlign,
    SourceProviderFreeCacheLineAlign,
    SourceProviderBitstreamBufSize,
    SourceProviderBitstreamBufQueryAvailableSize,
    SourceProviderBitstreamBufUpdataAdd,
    SourceProviderAddOneData,
    SourceProviderBaseFileOpen
};

#ifdef __VE_DCM_WITH_COMPRESSION__
#pragma arm section code, rodata
#endif

#ifdef __VE_STREAM_SUPPORT__
static kal_bool _SourceProviderStreamingBufferStatus(SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr, SP_PORT_TYPE_T ePort)
{
    kal_uint32 u4LeftBitstreamBuf = 0, u4LeftPrivateData = 0, u4LeftBufferHeader = 0;
    SP_MEM_INFO_T *prSrcProviderMemInfo = (SP_MEM_INFO_T *)&prSrcProviderMgr->rMemInfo;
    SP_PARSER_PARAM_T *prPrvParserParam = prSrcProviderMgr->prPrvParserParam;
    kal_bool fgBufferHigh = KAL_FALSE;
    
    if (ePort == SOURCE_PROVIDER_PORT_AUDIO)
    {
        u4LeftBitstreamBuf = prPrvParserParam->u4ALeftBitstreamBuf;
        u4LeftPrivateData = prPrvParserParam->u4ALeftPrivateData;
        u4LeftBufferHeader = SOURCE_PROVIDER_STREAMING_A_BUF_HEADER_LEN>>2;
    }
    else if (ePort == SOURCE_PROVIDER_PORT_VIDEO)
    {
        u4LeftBitstreamBuf = prPrvParserParam->u4VLeftBitstreamBuf;
        u4LeftPrivateData = prPrvParserParam->u4VLeftPrivateData;
        u4LeftBufferHeader = SOURCE_PROVIDER_STREAMING_V_BUF_HEADER_LEN>>2;
    }
    else
    {
        ASSERT(0);
    }

#ifdef __VE_SP_LOG_LOW__
    drv_trace8(SP_TRACE_LOW_GROUP, SP_STREAMING_BUF, ePort, 
                                                    _SourceProviderBitstreamBufTotalLeftSize(&prSrcProviderMemInfo->rBitstreamBuf[ePort]),
                                                    _SourceProviderBufferHeaderFreeNum(&prSrcProviderMemInfo->rBufHeader[ePort]),
                                                    _SourceProviderPrivateBufLeftSize(&prSrcProviderMemInfo->rPrivateData[ePort]),
                                                    u4LeftBitstreamBuf, u4LeftBufferHeader, u4LeftPrivateData, (kal_uint32)prSrcProviderMgr);
#endif    

    if((_SourceProviderBitstreamBufTotalLeftSize(&prSrcProviderMemInfo->rBitstreamBuf[ePort]) < u4LeftBitstreamBuf) ||    //for read performance
        (_SourceProviderBufferHeaderFreeNum(&prSrcProviderMemInfo->rBufHeader[ePort]) <= u4LeftBufferHeader) ||
        (_SourceProviderPrivateBufLeftSize(&prSrcProviderMemInfo->rPrivateData[ePort]) < u4LeftPrivateData)) // at least one private data
    {
        fgBufferHigh = KAL_TRUE;
    }

    return fgBufferHigh;
}
#endif

void SourceProviderSrcMain(ilm_struct *prIlm)
{        
    VIDEO_START_LOGGING("SP");
#if 0
#if defined(__MTK_TARGET__)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
    {
        SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr;
        SP_IND_T *prMsg;
        kal_bool fgClose = KAL_FALSE;

        prMsg = (SP_IND_T *)prIlm->local_para_ptr;
        prSrcProviderMgr = (SRC_PRIVDER_CONTEXT_T *)prMsg->prHandle;

        if (prSrcProviderMgr->rTaskInfo.eRunTask == stack_get_active_module_id())
        {
            fgClose = _SourceProviderDataHdlr(prSrcProviderMgr);
            if (fgClose == KAL_TRUE)
            {
                VideoCommChangeState(&prSrcProviderMgr->rCommState, VIDEO_STATE_CLOSE);
            }
        }
        else
        {
            #ifdef __VE_SP_LOG_HIGH__
            drv_trace4(SP_TRACE_HIGH_GROUP, SP_SKIP_TASK, prSrcProviderMgr->rTaskInfo.eRunTask, stack_get_active_module_id(), __LINE__, (kal_uint32)prSrcProviderMgr);
            #endif  
        }
    }

    VIDEO_STOP_LOGGING("SP");
}

SP_FILE_TYPE_T SourceProviderContainerType(med_mode_enum eOpenType, kal_uint8* pu1Data, kal_uint32 u4Size)
{
    kal_uint8 u1Buf[SP_CHK_INTEGRITY_BUF_LEN];
    STFSAL rFile;
    FSAL_Status eFsalRet;
    SP_FILE_TYPE_T eRet = SOURCE_PROVIDER_MAX;

#ifdef __VE_SP_LOG_FUNC__
    drv_trace4(SP_TRACE_FUNC_GROUP, SP_CONTAINER_TYPE, eOpenType, (kal_uint32)pu1Data, u4Size, 0);
#endif

    if (eOpenType != MED_MODE_BUFFER) // from file
    {
        eFsalRet = FSAL_Open(&rFile, (void*)pu1Data, FSAL_READ);
        if (eFsalRet != FSAL_OK)
        {
            SP_TRACE_FSAL_ERROR(eFsalRet, 0, 0);
            goto OBT_E2;
        }
    }
    else
    {
        FSAL_Direct_SetRamFileSize(&rFile, u4Size);
        eFsalRet = FSAL_Open(&rFile, (void*)pu1Data, FSAL_ROMFILE);
        if (eFsalRet != FSAL_OK)
        {
            SP_TRACE_FSAL_ERROR(eFsalRet, 0, 0);
            goto OBT_E2;
        }
    }

    eFsalRet = FSAL_Read(&rFile, &u1Buf[0], SP_CHK_INTEGRITY_BUF_LEN);
    if (eFsalRet != FSAL_OK)
    {
        SP_TRACE_FSAL_ERROR(eFsalRet, 0, 1);
        goto OBT_E1;
    }

#ifdef __VE_MOT_DECRYPTION__
    eRet = _SourceProviderObtainContainerType(eOpenType, &u1Buf[0], SP_CHK_INTEGRITY_BUF_LEN);
#else
    eRet = _SourceProviderObtainContainerType(&u1Buf[0], SP_CHK_INTEGRITY_BUF_LEN);
#endif
    if (eRet == SOURCE_PROVIDER_MAX)
    {
        goto OBT_E1;
    }

OBT_E1:
    FSAL_Close(&rFile);

OBT_E2:

    return eRet;
}

VIDEO_ERROR_TYPE_T SourceProviderStreamingAddHeader(void* pvHandle, SP_PORT_TYPE_T eType, media_dec_config_t *prConfig)
{
    VIDEO_ERROR_TYPE_T rRet = VIDEO_ERROR_NONE;
    
#ifdef __VE_STREAM_SUPPORT__
    VIDEO_BUFFERHEADER_TYPE_T rBuffHeader;
    kal_bool fgSendHeader = KAL_FALSE;

    kal_mem_set((void *)&rBuffHeader, 0, sizeof(VIDEO_BUFFERHEADER_TYPE_T));

    if (eType ==  SOURCE_PROVIDER_PORT_VIDEO)
    {
        switch (prConfig->codec)
        {
        case MEDIA_CODEC_VID_MPEG4:
            rBuffHeader.pu1Buffer = prConfig->u.mpeg4.pu1VOS;
            rBuffHeader.u4BuffSize= prConfig->u.mpeg4.u4VOSSize;
            fgSendHeader = KAL_TRUE;
            break;

        case MEDIA_CODEC_VID_H264:
            rBuffHeader.pu1Buffer = prConfig->u.h264.pu1Buffer;
            rBuffHeader.u4BuffSize= prConfig->u.h264.u4BuffSize;
            rBuffHeader.pPrivateData = prConfig->u.h264.pPrivateData;
            fgSendHeader = KAL_TRUE;
            break;            

        default:
            break;
        }

        if (fgSendHeader == KAL_TRUE)
        {
            rBuffHeader.eFlags = VIDEO_BUFFERFLAG_PARAMETERSET;
            rBuffHeader.u4InputPort = eType;
            rBuffHeader.u4OutputPort = eType;         
            rRet = SourceProviderEmptyThisBuffer(pvHandle, &rBuffHeader);
        }
    }
    else
    {
        ASSERT(0);
    }
    
#else
    //ASSERT(0);
    rRet = VIDEO_ERROR_INPUT_PARAM_ERROR;
#endif

    return rRet;
}

VIDEO_ERROR_TYPE_T SourceProviderStreamingAddData(void* pvHandle, SP_PORT_TYPE_T eType, media_data_t *prData, SPIF_STREAMING_SILENT_INFO_T *prSilentInfo)
{
    VIDEO_ERROR_TYPE_T rRet = VIDEO_ERROR_NONE;

#ifdef __VE_STREAM_SUPPORT__
    VIDEO_BUFFERHEADER_TYPE_T rBuffHeader;
    //kal_bool fgSendHeader = KAL_FALSE;

    // process silent case
    if (prSilentInfo != NULL)
    {
        if (prData->display_time > prSilentInfo->u8LastTime &&
            prData->display_time - prSilentInfo->u8LastTime >= prSilentInfo->u4PredictionLength*2)
        {
            kal_mem_set((void *)&rBuffHeader, 0, sizeof(VIDEO_BUFFERHEADER_TYPE_T));

            rBuffHeader.u8TimeStamp = (prSilentInfo->u8LastTime+prSilentInfo->u4PredictionLength)*1000;
            rBuffHeader.eFlags = VIDEO_BUFFERFLAG_SILENT;
            rBuffHeader.u4OutputPort = eType;
            rBuffHeader.u4InputPort = eType; 

            rRet = SourceProviderEmptyThisBuffer(pvHandle, &rBuffHeader);
            
            // can't send out
            if (rRet == VIDEO_ERROR_BUFF_FULL)
            {            
                if (prData->release != NULL)
		        {
		            prData->release(prData); 
		        } 
                return rRet;
            }
            
            // update time
            prSilentInfo->u8LastTime = rBuffHeader.u8TimeStamp/1000;
        }
    }

    kal_mem_set((void *)&rBuffHeader, 0, sizeof(VIDEO_BUFFERHEADER_TYPE_T));

    rBuffHeader.pu1Buffer = prData->data;
    rBuffHeader.u4BuffSize = prData->size;
    rBuffHeader.u8TimeStamp = prData->display_time * 1000;    
    rBuffHeader.u4OutputPort = eType;
    rBuffHeader.u4InputPort = eType;    
    
    if (eType ==  SOURCE_PROVIDER_PORT_VIDEO)
    {         
        if (prData->specific_info != NULL)
        {
            rBuffHeader.pPrivateData = (void *)prData->specific_info;
        }

        if (prData->flags & MEDIA_DATA_FLAG_KEY_FRAME)
        {
            rBuffHeader.eFlags = VIDEO_BUFFERFLAG_SYNCFRAME;
        }
        else
        {
            rBuffHeader.eFlags = VIDEO_BUFFERFLAG_NONE;
        }
    }
    else
    {
    }

    rRet = SourceProviderEmptyThisBuffer(pvHandle, &rBuffHeader);

    if (prData->release != NULL)
    {
        prData->release(prData); 
    }
    
#else
   //ASSERT(0);
   rRet = VIDEO_ERROR_INPUT_PARAM_ERROR;
#endif

   return rRet;
}

VIDEO_ERROR_TYPE_T SourceProviderStreamingAddEof(void* pvHandle, SP_PORT_TYPE_T eType, kal_uint64 u8EndTime)
{
    VIDEO_ERROR_TYPE_T rRet = VIDEO_ERROR_NONE;

#ifdef __VE_STREAM_SUPPORT__
    VIDEO_BUFFERHEADER_TYPE_T rBuffHeader;
    //kal_bool fgSendHeader = KAL_FALSE;

    kal_mem_set((void *)&rBuffHeader, 0, sizeof(VIDEO_BUFFERHEADER_TYPE_T));

    rBuffHeader.u8TimeStamp = u8EndTime * 1000;    
    rBuffHeader.u4OutputPort = eType;
    rBuffHeader.u4InputPort = eType; 
    rBuffHeader.eFlags = VIDEO_BUFFERFLAG_EOF;

    rRet = SourceProviderEmptyThisBuffer(pvHandle, &rBuffHeader);
#else
    //ASSERT(0);
    rRet = VIDEO_ERROR_INPUT_PARAM_ERROR;
#endif

    return rRet;
}
#endif // __VE_SOURCE_PROVIDER__

