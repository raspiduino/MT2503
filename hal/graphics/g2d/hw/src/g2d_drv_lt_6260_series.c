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
 *   g2d_drv_lt_6260_series.c
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features_g2d.h"

#if defined (__DRV_GRAPHICS_G2D_6260_SERIES__)

#include "kal_general_types.h"

#if defined(G2D_CODEC_STANDALONE)
   #include "assert.h"
   #ifndef ASSERT
      #define ASSERT(x) assert(x)
   #endif
#elif defined(G2D_FPGA)
   #include "assert.h"
   #ifndef ASSERT
      #define ASSERT(x) { if (!(x))  while (1); }
   #endif 
#else
   #include "kal_public_api.h"
#endif

#include "g2d_enum.h"
#include "g2d_structure.h"
#include "g2d_macro.h"
#include "g2d_drv_6260_series.h"
#include "g2d_drv_api.h"

#include "iul_x_math.h"

#if defined(__MTK_TARGET__) || defined(G2D_FPGA)
#else
   extern kal_uint32 g2d_hw_registers[100];
#endif



static void _g2d_drv_lt_set_src_info(G2D_HANDLE_STRUCT *handle)
{
   G2D_LT_STRUCT *ltFunc = &(handle->ltFunc);
   G2D_CANVAS_INFO_STRUCT  *srcCanvas = &(ltFunc->srcCanvas);
   G2D_WINDOW_STRUCT *srcWindow  = &(ltFunc->srcWindow);
   G2D_COORDINATE_STRUCT *topLeft     = &(srcWindow->topLeft);
   G2D_COORDINATE_STRUCT *buttomRight = &(srcWindow->buttomRight);
   kal_uint32 width, height, pitch;
   kal_uint8* addr;

   /// -2048 <= x <= 2047
   ASSERT((topLeft->x) >= 0);
   ASSERT((topLeft->y) >= 0);
   SET_G2D_LAYER_OFFSET(1, 0, 0);

   /// Pitch
   pitch = (srcCanvas->width) * (srcCanvas->bytesPerPixel);
   ASSERT(((unsigned)pitch) <= 0x2000);
   SET_G2D_LAYER_PITCH(1, pitch);

   /// setting the source canvas info. and source lt rectangle
   if (KAL_FALSE == ltFunc->srcRectFillEnable)
   {
      switch(srcCanvas->colorFormat)
      {
         case G2D_COLOR_FORMAT_RGB565:
         case G2D_COLOR_FORMAT_ARGB8888:
         case G2D_COLOR_FORMAT_RGB888:
         case G2D_COLOR_FORMAT_BGR888:
         case G2D_COLOR_FORMAT_PARGB8888:
         case G2D_COLOR_FORMAT_ARGB8565:
         case G2D_COLOR_FORMAT_PARGB8565:
         case G2D_COLOR_FORMAT_ARGB6666:
         case G2D_COLOR_FORMAT_PARGB6666:
            ASSERT(NULL != (srcCanvas->RGBBufferAddr));
            addr = srcCanvas->RGBBufferAddr + ((topLeft->y) * (srcCanvas->width) + (topLeft->x)) * (srcCanvas->bytesPerPixel);
            SET_G2D_LAYER_ADDR(1, (kal_uint32)addr);
         break;
         case G2D_COLOR_FORMAT_UYVY422:
            ASSERT(NULL != (srcCanvas->YUVBufferAddr[0]));
            addr = srcCanvas->YUVBufferAddr[0] + ((topLeft->y) * (srcCanvas->width) + (topLeft->x)) * (srcCanvas->bytesPerPixel);
            SET_G2D_LAYER_ADDR(1, (kal_uint32)addr);
         break;
         default:
            ASSERT(0);
         break;
      }
   }

   width = buttomRight->x - topLeft->x + 1;
   height = buttomRight->y - topLeft->y + 1;
   /// 1 <= x <= 2048
   ASSERT(((unsigned)(width - 1)) < 2048);
   ASSERT(((unsigned)(height - 1)) < 2048);
   SET_G2D_LAYER_SIZE(1, width, height);

   /// set src_clr_fmt bits
   switch(srcCanvas->colorFormat)
   {
      case G2D_COLOR_FORMAT_RGB565:
         SET_G2D_LAYER_CON_COLOR_FORMAT(1, G2D_LX_CON_COLOR_RGB565);
      break;
      case G2D_COLOR_FORMAT_ARGB8888:
         SET_G2D_LAYER_CON_COLOR_FORMAT(1, G2D_LX_CON_COLOR_ARGB8888);
      break;
      case G2D_COLOR_FORMAT_RGB888:
         SET_G2D_LAYER_CON_COLOR_FORMAT(1, G2D_LX_CON_COLOR_RGB888);
      break;
      case G2D_COLOR_FORMAT_BGR888:
         SET_G2D_LAYER_CON_COLOR_FORMAT(1, G2D_LX_CON_COLOR_BGR888);
      break;
      case G2D_COLOR_FORMAT_PARGB8888:
         SET_G2D_LAYER_CON_COLOR_FORMAT(1, G2D_LX_CON_COLOR_PARGB8888);
      break;
      case G2D_COLOR_FORMAT_UYVY422:
         SET_G2D_LAYER_CON_COLOR_FORMAT(1, G2D_LX_CON_COLOR_UYVY);
      break;
      case G2D_COLOR_FORMAT_ARGB8565:
         SET_G2D_LAYER_CON_COLOR_FORMAT(1, G2D_LX_CON_COLOR_ARGB8565);
      break;
      case G2D_COLOR_FORMAT_PARGB8565:
         SET_G2D_LAYER_CON_COLOR_FORMAT(1, G2D_LX_CON_COLOR_PARGB8565);
      break;
      case G2D_COLOR_FORMAT_ARGB6666:
         SET_G2D_LAYER_CON_COLOR_FORMAT(1, G2D_LX_CON_COLOR_ARGB6666);
      break;
      case G2D_COLOR_FORMAT_PARGB6666:
         SET_G2D_LAYER_CON_COLOR_FORMAT(1, G2D_LX_CON_COLOR_PARGB6666);
      break;
      default:
         ASSERT(0);
      break;
   }

   if(KAL_TRUE == (ltFunc->srcAlphaEnable))
   {
      ENABLE_G2D_LAYER_CON_ALPHA(1);
      SET_G2D_LAYER_CON_ALPHA(1, ltFunc->srcAlphaValue);
   }

   if (KAL_TRUE == ltFunc->srcRectFillEnable)
   {
      SET_G2D_LAYER_RECTANGLE_FILL_COLOR(1, (kal_uint32)ltFunc->srcRectFillColor);
      ENABLE_G2D_LAYER_CON_RECT_FILL(1);
   }

   ENABLE_G2D_ROI_LAYER(1);
}

static void _g2d_drv_lt_set_dst_info(G2D_HANDLE_STRUCT *handle)
{
   G2D_CANVAS_INFO_STRUCT *dstCanvas  = &(handle->dstCanvas);
   G2D_LT_STRUCT *ltFunc = &(handle->ltFunc);
   #if defined(G2D_FPGA)
      G2D_WINDOW_STRUCT *dstWindow  = &(ltFunc->dstWindow);
   #else
      G2D_WINDOW_STRUCT *dstWindow  = &(handle->targetClipWindow);
   #endif
   G2D_COORDINATE_STRUCT *topLeft     = &(dstWindow->topLeft);
   G2D_COORDINATE_STRUCT *buttomRight = &(dstWindow->buttomRight);
   kal_uint32 width, height, pitch;

   #if !defined(G2D_FPGA)
      /// -2048 <= x <= 2047
      ASSERT(((unsigned)((topLeft->x) + 2048)) < 4096);
      ASSERT(((unsigned)((topLeft->y) + 2048)) < 4096);
   #endif

   SET_G2D_LAYER_OFFSET(0, 0, 0);
   SET_G2D_ROI_OFFSET(topLeft->x, topLeft->y);
   SET_G2D_W2M_OFFSET(topLeft->x, topLeft->y);
   /// Pitch
   pitch = (dstCanvas->width) * (dstCanvas->bytesPerPixel);
   ASSERT(((unsigned)pitch) <= 0x2000);
   SET_G2D_LAYER_PITCH(0, pitch);
   SET_G2D_W2M_PITCH(pitch);

   /// setting the source canvas info. and source lt rectangle
   ASSERT(NULL != (dstCanvas->RGBBufferAddr));
   SET_G2D_LAYER_ADDR(0, (kal_uint32)(dstCanvas->RGBBufferAddr));
   SET_G2D_W2M_ADDR((kal_int32)dstCanvas->RGBBufferAddr);

   width = buttomRight->x - topLeft->x + 1;
   height = buttomRight->y - topLeft->y + 1;
   /// 1 <= x <= 2048
   ASSERT(((unsigned)(width - 1)) < 2048);
   ASSERT(((unsigned)(height - 1)) < 2048);
   //SET_G2D_LAYER_SIZE(0, width, height);
   SET_G2D_ROI_SIZE(width, height);

   SET_G2D_LAYER_SIZE(0, dstCanvas->width, dstCanvas->height);

   /// setting destination color format bits
   switch(dstCanvas->colorFormat)
   {
      case G2D_COLOR_FORMAT_RGB565:
         SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_RGB565);
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_RGB565);
      break;
      case G2D_COLOR_FORMAT_ARGB8888:
         SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_ARGB8888);
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_ARGB8888);
      break;
      case G2D_COLOR_FORMAT_RGB888:
         SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_RGB888);
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_RGB888);
      break;
      case G2D_COLOR_FORMAT_BGR888:
         SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_BGR888);
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_BGR888);
      break;
      case G2D_COLOR_FORMAT_PARGB8888:
         SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_PARGB8888);
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_PARGB8888);
      break;
      case G2D_COLOR_FORMAT_ARGB8565:
         SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_ARGB8565);
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_ARGB8565);
      break;
      case G2D_COLOR_FORMAT_PARGB8565:
         SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_PARGB8565);
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_PARGB8565);
      break;
      case G2D_COLOR_FORMAT_ARGB6666:
         SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_ARGB6666);
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_ARGB6666);
      break;
      case G2D_COLOR_FORMAT_PARGB6666:
         SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_PARGB6666);
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_PARGB6666);
      break;
      default:
         ASSERT(0);
      break;
   }

   //ENABLE_G2D_ROI_LAYER(0);
   ENABLE_G2D_ROI_LAYER_0;

   /// Always disable bg
   DISABLE_G2D_ROI_CON_BG;

   if(KAL_TRUE == (ltFunc->dstAlphaEnable))
   {
      ENABLE_G2D_ROI_CON_ALPHA;
      SET_G2D_ROI_CON_ALPHA(ltFunc->dstAlphaValue);
   }

}



static void _g2d_drv_lt_set_sample_mode(G2D_HANDLE_STRUCT *handle)
{
   G2D_LT_STRUCT *ltFunc = &(handle->ltFunc);
   G2D_LT_SAMPLE_MODE_ENUM samplingMode = ltFunc->samplingMode;

   /// set sample mode
   REG_G2D_MODE_CTRL |= ((samplingMode) & 0xF) << 16;

   if(G2D_LT_SAMPLE_MODE_BILINEAR_WITH_EDGE_FILTER_USER_SPEC_COLOR == samplingMode)
   {
      REG_G2D_LT_EDGE_FILTER_USER_SPECIFIED_COLOR = ltFunc->userSpecifiedColor;
   }
}


static void _g2d_drv_lt_set_dithering_mode(G2D_HANDLE_STRUCT *handle)
{
   G2D_LT_STRUCT *ltFunc = &(handle->ltFunc);
   G2D_CANVAS_INFO_STRUCT	*srcCanvas = &(ltFunc->srcCanvas);
   G2D_CANVAS_INFO_STRUCT *dstCanvas  = &(handle->dstCanvas);

   /// setting destination color format bits
#if defined(G2D_HW_DITHERING_SUPPORT)
   if (KAL_TRUE == handle->ditheringEnable)
   {
      switch(srcCanvas->colorFormat)
      {
         //case G2D_COLOR_FORMAT_RGB565:
         case G2D_COLOR_FORMAT_RGB888:
         case G2D_COLOR_FORMAT_BGR888:
         {
            switch(dstCanvas->colorFormat)
            {
               case G2D_COLOR_FORMAT_RGB565:
               handle->ditherBitR = (G2D_DITHERING_BIT_ENUM)3;
               handle->ditherBitG = (G2D_DITHERING_BIT_ENUM)2;
               handle->ditherBitB = (G2D_DITHERING_BIT_ENUM)3;
               break;
               case G2D_COLOR_FORMAT_PARGB6666:
               handle->ditherBitR = (G2D_DITHERING_BIT_ENUM)2;
               handle->ditherBitG = (G2D_DITHERING_BIT_ENUM)2;
               handle->ditherBitB = (G2D_DITHERING_BIT_ENUM)2;
               break;
            }
            break;
         }
         case G2D_COLOR_FORMAT_ARGB8888:
         case G2D_COLOR_FORMAT_PARGB8888:
         {
            switch(dstCanvas->colorFormat)
            {
               case G2D_COLOR_FORMAT_RGB565:
               handle->ditherBitR = (G2D_DITHERING_BIT_ENUM)3;
               handle->ditherBitG = (G2D_DITHERING_BIT_ENUM)2;
               handle->ditherBitB = (G2D_DITHERING_BIT_ENUM)3;
               break;
               case G2D_COLOR_FORMAT_ARGB8888:
               case G2D_COLOR_FORMAT_PARGB8888:
               handle->ditherBitR = (G2D_DITHERING_BIT_ENUM)3;
               handle->ditherBitG = (G2D_DITHERING_BIT_ENUM)3;
               handle->ditherBitB = (G2D_DITHERING_BIT_ENUM)3;
               break;
               case G2D_COLOR_FORMAT_PARGB6666:
               handle->ditherBitR = (G2D_DITHERING_BIT_ENUM)2;
               handle->ditherBitG = (G2D_DITHERING_BIT_ENUM)2;
               handle->ditherBitB = (G2D_DITHERING_BIT_ENUM)2;

               break;
            }
            break;
         }
         case G2D_COLOR_FORMAT_PARGB6666:
         {
            if (G2D_COLOR_FORMAT_RGB565 == dstCanvas->colorFormat)
            {
               //The HW will use PARGB8888 to process in interal format.
               //You must choose 3.2.3, not 1.0.1
               handle->ditherBitR = (G2D_DITHERING_BIT_ENUM)3;
               handle->ditherBitG = (G2D_DITHERING_BIT_ENUM)2;
               handle->ditherBitB = (G2D_DITHERING_BIT_ENUM)3;
            }
            break;
         }
         default:
         break;
      }
      g2d_drv_set_dithering(handle);
   }
#endif

}


static void _g2d_drv_lt_set_src_key_filter(G2D_HANDLE_STRUCT *handle)
{
   G2D_LT_STRUCT *ltFunc = &(handle->ltFunc);
   ///G2D_LT_SAMPLE_MODE_ENUM sample_mode = ltFunc->samplingMode;
   G2D_LT_SRC_KEY_EDGE_FILTER_ENUM srcKeyFilterMode = ltFunc->srcKeyFilterMode;


   if(KAL_TRUE == (handle->srcKeyEnable))
   {
      ///ASSERT((G2D_LT_SAMPLE_MODE_BILINEAR_WITH_EDGE_FILTER_DULPLICATE == sample_mode) ||
      ///       (G2D_LT_SAMPLE_MODE_BILINEAR_WITHOUT_EDGE_FILTER == sample_mode) ||
      ///       (G2D_LT_SAMPLE_MODE_NEAREST == sample_mode) ||
      ///       (G2D_LT_SAMPLE_MODE_TRUNCATED == sample_mode));

      if(G2D_LT_SRC_KEY_EDGE_FILTER_USER_SPEC_COLOR == srcKeyFilterMode)
      {
         REG_G2D_MODE_CTRL |= 1 << 20;
         REG_G2D_LT_EDGE_FILTER_USER_SPECIFIED_COLOR = ltFunc->userSpecifiedColor;
      }
   }
}



static void _g2d_drv_lt_set_float_inverse_matrix(G2D_HANDLE_STRUCT *handle)
{
   #if defined(G2D_FPGA)
      G2D_WINDOW_STRUCT *dstWindow  = &(handle->ltFunc.dstWindow);
   #else
      G2D_WINDOW_STRUCT *dstWindow  = &(handle->targetClipWindow);
   #endif
   G2D_COORDINATE_STRUCT *dstWindowTopLeft     = &(dstWindow->topLeft);
   kal_int32 dstWindow_start_x = dstWindowTopLeft->x;
   kal_int32 dstWindow_start_y = dstWindowTopLeft->y;

   //G2D_LT_MATRIX_UNION *inverseMatrix = &(handle->ltFunc.inverseMatrix);
   float *floatMatrix = handle->ltFunc.inverseMatrix.floatMatrix;
   IUL_FIXED fixedMatrix[9];

   fixedMatrix[0] = IUL_F_TO_X(floatMatrix[0]);
   fixedMatrix[1] = IUL_F_TO_X(floatMatrix[1]);
   fixedMatrix[2] = IUL_F_TO_X(floatMatrix[2]);
   fixedMatrix[3] = IUL_F_TO_X(floatMatrix[3]);
   fixedMatrix[4] = IUL_F_TO_X(floatMatrix[4]);
   fixedMatrix[5] = IUL_F_TO_X(floatMatrix[5]);
   fixedMatrix[6] = IUL_F_TO_X(floatMatrix[6]);
   fixedMatrix[7] = IUL_F_TO_X(floatMatrix[7]);
   fixedMatrix[8] = IUL_F_TO_X(floatMatrix[8]);

   REG_G2D_SX_INIT = IUL_F_TO_X(floatMatrix[0] * dstWindow_start_x + floatMatrix[1] * dstWindow_start_y + floatMatrix[2]);
   REG_G2D_SY_INIT = IUL_F_TO_X(floatMatrix[3] * dstWindow_start_x + floatMatrix[4] * dstWindow_start_y + floatMatrix[5]);
   REG_G2D_SZ_INIT = IUL_F_TO_X(floatMatrix[6] * dstWindow_start_x + floatMatrix[7] * dstWindow_start_y + floatMatrix[8]);

   REG_G2D_START_DST_X = dstWindow_start_x;
   REG_G2D_START_DST_Y = dstWindow_start_y;

   REG_G2D_SDXDX = fixedMatrix[0];
   REG_G2D_SDYDX = fixedMatrix[3];
   REG_G2D_SDZDX = fixedMatrix[6];
   REG_G2D_SDXDY = fixedMatrix[1];
   REG_G2D_SDYDY = fixedMatrix[4];
   REG_G2D_SDZDY = fixedMatrix[7];
}



static kal_bool _g2d_drv_lt_check_window_range(G2D_HANDLE_STRUCT *handle)
{
   G2D_CANVAS_INFO_STRUCT *srcCanvas = &handle->ltFunc.srcCanvas;
   G2D_CANVAS_INFO_STRUCT *dstCanvas = &handle->dstCanvas;
   G2D_WINDOW_STRUCT *srcWindow  = &handle->ltFunc.srcWindow;
   G2D_WINDOW_STRUCT *dstWindow  = &handle->ltFunc.dstWindow;
   G2D_COORDINATE_STRUCT *dstTopLeft = &(dstWindow->topLeft);
   G2D_COORDINATE_STRUCT *dstButtomRight = &(dstWindow->buttomRight);
   G2D_COORDINATE_STRUCT *srcTopLeft = &(srcWindow->topLeft);
   G2D_COORDINATE_STRUCT *srcButtomRight = &(srcWindow->buttomRight);

   /// pitch = 0
   if(0 == (srcCanvas->width))
     return KAL_FALSE;
   /// width =0  height =0
   if((0 > (srcButtomRight->x - srcTopLeft->x)) || (0 > (srcButtomRight->y - srcTopLeft->y)))
     return KAL_FALSE;

   /// pitch = 0
   if(0 == (dstCanvas->width))
     return KAL_FALSE;
   /// width =0  height =0
   if((0 > (dstButtomRight->x - dstTopLeft->x)) || (0 > (dstButtomRight->y - dstTopLeft->y)))
     return KAL_FALSE;

   /// clip check
   if(KAL_TRUE == handle->clipEnable)
   {
      G2D_WINDOW_STRUCT *clip_w = &handle->clipWindow;
      G2D_COORDINATE_STRUCT *clipTopLeft = &(clip_w->topLeft);
      G2D_COORDINATE_STRUCT *clipButtomRight = &(clip_w->buttomRight);

      if(((clipButtomRight->x) < 0) && ((clipTopLeft->x) < 0))
        return KAL_FALSE;
      if(((clipButtomRight->y) < 0) && ((clipTopLeft->y) < 0))
        return KAL_FALSE;
     /// width =0  height =0
      if((0 > (clipButtomRight->x - clipTopLeft->x)) || (0 > (clipButtomRight->y - clipTopLeft->y)))
        return KAL_FALSE;
    }
    return KAL_TRUE;
}



static void _g2d_drv_lt_set_window_intersection(G2D_HANDLE_STRUCT *handle)
{
   G2D_WINDOW_STRUCT *clipWindow = &(handle->clipWindow);
   G2D_COORDINATE_STRUCT *clipWindowTopLeft     = &(clipWindow->topLeft);
   G2D_COORDINATE_STRUCT *clipWindowButtomRight = &(clipWindow->buttomRight);
   G2D_WINDOW_STRUCT *dstWindow  = &(handle->ltFunc.dstWindow);
   G2D_COORDINATE_STRUCT *dstWindowTopLeft     = &(dstWindow->topLeft);
   G2D_COORDINATE_STRUCT *dstWindowButtomRight = &(dstWindow->buttomRight);
   G2D_WINDOW_STRUCT *targetClipWindow = &(handle->targetClipWindow);

   kal_uint32 dstCanvasWidth  = handle->dstCanvas.width;
   kal_uint32 dstCanvasHeight = handle->dstCanvas.height;

   if(KAL_FALSE == handle->clipEnable)
   {
      targetClipWindow->topLeft.x = dstWindowTopLeft->x;
      targetClipWindow->topLeft.y = dstWindowTopLeft->y;

      targetClipWindow->buttomRight.x = dstWindowButtomRight->x;
      targetClipWindow->buttomRight.y = dstWindowButtomRight->y;
   }
   else
   {
      targetClipWindow->topLeft.x = MAX(0, clipWindowTopLeft->x);
      targetClipWindow->topLeft.y = MAX(0, clipWindowTopLeft->y);

      targetClipWindow->topLeft.x = MAX(dstWindowTopLeft->x, targetClipWindow->topLeft.x);
      targetClipWindow->topLeft.y = MAX(dstWindowTopLeft->y, targetClipWindow->topLeft.y);

      targetClipWindow->buttomRight.x = MIN(clipWindowButtomRight->x, dstCanvasWidth - 1);
      targetClipWindow->buttomRight.y = MIN(clipWindowButtomRight->y, dstCanvasHeight - 1);

      targetClipWindow->buttomRight.x = MIN(dstWindowButtomRight->x, targetClipWindow->buttomRight.x);
      targetClipWindow->buttomRight.y = MIN(dstWindowButtomRight->y, targetClipWindow->buttomRight.y);
   }
}



#if defined(G2D_HW_LT_C_MODEL_SUPPORT)
   G2D_STATUS_ENUM g2d_drv_c_model_start(G2D_HANDLE_STRUCT *handle);
#endif

G2D_STATUS_ENUM g2d_drv_lt_start(G2D_HANDLE_STRUCT *handle)
{
   {
      kal_bool status;

      #if !defined(G2D_FPGA)
         status = _g2d_drv_lt_check_window_range(handle);
         if(KAL_FALSE == status)
             return G2D_STATUS_OK;
      #endif

      _g2d_drv_lt_set_window_intersection(handle);
   }

   HARD_RESET_G2D_ENGINE;
   REG_G2D_MODE_CTRL = 0x400000;
   REG_G2D_ROI_CON = 0;
   REG_G2D_DI_CON = 0x0;
   CLR_G2D_LAYER_CON(0);
   CLR_G2D_LAYER_CON(1);

   /// setting the hw hisr callback function
   g2d_drv_set_hw_hisr_callback(&g2d_irq_handler);

   /// setting the source color key
   g2d_drv_set_source_color_key(handle, handle->ltFunc.srcCanvas.colorFormat);

   /// setting the avoidance and replacement colors
   g2d_drv_set_replacement_colors(handle);

   /// setting the lt source infomation(src buffer ,src lt rectangle)
   _g2d_drv_lt_set_src_info(handle);

   /// setting the lt destination infomation
   _g2d_drv_lt_set_dst_info(handle);

   /// setting dithering mode
   _g2d_drv_lt_set_dithering_mode(handle);

   /// setting the clipping window
   g2d_drv_set_clipping_window(handle);

   /// set sample mode
   _g2d_drv_lt_set_sample_mode(handle);

   _g2d_drv_lt_set_src_key_filter(handle);

   /// matrix
   _g2d_drv_lt_set_float_inverse_matrix(handle);

   //Enable Tile
   g2d_drv_set_tile(handle);

   /// burst mode
   g2d_drv_set_burst_type(handle);

   /// slow down
   g2d_drv_set_slow_down(handle);

   //// set cache
   //#if defined(G2D_FPGA)
   //   SET_REG_G2D_CACHE_CON_LT_CACHE_SIZE(handle->cacheSize);
   //#else
   //   SET_REG_G2D_CACHE_CON_LT_CACHE_SIZE(G2D_LT_CACHE_SIZE_8x8);
   //#endif

   if (KAL_TRUE == handle->callbackEnable)
   {
      REG_G2D_IRQ |= G2D_IRQ_ENABLE_BIT;
   }
   else
   {
      REG_G2D_IRQ &= ~G2D_IRQ_ENABLE_BIT;
   }
   REG_G2D_MODE_CTRL |= G2D_MODE_CON_ENG_MODE_G2D_LT_BIT;

   /// trigger
   REG_G2D_START = G2D_START_BIT;

   #if defined(G2D_HW_LT_C_MODEL_SUPPORT)
      g2d_drv_c_model_start(handle);
   #endif

   return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2d_drv_lt_query_src_alpha_support(void)
{
   return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2d_drv_lt_query_dst_alpha_support(void)
{
   return G2D_STATUS_OK;
}
#endif /// __DRV_GRAPHICS_G2D_6260_SERIES__

