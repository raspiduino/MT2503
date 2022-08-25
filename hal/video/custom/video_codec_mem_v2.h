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
 *   video_codec_mem_v2.h
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef VIDEO_CODEC_MEM_V2_H
#define VIDEO_CODEC_MEM_V2_H

#include "drv_features_video.h"

#ifdef __VE_VIDEO_ARCHI_V2__
#include "drv_features_chip_select.h"

#ifdef __VE_VIDEO_VT_SUPPORT__
#include "mpl_vt.h"
#endif

#if defined(__VE_MJPEG_ENC_BYPASS__)
    #include "jpeg_mjpeg_mem.h"
#endif

#include "sw_video_decode_custom.h"
#include "hw_video_decode_custom.h"
#include "sw_video_encode_custom.h"
#include "hw_video_encode_custom.h"
#include "video_codec_mem_custom_v2.h"
#include "video_encoder_component_if_v2.h"
#include "video_comm_component_v2.h"
#include "video_types_v2.h"
#include "avi_muxer_if_v2.h"
#include "video_muxer_mem_req_v2.h"
#include "mp4_muxer_adapter_if_v2.h"
#include "hal_custom_video_if.h"

#define CPU_CACHE_LINE_SIZE_MINE 32


#if defined(__VIDEO_V2_MT6236_SERIES__)
#define VIDEO_EXTRA_MEM_SIZE 102400  // For INT RAM backup. 100KB is a temp value
#else
#define VIDEO_EXTRA_MEM_SIZE 0
#endif

// preview
#define DECODER_PREVIEW_ESSENTIAL_BUFFER_NUM    1 // 3       //<preview_1_frame>
#define RM_DECODER_PREVIEW_ESSENTIAL_BUFFER_NUM 1 //  (5)    //<preview_1_frame>

#if defined(__VIDEO_V2_MT6268_SERIES__)
#define DECODER_ESSENTIAL_BUFFER_NUM    4 // For HW pipline, one additional frame will need.
#else
#define DECODER_ESSENTIAL_BUFFER_NUM    3
#endif
#define RM_DECODER_ESSENTIAL_BUFFER_NUM    (5)
#define VP8_DECODER_ESSENTIAL_BUFFER_NUM    (5)

#define ALIGN_X(VAL, SIZE) \
           ((((VAL)+(SIZE)-1)/(SIZE))*(SIZE))

/***************************************
*
*   Custom value checking
*
***************************************/

#ifdef __VE_MPEG4_DEC_SW_SUPPORT__
    #ifdef __VE_MTV_SUPPORT__
        #if (MPEG4_SUPPORT_RESOLUTION < (320*240))
            #error "Please make sure MPEG4_SUPPORT_RESOLUTION is higher than 320x240 when enable __DRV_MTV_SUPPORT__"
        #endif
    #endif /*__VE_MTV_SUPPORT__*/
#endif /* __VE_MPEG4_DEC_SW_SUPPORT__ */

/***************************************
*
*   Decide the size of frame buffer & the working memory of codec
*
*   Assumption: YUV420 format
*
***************************************/
#define GUARD_PATTERN_LENGTH   (4)
#define CODEC_ADM_SIZE  (512)

#define FRM_BUFFER_SIZE             0
#define CODEC_WORKING_MEM_SIZE      0
#define TEMP_TOTAL_MEM_SIZE     0

#define MAX_ONE_FRM_BUFFER_SIZE     0
#define MAX_FRM_BUFFER_WIDTH        0
#define MAX_FRM_BUFFER_HEIGHT       0


#ifdef __VE_MPEG4_DEC_HW_SUPPORT__
    #if (MPEG4_EXTRA_BUFFER_NUM_SP < 0)
    #error "Extra frame number of MPEG4 decoder should be no bigger than or equal to 0"
    #endif

    #define MPEG4_SP_FAST_MODE_BUFFER_SIZE  0 // HW no subsampling
    #define MPEG4_SP_NORMAL_BUFFER_SIZE     (MPEG4_DEC_MAX_NORMAL_WIDTH_SP * MPEG4_DEC_MAX_NORMAL_HEIGHT_SP * (MPEG4_EXTRA_BUFFER_NUM_SP + DECODER_ESSENTIAL_BUFFER_NUM) * 3 / 2 + (CPU_CACHE_LINE_SIZE_MINE*2))
    #define MPEG4_ASP_NORMAL_BUFFER_SIZE    0
    #define MPEG4_DEC_WORKING_MEM_ASP       0
#endif /*__VE_MPEG4_DEC_HW_SUPPORT__*/


#ifdef __VE_MPEG4_DEC_SW_SUPPORT__
    #if (MPEG4_EXTRA_BUFFER_NUM_SP < 0)
        #error "[MPEG4 SP] Extra frame number of MPEG4 decoder should be no bigger than or equal to 0"
    #endif

    //#define MPEG4_SP_DEC_MAX_WIDTH_1_TO_2_ALIGN     ALIGN_X((MPEG4_DEC_MAX_WIDTH_1_TO_2_SP), 16)
    //#define MPEG4_SP_DEC_MAX_HEIGHT_1_TO_2_ALIGN    ALIGN_X((MPEG4_DEC_MAX_HEIGHT_1_TO_2_SP / 2), 16)
    #define MPEG4_SP_DEC_MAX_HALF_WIDTH_ALIGN       ALIGN_X((MPEG4_DEC_MAX_WIDTH_1_TO_4_SP / 2), 16)
    #define MPEG4_SP_DEC_MAX_HALF_HEIGHT_ALIGN      ALIGN_X((MPEG4_DEC_MAX_HEIGHT_1_TO_4_SP / 2), 16)
    #define MPEG4_SP_DEC_MAX_WIDTH_1_TO_8_ALIGN     ALIGN_X((MPEG4_DEC_MAX_WIDTH_SP / 2), 16)
    #define MPEG4_SP_DEC_MAX_HEIGHT_1_TO_8_ALIGN    ALIGN_X((MPEG4_DEC_MAX_HEIGHT_SP / 4), 16)

    #define MPEG4_SP_NORMAL_BUFFER_SIZE             (MPEG4_DEC_MAX_NORMAL_WIDTH_SP * MPEG4_DEC_MAX_NORMAL_HEIGHT_SP * (MPEG4_EXTRA_BUFFER_NUM_SP + DECODER_ESSENTIAL_BUFFER_NUM) * 3 / 2 + (CPU_CACHE_LINE_SIZE_MINE * 2))
    //#define MPEG4_SP_FAST_MODE_1_TO_2_BUFFER_SIZE   ((MPEG4_SP_DEC_MAX_WIDTH_1_TO_2_ALIGN * MPEG4_SP_DEC_MAX_HEIGHT_1_TO_2_ALIGN * (MPEG4_EXTRA_BUFFER_NUM_SP + DECODER_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE * 2))
    #define MPEG4_SP_FAST_MODE_BUFFER_SIZE          ((MPEG4_SP_DEC_MAX_HALF_WIDTH_ALIGN * MPEG4_SP_DEC_MAX_HALF_HEIGHT_ALIGN * (MPEG4_EXTRA_BUFFER_NUM_SP + DECODER_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE * 2))
    #define MPEG4_SP_FAST_MODE_1_TO_8_BUFFER_SIZE   ((MPEG4_SP_DEC_MAX_WIDTH_1_TO_8_ALIGN * MPEG4_SP_DEC_MAX_HEIGHT_1_TO_8_ALIGN * (MPEG4_EXTRA_BUFFER_NUM_SP + DECODER_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE * 2))

    #ifdef __MP4_DEC_SW_SUPPORT_ASP__
        #if (MPEG4_EXTRA_BUFFER_NUM_ASP < 0)
            #error "[MPEG4 ASP] Extra frame number of MPEG4 decoder should be no bigger than or equal to 0"
        #endif

        //#define MPEG4_ASP_DEC_MAX_WIDTH_1_TO_2_ALIGN    ALIGN_X((MPEG4_DEC_MAX_WIDTH_1_TO_2_ASP), 16)
        //#define MPEG4_ASP_DEC_MAX_HEIGHT_1_TO_2_ALIGN   ALIGN_X((MPEG4_DEC_MAX_HEIGHT_1_TO_2_ASP / 2), 16)
        #define MPEG4_ASP_DEC_MAX_HALF_WIDTH_ALIGN      ALIGN_X((MPEG4_DEC_MAX_WIDTH_1_TO_4_ASP / 2), 16)
        #define MPEG4_ASP_DEC_MAX_HALF_HEIGHT_ALIGN     ALIGN_X((MPEG4_DEC_MAX_HEIGHT_1_TO_4_ASP / 2), 16)
        #define MPEG4_ASP_DEC_MAX_WIDTH_1_TO_8_ALIGN    ALIGN_X((MPEG4_DEC_MAX_WIDTH_ASP / 2), 16)
        #define MPEG4_ASP_DEC_MAX_HEIGHT_1_TO_8_ALIGN   ALIGN_X((MPEG4_DEC_MAX_HEIGHT_ASP / 4), 16)

        #define MPEG4_ASP_NORMAL_BUFFER_SIZE            (MPEG4_DEC_MAX_NORMAL_WIDTH_ASP * MPEG4_DEC_MAX_NORMAL_HEIGHT_ASP * (MPEG4_EXTRA_BUFFER_NUM_ASP + DECODER_ESSENTIAL_BUFFER_NUM) * 3 / 2 + (CPU_CACHE_LINE_SIZE_MINE * 2))
        //#define MPEG4_ASP_FAST_MODE_BUFFER_1_TO_2_SIZE  ((MPEG4_ASP_DEC_MAX_WIDTH_1_TO_2_ALIGN * MPEG4_ASP_DEC_MAX_HEIGHT_1_TO_2_ALIGN * (MPEG4_EXTRA_BUFFER_NUM_ASP + DECODER_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE * 2))
        #define MPEG4_ASP_FAST_MODE_BUFFER_SIZE         ((MPEG4_ASP_DEC_MAX_HALF_WIDTH_ALIGN * MPEG4_ASP_DEC_MAX_HALF_HEIGHT_ALIGN * (MPEG4_EXTRA_BUFFER_NUM_ASP + DECODER_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE * 2))
        #define MPEG4_ASP_FAST_MODE_1_TO_8_BUFFER_SIZE  ((MPEG4_ASP_DEC_MAX_WIDTH_1_TO_8_ALIGN * MPEG4_ASP_DEC_MAX_HEIGHT_1_TO_8_ALIGN * (MPEG4_EXTRA_BUFFER_NUM_ASP + DECODER_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE * 2))
    #endif  /*__MP4_DEC_SW_SUPPORT_ASP__*/
#endif  /* __VE_MPEG4_DEC_SW_SUPPORT__ */


#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    // MPEG4 SP +
    // The comparison of 1:2 must be written in the future if needed.
    #if (MPEG4_SP_FAST_MODE_BUFFER_SIZE > MPEG4_SP_NORMAL_BUFFER_SIZE)
        // 1:4 > 1:1
        #if (MPEG4_SP_FAST_MODE_BUFFER_SIZE > MPEG4_SP_FAST_MODE_1_TO_8_BUFFER_SIZE)
            // 1:4 > 1:8
            #define MPEG4_SP_FRM_BUFFER_SIZE        (MPEG4_SP_FAST_MODE_BUFFER_SIZE)
            #define MPEG4_SP_ONE_FRM_BUFFER_SIZE    (MPEG4_SP_DEC_MAX_HALF_WIDTH_ALIGN * MPEG4_SP_DEC_MAX_HALF_HEIGHT_ALIGN * 3 / 2)
            #define MPEG4_SP_FRM_BUFFER_WIDTH       (MPEG4_SP_DEC_MAX_HALF_WIDTH_ALIGN)
            #define MPEG4_SP_FRM_BUFFER_HEIGHT      (MPEG4_SP_DEC_MAX_HALF_HEIGHT_ALIGN)
        #else
            // 1:8 > 1:4
            #define MPEG4_SP_FRM_BUFFER_SIZE        (MPEG4_SP_FAST_MODE_1_TO_8_BUFFER_SIZE)
            #define MPEG4_SP_ONE_FRM_BUFFER_SIZE    (MPEG4_SP_DEC_MAX_WIDTH_1_TO_8_ALIGN * MPEG4_SP_DEC_MAX_HEIGHT_1_TO_8_ALIGN * 3 / 2)
            #define MPEG4_SP_FRM_BUFFER_WIDTH       (MPEG4_SP_DEC_MAX_WIDTH_1_TO_8_ALIGN)
            #define MPEG4_SP_FRM_BUFFER_HEIGHT      (MPEG4_SP_DEC_MAX_HEIGHT_1_TO_8_ALIGN)
        #endif
    #else
        // 1:1 > 1:4
        #if (MPEG4_SP_NORMAL_BUFFER_SIZE > MPEG4_SP_FAST_MODE_1_TO_8_BUFFER_SIZE)
            // 1:1 > 1:8
            #define MPEG4_SP_FRM_BUFFER_SIZE        (MPEG4_SP_NORMAL_BUFFER_SIZE)
            #define MPEG4_SP_ONE_FRM_BUFFER_SIZE    (MPEG4_DEC_MAX_NORMAL_WIDTH_SP * MPEG4_DEC_MAX_NORMAL_HEIGHT_SP * 3 / 2)
            #define MPEG4_SP_FRM_BUFFER_WIDTH       (MPEG4_DEC_MAX_NORMAL_WIDTH_SP)
            #define MPEG4_SP_FRM_BUFFER_HEIGHT      (MPEG4_DEC_MAX_NORMAL_HEIGHT_SP)
        #else
            // 1:8 > 1:1
            #define MPEG4_SP_FRM_BUFFER_SIZE        (MPEG4_SP_FAST_MODE_1_TO_8_BUFFER_SIZE)
            #define MPEG4_SP_ONE_FRM_BUFFER_SIZE    (MPEG4_SP_DEC_MAX_WIDTH_1_TO_8_ALIGN * MPEG4_SP_DEC_MAX_HEIGHT_1_TO_8_ALIGN * 3 / 2)
            #define MPEG4_SP_FRM_BUFFER_WIDTH       (MPEG4_SP_DEC_MAX_WIDTH_1_TO_8_ALIGN)
            #define MPEG4_SP_FRM_BUFFER_HEIGHT      (MPEG4_SP_DEC_MAX_HEIGHT_1_TO_8_ALIGN)
        #endif
    #endif
    #define MPEG4_SP_FRM_BUFFER_SIZE_CACHE_LINE     ALIGN_X((MPEG4_SP_FRM_BUFFER_SIZE + GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)
    #define MPEG4_SP_WORKING_MEM_SIZE_CACHE_LINE    ALIGN_X((MPEG4_DEC_WORKING_MEM_SP + CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)
    // MPEG4 SP -

    // MPEG4 ASP +
    #ifdef __MP4_DEC_SW_SUPPORT_ASP__
        // The comparison of 1:2 must be written in the future if needed.
        #if (MPEG4_ASP_FAST_MODE_BUFFER_SIZE > MPEG4_ASP_NORMAL_BUFFER_SIZE)
            // 1:4 > 1:1
            #if (MPEG4_ASP_FAST_MODE_BUFFER_SIZE > MPEG4_ASP_FAST_MODE_1_TO_8_BUFFER_SIZE)
                // 1:4 > 1:8
                #define MPEG4_ASP_FRM_BUFFER_SIZE       (MPEG4_ASP_FAST_MODE_BUFFER_SIZE)
                #define MPEG4_ASP_ONE_FRM_BUFFER_SIZE   (MPEG4_ASP_DEC_MAX_HALF_WIDTH_ALIGN * MPEG4_ASP_DEC_MAX_HALF_HEIGHT_ALIGN * 3 / 2)
                #define MPEG4_ASP_FRM_BUFFER_WIDTH      (MPEG4_ASP_DEC_MAX_HALF_WIDTH_ALIGN)
                #define MPEG4_ASP_FRM_BUFFER_HEIGHT     (MPEG4_ASP_DEC_MAX_HALF_HEIGHT_ALIGN)
            #else
                // 1:8 > 1:4
                #define MPEG4_ASP_FRM_BUFFER_SIZE       (MPEG4_ASP_FAST_MODE_1_TO_8_BUFFER_SIZE)
                #define MPEG4_ASP_ONE_FRM_BUFFER_SIZE   (MPEG4_ASP_DEC_MAX_WIDTH_1_TO_8_ALIGN * MPEG4_ASP_DEC_MAX_HEIGHT_1_TO_8_ALIGN * 3 / 2)
                #define MPEG4_ASP_FRM_BUFFER_WIDTH      (MPEG4_ASP_DEC_MAX_WIDTH_1_TO_8_ALIGN)
                #define MPEG4_ASP_FRM_BUFFER_HEIGHT     (MPEG4_ASP_DEC_MAX_HEIGHT_1_TO_8_ALIGN)
            #endif
        #else
            // 1:1 > 1:4
            #if (MPEG4_ASP_NORMAL_BUFFER_SIZE > MPEG4_ASP_FAST_MODE_1_TO_8_BUFFER_SIZE)
                // 1:1 > 1:8
                #define MPEG4_ASP_FRM_BUFFER_SIZE       (MPEG4_ASP_NORMAL_BUFFER_SIZE)
                #define MPEG4_ASP_ONE_FRM_BUFFER_SIZE   (MPEG4_DEC_MAX_NORMAL_WIDTH_ASP * MPEG4_DEC_MAX_NORMAL_HEIGHT_ASP * 3 / 2)
                #define MPEG4_ASP_FRM_BUFFER_WIDTH      (MPEG4_DEC_MAX_NORMAL_WIDTH_ASP)
                #define MPEG4_ASP_FRM_BUFFER_HEIGHT     (MPEG4_DEC_MAX_NORMAL_HEIGHT_ASP)
            #else
                // 1:8 > 1:1
                #define MPEG4_ASP_FRM_BUFFER_SIZE       (MPEG4_ASP_FAST_MODE_1_TO_8_BUFFER_SIZE)
                #define MPEG4_ASP_ONE_FRM_BUFFER_SIZE   (MPEG4_ASP_DEC_MAX_WIDTH_1_TO_8_ALIGN * MPEG4_ASP_DEC_MAX_HEIGHT_1_TO_8_ALIGN * 3 / 2)
                #define MPEG4_ASP_FRM_BUFFER_WIDTH      (MPEG4_ASP_DEC_MAX_WIDTH_1_TO_8_ALIGN)
                #define MPEG4_ASP_FRM_BUFFER_HEIGHT     (MPEG4_ASP_DEC_MAX_HEIGHT_1_TO_8_ALIGN)
            #endif
        #endif
        #define MPEG4_ASP_FRM_BUFFER_SIZE_CACHE_LINE    ALIGN_X((MPEG4_ASP_FRM_BUFFER_SIZE + GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)
        #define MPEG4_ASP_WORKING_MEM_SIZE_CACHE_LINE   ALIGN_X((MPEG4_DEC_WORKING_MEM_ASP + CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)
    #endif
    // MPEG4 ASP -

    // Comparision +
    #ifdef __MP4_DEC_SW_SUPPORT_ASP__
        // Compare frame buffer
        #if ((MPEG4_ASP_FRM_BUFFER_SIZE_CACHE_LINE) > (MPEG4_SP_FRM_BUFFER_SIZE_CACHE_LINE))
            #define MPEG4_FRM_BUFFER_SIZE           (MPEG4_ASP_FRM_BUFFER_SIZE_CACHE_LINE)
            #define MPEG4_ONE_FRM_BUFFER_SIZE       (MPEG4_ASP_ONE_FRM_BUFFER_SIZE)
            #define MPEG4_FRM_BUFFER_WIDTH          (MPEG4_ASP_FRM_BUFFER_WIDTH)
            #define MPEG4_FRM_BUFFER_HEIGHT         (MPEG4_ASP_FRM_BUFFER_HEIGHT)

            #undef MPEG4_SUPPORT_RESOLUTION
            #undef MPEG4_MAX_NORMAL_MODE_RESOLUTION
            #undef MPEG4_DEC_MAX_WIDTH
            #undef MPEG4_DEC_MAX_HEIGHT
            #undef MPEG4_EXTRA_BUFFER_NUM

            #define MPEG4_SUPPORT_RESOLUTION         MPEG4_SUPPORT_RESOLUTION_ASP
            #define MPEG4_MAX_NORMAL_MODE_RESOLUTION MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP
            #define MPEG4_DEC_MAX_WIDTH              MPEG4_DEC_MAX_WIDTH_ASP
            #define MPEG4_DEC_MAX_HEIGHT             MPEG4_DEC_MAX_HEIGHT_ASP
            #define MPEG4_EXTRA_BUFFER_NUM           MPEG4_EXTRA_BUFFER_NUM_ASP

            #if 0  // Leroy
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif  // 0
        #else
            #define MPEG4_FRM_BUFFER_SIZE           (MPEG4_SP_FRM_BUFFER_SIZE_CACHE_LINE)
            #define MPEG4_ONE_FRM_BUFFER_SIZE       (MPEG4_SP_ONE_FRM_BUFFER_SIZE)
            #define MPEG4_FRM_BUFFER_WIDTH          (MPEG4_SP_FRM_BUFFER_WIDTH)
            #define MPEG4_FRM_BUFFER_HEIGHT         (MPEG4_SP_FRM_BUFFER_HEIGHT)

            #undef MPEG4_SUPPORT_RESOLUTION
            #undef MPEG4_MAX_NORMAL_MODE_RESOLUTION
            #undef MPEG4_DEC_MAX_WIDTH
            #undef MPEG4_DEC_MAX_HEIGHT
            #undef MPEG4_EXTRA_BUFFER_NUM

            #define MPEG4_SUPPORT_RESOLUTION         MPEG4_SUPPORT_RESOLUTION_SP
            #define MPEG4_MAX_NORMAL_MODE_RESOLUTION MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP
            #define MPEG4_DEC_MAX_WIDTH              MPEG4_DEC_MAX_WIDTH_SP
            #define MPEG4_DEC_MAX_HEIGHT             MPEG4_DEC_MAX_HEIGHT_SP
            #define MPEG4_EXTRA_BUFFER_NUM           MPEG4_EXTRA_BUFFER_NUM_SP

            #if 0  // Leroy
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif  // 0
        #endif

        // Compare working memory
        #if ((MPEG4_ASP_WORKING_MEM_SIZE_CACHE_LINE) > (MPEG4_SP_WORKING_MEM_SIZE_CACHE_LINE))
            #undef MPEG4_DEC_WORKING_MEM
            #define MPEG4_DEC_WORKING_MEM            MPEG4_ASP_WORKING_MEM_SIZE_CACHE_LINE
        #else
            #undef MPEG4_DEC_WORKING_MEM
            #define MPEG4_DEC_WORKING_MEM            MPEG4_SP_WORKING_MEM_SIZE_CACHE_LINE
        #endif

    #else  // #ifdef __MP4_DEC_SW_SUPPORT_ASP__

        #define MPEG4_FRM_BUFFER_SIZE               (MPEG4_SP_FRM_BUFFER_SIZE)
        #define MPEG4_ONE_FRM_BUFFER_SIZE           (MPEG4_SP_ONE_FRM_BUFFER_SIZE)
        #define MPEG4_FRM_BUFFER_WIDTH              (MPEG4_SP_FRM_BUFFER_WIDTH)
        #define MPEG4_FRM_BUFFER_HEIGHT             (MPEG4_SP_FRM_BUFFER_HEIGHT)

        #undef MPEG4_SUPPORT_RESOLUTION
        #undef MPEG4_MAX_NORMAL_MODE_RESOLUTION
        #undef MPEG4_DEC_MAX_WIDTH
        #undef MPEG4_DEC_MAX_HEIGHT
        #undef MPEG4_EXTRA_BUFFER_NUM
        #undef MPEG4_DEC_WORKING_MEM

        #define MPEG4_DEC_WORKING_MEM               MPEG4_SP_WORKING_MEM_SIZE_CACHE_LINE
        #define MPEG4_SUPPORT_RESOLUTION            MPEG4_SUPPORT_RESOLUTION_SP
        #define MPEG4_MAX_NORMAL_MODE_RESOLUTION    MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP
        #define MPEG4_DEC_MAX_WIDTH                 MPEG4_DEC_MAX_WIDTH_SP
        #define MPEG4_DEC_MAX_HEIGHT                MPEG4_DEC_MAX_HEIGHT_SP
        #define MPEG4_EXTRA_BUFFER_NUM              MPEG4_EXTRA_BUFFER_NUM_SP

        #if 0  // Leroy
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif  // 0
    #endif // #ifdef __MP4_DEC_SW_SUPPORT_ASP__
    // Comparision -

    // Decision +
    #if (MPEG4_ONE_FRM_BUFFER_SIZE > MAX_ONE_FRM_BUFFER_SIZE)
        #undef MAX_ONE_FRM_BUFFER_SIZE
        #undef MAX_FRM_BUFFER_WIDTH
        #undef MAX_FRM_BUFFER_HEIGHT
        #define MAX_ONE_FRM_BUFFER_SIZE     (MPEG4_ONE_FRM_BUFFER_SIZE)
        #define MAX_FRM_BUFFER_WIDTH        (MPEG4_FRM_BUFFER_WIDTH)
        #define MAX_FRM_BUFFER_HEIGHT       (MPEG4_FRM_BUFFER_HEIGHT)
    #endif

    #if ((MPEG4_FRM_BUFFER_SIZE + MPEG4_DEC_WORKING_MEM) > TEMP_TOTAL_MEM_SIZE)
        #undef TEMP_TOTAL_MEM_SIZE
        #undef FRM_BUFFER_SIZE
        #undef CODEC_WORKING_MEM_SIZE
        #define TEMP_TOTAL_MEM_SIZE     (MPEG4_FRM_BUFFER_SIZE + MPEG4_DEC_WORKING_MEM)
        #define FRM_BUFFER_SIZE         MPEG4_FRM_BUFFER_SIZE
        #define CODEC_WORKING_MEM_SIZE  MPEG4_DEC_WORKING_MEM

        #undef PLAYER_MAX_CONSUMPTION
        #ifdef __MP4_DEC_SW_SUPPORT_ASP__
            #if ( (MPEG4_ASP_FRM_BUFFER_SIZE_CACHE_LINE+MPEG4_ASP_WORKING_MEM_SIZE_CACHE_LINE) > (MPEG4_SP_FRM_BUFFER_SIZE_CACHE_LINE+MPEG4_SP_WORKING_MEM_SIZE_CACHE_LINE) )
                #define PLAYER_MAX_CONSUMPTION MPEG4_ASP_CODEC
            #else
                #define PLAYER_MAX_CONSUMPTION MPEG4_SP_CODEC
            #endif
        #else //__MP4_DEC_SW_SUPPORT_ASP__
            #define PLAYER_MAX_CONSUMPTION MPEG4_SP_CODEC
        #endif //__MP4_DEC_SW_SUPPORT_ASP__

    #endif
    // Decision -
#endif /*(defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))*/


#if (defined (__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    #if (H264_EXTRA_BUFFER_NUM_BP < 0)
        #error "Extra frame number of H264 decoder should be no bigger than or equal to 0"
    #endif

    // BP +
    #define H264_BP_DEC_MAX_HALF_WIDTH_ALIGN \
           ALIGN_X((H264_DEC_MAX_WIDTH_BP/2), 16)
    #define H264_BP_DEC_MAX_HALF_HEIGHT_ALIGN \
           ALIGN_X((H264_DEC_MAX_HEIGHT_BP/2), 16)

    #define H264_BP_FAST_MODE_BUFFER_SIZE ((H264_BP_DEC_MAX_HALF_WIDTH_ALIGN * H264_BP_DEC_MAX_HALF_HEIGHT_ALIGN * (H264_EXTRA_BUFFER_NUM_BP + DECODER_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE*2))
    #define H264_BP_NORMAL_BUFFER_SIZE (H264_DEC_MAX_NORMAL_WIDTH_BP * H264_DEC_MAX_NORMAL_HEIGHT_BP * (H264_EXTRA_BUFFER_NUM_BP + DECODER_ESSENTIAL_BUFFER_NUM) * 3 / 2 + (CPU_CACHE_LINE_SIZE_MINE*2))

    #if (H264_BP_FAST_MODE_BUFFER_SIZE > H264_BP_NORMAL_BUFFER_SIZE)
        #define H264_BP_FRM_BUFFER_SIZE (H264_BP_FAST_MODE_BUFFER_SIZE)
        #define H264_BP_3_FRM_SIZE    (3 * H264_BP_DEC_MAX_HALF_WIDTH_ALIGN * H264_BP_DEC_MAX_HALF_HEIGHT_ALIGN * 3 / 2)
        #define H264_BP_ONE_FRM_BUFFER_SIZE  (H264_BP_DEC_MAX_HALF_WIDTH_ALIGN * H264_BP_DEC_MAX_HALF_HEIGHT_ALIGN * 3 / 2)
        #define H264_BP_FRM_BUFFER_WIDTH  (H264_BP_DEC_MAX_HALF_WIDTH_ALIGN)
        #define H264_BP_FRM_BUFFER_HEIGHT  (H264_BP_DEC_MAX_HALF_HEIGHT_ALIGN)
    #else
        #define H264_BP_FRM_BUFFER_SIZE (H264_BP_NORMAL_BUFFER_SIZE)
        #define H264_BP_3_FRM_SIZE    (3 * H264_DEC_MAX_NORMAL_WIDTH_BP * H264_DEC_MAX_NORMAL_HEIGHT_BP * 3 / 2)
        #define H264_BP_ONE_FRM_BUFFER_SIZE  (H264_DEC_MAX_NORMAL_WIDTH_BP * H264_DEC_MAX_NORMAL_HEIGHT_BP * 3 / 2)
        #define H264_BP_FRM_BUFFER_WIDTH  (H264_DEC_MAX_NORMAL_WIDTH_BP)
        #define H264_BP_FRM_BUFFER_HEIGHT  (H264_DEC_MAX_NORMAL_HEIGHT_BP)
    #endif

    #if ((H264_EXTRA_BUFFER_NUM_BP + DECODER_ESSENTIAL_BUFFER_NUM) < 19)
		#if (defined(MT6260) || defined(MT6261)) && defined(__VE_H264_DEC_SW_SLIM__)
			#undef H264_DEC_DPB_SIZE_BP
			#define H264_DEC_DPB_SIZE_BP H264_BP_FRM_BUFFER_SIZE
		#else		
            #if ((H264_DEC_DPB_SIZE_BP + H264_BP_3_FRM_SIZE) > H264_BP_FRM_BUFFER_SIZE)
                #error "[H264 BP]Frame buffer size is smaller than the level specified. Please either increase the frame number or raise the level."
            #else
                #undef H264_DEC_DPB_SIZE_BP
                #define H264_DEC_DPB_SIZE_BP H264_BP_FRM_BUFFER_SIZE
            #endif
		#endif
    #else
        #undef H264_DEC_DPB_SIZE_BP
        #define H264_DEC_DPB_SIZE_BP H264_BP_FRM_BUFFER_SIZE
    #endif

    #define H264_BP_FRM_BUFFER_SIZE_CACHE_LINE \
            ALIGN_X((H264_BP_FRM_BUFFER_SIZE+GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define H264_BP_WORKING_MEM_SIZE_CACHE_LINE \
            ALIGN_X((H264_DEC_MAX_WORKING_MEM_BP+CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #define H264_BP_WORKING_MEM_SIZE_FINAL H264_BP_WORKING_MEM_SIZE_CACHE_LINE

    #if (H264_BP_ONE_FRM_BUFFER_SIZE > MAX_ONE_FRM_BUFFER_SIZE)
        #undef MAX_ONE_FRM_BUFFER_SIZE
        #undef MAX_FRM_BUFFER_WIDTH
        #undef MAX_FRM_BUFFER_HEIGHT
        #define MAX_ONE_FRM_BUFFER_SIZE (H264_BP_ONE_FRM_BUFFER_SIZE)
        #define MAX_FRM_BUFFER_WIDTH (H264_BP_FRM_BUFFER_WIDTH)
        #define MAX_FRM_BUFFER_HEIGHT (H264_BP_FRM_BUFFER_HEIGHT)
    #endif
    // BP -

    // MPHP +
    #ifdef __H264_DEC_SW_SUPPORT_MAINHIGH__
        #define H264_MPHP_DEC_MAX_HALF_WIDTH_ALIGN \
                ALIGN_X((H264_DEC_MAX_WIDTH_MPHP/2), 16)
        #define H264_MPHP_DEC_MAX_HALF_HEIGHT_ALIGN \
                ALIGN_X((H264_DEC_MAX_HEIGHT_MPHP/2), 16)

        #define H264_MPHP_FAST_MODE_BUFFER_SIZE ((H264_MPHP_DEC_MAX_HALF_WIDTH_ALIGN * H264_MPHP_DEC_MAX_HALF_HEIGHT_ALIGN * (H264_EXTRA_BUFFER_NUM_MPHP + DECODER_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE*2))
        #define H264_MPHP_NORMAL_BUFFER_SIZE (H264_DEC_MAX_NORMAL_WIDTH_MPHP * H264_DEC_MAX_NORMAL_HEIGHT_MPHP * (H264_EXTRA_BUFFER_NUM_MPHP + DECODER_ESSENTIAL_BUFFER_NUM) * 3 / 2 + (CPU_CACHE_LINE_SIZE_MINE*2))

        #if (H264_MPHP_FAST_MODE_BUFFER_SIZE > H264_MPHP_NORMAL_BUFFER_SIZE)
            #define H264_MPHP_FRM_BUFFER_SIZE (H264_MPHP_FAST_MODE_BUFFER_SIZE)
            #define H264_MPHP_3_FRM_SIZE    (3 * H264_MPHP_DEC_MAX_HALF_WIDTH_ALIGN * H264_MPHP_DEC_MAX_HALF_HEIGHT_ALIGN * 3 / 2)
            #define H264_MPHP_ONE_FRM_BUFFER_SIZE  (H264_MPHP_DEC_MAX_HALF_WIDTH_ALIGN * H264_MPHP_DEC_MAX_HALF_HEIGHT_ALIGN * 3 / 2)
            #define H264_MPHP_FRM_BUFFER_WIDTH  (H264_MPHP_DEC_MAX_HALF_WIDTH_ALIGN)
            #define H264_MPHP_FRM_BUFFER_HEIGHT  (H264_MPHP_DEC_MAX_HALF_HEIGHT_ALIGN)
        #else
            #define H264_MPHP_FRM_BUFFER_SIZE (H264_MPHP_NORMAL_BUFFER_SIZE)
            #define H264_MPHP_3_FRM_SIZE    (3 * H264_DEC_MAX_NORMAL_WIDTH_MPHP * H264_DEC_MAX_NORMAL_HEIGHT_MPHP * 3 / 2)
            #define H264_MPHP_ONE_FRM_BUFFER_SIZE  (H264_DEC_MAX_NORMAL_WIDTH_MPHP * H264_DEC_MAX_NORMAL_HEIGHT_MPHP * 3 / 2)
            #define H264_MPHP_FRM_BUFFER_WIDTH  (H264_DEC_MAX_NORMAL_WIDTH_MPHP)
            #define H264_MPHP_FRM_BUFFER_HEIGHT  (H264_DEC_MAX_NORMAL_HEIGHT_MPHP)
        #endif

        #if ((H264_EXTRA_BUFFER_NUM_MPHP + DECODER_ESSENTIAL_BUFFER_NUM) < 19)
            #if ((H264_DEC_DPB_SIZE_MPHP + H264_MPHP_3_FRM_SIZE) > H264_MPHP_FRM_BUFFER_SIZE)
                #error "[H264 MP/HP] Frame buffer size is smaller than the level specified. Please either increase the frame number or raise the level."
            #else
                #undef H264_DEC_DPB_SIZE_MPHP
                #define H264_DEC_DPB_SIZE_MPHP H264_MPHP_FRM_BUFFER_SIZE
            #endif
        #else
            #undef H264_DEC_DPB_SIZE_MPHP
            #define H264_DEC_DPB_SIZE_MPHP H264_MPHP_FRM_BUFFER_SIZE
        #endif

        #define H264_MPHP_FRM_BUFFER_SIZE_CACHE_LINE \
                ALIGN_X((H264_MPHP_FRM_BUFFER_SIZE+GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

        #define H264_MPHP_WORKING_MEM_SIZE_CACHE_LINE \
                ALIGN_X((H264_DEC_MAX_WORKING_MEM_MPHP+CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

        #define H264_MPHP_WORKING_MEM_SIZE_FINAL H264_MPHP_WORKING_MEM_SIZE_CACHE_LINE

        #if (H264_MPHP_ONE_FRM_BUFFER_SIZE > MAX_ONE_FRM_BUFFER_SIZE)
            #undef MAX_ONE_FRM_BUFFER_SIZE
            #undef MAX_FRM_BUFFER_WIDTH
            #undef MAX_FRM_BUFFER_HEIGHT
            #define MAX_ONE_FRM_BUFFER_SIZE (H264_MPHP_ONE_FRM_BUFFER_SIZE)
            #define MAX_FRM_BUFFER_WIDTH (H264_MPHP_FRM_BUFFER_WIDTH)
            #define MAX_FRM_BUFFER_HEIGHT (H264_MPHP_FRM_BUFFER_HEIGHT)
        #endif
    #endif  // #ifdef __H264_DEC_SW_SUPPORT_MAINHIGH__
    // MPHP -

    // Comparision +
    #ifdef __H264_DEC_SW_SUPPORT_MAINHIGH__
        // Compare frame buffer
        #if ( (H264_MPHP_FRM_BUFFER_SIZE_CACHE_LINE) > (H264_BP_FRM_BUFFER_SIZE_CACHE_LINE) )
            #define H264_FRM_BUFFER_SIZE (H264_MPHP_FRM_BUFFER_SIZE)
            #define H264_3_FRM_SIZE    (H264_MPHP_3_FRM_SIZE)
            #define H264_ONE_FRM_BUFFER_SIZE  (H264_MPHP_ONE_FRM_BUFFER_SIZE)
            #define H264_FRM_BUFFER_WIDTH  (H264_MPHP_FRM_BUFFER_WIDTH)
            #define H264_FRM_BUFFER_HEIGHT  (H264_MPHP_FRM_BUFFER_HEIGHT)

            #undef H264_SUPPORT_RESOLUTION
            #undef H264_MAX_NORMAL_MODE_RESOLUTION
            #undef H264_DECODER_LEVEL
            #undef H264_DEC_MAX_WIDTH
            #undef H264_DEC_MAX_HEIGHT
            #undef H264_DEC_DPB_SIZE
            #undef H264_FRM_BUFFER_SIZE
            #undef H264_EXTRA_BUFFER_NUM

            #define H264_SUPPORT_RESOLUTION         H264_SUPPORT_RESOLUTION_MPHP
            #define H264_MAX_NORMAL_MODE_RESOLUTION H264_MAX_NORMAL_MODE_RESOLUTION_MPHP
            #define H264_DECODER_LEVEL              H264_DECODER_LEVEL_MPHP
            #define H264_DEC_MAX_WIDTH              H264_DEC_MAX_WIDTH_MPHP
            #define H264_DEC_MAX_HEIGHT             H264_DEC_MAX_HEIGHT_MPHP
            #define H264_DEC_DPB_SIZE               H264_DEC_DPB_SIZE_MPHP
            #define H264_FRM_BUFFER_SIZE            H264_MPHP_FRM_BUFFER_SIZE
            #define H264_EXTRA_BUFFER_NUM           H264_EXTRA_BUFFER_NUM_MPHP

            #define H264_DEC_MAX_HALF_WIDTH_ALIGN   H264_MPHP_DEC_MAX_HALF_WIDTH_ALIGN
            #define H264_DEC_MAX_HALF_HEIGHT_ALIGN  H264_MPHP_DEC_MAX_HALF_HEIGHT_ALIGN

            #define H264_DEC_MAX_NORMAL_WIDTH       H264_DEC_MAX_NORMAL_WIDTH_MPHP
            #define H264_DEC_MAX_NORMAL_HEIGHT      H264_DEC_MAX_NORMAL_HEIGHT_MPHP
        #else
            #define H264_FRM_BUFFER_SIZE (H264_BP_FRM_BUFFER_SIZE)
            #define H264_3_FRM_SIZE    (H264_BP_3_FRM_SIZE)
            #define H264_ONE_FRM_BUFFER_SIZE  (H264_BP_ONE_FRM_BUFFER_SIZE)
            #define H264_FRM_BUFFER_WIDTH  (H264_BP_FRM_BUFFER_WIDTH)
            #define H264_FRM_BUFFER_HEIGHT  (H264_BP_FRM_BUFFER_HEIGHT)

            #undef H264_SUPPORT_RESOLUTION
            #undef H264_MAX_NORMAL_MODE_RESOLUTION
            #undef H264_DECODER_LEVEL
            #undef H264_DEC_MAX_WIDTH
            #undef H264_DEC_MAX_HEIGHT
            #undef H264_DEC_DPB_SIZE
            #undef H264_FRM_BUFFER_SIZE
            #undef H264_EXTRA_BUFFER_NUM

            #define H264_SUPPORT_RESOLUTION         H264_SUPPORT_RESOLUTION_BP
            #define H264_MAX_NORMAL_MODE_RESOLUTION H264_MAX_NORMAL_MODE_RESOLUTION_BP
            #define H264_DECODER_LEVEL              H264_DECODER_LEVEL_BP
            #define H264_DEC_MAX_WIDTH              H264_DEC_MAX_WIDTH_BP
            #define H264_DEC_MAX_HEIGHT             H264_DEC_MAX_HEIGHT_BP
            #define H264_DEC_DPB_SIZE               H264_DEC_DPB_SIZE_BP
            #define H264_FRM_BUFFER_SIZE            H264_BP_FRM_BUFFER_SIZE
            #define H264_EXTRA_BUFFER_NUM           H264_EXTRA_BUFFER_NUM_BP

            #define H264_DEC_MAX_HALF_WIDTH_ALIGN   H264_BP_DEC_MAX_HALF_WIDTH_ALIGN
            #define H264_DEC_MAX_HALF_HEIGHT_ALIGN   H264_BP_DEC_MAX_HALF_HEIGHT_ALIGN

            #define H264_DEC_MAX_NORMAL_WIDTH       H264_DEC_MAX_NORMAL_WIDTH_BP
            #define H264_DEC_MAX_NORMAL_HEIGHT      H264_DEC_MAX_NORMAL_HEIGHT_BP
        #endif

        // Compare working memory
        #if ( (H264_MPHP_WORKING_MEM_SIZE_CACHE_LINE) > (H264_BP_WORKING_MEM_SIZE_CACHE_LINE) )
            #undef H264_DEC_WORKING_MEM
            #define H264_DEC_WORKING_MEM            H264_MPHP_WORKING_MEM_SIZE_CACHE_LINE
        #else
            #undef H264_DEC_WORKING_MEM
            #define H264_DEC_WORKING_MEM            H264_BP_WORKING_MEM_SIZE_CACHE_LINE
        #endif

    #else  // #ifdef __H264_DEC_SW_SUPPORT_MAINHIGH__

        /* Leroy: The following lines may contain redundant code. */
        #define H264_FRM_BUFFER_SIZE (H264_BP_FRM_BUFFER_SIZE)
        #define H264_3_FRM_SIZE    (H264_BP_3_FRM_SIZE)
        #define H264_ONE_FRM_BUFFER_SIZE  (H264_BP_ONE_FRM_BUFFER_SIZE)
        #define H264_FRM_BUFFER_WIDTH  (H264_BP_FRM_BUFFER_WIDTH)
        #define H264_FRM_BUFFER_HEIGHT  (H264_BP_FRM_BUFFER_HEIGHT)

        #undef H264_SUPPORT_RESOLUTION
        #undef H264_MAX_NORMAL_MODE_RESOLUTION
        #undef H264_DECODER_LEVEL
        #undef H264_DEC_MAX_WIDTH
        #undef H264_DEC_MAX_HEIGHT
        #undef H264_DEC_WORKING_MEM
        #undef H264_DEC_DPB_SIZE
        #undef H264_FRM_BUFFER_SIZE
        #undef H264_EXTRA_BUFFER_NUM

        #define H264_SUPPORT_RESOLUTION         H264_SUPPORT_RESOLUTION_BP
        #define H264_MAX_NORMAL_MODE_RESOLUTION H264_MAX_NORMAL_MODE_RESOLUTION_BP
        #define H264_DECODER_LEVEL              H264_DECODER_LEVEL_BP
        #define H264_DEC_MAX_WIDTH              H264_DEC_MAX_WIDTH_BP
        #define H264_DEC_MAX_HEIGHT             H264_DEC_MAX_HEIGHT_BP
        #define H264_DEC_WORKING_MEM            H264_BP_WORKING_MEM_SIZE_CACHE_LINE
        #define H264_DEC_DPB_SIZE               H264_DEC_DPB_SIZE_BP
        #define H264_FRM_BUFFER_SIZE            H264_BP_FRM_BUFFER_SIZE
        #define H264_EXTRA_BUFFER_NUM           H264_EXTRA_BUFFER_NUM_BP

        #define H264_DEC_MAX_HALF_WIDTH_ALIGN   H264_BP_DEC_MAX_HALF_WIDTH_ALIGN
        #define H264_DEC_MAX_HALF_HEIGHT_ALIGN   H264_BP_DEC_MAX_HALF_HEIGHT_ALIGN

        #define H264_DEC_MAX_NORMAL_WIDTH       H264_DEC_MAX_NORMAL_WIDTH_BP
        #define H264_DEC_MAX_NORMAL_HEIGHT      H264_DEC_MAX_NORMAL_HEIGHT_BP

    #endif  // #ifdef __H264_DEC_SW_SUPPORT_MAINHIGH__
    // Comparision -

    // Decision +
    #if ( (H264_FRM_BUFFER_SIZE+H264_DEC_WORKING_MEM) > TEMP_TOTAL_MEM_SIZE)
        #undef TEMP_TOTAL_MEM_SIZE
        #undef FRM_BUFFER_SIZE
        #undef CODEC_WORKING_MEM_SIZE
        #define TEMP_TOTAL_MEM_SIZE (H264_FRM_BUFFER_SIZE+H264_DEC_WORKING_MEM)
        #define FRM_BUFFER_SIZE H264_FRM_BUFFER_SIZE
        #define CODEC_WORKING_MEM_SIZE H264_DEC_WORKING_MEM

        #undef PLAYER_MAX_CONSUMPTION
        #ifdef __H264_DEC_SW_SUPPORT_MAINHIGH__
            #if ( (H264_MPHP_FRM_BUFFER_SIZE_CACHE_LINE+H264_MPHP_WORKING_MEM_SIZE_CACHE_LINE) > (H264_BP_FRM_BUFFER_SIZE_CACHE_LINE+H264_BP_WORKING_MEM_SIZE_CACHE_LINE) )
                #define PLAYER_MAX_CONSUMPTION H264_MPHP_CODEC
            #else
                #define PLAYER_MAX_CONSUMPTION H264_BP_CODEC
            #endif
        #else //__H264_DEC_SW_SUPPORT_MAINHIGH__
            #define PLAYER_MAX_CONSUMPTION H264_BP_CODEC
        #endif //__H264_DEC_SW_SUPPORT_MAINHIGH__
    #endif
    // Decision -
#endif  /* #if (defined (__VE_H264_DEC_SW_SUPPORT__) || (__VE_H264_DEC_HW_SUPPORT__)) */


#ifdef __VE_RV_DEC_SW_SUPPORT__
    #if (RV9_EXTRA_BUFFER_NUM < 0)
    #error "Extra frame number of RV decoder should be no bigger than or equal to 0"
    #endif

    #define RV9_DEC_MAX_HALF_WIDTH_ALIGN \
           ALIGN_X((RV9_DEC_MAX_WIDTH/2), 16)
    #define RV9_DEC_MAX_HALF_HEIGHT_ALIGN \
           ALIGN_X((RV9_DEC_MAX_HEIGHT/2), 16)

    #define RV9_FAST_MODE_BUFFER_SIZE ((RV9_DEC_MAX_HALF_WIDTH_ALIGN * RV9_DEC_MAX_HALF_HEIGHT_ALIGN * (RV9_EXTRA_BUFFER_NUM + RM_DECODER_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (2*16*RV9_DEC_MAX_HALF_WIDTH_ALIGN) + (CPU_CACHE_LINE_SIZE_MINE*2))
    #define RV9_NORMAL_BUFFER_SIZE (((RV9_DEC_MAX_NORMAL_WIDTH) * (RV9_DEC_MAX_NORMAL_HEIGHT) * (RV9_EXTRA_BUFFER_NUM + RM_DECODER_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (2*16*RV9_DEC_MAX_NORMAL_WIDTH) + (CPU_CACHE_LINE_SIZE_MINE*2))

    #if (RV9_FAST_MODE_BUFFER_SIZE > RV9_NORMAL_BUFFER_SIZE)
        #define RV9_FRM_BUFFER_SIZE (RV9_FAST_MODE_BUFFER_SIZE)
        #define RV9_ONE_FRM_BUFFER_SIZE  (RV9_DEC_MAX_HALF_WIDTH_ALIGN * RV9_DEC_MAX_HALF_HEIGHT_ALIGN * 3 / 2)
        #define RV9_FRM_BUFFER_WIDTH  (RV9_DEC_MAX_HALF_WIDTH_ALIGN)
        #define RV9_FRM_BUFFER_HEIGHT  (RV9_DEC_MAX_HALF_HEIGHT_ALIGN)
    #else
        #define RV9_FRM_BUFFER_SIZE (RV9_NORMAL_BUFFER_SIZE)
        #define RV9_ONE_FRM_BUFFER_SIZE  (RV9_DEC_MAX_NORMAL_WIDTH * RV9_DEC_MAX_NORMAL_HEIGHT * 3 / 2)
        #define RV9_FRM_BUFFER_WIDTH  (RV9_DEC_MAX_NORMAL_WIDTH)
        #define RV9_FRM_BUFFER_HEIGHT  (RV9_DEC_MAX_NORMAL_HEIGHT)
    #endif

    #define RV9_FRM_BUFFER_SIZE_CACHE_LINE \
            ALIGN_X((RV9_FRM_BUFFER_SIZE+GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define RV9_WORKING_MEM_SIZE_CACHE_LINE \
            ALIGN_X((RV9_DEC_WORKING_MEM+CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #define RV9_WORKING_MEM_SIZE_FINAL RV9_WORKING_MEM_SIZE_CACHE_LINE

    #if ((RV9_FRM_BUFFER_SIZE_CACHE_LINE + RV9_WORKING_MEM_SIZE_CACHE_LINE) > TEMP_TOTAL_MEM_SIZE)
        #undef TEMP_TOTAL_MEM_SIZE
        #undef FRM_BUFFER_SIZE
        #undef CODEC_WORKING_MEM_SIZE
        #define TEMP_TOTAL_MEM_SIZE (RV9_FRM_BUFFER_SIZE_CACHE_LINE + RV9_WORKING_MEM_SIZE_CACHE_LINE)
        #define FRM_BUFFER_SIZE RV9_FRM_BUFFER_SIZE_CACHE_LINE
        #define CODEC_WORKING_MEM_SIZE RV9_WORKING_MEM_SIZE_CACHE_LINE

        #undef PLAYER_MAX_CONSUMPTION
        #define PLAYER_MAX_CONSUMPTION RV_CODEC
    #endif

    #if (RV9_ONE_FRM_BUFFER_SIZE > MAX_ONE_FRM_BUFFER_SIZE)
        #undef MAX_ONE_FRM_BUFFER_SIZE
        #undef MAX_FRM_BUFFER_WIDTH
        #undef MAX_FRM_BUFFER_HEIGHT
        #define MAX_ONE_FRM_BUFFER_SIZE (RV9_ONE_FRM_BUFFER_SIZE)
        #define MAX_FRM_BUFFER_WIDTH (RV9_FRM_BUFFER_WIDTH)
        #define MAX_FRM_BUFFER_HEIGHT (RV9_FRM_BUFFER_HEIGHT)
    #endif
#endif  /* __VE_RV_DEC_SW_SUPPORT__ */


#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
    #define MJPEG_DEC_MAX_QUARTER_WIDTH_ALIGN ALIGN_X((MJPEG_DEC_MAX_WIDTH/4), 16)
    #define MJPEG_DEC_MAX_QUARTER_HEIGHT_ALIGN ALIGN_X((MJPEG_DEC_MAX_HEIGHT/4), 16)

    #define MJPEG_DEC_MAX_HALF_WIDTH_ALIGN ALIGN_X((MJPEG_DEC_MAX_QTY_WIDTH/2), 16)
    #define MJPEG_DEC_MAX_HALF_HEIGHT_ALIGN ALIGN_X((MJPEG_DEC_MAX_QTY_HEIGHT/2), 16)

    #define MJPEG_FAST_MODE_BUFFER_SIZE ((MJPEG_DEC_MAX_QUARTER_WIDTH_ALIGN * MJPEG_DEC_MAX_QUARTER_HEIGHT_ALIGN * (MJPEG_EXTRA_BUFFER_NUM + DECODER_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE*2))
    #define MJPEG_QTY_MODE_BUFFER_SIZE ((MJPEG_DEC_MAX_HALF_WIDTH_ALIGN * MJPEG_DEC_MAX_HALF_HEIGHT_ALIGN * (MJPEG_EXTRA_BUFFER_NUM + DECODER_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE*2))
    #define MJPEG_NORMAL_BUFFER_SIZE (((MJPEG_DEC_MAX_NORMAL_WIDTH) * (MJPEG_DEC_MAX_NORMAL_HEIGHT) * (MJPEG_EXTRA_BUFFER_NUM + DECODER_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE*2))

    #if (MJPEG_NORMAL_BUFFER_SIZE > MJPEG_QTY_MODE_BUFFER_SIZE)
        #define MJPEG_FRM_BUFFER_SIZE (MJPEG_NORMAL_BUFFER_SIZE)
        #define MJPEG_ONE_FRM_BUFFER_SIZE  (MJPEG_DEC_MAX_NORMAL_WIDTH * MJPEG_DEC_MAX_NORMAL_HEIGHT * 3 / 2)
        #define MJPEG_FRM_BUFFER_WIDTH  (MJPEG_DEC_MAX_NORMAL_WIDTH)
        #define MJPEG_FRM_BUFFER_HEIGHT  (MJPEG_DEC_MAX_NORMAL_HEIGHT)
    #else
        #define MJPEG_FRM_BUFFER_SIZE (MJPEG_QTY_MODE_BUFFER_SIZE)
        #define MJPEG_ONE_FRM_BUFFER_SIZE  (MJPEG_DEC_MAX_HALF_WIDTH_ALIGN * MJPEG_DEC_MAX_HALF_HEIGHT_ALIGN * 3 / 2)
        #define MJPEG_FRM_BUFFER_WIDTH  (MJPEG_DEC_MAX_HALF_WIDTH_ALIGN)
        #define MJPEG_FRM_BUFFER_HEIGHT  (MJPEG_DEC_MAX_HALF_HEIGHT_ALIGN)
    #endif

    #if (MJPEG_FAST_MODE_BUFFER_SIZE > MJPEG_FRM_BUFFER_SIZE)
        #define MJPEG_FRM_BUFFER_SIZE (MJPEG_FAST_MODE_BUFFER_SIZE)
        #define MJPEG_ONE_FRM_BUFFER_SIZE  (MJPEG_DEC_MAX_QUARTER_WIDTH_ALIGN * MJPEG_DEC_MAX_QUARTER_HEIGHT_ALIGN * 3 / 2)
        #define MJPEG_FRM_BUFFER_WIDTH  (MJPEG_DEC_MAX_QUARTER_WIDTH_ALIGN)
        #define MJPEG_FRM_BUFFER_HEIGHT  (MJPEG_DEC_MAX_QUARTER_HEIGHT_ALIGN)
    #endif


    #define MJPEG_FRM_BUFFER_SIZE_CACHE_LINE ALIGN_X((MJPEG_FRM_BUFFER_SIZE+GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define MJPEG_WORKING_MEM_SIZE_CACHE_LINE ALIGN_X((MJPEG_DEC_WORKING_MEM+CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)


    #if ((MJPEG_FRM_BUFFER_SIZE_CACHE_LINE + MJPEG_WORKING_MEM_SIZE_CACHE_LINE) > TEMP_TOTAL_MEM_SIZE)
        #undef TEMP_TOTAL_MEM_SIZE
        #undef FRM_BUFFER_SIZE
        #undef CODEC_WORKING_MEM_SIZE
        #define TEMP_TOTAL_MEM_SIZE (MJPEG_FRM_BUFFER_SIZE_CACHE_LINE+MJPEG_WORKING_MEM_SIZE_CACHE_LINE)
        #define FRM_BUFFER_SIZE MJPEG_FRM_BUFFER_SIZE_CACHE_LINE
        #define CODEC_WORKING_MEM_SIZE MJPEG_WORKING_MEM_SIZE_CACHE_LINE

        #undef PLAYER_MAX_CONSUMPTION
        #define PLAYER_MAX_CONSUMPTION MJPG_CODEC
    #endif

    #if (MJPEG_ONE_FRM_BUFFER_SIZE > MAX_ONE_FRM_BUFFER_SIZE)
        #undef MAX_ONE_FRM_BUFFER_SIZE
        #undef MAX_FRM_BUFFER_WIDTH
        #undef MAX_FRM_BUFFER_HEIGHT
        #define MAX_ONE_FRM_BUFFER_SIZE (MJPEG_ONE_FRM_BUFFER_SIZE)
        #define MAX_FRM_BUFFER_WIDTH (MJPEG_FRM_BUFFER_WIDTH)
        #define MAX_FRM_BUFFER_HEIGHT (MJPEG_FRM_BUFFER_HEIGHT)
    #endif
#endif  /* __VE_MJPEG_DEC_SW_SUPPORT__ */


#ifdef __VE_VP8_DEC_SW_SUPPORT__
    #if (VP8_EXTRA_BUFFER_NUM < 0)
    #error "Extra frame number of VP8 decoder should be no bigger than or equal to 0"
    #endif

    #define VP8_DEC_MAX_HALF_WIDTH_ALIGN ALIGN_X((VP8_DEC_MAX_WIDTH/2), 16)
    #define VP8_DEC_MAX_HALF_HEIGHT_ALIGN ALIGN_X((VP8_DEC_MAX_HEIGHT/2), 16)

    #define VP8_FAST_MODE_BUFFER_SIZE ((ALIGN_X((VP8_DEC_MAX_HALF_WIDTH_ALIGN+VP8_PADDING_SIZE), 32)* ALIGN_X((VP8_DEC_MAX_HALF_HEIGHT_ALIGN+VP8_PADDING_SIZE), 32) * (VP8_EXTRA_BUFFER_NUM + VP8_DECODER_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE*2))
    #define VP8_NORMAL_BUFFER_SIZE ((ALIGN_X((VP8_DEC_MAX_NORMAL_WIDTH+VP8_PADDING_SIZE), 32) * ALIGN_X((VP8_DEC_MAX_NORMAL_HEIGHT+VP8_PADDING_SIZE), 32) * (VP8_EXTRA_BUFFER_NUM + VP8_DECODER_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE*2))

    #if (VP8_FAST_MODE_BUFFER_SIZE > VP8_NORMAL_BUFFER_SIZE)
        #define VP8_FRM_BUFFER_SIZE (VP8_FAST_MODE_BUFFER_SIZE)
        #define VP8_ONE_FRM_BUFFER_SIZE  (ALIGN_X((VP8_DEC_MAX_HALF_WIDTH_ALIGN+VP8_PADDING_SIZE), 32)* ALIGN_X((VP8_DEC_MAX_HALF_HEIGHT_ALIGN+VP8_PADDING_SIZE), 32) * 3 / 2)
        #define VP8_FRM_BUFFER_WIDTH  ALIGN_X((VP8_DEC_MAX_HALF_WIDTH_ALIGN+VP8_PADDING_SIZE), 32)
        #define VP8_FRM_BUFFER_HEIGHT  ALIGN_X((VP8_DEC_MAX_HALF_HEIGHT_ALIGN+VP8_PADDING_SIZE), 32)
    #else
        #define VP8_FRM_BUFFER_SIZE (VP8_NORMAL_BUFFER_SIZE)
        #define VP8_ONE_FRM_BUFFER_SIZE  (ALIGN_X((VP8_DEC_MAX_NORMAL_WIDTH+VP8_PADDING_SIZE), 32) * ALIGN_X((VP8_DEC_MAX_NORMAL_HEIGHT+VP8_PADDING_SIZE), 32) * 3 / 2)
        #define VP8_FRM_BUFFER_WIDTH  ALIGN_X((VP8_DEC_MAX_NORMAL_WIDTH+VP8_PADDING_SIZE), 32)
        #define VP8_FRM_BUFFER_HEIGHT  ALIGN_X((VP8_DEC_MAX_NORMAL_HEIGHT+VP8_PADDING_SIZE), 32)
    #endif

    #define VP8_FRM_BUFFER_SIZE_CACHE_LINE ALIGN_X((VP8_FRM_BUFFER_SIZE+GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define VP8_WORKING_MEM_SIZE_CACHE_LINE ALIGN_X((VP8_DEC_WORKING_MEM+CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ( (VP8_FRM_BUFFER_SIZE_CACHE_LINE+VP8_WORKING_MEM_SIZE_CACHE_LINE) > TEMP_TOTAL_MEM_SIZE)
        #undef TEMP_TOTAL_MEM_SIZE
        #undef FRM_BUFFER_SIZE
        #undef CODEC_WORKING_MEM_SIZE
        #define TEMP_TOTAL_MEM_SIZE (VP8_FRM_BUFFER_SIZE_CACHE_LINE+VP8_WORKING_MEM_SIZE_CACHE_LINE)
        #define FRM_BUFFER_SIZE VP8_FRM_BUFFER_SIZE_CACHE_LINE
        #define CODEC_WORKING_MEM_SIZE VP8_WORKING_MEM_SIZE_CACHE_LINE

        #undef PLAYER_MAX_CONSUMPTION
        #define PLAYER_MAX_CONSUMPTION VP8_CODEC
    #endif

    #if (VP8_ONE_FRM_BUFFER_SIZE > MAX_ONE_FRM_BUFFER_SIZE)
        #undef MAX_ONE_FRM_BUFFER_SIZE
        #undef MAX_FRM_BUFFER_WIDTH
        #undef MAX_FRM_BUFFER_HEIGHT
        #define MAX_ONE_FRM_BUFFER_SIZE (VP8_ONE_FRM_BUFFER_SIZE)
        #define MAX_FRM_BUFFER_WIDTH (VP8_FRM_BUFFER_WIDTH)
        #define MAX_FRM_BUFFER_HEIGHT (VP8_FRM_BUFFER_HEIGHT)
    #endif
#endif  /* __VE_VP8_DEC_SW_SUPPORT__ */


#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__) || defined (__VE_H264_DEC_SW_SUPPORT__) \
       || defined(__VE_H264_DEC_HW_SUPPORT__) || defined(__VE_RV_DEC_SW_SUPPORT__) || defined(__VE_MJPEG_DEC_SW_SUPPORT__) \
       || defined(__VE_VP8_DEC_SW_SUPPORT__))

    #if (FRM_BUFFER_SIZE == 0)
        #error "Cannot decide the size of frame buffer, no codec is enable"
    #endif
#endif


/*******************************************************
*
*   Decide the working memory of video decoder component
*
*******************************************************/
#define COMMAND_SIZE        (8)
#define BUFFERHEADER_SIZE   (40)
#define INFO_MEM_SIZE       (5272)//(5120)


#define VIDEO_DECODER_MAX_YUV_BUF_NUM           (32)
#define VIDEO_DECODER_INPUT_BUFFER_Q_LEN        (10)
#define VIDEO_DECODER_OUTPUTPUT_BUFFER_Q_LEN    (10)
#define VIDEO_DECODER_COMMAND_Q_LEN             (10)
#define VIDEO_DECODER_RESEND_Q_NUM              (10)
#define VIDEO_DECODER_RETURN_BS_BUFFER_Q_NUM    (VIDEO_DECODER_RESEND_Q_NUM + 1)
#define VIDEO_DECODER_MGR_LEN                   (2048)
#define VIDEO_FLUENCY_MGR_LEN                   (1024)

#ifdef __VE_KMV_SUPPORT__
    #define VIDEO_DECODER_KMV_META_LEN              (6528) //(408*16)
    #define VIDEO_KMV_SW_SCALER_UP_BUFFER           (3840) //(320x6x2)
#else
    #define VIDEO_DECODER_KMV_META_LEN              (0)
    #define VIDEO_KMV_SW_SCALER_UP_BUFFER           (0)
#endif

#define VIDEO_INPUT_QUEUE_SIZE_ALIGN_CACHE_LINE  \
            ALIGN_X((VIDEO_DECODER_INPUT_BUFFER_Q_LEN * BUFFERHEADER_SIZE), CPU_CACHE_LINE_SIZE_MINE)
#define VIDEO_OUTPUT_QUEUE_SIZE_ALIGN_CACHE_LINE \
            ALIGN_X((VIDEO_DECODER_OUTPUTPUT_BUFFER_Q_LEN * BUFFERHEADER_SIZE), CPU_CACHE_LINE_SIZE_MINE)
#define VIDEO_COMMAND_QUEUE_SIZE_ALIGN_CACHE_LINE \
            ALIGN_X((VIDEO_DECODER_COMMAND_Q_LEN * COMMAND_SIZE), CPU_CACHE_LINE_SIZE_MINE)
#define VIDEO_INFO_MEM_SIZE_ALIGN_CACHE_LINE \
            ALIGN_X(INFO_MEM_SIZE, CPU_CACHE_LINE_SIZE_MINE)

#define VIDEO_DECODER_MGR_SIZE_ALIGN_CACHE_LINE ALIGN_X(VIDEO_DECODER_MGR_LEN + GUARD_PATTERN_LENGTH, CPU_CACHE_LINE_SIZE_MINE)
#define VIDEO_FLUENCY_MGR_SIZE_ALIGN_CACHE_LINE ALIGN_X(VIDEO_FLUENCY_MGR_LEN + GUARD_PATTERN_LENGTH, CPU_CACHE_LINE_SIZE_MINE)

#define VIDEO_DECODER_KMV_META_SIZE_ALIGN_CACHE_LINE ALIGN_X(VIDEO_DECODER_KMV_META_LEN + GUARD_PATTERN_LENGTH, CPU_CACHE_LINE_SIZE_MINE)
#define VIDEO_DECODER_KMV_SCALER_UP_BUFFER_SIZE_ALIGN_CACHE_LINE ALIGN_X(VIDEO_KMV_SW_SCALER_UP_BUFFER + GUARD_PATTERN_LENGTH, CPU_CACHE_LINE_SIZE_MINE)

#define VIDEO_DEC_WORKING_MEM_SIZE (VIDEO_INPUT_QUEUE_SIZE_ALIGN_CACHE_LINE+ \
                                    VIDEO_OUTPUT_QUEUE_SIZE_ALIGN_CACHE_LINE + \
                                    VIDEO_COMMAND_QUEUE_SIZE_ALIGN_CACHE_LINE + \
                                    VIDEO_INFO_MEM_SIZE_ALIGN_CACHE_LINE + \
                                    VIDEO_DECODER_MGR_SIZE_ALIGN_CACHE_LINE + \
                                    VIDEO_DECODER_KMV_META_SIZE_ALIGN_CACHE_LINE + \
                                    VIDEO_DECODER_KMV_SCALER_UP_BUFFER_SIZE_ALIGN_CACHE_LINE + \
                                    VIDEO_FLUENCY_MGR_SIZE_ALIGN_CACHE_LINE)


/*******************************************************
*
*   Decide the total external memory needed by
*   decoder component
*
*******************************************************/

#define DECODER_MEM_SIZE (FRM_BUFFER_SIZE + VIDEO_EXTRA_MEM_SIZE + VIDEO_DEC_WORKING_MEM_SIZE + CODEC_WORKING_MEM_SIZE)


/******************************************************************************
* Decide the max memory for Video Live Wallpaper
******************************************************************************/

#define DECODER_MPEG4_MEM_SIZE (MPEG4_FRM_BUFFER_SIZE + VIDEO_EXTRA_MEM_SIZE + VIDEO_DEC_WORKING_MEM_SIZE + MPEG4_DEC_WORKING_MEM)
#define DECODER_MJPG_MEM_SIZE (MJPEG_FRM_BUFFER_SIZE_CACHE_LINE + VIDEO_EXTRA_MEM_SIZE + VIDEO_DEC_WORKING_MEM_SIZE + MJPEG_WORKING_MEM_SIZE_CACHE_LINE)

#if (DECODER_MPEG4_MEM_SIZE > DECODER_MJPG_MEM_SIZE)
    #define DECODER_VLW_MEM_SIZE DECODER_MPEG4_MEM_SIZE
#else
    #define DECODER_VLW_MEM_SIZE DECODER_MJPG_MEM_SIZE
#endif


/******************************************************************************
* Definitions for recorder audio buffer.
******************************************************************************/
#ifdef __VE_AVI_ENC_SUPPORT__
#define MPLVR_AVI_AUDIO_BUFFER_SIZE         (16 << 10)      /* 16 KB */
#else
#define MPLVR_AVI_AUDIO_BUFFER_SIZE         (0)
#endif  // __VE_AVI_ENC_SUPPORT__

#ifdef __VE_MPEG4_ENC_SUPPORT__
#define MPLVR_MP4_AUDIO_BUFFER_SIZE         (32 << 10)      /* 32 KB */
#else
#define MPLVR_MP4_AUDIO_BUFFER_SIZE         (0)
#endif  // __VE_MPEG4_ENC_SUPPORT__

#if (MPLVR_AVI_AUDIO_BUFFER_SIZE > MPLVR_MP4_AUDIO_BUFFER_SIZE)
#define MPLVR_AUDIO_BUFFER_SIZE MPLVR_AVI_AUDIO_BUFFER_SIZE
#else
#define MPLVR_AUDIO_BUFFER_SIZE MPLVR_MP4_AUDIO_BUFFER_SIZE
#endif  // (MPLVR_AVI_AUDIO_BUFFER_SIZE > MPLVR_MP4_AUDIO_BUFFER_SIZE)


/******************************************************************************
* Definitions for MPEG-4 encoder
******************************************************************************/
#define CPU_CACHE_LINE_SIZE_REC             (32)

#ifdef __VE_VIDEO_VT_SUPPORT__
    #define VENC_SIZE_PER_CHASSIS      810
    #define VENC_MAX_CHASSIS_NUM_X     33
#else
    #define VENC_SIZE_PER_CHASSIS      0
    #define VENC_MAX_CHASSIS_NUM_X     0
#endif  // __VE_VIDEO_VT_SUPPORT__


#define VENC_COMP_CMD_Q_SIZE            (VIDEO_COMM_COMMAND_Q_ITEM_SIZE *   \
                                         VENC_COMMAND_Q_NUM)

#define VENC_COMP_INPUT_Q_SIZE          (VIDEO_COMM_INPUT_Q_ITEM_SIZE *     \
                                         VIDEO_ENCODER_INPUT_BUFFER_Q_NUM)

#define VENC_COMP_OUTPUT_Q_SIZE         (VIDEO_COMM_OUTPUT_Q_ITEM_SIZE *    \
                                         VENC_OUTPUT_BUFFER_Q_NUM)

#define VENC_COMP_ALL_Q_SIZE            (VENC_COMP_CMD_Q_SIZE +           \
                                         VENC_COMP_INPUT_Q_SIZE +         \
                                         VENC_COMP_OUTPUT_Q_SIZE +        \
                                         (CPU_CACHE_LINE_SIZE_REC * 3))

#define VENC_YUV_HEADER_Q_SIZE          (VENC_YUV_HEADER_Q_ITEM_SIZE * \
                                         VIDEO_ENCODER_YUV_HEADER_Q_NUM)

#define VENC_TIME_STAMP_Q_SIZE          (VENC_TIME_STAMP_Q_ITEM_SIZE * \
                                         VENC_TIME_STAMP_Q_NUM)

#define VENC_RESEND_Q_SIZE              (VIDEO_ENCODER_RESEND_Q_NUM * VENC_YUV_HEADER_Q_ITEM_SIZE)

#define VENC_WORKING_MEM_ADM_OVERHEAD    512
#define VENC_EXTRA_OVERHEAD              1024

#define VENC_FW_EXT_MEM_SIZE        0
#define VENC_FRM_BUFFER_MEM_SIZE    0
#define VENC_CODEC_WORKING_MEM_SIZE 0
#define VENC_BITSTREAM_MEM_SIZE     0
#define VENC_BITSTREAM_HEADER_MEM_SIZE  (512)

#define VENC_FRM_BUFFER_CIF_MEM_SIZE    0
#define VENC_CIF_WIDTH      352
#define VENC_CIF_HEIGHT     288

#define VENC_YUV_BUFFER_SIZE_CAL(u4Width, u4Height, u4FrmNum)   \
        (((u4Width * u4Height * 3 / 2) +                        \
          CPU_CACHE_LINE_SIZE_REC) * u4FrmNum)


#if defined(__VE_MJPEG_ENC_BYPASS__)
    #if !defined(MJPEG_HW_ENC_CUSTOM_FRAME_SETTING_ENABLE)
        #define DIRECTCOUPLE_BISTREAM_NUM                   (4)
        #define DIRECTCOUPLD_ONE_BITSTREAM_SIZE             (JPEG_ENC_MJPEG_DST_MAX_MEM_SIZE_WITH_QUALITY_GOOD)
    #else
        #define DIRECTCOUPLE_BISTREAM_NUM                   (4 + MJPEG_HW_ENC_CUSTOM_EXTRA_BITSTREAM_BUFFER_NUM)
        #define DIRECTCOUPLD_ONE_BITSTREAM_SIZE             (JPEG_ENC_MJPEG_DST_MAX_MEM_SIZE_WITH_QUALITY_GOOD + MJPEG_HW_ENC_CUSTOM_EXTRA_BITSTREAM)
    #endif
    #define DIRECTCOUPLE_ONE_BISTREAM_ALIGHED_SIZE      (DIRECTCOUPLD_ONE_BITSTREAM_SIZE + 4)
    #define VENC_COMP_DIRECTCOUPLE_BITSTREAM_SIZE       (DIRECTCOUPLE_BISTREAM_NUM* DIRECTCOUPLE_ONE_BISTREAM_ALIGHED_SIZE)

    #define BITSTREAM_ONE_UNIT_MEM_SIZE                 (100)
    #define VENC_BITSTREAM_CTRL_SIZE                    (BITSTREAM_ONE_UNIT_MEM_SIZE * DIRECTCOUPLE_BISTREAM_NUM)
    #define VENC_DUMMY_BUFFER_SIZE                      (DIRECTCOUPLE_ONE_BISTREAM_ALIGHED_SIZE + CPU_CACHE_LINE_SIZE_REC)
#else
    #define DIRECTCOUPLE_BISTREAM_NUM                   (0)
    #define DIRECTCOUPLD_ONE_BITSTREAM_SIZE             (0)
    #define DIRECTCOUPLE_ONE_BISTREAM_ALIGHED_SIZE      (DIRECTCOUPLD_ONE_BITSTREAM_SIZE + 4)
    #define VENC_COMP_DIRECTCOUPLE_BITSTREAM_SIZE       (0)

    #define BITSTREAM_ONE_UNIT_MEM_SIZE                 (0)
    #define VENC_BITSTREAM_CTRL_SIZE                    (0)
    #define VENC_DUMMY_BUFFER_SIZE                      (0)
#endif  // __VE_MJPEG_ENC_BYPASS__


/****************************************************
*
* Calculating the memory size of the encoder
*
****************************************************/

#ifdef __VE_MPEG4_ENC_SW_SUPPORT__
    #if (MPEG4_ENC_WORKING_MEM_SIZE == -1)
        #error "The specified resolution is not supported by MPEG-4 encoder."
    #endif  // (MPEG4_ENC_WORKING_MEM_SIZE == -1)

    #if (MPEG4_ENC_BIT_BUFFER_SIZE < 131072)
        #error "The size of bit-stream buffer for MPEG-4 encoder shall not be less than 128 KB."
    #endif  // (MPEG4_ENC_BIT_BUFFER_SIZE < 131072)

    #if ((MPEG4_ENC_BIT_BUFFER_SIZE % 32768) != 0)
        #error "For better performance, the size of the bit-stream buffer shall be a multiple of 32 KB."
    #endif  // ((MPEG4_ENC_BIT_BUFFER_SIZE % 32768) != 0)

    #define MPEG4_ENC_MIN_FRAME_NUM   (4)
    #define MPEG4_ENC_YUV_FRAME_NUM  (MPEG4_ENC_MIN_FRAME_NUM +      \
                                      MPEG4_ENC_EXTRA_YUV_FRAME_NUM)

    #define MPEG4_ENC_MAX_YUV_BUFFER_SIZE   \
        VENC_YUV_BUFFER_SIZE_CAL(MPEG4_ENC_MAX_WIDTH, MPEG4_ENC_MAX_HEIGHT, MPEG4_ENC_YUV_FRAME_NUM)

    #define MPEG4_ENC_CIF_YUV_BUFFER_SIZE \
        VENC_YUV_BUFFER_SIZE_CAL(VENC_CIF_WIDTH, VENC_CIF_HEIGHT, MPEG4_ENC_YUV_FRAME_NUM)

    #ifndef MPEG4_ENC_WORKING_MEM_SIZE
        #error "The size of encoder working memory is not defined."
    #else
        #define MPEG4_ENC_WORKING_MEM_WITH_ADM_OVERHEAD                         \
            (MPEG4_ENC_WORKING_MEM_SIZE + VENC_WORKING_MEM_ADM_OVERHEAD)
    #endif  // MPEG4_ENC_WORKING_MEM_SIZE

    #ifndef MPEG4_ENC_MAX_YUV_BUFFER_SIZE
        #error "Frame buffer size is 0. No codec will be enabled."
    #endif  // MPEG4_ENC_MAX_YUV_BUFFER_SIZE

    #define MPEG4_ENC_TOTAL_MEM_SIZE  (MPEG4_ENC_MAX_YUV_BUFFER_SIZE + \
                                       MPEG4_ENC_WORKING_MEM_WITH_ADM_OVERHEAD + \
                                       MPEG4_ENC_BIT_BUFFER_SIZE)

    // Check memory settings
    #if ((MPEG4_ENC_MAX_YUV_BUFFER_SIZE) > (VENC_FRM_BUFFER_MEM_SIZE))
        #undef VENC_FRM_BUFFER_MEM_SIZE
        #define VENC_FRM_BUFFER_MEM_SIZE MPEG4_ENC_MAX_YUV_BUFFER_SIZE
    #endif

    #if ((MPEG4_ENC_CIF_YUV_BUFFER_SIZE) > (VENC_FRM_BUFFER_CIF_MEM_SIZE))
        #undef VENC_FRM_BUFFER_CIF_MEM_SIZE
        #define VENC_FRM_BUFFER_CIF_MEM_SIZE MPEG4_ENC_CIF_YUV_BUFFER_SIZE
    #endif

    #if ((MPEG4_ENC_WORKING_MEM_WITH_ADM_OVERHEAD) >(VENC_CODEC_WORKING_MEM_SIZE))
        #undef VENC_CODEC_WORKING_MEM_SIZE
        #define VENC_CODEC_WORKING_MEM_SIZE MPEG4_ENC_WORKING_MEM_WITH_ADM_OVERHEAD
    #endif

    #if ((MPEG4_ENC_BIT_BUFFER_SIZE) >(VENC_BITSTREAM_MEM_SIZE))
        #undef VENC_BITSTREAM_MEM_SIZE
        #define VENC_BITSTREAM_MEM_SIZE MPEG4_ENC_BIT_BUFFER_SIZE
    #endif
#else
    #define MPEG4_ENC_YUV_FRAME_NUM (0)
#endif  // __VE_MPEG4_ENC_SW_SUPPORT__


#ifdef __VE_H264_ENC_SW_SUPPORT__
    #if (H264_ENC_WORKING_MEM_SIZE == -1)
        #error "The specified resolution is not supported by H264 encoder."
    #endif  // (MPEG4_ENC_WORKING_MEM_SIZE == -1)

    #if ((H264_ENC_BIT_BUFFER_SIZE % 32768) != 0)
        #error "For better performance, the size of the bit-stream buffer shall be a multiple of 32 KB."
    #endif  // ((MPEG4_ENC_BIT_BUFFER_SIZE % 32768) != 0)

    #define H264_ENC_MIN_FRAME_NUM  (4)
    #define H264_ENC_YUV_FRAME_NUM  (H264_ENC_MIN_FRAME_NUM +      \
                                     H264_ENC_EXTRA_YUV_FRAME_NUM)

    #define H264_ENC_MAX_YUV_BUFFER_SIZE   \
        VENC_YUV_BUFFER_SIZE_CAL(H264_ENC_MAX_WIDTH, H264_ENC_MAX_HEIGHT, H264_ENC_YUV_FRAME_NUM)

    #define H264_ENC_CIF_YUV_BUFFER_SIZE \
        VENC_YUV_BUFFER_SIZE_CAL(VENC_CIF_WIDTH, VENC_CIF_HEIGHT, H264_ENC_YUV_FRAME_NUM)

    #ifndef H264_ENC_WORKING_MEM_SIZE
        #error "The size of h264 sw encoder working memory is not defined."
    #else
        #define H264_ENC_WORKING_MEM_WITH_ADM_OVERHEAD                         \
            (H264_ENC_WORKING_MEM_SIZE + VENC_WORKING_MEM_ADM_OVERHEAD)
    #endif  // H264_ENC_WORKING_MEM_SIZE

    #define H264_ENC_TOTAL_MEM_SIZE  (H264_ENC_MAX_YUV_BUFFER_SIZE + \
                                      H264_ENC_WORKING_MEM_WITH_ADM_OVERHEAD + \
                                      H264_ENC_BIT_BUFFER_SIZE)

    // Check memory settings
    #if ((H264_ENC_MAX_YUV_BUFFER_SIZE) > (VENC_FRM_BUFFER_MEM_SIZE))
        #undef VENC_FRM_BUFFER_MEM_SIZE
        #define VENC_FRM_BUFFER_MEM_SIZE H264_ENC_MAX_YUV_BUFFER_SIZE
    #endif

    #if ((H264_ENC_CIF_YUV_BUFFER_SIZE) > (VENC_FRM_BUFFER_CIF_MEM_SIZE))
        #undef VENC_FRM_BUFFER_CIF_MEM_SIZE
        #define VENC_FRM_BUFFER_CIF_MEM_SIZE H264_ENC_CIF_YUV_BUFFER_SIZE
    #endif

    #if ((H264_ENC_WORKING_MEM_WITH_ADM_OVERHEAD) >(VENC_CODEC_WORKING_MEM_SIZE))
        #undef VENC_CODEC_WORKING_MEM_SIZE
        #define VENC_CODEC_WORKING_MEM_SIZE H264_ENC_WORKING_MEM_WITH_ADM_OVERHEAD
    #endif

    #if ((H264_ENC_BIT_BUFFER_SIZE) >(VENC_BITSTREAM_MEM_SIZE))
        #undef VENC_BITSTREAM_MEM_SIZE
        #define VENC_BITSTREAM_MEM_SIZE H264_ENC_BIT_BUFFER_SIZE
    #endif
#else
    #define H264_ENC_YUV_FRAME_NUM (0)
#endif  // __VE_H264_ENC_SW_SUPPORT__


#ifdef  __VE_MPEG4_ENC_HW_SUPPORT__
    #if (MPEG4_HW_ENC_BIT_BUFFER_SIZE < 131072)
        #error "The size of bit-stream buffer for MPEG-4 HW encoder shall not be less than 128 KB."
    #endif  // (MPEG4_ENC_BIT_BUFFER_SIZE < 131072)

    #define MPEG4_HW_ENC_MIN_FRAME_NUM     (4)
    #define MPEG4_HW_ENC_YUV_FRAME_NUM  (MPEG4_HW_ENC_MIN_FRAME_NUM +      \
                                         MPEG4_HW_ENC_EXTRA_YUV_FRAME_NUM)

    #define MPEG4_HW_ENC_MAX_YUV_BUFFER_SIZE \
        VENC_YUV_BUFFER_SIZE_CAL(MPEG4_HW_ENC_MAX_WIDTH, MPEG4_HW_ENC_MAX_HEIGHT, MPEG4_HW_ENC_YUV_FRAME_NUM)

    #define MPEG4_HW_ENC_CIF_YUV_BUFFER_SIZE    \
        VENC_YUV_BUFFER_SIZE_CAL(VENC_CIF_WIDTH, VENC_CIF_HEIGHT, MPEG4_HW_ENC_YUV_FRAME_NUM)

    #define MPEG4_HW_ENC_WORKING_MEM_WITH_ADM_OVERHEAD                         \
        (MPEG4_HW_ENC_WORKING_MEM_SIZE + VENC_WORKING_MEM_ADM_OVERHEAD)

    #define MPEG4_HW_ENC_TOTAL_MEM_SIZE  (MPEG4_HW_ENC_MAX_YUV_BUFFER_SIZE + \
                                          MPEG4_HW_ENC_WORKING_MEM_WITH_ADM_OVERHEAD + \
                                          MPEG4_HW_ENC_BIT_BUFFER_SIZE)

    // Check memory settings
    #if ((MPEG4_HW_ENC_MAX_YUV_BUFFER_SIZE) > (VENC_FRM_BUFFER_MEM_SIZE))
        #undef VENC_FRM_BUFFER_MEM_SIZE
        #define VENC_FRM_BUFFER_MEM_SIZE MPEG4_HW_ENC_MAX_YUV_BUFFER_SIZE
    #endif

    #if ((MPEG4_HW_ENC_CIF_YUV_BUFFER_SIZE) > (VENC_FRM_BUFFER_CIF_MEM_SIZE))
        #undef VENC_FRM_BUFFER_CIF_MEM_SIZE
        #define VENC_FRM_BUFFER_CIF_MEM_SIZE MPEG4_HW_ENC_CIF_YUV_BUFFER_SIZE
    #endif

    #if ((MPEG4_HW_ENC_WORKING_MEM_WITH_ADM_OVERHEAD) >(VENC_CODEC_WORKING_MEM_SIZE))
        #undef VENC_CODEC_WORKING_MEM_SIZE
        #define VENC_CODEC_WORKING_MEM_SIZE MPEG4_HW_ENC_WORKING_MEM_WITH_ADM_OVERHEAD
    #endif

    #if ((MPEG4_HW_ENC_BIT_BUFFER_SIZE) >(VENC_BITSTREAM_MEM_SIZE))
        #undef VENC_BITSTREAM_MEM_SIZE
        #define VENC_BITSTREAM_MEM_SIZE MPEG4_HW_ENC_BIT_BUFFER_SIZE
    #endif
#else
    #define MPEG4_HW_ENC_YUV_FRAME_NUM (0)
#endif  // __VE_MPEG4_ENC_HW_SUPPORT__


#ifdef __VE_MJPEG_ENC_SUPPORT__
    #if defined(MT6236) || defined(MT6236B)
        #if (MJPEG_ENC_BIT_BUFFER_SIZE < 131072)
            #error "The size of bit-stream buffer for MJPEG encoder shall not be less than 128 KB."
        #endif  // (MJPEG_ENC_BIT_BUFFER_SIZE < 131072)
    #endif

    #define MJPEG_ENC_MIN_FRAME_NUM  (3)
    #define MJPEG_ENC_YUV_FRAME_NUM  (MJPEG_ENC_MIN_FRAME_NUM +      \
                                      MJPEG_ENC_EXTRA_YUV_FRAME_NUM)

    #define MJPEG_ENC_MAX_YUV_BUFFER_SIZE \
        VENC_YUV_BUFFER_SIZE_CAL(MJPEG_ENC_MAX_WIDTH, MJPEG_ENC_MAX_HEIGHT, MJPEG_ENC_YUV_FRAME_NUM)

    #define MJPEG_ENC_CIF_YUV_BUFFER_SIZE \
        VENC_YUV_BUFFER_SIZE_CAL(VENC_CIF_WIDTH, VENC_CIF_HEIGHT, MJPEG_ENC_YUV_FRAME_NUM)

    #define MJPEG_ENC_WORKING_MEM_WITH_ADM_OVERHEAD                         \
        (MJPEG_ENC_WORKING_MEM_SIZE + VENC_WORKING_MEM_ADM_OVERHEAD)

    #define MJPEG_ENC_TOTAL_MEM_SIZE  (MJPEG_ENC_MAX_YUV_BUFFER_SIZE + \
                                       MJPEG_ENC_WORKING_MEM_WITH_ADM_OVERHEAD + \
                                       MJPEG_ENC_BIT_BUFFER_SIZE)

    // Check memory settings
    #if ((MJPEG_ENC_MAX_YUV_BUFFER_SIZE) > (VENC_FRM_BUFFER_MEM_SIZE))
        #undef VENC_FRM_BUFFER_MEM_SIZE
        #define VENC_FRM_BUFFER_MEM_SIZE MJPEG_ENC_MAX_YUV_BUFFER_SIZE
    #endif

    #if ((MJPEG_ENC_CIF_YUV_BUFFER_SIZE) > (VENC_FRM_BUFFER_CIF_MEM_SIZE))
        #undef VENC_FRM_BUFFER_CIF_MEM_SIZE
        #define VENC_FRM_BUFFER_CIF_MEM_SIZE MJPEG_ENC_CIF_YUV_BUFFER_SIZE
    #endif

    #if ((MJPEG_ENC_WORKING_MEM_WITH_ADM_OVERHEAD) >(VENC_CODEC_WORKING_MEM_SIZE))
        #undef VENC_CODEC_WORKING_MEM_SIZE
        #define VENC_CODEC_WORKING_MEM_SIZE MJPEG_ENC_WORKING_MEM_WITH_ADM_OVERHEAD
    #endif

    #if ((MJPEG_ENC_BIT_BUFFER_SIZE) >(VENC_BITSTREAM_MEM_SIZE))
        #undef VENC_BITSTREAM_MEM_SIZE
        #define VENC_BITSTREAM_MEM_SIZE MJPEG_ENC_BIT_BUFFER_SIZE
    #endif
#else
    #define MJPEG_ENC_YUV_FRAME_NUM (0)
#endif  // __VE_MJPEG_ENC_SUPPORT__


#define VIDEO_ENCODER_VT_CHASSIS_MEM_SIZE     \
    (VENC_MAX_CHASSIS_NUM_X * VENC_SIZE_PER_CHASSIS)


#ifndef MPEG4_ENC_BIT_BUFFER_SIZE
    #define MPEG4_ENC_BIT_BUFFER_SIZE 0
#endif


/****************************************************
*
* Calculating the memory size of the file writer
*
****************************************************/

#if defined(MP4_MUXER_TOTAL_EXT_MEM_SIZE)
    #if (MP4_MUXER_TOTAL_EXT_MEM_SIZE > VENC_FW_EXT_MEM_SIZE)
        #undef VENC_FW_EXT_MEM_SIZE
        #define VENC_FW_EXT_MEM_SIZE    (MP4_MUXER_TOTAL_EXT_MEM_SIZE + MUXER_COMP_MEM_SIZE)
    #endif
#endif  // MP4_FW_TOTAL_EXT_MEM_SIZE


// we don't count the memory of AVI currently since it retrieves memory from MED pool
#if defined(AVI_MUXER_TOTAL_EXT_MEM_SIZE)
    #if (AVI_MUXER_TOTAL_EXT_MEM_SIZE > VENC_FW_EXT_MEM_SIZE)
        #undef VENC_FW_EXT_MEM_SIZE
        #define VENC_FW_EXT_MEM_SIZE    (AVI_MUXER_TOTAL_EXT_MEM_SIZE + MUXER_COMP_MEM_SIZE)
    #endif
#endif  // AVI_FW_TOTAL_EXT_V2_MEM_SIZE

// we don't count the memory of AVI currently since it retrieves memory from MED pool
#if defined(RTP_MUXER_TOTAL_EXT_MEM_SIZE)
    #if (RTP_MUXER_TOTAL_EXT_MEM_SIZE > VENC_FW_EXT_MEM_SIZE)
        #undef VENC_FW_EXT_MEM_SIZE
        #define VENC_FW_EXT_MEM_SIZE    (RTP_MUXER_TOTAL_EXT_MEM_SIZE + MUXER_COMP_MEM_SIZE)
    #endif
#endif  // RTP_MUXER_TOTAL_EXT_MEM_SIZE

/****************************************************
*
* Sum the total memory size of the encoder component
*
****************************************************/
#define SUM_VENC_MEMORY(FrameBufferSize, BistreamBufferSize, CodecWorkingSize) \
    (FrameBufferSize + 1 +             \
    BistreamBufferSize + 1 +               \
    CodecWorkingSize + 1 +           \
    VENC_EXTRA_OVERHEAD + 1 +                   \
    VENC_COMP_ALL_Q_SIZE + 1 +                  \
    VENC_YUV_HEADER_Q_SIZE + 1 +                \
    VENC_TIME_STAMP_Q_SIZE + 1 +                \
    VENC_RESEND_Q_SIZE + 1 +                    \
    VIDEO_ENCODER_VT_CHASSIS_MEM_SIZE + 1 +     \
    VENC_WORKING_MEM_ADM_OVERHEAD+ 1 +          \
    VENC_BITSTREAM_HEADER_MEM_SIZE)

#define MPEG4_RECORDER_TOTAL_MEM_SIZE  \
    SUM_VENC_MEMORY(MPEG4_ENC_MAX_YUV_BUFFER_SIZE, MPEG4_ENC_BIT_BUFFER_SIZE, MPEG4_ENC_WORKING_MEM_WITH_ADM_OVERHEAD)
#define H264_RECORDER_TOTAL_MEM_SIZE  \
    SUM_VENC_MEMORY(H264_ENC_MAX_YUV_BUFFER_SIZE, H264_ENC_BIT_BUFFER_SIZE, H264_ENC_WORKING_MEM_WITH_ADM_OVERHEAD)
#define MPEG4_HW_RECORDER_TOTAL_MEM_SIZE  \
    SUM_VENC_MEMORY(MPEG4_HW_ENC_MAX_YUV_BUFFER_SIZE, MPEG4_HW_ENC_BIT_BUFFER_SIZE, MPEG4_HW_ENC_WORKING_MEM_WITH_ADM_OVERHEAD)
#define MJPEG_RECORDER_TOTAL_MEM_SIZE  \
    SUM_VENC_MEMORY(MJPEG_ENC_MAX_YUV_BUFFER_SIZE, MJPEG_ENC_BIT_BUFFER_SIZE, MJPEG_ENC_WORKING_MEM_WITH_ADM_OVERHEAD)


#define VENC_RECORDER_TOTAL_MEM_SIZE  \
    SUM_VENC_MEMORY(VENC_FRM_BUFFER_MEM_SIZE, VENC_BITSTREAM_MEM_SIZE, VENC_CODEC_WORKING_MEM_SIZE)


#define VENC_COMP_TOTAL_MEM_SIZE (VENC_RECORDER_TOTAL_MEM_SIZE)
#define VENC_COMP_CIF_TOTAL_MEM_SIZE    \
    (VENC_RECORDER_TOTAL_MEM_SIZE -     \
    VENC_FRM_BUFFER_MEM_SIZE +          \
    VENC_FRM_BUFFER_CIF_MEM_SIZE)

#define VENC_COMP_DIRECTCOUPLE_MEMORY_SIZE      \
    (VENC_COMP_DIRECTCOUPLE_BITSTREAM_SIZE +    \
    VENC_BITSTREAM_CTRL_SIZE +                  \
    VENC_DUMMY_BUFFER_SIZE +                    \
    VENC_COMP_ALL_Q_SIZE +                      \
    VENC_RESEND_Q_SIZE)


#if (VENC_COMP_DIRECTCOUPLE_MEMORY_SIZE > VENC_COMP_TOTAL_MEM_SIZE)
    #undef VENC_COMP_TOTAL_MEM_SIZE
    #define VENC_COMP_TOTAL_MEM_SIZE (VENC_COMP_DIRECTCOUPLE_MEMORY_SIZE)
#endif


#if (VENC_COMP_DIRECTCOUPLE_MEMORY_SIZE > VENC_COMP_CIF_TOTAL_MEM_SIZE)
    #undef VENC_COMP_CIF_TOTAL_MEM_SIZE
    #define VENC_COMP_CIF_TOTAL_MEM_SIZE (VENC_COMP_DIRECTCOUPLE_MEMORY_SIZE)
#endif


/****************************************************
*
* Calculating the total memory size of the recorder
*
****************************************************/

// Each memory allocation through the common video function needs to be aligned
// to cache-line size.  MP4_ENC_EXTRA_OVERHEAD must cover this overhead.
#define VIDEO_V2_RECORDER_EXT_MEM_SIZE          (2 + VENC_COMP_TOTAL_MEM_SIZE + MPLVR_AUDIO_BUFFER_SIZE + 2 + VENC_FW_EXT_MEM_SIZE + 2)

#define VIDEO_V2_RECORDER_CIF_EXT_MEM_SIZE  (2 + VENC_COMP_CIF_TOTAL_MEM_SIZE + MPLVR_AUDIO_BUFFER_SIZE + VENC_FW_EXT_MEM_SIZE + 2)


/****************************************************
*
* Calculating the total memory size of the writer
*
****************************************************/

#define VIDEO_V2_RECORDER_FW_EXT_MEM_SIZE                    \
    (MP4_MUXER_TOTAL_EXT_MEM_SIZE + MUXER_COMP_MEM_SIZE)

// The definition is for foreground recording memory usage
#define VIDEO_V2_RECORDER_AVI_FW_EXT_MEM_SIZE   \
    (AVI_MUXER_TOTAL_EXT_MEM_SIZE + MUXER_COMP_MEM_SIZE)

// The definition is for background file merge memory usage
#define VIDEO_V2_RECORDER_AVI_FW_FILEMERGE_EXT_MEM_SIZE   \
    (AVI_MUXER_TOTAL_MERGE_FILE_EXT_MEM_SIZE + MUXER_COMP_MEM_SIZE)

/***************************************
*
*   VT Setting
*
*   Assumption: YUV420 format
*
***************************************/
#ifdef __VE_VIDEO_VT_SUPPORT__

    /* decoder part */
    #if ((!defined(MPEG4_VT_DEC_MAX_WIDTH)) || (!defined(MPEG4_VT_DEC_MAX_HEIGHT)) || (!defined(MPEG4_VT_DEC_WORKING_MEM)))
        #error "VT enable, but no decoder"
    #endif

    #if (MPEG4_VT_BUFFER_NUM < 4)
        #error "Frame number of MPEG4 VT decoder should be no less than 4"
    #endif

    #if (MPEG4_VT_DEC_WORKING_MEM == -1)
        #error "This resolution is not support by mpeg4 VT decoder"
    #endif

    #define MPEG4_VT_TOTAL_BUFFER_SIZE (MPEG4_VT_DEC_MAX_WIDTH * MPEG4_VT_DEC_MAX_HEIGHT * MPEG4_VT_BUFFER_NUM * 3 / 2 + (CPU_CACHE_LINE_SIZE_MINE*2))

    #define VIDEO_VT_DECODER_TOTAL_BUFFER_SIZE  MPEG4_VT_TOTAL_BUFFER_SIZE
    #define VIDEO_VT_DECODER_WORKING_MEM        MPEG4_VT_DEC_WORKING_MEM


    /* encoder part */
    #if((!defined(MPEG4_ENC_VT_WORKING_MEM_SIZE))||(!defined(MPEG4_ENC_VT_MAX_WIDTH))||(!defined(MPEG4_ENC_VT_MAX_HEIGHT)))
        #error "VT is enable but codec doesn't provide settings"
    #endif

    #if (MPEG4_ENC_VT_WORKING_MEM_SIZE == (-1))
        #error "This resolution is not support by mpeg4 VT encoder"
    #endif

    #define MPEG4_ENC_VT_BIT_BUFFER_SIZE (262144)
    #define MPEG4_ENC_VT_WORKING_MEM_WITH_ADM_OVERHEAD (MPEG4_ENC_VT_WORKING_MEM_SIZE + VENC_WORKING_MEM_ADM_OVERHEAD)

    #if (MPEG4_ENC_VT_WORKING_MEM_SIZE == -1)
        #error "The specified resolution is not supported by MPEG-4 encoder.(VT)"
    #endif  // (MPEG4_ENC_VT_WORKING_MEM_SIZE == -1)

    #if (MPEG4_ENC_VT_BIT_BUFFER_SIZE < 163840)
        #error "The size of bit-stream buffer for MPEG-4 encoder shall not be less than 160KB."
    #endif  // (MPEG4_VT_ENC_BIT_BUFFER_SIZE < 163840)

    #if ((MPEG4_ENC_VT_BIT_BUFFER_SIZE % 32768) != 0)
        #error "For better performance, the size of the bit-stream buffer shall be a multiple of 32 KB."
    #endif  // ((MPEG4_VT_ENC_BIT_BUFFER_SIZE % 32768) != 0)

    #define MPEG4_ENC_VT_MIN_FRAME_NUM    (4)
    #define MPEG4_ENC_VT_YUV_FRAME_NUM  (MPEG4_ENC_VT_MIN_FRAME_NUM +      \
                                         MPEG4_ENC_VT_EXTRA_YUV_BUFFER_NUM)

    #define MPEG4_ENC_VT_MAX_YUV_BUFFER_SIZE \
        VENC_YUV_BUFFER_SIZE_CAL(MPEG4_ENC_VT_MAX_WIDTH, MPEG4_ENC_VT_MAX_HEIGHT, MPEG4_ENC_VT_YUV_FRAME_NUM)

    #define VIDEO_V2_ENCODER_VT_EXT_MEM_SIZE                \
       (MPEG4_ENC_VT_MAX_YUV_BUFFER_SIZE + 1 +              \
        MPEG4_ENC_VT_BIT_BUFFER_SIZE + 1 +                  \
        MPEG4_ENC_VT_WORKING_MEM_WITH_ADM_OVERHEAD + 1 +    \
        VENC_EXTRA_OVERHEAD + 1 +                           \
        VENC_COMP_ALL_Q_SIZE + 1 +                          \
        VENC_YUV_HEADER_Q_SIZE + 1 +                        \
        VENC_TIME_STAMP_Q_SIZE + 1 +                        \
        VIDEO_ENCODER_VT_CHASSIS_MEM_SIZE + 1 +             \
        VENC_WORKING_MEM_ADM_OVERHEAD + 1 +                 \
        VENC_BITSTREAM_HEADER_MEM_SIZE)

    #define MPEG4_ENC_VT_TOTAL_MEM_SIZE (VIDEO_V2_ENCODER_VT_EXT_MEM_SIZE)

    /* common part */
    #define VIDEO_VT_IL_EXT_MEM_SIZE          (VIDEO_COMM_INPUT_Q_ITEM_SIZE *     \
                                         VIDEO_VT_IL_INPUT_BUFFER_Q_NUM)

    #define VIDEO_VT_EXT_MEM_SIZE (VIDEO_VT_DECODER_TOTAL_BUFFER_SIZE + VIDEO_EXTRA_MEM_SIZE + VIDEO_VT_DECODER_WORKING_MEM + VIDEO_DEC_WORKING_MEM_SIZE + VIDEO_V2_ENCODER_VT_EXT_MEM_SIZE + VIDEO_VT_IL_EXT_MEM_SIZE)
#else
    #define MPEG4_ENC_VT_YUV_FRAME_NUM (0)
    #define VIDEO_VT_EXT_MEM_SIZE (0)
#endif  /* __VE_VIDEO_VT_SUPPORT__ */


/***************************************
*   QVGA Scenario
*   Decide the size of frame buffer & the working memory of codec
*   Assumption: YUV420 format
***************************************/
#define QVGA_FRM_BUFFER_SIZE             0
#define QVGA_CODEC_WORKING_MEM_SIZE      0
#define QVGA_TEMP_TOTAL_MEM_SIZE         0

#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    #if (MPEG4_QVGA_EXTRA_BUFFER_NUM < 0)
    #error "QVGA Scenario: Extra frame number of MPEG4 decoder should be no bigger than or equal to 0"
    #endif

    #define MPEG4_QVGA_NORMAL_BUFFER_SIZE (MPEG4_QVGA_DEC_MAX_WIDTH * MPEG4_QVGA_DEC_MAX_HEIGHT * (MPEG4_QVGA_EXTRA_BUFFER_NUM + DECODER_ESSENTIAL_BUFFER_NUM) * 3 / 2 + (CPU_CACHE_LINE_SIZE_MINE*2))

    #define MPEG4_QVGA_FRM_BUFFER_SIZE_CACHE_LINE \
            ALIGN_X((MPEG4_QVGA_NORMAL_BUFFER_SIZE + GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define MPEG4_QVGA_WORKING_MEM_SIZE_CACHE_LINE \
            ALIGN_X((MPEG4_QVGA_DEC_WORKING_MEM + CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ((MPEG4_QVGA_FRM_BUFFER_SIZE_CACHE_LINE + MPEG4_QVGA_WORKING_MEM_SIZE_CACHE_LINE) > QVGA_TEMP_TOTAL_MEM_SIZE)
        #undef QVGA_TEMP_TOTAL_MEM_SIZE
        #undef QVGA_FRM_BUFFER_SIZE
        #undef QVGA_CODEC_WORKING_MEM_SIZE
        #define QVGA_TEMP_TOTAL_MEM_SIZE    (MPEG4_QVGA_FRM_BUFFER_SIZE_CACHE_LINE + MPEG4_QVGA_WORKING_MEM_SIZE_CACHE_LINE)
        #define QVGA_FRM_BUFFER_SIZE        (MPEG4_QVGA_FRM_BUFFER_SIZE_CACHE_LINE)
        #define QVGA_CODEC_WORKING_MEM_SIZE (MPEG4_QVGA_WORKING_MEM_SIZE_CACHE_LINE)
    #endif
#endif  /* (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__)) */


#if (defined (__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    #if (H264_QVGA_EXTRA_BUFFER_NUM < 0)
    #error "QVGA Scenario: Extra frame number of H264 decoder should be no bigger than or equal to 0"
    #endif

    #define H264_QVGA_NORMAL_BUFFER_SIZE (H264_QVGA_DEC_MAX_WIDTH * H264_QVGA_DEC_MAX_HEIGHT * (H264_QVGA_EXTRA_BUFFER_NUM + DECODER_ESSENTIAL_BUFFER_NUM) * 3 / 2 + (CPU_CACHE_LINE_SIZE_MINE*2))
    #define H264_QVGA_3_FRM_SIZE    (3 * H264_QVGA_DEC_MAX_WIDTH * H264_QVGA_DEC_MAX_HEIGHT * 3 / 2)

    #if ((H264_QVGA_EXTRA_BUFFER_NUM + DECODER_ESSENTIAL_BUFFER_NUM) < 19)
        #if ((H264_QVGA_DEC_DPB_SIZE + H264_QVGA_3_FRM_SIZE) > H264_QVGA_NORMAL_BUFFER_SIZE)
            #error "QVGA Scenario: Frame buffer size is smaller than the level specified. Please either increase the frame number or raise the level."
        #else
            #undef H264_QVGA_DEC_DPB_SIZE
            #define H264_QVGA_DEC_DPB_SIZE H264_QVGA_NORMAL_BUFFER_SIZE
        #endif
    #else
        #undef H264_QVGA_DEC_DPB_SIZE
        #define H264_QVGA_DEC_DPB_SIZE H264_QVGA_NORMAL_BUFFER_SIZE
    #endif

    #define H264_QVGA_FRM_BUFFER_SIZE_CACHE_LINE \
            ALIGN_X((H264_QVGA_NORMAL_BUFFER_SIZE+GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define H264_QVGA_WORKING_MEM_SIZE_CACHE_LINE \
            ALIGN_X((H264_QVGA_DEC_WORKING_MEM+CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ((H264_QVGA_FRM_BUFFER_SIZE_CACHE_LINE + H264_QVGA_WORKING_MEM_SIZE_CACHE_LINE) > QVGA_TEMP_TOTAL_MEM_SIZE)
        #undef QVGA_TEMP_TOTAL_MEM_SIZE
        #undef QVGA_FRM_BUFFER_SIZE
        #undef QVGA_CODEC_WORKING_MEM_SIZE
        #define QVGA_TEMP_TOTAL_MEM_SIZE    (H264_QVGA_FRM_BUFFER_SIZE_CACHE_LINE + H264_QVGA_WORKING_MEM_SIZE_CACHE_LINE)
        #define QVGA_FRM_BUFFER_SIZE        (H264_QVGA_FRM_BUFFER_SIZE_CACHE_LINE)
        #define QVGA_CODEC_WORKING_MEM_SIZE (H264_QVGA_WORKING_MEM_SIZE_CACHE_LINE)
    #endif
#endif  /* #if (defined (__VE_H264_DEC_SW_SUPPORT__) || (__VE_H264_DEC_HW_SUPPORT__)) */


#ifdef __VE_RV_DEC_SW_SUPPORT__
    #if (RV9_QVGA_EXTRA_BUFFER_NUM < 0)
    #error "QVGA Scenario: Extra frame number of RV decoder should be no bigger than or equal to 0"
    #endif

    #define RV9_QVGA_NORMAL_BUFFER_SIZE (((RV9_QVGA_DEC_MAX_WIDTH) * (RV9_QVGA_DEC_MAX_HEIGHT) * (RV9_QVGA_EXTRA_BUFFER_NUM + RM_DECODER_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (2*16*RV9_QVGA_DEC_MAX_WIDTH) + (CPU_CACHE_LINE_SIZE_MINE*2))

    #define RV9_QVGA_FRM_BUFFER_SIZE_CACHE_LINE \
            ALIGN_X((RV9_QVGA_NORMAL_BUFFER_SIZE+GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define RV9_QVGA_WORKING_MEM_SIZE_CACHE_LINE \
            ALIGN_X((RV9_QVGA_DEC_WORKING_MEM+CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ((RV9_QVGA_FRM_BUFFER_SIZE_CACHE_LINE + RV9_QVGA_WORKING_MEM_SIZE_CACHE_LINE) > QVGA_TEMP_TOTAL_MEM_SIZE)
        #undef QVGA_TEMP_TOTAL_MEM_SIZE
        #undef QVGA_FRM_BUFFER_SIZE
        #undef QVGA_CODEC_WORKING_MEM_SIZE
        #define QVGA_TEMP_TOTAL_MEM_SIZE    (RV9_QVGA_FRM_BUFFER_SIZE_CACHE_LINE + RV9_QVGA_WORKING_MEM_SIZE_CACHE_LINE)
        #define QVGA_FRM_BUFFER_SIZE        (RV9_QVGA_FRM_BUFFER_SIZE_CACHE_LINE)
        #define QVGA_CODEC_WORKING_MEM_SIZE (RV9_QVGA_WORKING_MEM_SIZE_CACHE_LINE)
    #endif
#endif  /* __VE_RV_DEC_SW_SUPPORT__ */


#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
    #define MJPEG_QVGA_BUFFER_SIZE (((MJPEG_QVGA_DEC_MAX_WIDTH) * (MJPEG_QVGA_DEC_MAX_HEIGHT) * (MJPEG_QVGA_EXTRA_BUFFER_NUM + DECODER_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE*2))

    #define MJPEG_QVGA_FRM_BUFFER_SIZE_CACHE_LINE \
            ALIGN_X((MJPEG_QVGA_BUFFER_SIZE+GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define MJPEG_QVGA_WORKING_MEM_SIZE_CACHE_LINE \
            ALIGN_X((MJPEG_QVGA_DEC_WORKING_MEM+CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ( (MJPEG_QVGA_FRM_BUFFER_SIZE_CACHE_LINE+MJPEG_QVGA_WORKING_MEM_SIZE_CACHE_LINE) > QVGA_TEMP_TOTAL_MEM_SIZE)
        #undef QVGA_TEMP_TOTAL_MEM_SIZE
        #undef QVGA_FRM_BUFFER_SIZE
        #undef QVGA_CODEC_WORKING_MEM_SIZE
        #define QVGA_TEMP_TOTAL_MEM_SIZE    (MJPEG_QVGA_FRM_BUFFER_SIZE_CACHE_LINE + MJPEG_QVGA_WORKING_MEM_SIZE_CACHE_LINE)
        #define QVGA_FRM_BUFFER_SIZE        (MJPEG_QVGA_FRM_BUFFER_SIZE_CACHE_LINE)
        #define QVGA_CODEC_WORKING_MEM_SIZE (MJPEG_QVGA_WORKING_MEM_SIZE_CACHE_LINE)
    #endif
#endif  /* __VE_MJPEG_DEC_SW_SUPPORT__ */


#ifdef __VE_VP8_DEC_SW_SUPPORT__
    #if (VP8_QVGA_EXTRA_BUFFER_NUM < 0)
        #error "QVGA Scenario: Extra frame number of VP8 decoder should be no bigger than or equal to 0"
    #endif

    #define VP8_QVGA_NORMAL_BUFFER_SIZE ((ALIGN_X((VP8_QVGA_DEC_MAX_WIDTH+VP8_PADDING_SIZE), 32) * ALIGN_X((VP8_QVGA_DEC_MAX_HEIGHT+VP8_PADDING_SIZE), 32) * (VP8_QVGA_EXTRA_BUFFER_NUM + VP8_DECODER_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE*2))

    #define VP8_QVGA_FRM_BUFFER_SIZE_CACHE_LINE ALIGN_X((VP8_QVGA_NORMAL_BUFFER_SIZE+GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define VP8_QVGA_WORKING_MEM_SIZE_CACHE_LINE ALIGN_X((VP8_QVGA_DEC_WORKING_MEM+CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ( (VP8_QVGA_FRM_BUFFER_SIZE_CACHE_LINE + VP8_QVGA_WORKING_MEM_SIZE_CACHE_LINE) > QVGA_TEMP_TOTAL_MEM_SIZE)
        #undef QVGA_TEMP_TOTAL_MEM_SIZE
        #undef QVGA_FRM_BUFFER_SIZE
        #undef QVGA_CODEC_WORKING_MEM_SIZE
        #define QVGA_TEMP_TOTAL_MEM_SIZE    (VP8_QVGA_FRM_BUFFER_SIZE_CACHE_LINE + VP8_QVGA_WORKING_MEM_SIZE_CACHE_LINE)
        #define QVGA_FRM_BUFFER_SIZE        (VP8_QVGA_FRM_BUFFER_SIZE_CACHE_LINE)
        #define QVGA_CODEC_WORKING_MEM_SIZE (VP8_QVGA_WORKING_MEM_SIZE_CACHE_LINE)
    #endif
#endif  // __VE_VP8_DEC_SW_SUPPORT__


#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__) || defined (__VE_H264_DEC_SW_SUPPORT__) \
       || defined(__VE_H264_DEC_HW_SUPPORT__) || defined(__VE_RV_DEC_SW_SUPPORT__) || defined(__VE_MJPEG_DEC_SW_SUPPORT__) \
       || defined(__VE_VP8_DEC_SW_SUPPORT__))

    #if (QVGA_FRM_BUFFER_SIZE == 0)
        #error "QVGA Scenario: Cannot decide the size of frame buffer, no codec is enable"
    #endif
#endif

//Temp solution
#define DECODER_QVGA_MEM_SIZE (QVGA_FRM_BUFFER_SIZE + VIDEO_EXTRA_MEM_SIZE + VIDEO_DEC_WORKING_MEM_SIZE + QVGA_CODEC_WORKING_MEM_SIZE)
//#define DECODER_QVGA_MEM_SIZE (QVGA_FRM_BUFFER_SIZE + VIDEO_DEC_WORKING_MEM_SIZE + CODEC_WORKING_MEM_SIZE)


/***************************************
*   QVGAMPEG4SP Scenario
*   Decide the size of frame buffer & the working memory of codec
*   Assumption: YUV420 format
***************************************/
#define QVGAMPEG4SP_FRM_BUFFER_SIZE             0
#define QVGAMPEG4SP_CODEC_WORKING_MEM_SIZE      0
#define QVGAMPEG4SP_TEMP_TOTAL_MEM_SIZE         0

#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    #if (MPEG4_QVGAMPEG4SP_EXTRA_BUFFER_NUM < 0)
    #error "QVGAMPEG4SP Scenario: Extra frame number of MPEG4 decoder should be no bigger than or equal to 0"
    #endif

    #define MPEG4_QVGAMPEG4SP_NORMAL_BUFFER_SIZE (MPEG4_QVGA_DEC_MAX_WIDTH * MPEG4_QVGA_DEC_MAX_HEIGHT * (MPEG4_QVGAMPEG4SP_EXTRA_BUFFER_NUM + DECODER_ESSENTIAL_BUFFER_NUM) * 3 / 2 + (CPU_CACHE_LINE_SIZE_MINE*2))

    #define MPEG4_QVGAMPEG4SP_FRM_BUFFER_SIZE_CACHE_LINE ALIGN_X((MPEG4_QVGAMPEG4SP_NORMAL_BUFFER_SIZE + GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define MPEG4_QVGAMPEG4SP_WORKING_MEM_SIZE_CACHE_LINE ALIGN_X((MPEG4_QVGAMPEG4SP_DEC_WORKING_MEM + CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #undef QVGAMPEG4SP_TEMP_TOTAL_MEM_SIZE
    #undef QVGAMPEG4SP_FRM_BUFFER_SIZE
    #undef QVGAMPEG4SP_CODEC_WORKING_MEM_SIZE
    #define QVGAMPEG4SP_TEMP_TOTAL_MEM_SIZE    (MPEG4_QVGAMPEG4SP_FRM_BUFFER_SIZE_CACHE_LINE + MPEG4_QVGAMPEG4SP_WORKING_MEM_SIZE_CACHE_LINE)
    #define QVGAMPEG4SP_FRM_BUFFER_SIZE        (MPEG4_QVGAMPEG4SP_FRM_BUFFER_SIZE_CACHE_LINE)
    #define QVGAMPEG4SP_CODEC_WORKING_MEM_SIZE (MPEG4_QVGAMPEG4SP_WORKING_MEM_SIZE_CACHE_LINE)

#endif  /* (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__)) */

#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    #if (QVGAMPEG4SP_FRM_BUFFER_SIZE == 0)
        #error "QVGAMPEG4SP Scenario: Cannot decide the size of frame buffer, no codec is enable"
    #endif
#endif

//Temp solution
#define DECODER_QVGAMPEG4SP_MEM_SIZE (QVGAMPEG4SP_FRM_BUFFER_SIZE + VIDEO_EXTRA_MEM_SIZE + VIDEO_DEC_WORKING_MEM_SIZE + QVGAMPEG4SP_CODEC_WORKING_MEM_SIZE)
//#define DECODER_QVGA_MEM_SIZE (QVGA_FRM_BUFFER_SIZE + VIDEO_DEC_WORKING_MEM_SIZE + CODEC_WORKING_MEM_SIZE)


// preview
/***************************************
*   PREVIEW Scenario
*   Decide the size of frame buffer & the working memory of codec
*   Assumption: YUV420 format
***************************************/
#define PREVIEW_FRM_BUFFER_SIZE             0
#define PREVIEW_CODEC_WORKING_MEM_SIZE      0
#define PREVIEW_TEMP_TOTAL_MEM_SIZE         0


#ifdef __VE_MPEG4_DEC_HW_SUPPORT__
    #if (MPEG4_PREVIEW_EXTRA_BUFFER_NUM < 0)
    #error "PREVIEW Scenario:Extra frame number of MPEG4 decoder should be no bigger than or equal to 0"
    #endif

    #define MPEG4_PREVIEW_SP_FAST_MODE_BUFFER_SIZE 0 // HW no subsampling
    #define MPEG4_PREVIEW_SP_NORMAL_BUFFER_SIZE (MPEG4_DEC_MAX_NORMAL_WIDTH_SP * MPEG4_DEC_MAX_NORMAL_HEIGHT_SP * (MPEG4_PREVIEW_EXTRA_BUFFER_NUM + DECODER_PREVIEW_ESSENTIAL_BUFFER_NUM) * 3 / 2 + (CPU_CACHE_LINE_SIZE_MINE*2))

    #define MPEG4_PREVIEW_ASP_FAST_MODE_BUFFER_SIZE 0 // HW doesn't support ASP
    #define MPEG4_PREVIEW_ASP_NORMAL_BUFFER_SIZE 0 // HW doesn't support ASP
#endif  /* __VE_MPEG4_DEC_HW_SUPPORT__ */


#ifdef __VE_MPEG4_DEC_SW_SUPPORT__
    #if (MPEG4_PREVIEW_EXTRA_BUFFER_NUM < 0)
    #error "PREVIEW Scenario:Extra frame number of MPEG4 decoder should be no bigger than or equal to 0"
    #endif

    // SP +
    #define MPEG4_PREVIEW_SP_NORMAL_BUFFER_SIZE     (MPEG4_DEC_MAX_NORMAL_WIDTH_SP * MPEG4_DEC_MAX_NORMAL_HEIGHT_SP * (MPEG4_PREVIEW_EXTRA_BUFFER_NUM + DECODER_PREVIEW_ESSENTIAL_BUFFER_NUM) * 3 / 2 + (CPU_CACHE_LINE_SIZE_MINE * 2))
    //#define MPEG4_PREVIEW_SP_1_TO_2_BUFFER_SIZE   ((MPEG4_SP_DEC_MAX_WIDTH_1_TO_2_ALIGN * MPEG4_SP_DEC_MAX_HEIGHT_1_TO_2_ALIGN * (MPEG4_PREVIEW_EXTRA_BUFFER_NUM + DECODER_PREVIEW_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE * 2))
    #define MPEG4_PREVIEW_SP_FAST_MODE_BUFFER_SIZE  ((MPEG4_SP_DEC_MAX_HALF_WIDTH_ALIGN * MPEG4_SP_DEC_MAX_HALF_HEIGHT_ALIGN * (MPEG4_PREVIEW_EXTRA_BUFFER_NUM + DECODER_PREVIEW_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE * 2))
    #define MPEG4_PREVIEW_SP_1_TO_8_BUFFER_SIZE     ((MPEG4_SP_DEC_MAX_WIDTH_1_TO_8_ALIGN * MPEG4_SP_DEC_MAX_HEIGHT_1_TO_8_ALIGN * (MPEG4_PREVIEW_EXTRA_BUFFER_NUM + DECODER_PREVIEW_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE * 2))
    // SP -

    #ifdef __MP4_DEC_SW_SUPPORT_ASP__
    // ASP +
    #define MPEG4_PREVIEW_ASP_NORMAL_BUFFER_SIZE    (MPEG4_DEC_MAX_NORMAL_WIDTH_ASP * MPEG4_DEC_MAX_NORMAL_HEIGHT_ASP * (MPEG4_PREVIEW_EXTRA_BUFFER_NUM + DECODER_PREVIEW_ESSENTIAL_BUFFER_NUM) * 3 / 2 + (CPU_CACHE_LINE_SIZE_MINE * 2))
    //#define MPEG4_PREVIEW_ASP_1_TO_2_BUFFER_SIZE    ((MPEG4_ASP_DEC_MAX_WIDTH_1_TO_2_ALIGN * MPEG4_ASP_DEC_MAX_HEIGHT_1_TO_2_ALIGN * (MPEG4_PREVIEW_EXTRA_BUFFER_NUM + DECODER_PREVIEW_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE * 2))
    #define MPEG4_PREVIEW_ASP_FAST_MODE_BUFFER_SIZE ((MPEG4_ASP_DEC_MAX_HALF_WIDTH_ALIGN * MPEG4_ASP_DEC_MAX_HALF_HEIGHT_ALIGN * (MPEG4_PREVIEW_EXTRA_BUFFER_NUM + DECODER_PREVIEW_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE * 2))
    #define MPEG4_PREVIEW_ASP_1_TO_8_BUFFER_SIZE    ((MPEG4_ASP_DEC_MAX_WIDTH_1_TO_8_ALIGN * MPEG4_ASP_DEC_MAX_HEIGHT_1_TO_8_ALIGN * (MPEG4_PREVIEW_EXTRA_BUFFER_NUM + DECODER_PREVIEW_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE * 2))
    // ASP -
    #endif
#endif


#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    // SP +
    // The comparison of 1:2 must be written in the future if needed.
    #if (MPEG4_PREVIEW_SP_FAST_MODE_BUFFER_SIZE > MPEG4_PREVIEW_SP_NORMAL_BUFFER_SIZE)
        // 1:4 > 1:1
        #if (MPEG4_PREVIEW_SP_FAST_MODE_BUFFER_SIZE > MPEG4_PREVIEW_SP_1_TO_8_BUFFER_SIZE)
            // 1:4 > 1:8
            #define MPEG4_PREVIEW_SP_FRM_BUFFER_SIZE    (MPEG4_PREVIEW_SP_FAST_MODE_BUFFER_SIZE)
            #define MPEG4_PREVIEW_SP_FRM_BUFFER_WIDTH   (MPEG4_SP_DEC_MAX_HALF_WIDTH_ALIGN)
            #define MPEG4_PREVIEW_SP_FRM_BUFFER_HEIGHT  (MPEG4_SP_DEC_MAX_HALF_HEIGHT_ALIGN)
        #else
            // 1:8 > 1:4
            #define MPEG4_PREVIEW_SP_FRM_BUFFER_SIZE    (MPEG4_PREVIEW_SP_1_TO_8_BUFFER_SIZE)
            #define MPEG4_PREVIEW_SP_FRM_BUFFER_WIDTH   (MPEG4_SP_DEC_MAX_WIDTH_1_TO_8_ALIGN)
            #define MPEG4_PREVIEW_SP_FRM_BUFFER_HEIGHT  (MPEG4_SP_DEC_MAX_HEIGHT_1_TO_8_ALIGN)
        #endif
    #else
        // 1:1 > 1:4
        #if (MPEG4_PREVIEW_SP_NORMAL_BUFFER_SIZE > MPEG4_PREVIEW_SP_1_TO_8_BUFFER_SIZE)
            // 1:1 > 1:8
            #define MPEG4_PREVIEW_SP_FRM_BUFFER_SIZE    (MPEG4_PREVIEW_SP_NORMAL_BUFFER_SIZE)
            #define MPEG4_PREVIEW_SP_FRM_BUFFER_WIDTH   (MPEG4_DEC_MAX_NORMAL_WIDTH_SP)
            #define MPEG4_PREVIEW_SP_FRM_BUFFER_HEIGHT  (MPEG4_DEC_MAX_NORMAL_HEIGHT_SP)
        #else
            // 1:8 > 1:1
            #define MPEG4_PREVIEW_SP_FRM_BUFFER_SIZE    (MPEG4_PREVIEW_SP_1_TO_8_BUFFER_SIZE)
            #define MPEG4_PREVIEW_SP_FRM_BUFFER_WIDTH   (MPEG4_SP_DEC_MAX_WIDTH_1_TO_8_ALIGN)
            #define MPEG4_PREVIEW_SP_FRM_BUFFER_HEIGHT  (MPEG4_SP_DEC_MAX_HEIGHT_1_TO_8_ALIGN)
        #endif
    #endif
    // SP -

    #ifdef __MP4_DEC_SW_SUPPORT_ASP__
        // ASP +
        // The comparison of 1:2 must be written in the future if needed.
        #if (MPEG4_PREVIEW_ASP_FAST_MODE_BUFFER_SIZE > MPEG4_PREVIEW_ASP_NORMAL_BUFFER_SIZE)
            // 1:4 > 1:1
            #if (MPEG4_PREVIEW_ASP_FAST_MODE_BUFFER_SIZE > MPEG4_PREVIEW_ASP_1_TO_8_BUFFER_SIZE)
                // 1:4 > 1:8
                #define MPEG4_PREVIEW_ASP_FRM_BUFFER_SIZE   (MPEG4_PREVIEW_ASP_FAST_MODE_BUFFER_SIZE)
                #define MPEG4_PREVIEW_ASP_FRM_BUFFER_WIDTH  (MPEG4_ASP_DEC_MAX_HALF_WIDTH_ALIGN)
                #define MPEG4_PREVIEW_ASP_FRM_BUFFER_HEIGHT (MPEG4_ASP_DEC_MAX_HALF_HEIGHT_ALIGN)
            #else
                // 1:8 > 1:4
                #define MPEG4_PREVIEW_ASP_FRM_BUFFER_SIZE   (MPEG4_PREVIEW_ASP_1_TO_8_BUFFER_SIZE)
                #define MPEG4_PREVIEW_ASP_FRM_BUFFER_WIDTH  (MPEG4_ASP_DEC_MAX_WIDTH_1_TO_8_ALIGN)
                #define MPEG4_PREVIEW_ASP_FRM_BUFFER_HEIGHT (MPEG4_ASP_DEC_MAX_HEIGHT_1_TO_8_ALIGN)
            #endif
        #else
            // 1:1 > 1:4
            #if (MPEG4_PREVIEW_ASP_NORMAL_BUFFER_SIZE > MPEG4_PREVIEW_ASP_1_TO_8_BUFFER_SIZE)
                // 1:1 > 1:8
                #define MPEG4_PREVIEW_ASP_FRM_BUFFER_SIZE   (MPEG4_PREVIEW_ASP_NORMAL_BUFFER_SIZE)
                #define MPEG4_PREVIEW_ASP_FRM_BUFFER_WIDTH  (MPEG4_DEC_MAX_NORMAL_WIDTH_ASP)
                #define MPEG4_PREVIEW_ASP_FRM_BUFFER_HEIGHT (MPEG4_DEC_MAX_NORMAL_HEIGHT_ASP)
            #else
                // 1:8 > 1:1
                #define MPEG4_PREVIEW_ASP_FRM_BUFFER_SIZE   (MPEG4_PREVIEW_ASP_1_TO_8_BUFFER_SIZE)
                #define MPEG4_PREVIEW_ASP_FRM_BUFFER_WIDTH  (MPEG4_ASP_DEC_MAX_WIDTH_1_TO_8_ALIGN)
                #define MPEG4_PREVIEW_ASP_FRM_BUFFER_HEIGHT (MPEG4_ASP_DEC_MAX_HEIGHT_1_TO_8_ALIGN)
            #endif
        #endif
        // ASP -
    #endif

    #ifdef __MP4_DEC_SW_SUPPORT_ASP__
        #if (MPEG4_PREVIEW_ASP_FRM_BUFFER_SIZE > MPEG4_PREVIEW_SP_FRM_BUFFER_SIZE)
            #define MPEG4_PREVIEW_FRM_BUFFER_SIZE   (MPEG4_PREVIEW_ASP_FRM_BUFFER_SIZE)
            #define MPEG4_PREVIEW_FRM_BUFFER_WIDTH  (MPEG4_PREVIEW_ASP_FRM_BUFFER_WIDTH)
            #define MPEG4_PREVIEW_FRM_BUFFER_HEIGHT (MPEG4_PREVIEW_ASP_FRM_BUFFER_HEIGHT)
        #else
            #define MPEG4_PREVIEW_FRM_BUFFER_SIZE   (MPEG4_PREVIEW_SP_FRM_BUFFER_SIZE)
            #define MPEG4_PREVIEW_FRM_BUFFER_WIDTH  (MPEG4_PREVIEW_SP_FRM_BUFFER_WIDTH)
            #define MPEG4_PREVIEW_FRM_BUFFER_HEIGHT (MPEG4_PREVIEW_SP_FRM_BUFFER_HEIGHT)
        #endif
    #else  // __MP4_DEC_SW_SUPPORT_ASP__
        #define MPEG4_PREVIEW_FRM_BUFFER_SIZE       (MPEG4_PREVIEW_SP_FRM_BUFFER_SIZE)
        #define MPEG4_PREVIEW_FRM_BUFFER_WIDTH      (MPEG4_PREVIEW_SP_FRM_BUFFER_WIDTH)
        #define MPEG4_PREVIEW_FRM_BUFFER_HEIGHT     (MPEG4_PREVIEW_SP_FRM_BUFFER_HEIGHT)
    #endif  // __MP4_DEC_SW_SUPPORT_ASP__

    #define MPEG4_PREVIEW_FRM_BUFFER_SIZE_CACHE_LINE \
            ALIGN_X((MPEG4_PREVIEW_FRM_BUFFER_SIZE + GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #ifdef __MP4_DEC_SW_SUPPORT_ASP__
        #if (MPEG4_PREVIEW_DEC_WORKING_MEM_ASP > MPEG4_PREVIEW_DEC_WORKING_MEM_SP)
            #define MPEG4_PREVIEW_WORKING_MEM_SIZE_CACHE_LINE ALIGN_X((MPEG4_PREVIEW_DEC_WORKING_MEM_ASP + CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)
        #else
            #define MPEG4_PREVIEW_WORKING_MEM_SIZE_CACHE_LINE ALIGN_X((MPEG4_PREVIEW_DEC_WORKING_MEM_SP + CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)
        #endif
    #else
        #define MPEG4_PREVIEW_WORKING_MEM_SIZE_CACHE_LINE ALIGN_X((MPEG4_PREVIEW_DEC_WORKING_MEM_SP + CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)
    #endif

    #if ((MPEG4_PREVIEW_FRM_BUFFER_SIZE_CACHE_LINE + MPEG4_PREVIEW_WORKING_MEM_SIZE_CACHE_LINE) > PREVIEW_TEMP_TOTAL_MEM_SIZE)
        #undef PREVIEW_TEMP_TOTAL_MEM_SIZE
        #undef PREVIEW_FRM_BUFFER_SIZE
        #undef PREVIEW_CODEC_WORKING_MEM_SIZE
        #define PREVIEW_TEMP_TOTAL_MEM_SIZE (MPEG4_PREVIEW_FRM_BUFFER_SIZE_CACHE_LINE+MPEG4_PREVIEW_WORKING_MEM_SIZE_CACHE_LINE)
        #define PREVIEW_FRM_BUFFER_SIZE MPEG4_PREVIEW_FRM_BUFFER_SIZE_CACHE_LINE
        #define PREVIEW_CODEC_WORKING_MEM_SIZE MPEG4_PREVIEW_WORKING_MEM_SIZE_CACHE_LINE

        #undef PREVIEW_MAX_CONSUMPTION
        #ifdef __MP4_DEC_SW_SUPPORT_ASP__
            #if (MPEG4_PREVIEW_ASP_FRM_BUFFER_SIZE + MPEG4_PREVIEW_DEC_WORKING_MEM_ASP > MPEG4_PREVIEW_SP_FRM_BUFFER_SIZE + MPEG4_PREVIEW_DEC_WORKING_MEM_SP)
                #define PREVIEW_MAX_CONSUMPTION MPEG4_ASP_CODEC
            #else
                #define PREVIEW_MAX_CONSUMPTION MPEG4_SP_CODEC
            #endif
        #else //__MP4_DEC_SW_SUPPORT_ASP__
            #define PREVIEW_MAX_CONSUMPTION MPEG4_SP_CODEC
        #endif //__MP4_DEC_SW_SUPPORT_ASP__
    #endif
#endif  /* (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__)) */


#if (defined (__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    #if (H264_EXTRA_BUFFER_NUM < 0)
    #error "PREVIEW Scenario: Extra frame number of H264 decoder should be no bigger than or equal to 0"
    #endif

    // BP +
    #define H264_PREVIEW_BP_FAST_MODE_BUFFER_SIZE ((H264_BP_DEC_MAX_HALF_WIDTH_ALIGN * H264_BP_DEC_MAX_HALF_HEIGHT_ALIGN * (H264_PREVIEW_EXTRA_BUFFER_NUM + DECODER_PREVIEW_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE*2))
    #define H264_PREVIEW_BP_NORMAL_BUFFER_SIZE (H264_DEC_MAX_NORMAL_WIDTH_BP * H264_DEC_MAX_NORMAL_HEIGHT_BP * (H264_PREVIEW_EXTRA_BUFFER_NUM + DECODER_PREVIEW_ESSENTIAL_BUFFER_NUM) * 3 / 2 + (CPU_CACHE_LINE_SIZE_MINE*2))

    #if (H264_PREVIEW_BP_FAST_MODE_BUFFER_SIZE > H264_PREVIEW_BP_NORMAL_BUFFER_SIZE)
        #define H264_PREVIEW_BP_FRM_BUFFER_SIZE (H264_PREVIEW_BP_FAST_MODE_BUFFER_SIZE)
        #define H264_PREVIEW_BP_FRM_BUFFER_WIDTH  (H264_BP_DEC_MAX_HALF_WIDTH_ALIGN)
        #define H264_PREVIEW_BP_FRM_BUFFER_HEIGHT  (H264_BP_DEC_MAX_HALF_HEIGHT_ALIGN)
    #else
        #define H264_PREVIEW_BP_FRM_BUFFER_SIZE (H264_PREVIEW_BP_NORMAL_BUFFER_SIZE)
        #define H264_PREVIEW_BP_FRM_BUFFER_WIDTH  (H264_DEC_MAX_NORMAL_WIDTH_BP)
        #define H264_PREVIEW_BP_FRM_BUFFER_HEIGHT  (H264_DEC_MAX_NORMAL_HEIGHT_BP)
    #endif

    #define H264_PREVIEW_BP_DEC_DPB_SIZE H264_PREVIEW_BP_FRM_BUFFER_SIZE

    #define H264_PREVIEW_BP_FRM_BUFFER_SIZE_CACHE_LINE \
            ALIGN_X((H264_PREVIEW_BP_FRM_BUFFER_SIZE+GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)
    // BP -

    // MPHP +
    #ifdef __H264_DEC_SW_SUPPORT_MAINHIGH__

        #define H264_PREVIEW_MPHP_FAST_MODE_BUFFER_SIZE ((H264_MPHP_DEC_MAX_HALF_WIDTH_ALIGN * H264_MPHP_DEC_MAX_HALF_HEIGHT_ALIGN * (H264_PREVIEW_EXTRA_BUFFER_NUM + DECODER_PREVIEW_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE*2))
        #define H264_PREVIEW_MPHP_NORMAL_BUFFER_SIZE (H264_DEC_MAX_NORMAL_WIDTH_MPHP * H264_DEC_MAX_NORMAL_HEIGHT_MPHP * (H264_PREVIEW_EXTRA_BUFFER_NUM + DECODER_PREVIEW_ESSENTIAL_BUFFER_NUM) * 3 / 2 + (CPU_CACHE_LINE_SIZE_MINE*2))

        #if (H264_PREVIEW_MPHP_FAST_MODE_BUFFER_SIZE > H264_PREVIEW_MPHP_NORMAL_BUFFER_SIZE)
            #define H264_PREVIEW_MPHP_FRM_BUFFER_SIZE (H264_PREVIEW_MPHP_FAST_MODE_BUFFER_SIZE)
            #define H264_PREVIEW_MPHP_FRM_BUFFER_WIDTH  (H264_MPHP_DEC_MAX_HALF_WIDTH_ALIGN)
            #define H264_PREVIEW_MPHP_FRM_BUFFER_HEIGHT  (H264_MPHP_DEC_MAX_HALF_HEIGHT_ALIGN)
        #else
            #define H264_PREVIEW_MPHP_FRM_BUFFER_SIZE (H264_PREVIEW_MPHP_NORMAL_BUFFER_SIZE)
            #define H264_PREVIEW_MPHP_FRM_BUFFER_WIDTH  (H264_DEC_MAX_NORMAL_WIDTH_MPHP)
            #define H264_PREVIEW_MPHP_FRM_BUFFER_HEIGHT  (H264_DEC_MAX_NORMAL_HEIGHT_MPHP)
        #endif

        #define H264_PREVIEW_MPHP_DEC_DPB_SIZE H264_PREVIEW_MPHP_FRM_BUFFER_SIZE

        #define H264_PREVIEW_MPHP_FRM_BUFFER_SIZE_CACHE_LINE \
                ALIGN_X((H264_PREVIEW_MPHP_FRM_BUFFER_SIZE+GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #endif  // #ifdef __H264_DEC_SW_SUPPORT_MAINHIGH__
    // MPHP -


    // Comparision +
    #ifdef __H264_DEC_SW_SUPPORT_MAINHIGH__
        // Compare frame buffer
        #if ( (H264_PREVIEW_MPHP_FRM_BUFFER_SIZE) > (H264_PREVIEW_BP_FRM_BUFFER_SIZE) )
            #define H264_PREVIEW_FRM_BUFFER_SIZE (H264_PREVIEW_MPHP_FRM_BUFFER_SIZE)
            #define H264_PREVIEW_FRM_BUFFER_WIDTH  (H264_MPHP_DEC_MAX_HALF_WIDTH_ALIGN)
            #define H264_PERVIEW_FRM_BUFFER_HEIGHT  (H264_MPHP_DEC_MAX_HALF_HEIGHT_ALIGN)
        #else
            #define H264_PREVIEW_FRM_BUFFER_SIZE (H264_PREVIEW_BP_FRM_BUFFER_SIZE)
            #define H264_PREVIEW_FRM_BUFFER_WIDTH  (H264_BP_DEC_MAX_HALF_WIDTH_ALIGN)
            #define H264_PERVIEW_FRM_BUFFER_HEIGHT  (H264_BP_DEC_MAX_HALF_HEIGHT_ALIGN)
        #endif
    #else  // #ifdef __H264_DEC_SW_SUPPORT_MAINHIGH__
        #define H264_PREVIEW_FRM_BUFFER_SIZE (H264_PREVIEW_BP_FRM_BUFFER_SIZE)
        #define H264_PREVIEW_FRM_BUFFER_WIDTH  (H264_BP_DEC_MAX_HALF_WIDTH_ALIGN)
        #define H264_PERVIEW_FRM_BUFFER_HEIGHT  (H264_BP_DEC_MAX_HALF_HEIGHT_ALIGN)
    #endif  // #ifdef __H264_DEC_SW_SUPPORT_MAINHIGH__


    #ifdef H264_PREVIEW_DEC_DPB_SIZE
    #undef H264_PREVIEW_DEC_DPB_SIZE
    #endif

    #define H264_PREVIEW_DEC_DPB_SIZE H264_PREVIEW_FRM_BUFFER_SIZE

    #define H264_PREVIEW_FRM_BUFFER_SIZE_CACHE_LINE \
            ALIGN_X((H264_PREVIEW_FRM_BUFFER_SIZE+GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)
    // Comparision -

    // Decision +
    // Get the max preview working memory
    #ifdef __H264_DEC_SW_SUPPORT_MAINHIGH__
        #if (H264_DEC_MAX_WORKING_PREVMEM_MPHP > H264_DEC_MAX_WORKING_PREVMEM_BP)
            #define H264_PREVIEW_WORKING_MEM_SIZE_CACHE_LINE ALIGN_X((H264_DEC_MAX_WORKING_PREVMEM_MPHP+CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)
        #else
            #define H264_PREVIEW_WORKING_MEM_SIZE_CACHE_LINE ALIGN_X((H264_DEC_MAX_WORKING_PREVMEM_BP+CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)
        #endif
    #else  // __H264_DEC_SW_SUPPORT_MAINHIGH__
        #define H264_PREVIEW_WORKING_MEM_SIZE_CACHE_LINE ALIGN_X((H264_DEC_MAX_WORKING_PREVMEM_BP+CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)
    #endif  // #ifdef __H264_DEC_SW_SUPPORT_MAINHIGH__

    #if ( (H264_PREVIEW_FRM_BUFFER_SIZE_CACHE_LINE+H264_PREVIEW_WORKING_MEM_SIZE_CACHE_LINE) > PREVIEW_TEMP_TOTAL_MEM_SIZE)
        #undef PREVIEW_TEMP_TOTAL_MEM_SIZE
        #undef PREVIEW_FRM_BUFFER_SIZE
        #undef PREVIEW_CODEC_WORKING_MEM_SIZE
        #define PREVIEW_TEMP_TOTAL_MEM_SIZE (H264_PREVIEW_FRM_BUFFER_SIZE_CACHE_LINE+H264_PREVIEW_WORKING_MEM_SIZE_CACHE_LINE)
        #define PREVIEW_FRM_BUFFER_SIZE H264_PREVIEW_FRM_BUFFER_SIZE_CACHE_LINE
        #define PREVIEW_CODEC_WORKING_MEM_SIZE H264_DEC_WORKING_MEM// Fix it. it should be H264_PREVIEW_WORKING_MEM_SIZE_CACHE_LINE

        #undef PREVIEW_MAX_CONSUMPTION
        #ifdef __H264_DEC_SW_SUPPORT_MAINHIGH__
            #if (H264_PREVIEW_MPHP_FRM_BUFFER_SIZE + H264_DEC_MAX_WORKING_PREVMEM_MPHP > H264_PREVIEW_BP_FRM_BUFFER_SIZE + H264_DEC_MAX_WORKING_PREVMEM_BP)
                #define PREVIEW_MAX_CONSUMPTION H264_MPHP_CODEC
            #else
                #define PREVIEW_MAX_CONSUMPTION H264_BP_CODEC
            #endif
        #else
            #define PREVIEW_MAX_CONSUMPTION H264_BP_CODEC
        #endif  // __H264_DEC_SW_SUPPORT_MAINHIGH__

    #endif
    // Decision -
#endif  /* #if (defined (__VE_H264_DEC_SW_SUPPORT__) || (__VE_H264_DEC_HW_SUPPORT__)) */


#ifdef __VE_RV_DEC_SW_SUPPORT__
    #if (RV9_EXTRA_BUFFER_NUM < 0)
    #error "PREVIEW Scenario: Extra frame number of RV decoder should be no bigger than or equal to 0"
    #endif

    #define RV9_PREVIEW_FAST_MODE_BUFFER_SIZE ((RV9_DEC_MAX_HALF_WIDTH_ALIGN * RV9_DEC_MAX_HALF_HEIGHT_ALIGN * (RV9_PREVIEW_EXTRA_BUFFER_NUM + RM_DECODER_PREVIEW_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (2*16*RV9_DEC_MAX_HALF_WIDTH_ALIGN) + (CPU_CACHE_LINE_SIZE_MINE*2))
    #define RV9_PREVIEW_NORMAL_BUFFER_SIZE (((RV9_DEC_MAX_NORMAL_WIDTH) * (RV9_DEC_MAX_NORMAL_HEIGHT) * (RV9_PREVIEW_EXTRA_BUFFER_NUM + RM_DECODER_PREVIEW_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (2*16*RV9_DEC_MAX_NORMAL_WIDTH) + (CPU_CACHE_LINE_SIZE_MINE*2))

    #if (RV9_PREVIEW_FAST_MODE_BUFFER_SIZE > RV9_PREVIEW_NORMAL_BUFFER_SIZE)
        #define RV9_PREVIEW_FRM_BUFFER_SIZE (RV9_PREVIEW_FAST_MODE_BUFFER_SIZE)
        #define RV9_PREVIEW_ONE_FRM_BUFFER_SIZE  (RV9_DEC_MAX_HALF_WIDTH_ALIGN * RV9_DEC_MAX_HALF_HEIGHT_ALIGN * 3 / 2)
        #define RV9_PREVIEW_FRM_BUFFER_WIDTH  (RV9_DEC_MAX_HALF_WIDTH_ALIGN)
        #define RV9_PREVIEW_FRM_BUFFER_HEIGHT  (RV9_DEC_MAX_HALF_HEIGHT_ALIGN)
    #else
        #define RV9_PREVIEW_FRM_BUFFER_SIZE (RV9_PREVIEW_NORMAL_BUFFER_SIZE)
        #define RV9_PREVIEW_ONE_FRM_BUFFER_SIZE  (RV9_DEC_MAX_NORMAL_WIDTH * RV9_DEC_MAX_NORMAL_HEIGHT * 3 / 2)
        #define RV9_PREVIEW_FRM_BUFFER_WIDTH  (RV9_DEC_MAX_NORMAL_WIDTH)
        #define RV9_PREVIEW_FRM_BUFFER_HEIGHT  (RV9_DEC_MAX_NORMAL_HEIGHT)
    #endif

    #define RV9_PREVIEW_FRM_BUFFER_SIZE_CACHE_LINE ALIGN_X((RV9_PREVIEW_FRM_BUFFER_SIZE+GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define RV9_PREVIEW_WORKING_MEM_SIZE_CACHE_LINE ALIGN_X((RV9_PREVIEW_DEC_WORKING_MEM+CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ( (RV9_PREVIEW_FRM_BUFFER_SIZE_CACHE_LINE+RV9_PREVIEW_WORKING_MEM_SIZE_CACHE_LINE) > PREVIEW_TEMP_TOTAL_MEM_SIZE)
        #undef PREVIEW_TEMP_TOTAL_MEM_SIZE
        #undef PREVIEW_FRM_BUFFER_SIZE
        #undef PREVIEW_CODEC_WORKING_MEM_SIZE
        #define PREVIEW_TEMP_TOTAL_MEM_SIZE (RV9_PREVIEW_FRM_BUFFER_SIZE_CACHE_LINE+RV9_PREVIEW_WORKING_MEM_SIZE_CACHE_LINE)
        #define PREVIEW_FRM_BUFFER_SIZE RV9_PREVIEW_FRM_BUFFER_SIZE_CACHE_LINE
        #define PREVIEW_CODEC_WORKING_MEM_SIZE RV9_PREVIEW_WORKING_MEM_SIZE_CACHE_LINE

        #undef PREVIEW_MAX_CONSUMPTION
        #define PREVIEW_MAX_CONSUMPTION RV_CODEC
    #endif
#endif  /* __VE_RV_DEC_SW_SUPPORT__ */


#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
    #define MJPEG_PREVIEW_FAST_MODE_BUFFER_SIZE ((MJPEG_DEC_MAX_QUARTER_WIDTH_ALIGN * MJPEG_DEC_MAX_QUARTER_HEIGHT_ALIGN * (MJPEG_PREVIEW_EXTRA_BUFFER_NUM + DECODER_PREVIEW_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE*2))
    #define MJPEG_PREVIEW_QTY_MODE_BUFFER_SIZE ((MJPEG_DEC_MAX_HALF_WIDTH_ALIGN * MJPEG_DEC_MAX_HALF_HEIGHT_ALIGN * (MJPEG_PREVIEW_EXTRA_BUFFER_NUM + DECODER_PREVIEW_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE*2))
    #define MJPEG_PREVIEW_NORMAL_BUFFER_SIZE (((MJPEG_DEC_MAX_NORMAL_WIDTH) * (MJPEG_DEC_MAX_NORMAL_HEIGHT) * (MJPEG_PREVIEW_EXTRA_BUFFER_NUM + DECODER_PREVIEW_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE*2))

    #if (MJPEG_PREVIEW_FAST_MODE_BUFFER_SIZE > MJPEG_PREVIEW_QTY_MODE_BUFFER_SIZE)
        #define MJPEG_PREVIEW_BUFFER_SIZE (MJPEG_PREVIEW_FAST_MODE_BUFFER_SIZE)
    #elif (MJPEG_PREVIEW_QTY_MODE_BUFFER_SIZE > MJPEG_PREVIEW_NORMAL_BUFFER_SIZE)
        #define MJPEG_PREVIEW_BUFFER_SIZE (MJPEG_PREVIEW_QTY_MODE_BUFFER_SIZE)
    #else
        #define MJPEG_PREVIEW_BUFFER_SIZE (MJPEG_PREVIEW_NORMAL_BUFFER_SIZE)
    #endif

    #define MJPEG_PREVIEW_FRM_BUFFER_SIZE_CACHE_LINE ALIGN_X((MJPEG_PREVIEW_BUFFER_SIZE+GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)
    #define MJPEG_PREVIEW_WORKING_MEM_SIZE_CACHE_LINE ALIGN_X((MJPEG_PREVIEW_DEC_WORKING_MEM+CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ( (MJPEG_PREVIEW_FRM_BUFFER_SIZE_CACHE_LINE+MJPEG_PREVIEW_WORKING_MEM_SIZE_CACHE_LINE) > PREVIEW_TEMP_TOTAL_MEM_SIZE)
        #undef PREVIEW_TEMP_TOTAL_MEM_SIZE
        #undef PREVIEW_FRM_BUFFER_SIZE
        #undef PREVIEW_CODEC_WORKING_MEM_SIZE
        #define PREVIEW_TEMP_TOTAL_MEM_SIZE (MJPEG_PREVIEW_FRM_BUFFER_SIZE_CACHE_LINE+MJPEG_PREVIEW_WORKING_MEM_SIZE_CACHE_LINE)
        #define PREVIEW_FRM_BUFFER_SIZE MJPEG_PREVIEW_FRM_BUFFER_SIZE_CACHE_LINE
        #define PREVIEW_CODEC_WORKING_MEM_SIZE MJPEG_PREVIEW_WORKING_MEM_SIZE_CACHE_LINE

        #undef PREVIEW_MAX_CONSUMPTION
        #define PREVIEW_MAX_CONSUMPTION MJPG_CODEC
    #endif
#endif  /* __VE_MJPEG_DEC_SW_SUPPORT__ */


#ifdef __VE_VP8_DEC_SW_SUPPORT__
    #if (VP8_PREVIEW_EXTRA_BUFFER_NUM < 0)
        #error "PREVIEW Scenario:Extra frame number of VP8 decoder should be no bigger than or equal to 0"
    #endif

    #define VP8_PREVIEW_FAST_MODE_BUFFER_SIZE ((ALIGN_X((VP8_DEC_MAX_HALF_WIDTH_ALIGN+VP8_PADDING_SIZE), 32) * ALIGN_X((VP8_DEC_MAX_HALF_HEIGHT_ALIGN+VP8_PADDING_SIZE), 32) * (VP8_PREVIEW_EXTRA_BUFFER_NUM + DECODER_PREVIEW_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE*2))
    #define VP8_PREVIEW_NORMAL_BUFFER_SIZE (ALIGN_X((VP8_DEC_MAX_NORMAL_WIDTH+VP8_PADDING_SIZE), 32) * ALIGN_X((VP8_DEC_MAX_NORMAL_HEIGHT+VP8_PADDING_SIZE), 32) * (VP8_PREVIEW_EXTRA_BUFFER_NUM + DECODER_PREVIEW_ESSENTIAL_BUFFER_NUM) * 3 / 2 + (CPU_CACHE_LINE_SIZE_MINE*2))

    #if (VP8_PREVIEW_FAST_MODE_BUFFER_SIZE > VP8_PREVIEW_NORMAL_BUFFER_SIZE)
        #define VP8_PREVIEW_FRM_BUFFER_SIZE (VP8_PREVIEW_FAST_MODE_BUFFER_SIZE)
        #define VP8_PREVIEW_ONE_FRM_BUFFER_SIZE  (ALIGN_X((VP8_DEC_MAX_HALF_WIDTH_ALIGN+VP8_PADDING_SIZE), 32) * ALIGN_X((VP8_DEC_MAX_HALF_HEIGHT_ALIGN+VP8_PADDING_SIZE), 32) * 3 / 2)
        #define VP8_PREVIEW_FRM_BUFFER_WIDTH  ALIGN_X((VP8_DEC_MAX_HALF_WIDTH_ALIGN+VP8_PADDING_SIZE), 32)
        #define VP8_PREVIEW_FRM_BUFFER_HEIGHT  ALIGN_X((VP8_DEC_MAX_HALF_HEIGHT_ALIGN+VP8_PADDING_SIZE), 32)
    #else
        #define VP8_PREVIEW_FRM_BUFFER_SIZE (VP8_PREVIEW_NORMAL_BUFFER_SIZE)
        #define VP8_PREVIEW_ONE_FRM_BUFFER_SIZE  (ALIGN_X((VP8_DEC_MAX_NORMAL_WIDTH+VP8_PADDING_SIZE), 32) * ALIGN_X((VP8_DEC_MAX_NORMAL_HEIGHT+VP8_PADDING_SIZE), 32) * 3 / 2)
        #define VP8_PREVIEW_FRM_BUFFER_WIDTH  ALIGN_X((VP8_DEC_MAX_NORMAL_WIDTH+VP8_PADDING_SIZE), 32)
        #define VP8_PREVIEW_FRM_BUFFER_HEIGHT  ALIGN_X((VP8_DEC_MAX_NORMAL_HEIGHT+VP8_PADDING_SIZE), 32)
    #endif

    #define VP8_PREVIEW_FRM_BUFFER_SIZE_CACHE_LINE ALIGN_X((VP8_PREVIEW_FRM_BUFFER_SIZE+GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define VP8_PREVIEW_WORKING_MEM_SIZE_CACHE_LINE ALIGN_X((VP8_PREVIEW_DEC_WORKING_MEM+CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ( (VP8_PREVIEW_FRM_BUFFER_SIZE_CACHE_LINE + VP8_PREVIEW_WORKING_MEM_SIZE_CACHE_LINE) > PREVIEW_TEMP_TOTAL_MEM_SIZE)
        #undef PREVIEW_TEMP_TOTAL_MEM_SIZE
        #undef PREVIEW_FRM_BUFFER_SIZE
        #undef PREVIEW_CODEC_WORKING_MEM_SIZE
        #define PREVIEW_TEMP_TOTAL_MEM_SIZE (VP8_PREVIEW_FRM_BUFFER_SIZE_CACHE_LINE + VP8_PREVIEW_WORKING_MEM_SIZE_CACHE_LINE)
        #define PREVIEW_FRM_BUFFER_SIZE VP8_PREVIEW_FRM_BUFFER_SIZE_CACHE_LINE
        #define PREVIEW_CODEC_WORKING_MEM_SIZE VP8_PREVIEW_WORKING_MEM_SIZE_CACHE_LINE

        #undef PREVIEW_MAX_CONSUMPTION
        #define PREVIEW_MAX_CONSUMPTION VP8_CODEC
    #endif
#endif  /* defined(__VE_VP8_DEC_SW_SUPPORT__) */


#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__) || defined (__VE_H264_DEC_SW_SUPPORT__) \
       || defined(__VE_H264_DEC_HW_SUPPORT__) || defined(__VE_RV_DEC_SW_SUPPORT__) || defined(__VE_MJPEG_DEC_SW_SUPPORT__) \
       || defined(__VE_VP8_DEC_SW_SUPPORT__))

    #if (PREVIEW_FRM_BUFFER_SIZE == 0)
        #error "PREVIEW Scenario: Cannot decide the size of frame buffer, no codec is enable"
    #endif
#endif


//Temp solution
//#define DECODER_QVGA_MEM_SIZE (QVGA_FRM_BUFFER_SIZE + VIDEO_DEC_WORKING_MEM_SIZE + QVGA_CODEC_WORKING_MEM_SIZE)
#define DECODER_PREVIEW_MEM_SIZE (PREVIEW_FRM_BUFFER_SIZE + VIDEO_EXTRA_MEM_SIZE + VIDEO_DEC_WORKING_MEM_SIZE + PREVIEW_CODEC_WORKING_MEM_SIZE)

/***************************************
*   QCIF Scenario
*   Decide the size of frame buffer & the working memory of codec
*   Assumption: YUV420 format
***************************************/
#define QCIF_FRM_BUFFER_SIZE             0
#define QCIF_CODEC_WORKING_MEM_SIZE      0
#define QCIF_TEMP_TOTAL_MEM_SIZE         0

#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    #if (MPEG4_QCIF_EXTRA_BUFFER_NUM < 0)
    #error "QCIF Scenario: Extra frame number of MPEG4 decoder should be no bigger than or equal to 0"
    #endif

    #define MPEG4_QCIF_NORMAL_BUFFER_SIZE (MPEG4_QCIF_DEC_MAX_WIDTH * MPEG4_QCIF_DEC_MAX_HEIGHT * (MPEG4_QCIF_EXTRA_BUFFER_NUM + DECODER_ESSENTIAL_BUFFER_NUM) * 3 / 2 + (CPU_CACHE_LINE_SIZE_MINE*2))

    #define MPEG4_QCIF_FRM_BUFFER_SIZE_CACHE_LINE \
            ALIGN_X((MPEG4_QCIF_NORMAL_BUFFER_SIZE + GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define MPEG4_QCIF_WORKING_MEM_SIZE_CACHE_LINE \
            ALIGN_X((MPEG4_QCIF_DEC_WORKING_MEM + CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ((MPEG4_QCIF_FRM_BUFFER_SIZE_CACHE_LINE + MPEG4_QCIF_WORKING_MEM_SIZE_CACHE_LINE) > QCIF_TEMP_TOTAL_MEM_SIZE)
        #undef QCIF_TEMP_TOTAL_MEM_SIZE
        #undef QCIF_FRM_BUFFER_SIZE
        #undef QCIF_CODEC_WORKING_MEM_SIZE
        #define QCIF_TEMP_TOTAL_MEM_SIZE    (MPEG4_QCIF_FRM_BUFFER_SIZE_CACHE_LINE+MPEG4_QCIF_WORKING_MEM_SIZE_CACHE_LINE)
        #define QCIF_FRM_BUFFER_SIZE        MPEG4_QCIF_FRM_BUFFER_SIZE_CACHE_LINE
        #define QCIF_CODEC_WORKING_MEM_SIZE MPEG4_QCIF_WORKING_MEM_SIZE_CACHE_LINE
    #endif
#endif  /* (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__)) */


#if (defined (__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    #if (H264_QCIF_EXTRA_BUFFER_NUM < 0)
    #error "QCIF Scenario: Extra frame number of H264 decoder should be no bigger than or equal to 0"
    #endif

    #define H264_QCIF_NORMAL_BUFFER_SIZE (H264_QCIF_DEC_MAX_WIDTH * H264_QCIF_DEC_MAX_HEIGHT * (H264_QCIF_EXTRA_BUFFER_NUM + DECODER_ESSENTIAL_BUFFER_NUM) * 3 / 2 + (CPU_CACHE_LINE_SIZE_MINE*2))
    #define H264_QCIF_3_FRM_SIZE    (3 * H264_QCIF_DEC_MAX_WIDTH * H264_QCIF_DEC_MAX_HEIGHT * 3 / 2)

    #if ((H264_QCIF_EXTRA_BUFFER_NUM + DECODER_ESSENTIAL_BUFFER_NUM) < 19)
        #if ((H264_QCIF_DEC_DPB_SIZE + H264_QCIF_3_FRM_SIZE) > H264_QCIF_NORMAL_BUFFER_SIZE)
            #error "QCIF Scenario: Frame buffer size is smaller than the level specified. Please either increase the frame number or raise the level."
        #else
            #undef H264_QCIF_DEC_DPB_SIZE
            #define H264_QCIF_DEC_DPB_SIZE H264_QCIF_NORMAL_BUFFER_SIZE
        #endif
    #else
        #undef H264_QCIF_DEC_DPB_SIZE
        #define H264_QCIF_DEC_DPB_SIZE H264_QCIF_NORMAL_BUFFER_SIZE
    #endif

    #define H264_QCIF_FRM_BUFFER_SIZE_CACHE_LINE \
            ALIGN_X((H264_QCIF_NORMAL_BUFFER_SIZE+GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define H264_QCIF_WORKING_MEM_SIZE_CACHE_LINE \
            ALIGN_X((H264_QCIF_DEC_WORKING_MEM+CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ( (H264_QCIF_FRM_BUFFER_SIZE_CACHE_LINE+H264_QCIF_WORKING_MEM_SIZE_CACHE_LINE) > QCIF_TEMP_TOTAL_MEM_SIZE)
        #undef QCIF_TEMP_TOTAL_MEM_SIZE
        #undef QCIF_FRM_BUFFER_SIZE
        #undef QCIF_CODEC_WORKING_MEM_SIZE
        #define QCIF_TEMP_TOTAL_MEM_SIZE    (H264_QCIF_FRM_BUFFER_SIZE_CACHE_LINE + H264_QCIF_WORKING_MEM_SIZE_CACHE_LINE)
        #define QCIF_FRM_BUFFER_SIZE        H264_QCIF_FRM_BUFFER_SIZE_CACHE_LINE
        #define QCIF_CODEC_WORKING_MEM_SIZE H264_QCIF_WORKING_MEM_SIZE_CACHE_LINE
    #endif
#endif  /* #if (defined (__VE_H264_DEC_SW_SUPPORT__) || (__VE_H264_DEC_HW_SUPPORT__)) */


#ifdef __VE_RV_DEC_SW_SUPPORT__
    #if (RV9_QCIF_EXTRA_BUFFER_NUM < 0)
    #error "QCIF Scenario: Extra frame number of RV decoder should be no bigger than or equal to 0"
    #endif

    #define RV9_QCIF_NORMAL_BUFFER_SIZE (((RV9_QCIF_DEC_MAX_WIDTH) * (RV9_QCIF_DEC_MAX_HEIGHT) * (RV9_QCIF_EXTRA_BUFFER_NUM + RM_DECODER_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (2*16*RV9_QCIF_DEC_MAX_WIDTH) + (CPU_CACHE_LINE_SIZE_MINE*2))

    #define RV9_QCIF_FRM_BUFFER_SIZE_CACHE_LINE \
            ALIGN_X((RV9_QCIF_NORMAL_BUFFER_SIZE + GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define RV9_QCIF_WORKING_MEM_SIZE_CACHE_LINE \
            ALIGN_X((RV9_QCIF_DEC_WORKING_MEM + CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ( (RV9_QCIF_FRM_BUFFER_SIZE_CACHE_LINE + RV9_QCIF_WORKING_MEM_SIZE_CACHE_LINE) > QCIF_TEMP_TOTAL_MEM_SIZE)
        #undef QCIF_TEMP_TOTAL_MEM_SIZE
        #undef QCIF_FRM_BUFFER_SIZE
        #undef QCIF_CODEC_WORKING_MEM_SIZE
        #define QCIF_TEMP_TOTAL_MEM_SIZE    (RV9_QCIF_FRM_BUFFER_SIZE_CACHE_LINE + RV9_QCIF_WORKING_MEM_SIZE_CACHE_LINE)
        #define QCIF_FRM_BUFFER_SIZE        RV9_QCIF_FRM_BUFFER_SIZE_CACHE_LINE
        #define QCIF_CODEC_WORKING_MEM_SIZE RV9_QCIF_WORKING_MEM_SIZE_CACHE_LINE
    #endif
#endif  /* __VE_RV_DEC_SW_SUPPORT__ */


#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
    #define MJPEG_QCIF_BUFFER_SIZE (((MJPEG_QCIF_DEC_MAX_WIDTH) * (MJPEG_QCIF_DEC_MAX_HEIGHT) * (MJPEG_QCIF_EXTRA_BUFFER_NUM + DECODER_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE*2))

    #define MJPEG_QCIF_FRM_BUFFER_SIZE_CACHE_LINE \
            ALIGN_X((MJPEG_QCIF_BUFFER_SIZE + GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define MJPEG_QCIF_WORKING_MEM_SIZE_CACHE_LINE \
            ALIGN_X((MJPEG_QCIF_DEC_WORKING_MEM + CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ( (MJPEG_QCIF_FRM_BUFFER_SIZE_CACHE_LINE + MJPEG_QCIF_WORKING_MEM_SIZE_CACHE_LINE) > QCIF_TEMP_TOTAL_MEM_SIZE)
        #undef QCIF_TEMP_TOTAL_MEM_SIZE
        #undef QCIF_FRM_BUFFER_SIZE
        #undef QCIF_CODEC_WORKING_MEM_SIZE
        #define QCIF_TEMP_TOTAL_MEM_SIZE    (MJPEG_QCIF_FRM_BUFFER_SIZE_CACHE_LINE + MJPEG_QCIF_WORKING_MEM_SIZE_CACHE_LINE)
        #define QCIF_FRM_BUFFER_SIZE        MJPEG_QCIF_FRM_BUFFER_SIZE_CACHE_LINE
        #define QCIF_CODEC_WORKING_MEM_SIZE MJPEG_QCIF_WORKING_MEM_SIZE_CACHE_LINE
    #endif
#endif  /* __VE_MJPEG_DEC_SW_SUPPORT__ */


#if defined(__VE_VP8_DEC_SW_SUPPORT__)
    #if (VP8_QCIF_EXTRA_BUFFER_NUM < 0)
        #error "QCIF Scenario: Extra frame number of VP8 decoder should be no bigger than or equal to 0"
    #endif

    #define VP8_QCIF_NORMAL_BUFFER_SIZE (ALIGN_X((VP8_QCIF_DEC_MAX_WIDTH+VP8_PADDING_SIZE), 32) * ALIGN_X((VP8_QCIF_DEC_MAX_HEIGHT+VP8_PADDING_SIZE), 32) * (VP8_QCIF_EXTRA_BUFFER_NUM + VP8_DECODER_ESSENTIAL_BUFFER_NUM) * 3 / 2 + (CPU_CACHE_LINE_SIZE_MINE*2))

    #define VP8_QCIF_FRM_BUFFER_SIZE_CACHE_LINE ALIGN_X((VP8_QCIF_NORMAL_BUFFER_SIZE+GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define VP8_QCIF_WORKING_MEM_SIZE_CACHE_LINE ALIGN_X((VP8_QCIF_DEC_WORKING_MEM+CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ( (VP8_QCIF_FRM_BUFFER_SIZE_CACHE_LINE + VP8_QCIF_WORKING_MEM_SIZE_CACHE_LINE) > QCIF_TEMP_TOTAL_MEM_SIZE)
        #undef QCIF_TEMP_TOTAL_MEM_SIZE
        #undef QCIF_FRM_BUFFER_SIZE
        #undef QCIF_CODEC_WORKING_MEM_SIZE
        #define QCIF_TEMP_TOTAL_MEM_SIZE    (VP8_QCIF_FRM_BUFFER_SIZE_CACHE_LINE + VP8_QCIF_WORKING_MEM_SIZE_CACHE_LINE)
        #define QCIF_FRM_BUFFER_SIZE        VP8_QCIF_FRM_BUFFER_SIZE_CACHE_LINE
        #define QCIF_CODEC_WORKING_MEM_SIZE VP8_QCIF_WORKING_MEM_SIZE_CACHE_LINE
    #endif
#endif  /* defined(__VE_VP8_DEC_SW_SUPPORT__) */


#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__) || defined (__VE_H264_DEC_SW_SUPPORT__) \
       || defined(__VE_H264_DEC_HW_SUPPORT__) || defined(__VE_RV_DEC_SW_SUPPORT__) || defined(__VE_MJPEG_DEC_SW_SUPPORT__)\
       || defined(__VE_VP8_DEC_SW_SUPPORT__))

    #if (QCIF_FRM_BUFFER_SIZE == 0)
        #error "QCIF Scenario: Cannot decide the size of frame buffer, no codec is enable"
    #endif
#endif


//Temp solution
#define DECODER_QCIF_MEM_SIZE (QCIF_FRM_BUFFER_SIZE + VIDEO_EXTRA_MEM_SIZE + VIDEO_DEC_WORKING_MEM_SIZE + QCIF_CODEC_WORKING_MEM_SIZE)

/***************************************
*   VGA Scenario
*   Decide the size of frame buffer & the working memory of codec
*   Assumption: YUV420 format
***************************************/
#define VGA_FRM_BUFFER_SIZE             0
#define VGA_CODEC_WORKING_MEM_SIZE      0
#define VGA_TEMP_TOTAL_MEM_SIZE         0

#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    #if (MPEG4_VGA_EXTRA_BUFFER_NUM < 0)
    #error "VGA Scenario: Extra frame number of MPEG4 decoder should be no bigger than or equal to 0"
    #endif

    #define MPEG4_VGA_NORMAL_BUFFER_SIZE (MPEG4_VGA_DEC_MAX_WIDTH * MPEG4_VGA_DEC_MAX_HEIGHT * (MPEG4_VGA_EXTRA_BUFFER_NUM + DECODER_ESSENTIAL_BUFFER_NUM) * 3 / 2 + (CPU_CACHE_LINE_SIZE_MINE*2))

    #define MPEG4_VGA_FRM_BUFFER_SIZE_CACHE_LINE \
            ALIGN_X((MPEG4_VGA_NORMAL_BUFFER_SIZE + GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define MPEG4_VGA_WORKING_MEM_SIZE_CACHE_LINE \
            ALIGN_X((MPEG4_VGA_DEC_WORKING_MEM + CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ( (MPEG4_VGA_FRM_BUFFER_SIZE_CACHE_LINE + MPEG4_VGA_WORKING_MEM_SIZE_CACHE_LINE) > VGA_TEMP_TOTAL_MEM_SIZE)
        #undef VGA_TEMP_TOTAL_MEM_SIZE
        #undef VGA_FRM_BUFFER_SIZE
        #undef VGA_CODEC_WORKING_MEM_SIZE
        #define VGA_TEMP_TOTAL_MEM_SIZE     (MPEG4_VGA_FRM_BUFFER_SIZE_CACHE_LINE+MPEG4_VGA_WORKING_MEM_SIZE_CACHE_LINE)
        #define VGA_FRM_BUFFER_SIZE         MPEG4_VGA_FRM_BUFFER_SIZE_CACHE_LINE
        #define VGA_CODEC_WORKING_MEM_SIZE  MPEG4_VGA_WORKING_MEM_SIZE_CACHE_LINE
    #endif
#endif  /* (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__)) */


#if (defined (__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    #if (H264_VGA_EXTRA_BUFFER_NUM < 0)
    #error "VGA Scenario: Extra frame number of H264 decoder should be no bigger than or equal to 0"
    #endif

    #define H264_VGA_NORMAL_BUFFER_SIZE (H264_VGA_DEC_MAX_WIDTH * H264_VGA_DEC_MAX_HEIGHT * (H264_VGA_EXTRA_BUFFER_NUM + DECODER_ESSENTIAL_BUFFER_NUM) * 3 / 2 + (CPU_CACHE_LINE_SIZE_MINE*2))
    #define H264_VGA_3_FRM_SIZE    (3 * H264_VGA_DEC_MAX_WIDTH * H264_VGA_DEC_MAX_HEIGHT * 3 / 2)

    #if ((H264_VGA_EXTRA_BUFFER_NUM + DECODER_ESSENTIAL_BUFFER_NUM) < 19)
        #if ((H264_VGA_DEC_DPB_SIZE + H264_VGA_3_FRM_SIZE) > H264_VGA_NORMAL_BUFFER_SIZE)
            #error "VGA Scenario: Frame buffer size is smaller than the level specified. Please either increase the frame number or raise the level."
        #else
            #undef H264_VGA_DEC_DPB_SIZE
            #define H264_VGA_DEC_DPB_SIZE H264_VGA_NORMAL_BUFFER_SIZE
        #endif
    #else
        #undef H264_VGA_DEC_DPB_SIZE
        #define H264_VGA_DEC_DPB_SIZE H264_VGA_NORMAL_BUFFER_SIZE
    #endif

    #define H264_VGA_FRM_BUFFER_SIZE_CACHE_LINE \
            ALIGN_X((H264_VGA_NORMAL_BUFFER_SIZE+GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define H264_VGA_WORKING_MEM_SIZE_CACHE_LINE \
            ALIGN_X((H264_VGA_DEC_WORKING_MEM+CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ( (H264_VGA_FRM_BUFFER_SIZE_CACHE_LINE+H264_VGA_WORKING_MEM_SIZE_CACHE_LINE) > VGA_TEMP_TOTAL_MEM_SIZE)
        #undef VGA_TEMP_TOTAL_MEM_SIZE
        #undef VGA_FRM_BUFFER_SIZE
        #undef VGA_CODEC_WORKING_MEM_SIZE
        #define VGA_TEMP_TOTAL_MEM_SIZE     (H264_VGA_FRM_BUFFER_SIZE_CACHE_LINE+H264_VGA_WORKING_MEM_SIZE_CACHE_LINE)
        #define VGA_FRM_BUFFER_SIZE         H264_VGA_FRM_BUFFER_SIZE_CACHE_LINE
        #define VGA_CODEC_WORKING_MEM_SIZE  H264_VGA_WORKING_MEM_SIZE_CACHE_LINE
    #endif
#endif  /* #if (defined (__VE_H264_DEC_SW_SUPPORT__) || (__VE_H264_DEC_HW_SUPPORT__)) */


#ifdef __VE_RV_DEC_SW_SUPPORT__
    #if (RV9_VGA_EXTRA_BUFFER_NUM < 0)
    #error "VGA Scenario: Extra frame number of RV decoder should be no bigger than or equal to 0"
    #endif

    #define RV9_VGA_NORMAL_BUFFER_SIZE (((RV9_VGA_DEC_MAX_WIDTH) * (RV9_VGA_DEC_MAX_HEIGHT) * (RV9_VGA_EXTRA_BUFFER_NUM + RM_DECODER_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (2*16*RV9_VGA_DEC_MAX_WIDTH) + (CPU_CACHE_LINE_SIZE_MINE*2))

    #define RV9_VGA_FRM_BUFFER_SIZE_CACHE_LINE \
            ALIGN_X((RV9_VGA_NORMAL_BUFFER_SIZE + GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define RV9_VGA_WORKING_MEM_SIZE_CACHE_LINE \
            ALIGN_X((RV9_VGA_DEC_WORKING_MEM + CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ( (RV9_VGA_FRM_BUFFER_SIZE_CACHE_LINE + RV9_VGA_WORKING_MEM_SIZE_CACHE_LINE) > VGA_TEMP_TOTAL_MEM_SIZE)
        #undef VGA_TEMP_TOTAL_MEM_SIZE
        #undef VGA_FRM_BUFFER_SIZE
        #undef VGA_CODEC_WORKING_MEM_SIZE
        #define VGA_TEMP_TOTAL_MEM_SIZE     (RV9_VGA_FRM_BUFFER_SIZE_CACHE_LINE+RV9_VGA_WORKING_MEM_SIZE_CACHE_LINE)
        #define VGA_FRM_BUFFER_SIZE         RV9_VGA_FRM_BUFFER_SIZE_CACHE_LINE
        #define VGA_CODEC_WORKING_MEM_SIZE  RV9_VGA_WORKING_MEM_SIZE_CACHE_LINE
    #endif
#endif  /* __VE_RV_DEC_SW_SUPPORT__ */


#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
    #define MJPEG_VGA_BUFFER_SIZE (((MJPEG_VGA_DEC_MAX_WIDTH) * (MJPEG_VGA_DEC_MAX_HEIGHT) * (MJPEG_VGA_EXTRA_BUFFER_NUM + DECODER_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE*2))

    #define MJPEG_VGA_FRM_BUFFER_SIZE_CACHE_LINE \
            ALIGN_X((MJPEG_VGA_BUFFER_SIZE + GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define MJPEG_VGA_WORKING_MEM_SIZE_CACHE_LINE \
            ALIGN_X((MJPEG_VGA_DEC_WORKING_MEM + CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ( (MJPEG_VGA_FRM_BUFFER_SIZE_CACHE_LINE + MJPEG_VGA_WORKING_MEM_SIZE_CACHE_LINE) > VGA_TEMP_TOTAL_MEM_SIZE)
        #undef VGA_TEMP_TOTAL_MEM_SIZE
        #undef VGA_FRM_BUFFER_SIZE
        #undef VGA_CODEC_WORKING_MEM_SIZE
        #define VGA_TEMP_TOTAL_MEM_SIZE     (MJPEG_VGA_FRM_BUFFER_SIZE_CACHE_LINE+MJPEG_VGA_WORKING_MEM_SIZE_CACHE_LINE)
        #define VGA_FRM_BUFFER_SIZE         MJPEG_VGA_FRM_BUFFER_SIZE_CACHE_LINE
        #define VGA_CODEC_WORKING_MEM_SIZE  MJPEG_VGA_WORKING_MEM_SIZE_CACHE_LINE
    #endif
#endif  /* __VE_MJPEG_DEC_SW_SUPPORT__ */


#if defined(__VE_VP8_DEC_SW_SUPPORT__)
    #if (VP8_VGA_EXTRA_BUFFER_NUM < 0)
        #error "VGA Scenario: Extra frame number of VP8 decoder should be no bigger than or equal to 0"
    #endif

    #define VP8_VGA_NORMAL_BUFFER_SIZE (ALIGN_X((VP8_VGA_DEC_MAX_WIDTH+VP8_PADDING_SIZE), 32) * ALIGN_X((VP8_VGA_DEC_MAX_HEIGHT+VP8_PADDING_SIZE), 32) * (VP8_VGA_EXTRA_BUFFER_NUM + VP8_DECODER_ESSENTIAL_BUFFER_NUM) * 3 / 2 + (CPU_CACHE_LINE_SIZE_MINE*2))

    #define VP8_VGA_FRM_BUFFER_SIZE_CACHE_LINE ALIGN_X((VP8_VGA_NORMAL_BUFFER_SIZE+GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define VP8_VGA_WORKING_MEM_SIZE_CACHE_LINE ALIGN_X((VP8_VGA_DEC_WORKING_MEM+CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ( (VP8_VGA_FRM_BUFFER_SIZE_CACHE_LINE + VP8_VGA_WORKING_MEM_SIZE_CACHE_LINE) > VGA_TEMP_TOTAL_MEM_SIZE)
        #undef VGA_TEMP_TOTAL_MEM_SIZE
        #undef VGA_FRM_BUFFER_SIZE
        #undef VGA_CODEC_WORKING_MEM_SIZE
        #define VGA_TEMP_TOTAL_MEM_SIZE     (VP8_VGA_FRM_BUFFER_SIZE_CACHE_LINE + VP8_VGA_WORKING_MEM_SIZE_CACHE_LINE)
        #define VGA_FRM_BUFFER_SIZE         VP8_VGA_FRM_BUFFER_SIZE_CACHE_LINE
        #define VGA_CODEC_WORKING_MEM_SIZE  VP8_VGA_WORKING_MEM_SIZE_CACHE_LINE
    #endif
#endif  /* defined(__VE_VP8_DEC_SW_SUPPORT__) */


#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__) || defined (__VE_H264_DEC_SW_SUPPORT__) \
       || defined(__VE_H264_DEC_HW_SUPPORT__) || defined(__VE_RV_DEC_SW_SUPPORT__) || defined(__VE_MJPEG_DEC_SW_SUPPORT__) \
       || defined(__VE_VP8_DEC_SW_SUPPORT__))

    #if (VGA_FRM_BUFFER_SIZE == 0)
        #error "VGA Scenario: Cannot decide the size of frame buffer, no codec is enable"
    #endif
#endif


//Temp solution
#define DECODER_VGA_MEM_SIZE (VGA_FRM_BUFFER_SIZE + VIDEO_EXTRA_MEM_SIZE + VIDEO_DEC_WORKING_MEM_SIZE + VGA_CODEC_WORKING_MEM_SIZE)

/***************************************
*   CIF Scenario
*   Decide the size of frame buffer & the working memory of codec
*   Assumption: YUV420 format
***************************************/
#define CIF_FRM_BUFFER_SIZE             0
#define CIF_CODEC_WORKING_MEM_SIZE      0
#define CIF_TEMP_TOTAL_MEM_SIZE         0

#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    #if (MPEG4_CIF_EXTRA_BUFFER_NUM < 0)
    #error "CIF Scenario: Extra frame number of MPEG4 decoder should be no bigger than or equal to 0"
    #endif

    #define MPEG4_CIF_NORMAL_BUFFER_SIZE (MPEG4_CIF_DEC_MAX_WIDTH * MPEG4_CIF_DEC_MAX_HEIGHT * (MPEG4_CIF_EXTRA_BUFFER_NUM + DECODER_ESSENTIAL_BUFFER_NUM) * 3 / 2 + (CPU_CACHE_LINE_SIZE_MINE*2))

    #define MPEG4_CIF_FRM_BUFFER_SIZE_CACHE_LINE \
            ALIGN_X((MPEG4_CIF_NORMAL_BUFFER_SIZE + GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define MPEG4_CIF_WORKING_MEM_SIZE_CACHE_LINE \
            ALIGN_X((MPEG4_CIF_DEC_WORKING_MEM + CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ( (MPEG4_CIF_FRM_BUFFER_SIZE_CACHE_LINE + MPEG4_CIF_WORKING_MEM_SIZE_CACHE_LINE) > CIF_TEMP_TOTAL_MEM_SIZE)
        #undef CIF_TEMP_TOTAL_MEM_SIZE
        #undef CIF_FRM_BUFFER_SIZE
        #undef CIF_CODEC_WORKING_MEM_SIZE
        #define CIF_TEMP_TOTAL_MEM_SIZE     (MPEG4_CIF_FRM_BUFFER_SIZE_CACHE_LINE+MPEG4_CIF_WORKING_MEM_SIZE_CACHE_LINE)
        #define CIF_FRM_BUFFER_SIZE         MPEG4_CIF_FRM_BUFFER_SIZE_CACHE_LINE
        #define CIF_CODEC_WORKING_MEM_SIZE  MPEG4_CIF_WORKING_MEM_SIZE_CACHE_LINE
    #endif
#endif  /* (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__)) */


#if (defined (__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    #if (H264_CIF_EXTRA_BUFFER_NUM < 0)
    #error "CIF Scenario: Extra frame number of H264 decoder should be no bigger than or equal to 0"
    #endif

    #define H264_CIF_NORMAL_BUFFER_SIZE (H264_CIF_DEC_MAX_WIDTH * H264_CIF_DEC_MAX_HEIGHT * (H264_CIF_EXTRA_BUFFER_NUM + DECODER_ESSENTIAL_BUFFER_NUM) * 3 / 2 + (CPU_CACHE_LINE_SIZE_MINE*2))
    #define H264_CIF_3_FRM_SIZE    (3 * H264_CIF_DEC_MAX_WIDTH * H264_CIF_DEC_MAX_HEIGHT * 3 / 2)

    #if ((H264_CIF_EXTRA_BUFFER_NUM + DECODER_ESSENTIAL_BUFFER_NUM) < 19)
        #if ((H264_CIF_DEC_DPB_SIZE + H264_CIF_3_FRM_SIZE) > H264_CIF_NORMAL_BUFFER_SIZE)
            #error "CIF Scenario: Frame buffer size is smaller than the level specified. Please either increase the frame number or raise the level."
        #else
            #undef H264_CIF_DEC_DPB_SIZE
            #define H264_CIF_DEC_DPB_SIZE H264_CIF_NORMAL_BUFFER_SIZE
        #endif
    #else
        #undef H264_CIF_DEC_DPB_SIZE
        #define H264_CIF_DEC_DPB_SIZE H264_CIF_NORMAL_BUFFER_SIZE
    #endif

    #define H264_CIF_FRM_BUFFER_SIZE_CACHE_LINE \
            ALIGN_X((H264_CIF_NORMAL_BUFFER_SIZE+GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define H264_CIF_WORKING_MEM_SIZE_CACHE_LINE \
            ALIGN_X((H264_CIF_DEC_WORKING_MEM+CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ( (H264_CIF_FRM_BUFFER_SIZE_CACHE_LINE+H264_CIF_WORKING_MEM_SIZE_CACHE_LINE) > CIF_TEMP_TOTAL_MEM_SIZE)
        #undef CIF_TEMP_TOTAL_MEM_SIZE
        #undef CIF_FRM_BUFFER_SIZE
        #undef CIF_CODEC_WORKING_MEM_SIZE
        #define CIF_TEMP_TOTAL_MEM_SIZE     (H264_CIF_FRM_BUFFER_SIZE_CACHE_LINE+H264_CIF_WORKING_MEM_SIZE_CACHE_LINE)
        #define CIF_FRM_BUFFER_SIZE         H264_CIF_FRM_BUFFER_SIZE_CACHE_LINE
        #define CIF_CODEC_WORKING_MEM_SIZE  H264_CIF_WORKING_MEM_SIZE_CACHE_LINE
    #endif
#endif  /* #if (defined (__VE_H264_DEC_SW_SUPPORT__) || (__VE_H264_DEC_HW_SUPPORT__)) */


#ifdef __VE_RV_DEC_SW_SUPPORT__
    #if (RV9_CIF_EXTRA_BUFFER_NUM < 0)
    #error "CIF Scenario: Extra frame number of RV decoder should be no bigger than or equal to 0"
    #endif

    #define RV9_CIF_NORMAL_BUFFER_SIZE (((RV9_CIF_DEC_MAX_WIDTH) * (RV9_CIF_DEC_MAX_HEIGHT) * (RV9_CIF_EXTRA_BUFFER_NUM + RM_DECODER_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (2*16*RV9_CIF_DEC_MAX_WIDTH) + (CPU_CACHE_LINE_SIZE_MINE*2))

    #define RV9_CIF_FRM_BUFFER_SIZE_CACHE_LINE \
            ALIGN_X((RV9_CIF_NORMAL_BUFFER_SIZE + GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define RV9_CIF_WORKING_MEM_SIZE_CACHE_LINE \
            ALIGN_X((RV9_CIF_DEC_WORKING_MEM + CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ( (RV9_CIF_FRM_BUFFER_SIZE_CACHE_LINE + RV9_CIF_WORKING_MEM_SIZE_CACHE_LINE) > CIF_TEMP_TOTAL_MEM_SIZE)
        #undef CIF_TEMP_TOTAL_MEM_SIZE
        #undef CIF_FRM_BUFFER_SIZE
        #undef CIF_CODEC_WORKING_MEM_SIZE
        #define CIF_TEMP_TOTAL_MEM_SIZE     (RV9_CIF_FRM_BUFFER_SIZE_CACHE_LINE+RV9_CIF_WORKING_MEM_SIZE_CACHE_LINE)
        #define CIF_FRM_BUFFER_SIZE         RV9_CIF_FRM_BUFFER_SIZE_CACHE_LINE
        #define CIF_CODEC_WORKING_MEM_SIZE  RV9_CIF_WORKING_MEM_SIZE_CACHE_LINE
    #endif
#endif  /* __VE_RV_DEC_SW_SUPPORT__ */


#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
    #define MJPEG_CIF_BUFFER_SIZE (((MJPEG_CIF_DEC_MAX_WIDTH) * (MJPEG_CIF_DEC_MAX_HEIGHT) * (MJPEG_CIF_EXTRA_BUFFER_NUM + DECODER_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE*2))

    #define MJPEG_CIF_FRM_BUFFER_SIZE_CACHE_LINE \
            ALIGN_X((MJPEG_CIF_BUFFER_SIZE+GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define MJPEG_CIF_WORKING_MEM_SIZE_CACHE_LINE \
            ALIGN_X((MJPEG_CIF_DEC_WORKING_MEM+CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ( (MJPEG_CIF_FRM_BUFFER_SIZE_CACHE_LINE+MJPEG_CIF_WORKING_MEM_SIZE_CACHE_LINE) > CIF_TEMP_TOTAL_MEM_SIZE)
        #undef CIF_TEMP_TOTAL_MEM_SIZE
        #undef CIF_FRM_BUFFER_SIZE
        #undef CIF_CODEC_WORKING_MEM_SIZE
        #define CIF_TEMP_TOTAL_MEM_SIZE     (MJPEG_CIF_FRM_BUFFER_SIZE_CACHE_LINE+MJPEG_CIF_WORKING_MEM_SIZE_CACHE_LINE)
        #define CIF_FRM_BUFFER_SIZE         MJPEG_CIF_FRM_BUFFER_SIZE_CACHE_LINE
        #define CIF_CODEC_WORKING_MEM_SIZE  MJPEG_CIF_WORKING_MEM_SIZE_CACHE_LINE
    #endif
#endif  /* __VE_MJPEG_DEC_SW_SUPPORT__ */


#if defined(__VE_VP8_DEC_SW_SUPPORT__)
    #if (VP8_CIF_EXTRA_BUFFER_NUM < 0)
        #error "CIF Scenario: Extra frame number of VP8 decoder should be no bigger than or equal to 0"
    #endif

    #define VP8_CIF_NORMAL_BUFFER_SIZE (ALIGN_X((VP8_CIF_DEC_MAX_WIDTH+VP8_PADDING_SIZE), 32) * ALIGN_X((VP8_CIF_DEC_MAX_HEIGHT+VP8_PADDING_SIZE), 32) * (VP8_CIF_EXTRA_BUFFER_NUM + VP8_DECODER_ESSENTIAL_BUFFER_NUM) * 3 / 2 + (CPU_CACHE_LINE_SIZE_MINE*2))

    #define VP8_CIF_FRM_BUFFER_SIZE_CACHE_LINE ALIGN_X((VP8_CIF_NORMAL_BUFFER_SIZE+GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define VP8_CIF_WORKING_MEM_SIZE_CACHE_LINE ALIGN_X((VP8_CIF_DEC_WORKING_MEM+CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ( (VP8_CIF_FRM_BUFFER_SIZE_CACHE_LINE + VP8_CIF_WORKING_MEM_SIZE_CACHE_LINE) > CIF_TEMP_TOTAL_MEM_SIZE)
        #undef CIF_TEMP_TOTAL_MEM_SIZE
        #undef CIF_FRM_BUFFER_SIZE
        #undef CIF_CODEC_WORKING_MEM_SIZE
        #define CIF_TEMP_TOTAL_MEM_SIZE     (VP8_CIF_FRM_BUFFER_SIZE_CACHE_LINE + VP8_CIF_WORKING_MEM_SIZE_CACHE_LINE)
        #define CIF_FRM_BUFFER_SIZE         VP8_CIF_FRM_BUFFER_SIZE_CACHE_LINE
        #define CIF_CODEC_WORKING_MEM_SIZE  VP8_CIF_WORKING_MEM_SIZE_CACHE_LINE
    #endif
#endif  /* defined(__VE_VP8_DEC_SW_SUPPORT__) */


#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__) || defined (__VE_H264_DEC_SW_SUPPORT__) \
       || defined(__VE_H264_DEC_HW_SUPPORT__) || defined(__VE_RV_DEC_SW_SUPPORT__) || defined(__VE_MJPEG_DEC_SW_SUPPORT__) \
       || defined(__VE_VP8_DEC_SW_SUPPORT__))

    #if (CIF_FRM_BUFFER_SIZE == 0)
        #error "CIF Scenario: Cannot decide the size of frame buffer, no codec is enable"
    #endif
#endif


//Temp solution
#define DECODER_CIF_MEM_SIZE (CIF_FRM_BUFFER_SIZE + VIDEO_EXTRA_MEM_SIZE + VIDEO_DEC_WORKING_MEM_SIZE + CIF_CODEC_WORKING_MEM_SIZE)


/***************************************
*   UPTO-QVGA Scenario
*   Decide the size of frame buffer & the working memory of codec
*   Assumption: YUV420 format
***************************************/
#define UPTOQVGA_FRM_BUFFER_SIZE             0
#define UPTOQVGA_CODEC_WORKING_MEM_SIZE      0
#define UPTOQVGA_TEMP_TOTAL_MEM_SIZE         0

#if defined(__VE_MPEG4_DEC_SW_SUPPORT__)
    #ifdef __MP4_DEC_SW_SUPPORT_ASP__
        #if (MPEG4_DEC_MAX_WIDTH_SP * MPEG4_DEC_MAX_HEIGHT_SP > MPEG4_DEC_MAX_WIDTH_ASP * MPEG4_DEC_MAX_HEIGHT_ASP)
            #if (320 * 240 > MPEG4_DEC_MAX_WIDTH_SP * MPEG4_DEC_MAX_HEIGHT_SP)
                #define MPEG4_UPTOQVGA_DEC_MAX_WIDTH         MPEG4_DEC_MAX_WIDTH_SP
                #define MPEG4_UPTOQVGA_DEC_MAX_HEIGHT        MPEG4_DEC_MAX_HEIGHT_SP
                #define MPEG4_UPTOQVGA_DEC_WORKING_MEM       MPEG4_DEC_WORKING_MEM_SP
            #else
                #define MPEG4_UPTOQVGA_DEC_MAX_WIDTH         320
                #define MPEG4_UPTOQVGA_DEC_MAX_HEIGHT        240
                #define MPEG4_UPTOQVGA_DEC_WORKING_MEM       MP4SwDecExtSize_320x240_SP
            #endif
        #else // (MPEG4_DEC_MAX_WIDTH_SP * MPEG4_DEC_MAX_HEIGHT_SP > MPEG4_DEC_MAX_WIDTH_ASP * MPEG4_DEC_MAX_HEIGHT_ASP)
            #if (320*240 > MPEG4_DEC_MAX_WIDTH_ASP*MPEG4_DEC_MAX_HEIGHT_ASP)
                #define MPEG4_UPTOQVGA_DEC_MAX_WIDTH         MPEG4_DEC_MAX_WIDTH_ASP
                #define MPEG4_UPTOQVGA_DEC_MAX_HEIGHT        MPEG4_DEC_MAX_HEIGHT_ASP
                #define MPEG4_UPTOQVGA_DEC_WORKING_MEM       MPEG4_DEC_WORKING_MEM_ASP
            #else
                #define MPEG4_UPTOQVGA_DEC_MAX_WIDTH         320
                #define MPEG4_UPTOQVGA_DEC_MAX_HEIGHT        240
                #define MPEG4_UPTOQVGA_DEC_WORKING_MEM       MP4SwDecExtSize_320x240_SP
            #endif
        #endif
    #else // __MP4_DEC_SW_SUPPORT_ASP__
        #if (320 * 240 > MPEG4_DEC_MAX_WIDTH_SP * MPEG4_DEC_MAX_HEIGHT_SP)
            #define MPEG4_UPTOQVGA_DEC_MAX_WIDTH         MPEG4_DEC_MAX_WIDTH_SP
            #define MPEG4_UPTOQVGA_DEC_MAX_HEIGHT        MPEG4_DEC_MAX_HEIGHT_SP
            #define MPEG4_UPTOQVGA_DEC_WORKING_MEM       MPEG4_DEC_WORKING_MEM_SP
        #else
            #define MPEG4_UPTOQVGA_DEC_MAX_WIDTH         320
            #define MPEG4_UPTOQVGA_DEC_MAX_HEIGHT        240
            #define MPEG4_UPTOQVGA_DEC_WORKING_MEM       MP4SwDecExtSize_320x240_SP
        #endif
    #endif
#endif  /* #if defined(__VE_MPEG4_DEC_HW_SUPPORT__) */


#if defined (__VE_H264_DEC_SW_SUPPORT__)
    #ifdef __H264_DEC_SW_SUPPORT_MAINHIGH__
        #if (H264_DEC_MAX_WIDTH_BP*H264_DEC_MAX_HEIGHT_BP > H264_DEC_MAX_WIDTH_MPHP*H264_DEC_MAX_HEIGHT_MPHP)
            #if (320*240 > H264_DEC_MAX_WIDTH_BP*H264_DEC_MAX_HEIGHT_BP)
                #define H264_UPTOQVGA_DEC_MAX_WIDTH         H264_DEC_MAX_WIDTH_BP
                #define H264_UPTOQVGA_DEC_MAX_HEIGHT        H264_DEC_MAX_HEIGHT_BP
                #define H264_UPTOQVGA_DEC_WORKING_MEM       H264_DEC_MAX_WORKING_MEM_BP
                #define H264_UPTOQVGA_DECODER_LEVEL         H264_DECODER_LEVEL_BP
                #define H264_UPTOQVGA_DEC_DPB_SIZE          H264_DEC_DPB_SIZE_BP
            #else
                #define H264_UPTOQVGA_DEC_MAX_WIDTH         320
                #define H264_UPTOQVGA_DEC_MAX_HEIGHT        240
                #define H264_UPTOQVGA_DEC_WORKING_MEM       H264SwDecExtSize_320x240_BP
                #define H264_UPTOQVGA_DECODER_LEVEL         Level_11
                #define H264_UPTOQVGA_DEC_DPB_SIZE          H264SwDecLevel11
            #endif
        #else // (H264_DEC_MAX_WIDTH_BP*H264_DEC_MAX_HEIGHT_BP > H264_DEC_MAX_WIDTH_MPHP*H264_DEC_MAX_HEIGHT_MPHP)
            #if (320*240 > H264_DEC_MAX_WIDTH_MPHP*H264_DEC_MAX_HEIGHT_MPHP)
                #define H264_UPTOQVGA_DEC_MAX_WIDTH         H264_DEC_MAX_WIDTH_MPHP
                #define H264_UPTOQVGA_DEC_MAX_HEIGHT        H264_DEC_MAX_HEIGHT_MPHP
                #define H264_UPTOQVGA_DEC_WORKING_MEM       H264_DEC_MAX_WORKING_MEM_MPHP
                #define H264_UPTOQVGA_DECODER_LEVEL         H264_DECODER_LEVEL_MPHP
                #define H264_UPTOQVGA_DEC_DPB_SIZE          H264_DEC_DPB_SIZE_MPHP
            #else
                #define H264_UPTOQVGA_DEC_MAX_WIDTH         320
                #define H264_UPTOQVGA_DEC_MAX_HEIGHT        240
                #define H264_UPTOQVGA_DEC_WORKING_MEM       H264SwDecExtSize_320x240_MPHP
                #define H264_UPTOQVGA_DECODER_LEVEL         Level_11
                #define H264_UPTOQVGA_DEC_DPB_SIZE          H264SwDecLevel11
            #endif
        #endif
    #else  // __H264_DEC_SW_SUPPORT_MAINHIGH__
        #if (320*240 > H264_DEC_MAX_WIDTH_BP*H264_DEC_MAX_HEIGHT_BP)
            #define H264_UPTOQVGA_DEC_MAX_WIDTH         H264_DEC_MAX_WIDTH_BP
            #define H264_UPTOQVGA_DEC_MAX_HEIGHT        H264_DEC_MAX_HEIGHT_BP
            #define H264_UPTOQVGA_DEC_WORKING_MEM       H264_DEC_MAX_WORKING_MEM_BP
            #define H264_UPTOQVGA_DECODER_LEVEL         H264_DECODER_LEVEL_BP
            #define H264_UPTOQVGA_DEC_DPB_SIZE          H264_DEC_DPB_SIZE_BP
        #else
            #define H264_UPTOQVGA_DEC_MAX_WIDTH         320
            #define H264_UPTOQVGA_DEC_MAX_HEIGHT        240
            #define H264_UPTOQVGA_DEC_WORKING_MEM       H264SwDecExtSize_320x240_BP
            #define H264_UPTOQVGA_DECODER_LEVEL         Level_11
            #define H264_UPTOQVGA_DEC_DPB_SIZE          H264SwDecLevel11
        #endif
    #endif
#endif  /* #if defined(__VE_H264_DEC_HW_SUPPORT__) */


#ifdef __RV_DEC_SW_SUPPORT__
    #if (320*240 > RV9_DEC_MAX_WIDTH*RV9_DEC_MAX_HEIGHT)
        #define RV9_UPTOQVGA_DEC_MAX_WIDTH         RV9_DEC_MAX_WIDTH
        #define RV9_UPTOQVGA_DEC_MAX_HEIGHT        RV9_DEC_MAX_HEIGHT
        #define RV9_UPTOQVGA_DEC_WORKING_MEM       RV9_DEC_WORKING_MEM
    #else
        #define RV9_UPTOQVGA_DEC_MAX_WIDTH        320
        #define RV9_UPTOQVGA_DEC_MAX_HEIGHT       240
        #define RV9_UPTOQVGA_DEC_WORKING_MEM      RVSwDecExtSize_320x240
    #endif
#endif  /* __RV_DEC_SW_SUPPORT__ */


#ifdef __MJPEG_DEC_SW_SUPPORT__
    #if (320*240 > MJPEG_DEC_MAX_WIDTH*MJPEG_DEC_MAX_HEIGHT)
        #define MJPEG_UPTOQVGA_DEC_MAX_WIDTH        MJPEG_DEC_MAX_WIDTH
        #define MJPEG_UPTOQVGA_DEC_MAX_HEIGHT       MJPEG_DEC_MAX_HEIGHT
        #define MJPEG_UPTOQVGA_DEC_WORKING_MEM      MJPEG_DEC_WORKING_MEM
    #else
        #define MJPEG_UPTOQVGA_DEC_MAX_WIDTH        320
        #define MJPEG_UPTOQVGA_DEC_MAX_HEIGHT       240
        #define MJPEG_UPTOQVGA_DEC_WORKING_MEM      JPEG_DEC_MJPEG_EXT_MIN_MEM_SIZE
    #endif
#endif  /* __MJPEG_DEC_SW_SUPPORT__ */


#ifdef __VP8_DEC_SW_SUPPORT__
    #if (320 * 240 > VP8_DEC_MAX_WIDTH * VP8_DEC_MAX_HEIGHT)
        #define VP8_UPTOQVGA_DEC_MAX_WIDTH        VP8_DEC_MAX_WIDTH
        #define VP8_UPTOQVGA_DEC_MAX_HEIGHT       VP8_DEC_MAX_HEIGHT
        #define VP8_UPTOQVGA_DEC_WORKING_MEM      VP8_DEC_WORKING_MEM
    #else
        #define VP8_UPTOQVGA_DEC_MAX_WIDTH        320
        #define VP8_UPTOQVGA_DEC_MAX_HEIGHT       240
        #define VP8_UPTOQVGA_DEC_WORKING_MEM      VP8SwDecExtSize_320x240
    #endif
#endif  /* __VP8_DEC_SW_SUPPORT__ */


#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    #if (MPEG4_UPTOQVGA_EXTRA_BUFFER_NUM < 0)
        #error "UPTO-QVGA Scenario: Extra frame number of MPEG4 decoder should be no bigger than or equal to 0"
    #endif

    #define MPEG4_UPTOQVGA_NORMAL_BUFFER_SIZE (MPEG4_UPTOQVGA_DEC_MAX_WIDTH * MPEG4_UPTOQVGA_DEC_MAX_HEIGHT * (MPEG4_UPTOQVGA_EXTRA_BUFFER_NUM + DECODER_ESSENTIAL_BUFFER_NUM) * 3 / 2 + (CPU_CACHE_LINE_SIZE_MINE*2))

    #define MPEG4_UPTOQVGA_FRM_BUFFER_SIZE_CACHE_LINE ALIGN_X((MPEG4_UPTOQVGA_NORMAL_BUFFER_SIZE+GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define MPEG4_UPTOQVGA_WORKING_MEM_SIZE_CACHE_LINE ALIGN_X((MPEG4_UPTOQVGA_DEC_WORKING_MEM+CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ((MPEG4_UPTOQVGA_FRM_BUFFER_SIZE_CACHE_LINE + MPEG4_UPTOQVGA_WORKING_MEM_SIZE_CACHE_LINE) > UPTOQVGA_TEMP_TOTAL_MEM_SIZE)
        #undef UPTOQVGA_TEMP_TOTAL_MEM_SIZE
        #undef UPTOQVGA_FRM_BUFFER_SIZE
        #undef UPTOQVGA_CODEC_WORKING_MEM_SIZE
        #define UPTOQVGA_TEMP_TOTAL_MEM_SIZE    (MPEG4_UPTOQVGA_FRM_BUFFER_SIZE_CACHE_LINE+MPEG4_UPTOQVGA_WORKING_MEM_SIZE_CACHE_LINE)
        #define UPTOQVGA_FRM_BUFFER_SIZE        MPEG4_UPTOQVGA_FRM_BUFFER_SIZE_CACHE_LINE
        #define UPTOQVGA_CODEC_WORKING_MEM_SIZE MPEG4_UPTOQVGA_WORKING_MEM_SIZE_CACHE_LINE
    #endif
#endif  /* (defined(__VE_MPEG4_DEC_SW_SUPPORT__) */


#if (defined (__VE_H264_DEC_SW_SUPPORT__) || defined (__VE_H264_DEC_HW_SUPPORT__))
    #if (H264_UPTOQVGA_EXTRA_BUFFER_NUM < 0)
        #error "UPTOQVGA Scenario: Extra frame number of H264 decoder should be no bigger than or equal to 0"
    #endif

    #if (H264_UPTOQVGA_DEC_DPB_SIZE <= 0)
        #error "UPTOQVGA Scenario: Frame buffer of H264 decoder should be more than 0"
    #endif

    #define H264_UPTOQVGA_NORMAL_BUFFER_SIZE (H264_UPTOQVGA_DEC_MAX_WIDTH * H264_UPTOQVGA_DEC_MAX_HEIGHT * (H264_UPTOQVGA_EXTRA_BUFFER_NUM + DECODER_ESSENTIAL_BUFFER_NUM) * 3 / 2 + (CPU_CACHE_LINE_SIZE_MINE*2))
    #define H264_UPTOQVGA_3_FRM_SIZE    (3 * H264_UPTOQVGA_DEC_MAX_WIDTH * H264_UPTOQVGA_DEC_MAX_HEIGHT * 3 / 2)

    #if ((H264_UPTOQVGA_EXTRA_BUFFER_NUM + DECODER_ESSENTIAL_BUFFER_NUM) < 19)
        #if (H264_UPTOQVGA_DEC_DPB_SIZE + H264_UPTOQVGA_3_FRM_SIZE > H264_UPTOQVGA_NORMAL_BUFFER_SIZE)
            #undef H264_UPTOQVGA_NORMAL_BUFFER_SIZE
            #define H264_UPTOQVGA_NORMAL_BUFFER_SIZE H264_UPTOQVGA_DEC_DPB_SIZE // H264_UPTOQVGA_DEC_DPB_SIZE might be re-defined before this line.
        #endif
    #else
        #error "UPTOQVGA Scenario: abnormal frame buffer configurations"
    #endif

    #define H264_UPTOQVGA_FRM_BUFFER_SIZE_CACHE_LINE ALIGN_X((H264_UPTOQVGA_NORMAL_BUFFER_SIZE+GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define H264_UPTOQVGA_WORKING_MEM_SIZE_CACHE_LINE ALIGN_X((H264_UPTOQVGA_DEC_WORKING_MEM+CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ( (H264_UPTOQVGA_FRM_BUFFER_SIZE_CACHE_LINE+H264_UPTOQVGA_WORKING_MEM_SIZE_CACHE_LINE) > UPTOQVGA_TEMP_TOTAL_MEM_SIZE)
        #undef UPTOQVGA_TEMP_TOTAL_MEM_SIZE
        #undef UPTOQVGA_FRM_BUFFER_SIZE
        #undef UPTOQVGA_CODEC_WORKING_MEM_SIZE
        #define UPTOQVGA_TEMP_TOTAL_MEM_SIZE    (H264_UPTOQVGA_FRM_BUFFER_SIZE_CACHE_LINE+H264_UPTOQVGA_WORKING_MEM_SIZE_CACHE_LINE)
        #define UPTOQVGA_FRM_BUFFER_SIZE        H264_UPTOQVGA_FRM_BUFFER_SIZE_CACHE_LINE
        #define UPTOQVGA_CODEC_WORKING_MEM_SIZE H264_UPTOQVGA_WORKING_MEM_SIZE_CACHE_LINE
    #endif
#endif  /* #if (defined (__VE_H264_DEC_SW_SUPPORT__) || defined (__VE_H264_DEC_HW_SUPPORT__)) */


#ifdef __VE_RV_DEC_SW_SUPPORT__

    #if (RV9_UPTOQVGA_EXTRA_BUFFER_NUM < 0)
        #error "UPTOQVGA Scenario: Extra frame number of RV decoder should be no bigger than or equal to 0"
    #endif

    #define RV9_UPTOQVGA_NORMAL_BUFFER_SIZE (((RV9_UPTOQVGA_DEC_MAX_WIDTH) * (RV9_UPTOQVGA_DEC_MAX_HEIGHT) * (RV9_UPTOQVGA_EXTRA_BUFFER_NUM + RM_DECODER_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (2*16*RV9_UPTOQVGA_DEC_MAX_WIDTH) + (CPU_CACHE_LINE_SIZE_MINE*2))

    #define RV9_UPTOQVGA_FRM_BUFFER_SIZE_CACHE_LINE ALIGN_X((RV9_UPTOQVGA_NORMAL_BUFFER_SIZE+GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define RV9_UPTOQVGA_WORKING_MEM_SIZE_CACHE_LINE ALIGN_X((RV9_UPTOQVGA_DEC_WORKING_MEM+CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ( (RV9_UPTOQVGA_FRM_BUFFER_SIZE_CACHE_LINE+RV9_UPTOQVGA_WORKING_MEM_SIZE_CACHE_LINE) > UPTOQVGA_TEMP_TOTAL_MEM_SIZE)
        #undef UPTOQVGA_TEMP_TOTAL_MEM_SIZE
        #undef UPTOQVGA_FRM_BUFFER_SIZE
        #undef UPTOQVGA_CODEC_WORKING_MEM_SIZE
        #define UPTOQVGA_TEMP_TOTAL_MEM_SIZE    (RV9_UPTOQVGA_FRM_BUFFER_SIZE_CACHE_LINE+RV9_UPTOQVGA_WORKING_MEM_SIZE_CACHE_LINE)
        #define UPTOQVGA_FRM_BUFFER_SIZE        RV9_UPTOQVGA_FRM_BUFFER_SIZE_CACHE_LINE
        #define UPTOQVGA_CODEC_WORKING_MEM_SIZE RV9_UPTOQVGA_WORKING_MEM_SIZE_CACHE_LINE
    #endif
#endif  /* __VE_RV_DEC_SW_SUPPORT__ */


#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
    #define MJPEG_UPTOQVGA_BUFFER_SIZE (((MJPEG_UPTOQVGA_DEC_MAX_WIDTH) * (MJPEG_UPTOQVGA_DEC_MAX_HEIGHT) * (MJPEG_UPTOQVGA_EXTRA_BUFFER_NUM + DECODER_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE*2))
    #define MJPEG_UPTOQVGA_FRM_BUFFER_SIZE_CACHE_LINE ALIGN_X((MJPEG_UPTOQVGA_BUFFER_SIZE+GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)
    #define MJPEG_UPTOQVGA_WORKING_MEM_SIZE_CACHE_LINE ALIGN_X((MJPEG_UPTOQVGA_DEC_WORKING_MEM+CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ( (MJPEG_UPTOQVGA_FRM_BUFFER_SIZE_CACHE_LINE+MJPEG_UPTOQVGA_WORKING_MEM_SIZE_CACHE_LINE) > UPTOQVGA_TEMP_TOTAL_MEM_SIZE)
        #undef UPTOQVGA_TEMP_TOTAL_MEM_SIZE
        #undef UPTOQVGA_FRM_BUFFER_SIZE
        #undef UPTOQVGA_CODEC_WORKING_MEM_SIZE
        #define UPTOQVGA_TEMP_TOTAL_MEM_SIZE    (MJPEG_UPTOQVGA_FRM_BUFFER_SIZE_CACHE_LINE+MJPEG_UPTOQVGA_WORKING_MEM_SIZE_CACHE_LINE)
        #define UPTOQVGA_FRM_BUFFER_SIZE        MJPEG_UPTOQVGA_FRM_BUFFER_SIZE_CACHE_LINE
        #define UPTOQVGA_CODEC_WORKING_MEM_SIZE MJPEG_UPTOQVGA_WORKING_MEM_SIZE_CACHE_LINE
    #endif
#endif  /* __VE_MJPEG_DEC_SW_SUPPORT__ */


#ifdef __VE_VP8_DEC_SW_SUPPORT__

    #if (VP8_UPTOQVGA_EXTRA_BUFFER_NUM < 0)
        #error "UPTOQVGA Scenario: Extra frame number of VP8 decoder should be no bigger than or equal to 0"
    #endif

    #define VP8_UPTOQVGA_NORMAL_BUFFER_SIZE ((ALIGN_X((VP8_UPTOQVGA_DEC_MAX_WIDTH+VP8_PADDING_SIZE), 32) * ALIGN_X((VP8_UPTOQVGA_DEC_MAX_HEIGHT+VP8_PADDING_SIZE), 32) * (VP8_UPTOQVGA_EXTRA_BUFFER_NUM + VP8_DECODER_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE*2))
    #define VP8_UPTOQVGA_FRM_BUFFER_SIZE_CACHE_LINE ALIGN_X((VP8_UPTOQVGA_NORMAL_BUFFER_SIZE+GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)
    #define VP8_UPTOQVGA_WORKING_MEM_SIZE_CACHE_LINE ALIGN_X((VP8_UPTOQVGA_DEC_WORKING_MEM+CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ( (VP8_UPTOQVGA_FRM_BUFFER_SIZE_CACHE_LINE + VP8_UPTOQVGA_WORKING_MEM_SIZE_CACHE_LINE) > UPTOQVGA_TEMP_TOTAL_MEM_SIZE)
        #undef UPTOQVGA_TEMP_TOTAL_MEM_SIZE
        #undef UPTOQVGA_FRM_BUFFER_SIZE
        #undef UPTOQVGA_CODEC_WORKING_MEM_SIZE
        #define UPTOQVGA_TEMP_TOTAL_MEM_SIZE    (VP8_UPTOQVGA_FRM_BUFFER_SIZE_CACHE_LINE + VP8_UPTOQVGA_WORKING_MEM_SIZE_CACHE_LINE)
        #define UPTOQVGA_FRM_BUFFER_SIZE        VP8_UPTOQVGA_FRM_BUFFER_SIZE_CACHE_LINE
        #define UPTOQVGA_CODEC_WORKING_MEM_SIZE VP8_UPTOQVGA_WORKING_MEM_SIZE_CACHE_LINE
    #endif

#endif  // __VE_VP8_DEC_SW_SUPPORT__


#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__) \
       || defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__) \
       || defined(__VE_RV_DEC_SW_SUPPORT__) || defined(__VE_MJPEG_DEC_SW_SUPPORT__) \
       || defined(__VE_VP8_DEC_SW_SUPPORT__))

    #if (UPTOQVGA_FRM_BUFFER_SIZE == 0)
        #error "UPTOQVGA Scenario: Cannot decide the size of frame buffer, no codec is enable"
    #endif
#endif


//Temp solution
#define DECODER_UPTOQVGA_MEM_SIZE (UPTOQVGA_FRM_BUFFER_SIZE + VIDEO_EXTRA_MEM_SIZE + VIDEO_DEC_WORKING_MEM_SIZE + UPTOQVGA_CODEC_WORKING_MEM_SIZE)


/***************************************
*   UPTO-CIF Scenario
*   Decide the size of frame buffer & the working memory of codec
*   Assumption: YUV420 format
***************************************/
#define UPTOCIF_FRM_BUFFER_SIZE             0
#define UPTOCIF_CODEC_WORKING_MEM_SIZE      0
#define UPTOCIF_TEMP_TOTAL_MEM_SIZE         0

#if defined(__VE_MPEG4_DEC_SW_SUPPORT__)
    #ifdef __MP4_DEC_SW_SUPPORT_ASP__
        #if (MPEG4_DEC_MAX_WIDTH_SP * MPEG4_DEC_MAX_HEIGHT_SP > MPEG4_DEC_MAX_WIDTH_ASP * MPEG4_DEC_MAX_HEIGHT_ASP)
            #if (352 * 288 > MPEG4_DEC_MAX_WIDTH_SP * MPEG4_DEC_MAX_HEIGHT_SP)
                #define MPEG4_UPTOCIF_DEC_MAX_WIDTH         MPEG4_DEC_MAX_WIDTH_SP
                #define MPEG4_UPTOCIF_DEC_MAX_HEIGHT        MPEG4_DEC_MAX_HEIGHT_SP
                #define MPEG4_UPTOCIF_DEC_WORKING_MEM       MPEG4_DEC_WORKING_MEM_SP
            #else
                #define MPEG4_UPTOCIF_DEC_MAX_WIDTH         352
                #define MPEG4_UPTOCIF_DEC_MAX_HEIGHT        288
                #define MPEG4_UPTOCIF_DEC_WORKING_MEM       MP4SwDecExtSize_352x288_SP
            #endif
        #else // (MPEG4_DEC_MAX_WIDTH_SP * MPEG4_DEC_MAX_HEIGHT_SP > MPEG4_DEC_MAX_WIDTH_ASP * MPEG4_DEC_MAX_HEIGHT_ASP)
            #if (352*288 > MPEG4_DEC_MAX_WIDTH_ASP*MPEG4_DEC_MAX_HEIGHT_ASP)
                #define MPEG4_UPTOCIF_DEC_MAX_WIDTH         MPEG4_DEC_MAX_WIDTH_ASP
                #define MPEG4_UPTOCIF_DEC_MAX_HEIGHT        MPEG4_DEC_MAX_HEIGHT_ASP
                #define MPEG4_UPTOCIF_DEC_WORKING_MEM       MPEG4_DEC_WORKING_MEM_ASP
            #else
                #define MPEG4_UPTOCIF_DEC_MAX_WIDTH         352
                #define MPEG4_UPTOCIF_DEC_MAX_HEIGHT        288
                #define MPEG4_UPTOCIF_DEC_WORKING_MEM       MP4SwDecExtSize_352x288_SP
            #endif
        #endif
    #else  // __MP4_DEC_SW_SUPPORT_ASP__
        #if (352 * 288 > MPEG4_DEC_MAX_WIDTH_SP * MPEG4_DEC_MAX_HEIGHT_SP)
            #define MPEG4_UPTOCIF_DEC_MAX_WIDTH         MPEG4_DEC_MAX_WIDTH_SP
            #define MPEG4_UPTOCIF_DEC_MAX_HEIGHT        MPEG4_DEC_MAX_HEIGHT_SP
            #define MPEG4_UPTOCIF_DEC_WORKING_MEM       MPEG4_DEC_WORKING_MEM_SP
        #else
            #define MPEG4_UPTOCIF_DEC_MAX_WIDTH         352
            #define MPEG4_UPTOCIF_DEC_MAX_HEIGHT        288
            #define MPEG4_UPTOCIF_DEC_WORKING_MEM       MP4SwDecExtSize_352x288_SP
        #endif
    #endif
#endif  /* defined(__VE_MPEG4_DEC_SW_SUPPORT__) */


#if defined (__VE_H264_DEC_SW_SUPPORT__)
    #ifdef __H264_DEC_SW_SUPPORT_MAINHIGH__
        #if (H264_DEC_MAX_WIDTH_BP*H264_DEC_MAX_HEIGHT_BP > H264_DEC_MAX_WIDTH_MPHP*H264_DEC_MAX_HEIGHT_MPHP)
            #if (352*288 > H264_DEC_MAX_WIDTH_BP*H264_DEC_MAX_HEIGHT_BP)
                #define H264_UPTOCIF_DEC_MAX_WIDTH         H264_DEC_MAX_WIDTH_BP
                #define H264_UPTOCIF_DEC_MAX_HEIGHT        H264_DEC_MAX_HEIGHT_BP
                #define H264_UPTOCIF_DEC_WORKING_MEM       H264_DEC_MAX_WORKING_MEM_BP
                #define H264_UPTOCIF_DECODER_LEVEL         H264_DECODER_LEVEL_BP
                #define H264_UPTOCIF_DEC_DPB_SIZE          H264_DEC_DPB_SIZE_BP
            #else
                #define H264_UPTOCIF_DEC_MAX_WIDTH         352
                #define H264_UPTOCIF_DEC_MAX_HEIGHT        288
                #define H264_UPTOCIF_DEC_WORKING_MEM       H264SwDecExtSize_352x288_BP
                #define H264_UPTOCIF_DECODER_LEVEL         Level_11
                #define H264_UPTOCIF_DEC_DPB_SIZE          H264SwDecLevel11
            #endif
        #else  // (H264_DEC_MAX_WIDTH_BP*H264_DEC_MAX_HEIGHT_BP > H264_DEC_MAX_WIDTH_MPHP*H264_DEC_MAX_HEIGHT_MPHP)
            #if (352*288 > H264_DEC_MAX_WIDTH_MPHP*H264_DEC_MAX_HEIGHT_MPHP)
                #define H264_UPTOCIF_DEC_MAX_WIDTH         H264_DEC_MAX_WIDTH_MPHP
                #define H264_UPTOCIF_DEC_MAX_HEIGHT        H264_DEC_MAX_HEIGHT_MPHP
                #define H264_UPTOCIF_DEC_WORKING_MEM       H264_DEC_MAX_WORKING_MEM_MPHP
                #define H264_UPTOCIF_DECODER_LEVEL         H264_DECODER_LEVEL_MPHP
                #define H264_UPTOCIF_DEC_DPB_SIZE          H264_DEC_DPB_SIZE_MPHP
            #else
                #define H264_UPTOCIF_DEC_MAX_WIDTH         352
                #define H264_UPTOCIF_DEC_MAX_HEIGHT        288
                #define H264_UPTOCIF_DEC_WORKING_MEM       H264SwDecExtSize_352x288_MPHP
                #define H264_UPTOCIF_DECODER_LEVEL         Level_11
                #define H264_UPTOCIF_DEC_DPB_SIZE          H264SwDecLevel11
            #endif
        #endif
    #else  // __H264_DEC_SW_SUPPORT_MAINHIGH__
        #if (352*288 > H264_DEC_MAX_WIDTH_BP*H264_DEC_MAX_HEIGHT_BP)
            #define H264_UPTOCIF_DEC_MAX_WIDTH         H264_DEC_MAX_WIDTH_BP
            #define H264_UPTOCIF_DEC_MAX_HEIGHT        H264_DEC_MAX_HEIGHT_BP
            #define H264_UPTOCIF_DEC_WORKING_MEM       H264_DEC_MAX_WORKING_MEM_BP
            #define H264_UPTOCIF_DECODER_LEVEL         H264_DECODER_LEVEL_BP
            #define H264_UPTOCIF_DEC_DPB_SIZE          H264_DEC_DPB_SIZE_BP
        #else
            #define H264_UPTOCIF_DEC_MAX_WIDTH         352
            #define H264_UPTOCIF_DEC_MAX_HEIGHT        288
            #define H264_UPTOCIF_DEC_WORKING_MEM       H264SwDecExtSize_352x288_BP
            #define H264_UPTOCIF_DECODER_LEVEL         Level_11
            #define H264_UPTOCIF_DEC_DPB_SIZE          H264SwDecLevel11
        #endif
    #endif
#endif  // #if defined(__VE_H264_DEC_SW_SUPPORT__)


#ifdef __RV_DEC_SW_SUPPORT__
    #if (352*288 > RV9_DEC_MAX_WIDTH*RV9_DEC_MAX_HEIGHT)
        #define RV9_UPTOCIF_DEC_MAX_WIDTH         RV9_DEC_MAX_WIDTH
        #define RV9_UPTOCIF_DEC_MAX_HEIGHT        RV9_DEC_MAX_HEIGHT
        #define RV9_UPTOCIF_DEC_WORKING_MEM       RV9_DEC_WORKING_MEM
    #else
        #define RV9_UPTOCIF_DEC_MAX_WIDTH        352
        #define RV9_UPTOCIF_DEC_MAX_HEIGHT       288
        #define RV9_UPTOCIF_DEC_WORKING_MEM      RVSwDecExtSize_352x288
    #endif
#endif  /* __RV_DEC_SW_SUPPORT__ */


#ifdef __MJPEG_DEC_SW_SUPPORT__
    #if (352*288 > MJPEG_DEC_MAX_WIDTH*MJPEG_DEC_MAX_HEIGHT)
        #define MJPEG_UPTOCIF_DEC_MAX_WIDTH        MJPEG_DEC_MAX_WIDTH
        #define MJPEG_UPTOCIF_DEC_MAX_HEIGHT       MJPEG_DEC_MAX_HEIGHT
        #define MJPEG_UPTOCIF_DEC_WORKING_MEM      MJPEG_DEC_WORKING_MEM
    #else
        #define MJPEG_UPTOCIF_DEC_MAX_WIDTH        352
        #define MJPEG_UPTOCIF_DEC_MAX_HEIGHT       288
        #define MJPEG_UPTOCIF_DEC_WORKING_MEM      JPEG_DEC_MJPEG_EXT_MIN_MEM_SIZE
    #endif
#endif  /* __MJPEG_DEC_SW_SUPPORT__ */


#ifdef __VP8_DEC_SW_SUPPORT__
    #if (352*288 > VP8_DEC_MAX_WIDTH*VP8_DEC_MAX_HEIGHT)
        #define VP8_UPTOCIF_DEC_MAX_WIDTH        VP8_DEC_MAX_WIDTH
        #define VP8_UPTOCIF_DEC_MAX_HEIGHT       VP8_DEC_MAX_HEIGHT
        #define VP8_UPTOCIF_DEC_WORKING_MEM      VP8_DEC_WORKING_MEM
    #else
        #define VP8_UPTOCIF_DEC_MAX_WIDTH        352
        #define VP8_UPTOCIF_DEC_MAX_HEIGHT       288
        #define VP8_UPTOCIF_DEC_WORKING_MEM      VP8SwDecExtSize_352x288
    #endif
#endif  /* __VP8_DEC_SW_SUPPORT__ */


#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    #if (MPEG4_UPTOCIF_EXTRA_BUFFER_NUM < 0)
        #error "UPTO-CIF Scenario: Extra frame number of MPEG4 decoder should be no bigger than or equal to 0"
    #endif

    #define MPEG4_UPTOCIF_NORMAL_BUFFER_SIZE (MPEG4_UPTOCIF_DEC_MAX_WIDTH * MPEG4_UPTOCIF_DEC_MAX_HEIGHT * (MPEG4_UPTOCIF_EXTRA_BUFFER_NUM + DECODER_ESSENTIAL_BUFFER_NUM) * 3 / 2 + (CPU_CACHE_LINE_SIZE_MINE*2))

    #define MPEG4_UPTOCIF_FRM_BUFFER_SIZE_CACHE_LINE ALIGN_X((MPEG4_UPTOCIF_NORMAL_BUFFER_SIZE+GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define MPEG4_UPTOCIF_WORKING_MEM_SIZE_CACHE_LINE ALIGN_X((MPEG4_UPTOCIF_DEC_WORKING_MEM+CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ( (MPEG4_UPTOCIF_FRM_BUFFER_SIZE_CACHE_LINE+MPEG4_UPTOCIF_WORKING_MEM_SIZE_CACHE_LINE) > UPTOCIF_TEMP_TOTAL_MEM_SIZE)
        #undef UPTOCIF_TEMP_TOTAL_MEM_SIZE
        #undef UPTOCIF_FRM_BUFFER_SIZE
        #undef UPTOCIF_CODEC_WORKING_MEM_SIZE
        #define UPTOCIF_TEMP_TOTAL_MEM_SIZE     (MPEG4_UPTOCIF_FRM_BUFFER_SIZE_CACHE_LINE+MPEG4_UPTOCIF_WORKING_MEM_SIZE_CACHE_LINE)
        #define UPTOCIF_FRM_BUFFER_SIZE         MPEG4_UPTOCIF_FRM_BUFFER_SIZE_CACHE_LINE
        #define UPTOCIF_CODEC_WORKING_MEM_SIZE  MPEG4_UPTOCIF_WORKING_MEM_SIZE_CACHE_LINE
    #endif
#endif  /* (defined(__VE_MPEG4_DEC_SW_SUPPORT__) */


#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    #if (H264_UPTOCIF_EXTRA_BUFFER_NUM < 0)
        #error "UPTOCIF Scenario: Extra frame number of H264 decoder should be no bigger than or equal to 0"
    #endif

    #define H264_UPTOCIF_NORMAL_BUFFER_SIZE (H264_UPTOCIF_DEC_MAX_WIDTH * H264_UPTOCIF_DEC_MAX_HEIGHT * (H264_UPTOCIF_EXTRA_BUFFER_NUM + DECODER_ESSENTIAL_BUFFER_NUM) * 3 / 2 + (CPU_CACHE_LINE_SIZE_MINE*2))
    #define H264_UPTOCIF_3_FRM_SIZE    (3 * H264_UPTOCIF_DEC_MAX_WIDTH * H264_UPTOCIF_DEC_MAX_HEIGHT * 3 / 2)

    #if ((H264_UPTOCIF_EXTRA_BUFFER_NUM + DECODER_ESSENTIAL_BUFFER_NUM) < 19)
        #if (H264_UPTOCIF_DEC_DPB_SIZE + H264_UPTOCIF_3_FRM_SIZE > H264_UPTOCIF_NORMAL_BUFFER_SIZE)
            #undef H264_UPTOCIF_NORMAL_BUFFER_SIZE
            #define H264_UPTOCIF_NORMAL_BUFFER_SIZE H264_UPTOCIF_DEC_DPB_SIZE // H264_UPTOCIF_DEC_DPB_SIZE might be re-defined before this line.
        #endif
    #else
        #error "UPTOCIF Scenario: abnormal frame buffer configurations"
    #endif

    #define H264_UPTOCIF_FRM_BUFFER_SIZE_CACHE_LINE ALIGN_X((H264_UPTOCIF_NORMAL_BUFFER_SIZE+GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define H264_UPTOCIF_WORKING_MEM_SIZE_CACHE_LINE ALIGN_X((H264_UPTOCIF_DEC_WORKING_MEM+CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ( (H264_UPTOCIF_FRM_BUFFER_SIZE_CACHE_LINE+H264_UPTOCIF_WORKING_MEM_SIZE_CACHE_LINE) > UPTOCIF_TEMP_TOTAL_MEM_SIZE)
        #undef UPTOCIF_TEMP_TOTAL_MEM_SIZE
        #undef UPTOCIF_FRM_BUFFER_SIZE
        #undef UPTOCIF_CODEC_WORKING_MEM_SIZE
        #define UPTOCIF_TEMP_TOTAL_MEM_SIZE     (H264_UPTOCIF_FRM_BUFFER_SIZE_CACHE_LINE+H264_UPTOCIF_WORKING_MEM_SIZE_CACHE_LINE)
        #define UPTOCIF_FRM_BUFFER_SIZE         H264_UPTOCIF_FRM_BUFFER_SIZE_CACHE_LINE
        #define UPTOCIF_CODEC_WORKING_MEM_SIZE  H264_UPTOCIF_WORKING_MEM_SIZE_CACHE_LINE
    #endif
#endif  /* #if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__)) */


#ifdef __VE_RV_DEC_SW_SUPPORT__
    #if (RV9_UPTOCIF_EXTRA_BUFFER_NUM < 0)
        #error "UPTOCIF Scenario: Extra frame number of RV decoder should be no bigger than or equal to 0"
    #endif

    #define RV9_UPTOCIF_NORMAL_BUFFER_SIZE (((RV9_UPTOCIF_DEC_MAX_WIDTH) * (RV9_UPTOCIF_DEC_MAX_HEIGHT) * (RV9_UPTOCIF_EXTRA_BUFFER_NUM + RM_DECODER_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (2*16*RV9_UPTOCIF_DEC_MAX_WIDTH) + (CPU_CACHE_LINE_SIZE_MINE*2))

    #define RV9_UPTOCIF_FRM_BUFFER_SIZE_CACHE_LINE ALIGN_X((RV9_UPTOCIF_NORMAL_BUFFER_SIZE+GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define RV9_UPTOCIF_WORKING_MEM_SIZE_CACHE_LINE ALIGN_X((RV9_UPTOCIF_DEC_WORKING_MEM+CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ( (RV9_UPTOCIF_FRM_BUFFER_SIZE_CACHE_LINE+RV9_UPTOCIF_WORKING_MEM_SIZE_CACHE_LINE) > UPTOCIF_TEMP_TOTAL_MEM_SIZE)
        #undef UPTOCIF_TEMP_TOTAL_MEM_SIZE
        #undef UPTOCIF_FRM_BUFFER_SIZE
        #undef UPTOCIF_CODEC_WORKING_MEM_SIZE
        #define UPTOCIF_TEMP_TOTAL_MEM_SIZE     (RV9_UPTOCIF_FRM_BUFFER_SIZE_CACHE_LINE+RV9_UPTOCIF_WORKING_MEM_SIZE_CACHE_LINE)
        #define UPTOCIF_FRM_BUFFER_SIZE         RV9_UPTOCIF_FRM_BUFFER_SIZE_CACHE_LINE
        #define UPTOCIF_CODEC_WORKING_MEM_SIZE  RV9_UPTOCIF_WORKING_MEM_SIZE_CACHE_LINE
    #endif
#endif  /* __VE_RV_DEC_SW_SUPPORT__ */


#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
    #define MJPEG_UPTOCIF_BUFFER_SIZE (((MJPEG_UPTOCIF_DEC_MAX_WIDTH) * (MJPEG_UPTOCIF_DEC_MAX_HEIGHT) * (MJPEG_UPTOCIF_EXTRA_BUFFER_NUM + DECODER_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE*2))

    #define MJPEG_UPTOCIF_FRM_BUFFER_SIZE_CACHE_LINE ALIGN_X((MJPEG_UPTOCIF_BUFFER_SIZE+GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)

    #define MJPEG_UPTOCIF_WORKING_MEM_SIZE_CACHE_LINE ALIGN_X((MJPEG_UPTOCIF_DEC_WORKING_MEM+CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ( (MJPEG_UPTOCIF_FRM_BUFFER_SIZE_CACHE_LINE+MJPEG_UPTOCIF_WORKING_MEM_SIZE_CACHE_LINE) > UPTOCIF_TEMP_TOTAL_MEM_SIZE)
        #undef UPTOCIF_TEMP_TOTAL_MEM_SIZE
        #undef UPTOCIF_FRM_BUFFER_SIZE
        #undef UPTOCIF_CODEC_WORKING_MEM_SIZE
        #define UPTOCIF_TEMP_TOTAL_MEM_SIZE     (MJPEG_UPTOCIF_FRM_BUFFER_SIZE_CACHE_LINE+MJPEG_UPTOCIF_WORKING_MEM_SIZE_CACHE_LINE)
        #define UPTOCIF_FRM_BUFFER_SIZE         MJPEG_UPTOCIF_FRM_BUFFER_SIZE_CACHE_LINE
        #define UPTOCIF_CODEC_WORKING_MEM_SIZE  MJPEG_UPTOCIF_WORKING_MEM_SIZE_CACHE_LINE
    #endif
#endif  /* __VE_MJPEG_DEC_SW_SUPPORT__ */


#ifdef __VE_VP8_DEC_SW_SUPPORT__
    #if (VP8_UPTOCIF_EXTRA_BUFFER_NUM < 0)
        #error "UPTOCIF Scenario: Extra frame number of VP8 decoder should be no bigger than or equal to 0"
    #endif

    #define VP8_UPTOCIF_NORMAL_BUFFER_SIZE ((ALIGN_X((VP8_UPTOCIF_DEC_MAX_WIDTH+VP8_PADDING_SIZE), 32) * ALIGN_X((VP8_UPTOCIF_DEC_MAX_HEIGHT+VP8_PADDING_SIZE), 32) * (VP8_UPTOCIF_EXTRA_BUFFER_NUM + VP8_DECODER_ESSENTIAL_BUFFER_NUM)  * 3 / 2) + (CPU_CACHE_LINE_SIZE_MINE*2))
    #define VP8_UPTOCIF_FRM_BUFFER_SIZE_CACHE_LINE ALIGN_X((VP8_UPTOCIF_NORMAL_BUFFER_SIZE+GUARD_PATTERN_LENGTH), CPU_CACHE_LINE_SIZE_MINE)
    #define VP8_UPTOCIF_WORKING_MEM_SIZE_CACHE_LINE ALIGN_X((VP8_UPTOCIF_DEC_WORKING_MEM+CODEC_ADM_SIZE), CPU_CACHE_LINE_SIZE_MINE)

    #if ( (VP8_UPTOCIF_FRM_BUFFER_SIZE_CACHE_LINE + VP8_UPTOCIF_WORKING_MEM_SIZE_CACHE_LINE) > UPTOCIF_TEMP_TOTAL_MEM_SIZE)
        #undef UPTOCIF_TEMP_TOTAL_MEM_SIZE
        #undef UPTOCIF_FRM_BUFFER_SIZE
        #undef UPTOCIF_CODEC_WORKING_MEM_SIZE
        #define UPTOCIF_TEMP_TOTAL_MEM_SIZE     (VP8_UPTOCIF_FRM_BUFFER_SIZE_CACHE_LINE + VP8_UPTOCIF_WORKING_MEM_SIZE_CACHE_LINE)
        #define UPTOCIF_FRM_BUFFER_SIZE         VP8_UPTOCIF_FRM_BUFFER_SIZE_CACHE_LINE
        #define UPTOCIF_CODEC_WORKING_MEM_SIZE  VP8_UPTOCIF_WORKING_MEM_SIZE_CACHE_LINE
    #endif
#endif  // __VE_VP8_DEC_SW_SUPPORT__


#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__)  \
       || defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__) \
       || defined(__VE_RV_DEC_SW_SUPPORT__) || defined(__VE_MJPEG_DEC_SW_SUPPORT__) \
       || defined(__VE_VP8_DEC_SW_SUPPORT__))

    #if (UPTOCIF_FRM_BUFFER_SIZE == 0)
        #error "UPTOCIF Scenario: Cannot decide the size of frame buffer, no codec is enable"
    #endif
#endif


//Temp solution
#define DECODER_UPTOCIF_MEM_SIZE (UPTOCIF_FRM_BUFFER_SIZE + VIDEO_EXTRA_MEM_SIZE + VIDEO_DEC_WORKING_MEM_SIZE + UPTOCIF_CODEC_WORKING_MEM_SIZE)


// Defines for MDP for reserving video buffers
#if defined(__MPEG4_ENC_SW_SUPPORT__)
    #define VIDEO_ENC_RECORDER_MAX_WIDTH  (MPEG4_ENC_MAX_WIDTH)
    #define VIDEO_ENC_RECORDER_MAX_HEIGHT (MPEG4_ENC_MAX_HEIGHT)
#elif defined(__MPEG4_ENC_HW_SUPPORT__)
    #define VIDEO_ENC_RECORDER_MAX_WIDTH  (MPEG4_HW_ENC_MAX_WIDTH)
    #define VIDEO_ENC_RECORDER_MAX_HEIGHT (MPEG4_HW_ENC_MAX_HEIGHT)
#else
    #define VIDEO_ENC_RECORDER_MAX_WIDTH  (0)
    #define VIDEO_ENC_RECORDER_MAX_HEIGHT (0)
#endif


#if defined(__VIDEO_VT_SUPPORT__)
    #define VIDEO_ENC_VT_MAX_WIDTH  (MPEG4_ENC_VT_MAX_WIDTH)
    #define VIDEO_ENC_VT_MAX_HEIGHT (MPEG4_ENC_VT_MAX_HEIGHT)
#else
    #define VIDEO_ENC_VT_MAX_WIDTH  (0)
    #define VIDEO_ENC_VT_MAX_HEIGHT (0)
#endif


// Compare Encoder YUV Count
#define VIDEO_ENC_MIN_YUV_FRAME_NUM (0)
#if (MPEG4_HW_ENC_YUV_FRAME_NUM > VIDEO_ENC_MIN_YUV_FRAME_NUM)
    #undef VIDEO_ENC_MIN_YUV_FRAME_NUM
    #define VIDEO_ENC_MIN_YUV_FRAME_NUM (MPEG4_HW_ENC_YUV_FRAME_NUM)
#endif

#if (MPEG4_ENC_YUV_FRAME_NUM > VIDEO_ENC_MIN_YUV_FRAME_NUM)
    #undef VIDEO_ENC_MIN_YUV_FRAME_NUM
    #define VIDEO_ENC_MIN_YUV_FRAME_NUM (MPEG4_ENC_YUV_FRAME_NUM)
#endif

#if (MJPEG_ENC_YUV_FRAME_NUM > VIDEO_ENC_MIN_YUV_FRAME_NUM)
    #undef VIDEO_ENC_MIN_YUV_FRAME_NUM
    #define VIDEO_ENC_MIN_YUV_FRAME_NUM (MJPEG_ENC_YUV_FRAME_NUM)
#endif

#if (H264_ENC_YUV_FRAME_NUM > VIDEO_ENC_MIN_YUV_FRAME_NUM)
    #undef VIDEO_ENC_MIN_YUV_FRAME_NUM
    #define VIDEO_ENC_MIN_YUV_FRAME_NUM (H264_ENC_YUV_FRAME_NUM)
#endif

#if (MPEG4_ENC_VT_YUV_FRAME_NUM > VIDEO_ENC_MIN_YUV_FRAME_NUM)
    #undef VIDEO_ENC_MIN_YUV_FRAME_NUM
    #define VIDEO_ENC_MIN_YUV_FRAME_NUM (MPEG4_ENC_VT_YUV_FRAME_NUM)
#endif

#define VIDEO_ENC_MAX_YUV_FRAME_NUM (VIDEO_ENC_MIN_YUV_FRAME_NUM * 2)

#if (defined(__VE_MPEG4_ENC_HW_SUPPORT__) || defined(__VE_MPEG4_ENC_SW_SUPPORT__) || defined (__VE_MJPEG_ENC_SUPPORT__) \
       || defined(__VE_H264_ENC_SW_SUPPORT__) || defined(__VE_VIDEO_VT_SUPPORT__))
    #if (VIDEO_ENC_MAX_YUV_FRAME_NUM == 0)
        #error "Encoder Max YUV Frame Count is Zero"
    #endif
#else
    #if (VIDEO_ENC_MAX_YUV_FRAME_NUM == 0)
        #undef VIDEO_ENC_MAX_YUV_FRAME_NUM
        #define VIDEO_ENC_MAX_YUV_FRAME_NUM (1)
    #endif
#endif


#else  /* __VE_VIDEO_ARCHI_V2__ */


    // V2 is disabled

    // Defines for MDP for reserving video buffers
    #define VIDEO_ENC_RECORDER_MAX_WIDTH    (0)
    #define VIDEO_ENC_RECORDER_MAX_HEIGHT   (0)
    #define VIDEO_ENC_VT_MAX_WIDTH          (0)
    #define VIDEO_ENC_VT_MAX_HEIGHT         (0)

    #define MAX_FRM_BUFFER_WIDTH        0
    #define MAX_FRM_BUFFER_HEIGHT       0
    #define VIDEO_ENC_MAX_YUV_FRAME_NUM 0
#endif  /* __VE_VIDEO_ARCHI_V2__ */


#endif  /* VIDEO_CODEC_MEM_V2_H */

