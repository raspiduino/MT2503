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
 *    va2_video_renderer_vp_mt6235.c
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
/// \ingroup va2_video_renderer_vp_mt6235
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
#include "va2_video_renderer_vp_mt6235.h"

#if defined(VA2_VIDEO_RENDERER_VP_MT6235)

/******* Kernal abstraction *****************/
#include "kal_public_api.h"
/******* VA2 common *************************/
#include "video_types_v2.h"
#include "video_comm_component_v2.h"
#include "video_buffer_management_v2.h"
/******* VA2 Video Renderer Component *******/
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
#include "idp_video_decode.h" /**< MT6235 Video Decode scenario header file. */
/******* LCD driver *************************/
#include "lcd_if.h" // TODO:[3] check inc path
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
#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
#include "SST_sla.h"
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)

#include "cache_sw.h"
#include "mmu.h"

#include "sw_video_resizer.h"
#include "idp_sw_yuv420_2_uyvy422_resizer.h"

/****************************************************************************
 * local type definitions and macros
 ****************************************************************************/
#define VA2_COMP_VR_RENDER_TIME_MAX             (6600) // (32768/1000)*33.3 ~ 1091 // 33.3ms
#define VA2_VR_VP_6235_DEBUG_TRACE_SIZE         (32)

/****************************************************************************
 * declarations
 ****************************************************************************/
#if defined(__MTK_TARGET__)


static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6235_init(void);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6235_send_command(
  VIDEO_COMMAND_TYPE_T eCmd, 
  kal_uint32 u4Param);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6235_get_parameter(
  VIDEO_PARAM_TYPE_T eCmd, 
  void *pParam);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6235_set_parameter(
  VIDEO_PARAM_TYPE_T eCmd, 
  void *pParam);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6235_use_buffer(
  kal_uint8 *pu1Buff, 
  kal_uint32 u4Size);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6235_empty_this_buffer(
  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6235_empty_this_buffer_real(
  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6235_fill_this_buffer(
  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6235_set_callbacks(
  VIDEO_CALLBACK_TYPE_T *prCallback);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6235_deinit(void);

kal_uint32  
_va2_vr_vp_6235_try_to_return_buffer_headers(
  va2_comp_video_renderer_cb_t *cb);

static kal_uint32
_va2_vr_vp_6235_sw_render_display_frame_buffer(
  va2_comp_video_renderer_cb_t *cb, 
  kal_bool blocking);
static kal_uint32
_va2_vr_vp_6235_hw_render_display_frame_buffer(
  va2_comp_video_renderer_cb_t *cb, 
  kal_bool blocking);


static kal_bool 
_va2_vr_vp_6235_check_params_configs(
  va2_comp_video_renderer_cb_t *cb);

static kal_bool 
_va2_vr_vp_6235_config_idp_by_render_mode(
  va2_comp_video_renderer_cb_t *cb, 
  VA2_VIDEO_FRAME_T *video_frame);

static void
_va2_vr_vp_6235_display_timer_hdlr(
  void *param);

static void
_va2_vr_vp_6235_idp_frame_done_cb(
  void *param);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6235_t01_close_to_init(
  va2_comp_video_renderer_cb_t *cb);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6235_t03_init_to_idle(
  va2_comp_video_renderer_cb_t *cb);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6235_t04_idle_to_run(
  va2_comp_video_renderer_cb_t *cb);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6235_t05_run_to_stop(
  va2_comp_video_renderer_cb_t *cb);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6235_t06_stop_to_run(
  va2_comp_video_renderer_cb_t *cb);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6235_t10_idle_to_close(
  va2_comp_video_renderer_cb_t *cb);

static void 
_va2_vr_vp_6235_lcd_frame_done_cb(
  void *param);

static void
_va2_vr_vp_6235_touch_from_inside_pitch(
  void *param);

static kal_bool 
_va2_vr_vp_6235_check_resize_ratio(
  va2_comp_video_renderer_cb_t *cb);

static void
_va2_vr_vp_6235_sw_resizer_frmae_done_cb(
  void *param);

static void
_va2_vr_vp_6235_hisr_trigger_display(
  void);


#endif  // #if defined(__MTK_TARGET__)

/****************************************************************************
 * local variables
 ****************************************************************************/
#if defined(__MTK_TARGET__)


kal_uint32 (*render_dspl_frame_buf)(va2_comp_video_renderer_cb_t *cb, kal_bool blocking);


/**
 *  @status OK
 */
static VIDEO_COMPONENT_TYPE_T _va2_vr_vp_6235_primitives = 
{
    _va2_vr_vp_6235_init
  , _va2_vr_vp_6235_send_command
  , _va2_vr_vp_6235_get_parameter
  , _va2_vr_vp_6235_set_parameter
  , _va2_vr_vp_6235_use_buffer
  , _va2_vr_vp_6235_empty_this_buffer
  , _va2_vr_vp_6235_fill_this_buffer
  , _va2_vr_vp_6235_set_callbacks
  , _va2_vr_vp_6235_deinit
};

static struct va2_comp_video_renderer_cb _va2_vr_vp_6235_cb = 
  {
    {
      _va2_vr_vp_6235_t01_close_to_init, 
      va2_vr_t02_init_to_close, 
      _va2_vr_vp_6235_t03_init_to_idle, 
      _va2_vr_vp_6235_t04_idle_to_run, 
      _va2_vr_vp_6235_t05_run_to_stop, 
      _va2_vr_vp_6235_t06_stop_to_run, 
      va2_vr_t07_run_to_idle, 
      va2_vr_t08_stop_to_idle, 
      va2_vr_t09_idle_to_init, 
      _va2_vr_vp_6235_t10_idle_to_close, 
      va2_vr_t11_stop_to_close, 
      va2_vr_t12_idle_to_idle,
      _va2_vr_vp_6235_try_to_return_buffer_headers, 
      _va2_vr_vp_6235_check_params_configs, 
      _va2_vr_vp_6235_config_idp_by_render_mode, 
      (va2_vr_dspl_timer_hdlr_func_t) _va2_vr_vp_6235_display_timer_hdlr, 
      (va2_vr_hw_frame_done_cb_func_t) _va2_vr_vp_6235_idp_frame_done_cb, 
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

/**
 *  The control of IDP
 *  @remark set it back to 0 when IDP is closed.
 *  @common none
 */

static va2_vr_debug_trace_entry_t _va2_vr_vp_6235_debug_trace[VA2_VR_VP_6235_DEBUG_TRACE_SIZE] = {0};
#endif  // #if defined(__MTK_TARGET__)

#if defined(DRV_DISPLAY_DRIVER_V2)
static WFCDevice _va2_vr_vp_6235_ddv2_dev = WFC_INVALID_HANDLE;
static WFCContext _va2_vr_vp_6235_ddv2_ctx = WFC_INVALID_HANDLE;
static WFCElement _va2_vr_vp_6235_ddv2_element = WFC_INVALID_HANDLE;
static WFCSource _va2_vr_vp_6235_ddv2_src = WFC_INVALID_HANDLE;
static OWFNativeStreamType _va2_vr_vp_6235_ddv2_stream = OWF_INVALID_HANDLE;
static WFCSource _va2_vr_vp_6235_ddv2_img_src = WFC_INVALID_HANDLE;
static kal_uint32 _va2_vr_vp_6235_dspl_fbs[3][2] = { 0 };
static volatile kal_bool _va2_vr_vp_6235_lcd_frame_done = KAL_TRUE;
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)

//Below variables are used by Touch Frame Inside.
static kal_uint32 fb_width,fb_heigh;
static kal_uint32 inside_dst_x = 0,inside_dst_y = 0;
static kal_uint32 target_pitch =0;
static kal_uint32 offset_x = 0;

static kal_uint32 inside_dst_start_offset;
static VA2_CLIP_WINDOW_T video_src_clip;
static VA2_FRAME_SIZE_T video_target_size;

static kal_uint32 new_source_width =0;
static kal_uint32 new_source_height =0;
static kal_uint32 new_source_offset =0;
static kal_bool bIsSpecialVideoResolution;
static kal_uint32 hw_src_width =0;
static kal_uint32 hw_src_height =0;

/****************************************************************************
 * External References
 ****************************************************************************/
#if defined(__MTK_TARGET__)
extern VIDEO_BUFFERHEADER_TYPE_T _rBlackBufferHdr;
extern VA2_VIDEO_FRAME_T _rBlackVdoFrm;

extern kal_bool   _va2_comp_vr_have_config_lcd;
extern kal_uint32 _va2_comp_vr_triggered_lcd_id_this_time;

#define CCASSERT(predicate) _x_CCASSERT_LINE(predicate, __LINE__)
#define _x_CCASSERT_LINE(predicate, line) typedef char constraint_violated_on_line_##line[2*((predicate)!=0)-1];


static kal_uint32 ispVideoFrame_UYVY422;
// TODO: W1045 Code Review g_EnterRendererState remove
static kal_bool volatile g_bBusy = KAL_FALSE;
static kal_bool volatile g_bBusy_SW_YUV420_2_UYVY422 = KAL_FALSE;
static kal_bool volatile g_bBusy_TouchInSide_Pitch = KAL_FALSE;

#define IDP_SW_YUV420_2_UYVY422_RESIZER__DYNAMIC_SWITCH_CACHEABLE

#endif  // #if defined(__MTK_TARGET__)

/****************************************************************************
 * local function bodies
 ****************************************************************************/
#if defined(__MTK_TARGET__)

#if defined(DRV_DISPLAY_DRIVER_V2)
void _va2_vr_vp_6235_wfc_frame_done_cb(
  WFCContextEventTypeMTK event, 
  void* param)
{
  _va2_vr_vp_6235_lcd_frame_done_cb(param);
}
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)

static void _va2_vr_vp_6235_lcd_frame_done_cb(void *param)
{
  kal_uint32 const saved_mask = SaveAndSetIRQMask();
  _va2_vr_vp_6235_lcd_frame_done = KAL_TRUE;
  RestoreIRQMask(saved_mask);
}

static void 
_va2_vr_vp_6235_config_n_activate_ddv2( 
  va2_comp_video_renderer_cb_t *cb)
{
#if defined(DRV_DISPLAY_DRIVER_V2)
  kal_check_stack();

  // TODO: [m] Which variable can decide if display needs to work? 
  {
    WFCint displayInputWidth, displayInputHeight; // The output width/height of MM...

    _va2_vr_vp_6235_ddv2_dev = cb->display_surface.dspl_dev_handle;
    _va2_vr_vp_6235_ddv2_ctx = cb->display_surface.dspl_ctx_handle;
    _va2_vr_vp_6235_ddv2_element = cb->display_surface.dspl_element_handle;

    // Check if this element is a video layer...for debug only and can be removed for last QC stage...
    if (WFC_FALSE == wfcGetElementAttribi(_va2_vr_vp_6235_ddv2_dev, _va2_vr_vp_6235_ddv2_element, WFC_ELEMENT_VIDEO_LAYER_MTK))
    {
        // TODO: [m] Make GDI add this line...
        wfcMMSetElementAttribi(_va2_vr_vp_6235_ddv2_dev, _va2_vr_vp_6235_ddv2_element, WFC_ELEMENT_VIDEO_LAYER_MTK, WFC_TRUE);
    }
    {
      wfcMMSetContextAttribi(_va2_vr_vp_6235_ddv2_dev, _va2_vr_vp_6235_ddv2_ctx, WFC_CONTEXT_AUTONOMOUS_SYNC_MODE_MTK, (WFCint) WFC_AUTONOMOUS_SYNC_TO_ELEMENT);
      wfcMMSetContextAttribi(_va2_vr_vp_6235_ddv2_dev, _va2_vr_vp_6235_ddv2_ctx, WFC_CONTEXT_AUTONOMOUS_PERIOD_MTK, (WFCint) 30);
      wfcMMSetContextAttribi(_va2_vr_vp_6235_ddv2_dev, _va2_vr_vp_6235_ddv2_ctx, WFC_CONTEXT_AUTONOMOUS_SYNC_ELEMENT_MTK, (WFCint) _va2_vr_vp_6235_ddv2_element);
      wfcMMSetContextAttribi(_va2_vr_vp_6235_ddv2_dev, _va2_vr_vp_6235_ddv2_ctx, WFC_CONTEXT_CURRENT_REFRESH_RATE_MTK, 0);
    }

    // Derive the output width/height of MDP, which should be the input width height of Display

    displayInputWidth = cb->dst_size.u4_width;
    displayInputHeight = cb->dst_size.u4_height;
    //Touch Inside used in stop_n_deactivate_ddv2
    fb_width = cb->dst_fb_size.u4_width;
    fb_heigh = cb->dst_fb_size.u4_height;

    // Config Display Rotation angle & flip
    {
      WFCRotation layerRotation;

      layerRotation = (WFCRotation) 
        wfcGetElementAttribi(_va2_vr_vp_6235_ddv2_dev, _va2_vr_vp_6235_ddv2_element, WFC_ELEMENT_SOURCE_ROTATION);

      // MT6235 MDP cannot rotate
      // MDP/LCD rotation is done by LCD fast read rotator.
      // So the source clipping for LCD layer rotation should be correct...
      wfcMMSetElementAttribi(_va2_vr_vp_6235_ddv2_dev, _va2_vr_vp_6235_ddv2_element, WFC_ELEMENT_SOURCE_ROTATION, layerRotation);

      // Config Display Source width/height (The output of MDP) and source clip/pitch
      if (KAL_FALSE == cb->bypass_hw_layer_src_rect)
      {
        WFCint srcRect[4];
        srcRect[0] = 0;
        srcRect[1] = 0;
        srcRect[2] = displayInputWidth;
        srcRect[3] = displayInputHeight;
        wfcMMSetElementAttribiv(_va2_vr_vp_6235_ddv2_dev, _va2_vr_vp_6235_ddv2_element, WFC_ELEMENT_SOURCE_RECTANGLE, 4, &srcRect[0]);
      }
      else
      {
        cb->bypass_hw_layer_src_rect = KAL_FALSE;
      }

      switch (layerRotation) 
      {
      case WFC_ROTATION_0: 
        cb->rotate_flip.u2_cw_rotate_angle = 0;
        break;
      case WFC_ROTATION_90: 
        cb->rotate_flip.u2_cw_rotate_angle = 90;
        break;
      case WFC_ROTATION_180: 
        cb->rotate_flip.u2_cw_rotate_angle = 180;
        break; 
      case WFC_ROTATION_270: 
        cb->rotate_flip.u2_cw_rotate_angle = 270;
        break;
      default: 
        VRNDRR_DD_ASSERT(0);
        break;
      }
    

    }
   
    if ((90 == cb->rotate_flip.u2_cw_rotate_angle) || 
        (270 == cb->rotate_flip.u2_cw_rotate_angle))
    {
      // Frame buffer is actually rotated, To align with MT6268/36/76..etc
      cb->dst_fb_size.u4_height ^= cb->dst_fb_size.u4_width;
      cb->dst_fb_size.u4_width ^= cb->dst_fb_size.u4_height;
      cb->dst_fb_size.u4_height ^= cb->dst_fb_size.u4_width;
    }
    
    // TODO: [m] This is only for testing and should be removed.
    // Layer ROI offset does not change...use the setting from GDI...

    // Create stream...
    {
        OWF_IMAGE_FORMAT imageFormat;
        kal_uint32 bufs[2];

        imageFormat.linear = OWF_FALSE;
        imageFormat.premultiplied = OWF_FALSE;
        imageFormat.rowPadding = 0;
        switch (cb->dst_color_format)
        {
        case VIDEO_RENDERER_COLOR_RGB565: 
            imageFormat.pixelFormat = OWF_IMAGE_RGB565;
            break;
        case VIDEO_RENDERER_COLOR_RGB888: 
            imageFormat.pixelFormat = OWF_IMAGE_RGB888;
            break;
        case VIDEO_RENDERER_COLOR_BGR888: 
            imageFormat.pixelFormat = OWF_IMAGE_BGR888;
            break;
        case VIDEO_RENDERER_COLOR_ARGB8888: 
            imageFormat.pixelFormat = OWF_IMAGE_ARGB8888;
            break;
        case VIDEO_RENDERER_COLOR_PACKED_UYVY422: 
            imageFormat.pixelFormat = OWF_IMAGE_UYVY;
            break;
        default: 
            VRNDRR_DD_ASSERT(0); // TODO: [o] Need error handling...
            imageFormat.pixelFormat = OWF_IMAGE_RGB565;
            break;
        }

        _va2_vr_vp_6235_dspl_fbs[0][0] = bufs[0] = cb->dst_fb_addr_array[1].u4_fb_addr_plane0;
        _va2_vr_vp_6235_dspl_fbs[1][0] = bufs[1] = cb->dst_fb_addr_array[2].u4_fb_addr_plane0;

        // TODO: [m] When to destroy the stream? Where is the exit function?
        // TODO: [o] magical number here...
        _va2_vr_vp_6235_ddv2_stream = 
            owfNativeStreamCreateImageStreamEx((OWFint) displayInputWidth, 
                                               (OWFint) displayInputHeight, 
                                               &imageFormat, (OWFint) 2, (void**) &bufs[0]);

        // This code segment is used to do buffer control...
        {
          void * bufPtr;
          OWFNativeStreamBuffer buf;

          buf = owfNativeStreamAcquireWriteBuffer(_va2_vr_vp_6235_ddv2_stream);
          bufPtr = owfNativeStreamGetBufferPtr(_va2_vr_vp_6235_ddv2_stream, buf);
          VRNDRR_DD_ASSERT(NULL != bufPtr);

          if (_va2_vr_vp_6235_dspl_fbs[0][0] == (kal_uint32) bufPtr)
          {
            _va2_vr_vp_6235_dspl_fbs[0][1] = (kal_uint32) buf;
            _va2_vr_vp_6235_dspl_fbs[1][1] = owfNativeStreamAcquireWriteBuffer(_va2_vr_vp_6235_ddv2_stream);
          }
          else
          {
            _va2_vr_vp_6235_dspl_fbs[1][1] = (kal_uint32) buf;
            _va2_vr_vp_6235_dspl_fbs[0][1] = owfNativeStreamAcquireWriteBuffer(_va2_vr_vp_6235_ddv2_stream);
          }
        }

        _va2_vr_vp_6235_ddv2_src = wfcCreateSourceFromStream(_va2_vr_vp_6235_ddv2_dev, _va2_vr_vp_6235_ddv2_ctx, (WFCNativeStreamType) _va2_vr_vp_6235_ddv2_stream, NULL);

        // TODO: [m] Need an API to set buffers into the stream...

        if (WFC_INVALID_HANDLE == _va2_vr_vp_6235_ddv2_src)
        {
            VRNDRR_DD_ASSERT(0); // TODO: [m] remove this after IT done...need error handling...
        }
    }

    // Set Element source
    wfcMMSetElementAttribi(_va2_vr_vp_6235_ddv2_dev, _va2_vr_vp_6235_ddv2_element, WFC_ELEMENT_SOURCE, (WFCint) _va2_vr_vp_6235_ddv2_src);

    // TODO: [m] If camera preview only uses double display frame buffer, DDv2 needs to sync to content provider...since camera cannot wait...

    // Add cb function
    {
      WFCint array[4];
      array[0] = (WFCint) WFC_CONTEXT_EVENT_COMPOSITION_FINISH_ALWAYS_CALLBACK_MTK;
      array[1] = (WFCint) _va2_vr_vp_6235_wfc_frame_done_cb;
      array[2] = (WFCint) cb;
      array[3] = (WFCint) WFC_TRUE;
      wfcMMSetContextAttribiv(_va2_vr_vp_6235_ddv2_dev, _va2_vr_vp_6235_ddv2_ctx, WFC_CONTEXT_CALLBACK_MTK, 4, &array[0]);
    }

    // Commmit
    wfcMMCommit(_va2_vr_vp_6235_ddv2_dev, _va2_vr_vp_6235_ddv2_ctx, _va2_vr_vp_6235_ddv2_element, WFC_COMMIT_CONTEXT_AND_ELEMENT);
  }
  kal_check_stack();
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)
}


static void 
_va2_vr_vp_6235_stop_n_deactivate_ddv2( 
  va2_comp_video_renderer_cb_t *cb)
{
#if defined(DRV_DISPLAY_DRIVER_V2)
  kal_check_stack();
  // TODO: [m] Which variable can decide if display needs to work? 
  if (OWF_INVALID_HANDLE != _va2_vr_vp_6235_ddv2_stream)
  {
    if ((WFC_INVALID_HANDLE == _va2_vr_vp_6235_ddv2_dev) || 
        (WFC_INVALID_HANDLE == _va2_vr_vp_6235_ddv2_ctx) || 
        (WFC_INVALID_HANDLE == _va2_vr_vp_6235_ddv2_element))
    {
      VRNDRR_DD_ASSERT(0);
    }

    // check the last frame has been flash out
    // TODO: [optional] Move this to the top most of this function...
    while(_va2_vr_vp_6235_lcd_frame_done == KAL_FALSE)
    {
      kal_sleep_task(1);
    }

    // Remove cb function
    {
      WFCint array[4];
      array[0] = (WFCint) WFC_CONTEXT_EVENT_COMPOSITION_FINISH_ALWAYS_CALLBACK_MTK;
      array[1] = (WFCint) _va2_vr_vp_6235_wfc_frame_done_cb;
      array[2] = (WFCint) cb;
      array[3] = (WFCint) WFC_FALSE;
      wfcMMSetContextAttribiv(_va2_vr_vp_6235_ddv2_dev, _va2_vr_vp_6235_ddv2_ctx, WFC_CONTEXT_CALLBACK_MTK, 4, &array[0]);
    }

    wfcMMSetElementAttribi(_va2_vr_vp_6235_ddv2_dev, _va2_vr_vp_6235_ddv2_element, WFC_ELEMENT_SOURCE, WFC_INVALID_HANDLE);
    {
      wfcMMSetContextAttribi(_va2_vr_vp_6235_ddv2_dev, _va2_vr_vp_6235_ddv2_ctx, WFC_CONTEXT_AUTONOMOUS_SYNC_MODE_MTK, (WFCint) WFC_AUTONOMOUS_SYNC_TO_TIMER);
      wfcMMSetContextAttribi(_va2_vr_vp_6235_ddv2_dev, _va2_vr_vp_6235_ddv2_ctx, WFC_CONTEXT_AUTONOMOUS_PERIOD_MTK, (WFCint) 0);
      wfcMMSetContextAttribi(_va2_vr_vp_6235_ddv2_dev, _va2_vr_vp_6235_ddv2_ctx, WFC_CONTEXT_AUTONOMOUS_SYNC_ELEMENT_MTK, (WFCint) 0);
      wfcMMSetContextAttribi(_va2_vr_vp_6235_ddv2_dev, _va2_vr_vp_6235_ddv2_ctx, WFC_CONTEXT_CURRENT_REFRESH_RATE_MTK, 30);
    }

    // Set an image source back to element
    {
      OWF_IMAGE image;
      OWF_PIXEL_FORMAT color_format = OWF_IMAGE_NOT_SUPPORTED;
      WFCint pixel_size = 0;
      // TODO: Add an image sourece
      if (_va2_vr_vp_6235_ddv2_img_src != WFC_INVALID_HANDLE)
      {
        wfcDestroySource(_va2_vr_vp_6235_ddv2_dev, _va2_vr_vp_6235_ddv2_img_src);
      }
     
      // Render to first frame buffer...
      {
        kal_uint32 save_irq_mask;
        if ((NULL == cb->vr_q_handle.curr_dspl_buf_hdr) && 
            (0 == cb->vr_q_handle.to_be_processed_q.size))
        {
          // TODO: draw the display frame buffer to black!
          if (NULL == cb->dst_fb_addr_array[0].u4_fb_addr_plane0)
          {
            ASSERT(0);
          }

          {
            kal_uint32 size = cb->dst_fb_size.u4_width * 
                              cb->dst_fb_size.u4_height * 
                              va2_util_get_bpp(cb->dst_color_format);
            kal_uint32 addr;
            if (0x0 != (addr = cb->dst_fb_start_addr_array[0].u4_fb_addr_plane0))
            {
              if (VIDEO_RENDERER_COLOR_RGB565 == cb->dst_color_format)
              {
                kal_mem_set((void*) addr, 0x0, size);  //black for RGB565
              }
              else
              {
                ASSERT(0);
              }
            }
          }
          va2_vr_add_trace(&_va2_vr_vp_6235_debug_trace[0], VA2_VR_DEBUG_______NO_VIDEO_FRAME_TO_DRAW, 0);
          image.data = (void*) cb->dst_fb_addr_array[0].u4_fb_addr_plane0;
        }
        else
        {

          VA2_VIDEO_FRAME_T *video_frame;
          va2_util_buf_hdr_q_item_t *curr_dspl_buf_hdr;
          save_irq_mask = SaveAndSetIRQMask();
          if((KAL_FALSE == cb->keep_curr_ptr_when_run) || (NULL == cb->vr_q_handle.curr_dspl_buf_hdr))
          {
            // If only one frame is inserted in Run state, this action is to emulate 
            // the processing of the previous Bypass-Mode Frames.
            va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
          }
          RestoreIRQMask(save_irq_mask);

          // Try to guarantee the index is 0 before get buffer...
          curr_dspl_buf_hdr = cb->vr_q_handle.curr_dspl_buf_hdr;

          // get frame data...
          video_frame = (VA2_VIDEO_FRAME_T*) curr_dspl_buf_hdr->buffer_header.pPrivateData;
          ASSERT(NULL != video_frame);

          kal_mem_cpy(&(cb->src_size), &(video_frame->r_fb_size), sizeof(VA2_FRAME_SIZE_T));
          kal_mem_cpy(&(cb->src_clip), &(video_frame->r_clip_window), sizeof(VA2_CLIP_WINDOW_T));
          kal_mem_cpy(&(cb->src_fb_addr), &(video_frame->r_fb_addr), sizeof(VA2_FRAME_BUFFER_ADDRESS_T));
          if (_va2_vr_vp_6235_check_resize_ratio(cb))
          {
            cb->funcs.render_dspl_frame_buf = _va2_vr_vp_6235_sw_render_display_frame_buffer;
            image.data = (void*) cb->funcs.render_dspl_frame_buf(cb, KAL_TRUE);
          }
          else
          {
            cb->funcs.render_dspl_frame_buf = _va2_vr_vp_6235_hw_render_display_frame_buffer;
            if (0 == _va2_comp_video_renderer_idp_key) 
            {
              if (KAL_FALSE == idp_video_decode_open(&_va2_comp_video_renderer_idp_key))          
              {
                cb->funcs.render_dspl_frame_buf = _va2_vr_vp_6235_sw_render_display_frame_buffer;
                image.data = (void*)cb->funcs.render_dspl_frame_buf(cb, KAL_TRUE);
              }
              else
              {
                image.data = (void*)cb->funcs.render_dspl_frame_buf(cb, KAL_TRUE);
                if (KAL_FALSE == idp_video_decode_stop(_va2_comp_video_renderer_idp_key))
                {
                  ASSERT(0);
                }
                if (KAL_FALSE == idp_video_decode_close(_va2_comp_video_renderer_idp_key))
                {
                  ASSERT(0);
                }
                _va2_comp_video_renderer_idp_key = 0;
              }
             }
           }
        }
      }
      if ((kal_uint32)image.data != cb->dst_fb_addr_array[0].u4_fb_addr_plane0 &&
          (kal_uint32)image.data != cb->dst_fb_addr_array[1].u4_fb_addr_plane0)
           {image.data = (void*) cb->dst_fb_addr_array[0].u4_fb_addr_plane0;}

      // TODO: buffer address refer to CalDisplayFBs[?][1] == 0x0
      // TODO: fill in this structure 
      {
        image.width = fb_width;
        image.height = fb_heigh;
      }
      switch(cb->dst_color_format)
      {
        case VIDEO_RENDERER_COLOR_RGB565:
          color_format = OWF_IMAGE_RGB565;
          pixel_size = 2;
        break;
        case VIDEO_RENDERER_COLOR_RGB888:
          color_format = OWF_IMAGE_RGB888;
          pixel_size = 3;
        break;
        case VIDEO_RENDERER_COLOR_ARGB8888:
          color_format = OWF_IMAGE_ARGB8888;
          pixel_size = 4;
        break;
        case VIDEO_RENDERER_COLOR_PACKED_UYVY422:
          color_format = OWF_IMAGE_UYVY;
          pixel_size = 2;
        break;
        default:
          VRNDRR_DD_ASSERT(0);
        break;
      }
      image.format.pixelFormat = color_format;
        
      image.format.linear = OWF_FALSE;
      image.format.premultiplied = OWF_TRUE;
      image.format.rowPadding = 0;
      image.foreign = OWF_TRUE; // don't care.
      image.alpha = 0xFF;
      image.pixelSize = pixel_size;
      image.dataMax = image.width * image.height * image.pixelSize; /* data buffer max size */
      image.stride = image.width * pixel_size; /**< number of bytes per line */
    
      _va2_vr_vp_6235_ddv2_img_src = wfcCreateSourceFromImage(_va2_vr_vp_6235_ddv2_dev, _va2_vr_vp_6235_ddv2_ctx, (WFCHandle) &image, NULL);
      VRNDRR_DD_ASSERT(_va2_vr_vp_6235_ddv2_img_src != WFC_INVALID_HANDLE);
      wfcMMSetElementAttribi(_va2_vr_vp_6235_ddv2_dev, _va2_vr_vp_6235_ddv2_element, WFC_ELEMENT_SOURCE, _va2_vr_vp_6235_ddv2_img_src);
      wfcMMCommit(_va2_vr_vp_6235_ddv2_dev, _va2_vr_vp_6235_ddv2_ctx, _va2_vr_vp_6235_ddv2_element, WFC_COMMIT_CONTEXT_AND_ELEMENT);
    }

    wfcDestroySource(_va2_vr_vp_6235_ddv2_dev, _va2_vr_vp_6235_ddv2_src);
    _va2_vr_vp_6235_ddv2_src = WFC_INVALID_HANDLE;
    _va2_vr_vp_6235_ddv2_element = WFC_INVALID_HANDLE;
    _va2_vr_vp_6235_ddv2_ctx = WFC_INVALID_HANDLE;
    _va2_vr_vp_6235_ddv2_dev = WFC_INVALID_HANDLE;
    
    owfNativeStreamDestroy(_va2_vr_vp_6235_ddv2_stream);
    _va2_vr_vp_6235_ddv2_stream = OWF_INVALID_HANDLE;

    kal_mem_set((void*) _va2_vr_vp_6235_dspl_fbs, 0x0, sizeof(kal_uint32)*3*2);
  }
  kal_check_stack();
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)
}

static void
_va2_vr_vp_6235_trigger_display(
  kal_uint32 dspl_fb, 
  va2_comp_video_renderer_cb_t *cb)
{
#if defined(DRV_DISPLAY_DRIVER_V2)
  if ((KAL_TRUE == cb->trigger_display) && 
      (OWF_INVALID_HANDLE != _va2_vr_vp_6235_ddv2_stream))
  {
    OWFNativeStreamBuffer buf;
    if (dspl_fb == _va2_vr_vp_6235_dspl_fbs[0][0])
    {
      buf = (OWFNativeStreamBuffer) _va2_vr_vp_6235_dspl_fbs[0][1];
      if (buf==0)
      {
        return;
      }
      {
        kal_uint32 const saved_mask = SaveAndSetIRQMask();
        _va2_vr_vp_6235_lcd_frame_done = KAL_FALSE;
        RestoreIRQMask(saved_mask);
      }

      owfNativeStreamReleaseWriteBuffer(_va2_vr_vp_6235_ddv2_stream, 
                                      buf/* (OWFNativeStreamBuffer) 0x100 */, 
                                      NULL /* (EGLDisplay) */, 
                                      NULL /* (EGLSyncKHR) */);
      _va2_vr_vp_6235_dspl_fbs[0][1] = 0x0;
      if (0x0 == _va2_vr_vp_6235_dspl_fbs[1][1])
      {
        _va2_vr_vp_6235_dspl_fbs[1][1] = (kal_uint32) owfNativeStreamAcquireWriteBuffer(_va2_vr_vp_6235_ddv2_stream);
      }
    }
    else
    {
      buf = (OWFNativeStreamBuffer) _va2_vr_vp_6235_dspl_fbs[1][1];
      if (buf==0)
      {
        return;
      }
      {
        kal_uint32 const saved_mask = SaveAndSetIRQMask();
        _va2_vr_vp_6235_lcd_frame_done = KAL_FALSE;
        RestoreIRQMask(saved_mask);
      }
      owfNativeStreamReleaseWriteBuffer(_va2_vr_vp_6235_ddv2_stream, 
                                      buf/* (OWFNativeStreamBuffer) 0x100 */, 
                                      NULL /* (EGLDisplay) */, 
                                      NULL /* (EGLSyncKHR) */);

      _va2_vr_vp_6235_dspl_fbs[1][1] = 0x0;
      if (0x0 == _va2_vr_vp_6235_dspl_fbs[0][1])
      {
        _va2_vr_vp_6235_dspl_fbs[0][1] = (kal_uint32) owfNativeStreamAcquireWriteBuffer(_va2_vr_vp_6235_ddv2_stream);
      }
    }
  }
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)
}


/**
 *  @description IL Client has a limitation that the error notify event can't be sent under VR's Stop state
 */
static void 
_va2_vr_vp_6235_notify_error_to_client(
  va2_comp_video_renderer_cb_t *cb)
{
  if ((NULL != cb) && 
      (NULL != cb->state.prCallback) && 
      (NULL != cb->state.prCallback->pfnEventHandler))
  {
    if (KAL_FALSE == cb->bIsErrorNotified)
    {
      cb->state.prCallback->pfnEventHandler(VIDEO_EVENT_ERROR, 0, 0, NULL);
      cb->bIsErrorNotified = KAL_TRUE;
    }
  }
  else
  {
    ASSERT(0); // No callback function set?
  }
}

/**
 *  @status OK
 */
kal_uint32  
_va2_vr_vp_6235_try_to_return_buffer_headers(
  va2_comp_video_renderer_cb_t *cb)
{
  va2_util_buf_hdr_q_item_t *item = NULL;
  
  // while there is still item in the to be returned queue
  while (NULL != (item = cb->vr_q_handle.to_be_returned_q.head))
  {
    if(((kal_uint32)(item->buffer_header.pPrivateData)) != ((kal_uint32)(&_rBlackVdoFrm)))
    {
      // return it by invoking the FillThisBuffer hook of peer component
      if (VIDEO_ERROR_NONE != cb->state.rInputComp[0].prComp->pfnFillThisBuffer(&(item->buffer_header)))
      {
        // break if any error happens
        break;
      }
    }
    else
    {

    }
    // dequeue from the to be returned queue...
    item = va2_util_buf_hdr_dequeue(&(cb->vr_q_handle.to_be_returned_q));
    // release q items back to pool...
    kal_mem_set((void*) item, 0x0, sizeof(va2_util_buf_hdr_q_item_t));
  }
  return 0;
}

static kal_bool 
_va2_vr_vp_6235_check_special_video_resolution_touch_from_inside_only(
  va2_comp_video_renderer_cb_t *cb)
{
  if ((cb->src_size.u4_width == 176) && (cb->src_size.u4_height == 144) ||
      (cb->src_size.u4_width == 320) && (cb->src_size.u4_height == 240) ||
      (cb->src_size.u4_width == 352) && (cb->src_size.u4_height == 288) ||
      (cb->src_size.u4_width == 240) && (cb->src_size.u4_height == 160) ||
      (cb->src_size.u4_width == 480) && (cb->src_size.u4_height == 320) ||
      (cb->src_size.u4_width == 640) && (cb->src_size.u4_height == 480) ||
      (cb->src_size.u4_width == 640) && (cb->src_size.u4_height == 360) ||
      (cb->src_size.u4_width == 160) && (cb->src_size.u4_height == 120) ||
      (cb->src_size.u4_width == 88) && (cb->src_size.u4_height ==  77)  ||
      (cb->src_size.u4_width == 80) && (cb->src_size.u4_height ==  60)  ||
      (cb->src_size.u4_width == 320) && (cb->src_size.u4_height == 180))
  {
    return KAL_TRUE;
  }
  else
  {
    return KAL_FALSE;
  }
}

/**
 *  @status OK
 *  @common IDP API dependent
 */
static kal_bool 
_va2_vr_vp_6235_check_resize_ratio(
  va2_comp_video_renderer_cb_t *cb)
{
    //Yout must calculate in outside mode.
    kal_uint32 clip_width,clip_height;
    kal_uint32 target_w, target_h;
    kal_uint32 n_src_width = 0;
    kal_uint32 n_src_height = 0;
    kal_uint32 n_src_offset = 0;
    kal_bool bSpecVideoCheckSize = KAL_FALSE;
    static VA2_CLIP_WINDOW_T check_src_clip;
    kal_mem_cpy(&(check_src_clip), &(cb->src_clip), sizeof(VA2_CLIP_WINDOW_T));
    target_w = cb->dst_size.u4_width;
    target_h = cb->dst_size.u4_height;
    if (VIDEO_RENDERER_RENDER_MODE_TOUCH_WINDOW_FROM_OUTSIDE == cb->render_mode)
    {
        kal_uint32 src_clip_w, src_clip_h;
        kal_uint32 new_src_clip_w, new_src_clip_h;    
        kal_uint32 new_src_clip_top, new_src_clip_bottom;    
        kal_uint32 new_src_clip_left, new_src_clip_right;    
        kal_uint32 diff_w,diff_h;
        kal_uint32 h_ratio,v_ratio;
        
        //Initialization
        new_src_clip_top = check_src_clip.u4_clip_top;
        new_src_clip_bottom = check_src_clip.u4_clip_bottom;
        new_src_clip_left = check_src_clip.u4_clip_left;
        new_src_clip_right = check_src_clip.u4_clip_right;

        // src clip window size
        if (KAL_TRUE == cb->src_clip.b_clip_enable)
        {
          src_clip_w = cb->src_clip.u4_clip_right - cb->src_clip.u4_clip_left + 1;
          src_clip_h = cb->src_clip.u4_clip_bottom - cb->src_clip.u4_clip_top + 1;
        }
        else
        {
          src_clip_w = cb->src_size.u4_width;
          src_clip_h = cb->src_size.u4_height;
        }
        ASSERT(0 != src_clip_w);
        ASSERT(0 != src_clip_h);
        
        // compute min. dst_size bigger than dst_fb_size to keep src_size ratio...
        {
          h_ratio = (cb->dst_size.u4_width<<16)/src_clip_w;
          v_ratio = (cb->dst_size.u4_height<<16)/src_clip_h;
          if (h_ratio > v_ratio)
          {
            // dst_h needs not to be changed...
            new_src_clip_h = (cb->dst_size.u4_height<<16) / h_ratio;
            new_src_clip_h = ((new_src_clip_h + 1) >> 1 ) <<1;
            new_src_clip_w = src_clip_w;
            diff_h = (src_clip_h - new_src_clip_h) / 2;
            new_src_clip_top = cb->src_clip.u4_clip_top + diff_h;
            if ((new_src_clip_top & 0x01)==0x01)
            {
              new_src_clip_top = new_src_clip_top + 1;
            }
            new_src_clip_bottom = new_src_clip_top + new_src_clip_h -1;
            //For consistent with sw color format transform and sw resizer
            check_src_clip.u4_clip_top = new_src_clip_top;
            check_src_clip.u4_clip_bottom = new_src_clip_bottom;
          }
          else if (h_ratio < v_ratio)
          {
            // dst_w needs not to be changed...
            new_src_clip_w = (cb->dst_size.u4_width<<16) / v_ratio;
            new_src_clip_w = ((new_src_clip_w + 1) >> 1 ) <<1;
            new_src_clip_h = src_clip_h;
            diff_w = (src_clip_w - new_src_clip_w) / 2;
            new_src_clip_left = cb->src_clip.u4_clip_left + diff_w;
            if ((new_src_clip_left & 0x01)==0x01)
            {
              new_src_clip_left = new_src_clip_left + 1;
            }
            new_src_clip_right = new_src_clip_left + new_src_clip_w -1;
            //For consistent with sw color format transform and sw resizer
            check_src_clip.u4_clip_left = new_src_clip_left;
            check_src_clip.u4_clip_right = new_src_clip_right;
          }
          else  //Equal
          {
          
          }
        }
    
    }
    else if (VIDEO_RENDERER_RENDER_MODE_TOUCH_WINDOW_FROM_INSIDE == cb->render_mode)
    {
        kal_uint32 src_clip_w, src_clip_h;
        kal_uint32 w_after_rot, h_after_rot;
        kal_uint32 ori_src_width,ori_src_height;
        kal_bool bSpecVideo;
        kal_uint32 dst_pitch;
        kal_uint32 h_ratio,v_ratio;

        if ((90 == cb->rotate_flip.u2_cw_rotate_angle) || 
           (270 == cb->rotate_flip.u2_cw_rotate_angle))
        {
           target_w = cb->dst_fb_size.u4_height;
           target_h = cb->dst_fb_size.u4_width;
        }
        else
        {
           target_w = cb->dst_fb_size.u4_width;
           target_h = cb->dst_fb_size.u4_height;
        }
        w_after_rot = target_w;
        h_after_rot = target_h;
        dst_pitch = target_w;
        bSpecVideo = _va2_vr_vp_6235_check_special_video_resolution_touch_from_inside_only(cb);
        
        // src clip window size
        if (KAL_TRUE == cb->src_clip.b_clip_enable)
        {
          src_clip_w = cb->src_clip.u4_clip_right - cb->src_clip.u4_clip_left + 1;
          src_clip_h = cb->src_clip.u4_clip_bottom - cb->src_clip.u4_clip_top + 1;
        }
        else
        {
          src_clip_w = cb->src_size.u4_width;
          src_clip_h = cb->src_size.u4_height;
        }
        ori_src_width = src_clip_w;
        ori_src_height = src_clip_h;
        {
          h_ratio = (target_w<<16)/src_clip_w;
          v_ratio = (target_h<<16)/src_clip_h;
        
          if (h_ratio < v_ratio)
          {
            // dst_w needs not to be changed...
            //target_h = (h_ratio*src_clip_h)>>16;
            target_h = (((((h_ratio*src_clip_h)>>16)+1)>>1)<<1);
            if (target_h == 0) {target_h = 2;}
          }
          else if (h_ratio > v_ratio)
          {
            // dst_h needs not to be changed...
            //target_w = (v_ratio*src_clip_w)>>16;
            target_w =  (((((v_ratio*src_clip_w)>>16)+1)>>1)<<1);
            if (target_w == 0) {target_w = 2;}
          }
        }
        {
            kal_uint32 dst_x = 0,dst_y = 0;
        
            if (w_after_rot == target_w)
            {
              ASSERT(h_after_rot >= target_h);
              dst_x = 0;
              dst_y = (h_after_rot - target_h)>>1;
              if ((dst_y & 0x1) == 1)
              {
                dst_y--;
                target_h+=2;
              }

            }
            else if (h_after_rot == target_h)
            {
              ASSERT(w_after_rot >= target_w);
              dst_x = (w_after_rot - target_w)>>1;
              dst_y = 0;
              if ((dst_x & 0x1) == 1)
              {
                dst_x--;
                target_w+=2;
              }
              if (KAL_TRUE == bSpecVideo)
              {
                n_src_width = (((((dst_pitch<<16) / v_ratio)+1)>>1)<<1);
                n_src_height = ori_src_height;
                n_src_offset = (n_src_width-ori_src_width)/2;
                if ((n_src_offset & 0x01)==0x01)
                {
                  n_src_offset--;
                }
                n_src_width = (2*n_src_offset)+ori_src_width;
                bSpecVideoCheckSize = KAL_TRUE;
                if ((2*n_src_width*n_src_height) > VA2_VR_VP_SW_RESIZER_BUFFER_SIZE)
                {
                  bSpecVideoCheckSize = KAL_FALSE;
                }
              } 

            }
            else
            {
              ASSERT(0);
            }
        }
    }
    if ( KAL_TRUE == cb->src_clip.b_clip_enable)
    {
       if ((check_src_clip.u4_clip_left & 0x01) == 0x01)
       {
         check_src_clip.u4_clip_left += 1;
       }
       if ((check_src_clip.u4_clip_right & 0x01) == 0x01)
       {
         check_src_clip.u4_clip_right += 1;
       }
       if ((check_src_clip.u4_clip_top & 0x01) == 0x01)
       {
         check_src_clip.u4_clip_top += 1;
       }
       if ((check_src_clip.u4_clip_bottom & 0x01) == 0x01)
       {
         check_src_clip.u4_clip_bottom += 1;
       }
     }
     else
     {
       check_src_clip.u4_clip_left = 0;
       check_src_clip.u4_clip_top = 0;
       check_src_clip.u4_clip_right = cb->src_size.u4_width;
       check_src_clip.u4_clip_bottom= cb->src_size.u4_height;  
     }
     if (check_src_clip.u4_clip_right>cb->src_size.u4_width)
     {
       check_src_clip.u4_clip_right = cb->src_size.u4_width;
       if ((check_src_clip.u4_clip_right & 0x01) == 0x01)
       {
         check_src_clip.u4_clip_right -= 1;
       }
     }
     if (check_src_clip.u4_clip_bottom>cb->src_size.u4_height)
     {
       check_src_clip.u4_clip_bottom = cb->src_size.u4_height;
       if ((check_src_clip.u4_clip_bottom & 0x01) == 0x01)
       {
         check_src_clip.u4_clip_bottom -= 1;
       }
     }
     if (KAL_TRUE == bSpecVideoCheckSize)
     {
       clip_width = n_src_width*2;
       clip_height = n_src_height*2;
     }
     else
     {
       clip_width = (check_src_clip.u4_clip_right - check_src_clip.u4_clip_left)*2;
       clip_height = (check_src_clip.u4_clip_bottom - check_src_clip.u4_clip_top)*2;
     }
     if ((clip_width < target_w) || (clip_height < target_h))
     {
       return KAL_TRUE;
     }
     else
     {
       return KAL_FALSE;
     }
}    

/**
 *  @status OK
 *  @common IDP API dependent
 */
static kal_bool 
_va2_vr_vp_6235_check_params_configs(
  va2_comp_video_renderer_cb_t *cb)
{
  kal_bool fgRet = KAL_TRUE;
  ASSERT(NULL != cb);

  //VA2_VIDEO_RENDERER_COLOR_FORMAT_T         src_color_format;
  // TODO: Note this! Cannot remove...here to check if ever set
  if (VIDEO_RENDERER_COLOR_YUV420 != cb->src_color_format)
  {
    fgRet = KAL_FALSE; // TODO: Why not directly return?
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
  if ((0 == cb->src_size.u4_width) 
      || (0 == cb->src_size.u4_height) 
      || (0xFFFF < cb->src_size.u4_width) 
      || (0xFFFF < cb->src_size.u4_height))
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
        //michael add for reject small video WH
        (cb->src_clip.u4_clip_bottom < 6) ||
        (cb->src_clip.u4_clip_right < 6))

    {
      fgRet = KAL_FALSE;
    }
  }
  
  //VA2_FRAME_SIZE_T                          dst_size;
  // TODO: Note this! Cannot remove...here to check if ever set
  if ((0 == cb->dst_size.u4_width) 
      || (0 == cb->dst_size.u4_height) 
      || (0xFFFF < cb->dst_size.u4_width) 
      || (0xFFFF < cb->dst_size.u4_height))
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
  if (VIDEO_RENDERER_COLOR_RGB565 != cb->dst_color_format)
  {
    fgRet = KAL_FALSE;
  }

  //VA2_FRAME_SIZE_T                          dst_fb_size;
  if ((0 == cb->dst_fb_size.u4_width) 
      || (0 == cb->dst_fb_size.u4_height) 
      || (0xFFFF < cb->dst_fb_size.u4_width) 
      || (0xFFFF < cb->dst_fb_size.u4_height))
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
 *  @common IDP API dependent
 */

static kal_bool 
_va2_vr_vp_6235_config_idp_by_render_mode(
  va2_comp_video_renderer_cb_t *cb, 
  VA2_VIDEO_FRAME_T *video_frame)
{
  kal_mem_cpy(&(cb->src_size), &(video_frame->r_fb_size), sizeof(VA2_FRAME_SIZE_T));
  kal_mem_cpy(&(cb->src_clip), &(video_frame->r_clip_window), sizeof(VA2_CLIP_WINDOW_T));
  kal_mem_cpy(&(cb->src_fb_addr), &(video_frame->r_fb_addr), sizeof(VA2_FRAME_BUFFER_ADDRESS_T));

  if (VIDEO_RENDERER_RENDER_MODE_TOUCH_WINDOW_FROM_INSIDE == cb->render_mode)
  {
    kal_uint32 src_clip_w, src_clip_h;
    kal_uint32 w_after_rot, h_after_rot;
    kal_uint32 h_ratio;
    kal_uint32 v_ratio;
    kal_uint32 ori_src_width,ori_src_height;
    
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

    w_after_rot = cb->dst_size.u4_width;
    h_after_rot = cb->dst_size.u4_height;
    
    bIsSpecialVideoResolution = _va2_vr_vp_6235_check_special_video_resolution_touch_from_inside_only(cb);

    // src clip window size
    if (KAL_TRUE == cb->src_clip.b_clip_enable)
    {
      src_clip_w = cb->src_clip.u4_clip_right - cb->src_clip.u4_clip_left + 1;
      src_clip_h = cb->src_clip.u4_clip_bottom - cb->src_clip.u4_clip_top + 1;
    }
    else
    {
      src_clip_w = cb->src_size.u4_width;
      src_clip_h = cb->src_size.u4_height;
    }
    ori_src_width = src_clip_w;
    ori_src_height = src_clip_h;
   
    ASSERT(0 != src_clip_w);
    ASSERT(0 != src_clip_h);

    // compute max. dst_size smaller than dst_fb_size to keep src_size ratio...
    target_pitch = cb->dst_size.u4_width;
    {
      h_ratio = (cb->dst_size.u4_width<<16)/src_clip_w;
      v_ratio = (cb->dst_size.u4_height<<16)/src_clip_h;

      if (h_ratio < v_ratio)
      {
        // dst_w needs not to be changed...
        cb->dst_size.u4_height = (((((h_ratio*src_clip_h)>>16)+1)>>1)<<1);
        if (cb->dst_size.u4_height == 0) {cb->dst_size.u4_height = 2;}
      }
      else if (h_ratio > v_ratio)
      {
        // dst_h needs not to be changed...
        cb->dst_size.u4_width =  (((((v_ratio*src_clip_w)>>16)+1)>>1)<<1);
        if (cb->dst_size.u4_width == 0) {cb->dst_size.u4_width = 2;}
      }
    }

    // compute pitch start address...
    {
      kal_uint32 dst_x = 0,dst_y = 0;
      kal_uint32 dst_start_offset;

      if (w_after_rot == cb->dst_size.u4_width)
      {
        ASSERT(h_after_rot >= cb->dst_size.u4_height);
        dst_x = 0;
        dst_y = (h_after_rot - cb->dst_size.u4_height)>>1;
        if ((dst_y & 0x1) == 1)
        {
          dst_y--;
          cb->dst_size.u4_height+=2;
        }
        target_pitch = 0; //cb->dst_size.u4_width
        bIsSpecialVideoResolution = KAL_FALSE;
      }
      else if (h_after_rot == cb->dst_size.u4_height)
      {
        ASSERT(w_after_rot >= cb->dst_size.u4_width);
        dst_x = (w_after_rot - cb->dst_size.u4_width)>>1;
        dst_y = 0;
        if ((dst_x & 0x1) == 1)
        {
          dst_x--;
          cb->dst_size.u4_width+=2;
        }
        if (KAL_TRUE == bIsSpecialVideoResolution)
        {
          new_source_width = (((((target_pitch<<16) / v_ratio)+1)>>1)<<1);
          new_source_height = ori_src_height;
          new_source_offset = (new_source_width-ori_src_width)/2;
          if ((new_source_offset & 0x01)==0x01)
          {
            new_source_offset--;
          }
          new_source_width = (2*new_source_offset)+ori_src_width;
          if ((2*new_source_width*new_source_height) > VA2_VR_VP_SW_RESIZER_BUFFER_SIZE)
          {
            bIsSpecialVideoResolution = KAL_FALSE;
          }
        } 
      }
      else
      {
        ASSERT(0);
      }
      dst_start_offset = (cb->dst_size.u4_width*dst_y + dst_x) * va2_util_get_bpp(cb->dst_color_format);
      inside_dst_x = dst_x;
      inside_dst_y = dst_y;
      inside_dst_start_offset = dst_start_offset;
      {
        kal_uint32 i = VA2_COMP_VR_MAX_DSPL_FB_COUNT;
        for (i=0 ; i< VA2_COMP_VR_MAX_DSPL_FB_COUNT; i++)
        {
          cb->dst_fb_start_addr_array[i].u4_fb_addr_plane0 = cb->dst_fb_addr_array[i].u4_fb_addr_plane0;
          cb->dst_fb_start_addr_array[i].u4_fb_addr_plane1 = 0;
          cb->dst_fb_start_addr_array[i].u4_fb_addr_plane2 = 0;
        }
      }
    }
    
  }
  else if (VIDEO_RENDERER_RENDER_MODE_TOUCH_WINDOW_FROM_OUTSIDE == cb->render_mode)
  {
    kal_uint32 src_clip_w, src_clip_h;
    kal_uint32 new_src_clip_w, new_src_clip_h;    
    kal_uint32 diff_w,diff_h;
    kal_uint32 h_ratio,v_ratio;
    

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
      src_clip_w = cb->src_clip.u4_clip_right - cb->src_clip.u4_clip_left + 1;
      src_clip_h = cb->src_clip.u4_clip_bottom - cb->src_clip.u4_clip_top + 1;
    }
    else
    {
      src_clip_w = cb->src_size.u4_width;
      src_clip_h = cb->src_size.u4_height;
    }
    ASSERT(0 != src_clip_w);
    ASSERT(0 != src_clip_h);

    // compute min. dst_size bigger than dst_fb_size to keep src_size ratio...
    {
      h_ratio = (cb->dst_size.u4_width<<16)/src_clip_w;
      v_ratio = (cb->dst_size.u4_height<<16)/src_clip_h;
      if (h_ratio > v_ratio)
      {
        // dst_h needs not to be changed...
        new_src_clip_h = (cb->dst_size.u4_height<<16) / h_ratio;
        new_src_clip_h = ((new_src_clip_h + 1) >> 1 ) <<1;
        new_src_clip_w = src_clip_w;
        diff_h = (src_clip_h - new_src_clip_h) / 2;
        cb->src_clip.u4_clip_top = cb->src_clip.u4_clip_top + diff_h;
        if ((cb->src_clip.u4_clip_top & 0x01)==0x01)
        {
          cb->src_clip.u4_clip_top = cb->src_clip.u4_clip_top + 1;
        }
        cb->src_clip.u4_clip_bottom = cb->src_clip.u4_clip_top + new_src_clip_h -1;
      }
      else if (h_ratio < v_ratio)
      {
        // dst_w needs not to be changed...
        new_src_clip_w = (cb->dst_size.u4_width<<16) / v_ratio;
        new_src_clip_w = ((new_src_clip_w + 1) >> 1 ) <<1;
        new_src_clip_h = src_clip_h;
        diff_w = (src_clip_w - new_src_clip_w) / 2;
        cb->src_clip.u4_clip_left = cb->src_clip.u4_clip_left + diff_w;
        if ((cb->src_clip.u4_clip_left & 0x01)==0x01)
        {
          cb->src_clip.u4_clip_left = cb->src_clip.u4_clip_left + 1;
        }
        cb->src_clip.u4_clip_right = cb->src_clip.u4_clip_left + new_src_clip_w -1;
      }
      else  //Equal
      {
      
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
  }
  else
  {
    return KAL_FALSE;
  }

  if (cb->funcs.render_dspl_frame_buf == _va2_vr_vp_6235_hw_render_display_frame_buffer)
  {
    kal_bool result;
    kal_uint32 extmem_start_address = 0;
    kal_uint32 extmem_size = 0;
    kal_uint32 dst_width = 0;
    kal_uint32 dst_height = 0;
    // TODO: Add two parameter field.
#if defined(CONTOUR_IMPROVEMENT_MT6235)
    kal_uint32 video_frame_rate = 0;
    kal_uint32 reserve_time_to_mdp = 0;
    extmem_start_address = cb->WM_start_address;
    extmem_size = cb->WM_size;
    video_frame_rate = cb->u4Fps;
    {
        if (cb->u4FramePeriodInMS > cb->u4DecodingTime)
        {
            cb->u4RemainTimeForSwDither =  cb->u4FramePeriodInMS  - cb->u4DecodingTime;
        }
        else
        {
            cb->u4RemainTimeForSwDither = 0;
        }
        reserve_time_to_mdp = cb->u4RemainTimeForSwDither;
    }
#endif

    if ((0 == inside_dst_y) && (0 != inside_dst_x) && (KAL_TRUE== bIsSpecialVideoResolution))
    {
      dst_width = target_pitch;
      dst_height = cb->dst_size.u4_height;
    }
    else
    {
      dst_width = cb->dst_size.u4_width;
      dst_height = cb->dst_size.u4_height;
    }

    result = idp_video_decode_config(
      _va2_comp_video_renderer_idp_key, 
      /* not in use */
      IDP_VIDEO_DECODE_INTMEM_START_ADDRESS, 0,
      IDP_VIDEO_DECODE_INTMEM_SIZE, 0,
      IDP_VIDEO_DECODE_EXTMEM_START_ADDRESS, extmem_start_address,
      IDP_VIDEO_DECODE_EXTMEM_SIZE, extmem_size,
#if defined(CONTOUR_IMPROVEMENT_MT6235)
      IDP_VIDEO_DECODE_VIDEO_FRAME_RATE, video_frame_rate,
      IDP_VIDEO_DECODE_RESERVE_TIME_TO_MDP, reserve_time_to_mdp,
#endif
      /* not in use */
      IDP_VIDEO_DECODE_TARGET_WIDTH_FOR_TVOUT, 0,
      IDP_VIDEO_DECODE_TARGET_HEIGHT_FOR_TVOUT, 0,

      IDP_VIDEO_DECODE_TARGET_WIDTH, dst_width,
      IDP_VIDEO_DECODE_TARGET_HEIGHT, dst_height,
      // TODO: handle MED incorrect param for IPP
      IDP_VIDEO_DECODE_CONTRAST_LEVEL, (KAL_FALSE == cb->post_process.b_contrast) ? 0x80 : cb->post_process.u1_contrast, 
      IDP_VIDEO_DECODE_BRIGHTNESS_LEVEL, (KAL_FALSE == cb->post_process.b_brightness) ? 0x80 : cb->post_process.u1_brightness, 

      IDP_VIDEO_DECODE_ENABLE_PITCH, KAL_FALSE,
      IDP_VIDEO_DECODE_IMAGE_DATA_FORMAT, va2_util_convert_to_idp_color_format(cb->dst_color_format), 
#if defined(DRV_DISPLAY_DRIVER_V1)
      IDP_VIDEO_DECODE_TRIGGER_LCD, cb->trigger_display,
#endif
#if defined(DRV_DISPLAY_DRIVER_V2)
      IDP_VIDEO_DECODE_TRIGGER_LCD, cb->trigger_display, 
#endif
      IDP_VIDEO_DECODE_FORCE_LCD_HW_TRIGGER, KAL_FALSE,

      IDP_VIDEO_DECODE_ENABLE_CLIP, KAL_FALSE,
      IDP_VIDEO_DECODE_ROT_ANGLE, 0x0, 

      /* not in use */
      IDP_VIDEO_DECODE_SRC_FMT_4X4, KAL_FALSE, 
      IDP_VIDEO_DECODE_ENABLE_MP4DEBLK, KAL_FALSE, 

      IDP_VIDEO_DECODE_RESIZER_U_VALUE, 0x8,
      IDP_VIDEO_DECODE_RESIZER_V_VALUE, 0xF,
    
      0);

      return result;
  }
  return KAL_TRUE;

  
}

/**
 *  @todo OK
 *  @common Common for VR.VP except for control block instance.
 */
static void
_va2_vr_vp_6235_display_timer_hdlr(
  void *param)
{
  kal_uint32 save_irq_mask;
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6235_cb;

  if ((va2_comp_video_renderer_cb_t*) param != cb)
  {
    ASSERT(0); // incorrect timer handler param
  }

  // TODO: check why need to observe this code segment
#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("TM0", 1);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)

  if(VIDEO_STATE_RUN != cb->state.eState)
  {
    return;
  }

  if(KAL_TRUE == va2_util_check_bypass_redraw(cb))
  {
    return;
  }

  save_irq_mask = SaveAndSetIRQMask();
  if (NULL == cb->vr_q_handle.curr_dspl_buf_hdr)
  {
    va2_vr_add_trace(&_va2_vr_vp_6235_debug_trace[0], VA2_VR_INTERNAL____DSPL_TIMER_ASSERT, 0);
    // TODO: Note this! we remove this assertion due to this is not necessary from decoder and application's point of view!
    RestoreIRQMask(save_irq_mask);

#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
      SLA_CustomLogging("TM0", 0);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)

    return;
  }
  RestoreIRQMask(save_irq_mask);

  // TODO: This close logging statement is missed...
#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("TM0", 0);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)

  if (KAL_TRUE == cb->bypass)
  {
    // If times out in bypass mode, do nothing...especially not to trigger IDP...
    // And actually we don't care about if no consequent buffer comes or not!!
    return;
  }

  va2_vr_add_trace(&_va2_vr_vp_6235_debug_trace[0], VA2_VR_INTERNAL____DSPL_TIMER_TIMEOUT, 0);

  // TODO: Add display redraw hisr
  visual_active_hisr(VISUAL_RENDERER_TIMER_HISR_ID);
  
}

static void
_va2_vr_vp_6235_touch_from_inside_pitch(
  void *param)
{
    va2_comp_video_renderer_cb_t *cb = (va2_comp_video_renderer_cb_t*) &_va2_vr_vp_6235_cb;
    kal_uint32 frame_buf_size;
    kal_uint32 dst_fb_start_addr;
    kal_uint32 dst_fb_size;
    kal_uint8* frame_start_addr;
    kal_uint8* frame_end_addr;
    kal_uint8* pitch_start_addr;
    kal_uint8* pitch_end_addr;
    kal_uint32 u4Flags = 0;
    kal_uint32 framesize32ByteAlgin;
    if (NULL == param)
    {
      ASSERT(0);
    }
#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
    SLA_CustomLogging("PIT", 1);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)

    frame_buf_size = ((cb->dst_size.u4_width*cb->dst_size.u4_height) * va2_util_get_bpp(cb->dst_color_format));
    dst_fb_size = ((cb->dst_fb_size.u4_width*cb->dst_fb_size.u4_height) * va2_util_get_bpp(cb->dst_color_format));

    dst_fb_start_addr = (*((kal_uint32*)(param)));
    framesize32ByteAlgin = ((dst_fb_size+31)>>5)<<5;
    if (framesize32ByteAlgin>VA2_VR_VP_DISPLAY_BUFFER_SIZE)
    {
      framesize32ByteAlgin = VA2_VR_VP_DISPLAY_BUFFER_SIZE;
    }
    if (VIDEO_RENDERER_RENDER_MODE_TOUCH_WINDOW_FROM_INSIDE == cb->render_mode)
    {
      kal_uint32 i=0;
      if ((0 == inside_dst_x) && (0 != inside_dst_y))
      {
        //Black
        dynamic_switch_cacheable_region(&dst_fb_start_addr, framesize32ByteAlgin, PAGE_CACHEABLE);
            
        //In-Place Pitch
        frame_start_addr = (kal_uint8*)(dst_fb_start_addr);
        frame_end_addr = (kal_uint8*)(frame_start_addr + frame_buf_size);
        pitch_start_addr = (kal_uint8*)(frame_start_addr + inside_dst_start_offset);

        kal_mem_set((void*) frame_start_addr, 0x0, inside_dst_start_offset);  //black for RGB565
        pitch_start_addr = pitch_start_addr+frame_buf_size;
        kal_mem_set((void*) pitch_start_addr, 0x0, inside_dst_start_offset);  //black for RGB565

        dynamic_switch_cacheable_region(&dst_fb_start_addr, framesize32ByteAlgin, PAGE_NO_CACHE);
      }
      else if ((0 == inside_dst_y) && (0 != inside_dst_x))
      {

        kal_uint32 tmp_width;
        kal_uint32 x_offset;
        dynamic_switch_cacheable_region(&dst_fb_start_addr, framesize32ByteAlgin, PAGE_CACHEABLE);
        
        //In-Place Pitch
        frame_start_addr = (kal_uint8*)(dst_fb_start_addr);
        frame_end_addr = (kal_uint8*)(frame_start_addr + frame_buf_size);
        pitch_start_addr = (kal_uint8*)(frame_start_addr + inside_dst_start_offset);

        kal_mem_set((void*) (kal_uint8*)(cb->SW_Pitch_Mem_Addr), 0x0, cb->SW_Pitch_Mem_Size);  //black for RGB565

        x_offset = inside_dst_x*va2_util_get_bpp(cb->dst_color_format);
        pitch_end_addr = (kal_uint8*)(frame_start_addr + dst_fb_size);
        tmp_width = (cb->dst_size.u4_width + (2*inside_dst_x)) * va2_util_get_bpp(cb->dst_color_format);
        for (i=0;i<cb->dst_size.u4_height;i++)
        {
          pitch_end_addr = pitch_end_addr - tmp_width;;
          frame_end_addr = frame_end_addr - (cb->dst_size.u4_width * va2_util_get_bpp(cb->dst_color_format));

          kal_mem_cpy((kal_uint8*)(cb->SW_Pitch_Mem_Addr+x_offset), frame_end_addr, 
                       (cb->dst_size.u4_width * va2_util_get_bpp(cb->dst_color_format)));
          kal_mem_cpy(pitch_end_addr, (kal_uint8*)(cb->SW_Pitch_Mem_Addr), 
                       tmp_width);
        }
        dynamic_switch_cacheable_region(&dst_fb_start_addr, framesize32ByteAlgin, PAGE_NO_CACHE);

      }
      else
      {
      }
    }

#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
    SLA_CustomLogging("PIT", 0);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
    
    if (KAL_TRUE == g_bBusy_TouchInSide_Pitch)
    {
      kal_retrieve_eg_events(cb->EventID, TASK_WAIT_TRIGGER_DISPLAY_HISR_SET, KAL_AND_CONSUME, &u4Flags, KAL_NO_SUSPEND);
      visual_active_hisr(VISUAL_RENDERER_TRIGGER_DISPLAY_HISR_ID);
      kal_retrieve_eg_events(cb->EventID, TASK_WAIT_TRIGGER_DISPLAY_HISR_SET, KAL_AND_CONSUME, &u4Flags, KAL_SUSPEND);
    }
}

/**
 *  @status XX
 *  @remark callback in HISR...VISUAL HISR to be specific...
 */
 // TODO: W1045 Code Review SW Resizer call back a new function to activate a HISR
static void
_va2_vr_vp_6235_idp_frame_done_cb(
  void *param)
{
  va2_comp_video_renderer_cb_t *cb = (va2_comp_video_renderer_cb_t*) &_va2_vr_vp_6235_cb;
  kal_uint32 iIndex;

#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
      SLA_CustomLogging("HWR", 0);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)

#if defined(DRV_DISPLAY_DRIVER_V1)
  lcd_frame_update_struct *lcd_cfg; 
#endif
  ASSERT(NULL != cb);

#if defined(DRV_DISPLAY_DRIVER_V1)
  lcd_cfg = &cb->display_surface.r_mtk_lcd_config;
#endif
    
#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
   SLA_CustomLogging("RFD", 1);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
  va2_vr_add_trace(&_va2_vr_vp_6235_debug_trace[0], VA2_VR_INTERNAL____MDP_HW_FRAME_DONE_CB, 0);

  if(VIDEO_STATE_RUN != cb->state.eState)
  {
#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
      SLA_CustomLogging("RFD", 0);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
    return;
  }
// TODO: W1045 Code Review, IDP Don't control LCD. Renderer control LCD. Discuss with CM and CT.
#if defined(DRV_DISPLAY_DRIVER_V1)
  if (KAL_FALSE == lcd_is_busy())
  {
    if(KAL_TRUE == cb->trigger_display)
    {
      LCD_preview(lcd_cfg->update_layer,
          cb->dst_fb_start_addr_array[iIndex].u4_fb_addr_plane0, 
          cb->dst_fb_start_addr_array[iIndex].u4_fb_addr_plane0);
     }
  }
#endif
  iIndex = ((_va2_vr_render_display_buffer_cnt&0x1)^0x01)+1;
  if (VIDEO_RENDERER_RENDER_MODE_TOUCH_WINDOW_FROM_INSIDE == cb->render_mode)
  {
     if ((cb->funcs.render_dspl_frame_buf == _va2_vr_vp_6235_hw_render_display_frame_buffer) && (KAL_FALSE == ((0 == inside_dst_y) && (0 != inside_dst_x) && (KAL_TRUE == bIsSpecialVideoResolution)))
           || ((cb->funcs.render_dspl_frame_buf == _va2_vr_vp_6235_sw_render_display_frame_buffer) && (0 != inside_dst_y) && (0 == inside_dst_x)) 
         )
     {
        g_bBusy_TouchInSide_Pitch = KAL_TRUE;
        ASSERT(KAL_TRUE == idp_sw_resizer_start_hisr(
                                 IDP_REQUIRE_TASK_DO_TOUCH_FROM_INSIDE_PITCH,   //nCmd , 1 for sw resizer, 2 for color format trasnform  
                                 cb->src_size.u4_width,
                                 cb->src_size.u4_height,
                                 KAL_TRUE,
                                 0,
                                 0,
                                 cb->src_size.u4_width,
                                 cb->src_size.u4_height,
                                 cb->dst_size.u4_width,
                                 cb->dst_size.u4_height,
                                 cb->src_fb_addr.u4_fb_addr_plane0, 
                                 cb->src_fb_addr.u4_fb_addr_plane1, 
                                 cb->src_fb_addr.u4_fb_addr_plane2, 
                                 cb->dst_fb_start_addr_array[0].u4_fb_addr_plane0,
                                 ispVideoFrame_UYVY422,
                                 (VA2_VR_VP_SW_RESIZER_BUFFER_SIZE),
                                 inside_dst_x,
                                 (idp_sw_resizer_cbfxn_t)_va2_vr_vp_6235_touch_from_inside_pitch,
                                 (void*)&cb->dst_fb_addr_array[iIndex].u4_fb_addr_plane0));
        return;
      }  
      bIsSpecialVideoResolution = KAL_FALSE;
  }

  // Trigger display 
#if defined(DRV_DISPLAY_DRIVER_V2)
  {
    if (WFC_FALSE == wfcMMCheckBusy())
    {
      _va2_vr_vp_6235_trigger_display(
         cb->dst_fb_addr_array[iIndex].u4_fb_addr_plane0, 
         cb);
    }
    else
    {
      _va2_vr_render_display_buffer_cnt--;    
      _va2_vr_render_display_buffer_cnt &= 0x01;
    }
  }
#endif

  if (KAL_TRUE == cb->bypass)
  {
    // Unexpected: FrameDone occurs unders bypass mode.
    // Bypass mode should only be switched under Stop state, and render should only execute under Run state.
    // At last, FrameDone will not be processed except under Run state. There it is.
    ASSERT(0);
  }
  //Because of empty this buffer, when you call idp_frame_don_cb in task.
  //But empty this buffer is in the hisr will get the higher priority and will
  //cause system stack error from camera task (med_c_main.c)
  g_bBusy =KAL_FALSE;

  // TODO: W1045 Code Review SW Resizer call back a new function to activate a HISR

#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("RFD", 0);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
}


static void
_va2_vr_vp_6235_yuv420_2_yuv422_done_cb(
  void *param)
{
    kal_bool result;
    void (*ptr_FrmDoneCBFunc)(void *) = NULL;
    kal_uint32 iIndex;
    kal_uint32 addrOffset;
    va2_comp_video_renderer_cb_t *cb = (va2_comp_video_renderer_cb_t*) &_va2_vr_vp_6235_cb;
    if ((NULL == cb) || 
        (NULL == cb->vr_q_handle.curr_dspl_buf_hdr))
    {
      ASSERT(0); // incorrect param
    }

    addrOffset = 0;
    if (VIDEO_RENDERER_RENDER_MODE_TOUCH_WINDOW_FROM_INSIDE == cb->render_mode)
    {
      if ((0 != inside_dst_y) && (0 == inside_dst_x))
      {
        addrOffset = inside_dst_start_offset;
      }
    }    
    ptr_FrmDoneCBFunc = _va2_vr_vp_6235_idp_frame_done_cb;
    iIndex = (_va2_vr_render_display_buffer_cnt&0x1)+1;
    result = idp_video_decode_config(
               _va2_comp_video_renderer_idp_key, 
               IDP_VIDEO_DECODE_SRC_WIDTH, hw_src_width,
               IDP_VIDEO_DECODE_SRC_HEIGHT, hw_src_height,
               IDP_VIDEO_DECODE_VIDEO_Y_BUFFER_ADDRESS,ispVideoFrame_UYVY422,
               IDP_VIDEO_DECODE_VIDEO_U_BUFFER_ADDRESS,0,
               IDP_VIDEO_DECODE_VIDEO_V_BUFFER_ADDRESS,0,
               IDP_VIDEO_DECODE_SOURCE_DATA_FORMAT, va2_util_convert_to_idp_color_format(cb->src_color_format),
               IDP_VIDEO_DECODE_DST_CLIP, cb->dst_clip.b_clip_enable, 
                                          cb->dst_clip.u4_clip_left, cb->dst_clip.u4_clip_top, 
                                          cb->dst_clip.u4_clip_right, cb->dst_clip.u4_clip_bottom, 

               IDP_VIDEO_DECODE_DONE_CB, ptr_FrmDoneCBFunc, 
               IDP_VIDEO_DECODE_FRAME_BUFFER_ADDRESS, (cb->dst_fb_start_addr_array[iIndex].u4_fb_addr_plane0 + addrOffset), 
               IDP_VIDEO_DECODE_FRAME_BUFFER_ADDRESS_2, (cb->dst_fb_start_addr_array[iIndex].u4_fb_addr_plane0 + addrOffset),
               IDP_VIDEO_DECODE_DONE_CB_PARAM, cb, 
               0);
      _va2_vr_render_display_buffer_cnt++;
      _va2_vr_render_display_buffer_cnt &= 0x01;

  if (KAL_FALSE == result)  
  {
    _va2_vr_vp_6235_notify_error_to_client(cb);
  }

  if (KAL_FALSE == idp_video_decode_start_all(_va2_comp_video_renderer_idp_key))
  {
    ASSERT(0);
  }

  g_bBusy_SW_YUV420_2_UYVY422 = KAL_FALSE;


}

static kal_uint32 
_va2_vr_vp_6235_get_source_clip(
  va2_comp_video_renderer_cb_t *cb)
{
  kal_mem_cpy(&(video_src_clip), &(cb->src_clip), sizeof(VA2_CLIP_WINDOW_T));
  if ( KAL_TRUE == cb->src_clip.b_clip_enable)
  {
    if ((video_src_clip.u4_clip_left & 0x01) == 0x01)
    {
      video_src_clip.u4_clip_left += 1;
    }
    if ((video_src_clip.u4_clip_right & 0x01) == 0x01)
    {
      video_src_clip.u4_clip_right += 1;
    }
    if ((video_src_clip.u4_clip_top & 0x01) == 0x01)
    {
      video_src_clip.u4_clip_top += 1;
    }
    if ((video_src_clip.u4_clip_bottom & 0x01) == 0x01)
    {
      video_src_clip.u4_clip_bottom += 1;
    }
  }
  else
  {
    video_src_clip.u4_clip_left = 0;
    video_src_clip.u4_clip_top = 0;
    video_src_clip.u4_clip_right = cb->src_size.u4_width;
    video_src_clip.u4_clip_bottom= cb->src_size.u4_height;  
  }
  if (video_src_clip.u4_clip_right>cb->src_size.u4_width)
  {
    video_src_clip.u4_clip_right = cb->src_size.u4_width;
    if ((video_src_clip.u4_clip_right & 0x01) == 0x01)
    {
      video_src_clip.u4_clip_right -= 1;
    }
  }
  if (video_src_clip.u4_clip_bottom>cb->src_size.u4_height)
  {
    video_src_clip.u4_clip_bottom = cb->src_size.u4_height;
    if ((video_src_clip.u4_clip_bottom & 0x01) == 0x01)
    {
      video_src_clip.u4_clip_bottom -= 1;
    }
  }

  video_target_size.u4_width = video_src_clip.u4_clip_right - video_src_clip.u4_clip_left;
  video_target_size.u4_height = video_src_clip.u4_clip_bottom - video_src_clip.u4_clip_top;
}


/**
 *  @return kal_uint32 the address to destination frame buffer if blocking is set to KAL_TRUE, 0 if blocking is set to KAL_FALSE.
 *  @status OK
 */
// TODO: W1045 Code Review Divided to SW and HW Function
static kal_uint32 
_va2_vr_vp_6235_hw_render_display_frame_buffer(
  va2_comp_video_renderer_cb_t *cb, 
  kal_bool blocking)
{
  VA2_VIDEO_FRAME_T *video_frame;
  va2_util_buf_hdr_q_item_t *curr_dspl_buf_hdr;
  kal_bool result;
  kal_uint32 uyvy422size;
  kal_uint32 addrOffset;
  SW_VIDEO_RESIZER_PUT_STRUCT video_put;
  SW_VIDEO_RESIZER_CONFIG_STRUCT sw_video_resizer_cfg;
  void (*ptr_FrmDoneCBFunc)(void *) = NULL;

#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
    SLA_CustomLogging("HWR", 1);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)

  if ((NULL == cb) || 
      (NULL == cb->vr_q_handle.curr_dspl_buf_hdr))
  {
    ASSERT(0); // incorrect param
  }

  curr_dspl_buf_hdr = cb->vr_q_handle.curr_dspl_buf_hdr;
  va2_vr_add_trace(&_va2_vr_vp_6235_debug_trace[0], VA2_VR_HW_RESIZER_INTERNAL____RENDER, (kal_uint32) curr_dspl_buf_hdr);

  if (0 == _va2_comp_video_renderer_idp_key)
  {
    ASSERT(0); // IDP video playback not opened
  }
  
  if (KAL_FALSE == idp_video_decode_stop(_va2_comp_video_renderer_idp_key))
  {
    ASSERT(0);
  }

  // get frame data...
  video_frame = (VA2_VIDEO_FRAME_T*) curr_dspl_buf_hdr->buffer_header.pPrivateData;
  ASSERT(NULL != video_frame);
  kal_mem_cpy(&(cb->src_size), &(video_frame->r_fb_size), sizeof(VA2_FRAME_SIZE_T));
  kal_mem_cpy(&(cb->src_clip), &(video_frame->r_clip_window), sizeof(VA2_CLIP_WINDOW_T));
  kal_mem_cpy(&(cb->src_fb_addr), &(video_frame->r_fb_addr), sizeof(VA2_FRAME_BUFFER_ADDRESS_T));

  // config video playback path according to render mode...
  result = _va2_vr_vp_6235_config_idp_by_render_mode(cb, video_frame);
  if (KAL_FALSE == result)
  {
    if (KAL_FALSE == blocking)
    {
      _va2_vr_vp_6235_notify_error_to_client(cb);
    }
    else
      return KAL_FALSE;
  }

  // check all parameters and configs for triggering HW
  if (KAL_FALSE == _va2_vr_vp_6235_check_params_configs(cb))
  {
    if (KAL_FALSE == blocking)
    {
      _va2_vr_vp_6235_notify_error_to_client(cb);
    }
    return VIDEO_ERROR_INPUT_PARAM_ERROR;
  }

#if defined(CONTOUR_IMPROVEMENT_MT6235)
  if (KAL_FALSE == blocking)
  {
        VA2_DITHERING_INFO_T *dithering_info;
  
        dithering_info = &(video_frame->r_dithering_info);
        if (dithering_info->u4MaxAVunSyncTime == 0)
        {
            // TODO: Please take care here when check-in
            // TODO: AVunSyncTime's unit will change us to ms from W1128.
            dithering_info->u4MaxAVunSyncTime = 10,000,000;
        }
        if (dithering_info->u4AVunSyncTime <= dithering_info->u4MaxAVunSyncTime)
        {
          cb->u4VdoBufConsumptPercent = (kal_uint32)(((kal_uint64)(((kal_uint64)(dithering_info->u4MaxAVunSyncTime - dithering_info->u4AVunSyncTime))*100))/ (dithering_info->u4MaxAVunSyncTime));
        }
        else
        {
            // TODO: Please take care here when check-in
            cb->u4VdoBufConsumptPercent = 0;
        }
        if (KAL_TRUE == idp_video_decode_notify_buffer_consumption(cb->u4VdoBufConsumptPercent))
        {
          if (0 != cb->vr_q_handle.to_be_processed_q.size)
          {
            va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
          }
          // try to return all buffers...
          cb->funcs.try_to_return_buf_hdrs(cb);
          return;
        }
  }        
#endif //#if defined(CONTOUR_IMPROVEMENT_MT6235)
  _va2_vr_vp_6235_get_source_clip(cb);
  sw_video_resizer_cfg.u4SrcClipX1 = video_src_clip.u4_clip_left;
  sw_video_resizer_cfg.u4SrcClipY1 = video_src_clip.u4_clip_top;
  sw_video_resizer_cfg.u4SrcClipX2 = video_src_clip.u4_clip_right;
  sw_video_resizer_cfg.u4SrcClipY2 = video_src_clip.u4_clip_bottom;


  sw_video_resizer_cfg.src_width = cb->src_size.u4_width;
  sw_video_resizer_cfg.src_height= cb->src_size.u4_height;
  sw_video_resizer_cfg.tar_width= sw_video_resizer_cfg.u4SrcClipX2 - sw_video_resizer_cfg.u4SrcClipX1;
  sw_video_resizer_cfg.tar_height= sw_video_resizer_cfg.u4SrcClipY2 - sw_video_resizer_cfg.u4SrcClipY1;    
  if ((0 == inside_dst_y) && (0 != inside_dst_x) && (KAL_TRUE== bIsSpecialVideoResolution))
  {
    uyvy422size = (new_source_width * new_source_height * 2);
    offset_x = new_source_offset;
    hw_src_width =new_source_width;
    hw_src_height =new_source_height;
  }
  else
  {
    uyvy422size = (sw_video_resizer_cfg.src_width * sw_video_resizer_cfg.src_height * 2);
    offset_x = 0;
    hw_src_width = video_target_size.u4_width;
    hw_src_height = video_target_size.u4_height;
  }
  uyvy422size += 0x1f;
  uyvy422size &= ~0x1f;

  // TODO: add check size mechanism
  if (uyvy422size > VA2_VR_VP_SW_RESIZER_BUFFER_SIZE)
  {
    uyvy422size = VA2_VR_VP_SW_RESIZER_BUFFER_SIZE;
  }

  //Remove Color Format Code to Task
  if (KAL_FALSE == blocking)
  {
      g_bBusy_SW_YUV420_2_UYVY422 = KAL_TRUE;
      ASSERT(KAL_TRUE == idp_sw_resizer_start_hisr(
                               IDP_REQUIRE_TASK_DO_COLOR_FORMAT_TRANSMFOM,   //nCmd , 1 for sw resizer, 2 for color format trasnform  
                               cb->src_size.u4_width,
                               cb->src_size.u4_height,
                               video_frame->r_clip_window.b_clip_enable,
                               video_src_clip.u4_clip_left,
                               video_src_clip.u4_clip_top,
                               video_src_clip.u4_clip_right,
                               video_src_clip.u4_clip_bottom,
                               video_target_size.u4_width,
                               video_target_size.u4_height,
                               video_frame->r_fb_addr.u4_fb_addr_plane0, 
                               video_frame->r_fb_addr.u4_fb_addr_plane1, 
                               video_frame->r_fb_addr.u4_fb_addr_plane2, 
                               cb->dst_fb_start_addr_array[0].u4_fb_addr_plane0,
                               ispVideoFrame_UYVY422,
                               uyvy422size,
                               offset_x,
                               (idp_sw_resizer_cbfxn_t)_va2_vr_vp_6235_yuv420_2_yuv422_done_cb,
                                     NULL));
      return;
  }

  // TODO: W1045 Code Review Check with Rey about color format
#if defined(IDP_SW_YUV420_2_UYVY422_RESIZER__DYNAMIC_SWITCH_CACHEABLE)
  dynamic_switch_cacheable_region(&ispVideoFrame_UYVY422, uyvy422size, PAGE_CACHEABLE);
#endif //#if defined(IDP_SW_YUV420_2_UYVY422_RESIZER__DYNAMIC_SWITCH_CACHEABLE)

  video_put.input_buffer[0] =(kal_uint8*) video_frame->r_fb_addr.u4_fb_addr_plane0;
  video_put.input_buffer[1] =(kal_uint8*) video_frame->r_fb_addr.u4_fb_addr_plane1;
  video_put.input_buffer[2] =(kal_uint8*) video_frame->r_fb_addr.u4_fb_addr_plane2;
    
  video_put.output_buffer[0] = (kal_uint8*) (ispVideoFrame_UYVY422);

  sw_video_resizer_cfg.tar_offset= offset_x;
  sw_video_resizer_cfg.input_buff_width[0] = cb->src_size.u4_width;
  sw_video_resizer_cfg.input_buff_width[1] = (cb->src_size.u4_width >> 1);
  sw_video_resizer_cfg.input_buff_width[2] = (cb->src_size.u4_width >> 1);
  if(sw_video_resizer_init(&sw_video_resizer_cfg) != SW_VIDEO_RESIZER_SUCCESS)
  {
    ASSERT(0);
  } 

  sw_video_yuv420_pack_uyvy422(&video_put,&sw_video_resizer_cfg);

#if defined(IDP_SW_YUV420_2_UYVY422_RESIZER__DYNAMIC_SWITCH_CACHEABLE)   
  dynamic_switch_cacheable_region(&ispVideoFrame_UYVY422, uyvy422size, PAGE_NO_CACHE);
#endif //#if defined(IDP_SW_YUV420_2_UYVY422_RESIZER__DYNAMIC_SWITCH_CACHEABLE)
  sw_video_resizer_deinit();

  if (KAL_FALSE == blocking)
  {
    ptr_FrmDoneCBFunc = _va2_vr_vp_6235_idp_frame_done_cb;
  }
  else
  {
    ptr_FrmDoneCBFunc = NULL;
  }
  
  result = idp_video_decode_config(
             _va2_comp_video_renderer_idp_key, 
             IDP_VIDEO_DECODE_SRC_WIDTH, hw_src_width,
             IDP_VIDEO_DECODE_SRC_HEIGHT, hw_src_height,
             IDP_VIDEO_DECODE_VIDEO_Y_BUFFER_ADDRESS,ispVideoFrame_UYVY422,
             IDP_VIDEO_DECODE_VIDEO_U_BUFFER_ADDRESS,0,
             IDP_VIDEO_DECODE_VIDEO_V_BUFFER_ADDRESS,0,
             IDP_VIDEO_DECODE_SOURCE_DATA_FORMAT, va2_util_convert_to_idp_color_format(cb->src_color_format),
             IDP_VIDEO_DECODE_DST_CLIP, cb->dst_clip.b_clip_enable, 
                                        cb->dst_clip.u4_clip_left, cb->dst_clip.u4_clip_top, 
                                        cb->dst_clip.u4_clip_right, cb->dst_clip.u4_clip_bottom, 

             IDP_VIDEO_DECODE_DONE_CB, ptr_FrmDoneCBFunc, 
             IDP_VIDEO_DECODE_DONE_CB_PARAM, cb, 
             0);

  addrOffset = 0;
  if (VIDEO_RENDERER_RENDER_MODE_TOUCH_WINDOW_FROM_INSIDE == cb->render_mode)
  {
    if ((0 != inside_dst_y) && (0 == inside_dst_x))
    {
      addrOffset = inside_dst_start_offset;
    }
  }
  if (blocking == KAL_TRUE)
  {
      idp_video_decode_config(
          _va2_comp_video_renderer_idp_key, 
          IDP_VIDEO_DECODE_FRAME_BUFFER_ADDRESS, (cb->dst_fb_start_addr_array[1].u4_fb_addr_plane0 + addrOffset), 
          IDP_VIDEO_DECODE_FRAME_BUFFER_ADDRESS_2, (cb->dst_fb_start_addr_array[1].u4_fb_addr_plane0 + addrOffset),
          0);
  }       
  else
  {
      kal_uint32 iIndex = (_va2_vr_render_display_buffer_cnt&0x1)+1;
      idp_video_decode_config(
          _va2_comp_video_renderer_idp_key, 
          IDP_VIDEO_DECODE_FRAME_BUFFER_ADDRESS, (cb->dst_fb_start_addr_array[iIndex].u4_fb_addr_plane0 + addrOffset), 
          IDP_VIDEO_DECODE_FRAME_BUFFER_ADDRESS_2, (cb->dst_fb_start_addr_array[iIndex].u4_fb_addr_plane0 + addrOffset),
          0);
      _va2_vr_render_display_buffer_cnt++;
      _va2_vr_render_display_buffer_cnt &= 0x01;
  }

  if (KAL_FALSE == result)  
  {
    if (KAL_FALSE == blocking)
    {
      _va2_vr_vp_6235_notify_error_to_client(cb);
    }
    else
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
      kal_sleep_task(2); // If assert here, it means blocking mode is only allowed to be invoked in NU+ task.
      ASSERT(KAL_TRUE == idp_video_decode_is_busy(_va2_comp_video_renderer_idp_key, &busy));
    } while ((KAL_TRUE == busy) && 
             ((VA2_COMP_VR_RENDER_TIME_MAX) > drv_get_duration_tick(start_time, drv_get_current_time())));
    if (VIDEO_RENDERER_RENDER_MODE_TOUCH_WINDOW_FROM_INSIDE == cb->render_mode)
    {
      if (KAL_FALSE == ((0 == inside_dst_y) && (0 != inside_dst_x) && (KAL_TRUE == bIsSpecialVideoResolution)))
      {
        _va2_vr_vp_6235_touch_from_inside_pitch (&cb->dst_fb_addr_array[1].u4_fb_addr_plane0);
      }
    }
    {
      kal_uint8* dst_addr= (kal_uint8*)cb->dst_fb_start_addr_array[0].u4_fb_addr_plane0;
      kal_uint8* src_addr= (kal_uint8*)cb->dst_fb_addr_array[1].u4_fb_addr_plane0;
      kal_mem_cpy(dst_addr, src_addr, 
                 (cb->dst_fb_size.u4_width * cb->dst_fb_size.u4_height * va2_util_get_bpp(cb->dst_color_format)));
    }
#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
        SLA_CustomLogging("HWR", 0);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
    return cb->dst_fb_start_addr_array[0].u4_fb_addr_plane0;
  }
  else
  {
    return 0;
  }
} // end of _va2_vr_vp_6235_render_display_frame_buffer

static kal_uint32 
_va2_vr_vp_6235_sw_render_display_frame_buffer(
  va2_comp_video_renderer_cb_t *cb, 
  kal_bool blocking)
{
  VA2_VIDEO_FRAME_T *video_frame;
  va2_util_buf_hdr_q_item_t *curr_dspl_buf_hdr;
  kal_bool result;
  kal_uint32 rgbSize;
  kal_uint32 addrOffset;

  if ((NULL == cb) || 
      (NULL == cb->vr_q_handle.curr_dspl_buf_hdr))
  {
    ASSERT(0); // incorrect param
  }

  curr_dspl_buf_hdr = cb->vr_q_handle.curr_dspl_buf_hdr;
  va2_vr_add_trace(&_va2_vr_vp_6235_debug_trace[0], VA2_VR_SW_RESIZER_INTERNAL____RENDER, (kal_uint32) curr_dspl_buf_hdr);

  // get frame data...
  video_frame = (VA2_VIDEO_FRAME_T*) curr_dspl_buf_hdr->buffer_header.pPrivateData;
  ASSERT(NULL != video_frame);
  kal_mem_cpy(&(cb->src_size), &(video_frame->r_fb_size), sizeof(VA2_FRAME_SIZE_T));
  kal_mem_cpy(&(cb->src_clip), &(video_frame->r_clip_window), sizeof(VA2_CLIP_WINDOW_T));
  kal_mem_cpy(&(cb->src_fb_addr), &(video_frame->r_fb_addr), sizeof(VA2_FRAME_BUFFER_ADDRESS_T));

#if defined(CONTOUR_IMPROVEMENT_MT6235)
    if (KAL_FALSE == blocking)
    {
       VA2_DITHERING_INFO_T *dithering_info;
    
       dithering_info = &(video_frame->r_dithering_info);
       if (dithering_info->u4MaxAVunSyncTime == 0)
       {
           // TODO: Please take care here when check-in
           // TODO: AVunSyncTime's unit will change us to ms from W1128.
           dithering_info->u4MaxAVunSyncTime = 10,000,000;
       }
       if (dithering_info->u4AVunSyncTime <= dithering_info->u4MaxAVunSyncTime)
       {
          cb->u4VdoBufConsumptPercent = (kal_uint32)(((kal_uint64)(((kal_uint64)(dithering_info->u4MaxAVunSyncTime - dithering_info->u4AVunSyncTime))*100))/ (dithering_info->u4MaxAVunSyncTime));
       }
       else
       {
           // TODO: Please take care here when check-in
           cb->u4VdoBufConsumptPercent = 0;
       }       
       if (KAL_TRUE == idp_video_decode_notify_buffer_consumption(cb->u4VdoBufConsumptPercent))
       {
         if (0 != cb->vr_q_handle.to_be_processed_q.size)
         {
           va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
         }
         // try to return all buffers...
         cb->funcs.try_to_return_buf_hdrs(cb);
         return;
       }
    }        
#endif //#if defined(CONTOUR_IMPROVEMENT_MT6235)

  // check all parameters and configs for triggering HW
  if (KAL_FALSE == _va2_vr_vp_6235_check_params_configs(cb))
  {
    if (KAL_FALSE == blocking)
    {
      _va2_vr_vp_6235_notify_error_to_client(cb);
    }
    return VIDEO_ERROR_INPUT_PARAM_ERROR;
  }

  // config video playback path according to render mode...
  result = _va2_vr_vp_6235_config_idp_by_render_mode(cb, video_frame);
  if (KAL_FALSE == result)
  {
    if (KAL_FALSE == blocking)
    {
      _va2_vr_vp_6235_notify_error_to_client(cb);
    }
    else
      return KAL_FALSE;
  }

  if (KAL_FALSE == result)  
  {
    if (KAL_FALSE == blocking)
    {
      _va2_vr_vp_6235_notify_error_to_client(cb);
    }
    else
      return KAL_FALSE;
  }

  cb->u4LastRenderTimestamp = drv_get_current_time();

  rgbSize = (((cb->dst_size.u4_width)*(cb->dst_size.u4_height)) << 1);
  addrOffset = 0;
  if (VIDEO_RENDERER_RENDER_MODE_TOUCH_WINDOW_FROM_INSIDE == cb->render_mode)
  {
    if ((0 != inside_dst_y) && (0 == inside_dst_x))
    {
      rgbSize = rgbSize + inside_dst_start_offset;
      addrOffset = inside_dst_start_offset;
      target_pitch = 0;
    }
    else if ((0 == inside_dst_y) && (0 != inside_dst_x)) 
    {
      rgbSize = (((target_pitch)*(cb->dst_size.u4_height)) << 1);
      addrOffset = 0;
    }
  }
  else
  {
    //When inside_dst_x = 0, and target_Pitch=0 ==> disable sw pitch
    inside_dst_x = 0;
    target_pitch = 0;
  }
  rgbSize = (((rgbSize + 31) >> 5) << 5) ; //length must 32 byte alignment for switch cacheable
  // TODO: add check size mechanism
  if (rgbSize>VA2_VR_VP_DISPLAY_BUFFER_SIZE)
  {
    rgbSize = VA2_VR_VP_DISPLAY_BUFFER_SIZE;
  }
  // busy loop til IDP finishes
  if (KAL_TRUE == blocking)
  {
      SW_VIDEO_RESIZER_CONFIG_STRUCT    sw_video_resizer_cfg;
      SW_VIDEO_RESIZER_PUT_STRUCT   video_put;

#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
      SLA_CustomLogging("SWG", 1);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)

      kal_mem_set(&sw_video_resizer_cfg,0x0,sizeof(sw_video_resizer_cfg));
      kal_mem_set(&video_put,0x0,sizeof(SW_VIDEO_RESIZER_PUT_STRUCT));

      video_put.input_buffer[0] =(kal_uint8*) video_frame->r_fb_addr.u4_fb_addr_plane0;
      video_put.input_buffer[1] =(kal_uint8*) video_frame->r_fb_addr.u4_fb_addr_plane1;
      video_put.input_buffer[2] =(kal_uint8*) video_frame->r_fb_addr.u4_fb_addr_plane2;

#if defined(IDP_SW_YUV420_2_UYVY422_RESIZER__DYNAMIC_SWITCH_CACHEABLE)
      dynamic_switch_cacheable_region(&cb->dst_fb_addr_array[1].u4_fb_addr_plane0, rgbSize, PAGE_CACHEABLE);
#endif //#if defined(IDP_SW_YUV420_2_UYVY422_RESIZER__DYNAMIC_SWITCH_CACHEABLE)

      video_put.output_buffer[0] = (kal_uint8*) ((cb->dst_fb_addr_array[1].u4_fb_addr_plane0)+addrOffset);

      _va2_vr_vp_6235_get_source_clip(cb); 
      sw_video_resizer_cfg.u4SrcClipX1 = video_src_clip.u4_clip_left;
      sw_video_resizer_cfg.u4SrcClipY1 = video_src_clip.u4_clip_top;
      sw_video_resizer_cfg.u4SrcClipX2 = video_src_clip.u4_clip_right;
      sw_video_resizer_cfg.u4SrcClipY2 = video_src_clip.u4_clip_bottom;
      sw_video_resizer_cfg.src_width = cb->src_size.u4_width;
      sw_video_resizer_cfg.src_height= cb->src_size.u4_height;
      sw_video_resizer_cfg.tar_width= cb->dst_size.u4_width;
      sw_video_resizer_cfg.tar_height= cb->dst_size.u4_height; 
      sw_video_resizer_cfg.tar_offset= inside_dst_x;
   
      sw_video_resizer_cfg.input_buff_width[0] = cb->src_size.u4_width;
      sw_video_resizer_cfg.input_buff_width[1] = (cb->src_size.u4_width >> 1);
      sw_video_resizer_cfg.input_buff_width[2] = (cb->src_size.u4_width >> 1);

      if(sw_video_resizer_init(&sw_video_resizer_cfg) != SW_VIDEO_RESIZER_SUCCESS)
      {
        ASSERT(0);
      } 

      //Starting the resize!!!!!!!!!!!!!!!!!!!!!     
      sw_video_resizer_put_data(&video_put,&sw_video_resizer_cfg);
      //Done..................................................................//
        
#if defined(IDP_SW_YUV420_2_UYVY422_RESIZER__DYNAMIC_SWITCH_CACHEABLE)   
      dynamic_switch_cacheable_region(&cb->dst_fb_addr_array[1].u4_fb_addr_plane0, rgbSize, PAGE_NO_CACHE);
#endif //#if defined(IDP_SW_YUV420_2_UYVY422_RESIZER__DYNAMIC_SWITCH_CACHEABLE

      sw_video_resizer_deinit();
      if (VIDEO_RENDERER_RENDER_MODE_TOUCH_WINDOW_FROM_INSIDE == cb->render_mode)
      {
        if ((0 != inside_dst_y) && (0 == inside_dst_x))
        {
          _va2_vr_vp_6235_touch_from_inside_pitch (&cb->dst_fb_addr_array[1].u4_fb_addr_plane0);
        }
      }
      {
         kal_uint8* dst_addr= (kal_uint8*)cb->dst_fb_start_addr_array[0].u4_fb_addr_plane0;
         kal_uint8* src_addr= (kal_uint8*)cb->dst_fb_addr_array[1].u4_fb_addr_plane0;
         kal_mem_cpy(dst_addr, src_addr, 
                    (cb->dst_fb_size.u4_width * cb->dst_fb_size.u4_height * va2_util_get_bpp(cb->dst_color_format)));
      }
#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
              SLA_CustomLogging("SWG", 0);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
      return cb->dst_fb_start_addr_array[0].u4_fb_addr_plane0;
  }
  else
  {
     kal_uint32 iIndex = (_va2_vr_render_display_buffer_cnt&0x1)+1;
     _va2_vr_vp_6235_get_source_clip(cb); 
     ASSERT(KAL_TRUE == idp_sw_resizer_start_hisr(
                              IDP_REQUIRE_TASK_DO_SW_RESIZER,   //nCmd , 1 for sw resizer, 2 for color format trasnform  
                              cb->src_size.u4_width,
                              cb->src_size.u4_height,
                              video_frame->r_clip_window.b_clip_enable,
                              video_src_clip.u4_clip_left,
                              video_src_clip.u4_clip_top,
                              video_src_clip.u4_clip_right,
                              video_src_clip.u4_clip_bottom,
                              cb->dst_size.u4_width,
                              cb->dst_size.u4_height,
                              video_frame->r_fb_addr.u4_fb_addr_plane0, 
                              video_frame->r_fb_addr.u4_fb_addr_plane1, 
                              video_frame->r_fb_addr.u4_fb_addr_plane2, 
                              cb->dst_fb_addr_array[iIndex].u4_fb_addr_plane0,
                              addrOffset,
                              rgbSize,
                              inside_dst_x,
                              (idp_sw_resizer_cbfxn_t)_va2_vr_vp_6235_sw_resizer_frmae_done_cb,
                                    NULL));
      _va2_vr_render_display_buffer_cnt++;
      _va2_vr_render_display_buffer_cnt &= 0x01;
    return 0;
  }
} // end of _va2_vr_vp_6235_render_display_frame_buffer

static void
_va2_vr_vp_6235_sw_resizer_frmae_done_cb(void *param)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6235_cb;
  kal_uint32 u4Flags = 0;
  g_bBusy_TouchInSide_Pitch = KAL_FALSE;
  kal_retrieve_eg_events(cb->EventID, TASK_WAIT_TRIGGER_DISPLAY_HISR_SET, KAL_AND_CONSUME, &u4Flags, KAL_NO_SUSPEND);
  visual_active_hisr(VISUAL_RENDERER_TRIGGER_DISPLAY_HISR_ID);
  kal_retrieve_eg_events(cb->EventID, TASK_WAIT_TRIGGER_DISPLAY_HISR_SET, KAL_AND_CONSUME, &u4Flags, KAL_SUSPEND);
}

static void
_va2_vr_vp_6235_hisr_trigger_display(void)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6235_cb;
  kal_uint32 iIndex;
  kal_set_eg_events(cb->EventID, TASK_WAIT_TRIGGER_DISPLAY_HISR_SET, KAL_OR);
  if (KAL_FALSE == g_bBusy_TouchInSide_Pitch)
  {
    _va2_vr_vp_6235_idp_frame_done_cb(NULL);
  }
  else
  {
    //Touch Fron Inside used.
    // Trigger display 
    iIndex = ((_va2_vr_render_display_buffer_cnt&0x1)^0x01)+1;
#if defined(DRV_DISPLAY_DRIVER_V2)
    if (WFC_FALSE == wfcMMCheckBusy())
    {
      _va2_vr_vp_6235_trigger_display(
        cb->dst_fb_addr_array[iIndex].u4_fb_addr_plane0, 
        cb);
    }
    else
    {
      _va2_vr_render_display_buffer_cnt--;    
      _va2_vr_render_display_buffer_cnt &= 0x01;
    }
#endif
    if (KAL_TRUE == cb->bypass)
    {
      // Unexpected: FrameDone occurs unders bypass mode.
      // Bypass mode should only be switched under Stop state, and render should only execute under Run state.
      // At last, FrameDone will not be processed except under Run state. There it is.
      ASSERT(0);
    }
    //Because of empty this buffer, when you call idp_frame_don_cb in task.
    //But empty this buffer is in the hisr will get the higher priority and will
    //cause system stack error from camera task (med_c_main.c)
    g_bBusy =KAL_FALSE;
    g_bBusy_TouchInSide_Pitch = KAL_FALSE;
  }
}

static void
_va2_vr_vp_6235_hisr_general(void)
{

  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6235_cb;

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
    }
    break;

  default:
    ASSERT(0);
  }

  cb->eVdoRndrHisrMode = VIDEO_RENDERER_HISR_MODE_NONE;


  return;
}

static void
_va2_vr_vp_6235_hisr_empty_this_buffer(void)
{
    va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6235_cb;
    _va2_vr_vp_6235_empty_this_buffer_real(&_va2_comp_video_renderer_rNewBuffHeader);
    kal_set_eg_events(cb->EventID, TASK_WAIT_HISR_SET, KAL_OR);
}


/**
 *  @status XX
 */
static void
_va2_vr_vp_6235_disp_timer_visu_hisr_cb_func(void)
{
  kal_bool idp_busy;
  static kal_uint32 _u4DispTimerRefreshCnt = 0;
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6235_cb;

  VA2_VIDEO_FRAME_T *video_frame;
  va2_util_buf_hdr_q_item_t *curr_dspl_buf_hdr;

#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("TM1", 1);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)

  _u4DispTimerRefreshCnt++;

  if (g_bBusy==KAL_TRUE)
  {
    return;
  }

  va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
  if( (NULL == cb) || 
      (NULL == cb->vr_q_handle.curr_dspl_buf_hdr))
  { 
    ASSERT(0); // incorrect param
  }
  curr_dspl_buf_hdr = cb->vr_q_handle.curr_dspl_buf_hdr;
  // get frame data...
  video_frame = (VA2_VIDEO_FRAME_T*) curr_dspl_buf_hdr->buffer_header.pPrivateData;
  ASSERT(NULL != video_frame);
  kal_mem_cpy(&(cb->src_size), &(video_frame->r_fb_size), sizeof(VA2_FRAME_SIZE_T));
  kal_mem_cpy(&(cb->src_clip), &(video_frame->r_clip_window), sizeof(VA2_CLIP_WINDOW_T));
  kal_mem_cpy(&(cb->src_fb_addr), &(video_frame->r_fb_addr), sizeof(VA2_FRAME_BUFFER_ADDRESS_T));
  if (_va2_vr_vp_6235_check_resize_ratio(cb))
  {
      cb->funcs.render_dspl_frame_buf = _va2_vr_vp_6235_sw_render_display_frame_buffer;
      sw_video_resizer_is_busy(_va2_comp_video_renderer_idp_key,&idp_busy);
  }
  else
  {
      cb->funcs.render_dspl_frame_buf = _va2_vr_vp_6235_hw_render_display_frame_buffer;
      idp_video_decode_is_busy(_va2_comp_video_renderer_idp_key,&idp_busy);
  }   
  if (idp_busy==KAL_TRUE)
  {
    return;
  }

  // If IDP not busy and no BH waiting...
  if ((KAL_FALSE == idp_busy) && 
      (VIDEO_STATE_RUN == cb->state.eState) && 
      (KAL_FALSE == g_bBusy) &&
      (KAL_FALSE == cb->bypass) )
  {
      kal_uint32 save_irq_mask; 

    va2_vr_add_trace(&_va2_vr_vp_6235_debug_trace[0], VA2_VR_INTERNAL____DSPL_TIMER_TRIGGER_RENDER_IN_VHISR, (kal_uint32) cb->vr_q_handle.curr_dspl_buf_hdr);

#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
    SLA_CustomLogging("RTM", 1);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
    save_irq_mask = SaveAndSetIRQMask();
    g_bBusy = KAL_TRUE;
    RestoreIRQMask(save_irq_mask);

    cb->funcs.render_dspl_frame_buf(cb, KAL_FALSE); 

#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
    SLA_CustomLogging("RTM", 0);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
  }

#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
    SLA_CustomLogging("TM1", 0);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)

}  // end of _va2_vr_vp_6235_disp_timer_visu_hisr_cb_func


/**
 *  @status OK
 *  @todo init the control block
 *  @common none
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6235_t01_close_to_init(
  va2_comp_video_renderer_cb_t *cb)
{
  if (NULL == cb)
  {
    ASSERT(0);
  }

  va2_vr_add_trace(&_va2_vr_vp_6235_debug_trace[0], VA2_VR_TRANSITION__T01_CLOSE_TO_INIT, 0);
    
  if (VIDEO_ERROR_NONE != va2_vr_t01_close_to_init(cb))
  {
    return VIDEO_ERROR_INIT_ERROR;
  }

  //  4. Initialize video renderer parameters...
  {
    //    4.1 allocate memory for secondary display frame buffer
    //Modify for 0x01000000 hardware bug(isp).
    ispVideoFrame_UYVY422 = VideoGetRendererExtBuffer(_va2_vr_render_extmem_handler,(VA2_VR_VP_SW_RESIZER_BUFFER_SIZE));
    ispVideoFrame_UYVY422 += 0x1f;
    ispVideoFrame_UYVY422 &= ~0x1f;

    if (0 == ispVideoFrame_UYVY422)
    {
      ASSERT(0); // buffer allocation failed
    }

    ispVideoFrame_UYVY422 = VideoCommExtBufferCacheableSwitch( ispVideoFrame_UYVY422, 
                                                               (VA2_VR_VP_SW_RESIZER_BUFFER_SIZE-32), 
                                                               VIDEO_NON_CACHEABLE);

    sw_video_resizer_deinit();       

    //Because MMI's frame buffer doesn't have 32-Bytes Alignment.
    //You must allocate it in Thumbnail mode
    cb->dst_fb_addr_array[1].u4_fb_addr_plane0 = VideoGetExtBuffer(_va2_vr_render_extmem_handler,VA2_VR_VP_DISPLAY_BUFFER_SIZE);
    if (0 == cb->dst_fb_addr_array[1].u4_fb_addr_plane0)
    {
      //ASSERT(0); // buffer allocation failed
      return VIDEO_ERROR_NO_MEMORY; // memory allocation fail
    }
    
    cb->dst_fb_addr_array[1].u4_fb_addr_plane0 = 
                VideoCommExtBufferCacheableSwitch( cb->dst_fb_addr_array[1].u4_fb_addr_plane0, 
                                                   VA2_VR_VP_DISPLAY_BUFFER_SIZE,
                                                   VIDEO_NON_CACHEABLE);


    if (cb->renderer_type == VIDEO_RENDERER_VIDEO_PLAYBACK)
    {   
      //Because MMI's frame buffer doesn't have 32-Bytes Alignment.
      cb->dst_fb_addr_array[2].u4_fb_addr_plane0 = VideoGetExtBuffer(_va2_vr_render_extmem_handler,VA2_VR_VP_DISPLAY_BUFFER_SIZE);
      if (0 == cb->dst_fb_addr_array[2].u4_fb_addr_plane0)
      {
        //ASSERT(0); // buffer allocation failed
        return VIDEO_ERROR_NO_MEMORY; // memory allocation fail
      }
      cb->dst_fb_addr_array[2].u4_fb_addr_plane0 = 
                  VideoCommExtBufferCacheableSwitch( cb->dst_fb_addr_array[2].u4_fb_addr_plane0, 
                                                     VA2_VR_VP_DISPLAY_BUFFER_SIZE,
                                                     VIDEO_NON_CACHEABLE);
    }     

#if defined(CONTOUR_IMPROVEMENT_MT6235)
     //     allocate memory for sw dithering working memory
     cb->WM_start_address = VideoGetExtBuffer(_va2_vr_render_extmem_handler, VA2_VR_SW_DITHER_WORKING_MEM_SZ);
     if (0 == cb->WM_start_address)
     {
       //ASSERT(0); // buffer allocation failed
       return VIDEO_ERROR_NO_MEMORY; // memory allocation fail
     }
     cb->WM_start_address = 
                   VideoCommExtBufferCacheableSwitch( cb->WM_start_address, 
                                                       VA2_VR_SW_DITHER_WORKING_MEM_SZ,
                                                       VIDEO_NON_CACHEABLE);
      cb->WM_size = VA2_VR_SW_DITHER_WORKING_MEM_SZ;
#endif // #if defined(CONTOUR_IMPROVEMENT_MT6235)

    {
       //     allocate memory for sw pitch working memory
       cb->SW_Pitch_Mem_Addr = VideoGetExtBuffer(_va2_vr_render_extmem_handler, VA2_VR_VP_SW_PITCH_WORKING_MEM_SIZE);
       if (0 == cb->SW_Pitch_Mem_Addr)
       {
         //ASSERT(0); // buffer allocation failed
         return VIDEO_ERROR_NO_MEMORY; // memory allocation fail
       }
       cb->SW_Pitch_Mem_Addr = 
                   VideoCommExtBufferCacheableSwitch( cb->SW_Pitch_Mem_Addr, 
                                                      VA2_VR_VP_SW_PITCH_WORKING_MEM_SIZE,
                                                      VIDEO_CACHEABLE);
       cb->SW_Pitch_Mem_Size = VA2_VR_VP_SW_PITCH_WORKING_MEM_SIZE;
    }

    //    4.3
    // TODO: very temp...
    cb->dst_fb_start_addr_array[0].u4_fb_addr_plane0 = 
      cb->dst_fb_addr_array[0].u4_fb_addr_plane0;
    cb->dst_fb_start_addr_array[1].u4_fb_addr_plane0 = 
      cb->dst_fb_addr_array[1].u4_fb_addr_plane0;
    cb->dst_fb_start_addr_array[2].u4_fb_addr_plane0 = 
      cb->dst_fb_addr_array[2].u4_fb_addr_plane0;
  }
  _va2_vr_render_display_buffer_cnt = 0;
  g_bBusy_SW_YUV420_2_UYVY422 = KAL_FALSE;
  g_bBusy_TouchInSide_Pitch = KAL_FALSE;
  bIsSpecialVideoResolution = KAL_FALSE;
  return VIDEO_ERROR_NONE;
}



/**
 *  @status OK
 *  @todo: remove those "very temp" part before SQC...
 *  @common VR.VP
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6235_t03_init_to_idle(
  va2_comp_video_renderer_cb_t *cb)
{

  if (NULL == cb)
  {
    ASSERT(0);
  }

  va2_vr_add_trace(&_va2_vr_vp_6235_debug_trace[0], VA2_VR_TRANSITION__T03_INIT_TO_IDLE, 0);

#if 0   // Delay idp_video_decode_open() to the point of entering RUN state.
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // #if 0

  cb->bIsErrorNotified = KAL_FALSE;

  //    1.1 register VISUAL HISR for misc video render use
  VISUAL_Register_HISR(VISUAL_RENDERER_HISR_ID, _va2_vr_vp_6235_hisr_general);

  // For SW Resizer frame done used.
  VISUAL_Register_HISR(VISUAL_RENDERER_TRIGGER_DISPLAY_HISR_ID, _va2_vr_vp_6235_hisr_trigger_display);

  VISUAL_Register_HISR(VISUAL_RENDERER_EMPTY_THIS_BUFFER_HISR_ID, _va2_vr_vp_6235_hisr_empty_this_buffer);

  //    1.2 register VISUAL HISR for VR Timer processing. The timer is used to trigger MDP for redraw when 
  //        there is no video frame in certain period of time. Under the situation, the UI updates will not
  //        be in effect since UI updates relies on MDP trigger under hardware trigger mode. The reason to 
  //        let timer activates Visual HISR for MDP trigger is to centralize the control of MDP, so that 
  //        reentrant condition can be solved.
  VISUAL_Register_HISR(VISUAL_RENDERER_TIMER_HISR_ID, _va2_vr_vp_6235_disp_timer_visu_hisr_cb_func);  

  //  2. Create a timer for periodically update display device
  if (0 == cb->display_timer)
  {
    cb->display_timer = kal_create_timer("VA2_VR_VP_6235_TIMER");
    if (0 == cb->display_timer)
    {
      ASSERT(0); // Timer create fail
    }
  }

  // 6. Invoke VideoCommChangeState() to change to IDLE state
  VideoCommClrAllQ(&(cb->state));
  VideoCommChangeState(&(cb->state), VIDEO_STATE_IDLE);
  return VIDEO_ERROR_NONE;
}


/**
 *  @status OK
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6235_t04_idle_to_run(
  va2_comp_video_renderer_cb_t *cb)
{
  kal_uint32 save_irq_mask;
  volatile VA2_VIDEO_RENDERER_HISR_MODE* pRndrHisrMode;

  if (NULL == cb)
  {
    ASSERT(0);
  }

  //chrono add for reset u4LastSrcRenderTimestamp
  cb->u4LastSrcRenderTimestamp = drv_get_current_time();

#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("I2R", 1);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)

  va2_vr_add_trace(&_va2_vr_vp_6235_debug_trace[0], VA2_VR_TRANSITION__T04_IDLE_TO_RUN, 0);

  if (KAL_FALSE == cb->bypass)  // Do not control LCD, timer, black frame under bypass mode
  {
     if ((0 == _va2_comp_video_renderer_idp_key) 
         && (KAL_FALSE == idp_video_decode_open(&_va2_comp_video_renderer_idp_key)))
      {
        ASSERT(0); // MDP driver open fail
      }

      save_irq_mask = SaveAndSetIRQMask();
      // Do not insert black frame if previous frame is available.
      // [MAUI_02597121] Do not insert a black frame if bypass mode since no need to update display.
      if ((NULL == cb->vr_q_handle.curr_dspl_buf_hdr) && 
          (0 == cb->vr_q_handle.to_be_processed_q.size) && 
          (KAL_FALSE == cb->bypass))
      {
        cb->eVdoRndrHisrMode = VIDEO_RENDERER_HISR_MODE_BLACK_FRAME_INSERT;
        visual_active_hisr(VISUAL_RENDERER_HISR_ID);
      }
      RestoreIRQMask(save_irq_mask);

    if (KAL_TRUE == cb->trigger_display)
    {
#if defined(DRV_DISPLAY_DRIVER_V1)
      lcd_frame_update_struct *lcd_cfg = &cb->display_surface.r_mtk_lcd_config;
#endif  // #if defined(DRV_DISPLAY_DRIVER_V1)       
      if (KAL_FALSE == _va2_comp_vr_have_config_lcd)
      {
#if defined(DRV_DISPLAY_DRIVER_V1)
        _va2_comp_vr_triggered_lcd_id_this_time = lcd_cfg->lcd_id;

        lcd_cfg->fb_update_mode = LCD_HW_TRIGGER_MODE;
        lcd_cfg->memory_output = KAL_FALSE;
        lcd_cfg->block_mode_flag = KAL_TRUE;  
        lcd_cfg->lcd_block_mode_cb = NULL;
        ASSERT(LCD_OK == lcd_fb_update(lcd_cfg));
#endif  // #if defined(DRV_DISPLAY_DRIVER_V1)      

#if defined(DRV_DISPLAY_DRIVER_V2)
        _va2_vr_vp_6235_config_n_activate_ddv2(cb);
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)

        va2_vr_add_trace(&_va2_vr_vp_6235_debug_trace[0], VA2_VR_DEBUG_______START_LCD_HW_TRIGGER_MODE, 0);
        _va2_comp_vr_have_config_lcd = KAL_TRUE;
      }
      kal_set_timer(cb->display_timer, 
                    (kal_timer_func_ptr) cb->funcs.display_timer_hdlr,
                    (void*) cb,
                    kal_milli_secs_to_ticks(VA2_COMP_VR_DSPL_DEFAULT_TIMEOUT_TIME),
                    kal_milli_secs_to_ticks(VA2_COMP_VR_DSPL_DEFAULT_TIMEOUT_TIME));
      
    }


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

    // buffer header movements...
    // if no current buffer header, advance to the latest if possible...
    if((NULL == cb->vr_q_handle.curr_dspl_buf_hdr) && 
       (0 != cb->vr_q_handle.to_be_processed_q.size))
    {
      // advance to the latest buffer header...
      va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
      ASSERT(NULL != cb->vr_q_handle.curr_dspl_buf_hdr);
    }
  } // end of bypass mode check
   
  //  Invoke VideoCommChangeState() to RUN state.
  if (VIDEO_ERROR_NONE != VideoCommChangeState(&(cb->state), VIDEO_STATE_RUN))
  {
    ASSERT(0);
  }

#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("I2R", 0);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)

  return VIDEO_ERROR_NONE;
}  // end of _va2_vr_vp_6235_t04_idle_to_run


/**
 *  @status OK
 *  @common VR.VP
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6235_t05_run_to_stop(
  va2_comp_video_renderer_cb_t *cb)
{
  kal_bool busy; 
  if (NULL == cb)
  {
    ASSERT(0);
  }

#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("R2S", 1);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)

  va2_vr_add_trace(&_va2_vr_vp_6235_debug_trace[0], VA2_VR_TRANSITION__T05_RUN_TO_STOP, 0);

  // Matt: to prevent EmptyThisBuffer, IDPFrameDone getting into wrong situation with a
  //       conservative state by reordering state assignment for in and out Run state.
  //       IL client is designed to invoke Renderer state transition in the blocking manner.
  //  0. Invoke VideoCommChangeState() to change state to STOP state.
  if (VIDEO_ERROR_NONE != VideoCommChangeState(&(cb->state), VIDEO_STATE_STOP))
  {
    ASSERT(0);
  }

  if (0 != cb->display_timer)
  {
    kal_cancel_timer(cb->display_timer);
  }

  //  Stop processing...
  if (KAL_TRUE == cb->bypass)
  {
    // TODO:[1] do something?
  }
  else
  {
    if (cb->funcs.render_dspl_frame_buf == _va2_vr_vp_6235_hw_render_display_frame_buffer)
    {
      //Check SW YUV420 2 UYVY422 Color Format Transform done or not?!!
      do
      {
        kal_sleep_task(2); // If assert here, it means blocking mode is only allowed to be invoked in NU+ task.
      } while (KAL_TRUE == g_bBusy_SW_YUV420_2_UYVY422);

      if (KAL_FALSE == idp_video_decode_stop(_va2_comp_video_renderer_idp_key))
      {
        ASSERT(0);
      }

      // Close idp_video_decode when leave RUN state to stop LCD HW update mode...
      if (KAL_FALSE == idp_video_decode_close(_va2_comp_video_renderer_idp_key))
      {
        ASSERT(0);
      }
      do
      {
        kal_sleep_task(1); // If assert here, it means blocking mode is only allowed to be invoked in NU+ task.
      } while (KAL_TRUE == g_bBusy_TouchInSide_Pitch);
      _va2_comp_video_renderer_idp_key = 0;
    }
    else
    {
        if (_va2_comp_video_renderer_idp_key!=0)
        {
            if (KAL_FALSE == idp_video_decode_stop(_va2_comp_video_renderer_idp_key))
            {
              ASSERT(0);
            }
            
            // Close idp_video_decode when leave RUN state to stop LCD HW update mode...
            if (KAL_FALSE == idp_video_decode_close(_va2_comp_video_renderer_idp_key))
            {
              ASSERT(0);
            }
            _va2_comp_video_renderer_idp_key = 0;
        }   
    
        do
        {
            kal_sleep_task(2); // If assert here, it means blocking mode is only allowed to be invoked in NU+ task.
            sw_video_resizer_is_busy(_va2_comp_video_renderer_idp_key,&busy);
        } while (KAL_TRUE == busy);
    
    }
    g_bBusy =KAL_FALSE;
if ( (cb->trigger_display) && 
     (KAL_TRUE == _va2_comp_vr_have_config_lcd))
    {
#if defined(DRV_DISPLAY_DRIVER_V1)
      lcd_stop_hw_update(_va2_comp_vr_triggered_lcd_id_this_time); // Not necessary...
#endif
#if defined(DRV_DISPLAY_DRIVER_V2)
      _va2_vr_vp_6235_stop_n_deactivate_ddv2(cb);
#endif
      va2_vr_add_trace(&_va2_vr_vp_6235_debug_trace[0], VA2_VR_DEBUG_______STOP_LCD_HW_TRIGGER_MODE, 0);
      _va2_comp_vr_have_config_lcd = KAL_FALSE;
    }
    _va2_vr_render_display_buffer_cnt = 0;  
  }

#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("R2S", 0);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)

  return VIDEO_ERROR_NONE;
}


/**
 *  @status OK
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6235_t06_stop_to_run(
  va2_comp_video_renderer_cb_t *cb)
{
#if defined(__MTK_TARGET__)
  kal_uint32 save_irq_mask;
  volatile VA2_VIDEO_RENDERER_HISR_MODE* pRndrHisrMode;


  if (NULL == cb)
  {
    ASSERT(0);
  }

  //chrono add for reset u4LastSrcRenderTimestamp
  cb->u4LastSrcRenderTimestamp = drv_get_current_time();


#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("S2R", 1);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)

  va2_vr_add_trace(&_va2_vr_vp_6235_debug_trace[0], VA2_VR_TRANSITION__T06_STOP_TO_RUN, 0);

  if (KAL_FALSE == cb->bypass)  // Do not control LCD, timer, black frame under bypass mode
  {
      if ((0 == _va2_comp_video_renderer_idp_key) 
          && (KAL_FALSE == idp_video_decode_open(&_va2_comp_video_renderer_idp_key)))
      {
        ASSERT(0); // MDP driver open fail
      }

      save_irq_mask = SaveAndSetIRQMask();
      // Do not insert black frame if previous frame is available.
      // [MAUI_02597121] Do not insert a black frame if bypass mode since no need to update display.
      if ((NULL == cb->vr_q_handle.curr_dspl_buf_hdr) && 
          (0 == cb->vr_q_handle.to_be_processed_q.size) && 
          (KAL_FALSE == cb->bypass))
      {
        cb->eVdoRndrHisrMode = VIDEO_RENDERER_HISR_MODE_BLACK_FRAME_INSERT;
        visual_active_hisr(VISUAL_RENDERER_HISR_ID);
      }
      RestoreIRQMask(save_irq_mask);

//  config LCD driver if LCD HW_Trig is requested through set_parameter
    if (KAL_TRUE == cb->trigger_display)
    {
#if defined(DRV_DISPLAY_DRIVER_V1)
      lcd_frame_update_struct *lcd_cfg = &cb->display_surface.r_mtk_lcd_config;
      //debug_reg666 =9;
#endif  // #if defined(DRV_DISPLAY_DRIVER_V1)
      if (KAL_FALSE == _va2_comp_vr_have_config_lcd)
      {
#if defined(DRV_DISPLAY_DRIVER_V1)
        _va2_comp_vr_triggered_lcd_id_this_time = lcd_cfg->lcd_id;

        lcd_cfg->fb_update_mode = LCD_HW_TRIGGER_MODE;
        lcd_cfg->memory_output = KAL_FALSE;
        lcd_cfg->block_mode_flag = KAL_TRUE;  
        lcd_cfg->lcd_block_mode_cb = NULL;

        // all the others are configed when processing video renderer parameters and configs

        // Config LCD and start updating.
        ASSERT(LCD_OK == lcd_fb_update(lcd_cfg));
#endif  // #if defined(DRV_DISPLAY_DRIVER_V1)

#if defined(DRV_DISPLAY_DRIVER_V2)
        _va2_vr_vp_6235_config_n_activate_ddv2(cb);
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)

        va2_vr_add_trace(&_va2_vr_vp_6235_debug_trace[0], VA2_VR_DEBUG_______START_LCD_HW_TRIGGER_MODE, 0);
        _va2_comp_vr_have_config_lcd = KAL_TRUE;
      }
      kal_set_timer(cb->display_timer, 
                    (kal_timer_func_ptr) cb->funcs.display_timer_hdlr,
                    (void*) cb,
                    kal_milli_secs_to_ticks(VA2_COMP_VR_DSPL_DEFAULT_TIMEOUT_TIME),
                    kal_milli_secs_to_ticks(VA2_COMP_VR_DSPL_DEFAULT_TIMEOUT_TIME));
    }

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

    // buffer header movements...
    // if no current buffer header, advance to the latest if possible...
    if((NULL == cb->vr_q_handle.curr_dspl_buf_hdr) && 
       (0 != cb->vr_q_handle.to_be_processed_q.size))
    {
      // advance to the latest buffer header...
      va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
      ASSERT(NULL != cb->vr_q_handle.curr_dspl_buf_hdr);
    }

  }

  //  Invoke VideoCommChangeState() to RUN state.
  if (VIDEO_ERROR_NONE != VideoCommChangeState(&(cb->state), VIDEO_STATE_RUN))
  {
    ASSERT(0);
  }

#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("S2R", 0);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)

#endif  // #if defined(__MTK_TARGET__)
  return VIDEO_ERROR_NONE;
}  // end of _va2_vr_vp_6235_t06_stop_to_run


/**
 *  @status OK
 *  @common VR.VP
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6235_t10_idle_to_close(
  va2_comp_video_renderer_cb_t *cb)
{
  kal_uint32 save_irq_mask;

  if (NULL == cb)
  {
    ASSERT(0);
  }

  va2_vr_add_trace(&_va2_vr_vp_6235_debug_trace[0], VA2_VR_TRANSITION__T10_IDLE_TO_CLOSE, 0);
  
  save_irq_mask = SaveAndSetIRQMask();
  //  1. reset buffer header queues...
  va2_util_buf_hdr_reset_buffer_header_queues(&(cb->vr_q_handle));
  RestoreIRQMask(save_irq_mask);

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
_va2_vr_vp_6235_init(void)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6235_cb;
  VIDEO_ERROR_TYPE_T iRet;

  // create semaphore for API protection
  if (0 == cb->vr_sema_vrstate_sync)
  {
    cb->vr_sema_vrstate_sync = kal_create_sem("VA2_VR_VP_SEMA_VHISRCMD", 1);
  }

  kal_take_sem(cb->vr_sema_vrstate_sync, KAL_INFINITE_WAIT);

  va2_vr_init_trace(VA2_VR_VP_6235_DEBUG_TRACE_SIZE, &_va2_vr_vp_6235_debug_trace[0]);

  va2_vr_add_trace(&_va2_vr_vp_6235_debug_trace[0], VA2_VR_API_________INIT, 0);

  if (VIDEO_STATE_CLOSE != cb->state.eState)
  {
    ASSERT(0); // incorrect state
    kal_give_sem(cb->vr_sema_vrstate_sync);
    return VIDEO_ERROR_INIT_ERROR;
  }

  iRet = cb->funcs.t01_close_to_init(cb);
  kal_give_sem(cb->vr_sema_vrstate_sync);

  return iRet;
}

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6235_send_command(
  VIDEO_COMMAND_TYPE_T eCmd, 
  kal_uint32 u4Param)
{
  return va2_vr_send_command(&_va2_vr_vp_6235_cb, eCmd, u4Param);
}


/**
 *  @status OK
 *  @common VR.VP
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6235_get_parameter(
  VIDEO_PARAM_TYPE_T eCmd, 
  void *pParam)
{
  VIDEO_ERROR_TYPE_T iRet = VIDEO_ERROR_NONE;
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6235_cb;
  VA2_VIDEO_FRAME_T *video_frame;
  va2_util_buf_hdr_q_item_t *curr_dspl_buf_hdr;

  // special case, this config could be get in any state...
  if (VIDEO_CONFIG_RENDERER_STATUS == eCmd)
  {
    ASSERT(NULL != pParam);
    *((VIDEO_STATE_TYPE_T*) pParam) = cb->state.eState;
    return VIDEO_ERROR_NONE;
  }

  kal_take_sem(cb->vr_sema_vrstate_sync, KAL_INFINITE_WAIT);
  va2_vr_add_trace(&_va2_vr_vp_6235_debug_trace[0], VA2_VR_API_________GET_PARAMETER, (kal_uint32) eCmd);

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

  case VIDEO_PARAM_RENDERER_RENDER_DISPLAY_BUFFER: /**< arg type: kal_uint32* */
    if ((VIDEO_STATE_STOP != cb->state.eState) && 
        (VIDEO_STATE_IDLE != cb->state.eState))
    {
      ASSERT(0); // This parameter is only supported in STOP and IDLE state...
    }
    // TODO: Note this! Video Renderer will NOT assert if no video frame to be rendered
    //if no any frame, please draw the display frame buffer to black.
    if ((NULL == cb->vr_q_handle.curr_dspl_buf_hdr) && 
        (0 == cb->vr_q_handle.to_be_processed_q.size))
    {
      // TODO: draw the display frame buffer to black!
     
      ASSERT(NULL != cb->dst_fb_addr_array[0].u4_fb_addr_plane0);
      {
        kal_uint32 size = cb->dst_fb_size.u4_width * 
                          cb->dst_fb_size.u4_height * 
                          va2_util_get_bpp(cb->dst_color_format);
        kal_uint32 addr;
        if (0x0 != (addr = cb->dst_fb_start_addr_array[0].u4_fb_addr_plane0))
        {
          kal_mem_set((void*) addr, 0x0, size);
        }
      }
      va2_vr_add_trace(&_va2_vr_vp_6235_debug_trace[0], VA2_VR_DEBUG_______NO_VIDEO_FRAME_TO_DRAW, 0);
      *(kal_uint32*)pParam = cb->dst_fb_addr_array[0].u4_fb_addr_plane0;
      break;
    }

    if ((KAL_FALSE == cb->keep_curr_ptr_when_run) || 
        (NULL == cb->vr_q_handle.curr_dspl_buf_hdr)) // [MAUI_02568443] To cover curr is NULL case.
    {
      va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
    }
    
    curr_dspl_buf_hdr = cb->vr_q_handle.curr_dspl_buf_hdr;
    // get frame data...
    video_frame = (VA2_VIDEO_FRAME_T*) curr_dspl_buf_hdr->buffer_header.pPrivateData;
    ASSERT(NULL != video_frame);
    kal_mem_cpy(&(cb->src_size), &(video_frame->r_fb_size), sizeof(VA2_FRAME_SIZE_T));
    kal_mem_cpy(&(cb->src_clip), &(video_frame->r_clip_window), sizeof(VA2_CLIP_WINDOW_T));
    kal_mem_cpy(&(cb->src_fb_addr), &(video_frame->r_fb_addr), sizeof(VA2_FRAME_BUFFER_ADDRESS_T));
    if (_va2_vr_vp_6235_check_resize_ratio(cb))
    {
        cb->funcs.render_dspl_frame_buf = _va2_vr_vp_6235_sw_render_display_frame_buffer;
        *(kal_uint32*)pParam = cb->funcs.render_dspl_frame_buf(cb, KAL_TRUE);
    }
    else
    {
        cb->funcs.render_dspl_frame_buf = _va2_vr_vp_6235_hw_render_display_frame_buffer;
        if (0 == _va2_comp_video_renderer_idp_key) 
        {
           if (KAL_FALSE == idp_video_decode_open(&_va2_comp_video_renderer_idp_key))           
           {
                cb->funcs.render_dspl_frame_buf = _va2_vr_vp_6235_sw_render_display_frame_buffer;
                *(kal_uint32*)pParam = cb->funcs.render_dspl_frame_buf(cb, KAL_TRUE);
           }
           else
           {
               *(kal_uint32*)pParam = cb->funcs.render_dspl_frame_buf(cb, KAL_TRUE);
               
               if (KAL_FALSE == idp_video_decode_close(_va2_comp_video_renderer_idp_key))
               {
                 ASSERT(0);
               }
               _va2_comp_video_renderer_idp_key = 0;
           }
        }
        else
        {
          ASSERT(0);
        }
    }
    if(KAL_FALSE == (*(kal_uint32*)pParam) || (*(kal_uint32*)pParam != cb->dst_fb_start_addr_array[0].u4_fb_addr_plane0))
    {
      iRet = VIDEO_ERROR_INPUT_PARAM_ERROR;
    }
    break;

  case VIDEO_PARAM_RENDERER_ROTATE_FLIP: /**< arg type: va2_video_renderer_rotate_flip_t* */
    kal_mem_cpy(pParam, &(cb->rotate_flip), sizeof(va2_video_renderer_rotate_flip_t));
    break;
    
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

  default:
    iRet = VIDEO_ERROR_INPUT_PARAM_ERROR;
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
_va2_vr_vp_6235_set_parameter(
  VIDEO_PARAM_TYPE_T eCmd, 
  void *pParam)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6235_cb;
  VIDEO_STATE_TYPE_T state;
  VIDEO_ERROR_TYPE_T i4Ret = VIDEO_ERROR_UNDEFINED;

  kal_take_sem(cb->vr_sema_vrstate_sync, KAL_INFINITE_WAIT);

  state = cb->state.eState;

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
            ASSERT(0); // incorrect parameter
          }

          if (VIDEO_RENDERER_COLOR_RGB565 != *color_format)
          {
            return VIDEO_ERROR_INPUT_PARAM_ERROR;
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
        if ((cb->bypass == KAL_FALSE) &&
            (cb->renderer_type == VIDEO_RENDERER_VIDEO_THUMBNAIL))
        {i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;}
        else
        {i4Ret = VIDEO_ERROR_NONE;}
        break;

      case VIDEO_PARAM_RENDERER_ROTATE_FLIP: /**< arg type: va2_video_renderer_rotate_flip_t* */
        {
          va2_video_renderer_rotate_flip_t *rotate_flip = (va2_video_renderer_rotate_flip_t*) pParam;
      
          if (NULL == rotate_flip)
          {
            ASSERT(0);
          }
      
          if ((0 == rotate_flip->u2_cw_rotate_angle) || 
              (90 == rotate_flip->u2_cw_rotate_angle) || 
              (180 == rotate_flip->u2_cw_rotate_angle) ||
              (270 == rotate_flip->u2_cw_rotate_angle))
          {
          }
          else
          {
            ASSERT(0);
          }
      
          if ((KAL_TRUE == rotate_flip->b_flip) || 
              (KAL_FALSE == rotate_flip->b_flip))
          {
          }
          else
          {
            ASSERT(0);
          }
      
          cb->rotate_flip.u2_cw_rotate_angle = rotate_flip->u2_cw_rotate_angle;
          cb->rotate_flip.b_flip = rotate_flip->b_flip;
        }
        i4Ret = VIDEO_ERROR_NONE;
        break;
      
      default: 
        // i4Ret is still VIDEO_ERROR_UNDEFINED...
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

      case VIDEO_CONFIG_RENDERER_SOURCE_FRAME_PERIOD: /**< arg type: kal_uint32* */
        {
          kal_uint32 *frame_period_in_ms = (kal_uint32 *) pParam;
          cb->u4FramePeriodInMS = *frame_period_in_ms;
          if(cb->u4FramePeriodInMS > 30000)
          {
            cb->u4FramePeriodInMS = 110;
          }
#if defined(CONTOUR_IMPROVEMENT_MT6235)
          cb->u4Fps = (1000/(cb->u4FramePeriodInMS));
#endif
        }
        i4Ret = VIDEO_ERROR_NONE;
        break;
        
      case VIDEO_CONFIG_RENDERER_BYPASS_HW_LAYER_SRC_RECT:
        {
          kal_bool *bypass_hw_layer_src_rect = (kal_bool*) pParam;
          
          if (NULL == bypass_hw_layer_src_rect)
          {
            ASSERT(0);
            break;
          }
          
          if ((KAL_TRUE == *bypass_hw_layer_src_rect) ||
              (KAL_FALSE == *bypass_hw_layer_src_rect))
          {
            cb->bypass_hw_layer_src_rect = *bypass_hw_layer_src_rect;
          }
          else
          {
            ASSERT(0);
            break;
          }
        }
        i4Ret = VIDEO_ERROR_NONE;
        break;
        
#if defined(CONTOUR_IMPROVEMENT_MT6235)
      case VIDEO_CONFIG_RENDERER_DECODE_TIME: /**< arg type: kal_uint32* */
        {
          kal_uint32 *u4Time = (kal_uint32 *) pParam;

          cb->u4DecodingTime = *u4Time;
        }
        i4Ret = VIDEO_ERROR_NONE;
        break;
#endif
      
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

  kal_give_sem(cb->vr_sema_vrstate_sync);
  return VIDEO_ERROR_NONE;
}

/**
 *  @status OK
 *  @common VR
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6235_use_buffer(
  kal_uint8 *pu1Buff, 
  kal_uint32 u4Size)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6235_cb;
  VIDEO_ERROR_TYPE_T i4Ret;

  kal_take_sem(cb->vr_sema_vrstate_sync, KAL_INFINITE_WAIT);
  i4Ret = va2_vr_use_buffer(&_va2_vr_vp_6235_cb, pu1Buff, u4Size);
  kal_give_sem(cb->vr_sema_vrstate_sync);
  return i4Ret;
}

/**
 *  @status OK
 *  @todo vr_q_handle
 *  @common VR.VP
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6235_empty_this_buffer(
  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
  //MAUI_02978827
  //When Renderer's bypass is kal_true, V2DEC will send video buffer from task.
  //When Renderer's bypass is kal_false, V2DEC will send video buffer from hisr.
  //Med's task priority is higher than V2DEC Task. If Med task will change video renderer's status, our queue's state
  //will be re-entry. We check the video buffer whether is send from task or not?? If it does, we will actiavte another
  //Hisr to send this video buffer.
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6235_cb;
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
  if (KAL_FALSE== kal_if_hisr())
  {
    kal_mem_cpy((void*) &(_va2_comp_video_renderer_rNewBuffHeader), prBuffHeader, sizeof(VIDEO_BUFFERHEADER_TYPE_T));
    kal_retrieve_eg_events(cb->EventID, TASK_WAIT_HISR_SET, KAL_AND_CONSUME, &u4Flags, KAL_NO_SUSPEND);
    visual_active_hisr(VISUAL_RENDERER_EMPTY_THIS_BUFFER_HISR_ID);
    kal_retrieve_eg_events(cb->EventID, TASK_WAIT_HISR_SET, KAL_AND_CONSUME, &u4Flags, KAL_SUSPEND);
    return;
  }
  _va2_vr_vp_6235_empty_this_buffer_real(prBuffHeader);


  return VIDEO_ERROR_NONE;
}

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6235_empty_this_buffer_real(
  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
  va2_util_buf_hdr_q_item_t *q_item;
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6235_cb;

#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("REB", 1);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)

  va2_vr_add_trace(&_va2_vr_vp_6235_debug_trace[0], VA2_VR_API_________EMPTY_THIS_BUFFER, (kal_uint32) prBuffHeader->pu1Buffer);

  // 0.7 This action is to emulate the processing of the previous Bypass-Mode Frames
  if (KAL_TRUE == cb->bypass)
  {
    if(cb->state.eState == VIDEO_STATE_RUN)
    {
      // For bypass mode, don't process/advance unless the frame is enqueued in Run state
      va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
    }
  }

  //  1. Return all buffer headers except the curr_dspl_buf_hdr
  va2_util_buf_hdr_remove_all_q_items(&(cb->vr_q_handle.to_be_returned_q), &(cb->vr_q_handle.to_be_processed_q));
  cb->funcs.try_to_return_buf_hdrs(cb);

  //  2. enqueue the buffer header...
  q_item = va2_util_buf_hdr_get_empty_q_item(&(cb->vr_q_handle));
  if (NULL == q_item)
  {
    ASSERT(0);
  }

  // Add a log to track the last valid emptyThisBuffer calls...
  // To save memory...
  //va2_vr_add_trace_empty_this_buffer(cb, VA2_VR_API_________EMPTY_THIS_BUFFER, (kal_uint32) prBuffHeader->pu1Buffer);

  //    2.2 enqueue should not fail here...
  kal_mem_cpy((void*) &(q_item->buffer_header), prBuffHeader, sizeof(VIDEO_BUFFERHEADER_TYPE_T));
  va2_util_buf_hdr_enqueue(&(cb->vr_q_handle.to_be_processed_q), q_item);

#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("REB", 0);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)

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
        kal_bool busy;

        VA2_VIDEO_FRAME_T *video_frame;
        va2_util_buf_hdr_q_item_t *curr_dspl_buf_hdr;

        // TODO: W1045 Code Review Add g_bBusy's Reason. 
        //Due to frame switching, so sometimes use hw resizer, sometimes use sw resizer,
        //When using sw-resizer, you must block the new-coming frame. so we add a bool g_bBusy to control
        //SW and HW Procedure.
        if (g_bBusy == KAL_TRUE)
        {
          va2_vr_add_trace(&_va2_vr_vp_6235_debug_trace[0], VA2_VR_API_________EMPTY_THIS_BUFFER__ENQUEUE_ONLY, (kal_uint32) (cb->vr_q_handle.to_be_processed_q.tail));
          return VIDEO_ERROR_NONE;
        }       
        else
        {
            kal_uint32 save_irq_mask; 
            save_irq_mask = SaveAndSetIRQMask();
            g_bBusy = KAL_TRUE;
            RestoreIRQMask(save_irq_mask);
        }
        va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));

        if( (NULL == cb) || 
            (NULL == cb->vr_q_handle.curr_dspl_buf_hdr))
        { 
          ASSERT(0); // incorrect param
        }

        curr_dspl_buf_hdr = cb->vr_q_handle.curr_dspl_buf_hdr;

        // get frame data...
        video_frame = (VA2_VIDEO_FRAME_T*) curr_dspl_buf_hdr->buffer_header.pPrivateData;
        ASSERT(NULL != video_frame);
        //Yout must calculate in outside mode.
        kal_mem_cpy(&(cb->src_size), &(video_frame->r_fb_size), sizeof(VA2_FRAME_SIZE_T));
        kal_mem_cpy(&(cb->src_clip), &(video_frame->r_clip_window), sizeof(VA2_CLIP_WINDOW_T));
        kal_mem_cpy(&(cb->src_fb_addr), &(video_frame->r_fb_addr), sizeof(VA2_FRAME_BUFFER_ADDRESS_T));
        if (_va2_vr_vp_6235_check_resize_ratio(cb))
        {
            cb->funcs.render_dspl_frame_buf = _va2_vr_vp_6235_sw_render_display_frame_buffer;
            sw_video_resizer_is_busy(_va2_comp_video_renderer_idp_key,&busy);
        }
        else
        {
            cb->funcs.render_dspl_frame_buf = _va2_vr_vp_6235_hw_render_display_frame_buffer;
            idp_video_decode_is_busy(_va2_comp_video_renderer_idp_key,&busy);
        }

        //////////////////////////////////////////////////////////////////////////////////////////
        if(KAL_FALSE == busy)
        {
          va2_vr_add_trace(&_va2_vr_vp_6235_debug_trace[0], VA2_VR_API_________EMPTY_THIS_BUFFER__TRIGGER_HW, (kal_uint32)(cb->vr_q_handle.curr_dspl_buf_hdr));
          cb->funcs.render_dspl_frame_buf(cb, KAL_FALSE);
        }
        else
        {
          va2_vr_add_trace(&_va2_vr_vp_6235_debug_trace[0], VA2_VR_API_________EMPTY_THIS_BUFFER__ENQUEUE_ONLY, (kal_uint32) (cb->vr_q_handle.to_be_processed_q.tail));
        }
        cb->u4LastSrcRenderTimestamp = drv_get_current_time();
      }
      break;

    case VIDEO_STATE_STOP:
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
_va2_vr_vp_6235_fill_this_buffer(
  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6235_cb;
  VIDEO_ERROR_TYPE_T i4Ret = VIDEO_ERROR_NONE;
  
  i4Ret = va2_vr_fill_this_buffer(cb, prBuffHeader);

  return i4Ret;
}

/**
 *  @status OK
 *  @common VR
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6235_set_callbacks(
  VIDEO_CALLBACK_TYPE_T *prCallback)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6235_cb;
  VIDEO_ERROR_TYPE_T i4Ret;

  kal_take_sem(cb->vr_sema_vrstate_sync, KAL_INFINITE_WAIT);
  i4Ret = va2_vr_set_callbacks(&_va2_vr_vp_6235_cb, prCallback);
  kal_give_sem(cb->vr_sema_vrstate_sync);

  return i4Ret;
}

/**
 *  @status OK
 *  @remark this function could only be invoked when in CLOSE state.
 */
VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6235_deinit(void)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6235_cb;
  VIDEO_ERROR_TYPE_T i4Ret;

#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("DIN", 1);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)

  kal_take_sem(cb->vr_sema_vrstate_sync, KAL_INFINITE_WAIT);
  i4Ret = va2_vr_deinit(&_va2_vr_vp_6235_cb);
  va2_vr_init_trace(0, NULL);
  kal_give_sem(cb->vr_sema_vrstate_sync);

#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("DIN", 0);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)

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
va2_video_renderer_vp_mt6235_get_handle(
  VA2_VIDEO_RENDERER_TYPE_T e_type)
{
#if defined(__MTK_TARGET__)
  VIDEO_COMPONENT_TYPE_T *pr_video_renderer_comp = NULL;
  //VIDEO_ERROR_TYPE_T error_code = VIDEO_ERROR_NONE;

  switch (e_type)
  {
  case VIDEO_RENDERER_VIDEO_THUMBNAIL:
  case VIDEO_RENDERER_MJPG_THUMBNAIL:
    pr_video_renderer_comp = &_va2_vr_vp_6235_primitives;
    _va2_vr_vp_6235_cb.renderer_type = VIDEO_RENDERER_VIDEO_THUMBNAIL;
    break;

  case VIDEO_RENDERER_VIDEO_PLAYBACK:
  case VIDEO_RENDERER_MJPG_PLAYBACK:
    pr_video_renderer_comp = &_va2_vr_vp_6235_primitives;
    _va2_vr_vp_6235_cb.renderer_type = VIDEO_RENDERER_VIDEO_PLAYBACK;
    break;

  default: 
    break;
  }

  return pr_video_renderer_comp;
#else   // #if defined(__MTK_TARGET__)
  return NULL;
#endif  // #if defined(__MTK_TARGET__)
}

/**
 *  @status OK
 */
VIDEO_ERROR_TYPE_T 
va2_video_renderer_vp_mt6235_release_handle(
  VIDEO_COMPONENT_TYPE_T *pr_handle)
{
#if defined(__MTK_TARGET__)
  VIDEO_ERROR_TYPE_T error_code = VIDEO_ERROR_NONE;
  
  if ((NULL == pr_handle) || 
      (&_va2_vr_vp_6235_primitives != pr_handle) || 
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

#endif  // #if defined(VA2_VIDEO_RENDERER_VP_MT6235)
#endif  // #if defined(__VIDEO_ARCHI_V2__)
/// @}

