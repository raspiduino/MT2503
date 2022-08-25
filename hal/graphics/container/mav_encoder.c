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
 *   mav_encoder.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Main include file of JPEG memory.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "mav_common.h"
#include "mav_encoder.h"
#include "mav_mem.h"

#include "iul_color_convert.h"
#include "iul_csc_macros.h"

#include "jpeg_enum.h"
#include "jpeg_encode_api.h"
#include "jpeg_encode_wrapper.h"


#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)



MAV_ENC_STATUS
_mavEncWrapperConfigIvlw(
   IVLW_ENCODER_HANDLE *ivlw_handle,
   MAV_ENC_WRAPPER *wrapperPtr)
{
   if (IVLW_ENC_STATUS_OK != ivlwEncSetDstBuf(ivlw_handle, wrapperPtr->dst_buf, wrapperPtr->dst_buf_size))
   {
      return MAV_ENC_STATUS_INVALID_PARA;
   }

   if (IVLW_ENC_STATUS_OK != ivlwEncSetAllocAndFree(ivlw_handle, wrapperPtr->_alloc_func, wrapperPtr->_free_func))
   {
      return MAV_ENC_STATUS_INVALID_PARA;
   }

   if (IVLW_ENC_STATUS_OK != ivlwEncSetDstFormat(ivlw_handle, IVLW_COLOR_RGB565))
   {
      return MAV_ENC_STATUS_INVALID_PARA;
   }

   if (IVLW_ENC_STATUS_OK != ivlwEncSetTotalFrameCount(ivlw_handle, wrapperPtr->frame_cnt))
   {
      return MAV_ENC_STATUS_INVALID_PARA;
   }

   if (IVLW_ENC_STATUS_OK != ivlwEncSetTotalPartitionCount(ivlw_handle, 1))
   {
      return MAV_ENC_STATUS_INVALID_PARA;
   }

   if (IVLW_ENC_STATUS_OK != ivlwEncSetPartitionInfo(ivlw_handle, 0, wrapperPtr->frame_cnt, 0))
   {
      return MAV_ENC_STATUS_INVALID_PARA;
   }

   if (IVLW_ENC_STATUS_OK != ivlwEncSetEncMethod(ivlw_handle, IVLW_ALG_MAV))
   {
      return MAV_ENC_STATUS_INVALID_PARA;
   }

   return MAV_ENC_STATUS_OK;
}



MAV_ENC_STATUS
_mavEncWrapperStartIvlw(
   IVLW_ENCODER_HANDLE *ivlw_handle,
   MAV_ENC_WRAPPER *wrapperPtr,
    unsigned char *encodeBufferAddr,
    unsigned int encode_size,
    kal_uint32 frameIdx)
{
   IVLW_PPM_INFO_T ppm_info;

   ppm_info.color_format = IVLW_COLOR_RGB565;
   ppm_info.height = wrapperPtr->srcHeight;
   ppm_info.width = wrapperPtr->srcWidth;
   ppm_info.pixel_start_p = encodeBufferAddr;          
   ppm_info.pixel_data_size = encode_size;

   if (IVLW_ENC_STATUS_OK != ivlwEncSetPPMInfo(ivlw_handle, &ppm_info))
   {
      return MAV_ENC_STATUS_INVALID_PARA;
   }
   if (IVLW_ENC_STATUS_OK != ivlwEncFrame(ivlw_handle, frameIdx, encodeBufferAddr, encode_size, 8))
   {
      return MAV_ENC_STATUS_FAIL;
   }

   return MAV_ENC_STATUS_OK;
}



MAV_ENC_STATUS
_mavEncWrapperOpenJpeg(JPEG_ENCODER_HANDLE *jpegEncoderHandle)
{
   if (JPEG_STATUS_OK != jpegEncGetEncoder(JPEG_CODEC_TYPE_HW, jpegEncoderHandle))
   {
      if (JPEG_STATUS_OK != jpegEncGetEncoder(JPEG_CODEC_TYPE_SW, jpegEncoderHandle))
      {
         return MAV_ENC_STATUS_HANDLE_UNAVAILABLE;
      }
   }

   return MAV_ENC_STATUS_OK;
}



MAV_ENC_STATUS
_mavEncWrapperCloseJpeg(JPEG_ENCODER_HANDLE jpegEncoderHandle)
{
   if (JPEG_STATUS_OK != jpegEncReleaseEncoder(jpegEncoderHandle))
   {
      return MAV_ENC_STATUS_HANDLE_UNAVAILABLE;
   }

   return MAV_ENC_STATUS_OK;
}



MAV_ENC_STATUS
_mavEncWrapperConfigJpeg(
   JPEG_ENCODER_HANDLE jpegEncoderHandle,
   MAV_ENC_WRAPPER *wrapperPtr,
   kal_uint32 frameIdx)
{
   kal_uint32 *intMemAddr = NULL;
   kal_uint32 *extMemAddr = NULL;
   kal_uint32 intMemSizeBest;
   kal_uint32 extMemSizeBest;
   kal_uint32 intMemSizeMinimum;
   kal_uint32 extMemSizeMinimum;

   unsigned char *mav_working_buf = wrapperPtr->working_buf;
   unsigned int mav_working_buf_size = wrapperPtr->working_buf_size;


   //jpegEncoderHandle = &jpegEncoderHandle;
   if (JPEG_STATUS_OK != jpegEncSetSrcMode(jpegEncoderHandle, wrapperPtr->srcMode))
   {
      return MAV_ENC_STATUS_INVALID_PARA;
   }

   if (JPEG_ENCODE_SOURCE_RGB_BUFFER == wrapperPtr->srcMode)   
   {
      if (JPEG_STATUS_OK != jpegEncSetSrcRGBFormat(jpegEncoderHandle, wrapperPtr->srcRGBFormat))
      {
         return MAV_ENC_STATUS_INVALID_PARA;
      }
      if (JPEG_STATUS_OK != jpegEncSetRGBBuffer(jpegEncoderHandle, (void *)wrapperPtr->in_buf[frameIdx], wrapperPtr->in_buf_size[frameIdx]))
      {
         return MAV_ENC_STATUS_INVALID_PARA;
      }
   }
   else if (JPEG_ENCODE_SOURCE_YUV_BUFFER == wrapperPtr->srcMode)   
   {
      kal_uint32 in_buf_y, in_buf_u, in_buf_v;
      kal_uint32 in_buf_size_y, in_buf_size_u, in_buf_size_v;

      in_buf_size_y = wrapperPtr->srcWidth * wrapperPtr->srcHeight;
      in_buf_size_u = in_buf_size_y >> 2;
      in_buf_size_v = in_buf_size_u;
      
      in_buf_y = (kal_uint32)wrapperPtr->in_buf[frameIdx];
      in_buf_u = in_buf_y + in_buf_size_y;
      in_buf_v = in_buf_u + in_buf_size_u;
      
      if (JPEG_STATUS_OK != jpegEncSetSrcYUVFormat(jpegEncoderHandle, wrapperPtr->srcSamplingFormat))
      {
         return MAV_ENC_STATUS_INVALID_PARA;
      }
      if (JPEG_STATUS_OK != jpegEncSetYUVBuffer(jpegEncoderHandle, (void *)in_buf_y, (void *)in_buf_u, (void *)in_buf_v,
                                                                             in_buf_size_y, in_buf_size_u, in_buf_size_v))
      {
         return MAV_ENC_STATUS_INVALID_PARA;
      }
   }
   else
   {
      return MAV_ENC_STATUS_INVALID_PARA;
   }

   if ((MAV_MAX_WIDTH * MAV_MAX_HEIGHT) < (wrapperPtr->srcWidth * wrapperPtr->srcHeight))
   {
      return MAV_ENC_STATUS_INVALID_PARA;
   }
   else
   {
      if (JPEG_STATUS_OK != jpegEncSetSrcDimension(jpegEncoderHandle, wrapperPtr->srcWidth, wrapperPtr->srcHeight))
      {
         return MAV_ENC_STATUS_INVALID_PARA;
      }

      if (JPEG_STATUS_OK != jpegEncSetDstDimension(jpegEncoderHandle, wrapperPtr->srcWidth, wrapperPtr->srcHeight))
      {
         return MAV_ENC_STATUS_INVALID_PARA;
      }
   }
   
   if (JPEG_STATUS_OK != jpegEncSetDirectFileOutputHandle(jpegEncoderHandle, NULL))
   {
      return MAV_ENC_STATUS_INVALID_PARA;
   }

   if (JPEG_STATUS_OK != jpegEncSetDstFileFormat(jpegEncoderHandle, wrapperPtr->dstFileFormat))
   {
      return MAV_ENC_STATUS_INVALID_PARA;
   }
   
   if (JPEG_STATUS_OK != jpegEncSetDstQuality(jpegEncoderHandle, JPEG_ENCODE_QUALITY_EXCELLENT))
   {
      return MAV_ENC_STATUS_INVALID_PARA;
   }

   if (JPEG_STATUS_OK != jpegEncSetDstSampleFormat(jpegEncoderHandle, wrapperPtr->dstSamplingFormat))
   {
      return MAV_ENC_STATUS_INVALID_PARA;
   }

   if (JPEG_STATUS_OK != jpegEncSetDstThumbnail(jpegEncoderHandle, KAL_FALSE, 0, 0))
   {
      return MAV_ENC_STATUS_INVALID_PARA;
   }

   if (JPEG_STATUS_OK != jpegEncQueryWorkingMemory(jpegEncoderHandle, &intMemSizeBest, &intMemSizeMinimum, &extMemSizeBest, &extMemSizeMinimum))
   {
      return MAV_ENC_STATUS_INVALID_PARA;
   }

   if (extMemSizeMinimum > mav_working_buf_size)
   {
      return MAV_ENC_STATUS_WORKING_BUF_NOT_ENOUGH;
   }
   else
   {
      if (IVLW_ENC_STATUS_OK != jpegEncSetWorkingMemory(jpegEncoderHandle, NULL, 0, (kal_uint32*)mav_working_buf, extMemSizeMinimum))
      {
         return MAV_ENC_STATUS_INVALID_PARA;
      }    
   }

   mav_working_buf = mav_working_buf + extMemSizeMinimum;
   mav_working_buf_size = mav_working_buf_size - extMemSizeMinimum;

   if (JPEG_STATUS_OK != jpegEncSetCallbackFunction(jpegEncoderHandle, NULL))
   {
      return MAV_ENC_STATUS_INVALID_PARA;
   }

   if (JPEG_STATUS_OK != jpegEncSetDstBuffer(jpegEncoderHandle, mav_working_buf, mav_working_buf_size))
   {
      return MAV_ENC_STATUS_INVALID_PARA;
   }

   return MAV_ENC_STATUS_OK;
}



MAV_ENC_STATUS
_mavEncWrapperStartJpeg(
   JPEG_ENCODER_HANDLE jpegEncoderHandle,
   kal_uint8 **encodeBufferAddr,
   kal_uint32 *encode_size)
{
   JPEG_CODEC_STATE_ENUM jpeg_state;

   jpeg_state = JPEG_CODEC_STATE_BUSY;
   if (JPEG_STATUS_OK != jpegEncStart(jpegEncoderHandle))
   {
      return MAV_ENC_STATUS_FAIL;
   }

   /// Polling to wait encoding done.
   while (JPEG_CODEC_STATE_COMPLETE != jpeg_state && JPEG_CODEC_STATE_ERROR != jpeg_state)
   {
      if (JPEG_STATUS_OK != jpegEncGetEncoderState(jpegEncoderHandle, &jpeg_state))
      {
         return MAV_ENC_STATUS_FAIL;
      }
   }

   if (JPEG_STATUS_OK != jpegEncGetEncodedData(jpegEncoderHandle, encodeBufferAddr, encode_size))
   {
      return MAV_ENC_STATUS_FAIL;
   }

   return MAV_ENC_STATUS_OK;
}



MAV_ENC_STATUS
mavEncWrapperOpen(MAV_ENCODER_HANDLE* handlePtr)
{
   MAV_ENCODER_HANDLE h = NULL;
   
   h = (MAV_ENCODER_HANDLE) get_ctrl_buffer(sizeof(MAV_ENC_WRAPPER));
   if (h)
   {
      memset(h, 0, sizeof(MAV_ENC_WRAPPER));
      *handlePtr = h;
   }
   else
   {
      *handlePtr = NULL;
      return MAV_ENC_STATUS_HANDLE_UNAVAILABLE;
   }

   if (IVLW_ENC_STATUS_OK != ivlwEncGetHandle(&((*handlePtr)->ivlw_handle)))
   {
      return MAV_ENC_STATUS_HANDLE_UNAVAILABLE;
   }

   return MAV_ENC_STATUS_OK;
}



MAV_ENC_STATUS
mavEncWrapperClose(MAV_ENCODER_HANDLE handle)
{
   if (IVLW_ENC_STATUS_OK != ivlwEncReleaseHandle(&handle->ivlw_handle))
   {
      return MAV_ENC_STATUS_INVALID_PARA;
   }

   free_ctrl_buffer((void*)handle);
   return MAV_ENC_STATUS_OK;
}



MAV_ENC_STATUS
mavEncWrapperStart(
   MAV_ENCODER_HANDLE handle,
   MAV_ENC_WRAPPER *wrapperPtr)
{
#if !defined(__ARMULATOR__)

   unsigned int i;
   JPEG_ENCODER_HANDLE jpegEncoderHandle;
   IVLW_ENCODER_HANDLE *ivlw_handle = handle->ivlw_handle;
   kal_uint8 *encodeBufferAddr = NULL;
   JPEG_CODEC_STATE_ENUM jpeg_state;
   kal_uint32 width, height, encode_size;

   if (MAV_ENC_STATUS_OK != _mavEncWrapperConfigIvlw(ivlw_handle, wrapperPtr))
   {
      return MAV_ENC_STATUS_INVALID_PARA;
   }

   // main jpeg encode
   for (i=0; i<wrapperPtr->frame_cnt; i++)
   {
      if (MAV_ENC_STATUS_OK != _mavEncWrapperOpenJpeg(&jpegEncoderHandle))
      {
         return MAV_ENC_STATUS_INVALID_PARA;
      }
   
      if (MAV_ENC_STATUS_OK != _mavEncWrapperConfigJpeg(jpegEncoderHandle, wrapperPtr, i))
      {
         return MAV_ENC_STATUS_INVALID_PARA;
      }
   
      if (MAV_ENC_STATUS_OK != _mavEncWrapperStartJpeg(jpegEncoderHandle, &encodeBufferAddr, &encode_size))
      {
         return MAV_ENC_STATUS_FAIL;
      }
   
      if (MAV_ENC_STATUS_OK != _mavEncWrapperStartIvlw(ivlw_handle, wrapperPtr, encodeBufferAddr, encode_size, i))
      {
         return MAV_ENC_STATUS_FAIL;
      }

      if (MAV_ENC_STATUS_OK != _mavEncWrapperCloseJpeg(jpegEncoderHandle))
      {
         return MAV_ENC_STATUS_INVALID_PARA;
      }
   }
#endif //__ARMULATOR__

   return MAV_ENC_STATUS_OK;
}



MAV_ENC_STATUS
mavEncWrapperGetEncodedData(MAV_ENCODER_HANDLE handle, kal_uint8 **encodeBufferAddr, kal_uint32 *encodeBufferSize)
{
   if (IVLW_ENC_STATUS_OK != ivlwEncGetEncodedData(handle->ivlw_handle, encodeBufferAddr, encodeBufferSize))
   {
      return MAV_ENC_STATUS_INVALID_PARA;
   }

   return MAV_ENC_STATUS_OK;
}


#endif  // __MULTIPLE_ANGLE_VIEW_SUPPORT__


