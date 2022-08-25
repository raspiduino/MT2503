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
 *   g2d_drv_overlay_6260_series.c
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
#include "g2d_drv_6260_series.h"
#include "g2d_drv_api.h"

#if defined(__MTK_TARGET__) || defined(G2D_FPGA)
#else
   extern kal_uint32 g2d_hw_registers[100];
#endif



static kal_bool _g2d_drv_overlay_check_window_range(G2D_HANDLE_STRUCT *handle)
{
   G2D_OVERLAY_STRUCT *overlayFunc = &(handle->overlayFunc);
   G2D_CANVAS_INFO_STRUCT *dstCanvas = &handle->dstCanvas;
   kal_int32 i;

   for (i = 0; i < G2D_HW_OVERLAY_TOTAL_LAYER; i++)
   {
      G2D_OVERLAY_LAYER_STRUCT *layerInfo = &(overlayFunc->layerInfo[i]);

      if(KAL_TRUE == (layerInfo->layerEnable))
      {
         G2D_CANVAS_INFO_STRUCT *layerCanvas = &(layerInfo->layerCanvas);
         G2D_WINDOW_STRUCT *layerWindow = &(layerInfo->layerWindow);

         /// pitch = 0
        if(0 == (layerCanvas->width))
           return KAL_FALSE;

        /// width =0  height =0
        if((0 > (layerWindow->buttomRight.x - layerWindow->topLeft.x)) || (0 > (layerWindow->buttomRight.y - layerWindow->topLeft.y)))
           return KAL_FALSE;
      }
   }

   /// pitch = 0
   if(0 == (dstCanvas->width))
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



static kal_bool _g2d_drv_overlay_set_window_intersection(G2D_HANDLE_STRUCT *handle)
{
   G2D_WINDOW_STRUCT *clipWindow = &(handle->clipWindow);
   G2D_COORDINATE_STRUCT *clipWindowTopLeft     = &(clipWindow->topLeft);
   G2D_COORDINATE_STRUCT *clipWindowButtomRight = &(clipWindow->buttomRight);

   G2D_WINDOW_STRUCT *targetClipWindow = &(handle->targetClipWindow);

   G2D_WINDOW_STRUCT *roiWindow = &(handle->overlayFunc.roiWindow);
   kal_int32 roiWindow_topLeftX = (roiWindow->topLeft.x);
   kal_int32 roiWindow_topLeftY = (roiWindow->topLeft.y);
   kal_int32 roiWindow_buttomRightX = (roiWindow->buttomRight.x);
   kal_int32 roiWindow_buttomRightY = (roiWindow->buttomRight.y);

   kal_int32 topLeftX, topLeftY, buttomRightX, buttomRightY;
   
   #if !defined(G2D_FPGA)
      if(KAL_FALSE == handle->clipEnable)
      {
         topLeftX = roiWindow_topLeftX;
         topLeftY = roiWindow_topLeftY;

         buttomRightX = roiWindow_buttomRightX;
         buttomRightY = roiWindow_buttomRightY;
      }
      else
      {
         if((clipWindowButtomRight->x) > roiWindow_buttomRightX)
         {	
            buttomRightX = roiWindow_buttomRightX;
         }
         else
         {
            buttomRightX = clipWindowButtomRight->x;
         }
         if((clipWindowButtomRight->y) > roiWindow_buttomRightY)
         {	
            buttomRightY = roiWindow_buttomRightY;
         }
         else
         {
            buttomRightY = clipWindowButtomRight->y;
         }
         
         topLeftX = clipWindowTopLeft->x;
         topLeftY = clipWindowTopLeft->y;   
      }
   #else
      topLeftX = clipWindowTopLeft->x;
      topLeftY = clipWindowTopLeft->y;  
      buttomRightX = clipWindowButtomRight->x; 
      buttomRightY = clipWindowButtomRight->y;
   #endif

   if(buttomRightX < topLeftX)
      return KAL_FALSE;
   if(buttomRightY < topLeftY)
      return KAL_FALSE;

   targetClipWindow->topLeft.x = topLeftX;
   targetClipWindow->topLeft.y = topLeftY;

   targetClipWindow->buttomRight.x = buttomRightX;
   targetClipWindow->buttomRight.y = buttomRightY;

   return KAL_TRUE;
}



static void _g2d_drv_overlay_set_dst_info(G2D_HANDLE_STRUCT *handle)
{
   G2D_CANVAS_INFO_STRUCT *dstCanvas  = &(handle->dstCanvas);
   G2D_COORDINATE_STRUCT *dstCoordiante = &(handle->overlayFunc.dstCoordiante);
   kal_uint32 pitch;

   /// destination base addr
   ASSERT(dstCanvas->RGBBufferAddr);
   SET_G2D_W2M_ADDR((kal_int32)dstCanvas->RGBBufferAddr);

   /// destination pitch
   pitch = (dstCanvas->width) * (dstCanvas->bytesPerPixel);
   ASSERT(((unsigned)pitch) <= 0x2000);
   SET_G2D_W2M_PITCH(pitch);

   /// -2048 <= x <= 2047
   ASSERT(((unsigned)((dstCoordiante->x) + 2048)) < 4096);
   ASSERT(((unsigned)((dstCoordiante->y) + 2048)) < 4096);
   /// destination rectangle start point(x,y)
   SET_G2D_W2M_OFFSET(dstCoordiante->x, dstCoordiante->y);

   /// setting destination color format bits
   switch(dstCanvas->colorFormat)
   {
      case G2D_COLOR_FORMAT_GRAY:
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_GRAY);
      break;
      case G2D_COLOR_FORMAT_RGB565:
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_RGB565);
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
      case G2D_COLOR_FORMAT_PARGB8888:
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_PARGB8888);
      break;
      case G2D_COLOR_FORMAT_ARGB8565:
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_ARGB8565);
      break;
      case G2D_COLOR_FORMAT_PARGB8565:
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_PARGB8565);
      break;
      case G2D_COLOR_FORMAT_ARGB6666:
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_ARGB6666);
      break;
      case G2D_COLOR_FORMAT_PARGB6666:
         SET_G2D_W2M_COLOR_FORMAT(G2D_ROI_CON_W2M_COLOR_PARGB6666);
      break;
      default:
         ASSERT(0);
      break;
   }
}



static void _g2d_drv_overlay_set_layer_info(G2D_HANDLE_STRUCT *handle)
{
   G2D_OVERLAY_STRUCT *overlayFunc = &(handle->overlayFunc);
   kal_int32 layer;

   for (layer = 0; layer < G2D_HW_OVERLAY_TOTAL_LAYER; layer++)
   {
      G2D_OVERLAY_LAYER_STRUCT *layerInfo = &(overlayFunc->layerInfo[layer]);
      G2D_WINDOW_STRUCT *layerWindow = &(layerInfo->layerWindow);
      G2D_CANVAS_INFO_STRUCT *layerCanvas = &(layerInfo->layerCanvas);

      if(KAL_TRUE == (layerInfo->layerEnable))
      {

         kal_uint32 layerWidth  = layerWindow->buttomRight.x - layerWindow->topLeft.x + 1;
         kal_uint32 layerHeight = layerWindow->buttomRight.y - layerWindow->topLeft.y + 1;
         kal_uint32 layerPitch = 0;

         CLR_G2D_LAYER_CON(layer);
         switch(layerInfo->function)
         {
            case G2D_OVERLAY_LAYER_FUNCTION_BUFFER:
            {
               layerPitch = (layerCanvas->width) * (layerCanvas->bytesPerPixel);

               if(KAL_TRUE == (layerInfo->srcKeyEnable))
               {
                  ENABLE_G2D_LAYER_CON_SRC_KEY(layer);
                  SET_G2D_LAYER_SRC_KEY(layer, layerInfo->srcKeyValue);
               }
               if(KAL_TRUE == (layerInfo->layerAlphaEnable))
               {
                  ENABLE_G2D_LAYER_CON_ALPHA(layer);
                  SET_G2D_LAYER_CON_ALPHA(layer, layerInfo->layerAlphaValue);
               }
               {
                  switch(layerCanvas->colorFormat)
                  {
                     case G2D_COLOR_FORMAT_GRAY:
                        SET_G2D_LAYER_CON_COLOR_FORMAT(layer, G2D_LX_CON_COLOR_GRAY);
                     break;
                     case G2D_COLOR_FORMAT_RGB565:
                        SET_G2D_LAYER_CON_COLOR_FORMAT(layer, G2D_LX_CON_COLOR_RGB565);
                     break;
                     case G2D_COLOR_FORMAT_ARGB8888:
                        SET_G2D_LAYER_CON_COLOR_FORMAT(layer, G2D_LX_CON_COLOR_ARGB8888);
                     break;
                     case G2D_COLOR_FORMAT_RGB888:
                        SET_G2D_LAYER_CON_COLOR_FORMAT(layer, G2D_LX_CON_COLOR_RGB888);
                     break;
                     case G2D_COLOR_FORMAT_BGR888:
                        SET_G2D_LAYER_CON_COLOR_FORMAT(layer, G2D_LX_CON_COLOR_BGR888);
                     break;
                     case G2D_COLOR_FORMAT_PARGB8888:
                        SET_G2D_LAYER_CON_COLOR_FORMAT(layer, G2D_LX_CON_COLOR_PARGB8888);
                     break;
                     case G2D_COLOR_FORMAT_UYVY422:
                        SET_G2D_LAYER_CON_COLOR_FORMAT(layer, G2D_LX_CON_COLOR_UYVY);
                     break;
                     case G2D_COLOR_FORMAT_ARGB8565:
                        SET_G2D_LAYER_CON_COLOR_FORMAT(layer, G2D_LX_CON_COLOR_ARGB8565);
                     break;
                     case G2D_COLOR_FORMAT_PARGB8565:
                        SET_G2D_LAYER_CON_COLOR_FORMAT(layer, G2D_LX_CON_COLOR_PARGB8565);
                     break;
                     case G2D_COLOR_FORMAT_ARGB6666:
                        SET_G2D_LAYER_CON_COLOR_FORMAT(layer, G2D_LX_CON_COLOR_ARGB6666);
                     break;
                     case G2D_COLOR_FORMAT_PARGB6666:
                        SET_G2D_LAYER_CON_COLOR_FORMAT(layer, G2D_LX_CON_COLOR_PARGB6666);
                     break;
                     default:
                        ASSERT(0);
                     break;
                  }
               }
            }
            break;
            case G2D_OVERLAY_LAYER_FUNCTION_RECT:
            {
               layerPitch = (layerCanvas->width) * (layerCanvas->bytesPerPixel);

               ENABLE_G2D_LAYER_CON_RECT_FILL(layer);
               if(KAL_TRUE == (layerInfo->srcKeyEnable))
               {
                  ASSERT(0);
               }
               if(KAL_TRUE == (layerInfo->layerAlphaEnable))
               {
                  ENABLE_G2D_LAYER_CON_ALPHA(layer);
                  SET_G2D_LAYER_CON_ALPHA(layer, layerInfo->layerAlphaValue);
               }
               {
                  switch(layerCanvas->colorFormat)
                  {
                     case G2D_COLOR_FORMAT_GRAY:
                        SET_G2D_LAYER_CON_COLOR_FORMAT(layer, G2D_LX_CON_COLOR_GRAY);
                     break;
                     case G2D_COLOR_FORMAT_RGB565:
                        SET_G2D_LAYER_CON_COLOR_FORMAT(layer, G2D_LX_CON_COLOR_RGB565);
                     break;
                     case G2D_COLOR_FORMAT_ARGB8888:
                        SET_G2D_LAYER_CON_COLOR_FORMAT(layer, G2D_LX_CON_COLOR_ARGB8888);
                     break;
                     case G2D_COLOR_FORMAT_RGB888:
                        SET_G2D_LAYER_CON_COLOR_FORMAT(layer, G2D_LX_CON_COLOR_RGB888);
                     break;
                     case G2D_COLOR_FORMAT_BGR888:
                        SET_G2D_LAYER_CON_COLOR_FORMAT(layer, G2D_LX_CON_COLOR_BGR888);
                     break;
                     case G2D_COLOR_FORMAT_PARGB8888:
                        SET_G2D_LAYER_CON_COLOR_FORMAT(layer, G2D_LX_CON_COLOR_PARGB8888);
                     break;
                     case G2D_COLOR_FORMAT_UYVY422:
                        SET_G2D_LAYER_CON_COLOR_FORMAT(layer, G2D_LX_CON_COLOR_UYVY);
                     break;
                     case G2D_COLOR_FORMAT_ARGB8565:
                        SET_G2D_LAYER_CON_COLOR_FORMAT(layer, G2D_LX_CON_COLOR_ARGB8565);
                     break;
                     case G2D_COLOR_FORMAT_PARGB8565:
                        SET_G2D_LAYER_CON_COLOR_FORMAT(layer, G2D_LX_CON_COLOR_PARGB8565);
                     break;
                     case G2D_COLOR_FORMAT_ARGB6666:
                        SET_G2D_LAYER_CON_COLOR_FORMAT(layer, G2D_LX_CON_COLOR_ARGB6666);
                     break;
                     case G2D_COLOR_FORMAT_PARGB6666:
                        SET_G2D_LAYER_CON_COLOR_FORMAT(layer, G2D_LX_CON_COLOR_PARGB6666);
                     break;
                     default:
                        ASSERT(0);
                     break;
                  }
               }
               /// Set color;
               SET_G2D_LAYER_RECTANGLE_FILL_COLOR(layer, (kal_uint32)layerInfo->rectFillColor);
            }
            break;
            case G2D_OVERLAY_LAYER_FUNCTION_NORMAL_FONT:
            {
               layerPitch = layerCanvas->width;

               ENABLE_G2D_LAYER_CON_FONT(layer);
               if((KAL_TRUE == (layerInfo->srcKeyEnable)) || (KAL_TRUE == (layerInfo->layerAlphaEnable)))
               {
                  ASSERT(0);
               }
               ASSERT(G2D_CW_ROTATE_ANGLE_000 == (layerInfo->rotation));

               SET_G2D_LAYER_CON_COLOR_FORMAT(layer, G2D_LX_CON_COLOR_ARGB8888);
               layerCanvas->colorFormat = G2D_COLOR_FORMAT_ARGB8888;
               SET_G2D_LAYER_FONT_FOREGROUND_COLOR(layer, layerInfo->foregroundColor);
            }
            break;
            case G2D_OVERLAY_LAYER_FUNCTION_AA_FONT:
            {
               layerPitch = layerCanvas->width;

               ENABLE_G2D_LAYER_CON_FONT(layer);
               SET_G2D_LAYER_CON_AA_FONT_BIT(layer, (layerInfo->fontBit) << 28);

               if((KAL_TRUE == (layerInfo->srcKeyEnable)) || (KAL_FALSE == (layerInfo->layerAlphaEnable)))
               {
                  ASSERT(0);
               }
               ENABLE_G2D_LAYER_CON_ALPHA(layer);
               SET_G2D_LAYER_CON_ALPHA(layer, 0xFF);

               ASSERT(G2D_CW_ROTATE_ANGLE_000 == (layerInfo->rotation));
               layerCanvas->colorFormat = G2D_COLOR_FORMAT_ARGB8888;
               SET_G2D_LAYER_CON_COLOR_FORMAT(layer, G2D_LX_CON_COLOR_ARGB8888);
               SET_G2D_LAYER_FONT_FOREGROUND_COLOR(layer, layerInfo->foregroundColor);
            }
            break;
            default:
              ASSERT(0);
         }
         /// rotation
         {
            switch(layerInfo->rotation)
            {
               case G2D_CW_ROTATE_ANGLE_000:
               {
                  SET_G2D_LAYER_CON_ROTATE(layer, G2D_LX_CON_CCW_ROTATE_000);
                  SET_G2D_LAYER_OFFSET(layer, layerWindow->topLeft.x, layerWindow->topLeft.y);
               }
               break;
               case G2D_CW_ROTATE_ANGLE_090:
               {
                  SET_G2D_LAYER_CON_ROTATE(layer, G2D_LX_CON_CCW_ROTATE_090);
                  SET_G2D_LAYER_OFFSET(layer, layerWindow->topLeft.x, layerWindow->topLeft.y + layerWidth - 1);
               }
               break;
               case G2D_CW_ROTATE_ANGLE_180:
               {
                  SET_G2D_LAYER_CON_ROTATE(layer, G2D_LX_CON_CCW_ROTATE_180);
                  SET_G2D_LAYER_OFFSET(layer, layerWindow->topLeft.x + layerWidth - 1, layerWindow->topLeft.y + layerHeight - 1);
               }
               break;
               case G2D_CW_ROTATE_ANGLE_270:
               {
                  SET_G2D_LAYER_CON_ROTATE(layer, G2D_LX_CON_CCW_ROTATE_270);
                  SET_G2D_LAYER_OFFSET(layer, layerWindow->topLeft.x + layerHeight - 1, layerWindow->topLeft.y);

               }
               break;
               case G2D_CW_ROTATE_ANGLE_MIRROR_000:
               {
                  SET_G2D_LAYER_CON_ROTATE(layer, G2D_LX_CON_CCW_ROTATE_MIRROR_000);
                  SET_G2D_LAYER_OFFSET(layer, layerWindow->topLeft.x + layerWidth - 1, layerWindow->topLeft.y);
               }
               break;
               case G2D_CW_ROTATE_ANGLE_MIRROR_090:
               {
                  SET_G2D_LAYER_CON_ROTATE(layer, G2D_LX_CON_CCW_ROTATE_MIRROR_090);
                  SET_G2D_LAYER_OFFSET(layer, layerWindow->topLeft.x, layerWindow->topLeft.y);
               }
               break;
               case G2D_CW_ROTATE_ANGLE_MIRROR_180:
               {
                  SET_G2D_LAYER_CON_ROTATE(layer, G2D_LX_CON_CCW_ROTATE_MIRROR_180);
                  SET_G2D_LAYER_OFFSET(layer, layerWindow->topLeft.x, layerWindow->topLeft.y + layerHeight - 1);
               }
               break;
               case G2D_CW_ROTATE_ANGLE_MIRROR_270:
               {
                  SET_G2D_LAYER_CON_ROTATE(layer, G2D_LX_CON_CCW_ROTATE_MIRROR_270);
                  SET_G2D_LAYER_OFFSET(layer, layerWindow->topLeft.x + layerHeight - 1, layerWindow->topLeft.y + layerWidth - 1);
               }
               break;
               default:
                  ASSERT(0);
               break;
            }
         }

         switch(layerCanvas->colorFormat)
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
               SET_G2D_LAYER_ADDR(layer, (kal_uint32)(layerCanvas->RGBBufferAddr));
            break;
            case G2D_COLOR_FORMAT_UYVY422:
               SET_G2D_LAYER_ADDR(layer, (kal_uint32)(layerCanvas->YUVBufferAddr[0]));
            break;
            default:
               ASSERT(0);
            break;
         }

         ASSERT(((unsigned)layerPitch) <= 0x2000);
         SET_G2D_LAYER_PITCH(layer, layerPitch);

         /// This is set in rotation
         /// SET_G2D_LAYER_OFFSET(layer, layerWindow->topLeft.x, layerWindow->topLeft.y);
         SET_G2D_LAYER_SIZE(layer, layerWidth, layerHeight);
         ENABLE_G2D_ROI_LAYER(layer);
      }
   }
}



static void _g2d_drv_overlay_set_roi_info(G2D_HANDLE_STRUCT *handle)
{
   G2D_OVERLAY_STRUCT *overlayFunc = &(handle->overlayFunc);
   G2D_WINDOW_STRUCT *roiWindow = &(handle->overlayFunc.roiWindow);

   /// setting the avoidance and replacement colors
   g2d_drv_set_replacement_colors(handle);

   /// setting the clipping window
   g2d_drv_set_clipping_window(handle);

   SET_G2D_ROI_OFFSET(roiWindow->topLeft.x, roiWindow->topLeft.y);
   SET_G2D_ROI_SIZE(roiWindow->buttomRight.x - roiWindow->topLeft.x + 1, roiWindow->buttomRight.y - roiWindow->topLeft.y + 1);

   #if defined(G2D_FPGA)
      if(KAL_TRUE == (overlayFunc->backgroundDisable))
      {
         DISABLE_G2D_ROI_CON_BG;
      }
      else
      {
         SET_G2D_ROI_CON_BG_COLOR(overlayFunc->backgroundColor);
      }
   #else
      SET_G2D_ROI_CON_BG_COLOR(overlayFunc->backgroundColor);
   #endif
   
   if(KAL_TRUE == (overlayFunc->dstAlphaEnable))
   {
      ENABLE_G2D_ROI_CON_ALPHA;
      SET_G2D_ROI_CON_ALPHA(overlayFunc->dstAlphaValue);
   }

   /// color setting is on _g2d_drv_overlay_set_dst_info
   //Enable Tile
   {
      #if defined(G2D_FPGA)
         ///if(KAL_FALSE == (handle->auto_tile_size_enable))
         ///{
         ///   REG_G2D_ROI_CON |= G2D_ROI_CON_ENABLE_FORCE_TS_BIT;
         ///   switch(handle->tile_size)
         ///   {
         ///      case G2D_TILE_SIZE_TYPE_8x8:
         ///         REG_G2D_ROI_CON |= G2D_ROI_CON_TILE_SIZE_8x8_BIT;
         ///      break;
         ///      case G2D_TILE_SIZE_TYPE_16x8:
         ///         REG_G2D_ROI_CON |= G2D_ROI_CON_TILE_SIZE_16x8_BIT;
         ///      break;
         ///      default:
         ///         ASSERT(0);
         ///   }
         ///}
      #else
      #endif
   }
}



#if defined(G2D_HW_C_MODEL_SUPPORT)
   G2D_STATUS_ENUM g2d_drv_c_model_start(G2D_HANDLE_STRUCT *handle);
#endif

G2D_STATUS_ENUM g2d_drv_overlay_start(G2D_HANDLE_STRUCT *handle)
{
   {
      kal_bool status;

      #if !defined(G2D_FPGA)
         status = _g2d_drv_overlay_check_window_range(handle);
         if(KAL_FALSE == status)
             return G2D_STATUS_OK;
      #endif

      status = _g2d_drv_overlay_set_window_intersection(handle);
      if(KAL_FALSE == status)
         return G2D_STATUS_OK;
   }

   HARD_RESET_G2D_ENGINE;
   REG_G2D_MODE_CTRL = 0;
   REG_G2D_ROI_CON = 0;

   /// setting the hw hisr callback function
   g2d_drv_set_hw_hisr_callback(&g2d_irq_handler);

   /// setting the lt destination infomation
   _g2d_drv_overlay_set_dst_info(handle);

   _g2d_drv_overlay_set_layer_info(handle);

   _g2d_drv_overlay_set_roi_info(handle);

   /// burst mode
   g2d_drv_set_burst_type(handle);

   /// slow down
   g2d_drv_set_slow_down(handle);
   
   g2d_drv_set_tile(handle);
   
   g2d_drv_set_dithering(handle);
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


#endif
