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
 *   idp_mem.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 07 02 2012 chrono.wu
 * removed!
 * .
 *
 * 05 08 2012 chrono.wu
 * removed!
 * .
 *
 * 04 25 2012 chrono.wu
 * removed!
 * .
 *
 * 03 09 2012 chrono.wu
 * removed!
 * .
 *
 * 12 27 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 11 29 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 10 28 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 10 25 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 09 24 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 09 13 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_mem_mt6255_h__
#define __idp_mem_mt6255_h__

#include "sensor_capability.h"
#include "custom_emi_release.h"

/* ==================================================================
 *                           boundry size
 * ================================================================== */

//#define IDP_CAMERA_CAPTURE_TO_BARCODE_MAX_DISPLAYED_WIDTH (400) // TBD

#define IDP_CAMERA_CAPTURE_TO_JPEG_MAX_DISPLAYED_WIDTH (864)
#define IDP_CAMERA_CAPTURE_TO_JPEG_MAX_CAPTURED_WIDTH (2048)

//#define IDP_CAMERA_CAPTURE_TO_MEM_MAX_DST_WIDTH (720) // TBD

//#define IDP_CAMERA_PREVIEW_MAX_DISPLAYED_WIDTH (480) //HVGA
#define IDP_CAMERA_PREVIEW_MAX_DISPLAYED_WIDTH (864) //WVGA

//#define IDP_IMAGE_EFFECT_PIXEL_MAX_SRC_WIDTH (720) // TBD

//#define IDP_IMAGE_RESIZE_MAX_DST_WIDTH (720) // TBD

//#define IDP_JPEG_DECODE_MAX_SRC_WIDTH (2592) // TBD
#define IDP_JPEG_DECODE_MAX_DST_WIDTH (2592) // TBD

//#define IDP_JPEG_ENCODE_MAX_DST_WIDTH (2592) // TBD

//#define IDP_JPEG_ENCODE_PANORAMA_RGB565_MAX_SRC_WIDTH   (4096) 
//#define IDP_JPEG_ENCODE_PANORAMA_RGB565_MAX_SRC_HEIGHT   (65535) 

//#define IDP_JPEG_ENCODE_PANORAMA_YUV420_MAX_SRC_WIDTH   (4096) 
//#define IDP_JPEG_ENCODE_PANORAMA_YUV420_MAX_SRC_HEIGHT   (65535) 

//#define IDP_JPEG_RESIZE_MAX_DST_WIDTH (720) // TBD

//#define IDP_VIDEO_DECODE_MAX_SRC_WIDTH_HEIGHT (640)

#define IDP_VIDEO_DECODE_MAX_DISPLAYED_WIDTH (480)

//#define IDP_VIDEO_EDITOR_ENCODE_MAX_SRC_WIDTH (0) // feature not support
//#define IDP_VIDEO_EDITOR_ENCODE_MAX_ENCODED_WIDTH (0) // feature not support

//#define IDP_VIDEO_EDITOR_DECODE_MAX_DST_WIDTH (0) // feature not support
//#define IDP_VIDEO_EDITOR_DECODE_MAX_SRC_WIDTH_HEIGHT (0) // feature not support

/* ========================= video encode ============================ */

// display max size  
#define IDP_VIDEO_ENCODE_MAX_DISPLAYED_WIDTH        (864) //WVGA

// video spec max size
// MDP will use 1-pass when size exceed this, and performance is not gurateed. 
#if defined(__EMI_CLK_200MHZ__)
#define IDP_VIDEO_ENCODE_MAX_VIDEO_SPEC_WIDTH       (800)
#else
#define IDP_VIDEO_ENCODE_MAX_VIDEO_SPEC_WIDTH       (640)
#endif

// video with rotation max size
#define IDP_VIDEO_ENCODE_MAX_VIDEO_ROTATION_WIDTH          (640)


// TODO: check if this is to be supported.
//#ifdef IDP_H264_SLIM_MODE
// CIF resolution
//#define IDP_VIDEO_ENCODE_MAX_ENCODED_WIDTH (352)
//#define IDP_VIDEO_ENCODE_MAX_ENCODED_HEIGHT (288)
//#else // #ifdef IDP_H264_SLIM_MODE
//#define IDP_VIDEO_ENCODE_MAX_ENCODED_WIDTH (320)
//#define IDP_VIDEO_ENCODE_MAX_ENCODED_HEIGHT (240)
//#endif // #ifdef IDP_H264_SLIM_MODE

//#define IDP_VIDEO_ENCODE_MAX_ENCODED_WIDTH_HEIGHT (320)

//#define IDP_WEBCAM_MAX_CAPTURED_WIDTH (720) // TBD

//#define IDP_RGB2YUV_DISPLAY_WIDTH (480) // TBD

//#define IDP_VIDEO_CALL_ENCODE_MAX_ENCODED_WIDTH (176)
//#define IDP_VIDEO_CALL_ENCODE_MAX_ENCODED_HEIGHT (144)

//#define IDP_VIDEO_CALL_DECODE_MAX_SRC_WIDTH_HEIGHT (176)
//#define IDP_VIDEO_CALL_DECODE_MAX_DISPLAYED_WIDTH (144)

/* ==================================================================
 *                    working memory line count
 * ================================================================== */
//#define IDP_IMGDMA_JPEG_FIFO_LENGTH (0)

//#define IDP_RESZ_PRZ_FIFO_LENGTH (0)

/* ==================================================================
 *                     Equation for each path
 * ================================================================== */

//#define IDP_MEM_CONSUME_CAMERA_CAPTURE_TO_BARCODE_INTMEM (0)
//#define IDP_MEM_CONSUME_CAMERA_CAPTURE_TO_BARCODE_EXTMEM (0)

/* ========================= camera capture to jpeg ============================ */
/*
 * 1. IDP_MEM_CONSUME_CAMERA_CAPTURE_TO_JPEG_INTMEM :
 *    Not used now.
 *
 * 2. IDP_MEM_CONSUME_CAMERA_CAPTURE_TO_JPEG_EXTMEM: 
 *    To define external memory required by MDP.
 *
 *    The formula is SIZE * BPP + 32, SIZE maybe "capture size"(WIDTH * HEIGHT) for 
 *    normal capture or "preview size" (WIDTH * HEIGHT / 4) for webcam, depends on 
 *    different configuration. BPP is 2 for format YUYV422. + 32 is for align adjustment.
 *
 *    (A)Single cam & main is YUV
 *       It is normal case, use main "capture size" 
 *
 *    (B)Single cam & main is JPEG
 *       Although normal capture will not use MDP path, we still reserve "preview size" for
 *       webcam.
 *
 *    (C)Dual cam & main is YUV (it means sub is YUV)
 *       Main size > sub size, , use main "capture size"
 
 *    (D)Dual cam & main is JPEG (it means sub is YUV)
 *       For webcam, we must select the larger one of "main preivew size" or "sub capture size"    
 *
 *    (main cam + sub cam) = (JPEG + JPEG) or (YUV + JPEG) are not supported now. 
 *
 */

#define IDP_MEM_CONSUME_CAMERA_CAPTURE_TO_JPEG_INTMEM (0)  
//1.MT6256 Will need external 4.5M(3M*1.5).
//2.Origianl,MT6255 Will need 6M(3M*2, in order to rotate). + 4.5M(3M*1.5, no on-the-fly jpeg encode).
//3.Now, we allocate only 6M(3M*2), and ISP will increase 1.5M(origianl is 2~3M)=> 1.5+3=4.5M.
//MT6255's external memory is more than MT6256. The value is 3M.
//MT6256 original is 10M, now is 7.5M, we save 3M external memory.

#if defined(DUAL_CAMERA_SUPPORT) // dual cam

  #if defined(__JPEG_SENSOR_SUPPORT__) // main cam is jpeg, sub cam is yuv
    #define DUAL_CAM_MAIN_PREVIEW ((IMAGE_SENSOR_SOURCE_MAX_WIDTH * IMAGE_SENSOR_SOURCE_MAX_HEIGHT * 2 / 4 +31)&0xFFFFFFE0)
    #define DUAL_CAM_SUB_CAPTURE  ((IMAGE_SENSOR_SOURCE_SUB_MAX_WIDTH * IMAGE_SENSOR_SOURCE_SUB_MAX_HEIGHT * 2 +31)&0xFFFFFFE0)
    #define IDP_MEM_CONSUME_CAMERA_CAPTURE_TO_JPEG_EXTMEM ((DUAL_CAM_MAIN_PREVIEW > DUAL_CAM_SUB_CAPTURE) ? DUAL_CAM_MAIN_PREVIEW : DUAL_CAM_SUB_CAPTURE)
  #else                                // main cam is yuv, sub cam is yuv
    #define IDP_MEM_CONSUME_CAMERA_CAPTURE_TO_JPEG_EXTMEM ((IMAGE_SENSOR_SOURCE_MAX_WIDTH * IMAGE_SENSOR_SOURCE_MAX_HEIGHT * 2  +31)&0xFFFFFFE0)
  #endif

#else //defined(DUAL_CAMERA_SUPPORT) // single cam

  #if defined(__JPEG_SENSOR_SUPPORT__) // cam is jpeg
    #define IDP_MEM_CONSUME_CAMERA_CAPTURE_TO_JPEG_EXTMEM ((IMAGE_SENSOR_SOURCE_MAX_WIDTH * IMAGE_SENSOR_SOURCE_MAX_HEIGHT * 2 / 4 +31)&0xFFFFFFE0)
  #else                                // cam is yuv
    #define IDP_MEM_CONSUME_CAMERA_CAPTURE_TO_JPEG_EXTMEM ((IMAGE_SENSOR_SOURCE_MAX_WIDTH * IMAGE_SENSOR_SOURCE_MAX_HEIGHT * 2 +31)&0xFFFFFFE0)
  #endif

#endif //defined(DUAL_CAMERA_SUPPORT)


#define IDP_MEM_CONSUME_CAMERA_PREVIEW_INTMEM (0)
#define IDP_MEM_CONSUME_CAMERA_PREVIEW_EXTMEM (0)

/* ========================= jpeg encode & decode ============================ */
/*
 * For jpeg decode, the external memory is allocated for BRZ
 * When format is 444, it need (width * 24) 
 * When format is 420, it need (width * 24)
 * When format is 422, it need (width * 16)
 * When format is 422V, it need (width * 32) 
 *
 * For jpeg encode, the external memory is allocated for JPG_DMA
 * When format is 422, it need (width * 16) 
 * When format is 420, it need (width * 24)
 * When format is 400, it need (width * 8)
 * When format is 441, it need (width * 12) 
 *
 * The macro set "IDP_MEM_CONSUME_JPEG_XXX_CALC_EXTMEM" is need by jpeg driver. It
 * use those macros to get external from AP dynamically according to image size,
 * although we had defined the max one.
 *
 * For jpeg decode, IDP_MEM_CONSUME_JPEG_DECODE_EXTMEM & IDP_MEM_CONSUME_JPEG_DECODE_YUV422V_EXTMEM
 * MDP define the max width, 4096
 *
 * For jpeg encode, IDP_MEM_CONSUME_JPEG_ENCODE_EXTMEM & IDP_MEM_CONSUME_JPEG_ENCODE_YUV420_EXTMEM
 * use "JPEG_MAX_WIDTH" defined by jpeg driver "jpeg_mem.h"
 *
 */
#define IDP_MEM_CONSUME_JPEG_DECODE_CALC_INTMEM (0)
#define IDP_MEM_CONSUME_JPEG_DECODE_CALC_EXTMEM(max_width) (0)
#define IDP_MEM_CONSUME_JPEG_DECODE_CALC_YUV422V_EXTMEM(max_width) (0)

#define IDP_MEM_CONSUME_JPEG_ENCODE_CALC_INTMEM (0)
#define IDP_MEM_CONSUME_JPEG_ENCODE_CALC_EXTMEM(max_width) (0)
#define IDP_MEM_CONSUME_JPEG_ENCODE_CALC_YUV420_EXTMEM(max_width) (0)

#define IDP_MEM_CONSUME_JPEG_DECODE_INTMEM (0)
#define IDP_MEM_CONSUME_JPEG_DECODE_EXTMEM (0)
#define IDP_MEM_CONSUME_JPEG_DECODE_YUV422V_EXTMEM (0)

#define IDP_MEM_CONSUME_JPEG_ENCODE_INTMEM (0)
#define IDP_MEM_CONSUME_JPEG_ENCODE_EXTMEM (0)
#define IDP_MEM_CONSUME_JPEG_ENCODE_YUV420_EXTMEM (0)

/* ========================= mjpeg encode & decode ============================ */
/* 
 * Although the feature option is __MJPEG_DEC_SW_SUPPORT__, but it means HW support
 * for MDP's viewpoint. Allocate external memory if & only if
 * 1. MJPEG is use MDP to do jpeg encode/decode.
 * 2. MDP need external memory for jpeg encode/decode for MJPEG scenaro. 
 * For memory calculation, see section "jpeg encode & decode" for detail.
 *
 */
#if defined(__MJPEG_DEC_SW_SUPPORT__) 
   #define IDP_MEM_CONSUME_MJPEG_DECODE_INTMEM (0)
   #define IDP_MEM_CONSUME_MJPEG_DECODE_EXTMEM (0)
   #define IDP_MEM_CONSUME_MJPEG_DECODE_YUV422V_EXTMEM (0)
#endif

#if defined(__MJPEG_ENC_SW_SUPPORT__) 
   #define IDP_MEM_CONSUME_MJPEG_ENCODE_INTMEM (0)
   #define IDP_MEM_CONSUME_MJPEG_ENCODE_EXTMEM (0)
   #define IDP_MEM_CONSUME_MJPEG_ENCODE_YUV420_EXTMEM (0)
   //#define IDP_MEM_CONSUME_MJPEG_ENCODE_EXTMEM (MJPEG_ENC_MAX_WIDTH * 16 + 32)
   //#define IDP_MEM_CONSUME_MJPEG_ENCODE_YUV420_EXTMEM (MJPEG_ENC_MAX_WIDTH * 24 + 32)

#endif

/* ========================= panorama encode & decode ============================ */
/* 
 * Those macros are defined for panorama encode & decode. 
 * PANORAMA_JPEG_ENCODE_SOURCE_MAX_WIDTH & PANORAMA_JPEG_ENCODE_SOURCE_MAX_WIDTH are
 * defined in feature_comm_def.h in custom folder
 * For memory calculation, see section "jpeg encode & decode" for detail.
 *
 */
#if defined(__PANORAMA_VIEW_SUPPORT__) || defined(__AUTOCAP_PANORAMA_SUPPORT__)
   #define IDP_MEM_CONSUME_PANORAMA_DECODE_INTMEM (0)
   #define IDP_MEM_CONSUME_PANORAMA_DECODE_EXTMEM ((PANORAMA_JPEG_ENCODE_SOURCE_MAX_WIDTH * 24) + 32)
   #define IDP_MEM_CONSUME_PANORAMA_DECODE_YUV422V_EXTMEM ((PANORAMA_JPEG_ENCODE_SOURCE_MAX_WIDTH * 32) + 32)

   #define IDP_MEM_CONSUME_PANORAMA_ENCODE_INTMEM (0)
   #define IDP_MEM_CONSUME_PANORAMA_ENCODE_EXTMEM ((PANORAMA_JPEG_ENCODE_SOURCE_MAX_WIDTH * 16) + 32)
   #define IDP_MEM_CONSUME_PANORAMA_ENCODE_YUV420_EXTMEM ((PANORAMA_JPEG_ENCODE_SOURCE_MAX_WIDTH * 24) + 32)
#endif


//#define IDP_MEM_CONSUME_JPEG_RESIZE_RRZ_COARSE_MAX_ALLOWABLE_INTMEM (0)
//#define IDP_MEM_CONSUME_JPEG_RESIZE_RRZ_COARSE_MAX_ALLOWABLE_EXTMEM (0)

//#define IDP_MEM_CONSUME_JPEG_RESIZE_INTMEM (0)
//#define IDP_MEM_CONSUME_JPEG_RESIZE_EXTMEM (0)

#define IDP_MEM_CONSUME_RGB2YUV_INTMEM          (0)
#define IDP_MEM_CONSUME_RGB2YUV_EXTMEM          (0)

//#define IDP_MEM_CONSUME_VIDEO_CALL_INTMEM              (0)
//#define IDP_MEM_CONSUME_VIDEO_CALL_EXTMEM              (0)

//#define IDP_MEM_CONSUME_VIDEO_DECODE_MP4_INTMEM (0)
//#define IDP_MEM_CONSUME_VIDEO_DECODE_MP4_EXTMEM (0)

//#define IDP_MEM_CONSUME_VIDEO_DECODE_H264_INTMEM (0)
//#define IDP_MEM_CONSUME_VIDEO_DECODE_H264_EXTMEM (0)

//#define IDP_MEM_CONSUME_VIDEO_EDITOR_ENCODE_INTMEM (0)
//#define IDP_MEM_CONSUME_VIDEO_EDITOR_ENCODE_EXTMEM (0)

//#define IDP_MEM_CONSUME_VIDEO_EDITOR_DECODE_INTMEM (0)
//#define IDP_MEM_CONSUME_VIDEO_EDITOR_DECODE_EXTMEM (0)

//video encode support maxima 864x480 for 2 pass dummy buffer
#define IDP_MEM_CONSUME_VIDEO_ENCODE_INTMEM (0)
#define IDP_MEM_CONSUME_VIDEO_ENCODE_EXTMEM (IDP_VIDEO_ENCODE_MAX_VIDEO_SPEC_WIDTH * 480 * 3 / 2 + 32)

//#define IDP_MEM_CONSUME_WEBCAM_INTMEM (0)
//#define IDP_MEM_CONSUME_WEBCAM_EXTMEM (0)

/* ========================= video call encode ============================ */
#define IDP_MEM_CONSUME_VIDEO_CALL_ENCODE_INTMEM (0)
#define IDP_MEM_CONSUME_VIDEO_CALL_ENCODE_EXTMEM (((176 * 144 * 3)>>1) + 32 ) * 2

/* ========================= video call decode ============================ */
//#define IDP_MEM_CONSUME_VIDEO_CALL_DECODE_INTMEM (0)
//#define IDP_MEM_CONSUME_VIDEO_CALL_DECODE_EXTMEM (0)


#endif // #ifndef __idp_mem_mt6255_h__
