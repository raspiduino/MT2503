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
 *   swipp_interface.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Prototypes of swipp APIs.
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
#ifndef __SWIPP_INTERFACE_H__
#define __SWIPP_INTERFACE_H__

#undef SWIPP_STANDALONE

#if defined(SWIPP_STANDALONE)
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

   /// wrapper for kal_mutex
   typedef unsigned int kal_mutexid;
   #define kal_create_mutex(_par1)  (1)
   #define kal_take_mutex
   #define kal_give_mutex

#else
   #include "drv_comm.h"
#endif

#include "swipp_enum.h"

// RHR suggestion
#include "kal_general_types.h"

#if (defined DRV_BLOCK_EFFECT_SW_SUPPORT)


/** DESCRIPTION :
 *     Set the swipp handle for image post process. \n
 *  @return return a non-zero value if success, otherwise fail
 *  @remark The returned handle must be released by swippReleaseHandle
 */
kal_int32 swippSetHandle(kal_int32 handle);



/** DESCRIPTION :
 *     Release the swipp handle.\n
 *  @param[in] handle The returned value of swippGetHandle
 *  @return Return SWIPP_STATUS_OK if success. \n
 *          Return error code SWIPP_STATUS_ERROR_RELEASE_HANDLE_AT_PROCESSING if the process is doing. \n
 */
SWIPP_STATUS_ENUM swippReleaseHandle(kal_uint32 handle);



/** DESCRIPTION :
 *     Set information of the source image. \n
 *  @param[in] handle The returned value of ippGetHandle
 *  @param[in] src_addr Address of the source image.
 *  @param[in] width Width of the source image.
 *  @param[in] height Height of the source image.
 *  @param[in] src_bpp BytesPerPixel of the source image.
 *  @return Return SWIPP_STATUS_OK if success. \n
 *          Return SWIPP_STATUS_ERROR_AT_PAUSE_CHANGE_SRC_INFO when changing information under pause atate.
 */
SWIPP_STATUS_ENUM swippSetSrcInfo(kal_uint32 handle, kal_uint8 *src_addr, kal_uint32 width, kal_uint32 height, kal_uint32 src_bpp);



/** DESCRIPTION :
 *     Set information of the destination image. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @param[in] dst_addr Address to store the processed image.
 *  @param[in] buffer_size Destination buffer size .
 *  @param[in] dst_bpp BytesPerPixel of the destination image.
 *  @return Return SWIPP_STATUS_OK if success. \n
 *          Return SWIPP_STATUS_ERROR_INVALID_DST_SIZE if the destination buffer size is wrong.
 *          Return SWIPP_STATUS_ERROR_AT_PAUSE_CHANGE_DST_INFO when changing information under pause atate.
 */
SWIPP_STATUS_ENUM swippSetDstInfo(kal_uint32 handle, kal_uint8 *dst_addr, kal_uint32 buffer_size, kal_uint32 dst_bpp);



/** DESCRIPTION :
 *     Query the size of working buffer\n
 *  @param[in] effect The block effect that will be applied
 *  @param[in] width The width of the image.
 *  @param[in] height The height of the image
 *  @return None
 *  @remark The size of the working buffer is depended on the block effect. Now only the watercolor will need working buffer
 *  @remark Besides the buffer size must at least be equal to the source image or the clipped image.
 *  @remark Call this function after you have called swippSetSrcInfo. \n
 */
kal_uint32 swippQueryWorkingMemory(SWIPP_EFFECT_ENUM effect, kal_uint32 width, kal_uint32 height, kal_uint32 src_bpp)
;



/** DESCRIPTION :
 *     Set the working buffer information. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @param[in] buffer_addr Address of the working buffer.
 *  @param[in] buffer_size Size of the working buffer.
 *  @return Return SWIPP_STATUS_OK if success. \n
 *          Return SWIPP_STATUS_ERROR_AT_PAUSE_CHANGE_WORKING_BUFFER when changing information under pause atate.
 *  @remark The size of the working buffer must at least be equal to the source image or the clipped image.
 *  @remark Call this function after you have called swippSetSrcInfo. \n
 */
SWIPP_STATUS_ENUM swippSetWorkingMemory(kal_uint32 handle, kal_uint8 *buffer_addr, kal_uint32 buffer_size);



/** DESCRIPTION :
 *     Set the block effect index to swipp\n
 *  @param[in] handle The returned value of swippGetHandle
 *  @param[in] effect  This parameter indicates which block effect wil be applied.
 *  @return Return SWIPP_STATUS_OK if success. \n
 *          Return SWIPP_STATUS_ERROR_INVALID_EFFECT if the effect is invalid.
 */
SWIPP_STATUS_ENUM swippSetBlockEffect(kal_uint32 handle, SWIPP_EFFECT_ENUM effect_index);



/** DESCRIPTION :
 *     call this function to abort current processing of image effect. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @return Return SWIPP_STATUS_OK_WAIT_ABORT if success.
 *          Return SWIPP_STATUS_OK_HAS_ABORTED if the effect has been aborted.
 */
SWIPP_STATUS_ENUM swippAbortProcess(kal_uint32 handle);



/** DESCRIPTION :
 *     call this function to pause the processing of image effect\n
 *  @param[in] handle The returned value of swippGetHandle
 *  @return Return SWIPP_STATUS_OK_WAIT_PAUSE if success.
 *          Return SWIPP_STATUS_OK_HAS_PAUSED if the effect has been paused.
 */
SWIPP_STATUS_ENUM swippPauseProcess(kal_uint32 handle);



/** DESCRIPTION :
 *     call this function to query if the process is terminated. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @return Return the current state value of IPP_STATE_ENUM
 *  @remark Hw doesn't support abort/pause/resume functionality.
 */
SWIPP_STATE_ENUM swippQueryState(kal_uint32 handle);



/** DESCRIPTION :
 *     call this function to resume the processing of image effect\n
 *  @param[in] handle The returned value of swippGetHandle
 *  @remark Hw doesn't support abort/pause/resume functionality.
 */
void swippResumeProcess(kal_uint32 handle);



/** DESCRIPTION :
 *     call this function to start processing of image effect\n
 *  @param[in] handle The returned value of swippGetHandle
 *  @return None
 */
void swippStartProcess(kal_uint32 handle);



/** DESCRIPTION :
 *     call this function to query the processing progress \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @return None
 */
kal_int32 swippQueryProgress(kal_uint32 handle);



/** DESCRIPTION :
 *     call this function to set clipping information\n
 *  @param[in] handle The returned value of swippGetHandle
 *  @param[in] clip_x The x coordinates of starting point for the clipping window
 *  @param[in] clip_y The y coordinates of starting point for the clipping window
 *  @param[in] clip_width Width of the clipping window
 *  @param[in] clip_height Height of the clipping window
 *  @return Return SWIPP_STATUS_OK if success. \n
 *          Return SWIPP_STATUS_ERROR_AT_PAUSE_CHANGE_CLIP_INFO when changing clipping information under pause atate.
 */
SWIPP_STATUS_ENUM swippSetClippingInfo(kal_uint32 handle, kal_uint32 clip_x, kal_uint32 clip_y, kal_uint32 clip_width, kal_uint32 clip_height);


/** DESCRIPTION :
 *     call this function to set the callback function, used to report processing progress periodically\n
 *  @param[in] handle The returned value of swippGetHandle
 *  @param[in] callback The callback function supported by the AP
 *  @param[in] interval The interval that we call this function call, in percentage
 *  @return Return SWIPP_STATUS_OK if success. \n
 *          Return SWIPP_STATUS_ERROR_AT_PAUSE_CHANGE_CALLBACK when changing progress callback funciton under pause atate.
 */
SWIPP_STATUS_ENUM swippSetProgressCallbckFunc(kal_uint32 handle, kal_uint32 (*callback)(kal_int32 percentage), kal_uint32 interval);



/** DESCRIPTION :
 *     call this function to To BE DEFINED\n
 *  @param[in] handle The returned value of swippGetHandle
 *  @return Return SWIPP_STATUS_OK if success. \n
 */
SWIPP_STATUS_ENUM swippResetPorcess(kal_uint32 handle);

#endif //(defined(DRV_PIXEL_EFFECT_SUPPORT) || defined(DRV_BLOCK_EFFECT_SUPPORT))

#endif //__SWIPP_INTERFACE_H__
