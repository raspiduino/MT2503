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
 *    va2_video_renderer_vt_mt6256_e2.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    OpenMAX-like Video Renderer of Video Architecture V2 for 
 *    video telephony playback on MT6256 platform.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
/// \ingroup va2_video_renderer_vt_mt6256
/// @{
#if defined(__VIDEO_ARCHI_V2__)

/****************************************************************************
 * include directives
 ****************************************************************************/
/******* main header file *******************/
#include "lcd_sw_inc.h"
#include "va2_video_renderer_vt_mt6256_e2.h"

#if defined(VA2_VIDEO_RENDERER_VT_MT6256_E2)

/******* Kernal abstraction *****************/
#include "kal_release.h"
/******* VA2 common *************************/
#include "video_types_v2.h"
#include "video_comm_component_v2.h"
#include "video_buffer_management_v2.h"
/******* VA2 Video Renderer Component *******/
#include "va2_comp_video_renderer.h"
#include "va2_video_renderer_common.h"
#include "va2_util_buffer_header_queue.h"
#include "va2_util_misc.h"
#include "va2_video_renderer_vt.h"
#include "va2_video_renderer_mem_req.h"
/******* driver common **********************/
//#include "drv_features.h"
#include "drv_comm.h"
/******* MDP driver *************************/
#include "img_common_enum.h"
#include "idp_video_call_decode.h"
/******* LCD driver *************************/
#include "Lcd_if.h"
#include "lcd_if_hw.h" // TODO:[3] check inc path
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

#include "kal_trace.h"
#include "med_trc.h"
/****************************************************************************
 * external symbols
 ****************************************************************************/
extern void 
LCD_config_fullvideo_layer_address(
  kal_uint32 layer, 
  kal_uint32 addr);

/****************************************************************************
 * local type definitions and macros
 ****************************************************************************/
//#define VA2_VR_VT_6256_MAX_BH_COUNT             (16)
// TODO: check this size and color format
//#define VA2_VR_VT_6256_DISPLAY_BUFFER_SIZE      (320*240*2) // QVGA RGB565 or UYVY422 color format
#define VA2_VR_VT_6256_RENDER_TIME_MAX          (1100) // (32768/1000)*33.3 ~ 1091

#define VA2_VR_VT_6256_DEBUG_TRACE_SIZE         (64)

//#define VIDEO_RENDER_VT_TRC
/****************************************************************************
 * declarations
 ****************************************************************************/
#if defined(__MTK_TARGET__)

static VIDEO_ERROR_TYPE_T 
_va2_vr_vt_6256_init(void);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vt_6256_send_command(
  VIDEO_COMMAND_TYPE_T eCmd, 
  kal_uint32 u4Param);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vt_6256_get_parameter(
  VIDEO_PARAM_TYPE_T eCmd, 
  void *pParam);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vt_6256_set_parameter(
  VIDEO_PARAM_TYPE_T eCmd, 
  void *pParam);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vt_6256_use_buffer(
  kal_uint8 *pu1Buff, 
  kal_uint32 u4Size);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vt_6256_empty_this_buffer(
  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vt_6256_empty_this_buffer_real(
  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader);
  
static VIDEO_ERROR_TYPE_T 
_va2_vr_vt_6256_fill_this_buffer(
  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vt_6256_set_callbacks(
  VIDEO_CALLBACK_TYPE_T *prCallback);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vt_6256_deinit(void);

static kal_uint32 
_va2_vr_vt_6256_render_display_frame_buffer(
  va2_comp_video_renderer_cb_t *cb, 
  kal_bool blocking);

static kal_bool 
_va2_vr_vt_6256_check_params_configs(
  va2_comp_video_renderer_cb_t *cb);

static kal_bool 
_va2_vr_vt_6256_config_idp_by_render_mode(
  va2_comp_video_renderer_cb_t *cb, 
  VA2_VIDEO_FRAME_T *video_frame);

static void
_va2_vr_vt_6256_display_timer_hdlr(
  void *param);

static void
_va2_vr_vt_6256_idp_frame_done_cb(
  void *param);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vt_6256_t01_close_to_init(
  va2_comp_video_renderer_cb_t *cb);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vt_6256_t03_init_to_idle(
  va2_comp_video_renderer_cb_t *cb);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vt_6256_t04_idle_to_run(
  va2_comp_video_renderer_cb_t *cb);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vt_6256_t05_run_to_stop(
  va2_comp_video_renderer_cb_t *cb);

static VIDEO_ERROR_TYPE_T 
_va2_vr_vt_6256_t06_stop_to_run(
  va2_comp_video_renderer_cb_t *cb);    

static VIDEO_ERROR_TYPE_T 
_va2_vr_vt_6256_t10_idle_to_close(
  va2_comp_video_renderer_cb_t *cb);

//static void 
//_va2_vr_vt_6256_lcd_frame_done_cb(
//  void *param);

#endif  // #if defined(__MTK_TARGET__)

/****************************************************************************
 * local variables
 ****************************************************************************/
#if defined(__MTK_TARGET__)

/**
 *  @status OK
 */
static VIDEO_COMPONENT_TYPE_T _va2_vr_vt_6256_primitives = 
{
    _va2_vr_vt_6256_init
  , _va2_vr_vt_6256_send_command
  , _va2_vr_vt_6256_get_parameter
  , _va2_vr_vt_6256_set_parameter
  , _va2_vr_vt_6256_use_buffer
  , _va2_vr_vt_6256_empty_this_buffer
  , _va2_vr_vt_6256_fill_this_buffer
  , _va2_vr_vt_6256_set_callbacks
  , _va2_vr_vt_6256_deinit
};

static struct va2_comp_video_renderer_cb _va2_vr_vt_6256_cb = 
  {
    {
      _va2_vr_vt_6256_t01_close_to_init, 
      va2_vr_t02_init_to_close, 
      _va2_vr_vt_6256_t03_init_to_idle, 
      _va2_vr_vt_6256_t04_idle_to_run,
      _va2_vr_vt_6256_t05_run_to_stop, 
      _va2_vr_vt_6256_t06_stop_to_run,
      va2_vr_t07_run_to_idle, 
      va2_vr_t08_stop_to_idle, 
      va2_vr_t09_idle_to_init, 
      _va2_vr_vt_6256_t10_idle_to_close, 
      va2_vr_t11_stop_to_close, 
      va2_vr_t12_idle_to_idle,
      va2_vr_try_to_return_buffer_headers, 
      _va2_vr_vt_6256_check_params_configs, 
      _va2_vr_vt_6256_config_idp_by_render_mode, 
      (va2_vr_dspl_timer_hdlr_func_t) _va2_vr_vt_6256_display_timer_hdlr, 
      (va2_vr_hw_frame_done_cb_func_t) _va2_vr_vt_6256_idp_frame_done_cb, 
      _va2_vr_vt_6256_render_display_frame_buffer, 
      NULL,
      NULL
    }, 
    VIDEO_RENDERER_VIDEO_TELEPHONY, 
    0, 
    0, 
    {0}, 
    KAL_FALSE
  };

#if defined(DRV_DISPLAY_DRIVER_V2)
static WFCDevice _va2_vr_vt_6256_ddv2_dev = WFC_INVALID_HANDLE;
static WFCContext _va2_vr_vt_6256_ddv2_ctx = WFC_INVALID_HANDLE;
static WFCElement _va2_vr_vt_6256_ddv2_element = WFC_INVALID_HANDLE;
static WFCSource _va2_vr_vt_6256_ddv2_src = WFC_INVALID_HANDLE;
static WFCSource _va2_vr_vt_6256_ddv2_img_src = WFC_INVALID_HANDLE;
static OWFNativeStreamType _va2_vr_vt_6256_ddv2_stream = OWF_INVALID_HANDLE;
static kal_uint32 _va2_vr_vt_6256_dspl_fbs[3][2] = { 0 };
static kal_bool _va2_vr_vt_6256_disp_buffer_init = KAL_FALSE;

#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)

/**
 *  The control of IDP
 *  @remark set it back to 0 when IDP is closed.
 *  @common none
 */
//static kal_uint32 _va2_vr_vt_6256_idp_key = 0;

/****************************************************************************
 * External References
 ****************************************************************************/
extern kal_bool   _va2_comp_vr_have_config_lcd;
extern kal_uint32 _va2_comp_vr_triggered_lcd_id_this_time;

#define CCASSERT(predicate) _x_CCASSERT_LINE(predicate, __LINE__)
#define _x_CCASSERT_LINE(predicate, line) typedef char constraint_violated_on_line_##line[2*((predicate)!=0)-1];

/**
 *  This variable is used to control display double buffering...
 *  
 */
static volatile kal_uint32 _va2_vr_vt_6256_curr_dspl_frame_buf_idx = 0;
static kal_bool _va2_vr_vt_6256_bypass_config_src_rect = KAL_FALSE;

static va2_vr_debug_trace_entry_t _va2_vr_vt_6256_debug_trace[VA2_VR_VT_6256_DEBUG_TRACE_SIZE] = {0};

#endif  // #if defined(__MTK_TARGET__)

/****************************************************************************
 * local function bodies
 ****************************************************************************/
#if defined(__MTK_TARGET__)

_va2_vr_vt_6256_lcd_is_busy(void)
{
  // [MAUI_02234600] When TE is enabled on LCD, LCD may look like not busy but actaully waiting for TE signal...
#if defined(__SYNC_LCM_HW_SUPPORT__)
  if ((LCD_IS_RUNNING) || 
      (LCD_WAIT_TE))
#else   // #if defined(__SYNC_LCM_HW_SUPPORT__)
  if (LCD_IS_RUNNING)
#endif  // #if defined(__SYNC_LCM_HW_SUPPORT__)
  {
    return KAL_TRUE;
  }
  else
  {
    return KAL_FALSE;
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
  #if defined(VA2_VR_VT_6256_ENABLE_SWLA_TRACE)
/* under construction !*/
  #endif  // #if defined(VA2_VR_VT_6256_ENABLE_SWLA_TRACE)
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
    #if defined(VA2_VR_VT_6256_ENABLE_SWLA_TRACE)
/* under construction !*/
    #endif  // #if defined(VA2_VR_VT_6256_ENABLE_SWLA_TRACE)
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
    #if defined(VA2_VR_VT_6256_ENABLE_SWLA_TRACE)
/* under construction !*/
    #endif  // #if defined(VA2_VR_VT_6256_ENABLE_SWLA_TRACE)
/* under construction !*/
/* under construction !*/
  #if defined(VA2_VR_VT_6256_ENABLE_SWLA_TRACE)
/* under construction !*/
  #endif  // #if defined(VA2_VR_VT_6256_ENABLE_SWLA_TRACE)
/* under construction !*/
#endif //#if 0

#if defined(DRV_DISPLAY_DRIVER_V2)
void _va2_vr_vt_6256_wfc_frame_done_cb(
  WFCContextEventTypeMTK event, 
  void* param)
{
  //_va2_vr_vt_6256_lcd_frame_done_cb(param);
}
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)

static void
_va2_vr_vt_6256_trigger_display(
  kal_uint32 dspl_fb, 
  va2_comp_video_renderer_cb_t *cb)
{
#if defined(DRV_DISPLAY_DRIVER_V2)
//  if ((KAL_TRUE == cb->trigger_display) && 
//      (OWF_INVALID_HANDLE != _va2_vr_vt_6256_ddv2_stream))
    if (OWF_INVALID_HANDLE != _va2_vr_vt_6256_ddv2_stream)
  {
    OWFNativeStreamBuffer buf;
    if (dspl_fb == _va2_vr_vt_6256_dspl_fbs[0][0])
    {
      buf = (OWFNativeStreamBuffer) _va2_vr_vt_6256_dspl_fbs[0][1];
      owfNativeStreamReleaseWriteBuffer(_va2_vr_vt_6256_ddv2_stream, 
                                      buf/* (OWFNativeStreamBuffer) 0x100 */, 
                                      NULL /* (EGLDisplay) */, 
                                      NULL /* (EGLSyncKHR) */);
      _va2_vr_vt_6256_dspl_fbs[0][1] = 0x0;
      if (0x0 == _va2_vr_vt_6256_dspl_fbs[1][1])
      {
        _va2_vr_vt_6256_dspl_fbs[1][1] = (kal_uint32) owfNativeStreamAcquireWriteBuffer(_va2_vr_vt_6256_ddv2_stream);
      }
    }
    else
    {
      buf = (OWFNativeStreamBuffer) _va2_vr_vt_6256_dspl_fbs[1][1];
      owfNativeStreamReleaseWriteBuffer(_va2_vr_vt_6256_ddv2_stream, 
                                      buf/* (OWFNativeStreamBuffer) 0x100 */, 
                                      NULL /* (EGLDisplay) */, 
                                      NULL /* (EGLSyncKHR) */);

      _va2_vr_vt_6256_dspl_fbs[1][1] = 0x0;
      if (0x0 == _va2_vr_vt_6256_dspl_fbs[0][1])
      {
        _va2_vr_vt_6256_dspl_fbs[0][1] = (kal_uint32) owfNativeStreamAcquireWriteBuffer(_va2_vr_vt_6256_ddv2_stream);
      }
    }
  }
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)
}

static kal_bool 
_va2_vr_vt_6256_clear_uyvy_buffer_black(kal_uint32* pu4Addr, kal_uint32 u4Size)	
{
     kal_uint32 i;
     
     for (i = 0; i < (u4Size >> 2); i++)
     {
          *(pu4Addr + i) = 0x00800080;
     }

     return KAL_TRUE;
}

/**
 *  \remarks After this function, the rotation/flip of Video Renderer might be changed...
 */
static void 
_va2_vr_vt_6256_config_n_activate_ddv2( 
  va2_comp_video_renderer_cb_t *cb)
{
#if defined(DRV_DISPLAY_DRIVER_V2)
  kal_check_stack();

  // TODO: [m] Which variable can decide if display needs to work? 
  {
    WFCint displayInputWidth, displayInputHeight; // The output width/height of MM...
    //WFCRotation layerRotation;
    
    _va2_vr_vt_6256_ddv2_dev = (WFCDevice) cb->display_surface.dspl_dev_handle;
    _va2_vr_vt_6256_ddv2_ctx = (WFCContext) cb->display_surface.dspl_ctx_handle;
    _va2_vr_vt_6256_ddv2_element = (WFCElement) cb->display_surface.dspl_element_handle;

    if ((WFC_INVALID_HANDLE == _va2_vr_vt_6256_ddv2_dev) || 
        (WFC_INVALID_HANDLE == _va2_vr_vt_6256_ddv2_ctx) || 
        (WFC_INVALID_HANDLE == _va2_vr_vt_6256_ddv2_element))
    {
      VRNDRR_DD_ASSERT(0); // TODO: [m] remove this after IT done...need error handling...
    }

    // Check if this element is a video layer...for debug only and can be removed for last QC stage...
    if (WFC_FALSE == wfcGetElementAttribi(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_element, WFC_ELEMENT_VIDEO_LAYER_MTK))
    {
      // TODO: [m] Make GDI add this line...
      wfcMMSetElementAttribi(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_element, WFC_ELEMENT_VIDEO_LAYER_MTK, WFC_TRUE);
      //VRNDRR_DD_ASSERT(0);
    }

    if (KAL_TRUE == cb->trigger_display)
    {
      WFCint array[3];
      array[0] = (WFCint) WFC_AUTONOMOUS_SYNC_TO_ELEMENT;
      array[1] = (WFCint) 30; // TODO: [m] tamp value for testing...
      array[2] = (WFCint) _va2_vr_vt_6256_ddv2_element;
      
      wfcMMSetContextAttribiv(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_ctx, WFC_CONTEXT_AUTONOMOUS_SYNC_TRIGGER_MTK, 3, &array[0]);
      wfcMMSetContextAttribi(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_ctx, WFC_CONTEXT_CURRENT_REFRESH_RATE_MTK, 0);
    }

    // Derive the output width/height of MDP, which might be the input width height of Display
    // Need to take rotation into consideration later...
    displayInputWidth = cb->dst_size.u4_width;
    displayInputHeight = cb->dst_size.u4_height;

    // Config Display Rotation angle & flip
    {
      //WFCRotation layerRotation;
      //WFCboolean layerFlip;

      if (0 != cb->rotate_flip.u2_cw_rotate_angle)
      {
        //VRNDRR_DD_ASSERT(0); // Should not happen since HW layer...but this will be removed...
      }
      
      //layerRotation = (WFCRotation) 
      //  wfcGetElementAttribi(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_element, WFC_ELEMENT_SOURCE_ROTATION);
      
      //layerFlip = (WFCboolean)
      //  wfcGetElementAttribi(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_element, WFC_ELEMENT_SOURCE_FLIP);

      wfcMMSetElementAttribi(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_element, WFC_ELEMENT_SOURCE_ROTATION, WFC_ROTATION_0);
      //wfcMMSetElementAttribi(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_element, WFC_ELEMENT_SOURCE_FLIP, WFC_FALSE);
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
      //if (layerRotation!=WFC_ROTATION_0)
      if (_va2_vr_vt_6256_bypass_config_src_rect == KAL_FALSE)
      {
        if (0 != cb->rotate_flip.u2_cw_rotate_angle)
        {
          wfcGetElementAttribiv(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_element, WFC_ELEMENT_SOURCE_RECTANGLE, 4, &srcRect[0]);
    
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
          wfcMMSetElementAttribiv(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_element, WFC_ELEMENT_SOURCE_RECTANGLE, 4, &srcRect[0]);
       }
     }
     else
     {
       _va2_vr_vt_6256_bypass_config_src_rect = KAL_FALSE;
     }  
     // wfcMMSetElementAttribi(_va2_vr_vp_6268_ddv2_dev, _va2_vr_vp_6268_ddv2_element, WFC_ELEMENT_SOURCE_ROTATION, WFC_ROTATION_0);
    
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
    // TODO: [m] This is only for testing and should be removed.
    //wfcInsertElement(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_element, WFC_INVALID_HANDLE);

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
        VRNDRR_DD_ASSERT(0); // TODO: [o] Need error handling...
        imageFormat.pixelFormat = OWF_IMAGE_RGB565;
        break;
      }

      _va2_vr_vt_6256_dspl_fbs[0][0] = bufs[0] = cb->dst_fb_addr_array[0].u4_fb_addr_plane0;
      _va2_vr_vt_6256_dspl_fbs[1][0] = bufs[1] = cb->dst_fb_addr_array[1].u4_fb_addr_plane0;
      // TODO: [m] When to destroy the stream? Where is the exit function?
      // TODO: [o] magical number here...
      _va2_vr_vt_6256_ddv2_stream = 
        owfNativeStreamCreateImageStreamEx((OWFint) displayInputWidth, 
                                           (OWFint) displayInputHeight, 
                                           &imageFormat, (OWFint) 2, (void**) &bufs[0]);

      // This code segment is used to do buffer control...
      {
        void * bufPtr;
        OWFNativeStreamBuffer buf;

        buf = owfNativeStreamAcquireWriteBuffer(_va2_vr_vt_6256_ddv2_stream);
        bufPtr = owfNativeStreamGetBufferPtr(_va2_vr_vt_6256_ddv2_stream, buf);
        VRNDRR_DD_ASSERT(NULL != bufPtr);

        if (_va2_vr_vt_6256_dspl_fbs[0][0] == (kal_uint32) bufPtr)
        {
          _va2_vr_vt_6256_dspl_fbs[0][1] = (kal_uint32) buf;
          _va2_vr_vt_6256_dspl_fbs[1][1] = owfNativeStreamAcquireWriteBuffer(_va2_vr_vt_6256_ddv2_stream);
        }
        else
        {
          _va2_vr_vt_6256_dspl_fbs[1][1] = (kal_uint32) buf;
          _va2_vr_vt_6256_dspl_fbs[0][1] = owfNativeStreamAcquireWriteBuffer(_va2_vr_vt_6256_ddv2_stream);
        }
      }

      _va2_vr_vt_6256_ddv2_src = wfcCreateSourceFromStream(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_ctx, (WFCNativeStreamType) _va2_vr_vt_6256_ddv2_stream, NULL);

      // TODO: [m] Need an API to set buffers into the stream...

      if (WFC_INVALID_HANDLE == _va2_vr_vt_6256_ddv2_src)
      {
        VRNDRR_DD_ASSERT(0); // TODO: [m] remove this after IT done...need error handling...
      }
    }

    // Set Element source
    wfcMMSetElementAttribi(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_element, WFC_ELEMENT_SOURCE, (WFCint) _va2_vr_vt_6256_ddv2_src);

    // TODO: [m] If camera preview only uses double display frame buffer, DDv2 needs to sync to content provider...since camera cannot wait...

    // Add cb function
    {
      WFCint array[4];
      array[0] = (WFCint) WFC_CONTEXT_EVENT_COMPOSITION_FINISH_MTK;
      array[1] = (WFCint) _va2_vr_vt_6256_wfc_frame_done_cb;
      array[2] = (WFCint) cb;
      array[3] = (WFCint) WFC_TRUE;
      wfcMMSetContextAttribiv(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_ctx, WFC_CONTEXT_CALLBACK_MTK, 4, &array[0]);
    }

    // Commmit
    //wfcCommit(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_ctx, WFC_TRUE);
    wfcMMCommit(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_ctx, _va2_vr_vt_6256_ddv2_element, WFC_COMMIT_CONTEXT_AND_ELEMENT);                

  //MAUI_02912771 first time trigger display is needed only in full-duplex mode
  if (KAL_FALSE == cb->trigger_display)
  {
    //draw the current display frame buffer to black
    if (KAL_FALSE == _va2_vr_vt_6256_disp_buffer_init)
    {
      kal_uint32 addr;
      kal_uint32 size = cb->dst_fb_size.u4_width * 
                        cb->dst_fb_size.u4_height * 
                        va2_util_get_bpp(cb->dst_color_format);
      if (0x0 != (addr = cb->dst_fb_start_addr_array[_va2_vr_vt_6256_curr_dspl_frame_buf_idx^0x1].u4_fb_addr_plane0))
      {
        if (VIDEO_RENDERER_COLOR_RGB565 == cb->dst_color_format)
        {
          kal_mem_set((void*) addr, 0x0, size);  //black for RGB565
        }
        else if (VIDEO_RENDERER_COLOR_PACKED_UYVY422 == cb->dst_color_format)
        {
          if (KAL_FALSE == _va2_vr_vt_6256_clear_uyvy_buffer_black((kal_uint32*)addr, size))  //black for UYVY422 
          {
            ASSERT(0);
          }
        }
        else
        {
          ASSERT(0);
        }
      }
      _va2_vr_vt_6256_disp_buffer_init = KAL_TRUE;
    }

    //first time trigger display to confirm lcd won't bypass this video layer
    _va2_vr_vt_6256_trigger_display(
      cb->dst_fb_start_addr_array[_va2_vr_vt_6256_curr_dspl_frame_buf_idx^0x1].u4_fb_addr_plane0, 
      cb);  
  }
  
//    wfcActivate(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_ctx);
  }

  kal_check_stack();
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)
}

static void 
_va2_vr_vt_6256_stop_n_deactivate_ddv2( 
  va2_comp_video_renderer_cb_t *cb)
{
#if defined(DRV_DISPLAY_DRIVER_V2)
  kal_check_stack();
  // TODO: [m] Which variable can decide if display needs to work? 
  if (OWF_INVALID_HANDLE != _va2_vr_vt_6256_ddv2_stream)
  {
    if ((WFC_INVALID_HANDLE == _va2_vr_vt_6256_ddv2_dev) || 
        (WFC_INVALID_HANDLE == _va2_vr_vt_6256_ddv2_ctx) || 
        (WFC_INVALID_HANDLE == _va2_vr_vt_6256_ddv2_element))
    {
      VRNDRR_DD_ASSERT(0);
    }

    {
      WFCint array[4];
      array[0] = (WFCint) WFC_CONTEXT_EVENT_COMPOSITION_FINISH_MTK;
      array[1] = (WFCint) _va2_vr_vt_6256_wfc_frame_done_cb;
      array[2] = (WFCint) cb;
      array[3] = (WFCint) WFC_FALSE;
      wfcMMSetContextAttribiv(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_ctx, WFC_CONTEXT_CALLBACK_MTK, 4, &array[0]);
    }

/*
    //Restore rotation/flip inf. back to element
    {    
    WFCRotation layerRotation;
    WFCboolean layerFlip;
    
      switch (cb->rotate_flip.u2_cw_rotate_angle) 
      {
      case 0: 
        layerRotation = WFC_ROTATION_0;
        break;
      case 90: 
        layerRotation = WFC_ROTATION_90;
        break;
      case 180: 
        layerRotation = WFC_ROTATION_180;
        break; 
      case 270: 
        layerRotation = WFC_ROTATION_270;
        break;
      default: 
        VRNDRR_DD_ASSERT(0);
        break;
      }      

      layerFlip = (WFCboolean) cb->rotate_flip.b_flip;
      cb->rotate_flip.b_flip = KAL_FALSE;

      wfcMMSetElementAttribi(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_element, WFC_ELEMENT_SOURCE_ROTATION, layerRotation);
      wfcMMSetElementAttribi(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_element, WFC_ELEMENT_SOURCE_FLIP, layerFlip);
    }
    
  //Restore src/dst rect inf. back to element
  {
  WFCint displayInputWidth, displayInputHeight; // The output width/height of MM...
  	
    displayInputWidth = cb->dst_size.u4_width;
    displayInputHeight = cb->dst_size.u4_height;
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
      //Restore rotation angle to 0
      cb->rotate_flip.u2_cw_rotate_angle = 0;
    }
 
    // Config Display Source width/height (The output of MDP) and source clip/pitch
    {
      WFCint srcRect[4];
      srcRect[0] = 0;
      srcRect[1] = 0;
      srcRect[2] = displayInputWidth;
      srcRect[3] = displayInputHeight;
      wfcMMSetElementAttribiv(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_element, WFC_ELEMENT_SOURCE_RECTANGLE, 4, &srcRect[0]);
    }

    // Reconfig Display Destination Rect...only size but not X, Y offset...
    // Layer ROI offset does not change...use the setting from GDI...
    {
      WFCint dstRect[4] = {0};
      wfcGetElementAttribiv(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_element, WFC_ELEMENT_DESTINATION_RECTANGLE, 4, &dstRect[0]);
      dstRect[2] = displayInputWidth;
      dstRect[3] = displayInputHeight;
      wfcMMSetElementAttribiv(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_element, WFC_ELEMENT_DESTINATION_RECTANGLE, 4, &dstRect[0]);
    }
  }
*/

    //wfcMMSetElementAttribi(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_element, WFC_ELEMENT_SOURCE, WFC_INVALID_HANDLE);
    //wfcRemoveElement(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_element);
    //wfcMMCommit(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_ctx, _va2_vr_vt_6256_ddv2_element, WFC_COMMIT_CONTEXT_AND_ELEMENT);                

    {
      WFCint array[3];
      array[0] = (WFCint) WFC_AUTONOMOUS_SYNC_TO_TIMER;
      array[1] = (WFCint) 0;
      array[2] = (WFCint) 0;

      wfcMMSetContextAttribiv(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_ctx, WFC_CONTEXT_AUTONOMOUS_SYNC_TRIGGER_MTK, 3, &array[0]);
      wfcMMSetContextAttribi(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_ctx, WFC_CONTEXT_CURRENT_REFRESH_RATE_MTK, 30);
    }

    // Set an image source back to element
    {
    OWF_IMAGE image;
    OWF_PIXEL_FORMAT color_format = OWF_IMAGE_NOT_SUPPORTED;
    WFCint pixel_size = 0;
      // TODO: Add an image sourece
      if (_va2_vr_vt_6256_ddv2_img_src != WFC_INVALID_HANDLE)
      {
      wfcDestroySource(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_img_src);
      }
      // TODO: buffer address refer to CalDisplayFBs[?][1] == 0x0
      // TODO: fill in this structure 

#if 1
      // MAUI_02907500 always use second frame buffer for display image because first buffer can be used for get frame 
      // if last frame is 1st buffer, copy contain to 2nd buffer
      if (_va2_vr_vt_6256_dspl_fbs[1][1] == 0x0)
      {
      kal_uint8* dst_addr= (kal_uint8*)cb->dst_fb_start_addr_array[0].u4_fb_addr_plane0;
      kal_uint8* src_addr= (kal_uint8*)cb->dst_fb_start_addr_array[1].u4_fb_addr_plane0;
        kal_mem_cpy(dst_addr, src_addr, 
                   (cb->dst_fb_size.u4_width * cb->dst_fb_size.u4_height * va2_util_get_bpp(cb->dst_color_format)));
      }
      image.data = (void*)_va2_vr_vt_6256_dspl_fbs[0][0];
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
#endif

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
	
       _va2_vr_vt_6256_ddv2_img_src = wfcCreateSourceFromImage(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_ctx, (WFCHandle) &image, NULL);
       VRNDRR_DD_ASSERT(_va2_vr_vt_6256_ddv2_img_src != WFC_INVALID_HANDLE);
       wfcMMSetElementAttribi(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_element, WFC_ELEMENT_SOURCE, _va2_vr_vt_6256_ddv2_img_src);
       //wfcCommit(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_ctx, WFC_TRUE);
       wfcMMCommit(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_ctx, _va2_vr_vt_6256_ddv2_element, WFC_COMMIT_CONTEXT_AND_ELEMENT);                
    }

    //wfcDestroyElement(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_element);
    wfcDestroySource(_va2_vr_vt_6256_ddv2_dev, _va2_vr_vt_6256_ddv2_src);
    _va2_vr_vt_6256_ddv2_src = WFC_INVALID_HANDLE;

    _va2_vr_vt_6256_ddv2_element = WFC_INVALID_HANDLE;
    _va2_vr_vt_6256_ddv2_ctx = WFC_INVALID_HANDLE;
    _va2_vr_vt_6256_ddv2_dev = WFC_INVALID_HANDLE;
    
    owfNativeStreamDestroy(_va2_vr_vt_6256_ddv2_stream);
    _va2_vr_vt_6256_ddv2_stream = OWF_INVALID_HANDLE;

    kal_mem_set((void*) _va2_vr_vt_6256_dspl_fbs, 0x0, sizeof(kal_uint32)*3*2);
  }
  kal_check_stack();
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)
}

/**
 *  @status OK
 *  @todo customize for MT6256 VT
 *  @common VR.VT
 */
static kal_bool 
_va2_vr_vt_6256_check_params_configs(
  va2_comp_video_renderer_cb_t *cb)
{
  kal_bool fgRet = KAL_TRUE;
  ASSERT(NULL != cb);

  //VA2_VIDEO_RENDERER_COLOR_FORMAT_T         src_color_format;
  // TODO: Note this! Cannot remove...here to check if ever set
  if (VIDEO_RENDERER_COLOR_4X4_BLOCK_YUV420 != cb->src_color_format)
#if 0   // only 4x4 block based YUV420 is allowed in MT6256 VT
/* under construction !*/
/* under construction !*/
#endif  // #if 0
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
    // Ignore this problem...since this is not supported on MT6256
    //ASSERT(0);
    //return KAL_FALSE;
#if 0   // src clip is unsupported in MT6256 VT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // #if 0
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
#if 0
/* under construction !*/
#else   // only RGB565 is allowed in MT6256 VT...
  if ((VIDEO_RENDERER_COLOR_DEFAULT_ERR == cb->dst_color_format) || 
      (VIDEO_RENDERER_COLOR_YUV444 <= cb->dst_color_format))
#endif  // #if 0
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
  //if (KAL_TRUE == cb->trigger_display)
  //{
  //  ASSERT(0);
  //}

  //va2_video_renderer_post_process_config_t  post_process;
  // TODO: Note this! unnecessary!
  
  //VA2_VIDEO_RENDERER_RENDER_MODE_T          render_mode;
  // TODO: Note this! unnecessary!
  if (VIDEO_RENDERER_RENDER_MODE_FULL_CONTROL != cb->render_mode)
  {
    ASSERT(0);
  }
  
  //va2_video_renderer_display_surface_t      display_surface;
  // TODO: Note this! nothing to check...

  return fgRet;
}

/**
 *  @remark not supported
 *  @status OK
 *  @common none
 */
static kal_bool 
_va2_vr_vt_6256_config_idp_by_render_mode(
  va2_comp_video_renderer_cb_t *cb, 
  VA2_VIDEO_FRAME_T *video_frame)
{
  ASSERT(0); // function not supported!
  return KAL_TRUE;
}

/**
 *  @remark not supported
 *  @status OK
 *  @common none
 */
static void
_va2_vr_vt_6256_display_timer_hdlr(
  void *param)
{
  //kal_bool idp_busy;
  kal_uint32 save_irq_mask;
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vt_6256_cb;

  if ((va2_comp_video_renderer_cb_t*) param != cb)
  {
    ASSERT(0); // incorrect timer handler param
  }

  #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)
    SLA_CustomLogging("TM0", 1);
  #endif  // #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)

  save_irq_mask = SaveAndSetIRQMask();
  if (NULL == cb->vr_q_handle.curr_dspl_buf_hdr)
  {
    va2_vr_add_trace(&_va2_vr_vt_6256_debug_trace[0], VA2_VR_INTERNAL____DSPL_TIMER_ASSERT, 0);
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

  va2_vr_add_trace(&_va2_vr_vt_6256_debug_trace[0], VA2_VR_INTERNAL____DSPL_TIMER_TIMEOUT, 0);
  //_va2_comp_vr_add_trace(, 0);
  if (KAL_TRUE== cb->trigger_display)
  {
    visual_active_hisr(VISUAL_RENDERER_TIMER_HISR_ID);
  }
  return;
}

/**
 *  @status XX
 *  @remark callback in HISR...VISUAL HISR to be specific...
 *  @common VR.VT
 */
static void
_va2_vr_vt_6256_blocking_idp_frame_done_cb(
  void *param)
{
  va2_comp_video_renderer_cb_t *cb = (va2_comp_video_renderer_cb_t*) param;
  ASSERT(NULL != cb);
  _va2_vr_vt_6256_curr_dspl_frame_buf_idx = 0;
  _va2_vr_vt_get_frame=KAL_FALSE;
  idp_trigger_video_call_encode_display_cb();
}


/**
 *  @status XX
 *  @remark callback in HISR...VISUAL HISR to be specific...
 *  @common VR.VT
 */
static void
_va2_vr_vt_6256_idp_frame_done_cb(
  void *param)
{
  //kal_bool hw_busy = KAL_FALSE;
  va2_comp_video_renderer_cb_t *cb = (va2_comp_video_renderer_cb_t*) param;
  //va2_util_buf_hdr_q_item_t *item = cb->vr_q_handle.curr_dspl_buf_hdr;

  ASSERT(NULL != cb);

  if (KAL_FALSE== cb->trigger_display)
  {
    idp_trigger_video_call_encode_display_cb();

    if (_va2_comp_video_renderer_idp_key!=0)
    {
      _va2_comp_video_renderer_idp_key = 0;
    }
  }


  if(VIDEO_STATE_RUN != cb->state.eState)
  {
    return;
  }

  #if defined(VA2_VR_VT_6256_ENABLE_SWLA_TRACE)
    SLA_CustomLogging("RFD", 1);
  #endif  // #if defined(VA2_VR_VT_6236_ENABLE_SWLA_TRACE)

  if (KAL_TRUE == cb->bypass)
  {
    // Unexpected: FrameDone occurs unders bypass mode.
    // Bypass mode should only be switched under Stop state, and render should only execute under Run state.
    // At last, FrameDone will not be processed except under Run state. There it is.
    ASSERT(0);
  }

  va2_vr_add_trace(&_va2_vr_vt_6256_debug_trace[0], VA2_VR_INTERNAL____MDP_HW_FRAME_DONE_CB, 0);

  // Trigger display 
  #if defined(DRV_DISPLAY_DRIVER_V2)
  {
//    kal_uint32 iIndex = ((_va2_vr_render_display_buffer_cnt&0x1)^0x1);
//    kal_uint32 iIndex = ((_va2_vr_render_display_buffer_cnt&0x1));
  if (KAL_TRUE == cb->trigger_display)
  {
    if (KAL_FALSE == _va2_vr_vt_6256_lcd_is_busy())
    {
    _va2_vr_vt_6256_trigger_display(
      cb->dst_fb_start_addr_array[_va2_vr_vt_6256_curr_dspl_frame_buf_idx^0x1].u4_fb_addr_plane0, 
      cb);
  }
    else
    {
    kal_uint32 saved_mask;
    saved_mask = SaveAndSetIRQMask();
    _va2_vr_vt_6256_curr_dspl_frame_buf_idx ^= 0x1;
    RestoreIRQMask(saved_mask);
    }
  }
  else
  {
    _va2_vr_vt_6256_trigger_display(
      cb->dst_fb_start_addr_array[_va2_vr_vt_6256_curr_dspl_frame_buf_idx^0x1].u4_fb_addr_plane0, 
      cb);  
  }
  }
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

/**
 *  @return kal_uint32 the address to destination frame buffer if blocking is set to KAL_TRUE, 0 if blocking is set to KAL_FALSE.
 *  @status OK
 *  @common VR.VT
 */
#if defined (VIDEO_RENDER_VT_TRC)
static kal_uint64 current_output_ts = 0;
#endif

static kal_uint32 
_va2_vr_vt_6256_render_display_frame_buffer(
  va2_comp_video_renderer_cb_t *cb, 
  kal_bool blocking)
{
  VA2_VIDEO_FRAME_T *video_frame;
  va2_util_buf_hdr_q_item_t *curr_dspl_buf_hdr;
  kal_uint32 saved_mask;
  kal_uint32 curr_dspl_buf_idx;

  if ((NULL == cb) || 
      (NULL == cb->vr_q_handle.curr_dspl_buf_hdr))
  {
    ASSERT(0); // incorrect param
  }

  curr_dspl_buf_hdr = cb->vr_q_handle.curr_dspl_buf_hdr;

  // IDP opened
  if (0 == _va2_comp_video_renderer_idp_key)
  {
    ASSERT(0); // IDP video playback not opened
  }

  va2_vr_add_trace(&_va2_vr_vt_6256_debug_trace[0], VA2_VR_INTERNAL____RENDER, (kal_uint32) curr_dspl_buf_hdr);

  // get frame data...
  video_frame = (VA2_VIDEO_FRAME_T*) curr_dspl_buf_hdr->buffer_header.pPrivateData;
  ASSERT(NULL != video_frame);
  kal_mem_cpy(&(cb->src_size), &(video_frame->r_fb_size), sizeof(VA2_FRAME_SIZE_T));
  kal_mem_cpy(&(cb->src_clip), &(video_frame->r_clip_window), sizeof(VA2_CLIP_WINDOW_T));
  kal_mem_cpy(&(cb->src_fb_addr), &(video_frame->r_fb_addr), sizeof(VA2_FRAME_BUFFER_ADDRESS_T));

  // check all parameters and configs for triggering HW
  if (KAL_FALSE == _va2_vr_vt_6256_check_params_configs(cb))
  {
    if (KAL_FALSE == blocking)
    {
      va2_vr_notify_error_to_client(cb);
    }
    return VIDEO_ERROR_INPUT_PARAM_ERROR;
  }

    {
    saved_mask = SaveAndSetIRQMask();
    curr_dspl_buf_idx = _va2_vr_vt_6256_curr_dspl_frame_buf_idx;
    _va2_vr_vt_6256_curr_dspl_frame_buf_idx ^= 0x1;
    RestoreIRQMask(saved_mask);
    }
  
  // Stop IDP
  if (KAL_FALSE == idp_video_call_decode_stop(_va2_comp_video_renderer_idp_key))
  {
    ASSERT(0);
  }

  //  5.1. config MDP driver [OK]
  {
    kal_bool result;
    void (*ptr_FrmDoneCBFunc)(void *) = NULL;
      
    if(KAL_FALSE == blocking)
    {
      ptr_FrmDoneCBFunc = _va2_vr_vt_6256_idp_frame_done_cb;
    }
    else
    {
      if (cb->trigger_display == KAL_TRUE)
      {
          ptr_FrmDoneCBFunc = NULL;
      }
      else
      {
      ptr_FrmDoneCBFunc = _va2_vr_vt_6256_blocking_idp_frame_done_cb;
    }
    }



    result = idp_video_call_decode_config(
      _va2_comp_video_renderer_idp_key,
      IDP_VIDEO_CALL_DECODE_INTMEM_START_ADDRESS, cb->internal_memory.u4_start_addr,
      IDP_VIDEO_CALL_DECODE_INTMEM_SIZE, cb->internal_memory.u4_size,
      IDP_VIDEO_CALL_DECODE_EXTMEM_START_ADDRESS, 0,
      IDP_VIDEO_CALL_DECODE_EXTMEM_SIZE, 0,
        
      IDP_VIDEO_CALL_DECODE_DONE_CB, ptr_FrmDoneCBFunc, 
      IDP_VIDEO_CALL_DECODE_DONE_CB_PARAM, cb, 

      
      IDP_VIDEO_CALL_DECODE_DECODE_SRC_WIDTH, cb->src_size.u4_width,
      IDP_VIDEO_CALL_DECODE_DECODE_SRC_HEIGHT, cb->src_size.u4_height,
      IDP_VIDEO_CALL_DECODE_DECODE_TAR_WIDTH, cb->dst_size.u4_width,
      IDP_VIDEO_CALL_DECODE_DECODE_TAR_HEIGHT, cb->dst_size.u4_height,
      
      IDP_VIDEO_CALL_DECODE_DECODE_SRC_Y_BUFFER_ADDRESS, video_frame->r_fb_addr.u4_fb_addr_plane0,
      IDP_VIDEO_CALL_DECODE_DECODE_SRC_U_BUFFER_ADDRESS, video_frame->r_fb_addr.u4_fb_addr_plane1,
      IDP_VIDEO_CALL_DECODE_DECODE_SRC_V_BUFFER_ADDRESS, video_frame->r_fb_addr.u4_fb_addr_plane2,

	  IDP_VIDEO_CALL_DECODE_DECODE_IMAGE_DATA_FORMAT, va2_util_convert_to_idp_color_format(cb->dst_color_format), 
      // TODO: toggle double buffer here in video renderer!!
      IDP_VIDEO_CALL_DECODE_FRAME_BUFFER_ADDRESS, cb->dst_fb_start_addr_array[curr_dspl_buf_idx].u4_fb_addr_plane0, 
      IDP_VIDEO_CALL_DECODE_FRAME_BUFFER_ADDRESS_2, NULL, /* [vt_decode_double_buffering] */
      
#if defined(DRV_DISPLAY_DRIVER_V1)
      IDP_VIDEO_CALL_DECODE_TRIGGER_LCD, cb->trigger_display,
#endif
#if defined(DRV_DISPLAY_DRIVER_V2)
      IDP_VIDEO_CALL_DECODE_TRIGGER_LCD, KAL_FALSE, 
#endif
      IDP_VIDEO_CALL_DECODE_DECODE_ROT_ANGLE, va2_util_convert_to_idp_rot_angle(cb->rotate_flip.u2_cw_rotate_angle,
                                                                                cb->rotate_flip.b_flip), 
      
      IDP_VIDEO_CALL_DECODE_DECODE_SRC_FMT_4X4, KAL_TRUE,
      IDP_VIDEO_CALL_DECODE_DECODE_ENABLE_CLIP, cb->dst_clip.b_clip_enable,
      IDP_VIDEO_CALL_DECODE_DECODE_CLIP_LEFT, cb->dst_clip.u4_clip_left,
      IDP_VIDEO_CALL_DECODE_DECODE_CLIP_RIGHT, cb->dst_clip.u4_clip_right,
      IDP_VIDEO_CALL_DECODE_DECODE_CLIP_TOP, cb->dst_clip.u4_clip_top,
      IDP_VIDEO_CALL_DECODE_DECODE_CLIP_BOTTOM, cb->dst_clip.u4_clip_bottom,
      
      IDP_VIDEO_CALL_DECODE_DECODE_MP4DEBLK_QUANT_BUF, cb->mp4dblk_quant_buf,
      
      0);
    if(result == KAL_FALSE)
    {
      if (KAL_FALSE == blocking)
      {
        va2_vr_notify_error_to_client(cb);
      }
      return KAL_FALSE;
    }
    ASSERT(KAL_TRUE == result);  
  }

  //encoder callback is not enabled yet, update LCD address at render display frame buffer
  #if defined(DRV_DISPLAY_DRIVER_V1)
  if (_va2_vr_vt_6256_enable_encoder  == KAL_FALSE)
  {
  // config LCD...I think this implementation sucks!
  if (KAL_FALSE == cb->trigger_display)
  {
    kal_uint32 lcd_layer;
    switch ((kal_uint32) cb->display_surface.r_mtk_lcd_config.hw_update_layer)
    {
    case LCD_LAYER0_ENABLE: lcd_layer = LCD_LAYER0; break;
    case LCD_LAYER1_ENABLE: lcd_layer = LCD_LAYER1; break;
    case LCD_LAYER2_ENABLE: lcd_layer = LCD_LAYER2; break;
    case LCD_LAYER3_ENABLE: lcd_layer = LCD_LAYER3; break;
    case LCD_LAYER4_ENABLE: lcd_layer = LCD_LAYER4; break;
    case LCD_LAYER5_ENABLE: lcd_layer = LCD_LAYER5; break;
    default: ASSERT(0); break;
    }
    LCD_config_fullvideo_layer_address(lcd_layer,
                                       (kal_uint32) cb->dst_fb_start_addr_array[_va2_vr_vt_6256_curr_dspl_frame_buf_idx].u4_fb_addr_plane0);
  }
  }
  #endif
#if defined (VIDEO_RENDER_VT_TRC)
    if(kal_if_hisr())
    {
      kal_dev_trace(TRACE_GROUP_6, REND_TRC_RENDER_DISP_FRAME_BUFFER, 
                             _va2_comp_video_renderer_idp_key, 
                             curr_dspl_buf_idx,
                             cb->dst_fb_start_addr_array[curr_dspl_buf_idx].u4_fb_addr_plane0, 
                             curr_dspl_buf_hdr->buffer_header.u8TimeStamp
                );
    }
    else
    {
      kal_trace(TRACE_GROUP_6, REND_TRC_RENDER_DISP_FRAME_BUFFER, 
                             _va2_comp_video_renderer_idp_key, 
                             curr_dspl_buf_idx,
                             cb->dst_fb_start_addr_array[curr_dspl_buf_idx].u4_fb_addr_plane0, 
                             curr_dspl_buf_hdr->buffer_header.u8TimeStamp
                 );
    }

  ASSERT(curr_dspl_buf_hdr->buffer_header.u8TimeStamp >= current_output_ts);
  current_output_ts = curr_dspl_buf_hdr->buffer_header.u8TimeStamp;

  cb->dst_fb_start_addr_array[curr_dspl_buf_idx].u4_fb_time_stamp = curr_dspl_buf_hdr->buffer_header.u8TimeStamp;
#endif

  // trigger IDP
  if (KAL_FALSE == idp_video_call_decode_start_all(_va2_comp_video_renderer_idp_key))
  {
    ASSERT(0);
  }

  // busy loop til IDP finishes
  if (KAL_TRUE == blocking)
  {
    if (cb->trigger_display == KAL_TRUE)
    {
    kal_bool busy;
    kal_uint32 start_time = drv_get_current_time();

    do
    {
      ASSERT(KAL_TRUE == idp_video_call_decode_is_busy(_va2_comp_video_renderer_idp_key, &busy));
      // TODO: sleep ?
    } while ((KAL_TRUE == busy) && 
             (VA2_VR_VT_6256_RENDER_TIME_MAX > drv_get_duration_tick(start_time, drv_get_current_time())));
    }
    return cb->dst_fb_start_addr_array[0].u4_fb_addr_plane0;
  }
  else
  {
    return 0;
  }
}

static void
_va2_vr_vt_6256_hisr_general(void)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vt_6256_cb;

  switch(cb->eVdoRndrHisrMode)
  {
  case VIDEO_RENDERER_HISR_MODE_BLACK_FRAME_INSERT:

    // Do not insert black frame if previous frame is available.
    if((cb->vr_q_handle.curr_dspl_buf_hdr == NULL) && 
       (0 == cb->vr_q_handle.to_be_processed_q.size))
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

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

static void
_va2_vr_vt_6256_disp_timer_visu_hisr_cb_func(void)
{
  kal_bool idp_busy;
  kal_uint32 u4DurationmS;
  static kal_uint32 _u4DispTimerSkipCnt = 0, _u4DispTimerRefreshCnt = 0;
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vt_6256_cb;

  #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)
    SLA_CustomLogging("TM1", 1);
  #endif  // #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)

  u4DurationmS = drv_get_duration_ms(cb->u4LastRenderTimestamp);
  if(u4DurationmS < 60)
  {
    _u4DispTimerSkipCnt++;

    #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)
      SLA_CustomLogging("TM1", 0);
    #endif  // #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)
    return;
  }
  _u4DispTimerRefreshCnt++;

  idp_video_call_decode_is_busy(_va2_comp_video_renderer_idp_key, &idp_busy);

  // If IDP not busy and no BH waiting...
  if ((KAL_FALSE == idp_busy) && 
      // (0 == _to_be_processed_q.size) && 
      (VIDEO_STATE_RUN == cb->state.eState) && 
      (KAL_FALSE == cb->bypass))
  {
    va2_vr_add_trace(&_va2_vr_vt_6256_debug_trace[0], VA2_VR_INTERNAL____DSPL_TIMER_TRIGGER_RENDER_IN_VHISR, (kal_uint32) cb->vr_q_handle.curr_dspl_buf_hdr);

    _va2_vr_vt_6256_render_display_frame_buffer(cb, KAL_FALSE);

  }

  #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)
    SLA_CustomLogging("TM1", 0);
  #endif  // #if defined(VA2_COMP_VR_ENABLE_SWLA_TRACE)

}  // end of _va2_vr_vt_6236_disp_timer_visu_hisr_cb_func
void
_va2_vr_vt_6256_video_decode_empty_this_buffer(
  void *user_data)
{
    //va2_comp_video_renderer_cb_t *cb = &_va2_vr_vt_6256_cb;
    
    _va2_vr_vt_trigger_empty_this_buffer(&_va2_vr_vt_6256_cb,
                   &_va2_comp_video_renderer_idp_key,
                   &_va2_vr_vt_6256_debug_trace[0]);
}

/**
 *  @status OK
 *  @todo init the control block
 *  @common none
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vt_6256_t01_close_to_init(
  va2_comp_video_renderer_cb_t *cb)
{
  VIDEO_ERROR_TYPE_T ret;

  if (NULL == cb)
  {
    ASSERT(0);
  }
  
  va2_vr_add_trace(&_va2_vr_vt_6256_debug_trace[0], VA2_VR_TRANSITION__T01_CLOSE_TO_INIT, 0);
  
  ret = va2_vr_t01_close_to_init(cb);
  
  if (ret != VIDEO_ERROR_NONE)
  {
    return ret;
  }

  // callback setting  
  idp_set_video_call_decode_cb(&_va2_vr_vt_6256_video_decode_empty_this_buffer);

  // allocate memory for display frame buffer 2
  {
    cb->dst_fb_addr_array[1].u4_fb_addr_plane0 = VideoGetExtBuffer(_va2_vr_render_extmem_handler,VA2_VR_VP_DISPLAY_BUFFER_SIZE);
    if (0 == cb->dst_fb_addr_array[1].u4_fb_addr_plane0)
    {
      ASSERT(0); // buffer allocation failed
    }
    cb->dst_fb_addr_array[1].u4_fb_addr_plane0 = 
      VideoCommExtBufferCacheableSwitch(cb->dst_fb_addr_array[1].u4_fb_addr_plane0, 
                                        VA2_VR_VP_DISPLAY_BUFFER_SIZE, 
                                        VIDEO_NON_CACHEABLE);

    cb->dst_fb_start_addr_array[1].u4_fb_addr_plane0 = cb->dst_fb_addr_array[1].u4_fb_addr_plane0;
  }
  
  // init color forkat
  cb->src_color_format = VIDEO_RENDERER_COLOR_4X4_BLOCK_YUV420;
  cb->dst_color_format = VIDEO_RENDERER_COLOR_PACKED_UYVY422;

  _va2_vr_render_display_buffer_cnt = 0;
  _va2_vr_vt_6256_curr_dspl_frame_buf_idx = 0;
  
  return VIDEO_ERROR_NONE;

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

/**
 *  @status OK
 *  @todo: remove those "very temp" part before SQC...
 *  @common VR.VT
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vt_6256_t03_init_to_idle(
  va2_comp_video_renderer_cb_t *cb)
{
  //kal_uint32 save_irq_mask;

  if (NULL == cb)
  {
    ASSERT(0);
  }

  va2_vr_add_trace(&_va2_vr_vt_6256_debug_trace[0], VA2_VR_TRANSITION__T03_INIT_TO_IDLE, 0);
  _va2_comp_video_renderer_idp_key = 0;
  
  //  1. Open MDP path
  if (KAL_TRUE== cb->trigger_display)
  {
    if (0 == _va2_comp_video_renderer_idp_key)
    {
      if (KAL_FALSE == idp_video_call_decode_open(&_va2_comp_video_renderer_idp_key))
      {
        ASSERT(0); // MDP driver open fail
        return VIDEO_ERROR_INIT_ERROR; // TODO: find a proper error code...
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  

  //    1.1 register VISUAL HISR for misc video render use
  VISUAL_Register_HISR(VISUAL_RENDERER_HISR_ID, _va2_vr_vt_6256_hisr_general);

  //    1.2 register VISUAL HISR for VR Timer processing. The timer is used to trigger MDP for redraw when 
  //        there is no video frame in certain period of time. Under the situation, the UI updates will not
  //        be in effect since UI updates relies on MDP trigger under hardware trigger mode. The reason to 
  //        let timer activates Visual HISR for MDP trigger is to centralize the control of MDP, so that 
  //        reentrant condition can be solved.
  VISUAL_Register_HISR(VISUAL_RENDERER_TIMER_HISR_ID, _va2_vr_vt_6256_disp_timer_visu_hisr_cb_func);  

  //  Create a timer for periodically update display device
  if (0 == cb->display_timer)
  {
    cb->display_timer = kal_create_timer("VA2_VR_VT_6256_TIMER");
    if (0 == cb->display_timer)
    {
      ASSERT(0); // Timer create fail
    }
  }

  //  6. Invoke VideoCommChangeState() to change to IDLE state
  VideoCommClrAllQ(&(cb->state));
  VideoCommChangeState(&(cb->state), VIDEO_STATE_IDLE);
  
  // set the buffer clear flag to false
  _va2_vr_vt_6256_disp_buffer_init = KAL_FALSE;

  return VIDEO_ERROR_NONE;
}

/**
 *  @status OK
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vt_6256_t04_idle_to_run(
  va2_comp_video_renderer_cb_t *cb)
{
#if defined(__MTK_TARGET__)
  kal_uint32 save_irq_mask;
  volatile VA2_VIDEO_RENDERER_HISR_MODE* pRndrHisrMode;

  if (NULL == cb)
  {
    ASSERT(0);
  }

  va2_vr_add_trace(&_va2_vr_vt_6256_debug_trace[0], VA2_VR_TRANSITION__T04_IDLE_TO_RUN, 0);

  if (KAL_FALSE == cb->bypass)  // Do not control LCD, timer, black frame under bypass mode
  {
    //  config LCD driver if LCD HW_Trig is requested through set_parameter
	if (KAL_TRUE== cb->trigger_display)
	{
	  if (0 == _va2_comp_video_renderer_idp_key)
	  {
		if (KAL_FALSE == idp_video_call_decode_open(&_va2_comp_video_renderer_idp_key))
		{
		  //ASSERT(0); // MDP driver open fail
		  //return VIDEO_ERROR_INIT_ERROR; // TODO: find a proper error code...
		}
	  }
	}


//    if (KAL_TRUE == cb->trigger_display)
    {
      //lcd_frame_update_struct *lcd_cfg;

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
      }

      //lcd_cfg = &cb->display_surface.r_mtk_lcd_config;

      if (KAL_FALSE == _va2_comp_vr_have_config_lcd)
      {
#if defined(DRV_DISPLAY_DRIVER_V1)
        _va2_comp_vr_triggered_lcd_id_this_time = lcd_cfg->lcd_id;

        lcd_cfg->fb_update_mode = LCD_HW_TRIGGER_MODE;
        lcd_cfg->hw_trigger_src = LCD_HWREF_SEL_ROT_DMA1;
   
        lcd_cfg->memory_output = KAL_FALSE;
        lcd_cfg->block_mode_flag = KAL_FALSE;
        lcd_cfg->lcd_block_mode_cb = NULL;

        // all the others are configed when processing video renderer parameters and configs

        // Config LCD and start updating.
        ASSERT(LCD_OK == lcd_fb_update(lcd_cfg));
#endif  // #if defined(DRV_DISPLAY_DRIVER_V1)

#if defined(DRV_DISPLAY_DRIVER_V2)
        _va2_vr_vt_6256_config_n_activate_ddv2(cb);
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)
        va2_vr_add_trace(&_va2_vr_vt_6256_debug_trace[0], VA2_VR_DEBUG_______START_LCD_HW_TRIGGER_MODE, 0);

        _va2_comp_vr_have_config_lcd = KAL_TRUE;
      }
      kal_set_timer( cb->display_timer, 
                     (kal_timer_func_ptr) cb->funcs.display_timer_hdlr,
                     (void*) cb,
                     kal_milli_secs_to_ticks(VA2_COMP_VR_DSPL_DEFAULT_TIMEOUT_TIME),
                     kal_milli_secs_to_ticks(VA2_COMP_VR_DSPL_DEFAULT_TIMEOUT_TIME)
                   );
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
  if (0 != cb->vr_q_handle.to_be_processed_q.size)
  {
    // advance to the latest buffer header...
    va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
    ASSERT(NULL != cb->vr_q_handle.curr_dspl_buf_hdr);
  }

    }
  } // end of bypass mode check



  //  Invoke VideoCommChangeState() to RUN state.
  if (VIDEO_ERROR_NONE != VideoCommChangeState(&(cb->state), VIDEO_STATE_RUN))
  {
    ASSERT(0);
  }
#endif  // #if defined(__MTK_TARGET__)

  return VIDEO_ERROR_NONE;
}  // end of _va2_vr_vt_6236_t04_idle_to_run


/**
 *  @status OK
 *  @common VR.VT
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vt_6256_t05_run_to_stop(
  va2_comp_video_renderer_cb_t *cb)
{
  if (NULL == cb)
  {
    ASSERT(0);
  }

  va2_vr_add_trace(&_va2_vr_vt_6256_debug_trace[0], VA2_VR_TRANSITION__T05_RUN_TO_STOP, 0);

  if (0 != cb->display_timer)
  {
    kal_cancel_timer(cb->display_timer);
  }

  // when in this function, Video Renderer should not be triggered by new BH...protect this case...
  // ...so we move the last step to be the first one...
  //  0. Invoke VideoCommChangeState() to change state to STOP state.
  if (VIDEO_ERROR_NONE != VideoCommChangeState(&(cb->state), VIDEO_STATE_STOP))
  {
    ASSERT(0);
  }

  _va2_vr_render_display_buffer_cnt = 0;
  _va2_vr_vt_6256_curr_dspl_frame_buf_idx = 0;

  //  Stop processing...
  if (KAL_TRUE == cb->bypass)
  {
    // TODO:[1] do something?
  }
  else
  {
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

      if (KAL_TRUE== cb->trigger_display)
      {
        if (_va2_comp_video_renderer_idp_key!=0)
        {
          if (KAL_FALSE == idp_video_call_decode_stop(_va2_comp_video_renderer_idp_key))
          {
            ASSERT(0);
          }
          idp_video_call_decode_close(_va2_comp_video_renderer_idp_key);
          _va2_comp_video_renderer_idp_key = 0;
        }
      }

    if (//(cb->trigger_display) && 
        (KAL_TRUE == _va2_comp_vr_have_config_lcd))
    {
#if defined(DRV_DISPLAY_DRIVER_V1)
      lcd_stop_hw_update(_va2_comp_vr_triggered_lcd_id_this_time);
#endif
      
#if defined(DRV_DISPLAY_DRIVER_V2)
      _va2_vr_vt_6256_stop_n_deactivate_ddv2(cb);
#endif
      va2_vr_add_trace(&_va2_vr_vt_6256_debug_trace[0], VA2_VR_DEBUG_______STOP_LCD_HW_TRIGGER_MODE, 0);
      _va2_comp_vr_have_config_lcd = KAL_FALSE;
    }
  }

  //  4. while to-be-processed queue is not empty, 
  //    4.1 do not alter the current buffer header!
  //    4.1 dequeue all buffer headers from Qtbp til the latest buffer header is left...
  //    4.2 enqueue all buffer headers dequeued from Qtbp
  //    4.3 Try to return all the buffer headers in to-be-returned queue.
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
#endif
  return VIDEO_ERROR_NONE;
}

/**
 *  @status OK
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vt_6256_t06_stop_to_run(
  va2_comp_video_renderer_cb_t *cb)
{
#if defined(__MTK_TARGET__)
  kal_uint32 save_irq_mask;
  volatile VA2_VIDEO_RENDERER_HISR_MODE* pRndrHisrMode;

  if (NULL == cb)
  {
    ASSERT(0);
  }

  va2_vr_add_trace(&_va2_vr_vt_6256_debug_trace[0], VA2_VR_TRANSITION__T06_STOP_TO_RUN, 0);

  if (KAL_FALSE == cb->bypass)  // Do not control LCD, timer, black frame under bypass mode
  {
    //  config LCD driver if LCD HW_Trig is requested through set_parameter
	if (KAL_TRUE== cb->trigger_display)
	{
	  if (0 == _va2_comp_video_renderer_idp_key)
	  {
		if (KAL_FALSE == idp_video_call_decode_open(&_va2_comp_video_renderer_idp_key))
		{
		  //ASSERT(0); // MDP driver open fail
		  //return VIDEO_ERROR_INIT_ERROR; // TODO: find a proper error code...
		}
	  }
	}

//    if (KAL_TRUE == cb->trigger_display)
    {
      //lcd_frame_update_struct *lcd_cfg = &cb->display_surface.r_mtk_lcd_config;

  save_irq_mask = SaveAndSetIRQMask();
  // Do not insert black frame if previous frame is available.
  if((cb->vr_q_handle.curr_dspl_buf_hdr == NULL) && 
     (0 == cb->vr_q_handle.to_be_processed_q.size))
  {
    cb->eVdoRndrHisrMode = VIDEO_RENDERER_HISR_MODE_BLACK_FRAME_INSERT;
    visual_active_hisr(VISUAL_RENDERER_HISR_ID);
  }
  RestoreIRQMask(save_irq_mask);

      if (KAL_FALSE == _va2_comp_vr_have_config_lcd)
      {
#if defined(DRV_DISPLAY_DRIVER_V1)
        _va2_comp_vr_triggered_lcd_id_this_time = lcd_cfg->lcd_id;

        lcd_cfg->fb_update_mode = LCD_HW_TRIGGER_MODE;
        lcd_cfg->hw_trigger_src = LCD_HWREF_SEL_ROT_DMA1;

        lcd_cfg->memory_output = KAL_FALSE;
        lcd_cfg->block_mode_flag = KAL_FALSE;
        lcd_cfg->lcd_block_mode_cb = NULL;

        // all the others are configed when processing video renderer parameters and configs

        // Config LCD and start updating.
        ASSERT(LCD_OK == lcd_fb_update(lcd_cfg));
#endif  // #if defined(DRV_DISPLAY_DRIVER_V1)

#if defined(DRV_DISPLAY_DRIVER_V2)
        _va2_vr_vt_6256_config_n_activate_ddv2(cb);
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)
        va2_vr_add_trace(&_va2_vr_vt_6256_debug_trace[0], VA2_VR_DEBUG_______START_LCD_HW_TRIGGER_MODE, 0);

        _va2_comp_vr_have_config_lcd = KAL_TRUE;
      }
      kal_set_timer( cb->display_timer, 
                     (kal_timer_func_ptr) cb->funcs.display_timer_hdlr,
                     (void*) cb,
                     kal_milli_secs_to_ticks(VA2_COMP_VR_DSPL_DEFAULT_TIMEOUT_TIME),
                     kal_milli_secs_to_ticks(VA2_COMP_VR_DSPL_DEFAULT_TIMEOUT_TIME)
                   );

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
      if (0 != cb->vr_q_handle.to_be_processed_q.size)
      {
        // advance to the latest buffer header...
        va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
        ASSERT(NULL != cb->vr_q_handle.curr_dspl_buf_hdr);
      }

    }
  }

  //  Invoke VideoCommChangeState() to RUN state.
  if (VIDEO_ERROR_NONE != VideoCommChangeState(&(cb->state), VIDEO_STATE_RUN))
  {
    ASSERT(0);
  }
//save_irq_mask = SaveAndSetIRQMask();
//  _va2_vr_vt_6236_curr_dspl_frame_buf_idx = 3;
//  _va2_vr_vt_6236_queued_dspl_frame = 0;
//  _va2_vr_vt_6236_curr_render_frame_buf_idx = 0;
//RestoreIRQMask(save_irq_mask);

#endif  // #if defined(__MTK_TARGET__)
  return VIDEO_ERROR_NONE;
}  // end of _va2_vr_vt_6236_t06_stop_to_run


/**
 *  @status OK
 *  @common VR.VT
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vt_6256_t10_idle_to_close(
  va2_comp_video_renderer_cb_t *cb)
{
  if (NULL == cb)
  {
    ASSERT(0);
  }

  va2_vr_add_trace(&_va2_vr_vt_6256_debug_trace[0], VA2_VR_TRANSITION__T10_IDLE_TO_CLOSE, 0);
  
  //  1. reset buffer header queues...
  va2_util_buf_hdr_reset_buffer_header_queues(&(cb->vr_q_handle));

  //  2. Destroy timer.
  if (NULL != cb->display_timer)
  {
    kal_cancel_timer(cb->display_timer);
  }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
 *  @common VR.VT
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vt_6256_init(void)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vt_6256_cb;
  VIDEO_ERROR_TYPE_T iRet;

  //    2.1 create semaphore for API protection
  if (0 == cb->vr_sema_vrstate_sync)
  {
    cb->vr_sema_vrstate_sync = kal_create_sem("VA2_VR_VT_SEM", 1);
  }

  kal_take_sem(cb->vr_sema_vrstate_sync, KAL_INFINITE_WAIT);

  va2_vr_init_trace(VA2_VR_VT_6256_DEBUG_TRACE_SIZE, &_va2_vr_vt_6256_debug_trace[0]);

  va2_vr_add_trace(&_va2_vr_vt_6256_debug_trace[0], VA2_VR_API_________INIT, 0);

  if (VIDEO_STATE_CLOSE != cb->state.eState)
  {
    ASSERT(0); // incorrect state
    return VIDEO_ERROR_INIT_ERROR;
  }

  iRet = cb->funcs.t01_close_to_init(cb);
  kal_give_sem(cb->vr_sema_vrstate_sync);

  return iRet;
}

/**
 *  @status OK
 *  @common VR
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vt_6256_send_command(
  VIDEO_COMMAND_TYPE_T eCmd, 
  kal_uint32 u4Param)
{
  return va2_vr_send_command(&_va2_vr_vt_6256_cb, eCmd, u4Param);
}

/**
 *  @status OK
 *  @todo modify this based on supported param/config
 *  @common VR.VT
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vt_6256_get_parameter(
  VIDEO_PARAM_TYPE_T eCmd, 
  void *pParam)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vt_6256_cb;

  va2_vr_add_trace(&_va2_vr_vt_6256_debug_trace[0], VA2_VR_API_________GET_PARAMETER, (kal_uint32) eCmd);

  // special case, this config could be get in any state...
  if (VIDEO_CONFIG_RENDERER_STATUS == eCmd)
  {
    ASSERT(NULL != pParam);
    *((VIDEO_STATE_TYPE_T*) pParam) = cb->state.eState;
    return VIDEO_ERROR_NONE;
  }

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

  case VIDEO_PARAM_RENDERER_ROTATE_FLIP: /**< arg type: va2_video_renderer_rotate_flip_t* */
    kal_mem_cpy(pParam, &(cb->rotate_flip), sizeof(va2_video_renderer_rotate_flip_t));
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

      if ((VIDEO_STATE_STOP != cb->state.eState) && 
          (VIDEO_STATE_IDLE != cb->state.eState))
      {
        ASSERT(0); // This parameter is only supported in STOP and IDLE state...
      }

      // TODO: Note this! Video Renderer will NOT assert if no video frame to be rendered  [MAUI_02847197]
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
            else if (VIDEO_RENDERER_COLOR_PACKED_UYVY422 == cb->dst_color_format)
            {
              va2_util_clear_uyvy_buffer_black((kal_uint32*)addr, size);  //black for UYVY422 
            }
            else
            {
              ASSERT(0);
            }
          }
        }
        va2_vr_add_trace(&_va2_vr_vt_6256_debug_trace[0], VA2_VR_DEBUG_______NO_VIDEO_FRAME_TO_DRAW, 0);
        *(kal_uint32*)pParam = cb->dst_fb_addr_array[0].u4_fb_addr_plane0;
        break;
      }

      save_irq_mask = SaveAndSetIRQMask();
      if (KAL_FALSE == cb->keep_curr_ptr_when_run)
      {
        va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
      }
      RestoreIRQMask(save_irq_mask);

      if (cb->trigger_display == KAL_TRUE)
      {
	      if (0 == _va2_comp_video_renderer_idp_key)
	      {
	        if (KAL_FALSE == idp_video_call_decode_open(&_va2_comp_video_renderer_idp_key))
	        {
		        ASSERT(0); // MDP driver open fail
	         	return VIDEO_ERROR_INIT_ERROR; // TODO: find a proper error code...
	        }
	      }
        //MAUI_02908562 reset buffer pointer to ensure renderer will use first buffer for get frame
        _va2_vr_vt_6256_curr_dspl_frame_buf_idx = 0;
        *(kal_uint32*)pParam = _va2_vr_vt_6256_render_display_frame_buffer(cb, KAL_TRUE);
        if (0 != _va2_comp_video_renderer_idp_key)
        {
          idp_video_call_decode_close(_va2_comp_video_renderer_idp_key);
          _va2_comp_video_renderer_idp_key = 0;
        }
      }
      else
      {
        _va2_vr_vt_get_frame = KAL_TRUE;
        {
          kal_uint32 start_time = drv_get_current_time();
          do
          {
            if (_va2_vr_vt_get_frame==KAL_FALSE)
            {
              break;
            }
          } while (VA2_VR_VT_6256_RENDER_TIME_MAX > drv_get_duration_tick(start_time, drv_get_current_time()));
        }
        *(kal_uint32*)pParam = cb->dst_fb_start_addr_array[0].u4_fb_addr_plane0;
      }  
      _va2_vr_vt_6256_bypass_config_src_rect = KAL_TRUE;
    }
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

  return VIDEO_ERROR_NONE;
}

/**
 *  @status OK
 *  @commmon none
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vt_6256_set_parameter(
  VIDEO_PARAM_TYPE_T eCmd, 
  void *pParam)
{
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vt_6256_cb;
  VIDEO_STATE_TYPE_T state;
  VIDEO_ERROR_TYPE_T i4Ret = VIDEO_ERROR_UNDEFINED;

  state = cb->state.eState;

  va2_vr_add_trace(&_va2_vr_vt_6256_debug_trace[0], VA2_VR_API_________SET_PARAMETER, (kal_uint32) eCmd);

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

          // TODO: this cannot be set...put this in init function!...
          cb->dst_color_format = *color_format;
          //cb->dst_color_format = VIDEO_RENDERER_COLOR_RGB565;
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

      case VIDEO_PARAM_RENDERER_DISPLAY_SURFACE: /**< arg type: va2_video_renderer_display_surface_t* */
#if 1   // Use va2_video_renderer_display_surface_t.r_mtk_lcd_config.hw_update_layer to denote which layer will be used for video call decode display...
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
#endif  // #if 1
#if 0
/* under construction !*/
/* under construction !*/
#endif  // #if 0
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
        i4Ret = VIDEO_ERROR_NONE;
        break;

      case VIDEO_PARAM_RENDERER_INTERNAL_MEMORY: /**< arg type: VA2_MEMORY_BLOCK_T* */
        {
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
        
        // TODO: cannot be set, put this in init function
        //cb->src_color_format = *color_format;
        cb->src_color_format = VIDEO_RENDERER_COLOR_4X4_BLOCK_YUV420;
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
#if 0   // This config is unsupported in MT6256 VT
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
#endif  // #if 0
      //ASSERT(0);
      i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
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
#if 0   // This config is unsupported in MT6256 VT
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
#endif  // #if 0
      break;
      
    // TODO: Add MP4 DEBLK params for MT6256 VT...
    case VIDEO_CONFIG_RENDERER_MP4DEBLK_Q_BUF: /**< arg type: kal_uint32* */
      {
        if (NULL == pParam)
        {
          ASSERT(0);
          i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
          break;
        }
        cb->mp4dblk_quant_buf = *((kal_uint32*)pParam);
      }
      i4Ret = VIDEO_ERROR_NONE;
      break;

    default: 
      ASSERT(0);
      i4Ret = VIDEO_ERROR_INPUT_PARAM_ERROR;
      break;
    }

    if(i4Ret != VIDEO_ERROR_UNDEFINED)
    {
      kal_give_sem(cb->vr_sema_vrstate_sync);
      return i4Ret;
    }
  }

  return VIDEO_ERROR_NONE;
}

/**
 *  @status OK
 *  @common VR
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vt_6256_use_buffer(
  kal_uint8 *pu1Buff, 
  kal_uint32 u4Size)
{
  return va2_vr_use_buffer(&_va2_vr_vt_6256_cb, pu1Buff, u4Size);
}

/**
 *  @status XX
 *  @todo timer?
 *  @common VR.VT
 */
#if (defined (VIDEO_RENDER_VT_TRC))
static kal_uint64 current_input_ts=0;
#endif   
static VIDEO_ERROR_TYPE_T 
_va2_vr_vt_6256_empty_this_buffer(
  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
  //va2_util_buf_hdr_q_item_t *q_item;
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vt_6256_cb;
  kal_uint32 u4Flags = 0;

  //  0.  parameter check...
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
    //cb->eVdoRndrHisrMode = VIDEO_RENDERER_HISR_MODE_EMPTY_THIS_BUFFER;
    kal_retrieve_eg_events(cb->EventID, TASK_WAIT_HISR_SET, KAL_AND_CONSUME, &u4Flags, KAL_NO_SUSPEND);
    visual_active_hisr(VISUAL_RENDERER_EMPTY_THIS_BUFFER_HISR_ID);
    kal_retrieve_eg_events(cb->EventID, TASK_WAIT_HISR_SET, KAL_AND_CONSUME, &u4Flags, KAL_SUSPEND);
    return VIDEO_ERROR_NONE;
  }
  _va2_vr_vt_6256_empty_this_buffer_real(prBuffHeader);


  return VIDEO_ERROR_NONE;
}


static VIDEO_ERROR_TYPE_T 
_va2_vr_vt_6256_empty_this_buffer_real(
  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
  va2_util_buf_hdr_q_item_t *q_item;
  va2_comp_video_renderer_cb_t *cb = &_va2_vr_vt_6256_cb;
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
  #if (defined (VIDEO_RENDER_VT_TRC)) 
  ASSERT(kal_mem_cmp((void*)(&prBuffHeader->u8TimeStamp), (void*)(prBuffHeader->pu1Buffer), sizeof(kal_uint64)) == 0);// gellmann
  
  ASSERT(prBuffHeader->u8TimeStamp >= current_input_ts);
  current_input_ts = prBuffHeader->u8TimeStamp;
  #endif

  va2_vr_add_trace(&_va2_vr_vt_6256_debug_trace[0], VA2_VR_API_________EMPTY_THIS_BUFFER, (kal_uint32) prBuffHeader);

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
  //    2.1 if queue full, return error code...
  if (NULL == q_item)
  {
    ASSERT(0);
  }

  // Add a log to track the last valid emptyThisBuffer calls...
  //va2_vr_add_trace_empty_this_buffer(cb, VA2_VR_API_________EMPTY_THIS_BUFFER, (kal_uint32) prBuffHeader->pu1Buffer);

  //    2.2 enqueue should not fail here...
  kal_mem_cpy((void*) &(q_item->buffer_header), prBuffHeader, sizeof(VIDEO_BUFFERHEADER_TYPE_T));
  va2_util_buf_hdr_enqueue(&(cb->vr_q_handle.to_be_processed_q), q_item);

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
	  if (KAL_FALSE== cb->trigger_display)
	  {
	    break;
	  }

      ASSERT(KAL_TRUE == idp_video_call_decode_is_busy(_va2_comp_video_renderer_idp_key, &busy));
      if (KAL_FALSE == busy)
      {
	{
        va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
        va2_vr_add_trace(&_va2_vr_vt_6256_debug_trace[0], VA2_VR_API_________EMPTY_THIS_BUFFER__TRIGGER_HW, (kal_uint32) (cb->vr_q_handle.curr_dspl_buf_hdr));
        _va2_vr_vt_6256_render_display_frame_buffer(cb, KAL_FALSE);
      }
      }
      else
      {
        va2_vr_add_trace(&_va2_vr_vt_6256_debug_trace[0], VA2_VR_API_________EMPTY_THIS_BUFFER__ENQUEUE_ONLY, (kal_uint32) (cb->vr_q_handle.to_be_processed_q.tail));
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
_va2_vr_vt_6256_fill_this_buffer(
  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
  return va2_vr_fill_this_buffer(&_va2_vr_vt_6256_cb, prBuffHeader);
}

/**
 *  @status OK
 *  @common VR
 */
static VIDEO_ERROR_TYPE_T 
_va2_vr_vt_6256_set_callbacks(
  VIDEO_CALLBACK_TYPE_T *prCallback)
{
  return va2_vr_set_callbacks(&_va2_vr_vt_6256_cb, prCallback);
}

/**
 *  @status OK
 *  @remark this function could only be invoked when in CLOSE state.
 */
VIDEO_ERROR_TYPE_T 
_va2_vr_vt_6256_deinit(void)
{
  VIDEO_ERROR_TYPE_T ret = va2_vr_deinit(&_va2_vr_vt_6256_cb);
  va2_vr_init_trace(0, NULL);
  return ret;
}
#endif  // #if defined(__MTK_TARGET__)

/****************************************************************************
 * external function bodies
 ****************************************************************************/
VIDEO_COMPONENT_TYPE_T* 
va2_video_renderer_vt_mt6256_get_handle(
  VA2_VIDEO_RENDERER_TYPE_T e_type)
{
#if defined(__MTK_TARGET__)
  VIDEO_COMPONENT_TYPE_T *pr_video_renderer_comp = NULL;

  switch (e_type)
  {
  case VIDEO_RENDERER_VIDEO_TELEPHONY: 
    pr_video_renderer_comp = &_va2_vr_vt_6256_primitives;
    _va2_vr_vt_6256_cb.renderer_type = VIDEO_RENDERER_VIDEO_TELEPHONY;
    break;

  default:    
    break;
  }

  return pr_video_renderer_comp;
#else   // #if defined(__MTK_TARGET__)
  return NULL;
#endif  // #if defined(__MTK_TARGET__)
  
}

VIDEO_ERROR_TYPE_T 
va2_video_renderer_vt_mt6256_release_handle(
  VIDEO_COMPONENT_TYPE_T *pr_handle)
{
#if defined(__MTK_TARGET__)
  VIDEO_ERROR_TYPE_T error = VIDEO_ERROR_NONE;
  
  if ((NULL == pr_handle) || 
      (&_va2_vr_vt_6256_primitives != pr_handle) || 
      (NULL == pr_handle->pfnDeInit))
  {
    ASSERT(0);
  }
  else
  {
    error = pr_handle->pfnDeInit();
  }

  return error;
#else   // #if defined(__MTK_TARGET__)
  return VIDEO_ERROR_DEINIT_ERROR;
#endif  // #if defined(__MTK_TARGET__)
}

#endif  // #if defined(VA2_VIDEO_RENDERER_VT_MT6256_E2)

#endif	// #if defined(__VIDEO_ARCHI_V2__)
/// @}

