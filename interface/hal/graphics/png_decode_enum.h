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
 *    png_decode_enum.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   PNG decoder enumeration type
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __PNG_COMMON_ENUM_H__
#define __PNG_COMMON_ENUM_H__


typedef enum
{
   PNG_DECODER_TYPE_HW = 0,
   PNG_DECODER_TYPE_SW,
   PNG_DECODER_TYPE_DEFAULT      ///< by using the default, HAL will responsible for choosing decoder type automatically

} PNG_DECODER_TYPE_ENUM;


typedef enum
{
   PNG_DECODER_STATE_FREE = 0,   /// the module is free to use
   PNG_DECODER_STATE_IDLE,       /// the module is acquired by some body
   PNG_DECODER_STATE_RESET,
   PNG_DECODER_STATE_READY,
   PNG_DECODER_STATE_DECODING,   /// the module is working
   PNG_DECODER_STATE_PAUSE,      /// the module is paused
   PNG_DECODER_STATE_ERROR
} PNG_DECODER_STATE_ENUM;


/**
 * @brief define the decode status and error status of PNG decoder
 */
typedef enum
{
   PNG_STATUS_OK = 0,                           ///< Function call return normally or IDAT of source image is decode completely
   PNG_STATUS_DECODE_INCOMPLETE,                ///< soure image is parsed or decoded partially
   PNG_STATUS_IN_DECODING,                      ///< png decoder is decoding
   PNG_STATUS_DECODE_COMPLETE,                  ///< all image data are decode completely
   PNG_STATUS_DECODE_TIMEOUT,                   ///< png decoder timeout

   PNG_STATUS_DECODER_UNAVAILABLE,
   PNG_STATUS_INVALID_HANDLE,
   PNG_STATUS_INVALIDE_DECODER_TYPE,
   PNG_STATUS_INVALID_SOURCE_FILE,
   PNG_STATUS_INVALID_OPERATION,
   PNG_STATUS_UNSUPPORTED_FEATURE,

   PNG_STATUS_ERROR_DECODE_FAILED,
   PNG_STATUS_ERROR_INVALID_BUFFER,
   PNG_STATUS_ERROR_GENERAL_ERROR,
   PNG_STATUS_ERROR_UNSUPPORTED_FILE_DIMENSION,
   PNG_STATUS_ERROR_UNSUPPORTED_FORMAT,
   PNG_STATUS_ERROR_NULL_OUTPUT_WINDOW,
   PNG_STATUS_ERROR_RSB_INIT_FAILED,
   PNG_STATUS_ERROR_BLD_BUFF_INVALID,
   PNG_STATUS_ENUM_END_CODE
} PNG_STATUS_ENUM;


/**
 * @brief define the color format
 * @remarks For ARGB4444 and PARGB8888 color format, only takes effect on SW PNG decoder
 */
typedef enum
{
   PNG_FORMAT_RGB565,
   PNG_FORMAT_RGB888,
   PNG_FORMAT_ARGB8888,
   PNG_FORMAT_ARGB4444,           ///<only SW PNG decoder support ARGB4444 color format
   PNG_FORMAT_PARGB8888,          ///<only SW PNG decoder support PARGB8888 color format
   PNG_FORMAT_ARGB6666,           ///<only SW PNG decoder support ARGB6666 color format
   PNG_FORMAT_PARGB6666           ///<only SW PNG decoder support ARGB6666 color format

} PNG_DECODE_COLOR_FORMAT_ENUM;



/**
 * @brief define the bleding mode
 */
typedef enum
{
   PNG_BLEND_NONE = 0,
   PNG_BLEND_FILE_ALPHA,           ///<  PNG built-in alpha \n
                                   ///<  dstColor = pngAlpha x pngColor + (1 - pngAlpha) x bldColor \n
                                   ///<  pngAlpha may comes from several sources:\n
                                   ///<         i.   the alpha component of the pixel if the color type is ARGB \n
                                   ///<         ii.  the alpha component of the pixel if the color type is grayscale with alpha \n
                                   ///<         iii. the single alpha defined in the transparent chunk if the color type is not palette type \n
                                   ///<         iv.  the per-palette-entry alpha defined in the transparent chunk if the color type is palette type\n
   PNG_BLEND_BUFFER,                      ///<  blending buffer (always be per-pixel) \n
                                   ///<  dstColor = dstAlpha x pngColor + (1 - dstAlpha) x bldColor \n
                                   ///<  This mode works only when the destination buffer is ARGB mode.\n\n
   PNG_BLEND_USER_ASSIGNED,               ///<  user-specified single alpha value (always be per-alpha) \n
                                          ///<  dstColor = userAlpha x pngColor + (1 - userAlpha) x bldColor \n\n

   PNG_BLEND_BG_COLOR              ///< png file alpha blends with a single background color
} PNG_BLEND_MODE_ENUM;


#endif  /* __PNG_ENUM_H__ */
