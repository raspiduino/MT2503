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
 *   mjpeg_decoder_component_v2.c
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 ****************************************************************************/
#include "drv_comm.h"

#ifdef __VIDEO_ARCHI_V2__
#ifdef __MJPEG_DEC_SW_SUPPORT__
 
#include "dcmgr.h"
#include "video_types_v2.h"
#include "mjpeg_decoder_component_v2.h"
#include "jpeg_mjpeg_mem.h"
#include "video_buffer_management_v2.h"
#include "vcodec_v2_trc.h"
#include "video_codec_if_v2.h"
#include "video_codec_type_v2.h"
#include "video_types_v2.h"
#include "kal_trace.h"
#include "video_dbg_v2.h"
#include "fsal.h"
#include "jpeg_decode_api.h"

#define MJPEG_HW_ROUND_UP_TO_POWER_OF_TWO(data,x)                                 \
    (((kal_uint32)(data) + (kal_uint32)(x) - 1) & ~((kal_uint32)(x) - 1))

static MJPEG_DECODER_CTRL_T rMJPEGDecCtrl; 
static kal_bool _fgMJPEGEventCreate = KAL_FALSE;

extern kal_uint32 query_opposite_switchable_cacheaddr_ram(kal_uint32 addr);

static kal_int32 MJPEGDecoderCallback(JPEG_CODEC_STATE_ENUM state)
{
    drv_trace1(TRACE_GROUP_8, MJPEGDEC_DECODE_STATE, state);

    if (state == JPEG_CODEC_STATE_PAUSED)
    {
#if defined (__VE_MJPEG_DEC_SUPPORT_MT6256_SERIES__)
        kal_set_eg_events(rMJPEGDecCtrl.EventId, EVENT_MJPEG_DEC_RESUME, KAL_OR);
#endif
    }
    else if (state == JPEG_CODEC_STATE_BUSY)
    {
        /* still decoding, nothing to do... */
    }
    else
    {
        switch (state)
        {   
            case JPEG_CODEC_STATE_COMPLETE:             /* the module is stopped after the completion of task */
            case JPEG_CODEC_STATE_FREE:                 /* the module is free to use */
            case JPEG_CODEC_STATE_IDLE:                 /* the module is acquired by some body */
            case JPEG_CODEC_STATE_EOF:
            case JPEG_CODEC_STATE_ERROR:                /* the module is stopped due to error */
                kal_set_eg_events(rMJPEGDecCtrl.EventId, EVENT_MJPEG_DEC_COMPLETE, KAL_OR);
                break;
            
            default:
                ASSERT(0);
                break;
        }
    }

    return 0;
}

static void *MJPEGDecoderMallocYUV(void)
{
    kal_uint8* pu1Yuv_addr = VideoDecoderGetYUVBuffer();
    kal_bool fgCurFrmBufferCacheable;

    fgCurFrmBufferCacheable = VideoCommIsExtBufferCacheable((kal_uint32)pu1Yuv_addr, rMJPEGDecCtrl.u4BufferSize);

    if ((rMJPEGDecCtrl.fgFrmBufferCacheable == KAL_TRUE) && (fgCurFrmBufferCacheable == KAL_FALSE))
    {
        rMJPEGDecCtrl.fgFrmBufferSwitch = KAL_TRUE;
        pu1Yuv_addr = (kal_uint8*)VideoCommExtBufferCacheableSwitch((kal_uint32)pu1Yuv_addr ,
                                                                                                    rMJPEGDecCtrl.u4BufferSize, VIDEO_CACHEABLE);
    }
    else if ((rMJPEGDecCtrl.fgFrmBufferCacheable == KAL_FALSE) && (fgCurFrmBufferCacheable == KAL_TRUE))
    {
        rMJPEGDecCtrl.fgFrmBufferSwitch = KAL_TRUE;
        pu1Yuv_addr = (kal_uint8*)VideoCommExtBufferCacheableSwitch((kal_uint32)pu1Yuv_addr , 
                                                                                                    rMJPEGDecCtrl.u4BufferSize, VIDEO_NON_CACHEABLE);
    }

    return (void*)pu1Yuv_addr;
}

static void MJPEGDecoderFreeYUV(void *ptr)
{
    kal_uint8 *pu1Yuv_addr = (kal_uint8 *)ptr;
        
    if (pu1Yuv_addr != NULL)
    {
        if (rMJPEGDecCtrl.fgFrmBufferSwitch == KAL_TRUE)
        {
            pu1Yuv_addr = (kal_uint8*)query_opposite_switchable_cacheaddr_ram((kal_uint32)pu1Yuv_addr);
        }

        VideoDecoderRefFreeYUVBuffer(pu1Yuv_addr);
    }
}

static void MJPEGDecoderReturnBitstream(kal_uint32 u4Addr, kal_uint32 u4Size)
{
    kal_uint8 *pu1BsAddr = (kal_uint8 *)u4Addr;
    kal_bool fgCacheable;

    if ((u4Addr == 0) || (u4Size == 0))
    {
        ASSERT(0);
        return;
    }

    fgCacheable = VideoCommIsExtBufferCacheable(u4Addr, u4Size);
    if ((!rMJPEGDecCtrl.fgBsSrcCacheable) && fgCacheable)
    {
        pu1BsAddr = (kal_uint8 *)VideoCommExtBufferCacheableSwitchAlignMemory(u4Addr, u4Size, VIDEO_NON_CACHEABLE);
    }
    else if (rMJPEGDecCtrl.fgBsSrcCacheable && (!fgCacheable))
    {
        pu1BsAddr = (kal_uint8 *)VideoCommExtBufferCacheableSwitchAlignMemory(u4Addr, u4Size, VIDEO_CACHEABLE);
    }
    VideoDecoderReturnBitstream(pu1BsAddr, u4Size);
}

VIDEO_DECODER_CODEC_ERROR_T MJPEGDecoderOpenAdapt(void)
{
    VIDEO_DECODER_CODEC_ERROR_T rRet = VIDEO_DECODER_CODEC_ERROR_NONE;

#if 0
#if defined(MT6236_CODEC_SERIES)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#if defined(MT6253_CODEC_SERIES)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

    drv_trace0(TRACE_GROUP_8, MJPEGDEC_OPEN);

    if(_fgMJPEGEventCreate == KAL_FALSE)
    {
        rMJPEGDecCtrl.EventId = kal_create_event_group("MJPEG_DEC_EVEVT");
        _fgMJPEGEventCreate = KAL_TRUE;
    }

    return rRet;
}

VIDEO_DECODER_CODEC_ERROR_T MJPEGDecoderInitAdapt(void)
{
   kal_uint32 u4CacheSizeBest, u4CacheSizeMinimum;
   kal_uint32 u4ReadBufferSizeBest, u4ReadBufferSizeMinimum;
   kal_uint32 u4IntMemSize, u4ExtMemSize;
    
    drv_trace0(TRACE_GROUP_8, MJPEGDEC_INIT);

    jpegDecQueryFileBuffer(rMJPEGDecCtrl.rMJPEGHandle, 
                          &u4ReadBufferSizeBest, &u4ReadBufferSizeMinimum,
                          &u4CacheSizeBest, &u4CacheSizeMinimum);

    rMJPEGDecCtrl.pu1Cache = NULL;
    rMJPEGDecCtrl.pu1ReadBuffer = NULL;

    if (u4CacheSizeMinimum)
    {
        rMJPEGDecCtrl.pu1Cache = (kal_uint8 *)VideoDecoderMalloc(sizeof(kal_uint8) * u4CacheSizeMinimum);

        if ((void *)rMJPEGDecCtrl.pu1Cache == NULL)
        {
            drv_trace0(TRACE_GROUP_8, MJPEGDEC_INIT_ERROR);
            ASSERT(0);
        }    
    }
    if (u4ReadBufferSizeMinimum)
    {
        rMJPEGDecCtrl.pu1ReadBuffer = (kal_uint8 *)VideoDecoderMalloc(sizeof(kal_uint8) * u4ReadBufferSizeMinimum);

        if ((void *)rMJPEGDecCtrl.pu1ReadBuffer == NULL)
        {
            drv_trace0(TRACE_GROUP_8, MJPEGDEC_INIT_ERROR);
            ASSERT(0);
        }    
    }

    u4IntMemSize = rMJPEGDecCtrl.u4IntMemSize;
    u4ExtMemSize = rMJPEGDecCtrl.u4ExtMemSize - u4CacheSizeMinimum - u4ReadBufferSizeMinimum;
    
    rMJPEGDecCtrl.u4IntMemAddr = 0;
    rMJPEGDecCtrl.u4ExtMemAddr = 0;

    if (u4IntMemSize)
    {
        rMJPEGDecCtrl.u4IntMemAddr = VideoDecoderIntBuffer(u4IntMemSize);

        if ((void *)rMJPEGDecCtrl.u4IntMemAddr == NULL)
        {
            drv_trace0(TRACE_GROUP_8, MJPEGDEC_INIT_ERROR);
            ASSERT(0);
        }    
    }
    if (u4ExtMemSize)
    {
        rMJPEGDecCtrl.u4ExtMemAddr = (kal_uint32)VideoDecoderMalloc(u4ExtMemSize);

        if ((void *)rMJPEGDecCtrl.u4ExtMemAddr == NULL)
        {
            drv_trace0(TRACE_GROUP_8, MJPEGDEC_INIT_ERROR);
            ASSERT(0);
        }    
    }

    rMJPEGDecCtrl.fgBsSrcCacheable = KAL_FALSE;
    rMJPEGDecCtrl.fgFrmBufferSwitch = KAL_FALSE;
    rMJPEGDecCtrl.fgEOF = KAL_FALSE;
    rMJPEGDecCtrl.fgErrorDecoding = KAL_FALSE;
    rMJPEGDecCtrl.fgIsCodecInit = KAL_TRUE;
    rMJPEGDecCtrl.u2FrameHeight = 0;
    rMJPEGDecCtrl.u2FrameWidth = 0;
    rMJPEGDecCtrl.u2RealFrameHeight = 0;
    rMJPEGDecCtrl.u2RealFrameWidth = 0;
    rMJPEGDecCtrl.u4SelectedWidthFactor = 0;
    rMJPEGDecCtrl.u4SelectedHeightFactor = 0;
    rMJPEGDecCtrl.u4BufferSize = 0;
    rMJPEGDecCtrl.u4OutAddr = 0;
    rMJPEGDecCtrl.u8FrameTime = 0;

    return VIDEO_DECODER_CODEC_ERROR_NONE;
}

VIDEO_DECODER_CODEC_ERROR_T MJPEGDecoderDeInitAdapt(void)
{
    if ( rMJPEGDecCtrl.fgIsCodecInit == KAL_TRUE )
    {
        drv_trace0(TRACE_GROUP_8, MJPEGDEC_DEINIT);
        if ((void *)rMJPEGDecCtrl.pu1Cache != NULL)
        {
            VideoDecoderFree((void *)rMJPEGDecCtrl.pu1Cache);
        }
        if ((void *)rMJPEGDecCtrl.pu1ReadBuffer != NULL)
        {
            VideoDecoderFree((void *)rMJPEGDecCtrl.pu1ReadBuffer);
        }
        if ((void *)rMJPEGDecCtrl.u4ExtMemAddr != NULL)
        {
            VideoDecoderFree((void *)rMJPEGDecCtrl.u4ExtMemAddr);
        }
        rMJPEGDecCtrl.pu1ReadBuffer = NULL;
        rMJPEGDecCtrl.pu1Cache = NULL;
        rMJPEGDecCtrl.u4ExtMemAddr = 0;
    }
    
    rMJPEGDecCtrl.fgIsCodecInit = KAL_FALSE;
    rMJPEGDecCtrl.fgEOF = KAL_FALSE;
    rMJPEGDecCtrl.fgErrorDecoding = KAL_FALSE;
    rMJPEGDecCtrl.fgBsSrcCacheable = KAL_FALSE;
    rMJPEGDecCtrl.fgFrmBufferSwitch = KAL_FALSE;
    rMJPEGDecCtrl.u2FrameHeight = 0;
    rMJPEGDecCtrl.u2FrameWidth = 0;  
    rMJPEGDecCtrl.u2RealFrameHeight = 0;
    rMJPEGDecCtrl.u2RealFrameWidth = 0;  
    rMJPEGDecCtrl.u4SelectedWidthFactor = 0;
    rMJPEGDecCtrl.u4SelectedHeightFactor = 0;
    rMJPEGDecCtrl.u4BufferSize = 0;
    rMJPEGDecCtrl.u4OutAddr = 0;
    rMJPEGDecCtrl.u8FrameTime = 0;

    return VIDEO_DECODER_CODEC_ERROR_NONE;
}

VIDEO_DECODER_CODEC_ERROR_T MJPEGDecoderCloseAdapt(void)
{
#if 0
#if defined (MT6236_CODEC_SERIES)
/* under construction !*/
#endif
/* under construction !*/
#if defined(MT6253_CODEC_SERIES)
/* under construction !*/
/* under construction !*/
#endif
#endif

    drv_trace0(TRACE_GROUP_8, MJPEGDEC_CLOSE);

    jpegDecReleaseDecoder(rMJPEGDecCtrl.rMJPEGHandle);

    return VIDEO_DECODER_CODEC_ERROR_NONE;
}

VIDEO_DECODER_CODEC_ERROR_T MJPEGDecoderGetParameterAdapt(VIDEO_DECODER_PARAM_TYPE_T eCmd, void *pParam)
{  
    if (pParam == NULL)
    {
        ASSERT(0);
        return VIDEO_DECODER_CODEC_ERROR_NONE;
    }
    //VideoDecoderGetCustomSetting((void*)(&rCustomSetting));

    switch(eCmd)
    {
    case VIDEO_DECODER_PARAM_QUERY_RESOLUTION_AHEAD:
    case VIDEO_DECODER_PARAM_QUERY_RESOLUTION:
        if (rMJPEGDecCtrl.fgIsCodecInit == KAL_TRUE)
        {
            VIDEO_DECODER_QUERY_FRAME_SIZE_TYPE_T* prQueryType = (VIDEO_DECODER_QUERY_FRAME_SIZE_TYPE_T*)pParam;        
            *prQueryType->pu4Height = (kal_uint32)rMJPEGDecCtrl.u2FrameHeight;
            *prQueryType->pu4Width = (kal_uint32)rMJPEGDecCtrl.u2FrameWidth;
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
        
            prMemorySize->u4InternalSize = JPEG_DEC_MJPEG_INT_MIN_MEM_SIZE;
            prMemorySize->u4ExternalSize = JPEG_DEC_MJPEG_EXT_MIN_MEM_SIZE;

            rMJPEGDecCtrl.u4IntMemSize = prMemorySize->u4InternalSize;
            rMJPEGDecCtrl.u4ExtMemSize = prMemorySize->u4ExternalSize;
        }
        break;  
    case VIDEO_DECODER_PARAM_QUERY_PREDICATION_TIME:
    #ifdef __CONTOUR_IMPROVEMENT_SUPPORT__
        {
            kal_uint32* pu4PredicationTime = (kal_uint32*)(pParam);

            *pu4PredicationTime = 0xFFFF;
        }
				break;
    #else
        return VIDEO_DECODER_CODEC_ERROR_NOT_SUPPORT;
    #endif /* __CONTOUR_IMPROVEMENT_SUPPORT__ */
    case VIDEO_DECODER_PARAM_GET_SBSFLAG:
        *((kal_bool*)(pParam)) = KAL_FALSE;
        break;
    case VIDEO_DECODER_PARAM_EOF:
    default:
        ASSERT(0);
        break;
    };

    return VIDEO_DECODER_CODEC_ERROR_NONE;
}

VIDEO_DECODER_CODEC_ERROR_T MJPEGDecoderSetParameterAdapt(VIDEO_DECODER_PARAM_TYPE_T eCmd, void *pParam)
{
    switch(eCmd)
    {
    case VIDEO_DECODER_PARAM_EOF:
        rMJPEGDecCtrl.fgEOF = KAL_TRUE;
        break;
    case VIDEO_DECODER_PARAM_BITRATE:
    case VIDEO_DECODER_PARAM_FRAMERATE:        
    case VIDEO_DECODER_PARAM_NOT_BUFFERING:
    case VIDEO_DECODER_PARAM_BUFFERING:    
    case VIDEO_DECODER_PARAM_FLUSH_BUFFER:      
    case VIDEO_DECODER_PARAM_HEADER_RETRY:      
        break;
    default:
        ASSERT(0);
        break;
    };

    return VIDEO_DECODER_CODEC_ERROR_NONE;
}

VIDEO_DECODER_CODEC_ERROR_T MJPEGDecoderStartAdapt(VIDEO_BUFFERHEADER_TYPE_T *prBufferHeader)
{
    VIDEO_DECODER_CODEC_ERROR_T rRet = VIDEO_DECODER_CODEC_ERROR_NONE;    
    MJPEG_DECODER_CUSTOM_SETTING_T rCustomSettings;
    STFSAL jpegFile;
    JPEG_STATUS_ENUM eDecRet;
    kal_uint32 u4ReadBufferSizeBest, u4ReadBufferSizeMinimum;
    kal_uint32 u4IntMemSizeBest, u4IntMemSizeMinimum, u4ExtMemSizeBest, u4ExtMemSizeMinimum;
    kal_uint32 u4IntMemSize, u4ExtMemSize;
    kal_uint32 u4CacheSizeBest = 0;
    kal_uint32 u4CacheSizeMinimum = 0;
    kal_uint32 u4RealBsAddr;
    kal_uint32 u4UAddr, u4VAddr, u4Width, u4Height;
    kal_uint32 u4EventGroup;
    kal_uint8 *pu1YUVBuffer;
    kal_uint16 u2Width, u2Height;
    kal_uint32 u4DecodeStartTime, u4DecodeTime;
    kal_uint64 u8CurrentPlayTime;
    kal_bool fgCurBsBufferCacheable;
    kal_int32 s4SrcWidthBit, s4SrcHeightBit, s4MaxResizeBit;
    VIDEO_RESIZE_FACTOR_TYPE_T pResizeFactor;

    jpegDecReset(rMJPEGDecCtrl.rMJPEGHandle);

    if (prBufferHeader == NULL)
    {
        drv_trace1(TRACE_GROUP_8, MJPEGDEC_ARGUMENT_ERROR, __LINE__);
        ASSERT(0);

        return VIDEO_DECODER_CODEC_ERROR;
    }
    if ((prBufferHeader->pu1Buffer == NULL) || (prBufferHeader->u4BuffSize == 0))
    {
        drv_trace1(TRACE_GROUP_8, MJPEGDEC_ARGUMENT_ERROR, __LINE__);
        ASSERT(0);

        return VIDEO_DECODER_CODEC_ERROR;
    }

    u8CurrentPlayTime = VideoDecoderGetCurrPlayTime();
    // if current time + decode time > display time, then skip current frame
    if (u8CurrentPlayTime + rMJPEGDecCtrl.u8FrameTime > prBufferHeader->u8TimeStamp)
    {
        drv_trace4(TRACE_GROUP_8, MJPEGDEC_AVSYNC_ERROR, (kal_uint32)prBufferHeader->u8TimeStamp, 
                     (kal_uint32)u8CurrentPlayTime, (kal_uint32)rMJPEGDecCtrl.u8FrameTime, video_get_current_time());

        MJPEGDecoderReturnBitstream((kal_uint32)prBufferHeader->pu1Buffer, prBufferHeader->u4BuffSize);
        rMJPEGDecCtrl.fgErrorDecoding = KAL_TRUE;

        return VIDEO_DECODER_CODEC_ERROR_NONE;
    }
    else
    {
        //Analyze bitstream buffer's cache type
        fgCurBsBufferCacheable = VideoCommIsExtBufferCacheable((kal_uint32)prBufferHeader->pu1Buffer, prBufferHeader->u4BuffSize);
        rMJPEGDecCtrl.fgBsSrcCacheable = fgCurBsBufferCacheable;

        u4RealBsAddr = (kal_uint32)prBufferHeader->pu1Buffer;  //prepare for cache switch

        //Cache Switch for a frame bitstream
        if (rMJPEGDecCtrl.fgBsBufferCacheable)
        {
            if (fgCurBsBufferCacheable == KAL_FALSE)
            {
                u4RealBsAddr = VideoCommExtBufferCacheableSwitchAlignMemory((kal_uint32)prBufferHeader->pu1Buffer,
                                                                            prBufferHeader->u4BuffSize, VIDEO_CACHEABLE);
            }
        }
        else
        {
            if (fgCurBsBufferCacheable == KAL_TRUE)
            {
                u4RealBsAddr = VideoCommExtBufferCacheableSwitchAlignMemory((kal_uint32)prBufferHeader->pu1Buffer,
                                                                            prBufferHeader->u4BuffSize, VIDEO_NON_CACHEABLE);
            }
        }

        FSAL_Direct_SetRamFileSize(&jpegFile, prBufferHeader->u4BuffSize);
        if (FSAL_OK != FSAL_Open(&jpegFile, (void *)u4RealBsAddr, FSAL_ROMFILE))
        {
            drv_trace1(TRACE_GROUP_8, MJPEGDEC_SETBUF_ERROR, __LINE__);
            MJPEGDecoderReturnBitstream(u4RealBsAddr, prBufferHeader->u4BuffSize);
            ASSERT(0);

            return VIDEO_DECODER_CODEC_ERROR;
        }
        jpegDecQueryFileBuffer(rMJPEGDecCtrl.rMJPEGHandle, 
                               &u4ReadBufferSizeBest, &u4ReadBufferSizeMinimum,
                               &u4CacheSizeBest, &u4CacheSizeMinimum);
    
        u4IntMemSize = rMJPEGDecCtrl.u4IntMemSize;
        u4ExtMemSize = rMJPEGDecCtrl.u4ExtMemSize;

        if ((u4ReadBufferSizeMinimum + u4CacheSizeMinimum) > u4ExtMemSize)
        {
            ASSERT(0);
        }
        else
        {
            u4ExtMemSize -= (u4ReadBufferSizeMinimum + u4CacheSizeMinimum);

            if (JPEG_STATUS_OK != jpegDecSetSourceFile(rMJPEGDecCtrl.rMJPEGHandle, &jpegFile, rMJPEGDecCtrl.pu1ReadBuffer, 
                                                       u4ReadBufferSizeMinimum , rMJPEGDecCtrl.pu1Cache, u4CacheSizeMinimum))
            {
                drv_trace1(TRACE_GROUP_8, MJPEGDEC_SETBUF_ERROR, __LINE__);
#if 0
/* under construction !*/
#endif
                MJPEGDecoderReturnBitstream(u4RealBsAddr, prBufferHeader->u4BuffSize);        
                FSAL_Close(&jpegFile);
    
                return VIDEO_DECODER_CODEC_ERROR;
            }
        }

        jpegDecQueryWorkingMemory(rMJPEGDecCtrl.rMJPEGHandle, 
                                 &u4IntMemSizeBest, &u4IntMemSizeMinimum,
                                 &u4ExtMemSizeBest, &u4ExtMemSizeMinimum);

        if ((u4IntMemSizeMinimum > u4IntMemSize) || (u4ExtMemSizeMinimum > u4ExtMemSize))
        {
            ASSERT(0);
        }
        else
        {
            u4IntMemSize -= (u4IntMemSizeMinimum);
            u4ExtMemSize -= (u4ExtMemSizeMinimum);

            if (JPEG_STATUS_OK != jpegDecSetWorkingMemory(rMJPEGDecCtrl.rMJPEGHandle,
                                                          (kal_uint32 *)rMJPEGDecCtrl.u4IntMemAddr, 
                                                          u4IntMemSizeMinimum,
                                                          (kal_uint32 *)rMJPEGDecCtrl.u4ExtMemAddr,
                                                          u4ExtMemSizeMinimum))
            {
                drv_trace1(TRACE_GROUP_8, MJPEGDEC_SETBUF_ERROR, __LINE__);
#if 0
/* under construction !*/
#endif
                MJPEGDecoderReturnBitstream(u4RealBsAddr, prBufferHeader->u4BuffSize);        
                FSAL_Close(&jpegFile);
    
                return VIDEO_DECODER_CODEC_ERROR;
            }
        }

        if (JPEG_STATUS_OK != jpegDecGetImageDimension(rMJPEGDecCtrl.rMJPEGHandle, &u2Width, &u2Height))
        {
            drv_trace1(TRACE_GROUP_8, MJPEGDEC_HEADER_ERROR, __LINE__);
            //ASSERT(0);
            MJPEGDecoderReturnBitstream(u4RealBsAddr, prBufferHeader->u4BuffSize);
            FSAL_Close(&jpegFile);

            return VIDEO_DECODER_CODEC_ERROR;        
        }

        if ((u2Width == 0) || (u2Height == 0))
        {
            drv_trace1(TRACE_GROUP_8, MJPEGDEC_HEADER_ERROR, __LINE__);
            //ASSERT(0);
            MJPEGDecoderReturnBitstream(u4RealBsAddr, prBufferHeader->u4BuffSize);
            FSAL_Close(&jpegFile);

            return VIDEO_DECODER_CODEC_ERROR;   
        }

        u4Width = MJPEG_HW_ROUND_UP_TO_POWER_OF_TWO(u2Width, 16);
        u4Height = MJPEG_HW_ROUND_UP_TO_POWER_OF_TWO(u2Height, 16);
        drv_trace2(TRACE_GROUP_8, MJPEGDEC_GET_RESOLUTION, u4Width, u4Height);

        //first frame
        if ((0 == rMJPEGDecCtrl.u2FrameWidth) && (0 == rMJPEGDecCtrl.u2FrameHeight))
        {
            pResizeFactor.u4SrcWidth = u4Width;
            pResizeFactor.u4SrcHeight = u4Height;
    
            // calculate power of 2 based resize factor
            s4SrcWidthBit = u4Width;
            s4SrcHeightBit = u4Height;
            s4MaxResizeBit = 1;
            while ((0 < s4SrcWidthBit) && (0 < s4SrcHeightBit))
            {
               s4SrcWidthBit >>= 1;
               s4SrcHeightBit >>= 1;
               s4MaxResizeBit <<= 1;
            }
            if (s4MaxResizeBit > 2048)
            {
               s4MaxResizeBit = 2048;
            }
            else
            {
               s4MaxResizeBit >>= 1;
            }
            
            pResizeFactor.u4MaxAvailableFactor = s4MaxResizeBit;
            pResizeFactor.u4MinAvailableFactor = 1;
            
            // get prescale factor for bandwidth reduction
            VideoDecoderGetResizerFactor(&pResizeFactor);
    
            // resize factor adjustment
            if (pResizeFactor.u4SelectedWidthFactor)
            {
                u4Width /= pResizeFactor.u4SelectedWidthFactor;
                u2Width /= pResizeFactor.u4SelectedWidthFactor;
            }
            else
            {
                ASSERT(0);
            }
            if (pResizeFactor.u4SelectedHeightFactor)
            {
                u4Height /= pResizeFactor.u4SelectedHeightFactor;
                u2Height /= pResizeFactor.u4SelectedHeightFactor;
            }
            else
            {
                ASSERT(0);
            }

            if (!VideoDecoderSetYUVBuffer(&u4Width, &u4Height, 4, 0, 0))
            {
                return VIDEO_DECODER_CODEC_ERROR_NOT_SUPPORT;
            }
            rMJPEGDecCtrl.u2FrameWidth = (kal_uint16)u4Width;
            rMJPEGDecCtrl.u2FrameHeight = (kal_uint16)u4Height;
            rMJPEGDecCtrl.u2RealFrameWidth = u2Width;
            rMJPEGDecCtrl.u2RealFrameHeight = u2Height;
            rMJPEGDecCtrl.u4SelectedWidthFactor = pResizeFactor.u4SelectedWidthFactor;
            rMJPEGDecCtrl.u4SelectedHeightFactor = pResizeFactor.u4SelectedHeightFactor;
            rMJPEGDecCtrl.u4BufferSize = ((((u4Width * u4Height) * 3) >> 1) + 31) & (~31);  // add 32 byte alignment to cache switching
            VideoDecoderGetCustomSetting(&rCustomSettings);
            if (((kal_uint64)rMJPEGDecCtrl.u2FrameWidth * (kal_uint64)rMJPEGDecCtrl.u2FrameHeight) >  rCustomSettings.u8MaxResolution)
            {
                drv_trace1(TRACE_GROUP_8, MJPEGDEC_OVER_RESOLUTION, __LINE__);
                MJPEGDecoderReturnBitstream(u4RealBsAddr, prBufferHeader->u4BuffSize);
                FSAL_Close(&jpegFile);
                return VIDEO_DECODER_CODEC_ERROR_NOT_SUPPORT;
            }
        }
        else
        {
            if ((((kal_uint32)rMJPEGDecCtrl.u2FrameWidth * rMJPEGDecCtrl.u4SelectedWidthFactor) != u4Width) 
                || (((kal_uint32)rMJPEGDecCtrl.u2FrameHeight * rMJPEGDecCtrl.u4SelectedHeightFactor) != u4Height)
                )
            {
                //change resolution
                drv_trace1(TRACE_GROUP_8, MJPEGDEC_CHANGE_RESOLUTION, __LINE__);
                MJPEGDecoderReturnBitstream(u4RealBsAddr, prBufferHeader->u4BuffSize);
                FSAL_Close(&jpegFile);

                return VIDEO_DECODER_CODEC_ERROR;   
            }
        }

        pu1YUVBuffer = (kal_uint8 *)MJPEGDecoderMallocYUV();

        if (pu1YUVBuffer == NULL)
        {
            drv_trace1(TRACE_GROUP_8, MJPEGDEC_ALLOCATE_ERROR, __LINE__);
            ASSERT(0);
            MJPEGDecoderReturnBitstream(u4RealBsAddr, prBufferHeader->u4BuffSize);
            FSAL_Close(&jpegFile);

            return VIDEO_DECODER_CODEC_ERROR;    
        }
        u4UAddr = (kal_uint32)pu1YUVBuffer + (kal_uint32)(rMJPEGDecCtrl.u2FrameWidth * rMJPEGDecCtrl.u2FrameHeight);
        u4VAddr = u4UAddr + ((kal_uint32)(rMJPEGDecCtrl.u2FrameWidth * rMJPEGDecCtrl.u2FrameHeight) >> 2);

        jpegDecSetYUVCanvas(rMJPEGDecCtrl.rMJPEGHandle,
                            (void *)pu1YUVBuffer,
                            (void *)u4UAddr,
                            (void *)u4VAddr,
                            (kal_uint32)rMJPEGDecCtrl.u2FrameWidth,
                            (kal_uint32)rMJPEGDecCtrl.u2FrameHeight,
                            JPEG_YUV_FORMAT_YUV420);

        jpegDecSetClipWindow(rMJPEGDecCtrl.rMJPEGHandle, 0, 0, (kal_uint32)rMJPEGDecCtrl.u2FrameWidth, (kal_uint32)rMJPEGDecCtrl.u2FrameHeight);
        jpegDecSetOutputWindow(rMJPEGDecCtrl.rMJPEGHandle, 0, 0, (kal_uint32)rMJPEGDecCtrl.u2FrameWidth, (kal_uint32)rMJPEGDecCtrl.u2FrameHeight);
        jpegDecSetDecodeMode(rMJPEGDecCtrl.rMJPEGHandle, JPEG_DECODE_MODE_MAIN_IMAGE);

        jpegDecSetCallbackFunction(rMJPEGDecCtrl.rMJPEGHandle, MJPEGDecoderCallback);

        u4DecodeStartTime = video_get_current_time();
        eDecRet = jpegDecStart(rMJPEGDecCtrl.rMJPEGHandle);

        //wait decoding done
        if (eDecRet == JPEG_STATUS_OK)
        {
            kal_set_eg_events(rMJPEGDecCtrl.EventId, 0, KAL_OR);
#if defined (__VE_MJPEG_DEC_SUPPORT_MT6256_SERIES__)
            kal_retrieve_eg_events(rMJPEGDecCtrl.EventId, (EVENT_MJPEG_DEC_RESUME | EVENT_MJPEG_DEC_COMPLETE), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
            if(u4EventGroup & EVENT_MJPEG_DEC_RESUME)
            {
                jpegDecResume(rMJPEGDecCtrl.rMJPEGHandle);  // decode not finished
                kal_retrieve_eg_events(rMJPEGDecCtrl.EventId, EVENT_MJPEG_DEC_COMPLETE, KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
            }
#else
            kal_retrieve_eg_events(rMJPEGDecCtrl.EventId, EVENT_MJPEG_DEC_COMPLETE, KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
#endif
            eDecRet = jpegDecGetLastError(rMJPEGDecCtrl.rMJPEGHandle);
        }

        drv_trace1(TRACE_GROUP_8, MJPEGDEC_DECODE_RESULT, eDecRet);
        if (eDecRet != JPEG_STATUS_OK)
        {
            rMJPEGDecCtrl.fgErrorDecoding = KAL_TRUE;
        }
        else
        {
            u4DecodeTime = video_get_duration_ms(u4DecodeStartTime);
            rMJPEGDecCtrl.u8FrameTime = ((kal_uint64)u4DecodeTime) * 1000;
        }
   
        rMJPEGDecCtrl.u4OutAddr = (kal_uint32)pu1YUVBuffer;
    
        MJPEGDecoderReturnBitstream(u4RealBsAddr, prBufferHeader->u4BuffSize);

        MJPEGDecoderFreeYUV((void *)pu1YUVBuffer);

        //necessary???
        FSAL_Close(&jpegFile);
    }

    return rRet;
}

VIDEO_DECODER_CODEC_ERROR_T MJPEGDecoderGetNextDisplay(kal_uint8** pu1NextFrameAddr, VIDEO_DECODER_PRIVATE_OUTPUT_T* prPrivateOutput)
{
    VIDEO_DECODER_CODEC_ERROR_T rRet = VIDEO_DECODER_CODEC_ERROR_NONE;

    if (prPrivateOutput == NULL)
    {
        drv_trace1(TRACE_GROUP_8, MJPEGDEC_ARGUMENT_ERROR, __LINE__);
        ASSERT(0);
        
        return VIDEO_DECODER_CODEC_ERROR;
    }

    if (KAL_TRUE == rMJPEGDecCtrl.fgErrorDecoding)
    {
        prPrivateOutput->fgRepeatLastFrame = KAL_TRUE;
        rMJPEGDecCtrl.fgErrorDecoding = KAL_FALSE;
    }

    if (rMJPEGDecCtrl.u4OutAddr != 0)
    {
        drv_trace0(TRACE_GROUP_8, MJPEGDEC_OUTPUT);
        prPrivateOutput->fgYUVSeperated = KAL_FALSE;
        prPrivateOutput->pu1YStartAddr = (kal_uint8*)rMJPEGDecCtrl.u4OutAddr;
        //prPrivateOutput->pu1UStartAddr = (kal_uint8*)rDecPic.pOutputPictureCb;
        //prPrivateOutput->pu1VStartAddr = (kal_uint8*)rDecPic.pOutputPictureCr;
        prPrivateOutput->fgEOF = KAL_FALSE;
        if ((rMJPEGDecCtrl.fgFrmBufferSwitch == KAL_TRUE) && (prPrivateOutput->fgEOF == KAL_FALSE))
        {
            if (rMJPEGDecCtrl.fgFrmBufferCacheable == KAL_TRUE)
            {
                *pu1NextFrameAddr = (kal_uint8*)VideoCommExtBufferCacheableSwitch(rMJPEGDecCtrl.u4OutAddr, 
                                                                                  rMJPEGDecCtrl.u4BufferSize,
                                                                                  VIDEO_NON_CACHEABLE);
            }
            else
            {
                *pu1NextFrameAddr = (kal_uint8*)VideoCommExtBufferCacheableSwitch(rMJPEGDecCtrl.u4OutAddr,
                                                                                  rMJPEGDecCtrl.u4BufferSize,
                                                                                  VIDEO_CACHEABLE);
            }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
            prPrivateOutput->pu1YStartAddr = (kal_uint8*)query_opposite_switchable_cacheaddr_ram((kal_uint32)(prPrivateOutput->pu1YStartAddr));
#endif            
        }
        else
        {
            *pu1NextFrameAddr = (kal_uint8 *)rMJPEGDecCtrl.u4OutAddr;
        }
        prPrivateOutput->eFrameType = VIDEO_CODEC_FRAMETYPE_I;
        prPrivateOutput->u2FrameHeight = rMJPEGDecCtrl.u2FrameHeight;
        prPrivateOutput->u2FrameWidth = rMJPEGDecCtrl.u2FrameWidth;
        drv_trace4(TRACE_GROUP_8, MJPEGDEC_DISPLAY_INFO, (kal_uint32)*pu1NextFrameAddr,
        prPrivateOutput->u2FrameWidth, prPrivateOutput->u2FrameHeight, prPrivateOutput->eFrameType);

        prPrivateOutput->u2ClipBottom = rMJPEGDecCtrl.u2RealFrameHeight - 1;
        prPrivateOutput->u2ClipRight = rMJPEGDecCtrl.u2RealFrameWidth - 1;
        prPrivateOutput->u2ClipLeft = 0;
        prPrivateOutput->u2ClipTop = 0;   
        //clear output list after getting
        rMJPEGDecCtrl.u4OutAddr = 0;
    }
    else
    {
        *pu1NextFrameAddr = NULL;
        if (rMJPEGDecCtrl.fgEOF)
        {
            //for CODEC requirement
            rMJPEGDecCtrl.fgEOF = KAL_FALSE;
            prPrivateOutput->fgEOF = KAL_TRUE;
        }
    }

    return rRet;
}

static const VIDEO_DECODER_CODEC_API_T rMJPEGAPI=
{
    MJPEGDecoderOpenAdapt,
    MJPEGDecoderInitAdapt,
    MJPEGDecoderGetParameterAdapt,
    MJPEGDecoderSetParameterAdapt,
    MJPEGDecoderStartAdapt,
    MJPEGDecoderDeInitAdapt,
    MJPEGDecoderCloseAdapt,
    MJPEGDecoderGetNextDisplay
};

VIDEO_DECODER_CODEC_API_T* GetMJPEGDecoderHandler(VIDEO_DECODER_SCENARIO_T eType)
{
    JPEG_STATUS_ENUM status;

#if defined (__VE_MJPEG_DEC_SUPPORT_MT6256_SERIES__)
    // set mjpg scenario for mdp control
    status = jpegDecGetDecoderExt(JPEG_CODEC_TYPE_HW, JPEG_SCENARIO_TYPE_MJPEG, &rMJPEGDecCtrl.rMJPEGHandle);
    if (status != JPEG_STATUS_OK)
    {
        drv_trace0(TRACE_GROUP_8, MJPEGDEC_NOHANDLE);
        return NULL;
    }
    rMJPEGDecCtrl.fgBsBufferCacheable = KAL_FALSE;
    rMJPEGDecCtrl.fgFrmBufferCacheable = KAL_FALSE;
    drv_trace0(TRACE_GROUP_8, MJPEGDEC_HWHANDLE);
#elif defined(__VE_MJPEG_DEC_SUPPORT_MT6255_SERIES__)
    status = jpegDecGetDecoderExt(JPEG_CODEC_TYPE_SW, JPEG_SCENARIO_TYPE_MJPEG, &rMJPEGDecCtrl.rMJPEGHandle);
    if (status != JPEG_STATUS_OK)
    {
        drv_trace0(TRACE_GROUP_8, MJPEGDEC_NOHANDLE);
        return NULL;
    }
    rMJPEGDecCtrl.fgBsBufferCacheable = KAL_FALSE;
    rMJPEGDecCtrl.fgFrmBufferCacheable = KAL_TRUE;
    drv_trace0(TRACE_GROUP_8, MJPEGDEC_SWHANDLE);
#else
    status = jpegDecGetDecoder(JPEG_CODEC_TYPE_SW, &rMJPEGDecCtrl.rMJPEGHandle);
    if (status != JPEG_STATUS_OK)
    {
        drv_trace0(TRACE_GROUP_8, MJPEGDEC_NOHANDLE);
        return NULL;
    }
    rMJPEGDecCtrl.fgBsBufferCacheable = KAL_TRUE;
    rMJPEGDecCtrl.fgFrmBufferCacheable = KAL_TRUE;
    drv_trace0(TRACE_GROUP_8, MJPEGDEC_SWHANDLE);
#endif

    return (VIDEO_DECODER_CODEC_API_T*)&rMJPEGAPI;
}

#endif /* __MJPEG_DEC_SW_SUPPORT__ */
#endif /* __VIDEO_ARCHI_V2__ */
