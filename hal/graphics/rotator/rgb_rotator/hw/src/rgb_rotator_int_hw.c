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
 *   rgb_rotator_int_hw.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   RGB Rotator
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features_rotator.h"

#if defined(RGB_ROTATOR_HW_SUPPORT)

#include "kal_general_types.h"

#include "rotator_enum.h"

#include "rgb_rotator_structure.h"

#include "iul_csc_macros.h"

#include "g2d_enum.h"
#include "g2d_common_api.h"
#include "g2d_bitblt_api.h"

static G2D_HANDLE_STRUCT *_rgb_rotator_g2d_hw_handle;

ROTATOR_STATUS_ENUM rgb_rotator_drv_query_working_memory(RGB_ROTATOR_HANDLE_STRUCT *handle, kal_uint32 *intMemBest, kal_uint32 *intMemMin,
                                                                                            kal_uint32 *extMemBest, kal_uint32 *extMemMin)
{
   *intMemBest = 0;
   *intMemMin = 0;
   *extMemBest = 0;
   *extMemMin = 0;

   return ROTATOR_STATUS_OK;
}



kal_int32 rgb_rotator_drv_init(void)
{
   g2dInit();

   return 0;
}



kal_int32 rgb_rotator_drv_open(void)
{
   kal_int32 ret = 0;

   /// open
   if(G2D_STATUS_OK != g2dGetHandle(&_rgb_rotator_g2d_hw_handle, G2D_CODEC_TYPE_HW, G2D_GET_HANDLE_MODE_DIRECT_RETURN_HANDLE))
   {
      ret = -1;
   }

   return ret;
}



kal_int32 rgb_rotator_drv_close(void)
{
   kal_int32 ret = 0;

   /// close rotator
   if(G2D_STATUS_OK != g2dReleaseHandle(_rgb_rotator_g2d_hw_handle))
   {
      ret = -1;
   }

   return ret;
}



kal_int32 rgb_rotator_drv_start(RGB_ROTATOR_HANDLE_STRUCT *handle)
{
   RGB_ROTATOR_WINDOW_STRUCT *dstClipWindow = &(handle->dstClipWindow);
   RGB_ROTATOR_WINDOW_STRUCT *dstWindow = &(handle->dstWindow);
   RGB_ROTATOR_WINDOW_STRUCT *srcWindow = &(handle->srcWindow);
   kal_uint32 colorToAvoid = handle->colorToAvoid;
   kal_uint32 colorToReplace = handle->colorToReplace;
   kal_bool colorReplaceEnable = handle->colorReplaceEnable;
   kal_uint8 colorAvoidA = 0, colorAvoidR = 0, colorAvoidG = 0, colorAvoidB = 0;
   kal_uint8 colorReplaceA = 0, colorReplaceR = 0, colorReplaceG = 0, colorReplaceB = 0;
   G2D_COLOR_FORMAT_ENUM dstColorFormat, srcColorFormat;
   G2D_STATUS_ENUM status;
   G2D_CW_ROTATE_ANGLE_ENUM rotation = G2D_CW_ROTATE_ANGLE_000;

   g2dSetCallbackFunction(_rgb_rotator_g2d_hw_handle ,handle->rgbRotatorCallback);

   switch(handle->srcColorFormat)
   {
      case ROTATOR_COLOR_FORMAT_ENUM_GRAY:
         dstColorFormat = G2D_COLOR_FORMAT_GRAY;
         srcColorFormat = G2D_COLOR_FORMAT_GRAY;
      break;
      case ROTATOR_COLOR_FORMAT_ENUM_RGB565:
         dstColorFormat = G2D_COLOR_FORMAT_RGB565;
         srcColorFormat = G2D_COLOR_FORMAT_RGB565;

         if(KAL_TRUE == colorReplaceEnable)
         {
            /// colorAvoidA = 0;
            colorAvoidR = RGB565_TO_RGB888_R(colorToAvoid);
            colorAvoidG = RGB565_TO_RGB888_G(colorToAvoid);
            colorAvoidB = RGB565_TO_RGB888_B(colorToAvoid);
            /// colorReplaceA = 0;
            colorReplaceR = RGB565_TO_RGB888_R(colorToReplace);
            colorReplaceG = RGB565_TO_RGB888_G(colorToReplace);
            colorReplaceB = RGB565_TO_RGB888_B(colorToReplace);
         }
      break;
      case ROTATOR_COLOR_FORMAT_ENUM_RGB888:
         dstColorFormat = G2D_COLOR_FORMAT_RGB888;
         srcColorFormat = G2D_COLOR_FORMAT_RGB888;

         if(KAL_TRUE == colorReplaceEnable)
         {
            /// colorAvoidA = 0;
            colorAvoidR = (colorToAvoid >> 16) & 0xFF;
            colorAvoidG = (colorToAvoid >> 8) & 0xFF;
            colorAvoidB = colorToAvoid & 0xFF;
            /// colorReplaceA = 0;
            colorReplaceR = (colorToReplace >> 16) & 0xFF;
            colorReplaceG = (colorToReplace >> 8) & 0xFF;
            colorReplaceB = colorToReplace & 0xFF;
         }
      break;
      case ROTATOR_COLOR_FORMAT_ENUM_BGR888:
         dstColorFormat = G2D_COLOR_FORMAT_BGR888;
         srcColorFormat = G2D_COLOR_FORMAT_BGR888;

         if(KAL_TRUE == colorReplaceEnable)
         {
            /// colorAvoidA = 0;
            colorAvoidB = (colorToAvoid >> 16) & 0xFF;
            colorAvoidG = (colorToAvoid >> 8) & 0xFF;
            colorAvoidR = colorToAvoid & 0xFF;
            /// colorReplaceA = 0;
            colorReplaceB = (colorToReplace >> 16) & 0xFF;
            colorReplaceG = (colorToReplace >> 8) & 0xFF;
            colorReplaceR = colorToReplace & 0xFF;
         }
      break;
      case ROTATOR_COLOR_FORMAT_ENUM_ARGB8888:
         dstColorFormat = G2D_COLOR_FORMAT_ARGB8888;
         srcColorFormat = G2D_COLOR_FORMAT_ARGB8888;

         if(KAL_TRUE == colorReplaceEnable)
         {
            colorAvoidA = (colorToAvoid >> 24) & 0xFF;
            colorAvoidR = (colorToAvoid >> 16) & 0xFF;
            colorAvoidG = (colorToAvoid >> 8) & 0xFF;
            colorAvoidB = colorToAvoid & 0xFF;
            colorReplaceA = (colorToReplace >> 24) & 0xFF;
            colorReplaceR = (colorToReplace >> 16) & 0xFF;
            colorReplaceG = (colorToReplace >> 8) & 0xFF;
            colorReplaceB = colorToReplace & 0xFF;
         }
      break;
      case ROTATOR_COLOR_FORMAT_ENUM_PARGB8888:
         dstColorFormat = G2D_COLOR_FORMAT_PARGB8888;
         srcColorFormat = G2D_COLOR_FORMAT_PARGB8888;

         if(KAL_TRUE == colorReplaceEnable)
         {
            colorAvoidA = (colorToAvoid >> 24) & 0xFF;
            colorAvoidR = (colorToAvoid >> 16) & 0xFF;
            colorAvoidG = (colorToAvoid >> 8) & 0xFF;
            colorAvoidB = colorToAvoid & 0xFF;
            colorReplaceA = (colorToReplace >> 24) & 0xFF;
            colorReplaceR = (colorToReplace >> 16) & 0xFF;
            colorReplaceG = (colorToReplace >> 8) & 0xFF;
            colorReplaceB = colorToReplace & 0xFF;
         }
      break;
      case ROTATOR_COLOR_FORMAT_ENUM_ARGB6666:
         dstColorFormat = G2D_COLOR_FORMAT_ARGB6666;
         srcColorFormat = G2D_COLOR_FORMAT_ARGB6666;

         if(KAL_TRUE == colorReplaceEnable)
         {
            colorAvoidA = (colorToAvoid >> 18) & 0x3F;
            colorAvoidR = (colorToAvoid >> 12) & 0x3F;
            colorAvoidG = (colorToAvoid >> 6) & 0x3F;
            colorAvoidB = colorToAvoid & 0x3F;
            colorReplaceA = (colorToReplace >> 18) & 0x3F;
            colorReplaceR = (colorToReplace >> 12) & 0x3F;
            colorReplaceG = (colorToReplace >> 6) & 0x3F;
            colorReplaceB = colorToReplace & 0x3F;
         }
      break;
      case ROTATOR_COLOR_FORMAT_ENUM_PARGB6666:
         dstColorFormat = G2D_COLOR_FORMAT_PARGB6666;
         srcColorFormat = G2D_COLOR_FORMAT_PARGB6666;

         if(KAL_TRUE == colorReplaceEnable)
         {
            colorAvoidA = (colorToAvoid >> 18) & 0x3F;
            colorAvoidR = (colorToAvoid >> 12) & 0x3F;
            colorAvoidG = (colorToAvoid >> 6) & 0x3F;
            colorAvoidB = colorToAvoid & 0x3F;
            colorReplaceA = (colorToReplace >> 18) & 0x3F;
            colorReplaceR = (colorToReplace >> 12) & 0x3F;
            colorReplaceG = (colorToReplace >> 6) & 0x3F;
            colorReplaceB = colorToReplace & 0x3F;
         }
      break;  
      default:
         return -1;
   }

   switch(handle->rotation)
   {
      case ROTATOR_CW_ROTATE_ANGLE_000:
         rotation = G2D_CW_ROTATE_ANGLE_000;
      break;
      case ROTATOR_CW_ROTATE_ANGLE_090:
         rotation = G2D_CW_ROTATE_ANGLE_090;
      break;
      case ROTATOR_CW_ROTATE_ANGLE_180:
         rotation = G2D_CW_ROTATE_ANGLE_180;
      break;
      case ROTATOR_CW_ROTATE_ANGLE_270:
         rotation = G2D_CW_ROTATE_ANGLE_270;
      break;
      case ROTATOR_CW_ROTATE_ANGLE_MIRROR_000:
         rotation = G2D_CW_ROTATE_ANGLE_MIRROR_000;
      break;
      case ROTATOR_CW_ROTATE_ANGLE_MIRROR_090:
         rotation = G2D_CW_ROTATE_ANGLE_MIRROR_090;
      break;
      case ROTATOR_CW_ROTATE_ANGLE_MIRROR_180:
         rotation = G2D_CW_ROTATE_ANGLE_MIRROR_180;
      break;
      case ROTATOR_CW_ROTATE_ANGLE_MIRROR_270:
         rotation = G2D_CW_ROTATE_ANGLE_MIRROR_270;
      break;
   }

   status = g2dSetDstRGBBufferInfo(_rgb_rotator_g2d_hw_handle, (kal_uint8 *)handle->dstBuffer, handle->dstBufferSize, handle->dstWidth, handle->dstHeight, dstColorFormat);
   if(G2D_STATUS_OK != status)
      return -1;

   g2dSetColorReplacement(_rgb_rotator_g2d_hw_handle, colorReplaceEnable, colorAvoidA, colorAvoidR, colorAvoidG, colorAvoidB, colorReplaceA, colorReplaceR, colorReplaceG, colorReplaceB);
   status = g2dSetDstClipWindow(_rgb_rotator_g2d_hw_handle, handle->dstClipWindowEnable, dstClipWindow->startX, dstClipWindow->startY, dstClipWindow->width, dstClipWindow->height);
   if(G2D_STATUS_OK != status)
      return -1;
   g2dSetSrcKey(_rgb_rotator_g2d_hw_handle, KAL_FALSE, 0, 0, 0, 0);

   status = g2dBitBltSetSrcRGBBufferInfo(_rgb_rotator_g2d_hw_handle, handle->srcBuffer, handle->srcBufferSize, handle->srcWidth, handle->srcHeight, srcColorFormat);
   if(G2D_STATUS_OK != status)
      return -1;
   status = g2dBitBltSetSrcWindow(_rgb_rotator_g2d_hw_handle, srcWindow->startX, srcWindow->startY, srcWindow->width, srcWindow->height);
   if(G2D_STATUS_OK != status)
      return -1;
   status = g2dBitBltSetDstWindow(_rgb_rotator_g2d_hw_handle, dstWindow->startX, dstWindow->startY, dstWindow->width, dstWindow->height);
   if(G2D_STATUS_OK != status)
      return -1;
   g2dBitBltSetRotation(_rgb_rotator_g2d_hw_handle, rotation);
   ///g2dBitBltSetSrcAlpha(_rgb_rotator_g2d_hw_handle, KAL_FALSE, 0x0);
   ///g2dBitBltSetDstAlpha(_rgb_rotator_g2d_hw_handle, KAL_FALSE, 0x0);
   status = g2dBitBltStart(_rgb_rotator_g2d_hw_handle);
   if(G2D_STATUS_OK != status)
      return -1;
   return 0;
}



kal_int32 rgb_rotator_drv_get_status(void)
{
   return g2dGetStatus(_rgb_rotator_g2d_hw_handle);
}

#endif


