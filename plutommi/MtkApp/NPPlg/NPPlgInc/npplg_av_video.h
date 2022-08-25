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
 *   npplg_av_video.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   This file includes the structures and enums used by video instance.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef NPPLG_AV_VIDEO_H
#define NPPLG_AV_VIDEO_H

#include "MMI_features.h"
#include "gdi_datatype.h"
#include "npplg_av_main.h"
#include "kal_general_types.h"


#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
/************************************************************
 * Define
 ************************************************************/

/*
 * Progressive download peeking buffer size (in Bytes)
 * A/V Plug-in have to peek the video file to see if it is a progressive download file.
 */
#define NPPLG_AV_PDL_PEEK_SIZE 2048 /* 2K */

/* This timer interval is used to check if PDL buffer percent reaches 100%. */
#if defined(__MMI_VIDEO_PDL__)
#define NPPLG_AV_PDL_BUF_CHECK_INTERVAL 300 /* 0.3 second */
#endif


/************************************************************
 * Typedef
 ************************************************************/

/* The state of the video plug-in instance which is responsible of handling video file and progressive downloadable video */
typedef enum
{
  NPPLG_AV_VIDEO_OBJ_STATE_IDLE = 0,
  NPPLG_AV_VIDEO_OBJ_STATE_PRE_BUFFERING,
  NPPLG_AV_VIDEO_OBJ_STATE_DOWNLOADING,
  NPPLG_AV_VIDEO_OBJ_STATE_WAITING_PLAY,
  NPPLG_AV_VIDEO_OBJ_STATE_PDL_OPENING,
#ifdef __COSMOS_MMI_PACKAGE__
  NPPLG_AV_VIDEO_OBJ_STATE_CREATE_VDO_LAYER,
#endif
  NPPLG_AV_VIDEO_OBJ_STATE_BUFFERING,
  NPPLG_AV_VIDEO_OBJ_STATE_PLAYING,
  NPPLG_AV_VIDEO_OBJ_STATE_PAUSED,
  NPPLG_AV_VIDEO_OBJ_STATE_SEEKING,
  NPPLG_AV_VIDEO_OBJ_STATE_WAITING_SEEK_RSP,
  NPPLG_AV_VIDEO_OBJ_STATE_LAUNCH_MEDIA_PLAYER, /* Indicate whether plug-in should launch media player after the video is downloaded */
  NPPLG_AV_VIDEO_OBJ_STATE_RESET_PLAY_PANEL,
  NPPLG_AV_VIDEO_OBJ_STATE_PAUSED_PLAY
} npplg_av_video_obj_state_enum;


/* Additional video information */
typedef struct
{
  kal_uint64    total_time;             /* The duration of the object (video or audio) */
  kal_uint64    play_time;              /* The time that the object (video or audio) is playing */
  gdi_handle    vdo_layer_handle;       /* Video layer handle */
  kal_int32     pdl_buf_percentage;     /* PDL buffer percentage */
  kal_int32     vdo_width;              /* Video width */
  kal_int32     vdo_height;             /* Video height */
  kal_int32     layer_x;                /* The x coordinate of the video layer (relative to LCD) */
  kal_int32     layer_y;                /* The y coordinate of the video layer (relative to LCD) */
  kal_int32     layer_w;                /* The width of the video layer */
  kal_int32     layer_h;                /* The height of the video layer */
  kal_int32     offset_x;               /* The distance between object and video layer */
  kal_int32     offset_y;
  kal_bool      audio_only;             /* Indicate if the video only with audio track */
  kal_bool      is_pdl_or_rtsp;         /* Indicate the video is a PDL video or the video is rtsp:// */
  kal_bool      lcm_update;
#ifdef __COSMOS_MMI_PACKAGE__
  kal_bool      create_vdo_frame;
#endif
} npplg_av_video_data_struct;

/* Represent a rectangle */
typedef struct
{
  kal_int32 x1;
  kal_int32 y1;
  kal_int32 x2;
  kal_int32 y2;
} npplg_av_video_rect_struct;


/************************************************************
 * Global Function
 ************************************************************/
extern void npplg_av_video_handle_event(npplg_av_instance_struct *plugin_data, kal_uint8 event);
extern kal_int16 npplg_av_video_handle_timer_event(npplg_av_instance_struct *plugin_data, kal_uint8 timer_type);
extern void npplg_av_video_check_pdl_format(npplg_av_instance_struct *plugin_data);
extern void npplg_av_video_handle_url_rsp(npplg_av_instance_struct *plugin_data, NPReason download_rsp);
extern void npplg_av_video_get_best_fit_size(npplg_av_instance_struct *plugin_data);
extern void npplg_av_video_start_to_play(npplg_av_instance_struct *plugin_data);
extern void npplg_av_video_decide_layout(npplg_av_instance_struct *plugin_data);
extern void npplg_av_video_show_additional_info(npplg_av_instance_struct *plugin_data, gdi_handle paint_layer);
extern void npplg_av_video_redraw_window(npplg_av_instance_struct *plugin_data);
extern void npplg_av_video_set_position(npplg_av_instance_struct *plugin_data);
extern void npplg_av_video_reset_vdo_data(npplg_av_instance_struct *plugin_data);
extern void npplg_av_video_set_state_to_idle(npplg_av_instance_struct *plugin_data);
extern kal_bool npplg_av_video_process_vdo_layer(npplg_av_instance_struct *plugin_data);
extern void npplg_av_video_suspend_by_app(npplg_av_instance_struct *plugin_data);
extern void npplg_av_video_resume_by_app(npplg_av_instance_struct *plugin_data);
extern void npplg_av_video_close_by_app(npplg_av_instance_struct *plugin_data);
extern void npplg_av_video_visual_update(npplg_av_instance_struct *plugin_data, kal_bool lcm_update, kal_bool clear_vdo_layer);
extern void npplg_av_video_stop_by_app_for_screen_rotate(npplg_av_instance_struct *plugin_data);
extern void npplg_av_video_redraw_vdo_layer(npplg_av_instance_struct *plugin_data);
extern void npplg_av_video_handle_suspend_background_play_rsp(npplg_av_instance_struct *plugin_data,
                                                              kal_int32 result);
extern void npplg_av_video_mmi_resume_ind_handler(npplg_av_instance_struct *plugin_data);
#ifdef __COSMOS_MMI_PACKAGE__
extern void npplg_av_video_prepare_vdo_layer(npplg_av_instance_struct *plugin_data);
extern void npplg_av_video_unprepare_vdo_layer(npplg_av_instance_struct *plugin_data);
extern void npplg_av_video_create_vdo_layer_rsp_handler(npplg_av_instance_struct *plugin_data,gdi_handle vdo_layer);
extern void npplg_av_video_mmi_update_video_layer(npplg_av_instance_struct *plugin_data, kal_int32 x, kal_int32 y, kal_int32 w, kal_int32 h, gdi_color transparent_color);
#endif /* __COSMOS_MMI_PACKAGE__ */

#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
#endif /* NPPLG_AV_VIDEO_H */
