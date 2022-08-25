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
 *    va2_video_renderer_vt.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    OpenMAX-like Video Renderer of Video Architecture V2.
 *    This contains the common part of Video Renderer for Video Playback in Video Telephony. 
 *    This file contains a factory method to return handles of VR.VT based on HW platforms.
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
 *
 ****************************************************************************/
/// \ingroup va2_video_renderer_vt
/// @{
#ifdef __VIDEO_ARCHI_V2__

/****************************************************************************
 * internal options
 ****************************************************************************/

/****************************************************************************
 * include directives
 ****************************************************************************/
#include "kal_public_api.h"
/******* VA2 common *************************/
#include "video_types_v2.h"
//#include "video_comm_component_v2.h" // unnecessary for now...
//#include "video_buffer_management_v2.h" // unnecessary for now...
/******* VA2 Video Renderer Component *******/
#include "va2_comp_video_renderer.h"
#include "va2_video_renderer_common.h"
#include "va2_video_renderer_vt.h"
#include "va2_video_renderer_vt_mt6236.h"
#include "va2_video_renderer_vt_mt6268.h"
#include "va2_video_renderer_vt_mt6276.h"
#include "va2_video_renderer_vt_mt6256_e2.h"
/******* driver common **********************/
//#include "drv_comm.h" // unnecessary for now...

/****************************************************************************
 * external function bodies
 ****************************************************************************/
VIDEO_COMPONENT_TYPE_T* 
va2_video_renderer_vt_get_handle(
  VA2_VIDEO_RENDERER_TYPE_T e_type)
{
#if(defined(__MTK_TARGET__) && defined(__MEDIA_VT__))

#if defined(VA2_VIDEO_RENDERER_VT_MT6236)
  return va2_video_renderer_vt_mt6236_get_handle(e_type);
#elif defined(VA2_VIDEO_RENDERER_VT_MT6268)
  return va2_video_renderer_vt_mt6268_get_handle(e_type);
#elif defined(VA2_VIDEO_RENDERER_VT_MT6276)
  return va2_video_renderer_vt_mt6276_get_handle(e_type);
#elif defined(VA2_VIDEO_RENDERER_VT_MT6256_E2)
  return va2_video_renderer_vt_mt6256_get_handle(e_type);
#else   // options for VR.VP implementation
  return NULL;
#endif  // options for VR.VP implementation

#else   // #if(defined(__MTK_TARGET__) && defined(__MEDIA_VT__))
  return NULL;
#endif  // #if(defined(__MTK_TARGET__) && defined(__MEDIA_VT__))
}

VIDEO_ERROR_TYPE_T 
va2_video_renderer_vt_release_handle(
  VIDEO_COMPONENT_TYPE_T *pr_handle)
{
#if(defined(__MTK_TARGET__) && defined(__MEDIA_VT__))

#if defined(VA2_VIDEO_RENDERER_VT_MT6236)
  return va2_video_renderer_vt_mt6236_release_handle(pr_handle);
#elif defined(VA2_VIDEO_RENDERER_VT_MT6268)
  return va2_video_renderer_vt_mt6268_release_handle(pr_handle);
#elif defined(VA2_VIDEO_RENDERER_VT_MT6276)
  return va2_video_renderer_vt_mt6276_release_handle(pr_handle);
#elif defined(VA2_VIDEO_RENDERER_VT_MT6256_E2)
  return va2_video_renderer_vt_mt6256_release_handle(pr_handle);
#else   // options for VR.VP implementation
  return VIDEO_ERROR_DEINIT_ERROR;
#endif  // options for VR.VP implementation

#else   // #if(defined(__MTK_TARGET__) && defined(__MEDIA_VT__))
  return VIDEO_ERROR_DEINIT_ERROR;
#endif  // #if(defined(__MTK_TARGET__) && defined(__MEDIA_VT__))
}

#if defined(VA2_VIDEO_RENDERER_VT_MT6268) || defined(VA2_VIDEO_RENDERER_VT_MT6236) || defined(VA2_VIDEO_RENDERER_VT_MT6256_E2)

void
_va2_vr_vt_trigger_empty_this_buffer(
  va2_comp_video_renderer_cb_t *cb, 
  kal_uint32* idp_key, 
  va2_vr_debug_trace_entry_t* _va2_vr_vt_debug_trace)
{
  //va2_comp_video_renderer_cb_t *cb = &_va2_vr_vt_6268_cb;
  kal_bool busy;

#if defined(VIDEO_CALL_TIME_SHARING_ENABLE_SWLA_TRACE)
  SLA_CustomLogging("DED", 1);
#endif	// #if defined(VIDEO_CALL_TIME_SHARING_ENABLE_SWLA_TRACE)

  if (KAL_TRUE == cb->bypass)
  {
#if defined(VIDEO_CALL_TIME_SHARING_ENABLE_SWLA_TRACE)
    SLA_CustomLogging("DED", 0);
#endif	// #if defined(VIDEO_CALL_TIME_SHARING_ENABLE_SWLA_TRACE)
    //1.You don't need to check trigger_display, because you must trigger encode display whatever.
    //2.You must trigger encode display when the renderer is in bypass mode (bypass=KAL_TRUE);      
    //if (KAL_FALSE== cb->trigger_display)
    // TODO: See If add callback function pointer to NULL
    {
      idp_trigger_video_call_encode_display_cb();
    }
  }
  else
  {
    //Query idp_video_call_decode key to use
    {
      idp_video_call_query_key(idp_key);
      if (*idp_key==0)
      {
        ASSERT(0);
      }
    }

    if (cb->state.eState != VIDEO_STATE_RUN)
    {
#if defined(VIDEO_CALL_TIME_SHARING_ENABLE_SWLA_TRACE)
      SLA_CustomLogging("DED", 0);
#endif	// #if defined(VIDEO_CALL_TIME_SHARING_ENABLE_SWLA_TRACE)
      //if (KAL_FALSE== cb->trigger_display)
      // TODO: See If add callback function pointer to NULL
      {
        //1.Plutmmi snapshot will not pause/resume, so we need a flag to check get frame or not?
        //Cosmos mmi snashot will pause/resume at present, but it doesn't affect the behavior in Time Sharing Mechanism.
        //2.If current buffer is null, we don't use black frame to blt temporary. The MMI will clear it by default.
        //Don't forget to blt encode display buffer (idp_trigger_video_call_encode_display_cb)
        //3.You don't need to check trigger_display, because you must trigger encode display whatever.
        if (_va2_vr_vt_get_frame == KAL_TRUE)
        {
          va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
          if (NULL == cb->vr_q_handle.curr_dspl_buf_hdr)
          {
            idp_trigger_video_call_encode_display_cb();
          }
          else
          {
            cb->funcs.render_dspl_frame_buf(cb, KAL_TRUE);
          }
        }
        else
        {
          idp_trigger_video_call_encode_display_cb();
        }
      }
    }
    else
    {
      ASSERT(KAL_TRUE == idp_video_call_decode_is_busy(*idp_key, &busy));
      if (KAL_FALSE == busy)
      {
        //If current buffer is null, we don't use black frame to blt temporary. The MMI will clear it by default.
        //Don't forget to blt encode display buffer (idp_trigger_video_call_encode_display_cb)
        va2_util_buf_hdr_advance_to_the_latest_buffer_header(&(cb->vr_q_handle));
        va2_vr_add_trace(_va2_vr_vt_debug_trace, VA2_VR_API_________EMPTY_THIS_BUFFER__TRIGGER_HW, (kal_uint32) (cb->vr_q_handle.curr_dspl_buf_hdr));
        if (NULL == cb->vr_q_handle.curr_dspl_buf_hdr)
        {
          idp_trigger_video_call_encode_display_cb();
        }
        else
        {
          cb->funcs.render_dspl_frame_buf(cb, KAL_FALSE);
        }
      }
      else
      {
        va2_vr_add_trace(_va2_vr_vt_debug_trace, VA2_VR_API_________EMPTY_THIS_BUFFER__ENQUEUE_ONLY, (kal_uint32) (cb->vr_q_handle.to_be_processed_q.tail));
        idp_trigger_video_call_encode_display_cb();
      }
    }
  }
}
#endif  //#if defined(VA2_VIDEO_RENDERER_VT_MT6268) || defined(VA2_VIDEO_RENDERER_VT_MT6236) || defined(VA2_VIDEO_RENDERER_VT_MT6256_E2)

#endif	// #ifdef __VIDEO_ARCHI_V2__
/// @}

