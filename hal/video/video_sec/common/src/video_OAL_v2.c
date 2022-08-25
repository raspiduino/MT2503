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
 *   video_OAL_v2.c
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
 *
 * removed!
 *
 * removed!
 ****************************************************************************/
#include "drv_comm.h"
#include "drv_features_video.h"
#ifdef __VE_VIDEO_ARCHI_V2__

#if defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_SW_SUPPORT__) || \
    defined(__VE_RV_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_ENC_SW_SUPPORT__)

#include "video_types_v2.h"
#include "video_buffer_management_v2.h"
#include "video_encoder_component_v2.h"
#include "vcodec_v2_trc.h"
#include "video_codec_if_v2.h"
#include "video_codec_type_v2.h"
#include "kal_trace.h"
#include "video_dbg_v2.h"
//#include "vcodec_OAL.h"
#include "vcodec_if.h"
#include "cache_sw.h"

extern kal_uint32 query_opposite_switchable_cacheaddr_ram(kal_uint32 addr);
extern void kal_assert_fail_native(char* expr, char* file, kal_uint32 line);

static void _VideoCommEncAssert(void)
{
    ASSERT(0);
}

#ifdef __VE_MM_DCM_SUPPORT__
#include "dcmgr.h" //DCM

#pragma arm section code = "DYNAMIC_CODE_VECOM_ROCODE", rodata = "DYNAMIC_CODE_VECOM_RODATA"
#endif

void VideoQueryMemType(void *pBuffer_VA, unsigned int u4Size, VCODEC_MEMORY_TYPE_T *peMemType)
{
    if (VideoCommIsExtBufferCacheable((kal_uint32)pBuffer_VA, (kal_uint32)u4Size) == KAL_TRUE)
    {
        *peMemType = VCODEC_BUFFER_CACHEABLE;
    }
    else
    {
        *peMemType = VCODEC_BUFFER_NON_CACHEABLE;
    }
}

void VideoQueryPhysicalAddr(void *pBuffer_VA, void **pBufferOut_PA)
{
    if (pBuffer_VA == NULL)
    {
        *pBufferOut_PA = NULL;
    }
    else
    {
        if (VideoCommIsExtBufferCacheable((kal_uint32)pBuffer_VA, (kal_uint32)4) == KAL_TRUE)
        {
    #if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
            if (is_predef_dyna_c_region((kal_uint32)pBuffer_VA, (kal_uint32)4))
            {
                *pBufferOut_PA = (void *)virt_to_phys((void *)pBuffer_VA);
        	}
        	else
    #endif
            {
                *pBufferOut_PA = pBuffer_VA;
            }
        }
        else
        {
            *pBufferOut_PA = pBuffer_VA;
        }
    }
}


// VCodecSwitchMemType - return 0 if success.
//                       return -1 if failed, but pBufferOut_VA will be assigned with pBuffer_VA
int VideoSwitchMemType(void *pBuffer_VA, unsigned int u4Size, VCODEC_MEMORY_TYPE_T eMemType, void **pBufferOut_VA)
{
    VIDEO_MEMORY_SWITCH_T eSwitch;
    VCODEC_MEMORY_TYPE_T eMemTypeAfterSwitch;

    eSwitch = (eMemType == VCODEC_BUFFER_CACHEABLE) ? (VIDEO_CACHEABLE) : (VIDEO_NON_CACHEABLE);
    *pBufferOut_VA = (void *)VideoCommExtBufferCacheableSwitch((kal_uint32)pBuffer_VA, (kal_uint32)u4Size, eSwitch);
    VideoQueryMemType(*pBufferOut_VA, u4Size, &eMemTypeAfterSwitch);
    if (eMemTypeAfterSwitch != eMemType)
    {
        return -1;
    }

    return 0;
}

// VCodecFlushCachedBuffer - u4Size is in byte
void VideoFlushCachedBuffer(void *pBuffer_VA, unsigned int u4Size)
{
    VideoCommFlushBuffer((kal_uint32)pBuffer_VA, (kal_uint32)u4Size);
}

// VCodecInvalidateCachedBuffer - u4Size is in byte
void VideoInvalidateCachedBuffer(void *pBuffer_VA, unsigned int u4Size)
{
    VideoCommInvalidateBuffer((kal_uint32)pBuffer_VA, (kal_uint32)u4Size);
}

void VideoFlushCachedBufferAll(void)
{
    _VideoCommEncAssert();
    return;
}

void VideoInvalidateCachedBufferAll(void)
{
    _VideoCommEncAssert();
    return;
}

void VideoFlushInvalidateCacheBufferAll(void)
{
    _VideoCommEncAssert();
    return;
}

void VideoMemSet(void *pBuffer_VA, char cValue, unsigned int u4Length)
{
    kal_mem_set(pBuffer_VA, (kal_int32)cValue, (kal_uint32)u4Length);
    return;

}
                                         
void VideoMemCopy(void *pvDest , const void *pvSrc, unsigned int u4Length)       
{
    if ((pvDest == NULL)||
        (pvSrc == NULL))
    {
        _VideoCommEncAssert();
    }

    kal_mem_cpy(pvDest, (void *)pvSrc, (kal_uint32)u4Length);
}

void VideoAssertFail(char *ptr, int i4Line, int i4Arg)
{
    drv_trace2(TRACE_GROUP_10, VOAL_ASSERT_ERROR, i4Line, i4Arg);
    kal_assert_fail_native(0, ptr, (kal_uint32)i4Line);
}

#ifdef __VE_MM_DCM_SUPPORT__
#pragma arm section code, rodata
#endif

#endif
#endif /* __VE_VIDEO_ARCHI_V2__ */
