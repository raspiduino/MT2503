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
 *   h264_hw_decoder_component_v2.c
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
 *
 * removed!
 *
 * removed!
 ****************************************************************************/

#include "drv_features_video.h"
#ifdef __VE_VIDEO_ARCHI_V2__
#ifdef __VE_H264_DEC_HW_SUPPORT__
 
#include "drv_comm.h" 
#include "video_types_v2.h"
#include "h264_hw_decoder_component_v2.h"
#include "video_buffer_management_v2.h"
#include "vcodec_v2_trc.h"
#include "h264_open_api_video_if.h"
#include "kal_general_types.h"
#include "video_codec_if_v2.h"
#include "kal_public_api.h"
#include "video_codec_type_v2.h"
#include "kal_trace.h"
#include "med_status.h"
#include "video_decoder_demuxer_if_v2.h"
#include "video_dbg_v2.h"
#include "video_codec_mem_v2.h"
#include "cache_sw.h"


#define H264_HW_ALIGNMENT 8192
#define H264_HW_KAL_OVERHEAD 1024
#define H264_HW_ROUND_UP_TO_POWER_OF_TWO(data,x)                                 \
    (((kal_uint32)(data) + (kal_uint32)(x) - 1) & ~((kal_uint32)(x) - 1))

#define H264_HW_DUMMY_DELIMITER_LENGTH 2
#define H264_HW_RETURN_BS_NUM 4
#define H264_HW_DUMMY_YUV_BUFFER_SIZE (((720 * 480 * 3) >> 1) + 32)
static kal_uint8 _au1H264DummyDelimiter[H264_HW_DUMMY_DELIMITER_LENGTH] = {0x09, 0x10};

static H264_HW_DECODER_CTRL_T rH264HwDecCtrl; 
static H264_HW_DEC_RETURN_BS_T rH264HwReturnBs[H264_HW_RETURN_BS_NUM];
static H264_HW_DEC_RETURN_BS_T rLastBs;

extern kal_uint32 query_opposite_switchable_cacheaddr_ram(kal_uint32 addr);
//non public functions which only used in V2 adapter
extern void VideoH264PipelineSupport(void);
extern void VideoH264SetRealDPBSize(kal_uint32 u4DPBSize);

static kal_uint32 H264HwDecoderMallocDPB(void)
{
    kal_uint8* pu1Yuv_addr;
    kal_bool fgCurFrmBufferCacheable;

    if (rH264HwDecCtrl.u2GetPicInOneTrigger)
    {
        //use dummy frame
        //ASSERT(0);
        rH264HwDecCtrl.u2GetPicInOneTrigger++;
        
        return rH264HwDecCtrl.u4DummyYUV;
    }
    else
    {
        pu1Yuv_addr = VideoDecoderGetYUVBuffer();
        rH264HwDecCtrl.u2GetPicInOneTrigger++;
    }

    fgCurFrmBufferCacheable = VideoCommIsExtBufferCacheable((kal_uint32)pu1Yuv_addr, rH264HwDecCtrl.u4BufferSize);

    if ((rH264HwDecCtrl.fgFrmBufferCacheable == KAL_TRUE) && (fgCurFrmBufferCacheable == KAL_FALSE))
    {
        rH264HwDecCtrl.fgFrmBufferSwitch = KAL_TRUE;
        pu1Yuv_addr = (kal_uint8*)VideoCommExtBufferCacheableSwitch((kal_uint32)pu1Yuv_addr ,
                                                                                                    rH264HwDecCtrl.u4BufferSize, VIDEO_CACHEABLE);
    }
    else if ((rH264HwDecCtrl.fgFrmBufferCacheable == KAL_FALSE) && (fgCurFrmBufferCacheable == KAL_TRUE))
    {
        rH264HwDecCtrl.fgFrmBufferSwitch = KAL_TRUE;
        pu1Yuv_addr = (kal_uint8*)VideoCommExtBufferCacheableSwitch((kal_uint32)pu1Yuv_addr , 
                                                                                                    rH264HwDecCtrl.u4BufferSize, VIDEO_NON_CACHEABLE);
    }

    return (kal_uint32)pu1Yuv_addr;
}

static void H264HwDecoderFreeDPB(kal_uint32 u4Addr)
{
    kal_uint8 *pu1Yuv_addr = (kal_uint8 *)u4Addr;
        
    if (pu1Yuv_addr != NULL)
    {
        if ((kal_uint32)pu1Yuv_addr == rH264HwDecCtrl.u4DummyYUV)
        {
            //don't free dummy yuv
            return;
        }
    
        if (rH264HwDecCtrl.fgFrmBufferSwitch == KAL_TRUE)
        {
            pu1Yuv_addr = (kal_uint8*)query_opposite_switchable_cacheaddr_ram((kal_uint32)pu1Yuv_addr);
        }

        VideoDecoderRefFreeYUVBuffer(pu1Yuv_addr);
    }
}

static void H264HwDecoderReturnBitstream(kal_uint32 u4BsBuffer)
{
    H264_HW_DEC_RETURN_BS_T *pBs = (H264_HW_DEC_RETURN_BS_T *)u4BsBuffer;
    kal_uint8 *pu1BsAddr;
    kal_uint16 Idx;

    if (pBs == NULL)
    {
        ASSERT(0);
        return;
    }

    pu1BsAddr = pBs->pBsAddr;
    if ((pu1BsAddr == NULL) || (pBs->BsTotalLen == 0))
    {
        ASSERT(0);
    }

    for (Idx = 0; Idx < H264_HW_RETURN_BS_NUM; Idx++)
    {
        if (pu1BsAddr == rH264HwReturnBs[Idx].pBsAddr)
        {
            if (KAL_TRUE == rH264HwReturnBs[Idx].fgUsed)
            {
                rH264HwReturnBs[Idx].fgUsed = KAL_FALSE;
            }
            else
            {
                //return twice
                if (rH264HwDecCtrl.u2GetPicInOneTrigger <= 1)
                {
                    //ASSERT(0);
                }
                return;
            }
            break;                
        }
    }
    if (Idx == H264_HW_RETURN_BS_NUM)
    {
        ASSERT(0);
    }

    if (rLastBs.pBsAddr != pu1BsAddr)
    {
        //ensure to return bs at the last part
        if (rLastBs.pBsAddr != 0)
        {
            VideoDecoderReturnBitstream(rLastBs.pBsAddr, rLastBs.BsTotalLen);
        }
        rLastBs.pBsAddr = pu1BsAddr;
        rLastBs.BsTotalLen = pBs->BsTotalLen;
    }
}

static void H264HwDecoderOutputFrame(kal_uint32 u4Address, kal_bool fgCorruptedFrame)
{
    if (u4Address == rH264HwDecCtrl.u4DummyYUV)
    {
        //don't display dummy yuv
        return;
    }
    rH264HwDecCtrl.au4OutputList[rH264HwDecCtrl.u4OutWIdx] = u4Address;
    rH264HwDecCtrl.u4OutWIdx = (rH264HwDecCtrl.u4OutWIdx + 1) % H264_HW_MAX_OUT_IDX;
    if (rH264HwDecCtrl.u4OutWIdx == rH264HwDecCtrl.u4OutRIdx)
    {
        ASSERT(0);
    }
}

VIDEO_DECODER_CODEC_ERROR_T H264HwDecoderOpenAdapt(void)
{        
    OPEN_API_MEM_INFO_T rMem;
    
    drv_trace0(TRACE_GROUP_8, H264HWDEC_OPEN);

    VideoH264DecGetParam(OPEN_API_PARAM_MEM_INFO, &rMem, sizeof(OPEN_API_MEM_INFO_T));

    rH264HwDecCtrl.fgBsBufferCacheable = (rMem.isBsCacheable == 1) ? KAL_TRUE : KAL_FALSE;
    rH264HwDecCtrl.fgFrmBufferCacheable = (rMem.isFrameCacheable == 1) ? KAL_TRUE : KAL_FALSE;        
    if (VideoDecoderCheckIntBuffer() != KAL_TRUE)
    {
        rH264HwDecCtrl.u4IntMemOriginalAddr = (kal_uint32)VideoDecoderMalloc(rMem.u4IntMemSize + CPU_CACHE_LINE_SIZE*2);
        if (rH264HwDecCtrl.u4IntMemOriginalAddr == 0)
        {
            ASSERT(0);
        }
        rH264HwDecCtrl.fgExtMemReplaceIntMem = KAL_TRUE;
        rH264HwDecCtrl.u4IntMemAlignSize = H264_HW_ROUND_UP_TO_POWER_OF_TWO(rMem.u4IntMemSize, CPU_CACHE_LINE_SIZE);
        rH264HwDecCtrl.u4IntMemAddr = H264_HW_ROUND_UP_TO_POWER_OF_TWO(rH264HwDecCtrl.u4IntMemOriginalAddr, CPU_CACHE_LINE_SIZE);
        
        /* Should switch to non-cache */
        if (VideoCommIsExtBufferCacheable((kal_uint32)rH264HwDecCtrl.u4IntMemAddr, rH264HwDecCtrl.u4IntMemAlignSize) == KAL_FALSE)
        {
            /* External memory allocated from common part is NON-CACHEABLE */
            rH264HwDecCtrl.fgExtMemReplaceIntMemSwitch = KAL_FALSE;
        }
        else
        {
            rH264HwDecCtrl.fgExtMemReplaceIntMemSwitch = KAL_TRUE;
            rH264HwDecCtrl.u4IntMemAddr = VideoCommExtBufferCacheableSwitch(rH264HwDecCtrl.u4IntMemAddr, 
                                                                                                                                rH264HwDecCtrl.u4IntMemAlignSize, VIDEO_NON_CACHEABLE);
        }
    }
    else
    {
        rH264HwDecCtrl.u4IntMemAddr = VideoDecoderIntBuffer(rMem.u4IntMemSize);
        rH264HwDecCtrl.fgExtMemReplaceIntMem = KAL_FALSE;
    }

    return VIDEO_DECODER_CODEC_ERROR_NONE;
}

VIDEO_DECODER_CODEC_ERROR_T H264HwDecoderCloseAdapt(void)
{
    kal_bool fgCacheable;
    drv_trace0(TRACE_GROUP_8, H264HWDEC_CLOSE);

    if (rH264HwDecCtrl.fgExtMemReplaceIntMem)
    {
        if (rH264HwDecCtrl.fgExtMemReplaceIntMemSwitch)
        {
            fgCacheable = VideoCommIsExtBufferCacheable((kal_uint32)rH264HwDecCtrl.u4IntMemAddr, rH264HwDecCtrl.u4IntMemAlignSize);
            if (fgCacheable == KAL_FALSE)
            {
                VideoCommExtBufferCacheableSwitch(rH264HwDecCtrl.u4IntMemAddr, rH264HwDecCtrl.u4IntMemAlignSize, VIDEO_CACHEABLE);
            }
            else
            {
                //switched internal memory to cacheable???
                ASSERT(0);
            }
        }
        VideoDecoderFree((void *)rH264HwDecCtrl.u4IntMemOriginalAddr);
    }

    return VIDEO_DECODER_CODEC_ERROR_NONE;
}

VIDEO_DECODER_CODEC_ERROR_T H264HwDecoderInitAdapt(void)
{  
    VIDEO_DECODER_CODEC_ERROR_T rRet = VIDEO_DECODER_CODEC_ERROR_NONE;
    OPEN_API_MEM_INFO_T rMem;
    H264_DEC_INIT_PARAM_TYPE_T rParam;
    H264_DECODER_CUSTOM_SETTING_T rCustomSettings;
    kal_uint64 u8MaxResolution;
    kal_uint32 u4RealDPBSize;
    kal_uint32 u4ExtSize;
    kal_uint16 Idx;

    VideoDecoderGetCustomSetting((void *)&rCustomSettings);

    drv_trace0(TRACE_GROUP_8, H264HWDEC_INIT);    

    VideoH264DecGetParam(OPEN_API_PARAM_MEM_INFO, &rMem, sizeof(OPEN_API_MEM_INFO_T));
    
    u4ExtSize = rMem.u4ExtMemSize + H264_HW_DUMMY_YUV_BUFFER_SIZE; 
    rH264HwDecCtrl.u4ExtMemAddr = (kal_uint32)VideoDecoderMalloc(u4ExtSize);
    if (VideoCommIsExtBufferCacheable(rH264HwDecCtrl.u4ExtMemAddr, u4ExtSize))
    {
        rH264HwDecCtrl.u4ExtMemAddr = VideoCommExtBufferCacheableSwitchAlignMemory(rH264HwDecCtrl.u4ExtMemAddr,
                                                                                                        u4ExtSize, VIDEO_NON_CACHEABLE);
    }
    
    rParam.ext_mem_addr.p_addr = rParam.ext_mem_addr.v_addr = H264_HW_ROUND_UP_TO_POWER_OF_TWO(rH264HwDecCtrl.u4ExtMemAddr, H264_HW_ALIGNMENT);    
    rParam.ext_mem_size = rMem.u4ExtMemSize - (rParam.ext_mem_addr.p_addr - rH264HwDecCtrl.u4ExtMemAddr);

    rParam.int_mem_addr.p_addr = rParam.int_mem_addr.v_addr = H264_HW_ROUND_UP_TO_POWER_OF_TWO(rH264HwDecCtrl.u4IntMemAddr, H264_HW_ALIGNMENT);
    rParam.int_mem_size = rMem.u4IntMemSize - (rParam.int_mem_addr.p_addr - rH264HwDecCtrl.u4IntMemAddr);
    rParam.fgDisplayOrderMode = KAL_TRUE;
    rParam.pfnGetYUVBufferCallback = H264HwDecoderMallocDPB;
    rParam.pfnOutputOneFrameCallback = H264HwDecoderOutputFrame;
    rParam.pfnReturnBsBufferCallback = H264HwDecoderReturnBitstream;
    rParam.pfnSetFrameUnReferenceCallback = H264HwDecoderFreeDPB;

    if (VideoH264DecOpen((void *)&rParam) != MEDIA_STATUS_OK)
    {
        rRet = VIDEO_DECODER_CODEC_ERROR;
    }
    VideoH264PipelineSupport();
    u8MaxResolution = rCustomSettings.u8MaxResolution;
    u4RealDPBSize = (kal_uint32)(rCustomSettings.u4DPBSize - ((u8MaxResolution * DECODER_ESSENTIAL_BUFFER_NUM * 3) >> 1));
    VideoH264SetRealDPBSize(u4RealDPBSize);

    rH264HwDecCtrl.fgFrmBufferSwitch = KAL_FALSE;
    rH264HwDecCtrl.fgEOF = KAL_FALSE;
    rH264HwDecCtrl.fgIsCodecInit = KAL_TRUE;
    rH264HwDecCtrl.u2FrameHeight = 0;
    rH264HwDecCtrl.u2FrameWidth = 0;
    rH264HwDecCtrl.u4BufferSize = 0;
    rH264HwDecCtrl.u4BitRate = 0;
    rH264HwDecCtrl.u4FrameRate = 0;
    rH264HwDecCtrl.u4OutRIdx = 0;
    rH264HwDecCtrl.u4OutWIdx = 0;
    rH264HwDecCtrl.u4PicCnt = 0;
    rH264HwDecCtrl.u2GetPicInOneTrigger = 0;
    rH264HwDecCtrl.u4DummyYUV = H264_HW_ROUND_UP_TO_POWER_OF_TWO(rH264HwDecCtrl.u4ExtMemAddr + rParam.ext_mem_size, 32);

    for (Idx = 0; Idx < H264_HW_RETURN_BS_NUM; Idx++)
    {
        rH264HwReturnBs[Idx].fgUsed = KAL_FALSE;
    }
    rLastBs.BsTotalLen = 0;
    rLastBs.pBsAddr = NULL;

    return rRet;
}

VIDEO_DECODER_CODEC_ERROR_T H264HwDecoderDeInitAdapt(void)
{
    if ( rH264HwDecCtrl.fgIsCodecInit != KAL_TRUE )
    {
        ASSERT(0);
        return VIDEO_DECODER_CODEC_ERROR;
    }
    
    drv_trace0(TRACE_GROUP_8, H264HWDEC_DEINIT);
    
    VideoH264DecClose();    
    
    rH264HwDecCtrl.fgIsCodecInit = KAL_FALSE;
    rH264HwDecCtrl.fgEOF = KAL_FALSE;
    rH264HwDecCtrl.fgFrmBufferSwitch = KAL_FALSE;
    rH264HwDecCtrl.u2FrameHeight = 0;
    rH264HwDecCtrl.u2FrameWidth = 0;  
    rH264HwDecCtrl.u4BufferSize = 0;
    rH264HwDecCtrl.u4BitRate = 0;
    rH264HwDecCtrl.u4FrameRate = 0;
    rH264HwDecCtrl.u4OutRIdx = 0;
    rH264HwDecCtrl.u4OutWIdx = 0;

    if (rH264HwDecCtrl.u4ExtMemAddr)
    {
        VideoDecoderFree((void *)rH264HwDecCtrl.u4ExtMemAddr);    
        rH264HwDecCtrl.u4ExtMemAddr = 0;
    }

    return VIDEO_DECODER_CODEC_ERROR_NONE;
}

VIDEO_DECODER_CODEC_ERROR_T H264HwDecoderGetParameterAdapt(VIDEO_DECODER_PARAM_TYPE_T eCmd, void *pParam)
{
    OPEN_API_MEM_INFO_T rMem;   
    
    if (pParam == NULL)
    {
        ASSERT(0);
        return VIDEO_DECODER_CODEC_ERROR_NONE;
    }    

    switch(eCmd)
    {
    case VIDEO_DECODER_PARAM_QUERY_RESOLUTION_AHEAD:
        break;
    case VIDEO_DECODER_PARAM_QUERY_RESOLUTION:
        if (rH264HwDecCtrl.fgIsCodecInit == KAL_TRUE)
        {
            VIDEO_DECODER_QUERY_FRAME_SIZE_TYPE_T* prQueryType = (VIDEO_DECODER_QUERY_FRAME_SIZE_TYPE_T*)pParam;        
            *prQueryType->pu4Height = rH264HwDecCtrl.u2FrameHeight;
            *prQueryType->pu4Width = rH264HwDecCtrl.u2FrameWidth;
        }
        else
        {
            ASSERT(0);
            return VIDEO_DECODER_CODEC_ERROR;            
        }
        break;
    case VIDEO_DECODER_PARAM_MEMORY_REQUIREMENT:
        {
            VIDEO_CODEC_MEMORY_T* prMemorySize = (VIDEO_CODEC_MEMORY_T*)pParam;
            VideoH264DecGetParam(OPEN_API_PARAM_MEM_INFO, &rMem, sizeof(OPEN_API_MEM_INFO_T));
            prMemorySize->u4ExternalSize = rMem.u4ExtMemSize + H264_HW_DUMMY_YUV_BUFFER_SIZE + H264_HW_KAL_OVERHEAD;
            prMemorySize->u4InternalSize = rMem.u4IntMemSize;
            if (VideoDecoderCheckIntBuffer() != KAL_TRUE)
            {
                prMemorySize->u4ExternalSize += prMemorySize->u4InternalSize;
            }
        }
        break;  
    case VIDEO_DECODER_PARAM_EOF:
    default:
        ASSERT(0);
        break;
    };

    return VIDEO_DECODER_CODEC_ERROR_NONE;
}

VIDEO_DECODER_CODEC_ERROR_T H264HwDecoderSetParameterAdapt(VIDEO_DECODER_PARAM_TYPE_T eCmd, void *pParam)
{
    //VIDEO_DECODE_PARAM_T rDecParam;
    kal_uint32 u4FlushBuffer = 1;
    
    switch(eCmd)
    {
    case VIDEO_DECODER_PARAM_EOF:        
        /*rDecParam.u4AddrOfNALu = (kal_uint32)_au1H264DummyDelimiter;
        rDecParam.u4LengthOfNALu = H264_HW_DUMMY_DELIMITER_LENGTH;
        rDecParam.pReseved = NULL;        
        VideoH264DecNALu(&rDecParam);*/
        rH264HwDecCtrl.fgEOF = KAL_TRUE;
    case VIDEO_DECODER_PARAM_FLUSH_BUFFER:    
        VideoH264DecSetParam(OPEN_API_PARAM_FLUSH_BUFFER_CMD, &u4FlushBuffer, sizeof(kal_uint32));
        //return the final bs
        if (rLastBs.pBsAddr != 0)
        {
            VideoDecoderReturnBitstream(rLastBs.pBsAddr, rLastBs.BsTotalLen);
            rLastBs.pBsAddr = NULL;
        }
        break;
    case VIDEO_DECODER_PARAM_BITRATE:
        rH264HwDecCtrl.u4BitRate = *(kal_uint32*)(pParam);
        break;
    case VIDEO_DECODER_PARAM_FRAMERATE:
        rH264HwDecCtrl.u4FrameRate = *(kal_uint32*)(pParam);
        break;
    case VIDEO_DECODER_PARAM_NOT_BUFFERING:
    case VIDEO_DECODER_PARAM_BUFFERING:    
        break;
    default:
        ASSERT(0);
        break;
    };

    return VIDEO_DECODER_CODEC_ERROR_NONE;
}


VIDEO_DECODER_CODEC_ERROR_T H264HwDecoderStartAdapt(VIDEO_BUFFERHEADER_TYPE_T *prBufferHeader)
{    
    VIDEO_DECODER_CODEC_ERROR_T rRet = VIDEO_DECODER_CODEC_ERROR_NONE;    
    H264_DECODER_INPUT_PARAM_T *prInputParam;
    H264_DECODER_PAYLOAD_INFO_T *prPayload;
    kal_uint32 u4PayloadCnt = 0;
    //kal_bool fgNotSupport = KAL_FALSE;
    kal_bool fgCurBsBufferCacheable;
    H264_DECODE_STATUS_CODE_T eResult = H264_STATUS_OK;
    VIDEO_DECODE_PARAM_T rDecParam;
    H264_HW_DEC_RETURN_BS_T *prReturnBs = NULL;
    kal_uint32 u4Addr, u4Length;
    kal_uint32 u4Width, u4Height, u4RealWidth, u4RealHeight;
    kal_uint16 Idx;

    if (prBufferHeader == NULL)
    {
        drv_trace1(TRACE_GROUP_8, H264HWDEC_ARGUMENT_ERROR, __LINE__);
        ASSERT(0);

        return VIDEO_DECODER_CODEC_ERROR;
    }
    
    prInputParam = (H264_DECODER_INPUT_PARAM_T *)prBufferHeader->pPrivateData;

    if ((prInputParam == NULL) || (prBufferHeader->pu1Buffer == NULL) || (prBufferHeader->u4BuffSize == 0))
    {
        drv_trace1(TRACE_GROUP_8, H264HWDEC_ARGUMENT_ERROR, __LINE__);
        ASSERT(0);

        return VIDEO_DECODER_CODEC_ERROR;
    }

    prPayload = prInputParam->pu1PayloadAddress;
    if ((prPayload == NULL) || (prInputParam->u4PayloadNumber == 0))
    {
        drv_trace1(TRACE_GROUP_8, H264HWDEC_ARGUMENT_ERROR, __LINE__);
        ASSERT(0);

        return VIDEO_DECODER_CODEC_ERROR;
    }

    drv_trace1(TRACE_GROUP_8, H264HWDEC_PAYLOAD_INFO, prInputParam->u4PayloadNumber);

    if ((prPayload[0].u4Length != 0) && (prPayload[0].u4Length <= prBufferHeader->u4BuffSize))
    {
        fgCurBsBufferCacheable = VideoCommIsExtBufferCacheable(prPayload[0].u4Address, prPayload[0].u4Length);
    }
    else
    {
        fgCurBsBufferCacheable = rH264HwDecCtrl.fgBsBufferCacheable;
    }

    for (Idx = 0; Idx < H264_HW_RETURN_BS_NUM; Idx++)
    {
        if (rH264HwReturnBs[Idx].fgUsed == KAL_FALSE)
        {
            rH264HwReturnBs[Idx].fgUsed = KAL_TRUE;
            prReturnBs = &rH264HwReturnBs[Idx];
            prReturnBs->BsTotalLen = prBufferHeader->u4BuffSize;
            prReturnBs->pBsAddr = prBufferHeader->pu1Buffer;
            //prReturnBs.totalNalu = prInputParam->u4PayloadNumber;            
            break;
        }
    }
    if (Idx == H264_HW_RETURN_BS_NUM)
    {
        ASSERT(0);
        return VIDEO_DECODER_CODEC_ERROR;
    }

    rH264HwDecCtrl.u2GetPicInOneTrigger = 0;

    do
    {   

        u4Addr = prPayload[u4PayloadCnt].u4Address;
        u4Length = prPayload[u4PayloadCnt].u4Length;        
        if ((u4Length > prBufferHeader->u4BuffSize) || (u4Length == 0))
        {
            drv_trace2(TRACE_GROUP_8, H264HWDEC_ABNORMAL_NALU_SIZE, u4Length, prBufferHeader->u4BuffSize);
            if (u4Length > prBufferHeader->u4BuffSize)
            {
                u4Length = 0;          //huge nalu size, error bitstream, don't decoding, only count nalu num
            }
        }            
        
        if (rH264HwDecCtrl.fgBsBufferCacheable)
        {
            if ((fgCurBsBufferCacheable == KAL_FALSE) && (u4Length != 0))
            {
                u4Addr = VideoCommExtBufferCacheableSwitchAlignMemory(u4Addr , u4Length, VIDEO_CACHEABLE);
            }
        }
        else
        {
            if ((fgCurBsBufferCacheable == KAL_TRUE) && (u4Length != 0))
            {
                u4Addr = VideoCommExtBufferCacheableSwitchAlignMemory(u4Addr , u4Length, VIDEO_NON_CACHEABLE);
            }
        }

        //rReturnBs.NaluCnt = u4PayloadCnt + 1;        
        rDecParam.u4AddrOfNALu = u4Addr;
        rDecParam.u4LengthOfNALu = u4Length;
        rDecParam.pReseved = (void *)prReturnBs;
        
        /* decode one decoding unit */
        eResult = VideoH264DecNALu(&rDecParam);
        drv_trace2(TRACE_GROUP_8, H264HWDEC_DECODE_RESULT, eResult, u4Length);

        switch(eResult)
        {
        case H264_STATUS_OK:
        case H264_STATUS_DECODE_OK:
            if ((!rH264HwDecCtrl.u2FrameWidth) && (!rH264HwDecCtrl.u2FrameHeight))
            {
                H264_DECODER_CUSTOM_SETTING_T rCustomSetting;
                VideoH264DecGetParam(OPEN_API_PARAM_WIDTH, &u4Width, sizeof(kal_uint32));
                VideoH264DecGetParam(OPEN_API_PARAM_HEIGHT, &u4Height, sizeof(kal_uint32));
                VideoH264DecGetParam(OPEN_API_PARAM_REAL_WIDTH, &u4RealWidth, sizeof(kal_uint32));
                VideoH264DecGetParam(OPEN_API_PARAM_REAL_HEIGHT, &u4RealHeight, sizeof(kal_uint32));
                rH264HwDecCtrl.u2FrameHeight = (kal_uint16)u4Height;
                rH264HwDecCtrl.u2FrameWidth = (kal_uint16)u4Width;
                rH264HwDecCtrl.u4BufferSize = ((u4Width * u4Height) *3) >> 1;    
                VideoDecoderGetCustomSetting(&rCustomSetting);

                if ((rH264HwDecCtrl.u2FrameHeight > rCustomSetting.u4MaxHeight) || 
                    (rH264HwDecCtrl.u2FrameWidth > rCustomSetting.u4MaxWidth))
                {
                    H264HwDecoderReturnBitstream((kal_uint32)prReturnBs);
                    
                    return VIDEO_DECODER_CODEC_ERROR_NOT_SUPPORT;
                }
                /* Error handle */
                if (u4Width == 0 || u4Height == 0)
                {
                    return VIDEO_DECODER_CODEC_ERROR_NOT_SUPPORT;
                }
                
                //First slice, set yuv buffer
                VideoDecoderSetYUVBuffer(&u4Width, &u4Height, 4, 0, 0);

                if ((u4Width != u4RealWidth) || (u4Height != u4RealHeight))
                {
                    rH264HwDecCtrl.fgCropping = KAL_TRUE;
                }
                else
                {
                    rH264HwDecCtrl.fgCropping = KAL_FALSE;
                }
            }
            u4PayloadCnt++;
            break;        
        case H264_STATUS_SPS_ERROR:
        case H264_STATUS_PPS_ERROR:
            drv_trace1(TRACE_GROUP_8, H264HWDEC_HEADER_ERROR, __LINE__);       
            H264HwDecoderReturnBitstream((kal_uint32)prReturnBs);
            return VIDEO_DECODER_CODEC_ERROR_NOT_SUPPORT;
        case H264_STATUS_ERROR:
        case H264_STATUS_DECODE_ERROR:
        default:
            drv_trace0(TRACE_GROUP_8, H264HWDEC_DECODE_ERROR);
            VIDEO_WARNING(VIDEO_DBG_OWNER_DECODER);
            u4PayloadCnt++;
            break;
        }       
    }while(u4PayloadCnt < prInputParam->u4PayloadNumber);

    //Send a AU boundary to trigger current frame decoding
    rDecParam.u4AddrOfNALu = (kal_uint32)_au1H264DummyDelimiter;
    rDecParam.u4LengthOfNALu = H264_HW_DUMMY_DELIMITER_LENGTH;
    rDecParam.pReseved = NULL;        
    eResult = VideoH264DecNALu(&rDecParam);
    //FIXME: in unsync mode, it can't return bitstream here!!!
    //H264HwDecoderReturnBitstream((kal_uint32)&rReturnBs);

    return rRet;
}

VIDEO_DECODER_CODEC_ERROR_T H264HwDecoderGetNextDisplay(kal_uint8** pu1NextFrameAddr, VIDEO_DECODER_PRIVATE_OUTPUT_T* prPrivateOutput)
{
    H264_DECODE_CROPPING_T rCropping;
    VIDEO_DECODER_CODEC_ERROR_T rRet = VIDEO_DECODER_CODEC_ERROR_NONE;

    if (prPrivateOutput == NULL)
    {
        drv_trace1(TRACE_GROUP_8, H264HWDEC_ARGUMENT_ERROR, __LINE__);
        ASSERT(0);
        
        return VIDEO_DECODER_CODEC_ERROR;
    }

    *pu1NextFrameAddr = NULL;

    if (rH264HwDecCtrl.u4OutRIdx != rH264HwDecCtrl.u4OutWIdx)
    {
        VideoH264DecGetParam(OPEN_API_PARAM_CROPPING_INFO, &rCropping, sizeof(H264_DECODE_CROPPING_T));
        prPrivateOutput->fgYUVSeperated = KAL_FALSE;//KAL_TRUE;
        prPrivateOutput->pu1YStartAddr = (kal_uint8*)rH264HwDecCtrl.au4OutputList[rH264HwDecCtrl.u4OutRIdx];
        if (rH264HwDecCtrl.fgFrmBufferSwitch == KAL_TRUE)
        {
            if (rH264HwDecCtrl.fgFrmBufferCacheable == KAL_TRUE)
            {
                *pu1NextFrameAddr = (kal_uint8*)VideoCommExtBufferCacheableSwitch((kal_uint32)prPrivateOutput->pu1YStartAddr, 
                                                                                                    rH264HwDecCtrl.u4BufferSize, VIDEO_NON_CACHEABLE);
            }
            else
            {
                *pu1NextFrameAddr = (kal_uint8*)VideoCommExtBufferCacheableSwitch((kal_uint32)prPrivateOutput->pu1YStartAddr,
                                                                                                    rH264HwDecCtrl.u4BufferSize, VIDEO_CACHEABLE);
            }

            if (KAL_TRUE == prPrivateOutput->fgYUVSeperated)
            {
                prPrivateOutput->pu1YStartAddr = (kal_uint8*)query_opposite_switchable_cacheaddr_ram((kal_uint32)(prPrivateOutput->pu1YStartAddr));
                prPrivateOutput->pu1UStartAddr = (kal_uint8*)query_opposite_switchable_cacheaddr_ram((kal_uint32)(prPrivateOutput->pu1UStartAddr));
                prPrivateOutput->pu1VStartAddr = (kal_uint8*)query_opposite_switchable_cacheaddr_ram((kal_uint32)(prPrivateOutput->pu1VStartAddr));
            }
        }
        else
        {
            *pu1NextFrameAddr = prPrivateOutput->pu1YStartAddr;
        }
        //prPrivateOutput->eFrameType = (rDecPic.isIdrPicture) ? VIDEO_CODEC_FRAMETYPE_I : VIDEO_CODEC_FRAMETYPE_P;
        prPrivateOutput->u2FrameHeight = rH264HwDecCtrl.u2FrameHeight;
        prPrivateOutput->u2FrameWidth = rH264HwDecCtrl.u2FrameWidth;
        drv_trace4(TRACE_GROUP_8, H264HWDEC_DISPLAY_INFO, (kal_uint32)*pu1NextFrameAddr,
            prPrivateOutput->u2FrameWidth, prPrivateOutput->u2FrameHeight, rH264HwDecCtrl.fgEOF);
     
        if (rH264HwDecCtrl.fgCropping)
        {
            prPrivateOutput->u2ClipBottom = rCropping.u4BottomY;
            prPrivateOutput->u2ClipRight = rCropping.u4RightX;
            prPrivateOutput->u2ClipLeft = rCropping.u4LeftX;
            prPrivateOutput->u2ClipTop = rCropping.u4TopY;
            drv_trace4(TRACE_GROUP_8, H264HWDEC_CROP_INFO, prPrivateOutput->u2ClipBottom,
            prPrivateOutput->u2ClipRight, prPrivateOutput->u2ClipLeft, prPrivateOutput->u2ClipTop);
        }
        else
        {
            prPrivateOutput->u2ClipBottom = rH264HwDecCtrl.u2FrameHeight - 1;
            prPrivateOutput->u2ClipRight = rH264HwDecCtrl.u2FrameWidth - 1;
            prPrivateOutput->u2ClipLeft = 0;
            prPrivateOutput->u2ClipTop = 0;   
        }

        rH264HwDecCtrl.u4OutRIdx = (rH264HwDecCtrl.u4OutRIdx + 1) % H264_HW_MAX_OUT_IDX;
        rH264HwDecCtrl.u4PicCnt++;
    }
    else
    {
        *pu1NextFrameAddr = NULL;
        if (rH264HwDecCtrl.fgEOF)
        {
            prPrivateOutput->fgEOF = KAL_TRUE;
            rH264HwDecCtrl.fgEOF = KAL_FALSE;
        }
    }    
    
    return rRet;
}

void H264HwSwLAStart(kal_char *pCh)
{
    VIDEO_START_LOGGING(pCh);
}

void H264HwSwLAStop(kal_char *pCh)
{
    VIDEO_STOP_LOGGING(pCh);
}


VIDEO_DECODER_CODEC_API_T rH264HwAPI=
{
    H264HwDecoderOpenAdapt,
    H264HwDecoderInitAdapt,
    H264HwDecoderGetParameterAdapt,
    H264HwDecoderSetParameterAdapt,
    H264HwDecoderStartAdapt,
    H264HwDecoderDeInitAdapt,
    H264HwDecoderCloseAdapt,
    H264HwDecoderGetNextDisplay
};

VIDEO_DECODER_CODEC_API_T* GetH264HwDecoderHandler(VIDEO_DECODER_SCENARIO_T eType)
{
    return &rH264HwAPI;
}

#endif /* __VE_H264_DEC_HW_SUPPORT__ */
#endif /* __VE_VIDEO_ARCHI_V2__ */
