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
 *   rgb_resizer_api.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __RGB_RESIZER_API_H__
#define __RGB_RESIZER_API_H__

#include "kal_general_types.h"

#include "resizer_enum.h"

#include "gfx_cache_switch_behavior_enum.h"

typedef struct RGB_RESIZER_HANDLE_STRUCT_T RGB_RESIZER_HANDLE_STRUCT;

/**
 *  Get rgb resizer handle
 *  @return RESIZER_STATUS_ENUM : enumeration type of RGB Resizer status
 *  @remarks
 */
RESIZER_STATUS_ENUM rgbResizerGetHandle(RGB_RESIZER_HANDLE_STRUCT **resizerHandle, RESIZER_MODE_ENUM mode, RESIZER_QUALITY_ENUM resizerQuality);



/**
 *  Release rgb resizer handle
 *  @return RESIZER_STATUS_ENUM : enumeration type of RGB Resizer status
 *  @remarks
 */
RESIZER_STATUS_ENUM rgbResizerReleaseHandle(RGB_RESIZER_HANDLE_STRUCT *resizerHandle);



/**
 *  Setting the callback function for the RGB Resizer
 *  @return G2D_STATUS_ENUM : enumeration type of RGB Resizer status
 *  @remarks This function sets the callback function user defined.
 *           Only if the callback function is set, the interrupt of
 *           hardware RGB Resizer will be enable, else the interrupt will be
 *           disable
 *
 */
RESIZER_STATUS_ENUM rgbResizerSetCallbackFunction(RGB_RESIZER_HANDLE_STRUCT *resizerHandle, RESIZER_CALLBACK_FUNC_PTR rgbResizerCallback);



/**
 *  Setting the source buffer information
 *  @param colorFormat  : enumeration type of source color format
 *  @param bufferAddr   : address pointer of source buffer
 *  @param bufferSize   : size of source buffer
 *  @param bufferWidth  : the source buffer width
 *  @param bufferHeight : the source buffer height
 *  @return RESIZER_STATUS_ENUM : enumeration type of RGB Resize status
 *  @remarks
 */
RESIZER_STATUS_ENUM rgbResizerSetSrcBufferInfo(RGB_RESIZER_HANDLE_STRUCT *resizerHandle,
                                               RESIZER_COLOR_FORMAT_ENUM colorFormat, void *bufferAddr, kal_uint32 bufferSize,
                                               kal_uint32 bufferWidth, kal_uint32 bufferHeight);



/**
 *  Setting the destination buffer information
 *  @param colorFormat  : enumeration type of destination color format
 *  @param bufferAddr   : address pointer of destination buffer
 *  @param bufferSize   : size of destination buffer
 *  @param bufferWidth  : the destination buffer width
 *  @param bufferHeight : the destination buffer height
 *  @return RESIZER_STATUS_ENUM : enumeration type of RGB Resize status
 *  @remarks
 */
RESIZER_STATUS_ENUM rgbResizerSetDstBufferInfo(RGB_RESIZER_HANDLE_STRUCT *resizerHandle,
                                               RESIZER_COLOR_FORMAT_ENUM colorFormat, void *bufferAddr, kal_uint32 bufferSize,
                                               kal_uint32 bufferWidth, kal_uint32 bufferHeight);



/**
 *  Setting the Destination buffer cache switch behavior
 */
RESIZER_STATUS_ENUM rgbResizerSetDstBufferSwitchBehavior(RGB_RESIZER_HANDLE_STRUCT *handle, GFX_CACHE_SWITCH_BEHAVIOR_ENUM behavior);


/**
 *  Setting the Source buffer cache switch behavior
 */
RESIZER_STATUS_ENUM rgbResizerSetSrcBufferSwitchBehavior(RGB_RESIZER_HANDLE_STRUCT *handle, GFX_CACHE_SWITCH_BEHAVIOR_ENUM behavior);


/**
 *  Setting the source window information
 *  @param x : x-coordinate of top-left point in source window
 *  @param y : y-coordinate of top-left point in source window
 *  @param w : source window width
 *  @param h : source window height
 *  @return RESIZER_STATUS_ENUM : enumeration type of RGB Resize status
 *  @remarks
 */
RESIZER_STATUS_ENUM rgbResizerSetSrcWindow(RGB_RESIZER_HANDLE_STRUCT *resizerHandle, kal_int32 x, kal_int32 y, kal_uint32 width, kal_uint32 height);



/**
 *  Setting the destination window information
 *  @param x : x-coordinate of top-left point in destination  window
 *  @param y : y-coordinate of top-left point in destination  window
 *  @param w :  window width
 *  @param h :  window height
 *  @return RESIZER_STATUS_ENUM : enumeration type of RGB Resize status
 *  @remarks
 */
RESIZER_STATUS_ENUM rgbResizerSetDstWindow(RGB_RESIZER_HANDLE_STRUCT *resizerHandle, kal_int32 x, kal_int32 y, kal_uint32 width, kal_uint32 height);



/**
 *  Setting the clipping window for the destination buffer, all data outside the clipping window will be remained \n
 *  @param dstClipEnable : enable/disable clipping window flag
 *  @param (x,y)         : base vertex coordinate of clipping window
 *  @param w             : width of the clipping window
 *  @param h             : height of the clipping window
 *  @return RESIZER_STATUS_ENUM : enumeration type of RGB Resize status
 *  @remarks This function sets the clipping window for destination buffer
 *           If clip_enable is TRUE,all data outside the clipping window \n
 *           will be discarded
 */
RESIZER_STATUS_ENUM rgbResizerSetDstClipWindow(RGB_RESIZER_HANDLE_STRUCT *resizerHandle, kal_bool dstClipWindowEnable, kal_int32 x, kal_int32 y, kal_uint32 width, kal_uint32 height);



/**
 *  Setting the source key flag and source key value
 *  @param srcKeyEnable : enable/disable source color key
 *  @param srcKeyValue  : source key color
 *  @return RESIZER_STATUS_ENUM : enumeration type of RGB Resize status
 *  @remarks
 *       if srcKeyEnable, the setted color will be transparent
 */
RESIZER_STATUS_ENUM rgbResizerSetSrcKey(RGB_RESIZER_HANDLE_STRUCT *resizerHandle, kal_bool srcKeyEnable, kal_uint32 srcKeyValue);




/**
 *  Setting the Color of replacement features
 *  @param colorReplaceEnable : specified the color replacement is enable or disable
 *  @param colorToAvoid       : color to be replaced
 *  @param colorToReplace     : color component to substitute
 *  @return RESIZER_STATUS_ENUM : enumeration type of RGB Resize status
 *  @remarks This function set the color components of replacement and
 *           substitute
 */
RESIZER_STATUS_ENUM rgbResizerSetColorReplacement(RGB_RESIZER_HANDLE_STRUCT *resizerHandle, kal_bool colorReplaceEnable,
                                                  kal_uint32 oldColor, kal_uint32 newColor);



/**
 *  Enable dithering ot not
 *  @param ditherEnablee : enable/disable dithering
 *  @return RESIZER_STATUS_ENUM : enumeration type of RGB Resize status
 *  @remarks
 */
RESIZER_STATUS_ENUM rgbResizerSetDithering(RGB_RESIZER_HANDLE_STRUCT *resizerHandle, kal_bool ditherEnable);



/**
 *  Abort the RGB Resizing process.
 *  @return RESIZER_STATUS_ENUM : enumeration type of RGB Resize status
 *  @remarks
 */
RESIZER_STATUS_ENUM rgbResizerCheckAbortFunction(RGB_RESIZER_HANDLE_STRUCT *resizerHandle, kal_int32 (*check_abort_func)(void));



/**
 *  Query the necessary working memory for the encoder.
 *  @param intMemBest  : pointer to unsigned int to obtain the max internal memory size
 *  @param intMemMin   : pointer to unsigned int to obtain the min internal memory size
 *  @param extMemBest  : pointer to unsigned int to obtain the max external memory size
 *  @param extMemMin   : pointer to unsigned int to obtain the min external memory size
 *  @return RESIZER_STATUS_ENUM : enumeration type of RGB Resize status
 *  @remarks
 */
RESIZER_STATUS_ENUM rgbResizerQueryWorkingMemory(RGB_RESIZER_HANDLE_STRUCT *resizerHandle, kal_uint32 *intMemBest, kal_uint32 *intMemMin,
                                                 kal_uint32 *extMemBest, kal_uint32 *extMemMin);




/**
 *  Set the necessary : working memory for the RGB Resizer.
 *  @param intMemAddr : pointer to starting address of the internal working memory
 *  @param intMemSize : size of the internal working memory
 *  @param extMemAddr : pointer to starting address of the external working memory
 *  @param extMemSize : size of the external working memory
 *  @return RESIZER_STATUS_ENUM : enumeration type of RGB Resize status
 *  @remarks
 */
RESIZER_STATUS_ENUM rgbResizerSetWorkingMemory(RGB_RESIZER_HANDLE_STRUCT *resizerHandle, kal_uint32 *intMemAddr, kal_uint32 intMemSize,
                                               kal_uint32 *extMemAddr, kal_uint32 extMemSize);



/**
 *  Start the RGB Resizing
 *  @return RESIZER_STATUS_ENUM : enumeration type of RGB Resize status
 *  @remarks This function start performing the RGB Resizing operation based \n
 *           on previous API setting
 */
RESIZER_STATUS_ENUM rgbResizerStart(RGB_RESIZER_HANDLE_STRUCT **resizerHandle);




/**
 *  Getting the status of RGB Resizer
 *  @return : if the return is equal to RESIZER_STATUS_BUSY, it means that the G2D engine is busy.\n
              if the return is equal to RESIZER_STATUS_COMPLETE, it means that the G2D engine is busy.\n
 *            else the GRGB Resizer operation has error
 *  @remarks  This function provide the user to poll the status of RGB Resizer, if the callback function
 *            is not setted, user should use this function to check if the RGB Resizer is busy or not
 */
RESIZER_STATUS_ENUM rgbResizerGetStatus(RGB_RESIZER_HANDLE_STRUCT *resizerHandle);

#endif
