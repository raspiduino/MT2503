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
 *   g2d_structure.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   G2D Driver
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __G2D_STRUCTURE_H__
#define __G2D_STRUCTURE_H__

#include "kal_general_types.h" 

#include "drv_features_g2d.h"  
#include "g2d_enum.h"

#include "gfx_cache_switch_behavior_enum.h"



typedef struct G2D_COORDINATE_T
{
   kal_int32 x;
   kal_int32 y;

} G2D_COORDINATE_STRUCT;



typedef struct G2D_WINDOW_T
{
   G2D_COORDINATE_STRUCT topLeft;
   G2D_COORDINATE_STRUCT buttomRight;

} G2D_WINDOW_STRUCT;



typedef struct G2D_COLOR_T
{
   kal_uint8 alpha;
   kal_uint8 red;
   kal_uint8 green;
   kal_uint8 blue;

} G2D_COLOR_STRUCT;



typedef struct G2D_CANVAS_INFO_STRUCT_T
{
   kal_uint8 *RGBBufferAddr;                  /// For the use of encode from RGB buffer
   kal_uint8 *YUVBufferAddr[3];
   kal_uint32 RGBBufferSize;
   kal_uint32 YUVBufferSize[3];
   kal_uint32 width;                         /// width in pixel
   kal_uint32 height;                        /// height in pixel
   G2D_COLOR_FORMAT_ENUM colorFormat;        /// color format
   kal_uint32 bytesPerPixel;

} G2D_CANVAS_INFO_STRUCT;



typedef struct G2D_RECTANGLE_FILL_T
{
   G2D_CANVAS_INFO_STRUCT srcCanvas;

   G2D_WINDOW_STRUCT dstWindow;          /// define destination buffer info.
   kal_uint32 rectFillColor;
   kal_uint32 srcAlphaValue;
   kal_bool srcAlphaEnable;
   kal_bool overlayBufferEnable;
}G2D_RECTANGLE_FILL_STRUCT;



typedef struct G2D_FONT_CACHING_T
{
   G2D_CANVAS_INFO_STRUCT srcCanvas;

   G2D_WINDOW_STRUCT srcWindow;          /// define source rectangle buffer to be bitblt
   G2D_WINDOW_STRUCT dstWindow;          /// define destination buffer info.

   G2D_COLOR_STRUCT foregroundColor;

   kal_bool aaFontEnable;

   G2D_FONT_BIT_ENUM fontBit;

   #if defined(G2D_HW_TILT_FONT_SUPPORT)
      kal_bool tiltModeEnable;                ///italic mode
      kal_uint32 tiltValued[32];
      kal_int32 tiltTableSize;
   #endif
} G2D_FONT_STRUCT;



typedef struct G2D_BITBLT__T
{
   /// src config
   G2D_CANVAS_INFO_STRUCT srcCanvas;

   G2D_WINDOW_STRUCT srcWindow;          /// define source rectangle buffer to be bitblt
   G2D_WINDOW_STRUCT dstWindow;          /// define destination buffer info.


   kal_bool srcAlphaEnable;
   kal_uint32 srcAlphaValue;

   kal_bool dstAlphaEnable;
   kal_uint32 dstAlphaValue;

   G2D_CW_ROTATE_ANGLE_ENUM rotation;

   kal_uint32* indexColorTableAddr;
   G2D_INDEX_COLOR_TABLE_SIZE_ENUM  indexColorTableSize;

} G2D_BITBLT_STRUCT;



typedef struct G2D_SAD_IMG_STRUCT_T
{
   kal_uint8 *bufferAddr;       /// the first byte of the first row
   kal_uint32 bufferSize;
   kal_uint32 width;               /// width in pixel
   kal_uint32 height;              /// height in pixel
   G2D_WINDOW_STRUCT window;

} G2D_SAD_IMG_STRUCT;



typedef struct G2D_SAD_T
{
   G2D_SAD_IMG_STRUCT imgInfo[2];        
   G2D_WINDOW_STRUCT dstWindow;
   
} G2D_SAD_STRUCT;



typedef union {
   kal_uint32 fixedMatrix[9];
   float floatMatrix[9];

}G2D_LT_MATRIX_UNION;



typedef struct G2D_LT_STRUCT_T
{
   G2D_CANVAS_INFO_STRUCT srcCanvas;
   G2D_WINDOW_STRUCT srcWindow;
   G2D_WINDOW_STRUCT dstWindow;

   kal_bool srcRectFillEnable;
   kal_uint32 srcRectFillColor;

   kal_bool srcAlphaEnable;
   kal_uint32 srcAlphaValue;

   kal_bool dstAlphaEnable;
   kal_uint32 dstAlphaValue;

   G2D_LT_SAMPLE_MODE_ENUM samplingMode;

   G2D_LT_SRC_KEY_EDGE_FILTER_ENUM srcKeyFilterMode;
   kal_uint32 userSpecifiedColor;

   G2D_LT_MATRIX_UNION inverseMatrix;
   G2D_LT_MATRIX_UNION matrix;

} G2D_LT_STRUCT;

#if (defined(G2D_HW_OVERLAY_SUPPORT))   

typedef struct G2D_OVERLAY_LAYER_STRUCT_T
{
   kal_bool layerEnable;

   G2D_CANVAS_INFO_STRUCT layerCanvas;
   G2D_WINDOW_STRUCT layerWindow;

   kal_bool layerAlphaEnable;
   kal_uint32 layerAlphaValue;

   kal_bool srcKeyEnable;
   kal_uint32 srcKeyValue;

   G2D_OVERLAY_LAYER_FUNCTION_ENUM function;

   G2D_FONT_BIT_ENUM fontBit;
   kal_uint32 foregroundColor;

   kal_uint32 rectFillColor;
   G2D_CW_ROTATE_ANGLE_ENUM rotation;

} G2D_OVERLAY_LAYER_STRUCT;



typedef struct G2D_OVERLAY_STRUCT_T
{
   G2D_OVERLAY_LAYER_STRUCT layerInfo[G2D_HW_OVERLAY_TOTAL_LAYER];

   kal_uint32 backgroundColor;
   #if defined(G2D_FPGA)
      kal_bool backgroundDisable;
   #endif

   kal_bool dstAlphaEnable;
   kal_uint32 dstAlphaValue;

   G2D_COORDINATE_STRUCT dstCoordiante;
   G2D_WINDOW_STRUCT roiWindow;
} G2D_OVERLAY_STRUCT;

#endif

typedef struct G2D_HANDLE_STRUCT_T
{
   G2D_STATE_ENUM g2dState;
   G2D_CODEC_TYPE_ENUM type;
   #if defined(G2D_HW_SHARE_WITH_GOVL_SUPPORT)
      G2D_CODEC_OWNER_ENUM owner;
   #endif

   #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
      G2D_MEMORY_TYPE_ENUM srcRectFillOverlayRGBCanvasType;
      G2D_MEMORY_TYPE_ENUM srcBitbltRGBCanvasType;
      G2D_MEMORY_TYPE_ENUM srcLtRGBCanvasType;
      G2D_MEMORY_TYPE_ENUM srcLtYUVCanvasType[3];
      
      G2D_MEMORY_TYPE_ENUM dstCanvasType;

      GFX_CACHE_SWITCH_BEHAVIOR_ENUM srcCanvasCacheSwitchBehavior;
      GFX_CACHE_SWITCH_BEHAVIOR_ENUM dstCanvasCacheSwitchBehavior;
   #endif
   
   /// coordinate system
   G2D_CANVAS_INFO_STRUCT dstCanvas;

   kal_bool clipEnable;
   G2D_WINDOW_STRUCT clipWindow;

   /// The inter-section between clip_window and dst_window
   G2D_WINDOW_STRUCT targetClipWindow;

   /// for source key
   /// For Bitblt, Rect, LT
   kal_bool srcKeyEnable;
   G2D_COLOR_STRUCT srcKeyValue;

   /// for color replacement
   kal_bool colorReplaceEnable;
   G2D_COLOR_STRUCT colorToAvoid;           /// color to avoid (to be replaced)
   G2D_COLOR_STRUCT colorToReplace;         /// color to replace colorToAvoid

   void* intMemAddr;
   kal_uint32 intMemSize;

   #if defined(G2D_HW_DITHERING_SUPPORT)
      kal_bool ditheringEnable;
      G2D_DITHERING_MODE_ENUM ditheringMode;
      G2D_DITHERING_BIT_ENUM ditherBitR;
      G2D_DITHERING_BIT_ENUM ditherBitG;
      G2D_DITHERING_BIT_ENUM ditherBitB;
            

   #endif
   #if defined(G2D_HW_SUPPORT)
      G2D_FONT_STRUCT fontFunc;
      G2D_BITBLT_STRUCT bitbltFunc;

      #if defined(G2D_HW_SAD_SUPPORT)
         G2D_SAD_STRUCT sadFunc;
      #endif

      #if defined(G2D_HW_OVERLAY_SUPPORT)
         G2D_OVERLAY_STRUCT overlayFunc;
      #endif
   #endif

   G2D_RECTANGLE_FILL_STRUCT rectFillFunc;
   G2D_LT_STRUCT ltFunc;

   #if defined(G2D_FPGA)
      G2D_READ_BURST_TYPE_ENUM readBurstType;
      G2D_WRITE_BURST_TYPE_ENUM writeBurstType;
      kal_bool slowDownEnable;
      kal_uint32 slowDownCount;

      kal_bool autoTileSizeEnable;
      G2D_TILE_SIZE_TYPE_ENUM tileSize;
      G2D_LT_CACHE_SIZE_ENUM cacheSize;
      G2D_MAX_OUTSTANDING_NUM_ENUM maxOutstanding;
      G2D_DITHERING_BIT_ENUM ditherBitR;
      G2D_DITHERING_BIT_ENUM ditherBitG;
      G2D_DITHERING_BIT_ENUM ditherBitB;
      kal_uint32 ditherMw;
      kal_uint32 ditherMz;
   #endif

   kal_bool callbackEnable;
   G2D_CALLBACK_FUNC_PTR g2dCallback;

} G2D_HANDLE_STRUCT;



#endif  /*g2d_structure.h*/
