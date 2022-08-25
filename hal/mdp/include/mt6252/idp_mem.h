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
 *	 MT6252
 *
 * Description:
 * ------------
 *   Various constant for memory size computation
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
 * 12 27 2011 peter.wang
 * removed!
 * .
 *
 * 12 27 2011 peter.wang
 * removed!
 * .
 *
 * 11 15 2011 peter.wang
 * removed!
 * .
 *
 * 09 21 2011 peter.wang
 * removed!
 * .
 *
 * 07 27 2011 peter.wang
 * removed!
 * .
 *
 * 04 22 2011 peter.wang
 * removed!
 * .
 *
 * 01 20 2011 cm.huang
 * removed!
 * .
 *
 * 11 23 2010 cm.huang
 * removed!
 * .
 *
 * 11 15 2010 cm.huang
 * NULL
 * .
 *
 * 11 13 2010 cm.huang
 * NULL
 * .
 *
 * 11 01 2010 cm.huang
 * NULL
 * .
 *
 * removed!
 * removed!
 *
 *
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

#ifndef __idp_mem_mt6252_h__
#define __idp_mem_mt6252_h__

/* ==================================================================
 *                           boundry size
 * ================================================================== */

#define IDP_CAMERA_CAPTURE_TO_BARCODE_MAX_DISPLAYED_WIDTH        (320)

#define IDP_CAMERA_CAPTURE_TO_JPEG_MAX_DISPLAYED_WIDTH        (320)
#define IDP_CAMERA_CAPTURE_TO_JPEG_MAX_CAPTURED_WIDTH        (1600)

#define IDP_CAMERA_CAPTURE_TO_MEM_MAX_DST_WIDTH        (720)

#define IDP_CAMERA_PREVIEW_MAX_DISPLAYED_WIDTH        (400)

#define IDP_IMAGE_EFFECT_PIXEL_MAX_SRC_WIDTH        (720)

#define IDP_IMAGE_RESIZE_MAX_DST_WIDTH        (720)

#define IDP_JPEG_DECODE_MAX_SRC_WIDTH        (720)
#define IDP_JPEG_DECODE_MAX_DST_WIDTH        (720)

#define IDP_JPEG_ENCODE_MAX_DST_WIDTH        (2592)

#define IDP_JPEG_ENCODE_PANORAMA_RGB565_MAX_SRC_WIDTH   (0)
#define IDP_JPEG_ENCODE_PANORAMA_RGB565_MAX_SRC_HEIGHT   (0)

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
#define IDP_VIDEO_ENCODE_MAX_ENCODED_WIDTH          (720)
#define IDP_VIDEO_ENCODE_MAX_ENCODED_HEIGHT         (480)
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
// TODO: Need to update with MT6253 values

#define IDP_IMGDMA_IRT0_FIFO_LENGTH         (8)
#define IDP_IMGDMA_IRT0_FIFO_LENGTH_FOR_VIDEO_DECODE         (8)
#define IDP_IMGDMA_IRT0_FIFO_LENGTH_FOR_VIDEO_DECODE_VP7     (8)
#define IDP_IMGDMA_IRT0_FIFO_LENGTH_FOR_VIDEO_CALL_DECODE    (8)

#define IDP_IMGDMA_IRT1_FIFO_LENGTH         (8)
#define IDP_IMGDMA_IRT1_FIFO_LENGTH_FOR_VIDEO_DECODE         (8)

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
/* ========================= camera preview ============================ */
#define IDP_MEM_CONSUME_CAMERA_PREVIEW_EXTMEM (0)


/* ========================= camera catpure ============================ */
#define IDP_MEM_CONSUME_CAMERA_CAPTURE_TO_JPEG_EXTMEM (0)

#define IDP_MEM_CONSUME_CAMERA_CAPTURE_TO_MEM_EXTMEM (0)

/* ========================= video encode ============================ */
#define IDP_MEM_CONSUME_VIDEO_ENCODE_EXTMEM (0)


/* ========================= video call encode ============================ */
#define IDP_MEM_CONSUME_VIDEO_CALL_ENCODE_EXTMEM  (0)


/* ========================= video call decode ============================ */
#define IDP_MEM_CONSUME_VIDEO_CALL_DECODE_EXTMEM                             (0)



/* ========================= mjpg encode/decode ============================ */
#if defined(__MJPEG_DEC_SW_SUPPORT__) 
   #define IDP_MEM_CONSUME_MJPEG_DECODE_INTMEM (0)
   #define IDP_MEM_CONSUME_MJPEG_DECODE_EXTMEM (0)
   #define IDP_MEM_CONSUME_MJPEG_DECODE_YUV422V_EXTMEM (0)
#endif

#if defined(__MJPEG_ENC_SW_SUPPORT__) 
   #define IDP_MEM_CONSUME_MJPEG_ENCODE_INTMEM (0)
   #define IDP_MEM_CONSUME_MJPEG_ENCODE_EXTMEM (0)
   #define IDP_MEM_CONSUME_MJPEG_ENCODE_YUV420_EXTMEM (0)
#endif

#endif // __idp_mem_mt6252_h__



