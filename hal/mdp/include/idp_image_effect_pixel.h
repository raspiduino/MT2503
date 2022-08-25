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
 * removed!
 * removed!
 * add comment
 *
 * removed!
 * removed!
 * Image Effect Pixel scenario added in MT6236
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

#ifndef __idp_image_effect_pixel_h__
#define __idp_image_effect_pixel_h__

#include "kal_general_types.h"
#include <idp_core.h>

enum
{
  IDP_IMAGE_EFFECT_PIXEL_EXTMEM_START_ADDRESS = 1,
  IDP_IMAGE_EFFECT_PIXEL_EXTMEM_SIZE,
  
  IDP_IMAGE_EFFECT_PIXEL_SRC_ADDRESS,
  IDP_IMAGE_EFFECT_PIXEL_SRC_COLOR_FMT,
  IDP_IMAGE_EFFECT_PIXEL_SRC_WIDTH,
  IDP_IMAGE_EFFECT_PIXEL_SRC_HEIGHT,
  
  IDP_IMAGE_EFFECT_PIXEL_DEST_ADDRESS,
  IDP_IMAGE_EFFECT_PIXEL_DEST_COLOR_FMT,
  
  IDP_IMAGE_EFFECT_PIXEL_ROT_ANGLE,
  
  IDP_IMAGE_EFFECT_PIXEL_HSA,
  IDP_IMAGE_EFFECT_PIXEL_CBA,
  IDP_IMAGE_EFFECT_PIXEL_INV,
  IDP_IMAGE_EFFECT_PIXEL_CLR,
  IDP_IMAGE_EFFECT_PIXEL_GMA,
  
  IDP_IMAGE_EFFECT_PIXEL_C11,
  IDP_IMAGE_EFFECT_PIXEL_C12,
  IDP_IMAGE_EFFECT_PIXEL_C21,
  IDP_IMAGE_EFFECT_PIXEL_C22,
  
  IDP_IMAGE_EFFECT_PIXEL_SATADJ,
  
  IDP_IMAGE_EFFECT_PIXEL_COLORIZE_U,
  IDP_IMAGE_EFFECT_PIXEL_COLORIZE_V,
  
  IDP_IMAGE_EFFECT_PIXEL_GAMMA,
  IDP_IMAGE_EFFECT_PIXEL_OFF0,
  IDP_IMAGE_EFFECT_PIXEL_OFF1,
  IDP_IMAGE_EFFECT_PIXEL_OFF2,
  IDP_IMAGE_EFFECT_PIXEL_OFF3,
  IDP_IMAGE_EFFECT_PIXEL_OFF4,
  IDP_IMAGE_EFFECT_PIXEL_OFF5,
  IDP_IMAGE_EFFECT_PIXEL_OFF6,
  IDP_IMAGE_EFFECT_PIXEL_OFF7,
  IDP_IMAGE_EFFECT_PIXEL_SLP0,
  
  IDP_IMAGE_EFFECT_PIXEL_SLP1,
  IDP_IMAGE_EFFECT_PIXEL_SLP2,
  IDP_IMAGE_EFFECT_PIXEL_SLP3,
  IDP_IMAGE_EFFECT_PIXEL_SLP4,
  IDP_IMAGE_EFFECT_PIXEL_SLP5,
  IDP_IMAGE_EFFECT_PIXEL_SLP6,
  IDP_IMAGE_EFFECT_PIXEL_SLP7,
  
  IDP_IMAGE_EFFECT_PIXEL_R1X,
  IDP_IMAGE_EFFECT_PIXEL_R1Y,
  IDP_IMAGE_EFFECT_PIXEL_R2X,
  IDP_IMAGE_EFFECT_PIXEL_R2Y,
  IDP_IMAGE_EFFECT_PIXEL_R0SLP,
  IDP_IMAGE_EFFECT_PIXEL_R1SLP,
  IDP_IMAGE_EFFECT_PIXEL_R2SLP,
  IDP_IMAGE_EFFECT_PIXEL_G1X,
  IDP_IMAGE_EFFECT_PIXEL_G1Y,
  IDP_IMAGE_EFFECT_PIXEL_G2X,
  IDP_IMAGE_EFFECT_PIXEL_G2Y,
  IDP_IMAGE_EFFECT_PIXEL_G0SLP,
  IDP_IMAGE_EFFECT_PIXEL_G1SLP,
  IDP_IMAGE_EFFECT_PIXEL_G2SLP,
  IDP_IMAGE_EFFECT_PIXEL_B1X,
  IDP_IMAGE_EFFECT_PIXEL_B1Y,
  IDP_IMAGE_EFFECT_PIXEL_B2X,
  IDP_IMAGE_EFFECT_PIXEL_B2Y,
  IDP_IMAGE_EFFECT_PIXEL_B0SLP,
  IDP_IMAGE_EFFECT_PIXEL_B1SLP,
  IDP_IMAGE_EFFECT_PIXEL_B2SLP,
  
  IDP_IMAGE_EFFECT_PIXEL_BRIGHT,
  IDP_IMAGE_EFFECT_PIXEL_DARK,
  IDP_IMAGE_EFFECT_PIXEL_CONTRAST,

  IDP_IMAGE_EFFECT_PIXEL_LAST_MANDATORY_USER_CONFIG,
  // ***********************Mandatory parameter definition end****************************
  // The following region defines the optional parameters which will not be checked by idp_finish_read_user_config()

  IDP_IMAGE_EFFECT_PIXEL_INTMEM_START_ADDRESS,
  IDP_IMAGE_EFFECT_PIXEL_INTMEM_SIZE,

  //SOP of adding new parameter for this scenario
  //1. Add a new definition here
  //2. Add a corresponding variable in the config struct 
  //3. Make sure adding the matching handler for this definition in the "read_user_config_hook" function 
  //   In the switch case, default case would cause "ASSERT(0)"!!!!!
  //4. Make sure SET_BIT to variable of "read_user_config" in the "read_user_config_hook" function 
  //5. If no use in some platforms, please make sure adding the SET_BIT in the init_config_hook function
    
  IDP_IMAGE_EFFECT_PIXEL_LAST_USER_CONFIG
};


enum
{
  IDP_IMAGE_EFFECT_PIXEL_QUERY_ERROR_CODE = 1
};


typedef enum 
{
  IDP_IMAGE_EFFECT_PIXEL_NO_ERROR,
  IDP_IMAGE_EFFECT_PIXEL_ERROR_CODE_SRC_WIDTH_TOO_LARGE,
  IDP_IMAGE_EFFECT_PIXEL_ERROR_CODE_SRC_WIDTH_TOO_SMALL,
  IDP_IMAGE_EFFECT_PIXEL_ERROR_CODE_SRC_HEIGHT_TOO_LARGE,
  IDP_IMAGE_EFFECT_PIXEL_ERROR_CODE_SRC_HEIGHT_TOO_SMALL,
  IDP_IMAGE_EFFECT_PIXEL_ERROR_CODE_TAR_WIDTH_TOO_LARGE,
  IDP_IMAGE_EFFECT_PIXEL_ERROR_CODE_TAR_WIDTH_TOO_SMALL,
  IDP_IMAGE_EFFECT_PIXEL_ERROR_CODE_TAR_HEIGHT_TOO_LARGE,
  IDP_IMAGE_EFFECT_PIXEL_ERROR_CODE_TAR_HEIGHT_TOO_SMALL,
  IDP_IMAGE_EFFECT_PIXEL_ERROR_CODE_NOT_ENOUGH_MEMORY,
  IDP_IMAGE_EFFECT_PIXEL_ERROR_CODE_HW_LIMITATION
}idp_image_effect_pixel_error_code_t ;

typedef enum
{
	IDP_IMAGE_EFFECT_PIXEL_HSA_NONE = 0,
	IDP_IMAGE_EFFECT_PIXEL_HSA_GRAY = 1,
	IDP_IMAGE_EFFECT_PIXEL_HSA_COLORIZE = 2,
	IDP_IMAGE_EFFECT_PIXEL_HSA_HUE = 5,
	IDP_IMAGE_EFFECT_PIXEL_HSA_SAT = 6,
	IDP_IMAGE_EFFECT_PIXEL_HSA_HUE_SAT = 7
} idp_image_effect_pixel_hsa_enum_t;

extern kal_bool idp_image_effect_pixel_open_real(             
  kal_uint32 * const key,                           
  char const * const filename,                      
  kal_uint32 const lineno);                         

extern kal_bool idp_image_effect_pixel_close(                 
  kal_uint32 const key);                            

extern kal_bool idp_image_effect_pixel_stop(                 
  kal_uint32 const key);                            

extern kal_bool idp_image_effect_pixel_start_intermedia_pipe( 
  kal_uint32 const key);                            

extern kal_bool idp_image_effect_pixel_start_input(           
  kal_uint32 const key);                            

extern kal_bool idp_image_effect_pixel_start_output(          
  kal_uint32 const key);                            

extern kal_bool idp_image_effect_pixel_start_all(             
  kal_uint32 const key);                            

extern kal_bool idp_image_effect_pixel_config(
  kal_uint32 const key,
  ...);

extern kal_bool idp_image_effect_pixel_configurable(
  kal_uint32 const key,
  ...);

extern kal_bool idp_image_effect_pixel_config_fast(
  kal_uint32 const key,
  kal_uint32 const para_type,
  kal_uint32 const para_value);

extern kal_bool idp_image_effect_pixel_query(
  kal_uint32 const key,
  ...);

extern kal_bool idp_image_effect_pixel_config_and_start(
  kal_uint32 const key,
  ...);

extern kal_bool idp_image_effect_pixel_is_busy(               
  kal_uint32 const key,                             
  kal_bool * const busy);

extern kal_bool idp_image_effect_pixel_is_in_use(void);

#define idp_image_effect_pixel_open(key) idp_image_effect_pixel_open_real(key, __FILE__, __LINE__)

#endif
