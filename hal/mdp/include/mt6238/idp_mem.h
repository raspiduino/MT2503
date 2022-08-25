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
 *
 * Project:
 * --------
 *	 Maui
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
 * 10 20 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 09 21 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 08 25 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 07 27 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 05 23 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 05 14 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 04 27 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 04 12 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 03 30 2011 hung-wen.hsieh
 * removed!
 * Check in video call encode drop frame mechanism.
 *
 * 12 22 2010 chrono.wu
 * removed!
 * .
 *
 * 11 23 2010 hung-wen.hsieh
 * removed!
 * .
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * add to source control recursely
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_mem_mt6238_h__
#define __idp_mem_mt6238_h__


/* ==================================================================
 *                           boundry size
 * ================================================================== */

#define IDP_CAMERA_CAPTURE_TO_BARCODE_MAX_DISPLAYED_WIDTH        (400)

#define IDP_CAMERA_CAPTURE_TO_JPEG_MAX_DISPLAYED_WIDTH        (480)
#define IDP_CAMERA_CAPTURE_TO_JPEG_MAX_CAPTURED_WIDTH        (2592)

#define IDP_CAMERA_CAPTURE_TO_MEM_MAX_DST_WIDTH        (720)

#define IDP_CAMERA_PREVIEW_MAX_DISPLAYED_WIDTH        (400)

#define IDP_IMAGE_EFFECT_PIXEL_MAX_SRC_WIDTH        (720)

#define IDP_IMAGE_RESIZE_MAX_DST_WIDTH        (720)

#define IDP_JPEG_DECODE_MAX_SRC_WIDTH        (720)
#define IDP_JPEG_DECODE_MAX_DST_WIDTH        (720)

#define IDP_JPEG_ENCODE_MAX_DST_WIDTH        (2592)

#define IDP_JPEG_ENCODE_PANORAMA_RGB565_MAX_SRC_WIDTH   (4096) 
#define IDP_JPEG_ENCODE_PANORAMA_RGB565_MAX_SRC_HEIGHT   (4096) 

#define IDP_JPEG_ENCODE_PANORAMA_YUV420_MAX_SRC_WIDTH   (0) 
#define IDP_JPEG_ENCODE_PANORAMA_YUV420_MAX_SRC_HEIGHT   (0) 

#define IDP_JPEG_RESIZE_MAX_DST_WIDTH        (720)

#define IDP_VIDEO_DECODE_MAX_SRC_WIDTH_HEIGHT (720)
#define IDP_VIDEO_DECODE_MAX_DISPLAYED_WIDTH  (480)

#define IDP_VIDEO_EDITOR_ENCODE_MAX_SRC_WIDTH            (720)
#define IDP_VIDEO_EDITOR_ENCODE_MAX_ENCODED_WIDTH        (720)

#define IDP_VIDEO_EDITOR_DECODE_MAX_DST_WIDTH         (720)
#define IDP_VIDEO_EDITOR_DECODE_MAX_SRC_WIDTH_HEIGHT  (720)

#define IDP_VIDEO_ENCODE_MAX_DISPLAYED_WIDTH        (480)
#define IDP_VIDEO_ENCODE_MAX_DISPLAYED_HEIGHT       (480)

#ifdef IDP_H264_SLIM_MODE
// CIF resolution
#define IDP_VIDEO_ENCODE_MAX_ENCODED_WIDTH          (352)
#define IDP_VIDEO_ENCODE_MAX_ENCODED_HEIGHT         (288)
#else // IDP_H264_SLIM_MODE
#define IDP_VIDEO_ENCODE_MAX_ENCODED_WIDTH          (720)
#define IDP_VIDEO_ENCODE_MAX_ENCODED_HEIGHT         (480)
#endif // IDP_H264_SLIM_MODE

#define IDP_VIDEO_ENCODE_MAX_ENCODED_WIDTH_HEIGHT   (720)

#define IDP_WEBCAM_MAX_CAPTURED_WIDTH    (720)

#define IDP_RGB2YUV_DISPLAY_WIDTH        (400)

#define IDP_VIDEO_CALL_ENCODE_MAX_ENCODED_WIDTH          (720)
#define IDP_VIDEO_CALL_ENCODE_MAX_ENCODED_HEIGHT         (480)

#define IDP_VIDEO_CALL_DECODE_MAX_SRC_WIDTH_HEIGHT       (720)
#define IDP_VIDEO_CALL_DECODE_MAX_DISPLAYED_WIDTH        (480)

/* ==================================================================
 *                    working memory line count
 * ================================================================== */

#define IDP_IMGDMA_IRT0_FIFO_LENGTH         (8)
#define IDP_IMGDMA_IRT0_FIFO_LENGTH_FOR_VIDEO_DECODE         (8)
#define IDP_IMGDMA_IRT0_FIFO_LENGTH_FOR_VIDEO_DECODE_VP7     (8)
#define IDP_IMGDMA_IRT0_FIFO_LENGTH_FOR_VIDEO_CALL_DECODE    (8)

#define IDP_IMGDMA_IRT1_FIFO_LENGTH         (8)
#define IDP_IMGDMA_IRT1_FIFO_LENGTH_FOR_VIDEO_DECODE         (8)
#define IDP_IMGDMA_IRT1_FIFO_LENGTH_FOR_CAPTURE_TO_MEM       (16)
#define IDP_IMGDMA_IRT1_FIFO_LENGTH_FOR_VIDEO_ENCODE_VR5     (16)

#define IDP_IMGDMA_IRT2_FIFO_LENGTH         (8)
#define IDP_IMGDMA_IRT2_FIFO_LENGTH_FOR_VIDEO_DECODE_VP7     (16)
#define IDP_IMGDMA_IRT2_FIFO_LENGTH_FOR_VIDEO_ENCODE_VR5     (16)

#define IDP_IMGDMA_VIDEO_ENCODE_FIFO_LENGTH                           (8)
#define IDP_IMGDMA_VIDEO_ENCODE_FIFO_LENGTH_FOR_VIDEO_ENCODE_VR1_VR2  (8)
#define IDP_IMGDMA_VIDEO_ENCODE_FIFO_LENGTH_FOR_VIDEO_ENCODE_VR5      (8)
#define IDP_IMGDMA_VIDEO_ENCODE_FIFO_LENGTH_FOR_VIDEO_CALL_ENCODE     (8)

/* The working memory line number should be 16 rather than 8
 * (means double buffer) to capture a 300M JPEG image.
 *
 * If the internal memory size is not enough, than MMI
 * should capture a YUV420 jpeg file rather than YUV411 or
 * YUV422.
 */
#define IDP_IMGDMA_JPEG_FIFO_LENGTH         (16)
#define IDP_IMGDMA_JPEG_FIFO_LENGTH_FOR_JPEG_ENCODE         (8)

#define IDP_RESZ_PRZ_FIFO_LENGTH                             (4)
#define IDP_RESZ_PRZ_FIFO_LENGTH_CAPTURE_TO_JPEG             (8)
#define IDP_RESZ_PRZ_FIFO_LENGTH_VP7                         (8)
#define IDP_RESZ_PRZ_FIFO_LENGTH_FOR_VIDEO_ENCODE_VR1_VR2    (4)
#define IDP_RESZ_PRZ_FIFO_LENGTH_FOR_VIDEO_ENCODE_VR5        (6)
#define IDP_RESZ_PRZ_FIFO_LENGTH_FOR_CAMERA_CAPTURE_TO_JPEG  (8)
#define IDP_RESZ_PRZ_FIFO_LENGTH_FOR_VIDEO_CALL_DECODE       (8)

/* ==================================================================
 *                     Equation for each path
 * ================================================================== */

#define IDP_MEM_CONSUME_JPEG_DECODE_CALC_INTMEM (0)
#define IDP_MEM_CONSUME_JPEG_DECODE_CALC_EXTMEM(max_width) (0)
#define IDP_MEM_CONSUME_JPEG_DECODE_CALC_YUV422V_EXTMEM(max_width) (0)

#define IDP_MEM_CONSUME_JPEG_ENCODE_CALC_INTMEM (0)
#define IDP_MEM_CONSUME_JPEG_ENCODE_CALC_EXTMEM(max_width) (0)
#define IDP_MEM_CONSUME_JPEG_ENCODE_CALC_YUV420_EXTMEM(max_width) (0)

//#define IDP_MEM_CONSUME_JPEG_DECODE_INTMEM (0)
//#define IDP_MEM_CONSUME_JPEG_DECODE_EXTMEM (4096 * 24 + 32)
//#define IDP_MEM_CONSUME_JPEG_DECODE_YUV422V_EXTMEM (4096 * 32 + 32)

//#define IDP_MEM_CONSUME_JPEG_ENCODE_INTMEM (0)
//#define IDP_MEM_CONSUME_JPEG_ENCODE_EXTMEM (JPEG_MAX_WIDTH * 16 + 32)
//#define IDP_MEM_CONSUME_JPEG_ENCODE_YUV420_EXTMEM (JPEG_MAX_WIDTH * 24 + 32)


#if defined(__MJPEG_DEC_SW_SUPPORT__) 
   #define IDP_MEM_CONSUME_MJPEG_DECODE_INTMEM (0)
   #define IDP_MEM_CONSUME_MJPEG_DECODE_EXTMEM (0)
   #define IDP_MEM_CONSUME_MJPEG_DECODE_YUV422V_EXTMEM (0)
   //#define IDP_MEM_CONSUME_MJPEG_DECODE_EXTMEM (MJPEG_DEC_MAX_WIDTH * 24 + 32)
   //#define IDP_MEM_CONSUME_MJPEG_DECODE_YUV422V_EXTMEM (MJPEG_DEC_MAX_WIDTH * 32 + 32)
#endif

#if defined(__MJPEG_ENC_SW_SUPPORT__) 
   #define IDP_MEM_CONSUME_MJPEG_ENCODE_INTMEM (0)
   #define IDP_MEM_CONSUME_MJPEG_ENCODE_EXTMEM (0)
   #define IDP_MEM_CONSUME_MJPEG_ENCODE_YUV420_EXTMEM (0)
   //#define IDP_MEM_CONSUME_MJPEG_ENCODE_EXTMEM (MJPEG_ENC_MAX_WIDTH * 16 + 32)
   //#define IDP_MEM_CONSUME_MJPEG_ENCODE_YUV420_EXTMEM (MJPEG_ENC_MAX_WIDTH * 24 + 32)

#endif

#if defined(__PANORAMA_VIEW_SUPPORT__) || defined(__AUTOCAP_PANORAMA_SUPPORT__)
   #define IDP_MEM_CONSUME_PANORAMA_DECODE_INTMEM (0)
   #define IDP_MEM_CONSUME_PANORAMA_DECODE_EXTMEM (0)
   #define IDP_MEM_CONSUME_PANORAMA_DECODE_YUV422V_EXTMEM (0)

   #define IDP_MEM_CONSUME_PANORAMA_ENCODE_INTMEM (0)
   #define IDP_MEM_CONSUME_PANORAMA_ENCODE_EXTMEM (0)
   #define IDP_MEM_CONSUME_PANORAMA_ENCODE_YUV420_EXTMEM (0)
#endif


#define IDP_MEM_CONSUME_CAMERA_CAPTURE_TO_BARCODE_INTMEM                \
  (((IDP_CAMERA_CAPTURE_TO_BARCODE_MAX_DISPLAYED_WIDTH * 2 * IDP_RESZ_PRZ_FIFO_LENGTH + 4)) +   /*  prz fine */ \
   ((IDP_CAMERA_CAPTURE_TO_BARCODE_MAX_DISPLAYED_WIDTH * 4 * IDP_IMGDMA_IRT1_FIFO_LENGTH + 4))) /* irt1 */

#define IDP_MEM_CONSUME_CAMERA_CAPTURE_TO_BARCODE_EXTMEM (0)

#define IDP_MEM_CONSUME_CAMERA_CAPTURE_TO_JPEG_INTMEM                   \
  (((IDP_CAMERA_CAPTURE_TO_JPEG_MAX_DISPLAYED_WIDTH * 2 * IDP_RESZ_PRZ_FIFO_LENGTH_CAPTURE_TO_JPEG + 4)) +   /*  prz fine */ \
   ((((IDP_CAMERA_CAPTURE_TO_JPEG_MAX_CAPTURED_WIDTH / 16) + 1) * 16) * IDP_IMGDMA_JPEG_FIFO_LENGTH * 2 + 4) +   /* jpeg DMA */ \
   ((IDP_CAMERA_CAPTURE_TO_JPEG_MAX_DISPLAYED_WIDTH * 2 * IDP_IMGDMA_IRT2_FIFO_LENGTH + 4))) /*   irt2, RGB565 */

#define IDP_MEM_CONSUME_CAMERA_CAPTURE_TO_JPEG_EXTMEM (0)

#define IDP_MEM_CONSUME_CAMERA_CAPTURE_TO_MEM_INTMEM                    \
  (((IDP_CAMERA_CAPTURE_TO_MEM_MAX_DST_WIDTH * 2 * IDP_RESZ_PRZ_FIFO_LENGTH + 4)) +   /*  prz fine */ \
   ((IDP_CAMERA_CAPTURE_TO_MEM_MAX_DST_WIDTH * 4 * IDP_IMGDMA_IRT1_FIFO_LENGTH + 4))) /* irt1 */

#define IDP_MEM_CONSUME_CAMERA_CAPTURE_TO_MEM_EXTMEM (0)

#define IDP_MEM_CONSUME_CAMERA_PREVIEW_INTMEM                           \
  ((IDP_CAMERA_PREVIEW_MAX_DISPLAYED_WIDTH * 4 * IDP_IMGDMA_IRT1_FIFO_LENGTH + 4)) /* irt1 */

#define IDP_MEM_CONSUME_CAMERA_PREVIEW_EXTMEM (0)

#define IDP_MEM_CONSUME_IMAGE_EFFECT_PIXEL_INTMEM                       \
  ((IDP_IMAGE_EFFECT_PIXEL_MAX_SRC_WIDTH * 4 * IDP_IMGDMA_IRT1_FIFO_LENGTH + 4)) /* irt1 */

#define IDP_MEM_CONSUME_IMAGE_EFFECT_PIXEL_EXTMEM (0)

#define IDP_MEM_CONSUME_IMAGE_RESIZE_INTMEM                             \
  ((IDP_IMAGE_RESIZE_MAX_DST_WIDTH * 4 * IDP_IMGDMA_IRT1_FIFO_LENGTH + 4)) /* irt1 */

#define IDP_MEM_CONSUME_IMAGE_RESIZE_EXTMEM (0)

#define IDP_MEM_CONSUME_JPEG_DECODE_RRZ_COARSE_MAX_ALLOWABLE_INTMEM (60 * 1024)
#define IDP_MEM_CONSUME_JPEG_DECODE_RRZ_COARSE_MAX_ALLOWABLE_EXTMEM (0)

#define IDP_MEM_CONSUME_JPEG_DECODE_INTMEM                              \
  (                                                                     \
    ((IDP_JPEG_DECODE_MAX_DST_WIDTH * 4 * IDP_IMGDMA_IRT1_FIFO_LENGTH + 4)) + /* irt1 */ \
    (IDP_MEM_CONSUME_JPEG_DECODE_RRZ_COARSE_MAX_ALLOWABLE_INTMEM) /*  prz coarse */ \
                                                                        )

#define IDP_MEM_CONSUME_JPEG_DECODE_EXTMEM (0)
#define IDP_MEM_CONSUME_JPEG_DECODE_YUV422V_EXTMEM (0)

//MM Internal Memory interface change Modify By Michael 2010/11/18
#define IDP_MEM_CONSUME_JPEG_ENCODE_INTMEM (0)
//#define IDP_MEM_CONSUME_JPEG_ENCODE_INTMEM                              \
//  ((IDP_JPEG_ENCODE_MAX_DST_WIDTH * 2 * IDP_RESZ_PRZ_FIFO_LENGTH) +   /*  prz fine */ \
//   ((((IDP_JPEG_ENCODE_MAX_DST_WIDTH / 16) + 1) * 16) * IDP_IMGDMA_JPEG_FIFO_LENGTH_FOR_JPEG_ENCODE * 3))   /* jpeg DMA */

#define IDP_MEM_CONSUME_JPEG_ENCODE_EXTMEM (0)
#define IDP_MEM_CONSUME_JPEG_ENCODE_YUV420_EXTMEM (0)


#define IDP_MEM_CONSUME_JPEG_RESIZE_RRZ_COARSE_MAX_ALLOWABLE_INTMEM (50 * 1024)
#define IDP_MEM_CONSUME_JPEG_RESIZE_RRZ_COARSE_MAX_ALLOWABLE_EXTMEM (50 * 1024)

#define IDP_MEM_CONSUME_JPEG_RESIZE_INTMEM                              \
  (                                                                     \
    ((((IDP_JPEG_RESIZE_MAX_DST_WIDTH / 16) + 1) * 16) * IDP_IMGDMA_JPEG_FIFO_LENGTH * 3 + 4)   /* jpeg DMA */ \
    (IDP_MEM_CONSUME_JPEG_RESIZE_RRZ_COARSE_MAX_ALLOWABLE_INTMEM) /*  prz coarse */ \
                                                                        )

#define IDP_MEM_CONSUME_JPEG_RESIZE_EXTMEM (0)

#define IDP_MEM_CONSUME_RGB2YUV_INTMEM                 (IDP_RGB2YUV_DISPLAY_WIDTH * IDP_IMGDMA_VIDEO_ENCODE_FIFO_LENGTH * 2 + 4) /* video encode DMA */
#define IDP_MEM_CONSUME_RGB2YUV_EXTMEM                 (0)

#define IDP_MEM_CONSUME_VIDEO_CALL_INTMEM              (0)
#define IDP_MEM_CONSUME_VIDEO_CALL_EXTMEM              (0)

#if 1
// VP7
#define IDP_MEM_CONSUME_VIDEO_DECODE_MP4_INTMEM                         \
  (((IDP_VIDEO_DECODE_MAX_SRC_WIDTH_HEIGHT * 8 * 3) / 2 + 4) +   /* mp4deblk*/ \
   ((IDP_VIDEO_DECODE_MAX_SRC_WIDTH_HEIGHT * IDP_IMGDMA_IRT0_FIFO_LENGTH_FOR_VIDEO_DECODE_VP7 * 3) / 2 + 4) +   /* irt0 */ \
   ((IDP_VP7_MIDDLE_BUFFER_HEIGHT * 2 * IDP_IMGDMA_IRT2_FIFO_LENGTH_FOR_VIDEO_DECODE_VP7) + 4) +   /* irt2 */ \
   ((IDP_VIDEO_DECODE_MAX_DISPLAYED_WIDTH * 2 * IDP_RESZ_PRZ_FIFO_LENGTH_VP7 + 4)))  /*  prz fine */
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#define IDP_MEM_CONSUME_VIDEO_DECODE_MP4_EXTMEM (0)

#if 1
// VP7
#define IDP_MEM_CONSUME_VIDEO_DECODE_H264_INTMEM                        \
  (((IDP_VIDEO_DECODE_MAX_SRC_WIDTH_HEIGHT * IDP_IMGDMA_IRT0_FIFO_LENGTH_FOR_VIDEO_DECODE_VP7 * 3) / 2 + 4) +   /* irt0 */ \
   ((IDP_VP7_MIDDLE_BUFFER_HEIGHT * 2 * IDP_IMGDMA_IRT2_FIFO_LENGTH_FOR_VIDEO_DECODE_VP7) + 4) +   /* irt2 */ \
   ((IDP_VIDEO_DECODE_MAX_DISPLAYED_WIDTH * 2 * IDP_RESZ_PRZ_FIFO_LENGTH_VP7 + 4)))  /*  prz fine */
#else
/* under construction !*/
/* under construction !*/
#endif

#define IDP_MEM_CONSUME_VIDEO_DECODE_H264_EXTMEM (0)

#define IDP_MEM_CONSUME_VIDEO_EDITOR_ENCODE_INTMEM                      \
  ((IDP_VIDEO_EDITOR_ENCODE_MAX_SRC_WIDTH * 2 * IDP_RESZ_PRZ_FIFO_LENGTH + 4) +  /*  prz fine */ \
   (IDP_VIDEO_EDITOR_ENCODE_MAX_ENCODED_WIDTH * IDP_IMGDMA_VIDEO_ENCODE_FIFO_LENGTH * 2 + 4)) /* video encode DMA */

#define IDP_MEM_CONSUME_VIDEO_EDITOR_ENCODE_EXTMEM (0)

#define IDP_MEM_CONSUME_VIDEO_EDITOR_DECODE_INTMEM                      \
  (((IDP_VIDEO_EDITOR_DECODE_MAX_DST_WIDTH * 2 * IDP_RESZ_PRZ_FIFO_LENGTH + 4)) +  /*  prz fine */ \
   ((IDP_VIDEO_EDITOR_DECODE_MAX_SRC_WIDTH_HEIGHT * IDP_IMGDMA_IRT0_FIFO_LENGTH * 3) / 2 + 4) + /* irt0 */ \
   ((IDP_VIDEO_EDITOR_DECODE_MAX_DST_WIDTH * 4 * IDP_IMGDMA_IRT1_FIFO_LENGTH + 4)))

#define IDP_MEM_CONSUME_VIDEO_EDITOR_DECODE_EXTMEM (0)

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
#endif /* #if 0 */

#if defined(MT6238_S00) || defined(MT6239_S00) || defined(MT6268T) || defined(MT6268) || defined(MT6268A) || defined(MT6268B)
// For E3 only
#define IDP_MEM_CONSUME_VIDEO_ENCODE_INTMEM                             \
  (((IDP_VIDEO_ENCODE_MAX_DISPLAYED_HEIGHT * 2 * IDP_IMGDMA_IRT2_FIFO_LENGTH) + 4) +   /*    irt2, only RGB565 */ \
   ((IDP_VIDEO_ENCODE_MAX_DISPLAYED_WIDTH * 2 * IDP_RESZ_PRZ_FIFO_LENGTH_FOR_VIDEO_ENCODE_VR5 + 4)) +  /*  prz fine */ \
   (IDP_VIDEO_ENCODE_MAX_ENCODED_WIDTH * IDP_IMGDMA_VIDEO_ENCODE_FIFO_LENGTH_FOR_VIDEO_ENCODE_VR5 * 2 + 4)) /* video encode DMA */
#else
// For E2 only, prz working mem trick
#define IDP_MEM_CONSUME_VIDEO_ENCODE_INTMEM                             \
  (((IDP_VIDEO_ENCODE_MAX_DISPLAYED_HEIGHT * 2 * IDP_IMGDMA_IRT2_FIFO_LENGTH) + 4) +   /* irt2 */ \
   (IDP_VIDEO_ENCODE_MAX_ENCODED_WIDTH * IDP_IMGDMA_VIDEO_ENCODE_FIFO_LENGTH_FOR_VIDEO_ENCODE_VR5 * 2 + 4)) /* video encode DMA */
#endif

#define IDP_MEM_CONSUME_VIDEO_ENCODE_EXTMEM                             \
  (IDP_VIDEO_ENCODE_MAX_ENCODED_WIDTH * IDP_VIDEO_ENCODE_MAX_ENCODED_HEIGHT * 3 + 4)

#define IDP_MEM_CONSUME_WEBCAM_INTMEM                                   \
  ((((IDP_WEBCAM_MAX_CAPTURED_WIDTH / 16) + 1) * 16) * IDP_IMGDMA_JPEG_FIFO_LENGTH * 3 + 4) /* jpeg DMA */

#define IDP_MEM_CONSUME_WEBCAM_EXTMEM (0)

/* ========================= video call encode ============================ */

/**
 *  \def IDP_MEM_CONSUME_VIDEO_CALL_ENCODE_INTMEM
 *  For MT6238 series video call if max video encode resolution is QCIF and max preview size is QCIF also
 *  We need 176*2*8 + 4 + 176*2*16 + 4 = 8456 bytes
 *  Below macro gives us 720*8*2+4 = 11524 bytes
 */
#define IDP_MEM_CONSUME_VIDEO_CALL_ENCODE_INTMEM                             \
  (IDP_VIDEO_CALL_ENCODE_MAX_ENCODED_WIDTH * IDP_IMGDMA_VIDEO_ENCODE_FIFO_LENGTH_FOR_VIDEO_CALL_ENCODE * 2 + 4) /* video encode DMA */

/**
 *  \def IDP_MEM_CONSUME_VIDEO_CALL_ENCODE_EXTMEM
 *  For MT6238 series video call encode path, 
 *  We need four QCIF YUV420 frame buffer from external memory
 *  176*144*3/2 * 4 = 152064 bytes
 *  Below macro gives us 720*480*3+4 = 1036804 bytes
 */

#define IDP_MEM_CONSUME_VIDEO_CALL_ENCODE_EXTMEM             (((176 * 144 * 3)>>1) + 32 ) * 2

//#define IDP_MEM_CONSUME_VIDEO_CALL_ENCODE_EXTMEM                             \
//  (IDP_VIDEO_CALL_ENCODE_MAX_ENCODED_WIDTH * IDP_VIDEO_CALL_ENCODE_MAX_ENCODED_HEIGHT * 3 + 4)

/* ========================= video call decode ============================ */

#define IDP_MEM_CONSUME_VIDEO_CALL_DECODE_INTMEM                        \
  (((IDP_VIDEO_CALL_DECODE_MAX_SRC_WIDTH_HEIGHT * 8 * 3) / 2 + 4) +   /* mp4deblk*/ \
   ((IDP_VIDEO_CALL_DECODE_MAX_SRC_WIDTH_HEIGHT * IDP_IMGDMA_IRT0_FIFO_LENGTH_FOR_VIDEO_CALL_DECODE * 3) / 2 + 4) +   /* irt0 */ \
   ((IDP_VIDEO_CALL_DECODE_MAX_DISPLAYED_WIDTH * 2 * IDP_RESZ_PRZ_FIFO_LENGTH_FOR_VIDEO_CALL_DECODE + 4)))  /*  prz fine */

#define IDP_MEM_CONSUME_VIDEO_CALL_DECODE_EXTMEM                             (0)

#endif
