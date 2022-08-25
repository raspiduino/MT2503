/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
/*******************************************************************************
 * Filename:
 * ---------
 *  png_decode_api.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  PNG HAL decode interface
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *==============================================================================
 *******************************************************************************/
 
/// #define USE_SW_PNG_DECODER
#include "png_decode_api.h"
#include "png_decode_enum.h"
#include "png_memory_usage.h"
#include "png_decode_structure.h"
#include "png_decoder_int.h"
#include "gfx_cache_switch_behavior_enum.h"

#include "kal_public_api.h"
#include "kal_general_types.h"
#include "string.h"
#include "fsal.h"
#include "drv_features_png.h"
    
#if defined(__MTK_TARGET__)
   /// #include "init.h"
   /// #include "cache_sw.h"
   /// #include "app_buff_alloc.h"
   #define malloc get_ctrl_buffer
   #define free   free_ctrl_buffer
   #define dbg_log 
#elif defined (WIN32)
    #include <stdlib.h>
    #define dbg_log printf
#else
    #error "Must define platform!"
#endif

#if defined(USE_HW_PNG_DECODER)
   #include "rs_buffer.h"
   #include "png_drv_common.h"
   #include "png_decode.h"
   static PNG_DECODER png_hw_decoder = {0};
   
#elif defined(USE_SW_PNG_DECODER)
   /// interface to SW PNG decoder
   #include "png_decoder.h"
///   static png_config_struct png_dec_image_config;
///   static png_inform_struct png_dec_info;
   /// static PNG_STATUS_ENUM png_image_png_status;     
   extern void sw_png_hook_png_decode_progress_callback(kal_int32 (*png_decode_progress_callback)(void));
#endif

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && !defined(__MTK_TARGET__)
#undef __DYNAMIC_SWITCH_CACHEABILITY__
#endif


#define SW_PNGDEC_FILE_BUFFER_SIZE_MAX        (16*1024)
#define SW_PNGDEC_FILE_BUFFER_SIZE_MIN        (1024)

/// HW_PNG_FILE_BUFFER_SIZE_MIN is recommanded to be at least 1KB, and sequential buffer must be 4-byte aligned
#define HW_PNG_FILE_BUFFER_SIZE_MIN        (1024)

#if defined(USE_SW_PNG_DECODER)

void sw_png_status_callback(void *handlePtr, PNG_STATUS_ENUM png_status)
{
    PNG_DECODER_HANDLE handle = (PNG_DECODER_HANDLE)handlePtr;
    handle->png_image_png_status = png_status;	
}
#endif



PNG_STATUS_ENUM pngDecGetDecoder(PNG_DECODER_TYPE_ENUM decoderType, PNG_DECODER_HANDLE *handlePtr)
{
   PNG_DECODER_HANDLE handle = NULL;

      
   switch (decoderType)
   {
   case PNG_DECODER_TYPE_HW:
      #if defined (USE_HW_PNG_DECODER)      
      {
          handle = &png_hw_decoder;
          
          if (PNG_DECODER_STATE_FREE != handle->decodeState)
          {   
             *handlePtr = NULL;
             handle->lastStatus = PNG_STATUS_INVALID_OPERATION;
             return handle->lastStatus;
          }
             
          handle->decoderType = PNG_DECODER_TYPE_HW;
          
          /// Init HW decoder           
          {
               PNG_STATUS_ENUM ret;
               
               ret = pngInit();
               
               if (PNG_STATUS_OK != ret)
               {
                   handle->lastStatus = ret;
                   return handle->lastStatus;
               }
          }
          break;
      }
      #else
      {
          *handlePtr = NULL;
          return PNG_STATUS_DECODER_UNAVAILABLE;
      }
      #endif
   case PNG_DECODER_TYPE_SW:
      #if defined (USE_SW_PNG_DECODER)
      {          
          handle = (PNG_DECODER_HANDLE)malloc(sizeof(PNG_DECODER));
          memset(handle, 0, sizeof(PNG_DECODER));
          /// memset(&png_dec_image_config, 0x0, sizeof(png_dec_image_config));
            
          /// Check for alignment.
          if ((kal_uint32)handle & 0x3)
          {
             ASSERT(0);
          }
          handle->decoderType = PNG_DECODER_TYPE_SW;
      }
      #else
      {
          *handlePtr = NULL;
          return PNG_STATUS_DECODER_UNAVAILABLE;
      }
      #endif
      break;

   case PNG_DECODER_TYPE_DEFAULT:
      #if defined (__MTK_TARGET__)
      {
          #if defined (USE_HW_PNG_DECODER)
              handle = &png_hw_decoder;

              /// The desired HW is already in use.              
              handle->decoderType = PNG_DECODER_TYPE_HW;
              
          #elif defined (USE_SW_PNG_DECODER)
          
              handle = (PNG_DECODER_HANDLE)malloc(sizeof(PNG_DECODER));
              memset(handle, 0, sizeof(PNG_DECODER));

              /// Check for alignment.
              if ((kal_uint32)handle & 0x3)
              {
                 ASSERT(0);
              }
              handle->decoderType = PNG_DECODER_TYPE_SW;
              
          #else
          
              *handlePtr = NULL;
              handle->lastStatus = PNG_STATUS_DECODER_UNAVAILABLE;
              return  handle->lastStatus;
          #endif
      }
      #else   ///< for Modis, use SW Decoder or not support
      {
          #if defined (USE_SW_PNG_DECODER)
              handle = (PNG_DECODER_HANDLE)malloc(sizeof(PNG_DECODER));
              memset(handle, 0, sizeof(PNG_DECODER));

              /// Check for alignment.
              if ((kal_uint32)handle & 0x3)
              {
                 ASSERT(0);
              }
              handle->decoderType = PNG_DECODER_TYPE_SW;
          #else
              *handlePtr = NULL;
              return PNG_STATUS_DECODER_UNAVAILABLE;
          #endif
      }
      #endif
      break;
   default:
      ASSERT(0);
      *handlePtr = NULL;
      return PNG_STATUS_DECODER_UNAVAILABLE;
      break;
   }
   
    handle->decodeState = PNG_DECODER_STATE_IDLE;
   *handlePtr = handle;    
    handle->lastStatus = PNG_STATUS_OK;
    return handle->lastStatus;
}



PNG_STATUS_ENUM pngDecReleaseDecoder(PNG_DECODER_HANDLE handle)
{
    PNG_STATUS_ENUM status = PNG_STATUS_OK;
     
    if (!handle)
    {
       return PNG_STATUS_INVALID_HANDLE;
    }
            
    switch (handle->decoderType)        
    {
    case PNG_DECODER_TYPE_HW:   
        #if defined(USE_HW_PNG_DECODER)
        {
            PNG_STATUS_ENUM ret;
            ret = pngReset();
            ret = pngFinalize();
            ASSERT(ret != PNG_STATUS_INVALID_OPERATION);
            status = ret;
        }
        #endif
            
        memset(handle, 0, sizeof(PNG_DECODER));         
        break;
    case PNG_DECODER_TYPE_SW:       
        free(handle);      
        status = PNG_STATUS_OK;    
        break;
    default:
        ASSERT(0);   
        status = PNG_STATUS_INVALIDE_DECODER_TYPE; 
    }
      
    /// handle->decodeState = PNG_DECODER_STATE_FREE;    
    return status;
}



PNG_STATUS_ENUM pngDecQueryDecoderType(PNG_DECODER_HANDLE handle, PNG_DECODER_TYPE_ENUM *decoderType)
{
    if (!handle)
    {
       return PNG_STATUS_INVALID_HANDLE;
    }

    switch (handle->decoderType)
    {
    case PNG_DECODER_TYPE_HW:
        *decoderType = PNG_DECODER_TYPE_HW;
        break;
    case PNG_DECODER_TYPE_SW:
        *decoderType = PNG_DECODER_TYPE_SW;
        break;
    default:
        return PNG_STATUS_DECODER_UNAVAILABLE;
    }

    handle->lastStatus = PNG_STATUS_OK;
    return handle->lastStatus;
}



PNG_STATUS_ENUM pngDecReset(PNG_DECODER_HANDLE handle)
{
    if (!handle)
    {
       return PNG_STATUS_INVALID_HANDLE;
    }
        
    
    #if defined(USE_HW_PNG_DECODER)
    if (PNG_DECODER_TYPE_HW == handle->decoderType)
    {
        PNG_STATUS_ENUM ret;
        ret = pngReset();
        if (PNG_STATUS_OK != ret)
        {
            handle->lastStatus = ret;
            return handle->lastStatus;
        }
    }
    #endif
    
    handle->lastStatus = PNG_STATUS_OK;
    return handle->lastStatus;
}



PNG_STATUS_ENUM pngDecHookCallback(PNG_DECODER_HANDLE handle, 
                                   void (*pngdec_callback)(PNG_STATUS_ENUM status))
{
    if (!handle)
    {
       return PNG_STATUS_INVALID_HANDLE;
    }

    handle->pngdec_callback = pngdec_callback;

    #if defined(USE_HW_PNG_DECODER)
    if (PNG_DECODER_TYPE_HW == handle->decoderType)
    {
        pngHookCallback(handle->pngdec_callback);
    } 
    #endif

    return PNG_STATUS_OK;
}



PNG_STATUS_ENUM pngDecQueryWorkingBufferSize(PNG_DECODER_HANDLE handle, kal_uint32* internal_mem_sz, kal_uint32* external_mem_sz)
{
    if (!handle)
    { 
       *internal_mem_sz = 0;
	   *external_mem_sz = 0;
       return PNG_STATUS_INVALID_HANDLE;
    }

    #if defined(USE_HW_PNG_DECODER)
        png_drv_get_working_buffer_size(internal_mem_sz, external_mem_sz);    
    #elif defined(USE_SW_PNG_DECODER)
        *internal_mem_sz = PNG_MAX_INT_MEM_SIZE;
        *external_mem_sz = PNG_MAX_EXT_MEM_SIZE - SW_PNGDEC_FILE_BUFFER_SIZE_MAX; /// substract file buffer size
    #else
        *internal_mem_sz = 0;
        *external_mem_sz = 0;                
    #endif  
    
    return PNG_STATUS_OK;
}



PNG_STATUS_ENUM pngDecSetWorkingBuffer(PNG_DECODER_HANDLE handle, kal_uint32* internalBuf, kal_uint32* externalBuf)
{
    if (!handle)
    {
       return PNG_STATUS_INVALID_HANDLE;
    }
    
    handle->internalMem = (void *)internalBuf;
    handle->externalMem = (void *)externalBuf;

    #if defined(USE_HW_PNG_DECODER)
    if (PNG_DECODER_TYPE_HW == handle->decoderType)
    {
       pngSetWorkingBuffer((kal_uint32 *)internalBuf, (kal_uint32 *)externalBuf);
    }
    #endif

    return PNG_STATUS_OK;
}



PNG_STATUS_ENUM pngDecQueryFileBufferSize(PNG_DECODER_HANDLE handle,
                                          kal_uint32 *bestFileBuffSize,
                                          kal_uint32 *minFileBuffSize)
{
    if (!handle)
    {
	   *minFileBuffSize  = 0;
	   *bestFileBuffSize = 0;		
       return PNG_STATUS_INVALID_HANDLE;
    }

    switch(handle->decoderType)
    {
    case PNG_DECODER_TYPE_SW:
        *bestFileBuffSize = SW_PNGDEC_FILE_BUFFER_SIZE_MAX;
        *minFileBuffSize  = SW_PNGDEC_FILE_BUFFER_SIZE_MIN;
        break;
    case PNG_DECODER_TYPE_HW:
        *bestFileBuffSize = HW_PNG_FILE_BUFFER_SIZE_MIN;
        *minFileBuffSize  = HW_PNG_FILE_BUFFER_SIZE_MIN;
        break;
    default:
        ASSERT(0);
        break;
    }

    return PNG_STATUS_OK;
}



PNG_STATUS_ENUM pngDecSetSourceFile(PNG_DECODER_HANDLE handle, STFSAL *fp,
                                    void *fileBufferAddr, kal_int32 fileBufferSize)
{
    /// file buffer
    ASSERT(0 == ((kal_uint32)fileBufferAddr & 3));

    if (!handle)
    {
       return PNG_STATUS_INVALID_HANDLE;
    }

    /// Check input parameters.
    if (NULL == fp)
    {
       handle->lastStatus = PNG_STATUS_INVALID_SOURCE_FILE;
       return handle->lastStatus;
    }

    handle->fileBufferAddr = fileBufferAddr;
    handle->fileBufferSize = fileBufferSize;
    handle->fileHandle     = fp;

#if 0 /// defined(__DYNAMIC_SWITCH_CACHEABILITY__)
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
#endif /// __DYNAMIC_SWITCH_CACHEABILITY__

    if (FSAL_OK != FSAL_GetFileSize(fp, &(handle->fileSize)))
    {
       handle->lastStatus = PNG_STATUS_INVALID_SOURCE_FILE;
       return handle->lastStatus;
    }

    if (FSAL_OK != FSAL_GetCurPos(fp, &(handle->imageOffsetInFile)))
    {
       handle->lastStatus = PNG_STATUS_INVALID_SOURCE_FILE;
       return handle->lastStatus;
    }

    pngDecParseImage(handle);

    return PNG_STATUS_OK;
}




PNG_STATUS_ENUM pngDecGetImgDimension(PNG_DECODER_HANDLE handle, kal_int32* src_w, kal_int32* src_h)
{
    if (!handle)
    {
       return PNG_STATUS_INVALID_HANDLE;
    }
    
    *src_w = handle->pngImageWidth; 
    *src_h = handle->pngImageHeight;
    
    return PNG_STATUS_OK;
}



PNG_STATUS_ENUM pngDecSetBgColorOut(PNG_DECODER_HANDLE handle)
{
    if (!handle)
    {
       return PNG_STATUS_INVALID_HANDLE;
    }

    #if defined(USE_HW_PNG_DECODER)
    if (PNG_DECODER_TYPE_HW == handle->decoderType)
    {
        pngSetBgColorOut();
    }    
    #endif

    return PNG_STATUS_OK;
}



kal_int32 pngDecIsFileAlphaExist(PNG_DECODER_HANDLE handle)
{
    if (!handle)
    {
       return PNG_STATUS_INVALID_HANDLE;
    }

    #if defined(USE_HW_PNG_DECODER)
    if (PNG_DECODER_TYPE_HW == handle->decoderType)
    {
        kal_int32 isExist;
        isExist = pngFileAlphaExist();
        return isExist;
    }
    #endif

    return PNG_STATUS_OK;
}



kal_int32 pngDecIsFileTransparencyExist(PNG_DECODER_HANDLE handle)
{
    if (!handle)
    {
       return PNG_STATUS_INVALID_HANDLE;
    }

    #if defined(USE_HW_PNG_DECODER)
    if (PNG_DECODER_TYPE_HW == handle->decoderType)
    {
        kal_int32 isExist;
        isExist = pngFileTransparencyExist();
        return isExist;
    }
    #endif

    return PNG_STATUS_OK;
}


   
PNG_STATUS_ENUM pngDecGetDecodeState(PNG_DECODER_HANDLE handle, PNG_DECODER_STATE_ENUM *state)
{
    if (!handle)
    {
       return PNG_STATUS_INVALID_HANDLE;
    }    
   
    
    #if defined(USE_HW_PNG_DECODER)
    if (PNG_DECODER_TYPE_HW == handle->decoderType)
    {
        PNG_STATUS_ENUM ret;
        PNG_DECODER_STATE_ENUM decoderState;
        
        ret = pngGetDecodeState(&decoderState);
        
        if (PNG_STATUS_OK != ret)
        {         
            handle->lastStatus = PNG_STATUS_ERROR_GENERAL_ERROR;       
            return handle->lastStatus;
        }        
        else
        {                           
            *state = PNG_DECODER_STATE_IDLE;                                  
        }
  
        return handle->lastStatus;
    }
    #elif defined(USE_SW_PNG_DECODER)    
    {
        *state = (PNG_DECODER_STATE_ENUM)handle->decodeState;        
    }
    #endif

    return PNG_STATUS_OK;
}



PNG_STATUS_ENUM pngDecSetTimeoutValue(PNG_DECODER_HANDLE handle, kal_int32 timeout_msec)
{
    if (!handle)
    {
       return PNG_STATUS_INVALID_HANDLE;
    }
    
    handle->timeoutMsec = timeout_msec;
    
    #if defined(USE_HW_PNG_DECODER)
    if (PNG_DECODER_TYPE_HW == handle->decoderType)
    {
        PNG_STATUS_ENUM ret;
        ret = pngSetTimeoutValue(timeout_msec);
        handle->lastStatus = ret;
        return handle->lastStatus;
    }
    #endif

    return PNG_STATUS_OK;
}



PNG_STATUS_ENUM pngDecSetAlphaBlending(PNG_DECODER_HANDLE handle, void* blendBuffAddr, kal_uint32 blndBuffW, kal_uint32 blndBuffH,
                                       PNG_DECODE_COLOR_FORMAT_ENUM color_format, PNG_BLEND_MODE_ENUM blend_mode)
{
    if (!handle)
    {
       return PNG_STATUS_INVALID_HANDLE;
    }

    handle->blendingBufferStartAddr = blendBuffAddr;
    handle->blend_buf_format        = color_format;
    handle->blendingMode = blend_mode;
    
    handle->blendingBufferWidth  = blndBuffW;
    handle->blendingBufferHeight = blndBuffH;
    
    #if defined(USE_HW_PNG_DECODER)
    if (PNG_DECODER_TYPE_HW == handle->decoderType)
    {    
        pngSetBlendingMode(blend_mode, color_format);
        
        if (!((PNG_BLEND_NONE == blend_mode) || (NULL == blendBuffAddr)))
        {
            pngSetBlendingBuffer(blendBuffAddr);   
        }                
    }
    #endif
    
    return PNG_STATUS_OK;
}



PNG_STATUS_ENUM pngDecSetColorReplacement(PNG_DECODER_HANDLE handle, kal_bool rep_enable, 
                                          kal_uint8 new_r, kal_uint8 new_g, kal_uint8 new_b,
                                          kal_uint8 ori_r, kal_uint8 ori_g, kal_uint8 ori_b)
{
    if (!handle)
    {
       return PNG_STATUS_INVALID_HANDLE;
    }

    handle->orgRepColor_R = ori_r;
    handle->orgRepColor_G = ori_g;
    handle->orgRepColor_B = ori_b;

    handle->newRepColor_R = new_r;
    handle->newRepColor_G = new_g;
    handle->newRepColor_B = new_b;

    handle->clrRepEnable = rep_enable;
    
    #if defined(USE_HW_PNG_DECODER)
    if (PNG_DECODER_TYPE_HW == handle->decoderType)
    {        
        png_color orgRep, newRep;
        orgRep.red   = ori_r;
        orgRep.green = ori_g;
        orgRep.blue  = ori_b;
            
        newRep.red   = ori_r;
        newRep.green = ori_g;
        newRep.blue  = ori_b;            
        pngSetReplaceColor(orgRep, newRep);                    
    }
    #endif
   
    return PNG_STATUS_OK;
}



PNG_STATUS_ENUM pngDecQueryDitheringSupport(PNG_DECODER_HANDLE handle)
{
    if (!handle)
    {
       return PNG_STATUS_INVALID_HANDLE;
    }

    if (PNG_DECODER_TYPE_SW == handle->decoderType)
    {
        #if defined(__SPATIAL_DITHERING__)
            return PNG_STATUS_OK;
        #else
            return PNG_STATUS_UNSUPPORTED_FEATURE;
        #endif
    }
    else if(PNG_DECODER_TYPE_HW == handle->decoderType)
    {
        return PNG_STATUS_UNSUPPORTED_FEATURE;
    }
    else
    {
        ASSERT(0);
    }

    return PNG_STATUS_OK;
}



PNG_STATUS_ENUM pngDecEnableDithering(PNG_DECODER_HANDLE handle, kal_bool dithering_enable)
{
    if (!handle)
    {
       return PNG_STATUS_INVALID_HANDLE;
    }

    if (PNG_DECODER_TYPE_SW == handle->decoderType)
    {
        #if defined(__SPATIAL_DITHERING__)
            handle->ditheringEnable = dithering_enable;
        #else
            handle->ditheringEnable = KAL_FALSE;
        #endif        
    }    
    else
    {
        return PNG_STATUS_UNSUPPORTED_FEATURE;
    }            
    
    return PNG_STATUS_OK;
}



PNG_STATUS_ENUM pngDecSetCanvas(PNG_DECODER_HANDLE handle, 
                                void *canvasStartAddr, 
                                kal_int32 width, kal_int32 height, 
                                PNG_DECODE_COLOR_FORMAT_ENUM out_color_format)
{
    if (!handle)
    {
       return PNG_STATUS_INVALID_HANDLE;
    }
    
    handle->canvasStartAddr   = canvasStartAddr;         
    handle->canvasWidth       = width;
    handle->canvasHeight      = height;
    handle->canvasColorFormat = out_color_format;
    
    switch(out_color_format)
    {
    case PNG_FORMAT_RGB565:       
       handle->canvasBufferSize = (2 * width * height);
       break;
    case PNG_FORMAT_RGB888:       
       handle->canvasBufferSize = (3 * width * height);
       break;
    case PNG_FORMAT_PARGB8888:   
    case PNG_FORMAT_ARGB8888:       
       handle->canvasBufferSize = (4 * width * height);
       break;
    case PNG_FORMAT_ARGB4444:   
       handle->canvasBufferSize = (2 * width * height);
       break; 
    case PNG_FORMAT_ARGB6666: 
	  case PNG_FORMAT_PARGB6666:		
       handle->canvasBufferSize = (3 * width * height);
       break;        
    default:
       ASSERT(0);
    }            
    
    #if defined(USE_HW_PNG_DECODER)
    if (PNG_DECODER_TYPE_HW == handle->decoderType)
    {    
        pngSetCanvas(canvasStartAddr, width, height, out_color_format);
    }
    #endif
    
    return PNG_STATUS_OK;    
}                                
                                
    
    
PNG_STATUS_ENUM pngDecSetOutputWindow(PNG_DECODER_HANDLE handle, kal_int32 up_left_x, kal_int32 up_left_y, kal_int32 dst_w, kal_int32 dst_h)
{
    if (!handle)
    {
       return PNG_STATUS_INVALID_HANDLE;
    }    
    
    handle->outputWindow_x      = up_left_x;
    handle->outputWindow_y      = up_left_y;
    handle->outputWindowWidth   = dst_w;
    handle->outputWindowHeight  = dst_h;    
    
    #if defined(USE_HW_PNG_DECODER)
    if (PNG_DECODER_TYPE_HW == handle->decoderType)
    {    
        pngSetOutputWindow(up_left_x, up_left_y, dst_w, dst_h);
    }
    #endif

    return PNG_STATUS_OK;
}                                



PNG_STATUS_ENUM pngDecSetClipWindow(PNG_DECODER_HANDLE handle, kal_int32 up_left_x, kal_int32 up_left_y, kal_int32 clip_w, kal_int32 clip_h)
{
    if (!handle)
    {
       return PNG_STATUS_INVALID_HANDLE;
    }    
    
    handle->clipWindow_ul_x  = up_left_x;
    handle->clipWindow_ul_y  = up_left_y;
    handle->clipWindow_dr_x  = (up_left_x + clip_w - 1);
    handle->clipWindow_dr_y  = (up_left_y + clip_h - 1);    
    
    #if defined(USE_HW_PNG_DECODER)
    if (PNG_DECODER_TYPE_HW == handle->decoderType)
    {        
        pngSetClipWindow(handle->clipWindow_ul_x, handle->clipWindow_ul_y , handle->clipWindow_dr_x, handle->clipWindow_dr_y);
    }
    #endif    

    return PNG_STATUS_OK;
}



PNG_STATUS_ENUM pngDecDecodeStart(PNG_DECODER_HANDLE handle)
{
    if (!handle)
    {
       return PNG_STATUS_INVALID_HANDLE;
    }

    if (PNG_DECODER_STATE_IDLE != handle->decodeState ||
        PNG_STATUS_OK != handle->lastStatus)
    {
       handle->lastStatus = PNG_STATUS_INVALID_OPERATION;
       return handle->lastStatus;
    }
 
    handle->decodeState = PNG_DECODER_STATE_DECODING;     
    
    #if defined(USE_HW_PNG_DECODER)
    if (PNG_DECODER_TYPE_HW == handle->decoderType)
    {
        PNG_STATUS_ENUM ret; 
        
        ret = pngDecodeStart();
        
        handle->lastStatus = ret;
        return handle->lastStatus; 
    }  
    #endif
                              
    #if defined(USE_SW_PNG_DECODER)
    if (PNG_DECODER_TYPE_SW == handle->decoderType)
    {
        PNG_STATUS_ENUM png_dec_status;
        
        handle->png_dec_image_config.cb       = sw_png_status_callback;
        handle->png_dec_image_config.cb_param = (void *)handle;
        
        pngDecSetupSWConfiguration(handle, &handle->png_dec_image_config);                
        png_dec_status = png_decode_start(&handle->png_dec_image_config, &handle->png_dec_info);        
               
        if (png_dec_status != PNG_STATUS_IN_DECODING)
        {  
           /// if not equal to PNG_STATUS_IN_DECODING which means something wrong 
           /// inside decorder and return error code
           handle->png_image_png_status = png_dec_status;
        }   

        handle->lastStatus = handle->png_image_png_status;                
        return handle->lastStatus; 
    }
    #endif
    
    return PNG_STATUS_OK;
}



PNG_STATUS_ENUM pngDecDecodeResume(PNG_DECODER_HANDLE handle)
{
    if (!handle)
    {
       return PNG_STATUS_INVALID_HANDLE;
    }
       
    handle->decodeState = PNG_DECODER_STATE_DECODING;   
       
    #if defined(USE_HW_PNG_DECODER)
    if (PNG_DECODER_TYPE_HW == handle->decoderType)
    {
        kal_bool is_src_end;
        kal_int32 read_size;
        kal_uint8 *write_ptr;
        kal_uint32 g_hwpng_src_size = handle->g_hwpng_src_size;
        PNG_STATUS_ENUM decode_result;
        /* read and set new source data and resume decoding */
        read_size = min(rsbGetSpaceAvailable(&handle->g_hwpng_rsb), g_hwpng_src_size);
        if (g_hwpng_src_size == read_size) 
        {
            is_src_end = KAL_TRUE;
        }
        else 
        {
            is_src_end = KAL_FALSE;
        }
                
        rsbGetWritePointer(&handle->g_hwpng_rsb, (void **)&write_ptr);
        FSAL_Read_Bytes(handle->g_hwpng_read_fp, write_ptr, read_size);
        rsbAdjustWritePointer(&handle->g_hwpng_rsb, read_size);        
        
        if((0 == g_hwpng_src_size) && (0 == read_size))
        {
            handle->lastStatus  = PNG_STATUS_INVALID_SOURCE_FILE;
            return handle->lastStatus;           
        }
        else
        {
            /// re-fill data and decode
            g_hwpng_src_size -= read_size;
            pngSetSourceData(&handle->g_hwpng_rsb, is_src_end);         
            decode_result = pngDecodeResume();
            
            if (PNG_STATUS_OK != decode_result)
            {
                handle->lastStatus  = decode_result;
                return handle->lastStatus;
            }
        }              
    }
    #endif
   
    return PNG_STATUS_OK;
}



PNG_STATUS_ENUM pngDecSetCheckAbortFunction(PNG_DECODER_HANDLE handle, kal_int32 (*check_abort_func)(void))
{
    if (!handle)
    {
       return PNG_STATUS_INVALID_HANDLE;
    }

   switch (handle->decoderType)
   {
   case PNG_DECODER_TYPE_HW:
      handle->lastStatus = PNG_STATUS_INVALID_OPERATION;
      break;

   case PNG_DECODER_TYPE_SW:
      handle->check_abort_func = check_abort_func;
      
      #if defined(USE_SW_PNG_DECODER)
      /// if (PNG_DECODER_TYPE_SW == handle->decoderType)    
      /// {
      ///     sw_png_hook_png_decode_progress_callback(check_abort_func);    
      /// }      
      #endif
      break;
      
   default:
      handle->lastStatus = PNG_STATUS_INVALID_OPERATION;
   }

   return handle->lastStatus;    
}



PNG_STATUS_ENUM pngDecSetDstBufferSwitchBehavior(PNG_DECODER_HANDLE handle, 
                                                 GFX_CACHE_SWITCH_BEHAVIOR_ENUM behavior)
{
    if (!handle)
    {
       return PNG_STATUS_INVALID_HANDLE;
    }

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)    
    handle->dstBufferCacheSwitchBehavior = behavior;         
#endif

    return PNG_STATUS_OK;    
}
   
