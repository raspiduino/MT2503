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
 *   mav_decoder.c
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
#include "kal_general_types.h"

#include "mav_common.h"
#include "mav_decoder.h"
#include "cache_sw.h"
#include "mmu.h"

#include "iul_csc_y2r.h"
#include "iul_color_convert.h"
#include "idp_image_resize.h"
#include "img_common_enum.h"
#include "jpeg_decode_structure.h"


#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)
MAV_DECODER_HANDLE  *mav_current_handle;
kal_int32 g_mav_dec_malloc_times = 0;


/***************************************************
** Definitions
****************************************************/
#define JPEG_OUTPUT_YUV420
//JPEG_OUTPUT_YUV422: used for debug. Currently some bugs for YUV422 format.

#if defined(__MTK_TARGET__) && defined(__MAV_SWLA_DEBUG__)
#define MAV_SWLA_DEBUG(tag,start) SLA_CustomLogging((tag), (start));
#else
#define MAV_SWLA_DEBUG(tag,start)
#endif
#define MAV_ASYNC_FS_WORKING_BUF_SIZE  FS_ASYNC_WORKING_BUFFER_SIZE;


#if !defined(MAV_DECODER_STANDALONE)
kal_mutexid  mavMutex;
#define MAV_TAKE_MUTEX() \
do{\
  if (KAL_FALSE == kal_query_systemInit())\
  {\
     kal_take_mutex(mavMutex);\
  } \
}while(0)

#define MAV_GIVE_MUTEX() \
do{\
  if (KAL_FALSE == kal_query_systemInit())\
  {\
     kal_give_mutex(mavMutex);\
  } \
}while(0)
#define MAV_CREATE_MUTEX()\
do{\
  if (0 == mavMutex)\
  {\
     mavMutex = kal_create_mutex("MAV_MGR");\
  }\
}while(0)
#else //!defined(MAV_DECODER_STANDALONE)
unsigned int  mavMutex;
#define MAV_TAKE_MUTEX()
#define MAV_GIVE_MUTEX()
#define MAV_CREATE_MUTEX()
#endif



/***************************************************
** Functions
****************************************************/

MAV_DEC_STATUS
mavDecGetHandle(MAV_DECODER_HANDLE** handlePtr, JPEG_CODEC_TYPE_ENUM jpegCodecType)
{
   MAV_DECODER_HANDLE *h = NULL;
   MAV_DEC_STATUS rtn;

   h = (MAV_DECODER_HANDLE*) get_ctrl_buffer(sizeof(MAV_DECODER_HANDLE));
   //g_mav_dec_malloc_times++;
   if (h)
   {
      memset(h, 0, sizeof(MAV_DECODER_HANDLE));
      rtn = MAV_DEC_STATUS_OK;
      *handlePtr = h;
   }
   else
   {
      *handlePtr = NULL;
      rtn = MAV_DEC_STATUS_HANDLE_UNAVAILABLE;
   }

   mav_current_handle = h;
   memset((*handlePtr), 0, sizeof(MAV_DECODER_HANDLE));

   if (IVLW_DEC_STATUS_OK == ivlwDecGetHandle(&(*handlePtr)->ivlwHandle))
   {
      if (IVLW_DEC_STATUS_OK != ivlwDecSetAllocAndFree((*handlePtr)->ivlwHandle, NULL, NULL))
      {
         ASSERT(0);
      }
   }
   else
   {
      mavDecReleaseHandle(&h);
      *handlePtr = NULL;
      return MAV_DEC_STATUS_HANDLE_UNAVAILABLE;
   }

   if (JPEG_STATUS_OK != jpegDecGetDecoder(jpegCodecType, &(*handlePtr)->jpegHandle))
   {
     mavDecReleaseHandle(&h);
     *handlePtr = NULL;
     return MAV_DEC_STATUS_JPEG_HANDLE_UNAVAILABLE;
   }

   return MAV_DEC_STATUS_OK;
}



MAV_DEC_STATUS
mavDecReleaseHandle(MAV_DECODER_HANDLE** handle)
{
   if (((*handle)->ivlwHandle) &&  
       (IVLW_DEC_STATUS_OK != ivlwDecReleaseHandle(&((*handle)->ivlwHandle))))
   {
      return MAV_DEC_STATUS_INVALID_PARA;
   }

   if (((*handle)->jpegHandle) &&
       (JPEG_STATUS_OK != jpegDecReleaseDecoder((*handle)->jpegHandle)))
   {
     return MAV_DEC_STATUS_JPEG_HANDLE_FREE_FAIL;
   }

   if (*handle)
   {
      free_ctrl_buffer((void*) (*handle));
      //g_mav_dec_malloc_times--;
      *handle = NULL;
   }
   mav_current_handle = NULL;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

   return MAV_DEC_STATUS_OK;
}



MAV_DEC_STATUS
mavDecQuerySrcFileBuf(
   MAV_DECODER_HANDLE* handle, 
   kal_uint32 *readBufferSizeBest,
   kal_uint32 *readBufferSizeMinimum,
   kal_uint32 *fsalCacheSizeBest, 
   kal_uint32 *fsalCacheSizeMinimum)
{
   JPEG_STATUS_ENUM jpeg_status;

   jpeg_status = jpegDecQueryFileBuffer(handle->jpegHandle,
                             readBufferSizeBest,
                             readBufferSizeMinimum,
                             fsalCacheSizeBest,
                             fsalCacheSizeMinimum);

   if (JPEG_STATUS_OK != jpeg_status)
   {
      return MAV_DEC_STATUS_INVALID_PARA;
   }
   return MAV_DEC_STATUS_OK;
}


MAV_DEC_STATUS
_mavDecConvertIvlwStatusToMavStatus(IVLW_DEC_STATUS status)
{
   switch (status)
   {
     case IVLW_DEC_STATUS_HANDLE_UNAVAILABLE: 
        return MAV_DEC_STATUS_HANDLE_UNAVAILABLE;
     case IVLW_DEC_STATUS_MEM_UNAVAILABLE: 
        return MAV_DEC_STATUS_MEM_UNAVAILABLE;
     case IVLW_DEC_STATUS_INVALID_FILE: 
        return MAV_DEC_STATUS_INVALID_FILE;
     case IVLW_DEC_STATUS_INVALID_PARA: 
        return MAV_DEC_STATUS_INVALID_PARA;
     case IVLW_DEC_STATUS_FS_FAIL: 
        return MAV_DEC_STATUS_FS_FAIL;
     case IVLW_DEC_STATUS_FS_ASYNC_NOT_SUPPORT: 
        return MAV_DEC_STATUS_FS_ASYNC_NOT_SUPPORT;
     case IVLW_DEC_STATUS_FAIL: 
        return MAV_DEC_STATUS_FAIL;
     case IVLW_DEC_STATUS_INVALID_CALL_SEQENCE: 
        return MAV_DEC_STATUS_INVALID_CALL_SEQENCE;
     //case IVLW_DEC_STATUS_ASYNC_RD_CMD_UNAVAILABLE: 
     //   return MAV_DEC_STATUS_ASYNC_RD_CMD_UNAVAILABLE;
     case IVLW_DEC_STATUS_OK:
        return MAV_DEC_STATUS_OK;
     default: return MAV_DEC_STATUS_FAIL;
         
   }

   return MAV_DEC_STATUS_OK;
}



MAV_DEC_STATUS
_mavDecSetDecConfiguration(MAV_DECODER_HANDLE* handle)
{
  JPEG_STATUS_ENUM jpeg_status;
  IVLW_DEC_STATUS ivlw_status;
  kal_uint32 width, height;

  ivlw_status = ivlwDecQuerySrcResolution(handle->ivlwHandle, &width, &height);
  if (IVLW_DEC_STATUS_OK != ivlw_status)
  {
     return MAV_DEC_STATUS_INVALID_PARA;
  }

  if (handle->upScale)
  {
#if defined (JPEG_OUTPUT_YUV420)
     kal_uint8* buffer0 = (kal_uint8*)((((kal_uint32)handle->tempOutputBuffer)>>CPU_CACHE_LINE_BIT_OFFSET)<<CPU_CACHE_LINE_BIT_OFFSET);
     kal_uint8* buffer1 = (kal_uint8*)((((kal_uint32)buffer0 + (handle->tempOutputBufferSize / 2))>>CPU_CACHE_LINE_BIT_OFFSET)<<CPU_CACHE_LINE_BIT_OFFSET); //srcWidth * srcHeight
     kal_uint8* buffer2 = (kal_uint8*)((((kal_uint32)buffer1 + (handle->tempOutputBufferSize / 4))>>CPU_CACHE_LINE_BIT_OFFSET)<<CPU_CACHE_LINE_BIT_OFFSET); //srcWidth * srcHeight /4

     //temp output result. (this is also the resize's input data)
     jpeg_status = jpegDecSetYUVCanvas(handle->jpegHandle,
                   buffer0, buffer1, buffer2,
                   width, height,
                   JPEG_YUV_FORMAT_YUV420);
#else
     //YUV422
     kal_uint8* buffer0 = (kal_uint8*)((((kal_uint32)handle->tempOutputBuffer)>>CPU_CACHE_LINE_BIT_OFFSET)<<CPU_CACHE_LINE_BIT_OFFSET);
     kal_uint8* buffer1 = (kal_uint8*)((((kal_uint32)buffer0 + (handle->tempOutputBufferSize / 2))>>CPU_CACHE_LINE_BIT_OFFSET)<<CPU_CACHE_LINE_BIT_OFFSET); //srcWidth * srcHeight
     kal_uint8* buffer2 = (kal_uint8*)((((kal_uint32)buffer1 + (handle->tempOutputBufferSize / 4))>>CPU_CACHE_LINE_BIT_OFFSET)<<CPU_CACHE_LINE_BIT_OFFSET); //srcWidth * srcHeight /4

     jpeg_status = jpegDecSetYUVCanvas(handle->jpegHandle,
                   buffer0, buffer1, buffer2,
                   width, height,
                   JPEG_YUV_FORMAT_PACKED_UYVY422);
#endif //JPEG_OUTPUT_YUV420

     if (JPEG_STATUS_OK != jpeg_status)
     {
        return MAV_DEC_STATUS_INVALID_PARA;
     }

     jpeg_status = jpegDecSetOutputWindow(handle->jpegHandle, 0, 0, width, height);
     if (JPEG_STATUS_OK != jpeg_status)
     {
        return MAV_DEC_STATUS_INVALID_PARA;
     }

     jpeg_status = jpegDecSetClipWindow(handle->jpegHandle, 0, 0, width, height);
     if (JPEG_STATUS_OK != jpeg_status)
     {
        return MAV_DEC_STATUS_INVALID_PARA;
     }

     handle->rszSrcWnd.w = width;
     handle->rszSrcWnd.h = height;

     handle->rszSrcCanvasBuffer[0] = buffer0;
     handle->rszSrcCanvasBuffer[1] = buffer1;
     handle->rszSrcCanvasBuffer[2] = buffer2;
     handle->rszSrcCanvasBufferSize[0] = handle->tempOutputBufferSize;
     handle->rszSrcCanvasBufferSize[1] = (handle->tempOutputBufferSize >> 1);
     handle->rszSrcCanvasBufferSize[2] = (handle->tempOutputBufferSize >> 1);

  }
  else //(handle->doRsz)
  {
     if (JPEG_RGB_FORMAT_UNSUPPORTED != handle->rgbCanvasFormat)
     {
        jpeg_status = jpegDecSetRGBCanvas(handle->jpegHandle,
                    handle->canvasBuffer[0],
                    //width, height, handle->rgbCanvasFormat);
                    handle->canvasWnd.w, handle->canvasWnd.h, handle->rgbCanvasFormat);

     }
     else
     {
        jpeg_status = jpegDecSetYUVCanvas(handle->jpegHandle,
                    handle->canvasBuffer[0], handle->canvasBuffer[1], handle->canvasBuffer[2],
                    //width, height, handle->yuvCanvasFormat);
                    handle->canvasWnd.w, handle->canvasWnd.h, handle->yuvCanvasFormat);

     }
     if (JPEG_STATUS_OK != jpeg_status)
     {
        return MAV_DEC_STATUS_INVALID_PARA;
     }

     jpeg_status = jpegDecSetOutputWindow(handle->jpegHandle,
                    handle->outputWnd.x, handle->outputWnd.y, handle->outputWnd.w, handle->outputWnd.h);
     if (JPEG_STATUS_OK != jpeg_status)
     {
        return MAV_DEC_STATUS_INVALID_PARA;
     }

     jpeg_status = jpegDecSetClipWindow(handle->jpegHandle,
                    handle->clipWnd.x, handle->clipWnd.y, handle->clipWnd.w, handle->clipWnd.h);
     if (JPEG_STATUS_OK != jpeg_status)
     {
        return MAV_DEC_STATUS_INVALID_PARA;
     }
  }
  return MAV_DEC_STATUS_OK;
}




MAV_DEC_STATUS
_mavDecRsz(MAV_DECODER_HANDLE* handle)
{
   kal_bool result;
   kal_uint32 key;
   MAV_DEC_STATUS ret = MAV_DEC_STATUS_OK;
   kal_uint32 i;
   kal_uint8* rszCachableSrcCanvasBuffer = 0;
   kal_uint8* rszAlignDstCanvasBuffer = 0;
   kal_bool srcBufSwapToNC, dstBufSwapToNC;
   kal_uint32 src_buf_size;
   kal_uint32 dst_buf_size;
   
#if defined(__MTK_TARGET__)    

   if (KAL_FALSE == handle->upScale)
   {
      return MAV_DEC_STATUS_OK;
   }

   MAV_SWLA_DEBUG("RSZ",1);

   result = idp_image_resize_open(&key);
   if (KAL_TRUE != result)
   {
     return MAV_DEC_STATUS_RSZ_UNAVAILABLE;
   }

   /// config memory
   result = idp_image_resize_config(
         key,
         IDP_IMAGE_RESIZE_INTMEM_START_ADDRESS,
         0,
         IDP_IMAGE_RESIZE_INTMEM_SIZE,
         0,
         IDP_IMAGE_RESIZE_EXTMEM_START_ADDRESS,
         NULL,
         IDP_IMAGE_RESIZE_EXTMEM_SIZE,
         0,
         0);
   if (KAL_TRUE != result)
   {
     ret = MAV_DEC_STATUS_RSZ_FAIL;
     ASSERT(0);
   }

   /// config color format
   if (JPEG_RGB_FORMAT_UNSUPPORTED != handle->rgbCanvasFormat)
   {
      kal_uint8* buffer1 ;
      kal_uint8* buffer2 ;

      img_color_fmt_rgb_enum_t format = 0;
      switch(handle->rgbCanvasFormat)
      {
        case JPEG_RGB_FORMAT_RGB565: format =IMG_COLOR_FMT_RGB565;  break;
        case JPEG_RGB_FORMAT_RGB888: format =IMG_COLOR_FMT_RGB888; break;
        case JPEG_RGB_FORMAT_BGR888: format =IMG_COLOR_FMT_BGR888; break;
        case JPEG_RGB_FORMAT_ARGB8888: format =IMG_COLOR_FMT_ARGB8888; break;
        case JPEG_RGB_FORMAT_GRAYLEVEL: ASSERT(0); break;
      }

#if defined (JPEG_OUTPUT_YUV420)

      result = idp_image_resize_config(
          key,
          IDP_IMAGE_RESIZE_SRC_COLOR_FMT,
          IMG_COLOR_FMT_YUV420,   /// support: RGB565, RGB888, BGR888
          IDP_IMAGE_RESIZE_DEST_COLOR_FMT,
#if defined(MT6250)
          IMG_COLOR_FMT_PACKET_YUYV422,
#else
          format,   /// support: RGB565, RGB888, ARGB8888
#endif
          0);
#else //JPEG_OUTPUT_YUV420
      result = idp_image_resize_config(
        key,
        IDP_IMAGE_RESIZE_SRC_COLOR_FMT,
        IMG_COLOR_FMT_YUV420,	/// support: RGB565, RGB888, BGR888
        IDP_IMAGE_RESIZE_DEST_COLOR_FMT,
#if defined(MT6250)
        IMG_COLOR_FMT_PACKET_YUYV422,
#else
        format,   /// support: RGB565, RGB888, ARGB8888
#endif
        0);

#endif //JPEG_OUTPUT_YUV420


      if (KAL_TRUE != result)
      {
         ret = MAV_DEC_STATUS_RSZ_FAIL;
         ASSERT(0);
      }

      srcBufSwapToNC = KAL_FALSE;
      dstBufSwapToNC = KAL_FALSE;

      //MAV_SWLA_DEBUG("CAH",1);
      src_buf_size = (((handle->rszSrcCanvasBufferSize[0] * 2 ) >> CPU_CACHE_LINE_BIT_OFFSET) << CPU_CACHE_LINE_BIT_OFFSET) + 2 * (1<<CPU_CACHE_LINE_BIT_OFFSET);
      dst_buf_size = ((handle->canvasWnd.w * handle->canvasWnd.h * 2) >> CPU_CACHE_LINE_BIT_OFFSET) << CPU_CACHE_LINE_BIT_OFFSET;
      if (INT_QueryIsCachedRAM(handle->rszSrcCanvasBuffer[0], (handle->rszSrcCanvasBufferSize[0] * 2)))
      {
         dynamic_switch_cacheable_region((void*)&(handle->rszSrcCanvasBuffer[0]), src_buf_size, PAGE_NO_CACHE);
         srcBufSwapToNC = KAL_TRUE;
      }
      buffer1 = (kal_uint8*)((((kal_uint32)handle->rszSrcCanvasBuffer[0] + (handle->tempOutputBufferSize / 2))>>CPU_CACHE_LINE_BIT_OFFSET)<<CPU_CACHE_LINE_BIT_OFFSET); //srcWidth * srcHeight
      buffer2 = (kal_uint8*)((((kal_uint32)buffer1 + (handle->tempOutputBufferSize / 4))>>CPU_CACHE_LINE_BIT_OFFSET)<<CPU_CACHE_LINE_BIT_OFFSET); //srcWidth * srcHeight /4

      rszAlignDstCanvasBuffer = (kal_uint8*)((((kal_uint32)handle->canvasBuffer[0])>>CPU_CACHE_LINE_BIT_OFFSET)<<CPU_CACHE_LINE_BIT_OFFSET);
      if (INT_QueryIsCachedRAM(rszAlignDstCanvasBuffer, (handle->canvasWnd.w * handle->canvasWnd.h * 4)))
      {
         dynamic_switch_cacheable_region((void*)&(rszAlignDstCanvasBuffer), dst_buf_size, PAGE_NO_CACHE);
         dstBufSwapToNC = KAL_TRUE;
      }
      //MAV_SWLA_DEBUG("CAH",0);

      /// config src image address
      result = idp_image_resize_config(
          key,
          IDP_IMAGE_RESIZE_SRC_IMAGE_ADDRESS,
          handle->rszSrcCanvasBuffer[0], 
          IDP_IMAGE_RESIZE_SRC_IMAGE_U_ADDRESS,
          buffer1,
          IDP_IMAGE_RESIZE_SRC_IMAGE_V_ADDRESS,
          buffer2,
          IDP_IMAGE_RESIZE_DEST_IMAGE_ADDRESS,
          rszAlignDstCanvasBuffer,
          0);
      if (KAL_TRUE != result)
      {
         ret = MAV_DEC_STATUS_RSZ_FAIL;
         ASSERT(0);
      }
   }
   else
   {
      // no support yet ...
      ASSERT(0);
   }

   /// config src dimension
   result = idp_image_resize_config(
         key,
         IDP_IMAGE_RESIZE_SRC_WIDTH,
         handle->rszSrcWnd.w,
         IDP_IMAGE_RESIZE_SRC_HEIGHT,
         handle->rszSrcWnd.h,
         0);
   if (KAL_TRUE != result)
   {
     ret = MAV_DEC_STATUS_RSZ_FAIL;
     ASSERT(0);
   }
         
   /// config target dimension
   {
      //MT6250 will output UYVY422, because UYVY422 can color transform in place. yuv420 can't.
      //uyvy422 format's target width must be 2x Alignment.
      result = idp_image_resize_config(
         key,
         IDP_IMAGE_RESIZE_TARGET_WIDTH,
         handle->outputWnd.w,
         IDP_IMAGE_RESIZE_TARGET_HEIGHT,
         handle->outputWnd.h,
         0);
   }
   if (KAL_TRUE != result)
   {
     ret = MAV_DEC_STATUS_RSZ_FAIL;
     ASSERT(0);
   }
         
   /// config dest clipping
   {
      signed int x,y;

      x = handle->clipWnd.x - handle->outputWnd.x;
      if (x < 0)
      {
        x = handle->outputWnd.x;
      }
         

      y = handle->clipWnd.y - handle->outputWnd.y;
      if (y < 0)
      {
         y = handle->outputWnd.y;
      }
      result = idp_image_resize_config(
            key,
            IDP_IMAGE_RESIZE_ENABLE_CLIP,
            KAL_TRUE,
            IDP_IMAGE_RESIZE_CLIP_LEFT,
            x,
            IDP_IMAGE_RESIZE_CLIP_RIGHT,
            (x + handle->clipWnd.w) - 1,
            IDP_IMAGE_RESIZE_CLIP_TOP,
            y,
            IDP_IMAGE_RESIZE_CLIP_BOTTOM,
            (y + handle->clipWnd.h) - 1,
            0);   
   }
   if (KAL_TRUE != result)
   {
     ret = MAV_DEC_STATUS_RSZ_FAIL;
     ASSERT(0);
   }
         
   /// config destnation pitch
   result = idp_image_resize_config(
         key,
         IDP_IMAGE_RESIZE_ENABLE_PITCH,    /// dest pitch mode
         KAL_TRUE,
         IDP_IMAGE_RESIZE_BG_IMAGE_WIDTH,    /// dest pitch
         handle->canvasWnd.w,
         0);
   if (KAL_TRUE != result)
   {
     ret = MAV_DEC_STATUS_RSZ_FAIL;
     ASSERT(0);
   }
         
   /// config rotate
   result = idp_image_resize_config(
         key,
         IDP_IMAGE_RESIZE_ROT_ANGLE,
         IMG_ROT_ANGLE_0,
         0);
   if (KAL_TRUE != result)
   {
     ret = MAV_DEC_STATUS_RSZ_FAIL;
     ASSERT(0);
   }
         
   /// config u value and v value
   result = idp_image_resize_config(
         key,
         IDP_IMAGE_RESIZE_RESIZER_U_VALUE,
         8,
         IDP_IMAGE_RESIZE_RESIZER_V_VALUE,
         15,
         0);
   if (KAL_TRUE != result)
   {
     ret = MAV_DEC_STATUS_RSZ_FAIL;
     ASSERT(0);
   }

   /// config dithering, disable dithering
   result = idp_image_resize_config(
         key,
         IDP_IMAGE_RESIZE_IPP_ENABLE_SPATIAL_DITHERING,
         KAL_FALSE,
         IDP_IMAGE_RESIZE_ENG_CONFIG,
         KAL_TRUE,
         0);
   if (KAL_TRUE != result)
   {
     ret = MAV_DEC_STATUS_RSZ_FAIL;
     ASSERT(0);
   }

   /// start resizer
   result = idp_image_resize_start_all(key);
   if (KAL_TRUE != result)
   {
      ret = MAV_DEC_STATUS_RSZ_FAIL;
      ASSERT(0);
   }

   /// wait until resizer finished
   while (1)
   {
      kal_bool busy;
  
      result = idp_image_resize_is_busy(key, &busy);
      if (KAL_TRUE != result)
      {
         ret = MAV_DEC_STATUS_RSZ_FAIL;
         ASSERT(0);
         break;
      }
  
      if (KAL_FALSE == busy)
      {
         break;
      }
   }

   /// close resizer
   result = idp_image_resize_close(key);
   if (KAL_TRUE != result)
   {
     ret = MAV_DEC_STATUS_RSZ_FAIL;
     ASSERT(0);
   }

#if defined(MT6250)
   if (INT_QueryIsCachedRAM(rszAlignDstCanvasBuffer, (handle->canvasWnd.w * handle->canvasWnd.h * 4)))
   {
      dynamic_switch_cacheable_region((void*)&(rszAlignDstCanvasBuffer), dst_buf_size, PAGE_CACHEABLE);
      //dstBufSwapToNC = KAL_TRUE;
      if (KAL_TRUE == dstBufSwapToNC)
      {
        dstBufSwapToNC = KAL_FALSE;
      }
      else
      {
        dstBufSwapToNC = KAL_TRUE;
      }
   }

   iul_csc_yuv422itlv_to_rgb565((unsigned int *)rszAlignDstCanvasBuffer, (unsigned short*)rszAlignDstCanvasBuffer, handle->canvasWnd.w, handle->canvasWnd.h);
#endif
   //MAV_SWLA_DEBUG("CAH",1);
   if (srcBufSwapToNC)
   {
      dynamic_switch_cacheable_region((void*)&(handle->rszSrcCanvasBuffer[0]),src_buf_size , PAGE_CACHEABLE);
   }
   
   if (dstBufSwapToNC)
   {
      dynamic_switch_cacheable_region((void*)&(rszAlignDstCanvasBuffer), dst_buf_size , PAGE_CACHEABLE);
   }
   //MAV_SWLA_DEBUG("CAH",0);

   //MAV_SWLA_DEBUG("MCY",1);
   if (!IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)handle->canvasBuffer[0]))
   {
      memcpy(handle->canvasBuffer[0], rszAlignDstCanvasBuffer, (handle->canvasWnd.w * handle->canvasWnd.h * 2));

   }
   //MAV_SWLA_DEBUG("MCY",1);

_return:

   MAV_SWLA_DEBUG("RSZ",0);

#endif //#if defined(__MTK_TARGET__) 

   return ret;
}




MAV_DEC_STATUS
mavDecSetSrcFile(
   MAV_DECODER_HANDLE* handle, 
   STFSAL *fp, 
   kal_uint8 *fsalCacheAddr,
   kal_uint32 fsalCacheSize,
   kal_uint8 *fsalReadBufferAddr, 
   kal_uint32 fsalReadBufferSize)
{
   FSAL_Status fsal_status;
   IVLW_DEC_STATUS status;
   JPEG_STATUS_ENUM jpeg_status;
   unsigned int frame_file_offset;
   unsigned int frame_file_size;

   if (NULL == fp)
   {
      return MAV_DEC_STATUS_INVALID_PARA;
   }

   status = ivlwDecSetSrcFile(handle->ivlwHandle, fp);
   if (status != IVLW_DEC_STATUS_OK)
   {
      return _mavDecConvertIvlwStatusToMavStatus(status);
   }

   status = 
   ivlwDecQueryFrameInfo(handle->ivlwHandle, 
                       0, 
                       &frame_file_offset,
                       &frame_file_size);
   if (status != IVLW_DEC_STATUS_OK)
   {
      ASSERT(0);
   }
   fsal_status = FSAL_Seek(fp, frame_file_offset);
   if (FSAL_OK != fsal_status)
   {
      return IVLW_DEC_STATUS_FS_FAIL;
   }
  
   jpeg_status = jpegDecSetSourceFile(handle->jpegHandle,
                                 fp,
                                 fsalReadBufferAddr,
                                 fsalReadBufferSize,
                                 fsalCacheAddr,
                                 fsalCacheSize);
   if (JPEG_STATUS_OK != jpeg_status)
   {
      return MAV_DEC_STATUS_INVALID_PARA;
   }

   handle->fp = fp;
   handle->fsalCacheAddr = fsalCacheAddr;
   handle->fsalCacheSize = fsalCacheSize;
   handle->fsalReadBufferAddr = fsalReadBufferAddr;
   handle->fsalReadBufferSize = fsalReadBufferSize;
  
   return MAV_DEC_STATUS_OK;
}


MAV_DEC_STATUS
mavDecQuerySrcImageResolution(
   MAV_DECODER_HANDLE* handle,
   kal_uint32 *width,
   kal_uint32 *height)
{
   IVLW_DEC_STATUS status;

   if (NULL == handle->fp)
   {
      return MAV_DEC_STATUS_INVALID_CALL_SEQENCE;
   }

   status = ivlwDecQuerySrcResolution(handle->ivlwHandle, width, height);
   if ((status != IVLW_DEC_STATUS_OK) || 
       (*width == 0) || 
       (*height == 0))
   {
      ASSERT(0);
   }
   return MAV_DEC_STATUS_OK;
}



MAV_DEC_STATUS
mavDecQueryWorkingMemory(
   MAV_DECODER_HANDLE* handle,       
   kal_uint32 *intMemorySizeBest,   
   kal_uint32 *intMemorySizeMinimum,
   kal_uint32 *extMemorySizeBest,   
   kal_uint32 *extMemorySizeMinimum)
{
   JPEG_STATUS_ENUM jpeg_status;
   IVLW_DEC_STATUS ivlw_status;
   kal_uint32 width, height;

   jpeg_status = jpegDecQueryWorkingMemory(handle->jpegHandle,
                                 intMemorySizeBest,
                                 intMemorySizeMinimum,
                                 extMemorySizeBest,
                                 extMemorySizeMinimum);
   if (JPEG_STATUS_OK != jpeg_status)
   {
      return MAV_DEC_STATUS_INVALID_PARA;
   }

   ivlw_status = ivlwDecQuerySrcResolution(handle->ivlwHandle, &width, &height);
   if (IVLW_DEC_STATUS_OK != ivlw_status)
   {
      return MAV_DEC_STATUS_INVALID_PARA;
   }
  
   handle->upScale = KAL_FALSE;

#if defined(__MTK_TARGET__) 

   if ((width < handle->outputWnd.w) || (height < handle->outputWnd.h))
   {
      handle->upScale = KAL_TRUE;
   }
#else
   // for MODIS case, always use JPEG to processing Rsz case.
#endif 

#if defined(MT6256)
   //For MT6256, Dicrect couple to MDP RSZ. MAUI_03192214: avoid concurrency issue
   handle->upScale = KAL_FALSE;
#endif //(MT6256)
   
   handle->tempOutputBufferSize = 0;
   if (handle->upScale)
   {
      handle->tempOutputBufferSize = width * height * 2; // 2: temp output: JPEG_YUV_FORMAT_YUV420
      *extMemorySizeMinimum += handle->tempOutputBufferSize;
      *extMemorySizeBest += handle->tempOutputBufferSize;
   }
   return MAV_DEC_STATUS_OK;
}




MAV_DEC_STATUS
mavDecSetWorkingMemory(
   MAV_DECODER_HANDLE* handle,       
   kal_uint32 *intMemoryAddr,   
   kal_uint32  intMemorySize,
   kal_uint32 *extMemoryAddr,   
   kal_uint32  extMemorySize)
{
   JPEG_STATUS_ENUM jpeg_status;

   if (extMemorySize < handle->tempOutputBufferSize)
   {
      return MAV_DEC_STATUS_MEM_UNAVAILABLE;
   }

   jpeg_status = jpegDecSetWorkingMemory(handle->jpegHandle,
                                 intMemoryAddr,
                                 intMemorySize,
                                 extMemoryAddr,
                                 (extMemorySize - handle->tempOutputBufferSize));
   if (JPEG_STATUS_OK != jpeg_status)
   {
      return MAV_DEC_STATUS_INVALID_PARA;
   }

   handle->tempOutputBuffer = ((kal_uint8*)extMemoryAddr) + extMemorySize - handle->tempOutputBufferSize;
   return MAV_DEC_STATUS_OK;
}





MAV_DEC_STATUS
mavDecSetRGBCanvas(
   MAV_DECODER_HANDLE* handle,       
   void *buffer, 
   kal_uint32 width, 
   kal_uint32 height, 
   JPEG_RGB_FORMAT_ENUM format)
{
   JPEG_STATUS_ENUM jpeg_status;

   handle->canvasWnd.x = 0;
   handle->canvasWnd.y = 0;
   handle->canvasWnd.w = width;
   handle->canvasWnd.h = height;
   handle->rgbCanvasFormat = format;
   handle->canvasBuffer[0] = buffer;
   return MAV_DEC_STATUS_OK;
}



MAV_DEC_STATUS
mavDecSetYUVCanvas(
   MAV_DECODER_HANDLE* handle,       
   void  *canvas_yuv_buffer0,
   void  *canvas_yuv_buffer1,
   void  *canvas_yuv_buffer2,
   kal_uint32   width,
   kal_uint32   height,
   JPEG_YUV_FORMAT_ENUM   format)
{
   JPEG_STATUS_ENUM jpeg_status;

   handle->canvasWnd.x = 0;
   handle->canvasWnd.y = 0;
   handle->canvasWnd.w = width;
   handle->canvasWnd.h = height;
   handle->rgbCanvasFormat = format;
   handle->canvasBuffer[0] = canvas_yuv_buffer0;
   handle->canvasBuffer[1] = canvas_yuv_buffer1;
   handle->canvasBuffer[2] = canvas_yuv_buffer2;
   return MAV_DEC_STATUS_OK;
}



MAV_DEC_STATUS
mavDecSetOutputWindow(
   MAV_DECODER_HANDLE* handle, 
   kal_int32 x, 
   kal_int32 y, 
   kal_uint32 w, 
   kal_uint32 h )
{
   handle->outputWnd.x = x;
   handle->outputWnd.y = y;
   handle->outputWnd.w = w;
   handle->outputWnd.h = h;

   return MAV_DEC_STATUS_OK;
}



MAV_DEC_STATUS
mavDecSetClipWindow(
   MAV_DECODER_HANDLE* handle, 
   kal_int32 x, 
   kal_int32 y, 
   kal_uint32 w, 
   kal_uint32 h )
{
   handle->clipWnd.x = x;
   handle->clipWnd.y = y;
   handle->clipWnd.w = w;
   handle->clipWnd.h = h;
   return MAV_DEC_STATUS_OK;
}



MAV_DEC_STATUS
mavDecSetCallbackFunction(
   MAV_DECODER_HANDLE* handle, 
   kal_int32 (*callback_function)(JPEG_CODEC_STATE_ENUM state))
{
   JPEG_STATUS_ENUM jpeg_status;

   jpeg_status = jpegDecSetCallbackFunction(handle->jpegHandle,callback_function);
   if (JPEG_STATUS_OK != jpeg_status)
   {
      return MAV_DEC_STATUS_INVALID_PARA;
   }
   return MAV_DEC_STATUS_OK;
}



MAV_DEC_STATUS
mavDecSetCheckAbortFunction(
   MAV_DECODER_HANDLE* handle, 
   kal_int32 (*check_abort_func)(void))
{
   JPEG_STATUS_ENUM jpeg_status;

   jpeg_status = jpegDecSetCheckAbortFunction(handle->jpegHandle, check_abort_func);
   if (JPEG_STATUS_OK != jpeg_status)
   {
      return MAV_DEC_STATUS_INVALID_PARA;
   }
   return MAV_DEC_STATUS_OK;
}


MAV_DEC_STATUS
mavDecSetDecodeMode(
   MAV_DECODER_HANDLE* handle, 
   JPEG_DECODE_MODE_ENUM mode)
{
   JPEG_STATUS_ENUM jpeg_status;

   jpeg_status = jpegDecSetDecodeMode(handle->jpegHandle, mode);
   if (JPEG_STATUS_OK != jpeg_status)
   {
      return MAV_DEC_STATUS_INVALID_PARA;
   }
   return MAV_DEC_STATUS_OK;
}



MAV_DEC_STATUS
mavDecGetLastError(
   MAV_DECODER_HANDLE* handle)
{
   return jpegDecGetLastError(handle->jpegHandle);
}



MAV_DEC_STATUS
mavDecQueryFrameCount(
   MAV_DECODER_HANDLE* handle,
   kal_uint32 *frame_count)
{
   IVLW_DEC_STATUS status;
   status = ivlwDecQueryFrameCount(handle->ivlwHandle, frame_count);
   if (status != IVLW_DEC_STATUS_OK)
   {
      ASSERT(0);
   }
   handle->frameCnt = *frame_count;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
   return MAV_DEC_STATUS_OK;
}



MAV_DEC_STATUS
mavDecStart(
   MAV_DECODER_HANDLE* handle,
   unsigned int frameIdx )
{
   FSAL_Status fsal_status;
   unsigned int frame_file_offset;
   unsigned int frame_file_size;
   JPEG_DECODER *jpegHandle = handle->jpegHandle;

   IVLW_DEC_STATUS ivlw_status;
   JPEG_STATUS_ENUM jpeg_status;
   MAV_DEC_STATUS ret = MAV_DEC_STATUS_OK;


   MAV_SWLA_DEBUG("MJP",1);

   ret = _mavDecSetDecConfiguration(handle);
   if (MAV_DEC_STATUS_OK != ret)
   {
      ASSERT(0);
   }

   if (IVLW_DEC_STATUS_OK != ivlwDecQueryFrameInfo(handle->ivlwHandle, frameIdx, &frame_file_offset, &frame_file_size))
   {
      ret = MAV_DEC_STATUS_IVLW_FAIL; 
      ASSERT(0);
   }

   fsal_status = FSAL_Seek(handle->fp, frame_file_offset);
   if (FSAL_OK != fsal_status)
   {
      ret = MAV_DEC_STATUS_FS_FAIL; 
      goto _return;
   }

   jpeg_status = jpegDecSetSourceFile(handle->jpegHandle,
                                 handle->fp,
                                 handle->fsalReadBufferAddr,
                                 handle->fsalReadBufferSize,
                                 handle->fsalCacheAddr,
                                 handle->fsalCacheSize);
   if (JPEG_STATUS_OK != jpeg_status)
   {
      ret = MAV_DEC_STATUS_INVALID_PARA; 
      goto _return;
   }

   jpeg_status = jpegDecStart(handle->jpegHandle);
   if (JPEG_STATUS_OK != jpeg_status)
   {
      handle->jpegStatus = jpegDecGetLastError(handle->jpegHandle);
      ret = MAV_DEC_STATUS_JPEG_FAIL; 
      goto _return;
   }
   MAV_SWLA_DEBUG("MJP",0);

   if (KAL_TRUE == handle->upScale)
   {
      ret = _mavDecRsz(handle);
      if (MAV_DEC_STATUS_RSZ_UNAVAILABLE == ret)
      {
         ASSERT(0);
      }
   }

_return:

   return ret;
}



MAV_DEC_STATUS
mavDecReset(MAV_DECODER_HANDLE* handle)
{
  JPEG_STATUS_ENUM jpeg_status;
  
  jpeg_status = jpegDecReset(handle->jpegHandle);
   if (JPEG_STATUS_OK != jpeg_status)
   {
     handle->jpegStatus = jpegDecGetLastError(handle->jpegHandle);
     return MAV_DEC_STATUS_JPEG_FAIL;
   }
   return MAV_DEC_STATUS_OK;
}


MAV_DEC_STATUS
mavDecQueryIsMAV(
   MAV_DECODER_HANDLE* handle,
   kal_bool* yOrn)
{
   IVLW_DEC_STATUS status;
   IVLW_FILE_TYPE file_type;
   
   status = ivlwDecQuerySrcFileType(handle->ivlwHandle, &file_type);
   if (IVLW_DEC_STATUS_OK != status)
   {
      *yOrn = KAL_FALSE;
      return MAV_DEC_STATUS_INVALID_FILE;
   }

   *yOrn = KAL_FALSE;
   if (IVLW_FILE_TYPE_MAV == file_type)
   {
      *yOrn = KAL_TRUE;
   }

   return MAV_DEC_STATUS_OK;
}


/*
IVLW_DEC_STATUS
mavDecAbort(MAV_DECODER_HANDLE *handle, mav_abort_callback cb)
{
   IVLW_DEC_STATUS status;

   status = ivlwDecAbortGetFrameSrcBuf(handle->ivlwHandle);
   if (IVLW_DEC_STATUS_OK != status)
   {
      return MAV_DEC_STATUS_INVALID_PARA;
   }
}
*/

#endif //#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)
