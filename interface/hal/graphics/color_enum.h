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
 *   color_enum.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Enum for COLOR(picture quality tuning).
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __COLOR_ENUM_H__
#define __COLOR_ENUM_H__


typedef enum 
{
   COLOR_STATUS_OK = 0,
   COLOR_STATUS_UNAVAILABLE,
   COLOR_STATUS_INVALID_PARAMETER,
   COLOR_STATUS_INVALID_OPERATION,
   COLOR_STATUS_INVALID_HANDLE,
   COLOR_STATUS_UNSUPPORTED_EFFECT,
} COLOR_STATUS_ENUM;


typedef enum
{
   COLOR_STATE_FREE = 0,  /*!< engine is free to use */
   COLOR_STATE_IDLE,  /*!< engine is acquired by someone */
   COLOR_STATE_BUSY,   /*!< engine is running */
   COLOR_STATE_COMPLETE         /*!< engine is running completely */
} COLOR_STATE_ENUM;


typedef enum
{
   COLOR_DISABLE = 0,
   COLOR_ENABLE,
   MAX_COLOR_ENABLE
} COLOR_ENABLE_ENUM;


typedef enum
{
   COLOR_PATH_LCD = 0,
   COLOR_PATH_MDP,
   MAX_COLOR_PATH
} COLOR_PATH_ENUM;


typedef enum
{
   COLOR_EFFECT_SHARPNESS = 0,
   COLOR_EFFECT_CONTRAST,
   COLOR_EFFECT_SATURATION,
   MAX_COLOR_EFFECT
} COLOR_EFFECT_ENUM;


typedef enum
{
   COLOR_SCENARIO_DEFAULT = 0,
   COLOR_SCENARIO_IMAGE_PLAYBACK,
   COLOR_SCENARIO_VIDEO_PLAYBACK,
   COLOR_SCENARIO_VIDEO_ENCODE,
   COLOR_SCENARIO_CAMERA_PREVIEW,
   COLOR_SCENARIO_CAMERA_QUICKVIEW,
   MAX_COLOR_SCENARIO
} COLOR_SCENARIO_ENUM;


#endif  // __COLOR_ENUM_H__

