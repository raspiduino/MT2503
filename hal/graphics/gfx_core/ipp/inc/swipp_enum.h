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
 *   swipp_enum.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Enum for swipp.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __SWIPP_ENUM_H__
#define __SWIPP_ENUM_H__


typedef enum
{
  SWIPP_COLOR_FORMAT_RGB565,
  SWIPP_COLOR_FORMAT_RGB888
} SWIPP_COLOR_FORMAT_ENUM;



/* SWIPP_STATE_IDLE is the initial state.
 * Call swippStartProcess will go to SWIPP_STATE_PROCESS.
 * Call swippPauseProcess will go to SWIPP_STATE_PAUSE. When processing check the state is SWIPP_STATE_PAUSE, it will keep some required informations when resume, and then go to SWIPP_STATE_IDLE.
 * Call swippResumeProcess will go to SWIPP_STATE_PROCESS.
 * Call swippAbortProcess will go to SWIPP_STATE_IDLE.
**/
typedef enum
{
  SWIPP_STATE_IDLE = 0,
  SWIPP_STATE_PROCESS,
  SWIPP_STATE_PAUSING,
  SWIPP_STATE_PAUSED,
  SWIPP_STATE_ABORTING,
  SWIPP_STATE_ABORTED
} SWIPP_STATE_ENUM;



typedef enum
{
   SWIPP_EFFECT_WATERCOLOR = 0,
   SWIPP_EFFECT_LIGHTBLUR,
   SWIPP_EFFECT_BLUR,
   SWIPP_EFFECT_STRONGBLUR,
   SWIPP_EFFECT_UNSHARP,
   SWIPP_EFFECT_SHARPEN,
   SWIPP_EFFECT_MORESHARPEN,
   SWIPP_EFFECT_MEDIAN,
   SWIPP_EFFECT_DILATION,
   SWIPP_EFFECT_EROSION
} SWIPP_EFFECT_ENUM;


typedef enum
{
  SWIPP_STATUS_OK = 0,
  SWIPP_STATUS_ERROR,
  SWIPP_STATUS_ERROR_INVALID_DST_SIZE,
  SWIPP_STATUS_ERROR_INVALID_EFFECT,

  SWIPP_STATUS_ERROR_AT_PAUSE_CHANGE_SRC_INFO,
  SWIPP_STATUS_ERROR_AT_PAUSE_CHANGE_DST_INFO,
  SWIPP_STATUS_ERROR_AT_PAUSE_CHANGE_CLIP_INFO,
  SWIPP_STATUS_ERROR_AT_PAUSE_CHANGE_WORKING_BUFFER,
  SWIPP_STATUS_ERROR_AT_PAUSE_CHANGE_EFFECT,
  SWIPP_STATUS_ERROR_AT_PAUSE_CHANGE_CALLBACK,

  SWIPP_STATUS_ERROR_RELEASE_HANDLE_AT_PROCESSING_OR_PAUSING
} SWIPP_STATUS_ENUM;


#endif
