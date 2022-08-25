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
 *    va2_comp_video_renderer.c
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
 *
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
 ****************************************************************************/
#if defined(__VIDEO_ARCHI_V2__)
/// \ingroup va2_comp_video_renderer
/// @{
/****************************************************************************
 * internal options
 ****************************************************************************/
#define VA2_VR_ENABLE_DEBUG_TRACE

/****************************************************************************
 * include directives
 ****************************************************************************/
#include "kal_public_api.h"
/******* VA2 common *************************/
#include "video_types_v2.h"
#include "video_comm_component_v2.h"
#include "video_buffer_management_v2.h"
/******* VA2 Video Renderer Component *******/
#include "va2_comp_video_renderer.h"
#include "va2_video_renderer_common.h"
#include "va2_video_renderer_vp.h"
#include "va2_video_renderer_vt.h"
#include "va2_video_renderer_mem_req.h"
#include "va2_util_buffer_header_queue.h"
#include "Va2_util_misc.h"
/******* driver common **********************/
#include "drv_comm.h"
/******* Visual HISR driver *****************/
#include "visualhisr.h"

#if defined(__MM_DCM_SUPPORT__)
#include "dcmgr.h"
#pragma arm section code = "DYNAMIC_CODE_RENDER_ROCODE", rodata = "DYNAMIC_CODE_RENDER_ROCODE"
#endif

/****************************************************************************
 * local type definitions and macros
 ****************************************************************************/

/**
 *  \def VA2_VR_DEBUG_TRACE_SIZE
 *  @remark Must be 2^N, N is natural number...
 */
#if defined(__MTK_INTERNAL__)
/* under construction !*/
#else   // #if defined(__MTK_INTERNAL__)
#define VA2_VR_DEBUG_TRACE_SIZE            (32)
#endif  // #if defined(__MTK_INTERNAL__)

/****************************************************************************
 * local variables
 ****************************************************************************/
#if defined(__MTK_TARGET__)
/**
 *  This set of variables are for debug tracing...
 */
#if defined(VA2_VR_ENABLE_DEBUG_TRACE)
static kal_uint32 _va2_vr_debug_trace_size = 0;
static kal_uint32 _va2_vr_debug_trace_curr_idx = 0;
static va2_vr_debug_trace_entry_t *_va2_vr_debug_trace = NULL;

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
#endif
#endif  // #if defined(VA2_VR_ENABLE_DEBUG_TRACE)

kal_uint32 _va2_comp_video_renderer_idp_key = 0;
VIDEO_BUFFERHEADER_TYPE_T _va2_comp_video_renderer_rNewBuffHeader;

#if defined(__MEDIA_VT__)
/* under construction !*/
#endif

#if (!defined(DRV_IDP_6252_SERIES))
kal_uint32 _va2_vr_render_display_buffer_cnt = 0;
#endif

/**
 *  This set of variables are to control the usage of LCD
 *  @common none
 */
kal_bool   _va2_comp_vr_have_config_lcd = KAL_FALSE;

#if (!defined(DRV_IDP_6252_SERIES))
kal_uint32 _va2_comp_vr_triggered_lcd_id_this_time = 0;
#endif

VIDEO_BUFFERHEADER_TYPE_T _rBlackBufferHdr = { NULL };
VA2_VIDEO_FRAME_T _rBlackVdoFrm;

VIDEO_EXTMEM_HANDLER_T* _va2_vr_render_extmem_handler;

// VIDEO mutex for Video Renderer
static kal_mutexid eMutex;

#define CCASSERT(predicate) _x_CCASSERT_LINE(predicate, __LINE__)
#define _x_CCASSERT_LINE(predicate, line) typedef char constraint_violated_on_line_##line[2*((predicate)!=0)-1];

#endif  // #if defined(__MTK_TARGET__)

/****************************************************************************
 * external function bodies
 ****************************************************************************/
/**
 *  @status OK
 *  @param kal_uint32 no_of_entries Specify how many entries could be stored, must be 2^N, N is natural number.
 *  @param va2_vr_debug_trace_entry_t *storage Specify the storage for storing debugging logs.
 */
void
va2_vr_init_trace(
  kal_uint32 no_of_entries,
  va2_vr_debug_trace_entry_t *storage)
{
#if defined(__MTK_TARGET__)
#if defined(VA2_VR_ENABLE_DEBUG_TRACE)
  kal_uint32 saved_mask = SaveAndSetIRQMask();
  _va2_vr_debug_trace_size = no_of_entries;
  _va2_vr_debug_trace_curr_idx = 0;
  _va2_vr_debug_trace = storage;
  RestoreIRQMask(saved_mask);
#endif  // #if defined(VA2_VR_ENABLE_DEBUG_TRACE)
#endif  // #if defined(__MTK_TARGET__)
}

/**
 *  @status OK
 *  @param va2_vr_debug_trace_entry_t *storage Specify the storage for logging.
 *  @param va2_vr_debug_trace_id_t trace_id ID.
 *  @param kal_uint32 param 32-bit param, different definition for each trace ID.
 */
void
va2_vr_add_trace(
  va2_vr_debug_trace_entry_t *storage,
  va2_vr_debug_trace_id_t trace_id,
  kal_uint32 param)
{
#if defined(__MTK_TARGET__)
#if defined(VA2_VR_ENABLE_DEBUG_TRACE)
  kal_uint32 saved_mask;
  kal_uint32 register curr_idx;

  if (NULL == storage) { return; }

  saved_mask = SaveAndSetIRQMask();
  curr_idx = _va2_vr_debug_trace_curr_idx;
  ++_va2_vr_debug_trace_curr_idx;
  _va2_vr_debug_trace_curr_idx &= (_va2_vr_debug_trace_size - 1);
  RestoreIRQMask(saved_mask);

  storage[curr_idx].time_stamp = drv_get_current_time();
  storage[curr_idx].param = param;
  storage[curr_idx].trace_id = trace_id;
#endif  // #if defined(VA2_VR_ENABLE_DEBUG_TRACE)
#endif  // #if defined(__MTK_TARGET__)
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
#if defined(__MTK_TARGET__)
#if defined(VA2_VR_ENABLE_DEBUG_TRACE)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // #if defined(VA2_VR_ENABLE_DEBUG_TRACE)
#endif  // #if defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MTK_TARGET__)
#if defined(VA2_VR_ENABLE_DEBUG_TRACE)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // #if defined(VA2_VR_ENABLE_DEBUG_TRACE)
#endif  // #if defined(__MTK_TARGET__)
/* under construction !*/
#endif

/**
 *  @status OK
 */
kal_uint32
va2_vr_try_to_return_buffer_headers(
  va2_comp_video_renderer_cb_t *cb)
{
#if defined(__MTK_TARGET__)
  va2_util_buf_hdr_q_item_t *item = NULL;

  // while there is still item in the to be returned queue
  while (NULL != (item = va2_util_buf_hdr_q_peek(&(cb->vr_q_handle.to_be_returned_q))))
  {
    if(((VA2_VIDEO_FRAME_T*) (item->buffer_header.pPrivateData)) != ((VA2_VIDEO_FRAME_T*)(&_rBlackVdoFrm)))
    {
      // return it by invoking the FillThisBuffer hook of peer component
      if (VIDEO_ERROR_NONE != cb->state.rInputComp[0].prComp->pfnFillThisBuffer(&(item->buffer_header)))
      {
        // break if any error happens
        break;
      }
      va2_vr_add_trace(_va2_vr_debug_trace, VA2_VR_INTERNAL____RETURN_BUFFER_HEADER, (kal_uint32) (item->buffer_header.pu1Buffer));
    }
    else
    {
      va2_vr_add_trace(_va2_vr_debug_trace, VA2_VR_INTERNAL____RETURN_BLACK_BUFFER_HEADER, (kal_uint32) (((VA2_VIDEO_FRAME_T*) (item->buffer_header.pPrivateData))->pv_extra));
    }
    // dequeue from the to be returned queue...
    item = va2_util_buf_hdr_dequeue(&(cb->vr_q_handle.to_be_returned_q));
    // release q items back to pool...
    kal_mem_set((void*) item, 0x0, sizeof(va2_util_buf_hdr_q_item_t));
  }
#endif  // #if defined(__MTK_TARGET__)
  return 0;
}

/**
 *  @description IL Client has a limitation that the error notify event can't be sent under VR's Stop state
 */
void
va2_vr_notify_error_to_client(
  va2_comp_video_renderer_cb_t *cb)
{
  if ((NULL != cb) &&
      (NULL != cb->state.prCallback) &&
      (NULL != cb->state.prCallback->pfnEventHandler))
  {
    cb->state.prCallback->pfnEventHandler(VIDEO_EVENT_ERROR, 0, 0, NULL);
  }
  else
  {
    ASSERT(0); // No callback function set?
  }
}


/**
 *  @status OK
 */
VIDEO_ERROR_TYPE_T
va2_vr_t01_close_to_init(
  va2_comp_video_renderer_cb_t *cb)
{
#if defined(__MTK_TARGET__)

  kal_uint32 save_irq_mask;

  // 1. Allocate memory for queue item pool
  {
    CCASSERT(sizeof(va2_util_buf_hdr_q_item_t) == VA2_UTIL_BUF_HDR_Q_ITEM_T_STRUCT_SZ)
  }
  cb->vr_q_handle.q_item_pool = (va2_util_buf_hdr_q_item_t*) VideoGetExtBuffer(_va2_vr_render_extmem_handler, VA2_VR_UTIL_BUF_HDR_QUEUE_POOL_SZ);
  cb->vr_q_handle.q_item_pool_size = VA2_VR_VP_MAX_BH_COUNT;
  if (NULL == cb->vr_q_handle.q_item_pool)
  {
    cb->vr_q_handle.q_item_pool_size = 0;
    return VIDEO_ERROR_NO_MEMORY; // memory allocation fail
  }

#if defined(__VIDEO_SUBTITLE_SUPPORT__)
  if (cb->renderer_type == VIDEO_RENDERER_VIDEO_SUBTITLE_PLAYBACK)
  {
    // allocate subtitle queue buffer
    cb->sub_vr_q_handle.q_item_pool = (va2_util_buf_hdr_q_item_t*) VideoGetExtBuffer(_va2_vr_render_extmem_handler, VA2_VR_UTIL_BUF_HDR_QUEUE_POOL_SZ);
    cb->sub_vr_q_handle.q_item_pool_size = VA2_VR_VP_MAX_BH_COUNT;
    if (NULL == cb->sub_vr_q_handle.q_item_pool)
    {
      cb->sub_vr_q_handle.q_item_pool_size = 0;
      return VIDEO_ERROR_NO_MEMORY; // memory allocation fail
    }
  }
#endif

  // 2. Allocate Black Frame memory and init it as YUV420 planar format with minimal dimension (16x16)
  {
    _rBlackBufferHdr.pu1Buffer = (kal_uint8 *) VideoGetExtBuffer(_va2_vr_render_extmem_handler, VA2_VR_VP_BLACK_FRMSZ);
    if (NULL == _rBlackBufferHdr.pu1Buffer)
    {
      return VIDEO_ERROR_NO_MEMORY; // memory allocation fail
    }
    memset( (_rBlackBufferHdr.pu1Buffer)                                   ,    0, VA2_VR_VP_BLACK_FRM_Y_PLANE_SZ );
    memset(((_rBlackBufferHdr.pu1Buffer) + VA2_VR_VP_BLACK_FRM_Y_PLANE_SZ) , 0x80, VA2_VR_VP_BLACK_FRM_UV_PLANE_SZ);
    if (VideoCommIsExtBufferCacheable((kal_uint32)(_rBlackBufferHdr.pu1Buffer), VA2_VR_VP_BLACK_FRMSZ) == KAL_TRUE)
    {
        _rBlackBufferHdr.pu1Buffer = (kal_uint8 *) VideoCommExtBufferCacheableSwitch(
                                                     (kal_uint32) (_rBlackBufferHdr.pu1Buffer),
                                                     VA2_VR_VP_BLACK_FRMSZ,
                                                     VIDEO_NON_CACHEABLE);
    }

    _rBlackVdoFrm.r_fb_addr.u4_fb_addr_plane0 = ((kal_uint32) _rBlackBufferHdr.pu1Buffer);
    _rBlackVdoFrm.r_fb_addr.u4_fb_addr_plane1 = ((kal_uint32) _rBlackBufferHdr.pu1Buffer) + VA2_VR_VP_BLACK_FRM_Y_PLANE_SZ;
    _rBlackVdoFrm.r_fb_addr.u4_fb_addr_plane2 = ((kal_uint32) _rBlackBufferHdr.pu1Buffer) + VA2_VR_VP_BLACK_FRM_Y_PLANE_SZ + (VA2_VR_VP_BLACK_FRM_UV_PLANE_SZ/2);
    _rBlackVdoFrm.r_fb_size.u4_width = VA2_VR_VP_BLACK_FRM_WIDTH;
    _rBlackVdoFrm.r_fb_size.u4_height = VA2_VR_VP_BLACK_FRM_HEIGHT;
    //_rBlackVdoFrm.r_clip_window.b_clip_enable = KAL_FALSE;
    //_rBlackVdoFrm.r_clip_window.u4_clip_left = 0;
    //_rBlackVdoFrm.r_clip_window.u4_clip_top = 0;
    _rBlackVdoFrm.r_clip_window.u4_clip_right = VA2_VR_VP_BLACK_FRM_WIDTH-1;
    _rBlackVdoFrm.r_clip_window.u4_clip_bottom = VA2_VR_VP_BLACK_FRM_HEIGHT-1;
    _rBlackVdoFrm.eFrameColorFmt = VIDEO_RENDERER_COLOR_YUV420;
    //_rBlackVdoFrm.pv_extra = 0;
    //_rBlackVdoFrm.r_dithering_info.u4AVunSyncTime = 0;
    _rBlackVdoFrm.r_frame_aspect_ratio.i4AspectRatioWidth = 1;
    _rBlackVdoFrm.r_frame_aspect_ratio.i4AspectRatioHeight = 1;
    _rBlackVdoFrm.r_dithering_info.u4MaxAVunSyncTime = 10,000,000;

    _rBlackBufferHdr.u4BuffSize = VA2_VR_VP_BLACK_FRMSZ;
    _rBlackBufferHdr.pPrivateData = (void*) &_rBlackVdoFrm;
  }

  //  3. init video renderer internal data
  {
    save_irq_mask = SaveAndSetIRQMask();
    va2_util_buf_hdr_reset_buffer_header_queues(&(cb->vr_q_handle));
    RestoreIRQMask(save_irq_mask);

#if defined(__VIDEO_SUBTITLE_SUPPORT__)
    if (cb->renderer_type == VIDEO_RENDERER_VIDEO_SUBTITLE_PLAYBACK)
    {
      save_irq_mask = SaveAndSetIRQMask();
      va2_util_buf_hdr_reset_buffer_header_queues(&(cb->sub_vr_q_handle));
      RestoreIRQMask(save_irq_mask);
    }
#endif

    #if 0 // will config when set_parameter
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
    cb->u4MaxLcdTransferDuration = 35;  //initial value for u4RecentRenderDuration

#if defined(__VIDEO_SUBTITLE_SUPPORT__)
    if (cb->renderer_type == VIDEO_RENDERER_VIDEO_SUBTITLE_PLAYBACK)
    {
      //kal_mem_set(&cb->sub_src_fb_addr, 0x0, sizeof(VA2_FRAME_BUFFER_ADDRESS_T));
      //kal_mem_set(&cb->sub_src_size, 0x0, sizeof(VA2_FRAME_SIZE_T));
      //cb->sub_src_color_format = VIDEO_RENDERER_COLOR_DEFAULT_ERR;
      //kal_mem_set(&cb->sub_dst_size, 0x0, sizeof(VA2_FRAME_SIZE_T));
      //kal_mem_set(&cb->sub_dst_fb_size, 0x0, sizeof(VA2_FRAME_SIZE_T));
      //cb->sub_dst_color_format = VIDEO_RENDERER_COLOR_DEFAULT_ERR;
      kal_mem_set(&(cb->sub_dst_fb_addr_array[0]), 0x0, sizeof(VA2_FRAME_BUFFER_ADDRESS_T)*VA2_COMP_VR_MAX_DSPL_FB_COUNT);
      kal_mem_set(&cb->sub_display_surface, 0x0, sizeof(va2_video_renderer_display_surface_t));
    }
#endif
  }

  if (NULL == cb->EventID)
  {
    cb->EventID = kal_create_event_group("RENDERER_EVENTS");
  }

  // 4. invoke VideoCommInit() to change to INIT state.
  {
    VIDEO_PORT_CONFIG_T r_video_intput_port;
#if (!defined(DRV_IDP_6252_SERIES))
    VIDEO_PORT_CONFIG_T r_subtitle_intput_port;
#endif
    VIDEO_COMPONENT_INIT_T r_init_config;

    r_video_intput_port.ePortType = VIDEO_PORT_VIDEO_DATA;
    r_video_intput_port.fgSupplier = KAL_FALSE;
    // TODO:[3] What is this and the relationship with VIDEO_COMPONENT_INIT_T.u4InputBuffQSize?
    // TODO:[3] Could we use this for buffer header queue management?
    r_video_intput_port.u4BuffSize = 0;

#if (!defined(DRV_IDP_6252_SERIES))
    r_subtitle_intput_port.ePortType = VIDEO_PORT_SUBTITLE;
    r_subtitle_intput_port.fgSupplier = KAL_FALSE;
    r_subtitle_intput_port.u4BuffSize = 0;
#endif

    kal_mem_set(&r_init_config, 0x0, sizeof(r_init_config));
    r_init_config.prInputPort1 = &r_video_intput_port;

#if (!defined(DRV_IDP_6252_SERIES))
    r_init_config.prInputPort2 = &r_subtitle_intput_port;
#else
    r_init_config.prInputPort2 = NULL;
#endif

    r_init_config.prOutputPort1 = NULL;
    r_init_config.prOutputPort2 = NULL;
    // Note this! It seems command queue is used to queue command when command handling is in component own task...
    // Note this! Since video renderer runs in caller's context, command is directly handled, so no command queue is in need...
    r_init_config.u4CmdQSize = 0;
    // TODO:[3] Check what is this and how to use it...
    r_init_config.u4InputBuffQSize = 0;
    // TODO:[3] Check what is this and how to use it...
    r_init_config.u4OutputBuffQSize = 0;

    r_init_config.prExtMemHdlr = _va2_vr_render_extmem_handler;
    r_init_config.eMutex = eMutex = VideoGetMutex(MUTEX_USER_VIDEO_RENDERER);

    // TODO:[2] "VIDEO_COMM_RENDER"? Could we rename it?
    if (VIDEO_ERROR_NONE != VideoCommInit(&(cb->state), &r_init_config, "VA2_VR"))
    {
      // free the mutex before return
      va2_vr_deinit(cb);
      return VIDEO_ERROR_INIT_ERROR;
    }
  }

#endif  // #if defined(__MTK_TARGET__)

  return VIDEO_ERROR_NONE;
}


/**
 *  @status OK
 */
VIDEO_ERROR_TYPE_T
va2_vr_t02_init_to_close(
  va2_comp_video_renderer_cb_t *cb)
{
#if defined(__MTK_TARGET__)
  va2_vr_add_trace(_va2_vr_debug_trace, VA2_VR_TRANSITION__T02_INIT_TO_CLOSE, 0);

  //  1. deinit video renderer internal data

  //    1.1 destroy semaphore
  //    ==> there is no way to destroy a kal semaphore...

  //  2. [2009/12/04 ctfang] state machine changed, unnecessary to invoke VideoCommDeInit()
  VideoCommChangeState(&(cb->state), VIDEO_STATE_CLOSE);

#endif  // #if defined(__MTK_TARGET__)
  return VIDEO_ERROR_NONE;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // #if defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else   // #if defined(__MTK_TARGET__)
/* under construction !*/
#endif  // #if defined(__MTK_TARGET__)
/* under construction !*/
#endif

/**
 *  @status OK
 */
VIDEO_ERROR_TYPE_T
va2_vr_t07_run_to_idle(
  va2_comp_video_renderer_cb_t *cb)
{
#if defined(__MTK_TARGET__)
  va2_vr_add_trace(_va2_vr_debug_trace, VA2_VR_TRANSITION__T07_RUN_TO_IDLE, 0);
  // currently not supported
  ASSERT(0);
#endif  // #if defined(__MTK_TARGET__)
  return VIDEO_ERROR_NONE;
}

/**
 *  @status OK
 */
VIDEO_ERROR_TYPE_T
va2_vr_t08_stop_to_idle(
  va2_comp_video_renderer_cb_t *cb)
{
#if defined(__MTK_TARGET__)
  kal_uint32 save_irq_mask;

  va2_vr_add_trace(_va2_vr_debug_trace, VA2_VR_TRANSITION__T08_STOP_TO_IDLE, 0);

  save_irq_mask = SaveAndSetIRQMask();
  //  1. Directly clear all buffer headers in to-be-processed queue and to-be-returned queue and the current buffer!
  va2_util_buf_hdr_reset_buffer_header_queues(&cb->vr_q_handle);
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

  cb->bIsErrorNotified = KAL_FALSE;

  //  2. Invoke VideoCommChangeState() to change state to IDLE state.
  VideoCommChangeState(&cb->state, VIDEO_STATE_IDLE);

#endif  // #if defined(__MTK_TARGET__)
  return VIDEO_ERROR_NONE;
}

/**
 *  @status OK
 */
VIDEO_ERROR_TYPE_T
va2_vr_t09_idle_to_init(
  va2_comp_video_renderer_cb_t *cb)
{
#if defined(__MTK_TARGET__)

  va2_vr_add_trace(_va2_vr_debug_trace, VA2_VR_TRANSITION__T09_IDLE_TO_INIT, 0);
  // currently not supported
  ASSERT(0);
#endif  // #if defined(__MTK_TARGET__)
  return VIDEO_ERROR_NONE;
}

/**
 *  @status OK
 */
VIDEO_ERROR_TYPE_T
va2_vr_t11_stop_to_close(
  va2_comp_video_renderer_cb_t *cb)
{
#if defined(__MTK_TARGET__)
  va2_vr_add_trace(_va2_vr_debug_trace, VA2_VR_TRANSITION__T11_STOP_TO_CLOSE, 0);

  return cb->funcs.t10_idle_to_close(cb);
#else   // #if defined(__MTK_TARGET__)
  return VIDEO_ERROR_NONE;
#endif  // #if defined(__MTK_TARGET__)
}

/**
 *  @status OK
 */
VIDEO_ERROR_TYPE_T
va2_vr_t12_idle_to_idle(
  va2_comp_video_renderer_cb_t *cb)
{
#if defined(__MTK_TARGET__)
  kal_uint32 save_irq_mask;

  va2_vr_add_trace(_va2_vr_debug_trace, VA2_VR_TRANSITION__T12_IDLE_TO_IDLE, 0);

  save_irq_mask = SaveAndSetIRQMask();
  //  1. Directly clear all buffer headers in Qtbp and Qtbr and the current buffer!
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

  cb->bIsErrorNotified = KAL_FALSE;

  //  2. Invoke VideoCommChangeState() to change state to IDLE state.
  VideoCommChangeState(&(cb->state), VIDEO_STATE_IDLE);

#endif  // #if defined(__MTK_TARGET__)
  return VIDEO_ERROR_NONE;
}

/**
 *  @status OK
 */
VIDEO_ERROR_TYPE_T
va2_vr_send_command(
  va2_comp_video_renderer_cb_t *cb,
  VIDEO_COMMAND_TYPE_T eCmd,
  kal_uint32 u4Param)
{
#if defined(__MTK_TARGET__)
  VIDEO_ERROR_TYPE_T result = VIDEO_ERROR_INPUT_PARAM_ERROR;

  if (VIDEO_COMMAND_STATESET == eCmd)
  {
    va2_vr_add_trace(_va2_vr_debug_trace, VA2_VR_API_________SEND_COMMAND__STATE_SET, u4Param);

    kal_take_sem(cb->vr_sema_vrstate_sync, KAL_INFINITE_WAIT);

    switch (cb->state.eState)
    {
    case VIDEO_STATE_INIT:
      if (VIDEO_STATE_INIT == u4Param)
      {
        // self transition and do nothing
        va2_vr_add_trace(_va2_vr_debug_trace, VA2_VR_TRANSITION__T00_SELF_TRANSITION, u4Param);
        VideoCommChangeState(&(cb->state), VIDEO_STATE_INIT);
        result = VIDEO_ERROR_NONE;
      }
      else if (VIDEO_STATE_IDLE == u4Param)
      {
        result = cb->funcs.t03_init_to_idle(cb);
      }
      else if (VIDEO_STATE_CLOSE == u4Param)
      {
        result = cb->funcs.t02_init_to_close(cb);
      }
      break;

    case VIDEO_STATE_IDLE:
      if (VIDEO_STATE_CLOSE == u4Param)
      {
        result = cb->funcs.t10_idle_to_close(cb);
      }
      else if (VIDEO_STATE_INIT == u4Param)
      {
        result = cb->funcs.t09_idle_to_init(cb);
      }
      else if (VIDEO_STATE_IDLE == u4Param)
      {
        result = cb->funcs.t12_idle_to_idle(cb);
      }
      else if (VIDEO_STATE_RUN == u4Param)
      {
        result = cb->funcs.t04_idle_to_run(cb);
      }
      break;

    case VIDEO_STATE_RUN:
      if (VIDEO_STATE_IDLE == u4Param)
      {
        result = cb->funcs.t07_run_to_idle(cb);
      }
      else if (VIDEO_STATE_RUN == u4Param)
      {
        // self transition and do nothing
        va2_vr_add_trace(_va2_vr_debug_trace, VA2_VR_TRANSITION__T00_SELF_TRANSITION, u4Param);
        VideoCommChangeState(&(cb->state), VIDEO_STATE_RUN);
        result = VIDEO_ERROR_NONE;
      }
      else if (VIDEO_STATE_STOP == u4Param)
      {
        result = cb->funcs.t05_run_to_stop(cb);
      }
      break;

    case VIDEO_STATE_STOP:
      if (VIDEO_STATE_CLOSE == u4Param)
      {
        result = cb->funcs.t11_stop_to_close(cb);
      }
      else if (VIDEO_STATE_IDLE == u4Param)
      {
        result = cb->funcs.t08_stop_to_idle(cb);
      }
      else if (VIDEO_STATE_RUN == u4Param)
      {
        result = cb->funcs.t06_stop_to_run(cb);
      }
      else if (VIDEO_STATE_STOP == u4Param)
      {
        // self transition and do nothing
        va2_vr_add_trace(_va2_vr_debug_trace, VA2_VR_TRANSITION__T00_SELF_TRANSITION, u4Param);
        VideoCommChangeState(&(cb->state), VIDEO_STATE_STOP);
        result = VIDEO_ERROR_NONE;
      }
      break;

#if 1 //annu
    case VIDEO_STATE_CLOSE:
      if (VIDEO_STATE_INIT == u4Param)
      {
        VideoCommChangeState(&(cb->state), VIDEO_STATE_INIT);
        result = VIDEO_ERROR_NONE;
      }
      break;
#endif

    default:
      break;
    }

    kal_give_sem(cb->vr_sema_vrstate_sync);
  }

  return result;
#else   // #if defined(__MTK_TARGET__)
  return VIDEO_ERROR_NONE;
#endif  // #if defined(__MTK_TARGET__)
}

/**
 *  @status OK
 */
VIDEO_ERROR_TYPE_T
va2_vr_use_buffer(
  va2_comp_video_renderer_cb_t *cb,
  kal_uint8 *pu1Buff,
  kal_uint32 u4Size)
{
  VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
#if defined(__MTK_TARGET__)
  va2_vr_add_trace(_va2_vr_debug_trace, VA2_VR_API_________USE_BUFFER, (kal_uint32) pu1Buff);

  ASSERT(0); // This primitive is not supported!
#endif  // #if defined(__MTK_TARGET__)
  return eError;
}

/**
 *  @status OK
 */
VIDEO_ERROR_TYPE_T
va2_vr_fill_this_buffer(
  va2_comp_video_renderer_cb_t *cb,
  VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
  VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
#if defined(__MTK_TARGET__)

  ASSERT(0); // This primitive is not supported!

  va2_vr_add_trace(_va2_vr_debug_trace, VA2_VR_API_________FILL_THIS_BUFFER, (kal_uint32) prBuffHeader);
#endif  // #if defined(__MTK_TARGET__)

  return eError;
}

/**
 *  @status OK
 */
VIDEO_ERROR_TYPE_T
va2_vr_set_callbacks(
  va2_comp_video_renderer_cb_t *cb,
  VIDEO_CALLBACK_TYPE_T *prCallback)
{
  VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
#if defined(__MTK_TARGET__)
  va2_vr_add_trace(_va2_vr_debug_trace, VA2_VR_API_________SET_CALLBACKS, (kal_uint32) prCallback);

  // TODO:[2] protect this function with semaphore? and only allow invokation in NU+ task level.
#if 0 //annu
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
  eError = VideoCommSetCallbacks(&(cb->state), prCallback);
#endif  // #if defined(__MTK_TARGET__)
  return eError;
}

/**
 *  @status OK
 *  @remark this function could only be invoked when in CLOSE state.
 */
VIDEO_ERROR_TYPE_T
va2_vr_deinit(
  va2_comp_video_renderer_cb_t *cb)
{
#if defined(__MTK_TARGET__)
  va2_vr_add_trace(_va2_vr_debug_trace, VA2_VR_API_________DEINIT, 0);

  VideoFreeMutex(MUTEX_USER_VIDEO_RENDERER, eMutex);
  return VideoCommDeInit(&(cb->state));

#else
  return VIDEO_ERROR_NONE;
#endif

}

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif

/**
 *  @status OK
 */
VIDEO_COMPONENT_TYPE_T*
GetVideoRendererHandle(
  VA2_VIDEO_RENDERER_TYPE_T eType,
  VIDEO_EXTMEM_HANDLER_T* prExtmemHandler,
  VIDEO_INTMEM_HANDLER_T* prIntmemHandler)
{
#if defined(__MTK_TARGET__)
  VIDEO_COMPONENT_TYPE_T *prVideoRendererComp = NULL;
  VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

#if defined(__MM_DCM_SUPPORT__)
  DCM_Load(DYNAMIC_CODE_COMPRESS_RENDER, NULL, NULL);
#endif

  _va2_vr_render_extmem_handler = prExtmemHandler;

  switch (eType)
  {
  case VIDEO_RENDERER_VIDEO_THUMBNAIL:
  case VIDEO_RENDERER_VIDEO_PLAYBACK:
  case VIDEO_RENDERER_MJPG_THUMBNAIL:
  case VIDEO_RENDERER_MJPG_PLAYBACK:
  case VIDEO_RENDERER_VIDEO_SUBTITLE_PLAYBACK:
  case VIDEO_RENDERER_MJPG_SUBTITLE_PLAYBACK:
    prVideoRendererComp = va2_video_renderer_vp_get_handle(eType);
    break;

#if defined(__MEDIA_VT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

  default:
    break;
  }

  if (NULL != prVideoRendererComp)
  {
    eError = prVideoRendererComp->pfnInit();
    if (VIDEO_ERROR_NONE != eError)
    {
      // if init failed, it is unnecessary to deinit the component...
      prVideoRendererComp = NULL;
    }
  }

  return prVideoRendererComp;
#else   // #if defined(__MTK_TARGET__)
  return NULL;
#endif  // #if defined(__MTK_TARGET__)

}

/**
 *  @status OK
 */
VIDEO_ERROR_TYPE_T
ReleaseVideoRendererHandle(
  VIDEO_COMPONENT_TYPE_T *prHandle)
{
  VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

#if defined(__MTK_TARGET__)
  if (prHandle != NULL)
  {
    eError = prHandle->pfnDeInit();
  }
  else
  {
    eError = VIDEO_ERROR_DEINIT_ERROR;
  }
#else
  eError = VIDEO_ERROR_DEINIT_ERROR;
#endif

#if defined(__MM_DCM_SUPPORT__)
  DCM_Unload(DYNAMIC_CODE_COMPRESS_RENDER);
#endif
  return eError;
}


/// @}
#endif  // #if defined(__VIDEO_ARCHI_V2__)

