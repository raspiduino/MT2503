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
 *   jpeg_encode_api.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Code body of JPEG codec unified interface (encode).
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
#include "drv_features_jpeg.h"

#include "kal_general_types.h"

#include "jpeg_enum.h"
#include "jpeg_encode_structure.h"
#include "jpeg_misc_api.h"

#if defined(JPG_ENCODE)

#include "string.h"

#include "jpeg_encode_int.h"
#include "jpeg_drv_api.h"

#include "swje_structure.h"

#include "fsal.h"

#include "iul_x_math.h"

#if defined(JPEG_CODEC_STANDALONE)
   #include <assert.h>
   #if !defined(ASSERT)
      #define ASSERT assert
   #endif
   #include <stdlib.h>
#else
   #include "kal_public_defs.h"
   #include "kal_public_api.h"
   #include "drv_gfx_stack_switch_manager.h"

   #include "cache_sw.h"

   #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
      #include "mmu.h"
   #endif

   #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)   
      #include "drv_gfx_dynamic_switch.h"
   #endif

   #if defined(__MTK_TARGET__)
      #include "idp_jpeg_encode.h"
      #include "idp_camera_capture_to_jpeg.h"
      #include "img_common_enum.h"

      #include "mm_intmem.h"

      extern kal_uint32 INT_SwitchStackToRun(void *stack_start, kal_uint32 stack_size, kal_func_ptr func, kal_uint32 argc, ...);
      extern kal_bool INT_QueryExceptionStatus(void);
   #endif
#endif


JPEG_STATUS_ENUM jpegEncGetEncoder(JPEG_CODEC_TYPE_ENUM codecType, JPEG_ENCODER_HANDLE *handlePtr)
{
   JPEG_STATUS_ENUM status = JPEG_STATUS_OK;
   
#if defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SEPARATED_FROM_MDP__) || defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_ENCODE_SUPPORTED__)
   if (JPEG_CODEC_TYPE_HW == codecType)
   {
      *handlePtr = NULL;
      return JPEG_STATUS_CODEC_UNAVAILABLE;
   }
#endif

   status = jpeg_enc_get_encoder(codecType, handlePtr);

   return status;
}



JPEG_STATUS_ENUM jpegEncReleaseEncoder(JPEG_ENCODER_HANDLE handle)
{
   JPEG_STATUS_ENUM status = JPEG_STATUS_OK;

   if (0 != jpeg_enc_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   status = jpeg_enc_release_encoder(handle);

   return status;
}



JPEG_STATUS_ENUM jpegEncSetSrcMode(JPEG_ENCODER_HANDLE handle, JPEG_ENCODE_SOURCE_ENUM srcMode)
{
   if (0 != jpeg_enc_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }


   if (JPEG_ENCODE_SOURCE_UNSUPPORTED == srcMode)
   {
      handle->lastStatus = JPEG_STATUS_INVALID_OPERATION;
      return handle->lastStatus;
   }

   handle->srcMode = srcMode;

   switch (handle->codecType)
   {
      #if defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SUPPORTED__)
         case JPEG_CODEC_TYPE_HW:
         {
            #if defined(__MTK_TARGET__)
#if (!defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SEPARATED_FROM_MDP__)) && (!defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_ENCODE_SUPPORTED__))
               if (JPEG_ENCODE_SOURCE_ISP != srcMode)
               {
                  /// In the JPEG encode (from buffer) case, the IDP is controlled by JPEG.
                  handle->idp_open_func = idp_jpeg_encode_open_wrapper;
                  handle->idp_close_func = idp_jpeg_encode_close;
                  handle->idp_config_func = idp_jpeg_encode_config_wrapper;
                  handle->idp_start_output_func = idp_jpeg_encode_start_output;
                  handle->idp_start_all_func = idp_jpeg_encode_start_all;
               }
               else
#endif
               {
                  /// In the camera capture to JPEG path, the IDP is controlled outside JPEG,
                  /// thus we hook dummy functions here.
                  handle->idp_open_func = idp_dummy_open;
                  handle->idp_close_func = idp_dummy_others;
                  handle->idp_config_func = idp_dummy_config;
                  handle->idp_start_output_func = idp_dummy_others;
                  handle->idp_start_all_func = idp_dummy_others;
               }
#endif /// __MTK_TARGET__
         }
         break;
      #endif
      #if defined(__SW_JPEG_ENCODER_SUPPORT__)
         case JPEG_CODEC_TYPE_SW:
            if (JPEG_ENCODE_SOURCE_ISP == srcMode)
            {
               handle->lastStatus = JPEG_STATUS_INVALID_OPERATION;
               return handle->lastStatus;
            }
         break;
      #endif
      default:
         ASSERT(0);
   }

   handle->lastStatus = JPEG_STATUS_OK;
   return handle->lastStatus;
}



JPEG_STATUS_ENUM jpegEncSetSrcWindow(JPEG_ENCODER_HANDLE handle, MY_RECTANGLE* srcWindow)
{
   if (0 != jpeg_enc_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }
   if (!srcWindow)
   {
      return JPEG_STATUS_INVALID_PARAMETER;
   }
   if (0 == srcWindow->w * srcWindow->h)
   {
      return JPEG_STATUS_INVALID_PARAMETER;
   }

   memcpy(&(handle->srcWindow), srcWindow, sizeof(MY_RECTANGLE));

   handle->lastStatus = JPEG_STATUS_OK;
   return handle->lastStatus;
}



JPEG_STATUS_ENUM jpegEncSetSrcDimension(JPEG_ENCODER_HANDLE handle, kal_uint32 width, kal_uint32 height)
{
   if (0 != jpeg_enc_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   if (0 == width * height)
   {
      handle->lastStatus = JPEG_STATUS_INVALID_OPERATION;
   }
   else if(width > 65535)
   {
      handle->lastStatus = JPEG_STATUS_ENC_ERROR_SIZE_OVERFLOW;
   }
   else if(height > 65535)
   {
      handle->lastStatus = JPEG_STATUS_ENC_ERROR_SIZE_OVERFLOW;
   }
   else
   {
      handle->srcWidth = width;
      handle->srcHeight = height;
      handle->lastStatus = JPEG_STATUS_OK;
   }
   return handle->lastStatus;
}



JPEG_STATUS_ENUM jpegEncGetSrcDimension(JPEG_ENCODER_HANDLE handle, kal_uint32* width, kal_uint32* height)
{
   if (0 != jpeg_enc_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   *width = handle->srcWidth;
   *height = handle->srcHeight;
   return JPEG_STATUS_OK;
}



JPEG_STATUS_ENUM jpegEncSetSrcRGBFormat(JPEG_ENCODER_HANDLE handle, JPEG_RGB_FORMAT_ENUM rgbFormat)
{
   if (0 != jpeg_enc_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   switch (handle->srcMode)
   {
      case JPEG_ENCODE_SOURCE_ISP:
      case JPEG_ENCODE_SOURCE_UNSUPPORTED:
      case JPEG_ENCODE_SOURCE_YUV_BUFFER:
         handle->lastStatus = JPEG_STATUS_INVALID_OPERATION;
      break;
      default:
         handle->srcRGBFormat = rgbFormat;
         handle->lastStatus = JPEG_STATUS_OK;
      break;
   }

   return handle->lastStatus;
}



JPEG_STATUS_ENUM jpegEncSetRGBBuffer(JPEG_ENCODER_HANDLE handle, void *buffer, kal_uint32 bufferSize)
{
   if (0 != jpeg_enc_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   switch (handle->srcMode)
   {
      case JPEG_ENCODE_SOURCE_ISP:
      case JPEG_ENCODE_SOURCE_UNSUPPORTED:
      case JPEG_ENCODE_SOURCE_YUV_BUFFER:
         handle->lastStatus = JPEG_STATUS_INVALID_OPERATION;
      break;
      default:
      {
         #if (defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__))
            if(JPEG_CODEC_TYPE_HW == handle->codecType)
            {
               if (INT_QueryIsCachedRAM((kal_uint32)buffer, 4))
               {
                  ASSERT(0);
               }
            }
         #endif /// __DYNAMIC_SWITCH_CACHEABILITY__
         handle->srcRGBBuffer = buffer;
         handle->srcBufferSize[0] = bufferSize;
         handle->srcBufferSize[1] = 0;
         handle->srcBufferSize[2] = 0;
         handle->lastStatus = JPEG_STATUS_OK;
      }
      break;
   }

   return handle->lastStatus;
}



JPEG_STATUS_ENUM jpegEncSetSrcYUVFormat(JPEG_ENCODER_HANDLE handle, JPEG_YUV_FORMAT_ENUM yuvFormat)
{
   if (0 != jpeg_enc_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   switch (handle->srcMode)
   {
      case JPEG_ENCODE_SOURCE_ISP:
      case JPEG_ENCODE_SOURCE_UNSUPPORTED:
      case JPEG_ENCODE_SOURCE_RGB_BUFFER:
         handle->lastStatus = JPEG_STATUS_INVALID_OPERATION;
      break;
      default:
         handle->srcSamplingFormat = yuvFormat;
         handle->lastStatus = JPEG_STATUS_OK;
      break;
   }

   return handle->lastStatus;
}



JPEG_STATUS_ENUM jpegEncSetYUVBuffer(JPEG_ENCODER_HANDLE handle,
                                     void *yBuffer, void *uBuffer, void *vBuffer,
                                     kal_uint32 yBufferSize, kal_uint32 uBufferSize, kal_uint32 vBufferSize)
{
   if (0 != jpeg_enc_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   switch (handle->srcMode)
   {
      case JPEG_ENCODE_SOURCE_ISP:
      case JPEG_ENCODE_SOURCE_UNSUPPORTED:
      case JPEG_ENCODE_SOURCE_RGB_BUFFER:
         handle->lastStatus = JPEG_STATUS_INVALID_OPERATION;
      break;
      default:
      {
         /// For JPEG_YUV_FORMAT_PACKED_UYVY422, only handle->srcYBuffer is in use.
         handle->srcYUVBuffer[0] = yBuffer;
         handle->srcYUVBuffer[1] = uBuffer;
         handle->srcYUVBuffer[2] = vBuffer;
         handle->srcBufferSize[0] = yBufferSize;
         handle->srcBufferSize[1] = uBufferSize;
         handle->srcBufferSize[2] = vBufferSize;
         handle->lastStatus = JPEG_STATUS_OK;
      }
      break;
   }

   return handle->lastStatus;
}



JPEG_STATUS_ENUM jpegEncSetDstQuality(JPEG_ENCODER_HANDLE handle, JPEG_ENCODE_QUALITTY_ENUM quality)
{
   if (0 != jpeg_enc_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   handle->dstQuality = quality;
   handle->lastStatus = JPEG_STATUS_OK;
   return handle->lastStatus;
}



JPEG_STATUS_ENUM jpegEncSetDstFileFormat(JPEG_ENCODER_HANDLE handle, JPEG_FILE_FORMAT_ENUM format)
{
   if (0 != jpeg_enc_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   handle->dstFileFormat = format;
   handle->lastStatus = JPEG_STATUS_OK;
   return handle->lastStatus;
}



JPEG_STATUS_ENUM jpegEncSetDstThumbnail(JPEG_ENCODER_HANDLE handle, kal_bool enable, kal_uint32 width, kal_uint32 height)
{
   if (0 != jpeg_enc_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   ASSERT(KAL_FALSE == enable);

   handle->enableThumbnail = enable;
   handle->lastStatus = JPEG_STATUS_OK;

   return handle->lastStatus;
}



JPEG_STATUS_ENUM jpegEncSetDstDimension(JPEG_ENCODER_HANDLE handle, kal_uint32 width, kal_uint32 height)
{
   if (0 != jpeg_enc_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   if (0 == width * height)
   {
      handle->lastStatus = JPEG_STATUS_INVALID_OPERATION;
   }
   else if(width > 65535)
   {
      handle->lastStatus = JPEG_STATUS_ENC_ERROR_SIZE_OVERFLOW;
   }
   else if(height > 65535)
   {
      handle->lastStatus = JPEG_STATUS_ENC_ERROR_SIZE_OVERFLOW;
   }
   else
   {
      JPEG_ENCODE_INFO* const mainEncodeInfo = &(handle->mainEncodeInfo);

      mainEncodeInfo->dstWidth = width;
      mainEncodeInfo->dstHeight = height;
      handle->lastStatus = JPEG_STATUS_OK;
   }
   return handle->lastStatus;
}



JPEG_STATUS_ENUM jpegEncSetDstSampleFormat(JPEG_ENCODER_HANDLE handle, JPEG_YUV_FORMAT_ENUM sampleFormat)
{
   JPEG_GENGERAL_ENCODE_INFO* const gengralEncodeInfo = &(handle->gengralEncodeInfo);

   if (0 != jpeg_enc_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   handle->dstSamplingFormat = sampleFormat;

   switch(sampleFormat)
   {
      case JPEG_YUV_FORMAT_YUV420:
      {
         gengralEncodeInfo->numComponent = 3;
         gengralEncodeInfo->hSamplingFactor[0] = 2;
         gengralEncodeInfo->hSamplingFactor[1] = 1;
         gengralEncodeInfo->hSamplingFactor[2] = 1;
         gengralEncodeInfo->hSamplingFactorMax = 2;

         gengralEncodeInfo->vSamplingFactor[0] = 2;
         gengralEncodeInfo->vSamplingFactor[1] = 1;
         gengralEncodeInfo->vSamplingFactor[2] = 1;
         gengralEncodeInfo->vSamplingFactorMax = 2;
      }
      break;
      #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_DST_YUV422)
         case JPEG_YUV_FORMAT_YUV422:
         {
            gengralEncodeInfo->numComponent = 3;
            gengralEncodeInfo->hSamplingFactor[0] = 2;
            gengralEncodeInfo->hSamplingFactor[1] = 1;
            gengralEncodeInfo->hSamplingFactor[2] = 1;
            gengralEncodeInfo->hSamplingFactorMax = 2;

            gengralEncodeInfo->vSamplingFactor[0] = 1;
            gengralEncodeInfo->vSamplingFactor[1] = 1;
            gengralEncodeInfo->vSamplingFactor[2] = 1;
            gengralEncodeInfo->vSamplingFactorMax = 1;
         }
         break;
      #endif
      default:
         ASSERT(0);
   }

   handle->lastStatus = JPEG_STATUS_OK;
   return handle->lastStatus;
}



JPEG_STATUS_ENUM jpegEncSetDstBuffer(JPEG_ENCODER_HANDLE handle, void *bufferAddr, kal_uint32 bufferSize)
{
   if (0 != jpeg_enc_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   handle->lastStatus = JPEG_STATUS_OK;

   if(NULL == (handle->dstFile.pDstFileHandle))
   {
      if (0 == bufferAddr || 0 == bufferSize)
      {
         handle->lastStatus = JPEG_STATUS_INVALID_OPERATION;
      }
      else
      {
         SWJE_FILE *dstFile = &(handle->dstFile);
         #if (defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__))
            if(JPEG_CODEC_TYPE_HW == handle->codecType)
            {
               if (INT_QueryIsCachedRAM((kal_uint32)bufferAddr, bufferSize))
               {
                  ASSERT(0);
               }
            }
         #endif /// __DYNAMIC_SWITCH_CACHEABILITY__

         dstFile->dstBufferAddr = bufferAddr;
         dstFile->dstWritePtr = bufferAddr;
         dstFile->dstBufferSize = bufferSize;
         dstFile->dstBufferLeft = bufferSize;
         dstFile->dstFileSize = 0;
      }
   }

   return handle->lastStatus;
}



JPEG_STATUS_ENUM jpegEncSetDirectFileOutputHandle(JPEG_ENCODER_HANDLE handle, STFSAL *fp)
{
   if (0 != jpeg_enc_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   /// NULL == fp means no direct file output
   switch (handle->codecType)
   {
      #if defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SUPPORTED__)
         case JPEG_CODEC_TYPE_HW:
            /// We do not support direct file output in HW JPEG Encoder
            ASSERT(NULL == fp);
         break;
      #endif /// __DRV_GRAPHICS_HW_JPEG_ENCODE_SUPPORTED__
      #if defined(__SW_JPEG_ENCODER_SUPPORT__)
         case JPEG_CODEC_TYPE_SW:
         {
            if(NULL != fp)
            {
               SWJE_FILE *dstFile = &(handle->dstFile);

               dstFile->pDstFileHandle = fp;
               dstFile->dstBufferAddr = fp->pbBuf;
               dstFile->dstWritePtr = fp->pbBuf;
               dstFile->dstBufferSize = fp->uBufSize;
               dstFile->dstBufferLeft = fp->uBufSize;
               dstFile->dstFileSize = 0;
               FSAL_SetBuffer(fp, 0, NULL);
            }
         }
         break;
      #endif
      default:
         ASSERT(0);
   }

   handle->lastStatus = JPEG_STATUS_OK;

   return handle->lastStatus;
}



JPEG_STATUS_ENUM jpegEncSetCallbackFunction(JPEG_ENCODER_HANDLE handle, kal_int32 (*callback_function)(JPEG_CODEC_STATE_ENUM state))
{
   if (0 != jpeg_enc_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   handle->callback_function = callback_function;
   handle->lastStatus = JPEG_STATUS_OK;
   return handle->lastStatus;
}



JPEG_STATUS_ENUM jpegEncGetEncoderState(JPEG_ENCODER_HANDLE handle, JPEG_CODEC_STATE_ENUM *state)
{
   if (0 != jpeg_enc_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   *state = handle->codecState;

   return JPEG_STATUS_OK;
}



JPEG_STATUS_ENUM jpegEncSetRotation(JPEG_ENCODER_HANDLE handle, JPEG_ENCODE_ROTATE_ANGLE_ENUM angle)
{
   if (0 != jpeg_enc_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   handle->rotation = angle;
   handle->lastStatus = JPEG_STATUS_OK;

   return JPEG_STATUS_OK;
}



JPEG_STATUS_ENUM jpegEncSetCheckAbortFunction(JPEG_ENCODER_HANDLE handle,
                                              kal_int32 (*check_abort_func)(void))
{
   if (0 != jpeg_enc_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   switch (handle->codecType)
   {
      #if defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SUPPORTED__)
         case JPEG_CODEC_TYPE_HW:
            handle->check_abort_func = NULL;
            handle->lastStatus = JPEG_STATUS_INVALID_OPERATION;
         break;
      #endif
      #if defined(__SW_JPEG_ENCODER_SUPPORT__)
         case JPEG_CODEC_TYPE_SW:
            handle->check_abort_func = check_abort_func;
            handle->lastStatus = JPEG_STATUS_OK;
         break;
      #endif
      default:
         ASSERT(0);
   }

   return handle->lastStatus;
}



JPEG_STATUS_ENUM jpegEncSetDynamicQuantAdjustment(JPEG_ENCODER_HANDLE handle, kal_bool enable)

{
   #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_DYNAMIC_QUALITY_ADJUSTMENT)
      if (0 != jpeg_enc_check_handle(handle))
      {
         return JPEG_STATUS_INVALID_HANDLE;
      }

      handle->lastStatus = JPEG_STATUS_OK;

      handle->enableDynamicQuantAdjustment = enable;
      handle->quantScaleFactor = 1.0;

      return handle->lastStatus;
   #else
      handle->lastStatus = JPEG_STATUS_INVALID_OPERATION;

      return handle->lastStatus;
   #endif
}



JPEG_STATUS_ENUM jpegEncStart(JPEG_ENCODER_HANDLE handle)
{
   JPEG_ENCODE_INFO* const mainEncodeInfo = &(handle->mainEncodeInfo);
   SWJE_FILE *dstFile = &(handle->dstFile);
   MY_RECTANGLE* srcWindow = &(handle->srcWindow);

   if (0 != jpeg_enc_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   // add source window parameter check for safety
   if ((srcWindow->x < 0) || ((srcWindow->x + srcWindow->w) > handle->srcWidth))
   {
      handle->lastStatus = JPEG_STATUS_ENC_ERROR_SIZE_OVERFLOW;
      return handle->lastStatus;
   }
   if ((srcWindow->y < 0) || ((srcWindow->y + srcWindow->h) > handle->srcHeight))
   {
      handle->lastStatus = JPEG_STATUS_ENC_ERROR_SIZE_OVERFLOW;
      return handle->lastStatus;
   }
#if defined(__SW_JPEG_ENCODER_SUPPORT__)
   // not support sw partial encode yet ...
   if ((JPEG_CODEC_TYPE_SW == handle->codecType)
      && (0 != srcWindow->w * srcWindow->h)
      && ((handle->srcWidth != srcWindow->w) || (handle->srcHeight != srcWindow->h))
      )
   {
      handle->lastStatus = JPEG_STATUS_ENC_ERROR_NOT_UNSUPPORT_SW;
      return handle->lastStatus;
   }
#endif

   ///ASSERT(JPEG_CODEC_STATE_IDLE == handle->codecState);
   handle->lastStatus = JPEG_STATUS_OK;

   /// Basic check...
   ASSERT(mainEncodeInfo->dstWidth * mainEncodeInfo->dstHeight);
   ASSERT(handle->srcWidth * handle->srcHeight);

   if(NULL == (dstFile->pDstFileHandle))
   {
      ASSERT(dstFile->dstBufferAddr);
      ASSERT(dstFile->dstBufferSize);
   }
   ///ASSERT((dstFile->dstBufferLeft) == (dstFile->dstBufferSize));

   ASSERT(JPEG_ENCODE_SOURCE_UNSUPPORTED != handle->srcMode);
   ASSERT(JPEG_YUV_FORMAT_UNSUPPORTED != handle->dstSamplingFormat);
   if((JPEG_YUV_FORMAT_PACKED_UYVY422 == handle->srcSamplingFormat) && (KAL_TRUE == handle->enableThumbnail))
   {
      ASSERT(0);
   }

   if(JPEG_ENCODE_SOURCE_YUV_BUFFER == (handle->srcMode))
   {
      /// ASSERT(handle->srcSamplingFormat == handle->dstSamplingFormat);

      if(JPEG_YUV_FORMAT_YUV420 == (handle->dstSamplingFormat))
      {
         ASSERT( 0 == ((handle->srcWidth) & 0x1));
         ASSERT( 0 == ((handle->srcHeight) & 0x1));
         ASSERT( 0 == ((mainEncodeInfo->dstWidth) & 0x1));
         ASSERT( 0 == ((mainEncodeInfo->dstHeight) & 0x1));
      }
      #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_DST_YUV422)
         else if(JPEG_YUV_FORMAT_YUV422 == (handle->dstSamplingFormat))
         {
            ASSERT( 0 == ((handle->srcWidth) & 0x1));
            ASSERT( 0 == ((mainEncodeInfo->dstWidth) & 0x1));
         }
      #endif
   }

   #if defined(__MM_DEBUG_MEASURE__)
/* under construction !*/
   #endif

#if defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SEPARATED_FROM_MDP__)
   if (JPEG_CODEC_TYPE_SW == handle->codecType)
   {
      kal_uint32 enterAcceleator = 1;

      // check color format
      if (JPEG_ENCODE_SOURCE_YUV_BUFFER == handle->srcMode)
      {
         if (JPEG_YUV_FORMAT_YUV420 != handle->srcSamplingFormat)
         {
            enterAcceleator = 0;
         }
         if (JPEG_YUV_FORMAT_YUV420 != handle->dstSamplingFormat)
         {
            enterAcceleator = 0;
         }
      }
      else
      {
         enterAcceleator= 0;
      }

      // check resize
      if ((handle->srcWidth == mainEncodeInfo->dstWidth) && (handle->srcHeight == mainEncodeInfo->dstHeight))
      {
         // check mcu boundary
         if ((handle->srcWidth & 15) || (handle->srcHeight & 15))
         {
            enterAcceleator= 0;
         }
      }
      else
      {
         enterAcceleator= 0;
      }

      // check rotate angle
      if (JPEG_ENCODE_ROTATE_ANGLE_000 != handle->rotation)
      {
         enterAcceleator= 0;
      }

      // check dynamic quality adjustment
   #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_DYNAMIC_QUALITY_ADJUSTMENT)
      if (KAL_TRUE == handle->enableDynamicQuantAdjustment)
      {
         enterAcceleator= 0;
      }
   #endif

      // enter accelator
      if (enterAcceleator)
      {
         #if (defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__))
         {
            // switch source buffer
            if ((IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(handle->srcYUVBuffer[0]))) &&
               (IS_CACHE_LINE_SIZE_ALIGNED(handle->srcBufferSize[0])) &&
               (is_predef_dyna_c_region((kal_uint32)(handle->srcYUVBuffer[0]), handle->srcBufferSize[0])) &&
               (IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(handle->srcYUVBuffer[1]))) &&
               (IS_CACHE_LINE_SIZE_ALIGNED(handle->srcBufferSize[1])) &&
               (is_predef_dyna_c_region((kal_uint32)(handle->srcYUVBuffer[1]), handle->srcBufferSize[1])) &&
               (IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(handle->srcYUVBuffer[2]))) &&
               (IS_CACHE_LINE_SIZE_ALIGNED(handle->srcBufferSize[2])) &&
               (is_predef_dyna_c_region((kal_uint32)(handle->srcYUVBuffer[2]), handle->srcBufferSize[2])))
            {
               if((KAL_TRUE == INT_QueryIsCachedRAM(handle->srcYUVBuffer[0], handle->srcBufferSize[0])) &&
                  (KAL_TRUE == INT_QueryIsCachedRAM(handle->srcYUVBuffer[1], handle->srcBufferSize[1])) &&
                  (KAL_TRUE == INT_QueryIsCachedRAM(handle->srcYUVBuffer[2], handle->srcBufferSize[2])))
               {
                  dynamic_switch_cacheable_region((void*)&(handle->srcYUVBuffer[0]), handle->srcBufferSize[0], PAGE_NO_CACHE);
                  dynamic_switch_cacheable_region((void*)&(handle->srcYUVBuffer[1]), handle->srcBufferSize[1], PAGE_NO_CACHE);
                  dynamic_switch_cacheable_region((void*)&(handle->srcYUVBuffer[2]), handle->srcBufferSize[2], PAGE_NO_CACHE);
                  handle->enableSrcDynamicSwitch = KAL_TRUE;
               }
            }
            else
            {
               enterAcceleator = 0;
            }

            // switch destination buffer
            if ((IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)dstFile->dstBufferAddr)) &&
               (IS_CACHE_LINE_SIZE_ALIGNED(dstFile->dstBufferSize)) &&
               (is_predef_dyna_c_region((kal_uint32)dstFile->dstBufferAddr, dstFile->dstBufferSize)) &&
               (IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)dstFile->dstWritePtr)) &&
               (IS_CACHE_LINE_SIZE_ALIGNED(dstFile->dstBufferLeft)) &&
               (is_predef_dyna_c_region((kal_uint32)dstFile->dstWritePtr, dstFile->dstBufferLeft)))
            {
               if((KAL_TRUE == INT_QueryIsCachedRAM(dstFile->dstBufferAddr, dstFile->dstBufferSize)) &&
                  (KAL_TRUE == INT_QueryIsCachedRAM(dstFile->dstWritePtr, dstFile->dstBufferLeft)))
               {
                  dynamic_switch_cacheable_region((void*)&(dstFile->dstBufferAddr), dstFile->dstBufferSize, PAGE_NO_CACHE);
                  dynamic_switch_cacheable_region((void*)&(dstFile->dstWritePtr), dstFile->dstBufferLeft, PAGE_NO_CACHE);
                  handle->enableDstDynamicSwitch = KAL_TRUE;
               }
            }
            else
            {
               enterAcceleator = 0;
            }
         }
         #endif

         if (enterAcceleator)
         {
            // get hw encoder      
            if (0 == handle->hwAcceleratorHandle)
            {
               if (JPEG_STATUS_OK == jpeg_enc_get_encoder(JPEG_CODEC_TYPE_HW, (JPEG_ENCODER_HANDLE *)&(handle->hwAcceleratorHandle)))
               {
                  handle->codecType = JPEG_CODEC_TYPE_HW;
               }
            }
         }
      }
   }
#elif defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_ENCODE_SUPPORTED__)
   if (JPEG_CODEC_TYPE_SW == handle->codecType)
   {
      // get hw encoder      
      if (0 == handle->hwAcceleratorHandle)
      {
         if (JPEG_STATUS_OK == jpeg_enc_get_encoder(JPEG_CODEC_TYPE_HW, (JPEG_ENCODER_HANDLE *)&(handle->hwAcceleratorHandle)))
         {
         }
      }
   }
#endif

   switch (handle->codecType)
   {
      JPEG_STATUS_ENUM status;

      #if defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SUPPORTED__)
         case JPEG_CODEC_TYPE_HW:
         {
            status = jpeg_enc_hw_internal(handle);

            #if defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SEPARATED_FROM_MDP__)
               #if (defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__))
               {
                  // switch source buffer
                  if (KAL_TRUE == handle->enableSrcDynamicSwitch)
                  {
                     if ((IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(handle->srcYUVBuffer[0]))) &&
                        (IS_CACHE_LINE_SIZE_ALIGNED(handle->srcBufferSize[0])) &&
                        (is_predef_dyna_c_region((kal_uint32)(handle->srcYUVBuffer[0]), handle->srcBufferSize[0])) &&
                        (IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(handle->srcYUVBuffer[1]))) &&
                        (IS_CACHE_LINE_SIZE_ALIGNED(handle->srcBufferSize[1])) &&
                        (is_predef_dyna_c_region((kal_uint32)(handle->srcYUVBuffer[1]), handle->srcBufferSize[1])) &&
                        (IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(handle->srcYUVBuffer[2]))) &&
                        (IS_CACHE_LINE_SIZE_ALIGNED(handle->srcBufferSize[2])) &&
                        (is_predef_dyna_c_region((kal_uint32)(handle->srcYUVBuffer[2]), handle->srcBufferSize[2])))
                     {
                        if((KAL_TRUE == INT_QueryIsNonCachedRAM(handle->srcYUVBuffer[0], handle->srcBufferSize[0])) &&
                           (KAL_TRUE == INT_QueryIsNonCachedRAM(handle->srcYUVBuffer[1], handle->srcBufferSize[1])) &&
                           (KAL_TRUE == INT_QueryIsNonCachedRAM(handle->srcYUVBuffer[2], handle->srcBufferSize[2])))
                        {
                           dynamic_switch_cacheable_region((void*)&(handle->srcYUVBuffer[0]), handle->srcBufferSize[0], PAGE_CACHEABLE);
                           dynamic_switch_cacheable_region((void*)&(handle->srcYUVBuffer[1]), handle->srcBufferSize[1], PAGE_CACHEABLE);
                           dynamic_switch_cacheable_region((void*)&(handle->srcYUVBuffer[2]), handle->srcBufferSize[2], PAGE_CACHEABLE);
                           handle->enableSrcDynamicSwitch = KAL_FALSE;
                        }
                     }
                  }
         
                  // switch destination buffer
                  if (KAL_TRUE == handle->enableDstDynamicSwitch)
                  {
                     SWJE_FILE *dstFile = &(handle->dstFile);
         
                     if ((IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)dstFile->dstBufferAddr)) &&
                        (IS_CACHE_LINE_SIZE_ALIGNED(dstFile->dstBufferSize)) &&
                        (is_predef_dyna_c_region((kal_uint32)dstFile->dstBufferAddr, dstFile->dstBufferSize)))
                     {
                        if(KAL_TRUE == INT_QueryIsNonCachedRAM(dstFile->dstBufferAddr, dstFile->dstBufferSize))
                        {
                           dynamic_switch_cacheable_region((void*)&(dstFile->dstBufferAddr), dstFile->dstBufferSize, PAGE_CACHEABLE);
                           handle->enableDstDynamicSwitch = KAL_FALSE;
                        }
                     }
                  }
               }
               #endif
                     
               if (handle->hwAcceleratorHandle)
               {
                  if (JPEG_STATUS_OK != jpeg_enc_release_encoder((JPEG_ENCODER_HANDLE)handle->hwAcceleratorHandle))
                  {
                     ASSERT(0);
                  }
                  handle->hwAcceleratorHandle = 0;
                  handle->codecType = JPEG_CODEC_TYPE_SW;
               }
            #endif

            if(JPEG_STATUS_OK != status)
            {
               return handle->lastStatus;
            }
         }
         break;
      #endif
      #if defined(__SW_JPEG_ENCODER_SUPPORT__)
         case JPEG_CODEC_TYPE_SW:
         {
            #if defined(__SW_JPEG_ENC_V2_USING_INTERNAL_MEMORY__)
            {
               #if defined(__MTK_TARGET__)
                  /// try to switch stack for better performance
                  kal_uint32 stack_size = JPEG_STACK_SIZE;
                  void *stack_ptr = drv_gfx_stkmgr_get_stack(stack_size);

                  if (stack_ptr)
                  {
                     status = (JPEG_STATUS_ENUM)(INT_SwitchStackToRun(stack_ptr, stack_size, (kal_func_ptr)jpeg_enc_sw_internal, 1, handle));
                     drv_gfx_stkmgr_release_stack(stack_ptr);
                  }
                  else
               #endif
               {
                  status = jpeg_enc_sw_internal(handle);
               }
            }
            #else
            {
               #if (defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__))
                  handle->enableSrcDynamicSwitch = KAL_FALSE;
               #endif

               #if (defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__))
               {
                  if(JPEG_ENCODE_SOURCE_YUV_BUFFER == (handle->srcMode))
                  {
                     if ((IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(handle->srcYUVBuffer[0]))) &&
                        (IS_CACHE_LINE_SIZE_ALIGNED(handle->srcBufferSize[0])) &&
                        (is_predef_dyna_c_region((kal_uint32)(handle->srcYUVBuffer[0]), handle->srcBufferSize[0])) &&
                        (IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(handle->srcYUVBuffer[1]))) &&
                        (IS_CACHE_LINE_SIZE_ALIGNED(handle->srcBufferSize[1])) &&
                        (is_predef_dyna_c_region((kal_uint32)(handle->srcYUVBuffer[1]), handle->srcBufferSize[1])) &&
                        (IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(handle->srcYUVBuffer[2]))) &&
                        (IS_CACHE_LINE_SIZE_ALIGNED(handle->srcBufferSize[2])) &&
                        (is_predef_dyna_c_region((kal_uint32)(handle->srcYUVBuffer[2]), handle->srcBufferSize[2])))
                     {
                        if((KAL_TRUE == INT_QueryIsNonCachedRAM(handle->srcYUVBuffer[0], handle->srcBufferSize[0])) &&
                           (KAL_TRUE == INT_QueryIsNonCachedRAM(handle->srcYUVBuffer[1], handle->srcBufferSize[1])) &&
                           (KAL_TRUE == INT_QueryIsNonCachedRAM(handle->srcYUVBuffer[2], handle->srcBufferSize[2])))
                        {
                           dynamic_switch_cacheable_region((void*)&(handle->srcYUVBuffer[0]), handle->srcBufferSize[0], PAGE_CACHEABLE);
                           dynamic_switch_cacheable_region((void*)&(handle->srcYUVBuffer[1]), handle->srcBufferSize[1], PAGE_CACHEABLE);
                           dynamic_switch_cacheable_region((void*)&(handle->srcYUVBuffer[2]), handle->srcBufferSize[2], PAGE_CACHEABLE);
                           handle->enableSrcDynamicSwitch = KAL_TRUE;
                        }
                     }

                  }
                  else if(JPEG_ENCODE_SOURCE_RGB_BUFFER == (handle->srcMode))
                  {
                     handle->enableSrcDynamicSwitch = drv_gfx_dynamic_switch_cacheable(&(handle->srcRGBBuffer), handle->srcBufferSize[0], KAL_TRUE);
                  }
               }
               #endif

               status = jpeg_enc_sw_internal(handle);

               #if (defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__))
               {
                  if(KAL_TRUE == (handle->enableSrcDynamicSwitch))
                  {
                     if(JPEG_ENCODE_SOURCE_YUV_BUFFER == (handle->srcMode))
                     {
                        drv_gfx_dynamic_switch_noncacheable(&(handle->srcYUVBuffer[0]), handle->srcBufferSize[0], KAL_FALSE);
                        drv_gfx_dynamic_switch_noncacheable(&(handle->srcYUVBuffer[1]), handle->srcBufferSize[1], KAL_FALSE);
                        drv_gfx_dynamic_switch_noncacheable(&(handle->srcYUVBuffer[2]), handle->srcBufferSize[2], KAL_FALSE);
                     }
                     else if(JPEG_ENCODE_SOURCE_RGB_BUFFER == (handle->srcMode))
                     {
                        drv_gfx_dynamic_switch_noncacheable(&(handle->srcRGBBuffer), handle->srcBufferSize[0], KAL_FALSE);
                     }
                  }

                  /// can not set to jpegEncRelease, due to web will only call jpegEncRelease one time
                  if(KAL_TRUE == (handle->extMemoryEnableDynamicSwitch))
                  {
                     dynamic_switch_cacheable_region((void*)&(handle->extMemoryAddr), (handle->extMemorySize), PAGE_NO_CACHE);
                     handle->extMemoryEnableDynamicSwitch = KAL_FALSE;
                  }
               }
               #endif
            }
            #endif

            #if defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_ENCODE_SUPPORTED__)
               if (handle->hwAcceleratorHandle)
               {
                  if (JPEG_STATUS_OK != jpeg_enc_release_encoder((JPEG_ENCODER_HANDLE)handle->hwAcceleratorHandle))
                  {
                     ASSERT(0);
                  }
                  handle->hwAcceleratorHandle = 0;
               }
            #endif
         
            if (JPEG_STATUS_OK != status)
            {
               return handle->lastStatus;
            }

            if (handle->callback_function)
            {
               handle->callback_function(handle->codecState);
            }

         }
         break;
      #endif
      default:
         ASSERT(0);
   }

   #if defined(__MM_DEBUG_MEASURE__)
/* under construction !*/
   #endif

   return handle->lastStatus;
}



JPEG_STATUS_ENUM jpegEncQueryWorkingMemory(JPEG_ENCODER_HANDLE handle,
                                           kal_uint32 *intMemorySizeBest, kal_uint32 *intMemorySizeMinimum,
                                           kal_uint32 *extMemorySizeBest, kal_uint32 *extMemorySizeMinimum)
{
   if (0 != jpeg_enc_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   if (JPEG_ENCODE_SOURCE_UNSUPPORTED == handle->srcMode)
   {
      /// Must set source mode before query working memory.
      handle->lastStatus = JPEG_STATUS_INVALID_OPERATION;
      return handle->lastStatus;
   }

   /// Set some necessary information
   #if defined(__SW_JPEG_ENCODER_SUPPORT__)
   {
      JPEG_ENCODE_INFO * const mainEncodeInfo = &(handle->mainEncodeInfo);
      JPEG_GENGERAL_ENCODE_INFO* const gengralEncodeInfo = &(handle->gengralEncodeInfo);
      kal_int32 comp;

      switch(handle->rotation)
      {
         case JPEG_ENCODE_ROTATE_ANGLE_000:
         case JPEG_ENCODE_ROTATE_ANGLE_180:
         case JPEG_ENCODE_ROTATE_ANGLE_MIRROR_000:
         case JPEG_ENCODE_ROTATE_ANGLE_MIRROR_180:
            mainEncodeInfo->srcStepX = IUL_I_TO_X(handle->srcWidth) / (mainEncodeInfo->dstWidth);
            mainEncodeInfo->srcStepY = IUL_I_TO_X(handle->srcHeight) / (mainEncodeInfo->dstHeight);
            mainEncodeInfo->dstStepX = IUL_I_TO_X(mainEncodeInfo->dstWidth) / (handle->srcWidth);
            mainEncodeInfo->dstStepY = IUL_I_TO_X(mainEncodeInfo->dstHeight) / (handle->srcHeight);
         break;
         case JPEG_ENCODE_ROTATE_ANGLE_090:
         case JPEG_ENCODE_ROTATE_ANGLE_270:
         case JPEG_ENCODE_ROTATE_ANGLE_MIRROR_090:
         case JPEG_ENCODE_ROTATE_ANGLE_MIRROR_270:
            mainEncodeInfo->srcStepX = IUL_I_TO_X(handle->srcHeight) / (mainEncodeInfo->dstWidth);
            mainEncodeInfo->srcStepY = IUL_I_TO_X(handle->srcWidth) / (mainEncodeInfo->dstHeight);
            mainEncodeInfo->dstStepX = IUL_I_TO_X(mainEncodeInfo->dstWidth) / (handle->srcHeight);
            mainEncodeInfo->dstStepY = IUL_I_TO_X(mainEncodeInfo->dstHeight) / (handle->srcWidth);
         break;
         default:
            ASSERT(0);
      }
      mainEncodeInfo->dstMcuWidth = (gengralEncodeInfo->hSamplingFactorMax) << 3;
      mainEncodeInfo->dstMcuHeight = (gengralEncodeInfo->vSamplingFactorMax) << 3;
      mainEncodeInfo->srcMcuWidth = (mainEncodeInfo->dstMcuWidth) * (mainEncodeInfo->srcStepX);
      mainEncodeInfo->srcMcuHeight = (mainEncodeInfo->dstMcuHeight) * (mainEncodeInfo->srcStepY);

      comp = gengralEncodeInfo->numComponent;
      while(--comp >= 0)
      {
         mainEncodeInfo->srcCompWidthPerMcu[comp] = IUL_X_TO_I_CARRY(((gengralEncodeInfo->vSamplingFactor[comp]) << 3) * (mainEncodeInfo->srcStepX));
         mainEncodeInfo->srcCompHeightPerMcu[comp] = IUL_X_TO_I_CARRY(((gengralEncodeInfo->hSamplingFactor[comp]) << 3) * (mainEncodeInfo->srcStepY));
      }

      mainEncodeInfo->srcPitch = handle->srcWidth;
      mainEncodeInfo->dstPitch = mainEncodeInfo->dstWidth;
   }
   #endif

   jpeg_enc_query_working_memory(handle);

   *intMemorySizeMinimum = 0;
   *intMemorySizeBest = 0;
   *extMemorySizeMinimum = handle->extMemorySizeMinimum;
   *extMemorySizeBest = handle->extMemorySizeBest;

   handle->lastStatus = JPEG_STATUS_OK;
   return handle->lastStatus;
}



JPEG_STATUS_ENUM jpegEncGetEncodedData(JPEG_ENCODER_HANDLE handle, kal_uint8 **startPtr, kal_uint32 *length)
{
   if (0 != jpeg_enc_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   if (JPEG_CODEC_STATE_COMPLETE != handle->codecState)
   {
      *length = 0;
      *startPtr = NULL;
      return handle->lastStatus;
   }

   switch (handle->codecType)
   {
      #if defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SUPPORTED__)
         case JPEG_CODEC_TYPE_HW:
         {
            SWJE_FILE *dstFile = &(handle->dstFile);

            *startPtr = (kal_uint8 *)(dstFile->dstBufferAddr);
            *length = dstFile->dstFileSize;

            if (KAL_FALSE == (dstFile->dstFileCompleted))
            {
               #if defined(__JPEG_ENC_PATCH_FOR_HQA00000392__)
                  /// Patch for HW bug: HQA00000392
                  jpeg_enc_patch_for_HQA00000392((kal_uint8 *)(dstFile->dstBufferAddr),
                                                 ((kal_uint8 *)(dstFile->dstBufferAddr)) + (dstFile->dstFileSize));
               #endif

               dstFile->dstFileCompleted = KAL_TRUE;
            }
         }
         break;
      #endif /// __DRV_GRAPHICS_HW_JPEG_ENCODE_SUPPORTED__
      #if defined(__SW_JPEG_ENCODER_SUPPORT__)
         case JPEG_CODEC_TYPE_SW:
         {
            SWJE_FILE *dstFile = &(handle->dstFile);
            kal_uint32 encodeBufferSize;

            *startPtr = (kal_uint8 *)dstFile->dstBufferAddr;

            if(NULL == (dstFile->pDstFileHandle))
            {
               encodeBufferSize = dstFile->dstBufferSize - dstFile->dstBufferLeft;
            }
            else
            {
               kal_uint32 cur_pos;

               /// Get the encoded file size.
               if(FSAL_OK != FSAL_Direct_GetCurPos(dstFile->pDstFileHandle, &cur_pos))
               {
                  ASSERT(0);
               }
               encodeBufferSize =  (kal_uint32)cur_pos;
            }

            #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_DYNAMIC_QUALITY_ADJUSTMENT)
               if(KAL_TRUE == (handle->enableDynamicQuantAdjustment))
               {
                  JPEG_ENCODE_INFO* const mainEncodeInfo = &(handle->mainEncodeInfo);

                  float quantScaleFactor = handle->quantScaleFactor;
                  kal_int32 size;

                  size = (mainEncodeInfo->dstWidth) * (mainEncodeInfo->dstHeight);
                  switch(handle->dstSamplingFormat)
                  {
                     case JPEG_YUV_FORMAT_YUV420:
                        /// YUV420 => size * 1.5
                        size = (size * 3) >> 1;
                     break;
                     #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_DST_YUV422)
                        case JPEG_YUV_FORMAT_YUV422:
                           /// YUV422 => size * 2
                           size = size << 1;
                        break;
                     #endif
                     default:
                        ASSERT(0);
                  }

                  if (encodeBufferSize >= ((size * SW_JPEG_ENCODER_MAX_COMPRESSION_RATIO_WITH_DYNAMIC_QUALITY_ADJUSTMENT * 4) >> 6))
                  {
                     quantScaleFactor = 3.0;
                  }
                  else if (encodeBufferSize >= ((size * SW_JPEG_ENCODER_MAX_COMPRESSION_RATIO_WITH_DYNAMIC_QUALITY_ADJUSTMENT * 3) >> 6))
                  {
                     quantScaleFactor += 0.6;
                     if (quantScaleFactor > 3.0)
                     {
                        quantScaleFactor = 3.0;
                     }
                  }
                  else if (encodeBufferSize >= ((size * SW_JPEG_ENCODER_MAX_COMPRESSION_RATIO_WITH_DYNAMIC_QUALITY_ADJUSTMENT * 2) >> 6))
                  {
                     quantScaleFactor += 0.3;
                     if (quantScaleFactor > 3.0)
                     {
                        quantScaleFactor = 3.0;
                     }
                  }
                  else
                  {
                     quantScaleFactor -= 0.3;
                     if (quantScaleFactor < 1.0)
                     {
                        quantScaleFactor = 1.0;
                     }
                  }
                  handle->quantScaleFactor = quantScaleFactor;
               }
            #endif

            *length = encodeBufferSize;
         }
         break;
      #endif
      default:
         ASSERT(0);
   }
   return JPEG_STATUS_OK;
}



JPEG_STATUS_ENUM jpegEncSetWorkingMemory(JPEG_ENCODER_HANDLE handle,
                                         kal_uint32 *intMemory, kal_uint32 intSize,
                                         kal_uint32 *extMemory, kal_uint32 extSize)
{
   if (0 != jpeg_enc_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   /// Check the memory size.
   if (extSize < (handle->extMemorySizeMinimum))
   {
      handle->lastStatus = JPEG_STATUS_ENC_ERROR_INSUFFICIENT_MEMORY;
      return handle->lastStatus;
   }

   /// handle->intMemoryAddr = (kal_uint8 *)intMemory;
   /// handle->intMemorySize = intSize;
   /// Get memory form MDP
   #ifdef __SW_JPEG_ENC_V2_USING_INTERNAL_MEMORY__

      if (handle->intMemorySizeMinimum)
      {
         #if defined(__MTK_TARGET__)
            mm_intmem_get(MM_SCEN__JPEG_ENCODE, MM_INTMEM_SEG__JPEG_ENC, (kal_uint32 *)(&(handle->intMemoryAddr)), &(handle->intMemorySize));
         #endif

         if(NULL == (handle->intMemoryAddr))
         {
            handle->intMemoryAddr = (kal_uint8 *)extMemory;
            handle->intMemorySize = ((handle->intMemorySizeMinimum) + 0x1F) & (~0x1F);

            extMemory += (handle->intMemorySize) >> 2;
            extSize -= handle->intMemorySize;
         }
         else
         {
            handle->intMemoryAllocateEnable = KAL_TRUE;
         }

         if ((handle->intMemorySize) < (handle->intMemorySizeMinimum))
         {
            ASSERT(0);
         }
      }
      else
      {
        handle->intMemorySize = 0;
        handle->intMemoryAddr = NULL;
      }
   #else
      if(handle->intMemorySizeMinimum)
      {
         ASSERT(0);
      }
   #endif

   handle->extMemoryAddr = (kal_uint8 *)extMemory;
   handle->extMemorySize = extSize;

   handle->lastStatus = JPEG_STATUS_OK;

   if(JPEG_STATUS_OK != jpeg_enc_set_working_memory(handle))
   {
      return handle->lastStatus;
   }

   return handle->lastStatus;
}



JPEG_STATUS_ENUM jpegEncReset(JPEG_ENCODER_HANDLE handle)
{
   JPEG_CODEC_TYPE_ENUM codecType = handle->codecType;

   if (0 != jpeg_enc_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   switch (codecType)
   {
      #if defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SUPPORTED__)
         case JPEG_CODEC_TYPE_HW:
            jpeg_drv_enc_reset();

            jpeg_drv_enc_power_off();

            #if defined(__MTK_TARGET__) && (!defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SEPARATED_FROM_MDP__)) && (!defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_ENCODE_SUPPORTED__))
            /// Release the control of IDP
            if (handle->idpKey)
            {
               if (!handle->idp_close_func(handle->idpKey))
               {
                  ASSERT(0);
               }
               handle->idpKey = 0;
            }
            #endif
         break;
      #endif /// __DRV_GRAPHICS_HW_JPEG_ENCODE_SUPPORTED__
      #if defined(__SW_JPEG_ENCODER_SUPPORT__)
         case JPEG_CODEC_TYPE_SW:
         break;
      #endif
      default:
         ASSERT(0);
   }

   memset(handle, 0, sizeof(JPEG_ENCODER));
   handle->codecType = codecType;
   handle->codecState = JPEG_CODEC_STATE_IDLE;

   handle->lastStatus = JPEG_STATUS_OK;
   return handle->lastStatus;
}



JPEG_STATUS_ENUM jpegEncQueryDstBufferSize(kal_uint32 *bufferSize,
                                           JPEG_ENCODE_EVALUATION_MODE_ENUM mode,
                                           JPEG_ENCODE_QUALITTY_ENUM quality,
                                           JPEG_YUV_FORMAT_ENUM dstFormat, kal_uint32 dstWidth, kal_uint32 dstHeight,
                                           kal_bool metadataEnable)
{
   kal_uint32 size = 0;
   kal_uint32 step = 0;

   switch(mode)
   {
      case JPEG_ENCODE_EVALUATION_MODE_AVERAGE:
      {
         switch(dstFormat)
         {
            case JPEG_YUV_FORMAT_YUV420:
            {
               switch(quality)
               {
                  case JPEG_ENCODE_QUALITY_EXCELLENT: /// 30% * 1.5
                     step = 15;
                  break;
                  case JPEG_ENCODE_QUALITY_GOOD: /// 20% * 1.5
                     step = 9;
                  break;
                  case JPEG_ENCODE_QUALITY_FAIR: /// 10% * 1.5
                     step = 4;
                  break;
                  default:  /// 5% * 1.5
                  /// case JPEG_ENCODE_QUALITY_LOW:
                  /// case JPEG_ENCODE_QUALITY_POOR:
                     step = 2;
                  break;
               }

               size += (dstWidth * dstHeight * step) >> 5; // w * h * (step/32)
            }
            break;
            #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_DST_YUV422)
            case JPEG_YUV_FORMAT_YUV422:
            {
               switch(quality)
               {
                  case JPEG_ENCODE_QUALITY_EXCELLENT: /// 30% * 2
                     step = 5;
                  break;
                  case JPEG_ENCODE_QUALITY_GOOD: /// 20% * 2
                     step = 3;
                  break;
                  default:  /// 5% * 2
                  /// case JPEG_ENCODE_QUALITY_FAIR:
                  /// case JPEG_ENCODE_QUALITY_LOW:
                  /// case JPEG_ENCODE_QUALITY_POOR:
                     step = 1;
                  break;
               }

               size += (dstWidth * dstHeight * step) >> 3; // w * h * (step/8)
            }
            break;
            #endif
            default:
               ASSERT(0);
         }
      }
      break;
      case JPEG_ENCODE_EVALUATION_MODE_WORST:
      {
         switch(dstFormat)
         {
            case JPEG_YUV_FORMAT_YUV420:
            {
               switch(quality)
               {
                  case JPEG_ENCODE_QUALITY_EXCELLENT: /// 75% * 1.5
                     step = 36;
                  break;
                  case JPEG_ENCODE_QUALITY_GOOD: /// 70% * 1.5
                     step = 33;
                  break;
                  case JPEG_ENCODE_QUALITY_FAIR: /// 60% * 1.5
                     step = 30;
                  break;
                  case JPEG_ENCODE_QUALITY_LOW:  /// 30% * 1.5
                     step = 15;
                  break;
                  case JPEG_ENCODE_QUALITY_POOR: /// 20% * 1.5
                     step = 9;
                  break;
               }

               size += (dstWidth * dstHeight * step) >> 5; // w * h * (step/32)
            }
            break;
            #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_DST_YUV422)
            case JPEG_YUV_FORMAT_YUV422:
            {
               switch(quality)
               {
                  case JPEG_ENCODE_QUALITY_EXCELLENT: /// 75% * 2
                     step = 12;
                  break;
                  case JPEG_ENCODE_QUALITY_GOOD: /// 70% * 2
                     step = 11;
                  break;
                  case JPEG_ENCODE_QUALITY_FAIR: /// 60% * 2
                     step = 10;
                  break;
                  case JPEG_ENCODE_QUALITY_LOW:  /// 30% * 2
                     step = 5;
                  break;
                  case JPEG_ENCODE_QUALITY_POOR: /// 20% * 2
                     step = 3;
                  break;
               }

               size += (dstWidth * dstHeight * step) >> 3; // w * h * (step/8)
            }
            break;
            #endif
            default:
               ASSERT(0);
         }
      }
      break;
      default:
         ASSERT(0);
      break;
   }

   if(KAL_TRUE == metadataEnable)
   {
      size += (size * 3) >> 5;  /// size * 10%
   }

   *bufferSize = size;
   return JPEG_STATUS_OK;
}



JPEG_STATUS_ENUM jpegEncGetLastError(JPEG_ENCODER_HANDLE handle)
{
   if (0 != jpeg_enc_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   return handle->lastStatus;
}



#else



JPEG_STATUS_ENUM jpegEncGetEncoder(JPEG_CODEC_TYPE_ENUM codecType, JPEG_ENCODER_HANDLE *handlePtr)
{
   return JPEG_STATUS_CODEC_UNAVAILABLE;
}



JPEG_STATUS_ENUM jpegEncReleaseEncoder(JPEG_ENCODER_HANDLE handle)
{
   return JPEG_STATUS_CODEC_UNAVAILABLE;
}



JPEG_STATUS_ENUM jpegEncSetSrcMode(JPEG_ENCODER_HANDLE handle, JPEG_ENCODE_SOURCE_ENUM srcMode)
{
   return JPEG_STATUS_CODEC_UNAVAILABLE;
}



JPEG_STATUS_ENUM jpegEncSetSrcWindow(JPEG_ENCODER_HANDLE handle, MY_RECTANGLE* srcWindow)
{
   return JPEG_STATUS_CODEC_UNAVAILABLE;
}



JPEG_STATUS_ENUM jpegEncSetSrcDimension(JPEG_ENCODER_HANDLE handle, kal_uint32 width, kal_uint32 height)
{
   return JPEG_STATUS_CODEC_UNAVAILABLE;
}



JPEG_STATUS_ENUM jpegEncSetSrcRGBFormat(JPEG_ENCODER_HANDLE handle, JPEG_RGB_FORMAT_ENUM rgbFormat)
{
   return JPEG_STATUS_CODEC_UNAVAILABLE;
}



JPEG_STATUS_ENUM jpegEncSetRGBBuffer(JPEG_ENCODER_HANDLE handle, void *buffer, kal_uint32 bufferSize)
{
   return JPEG_STATUS_CODEC_UNAVAILABLE;
}



JPEG_STATUS_ENUM jpegEncSetSrcYUVFormat(JPEG_ENCODER_HANDLE handle, JPEG_YUV_FORMAT_ENUM yuvFormat)
{
   return JPEG_STATUS_CODEC_UNAVAILABLE;
}



JPEG_STATUS_ENUM jpegEncSetYUVBuffer(JPEG_ENCODER_HANDLE handle,
                                     void *yBuffer, void *uBuffer, void *vBuffer,
                                     kal_uint32 yBufferSize, kal_uint32 uBufferSize, kal_uint32 vBufferSize)
{
   return JPEG_STATUS_CODEC_UNAVAILABLE;
}



JPEG_STATUS_ENUM jpegEncSetDstQuality(JPEG_ENCODER_HANDLE handle, JPEG_ENCODE_QUALITTY_ENUM quality)
{
   return JPEG_STATUS_CODEC_UNAVAILABLE;
}



JPEG_STATUS_ENUM jpegEncSetDstFileFormat(JPEG_ENCODER_HANDLE handle, JPEG_FILE_FORMAT_ENUM format)
{
   return JPEG_STATUS_CODEC_UNAVAILABLE;
}



JPEG_STATUS_ENUM jpegEncSetDstThumbnail(JPEG_ENCODER_HANDLE handle, kal_bool enable, kal_uint32 width, kal_uint32 height)
{
   return JPEG_STATUS_CODEC_UNAVAILABLE;
}



JPEG_STATUS_ENUM jpegEncSetDstDimension(JPEG_ENCODER_HANDLE handle, kal_uint32 width, kal_uint32 height)
{
   return JPEG_STATUS_CODEC_UNAVAILABLE;
}



JPEG_STATUS_ENUM jpegEncSetDstSampleFormat(JPEG_ENCODER_HANDLE handle, JPEG_YUV_FORMAT_ENUM sampleFormat)
{
   return JPEG_STATUS_CODEC_UNAVAILABLE;
}



JPEG_STATUS_ENUM jpegEncSetDstBuffer(JPEG_ENCODER_HANDLE handle, void *bufferAddr, kal_uint32 bufferSize)
{
   return JPEG_STATUS_CODEC_UNAVAILABLE;
}



JPEG_STATUS_ENUM jpegEncSetDirectFileOutputHandle(JPEG_ENCODER_HANDLE handle, STFSAL *fp)
{
   return JPEG_STATUS_CODEC_UNAVAILABLE;
}



JPEG_STATUS_ENUM jpegEncSetCallbackFunction(JPEG_ENCODER_HANDLE handle, kal_int32 (*callback_function)(JPEG_CODEC_STATE_ENUM state))
{
   return JPEG_STATUS_CODEC_UNAVAILABLE;
}



JPEG_STATUS_ENUM jpegEncGetEncoderState(JPEG_ENCODER_HANDLE handle, JPEG_CODEC_STATE_ENUM *state)
{
   return JPEG_STATUS_CODEC_UNAVAILABLE;
}



JPEG_STATUS_ENUM jpegEncSetRotation(JPEG_ENCODER_HANDLE handle, JPEG_ENCODE_ROTATE_ANGLE_ENUM angle)
{
   return JPEG_STATUS_CODEC_UNAVAILABLE;
}



JPEG_STATUS_ENUM jpegEncSetCheckAbortFunction(JPEG_ENCODER_HANDLE handle,
                                              kal_int32 (*check_abort_func)(void))
{
   return JPEG_STATUS_CODEC_UNAVAILABLE;
}



JPEG_STATUS_ENUM jpegEncSetDynamicQuantAdjustment(JPEG_ENCODER_HANDLE handle, kal_bool enable)

{
   return JPEG_STATUS_CODEC_UNAVAILABLE;
}



JPEG_STATUS_ENUM jpegEncStart(JPEG_ENCODER_HANDLE handle)
{
   return JPEG_STATUS_CODEC_UNAVAILABLE;
}



JPEG_STATUS_ENUM jpegEncQueryWorkingMemory(JPEG_ENCODER_HANDLE handle,
                                           kal_uint32 *intMemorySizeBest, kal_uint32 *intMemorySizeMinimum,
                                           kal_uint32 *extMemorySizeBest, kal_uint32 *extMemorySizeMinimum)
{
   return JPEG_STATUS_CODEC_UNAVAILABLE;
}



JPEG_STATUS_ENUM jpegEncGetEncodedData(JPEG_ENCODER_HANDLE handle, kal_uint8 **startPtr, kal_uint32 *length)
{
   return JPEG_STATUS_CODEC_UNAVAILABLE;
}



JPEG_STATUS_ENUM jpegEncSetWorkingMemory(JPEG_ENCODER_HANDLE handle,
                                         kal_uint32 *intMemory, kal_uint32 intSize,
                                         kal_uint32 *extMemory, kal_uint32 extSize)
{
   return JPEG_STATUS_CODEC_UNAVAILABLE;
}



JPEG_STATUS_ENUM jpegEncReset(JPEG_ENCODER_HANDLE handle)
{
   return JPEG_STATUS_CODEC_UNAVAILABLE;
}



JPEG_STATUS_ENUM jpegEncQueryDstBufferSize(kal_uint32 *bufferSize,
                                           JPEG_ENCODE_EVALUATION_MODE_ENUM mode,
                                           JPEG_ENCODE_QUALITTY_ENUM quality,
                                           JPEG_YUV_FORMAT_ENUM dstFormat, kal_uint32 dstWidth, kal_uint32 dstHeight,
                                           kal_bool metadataEnable)
{
   return JPEG_STATUS_CODEC_UNAVAILABLE;
}



JPEG_STATUS_ENUM jpegEncGetLastError(JPEG_ENCODER_HANDLE handle)
{
   return JPEG_STATUS_CODEC_UNAVAILABLE;
}


#endif



