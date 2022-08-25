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
 *   g2d_overlay_api.c
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
#include "kal_general_types.h"

#include "drv_features_g2d.h"
#include "g2d_enum.h"
#include "g2d_structure.h"

#if defined (G2D_HW_OVERLAY_SUPPORT)

#if defined(G2D_CODEC_STANDALONE)
   #include "stdio.h"
   #include "stdlib.h"

   #include "assert.h"
   #ifndef ASSERT
      #define ASSERT(x) assert(x)
   #endif
#elif defined(G2D_FPGA)
   #include "assert.h"
   #ifndef ASSERT
      extern void ASSERT(int const expr);
   #endif
#else
   #include "kal_public_api.h"
   #include "kal_public_defs.h"
   #include "cache_sw.h"

   #if defined(__MTK_TARGET__)
      extern kal_mutexid g2d_state_mutex;
      extern kal_bool INT_QueryExceptionStatus(void);

   #endif
#endif

#include "g2d_drv_api.h"



G2D_STATUS_ENUM g2dOverlayEnableLayer(G2D_HANDLE_STRUCT *handle,
                                      G2D_OVERLAY_LAYER_ENUM layer, kal_bool layerEnable)
{
   G2D_OVERLAY_LAYER_STRUCT *layerInfo = &(handle->overlayFunc.layerInfo[layer]);

   layerInfo->layerEnable = layerEnable;

   return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2dOverlaySetLayerFunction(G2D_HANDLE_STRUCT *handle,
                                           G2D_OVERLAY_LAYER_ENUM layer, G2D_OVERLAY_LAYER_FUNCTION_ENUM function)
{
   G2D_OVERLAY_LAYER_STRUCT *layerInfo = &(handle->overlayFunc.layerInfo[layer]);

   layerInfo->function = function;

   return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2dOverlaySetLayerFontBit(G2D_HANDLE_STRUCT *handle,
                                          G2D_OVERLAY_LAYER_ENUM layer, G2D_FONT_BIT_ENUM fontBit)
{
   G2D_OVERLAY_LAYER_STRUCT *layerInfo = &(handle->overlayFunc.layerInfo[layer]);

   layerInfo->fontBit = fontBit;

   return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2dOverlaySetLayerFontFgColor(G2D_HANDLE_STRUCT *handle,
                                              G2D_OVERLAY_LAYER_ENUM layer, kal_uint32 foregroundColor)
{
   G2D_OVERLAY_LAYER_STRUCT *layerInfo = &(handle->overlayFunc.layerInfo[layer]);

   layerInfo->foregroundColor = foregroundColor;

   return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2dOverlaySetLayerRectFillColor(G2D_HANDLE_STRUCT *handle,
                                                G2D_OVERLAY_LAYER_ENUM layer, kal_uint32 rectFillColor)
{
   G2D_OVERLAY_LAYER_STRUCT *layerInfo = &(handle->overlayFunc.layerInfo[layer]);

   layerInfo->rectFillColor = rectFillColor;

   return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2dOverlaySetLayerBufferInfo(G2D_HANDLE_STRUCT *handle, G2D_OVERLAY_LAYER_ENUM layer,
                                             kal_uint8 *bufferAddr, kal_uint32 bufferSize)
{
   G2D_OVERLAY_LAYER_STRUCT *layerInfo = &(handle->overlayFunc.layerInfo[layer]);
   G2D_CANVAS_INFO_STRUCT *layerCanvas = &(layerInfo->layerCanvas);
   G2D_STATUS_ENUM status = G2D_STATUS_OK;

   layerCanvas->RGBBufferAddr = bufferAddr;
   layerCanvas->RGBBufferSize = bufferSize;
   layerCanvas->colorFormat = G2D_COLOR_FORMAT_ARGB8888;

   ///if(G2D_CODEC_TYPE_HW == (handle->type))
   ///{
   ///   #if defined(__MTK_TARGET__)
   ///   {
   ///      if(0 != bufferSize)
   ///      {
   ///         ASSERT(INT_QueryIsNonCachedRAM((kal_uint32)bufferAddr, bufferSize));
   ///      }
   ///   }
   ///   #endif
   ///}

   return status;
}



G2D_STATUS_ENUM g2dOverlaySetLayerRGBBufferInfo(G2D_HANDLE_STRUCT *handle, G2D_OVERLAY_LAYER_ENUM layer,
                                                kal_uint8 *bufferAddr, kal_uint32 bufferSize,
                                                kal_uint32 width, kal_uint32 height, G2D_COLOR_FORMAT_ENUM colorFormat)
{
   G2D_OVERLAY_LAYER_STRUCT *layerInfo = &(handle->overlayFunc.layerInfo[layer]);
   G2D_CANVAS_INFO_STRUCT *layerCanvas = &(layerInfo->layerCanvas);
   G2D_STATUS_ENUM status = G2D_STATUS_OK;

   layerCanvas->RGBBufferAddr = bufferAddr;
   layerCanvas->RGBBufferSize = bufferSize;
   layerCanvas->width = width;
   layerCanvas->height = height;
   layerCanvas->colorFormat = colorFormat;

   switch (colorFormat)
   {
      case G2D_COLOR_FORMAT_GRAY:
         layerCanvas->bytesPerPixel = 1;
      break;
      case G2D_COLOR_FORMAT_RGB565 :
         layerCanvas->bytesPerPixel = 2;
      break;
      case G2D_COLOR_FORMAT_RGB888:
      case G2D_COLOR_FORMAT_BGR888:
      case G2D_COLOR_FORMAT_ARGB8565:
      case G2D_COLOR_FORMAT_PARGB8565:
      case G2D_COLOR_FORMAT_ARGB6666:
      case G2D_COLOR_FORMAT_PARGB6666:
         layerCanvas->bytesPerPixel = 3;
      break;
      case G2D_COLOR_FORMAT_ARGB8888:
      case G2D_COLOR_FORMAT_PARGB8888:
         layerCanvas->bytesPerPixel = 4;
      break;
      default:
         ASSERT(0);
      break;
   }

   if(G2D_CODEC_TYPE_HW == (handle->type))
   {
      status = g2d_drv_check_src_canvas_info(width);

      ///#if defined(__MTK_TARGET__)
      ///{
      ///   if(0 != bufferSize)
      ///   {
      ///      ASSERT(INT_QueryIsNonCachedRAM((kal_uint32)bufferAddr, bufferSize));
      ///   }
      ///}
      ///#endif
   }

   return status;
}



G2D_STATUS_ENUM g2dOverlaySetLayerYUVBufferInfo(G2D_HANDLE_STRUCT *handle, G2D_OVERLAY_LAYER_ENUM layer,
                                                kal_uint8 *bufferAddr[3], kal_uint32 bufferSize[3],
                                                kal_uint32 width, kal_uint32 height, G2D_COLOR_FORMAT_ENUM colorFormat)
{
   G2D_OVERLAY_LAYER_STRUCT *layerInfo = &(handle->overlayFunc.layerInfo[layer]);
   G2D_CANVAS_INFO_STRUCT *layerCanvas = &(layerInfo->layerCanvas);
   G2D_STATUS_ENUM status = G2D_STATUS_OK;

   layerCanvas->YUVBufferAddr[0] = bufferAddr[0];
   layerCanvas->YUVBufferAddr[1] = bufferAddr[1];
   layerCanvas->YUVBufferAddr[2] = bufferAddr[2];
   layerCanvas->YUVBufferSize[0] = bufferSize[0];
   layerCanvas->YUVBufferSize[1] = bufferSize[1];
   layerCanvas->YUVBufferSize[2] = bufferSize[2];
   layerCanvas->width  = width;
   layerCanvas->height       = height;
   layerCanvas->colorFormat = colorFormat;


   switch (colorFormat)
   {
      case G2D_COLOR_FORMAT_UYVY422:
         layerCanvas->bytesPerPixel = 2;
      break;
      default:
         ASSERT(0);
      break;
   }

   if(G2D_CODEC_TYPE_HW == (handle->type))
   {
      status = g2d_drv_check_src_canvas_info(width);

      ///#if defined(__MTK_TARGET__)
      ///{
      ///   if(0 != bufferSize)
      ///   {
      ///      ASSERT(INT_QueryIsNonCachedRAM((kal_uint32)bufferAddr, bufferSize));
      ///   }
      ///}
      ///#endif
   }

   return status;
}



G2D_STATUS_ENUM g2dOverlaySetLayerWindow(G2D_HANDLE_STRUCT *handle,
                                         G2D_OVERLAY_LAYER_ENUM layer, kal_int32 x, kal_int32 y, kal_uint32 w, kal_uint32 h)
{
   G2D_OVERLAY_LAYER_STRUCT *layerInfo = &(handle->overlayFunc.layerInfo[layer]);
   G2D_WINDOW_STRUCT *layerWindow = &(layerInfo->layerWindow);
   G2D_CANVAS_INFO_STRUCT *layerCanvas = &(layerInfo->layerCanvas);
   G2D_STATUS_ENUM status = G2D_STATUS_OK;

   if(G2D_CODEC_TYPE_HW == (handle->type))
   {
      status = g2d_drv_check_src_window(x, y, w, h);
   }

   layerWindow->topLeft.x     = x;
   layerWindow->topLeft.y     = y;
   layerWindow->buttomRight.x = x + (signed)w - 1;
   layerWindow->buttomRight.y = y + (signed)h - 1;

   if((G2D_OVERLAY_LAYER_FUNCTION_NORMAL_FONT == (layerInfo->function)) || (G2D_OVERLAY_LAYER_FUNCTION_AA_FONT == (layerInfo->function)))
   {
      layerCanvas->width = w;
      layerCanvas->bytesPerPixel = 1;
      
      if(G2D_CODEC_TYPE_HW == (handle->type))
      {
         status = g2d_drv_check_src_canvas_info(w);
      }
   }
   
   return status ;
}



G2D_STATUS_ENUM g2dOverlaySetLayerSrcKey(G2D_HANDLE_STRUCT *handle,
                                         G2D_OVERLAY_LAYER_ENUM layer, kal_bool srcKeyEnable, kal_uint32 srcKeyValue)
{
   G2D_OVERLAY_LAYER_STRUCT *layerInfo = &(handle->overlayFunc.layerInfo[layer]);

   layerInfo->srcKeyEnable = srcKeyEnable;
   layerInfo->srcKeyValue = srcKeyValue;

   return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2dOverlaySetLayerRotation(G2D_HANDLE_STRUCT *handle,
                                           G2D_OVERLAY_LAYER_ENUM layer, G2D_CW_ROTATE_ANGLE_ENUM rotation)
{
   G2D_OVERLAY_LAYER_STRUCT *layerInfo = &(handle->overlayFunc.layerInfo[layer]);

   layerInfo->rotation = rotation;

   return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2dOverlaySetLayerAlpha(G2D_HANDLE_STRUCT *handle,
                                        G2D_OVERLAY_LAYER_ENUM layer, kal_bool layerAlphaEnable, kal_uint32 layerAlphaValue)
{
   G2D_OVERLAY_LAYER_STRUCT *layerInfo = &(handle->overlayFunc.layerInfo[layer]);

   layerInfo->layerAlphaEnable = layerAlphaEnable;
   layerInfo->layerAlphaValue = layerAlphaValue;

   return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2dOverlaySetBgColor(G2D_HANDLE_STRUCT *handle, kal_uint32 backgroundColor)
{
   G2D_OVERLAY_STRUCT *overlayFunc = &(handle->overlayFunc);

   overlayFunc->backgroundColor = backgroundColor;

   return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2dOverlaySetDstAlpha(G2D_HANDLE_STRUCT *handle, kal_bool dstAlphaEnable, kal_uint32 dstAlphaValue)
{
   G2D_OVERLAY_STRUCT *overlayFunc = &(handle->overlayFunc);

   overlayFunc->dstAlphaEnable = dstAlphaEnable;
   overlayFunc->dstAlphaValue = dstAlphaValue;

   return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2dOverlaySetDstWindow(G2D_HANDLE_STRUCT *handle, kal_int32 x, kal_int32 y)
{
   G2D_COORDINATE_STRUCT *dstCoordiante = &(handle->overlayFunc.dstCoordiante);

   dstCoordiante->x = x;
   dstCoordiante->y = y;

   return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2dOverlaySetRoiWindow(G2D_HANDLE_STRUCT *handle, kal_int32 x, kal_int32 y, kal_uint32 w, kal_uint32 h)
{
   G2D_WINDOW_STRUCT *roiWindow = &(handle->overlayFunc.roiWindow);
   G2D_STATUS_ENUM status = G2D_STATUS_OK;

   if(G2D_CODEC_TYPE_HW == (handle->type))
   {
      status = g2d_drv_check_src_window(x, y, w, h);
   }

   roiWindow->topLeft.x     = x;
   roiWindow->topLeft.y     = y;
   roiWindow->buttomRight.x = x + (signed)w - 1;
   roiWindow->buttomRight.y = y + (signed)h - 1;

   return status ;
}


G2D_STATUS_ENUM g2dOverlayStart(G2D_HANDLE_STRUCT *handle)
{
   switch (handle->type)
   {
      case G2D_CODEC_TYPE_HW:
      {
         #if defined(__MTK_TARGET__)
            if (KAL_TRUE != INT_QueryExceptionStatus())
            {
               kal_take_mutex(g2d_state_mutex);
               handle->g2dState = G2D_STATE_READY;
               kal_give_mutex(g2d_state_mutex);
            }
            else
         #endif
         {
            handle->g2dState = G2D_STATE_READY;
         }

         #if defined(__MTK_TARGET__)
         {
            G2D_CANVAS_INFO_STRUCT *dstCanvas = &(handle->dstCanvas);

            kal_int32 layer;

            for (layer = 0; layer < G2D_HW_OVERLAY_TOTAL_LAYER; layer++)
            {
            	 G2D_OVERLAY_LAYER_STRUCT *layerInfo = &(handle->overlayFunc.layerInfo[layer]);
            	 G2D_CANVAS_INFO_STRUCT *layerCanvas = &(layerInfo->layerCanvas);

            	 if(G2D_COLOR_FORMAT_UYVY422 != (layerCanvas->colorFormat))
               {
                  ASSERT(INT_QueryIsNonCachedRAM((kal_uint32)(layerCanvas->RGBBufferAddr), layerCanvas->RGBBufferSize));
               }
               else
               {
                  kal_int32 colorSize;

                  /// YUV
                  for(colorSize = 0; colorSize < 3; colorSize++)
                  {
                     if(0 != (layerCanvas->YUVBufferSize[colorSize]))
                     {
                        ASSERT(INT_QueryIsNonCachedRAM((kal_uint32)(layerCanvas->YUVBufferAddr[colorSize]), layerCanvas->YUVBufferSize[colorSize]));
                     }
                  }
               }
            }

            ASSERT(INT_QueryIsNonCachedRAM((kal_uint32)(dstCanvas->RGBBufferAddr), dstCanvas->RGBBufferSize));
         }
         #endif

         g2d_drv_overlay_start(handle);

         #if defined(__MTK_TARGET__)
            if (KAL_TRUE != INT_QueryExceptionStatus())
            {
               kal_take_mutex(g2d_state_mutex);
               handle->g2dState = G2D_STATE_BUSY;
               kal_give_mutex(g2d_state_mutex);
            }
            else
         #endif
         {
            handle->g2dState = G2D_STATE_BUSY;
         }
      }
      break;
      default:
         ASSERT(0);
      break;
   }

   return G2D_STATUS_OK;
}

#else


G2D_STATUS_ENUM g2dOverlayEnableLayer(G2D_HANDLE_STRUCT *handle,
                                      G2D_OVERLAY_LAYER_ENUM layer, kal_bool layerEnable)
{
   return G2D_STATUS_NOT_SUPPORT;
}



G2D_STATUS_ENUM g2dOverlaySetLayerFunction(G2D_HANDLE_STRUCT *handle,
                                           G2D_OVERLAY_LAYER_ENUM layer, G2D_OVERLAY_LAYER_FUNCTION_ENUM function)
{
   return G2D_STATUS_NOT_SUPPORT;
}



G2D_STATUS_ENUM g2dOverlaySetLayerFontBit(G2D_HANDLE_STRUCT *handle,
                                          G2D_OVERLAY_LAYER_ENUM layer, G2D_FONT_BIT_ENUM fontBit)
{
   return G2D_STATUS_NOT_SUPPORT;
}



G2D_STATUS_ENUM g2dOverlaySetLayerFontFgColor(G2D_HANDLE_STRUCT *handle,
                                              G2D_OVERLAY_LAYER_ENUM layer, kal_uint32 foregroundColor)
{
   return G2D_STATUS_NOT_SUPPORT;
}



G2D_STATUS_ENUM g2dOverlaySetLayerRectFillColor(G2D_HANDLE_STRUCT *handle,
                                                G2D_OVERLAY_LAYER_ENUM layer, kal_uint32 rectFillColor)
{
   return G2D_STATUS_NOT_SUPPORT;
}



G2D_STATUS_ENUM g2dOverlaySetLayerYUVBufferInfo(G2D_HANDLE_STRUCT *handle, G2D_OVERLAY_LAYER_ENUM layer,
                                                kal_uint8 *bufferAddr[3], kal_uint32 bufferSize[3],
                                                kal_uint32 width, kal_uint32 height, G2D_COLOR_FORMAT_ENUM colorFormat)
{
   return G2D_STATUS_NOT_SUPPORT;
}



G2D_STATUS_ENUM g2dOverlaySetLayerRGBBufferInfo(G2D_HANDLE_STRUCT *handle, G2D_OVERLAY_LAYER_ENUM layer,
                                                kal_uint8 *bufferAddr, kal_uint32 bufferSize,
                                                kal_uint32 width, kal_uint32 height, G2D_COLOR_FORMAT_ENUM colorFormat)
{
   return G2D_STATUS_NOT_SUPPORT;
}



G2D_STATUS_ENUM g2dOverlaySetLayerBufferInfo(G2D_HANDLE_STRUCT *handle, G2D_OVERLAY_LAYER_ENUM layer,
                                             kal_uint8 *bufferAddr, kal_uint32 bufferSize)
{
   return G2D_STATUS_NOT_SUPPORT;
}



G2D_STATUS_ENUM g2dOverlaySetLayerWindow(G2D_HANDLE_STRUCT *handle,
                                         G2D_OVERLAY_LAYER_ENUM layer, kal_int32 x, kal_int32 y, kal_uint32 w, kal_uint32 h)
{
   return G2D_STATUS_NOT_SUPPORT;
}


G2D_STATUS_ENUM g2dOverlaySetLayerSrcKey(G2D_HANDLE_STRUCT *handle,
                                         G2D_OVERLAY_LAYER_ENUM layer, kal_bool srcKeyEnable, kal_uint32 srcKeyValue)
{
   return G2D_STATUS_NOT_SUPPORT;
}



G2D_STATUS_ENUM g2dOverlaySetLayerRotation(G2D_HANDLE_STRUCT *handle,
                                           G2D_OVERLAY_LAYER_ENUM layer, G2D_CW_ROTATE_ANGLE_ENUM rotation)
{
   return G2D_STATUS_NOT_SUPPORT;
}



G2D_STATUS_ENUM g2dOverlaySetLayerAlpha(G2D_HANDLE_STRUCT *handle,
                                        G2D_OVERLAY_LAYER_ENUM layer, kal_bool layerAlphaEnable, kal_uint32 layerAlphaValue)
{
   return G2D_STATUS_NOT_SUPPORT;
}



G2D_STATUS_ENUM g2dOverlaySetBgColor(G2D_HANDLE_STRUCT *handle, kal_uint32 backgroundColor)
{
   return G2D_STATUS_NOT_SUPPORT;
}


G2D_STATUS_ENUM g2dOverlaySetDstAlpha(G2D_HANDLE_STRUCT *handle, kal_bool dstAlphaEnable, kal_uint32 dstAlphaValue)
{
   return G2D_STATUS_NOT_SUPPORT;
}


G2D_STATUS_ENUM g2dOverlaySetDstWindow(G2D_HANDLE_STRUCT *handle, kal_int32 x, kal_int32 y)
{
   return G2D_STATUS_NOT_SUPPORT;
}


G2D_STATUS_ENUM g2dOverlaySetRoiWindow(G2D_HANDLE_STRUCT *handle, kal_int32 x, kal_int32 y, kal_uint32 w, kal_uint32 h)
{
   return G2D_STATUS_NOT_SUPPORT;
}


G2D_STATUS_ENUM g2dOverlayStart(G2D_HANDLE_STRUCT *handle)
{
   return G2D_STATUS_NOT_SUPPORT;
}

#endif



#if defined(G2D_FPGA)


G2D_STATUS_ENUM g2dOverlayDisableBg(G2D_HANDLE_STRUCT *handle, kal_bool backgroundDisable)
{
   G2D_OVERLAY_STRUCT *overlayFunc = &(handle->overlayFunc);

   overlayFunc->backgroundDisable = backgroundDisable;

   return G2D_STATUS_OK;
}

#endif


