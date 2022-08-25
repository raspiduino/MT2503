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
 *    va2_video_renderer_vp_mt6253.c
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
 ****************************************************************************/
/// \ingroup va2_video_renderer_vp_mt6253
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
#include "va2_video_renderer_vp_mt6253.h"

#if defined(VA2_VIDEO_RENDERER_VP_MT6253)

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
#include "drv_features.h"
#include "drv_comm.h"
/******* MDP driver *************************/
#include "img_common_enum.h"
#include "idp_vdo_dec_mt6253.h" /**< MT6253 Video Decode scenario header file. */
/******* LCD driver *************************/
#include "lcd_if.h"
#include "drv_features_display.h"
/******* driver option **********************/
#include "drv_sw_features_video.h"

#if defined(DRV_DISPLAY_DRIVER_V2)
#include "wfc\inc\wfc_mm_api.h"     // The include path is "mcu\hal\display\wfc\inc"
#include "common\owftypes.h" // The include path is "mcu\interface\hal\display\api"
#include "common\owfnativestream.h" // The include path is "mcu\interface\hal\display\api"
// That I can turn it all off here...
#ifndef VRNDRR_DD_ASSERT
#define VRNDRR_DD_ASSERT(_expr_) ASSERT(_expr_)
#endif
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)


/******* Visual HISR driver *****************/
#include "visualhisr.h"
/******* SoftwareLA *************************/
#if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)
#include "SST_sla.h"
#endif


/****************************************************************************
 * local type definitions and macros
 ****************************************************************************/
//#define VA2_COMP_VR_MAX_DSPL_FB_COUNT           (3) // unnecessary
#define VA2_COMP_VR_RENDER_TIME_MAX             (1100) // (32768/1000)*33.3 ~ 1091 // 33.3ms

#define VA2_VR_VP_6253_DEBUG_TRACE_SIZE         (32)

/****************************************************************************
 * declarations
 ****************************************************************************/
#if defined(__MTK_TARGET__)


static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6253_init(void);

static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6253_send_command(
  VIDEO_COMMAND_TYPE_T eCmd,
  kal_uint32 u4Param);

static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6253_get_parameter(
  VIDEO_PARAM_TYPE_T eCmd,
  void *pParam);

static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6253_set_parameter(
  VIDEO_PARAM_TYPE_T eCmd,
  void *pParam);

static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6253_empty_this_buffer(
  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vp_6253_empty_this_buffer_real(
  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader);

static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6253_set_callbacks(
  VIDEO_CALLBACK_TYPE_T *prCallback);

static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6253_deinit(void);

static kal_uint32
_va2_vr_vp_6253_render_display_frame_buffer(
  va2_comp_video_renderer_cb_t *cb,
  kal_bool blocking);

static kal_bool
_va2_vr_vp_6253_check_params_configs(
  va2_comp_video_renderer_cb_t *cb);

static kal_bool
_va2_vr_vp_6253_config_idp_by_render_mode(
  va2_comp_video_renderer_cb_t *cb,
  VA2_VIDEO_FRAME_T *video_frame);

static void
_va2_vr_vp_6253_display_timer_hdlr(
  void *param);

static void
_va2_vr_vp_6253_idp_frame_done_cb(
  void *param);

static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6253_t01_close_to_init(
  va2_comp_video_renderer_cb_t *cb);

static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6253_t03_init_to_idle(
  va2_comp_video_renderer_cb_t *cb);

static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6253_t04_idle_to_run(
  va2_comp_video_renderer_cb_t *cb);

static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6253_t05_run_to_stop(
  va2_comp_video_renderer_cb_t *cb);

static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6253_t06_stop_to_run(
  va2_comp_video_renderer_cb_t *cb);

static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6253_t10_idle_to_close(
  va2_comp_video_renderer_cb_t *cb);


#endif  // #if defined(__MTK_TARGET__)

/****************************************************************************
 * local variables
 ****************************************************************************/
#if defined(__MTK_TARGET__)

/**
 *  @status OK
 */
static VIDEO_COMPONENT_TYPE_T _va2_vr_vp_6253_primitives =
{
    _va2_vr_vp_6253_init
  , _va2_vr_vp_6253_send_command
  , _va2_vr_vp_6253_get_parameter
  , _va2_vr_vp_6253_set_parameter
  , NULL
  , _va2_vr_vp_6253_empty_this_buffer
  , NULL
  , _va2_vr_vp_6253_set_callbacks
  , _va2_vr_vp_6253_deinit
};

static struct va2_comp_video_renderer_cb _va2_vr_vp_6253_cb =
  {
    {
      _va2_vr_vp_6253_t01_close_to_init,
      va2_vr_t02_init_to_close,
      _va2_vr_vp_6253_t03_init_to_idle,
      _va2_vr_vp_6253_t04_idle_to_run,
      _va2_vr_vp_6253_t05_run_to_stop,
      _va2_vr_vp_6253_t06_stop_to_run,
      NULL,//va2_vr_t07_run_to_idle,
      va2_vr_t08_stop_to_idle,
      NULL,//va2_vr_t09_idle_to_init,
      _va2_vr_vp_6253_t10_idle_to_close,
      va2_vr_t11_stop_to_close,
      va2_vr_t12_idle_to_idle,
      va2_vr_try_to_return_buffer_headers,
      _va2_vr_vp_6253_check_params_configs,
      _va2_vr_vp_6253_config_idp_by_render_mode,
      (va2_vr_dspl_timer_hdlr_func_t) _va2_vr_vp_6253_display_timer_hdlr,
      (va2_vr_hw_frame_done_cb_func_t) _va2_vr_vp_6253_idp_frame_done_cb,
      _va2_vr_vp_6253_render_display_frame_buffer,
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
//Use the one defined in va2_comp_video_renderer.c::_va2_comp_video_renderer_idp_key
//static kal_uint32 _va2_comp_video_renderer_idp_key = 0;

static va2_vr_debug_trace_entry_t _va2_vr_vp_6253_debug_trace[VA2_VR_VP_6253_DEBUG_TRACE_SIZE] = {0};

#if defined(DRV_DISPLAY_DRIVER_V2)
static WFCDevice _va2_vr_vp_6253_ddv2_dev = WFC_INVALID_HANDLE;
static WFCContext _va2_vr_vp_6253_ddv2_ctx = WFC_INVALID_HANDLE;
static WFCElement _va2_vr_vp_6253_ddv2_element = WFC_INVALID_HANDLE;
static WFCSource _va2_vr_vp_6253_ddv2_src = WFC_INVALID_HANDLE;
static OWFNativeStreamType _va2_vr_vp_6253_ddv2_stream = OWF_INVALID_HANDLE;
static WFCSource _va2_vr_vp_6253_ddv2_img_src = WFC_INVALID_HANDLE;
static kal_uint32 _va2_vr_vp_6253_dspl_fbs[3][2] = { 0 };

#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)

#endif  // #if defined(__MTK_TARGET__)

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
#endif  // #if defined(__MTK_TARGET__)

/****************************************************************************
 * local function bodies
 ****************************************************************************/
#if defined(__MTK_TARGET__)
#if defined(DRV_DISPLAY_DRIVER_V2)
void _va2_vr_vp_6253_wfc_frame_done_cb(
  WFCContextEventTypeMTK event,
  void* param)
{
  //_va2_vr_vp_6253_lcd_frame_done_cb(param);  //[CM TODO] 20101214
}

#if (defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252))
#define swap8(x, y)  { kal_uint8 z;  \
                       z = y;  \
                       y = x;  \
                       x = z; }
#define swap32(x, y) { kal_uint32 z; \
                       z = y;  \
                       y = x;  \
                       x = z; }
static void 
_va2_vr_vp_6252_sw_h_flip(
  va2_comp_video_renderer_cb_t *cb)
{
  kal_uint32 i, j;
  
  kal_uint8 *buffer = (kal_uint8*) cb->dst_fb_addr_array[0].u4_fb_addr_plane0;
  kal_uint32 width = cb->dst_fb_size.u4_width;
  kal_uint32 height = cb->dst_fb_size.u4_height;
  
  // for each row
  for (i=0; i<height; i++)
  {
    // for each byte (pixel/2)
    for (j=0; j<width; j++)
    {
      // Y, 1 <-> 2w-1, 3 <-> 2w-3, ....
      // V, 2 <-> 2w-2, 6 <-> 2w-6, ....
      // U, 0 <-> 2w-4, 4 <-> 2w-8, ....
      swap8(*(buffer + i*width*2 + j), *(buffer + i*width*2 + width*2 - j - ((j & 0x03) == 0x0? 4 : 0)));
    }
  }
}

static void 
_va2_vr_vp_6252_sw_v_flip(
  va2_comp_video_renderer_cb_t *cb)
{
  kal_uint32 i, j;
  
  kal_uint32 *buffer = (kal_uint32*) cb->dst_fb_addr_array[0].u4_fb_addr_plane0;
  kal_uint32 width = cb->dst_fb_size.u4_width;
  kal_uint32 height = cb->dst_fb_size.u4_height;
  
  // for each 2 column (width/2)
  for (i=0; i<(width/2); i++)
  {
    // for each word (2*pixel)
    for (j=0; j<(height/2); j++)
    {
      // UYVY(0) <-> UYVY(h-1), UYVY(1) <-> UYVY(h-2), ....
      swap32(*(buffer + j*(width/2) + i), *(buffer + (height-j-1)*(width/2) + i));
    }
  }
}

static kal_bool
_va2_vr_vp_6253_is_hw_layer_setting_modified_by_VR(
  WFCRotation *layerRotation, WFCboolean *layerFlip, va2_comp_video_renderer_cb_t *cb)
{
  kal_uint16 layer_rotation = 0;
  
  if (WFC_ROTATION_0 == *layerRotation)
  {
    layer_rotation = 0;
  }
  else if (WFC_ROTATION_90 == *layerRotation)
  {
    layer_rotation = 90;
  }
  else if (WFC_ROTATION_180 == *layerRotation)
  {
    layer_rotation = 180;
  }
  else if (WFC_ROTATION_270 == *layerRotation)
  {
    layer_rotation = 270;
  }
  
  // check layerRotation angle and flip: 
  // if layerRotation != display rotate angle or layerFlip != display flip
  // It must be modified by mMDP
  if ((cb->display_rotate_flip.u2_cw_rotate_angle != layer_rotation) ||
      ( cb->display_rotate_flip.b_flip != (kal_bool)*layerFlip))
  {
    return KAL_TRUE;
  }
  else
  {
    return KAL_FALSE;
  }
}
#endif

#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)

/**
 *  \remarks After this function, the rotation/flip of Video Renderer might be changed...
 */
static void
_va2_vr_vp_6253_config_n_activate_ddv2(
  va2_comp_video_renderer_cb_t *cb)
{
#if defined(DRV_DISPLAY_DRIVER_V2)
  kal_check_stack();

  {
    WFCint displayInputWidth = 0, displayInputHeight = 0; // The output width/height of MM...
    
#if (defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252))
    kal_uint16 final_lcd_rotate;
    WFCRotation layerRotation;

    WFCRotation FinallayerRotation = WFC_ROTATION_0;
    WFCboolean layerFlip;
    WFCboolean FinallayerFlip = (WFCboolean) KAL_FALSE;
#endif

    _va2_vr_vp_6253_ddv2_dev = (WFCDevice) cb->display_surface.dspl_dev_handle;
    _va2_vr_vp_6253_ddv2_ctx = (WFCContext) cb->display_surface.dspl_ctx_handle;
    _va2_vr_vp_6253_ddv2_element = (WFCElement) cb->display_surface.dspl_element_handle;

    if ((WFC_INVALID_HANDLE == _va2_vr_vp_6253_ddv2_dev) ||
        (WFC_INVALID_HANDLE == _va2_vr_vp_6253_ddv2_ctx) ||
        (WFC_INVALID_HANDLE == _va2_vr_vp_6253_ddv2_element))
    {
      VRNDRR_DD_ASSERT(0);
    }

    // Check if this element is a video layer...for debug only and can be removed for last QC stage...
    if (WFC_FALSE == wfcGetElementAttribi(_va2_vr_vp_6253_ddv2_dev, _va2_vr_vp_6253_ddv2_element, WFC_ELEMENT_VIDEO_LAYER_MTK))
    {
        wfcMMSetElementAttribi(_va2_vr_vp_6253_ddv2_dev, _va2_vr_vp_6253_ddv2_element, WFC_ELEMENT_VIDEO_LAYER_MTK, WFC_TRUE);
    }

    {
      wfcMMSetContextAttribi(_va2_vr_vp_6253_ddv2_dev, _va2_vr_vp_6253_ddv2_ctx, WFC_CONTEXT_AUTONOMOUS_SYNC_MODE_MTK, (WFCint) WFC_AUTONOMOUS_SYNC_TO_ELEMENT);
      wfcMMSetContextAttribi(_va2_vr_vp_6253_ddv2_dev, _va2_vr_vp_6253_ddv2_ctx, WFC_CONTEXT_AUTONOMOUS_PERIOD_MTK, (WFCint) 30);
      wfcMMSetContextAttribi(_va2_vr_vp_6253_ddv2_dev, _va2_vr_vp_6253_ddv2_ctx, WFC_CONTEXT_AUTONOMOUS_SYNC_ELEMENT_MTK, (WFCint) _va2_vr_vp_6253_ddv2_element);

      wfcMMSetContextAttribi(_va2_vr_vp_6253_ddv2_dev, _va2_vr_vp_6253_ddv2_ctx, WFC_CONTEXT_CURRENT_REFRESH_RATE_MTK, 0);
    }

    // Derive the output width/height of MDP, which might be the input width height of Display
    // Need to take rotation into consideration later...
    displayInputWidth = cb->dst_size.u4_width;
    displayInputHeight = cb->dst_size.u4_height;

#if (defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252))
    layerRotation = (WFCRotation)
        wfcGetElementAttribi(_va2_vr_vp_6253_ddv2_dev, _va2_vr_vp_6253_ddv2_element, WFC_ELEMENT_SOURCE_ROTATION);

    layerFlip = (WFCboolean)
        wfcGetElementAttribi(_va2_vr_vp_6253_ddv2_dev, _va2_vr_vp_6253_ddv2_element, WFC_ELEMENT_SOURCE_FLIP);

#if defined (__MAIN_LCM_SCANLINE_ROTATION_0__)
    // do nothing
#elif defined (__MAIN_LCM_SCANLINE_ROTATION_90__)
    if (cb->display_rotate_flip.u2_cw_rotate_angle >= 90)
    {cb->display_rotate_flip.u2_cw_rotate_angle -= 90;}
    else
    {cb->display_rotate_flip.u2_cw_rotate_angle += 270;}
#elif defined (__MAIN_LCM_SCANLINE_ROTATION_180__)
    if (cb->display_rotate_flip.u2_cw_rotate_angle >= 180)
    {cb->display_rotate_flip.u2_cw_rotate_angle -= 180;}
    else
    {cb->display_rotate_flip.u2_cw_rotate_angle += 180;}
#elif defined (__MAIN_LCM_SCANLINE_ROTATION_270__)
    if (cb->display_rotate_flip.u2_cw_rotate_angle >= 270)
    {cb->display_rotate_flip.u2_cw_rotate_angle -= 270;}
    else
    {cb->display_rotate_flip.u2_cw_rotate_angle += 90;}
#endif  

    // calculate Video Renderer rotate angle according to Video Frame rotate angle
    // which is assigned by Video Rotation Tag
    if (KAL_TRUE == cb->video_frame_rotate_flip.b_flip)
    {
      cb->rotate_flip.b_flip = KAL_TRUE;
      cb->rotate_flip.u2_cw_rotate_angle = (cb->video_frame_rotate_flip.u2_cw_rotate_angle >= cb->display_rotate_flip.u2_cw_rotate_angle)?
        cb->video_frame_rotate_flip.u2_cw_rotate_angle - cb->display_rotate_flip.u2_cw_rotate_angle : 
        360 + cb->video_frame_rotate_flip.u2_cw_rotate_angle - cb->display_rotate_flip.u2_cw_rotate_angle;        
    }
    else
    {
      cb->rotate_flip.b_flip = KAL_FALSE;
      cb->rotate_flip.u2_cw_rotate_angle = cb->video_frame_rotate_flip.u2_cw_rotate_angle + cb->display_rotate_flip.u2_cw_rotate_angle;
      if (cb->rotate_flip.u2_cw_rotate_angle >= 360)
      {
        cb->rotate_flip.u2_cw_rotate_angle -= 360;
      }
    }

    if ((cb->rotate_flip.u2_cw_rotate_angle == 0) || (cb->rotate_flip.u2_cw_rotate_angle == 180))
    {
      final_lcd_rotate = cb->rotate_flip.u2_cw_rotate_angle;
      FinallayerFlip = (WFCboolean) (cb->rotate_flip.b_flip ^ KAL_FALSE);

      cb->rotate_flip.u2_cw_rotate_angle = 0;
      cb->rotate_flip.b_flip = KAL_FALSE; 
    }
    else
    {
      final_lcd_rotate = cb->rotate_flip.u2_cw_rotate_angle - 90;
      FinallayerFlip = (WFCboolean) (cb->rotate_flip.b_flip ^ KAL_TRUE);

      cb->rotate_flip.u2_cw_rotate_angle = 90;
      cb->rotate_flip.b_flip = KAL_TRUE;
    }

    if (final_lcd_rotate == 0)
    {
      FinallayerRotation = WFC_ROTATION_0;
    }
    else if (final_lcd_rotate == 90)
    {
      FinallayerRotation = WFC_ROTATION_90;
    }
    else if (final_lcd_rotate == 180 )
    {
      FinallayerRotation = WFC_ROTATION_180;
    }
    else if (final_lcd_rotate == 270)
    {
      FinallayerRotation = WFC_ROTATION_270;
    }

    // Check if skip source rect and layerRotation/layerFlip setting
    if (_va2_vr_vp_6253_is_hw_layer_setting_modified_by_VR(&layerRotation, &layerFlip, cb) == KAL_FALSE)
    {
        wfcMMSetElementAttribi(_va2_vr_vp_6253_ddv2_dev, _va2_vr_vp_6253_ddv2_element, WFC_ELEMENT_SOURCE_ROTATION, FinallayerRotation);
        wfcMMSetElementAttribi(_va2_vr_vp_6253_ddv2_dev, _va2_vr_vp_6253_ddv2_element, WFC_ELEMENT_SOURCE_FLIP, FinallayerFlip);
    }

    if ((90 == cb->display_rotate_flip.u2_cw_rotate_angle) ||
        (270 == cb->display_rotate_flip.u2_cw_rotate_angle))
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

      // Check if skip source rect and layerRotation/layerFlip setting
      if (_va2_vr_vp_6253_is_hw_layer_setting_modified_by_VR(&layerRotation, &layerFlip, cb) == KAL_FALSE)
      {
        wfcGetElementAttribiv(_va2_vr_vp_6253_ddv2_dev, _va2_vr_vp_6253_ddv2_element, WFC_ELEMENT_SOURCE_RECTANGLE, 4, &srcRect[0]);

        if ((90 == cb->display_rotate_flip.u2_cw_rotate_angle) || 
            (270 == cb->display_rotate_flip.u2_cw_rotate_angle))
        {
          ClipX = srcRect[1];
          ClipY = srcRect[0];
          Width = srcRect[3];
          Height = srcRect[2];
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
        wfcMMSetElementAttribiv(_va2_vr_vp_6253_ddv2_dev, _va2_vr_vp_6253_ddv2_element, WFC_ELEMENT_SOURCE_RECTANGLE, 4, &srcRect[0]);
      }
    }
#endif  //#if (defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252))


    // Create stream...
    {
        //OWFNativeStreamType stream;
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
            VRNDRR_DD_ASSERT(0); //  [o] Need error handling...
            imageFormat.pixelFormat = OWF_IMAGE_RGB565;
            break;
        }

        _va2_vr_vp_6253_dspl_fbs[0][0] = bufs[0] = cb->dst_fb_addr_array[0].u4_fb_addr_plane0;
        _va2_vr_vp_6253_dspl_fbs[1][0] = bufs[1] = cb->dst_fb_addr_array[0].u4_fb_addr_plane0;
        // if use single buffer

        //  [m] When to destroy the stream? Where is the exit function?
        //  [o] magical number here...
        _va2_vr_vp_6253_ddv2_stream =
            owfNativeStreamCreateImageStreamEx((OWFint) displayInputWidth,
                                               (OWFint) displayInputHeight,
                                               &imageFormat, (OWFint) 2, (void**) &bufs[0]);

        // This code segment is used to do buffer control...
        {
          void * bufPtr;
          OWFNativeStreamBuffer buf;

          buf = owfNativeStreamAcquireWriteBuffer(_va2_vr_vp_6253_ddv2_stream);
          bufPtr = owfNativeStreamGetBufferPtr(_va2_vr_vp_6253_ddv2_stream, buf);
          VRNDRR_DD_ASSERT(NULL != bufPtr);

          _va2_vr_vp_6253_dspl_fbs[0][1] = (kal_uint32) buf;
        }

        _va2_vr_vp_6253_ddv2_src = wfcCreateSourceFromStream(_va2_vr_vp_6253_ddv2_dev, _va2_vr_vp_6253_ddv2_ctx, (WFCNativeStreamType) _va2_vr_vp_6253_ddv2_stream, NULL);

        if (WFC_INVALID_HANDLE == _va2_vr_vp_6253_ddv2_src)
        {
            VRNDRR_DD_ASSERT(0); //  [m] remove this after IT done...need error handling...
        }
    }

    // Set Element source
    wfcMMSetElementAttribi(_va2_vr_vp_6253_ddv2_dev, _va2_vr_vp_6253_ddv2_element, WFC_ELEMENT_SOURCE, (WFCint) _va2_vr_vp_6253_ddv2_src);

    // Add cb function
    {
      WFCint array[4];
      array[0] = (WFCint) WFC_CONTEXT_EVENT_COMPOSITION_FINISH_MTK;
      array[1] = (WFCint) _va2_vr_vp_6253_wfc_frame_done_cb;     //[CM TODO] 20101214
      array[2] = (WFCint) cb;
      array[3] = (WFCint) WFC_TRUE;
      wfcMMSetContextAttribiv(_va2_vr_vp_6253_ddv2_dev, _va2_vr_vp_6253_ddv2_ctx, WFC_CONTEXT_CALLBACK_MTK, 4, &array[0]);
    }

    // Commmit
    wfcMMCommit(_va2_vr_vp_6253_ddv2_dev, _va2_vr_vp_6253_ddv2_ctx, _va2_vr_vp_6253_ddv2_element, WFC_COMMIT_CONTEXT_AND_ELEMENT);

    // Need clear buffer, because get frame may render somethig without rotate.
    // And it will have some garbage with inside mode
#if defined(VA2_RENDER_MODE_TOUCH_FROM_INSIDE_SUPPORTED)
    if (VIDEO_RENDERER_RENDER_MODE_TOUCH_WINDOW_FROM_INSIDE == cb->render_mode)
    {
      kal_uint32 size = cb->dst_fb_size.u4_width * 
                        cb->dst_fb_size.u4_height * 
                        va2_util_get_bpp(cb->dst_color_format);
      kal_uint32 addr;

      #if (defined(MT6253) || defined(MT6253T))      
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
      #endif

      #if (defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252))
      if (VIDEO_RENDERER_COLOR_PACKED_UYVY422 == cb->dst_color_format)
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
      #endif
    }
#endif

  }

  kal_check_stack();
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)
}

static void
_va2_vr_vp_6253_stop_n_deactivate_ddv2(
  va2_comp_video_renderer_cb_t *cb)
{
#if defined(DRV_DISPLAY_DRIVER_V2)
  kal_check_stack();
  //  [m] Which variable can decide if display needs to work?
  if (OWF_INVALID_HANDLE != _va2_vr_vp_6253_ddv2_stream)
  {
    if ((WFC_INVALID_HANDLE == _va2_vr_vp_6253_ddv2_dev) ||
        (WFC_INVALID_HANDLE == _va2_vr_vp_6253_ddv2_ctx) ||
        (WFC_INVALID_HANDLE == _va2_vr_vp_6253_ddv2_element))
    {
      VRNDRR_DD_ASSERT(0);
    }

    {
      wfcMMSetContextAttribi(_va2_vr_vp_6253_ddv2_dev, _va2_vr_vp_6253_ddv2_ctx, WFC_CONTEXT_AUTONOMOUS_SYNC_MODE_MTK, (WFCint) WFC_AUTONOMOUS_SYNC_TO_TIMER);
      wfcMMSetContextAttribi(_va2_vr_vp_6253_ddv2_dev, _va2_vr_vp_6253_ddv2_ctx, WFC_CONTEXT_AUTONOMOUS_PERIOD_MTK, (WFCint) 0);
      wfcMMSetContextAttribi(_va2_vr_vp_6253_ddv2_dev, _va2_vr_vp_6253_ddv2_ctx, WFC_CONTEXT_AUTONOMOUS_SYNC_ELEMENT_MTK, (WFCint) 0);

      wfcMMSetContextAttribi(_va2_vr_vp_6253_ddv2_dev, _va2_vr_vp_6253_ddv2_ctx, WFC_CONTEXT_CURRENT_REFRESH_RATE_MTK, 30);
    }

    // Remove cb function
    {
      WFCint array[4];
      array[0] = (WFCint) WFC_CONTEXT_EVENT_COMPOSITION_FINISH_MTK;
      array[1] = (WFCint) _va2_vr_vp_6253_wfc_frame_done_cb;
      array[2] = (WFCint) cb;
      array[3] = (WFCint) WFC_FALSE;
      wfcMMSetContextAttribiv(_va2_vr_vp_6253_ddv2_dev, _va2_vr_vp_6253_ddv2_ctx, WFC_CONTEXT_CALLBACK_MTK, 4, &array[0]);
    }

    // Set an image source back to element
    {
      OWF_IMAGE image;
      OWF_PIXEL_FORMAT color_format = OWF_IMAGE_NOT_SUPPORTED;
      WFCint pixel_size = 0;

      if (_va2_vr_vp_6253_ddv2_img_src != WFC_INVALID_HANDLE)
      {
        wfcDestroySource(_va2_vr_vp_6253_ddv2_dev, _va2_vr_vp_6253_ddv2_img_src);
      }

      // Render to first frame buffer...
      {
        kal_uint32 save_irq_mask;
        if ((NULL == cb->vr_q_handle.curr_dspl_buf_hdr) && 
            (0 == cb->vr_q_handle.to_be_processed_q.size))
        {
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
              #if defined(MT6253) || defined(MT6253T)   
              if (VIDEO_RENDERER_COLOR_RGB565 == cb->dst_color_format)
              {
                kal_mem_set((void*) addr, 0x0, size);  //black for RGB565
              }
              #endif

              #if (defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252))
              if (VIDEO_RENDERER_COLOR_PACKED_UYVY422 == cb->dst_color_format)
              {
                va2_util_clear_uyvy_buffer_black((kal_uint32*)addr, size);  //black for UYVY422 
              }
              #endif
            }
          }
          va2_vr_add_trace(&_va2_vr_vp_6253_debug_trace[0], VA2_VR_DEBUG_______NO_VIDEO_FRAME_TO_DRAW, 0);
          image.data = (void*) cb->dst_fb_addr_array[0].u4_fb_addr_plane0;
        }
        else
        {
          save_irq_mask = SaveAndSetIRQMask();
          if((KAL_FALSE == cb->keep_curr_ptr_when_run) || (NULL == cb->vr_q_handle.curr_dspl_buf_hdr))
          {
            // If only one frame is inserted in Run state, this action is to emulate 
            // the processing of the previous Bypass-Mode Frames.
            va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
          }
          RestoreIRQMask(save_irq_mask);

          // Try to guarantee the index is 0 before get buffer...
          _va2_vr_render_display_buffer_cnt = 0;

          image.data = (void*) _va2_vr_vp_6253_render_display_frame_buffer(cb, KAL_TRUE);
          if ((kal_uint32)image.data != cb->dst_fb_addr_array[0].u4_fb_addr_plane0 &&
              (kal_uint32)image.data != cb->dst_fb_addr_array[1].u4_fb_addr_plane0)
          {image.data = (void*) cb->dst_fb_addr_array[0].u4_fb_addr_plane0;}
        }
      }

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
  
      _va2_vr_vp_6253_ddv2_img_src = wfcCreateSourceFromImage(_va2_vr_vp_6253_ddv2_dev, _va2_vr_vp_6253_ddv2_ctx, (WFCHandle) &image, NULL);
      VRNDRR_DD_ASSERT(_va2_vr_vp_6253_ddv2_img_src != WFC_INVALID_HANDLE);
      wfcMMSetElementAttribi(_va2_vr_vp_6253_ddv2_dev, _va2_vr_vp_6253_ddv2_element, WFC_ELEMENT_SOURCE, _va2_vr_vp_6253_ddv2_img_src);
      wfcMMCommit(_va2_vr_vp_6253_ddv2_dev, _va2_vr_vp_6253_ddv2_ctx, _va2_vr_vp_6253_ddv2_element, WFC_COMMIT_CONTEXT_AND_ELEMENT);              
    }

    wfcDestroySource(_va2_vr_vp_6253_ddv2_dev, _va2_vr_vp_6253_ddv2_src);
    _va2_vr_vp_6253_ddv2_src = WFC_INVALID_HANDLE;

    _va2_vr_vp_6253_ddv2_element = WFC_INVALID_HANDLE;
    _va2_vr_vp_6253_ddv2_ctx = WFC_INVALID_HANDLE;
    _va2_vr_vp_6253_ddv2_dev = WFC_INVALID_HANDLE;

    owfNativeStreamDestroy(_va2_vr_vp_6253_ddv2_stream);
    _va2_vr_vp_6253_ddv2_stream = OWF_INVALID_HANDLE;

    kal_mem_set((void*) _va2_vr_vp_6253_dspl_fbs, 0x0, sizeof(kal_uint32)*3*2);
  }
  kal_check_stack();
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)
}

static void
_va2_vr_vp_6253_trigger_display(
  kal_uint32 dspl_fb,
  va2_comp_video_renderer_cb_t *cb)
{
#if defined(DRV_DISPLAY_DRIVER_V2)
  if ((KAL_TRUE == cb->trigger_display) &&
      (OWF_INVALID_HANDLE != _va2_vr_vp_6253_ddv2_stream))
  {
    OWFNativeStreamBuffer buf;

    buf = (OWFNativeStreamBuffer) _va2_vr_vp_6253_dspl_fbs[0][1];
    owfNativeStreamReleaseWriteBuffer(_va2_vr_vp_6253_ddv2_stream,
                                  buf/* (OWFNativeStreamBuffer) 0x100 */,
                                  NULL /* (EGLDisplay) */,
                                  NULL /* (EGLSyncKHR) */);

    _va2_vr_vp_6253_dspl_fbs[0][1] = (kal_uint32) owfNativeStreamAcquireWriteBuffer(_va2_vr_vp_6253_ddv2_stream);
  }
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)
}


/**
 *  @description IL Client has a limitation that the error notify event can't be sent under VR's Stop state
 */
static void
_va2_vr_vp_6253_notify_error_to_client(
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
}

/**
 *  @status OK
 *  @common IDP API dependent
 */
static kal_bool
_va2_vr_vp_6253_check_params_configs(
  va2_comp_video_renderer_cb_t *cb)
{
  kal_bool fgRet = KAL_TRUE;

  //VA2_VIDEO_RENDERER_COLOR_FORMAT_T         src_color_format;
  //  Note this! Cannot remove...here to check if ever set
  if (VIDEO_RENDERER_COLOR_YUV420 != cb->src_color_format)
  {
    fgRet = KAL_FALSE; //  Why not directly return?
  }

  //VA2_FRAME_BUFFER_ADDRESS_T                src_fb_addr;
  //  Note this! alignment checking is left to MDP driver...
  if ((0 == cb->src_fb_addr.u4_fb_addr_plane0) ||
      (0 == cb->src_fb_addr.u4_fb_addr_plane1) ||
      (0 == cb->src_fb_addr.u4_fb_addr_plane2))
  {
    fgRet = KAL_FALSE;
  }

  //VA2_FRAME_SIZE_T                          src_size;
  //  Note this! Cannot remove...here to check if ever set
  //  Note this! alignment checking is left to MDP driver...
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
    //  Note this! Cannot remove...here to check if ever set
    if (cb->src_clip.u4_clip_top > cb->src_clip.u4_clip_bottom)
    {
      fgRet = KAL_FALSE;
    }
    if (cb->src_clip.u4_clip_left > cb->src_clip.u4_clip_right)
    {
      fgRet = KAL_FALSE;
    }
    if ((0 != cb->src_clip.u4_clip_left) ||
        (0 != cb->src_clip.u4_clip_top))
    {
      fgRet = KAL_FALSE;
    }
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
  //  Note this! Cannot remove...here to check if ever set
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
    //  Note this! Cannot remove...here to check if ever set
    if (cb->dst_clip.u4_clip_top > cb->dst_clip.u4_clip_bottom)
    {
      fgRet = KAL_FALSE;
    }
    if (cb->dst_clip.u4_clip_left > cb->dst_clip.u4_clip_right)
    {
      fgRet = KAL_FALSE;
    }
    if (((cb->dst_size.u4_width-1) < cb->dst_clip.u4_clip_right) ||
        ((cb->dst_size.u4_height-1) < cb->dst_clip.u4_clip_bottom))
    {
      fgRet = KAL_FALSE;
    }
  }

  //VA2_VIDEO_RENDERER_COLOR_FORMAT_T         dst_color_format;
  //  Note this! Cannot remove...here to check if ever set
#if (defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252))
  if (VIDEO_RENDERER_COLOR_PACKED_UYVY422 != cb->dst_color_format)
#else
  if (VIDEO_RENDERER_COLOR_RGB565 != cb->dst_color_format)
#endif
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

  //VA2_FRAME_BUFFER_ADDRESS_T                dst_fb_start_addr_array[VA2_COMP_VR_MAX_DSPL_FB_COUNT];
  // At least one frame...
  if (0x0 == cb->dst_fb_start_addr_array[0].u4_fb_addr_plane0)
  {
    fgRet = KAL_FALSE;
  }

  return fgRet;
}

/**
 *  @status OK
 *  @common IDP API dependent
 */
static kal_bool
_va2_vr_vp_6253_config_idp_by_render_mode(
  va2_comp_video_renderer_cb_t *cb,
  VA2_VIDEO_FRAME_T *video_frame)
{
  kal_uint16 mdp_real_rotate_angle;

  kal_mem_cpy(&(cb->src_size), &(video_frame->r_fb_size), sizeof(VA2_FRAME_SIZE_T));
  kal_mem_cpy(&(cb->src_clip), &(video_frame->r_clip_window), sizeof(VA2_CLIP_WINDOW_T));
  kal_mem_cpy(&(cb->src_fb_addr), &(video_frame->r_fb_addr), sizeof(VA2_FRAME_BUFFER_ADDRESS_T));

#if (defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252))
    if ((90 == cb->rotate_flip.u2_cw_rotate_angle) ||
        (270 == cb->rotate_flip.u2_cw_rotate_angle))
    {
      mdp_real_rotate_angle = 90;
    }
    else
#endif
    {
      mdp_real_rotate_angle = 0;
    }

#if defined(VA2_RENDER_MODE_TOUCH_FROM_INSIDE_SUPPORTED)
  if (VIDEO_RENDERER_RENDER_MODE_TOUCH_WINDOW_FROM_INSIDE == cb->render_mode)
  {
    kal_uint32 src_clip_w, src_clip_h;
    kal_uint32 w_after_rot, h_after_rot;

    // no dst clipping
    cb->dst_clip.b_clip_enable = KAL_FALSE;

    // set dst_size according to rotation angle
    if (mdp_real_rotate_angle == 90)
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
    if (0 == src_clip_w)
    {
      return KAL_FALSE;
    }
    if (0 == src_clip_h)
    {
      return KAL_FALSE;
    }
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
        if (temp < cb->dst_size.u4_height)
        {
          cb->dst_size.u4_height = temp;
        }
        if (cb->dst_size.u4_height == 0)
        {
          cb->dst_size.u4_height = 2;
        }
      }
      else
      {
        // dst_h needs not to be changed...
        temp = cb->dst_size.u4_width;
        cb->dst_size.u4_width = ((((v_ratio*src_clip_w)>>16)+1)>>1)<<1;
        if (temp < cb->dst_size.u4_width)
        {
          cb->dst_size.u4_width = temp;
        }
        if (cb->dst_size.u4_width == 0)
        {
          cb->dst_size.u4_width = 2;
        }
      }
    }

    // compute the pitch start address according to rotation...
    if (mdp_real_rotate_angle == 90)
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
        dst_x = 0;
        dst_y = (cb->dst_fb_size.u4_height - h_after_rot)>>1;

        // re-cauculate dst_y to 2x offset allignment
        if ((dst_y & 0x1) == 1)
        {
          dst_y--;
          if (mdp_real_rotate_angle == 90)
          {
            cb->dst_size.u4_width += 2;
          }
          else
          {
            cb->dst_size.u4_height += 2;
          }
        }
      }
      else if (h_after_rot == cb->dst_fb_size.u4_height)
      {
        dst_x = (cb->dst_fb_size.u4_width - w_after_rot)>>1;
        dst_y = 0;

        // re-cauculate dst_x to 2x offset allignment
        if ((dst_x & 0x1) == 1)
        {
          dst_x--;
          if (mdp_real_rotate_angle == 90)
          {
            cb->dst_size.u4_height += 2;
          }
          else
          {
            cb->dst_size.u4_width += 2;
          }
        }
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
  else 
#endif // defined(VA2_RENDER_MODE_TOUCH_FROM_INSIDE_SUPPORTED)
#if defined(VA2_RENDER_MODE_TOUCH_FROM_OUTSIDE_SUPPORTED)
  if (VIDEO_RENDERER_RENDER_MODE_TOUCH_WINDOW_FROM_OUTSIDE == cb->render_mode)
  {
    kal_uint32 src_clip_w, src_clip_h;
    kal_uint32 w_after_rot, h_after_rot;

    // set dst_size according to rotation angle
    if (mdp_real_rotate_angle == 90)
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
    if (0 == src_clip_w)
    {
      return KAL_FALSE;
    }
    if (0 == src_clip_h)
    {
      return KAL_FALSE;
    }

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

    // modify width to 2x if dst_color_format is UYVY
    if (VIDEO_RENDERER_COLOR_PACKED_UYVY422 == cb->dst_color_format)
    {
      cb->dst_fb_size.u4_width = (cb->dst_fb_size.u4_width>>1)<<1;
      if (mdp_real_rotate_angle == 90)
      {
        cb->dst_size.u4_height = (cb->dst_size.u4_height>>1)<<1;
      }
      else
      {
        cb->dst_size.u4_width = (cb->dst_size.u4_width>>1)<<1;
      }
    }

    // compute the pitch start address according to rotation...
    if (mdp_real_rotate_angle == 90)
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
        cb->dst_clip.b_clip_enable = KAL_FALSE;
        return KAL_FALSE;
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
  else 
#endif //defined(VA2_RENDER_MODE_TOUCH_FROM_OUTSIDE_SUPPORTED)
  if (VIDEO_RENDERER_RENDER_MODE_STRETCH_TO_WINDOW == cb->render_mode)
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
      if (mdp_real_rotate_angle == 90)
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

  {
    kal_bool result;
    idp_vdo_dec_t config;
    kal_mem_set((void*) &config, 0x0, sizeof(idp_vdo_dec_t));

    config.source_width = (kal_uint16) cb->src_size.u4_width;
    config.source_height = (kal_uint16) cb->src_size.u4_height;

    config.video_frame_real_width = (kal_uint16) (cb->src_clip.u4_clip_right + 1);
    config.video_frame_real_height = (kal_uint16) (cb->src_clip.u4_clip_bottom + 1);

    config.target_width = (kal_uint16) cb->dst_size.u4_width;
    config.target_height = (kal_uint16) cb->dst_size.u4_height;

    config.target_clip = cb->dst_clip.b_clip_enable;
    config.target_clip_top = (kal_uint16) cb->dst_clip.u4_clip_top;
    config.target_clip_bottom = (kal_uint16) cb->dst_clip.u4_clip_bottom;
    config.target_clip_left = (kal_uint16) cb->dst_clip.u4_clip_left;
    config.target_clip_right = (kal_uint16) cb->dst_clip.u4_clip_right;

    config.pitch = (cb->render_mode == VIDEO_RENDERER_RENDER_MODE_TOUCH_WINDOW_FROM_INSIDE)? KAL_TRUE: KAL_FALSE;
    config.pitch_width = cb->dst_fb_size.u4_width;

    config.out_frame_buffer_addr_1 = cb->dst_fb_start_addr_array[0].u4_fb_addr_plane0;
    if (NULL == cb->dst_fb_start_addr_array[1].u4_fb_addr_plane0)
    {
      config.out_frame_buffer_addr_2 = config.out_frame_buffer_addr_1;
    }
    else
    {
      config.out_frame_buffer_addr_2 = cb->dst_fb_start_addr_array[1].u4_fb_addr_plane0;
    }

#if defined(DRV_DISPLAY_DRIVER_V1)
    config.enable_trigger_lcd = ((KAL_FALSE == cb->bypass) && (KAL_TRUE == cb->trigger_display)) ? KAL_TRUE : KAL_FALSE;
#endif
#if defined(DRV_DISPLAY_DRIVER_V2)
    config.enable_trigger_lcd = KAL_FALSE;
#endif

    config.enable_cb = KAL_TRUE;
    config.frame_start_cb = NULL;
    config.frame_done_cb = _va2_vr_vp_6253_idp_frame_done_cb;

    config.lcd_data = &(cb->display_surface.r_mtk_lcd_config);

#if defined(DRV_DISPLAY_DRIVER_V2)
#if (defined(MT6253E) || defined(MT6253L) ||defined(MT6252) || defined(MT6252H))
    if ((90 == cb->rotate_flip.u2_cw_rotate_angle) ||
        (270 == cb->rotate_flip.u2_cw_rotate_angle))
    {
        config.rot_angle = IMG_MIRROR_ROT_ANGLE_90;
    }
    else
    {
        config.rot_angle = IMG_ROT_ANGLE_0;
    }
#endif
#endif

#if defined(CONTOUR_IMPROVEMENT_MT6253)
    config.extmem_start_address = cb->WM_start_address;
    config.extmem_size = cb->WM_size;
    config.video_frame_rate = cb->u4Fps;

    // Compute sw digher remain time
    if (cb->u4FramePeriodInMS > cb->u4DecodingTime)
    {
        cb->u4RemainTimeForSwDither = cb->u4FramePeriodInMS - cb->u4DecodingTime;
    }
    else
    {
        cb->u4RemainTimeForSwDither = 0;
    }
    config.reserve_time_to_mdp = cb->u4RemainTimeForSwDither;

#endif

    result = idp_video_decode_config(_va2_comp_video_renderer_idp_key, &config);

    return result;
  }
}

/**
 *  @todo OK
 *  @common Common for VR.VP except for control block instance.
 */
static void
_va2_vr_vp_6253_display_timer_hdlr(
  void *param)
{
  //kal_bool idp_busy;
  kal_uint32 save_irq_mask;
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6253_cb;

  //  check why need to observe this code segment
#if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("TM0", (SA_ACTION_T) 1);
#endif  // #if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)

#if defined(APPLY_NEW_REDRAW_MECHANISM)
  if(VIDEO_STATE_RUN != cb->state.eState)
  {
    return;
  }

  if(KAL_TRUE == va2_util_check_bypass_redraw(cb))
  {
    return;
  }
#endif

  save_irq_mask = SaveAndSetIRQMask();
  if (NULL == cb->vr_q_handle.curr_dspl_buf_hdr)
  {
    va2_vr_add_trace(&_va2_vr_vp_6253_debug_trace[0], VA2_VR_INTERNAL____DSPL_TIMER_ASSERT, 0);
    //  Note this! we remove this assertion due to this is not necessary from decoder and application's point of view!
    //ASSERT(0); // Until 5 sec time-out, no updates from former stage or IL client.
    RestoreIRQMask(save_irq_mask);

#if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)
      SLA_CustomLogging("TM0", (SA_ACTION_T) 0);
#endif  // #if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)

    return;
  }
  RestoreIRQMask(save_irq_mask);

  //  This close logging statement is missed...
#if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("TM0", (SA_ACTION_T) 0);
#endif  // #if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)

  if (KAL_TRUE == cb->bypass)
  {
    // If times out in bypass mode, do nothing...especially not to trigger IDP...
    // And actually we don't care about if no consequent buffer comes or not!!
    return;
  }

  va2_vr_add_trace(&_va2_vr_vp_6253_debug_trace[0], VA2_VR_INTERNAL____DSPL_TIMER_TIMEOUT, 0);

  //_va2_comp_vr_add_trace(, 0);
  visual_active_hisr(VISUAL_RENDERER_TIMER_HISR_ID);
}

/**
 *  @status XX
 *  @remark callback in HISR...VISUAL HISR to be specific...
 */
static void
_va2_vr_vp_6253_idp_frame_done_cb(
  void *param)
{
  va2_comp_video_renderer_cb_t *cb = (va2_comp_video_renderer_cb_t*) &_va2_vr_vp_6253_cb;

  if(VIDEO_STATE_RUN != cb->state.eState)
  {
    return;
  }

#if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("RFD", (SA_ACTION_T) 1);
#endif  // #if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)

  if (KAL_TRUE == cb->bypass)
  {
    // Unexpected: FrameDone occurs unders bypass mode.
    // Bypass mode should only be switched under Stop state, and render should only execute under Run state.
    // At last, FrameDone will not be processed except under Run state. There it is.
    ASSERT(0);
  }

  // Trigger display
#if defined(DRV_DISPLAY_DRIVER_V2)
    _va2_vr_vp_6253_trigger_display(
      cb->dst_fb_start_addr_array[0].u4_fb_addr_plane0,
      cb);
#endif

  va2_vr_add_trace(&_va2_vr_vp_6253_debug_trace[0], VA2_VR_INTERNAL____MDP_HW_FRAME_DONE_CB, 0);

  // if buffer header received while HW doing a frame...use the latest frame buffer for the next update...
  if (0 != cb->vr_q_handle.to_be_processed_q.size)
  {
    va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
  }

  // try to return all buffers...
  cb->funcs.try_to_return_buf_hdrs(cb);

#if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("RFD", (SA_ACTION_T) 0);
#endif  // #if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)
}

/**
 *  @return kal_uint32 the address to destination frame buffer if blocking is set to KAL_TRUE, 0 if blocking is set to KAL_FALSE.
 *  @status OK
 */
static kal_uint32
_va2_vr_vp_6253_render_display_frame_buffer(
  va2_comp_video_renderer_cb_t *cb,
  kal_bool blocking)
{
  VA2_VIDEO_FRAME_T *video_frame;
  va2_util_buf_hdr_q_item_t *curr_dspl_buf_hdr;
  kal_bool result;

  if ((NULL == cb) ||
      (NULL == cb->vr_q_handle.curr_dspl_buf_hdr))
  {
    return KAL_FALSE;; // incorrect param
  }

  curr_dspl_buf_hdr = cb->vr_q_handle.curr_dspl_buf_hdr;
  va2_vr_add_trace(&_va2_vr_vp_6253_debug_trace[0], VA2_VR_INTERNAL____RENDER, (kal_uint32) curr_dspl_buf_hdr);

  // IDP opened
  if (0 == _va2_comp_video_renderer_idp_key)
  {
    return KAL_FALSE; // IDP video playback not opened
  }

  // get frame data...
  video_frame = (VA2_VIDEO_FRAME_T*) curr_dspl_buf_hdr->buffer_header.pPrivateData;

  kal_mem_cpy(&(cb->src_size), &(video_frame->r_fb_size), sizeof(VA2_FRAME_SIZE_T));
  kal_mem_cpy(&(cb->src_clip), &(video_frame->r_clip_window), sizeof(VA2_CLIP_WINDOW_T));
  kal_mem_cpy(&(cb->src_fb_addr), &(video_frame->r_fb_addr), sizeof(VA2_FRAME_BUFFER_ADDRESS_T));

  // config video playback path according to render mode...
  result = _va2_vr_vp_6253_config_idp_by_render_mode(cb, video_frame);
  if (KAL_FALSE == result)
  {
    if (KAL_FALSE == blocking)
    {
      _va2_vr_vp_6253_notify_error_to_client(cb);
    }
    return KAL_FALSE;
  }

  // check all parameters and configs for triggering HW
  if (KAL_FALSE == _va2_vr_vp_6253_check_params_configs(cb))
  {
    if (KAL_FALSE == blocking)
    {
      _va2_vr_vp_6253_notify_error_to_client(cb);
    }
    return KAL_FALSE;
  }

#if defined(CONTOUR_IMPROVEMENT_MT6253)
  if (KAL_FALSE == blocking)
  {
    VA2_DITHERING_INFO_T *dithering_info;

    dithering_info = &(video_frame->r_dithering_info);

    if (dithering_info->u4MaxAVunSyncTime == 0)
    {
      dithering_info->u4MaxAVunSyncTime = 10,000,000;
    }

    if (dithering_info->u4AVunSyncTime <= dithering_info->u4MaxAVunSyncTime)
    {
      cb->u4VdoBufConsumptPercent = (kal_uint32)(((kal_uint64)(((kal_uint64)(dithering_info->u4MaxAVunSyncTime - dithering_info->u4AVunSyncTime))*100))/ (dithering_info->u4MaxAVunSyncTime));
    }
    else
    {
      cb->u4VdoBufConsumptPercent = 0;
    }

    idp_video_decode_notify_buffer_consumption(cb->u4VdoBufConsumptPercent);
  }
#endif

  result = idp_video_decode_config_yuv_src_address(
            _va2_comp_video_renderer_idp_key,
            video_frame->r_fb_addr.u4_fb_addr_plane0,
            video_frame->r_fb_addr.u4_fb_addr_plane1,
            video_frame->r_fb_addr.u4_fb_addr_plane2);
  if (KAL_FALSE == result)
  {
    if (KAL_FALSE == blocking)
    {
      _va2_vr_vp_6253_notify_error_to_client(cb);
    }
    return KAL_FALSE;
  }

  idp_video_decode_start(_va2_comp_video_renderer_idp_key);

  cb->u4LastRenderTimestamp = drv_get_current_time();

  // busy loop til IDP finishes
  if (KAL_TRUE == blocking)
  {
    kal_bool busy;
    kal_uint32 start_time = drv_get_current_time();

    do
    {
      kal_sleep_task(2); // If assert here, it means blocking mode is only allowed to be invoked in NU+ task.

      idp_video_decode_is_busy(_va2_comp_video_renderer_idp_key, &busy);

    } while ((KAL_TRUE == busy) &&
             (VA2_COMP_VR_RENDER_TIME_MAX > drv_get_duration_tick(start_time, drv_get_current_time())));

    return cb->dst_fb_start_addr_array[0].u4_fb_addr_plane0;
  }
  else
  {
    return KAL_FALSE;
  }
} // end of _va2_vr_vp_6253_render_display_frame_buffer

static void
_va2_vr_vp_6253_hisr_general(void)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6253_cb;

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
    break;
  }

  cb->eVdoRndrHisrMode = VIDEO_RENDERER_HISR_MODE_NONE;
}

static void
_va2_vr_vp_6253_hisr_empty_this_buffer(void)
{
    va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6253_cb;
    _va2_vr_vp_6253_empty_this_buffer_real(&_va2_comp_video_renderer_rNewBuffHeader);
    kal_set_eg_events(cb->EventID, TASK_WAIT_HISR_SET, KAL_OR);
}

static void
_va2_vr_vp_6253_disp_timer_visu_hisr_cb_func(void)
{
  kal_bool idp_busy;

#if !defined(APPLY_NEW_REDRAW_MECHANISM)
  kal_uint32 u4DurationmS;
  static kal_uint32 _u4DispTimerSkipCnt = 0, _u4DispTimerRefreshCnt = 0;
#endif

  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6253_cb;

#if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("TM1", (SA_ACTION_T) 1);
#endif  // #if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)

#if !defined(APPLY_NEW_REDRAW_MECHANISM)
  u4DurationmS = drv_get_duration_ms(cb->u4LastRenderTimestamp);
  if(u4DurationmS < 60)
  {
    _u4DispTimerSkipCnt++;

#if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)
    SLA_CustomLogging("TM1", (SA_ACTION_T) 0);
#endif  // #if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)
    return;
  }
  _u4DispTimerRefreshCnt++;
#endif

  idp_video_decode_is_busy(_va2_comp_video_renderer_idp_key, &idp_busy);

  // If IDP not busy and no BH waiting...
  if ((KAL_FALSE == idp_busy) &&
      // (0 == _to_be_processed_q.size) &&
      (VIDEO_STATE_RUN == cb->state.eState) &&
      (KAL_FALSE == cb->bypass))
  {
    va2_vr_add_trace(&_va2_vr_vp_6253_debug_trace[0], VA2_VR_INTERNAL____DSPL_TIMER_TRIGGER_RENDER_IN_VHISR, (kal_uint32) cb->vr_q_handle.curr_dspl_buf_hdr);

#if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)
    SLA_CustomLogging("RTM", (SA_ACTION_T) 1);
#endif  // #if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)

    _va2_vr_vp_6253_render_display_frame_buffer(cb, KAL_FALSE);

#if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)
    SLA_CustomLogging("RTM", (SA_ACTION_T) 0);
#endif  // #if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)
  }

#if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("TM1", (SA_ACTION_T) 0);
#endif  // #if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)

}  // end of _va2_vr_vp_6236_disp_timer_visu_hisr_cb_func


/**
 *  @status OK
 *  @todo init the control block
 *  @common none
 */
static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6253_t01_close_to_init(
  va2_comp_video_renderer_cb_t *cb)
{
  va2_vr_add_trace(&_va2_vr_vp_6253_debug_trace[0], VA2_VR_TRANSITION__T01_CLOSE_TO_INIT, 0);

  return va2_vr_t01_close_to_init(cb);
}


/**
 *  @status OK
 *  @todo: remove those "very temp" part before SQC...
 *  @common VR.VP
 */
static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6253_t03_init_to_idle(
  va2_comp_video_renderer_cb_t *cb)
{
  //kal_uint32 save_irq_mask;

  va2_vr_add_trace(&_va2_vr_vp_6253_debug_trace[0], VA2_VR_TRANSITION__T03_INIT_TO_IDLE, 0);

  cb->bIsErrorNotified = KAL_FALSE;

  //    1. Open MDP path and register Visual HISR. LCD driver are opened in state transitions to Run state
  idp_video_decode_open(&_va2_comp_video_renderer_idp_key);

  //    1.1 register VISUAL HISR for misc video render use
  VISUAL_Register_HISR(VISUAL_RENDERER_HISR_ID, _va2_vr_vp_6253_hisr_general);

  VISUAL_Register_HISR(VISUAL_RENDERER_EMPTY_THIS_BUFFER_HISR_ID, _va2_vr_vp_6253_hisr_empty_this_buffer);

  //    1.2 register VISUAL HISR for VR Timer processing. The timer is used to trigger MDP for redraw when
  //        there is no video frame in certain period of time. Under the situation, the UI updates will not
  //        be in effect since UI updates relies on MDP trigger under hardware trigger mode. The reason to
  //        let timer activates Visual HISR for MDP trigger is to centralize the control of MDP, so that
  //        reentrant condition can be solved.
  VISUAL_Register_HISR(VISUAL_RENDERER_TIMER_HISR_ID, _va2_vr_vp_6253_disp_timer_visu_hisr_cb_func);

  //  2. Create a timer for periodically update display device
  if (0 == cb->display_timer)
  {
    cb->display_timer = kal_create_timer("VA2_VR_VP_6253_TIMER");
    if (0 == cb->display_timer)
    {
      return VIDEO_ERROR_INIT_ERROR;
    }
  }

  //  4. Initialize video renderer parameters...
  {
#if defined(CONTOUR_IMPROVEMENT_MT6253)
    if (cb->renderer_type == VIDEO_RENDERER_VIDEO_PLAYBACK)
    {
        #if !defined(CONTOUR_IMPROVEMENT_MT6253_SLIM)
        //    4.1 allocate memory for secondary display frame buffer
        cb->dst_fb_addr_array[1].u4_fb_addr_plane0 = VideoGetExtBuffer(_va2_vr_render_extmem_handler, VA2_VR_VP_DISPLAY_BUFFER_SIZE);
        if (0 == cb->dst_fb_addr_array[1].u4_fb_addr_plane0)
        {
          return VIDEO_ERROR_INIT_ERROR;
        }
        #endif

        //     allocate memory for sw dithering working memory
        cb->WM_start_address = VideoGetExtBuffer(_va2_vr_render_extmem_handler, VA2_VR_SW_DITHER_WORKING_MEM_SZ);
        cb->WM_size = VA2_VR_SW_DITHER_WORKING_MEM_SZ;

        if (0 == cb->WM_start_address)
        {
          return VIDEO_ERROR_INIT_ERROR;
        }
    }
#endif

    //    4.2
    //  very temp...
    cb->dst_fb_size.u4_width = LCD_WIDTH;
    cb->dst_fb_size.u4_height = LCD_HEIGHT;

    //    4.3
    //  very temp...
    cb->dst_fb_start_addr_array[0].u4_fb_addr_plane0 = cb->dst_fb_addr_array[0].u4_fb_addr_plane0;
    cb->dst_fb_start_addr_array[1].u4_fb_addr_plane0 = cb->dst_fb_addr_array[1].u4_fb_addr_plane0;

    //    4.4
    //  very temp...
#if (defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252))
    cb->dst_color_format = VIDEO_RENDERER_COLOR_PACKED_UYVY422;
#else
    cb->dst_color_format = VIDEO_RENDERER_COLOR_RGB565;
#endif
    //    4.5
    //  very temp...
    cb->dst_size.u4_width = 240;
    cb->dst_size.u4_height = 196;

#if defined(APPLY_NEW_REDRAW_MECHANISM)
    cb->u4FramePeriodInMS = 83;  // this initial value should be removed, and follow set_parameter
#endif
  }

  // 5. Invoke VideoCommChangeState() to change to IDLE state
  VideoCommClrAllQ(&(cb->state));
  VideoCommChangeState(&(cb->state), VIDEO_STATE_IDLE);

  return VIDEO_ERROR_NONE;
}


/**
 *  @status OK
 */
static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6253_t04_idle_to_run(
  va2_comp_video_renderer_cb_t *cb)
{
  kal_uint32 save_irq_mask;
  //volatile VA2_VIDEO_RENDERER_HISR_MODE* pRndrHisrMode;

#if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("I2R", (SA_ACTION_T) 1);
#endif  // #if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)

  va2_vr_add_trace(&_va2_vr_vp_6253_debug_trace[0], VA2_VR_TRANSITION__T04_IDLE_TO_RUN, 0);

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

  if (KAL_FALSE == cb->bypass && VIDEO_RENDERER_VIDEO_PLAYBACK == cb->renderer_type)  // Do not control LCD, timer, black frame under bypass mode
  {
    //  config LCD driver if LCD HW_Trig is requested through set_parameter
    //  fix this!
    if (KAL_TRUE == cb->trigger_display)
    {
#if defined(DRV_DISPLAY_DRIVER_V2)
      if (KAL_FALSE == _va2_comp_vr_have_config_lcd)
      {
        _va2_vr_vp_6253_config_n_activate_ddv2(cb);

        va2_vr_add_trace(&_va2_vr_vp_6253_debug_trace[0], VA2_VR_DEBUG_______START_LCD_HW_TRIGGER_MODE, 0);

        _va2_comp_vr_have_config_lcd = KAL_TRUE;
      }
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)
    }

    // [MAUI_02440486] If black frame is not inserted in time, the 1st lcd_fb_update() call might be in HISR...
    if (KAL_TRUE == cb->trigger_display)
    {
      while ((NULL == cb->vr_q_handle.curr_dspl_buf_hdr) &&
             (0 == cb->vr_q_handle.to_be_processed_q.size))
      {
        kal_sleep_task(2); // Wait for any frame to be inserted...
      }
    }

    // buffer header movements...
    // if no current buffer header, advance to the latest if possible...
    if((NULL == cb->vr_q_handle.curr_dspl_buf_hdr) &&
       (0 != cb->vr_q_handle.to_be_processed_q.size))
    {
      // advance to the latest buffer header...
      va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
    }

    if (KAL_FALSE == _va2_vr_vp_6253_config_idp_by_render_mode(cb, (VA2_VIDEO_FRAME_T*) cb->vr_q_handle.curr_dspl_buf_hdr->buffer_header.pPrivateData))
    {
      //return VIDEO_ERROR_INPUT_PARAM_ERROR;
      _va2_vr_vp_6253_notify_error_to_client(cb);
    }

    if (KAL_TRUE == cb->trigger_display)
    {
      kal_set_timer(cb->display_timer,
                    (kal_timer_func_ptr) cb->funcs.display_timer_hdlr,
                    (void*) cb,
                    kal_milli_secs_to_ticks(VA2_COMP_VR_DSPL_DEFAULT_TIMEOUT_TIME),
                    kal_milli_secs_to_ticks(VA2_COMP_VR_DSPL_DEFAULT_TIMEOUT_TIME));
    }
  } // end of bypass mode check

  //  Invoke VideoCommChangeState() to RUN state.
  VideoCommChangeState(&(cb->state), VIDEO_STATE_RUN);


#if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("I2R", (SA_ACTION_T) 0);
#endif  // #if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)

  return VIDEO_ERROR_NONE;
}  // end of _va2_vr_vp_6253_t04_idle_to_run


/**
 *  @status OK
 *  @common VR.VP
 */
static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6253_t05_run_to_stop(
  va2_comp_video_renderer_cb_t *cb)
{
  //kal_uint32 save_irq_mask;

#if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("R2S", (SA_ACTION_T) 1);
#endif  // #if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)

  va2_vr_add_trace(&_va2_vr_vp_6253_debug_trace[0], VA2_VR_TRANSITION__T05_RUN_TO_STOP, 0);

  // Matt: to prevent EmptyThisBuffer, IDPFrameDone getting into wrong situation with a
  //       conservative state by reordering state assignment for in and out Run state.
  //       IL client is designed to invoke Renderer state transition in the blocking manner.
  //  0. Invoke VideoCommChangeState() to change state to STOP state.
  VideoCommChangeState(&(cb->state), VIDEO_STATE_STOP);

  if (0 != cb->display_timer)
  {
    kal_cancel_timer(cb->display_timer);
  }

  //  Stop processing...
  if (KAL_TRUE == cb->bypass || VIDEO_RENDERER_VIDEO_THUMBNAIL == cb->renderer_type)
  {
    // [1] do something?
  }
  else
  {
    idp_video_decode_stop(_va2_comp_video_renderer_idp_key);

#if defined(DRV_DISPLAY_DRIVER_V2)
    _va2_vr_vp_6253_stop_n_deactivate_ddv2(cb);
#endif

    if ((cb->trigger_display) &&
        (KAL_TRUE == _va2_comp_vr_have_config_lcd))
    {
      //lcd_stop_hw_update(_va2_comp_vr_triggered_lcd_id_this_time); // Not necessary...
      va2_vr_add_trace(&_va2_vr_vp_6253_debug_trace[0], VA2_VR_DEBUG_______STOP_LCD_HW_TRIGGER_MODE, 0);
      _va2_comp_vr_have_config_lcd = KAL_FALSE;
    }
  }

#if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("R2S", (SA_ACTION_T) 0);
#endif  // #if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)

  return VIDEO_ERROR_NONE;
}


/**
 *  @status OK
 */
static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6253_t06_stop_to_run(
  va2_comp_video_renderer_cb_t *cb)
{
#if defined(__MTK_TARGET__)
  kal_uint32 save_irq_mask;

#if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("S2R", (SA_ACTION_T) 1);
#endif  // #if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)

  va2_vr_add_trace(&_va2_vr_vp_6253_debug_trace[0], VA2_VR_TRANSITION__T06_STOP_TO_RUN, 0);

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

  if (KAL_FALSE == cb->bypass && VIDEO_RENDERER_VIDEO_PLAYBACK == cb->renderer_type)  // Do not control LCD, timer, black frame under bypass mode
  {
    //  config LCD driver if LCD HW_Trig is requested through set_parameter
    if (KAL_TRUE == cb->trigger_display)
    {
#if defined(DRV_DISPLAY_DRIVER_V2)
      if (KAL_FALSE == _va2_comp_vr_have_config_lcd)
      {
        _va2_vr_vp_6253_config_n_activate_ddv2(cb);

        va2_vr_add_trace(&_va2_vr_vp_6253_debug_trace[0], VA2_VR_DEBUG_______START_LCD_HW_TRIGGER_MODE, 0);

        _va2_comp_vr_have_config_lcd = KAL_TRUE;
      }
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)
    }

    // [MAUI_02440486] If black frame is not inserted in time, the 1st lcd_fb_update() call might be in HISR...
    if (KAL_TRUE == cb->trigger_display)
    {
      while ((NULL == cb->vr_q_handle.curr_dspl_buf_hdr) &&
             (0 == cb->vr_q_handle.to_be_processed_q.size))
      {
        kal_sleep_task(2); // Wait for any frame to be inserted...
      }
    }

    // buffer header movements...
    // if no current buffer header, advance to the latest if possible...
    if((NULL == cb->vr_q_handle.curr_dspl_buf_hdr) &&
       (0 != cb->vr_q_handle.to_be_processed_q.size))
    {
      // advance to the latest buffer header...
      va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
    }

    if (KAL_FALSE == _va2_vr_vp_6253_config_idp_by_render_mode(cb, (VA2_VIDEO_FRAME_T*) cb->vr_q_handle.curr_dspl_buf_hdr->buffer_header.pPrivateData))
    {
      //return VIDEO_ERROR_INPUT_PARAM_ERROR;
      _va2_vr_vp_6253_notify_error_to_client(cb);
    }

    if (KAL_TRUE == cb->trigger_display)
    {
      kal_set_timer(cb->display_timer,
                    (kal_timer_func_ptr) cb->funcs.display_timer_hdlr,
                    (void*) cb,
                    kal_milli_secs_to_ticks(VA2_COMP_VR_DSPL_DEFAULT_TIMEOUT_TIME),
                    kal_milli_secs_to_ticks(VA2_COMP_VR_DSPL_DEFAULT_TIMEOUT_TIME));
    }
  }

  //  Invoke VideoCommChangeState() to RUN state.
  VideoCommChangeState(&(cb->state), VIDEO_STATE_RUN);

#if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("S2R", (SA_ACTION_T) 0);
#endif  // #if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)

#endif  // #if defined(__MTK_TARGET__)
  return VIDEO_ERROR_NONE;
}  // end of _va2_vr_vp_6253_t06_stop_to_run


/**
 *  @status OK
 *  @common VR.VP
 */
static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6253_t10_idle_to_close(
  va2_comp_video_renderer_cb_t *cb)
{
  kal_uint32 save_irq_mask;

  va2_vr_add_trace(&_va2_vr_vp_6253_debug_trace[0], VA2_VR_TRANSITION__T10_IDLE_TO_CLOSE, 0);

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
  VideoCommChangeState(&(cb->state), VIDEO_STATE_CLOSE);

  return VIDEO_ERROR_NONE;
}


/**
 *  @status OK
 *  @common VR
 */
static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6253_init(void)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6253_cb;
  VIDEO_ERROR_TYPE_T iRet;

  // create semaphore for API protection
  if (0 == cb->vr_sema_vrstate_sync)
  {
    cb->vr_sema_vrstate_sync = kal_create_sem("VA2_VR_VP_SEMA_VHISRCMD", 1);
  }

  kal_take_sem(cb->vr_sema_vrstate_sync, KAL_INFINITE_WAIT);

  va2_vr_init_trace(VA2_VR_VP_6253_DEBUG_TRACE_SIZE, &_va2_vr_vp_6253_debug_trace[0]);

  va2_vr_add_trace(&_va2_vr_vp_6253_debug_trace[0], VA2_VR_API_________INIT, 0);

  if (VIDEO_STATE_CLOSE != cb->state.eState)
  {
    kal_give_sem(cb->vr_sema_vrstate_sync);
    return VIDEO_ERROR_INIT_ERROR;
  }

  iRet = cb->funcs.t01_close_to_init(cb);
  kal_give_sem(cb->vr_sema_vrstate_sync);

  return iRet;
}

static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6253_send_command(
  VIDEO_COMMAND_TYPE_T eCmd,
  kal_uint32 u4Param)
{
  return va2_vr_send_command(&_va2_vr_vp_6253_cb, eCmd, u4Param);
}

/**
 *  @status OK
 *  @common VR.VP
 */
static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6253_get_parameter(
  VIDEO_PARAM_TYPE_T eCmd,
  void *pParam)
{
  VIDEO_ERROR_TYPE_T iRet = VIDEO_ERROR_NONE;
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6253_cb;

  if (NULL == pParam)
  {
    return VIDEO_ERROR_INPUT_PARAM_ERROR;
  }

  // special case, this config could be get in any state...
  if (VIDEO_CONFIG_RENDERER_STATUS == eCmd)
  {
    *((VIDEO_STATE_TYPE_T*) pParam) = cb->state.eState;
    return VIDEO_ERROR_NONE;
  }

  kal_take_sem(cb->vr_sema_vrstate_sync, KAL_INFINITE_WAIT);
  va2_vr_add_trace(&_va2_vr_vp_6253_debug_trace[0], VA2_VR_API_________GET_PARAMETER, (kal_uint32) eCmd);

  if (VIDEO_STATE_CLOSE == cb->state.eState)
  {
    kal_give_sem(cb->vr_sema_vrstate_sync);
    return VIDEO_ERROR_INPUT_PARAM_ERROR;
  }

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
        iRet = VIDEO_ERROR_INPUT_PARAM_ERROR;
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
      iRet = VIDEO_ERROR_INPUT_PARAM_ERROR; // This parameter is only supported in STOP and IDLE state...
      break;
    }
    //  Note this! Video Renderer will NOT assert if no video frame to be rendered
    if ((NULL == cb->vr_q_handle.curr_dspl_buf_hdr) &&
        (0 == cb->vr_q_handle.to_be_processed_q.size))
    {
      //  draw the display frame buffer to black!
      if (NULL == cb->dst_fb_addr_array[0].u4_fb_addr_plane0)
      {
        iRet = VIDEO_ERROR_INPUT_PARAM_ERROR;
        break;
      }
      {
        kal_uint32 size = cb->dst_fb_size.u4_width *
                          cb->dst_fb_size.u4_height *
                          va2_util_get_bpp(cb->dst_color_format);
        kal_uint32 addr;
        if (0x0 != (addr = cb->dst_fb_start_addr_array[0].u4_fb_addr_plane0))
        {
          #if defined(MT6253) || defined(MT6253T)
          kal_mem_set((void*) addr, 0x0, size);  //black for RGB565
          #endif

          #if (defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252))
          va2_util_clear_uyvy_buffer_black((kal_uint32*)addr, size);  //black for UYVY422
          #endif
        }
      }
      va2_vr_add_trace(&_va2_vr_vp_6253_debug_trace[0], VA2_VR_DEBUG_______NO_VIDEO_FRAME_TO_DRAW, 0);
      *(kal_uint32*)pParam = cb->dst_fb_addr_array[0].u4_fb_addr_plane0;

      break;
    }

    if ((KAL_FALSE == cb->keep_curr_ptr_when_run) ||
        (NULL == cb->vr_q_handle.curr_dspl_buf_hdr)) // [MAUI_02568443] To cover curr is NULL case.
    {
      va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
    }

#if defined(MT6253) || defined(MT6253T)
    *(kal_uint32*)pParam = _va2_vr_vp_6253_render_display_frame_buffer(cb, KAL_TRUE);

    if(KAL_FALSE == (*(kal_uint32*)pParam))
    {
      iRet = VIDEO_ERROR_INPUT_PARAM_ERROR;
    }
#endif

#if (defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252))
    // calculate Video Renderer rotate angle according to Video Frame rotate angle
    // which is assigned by Video Rotation Tag
    if (KAL_TRUE == cb->video_frame_rotate_flip.b_flip)
    {
      cb->rotate_flip.b_flip = KAL_TRUE;
      cb->rotate_flip.u2_cw_rotate_angle = (cb->video_frame_rotate_flip.u2_cw_rotate_angle >= cb->display_rotate_flip.u2_cw_rotate_angle)?
        cb->video_frame_rotate_flip.u2_cw_rotate_angle - cb->display_rotate_flip.u2_cw_rotate_angle : 
        360 + cb->video_frame_rotate_flip.u2_cw_rotate_angle - cb->display_rotate_flip.u2_cw_rotate_angle;        
    }
    else
    {
      cb->rotate_flip.b_flip = KAL_FALSE;
      cb->rotate_flip.u2_cw_rotate_angle = cb->video_frame_rotate_flip.u2_cw_rotate_angle + cb->display_rotate_flip.u2_cw_rotate_angle;
      if (cb->rotate_flip.u2_cw_rotate_angle >= 360)
      {
        cb->rotate_flip.u2_cw_rotate_angle -= 360;
      }
    }

    if (((cb->rotate_flip.u2_cw_rotate_angle == 0) && (cb->rotate_flip.b_flip == KAL_FALSE)) ||
        ((cb->rotate_flip.u2_cw_rotate_angle == 90) && (cb->rotate_flip.b_flip == KAL_TRUE)))
    {
      // MDP can handle rotate
      *(kal_uint32*)pParam = _va2_vr_vp_6253_render_display_frame_buffer(cb, KAL_TRUE);

      if (KAL_FALSE == (*(kal_uint32*)pParam))
      {
        iRet = VIDEO_ERROR_INPUT_PARAM_ERROR;
      }
    }
    else
    {
      kal_uint16  sw_rotate; /**< CW. 0, 90, 180, 270 only. Default 0. */
      kal_bool    sw_flip; /**< KAL_TRUE to enable flipping. Default FALSE. */

      if ((cb->rotate_flip.u2_cw_rotate_angle == 0) || (cb->rotate_flip.u2_cw_rotate_angle == 180))
      {
        sw_rotate = cb->rotate_flip.u2_cw_rotate_angle;
        sw_flip = (kal_bool) (cb->rotate_flip.b_flip ^ KAL_FALSE);

        // No Rotate/Flip, give sw rotate do it.
        cb->rotate_flip.u2_cw_rotate_angle = 0;
        cb->rotate_flip.b_flip = KAL_FALSE; 
      }
      else
      {
        sw_rotate = cb->rotate_flip.u2_cw_rotate_angle - 90;
        sw_flip = (kal_bool) (cb->rotate_flip.b_flip ^ KAL_TRUE);

        // MDP must handle 90 because we need render mode setting.
        cb->rotate_flip.u2_cw_rotate_angle = 90;
        cb->rotate_flip.b_flip = KAL_TRUE;
      }

      *(kal_uint32*)pParam = _va2_vr_vp_6253_render_display_frame_buffer(cb, KAL_TRUE);

      if (KAL_FALSE == (*(kal_uint32*)pParam))
      {
        iRet = VIDEO_ERROR_INPUT_PARAM_ERROR;
        break;
      }

      // Only need support this three angle rotate
      if ((sw_rotate == 180) && (sw_flip == KAL_FALSE))
      {
        _va2_vr_vp_6252_sw_h_flip(cb);
        _va2_vr_vp_6252_sw_v_flip(cb);
      }
      else if ((sw_rotate == 0) && (sw_flip == KAL_TRUE))
      {
        _va2_vr_vp_6252_sw_h_flip(cb);
      }
      else if ((sw_rotate == 180) && (sw_flip == KAL_TRUE))
      {
        _va2_vr_vp_6252_sw_v_flip(cb);
      }
    }
#endif
    break;

  case VIDEO_PARAM_RENDERER_ROTATE_FLIP: /**< arg type: va2_video_renderer_rotate_flip_t* */
    kal_mem_cpy(pParam, &(cb->rotate_flip), sizeof(va2_video_renderer_rotate_flip_t));
    break;

  case VIDEO_PARAM_RENDERER_VIDEO_FRAME_ROTATE_FLIP: /**< arg type: va2_video_renderer_rotate_flip_t* */
    kal_mem_cpy(pParam, &(cb->video_frame_rotate_flip), sizeof(va2_video_renderer_rotate_flip_t));
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
                    &(cb->dst_fb_start_addr_array[dst_start_addr->u2_index]),
                    sizeof(VA2_FRAME_BUFFER_ADDRESS_T));
      }
      else
      {
        iRet = VIDEO_ERROR_INPUT_PARAM_ERROR;
      }
    }
    break;

  case VIDEO_CONFIG_RENDERER_POST_PROCESS: /**< arg type: va2_video_renderer_post_process_config_t* */
    kal_mem_cpy(pParam, &(cb->post_process), sizeof(va2_video_renderer_post_process_config_t));
    break;

  default:
    //ASSERT(0);
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
_va2_vr_vp_6253_set_parameter(
  VIDEO_PARAM_TYPE_T eCmd,
  void *pParam)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6253_cb;
  VIDEO_STATE_TYPE_T state;
  VIDEO_ERROR_TYPE_T i4Ret = VIDEO_ERROR_UNDEFINED;

  kal_take_sem(cb->vr_sema_vrstate_sync, KAL_INFINITE_WAIT);

  state = cb->state.eState;
  va2_vr_add_trace(&_va2_vr_vp_6253_debug_trace[0], VA2_VR_API_________SET_PARAMETER, (kal_uint32) eCmd);

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
            i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
            break;
          }

#if (defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252))
          if (VIDEO_RENDERER_COLOR_PACKED_UYVY422 != *color_format)
#else
          if (VIDEO_RENDERER_COLOR_RGB565 != *color_format)
#endif
          {
            i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
            break;
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
            i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
            break;
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
            i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
            break;
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
            i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
            break;
          }

          if ((KAL_TRUE == *trigger_display) ||
              (KAL_FALSE == *trigger_display))
          {
            cb->trigger_display = *trigger_display;
          }
          else
          {
            i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
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
            i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
            break;
          }

          if ((KAL_TRUE == *disable_dc_mode) ||
              (KAL_FALSE == *disable_dc_mode))
          {
            cb->disable_dcmode = *disable_dc_mode;
          }
          else
          {
            i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
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
            i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
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
            i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
            break;
          }

          if ((VIDEO_RENDERER_RENDER_MODE_FULL_CONTROL == *render_mode) ||
              (VIDEO_RENDERER_RENDER_MODE_STRETCH_TO_WINDOW == *render_mode))
          {
            cb->render_mode = *render_mode;
          }
          else if ((VIDEO_RENDERER_RENDER_MODE_TOUCH_WINDOW_FROM_INSIDE == *render_mode) ||
                   (VIDEO_RENDERER_RENDER_MODE_TOUCH_WINDOW_FROM_OUTSIDE == *render_mode))
          {
#if defined(VA2_RENDER_MODE_TOUCH_FROM_INSIDE_SUPPORTED) || defined(VA2_RENDER_MODE_TOUCH_FROM_OUTSIDE_SUPPORTED)
            // currently we cannot support this render mode yet!
            cb->render_mode = *render_mode;
#else
            i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
            break;
#endif
          }
          else
          {
            i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
            break;
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
        i4Ret = VIDEO_ERROR_NONE;
        break;

      case VIDEO_PARAM_RENDERER_ROTATE_FLIP: /**< arg type: va2_video_renderer_rotate_flip_t* */
        {
          va2_video_renderer_rotate_flip_t *display_rotate_flip = (va2_video_renderer_rotate_flip_t*) pParam;
      
          if (NULL == display_rotate_flip)
          {
            i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
            break;
          }
      
          if ((0 != display_rotate_flip->u2_cw_rotate_angle) &&
              (90 != display_rotate_flip->u2_cw_rotate_angle) &&
              (180 != display_rotate_flip->u2_cw_rotate_angle) &&
              (270 != display_rotate_flip->u2_cw_rotate_angle))
          {
            i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
            break;
          }
      
          if ((KAL_TRUE != display_rotate_flip->b_flip) &&
              (KAL_FALSE != display_rotate_flip->b_flip))
          {
            i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
            break;
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
            i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
            break;
          }
      
          if ((0 != video_frame_rotate_flip->u2_cw_rotate_angle) &&
              (90 != video_frame_rotate_flip->u2_cw_rotate_angle) &&
              (180 != video_frame_rotate_flip->u2_cw_rotate_angle) &&
              (270 != video_frame_rotate_flip->u2_cw_rotate_angle))
          {
            i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
            break;
          }
      
          if ((KAL_TRUE != video_frame_rotate_flip->b_flip) &&
              (KAL_FALSE != video_frame_rotate_flip->b_flip))
          {
            i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
            break;
          }
      
          cb->video_frame_rotate_flip.u2_cw_rotate_angle = video_frame_rotate_flip->u2_cw_rotate_angle;
          cb->video_frame_rotate_flip.b_flip = video_frame_rotate_flip->b_flip;
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
          i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
          break;
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
          i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
          break;
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
          i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
          break;
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
          i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
          break;
        }

        if (KAL_TRUE == src_clip->b_clip_enable)
        {
          if (src_clip->u4_clip_top > src_clip->u4_clip_bottom)
          {
            i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
            break;
          }
          if (src_clip->u4_clip_left > src_clip->u4_clip_right)
          {
            i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
            break;
          }
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
          i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
          break;
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
          i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
          break;
        }

        if (KAL_TRUE == dst_clip->b_clip_enable)
        {
          if (dst_clip->u4_clip_top > dst_clip->u4_clip_bottom)
          {
            i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
            break;
          }
          if (dst_clip->u4_clip_left > dst_clip->u4_clip_right)
          {
            i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
            break;
          }
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
          i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
          break;
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
          i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
          break;
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

          #if defined(CONTOUR_IMPROVEMENT_MT6253)
          cb->u4Fps = (1000/(cb->u4FramePeriodInMS));
          #endif
        }
        i4Ret = VIDEO_ERROR_NONE;
        break;

      #if defined(CONTOUR_IMPROVEMENT_MT6253)
      case VIDEO_CONFIG_RENDERER_DECODE_TIME: /**< arg type: kal_uint32* */
        {
          kal_uint32 *u4Time = (kal_uint32 *) pParam;

          cb->u4DecodingTime = *u4Time;
        }
        i4Ret = VIDEO_ERROR_NONE;
        break;
      #endif

      case VIDEO_CONFIG_RENDERER_BYPASS_HW_LAYER_SRC_RECT:
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
  return i4Ret;
}

static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6253_empty_this_buffer(
  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6253_cb;
  kal_uint32 u4Flags = 0;

  //  0.  parameter check and execution context check
  if ((NULL == prBuffHeader) ||
      (NULL == prBuffHeader->pu1Buffer) ||
      (NULL == prBuffHeader->pPrivateData))
  {
    return VIDEO_ERROR_INPUT_PARAM_ERROR; // incorrect param
  }
  //  0.5 cannot be invoked in NU+ LISR
  if (KAL_TRUE == kal_if_lisr())
  {
    return VIDEO_ERROR_INPUT_PARAM_ERROR; // cannot be invoked in NU+ LISR
  }

  if (KAL_FALSE == kal_if_hisr())
  {
    kal_mem_cpy((void*) &(_va2_comp_video_renderer_rNewBuffHeader), prBuffHeader, sizeof(VIDEO_BUFFERHEADER_TYPE_T));
    kal_retrieve_eg_events(cb->EventID, TASK_WAIT_HISR_SET, KAL_AND_CONSUME, &u4Flags, KAL_NO_SUSPEND);
    visual_active_hisr(VISUAL_RENDERER_EMPTY_THIS_BUFFER_HISR_ID);
    kal_retrieve_eg_events(cb->EventID, TASK_WAIT_HISR_SET, KAL_AND_CONSUME, &u4Flags, KAL_SUSPEND);
    return VIDEO_ERROR_NONE;
  }

  _va2_vr_vp_6253_empty_this_buffer_real(prBuffHeader);

  return VIDEO_ERROR_NONE;
}


static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6253_empty_this_buffer_real(
  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
  va2_util_buf_hdr_q_item_t *q_item;
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6253_cb;

#if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("REB", (SA_ACTION_T) 1);
#endif  // #if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)

  va2_vr_add_trace(&_va2_vr_vp_6253_debug_trace[0], VA2_VR_API_________EMPTY_THIS_BUFFER, (kal_uint32) prBuffHeader->pu1Buffer);

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

#if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("REB", (SA_ACTION_T) 0);
#endif  // #if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)

  if (KAL_TRUE == cb->bypass)
  {
    // For bypass mode, just keep one frame at most.
    va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
    va2_util_buf_hdr_remove_all_q_items(&(cb->vr_q_handle.to_be_returned_q), &(cb->vr_q_handle.to_be_processed_q));
    cb->funcs.try_to_return_buf_hdrs(cb);

    return VIDEO_ERROR_NONE;
  }

  switch(cb->state.eState)
  {
    case VIDEO_STATE_RUN:
      {
        kal_bool busy;

        idp_video_decode_is_busy(_va2_comp_video_renderer_idp_key, &busy);

        if (KAL_FALSE == busy)
        {
          va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
          va2_vr_add_trace(&_va2_vr_vp_6253_debug_trace[0], VA2_VR_API_________EMPTY_THIS_BUFFER__TRIGGER_HW, (kal_uint32) (cb->vr_q_handle.curr_dspl_buf_hdr));
          _va2_vr_vp_6253_render_display_frame_buffer(cb, KAL_FALSE);
        }
        else
        {
          va2_vr_add_trace(&_va2_vr_vp_6253_debug_trace[0], VA2_VR_API_________EMPTY_THIS_BUFFER__ENQUEUE_ONLY, (kal_uint32) (cb->vr_q_handle.to_be_processed_q.tail));
        }
#if defined(APPLY_NEW_REDRAW_MECHANISM)
        cb->u4LastSrcRenderTimestamp = drv_get_current_time();
#endif
      }
      break;

    case VIDEO_STATE_STOP:
      //ASSERT(0); // Bypass maybe late set, because empty_this_buffer run in hisr and interrup task set bypass
      break;

    default:
      ASSERT(0); // component in incorrect state...
      break;
  } // end of switch(cb->state.eState)

  return VIDEO_ERROR_NONE;
}

/**
 *  @status OK
 *  @common VR
 */
static VIDEO_ERROR_TYPE_T
_va2_vr_vp_6253_set_callbacks(
  VIDEO_CALLBACK_TYPE_T *prCallback)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6253_cb;
  VIDEO_ERROR_TYPE_T i4Ret;

  kal_take_sem(cb->vr_sema_vrstate_sync, KAL_INFINITE_WAIT);
  i4Ret = va2_vr_set_callbacks(&_va2_vr_vp_6253_cb, prCallback);
  kal_give_sem(cb->vr_sema_vrstate_sync);

  return i4Ret;
}

/**
 *  @status OK
 *  @remark this function could only be invoked when in CLOSE state.
 */
VIDEO_ERROR_TYPE_T
_va2_vr_vp_6253_deinit(void)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vp_6253_cb;
  VIDEO_ERROR_TYPE_T i4Ret;

#if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("DIN", (SA_ACTION_T) 1);
#endif  // #if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)

  kal_take_sem(cb->vr_sema_vrstate_sync, KAL_INFINITE_WAIT);
  i4Ret = va2_vr_deinit(&_va2_vr_vp_6253_cb);
  va2_vr_init_trace(0, NULL);
  kal_give_sem(cb->vr_sema_vrstate_sync);

#if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("DIN", (SA_ACTION_T) 0);
#endif  // #if defined(VA2_VR_VP_6253_ENABLE_SWLA_TRACE)

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
va2_video_renderer_vp_mt6253_get_handle(
  VA2_VIDEO_RENDERER_TYPE_T e_type)
{
#if defined(__MTK_TARGET__)
  VIDEO_COMPONENT_TYPE_T *pr_video_renderer_comp = NULL;
  //VIDEO_ERROR_TYPE_T error_code = VIDEO_ERROR_NONE;

  switch (e_type)
  {
  case VIDEO_RENDERER_VIDEO_THUMBNAIL:
  case VIDEO_RENDERER_MJPG_THUMBNAIL:
    pr_video_renderer_comp = &_va2_vr_vp_6253_primitives;
    _va2_vr_vp_6253_cb.renderer_type = VIDEO_RENDERER_VIDEO_THUMBNAIL;
    break;

  case VIDEO_RENDERER_VIDEO_PLAYBACK:
  case VIDEO_RENDERER_MJPG_PLAYBACK:
    pr_video_renderer_comp = &_va2_vr_vp_6253_primitives;
    _va2_vr_vp_6253_cb.renderer_type = VIDEO_RENDERER_VIDEO_PLAYBACK;
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
va2_video_renderer_vp_mt6253_release_handle(
  VIDEO_COMPONENT_TYPE_T *pr_handle)
{
#if defined(__MTK_TARGET__)
  VIDEO_ERROR_TYPE_T error_code = VIDEO_ERROR_NONE;

  if ((NULL == pr_handle) ||
      (&_va2_vr_vp_6253_primitives != pr_handle) ||
      (NULL == pr_handle->pfnDeInit))
  {
    return VIDEO_ERROR_INPUT_PARAM_ERROR; // incorrect param
  }
  error_code = pr_handle->pfnDeInit();
  return error_code;
#else   // #if defined(__MTK_TARGET__)
  return VIDEO_ERROR_DEINIT_ERROR;
#endif  // #if defined(__MTK_TARGET__)
}

#endif  // #if defined(VA2_VIDEO_RENDERER_VP_MT6253)
#endif	// #if defined(__VIDEO_ARCHI_V2__)
/// @}

