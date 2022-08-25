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
 *	 MT6235
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
 * 07 27 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 06 08 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 04 27 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 01 20 2011 cm.huang
 * removed!
 * .
 *
 * 11 29 2010 hung-wen.hsieh
 * removed!
 * .
 *
 * 11 26 2010 cm.huang
 * removed!
 * .
 *
 * 11 23 2010 hung-wen.hsieh
 * removed!
 * .
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_mem_mt6235_h__
#define __idp_mem_mt6235_h__

/* ==================================================================
 *                           boundry size
 * ================================================================== */

#define IDP_JPEG_ENCODE_PANORAMA_RGB565_MAX_SRC_WIDTH   (0) 
#define IDP_JPEG_ENCODE_PANORAMA_RGB565_MAX_SRC_HEIGHT   (0) 

#define IDP_JPEG_ENCODE_PANORAMA_YUV420_MAX_SRC_WIDTH   (0) 
#define IDP_JPEG_ENCODE_PANORAMA_YUV420_MAX_SRC_HEIGHT   (0) 

/* ==================================================================
 *                    working memory line count
 * ================================================================== */


/* ==================================================================
 *                     external memory Equation for each path
 * ================================================================== */
/* ========================= camera preview ============================ */

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


#if defined(__MJPEG_DEC_SW_SUPPORT__) 
   #define IDP_MEM_CONSUME_MJPEG_DECODE_INTMEM (0)
   #define IDP_MEM_CONSUME_MJPEG_DECODE_EXTMEM (0)
   #define IDP_MEM_CONSUME_MJPEG_DECODE_YUV422V_EXTMEM (0)
   //#define IDP_MEM_CONSUME_MJPEG_DECODE_EXTMEM (0)
   //#define IDP_MEM_CONSUME_MJPEG_DECODE_YUV422V_EXTMEM (0)
#endif

#if defined(__MJPEG_ENC_SW_SUPPORT__) 
   #define IDP_MEM_CONSUME_MJPEG_ENCODE_INTMEM (0)
   #define IDP_MEM_CONSUME_MJPEG_ENCODE_EXTMEM (0)
   #define IDP_MEM_CONSUME_MJPEG_ENCODE_YUV420_EXTMEM (0)
   //#define IDP_MEM_CONSUME_MJPEG_ENCODE_EXTMEM (0)
   //#define IDP_MEM_CONSUME_MJPEG_ENCODE_YUV420_EXTMEM (0)

#endif

#if defined(__PANORAMA_VIEW_SUPPORT__) || defined(__AUTOCAP_PANORAMA_SUPPORT__)
   #define IDP_MEM_CONSUME_PANORAMA_DECODE_INTMEM (0)
   #define IDP_MEM_CONSUME_PANORAMA_DECODE_EXTMEM (0)
   #define IDP_MEM_CONSUME_PANORAMA_DECODE_YUV422V_EXTMEM (0)

   #define IDP_MEM_CONSUME_PANORAMA_ENCODE_INTMEM (0)
   #define IDP_MEM_CONSUME_PANORAMA_ENCODE_EXTMEM (0)
   #define IDP_MEM_CONSUME_PANORAMA_ENCODE_YUV420_EXTMEM (0)
#endif

//external memory sw dithering
#if defined(CONTOUR_IMPROVEMENT_MT6235)
#define IDP_MEM_CONSUME_CAMERA_PREVIEW_EXTMEM ((LCD_WIDTH >= LCD_HEIGHT) ? ((3*(((LCD_WIDTH+15)>>4)<<4)*LCD_HEIGHT)+(32*7)):((3*(((LCD_HEIGHT+15)>>4)<<4)*LCD_WIDTH)+(32*7)))
#else
#define IDP_MEM_CONSUME_CAMERA_PREVIEW_EXTMEM (0)   
#endif
#define IDP_MEM_CONSUME_JPEG_DECODE_YUV422V_EXTMEM (0)


/* ========================= camera catpure ============================ */
#define IDP_MEM_CONSUME_CAMERA_CAPTURE_TO_JPEG_EXTMEM (0)

#define IDP_MEM_CONSUME_CAMERA_CAPTURE_TO_MEM_EXTMEM (0)

/* ========================= video encode ============================ */
//external memory sw dithering
#if defined(CONTOUR_IMPROVEMENT_MT6235)
#define IDP_MEM_CONSUME_VIDEO_ENCODE_EXTMEM ((LCD_WIDTH >= LCD_HEIGHT) ? ((3*(((LCD_WIDTH+15)>>4)<<4)*LCD_HEIGHT)+(32*7)):((3*(((LCD_HEIGHT+15)>>4)<<4)*LCD_WIDTH)+(32*7)))                        
#else
#define IDP_MEM_CONSUME_VIDEO_ENCODE_EXTMEM (0)   
#endif


/* ========================= video call encode ============================ */
#define IDP_MEM_CONSUME_VIDEO_CALL_ENCODE_EXTMEM  (0)                          


/* ========================= video call decode ============================ */
#define IDP_MEM_CONSUME_VIDEO_CALL_DECODE_EXTMEM                             (0)
 
#endif // __idp_mem_mt6235_h__
