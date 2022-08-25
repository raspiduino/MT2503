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
 * 02 07 2012 chrono.wu
 * removed!
 * .
 *
 * 01 10 2012 chrono.wu
 * removed!
 * .
 *
 * 11 14 2011 chrono.wu
 * removed!
 * .
 *
 * 09 23 2011 chelun.tsai
 * removed!
 * .
 *
 * 08 04 2011 chelun.tsai
 * removed!
 * .
 *
 * 07 27 2011 chelun.tsai
 * removed!
 * .
 *
 * 03 16 2011 chrono.wu
 * removed!
 * .
 *
 * 01 20 2011 chrono.wu
 * removed!
 * .
 *
 * 01 14 2011 chrono.wu
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
 * 11 15 2010 cm.huang
 * NULL
 * .
 *
 * 11 15 2010 cm.huang
 * NULL
 * fix build error.
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
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_jpeg_decode_h__
#define __idp_jpeg_decode_h__

#include "kal_general_types.h"
#include <idp_core.h>

/*******************************************************************************
 *  Options
 ******************************************************************************/
#define IDP_JPEG_DECODE__OUTPUT_ARGB8888

/*******************************************************************************
 *  Typedef
 ******************************************************************************/
enum
{
  IDP_JPEG_DECODE_EXTMEM_START_ADDRESS = 1,
  IDP_JPEG_DECODE_EXTMEM_SIZE,
  
  IDP_JPEG_DECODE_JPEG_REAL_WIDTH,
  IDP_JPEG_DECODE_JPEG_REAL_HEIGHT,
  IDP_JPEG_DECODE_JPEG_DUMMY_WIDTH,
  IDP_JPEG_DECODE_JPEG_DUMMY_HEIGHT,
  IDP_JPEG_DECODE_JPEG_NUMBER_OF_COMPONENT,
  IDP_JPEG_DECODE_JPEG_Y_H_SAMPLE_FACTOR,
  IDP_JPEG_DECODE_JPEG_Y_V_SAMPLE_FACTOR,
  IDP_JPEG_DECODE_JPEG_U_H_SAMPLE_FACTOR,
  IDP_JPEG_DECODE_JPEG_U_V_SAMPLE_FACTOR,
  IDP_JPEG_DECODE_JPEG_V_H_SAMPLE_FACTOR,
  IDP_JPEG_DECODE_JPEG_V_V_SAMPLE_FACTOR,
  
  IDP_JPEG_DECODE_IMAGE_BUFFER_ADDRESS,
  IDP_JPEG_DECODE_IMAGE_UBUFFER_ADDRESS,
  IDP_JPEG_DECODE_IMAGE_VBUFFER_ADDRESS,
  IDP_JPEG_DECODE_IMAGE_BUFFER_SIZE,
  IDP_JPEG_DECODE_DISPLAY_WIDTH,
  IDP_JPEG_DECODE_DISPLAY_HEIGHT,
  
  // this clip interface is dest. clip for MDP(MT6268 supports only dest. clip), 
  // jpeg decoder will transform the source clip(to cut the dummy pixels)
  // to destination clip no matter resize is performed or not.
  IDP_JPEG_DECODE_IMAGE_CLIP_LEFT,
  IDP_JPEG_DECODE_IMAGE_CLIP_RIGHT,
  IDP_JPEG_DECODE_IMAGE_CLIP_TOP,
  IDP_JPEG_DECODE_IMAGE_CLIP_BOTTOM,
  
  IDP_JPEG_DECODE_ENABLE_PITCH,
  IDP_JPEG_DECODE_BG_IMAGE_WIDTH,
  
  IDP_JPEG_DECODE_IMAGE_DATA_FORMAT,
  
  IDP_JPEG_DECODE_ROT_ANGLE,
  
  IDP_JPEG_DECODE_JPEG_DECODE_FINISH_CB,
  IDP_JPEG_DECODE_JPEG_DECODE_FINISH_CB_PARAM,

  IDP_JPEG_DECODE_LAST_MANDATORY_USER_CONFIG,
  // ***********************Mandatory parameter definition end****************************
  // The following region defines the optional parameters which will not be checked by idp_finish_read_user_config()

  // currently unused interfaces
  IDP_JPEG_DECODE_INTMEM_START_ADDRESS,
  IDP_JPEG_DECODE_INTMEM_SIZE,

  //SOP of adding new parameter for this scenario
  //1. Add a new definition here
  //2. Add a corresponding variable in the config struct 
  //3. Make sure adding the matching handler for this definition in the "read_user_config_hook" function 
  //   In the switch case, default case would cause "ASSERT(0)"!!!!!
  //4. Make sure SET_BIT to variable of "read_user_config" in the "read_user_config_hook" function 
  //5. If no use in some platforms, please make sure adding the SET_BIT in the init_config_hook function  
  
  IDP_JPEG_DECODE_LAST_USER_CONFIG
};

enum
{
  IDP_JPEG_DECODE_QUERY_ERROR_CODE = 1,
  IDP_JPEG_DECODE_QUERY_EXT_MEM_SIZE
};

enum idp_jpeg_decode_error_code_t
{
  IDP_JPEG_DECODE_NO_ERROR,
  IDP_JPEG_DECODE_ERROR_CODE_SRC_WIDTH_TOO_LARGE,
  IDP_JPEG_DECODE_ERROR_CODE_SRC_WIDTH_TOO_SMALL,
  IDP_JPEG_DECODE_ERROR_CODE_SRC_HEIGHT_TOO_LARGE,
  IDP_JPEG_DECODE_ERROR_CODE_SRC_HEIGHT_TOO_SMALL,
  IDP_JPEG_DECODE_ERROR_CODE_TAR_WIDTH_TOO_LARGE,
  IDP_JPEG_DECODE_ERROR_CODE_TAR_WIDTH_TOO_SMALL,
  IDP_JPEG_DECODE_ERROR_CODE_TAR_HEIGHT_TOO_LARGE,
  IDP_JPEG_DECODE_ERROR_CODE_TAR_HEIGHT_TOO_SMALL,
  IDP_JPEG_DECODE_ERROR_CODE_NOT_ENOUGH_MEMORY,
  IDP_JPEG_DECODE_ERROR_CODE_HW_LIMITATION, 
  IDP_JPEG_DECODE_ERROR_CODE_HW_IN_USE /**< Some HW engine needed in this path is in use. */
};
typedef enum idp_jpeg_decode_error_code_t idp_jpeg_decode_error_code_t;

extern kal_bool idp_jpeg_decode_open_real(             
  kal_uint32 * const key,                           
  char const * const filename,                      
  kal_uint32 const lineno);                         

extern kal_bool idp_jpeg_decode_close(                 
  kal_uint32 const key);                            

extern kal_bool idp_jpeg_decode_stop(                 
  kal_uint32 const key);                            

extern kal_bool idp_jpeg_decode_start_intermedia_pipe( 
  kal_uint32 const key);                            

extern kal_bool idp_jpeg_decode_start_input(           
  kal_uint32 const key);                            

extern kal_bool idp_jpeg_decode_start_output(          
  kal_uint32 const key);                            

extern kal_bool idp_jpeg_decode_start_all(             
  kal_uint32 const key);                            

extern kal_bool idp_jpeg_decode_config(
  kal_uint32 const key,
  ...);

extern kal_bool idp_jpeg_decode_configurable(
  kal_uint32 const key,
  ...);

extern kal_bool idp_jpeg_decode_config_fast(
  kal_uint32 const key,
  kal_uint32 const para_type,
  kal_uint32 const para_value);

extern kal_bool idp_jpeg_decode_query(
  kal_uint32 const key,
  ...);

extern kal_bool idp_jpeg_decode_config_and_start(
  kal_uint32 const key,
  ...);

extern kal_bool idp_jpeg_decode_is_busy(               
  kal_uint32 const key,                             
  kal_bool * const busy);

extern kal_bool idp_jpeg_decode_is_in_use(void);

/* 
 * for MT6256E2 mjpg decode only, and only support on MT6256E2 while mjpeg decode feature is on.  
 * The 2 APIs must be called before idp_jpeg_decode_open()
 * For mjpeg decode, call idp_jpeg_decode_mjpg_mode_enable()
 * For normag jpeg decode, call idp_jpeg_decode_mjpg_mode_disable()
 */

#if defined(DRV_IDP_MT6256_E2_SERIES) && defined(MJPG_DECODE)
extern void idp_jpeg_decode_mjpg_mode_enable(void);

extern void idp_jpeg_decode_mjpg_mode_disable(void);
#endif // #if defined(DRV_IDP_MT6256_E2_SERIES) && defined(MJPG_DECODE)

#define idp_jpeg_decode_open(key) idp_jpeg_decode_open_real(key, __FILE__, __LINE__)

#endif
