/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
 *
 * Project:
 * --------
 *	 Maui
 *
 * Description:
 * ------------
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 12 17 2010 cm.huang
 * removed!
 * .
 *
 * 11 23 2010 cm.huang
 * removed!
 * .
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * add comment
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_camera_preview_with_face_detection_h__
#define __idp_camera_preview_with_face_detection_h__

#include <idp_core.h>
#include "idp_define.h"
#include "kal_general_types.h"

enum
{
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_INTMEM_START_ADDRESS = 1,
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_INTMEM_SIZE,
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_EXTMEM_START_ADDRESS,
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_EXTMEM_SIZE,
  
#if ENABLE_UT
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_IMAGE_BUFFER_ADDRESS,
#endif
  
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_IMAGE_SRC_WIDTH,
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_IMAGE_SRC_HEIGHT,
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_PREVIEW_WIDTH,
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_PREVIEW_HEIGHT,
  
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_ENABLE_PITCH,
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_BG_IMAGE_WIDTH,
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_IMAGE_DATA_FORMAT,
  
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_ENABLE_OVERLAY,
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_SET_OVERLAY_PALETTE_SIZE_AND_ADDR,
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_OVERLAY_PALETTE_MODE,
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_OVERLAY_FRAME_SOURCE_KEY,
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_OVERLAY_FRAME_WIDTH,
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_OVERLAY_FRAME_HEIGHT,
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_OVERLAY_FRAME_BUFFER_ADDRESS,
  
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_FRAME_BUFFER_ADDRESS,
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_FRAME_BUFFER_ADDRESS1,
  
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_ROT_ANGLE,
  
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_RESIZER_U_VALUE,
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_RESIZER_V_VALUE,
  
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_FRAME_START_HISR_CB_ENABLE,
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_FRAME_START_HISR_CB_AND_PARAM,
  
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_FACE_DETECTION_WIDTH,
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_FACE_DETECTION_HEIGHT,
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_FACE_DETECTION_BUFFER_ADDRESS_1,
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_FACE_DETECTION_BUFFER_ADDRESS_2,
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_FACE_DETECTION_BUFFER_ADDRESS_3,
  
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_AUTO_RESTART,
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_FLIP,
  
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_ENABLE_LAST_STAGE_DONE_LISR,
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_LAST_STAGE_DONE_LISR_CB_AND_PARAM,
  
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_ENABLE_TRIGGER_LCD, /**< KAL_TRUE to enable trigger LCD, KAL_FALSE to disable trigger LCD */

  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_ADV_LCD_RD_PTR,

  //SOP of adding new parameter for this scenario
  //1. Add a new definition here
  //2. Add a corresponding variable in the config struct 
  //3. Make sure adding the matching handler for this definition in the "read_user_config_hook" function 
  //   In the switch case, default case would cause "ASSERT(0)"!!!!!
  //4. Make sure SET_BIT to variable of "read_user_config" in the "read_user_config_hook" function 
  //5. If no use in some platforms, please make sure adding the SET_BIT in the init_config_hook function
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_LAST_USER_CONFIG
};

enum
{
  IDP_CAMERA_PREVIEW_WITH_FACE_DETECTION_QUERY_CURRENT_BUFFER_ADDR_FOR_FACE_DETECTION = 1
};

extern kal_bool idp_camera_preview_with_face_detection_open_real(
  kal_uint32 * const key,                           
  char const * const filename,                      
  kal_uint32 const lineno);                         

extern kal_bool idp_camera_preview_with_face_detection_close(                 
  kal_uint32 const key);                            

extern kal_bool idp_camera_preview_with_face_detection_stop(                 
  kal_uint32 const key);                            

extern kal_bool idp_camera_preview_with_face_detection_start_intermedia_pipe( 
  kal_uint32 const key);                            

extern kal_bool idp_camera_preview_with_face_detection_start_input(           
  kal_uint32 const key);                            

extern kal_bool idp_camera_preview_with_face_detection_start_output(          
  kal_uint32 const key);                            

extern kal_bool idp_camera_preview_with_face_detection_start_all(             
  kal_uint32 const key);                            

extern kal_bool idp_camera_preview_with_face_detection_config(
  kal_uint32 const key,
  ...);

extern kal_bool idp_camera_preview_with_face_detection_configurable(
  kal_uint32 const key,
  ...);

extern kal_bool idp_camera_preview_with_face_detection_config_fast(
  kal_uint32 const key,
  kal_uint32 const para_type,
  kal_uint32 const para_value);

extern kal_bool idp_camera_preview_with_face_detection_query(
  kal_uint32 const key,
  ...);

extern kal_bool idp_camera_preview_with_face_detection_config_and_start(
  kal_uint32 const key,
  ...);

extern kal_bool idp_camera_preview_with_face_detection_is_busy(               
  kal_uint32 const key,                             
  kal_bool * const busy);

extern kal_bool idp_camera_preview_with_face_detection_is_in_use(void);

#define idp_camera_preview_with_face_detection_open(key) idp_camera_preview_with_face_detection_open_real(key, __FILE__, __LINE__)

#endif
