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
 *   g2d_bitblt_api.c
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
#include "kal_general_types.h"

#include "drv_features_g2d.h"
#include "g2d_enum.h"
#include "g2d_structure.h"
#include "g2d_mutex.h"

#if defined(G2D_HW_BITBLT_SUPPORT)

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
      #define ASSERT(x) assert(x)
   #endif
#else
   #include "kal_public_api.h"
   #include "kal_public_defs.h"
   #include "cache_sw.h"

   #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)   
      #include "drv_gfx_dynamic_switch.h"
   #endif

   #if defined(__MTK_TARGET__)
      extern kal_mutexid g2d_state_mutex;
      extern g2d_mutex_struct g2d_mutex;
      extern kal_bool INT_QueryExceptionStatus(void);

   #endif
#endif

#include "g2d_drv_api.h"

G2D_STATUS_ENUM g2dBitBltSetSrcRGBBufferInfo(G2D_HANDLE_STRUCT *handle,
                                             kal_uint8 *bufferAddr, kal_uint32 bufferSize,
                                             kal_uint32 width, kal_uint32 height, G2D_COLOR_FORMAT_ENUM colorFormat)
{
   G2D_CANVAS_INFO_STRUCT *srcCanvas = &(handle->bitbltFunc.srcCanvas);
   G2D_STATUS_ENUM status = G2D_STATUS_OK;

   ASSERT(bufferAddr);

   srcCanvas->RGBBufferAddr = bufferAddr;
   srcCanvas->RGBBufferSize = bufferSize;
   srcCanvas->width = width;
   srcCanvas->height = height;
   srcCanvas->colorFormat = colorFormat;

   switch (colorFormat)
   {
      case G2D_COLOR_FORMAT_GRAY:
      case G2D_COLOR_FORMAT_ARGB8888_INDEX_COLOR :
         srcCanvas->bytesPerPixel = 1;
      break;
      case G2D_COLOR_FORMAT_RGB565:
         srcCanvas->bytesPerPixel = 2;
      break;
      case G2D_COLOR_FORMAT_RGB888:
      case G2D_COLOR_FORMAT_BGR888:
      case G2D_COLOR_FORMAT_ARGB8565:
      case G2D_COLOR_FORMAT_PARGB8565:
      case G2D_COLOR_FORMAT_ARGB6666:
      case G2D_COLOR_FORMAT_PARGB6666:
         srcCanvas->bytesPerPixel = 3;
      break;
      case G2D_COLOR_FORMAT_ARGB8888:
      case G2D_COLOR_FORMAT_PARGB8888:
         srcCanvas->bytesPerPixel = 4;
      break;
      default:
         ASSERT(0);
      break;
   }

#if defined(MT6255)
#if defined(__MTK_TARGET__)
   if (INT_QueryIsROMSpace((kal_uint32)srcCanvas->RGBBufferAddr))
   {
      EXT_ASSERT(0, (kal_uint32)srcCanvas->RGBBufferAddr, 0, 0);
   }
#endif //#if defined(__MTK_TARGET__)
#endif

   if(G2D_CODEC_TYPE_HW == (handle->type))
   {
      status =  g2d_drv_check_src_canvas_info(width);

      ///#if defined(__MTK_TARGET__)
      ///{
      ///   ASSERT(INT_QueryIsNonCachedRAM((kal_uint32)bufferAddr, bufferSize));
      ///}
      ///#endif
   }

   return status;
}



G2D_STATUS_ENUM g2dBitBltSetSrcWindow(G2D_HANDLE_STRUCT *handle, kal_int32 x, kal_int32 y, kal_uint32 w, kal_uint32 h)
{
   G2D_WINDOW_STRUCT *srcWindow = &(handle->bitbltFunc.srcWindow);
   G2D_STATUS_ENUM status = G2D_STATUS_OK;

   if(G2D_CODEC_TYPE_HW == (handle->type))
   {
      status = g2d_drv_check_src_window(x, y, w, h);
   }

   srcWindow->topLeft.x     = x;
   srcWindow->topLeft.y     = y;
   srcWindow->buttomRight.x = x + (signed)w - 1;
   srcWindow->buttomRight.y = y + (signed)h - 1;

   return status;
}



G2D_STATUS_ENUM g2dBitBltSetDstWindow(G2D_HANDLE_STRUCT *handle, kal_int32 x, kal_int32 y, kal_uint32 w, kal_uint32 h)
{
   G2D_WINDOW_STRUCT *dstWindow = &(handle->bitbltFunc.dstWindow);
   G2D_STATUS_ENUM status = G2D_STATUS_OK;

   if(G2D_CODEC_TYPE_HW == (handle->type))
   {
      status = g2d_drv_check_dst_window(x, y, w, h);
   }

   dstWindow->topLeft.x     = x;
   dstWindow->topLeft.y     = y;
   dstWindow->buttomRight.x = x + (signed)w - 1;
   dstWindow->buttomRight.y = y + (signed)h - 1;

   return status;
}



G2D_STATUS_ENUM g2dBitBltSetRotation(G2D_HANDLE_STRUCT *handle, G2D_CW_ROTATE_ANGLE_ENUM rotation)
{
   G2D_BITBLT_STRUCT *bitbltFunc = &(handle->bitbltFunc);

   bitbltFunc->rotation = rotation;

   return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2dBitBltSetSrcAlpha(G2D_HANDLE_STRUCT *handle, kal_bool srcAlphaEnable, kal_uint32 srcAlphaValue)
{
   G2D_BITBLT_STRUCT *bitbltFunc = &(handle->bitbltFunc);
   G2D_STATUS_ENUM status = G2D_STATUS_OK;

   switch (handle->type)
   {
      case G2D_CODEC_TYPE_HW:
      {
         status = g2d_drv_bitblt_query_src_alpha_support();
      }
      break;
      case G2D_CODEC_TYPE_SW:
         status = G2D_STATUS_NOT_SUPPORT;
      break;
      default:
         ASSERT(0);
      break;
   }

   bitbltFunc->srcAlphaEnable = srcAlphaEnable;
   if (KAL_TRUE == srcAlphaEnable)
   {
      bitbltFunc->srcAlphaValue = srcAlphaValue;
   }

   return status;
}



G2D_STATUS_ENUM g2dBitBltSetDstAlpha(G2D_HANDLE_STRUCT *handle, kal_bool dstAlphaEnable, kal_uint32 dstAlphaValue)
{
   G2D_BITBLT_STRUCT *bitbltFunc = &(handle->bitbltFunc);
   G2D_STATUS_ENUM status = G2D_STATUS_OK;

   bitbltFunc->dstAlphaEnable = dstAlphaEnable;
   bitbltFunc->dstAlphaValue = dstAlphaValue;


   return status;
}



G2D_STATUS_ENUM  g2dBitBltSetIndexColorTable(G2D_HANDLE_STRUCT *handle, kal_uint32 *paletteTableAddress, G2D_INDEX_COLOR_TABLE_SIZE_ENUM paletteSize)
{
   G2D_BITBLT_STRUCT *bitbltFunc = &(handle->bitbltFunc);

   bitbltFunc->indexColorTableAddr = paletteTableAddress;
   bitbltFunc->indexColorTableSize = paletteSize;

   return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2dBitBltQuerySrcRGBBufferRange(G2D_HANDLE_STRUCT *handle, kal_uint32 *min_width, kal_uint32 *max_width, kal_uint32 *min_height, kal_uint32 *max_height)
{
   G2D_STATUS_ENUM status = G2D_STATUS_OK;

   switch (handle->type)
   {
      case G2D_CODEC_TYPE_HW:
      {
         status = g2d_drv_query_src_canvas_info(min_width, max_width, min_height, max_height);
      }
      break;
      default:
         ASSERT(0);
      break;
   }

   return status;
}


G2D_STATUS_ENUM g2dBitBltQuerySrcWindowRange(G2D_HANDLE_STRUCT *handle,
                                             kal_int32 *min_x, kal_int32 *max_x, kal_int32 *min_y, kal_int32 *max_y,
                                             kal_uint32 *min_w, kal_uint32 *max_w, kal_uint32 *min_h, kal_uint32 *max_h)
{
   G2D_STATUS_ENUM status = G2D_STATUS_OK;

   switch (handle->type)
   {
      case G2D_CODEC_TYPE_HW:
      {
         status = g2d_drv_query_src_window(min_x, max_x, min_y, max_y, min_w, max_w, min_h, max_h);
      }
      break;
      default:
         ASSERT(0);
      break;
   }

   return status;
}


G2D_STATUS_ENUM g2dBitBltQueryDstWindowRange(G2D_HANDLE_STRUCT *handle,
                                             kal_int32 *min_x, kal_int32 *max_x, kal_int32 *min_y, kal_int32 *max_y,
                                             kal_uint32 *min_w, kal_uint32 *max_w, kal_uint32 *min_h, kal_uint32 *max_h)
{
   G2D_STATUS_ENUM status = G2D_STATUS_OK;

   switch (handle->type)
   {
      case G2D_CODEC_TYPE_HW:
      {
         status = g2d_drv_query_dst_window(min_x, max_x, min_y, max_y, min_w, max_w, min_h, max_h);
      }
      break;
      default:
         ASSERT(0);
      break;
   }

   return status;
}



G2D_STATUS_ENUM g2dBitBltStart(G2D_HANDLE_STRUCT *handle)
{
   switch (handle->type)
   {
      case G2D_CODEC_TYPE_HW:
      {
         #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
         {
            G2D_CANVAS_INFO_STRUCT *dstCanvas = &(handle->dstCanvas);
            G2D_CANVAS_INFO_STRUCT *srcCanvas = &(handle->bitbltFunc.srcCanvas);

            /// Source
            /// RGB
            if (GFX_CACHE_SWITCH_BEHAVIOR_TRY_SWITCH == handle->srcCanvasCacheSwitchBehavior)
            {
               if(KAL_TRUE == drv_gfx_dynamic_switch_noncacheable(&(srcCanvas->RGBBufferAddr), srcCanvas->RGBBufferSize, KAL_TRUE))
               {
                  handle->srcBitbltRGBCanvasType = G2D_MEMORY_TYPE_SWITCH_TO_NONCACHEABLE;
               }
            }

            /// Destination
            /// RGB
            if (GFX_CACHE_SWITCH_BEHAVIOR_TRY_SWITCH == handle->dstCanvasCacheSwitchBehavior)
            {
               if(KAL_TRUE == drv_gfx_dynamic_switch_noncacheable(&(dstCanvas->RGBBufferAddr), dstCanvas->RGBBufferSize, KAL_TRUE))
               {
                  handle->dstCanvasType = G2D_MEMORY_TYPE_SWITCH_TO_NONCACHEABLE;
               }
            }
         }
         #endif

         #if defined(__MTK_TARGET__)
         {
            G2D_CANVAS_INFO_STRUCT *dstCanvas = &(handle->dstCanvas);
            G2D_CANVAS_INFO_STRUCT *srcCanvas = &(handle->bitbltFunc.srcCanvas);

            ASSERT(INT_QueryIsNonCachedRAM((kal_uint32)(srcCanvas->RGBBufferAddr), srcCanvas->RGBBufferSize));
            ASSERT(INT_QueryIsNonCachedRAM((kal_uint32)(dstCanvas->RGBBufferAddr), dstCanvas->RGBBufferSize));
         }
         #endif

         g2d_drv_bitblt_start(handle);

         #if defined(__MTK_TARGET__)
            if (KAL_TRUE != INT_QueryExceptionStatus())
            {
               handle->g2dState = G2D_STATE_BUSY;
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

G2D_STATUS_ENUM g2dBitBltSetSrcRGBBufferInfo(G2D_HANDLE_STRUCT *handle,
                                             kal_uint8 *bufferAddr, kal_uint32 bufferSize,
                                             kal_uint32 width, kal_uint32 height, G2D_COLOR_FORMAT_ENUM colorFormat)
{
   return G2D_STATUS_NOT_SUPPORT;
}



G2D_STATUS_ENUM g2dBitBltSetSrcWindow(G2D_HANDLE_STRUCT *handle, kal_int32 x, kal_int32 y, kal_uint32 w, kal_uint32 h)
{
   return G2D_STATUS_NOT_SUPPORT;
}



G2D_STATUS_ENUM g2dBitBltSetDstWindow(G2D_HANDLE_STRUCT *handle, kal_int32 x, kal_int32 y, kal_uint32 w, kal_uint32 h)
{
   return G2D_STATUS_NOT_SUPPORT;
}



G2D_STATUS_ENUM g2dBitBltSetRotation(G2D_HANDLE_STRUCT *handle, G2D_CW_ROTATE_ANGLE_ENUM rotation)
{
   return G2D_STATUS_NOT_SUPPORT;
}



G2D_STATUS_ENUM g2dBitBltSetSrcAlpha(G2D_HANDLE_STRUCT *handle, kal_bool srcAlphaEnable, kal_uint32 srcAlphaValue)
{
   return G2D_STATUS_NOT_SUPPORT;
}



G2D_STATUS_ENUM g2dBitBltSetDstAlpha(G2D_HANDLE_STRUCT *handle, kal_bool dstAlphaEnable, kal_uint32 dstAlphaValue)
{
   return G2D_STATUS_NOT_SUPPORT;
}



G2D_STATUS_ENUM  g2dBitBltSetIndexColorTable(G2D_HANDLE_STRUCT *handle, kal_uint32 *palette_table_address, G2D_INDEX_COLOR_TABLE_SIZE_ENUM palette_size)
{
   return G2D_STATUS_NOT_SUPPORT;
}



G2D_STATUS_ENUM g2dBitBltQuerySrcRGBBufferRange(G2D_HANDLE_STRUCT *handle, kal_uint32 *min_width, kal_uint32 *max_width, kal_uint32 *min_height, kal_uint32 *max_height)
{
   return G2D_STATUS_NOT_SUPPORT;
}


G2D_STATUS_ENUM g2dBitBltQuerySrcWindowRange(G2D_HANDLE_STRUCT *handle,
                                             kal_int32 *min_x, kal_int32 *max_x, kal_int32 *min_y, kal_int32 *max_y,
                                             kal_uint32 *min_w, kal_uint32 *max_w, kal_uint32 *min_h, kal_uint32 *max_h)
{
   return G2D_STATUS_NOT_SUPPORT;
}


G2D_STATUS_ENUM g2dBitBltQueryDstWindowRange(G2D_HANDLE_STRUCT *handle,
                                             kal_int32 *min_x, kal_int32 *max_x, kal_int32 *min_y, kal_int32 *max_y,
                                             kal_uint32 *min_w, kal_uint32 *max_w, kal_uint32 *min_h, kal_uint32 *max_h)
{
   return G2D_STATUS_NOT_SUPPORT;
}



G2D_STATUS_ENUM g2dBitBltStart(G2D_HANDLE_STRUCT *handle)
{
   return G2D_STATUS_NOT_SUPPORT;
}

#endif

