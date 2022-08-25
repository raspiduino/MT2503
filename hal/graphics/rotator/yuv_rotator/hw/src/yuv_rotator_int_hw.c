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
 *   yuv_rotator_int_hw.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   YUV Rotator
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

#if defined(YUV_ROTATOR_HW_SUPPORT)

#include "kal_general_types.h"

#include "rotator_enum.h"

#include "yuv_rotator_structure.h"

#include "iul_csc_macros.h"

#include "g2d_enum.h"
#include "g2d_common_api.h"
#include "g2d_bitblt_api.h"

static G2D_HANDLE_STRUCT *_yuv_rotator_g2d_hw_handle;

ROTATOR_STATUS_ENUM yuv_rotator_drv_query_working_memory(YUV_ROTATOR_HANDLE_STRUCT *handle, kal_uint32 *intMemBest, kal_uint32 *intMemMin,
                                                                                            kal_uint32 *extMemBest, kal_uint32 *extMemMin)
{
   *intMemBest = 0;
   *intMemMin = 0;
   *extMemBest = 0;
   *extMemMin = 0;

   return ROTATOR_STATUS_OK;
}



kal_int32 yuv_rotator_drv_init(void)
{
   g2dInit();

   return 0;
}



kal_int32 yuv_rotator_drv_open(void)
{
   kal_int32 ret = 0;

   /// open
   if(G2D_STATUS_OK != g2dGetHandle(&_yuv_rotator_g2d_hw_handle, G2D_CODEC_TYPE_HW, G2D_GET_HANDLE_MODE_DIRECT_RETURN_HANDLE))
   {
      ret = -1;
   }

   return ret;
}



kal_int32 yuv_rotator_drv_close(void)
{
   kal_int32 ret = 0;

   /// close rotator
   if(G2D_STATUS_OK != g2dReleaseHandle(_yuv_rotator_g2d_hw_handle))
   {
      ret = -1;
   }

   return ret;
}



kal_int32 yuv_rotator_drv_start(YUV_ROTATOR_HANDLE_STRUCT *handle)
{
   YUV_ROTATOR_WINDOW_STRUCT *dstWindow = &(handle->dstWindow);
   YUV_ROTATOR_WINDOW_STRUCT *srcWindow = &(handle->srcWindow);

   G2D_COLOR_FORMAT_ENUM dstColorFormat, srcColorFormat;
   G2D_STATUS_ENUM status;
   G2D_CW_ROTATE_ANGLE_ENUM rotation = G2D_CW_ROTATE_ANGLE_000;

   g2dSetCallbackFunction(_yuv_rotator_g2d_hw_handle ,handle->yuvRotatorCallback);

   switch(handle->srcColorFormat)
   {
      case ROTATOR_COLOR_FORMAT_ENUM_YUV420_P:
         dstColorFormat = G2D_COLOR_FORMAT_GRAY;
         srcColorFormat = G2D_COLOR_FORMAT_GRAY;
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

   ///Y
   status = g2dSetDstRGBBufferInfo(_yuv_rotator_g2d_hw_handle, (kal_uint8 *)handle->dstBuffer[0], handle->dstBufferSize[0], handle->dstWidth, handle->dstHeight, dstColorFormat);
   if(G2D_STATUS_OK != status)
      return -1;

   g2dSetColorReplacement(_yuv_rotator_g2d_hw_handle, KAL_FALSE, 0, 0, 0, 0, 0, 0, 0, 0);
   g2dSetDstClipWindow(_yuv_rotator_g2d_hw_handle, KAL_FALSE, 0, 0, 0, 0);
   g2dSetSrcKey(_yuv_rotator_g2d_hw_handle, KAL_FALSE, 0, 0, 0, 0);

   status = g2dBitBltSetSrcRGBBufferInfo(_yuv_rotator_g2d_hw_handle, handle->srcBuffer[0], handle->srcBufferSize[0], handle->srcWidth, handle->srcHeight, srcColorFormat);
   if(G2D_STATUS_OK != status)
      return -1;
   status = g2dBitBltSetSrcWindow(_yuv_rotator_g2d_hw_handle, srcWindow->startX, srcWindow->startY, srcWindow->width, srcWindow->height);
   if(G2D_STATUS_OK != status)
      return -1;
   status = g2dBitBltSetDstWindow(_yuv_rotator_g2d_hw_handle, dstWindow->startX, dstWindow->startY, dstWindow->width, dstWindow->height);
   if(G2D_STATUS_OK != status)
      return -1;
   g2dBitBltSetRotation(_yuv_rotator_g2d_hw_handle, rotation);
   status = g2dBitBltStart(_yuv_rotator_g2d_hw_handle);
   if(G2D_STATUS_OK != status)
      return -1;

   while(g2dGetStatus(_yuv_rotator_g2d_hw_handle)) {};

   ///U
   status = g2dSetDstRGBBufferInfo(_yuv_rotator_g2d_hw_handle, (kal_uint8 *)handle->dstBuffer[1], handle->dstBufferSize[1], (handle->dstWidth) >> 1, (handle->dstHeight) >> 1, dstColorFormat);
   if(G2D_STATUS_OK != status)
      return -1;
   status = g2dBitBltSetSrcRGBBufferInfo(_yuv_rotator_g2d_hw_handle, handle->srcBuffer[1], handle->srcBufferSize[1], (handle->srcWidth) >> 1, (handle->srcHeight) >> 1, srcColorFormat);
   if(G2D_STATUS_OK != status)
      return -1;
   status = g2dBitBltSetSrcWindow(_yuv_rotator_g2d_hw_handle, srcWindow->startX, srcWindow->startY, (srcWindow->width) >> 1, (srcWindow->height) >> 1);
   if(G2D_STATUS_OK != status)
      return -1;
   status = g2dBitBltSetDstWindow(_yuv_rotator_g2d_hw_handle, dstWindow->startX, dstWindow->startY, (dstWindow->width) >> 1, (dstWindow->height) >> 1);
   if(G2D_STATUS_OK != status)
      return -1;
   ///g2dBitBltSetRotation(_yuv_rotator_g2d_hw_handle, rotation);
   status = g2dBitBltStart(_yuv_rotator_g2d_hw_handle);
   if(G2D_STATUS_OK != status)
      return -1;

   while(g2dGetStatus(_yuv_rotator_g2d_hw_handle)) {};

   ///V
   status = g2dSetDstRGBBufferInfo(_yuv_rotator_g2d_hw_handle, (kal_uint8 *)handle->dstBuffer[2], handle->dstBufferSize[2], (handle->dstWidth) >> 1, (handle->dstHeight) >> 1, dstColorFormat);
   if(G2D_STATUS_OK != status)
      return -1;
   status = g2dBitBltSetSrcRGBBufferInfo(_yuv_rotator_g2d_hw_handle, handle->srcBuffer[2], handle->srcBufferSize[2], (handle->srcWidth) >> 1, (handle->srcHeight) >> 1, srcColorFormat);
   if(G2D_STATUS_OK != status)
      return -1;
   status = g2dBitBltSetSrcWindow(_yuv_rotator_g2d_hw_handle, srcWindow->startX, srcWindow->startY, (srcWindow->width) >> 1, (srcWindow->height) >> 1);
   if(G2D_STATUS_OK != status)
      return -1;
   status = g2dBitBltSetDstWindow(_yuv_rotator_g2d_hw_handle, dstWindow->startX, dstWindow->startY, (dstWindow->width) >> 1, (dstWindow->height) >> 1);
   if(G2D_STATUS_OK != status)
      return -1;
   ///g2dBitBltSetRotation(_yuv_rotator_g2d_hw_handle, rotation);
   status = g2dBitBltStart(_yuv_rotator_g2d_hw_handle);

   while(g2dGetStatus(_yuv_rotator_g2d_hw_handle)) {};

   if(G2D_STATUS_OK != status)
      return -1;
   return 0;
}



kal_int32 yuv_rotator_drv_get_status(void)
{
   return g2dGetStatus(_yuv_rotator_g2d_hw_handle);
}

#endif


