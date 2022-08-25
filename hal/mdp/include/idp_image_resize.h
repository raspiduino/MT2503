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
 * 06 04 2012 peter.wang
 * removed!
 * .
 *
 * 05 08 2012 chrono.wu
 * removed!
 * .
 *
 * 04 19 2012 chrono.wu
 * removed!
 * .
 *
 * 02 07 2012 chrono.wu
 * removed!
 * .
 *
 * 01 10 2012 chrono.wu
 * removed!
 * .
 *
 * 12 17 2010 cm.huang
 * removed!
 * .
 *
 * 11 23 2010 cm.huang
 * removed!
 * .
 *
 * 11 19 2010 cm.huang
 * NULL
 * .
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
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_image_resize_h__
#define __idp_image_resize_h__

#include "kal_general_types.h"
#include <idp_core.h>

enum
{
  IDP_IMAGE_RESIZE_EXTMEM_START_ADDRESS = 1,
  IDP_IMAGE_RESIZE_EXTMEM_SIZE,
  
  IDP_IMAGE_RESIZE_SRC_COLOR_FMT,  
  IDP_IMAGE_RESIZE_DEST_COLOR_FMT,
  
  IDP_IMAGE_RESIZE_SRC_IMAGE_ADDRESS,
  IDP_IMAGE_RESIZE_DEST_IMAGE_ADDRESS,
  
  IDP_IMAGE_RESIZE_SRC_WIDTH,
  IDP_IMAGE_RESIZE_SRC_HEIGHT,
  
  IDP_IMAGE_RESIZE_TARGET_WIDTH,
  IDP_IMAGE_RESIZE_TARGET_HEIGHT,
  
  IDP_IMAGE_RESIZE_ENABLE_CLIP,
  IDP_IMAGE_RESIZE_CLIP_LEFT,
  IDP_IMAGE_RESIZE_CLIP_RIGHT,
  IDP_IMAGE_RESIZE_CLIP_TOP,
  IDP_IMAGE_RESIZE_CLIP_BOTTOM,
  
  IDP_IMAGE_RESIZE_ENABLE_PITCH,
  IDP_IMAGE_RESIZE_BG_IMAGE_WIDTH,
  
  IDP_IMAGE_RESIZE_ROT_ANGLE,
    
  IDP_IMAGE_RESIZE_LAST_MANDATORY_USER_CONFIG,
  // ***********************Mandatory parameter definition end****************************
  // The following region defines the optional parameters which will not be checked by idp_finish_read_user_config()

  // currently unused interfaces
  IDP_IMAGE_RESIZE_INTMEM_START_ADDRESS,
  IDP_IMAGE_RESIZE_INTMEM_SIZE,
  IDP_IMAGE_RESIZE_RESIZER_U_VALUE,
  IDP_IMAGE_RESIZE_RESIZER_V_VALUE,

  IDP_IMAGE_RESIZE_FRAME_DONE_CB, /**< Optional. 
                                       Type: idp_hisr_intr_cb_t 
                                       (defined in mcu\drv\idp\include\idp_core.h); 
                                       If NULL (default), no callback. 
                                       Will be invoked in HISR level thread. 
                                       Only invoked when MDP is done successfully. 
                                   */

  IDP_IMAGE_RESIZE_FRAME_DONE_CB_PARAM, /**< Optional.
                                             Type: void* 
                                             Whatever you passed in, 
                                             MDP passes it to your cb. 
                                         */

  // dither function enable(chip dependent)
  IDP_IMAGE_RESIZE_IPP_ENABLE_SPATIAL_DITHERING, /**< Set argument to KAL_TRUE (default) to enable spatial dithering, KAL_FALSE to disable spatial dithering. */

  IDP_IMAGE_RESIZE_SRC_IMAGE_U_ADDRESS,
  IDP_IMAGE_RESIZE_SRC_IMAGE_V_ADDRESS,
  IDP_IMAGE_RESIZE_ENABLE_SRC_CLIP,
  IDP_IMAGE_RESIZE_SRC_CLIP_LEFT,
  IDP_IMAGE_RESIZE_SRC_CLIP_RIGHT,
  IDP_IMAGE_RESIZE_SRC_CLIP_TOP,
  IDP_IMAGE_RESIZE_SRC_CLIP_BOTTOM,
  IDP_IMAGE_RESIZE_ENABLE_SRC_PITCH,
  IDP_IMAGE_RESIZE_SRC_BG_IMAGE_WIDTH,

  //SOP of adding new parameter for this scenario
  //1. Add a new definition here
  //2. Add a corresponding variable in the config struct 
  //3. Make sure adding the matching handler for this definition in the "read_user_config_hook" function 
  //   In the switch case, default case would cause "ASSERT(0)"!!!!!
  //4. Make sure SET_BIT to variable of "read_user_config" in the "read_user_config_hook" function 
  //5. If no use in some platforms, please make sure adding the SET_BIT in the init_config_hook function  

  IDP_IMAGE_RESIZE_ENG_CONFIG,   // Only for MT6250 no check bit and use end config
  
  IDP_IMAGE_RESIZE_LAST_USER_CONFIG
};

enum
{
  IDP_IMAGE_RESIZE_QUERY_ERROR_CODE = 1
};

enum idp_image_resize_error_code_t
{
  IDP_IMAGE_RESIZE_NO_ERROR,
  IDP_IMAGE_RESIZE_ERROR_CODE_SRC_WIDTH_TOO_LARGE,
  IDP_IMAGE_RESIZE_ERROR_CODE_SRC_WIDTH_TOO_SMALL,
  IDP_IMAGE_RESIZE_ERROR_CODE_SRC_HEIGHT_TOO_LARGE,
  IDP_IMAGE_RESIZE_ERROR_CODE_SRC_HEIGHT_TOO_SMALL,
  IDP_IMAGE_RESIZE_ERROR_CODE_TAR_WIDTH_TOO_LARGE,
  IDP_IMAGE_RESIZE_ERROR_CODE_TAR_WIDTH_TOO_SMALL,
  IDP_IMAGE_RESIZE_ERROR_CODE_TAR_HEIGHT_TOO_LARGE,
  IDP_IMAGE_RESIZE_ERROR_CODE_TAR_HEIGHT_TOO_SMALL,
  IDP_IMAGE_RESIZE_ERROR_CODE_NOT_ENOUGH_MEMORY,
  IDP_IMAGE_RESIZE_ERROR_CODE_HW_LIMITATION
};
typedef enum idp_image_resize_error_code_t idp_image_resize_error_code_t;

extern kal_bool idp_image_resize_open_real(             
  kal_uint32 * const key,                           
  char const * const filename,                      
  kal_uint32 const lineno);                         

extern kal_bool idp_image_resize_close(                 
  kal_uint32 const key);                            

extern kal_bool idp_image_resize_stop(                 
  kal_uint32 const key);                            

extern kal_bool idp_image_resize_start_intermedia_pipe( 
  kal_uint32 const key);                            

extern kal_bool idp_image_resize_start_input(           
  kal_uint32 const key);                            

extern kal_bool idp_image_resize_start_output(          
  kal_uint32 const key);                            

extern kal_bool idp_image_resize_start_all(             
  kal_uint32 const key);                            

extern kal_bool idp_image_resize_config(
  kal_uint32 const key,
  ...);

extern kal_bool idp_image_resize_configurable(
  kal_uint32 const key,
  ...);

extern kal_bool idp_image_resize_config_fast(
  kal_uint32 const key,
  kal_uint32 const para_type,
  kal_uint32 const para_value);

extern kal_bool idp_image_resize_query(
  kal_uint32 const key,
  ...);

extern kal_bool idp_image_resize_config_and_start(
  kal_uint32 const key,
  ...);

extern kal_bool idp_image_resize_is_busy(               
  kal_uint32 const key,                             
  kal_bool * const busy);

extern kal_bool idp_image_resize_is_in_use(void);

#define idp_image_resize_open(key) idp_image_resize_open_real(key, __FILE__, __LINE__)

#endif
