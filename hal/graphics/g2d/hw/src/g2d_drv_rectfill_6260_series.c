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
 *   g2d_drv_rectfill_6260_series.c
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
      //#define ASSERT(x) assert(x)
      #define ASSERT(x)
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



static void _g2d_drv_rectfill_set_info(G2D_HANDLE_STRUCT *handle)
{
   G2D_RECTANGLE_FILL_STRUCT *rectFillFunc = &(handle->rectFillFunc);
   G2D_CANVAS_INFO_STRUCT *srcCanvas = &(rectFillFunc->srcCanvas);

   G2D_CANVAS_INFO_STRUCT *dstCanvas  = &(handle->dstCanvas);
   #if defined(G2D_FPGA)
      G2D_WINDOW_STRUCT *dstWindow  = &(handle->rectFillFunc.dstWindow);
   #else
      G2D_WINDOW_STRUCT  *dstWindow = &(handle->targetClipWindow);
   #endif
   G2D_COORDINATE_STRUCT *topLeft     = &(dstWindow->topLeft);
   G2D_COORDINATE_STRUCT *buttomRight = &(dstWindow->buttomRight);
   kal_uint32 width, height, pitch, srcpitch;

   /// destination base addr
   ASSERT(dstCanvas->RGBBufferAddr);
   //SET_G2D_LAYER_ADDR(0, (kal_uint32)(dstCanvas->RGBBufferAddr));
   REG_G2D_W2M_ADDR = (kal_int32)dstCanvas->RGBBufferAddr;

   /// destination pitch
   pitch = (dstCanvas->width) * (dstCanvas->bytesPerPixel);
   ASSERT(((unsigned)pitch) <= 0x2000);
   //SET_G2D_LAYER_PITCH(0, pitch);
   SET_G2D_LAYER_PITCH(1, pitch);
   REG_G2D_W2M_PITCH = pitch;

   /// -2048 <= x <= 2047
   ASSERT(((unsigned)((topLeft->x) + 2048)) < 4096);
   ASSERT(((unsigned)((topLeft->y) + 2048)) < 4096);
   /// destination rectangle start point(x,y)
   SET_G2D_W2M_OFFSET(topLeft->x, topLeft->y);
   SET_G2D_ROI_OFFSET(topLeft->x, topLeft->y);
   //SET_G2D_LAYER_OFFSET(0, 0, 0);
   SET_G2D_LAYER_OFFSET(1, topLeft->x, topLeft->y);

   width = buttomRight->x - topLeft->x + 1;
   height = buttomRight->y - topLeft->y + 1;

   /// 1 <= x <= 2048
   ASSERT(((unsigned)(width - 1)) <= 2048);
   ASSERT(((unsigned)(height - 1)) <= 2048);
   /// destination rectangle width and height
   REG_G2D_ROI_SIZE = (width << 16) | height;
   //SET_G2D_LAYER_SIZE(0, dstCanvas->width, dstCanvas->height);
   SET_G2D_LAYER_SIZE(1, width, height);

   if (KAL_TRUE == rectFillFunc->overlayBufferEnable)
   {
      srcpitch = (srcCanvas->width) * (srcCanvas->bytesPerPixel);
      ASSERT(((unsigned)srcpitch) <= 0x2000);
      SET_G2D_LAYER_PITCH(1, srcpitch);
      SET_G2D_LAYER_ADDR(0, (kal_uint32)(srcCanvas->RGBBufferAddr));
      SET_G2D_LAYER_OFFSET(0, 0, 0);
      SET_G2D_LAYER_SIZE(0, srcCanvas->width, srcCanvas->height);
      /// set src_clr_fmt bits
      switch(srcCanvas->colorFormat)
      {
         case G2D_COLOR_FORMAT_GRAY:
            SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_GRAY);
            SET_G2D_LAYER_CON_COLOR_FORMAT(1, G2D_LX_CON_COLOR_GRAY);
         break;
         case G2D_COLOR_FORMAT_RGB565:
            SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_RGB565);
            SET_G2D_LAYER_CON_COLOR_FORMAT(1, G2D_LX_CON_COLOR_RGB565);
         break;
         case G2D_COLOR_FORMAT_ARGB8888:
            SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_ARGB8888);
            SET_G2D_LAYER_CON_COLOR_FORMAT(1, G2D_LX_CON_COLOR_ARGB8888);
         break;
         case G2D_COLOR_FORMAT_RGB888:
            SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_RGB888);
            SET_G2D_LAYER_CON_COLOR_FORMAT(1, G2D_LX_CON_COLOR_RGB888);
         break;
         case G2D_COLOR_FORMAT_BGR888:
            SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_BGR888);
            SET_G2D_LAYER_CON_COLOR_FORMAT(1, G2D_LX_CON_COLOR_BGR888);
         break;
         case G2D_COLOR_FORMAT_PARGB8888:
            SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_PARGB8888);
            SET_G2D_LAYER_CON_COLOR_FORMAT(1, G2D_LX_CON_COLOR_PARGB8888);
         break;
         case G2D_COLOR_FORMAT_UYVY422:
            SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_UYVY);
            SET_G2D_LAYER_CON_COLOR_FORMAT(1, G2D_LX_CON_COLOR_UYVY);
         break;
         case G2D_COLOR_FORMAT_ARGB8565:
            SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_ARGB8565);
            SET_G2D_LAYER_CON_COLOR_FORMAT(1, G2D_LX_CON_COLOR_ARGB8565);
         break;
         case G2D_COLOR_FORMAT_PARGB8565:
            SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_PARGB8565);
            SET_G2D_LAYER_CON_COLOR_FORMAT(1, G2D_LX_CON_COLOR_PARGB8565);
         break;
         case G2D_COLOR_FORMAT_ARGB6666:
            SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_ARGB6666);
            SET_G2D_LAYER_CON_COLOR_FORMAT(1, G2D_LX_CON_COLOR_ARGB6666);
         break;
         case G2D_COLOR_FORMAT_PARGB6666:
            SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_PARGB6666);
            SET_G2D_LAYER_CON_COLOR_FORMAT(1, G2D_LX_CON_COLOR_PARGB6666);
         break;
         default:
            ASSERT(0);
         break;
      }

   }
   else
   {
     SET_G2D_LAYER_ADDR(0, (kal_uint32)(dstCanvas->RGBBufferAddr));
     SET_G2D_LAYER_PITCH(0, pitch);
     SET_G2D_LAYER_OFFSET(0, 0, 0);
     SET_G2D_LAYER_SIZE(0, dstCanvas->width, dstCanvas->height);

     /// setting destination color format bits
     switch(dstCanvas->colorFormat)
     {
        case G2D_COLOR_FORMAT_RGB565:
           SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_RGB565);
           SET_G2D_LAYER_CON_COLOR_FORMAT(1, G2D_LX_CON_COLOR_RGB565);
        break;
        case G2D_COLOR_FORMAT_ARGB6666:
           SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_ARGB6666);
           SET_G2D_LAYER_CON_COLOR_FORMAT(1, G2D_LX_CON_COLOR_ARGB6666);
        break;
        case G2D_COLOR_FORMAT_ARGB8888:
           SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_ARGB8888);
           SET_G2D_LAYER_CON_COLOR_FORMAT(1, G2D_LX_CON_COLOR_ARGB8888);
        break;
        case G2D_COLOR_FORMAT_RGB888:
           SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_RGB888);
           SET_G2D_LAYER_CON_COLOR_FORMAT(1, G2D_LX_CON_COLOR_RGB888);
        break;
        case G2D_COLOR_FORMAT_BGR888:
           SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_BGR888);
           SET_G2D_LAYER_CON_COLOR_FORMAT(1, G2D_LX_CON_COLOR_BGR888);
        break;
        case G2D_COLOR_FORMAT_PARGB6666:
           SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_PARGB6666);
           SET_G2D_LAYER_CON_COLOR_FORMAT(1, G2D_LX_CON_COLOR_PARGB6666);
        break;
        case G2D_COLOR_FORMAT_PARGB8888:
           SET_G2D_LAYER_CON_COLOR_FORMAT(0, G2D_LX_CON_COLOR_PARGB8888);
           SET_G2D_LAYER_CON_COLOR_FORMAT(1, G2D_LX_CON_COLOR_PARGB8888);
        break;
        default:
           ASSERT(0);
        break;
     }

   }

   /// setting destination color format bits
   switch(dstCanvas->colorFormat)
   {
      case G2D_COLOR_FORMAT_RGB565:
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_RGB565);
      break;
      case G2D_COLOR_FORMAT_ARGB6666:
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_ARGB6666);
      break;
      case G2D_COLOR_FORMAT_ARGB8888:
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_ARGB8888);
      break;
      case G2D_COLOR_FORMAT_RGB888:
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_RGB888);
      break;
      case G2D_COLOR_FORMAT_BGR888:
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_BGR888);
      break;
      case G2D_COLOR_FORMAT_PARGB6666:
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_PARGB6666);
      break;
      case G2D_COLOR_FORMAT_PARGB8888:
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_PARGB8888);
      break;
      default:
         ASSERT(0);
      break;
   }

   if(KAL_TRUE == (rectFillFunc->srcAlphaEnable))
   {
      ENABLE_G2D_LAYER_CON_ALPHA(1);
      SET_G2D_LAYER_CON_ALPHA(1, rectFillFunc->srcAlphaValue);
      //ENABLE_G2D_ROI_LAYER(0);
      ENABLE_G2D_ROI_LAYER_0;
   }

   /// Set color;
   SET_G2D_LAYER_RECTANGLE_FILL_COLOR(1, (kal_uint32)rectFillFunc->rectFillColor);
   ENABLE_G2D_ROI_LAYER(1);
}



static kal_bool _g2d_drv_rectfill_check_window_range(G2D_HANDLE_STRUCT *handle)
{
   G2D_CANVAS_INFO_STRUCT *dstCanvas  = &(handle->dstCanvas);
   G2D_WINDOW_STRUCT  *dstWindow = &(handle->rectFillFunc.dstWindow);
   G2D_COORDINATE_STRUCT *dstTopLeft = &(dstWindow->topLeft);
   G2D_COORDINATE_STRUCT *dstButtomRight = &(dstWindow->buttomRight);

   /// pitch = 0
   if(0 == (dstCanvas->width))
     return KAL_FALSE;
   /// width = 0  height = 0
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



static kal_bool _g2d_drv_rectfill_set_window_intersection(G2D_HANDLE_STRUCT *handle)
{
   G2D_WINDOW_STRUCT *clipWindow = &(handle->clipWindow);
   G2D_COORDINATE_STRUCT *clipWindowTopLeft     = &(clipWindow->topLeft);
   G2D_COORDINATE_STRUCT *clipWindowButtomRight = &(clipWindow->buttomRight);
   G2D_WINDOW_STRUCT *dstWindow  = &(handle->rectFillFunc.dstWindow);
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

      clipWindowTopLeft->x = MAX(dstWindowTopLeft->x, clipWindowTopLeft->x);
      clipWindowTopLeft->y = MAX(dstWindowTopLeft->y, clipWindowTopLeft->y);
      
      clipWindowButtomRight->x = MIN(dstWindowButtomRight->x, clipWindowButtomRight->x);
      clipWindowButtomRight->y = MIN(dstWindowButtomRight->y, clipWindowButtomRight->y);

      if((clipWindowButtomRight->x) > ((int)(dstCanvasWidth - 1)))
          clipWindowButtomRight->x = dstCanvasWidth - 1;
      if((clipWindowButtomRight->y) > ((int)(dstCanvasHeight - 1)))
          clipWindowButtomRight->y = dstCanvasHeight - 1;
   }

   /// width =0  height =0
   if((0 > (clipWindowButtomRight->x - clipWindowTopLeft->x)) || (0 > (clipWindowButtomRight->y - clipWindowTopLeft->y)))
     return KAL_FALSE;
        
   targetClipWindow->topLeft.x = clipWindowTopLeft->x;
   targetClipWindow->topLeft.y = clipWindowTopLeft->y;

   targetClipWindow->buttomRight.x = clipWindowButtomRight->x;
   targetClipWindow->buttomRight.y = clipWindowButtomRight->y;

   return KAL_TRUE;
}



#if defined(G2D_HW_C_MODEL_SUPPORT)
   G2D_STATUS_ENUM g2d_drv_c_model_start(G2D_HANDLE_STRUCT *handle);
#endif

G2D_STATUS_ENUM g2d_drv_rectfill_start(G2D_HANDLE_STRUCT *handle)
{
   {
      kal_bool status;

      status = _g2d_drv_rectfill_check_window_range(handle);
      if(KAL_FALSE == status)
         return G2D_STATUS_RANGE_CHECK_FAIL;

      status = _g2d_drv_rectfill_set_window_intersection(handle);
      if(KAL_FALSE == status)
         return G2D_STATUS_RANGE_CHECK_FAIL;
   }

   HARD_RESET_G2D_ENGINE;
   REG_G2D_MODE_CTRL = 0;
   REG_G2D_ROI_CON = 0;
   REG_G2D_DI_CON = 0x0;
   CLR_G2D_LAYER_CON(0);
   CLR_G2D_LAYER_CON(1);
   ENABLE_G2D_LAYER_CON_RECT_FILL(1);

   /// setting the hw hisr callback function
   g2d_drv_set_hw_hisr_callback(&g2d_irq_handler);

   /// setting the avoidance and replacement colors
   g2d_drv_set_replacement_colors(handle);

   /// setting the clipping window
   g2d_drv_set_clipping_window(handle);

   /// setting the bitblt destination infomation
   _g2d_drv_rectfill_set_info(handle);
   
   g2d_drv_set_dithering(handle);
   
   /// disable bg
   REG_G2D_ROI_CON |= G2D_ROI_CON_DISABLE_BG_BIT;

   /// burst mode
   g2d_drv_set_burst_type(handle);

   /// slow down
   g2d_drv_set_slow_down(handle);

   if (KAL_TRUE == handle->callbackEnable)
   {
      REG_G2D_IRQ |= G2D_IRQ_ENABLE_BIT;
   }
   else
   {
      REG_G2D_IRQ &= ~G2D_IRQ_ENABLE_BIT;
   }

   REG_G2D_MODE_CTRL |= G2D_MODE_CON_ENG_MODE_G2D_BITBLT_BIT;
   /// trigger the rectangle fill
   REG_G2D_START = G2D_START_BIT;

   #if defined(G2D_HW_C_MODEL_SUPPORT)
      g2d_drv_c_model_start(handle);
   #endif

   return G2D_STATUS_OK;
}

#endif /// __DRV_GRAPHICS_G2D_6236_SERIES__

