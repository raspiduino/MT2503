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
 * 08 19 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 05 16 2011 chrono.wu
 * removed!
 * .
 *
 * 05 14 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 01 20 2011 chrono.wu
 * removed!
 * .
 *
 * 12 17 2010 cm.huang
 * removed!
 * .
 *
 * 12 03 2010 hung-wen.hsieh
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
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_video_call_encode_h__
#define __idp_video_call_encode_h__

#include "kal_general_types.h"
#include <idp_core.h>

enum
{
    IDP_VIDEO_CALL_ENCODE_EXTMEM_START_ADDRESS = 1
  , IDP_VIDEO_CALL_ENCODE_EXTMEM_SIZE
  
  , IDP_VIDEO_CALL_ENCODE_SRC_WIDTH
  , IDP_VIDEO_CALL_ENCODE_SRC_HEIGHT
  , IDP_VIDEO_CALL_ENCODE_ENCODE_WIDTH
  , IDP_VIDEO_CALL_ENCODE_ENCODE_HEIGHT
  , IDP_VIDEO_CALL_ENCODE_DISPLAY_WIDTH
  , IDP_VIDEO_CALL_ENCODE_DISPLAY_HEIGHT
  , IDP_VIDEO_CALL_ENCODE_ENCODE_CROP_ENABLE
  , IDP_VIDEO_CALL_ENCODE_ENCODE_CROP_WIDTH
  , IDP_VIDEO_CALL_ENCODE_ENCODE_CROP_HEIGHT

  , IDP_VIDEO_CALL_ENCODE_DISPLAY_COLOR_FORMAT /**< display color format, parameter type: 
                                                    img_color_fmt_rgb_enum_t or img_color_fmt_yuv_enum_t. 
                                                    Only single plane color format is allowed. 
                                                    Added for MT6236 MDP driver */

  , IDP_VIDEO_CALL_ENCODE_DISPLAY_BUFFER_ADDRESS_1
  , IDP_VIDEO_CALL_ENCODE_DISPLAY_BUFFER_ADDRESS_2
  , IDP_VIDEO_CALL_ENCODE_DISPLAY_BUFFER_ADDRESS_3
    
  , IDP_VIDEO_CALL_ENCODE_ENABLE_OVERLAY
  , IDP_VIDEO_CALL_ENCODE_SET_OVERLAY_PALETTE_SIZE_AND_ADDR
  , IDP_VIDEO_CALL_ENCODE_OVERLAY_PALETTE_MODE
  , IDP_VIDEO_CALL_ENCODE_OVERLAY_FRAME_SOURCE_KEY
  , IDP_VIDEO_CALL_ENCODE_OVERLAY_FRAME_WIDTH
  , IDP_VIDEO_CALL_ENCODE_OVERLAY_FRAME_HEIGHT
  , IDP_VIDEO_CALL_ENCODE_OVERLAY_FRAME_BUFFER_ADDRESS
  
  , IDP_VIDEO_CALL_ENCODE_LCD_UPDATE /**< Enable update to LCD. */

  , IDP_VIDEO_CALL_ENCODE_FRAME_START_HISR_CB_ENABLE /**< Enable callback when CRZ frame start interrupt or not. */

  , IDP_VIDEO_CALL_ENCODE_DISPLAY_ROTATION_ANGLE /**< Specify the display rotation angle, must use enumeration defined in img_rot_angle_enum_t. */
  , IDP_VIDEO_CALL_ENCODE_VIDEO_FRAME_ROTATION_ANGLE /**< Specify the video frame output rotation angle, must use enumeration defined in img_rot_angle_enum_t. */
  , IDP_VIDEO_CALL_ENCODE_SENSOR_FPS_VIDEO_FPS /**< kal_uint32 sensor_fps_x_10, kal_uint32 video_fps_x_10, 
                                                    This parameter has two argument, sensor_fps_x_10 is sensor FPS * 10, 
                                                    video_fps_x_10 is video frame output FPS * 10, 
                                                    This parameter is optional, if not set, IDP video call encode will not drop 
                                                    video frame output. */

  , IDP_VIDEO_CALL_ENCODE_LAST_MANDATORY_USER_CONFIG
  // ***********************Mandatory parameter definition end****************************
  // The following region defines the optional parameters which will not be checked by idp_finish_read_user_config()

  // currently unused interfaces
  , IDP_VIDEO_CALL_ENCODE_INTMEM_START_ADDRESS
  , IDP_VIDEO_CALL_ENCODE_INTMEM_SIZE
  , IDP_VIDEO_CALL_ENCODE_RESIZER_U_VALUE
  , IDP_VIDEO_CALL_ENCODE_RESIZER_D_VALUE
  , IDP_VIDEO_CALL_ENCODE_ENABLE_VIDEO_ENCODE_CB

  //SOP of adding new parameter for this scenario
  //1. Add a new definition here
  //2. Add a corresponding variable in the config struct 
  //3. Make sure adding the matching handler for this definition in the "read_user_config_hook" function 
  //   In the switch case, default case would cause "ASSERT(0)"!!!!!
  //4. Make sure SET_BIT to variable of "read_user_config" in the "read_user_config_hook" function 
  //5. If no use in some platforms, please make sure adding the SET_BIT in the init_config_hook function  
  
  , IDP_VIDEO_CALL_ENCODE_LAST_USER_CONFIG

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
#endif

};

enum
{
	IDP_VIDEO_CALL_ENCODE_QUERY_TYPE = 1,
	IDP_VIDEO_CALL_ENCODE_QUERY_ARG_PATH,
	IDP_VIDEO_CALL_ENCODE_QUERY_ARG_CLR_FMT,
	IDP_VIDEO_CALL_ENCODE_QUERY_ARG_DESIRED_ANGLE,  
	IDP_VIDEO_CALL_ENCODE_QUERY_RESULT,
	//deprecated
  IDP_VIDEO_CALL_ENCODE_QUERY_CURRENT_ENCODABLE_VIDEO_BUFFER_ADDR = 1
};

#if defined(DRV_IDP_SUPPORT)
#if defined(__MTK_TARGET__)

extern kal_uint32 _video_call_decode_idp_key;
extern PFN_TRIGGER_VIDEO_CALL_DECODE_PATH pf_trigger_video_call_decode_path; 
extern PFN_TRIGGER_VIDEO_CALL_DECODE_PATH pf_trigger_video_call_encode_display_path; 

#endif
#endif


extern kal_bool idp_video_call_encode_open_real(             
  kal_uint32 * const key,                           
  char const * const filename,                      
  kal_uint32 const lineno);                         

extern kal_bool idp_video_call_encode_close(                 
  kal_uint32 const key);                            

extern kal_bool idp_video_call_encode_stop(                 
  kal_uint32 const key);                            

extern kal_bool idp_video_call_encode_start_intermedia_pipe( 
  kal_uint32 const key);                            

extern kal_bool idp_video_call_encode_start_input(           
  kal_uint32 const key);                            

extern kal_bool idp_video_call_encode_start_output(          
  kal_uint32 const key);                            

extern kal_bool idp_video_call_encode_start_all(             
  kal_uint32 const key);                            

extern kal_bool idp_video_call_encode_config(
  kal_uint32 const key,
  ...);

extern kal_bool idp_video_call_encode_configurable(
  kal_uint32 const key,
  ...);

extern kal_bool idp_video_call_encode_config_fast(
  kal_uint32 const key,
  kal_uint32 const para_type,
  kal_uint32 const para_value);

extern kal_bool idp_video_call_encode_query(
  kal_uint32 const key,
  ...);

extern kal_bool idp_video_call_encode_config_and_start(
  kal_uint32 const key,
  ...);

extern kal_bool idp_video_call_encode_is_busy(               
  kal_uint32 const key,                             
  kal_bool * const busy);

extern kal_bool idp_video_call_encode_is_in_use(void);

#define idp_video_call_encode_open(key) idp_video_call_encode_open_real(key, __FILE__, __LINE__)

#endif  // #ifndef __idp_video_call_encode_h__

