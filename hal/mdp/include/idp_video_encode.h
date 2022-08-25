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
 * 03 25 2013 chrono.wu
 * removed!
 * MT6260 WVGA Camera features support full screen.
 *
 * 02 07 2012 chrono.wu
 * removed!
 * .
 *
 * 01 10 2012 chrono.wu
 * removed!
 * .
 *
 * 12 20 2011 chrono.wu
 * removed!
 * .
 *
 * 12 16 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 12 14 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 09 21 2011 chrono.wu
 * removed!
 * .
 *
 * 08 19 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 07 26 2011 peter.wang
 * removed!
 * .
 *
 * 04 20 2011 chrono.wu
 * removed!
 * .
 *
 * 03 04 2011 chrono.wu
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
 *
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

#ifndef __idp_video_encode_h__
#define __idp_video_encode_h__

#include "drv_features_mdp.h"
#include "kal_general_types.h"
#include "idp_define.h"
#include <idp_core.h>

enum
{
  IDP_VIDEO_ENCODE_EXTMEM_START_ADDRESS = 1,
  IDP_VIDEO_ENCODE_EXTMEM_SIZE,
  IDP_VIDEO_ENCODE_IMAGE_SRC_WIDTH,
  IDP_VIDEO_ENCODE_IMAGE_SRC_HEIGHT,

  // display path settings
  IDP_VIDEO_ENCODE_DISPLAY_ROT_ANGLE,
  IDP_VIDEO_ENCODE_IMAGE_COLOR_FORMAT,
  IDP_VIDEO_ENCODE_DISPLAY_WIDTH,
  IDP_VIDEO_ENCODE_DISPLAY_HEIGHT,
  IDP_VIDEO_ENCODE_FRAME_BUFFER_ADDRESS1,
  IDP_VIDEO_ENCODE_FRAME_BUFFER_ADDRESS2,
  IDP_VIDEO_ENCODE_FRAME_BUFFER_ADDRESS3,
  IDP_VIDEO_ENCODE_ENABLE_PITCH,
  IDP_VIDEO_ENCODE_DISPLAY_PITCH_WIDTH,

  // video encode path settings
  IDP_VIDEO_ENCODE_ENCODE_WIDTH,
  IDP_VIDEO_ENCODE_ENCODE_HEIGHT,
  IDP_VIDEO_ENCODE_ENCODE_ROT_ANGLE,

  IDP_VIDEO_ENCODE_ENABLE_OVERLAY,
  IDP_VIDEO_ENCODE_SET_OVERLAY_PALETTE_SIZE_AND_ADDR,
  IDP_VIDEO_ENCODE_OVERLAY_PALETTE_MODE,
  IDP_VIDEO_ENCODE_OVERLAY_FRAME_SOURCE_KEY,
  IDP_VIDEO_ENCODE_OVERLAY_FRAME_WIDTH,
  IDP_VIDEO_ENCODE_OVERLAY_FRAME_HEIGHT,
  IDP_VIDEO_ENCODE_OVERLAY_FRAME_BUFFER_ADDRESS,

  IDP_VIDEO_ENCODE_FRAME_START_HISR_CB_ENABLE,
  IDP_VIDEO_ENCODE_PREVIEW_CROP_ENABLE,
  IDP_VIDEO_ENCODE_PREVIEW_CROP_WIDTH,
  IDP_VIDEO_ENCODE_PREVIEW_CROP_HEIGHT,

  IDP_VIDEO_ENCODE_UPDATE_TO_LCD,

  IDP_VIDEO_ENCODE_SENSOR_FPS_VIDEO_FPS, 

  IDP_VIDEO_ENCODE_LAST_MANDATORY_USER_CONFIG,
  // ***********************Mandatory parameter definition end****************************
  // The following region defines the optional parameters which will not be checked by idp_finish_read_user_config()

  // currently unused interfaces
  IDP_VIDEO_ENCODE_INTMEM_START_ADDRESS,
  IDP_VIDEO_ENCODE_INTMEM_SIZE,
  IDP_VIDEO_ENCODE_RESIZER_U_VALUE,
  IDP_VIDEO_ENCODE_RESIZER_D_VALUE,
  
  // This param is used for MATV chip MT5931 issue workaround: 
  // Delay trigger display timing from current frame done interrupt to next CRZ frame start interrupt
  IDP_VIDEO_ENCODE_ENABLE_TRIGGER_DISPLAY_DELAY_TO_FRAME_START,

  // This param is used for motion sensor encode rotation feature:
  // Specify encode rotation angle for MDP when encoding process start
  IDP_VIDEO_ENCODE_ENCODE_DYNAMIC_ROT_ANGLE,

  // MT6268 only
  IDP_VIDEO_ENCODE_FORCE_LCD_HW_TRIGGER,
  
#if defined(CONTOUR_IMPROVEMENT_MT6235) || defined(CONTOUR_IMPROVEMENT_MT6253)
  IDP_VIDEO_ENCODE_QUALITY_LEVEL,
#endif

  IDP_VIDEO_ENCODE_TEMP_BUFFER,

  //SOP of adding new parameter for this scenario
  //1. Add a new definition here
  //2. Add a corresponding variable in the config struct
  //3. Make sure adding the matching handler for this definition in the "read_user_config_hook" function
  //   In the switch case, default case would cause "ASSERT(0)"!!!!!
  //4. Make sure SET_BIT to variable of "read_user_config" in the "read_user_config_hook" function
  //5. If no use in some platforms, please make sure adding the SET_BIT in the init_config_hook function
  IDP_VIDEO_ENCODE_LAST_USER_CONFIG

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
/* under construction !*/
/* under construction !*/
#endif
};

enum
{
  IDP_VIDEO_ENCODE_QUERY_TYPE = 1,
  IDP_VIDEO_ENCODE_QUERY_ARG_PATH,
  IDP_VIDEO_ENCODE_QUERY_ARG_CLR_FMT,
  IDP_VIDEO_ENCODE_QUERY_ARG_DESIRED_ANGLE,  
  IDP_VIDEO_ENCODE_QUERY_RESULT,
  //deprecated
  IDP_VIDEO_ENCODE_QUERY_CURRENT_ENCODABLE_VIDEO_BUFFER_ADDR,
  IDP_VIDEO_ENCODE_QUERY_CURRENT_DISPLAYABLE_BUFFER_ADDR
};

enum
{
  IDP_VIDEO_ENCODE_SET_YUV_BUFFER_ADDR_1,
  IDP_VIDEO_ENCODE_SET_YUV_BUFFER_ADDR_2,
  IDP_VIDEO_ENCODE_SET_YUV_BUFFER_ADDR_1_2
};

enum idp_video_encode_error_code_t
{
  IDP_VIDEO_ENCODE_NO_ERROR,
  IDP_VIDEO_ENCODE_ERROR_CODE_NOT_ENOUGH_MEMORY,
  IDP_VIDEO_ENCODE_ERROR_CODE_HW_LIMITATION,
  IDP_VIDEO_ENCODE_ERROR_CODE_HW_IN_USE /**< Some HW engine needed in this path is in use. */
};
typedef enum idp_video_encode_error_code_t idp_video_encode_error_code_t;

extern kal_bool idp_video_encode_open_real(
  kal_uint32 * const key,
  char const * const filename,
  kal_uint32 const lineno);

extern kal_bool idp_video_encode_close(
  kal_uint32 const key);

extern kal_bool idp_video_encode_stop(
  kal_uint32 const key);

extern kal_bool idp_video_encode_start_intermedia_pipe(
  kal_uint32 const key);

extern kal_bool idp_video_encode_start_input(
  kal_uint32 const key);

extern kal_bool idp_video_encode_start_output(
  kal_uint32 const key);

extern kal_bool idp_video_encode_start_all(
  kal_uint32 const key);

extern kal_bool idp_video_encode_config(
  kal_uint32 const key,
  ...);

extern kal_bool idp_video_encode_configurable(
  kal_uint32 const key,
  ...);

extern kal_bool idp_video_encode_config_fast(
  kal_uint32 const key,
  kal_uint32 const para_type,
  kal_uint32 const para_value);

extern kal_bool idp_video_encode_query(
  kal_uint32 const key,
  ...);

extern kal_bool idp_video_encode_config_and_start(
  kal_uint32 const key,
  ...);

extern kal_bool idp_video_encode_is_busy(
  kal_uint32 const key,
  kal_bool * const busy);

extern kal_bool idp_video_encode_is_in_use(void);

#define idp_video_encode_open(key) idp_video_encode_open_real(key, __FILE__, __LINE__)

#endif
