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
 *   npplg_av_stream.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   This file includes the structures and enums used by video streaming instance.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef NPPLG_AV_STREAM_H
#define NPPLG_AV_STREAM_H

#include "MMI_features.h"
   
#if defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__MMI_VIDEO_STREAM__)

#include "kal_general_types.h"
#include "npplg_av_main.h"


/************************************************************
 * Define
 ************************************************************/

/* This timer interval is used to check if stream buffer data is enough to let driver play smoothly. */
#define NPPLG_AV_STREAM_BUF_CHECK_INTERVAL 300 /* 0.3 second */


/************************************************************
 * Typedef
 ************************************************************/

/* The state of the video plug-in instance which is responsible of handling video streaming */
typedef enum
{
  NPPLG_AV_STREAM_OBJ_STATE_IDLE = 0,
  NPPLG_AV_STREAM_OBJ_STATE_DOWNLOADING,
  NPPLG_AV_STREAM_OBJ_STATE_WAITING_PLAY,
  NPPLG_AV_STREAM_OBJ_STATE_INITED,
  NPPLG_AV_STREAM_OBJ_STATE_INITED_PLAY,
  NPPLG_AV_STREAM_OBJ_STATE_CONNECTING,
  NPPLG_AV_STREAM_OBJ_STATE_CONNECTED,
  NPPLG_AV_STREAM_OBJ_STATE_BUFFERING,
#ifdef __COSMOS_MMI_PACKAGE__
  NPPLG_AV_STREAM_OBJ_STATE_CREATE_VDO_LAYER,
#endif
  NPPLG_AV_STREAM_OBJ_STATE_PLAYING,
  NPPLG_AV_STREAM_OBJ_STATE_SEEKING,
  NPPLG_AV_STREAM_OBJ_STATE_LAUNCH_MEDIA_PLAYER,
  NPPLG_AV_STREAM_OBJ_STATE_RESET_PLAY_PANEL,
  NPPLG_AV_STREAM_OBJ_STATE_PAUSED_PLAY
} npplg_av_stream_obj_state_enum;


/************************************************************
 * Global Function
 ************************************************************/
extern void npplg_av_stream_handle_event(npplg_av_instance_struct *plugin_data, kal_uint8 event);
extern kal_int16 npplg_av_stream_handle_timer_event(npplg_av_instance_struct * plugin_data, kal_uint8 timer_type);
extern void npplg_av_stream_handle_url_rsp(npplg_av_instance_struct * plugin_data, NPReason download_rsp);
extern void npplg_av_stream_play(npplg_av_instance_struct *plugin_data);
extern kal_bool npplg_av_stream_update_layer_pause(npplg_av_instance_struct *plugin_data);
extern void npplg_av_stream_update_layer_resume(npplg_av_instance_struct *plugin_data, kal_bool seek_play, kal_bool lcm_update);
extern void npplg_av_stream_suspend_by_app(npplg_av_instance_struct *plugin_data);
extern void npplg_av_stream_resume_by_app(npplg_av_instance_struct *plugin_data);
extern void npplg_av_stream_close_by_app(npplg_av_instance_struct *plugin_data);
extern void npplg_av_stream_visual_update(npplg_av_instance_struct *plugin_data, kal_bool lcm_update, kal_bool clear_vdo_layer);
extern void npplg_av_stream_stop_by_app_for_screen_rotate(npplg_av_instance_struct *plugin_data);
extern void npplg_av_stream_handle_suspend_background_play_rsp(npplg_av_instance_struct *plugin_data, kal_int32 result);
extern void npplg_av_stream_mmi_resume_ind_handler(npplg_av_instance_struct *plugin_data);
#ifdef __COSMOS_MMI_PACKAGE__
extern void npplg_av_stream_prepare_vdo_layer(npplg_av_instance_struct *plugin_data);
extern void npplg_av_stream_create_vdo_layer_rsp_handler(npplg_av_instance_struct *plugin_data, gdi_handle vdo_layer);
#endif

#endif /* defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__MMI_VIDEO_STREAM__) */
#endif /* NPPLG_AV_STREAM_H */
