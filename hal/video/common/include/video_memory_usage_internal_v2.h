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
 *   video_memory_usage_internal_v2.h
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
 *
 ****************************************************************************/

#ifndef VIDEO_MEMORY_USAGE_INTERNAL_V2_H
#define VIDEO_MEMORY_USAGE_INTERNAL_V2_H

#include "drv_features_video.h"
#if defined(__VE_VIDEO_ARCHI_V2__)
#include "video_codec_mem_v2.h"
#include "va2_video_renderer_mem_req.h"
#include "video_decscheduler_component_if_v2.h"
#include "video_subtitle_decoder_if.h"
#include "mpl_video_clipper.h"
#include "media_provider_mem_usage_internal.h"

/*******************************************************
*
*   Additional memory if there's any
*
*******************************************************/
// This part is due to cacheable memory usage
#if defined(__VE_DYNAMIC_SWITCH_CACHEABILITY__)
#define _V2_MEM_MGR_ADM_OVERHEAD (2*1024)
#define CACHE_OVERHEAD  (0)
#elif defined(__VE_MTK_L1CACHEABLE__)
#define _V2_MEM_MGR_ADM_OVERHEAD (2*1024)
#define CACHE_OVERHEAD  (31*1024 + 32*1024 + 4*1024)
#else
#define _V2_MEM_MGR_ADM_OVERHEAD (0)
#define CACHE_OVERHEAD  (0)
#endif

#define ADDITIONAL_OVERHEAD (CACHE_OVERHEAD + _V2_MEM_MGR_ADM_OVERHEAD)

/*******************************************************
*
*   Decide the total external memory needed by
*   decoder component
*
*******************************************************/

#define __VE_VIDEO_V2_DEC_EXT_MEMORY__  \
    (DECODER_MEM_SIZE +  VA2_VIDEO_RENDERER_EXT_MEM_REQ + \
    V2SCH_EXT_MEM_SIZE + 2048 + ADDITIONAL_OVERHEAD)

#if defined(__VE_SPECIAL_MEM_ALLOCATION_FOR_RENDERER__)
    #if (__VE_VIDEO_V2_DEC_EXT_MEMORY__ >= (32*1024*1024))
        #error "A limitation put on memory management currently"
    #endif

    //Since memory is configerable by our customer,
    //there is a chance that the memory size may be just across 16M boundary
    //so that our memory management would fail
    //When this happen, this buffer need an extra size to make sure either the head or tail of the memory pool,
    //a memory not acrossing bounary can always be assured to succerfully allocated
    #if ((__VE_VIDEO_V2_DEC_EXT_MEMORY__ >= (16*1024*1024)) \
    && (__VE_VIDEO_V2_DEC_EXT_MEMORY__ < (16*1024*1024 + VA2_VR_VP_SW_RESIZER_BUFFER_SIZE)))
        #define V2_DEC_ORI_MEMORY_SIZE (__VE_VIDEO_V2_DEC_EXT_MEMORY__)
        #undef __VE_VIDEO_V2_DEC_EXT_MEMORY__
        #define __VE_VIDEO_V2_DEC_EXT_MEMORY__ (V2_DEC_ORI_MEMORY_SIZE + VA2_VR_VP_SW_RESIZER_BUFFER_SIZE)
    #endif
#endif

#define __VE_VIDEO_V2_DEC_N_SUBTITLE_EXT_MEMORY__  \
    (__VE_VIDEO_V2_DEC_EXT_MEMORY__ \
    + VSD_TOTAL_MEM_SIZE \
    + VA2_VIDEO_RENDERER_EXT_MEM_SUBTITLE_REQ)

// QVGA
#define __VE_VIDEO_V2_QVGA_DEC_EXT_MEMORY__  \
    (DECODER_QVGA_MEM_SIZE + VA2_VIDEO_RENDERER_EXT_MEM_REQ + \
    V2SCH_EXT_MEM_SIZE + 2048 + ADDITIONAL_OVERHEAD)

// QVGAMPEG4SP
#define __VE_VIDEO_V2_QVGA_MPEG4SP_DEC_EXT_MEMORY__  \
    (DECODER_QVGAMPEG4SP_MEM_SIZE + VA2_VIDEO_RENDERER_EXT_MEM_REQ + \
    V2SCH_EXT_MEM_SIZE + 2048 + ADDITIONAL_OVERHEAD)


// QCIF
#define __VE_VIDEO_V2_QCIF_DEC_EXT_MEMORY__  \
    (DECODER_QCIF_MEM_SIZE + VA2_VIDEO_RENDERER_EXT_MEM_REQ + \
    V2SCH_EXT_MEM_SIZE + 2048 + ADDITIONAL_OVERHEAD)

// VGA
#define __VE_VIDEO_V2_VGA_DEC_EXT_MEMORY__  \
    (DECODER_VGA_MEM_SIZE + VA2_VIDEO_RENDERER_EXT_MEM_REQ + \
    V2SCH_EXT_MEM_SIZE + 2048 + ADDITIONAL_OVERHEAD)

// CIF
#define __VE_VIDEO_V2_CIF_DEC_EXT_MEMORY__  \
    (DECODER_CIF_MEM_SIZE + VA2_VIDEO_RENDERER_EXT_MEM_REQ + \
    V2SCH_EXT_MEM_SIZE + 2048 + ADDITIONAL_OVERHEAD)


// preview
#define __VE_VIDEO_V2_PREVIEW_DEC_EXT_MEMORY__  \
    (DECODER_PREVIEW_MEM_SIZE + VA2_VIDEO_RENDERER_EXT_MEM_THUMB_REQ + \
    V2SCH_EXT_MEM_SIZE + 2048 + ADDITIONAL_OVERHEAD)

// Live wall paper
#define __VE_VIDEO_V2_DEC_MPEG4_EXT_MEMORY__  \
    (DECODER_VLW_MEM_SIZE + VA2_VIDEO_RENDERER_EXT_MEM_REQ + \
     V2SCH_EXT_MEM_SIZE + 2048 + ADDITIONAL_OVERHEAD)

// UPTOQVGA
#define __VE_VIDEO_V2_UPTOQVGA_DEC_EXT_MEMORY__  \
    (DECODER_UPTOQVGA_MEM_SIZE + 3 + VA2_VIDEO_RENDERER_EXT_MEM_REQ + 4 +\
    V2SCH_EXT_MEM_SIZE + 5 + 2048 + 6 + ADDITIONAL_OVERHEAD)

// UPTOCIF
#define __VE_VIDEO_V2_UPTOCIF_DEC_EXT_MEMORY__  \
    (DECODER_UPTOCIF_MEM_SIZE + 3 + VA2_VIDEO_RENDERER_EXT_MEM_REQ + 4 +\
    V2SCH_EXT_MEM_SIZE + 5 + 2048 + 6+ ADDITIONAL_OVERHEAD)



#if defined(__VE_SPECIAL_MEM_ALLOCATION_FOR_RENDERER__)
    #if (__VE_VIDEO_V2_DEC_MPEG4_EXT_MEMORY__ >= (32*1024*1024))
        #error "A limitation put on memory management currently"
    #endif

    //Since memory is configerable by our customer,
    // there is a chance that the memory size may be just across 16M boundary
    //so that our memory management would fail
    //When this happen, this buffer need an extra size to make sure either the head or tail of the memory pool,
    //a memory not acrossing bounary can always be assured to succerfully allocated
    #if ((__VE_VIDEO_V2_DEC_MPEG4_EXT_MEMORY__ >= (16*1024*1024)) \
    && (__VE_VIDEO_V2_DEC_MPEG4_EXT_MEMORY__ < (16*1024*1024 + VA2_VR_VP_SW_RESIZER_BUFFER_SIZE)))
        #define V2_DEC_ORI_MEMORY_SIZE (__VE_VIDEO_V2_DEC_MPEG4_EXT_MEMORY__)
        #undef __VE_VIDEO_V2_DEC_MPEG4_EXT_MEMORY__
        #define __VE_VIDEO_V2_DEC_MPEG4_EXT_MEMORY__ (V2_DEC_ORI_MEMORY_SIZE + VA2_VR_VP_SW_RESIZER_BUFFER_SIZE)
    #endif
#endif

/*******************************************************
*
*   Calculate the total external memory needed in
*   video recorder
*
*******************************************************/

#define __VE_VIDEO_V2_ENC_EXT_MEMORY__     (VIDEO_V2_RECORDER_EXT_MEM_SIZE + ADDITIONAL_OVERHEAD)
#define __VE_VIDEO_V2_ENC_CIF_EXT_MEMORY__ (VIDEO_V2_RECORDER_CIF_EXT_MEM_SIZE + ADDITIONAL_OVERHEAD)

// AVI writer is special case that no adidtional overhead is needed since it retrieves memory from other pool
// The definition is for background file merge memory usage
#define __VE_VIDEO_V2_AVI_FW_EXT_MEMORY__  (VIDEO_V2_RECORDER_AVI_FW_FILEMERGE_EXT_MEM_SIZE + ADDITIONAL_OVERHEAD)

// MP4 writer
#define __VE_VIDEO_V2_MP4_FW_EXT_MEMORY__  (VIDEO_V2_RECORDER_FW_EXT_MEM_SIZE + ADDITIONAL_OVERHEAD)

// The next line defines the amount of external memory used by File Writer.
#define __VE_VIDEO_V2_ENC_FW_EXT_MEMORY__  (__VE_VIDEO_V2_MP4_FW_EXT_MEMORY__)

/*******************************************************
*
*   Calculate the total external memory needed for VT
*
*******************************************************/
#define __VE_VIDEO_V2_VT_EXT_MEMORY__    \
    (VIDEO_VT_EXT_MEM_SIZE + V2SCH_EXT_MEM_SIZE + \
    VA2_VIDEO_RENDERER_EXT_MEM_REQ + 2048 + ADDITIONAL_OVERHEAD)  //VA2_VR_VT_6268_DISPLAY_BUFFER_SIZE

/*******************************************************
*
*   Calculate the total external memory needed for Video CLipper
*
*******************************************************/
#define AVI_PROVIDER_EXT_MEM_SIZE   (AVI_MP_CORE_MEM_SIZE_IF + AVI_MP_AUDIO_MEM_SIZE_IF + AVI_MP_VIDEO_MEM_SIZE_IF)
#define MP4_PROVIDER_EXT_MEM_SIZE   (MP4_MP_CORE_MEM_SIZE_IF + MP4_MP_AUDIO_MEM_SIZE_IF + MP4_MP_VIDEO_MEM_SIZE_IF)

#define __VE_VIDEO_V2_VIDEO_CLIPPER_EXT_MEMORY__    \
    (VENC_FW_EXT_MEM_SIZE + ADDITIONAL_OVERHEAD +   \
    MPLVC_EXT_MEM_SIZE + MP4_PROVIDER_EXT_MEM_SIZE)

#else
    #define __VE_VIDEO_V2_DEC_EXT_MEMORY__             (0)
    #define __VE_VIDEO_V2_QVGA_DEC_EXT_MEMORY__        (0)
    #define __VE_VIDEO_V2_PREVIEW_DEC_EXT_MEMORY__     (0)
    #define __VE_VIDEO_V2_ENC_EXT_MEMORY__             (0)
    #define __VE_VIDEO_V2_VT_EXT_MEMORY__              (0)
    #define __VE_VIDEO_V2_ENC_FW_EXT_MEMORY__          (0)
    #define __VE_VIDEO_V2_AVI_FW_EXT_MEMORY__          (0)
    #define __VE_VIDEO_V2_MP4_FW_EXT_MEMORY__          (0)
    #define __VE_VIDEO_V2_DEC_MPEG4_EXT_MEMORY__       (0)
    #define __VE_VIDEO_V2_CIF_DEC_EXT_MEMORY__         (0)
    #define __VE_VIDEO_V2_QCIF_DEC_EXT_MEMORY__        (0)
    #define __VE_VIDEO_V2_VGA_DEC_EXT_MEMORY__         (0)
    #define __VE_VIDEO_V2_UPTOCIF_DEC_EXT_MEMORY__     (0)
    #define __VE_VIDEO_V2_UPTOQVGA_DEC_EXT_MEMORY__    (0)
    #define __VE_VIDEO_V2_ENC_CIF_EXT_MEMORY__         (0)
    #define __VE_VIDEO_V2_VIDEO_CLIPPER_EXT_MEMORY__   (0)
    #define __VE_VIDEO_V2_DEC_N_SUBTITLE_EXT_MEMORY__  (0)
#endif /* __VE_VIDEO_ARCHI_V2__ */
#endif /* VIDEO_MEMORY_USAGE_INTERNAL_V2_H */

