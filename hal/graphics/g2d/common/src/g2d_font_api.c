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
 *   g2d_font_api.c
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

#if defined(G2D_HW_FONT_SUPPORT)

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
   
   #if defined(__MTK_TARGET__)
      extern kal_mutexid g2d_state_mutex;
      extern g2d_mutex_struct g2d_mutex;
      extern kal_bool INT_QueryExceptionStatus(void);

   #endif
#endif

#include "g2d_drv_api.h"

G2D_STATUS_ENUM g2dFontSetSrcBufferInfo(G2D_HANDLE_STRUCT *handle, kal_uint8 *bufferAddr, kal_uint32 bufferSize)
{
   G2D_CANVAS_INFO_STRUCT *srcCanvas = &(handle->fontFunc.srcCanvas);
   G2D_CANVAS_INFO_STRUCT *dstCanvas = &(handle->dstCanvas);
   G2D_STATUS_ENUM status = G2D_STATUS_OK;

   ASSERT(bufferAddr);

   srcCanvas->RGBBufferAddr = bufferAddr;
   srcCanvas->RGBBufferSize = bufferSize;
   srcCanvas->colorFormat = G2D_COLOR_FORMAT_GRAY;
   srcCanvas->bytesPerPixel = 1;
   srcCanvas->width = dstCanvas->width;
   srcCanvas->height = dstCanvas->height;

   status = g2d_drv_check_src_canvas_info(srcCanvas->width);

#if defined(MT6255)
#if defined(__MTK_TARGET__)
   if (INT_QueryIsROMSpace((kal_uint32)srcCanvas->RGBBufferAddr))
   {
     EXT_ASSERT(0, (kal_uint32)srcCanvas->RGBBufferAddr, 0, 0);
   }
#endif //#if defined(__MTK_TARGET__)
#endif

   ///if(G2D_CODEC_TYPE_HW == (handle->type))
   ///{
   ///   #if defined(__MTK_TARGET__)
   ///   {
   ///      ASSERT(INT_QueryIsNonCachedRAM((kal_uint32)bufferAddr, bufferSize));
   ///   }
   ///   #endif
   ///}

   return status;
}



G2D_STATUS_ENUM g2dFontSetTiltMode(G2D_HANDLE_STRUCT *handle, kal_bool tiltModeEnable, kal_int32 *tilt_table, kal_int32 tiltTableSize)
{
   #if defined(G2D_HW_TILT_FONT_SUPPORT)
      G2D_FONT_STRUCT *fontFunc = &(handle->fontFunc);
      G2D_STATUS_ENUM status = G2D_STATUS_OK;
      kal_int32 i;

      fontFunc->tiltModeEnable = tiltModeEnable;

      if (KAL_TRUE == tiltModeEnable)
      {
         switch (handle->type)
         {
            case G2D_CODEC_TYPE_HW:
            {
               status = g2d_drv_font_query_tilt_font_support();
            }
            break;
            default:
               ASSERT(0);
            break;
         }

         fontFunc->tiltTableSize = tiltTableSize;

         ASSERT(tilt_table);

         for (i = 0; i < tiltTableSize ; i++)
         {
            fontFunc->tiltValued[i] = tilt_table[i];
         }
      }

      return status;
   #else
      return G2D_STATUS_NOT_SUPPORT;
   #endif
}



G2D_STATUS_ENUM g2dFontSetAAFont(G2D_HANDLE_STRUCT *handle, kal_bool aaFontEnable)
{
   G2D_FONT_STRUCT *fontFunc = &(handle->fontFunc);
   G2D_STATUS_ENUM status = G2D_STATUS_OK;

   switch (handle->type)
   {
      case G2D_CODEC_TYPE_HW:
      {
         status = g2d_drv_font_query_aa_font_support();
      }
      break;
      default:
         ASSERT(0);
      break;
   }

   if(G2D_STATUS_OK == status)
   {
      fontFunc->aaFontEnable = aaFontEnable;
   }

   return status;
}



G2D_STATUS_ENUM g2dFontSetFontBit(G2D_HANDLE_STRUCT *handle, G2D_FONT_BIT_ENUM fontBit)
{
   G2D_FONT_STRUCT *fontFunc = &(handle->fontFunc);

   if (KAL_TRUE == (fontFunc->aaFontEnable))
   {
      fontFunc->fontBit = fontBit;
   }
   else
   {
      fontFunc->fontBit = G2D_FONT_BIT_1_BIT;
   }

   return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2dFontSetFgColor(G2D_HANDLE_STRUCT *handle, kal_uint8 a0, kal_uint8 r0, kal_uint8 g0, kal_uint8 b0)
{
   G2D_COLOR_STRUCT *fontColor = &(handle->fontFunc.foregroundColor);

   fontColor->alpha = a0;
   fontColor->red   = r0;
   fontColor->green = g0;
   fontColor->blue  = b0;

   return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2dFontSetDstWindow(G2D_HANDLE_STRUCT *handle, kal_int32 x, kal_int32 y, kal_int32 width, kal_int32 height)
{
   G2D_WINDOW_STRUCT *dstWindow = &(handle->fontFunc.dstWindow);
   G2D_STATUS_ENUM status = G2D_STATUS_OK;

   if(G2D_CODEC_TYPE_HW == (handle->type))
   {
      status = g2d_drv_check_dst_window(x, y, width, height);
   }

   /// We can not set x to 0 if x<0
   /// This is due to that 0 will be output
   dstWindow->topLeft.x   = x;
   dstWindow->topLeft.y   = y;
   dstWindow->buttomRight.x = x + width - 1;
   dstWindow->buttomRight.y = y + height - 1;

   return status;
}



G2D_STATUS_ENUM g2dFontQueryDstWindowRange(G2D_HANDLE_STRUCT *handle,
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



G2D_STATUS_ENUM g2dFontStart(G2D_HANDLE_STRUCT *handle)
{
   switch (handle->type)
   {
      case G2D_CODEC_TYPE_HW:
      {
         #if defined(__MTK_TARGET__)
         {
            G2D_CANVAS_INFO_STRUCT *srcCanvas = &(handle->fontFunc.srcCanvas);
            G2D_CANVAS_INFO_STRUCT *dstCanvas = &(handle->dstCanvas);
               
            ASSERT(INT_QueryIsNonCachedRAM((kal_uint32)(srcCanvas->RGBBufferAddr), srcCanvas->RGBBufferSize));
            ASSERT(INT_QueryIsNonCachedRAM((kal_uint32)(dstCanvas->RGBBufferAddr), dstCanvas->RGBBufferSize));
         }   
         #endif

         g2d_drv_font_start(handle);

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

G2D_STATUS_ENUM g2dFontSetSrcBufferInfo(G2D_HANDLE_STRUCT *handle, kal_uint8 *addr)
{
   return G2D_STATUS_NOT_SUPPORT;
}



G2D_STATUS_ENUM g2dFontSetTiltMode(G2D_HANDLE_STRUCT *handle, kal_bool tiltModeEnable, kal_int32 *tilt_table, kal_int32 tiltTableSize)
{
   return G2D_STATUS_NOT_SUPPORT;
}



G2D_STATUS_ENUM g2dFontSetAAFont(G2D_HANDLE_STRUCT *handle, kal_bool aaFontEnable)
{
   return G2D_STATUS_NOT_SUPPORT;
}



G2D_STATUS_ENUM g2dFontSetFontBit(G2D_HANDLE_STRUCT *handle, G2D_FONT_BIT_ENUM fontBit)
{
   return G2D_STATUS_NOT_SUPPORT;
}



G2D_STATUS_ENUM g2dFontSetFgColor(G2D_HANDLE_STRUCT *handle, kal_uint8 a0, kal_uint8 r0, kal_uint8 g0, kal_uint8 b0)
{
   return G2D_STATUS_NOT_SUPPORT;
}



G2D_STATUS_ENUM g2dFontSetDstWindow(G2D_HANDLE_STRUCT *handle, kal_int32 x, kal_int32 y, kal_int32 width, kal_int32 height)
{
   return G2D_STATUS_NOT_SUPPORT;
}



G2D_STATUS_ENUM g2dFontQueryDstWindowRange(G2D_HANDLE_STRUCT *handle,
                                           kal_int32 *min_x, kal_int32 *max_x, kal_int32 *min_y, kal_int32 *max_y,
                                           kal_uint32 *min_w, kal_uint32 *max_w, kal_uint32 *min_h, kal_uint32 *max_h)
{
   return G2D_STATUS_NOT_SUPPORT;
}



G2D_STATUS_ENUM g2dFontStart(G2D_HANDLE_STRUCT *handle)
{
   return G2D_STATUS_NOT_SUPPORT;
}

#endif

