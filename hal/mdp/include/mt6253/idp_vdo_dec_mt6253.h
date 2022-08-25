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
 *   idp_vdo_dec.h
 *
 * Project:
 * --------
 *	 Maui
 *
 * Description:
 * ------------
 *   This file provides interface for video decode to display YUV420 frames
 *   onto LCD.
 *   This module controls MT6253 image resizer and LCD for video frame display.
 *   This is only an extension to legacy IDP design rather than MT6238 series
 *   design.
 *
 *
 *    The calling sequence:
 *    1. idp_video_decode_open
 *
 *    2. idp_video_decode_config
 *
 *    3. idp_video_decode_config_yuv_src_address
 *
 *    4. idp_video_decode_start
 *
 *    5. HISR callback
 *
 *    6. idp_video_decode_stop
 *
 *    repeat 3 to 6 for every YUV420 frame...
 *
 *    7. idp_video_decode_close
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
 * 08 18 2011 peter.wang
 * removed!
 * .
 *
 * 07 26 2011 peter.wang
 * removed!
 * .
 *
 * 05 03 2011 peter.wang
 * removed!
 * .
 *
 * 04 22 2011 peter.wang
 * removed!
 * .
 *
 * 12 24 2010 cm.huang
 * removed!
 * .
 *
 * 12 03 2010 cm.huang
 * removed!
 * .
 *
 * 11 26 2010 cm.huang
 * removed!
 * .
 *
 * 11 23 2010 cm.huang
 * removed!
 * .
 *
 * 11 17 2010 cm.huang
 * NULL
 * .
 *
 * 11 13 2010 cm.huang
 * NULL
 * .
 *
 * 10 20 2010 cm.huang
 * NULL
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_vdo_dec_6253_h__
#define __idp_vdo_dec_6253_h__

#ifdef DRV_IDP_6253_SERIES

#include <lcd_if.h>

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
  IDP_VIDEO_DECODE_ERROR_CODE_NOT_ENOUGH_MEMORY
};
typedef enum idp_video_decode_error_code_t idp_video_decode_error_code_t;


#define IDP_VIDEO_DECODE_INT_MEM_MIN_SIZE 0 /**< sync this with IDP_VR_MAXIMUM_RESZ_WM_SIZE in resizer_6253t.h */
//// ctfang: directly obtained from display internal memory...


struct idp_vdo_dec_struct
{
    kal_uint32      intmem_start_address; /**< Must provide internal memory for video playback. */
    kal_uint32      intmem_size; /**< The size should be no less than IDP_VIDEO_DECODE_INT_MEM_MIN_SIZE */
    kal_uint32      extmem_start_address; /**< Not in use for now. */
    kal_uint32      extmem_size; /**< Not in use for now. */

#if defined(CONTOUR_IMPROVEMENT_MT6253)
    kal_uint32      reserve_time_to_mdp; /**< MDP can execute time(ms) every frame according to resolution & bit rate & frame rate */
    kal_uint32      video_frame_rate;   /**< Video frame rate */
#endif 

    kal_uint16      source_width; /**< video frame width w/ padding. The YUV frame buffer shall align to this size. */
    kal_uint16      source_height; /**< video frame height w/ padding. The YUV frame buffer shall align to this size. */

    kal_uint16      video_frame_real_width; /**< video frame real width w/o padding, shall be in the range [source_width-15, source_width] */
    kal_uint16      video_frame_real_height; /**< video frame real height w/o padding, shall be in the range [source_height-15, source_height] */

    kal_uint16      target_width; /**< resize output width, resized from video_frame_real_width */
    kal_uint16      target_height; /**< resize output height, resized from video_frame_real_height */

    kal_bool        target_clip; /**< KAL_TRUE to enable destination (target) clipping, clipping after resizing */
    kal_uint16      target_clip_top; /**< clip top after resize, restriction: bottom-top+1 must be even */
    kal_uint16      target_clip_bottom; /**< clip bottom after resize, restriction: bottom-top+1 must be even */
    kal_uint16      target_clip_left; /**< clip left after resize, restriction: bottom-top+1 must be even */
    kal_uint16      target_clip_right; /**< clip right after resize, restriction: bottom-top+1 must be even */

    kal_bool        pitch; /**< KAL_TRUE to enable pitch function. */
    kal_uint16      pitch_width; /** pitch width in pixel, must be even, this is a MT6253 HW limitation. */

    kal_uint32      out_frame_buffer_addr_1; /**< RGB565 frame buffer 1 for display */
    kal_uint32      out_frame_buffer_1_size;  /**< RGB565 frame buffer 1 size for display */
    kal_uint32      out_frame_buffer_addr_2; /**< RGB565 frame buffer 2 for display */
    kal_uint32      out_frame_buffer_2_size;  /**< RGB565 frame buffer 2 size for display */

    kal_bool        enable_trigger_lcd;

    kal_bool        enable_cb;
    void            (*frame_start_cb)(void*);
    void            (*frame_done_cb)(void*);

    lcd_frame_update_struct *lcd_data;
};
typedef struct idp_vdo_dec_struct idp_vdo_dec_t;

extern kal_bool idp_video_decode_open(
  kal_uint32 * const key);

extern kal_bool idp_video_decode_close(
  kal_uint32 const key);

extern kal_bool idp_video_decode_stop(
  kal_uint32 const key);

extern kal_bool idp_video_decode_start(
  kal_uint32 const key);

extern kal_bool idp_video_decode_config(
  kal_uint32 const key,
  idp_vdo_dec_t * const vdo_dec_cfg);

extern kal_bool idp_video_decode_config_yuv_src_address(
  kal_uint32 const key,
  kal_uint32 const y_address,
  kal_uint32 const u_address,
  kal_uint32 const v_address);

extern kal_bool idp_video_decode_query(
  kal_uint32 const key,
  ...);

extern kal_bool idp_video_decode_is_busy(
  kal_uint32 const key,
  kal_bool * const busy);

extern kal_bool idp_video_decode_is_in_use(void);

#if defined(CONTOUR_IMPROVEMENT_MT6253)
extern kal_bool idp_video_decode_notify_buffer_consumption(
	kal_uint32 const consumpt_percentage);
#endif 


#endif // DRV_IDP_6253_SERIES

#endif // __idp_vdo_dec_6253_h__
