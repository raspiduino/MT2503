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
 *   npplg_av_audio.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   This file includes the structures and enums used by audio instance.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef NPPLG_AV_AUDIO_H
#define NPPLG_AV_AUDIO_H

#include "med_api.h"
#include "npplg_av_main.h"
#include "kal_general_types.h"


/************************************************************
 * Define
 ************************************************************/

/* Audio build cache size */
#define NPPLG_AV_AUDIO_BUILD_CACHE_SIZE 2048 /* 2K */

/* Audio build cache file buffer size */
#define NPPLG_AV_AUDIO_BUILD_CACHE_FILE_BUF_SIZE 1024 /* 1K */

/* Audio build cache process buffer size */
#define NPPLG_AV_AUDIO_BUILD_CACHE_PROC_BUF_SIZE (32 * 1024)

/* This timer interval is used to check if the cache progress reaches 100 */
#define NPPLG_AV_AUDIO_BUILD_CACHE_CHECK_INTERVAL 300 /* 0.3 second */


/************************************************************
 * Typedef
 ************************************************************/

/* The state of the audio plug-in instance */
typedef enum
{
  NPPLG_AV_AUDIO_OBJ_STATE_IDLE = 0,
  NPPLG_AV_AUDIO_OBJ_STATE_DOWNLOADING,
  NPPLG_AV_AUDIO_OBJ_STATE_BUILDING_CACHE,
  NPPLG_AV_AUDIO_OBJ_STATE_WAITING_PLAY,
  NPPLG_AV_AUDIO_OBJ_STATE_PLAYING,
  NPPLG_AV_AUDIO_OBJ_STATE_PAUSED,
  NPPLG_AV_AUDIO_OBJ_STATE_SEEKING,
  NPPLG_AV_AUDIO_OBJ_STATE_RESET_PLAY_PANEL
} npplg_av_audio_obj_state_enum;

/* Indicate the progress of audio cache */
typedef enum
{
  NPPLG_AV_AUDIO_CACHE_STATUS_IDLE = 0,
  NPPLG_AV_AUDIO_CACHE_STATUS_BUILDING,
  NPPLG_AV_AUDIO_CACHE_STATUS_BUILT_OK,
  NPPLG_AV_AUDIO_CACHE_STATUS_BUILT_FAIL
} npplg_av_audio_cache_status_enum;


/* Additional audio information */
typedef struct
{
  kal_uint32    total_time;                                 /* The duration of the object (video or audio) */
  kal_uint32    play_time;                                  /* The time that the object (video or audio) is playing */
  kal_uint32    build_cache_progress;                       /* The progress of building cache */
  kal_int32     mma_handle;                                 /* MMA handle */
  kal_uint8     *cache_file_buf;                            /* Cache file buffer */
  kal_uint8     *cache_proc_buf;                            /* Cache process buffer */
  kal_uint8     cache[NPPLG_AV_AUDIO_BUILD_CACHE_SIZE];     /* Audio cache */
  kal_uint8     cache_status;                               /* Indicate whether cache is already built */
  mma_player_struct player;
  kal_bool      only_launch_aud_player;
#ifdef __COSMOS_MMI_PACKAGE__
  kal_bool      suspend_bgplay;
#endif
} npplg_av_audio_data_struct;


/************************************************************
 * Global Function
 ************************************************************/
extern void npplg_av_audio_free_data(npplg_av_instance_struct *plugin_data, void *data);
extern void npplg_av_audio_handle_url_rsp(npplg_av_instance_struct *plugin_data, NPReason download_rsp);
extern kal_int16 npplg_av_audio_handle_timer_event(npplg_av_instance_struct *plugin_data, kal_uint8 timer_type);
extern void npplg_av_audio_handle_event(npplg_av_instance_struct *plugin_data, kal_uint8 event);
extern void npplg_av_audio_redraw_window(npplg_av_instance_struct *plugin_data);
extern void npplg_av_audio_play_callback(kal_int32 handle, kal_int32 event);
extern void npplg_av_audio_suspend_by_app(npplg_av_instance_struct *plugin_data);
extern void npplg_av_audio_resume_by_app(npplg_av_instance_struct *plugin_data);
extern void npplg_av_audio_close_by_app(npplg_av_instance_struct *plugin_data);
extern void npplg_av_audio_play_ind_hdlr(kal_uint8 app_id, kal_int32 result);
extern void npplg_av_audio_handle_suspend_background_play_rsp(npplg_av_instance_struct *plugin_data,
                                                              kal_int32 result);
extern void npplg_av_audio_play_result_handler(npplg_av_instance_struct *plugin_data, kal_int32 result);
extern void npplg_av_audio_mmi_resume_ind_handler(npplg_av_instance_struct *plugin_data);

#endif /* NPPLG_AV_AUDIO_H */
