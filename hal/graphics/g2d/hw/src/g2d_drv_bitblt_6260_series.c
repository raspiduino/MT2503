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
 *   g2d_drv_bitblt_6260_series.c
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
 *
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

#if defined(__MTK_TARGET__) || defined(G2D_FPGA)
#else
   extern kal_uint32 g2d_hw_registers[100];
#endif



static void _g2d_drv_bitblt_set_src_info(G2D_HANDLE_STRUCT *handle)
{
   G2D_BITBLT_STRUCT *bitbltFunc = &(handle->bitbltFunc);
   G2D_CANVAS_INFO_STRUCT  *srcCanvas = &(bitbltFunc->srcCanvas);
   G2D_WINDOW_STRUCT *srcWindow  = &(bitbltFunc->srcWindow);
   G2D_COORDINATE_STRUCT *topLeft     = &(srcWindow->topLeft);
   G2D_COORDINATE_STRUCT *buttomRight = &(srcWindow->buttomRight);
   kal_uint32 width, height, pitch;
   kal_uint8* addr;

   /// 0 <= x <= 2047
   /// 0 <= x <= 2047
   ASSERT(((unsigned)(topLeft->x)) < 2048);
   ASSERT(((unsigned)(topLeft->y)) < 2048);

   /// Set offset at rotation
   ///SET_G2D_LAYER_OFFSET(1, 0, 0);

   /// Pitch
   pitch = (srcCanvas->width) * (srcCanvas->bytesPerPixel);
   ASSERT(((unsigned)pitch) <= 0x2000);
   SET_G2D_LAYER_PITCH(1, pitch);

   /// setting the source canvas info. and source lt rectangle
   switch(srcCanvas->colorFormat)
   {
      case G2D_COLOR_FORMAT_GRAY:
      case G2D_COLOR_FORMAT_RGB565:
      case G2D_COLOR_FORMAT_ARGB8888:
      case G2D_COLOR_FORMAT_RGB888:
      case G2D_COLOR_FORMAT_BGR888:
      case G2D_COLOR_FORMAT_PARGB8888:
      case G2D_COLOR_FORMAT_ARGB8565:
      case G2D_COLOR_FORMAT_PARGB8565:
      case G2D_COLOR_FORMAT_ARGB6666:
      case G2D_COLOR_FORMAT_PARGB6666:
         ASSERT(srcCanvas->RGBBufferAddr);
         addr = srcCanvas->RGBBufferAddr + ((topLeft->y) * (srcCanvas->width) + (topLeft->x)) * (srcCanvas->bytesPerPixel);
         SET_G2D_LAYER_ADDR(1, (kal_uint32)addr);
      break;
      case G2D_COLOR_FORMAT_UYVY422:
         ASSERT(srcCanvas->YUVBufferAddr[0]);
         addr = srcCanvas->YUVBufferAddr[0] + ((topLeft->y) * (srcCanvas->width) + (topLeft->x)) * (srcCanvas->bytesPerPixel);
         SET_G2D_LAYER_ADDR(1, (kal_uint32)addr);
      break;
      default:
         ASSERT(0);
      break;
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
      case G2D_COLOR_FORMAT_GRAY:
         SET_G2D_LAYER_CON_COLOR_FORMAT(1, G2D_LX_CON_COLOR_GRAY);
      break;
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

   if(KAL_TRUE == (bitbltFunc->srcAlphaEnable))
   {
      ENABLE_G2D_LAYER_CON_ALPHA(1);
      SET_G2D_LAYER_CON_ALPHA(1, bitbltFunc->srcAlphaValue);
   }

   ENABLE_G2D_ROI_LAYER(1);
}



static void _g2d_drv_bitblt_set_dst_info(G2D_HANDLE_STRUCT *handle)
{
   G2D_BITBLT_STRUCT *bitbltFunc = &(handle->bitbltFunc);
   G2D_CANVAS_INFO_STRUCT *dstCanvas  = &(handle->dstCanvas);
   ///G2D_WINDOW_STRUCT *targetClipWindow = &handle->targetClipWindow;
   G2D_WINDOW_STRUCT *dstWindow  = &(bitbltFunc->dstWindow);
   G2D_COORDINATE_STRUCT *dstWindowTopLeft     = &(dstWindow->topLeft);
   G2D_COORDINATE_STRUCT *dstWindowButtomRight = &(dstWindow->buttomRight);
   ///G2D_COORDINATE_STRUCT *targetClipWindowTopLeft     = &(targetClipWindow->topLeft);
   ///G2D_COORDINATE_STRUCT *targetClipWindowButtomRight = &(targetClipWindow->buttomRight);
   kal_uint32 width, height, pitch;

   #if !defined(G2D_FPGA)
      /// -2048 <= x <= 2047
      ASSERT(((unsigned)((dstWindowTopLeft->x) + 2048)) < 4096);
      ASSERT(((unsigned)((dstWindowTopLeft->y) + 2048)) < 4096);
   #endif

   SET_G2D_W2M_OFFSET(dstWindowTopLeft->x, dstWindowTopLeft->y);
   SET_G2D_ROI_OFFSET(dstWindowTopLeft->x, dstWindowTopLeft->y);
   /// Pitch
   pitch = (dstCanvas->width) * (dstCanvas->bytesPerPixel);
   ASSERT(((unsigned)pitch) <= 0x2000);
   SET_G2D_W2M_PITCH(pitch);

   /// setting the source canvas info. and source lt rectangle
   ASSERT(dstCanvas->RGBBufferAddr);
   SET_G2D_W2M_ADDR((kal_int32)dstCanvas->RGBBufferAddr);

   width = dstWindowButtomRight->x - dstWindowTopLeft->x + 1;
   height = dstWindowButtomRight->y - dstWindowTopLeft->y + 1;
   /// 1 <= x <= 2048
   ASSERT(((unsigned)(width - 1)) < 2048);
   ASSERT(((unsigned)(height - 1)) < 2048);
   SET_G2D_ROI_SIZE(width, height);

   /// setting destination color format bits
   switch(dstCanvas->colorFormat)
   {
      case G2D_COLOR_FORMAT_GRAY:
         SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_GRAY);
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_GRAY);
      break;
      case G2D_COLOR_FORMAT_RGB565 :
         SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_RGB565);
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_RGB565);
      break;
      case G2D_COLOR_FORMAT_ARGB8888 :
         SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_ARGB8888);
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_ARGB8888);
      break;
      case G2D_COLOR_FORMAT_RGB888 :
         SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_RGB888);
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_RGB888);
      break;
      case G2D_COLOR_FORMAT_BGR888 :
         SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_BGR888);
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_BGR888);
      break;
      case G2D_COLOR_FORMAT_PARGB8888 :
         SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_PARGB8888);
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_PARGB8888);
      break;
      case G2D_COLOR_FORMAT_ARGB8565 :
         SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_ARGB8565);
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_ARGB8565);
      break;
      case G2D_COLOR_FORMAT_PARGB8565 :
         SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_PARGB8565);
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_PARGB8565);
      break;
      case G2D_COLOR_FORMAT_ARGB6666 :
         SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_ARGB6666);
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_ARGB6666);
      break;
      case G2D_COLOR_FORMAT_PARGB6666 :
         SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_PARGB6666);
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_PARGB6666);
      break;
      default:
         ASSERT(0);
      break;
   }

   /// Always disable bg
   DISABLE_G2D_ROI_CON_BG;

   if(KAL_TRUE == (bitbltFunc->dstAlphaEnable))
   {
      ENABLE_G2D_ROI_CON_ALPHA;
      SET_G2D_ROI_CON_ALPHA(bitbltFunc->dstAlphaValue);
   }
}




static void _g2d_drv_bitblt_set_rotation(G2D_HANDLE_STRUCT *handle)
{
   G2D_BITBLT_STRUCT *bitbltFunc = &(handle->bitbltFunc);
   G2D_CW_ROTATE_ANGLE_ENUM rotation = bitbltFunc->rotation;

   G2D_WINDOW_STRUCT *srcWindow  = &(bitbltFunc->srcWindow);
   G2D_COORDINATE_STRUCT *srcWindowTopLeft     = &(srcWindow->topLeft);
   G2D_COORDINATE_STRUCT *srcWindowButtomRight = &(srcWindow->buttomRight);
   kal_uint32 srcWidth = srcWindowButtomRight->x - srcWindowTopLeft->x + 1;
   kal_uint32 srcHeight = srcWindowButtomRight->y - srcWindowTopLeft->y + 1;
   G2D_WINDOW_STRUCT *dstWindow  = &(bitbltFunc->dstWindow);
   G2D_COORDINATE_STRUCT *dstWindowTopLeft     = &(dstWindow->topLeft);

   kal_int32 topLeftX = dstWindowTopLeft->x, topLeftY = dstWindowTopLeft->y;

   switch(rotation)
   {
      case G2D_CW_ROTATE_ANGLE_000:
      {
         SET_G2D_LAYER_CON_ROTATE(1, G2D_LX_CON_CCW_ROTATE_000);
         SET_G2D_LAYER_OFFSET(1, topLeftX, topLeftY);
      }
      break;
      case G2D_CW_ROTATE_ANGLE_090:
      {
         SET_G2D_LAYER_CON_ROTATE(1, G2D_LX_CON_CCW_ROTATE_270);
         SET_G2D_LAYER_OFFSET(1, topLeftX + srcHeight - 1, topLeftY);
      }
      break;
      case G2D_CW_ROTATE_ANGLE_180:
      {
         SET_G2D_LAYER_CON_ROTATE(1, G2D_LX_CON_CCW_ROTATE_180);
         SET_G2D_LAYER_OFFSET(1, topLeftX + srcWidth - 1, topLeftY + srcHeight - 1);
      }
      break;
      case G2D_CW_ROTATE_ANGLE_270:
      {
         SET_G2D_LAYER_CON_ROTATE(1, G2D_LX_CON_CCW_ROTATE_090);
         SET_G2D_LAYER_OFFSET(1, topLeftX, topLeftY + srcWidth - 1);
      }
      break;
      case G2D_CW_ROTATE_ANGLE_MIRROR_000:
      {
         SET_G2D_LAYER_CON_ROTATE(1, G2D_LX_CON_CCW_ROTATE_MIRROR_000);
         SET_G2D_LAYER_OFFSET(1, topLeftX + srcWidth - 1, topLeftY);
      }
      break;
      case G2D_CW_ROTATE_ANGLE_MIRROR_090:
      {
         SET_G2D_LAYER_CON_ROTATE(1, G2D_LX_CON_CCW_ROTATE_MIRROR_090);
         SET_G2D_LAYER_OFFSET(1, topLeftX, topLeftY);
      }
      break;
      case G2D_CW_ROTATE_ANGLE_MIRROR_180:
      {
         SET_G2D_LAYER_CON_ROTATE(1, G2D_LX_CON_CCW_ROTATE_MIRROR_180);
         SET_G2D_LAYER_OFFSET(1, topLeftX, topLeftY + srcHeight - 1);
      }
      break;
      case G2D_CW_ROTATE_ANGLE_MIRROR_270:
      {
         SET_G2D_LAYER_CON_ROTATE(1, G2D_LX_CON_CCW_ROTATE_MIRROR_270);
         SET_G2D_LAYER_OFFSET(1, topLeftX + srcHeight - 1, topLeftY + srcWidth - 1);
      }
      break;
      default:
         ASSERT(0);
      break;
   }
}



static kal_bool _g2d_drv_bitblt_check_window_range(G2D_HANDLE_STRUCT *handle)
{
   G2D_CANVAS_INFO_STRUCT *srcCanvas = &(handle->bitbltFunc.srcCanvas);
   G2D_CANVAS_INFO_STRUCT *dstCanvas = &(handle->dstCanvas);
   G2D_WINDOW_STRUCT *srcWindow  = &(handle->bitbltFunc.srcWindow);
   G2D_WINDOW_STRUCT *dstWindow  = &(handle->bitbltFunc.dstWindow);
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
      G2D_WINDOW_STRUCT *clip_w = &(handle->clipWindow);
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



static void _g2d_drv_bitblt_set_window_intersection(G2D_HANDLE_STRUCT *handle)
{
   G2D_WINDOW_STRUCT *clipWindow = &(handle->clipWindow);
   G2D_COORDINATE_STRUCT *clipWindowTopLeft     = &(clipWindow->topLeft);
   G2D_COORDINATE_STRUCT *clipWindowButtomRight = &(clipWindow->buttomRight);
   G2D_BITBLT_STRUCT *bitbltFunc = &(handle->bitbltFunc);
   G2D_WINDOW_STRUCT *dstWindow  = &(bitbltFunc->dstWindow);
   G2D_COORDINATE_STRUCT *dstWindowTopLeft     = &(dstWindow->topLeft);
   G2D_COORDINATE_STRUCT *dstWindowButtomRight = &(dstWindow->buttomRight);
   G2D_WINDOW_STRUCT *targetClipWindow = &(handle->targetClipWindow);

   kal_uint32 dstCanvasWidth  = handle->dstCanvas.width;
   kal_uint32 dstCanvasHeight = handle->dstCanvas.height;

   if(KAL_FALSE == handle->clipEnable)
   {
      clipWindowTopLeft->x = dstWindowTopLeft->x;
      clipWindowTopLeft->y = dstWindowTopLeft->y;

      clipWindowButtomRight->x = dstWindowButtomRight->x;
      clipWindowButtomRight->y = dstWindowButtomRight->y;
   }
   else
   {
      clipWindowTopLeft->x = MAX(0, clipWindowTopLeft->x);
      clipWindowTopLeft->y = MAX(0, clipWindowTopLeft->y);

      if((clipWindowButtomRight->x) > ((int)(dstCanvasWidth - 1)))
          clipWindowButtomRight->x = dstCanvasWidth - 1;
      if((clipWindowButtomRight->y) > ((int)(dstCanvasHeight - 1)))
          clipWindowButtomRight->y = dstCanvasHeight - 1;
   }

   targetClipWindow->topLeft.x = clipWindowTopLeft->x;
   targetClipWindow->topLeft.y = clipWindowTopLeft->y;

   targetClipWindow->buttomRight.x = clipWindowButtomRight->x;
   targetClipWindow->buttomRight.y = clipWindowButtomRight->y;
}




#if defined(G2D_HW_C_MODEL_SUPPORT)
   G2D_STATUS_ENUM g2d_drv_c_model_start(G2D_HANDLE_STRUCT *handle);
#endif

G2D_STATUS_ENUM g2d_drv_bitblt_start(G2D_HANDLE_STRUCT *handle)
{
   {
      kal_bool status;

      #if !defined(G2D_FPGA)
         status = _g2d_drv_bitblt_check_window_range(handle);
         if(KAL_FALSE == status)
            return G2D_STATUS_OK;
      #endif

      _g2d_drv_bitblt_set_window_intersection(handle);
   }

   HARD_RESET_G2D_ENGINE;
   REG_G2D_MODE_CTRL = 0;
   REG_G2D_ROI_CON = 0;
   REG_G2D_DI_CON = 0x0;
   CLR_G2D_LAYER_CON(1);

   /// setting the hw hisr callback function
   g2d_drv_set_hw_hisr_callback(&g2d_irq_handler);

   /// setting the bitblt source infomation(src buffer ,src bitblt rectangle)
   _g2d_drv_bitblt_set_src_info(handle);

   /// setting the source color key
   g2d_drv_set_source_color_key(handle, handle->bitbltFunc.srcCanvas.colorFormat);

   /// setting the avoidance and replacement colors
   g2d_drv_set_replacement_colors(handle);

   /// setting the bitblt destination infomation
   _g2d_drv_bitblt_set_dst_info(handle);

   /// setting the clipping window
   g2d_drv_set_clipping_window(handle);

   _g2d_drv_bitblt_set_rotation(handle);

   /// burst mode
   g2d_drv_set_burst_type(handle);

   /// slow down
   g2d_drv_set_slow_down(handle);

   /// check if the callback function is setted, TURE => enable the interrupt configuration,
   ///                                          FALSE => disable the interrupt configuration
   if (KAL_TRUE == handle->callbackEnable)
   {
      REG_G2D_IRQ |= G2D_IRQ_ENABLE_BIT;
   }
   else
   {
      REG_G2D_IRQ &= ~G2D_IRQ_ENABLE_BIT;
   }

   REG_G2D_MODE_CTRL |= G2D_MODE_CON_ENG_MODE_G2D_BITBLT_BIT;
   /// trigger
   REG_G2D_START = G2D_START_BIT;

   #if defined(G2D_HW_C_MODEL_SUPPORT)
      g2d_drv_c_model_start(handle);
   #endif

   return G2D_STATUS_OK;
}



// support
G2D_STATUS_ENUM g2d_drv_bitblt_query_src_alpha_support(void)
{
   return G2D_STATUS_OK;
}



#endif /// __DRV_GRAPHICS_G2D_6236_SERIES__
