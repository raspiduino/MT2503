/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *    png_info.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   PNG decoder data type header
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __PNG_INFO_H__
#define __PNG_INFO_H__

/// #include "drv_comm.h"
#include "png_decode_enum.h"
#include "png_decode_structure.h"
#include "kal_general_types.h"
#include "drv_features_png.h"

#ifdef USE_HW_PNG_DECODER

#ifdef   WIN32_STANDALONE
#include "kal_non_specific_general_types.h"
#endif //   WIN32_STANDALONE

#ifndef PNG_H  // png.h is not included
   #define PNG_COLOR_TYPE_GRAY      0        // Greyscale
   #define PNG_COLOR_TYPE_RGB       2        // Truecolour
   #define PNG_COLOR_TYPE_PALETTE   3        // Indexed-colour
   #define PNG_COLOR_TYPE_GA        4        // Greyscale with alpha
   #define PNG_COLOR_TYPE_RGBA      6        // Truecolour with alpha
   
#else  
   #include "png.h"
#endif  // PNG_H

/**
 * @brief define the color format
 */
/// typedef enum
/// { 
///    PNG_RGB565 = 1, 
///    PNG_RGB888,
///    PNG_ARGB8888
/// } PNG_COLOR_FORMAT_ENUM;  
/// 
/// 
/// /**
///  * @brief define the bleding mode
///  */
/// typedef enum
/// { 
///    PNG_BLEND_NONE = 0,             
///    PNG_BLEND_FILEALPHA,           ///<  PNG built-in alpha \n
///                                   ///<  dstColor = pngAlpha x pngColor + (1 - pngAlpha) x bldColor \n
///                                   ///<  pngAlpha may comes from several sources:\n                                                      
///                                   ///<         i.   the alpha component of the pixel if the color type is ARGB \n                                   
///                                   ///<         ii.  the alpha component of the pixel if the color type is grayscale with alpha \n                   
///                                   ///<         iii. the single alpha defined in the transparent chunk if the color type is not palette type \n      
///                                   ///<         iv.  the per-palette-entry alpha defined in the transparent chunk if the color type is palette type\n
///    PNG_BLEND_BUFFER,              ///<  blending buffer (always be per-pixel) \n
///                                   ///<  dstColor = dstAlpha x pngColor + (1 - dstAlpha) x bldColor \n
///                                   ///<  This mode works only when the destination buffer is ARGB mode.\n\n
///    PNG_BLEND_USER_ASSIGNED,        ///<  user-specified single alpha value (always be per-alpha) \n
///                                   ///<  dstColor = userAlpha x pngColor + (1 - userAlpha) x bldColor \n\n
///    PNG_BLEND_BG_COLOR              ///< png file alpha blends with a single background color
/// } PNG_BLEND_MODE_ENUM;


/**
 * @brief this struct is to maintain image metadata extracted from png header
 */
typedef struct MY_PNG_INFO_T
{
   kal_uint32 width;             ///< width of image in pixels (from IHDR) 
   kal_uint32 height;            ///<  height of image in pixels (from IHDR) 
   kal_uint32 valid;             ///< valid chunk data (see chunk.h)  
   kal_uint32 num_palette;       ///< number of color entries in "palette" (PLTE) 
   kal_uint32 num_trans;         ///< number of transparent palette color (tRNS) 
   kal_uint8 bit_depth;          ///< 1, 2, 4, 8, or 16 bits/channel (from IHDR) 
   kal_uint8 color_type;         ///< png color type (from IHDR) 
   kal_uint8 compression_method; ///<must be 0 (IHDR) 
   kal_uint8 filter_method;      ///< must be 0 (from IHDR) 
   kal_uint8 interlace_method;   ///< 1: PNG_INTERLACE_NONE, 7: PNG_INTERLACE_ADAM7 
   kal_uint8 sig[8];             ///<  magic bytes read  from start of file 

   // -------------optional fields for ancillary chunks----------------------------  
   png_color_16 trans;           ///< transparent values for non-palette image
   png_color_16 background;      ///< background color (from bKGD)
} MY_PNG_INFO;


/**
 * @brief this struct is to maintain hw decoder information configured by GDI/AP
 */
typedef struct PNG_HW_INFO_T
{
   void*                      colorTableStartAddr; 
   void*                      HCLENStartAddr;      
   void*                      HLITStartAddr;        
   void*                      HDISTStartAddr;        
   void*                      lineBuff0StartAddr;     
   void*                      lz77StartAddr;           
   void*                      trnsTableAddr;       
   void*                      canvasStartAddr;     
   kal_int32                  canvas_width;       
   kal_int32                  canvas_height;       
   PNG_DECODE_COLOR_FORMAT_ENUM      canvasColorFormat;
   kal_int32                  outputWindow_x;       
   kal_int32                  outputWindow_y;       
   kal_int32                  outputWindowWidth;
   kal_int32                  outputWindowHeight;
   kal_int32                  clipWindow_ul_x;     
   kal_int32                  clipWindow_ul_y;
   kal_int32                  clipWindow_dr_x;     
   kal_int32                  clipWindow_dr_y;      
   png_color                  orgReplacedColor;    
   png_color                  newReplaceColor;      
   PNG_BLEND_MODE_ENUM        blendingMode;      
   kal_int32                  userSetAlphaValue;   
   void*                      blendingBufferStartAddr;   
   PNG_DECODE_COLOR_FORMAT_ENUM      blend_buf_format;       
   kal_int32                  timeoutMsec;   
   kal_bool                   ifSetWorkingBuffer;
   kal_bool                   ifSetSourceData;           ///< if IDAT has reached in parsing process, ifSetSourceData = true \n  after decode pause, ifSetSourceDat = false  until pngSetSourceData() is invoked
   kal_bool                   ifSetCanvas;               ///< ifSetCanvas = true if pngSetCanvas() is invoked
   kal_bool                   ifSetOutputWindow;         ///< ifSetOutputWindow = true if pngSetOutputWindow() is invoked
   kal_bool                   ifSetCallback;             ///< ifSetCallback = true if pngHookCallback() is invoked
   kal_bool                   ifSetClipWindow;           ///< if SetClipWindow = true if pngSetClipWindow() is invoked
   kal_bool                   ifSetColorReplacing;       ///< if ifSetColorReplacing = true if pngSetReplaceColor() is invoked
   
} PNG_HW_INFO;

#endif //   #ifdef USE_HW_PNG_DECODER
#endif //   __PNG_INFO_H__ 
