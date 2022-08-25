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
 *   ipp_interface.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Prototypes of IPP(image post process) APIs.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __IPP_INTERFACE_H__
#define __IPP_INTERFACE_H__

#undef IPP_STANDALONE

#if defined(IPP_STANDALONE)
   #include "kal_general_types.h"
   #include "stdlib.h"
   #include "stdio.h"
   #include "string.h"
   #include "math.h"
   #include "assert.h"
   #include "drv_comm.h"

   #if !defined(ASSERT)
   #define ASSERT assert
   #endif
#else
   // for MoDis and real target
   #include "kal_general_types.h"
   #include "drv_comm.h"
#endif

#include "ipp_enum.h"


/** DESCRIPTION :
 *     Query the supported effect list. \n
 *  @param[in] effect_supported_list The list indicates the effect is supported by SW or HW or NotSupported.
 *  @param[in] list_size This parameter indicates the size of supported_effect_list.
 *  @return Return the number of supported effects.\n
 *  @mark When you first calls this API, pass effect_supported_list = NULL and this API will output 'the size of effect_supported_list' to list_size.
 *        Then you base on list_size to allocate memory for effect_supported_list.
 *        Finally calling this API again with effect_supported_list!= NULL, and this API will return the supported effect list.\n
 */
kal_uint32 ippQuerySupportedEffects(IPP_ENUM_EFFECT_SUPPORTER *effect_supported_list, kal_uint32 *list_size);



/** DESCRIPTION :
 *     Get the ipp handle for image post process. \n
 *  @return Return a non-zero value if success, otherwise fail.\n
 *  @remark The returned handle must be released by ippReleaseHandle.\n
 */
kal_int32 ippGetHandle(void);



/** DESCRIPTION :
 *     Release the ipp handle.\n
 *  @param[in] handle The returned value of ippGetHandle\n
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return error code IPP_STATUS_ERROR_RELEASE_HANDLE_AT_PROCESSING_OR_PAUSING if the process is doing. \n
 *  @remark If the return value is IPP_STATUS_ERROR_RELEASE_HANDLE_AT_PROCESSING_OR_PAUSING, it means the previous request is not completed, thus you can't call this API.\n
 *          If you have ever called ippPauseProcess, then you should call ippAbortProcess or ippResumeProcess first to complete the previous request.\n
 *          Then you can call ippQueryState to check whether the processing is done, meaning the state is at IDLE or Aborted.\n
 *          Until the compeltion or abortion, you can call this API.\n
 */
IPP_STATUS_ENUM ippReleaseHandle(kal_uint32 handle);



/** DESCRIPTION :
 *     Set information of the source image. \n
 *  @param[in] handle The returned value of ippGetHandle
 *  @param[in] src_addr Address of the source image.
 *  @param[in] width Width of the source image.
 *  @param[in] height Height of the source image.
 *  @param[in] color_format Color format of the source image.
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_SRC_INFO when changing information under PAUSE atate.\n
 *  @remark If the return value is IPP_STATUS_ERROR_AT_PAUSE_CHANGE_SRC_INFO, it means you should call ippAbortProcess or ippResumeProcess first to complete the previous request.\n
 *          Then you can call ippQueryState to check whether the processing is done, meaning the state is at IDLE or Aborted. \n
 */
IPP_STATUS_ENUM ippSetSrcInfo(kal_uint32 handle, kal_uint8 *src_addr, kal_uint32 width, kal_uint32 height, IPP_COLOR_FORMAT_ENUM color_format);



/** DESCRIPTION :
 *     Set information of the destination image. \n
 *  @param[in] handle The returned value of ippGetHandle
 *  @param[in] dst_addr Address to store the processed image.
 *  @param[in] dst_buffer_size The buffer size of destination image.
 *  @param[in] color_format Color format of the destination image.
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_INVALID_DST_SIZE if the buffer size is smaller than (width * height * bpp)\n
 *          Return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_DST_INFO when changing information under pause atate.\n
 *  @remark If the return value is IPP_STATUS_ERROR_AT_PAUSE_CHANGE_DST_INFO, it means you should call ippAbortProcess or ippResumeProcess first to complete the previous request.\n
 *          Then you can call ippQueryState to check whether the processing is done, meaning the state is at IDLE or Aborted. \n
 */
IPP_STATUS_ENUM ippSetDstInfo(kal_uint32 handle, kal_uint8 *dst_addr, kal_uint32 buffer_size, IPP_COLOR_FORMAT_ENUM color_format);



/** DESCRIPTION :
 *     Query the size of working buffer\n
 *  @param[in] effect The block effect that will be applied.
 *  @param[in] width The width of the image.
 *  @param[in] height The height of the image.
 *  @param[in] src_bpp The bytePerPixel of the image 
 *  @return The minimum size of working bufer, used to process image.
 *  @remark The size of the working buffer depends on the effect. Now only the watercolor will need a working buffer.
 *          Besides, the buffer size should be at least equal to the size of source image or the clipped image. \n
 */
kal_uint32 ippQueryWorkingMemory(IPP_EFFECT_ENUM effect, kal_uint32 width, kal_uint32 height, kal_uint32 src_bpp);




/** DESCRIPTION :
 *     Set the working buffer information. \n
 *  @param[in] handle The returned value of ippGetHandle
 *  @param[in] buffer_addr Address of the working buffer.
 *  @param[in] buffer_size Size of the working buffer.
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_WORKING_BUFFER when changing information under pause atate.\n
 *  @remark If the return value is IPP_STATUS_ERROR_AT_PAUSE_CHANGE_WORKING_BUFFER,it means you should call ippAbortProcess or ippResumeProcess first to complete the previous request.\n
 *          Then you can call ippQueryState to check whether the processing is done, meaning the state is at IDLE or Aborted.\n
 *          Size of the working buffer must be at least equal to the size of source image or the clipped image.
 *          Be careful: it is better to call this function after you have called ippSetSrcInfo. \n
 */
IPP_STATUS_ENUM ippSetWorkingMemory(kal_uint32 handle, kal_uint8 *buffer_addr, kal_uint32 buffer_size);



/** DESCRIPTION :
 *     Set the effect index. \n
 *  @param[in] handle The returned value of ippGetHandle
 *  @param[in] effect This parameter indicates which effect will be applied.
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_EFFECT if change effect when the processing is paused.\n
 *          Return IPP_STATUS_ERROR_INVALID_EFFECT if the effect is invalid.\n
 *  @remark If the return value is IPP_STATUS_ERROR_AT_PAUSE_CHANGE_EFFECT, it means you should call ippAbortProcess or ippResumeProcess first to complete the previous request.
 *          Then you can call ippQueryState to check whether the processing is done, meaning the state is at IDLE or Aborted.
 */
IPP_STATUS_ENUM ippSetEffect(kal_uint32 handle, IPP_EFFECT_ENUM effect_index);



/** DESCRIPTION :
 *     Query whether HW or SW supports the effect index. \n
 *  @param[in] effect_index Effect index
 *  @param[in] effect_owner This parameter indicates the effect is supported by HW/SW/NotSupported.
 *  @return Return IPP_STATUS_OK if success. \n
 */
IPP_STATUS_ENUM ippQueryEffectSupporter(IPP_EFFECT_ENUM effect_index, IPP_ENUM_EFFECT_SUPPORTER *effect_owner);



/** DESCRIPTION :
 *     Call this function to abort current processing of image effect. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_HW_NOT_SUPPORT if the effect is supported by HW.\n
 *  @remark Hw doesn't support abort/pause/resume functionality.
 */
IPP_STATUS_ENUM ippAbortProcess(kal_uint32 handle);



/** DESCRIPTION :
 *     Call this function to pause the processing of image effect\n
 *  @param[in] handle The returned value of swippGetHandle
 *  @return Return IPP_STATUS_OK if success.\n
 *          Return IPP_STATUS_ERROR_HW_NOT_SUPPORT if the effect is supported by HW.\n
 *  @remark Hw doesn't support abort/pause/resume functionality.
 */
IPP_STATUS_ENUM ippPauseProcess(kal_uint32 handle);



/** DESCRIPTION :
 *     Call this function to query the current state. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @return Return the current state of IPP_STATE_ENUM if the effect is supported by SW.\n
 *          Return IPP_STATE_HW_STATE if the effect is supported by HW\n
 *  @remark Hw doesn't support abort/pause/resume functionality, so it has no state machine.
 */
IPP_STATE_ENUM ippQueryState(kal_uint32 handle);




/** DESCRIPTION :
 *     Call this function to resume the processing of image effect\n
 *  @param[in] handle The returned value of swippGetHandle
 *  @return Return IPP_STATUS_OK if set effect successfully.\n
  *          Return IPP_STATUS_ERROR_HW_NOT_SUPPORT if the current effect is supported by HW.\n
 *  @remark Hw doesn't support abort/pause/resume functionality.
 */
IPP_STATUS_ENUM ippResumeProcess(kal_uint32 handle);



/** DESCRIPTION :
 *     Call this function to start processing image. \n
 *  @param[in] handle The returned value of ippGetHandle
 *  @return None
 */
void ippStartProcess(kal_uint32 handle);



/** DESCRIPTION :
 *     Call this function to query the processing progress \n
 *  @param[in] handle The returned value of ippGetHandle\n
 *  @return Return completion percentage of processing supported by SW.\n
 *          Return -1 if the current effect is supported by HW.\n
 */
kal_int32 ippQueryProgress(kal_uint32 handle);



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
IPP_STATUS_ENUM ippSetClippingInfo(kal_uint32 handle, kal_uint32 clip_x, kal_uint32 clip_y, kal_uint32 clip_width, kal_uint32 clip_height);



/** DESCRIPTION :
 *     Call this function to reset IPP. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @return None
 *  @remark This function resets the all informations to zero. But for the handle, you still need to call ippReleaseHandle to release it.
 */
void ippResetPorcess(kal_uint32 handle);



/** DESCRIPTION :
 *     Call this function to set the callback function, used to report processing progress periodically\n
 *  @param[in] handle The returned value of swippGetHandle
 *  @param[in] callback The callback function supported by the AP
 *  @param[in] interval The periodic interval. The uint is mini-second.
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_CALLBACK when changing progress callback function under pause atate.\n
 *          Return IPP_STATUS_ERROR_HW_NOT_SUPPORT when this effect is supported by HW. However, HW doesn't provide callback to query progress.\n
 *  @remark
 */
IPP_STATUS_ENUM ippSetProgressCallbckFunc(kal_uint32 handle, kal_uint32 (*callback)(kal_int32 percentage), kal_uint32 interval);


#endif



/** @}*/
/** @}*/

/*! \page IPP API Usage Example
The following is an example of calling IPP APIs.\n\n
\code

typedef struct clipping_info_t
{
   kal_uint32 pivot_x;
   kal_uint32 pivot_y;
   kal_uint32 clip_width;
   kal_uint32 clip_height;

}clipping_info_st;

kal_uint32 ippHandle;

kal_uint32 color_format_to_bpp(IPP_COLOR_FORMAT_ENUM src_format)
{
   kal_uint32 src_bpp;

   switch (src_format)
   {
   case IPP_COLOR_FORMAT_RGB565:
      src_bpp = 2;
      break;
   case IPP_COLOR_FORMAT_RGB888:
      src_bpp = 3;
      break;
   default:
      ASSERT(0);
      break;
   }
   return src_bpp;
}



kal_uint32 call_ipp(
    kal_uint8* src_addr,
    kal_uint8* dst_addr,
    kal_uint32 dst_buffer_size,
    kal_uint32 width,
    kal_uint32 height,
    kal_uint32 src_format,
    kal_uint32 dst_format,
    kal_uint32 effect,
    clipping_info_st *clipping_info)
{
 kal_uint32 list_size, supported_effect_count;
  IPP_ENUM_EFFECT_SUPPORTER *effect_supported_list = NULL;
  kal_uint32 buf_size;
  kal_uint8 *buffer = NULL;
  kal_uint32 src_bpp, dst_bpp;

  ippQuerySupportedEffects(effect_supported_list, &list_size);
  effect_supported_list = malloc(list_size); 
  supported_effect_count = ippQuerySupportedEffects(effect_supported_list, &list_size);
  if (supported_effect_count == 0)
  {
     // No effect is supported, return
     // under this case, you should not call any other IPP_APIs except ippQuerySupportedEffects,
     // otherwise error will ocurr.
     return 0;
  }
  
   ippHandle = ippGetHandle();

   if (!ippHandle)
   {
      return 0;
   }

   src_bpp = color_format_to_bpp(src_format);
   dst_bpp = color_format_to_bpp(dst_format);

   ippSetSrcInfo(ippHandle, src_addr, width, height, src_format);

   if (set_clipping_flag == 1)
   {
      IMG_WIDTH = 210;
      IMG_HEIGHT = 370;
      ippSetClippingInfo(ippHandle, 30, 30, IMG_WIDTH, IMG_HEIGHT);
   }

   ippSetDstInfo(ippHandle, dst_addr, dst_buffer_size, dst_format);

   buf_size = ippQueryWorkingMemory(effect, width, height, src_bpp);

   if (buf_size)
   {
      buffer = malloc(buf_size);

      if (buffer == NULL)
      {
         ASSERT(0);
      }
   }

   ippSetWorkingMemory(ippHandle, buffer, buf_size, src_bpp);

   ippSetProgressCallbckFunc(ippHandle, progress_callback, 10);

   ippSetEffect(ippHandle, effect);

   ippStartProcess(ippHandle);

   return 1;
}

\endcode

Note:\n
1) ippSetClippingInfo precedes ippSetDstInfo because we will check DstBufferSize in ippSetDstInfo. (So we have had information about width and height before doing such checking)\n
\n
2) ippQueryWorkingMemory precedes ippSetWorkingMemory because we will check WorkingBufferSize in ippSetWorkingMemory.\n
\n
3) ippStartProcess is the final step. Before calling this API, you must make sure all the related information has past to IPP\n
\n
*/

