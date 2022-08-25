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
 * 09 21 2011 chrono.wu
 * removed!
 * .
 *
 * 04 20 2011 chrono.wu
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
 * 11 09 2010 cm.huang
 * NULL
 * .
 *
 * 11 05 2010 cm.huang
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

#ifndef __idp_camera_capture_to_jpeg_h__
#define __idp_camera_capture_to_jpeg_h__

#include <idp_core.h>
#include "idp_define.h"
#include "kal_general_types.h"

enum
{
  IDP_CAMERA_CAPTURE_TO_JPEG_EXTMEM_START_ADDRESS = 1,
  IDP_CAMERA_CAPTURE_TO_JPEG_EXTMEM_SIZE,

  IDP_CAMERA_CAPTURE_TO_JPEG_IMAGE_SRC_WIDTH,
  IDP_CAMERA_CAPTURE_TO_JPEG_IMAGE_SRC_HEIGHT,

  //fullsize image refers to the largest size image for still image encoding. There is no switch for this image, as it could be the only image in the low cost platforms(6235/6253).
  IDP_CAMERA_CAPTURE_TO_JPEG_FULLSIZE_IMAGE_ROT_ANGLE,
  IDP_CAMERA_CAPTURE_TO_JPEG_FULLSIZE_IMAGE_FORMAT,
  IDP_CAMERA_CAPTURE_TO_JPEG_FULLSIZE_IMAGE_CAPTURE_WIDTH,
  IDP_CAMERA_CAPTURE_TO_JPEG_FULLSIZE_IMAGE_CAPTURE_HEIGHT,
  IDP_CAMERA_CAPTURE_TO_JPEG_FULLSIZE_JPEG_YUV_MODE, // JPEG gray mode
  IDP_CAMERA_CAPTURE_TO_JPEG_FULLSIZE_IMAGE_YUV_ADDRESSES,  // three arguments, if RGB565, only first one is valid

  //quickview image refers to the display size image. For low cost platforms, it may be disabled.
  IDP_CAMERA_CAPTURE_TO_JPEG_ENABLE_QUICKVIEW, // to replace IDP_CAMERA_CAPTURE_TO_JPEG_OUTPUT_RGB,
  IDP_CAMERA_CAPTURE_TO_JPEG_QUICKVIEW_ROT_ANGLE,
  IDP_CAMERA_CAPTURE_TO_JPEG_QUICKVIEW_IMAGE_COLOR_FORMAT,
  IDP_CAMERA_CAPTURE_TO_JPEG_QUICKVIEW_WIDTH,
  IDP_CAMERA_CAPTURE_TO_JPEG_QUICKVIEW_HEIGHT,
  IDP_CAMERA_CAPTURE_TO_JPEG_QUICKVIEW_FRAME_BUFFER_ADDRESS,
  IDP_CAMERA_CAPTURE_TO_JPEG_ENABLE_QUICKVIEW_PITCH, // to replace IDP_CAMERA_CAPTURE_TO_JPEG_ENABLE_PITCH
  IDP_CAMERA_CAPTURE_TO_JPEG_QUICKVIEW_PITCH_WIDTH, // to replace IDP_CAMERA_CAPTURE_TO_JPEG_BG_IMAGE_WIDTH,

  //thumbnail image is the smallest image. For low cost platforms, it may be disabled.
  IDP_CAMERA_CAPTURE_TO_JPEG_ENABLE_THUMBNAIL,
  IDP_CAMERA_CAPTURE_TO_JPEG_THUMBNAIL_ROT_ANGLE,
  IDP_CAMERA_CAPTURE_TO_JPEG_THUMBNAIL_IMAGE_COLOR_FORMAT,
  IDP_CAMERA_CAPTURE_TO_JPEG_THUMBNAIL_WIDTH,
  IDP_CAMERA_CAPTURE_TO_JPEG_THUMBNAIL_HEIGHT,
  IDP_CAMERA_CAPTURE_TO_JPEG_THUMBNAIL_BUFFER_ADDRESS,

  IDP_CAMERA_CAPTURE_TO_JPEG_ENABLE_OVERLAY,
  IDP_CAMERA_CAPTURE_TO_JPEG_SET_OVERLAY_PALETTE_SIZE_AND_ADDR,
  IDP_CAMERA_CAPTURE_TO_JPEG_OVERLAY_PALETTE_MODE,
  IDP_CAMERA_CAPTURE_TO_JPEG_OVERLAY_FRAME_SOURCE_KEY,
  IDP_CAMERA_CAPTURE_TO_JPEG_OVERLAY_FRAME_WIDTH,
  IDP_CAMERA_CAPTURE_TO_JPEG_OVERLAY_FRAME_HEIGHT,
  IDP_CAMERA_CAPTURE_TO_JPEG_OVERLAY_FRAME_BUFFER_ADDRESS,
  
  IDP_CAMERA_CAPTURE_TO_JPEG_CROP_ENABLE,
  IDP_CAMERA_CAPTURE_TO_JPEG_CROP_WIDTH,
  IDP_CAMERA_CAPTURE_TO_JPEG_CROP_HEIGHT,

  IDP_CAMERA_CAPTURE_TO_JPEG_LAST_MANDATORY_USER_CONFIG,
  // ***********************Mandatory parameter definition end****************************
  // The following region defines the optional parameters which will not be checked by idp_finish_read_user_config()

  // currently unused interfaces
  IDP_CAMERA_CAPTURE_TO_JPEG_INTMEM_START_ADDRESS,
  IDP_CAMERA_CAPTURE_TO_JPEG_INTMEM_SIZE,
  IDP_CAMERA_CAPTURE_TO_JPEG_RESIZER_U_VALUE, // should it from CAL or from custom file directly?
  IDP_CAMERA_CAPTURE_TO_JPEG_RESIZER_D_VALUE,

#if ENABLE_UT
  IDP_CAMERA_CAPTURE_TO_JPEG_IMAGE_BUFFER_ADDRESS,
#endif

  //SOP of adding new parameter for this scenario
  //1. Add a new definition here
  //2. Add a corresponding variable in the config struct
  //3. Make sure adding the matching handler for this definition in the "read_user_config_hook" function
  //   In the switch case, default case would cause "ASSERT(0)"!!!!!
  //4. Make sure SET_BIT to variable of "read_user_config" in the "read_user_config_hook" function
  //5. If no use in some platforms, please make sure adding the SET_BIT in the init_config_hook function
  IDP_CAMERA_CAPTURE_TO_JPEG_LAST_USER_CONFIG

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
};

enum
{
  IDP_CAMERA_CAPTURE_TO_JPEG_QUERY_TYPE = 1,
  IDP_CAMERA_CAPTURE_TO_JPEG_QUERY_ARG_PATH,
  IDP_CAMERA_CAPTURE_TO_JPEG_QUERY_ARG_CLR_FMT,
  IDP_CAMERA_CAPTURE_TO_JPEG_QUERY_ARG_DESIRED_ANGLE,  
  IDP_CAMERA_CAPTURE_TO_JPEG_QUERY_RESULT
};

extern kal_bool idp_camera_capture_to_jpeg_open_real(
  kal_uint32 * const key,
  char const * const filename,
  kal_uint32 const lineno);

extern kal_bool idp_camera_capture_to_jpeg_close(
  kal_uint32 const key);

extern kal_bool idp_camera_capture_to_jpeg_stop(
  kal_uint32 const key);

extern kal_bool idp_camera_capture_to_jpeg_start_intermedia_pipe(
  kal_uint32 const key);

extern kal_bool idp_camera_capture_to_jpeg_start_input(
  kal_uint32 const key);

extern kal_bool idp_camera_capture_to_jpeg_start_output(
  kal_uint32 const key);

extern kal_bool idp_camera_capture_to_jpeg_start_all(
  kal_uint32 const key);

extern kal_bool idp_camera_capture_to_jpeg_config(
  kal_uint32 const key,
  ...);

extern kal_bool idp_camera_capture_to_jpeg_configurable(
  kal_uint32 const key,
  ...);

extern kal_bool idp_camera_preview_to_jpeg_config_fast(
  kal_uint32 const key,
  kal_uint32 const para_type,
  kal_uint32 const para_value);

extern kal_bool idp_camera_capture_to_jpeg_query(
  kal_uint32 const key,
  ...);

extern kal_bool idp_camera_capture_to_jpeg_config_and_start(
  kal_uint32 const key,
  ...);

extern kal_bool idp_camera_capture_to_jpeg_is_busy(
  kal_uint32 const key,
  kal_bool * const busy);

extern kal_bool idp_camera_capture_to_jpeg_is_in_use(void);

#define idp_camera_capture_to_jpeg_open(key) idp_camera_capture_to_jpeg_open_real(key, __FILE__, __LINE__)

#endif
