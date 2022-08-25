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
 *    va2_video_renderer_vp_mt6268.c
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
 *
 *
 ****************************************************************************/
/// \ingroup va2_video_renderer_vp_mt6268
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
#include "va2_video_renderer_vp_mt6268.h"

#if defined(VA2_VIDEO_RENDERER_VP_MT6268)

/******* Kernal abstraction *****************/
#include "kal_public_api.h"
#include "string.h"
#include "kal_general_types.h"
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
#include "idp_video_decode.h" // TODO:[3] check inc path
#include "idp_mem_def.h"
/******* LCD driver *************************/
#include "lcd_if.h" // TODO:[3] check inc path
#include "lcd_if_hw.h" // TODO:[3] check inc path
#include "lcd_sw_inc.h"
#include "drv_features_display.h"
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
#if defined(VA2_VR_VP_6268_ENABLE_SWLA_TRACE)
#include "SST_sla.h"
#endif  // #if defined(VA2_VR_VP_6268_ENABLE_SWLA_TRACE)

/****************************************************************************
 * local type definitions and macros
 ****************************************************************************/
#define VA2_COMP_VR_RENDER_TIME_MAX             (1100) // (32768/1000)*33.3 ~ 1091 // 33.3ms

#define VA2_VR_VP_6268_DEBUG_TRACE_SIZE         (32)

typedef struct
{
    kal_uint32 clip_conv_disp_width;
    kal_uint32 clip_conv_disp_height;
    kal_uint32 clip_conv_clip_left;
    kal_uint32 clip_conv_clip_right;
    kal_uint32 clip_conv_clip_top;
    kal_uint32 clip_conv_clip_bottom;
} VA2_6268_RENDERER_CLIP_CONVERT_T;

/****************************************************************************
 * declarations
 ****************************************************************************/
#if defined(__MTK_TARGET__)
static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6268_init(void);

static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6268_send_command(
  VIDEO_COMMAND_TYPE_T eCmd,
  kal_uint32 u4Param);

static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6268_get_parameter(
  VIDEO_PARAM_TYPE_T eCmd,
  void *pParam);

static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6268_set_parameter(
  VIDEO_PARAM_TYPE_T eCmd,
  void *pParam);

static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6268_use_buffer(
  kal_uint8 *pu1Buff,
  kal_uint32 u4Size);

static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6268_empty_this_buffer(
  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader);

static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6268_empty_this_buffer_real(
  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader);

static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6268_fill_this_buffer(
  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader);

static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6268_set_callbacks(
  VIDEO_CALLBACK_TYPE_T *prCallback);

static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6268_deinit(void);

static kal_uint32
_va2_vr_vp_6268_render_display_frame_buffer(
  va2_comp_video_renderer_cb_t *cb,
  kal_bool blocking);

static kal_bool
_va2_vr_vp_6268_check_params_configs(
  va2_comp_video_renderer_cb_t *cb);

static kal_bool
_va2_vr_vp_6268_config_idp_by_render_mode(
  va2_comp_video_renderer_cb_t *cb,
  VA2_VIDEO_FRAME_T *video_frame);

static void
_va2_vr_vp_6268_display_timer_hdlr(
  void *param);

static kal_bool
_va2_vr_vp_6268_idp_frame_done_cb(
  void *param);

static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6268_t01_close_to_init(
  va2_comp_video_renderer_cb_t *cb);

static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6268_t03_init_to_idle(
  va2_comp_video_renderer_cb_t *cb);

static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6268_t04_idle_to_run(
  va2_comp_video_renderer_cb_t *cb);

static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6268_t05_run_to_stop(
  va2_comp_video_renderer_cb_t *cb);

static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6268_t06_stop_to_run(
  va2_comp_video_renderer_cb_t *cb);

static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6268_t10_idle_to_close(
  va2_comp_video_renderer_cb_t *cb);

static void 
_va2_vr_vp_6268_lcd_frame_done_cb(
  void *param);
#endif  // #if defined(__MTK_TARGET__)

/****************************************************************************
 * local variables
 ****************************************************************************/
#if defined(__MTK_TARGET__)

/**
 *  @status OK
 */
static VIDEO_COMPONENT_TYPE_T _va2_vr_vp_6268_primitives =
{
    _va2_vr_vp_6268_init
  , _va2_vr_vp_6268_send_command
  , _va2_vr_vp_6268_get_parameter
  , _va2_vr_vp_6268_set_parameter
  , _va2_vr_vp_6268_use_buffer
  , _va2_vr_vp_6268_empty_this_buffer
  , _va2_vr_vp_6268_fill_this_buffer
  , _va2_vr_vp_6268_set_callbacks
  , _va2_vr_vp_6268_deinit
};

static struct va2_comp_video_renderer_cb _va2_vr_vp_6268_cb =
  {
    {
      _va2_vr_vp_6268_t01_close_to_init,
      va2_vr_t02_init_to_close,
      _va2_vr_vp_6268_t03_init_to_idle,
      _va2_vr_vp_6268_t04_idle_to_run,
      _va2_vr_vp_6268_t05_run_to_stop,
      _va2_vr_vp_6268_t06_stop_to_run,
      va2_vr_t07_run_to_idle,
      va2_vr_t08_stop_to_idle,
      va2_vr_t09_idle_to_init,
      _va2_vr_vp_6268_t10_idle_to_close,
      va2_vr_t11_stop_to_close,
      va2_vr_t12_idle_to_idle,
      va2_vr_try_to_return_buffer_headers,
      _va2_vr_vp_6268_check_params_configs,
      _va2_vr_vp_6268_config_idp_by_render_mode,
      (va2_vr_dspl_timer_hdlr_func_t) _va2_vr_vp_6268_display_timer_hdlr,
      (va2_vr_hw_frame_done_cb_func_t) _va2_vr_vp_6268_idp_frame_done_cb,
      _va2_vr_vp_6268_render_display_frame_buffer,
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

static va2_vr_debug_trace_entry_t _va2_vr_vp_6268_debug_trace[VA2_VR_VP_6268_DEBUG_TRACE_SIZE] = {0};

static kal_bool g_idp_val_video_decode_is_vp7 = KAL_FALSE;

static  kal_bool    force_lcd_hw_trigger = KAL_FALSE;

extern VIDEO_BUFFERHEADER_TYPE_T _rBlackBufferHdr;
extern VA2_VIDEO_FRAME_T _rBlackVdoFrm;
extern WFD_LCD_DC_ENGINE_ENUM __wfd_lcd_dc_engine;

#if defined(DRV_DISPLAY_DRIVER_V2)
static WFCDevice _va2_vr_vp_6268_ddv2_dev = WFC_INVALID_HANDLE;
static WFCContext _va2_vr_vp_6268_ddv2_ctx = WFC_INVALID_HANDLE;
static WFCElement _va2_vr_vp_6268_ddv2_element = WFC_INVALID_HANDLE;
static WFCSource _va2_vr_vp_6268_ddv2_src = WFC_INVALID_HANDLE;
static WFCSource _va2_vr_vp_6268_ddv2_img_src = WFC_INVALID_HANDLE;
static OWFNativeStreamType _va2_vr_vp_6268_ddv2_stream = OWF_INVALID_HANDLE;
static kal_uint32 _va2_vr_vp_6268_dspl_fbs[3][2] = { 0 };

static volatile kal_bool _va2_vr_vp_6268_lcd_frame_done = KAL_TRUE;
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)

/****************************************************************************
 * External References
 ****************************************************************************/
extern kal_bool   _va2_comp_vr_have_config_lcd;
extern kal_uint32 _va2_comp_vr_triggered_lcd_id_this_time;

#define CCASSERT(predicate) _x_CCASSERT_LINE(predicate, __LINE__)
#define _x_CCASSERT_LINE(predicate, line) typedef char constraint_violated_on_line_##line[2*((predicate)!=0)-1];

#endif  // #if defined(__MTK_TARGET__)

/****************************************************************************
 * local function bodies
 ****************************************************************************/
#if defined(__MTK_TARGET__)

#if defined(DRV_DISPLAY_DRIVER_V2)
void _va2_vr_vp_6268_wfc_frame_done_cb(
  WFCContextEventTypeMTK event, 
  void* param)
{
    _va2_vr_vp_6268_lcd_frame_done_cb(param);
}
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)

static kal_bool
_va2_vr_vp_6268_is_hw_layer_setting_modified_by_VR(
  WFCRotation *layerRotation)
{
#if defined(DRV_DISPLAY_DRIVER_V2)
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
#endif
}

/**
 *  \remarks After this function, the rotation/flip of Video Renderer might be changed...
 */
static void 
_va2_vr_vp_6268_config_n_activate_ddv2( 
  va2_comp_video_renderer_cb_t *cb)
{
#if defined(DRV_DISPLAY_DRIVER_V2)
  kal_check_stack();

  // TODO: [m] Which variable can decide if display needs to work? 
  {
    WFCint displayInputWidth, displayInputHeight; // The output width/height of MM...
    WFCint layerRotateAngle;
    WFCRotation layerRotation;
    WFCint layerFlip;
    
    _va2_vr_vp_6268_ddv2_dev = (WFCDevice) cb->display_surface.dspl_dev_handle;
    _va2_vr_vp_6268_ddv2_ctx = (WFCContext) cb->display_surface.dspl_ctx_handle;
    _va2_vr_vp_6268_ddv2_element = (WFCElement) cb->display_surface.dspl_element_handle;

    if ((WFC_INVALID_HANDLE == _va2_vr_vp_6268_ddv2_dev) || 
        (WFC_INVALID_HANDLE == _va2_vr_vp_6268_ddv2_ctx) || 
        (WFC_INVALID_HANDLE == _va2_vr_vp_6268_ddv2_element))
    {
      VRNDRR_DD_ASSERT(0); // TODO: [m] remove this after IT done...need error handling...
    }

    // Check if this element is a video layer...for debug only and can be removed for last QC stage...
    if (WFC_FALSE == wfcGetElementAttribi(_va2_vr_vp_6268_ddv2_dev, _va2_vr_vp_6268_ddv2_element, WFC_ELEMENT_VIDEO_LAYER_MTK))
    {
      // TODO: [m] Make GDI add this line...
      wfcMMSetElementAttribi(_va2_vr_vp_6268_ddv2_dev, _va2_vr_vp_6268_ddv2_element, WFC_ELEMENT_VIDEO_LAYER_MTK, WFC_TRUE);
    }
    if (KAL_FALSE == cb->disable_dcmode)
    {
      __wfd_lcd_dc_engine = WFD_LCD_DC_ENGINE_IRT2;
      wfcMMSetElementAttribi(_va2_vr_vp_6268_ddv2_dev, _va2_vr_vp_6268_ddv2_element, WFC_ELEMENT_DC_LAYER_MTK, WFC_TRUE);
    }

    {
      wfcMMSetContextAttribi(_va2_vr_vp_6268_ddv2_dev, _va2_vr_vp_6268_ddv2_ctx, WFC_CONTEXT_AUTONOMOUS_SYNC_MODE_MTK, (WFCint) WFC_AUTONOMOUS_SYNC_TO_ELEMENT);
      wfcMMSetContextAttribi(_va2_vr_vp_6268_ddv2_dev, _va2_vr_vp_6268_ddv2_ctx, WFC_CONTEXT_AUTONOMOUS_PERIOD_MTK, (WFCint) 30);
      wfcMMSetContextAttribi(_va2_vr_vp_6268_ddv2_dev, _va2_vr_vp_6268_ddv2_ctx, WFC_CONTEXT_AUTONOMOUS_SYNC_ELEMENT_MTK, (WFCint) _va2_vr_vp_6268_ddv2_element);

      if (KAL_FALSE == cb->disable_dcmode)
      {
        wfcMMSetContextAttribi(_va2_vr_vp_6268_ddv2_dev, _va2_vr_vp_6268_ddv2_ctx, WFC_CONTEXT_CURRENT_REFRESH_RATE_MTK, 0);
      }
    }

    // Derive the output width/height of MDP, which might be the input width height of Display
    // Need to take rotation into consideration later...
    displayInputWidth = cb->dst_size.u4_width;
    displayInputHeight = cb->dst_size.u4_height;

    // Config Display Rotation angle & flip
    {
      WFCboolean layerFlip;

      layerRotation = (WFCRotation) 
        wfcGetElementAttribi(_va2_vr_vp_6268_ddv2_dev, _va2_vr_vp_6268_ddv2_element, WFC_ELEMENT_SOURCE_ROTATION);
      
      wfcMMSetElementAttribi(_va2_vr_vp_6268_ddv2_dev, _va2_vr_vp_6268_ddv2_element, WFC_ELEMENT_SOURCE_ROTATION, WFC_ROTATION_0);
    }

    #if defined (__MAIN_LCM_SCANLINE_ROTATION_0__)
    // do nothing
    #elif defined (__MAIN_LCM_SCANLINE_ROTATION_90__)
    if (cb->rotate_flip.u2_cw_rotate_angle >= 90)
    {cb->rotate_flip.u2_cw_rotate_angle -= 90;}
    else
    {cb->rotate_flip.u2_cw_rotate_angle = cb->rotate_flip.u2_cw_rotate_angle + 360 - 90;}
    #elif defined (__MAIN_LCM_SCANLINE_ROTATION_180__)
    if (cb->rotate_flip.u2_cw_rotate_angle >= 180)
    {cb->rotate_flip.u2_cw_rotate_angle -= 180;}
    else
    {cb->rotate_flip.u2_cw_rotate_angle = cb->rotate_flip.u2_cw_rotate_angle + 360 - 180;}
    #elif defined (__MAIN_LCM_SCANLINE_ROTATION_270__)
    if (cb->rotate_flip.u2_cw_rotate_angle >= 270)
    {cb->rotate_flip.u2_cw_rotate_angle -= 270;}
    else
    {cb->rotate_flip.u2_cw_rotate_angle = cb->rotate_flip.u2_cw_rotate_angle + 360 - 270;}
    #endif  

    if ((90 == cb->rotate_flip.u2_cw_rotate_angle) || 
        (270 == cb->rotate_flip.u2_cw_rotate_angle))
    {
      // Swap width and height if MDP rotate 90 or 270 degree...
      displayInputWidth ^= displayInputHeight;
      displayInputHeight ^= displayInputWidth;
      displayInputWidth ^= displayInputHeight;

      // Frame buffer is actually rotated
      cb->dst_fb_size.u4_height ^= cb->dst_fb_size.u4_width;
      cb->dst_fb_size.u4_width ^= cb->dst_fb_size.u4_height;
      cb->dst_fb_size.u4_height ^= cb->dst_fb_size.u4_width;
    }
    
    // Config Display Source width/height (The output of MDP) and source clip/pitch
    {
      WFCint srcRect[4];
      WFCint ClipX, ClipY, Width, Height;
      if (KAL_FALSE == _va2_vr_vp_6268_is_hw_layer_setting_modified_by_VR(&layerRotation))
      {
        wfcGetElementAttribiv(_va2_vr_vp_6268_ddv2_dev, _va2_vr_vp_6268_ddv2_element, WFC_ELEMENT_SOURCE_RECTANGLE, 4, &srcRect[0]);

        if (90 == cb->rotate_flip.u2_cw_rotate_angle)
        {
          ClipX = displayInputWidth - srcRect[1] - srcRect[3];
          ClipY = srcRect[0];
          Width = srcRect[3];
          Height = srcRect[2];
        }
        else if (270 == cb->rotate_flip.u2_cw_rotate_angle)
        {
          ClipX = srcRect[1];
          ClipY = displayInputHeight - srcRect[0] - srcRect[2];
          Width = srcRect[3];
          Height = srcRect[2];
        }
        else if (180 == cb->rotate_flip.u2_cw_rotate_angle)
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
        wfcMMSetElementAttribiv(_va2_vr_vp_6268_ddv2_dev, _va2_vr_vp_6268_ddv2_element, WFC_ELEMENT_SOURCE_RECTANGLE, 4, &srcRect[0]);
      }
      else
      {
        cb->bypass_hw_layer_src_rect = KAL_FALSE;
      }
  }

  // Create stream...
  {
    OWFNativeStreamType stream;
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

    if (KAL_FALSE == cb->disable_dcmode)
    {
      imageFormat.pixelFormat = OWF_IMAGE_ARGB8888;
    }
    _va2_vr_vp_6268_dspl_fbs[0][0] = bufs[0] = cb->dst_fb_addr_array[2].u4_fb_addr_plane0;
    _va2_vr_vp_6268_dspl_fbs[1][0] = bufs[1] = cb->dst_fb_addr_array[1].u4_fb_addr_plane0;
      // TODO: [m] When to destroy the stream? Where is the exit function?
      // TODO: [o] magical number here...
    _va2_vr_vp_6268_ddv2_stream = 
      owfNativeStreamCreateImageStreamEx((OWFint) displayInputWidth, 
                                         (OWFint) displayInputHeight, 
                                         &imageFormat, (OWFint) 2, (void**) &bufs[0]);

    // This code segment is used to do buffer control...
    {
      void * bufPtr;
      OWFNativeStreamBuffer buf;

      buf = owfNativeStreamAcquireWriteBuffer(_va2_vr_vp_6268_ddv2_stream);
      bufPtr = owfNativeStreamGetBufferPtr(_va2_vr_vp_6268_ddv2_stream, buf);
      VRNDRR_DD_ASSERT(NULL != bufPtr);

      if (_va2_vr_vp_6268_dspl_fbs[0][0] == (kal_uint32) bufPtr)
      {
        _va2_vr_vp_6268_dspl_fbs[0][1] = (kal_uint32) buf;
        _va2_vr_vp_6268_dspl_fbs[1][1] = owfNativeStreamAcquireWriteBuffer(_va2_vr_vp_6268_ddv2_stream);
      }
      else
      {
        _va2_vr_vp_6268_dspl_fbs[1][1] = (kal_uint32) buf;
        _va2_vr_vp_6268_dspl_fbs[0][1] = owfNativeStreamAcquireWriteBuffer(_va2_vr_vp_6268_ddv2_stream);
      }
    }

    _va2_vr_vp_6268_ddv2_src = wfcCreateSourceFromStream(_va2_vr_vp_6268_ddv2_dev, _va2_vr_vp_6268_ddv2_ctx, (WFCNativeStreamType) _va2_vr_vp_6268_ddv2_stream, NULL);
    // TODO: [m] Need an API to set buffers into the stream...

    if (WFC_INVALID_HANDLE == _va2_vr_vp_6268_ddv2_src)
    {
      VRNDRR_DD_ASSERT(0); // TODO: [m] remove this after IT done...need error handling...
    }
  }

  // Set Element source
  wfcMMSetElementAttribi(_va2_vr_vp_6268_ddv2_dev, _va2_vr_vp_6268_ddv2_element, WFC_ELEMENT_SOURCE, (WFCint) _va2_vr_vp_6268_ddv2_src);

  // TODO: [m] If camera preview only uses double display frame buffer, DDv2 needs to sync to content provider...since camera cannot wait...

  // Add cb function
  {
    WFCint array[4];
    if (KAL_FALSE == cb->disable_dcmode)
    {
      array[0] = (WFCint) WFC_CONTEXT_EVENT_COMPOSITION_FINISH_MTK;
    }
    else
    {
      array[0] = (WFCint) WFC_CONTEXT_EVENT_COMPOSITION_FINISH_ALWAYS_CALLBACK_MTK;
    }
      array[1] = (WFCint) _va2_vr_vp_6268_wfc_frame_done_cb;
      array[2] = (WFCint) cb;
      array[3] = (WFCint) WFC_TRUE;
      wfcMMSetContextAttribiv(_va2_vr_vp_6268_ddv2_dev, _va2_vr_vp_6268_ddv2_ctx, WFC_CONTEXT_CALLBACK_MTK, 4, &array[0]);
    }

    // Commmit
    wfcMMCommit(_va2_vr_vp_6268_ddv2_dev, _va2_vr_vp_6268_ddv2_ctx, _va2_vr_vp_6268_ddv2_element,WFC_COMMIT_CONTEXT_AND_ELEMENT);
    if (VIDEO_RENDERER_RENDER_MODE_TOUCH_WINDOW_FROM_INSIDE == cb->render_mode)
    {
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
          if (0x0 != (addr = cb->dst_fb_addr_array[2].u4_fb_addr_plane0))
          {
           kal_mem_set((void*) addr, 0x0, size);  //black for RGB565
          }
        }
      }
    }
  }
  kal_check_stack();
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)
}

static void 
_va2_vr_vp_6268_stop_n_deactivate_ddv2( 
  va2_comp_video_renderer_cb_t *cb)
{
#if defined(DRV_DISPLAY_DRIVER_V2)
  //Add by Michael, avoid Element removed and no body Insert Element Correct Value.
  WFCint displayInputWidth, displayInputHeight; // The output width/height of MM...
  WFCRotation layerRotation = WFC_ROTATION_0;
  WFCboolean layerFlip;

  kal_check_stack();
  // TODO: [m] Which variable can decide if display needs to work? 
  if (OWF_INVALID_HANDLE != _va2_vr_vp_6268_ddv2_stream)
  {
    if ((WFC_INVALID_HANDLE == _va2_vr_vp_6268_ddv2_dev) || 
        (WFC_INVALID_HANDLE == _va2_vr_vp_6268_ddv2_ctx) || 
        (WFC_INVALID_HANDLE == _va2_vr_vp_6268_ddv2_element))
    {
      VRNDRR_DD_ASSERT(0);
    }

    // check the last frame has been flash out
    // TODO: [optional] Move this to the top most of this function...
    if (KAL_FALSE == cb->disable_dcmode)
    {
      wfcMMSetElementAttribi(_va2_vr_vp_6268_ddv2_dev, _va2_vr_vp_6268_ddv2_element, WFC_ELEMENT_DC_LAYER_MTK, WFC_FALSE);
    }
    else
    {
      while(_va2_vr_vp_6268_lcd_frame_done == KAL_FALSE)
      {
        kal_sleep_task(1);
      }
    }

    // Remove cb function
    {
      WFCint array[4];
      if (KAL_FALSE == cb->disable_dcmode)
      {
        array[0] = (WFCint) WFC_CONTEXT_EVENT_COMPOSITION_FINISH_MTK;
      }
      else
      {
        array[0] = (WFCint) WFC_CONTEXT_EVENT_COMPOSITION_FINISH_ALWAYS_CALLBACK_MTK;
      }
      array[1] = (WFCint) _va2_vr_vp_6268_wfc_frame_done_cb;
      array[2] = (WFCint) cb;
      array[3] = (WFCint) WFC_FALSE;
      wfcMMSetContextAttribiv(_va2_vr_vp_6268_ddv2_dev, _va2_vr_vp_6268_ddv2_ctx, WFC_CONTEXT_CALLBACK_MTK, 4, &array[0]);
    }
    wfcMMSetElementAttribi(_va2_vr_vp_6268_ddv2_dev, _va2_vr_vp_6268_ddv2_element, WFC_ELEMENT_SOURCE, WFC_INVALID_HANDLE);

    {
      wfcMMSetContextAttribi(_va2_vr_vp_6268_ddv2_dev, _va2_vr_vp_6268_ddv2_ctx, WFC_CONTEXT_AUTONOMOUS_SYNC_MODE_MTK, (WFCint) WFC_AUTONOMOUS_SYNC_TO_TIMER);
      wfcMMSetContextAttribi(_va2_vr_vp_6268_ddv2_dev, _va2_vr_vp_6268_ddv2_ctx, WFC_CONTEXT_AUTONOMOUS_PERIOD_MTK, (WFCint) 0);
      wfcMMSetContextAttribi(_va2_vr_vp_6268_ddv2_dev, _va2_vr_vp_6268_ddv2_ctx, WFC_CONTEXT_AUTONOMOUS_SYNC_ELEMENT_MTK, (WFCint) 0);
      wfcMMSetContextAttribi(_va2_vr_vp_6268_ddv2_dev, _va2_vr_vp_6268_ddv2_ctx, WFC_CONTEXT_CURRENT_REFRESH_RATE_MTK, 30);
    }
    // Set an image source back to element
    {
      OWF_IMAGE image;
      OWF_PIXEL_FORMAT color_format = OWF_IMAGE_NOT_SUPPORTED;
      WFCint pixel_size = 0;
      // TODO: Add an image sourece
      if (_va2_vr_vp_6268_ddv2_img_src != WFC_INVALID_HANDLE)
      {
        wfcDestroySource(_va2_vr_vp_6268_ddv2_dev, _va2_vr_vp_6268_ddv2_img_src);
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
          va2_vr_add_trace(&_va2_vr_vp_6268_debug_trace[0], VA2_VR_DEBUG_______NO_VIDEO_FRAME_TO_DRAW, 0);
          image.data = (void*) cb->dst_fb_addr_array[0].u4_fb_addr_plane0;
        }
        else
        {
          kal_bool trigger_display=KAL_FALSE;
          save_irq_mask = SaveAndSetIRQMask();
          if((KAL_FALSE == cb->keep_curr_ptr_when_run) || (NULL == cb->vr_q_handle.curr_dspl_buf_hdr))
          {
            // If only one frame is inserted in Run state, this action is to emulate 
            // the processing of the previous Bypass-Mode Frames.
            va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
          }
          trigger_display = cb->trigger_display;
          RestoreIRQMask(save_irq_mask);

          // Try to guarantee the index is 0 before get buffer...
          //_va2_vr_render_display_buffer_cnt = 0;
          cb->trigger_display = KAL_FALSE;
          image.data = (void*) _va2_vr_vp_6268_render_display_frame_buffer(cb, KAL_TRUE);
          cb->trigger_display = trigger_display;
         
          if ((kal_uint32)image.data != cb->dst_fb_addr_array[0].u4_fb_addr_plane0)
          {image.data = (void*) cb->dst_fb_addr_array[0].u4_fb_addr_plane0;}
        }
      }
          
      // TODO: buffer address refer to CalDisplayFBs[?][1] == 0x0
      // TODO: fill in this structure 
      // find the image buffer by last rendered frame
      image.data = (void*) cb->dst_fb_addr_array[0].u4_fb_addr_plane0;
      {
        image.width = cb->dst_fb_size.u4_width;
        image.height = cb->dst_fb_size.u4_height;
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
  
      _va2_vr_vp_6268_ddv2_img_src = wfcCreateSourceFromImage(_va2_vr_vp_6268_ddv2_dev, _va2_vr_vp_6268_ddv2_ctx, (WFCHandle) &image, NULL);
      VRNDRR_DD_ASSERT(_va2_vr_vp_6268_ddv2_img_src != WFC_INVALID_HANDLE);
      wfcMMSetElementAttribi(_va2_vr_vp_6268_ddv2_dev, _va2_vr_vp_6268_ddv2_element, WFC_ELEMENT_SOURCE, _va2_vr_vp_6268_ddv2_img_src);
      wfcMMCommit(_va2_vr_vp_6268_ddv2_dev, _va2_vr_vp_6268_ddv2_ctx, _va2_vr_vp_6268_ddv2_element, WFC_COMMIT_CONTEXT_AND_ELEMENT);
    }

    wfcDestroySource(_va2_vr_vp_6268_ddv2_dev, _va2_vr_vp_6268_ddv2_src);
    _va2_vr_vp_6268_ddv2_src = WFC_INVALID_HANDLE;

    _va2_vr_vp_6268_ddv2_element = WFC_INVALID_HANDLE;
    _va2_vr_vp_6268_ddv2_ctx = WFC_INVALID_HANDLE;
    _va2_vr_vp_6268_ddv2_dev = WFC_INVALID_HANDLE;
    
    owfNativeStreamDestroy(_va2_vr_vp_6268_ddv2_stream);
    _va2_vr_vp_6268_ddv2_stream = OWF_INVALID_HANDLE;

    kal_mem_set((void*) _va2_vr_vp_6268_dspl_fbs, 0x0, sizeof(kal_uint32)*3*2);
  }
  kal_check_stack();
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)
}

static kal_bool
_va2_vr_vp_6268_trigger_display(
  kal_uint32 dspl_fb, 
  va2_comp_video_renderer_cb_t *cb)
{
#if defined(DRV_DISPLAY_DRIVER_V2)
  if ((KAL_TRUE == cb->trigger_display) && 
      (OWF_INVALID_HANDLE != _va2_vr_vp_6268_ddv2_stream))
  {
    OWFNativeStreamBuffer buf;
    if (dspl_fb == _va2_vr_vp_6268_dspl_fbs[0][0])
    {
      buf = (OWFNativeStreamBuffer) _va2_vr_vp_6268_dspl_fbs[0][1];
      if (buf==0)
      {
        return KAL_FALSE;
      }
      {
        kal_uint32 const saved_mask = SaveAndSetIRQMask();
        _va2_vr_vp_6268_lcd_frame_done = KAL_FALSE;
        RestoreIRQMask(saved_mask);
      }
      owfNativeStreamReleaseWriteBuffer(_va2_vr_vp_6268_ddv2_stream, 
                                      buf/* (OWFNativeStreamBuffer) 0x100 */, 
                                      NULL /* (EGLDisplay) */, 
                                      NULL /* (EGLSyncKHR) */);
      _va2_vr_vp_6268_dspl_fbs[0][1] = 0x0;
      if (0x0 == _va2_vr_vp_6268_dspl_fbs[1][1])
      {
        _va2_vr_vp_6268_dspl_fbs[1][1] = (kal_uint32) owfNativeStreamAcquireWriteBuffer(_va2_vr_vp_6268_ddv2_stream);
      }
    }
    else
    {
      buf = (OWFNativeStreamBuffer) _va2_vr_vp_6268_dspl_fbs[1][1];
      if (buf==0)
      {
        return KAL_FALSE;
      }
      {
        kal_uint32 const saved_mask = SaveAndSetIRQMask();
        _va2_vr_vp_6268_lcd_frame_done = KAL_FALSE;
        RestoreIRQMask(saved_mask);
      }
      owfNativeStreamReleaseWriteBuffer(_va2_vr_vp_6268_ddv2_stream, 
                                      buf/* (OWFNativeStreamBuffer) 0x100 */, 
                                      NULL /* (EGLDisplay) */, 
                                      NULL /* (EGLSyncKHR) */);

      _va2_vr_vp_6268_dspl_fbs[1][1] = 0x0;
      if (0x0 == _va2_vr_vp_6268_dspl_fbs[0][1])
      {
        _va2_vr_vp_6268_dspl_fbs[0][1] = (kal_uint32) owfNativeStreamAcquireWriteBuffer(_va2_vr_vp_6268_ddv2_stream);
      }
    }
    return KAL_TRUE;
  }
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)
}

/**
 *  @status OK
 *  @common VR.VP
 */
static kal_bool
_va2_vr_vp_6268_check_params_configs(
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
         //michael add for reject small video WH
         (cb->src_clip.u4_clip_bottom < 6) ||
         (cb->src_clip.u4_clip_right < 6))
    {
      fgRet = KAL_FALSE;
    }
  }
  
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

  return fgRet;
}

static void
src_clip_2_dst_clip_hori(img_rot_angle_enum_t const rot_angle,
                         kal_uint32 const src_width,
                         kal_uint32 const tar_width,
                         kal_uint32 const src_x1,
                         kal_uint32 const src_x2,
                         kal_uint32 * const dst_x1,
                         kal_uint32 * const dst_x2)
{
  if (NULL == dst_x1)
  {
    ASSERT(0);
  }
  if (NULL == dst_x2)
  {
    ASSERT(0);
  }

  {
    kal_uint32 const tar_x1 = ((src_x1 * tar_width) / src_width);
    // [MAUI_01207646]
    kal_uint32 const tar_x2 = (((src_x2 + 1) * tar_width) / src_width) - 1;

    (*dst_x1) = tar_x1;
    (*dst_x2) = tar_x2;
  }
}

static void
src_clip_2_dst_clip_vert(img_rot_angle_enum_t const rot_angle,
                         kal_uint32 const src_height,
                         kal_uint32 const tar_height,
                         kal_uint32 const src_y1,
                         kal_uint32 const src_y2,
                         kal_uint32 * const dst_y1,
                         kal_uint32 * const dst_y2)
{
  if (NULL == dst_y1)
  {
    ASSERT(0);
  }
  if (NULL == dst_y2)
  {
    ASSERT(0);
  }

  {
    kal_uint32 const tar_y1 = ((src_y1 * tar_height) / src_height);
    // [MAUI_01207646]
    kal_uint32 const tar_y2 = (((src_y2 + 1) * tar_height) / src_height) - 1;

    (*dst_y1) = tar_y1;
    (*dst_y2) = tar_y2;
  }
}


/**
 *  @status OK
 *  @common none
 */
static kal_bool
va2_vr_vp_6268_src_clip_to_dst_clip_convert(
  va2_comp_video_renderer_cb_t *cb,
  VA2_6268_RENDERER_CLIP_CONVERT_T *prRender_Convert)
{
  kal_uint32 dst_clip_x1;
  kal_uint32 dst_clip_x2;
  kal_uint32 dst_clip_y1;
  kal_uint32 dst_clip_y2;
  kal_uint32 video_src_width_with_dummy, video_src_height_with_dummy;
  kal_uint32 video_target_width_with_dummy, video_target_height_with_dummy;
  kal_uint32 video_target_width_wo_dummy, video_target_height_wo_dummy;
  kal_uint32 real_video_display_width; /* The display target width after rotation */
  kal_uint32 real_video_display_height; /* The display target height after rotation */
  kal_uint32 real_video_clip_left; /* the clip_left after resizing and rotation. */
  kal_uint32 real_video_clip_right; /* the clip_right after resizing and rotation. */
  kal_uint32 real_video_clip_top; /* the clip_top after resizing and rotation. */
  kal_uint32 real_video_clip_bottom; /* the clip_bottom after resizing and rotation. */

  kal_uint32 const src_clip_width = cb->src_clip.u4_clip_right - cb->src_clip.u4_clip_left + 1;
  kal_uint32 const src_clip_height= cb->src_clip.u4_clip_bottom - cb->src_clip.u4_clip_top + 1;

  video_src_width_with_dummy  = cb->src_size.u4_width;
  video_src_height_with_dummy = cb->src_size.u4_height;
  video_target_width_wo_dummy = cb->dst_size.u4_width;
  video_target_height_wo_dummy = cb->dst_size.u4_height;

  // [MAUI_01245490]
  video_target_width_with_dummy = (((kal_uint32)(video_target_width_wo_dummy) *
                                    (kal_uint32)(video_src_width_with_dummy) +
                                    (kal_uint32)(src_clip_width) - 1) /
                                   (kal_uint32)(src_clip_width));
  video_target_height_with_dummy = (((kal_uint32)(video_target_height_wo_dummy) *
                                     (kal_uint32)(video_src_height_with_dummy) +
                                     (kal_uint32)(src_clip_height) - 1) /
                                    (kal_uint32)(src_clip_height));

  for (;;)
  {
    src_clip_2_dst_clip_hori(cb->rotate_flip.u2_cw_rotate_angle,
                             video_src_width_with_dummy,
                             video_target_width_with_dummy,
                             cb->src_clip.u4_clip_left,
                             cb->src_clip.u4_clip_right,
                             &dst_clip_x1,
                             &dst_clip_x2);

    if ((dst_clip_x2 - dst_clip_x1 + 1) < video_target_width_wo_dummy)
    {
      ++video_target_width_with_dummy;
      continue;
    }
    else if ((dst_clip_x2 - dst_clip_x1 + 1) > video_target_width_wo_dummy)
    {
      dst_clip_x2 = (dst_clip_x1 + video_target_width_wo_dummy - 1);
      break;
    }
    else
    {
      break;
    }
  }

  for (;;)
  {
    src_clip_2_dst_clip_vert(cb->rotate_flip.u2_cw_rotate_angle,
                             video_src_height_with_dummy,
                             video_target_height_with_dummy,
                             cb->src_clip.u4_clip_top,
                             cb->src_clip.u4_clip_bottom,
                             &dst_clip_y1,
                             &dst_clip_y2);

    if ((dst_clip_y2 - dst_clip_y1 + 1) < video_target_height_wo_dummy)
    {
      ++video_target_height_with_dummy;
      continue;
    }
    else if ((dst_clip_y2 - dst_clip_y1 + 1) > video_target_height_wo_dummy)
    {
      dst_clip_y2 = (dst_clip_y1 + video_target_height_wo_dummy - 1);
      break;
    }
    else
    {
      break;
    }
  }

  real_video_display_width = video_target_width_with_dummy;
  real_video_display_height = video_target_height_with_dummy;
  real_video_clip_left = dst_clip_x1;
  real_video_clip_right = dst_clip_x2;
  real_video_clip_top = dst_clip_y1;
  real_video_clip_bottom = dst_clip_y2;

  (*prRender_Convert).clip_conv_disp_width  = real_video_display_width;
  (*prRender_Convert).clip_conv_disp_height = real_video_display_height;
  (*prRender_Convert).clip_conv_clip_left   = real_video_clip_left;
  (*prRender_Convert).clip_conv_clip_right  = real_video_clip_right;
  (*prRender_Convert).clip_conv_clip_top    = real_video_clip_top;
  (*prRender_Convert).clip_conv_clip_bottom = real_video_clip_bottom;
}  // end of va2_vr_vp_6268_src_clip_to_dst_clip_convert


/**
 *  @status OK
 *  @common none
 */
static kal_bool
_va2_vr_vp_6268_config_idp_by_render_mode(
  va2_comp_video_renderer_cb_t *cb,
  VA2_VIDEO_FRAME_T *video_frame)
{
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

    // compute max. dst_size smaller than dst_fb_size to keep src_size ratio...
    {
      kal_uint32 h_ratio = (cb->dst_size.u4_width<<16)/src_clip_w;
      kal_uint32 v_ratio = (cb->dst_size.u4_height<<16)/src_clip_h;
      kal_uint32 temp;
      if (h_ratio < v_ratio)
      {
        // dst_w needs not to be changed...
        //cb->dst_size.u4_height = (h_ratio*src_clip_h)>>16;
       temp = cb->dst_size.u4_height;
       cb->dst_size.u4_height = ((((h_ratio*src_clip_h)>>16)+1)>>1)<<1;
       if (temp < cb->dst_size.u4_height) {cb->dst_size.u4_height = temp;}
       if (cb->dst_size.u4_height == 0) {cb->dst_size.u4_height = 2;}
      }
      else
      {
        // dst_h needs not to be changed...
        //cb->dst_size.u4_width = (v_ratio*src_clip_w)>>16;
        temp = cb->dst_size.u4_width;
        cb->dst_size.u4_width = ((((v_ratio*src_clip_w)>>16)+1)>>1)<<1;
        if (temp < cb->dst_size.u4_width) {cb->dst_size.u4_width = temp;}
        if (cb->dst_size.u4_width == 0) {cb->dst_size.u4_width = 2;}
      }
    }
  }
  else if (VIDEO_RENDERER_RENDER_MODE_TOUCH_WINDOW_FROM_OUTSIDE == cb->render_mode)
  {
    kal_uint32 src_clip_w, src_clip_h;

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
      kal_uint32 h_ratio = (cb->dst_size.u4_width<<16)/src_clip_w;
      kal_uint32 v_ratio = (cb->dst_size.u4_height<<16)/src_clip_h;
      if (h_ratio > v_ratio)
      {
        // dst_w needs not to be changed...
        cb->dst_size.u4_height = (h_ratio*src_clip_h)>>16;
      }
      else
      {
        // dst_h needs not to be changed...
        cb->dst_size.u4_width = (v_ratio*src_clip_w)>>16;
      }
    }

    // calculate dst clipping window to fit dst_fb_size...
    if ((cb->dst_size.u4_width == cb->dst_fb_size.u4_width) &&
        (cb->dst_size.u4_height == cb->dst_fb_size.u4_height))
    {
      cb->dst_clip.b_clip_enable = KAL_FALSE;
    }
    else
    {
      cb->dst_clip.b_clip_enable = KAL_TRUE;
      if (cb->dst_size.u4_width > cb->dst_fb_size.u4_width)
      {
        cb->dst_clip.u4_clip_left = (cb->dst_fb_size.u4_width-cb->dst_size.u4_width)>>1;
        cb->dst_clip.u4_clip_right = cb->dst_clip.u4_clip_left + cb->dst_fb_size.u4_width - 1;
      }
      else if (cb->dst_size.u4_height > cb->dst_fb_size.u4_height)
      {
        cb->dst_clip.u4_clip_top = (cb->dst_fb_size.u4_height-cb->dst_size.u4_height)>>1;
        cb->dst_clip.u4_clip_bottom = cb->dst_clip.u4_clip_top + cb->dst_fb_size.u4_height - 1;
      }
      else
      {
        ASSERT(0);
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
  return KAL_TRUE;
}

/**
 *  @todo OK
 *  @common VR.VP
 */
static void
_va2_vr_vp_6268_display_timer_hdlr(
  void *param)
{
  kal_bool idp_busy;
  kal_uint32 save_irq_mask;
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6268_cb;

  if ((va2_comp_video_renderer_cb_t*) param != cb)
  {
    ASSERT(0); // incorrect timer handler param
  }

  if(VIDEO_STATE_RUN != cb->state.eState)
  {
    return;
  }

  if(KAL_TRUE == va2_util_check_bypass_redraw(cb))
  {
    return;
  }

  #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)
    SLA_CustomLogging("TM0", 1);
  #endif  // #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)

  save_irq_mask = SaveAndSetIRQMask();
  if (NULL == cb->vr_q_handle.curr_dspl_buf_hdr)
  {
    va2_vr_add_trace(_va2_vr_vp_6268_debug_trace, VA2_VR_INTERNAL____DSPL_TIMER_ASSERT, 0);
    // TODO: Note this! we remove this assertion due to this is not necessary from decoder and application's point of view!
    //ASSERT(0); // Until 5 sec time-out, no updates from former stage or IL client.
    RestoreIRQMask(save_irq_mask);

    #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)
      SLA_CustomLogging("TM0", 0);
    #endif  // #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)

    return;
  }
  RestoreIRQMask(save_irq_mask);

  if (KAL_TRUE == cb->bypass)
  {
    // If times out in bypass mode, do nothing...especially not to trigger IDP...
    // And actually we don't care about if no consequent buffer comes or not!!
    return;
  }

  va2_vr_add_trace(_va2_vr_vp_6268_debug_trace, VA2_VR_INTERNAL____DSPL_TIMER_TIMEOUT, 0);
  visual_active_hisr(VISUAL_RENDERER_TIMER_HISR_ID);
}


/**
 *  @status OK
 *  @remark callback in HISR...VISUAL HISR to be specific...
 *  @common VR.VP
 */
static kal_bool
_va2_vr_vp_6268_idp_frame_done_cb(void *param)
{
  va2_comp_video_renderer_cb_t *cb = (va2_comp_video_renderer_cb_t*) param;
  va2_util_buf_hdr_q_item_t *item = cb->vr_q_handle.curr_dspl_buf_hdr;
  kal_bool hw_busy = KAL_FALSE;
  kal_uint32 u4Tmp1, u4Tmp2;
  kal_uint32 *pu4Tmp;

  ASSERT(NULL != cb);

  if(VIDEO_STATE_RUN != cb->state.eState)
  {
      // TODO: Encode's last frame will be triggered!!
      // TODO: Use dst_fb_addr_array to tigger because dst_fb_start_array will do pitch's offset.
    if (KAL_FALSE== cb->disable_dcmode)
    {
#if defined(DRV_DISPLAY_DRIVER_V2)
      {   
      kal_uint32 iIndex = ((_va2_vr_render_display_buffer_cnt&0x1)^0x1);
      return _va2_vr_vp_6268_trigger_display(
        //cb->dst_fb_start_addr_array[iIndex+1].u4_fb_addr_plane0, 
        cb->dst_fb_addr_array[iIndex+1].u4_fb_addr_plane0, 
        cb);
      }
#endif
      }
    return;
  }

  #if defined(VA2_VR_VP_6268_ENABLE_SWLA_TRACE)
    SLA_CustomLogging("RFD", 1);
  #endif  // #if defined(VA2_VR_VP_6268_ENABLE_SWLA_TRACE)

  if (KAL_TRUE == cb->bypass)
  {
    // Unexpected: FrameDone occurs unders bypass mode.
    // Bypass mode should only be switched under Stop state, and render should only execute under Run state.
    // At last, FrameDone will not be processed except under Run state. There it is.
    ASSERT(0);
  }

  va2_vr_add_trace(_va2_vr_vp_6268_debug_trace, VA2_VR_INTERNAL____MDP_HW_FRAME_DONE_CB, 0);


  // if buffer header received while MDP doing a frame, use the latest frame buffer for the next update...
  if (0 != cb->vr_q_handle.to_be_processed_q.size)
  {
    va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
  }

  // try to return all buffers...
  cb->funcs.try_to_return_buf_hdrs(cb);

  // Trigger display 
  #if defined(VA2_VR_VP_6268_ENABLE_SWLA_TRACE)
    SLA_CustomLogging("RFD", 0);
  #endif  // #if defined(VA2_VR_VP_6268_ENABLE_SWLA_TRACE)
#if defined(DRV_DISPLAY_DRIVER_V2)
  {   
    kal_uint32 iIndex = ((_va2_vr_render_display_buffer_cnt&0x1)^0x1);
    return _va2_vr_vp_6268_trigger_display(
    cb->dst_fb_addr_array[iIndex+1].u4_fb_addr_plane0, 
    cb);
  }
#endif

  ASSERT(KAL_TRUE == idp_video_decode_is_busy(_va2_comp_video_renderer_idp_key, &hw_busy));

  if((KAL_FALSE == hw_busy) && (item != cb->vr_q_handle.curr_dspl_buf_hdr))
  {
    va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
    va2_vr_add_trace(_va2_vr_vp_6268_debug_trace, VA2_VR_INTERNAL____MDP_HW_FRAME_DONE_CB__TRIGGER_HW, (kal_uint32) (cb->vr_q_handle.curr_dspl_buf_hdr));
    _va2_vr_vp_6268_render_display_frame_buffer(cb, KAL_FALSE);
    va2_vr_add_trace(_va2_vr_vp_6268_debug_trace, VA2_VR_INTERNAL____MDP_HW_FRAME_DONE_CB__TRIGGER_HW_DONE, 0);
  }

}

static void _va2_vr_vp_6268_lcd_frame_done_cb(void *param)
{
  va2_comp_video_renderer_cb_t *cb = (va2_comp_video_renderer_cb_t*) param;
  va2_util_buf_hdr_q_item_t *item = cb->vr_q_handle.curr_dspl_buf_hdr;
  kal_bool hw_busy = KAL_FALSE;
  kal_uint32 const saved_mask = SaveAndSetIRQMask();
  _va2_vr_vp_6268_lcd_frame_done = KAL_TRUE;
  RestoreIRQMask(saved_mask);

  ASSERT(NULL != cb);

  if(VIDEO_STATE_RUN != cb->state.eState)
  {
    return;
  }

  if (KAL_TRUE == cb->bypass)
  {
    // Unexpected: FrameDone occurs unders bypass mode.
    // Bypass mode should only be switched under Stop state, and render should only execute under Run state.
    // At last, FrameDone will not be processed except under Run state. There it is.
    ASSERT(0);
  }

  va2_vr_add_trace(_va2_vr_vp_6268_debug_trace, VA2_VR_INTERNAL____LCD_HW_FRAME_DONE_CB, 0);

  // if buffer header received while LCD doing a frame, use the latest frame buffer for the next update...
  if (0 != cb->vr_q_handle.to_be_processed_q.size)
  {
    va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
  }

  // try to return all buffers...
  cb->funcs.try_to_return_buf_hdrs(cb);

  ASSERT(KAL_TRUE == idp_video_decode_is_busy(_va2_comp_video_renderer_idp_key, &hw_busy));

  if((KAL_FALSE == hw_busy) && (item != cb->vr_q_handle.curr_dspl_buf_hdr))
  {
    va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
    va2_vr_add_trace(_va2_vr_vp_6268_debug_trace, VA2_VR_INTERNAL____LCD_HW_FRAME_DONE_CB__TRIGGER_HW, (kal_uint32) (cb->vr_q_handle.curr_dspl_buf_hdr->buffer_header.pu1Buffer));
    _va2_vr_vp_6268_render_display_frame_buffer(cb, KAL_FALSE);
    va2_vr_add_trace(_va2_vr_vp_6268_debug_trace, VA2_VR_INTERNAL____LCD_HW_FRAME_DONE_CB__TRIGGER_HW_DONE, 0);
  }
}


/**
 *  @return kal_uint32 the address to destination frame buffer if blocking is set to KAL_TRUE, 0 if blocking is set to KAL_FALSE.
 *  @status OK
 *  @todo post processing parameters...current MED just set some garbage down...
 *  @common VR.VP, VR.VT
 */
static kal_uint32
_va2_vr_vp_6268_render_display_frame_buffer(
  va2_comp_video_renderer_cb_t *cb,
  kal_bool blocking)
{
  VA2_VIDEO_FRAME_T *video_frame;
  va2_util_buf_hdr_q_item_t *curr_dspl_buf_hdr;
  VA2_6268_RENDERER_CLIP_CONVERT_T rRender_Convert;
  OWFNativeStreamBuffer buf;
  kal_uint32 dspl_fb;
  kal_uint32 dc_dst_width,dc_dst_heigth;
  
  if (NULL == cb)
  {
    ASSERT(0); // incorrect param
  }

  if (NULL == cb->vr_q_handle.curr_dspl_buf_hdr)
  {
    return VIDEO_ERROR_INPUT_PARAM_ERROR;
  }

  curr_dspl_buf_hdr = cb->vr_q_handle.curr_dspl_buf_hdr;
  va2_vr_add_trace(_va2_vr_vp_6268_debug_trace, VA2_VR_INTERNAL____RENDER, (kal_uint32) curr_dspl_buf_hdr);

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

  // get frame data...
  video_frame = (VA2_VIDEO_FRAME_T*) curr_dspl_buf_hdr->buffer_header.pPrivateData;
  ASSERT(NULL != video_frame);
  kal_mem_cpy(&(cb->src_size), &(video_frame->r_fb_size), sizeof(VA2_FRAME_SIZE_T));
  kal_mem_cpy(&(cb->src_clip), &(video_frame->r_clip_window), sizeof(VA2_CLIP_WINDOW_T));
  kal_mem_cpy(&(cb->src_fb_addr), &(video_frame->r_fb_addr), sizeof(VA2_FRAME_BUFFER_ADDRESS_T));

  //  5.1. config MDP driver [OK]
  {
    kal_bool result;
    kal_uint32 bg_image_width;
    kal_bool (*ptr_FrmDoneCBFunc)(void *) = NULL;

    if(KAL_FALSE == blocking)
    {
      ptr_FrmDoneCBFunc = _va2_vr_vp_6268_idp_frame_done_cb;
    }

    dc_dst_width = cb->dst_fb_size.u4_width;
    dc_dst_heigth = cb->dst_fb_size.u4_height;
    bg_image_width = cb->dst_fb_size.u4_width;
    _va2_vr_vp_6268_config_idp_by_render_mode(cb, video_frame);

    // check all parameters and configs for triggering HW
    if (KAL_FALSE == _va2_vr_vp_6268_check_params_configs(cb))
    {
      if (KAL_FALSE == blocking)
      {
        va2_vr_notify_error_to_client(cb);
      }
      return VIDEO_ERROR_INPUT_PARAM_ERROR;
    }


    va2_vr_vp_6268_src_clip_to_dst_clip_convert(cb, &rRender_Convert);

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
        src_clip_w = rRender_Convert.clip_conv_clip_right - rRender_Convert.clip_conv_clip_left + 1;
        src_clip_h = rRender_Convert.clip_conv_clip_bottom - rRender_Convert.clip_conv_clip_top + 1;
      }
      else
      {
        src_clip_w = cb->src_size.u4_width;
        src_clip_h = cb->src_size.u4_height;
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
          //cb->dst_size.u4_height = (h_ratio*src_clip_h)>>16;
          temp = cb->dst_size.u4_height;
          cb->dst_size.u4_height = ((((h_ratio*src_clip_h)>>16)+1)>>1)<<1;
          if (temp < cb->dst_size.u4_height) {cb->dst_size.u4_height = temp;}
          if (cb->dst_size.u4_height == 0) {cb->dst_size.u4_height = 2;}
        }
        else
        {
          // dst_h needs not to be changed...
          //cb->dst_size.u4_width = (v_ratio*src_clip_w)>>16;
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
        }
        else if (h_after_rot == cb->dst_fb_size.u4_height)
        {
          ASSERT(w_after_rot <= cb->dst_fb_size.u4_width);
          dst_x = (cb->dst_fb_size.u4_width - w_after_rot)>>1;
          dst_y = 0;
        }
        else
        {
          ASSERT(0);
        }
        dst_start_offset = (cb->dst_fb_size.u4_width*dst_y + dst_x) * va2_util_get_bpp(cb->dst_color_format);
        if (KAL_TRUE == cb->trigger_display) // HW mode
        {
          kal_uint32 iIndex = (_va2_vr_render_display_buffer_cnt&0x1);
          cb->dst_fb_start_addr_array[iIndex+1].u4_fb_addr_plane0 = cb->dst_fb_addr_array[iIndex+1].u4_fb_addr_plane0 + dst_start_offset;
        }  
        else
        {
          cb->dst_fb_start_addr_array[0].u4_fb_addr_plane0 = cb->dst_fb_addr_array[0].u4_fb_addr_plane0 + dst_start_offset;
        }
      }
    }

    if (KAL_FALSE == idp_video_decode_stop(_va2_comp_video_renderer_idp_key))
    {
      ASSERT(0);
    }
    
    if (KAL_TRUE == cb->trigger_display) // HW mode
    {
      kal_uint32 iIndex = (_va2_vr_render_display_buffer_cnt&0x1);
      idp_video_decode_config(
      _va2_comp_video_renderer_idp_key,
        IDP_VIDEO_DECODE_DC_RDMA_ADDR,cb->dst_fb_addr_array[iIndex+1].u4_fb_addr_plane0,
        IDP_VIDEO_DECODE_DC_TARGET_WIDTH, dc_dst_width,
        IDP_VIDEO_DECODE_DC_TARGET_HEIGHT, dc_dst_heigth,
        IDP_VIDEO_DECODE_FRAME_BUFFER_ADDRESS, cb->dst_fb_start_addr_array[iIndex+1].u4_fb_addr_plane0,
        IDP_VIDEO_DECODE_FRAME_BUFFER_ADDRESS_2, cb->dst_fb_start_addr_array[iIndex+1].u4_fb_addr_plane0,
        0);
      _va2_vr_render_display_buffer_cnt++;
    }
    else // SW mode
    {
      idp_video_decode_config(
        _va2_comp_video_renderer_idp_key,
        IDP_VIDEO_DECODE_DC_RDMA_ADDR,cb->dst_fb_addr_array[0].u4_fb_addr_plane0,
        IDP_VIDEO_DECODE_DC_TARGET_WIDTH, dc_dst_width,
        IDP_VIDEO_DECODE_DC_TARGET_HEIGHT, dc_dst_heigth,
        IDP_VIDEO_DECODE_FRAME_BUFFER_ADDRESS, cb->dst_fb_start_addr_array[0].u4_fb_addr_plane0,
        IDP_VIDEO_DECODE_FRAME_BUFFER_ADDRESS_2, cb->dst_fb_start_addr_array[0].u4_fb_addr_plane0,
        0); 
    }

    result = idp_video_decode_config(
      _va2_comp_video_renderer_idp_key,
      /* not in use */
      IDP_VIDEO_DECODE_INTMEM_START_ADDRESS, 0,
      IDP_VIDEO_DECODE_INTMEM_SIZE, 0,
      IDP_VIDEO_DECODE_EXTMEM_START_ADDRESS, 0,
      IDP_VIDEO_DECODE_EXTMEM_SIZE, 0,

      /* not in use */
      IDP_VIDEO_DECODE_TARGET_WIDTH_FOR_TVOUT, rRender_Convert.clip_conv_disp_width,
      IDP_VIDEO_DECODE_TARGET_HEIGHT_FOR_TVOUT, rRender_Convert.clip_conv_disp_height,
      IDP_VIDEO_DECODE_TARGET_WIDTH, rRender_Convert.clip_conv_disp_width,
      IDP_VIDEO_DECODE_TARGET_HEIGHT, rRender_Convert.clip_conv_disp_height,

      // TODO: handle MED incorrect param for IPP
      IDP_VIDEO_DECODE_CONTRAST_LEVEL, (KAL_FALSE == cb->post_process.b_contrast) ? 0x80 : cb->post_process.u1_contrast, 
      IDP_VIDEO_DECODE_BRIGHTNESS_LEVEL, (KAL_FALSE == cb->post_process.b_brightness) ? 0x80 : cb->post_process.u1_brightness, 
      //Pitch
      IDP_VIDEO_DECODE_ENABLE_PITCH, (VIDEO_RENDERER_RENDER_MODE_TOUCH_WINDOW_FROM_INSIDE == cb->render_mode)?KAL_TRUE:KAL_FALSE,
      IDP_VIDEO_DECODE_BG_IMAGE_WIDTH, (bg_image_width),

      IDP_VIDEO_DECODE_IMAGE_DATA_FORMAT, va2_util_convert_to_idp_color_format(cb->dst_color_format),
      IDP_VIDEO_DECODE_DONE_CB, ptr_FrmDoneCBFunc,
      IDP_VIDEO_DECODE_DONE_CB_PARAM, cb,

      IDP_VIDEO_DECODE_SOURCE_DATA_FORMAT, va2_util_convert_to_idp_color_format(cb->src_color_format),

      /* not in use */
      IDP_VIDEO_DECODE_SRC_FMT_4X4, KAL_FALSE,
      IDP_VIDEO_DECODE_ENABLE_MP4DEBLK, KAL_FALSE,
      IDP_VIDEO_DECODE_MP4DEBLK_QUANT_BUF, 0x0,

      IDP_VIDEO_DECODE_RESIZER_U_VALUE, 8,
      IDP_VIDEO_DECODE_RESIZER_V_VALUE, 15,

#if defined(DRV_DISPLAY_DRIVER_V1)
  IDP_VIDEO_DECODE_TRIGGER_LCD, cb->trigger_display,
   IDP_VIDEO_DECODE_FORCE_LCD_HW_TRIGGER, force_lcd_hw_trigger,
#endif
#if defined(DRV_DISPLAY_DRIVER_V2)
  IDP_VIDEO_DECODE_TRIGGER_LCD, cb->trigger_display, 
    IDP_VIDEO_DECODE_FORCE_LCD_HW_TRIGGER, cb->disable_dcmode,
#endif
      
      IDP_VIDEO_DECODE_SRC_WIDTH, video_frame->r_fb_size.u4_width,
      IDP_VIDEO_DECODE_SRC_HEIGHT, video_frame->r_fb_size.u4_height,
        
      IDP_VIDEO_DECODE_ENABLE_CLIP, video_frame->r_clip_window.b_clip_enable,
      IDP_VIDEO_DECODE_CLIP_LEFT, rRender_Convert.clip_conv_clip_left,
      IDP_VIDEO_DECODE_CLIP_RIGHT, rRender_Convert.clip_conv_clip_right,
      IDP_VIDEO_DECODE_CLIP_TOP, rRender_Convert.clip_conv_clip_top,
      IDP_VIDEO_DECODE_CLIP_BOTTOM, rRender_Convert.clip_conv_clip_bottom,

      IDP_VIDEO_DECODE_DST_CLIP, cb->dst_clip.b_clip_enable, 
                                 cb->dst_clip.u4_clip_left, cb->dst_clip.u4_clip_top, 
                                 cb->dst_clip.u4_clip_right, cb->dst_clip.u4_clip_bottom, 
        
      IDP_VIDEO_DECODE_VIDEO_Y_BUFFER_ADDRESS, video_frame->r_fb_addr.u4_fb_addr_plane0,
      IDP_VIDEO_DECODE_VIDEO_U_BUFFER_ADDRESS, video_frame->r_fb_addr.u4_fb_addr_plane1,
      IDP_VIDEO_DECODE_VIDEO_V_BUFFER_ADDRESS, video_frame->r_fb_addr.u4_fb_addr_plane2,

      IDP_VIDEO_DECODE_ROT_ANGLE, va2_util_convert_to_idp_rot_angle(cb->rotate_flip.u2_cw_rotate_angle,
                                                                    cb->rotate_flip.b_flip), 
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
    return cb->dst_fb_start_addr_array[0].u4_fb_addr_plane0;
  }
  else
  {
    return 0;
  }
} // end of _va2_vr_vp_6268_render_display_frame_buffer

static void
_va2_vr_vp_6268_hisr_general(void)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6268_cb;

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
      //va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
    }
    break;

  default:
    ASSERT(0);
  }

  cb->eVdoRndrHisrMode = VIDEO_RENDERER_HISR_MODE_NONE;
  return;
}

static void
_va2_vr_vp_6268_hisr_empty_this_buffer(void)
{
    va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6268_cb;
    _va2_vr_vp_6268_empty_this_buffer_real(&_va2_comp_video_renderer_rNewBuffHeader);
    kal_set_eg_events(cb->EventID, TASK_WAIT_HISR_SET, KAL_OR);
}

static void
_va2_vr_vp_6268_disp_timer_visu_hisr_cb_func(void)
{
  kal_bool idp_busy;
  kal_uint32 u4DurationmS;
  static kal_uint32 _u4DispTimerSkipCnt = 0, _u4DispTimerRefreshCnt = 0;
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6268_cb;

  if(VIDEO_STATE_RUN != cb->state.eState)
  {
    return;
  }

  #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)
    SLA_CustomLogging("TM1", 1);
  #endif  // #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)

  _u4DispTimerRefreshCnt++;

  idp_video_decode_is_busy(_va2_comp_video_renderer_idp_key, &idp_busy);

  // If IDP not busy and no BH waiting...
  if ((KAL_FALSE == idp_busy) &&
      // (0 == _to_be_processed_q.size) &&
      (VIDEO_STATE_RUN == cb->state.eState) &&
      (KAL_FALSE == cb->bypass))
  {
    va2_vr_add_trace(_va2_vr_vp_6268_debug_trace, VA2_VR_INTERNAL____DSPL_TIMER_TRIGGER_RENDER_IN_VHISR, (kal_uint32) cb->vr_q_handle.curr_dspl_buf_hdr);

    #if defined(VA2_VR_VP_6268_ENABLE_SWLA_TRACE)
      SLA_CustomLogging("RTM", 1);
    #endif  // #if defined(VA2_VR_VP_6268_ENABLE_SWLA_TRACE)

    _va2_vr_vp_6268_render_display_frame_buffer(cb, KAL_FALSE);

    #if defined(VA2_VR_VP_6268_ENABLE_SWLA_TRACE)
      SLA_CustomLogging("RTM", 0);
    #endif  // #if defined(VA2_VR_VP_6268_ENABLE_SWLA_TRACE)
  }

  #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)
    SLA_CustomLogging("TM1", 0);
  #endif  // #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)

}  // end of _va2_vr_vp_6268_disp_timer_visu_hisr_cb_func


/**
 *  @status OK
 *  @todo init the control block
 *  @common none
 */
static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6268_t01_close_to_init(
  va2_comp_video_renderer_cb_t *cb)
{
  kal_uint32 save_irq_mask;

  if (NULL == cb)
  {
    ASSERT(0);
  }

  va2_vr_add_trace(_va2_vr_vp_6268_debug_trace, VA2_VR_TRANSITION__T01_CLOSE_TO_INIT, 0);

  if (VIDEO_ERROR_NONE != va2_vr_t01_close_to_init(cb))
  {
    return VIDEO_ERROR_INIT_ERROR;
  }

  //  4. Initialize video renderer parameters...
  {
    //    4.1 Allocate memory for secondary display frame buffer
    //allocate extra display buffers when render_type is VIDEO_RENDERER_VIDEO_PLAYBACK
    if (cb->renderer_type == VIDEO_RENDERER_VIDEO_PLAYBACK)
    {
      cb->dst_fb_addr_array[1].u4_fb_addr_plane0 = VideoGetExtBuffer(_va2_vr_render_extmem_handler,VA2_VR_VP_DISPLAY_BUFFER_SIZE);
      if (0 == cb->dst_fb_addr_array[1].u4_fb_addr_plane0)
      {
        //ASSERT(0); // buffer allocation failed
        return VIDEO_ERROR_NO_MEMORY; // memory allocation fail
      }
      cb->dst_fb_addr_array[1].u4_fb_addr_plane0 =
        VideoCommExtBufferCacheableSwitch(cb->dst_fb_addr_array[1].u4_fb_addr_plane0,
                                          VA2_VR_VP_DISPLAY_BUFFER_SIZE,
                                          VIDEO_NON_CACHEABLE);
  
      // [6268_video_renderer_temp] Put the second allocated display frame buffer in 3rd slot.
      //    4.1.1 Allocate memory for secondary display frame buffer
      cb->dst_fb_addr_array[2].u4_fb_addr_plane0 = VideoGetExtBuffer(_va2_vr_render_extmem_handler,VA2_VR_VP_DISPLAY_BUFFER_SIZE);
      if (0 == cb->dst_fb_addr_array[2].u4_fb_addr_plane0)
      {
        //ASSERT(0); // buffer allocation failed
        return VIDEO_ERROR_NO_MEMORY; // memory allocation fail
      }
      cb->dst_fb_addr_array[2].u4_fb_addr_plane0 =
        VideoCommExtBufferCacheableSwitch(cb->dst_fb_addr_array[2].u4_fb_addr_plane0,
                                          VA2_VR_VP_DISPLAY_BUFFER_SIZE,
                                          VIDEO_NON_CACHEABLE);
    }
  }

  cb->dst_fb_start_addr_array[0].u4_fb_addr_plane0 = cb->dst_fb_addr_array[0].u4_fb_addr_plane0;
  cb->dst_fb_start_addr_array[1].u4_fb_addr_plane0 = cb->dst_fb_addr_array[1].u4_fb_addr_plane0;
  cb->dst_fb_start_addr_array[2].u4_fb_addr_plane0 = cb->dst_fb_addr_array[2].u4_fb_addr_plane0;
  
  cb->dst_color_format = VIDEO_RENDERER_COLOR_RGB565;

  _va2_vr_render_display_buffer_cnt = 0;
  //Use Time-Sharing Mechanism, you must clear it.
  _va2_comp_video_renderer_idp_key = 0;

  return VIDEO_ERROR_NONE;
}


/**
 *  @status OK
 *  @todo: remove those "very temp" part before SQC...
 *  @common VR.VP
 */
static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6268_t03_init_to_idle(
  va2_comp_video_renderer_cb_t *cb)
{
  kal_uint32 save_irq_mask;

  if (NULL == cb)
  {
    ASSERT(0);
  }

  //  clear_video_frame = KAL_FALSE;
  va2_vr_add_trace(_va2_vr_vp_6268_debug_trace, VA2_VR_TRANSITION__T03_INIT_TO_IDLE, 0);

  //  1. Open MDP path and register Visual HISR. LCD driver are opened in state transitions to Run state
  {
    kal_uint32 wait_count = 0;
    //return error instead of assert if mdp open fail
    while (wait_count < 10 && (0 == _va2_comp_video_renderer_idp_key) && 
      (KAL_FALSE == idp_video_decode_open(&_va2_comp_video_renderer_idp_key)))
    {
      kal_sleep_task(1);
      wait_count++;
    }
    if (wait_count >= 10)
    {return VIDEO_ERROR_INIT_ERROR;}
  }

  //    1.1 register VISUAL HISR for misc video render use
  VISUAL_Register_HISR(VISUAL_RENDERER_HISR_ID, _va2_vr_vp_6268_hisr_general);

  VISUAL_Register_HISR(VISUAL_RENDERER_EMPTY_THIS_BUFFER_HISR_ID, _va2_vr_vp_6268_hisr_empty_this_buffer);

  //    1.2 register VISUAL HISR for VR Timer processing. The timer is used to trigger MDP for redraw when
  //        there is no video frame in certain period of time. Under the situation, the UI updates will not
  //        be in effect since UI updates relies on MDP trigger under hardware trigger mode. The reason to
  //        let timer activates Visual HISR for MDP trigger is to centralize the control of MDP, so that
  //        reentrant condition can be solved.
  VISUAL_Register_HISR(VISUAL_RENDERER_TIMER_HISR_ID, _va2_vr_vp_6268_disp_timer_visu_hisr_cb_func);

  //  Create a timer for periodically update display device
  if (0 == cb->display_timer)
  {
    cb->display_timer = kal_create_timer("VA2_VR_VP_6268_TIMER");
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
_va2_vr_vp_6268_t04_idle_to_run(
  va2_comp_video_renderer_cb_t *cb)
{
#if defined(__MTK_TARGET__)
  kal_uint32 save_irq_mask;
  volatile VA2_VIDEO_RENDERER_HISR_MODE* pRndrHisrMode;

  if (NULL == cb)
  {
    ASSERT(0);
  }

  {
    // This bracket asserts the current IL client design. Without these assumption, black frame insertion may
    // cause some unwanted behavior.
    //
    // 2010/06/14 W1025, according to the design of Video Playback and Streaming, both confirmed that
    // the Idle->Run transition will be always "bypass-enabled". On the other hand, Stop->Run transition
    // is currently "bypass-disabled", but Stop->Run may subject to change in the future.
    //
    // The black frame insertion in Idle->Run will be wrong because it will definitely be inserted and cause some
    // unwanted initial black flash. However, the black frame inserted in Stop->Run transition may not be problem-free
    // as well, because it could still be inserted ahead of some videos/streaming and the initial black flash may be
    // observed for some contents.
    //
    // Also, the Idle state by its design definition resets all buffers for IL components. Together with the
    // open-up seqence that is in backward order, the render buffers must be empty at Idle->Run transition.
    ASSERT(KAL_TRUE == cb->bypass);
    ASSERT(NULL == cb->vr_q_handle.curr_dspl_buf_hdr);
    ASSERT(0 == cb->vr_q_handle.to_be_processed_q.size);
    ASSERT(0 == cb->vr_q_handle.to_be_returned_q.size);
    ASSERT(KAL_FALSE == _va2_comp_vr_have_config_lcd);
  }


  #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)
    SLA_CustomLogging("I2R", 1);
  #endif  // #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)

  //chrono add for reset u4LastSrcRenderTimestamp
  cb->u4LastSrcRenderTimestamp = drv_get_current_time();

  va2_vr_add_trace(_va2_vr_vp_6268_debug_trace, VA2_VR_TRANSITION__T04_IDLE_TO_RUN, 0);

  if (KAL_FALSE == cb->bypass)  // Do not control LCD, timer, black frame under bypass mode
  {
    save_irq_mask = SaveAndSetIRQMask();
    // Do not insert black frame if previous frame is available.
    if((cb->vr_q_handle.curr_dspl_buf_hdr == NULL) &&
       (0 == cb->vr_q_handle.to_be_processed_q.size))
    {
      cb->eVdoRndrHisrMode = VIDEO_RENDERER_HISR_MODE_BLACK_FRAME_INSERT;
      visual_active_hisr(VISUAL_RENDERER_HISR_ID);
    }
    RestoreIRQMask(save_irq_mask);

    //  config LCD driver if LCD HW_Trig is requested through set_parameter
    if (KAL_TRUE == cb->trigger_display)
    {
      lcd_frame_update_struct *lcd_cfg = &cb->display_surface.r_mtk_lcd_config;

      if (KAL_FALSE == _va2_comp_vr_have_config_lcd)
      {
#if defined(DRV_DISPLAY_DRIVER_V1)
        _va2_comp_vr_triggered_lcd_id_this_time = lcd_cfg->lcd_id;

        lcd_cfg->fb_update_mode = LCD_HW_TRIGGER_MODE;
        lcd_cfg->hw_trigger_src = 0; // pibben LCD_HWREF_SEL_ROT0;

        lcd_cfg->memory_output = KAL_FALSE;
        lcd_cfg->block_mode_flag = KAL_FALSE;
        lcd_cfg->lcd_block_mode_cb = NULL;

        // all the others are configed when processing video renderer parameters and configs

        // Register LCD HISR for FrameDone to do back-to-back rendering
        lcd_register_mm_callback(_va2_vr_vp_6268_lcd_frame_done_cb, cb);

        // Config LCD and start updating.
        ASSERT(LCD_OK == lcd_fb_update(lcd_cfg));
#endif  // #if defined(DRV_DISPLAY_DRIVER_V1)

#if defined(DRV_DISPLAY_DRIVER_V2)
        _va2_vr_vp_6268_config_n_activate_ddv2(cb);
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)

        va2_vr_add_trace(_va2_vr_vp_6268_debug_trace, VA2_VR_DEBUG_______START_LCD_HW_TRIGGER_MODE, 0);

        _va2_comp_vr_have_config_lcd = KAL_TRUE;
      }
      kal_set_timer( cb->display_timer,
                     (kal_timer_func_ptr) cb->funcs.display_timer_hdlr,
                     (void*) cb,
                     kal_milli_secs_to_ticks(VA2_COMP_VR_DSPL_DEFAULT_TIMEOUT_TIME),
                     kal_milli_secs_to_ticks(VA2_COMP_VR_DSPL_DEFAULT_TIMEOUT_TIME)
                   );
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
  } // end of bypass mode check


  // buffer header movements...
  // if no current buffer header, advance to the latest if possible...
  if((cb->vr_q_handle.curr_dspl_buf_hdr == NULL) &&
     (0 != cb->vr_q_handle.to_be_processed_q.size))
  {
    // advance to the latest buffer header...
    va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
    ASSERT(NULL != cb->vr_q_handle.curr_dspl_buf_hdr);
  }

  //  Invoke VideoCommChangeState() to RUN state.
  if (VIDEO_ERROR_NONE != VideoCommChangeState(&(cb->state), VIDEO_STATE_RUN))
  {
    ASSERT(0);
  }

  #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)
    SLA_CustomLogging("I2R", 0);
  #endif  // #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)
#endif  // #if defined(__MTK_TARGET__)

  return VIDEO_ERROR_NONE;
}  // end of _va2_vr_vp_6268_t04_idle_to_run


/**
 *  @status OK
 *  @common VR.VP
 */
static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6268_t05_run_to_stop(
  va2_comp_video_renderer_cb_t *cb)
{
  kal_uint32 save_irq_mask;

  if (NULL == cb)
  {
    ASSERT(0);
  }

  #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)
    SLA_CustomLogging("R2S", 1);
  #endif  // #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)

  va2_vr_add_trace(_va2_vr_vp_6268_debug_trace, VA2_VR_TRANSITION__T05_RUN_TO_STOP, 0);

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
    _va2_vr_vp_6268_stop_n_deactivate_ddv2(cb);
#endif
      va2_vr_add_trace(_va2_vr_vp_6268_debug_trace, VA2_VR_DEBUG_______STOP_LCD_HW_TRIGGER_MODE, 0);
      _va2_comp_vr_have_config_lcd = KAL_FALSE;
    }
  }
  //Because you must wait idp_frame_done.
  _va2_vr_render_display_buffer_cnt = 0;

  #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)
    SLA_CustomLogging("R2S", 0);
  #endif  // #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)

  return VIDEO_ERROR_NONE;
}

kal_bool
idp_val_video_decode_is_vp7_matt()
{
  if (KAL_FALSE == force_lcd_hw_trigger)
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
 */
static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6268_t06_stop_to_run(
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
  
  #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)
    SLA_CustomLogging("S2R", 1);
  #endif  // #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)

  va2_vr_add_trace(_va2_vr_vp_6268_debug_trace, VA2_VR_TRANSITION__T06_STOP_TO_RUN, 0);

  if (KAL_FALSE == cb->bypass)  // Do not control LCD, timer, black frame under bypass mode
  {
    save_irq_mask = SaveAndSetIRQMask();
    // Do not insert black frame if previous frame is available.
    if((cb->vr_q_handle.curr_dspl_buf_hdr == NULL) &&
       (0 == cb->vr_q_handle.to_be_processed_q.size))
    {
      cb->eVdoRndrHisrMode = VIDEO_RENDERER_HISR_MODE_BLACK_FRAME_INSERT;
      visual_active_hisr(VISUAL_RENDERER_HISR_ID);
    }
    RestoreIRQMask(save_irq_mask);

    //  config LCD driver if LCD HW_Trig is requested through set_parameter
    if (KAL_TRUE == cb->trigger_display)
    {
#if defined(DRV_DISPLAY_DRIVER_V1)
      //lcd_frame_update_struct *lcd_cfg = &cb->display_surface.r_mtk_lcd_config;
      lcd_frame_update_struct *lcd_data = &cb->display_surface.r_mtk_lcd_config;
#endif  // #if defined(DRV_DISPLAY_DRIVER_V1)

      if (KAL_FALSE == _va2_comp_vr_have_config_lcd)
      {
#if defined(DRV_DISPLAY_DRIVER_V1)
        #if 1
        g_idp_val_video_decode_is_vp7 = idp_val_video_decode_is_vp7_matt();
        #else
/* under construction !*/
        #endif //Matt: TODO: enable vp7 check later

        _va2_comp_vr_triggered_lcd_id_this_time = lcd_data->lcd_id;

        if (KAL_TRUE == g_idp_val_video_decode_is_vp7)
        {
          lcd_data->fb_update_mode = LCD_DIRECT_COUPLE_MODE;
#if defined(DRV_IDP_6238_SERIES)
          lcd_data->hw_trigger_src = LCD_HW_TRIGGER_IBW1;
#endif // #if defined(DRV_IDP_6238_SERIES)
        }
        else
        {
          lcd_data->fb_update_mode = LCD_HW_TRIGGER_MODE;
#if defined(DRV_IDP_6238_SERIES)
          lcd_data->hw_trigger_src = LCD_HW_TRIGGER_IRT1;
#endif // #if defined(DRV_IDP_6238_SERIES)
        }

        lcd_data->memory_output = KAL_FALSE;
        lcd_data->block_mode_flag = KAL_FALSE;
        lcd_data->lcd_block_mode_cb = NULL;
        // Register LCD HISR for FrameDone to do back-to-back rendering
        lcd_register_mm_callback(_va2_vr_vp_6268_lcd_frame_done_cb, cb);
        // Config LCD and start updating.
        ASSERT(LCD_OK == lcd_fb_update(lcd_data));
#endif  // #if defined(DRV_DISPLAY_DRIVER_V1)
#if defined(DRV_DISPLAY_DRIVER_V2)
    _va2_vr_vp_6268_config_n_activate_ddv2(cb);
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)
        va2_vr_add_trace(_va2_vr_vp_6268_debug_trace, VA2_VR_DEBUG_______START_LCD_HW_TRIGGER_MODE, 0);

        _va2_comp_vr_have_config_lcd = KAL_TRUE;
      }
      kal_set_timer( cb->display_timer,
                     (kal_timer_func_ptr) cb->funcs.display_timer_hdlr,
                     (void*) cb,
                     kal_milli_secs_to_ticks(VA2_COMP_VR_DSPL_DEFAULT_TIMEOUT_TIME),
                     kal_milli_secs_to_ticks(VA2_COMP_VR_DSPL_DEFAULT_TIMEOUT_TIME)
                   );
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
    if((cb->vr_q_handle.curr_dspl_buf_hdr == NULL) &&
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

  #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)
    SLA_CustomLogging("S2R", 0);
  #endif  // #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)

#endif  // #if defined(__MTK_TARGET__)
  return VIDEO_ERROR_NONE;
}  // end of _va2_vr_vp_6268_t06_stop_to_run


/**
 *  @status OK
 *  @common VR.VP
 */
static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6268_t10_idle_to_close(
  va2_comp_video_renderer_cb_t *cb)
{
  kal_uint32 save_irq_mask;

  if (NULL == cb)
  {
    ASSERT(0);
  }

  va2_vr_add_trace(_va2_vr_vp_6268_debug_trace, VA2_VR_TRANSITION__T10_IDLE_TO_CLOSE, 0);

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
_va2_vr_vp_6268_init(void)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6268_cb;
  VIDEO_ERROR_TYPE_T iRet;

  // create semaphore for API protection
  if (0 == cb->vr_sema_vrstate_sync)
  {
    cb->vr_sema_vrstate_sync = kal_create_sem("VA2_VR_VP_SEMA_VHISRCMD", 1);
  }

  kal_take_sem(cb->vr_sema_vrstate_sync, KAL_INFINITE_WAIT);

  va2_vr_init_trace(VA2_VR_VP_6268_DEBUG_TRACE_SIZE, &_va2_vr_vp_6268_debug_trace[0]);

  va2_vr_add_trace(_va2_vr_vp_6268_debug_trace, VA2_VR_API_________INIT, 0);

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
_va2_vr_vp_6268_send_command(
  VIDEO_COMMAND_TYPE_T eCmd,
  kal_uint32 u4Param)
{
  return va2_vr_send_command(&_va2_vr_vp_6268_cb, eCmd, u4Param);
}

/**
 *  @status OK
 *  @common VR.VP
 */
static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6268_get_parameter(
  VIDEO_PARAM_TYPE_T eCmd,
  void *pParam)
{
  VIDEO_ERROR_TYPE_T iRet = VIDEO_ERROR_NONE;
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6268_cb;

  // special case, this config could be get in any state...
  if (VIDEO_CONFIG_RENDERER_STATUS == eCmd)
  {
    ASSERT(NULL != pParam);
    *((VIDEO_STATE_TYPE_T*) pParam) = cb->state.eState;
    return VIDEO_ERROR_NONE;
  }

  kal_take_sem(cb->vr_sema_vrstate_sync, KAL_INFINITE_WAIT);
  va2_vr_add_trace(_va2_vr_vp_6268_debug_trace, VA2_VR_API_________GET_PARAMETER, (kal_uint32) eCmd);

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
    {
      kal_uint32 save_irq_mask;

      if (VIDEO_STATE_STOP != cb->state.eState)
      {
        ASSERT(0); // This parameter is only supported in STOP state
      }

    // TODO: Note this! Video Renderer will NOT assert if no video frame to be rendered  [MAUI_02995545 & MAUI_02994489]
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
        va2_vr_add_trace(&_va2_vr_vp_6268_debug_trace[0], VA2_VR_DEBUG_______NO_VIDEO_FRAME_TO_DRAW, 0);
        *(kal_uint32*)pParam = cb->dst_fb_addr_array[0].u4_fb_addr_plane0;
        break;
      }


      save_irq_mask = SaveAndSetIRQMask();
      if((KAL_FALSE == cb->keep_curr_ptr_when_run) || (NULL == cb->vr_q_handle.curr_dspl_buf_hdr))
      {
        // If only one frame is inserted in Run state, this action is to emulate
        // the processing of the previous Bypass-Mode Frames.
        va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
      }
      RestoreIRQMask(save_irq_mask);

      *(kal_uint32*)pParam = _va2_vr_vp_6268_render_display_frame_buffer(cb, KAL_TRUE);
      if(KAL_FALSE == (*(kal_uint32*)pParam) || (*(kal_uint32*)pParam != cb->dst_fb_start_addr_array[0].u4_fb_addr_plane0))
      {
        iRet = VIDEO_ERROR_INPUT_PARAM_ERROR;
      }
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
    ASSERT(0);
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
_va2_vr_vp_6268_set_parameter(
  VIDEO_PARAM_TYPE_T eCmd,
  void *pParam)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6268_cb;
  VIDEO_STATE_TYPE_T state;
  VIDEO_ERROR_TYPE_T i4Ret = VIDEO_ERROR_UNDEFINED;

  kal_take_sem(cb->vr_sema_vrstate_sync, KAL_INFINITE_WAIT);

  state = cb->state.eState;
  va2_vr_add_trace(_va2_vr_vp_6268_debug_trace, VA2_VR_API_________SET_PARAMETER, (kal_uint32) eCmd);

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
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
              (VIDEO_RENDERER_RENDER_MODE_STRETCH_TO_WINDOW == *render_mode))
          {
            cb->render_mode = *render_mode;
          }
          else if (VIDEO_RENDERER_RENDER_MODE_TOUCH_WINDOW_FROM_OUTSIDE == *render_mode)
          {
            // currently we cannot support this render mode yet!
            cb->render_mode = VIDEO_RENDERER_RENDER_MODE_STRETCH_TO_WINDOW;
            i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
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
        {
          i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
        }
        else
        {
          i4Ret = VIDEO_ERROR_NONE;
        }
        break;

      case VIDEO_PARAM_RENDERER_INTERNAL_MEMORY: /**< arg type: VA2_MEMORY_BLOCK_T* */
        {
          if (NULL == pParam)
          {
            ASSERT(0);
            i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
            break;
          }
        }
        i4Ret = VIDEO_ERROR_NONE;
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
_va2_vr_vp_6268_use_buffer(
  kal_uint8 *pu1Buff,
  kal_uint32 u4Size)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6268_cb;
  VIDEO_ERROR_TYPE_T i4Ret;

  kal_take_sem(cb->vr_sema_vrstate_sync, KAL_INFINITE_WAIT);
  i4Ret = va2_vr_use_buffer(&_va2_vr_vp_6268_cb, pu1Buff, u4Size);
  kal_give_sem(cb->vr_sema_vrstate_sync);
  return i4Ret;
}

/**
 *  @status OK
 *  @todo vr_q_handle
 *  @common VR.VP
 */
static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6268_empty_this_buffer(
  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6268_cb;
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
  _va2_vr_vp_6268_empty_this_buffer_real(prBuffHeader);
  return VIDEO_ERROR_NONE;
}

static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6268_empty_this_buffer_real(
  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
  va2_util_buf_hdr_q_item_t *q_item;
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6268_cb;

  #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)
    SLA_CustomLogging("REB", 1);
  #endif  // #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)

  va2_vr_add_trace(_va2_vr_vp_6268_debug_trace, VA2_VR_API_________EMPTY_THIS_BUFFER, (kal_uint32) prBuffHeader->pu1Buffer);

  // 0.7 This action is to emulate the processing of the previous Bypass-Mode Frames
  if (KAL_TRUE == cb->bypass)
  {
    if(cb->state.eState == VIDEO_STATE_RUN)
    {
      // For bypass mode, don't process/advance unless the frame is enqueued in Run state
      va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
    }
  }

  // 1. Return all buffer headers except the curr_dspl_buf_hdr
  va2_util_buf_hdr_remove_all_q_items(&(cb->vr_q_handle.to_be_returned_q), &(cb->vr_q_handle.to_be_processed_q));
  cb->funcs.try_to_return_buf_hdrs(cb);

  //  2. enqueue the buffer header...
  q_item = va2_util_buf_hdr_get_empty_q_item(&(cb->vr_q_handle));
  if (NULL == q_item)
  {
    ASSERT(0);
  }

  // Add a log to track the last valid emptyThisBuffer calls...
  va2_vr_add_trace(_va2_vr_vp_6268_debug_trace, VA2_VR_API_________EMPTY_THIS_BUFFER, (kal_uint32) (prBuffHeader->pu1Buffer));

  //    2.2 enqueue should not fail here...
  kal_mem_cpy((void*) &(q_item->buffer_header), prBuffHeader, sizeof(VIDEO_BUFFERHEADER_TYPE_T));
  va2_util_buf_hdr_enqueue(&(cb->vr_q_handle.to_be_processed_q), q_item);

  #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)
    SLA_CustomLogging("REB", 0);
  #endif  // #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)

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
      ASSERT(KAL_TRUE == idp_video_decode_is_busy(_va2_comp_video_renderer_idp_key, &busy));
      if (KAL_FALSE == busy)
      {
        va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
        va2_vr_add_trace(_va2_vr_vp_6268_debug_trace, VA2_VR_API_________EMPTY_THIS_BUFFER__TRIGGER_HW, (kal_uint32) (cb->vr_q_handle.curr_dspl_buf_hdr));
        _va2_vr_vp_6268_render_display_frame_buffer(cb, KAL_FALSE);
      }
      else
      {
        va2_vr_add_trace(_va2_vr_vp_6268_debug_trace, VA2_VR_API_________EMPTY_THIS_BUFFER__ENQUEUE_ONLY, (kal_uint32) (cb->vr_q_handle.to_be_processed_q.tail));
      }
      cb->u4LastSrcRenderTimestamp = drv_get_current_time();
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
_va2_vr_vp_6268_fill_this_buffer(
  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6268_cb;
  VIDEO_ERROR_TYPE_T i4Ret = VIDEO_ERROR_NONE;
  ASSERT(0); // This primitive is not supported!
  return i4Ret;
}

/**
 *  @status OK
 *  @common VR
 */
static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6268_set_callbacks(
  VIDEO_CALLBACK_TYPE_T *prCallback)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6268_cb;
  VIDEO_ERROR_TYPE_T i4Ret;

  kal_take_sem(cb->vr_sema_vrstate_sync, KAL_INFINITE_WAIT);
  i4Ret = va2_vr_set_callbacks(&_va2_vr_vp_6268_cb, prCallback);
  kal_give_sem(cb->vr_sema_vrstate_sync);

  return i4Ret;
}

/**
 *  @status OK
 *  @remark this function could only be invoked when in CLOSE state.
 */
VIDEO_ERROR_TYPE_T
_va2_vr_vp_6268_deinit(void)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6268_cb;
  VIDEO_ERROR_TYPE_T i4Ret;

  #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)
    SLA_CustomLogging("DIN", 1);
  #endif  // #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)

  kal_take_sem(cb->vr_sema_vrstate_sync, KAL_INFINITE_WAIT);
  i4Ret = va2_vr_deinit(&_va2_vr_vp_6268_cb);
  va2_vr_init_trace(0, NULL);
  kal_give_sem(cb->vr_sema_vrstate_sync);

  #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)
    SLA_CustomLogging("DIN", 0);
  #endif  // #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)

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
va2_video_renderer_vp_mt6268_get_handle(
  VA2_VIDEO_RENDERER_TYPE_T e_type)
{
#if defined(__MTK_TARGET__)
  VIDEO_COMPONENT_TYPE_T *pr_video_renderer_comp = NULL;
  VIDEO_ERROR_TYPE_T error_code = VIDEO_ERROR_NONE;

  switch (e_type)
  {
  case VIDEO_RENDERER_VIDEO_THUMBNAIL:
  case VIDEO_RENDERER_MJPG_THUMBNAIL:
    pr_video_renderer_comp = &_va2_vr_vp_6268_primitives;
    _va2_vr_vp_6268_cb.renderer_type = VIDEO_RENDERER_VIDEO_THUMBNAIL;
    break;

  case VIDEO_RENDERER_VIDEO_PLAYBACK:
  case VIDEO_RENDERER_MJPG_PLAYBACK:
    pr_video_renderer_comp = &_va2_vr_vp_6268_primitives;
    _va2_vr_vp_6268_cb.renderer_type = VIDEO_RENDERER_VIDEO_PLAYBACK;
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
va2_video_renderer_vp_mt6268_release_handle(
  VIDEO_COMPONENT_TYPE_T *pr_handle)
{
#if defined(__MTK_TARGET__)
  VIDEO_ERROR_TYPE_T error_code = VIDEO_ERROR_NONE;

  if ((NULL == pr_handle) ||
      (&_va2_vr_vp_6268_primitives != pr_handle) ||
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

#endif  // #if defined(VA2_VIDEO_RENDERER_VP_MT6268)
#endif  // #if defined(__VIDEO_ARCHI_V2__)
/// @}

