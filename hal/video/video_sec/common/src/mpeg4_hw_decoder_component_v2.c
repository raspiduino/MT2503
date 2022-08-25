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
 *   mpeg4_decoder_component.c
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
 *
 *
 *
 *
 *
 ****************************************************************************/
#include "drv_comm.h"
#include "drv_features_video.h"

#ifdef __VE_VIDEO_ARCHI_V2__
#ifdef __VE_MPEG4_DEC_HW_SUPPORT__

#include "kal_general_types.h"
#include "video_codec_type_v2.h"
#include "video_codec_if_v2.h"
#include "kal_public_api.h"
#include "video_dbg_v2.h"
#include "kal_trace.h"

#include "video_types_v2.h"
#include "video_buffer_management_v2.h"
#include "Video_comm_v2.h"
#include "vcodec_v2_trc.h"

#include "mpeg4_hw_decoder_component_v2.h"
#include "mp4_decore_v2.h"
#include "cache_sw.h"

#define MPEG4_HW_DEC_MEM_MAGIC_CODE 0x721012
#define CACHE_LINE_ALIGN(buffer) \
    ((((buffer)+CPU_CACHE_LINE_SIZE-1)/CPU_CACHE_LINE_SIZE)*CPU_CACHE_LINE_SIZE)


//#define MPEG4_PATTERN_TEST

extern kal_uint32 query_opposite_switchable_cacheaddr_ram(kal_uint32 addr);

MPEG4_HW_DECODER_CTRL_T rMPEG4HwDecCtrl;
MP4_DEC_DRIVER* pt_mp4_dec_driver;

static void _MPEG4HwcoderDecideSwitchOperation()
{
    if (KAL_TRUE == rMPEG4HwDecCtrl.fgIsBufferDefaultCacheable)
    {
        if (KAL_TRUE == rMPEG4HwDecCtrl.fgFrmBufferCacheable)
        {
            rMPEG4HwDecCtrl.eFrmBufferOperation = MPEG4_SWITCH_NONE;
        }
        else
        {
            rMPEG4HwDecCtrl.eFrmBufferOperation = MPEG4_SWITCH_TO_NONCACHE;
        }
    }
    else
    {
        if (KAL_TRUE == rMPEG4HwDecCtrl.fgFrmBufferCacheable)
        {
            rMPEG4HwDecCtrl.eFrmBufferOperation = MPEG4_SWITCH_TO_CACHE;
        }
        else
        {
            rMPEG4HwDecCtrl.eFrmBufferOperation = MPEG4_SWITCH_NONE;
        }
    }
}

static void _MPEG4HwDecoderControlInit()
{
    rMPEG4HwDecCtrl.fgBSBufferCacheable = KAL_FALSE;
    rMPEG4HwDecCtrl.fgFrmBufferCacheable = KAL_FALSE;
    rMPEG4HwDecCtrl.fgIsBufferDefaultCacheable = KAL_FALSE;
    rMPEG4HwDecCtrl.fgIsCodecInit = KAL_TRUE;
    rMPEG4HwDecCtrl.fgIsOutputDisplay = KAL_FALSE;
    rMPEG4HwDecCtrl.fgIsOutputRepeat = KAL_FALSE;
    rMPEG4HwDecCtrl.fgInitBuffer = KAL_FALSE;
    rMPEG4HwDecCtrl.fgCheckedBS = KAL_FALSE;
    rMPEG4HwDecCtrl.pu1RefYUVAddr = NULL;
    rMPEG4HwDecCtrl.pu1DecYUVAddr = NULL;
    rMPEG4HwDecCtrl.pu1NextDisplayAddr = NULL;
    rMPEG4HwDecCtrl.u2FrameWidth = 0;
    rMPEG4HwDecCtrl.u2FrameHeight = 0;
    rMPEG4HwDecCtrl.u2RealFrameWidth= 0;
    rMPEG4HwDecCtrl.u2RealFrameHeight= 0;
    rMPEG4HwDecCtrl.u4FrmBufferSize = 0;
    rMPEG4HwDecCtrl.fgIsFirstFrameIn = KAL_TRUE;
    rMPEG4HwDecCtrl.fgIsFirstFrameOut = KAL_TRUE;
    rMPEG4HwDecCtrl.u4BitRate = 0;
    rMPEG4HwDecCtrl.u4FrameRate = 0;
    rMPEG4HwDecCtrl.fgEOFSet = KAL_FALSE;

    rMPEG4HwDecCtrl.pu1DecodingBuffer = NULL;
    rMPEG4HwDecCtrl.u4DecodingBuffSize = 0;

    rMPEG4HwDecCtrl.rExtMem.pu1ExtMemAddr = NULL;
    rMPEG4HwDecCtrl.rExtMem.u4ExtMemSize = 0;
    rMPEG4HwDecCtrl.rExtMem.pu1ExtMemAddrAlign= NULL;
    rMPEG4HwDecCtrl.rExtMem.u4ExtMemSizeAlign= 0;
    rMPEG4HwDecCtrl.rExtMem.eExtMemSwitch = MPEG4_SWITCH_NONE;

    rMPEG4HwDecCtrl.rIntMem.pu1ExtMemAddr = NULL;
    rMPEG4HwDecCtrl.rIntMem.u4ExtMemSize = 0;
    rMPEG4HwDecCtrl.rIntMem.pu1ExtMemAddrAlign= NULL;
    rMPEG4HwDecCtrl.rIntMem.u4ExtMemSizeAlign= 0;
    rMPEG4HwDecCtrl.rIntMem.eExtMemSwitch = MPEG4_SWITCH_NONE;

    rMPEG4HwDecCtrl.eDisplayFrameType = VIDEO_CODEC_FRAMETYPE_P;
    rMPEG4HwDecCtrl.eBSBufferOperation = MPEG4_SWITCH_NONE;
    rMPEG4HwDecCtrl.eFrmBufferOperation = MPEG4_SWITCH_NONE;
}

static void _MPEG4HwDecoderControlDeinit()
{
    rMPEG4HwDecCtrl.fgIsBufferDefaultCacheable = KAL_FALSE;
    rMPEG4HwDecCtrl.fgIsCodecInit = KAL_FALSE;
    rMPEG4HwDecCtrl.pu1RefYUVAddr = NULL;
    rMPEG4HwDecCtrl.pu1DecYUVAddr = NULL;
    rMPEG4HwDecCtrl.fgIsOutputDisplay = KAL_FALSE;
    rMPEG4HwDecCtrl.fgIsOutputRepeat = KAL_FALSE;
    rMPEG4HwDecCtrl.pu1NextDisplayAddr = NULL;
    rMPEG4HwDecCtrl.fgInitBuffer = KAL_FALSE;
    rMPEG4HwDecCtrl.u2FrameHeight = 0;
    rMPEG4HwDecCtrl.u2FrameWidth = 0;
    rMPEG4HwDecCtrl.u4FrmBufferSize = 0;
    rMPEG4HwDecCtrl.fgIsFirstFrameIn = KAL_TRUE;
    rMPEG4HwDecCtrl.fgIsFirstFrameOut = KAL_TRUE;
    rMPEG4HwDecCtrl.pu1DecodingBuffer = NULL;
    rMPEG4HwDecCtrl.u4DecodingBuffSize = 0;
    rMPEG4HwDecCtrl.u4BitRate = 0;
    rMPEG4HwDecCtrl.u4FrameRate = 0;
    rMPEG4HwDecCtrl.fgEOFSet = KAL_FALSE;
    rMPEG4HwDecCtrl.rExtMem.pu1ExtMemAddr = NULL;
    rMPEG4HwDecCtrl.rExtMem.u4ExtMemSize = 0;
    rMPEG4HwDecCtrl.rExtMem.pu1ExtMemAddrAlign= NULL;
    rMPEG4HwDecCtrl.rExtMem.u4ExtMemSizeAlign= 0;
    rMPEG4HwDecCtrl.rExtMem.eExtMemSwitch = MPEG4_SWITCH_NONE;
}

static kal_uint8* _MPEG4HwDecoderMallocYUVBuffer(void)
{
    kal_uint8 *pu1BufferAddr = VideoDecoderGetYUVBuffer();

    ASSERT(pu1BufferAddr != NULL);

    switch(rMPEG4HwDecCtrl.eFrmBufferOperation)
    {
    case MPEG4_SWITCH_NONE:
    break;

    case MPEG4_SWITCH_TO_CACHE:
        pu1BufferAddr =
        (kal_uint8*) VideoCommExtBufferCacheableSwitch((kal_uint32)(pu1BufferAddr) , rMPEG4HwDecCtrl.u4FrmBufferSize, VIDEO_CACHEABLE);
    break;

    case MPEG4_SWITCH_TO_NONCACHE:
        pu1BufferAddr =
        (kal_uint8*) VideoCommExtBufferCacheableSwitch((kal_uint32)(pu1BufferAddr) , rMPEG4HwDecCtrl.u4FrmBufferSize, VIDEO_NON_CACHEABLE);
    break;

    default:
        ASSERT(0);
    break;
    };

    return pu1BufferAddr;
}

static void _MPEG4HwDecoderFreeRefBuffer(kal_uint8* pu1BufferAddr)
{
    /* YUV buffer is processed as non-cacheable for HW solution
        We need to switch back to cacheable if it is gotten as cacheable */

    switch(rMPEG4HwDecCtrl.eFrmBufferOperation)
    {
    case MPEG4_SWITCH_TO_CACHE:
    case MPEG4_SWITCH_TO_NONCACHE:
        pu1BufferAddr = (kal_uint8*)query_opposite_switchable_cacheaddr_ram((kal_uint32)(pu1BufferAddr));
        //pu1Addr = (kal_uint8*)fake_query_opposite_switchable_cacheaddr_ram((kal_uint32)(pu1Addr));
    break;

    case MPEG4_SWITCH_NONE:
    break;

    default:
        ASSERT(0);
    break;
    };

    drv_trace1(TRACE_GROUP_10, MP4HWDEC_FREE_YUV_REF, (kal_uint32)pu1BufferAddr);
    VideoDecoderRefFreeYUVBuffer(pu1BufferAddr);

}

static void _MPEG4HwDecoderFreeDispBuffer(kal_uint8* pu1BufferAddr)
{
    /* YUV buffer is processed as non-cacheable for HW solution
        We need to switch back to cacheable if it is gotten as cacheable */

    switch(rMPEG4HwDecCtrl.eFrmBufferOperation)
    {
    case MPEG4_SWITCH_TO_CACHE:
    case MPEG4_SWITCH_TO_NONCACHE:
        pu1BufferAddr = (kal_uint8*)query_opposite_switchable_cacheaddr_ram((kal_uint32)(pu1BufferAddr));
        //pu1Addr = (kal_uint8*)fake_query_opposite_switchable_cacheaddr_ram((kal_uint32)(pu1Addr));
    break;

    case MPEG4_SWITCH_NONE:
    break;

    default:
        ASSERT(0);
    break;
    };

    drv_trace1(TRACE_GROUP_10, MP4HWDEC_FREE_YUV_DISP, (kal_uint32)pu1BufferAddr);
    VideoDecoderDisplayFreeYUVBuffer(pu1BufferAddr);

}

static kal_bool _MPGE4HwDecoderYUVBufferCheck(void)
{
    kal_uint8* pu1TestBuffer = (kal_uint8*)VideoDecoderGetYUVBuffer();
    kal_bool fgIsCacheable = VideoCommIsExtBufferCacheable((kal_uint32)(pu1TestBuffer) , rMPEG4HwDecCtrl.u4FrmBufferSize);

    ASSERT(pu1TestBuffer != NULL);

    VideoDecoderRefFreeYUVBuffer(pu1TestBuffer);
    VideoDecoderDisplayFreeYUVBuffer(pu1TestBuffer);

#ifdef MPEG4HWDECDEBUG
    video_dbg_trace(VIDEO_DBG_OWNER_DECODER, VIDEO_DBG_DECODER_MPEG4HWADPT_YUV_CHECK,
        fgIsCacheable);
#endif

    return fgIsCacheable;
}

static void _MPGE4HwDecoderReturnBitstream(kal_uint8* pu1Addr, kal_uint32 u4Length)
{
#ifdef MPEG4HWDECDEBUG
    video_dbg_trace(VIDEO_DBG_OWNER_DECODER, VIDEO_DBG_DECODER_MPEG4HWADPT_RET_BTM,
        (kal_uint32)pu1Addr);
#endif
    drv_trace1(TRACE_GROUP_10, MP4HWDEC_RETURN_BTM, (kal_uint32)pu1Addr);

    switch(rMPEG4HwDecCtrl.eBSBufferOperation)
    {
    case MPEG4_SWITCH_NONE:
    break;

    case MPEG4_SWITCH_TO_CACHE:
        pu1Addr = (kal_uint8*) VideoCommExtBufferCacheableSwitchAlignMemory((kal_uint32)(pu1Addr), u4Length, VIDEO_NON_CACHEABLE);
    break;
    case MPEG4_SWITCH_TO_NONCACHE:
        pu1Addr = (kal_uint8*) VideoCommExtBufferCacheableSwitchAlignMemory((kal_uint32)(pu1Addr), u4Length, VIDEO_CACHEABLE);
        //pu1Addr = (kal_uint8*)query_opposite_switchable_cacheaddr_ram((kal_uint32)(pu1Addr));
    break;

    default:
        ASSERT(0);
    break;
    };

    VideoDecoderReturnBitstream(pu1Addr, u4Length);
}

static void _MPEGHwDecoderFlush(void)
{
    // Flush pipeline stage
    ASSERT(pt_mp4_dec_driver != NULL);
    pt_mp4_dec_driver->flush();

    // return YUV buffer
    if (rMPEG4HwDecCtrl.pu1RefYUVAddr != NULL)
    {
        _MPEG4HwDecoderFreeRefBuffer(rMPEG4HwDecCtrl.pu1RefYUVAddr);
    }
    rMPEG4HwDecCtrl.pu1RefYUVAddr = NULL;

    if (rMPEG4HwDecCtrl.pu1DecYUVAddr != NULL)
    {
        _MPEG4HwDecoderFreeRefBuffer(rMPEG4HwDecCtrl.pu1DecYUVAddr);
        _MPEG4HwDecoderFreeDispBuffer(rMPEG4HwDecCtrl.pu1DecYUVAddr);
    }
    rMPEG4HwDecCtrl.pu1DecYUVAddr = NULL;

    // return bitstream
    if ((rMPEG4HwDecCtrl.pu1DecodingBuffer != NULL) &&
        (rMPEG4HwDecCtrl.pu1DecodingBuffer != (kal_uint8 *)MP4_HW_DEC_EOF_CODE))
    {
        _MPGE4HwDecoderReturnBitstream(rMPEG4HwDecCtrl.pu1DecodingBuffer,
            rMPEG4HwDecCtrl.u4DecodingBuffSize);
    }
    rMPEG4HwDecCtrl.pu1DecodingBuffer = NULL;
    rMPEG4HwDecCtrl.u4DecodingBuffSize = 0;

    // First frame flag after flush
    rMPEG4HwDecCtrl.fgIsFirstFrameIn = KAL_TRUE;

}

VIDEO_DECODER_CODEC_ERROR_T MPEG4HwDecoderOpenAdapt(void)
{
    VIDEO_DECODER_CODEC_ERROR_T rRet = VIDEO_DECODER_CODEC_ERROR_NONE;
    mp4_dec_init_param tMp4InitParam;

    tMp4InitParam.max_width = rMPEG4HwDecCtrl.u4MaxWidth;
    tMp4InitParam.max_height = rMPEG4HwDecCtrl.u4MaxHeight;

    pt_mp4_dec_driver = GetMPEG4HwDecHandle();

    pt_mp4_dec_driver->init(&tMp4InitParam);

    // Internal Memory allocation for codec
    tMp4InitParam.int_mem_size = MP4_DEC_MAX_WORK_MEMORY(
                    rMPEG4HwDecCtrl.u4MaxWidth, rMPEG4HwDecCtrl.u4MaxHeight);

    if(VideoDecoderCheckIntBuffer() != KAL_TRUE)
    {
        // Internal RAM init fail. External RAM used
        rMPEG4HwDecCtrl.rIntMem.u4ExtMemSize = tMp4InitParam.int_mem_size;
        rMPEG4HwDecCtrl.rIntMem.u4ExtMemSizeAlign =
            CACHE_LINE_ALIGN(rMPEG4HwDecCtrl.rIntMem.u4ExtMemSize);

        rMPEG4HwDecCtrl.rIntMem.pu1ExtMemAddr = VideoDecoderMalloc(rMPEG4HwDecCtrl.rIntMem.u4ExtMemSize+CPU_CACHE_LINE_SIZE*2);
        ASSERT(rMPEG4HwDecCtrl.rIntMem.pu1ExtMemAddr != NULL);
        rMPEG4HwDecCtrl.rIntMem.pu1ExtMemAddrAlign = \
            (kal_uint8 *)CACHE_LINE_ALIGN((kal_uint32)rMPEG4HwDecCtrl.rIntMem.pu1ExtMemAddr);

        /* Should switch to non-cache */
        if (KAL_FALSE == VideoCommIsExtBufferCacheable((kal_uint32)(rMPEG4HwDecCtrl.rIntMem.pu1ExtMemAddrAlign),
                    rMPEG4HwDecCtrl.rIntMem.u4ExtMemSizeAlign))
        {
            /* External memory allocated from common part is NON-CACHEABLE */
            rMPEG4HwDecCtrl.rIntMem.eExtMemSwitch = MPEG4_SWITCH_NONE;
        }
        else
        {
            rMPEG4HwDecCtrl.rIntMem.eExtMemSwitch = MPEG4_SWITCH_TO_NONCACHE;

            rMPEG4HwDecCtrl.rIntMem.pu1ExtMemAddrAlign = (kal_uint8*) VideoCommExtBufferCacheableSwitch(
                (kal_uint32)(rMPEG4HwDecCtrl.rIntMem.pu1ExtMemAddrAlign),
                rMPEG4HwDecCtrl.rIntMem.u4ExtMemSizeAlign, VIDEO_NON_CACHEABLE);
        }

        tMp4InitParam.int_mem_addr = rMPEG4HwDecCtrl.rIntMem.pu1ExtMemAddrAlign;
    }
    else
    {
        tMp4InitParam.int_mem_addr =  (kal_uint8*)VideoDecoderIntBuffer(tMp4InitParam.int_mem_size);
    }

    ASSERT(tMp4InitParam.int_mem_addr != NULL);
    pt_mp4_dec_driver->set_param(VIDEO_MP4_DEC_PARAM_INT_MEM_ADDR, &tMp4InitParam);

#ifdef MPEG4HWDECDEBUG
    video_dbg_trace(VIDEO_DBG_OWNER_DECODER, VIDEO_DBG_DECODER_MPEG4HWADPT_OPEN,
        tMp4InitParam.int_mem_size);
#endif
    drv_trace2(TRACE_GROUP_10, MP4HWDEC_OPEN, (kal_uint32)tMp4InitParam.int_mem_addr, tMp4InitParam.int_mem_size);
    return rRet;
}

VIDEO_DECODER_CODEC_ERROR_T MPEG4HwDecoderInitAdapt(void)
{
    mp4_dec_init_param tMp4InitParam;

    _MPEG4HwDecoderControlInit();

    // External memory is for quantization scale information for deblocking
    tMp4InitParam.ext_mem_size = MP4_DEC_QS_WORK_SIZE(
                    rMPEG4HwDecCtrl.u4MaxWidth, rMPEG4HwDecCtrl.u4MaxHeight);
    rMPEG4HwDecCtrl.rExtMem.u4ExtMemSize = tMp4InitParam.ext_mem_size;
    rMPEG4HwDecCtrl.rExtMem.u4ExtMemSizeAlign =
        CACHE_LINE_ALIGN(rMPEG4HwDecCtrl.rExtMem.u4ExtMemSize);

    rMPEG4HwDecCtrl.rExtMem.pu1ExtMemAddr = VideoDecoderMalloc(rMPEG4HwDecCtrl.rExtMem.u4ExtMemSize+CPU_CACHE_LINE_SIZE*2);
    ASSERT(rMPEG4HwDecCtrl.rExtMem.pu1ExtMemAddr != NULL);
    rMPEG4HwDecCtrl.rExtMem.pu1ExtMemAddrAlign = \
        (kal_uint8 *)CACHE_LINE_ALIGN((kal_uint32)rMPEG4HwDecCtrl.rExtMem.pu1ExtMemAddr);

    /* Should switch to non-cache */
    if (KAL_FALSE == VideoCommIsExtBufferCacheable((kal_uint32)(rMPEG4HwDecCtrl.rExtMem.pu1ExtMemAddrAlign),
                rMPEG4HwDecCtrl.rExtMem.u4ExtMemSizeAlign))
    {
        /* External memory allocated from common part is NON-CACHEABLE */
        rMPEG4HwDecCtrl.rExtMem.eExtMemSwitch = MPEG4_SWITCH_NONE;
    }
    else
    {
        rMPEG4HwDecCtrl.rExtMem.eExtMemSwitch = MPEG4_SWITCH_TO_NONCACHE;

        rMPEG4HwDecCtrl.rExtMem.pu1ExtMemAddrAlign = (kal_uint8*) VideoCommExtBufferCacheableSwitch(
            (kal_uint32)(rMPEG4HwDecCtrl.rExtMem.pu1ExtMemAddrAlign),
            rMPEG4HwDecCtrl.rExtMem.u4ExtMemSizeAlign, VIDEO_NON_CACHEABLE);
    }

    tMp4InitParam.ext_mem_addr = rMPEG4HwDecCtrl.rExtMem.pu1ExtMemAddrAlign;
    tMp4InitParam.ext_mem_size = rMPEG4HwDecCtrl.rExtMem.u4ExtMemSizeAlign;

    ASSERT(pt_mp4_dec_driver != NULL);
    pt_mp4_dec_driver->set_param(VIDEO_MP4_DEC_PARAM_EXT_MEM_ADDR, &tMp4InitParam);

    #ifdef MPEG4HWDECDEBUG
    video_dbg_trace(VIDEO_DBG_OWNER_DECODER, VIDEO_DBG_DECODER_MPEG4HWADPT_INIT,
        tMp4InitParam.ext_mem_size);
    #endif
    drv_trace2(TRACE_GROUP_10, MP4HWDEC_INIT, (kal_uint32)tMp4InitParam.ext_mem_addr, tMp4InitParam.ext_mem_size);

    return VIDEO_DECODER_CODEC_ERROR_NONE;
}

VIDEO_DECODER_CODEC_ERROR_T MPEG4HwDecoderDeInitAdapt(void)
{
    ASSERT(pt_mp4_dec_driver != NULL);
    pt_mp4_dec_driver->flush();

    if(rMPEG4HwDecCtrl.rExtMem.eExtMemSwitch == MPEG4_SWITCH_TO_NONCACHE)
    {
        rMPEG4HwDecCtrl.rExtMem.pu1ExtMemAddrAlign = (kal_uint8*) VideoCommExtBufferCacheableSwitch(
            (kal_uint32)(rMPEG4HwDecCtrl.rExtMem.pu1ExtMemAddrAlign),
            rMPEG4HwDecCtrl.rExtMem.u4ExtMemSizeAlign, VIDEO_CACHEABLE);
    }
    else if(rMPEG4HwDecCtrl.rExtMem.eExtMemSwitch == MPEG4_SWITCH_NONE)
    {
        /* No change */
    }
    else
    {
        EXT_ASSERT(0, rMPEG4HwDecCtrl.rExtMem.eExtMemSwitch, 0, 0);
    }
    VideoDecoderFree(rMPEG4HwDecCtrl.rExtMem.pu1ExtMemAddr);

    _MPEG4HwDecoderControlDeinit();

    #ifdef MPEG4HWDECDEBUG
        video_dbg_trace(VIDEO_DBG_OWNER_DECODER, VIDEO_DBG_DECODER_MPEG4HWADPT_DEINIT, 0);
    #endif
    drv_trace0(TRACE_GROUP_10, MP4HWDEC_DEINIT);

    return VIDEO_DECODER_CODEC_ERROR_NONE;
}

VIDEO_DECODER_CODEC_ERROR_T MPEG4HwDecoderGetParameterAdapt(VIDEO_DECODER_PARAM_TYPE_T eCmd, void *pParam)
{
    VIDEO_DECODER_CODEC_ERROR_T rRet = VIDEO_DECODER_CODEC_ERROR_NONE;

    switch(eCmd)
    {
    case VIDEO_DECODER_PARAM_EOF:
        break;
    case VIDEO_DECODER_PARAM_MEMORY_REQUIREMENT:
        // In this command, adaptation is not opened/initialized
        {
            VIDEO_CODEC_MEMORY_T* prMemorySize = (VIDEO_CODEC_MEMORY_T*)pParam;
            prMemorySize->u4ExternalSize = MP4_DEC_QS_WORK_SIZE(
                rMPEG4HwDecCtrl.u4MaxWidth, rMPEG4HwDecCtrl.u4MaxHeight);
            prMemorySize->u4ExternalSize =
                CACHE_LINE_ALIGN(prMemorySize->u4ExternalSize) + CPU_CACHE_LINE_SIZE;
            prMemorySize->u4InternalSize = MP4_DEC_MAX_WORK_MEMORY(
                rMPEG4HwDecCtrl.u4MaxWidth, rMPEG4HwDecCtrl.u4MaxHeight);

            // External to include internal for internal not enough
            prMemorySize->u4ExternalSize +=
                CACHE_LINE_ALIGN(prMemorySize->u4InternalSize) + CPU_CACHE_LINE_SIZE;
        }
        break;
    case VIDEO_DECODER_PARAM_QUERY_RESOLUTION_AHEAD:
        ASSERT(0);
        rRet = VIDEO_DECODER_CODEC_ERROR;
        break;
    case VIDEO_DECODER_PARAM_QUERY_RESOLUTION:
        if ( rMPEG4HwDecCtrl.fgIsCodecInit == KAL_TRUE )
        {
            VIDEO_DECODER_QUERY_FRAME_SIZE_TYPE_T* prQueryType =
                (VIDEO_DECODER_QUERY_FRAME_SIZE_TYPE_T*)(pParam);
            *prQueryType->pu4Height = rMPEG4HwDecCtrl.u2FrameHeight;
            *prQueryType->pu4Width = rMPEG4HwDecCtrl.u2FrameWidth;
        }
        else
        {
            ASSERT(0);
            rRet = VIDEO_DECODER_CODEC_ERROR;
        }
        break;
    case VIDEO_DECODER_PARAM_CAPABILITY:
        ASSERT(pt_mp4_dec_driver != NULL);
        {
            VIDEO_DECODER_CODEC_CAPABILITY_T* prCapability = (VIDEO_DECODER_CODEC_CAPABILITY_T*)(pParam);
            pt_mp4_dec_driver->get_param(VIDEO_MP4_DEC_PARAM_MAX_WIDTH,
                &(prCapability->u4SupportWidth));
            pt_mp4_dec_driver->get_param(VIDEO_MP4_DEC_PARAM_MAX_HEIGHT,
                &(prCapability->u4SupportHeight));
            pt_mp4_dec_driver->get_param(VIDEO_MP4_DEC_PARAM_MAX_SIZE,
                &(prCapability->u4SupportResolution));
            pt_mp4_dec_driver->get_param(VIDEO_MP4_DEC_PARAM_PROFILE,
                &(prCapability->u4SupportProfile));
            pt_mp4_dec_driver->get_param(VIDEO_MP4_DEC_PARAM_LEVEL,
                &(prCapability->u4SupportLevel));
        }
        break;
    default:
        EXT_ASSERT(0, eCmd, 0, 0);
        rRet = VIDEO_DECODER_CODEC_ERROR;
        break;
    };

    return rRet;
}

VIDEO_DECODER_CODEC_ERROR_T MPEG4HwDecoderSetParameterAdapt(VIDEO_DECODER_PARAM_TYPE_T eCmd, void *pParam)
{
#ifdef MPEG4HWDECDEBUG
    video_dbg_trace(VIDEO_DBG_OWNER_DECODER, VIDEO_DBG_DECODER_MPEG4HWADPT_SETPARAM,
        eCmd);
#endif
    drv_trace1(TRACE_GROUP_10, MP4HWDEC_SET_PARAM, eCmd);

    switch(eCmd)
    {
        case VIDEO_DECODER_PARAM_EOF:
        {
            mp4_dec_decode_input_param t_mpeg4_dec_im;
            mp4_dec_decode_output_param t_mpeg4_dec_result_im;
            kal_uint32 u4result;
            kal_uint32 u4DecodeStartTime, u4DecodeTime;

            drv_trace0(TRACE_GROUP_10, MP4HWDEC_SET_EOF);

            t_mpeg4_dec_im.bitstream_addr = (kal_uint8 *)MP4_HW_DEC_EOF_CODE;
            t_mpeg4_dec_im.bitstream_length = MP4_HW_DEC_EOF_CODE;
            t_mpeg4_dec_im.ref_addr = (kal_uint8 *)MP4_HW_DEC_EOF_CODE;
            t_mpeg4_dec_im.yuv_addr = (kal_uint8 *)MP4_HW_DEC_EOF_CODE;
            t_mpeg4_dec_im.fgIsEOF = KAL_TRUE;

            u4DecodeStartTime = video_get_current_time();
            u4result = pt_mp4_dec_driver->decode((void *)&t_mpeg4_dec_im, (void *)&t_mpeg4_dec_result_im);
            u4DecodeTime = video_get_duration_ms(u4DecodeStartTime);

#ifdef MPEG4HWDECDEBUG
            video_dbg_trace(VIDEO_DBG_OWNER_DECODER, VIDEO_DBG_DECODER_MPEG4HWADPT_COMPLETE,
                u4result);
            video_dbg_trace(VIDEO_DBG_OWNER_DECODER, VIDEO_DBG_DECODER_MPEG4HWADPT_COMPLETE,
                u4DecodeTime);
#endif
            drv_trace2(TRACE_GROUP_10, MP4HWDEC_RESULT, u4result, u4DecodeTime);

            switch(u4result)
            {
                case MP4_DECODE_OK:
                case MP4_DECODE_FAILED:
                case MP4_DECODE_OK_BYPASS:
                case MP4_DECODE_FAILED_TIMEOUT:
                case MP4_DECODE_FAILED_VLC_LIMIT:
                {
                    kal_uint8* pu1RefFreeBuf = NULL;
                    ASSERT(rMPEG4HwDecCtrl.pu1RefYUVAddr != NULL);

                    if(u4result == MP4_DECODE_OK_BYPASS)
                    {
                        // To repeat last frame
                        rMPEG4HwDecCtrl.fgIsOutputRepeat = KAL_TRUE;
                    }
                    else
                    {
                        rMPEG4HwDecCtrl.fgIsOutputRepeat = KAL_FALSE;
                    }

                    if(t_mpeg4_dec_result_im.free_ref_yuv_addr != t_mpeg4_dec_result_im.disp_yuv_addr)
                    {
                        // change reference frame
                        rMPEG4HwDecCtrl.pu1RefYUVAddr = t_mpeg4_dec_result_im.disp_yuv_addr;
                    }

                    pu1RefFreeBuf = t_mpeg4_dec_result_im.free_ref_yuv_addr;
                    rMPEG4HwDecCtrl.pu1NextDisplayAddr = t_mpeg4_dec_result_im.disp_yuv_addr;

                    rMPEG4HwDecCtrl.fgIsOutputDisplay = KAL_TRUE;

                    if(rMPEG4HwDecCtrl.eScenario != VIDEO_SCENARIO_PREVIEW)
                    {
                        _MPEG4HwDecoderFreeRefBuffer(pu1RefFreeBuf);
                    }
                    ASSERT(rMPEG4HwDecCtrl.pu1DecYUVAddr == rMPEG4HwDecCtrl.pu1NextDisplayAddr);
                    _MPEG4HwDecoderFreeRefBuffer(rMPEG4HwDecCtrl.pu1NextDisplayAddr);

                    _MPGE4HwDecoderReturnBitstream(rMPEG4HwDecCtrl.pu1DecodingBuffer,
                        rMPEG4HwDecCtrl.u4DecodingBuffSize);

                    if(t_mpeg4_dec_result_im.u1_vop_coding_type == 0)
                    {
                        rMPEG4HwDecCtrl.eDisplayFrameType = VIDEO_CODEC_FRAMETYPE_I;
                    }
                    else if(t_mpeg4_dec_result_im.u1_vop_coding_type == 1)
                    {
                        rMPEG4HwDecCtrl.eDisplayFrameType = VIDEO_CODEC_FRAMETYPE_P;
                    }
                    else
                    {
                        rMPEG4HwDecCtrl.eDisplayFrameType = VIDEO_CODEC_FRAMETYPE_B;
                    }
                    video_dbg_trace(VIDEO_DBG_OWNER_DECODER,
                        VIDEO_DBG_DECODER_MPEG4HWADPT_VOP_TYPE, t_mpeg4_dec_result_im.u1_vop_coding_type);

                    if(rMPEG4HwDecCtrl.fgIsFirstFrameOut == KAL_TRUE)
                    {
                        drv_trace1(TRACE_GROUP_10, MP4HWDEC_1ST_VOP_TYPE, t_mpeg4_dec_result_im.u1_vop_coding_type);
                        rMPEG4HwDecCtrl.fgIsFirstFrameOut = KAL_FALSE;
                    }

                    rMPEG4HwDecCtrl.pu1DecodingBuffer = (kal_uint8 *)MP4_HW_DEC_EOF_CODE;
                    rMPEG4HwDecCtrl.u4DecodingBuffSize = MP4_HW_DEC_EOF_CODE;
                }
                break;

                case MP4_DECODE_BYPASS_EOF:
                break;

                case MP4_DECODE_BYPASS_PIPELINE:
                default:
                    ASSERT(0);
                break;
            }
            rMPEG4HwDecCtrl.fgEOFSet = KAL_TRUE;
            // First frame flag after flush
            rMPEG4HwDecCtrl.fgIsFirstFrameIn = KAL_TRUE;
            rMPEG4HwDecCtrl.pu1RefYUVAddr = NULL;
            rMPEG4HwDecCtrl.pu1DecYUVAddr = NULL;
        }
            break;

        case VIDEO_DECODER_PARAM_NOT_BUFFERING:
        case VIDEO_DECODER_PARAM_BUFFERING:
            break;
        case VIDEO_DECODER_PARAM_FLUSH_BUFFER:
            _MPEGHwDecoderFlush();
            break;
        case VIDEO_DECODER_PARAM_BITRATE:
            rMPEG4HwDecCtrl.u4BitRate = *(kal_uint32*)(pParam); // bps
            drv_trace1(TRACE_GROUP_10, MP4HWDEC_SET_BIT_RATE, rMPEG4HwDecCtrl.u4BitRate);
            break;
        case VIDEO_DECODER_PARAM_FRAMERATE: //x100 fps, e.g. 29.97 fps, the set vaule is 2997
            rMPEG4HwDecCtrl.u4FrameRate = *(kal_uint32*)(pParam);
            drv_trace1(TRACE_GROUP_10, MP4HWDEC_SET_FRAME_RATE, rMPEG4HwDecCtrl.u4FrameRate);
            break;
        default:
            EXT_ASSERT(0, eCmd, 0, 0);
            return VIDEO_DECODER_CODEC_ERROR;
    };

    return VIDEO_DECODER_CODEC_ERROR_NONE;
}

VIDEO_DECODER_CODEC_ERROR_T MPEG4HwDecoderCloseAdapt(void)
{
#ifdef MPEG4HWDECDEBUG
     video_dbg_trace(VIDEO_DBG_OWNER_DECODER, VIDEO_DBG_DECODER_MPEG4HWADPT_CLOSE, 0);
#endif
    drv_trace0(TRACE_GROUP_10, MP4HWDEC_CLOSE);

#if 1 // External memory for internal memory not enough
    if(rMPEG4HwDecCtrl.rIntMem.pu1ExtMemAddr != NULL)
    {
        if(rMPEG4HwDecCtrl.rIntMem.eExtMemSwitch == MPEG4_SWITCH_TO_NONCACHE)
        {
            rMPEG4HwDecCtrl.rIntMem.pu1ExtMemAddrAlign = (kal_uint8*) VideoCommExtBufferCacheableSwitch(
                (kal_uint32)(rMPEG4HwDecCtrl.rIntMem.pu1ExtMemAddrAlign),
                rMPEG4HwDecCtrl.rIntMem.u4ExtMemSizeAlign, VIDEO_CACHEABLE);
        }
        else if(rMPEG4HwDecCtrl.rIntMem.eExtMemSwitch == MPEG4_SWITCH_NONE)
        {
            /* No change */
        }
        else
        {
            EXT_ASSERT(0, rMPEG4HwDecCtrl.rIntMem.eExtMemSwitch, 0, 0);
        }
        VideoDecoderFree(rMPEG4HwDecCtrl.rIntMem.pu1ExtMemAddr);
    }
#endif

    rMPEG4HwDecCtrl.u4MaxWidth = 0;
    rMPEG4HwDecCtrl.u4MaxWidth = 0;
    rMPEG4HwDecCtrl.eScenario = VIDEO_SCENARIO_UNKNOWN;
    ASSERT(pt_mp4_dec_driver != NULL);
    pt_mp4_dec_driver->deinit();
    return VIDEO_DECODER_CODEC_ERROR_NONE;
}

VIDEO_DECODER_CODEC_ERROR_T MPEG4HwDecoderStartAdapt(VIDEO_BUFFERHEADER_TYPE_T *prBufferHeader)
{
    VIDEO_DECODER_CODEC_ERROR_T rRet = VIDEO_DECODER_CODEC_ERROR_NONE;
    kal_uint32 u4width, u4height;
    mp4_dec_parse_param tResult;
    mp4_dec_decode_input_param t_mpeg4_dec_im;
    mp4_dec_decode_output_param t_mpeg4_dec_result_im;
    kal_bool fgContinue = KAL_FALSE;

    ASSERT(pt_mp4_dec_driver != NULL);

    #ifdef MPEG4HWDECDEBUG
    video_dbg_trace(VIDEO_DBG_OWNER_DECODER, VIDEO_DBG_DECODER_MPEG4HWADPT_START,
        (kal_uint32)prBufferHeader->pu1Buffer);
    #endif
    drv_trace2(TRACE_GROUP_10, MP4HWDEC_START, (kal_uint32)prBufferHeader->pu1Buffer,
        prBufferHeader->u8TimeStamp);

    t_mpeg4_dec_im.bitstream_addr = prBufferHeader->pu1Buffer;
    t_mpeg4_dec_im.bitstream_length = prBufferHeader->u4BuffSize;
    t_mpeg4_dec_im.ref_addr = NULL;

    if (KAL_FALSE == rMPEG4HwDecCtrl.fgCheckedBS)
    {
        rMPEG4HwDecCtrl.eBSBufferOperation = MPEG4_SWITCH_NONE;
        if (KAL_TRUE == rMPEG4HwDecCtrl.fgBSBufferCacheable)
        {
            if (KAL_FALSE == VideoCommIsExtBufferCacheable((kal_uint32)(t_mpeg4_dec_im.bitstream_addr),
                t_mpeg4_dec_im.bitstream_length))
            {
                rMPEG4HwDecCtrl.eBSBufferOperation = MPEG4_SWITCH_TO_CACHE;
                t_mpeg4_dec_im.bitstream_addr = (kal_uint8*) VideoCommExtBufferCacheableSwitchAlignMemory(
                    (kal_uint32)(t_mpeg4_dec_im.bitstream_addr), t_mpeg4_dec_im.bitstream_length, VIDEO_CACHEABLE);
            }
        }
        else
        {
            if (KAL_TRUE == VideoCommIsExtBufferCacheable((kal_uint32)(t_mpeg4_dec_im.bitstream_addr),
                t_mpeg4_dec_im.bitstream_length))
            {
                rMPEG4HwDecCtrl.eBSBufferOperation = MPEG4_SWITCH_TO_NONCACHE;
                t_mpeg4_dec_im.bitstream_addr = (kal_uint8*) VideoCommExtBufferCacheableSwitchAlignMemory(
                    (kal_uint32)(t_mpeg4_dec_im.bitstream_addr) , t_mpeg4_dec_im.bitstream_length, VIDEO_NON_CACHEABLE);
            }
        }
        rMPEG4HwDecCtrl.fgCheckedBS = KAL_TRUE;
    }
    else
    {
        switch(rMPEG4HwDecCtrl.eBSBufferOperation)
        {
        case MPEG4_SWITCH_NONE:
        break;

        case MPEG4_SWITCH_TO_CACHE:
            t_mpeg4_dec_im.bitstream_addr = (kal_uint8*) VideoCommExtBufferCacheableSwitchAlignMemory(
                (kal_uint32)(t_mpeg4_dec_im.bitstream_addr) , t_mpeg4_dec_im.bitstream_length, VIDEO_CACHEABLE);
        break;

        case MPEG4_SWITCH_TO_NONCACHE:
            t_mpeg4_dec_im.bitstream_addr = (kal_uint8*) VideoCommExtBufferCacheableSwitchAlignMemory(
                (kal_uint32)(t_mpeg4_dec_im.bitstream_addr) , t_mpeg4_dec_im.bitstream_length, VIDEO_NON_CACHEABLE);
        break;

        default:
            ASSERT(0);
        break;
        };
    }

    if (rMPEG4HwDecCtrl.fgInitBuffer == KAL_TRUE)
    {
        t_mpeg4_dec_im.yuv_addr = _MPEG4HwDecoderMallocYUVBuffer();
        rMPEG4HwDecCtrl.pu1DecYUVAddr = t_mpeg4_dec_im.yuv_addr;
        drv_trace2(TRACE_GROUP_10, MP4HWDEC_GET_YUV_BUF, (kal_uint32)t_mpeg4_dec_im.yuv_addr, prBufferHeader->u8TimeStamp);

        fgContinue = KAL_TRUE;
    }

    if (rMPEG4HwDecCtrl.fgInitBuffer == KAL_FALSE)
    {
        #if 0
/* under construction !*/
        #endif

        /* First time, the bitstream should start with VOS or video_plane_with_short_header() */
        ASSERT((prBufferHeader->pu1Buffer != NULL) && (prBufferHeader->u4BuffSize!=0));
        t_mpeg4_dec_im.yuv_addr = NULL;

        /* Parse VOS or H.263 short header */
        tResult = pt_mp4_dec_driver->parseVOS((void *)&t_mpeg4_dec_im);

#ifdef MPEG4HWDECDEBUG
        video_dbg_trace(VIDEO_DBG_OWNER_DECODER, VIDEO_DBG_DECODER_MPEG4HWADPT_PARSE_HDR,
             tResult.eStatus);
#endif
        drv_trace4(TRACE_GROUP_10, MP4HWDEC_PARSE_HEADER, tResult.eStatus,
            (kal_uint32)prBufferHeader->pu1Buffer, prBufferHeader->u4BuffSize, 0);

        switch(tResult.eStatus)
        {
        case VIDEO_MP4_PARSE_SHR_HDR_RDY:
        case VIDEO_MP4_PARSE_VOS_RDY_WITH_VOP:
        case VIDEO_MP4_PARSE_VOS_RDY:
            break;

        case VIDEO_MP4_PARSE_VOS_ERR:
        case VIDEO_MP4_PARSE_SHR_HDR_ERR:
        case VIDEO_MP4_PARSE_UNKNOWN_ERR:
            _MPGE4HwDecoderReturnBitstream(prBufferHeader->pu1Buffer, prBufferHeader->u4BuffSize);
            rRet = VIDEO_DECODER_CODEC_ERROR_FAIL_PLAYBACK;
            break;
        default:
            ASSERT(0);
            _MPGE4HwDecoderReturnBitstream(prBufferHeader->pu1Buffer, prBufferHeader->u4BuffSize);
            rRet = VIDEO_DECODER_CODEC_ERROR_FAIL_PLAYBACK;
            break;
        }

        if(rRet == VIDEO_DECODER_CODEC_ERROR_NONE)
        {
            pt_mp4_dec_driver->get_param(VIDEO_MP4_DEC_PARAM_WIDTH, &u4width);
            rMPEG4HwDecCtrl.u2FrameWidth = (kal_uint16)u4width;
            pt_mp4_dec_driver->get_param(VIDEO_MP4_DEC_PARAM_HEIGHT, &u4height);
            rMPEG4HwDecCtrl.u2FrameHeight = (kal_uint16)u4height;
            pt_mp4_dec_driver->get_param(VIDEO_MP4_DEC_PARAM_REAL_WIDTH, &u4width);
            rMPEG4HwDecCtrl.u2RealFrameWidth = (kal_uint16)u4width;
            pt_mp4_dec_driver->get_param(VIDEO_MP4_DEC_PARAM_REAL_HEIGHT, &u4height);
            rMPEG4HwDecCtrl.u2RealFrameHeight = (kal_uint16)u4height;

            u4width = (kal_uint32)rMPEG4HwDecCtrl.u2FrameWidth;
            u4height = (kal_uint32)rMPEG4HwDecCtrl.u2FrameHeight;

            drv_trace2(TRACE_GROUP_10, MP4HWDEC_WIDTH_HEIGHT, u4width, u4height);

            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            if ((rMPEG4HwDecCtrl.u2FrameWidth > rMPEG4HwDecCtrl.u4MaxWidth) ||
                (rMPEG4HwDecCtrl.u2FrameHeight > rMPEG4HwDecCtrl.u4MaxHeight) ||
                ((rMPEG4HwDecCtrl.u2FrameWidth == 0) ||(rMPEG4HwDecCtrl.u2FrameHeight == 0)))
            {
                _MPGE4HwDecoderReturnBitstream(prBufferHeader->pu1Buffer, prBufferHeader->u4BuffSize);
                return VIDEO_DECODER_CODEC_ERROR_NOT_SUPPORT;
            }

            VideoDecoderSetYUVBuffer(&u4width, &u4height, 4, 0, 0);

            rMPEG4HwDecCtrl.u4FrmBufferSize = ((u4width* u4height)*3)>>1;
            rMPEG4HwDecCtrl.fgInitBuffer = KAL_TRUE;
            rMPEG4HwDecCtrl.fgIsBufferDefaultCacheable = _MPGE4HwDecoderYUVBufferCheck();
            _MPEG4HwcoderDecideSwitchOperation();

            switch(tResult.eStatus)
            {
            case VIDEO_MP4_PARSE_SHR_HDR_RDY:
            case VIDEO_MP4_PARSE_VOS_RDY_WITH_VOP:
                // H.263 case. the 1st decode unit. Or MPEG-4 VOS+VOP
                t_mpeg4_dec_im.yuv_addr = _MPEG4HwDecoderMallocYUVBuffer();
                rMPEG4HwDecCtrl.pu1DecYUVAddr = t_mpeg4_dec_im.yuv_addr;
                drv_trace2(TRACE_GROUP_10, MP4HWDEC_GET_YUV_BUF, (kal_uint32)t_mpeg4_dec_im.yuv_addr, prBufferHeader->u8TimeStamp);

                fgContinue = KAL_TRUE;
                break;

            case VIDEO_MP4_PARSE_VOS_RDY:
                ASSERT(fgContinue == KAL_FALSE);
                _MPGE4HwDecoderReturnBitstream(prBufferHeader->pu1Buffer, prBufferHeader->u4BuffSize);
                break;

            default:
                ASSERT(0);
                _MPGE4HwDecoderReturnBitstream(prBufferHeader->pu1Buffer, prBufferHeader->u4BuffSize);
                rRet = VIDEO_DECODER_CODEC_ERROR_FAIL_PLAYBACK;
                break;
            }
        }
    }

    if(fgContinue == KAL_TRUE)
    {
        kal_uint32 u4result;
        kal_uint32 u4DecodeStartTime, u4DecodeTime;

        if(rMPEG4HwDecCtrl.fgIsFirstFrameIn == KAL_TRUE)
        {
            ASSERT(rMPEG4HwDecCtrl.pu1RefYUVAddr == NULL);
            if(rMPEG4HwDecCtrl.eScenario == VIDEO_SCENARIO_PREVIEW)
            {
                // Only 1 frame is available for preview
                // Set Reference as reconstruct buffer
                t_mpeg4_dec_im.ref_addr = t_mpeg4_dec_im.yuv_addr;
            }
            else
            {
                // To avoid 1st frame is a P-frame, allocate reference buffer with black
                t_mpeg4_dec_im.ref_addr = _MPEG4HwDecoderMallocYUVBuffer();
                drv_trace2(TRACE_GROUP_10, MP4HWDEC_GET_YUV_BUF, (kal_uint32)t_mpeg4_dec_im.ref_addr, prBufferHeader->u8TimeStamp);
                // 第一張拿到的reference frame,  沒有display, adaptor自己display free.
                _MPEG4HwDecoderFreeDispBuffer(t_mpeg4_dec_im.ref_addr);
            }


            rMPEG4HwDecCtrl.fgIsFirstFrameIn = KAL_FALSE;
            rMPEG4HwDecCtrl.pu1RefYUVAddr = t_mpeg4_dec_im.ref_addr;
            rMPEG4HwDecCtrl.pu1DecodingBuffer = prBufferHeader->pu1Buffer;
            rMPEG4HwDecCtrl.u4DecodingBuffSize = prBufferHeader->u4BuffSize;
        }

        // Reconstruct and Reference buffer address should be 8 -byte aligned
        ASSERT(((kal_uint32)t_mpeg4_dec_im.ref_addr&7) == 0);
        ASSERT(((kal_uint32)t_mpeg4_dec_im.yuv_addr&7) == 0);

        u4DecodeStartTime = video_get_current_time();
        t_mpeg4_dec_im.fgIsEOF = KAL_FALSE;
        #ifndef MPEG4_PATTERN_TEST
        u4result = pt_mp4_dec_driver->decode((void *)&t_mpeg4_dec_im, (void *)&t_mpeg4_dec_result_im);
        #else
        u4result = MP4_DECODE_OK;
        // test
        VideoDecoderMemSet(t_mpeg4_dec_im.yuv_addr, 0xFFFFFFFF, rMPEG4HwDecCtrl.u4FrmBufferSize);
        t_mpeg4_dec_result_im.yuv_addr = t_mpeg4_dec_im.yuv_addr;
        t_mpeg4_dec_result_im.u1_vop_coding_type = VIDEO_CODEC_FRAMETYPE_I;
        #endif
        u4DecodeTime = video_get_duration_ms(u4DecodeStartTime);

#ifdef MPEG4HWDECDEBUG
        video_dbg_trace(VIDEO_DBG_OWNER_DECODER, VIDEO_DBG_DECODER_MPEG4HWADPT_COMPLETE,
             u4result);
        video_dbg_trace(VIDEO_DBG_OWNER_DECODER, VIDEO_DBG_DECODER_MPEG4HWADPT_COMPLETE,
             u4DecodeTime);
#endif
        drv_trace2(TRACE_GROUP_10, MP4HWDEC_RESULT, u4result, u4DecodeTime);

        switch(u4result)
        {
            case MP4_DECODE_OK:
            case MP4_DECODE_FAILED:
            case MP4_DECODE_OK_BYPASS:
            case MP4_DECODE_FAILED_TIMEOUT:
            case MP4_DECODE_FAILED_VLC_LIMIT:
            {
                kal_uint8* pu1RefFreeBuf = NULL;

                ASSERT(rMPEG4HwDecCtrl.pu1RefYUVAddr != NULL);
                if(t_mpeg4_dec_result_im.u1_vop_coding_type == 0)
                {
                    rMPEG4HwDecCtrl.eDisplayFrameType = VIDEO_CODEC_FRAMETYPE_I;
                }
                else if(t_mpeg4_dec_result_im.u1_vop_coding_type == 1)
                {
                    rMPEG4HwDecCtrl.eDisplayFrameType = VIDEO_CODEC_FRAMETYPE_P;
                }
                else
                {
                    rMPEG4HwDecCtrl.eDisplayFrameType = VIDEO_CODEC_FRAMETYPE_B;
                }
                video_dbg_trace(VIDEO_DBG_OWNER_DECODER,
                    VIDEO_DBG_DECODER_MPEG4HWADPT_VOP_TYPE, t_mpeg4_dec_result_im.u1_vop_coding_type);

                if(u4result == MP4_DECODE_OK_BYPASS)
                {
                    // To repeat last frame
                    rMPEG4HwDecCtrl.fgIsOutputRepeat = KAL_TRUE;
                }
                else
                {
                    rMPEG4HwDecCtrl.fgIsOutputRepeat = KAL_FALSE;
                }

                if(t_mpeg4_dec_result_im.free_ref_yuv_addr != t_mpeg4_dec_result_im.disp_yuv_addr)
                {
                    // change reference frame
                    rMPEG4HwDecCtrl.pu1RefYUVAddr = t_mpeg4_dec_result_im.disp_yuv_addr;
                }

                pu1RefFreeBuf = t_mpeg4_dec_result_im.free_ref_yuv_addr;
                rMPEG4HwDecCtrl.pu1NextDisplayAddr = t_mpeg4_dec_result_im.disp_yuv_addr;
                rMPEG4HwDecCtrl.fgIsOutputDisplay = KAL_TRUE;

                _MPEG4HwDecoderFreeRefBuffer(pu1RefFreeBuf);
                _MPGE4HwDecoderReturnBitstream(rMPEG4HwDecCtrl.pu1DecodingBuffer,
                    rMPEG4HwDecCtrl.u4DecodingBuffSize);


                if(rMPEG4HwDecCtrl.fgIsFirstFrameOut == KAL_TRUE)
                {
                    drv_trace1(TRACE_GROUP_10, MP4HWDEC_1ST_VOP_TYPE, t_mpeg4_dec_result_im.u1_vop_coding_type);
                    rMPEG4HwDecCtrl.fgIsFirstFrameOut = KAL_FALSE;
                }

                rMPEG4HwDecCtrl.pu1DecodingBuffer = prBufferHeader->pu1Buffer;
                rMPEG4HwDecCtrl.u4DecodingBuffSize = prBufferHeader->u4BuffSize;
            }
                break;
            case MP4_DECODE_BYPASS_PIPELINE:
                rMPEG4HwDecCtrl.fgIsOutputRepeat = KAL_FALSE;
                rMPEG4HwDecCtrl.fgIsOutputDisplay = KAL_FALSE;
                break;
            case MP4_DECODE_BYPASS_EOF:
            default:
                ASSERT(0);
                break;
        }
    }
    return rRet;
}

VIDEO_DECODER_CODEC_ERROR_T MPEG4HwDecoderGetNextDisplay(kal_uint8** pu1NextFrameAddr, VIDEO_DECODER_PRIVATE_OUTPUT_T* prPrivateOutput)
{
    VIDEO_DECODER_CODEC_ERROR_T rRet = VIDEO_DECODER_CODEC_ERROR_NONE;

    if (rMPEG4HwDecCtrl.fgIsOutputDisplay == KAL_TRUE)
    {
        prPrivateOutput->fgRepeatLastFrame = KAL_FALSE;
        if(rMPEG4HwDecCtrl.fgIsOutputRepeat == KAL_TRUE)
        {
            prPrivateOutput->fgRepeatLastFrame = KAL_TRUE;
            rMPEG4HwDecCtrl.fgIsOutputRepeat = KAL_FALSE;
        }
        *pu1NextFrameAddr = rMPEG4HwDecCtrl.pu1NextDisplayAddr;
        prPrivateOutput->eFrameType = rMPEG4HwDecCtrl.eDisplayFrameType;
        prPrivateOutput->u2FrameHeight = rMPEG4HwDecCtrl.u2FrameHeight;
        prPrivateOutput->u2FrameWidth = rMPEG4HwDecCtrl.u2FrameWidth;
        prPrivateOutput->u2ClipBottom= rMPEG4HwDecCtrl.u2RealFrameHeight - 1;
        prPrivateOutput->u2ClipRight= rMPEG4HwDecCtrl.u2RealFrameWidth - 1;
        prPrivateOutput->u2ClipLeft = 0;
        prPrivateOutput->u2ClipTop = 0;
        prPrivateOutput->fgYUVSeperated = KAL_FALSE;
    }
    else
    {
        if(rMPEG4HwDecCtrl.fgEOFSet == KAL_TRUE)
        {
            prPrivateOutput->fgEOF = KAL_TRUE;
            video_dbg_trace(VIDEO_DBG_OWNER_DECODER, VIDEO_DBG_DECODER_MPEG4HWADPT_EOF,
                    0);
            drv_trace0(TRACE_GROUP_10, MP4HWDEC_RETURN_EOF);
        }
        *pu1NextFrameAddr = NULL;
        /* EOF should be sent once for common part requirement */
        rMPEG4HwDecCtrl.fgEOFSet = KAL_FALSE;

    }

    if (rMPEG4HwDecCtrl.fgIsOutputDisplay == KAL_TRUE)
    {
        // Switch frame buffer cache attribute to the gotten
        switch(rMPEG4HwDecCtrl.eFrmBufferOperation)
        {
        case MPEG4_SWITCH_TO_CACHE:
            *pu1NextFrameAddr = (kal_uint8*) VideoCommExtBufferCacheableSwitch((kal_uint32)(*pu1NextFrameAddr) , rMPEG4HwDecCtrl.u4FrmBufferSize, VIDEO_NON_CACHEABLE);
        break;
        case MPEG4_SWITCH_TO_NONCACHE:
            *pu1NextFrameAddr = (kal_uint8*) VideoCommExtBufferCacheableSwitch((kal_uint32)(*pu1NextFrameAddr) , rMPEG4HwDecCtrl.u4FrmBufferSize, VIDEO_CACHEABLE);
        break;
        case MPEG4_SWITCH_NONE:
        break;
        default:
            ASSERT(0);
        break;
        };
        rMPEG4HwDecCtrl.fgIsOutputDisplay = KAL_FALSE;
    }

    drv_trace1(TRACE_GROUP_10, MP4HWDEC_GET_DISPLAY, (kal_uint32)(*pu1NextFrameAddr));
    #ifdef MPEG4HWDECDEBUG
    video_dbg_trace(VIDEO_DBG_OWNER_DECODER, VIDEO_DBG_DECODER_MPEG4HWADPT_NEXT_DISP,
         (kal_uint32)(*pu1NextFrameAddr));
    #endif

    return rRet;
}

void *MPEG4HwDecMalloc(unsigned int u4Size)
{
    return VideoDecoderMalloc(u4Size);
}

void MPEG4HwDecFree(void *pVoid)
{
    VideoDecoderFree(pVoid);
}

static const VIDEO_DECODER_CODEC_API_T rMPEG4HWAPI =
{
    MPEG4HwDecoderOpenAdapt,
    MPEG4HwDecoderInitAdapt,
    MPEG4HwDecoderGetParameterAdapt,
    MPEG4HwDecoderSetParameterAdapt,
    MPEG4HwDecoderStartAdapt,
    MPEG4HwDecoderDeInitAdapt,
    MPEG4HwDecoderCloseAdapt,
    MPEG4HwDecoderGetNextDisplay
};

VIDEO_DECODER_CODEC_API_T* GetMPEG4HwDecoderHandler(VIDEO_DECODER_SCENARIO_T eType)
{
    MPEG4_DECODER_CUSTOM_SETTING_T tCustomSetting;
    rMPEG4HwDecCtrl.eScenario = eType;

    VideoDecoderGetCustomSetting(&tCustomSetting);
    rMPEG4HwDecCtrl.u4MaxWidth = tCustomSetting.u4MaxWidth;
    rMPEG4HwDecCtrl.u4MaxHeight = tCustomSetting.u4MaxHeight;

    drv_trace4(TRACE_GROUP_10, MP4HWDEC_SCENARIO, rMPEG4HwDecCtrl.eScenario,
        rMPEG4HwDecCtrl.u4MaxWidth, rMPEG4HwDecCtrl.u4MaxHeight, 0);

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
    #endif
    return (VIDEO_DECODER_CODEC_API_T*)&rMPEG4HWAPI;
}

#endif /* __VE_MPEG4_DEC_HW_SUPPORT__ */
#endif /* __VE_VIDEO_ARCHI_V2__ */

