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
 *   hw_video_deocde_custom.h
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef HW_VIDEO_DECODE_CUSTOM_H
#define HW_VIDEO_DECODE_CUSTOM_H

#include "drv_comm.h"
#ifdef __VIDEO_ARCHI_V2__
#include "video_codec_custom_type.h"
#include "hal_custom_video_if.h"

#ifdef __MPEG4_DEC_HW_SUPPORT__
#include "mp4_decore_v2.h"
#endif

/******************************************************************************
* Setting for MT6268 series
******************************************************************************/
#if (defined(MT6268))

#ifdef __MPEG4_DEC_HW_SUPPORT__
#define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_720x480
//#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_720x480
#define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_720x480
#define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_720x480
#endif

#ifdef __H264_DEC_HW_SUPPORT__
#define H264_SUPPORT_RESOLUTION_BP          RESOLUTION_720x480
#define H264_MAX_NORMAL_MODE_RESOLUTION_BP  RESOLUTION_720x480
#define H264_DECODER_LEVEL_BP               Level_20
#endif
#endif  // (defined(MT6268))

/******************************************************************************
* Setting for VT scenario
******************************************************************************/
#ifdef __VIDEO_VT_SUPPORT__
#ifdef __MPEG4_DEC_HW_SUPPORT__
    #define MPEG4_VT_DEC_MAX_WIDTH         176
    #define MPEG4_VT_DEC_MAX_HEIGHT        144
    #define MPEG4_VT_SUPPORT_RESOLUTION    RESOLUTION_176x144
    #define MPEG4_VT_DEC_WORKING_MEM \
        ((MP4_DEC_QS_WORK_SIZE(MPEG4_VT_DEC_MAX_WIDTH,MPEG4_VT_DEC_MAX_HEIGHT) + CPU_CACHE_LINE_SIZE_MINE*2) + \
         (MP4_DEC_MAX_WORK_MEMORY(MPEG4_VT_DEC_MAX_WIDTH,MPEG4_VT_DEC_MAX_HEIGHT)  + CPU_CACHE_LINE_SIZE_MINE*2))
#endif /* __MPEG4_DEC_HW_SUPPORT__ */
#endif /* __VIDEO_VT_SUPPORT__*/

/******************************************************************************
* Setting for QVGA scenario
******************************************************************************/
#ifdef __MPEG4_DEC_HW_SUPPORT__
    #define MPEG4_QVGA_DEC_MAX_WIDTH         320
    #define MPEG4_QVGA_DEC_MAX_HEIGHT        240
    #define MPEG4_QVGA_DEC_WORKING_MEM \
         ((MP4_DEC_QS_WORK_SIZE(MPEG4_QVGA_DEC_MAX_WIDTH,MPEG4_QVGA_DEC_MAX_HEIGHT) + CPU_CACHE_LINE_SIZE_MINE*2) +\
          (MP4_DEC_MAX_WORK_MEMORY(MPEG4_QVGA_DEC_MAX_WIDTH,MPEG4_QVGA_DEC_MAX_HEIGHT)  + CPU_CACHE_LINE_SIZE_MINE*2))
#endif /* __MPEG4_DEC_HW_SUPPORT__ */

#ifdef __H264_DEC_HW_SUPPORT__
    #define H264_QVGA_DEC_MAX_WIDTH          320
    #define H264_QVGA_DEC_MAX_HEIGHT         240
    #define H264_QVGA_DEC_WORKING_MEM        (1322*1024)
    #define H264_QVGA_DECODER_LEVEL          Level_11
    #define H264_QVGA_DEC_DPB_SIZE           1024
#endif /* __H264_DEC_SW_SUPPORT__ */

/******************************************************************************
* Setting for UPTOQVGA scenario
******************************************************************************/
#ifdef __MPEG4_DEC_HW_SUPPORT__
    #define MPEG4_UPTOQVGA_DEC_MAX_WIDTH         320
    #define MPEG4_UPTOQVGA_DEC_MAX_HEIGHT        240
    #define MPEG4_UPTOQVGA_DEC_WORKING_MEM \
        ((MP4_DEC_QS_WORK_SIZE(MPEG4_UPTOQVGA_DEC_MAX_WIDTH,MPEG4_UPTOQVGA_DEC_MAX_HEIGHT) + CPU_CACHE_LINE_SIZE_MINE*2) +\
         (MP4_DEC_MAX_WORK_MEMORY(MPEG4_UPTOQVGA_DEC_MAX_WIDTH,MPEG4_UPTOQVGA_DEC_MAX_HEIGHT)  + CPU_CACHE_LINE_SIZE_MINE*2))
#endif /* __MPEG4_DEC_HW_SUPPORT__ */

#ifdef __H264_DEC_HW_SUPPORT__
    #define H264_UPTOQVGA_DEC_MAX_WIDTH          320
    #define H264_UPTOQVGA_DEC_MAX_HEIGHT         240
    #define H264_UPTOQVGA_DEC_WORKING_MEM        (1322*1024)
    #define H264_UPTOQVGA_DECODER_LEVEL          Level_11
    #define H264_UPTOQVGA_DEC_DPB_SIZE           1024
#endif /* __H264_DEC_SW_SUPPORT__ */


/******************************************************************************
* Setting for QVGAMPEG4SP scenario
******************************************************************************/
#ifdef __MPEG4_DEC_HW_SUPPORT__
    #define MPEG4_QVGAMPEG4SP_DEC_MAX_WIDTH        320
    #define MPEG4_QVGAMPEG4SP_DEC_MAX_HEIGHT       240
    #define MPEG4_QVGAMPEG4SP_DEC_WORKING_MEM       \
        ((MP4_DEC_QS_WORK_SIZE(MPEG4_QVGAMPEG4SP_DEC_MAX_WIDTH, MPEG4_QVGAMPEG4SP_DEC_MAX_HEIGHT) + CPU_CACHE_LINE_SIZE_MINE*2) +\
         (MP4_DEC_MAX_WORK_MEMORY(MPEG4_QVGAMPEG4SP_DEC_MAX_WIDTH, MPEG4_QVGAMPEG4SP_DEC_MAX_HEIGHT)  + CPU_CACHE_LINE_SIZE_MINE*2))
#endif  /* __MPEG4_DEC_HW_SUPPORT__ */


/******************************************************************************
* Setting for QCIF scenario
******************************************************************************/
#ifdef __MPEG4_DEC_HW_SUPPORT__
    #define MPEG4_QCIF_DEC_MAX_WIDTH         176
    #define MPEG4_QCIF_DEC_MAX_HEIGHT        144
    #define MPEG4_QCIF_DEC_WORKING_MEM \
         ((MP4_DEC_QS_WORK_SIZE(MPEG4_QCIF_DEC_MAX_WIDTH,MPEG4_QCIF_DEC_MAX_HEIGHT) + CPU_CACHE_LINE_SIZE_MINE*2) +\
          (MP4_DEC_MAX_WORK_MEMORY(MPEG4_QCIF_DEC_MAX_WIDTH,MPEG4_QCIF_DEC_MAX_HEIGHT)  + CPU_CACHE_LINE_SIZE_MINE*2))
#endif /* __MPEG4_DEC_HW_SUPPORT__ */

#ifdef __H264_DEC_HW_SUPPORT__
    #define H264_QCIF_DEC_MAX_WIDTH          176
    #define H264_QCIF_DEC_MAX_HEIGHT         144
    #define H264_QCIF_DEC_WORKING_MEM        (1250*1024) // Need to recalculate, this is temp value
    #define H264_QCIF_DECODER_LEVEL          Level_10
    #define H264_QCIF_DEC_DPB_SIZE           1024  // Ignore
#endif /* __H264_DEC_SW_SUPPORT__ */

/******************************************************************************
* Setting for VGA scenario
******************************************************************************/
#ifdef __MPEG4_DEC_HW_SUPPORT__
    #define MPEG4_VGA_DEC_MAX_WIDTH         640
    #define MPEG4_VGA_DEC_MAX_HEIGHT        480
    #define MPEG4_VGA_DEC_WORKING_MEM \
         ((MP4_DEC_QS_WORK_SIZE(MPEG4_VGA_DEC_MAX_WIDTH,MPEG4_VGA_DEC_MAX_HEIGHT) + CPU_CACHE_LINE_SIZE_MINE*2) +\
          (MP4_DEC_MAX_WORK_MEMORY(MPEG4_VGA_DEC_MAX_WIDTH,MPEG4_VGA_DEC_MAX_HEIGHT)  + CPU_CACHE_LINE_SIZE_MINE*2))
#endif /* __MPEG4_DEC_HW_SUPPORT__ */

#ifdef __H264_DEC_HW_SUPPORT__
    #define H264_VGA_DEC_MAX_WIDTH          640
    #define H264_VGA_DEC_MAX_HEIGHT         480
    #define H264_VGA_DEC_WORKING_MEM        (1250*1024) // Need to recalculate, this is temp value
    #define H264_VGA_DECODER_LEVEL          Level_22
    #define H264_VGA_DEC_DPB_SIZE           1024 // Ignore
#endif /* __H264_DEC_SW_SUPPORT__ */


/******************************************************************************
* Setting for CIF scenario
******************************************************************************/
#ifdef __MPEG4_DEC_HW_SUPPORT__
    #define MPEG4_CIF_DEC_MAX_WIDTH         352
    #define MPEG4_CIF_DEC_MAX_HEIGHT        288
    #define MPEG4_CIF_DEC_WORKING_MEM \
         ((MP4_DEC_QS_WORK_SIZE(MPEG4_CIF_DEC_MAX_WIDTH,MPEG4_CIF_DEC_MAX_HEIGHT) + CPU_CACHE_LINE_SIZE_MINE*2) +\
          (MP4_DEC_MAX_WORK_MEMORY(MPEG4_CIF_DEC_MAX_WIDTH,MPEG4_CIF_DEC_MAX_HEIGHT)  + CPU_CACHE_LINE_SIZE_MINE*2))
#endif /* __MPEG4_DEC_HW_SUPPORT__ */

#ifdef __H264_DEC_HW_SUPPORT__
    #define H264_CIF_DEC_MAX_WIDTH          352
    #define H264_CIF_DEC_MAX_HEIGHT         288
    #define H264_CIF_DEC_WORKING_MEM        (1250*1024) // Need to recalculate, this is temp value
    #define H264_CIF_DECODER_LEVEL          Level_11
    #define H264_CIF_DEC_DPB_SIZE           1024  // Ignore
#endif /* __H264_DEC_SW_SUPPORT__ */

/******************************************************************************
* Setting for UPTOCIF scenario
******************************************************************************/
#ifdef __MPEG4_DEC_HW_SUPPORT__
    #define MPEG4_UPTOCIF_DEC_MAX_WIDTH         352
    #define MPEG4_UPTOCIF_DEC_MAX_HEIGHT        288
    #define MPEG4_UPTOCIF_DEC_WORKING_MEM \
         ((MP4_DEC_QS_WORK_SIZE(MPEG4_UPTOCIF_DEC_MAX_WIDTH,MPEG4_UPTOCIF_DEC_MAX_HEIGHT) + CPU_CACHE_LINE_SIZE_MINE*2) +\
          (MP4_DEC_MAX_WORK_MEMORY(MPEG4_UPTOCIF_DEC_MAX_WIDTH,MPEG4_UPTOCIF_DEC_MAX_HEIGHT)  + CPU_CACHE_LINE_SIZE_MINE*2))
#endif /* __MPEG4_DEC_HW_SUPPORT__ */

#ifdef __H264_DEC_HW_SUPPORT__
    #define H264_UPTOCIF_DEC_MAX_WIDTH          352
    #define H264_UPTOCIF_DEC_MAX_HEIGHT         288
    #define H264_UPTOCIF_DEC_WORKING_MEM        (1250*1024) // Need to recalculate, this is temp value
    #define H264_UPTOCIF_DECODER_LEVEL          Level_11
    #define H264_UPTOCIF_DEC_DPB_SIZE           1024  // Ignore
#endif /* __H264_DEC_SW_SUPPORT__ */



/******************************************************************************
* Replace with custom setting
******************************************************************************/
// MPEG4 decode
#if defined(__MPEG4_DEC_HW_SUPPORT__)
    #ifdef MPEG4_DEC_CUSTOM_FRAME_SETTING_ENABLE
        // 1:1
        #ifdef MPEG4_CUSTOM_MAX_NORMAL_MODE_RESOLUTION_SP
            #undef MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP
            #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP (MPEG4_CUSTOM_MAX_NORMAL_MODE_RESOLUTION_SP)
        #endif
        #if 0
/* under construction !*/
        #ifdef MPEG4_CUSTOM_SUPPORT_RESOLUTION_1_TO_2_SP
/* under construction !*/
/* under construction !*/
        #endif
        #endif  // 0
        // 1:4
        #ifdef MPEG4_CUSTOM_SUPPORT_RESOLUTION_SP
            #undef MPEG4_SUPPORT_RESOLUTION_SP
            #define MPEG4_SUPPORT_RESOLUTION_SP (MPEG4_CUSTOM_SUPPORT_RESOLUTION_SP)
        #endif
        // 1:8
        #ifdef MPEG4_CUSTOM_SUPPORT_RESOLUTION_1_TO_8_SP
            #undef MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP
            #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP (MPEG4_CUSTOM_SUPPORT_RESOLUTION_1_TO_8_SP)
        #endif
    #endif /* MPEG4_DEC_CUSTOM_FRAME_SETTING_ENABLE */
#endif /* __MPEG4_DEC_SW_SUPPORT__ */

// H264 decode
#if defined(__H264_DEC_HW_SUPPORT__)
    #ifdef H264_DEC_CUSTOM_FRAME_SETTING_ENABLE
        #ifdef H264_CUSTOM_SUPPORT_RESOLUTION_BP
            #undef H264_SUPPORT_RESOLUTION_BP
            #define H264_SUPPORT_RESOLUTION_BP (H264_CUSTOM_SUPPORT_RESOLUTION_BP)
        #endif
        #ifdef H264_CUSTOM_MAX_NORMAL_MODE_RESOLUTION_BP
            #undef H264_MAX_NORMAL_MODE_RESOLUTION_BP
            #define H264_MAX_NORMAL_MODE_RESOLUTION_BP (H264_CUSTOM_MAX_NORMAL_MODE_RESOLUTION_BP)
        #endif
        #ifdef H264_CUSTOM_DECODER_LEVEL_BP
            #undef H264_DECODER_LEVEL_BP
            #define H264_DECODER_LEVEL_BP (H264_CUSTOM_DECODER_LEVEL_BP)
        #endif
    #endif /* H264_DEC_CUSTOM_FRAME_SETTING_ENABLE */
#endif /* __H264_DEC_SW_SUPPORT__ */

/******************************************************************************
* translate custom setting
******************************************************************************/
#ifdef __MPEG4_DEC_HW_SUPPORT__
    #if 0
/* under construction !*/
    #if (MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP == RESOLUTION_720x480)
/* under construction !*/
/* under construction !*/
    #else
/* under construction !*/
    #endif
    #endif  // 0
    // 1:4
    #if (MPEG4_SUPPORT_RESOLUTION_SP == RESOLUTION_720x480)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_SP       720
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_SP      480
    #else
        #error "This resolution is not support by MPEG-4 HW decoder"
    #endif
    // 1:8
    #if (MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP == RESOLUTION_720x480)
        #define MPEG4_DEC_MAX_WIDTH_SP              720
        #define MPEG4_DEC_MAX_HEIGHT_SP             480
        #define MPEG4_DEC_WORKING_MEM_SP \
                ((MP4_DEC_QS_WORK_SIZE(MPEG4_DEC_MAX_WIDTH_SP, MPEG4_DEC_MAX_HEIGHT_SP) + (CPU_CACHE_LINE_SIZE_MINE * 2)) + \
                 (MP4_DEC_MAX_WORK_MEMORY(MPEG4_DEC_MAX_WIDTH_SP, MPEG4_DEC_MAX_HEIGHT_SP)  + CPU_CACHE_LINE_SIZE_MINE * 2))
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_SP MPEG4_DEC_WORKING_MEM_SP
    #else
        #error "This resolution is not support by MPEG-4 HW decoder"
    #endif

    #if (MPEG4_DEC_WORKING_MEM == -1)
        #error "This resolution is not support by MPEG-4 HW decoder"
    #endif

    #if (MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP == RESOLUTION_720x480)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_SP         720
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_SP        480
    #else
        #error "This resolution is not support by MPEG-4 HW decode (Normal mode)"
    #endif

#endif /*__MPEG4_DEC_HW_SUPPORT__*/

#ifdef __H264_DEC_HW_SUPPORT__
    #if (H264_SUPPORT_RESOLUTION_BP == RESOLUTION_720x480)
        #define H264_DEC_MAX_WORKING_MEM_BP         (1322*1024)
        #define H264_DEC_MAX_WORKING_PREVMEM_BP     (1322*1024)
        #define H264_DEC_MAX_WIDTH_BP               720
        #define H264_DEC_MAX_HEIGHT_BP              480
    #else
        #error "This resolution is not support by H264 HW decoder"
    #endif

    /*FIXME*/
    #define H264_DEC_DPB_SIZE_BP  1024

    #if (H264_DEC_MAX_WORKING_MEM_BP == -1)
        #error "This resolution is not support by H264 HW decoder"
    #endif

    #if (H264_MAX_NORMAL_MODE_RESOLUTION_BP == RESOLUTION_720x480)
        #define H264_DEC_MAX_NORMAL_WIDTH_BP        720
        #define H264_DEC_MAX_NORMAL_HEIGHT_BP       480
    #else
        #error "This resolution is not support by mpeg4 decoder (Normal mode)"
    #endif

#endif /*__H264_DEC_HW_SUPPORT__*/

#endif /* __VIDEO_ARCHI_V2__ */
#endif /* VIDEO_CODEC_MEM_CUSTOM_V2_H */
