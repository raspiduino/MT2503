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
 *   video_encoder_common_adapter_v2.c
 *
 * Project:
 * --------
 *  MTK
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
 *
 *
 ****************************************************************************/
#include "drv_comm.h"
#include "drv_features_video.h"
#ifdef __VE_DCM_WITH_COMPRESSION__
#include "dcmgr.h"
#pragma arm section code = "DYNAMIC_CODE_VEENC_ROCODE", rodata = "DYNAMIC_CODE_VEENC_RODATA"
#endif
#ifdef __VE_VIDEO_ARCHI_V2__
#if defined(__VE_MPEG4_ENC_SW_SUPPORT__) || defined(__VE_VIDEO_VT_SUPPORT__) || defined(__VE_H264_ENC_SW_SUPPORT__)

#include "video_types_v2.h"
#include "video_encoder_component_v2.h"
#include "vcodec_v2_trc.h"
#include "video_buffer_management_v2.h"
#include "video_codec_type_v2.h"
#include "video_codec_if_v2.h"
#include "kal_trace.h"
#include "kal_general_types.h"
#include "video_codec_custom_setting_v2.h"
#include "vcodec_if.h"
#include "custom_video_enc_if.h"
#include "video_codec_custom_adapter_v2.h"
#include "video_encoder_common_adapter_v2.h"
#include "vcodec_enc_demuxer_if.h"
#include "vcodec_OAL.h"
#include "video_OAL_v2.h"
#include "cache_sw.h"

static VIDEO_ENCODER_ADAPTER_CTRL_T rEncoderAdapterCtrl;
extern kal_uint32 query_opposite_switchable_cacheaddr_ram(kal_uint32 addr);

static void VideoEncoderAdapterCheckHandle(HANDLE hDrv)
{
    if (rEncoderAdapterCtrl.hDrvHandle != hDrv)
    {
        //drv_trace0(TRACE_GROUP_10, VENC_ADAPT_ERR_HANDLE);
        ASSERT(0);
    }
}

static void VideoEncoderAdapterMalloc(HANDLE hDrv, unsigned int u4Size , unsigned int u4AlignSize,
        VCODEC_MEMORY_TYPE_T fgCacheable, VCODEC_BUFFER_T *prBuf)   /*buffer address must cache line align */
{
    VideoEncoderAdapterCheckHandle(hDrv);

    if (prBuf == NULL)
    {
        //drv_trace1(TRACE_GROUP_10, VENC_ADAPT_NULL_PTR, __LINE__);
        ASSERT(0);
    }
    else
    {
        if (u4Size == 0)
        {
            drv_trace1(TRACE_GROUP_10, VENC_ADAPT_ERR_OPERATION, __LINE__);
            prBuf->pu1Buffer_VA = prBuf->pu1Buffer_PA = NULL;
            prBuf->eBufferStatus = (fgCacheable == VIDEO_CACHEABLE) ? (VA_CACHED) : (0);
        }
        else
        {
            if (u4AlignSize != CPU_CACHE_LINE_SIZE)
            {
                ASSERT(0);
            }

        #if defined(__VE_DYNAMIC_SWITCH_CACHEABILITY__)
            if (fgCacheable == VIDEO_CACHEABLE)
            {
                prBuf->pu1Buffer_VA = (kal_uint8 *)VideoEncoderMallocCacheLineAlign((kal_uint32)u4Size, KAL_TRUE);
                if (prBuf->pu1Buffer_VA == NULL)
                {
                    prBuf->pu1Buffer_PA = NULL;
                }
                else
                {
                    prBuf->pu1Buffer_PA = (kal_uint8 *)query_opposite_switchable_cacheaddr_ram((kal_uint32)prBuf->pu1Buffer_VA);
                    prBuf->eBufferStatus = VA_CACHED;
                }
            }
            else
            {
                prBuf->pu1Buffer_VA = (kal_uint8 *)VideoEncoderMallocCacheLineAlign((kal_uint32)u4Size, KAL_FALSE);
                prBuf->pu1Buffer_PA = prBuf->pu1Buffer_VA;
                prBuf->eBufferStatus = 0;
            }
        #else
            prBuf->pu1Buffer_VA = prBuf->pu1Buffer_PA = (kal_uint8 *)VideoEncoderMallocAligned((kal_uint32)u4Size);
            prBuf->eBufferStatus = (fgCacheable == VIDEO_CACHEABLE) ? (VA_CACHED) : (0);
        #endif
        }
    }
}

static void VideoEncoderAdapterFree(HANDLE hDrv,VCODEC_BUFFER_T *prBuf)  /* same memory type with malloc */  
{
    VideoEncoderAdapterCheckHandle(hDrv);

    if (prBuf == NULL)
    {
        //drv_trace1(TRACE_GROUP_10, VENC_ADAPT_NULL_PTR, __LINE__);
        ASSERT(0);
    }
    else
    {
        VideoEncoderFreeCacheLineAlign((void *)prBuf->pu1Buffer_VA);
    }
}
static void VideoEncoderAdapterGetIntMem(
    HANDLE hDrv,
    unsigned int u4Size,
    unsigned int u4AlignSize,
    void **pBuffer_adr)
{
    VideoEncoderAdapterCheckHandle(hDrv);

    if (u4AlignSize != CPU_CACHE_LINE_SIZE)
    {
        ASSERT(0);
    }

    if (!u4Size)
    {
        *pBuffer_adr = NULL;
    }
    *pBuffer_adr = (void *)VideoEncoderGetIntMem((kal_uint32)u4Size);
    if (*pBuffer_adr == NULL)
    {
        rEncoderAdapterCtrl.u4GetIntMemSize = 0;
    }
    else
    {
        rEncoderAdapterCtrl.u4GetIntMemSize = u4Size;
    }
}

static void VideoEncoderAdapterFreeIntMem(HANDLE hDrv, void *pBuffer_adr)
{
    VCODEC_BUFFER_T* prTmp = (VCODEC_BUFFER_T*)pBuffer_adr;
    VideoEncoderAdapterCheckHandle(hDrv);
    if (0 != rEncoderAdapterCtrl.u4GetIntMemSize)
    {
        VideoEncoderFreeIntMem((kal_uint8*)prTmp->pu1Buffer_VA, rEncoderAdapterCtrl.u4GetIntMemSize);
    }
}

static void VideoEncoderAdapterReleaseYUV(HANDLE hDrv, VCODEC_BUFFER_T *prYUVBuf)
{
    VideoEncoderAdapterCheckHandle(hDrv);
    
    if (prYUVBuf == NULL)
    {
        //drv_trace1(TRACE_GROUP_10, VENC_ADAPT_NULL_PTR, __LINE__);
        ASSERT(0);
    }
    else
    {
        VideoEncoderReleaseYUV(prYUVBuf->pu1Buffer_VA);
    }
}
                                                                                             
static void VideoEncoderAdapterPaused(HANDLE hDrv, VCODEC_BUFFER_T *prBitstreamBuf)
{
    VideoEncoderAdapterCheckHandle(hDrv);
    
    if (prBitstreamBuf == NULL)
    {
        //drv_trace1(TRACE_GROUP_10, VENC_ADAPT_NULL_PTR, __LINE__);
        ASSERT(0);
    }
    else
    {
        VideoEncoderPaused((kal_uint8 *)prBitstreamBuf->pu1Buffer_VA);
    }
}

static void VideoEncoderAdapterAllocateBitstreamBuffer(HANDLE hDrv, VCODEC_ENC_BUFFER_INFO_T *prBitstreamBuf)
{
    kal_uint8* pu1StartAddr;
    kal_uint8* pu1EndAddr;
    kal_uint8* pu1WriteAddr;
    kal_uint8* pu1ReadAddr;
    kal_uint32 u4BufferLength;

    VideoEncoderAdapterCheckHandle(hDrv);
    if (prBitstreamBuf == NULL)
    {
        //drv_trace1(TRACE_GROUP_10, VENC_ADAPT_NULL_PTR, __LINE__);
        ASSERT(0);
        //return;
    }
    else
    {
        VideoEncoderAllocateBitstreamBuffer(&pu1StartAddr, &pu1EndAddr, &pu1WriteAddr, &pu1ReadAddr, &u4BufferLength);

        prBitstreamBuf->rStartAddr.pu1Buffer_VA = pu1StartAddr;
        prBitstreamBuf->rEndAddr.pu1Buffer_VA = pu1EndAddr;
        prBitstreamBuf->rWriteAddr.pu1Buffer_VA = pu1WriteAddr;
        prBitstreamBuf->rReadAddr.pu1Buffer_VA = pu1ReadAddr;
        prBitstreamBuf->u4BufferLength = u4BufferLength;
        VideoQueryPhysicalAddr((void *)pu1StartAddr, (void **)&prBitstreamBuf->rStartAddr.pu1Buffer_PA);
        VideoQueryPhysicalAddr((void *)pu1EndAddr, (void **)&prBitstreamBuf->rEndAddr.pu1Buffer_PA);
        VideoQueryPhysicalAddr((void *)pu1WriteAddr, (void **)&prBitstreamBuf->rWriteAddr.pu1Buffer_PA);
        VideoQueryPhysicalAddr((void *)pu1ReadAddr, (void **)&prBitstreamBuf->rReadAddr.pu1Buffer_PA);
    }
}

static void VideoEncoderAdapterUpdateBitstreamWP(HANDLE hDrv, VCODEC_ENC_UPDATE_WP_INTO_T *prUpdateWritePointer)
{
    VideoEncoderAdapterCheckHandle(hDrv);
    if (prUpdateWritePointer == NULL)
    {
        //drv_trace1(TRACE_GROUP_10, VENC_ADAPT_NULL_PTR, __LINE__);
        ASSERT(0);
    }
    else
    {
        VideoEncoderUpdateBitstreamWP((kal_uint8 *)prUpdateWritePointer->rWp.pu1Buffer_VA,
                                      (kal_int32)prUpdateWritePointer->fgSliceContained);
    }
}

static CUSTOM_VENC_ERROR_T _VideoEncCommonQueryCtrl(CUSTOM_VENC_OP_T eOP, kal_uint32* p4Val)
{
    CUSTOM_VENC_ERROR_T eResult = CUSTOM_VENC_ERROR_NONE;

    eResult = CustomVenc_Ctrl(eOP, NULL, 0, (void *)p4Val, sizeof(kal_uint32));
    if ((eResult != CUSTOM_VENC_ERROR_NONE) &&
        (eResult != CUSTOM_VENC_ERROR_USE_DEFAULT))
    {
        ASSERT(0);
    }
    return eResult;
}

static VCODEC_ENC_ERROR_T VideoEncoderAdapterQueryInfo(HANDLE hDrv, VCODEC_ENC_QUERY_INFO_TYPE_T query_id, void *pvParamData)
{
    CUSTOM_VENC_ERROR_T eResult = CUSTOM_VENC_ERROR_NONE;
    VCODEC_ENC_ERROR_T eRet = VCODEC_ENC_ERROR_NONE;
    kal_uint32 u4Val;
    kal_uint32 *p4Param = (kal_uint32 *)pvParamData;

    VideoEncoderAdapterCheckHandle(hDrv);

    switch (query_id)
    {
        case VCODEC_ENC_QUERY_INFO_TOTAL_FRAME_BUFFER:      // Total frame buffer size
        case VCODEC_ENC_QUERY_INFO_FRAMES_QUEUED:           // Number of frames waited to encoder
        case VCODEC_ENC_QUERY_INFO_VTBUFFER_FULLNESS_DENOM: // Denominator of VT buffer fullness
        case VCODEC_ENC_QUERY_INFO_VTBUFFER_FULLNESS_NUM:    // Numerator of VT buffer fullness
            break;
        case VCODEC_ENC_QUERY_INFO_INIT_Q:                  // Used by codec
            eResult = _VideoEncCommonQueryCtrl(CUSTOM_VENC_OP_GET_INIT_Q, p4Param);
            break;
        case VCODEC_ENC_QUERY_INFO_MIN_QP:                  // Used by codec
            eResult = _VideoEncCommonQueryCtrl(CUSTOM_VENC_OP_GET_MIN_QP, p4Param);
            break;
        case VCODEC_ENC_QUERY_INFO_MAX_QP:
            eResult = _VideoEncCommonQueryCtrl(CUSTOM_VENC_OP_GET_MAX_QP, p4Param);
            break;
        case VCODEC_ENC_QUERY_INFO_INTRA_VOP_RATE:  // Used by MED/codec
            eResult = _VideoEncCommonQueryCtrl(CUSTOM_VENC_OP_GET_INTRA_VOP_RATE, p4Param);
            break;
        case VCODEC_ENC_QUERY_INFO_ALGORITHM:           // Used by codec
            eResult = _VideoEncCommonQueryCtrl(CUSTOM_VENC_OP_GET_ALGORITHM, p4Param);
            break;
        case  VCODEC_ENC_QUERY_INFO_BIT_RATE:               // Used by codec
            eResult = _VideoEncCommonQueryCtrl(CUSTOM_VENC_OP_GET_BIT_RATE, p4Param);
            break;
        case VCODEC_ENC_QUERY_INFO_RATE_HARD_LIMIT:   // Used by MED/codec
            eResult = _VideoEncCommonQueryCtrl(CUSTOM_VENC_OP_GET_RATE_HARD_LIMIT, p4Param);
            break;
        case VCODEC_ENC_QUERY_INFO_RATE_BALANCE:        // Used by codec
            eResult = _VideoEncCommonQueryCtrl(CUSTOM_VENC_OP_GET_RATE_BALANCE, p4Param);
            break;
        case VCODEC_ENC_QUERY_INFO_DYNAMIC_RANGE_REDUCTION:        // Used by codec
            eResult = _VideoEncCommonQueryCtrl(CUSTOM_VENC_OP_GET_DYNAMIC_RANGE_REDUCTION, p4Param);
            break;
        case VCODEC_ENC_QUERY_INFO_IF_CUSTOMER_SET_TABLE:        // Used by codec
            eResult = _VideoEncCommonQueryCtrl(CUSTOM_VENC_OP_GET_IS_CUSTOMER_SET_TABLE, p4Param);
            break;
        case VCODEC_ENC_QUERY_INFO_DYNAMIC_RANGE_TABLE:        // Used by codec
            eResult = _VideoEncCommonQueryCtrl(CUSTOM_VENC_OP_GET_DYNAMIC_RANGE_TABLE, p4Param);
            break;
        case VCODEC_ENC_QUERY_INFO_TARGET_COMPLEXITY:        // Used by codec
            eResult = _VideoEncCommonQueryCtrl(CUSTOM_VENC_OP_GET_TARGET_COMPLEXITY, p4Param);
            break;
        case VCODEC_ENC_QUERY_INFO_THRESHOLD_AVG_LOW:        // Used by codec
            eResult = _VideoEncCommonQueryCtrl(CUSTOM_VENC_OP_GET_THRESHOLD_AVG_LOW, p4Param);
            break;
        case VCODEC_ENC_QUERY_INFO_THRESHOLD_AVG_HIGH:        // Used by codec
            eResult = _VideoEncCommonQueryCtrl(CUSTOM_VENC_OP_GET_THRESHOLD_AVG_HIGH, p4Param);
            break;
        case VCODEC_ENC_QUERY_INFO_THRESHOLD_CUR_LOW:        // Used by codec
            eResult = _VideoEncCommonQueryCtrl(CUSTOM_VENC_OP_GET_THRESHOLD_CUR_LOW, p4Param);
            break;
        case VCODEC_ENC_QUERY_INFO_THRESHOLD_CUR_HIGH:        // Used by codec
            eResult = _VideoEncCommonQueryCtrl(CUSTOM_VENC_OP_GET_THRESHOLD_CUR_HIGH, p4Param);
            break;   
        case VCODEC_ENC_QUERY_INFO_OAL_FUNCTION:
            {
                VCODEC_OAL_CALLBACK_T *prOALCallback = (VCODEC_OAL_CALLBACK_T *)pvParamData;
                const VCODEC_OAL_CALLBACK_T rCallback = 
                {
                    VideoQueryMemType,              /* VCodecQueryMemType */                    
                    VideoQueryPhysicalAddr,         /* VCodecQueryPhysicalAddr */              
                    VideoSwitchMemType,             /* VCodecSwitchMemType */                   
                    VideoFlushCachedBuffer,         /* VCodecFlushCachedBuffer */              
                    VideoInvalidateCachedBuffer,    /* VCodecInvalidateCachedBuffer */        
                    VideoFlushCachedBufferAll,      /* VCodecFlushCachedBufferAll */            
                    VideoInvalidateCachedBufferAll, /* VCodecInvalidateCachedBufferAll */       
                    VideoFlushInvalidateCacheBufferAll,/* VCodecFlushInvalidateCacheBufferAll */   
                    VideoMemSet,                    /* VCodecMemSet */                              
                    VideoMemCopy,                   /* VCodecMemCopy */                             
                    VideoAssertFail,                /* VCodecAssertFail */                          
                    NULL,                           /* VCodecMMAP */                                
                    NULL,                           /* VCodecUnMMAP */                              
                    NULL,                           /* VCodecWaitISR */                             
                    NULL,                           /* VCodecLockHW */                              
                    NULL,                           /* VCodecUnLockHW */                            
                    VideoTraceLog0,                 /* VcodecTraceLog0 */                           
                    VideoTraceLog1,                 /* VcodecTraceLog1 */                           
                    VideoTraceLog2,                 /* VcodecTraceLog2 */                           
                    VideoTraceLog4,                 /* VcodecTraceLog4 */                           
                    VideoTraceLog8,                 /* VcodecTraceLog8 */                            
                    NULL,                           /* VCodecInitHWLock */                          
                    NULL                            /* VCodecDeInitHWLock */                        
                };
                *prOALCallback = rCallback;
            }
            break;
        default:
            eRet = VCODEC_ENC_PARAM_NOT_SUPPORT;
            break;
    }

    if (eResult != CUSTOM_VENC_ERROR_NONE)
    {
        eRet = VCODEC_ENC_ERROR;
    }

    return eRet;
}


/******************************************************************************
* xxx
*
* Context:
*
* Side effect:
******************************************************************************/
VIDEO_ENCODER_CODEC_ERROR_T VideoEncoderOpenAdapt(void)
{
    VCODEC_ENC_ERROR_T eRet = VCODEC_ENC_ERROR_NONE;
    VCODEC_ENC_CALLBACK_T rCallback =
    {
        VideoEncoderAdapterMalloc,      /* pfnMalloc */
        VideoEncoderAdapterGetIntMem,   /* pfnIntMalloc */
        VideoEncoderAdapterFree,        /* pfnFree */
        VideoEncoderAdapterFreeIntMem,  /* pfnIntFree */
        VideoEncoderAdapterReleaseYUV,  /* pfnReleaseYUV */
        VideoEncoderAdapterPaused,      /* pfnPaused */
        VideoEncoderAdapterAllocateBitstreamBuffer, /* pfnAllocateBitstreamBuffer */
        VideoEncoderAdapterUpdateBitstreamWP, /* pfnUpdateBitstreamWP */
        VideoEncoderAdapterQueryInfo
    };

    eRet = rEncoderAdapterCtrl.prEncAPI->pfnOpen(rEncoderAdapterCtrl.hDrvHandle, &rCallback, &rEncoderAdapterCtrl.hCodecHandle);

    if (eRet != VCODEC_ENC_ERROR_NONE)
    {
        return VIDEO_ENCODER_CODEC_ERROR;
    }
    else
    {
        return VIDEO_ENCODER_CODEC_ERROR_NONE;
    }
}


/******************************************************************************
* xxx
*
* Context:
*
* Side effect:
******************************************************************************/
VIDEO_ENCODER_CODEC_ERROR_T VideoEncoderInitAdapt(void)
{
    VCODEC_ENC_ERROR_T eRet = VCODEC_ENC_ERROR_NONE;

    if (rEncoderAdapterCtrl.fgInit== KAL_FALSE)
    {
        eRet = rEncoderAdapterCtrl.prEncAPI->pfnInit(rEncoderAdapterCtrl.hCodecHandle);
    }

    if (eRet != VCODEC_ENC_ERROR_NONE)
    {
        //drv_trace2(TRACE_GROUP_10, VENC_ADAPT_ERR_RETURN, (kal_uint32)eRet, __LINE__);
        return VIDEO_ENCODER_CODEC_ERROR;
    }
    else
    {
        rEncoderAdapterCtrl.fgInit = KAL_TRUE;
        return VIDEO_ENCODER_CODEC_ERROR_NONE;
    }
}

/******************************************************************************
* xxx
*
* Context:
*
* Side effect:
******************************************************************************/
VIDEO_ENCODER_CODEC_ERROR_T VideoEncoderDeInitAdapt(void)
{
    VCODEC_ENC_ERROR_T eRet = VCODEC_ENC_ERROR_NONE;
    VIDEO_ENCODER_CODEC_ERROR_T eCodecError;

    if (rEncoderAdapterCtrl.fgInit == KAL_TRUE)
    {
        eRet = rEncoderAdapterCtrl.prEncAPI->pfnDeInit(rEncoderAdapterCtrl.hCodecHandle);
    }

    if (eRet != VCODEC_ENC_ERROR_NONE)
    {
        //drv_trace2(TRACE_GROUP_10, VENC_ADAPT_ERR_RETURN, (kal_uint32)eRet, __LINE__);
        if (eRet == VCODEC_ENC_BS_BUFFER_NOT_ENOUGH)
        {
            eCodecError = VIDEO_ENCODER_CODEC_BS_BUFFER_NOT_ENOUGH;
        }
        else
        {
            eCodecError = VIDEO_ENCODER_CODEC_ERROR;
        }
    }
    else
    {
        rEncoderAdapterCtrl.fgInit = KAL_FALSE;
        eCodecError = VIDEO_ENCODER_CODEC_ERROR_NONE;
    }

    return eCodecError;
}


/******************************************************************************
* xxx
*
* Context:
*
* Side effect:
******************************************************************************/
VIDEO_ENCODER_CODEC_ERROR_T VideoEncoderCloseAdapt(void)
{
    VCODEC_ENC_ERROR_T eRet = VCODEC_ENC_ERROR_NONE;

    eRet = rEncoderAdapterCtrl.prEncAPI->pfnClose(rEncoderAdapterCtrl.hCodecHandle);
    if (eRet != VCODEC_ENC_ERROR_NONE)
    {
        //drv_trace2(TRACE_GROUP_10, VENC_ADAPT_ERR_RETURN, (kal_uint32)eRet, __LINE__);
        return VIDEO_ENCODER_CODEC_ERROR;
    }
    else
    {
        return VIDEO_ENCODER_CODEC_ERROR_NONE;
    }
}


static VIDEO_ENCODER_CODEC_ERROR_T _VideoEncCommonCheckCodecReturn(VCODEC_ENC_ERROR_T eRet)
{
    if (eRet != VCODEC_ENC_ERROR_NONE)
    {
        if (eRet == VCODEC_ENC_PARAM_NOT_SUPPORT)
        {
            return VIDEO_ENCODER_CODEC_PARAM_NOT_SUPPORT;
        }
        else
        {
            return VIDEO_ENCODER_CODEC_ERROR;
        }
    }
    else
    {
        return VIDEO_ENCODER_CODEC_ERROR_NONE;
    }
}
/******************************************************************************
* xxx
*
* Context:
*
* Side effect:
******************************************************************************/
VIDEO_ENCODER_CODEC_ERROR_T VideoEncoderGetParameterAdapt(VIDEO_ENCODER_PARAM_TYPE_T eCmd, void *pParam)
{
    VCODEC_ENC_ERROR_T eRet = VCODEC_ENC_ERROR_NONE;
    VCODEC_ENC_API_T  *prEncAPI = rEncoderAdapterCtrl.prEncAPI;

    if (pParam == NULL)
    {
        //drv_trace1(TRACE_GROUP_10, VENC_ADAPT_NULL_PTR, __LINE__);
        ASSERT(0);
    }

    switch(eCmd)
    {
    case VENC_PARAM_MEMORY_REQUIREMENT:
        {
            VCODEC_ENC_SETTING_T rEncSetting;
            VCODEC_MEMORY_SIZE_T rMemInfo;
            VCODEC_ENC_GENERAL_SETTING_T *prCustomSetting = (VCODEC_ENC_GENERAL_SETTING_T *)rEncoderAdapterCtrl.prCustomSetting;
            VIDEO_ENC_MEMORY_T* prMemorySize = (VIDEO_ENC_MEMORY_T*)pParam;

            VideoEncoderMemCopy((void *)&rEncSetting.rMPEG4, (void *)prCustomSetting, sizeof(VCODEC_ENC_SETTING_T));

            if (!rEncoderAdapterCtrl.fgisVT)
            {
                if (rEncoderAdapterCtrl.eCodecType == VADP_CODEC_MPEG4)
                {
                    VCODEC_ENC_MPEG4_SETTING_T *prTmp = &rEncSetting.rMPEG4;

                    prTmp->eColorFormat = VCODEC_COLOR_FORMAT_YUV420;
                    prTmp->u4MaxWidth = prMemorySize->u4Width;
                    prTmp->u4MaxHeight = prMemorySize->u4Height;
                    prTmp->MaxVideoCodingResolution = prCustomSetting->MaxVideoCodingResolution;
                }
                else
                {
                    VCODEC_ENC_GENERAL_SETTING_T *prTmp = &rEncSetting.rH264;

                    prTmp->eColorFormat = VCODEC_COLOR_FORMAT_YUV420;
                    prTmp->u4MaxWidth = prMemorySize->u4Width;
                    prTmp->u4MaxHeight = prMemorySize->u4Height;
                    prTmp->MaxVideoCodingResolution = prCustomSetting->MaxVideoCodingResolution;
                }
            }
            else
            {
                VCODEC_ENC_GENERAL_SETTING_T *prTmp = &rEncSetting.rVT;

                prTmp->eColorFormat = VCODEC_COLOR_FORMAT_YUV420;
                prTmp->u4MaxWidth = prMemorySize->u4Width;
                prTmp->u4MaxHeight = prMemorySize->u4Height;
                prTmp->MaxVideoCodingResolution = prCustomSetting->MaxVideoCodingResolution;
            }

            eRet = prEncAPI->pfnGetMemoryRequired(&rEncSetting, &rMemInfo);
            prMemorySize->u4ExternalSize = rMemInfo.u4ExternalSize;
            prMemorySize->u4InternalSize = rMemInfo.u4InternalSize;
            drv_trace1(TRACE_GROUP_10, VENC_ADAPT_EXT_MEM_SIZE, prMemorySize->u4ExternalSize);
        }
        break;
    case VENC_PARAM_BITSTREAM_IN_CACHE:
        eRet = prEncAPI->pfnGetParameter(rEncoderAdapterCtrl.hCodecHandle,
                                                                 VCODEC_ENC_PARAM_BITSTREAM_IN_CACHE, pParam);
        break;
    case VENC_PARAM_FRM_BUFFER_ALIGNMENT:
        eRet = prEncAPI->pfnGetParameter(rEncoderAdapterCtrl.hCodecHandle,
                                                                VCODEC_ENC_PARAM_FRM_BUFFER_ALIGNMENT, pParam);
        break;
    case VENC_PARAM_HOLD_RES_TILL_RELEASE_FRM:
        eRet = prEncAPI->pfnGetParameter(rEncoderAdapterCtrl.hCodecHandle,
                                                                VCODEC_ENC_PARAM_HOLD_RES_TILL_RELEASE_FRM, pParam);
        break;
    case VENC_PARAM_IS_BLOCKBASED_YUV:
        eRet = prEncAPI->pfnGetParameter(rEncoderAdapterCtrl.hCodecHandle,
                                                                VCODEC_ENC_PARAM_IS_BLOCKBASED_YUV, pParam);
        break;
    case VENC_PARAM_GET_CODEC_CONFIG:
        {
#if defined(__H264_ENC_SW_SUPPORT__)
            H264_ENC_CONF_REC **pprRec = (H264_ENC_CONF_REC **)pParam;
            eRet = prEncAPI->pfnGetParameter(rEncoderAdapterCtrl.hCodecHandle,
                                                                VCODEC_ENC_PARAM_DECODER_CONFIGURATION_RECORD,
                                                                (void *)&rEncoderAdapterCtrl.rConfigRec);
            *pprRec = &rEncoderAdapterCtrl.rConfigRec;
#endif
        }
        break;
    default:
        //drv_trace1(TRACE_GROUP_10, VENC_ADAPT_ERR_OPERATION, __LINE__);
        return VIDEO_ENCODER_CODEC_PARAM_NOT_SUPPORT;
    }

    return _VideoEncCommonCheckCodecReturn(eRet);
}

static kal_int32 _VideoEncCommonTransformKalBoolToInt(kal_bool* pfgIn)
{
    return (KAL_TRUE == *pfgIn)? (1) : (0);
}
/******************************************************************************
* xxx
*
* Context:
*
* Side effect:
******************************************************************************/
VIDEO_ENCODER_CODEC_ERROR_T VideoEncoderSetParameterAdapt(VIDEO_ENCODER_PARAM_TYPE_T eCmd, void *pParam)
{
    VCODEC_ENC_ERROR_T eRet = VCODEC_ENC_ERROR_NONE;
    kal_int32 i4TempVal;
    kal_bool fgTemp;
    VCODEC_ENC_API_T  *prEncAPI = rEncoderAdapterCtrl.prEncAPI;
    HANDLE* prHdl = &rEncoderAdapterCtrl.hCodecHandle;

    switch(eCmd)
    {
    case VENC_PARAM_WIDTH:
        eRet = prEncAPI->pfnSetParameter(*prHdl, VCODEC_ENC_PARAM_WIDTH, pParam);
        break;
    case VENC_PARAM_HEIGHT:
        eRet = prEncAPI->pfnSetParameter(*prHdl, VCODEC_ENC_PARAM_HEIGHT, pParam);
        break;
    case VENC_PARAM_FRAME_RATE:
        eRet = prEncAPI->pfnSetParameter(*prHdl, VCODEC_ENC_PARAM_FRAME_RATE, pParam);
        break;
    case VENC_PARAM_FORCE_ENCODE_I:
        eRet = prEncAPI->pfnSetParameter(*prHdl, VCODEC_ENC_PARAM_FORCE_ENCODE_I, pParam);
        break;
    case VENC_PARAM_SCENARIO:
        eRet = prEncAPI->pfnSetParameter(*prHdl, VCODEC_ENC_PARAM_SCENARIO, pParam);
        break;
    case VENC_PARAM_SET_CALLBACK:
        eRet = prEncAPI->pfnSetParameter(*prHdl, VCODEC_ENC_PARAM_SET_CALLBACK, pParam);
        break;
    case VENC_PARAM_FLUSH_CODEC:
        eRet = prEncAPI->pfnSetParameter(*prHdl, VCODEC_ENC_PARAM_SET_NO_MORE_INPUT, pParam);
        break;
    case VENC_PARAM_SHORT_HEADER:
        i4TempVal = _VideoEncCommonTransformKalBoolToInt((kal_bool *)(pParam));
        eRet = prEncAPI->pfnSetParameter(*prHdl, VCODEC_ENC_PARAM_SHORT_HEADER, (void *)&i4TempVal);
        break;
    case VENC_PARAM_QUALITY:
        {
            VCODEC_ENC_QUALITY_T eAdapterQuality;
            VIDEO_ENCODER_QUALITY_T eQuality = *(VIDEO_ENCODER_QUALITY_T *)(pParam);
            switch (eQuality)
            {
                case VIDEO_ENCODER_QUALITY_NONE:
                    eAdapterQuality = VCODEC_ENC_QUALITY_NONE;
                    break;
                case VIDEO_ENCODER_QUALITY_LOW:
                    eAdapterQuality = VCODEC_ENC_QUALITY_LOW;
                    break;
                case VIDEO_ENCODER_QUALITY_NORMAL:
                    eAdapterQuality = VCODEC_ENC_QUALITY_NORMAL;
                    break;
                case VIDEO_ENCODER_QUALITY_GOOD:
                    eAdapterQuality = VCODEC_ENC_QUALITY_GOOD;
                    break;
                case VIDEO_ENCODER_QUALITY_FINE:
                    eAdapterQuality = VCODEC_ENC_QUALITY_FINE;
                    break;
                case VIDEO_ENCODER_QUALITY_CUSTOM:
                    eAdapterQuality = VCODEC_ENC_QUALITY_CUSTOM;
                    break;
                default:
                    //drv_trace1(TRACE_GROUP_10, VENC_ADAPT_ERR_OPERATION, __LINE__);
                    return VIDEO_ENCODER_CODEC_PARAM_NOT_SUPPORT;
            }
            eRet = prEncAPI->pfnSetParameter(*prHdl, VCODEC_ENC_PARAM_QUALITY, (void *)&eAdapterQuality);
        }
        break;

    case VENC_PARAM_CODEC_TYPE:
        {
            VCODEC_ENC_CODEC_T eAdapterCodecType;
            VIDEO_ENCODER_CODEC_T eCodecType = *(VIDEO_ENCODER_CODEC_T *)(pParam);
            switch (eCodecType)
            {
            case ENCODER_CODEC_TYPE_NONE:
                eAdapterCodecType = VCODEC_ENC_CODEC_TYPE_NONE;
                break;
            case ENCODER_CODEC_TYPE_MPEG4:
                eAdapterCodecType = VCODEC_ENC_CODEC_TYPE_MPEG4;
                break;
            case ENCODER_CODEC_TYPE_H263:
                eAdapterCodecType = VCODEC_ENC_CODEC_TYPE_H263;
                break;
            default:
                //drv_trace1(TRACE_GROUP_10, VENC_ADAPT_ERR_OPERATION, __LINE__);
                return VIDEO_ENCODER_CODEC_PARAM_NOT_SUPPORT;
            }
            eRet = prEncAPI->pfnSetParameter(*prHdl, VCODEC_ENC_PARAM_CODEC_TYPE, (void *)&eAdapterCodecType);
        }
        break;
#if defined(__VE_VIDEO_VT_SUPPORT__) 
    case VENC_PARAM_VT_RESTART:
        i4TempVal = _VideoEncCommonTransformKalBoolToInt((kal_bool *)(pParam));
        eRet = prEncAPI->pfnSetParameter(*prHdl, VCODEC_ENC_PARAM_VT_RESTART, (void *)&i4TempVal);
        break;
    case VENC_PARAM_BITRATE:
        eRet = prEncAPI->pfnSetParameter(*prHdl, VCODEC_ENC_PARAM_BITRATE, pParam);
        break;
    case VENC_PARAM_MAX_PKG_SIZE:
        eRet = prEncAPI->pfnSetParameter(*prHdl, VCODEC_ENC_PARAM_MAX_PKG_SIZE, pParam);
        break;
    case VENC_PARAM_GEN_HEADER_FRM_RATE:
        eRet = prEncAPI->pfnSetParameter(*prHdl, VCODEC_ENC_PARAM_GEN_HEADER_FRM_RATE, pParam);
        break; 
#endif
        
#if !defined(__VE_SLIM_PROJECT__)
    case VENC_PARAM_SYNC_INTERVAL:
        eRet = prEncAPI->pfnSetParameter(*prHdl, VCODEC_ENC_PARAM_SYNC_INTERVAL, pParam);
        break;
    case VENC_PARAM_ROTATE:
        {
            VCODEC_ENC_ROTATE_ANGLE_T eAdapterRotate;
            VIDEO_CODEC_ROTATE_ANGLE_T eRotate = *(VIDEO_CODEC_ROTATE_ANGLE_T *)(pParam);
            switch (eRotate)
            {
            case VIDEO_CODEC_ROTATE_0:
                eAdapterRotate = VCODEC_ENC_ROTATE_0;
                break;
            case VIDEO_CODEC_ROTATE_90:
                eAdapterRotate = VCODEC_ENC_ROTATE_90;
                break;
            case VIDEO_CODEC_ROTATE_180:
                eAdapterRotate = VCODEC_ENC_ROTATE_180;
                break;
            case VIDEO_CODEC_ROTATE_270:
                eAdapterRotate = VCODEC_ENC_ROTATE_270;
                break;
            default:
                //drv_trace1(TRACE_GROUP_10, VENC_ADAPT_ERR_OPERATION, __LINE__);
                return VIDEO_ENCODER_CODEC_PARAM_NOT_SUPPORT;
            }
            eRet = prEncAPI->pfnSetParameter(*prHdl, VCODEC_ENC_PARAM_ROTATE, (void *)&eAdapterRotate);
        }
        break;
#endif
    default:
        //drv_trace1(TRACE_GROUP_10, VENC_ADAPT_ERR_OPERATION, __LINE__);
        return VIDEO_ENCODER_CODEC_PARAM_NOT_SUPPORT;
    }


    return _VideoEncCommonCheckCodecReturn(eRet);
}

/******************************************************************************
* xxx
*
* Context:
*
* Side effect:
******************************************************************************/
VIDEO_ENCODER_CODEC_ERROR_T VideoEncoderGenerateHeader(void)
{
    VCODEC_ENC_ERROR_T eRet = VCODEC_ENC_ERROR_NONE;

    eRet = rEncoderAdapterCtrl.prEncAPI->pfnGenerateHeader(rEncoderAdapterCtrl.hCodecHandle);
    if (eRet != VCODEC_ENC_ERROR_NONE)
    {
        //drv_trace2(TRACE_GROUP_10, VENC_ADAPT_ERR_RETURN, (kal_uint32)eRet, __LINE__);
        return VIDEO_ENCODER_CODEC_ERROR;
    }
    else
    {
        return VIDEO_ENCODER_CODEC_ERROR_NONE;
    }
}

/******************************************************************************
* Encode one unit.
*
* Context:
*
* Side effect:
******************************************************************************/
VIDEO_ENCODER_CODEC_ERROR_T VideoEncoderEncodeOneFrame(VIDEO_BUFFERHEADER_TYPE_T *prBufferHeader)
{
    VCODEC_ENC_INPUT_PARAM_T rInputParam;
    VCODEC_BUFFER_T *prVideoBuffer = &rInputParam.rInput.rYUVBuffer;
    VCODEC_ENC_ERROR_T eRet = VCODEC_ENC_ERROR_NONE;

    if (prBufferHeader == NULL)
    {
        rInputParam.eFlags = INPUT_FLAG_NO_INPUT;
    }
    else
    {
        rInputParam.u8TimeStamp = prBufferHeader->u8TimeStamp;
        rInputParam.eFlags = INPUT_FLAG_YUVBUFFER;
        rInputParam.rInput.u4Length = prBufferHeader->u4BuffSize;
        prVideoBuffer->pu1Buffer_VA = prBufferHeader->pu1Buffer;
        if (VideoCommIsExtBufferCacheable((kal_uint32)prBufferHeader->pu1Buffer, prBufferHeader->u4BuffSize) == KAL_TRUE)
        {
            prVideoBuffer->pu1Buffer_PA = (kal_uint8 *)query_opposite_switchable_cacheaddr_ram((kal_uint32)prVideoBuffer->pu1Buffer_VA);
            prVideoBuffer->eBufferStatus = VA_CACHED;
        }
        else
        {
            prVideoBuffer->pu1Buffer_PA = prVideoBuffer->pu1Buffer_VA;
            prVideoBuffer->eBufferStatus = 0;
        }
    }

    eRet = rEncoderAdapterCtrl.prEncAPI->pfnEncodeOneUnit(rEncoderAdapterCtrl.hCodecHandle, &rInputParam);

    if (eRet != VCODEC_ENC_ERROR_NONE)
    {
        drv_trace2(TRACE_GROUP_10, VENC_ADAPT_ERR_RETURN, (kal_uint32)eRet, __LINE__);
        if (eRet == VCODEC_ENC_BS_BUFFER_NOT_ENOUGH)
        {
            return VIDEO_ENCODER_CODEC_BS_BUFFER_NOT_ENOUGH;
        }
        else if (eRet == VCODEC_ENC_INPUT_REJECT)
        {
            return VIDEO_ENCODER_CODEC_ERROR_NONE;
        }
        else
        {
            return VIDEO_ENCODER_CODEC_ERROR;
        }
    }
    else
    {
        return VIDEO_ENCODER_CODEC_ERROR_NONE;
    }
}


/******************************************************************************
* xxx
*
* Context:
*
* Side effect:
******************************************************************************/
VIDEO_ENCODER_CODEC_ERROR_T VideoEncoderGetNextBitstream(kal_uint8 **ppu1BitstreamAddr,
        VIDEO_ENCODER_PRIVATE_OUTPUT_T *prPrivateOutput)
{
    VCODEC_ENC_GENERAL_OUTPUT_T rEncoderOutput;
    VCODEC_ENC_ERROR_T eRet = VCODEC_ENC_ERROR_NONE;
#ifdef __VE_VIDEO_VT_SUPPORT__
    VCODEC_ENC_PACKET_SET_T *prCodecChasis = NULL;
    VIDEO_ENCODER_CHASSIS_T *prCommonChasis = NULL;
    kal_uint16 u2Idx = 0;
#endif

    if (prPrivateOutput == NULL)
    {
        //drv_trace1(TRACE_GROUP_10, VENC_ADAPT_NULL_PTR, __LINE__);
        ASSERT(0);
        return VIDEO_ENCODER_CODEC_ERROR;
    }
#ifdef __VE_VIDEO_VT_SUPPORT__
    if (rEncoderAdapterCtrl.fgisVT)
    {
        prCommonChasis = prPrivateOutput->prChassis;
        prCodecChasis = &rEncoderAdapterCtrl.rChassis;
        prCodecChasis->u4NumOfPkts = prCommonChasis->u4NumOfPkts;
        rEncoderOutput.prChassis = (void *)prCodecChasis;
    }
#endif
    rEncoderOutput.fgEndOfFrame = 0;

    eRet = rEncoderAdapterCtrl.prEncAPI->pfnGetNextBitstream(rEncoderAdapterCtrl.hCodecHandle, &rEncoderOutput);

    if (eRet != VCODEC_ENC_ERROR_NONE)
    {
        //drv_trace2(TRACE_GROUP_10, VENC_ADAPT_ERR_RETURN, (kal_uint32)eRet, __LINE__);
        return VIDEO_ENCODER_CODEC_ERROR;
    }

    switch (rEncoderOutput.eFrameType)
        {
        case VCODEC_FRAMETYPE_I:
            prPrivateOutput->eFrameType = VIDEO_CODEC_FRAMETYPE_I;
            break;
        case VCODEC_FRAMETYPE_P:
            prPrivateOutput->eFrameType = VIDEO_CODEC_FRAMETYPE_P;
            break;
        case VCODEC_FRAMETYPE_B:
            prPrivateOutput->eFrameType = VIDEO_CODEC_FRAMETYPE_B;
            break;
        case VCODEC_HEADER:
            prPrivateOutput->eFrameType = VIDEO_CODEC_HEADER;
            break;
        case VCODEC_UNKNOWN_TYPE:
        default:
            //drv_trace1(TRACE_GROUP_10, VENC_ADAPT_ERR_OPERATION, __LINE__);
            prPrivateOutput->eFrameType = VIDEO_CODEC_UNKNOWN_TYPE;
            break;
        }

    *ppu1BitstreamAddr = (kal_uint8 *)rEncoderOutput.rBitstreamAddr.pu1Buffer_VA;
    prPrivateOutput->u4BitstreamLength = rEncoderOutput.u4BitstreamLength;
    prPrivateOutput->fgEndOfFrame = (rEncoderOutput.fgEndOfFrame) ? KAL_TRUE : KAL_FALSE;

#ifdef __VE_VIDEO_VT_SUPPORT__
    if (rEncoderAdapterCtrl.fgisVT)
    {
//modified by larry
        prCommonChasis->u4NumOfPkts = prCodecChasis->u4NumOfPkts;
        prCommonChasis->parPktInfo = NULL;
        for (u2Idx = 0; u2Idx < prCommonChasis->u4NumOfPkts; u2Idx++)
        {
            prCommonChasis->arPktInfo[u2Idx].u4Addr = (kal_uint32)prCodecChasis->arPktInfo[u2Idx].u4Addr;
            prCommonChasis->arPktInfo[u2Idx].u4Size= (kal_uint32)prCodecChasis->arPktInfo[u2Idx].u4Size;
        }
    }
#endif

#if defined(__VE_ENABLE_CODEC_ADJUST_TIME__)
    prPrivateOutput->fgUpdateTimeStamp = KAL_TRUE;
    prPrivateOutput->u8TimeStamp = rEncoderOutput.u8TimeStamp;
#endif

    return VIDEO_ENCODER_CODEC_ERROR_NONE;
}


/******************************************************************************
* xxx
******************************************************************************/
static const VIDEO_ENCODER_CODEC_API_T _rVideoEncoderAPI =
{
    VideoEncoderOpenAdapt,
    VideoEncoderInitAdapt,
    VideoEncoderGetParameterAdapt,
    VideoEncoderSetParameterAdapt,
    VideoEncoderGenerateHeader,
    VideoEncoderEncodeOneFrame,
    VideoEncoderDeInitAdapt,
    VideoEncoderCloseAdapt,
    VideoEncoderGetNextBitstream
};


/******************************************************************************
* xxx
******************************************************************************/
VIDEO_ENCODER_CODEC_API_T* GetVideoEncoderAdapterHandle(VIDEO_ADAPTOR_CODEC_T eType, VIDEO_ADAPTOR_SCENARIO_T eScenario)
{
    rEncoderAdapterCtrl.prEncAPI = GetVideoEncoderAPI(eType, eScenario);

    if (rEncoderAdapterCtrl.prEncAPI == NULL)
    {
        //drv_trace1(TRACE_GROUP_10, VENC_ADAPT_GET_CUSTOM_FAILED, __LINE__);
        return NULL;
    }

    // Access NULL pointer would be automatically checked by our system with fatal error
    // In this case, no need to write codes to check each APIs respectively
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
    #endif

//   Get max w,h here
    rEncoderAdapterCtrl.prCustomSetting = GetVideoEncoderCustomSetting(eType, eScenario);

    if (rEncoderAdapterCtrl.prCustomSetting == NULL)
    {
        ASSERT(0);
        return NULL;
    }

    rEncoderAdapterCtrl.hDrvHandle = (HANDLE)&_rVideoEncoderAPI;
    rEncoderAdapterCtrl.fgisVT = (eScenario == VADP_VIDEOCALL) ? KAL_TRUE : KAL_FALSE;
    rEncoderAdapterCtrl.eCodecType = eType;

    drv_trace2(TRACE_GROUP_10, VENC_ADAPT_GET_HANDLE, eType, eScenario);

    return (VIDEO_ENCODER_CODEC_API_T*)&_rVideoEncoderAPI;
}

kal_bool VideoAdapterGenStreamHeader(VIDEO_ADAPTOR_CODEC_T eType, kal_uint8* pu1Buffer, kal_uint32 u4BufferSize,
                                                kal_uint32 u4TimeIncrResolution, kal_uint32* pu4EncodedSize)
{
#if defined (__VE_VIDEO_VT_SUPPORT__)
    MPEG4_VT_ENCODER_GEN_VT_HEADER_INPUT_T rHdrInput;
    VCODEC_BUFFER_T rStrmHdr;

    rHdrInput.u4TimeIncrResolution =  u4TimeIncrResolution;
    rHdrInput.u4BufferSize = u4BufferSize;
    rStrmHdr.pu1Buffer_VA = pu1Buffer;

    if (VideoCommIsExtBufferCacheable((kal_uint32)pu1Buffer, u4BufferSize))
    {
        rStrmHdr.pu1Buffer_PA = rStrmHdr.pu1Buffer_VA;//(kal_uint8 *)query_opposite_switchable_cacheaddr_ram((kal_uint32)pu1Buffer);
        rStrmHdr.eBufferStatus =  VA_CACHED;
    }
    else
    {
        rStrmHdr.pu1Buffer_PA = rStrmHdr.pu1Buffer_VA;
        rStrmHdr.eBufferStatus = 0;
    }
    rHdrInput.prBuffer = &rStrmHdr;

    switch (eType)
    {
    case VADP_CODEC_MPEG4:
        if (MPEG4EncoderGenerateVTHeader(&rHdrInput, pu4EncodedSize) == VCODEC_ENC_ERROR_NONE)
        {
            return KAL_TRUE;
        }
    default:
        break;
    }

    //drv_trace1(TRACE_GROUP_10, VENC_ADAPT_ERR_OPERATION, __LINE__);
#endif    
    return KAL_FALSE;
}

#endif
#endif /* __VE_VIDEO_ARCHI_V2__*/

#ifdef __VE_DCM_WITH_COMPRESSION__
#pragma arm section code, rodata
#endif

