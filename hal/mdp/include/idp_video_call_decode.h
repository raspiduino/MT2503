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
 * 02 17 2011 chrono.wu
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

#ifndef __idp_video_call_decode_h__
#define __idp_video_call_decode_h__

#include "kal_general_types.h"
#include <idp_core.h>

enum
{
    IDP_VIDEO_CALL_DECODE_EXTMEM_START_ADDRESS = 1 /**< external memory start address. @remakr not in use in MT6268. */
  , IDP_VIDEO_CALL_DECODE_EXTMEM_SIZE /**< external memory size in bytes. @remakr not in use in MT6268. */
  
  , IDP_VIDEO_CALL_DECODE_DECODE_SRC_WIDTH
  , IDP_VIDEO_CALL_DECODE_DECODE_SRC_HEIGHT
  , IDP_VIDEO_CALL_DECODE_DECODE_TAR_WIDTH
  , IDP_VIDEO_CALL_DECODE_DECODE_TAR_HEIGHT
  
  , IDP_VIDEO_CALL_DECODE_DECODE_ROT_ANGLE
  , IDP_VIDEO_CALL_DECODE_TRIGGER_LCD
  
  , IDP_VIDEO_CALL_DECODE_DECODE_SRC_Y_BUFFER_ADDRESS
  , IDP_VIDEO_CALL_DECODE_DECODE_SRC_U_BUFFER_ADDRESS
  , IDP_VIDEO_CALL_DECODE_DECODE_SRC_V_BUFFER_ADDRESS
  , IDP_VIDEO_CALL_DECODE_DECODE_IMAGE_DATA_FORMAT
  , IDP_VIDEO_CALL_DECODE_FRAME_BUFFER_ADDRESS
  , IDP_VIDEO_CALL_DECODE_FRAME_BUFFER_ADDRESS_2 /* [vt_decode_double_buffering] */
  , IDP_VIDEO_CALL_DECODE_DECODE_ENABLE_CLIP /**< destination clip. */
  , IDP_VIDEO_CALL_DECODE_DECODE_CLIP_LEFT /**< destination clip left. */
  , IDP_VIDEO_CALL_DECODE_DECODE_CLIP_RIGHT /**< destination clip right. */
  , IDP_VIDEO_CALL_DECODE_DECODE_CLIP_TOP /**< destination clip top. */
  , IDP_VIDEO_CALL_DECODE_DECODE_CLIP_BOTTOM /**< destination clip bottom. */
  
  , IDP_VIDEO_CALL_DECODE_DONE_CB /**< arg type: idp_hisr_intr_cb_t */
  , IDP_VIDEO_CALL_DECODE_DONE_CB_PARAM /**< arg type: idp_hisr_intr_cb_param_t */

  , IDP_VIDEO_CALL_DECODE_LAST_MANDATORY_USER_CONFIG
  // ***********************Mandatory parameter definition end****************************
  // The following region defines the optional parameters which will not be checked by idp_finish_read_user_config()

  // currently unused interfaces
  , IDP_VIDEO_CALL_DECODE_INTMEM_START_ADDRESS
  , IDP_VIDEO_CALL_DECODE_INTMEM_SIZE

  //MT6268 only
  , IDP_VIDEO_CALL_DECODE_DECODE_SRC_FMT_4X4 /**< @deprecated This param is actually not in use even in MT6268 */
  , IDP_VIDEO_CALL_DECODE_DECODE_MP4DEBLK_QUANT_BUF /**< MP4 deblock quantization buffer in internal memory for HW video only. This param is frame-based. */

  //SOP of adding new parameter for this scenario
  //1. Add a new definition here
  //2. Add a corresponding variable in the config struct 
  //3. Make sure adding the matching handler for this definition in the "read_user_config_hook" function 
  //   In the switch case, default case would cause "ASSERT(0)"!!!!!
  //4. Make sure SET_BIT to variable of "read_user_config" in the "read_user_config_hook" function 
  //5. If no use in some platforms, please make sure adding the SET_BIT in the init_config_hook function
  , IDP_VIDEO_CALL_DECODE_LAST_USER_CONFIG
};

extern kal_bool idp_video_call_decode_open_real(             
  kal_uint32 * const key,                           
  char const * const filename,                      
  kal_uint32 const lineno);                         

extern kal_bool idp_video_call_decode_close(                 
  kal_uint32 const key);                            

extern kal_bool idp_video_call_decode_stop(                 
  kal_uint32 const key);                            

extern kal_bool idp_video_call_decode_start_intermedia_pipe( 
  kal_uint32 const key);                            

extern kal_bool idp_video_call_decode_start_input(           
  kal_uint32 const key);                            

extern kal_bool idp_video_call_decode_start_output(          
  kal_uint32 const key);                            

extern kal_bool idp_video_call_decode_start_all(             
  kal_uint32 const key);                            

extern kal_bool idp_video_call_decode_config(
  kal_uint32 const key,
  ...);

extern kal_bool idp_video_call_decode_configurable(
  kal_uint32 const key,
  ...);

extern kal_bool idp_video_call_decode_config_fast(
  kal_uint32 const key,
  kal_uint32 const para_type,
  kal_uint32 const para_value);

extern kal_bool idp_video_call_decode_query(
  kal_uint32 const key,
  ...);

extern kal_bool idp_video_call_decode_config_and_start(
  kal_uint32 const key,
  ...);

extern kal_bool idp_video_call_decode_is_busy(               
  kal_uint32 const key,                             
  kal_bool * const busy);

extern kal_bool idp_video_call_decode_is_in_use(void);

#define idp_video_call_decode_open(key) idp_video_call_decode_open_real(key, __FILE__, __LINE__)

#endif
