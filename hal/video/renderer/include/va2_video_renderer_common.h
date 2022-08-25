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
 *    va2_video_renderer_common.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    Common Video Renderer definitions of Video Architecture V2.
 *    For internal usage, renderer only.
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
#ifndef __VA2_VIDEO_RENDERER_COMMON_H__
#define __VA2_VIDEO_RENDERER_COMMON_H__

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
#include "video_types_v2.h"
#include "va2_comp_video_renderer.h"
#include "va2_util_buffer_header_queue.h"
#include "video_comm_component_v2.h"
#include "drv_sw_features_video.h"


/****************************************************************************
 * macros and options -- internal use
 ****************************************************************************/
#if defined(MT6235) || defined(MT6235B)
#define VA2_COMP_VR_DSPL_DEFAULT_TIMEOUT_TIME         (100) // msec
#else
#define VA2_COMP_VR_DSPL_DEFAULT_TIMEOUT_TIME         (30) // msec
#endif

//MAUI_02452172 reduce late redraw threshold
//#define VA2_COMP_VR_DSPL_LATE_REDRAW_THRESHOLD        (400) // msec
#define VA2_COMP_VR_DSPL_LATE_REDRAW_THRESHOLD        (250) // msec
 
//#define VA2_COMP_VR_NO_BH_RECEIVED_TIMEOUT_TIME (5000) // msec
#define VA2_COMP_VR_FRAME_DONE_RETRY_TIME       (10) // msec

#define TASK_WAIT_HISR_SET 0x00000001
#define TASK_WAIT_TRIGGER_DISPLAY_HISR_SET 0x00000002
#define TASK_WAIT_SUB_TITLE_FRAME_DONE_HISR_SET 0x00000004

/****************************************************************************
 * type definitions -- video renderer internal use
 ****************************************************************************/
#define VA2_COMP_VR_MAX_DSPL_FB_COUNT           (3)

typedef struct va2_comp_video_renderer_cb va2_comp_video_renderer_cb_t;

typedef VIDEO_ERROR_TYPE_T  (*va2_vr_state_transition_func_t)(va2_comp_video_renderer_cb_t *cb);
typedef kal_uint32          (*va2_vr_try_to_return_buf_hdrs_func_t)(va2_comp_video_renderer_cb_t *cb);
typedef kal_bool            (*va2_vr_check_params_configs_func_t)(va2_comp_video_renderer_cb_t *cb);
typedef kal_bool            (*va2_vr_config_hw_by_render_mode_func_t)(va2_comp_video_renderer_cb_t *cb, VA2_VIDEO_FRAME_T *video_frame);
typedef void                (*va2_vr_dspl_timer_hdlr_func_t)(va2_comp_video_renderer_cb_t *cb);
typedef void                (*va2_vr_hw_frame_done_cb_func_t)(va2_comp_video_renderer_cb_t *cb);
typedef kal_uint32          (*va2_vr_render_dspl_frame_buf_func_t)(va2_comp_video_renderer_cb_t *cb, kal_bool blocking);
typedef void                (*va2_vr_hisr_null_process_done_func_t)(va2_comp_video_renderer_cb_t *cb);
typedef void                (*va2_vr_bypass_buf_hdr_func_t)(va2_comp_video_renderer_cb_t *cb);

typedef struct va2_comp_video_renderer_func_set va2_comp_video_renderer_func_set_t;

typedef enum
{
    VIDEO_RENDERER_HISR_MODE_NONE = 0 /**< default error. */
   ,VIDEO_RENDERER_HISR_MODE_INIT_DISPLAY_TIMER
   ,VIDEO_RENDERER_HISR_MODE_BLACK_FRAME_INSERT
} VA2_VIDEO_RENDERER_HISR_MODE; 

struct va2_comp_video_renderer_func_set
{
  va2_vr_state_transition_func_t          t01_close_to_init;
  va2_vr_state_transition_func_t          t02_init_to_close;
  va2_vr_state_transition_func_t          t03_init_to_idle;
  va2_vr_state_transition_func_t          t04_idle_to_run;
  va2_vr_state_transition_func_t          t05_run_to_stop;
  va2_vr_state_transition_func_t          t06_stop_to_run;
  va2_vr_state_transition_func_t          t07_run_to_idle;
  va2_vr_state_transition_func_t          t08_stop_to_idle;
  va2_vr_state_transition_func_t          t09_idle_to_init;
  va2_vr_state_transition_func_t          t10_idle_to_close;
  va2_vr_state_transition_func_t          t11_stop_to_close;
  va2_vr_state_transition_func_t          t12_idle_to_idle;

  va2_vr_try_to_return_buf_hdrs_func_t    try_to_return_buf_hdrs;
  va2_vr_check_params_configs_func_t      check_params_configs; // function pointer not used, to be removed 
  va2_vr_config_hw_by_render_mode_func_t  config_hw_by_render_mode; // function pointer not used, to be removed 
  va2_vr_dspl_timer_hdlr_func_t           display_timer_hdlr;
  va2_vr_hw_frame_done_cb_func_t          hw_frame_done_cb; // function pointer not used, to be removed 
  va2_vr_render_dspl_frame_buf_func_t     render_dspl_frame_buf; // function pointer not used, to be removed 
  va2_vr_hisr_null_process_done_func_t    hisr_null_process_done;
  va2_vr_bypass_buf_hdr_func_t            bypass_buf_hdr;
};

/**
 *  The control block of stereo video.
 */
typedef void(*stereo_renderer_transformation_cb)(void);

struct video_renderer_stereo_video
{
  VA2_VIDEO_RENDERER_3D_MODE_T              mode; /**< VA2_VIDEO_RENDERER_3D_MODE_T */
  kal_uint32                                src_buffer;
  kal_uint32                                src_buffer_size;
  kal_uint32                                dst_buffer;
  kal_uint32                                dst_buffer_size;
  kal_uint32                                src_width;
  kal_uint32                                src_height;
  VA2_VIDEO_RENDERER_COLOR_FORMAT_T         format;
  kal_bool                                  enable_callback;
  stereo_renderer_transformation_cb         callback;
};
typedef struct video_renderer_stereo_video video_renderer_stereo_video_t;

/**
 *  The control block of subtitle playback.
 */
struct video_renderer_subtitle_render_config
{
  va2_comp_video_renderer_cb_t *cb;
  kal_bool                     blocking;
};
typedef struct video_renderer_subtitle_render_config video_renderer_subtitle_render_config_t;


/**
 *  The control block of a VA2 OMX-like Video Renderer.
 */
struct va2_comp_video_renderer_cb
{
  va2_comp_video_renderer_func_set_t        funcs; /**< MUST NOT be changed, decided in compile time. */
  VA2_VIDEO_RENDERER_TYPE_T                 renderer_type; /**< MUST NOT be changed, decided in compile time. */
  kal_semid                                 vr_sema_vrstate_sync; 
                                            /**< The semaphore is to protect the VR states. This will be created 
                                            for one time for one handset power cycle. */
  kal_timerid                               display_timer; /**< This timer is used for self-triggering to keep display updated. This timer is only used 
                                                                    in RUN state, and should be cancelled when tranisition out of RUN state. */
  kal_eventgrpid                            EventID;
  va2_util_buf_hdr_q_handle_t               vr_q_handle; /**< This is the control block of buffer header queues. */

  VIDEO_COMM_STATE_T                        state;

  kal_bool                                  bypass;

  VA2_VIDEO_RENDERER_COLOR_FORMAT_T         src_color_format;
  VA2_FRAME_BUFFER_ADDRESS_T                src_fb_addr;
  VA2_FRAME_SIZE_T                          src_size;
  VA2_CLIP_WINDOW_T                         src_clip;

  VA2_FRAME_ASPECT_RATIO_T                  src_aspect_ratio;

  VA2_FRAME_SIZE_T                          dst_size;
  VA2_CLIP_WINDOW_T                         dst_clip;
  // total rotation angle and flip(for MDP)
  va2_video_renderer_rotate_flip_t          rotate_flip;
  // video frame rotation angle and flip, acquired from video tag
  va2_video_renderer_rotate_flip_t          video_frame_rotate_flip;
  // UI display rotation angle and flip
  va2_video_renderer_rotate_flip_t          display_rotate_flip;
  VA2_VIDEO_RENDERER_COLOR_FORMAT_T         dst_color_format;
  VA2_FRAME_SIZE_T                          dst_fb_size;
  VA2_FRAME_BUFFER_ADDRESS_T                dst_fb_addr_array[VA2_COMP_VR_MAX_DSPL_FB_COUNT];
  VA2_FRAME_BUFFER_ADDRESS_T                dst_fb_start_addr_array[VA2_COMP_VR_MAX_DSPL_FB_COUNT];
  kal_bool                                  trigger_display; /**< indicate if we need to config LCD to be in HW-trig mode */

#if (!defined(DRV_IDP_6252_SERIES))
  kal_bool                                  disable_dcmode; /**< indicate if we need to config LCD to be in HW-trig mode */
  kal_bool                                  bypass_hw_layer_src_rect; /**< indicate if we need to config source rectangle again */
  va2_video_renderer_post_process_config_t  post_process;
#endif

  VA2_VIDEO_RENDERER_RENDER_MODE_T          render_mode;
  va2_video_renderer_display_surface_t      display_surface;
  kal_bool                                  keep_curr_ptr_when_run; /**< default KAL_FALSE. */

#if (!defined(DRV_IDP_6252_SERIES))
  // TOD O: If this is obtained from module such as resource manager will be better, the upper layer code then can be HW independent! 
  VA2_MEMORY_BLOCK_T                        internal_memory; /**< internal memory chuck set by IL client used as HW line buffer in some platforms. */
  // TOD O: This is also a HW-dependent config...think about how to abstract this! */
  kal_uint32                                mp4dblk_quant_buf; /**< MP4 deblock quantization buffer address */
#endif

  VA2_VIDEO_RENDERER_HISR_MODE              eVdoRndrHisrMode;
  kal_uint32                                u4FramePeriodInMS;
  kal_uint32                                u4LastRenderTimestamp; /**< all rendering considered */
  kal_uint32                                u4LastSrcRenderTimestamp; /**< only src-triggered rendering considered */
  volatile kal_uint32                       u4MaxLcdTransferDuration; /**< TE sync included */
  kal_bool                                  bIsErrorNotified; /**< KAL_TRUE, if renderer ever notified an error. 
                                                                   KAL_FALSE, o.w. When Renderer is set to IDLE state, this should be set to KAL_FALSE. */
#if (!defined(DRV_IDP_6252_SERIES))
  kal_bool                                  IsRendererBusy;
#endif

#if defined(__VIDEO_SUBTITLE_SUPPORT__)
  va2_util_buf_hdr_q_handle_t               sub_vr_q_handle; /**< This is the control block of buffer header queues. */
  VA2_FRAME_BUFFER_ADDRESS_T                sub_src_fb_addr;
  VA2_FRAME_SIZE_T                          sub_src_size;
  VA2_VIDEO_RENDERER_COLOR_FORMAT_T         sub_src_color_format;
  VA2_FRAME_SIZE_T                          sub_dst_size;
  VA2_FRAME_SIZE_T                          sub_dst_fb_size;
  VA2_VIDEO_RENDERER_COLOR_FORMAT_T         sub_dst_color_format;
  VA2_FRAME_BUFFER_ADDRESS_T                sub_dst_fb_addr_array[VA2_COMP_VR_MAX_DSPL_FB_COUNT];
  va2_video_renderer_display_surface_t      sub_display_surface;
  kal_bool                                  IsSubtitleBusy;
#endif

#if defined(VA2_RENDERER_VP_STEREO_VIDEO_SUPPORTED)
  video_renderer_stereo_video_t             stereo_video;
#endif

#if defined(MT6235) || defined(MT6235B) 
  kal_uint32   SW_Pitch_Mem_Addr;
  kal_uint32   SW_Pitch_Mem_Size;
#endif
#if defined(CONTOUR_IMPROVEMENT_MT6253) || defined(CONTOUR_IMPROVEMENT_MT6235)
  kal_uint32   u4Fps;  
  kal_uint32   u4RemainTimeForSwDither; /**< unit : ms */
  kal_uint32   u4DecodingTime; /**< unit : ms */
  kal_uint32   u4VdoBufConsumptPercent;
  kal_uint32   WM_start_address;
  kal_uint32   WM_size;
#endif 
};

/**
 *  Debug trace IDs for video renderer internal uses
 *  @remark This enum is allowed to be expanded based on requirements of HW-dependent implementations. 
 *  @remark Please do not wrap chip or compile options inside this enum type.
 */
typedef enum
{
    VA2_VR_API_________INIT
  , VA2_VR_API_________SEND_COMMAND__STATE_SET
  , VA2_VR_API_________GET_PARAMETER
  , VA2_VR_API_________SET_PARAMETER
  , VA2_VR_API_________USE_BUFFER
  , VA2_VR_API_________EMPTY_THIS_BUFFER
  , VA2_VR_API_________EMPTY_THIS_BUFFER__Q_FULL
  , VA2_VR_API_________EMPTY_THIS_BUFFER__TRIGGER_HW
  , VA2_VR_API_________EMPTY_THIS_BUFFER__ENQUEUE_ONLY
  , VA2_VR_API_________EMPTY_THIS_BUFFER__SUBTITLE
  , VA2_VR_API_________EMPTY_THIS_BUFFER__SUBTITLE_TRIGGER_ROTATOR
  , VA2_VR_API_________EMPTY_THIS_BUFFER__SUBTITLE_ENQUEUE_ONLY
  , VA2_VR_API_________EMPTY_THIS_BUFFER__SUBTITLE_SILENT_FRAME
  , VA2_VR_API_________EMPTY_THIS_BUFFER__SUBTITLE_SOURCE_REMOVAL
  , VA2_VR_API_________EMPTY_THIS_BUFFER__SUBTITLE_SOURCE_RESTORE
  , VA2_VR_API_________RENDER_PASS1_START
  , VA2_VR_API_________RENDER_PASS1_END
  , VA2_VR_API_________RENDER_PASS1_CB
  , VA2_VR_API_________RENDER_PASS2_START
  , VA2_VR_API_________RENDER_PASS2_END
  , VA2_VR_API_________RENDER_PASS2_CB
  , VA2_VR_API_________RENDER_PASS3_START
  , VA2_VR_API_________RENDER_PASS3_END
  , VA2_VR_API_________RENDER_PASS3_CB
  , VA2_VR_API_________FILL_THIS_BUFFER
  , VA2_VR_API_________SET_CALLBACKS
  , VA2_VR_API_________DEINIT

  , VA2_VR_TRANSITION__T00_SELF_TRANSITION
  , VA2_VR_TRANSITION__T01_CLOSE_TO_INIT
  , VA2_VR_TRANSITION__T02_INIT_TO_CLOSE
  , VA2_VR_TRANSITION__T03_INIT_TO_IDLE
  , VA2_VR_TRANSITION__T04_IDLE_TO_RUN
  , VA2_VR_TRANSITION__T05_RUN_TO_STOP
  , VA2_VR_TRANSITION__T06_STOP_TO_RUN
  , VA2_VR_TRANSITION__T07_RUN_TO_IDLE
  , VA2_VR_TRANSITION__T08_STOP_TO_IDLE
  , VA2_VR_TRANSITION__T09_IDLE_TO_INIT
  , VA2_VR_TRANSITION__T10_IDLE_TO_CLOSE
  , VA2_VR_TRANSITION__T11_STOP_TO_CLOSE
  , VA2_VR_TRANSITION__T12_IDLE_TO_IDLE

  , VA2_VR_INTERNAL____RETURN_BUFFER_HEADER /**< Traced on each buf hdr returned, param: a pointer to the buf. */
  , VA2_VR_INTERNAL____RETURN_SUBTITLE_BUFFER_HEADER /**< Traced on each buf hdr returned, param: a pointer to the buf. */
  , VA2_VR_INTERNAL____RETURN_BLACK_BUFFER_HEADER
  , VA2_VR_INTERNAL____MDP_HW_FRAME_DONE_CB
  , VA2_VR_INTERNAL____MDP_HW_FRAME_DONE_CB__TRIGGER_HW
  , VA2_VR_INTERNAL____MDP_HW_FRAME_DONE_CB__TRIGGER_HW_DONE
  , VA2_VR_INTERNAL____LCD_HW_FRAME_DONE_CB
  , VA2_VR_INTERNAL____LCD_HW_FRAME_DONE_CB__TRIGGER_HW
  , VA2_VR_INTERNAL____LCD_HW_FRAME_DONE_CB__TRIGGER_HW_DONE
  , VA2_VR_INTERNAL____SUBTITLE_FRAME_DONE_CB
  , VA2_VR_INTERNAL____TRIGGER_SUBTITLE

  , VA2_VR_INTERNAL____DSPL_TIMER_ASSERT
  , VA2_VR_INTERNAL____DSPL_TIMER_TIMEOUT
  , VA2_VR_INTERNAL____DSPL_TIMER_TRIGGER_RENDER_IN_VHISR

  , VA2_VR_INTERNAL____RENDER /**< Video Renderer processes one buffer header by rendering it. */
  , VA2_VR_INTERNAL____SUBTITLE_RENDER /**< Video Renderer processes one buffer header by rendering it. */
  , VA2_VR_INTERNAL____NULL_PROCESS /**< Video Renderer processes one buffer header by not handling it and just puts it in the to-be-returned queue. */

  , VA2_VR_DEBUG_______NO_VIDEO_FRAME_TO_DRAW
  , VA2_VR_DEBUG_______NO_SUBTITLE_FRAME_TO_DRAW
  , VA2_VR_DEBUG_______START_LCD_HW_TRIGGER_MODE
  , VA2_VR_DEBUG_______STOP_LCD_HW_TRIGGER_MODE
  
  , VA2_VR_HW_RESIZER_INTERNAL____RENDER /**< Video Renderer processes one buffer header by rendering it. */
  , VA2_VR_SW_RESIZER_INTERNAL____RENDER /**< Video Renderer processes one buffer header by rendering it. */
  , VA2_VR_HW_RESIZER_DROP_FRAME  /**hw resizer drop frame */
  , VA2_VR_SW_RESIZER_DROP_FRAME  /**sw resizer drop frame */
} va2_vr_debug_trace_id_t;

typedef struct
{
  kal_uint32                        time_stamp;
  //va2_comp_video_renderer_cb_t*     cb; /**< @deprecated: Unnecessary. */
  kal_uint32                        param; /**< The meaning of this field is decided by different trace IDs. */
  va2_vr_debug_trace_id_t           trace_id;
} va2_vr_debug_trace_entry_t;


/****************************************************************************
 * API functions -- Video Renderer use only
 ****************************************************************************/
extern void 
va2_vr_init_trace(
  kal_uint32 no_of_entries, 
  va2_vr_debug_trace_entry_t *storage);

extern void 
va2_vr_add_trace(
  va2_vr_debug_trace_entry_t *storage, 
  va2_vr_debug_trace_id_t trace_id, 
  kal_uint32 param);

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
#endif

extern kal_uint32 
va2_vr_try_to_return_buffer_headers(
  va2_comp_video_renderer_cb_t *cb);

extern void 
va2_vr_notify_error_to_client(
  va2_comp_video_renderer_cb_t *cb);

extern VIDEO_ERROR_TYPE_T 
va2_vr_t01_close_to_init(
  va2_comp_video_renderer_cb_t *cb);

extern VIDEO_ERROR_TYPE_T 
va2_vr_t02_init_to_close(
  va2_comp_video_renderer_cb_t *cb);

extern VIDEO_ERROR_TYPE_T 
va2_vr_t04_idle_to_run(
  va2_comp_video_renderer_cb_t *cb);

extern VIDEO_ERROR_TYPE_T 
va2_vr_t06_stop_to_run(
  va2_comp_video_renderer_cb_t *cb);

extern VIDEO_ERROR_TYPE_T 
va2_vr_t07_run_to_idle(
  va2_comp_video_renderer_cb_t *cb);

extern VIDEO_ERROR_TYPE_T 
va2_vr_t08_stop_to_idle(
  va2_comp_video_renderer_cb_t *cb);

extern VIDEO_ERROR_TYPE_T 
va2_vr_t09_idle_to_init(
  va2_comp_video_renderer_cb_t *cb);

extern VIDEO_ERROR_TYPE_T 
va2_vr_t11_stop_to_close(
  va2_comp_video_renderer_cb_t *cb);

extern VIDEO_ERROR_TYPE_T 
va2_vr_t12_idle_to_idle(
  va2_comp_video_renderer_cb_t *cb);

extern VIDEO_ERROR_TYPE_T 
va2_vr_send_command(
  va2_comp_video_renderer_cb_t *cb, 
  VIDEO_COMMAND_TYPE_T eCmd, 
  kal_uint32 u4Param);

extern VIDEO_ERROR_TYPE_T 
va2_vr_use_buffer(
  va2_comp_video_renderer_cb_t *cb, 
  kal_uint8 *pu1Buff, 
  kal_uint32 u4Size);

extern VIDEO_ERROR_TYPE_T 
va2_vr_fill_this_buffer(
  va2_comp_video_renderer_cb_t *cb, 
  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader);

extern VIDEO_ERROR_TYPE_T 
va2_vr_set_callbacks(
  va2_comp_video_renderer_cb_t *cb, 
  VIDEO_CALLBACK_TYPE_T *prCallback);

extern VIDEO_ERROR_TYPE_T 
va2_vr_deinit(
  va2_comp_video_renderer_cb_t *cb);

/// @}
#endif /*__VIDEO_ARCHI_V2__*/
#endif // #ifndef __VA2_VIDEO_RENDERER_COMMON_H__

