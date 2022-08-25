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
 *    va2_video_renderer_mem_req.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    The required memory size of Video Renderer
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
 * removed!
 ****************************************************************************/
#ifndef __VA2_VIDEO_RENDERER_MEM_REQ_H__
#define __VA2_VIDEO_RENDERER_MEM_REQ_H__
#include "lcd_sw_inc.h"
#include "video_codec_mem_v2.h"
#include "drv_sw_features_video.h"
#include "mpl_player.h"

#if defined(__VIDEO_ARCHI_V2__)
#if defined(MT6235) || defined(MT6235B)
/**
 *  \def VA2_VR_VP_DISPLAY_FB_NONE
 *  Video Renderer will not allocate memory for display frame buffer.
 */
#undef VA2_VR_VP_DISPLAY_FB_NONE

/**
 *  \def VA2_VR_VP_DISPLAY_FB_SINGLE
 *  Video Renderer will allocate memory for single display frame buffer.
 */
#undef VA2_VR_VP_DISPLAY_FB_SINGLE

/**
 *  \def VA2_VR_VP_DISPLAY_FB_DOUBLE
 *  Video Renderer will allocate memory for double display frame buffer.
 */
#define VA2_VR_VP_DISPLAY_FB_DOUBLE

#endif	// #if defined(MT6235) || defined(MT6235B)
// TODO: Need a better solution than chip options
/**
 *  MT6253 series Renderer uses single display frame 
 *  buffer carried down by IL client.
 */
#if defined(MT6253T) || defined(MT6253) || defined(MT6253E)  || defined(MT6253L) || defined(MT6252H) || defined(MT6252) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
/**
 *  \def VA2_VR_VP_DISPLAY_FB_NONE
 *  Video Renderer will not allocate memory for display frame buffer.
 */
#define VA2_VR_VP_DISPLAY_FB_NONE

/**
 *  \def VA2_VR_VP_DISPLAY_FB_SINGLE
 *  Video Renderer will allocate memory for single display frame buffer.
 */
#undef VA2_VR_VP_DISPLAY_FB_SINGLE

/**
 *  \def VA2_VR_VP_DISPLAY_FB_DOUBLE
 *  Video Renderer will allocate memory for double display frame buffer.
 */
#undef VA2_VR_VP_DISPLAY_FB_DOUBLE
#endif	// #if defined(MT6253T) || defined(MT6253) || defined(MT6253E)  || defined(MT6253L) || defined(MT6252H) || defined(MT6252)

#if defined(CONTOUR_IMPROVEMENT_MT6253)
#if !defined(CONTOUR_IMPROVEMENT_MT6253_SLIM)
#undef VA2_VR_VP_DISPLAY_FB_NONE
#define VA2_VR_VP_DISPLAY_FB_SINGLE
#undef VA2_VR_VP_DISPLAY_FB_DOUBLE
#endif
#endif //#if defined(CONTOUR_IMPROVEMENT_MT6253)

/**
 *  MT6236 series Renderer use double buffering, 
 *  one display frame buffer is carried down by IL client, 
 *  and the other is allocated by Renderer.
 */
#if defined(MT6236) || defined(MT6236B) || defined(MT6276) || defined(MT6256) || defined(MT6255)
#undef VA2_VR_VP_DISPLAY_FB_NONE
#define VA2_VR_VP_DISPLAY_FB_SINGLE
#undef VA2_VR_VP_DISPLAY_FB_DOUBLE
#endif	// #if (defined(MT6236) || defined(MT6236B) || defined(MT6276) || defined(MT6256)) || defined(MT6255)

/**
 *  MT6268 series Renderer needs display double buffers of HVGA size. (for TV OUT)
 *  If set to trigger display, Renderer does not use the display frame buffer set by IL client. 
 *  If not to trigger display, Renderer uses the display frame buffer set by IL client.
 */
#if defined(MT6268T) || defined(MT6268) || defined(MT6268A) || defined(MT6268B) || defined(MT6268H)
#undef VA2_VR_VP_DISPLAY_FB_NONE
#undef VA2_VR_VP_DISPLAY_FB_SINGLE
#define VA2_VR_VP_DISPLAY_FB_DOUBLE
#endif  //  defined(MT6268T) || defined(MT6268) || defined(MT6268A) || defined(MT6268B) || defined(MT6268H)

//#define VA2_VR_VP_6268_DISPLAY_BUFFER_SIZE      (320*480*16/8)

//#if defined(MT6268T) || defined(MT6268) || defined(MT6268A) || defined(MT6268B) || defined(MT6268H)
//#define VA2_VR_VP_DISPLAY_BUFFER_SIZE           VA2_VR_VP_6268_DISPLAY_BUFFER_SIZE
//#define VA2_VR_VP_6236_DISPLAY_BUFFER_SIZE      (LCD_WIDTH * LCD_HEIGHT * MULTIMEDIA_DISPLAY_COLOR_FMT_BPP / 8)
//#else  // if not otherwise specified
//#define VA2_VR_VP_6236_DISPLAY_BUFFER_SIZE      (LCD_WIDTH * LCD_HEIGHT * MULTIMEDIA_DISPLAY_COLOR_FMT_BPP / 8)
//#define VA2_VR_VP_DISPLAY_BUFFER_SIZE           (LCD_WIDTH * LCD_HEIGHT * MULTIMEDIA_DISPLAY_COLOR_FMT_BPP / 8)
//#endif

#if defined(MT6235) || defined(MT6235B) 
//For Cache and Non-Cache Transfer
#define VA2_VR_VP_DISPLAY_BUFFER_SIZE           ((((LCD_WIDTH * LCD_HEIGHT * MULTIMEDIA_DISPLAY_COLOR_FMT_BPP / 8)+31)>>5)<<5)+32
#else
#define VA2_VR_VP_DISPLAY_BUFFER_SIZE           (LCD_WIDTH * LCD_HEIGHT * MULTIMEDIA_DISPLAY_COLOR_FMT_BPP / 8)
#endif //#if defined(MT6235) || defined(MT6235B) 

// define subtitle layer size according to VIDEO_SUBTITLE_RECT_MAX_WIDTH/HEIGHT(from subtitle decoder) with 32 bpp
#define VA2_VR_VP_SUBTITLE_BUFFER_SIZE          (VIDEO_SUBTITLE_RECT_MAX_WIDTH * VIDEO_SUBTITLE_RECT_MAX_HEIGHT * 4)

#define VA2_VR_VP_MAX_BH_COUNT                  (2)
#define VA2_UTIL_BUF_HDR_Q_ITEM_T_STRUCT_SZ     (40)
#define VA2_VR_UTIL_BUF_HDR_QUEUE_POOL_SZ       (VA2_UTIL_BUF_HDR_Q_ITEM_T_STRUCT_SZ * VA2_VR_VP_MAX_BH_COUNT)

#if defined(VA2_RENDERER_VP_STEREO_VIDEO_SUPPORTED)
#define VA2_VR_VP_BLACK_FRM_WIDTH               (32)
#define VA2_VR_VP_BLACK_FRM_HEIGHT              (16)
#else  //VA2_RENDERER_VP_STEREO_VIDEO_SUPPORTED
#define VA2_VR_VP_BLACK_FRM_WIDTH               (16)
#define VA2_VR_VP_BLACK_FRM_HEIGHT              (16)
#endif //VA2_RENDERER_VP_STEREO_VIDEO_SUPPORTED

#define VA2_VR_VP_BLACK_FRM_Y_PLANE_SZ          (VA2_VR_VP_BLACK_FRM_WIDTH*VA2_VR_VP_BLACK_FRM_HEIGHT)             //(pix_w * pix_h * YUV420)
#define VA2_VR_VP_BLACK_FRM_UV_PLANE_SZ         ((VA2_VR_VP_BLACK_FRM_WIDTH/2)*(VA2_VR_VP_BLACK_FRM_HEIGHT/2)*2)   //(pix_w * pix_h * YUV420)
#define VA2_VR_VP_BLACK_FRMSZ                   (VA2_VR_VP_BLACK_FRM_Y_PLANE_SZ + VA2_VR_VP_BLACK_FRM_UV_PLANE_SZ)

#if defined(MT6235) || defined(MT6235B) 
//Special  Video Resolution
/*
Touch From Inside Used
Type B is Top and Bottom is black.     
Type A is Left and Right is black.
    Soure WxH   Dest WxH  Inside Type  Output WxH         Offset  Pitch   New Source WxH

1. 176x144       240x400    Type B         240x196
2. 176x144       400x240    Type A         293x240           28      234       234x144
3. 320x240       240x400    Type B         240x180 
4. 320x240       400x240    Type A         320x240           40      400       400x240
5. 352x288       240x400    Type B         240x195     
6. 352x288       400x240    Type A         292x288           65      482       482x288
7. 240x160       240x400    Type B         240x160     
8. 240x160       400x240    Type A         360x240           13      360       266x160
9. 320x180       240x400    Type B         240x135     
10.320x180       400x240    Type B         400x225   
11.480x320       240x400    Type B         240x160   
12.480x320       400x240    Type A         360x240           26      536      536x320  
13.640x480       240x400    Type B         240x180   
14.640x480       400x240    Type A         320x240           80      800      800x480  
15.640x360       240x400    Type B         240x135
16.640x360       400x240    Type B         400x225
17.88x77         240x400    Type B         240x135
18.88x77         400x240    Type A         400x225           20      128      128x77  
19.160x120       240x400    Type B         240x135
20.160x120       400x240    Type A         400x225           80      320      320x120  
21.80x60         240x400    Type B         240x135
22.80x60         400x240    Type A         400x225           10      320      100x60  
Maximum Width (800=>)800, and Height is 320.
*/
#define VA2_VR_VP_SOURCE_DO_PITCH_MEM_REQ_SIZE  ((((800 * 480 * 2) + 31)>>5)<<5) + 32         
#define VA2_VR_VP_SW_RESIZER_BUFFER_SIZE        (((((((MAX_FRM_BUFFER_WIDTH * MAX_FRM_BUFFER_HEIGHT * 2) + 31)>>5)<<5) + 32) >= VA2_VR_VP_SOURCE_DO_PITCH_MEM_REQ_SIZE) ? (((((MAX_FRM_BUFFER_WIDTH * MAX_FRM_BUFFER_HEIGHT * 2) + 31)>>5)<<5) + 32) : (VA2_VR_VP_SOURCE_DO_PITCH_MEM_REQ_SIZE))
#else
#define VA2_VR_VP_SW_RESIZER_BUFFER_SIZE        0
#endif //#if defined(MT6235) || defined(MT6235B) 

#if defined(MT6235) || defined(MT6235B)
#define VA2_VR_VP_SW_PITCH_WORKING_MEM_SIZE     ((LCD_WIDTH >= LCD_HEIGHT) ? (((((LCD_WIDTH * MULTIMEDIA_DISPLAY_COLOR_FMT_BPP / 8)+32)>>5)<<5)+32):(((((LCD_HEIGHT * MULTIMEDIA_DISPLAY_COLOR_FMT_BPP / 8)+32)>>5)<<5)+32))
#else
#define VA2_VR_VP_SW_PITCH_WORKING_MEM_SIZE     0
#endif


#if defined(CONTOUR_IMPROVEMENT_MT6253) || defined(CONTOUR_IMPROVEMENT_MT6235)
#if defined(CONTOUR_IMPROVEMENT_MT6253_SLIM)
#define VA2_VR_SW_DITHER_WORKING_MEM_SZ    ((LCD_WIDTH >= LCD_HEIGHT) ? (((3*(((LCD_WIDTH+15)>>4)<<4)*LCD_HEIGHT) >> 1)+(32*4)+32):(((3*(((LCD_HEIGHT+15)>>4)<<4)*LCD_WIDTH) >> 1)+(32*4)+32))
#else
#define VA2_VR_SW_DITHER_WORKING_MEM_SZ    ((LCD_WIDTH >= LCD_HEIGHT) ? ((3*(((LCD_WIDTH+15)>>4)<<4)*LCD_HEIGHT)+(32*7)+32):((3*(((LCD_HEIGHT+15)>>4)<<4)*LCD_WIDTH)+(32*7)+32))
#endif 
#else
#define VA2_VR_SW_DITHER_WORKING_MEM_SZ        0
#endif //#if defined(CONTOUR_IMPROVEMENT_MT6253) || defined(CONTOUR_IMPROVEMENT_MT6235)

#if defined(VA2_RENDERER_VP_STEREO_VIDEO_SUPPORTED)
#define VA2_VR_VP_STEREO_VIDEO_SZ ((((LCD_WIDTH * LCD_HEIGHT * 2)+31)>>5)<<5) //RGB565, must be 32 byte align for cache switchable
                                                                              //the start address will be 32 byte align garuanteed by 
                                                                              //video module
#else
#define VA2_VR_VP_STEREO_VIDEO_SZ (0)
#endif//#if defined(VA2_RENDERER_VP_STEREO_VIDEO_SUPPORTED)

/**
 *  \def VA2_VIDEO_RENDERER_EXT_MEM_COMM_REQ
 *  The required size (in bytes) of external memory of video renderer.
 *  1. Buffer header queue item pool: e.g. 48bytes*2
 *  2. Black frame: 16(32 for side by side 3D)*16*2
 *  3. SW resizer buffer(MT6235 only)
 *  4. SW pitch working memory(MT6235 only)
 *  5. SW dither working memory(MT6253 only)
 *  6. Stereo video working buffer(for feature side by side 3D)
 */
#define VA2_VIDEO_RENDERER_EXT_MEM_COMM_REQ  \
  (VA2_VR_UTIL_BUF_HDR_QUEUE_POOL_SZ + 32)  + \
  (VA2_VR_VP_BLACK_FRMSZ + 32) + \
  (VA2_VR_VP_SW_RESIZER_BUFFER_SIZE) + \
  (VA2_VR_VP_SW_PITCH_WORKING_MEM_SIZE) + \
  (VA2_VR_SW_DITHER_WORKING_MEM_SZ) + \
  (VA2_VR_VP_STEREO_VIDEO_SZ)


// TODO: This file needs to be modified to depends on LCD size, supported scenarios, chip, and struct size...

#define VA2_VIDEO_RENDERER_EXT_MEM_THUMB_REQ  \
  (VA2_VIDEO_RENDERER_EXT_MEM_COMM_REQ)

#if defined(__VIDEO_SUBTITLE_SUPPORT__)
// This define acquires 1 video display buffer, 1 subtitle display buffer and 1 extra queue handle
#define VA2_VIDEO_RENDERER_EXT_MEM_SUBTITLE_REQ  \
  (VA2_VIDEO_RENDERER_EXT_MEM_COMM_REQ) + \
  (VA2_VR_UTIL_BUF_HDR_QUEUE_POOL_SZ + 32) + \
  (VA2_VR_VP_DISPLAY_BUFFER_SIZE + 32) + \
  (VA2_VR_VP_SUBTITLE_BUFFER_SIZE + 32)
#else
// if video subtitle does not support, define this size to 0
#define VA2_VIDEO_RENDERER_EXT_MEM_SUBTITLE_REQ  (0)
#endif

/**
 *  \def VA2_VIDEO_RENDERER_EXT_MEM_REQ
 *  The required size (in bytes) of external memory of video renderer.
 *  1. One dispay frame buffer LCD_WIDTH*LCD_HEIGHT*BPP: e.g. 320*480*2
 *  2. Buffer header queue item pool: e.g. 48bytes*2
 */
#if defined(VA2_VR_VP_DISPLAY_FB_NONE)
#define VA2_VIDEO_RENDERER_EXT_MEM_REQ  \
  (VA2_VIDEO_RENDERER_EXT_MEM_COMM_REQ)


#elif defined(VA2_VR_VP_DISPLAY_FB_SINGLE)
#define VA2_VIDEO_RENDERER_EXT_MEM_REQ  \
  (VA2_VIDEO_RENDERER_EXT_MEM_COMM_REQ) + \
  (VA2_VR_VP_DISPLAY_BUFFER_SIZE + 32)


#elif defined(VA2_VR_VP_DISPLAY_FB_DOUBLE)
#define VA2_VIDEO_RENDERER_EXT_MEM_REQ  \
  (VA2_VIDEO_RENDERER_EXT_MEM_COMM_REQ) + \
  (VA2_VR_VP_DISPLAY_BUFFER_SIZE + 32)*2

#else   // number of display frame buffer
#error "please check above macro definitions."
#endif  // number of display frame buffer

/**
 *  \def VA2_VIDEO_RENDERER_INT_MEM_REQ
 *  The required size (in bytes) of internal memory of video renderer.
 *  1. None for now...
 */
#define VA2_VIDEO_RENDERER_INT_MEM_REQ  (0)

#else   // #if defined(__VIDEO_ARCHI_V2__)

#define VA2_VIDEO_RENDERER_EXT_MEM_REQ  (0)
#define VA2_VIDEO_RENDERER_INT_MEM_REQ  (0)

#endif  // #if defined(__VIDEO_ARCHI_V2__)

#endif  // #ifndef __VA2_VIDEO_RENDERER_MEM_REQ_H__

