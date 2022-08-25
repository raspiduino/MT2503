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
 *   ipp_interface.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Code body of IPP(image post process) interface
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
#include "swipp_interface.h"
#include "swipp_enum.h"
#include "image_effect_struct.h"
#include "image_effect_post.h"
#include "ipp_enum.h"
#include "ipp_features.h"
#include "drv_gfx_stack_switch_manager.h"

/// RHR suggestion
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "string.h"


kal_uint32 _effect_supported_list[IPP_BLOCK_EFFECT_EROSION + 1] = 
{
#ifdef _IPP_PIXEL_EFFECT_GRAYSCALE
   IPP_EFFECT_HW_SUPPORTED,
#else
   IPP_EFFECT_NOT_SUPPORTED,
#endif

#ifdef _IPP_PIXEL_EFFECT_SEPIA
   IPP_EFFECT_HW_SUPPORTED,
#else
   IPP_EFFECT_NOT_SUPPORTED,
#endif

#ifdef _IPP_PIXEL_EFFECT_SEPIAGREEN
   IPP_EFFECT_HW_SUPPORTED,
#else
   IPP_EFFECT_NOT_SUPPORTED,
#endif

#ifdef _IPP_PIXEL_EFFECT_SEPIABLUE
   IPP_EFFECT_HW_SUPPORTED,
#else
   IPP_EFFECT_NOT_SUPPORTED,
#endif

#ifdef _IPP_PIXEL_EFFECT_COLORINV
   IPP_EFFECT_HW_SUPPORTED,
#else
   IPP_EFFECT_NOT_SUPPORTED,
#endif

#ifdef _IPP_PIXEL_EFFECT_GRAYINV
   IPP_EFFECT_HW_SUPPORTED,
#else
   IPP_EFFECT_NOT_SUPPORTED,
#endif


//Block effect
#ifdef _IPP_BLOCK_EFFECT_WATERCOLOR
   IPP_EFFECT_SW_SUPPORTED,
#else
   IPP_EFFECT_NOT_SUPPORTED,
#endif


#ifdef _IPP_BLOCK_EFFECT_LIGHTBLUR
   IPP_EFFECT_SW_SUPPORTED,
#else
   IPP_EFFECT_NOT_SUPPORTED,
#endif


#ifdef _IPP_BLOCK_EFFECT_BLUR
   IPP_EFFECT_SW_SUPPORTED,
#else
   IPP_EFFECT_NOT_SUPPORTED,
#endif


#ifdef _IPP_BLOCK_EFFECT_STRONGBLUR
   IPP_EFFECT_SW_SUPPORTED,
#else
   IPP_EFFECT_NOT_SUPPORTED,
#endif


#ifdef _IPP_BLOCK_EFFECT_UNSHARP
   IPP_EFFECT_SW_SUPPORTED,
#else
   IPP_EFFECT_NOT_SUPPORTED,
#endif


#ifdef _IPP_BLOCK_EFFECT_SHARPEN
   IPP_EFFECT_SW_SUPPORTED,
#else
   IPP_EFFECT_NOT_SUPPORTED,
#endif

#ifdef _IPP_BLOCK_EFFECT_MORESHARPEN
   IPP_EFFECT_SW_SUPPORTED,
#else
   IPP_EFFECT_NOT_SUPPORTED,
#endif

#ifdef _IPP_BLOCK_EFFECT_MEDIAN
   IPP_EFFECT_SW_SUPPORTED,
#else
   IPP_EFFECT_NOT_SUPPORTED,
#endif

#ifdef _IPP_BLOCK_EFFECT_DILATION
   IPP_EFFECT_SW_SUPPORTED,
#else
   IPP_EFFECT_NOT_SUPPORTED,
#endif

#ifdef _IPP_BLOCK_EFFECT_EROSION
  IPP_EFFECT_SW_SUPPORTED,
#else
   IPP_EFFECT_NOT_SUPPORTED,
#endif


};


static kal_uint32 _effect_supported_count = 0;


void ipp_set_effect_supported_list(void)
{
   kal_uint32 i;

   for (i = 0; i < (IPP_BLOCK_EFFECT_EROSION + 1); i++)
   {
       if (IPP_EFFECT_NOT_SUPPORTED != _effect_supported_list[i])
       {
          _effect_supported_count++;
       }
   }
}



kal_uint32 ippQuerySupportedEffects(IPP_ENUM_EFFECT_SUPPORTER *supported_list, kal_uint32 *list_size)
{
   kal_uint32 size_of_supported_list = sizeof (_effect_supported_list);

   ASSERT(NULL != list_size);

   if (NULL == supported_list)
   {
      if (_effect_supported_count == 0)
      {
         ipp_set_effect_supported_list();
      }
      *list_size = size_of_supported_list;
   }
   else
   {
      if (0 != _effect_supported_count)
      {
         if (*list_size < size_of_supported_list)
         {
             ASSERT(0);
         }
         memcpy(supported_list, &_effect_supported_list, size_of_supported_list);
      }
   }

   return _effect_supported_count;
}


#if defined(__MTK_TARGET__)
#if (defined(DRV_PIXEL_EFFECT_SUPPORT) || defined(DRV_BLOCK_EFFECT_SUPPORT))

IMAGE_EFFECT_DEC_STRUCT effect_dec_para;
static kal_uint32 _block_effect_flag = 0;
static kal_uint32 _old_block_effect_flag = 0;

static kal_uint32 _ipp_handle = 0;
static kal_mutexid _ipp_mutex = 0;

static IPP_STATE_ENUM _convert_state_from_swipp_to_ipp(SWIPP_STATE_ENUM state)
{
  switch (state)
  {
  case SWIPP_STATE_IDLE:
    return IPP_STATE_IDLE;

  case SWIPP_STATE_PROCESS:
    return IPP_STATE_PROCESS;

  case SWIPP_STATE_PAUSING:
    return IPP_STATE_PAUSING;

  case SWIPP_STATE_PAUSED:
    return IPP_STATE_PAUSED;

  case SWIPP_STATE_ABORTING:
    return IPP_STATE_ABORTING;

  case SWIPP_STATE_ABORTED:
    return IPP_STATE_ABORTED;

  default:
    ASSERT(0);
  }
  return IPP_STATE_IDLE;
}



static kal_uint32 _convert_effect_to_swipp_effect_index(IPP_EFFECT_ENUM ipp_effect, SWIPP_EFFECT_ENUM* swipp_effect)
{
  switch(ipp_effect)
  {
  case IPP_BLOCK_EFFECT_WATERCOLOR:
    *swipp_effect = SWIPP_EFFECT_WATERCOLOR;
    return KAL_TRUE;

  case IPP_BLOCK_EFFECT_LIGHTBLUR:
    *swipp_effect = SWIPP_EFFECT_LIGHTBLUR;
    return KAL_TRUE;

  case IPP_BLOCK_EFFECT_BLUR:
    *swipp_effect = SWIPP_EFFECT_BLUR;
    return KAL_TRUE;

  case IPP_BLOCK_EFFECT_STRONGBLUR:
    *swipp_effect = SWIPP_EFFECT_STRONGBLUR;
    return KAL_TRUE;

  case IPP_BLOCK_EFFECT_UNSHARP:
    *swipp_effect = SWIPP_EFFECT_UNSHARP;
    return KAL_TRUE;

  case IPP_BLOCK_EFFECT_SHARPEN:
    *swipp_effect = SWIPP_EFFECT_SHARPEN;
    return KAL_TRUE;

  case IPP_BLOCK_EFFECT_MORESHARPEN:
    *swipp_effect = SWIPP_EFFECT_MORESHARPEN;
    return KAL_TRUE;

  case IPP_BLOCK_EFFECT_MEDIAN:
    *swipp_effect = SWIPP_EFFECT_MEDIAN;
    return KAL_TRUE;

  case IPP_BLOCK_EFFECT_DILATION:
    *swipp_effect = SWIPP_EFFECT_DILATION;
    return KAL_TRUE;

  case IPP_BLOCK_EFFECT_EROSION:
    *swipp_effect = SWIPP_EFFECT_EROSION;
    return KAL_TRUE;

  default:
    return KAL_FALSE;
  }

  return KAL_FALSE;
}


static void _convert_effect_to_legacy_effect_index(IPP_EFFECT_ENUM ipp_effect, kal_uint32* effect)
{
  switch(ipp_effect)
  {
  case IPP_PIXEL_EFFECT_GRAYSCALE:
    *effect = IPP_CAM_EFFECT_DEC_GRAYSCALE;
    return ;

  case IPP_PIXEL_EFFECT_SEPIA:
    *effect = IPP_CAM_EFFECT_DEC_SEPIA;
    return ;

  case IPP_PIXEL_EFFECT_SEPIAGREEN:
    *effect = IPP_CAM_EFFECT_DEC_SEPIAGREEN;
    return ;

  case IPP_PIXEL_EFFECT_SEPIABLUE:
    *effect = IPP_CAM_EFFECT_DEC_SEPIABLUE;
    return ;

  case IPP_PIXEL_EFFECT_COLORINV:
    *effect = IPP_CAM_EFFECT_DEC_COLORINV;
    return ;
	
  case IPP_PIXEL_EFFECT_GRAYINV :
    *effect = IPP_CAM_EFFECT_DEC_GRAYINV;
    return ;

  case IPP_BLOCK_EFFECT_WATERCOLOR:
    *effect = IPP_CAM_EFFECT_DEC_WATERCOLOR;
    return ;

  case IPP_BLOCK_EFFECT_LIGHTBLUR:
    *effect = IPP_CAM_EFFECT_DEC_LIGHTBLUR;
    return ;

  case IPP_BLOCK_EFFECT_BLUR:
    *effect = IPP_CAM_EFFECT_DEC_BLUR;
    return ;

  case IPP_BLOCK_EFFECT_STRONGBLUR:
    *effect = IPP_CAM_EFFECT_DEC_STRONGBLUR;
    return ;

  case IPP_BLOCK_EFFECT_UNSHARP:
    *effect = IPP_CAM_EFFECT_DEC_UNSHARP;
    return ;

  case IPP_BLOCK_EFFECT_SHARPEN:
    *effect = IPP_CAM_EFFECT_DEC_SHARPEN;
    return ;

  case IPP_BLOCK_EFFECT_MORESHARPEN:
    *effect = IPP_CAM_EFFECT_DEC_MORESHARPEN;
    return ;

  case IPP_BLOCK_EFFECT_MEDIAN:
    *effect = IPP_CAM_EFFECT_DEC_MEDIAN;
    return ;

  case IPP_BLOCK_EFFECT_DILATION:
    *effect = IPP_CAM_EFFECT_DEC_DILATION;
    return ;

  case IPP_BLOCK_EFFECT_EROSION:
    *effect = IPP_CAM_EFFECT_DEC_EROSION;
    return ;

  default:
    return ;
  }

 return ;
}



/** DESCRIPTION :
 *     Get the ipp handle for image post process. This handle is used only for effects supported by SW. \n
 *  @return return a non-zero value if success, otherwise fail
 */
kal_int32 ippGetHandle(void)
{
   kal_int32 handle = _ipp_handle;

   if (!_ipp_mutex)
   {
    _ipp_mutex = kal_create_mutex("ipp_mutex");
   }

   if (handle != 0)
   {
       /// someone use swipp now
       ASSERT(0);
   }

   /// Take mutex
   kal_take_mutex(_ipp_mutex);

   if (0 == _ipp_handle)
   {
      while (0 == _ipp_handle)
      {
         _ipp_handle = rand();
      }
      handle = _ipp_handle;
   }

   /// Release mutex
   kal_give_mutex(_ipp_mutex);

#if defined(DRV_BLOCK_EFFECT_SW_SUPPORT)
   swippSetHandle(handle);
#endif

   return handle;
   
}


/** DESCRIPTION :
 *     Call this function to reset IPP. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @return None
 *  @remark This function resets the all informations to zero. But for the handle, you still need to call ippReleaseHandle to release it.
 */
void ippResetPorcess(kal_uint32 handle)
{
   if (handle != _ipp_handle)
   {
      /// This should never happen!
      ASSERT(0);
   }

#if defined(DRV_BLOCK_EFFECT_SW_SUPPORT)
  if (_block_effect_flag)
  {
    swippResetPorcess(handle);
  }	
#endif

   memset((kal_uint8*)(&effect_dec_para), 0, sizeof (effect_dec_para));
   //_ipp_handle = 0;
   _old_block_effect_flag = _block_effect_flag;
   _block_effect_flag = 0;
}



/** DESCRIPTION :
 *     Release the ipp handle.\n
 *  @param[in] handle The returned value of swippGetHandle
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return error code IPP_STATUS_ERROR_RELEASE_HANDLE_AT_PROCESSING_OR_PAUSING if the process is doing. \n
 */
IPP_STATUS_ENUM ippReleaseHandle(kal_uint32 handle)
{
   IPP_STATE_ENUM state;

   if (handle != _ipp_handle)
   {
      /// This should never happen!
      ASSERT(0);
   }

#if defined(DRV_BLOCK_EFFECT_SW_SUPPORT)
   if ((_old_block_effect_flag) || (_block_effect_flag))
   {
      state = _convert_state_from_swipp_to_ipp(swippQueryState(handle));   
      if ((state != IPP_STATE_IDLE) && (state != SWIPP_STATE_PAUSED))
      {
         ASSERT(0);//return IPP_STATUS_ERROR_RELEASE_HANDLE_AT_PROCESSING_OR_PAUSING;
      }
   }
   ippResetPorcess(handle);
   swippReleaseHandle(handle);
#endif

   kal_take_mutex(_ipp_mutex);
   _ipp_handle = 0;   
   kal_give_mutex(_ipp_mutex);
   _old_block_effect_flag = 0;
   _block_effect_flag = 0;
   
   return IPP_STATUS_OK;

}



/** DESCRIPTION :
 *     Set information of the source image. \n
 *  @param[in] handle The returned value of ippGetHandle
 *  @param[in] src_addr Address of the source image.
 *  @param[in] width Width of the source image.
 *  @param[in] height Height of the source image.
 *  @param[in] color_format color format of the source image.
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_SRC_INFO when changing information under pause atate.
 */
IPP_STATUS_ENUM ippSetSrcInfo(kal_uint32 handle, kal_uint8 *src_addr, kal_uint32 width, kal_uint32 height, IPP_COLOR_FORMAT_ENUM color_format)
{
   kal_uint32 bpp = 0;

   if (handle != _ipp_handle)
   {
      /// This should never happen!
      ASSERT(0);
   }

   switch (color_format)
   {
   case IPP_COLOR_FORMAT_RGB565:
      effect_dec_para.data_type = IBR1_TYPE_RGB565;  // for integration with legacy IPP
      bpp = 2;
      break;
   case IPP_COLOR_FORMAT_RGB888:
      effect_dec_para.data_type = IBR1_TYPE_RGB888;  // for integration with legacy IPP
      bpp = 3;
      break;
   default:
      ASSERT(0);
      break;
   }

#if defined(DRV_BLOCK_EFFECT_SW_SUPPORT)
   if (_block_effect_flag)
   {
      if (SWIPP_STATUS_ERROR_AT_PAUSE_CHANGE_SRC_INFO == swippSetSrcInfo(handle, src_addr, width, height, bpp))
      {
         return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_SRC_INFO;
      }
   }
#endif

   effect_dec_para.data_order= IBR1_ORDER_BGR888;  // for integration with legacy IPP
   effect_dec_para.source_buffer_address = (kal_uint32) src_addr;
   effect_dec_para.src_color_fmt = color_format;
   effect_dec_para.image_width = width;
   effect_dec_para.image_height = height;

   return IPP_STATUS_OK;   
}



/** DESCRIPTION :
 *     Set information of the destination image. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @param[in] dst_addr Address to store the processed image.
 *  @param[in] color_format color format of the destination image.
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_INVALID_DST_SIZE if the destination buffer size is wrong.
 *          Return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_DST_INFO when changing information under pause atate.
 */
IPP_STATUS_ENUM ippSetDstInfo(kal_uint32 handle, kal_uint8 *dst_addr, kal_uint32 buffer_size, IPP_COLOR_FORMAT_ENUM color_format)
{
   kal_uint32 dst_bpp = 0;
   
   if (handle != _ipp_handle)
   {
      /// This should never happen!
      ASSERT(0);
   }

   switch (color_format)
   {
   case IPP_COLOR_FORMAT_RGB565:
      dst_bpp = 2;
      break;
   case IPP_COLOR_FORMAT_RGB888:
      dst_bpp = 3;
      break;
   default:
      ASSERT(0);
      break;
   }

#if defined(DRV_BLOCK_EFFECT_SW_SUPPORT)
   if (_block_effect_flag)
   {
      SWIPP_STATUS_ENUM status;
   
      status = swippSetDstInfo(handle, dst_addr, buffer_size, dst_bpp);
      if (SWIPP_STATUS_ERROR_AT_PAUSE_CHANGE_DST_INFO == status)
      {
         return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_DST_INFO;
      }
      else if (SWIPP_STATUS_ERROR_INVALID_DST_SIZE == status)
      {
         return IPP_STATUS_ERROR_INVALID_DST_SIZE;
      }
   }
#endif

   effect_dec_para.dest_color_mode= IMGDMA_IBW_OUTPUT_RGB565;  // for integration with legacy IPP, only used  for 6228 series
   effect_dec_para.dest1_buffer_address = (kal_uint32) dst_addr;
   effect_dec_para.dest1_buffer_size = buffer_size;
   effect_dec_para.dest_color_fmt = color_format;

   return IPP_STATUS_OK;
}



/** DESCRIPTION :
 *     Query the size of working buffer\n
 *  @param[in] effect The block effect that will be applied
 *  @param[in] width The width of the image.
 *  @param[in] height The height of the image
 *  @return None
 *  @remark The size of the working buffer is depended on the block effect. Now only the watercolor will need working buffer.
 *  @remark The buffer size must at least be equal to the source image or the clipped image under such condition.
 */
kal_uint32 ippQueryWorkingMemory(IPP_EFFECT_ENUM effect, kal_uint32 width, kal_uint32 height, kal_uint32 src_bpp)
{

#if defined(DRV_BLOCK_EFFECT_SW_SUPPORT)
   if (_block_effect_flag)
   {
      SWIPP_EFFECT_ENUM swipp_block_effect = 0;
	  
      _convert_effect_to_swipp_effect_index(effect, &swipp_block_effect);  
      effect_dec_para.dest2_buffer_size = swippQueryWorkingMemory(swipp_block_effect, width, height, src_bpp);
      return effect_dec_para.dest2_buffer_size;
   }
#endif

   if (IPP_BLOCK_EFFECT_WATERCOLOR == effect)
   {
       effect_dec_para.dest2_buffer_size = width * height * src_bpp;
       return effect_dec_para.dest2_buffer_size;
   }

   effect_dec_para.dest2_buffer_size = 0;
   return 0;
}



/** DESCRIPTION :
 *     Set the working buffer information. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @param[in] buffer_addr Address of the working buffer.
 *  @param[in] buffer_size Size of the working buffer.
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_WORKING_BUFFER when changing information under pause atate.
 *  @remark The size of the working buffer must at least be equal to the source image or the clipped image.
 *  @remark Call this function after you have called ippSetSrcInfo. \n
 */
IPP_STATUS_ENUM ippSetWorkingMemory(kal_uint32 handle, kal_uint8 *buffer_addr, kal_uint32 buffer_size)
{
   if (handle != _ipp_handle)
   {
      /// This should never happen!
      ASSERT(0);
   }

#if defined(DRV_BLOCK_EFFECT_SW_SUPPORT)
   if (_block_effect_flag)
   {
      if (SWIPP_STATUS_ERROR_AT_PAUSE_CHANGE_WORKING_BUFFER == swippSetWorkingMemory(handle, buffer_addr, buffer_size))
      {
         return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_WORKING_BUFFER;
      }
   }
#endif

   effect_dec_para.dest2_buffer_address = (kal_uint32) buffer_addr;
   effect_dec_para.dest2_buffer_size = buffer_size;

   return IPP_STATUS_OK;
}



/** DESCRIPTION :
 *     Set the effect index. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @param[in] effect  This parameter indicates which effect will be applied.
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_EFFECT if change effect when the processing is paused.
 *          Return IPP_STATUS_ERROR_INVALID_EFFECT if the effect is invalid.
 *  @remark This API should be called after ippGetHandle
 */
IPP_STATUS_ENUM ippSetEffect(kal_uint32 handle, IPP_EFFECT_ENUM effect_index)
{
   SWIPP_EFFECT_ENUM swipp_block_effect = 0;
   kal_uint32 legacy_effect_index = 0;

   if (handle != _ipp_handle)
   {
      /// This should never happen!
      ASSERT(0);
   }

   if ((effect_index < IPP_PIXEL_EFFECT_GRAYSCALE) || (effect_index > IPP_BLOCK_EFFECT_EROSION))
   {
      return IPP_STATUS_ERROR_INVALID_EFFECT;
   }

   _old_block_effect_flag = 0;
   _block_effect_flag = 0;

#if defined(DRV_BLOCK_EFFECT_SW_SUPPORT)
   _block_effect_flag = _convert_effect_to_swipp_effect_index(effect_index, &swipp_block_effect);

   if (_block_effect_flag)
   {
     if (SWIPP_STATUS_ERROR_AT_PAUSE_CHANGE_EFFECT == swippSetBlockEffect(handle, swipp_block_effect))
     {
        return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_EFFECT;
     }
   }
#endif

   _convert_effect_to_legacy_effect_index(effect_index, &legacy_effect_index);

   effect_dec_para.effect_index = legacy_effect_index;

   return IPP_STATUS_OK;
}


/** DESCRIPTION :
 *     Query whether HW or SW supports the effect index. \n
 *  @param[in] effect_index Effect index
 *  @param[in] effect_owner This parameter indicates the effect is supported by HW/SW/NotSupported.
 *  @return Return IPP_STATUS_OK if success. \n
 */
IPP_STATUS_ENUM ippQueryEffectSupporter(IPP_EFFECT_ENUM effect_index, IPP_ENUM_EFFECT_SUPPORTER *effect_owner)
{

   if ((effect_index < IPP_PIXEL_EFFECT_GRAYSCALE) || (effect_index > IPP_BLOCK_EFFECT_EROSION))
   {
      return IPP_STATUS_ERROR_INVALID_EFFECT;
   }

   if (0 == _effect_supported_count)
   {
      ipp_set_effect_supported_list();
   }
   
   *effect_owner = _effect_supported_list[effect_index];
   return IPP_STATUS_OK;
}



/** DESCRIPTION :
 *     call this function to abort current processing of image effect. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_HW_NOT_SUPPORT if the effect is supported by HW.
 *  @remark Hw doesn't support abort/pause/resume functionality.
 */
IPP_STATUS_ENUM ippAbortProcess(kal_uint32 handle)
{
   if (handle != _ipp_handle)
   {
      /// This should never happen!
      ASSERT(0);
   }

#if defined(DRV_BLOCK_EFFECT_SW_SUPPORT)
  if (_block_effect_flag)
  {
     swippAbortProcess(handle);
     return IPP_STATUS_OK;
  }
#endif

  return IPP_STATUS_ERROR_HW_NOT_SUPPORT;
}



/** DESCRIPTION :
 *     call this function to pause the processing of image effect\n
 *  @param[in] handle The returned value of swippGetHandle
 *  @return Return IPP_STATUS_OK if success.
 *          Return IPP_STATUS_ERROR_HW_NOT_SUPPORT if the effect is supported by HW.
 *  @remark Hw doesn't support abort/pause/resume functionality.
 */
IPP_STATUS_ENUM ippPauseProcess(kal_uint32 handle)
{
   if (handle != _ipp_handle)
   {
      /// This should never happen!
      ASSERT(0);
   }


#if defined(DRV_BLOCK_EFFECT_SW_SUPPORT)

  if (_block_effect_flag)
  {
     swippPauseProcess(handle);
     return IPP_STATUS_OK;
  }

#endif

  return IPP_STATUS_ERROR_HW_NOT_SUPPORT;
}



/** DESCRIPTION :
 *     call this function to query if the process is terminated. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @return Return the current state value of IPP_STATE_ENUM if the current effect is supported by SW
 *          Return IPP_STATE_HW_STATE if the current effect is supported by HW
 *  @remark Hw doesn't support abort/pause/resume functionality.
 */
IPP_STATE_ENUM ippQueryState(kal_uint32 handle)
{

   if (handle != _ipp_handle)
   {
      /// This should never happen!
      ASSERT(0);
   }

#if defined(DRV_BLOCK_EFFECT_SW_SUPPORT)

  if (_block_effect_flag)
  {
    return _convert_state_from_swipp_to_ipp(swippQueryState(handle));
  }

#endif

  return IPP_STATE_HW;
}



/** DESCRIPTION :
 *     call this function to resume the processing of image effect\n
 *  @param[in] handle The returned value of swippGetHandle
 *  @return Return IPP_STATUS_OK if set effect successfully.\n
  *          Return IPP_STATUS_ERROR_HW_NOT_SUPPORT if the current effect is supported by HW.
 *  @remark Hw doesn't support abort/pause/resume functionality.
 */
IPP_STATE_ENUM ippResumeProcess(kal_uint32 handle)
{
   if (handle != _ipp_handle)
   {
      /// This should never happen!
      ASSERT(0);
   }

#if defined(DRV_BLOCK_EFFECT_SW_SUPPORT)

  if (_block_effect_flag)
  {
    swippResumeProcess(handle);
    return IPP_STATUS_OK;
  }

#endif

  return IPP_STATUS_ERROR_HW_NOT_SUPPORT;
}



/** DESCRIPTION :
 *     call this function to query the processing progress \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @return Return completion percentage of processing image supported by SW.\n
 *          Return -1 if the current effect is supported by HW.
 */
kal_int32 ippQueryProgress(kal_uint32 handle)
{
   if (handle != _ipp_handle)
   {
      /// This should never happen!
      ASSERT(0);
   }

#if defined(DRV_BLOCK_EFFECT_SW_SUPPORT)

  if (_block_effect_flag)
  {
    return swippQueryProgress(handle);
  }

#endif

  return -1;
}



/** DESCRIPTION :
 *     call this function to set clipping information\n
 *  @param[in] handle The returned value of swippGetHandle
 *  @param[in] pivot_x The x coordinates of starting point for the clipping window
 *  @param[in] pivot_y The y coordinates of starting point for the clipping window
 *  @param[in] clip_width Width of the clipping window
 *  @param[in] clip_height Height of the clipping window
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_CLIP_INFO when changing clipping information under pause atate.
 *          Return IPP_STATUS_ERROR_HW_NOT_SUPPORT when this effect is supported by HW. However, HW doesn't provide clipping.
 *  @remark If the return value is IPP_STATUS_ERROR_AT_PAUSE_CHANGE_CLIP_INFO, it means you should not call this function until the previous request has be done. \n
 *          You can call ippQueryState to check whether the processing is done, meaning the state is at IDLE. \n
*/
IPP_STATUS_ENUM ippSetClippingInfo(kal_uint32 handle, kal_uint32 clip_x, kal_uint32 clip_y, kal_uint32 clip_width, kal_uint32 clip_height)
{
   if (handle != _ipp_handle)
   {
      /// This should never happen!
      ASSERT(0);
   }

#if defined(DRV_BLOCK_EFFECT_SW_SUPPORT)
  if (_block_effect_flag)
  {
     if (SWIPP_STATUS_ERROR_AT_PAUSE_CHANGE_CLIP_INFO == swippSetClippingInfo(handle, clip_x, clip_y, clip_width, clip_height))
     {
        return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_CLIP_INFO;
     }
     return IPP_STATUS_OK;
  }
#endif

  return IPP_STATUS_ERROR_HW_NOT_SUPPORT;
}


/** DESCRIPTION :
 *     call this function to set the callback function, used to report processing progress periodically\n
 *  @param[in] handle The returned value of swippGetHandle
 *  @param[in] callback The callback function supported by the AP
 *  @param[in] interval The periodic interval. The uint is mini-second.
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_CALLBACK when changing progress callback function under pause atate.\n
 *          Return IPP_STATUS_ERROR_HW_NOT_SUPPORT when this effect is supported by HW. However, HW doesn't provide query progress.\n
 *  @remark
 */
IPP_STATUS_ENUM ippSetProgressCallbckFunc(kal_uint32 handle, kal_uint32 (*callback)(kal_int32 percentage), kal_uint32 interval)
{
   if (handle != _ipp_handle)
   {
      /// This should never happen!
      ASSERT(0);
   }

#if defined(DRV_BLOCK_EFFECT_SW_SUPPORT)
  if (_block_effect_flag)
  {
      if (SWIPP_STATUS_ERROR_AT_PAUSE_CHANGE_CALLBACK == swippSetProgressCallbckFunc(handle, callback, interval))
      {
         return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_CALLBACK;
      }
      return IPP_STATUS_OK;
   }
#endif

  return IPP_STATUS_ERROR_HW_NOT_SUPPORT;
}



/** DESCRIPTION :
 *     call this function to start processing image. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @return None
 */
void ippStartProcess(kal_uint32 handle)
{

   if (handle != _ipp_handle)
   {
      /// This should never happen!
      ASSERT(0);
   }

#if defined(DRV_BLOCK_EFFECT_SW_SUPPORT)
   if (_block_effect_flag)
   {

      #if defined(__MTK_TARGET__)
      {
         kal_uint32 stack_size = SW_IPP_TASK_STACK_SIZE;
         kal_uint32 ret = 0;
         void *stack_ptr = drv_gfx_stkmgr_get_stack(stack_size);
         if (stack_ptr)
         {
            extern kal_uint32 INT_SwitchStackToRun(void *stack_start, kal_uint32 stack_size, kal_func_ptr func, kal_uint32 argc, ...);
            ret = INT_SwitchStackToRun(stack_ptr, stack_size, (kal_func_ptr)swippStartProcess, 1, handle);
            drv_gfx_stkmgr_release_stack(stack_ptr);
         }
         else
         {
            swippStartProcess(handle);
         }
      }
      #else
      {
         swippStartProcess(handle);
      }
      #endif
      return;
   }
#endif

   image_effect_dec_process(&effect_dec_para);
   return;
}



#endif /// (defined(DRV_PIXEL_EFFECT_SUPPORT) || defined(DRV_BLOCK_EFFECT_SUPPORT))

#endif //__MTK_TARGET__

#if (!defined(__MTK_TARGET__) || ((!defined(DRV_PIXEL_EFFECT_SUPPORT)) && (!defined(DRV_BLOCK_EFFECT_SUPPORT))))

/// No Effect is Supported for Image Processing
kal_int32 ippGetHandle(void)
{
   //ASSERT(0);
   return 0;
}



IPP_STATUS_ENUM ippReleaseHandle(kal_uint32 handle)
{
   //ASSERT(0);
   return IPP_STATUS_ERROR;
}



IPP_STATUS_ENUM ippSetSrcInfo(kal_uint32 handle, kal_uint8 *src_addr, kal_uint32 width, kal_uint32 height, kal_uint32 bpp)
{
   //ASSERT(0);
   return IPP_STATUS_ERROR;
}



IPP_STATUS_ENUM ippSetDstInfo(kal_uint32 handle, kal_uint8 *dst_addr, kal_uint32 buffer_size, kal_uint32 dst_bpp)
{
   //ASSERT(0);
   return IPP_STATUS_ERROR;
}



kal_uint32 ippQueryWorkingMemory(IPP_EFFECT_ENUM effect, kal_uint32 width, kal_uint32 height)
{
   //ASSERT(0);
   return 0;
}

IPP_STATUS_ENUM ippSetWorkingMemory(kal_uint32 handle, kal_uint8 *buffer_addr, kal_uint32 buffer_size)
{
   //ASSERT(0);
   return IPP_STATUS_ERROR;
}



IPP_STATUS_ENUM ippSetEffect(kal_uint32 handle, IPP_EFFECT_ENUM effect_index)
{
   //ASSERT(0);
   return IPP_STATUS_ERROR;
}



IPP_STATUS_ENUM ippQueryEffectOwner(IPP_EFFECT_ENUM effect_index, IPP_ENUM_EFFECT_SUPPORTER *effect_owner)
{
   //ASSERT(0);
   return IPP_STATUS_ERROR;
}



IPP_STATUS_ENUM ippAbortProcess(kal_uint32 handle)
{
   //ASSERT(0);
   return IPP_STATUS_ERROR;
}



IPP_STATUS_ENUM ippPauseProcess(kal_uint32 handle)
{
   //ASSERT(0);
   return IPP_STATUS_ERROR;
}



IPP_STATE_ENUM ippQueryState(kal_uint32 handle)
{
   //ASSERT(0);
   return IPP_STATE_IDLE;
}



IPP_STATUS_ENUM ippResumeProcess(kal_uint32 handle)
{
   //ASSERT(0);
   return IPP_STATUS_ERROR;
}



kal_int32 ippQueryProgress(kal_uint32 handle)
{
   //ASSERT(0);
   return 0;
}



IPP_STATUS_ENUM ippSetClippingInfo(kal_uint32 handle, kal_uint32 clip_x, kal_uint32 clip_y, kal_uint32 clip_width, kal_uint32 clip_height)
{
   //ASSERT(0);
   return IPP_STATUS_ERROR;
}



IPP_STATUS_ENUM ippSetProgressCallbckFunc(kal_uint32 handle, kal_uint32 (*callback)(kal_int32 percentage), kal_uint32 interval)
{
   //ASSERT(0);
   return IPP_STATUS_ERROR;
}



void ippStartProcess(kal_uint32 handle)
{
   //ASSERT(0);
   return ;
}


#endif /// __MTK_TARGET__
