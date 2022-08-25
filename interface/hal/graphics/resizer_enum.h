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
 *   resizer_enum.h
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
#ifndef __RESIZER_ENUM_H__
#define __RESIZER_ENUM_H__


typedef enum {
  RESIZER_COLOR_FORMAT_ENUM_UNSUPPORTED = 0,

  RESIZER_COLOR_FORMAT_ENUM_RGB565,
  RESIZER_COLOR_FORMAT_ENUM_RGB888,
  RESIZER_COLOR_FORMAT_ENUM_BGR888,
  RESIZER_COLOR_FORMAT_ENUM_ARGB8888,
  RESIZER_COLOR_FORMAT_ENUM_PARGB8888,
  RESIZER_COLOR_FORMAT_ENUM_ARGB6666,
  RESIZER_COLOR_FORMAT_ENUM_PARGB6666,
  RESIZER_COLOR_FORMAT_ENUM_END
} RESIZER_COLOR_FORMAT_ENUM;



typedef enum {
   RESIZER_MODE_HW = 0,
   RESIZER_MODE_SW,
   RESIZER_MODE_AUTO
   
} RESIZER_MODE_ENUM;



typedef enum {
   RESIZER_TYPE_HW = 0,
   RESIZER_TYPE_SW
   
} RESIZER_TYPE_ENUM;

typedef enum {
  RESIZER_MEMORY_TYPE_NO_SWITCH  = 0,
  RESIZER_MEMORY_TYPE_SWITCH_TO_CACHEABLE,
  RESIZER_MEMORY_TYPE_SWITCH_TO_NONCACHEABLE

} RESIZER_MEMORY_TYPE_ENUM;


typedef enum {	
   RESIZER_STATUS_STATE_ERROR = -9,
   RESIZER_STATUS_NOT_SUPPORT_CSC = -8,
   RESIZER_STATUS_NOT_ENOUGH_MEMORY = -7,
   RESIZER_STATUS_HW_ERROR = -6,
   RESIZER_STATUS_NOT_SUPPORT_COLOR_FORMAT = -5,
   RESIZER_STATUS_RANGE_CHECK_FAIL = -4,
   RESIZER_STATUS_NOT_SUPPORT = -3,
   RESIZER_STATUS_SW_ERROR = -2,
   RESIZER_STATUS_NULL = -1,
   RESIZER_STATUS_BUSY = 0,
   RESIZER_STATUS_OK = 1,      	      
   RESIZER_STATUS_COMPLETE = 2   

} RESIZER_STATUS_ENUM;



typedef enum{
   RESIZER_STATE_IDLE        = 0x0,    
   RESIZER_STATE_SETTING_PARAMETER, 
   RESIZER_STATE_READY, 
   RESIZER_STATE_BUSY,    
   RESIZER_STATE_COMPLETE,  
   RESIZER_STATE_ABORTING        
} RESIZER_STATE_ENUM;



typedef enum {	
   RESIZER_QUALITY_HIGH = 0,
   RESIZER_QUALITY_MEDIUM,
   RESIZER_QUALITY_LOW
   
} RESIZER_QUALITY_ENUM;


typedef kal_bool (*RESIZER_CALLBACK_FUNC_PTR)(void *);

#endif

