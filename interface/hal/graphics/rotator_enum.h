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
 *   rotator_enum.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Resizer
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __ROTATOR_ENUM_H__
#define __ROTATOR_ENUM_H__


typedef enum {
  ROTATOR_COLOR_FORMAT_ENUM_UNSUPPORTED = 0,
  
  ROTATOR_COLOR_FORMAT_ENUM_GRAY,
  
  ROTATOR_COLOR_FORMAT_ENUM_RGB565,
  ROTATOR_COLOR_FORMAT_ENUM_RGB888,
  ROTATOR_COLOR_FORMAT_ENUM_BGR888,
  ROTATOR_COLOR_FORMAT_ENUM_ARGB8888,
  ROTATOR_COLOR_FORMAT_ENUM_PARGB8888,
  
  ROTATOR_COLOR_FORMAT_ENUM_ARGB6666,
  ROTATOR_COLOR_FORMAT_ENUM_PARGB6666,
  
  ROTATOR_COLOR_FORMAT_ENUM_YUV420_P,
  ROTATOR_COLOR_FORMAT_ENUM_YUV420_B4x4_P,
  ROTATOR_COLOR_FORMAT_ENUM_UYVY422,
  
  ROTATOR_COLOR_FORMAT_ENUM_END
} ROTATOR_COLOR_FORMAT_ENUM;



typedef enum {
   ROTATOR_MODE_HW = 0,
   ROTATOR_MODE_SW,
   ROTATOR_MODE_AUTO
   
} ROTATOR_MODE_ENUM;



typedef enum {
   ROTATOR_TYPE_HW = 0,
   ROTATOR_TYPE_SW
   
} ROTATOR_TYPE_ENUM;


typedef enum {
  ROTATOR_MEMORY_TYPE_NO_SWITCH  = 0,
  ROTATOR_MEMORY_TYPE_SWITCH_TO_CACHEABLE,
  ROTATOR_MEMORY_TYPE_SWITCH_TO_NONCACHEABLE

} ROTATOR_MEMORY_TYPE_ENUM;


typedef enum {	
   ROTATOR_STATUS_NOT_SUPPORT_PITCH = -11,
   ROTATOR_STATUS_NOT_SUPPORT_ROTATE_ANGLE = -10,
   ROTATOR_STATUS_STATE_ERROR = -9,
   ROTATOR_STATUS_NOT_SUPPORT_CSC = -8,
   ROTATOR_STATUS_NOT_ENOUGH_MEMORY = -7,
   ROTATOR_STATUS_HW_ERROR = -6,
   ROTATOR_STATUS_NOT_SUPPORT_COLOR_FORMAT = -5,
   ROTATOR_STATUS_RANGE_CHECK_FAIL = -4,
   ROTATOR_STATUS_NOT_SUPPORT = -3,
   ROTATOR_STATUS_SW_ERROR = -2,
   ROTATOR_STATUS_NULL = -1,
   ROTATOR_STATUS_BUSY = 0,
   ROTATOR_STATUS_OK = 1,      	      
   ROTATOR_STATUS_COMPLETE = 2   

} ROTATOR_STATUS_ENUM;



typedef enum{
   ROTATOR_STATE_IDLE        = 0x0,    
   ROTATOR_STATE_SETTING_PARAMETER, 
   ROTATOR_STATE_READY, 
   ROTATOR_STATE_BUSY,    
   ROTATOR_STATE_COMPLETE,  
   ROTATOR_STATE_ABORTING        
} ROTATOR_STATE_ENUM;



typedef enum
{
   ROTATOR_CW_ROTATE_ANGLE_000 = 0,                  ///< No rotation.
   ROTATOR_CW_ROTATE_ANGLE_090,                      ///< Rotate 90 degree.
   ROTATOR_CW_ROTATE_ANGLE_180,                      ///< Rotate 180 degree.
   ROTATOR_CW_ROTATE_ANGLE_270,                      ///< Rotate 270 degree.
   ROTATOR_CW_ROTATE_ANGLE_MIRROR_000,               ///< Mirror with no rotation.
   ROTATOR_CW_ROTATE_ANGLE_MIRROR_090,               ///< Rotate 90 degree and mirror.
   ROTATOR_CW_ROTATE_ANGLE_MIRROR_180,               ///< Rotate 180 degree and mirror.
   ROTATOR_CW_ROTATE_ANGLE_MIRROR_270                ///< Rotate 270 degree and mirror.
} ROTATOR_CW_ROTATE_ANGLE_ENUM;


typedef kal_bool (*ROTATOR_CALLBACK_FUNC_PTR)(void *);

#endif

