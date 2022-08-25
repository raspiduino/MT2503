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
 *    va2_comp_video_renderer.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    OpenMAX-like Video Renderer of Video Architecture V2.
 *    For external usage, renderer user.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 ****************************************************************************/
#ifndef __VA2_COMP_VIDEO_RENDERER_H__
#define __VA2_COMP_VIDEO_RENDERER_H__

#ifdef __VIDEO_ARCHI_V2__
/// \defgroup va2_comp_video_renderer
/// \ingroup va2
/// @{
/// \page parameters Parameters
/// VA2 Video Renderer Component accepts the following parameters defined in 
/// VIDEO_PARAM_TYPE_T in video_types_v2.h: 
/// #VIDEO_PARAM_RENDERER_BYPASS\n
///   - arg type: kal_bool*, default KAL_FALSE, if KAL_TRUE, Video Renderer does not renderer when in RUN state.
/// #VIDEO_PARAM_RENDERER_DST_COLOR_FORMAT\n
///   - arg type: VA2_VIDEO_RENDERER_COLOR_FORMAT_T*
/// #VIDEO_PARAM_RENDERER_DST_FB_ADDR\n
///   - arg type: va2_video_renderer_dst_fb_t*
/// #VIDEO_PARAM_RENDERER_DST_FB_SIZE\n
///   - arg type: VA2_FRAME_SIZE_T*
/// #VIDEO_PARAM_RENDERER_TRIGGER_DISPLAY\n
///   - arg type: kal_bool*
/// #VIDEO_PARAM_RENDERER_DISPLAY_SURFACE\n
///   - arg type: va2_video_renderer_display_surface_t* 
/// #VIDEO_PARAM_RENDERER_SEMI_AUTO_RENDER_MODE\n
///   - arg type: VA2_VIDEO_RENDERER_RENDER_MODE_T*
/// #VIDEO_PARAM_RENDERER_KEEP_CURR_PTR\n
///   - arg type: kal_bool*
/// #VIDEO_PARAM_RENDERER_RENDER_DISPLAY_BUFFER
///   - arg type: kal_uint32* This is a special function which commands video renderer to render in non-RUN state.
/// Parameters cannot be set while the component is in RUN state.

/// \page configs Configs
/// VA2 Video Renderer Component accepts the following configs defined in 
/// VIDEO_PARAM_TYPE_T in video_types_v2.h: 
/// #VIDEO_CONFIG_RENDERER_SRC_FB_ADDR
///   - arg type: VA2_FRAME_BUFFER_ADDRESS_T*
/// #VIDEO_CONFIG_RENDERER_SRC_COLOR_FORMAT
///   - arg type: VA2_VIDEO_RENDERER_COLOR_FORMAT_T*
/// #VIDEO_CONFIG_RENDERER_SRC_SIZE
///   - arg type: VA2_FRAME_SIZE_T*
/// #VIDEO_CONFIG_RENDERER_SRC_CLIP
///   - arg type: VA2_CLIP_WINDOW_T*
/// #VIDEO_CONFIG_RENDERER_RESIZE_DST_SIZE
///   - arg type: VA2_FRAME_SIZE_T*
/// #VIDEO_CONFIG_RENDERER_DST_CLIP
///   - arg type: VA2_CLIP_WINDOW_T*
/// #VIDEO_CONFIG_RENDERER_ROTATE_FLIP
///   - arg type: va2_video_renderer_rotate_flip_t*
/// #VIDEO_CONFIG_RENDERER_DST_FB_START_ADDR
///   - arg type: va2_video_renderer_dst_fb_t*
/// #VIDEO_CONFIG_RENDERER_POST_PROCESS
///   - arg type: va2_video_renderer_post_process_config_t*
/// #VIDEO_CONFIG_RENDERER_STATUS
///   - arg type: VIDEO_STATE_TYPE_T*, cannot be set
/// Configs can be set while component in RUN state.

/****************************************************************************
 * include directives
 ****************************************************************************/
#include "kal_public_api.h"
#include "video_types_v2.h"
#include "video_comm_component_v2.h"
#include "va2_util_buffer_header_queue.h"
#include "lcd_if.h" // TODO: consider this!

/****************************************************************************
 * type definitions -- external use
 ****************************************************************************/
#define VA2_COMP_VIDEO_RENDERER_SUPPORTED KAL_TRUE

typedef enum
{
    VIDEO_RENDERER_GENERAL /**< This is not allowed to be used to get a Video Renderer handle. */
  , VIDEO_RENDERER_VIDEO_PLAYBACK /**< Used to denote the type of video renderer instance for video playback. */
  , VIDEO_RENDERER_VIDEO_TELEPHONY /**< Used to denote the type of video renderer instance for video telephony playback. */
  , VIDEO_RENDERER_VIDEO_THUMBNAIL /**<Used to denote the type of video renderer instance for video playback with no extra display buffers. */  
  , VIDEO_RENDERER_MJPG_THUMBNAIL  /**< Used to denote the type of mjpg renderer instance for video playback with no extra display buffers. */
  , VIDEO_RENDERER_MJPG_PLAYBACK   /**< Used to denote the type of mjpg renderer instance for video playback. */
  , VIDEO_RENDERER_VIDEO_SUBTITLE_PLAYBACK /**< Used to denote the type of video renderer instance for video playback with subtitle support. */
  , VIDEO_RENDERER_MJPG_SUBTITLE_PLAYBACK /**< Used to denote the type of mjpg renderer instance for video playback with subtitle support. */
} VA2_VIDEO_RENDERER_TYPE_T;


/****************************************************************************
 * type definitions -- external use
 ****************************************************************************/

typedef enum 
{
    VIDEO_RENDERER_RENDER_MODE_FULL_CONTROL /**< Default value. */
  , VIDEO_RENDERER_RENDER_MODE_TOUCH_WINDOW_FROM_INSIDE
  , VIDEO_RENDERER_RENDER_MODE_TOUCH_WINDOW_FROM_OUTSIDE
  , VIDEO_RENDERER_RENDER_MODE_STRETCH_TO_WINDOW
} VA2_VIDEO_RENDERER_RENDER_MODE_T;

// enum to describe 3D anaglyph mode 
typedef enum 
{
    VIDEO_RENDERER_3D_MODE_NONE /**< Default value, 2D */
  , VIDEO_RENDERER_3D_MODE_SIDE_BY_SIDE /**< 2 frames are locate on left & right of the source image */
  , VIDEO_RENDERER_3D_MODE_TOP_DOWN /**< 2 frames are locate on top & down of the source image */
} VA2_VIDEO_RENDERER_3D_MODE_T;

typedef struct 
{
  kal_bool  b_brightness; /**< KAL_TRUE to enable or default value will be used. */
  kal_uint8 u1_brightness;
  kal_bool  b_contrast; /**< KAL_TRUE to enable or default value will be used. */
  kal_uint8 u1_contrast;
} va2_video_renderer_post_process_config_t;

typedef struct 
{
  kal_uint16  u2_cw_rotate_angle; /**< CW. 0, 90, 180, 270 only. Default 0. */
  kal_bool    b_flip; /**< KAL_TRUE to enable flipping. Default FALSE. */
} va2_video_renderer_rotate_flip_t;

typedef struct 
{
  VA2_FRAME_BUFFER_ADDRESS_T  r_fb_addr; /**< fb address(es). */
  kal_uint16                  u2_index; /**< buffer index. */
} va2_video_renderer_dst_fb_t;

typedef struct
{
  lcd_frame_update_struct     r_mtk_lcd_config; /**< lcd config. */
  kal_uint32                  dspl_dev_handle; /**< Display Device handle */
  kal_uint32                  dspl_ctx_handle; /**< Display Context handle */
  kal_uint32                  dspl_element_handle; /**< Display Element handle */
} va2_video_renderer_display_surface_t;

/****************************************************************************
 * API functions -- external use
 ****************************************************************************/
/**
 *  @return VIDEO_COMPONENT_TYPE_T* is the handle to the video renderer of specified type. \
 *          If NULL, this function call is failed.
 *  @param  VA2_VIDEO_RENDERER_TYPE_T eType The type of video renderer to be initialized.
 *  @remark This function is not allowed to be invoked in NU+ ISR threads, if NU+ is the target RTOS.
 *  @remark This function fails if not on MTK target
 */
extern VIDEO_COMPONENT_TYPE_T* 
GetVideoRendererHandle(
  VA2_VIDEO_RENDERER_TYPE_T eType,
  VIDEO_EXTMEM_HANDLER_T* prExtmemHandler,
  VIDEO_INTMEM_HANDLER_T* prIntmemHandler);

/**
 *  @return VIDEO_ERROR_TYPE_T error code
 *  @param  VIDEO_COMPONENT_TYPE_T *prHandle The handle of video renderer to be returned.
 *  @remark This function is not allowed to be invoked in NU+ ISR threads, if NU+ is the target RTOS.
 *  @remark This function fails if not on MTK target
 */
extern VIDEO_ERROR_TYPE_T 
ReleaseVideoRendererHandle(
  VIDEO_COMPONENT_TYPE_T *prHandle);


/**
 *  The control of IDP
 *  @remark set it back to 0 when IDP is closed.
 *  @common none
 */
extern kal_uint32 _va2_comp_video_renderer_idp_key;
extern VIDEO_BUFFERHEADER_TYPE_T _va2_comp_video_renderer_rNewBuffHeader;

extern volatile kal_bool _va2_vr_vt_get_frame;

extern VIDEO_BUFFERHEADER_TYPE_T _rBlackBufferHdr;
extern VA2_VIDEO_FRAME_T _rBlackVdoFrm;

extern kal_uint32 _va2_vr_render_display_buffer_cnt;

extern VIDEO_EXTMEM_HANDLER_T* _va2_vr_render_extmem_handler;
	
/// @}
#endif /*__VIDEO_ARCHI_V2__*/
#endif // #ifndef __VA2_COMP_VIDEO_RENDERER_H__

