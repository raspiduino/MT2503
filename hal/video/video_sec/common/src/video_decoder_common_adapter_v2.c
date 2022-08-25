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
 *   video_decoder_common_adapter_v2.c
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 * removed!
 ****************************************************************************/
#include "drv_comm.h"
#include "drv_features_video.h"
#ifdef __VE_VIDEO_ARCHI_V2__
#if defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_SW_SUPPORT__) || \
    defined(__VE_RV_DEC_SW_SUPPORT__) || defined(__VE_VP8_DEC_SW_SUPPORT__)
 
#include "video_types_v2.h"
#include "video_buffer_management_v2.h"
#include "vcodec_v2_trc.h"
#include "video_codec_if_v2.h"
//#include "basetype.h"
#include "video_codec_type_v2.h"
#include "kal_trace.h"
#include "video_dbg_v2.h"
#include "video_codec_custom_setting_v2.h"
#include "vcodec_if.h"
#include "video_codec_custom_adapter_v2.h"
#include "video_decoder_common_adapter_v2.h"
#include "vcodec_dec_demuxer_if.h"
#include "video_codec_mem_v2.h"
#include "vcodec_OAL.h"
#include "video_OAL_v2.h"
#include "cache_sw.h"
#include "source_provider_if.h"

#ifdef __VE_DCM_WITH_COMPRESSION__
#include "dcmgr.h" //DCM

#pragma arm section code = "DYNAMIC_CODE_VEDEC_ROCODE", rodata = "DYNAMIC_CODE_VEDEC_RODATA"
#endif

VIDEO_DECODER_ADAPTER_CTRL_T rDecoderAdapterCtrl;

#ifdef __VE_H264_DEC_SW_SUPPORT__
    // To check the struct definitions in Source Provider and Codec
    char H264CheckSize1[(sizeof(H264_DECODER_INPUT_PARAM_T) == sizeof(SPIF_DECODE_PAYLOAD_T)) ? 1 : -1];
    char H264CheckSize2[(sizeof(H264_DECODER_PAYLOAD_INFO_T) == sizeof(SPIF_H264_DECODER_PAYLOAD_INFO_T)) ? 1 : -1];
#endif

static void VideoDecoderAdapterCheckHandle(HANDLE hDrv)
{
    if (rDecoderAdapterCtrl.hDrvHandle != hDrv)
    {
        drv_trace0(TRACE_GROUP_10, VDEC_ADAPT_ERR_HANDLE);  
        ASSERT(0);
    }
}

static void VideoDecoderAdapterCheckPointer(void *ptr)
{
    if (ptr == NULL)
    {
        drv_trace1(TRACE_GROUP_10, VDEC_ADAPT_NULL_PTR, __LINE__);
        ASSERT(0);
        return;
    } 
}

extern kal_uint32 query_opposite_switchable_cacheaddr_ram(kal_uint32 addr);

static void VideoDecoderAdapterMalloc(HANDLE hDrv, unsigned int u4Size, unsigned int u4AlignSize,
                                                                        VCODEC_MEMORY_TYPE_T fgCacheable, VCODEC_BUFFER_T *prBuf)
{
    //kal_bool fgGetCacheable;
    
    VideoDecoderAdapterCheckHandle(hDrv);
    VideoDecoderAdapterCheckPointer(prBuf);

    if (u4AlignSize != CPU_CACHE_LINE_SIZE)
    {
        ASSERT(0);
    }

#if defined(__VE_DYNAMIC_SWITCH_CACHEABILITY__)
    if (fgCacheable == VIDEO_CACHEABLE)
    {
        prBuf->pu1Buffer_VA = (kal_uint8 *)VideoDecoderMallocCacheLineAlign((kal_uint32)u4Size, KAL_TRUE);
        if (prBuf->pu1Buffer_VA == NULL)
        {
            return;
        }
        prBuf->pu1Buffer_PA = (kal_uint8 *)query_opposite_switchable_cacheaddr_ram((kal_uint32)prBuf->pu1Buffer_VA);
        prBuf->eBufferStatus = VA_CACHED;        
    }
    else
    {
        prBuf->pu1Buffer_VA = (kal_uint8 *)VideoDecoderMallocCacheLineAlign((kal_uint32)u4Size, KAL_FALSE);
        prBuf->pu1Buffer_PA = prBuf->pu1Buffer_VA;
        prBuf->eBufferStatus = 0;        
    }
#else
    prBuf->pu1Buffer_VA = prBuf->pu1Buffer_PA = (kal_uint8 *)VideoDecoderMalloc((kal_uint32)u4Size);
    //fgGetCacheable =  VideoCommIsExtBufferCacheable((kal_uint32)prBuf->pu1Buffer_VA, u4Size);
    //prBuf->eBufferStatus = (fgGetCacheable) ? VA_CACHED : 0;
    prBuf->eBufferStatus = (fgCacheable == VIDEO_CACHEABLE) ? VA_CACHED : 0;
#endif    
}

static void VideoDecoderAdapterFree(HANDLE hDrv, VCODEC_BUFFER_T *prBuf)
{
    VideoDecoderAdapterCheckHandle(hDrv);
    VideoDecoderAdapterCheckPointer(prBuf);
    
#if defined(__VE_DYNAMIC_SWITCH_CACHEABILITY__)
    VideoDecoderFreeCacheLineAlign((void *)prBuf->pu1Buffer_VA);
#else
    VideoDecoderFree((void *)prBuf->pu1Buffer_VA);
#endif
}
                                                    
static void VideoDecoderAdapterGetIntMem(HANDLE hDrv, unsigned int u4Size, 
                                                                                unsigned int u4AlignSize, void **pBuffer_adr)
{
    VideoDecoderAdapterCheckHandle(hDrv);
    
    if (u4AlignSize != CPU_CACHE_LINE_SIZE)
    {
        ASSERT(0);
    }    
    if (!u4Size)
    {
        *pBuffer_adr = NULL;
    }
    *pBuffer_adr = (void *)VideoDecoderIntBuffer((kal_uint32)u4Size);
    if (*pBuffer_adr == NULL)
    {
        drv_trace1(TRACE_GROUP_10, VOAL_INT_MEM_ERROR, u4Size);
        rDecoderAdapterCtrl.u4GetIntMemSize = 0;
    }
    else
    {
        rDecoderAdapterCtrl.u4GetIntMemSize = u4Size;
    }
}

static void VideoDecoderAdapterFreeIntMem(HANDLE hDrv, void *pBuffer_adr)
{
    VCODEC_BUFFER_T* prTmp = (VCODEC_BUFFER_T*)pBuffer_adr;
    VideoDecoderAdapterCheckHandle(hDrv);
    //VideoDecoderResetIntBuffer();
    if (0 != rDecoderAdapterCtrl.u4GetIntMemSize)
    {
        VideoDecoderFreeIntMem((kal_uint8*)prTmp->pu1Buffer_VA, rDecoderAdapterCtrl.u4GetIntMemSize);
    }
}
                                                    
static VCODEC_DEC_ERROR_T VideoDecoderAdapterSetYUVBuffer(HANDLE hDrv, VCODEC_DEC_YUV_BUFFER_PARAM_T *prYUVParam)
{
    kal_bool ret;
    VideoDecoderAdapterCheckHandle(hDrv);
    VideoDecoderAdapterCheckPointer(prYUVParam);

    rDecoderAdapterCtrl.fgYUVCacheable = (prYUVParam->rYUVBUfferMemType == VCODEC_BUFFER_CACHEABLE) ? KAL_TRUE : KAL_FALSE;
    rDecoderAdapterCtrl.u4BufferSize = ((prYUVParam->u4Width * prYUVParam->u4Height) * 3) >> 1;
    ret = VideoDecoderSetYUVBuffer((kal_uint32 *)&prYUVParam->u4Width, (kal_uint32 *)&prYUVParam->u4Height, (kal_uint8)prYUVParam->u1Alignment,
                                (kal_uint32)prYUVParam->u4Offset, (kal_uint32)prYUVParam->u4ReduceLength);
    if(ret!=KAL_TRUE)
	   return VCODEC_DEC_ERROR_NOT_SUPPORT;

    return VCODEC_DEC_ERROR_NONE;
}
                                                    
static VCODEC_DEC_ERROR_T VideoDecoderAdapterGetYUVBuffer(HANDLE hDrv, VCODEC_BUFFER_T *prYUVBuf)
{
    VIDEO_MEMORY_SWITCH_T eSwitch;
    kal_uint8 *pu1YUVBuffer;
    kal_bool fgCacheable;
    
    VideoDecoderAdapterCheckHandle(hDrv);
    VideoDecoderAdapterCheckPointer(prYUVBuf);

    pu1YUVBuffer = VideoDecoderGetYUVBuffer();
    fgCacheable =  VideoCommIsExtBufferCacheable((kal_uint32)pu1YUVBuffer, rDecoderAdapterCtrl.u4BufferSize);
    
    prYUVBuf->pu1Buffer_PA = (fgCacheable) ? (kal_uint8 *)query_opposite_switchable_cacheaddr_ram(
                                                (kal_uint32)pu1YUVBuffer) : pu1YUVBuffer;
    prYUVBuf->eBufferStatus = (rDecoderAdapterCtrl.fgYUVCacheable) ? VA_CACHED : 0;
    rDecoderAdapterCtrl.fgYUVOriginCacheable = fgCacheable;

    if (fgCacheable == rDecoderAdapterCtrl.fgYUVCacheable)
    {
        prYUVBuf->pu1Buffer_VA = pu1YUVBuffer;        
    }
    else
    {
        eSwitch = (rDecoderAdapterCtrl.fgYUVCacheable) ? VIDEO_CACHEABLE : VIDEO_NON_CACHEABLE;
        prYUVBuf->pu1Buffer_VA = (kal_uint8 *)VideoCommExtBufferCacheableSwitch((kal_uint32)pu1YUVBuffer, 
                                                                rDecoderAdapterCtrl.u4BufferSize, eSwitch);
    }           
    return VCODEC_DEC_ERROR_NONE;       
}
                                                    
static void VideoDecoderAdapterRefFreeYUVBuffer(HANDLE hDrv, VCODEC_BUFFER_T *prYUVBuf)
{
    kal_uint8 *pu1ReleaseAddr;

    VideoDecoderAdapterCheckHandle(hDrv);
    VideoDecoderAdapterCheckPointer(prYUVBuf);
    if (prYUVBuf->pu1Buffer_VA == NULL)
    {
        drv_trace1(TRACE_GROUP_10, VDEC_ADAPT_ERR_OPERATION, __LINE__);
        return;
    }
    
    if ((prYUVBuf->eBufferStatus == 0 && rDecoderAdapterCtrl.fgYUVCacheable) || 
        (prYUVBuf->eBufferStatus == VA_CACHED && !rDecoderAdapterCtrl.fgYUVCacheable))
    {
        //drv_trace1(TRACE_GROUP_10, VDEC_ADAPT_ERR_OPERATION, __LINE__);
        //return opposite type
        ASSERT(0);

        return;
    }

    if (rDecoderAdapterCtrl.fgYUVOriginCacheable != rDecoderAdapterCtrl.fgYUVCacheable)
    {
        //switch to original type
		pu1ReleaseAddr = (kal_uint8 *)query_opposite_switchable_cacheaddr_ram((kal_uint32)prYUVBuf->pu1Buffer_VA);
    }
    else
    {
        pu1ReleaseAddr = (kal_uint8 *)prYUVBuf->pu1Buffer_VA;
    }
    
    VideoDecoderRefFreeYUVBuffer(pu1ReleaseAddr);

    return;
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
#endif

static VCODEC_DEC_ERROR_T VideoDecoderAdapterQueryInfo(HANDLE hDrv, VCODEC_DEC_QUERY_INFO_TYPE_T query_id, void *pvParamData)
{
    unsigned int *u4Result = (unsigned int *)pvParamData;
    VCODEC_DEC_ERROR_T eRet = VCODEC_DEC_ERROR_NONE;

    VideoDecoderAdapterCheckHandle(hDrv);

    switch (query_id)
    {
        case VCODEC_DEC_QUERY_INFO_AVAILABLE_YUV:
            *u4Result = (unsigned int)VideoDecoderGetAvailableYUV();
            break;
        case VCODEC_DEC_QUERY_INFO_TOTAL_YUV:
            *u4Result = (unsigned int)VideoDecoderGetTotalYUV();
            break;
        case VCODEC_DEC_QUERY_INFO_AVAILABLE_DISPLAY_FRAME:
            *u4Result = (unsigned int)VideoDecoderGetAvailableDisplay();
            break;
        case VCODEC_DEC_QUERY_INFO_REAL_AVAILABLE_DISPLAY_FRAME:
            *u4Result = VideoDecoderGetRealAvailableDisplay();
            break;
        case VCODEC_DEC_QUERY_INFO_OAL_FUNCTION:
            {
                VCODEC_OAL_CALLBACK_T *prOALCallback = (VCODEC_OAL_CALLBACK_T *)pvParamData;
                VideoMemSet((void *)prOALCallback, 0, sizeof(VCODEC_OAL_CALLBACK_T));
                prOALCallback->VCodecQueryMemType = VideoQueryMemType;
                prOALCallback->VCodecQueryPhysicalAddr= VideoQueryPhysicalAddr;
                prOALCallback->VCodecSwitchMemType = VideoSwitchMemType;
                prOALCallback->VCodecFlushCachedBuffer = VideoFlushCachedBuffer;
                prOALCallback->VCodecInvalidateCachedBuffer = VideoInvalidateCachedBuffer;
                prOALCallback->VCodecFlushCachedBufferAll = VideoFlushCachedBufferAll;
                prOALCallback->VCodecInvalidateCachedBufferAll = VideoInvalidateCachedBufferAll;
                prOALCallback->VCodecFlushInvalidateCacheBufferAll = VideoFlushInvalidateCacheBufferAll;
                prOALCallback->VCodecMemSet = VideoMemSet;
                prOALCallback->VCodecMemCopy = VideoMemCopy;
                prOALCallback->VCodecAssertFail = VideoAssertFail;                             
                prOALCallback->VcodecTraceLog0  =  VideoTraceLog0;                 
                prOALCallback->VcodecTraceLog1  =  VideoTraceLog1;                
                prOALCallback->VcodecTraceLog2  =  VideoTraceLog2;                 
                prOALCallback->VcodecTraceLog4  =  VideoTraceLog4;                 
                prOALCallback->VcodecTraceLog8  =  VideoTraceLog8;                                
            }
            break;
        case VCODEC_DEC_QUERY_INFO_CURRENT_TIME:
            {
                kal_uint64 *u8Result = (kal_uint64 *)pvParamData;
                *u8Result = VideoDecoderGetCurrPlayTime();
            }
            break;
        case VCODEC_DEC_QUERY_INFO_LAST_VIDEO_TIME:
            {
                kal_uint64 *u8Result = (kal_uint64 *)pvParamData;
                *u8Result = VideoDecoderGetLastDeliverTime();
            }
            break;
        default:
            drv_trace1(TRACE_GROUP_10, VDEC_ADAPT_ERR_OPERATION, __LINE__);
            *u4Result = 0;
            eRet = VCODEC_DEC_ERROR_NOT_SUPPORT;
            break;
    }

    return eRet;
}
                                                    
static void VideoDecoderAdapterReturnBitstream(HANDLE hDrv, VCODEC_BUFFER_T  *prBuffer, unsigned int u4BuffSize)
{
    VideoDecoderAdapterCheckHandle(hDrv);
    VideoDecoderAdapterCheckPointer(prBuffer);

    if (rDecoderAdapterCtrl.fgBsCacheable != rDecoderAdapterCtrl.fgBsOriginCacheable)
    {
        if (rDecoderAdapterCtrl.fgBsOriginCacheable)
        {
            prBuffer->pu1Buffer_VA = (kal_uint8 *)VideoCommExtBufferCacheableSwitchAlignMemory(
                                                           (kal_uint32)prBuffer->pu1Buffer_VA, u4BuffSize, VIDEO_CACHEABLE);
        }
        else
        {
            prBuffer->pu1Buffer_VA = (kal_uint8 *)VideoCommExtBufferCacheableSwitchAlignMemory(
                                                           (kal_uint32)prBuffer->pu1Buffer_VA, u4BuffSize, VIDEO_NON_CACHEABLE);        
        }
    }

    //FIXME
    VideoDecoderReturnBitstream((kal_uint8 *)prBuffer->pu1Buffer_VA, (kal_uint32)u4BuffSize);
}

VIDEO_DECODER_CODEC_ERROR_T VideoDecoderOpenAdapt(void)
{
    VCODEC_DEC_CALLBACK_T rCallback;
    VCODEC_OPEN_SETTING_T rOpenStruct;
    VCODEC_DEC_ERROR_T eRet = VCODEC_DEC_ERROR_NONE;
    kal_uint32 u4ExtraBufNum;

    rCallback.pfnMalloc             = (PFN_MALLOC)VideoDecoderAdapterMalloc;
    rCallback.pfnIntMalloc          = (PFN_INTMALLOC)VideoDecoderAdapterGetIntMem;
    rCallback.pfnFree               = (PFN_FREE)VideoDecoderAdapterFree;
    rCallback.pfnIntFree            = (PFN_INTFREE)VideoDecoderAdapterFreeIntMem;
    rCallback.pfnSetYUVBuffer       = (PFN_SETYUVBUFFER)VideoDecoderAdapterSetYUVBuffer;
    rCallback.pfnGetYUVBuffer       = (PFN_GETYUVBUFFER)VideoDecoderAdapterGetYUVBuffer;
    rCallback.pfnRefFreeYUVBuffer   = (PFN_REFFREEYUVBuffer)VideoDecoderAdapterRefFreeYUVBuffer;
    rCallback.pfnQueryInfo          = (PFN_QUERYINFO)VideoDecoderAdapterQueryInfo;
    rCallback.pfnReturnBitstream    = (PFN_RETURNBITSTREAM)VideoDecoderAdapterReturnBitstream;

    VideoDecoderMemSet((void *)rOpenStruct.PrivateData, 0, sizeof(unsigned int) * 4);

    switch (rDecoderAdapterCtrl.eDecType)
    {
#ifdef __VE_H264_DEC_SW_SUPPORT__    
    case VADP_CODEC_H264:
        {
            H264_DECODER_PRIVATE_PARAM_T rH264Private;
            H264_DEC_CUSTOM_SETTING_T *prCustomSetting = (H264_DEC_CUSTOM_SETTING_T *)rDecoderAdapterCtrl.prCustomSetting;
            rOpenStruct.MaxSupportWidthForYUV420 = prCustomSetting->MaxSupportWidthForYUV420_BP;
            rOpenStruct.MaxSupportHeightForYUV420 = prCustomSetting->MaxSupportHeightForYUV420_BP;
            rOpenStruct.ExternalMEMSize = prCustomSetting->ExternalMEMSize;
            rH264Private.MaxSupportWidthForYUV420_MPHP = prCustomSetting->MaxSupportWidthForYUV420_MPHP;
            rH264Private.MaxSupportHeightForYUV420_MPHP = prCustomSetting->MaxSupportHeightForYUV420_MPHP;  
            rH264Private.u4dpbSizes = prCustomSetting->DPBSize;
            rOpenStruct.PrivateData[2] = (kal_uint32)&rH264Private;
        }
        break;
#endif        

    case VADP_CODEC_MPEG4:        
    case VADP_CODEC_H263:
        {
            MPEG4_DECODER_PRIVATE_PARAM_T rMPEG4Private;
            MPEG4_DEC_CUSTOM_SETTING_T *prCustomSetting = (MPEG4_DEC_CUSTOM_SETTING_T *)rDecoderAdapterCtrl.prCustomSetting;
            VIDEO_CONTAINER_INFO_T *prContainerInfo     = (VIDEO_CONTAINER_INFO_T *)rDecoderAdapterCtrl.prContainerInfo;
            rOpenStruct.MaxSupportWidthForYUV420 = prCustomSetting->MaxSupportWidthForYUV420_SP;
            rOpenStruct.MaxSupportHeightForYUV420 = prCustomSetting->MaxSupportHeightForYUV420_SP;
            rOpenStruct.ExternalMEMSize = prCustomSetting->ExternalMEMSize;

            rMPEG4Private.MaxSupportWidthForYUV420_ASP = prCustomSetting->MaxSupportWidthForYUV420_ASP;
            rMPEG4Private.MaxSupportHeightForYUV420_ASP = prCustomSetting->MaxSupportHeightForYUV420_ASP;
            rMPEG4Private.u2FrameHeightInContainer      = prContainerInfo->u4ContainerHeight;
            rMPEG4Private.u2FrameWidthInContainer       = prContainerInfo->u4ContainerWidth;

            rOpenStruct.PrivateData[2] = (kal_uint32)&rMPEG4Private;
        }
        break;
    case VADP_CODEC_RV9_10:
        {
            RV9_DEC_CUSTOM_SETTING_T *prCustomSetting = (RV9_DEC_CUSTOM_SETTING_T *)rDecoderAdapterCtrl.prCustomSetting;
            rOpenStruct.MaxSupportWidthForYUV420 = prCustomSetting->MaxSupportWidthForYUV420;
            rOpenStruct.MaxSupportHeightForYUV420 = prCustomSetting->MaxSupportHeightForYUV420;
            rOpenStruct.ExternalMEMSize = prCustomSetting->ExternalMEMSize;
        }
        break;
    case VADP_CODEC_VP8:
        {
            VP8_DEC_CUSTOM_SETTING_T *prCustomSetting = (VP8_DEC_CUSTOM_SETTING_T *)rDecoderAdapterCtrl.prCustomSetting;
            rOpenStruct.MaxSupportWidthForYUV420 = prCustomSetting->MaxSupportWidthForYUV420;
            rOpenStruct.MaxSupportHeightForYUV420 = prCustomSetting->MaxSupportHeightForYUV420;
            rOpenStruct.ExternalMEMSize = prCustomSetting->ExternalMEMSize;
        }
        break;

        
    default:
        //drv_trace1(TRACE_GROUP_10, VDEC_ADAPT_ERR_OPERATION, __LINE__);
        return VIDEO_DECODER_CODEC_ERROR;
    }
    rOpenStruct.eFlag = 0;

    if (VideoDecoderCheckIntBuffer() != KAL_TRUE)
    {
        rOpenStruct.eFlag = INPUT_FLAG_OPENAPI;
        drv_trace0(TRACE_GROUP_10, VDEC_ADAPT_INTRAM_TO_EXTRAM);
    }
    if (rDecoderAdapterCtrl.eScenario == VADP_PREVIEW)
    {
        rOpenStruct.eFlag |= INPUT_FLAG_DECODE_INTRA_ONLY;
    }

    eRet = rDecoderAdapterCtrl.prDecAPI->pfnOpen(rDecoderAdapterCtrl.hDrvHandle, &rCallback, 
                                                                                (void *)&rOpenStruct, &rDecoderAdapterCtrl.hCodecHandle);

    if (eRet != VCODEC_DEC_ERROR_NONE)
    {
        return VIDEO_DECODER_CODEC_ERROR;
    }
    
    u4ExtraBufNum = (rDecoderAdapterCtrl.eScenario == VADP_PREVIEW) ? 0 : (kal_uint32)DECODER_ESSENTIAL_BUFFER_NUM;
    rDecoderAdapterCtrl.prDecAPI->pfnSetParameter(rDecoderAdapterCtrl.hCodecHandle, 
                                                                                VCODEC_DEC_PARAM_EXCLUDE_BUF_NUM, (void *)&u4ExtraBufNum);

    return VIDEO_DECODER_CODEC_ERROR_NONE;
}

VIDEO_DECODER_CODEC_ERROR_T VideoDecoderInitAdapt(void)
{
    VCODEC_DEC_ERROR_T eRet = VCODEC_DEC_ERROR_NONE;

    if (rDecoderAdapterCtrl.fgIsCodecInit == KAL_FALSE)
    {
        eRet = rDecoderAdapterCtrl.prDecAPI->pfnInit(rDecoderAdapterCtrl.hCodecHandle);
    }   

    if (eRet != VCODEC_DEC_ERROR_NONE)
    {
        //drv_trace2(TRACE_GROUP_10, VDEC_ADAPT_ERR_RETURN, (kal_uint32)eRet, __LINE__);
        return VIDEO_DECODER_CODEC_ERROR;
    }    
    rDecoderAdapterCtrl.fgIsCodecInit = KAL_TRUE;
    rDecoderAdapterCtrl.fgEOF = KAL_FALSE;
    rDecoderAdapterCtrl.fgYUVOriginCacheable = KAL_FALSE;
    rDecoderAdapterCtrl.fgYUVCacheable = KAL_FALSE;
    rDecoderAdapterCtrl.fgBsOriginCacheable = KAL_FALSE;
    //get this before init
    //rDecoderAdapterCtrl.fgBsCacheable = KAL_FALSE;
    rDecoderAdapterCtrl.u2FrameWidth = 0;
    rDecoderAdapterCtrl.u2FrameHeight = 0;
    rDecoderAdapterCtrl.u4BufferSize = 0;

    return VIDEO_DECODER_CODEC_ERROR_NONE;
}

VIDEO_DECODER_CODEC_ERROR_T VideoDecoderDeInitAdapt(void)
{
    VCODEC_DEC_ERROR_T eRet = VCODEC_DEC_ERROR_NONE;

    if (rDecoderAdapterCtrl.fgIsCodecInit == KAL_TRUE)
    {
        eRet = rDecoderAdapterCtrl.prDecAPI->pfnDeInit(rDecoderAdapterCtrl.hCodecHandle);
    }
    if (eRet != VCODEC_DEC_ERROR_NONE)
    {
        //drv_trace2(TRACE_GROUP_10, VDEC_ADAPT_ERR_RETURN, (kal_uint32)eRet, __LINE__);
        return VIDEO_DECODER_CODEC_ERROR;
    }     

    rDecoderAdapterCtrl.fgIsCodecInit = KAL_FALSE;
    rDecoderAdapterCtrl.fgEOF = KAL_FALSE;
    rDecoderAdapterCtrl.fgYUVOriginCacheable = KAL_FALSE;
    rDecoderAdapterCtrl.fgYUVCacheable = KAL_FALSE;
    rDecoderAdapterCtrl.fgBsOriginCacheable = KAL_FALSE;
    //rDecoderAdapterCtrl.fgBsCacheable = KAL_FALSE;
    rDecoderAdapterCtrl.u2FrameWidth = 0;
    rDecoderAdapterCtrl.u2FrameHeight = 0;
    rDecoderAdapterCtrl.u4BufferSize = 0;    

    return VIDEO_DECODER_CODEC_ERROR_NONE;
}

VIDEO_DECODER_CODEC_ERROR_T VideoDecoderCloseAdapt(void)
{
    VCODEC_DEC_ERROR_T eRet = VCODEC_DEC_ERROR_NONE;

    eRet = rDecoderAdapterCtrl.prDecAPI->pfnClose(rDecoderAdapterCtrl.hCodecHandle);
    
    if (eRet != VCODEC_DEC_ERROR_NONE)
    {
        //drv_trace2(TRACE_GROUP_10, VDEC_ADAPT_ERR_RETURN, (kal_uint32)eRet, __LINE__);
        return VIDEO_DECODER_CODEC_ERROR;
    }         
    //VideoDecoderMemSet((void *)&rDecoderAdapterCtrl, 0, sizeof(VIDEO_DECODER_ADAPTER_CTRL_T));

    return VIDEO_DECODER_CODEC_ERROR_NONE;
}

VIDEO_DECODER_CODEC_ERROR_T VideoDecoderGetParameterAdapt(VIDEO_DECODER_PARAM_TYPE_T eCmd, void *pParam)
{
    VCODEC_DEC_INPUT_T rDecInput;
    VCODEC_DEC_ERROR_T eRet = VCODEC_DEC_ERROR_NONE;  
    VCODEC_MEMORY_TYPE_T eMemType;
    VCODEC_DEC_API_T *prDecAPI = rDecoderAdapterCtrl.prDecAPI;

    VideoDecoderAdapterCheckPointer(pParam);

    switch(eCmd)
    {
    case VIDEO_DECODER_PARAM_GET_SBSFLAG: 
        {
            kal_uint32 u4SBSFlag = 0;
            prDecAPI->pfnGetParameter(rDecoderAdapterCtrl.hCodecHandle, VCODEC_DEC_PARAM_GET_SBSFLAG, (void*)&u4SBSFlag);    
            *((kal_bool*)pParam) = (u4SBSFlag != 0)? KAL_TRUE : KAL_FALSE;
        }
    break;

    case VIDEO_DECODER_PARAM_MEMORY_REQUIREMENT:
    {
        VIDEO_CODEC_MEMORY_T* prMemorySize = (VIDEO_CODEC_MEMORY_T*)pParam;
        VCODEC_MEMORY_SIZE_T rCodecMemInfo;
        VCODEC_DEC_YUV_BUFFER_PARAM_T rYUV;
        rDecInput.eFlags = INPUT_FLAG_CUSTOM_SETTING;
        if (VideoDecoderCheckIntBuffer() != KAL_TRUE)
        {
            rDecInput.eFlags |= INPUT_FLAG_OPENAPI;
        }
        if (rDecoderAdapterCtrl.eScenario == VADP_PREVIEW)
        {
            rDecInput.eFlags |= INPUT_FLAG_DECODE_INTRA_ONLY;
        }
        rDecInput.prInputData = (VCODEC_DEC_INPUT_DATA_T *)rDecoderAdapterCtrl.prCustomSetting;
        eRet = rDecoderAdapterCtrl.prDecAPI->pfnGetMemoryRequired(&rDecInput, &rCodecMemInfo, &rYUV, &eMemType);        
        prMemorySize->u4ExternalSize = rCodecMemInfo.u4ExternalSize;
        prMemorySize->u4InternalSize = rCodecMemInfo.u4InternalSize;
        if (VideoDecoderCheckIntBuffer() != KAL_TRUE)
        {
            prMemorySize->u4ExternalSize += rCodecMemInfo.u4InternalSize;
        }
        rDecoderAdapterCtrl.fgBsCacheable = (eMemType == VCODEC_BUFFER_CACHEABLE) ? KAL_TRUE : KAL_FALSE;
        drv_trace1(TRACE_GROUP_10, VDEC_ADAPT_EXT_MEM_SIZE, prMemorySize->u4ExternalSize);
        break;
    }
    case VIDEO_DECODER_PARAM_EOF:
        eRet = prDecAPI->pfnGetParameter(rDecoderAdapterCtrl.hCodecHandle, VCODEC_DEC_PARAM_EOF, pParam);
        break;
    case VIDEO_DECODER_PARAM_QUERY_RESOLUTION_AHEAD:
    case VIDEO_DECODER_PARAM_QUERY_RESOLUTION:
        {
            VIDEO_DECODER_QUERY_FRAME_SIZE_TYPE_T* prQueryType = (VIDEO_DECODER_QUERY_FRAME_SIZE_TYPE_T*)pParam;
            VCODEC_DEC_QUERY_FRAME_SIZE_TYPE_T rFrameSize;
            if (eCmd == VIDEO_DECODER_PARAM_QUERY_RESOLUTION)
            {
                eRet = prDecAPI->pfnGetParameter(rDecoderAdapterCtrl.hCodecHandle, VCODEC_DEC_PARAM_QUERY_RESOLUTION, (void *)&rFrameSize);
            }
            else
            {
                eRet = prDecAPI->pfnGetParameter(rDecoderAdapterCtrl.hCodecHandle, VCODEC_DEC_PARAM_QUERY_RESOLUTION_AHEAD, pParam);
            }
            prQueryType->pu1ParamStream = rFrameSize.pu1ParamStream;
            prQueryType->u4ParamLength = rFrameSize.u4ParamLength;
            *prQueryType->pu4Width = rFrameSize.u4Width;
            *prQueryType->pu4Height = rFrameSize.u4Height;
        }
        break;
    case VIDEO_DECODER_PARAM_QUERY_PREDICATION_TIME:
        eRet = prDecAPI->pfnGetParameter(rDecoderAdapterCtrl.hCodecHandle, VCODEC_DEC_PARAM_QUERY_PREDICATION_TIME, pParam);
        break;
    case VIDEO_DECODER_PARAM_CAPABILITY:
        {
            VCODEC_DEC_CAPABILITY_T rCapability;
            VIDEO_DECODER_CODEC_CAPABILITY_T *prCapability = (VIDEO_DECODER_CODEC_CAPABILITY_T *)pParam;
            eRet = prDecAPI->pfnGetParameter(rDecoderAdapterCtrl.hCodecHandle, VCODEC_DEC_PARAM_CAPABILITY, (void *)&rCapability);
            prCapability->u4SupportWidth = rCapability.u4SupportWidth;
            prCapability->u4SupportHeight = rCapability.u4SupportHeight;
            prCapability->u4SupportResolution = rCapability.u4SupportResolution;
            prCapability->u4SupportProfile = rCapability.u4SupportProfile;
            prCapability->u4SupportLevel = rCapability.u4SupportLevel;
        }
        break;
    case VIDEO_DECODER_PARAM_NOT_BUFFERING:
        eRet = prDecAPI->pfnGetParameter(rDecoderAdapterCtrl.hCodecHandle, VCODEC_DEC_PARAM_NOT_BUFFERING, pParam);
        break;
    case VIDEO_DECODER_PARAM_BUFFERING:
        eRet = prDecAPI->pfnGetParameter(rDecoderAdapterCtrl.hCodecHandle, VCODEC_DEC_PARAM_BUFFERING, pParam);
        break;
    case VIDEO_DECODER_PARAM_BITRATE:
        eRet = prDecAPI->pfnGetParameter(rDecoderAdapterCtrl.hCodecHandle, VCODEC_DEC_PARAM_BITRATE, pParam);
        break;
    case VIDEO_DECODER_PARAM_FRAMERATE:
        eRet = prDecAPI->pfnGetParameter(rDecoderAdapterCtrl.hCodecHandle, VCODEC_DEC_PARAM_FRAMERATE, pParam);
        break;
    case VIDEO_DECODER_PARAM_FLUSH_BUFFER:
        eRet = prDecAPI->pfnGetParameter(rDecoderAdapterCtrl.hCodecHandle, VCODEC_DEC_PARAM_FLUSH_BUFFER, pParam);
        break;
    case VIDEO_DECODER_PARAM_HEADER_RETRY:
//        eRet = rDecoderAdapterCtrl.prDecAPI->pfnGetParameter(rDecoderAdapterCtrl.hCodecHandle, VDEC_PARAM_HEADER_RETRY, pParam);
//        break;
    default:
        //drv_trace1(TRACE_GROUP_10, VDEC_ADAPT_ERR_OPERATION, __LINE__);
        return VIDEO_DECODER_CODEC_ERROR_NOT_SUPPORT;
    }

    if (eRet != VCODEC_DEC_ERROR_NONE)
    {
        //drv_trace2(TRACE_GROUP_10, VDEC_ADAPT_ERR_RETURN, (kal_uint32)eRet, __LINE__);
        if (eRet == VCODEC_DEC_ERROR_NOT_SUPPORT)
        {
            return VIDEO_DECODER_CODEC_ERROR_NOT_SUPPORT;
        }
        return VIDEO_DECODER_CODEC_ERROR;
    }  

    return VIDEO_DECODER_CODEC_ERROR_NONE;  
}

VIDEO_DECODER_CODEC_ERROR_T VideoDecoderSetParameterAdapt(VIDEO_DECODER_PARAM_TYPE_T eCmd, void *pParam)
{
    VCODEC_DEC_ERROR_T eRet = VCODEC_DEC_ERROR_NONE;  
    VCODEC_DEC_API_T *prDecAPI = rDecoderAdapterCtrl.prDecAPI;

    switch(eCmd)
    {
    case VIDEO_DECODER_PARAM_SET_DECODE_MODE: 
        eRet = prDecAPI->pfnSetParameter(rDecoderAdapterCtrl.hCodecHandle, VCODEC_DEC_PARAM_SET_DECODE_MODE, pParam);
        break;
    case VIDEO_DECODER_PARAM_DECRYPTION_MODE:
        eRet = prDecAPI->pfnSetParameter(rDecoderAdapterCtrl.hCodecHandle, VCODEC_DEC_PARAM_SET_DECRYPTION_MODE, pParam);
        break;
    case VIDEO_DECODER_PARAM_EOF:
        eRet = prDecAPI->pfnSetParameter(rDecoderAdapterCtrl.hCodecHandle, VCODEC_DEC_PARAM_EOF, pParam);
        break;
    case VIDEO_DECODER_PARAM_QUERY_RESOLUTION_AHEAD:
        eRet = prDecAPI->pfnSetParameter(rDecoderAdapterCtrl.hCodecHandle, VCODEC_DEC_PARAM_QUERY_RESOLUTION_AHEAD, pParam);
        break;
    case VIDEO_DECODER_PARAM_QUERY_RESOLUTION:
        eRet = prDecAPI->pfnSetParameter(rDecoderAdapterCtrl.hCodecHandle, VCODEC_DEC_PARAM_QUERY_RESOLUTION, pParam);
        break;
    case VIDEO_DECODER_PARAM_QUERY_PREDICATION_TIME:
        eRet = prDecAPI->pfnSetParameter(rDecoderAdapterCtrl.hCodecHandle, VCODEC_DEC_PARAM_QUERY_PREDICATION_TIME, pParam);
        break;
    case VIDEO_DECODER_PARAM_MEMORY_REQUIREMENT:
        eRet = prDecAPI->pfnSetParameter(rDecoderAdapterCtrl.hCodecHandle, VCODEC_DEC_PARAM_MEMORY_REQUIREMENT, pParam);
        break;
    case VIDEO_DECODER_PARAM_CAPABILITY:
        eRet = prDecAPI->pfnSetParameter(rDecoderAdapterCtrl.hCodecHandle, VCODEC_DEC_PARAM_CAPABILITY, pParam);
        break;
    case VIDEO_DECODER_PARAM_NOT_BUFFERING:
        eRet = prDecAPI->pfnSetParameter(rDecoderAdapterCtrl.hCodecHandle, VCODEC_DEC_PARAM_NOT_BUFFERING, pParam);
        break;
    case VIDEO_DECODER_PARAM_BUFFERING:
        eRet = prDecAPI->pfnSetParameter(rDecoderAdapterCtrl.hCodecHandle, VCODEC_DEC_PARAM_BUFFERING, pParam);
        break;
    case VIDEO_DECODER_PARAM_BITRATE:
        eRet = prDecAPI->pfnSetParameter(rDecoderAdapterCtrl.hCodecHandle, VCODEC_DEC_PARAM_BITRATE, pParam);
        break;
    case VIDEO_DECODER_PARAM_FRAMERATE:
        eRet = prDecAPI->pfnSetParameter(rDecoderAdapterCtrl.hCodecHandle, VCODEC_DEC_PARAM_FRAMERATE, pParam);
        break;
    case VIDEO_DECODER_PARAM_FLUSH_BUFFER:
        eRet = prDecAPI->pfnSetParameter(rDecoderAdapterCtrl.hCodecHandle, VCODEC_DEC_PARAM_FLUSH_BUFFER, pParam);
        break;
#ifdef __VE_VIDEO_VT_SUPPORT__        
    case VIDEO_DECODER_PARAM_SET_CTRL_VOS:
    {
        VCODEC_DEC_INPUT_T rDecInput;
        VCODEC_BUFFER_T rVideoBuffer;
        VT_CTRL_VOS_T* pVTCtrlVOS = (VT_CTRL_VOS_T*)pParam;
        kal_mem_set(&rDecInput, 0, sizeof(rDecInput));
        kal_mem_set(&rVideoBuffer, 0, sizeof(rVideoBuffer));

        rDecInput.prBuffer = &rVideoBuffer;
        rDecInput.prBuffer->pu1Buffer_VA = pVTCtrlVOS->pu1BufferAddr;
        rDecInput.u4BuffSize             = pVTCtrlVOS->u4BuffSize;
        eRet = prDecAPI->pfnSetParameter(rDecoderAdapterCtrl.hCodecHandle, VCODEC_DEC_PARAM_CTRL_VOS, (void*)&rDecInput);
    }
        break;
#endif        
        
    case VIDEO_DECODER_PARAM_HEADER_RETRY:
        {
//        eRet = prDecAPI->pfnSetParameter(rDecoderAdapterCtrl.hCodecHandle, VDEC_PARAM_HEADER_RETRY, pParam);
            rDecoderAdapterCtrl.u4MaxRetryValue = *((kal_uint32*)pParam);
        }
        break;
        
    default:
        //drv_trace1(TRACE_GROUP_10, VDEC_ADAPT_ERR_OPERATION, __LINE__);
        return VIDEO_DECODER_CODEC_ERROR_NOT_SUPPORT;
    }

    if (eRet != VCODEC_DEC_ERROR_NONE)
    {
        //drv_trace2(TRACE_GROUP_10, VDEC_ADAPT_ERR_RETURN, (kal_uint32)eRet, __LINE__);
        if (eRet == VCODEC_DEC_ERROR_NOT_SUPPORT)
        {
            return VIDEO_DECODER_CODEC_ERROR_NOT_SUPPORT;
        }
        return VIDEO_DECODER_CODEC_ERROR;
    }    

    return VIDEO_DECODER_CODEC_ERROR_NONE;
}

VIDEO_DECODER_CODEC_ERROR_T VideoDecoderStartAdapt(VIDEO_BUFFERHEADER_TYPE_T *prBufferHeader)
{
    VCODEC_DEC_INPUT_T rDecInput;
    VCODEC_BUFFER_T rVideoBuffer;
    VCODEC_DEC_ERROR_T eRet = VCODEC_DEC_ERROR_NONE;  

    //for mpeg-4 local payload
    MPEG4_DECODER_INPUT_PARAM_T rMPEG4Input;
    MPEG4_DECODER_PAYLOAD_INFO_T rMPEG4Payload;

    VideoDecoderAdapterCheckPointer(prBufferHeader);

    rDecInput.u8TimeStamp = prBufferHeader->u8TimeStamp;
    rDecInput.prInputData = (VCODEC_DEC_INPUT_DATA_T *)prBufferHeader->pPrivateData;
    rDecInput.u4BuffSize = prBufferHeader->u4BuffSize;
    rDecInput.prBuffer = &rVideoBuffer;

    rVideoBuffer.pu1Buffer_VA = prBufferHeader->pu1Buffer;
    rDecoderAdapterCtrl.fgBsOriginCacheable =  VideoCommIsExtBufferCacheable((kal_uint32)prBufferHeader->pu1Buffer, prBufferHeader->u4BuffSize);

    if (rDecoderAdapterCtrl.fgBsOriginCacheable == rDecoderAdapterCtrl.fgBsCacheable)
    {
        if (rDecoderAdapterCtrl.fgBsOriginCacheable)
        {
            rVideoBuffer.pu1Buffer_PA = (kal_uint8 *)query_opposite_switchable_cacheaddr_ram(
                                                                                                                    (kal_uint32)rVideoBuffer.pu1Buffer_VA);
            rVideoBuffer.eBufferStatus = VA_CACHED;
        }
        else
        {
            rVideoBuffer.pu1Buffer_PA = rVideoBuffer.pu1Buffer_VA;
            rVideoBuffer.eBufferStatus = 0;
        }
    }
    else
    {
        if (rDecoderAdapterCtrl.fgBsCacheable)
        {
            //current is noncacheable
            rVideoBuffer.pu1Buffer_PA = rVideoBuffer.pu1Buffer_VA;
            //non cacheable -> cacheable
            rVideoBuffer.pu1Buffer_VA = (kal_uint8 *)VideoCommExtBufferCacheableSwitchAlignMemory(
                                                           (kal_uint32)rVideoBuffer.pu1Buffer_VA, prBufferHeader->u4BuffSize, VIDEO_CACHEABLE);
            rVideoBuffer.eBufferStatus = VA_CACHED;
        }
        else
        {
            //cacheable -> non cacheable
            rVideoBuffer.pu1Buffer_VA = (kal_uint8 *)VideoCommExtBufferCacheableSwitchAlignMemory(
                                                           (kal_uint32)rVideoBuffer.pu1Buffer_VA, prBufferHeader->u4BuffSize, VIDEO_NON_CACHEABLE);
            rVideoBuffer.eBufferStatus = 0;
             //current is cacheable
            rVideoBuffer.pu1Buffer_PA = rVideoBuffer.pu1Buffer_VA;
        }    
#ifdef __VE_H264_DEC_SW_SUPPORT__        
        if (rDecoderAdapterCtrl.eDecType == VADP_CODEC_H264)
        {
            H264_DECODER_INPUT_PARAM_T *prH264Input = prBufferHeader->pPrivateData;
            H264_DECODER_PAYLOAD_INFO_T *prPayload = prH264Input->pu1PayloadAddress;
            kal_uint32 u4I;
            if (prPayload != NULL)
            {
                for (u4I = 0; u4I < prH264Input->u4PayloadNumber; u4I++)
                {
                    prPayload[u4I].u4Address = (kal_uint32)query_opposite_switchable_cacheaddr_ram((kal_uint32)prPayload[u4I].u4Address);
                }
            }
        }
#endif        
    }
	
    if ((rDecoderAdapterCtrl.eDecType == VADP_CODEC_MPEG4) || (rDecoderAdapterCtrl.eDecType == VADP_CODEC_H263) || (rDecoderAdapterCtrl.eDecType == VADP_CODEC_VP8))
    {
        rMPEG4Payload.u4Address = (kal_uint32)rVideoBuffer.pu1Buffer_VA;
        rMPEG4Payload.u4Length = prBufferHeader->u4BuffSize;
        rMPEG4Input.u4PayloadNumber = 1;
        rMPEG4Input.pu1PayloadAddress = &rMPEG4Payload;
        rDecInput.prInputData = (VCODEC_DEC_INPUT_DATA_T *)&rMPEG4Input;
    }
	
    switch (prBufferHeader->eFlags)
    {

    case VIDEO_BUFFERFLAG_STARTTIME:
        rDecInput.eFlags = INPUT_FLAG_STARTTIME;
        break;
    case VIDEO_BUFFERFLAG_DECODEONLY:
        rDecInput.eFlags = INPUT_FLAG_DECODEONLY;
        break;
    case VIDEO_BUFFERFLAG_PARAMETERSET:   
        rDecInput.eFlags = INPUT_FLAG_PARAMETERSET;
        break;
    default:
        rDecInput.eFlags = 0;
        break;
    }

    eRet = rDecoderAdapterCtrl.prDecAPI->pfnDecodeOneUnit(rDecoderAdapterCtrl.hCodecHandle, &rDecInput);

    if (eRet != VCODEC_DEC_ERROR_NONE)
    {
        //drv_trace2(TRACE_GROUP_10, VDEC_ADAPT_ERR_RETURN, (kal_uint32)eRet, __LINE__);
        if (VCODEC_DEC_ERROR_NOT_SUPPORT == eRet)
        {
            //drv_trace1(TRACE_GROUP_10, VDEC_ADAPT_ERR_MEM_NOT_SUPPORT, __LINE__);
            return VIDEO_DECODER_CODEC_ERROR_NOT_SUPPORT;
        }
        else if (VCODEC_DEC_ERROR_NOT_ENOUGH_MEM == eRet)
        {
            //drv_trace1(TRACE_GROUP_10, VDEC_ADAPT_ERR_MEM_NOT_ENOUGH, __LINE__);
            return VIDEO_DECODER_CODEC_ERROR_NOT_SUPPORT;
        }
        else if (VCODEC_DEC_ERROR_DECODE_ERROR == eRet)
        {
            if ((VADP_CODEC_MPEG4 == rDecoderAdapterCtrl.eDecType || VADP_CODEC_H264 == rDecoderAdapterCtrl.eDecType)
                && rDecoderAdapterCtrl.u4MaxRetryValue != 0)
            {
                rDecoderAdapterCtrl.u4DecodeErrRetryCount++;

                if (rDecoderAdapterCtrl.u4DecodeErrRetryCount > rDecoderAdapterCtrl.u4MaxRetryValue)
                {
                    // Exceed max retry threshold --> Callback to stop playback.
                    rDecoderAdapterCtrl.u4DecodeErrRetryCount = 0;
                    return VIDEO_DECODER_CODEC_EXCEED_MAX_RETRY;
                }
            }
        }
        
        return VIDEO_DECODER_CODEC_ERROR;
    }        

    // We just accumulate consecutive error.
    // Once decode successfully, reset this count
    rDecoderAdapterCtrl.u4DecodeErrRetryCount = 0;

    return VIDEO_DECODER_CODEC_ERROR_NONE;
}

VIDEO_DECODER_CODEC_ERROR_T VideoDecoderGetNextDisplay(kal_uint8** pu1NextFrameAddr, VIDEO_DECODER_PRIVATE_OUTPUT_T* prPrivateOutput)
{
    VCODEC_DEC_PRIVATE_OUTPUT_T rDispOutput;
    VCODEC_BUFFER_T *prVideoBuffer = &rDispOutput.rYUVStartAddr;
    VCODEC_DEC_ERROR_T eRet = VCODEC_DEC_ERROR_NONE; 
    kal_uint8 *pu1DisplayAddr;
    VIDEO_MEMORY_SWITCH_T eSwitch;
    
    VideoDecoderAdapterCheckPointer(prPrivateOutput);

    prVideoBuffer->pu1Buffer_VA = NULL; //reset output address
    eRet = rDecoderAdapterCtrl.prDecAPI->pfnGetNextDisplay(rDecoderAdapterCtrl.hCodecHandle, &rDispOutput);
    if (eRet != VCODEC_DEC_ERROR_NONE)
    {
        //drv_trace2(TRACE_GROUP_10, VDEC_ADAPT_ERR_RETURN, (kal_uint32)eRet, __LINE__);
        return VIDEO_DECODER_CODEC_ERROR;
    }     

    if (rDispOutput.eDisplayFrameStatus == NO_PIC)
    {
        if (prVideoBuffer->pu1Buffer_VA != NULL)
        {
            //drv_trace1(TRACE_GROUP_10, VDEC_ADAPT_ERR_OPERATION, __LINE__);
            ASSERT(0);
        }
        //no pic display
        *pu1NextFrameAddr = NULL;
        
        return VIDEO_DECODER_CODEC_ERROR_NONE;
    }
    else if (rDispOutput.eDisplayFrameStatus == LAST_FRAME)
    {
        //drv_trace0(TRACE_GROUP_10, VDEC_ADAPT_GET_EOF);
        prPrivateOutput->fgEOF = KAL_TRUE;
       *pu1NextFrameAddr = NULL;
        
        return VIDEO_DECODER_CODEC_ERROR_NONE;        
    }

    if ((prVideoBuffer->eBufferStatus == 0 && rDecoderAdapterCtrl.fgYUVCacheable) || 
        (prVideoBuffer->eBufferStatus == VA_CACHED && !rDecoderAdapterCtrl.fgYUVCacheable))
    {
        //return opposite type
        //drv_trace1(TRACE_GROUP_10, VDEC_ADAPT_ERR_OPERATION, __LINE__);
        ASSERT(0);
    }
    if (rDecoderAdapterCtrl.fgYUVOriginCacheable != rDecoderAdapterCtrl.fgYUVCacheable)
    {
        //switch to original type
        eSwitch = (rDecoderAdapterCtrl.fgYUVOriginCacheable) ? VIDEO_CACHEABLE : VIDEO_NON_CACHEABLE;
        pu1DisplayAddr = (kal_uint8 *)VideoCommExtBufferCacheableSwitch((kal_uint32)prVideoBuffer->pu1Buffer_VA, 
                                                                rDecoderAdapterCtrl.u4BufferSize, eSwitch);        
    }
    else
    {
        pu1DisplayAddr = (kal_uint8 *)prVideoBuffer->pu1Buffer_VA;
    }

    *pu1NextFrameAddr = pu1DisplayAddr;

    //VideoCommIsExtBufferCacheable((kal_uint32)VideoBuffer.pu1Buffer_VA, rDecoderAdapterCtrl.u4BufferSize);

    prPrivateOutput->fgUpdateTime = (rDispOutput.fgUpdateTime) ? KAL_TRUE : KAL_FALSE;
    prPrivateOutput->u8TimeStamp = rDispOutput.u8TimeStamp;
    prPrivateOutput->u2FrameWidth = rDispOutput.u2FrameWidth;
    prPrivateOutput->u2FrameHeight = rDispOutput.u2FrameHeight;
    prPrivateOutput->u2ClipTop = rDispOutput.u2ClipTop;
    prPrivateOutput->u2ClipBottom = rDispOutput.u2ClipBottom;
    prPrivateOutput->u2ClipLeft = rDispOutput.u2ClipLeft;
    prPrivateOutput->u2ClipRight = rDispOutput.u2ClipRight;
    prPrivateOutput->pu1YStartAddr = pu1DisplayAddr;
    if (rDispOutput.eDisplayFrameStatus == REPEAT_LAST)
    {
        prPrivateOutput->fgYUVSeperated = KAL_FALSE;
        prPrivateOutput->fgRepeatLastFrame = KAL_TRUE;
    }
    else if (rDispOutput.eDisplayFrameStatus == NOT_DISPLAY)
    {
        prPrivateOutput->fgYUVSeperated = KAL_FALSE;
        prPrivateOutput->fgNotDisplay = KAL_TRUE;
    }		
    else
    {
        prPrivateOutput->fgYUVSeperated = KAL_TRUE;        
        prPrivateOutput->pu1UStartAddr = prPrivateOutput->pu1YStartAddr + rDispOutput.u4UStartOffset;
        prPrivateOutput->pu1VStartAddr = prPrivateOutput->pu1YStartAddr + rDispOutput.u4VStartOffset;
        prPrivateOutput->fgRepeatLastFrame = KAL_FALSE;
    }
    prPrivateOutput->fgEOF = KAL_FALSE;    
    if (NULL != rDispOutput.prExtra)
    {
        prPrivateOutput->i4AspectRatioWidth  = ((VCODEC_DEC_PRIVATE_OUTPUT_EXTRA_T*)rDispOutput.prExtra)->i4AspectRatioWidth;
        prPrivateOutput->i4AspectRatioHeight = ((VCODEC_DEC_PRIVATE_OUTPUT_EXTRA_T*)rDispOutput.prExtra)->i4AspectRatioHeight;
    }

    switch (rDispOutput.eFrameType)
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
        //drv_trace1(TRACE_GROUP_10, VDEC_ADAPT_ERR_OPERATION, __LINE__);
        prPrivateOutput->eFrameType = VIDEO_CODEC_UNKNOWN_TYPE;
        break;
    }    

    return VIDEO_DECODER_CODEC_ERROR_NONE;
}

static const VIDEO_DECODER_CODEC_API_T rVideoAdapterAPI=
{
    VideoDecoderOpenAdapt,
    VideoDecoderInitAdapt,
    VideoDecoderGetParameterAdapt,
    VideoDecoderSetParameterAdapt,
    VideoDecoderStartAdapt,
    VideoDecoderDeInitAdapt,
    VideoDecoderCloseAdapt,
    VideoDecoderGetNextDisplay
};

VIDEO_DECODER_CODEC_API_T* GetVideoDecoderAdapterHandle(VIDEO_ADAPTOR_CODEC_T eType, VIDEO_ADAPTOR_SCENARIO_T eScenario)
{
    VCODEC_DEC_API_T *prDecAPI;

    // Reset Adapter Context
    kal_mem_set(&rDecoderAdapterCtrl, 0, sizeof(rDecoderAdapterCtrl));


    rDecoderAdapterCtrl.prDecAPI = prDecAPI = GetVideoDecoderAPI(eType, eScenario);

    if (prDecAPI == NULL)
    {
        //drv_trace1(TRACE_GROUP_10, VDEC_ADAPT_GET_CUSTOM_FAILED, __LINE__);
        return NULL;
    }

    if ((!prDecAPI->pfnOpen) || (!prDecAPI->pfnClose) ||
        (!prDecAPI->pfnInit) || (!prDecAPI->pfnDeInit) ||
        (!prDecAPI->pfnSetParameter) || (!prDecAPI->pfnGetParameter) ||
        (!prDecAPI->pfnDecodeOneUnit) || (!prDecAPI->pfnGetNextDisplay) ||
        (!prDecAPI->pfnGetMemoryRequired))
    {
        //drv_trace1(TRACE_GROUP_10, VDEC_ADAPT_ERR_OPERATION, __LINE__);
        ASSERT(0);

        return NULL;
    }

    rDecoderAdapterCtrl.prCustomSetting = GetVideoDecoderCustomSetting(eType, eScenario);

    // For no VOS handle
    if (VADP_CODEC_MPEG4 == eType || VADP_CODEC_H263 == eType)
    {
        rDecoderAdapterCtrl.prContainerInfo  = VideoDecoderGetContainerInfo();
    }

    if (rDecoderAdapterCtrl.prCustomSetting == NULL)
    {
        //drv_trace1(TRACE_GROUP_10, VDEC_ADAPT_GET_CUSTOM_FAILED, __LINE__);
        ASSERT(0);

        return NULL;
    }
    
    rDecoderAdapterCtrl.hDrvHandle = (HANDLE)&rVideoAdapterAPI;
    rDecoderAdapterCtrl.eDecType = eType;
    rDecoderAdapterCtrl.eScenario = eScenario;

    //drv_trace2(TRACE_GROUP_10, VDEC_ADAPT_GET_HANDLE, eType, eScenario);

    return (VIDEO_DECODER_CODEC_API_T*)&rVideoAdapterAPI;
}

#ifdef __VE_DCM_WITH_COMPRESSION__
#pragma arm section code, rodata
#endif

#endif
#endif /* __VE_VIDEO_ARCHI_V2__ */
