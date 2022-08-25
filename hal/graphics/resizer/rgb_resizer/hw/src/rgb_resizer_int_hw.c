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
 *   rgb_resizer_int_hw.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   RGB Resizer
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features_resizer.h"

#if defined(RGB_RESIZER_HW_SUPPORT)

#include "kal_general_types.h"

#include "rgb_resizer_structure.h"

#include "idp_image_resize.h"
#include "img_common_enum.h"

static kal_uint32 _rgb_resizer_hw_key;

RESIZER_STATUS_ENUM rgb_resizer_drv_query_working_memory(RGB_RESIZER_HANDLE_STRUCT *handle, kal_uint32 *intMemBest, kal_uint32 *intMemMin,
                                                                                            kal_uint32 *extMemBest, kal_uint32 *extMemMin)
{
   (*extMemBest) = 0;
   (*extMemMin) = 0;
   (*intMemBest) = 0;
   (*intMemMin) = 0;

   return RESIZER_STATUS_OK;
}


kal_int32 rgb_resizer_drv_get_status(void)
{
   kal_bool busy;
   kal_bool result;

   result = idp_image_resize_is_busy(_rgb_resizer_hw_key, &busy);
   if (KAL_TRUE != result)
   {
      return -1;
   }

   if (KAL_FALSE == busy)
   {
      return 0;
   }
   else
   {
      return 1;
   }
}




kal_int32 rgb_resizer_drv_open(void)
{
   kal_int32 ret = 0;
   kal_bool result;


   /// open, to get key
   result = idp_image_resize_open(&_rgb_resizer_hw_key);
   if (KAL_TRUE != result)
   {
      ret = -1;
   }

   return ret;
}



kal_int32 rgb_resizer_drv_close(void)
{
   kal_int32 ret = 0;
   kal_bool result;

   /// close resizer
   result = idp_image_resize_close(_rgb_resizer_hw_key);
   if (KAL_TRUE != result)
   {
       ret = -1;
   }

   return ret;
}



kal_int32 rgb_resizer_drv_start(RGB_RESIZER_HANDLE_STRUCT *handle)
{
   RGB_RESIZER_WINDOW_STRUCT *targetClipWindow = &(handle->targetClipWindow);
   RGB_RESIZER_WINDOW_STRUCT *srcWindow = &(handle->srcWindow);
   RGB_RESIZER_WINDOW_STRUCT *dstWindow = &(handle->dstWindow);
   img_color_fmt_rgb_enum_t srcColorFormat, dstColorFormat;
   
   kal_uint8 *dstAddr;
   kal_uint8 bpp;

   kal_int32 start_x,start_y,ret = 0;
   kal_bool result;

   start_x = (targetClipWindow->startX - dstWindow->startX);
   start_y = (targetClipWindow->startY - dstWindow->startY);

   switch(handle->dstColorFormat)
   {
      case RESIZER_COLOR_FORMAT_ENUM_RGB565:
         dstColorFormat = IMG_COLOR_FMT_RGB565;
         bpp = 2;
      break;
      case RESIZER_COLOR_FORMAT_ENUM_RGB888:
         dstColorFormat = IMG_COLOR_FMT_RGB888;
         bpp = 3;
      break;
      default:
         return -1;
   }

   switch(handle->srcColorFormat)
   {
      case RESIZER_COLOR_FORMAT_ENUM_RGB565:
         srcColorFormat = IMG_COLOR_FMT_RGB565;
      break;
      case RESIZER_COLOR_FORMAT_ENUM_RGB888:
         srcColorFormat = IMG_COLOR_FMT_RGB888;
      break;
      default:
         return -1;
   }

   dstAddr = ((kal_uint8*)handle->dstBuffer) + ((targetClipWindow->startY) * handle->dstWidth + (targetClipWindow->startX)) * bpp;

   do
   {
      /// config resizer, 0 represent configing over
      /// config memory
      result = idp_image_resize_config(
                  _rgb_resizer_hw_key,
                  IDP_IMAGE_RESIZE_INTMEM_START_ADDRESS,
                  0,
                  IDP_IMAGE_RESIZE_INTMEM_SIZE,
                  0,
                  IDP_IMAGE_RESIZE_EXTMEM_START_ADDRESS,
                  NULL,
                  IDP_IMAGE_RESIZE_EXTMEM_SIZE,
                  0,
                  0);
      /// config color format
      result = idp_image_resize_config(
                  _rgb_resizer_hw_key,
                  IDP_IMAGE_RESIZE_SRC_COLOR_FMT,
                  srcColorFormat,   /// support: RGB565, RGB888, BGR888
                  IDP_IMAGE_RESIZE_DEST_COLOR_FMT,
                  dstColorFormat,   /// support: RGB565, RGB888, ARGB8888
                  0);
      /// config image address
      result = idp_image_resize_config(
                  _rgb_resizer_hw_key,
                  IDP_IMAGE_RESIZE_SRC_IMAGE_ADDRESS,
                  handle->srcBuffer,
                  IDP_IMAGE_RESIZE_DEST_IMAGE_ADDRESS,
                  dstAddr,
                  0);
      /// config src dimension
      result = idp_image_resize_config(
                  _rgb_resizer_hw_key,
                  IDP_IMAGE_RESIZE_SRC_WIDTH,
                  handle->srcWidth,
                  IDP_IMAGE_RESIZE_SRC_HEIGHT,
                  handle->srcHeight,
                  0);
      /// config src clip
      result = idp_image_resize_config(
                  _rgb_resizer_hw_key,
                  IDP_IMAGE_RESIZE_ENABLE_SRC_CLIP,
                  KAL_TRUE,
                  IDP_IMAGE_RESIZE_SRC_CLIP_LEFT,
                  srcWindow->startX,
                  IDP_IMAGE_RESIZE_SRC_CLIP_RIGHT,
                  (srcWindow->startX + srcWindow->width - 1),
                  IDP_IMAGE_RESIZE_SRC_CLIP_TOP,
                  srcWindow->startY,
                  IDP_IMAGE_RESIZE_SRC_CLIP_BOTTOM,
                  (srcWindow->startY + srcWindow->height - 1),
                  0);
      /// config target dimension
      result = idp_image_resize_config(
                  _rgb_resizer_hw_key,
                  IDP_IMAGE_RESIZE_TARGET_WIDTH,
                  dstWindow->width,
                  IDP_IMAGE_RESIZE_TARGET_HEIGHT,
                  dstWindow->height,
                  0);
      /// config clipping
      result = idp_image_resize_config(
                  _rgb_resizer_hw_key,
                  IDP_IMAGE_RESIZE_ENABLE_CLIP,
                  KAL_TRUE,
                  IDP_IMAGE_RESIZE_CLIP_LEFT,
                  (start_x),
                  IDP_IMAGE_RESIZE_CLIP_RIGHT,
                  (start_x + targetClipWindow->width) - 1,
                  IDP_IMAGE_RESIZE_CLIP_TOP,
                  (start_y),
                  IDP_IMAGE_RESIZE_CLIP_BOTTOM,
                  (start_y + targetClipWindow->height) - 1,
                  0);
      /// config destnation pitch
      result = idp_image_resize_config(
                  _rgb_resizer_hw_key,
                  IDP_IMAGE_RESIZE_ENABLE_PITCH,      /// dest pitch mode
                  KAL_TRUE,
                  IDP_IMAGE_RESIZE_BG_IMAGE_WIDTH,    /// dest pitch
                  handle->dstWidth,
                  0);
      /// config rotate
      result = idp_image_resize_config(
                  _rgb_resizer_hw_key,
                  IDP_IMAGE_RESIZE_ROT_ANGLE,
                  IMG_ROT_ANGLE_0,
                  0);
      /// config u value and v value
      result = idp_image_resize_config(
                  _rgb_resizer_hw_key,
                  IDP_IMAGE_RESIZE_RESIZER_U_VALUE,
                  8,
                  IDP_IMAGE_RESIZE_RESIZER_V_VALUE,
                  15,
                  0);

      /// config dithering, disable dithering
      result = idp_image_resize_config(
                  _rgb_resizer_hw_key,
                  IDP_IMAGE_RESIZE_IPP_ENABLE_SPATIAL_DITHERING,
                  KAL_FALSE,
                  0);

      /// config callback
      result = idp_image_resize_config(
                  _rgb_resizer_hw_key,
                  IDP_IMAGE_RESIZE_FRAME_DONE_CB,
                  handle->rgbResizerCallback, 0);

      if (KAL_TRUE != result)
      {
         ret = -1;
         break;
      }

      /// start resizer
      result = idp_image_resize_start_all(_rgb_resizer_hw_key);
      if (KAL_TRUE != result)
      {
         ret = -1;
         break;
      }

   }while(0);

   return ret;
}


#endif
