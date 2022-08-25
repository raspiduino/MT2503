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
 *    va2_video_renderer_vp_mt6276.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    OpenMAX-like Video Renderer of Video Architecture V2.
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
/// \ingroup va2_video_renderer_vp_mt6276
/// @{
#if defined(__VIDEO_ARCHI_V2__)
/****************************************************************************
 * internal options
 ****************************************************************************/
//#define VA2_COMP_VR_ENABLE_DEBUG_TRACE

#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && !defined(__MAUI_BASIC__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // #if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && !defined(__MAUI_BASIC__)

/****************************************************************************
 * include directives
 ****************************************************************************/
/******* main header file *******************/
#include "lcd_sw_inc.h"
#include "va2_video_renderer_vp_mt6276.h"

#if defined(VA2_VIDEO_RENDERER_VP_MT6276)

/******* Kernal abstraction *****************/
#include "kal_public_api.h"
/******* VA2 common *************************/
#include "video_types_v2.h"
#include "video_comm_component_v2.h"
#include "video_buffer_management_v2.h"
/******* VA2 Video Renderer Component *******/
#include "drv_sw_features_video.h"
#include "va2_comp_video_renderer.h"
#include "va2_video_renderer_common.h"
#include "va2_util_buffer_header_queue.h"
#include "va2_util_misc.h"
#include "va2_video_renderer_vp.h"
#include "va2_video_renderer_mem_req.h"
/******* driver common **********************/
#include "drv_features_mdp.h"
#include "drv_comm.h"
/******* MDP driver *************************/
#include "img_common_enum.h"
#include "idp_video_decode.h" // TODO:[3] check inc path
/******* LCD driver *************************/
#include "lcd_if.h" // TODO:[3] check inc path
#include "lcd_if_hw.h"
#if defined(DRV_DISPLAY_DRIVER_V2)
//#include "wfc\wfc.h" // The include path is "mcu\interface\hal\display\api"
#include "wfc\inc\wfc_mm_api.h"     // The include path is "mcu\hal\display\wfc\inc"
#include "common\owftypes.h" // The include path is "mcu\interface\hal\display\api"
#include "common\owfnativestream.h" // The include path is "mcu\interface\hal\display\api"
#include "Owfimage.h"

// That I can turn it all off here...
#ifndef VRNDRR_DD_ASSERT
#define VRNDRR_DD_ASSERT(_expr_) ASSERT(_expr_)
#endif

#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)
/******* Visual HISR driver *****************/
#include "visualhisr.h"
/******* SoftwareLA *************************/
#if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)
#include "SST_sla.h"
#endif  // #if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)

#if defined(VA2_RENDERER_VP_STEREO_VIDEO_SUPPORTED)
#include "stereo_video_color_transformation.h"
#endif

#if defined(__VIDEO_SUBTITLE_SUPPORT__)
// include RGB rotator header for subtitle rotation
#include "rotator_enum.h"
#include "rgb_rotator_api.h"
#endif 

#if defined(VA2_RENDERER_VP_STEREO_VIDEO_SUPPORTED) || defined (__VIDEO_SUBTITLE_SUPPORT__)
#include "video_renderer_task_thread_pool.h"
#include "cache_sw.h"   /* For dynamic switch cacheability */
#include "mmu.h"        /* For dynamic switch cacheability */
#endif

#include "kal_trace.h"
#include "drv_trc.h"

/****************************************************************************
 * local type definitions and macros
 ****************************************************************************/
//#define VA2_COMP_VR_MAX_DSPL_FB_COUNT           (3) // unnecessary
//#define VA2_COMP_VR_RENDER_TIME_MAX             (1100) // (32768/1000)*33.3 ~ 1091 // 33.3ms
#define VA2_COMP_VR_RENDER_TIME_MAX             (3277) // (32768/1000)*100 ~ 3277 // 100ms

#define VA2_VR_VP_6276_DEBUG_TRACE_SIZE         (128)

#define VIDEO_RENDERER_SUPPORT_MULTIPLE_VIDEO_FRAME

/****************************************************************************
 * declarations
 ****************************************************************************/
#if defined(__MTK_TARGET__)


static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6276_init(void);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6276_send_command(
  VIDEO_COMMAND_TYPE_T eCmd, 
  kal_uint32 u4Param);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6276_get_parameter(
  VIDEO_PARAM_TYPE_T eCmd, 
  void *pParam);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6276_set_parameter(
  VIDEO_PARAM_TYPE_T eCmd, 
  void *pParam);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6276_use_buffer(
  kal_uint8 *pu1Buff, 
  kal_uint32 u4Size);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6276_empty_this_buffer(
  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6276_empty_this_buffer_real(
  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6276_fill_this_buffer(
  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6276_set_callbacks(
  VIDEO_CALLBACK_TYPE_T *prCallback);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6276_deinit(void);

static kal_uint32 
_va2_vr_vp_6276_process_input_buffer(
  va2_comp_video_renderer_cb_t *cb, 
  kal_bool blocking,
  kal_uint32 pass);

static kal_uint32 
_va2_vr_vp_6276_render_display_frame_buffer(
  va2_comp_video_renderer_cb_t *cb, 
  kal_bool blocking);

static kal_bool 
_va2_vr_vp_6276_check_params_configs(
  va2_comp_video_renderer_cb_t *cb);

static kal_bool 
_va2_vr_vp_6276_config_idp_by_render_mode(
  va2_comp_video_renderer_cb_t *cb, 
  VA2_VIDEO_FRAME_T *video_frame);

static void
_va2_vr_vp_6276_display_timer_hdlr(
  void *param);

static void
_va2_vr_vp_6276_idp_frame_done_cb(
  void *param);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6276_t01_close_to_init(
  va2_comp_video_renderer_cb_t *cb);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6276_t03_init_to_idle(
  va2_comp_video_renderer_cb_t *cb);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6276_t04_idle_to_run(
  va2_comp_video_renderer_cb_t *cb);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6276_t05_run_to_stop(
  va2_comp_video_renderer_cb_t *cb);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6276_t06_stop_to_run(
  va2_comp_video_renderer_cb_t *cb);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6276_t10_idle_to_close(
  va2_comp_video_renderer_cb_t *cb);

static void 
_va2_vr_vp_6276_lcd_frame_done_cb(
  void *param);
#endif  // #if defined(__MTK_TARGET__)

/****************************************************************************
 * local variables
 ****************************************************************************/
#if defined(__MTK_TARGET__)

/**
 *  @status OK
 */
static VIDEO_COMPONENT_TYPE_T _va2_vr_vp_6276_primitives = 
{
    _va2_vr_vp_6276_init
  , _va2_vr_vp_6276_send_command
  , _va2_vr_vp_6276_get_parameter
  , _va2_vr_vp_6276_set_parameter
  , _va2_vr_vp_6276_use_buffer
  , _va2_vr_vp_6276_empty_this_buffer
  , _va2_vr_vp_6276_fill_this_buffer
  , _va2_vr_vp_6276_set_callbacks
  , _va2_vr_vp_6276_deinit
};

static struct va2_comp_video_renderer_cb _va2_vr_vp_6276_cb = 
  {
    {
      _va2_vr_vp_6276_t01_close_to_init, 
      va2_vr_t02_init_to_close, 
      _va2_vr_vp_6276_t03_init_to_idle, 
      _va2_vr_vp_6276_t04_idle_to_run, 
      _va2_vr_vp_6276_t05_run_to_stop, 
      _va2_vr_vp_6276_t06_stop_to_run, 
      va2_vr_t07_run_to_idle, 
      va2_vr_t08_stop_to_idle, 
      va2_vr_t09_idle_to_init, 
      _va2_vr_vp_6276_t10_idle_to_close, 
      va2_vr_t11_stop_to_close, 
      va2_vr_t12_idle_to_idle,
      va2_vr_try_to_return_buffer_headers, 
      _va2_vr_vp_6276_check_params_configs, 
      _va2_vr_vp_6276_config_idp_by_render_mode, 
      (va2_vr_dspl_timer_hdlr_func_t) _va2_vr_vp_6276_display_timer_hdlr, 
      (va2_vr_hw_frame_done_cb_func_t) _va2_vr_vp_6276_idp_frame_done_cb, 
      NULL, 
      NULL,
      NULL
    }, 
    VIDEO_RENDERER_VIDEO_PLAYBACK, 
    0, 
    0, 
    0,
    {0}, 
    KAL_FALSE
  };

static va2_vr_debug_trace_entry_t _va2_vr_vp_6276_debug_trace[VA2_VR_VP_6276_DEBUG_TRACE_SIZE] = {0};

extern VIDEO_BUFFERHEADER_TYPE_T _rBlackBufferHdr;
extern VA2_VIDEO_FRAME_T _rBlackVdoFrm;

#if defined(DRV_DISPLAY_DRIVER_V2)
static WFCDevice _va2_vr_vp_6276_ddv2_dev = WFC_INVALID_HANDLE;
static WFCContext _va2_vr_vp_6276_ddv2_ctx = WFC_INVALID_HANDLE;
static WFCElement _va2_vr_vp_6276_ddv2_element = WFC_INVALID_HANDLE;
static WFCSource _va2_vr_vp_6276_ddv2_vid_src = WFC_INVALID_HANDLE;
static OWFNativeStreamType _va2_vr_vp_6276_ddv2_vid_stream = OWF_INVALID_HANDLE;
static WFCSource _va2_vr_vp_6276_ddv2_vid_img_src = WFC_INVALID_HANDLE;
static kal_uint32 _va2_vr_vp_6276_vid_dspl_fbs[3][2] = { 0 };

#if defined(__VIDEO_SUBTITLE_SUPPORT__)
static WFCSource _va2_vr_vp_6276_ddv2_sub_src = WFC_INVALID_HANDLE;
static OWFNativeStreamType _va2_vr_vp_6276_ddv2_sub_stream = OWF_INVALID_HANDLE;
static WFCSource _va2_vr_vp_6276_ddv2_sub_img_src = WFC_INVALID_HANDLE;
static kal_uint32 _va2_vr_vp_6276_sub_dspl_fbs[3][2] = { 0 };
static kal_uint32 _va2_vr_vp_6276_subtitle_trigger_buffer = NULL;
#endif
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)

static kal_uint32 _va2_vr_vp_6276_drop_frame_cnt = 0;
//static volatile kal_bool clear_video_frame = KAL_FALSE;

//chrono add for LCD frame done checking
static volatile kal_bool _va2_vr_vp_6276_lcd_frame_done = KAL_TRUE;
static kal_uint32 VideoPortNum;

#if defined(__VIDEO_SUBTITLE_SUPPORT__)
RGB_ROTATOR_HANDLE_STRUCT *pRgbRotHandle;
// This flag is used to indicate current subtitle source is removed or restored
static kal_bool _va2_vr_vp_6276_sub_src_removed = KAL_FALSE;
// This flag is used to indicate whether current source operation is committed or not
static kal_bool _va2_vr_vp_6276_sub_src_committed = KAL_TRUE;
static kal_uint32 _va2_vr_render_subtitle_buffer_cnt = 0;
static kal_uint32 SubtitlePortNum;
#endif

// for process input buffer error monitor
static kal_uint32 _va2_vr_vp_6276_pass1_err_cnt;
static kal_uint32 _va2_vr_vp_6276_pass2_err_cnt;
static kal_uint32 _va2_vr_vp_6276_pass3_err_cnt;

/*
 * "_idp_scen_video_decode_mode" is used to indicate motion jpeg mode or not.
 * When VIDEO, it means normal video decode playback
 * When MJPEG, it means motion jpeg decode playback
 */
#if defined(DRV_IDP_MT6256_E2_SERIES) && defined(MJPG_DECODE)

typedef enum 
{
  VIDEO,
  MJPEG
} render_mode;

static render_mode _va2_vr_vp_6276_render_mode = VIDEO;

#endif


/****************************************************************************
 * External References
 ****************************************************************************/
extern kal_bool   _va2_comp_vr_have_config_lcd;
extern kal_uint32 _va2_comp_vr_triggered_lcd_id_this_time;

//#define CCASSERT(predicate) _x_CCASSERT_LINE(predicate, __LINE__)
//#define _x_CCASSERT_LINE(predicate, line) typedef char constraint_violated_on_line_##line[2*((predicate)!=0)-1];

#endif  // #if defined(__MTK_TARGET__)

/****************************************************************************
 * local function bodies
 ****************************************************************************/
#if defined(__MTK_TARGET__)

#if 0
#if defined(MDP_SUPPORT_VP_EMI_BW_SWITCH)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //#if defined(MDP_SUPPORT_VP_EMI_BW_SWITCH)
#endif

static void _va2_vr_vp_6276_lcd_frame_done_cb(void *param)
{
  va2_comp_video_renderer_cb_t *cb = (va2_comp_video_renderer_cb_t*) param;

  kal_uint32 const saved_mask = SaveAndSetIRQMask();
  _va2_vr_vp_6276_lcd_frame_done = KAL_TRUE;
  RestoreIRQMask(saved_mask);

  ASSERT(NULL != cb);

#if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("LFD", SA_start);
#endif  // #if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)

  va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_INTERNAL____LCD_HW_FRAME_DONE_CB, 0);

#if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("LFD", SA_stop);
#endif  // #if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)
}

#if defined(DRV_DISPLAY_DRIVER_V2)
void _va2_vr_vp_6276_wfc_frame_done_cb(
  WFCContextEventTypeMTK event, 
  void* param)
{
  _va2_vr_vp_6276_lcd_frame_done_cb(param);
}
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)


#if defined(DRV_DISPLAY_DRIVER_V2)
static kal_bool
_va2_vr_vp_6276_is_hw_layer_setting_modified_by_VR(
  WFCRotation *layerRotation)
{
  // check layerRotation angle: 
  // if 0 degree => return KAL_TRUE.(no need to configure LCD source rectangle)
  // if not 0 degree => return KAL_FALSE. (need to configure LCD source rectangle)
  // (NOTE: Video Renderer will always configure 0 degree to LCD. 
  // If layerRotation is 0 degree, it means Video Renderer has configured LCD layerRotation angle
  // and source rectangle. There's no need to configure LCD source rectangle again.)
  if (WFC_ROTATION_0 != *layerRotation)
  {
    return KAL_FALSE;
  }
  else
  {
    return KAL_TRUE;
  }
}
#endif

#if defined(__VIDEO_SUBTITLE_SUPPORT__)
static void
_va2_vr_vp_6276_trigger_subtitle(
  kal_uint32 dspl_fb, 
  va2_comp_video_renderer_cb_t *cb)
{
#if defined(DRV_DISPLAY_DRIVER_V2)
  if ((KAL_TRUE == cb->trigger_display) && 
      (OWF_INVALID_HANDLE != _va2_vr_vp_6276_ddv2_sub_stream))
  {
    OWFNativeStreamBuffer buf;
    kal_uint32 i;

#if 1
    for (i=0; i<2; i++)
    {
      if (dspl_fb == _va2_vr_vp_6276_sub_dspl_fbs[i][0])
      {
        buf = (OWFNativeStreamBuffer) _va2_vr_vp_6276_sub_dspl_fbs[i][1];
        //set the lcd frame done flag to false only if trigger is valid
        if (buf == NULL)
        {return;}
      
        owfNativeStreamReleaseWriteBuffer(_va2_vr_vp_6276_ddv2_sub_stream, 
                                        buf/* (OWFNativeStreamBuffer) 0x100 */, 
                                        NULL /* (EGLDisplay) */, 
                                        NULL /* (EGLSyncKHR) */);
        _va2_vr_vp_6276_sub_dspl_fbs[i][1] = 0x0;
        if (0x0 == _va2_vr_vp_6276_sub_dspl_fbs[i^1][1])
        {
          _va2_vr_vp_6276_sub_dspl_fbs[i^1][1] = (kal_uint32) owfNativeStreamAcquireWriteBuffer(_va2_vr_vp_6276_ddv2_sub_stream);
        }
        break;
      }
    }
#else
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
/* under construction !*/
#endif
  }
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)
}


static kal_uint32  
_va2_vr_vp_6276_try_to_return_subtitle_buffer_headers(
  va2_comp_video_renderer_cb_t *cb)
{
  va2_util_buf_hdr_q_item_t *item = NULL;
  
  // while there is still item in the to be returned queue
  while (NULL != (item = va2_util_buf_hdr_q_peek(&(cb->sub_vr_q_handle.to_be_returned_q))))
  {
    // return it by invoking the FillThisBuffer hook of peer component
    if (VIDEO_ERROR_NONE != cb->state.rInputComp[SubtitlePortNum].prComp->pfnFillThisBuffer(&(item->buffer_header)))
    {
      // break if any error happens
      break;
    }
    va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_INTERNAL____RETURN_SUBTITLE_BUFFER_HEADER, (kal_uint32) (item->buffer_header.pu1Buffer));

    // dequeue from the to be returned queue...
    item = va2_util_buf_hdr_dequeue(&(cb->sub_vr_q_handle.to_be_returned_q));
    // release q items back to pool...
    kal_mem_set((void*) item, 0x0, sizeof(va2_util_buf_hdr_q_item_t));
  }
  return 0;
}


static void
_va2_vr_vp_6276_subtitle_frame_done_cb(void)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6276_cb;

  ASSERT(NULL != cb);

  if(VIDEO_STATE_RUN != cb->state.eState)
  {
    kal_set_eg_events(cb->EventID, TASK_WAIT_SUB_TITLE_FRAME_DONE_HISR_SET, KAL_OR);
    return;
  }
 
  if (KAL_TRUE == cb->bypass)
  {
    // Unexpected: FrameDone occurs unders bypass mode.
    // Bypass mode should only be switched under Stop state, and render should only execute under Run state.
    // At last, FrameDone will not be processed except under Run state. There it is.
    ASSERT(0);
  }

  va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_INTERNAL____SUBTITLE_FRAME_DONE_CB, 0);

#if defined (VIDEO_RENDERER_SUPPORT_MULTIPLE_VIDEO_FRAME)
  // if buffer header received while HW doing a frame...use the latest frame buffer for the next update...
  if (0 != cb->sub_vr_q_handle.to_be_processed_q.size)
  {
    va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->sub_vr_q_handle));
  }

  // try to return all buffers...
  _va2_vr_vp_6276_try_to_return_subtitle_buffer_headers(cb);
#endif

  kal_set_eg_events(cb->EventID, TASK_WAIT_SUB_TITLE_FRAME_DONE_HISR_SET, KAL_OR);
  return;
}


void 
va2_vr_vp_6276_rotate_subtitle_frame(
  void *param)
{
  ROTATOR_COLOR_FORMAT_ENUM RotatorColorFormat;
  ROTATOR_STATUS_ENUM RotatorStatus;
  kal_uint32 ImageBuffSize = 0;
  kal_uint32 ExtMemMin, ExtMemBest, IntMemMin, IntMemBest;
  kal_uint32 iIndex;
  video_renderer_subtitle_render_config_t *exec_param = (video_renderer_subtitle_render_config_t*)param;
  va2_comp_video_renderer_cb_t *cb = exec_param->cb;

  // this function must be called at task level
  if (KAL_TRUE == kal_if_hisr() || KAL_TRUE == kal_if_lisr())
  {ASSERT(0);}

  // configure and start rgbRotator for subtitle frame rotation
  if (VIDEO_RENDERER_COLOR_RGB565 == cb->sub_src_color_format)
  {
    ImageBuffSize = cb->sub_src_size.u4_width * cb->sub_src_size.u4_height * 2;
    RotatorColorFormat = ROTATOR_COLOR_FORMAT_ENUM_RGB565;
  }
  else if (VIDEO_RENDERER_COLOR_RGB888 == cb->sub_src_color_format)
  {
    ImageBuffSize = cb->sub_src_size.u4_width * cb->sub_src_size.u4_height * 3;
    RotatorColorFormat = ROTATOR_COLOR_FORMAT_ENUM_RGB888;
  }
  else if (VIDEO_RENDERER_COLOR_ARGB8888 == cb->sub_src_color_format)
  {
    ImageBuffSize = cb->sub_src_size.u4_width * cb->sub_src_size.u4_height * 4;
    RotatorColorFormat = ROTATOR_COLOR_FORMAT_ENUM_ARGB8888;
  }
  else
  {
    // unsupported format, drop current frame
    cb->IsSubtitleBusy = KAL_FALSE;
    return;
  }
  
  RotatorStatus = rgbRotatorGetHandle(&pRgbRotHandle, ROTATOR_MODE_AUTO);
  if (ROTATOR_STATUS_OK != RotatorStatus)
  {
    // RGBrotator is busy, drop current frame
    cb->IsSubtitleBusy = KAL_FALSE;
    return;
  }

  // RGBRotator ready, ready to process current frame
  // previous subtitle frame does not update to LCD but next subtitle frame comes!
  // decrease the subtitle frame count by 1 and clear the queued display subtitle buffer
  if (NULL != _va2_vr_vp_6276_subtitle_trigger_buffer)
  {
    iIndex = (_va2_vr_render_subtitle_buffer_cnt - 1) & 0x1;
    _va2_vr_vp_6276_subtitle_trigger_buffer = NULL;
  }
  else
  {
    iIndex = _va2_vr_render_subtitle_buffer_cnt & 0x1;
    _va2_vr_render_subtitle_buffer_cnt++;
  }

  // set callback function to NULL, currently use only blocking mode
  {
    rgbRotatorSetCallbackFunction(pRgbRotHandle, NULL);     // use polling mode instead of interrupt mode
  }

#if 1
  // Enable auto cache/non-cache switch for RGBRotator
  {
    rgbRotatorSetDstBufferSwitchBehavior(pRgbRotHandle, GFX_CACHE_SWITCH_BEHAVIOR_TRY_SWITCH);
  }
#else
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

  rgbRotatorSetSrcBufferInfo(pRgbRotHandle, RotatorColorFormat,
                             (void *) cb->sub_src_fb_addr.u4_fb_addr_plane0,
                             ImageBuffSize,
                             cb->sub_src_size.u4_width, cb->sub_src_size.u4_height);
  
  rgbRotatorSetDstBufferInfo(pRgbRotHandle, RotatorColorFormat,
                             (void *) cb->sub_dst_fb_addr_array[iIndex].u4_fb_addr_plane0,
                             ImageBuffSize,
                             cb->sub_dst_fb_size.u4_width, cb->sub_dst_fb_size.u4_height);
  
  rgbRotatorSetSrcWindow(pRgbRotHandle, 0, 0, cb->sub_src_size.u4_width, cb->sub_src_size.u4_height);
  
  rgbRotatorSetDstWindow(pRgbRotHandle, 0, 0, cb->sub_dst_fb_size.u4_width, cb->sub_dst_fb_size.u4_height);
  
  rgbRotatorSetRotation(pRgbRotHandle, (ROTATOR_CW_ROTATE_ANGLE_ENUM) va2_util_convert_to_idp_rot_angle(cb->rotate_flip.u2_cw_rotate_angle, cb->rotate_flip.b_flip));
  
  rgbRotatorCheckAbortFunction(pRgbRotHandle, NULL);
  
  rgbRotatorQueryWorkingMemory(pRgbRotHandle, &IntMemBest, &IntMemMin, &ExtMemBest, &ExtMemMin);
  
  if (IntMemMin != 0 || ExtMemMin > 0)
  {ASSERT(0);}

  // no working buffer is required
  rgbRotatorSetWorkingMemory(pRgbRotHandle, NULL, 0, NULL, 0);

  {
    RotatorStatus = rgbRotatorStart(&pRgbRotHandle);
    if (RotatorStatus != ROTATOR_STATUS_OK)
    {    
      // RGBrotator start fail, may be configuration error
      // temporary assert it
      ASSERT(0);
    }

    // busy waiting for rgbRotate finish
    {
      kal_uint32 start_time;
      
      start_time= drv_get_current_time();
       
      do
      {
        RotatorStatus = rgbRotatorGetStatus(pRgbRotHandle);
        if(ROTATOR_STATUS_OK == RotatorStatus ||
           ROTATOR_STATUS_COMPLETE == RotatorStatus)
        {
          break;
        }
        else
        {
          kal_sleep_task(1);
        }
      } while (VA2_COMP_VR_RENDER_TIME_MAX > drv_get_duration_tick(start_time, drv_get_current_time()));

      // release RGBRotator handle and change subtitle buffer with LCD
      rgbRotatorReleaseHandle(pRgbRotHandle);
      if (KAL_FALSE == exec_param->blocking)
      {
        kal_uint32 u4Flags = 0;

        if (KAL_FALSE == _va2_vr_vp_6276_sub_src_committed)
        {
          // subtitle stream source was only restored, not commit yet.
          // we need to commit the subtitle stream source before change buffer
          wfcMMCommit((WFCDevice) cb->sub_display_surface.dspl_dev_handle, 
                      (WFCContext) cb->sub_display_surface.dspl_ctx_handle, 
                      (WFCElement) cb->sub_display_surface.dspl_element_handle, WFC_COMMIT_ELEMENT);                
          _va2_vr_vp_6276_sub_src_committed = KAL_TRUE;
        }

        // record current subtitle display buffer address for trigger subtitle
        {
          kal_uint32 iIndex = ((_va2_vr_render_subtitle_buffer_cnt & 0x1) ^ 0x1);
        
          _va2_vr_vp_6276_subtitle_trigger_buffer = cb->sub_dst_fb_addr_array[iIndex].u4_fb_addr_plane0;
        }

        kal_retrieve_eg_events(cb->EventID, TASK_WAIT_SUB_TITLE_FRAME_DONE_HISR_SET, KAL_AND_CONSUME, &u4Flags, KAL_NO_SUSPEND);
        visual_active_hisr(VISUAL_RENDERER_TRIGGER_DISPLAY_HISR_ID);
        kal_retrieve_eg_events(cb->EventID, TASK_WAIT_SUB_TITLE_FRAME_DONE_HISR_SET, KAL_AND_CONSUME, &u4Flags, KAL_SUSPEND);
      }
      cb->IsSubtitleBusy = KAL_FALSE;
    }
  }
}


static kal_uint32 
_va2_vr_vp_6276_render_subtitle_frame_buffer(
  va2_comp_video_renderer_cb_t *cb, kal_bool blocking)
{
  VA2_VIDEO_FRAME_T *video_frame;
  va2_util_buf_hdr_q_item_t *curr_dspl_buf_hdr;
  video_renderer_subtitle_render_config_t exec_param;
  kal_uint32 save_irq_mask;

  if ((NULL == cb) || 
      (NULL == cb->sub_vr_q_handle.curr_dspl_buf_hdr))
  {
    ASSERT(0); // incorrect param
  }

  curr_dspl_buf_hdr = cb->sub_vr_q_handle.curr_dspl_buf_hdr;

  if (KAL_TRUE == cb->trigger_display)
  {
    if (KAL_FALSE == _va2_comp_vr_have_config_lcd)
    {
      ASSERT(0); // LCD must already be configed if it's in HW trigger mode
    }
  }

  // get frame data...
  video_frame = (VA2_VIDEO_FRAME_T*) curr_dspl_buf_hdr->buffer_header.pPrivateData;
  ASSERT(NULL != video_frame);
  kal_mem_cpy(&(cb->sub_src_size), &(video_frame->r_fb_size), sizeof(VA2_FRAME_SIZE_T));
  kal_mem_cpy(&(cb->sub_src_fb_addr), &(video_frame->r_fb_addr), sizeof(VA2_FRAME_BUFFER_ADDRESS_T));
  kal_mem_cpy(&(cb->sub_src_color_format), &(video_frame->eFrameColorFmt), sizeof(VA2_VIDEO_RENDERER_COLOR_FORMAT_T));

  // if source size is not equal to dst size, drop current frame render process
  // this is to prevent unsync subtitle frame being drawn
  // !! currently we only support subtitle render without resize
  if ((cb->sub_src_size.u4_width != cb->sub_dst_size.u4_width) ||
      (cb->sub_src_size.u4_height != cb->sub_dst_size.u4_height))
  {return KAL_FALSE;}

  save_irq_mask = SaveAndSetIRQMask();
  if (KAL_TRUE == cb->IsSubtitleBusy)
  {    
    RestoreIRQMask(save_irq_mask);
    return KAL_FALSE;    
  }
  else
  {
    cb->IsSubtitleBusy = KAL_TRUE;
  }
  RestoreIRQMask(save_irq_mask);

  va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_INTERNAL____SUBTITLE_RENDER, (kal_uint32) curr_dspl_buf_hdr);

  {
    // check all parameters and configs for triggering HW
    // temporary remove
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    //  5.1. config and start rgbRotator for subtitle rotation
    // if non-blocking mode, this is a VISUHISR process
    // need to confiure and send message to CAL task for subtitle rotation
    exec_param.cb = cb;
    exec_param.blocking = blocking;

    if (KAL_FALSE == blocking)
    {
      // send message to CAL & run on it.
      video_renderer_task_req_msg(
        "MOD_CAL",
        va2_vr_vp_6276_rotate_subtitle_frame,
        &exec_param,
        sizeof(video_renderer_subtitle_render_config_t));
    }
    // if blocking mode, there is no need to send message to CAL
    // call _va2_vr_vp_6276_rotate_subtitle_frame() directly
    else
    {
      va2_vr_vp_6276_rotate_subtitle_frame(&exec_param);
    }
      
    return cb->sub_dst_fb_addr_array[0].u4_fb_addr_plane0;
  }
} // end of _va2_vr_vp_6276_render_display_frame_buffer


void
va2_vr_vp_subtitle_restore_source_hdlr(
  void* param)
{
  kal_uint32 *exec_param = (kal_uint32*)param;
  va2_comp_video_renderer_cb_t *cb = (va2_comp_video_renderer_cb_t *)(*exec_param);

  // Set Element source to subtitle stream source
  wfcMMSetElementAttribi((WFCDevice) cb->sub_display_surface.dspl_dev_handle, 
                         (WFCElement) cb->sub_display_surface.dspl_element_handle, 
                         WFC_ELEMENT_SOURCE, (WFCint) _va2_vr_vp_6276_ddv2_sub_src);
    
  // move Commit process to the timing before change subtitle display buffer
  // This is to ensure that before new subtitle display buffer is ready, 
  // old subtitle display buffer won't be shown on screen.
  _va2_vr_vp_6276_sub_src_committed = KAL_FALSE;
  
  va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_API_________EMPTY_THIS_BUFFER__SUBTITLE_SOURCE_RESTORE, (kal_uint32) 0x1);
}


void
va2_vr_vp_subtitle_remove_source_hdlr(
  void* param)
{
  kal_uint32 *exec_param = (kal_uint32*)param;
  va2_comp_video_renderer_cb_t *cb = (va2_comp_video_renderer_cb_t *)(*exec_param);

  // Set Element source to NULL
  wfcMMSetElementAttribi((WFCDevice) cb->sub_display_surface.dspl_dev_handle, 
                         (WFCElement) cb->sub_display_surface.dspl_element_handle, 
                         WFC_ELEMENT_SOURCE, WFC_INVALID_HANDLE);
        
  wfcMMCommit((WFCDevice) cb->sub_display_surface.dspl_dev_handle, 
              (WFCContext) cb->sub_display_surface.dspl_ctx_handle, 
              (WFCElement) cb->sub_display_surface.dspl_element_handle, WFC_COMMIT_ELEMENT);                

  if (NULL != _va2_vr_vp_6276_subtitle_trigger_buffer)
  {
    //clear the previous prepared subtitle display buffer because subtitle is not going to show
    _va2_vr_vp_6276_subtitle_trigger_buffer = NULL;
  }
  
  va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_API_________EMPTY_THIS_BUFFER__SUBTITLE_SOURCE_REMOVAL, (kal_uint32) 0x0);
}


static void 
_va2_vr_vp_6276_subtitle_source_operation(
  va2_comp_video_renderer_cb_t *cb, kal_bool isSubtitleShow)
{
  void (*ptr_WfcSrcOpFunc)(void *) = NULL;
  kal_uint32 exec_param;

  if (KAL_TRUE == isSubtitleShow)
  {
    ptr_WfcSrcOpFunc = va2_vr_vp_subtitle_restore_source_hdlr;
  }
  else
  {
    ptr_WfcSrcOpFunc = va2_vr_vp_subtitle_remove_source_hdlr;
  }
  
  // send message to CAL & run on it.
  exec_param = (kal_uint32)cb;
  video_renderer_task_req_msg(
    "MOD_CAL",
    ptr_WfcSrcOpFunc,
    &exec_param,
    sizeof(va2_comp_video_renderer_cb_t*));
}


static void
_va2_vr_vp_6276_get_subtitle_frame(
  va2_comp_video_renderer_cb_t *cb)
{

  if (VIDEO_RENDERER_VIDEO_SUBTITLE_PLAYBACK == cb->renderer_type &&
      NULL != cb->sub_dst_fb_addr_array[0].u4_fb_addr_plane0)
  {
#if defined (VIDEO_RENDERER_SUPPORT_MULTIPLE_VIDEO_FRAME)
    kal_uint32 save_irq_mask;

    // get the latest subtitle frame buffer
    if (0 != cb->sub_vr_q_handle.to_be_processed_q.size)
    {  
      save_irq_mask = SaveAndSetIRQMask();
      va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->sub_vr_q_handle));
      RestoreIRQMask(save_irq_mask);
    }
#endif
  
    // if 1. current no subtitle frame for render
    //    2. current subtitle frame is silent frame
    //   => clear the display buffer to transparent
    if (NULL == cb->sub_vr_q_handle.curr_dspl_buf_hdr ||
        (NULL != cb->sub_vr_q_handle.curr_dspl_buf_hdr &&
         VIDEO_BUFFERFLAG_SILENT == cb->sub_vr_q_handle.curr_dspl_buf_hdr->buffer_header.eFlags))
    {        
      kal_uint32 size = cb->sub_dst_fb_size.u4_width * 
                        cb->sub_dst_fb_size.u4_height * 
                        va2_util_get_bpp(cb->sub_dst_color_format);
  
      if (VIDEO_RENDERER_COLOR_RGB565 == cb->sub_dst_color_format)
      {/*do nothing*/}
      else if (VIDEO_RENDERER_COLOR_ARGB8888 == cb->sub_dst_color_format)
      {
        kal_mem_set((void*) cb->sub_dst_fb_addr_array[0].u4_fb_addr_plane0, 0x0, size);  //transparent for ARGB8888
      }
      else
      {
        ASSERT(0);
      }
      va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_DEBUG_______NO_SUBTITLE_FRAME_TO_DRAW, 0);
    }
    else
    {    
      // get Subtitle Frame
      _va2_vr_render_subtitle_buffer_cnt = 0;
      // clear subtitle trigger buffer to avoid render to wrong subtitle display buffer
      _va2_vr_vp_6276_subtitle_trigger_buffer = NULL;
      _va2_vr_vp_6276_render_subtitle_frame_buffer(cb, KAL_TRUE);
    }
  }  
}
#endif


// function to get Multimedia Display Image format
// Input: DisplayImageFormat for MM color format, *image_format to write result
// Output: bpp value for the color format
OWFint GetRendererDisplayImageFMT(
  VA2_VIDEO_RENDERER_COLOR_FORMAT_T DisplayImageFormat, OWF_IMAGE_FORMAT *image_format)
{
    OWFint pixel_size = 0;
    image_format->linear = OWF_FALSE;
    image_format->premultiplied = OWF_FALSE;
    image_format->rowPadding = 0;

    switch(DisplayImageFormat)
    {
    case VIDEO_RENDERER_COLOR_RGB565:
      image_format->pixelFormat= OWF_IMAGE_RGB565;
      pixel_size = 2;
    break;
    
    case VIDEO_RENDERER_COLOR_RGB888:
      image_format->pixelFormat = OWF_IMAGE_RGB888;
      pixel_size = 3;
    break;
    
    case VIDEO_RENDERER_COLOR_BGR888:
      image_format->pixelFormat = OWF_IMAGE_BGR888;
      pixel_size = 3;
    break;
    
    case VIDEO_RENDERER_COLOR_ARGB8888:
      image_format->pixelFormat = OWF_IMAGE_ARGB8888;
      pixel_size = 4;
    break;
        
    case VIDEO_RENDERER_COLOR_PACKED_UYVY422:
      image_format->pixelFormat = OWF_IMAGE_UYVY;
      pixel_size = 2;
    break;
    
    default:
      VRNDRR_DD_ASSERT(0);
    break;
    }
    return pixel_size;
}


/**
 *  \remarks After this function, the rotation/flip of Video Renderer might be changed...
 */
static void 
_va2_vr_vp_6276_config_n_activate_ddv2( 
  va2_comp_video_renderer_cb_t *cb, kal_bool isVideoLayer)
{
#if defined(DRV_DISPLAY_DRIVER_V2)
  kal_check_stack();

  // TODO: [m] Which variable can decide if display needs to work? 
  {
    WFCint displayInputWidth, displayInputHeight; // The output width/height of MM...
    WFCRotation layerRotation = WFC_ROTATION_0;
    OWFNativeStreamType ddv2_stream;
    WFCSource ddv2_src;

#if defined(__VIDEO_SUBTITLE_SUPPORT__)
    if (KAL_FALSE == isVideoLayer)
    {
      _va2_vr_vp_6276_ddv2_dev = (WFCDevice) cb->sub_display_surface.dspl_dev_handle;
      _va2_vr_vp_6276_ddv2_ctx = (WFCContext) cb->sub_display_surface.dspl_ctx_handle;
      _va2_vr_vp_6276_ddv2_element = (WFCElement) cb->sub_display_surface.dspl_element_handle;
    }
    else
#endif
    {
      _va2_vr_vp_6276_ddv2_dev = (WFCDevice) cb->display_surface.dspl_dev_handle;
      _va2_vr_vp_6276_ddv2_ctx = (WFCContext) cb->display_surface.dspl_ctx_handle;
      _va2_vr_vp_6276_ddv2_element = (WFCElement) cb->display_surface.dspl_element_handle;
    }

    if ((WFC_INVALID_HANDLE == _va2_vr_vp_6276_ddv2_dev) || 
        (WFC_INVALID_HANDLE == _va2_vr_vp_6276_ddv2_ctx) || 
        (WFC_INVALID_HANDLE == _va2_vr_vp_6276_ddv2_element))
    {
      VRNDRR_DD_ASSERT(0); // TODO: [m] remove this after IT done...need error handling...
    }

    // Check if this element is a video layer...for debug only and can be removed for last QC stage...
    if (WFC_FALSE == wfcGetElementAttribi(_va2_vr_vp_6276_ddv2_dev, _va2_vr_vp_6276_ddv2_element, WFC_ELEMENT_VIDEO_LAYER_MTK))
    {
      // TODO: [m] Make GDI add this line...
      wfcMMSetElementAttribi(_va2_vr_vp_6276_ddv2_dev, _va2_vr_vp_6276_ddv2_element, WFC_ELEMENT_VIDEO_LAYER_MTK, WFC_TRUE);
      //VRNDRR_DD_ASSERT(0);
    }

    // sync mode need to be set once only and sync element need to be set to video layer
    if (KAL_TRUE == isVideoLayer)
    {
      wfcMMSetContextAttribi(_va2_vr_vp_6276_ddv2_dev, _va2_vr_vp_6276_ddv2_ctx, WFC_CONTEXT_AUTONOMOUS_SYNC_MODE_MTK, (WFCint) WFC_AUTONOMOUS_SYNC_TO_ELEMENT);
      wfcMMSetContextAttribi(_va2_vr_vp_6276_ddv2_dev, _va2_vr_vp_6276_ddv2_ctx, WFC_CONTEXT_AUTONOMOUS_PERIOD_MTK, (WFCint) 30);
      wfcMMSetContextAttribi(_va2_vr_vp_6276_ddv2_dev, _va2_vr_vp_6276_ddv2_ctx, WFC_CONTEXT_AUTONOMOUS_SYNC_ELEMENT_MTK, (WFCint) _va2_vr_vp_6276_ddv2_element);
      wfcMMSetContextAttribi(_va2_vr_vp_6276_ddv2_dev, _va2_vr_vp_6276_ddv2_ctx, WFC_CONTEXT_CURRENT_REFRESH_RATE_MTK, 0);
    }

    // Derive the output width/height of MDP, which might be the input width height of Display
    // Need to take rotation into consideration later...
#if defined(__VIDEO_SUBTITLE_SUPPORT__)
    if (KAL_FALSE == isVideoLayer)
    {
      displayInputWidth = cb->sub_dst_size.u4_width;
      displayInputHeight = cb->sub_dst_size.u4_height;
    }
    else
#endif
    {
      displayInputWidth = cb->dst_size.u4_width;
      displayInputHeight = cb->dst_size.u4_height;
    }

    // Config Display Rotation angle & flip
    {     
      layerRotation = (WFCRotation) 
        wfcGetElementAttribi(_va2_vr_vp_6276_ddv2_dev, _va2_vr_vp_6276_ddv2_element, WFC_ELEMENT_SOURCE_ROTATION);
      
      //layerFlip = (WFCboolean)
      //  wfcGetElementAttribi(_va2_vr_vp_6276_ddv2_dev, _va2_vr_vp_6276_ddv2_element, WFC_ELEMENT_SOURCE_FLIP);

      wfcMMSetElementAttribi(_va2_vr_vp_6276_ddv2_dev, _va2_vr_vp_6276_ddv2_element, WFC_ELEMENT_SOURCE_ROTATION, WFC_ROTATION_0);
      //wfcMMSetElementAttribi(_va2_vr_vp_6276_ddv2_dev, _va2_vr_vp_6276_ddv2_element, WFC_ELEMENT_SOURCE_FLIP, WFC_FALSE);
    }
    
#if defined (__MAIN_LCM_SCANLINE_ROTATION_0__)
    // do nothing
#elif defined (__MAIN_LCM_SCANLINE_ROTATION_90__)
    if (cb->display_rotate_flip.u2_cw_rotate_angle >= 90)
    {cb->display_rotate_flip.u2_cw_rotate_angle -= 90;}
    else
    {cb->display_rotate_flip.u2_cw_rotate_angle = cb->display_rotate_flip.u2_cw_rotate_angle + 360 - 90;}
#elif defined (__MAIN_LCM_SCANLINE_ROTATION_180__)
    if (cb->display_rotate_flip.u2_cw_rotate_angle >= 180)
    {cb->display_rotate_flip.u2_cw_rotate_angle -= 180;}
    else
    {cb->display_rotate_flip.u2_cw_rotate_angle = cb->display_rotate_flip.u2_cw_rotate_angle + 360 - 180;}
#elif defined (__MAIN_LCM_SCANLINE_ROTATION_270__)
    if (cb->display_rotate_flip.u2_cw_rotate_angle >= 270)
    {cb->display_rotate_flip.u2_cw_rotate_angle -= 270;}
    else
    {cb->display_rotate_flip.u2_cw_rotate_angle = cb->display_rotate_flip.u2_cw_rotate_angle + 360 - 270;}
#endif  
            
    // calculate Video Renderer rotate angle according to Video Frame rotate angle and UI rotate angle
    // Video Frame rotate angle is extracted from Video Rotation Tag
    va2_util_calculate_total_rotate_angle_n_flip(cb->video_frame_rotate_flip,
                                                 cb->display_rotate_flip,
                                                 &(cb->rotate_flip));

    if ((90 == cb->display_rotate_flip.u2_cw_rotate_angle) || 
        (270 == cb->display_rotate_flip.u2_cw_rotate_angle))
    {
      // Swap width and height if MDP rotate 90 or 270 degree...
      displayInputWidth ^= displayInputHeight;
      displayInputHeight ^= displayInputWidth;
      displayInputWidth ^= displayInputHeight;

      // Frame buffer is actually rotated
#if defined(__VIDEO_SUBTITLE_SUPPORT__)
      if (KAL_FALSE == isVideoLayer)
      {
        cb->sub_dst_fb_size.u4_height ^= cb->sub_dst_fb_size.u4_width;
        cb->sub_dst_fb_size.u4_width ^= cb->sub_dst_fb_size.u4_height;
        cb->sub_dst_fb_size.u4_height ^= cb->sub_dst_fb_size.u4_width;
      }
      else
#endif
      {
        cb->dst_fb_size.u4_height ^= cb->dst_fb_size.u4_width;
        cb->dst_fb_size.u4_width ^= cb->dst_fb_size.u4_height;
        cb->dst_fb_size.u4_height ^= cb->dst_fb_size.u4_width;
      }
    }
    
    if (KAL_FALSE == _va2_vr_vp_6276_is_hw_layer_setting_modified_by_VR(&layerRotation))
    // Config Display Source width/height (The output of MDP) and source clip/pitch
    //if (KAL_FALSE == cb->bypass_hw_layer_src_rect)
    {
      WFCint srcRect[4];
      WFCint ClipX, ClipY, Width, Height;

      wfcGetElementAttribiv(_va2_vr_vp_6276_ddv2_dev, _va2_vr_vp_6276_ddv2_element, WFC_ELEMENT_SOURCE_RECTANGLE, 4, &srcRect[0]);

      if (90 == cb->display_rotate_flip.u2_cw_rotate_angle)
      {
        ClipX = displayInputWidth - srcRect[1] - srcRect[3];
        ClipY = srcRect[0];
        Width = srcRect[3];
        Height = srcRect[2];
      }
      else if (270 == cb->display_rotate_flip.u2_cw_rotate_angle)
      {
        ClipX = srcRect[1];
        ClipY = displayInputHeight - srcRect[0] - srcRect[2];
        Width = srcRect[3];
        Height = srcRect[2];
      }
      else if (180 == cb->display_rotate_flip.u2_cw_rotate_angle)
      {
        ClipX = displayInputWidth - srcRect[1] - srcRect[3];
        ClipY = displayInputHeight - srcRect[0] - srcRect[2];
        Width = srcRect[2];
        Height = srcRect[3];
      }
      else
      {
        ClipX = srcRect[0];
        ClipY = srcRect[1];
        Width = srcRect[2];
        Height = srcRect[3];
      }
      srcRect[0] = ClipX;
      srcRect[1] = ClipY;
      srcRect[2] = Width;
      srcRect[3] = Height;
      wfcMMSetElementAttribiv(_va2_vr_vp_6276_ddv2_dev, _va2_vr_vp_6276_ddv2_element, WFC_ELEMENT_SOURCE_RECTANGLE, 4, &srcRect[0]);
    }
    else
    {
      cb->bypass_hw_layer_src_rect = KAL_FALSE;
    }

    // Create stream...
    {
      OWF_IMAGE_FORMAT imageFormat;
      kal_uint32 bufs[2];
      VA2_VIDEO_RENDERER_COLOR_FORMAT_T color_format;

#if defined(__VIDEO_SUBTITLE_SUPPORT__)
      if (KAL_FALSE == isVideoLayer)
      {
        color_format = cb->sub_dst_color_format;      
      }
      else
#endif
      {
        color_format = cb->dst_color_format;
      }

      // convert the Video Renderer color format to WFC color format
      GetRendererDisplayImageFMT(color_format, &imageFormat);

#if defined(__VIDEO_SUBTITLE_SUPPORT__)
      if (KAL_FALSE == isVideoLayer)
      {
        _va2_vr_vp_6276_sub_dspl_fbs[0][0] = bufs[0] = cb->sub_dst_fb_addr_array[0].u4_fb_addr_plane0;
        _va2_vr_vp_6276_sub_dspl_fbs[1][0] = bufs[1] = cb->sub_dst_fb_addr_array[1].u4_fb_addr_plane0;
      }
      else
#endif
      {
        _va2_vr_vp_6276_vid_dspl_fbs[0][0] = bufs[0] = cb->dst_fb_addr_array[0].u4_fb_addr_plane0;
        _va2_vr_vp_6276_vid_dspl_fbs[1][0] = bufs[1] = cb->dst_fb_addr_array[1].u4_fb_addr_plane0;
      }

      // TODO: [m] When to destroy the stream? Where is the exit function?
      // TODO: [o] magical number here...
      ddv2_stream = 
        owfNativeStreamCreateImageStreamEx((OWFint) displayInputWidth, 
                                           (OWFint) displayInputHeight, 
                                           &imageFormat, (OWFint) 2, (void**) &bufs[0]);

#if defined(__VIDEO_SUBTITLE_SUPPORT__)
      if (KAL_FALSE == isVideoLayer)
      {
        _va2_vr_vp_6276_ddv2_sub_stream = ddv2_stream;
      }
      else
#endif
      {
        _va2_vr_vp_6276_ddv2_vid_stream = ddv2_stream;
      }

      // This code segment is used to do buffer control...
      {
        void * bufPtr;
        OWFNativeStreamBuffer buf;
        kal_uint32 i;

        buf = owfNativeStreamAcquireWriteBuffer(ddv2_stream);
        bufPtr = owfNativeStreamGetBufferPtr(ddv2_stream, buf);
        VRNDRR_DD_ASSERT(NULL != bufPtr);

#if defined(__VIDEO_SUBTITLE_SUPPORT__)
        if (KAL_FALSE == isVideoLayer)
        {
#if 1
          for (i=0; i<2; i++)
          {
            if (_va2_vr_vp_6276_sub_dspl_fbs[i][0] == (kal_uint32) bufPtr)
            {
              _va2_vr_vp_6276_sub_dspl_fbs[i][1] = (kal_uint32) buf;
              _va2_vr_vp_6276_sub_dspl_fbs[i^1][1] = owfNativeStreamAcquireWriteBuffer(ddv2_stream);
              break;
            }
          }
#else
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
        }
        else
#endif
        {
#if 1
          for (i=0; i<2; i++)
          {
            if (_va2_vr_vp_6276_vid_dspl_fbs[i][0] == (kal_uint32) bufPtr)
            {
              _va2_vr_vp_6276_vid_dspl_fbs[i][1] = (kal_uint32) buf;
              _va2_vr_vp_6276_vid_dspl_fbs[i^1][1] = owfNativeStreamAcquireWriteBuffer(ddv2_stream);
              break;
            }
          }
#else
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
        }
      }

      ddv2_src = wfcCreateSourceFromStream(_va2_vr_vp_6276_ddv2_dev, _va2_vr_vp_6276_ddv2_ctx, (WFCNativeStreamType) ddv2_stream, NULL);
#if defined(__VIDEO_SUBTITLE_SUPPORT__)
      if (KAL_FALSE == isVideoLayer)
      {
        _va2_vr_vp_6276_ddv2_sub_src = ddv2_src;
      }
      else
#endif
      {
        _va2_vr_vp_6276_ddv2_vid_src = ddv2_src;
      }

      // TODO: [m] Need an API to set buffers into the stream...

      if (WFC_INVALID_HANDLE == ddv2_src)
      {
        VRNDRR_DD_ASSERT(0); // TODO: [m] remove this after IT done...need error handling...
      }
    }

    // Set Element source
    wfcMMSetElementAttribi(_va2_vr_vp_6276_ddv2_dev, _va2_vr_vp_6276_ddv2_element, WFC_ELEMENT_SOURCE, (WFCint) ddv2_src);

    // TODO: [m] If camera preview only uses double display frame buffer, DDv2 needs to sync to content provider...since camera cannot wait...

    // Add cb function, only video layer need this
    if (KAL_TRUE == isVideoLayer)
    {
      WFCint array[4];
      array[0] = (WFCint) WFC_CONTEXT_EVENT_COMPOSITION_FINISH_ALWAYS_CALLBACK_MTK;
      array[1] = (WFCint) _va2_vr_vp_6276_wfc_frame_done_cb;
      array[2] = (WFCint) cb;
      array[3] = (WFCint) WFC_TRUE;
      wfcMMSetContextAttribiv(_va2_vr_vp_6276_ddv2_dev, _va2_vr_vp_6276_ddv2_ctx, WFC_CONTEXT_CALLBACK_MTK, 4, &array[0]);
    }

    // Commmit
    wfcMMCommit(_va2_vr_vp_6276_ddv2_dev, _va2_vr_vp_6276_ddv2_ctx, _va2_vr_vp_6276_ddv2_element, WFC_COMMIT_CONTEXT_AND_ELEMENT);                

   // clean display buffer for INSIDE mode because INSIDE mode won't draw to the full display buffer
   if (KAL_TRUE == isVideoLayer &&
       VIDEO_RENDERER_RENDER_MODE_TOUCH_WINDOW_FROM_INSIDE == cb->render_mode)
   {
      kal_uint32 size = cb->dst_fb_size.u4_width * 
                        cb->dst_fb_size.u4_height * 
                        va2_util_get_bpp(cb->dst_color_format);
      kal_uint32 addr;
      if (VIDEO_RENDERER_COLOR_RGB565 == cb->dst_color_format)
      {
        if (0x0 != (addr = cb->dst_fb_addr_array[0].u4_fb_addr_plane0))
        {
          kal_mem_set((void*) addr, 0x0, size);  //black for RGB565
        }
        if (0x0 != (addr = cb->dst_fb_addr_array[1].u4_fb_addr_plane0))
        {
          kal_mem_set((void*) addr, 0x0, size);  //black for RGB565
        }
      }
      else if (VIDEO_RENDERER_COLOR_PACKED_UYVY422 == cb->dst_color_format)
      {
        if (0x0 != (addr = cb->dst_fb_addr_array[0].u4_fb_addr_plane0))
        {
          va2_util_clear_uyvy_buffer_black((kal_uint32*)addr, size);  //black for UYVY422 
        }
        if (0x0 != (addr = cb->dst_fb_addr_array[1].u4_fb_addr_plane0))
        {
          va2_util_clear_uyvy_buffer_black((kal_uint32*)addr, size);  //black for UYVY422 
        }
      }
    }
  }

  kal_check_stack();
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)
}

static void 
_va2_vr_vp_6276_stop_n_deactivate_ddv2( 
  va2_comp_video_renderer_cb_t *cb, kal_bool isVideoLayer)
{
#if defined(DRV_DISPLAY_DRIVER_V2)
  OWFNativeStreamType ddv2_stream;
  WFCSource ddv2_src;

  kal_check_stack();

#if defined(__VIDEO_SUBTITLE_SUPPORT__)
  if (KAL_FALSE == isVideoLayer)
  {
    _va2_vr_vp_6276_ddv2_dev = (WFCDevice) cb->sub_display_surface.dspl_dev_handle;
    _va2_vr_vp_6276_ddv2_ctx = (WFCContext) cb->sub_display_surface.dspl_ctx_handle;
    _va2_vr_vp_6276_ddv2_element = (WFCElement) cb->sub_display_surface.dspl_element_handle;
    ddv2_stream = _va2_vr_vp_6276_ddv2_sub_stream;
  }
  else
#endif
  {
    _va2_vr_vp_6276_ddv2_dev = (WFCDevice) cb->display_surface.dspl_dev_handle;
    _va2_vr_vp_6276_ddv2_ctx = (WFCContext) cb->display_surface.dspl_ctx_handle;
    _va2_vr_vp_6276_ddv2_element = (WFCElement) cb->display_surface.dspl_element_handle;
    ddv2_stream = _va2_vr_vp_6276_ddv2_vid_stream;
  }

  // TODO: [m] Which variable can decide if display needs to work? 
  if (OWF_INVALID_HANDLE != ddv2_stream)
  {
    if ((WFC_INVALID_HANDLE == _va2_vr_vp_6276_ddv2_dev) || 
        (WFC_INVALID_HANDLE == _va2_vr_vp_6276_ddv2_ctx) || 
        (WFC_INVALID_HANDLE == _va2_vr_vp_6276_ddv2_element))
    {
      VRNDRR_DD_ASSERT(0);
    }

    // check the last video frame has been flash out
    // TODO: [optional] Move this to the top most of this function...
    if (KAL_TRUE == isVideoLayer)
    {
      while(_va2_vr_vp_6276_lcd_frame_done == KAL_FALSE)
      {
        kal_sleep_task(1);
      }
    
      // Remove cb function
      {
        WFCint array[4];
        array[0] = (WFCint) WFC_CONTEXT_EVENT_COMPOSITION_FINISH_ALWAYS_CALLBACK_MTK;
        array[1] = (WFCint) _va2_vr_vp_6276_wfc_frame_done_cb;
        array[2] = (WFCint) cb;
        array[3] = (WFCint) WFC_FALSE;
        wfcMMSetContextAttribiv(_va2_vr_vp_6276_ddv2_dev, _va2_vr_vp_6276_ddv2_ctx, WFC_CONTEXT_CALLBACK_MTK, 4, &array[0]);
      }
    
      // Sync to timer...
      // TODO: [must] should be moved after image source is inserted.
      {
        wfcMMSetContextAttribi(_va2_vr_vp_6276_ddv2_dev, _va2_vr_vp_6276_ddv2_ctx, WFC_CONTEXT_AUTONOMOUS_SYNC_MODE_MTK, (WFCint) WFC_AUTONOMOUS_SYNC_TO_TIMER);
        wfcMMSetContextAttribi(_va2_vr_vp_6276_ddv2_dev, _va2_vr_vp_6276_ddv2_ctx, WFC_CONTEXT_AUTONOMOUS_PERIOD_MTK, (WFCint) 0);
        wfcMMSetContextAttribi(_va2_vr_vp_6276_ddv2_dev, _va2_vr_vp_6276_ddv2_ctx, WFC_CONTEXT_AUTONOMOUS_SYNC_ELEMENT_MTK, (WFCint) 0);
        wfcMMSetContextAttribi(_va2_vr_vp_6276_ddv2_dev, _va2_vr_vp_6276_ddv2_ctx, WFC_CONTEXT_CURRENT_REFRESH_RATE_MTK, 30);
      }
    }

    // Set an image source back to element
    {
      OWF_IMAGE image;
      VA2_VIDEO_RENDERER_COLOR_FORMAT_T dst_color_format;
      
      // TODO: Add an image sourece
#if defined(__VIDEO_SUBTITLE_SUPPORT__)
      if (KAL_FALSE == isVideoLayer)
      {
        ddv2_src = _va2_vr_vp_6276_ddv2_sub_img_src;
      }
      else
#endif
      {
        ddv2_src = _va2_vr_vp_6276_ddv2_vid_img_src;
      }

      if (ddv2_src != WFC_INVALID_HANDLE)
      {
        wfcDestroySource(_va2_vr_vp_6276_ddv2_dev, ddv2_src);
      }

#if defined(__VIDEO_SUBTITLE_SUPPORT__)
      if (KAL_FALSE == isVideoLayer)
      {
        // get subtitle frame
        _va2_vr_vp_6276_get_subtitle_frame(cb);
        image.data = (void*)cb->sub_dst_fb_addr_array[0].u4_fb_addr_plane0;        
      }
      else
#endif
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
#else
      // Render to first frame buffer...
      {
#if defined (VIDEO_RENDERER_SUPPORT_MULTIPLE_VIDEO_FRAME)
        kal_uint32 save_irq_mask;

        save_irq_mask = SaveAndSetIRQMask();
        if((0 != cb->vr_q_handle.to_be_processed_q.size))
        {
          // If only one frame is inserted in Run state, this action is to emulate 
          // the processing of the previous Bypass-Mode Frames.
          va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
        }
        RestoreIRQMask(save_irq_mask);
#endif

        // Try to guarantee the index is 0 before get buffer...
        _va2_vr_render_display_buffer_cnt = 0;

        _va2_vr_vp_6276_process_input_buffer(cb, KAL_TRUE, 1);
        image.data = (void*) cb->dst_fb_addr_array[0].u4_fb_addr_plane0;
      }
#endif

#if defined(__VIDEO_SUBTITLE_SUPPORT__)
      if (KAL_FALSE == isVideoLayer)
      {
        image.width = cb->sub_dst_fb_size.u4_width;
        image.height = cb->sub_dst_fb_size.u4_height;
        dst_color_format = cb->sub_dst_color_format;
      }
      else
#endif
      {
        image.width = cb->dst_fb_size.u4_width;
        image.height = cb->dst_fb_size.u4_height;
        dst_color_format = cb->dst_color_format;
      }

      // convert the Video Renderer color format to WFC color format
      image.pixelSize = GetRendererDisplayImageFMT(dst_color_format, &image.format);
      image.foreign = OWF_TRUE; // don't care.
      image.alpha = 0xFF;
      image.stride = image.width * image.pixelSize; /**< number of bytes per line */
      image.dataMax = image.stride * image.height; /* data buffer max size */

      // if image buffer address is NULL, it means currently no image need to be shown
      // set an invalid handle to layer source to bypass the blt of the layer
      if (NULL != image.data)
      {
        ddv2_src = wfcCreateSourceFromImage(_va2_vr_vp_6276_ddv2_dev, _va2_vr_vp_6276_ddv2_ctx, (WFCHandle) &image, NULL);
        VRNDRR_DD_ASSERT(ddv2_src != WFC_INVALID_HANDLE);
      }
      else
      {
        ddv2_src = NULL;
      }
      
#if defined(__VIDEO_SUBTITLE_SUPPORT__)
      if (KAL_FALSE == isVideoLayer)
      {
        _va2_vr_vp_6276_ddv2_sub_img_src = ddv2_src;
      }
      else
#endif
      {
        _va2_vr_vp_6276_ddv2_vid_img_src = ddv2_src;
      }

      wfcMMSetElementAttribi(_va2_vr_vp_6276_ddv2_dev, _va2_vr_vp_6276_ddv2_element, WFC_ELEMENT_SOURCE, ddv2_src);
      // commit the last frame image back to image source
      wfcMMCommit(_va2_vr_vp_6276_ddv2_dev, _va2_vr_vp_6276_ddv2_ctx, _va2_vr_vp_6276_ddv2_element, WFC_COMMIT_CONTEXT_AND_ELEMENT);                
    }

    // destroy the stream source used by VR
#if defined(__VIDEO_SUBTITLE_SUPPORT__)
    if (KAL_FALSE == isVideoLayer)
    {
      wfcDestroySource(_va2_vr_vp_6276_ddv2_dev, _va2_vr_vp_6276_ddv2_sub_src);
      _va2_vr_vp_6276_ddv2_sub_src = WFC_INVALID_HANDLE;
    }
    else
#endif
    {
      wfcDestroySource(_va2_vr_vp_6276_ddv2_dev, _va2_vr_vp_6276_ddv2_vid_src);
      _va2_vr_vp_6276_ddv2_vid_src = WFC_INVALID_HANDLE;
    }

    _va2_vr_vp_6276_ddv2_element = WFC_INVALID_HANDLE;
    _va2_vr_vp_6276_ddv2_ctx = WFC_INVALID_HANDLE;
    _va2_vr_vp_6276_ddv2_dev = WFC_INVALID_HANDLE;
    
    owfNativeStreamDestroy(ddv2_stream);
#if defined(__VIDEO_SUBTITLE_SUPPORT__)
    if (KAL_FALSE == isVideoLayer)
    {
      _va2_vr_vp_6276_ddv2_sub_stream = OWF_INVALID_HANDLE;
      kal_mem_set((void*) _va2_vr_vp_6276_sub_dspl_fbs, 0x0, sizeof(kal_uint32)*3*2);
    }
    else
#endif
    {
      _va2_vr_vp_6276_ddv2_vid_stream = OWF_INVALID_HANDLE;
      kal_mem_set((void*) _va2_vr_vp_6276_vid_dspl_fbs, 0x0, sizeof(kal_uint32)*3*2);
    }

  }
  kal_check_stack();
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)
}

static void
_va2_vr_vp_6276_trigger_display(
  kal_uint32 dspl_fb, 
  va2_comp_video_renderer_cb_t *cb)
{
#if defined(DRV_DISPLAY_DRIVER_V2)
  if ((KAL_TRUE == cb->trigger_display) && 
      (OWF_INVALID_HANDLE != _va2_vr_vp_6276_ddv2_vid_stream))
  {
    OWFNativeStreamBuffer buf;
    kal_uint32 i;

#if 1
    for (i=0; i<2; i++)
    {
      if (dspl_fb == _va2_vr_vp_6276_vid_dspl_fbs[i][0])
      {
        buf = (OWFNativeStreamBuffer) _va2_vr_vp_6276_vid_dspl_fbs[i][1];
        //set the lcd frame done flag to false only if trigger is valid
        if (buf == NULL)
        {return;}

        {
          kal_uint32 const saved_mask = SaveAndSetIRQMask();
          _va2_vr_vp_6276_lcd_frame_done = KAL_FALSE;
          RestoreIRQMask(saved_mask);
        }

        owfNativeStreamReleaseWriteBuffer(_va2_vr_vp_6276_ddv2_vid_stream, 
                                          buf/* (OWFNativeStreamBuffer) 0x100 */, 
                                          NULL /* (EGLDisplay) */, 
                                          NULL /* (EGLSyncKHR) */);
        _va2_vr_vp_6276_vid_dspl_fbs[i][1] = 0x0;
        if (0x0 == _va2_vr_vp_6276_vid_dspl_fbs[i^1][1])
        {
          _va2_vr_vp_6276_vid_dspl_fbs[i^1][1] = (kal_uint32) owfNativeStreamAcquireWriteBuffer(_va2_vr_vp_6276_ddv2_vid_stream);
        }
        break;
      }
    }
#else
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
  }
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)
}

/**
 *  @status OK
 *  @common VR.VP
 */
static kal_bool 
_va2_vr_vp_6276_check_src_params_configs(
  va2_comp_video_renderer_cb_t *cb)
{
  kal_bool fgRet = KAL_TRUE;
  ASSERT(NULL != cb);

  //VA2_VIDEO_RENDERER_COLOR_FORMAT_T         src_color_format;
  // TODO: Note this! Cannot remove...here to check if ever set
  if ((VIDEO_RENDERER_COLOR_DEFAULT_ERR == cb->src_color_format) || 
      (VIDEO_RENDERER_COLOR_MAX <= cb->src_color_format))
  {
    fgRet = KAL_FALSE;
  }

  //VA2_FRAME_BUFFER_ADDRESS_T                src_fb_addr;
  // TODO: Note this! alignment checking is left to MDP driver...
  if (0 == cb->src_fb_addr.u4_fb_addr_plane0)
  {
    fgRet = KAL_FALSE;
  }
  if ((VIDEO_RENDERER_COLOR_YUV444 <= cb->src_color_format) && 
      (VIDEO_RENDERER_COLOR_4X4_BLOCK_YUV420 >= cb->src_color_format))
  {
    if ((0 == cb->src_fb_addr.u4_fb_addr_plane1) || 
        (0 == cb->src_fb_addr.u4_fb_addr_plane2))
    {
      fgRet = KAL_FALSE;
    }
  }
  
  //VA2_FRAME_SIZE_T                          src_size;
  // TODO: Note this! Cannot remove...here to check if ever set
  // TODO: Note this! alignment checking is left to MDP driver...
  if ((0 == cb->src_size.u4_width) || 
      (0 == cb->src_size.u4_height))
  {
    fgRet = KAL_FALSE;
  }

  //VA2_CLIP_WINDOW_T                         src_clip;
  if (KAL_TRUE == cb->src_clip.b_clip_enable)
  {
    // TODO: Note this! Cannot remove...here to check if ever set
    ASSERT(cb->src_clip.u4_clip_top <= cb->src_clip.u4_clip_bottom);
    ASSERT(cb->src_clip.u4_clip_left <= cb->src_clip.u4_clip_right);
    if (((cb->src_size.u4_width-1) < cb->src_clip.u4_clip_right) || 
        ((cb->src_size.u4_height-1) < cb->src_clip.u4_clip_bottom) ||
         //chrono add for reject small video WH
         (cb->src_clip.u4_clip_bottom < 5) ||
         (cb->src_clip.u4_clip_right < 5))
    {
      fgRet = KAL_FALSE;
    }
  }
   return fgRet;
}

static kal_bool 
_va2_vr_vp_6276_check_dst_params_configs(
  va2_comp_video_renderer_cb_t *cb)
{
  kal_bool fgRet = KAL_TRUE;
  ASSERT(NULL != cb);

  //VA2_FRAME_SIZE_T                          dst_size;
  // TODO: Note this! Cannot remove...here to check if ever set
  if ((0 == cb->dst_size.u4_width) || 
      (0 == cb->dst_size.u4_height))
  {
    fgRet = KAL_FALSE;
  }

  //VA2_CLIP_WINDOW_T                         dst_clip;
  if (KAL_TRUE == cb->dst_clip.b_clip_enable)
  {
    // TODO: Note this! Cannot remove...here to check if ever set
    ASSERT(cb->dst_clip.u4_clip_top <= cb->dst_clip.u4_clip_bottom);
    ASSERT(cb->dst_clip.u4_clip_left <= cb->dst_clip.u4_clip_right);
    if (((cb->dst_size.u4_width-1) < cb->dst_clip.u4_clip_right) || 
        ((cb->dst_size.u4_height-1) < cb->dst_clip.u4_clip_bottom))
    {
      fgRet = KAL_FALSE;
    }
  }

  //va2_video_renderer_rotate_flip_t          rotate_flip;
  // TODO: Note this! Unnecessary here! default values is valid...
  
  //VA2_VIDEO_RENDERER_COLOR_FORMAT_T         dst_color_format;
  // TODO: Note this! Cannot remove...here to check if ever set
  if ((VIDEO_RENDERER_COLOR_DEFAULT_ERR == cb->dst_color_format) || 
      (VIDEO_RENDERER_COLOR_YUV444 <= cb->dst_color_format))
  {
    fgRet = KAL_FALSE;
  }

  //VA2_FRAME_SIZE_T                          dst_fb_size;
  if ((0 == cb->dst_fb_size.u4_width) || 
      (0 == cb->dst_fb_size.u4_height))
  {
    fgRet = KAL_FALSE;
  }
  
  //VA2_FRAME_BUFFER_ADDRESS_T                dst_fb_addr_array[VA2_COMP_VR_MAX_DSPL_FB_COUNT];
  // TODO: Note this! unnecessary! We use start address by default...

  //VA2_FRAME_BUFFER_ADDRESS_T                dst_fb_start_addr_array[VA2_COMP_VR_MAX_DSPL_FB_COUNT];
  // At least one frame...
  if (0x0 == cb->dst_fb_start_addr_array[0].u4_fb_addr_plane0)
  {
    fgRet = KAL_FALSE;
  }
  if ((VIDEO_RENDERER_COLOR_YUV444 <= cb->dst_color_format) && 
      (VIDEO_RENDERER_COLOR_4X4_BLOCK_YUV420 >= cb->dst_color_format))
  {
    if ((0 == cb->dst_fb_start_addr_array[0].u4_fb_addr_plane1) || 
        (0 == cb->dst_fb_start_addr_array[0].u4_fb_addr_plane2))
    {
      fgRet = KAL_FALSE;
    }
  }

  //kal_bool                                  trigger_display;
  // TODO: Note this! unnecessary! default value is valid.

  //va2_video_renderer_post_process_config_t  post_process;
  // TODO: Note this! unnecessary!
  
  //VA2_VIDEO_RENDERER_RENDER_MODE_T          render_mode;
  // TODO: Note this! unnecessary!
  
  //va2_video_renderer_display_surface_t      display_surface;
  // TODO: Note this! nothing to check...

  return fgRet;
}

/**
 *  @status OK
 *  @common VR.VP
 */
static kal_bool 
_va2_vr_vp_6276_check_params_configs(
  va2_comp_video_renderer_cb_t *cb)
{
  kal_bool fgRet;
  ASSERT(NULL != cb);

  // check source
  fgRet = _va2_vr_vp_6276_check_src_params_configs(cb);
  if (KAL_FALSE == fgRet)
  {
    return fgRet;
  }

  // check dst
  fgRet = _va2_vr_vp_6276_check_dst_params_configs(cb);
  return fgRet;
}


#define abs(a) (((a) < 0) ? (-(a)) : (a))

/**
 *  @status OK
 *  @common none
 */
static kal_bool 
_va2_vr_vp_6276_config_idp_by_render_mode(
  va2_comp_video_renderer_cb_t *cb, 
  VA2_VIDEO_FRAME_T *video_frame)
{
  kal_uint32 org_src_width = 0;
  kal_uint32 org_src_height = 0;
  kal_uint32 org_src_clip_top = 0;
  kal_uint32 org_src_clip_bottom = 0;
  kal_uint32 org_src_clip_left = 0;
  kal_uint32 org_src_clip_right = 0;

  if (0 != cb->src_aspect_ratio.i4AspectRatioWidth)
  {
    kal_uint32 width;
    if (0 < cb->src_aspect_ratio.i4AspectRatioWidth)
    {
      width = (cb->src_clip.u4_clip_right - cb->src_clip.u4_clip_left + 1) * cb->src_aspect_ratio.i4AspectRatioWidth;
      org_src_width = cb->src_size.u4_width * cb->src_aspect_ratio.i4AspectRatioWidth;
      org_src_clip_left = cb->src_clip.u4_clip_left * cb->src_aspect_ratio.i4AspectRatioWidth;
    }
    else
    {
      kal_uint32 Scale_x = abs(cb->src_aspect_ratio.i4AspectRatioWidth);
      width = (cb->src_clip.u4_clip_right - cb->src_clip.u4_clip_left + 1) / Scale_x;
      org_src_width = cb->src_size.u4_width / Scale_x;
      org_src_clip_left = cb->src_clip.u4_clip_left / Scale_x;
    }
    org_src_clip_right = org_src_clip_left + width - 1;
  }
  else
  {
    ASSERT(0);
  }

  if (0 != cb->src_aspect_ratio.i4AspectRatioHeight)
  {
    kal_uint32 height;
    if (0 < cb->src_aspect_ratio.i4AspectRatioHeight)
    {
      height = (cb->src_clip.u4_clip_bottom - cb->src_clip.u4_clip_top + 1) * cb->src_aspect_ratio.i4AspectRatioHeight;
      org_src_height = cb->src_size.u4_height * cb->src_aspect_ratio.i4AspectRatioHeight;
      org_src_clip_top = cb->src_clip.u4_clip_top * cb->src_aspect_ratio.i4AspectRatioHeight;
    }
    else
    {
      kal_uint32 Scale_y = abs(cb->src_aspect_ratio.i4AspectRatioHeight);
      height = (cb->src_clip.u4_clip_bottom - cb->src_clip.u4_clip_top + 1) / Scale_y;
      org_src_height = cb->src_size.u4_height / Scale_y;
      org_src_clip_top = cb->src_clip.u4_clip_top / Scale_y;
    }
    org_src_clip_bottom = org_src_clip_top + height - 1;
  }
  else
  {
    ASSERT(0);
  }

#if defined(VA2_RENDERER_VP_STEREO_VIDEO_SUPPORTED)
  if (VIDEO_RENDERER_3D_MODE_SIDE_BY_SIDE == cb->stereo_video.mode)
  {
    // when side by side mode, the output width after anaglyph computing is half
    // of original one, we must use (width * 2) for render mode computing

    org_src_width = org_src_width << 1;
    
    if (KAL_TRUE == cb->src_clip.b_clip_enable)
    {
      kal_uint32 width = (org_src_clip_right - org_src_clip_left + 1) << 1;
      org_src_clip_left = org_src_clip_left << 1;
      org_src_clip_right = org_src_clip_left + width - 1;
    }
  }
  else if (VIDEO_RENDERER_3D_MODE_TOP_DOWN == cb->stereo_video.mode)
  {
    // similar to side by side mode, but the strength direction is vertical
    org_src_height = org_src_height << 1;

    if (KAL_TRUE == cb->src_clip.b_clip_enable)
    {
      kal_uint32 height = (org_src_clip_bottom - org_src_clip_top + 1) << 1;
      org_src_clip_top = org_src_clip_top << 1;
      org_src_height = org_src_clip_top + height - 1;
    }
  }
#endif

  if (VIDEO_RENDERER_RENDER_MODE_TOUCH_WINDOW_FROM_INSIDE == cb->render_mode)
  {
    kal_uint32 src_clip_w, src_clip_h;
    kal_uint32 w_after_rot, h_after_rot;
    
    // no dst clipping
    cb->dst_clip.b_clip_enable = KAL_FALSE;
    
    // set dst_size according to rotation angle
    if ((90 == cb->rotate_flip.u2_cw_rotate_angle) || 
        (270 == cb->rotate_flip.u2_cw_rotate_angle))
    {
      cb->dst_size.u4_width = cb->dst_fb_size.u4_height;
      cb->dst_size.u4_height = cb->dst_fb_size.u4_width;
    }
    else
    {
      cb->dst_size.u4_width = cb->dst_fb_size.u4_width;
      cb->dst_size.u4_height = cb->dst_fb_size.u4_height;
    }

    // src clip window size
    if (KAL_TRUE == cb->src_clip.b_clip_enable)
    {
      src_clip_w = org_src_clip_right - org_src_clip_left + 1;
      src_clip_h = org_src_clip_bottom - org_src_clip_top + 1;
    }
    else
    {
      src_clip_w = org_src_width;
      src_clip_h = org_src_height;
    }
    ASSERT(0 != src_clip_w);
    ASSERT(0 != src_clip_h);

    // compute max. dst_size smaller than dst_fb_size to keep src_size ratio...
    {
      kal_uint32 h_ratio = (cb->dst_size.u4_width<<16)/src_clip_w;
      kal_uint32 v_ratio = (cb->dst_size.u4_height<<16)/src_clip_h;
      kal_uint32 temp;
      if (h_ratio < v_ratio)
      {
        // dst_w needs not to be changed...
        temp = cb->dst_size.u4_height;
        cb->dst_size.u4_height = ((((h_ratio*src_clip_h)>>16)+1)>>1)<<1;
        if (temp < cb->dst_size.u4_height) {cb->dst_size.u4_height = temp;}
        if (cb->dst_size.u4_height == 0) {cb->dst_size.u4_height = 2;}
      }
      else
      {
        // dst_h needs not to be changed...
        temp = cb->dst_size.u4_width;
        cb->dst_size.u4_width = ((((v_ratio*src_clip_w)>>16)+1)>>1)<<1;
        if (temp < cb->dst_size.u4_width) {cb->dst_size.u4_width = temp;}
        if (cb->dst_size.u4_width == 0) {cb->dst_size.u4_width = 2;}
      }
    }

    // compute the pitch start address according to rotation...
    if ((90 == cb->rotate_flip.u2_cw_rotate_angle) || 
        (270 == cb->rotate_flip.u2_cw_rotate_angle))
    {
      w_after_rot = cb->dst_size.u4_height;
      h_after_rot = cb->dst_size.u4_width;
    }
    else
    {
      w_after_rot = cb->dst_size.u4_width;
      h_after_rot = cb->dst_size.u4_height;
    }

    // compute pitch start address...
    {
      kal_uint32 dst_x = 0, dst_y = 0;
      kal_uint32 dst_start_offset;

      if (w_after_rot == cb->dst_fb_size.u4_width)
      {
        ASSERT(h_after_rot <= cb->dst_fb_size.u4_height);
        dst_x = 0;
        dst_y = (cb->dst_fb_size.u4_height - h_after_rot)>>1;
        // re-cauculate dst_y to 2x offset allignment
        if ((dst_y & 0x1) == 1)
        {
          dst_y--;
          
          if ((90 == cb->rotate_flip.u2_cw_rotate_angle) || 
              (270 == cb->rotate_flip.u2_cw_rotate_angle))
          {cb->dst_size.u4_width+=2;}
          else
          {cb->dst_size.u4_height+=2;}
        }
      }
      else if (h_after_rot == cb->dst_fb_size.u4_height)
      {
        ASSERT(w_after_rot <= cb->dst_fb_size.u4_width);
        dst_x = (cb->dst_fb_size.u4_width - w_after_rot)>>1;
        // re-cauculate dst_x to 2x offset allignment
        if ((dst_x & 0x1) == 1)
        {
          dst_x--;
          
          if ((90 == cb->rotate_flip.u2_cw_rotate_angle) || 
              (270 == cb->rotate_flip.u2_cw_rotate_angle))
          {cb->dst_size.u4_height+=2;}
          else
          {cb->dst_size.u4_width+=2;}
        }
        dst_y = 0;
      }
      else
      {
        ASSERT(0);
      }
      dst_start_offset = (cb->dst_fb_size.u4_width*dst_y + dst_x) * va2_util_get_bpp(cb->dst_color_format);
      {
        kal_uint32 i = VA2_COMP_VR_MAX_DSPL_FB_COUNT;
        for (; i-- != 0; )
        {
          cb->dst_fb_start_addr_array[i].u4_fb_addr_plane0 = cb->dst_fb_addr_array[i].u4_fb_addr_plane0 + dst_start_offset;
          cb->dst_fb_start_addr_array[i].u4_fb_addr_plane1 = 0;
          cb->dst_fb_start_addr_array[i].u4_fb_addr_plane2 = 0;
        }
      }
    }
    
  }
  else if (VIDEO_RENDERER_RENDER_MODE_TOUCH_WINDOW_FROM_OUTSIDE == cb->render_mode)
  {
    kal_uint32 src_clip_w, src_clip_h;
    kal_uint32 w_after_rot, h_after_rot;

    // set dst_size according to rotation angle
    if ((90 == cb->rotate_flip.u2_cw_rotate_angle) || 
        (270 == cb->rotate_flip.u2_cw_rotate_angle))
    {
      cb->dst_size.u4_width = cb->dst_fb_size.u4_height;
      cb->dst_size.u4_height = cb->dst_fb_size.u4_width;
    }
    else
    {
      cb->dst_size.u4_width = cb->dst_fb_size.u4_width;
      cb->dst_size.u4_height = cb->dst_fb_size.u4_height;
    }

    // src clip window size
    if (KAL_TRUE == cb->src_clip.b_clip_enable)
    {
      src_clip_w = org_src_clip_right - org_src_clip_left + 1;
      src_clip_h = org_src_clip_bottom - org_src_clip_top + 1;
    }
    else
    {
      src_clip_w = org_src_width;
      src_clip_h = org_src_height;
    }
    ASSERT(0 != src_clip_w);
    ASSERT(0 != src_clip_h);

    // compute min. dst_size bigger than dst_fb_size to keep src_size ratio...
    {
      kal_uint32 h_ratio = (cb->dst_size.u4_width<<16)/src_clip_w;
      kal_uint32 v_ratio = (cb->dst_size.u4_height<<16)/src_clip_h;
      if (h_ratio > v_ratio)
      {
        // dst_w needs not to be changed...
        cb->dst_size.u4_height = (h_ratio*src_clip_h)>>16;
      }
      else if (h_ratio < v_ratio)
      {
        // dst_h needs not to be changed...
        cb->dst_size.u4_width = (v_ratio*src_clip_w)>>16;
      }
      else // equal case
      {
        // Don't change a thing...dst_size should be the same as dst_fb_size...
      }
    }

    // MAUI_02943526 modify width to 2x if dst_color_format is UYVY
    //if (VIDEO_RENDERER_COLOR_PACKED_UYVY422 == cb->dst_color_format)
    {
      cb->dst_fb_size.u4_width = (cb->dst_fb_size.u4_width>>1)<<1;
      if ((90 == cb->rotate_flip.u2_cw_rotate_angle) || 
          (270 == cb->rotate_flip.u2_cw_rotate_angle))
      {cb->dst_size.u4_height = (cb->dst_size.u4_height>>1)<<1;}
      else
      {cb->dst_size.u4_width = (cb->dst_size.u4_width>>1)<<1;}
    }

    // compute the pitch start address according to rotation...
    if ((90 == cb->rotate_flip.u2_cw_rotate_angle) || 
        (270 == cb->rotate_flip.u2_cw_rotate_angle))
    {
      w_after_rot = cb->dst_fb_size.u4_height;
      h_after_rot = cb->dst_fb_size.u4_width;
    }
    else
    {
      w_after_rot = cb->dst_fb_size.u4_width;
      h_after_rot = cb->dst_fb_size.u4_height;
    }

    // calculate dst clipping window to fit dst_fb_size...
    if ((cb->dst_size.u4_width == w_after_rot) && 
        (cb->dst_size.u4_height == h_after_rot))
    {
      cb->dst_clip.b_clip_enable = KAL_FALSE;
    }
    else
    {
      cb->dst_clip.b_clip_enable = KAL_TRUE;
      if (cb->dst_size.u4_width > w_after_rot)
      {
        cb->dst_clip.u4_clip_left = (cb->dst_size.u4_width - w_after_rot)>>1;
        cb->dst_clip.u4_clip_right = cb->dst_clip.u4_clip_left + w_after_rot - 1;
        cb->dst_clip.u4_clip_top = 0;
        cb->dst_clip.u4_clip_bottom = h_after_rot - 1;
      }
      else if (cb->dst_size.u4_height > h_after_rot)
      {
        cb->dst_clip.u4_clip_top = (cb->dst_size.u4_height - h_after_rot)>>1;
        cb->dst_clip.u4_clip_bottom = cb->dst_clip.u4_clip_top + h_after_rot - 1;
        cb->dst_clip.u4_clip_left = 0;
        cb->dst_clip.u4_clip_right = w_after_rot - 1;
      }
      else
      {
        ASSERT(0);
        cb->dst_clip.b_clip_enable = KAL_FALSE;
      }
    }

    // dst_fb_start_addr set to dst_fb_addr
    {
      kal_uint32 i = VA2_COMP_VR_MAX_DSPL_FB_COUNT;
      for (; i-- != 0; )
      {
        kal_mem_cpy(&(cb->dst_fb_start_addr_array[i]), 
                    &(cb->dst_fb_addr_array[i]), 
                    sizeof(VA2_FRAME_BUFFER_ADDRESS_T));
      }
    }
  }
  else if (VIDEO_RENDERER_RENDER_MODE_STRETCH_TO_WINDOW == cb->render_mode)
  {
    // no dst clipping
    cb->dst_clip.b_clip_enable = KAL_FALSE;

    // dst_fb_start_addr set to dst_fb_addr
    {
      kal_uint32 i = VA2_COMP_VR_MAX_DSPL_FB_COUNT;
      for (; i-- != 0; )
      {
        kal_mem_cpy(&(cb->dst_fb_start_addr_array[i]), 
                    &(cb->dst_fb_addr_array[i]), 
                    sizeof(VA2_FRAME_BUFFER_ADDRESS_T));
      }
    }

    // set dst_size according to rotation angle
    {
      if ((90 == cb->rotate_flip.u2_cw_rotate_angle) || 
          (270 == cb->rotate_flip.u2_cw_rotate_angle))
      {
        cb->dst_size.u4_width = cb->dst_fb_size.u4_height;
        cb->dst_size.u4_height = cb->dst_fb_size.u4_width;
      }
      else
      {
        cb->dst_size.u4_width = cb->dst_fb_size.u4_width;
        cb->dst_size.u4_height = cb->dst_fb_size.u4_height;
      }
    }
    // MAUI_02943526 modify width to 2x if dst_color_format is UYVY
    //if (VIDEO_RENDERER_COLOR_PACKED_UYVY422 == cb->dst_color_format)
    {
      cb->dst_fb_size.u4_width = (cb->dst_fb_size.u4_width>>1)<<1;
      if ((90 == cb->rotate_flip.u2_cw_rotate_angle) || 
          (270 == cb->rotate_flip.u2_cw_rotate_angle))
      {cb->dst_size.u4_height = (cb->dst_size.u4_height>>1)<<1;}
      else
      {cb->dst_size.u4_width = (cb->dst_size.u4_width>>1)<<1;}
    }
  }
  else
  {
    return KAL_FALSE;
  }

  return KAL_TRUE;
}

/**
 *  @todo OK
 *  @common VR.VP
 */
static void
_va2_vr_vp_6276_display_timer_hdlr(
  void *param)
{
  //kal_bool idp_busy;
  //kal_uint32 save_irq_mask;
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6276_cb;

  if ((va2_comp_video_renderer_cb_t*) param != cb)
  {
    ASSERT(0); // incorrect timer handler param
  }

  va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_INTERNAL____DSPL_TIMER_TIMEOUT, 0);

#if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("TM0", SA_start);
  SLA_CustomLogging("TM0", SA_stop);
#endif  // #if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)

  if(VIDEO_STATE_RUN != cb->state.eState)
  {
    return;
  }

  if(KAL_TRUE == va2_util_check_bypass_redraw(cb))
  {
    return;
  }

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
/* under construction !*/
/* under construction !*/
#endif

  if (KAL_TRUE == cb->bypass)
  {
    // If times out in bypass mode, do nothing...especially not to trigger IDP...
    // And actually we don't care about if no consequent buffer comes or not!!
    return;
  }

  //_va2_comp_vr_add_trace(, 0);
  visual_active_hisr(VISUAL_RENDERER_TIMER_HISR_ID);
}


/**
 *  @status OK
 *  @remark callback in HISR...VISUAL HISR to be specific...
 *  @common VR.VP
 */
static void
_va2_vr_vp_6276_idp_frame_done_cb(
  void *param)
{
  va2_comp_video_renderer_cb_t *cb = (va2_comp_video_renderer_cb_t*) param;
  //kal_uint32 save_irq_mask;

  ASSERT(NULL != cb);

#if defined(MDP_SUPPORT_FAST_POWER_ON_OFF)
  idp_video_decode_config_fast(_va2_comp_video_renderer_idp_key,
                               IDP_VIDEO_DECODE_POWER_CTRL, KAL_FALSE);
#endif

  // release IsRendererBusy to let next frame can be inserted.
  //save_irq_mask = SaveAndSetIRQMask();
  cb->IsRendererBusy = KAL_FALSE;
  //RestoreIRQMask(save_irq_mask);

  if(VIDEO_STATE_RUN != cb->state.eState)
  {
    return;
  }

#if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("RFD", SA_start);
#endif  // #if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)
 
  if (KAL_TRUE == cb->bypass)
  {
    // Unexpected: FrameDone occurs unders bypass mode.
    // Bypass mode should only be switched under Stop state, and render should only execute under Run state.
    // At last, FrameDone will not be processed except under Run state. There it is.
    ASSERT(0);
  }

  va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_INTERNAL____MDP_HW_FRAME_DONE_CB, 0);

#if defined (VIDEO_RENDERER_SUPPORT_MULTIPLE_VIDEO_FRAME)
  // if buffer header received while HW doing a frame...use the latest frame buffer for the next update...
  if (0 != cb->vr_q_handle.to_be_processed_q.size)
  {
    va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
  }

  // try to return all buffers...
  cb->funcs.try_to_return_buf_hdrs(cb);
#endif

  // Trigger display 
#if defined(DRV_DISPLAY_DRIVER_V2)
  {
    kal_uint32 iIndex = ((_va2_vr_render_display_buffer_cnt&0x1)^0x1);

    if (WFC_FALSE == wfcMMCheckBusy())
    {
#if defined(__VIDEO_SUBTITLE_SUPPORT__)
      // trigger subtitle display buffer if previous trigger is aborted due to LCD busy
      if (NULL != _va2_vr_vp_6276_subtitle_trigger_buffer)
      {
        if (KAL_FALSE == _va2_vr_vp_6276_sub_src_removed)
        {
          _va2_vr_vp_6276_trigger_subtitle(
          _va2_vr_vp_6276_subtitle_trigger_buffer, 
          cb);
  
          va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_INTERNAL____TRIGGER_SUBTITLE, _va2_vr_vp_6276_subtitle_trigger_buffer);
        }
        _va2_vr_vp_6276_subtitle_trigger_buffer = NULL;
      }
#endif

      _va2_vr_vp_6276_trigger_display(
      cb->dst_fb_addr_array[iIndex].u4_fb_addr_plane0, 
      cb);

      // trace for trigger display
      if (kal_if_hisr())
      {
        kal_dev_trace(TRACE_GROUP_6, REND_TRC_TRIGGER_DISPLAY, 
                      (drv_get_current_time()), (cb->dst_fb_addr_array[iIndex].u4_fb_addr_plane0),
                      (cb->dst_fb_size.u4_width), (cb->dst_fb_size.u4_height));
      }
      else
      {
        kal_trace(TRACE_GROUP_6, REND_TRC_TRIGGER_DISPLAY, 
                      (drv_get_current_time()), (cb->dst_fb_addr_array[iIndex].u4_fb_addr_plane0),
                      (cb->dst_fb_size.u4_width), (cb->dst_fb_size.u4_height));
      }

#if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)
        SLA_CustomLogging("RDD", SA_start); // renderer display drop
        SLA_CustomLogging("RDD", SA_stop);
#endif

    }
    else
    {
      _va2_vr_render_display_buffer_cnt++;
      _va2_vr_vp_6276_drop_frame_cnt++;

#if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)
        SLA_CustomLogging("RDR", SA_start); // renderer display render
        SLA_CustomLogging("RDR", SA_stop);
#endif
    }
  }
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(VA2_VR_VP_6236_ENABLE_SWLA_TRACE)
/* under construction !*/
/* under construction !*/
#endif  // #if defined(VA2_VR_VP_6236_ENABLE_SWLA_TRACE)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(VA2_VR_VP_6236_ENABLE_SWLA_TRACE)
/* under construction !*/
#endif  // #if defined(VA2_VR_VP_6236_ENABLE_SWLA_TRACE)
/* under construction !*/
#endif

#if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("RFD", SA_stop);
#endif  // #if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)
}

#if defined(VA2_RENDERER_VP_STEREO_VIDEO_SUPPORTED)

stereo_video_format_enum_t
_va2_vr_vp_6276_3D_convert_to_stereo_video_format(VA2_VIDEO_RENDERER_COLOR_FORMAT_T format)
{ 
  switch(format)
  {
    case VIDEO_RENDERER_COLOR_RGB565:
      return STEREO_VIDEO_FORMAT_RGB565;
      
    case VIDEO_RENDERER_COLOR_RGB888:
      return STEREO_VIDEO_FORMAT_RGB888;

    default:
      ASSERT(0);
  }

  // only for build warning
  return STEREO_VIDEO_FORMAT_RGB565;
}


stereo_video_mode_enum_t 
_va2_vr_vp_6276_3D_convert_to_stereo_video_mode(VA2_VIDEO_RENDERER_3D_MODE_T mode)
{
  switch(mode)
  {
    case VIDEO_RENDERER_3D_MODE_SIDE_BY_SIDE:
      return STEREO_VIDEO_MODE_SIDE_BY_SIDE;
      
    case VIDEO_RENDERER_3D_MODE_TOP_DOWN:
      return STEREO_VIDEO_MODE_TOP_DOWN;

    default:
      ASSERT(0);
  }

  // only for build warning
  return STEREO_VIDEO_MODE_SIDE_BY_SIDE;
}

static void _va2_vr_vp_6276_3D_transformation(void *param)
{
  video_renderer_stereo_video_t *stereo_video = (video_renderer_stereo_video_t *)param;

  //addr & size for cache switchable must be 32 byte align
  if (((kal_uint32)stereo_video->src_buffer & 0x1F) ||
      (stereo_video->src_buffer_size & 0x1F) ||
      ((kal_uint32)stereo_video->dst_buffer & 0x1F) ||
      (stereo_video->dst_buffer_size & 0x1F))
  {
    ASSERT(0);
  }

#if defined(SW_3D_PROCESS_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("3DC", SA_start); // 3D cache
#endif
  
  dynamic_switch_cacheable_region(&stereo_video->src_buffer, stereo_video->src_buffer_size, PAGE_CACHEABLE);
  
  // only do switch when dst != src
  if ((stereo_video->src_buffer != stereo_video->dst_buffer) && 
      (stereo_video->src_buffer_size != stereo_video->dst_buffer_size))
  {    
    dynamic_switch_cacheable_region(&stereo_video->dst_buffer, stereo_video->dst_buffer_size, PAGE_CACHEABLE);
  }
  
#if defined(SW_3D_PROCESS_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("3DC", SA_stop);  // 3D cache
  SLA_CustomLogging("3DT", SA_start); // 3D transformation
#endif
  
  // function to render 3d anaglyph
  stereo_video_transformation(
  (void *)stereo_video->src_buffer,
  (void *)stereo_video->dst_buffer,
  stereo_video->src_width,
  stereo_video->src_height,
  _va2_vr_vp_6276_3D_convert_to_stereo_video_format(stereo_video->format),
  _va2_vr_vp_6276_3D_convert_to_stereo_video_mode(stereo_video->mode),
  STEREO_VIDEO_ALG_COLOR_TRANSFORM);

#if defined(SW_3D_PROCESS_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("3DT", SA_stop);  // 3D transformation
  SLA_CustomLogging("3DC", SA_start); // 3D cache
#endif
  
  dynamic_switch_cacheable_region(&stereo_video->src_buffer, stereo_video->src_buffer_size, PAGE_NO_CACHE);
  
  // only do switch when dst != src
  if ((stereo_video->src_buffer != stereo_video->dst_buffer) && 
      (stereo_video->src_buffer_size != stereo_video->dst_buffer_size))
  {    
    dynamic_switch_cacheable_region(&stereo_video->dst_buffer, stereo_video->dst_buffer_size, PAGE_NO_CACHE);
  }
  
#if defined(SW_3D_PROCESS_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("3DC", SA_stop); // 3D cache
#endif

  if ((stereo_video->enable_callback) && (stereo_video->callback))
  {
    stereo_video->callback();
  }
}

static void
_va2_vr_vp_6276_3D_pass1_cb(void * param)
{
  va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_API_________RENDER_PASS1_CB, 0);

  _va2_vr_vp_6276_process_input_buffer(
    &_va2_vr_vp_6276_cb,
    KAL_TRUE,
    2);
}

static kal_uint32
_va2_vr_vp_6276_3D_pass1(
  va2_comp_video_renderer_cb_t *cb, 
  kal_bool blocking)
{
  kal_uint32 src_width, src_height;
  kal_bool src_clip_enable;
  kal_uint32 src_clip_top, src_clip_bottom, src_clip_left, src_clip_right;
  kal_uint32 dst_width, dst_height;
  kal_bool result = KAL_TRUE;
  void (*ptr_FrmDoneCBFunc)(void *) = NULL;
  
  va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_API_________RENDER_PASS1_START, blocking);
  
  // to simplify the opration of 3D anaglyph, we make all the image width align to 4 pixel

  // check all parameters and configs for triggering HW
  if (KAL_FALSE == _va2_vr_vp_6276_check_src_params_configs(cb))
  {
    if (KAL_FALSE == blocking)
    {
      va2_vr_notify_error_to_client(cb);
    }
    return KAL_FALSE;
  }

  src_width  = cb->src_size.u4_width;
  src_height = cb->src_size.u4_height;
  src_clip_enable = cb->src_clip.b_clip_enable;
  src_clip_top = cb->src_clip.u4_clip_top;
  src_clip_bottom = cb->src_clip.u4_clip_bottom;
  src_clip_left = cb->src_clip.u4_clip_left;
  src_clip_right = cb->src_clip.u4_clip_right;

  if (KAL_FALSE == src_clip_enable)
  {
    // force clip
    src_clip_enable = KAL_TRUE;
    src_clip_left = 0;
    src_clip_top = 0;
    src_clip_right = src_width - 1;
    src_clip_bottom = src_height - 1;
  }

  // must be 2 pixel align
  ASSERT(0 == (src_clip_left & 1));
  ASSERT(0 == (src_clip_top & 1));

  // get dst size, make it 2 pixel align
  dst_width  = src_clip_right - src_clip_left + 1;
  if (1 == (dst_width & 1))
  {
    src_clip_right--;
    dst_width  = src_clip_right - src_clip_left + 1;
  }

  dst_height = src_clip_bottom - src_clip_top + 1;
  if (1 == (dst_height & 1))
  {
    src_clip_bottom--;
    dst_height = src_clip_bottom - src_clip_top + 1;
  }
  
  // dst size > panel size, do resize
  if ((dst_width * dst_height) > (LCD_WIDTH * LCD_HEIGHT)) 
  {
    kal_uint32 h_ratio = (dst_width<<16) / LCD_WIDTH;
    kal_uint32 v_ratio = (dst_height<<16) / LCD_HEIGHT;
    kal_uint32 max_ratio = (h_ratio > v_ratio) ? h_ratio : v_ratio;

    dst_width = (dst_width<<16) / (max_ratio);
    dst_height = (dst_height<<16) / (max_ratio); 

    // dst size still larger than LCD size 
    if (dst_width > LCD_WIDTH) {dst_width = LCD_WIDTH;}
    if (dst_height > LCD_HEIGHT) {dst_height = LCD_HEIGHT;}
  }

  // 4 pixel align
  dst_width &= 0xFFFFFFFC;

  cb->stereo_video.src_width = dst_width;
  cb->stereo_video.src_height = dst_height;
  cb->stereo_video.format = VIDEO_RENDERER_COLOR_RGB565;

#if defined(MDP_SUPPORT_FAST_POWER_ON_OFF)
  //power off MDP after get frame done
  idp_video_decode_config_fast(_va2_comp_video_renderer_idp_key,
                               IDP_VIDEO_DECODE_POWER_CTRL, KAL_TRUE);
#endif

  // process by mdp
  if(KAL_FALSE == blocking)
  {
    ptr_FrmDoneCBFunc = _va2_vr_vp_6276_3D_pass1_cb;
  }  

  if (KAL_FALSE == idp_video_decode_stop(_va2_comp_video_renderer_idp_key))
  {
    ASSERT(0);
  }
  
  // 1st config
  result &= idp_video_decode_config(
    _va2_comp_video_renderer_idp_key, 
    
    IDP_VIDEO_DECODE_TARGET_WIDTH, dst_width,
    IDP_VIDEO_DECODE_TARGET_HEIGHT, dst_height,

    IDP_VIDEO_DECODE_DST_CLIP, KAL_FALSE, 0, 0, 0, 0,

    IDP_VIDEO_DECODE_ENABLE_PITCH, KAL_FALSE,
    IDP_VIDEO_DECODE_BG_IMAGE_WIDTH, dst_width,
    IDP_VIDEO_DECODE_IMAGE_DATA_FORMAT, va2_util_convert_to_idp_color_format(cb->stereo_video.format),

    IDP_VIDEO_DECODE_ROT_ANGLE, IMG_ROT_ANGLE_0, 
    0);

  // 2nd config
  result &= idp_video_decode_config(
    _va2_comp_video_renderer_idp_key, 

    IDP_VIDEO_DECODE_TRIGGER_LCD, KAL_FALSE,     

    IDP_VIDEO_DECODE_FRAME_BUFFER_ADDRESS, cb->stereo_video.src_buffer, 
    IDP_VIDEO_DECODE_FRAME_BUFFER_ADDRESS_2, cb->stereo_video.src_buffer,

    IDP_VIDEO_DECODE_EXTMEM_START_ADDRESS, 0,
    IDP_VIDEO_DECODE_EXTMEM_SIZE, 0,
    0);
  
  // 3rd config
  result &= idp_video_decode_config(
    _va2_comp_video_renderer_idp_key, 

    IDP_VIDEO_DECODE_CONTRAST_LEVEL, (KAL_FALSE == cb->post_process.b_contrast) ? 0x80 : cb->post_process.u1_contrast, 
    IDP_VIDEO_DECODE_BRIGHTNESS_LEVEL, (KAL_FALSE == cb->post_process.b_brightness) ? 0x80 : cb->post_process.u1_brightness, 
    
    IDP_VIDEO_DECODE_DONE_CB, ptr_FrmDoneCBFunc, 
    IDP_VIDEO_DECODE_DONE_CB_PARAM, NULL, 

    IDP_VIDEO_DECODE_SRC_WIDTH, src_width,
    IDP_VIDEO_DECODE_SRC_HEIGHT, src_height,
    IDP_VIDEO_DECODE_SOURCE_DATA_FORMAT, va2_util_convert_to_idp_color_format(cb->src_color_format),  

    IDP_VIDEO_DECODE_DITHER_ENABLE, KAL_TRUE,
    0);
  
  // 4th config
  result &= idp_video_decode_config(
    _va2_comp_video_renderer_idp_key,
    
    IDP_VIDEO_DECODE_ENABLE_CLIP, src_clip_enable,
    IDP_VIDEO_DECODE_CLIP_LEFT, src_clip_left,
    IDP_VIDEO_DECODE_CLIP_RIGHT, src_clip_right,
    IDP_VIDEO_DECODE_CLIP_TOP, src_clip_top,
    IDP_VIDEO_DECODE_CLIP_BOTTOM, src_clip_bottom,

    IDP_VIDEO_DECODE_VIDEO_Y_BUFFER_ADDRESS, cb->src_fb_addr.u4_fb_addr_plane0,
    IDP_VIDEO_DECODE_VIDEO_U_BUFFER_ADDRESS, cb->src_fb_addr.u4_fb_addr_plane1,
    IDP_VIDEO_DECODE_VIDEO_V_BUFFER_ADDRESS, cb->src_fb_addr.u4_fb_addr_plane2,
    0);

  if(result == KAL_FALSE)
  {
    if (KAL_FALSE == blocking)
    {
      va2_vr_notify_error_to_client(cb);
    }
    return KAL_FALSE;
  }

  if (KAL_FALSE == idp_video_decode_start_all(_va2_comp_video_renderer_idp_key))
  {
    ASSERT(0);
  }

  cb->u4LastRenderTimestamp = drv_get_current_time();

  // busy loop til IDP finishes
  if (KAL_TRUE == blocking)
  {
    kal_bool busy;
    kal_uint32 start_time = drv_get_current_time();

    do
    {
      ASSERT(KAL_TRUE == idp_video_decode_is_busy(_va2_comp_video_renderer_idp_key, &busy));
      if(KAL_FALSE == busy)
      {
        break;
      }
      else
      {
        kal_sleep_task(1);
      }
    } while (VA2_COMP_VR_RENDER_TIME_MAX > drv_get_duration_tick(start_time, drv_get_current_time()));

    //va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_API_________RENDER_PASS1_END, blocking);
    return KAL_TRUE;
  }
  else
  {
    //va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_API_________RENDER_PASS1_END, blocking);
    return KAL_TRUE;
  }
}

static void
_va2_vr_vp_6276_3D_pass2_cb(void)
{ 
  va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_API_________RENDER_PASS2_CB, 0);

  _va2_vr_vp_6276_process_input_buffer(
    &_va2_vr_vp_6276_cb,
    KAL_TRUE,
    3);
}

static kal_uint32
_va2_vr_vp_6276_3D_pass2(
  va2_comp_video_renderer_cb_t *cb, 
  kal_bool blocking)
{
  va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_API_________RENDER_PASS2_START, blocking);

  cb->stereo_video.callback = _va2_vr_vp_6276_3D_pass2_cb;
  
  if (KAL_TRUE == blocking)
  {
    cb->stereo_video.enable_callback = KAL_FALSE;
    _va2_vr_vp_6276_3D_transformation(&(cb->stereo_video));
  }
  else
  {
    cb->stereo_video.enable_callback = KAL_TRUE;
    // send message to CAL & run on it.
    video_renderer_task_req_msg(
      "MOD_CAL",
      _va2_vr_vp_6276_3D_transformation,
      &(cb->stereo_video),
      sizeof(video_renderer_stereo_video_t));
  }

  //va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_API_________RENDER_PASS2_END, blocking);
  return KAL_TRUE;
}

#endif// #if defined(VA2_RENDERER_VP_STEREO_VIDEO_SUPPORTED)

static kal_uint32 
_va2_vr_vp_6276_process_input_buffer(
  va2_comp_video_renderer_cb_t *cb, 
  kal_bool blocking,
  kal_uint32 pass)
{
  static kal_bool pass1_blocking;
  kal_uint32 save_irq_mask;
  va2_util_buf_hdr_q_item_t *curr_dspl_buf_hdr;
  VA2_VIDEO_FRAME_T *video_frame;
  kal_uint32 status;

  // When 3D video,
  // pass 1, video buffer Y2R conversion & resize
  // pass 2, 3D anaglyph process
  // pass 3, renderer to display
  // When 2D(normal) video,
  // only pass 3.
  
  // to assure no frame will be inserted when last one is still under process.
  save_irq_mask = SaveAndSetIRQMask();
  if (1 == pass) 
  {
    if (KAL_TRUE == cb->IsRendererBusy)
    {    
      RestoreIRQMask(save_irq_mask);

#if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)
      SLA_CustomLogging("RPD", SA_start); // renderer process drop
      SLA_CustomLogging("RPD", SA_stop);
#endif

      return KAL_FALSE;    
    }
    else
    {

#if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)
      SLA_CustomLogging("RPR", SA_start); // renderer process render
      SLA_CustomLogging("RPR", SA_stop);
#endif

      cb->IsRendererBusy = KAL_TRUE;
    }
  }
  RestoreIRQMask(save_irq_mask);

  if (1 == pass)
  {
    // only pass1 blocking is effective
    pass1_blocking = blocking;

    // get frame data...
    if (NULL == cb->vr_q_handle.curr_dspl_buf_hdr)
    {
      ASSERT(0); // incorrect param
    }
    curr_dspl_buf_hdr = cb->vr_q_handle.curr_dspl_buf_hdr;
    va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_INTERNAL____RENDER, (kal_uint32) curr_dspl_buf_hdr);

    video_frame = (VA2_VIDEO_FRAME_T*) curr_dspl_buf_hdr->buffer_header.pPrivateData;
    curr_dspl_buf_hdr->buffer_header.eFlags |= VIDEO_BUFFERFLAG_RENDER_DISPLAY;
    ASSERT(NULL != video_frame);
    kal_mem_cpy(&(cb->src_size), &(video_frame->r_fb_size), sizeof(VA2_FRAME_SIZE_T));
    kal_mem_cpy(&(cb->src_clip), &(video_frame->r_clip_window), sizeof(VA2_CLIP_WINDOW_T));
    kal_mem_cpy(&(cb->src_fb_addr), &(video_frame->r_fb_addr), sizeof(VA2_FRAME_BUFFER_ADDRESS_T));
    kal_mem_cpy(&(cb->src_color_format), &(video_frame->eFrameColorFmt), sizeof(VA2_VIDEO_RENDERER_COLOR_FORMAT_T));
    kal_mem_cpy(&(cb->src_aspect_ratio), &(video_frame->r_frame_aspect_ratio), sizeof(VA2_FRAME_ASPECT_RATIO_T));
  }

#if defined(VA2_RENDERER_VP_STEREO_VIDEO_SUPPORTED)
    
  if (VIDEO_RENDERER_3D_MODE_NONE != cb->stereo_video.mode)
  {
    if (KAL_TRUE == pass1_blocking)
    {      
      //when blocking mode, param "pass" is not used since only 1 pass 

      // pass 1
      status = _va2_vr_vp_6276_3D_pass1(cb, pass1_blocking);
      if (KAL_FALSE == status) 
      {
        _va2_vr_vp_6276_pass1_err_cnt++;
        cb->IsRendererBusy = KAL_FALSE;
        return status;
      }

      // pass 2
      status = _va2_vr_vp_6276_3D_pass2(cb, pass1_blocking);
      if (KAL_FALSE == status) 
      {
        _va2_vr_vp_6276_pass2_err_cnt++;
        cb->IsRendererBusy = KAL_FALSE;
        return status;
      }
    }
    else //KAL_FALSE == pass1_blocking
    {
      // pass 1
      if (1 == pass)
      {
        status = _va2_vr_vp_6276_3D_pass1(cb, pass1_blocking);
        if (KAL_FALSE == status) 
        {
          _va2_vr_vp_6276_pass1_err_cnt++;
          cb->IsRendererBusy = KAL_FALSE;
        }
        return status;
      }

      // pass 2, 3D anaglyph process
      if (2 == pass)
      {
        status = _va2_vr_vp_6276_3D_pass2(cb, pass1_blocking);
        if (KAL_FALSE == status) 
        {
          _va2_vr_vp_6276_pass2_err_cnt++;
          cb->IsRendererBusy = KAL_FALSE;
        }
        return status;
      }
    } //if (KAL_TRUE == pass1_blocking)

    // replace source param for render display buffer
    if ((KAL_TRUE == pass1_blocking) || (3 == pass))
    {
      // when side by side mode, the output width is half of input width
      cb->src_size.u4_width = cb->stereo_video.src_width >> 1;
      cb->src_size.u4_height = cb->stereo_video.src_height;

      // force clip
      cb->src_clip.b_clip_enable = KAL_TRUE;
      cb->src_clip.u4_clip_top = 0;
      cb->src_clip.u4_clip_left = 0;
      cb->src_clip.u4_clip_bottom = cb->src_size.u4_height - 1;
      cb->src_clip.u4_clip_right = cb->src_size.u4_width - 1;

      // address & format
      cb->src_fb_addr.u4_fb_addr_plane0 = cb->stereo_video.dst_buffer;
      cb->src_fb_addr.u4_fb_addr_plane1 = 0;
      cb->src_fb_addr.u4_fb_addr_plane2 = 0;
      cb->src_color_format = VIDEO_RENDERER_COLOR_RGB565;
    }
  } //if (VIDEO_RENDERER_3D_MODE_NONE != cb->stereo_video.mode)

#endif //#if defined(VA2_RENDERER_VP_STEREO_VIDEO_SUPPORTED)

  // pass 3, renderer to display
  status = _va2_vr_vp_6276_render_display_frame_buffer(cb, pass1_blocking);
  if (KAL_FALSE == status) 
  {
    _va2_vr_vp_6276_pass3_err_cnt++;
    cb->IsRendererBusy = KAL_FALSE;
    return status;
  }

  if (KAL_TRUE == pass1_blocking)
  {
    cb->IsRendererBusy = KAL_FALSE;
  }

  return status;
}


/**
 *  @return kal_uint32 the address to destination frame buffer if blocking is set to KAL_TRUE, 0 if blocking is set to KAL_FALSE.
 *  @status OK
 *  @todo post processing parameters...current MED just set some garbage down...
 *  @common VR.VP, VR.VT
 */
static kal_uint32 
_va2_vr_vp_6276_render_display_frame_buffer(
  va2_comp_video_renderer_cb_t *cb, 
  kal_bool blocking)
{
  va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_API_________RENDER_PASS3_START, blocking);

  // IDP opened
  if (0 == _va2_comp_video_renderer_idp_key)
  {
    ASSERT(0); // IDP video playback not opened
  }

  if (KAL_TRUE == cb->trigger_display)
  {
    if (KAL_FALSE == _va2_comp_vr_have_config_lcd)
    {
      ASSERT(0); // LCD must already be configed if it's in HW trigger mode
    }
  }

  if (VIDEO_RENDERER_COLOR_YUV420 == cb->src_color_format)
  {
    // handle the case: source clip size is ODD, sub the clip_right/clip_bottom by 1 for HW limitation
    if (0 != cb->src_clip.u4_clip_right &&
        1 == ((cb->src_clip.u4_clip_right - cb->src_clip.u4_clip_left + 1) & 0x1))
    {cb->src_clip.u4_clip_right--;}
  
    if (0 != cb->src_clip.u4_clip_bottom &&
        1 == ((cb->src_clip.u4_clip_bottom - cb->src_clip.u4_clip_top + 1) & 0x1))
    {cb->src_clip.u4_clip_bottom--;}
  }

#if defined(MDP_SUPPORT_FAST_POWER_ON_OFF)
    //power on MDP
    idp_video_decode_config_fast(_va2_comp_video_renderer_idp_key,
                                 IDP_VIDEO_DECODE_POWER_CTRL, KAL_TRUE);
#endif

  //  5.1. config MDP driver [OK]
  {
    kal_bool result = KAL_TRUE;
    void (*ptr_FrmDoneCBFunc)(void *) = NULL;
    kal_uint32 iIndex;

    // reset IDP at the beginning of configuration
    if (KAL_FALSE == idp_video_decode_stop(_va2_comp_video_renderer_idp_key))
    {
      ASSERT(0);
    }

    // config video playback path according to render mode...
    // Switch the double buffer
    if (KAL_FALSE == _va2_vr_vp_6276_config_idp_by_render_mode(cb, NULL))
    {
      if (KAL_FALSE == blocking)
      {
        va2_vr_notify_error_to_client(cb);
      }

      return KAL_FALSE;
    }

    // check all parameters and configs for triggering HW
    if (KAL_FALSE == _va2_vr_vp_6276_check_params_configs(cb))
    {
      if (KAL_FALSE == blocking)
      {
        va2_vr_notify_error_to_client(cb);
      }
      return KAL_FALSE;
    }

    if(KAL_FALSE == blocking)
    {
      ptr_FrmDoneCBFunc = _va2_vr_vp_6276_idp_frame_done_cb;
    }

    iIndex = (_va2_vr_render_display_buffer_cnt&0x1);

    // 1st config
    result &= idp_video_decode_config(
      _va2_comp_video_renderer_idp_key, 
  
      IDP_VIDEO_DECODE_TARGET_WIDTH, cb->dst_size.u4_width,
      IDP_VIDEO_DECODE_TARGET_HEIGHT, cb->dst_size.u4_height,

      IDP_VIDEO_DECODE_DST_CLIP, cb->dst_clip.b_clip_enable, 
                                 cb->dst_clip.u4_clip_left, cb->dst_clip.u4_clip_top, 
                                 cb->dst_clip.u4_clip_right, cb->dst_clip.u4_clip_bottom, 
    
      IDP_VIDEO_DECODE_ENABLE_PITCH, (VIDEO_RENDERER_RENDER_MODE_TOUCH_WINDOW_FROM_INSIDE == cb->render_mode)?KAL_TRUE:KAL_FALSE,
      IDP_VIDEO_DECODE_BG_IMAGE_WIDTH, cb->dst_fb_size.u4_width,
      IDP_VIDEO_DECODE_IMAGE_DATA_FORMAT, va2_util_convert_to_idp_color_format(cb->dst_color_format), 
      IDP_VIDEO_DECODE_ROT_ANGLE, va2_util_convert_to_idp_rot_angle(cb->rotate_flip.u2_cw_rotate_angle, cb->rotate_flip.b_flip), 
      0);

    // 2nd config
    result &= idp_video_decode_config(
      _va2_comp_video_renderer_idp_key, 

#if defined(DRV_DISPLAY_DRIVER_V1)
      IDP_VIDEO_DECODE_TRIGGER_LCD, cb->trigger_display,
#endif
#if defined(DRV_DISPLAY_DRIVER_V2)
      IDP_VIDEO_DECODE_TRIGGER_LCD, KAL_FALSE, 
#endif

      IDP_VIDEO_DECODE_FRAME_BUFFER_ADDRESS, cb->dst_fb_start_addr_array[iIndex].u4_fb_addr_plane0, 
      IDP_VIDEO_DECODE_FRAME_BUFFER_ADDRESS_2, cb->dst_fb_start_addr_array[iIndex].u4_fb_addr_plane0,

      IDP_VIDEO_DECODE_EXTMEM_START_ADDRESS, 0,
      IDP_VIDEO_DECODE_EXTMEM_SIZE, 0,
      0);

    // 3rd config
    result &= idp_video_decode_config(
      _va2_comp_video_renderer_idp_key, 

      IDP_VIDEO_DECODE_CONTRAST_LEVEL, (KAL_FALSE == cb->post_process.b_contrast) ? 0x80 : cb->post_process.u1_contrast, 
      IDP_VIDEO_DECODE_BRIGHTNESS_LEVEL, (KAL_FALSE == cb->post_process.b_brightness) ? 0x80 : cb->post_process.u1_brightness, 

      IDP_VIDEO_DECODE_DONE_CB, ptr_FrmDoneCBFunc, 
      IDP_VIDEO_DECODE_DONE_CB_PARAM, cb, 
      
      IDP_VIDEO_DECODE_SRC_WIDTH, cb->src_size.u4_width,
      IDP_VIDEO_DECODE_SRC_HEIGHT, cb->src_size.u4_height,      
      IDP_VIDEO_DECODE_SOURCE_DATA_FORMAT, va2_util_convert_to_idp_color_format(cb->src_color_format),

      IDP_VIDEO_DECODE_DITHER_ENABLE, ((VIDEO_RENDERER_COLOR_RGB565 == cb->dst_color_format)?KAL_TRUE:KAL_FALSE),
      0);

    // 4th config
    result &= idp_video_decode_config(
      _va2_comp_video_renderer_idp_key,
      
      IDP_VIDEO_DECODE_ENABLE_CLIP, cb->src_clip.b_clip_enable,
      IDP_VIDEO_DECODE_CLIP_LEFT, cb->src_clip.u4_clip_left,
      IDP_VIDEO_DECODE_CLIP_RIGHT, cb->src_clip.u4_clip_right,
      IDP_VIDEO_DECODE_CLIP_TOP, cb->src_clip.u4_clip_top,
      IDP_VIDEO_DECODE_CLIP_BOTTOM, cb->src_clip.u4_clip_bottom,

      IDP_VIDEO_DECODE_VIDEO_Y_BUFFER_ADDRESS, cb->src_fb_addr.u4_fb_addr_plane0,
      IDP_VIDEO_DECODE_VIDEO_U_BUFFER_ADDRESS, cb->src_fb_addr.u4_fb_addr_plane1,
      IDP_VIDEO_DECODE_VIDEO_V_BUFFER_ADDRESS, cb->src_fb_addr.u4_fb_addr_plane2,
      0);

    if(result == KAL_FALSE)
    {
      if (KAL_FALSE == blocking)
      {
        va2_vr_notify_error_to_client(cb);
      }
      return KAL_FALSE;
    }
  }

  // display frame counter increament
  _va2_vr_render_display_buffer_cnt++;

  // trigger MDP
  if (KAL_FALSE == idp_video_decode_start_all(_va2_comp_video_renderer_idp_key))
  {
    ASSERT(0);
  }

  cb->u4LastRenderTimestamp = drv_get_current_time();

  // busy loop til IDP finishes
  if (KAL_TRUE == blocking)
  {
    kal_bool busy;
    kal_uint32 start_time = drv_get_current_time();

    do
    {
      ASSERT(KAL_TRUE == idp_video_decode_is_busy(_va2_comp_video_renderer_idp_key, &busy));
      if(KAL_FALSE == busy)
      {
        break;
      }
      else
      {
        kal_sleep_task(1);
      }
    } while (VA2_COMP_VR_RENDER_TIME_MAX > drv_get_duration_tick(start_time, drv_get_current_time()));

    //va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_API_________RENDER_PASS3_END, blocking);
    return cb->dst_fb_start_addr_array[0].u4_fb_addr_plane0;
  }
  else
  {
    //va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_API_________RENDER_PASS3_END, blocking);
    return KAL_TRUE;
  }
} // end of _va2_vr_vp_6276_render_display_frame_buffer

static void
_va2_vr_vp_6276_hisr_general(void)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6276_cb;

  switch(cb->eVdoRndrHisrMode)
  {
  case VIDEO_RENDERER_HISR_MODE_BLACK_FRAME_INSERT:

    // Do not insert black frame if previous frame is available.
    if((cb->vr_q_handle.curr_dspl_buf_hdr == NULL) && 
       (0 == cb->vr_q_handle.to_be_processed_q.size) &&
       (VA2_VR_VP_MAX_BH_COUNT > cb->vr_q_handle.to_be_returned_q.size))
    {
      //  Allocate a black screen buffer header as initial display for lcd to avoid lcd time out assertion
      va2_util_buf_hdr_q_item_t* prBufHdrQueueItem;

      prBufHdrQueueItem = va2_util_buf_hdr_get_empty_q_item(&(cb->vr_q_handle));
      if (NULL == prBufHdrQueueItem)
      {
        // unexpected
        ASSERT(0);
      }
      kal_mem_cpy((void*) &(prBufHdrQueueItem->buffer_header), &_rBlackBufferHdr, sizeof(VIDEO_BUFFERHEADER_TYPE_T));
      va2_util_buf_hdr_enqueue(&(cb->vr_q_handle.to_be_processed_q), prBufHdrQueueItem);
      //MAUI_02851339 push the black frame to the latest buffer for display
      va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
    }
    break;

  default:
    ASSERT(0);
  }

  cb->eVdoRndrHisrMode = VIDEO_RENDERER_HISR_MODE_NONE;
  return;
}

static void
_va2_vr_vp_6276_hisr_empty_this_buffer(void)
{
    va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6276_cb;
    _va2_vr_vp_6276_empty_this_buffer_real(&_va2_comp_video_renderer_rNewBuffHeader);
    kal_set_eg_events(cb->EventID, TASK_WAIT_HISR_SET, KAL_OR);
}

static void
_va2_vr_vp_6276_disp_timer_visu_hisr_cb_func(void)
{
#if defined (VR_REDRAW_TIMER_OLD)
  kal_uint32 u4DurationmS;
  static kal_uint32 _u4DispTimerSkipCnt = 0, _u4DispTimerRefreshCnt = 0;
#endif
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6276_cb;

#if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("TM1", SA_start);
#endif  // #if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)

#if defined (VR_REDRAW_TIMER_OLD)
  u4DurationmS = drv_get_duration_ms(cb->u4LastRenderTimestamp);
  if(u4DurationmS < 60)
  {
    _u4DispTimerSkipCnt++;

#if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)
    SLA_CustomLogging("TM1", SA_stop);
#endif  // #if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)
    return;
  }
  _u4DispTimerRefreshCnt++;
#endif

if ((VIDEO_STATE_RUN == cb->state.eState) && 
    (KAL_FALSE == cb->bypass))
  {

#if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)
    SLA_CustomLogging("RTM", SA_start);
#endif  // #if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)

#if defined (VIDEO_RENDERER_SUPPORT_MULTIPLE_VIDEO_FRAME)
    if (0 != cb->vr_q_handle.to_be_processed_q.size)
    {
      va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
    }
#endif
    va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_INTERNAL____DSPL_TIMER_TRIGGER_RENDER_IN_VHISR, (kal_uint32) cb->vr_q_handle.curr_dspl_buf_hdr);
    _va2_vr_vp_6276_process_input_buffer(cb, KAL_FALSE, 1);

#if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)
    SLA_CustomLogging("RTM", SA_stop);
#endif  // #if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)
  }

#if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("TM1", SA_stop);
#endif  // #if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)

}  // end of _va2_vr_vp_6276_disp_timer_visu_hisr_cb_func


/**
 *  @status OK
 *  @todo init the control block
 *  @common none
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6276_t01_close_to_init(
  va2_comp_video_renderer_cb_t *cb)
{
  VIDEO_ERROR_TYPE_T ret;
  
  if (NULL == cb)
  {
    ASSERT(0);
  }

  va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_TRANSITION__T01_CLOSE_TO_INIT, 0);
  
  ret = va2_vr_t01_close_to_init(cb);
  if (ret != VIDEO_ERROR_NONE)
  {
    return ret;
  }
 
  //allocate extra display buffers when render_type is VIDEO_RENDERER_VIDEO_PLAYBACK
  if (cb->renderer_type == VIDEO_RENDERER_VIDEO_PLAYBACK ||
      cb->renderer_type == VIDEO_RENDERER_VIDEO_SUBTITLE_PLAYBACK)
  {
    //    4.1 Allocate memory for secondary display frame buffer
    cb->dst_fb_addr_array[1].u4_fb_addr_plane0 = VideoGetExtBuffer(_va2_vr_render_extmem_handler, VA2_VR_VP_DISPLAY_BUFFER_SIZE);
    if (0 == cb->dst_fb_addr_array[1].u4_fb_addr_plane0)
    {
      //ASSERT(0); // buffer allocation failed
      // free the mutex before return
      va2_vr_deinit(cb);
      return VIDEO_ERROR_NO_MEMORY; // memory allocation fail
    }
    cb->dst_fb_addr_array[1].u4_fb_addr_plane0 = 
      VideoCommExtBufferCacheableSwitch(cb->dst_fb_addr_array[1].u4_fb_addr_plane0, 
                                        VA2_VR_VP_DISPLAY_BUFFER_SIZE, 
                                        VIDEO_NON_CACHEABLE);

    cb->dst_fb_start_addr_array[1].u4_fb_addr_plane0 = cb->dst_fb_addr_array[1].u4_fb_addr_plane0;
  }
  // query video port number
  VideoPortNum = VideoCommGetInputPortIndex(&(cb->state), VIDEO_PORT_VIDEO_DATA);  

  cb->IsRendererBusy = KAL_FALSE;

  // init display & drop counter
  _va2_vr_render_display_buffer_cnt = 0;
  _va2_vr_vp_6276_drop_frame_cnt = 0;

#if defined(VA2_RENDERER_VP_STEREO_VIDEO_SUPPORTED)
  cb->stereo_video.src_buffer = VideoGetExtBuffer(_va2_vr_render_extmem_handler, VA2_VR_VP_STEREO_VIDEO_SZ);
  if (0 == cb->stereo_video.src_buffer)
  {
    //ASSERT(0);
    // free the mutex before return
    va2_vr_deinit(cb);
    return VIDEO_ERROR_NO_MEMORY; // memory allocation fail
  }
  if (cb->stereo_video.src_buffer & 0x1F) // start address must be 32 byte align for cache switchable
  {
    //ASSERT(0);
    // free the mutex before return
    va2_vr_deinit(cb);
    return VIDEO_ERROR_INIT_ERROR; // memory alignment wrong
  }
  
  cb->stereo_video.src_buffer =
  VideoCommExtBufferCacheableSwitch(cb->stereo_video.src_buffer, 
                                    VA2_VR_VP_STEREO_VIDEO_SZ, 
                                    VIDEO_NON_CACHEABLE);
  cb->stereo_video.src_buffer_size = VA2_VR_VP_STEREO_VIDEO_SZ;

  cb->stereo_video.dst_buffer = cb->stereo_video.src_buffer;
  cb->stereo_video.dst_buffer_size = cb->stereo_video.src_buffer_size;
  
  cb->stereo_video.mode = VIDEO_RENDERER_3D_MODE_NONE;
#endif

#if defined(__VIDEO_SUBTITLE_SUPPORT__)
  if (cb->renderer_type == VIDEO_RENDERER_VIDEO_SUBTITLE_PLAYBACK)
  {
    //    4.2 Allocate memory for secondary subtitle frame buffer
    cb->sub_dst_fb_addr_array[1].u4_fb_addr_plane0 = VideoGetExtBuffer(_va2_vr_render_extmem_handler, VA2_VR_VP_SUBTITLE_BUFFER_SIZE);
    if (0 == cb->sub_dst_fb_addr_array[1].u4_fb_addr_plane0)
    {
      //ASSERT(0); // buffer allocation failed
      // free the mutex before return
      va2_vr_deinit(cb);
      return VIDEO_ERROR_NO_MEMORY; // memory allocation fail
    }
    cb->sub_dst_fb_addr_array[1].u4_fb_addr_plane0 = 
      VideoCommExtBufferCacheableSwitch(cb->sub_dst_fb_addr_array[1].u4_fb_addr_plane0, 
                                        VA2_VR_VP_SUBTITLE_BUFFER_SIZE, 
                                        VIDEO_NON_CACHEABLE);

    // query subtitle port number
    SubtitlePortNum = VideoCommGetInputPortIndex(&(cb->state), VIDEO_PORT_SUBTITLE);
  }
  cb->IsSubtitleBusy = KAL_FALSE;

  _va2_vr_render_subtitle_buffer_cnt = 0;
#endif

  _va2_vr_vp_6276_pass1_err_cnt = 0;
  _va2_vr_vp_6276_pass2_err_cnt = 0;
  _va2_vr_vp_6276_pass3_err_cnt = 0;

  return VIDEO_ERROR_NONE;
}


/**
 *  @status OK
 *  @todo: remove those "very temp" part before SQC...
 *  @common VR.VP
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6276_t03_init_to_idle(
  va2_comp_video_renderer_cb_t *cb)
{
  if (NULL == cb)
  {
    ASSERT(0);
  }
  
  va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_TRANSITION__T03_INIT_TO_IDLE, 0);
  // clean idp key to ensure no previous key left
  // this is important for VT 2pass archi because 2 scenario VT encode/decode will both exist.
  _va2_comp_video_renderer_idp_key = 0;

  //  1. Open MDP path and register Visual HISR. LCD driver are opened in state transitions to Run state
  {
    #define WAIT_COUNT 100
    kal_uint32 wait_count = 0;

#if defined(DRV_IDP_MT6256_E2_SERIES) && defined(MJPG_DECODE)
    if (MJPEG == _va2_vr_vp_6276_render_mode)
    {
      idp_video_decode_mjpg_mode_enable();
    }
    else
    {
      idp_video_decode_mjpg_mode_disable();
    }
#endif
 
    //return error instead of assert if mdp open fail
    while (wait_count < WAIT_COUNT && (0 == _va2_comp_video_renderer_idp_key) && 
        (KAL_FALSE == idp_video_decode_open(&_va2_comp_video_renderer_idp_key)))
    {
      kal_sleep_task(1);
      wait_count++;
    }
    if (wait_count >= WAIT_COUNT)
    {return VIDEO_ERROR_INIT_ERROR;}
  }

  //    1.1 register VISUAL HISR for misc video render use
  VISUAL_Register_HISR(VISUAL_RENDERER_HISR_ID, _va2_vr_vp_6276_hisr_general);

  VISUAL_Register_HISR(VISUAL_RENDERER_EMPTY_THIS_BUFFER_HISR_ID, _va2_vr_vp_6276_hisr_empty_this_buffer);

#if defined(__VIDEO_SUBTITLE_SUPPORT__)
  VISUAL_Register_HISR(VISUAL_RENDERER_TRIGGER_DISPLAY_HISR_ID, _va2_vr_vp_6276_subtitle_frame_done_cb);
#endif
  //    1.2 register VISUAL HISR for VR Timer processing. The timer is used to trigger MDP for redraw when 
  //        there is no video frame in certain period of time. Under the situation, the UI updates will not
  //        be in effect since UI updates relies on MDP trigger under hardware trigger mode. The reason to 
  //        let timer activates Visual HISR for MDP trigger is to centralize the control of MDP, so that 
  //        reentrant condition can be solved.
  VISUAL_Register_HISR(VISUAL_RENDERER_TIMER_HISR_ID, _va2_vr_vp_6276_disp_timer_visu_hisr_cb_func);  

  //  Create a timer for periodically update display device
  if (0 == cb->display_timer)
  {
    cb->display_timer = kal_create_timer("VA2_VR_VP_6276_TIMER");
    if (0 == cb->display_timer)
    {
      ASSERT(0); // Timer create fail
    }
  }

  // 2. Invoke VideoCommChangeState() to change to IDLE state
  VideoCommClrAllQ(&(cb->state));
  VideoCommChangeState(&(cb->state), VIDEO_STATE_IDLE);

  return VIDEO_ERROR_NONE;
}


/**
 *  @status OK
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6276_t04_idle_to_run(
  va2_comp_video_renderer_cb_t *cb)
{
#if defined(__MTK_TARGET__)
  kal_uint32 save_irq_mask;
  volatile VA2_VIDEO_RENDERER_HISR_MODE* pRndrHisrMode;

  if (NULL == cb)
  {
    ASSERT(0);
  }

#if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("I2R", SA_start);
#endif  // #if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)

  //chrono add for reset u4LastSrcRenderTimestamp
  cb->u4LastSrcRenderTimestamp = drv_get_current_time();

  va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_TRANSITION__T04_IDLE_TO_RUN, 0);

  save_irq_mask = SaveAndSetIRQMask();
  // Do not insert black frame if previous frame is available.
  // [MAUI_02597121] & MAUI_02832616 Do not insert a black frame if bypass mode since no need to update display.
  if((cb->vr_q_handle.curr_dspl_buf_hdr == NULL) && 
     (0 == cb->vr_q_handle.to_be_processed_q.size))
  {
    cb->eVdoRndrHisrMode = VIDEO_RENDERER_HISR_MODE_BLACK_FRAME_INSERT;
    visual_active_hisr(VISUAL_RENDERER_HISR_ID);
  }
  RestoreIRQMask(save_irq_mask);

  if (KAL_FALSE == cb->bypass)  // Do not control LCD, timer, black frame under bypass mode
  {
    //  config LCD driver if LCD HW_Trig is requested through set_parameter
    if (KAL_TRUE == cb->trigger_display)
    {
      if (KAL_FALSE == _va2_comp_vr_have_config_lcd)
      {
#if defined(DRV_DISPLAY_DRIVER_V1)
        lcd_frame_update_struct *lcd_cfg = &cb->display_surface.r_mtk_lcd_config;

        _va2_comp_vr_triggered_lcd_id_this_time = lcd_cfg->lcd_id;

        lcd_cfg->fb_update_mode = LCD_HW_TRIGGER_MODE;
        lcd_cfg->hw_trigger_src = LCD_HWREF_SEL_ROT_DMA1;
   
        lcd_cfg->memory_output = KAL_FALSE;
        lcd_cfg->block_mode_flag = KAL_FALSE;
        lcd_cfg->lcd_block_mode_cb = NULL;

        // all the others are configed when processing video renderer parameters and configs

        // Register LCD HISR for FrameDone to do back-to-back rendering
        lcd_register_mm_callback(_va2_vr_vp_6276_lcd_frame_done_cb, cb);

        // Config LCD and start updating.
        ASSERT(LCD_OK == lcd_fb_update(lcd_cfg));
#endif  // #if defined(DRV_DISPLAY_DRIVER_V1)

#if defined(DRV_DISPLAY_DRIVER_V2)
        _va2_vr_vp_6276_config_n_activate_ddv2(cb, KAL_TRUE);
#if defined(__VIDEO_SUBTITLE_SUPPORT__)
        if (VIDEO_RENDERER_VIDEO_SUBTITLE_PLAYBACK == cb->renderer_type &&
            NULL != cb->sub_display_surface.dspl_element_handle)
        {
          _va2_vr_vp_6276_config_n_activate_ddv2(cb, KAL_FALSE);
          _va2_vr_vp_6276_sub_src_removed = KAL_FALSE;
          _va2_vr_vp_6276_sub_src_committed = KAL_TRUE;
        }
#endif
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)

        va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_DEBUG_______START_LCD_HW_TRIGGER_MODE, 0);

        _va2_comp_vr_have_config_lcd = KAL_TRUE;

//#if defined(MDP_SUPPORT_VP_EMI_BW_SWITCH)
//        _va2_vr_vp_6276_swith_emi_bw(cb);
//#endif

#if defined(__VIDEO_SUBTITLE_SUPPORT__)
        // render the subtitle frame if current subtitle frame is not silent frame
        // this is to ensure current subtitle will be shown after switch to RUN state
        if (NULL != cb->sub_vr_q_handle.curr_dspl_buf_hdr &&
            VIDEO_BUFFERFLAG_SILENT != cb->sub_vr_q_handle.curr_dspl_buf_hdr->buffer_header.eFlags)
        {
          _va2_vr_vp_6276_render_subtitle_frame_buffer(cb, KAL_FALSE);
        }
#endif
      }
      
      kal_set_timer( cb->display_timer, 
                     (kal_timer_func_ptr) cb->funcs.display_timer_hdlr,
                     (void*) cb,
                     kal_milli_secs_to_ticks(VA2_COMP_VR_DSPL_DEFAULT_TIMEOUT_TIME),
                     kal_milli_secs_to_ticks(VA2_COMP_VR_DSPL_DEFAULT_TIMEOUT_TIME)
                   );
    }//if (KAL_FALSE == _va2_comp_vr_have_config_lcd)
  } // end of bypass mode check

  // wait for black frame insertion to finish if black frame insertion start
  {
    pRndrHisrMode = &(cb->eVdoRndrHisrMode);
    while(1)
    {
      if(*pRndrHisrMode != VIDEO_RENDERER_HISR_MODE_BLACK_FRAME_INSERT)
      {
        break;
      }
      else
      {
        kal_sleep_task(1);
      }
    }
  }

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

  //  Invoke VideoCommChangeState() to RUN state.
  if (VIDEO_ERROR_NONE != VideoCommChangeState(&(cb->state), VIDEO_STATE_RUN))
  {
    ASSERT(0);
  }

#if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("I2R", SA_stop);
#endif  // #if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)
#endif  // #if defined(__MTK_TARGET__)

  return VIDEO_ERROR_NONE;
}  // end of _va2_vr_vp_6276_t04_idle_to_run


/**
 *  @status OK
 *  @common VR.VP
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6276_t05_run_to_stop(
  va2_comp_video_renderer_cb_t *cb)
{
  //kal_uint32 save_irq_mask;

  if (NULL == cb)
  {
    ASSERT(0);
  }

#if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("R2S", SA_start);
#endif  // #if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)

  va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_TRANSITION__T05_RUN_TO_STOP, 0);

  // Matt: to prevent EmptyThisBuffer, IDPFrameDone getting into wrong situation with a
  //       conservative state by reordering state assignment for in and out Run state.
  //       IL client is designed to invoke Renderer state transition in the blocking manner.
  //  0. Invoke VideoCommChangeState() to change state to STOP state.
  if (VIDEO_ERROR_NONE != VideoCommChangeState(&(cb->state), VIDEO_STATE_STOP))
  {
    ASSERT(0);
  }

  _va2_vr_vp_6276_drop_frame_cnt = 0;

  if (0 != cb->display_timer)
  {
    kal_cancel_timer(cb->display_timer);
  }

  while (KAL_TRUE == cb->IsRendererBusy
#if defined(__VIDEO_SUBTITLE_SUPPORT__)
      || KAL_TRUE == cb->IsSubtitleBusy
#endif
        )
  {
    kal_sleep_task(1);
  };

  //  Stop processing...
  if (KAL_TRUE == cb->bypass)
  {
    // TODO:[1] do something?
  }
  else
  {
    if (KAL_FALSE == idp_video_decode_stop(_va2_comp_video_renderer_idp_key))
    {
      ASSERT(0);
    }

    if ((cb->trigger_display) && 
        (KAL_TRUE == _va2_comp_vr_have_config_lcd))
    {
#if defined(DRV_DISPLAY_DRIVER_V1)
      lcd_stop_hw_update(_va2_comp_vr_triggered_lcd_id_this_time);
#endif
      
#if defined(DRV_DISPLAY_DRIVER_V2)
      _va2_vr_vp_6276_stop_n_deactivate_ddv2(cb, KAL_TRUE);
#if defined(__VIDEO_SUBTITLE_SUPPORT__)
      if (VIDEO_RENDERER_VIDEO_SUBTITLE_PLAYBACK == cb->renderer_type &&
          NULL != cb->sub_display_surface.dspl_element_handle)
      {_va2_vr_vp_6276_stop_n_deactivate_ddv2(cb, KAL_FALSE);}
#endif
#endif
      va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_DEBUG_______STOP_LCD_HW_TRIGGER_MODE, 0);
      _va2_comp_vr_have_config_lcd = KAL_FALSE;
    }
  }

#if defined(MDP_SUPPORT_FAST_POWER_ON_OFF)
  //power off MDP after get frame done
  idp_video_decode_config_fast(_va2_comp_video_renderer_idp_key,
                               IDP_VIDEO_DECODE_POWER_CTRL, KAL_FALSE);
#endif

  // switch BW back to MMI
//#if defined(MDP_SUPPORT_VP_EMI_BW_SWITCH)
//  idp_video_decode_config_fast(_va2_comp_video_renderer_idp_key,
//                               IDP_VIDEO_DECODE_EMI_BW_SWITCH, 
//                               IDP_VIDEO_DECODE_EMI_BW_MMI);
//#endif

  // Move down here after idp_video_decode_stop() but no guarantee it is set to 0 before IDP done.
  _va2_vr_render_display_buffer_cnt = 0;
#if defined(__VIDEO_SUBTITLE_SUPPORT__)
  _va2_vr_render_subtitle_buffer_cnt = 0;
  _va2_vr_vp_6276_subtitle_trigger_buffer = NULL;
#endif

#if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("R2S", SA_stop);
#endif  // #if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)

  return VIDEO_ERROR_NONE;
}


/**
 *  @status OK
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6276_t06_stop_to_run(
  va2_comp_video_renderer_cb_t *cb)
{
#if defined(__MTK_TARGET__)
  kal_uint32 save_irq_mask;
  volatile VA2_VIDEO_RENDERER_HISR_MODE* pRndrHisrMode;

  if (NULL == cb)
  {
    ASSERT(0);
  }

#if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("S2R", SA_start);
#endif  // #if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)

  //chrono add for reset u4LastSrcRenderTimestamp
  cb->u4LastSrcRenderTimestamp = drv_get_current_time();

  va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_TRANSITION__T06_STOP_TO_RUN, 0);

  save_irq_mask = SaveAndSetIRQMask();
  // Do not insert black frame if previous frame is available.
  // [MAUI_02597121] & MAUI_02832616 Do not insert a black frame if bypass mode since no need to update display.
  if((cb->vr_q_handle.curr_dspl_buf_hdr == NULL) && 
     (0 == cb->vr_q_handle.to_be_processed_q.size))
  {
    cb->eVdoRndrHisrMode = VIDEO_RENDERER_HISR_MODE_BLACK_FRAME_INSERT;
    visual_active_hisr(VISUAL_RENDERER_HISR_ID);
  }
  RestoreIRQMask(save_irq_mask);

  if (KAL_FALSE == cb->bypass)  // Do not control LCD, timer, black frame under bypass mode
  {
    //  config LCD driver if LCD HW_Trig is requested through set_parameter
    if (KAL_TRUE == cb->trigger_display)
    {
      if (KAL_FALSE == _va2_comp_vr_have_config_lcd)
      {
#if defined(DRV_DISPLAY_DRIVER_V1)
        lcd_frame_update_struct *lcd_cfg = &cb->display_surface.r_mtk_lcd_config;

        _va2_comp_vr_triggered_lcd_id_this_time = lcd_cfg->lcd_id;

        lcd_cfg->fb_update_mode = LCD_HW_TRIGGER_MODE;
        lcd_cfg->hw_trigger_src = LCD_HWREF_SEL_ROT_DMA1;

        lcd_cfg->memory_output = KAL_FALSE;
        lcd_cfg->block_mode_flag = KAL_FALSE;
        lcd_cfg->lcd_block_mode_cb = NULL;

        // all the others are configed when processing video renderer parameters and configs

        // Register LCD HISR for FrameDone to do back-to-back rendering
        lcd_register_mm_callback(_va2_vr_vp_6276_lcd_frame_done_cb, cb);

        // Config LCD and start updating.
        ASSERT(LCD_OK == lcd_fb_update(lcd_cfg));
#endif  // #if defined(DRV_DISPLAY_DRIVER_V1)

#if defined(DRV_DISPLAY_DRIVER_V2)
        _va2_vr_vp_6276_config_n_activate_ddv2(cb, KAL_TRUE);
#if defined(__VIDEO_SUBTITLE_SUPPORT__)
        if (VIDEO_RENDERER_VIDEO_SUBTITLE_PLAYBACK == cb->renderer_type &&
            NULL != cb->sub_display_surface.dspl_element_handle)
        {
          _va2_vr_vp_6276_config_n_activate_ddv2(cb, KAL_FALSE);
          _va2_vr_vp_6276_sub_src_removed = KAL_FALSE;
          _va2_vr_vp_6276_sub_src_committed = KAL_TRUE;
        }
#endif
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)

        va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_DEBUG_______START_LCD_HW_TRIGGER_MODE, 0);

        _va2_comp_vr_have_config_lcd = KAL_TRUE;

//#if defined(MDP_SUPPORT_VP_EMI_BW_SWITCH)
//        _va2_vr_vp_6276_swith_emi_bw(cb);
//#endif

#if defined(__VIDEO_SUBTITLE_SUPPORT__)
        // render the subtitle frame if current subtitle frame is not silent frame
        // this is to ensure current subtitle will be shown after switch to RUN state
        if (NULL != cb->sub_vr_q_handle.curr_dspl_buf_hdr &&
            VIDEO_BUFFERFLAG_SILENT != cb->sub_vr_q_handle.curr_dspl_buf_hdr->buffer_header.eFlags)
        {
          _va2_vr_vp_6276_render_subtitle_frame_buffer(cb, KAL_FALSE);
        }
#endif
      }

      kal_set_timer( cb->display_timer, 
                     (kal_timer_func_ptr) cb->funcs.display_timer_hdlr,
                     (void*) cb,
                     kal_milli_secs_to_ticks(VA2_COMP_VR_DSPL_DEFAULT_TIMEOUT_TIME),
                     kal_milli_secs_to_ticks(VA2_COMP_VR_DSPL_DEFAULT_TIMEOUT_TIME)
                   );
    }
  }

  // wait for black frame insertion to finish if black frame insertion start
  {
    pRndrHisrMode = &(cb->eVdoRndrHisrMode);
    while(1)
    {
      if(*pRndrHisrMode != VIDEO_RENDERER_HISR_MODE_BLACK_FRAME_INSERT)
      {
        break;
      }
      else
      {
        kal_sleep_task(1);
      }
    }
  }

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

  //  Invoke VideoCommChangeState() to RUN state.
  if (VIDEO_ERROR_NONE != VideoCommChangeState(&(cb->state), VIDEO_STATE_RUN))
  {
    ASSERT(0);
  }

#if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("S2R", SA_stop);
#endif  // #if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)

#endif  // #if defined(__MTK_TARGET__)
  return VIDEO_ERROR_NONE;
}  // end of _va2_vr_vp_6276_t06_stop_to_run


/**
 *  @status OK
 *  @common VR.VP
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6276_t10_idle_to_close(
  va2_comp_video_renderer_cb_t *cb)
{
  kal_uint32 save_irq_mask;

  if (NULL == cb)
  {
    ASSERT(0);
  }

  va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_TRANSITION__T10_IDLE_TO_CLOSE, 0);
  
  save_irq_mask = SaveAndSetIRQMask();
  //  1. reset buffer header queues...
  va2_util_buf_hdr_reset_buffer_header_queues(&(cb->vr_q_handle));
  RestoreIRQMask(save_irq_mask);

#if defined(__VIDEO_SUBTITLE_SUPPORT__)
  if (VIDEO_RENDERER_VIDEO_SUBTITLE_PLAYBACK == cb->renderer_type)
  {
    save_irq_mask = SaveAndSetIRQMask();
    //  1. reset buffer header queues...
    va2_util_buf_hdr_reset_buffer_header_queues(&(cb->sub_vr_q_handle));
    RestoreIRQMask(save_irq_mask);
  }
#endif

  //  2. Destroy timer.
  if (NULL != cb->display_timer)
  {
    kal_cancel_timer(cb->display_timer);
  }

  //  3. Close MDP path.
  if (0 != _va2_comp_video_renderer_idp_key)
  {
    idp_video_decode_close(_va2_comp_video_renderer_idp_key);
    _va2_comp_video_renderer_idp_key = 0;

#if defined(DRV_IDP_MT6256_E2_SERIES) && defined(MJPG_DECODE)
      idp_video_decode_mjpg_mode_disable();
#endif    
    
  }

  //  4. DeInit Video Renderer internal data.
  //    4.1 Destroy the semaphore.

  //  5. change state to CLOSE
  if (VIDEO_ERROR_NONE != VideoCommChangeState(&(cb->state), VIDEO_STATE_CLOSE))
  {
    ASSERT(0);
  }

  return VIDEO_ERROR_NONE;
}


/**
 *  @status OK
 *  @common VR
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6276_init(void)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6276_cb;
  VIDEO_ERROR_TYPE_T iRet;

  // create semaphore for API protection
  if (0 == cb->vr_sema_vrstate_sync)
  {
    cb->vr_sema_vrstate_sync = kal_create_sem("VA2_VR_VP_SEMA_VHISRCMD", 1);
  }

  kal_take_sem(cb->vr_sema_vrstate_sync, KAL_INFINITE_WAIT);

  va2_vr_init_trace(VA2_VR_VP_6276_DEBUG_TRACE_SIZE, &_va2_vr_vp_6276_debug_trace[0]);

  va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_API_________INIT, 0);

  if (VIDEO_STATE_CLOSE != cb->state.eState)
  {
    ASSERT(0); // incorrect state
    return VIDEO_ERROR_INIT_ERROR;
  }

  iRet = cb->funcs.t01_close_to_init(cb);
  kal_give_sem(cb->vr_sema_vrstate_sync);

  return iRet;
}

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6276_send_command(
  VIDEO_COMMAND_TYPE_T eCmd, 
  kal_uint32 u4Param)
{
  return va2_vr_send_command(&_va2_vr_vp_6276_cb, eCmd, u4Param);
}


/**
 *  @status OK
 *  @common VR.VP
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6276_get_parameter(
  VIDEO_PARAM_TYPE_T eCmd, 
  void *pParam)
{
  VIDEO_ERROR_TYPE_T iRet = VIDEO_ERROR_NONE;
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6276_cb;

  // special case, this config could be get in any state...
  if (VIDEO_CONFIG_RENDERER_STATUS == eCmd)
  {
    ASSERT(NULL != pParam);
    *((VIDEO_STATE_TYPE_T*) pParam) = cb->state.eState;
    return VIDEO_ERROR_NONE;
  }

  kal_take_sem(cb->vr_sema_vrstate_sync, KAL_INFINITE_WAIT);
  va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_API_________GET_PARAMETER, (kal_uint32) eCmd);

  if (VIDEO_STATE_CLOSE == cb->state.eState)
  {
    ASSERT(0);
  }

  ASSERT(NULL != pParam);

  switch (eCmd)
  {
  case VIDEO_PARAM_OUTPUT_BUFFER_PARAM:
    VideoCommGetOutputPortParam(&cb->state, pParam);
    break;

  case VIDEO_PARAM_INPUT_BUFFER_PARAM:
    VideoCommGetInputPortParam(&cb->state, pParam);
    break;

  case VIDEO_PARAM_RENDERER_DST_COLOR_FORMAT: /**< arg type: VA2_VIDEO_RENDERER_COLOR_FORMAT_T* */
    kal_mem_cpy(pParam, &(cb->dst_color_format), sizeof(VA2_VIDEO_RENDERER_COLOR_FORMAT_T));
    break;

  case VIDEO_PARAM_RENDERER_DST_FB_ADDR: /**< arg type: va2_video_renderer_dst_fb_t* */
    {
      va2_video_renderer_dst_fb_t *dst_fb = (va2_video_renderer_dst_fb_t*) pParam;
      if (VA2_COMP_VR_MAX_DSPL_FB_COUNT > dst_fb->u2_index)
      {
        kal_mem_cpy(&dst_fb->r_fb_addr, 
                    &(cb->dst_fb_addr_array[dst_fb->u2_index]), 
                    sizeof(VA2_FRAME_BUFFER_ADDRESS_T));
      }
      else
      {
        ASSERT(0);
      }
    }
    break;

  case VIDEO_PARAM_RENDERER_DST_FB_SIZE: /**< arg type: VA2_FRAME_SIZE_T* */
    kal_mem_cpy(pParam, &(cb->dst_fb_size), sizeof(VA2_FRAME_SIZE_T));
    break;

  case VIDEO_PARAM_RENDERER_TRIGGER_DISPLAY: /**< arg type: kal_bool* */
    *(kal_bool*)pParam = cb->trigger_display;
    break;

  case VIDEO_PARAM_RENDERER_DISPLAY_SURFACE: /**< arg type: va2_video_renderer_display_surface_t* */
    kal_mem_cpy(pParam, &(cb->display_surface), sizeof(va2_video_renderer_display_surface_t));
    break;

  case VIDEO_PARAM_RENDERER_SEMI_AUTO_RENDER_MODE: /**< arg type: VA2_VIDEO_RENDERER_RENDER_MODE_T* */ 
    *(VA2_VIDEO_RENDERER_RENDER_MODE_T*)pParam = cb->render_mode;
    break;

  case VIDEO_PARAM_RENDERER_BYPASS: /**< arg type: kal_bool* */
    *(kal_bool*)pParam = cb->bypass;
    break;

#if defined(VA2_RENDERER_VP_STEREO_VIDEO_SUPPORTED)
  case VIDEO_PARAM_RENDERER_3D_MODE: /**< arg type: VA2_VIDEO_RENDERER_3D_MODE_T* */
    *(VA2_VIDEO_RENDERER_3D_MODE_T*)pParam = cb->stereo_video.mode;
    break;
#endif //#if defined(VA2_RENDERER_VP_STEREO_VIDEO_SUPPORTED)


  case VIDEO_PARAM_RENDERER_RENDER_DISPLAY_BUFFER: /**< arg type: kal_uint32* */
    {
      if (VIDEO_STATE_STOP != cb->state.eState)
      {
        //ASSERT(0); // This parameter is only supported in STOP state
        iRet = VIDEO_ERROR_INPUT_PARAM_ERROR;
        break;
      }

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
/* under construction !*/
#endif
      {
#if defined (VIDEO_RENDERER_SUPPORT_MULTIPLE_VIDEO_FRAME)
        kal_uint32 save_irq_mask;

        save_irq_mask = SaveAndSetIRQMask();
        if((KAL_FALSE == cb->keep_curr_ptr_when_run) &&
           (0 != cb->vr_q_handle.to_be_processed_q.size))
        {
          // If only one frame is inserted in Run state, this action is to emulate 
          // the processing of the previous Bypass-Mode Frames.
          va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
        }
        RestoreIRQMask(save_irq_mask);
#endif

        // Try to guarantee the index is 0 before get buffer...
        _va2_vr_render_display_buffer_cnt = 0;

//#if defined(MDP_SUPPORT_VP_EMI_BW_SWITCH)
//        idp_video_decode_config_fast(_va2_comp_video_renderer_idp_key,
//                                     IDP_VIDEO_DECODE_EMI_BW_SWITCH, 
//                                     IDP_VIDEO_DECODE_EMI_BW_VP);
//#endif

        // calculate Video Renderer rotate angle according to Video Frame rotate angle and UI rotate angle
        // Video Frame rotate angle is extracted from Video Rotation Tag
        va2_util_calculate_total_rotate_angle_n_flip(cb->video_frame_rotate_flip,
                                                     cb->display_rotate_flip,
                                                     &(cb->rotate_flip));
   
        // get Video Frame
        *(kal_uint32*)pParam = _va2_vr_vp_6276_process_input_buffer(cb, KAL_TRUE, 1);

//#if defined(MDP_SUPPORT_VP_EMI_BW_SWITCH)
//        idp_video_decode_config_fast(_va2_comp_video_renderer_idp_key,
//                                     IDP_VIDEO_DECODE_EMI_BW_SWITCH, 
//                                     IDP_VIDEO_DECODE_EMI_BW_MMI);
//#endif

#if defined(MDP_SUPPORT_FAST_POWER_ON_OFF)
        //power off MDP after get frame done
        idp_video_decode_config_fast(_va2_comp_video_renderer_idp_key,
                                     IDP_VIDEO_DECODE_POWER_CTRL, KAL_FALSE);
#endif
      }
      if(KAL_FALSE == (*(kal_uint32*)pParam))
      {
        iRet = VIDEO_ERROR_INPUT_PARAM_ERROR;
        // if video frame error, there is no need to get subtitle frame
        // break get frame process directly.
        break;
      }

#if defined(__VIDEO_SUBTITLE_SUPPORT__)
      // get subtitle frame
      _va2_vr_vp_6276_get_subtitle_frame(cb);
#endif
    }
    break;

  case VIDEO_PARAM_RENDERER_ROTATE_FLIP: /**< arg type: va2_video_renderer_rotate_flip_t* */
    kal_mem_cpy(pParam, &(cb->display_rotate_flip), sizeof(va2_video_renderer_rotate_flip_t));
    break;

  case VIDEO_PARAM_RENDERER_VIDEO_FRAME_ROTATE_FLIP: /**< arg type: va2_video_renderer_rotate_flip_t* */
    kal_mem_cpy(pParam, &(cb->video_frame_rotate_flip), sizeof(va2_video_renderer_rotate_flip_t));
    break;

#if defined(__VIDEO_SUBTITLE_SUPPORT__)
   case VIDEO_PARAM_RENDERER_SUBTITLE_DST_COLOR_FORMAT: /**< arg type: VA2_VIDEO_RENDERER_COLOR_FORMAT_T* */
     kal_mem_cpy(pParam, &(cb->sub_dst_color_format), sizeof(VA2_VIDEO_RENDERER_COLOR_FORMAT_T));
     break;
  
  case VIDEO_PARAM_RENDERER_SUBTITLE_DST_FB_ADDR: /**< arg type: va2_video_renderer_dst_fb_t* */
    {
      va2_video_renderer_dst_fb_t *dst_fb = (va2_video_renderer_dst_fb_t*) pParam;
      if (VA2_COMP_VR_MAX_DSPL_FB_COUNT > dst_fb->u2_index)
      {
        kal_mem_cpy(&dst_fb->r_fb_addr, 
                    &(cb->sub_dst_fb_addr_array[dst_fb->u2_index]), 
                    sizeof(VA2_FRAME_BUFFER_ADDRESS_T));
      }
      else
      {
        ASSERT(0);
      }
    }
    break;
  
  case VIDEO_PARAM_RENDERER_SUBTITLE_DST_FB_SIZE: /**< arg type: VA2_FRAME_SIZE_T* */
    kal_mem_cpy(pParam, &(cb->sub_dst_fb_size), sizeof(VA2_FRAME_SIZE_T));
    break;
  
  case VIDEO_PARAM_RENDERER_SUBTITLE_DISPLAY_SURFACE: /**< arg type: va2_video_renderer_display_surface_t* */
    kal_mem_cpy(pParam, &(cb->sub_display_surface), sizeof(va2_video_renderer_display_surface_t));
    break;

  case VIDEO_PARAM_RENDERER_SUBTITLE_CURRENT_BUFFER_HEADER: /**< arg type: VIDEO_BUFFERHEADER_TYPE_T* */
    if (NULL != cb->sub_vr_q_handle.curr_dspl_buf_hdr)
    {
      kal_mem_cpy(pParam, &(cb->sub_vr_q_handle.curr_dspl_buf_hdr->buffer_header), sizeof(VIDEO_BUFFERHEADER_TYPE_T));
    }
    else
    {
      // currently no subtitle buffer header, return 0
      kal_mem_set(pParam, 0x0, sizeof(VIDEO_BUFFERHEADER_TYPE_T));
    }
    break;
#endif // #if defined(__VIDEO_SUBTITLE_SUPPORT__)

  case VIDEO_CONFIG_RENDERER_SRC_FB_ADDR: /**< arg type: VA2_FRAME_BUFFER_ADDRESS_T* */
    kal_mem_cpy(pParam, &(cb->src_fb_addr), sizeof(VA2_FRAME_BUFFER_ADDRESS_T));
    break;

  case VIDEO_CONFIG_RENDERER_SRC_COLOR_FORMAT: /**< arg type: VA2_VIDEO_RENDERER_COLOR_FORMAT_T* */
    kal_mem_cpy(pParam, &(cb->src_color_format), sizeof(VA2_VIDEO_RENDERER_COLOR_FORMAT_T));
    break;

  case VIDEO_CONFIG_RENDERER_SRC_SIZE: /**< arg type: VA2_FRAME_SIZE_T* */
    kal_mem_cpy(pParam, &(cb->src_size), sizeof(VA2_FRAME_SIZE_T));
    break;

  case VIDEO_CONFIG_RENDERER_SRC_CLIP: /**< arg type: VA2_CLIP_WINDOW_T* */
    kal_mem_cpy(pParam, &(cb->src_clip), sizeof(VA2_CLIP_WINDOW_T));
    break;

  case VIDEO_CONFIG_RENDERER_RESIZE_DST_SIZE: /**< arg type: VA2_FRAME_SIZE_T* */
    kal_mem_cpy(pParam, &(cb->dst_size), sizeof(VA2_FRAME_SIZE_T));
    break;

  case VIDEO_CONFIG_RENDERER_DST_CLIP: /**< arg type: VA2_CLIP_WINDOW_T* */ 
    kal_mem_cpy(pParam, &(cb->dst_clip), sizeof(VA2_CLIP_WINDOW_T));
    break;

  case VIDEO_CONFIG_RENDERER_DST_FB_START_ADDR: /**< arg type: va2_video_renderer_dst_fb_t* */
    {
      va2_video_renderer_dst_fb_t *dst_start_addr = (va2_video_renderer_dst_fb_t*) pParam;
      if (VA2_COMP_VR_MAX_DSPL_FB_COUNT > dst_start_addr->u2_index)
      {
        kal_mem_cpy(&dst_start_addr->r_fb_addr, 
                    &(cb->dst_fb_addr_array[dst_start_addr->u2_index]), 
                    sizeof(VA2_FRAME_BUFFER_ADDRESS_T));
      }
      else
      {
        ASSERT(0);
      }
    }
    break;

  case VIDEO_CONFIG_RENDERER_POST_PROCESS: /**< arg type: va2_video_renderer_post_process_config_t* */
    kal_mem_cpy(pParam, &(cb->post_process), sizeof(va2_video_renderer_post_process_config_t));
    break;

#if defined(__VIDEO_SUBTITLE_SUPPORT__)
  case VIDEO_CONFIG_RENDERER_SUBTITLE_SRC_FB_ADDR: /**< arg type: VA2_FRAME_BUFFER_ADDRESS_T* */
    kal_mem_cpy(pParam, &(cb->sub_src_fb_addr), sizeof(VA2_FRAME_BUFFER_ADDRESS_T));
    break;

  case VIDEO_CONFIG_RENDERER_SUBTITLE_SRC_COLOR_FORMAT: /**< arg type: VA2_VIDEO_RENDERER_COLOR_FORMAT_T* */
    kal_mem_cpy(pParam, &(cb->sub_src_color_format), sizeof(VA2_VIDEO_RENDERER_COLOR_FORMAT_T));
    break;
  
  case VIDEO_CONFIG_RENDERER_SUBTITLE_SRC_SIZE: /**< arg type: VA2_FRAME_SIZE_T* */
    kal_mem_cpy(pParam, &(cb->sub_src_size), sizeof(VA2_FRAME_SIZE_T));
    break;
      
  case VIDEO_CONFIG_RENDERER_SUBTITLE_RESIZE_DST_SIZE: /**< arg type: VA2_FRAME_SIZE_T* */
    kal_mem_cpy(pParam, &(cb->sub_dst_size), sizeof(VA2_FRAME_SIZE_T));
    break;
#endif // #if defined(__VIDEO_SUBTITLE_SUPPORT__)

  default:
    break;
  }

  kal_give_sem(cb->vr_sema_vrstate_sync);
  return iRet;
}

/**
 *  @status OK
 *  @commmon none
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6276_set_parameter(
  VIDEO_PARAM_TYPE_T eCmd, 
  void *pParam)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6276_cb;
  VIDEO_STATE_TYPE_T state;
  VIDEO_ERROR_TYPE_T i4Ret = VIDEO_ERROR_UNDEFINED;

  // MAUI_03174170 Don't take mutex since this is to allow MPL 
  // update source frame period at visual hisr context
  // MPL will set a large number to source frame period when play finished
  if (VIDEO_CONFIG_RENDERER_SOURCE_FRAME_PERIOD != eCmd)
  kal_take_sem(cb->vr_sema_vrstate_sync, KAL_INFINITE_WAIT);

  state = cb->state.eState;
  va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_API_________SET_PARAMETER, (kal_uint32) eCmd);

  if (VIDEO_STATE_CLOSE == state)
  {
    i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
  }
  else
  {
    if (VIDEO_STATE_RUN != state)
    {
      switch (eCmd)
      {
      case VIDEO_PARAM_OUTPUT_BUFFER_PARAM:
        VideoCommSetOutputPortParam(&(cb->state), pParam);
        i4Ret = VIDEO_ERROR_NONE;
        break;
      
      case VIDEO_PARAM_INPUT_BUFFER_PARAM:
        VideoCommSetInputPortParam(&(cb->state), pParam);
        i4Ret = VIDEO_ERROR_NONE;
        break;

      case VIDEO_PARAM_RENDERER_DST_COLOR_FORMAT: /**< arg type: VA2_VIDEO_RENDERER_COLOR_FORMAT_T* */
        {
          VA2_VIDEO_RENDERER_COLOR_FORMAT_T *color_format = (VA2_VIDEO_RENDERER_COLOR_FORMAT_T*) pParam;

          if ((NULL == color_format) || 
              (VIDEO_RENDERER_COLOR_DEFAULT_ERR == *color_format) || 
              (VIDEO_RENDERER_COLOR_YUV444 <=  *color_format))
          {
            ASSERT(0);
          }
          
          cb->dst_color_format = *color_format;
        }
        i4Ret = VIDEO_ERROR_NONE;
        break;

      case VIDEO_PARAM_RENDERER_DST_FB_ADDR: /**< arg type: va2_video_renderer_dst_fb_t* */
        {
          va2_video_renderer_dst_fb_t *dst_fb_addr = (va2_video_renderer_dst_fb_t*) pParam;

          if ((NULL == dst_fb_addr) || 
              (VA2_COMP_VR_MAX_DSPL_FB_COUNT <= dst_fb_addr->u2_index) || 
              (0x0 == dst_fb_addr->r_fb_addr.u4_fb_addr_plane0))
          {
            ASSERT(0);
          }

          kal_mem_cpy(&(cb->dst_fb_addr_array[dst_fb_addr->u2_index]), 
                      &(dst_fb_addr->r_fb_addr), 
                      sizeof(VA2_FRAME_BUFFER_ADDRESS_T));
          // apply to start address...
          kal_mem_cpy(&(cb->dst_fb_start_addr_array[dst_fb_addr->u2_index]), 
                      &(dst_fb_addr->r_fb_addr), 
                      sizeof(VA2_FRAME_BUFFER_ADDRESS_T));
        }
        i4Ret = VIDEO_ERROR_NONE;
        break;

      case VIDEO_PARAM_RENDERER_DST_FB_SIZE: /**< arg type: VA2_FRAME_SIZE_T* */
        {
          VA2_FRAME_SIZE_T *dst_fb_size = (VA2_FRAME_SIZE_T*) pParam;
          
          if ((NULL == dst_fb_size) || 
              (0 == dst_fb_size->u4_width) || 
              (0 == dst_fb_size->u4_height) ||
              //add limitation to dst_fb_size to avoid memory corruption issue
              (VA2_VR_VP_DISPLAY_BUFFER_SIZE < ((dst_fb_size->u4_width * dst_fb_size->u4_height)<<1)))
          {
            ASSERT(0);
          }

          cb->dst_fb_size.u4_width = dst_fb_size->u4_width;
          cb->dst_fb_size.u4_height = dst_fb_size->u4_height;
        }
        i4Ret = VIDEO_ERROR_NONE;
        break;

      case VIDEO_PARAM_RENDERER_TRIGGER_DISPLAY: /**< arg type: kal_bool* */
        {
          kal_bool *trigger_display = (kal_bool*) pParam;
          
          if (NULL == trigger_display)
          {
            ASSERT(0);
            break;
          }

          if ((KAL_TRUE == *trigger_display) || 
              (KAL_FALSE == *trigger_display))
          {
            cb->trigger_display = *trigger_display;
          }
          else
          {
            ASSERT(0);
            break;
          }
        }
        i4Ret = VIDEO_ERROR_NONE;
        break;

      case VIDEO_PARAM_RENDERER_DISABLE_DC_MODE: /**< arg type: kal_bool* */
        {
          kal_bool *disable_dc_mode = (kal_bool*) pParam;

          if (NULL == disable_dc_mode)
          {
            ASSERT(0);
            break;
          }

          if ((KAL_TRUE == *disable_dc_mode) ||
              (KAL_FALSE == *disable_dc_mode))
          {
            cb->disable_dcmode = *disable_dc_mode;
          }
          else
          {
            ASSERT(0);
            break;
          }
        }
        i4Ret = VIDEO_ERROR_NONE;
        break;


      case VIDEO_PARAM_RENDERER_DISPLAY_SURFACE: /**< arg type: va2_video_renderer_display_surface_t* */
        {
          va2_video_renderer_display_surface_t *display_surface = (va2_video_renderer_display_surface_t*) pParam;
          
          if (NULL == display_surface)
          {
            ASSERT(0);
            break;
          }
          
          kal_mem_cpy(&(cb->display_surface), 
                      display_surface, 
                      sizeof(va2_video_renderer_display_surface_t));
        }
        i4Ret = VIDEO_ERROR_NONE;
        break;

      case VIDEO_PARAM_RENDERER_SEMI_AUTO_RENDER_MODE: /**< arg type: VA2_VIDEO_RENDERER_RENDER_MODE_T* */ 
        {
          VA2_VIDEO_RENDERER_RENDER_MODE_T *render_mode = (VA2_VIDEO_RENDERER_RENDER_MODE_T*) pParam;

          if (NULL == render_mode)
          {
            ASSERT(0);
            break;
          }

          if ((VIDEO_RENDERER_RENDER_MODE_FULL_CONTROL == *render_mode) || 
              (VIDEO_RENDERER_RENDER_MODE_TOUCH_WINDOW_FROM_INSIDE == *render_mode) || 
              (VIDEO_RENDERER_RENDER_MODE_TOUCH_WINDOW_FROM_OUTSIDE == *render_mode) || 
              (VIDEO_RENDERER_RENDER_MODE_STRETCH_TO_WINDOW == *render_mode))
          {
            cb->render_mode = *render_mode;
          }
          else
          {
            ASSERT(0);
          }
        }
        i4Ret = VIDEO_ERROR_NONE;
        break;

      case VIDEO_PARAM_RENDERER_KEEP_CURR_PTR: /**< arg type: kal_bool* */
        {
          kal_bool *keep_curr_ptr = (kal_bool *) pParam;

          cb->keep_curr_ptr_when_run = *keep_curr_ptr;
        }
        i4Ret = VIDEO_ERROR_NONE;
        break;

      case VIDEO_PARAM_RENDERER_BYPASS: /**< arg type: kal_bool* */
        {
          kal_bool *bypass = (kal_bool*) pParam;
          cb->bypass = *bypass;
        }
        if (cb->bypass == KAL_FALSE &&
            cb->renderer_type == VIDEO_RENDERER_VIDEO_THUMBNAIL)
        {i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;}
        else
        {i4Ret = VIDEO_ERROR_NONE;}
        break;

      case VIDEO_PARAM_RENDERER_ROTATE_FLIP: /**< arg type: va2_video_renderer_rotate_flip_t* */
        {
          va2_video_renderer_rotate_flip_t *display_rotate_flip = (va2_video_renderer_rotate_flip_t*) pParam;
      
          if (NULL == display_rotate_flip)
          {
            ASSERT(0);
          }
      
          if ((0 == display_rotate_flip->u2_cw_rotate_angle) || 
              (90 == display_rotate_flip->u2_cw_rotate_angle) || 
              (180 == display_rotate_flip->u2_cw_rotate_angle) ||
              (270 == display_rotate_flip->u2_cw_rotate_angle))
          {
          }
          else
          {
            ASSERT(0);
          }
      
          if ((KAL_TRUE == display_rotate_flip->b_flip) || 
              (KAL_FALSE == display_rotate_flip->b_flip))
          {
          }
          else
          {
            ASSERT(0);
          }
      
          cb->display_rotate_flip.u2_cw_rotate_angle = display_rotate_flip->u2_cw_rotate_angle;
          cb->display_rotate_flip.b_flip = display_rotate_flip->b_flip;
        }
        i4Ret = VIDEO_ERROR_NONE;
        break;

      case VIDEO_PARAM_RENDERER_VIDEO_FRAME_ROTATE_FLIP: /**< arg type: va2_video_renderer_rotate_flip_t* */
        {
          va2_video_renderer_rotate_flip_t *video_frame_rotate_flip = (va2_video_renderer_rotate_flip_t*) pParam;
      
          if (NULL == video_frame_rotate_flip)
          {
            ASSERT(0);
          }
      
          if ((0 == video_frame_rotate_flip->u2_cw_rotate_angle) || 
              (90 == video_frame_rotate_flip->u2_cw_rotate_angle) || 
              (180 == video_frame_rotate_flip->u2_cw_rotate_angle) ||
              (270 == video_frame_rotate_flip->u2_cw_rotate_angle))
          {
          }
          else
          {
            ASSERT(0);
          }
      
          if ((KAL_TRUE == video_frame_rotate_flip->b_flip) || 
              (KAL_FALSE == video_frame_rotate_flip->b_flip))
          {
          }
          else
          {
            ASSERT(0);
          }
      
          cb->video_frame_rotate_flip.u2_cw_rotate_angle = video_frame_rotate_flip->u2_cw_rotate_angle;
          cb->video_frame_rotate_flip.b_flip = video_frame_rotate_flip->b_flip;
        }
        i4Ret = VIDEO_ERROR_NONE;
        break;

#if defined(VA2_RENDERER_VP_STEREO_VIDEO_SUPPORTED)
      case VIDEO_PARAM_RENDERER_3D_MODE: /**< arg type: VA2_VIDEO_RENDERER_3D_MODE_T* */
        {
          VA2_VIDEO_RENDERER_3D_MODE_T *stereo_video_mode = (VA2_VIDEO_RENDERER_3D_MODE_T*) pParam;
          cb->stereo_video.mode = *stereo_video_mode;
        }
        break;
#endif //#if defined(VA2_RENDERER_VP_STEREO_VIDEO_SUPPORTED)

#if defined(__VIDEO_SUBTITLE_SUPPORT__)
      case VIDEO_PARAM_RENDERER_SUBTITLE_DST_COLOR_FORMAT: /**< arg type: VA2_VIDEO_RENDERER_COLOR_FORMAT_T* */
        {
          VA2_VIDEO_RENDERER_COLOR_FORMAT_T *sub_color_format = (VA2_VIDEO_RENDERER_COLOR_FORMAT_T*) pParam;

          if ((NULL == sub_color_format) || 
              (VIDEO_RENDERER_COLOR_DEFAULT_ERR == *sub_color_format) || 
              (VIDEO_RENDERER_COLOR_YUV444 <=  *sub_color_format))
          {
            ASSERT(0);
          }
          
          cb->sub_dst_color_format = *sub_color_format;
        }
        i4Ret = VIDEO_ERROR_NONE;
        break;

      case VIDEO_PARAM_RENDERER_SUBTITLE_DST_FB_ADDR: /**< arg type: va2_video_renderer_dst_fb_t* */
        {
          va2_video_renderer_dst_fb_t *sub_dst_fb_addr = (va2_video_renderer_dst_fb_t*) pParam;

          // remove address NULL assert check
          // NULL address is used to inform Video Renderer that AP does not want subtitle layer to be drawn
          if (//(NULL == sub_dst_fb_addr) || 
              (VA2_COMP_VR_MAX_DSPL_FB_COUNT <= sub_dst_fb_addr->u2_index) //|| 
              //(0x0 == sub_dst_fb_addr->r_fb_addr.u4_fb_addr_plane0)
              )
          {
            ASSERT(0);
          }

          kal_mem_cpy(&(cb->sub_dst_fb_addr_array[sub_dst_fb_addr->u2_index]), 
                      &(sub_dst_fb_addr->r_fb_addr), 
                      sizeof(VA2_FRAME_BUFFER_ADDRESS_T));
        }
        i4Ret = VIDEO_ERROR_NONE;
        break;

      case VIDEO_PARAM_RENDERER_SUBTITLE_DST_FB_SIZE: /**< arg type: VA2_FRAME_SIZE_T* */
        {
          VA2_FRAME_SIZE_T *sub_dst_fb_size = (VA2_FRAME_SIZE_T*) pParam;
          
          if ((NULL == sub_dst_fb_size) || 
              (0 == sub_dst_fb_size->u4_width) || 
              (0 == sub_dst_fb_size->u4_height) ||
              //add limitation to dst_fb_size to avoid memory corruption issue
              (VA2_VR_VP_SUBTITLE_BUFFER_SIZE < ((sub_dst_fb_size->u4_width * sub_dst_fb_size->u4_height)<<1)))
          {
            ASSERT(0);
          }

          cb->sub_dst_fb_size.u4_width = sub_dst_fb_size->u4_width;
          cb->sub_dst_fb_size.u4_height = sub_dst_fb_size->u4_height;
        }
        i4Ret = VIDEO_ERROR_NONE;
        break;

      case VIDEO_PARAM_RENDERER_SUBTITLE_DISPLAY_SURFACE: /**< arg type: va2_video_renderer_display_surface_t* */
        {
          va2_video_renderer_display_surface_t *sub_display_surface = (va2_video_renderer_display_surface_t*) pParam;
          
          if (NULL == sub_display_surface)
          {
            //ASSERT(0);
            break;
          }
          
          kal_mem_cpy(&(cb->sub_display_surface), 
                      sub_display_surface, 
                      sizeof(va2_video_renderer_display_surface_t));
        }
        i4Ret = VIDEO_ERROR_NONE;
        break;

      case VIDEO_PARAM_RENDERER_PORT_FLUSH: /**< arg type: kal_bool* */
        {
          kal_uint32 *port = (kal_uint32*) pParam;
          
          if (NULL == port)
          {
            ASSERT(0);
            break;
          }

          if (_va2_vr_vp_6276_cb.renderer_type == VIDEO_RENDERER_VIDEO_SUBTITLE_PLAYBACK &&
              SubtitlePortNum == *port)
          {
            va2_util_buf_hdr_reset_buffer_header_queues(&(cb->sub_vr_q_handle));
          }
          else if (VideoPortNum == *port)
          {
            va2_util_buf_hdr_reset_buffer_header_queues(&(cb->vr_q_handle));
          }
          else
          {
            i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;            
          }
        }
        i4Ret = VIDEO_ERROR_NONE;
        break;
#endif // #if defined(__VIDEO_SUBTITLE_SUPPORT__)

      default: 
        break;
      }

      if(i4Ret != VIDEO_ERROR_UNDEFINED)
      {
        kal_give_sem(cb->vr_sema_vrstate_sync);
        return i4Ret;
      }
    }

    switch (eCmd)
    {
    case VIDEO_CONFIG_RENDERER_SRC_FB_ADDR: /**< arg type: VA2_FRAME_BUFFER_ADDRESS_T* */
      {
        VA2_FRAME_BUFFER_ADDRESS_T *src_fb_addr = (VA2_FRAME_BUFFER_ADDRESS_T*) pParam;

        if ((NULL == src_fb_addr) || 
            (0 == src_fb_addr->u4_fb_addr_plane0))
        {
          ASSERT(0);
        }

        kal_mem_cpy(&cb->src_fb_addr, 
                    src_fb_addr, 
                    sizeof(VA2_FRAME_BUFFER_ADDRESS_T));
      }
      i4Ret = VIDEO_ERROR_NONE;
      break;

    case VIDEO_CONFIG_RENDERER_SRC_COLOR_FORMAT: /**< arg type: VA2_VIDEO_RENDERER_COLOR_FORMAT_T* */
      {
        VA2_VIDEO_RENDERER_COLOR_FORMAT_T *color_format = (VA2_VIDEO_RENDERER_COLOR_FORMAT_T*) pParam;

        if ((NULL == color_format) || 
            (VIDEO_RENDERER_COLOR_DEFAULT_ERR == *color_format) || 
            (VIDEO_RENDERER_COLOR_MAX <=  *color_format))
        {
          ASSERT(0);
        }
        
        cb->src_color_format = *color_format;
      }
      i4Ret = VIDEO_ERROR_NONE;
      break;

    case VIDEO_CONFIG_RENDERER_SRC_SIZE: /**< arg type: VA2_FRAME_SIZE_T* */
      {
        VA2_FRAME_SIZE_T *src_size = (VA2_FRAME_SIZE_T*) pParam;
          
        if ((NULL == src_size) || 
            (0 == src_size->u4_width) || 
            (0 == src_size->u4_height))
        {
          ASSERT(0);
        }

        cb->src_size.u4_width = src_size->u4_width;
        cb->src_size.u4_height = src_size->u4_height;
      }
      i4Ret = VIDEO_ERROR_NONE;
      break;

    case VIDEO_CONFIG_RENDERER_SRC_CLIP: /**< arg type: VA2_CLIP_WINDOW_T* */
      {
        VA2_CLIP_WINDOW_T *src_clip = (VA2_CLIP_WINDOW_T*) pParam;

        if (NULL == src_clip)
        {
          ASSERT(0);
        }

        if (KAL_TRUE == src_clip->b_clip_enable)
        {
          //ASSERT(0 <= src_clip->u4_clip_top);
          //ASSERT(0 <= src_clip->u4_clip_left);
          ASSERT(src_clip->u4_clip_top <= src_clip->u4_clip_bottom);
          ASSERT(src_clip->u4_clip_left <= src_clip->u4_clip_right);
        }

        kal_mem_cpy(&(cb->src_clip), 
                    src_clip, 
                    sizeof(VA2_CLIP_WINDOW_T));
      }
      i4Ret = VIDEO_ERROR_NONE;
      break;

    case VIDEO_CONFIG_RENDERER_RESIZE_DST_SIZE: /**< arg type: VA2_FRAME_SIZE_T* */
      {
        VA2_FRAME_SIZE_T *dst_size = (VA2_FRAME_SIZE_T*) pParam;
          
        if ((NULL == dst_size) || 
            (0 == dst_size->u4_width) || 
            (0 == dst_size->u4_height))
        {
          ASSERT(0);
        }

        cb->dst_size.u4_width = dst_size->u4_width;
        cb->dst_size.u4_height = dst_size->u4_height;
      }
      i4Ret = VIDEO_ERROR_NONE;
      break;

    case VIDEO_CONFIG_RENDERER_DST_CLIP: /**< arg type: VA2_CLIP_WINDOW_T* */
      {
        VA2_CLIP_WINDOW_T *dst_clip = (VA2_CLIP_WINDOW_T*) pParam;

        if (NULL == dst_clip)
        {
          ASSERT(0);
        }

        if (KAL_TRUE == dst_clip->b_clip_enable)
        {
          //ASSERT(0 <= dst_clip->u4_clip_top);
          //ASSERT(0 <= dst_clip->u4_clip_left);
          ASSERT(dst_clip->u4_clip_top <= dst_clip->u4_clip_bottom);
          ASSERT(dst_clip->u4_clip_left <= dst_clip->u4_clip_right);
        }

        kal_mem_cpy(&(cb->dst_clip), 
                    dst_clip, 
                    sizeof(VA2_CLIP_WINDOW_T));
      }
      i4Ret = VIDEO_ERROR_NONE;
      break;

    case VIDEO_CONFIG_RENDERER_DST_FB_START_ADDR: /**< arg type: va2_video_renderer_dst_fb_t* */
      {
        va2_video_renderer_dst_fb_t *dst_fb_start_addr = (va2_video_renderer_dst_fb_t*) pParam;

        if ((NULL == dst_fb_start_addr) || 
            (VA2_COMP_VR_MAX_DSPL_FB_COUNT <= dst_fb_start_addr->u2_index) || 
            (0x0 == dst_fb_start_addr->r_fb_addr.u4_fb_addr_plane0))
        {
          ASSERT(0);
        }

        kal_mem_cpy(&(cb->dst_fb_start_addr_array[dst_fb_start_addr->u2_index]), 
                      &(dst_fb_start_addr->r_fb_addr), 
                      sizeof(VA2_FRAME_BUFFER_ADDRESS_T));
      }
      i4Ret = VIDEO_ERROR_NONE;
      break;

    case VIDEO_CONFIG_RENDERER_POST_PROCESS: /**< arg type: va2_video_renderer_post_process_config_t* */
      {
        va2_video_renderer_post_process_config_t *ipp = (va2_video_renderer_post_process_config_t*) pParam;

        if (NULL == ipp)
        {
          ASSERT(0);
        }

        cb->post_process.b_brightness = ipp->b_brightness;
        cb->post_process.u1_brightness = ipp->u1_brightness;
        cb->post_process.b_contrast = ipp->b_contrast;
        cb->post_process.u1_contrast = ipp->u1_contrast;
      }
      i4Ret = VIDEO_ERROR_NONE;
      break;

    case VIDEO_CONFIG_RENDERER_SOURCE_FRAME_PERIOD:
      {
        kal_uint32 *frame_period_in_ms = (kal_uint32 *) pParam;
        cb->u4FramePeriodInMS = *frame_period_in_ms;
        if(cb->u4FramePeriodInMS > 30000)
        {
          cb->u4FramePeriodInMS = 110;
        }         
      }
      i4Ret = VIDEO_ERROR_NONE;
      break;
    
    case VIDEO_CONFIG_RENDERER_BYPASS_HW_LAYER_SRC_RECT:
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
      i4Ret = VIDEO_ERROR_NONE;
      break;
      
#if defined(__VIDEO_SUBTITLE_SUPPORT__)
    case VIDEO_CONFIG_RENDERER_SUBTITLE_SRC_FB_ADDR: /**< arg type: VA2_FRAME_BUFFER_ADDRESS_T* */
      {
        VA2_FRAME_BUFFER_ADDRESS_T *sub_src_fb_addr = (VA2_FRAME_BUFFER_ADDRESS_T*) pParam;

        if ((NULL == sub_src_fb_addr) || 
            (0 == sub_src_fb_addr->u4_fb_addr_plane0))
        {
          ASSERT(0);
        }

        kal_mem_cpy(&cb->sub_src_fb_addr, 
                    sub_src_fb_addr, 
                    sizeof(VA2_FRAME_BUFFER_ADDRESS_T));
      }
      i4Ret = VIDEO_ERROR_NONE;
      break;

    case VIDEO_CONFIG_RENDERER_SUBTITLE_SRC_COLOR_FORMAT: /**< arg type: VA2_VIDEO_RENDERER_COLOR_FORMAT_T* */
      {
        VA2_VIDEO_RENDERER_COLOR_FORMAT_T *sub_color_format = (VA2_VIDEO_RENDERER_COLOR_FORMAT_T*) pParam;
    
        if ((NULL == sub_color_format) || 
            (VIDEO_RENDERER_COLOR_DEFAULT_ERR == *sub_color_format) || 
            (VIDEO_RENDERER_COLOR_MAX <=  *sub_color_format))
        {
          ASSERT(0);
        }
        
        cb->sub_src_color_format = *sub_color_format;
      }
      i4Ret = VIDEO_ERROR_NONE;
      break;

    case VIDEO_CONFIG_RENDERER_SUBTITLE_SRC_SIZE: /**< arg type: VA2_FRAME_SIZE_T* */
      {
        VA2_FRAME_SIZE_T *sub_src_size = (VA2_FRAME_SIZE_T*) pParam;
          
        if ((NULL == sub_src_size) || 
            (0 == sub_src_size->u4_width) || 
            (0 == sub_src_size->u4_height))
        {
          ASSERT(0);
        }
    
        cb->sub_src_size.u4_width = sub_src_size->u4_width;
        cb->sub_src_size.u4_height = sub_src_size->u4_height;
      }
      i4Ret = VIDEO_ERROR_NONE;
      break;
    
    case VIDEO_CONFIG_RENDERER_SUBTITLE_RESIZE_DST_SIZE: /**< arg type: VA2_FRAME_SIZE_T* */
      {
        VA2_FRAME_SIZE_T *sub_dst_size = (VA2_FRAME_SIZE_T*) pParam;
          
        if ((NULL == sub_dst_size) || 
            (0 == sub_dst_size->u4_width) || 
            (0 == sub_dst_size->u4_height))
        {
          ASSERT(0);
        }
    
        cb->sub_dst_size.u4_width = sub_dst_size->u4_width;
        cb->sub_dst_size.u4_height = sub_dst_size->u4_height;
      }
      i4Ret = VIDEO_ERROR_NONE;
      break;
#endif // #if defined(__VIDEO_SUBTITLE_SUPPORT__)

    default: 
      i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
      break;
    }

    if(i4Ret != VIDEO_ERROR_UNDEFINED)
    {
      kal_give_sem(cb->vr_sema_vrstate_sync);
      return i4Ret;
    }
  }

  if (VIDEO_CONFIG_RENDERER_SOURCE_FRAME_PERIOD != eCmd)
  kal_give_sem(cb->vr_sema_vrstate_sync);
  
  return VIDEO_ERROR_NONE;
}

/**
 *  @status OK
 *  @common VR
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6276_use_buffer(
  kal_uint8 *pu1Buff, 
  kal_uint32 u4Size)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6276_cb;
  VIDEO_ERROR_TYPE_T i4Ret;

  kal_take_sem(cb->vr_sema_vrstate_sync, KAL_INFINITE_WAIT);
  i4Ret = va2_vr_use_buffer(&_va2_vr_vp_6276_cb, pu1Buff, u4Size);
  kal_give_sem(cb->vr_sema_vrstate_sync);
  return i4Ret;
}

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6276_empty_this_buffer(
  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6276_cb;
  kal_uint32 u4Flags = 0;

  //  0.  parameter check and execution context check
  if ((NULL == prBuffHeader) || 
      (NULL == prBuffHeader->pu1Buffer) || 
      (NULL == prBuffHeader->pPrivateData))
  {
    ASSERT(0); // incorrect param
  }
  //  0.5 cannot be invoked in NU+ LISR
  if (KAL_TRUE == kal_if_lisr())
  {
    ASSERT(0); // cannot be invoked in NU+ LISR
  }
  //if ((KAL_FALSE== kal_if_hisr()) && (KAL_FALSE == cb->bypass) && (cb->state.eState == VIDEO_STATE_RUN))
  if (KAL_FALSE== kal_if_hisr())
  {
    kal_mem_cpy((void*) &(_va2_comp_video_renderer_rNewBuffHeader), prBuffHeader, sizeof(VIDEO_BUFFERHEADER_TYPE_T));
    //cb->eVdoRndrHisrMode = VIDEO_RENDERER_HISR_MODE_EMPTY_THIS_BUFFER;
    kal_retrieve_eg_events(cb->EventID, TASK_WAIT_HISR_SET, KAL_AND_CONSUME, &u4Flags, KAL_NO_SUSPEND);
    visual_active_hisr(VISUAL_RENDERER_EMPTY_THIS_BUFFER_HISR_ID);
    kal_retrieve_eg_events(cb->EventID, TASK_WAIT_HISR_SET, KAL_AND_CONSUME, &u4Flags, KAL_SUSPEND);
  }
  else
  {
    _va2_vr_vp_6276_empty_this_buffer_real(prBuffHeader);
  }

  return VIDEO_ERROR_NONE;
}


/**
 *  @status OK
 *  @todo vr_q_handle
 *  @common VR.VP
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6276_empty_this_buffer_real(
  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
  va2_util_buf_hdr_q_item_t *q_item;
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6276_cb;
  va2_util_buf_hdr_q_handle_t *vr_q_handle;

#if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("REB", SA_start);
#endif  // #if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)

#if defined(__VIDEO_SUBTITLE_SUPPORT__)
  if (cb->renderer_type != VIDEO_RENDERER_VIDEO_SUBTITLE_PLAYBACK &&
      prBuffHeader->u4OutputPort != VideoPortNum)
  {
    // subtitle frame received but Vide Renderer handle is not video subtitle!
    ASSERT(0);
  }
#endif

#if defined(__VIDEO_SUBTITLE_SUPPORT__)
  if (cb->renderer_type == VIDEO_RENDERER_VIDEO_SUBTITLE_PLAYBACK &&
      prBuffHeader->u4OutputPort == SubtitlePortNum)
  {
    vr_q_handle = &(cb->sub_vr_q_handle);
    va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_API_________EMPTY_THIS_BUFFER__SUBTITLE, (kal_uint32) prBuffHeader->pu1Buffer);
  }
  else
#endif
  {
    vr_q_handle = &(cb->vr_q_handle);
    va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_API_________EMPTY_THIS_BUFFER, (kal_uint32) prBuffHeader->pu1Buffer);
  }

#if defined (VIDEO_RENDERER_SUPPORT_MULTIPLE_VIDEO_FRAME)
  // 0.7 This action is to emulate the processing of the previous Bypass-Mode Frames
  if (KAL_TRUE == cb->bypass)
  {
    if(cb->state.eState == VIDEO_STATE_RUN)
    {
      // For bypass mode, don't process/advance unless the frame is enqueued in Run state
      va2_util_buf_hdr_advance_to_the_latest_buffer_header(vr_q_handle);
    }
  }

  // 1. Return all buffer headers except the curr_dspl_buf_hdr
  va2_util_buf_hdr_remove_all_q_items(&(vr_q_handle->to_be_returned_q), &(vr_q_handle->to_be_processed_q));
#if defined(__VIDEO_SUBTITLE_SUPPORT__)
  if (vr_q_handle == &(cb->sub_vr_q_handle))
  {
    _va2_vr_vp_6276_try_to_return_subtitle_buffer_headers(cb);
  }
  else
#endif
  {
    cb->funcs.try_to_return_buf_hdrs(cb);
  }
#endif

  //  2. enqueue the buffer header...
  q_item = va2_util_buf_hdr_get_empty_q_item(vr_q_handle);
  if (NULL == q_item)
  {
    ASSERT(0);
  }

  // Add a log to track the last valid emptyThisBuffer calls...
  //va2_vr_add_trace_empty_this_buffer(cb, VA2_VR_API_________EMPTY_THIS_BUFFER, (kal_uint32) prBuffHeader->pu1Buffer);

  //    2.2 enqueue should not fail here...
  kal_mem_cpy((void*) &(q_item->buffer_header), prBuffHeader, sizeof(VIDEO_BUFFERHEADER_TYPE_T));
  va2_util_buf_hdr_enqueue(&(vr_q_handle->to_be_processed_q), q_item);

#if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("REB", SA_stop);
#endif  // #if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)

#if !defined (VIDEO_RENDERER_SUPPORT_MULTIPLE_VIDEO_FRAME)
  // return the old frame after enqueue, Video Renderer hold only 1 video frame
  {
    // update curr_dspl_buf_hdr only in RUN state
    if(cb->state.eState == VIDEO_STATE_RUN)
    {
      if (KAL_TRUE == cb->bypass ||
          (KAL_FALSE == cb->bypass &&
           ((vr_q_handle == &(cb->vr_q_handle) && KAL_FALSE == cb->IsRendererBusy)
#if defined(__VIDEO_SUBTITLE_SUPPORT__)
         || (vr_q_handle == &(cb->sub_vr_q_handle) && KAL_FALSE == cb->IsSubtitleBusy)
#endif
            )))
      va2_util_buf_hdr_advance_to_the_latest_buffer_header(vr_q_handle);
    }
    
    // Return all buffer headers except the curr_dspl_buf_hdr
    va2_util_buf_hdr_remove_all_q_items(&(vr_q_handle->to_be_returned_q), &(vr_q_handle->to_be_processed_q));
  #if defined(__VIDEO_SUBTITLE_SUPPORT__)
    if (vr_q_handle == &(cb->sub_vr_q_handle))
    {
      _va2_vr_vp_6276_try_to_return_subtitle_buffer_headers(cb);
    }
    else
  #endif
    {
      cb->funcs.try_to_return_buf_hdrs(cb);
    }
  }
#else
  // Video Renderer holds only 1 video buffer at bypass mode
  if (KAL_TRUE == cb->bypass)
  {
    // return the old frame when bypass mode, Video Renderer hold only 1 video frame
    if(cb->state.eState == VIDEO_STATE_RUN)
    {
      va2_util_buf_hdr_advance_to_the_latest_buffer_header(vr_q_handle);
    }

    // 1. Return all buffer headers except the curr_dspl_buf_hdr
    va2_util_buf_hdr_remove_all_q_items(&(vr_q_handle->to_be_returned_q), &(vr_q_handle->to_be_processed_q));
#if defined(__VIDEO_SUBTITLE_SUPPORT__)
    if (vr_q_handle == &(cb->sub_vr_q_handle))
    {
      _va2_vr_vp_6276_try_to_return_subtitle_buffer_headers(cb);
    }
    else
#endif
    {
      cb->funcs.try_to_return_buf_hdrs(cb);
    }
  }
#endif

  if (KAL_TRUE == cb->bypass)
  {
    return VIDEO_ERROR_NONE;
  }

  switch(cb->state.eState)
  {
    case VIDEO_STATE_IDLE:
    ASSERT(0); // component in incorrect state...
      break;

    case VIDEO_STATE_RUN:
    {
#if defined(__VIDEO_SUBTITLE_SUPPORT__)
      // render Subtitle Frame
      if(vr_q_handle == &(cb->sub_vr_q_handle) &&
         NULL != cb->sub_dst_fb_addr_array[0].u4_fb_addr_plane0)
      {
        // if buffer flag is silent and KAL_FALSE == _va2_vr_vp_6276_sub_src_removed
        // or buffer flag isn't silent and KAL_TRUE == _va2_vr_vp_6276_sub_src_removed
        // a ilm message will be sent to do wfc source remove or restore
        if ((VIDEO_BUFFERFLAG_SILENT == prBuffHeader->eFlags && KAL_FALSE == _va2_vr_vp_6276_sub_src_removed) ||
            (VIDEO_BUFFERFLAG_SILENT != prBuffHeader->eFlags && KAL_TRUE == _va2_vr_vp_6276_sub_src_removed))
        {
          _va2_vr_vp_6276_subtitle_source_operation(cb,_va2_vr_vp_6276_sub_src_removed);
          // reverse the _va2_vr_vp_6276_sub_src_removed flag after doing source operation
          _va2_vr_vp_6276_sub_src_removed ^= KAL_TRUE;  
        }

        if (KAL_FALSE == cb->IsSubtitleBusy)
        {
#if defined (VIDEO_RENDERER_SUPPORT_MULTIPLE_VIDEO_FRAME)
          va2_util_buf_hdr_advance_to_the_latest_buffer_header(vr_q_handle);
#endif
          // render the subtitle frame is not silent, else bypass the subtitle render process
          if (VIDEO_BUFFERFLAG_SILENT != prBuffHeader->eFlags)
          {
            va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_API_________EMPTY_THIS_BUFFER__SUBTITLE_TRIGGER_ROTATOR, (kal_uint32) (cb->sub_vr_q_handle.curr_dspl_buf_hdr));
            _va2_vr_vp_6276_render_subtitle_frame_buffer(cb, KAL_FALSE);
          }
          else
          {
            va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_API_________EMPTY_THIS_BUFFER__SUBTITLE_SILENT_FRAME, (kal_uint32) (cb->sub_vr_q_handle.curr_dspl_buf_hdr));
          }
        }
        else
        {
          va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_API_________EMPTY_THIS_BUFFER__SUBTITLE_ENQUEUE_ONLY, (kal_uint32) (cb->sub_vr_q_handle.to_be_processed_q.tail));
        }
      }
      else
#endif
      // render Video Frame
      {
        if (KAL_FALSE == cb->IsRendererBusy)
        {
#if defined (VIDEO_RENDERER_SUPPORT_MULTIPLE_VIDEO_FRAME)
          va2_util_buf_hdr_advance_to_the_latest_buffer_header(vr_q_handle);
#endif
          va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_API_________EMPTY_THIS_BUFFER__TRIGGER_HW, (kal_uint32) (cb->vr_q_handle.curr_dspl_buf_hdr));
          _va2_vr_vp_6276_process_input_buffer(cb, KAL_FALSE, 1);
        }
        else
        {
          va2_vr_add_trace(&_va2_vr_vp_6276_debug_trace[0], VA2_VR_API_________EMPTY_THIS_BUFFER__ENQUEUE_ONLY, (kal_uint32) (cb->vr_q_handle.to_be_processed_q.tail));
        }
        cb->u4LastSrcRenderTimestamp = drv_get_current_time();
      }
    }
      break;

    case VIDEO_STATE_STOP:
      //ASSERT(0); // component in incorrect state...
      break;

    default:
    ASSERT(0); // component in incorrect state...
      break;
  } // end of switch(cb->state.eState)

  return VIDEO_ERROR_NONE;
}

/**
 *  @status OK
 *  @remark not supported...
 *  @common VR
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6276_fill_this_buffer(
  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
  //va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6276_cb;
  VIDEO_ERROR_TYPE_T i4Ret = VIDEO_ERROR_NONE;
  
  #if 0
/* under construction !*/
  #else
  ASSERT(0); // This primitive is not supported!
  #endif

  return i4Ret;
}

/**
 *  @status OK
 *  @common VR
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6276_set_callbacks(
  VIDEO_CALLBACK_TYPE_T *prCallback)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6276_cb;
  VIDEO_ERROR_TYPE_T i4Ret;

  kal_take_sem(cb->vr_sema_vrstate_sync, KAL_INFINITE_WAIT);
  i4Ret = va2_vr_set_callbacks(&_va2_vr_vp_6276_cb, prCallback);
  kal_give_sem(cb->vr_sema_vrstate_sync);

  return i4Ret;
}

/**
 *  @status OK
 *  @remark this function could only be invoked when in CLOSE state.
 */
VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6276_deinit(void)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6276_cb;
  VIDEO_ERROR_TYPE_T i4Ret;

#if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("DIN", SA_start);
#endif  // #if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)

  kal_take_sem(cb->vr_sema_vrstate_sync, KAL_INFINITE_WAIT);
  i4Ret = va2_vr_deinit(&_va2_vr_vp_6276_cb);
  va2_vr_init_trace(0, NULL);
  kal_give_sem(cb->vr_sema_vrstate_sync);

#if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("DIN", SA_stop);
#endif  // #if defined(VA2_VR_VP_6276_ENABLE_SWLA_TRACE)

  return i4Ret;
}

#endif  // #if defined(__MTK_TARGET__)

/****************************************************************************
 * external function bodies
 ****************************************************************************/
/**
 *  @status OK
 */
VIDEO_COMPONENT_TYPE_T* 
va2_video_renderer_vp_mt6276_get_handle(
  VA2_VIDEO_RENDERER_TYPE_T e_type)
{
#if defined(__MTK_TARGET__)
  VIDEO_COMPONENT_TYPE_T *pr_video_renderer_comp = NULL;
  //VIDEO_ERROR_TYPE_T error_code = VIDEO_ERROR_NONE;

  switch (e_type)
  {
  case VIDEO_RENDERER_VIDEO_THUMBNAIL:
  case VIDEO_RENDERER_MJPG_THUMBNAIL:
    pr_video_renderer_comp = &_va2_vr_vp_6276_primitives;
    _va2_vr_vp_6276_cb.renderer_type = VIDEO_RENDERER_VIDEO_THUMBNAIL;
    break;

  case VIDEO_RENDERER_VIDEO_PLAYBACK:
  case VIDEO_RENDERER_MJPG_PLAYBACK:
    pr_video_renderer_comp = &_va2_vr_vp_6276_primitives;
    _va2_vr_vp_6276_cb.renderer_type = VIDEO_RENDERER_VIDEO_PLAYBACK;
    break;

  case VIDEO_RENDERER_VIDEO_SUBTITLE_PLAYBACK:
  case VIDEO_RENDERER_MJPG_SUBTITLE_PLAYBACK:
    pr_video_renderer_comp = &_va2_vr_vp_6276_primitives;
    _va2_vr_vp_6276_cb.renderer_type = VIDEO_RENDERER_VIDEO_SUBTITLE_PLAYBACK;
    break;

  default: 
    break;
  }


  // for MT6256 E2 MJPG only, set _va2_vr_vp_6276_render_mode
#if defined(DRV_IDP_MT6256_E2_SERIES) && defined(MJPG_DECODE)
  switch (e_type)
  {
    case VIDEO_RENDERER_VIDEO_THUMBNAIL:
    case VIDEO_RENDERER_VIDEO_PLAYBACK:
    case VIDEO_RENDERER_VIDEO_SUBTITLE_PLAYBACK:
      _va2_vr_vp_6276_render_mode = VIDEO;
      break;

    case VIDEO_RENDERER_MJPG_THUMBNAIL:    
    case VIDEO_RENDERER_MJPG_PLAYBACK:
    case VIDEO_RENDERER_MJPG_SUBTITLE_PLAYBACK:
      _va2_vr_vp_6276_render_mode = MJPEG;
      break;

    default: 
      break;
  }
#endif


#if 0 // extracted to va2_comp_video_renderer
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
#endif  // #if 0

  return pr_video_renderer_comp;
#else   // #if defined(__MTK_TARGET__)
  return NULL;
#endif  // #if defined(__MTK_TARGET__)
}

/**
 *  @status OK
 */
VIDEO_ERROR_TYPE_T 
va2_video_renderer_vp_mt6276_release_handle(
  VIDEO_COMPONENT_TYPE_T *pr_handle)
{
#if defined(__MTK_TARGET__)
  VIDEO_ERROR_TYPE_T error_code = VIDEO_ERROR_NONE;
  
  if ((NULL == pr_handle) || 
      (&_va2_vr_vp_6276_primitives != pr_handle) || 
      (NULL == pr_handle->pfnDeInit))
  {
    ASSERT(0); // incorrect param
  }
  error_code = pr_handle->pfnDeInit();
  return error_code;
#else   // #if defined(__MTK_TARGET__)
  return VIDEO_ERROR_DEINIT_ERROR;
#endif  // #if defined(__MTK_TARGET__)
}

#endif  // #if defined(VA2_VIDEO_RENDERER_VP_MT6276)
#endif  // #if defined(__VIDEO_ARCHI_V2__)
/// @}

