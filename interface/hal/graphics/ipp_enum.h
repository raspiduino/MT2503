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
 *   ipp_enum.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Enum for IPP(image post process).
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
#ifndef __IPP_ENUM_H__
#define __IPP_ENUM_H__


typedef enum
{
  IPP_COLOR_FORMAT_RGB565,
  IPP_COLOR_FORMAT_RGB888
} IPP_COLOR_FORMAT_ENUM;



/// State of IPP state machine
typedef enum
{
  IPP_STATE_IDLE = 0,  /*!< used for effect, supported by SW, to indicate the current state is idle */
  IPP_STATE_PROCESS,   /*!< used for effect, supported by SW, to indicate the current state is processing image */
  IPP_STATE_PAUSING,   /*!< used for effect, supported by SW, to indicate the current state is being paused. This is only for internal usage. */
  IPP_STATE_PAUSED,    /*!< used for effect, supported by SW, to indicate the current state has been paused */
  IPP_STATE_ABORTING,  /*!< used for effect, supported by SW, to indicate the current state is being aborted. This is only for internal usage. */
  IPP_STATE_ABORTED,   /*!< used for effect, supported by SW, to indicate the current state has been aborted */
  IPP_STATE_HW         /*!< used for effect, supported by HW */
} IPP_STATE_ENUM;


/// Supported effects of IPP
typedef enum
{
   IPP_PIXEL_EFFECT_GRAYSCALE = 0,   /*!< pixel effect, supported by HW */
   IPP_PIXEL_EFFECT_SEPIA,           /*!< pixel effect, supported by HW */
   IPP_PIXEL_EFFECT_SEPIAGREEN,      /*!< pixel effect, supported by HW */
   IPP_PIXEL_EFFECT_SEPIABLUE,       /*!< pixel effect, supported by HW */
   IPP_PIXEL_EFFECT_COLORINV,        /*!< pixel effect, supported by HW */
   IPP_PIXEL_EFFECT_GRAYINV,         /*!< pixel effect, supported by HW */

   IPP_BLOCK_EFFECT_WATERCOLOR,      /*!< block effect, supported by SW or HW*/
   IPP_BLOCK_EFFECT_LIGHTBLUR,       /*!< block effect, supported by SW or HW */
   IPP_BLOCK_EFFECT_BLUR,            /*!< block effect, supported by SW or HW */
   IPP_BLOCK_EFFECT_STRONGBLUR,      /*!< block effect, supported by SW or HW */
   IPP_BLOCK_EFFECT_UNSHARP,         /*!< block effect, supported by SW or HW */
   IPP_BLOCK_EFFECT_SHARPEN,         /*!< block effect, supported by SW or HW */
   IPP_BLOCK_EFFECT_MORESHARPEN,     /*!< block effect, supported by SW or HW */
   IPP_BLOCK_EFFECT_MEDIAN,          /*!< block effect, supported by SW or HW */
   IPP_BLOCK_EFFECT_DILATION,        /*!< block effect, supported by SW or HW */
   IPP_BLOCK_EFFECT_EROSION          /*!< block effect, supported by SW or HW */
} IPP_EFFECT_ENUM;



typedef enum
{
   IPP_EFFECT_NOT_SUPPORTED = 0, /*!< This effect is not supported*/
   IPP_EFFECT_SW_SUPPORTED,      /*!< This effect is supported by SW*/
   IPP_EFFECT_HW_SUPPORTED       /*!< This effect is supported by HW*/
} IPP_ENUM_EFFECT_SUPPORTER;



/// Status code of IPP
typedef enum
{
  IPP_STATUS_OK = 0,                               /*!< ok */
  IPP_STATUS_ERROR,                                /*!< error */
  IPP_STATUS_ERROR_INVALID_EFFECT,                 /*!< error, the effect index is invalid */
  IPP_STATUS_ERROR_INVALID_DST_SIZE,               /*!< error, the buffer size is invalid */
  IPP_STATUS_ERROR_RELEASE_HANDLE_AT_PROCESSING_OR_PAUSING,   /*!< error, try to release handle when processing image */  
  IPP_STATUS_ERROR_AT_PAUSE_CHANGE_SRC_INFO,       /*!< error, try to change src_info under pause state */
  IPP_STATUS_ERROR_AT_PAUSE_CHANGE_DST_INFO,       /*!< error, try to change dst_info under pause state */
  IPP_STATUS_ERROR_AT_PAUSE_CHANGE_CLIP_INFO,      /*!< error, try to change clip_info under pause state */
  IPP_STATUS_ERROR_AT_PAUSE_CHANGE_WORKING_BUFFER, /*!< error, try to change working buffer info under pause state */
  IPP_STATUS_ERROR_AT_PAUSE_CHANGE_EFFECT,         /*!< error, try to change effect index under pause state */
  IPP_STATUS_ERROR_AT_PAUSE_CHANGE_CALLBACK,       /*!< error, try to change callback function under pause state */
  IPP_STATUS_ERROR_HW_NOT_SUPPORT                  /*!< error, means HW doesn't support some feature*/
} IPP_STATUS_ENUM;


enum
{
    IPP_CAM_EFFECT_DEC_NORMAL = 0,
    IPP_CAM_EFFECT_DEC_GRAYSCALE,
    IPP_CAM_EFFECT_DEC_SEPIA,
    IPP_CAM_EFFECT_DEC_SEPIAGREEN,
    IPP_CAM_EFFECT_DEC_SEPIABLUE,
    IPP_CAM_EFFECT_DEC_COLORINV,
    IPP_CAM_EFFECT_DEC_GRAYINV,
    IPP_CAM_EFFECT_DEC_WATERCOLOR,
    IPP_CAM_EFFECT_DEC_LIGHTBLUR,
    IPP_CAM_EFFECT_DEC_BLUR,
    IPP_CAM_EFFECT_DEC_STRONGBLUR,
    IPP_CAM_EFFECT_DEC_UNSHARP,
    IPP_CAM_EFFECT_DEC_SHARPEN,
    IPP_CAM_EFFECT_DEC_MORESHARPEN,
    IPP_CAM_EFFECT_DEC_MEDIAN,
    IPP_CAM_EFFECT_DEC_DILATION,
    IPP_CAM_EFFECT_DEC_EROSION,
    IPP_CAM_NO_OF_EFFECT_DEC
};

#endif

