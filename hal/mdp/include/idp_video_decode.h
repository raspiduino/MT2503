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
 * 03 24 2014 chrono.wu
 * removed!
 * .
 *
 * 01 20 2012 chelun.tsai
 * removed!
 * .
 *
 * 01 10 2012 chrono.wu
 * removed!
 * .
 *
 * 11 29 2011 chelun.tsai
 * removed!
 * .
 *
 * 11 25 2011 chelun.tsai
 * removed!
 * .
 *
 * 11 25 2011 chelun.tsai
 * removed!
 * .
 *
 * 10 14 2011 chelun.tsai
 * removed!
 * .
 *
 * 09 23 2011 chelun.tsai
 * removed!
 * .
 *
 * 08 25 2011 chelun.tsai
 * removed!
 * .
 *
 * 08 18 2011 chrono.wu
 * removed!
 * .
 *
 * 08 05 2011 chrono.wu
 * removed!
 * .
 *
 * 08 04 2011 chelun.tsai
 * removed!
 * .
 *
 * 07 28 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 07 27 2011 chelun.tsai
 * removed!
 * .
 *
 * 07 27 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 05 25 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 04 13 2011 ct.fang
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
 * 11 13 2010 cm.huang
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

#ifndef __idp_video_decode_h__
#define __idp_video_decode_h__

#include "drv_features_mdp.h"
#include "kal_general_types.h"
#include <idp_core.h>

typedef enum
{
  IDP_VIDEO_DECODE_EFFECT_NONE = 0,
  IDP_VIDEO_DECODE_EFFECT_GRAYSCALE,
  IDP_VIDEO_DECODE_EFFECT_SEPIA,
  IDP_VIDEO_DECODE_EFFECT_SEPIAGREEN,
  IDP_VIDEO_DECODE_EFFECT_SEPIABLUE,
  IDP_VIDEO_DECODE_EFFECT_COLORINV,
  IDP_VIDEO_DECODE_EFFECT_GRAYINV
} idp_video_decode_effect_enum_t;

#if defined(MDP_SUPPORT_VP_EMI_BW_SWITCH)
typedef enum
{
  IDP_VIDEO_DECODE_EMI_BW_MMI,
  IDP_VIDEO_DECODE_EMI_BW_VP,
  IDP_VIDEO_DECODE_EMI_BW_VLW,
  IDP_VIDEO_DECODE_EMI_BW_VP_HVGA,
  IDP_VIDEO_DECODE_EMI_BW_VLW_HVGA
} 
idp_video_decode_emi_bw_switch_enum_t;
#endif //#if defined(MDP_SUPPORT_VP_EMI_BW_SWITCH)

enum
{
  IDP_VIDEO_DECODE_EXTMEM_START_ADDRESS = 1,
  IDP_VIDEO_DECODE_EXTMEM_SIZE,
  
  IDP_VIDEO_DECODE_SRC_WIDTH,
  IDP_VIDEO_DECODE_SRC_HEIGHT,
  IDP_VIDEO_DECODE_TARGET_WIDTH,
  IDP_VIDEO_DECODE_TARGET_HEIGHT,
  
  IDP_VIDEO_DECODE_ENABLE_CLIP,
  IDP_VIDEO_DECODE_CLIP_LEFT,
  IDP_VIDEO_DECODE_CLIP_RIGHT,
  IDP_VIDEO_DECODE_CLIP_TOP,
  IDP_VIDEO_DECODE_CLIP_BOTTOM,
  
  IDP_VIDEO_DECODE_VIDEO_Y_BUFFER_ADDRESS,
  IDP_VIDEO_DECODE_VIDEO_U_BUFFER_ADDRESS,
  IDP_VIDEO_DECODE_VIDEO_V_BUFFER_ADDRESS,
  
  IDP_VIDEO_DECODE_CONTRAST_LEVEL,   
  IDP_VIDEO_DECODE_BRIGHTNESS_LEVEL, 
  
  IDP_VIDEO_DECODE_ENABLE_PITCH,      
  IDP_VIDEO_DECODE_IMAGE_DATA_FORMAT,    
  IDP_VIDEO_DECODE_BG_IMAGE_WIDTH,   
  
  IDP_VIDEO_DECODE_FRAME_BUFFER_ADDRESS,
  IDP_VIDEO_DECODE_FRAME_BUFFER_ADDRESS_2,
  
  IDP_VIDEO_DECODE_ROT_ANGLE,

  IDP_VIDEO_DECODE_TRIGGER_LCD,

  IDP_VIDEO_DECODE_DONE_CB, 
  IDP_VIDEO_DECODE_DONE_CB_PARAM, 

  IDP_VIDEO_DECODE_DST_CLIP, /**< kal_bool enable, kal_uint32 left, kal_uint32 top, kal_uint32 right, kal_uint32 bottom */

  IDP_VIDEO_DECODE_SOURCE_DATA_FORMAT,

  IDP_VIDEO_DECODE_LAST_MANDATORY_USER_CONFIG,

  // ***********************Mandatory parameter definition end****************************
  // The following region defines the optional parameters which will not be checked by idp_finish_read_user_config()

  // currently unused interfaces
  IDP_VIDEO_DECODE_INTMEM_START_ADDRESS,
  IDP_VIDEO_DECODE_INTMEM_SIZE,
  IDP_VIDEO_DECODE_TARGET_WIDTH_FOR_TVOUT,
  IDP_VIDEO_DECODE_TARGET_HEIGHT_FOR_TVOUT,
  IDP_VIDEO_DECODE_RESIZER_U_VALUE,
  IDP_VIDEO_DECODE_RESIZER_V_VALUE,

  // This param is used for MDP power on/off control
  IDP_VIDEO_DECODE_POWER_CTRL,

  // This param is used for MDP emi bandwidth switch
  IDP_VIDEO_DECODE_EMI_BW_SWITCH,

  // dither function enable interface(chip dependent)
  IDP_VIDEO_DECODE_DITHER_ENABLE,  

  // MT6268 only
  IDP_VIDEO_DECODE_FORCE_LCD_HW_TRIGGER,
  IDP_VIDEO_DECODE_SRC_FMT_4X4,  
  IDP_VIDEO_DECODE_ENABLE_MP4DEBLK,
  IDP_VIDEO_DECODE_MP4DEBLK_QUANT_BUF,
  
  //SOP of adding new parameter for this scenario
  //1. Add a new definition here
  //2. Add a corresponding variable in the config struct 
  //3. Make sure adding the matching handler for this definition in the "read_user_config_hook" function 
  //   In the switch case, default case would cause "ASSERT(0)"!!!!!
  //4. Make sure SET_BIT to variable of "read_user_config" in the "read_user_config_hook" function 
  //5. If no use in some platforms, please make sure adding the SET_BIT in the init_config_hook function  
#if defined(CONTOUR_IMPROVEMENT_MT6235)
  IDP_VIDEO_DECODE_VIDEO_FRAME_RATE,
  IDP_VIDEO_DECODE_RESERVE_TIME_TO_MDP,
#endif
#if defined(MT6268T) || defined(MT6268) || defined(MT6268A) || defined(MT6268B) || defined(MT6268H)
    // DC Parameter will be used by MT6268, Please don't remove it. Thanks a lot!!
    // These parameter will be used by pitch.
    IDP_VIDEO_DECODE_DC_RDMA_ADDR,
    IDP_VIDEO_DECODE_DC_TARGET_WIDTH,
    IDP_VIDEO_DECODE_DC_TARGET_HEIGHT,
#endif

  IDP_VIDEO_DECODE_LAST_USER_CONFIG,
};

enum
{
  IDP_VIDEO_DECODE_QUERY_CURRENT_DECODABLE_VIDEO_YUV_BUFFER_ADDR = 1,
  IDP_VIDEO_DECODE_QUERY_ERROR_CODE,
  IDP_VIDEO_DECODE_QUERY_AND_LOCK_IDP_DRIVER,
  IDP_VIDEO_DECODE_QUERY_AND_UNLOCK_IDP_DRIVER
};

enum idp_video_decode_error_code_t
{
  IDP_VIDEO_DECODE_NO_ERROR,
  IDP_VIDEO_DECODE_ERROR_CODE_SRC_WIDTH_TOO_LARGE,
  IDP_VIDEO_DECODE_ERROR_CODE_SRC_WIDTH_TOO_SMALL,
  IDP_VIDEO_DECODE_ERROR_CODE_SRC_HEIGHT_TOO_LARGE,
  IDP_VIDEO_DECODE_ERROR_CODE_SRC_HEIGHT_TOO_SMALL,
  IDP_VIDEO_DECODE_ERROR_CODE_TAR_WIDTH_TOO_LARGE,
  IDP_VIDEO_DECODE_ERROR_CODE_TAR_WIDTH_TOO_SMALL,
  IDP_VIDEO_DECODE_ERROR_CODE_TAR_HEIGHT_TOO_LARGE,
  IDP_VIDEO_DECODE_ERROR_CODE_TAR_HEIGHT_TOO_SMALL,
  IDP_VIDEO_DECODE_ERROR_CODE_HW_IN_USE,
  IDP_VIDEO_DECODE_ERROR_CODE_NOT_ENOUGH_MEMORY
};
typedef enum idp_video_decode_error_code_t idp_video_decode_error_code_t;

extern kal_bool idp_video_decode_open_real(             
  kal_uint32 * const key,                           
  char const * const filename,                      
  kal_uint32 const lineno);                         

extern kal_bool idp_video_decode_close(                 
  kal_uint32 const key);                            

extern kal_bool idp_video_decode_stop(                 
  kal_uint32 const key);                            

extern kal_bool idp_video_decode_start_intermedia_pipe( 
  kal_uint32 const key);                            

extern kal_bool idp_video_decode_start_input(           
  kal_uint32 const key);                            

extern kal_bool idp_video_decode_start_output(          
  kal_uint32 const key);                            

extern kal_bool idp_video_decode_start_all(             
  kal_uint32 const key);                            

extern kal_bool idp_video_decode_config(
  kal_uint32 const key,
  ...);

extern kal_bool idp_video_decode_configurable(
  kal_uint32 const key,
  ...);

extern kal_bool idp_video_decode_config_fast(
  kal_uint32 const key,
  kal_uint32 const para_type,
  kal_uint32 const para_value);

extern kal_bool idp_video_decode_query(
  kal_uint32 const key,
  ...);

extern kal_bool idp_video_decode_config_and_start(
  kal_uint32 const key,
  ...);

extern kal_bool idp_video_decode_is_busy(               
  kal_uint32 const key,                             
  kal_bool * const busy);

extern kal_bool idp_video_decode_is_in_use(void);

/* 
 * for MT6256E2 mjpg decode only, and only support on MT6256E2 while mjpeg decode feature is on.  
 * The 2 APIs must be called before idp_video_decode_open()
 * For mjpeg decode, call idp_video_decode_mjpg_mode_enable()
 * For normag video decode, call idp_video_decode_mjpg_mode_disable()
 */
#if defined(DRV_IDP_MT6256_E2_SERIES) && defined(MJPG_DECODE)
extern void idp_video_decode_mjpg_mode_enable(void);

extern void idp_video_decode_mjpg_mode_disable(void);
#endif

#define idp_video_decode_open(key) idp_video_decode_open_real(key, __FILE__, __LINE__)

#endif
