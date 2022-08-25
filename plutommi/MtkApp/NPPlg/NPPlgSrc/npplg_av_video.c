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
 *   npplg_av_video.c
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   Implement video plug-in instance
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(OPERA_V10_BROWSER) || defined(__GADGET_SUPPORT__)

/************************************************************
 * Include
 ************************************************************/
/* MMI header file */
#include "MMI_features.h"

#if defined(__MMI_VIDEO_PLAY_SUPPORT__)

/* MDI header file */
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mdi_video.h"
#include "mdi_include.h"

/* A/V Plug-in header file */
#include "npplg_av_include.h"
#include "npplg_av_main.h"
#include "npplg_av_video.h"
#include "npplg_av_stream.h"
#include "npplg_av_util.h"
#include "npplg_av_custom_config.h"
#include "mmi_rp_app_npplg_def.h"
#include "npplg_struct.h"

#include "fs_func.h"
#include "GlobalResDef.h"
#include "kal_general_types.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "mmi_media_app_trc.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "stack_config.h"
#include "MMIDataType.h"
#include "gdi_include.h"
#include "lcd_if.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "lcd_sw_inc.h"
#include "PixcomFontEngine.h"
#include "FontRes.h"
#include "wgui_categories_util.h"
#include "CustDataRes.h"
#include "kal_active_module.h"
#include "fs_type.h"

#ifdef __COSMOS_MMI_PACKAGE__
#include "vapp_npplg_av_include.h"
#endif


/************************************************************
 * Typedef
 ************************************************************/
#define SMALLER(X, Y)   (((X) < (Y)) ? (X) : (Y) )
#define BIGGER(X, Y)    (((X) > (Y)) ? (X) : (Y) )
#define MINUS_2_ZERO(X) (((X) < 0) ? 0 : (X) )


/************************************************************
 * Static Declaration
 ************************************************************/
static void npplg_av_video_launch_media_player(npplg_av_instance_struct *plugin_data);
static void npplg_av_video_handle_play_event(npplg_av_instance_struct *plugin_data);
static void npplg_av_video_handle_stop_event(npplg_av_instance_struct *plugin_data);
static void npplg_av_video_handle_pause_event(npplg_av_instance_struct *plugin_data);
static void npplg_av_video_handle_seek_event(npplg_av_instance_struct *plugin_data, kal_bool start, kal_bool forward);
static void npplg_av_video_waiting_play(npplg_av_instance_struct *plugin_data);
static kal_bool npplg_av_video_file_open(npplg_av_instance_struct *plugin_data);
static kal_bool npplg_av_video_file_open_in_mmi(npplg_av_instance_struct *plugin_data);
static void npplg_av_video_play(npplg_av_instance_struct *plugin_data);
static void npplg_av_video_play_finish_callback(MDI_RESULT result, void *user_data);
static void npplg_av_video_seek_result_callback(MDI_RESULT result, void *user_data);

static void npplg_av_video_close(npplg_av_instance_struct *plugin_data);
static kal_bool npplg_av_video_create_vdo_layer(npplg_av_instance_struct *plugin_data);
static void npplg_av_video_set_blt_layer(npplg_av_instance_struct *plugin_data);
static void npplg_av_video_find_roi(npplg_av_video_rect_struct *bbox,
                                    npplg_av_video_rect_struct *vdo,
                                    npplg_av_video_rect_struct *roi);
static void npplg_av_video_switch_to_idle_state(npplg_av_instance_struct *plugin_data);
static kal_bool npplg_av_video_update_layer_pause(npplg_av_instance_struct *plugin_data);
static void npplg_av_video_update_layer_resume(npplg_av_instance_struct *plugin_data,
                                               kal_bool seek_play,
                                               kal_bool lcm_update);
static void npplg_av_video_resume_open(npplg_av_instance_struct *plugin_data, kal_uint8 state);
static void npplg_av_video_disable_seek_ctrl(npplg_av_instance_struct *plugin_data);
static kal_bool npplg_av_video_set_vdo_layer_clip(npplg_av_instance_struct *plugin_data, kal_int32 x_offset, kal_int32 y_offset);
static void npplg_av_video_free_vdo_layer(npplg_av_instance_struct *plugin_data);
#ifdef __MMI_VIDEO_PDL__
static void npplg_av_video_pdl_open(npplg_av_instance_struct *plugin_data);
static void npplg_av_video_pdl_open_callback(MDI_RESULT result, mdi_video_info_struct *info, void *user_data);
static void npplg_av_video_start_pdl_buf_check_timer(npplg_av_instance_struct *plugin_data);
#endif /* __MMI_VIDEO_PDL__ */


/************************************************************
 * Local Function
 ************************************************************/

/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_launch_media_player
 * DESCRIPTION
 *  Launch media player to play the video
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_video_launch_media_player(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (plugin_data->state)
    {
        case NPPLG_AV_VIDEO_OBJ_STATE_IDLE:
        {
            if (plugin_data->dl_state == NPPLG_AV_OBJ_DL_STATE_DOWNLOAD_OK)
            {
                /* This video has been downloaded. Check if the file still exists */
                if (FS_GetAttributes(plugin_data->file_path) < 0)
                {
                    plugin_data->dl_state = NPPLG_AV_OBJ_DL_STATE_NULL;
                    NPPLG_AV_MEM_FREE(plugin_data->app_id, plugin_data->file_path);
                    npplg_av_main_display_popup(plugin_data, STR_GLOBAL_FILE_NOT_FOUND);
                    return;
                }

                /* Launch media player -> send primitive to MMI because plug-in may not run in MMI task */
                npplg_av_util_send_launch_media_player_ind(plugin_data,
                                                           kal_get_active_module_id(),
                                                           NPPLG_AV_PLAYER_TYPE_VIDEO,
                                                           KAL_FALSE);
            }
            else
            {
                /*
                 * Video is not downloaded, plug-in should download it first.
                 *
                 * Set this instance as the active instance
                 */
                npplg_av_main_set_active_instance(plugin_data, KAL_FALSE, plugin_data->app_id);
                
                if (plugin_data->control_num == 1)
                {
                    /*
                     * Video size is too small or too large, there is not "Play" control.
                     * The "Launch media player" icon will be replaced with processing image.
                     *
                     * If user clicks the video object when plug-in is downloading the video,
                     * plug-in would stop the downloading because there is not "Stop" control
                     * for this case.
                     */
                    plugin_data->play_panel_state = NPPLG_AV_PLAY_PANEL_STATE_HIDE;
                }
                else
                {
                    /* Disable "Play" control */
                    npplg_av_util_disable_play_control(plugin_data, KAL_FALSE);
                }
                
                /* Show waiting image */
                plugin_data->processing_img_indx = 0;
                npplg_av_util_show_processing_image(plugin_data, KAL_TRUE);

                if (plugin_data->dl_state == NPPLG_AV_OBJ_DL_STATE_NULL)
                {
                    /* Download the video */
                    npplg_av_main_start_download(plugin_data, NPPLG_AV_VIDEO_OBJ_STATE_LAUNCH_MEDIA_PLAYER);
                }
                else if (plugin_data->dl_state == NPPLG_AV_OBJ_DL_STATE_DOWNLOADING)
                {
                    /*
                     * Enter LAUNCH_MEDIA_PLAYER state
                     * When plug-in finishes downloading, it will launch media player
                     */
                    NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_LAUNCH_MEDIA_PLAYER);
                }
                else
                {
                    ASSERT(0);
                }
            }

            return;
        }

        case NPPLG_AV_VIDEO_OBJ_STATE_PRE_BUFFERING:
        case NPPLG_AV_VIDEO_OBJ_STATE_DOWNLOADING:
        {
            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_LAUNCH_MEDIA_PLAYER);
            return;
        }

#ifdef __MMI_VIDEO_PDL__
        case NPPLG_AV_VIDEO_OBJ_STATE_PDL_OPENING:
        case NPPLG_AV_VIDEO_OBJ_STATE_BUFFERING:
        {
            mdi_video_progressive_close_file();
            npplg_av_video_reset_vdo_data(plugin_data);
            
            if (plugin_data->dl_state == NPPLG_AV_OBJ_DL_STATE_DOWNLOADING)
            {
                npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_PDL_BUF_CHECK);
                
                /* Should download the video first */
                NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_LAUNCH_MEDIA_PLAYER);
                return;
            }

            break;
        }
#endif /* __MMI_VIDEO_PDL__ */

        case NPPLG_AV_VIDEO_OBJ_STATE_PLAYING:
        {
            mdi_video_ply_stop();
            npplg_av_video_close(plugin_data);
            npplg_av_video_reset_vdo_data(plugin_data);

            if (plugin_data->dl_state == NPPLG_AV_OBJ_DL_STATE_DOWNLOADING)
            {
                npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_UPDATE_PROGRESS_BAR);
                npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_HIDE_VIDEO_PLAY_PANEL);

                /* Disable "Play" control */
                npplg_av_util_update_play_control(plugin_data, KAL_FALSE, KAL_FALSE);
                npplg_av_util_disable_play_control(plugin_data, KAL_TRUE);
            }

            break;
        }

        case NPPLG_AV_VIDEO_OBJ_STATE_WAITING_SEEK_RSP:
        {
            mdi_video_ply_stop_non_block_seek();
            /* Continue the following action (NPPLG_AV_VIDEO_OBJ_STATE_PAUSED) */
        }

        case NPPLG_AV_VIDEO_OBJ_STATE_PAUSED:
        case NPPLG_AV_VIDEO_OBJ_STATE_PAUSED_PLAY:
        {
            npplg_av_video_close(plugin_data);
            npplg_av_video_reset_vdo_data(plugin_data);

            if (plugin_data->dl_state == NPPLG_AV_OBJ_DL_STATE_DOWNLOADING)
            {
                /* Disable "Play" control */
                npplg_av_util_disable_play_control(plugin_data, KAL_TRUE);
            }

            break;
        }

        case NPPLG_AV_VIDEO_OBJ_STATE_RESET_PLAY_PANEL:
        {
            npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_RESET_PLAY_PANEL);
            npplg_av_video_reset_vdo_data(plugin_data);
            break;
        }

#ifdef __COSMOS_MMI_PACKAGE__
        case NPPLG_AV_VIDEO_OBJ_STATE_CREATE_VDO_LAYER:
        {            
            npplg_av_video_close(plugin_data);
            npplg_av_video_reset_vdo_data(plugin_data);
            break;
        }
#endif /* __COSMOS_MMI_PACKAGE__ */

        default:
            return;
    }

    if (plugin_data->dl_state == NPPLG_AV_OBJ_DL_STATE_DOWNLOADING)
    {
        /* Disable seek control */
        npplg_av_video_disable_seek_ctrl(plugin_data);

        /* Show waiting image */
        plugin_data->processing_img_indx = 0;
        npplg_av_util_show_processing_image(plugin_data, KAL_TRUE);

        NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_LAUNCH_MEDIA_PLAYER);
    }
    else if (plugin_data->dl_state == NPPLG_AV_OBJ_DL_STATE_DOWNLOAD_OK)
    {
        /* Video is downloaded -> switch to idle state */
        npplg_av_video_set_state_to_idle(plugin_data);
        
        /* Launch media player -> send primitive to MMI because plug-in may not run in MMI task */
        npplg_av_util_send_launch_media_player_ind(plugin_data,
                                                   kal_get_active_module_id(),
                                                   NPPLG_AV_PLAYER_TYPE_VIDEO,
                                                   KAL_FALSE);
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_handle_play_event
 * DESCRIPTION
 *  This function is used to handle play event.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_video_handle_play_event(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (plugin_data->state)
    {
        case NPPLG_AV_VIDEO_OBJ_STATE_IDLE:
        {
            if (plugin_data->dl_state == NPPLG_AV_OBJ_DL_STATE_DOWNLOAD_OK)
            {
                /* This video has been downloaded. Check if the file still exists */
                if (FS_GetAttributes(plugin_data->file_path) < 0)
                {
                    plugin_data->dl_state = NPPLG_AV_OBJ_DL_STATE_NULL;
                    NPPLG_AV_MEM_FREE(plugin_data->app_id, plugin_data->file_path);
                    npplg_av_main_display_popup(plugin_data, STR_GLOBAL_FILE_NOT_FOUND);
                    return;
                }

                /* Set this instance as the active instance */
                npplg_av_main_set_active_instance(plugin_data, KAL_FALSE, plugin_data->app_id);

                npplg_av_video_waiting_play(plugin_data);
            }
            else
            {
                /* Set this instance as the active instance */
                npplg_av_main_set_active_instance(plugin_data, KAL_FALSE, plugin_data->app_id);
                
                /* Disable "Play" control */
                npplg_av_util_disable_play_control(plugin_data, KAL_FALSE);
                
                /* Show waiting image */
                plugin_data->processing_img_indx = 0;
                npplg_av_util_show_processing_image(plugin_data, KAL_TRUE);

                if (plugin_data->dl_state == NPPLG_AV_OBJ_DL_STATE_NULL)
                {
                    /* Download the video */
                    npplg_av_main_start_download(plugin_data, NPPLG_AV_VIDEO_OBJ_STATE_PRE_BUFFERING);
                }
                else if (plugin_data->dl_state == NPPLG_AV_OBJ_DL_STATE_DOWNLOADING)
                {
                    /* Enter next state */
                    NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_PRE_BUFFERING);
                }
                else
                {
                    ASSERT(0);
                }
            }
            break;
        }

        case NPPLG_AV_VIDEO_OBJ_STATE_PAUSED:
        case NPPLG_AV_VIDEO_OBJ_STATE_PAUSED_PLAY:
        {
            if (vdo_data->is_pdl_or_rtsp)
            {
#ifdef __MMI_VIDEO_PDL__
                /* PDL video -> go to buffering state */
                NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_BUFFERING);
                mdi_video_progressive_get_buf_percentage(&vdo_data->pdl_buf_percentage);
                if (vdo_data->pdl_buf_percentage < 100)
                {
                    /* Disable "Play" control */
                    npplg_av_util_disable_play_control(plugin_data, KAL_FALSE);
                    
                    /* Show waiting image */
                    plugin_data->processing_img_indx = 0;
                    npplg_av_util_show_processing_image(plugin_data, KAL_TRUE);

                    /* Start timer to check buffer percentage reaches 100 */
                    npplg_av_video_start_pdl_buf_check_timer(plugin_data);
                }
                else
                {
                    npplg_av_video_play(plugin_data);
                }
#endif /* __MMI_VIDEO_PDL__ */
            }
            else
            {
                /* Video file */
                npplg_av_video_play(plugin_data);
            }
            
            break;
        }

        case NPPLG_AV_VIDEO_OBJ_STATE_LAUNCH_MEDIA_PLAYER:
        {
            /* Switch state to pre-buffering */
            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_PRE_BUFFERING);
            break;
        }

        case NPPLG_AV_VIDEO_OBJ_STATE_DOWNLOADING:
        {
            /*
             * User only can press "Play" control in downloading state if previous
             * state is paused and can not open pdl successfully when interrupt goes.
             *
             * 1. Disable "Play" control
             * 2. Show processing image
             *
             */
            npplg_av_util_disable_play_control(plugin_data, KAL_FALSE);

            plugin_data->processing_img_indx = 0;
            npplg_av_util_show_processing_image(plugin_data, KAL_TRUE);
            break;
        }

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_handle_stop_event
 * DESCRIPTION
 *  This function is used to handle stop event.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_video_handle_stop_event(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (plugin_data->state)
    {
        case NPPLG_AV_VIDEO_OBJ_STATE_IDLE:
            return;

        case NPPLG_AV_VIDEO_OBJ_STATE_PRE_BUFFERING:
        case NPPLG_AV_VIDEO_OBJ_STATE_DOWNLOADING:
        case NPPLG_AV_VIDEO_OBJ_STATE_LAUNCH_MEDIA_PLAYER:
        {
            break;
        }

#ifdef __MMI_VIDEO_PDL__
        case NPPLG_AV_VIDEO_OBJ_STATE_PDL_OPENING:
        case NPPLG_AV_VIDEO_OBJ_STATE_BUFFERING:
        {
            mdi_video_progressive_close_file();
            break;
        }
#endif /* __MMI_VIDEO_PDL__ */

        case NPPLG_AV_VIDEO_OBJ_STATE_PLAYING:
        {
            mdi_video_ply_stop();
            npplg_av_video_close(plugin_data);
            break;
        }

        case NPPLG_AV_VIDEO_OBJ_STATE_PAUSED:
        case NPPLG_AV_VIDEO_OBJ_STATE_PAUSED_PLAY:
        {
            npplg_av_video_close(plugin_data);
            break;
        }

        case NPPLG_AV_VIDEO_OBJ_STATE_SEEKING:
        {
            npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_SEEK_REPEAT);
            plugin_data->seek_repeat_num = 0;
            if (plugin_data->prev_state == NPPLG_AV_VIDEO_OBJ_STATE_PLAYING ||
                plugin_data->prev_state == NPPLG_AV_VIDEO_OBJ_STATE_PAUSED)
            {
                npplg_av_video_close(plugin_data);
            }
            plugin_data->prev_state = NPPLG_AV_VIDEO_OBJ_STATE_IDLE;
            break;
        }

        case NPPLG_AV_VIDEO_OBJ_STATE_WAITING_SEEK_RSP:
        {
            mdi_video_ply_stop_non_block_seek();
            npplg_av_video_close(plugin_data);
            break;
        }

        case NPPLG_AV_VIDEO_OBJ_STATE_RESET_PLAY_PANEL:
        {
            npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_RESET_PLAY_PANEL);
            break;
        }

#ifdef __COSMOS_MMI_PACKAGE__
        case NPPLG_AV_VIDEO_OBJ_STATE_CREATE_VDO_LAYER:
        {
            npplg_av_video_close(plugin_data);
            npplg_av_video_switch_to_idle_state(plugin_data);
            npplg_av_util_send_free_vdo_layer_ind(kal_get_active_module_id(),
                                                  plugin_data->app_id,
                                                  plugin_data->instance_id);
            return;
        }
#endif /* __COSMOS_MMI_PACKAGE__ */

        default:
            break;
    }

    npplg_av_video_switch_to_idle_state(plugin_data);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_handle_pause_event
 * DESCRIPTION
 *  This function is used to handle pause event.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_video_handle_pause_event(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (plugin_data->state)
    {
        case NPPLG_AV_VIDEO_OBJ_STATE_PLAYING:
        {
            npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_UPDATE_PROGRESS_BAR);
            npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_HIDE_VIDEO_PLAY_PANEL);
            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_PAUSED);
            mdi_video_ply_stop();
            mdi_video_ply_get_cur_play_time(&vdo_data->play_time);

            /* Change "Pause" control to "Play" control */
            npplg_av_util_update_play_control(plugin_data, KAL_FALSE, KAL_TRUE);
            break;
        }

        case NPPLG_AV_VIDEO_OBJ_STATE_PAUSED_PLAY:
        {
            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_PAUSED);

            /* Change "Pause" control to "Play" control */
            npplg_av_util_update_play_control(plugin_data, KAL_FALSE, KAL_TRUE);
            break;
        }

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_handle_seek_event
 * DESCRIPTION
 *  This function is used to handle seek event (fast forward or rewind).
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  forward         [IN]        TRUE: fast forward, FALSE: rewind
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_video_handle_seek_event(npplg_av_instance_struct *plugin_data, kal_bool start, kal_bool forward)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
    MDI_RESULT ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (start && plugin_data->seekable)
    {
        switch (plugin_data->state)
        {
            case NPPLG_AV_VIDEO_OBJ_STATE_PLAYING:
            {
                npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_UPDATE_PROGRESS_BAR);
                npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_HIDE_VIDEO_PLAY_PANEL);
                mdi_video_ply_stop();
                mdi_video_ply_get_cur_play_time(&vdo_data->play_time);
                /* Continue the following action */
            }

            case NPPLG_AV_VIDEO_OBJ_STATE_PAUSED:
            case NPPLG_AV_VIDEO_OBJ_STATE_IDLE:
            {
                plugin_data->seek_repeat_num = 0;
                
                /* Only update progress bar */
                npplg_av_util_seek(plugin_data, forward);
                break;
            }

            default:
            {
                /* Not support seeking in other states */
                return;
            }
        }

        plugin_data->prev_state = plugin_data->state;
        NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_SEEKING);
    }
    else if (!start && plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_SEEKING)
    {
        /* Receive mouse up event -> stop seeking */
        npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_SEEK_REPEAT);
        plugin_data->seek_repeat_num = 0;

        if (plugin_data->prev_state == NPPLG_AV_VIDEO_OBJ_STATE_PLAYING)
        {
            /* Change "Pause" control or "Stop" control to "Play" control */
            npplg_av_util_update_play_control(plugin_data, KAL_FALSE, KAL_TRUE);            
            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_WAITING_SEEK_RSP);
            mdi_video_ply_non_block_seek(vdo_data->play_time, npplg_av_video_seek_result_callback, 0);
            npplg_av_main_set_callback_app_id(NPPLG_AV_OBJ_TYPE_VIDEO, plugin_data->app_id);
        }
        else if (plugin_data->prev_state == NPPLG_AV_VIDEO_OBJ_STATE_PAUSED)
        {
            /* Seek video and get video frame */
            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_WAITING_SEEK_RSP);
            if (vdo_data->vdo_layer_handle != GDI_NULL_HANDLE)
            {
                ret = mdi_video_ply_non_block_seek_and_get_frame(vdo_data->play_time, vdo_data->vdo_layer_handle, npplg_av_video_seek_result_callback, 0);
            }
            else
            {
                ret = mdi_video_ply_non_block_seek(vdo_data->play_time, npplg_av_video_seek_result_callback, 0);
            }
            npplg_av_main_set_callback_app_id(NPPLG_AV_OBJ_TYPE_VIDEO, plugin_data->app_id);

            /* Show waiting image */
            if (ret == MDI_RES_VDOPLY_SUCCEED)
            {
                plugin_data->processing_img_indx = 0;
                npplg_av_util_show_processing_image(plugin_data, KAL_TRUE);
            }
        }
        else
        {
            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, plugin_data->prev_state);
            plugin_data->prev_state = NPPLG_AV_VIDEO_OBJ_STATE_IDLE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_waiting_play
 * DESCRIPTION
 *  Waiting for audio resource
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_video_waiting_play(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 action;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Change state */
    NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_WAITING_PLAY);

    switch (g_npplg_av_context.res_status)
    {
        case NPPLG_AV_RES_STATUS_NULL:
        {
            ASSERT(kal_get_active_module_id() != MOD_MMI);

#ifdef __COSMOS_MMI_PACKAGE__
            npplg_av_main_suspend_background_play(plugin_data->app_id, KAL_FALSE);
#else
            npplg_av_main_suspend_background_play(plugin_data->app_id, KAL_TRUE);
#endif
            break;
        }

        case NPPLG_AV_RES_STATUS_RELEASING:
        {
            g_npplg_av_context.res_status = NPPLG_AV_RES_STATUS_OCCUPIED;

            /* Continue following action */
        }

        case NPPLG_AV_RES_STATUS_OCCUPIED:
        {
            /* Apply the mute setting of active plug-in instance */
            npplg_av_main_set_mute(plugin_data->mute, plugin_data->app_id);
            
            /* Need to send primitive to MMI task to turn on backlight and set volume */
#ifdef __COSMOS_MMI_PACKAGE__
            action = NPPLG_AV_ACTION_SET_VOLUME | NPPLG_AV_ACTION_TURN_ON_BACKLIGHT | NPPLG_AV_ACTION_SEND_PLAY_IND | NPPLG_AV_ACTION_TERMINATE_BGPLAY;
#else
            action = NPPLG_AV_ACTION_SET_VOLUME | NPPLG_AV_ACTION_TURN_ON_BACKLIGHT | NPPLG_AV_ACTION_SEND_PLAY_IND;
#endif

            npplg_av_util_send_notify_mmi_ind(kal_get_active_module_id(),
                                              plugin_data->instance_id,
                                              plugin_data->app_id,
                                              action);
            break;
        }

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_file_open
 * DESCRIPTION
 *  Open video file and gather video information
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  Video file open succeed or fail
 *****************************************************************************/
static kal_bool npplg_av_video_file_open(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
    mdi_video_info_struct info;
    MDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    mdi_video_ply_enable_aud_only_video_clip();
#ifdef __COSMOS_MMI_PACKAGE__
    mdi_video_ply_set_scenario_type(MDI_VIDEO_SCENARIO_QVGA);
#endif
    result = mdi_video_ply_open_clip_file(g_npplg_av_context.app_cnxt[plugin_data->app_id].mem_app_id,
                                          (const S8*)plugin_data->file_path,
                                          &info);
    if (result != MDI_RES_VDOPLY_SUCCEED)
    {
        npplg_av_video_reset_vdo_data(plugin_data);
        npplg_av_video_set_state_to_idle(plugin_data);
        
        /* Get the error string id from MDI and display error popup */
        npplg_av_util_display_mdi_error_popup(result, plugin_data);
        return KAL_FALSE;
    }

    vdo_data->vdo_height = info.height;
    vdo_data->vdo_width = info.width;
    if (info.track == MDI_VIDEO_TRACK_A_ONLY)
    {
        vdo_data->audio_only = KAL_TRUE;
    }
    else
    {
        vdo_data->audio_only = KAL_FALSE;
    }

    /* Video file is seekable. info.is_seekable is only for streaming. */
    plugin_data->seekable = KAL_TRUE;
    vdo_data->total_time = info.total_time_duration;
    
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_file_open_in_mmi
 * DESCRIPTION
 *  Open video file and gather video information in MMI task
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  Video file open succeed or fail
 *****************************************************************************/
static kal_bool npplg_av_video_file_open_in_mmi(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
    mdi_video_info_struct info;
    MDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    mdi_video_ply_enable_aud_only_video_clip();
#ifdef __COSMOS_MMI_PACKAGE__
    mdi_video_ply_set_scenario_type(MDI_VIDEO_SCENARIO_QVGA);
#endif
    result = mdi_video_ply_open_clip_file(g_npplg_av_context.app_cnxt[plugin_data->app_id].mem_app_id,
                                          (const S8*)plugin_data->file_path,
                                          &info);
    if (result != MDI_RES_VDOPLY_SUCCEED)
    {
        return KAL_FALSE;
    }

    vdo_data->vdo_height = info.height;
    vdo_data->vdo_width = info.width;
    if (info.track == MDI_VIDEO_TRACK_A_ONLY)
    {
        vdo_data->audio_only = KAL_TRUE;
    }
    else
    {
        vdo_data->audio_only = KAL_FALSE;
    }

    /* Video file is seekable. info.is_seekable is only for streaming. */
    plugin_data->seekable = KAL_TRUE;
    vdo_data->total_time = info.total_time_duration;
    
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_play
 * DESCRIPTION
 *  Play the video
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_video_play(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
    MDI_RESULT result;
    kal_bool lcm_update;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_PLAY_VIDEO, plugin_data->instance_id, plugin_data->state);

    mdi_video_ply_enable_partial_display();

    /* Process video layer */
    lcm_update = npplg_av_video_process_vdo_layer(plugin_data);
    if (vdo_data->lcm_update == KAL_FALSE)
    {
        lcm_update = KAL_FALSE;
    }

    lcm_update = npplg_av_main_decide_video_visual_update(plugin_data->app_id, lcm_update);

    mdi_video_ply_seek(vdo_data->play_time);

    /* Play the video */
#if defined(__GADGET_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)
    if (plugin_data->app_id == NPPLG_AV_APP_ID_GOOGLE_GADGET)
    {
        result = mdi_video_ply_play(vdo_data->vdo_layer_handle,
                                    g_npplg_av_context.blt_layer_flag,
                                    g_npplg_av_context.hw_layer_flag,
                                    1,
                                    lcm_update,
                                    KAL_TRUE,
                                    MDI_DEVICE_SPEAKER2,
                                    g_npplg_av_context.app_cnxt[plugin_data->app_id].rotate,
                                    100,
                                    npplg_av_video_play_finish_callback,
                                    0);
    }
    else
#endif /* defined(__GADGET_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__) */
    result = mdi_video_ply_play(vdo_data->vdo_layer_handle,
                                NPPLG_AV_BLT_LAYER_FLAG,
                                NPPLG_AV_VDO_PLAY_LAYER_FLAG,
                                1,
                                lcm_update,
                                KAL_TRUE,
                                MDI_DEVICE_SPEAKER2,
                                g_npplg_av_context.app_cnxt[plugin_data->app_id].rotate,
                                100,
                                npplg_av_video_play_finish_callback,
                                0);

    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_VIDEO_PLAY_RESULT, result);

    if (result == MDI_RES_VDOPLY_SUCCEED)
    {
        npplg_av_main_set_callback_app_id(NPPLG_AV_OBJ_TYPE_VIDEO, plugin_data->app_id);
        NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_PLAYING);

        /* Update seek control */
        npplg_av_util_update_seek_control(plugin_data);
        plugin_data->reset_seek_ctrl = KAL_TRUE;

        /* Update UI - Change "Play" control to "Pause" control or "Stop" control */
        npplg_av_util_update_play_control(plugin_data, KAL_TRUE, KAL_TRUE);

        /* Start a timer to update progress bar */
        npplg_av_main_start_timer(plugin_data,
                                  NPPLG_AV_TIMER_UPDATE_PROGRESS_BAR,
                                  NPPLG_AV_UPDATE_PROGRESS_BAR_INTERVAL);

        if (vdo_data->audio_only == KAL_FALSE)
        {
            /* After a short period, plug-in will hide the play panel to let user see the video as large as possible */
            npplg_av_main_start_timer(plugin_data,
                                      NPPLG_AV_TIMER_HIDE_VIDEO_PLAY_PANEL,
                                      NPPLG_AV_CFG_VDO_HIDE_PLAY_PANEL_AFTER_PLAY_TIME);
        }
        return;
    }
    else
    {
        /* Encounter error -> set state to IDLE */    
        npplg_av_video_close(plugin_data);
        npplg_av_video_switch_to_idle_state(plugin_data);

        /* Get the error string id from MDI and display error popup */
        npplg_av_util_display_mdi_error_popup(result, plugin_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_play_finish_callback
 * DESCRIPTION
 *  This function is the callback function for video play.
 * PARAMETERS
 *  result          [IN]        Video play result
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_video_play_finish_callback(MDI_RESULT result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_struct *plugin_data;
    npplg_av_video_data_struct *vdo_data;
    npplg_av_obj_control_struct *progress_bar, *time_ctrl;
    kal_bool display_error = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_VIDEO_PLAY_RESULT, result);

    NPPLG_AV_LOCK;

    plugin_data = npplg_av_main_get_active_instance(npplg_av_main_get_callback_app_id(NPPLG_AV_OBJ_TYPE_VIDEO));
    
    if (plugin_data != NULL && plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
    {
        vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
        
        switch (result)
        {
            case MDI_RES_VDOPLY_SUCCEED:
            {
                progress_bar = npplg_av_util_get_control(plugin_data, NPPLG_AV_CTRL_TYPE_PROGRESS_BAR);
                time_ctrl = npplg_av_util_get_control(plugin_data, NPPLG_AV_CTRL_TYPE_TIME);

                if ((progress_bar != NULL || time_ctrl != NULL) &&
                    plugin_data->play_panel_state == NPPLG_AV_PLAY_PANEL_STATE_DISPLAY)
                {
                    plugin_data->processing = KAL_FALSE;
                    npplg_av_main_stop_all_timer(plugin_data);
                    
                    /* Fill the progress bar completely */
                    if (progress_bar != NULL)
                    {
                        npplg_av_util_invalidate_rect(plugin_data, progress_bar);
                    }

                    if (time_ctrl != NULL)
                    {
                        npplg_av_util_invalidate_rect(plugin_data, time_ctrl);
                    }
                    
                    npplg_av_video_close(plugin_data);
                    npplg_av_main_abort_download_req(plugin_data);
                    npplg_av_video_reset_vdo_data(plugin_data);

                    vdo_data->play_time = vdo_data->total_time;
    
                    /* Start a timer to redraw the play panel */
                    npplg_av_main_start_timer(plugin_data,
                                              NPPLG_AV_TIMER_RESET_PLAY_PANEL,
                                              NPPLG_AV_RESET_PLAY_PANEL_INTERVAL);

                    NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_RESET_PLAY_PANEL);

                    NPPLG_AV_UNLOCK;
                    return;
                }
                break;
            }

#ifdef __MMI_VIDEO_PDL__
            case MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH:
            {
                NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_BUFFERING);
                
                mdi_video_ply_get_cur_play_time(&vdo_data->play_time);
                npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_HIDE_VIDEO_PLAY_PANEL);
                npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_UPDATE_PROGRESS_BAR);

                /* Disable "Play" control */
                npplg_av_util_disable_play_control(plugin_data, KAL_FALSE);

                /* Show waiting image */
                plugin_data->processing_img_indx = 0;
                npplg_av_util_show_processing_image(plugin_data, KAL_TRUE);
                
                npplg_av_video_start_pdl_buf_check_timer(plugin_data);

                NPPLG_AV_UNLOCK;
                return;
            }
#endif /* __MMI_VIDEO_PDL__ */

            case MDI_RES_VDOPLY_ONLY_VIDEO_TRACK_ERROR:
            case MDI_RES_VDOPLY_ONLY_AUDIO_TRACK_ERROR:
            {
                NPPLG_AV_UNLOCK;
                return;
            }

            default:
            {
                display_error = KAL_TRUE;
                break;
            }
        }

        npplg_av_video_close(plugin_data);
        npplg_av_video_switch_to_idle_state(plugin_data);

        if (display_error == KAL_TRUE)
        {
            /* Get the error string id from MDI and display error popup */
            npplg_av_util_display_mdi_error_popup(result, plugin_data);
        }
    }

    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_seek_result_callback
 * DESCRIPTION
 *  This function is the callback function for video seek.
 * PARAMETERS
 *  result          [IN]        Video seek result
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_video_seek_result_callback(MDI_RESULT result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_struct *plugin_data;
    npplg_av_video_data_struct *vdo_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_VIDEO_SEEK_RESULT, result);

    NPPLG_AV_LOCK;

    plugin_data = npplg_av_main_get_active_instance(npplg_av_main_get_callback_app_id(NPPLG_AV_OBJ_TYPE_VIDEO));

    if (plugin_data != NULL && plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
    {
        if (plugin_data->processing)
        {
            plugin_data->processing = KAL_FALSE;
            npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_UPDATE_PROCESSNG_IMG);
        }
    
        if (plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_WAITING_SEEK_RSP)
        {
            vdo_data = (npplg_av_video_data_struct *)plugin_data->obj_data;
            
            if (result >= MDI_RES_VDOPLY_SUCCEED ||
                result == MDI_RES_VDOPLY_ERR_GET_FRAME_FAILED)
            {
                if (result == MDI_RES_VDOPLY_SEEK_PARTIAL_DONE)
                {
                    mdi_video_ply_get_cur_play_time(&vdo_data->play_time);
                }

                if (plugin_data->prev_state == NPPLG_AV_VIDEO_OBJ_STATE_PLAYING)
                {
                    if (vdo_data->is_pdl_or_rtsp)
                    {
#ifdef __MMI_VIDEO_PDL__
                        /* PDL video -> go to buffering state */
                        NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_BUFFERING);
                        mdi_video_progressive_get_buf_percentage(&vdo_data->pdl_buf_percentage);
                        if (vdo_data->pdl_buf_percentage < 100)
                        {
                            /* Disable "Play" control */
                            npplg_av_util_disable_play_control(plugin_data, KAL_FALSE);

                            /* Show waiting image */
                            plugin_data->processing_img_indx = 0;
                            npplg_av_util_show_processing_image(plugin_data, KAL_TRUE);
                            
                            npplg_av_video_start_pdl_buf_check_timer(plugin_data);
                        }
                        else
                        {
                            npplg_av_video_start_to_play(plugin_data);
                        }
#endif /* __MMI_VIDEO_PDL__ */
                    }
                    else
                    {
                        /* Video file */
                        npplg_av_video_start_to_play(plugin_data);
                    }
                }
                else
                {
                    npplg_av_util_invalidate_rect(plugin_data, NULL);
                    NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, plugin_data->prev_state);
                }

                plugin_data->prev_state = NPPLG_AV_VIDEO_OBJ_STATE_IDLE;
            }
            else
            {
                /* Seek error */
                npplg_av_video_close(plugin_data);
                npplg_av_video_switch_to_idle_state(plugin_data);

                /* Get the error string id from MDI and display error popup */
                npplg_av_util_display_mdi_error_popup(result, plugin_data);
            }
        }
    }

    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_close
 * DESCRIPTION
 *  Close video
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_video_close(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!vdo_data->is_pdl_or_rtsp)
    {
        mdi_video_ply_close_clip_file();
    }
#ifdef __MMI_VIDEO_PDL__
    else
    {
        mdi_video_progressive_close_file();
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_create_vdo_layer
 * DESCRIPTION
 *  This function is used to create video layer.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  Indicate success or failure
 *****************************************************************************/
static kal_bool npplg_av_video_create_vdo_layer(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
    npplg_av_rect_struct rect_in, rect_out;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_CREATE_VDO_LAYER, plugin_data->instance_id, plugin_data->obj_type, plugin_data->state);

    npplg_av_video_get_best_fit_size(plugin_data);

    rect_in.x = vdo_data->layer_x;
    rect_in.y = vdo_data->layer_y;
    rect_in.w = vdo_data->layer_w;
    rect_in.h = vdo_data->layer_h;

    vdo_data->vdo_layer_handle = npplg_av_main_create_video_layer(plugin_data->app_id, &rect_in, &rect_out);

    if (vdo_data->vdo_layer_handle == GDI_NULL_HANDLE)
    {
        if (g_npplg_av_context.app_cnxt[plugin_data->app_id].is_suspend_by_mmi == KAL_FALSE)
        {
            if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
            {
                if (plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_WAITING_SEEK_RSP)
                {
                    mdi_video_ply_stop_non_block_seek();
                }
                else if (plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_PLAYING)
                {
                    mdi_video_ply_stop();
                }

                npplg_av_video_close(plugin_data);
            }
#ifdef __MMI_VIDEO_STREAM__
            else if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
            {
                if (plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_PLAYING)
                {
                    mdi_video_stream_stop();
                }
                else if (plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_BUFFERING)
                {
                    mdi_video_stream_stop_buffering();
                }
                mdi_video_stream_disconnect();
                mdi_video_stream_deinit();
            }
#endif /* __MMI_VIDEO_STREAM__ */

            npplg_av_video_switch_to_idle_state(plugin_data);

            npplg_av_main_display_popup(plugin_data, STR_ID_NPPLG_FAIL_TO_PLAY);
        }
        else if (plugin_data == npplg_av_main_get_active_instance(plugin_data->app_id))
        {
            plugin_data->suspend = KAL_FALSE;

            if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
            {
                npplg_av_video_close_by_app(plugin_data);
                npplg_av_video_handle_event(plugin_data, NPPLG_AV_INT_EVT_STOP);
            }
#ifdef __MMI_VIDEO_STREAM__
            else if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
            {
                npplg_av_stream_close_by_app(plugin_data);
                npplg_av_stream_handle_event(plugin_data, NPPLG_AV_INT_EVT_STOP);
            }
#endif /* __MMI_VIDEO_STREAM__ */
        }

        return KAL_FALSE;
    }
    else
    {
        /* Update video layer size and position */
        vdo_data->layer_x = rect_out.x;
        vdo_data->layer_y = rect_out.y;
        vdo_data->layer_w = rect_out.w;
        vdo_data->layer_h = rect_out.h;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_set_blt_layer
 * DESCRIPTION
 *  Get the layer created by Opera and set blt layer before playing video
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_video_set_blt_layer(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
    gdi_handle layer_1, layer_2, layer_3;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    npplg_av_main_get_gdi_layer(plugin_data->app_id, &layer_1, &layer_2, &layer_3);

    gdi_layer_set_blt_layer(vdo_data->vdo_layer_handle,
                            layer_1,
                            layer_2,
                            layer_3);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_find_roi
 * DESCRIPTION
 *  Get the ROI of video
 * PARAMETERS
 *  bbox        [IN]        Bounding box
 *  vdo         [IN]        Layer to calculate ROI
 *  roi         [OUT]       The roi to set  (x, y are releated to (0,0) of video)
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_video_find_roi(npplg_av_video_rect_struct *bbox,
                                    npplg_av_video_rect_struct *vdo,
                                    npplg_av_video_rect_struct *roi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((vdo->x1 >= bbox->x1) && (vdo->y1 >= bbox->y1) &&
        (vdo->x2 <= bbox->x2) && (vdo->y2 <= bbox->y2))
    {
        /* Video is falling inside rendering area */
        roi->x1 = 0;
        roi->y1 = 0;
        roi->x2 = vdo->x2 - vdo->x1;
        roi->y2 = vdo->y2 - vdo->y1;
    }
    else if ((vdo->x1 >= bbox->x2) ||
             (vdo->x2 <= bbox->x1) ||
             (vdo->y2 <= bbox->y1) ||
             (vdo->y1 >= bbox->y2))
    {
        /* Video is outside rendering area */
        roi->x1 = 0;
        roi->y1 = 0;
        roi->x2 = 0;
        roi->y2 = 0;
    }
    else
    {
        /*
         * Video is partially inside the rendering area
         * Need calculate one by one
         */
        roi->x1 = BIGGER(bbox->x1, vdo->x1)  - vdo->x1;
        roi->y1 = BIGGER(bbox->y1, vdo->y1)  - vdo->y1;
        roi->x2 = SMALLER(bbox->x2, vdo->x2) - vdo->x1;
        roi->y2 = SMALLER(bbox->y2, vdo->y2) - vdo->y1;

        /* Don't allow x1 y1 x2 y2 < 0 */
        roi->x1 = MINUS_2_ZERO(roi->x1);
        roi->y1 = MINUS_2_ZERO(roi->y1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_switch_to_idle_state
 * DESCRIPTION
 *  This function is used to switch to idle state.
 *  1. Stop data retrieval
 *  2. Free video data
 *  3. Set state to idle state
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_video_switch_to_idle_state(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    npplg_av_video_reset_vdo_data(plugin_data);
    npplg_av_video_set_state_to_idle(plugin_data);

#ifdef OPERA_V10_BROWSER
    if (plugin_data->app_id != NPPLG_AV_APP_ID_OPERA_BROWSER)
#endif
    npplg_av_main_abort_download_req(plugin_data);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_update_layer_pause
 * DESCRIPTION
 *  This function is used to pause video before plug-in update video layer.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  Indicate whether plug-in should resume playing later
 *****************************************************************************/
static kal_bool npplg_av_video_update_layer_pause(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool seek_play = KAL_FALSE;
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_PLAYING)
    {
        if (vdo_data->audio_only == KAL_FALSE)
        {
            /*
             * MDI Video pause / resume interfaces can not support change layer rotate parameter
             *
             * Should stop video playing before update video layer because plug-in will create a new video layer
             * and may update layer rotate parameter
             */
#if defined(__GADGET_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)
            if (plugin_data->app_id != NPPLG_AV_APP_ID_GOOGLE_GADGET)
#endif
            {
                npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;

                mdi_video_ply_stop();
                mdi_video_ply_get_cur_play_time(&vdo_data->play_time);
            }
        }

        /* Change "Play" control to "Pause" control or "Stop" control */
        npplg_av_util_update_play_control(plugin_data, KAL_TRUE, KAL_FALSE);
    }
    else if (plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_PRE_BUFFERING ||
             plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_PDL_OPENING ||
             plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_BUFFERING ||
             plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_DOWNLOADING ||
             plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_LAUNCH_MEDIA_PLAYER)
    {
        /* Disable "Play" control */
        npplg_av_util_disable_play_control(plugin_data, KAL_FALSE);
    }
    else if (plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_PAUSED_PLAY)
    {
        /* Change "Play" control to "Pause" control or "Stop" control */
        npplg_av_util_update_play_control(plugin_data, KAL_TRUE, KAL_FALSE);
    }

    /* If window is resized in seeking state, stop seeking */
    if (plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_SEEKING)
    {
        if (plugin_data->prev_state == NPPLG_AV_VIDEO_OBJ_STATE_PLAYING)
        {
            /* Should resume video playing by non-blocking function */
            seek_play = KAL_TRUE;
        }
        npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_SEEK_REPEAT);
        plugin_data->seek_repeat_num = 0;
        NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, plugin_data->prev_state);
        plugin_data->prev_state = NPPLG_AV_VIDEO_OBJ_STATE_IDLE;
    }

    return seek_play;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_update_layer_resume
 * DESCRIPTION
 *  This function is used to resume video after plug-in update video layer.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_video_update_layer_resume(npplg_av_instance_struct *plugin_data,
                                               kal_bool seek_play,
                                               kal_bool lcm_update)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_PLAYING)
    {
#if defined(__GADGET_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)
        if (seek_play ||
            (vdo_data->audio_only == KAL_FALSE && plugin_data->app_id != NPPLG_AV_APP_ID_GOOGLE_GADGET))
#else
        if (seek_play || vdo_data->audio_only == KAL_FALSE)
#endif
        {
            plugin_data->prev_state = NPPLG_AV_VIDEO_OBJ_STATE_PLAYING;
            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_WAITING_SEEK_RSP);
            mdi_video_ply_non_block_seek(vdo_data->play_time, npplg_av_video_seek_result_callback, 0);
            npplg_av_main_set_callback_app_id(NPPLG_AV_OBJ_TYPE_VIDEO, plugin_data->app_id);
        }
    }
    else if (plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_PRE_BUFFERING ||
             plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_PDL_OPENING ||
             plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_BUFFERING ||
             plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_DOWNLOADING ||
             plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_LAUNCH_MEDIA_PLAYER)
    {
        /* Redraw processing image */
        npplg_av_util_show_processing_image(plugin_data, KAL_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_resume_open
 * DESCRIPTION
 *  This function is used to open video when interrupt goes.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  state           [IN]        State if video is opened
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_video_resume_open(npplg_av_instance_struct *plugin_data, kal_uint8 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
#ifdef __MMI_VIDEO_PDL__
    MDI_RESULT result;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plugin_data->dl_state == NPPLG_AV_OBJ_DL_STATE_DOWNLOAD_OK)
    {
        /* If video is downloaded, play the video */
        if (npplg_av_video_file_open_in_mmi(plugin_data) == KAL_TRUE)
        {
            /* Seek first because play_time may be large */
            plugin_data->prev_state = state;
            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_WAITING_SEEK_RSP);
            mdi_video_ply_non_block_seek(vdo_data->play_time, npplg_av_video_seek_result_callback, 0);
            npplg_av_main_set_callback_app_id(NPPLG_AV_OBJ_TYPE_VIDEO, plugin_data->app_id);
        }
        else
        {
            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_RESET_PLAY_PANEL);
            npplg_av_main_switch_backlight(KAL_FALSE);
        }
    }
#ifdef __MMI_VIDEO_PDL__
    else
    {
#ifdef __COSMOS_MMI_PACKAGE__
        mdi_video_ply_set_scenario_type(MDI_VIDEO_SCENARIO_QVGA);
#endif
        result = mdi_video_progressive_open_file(g_npplg_av_context.app_cnxt[plugin_data->app_id].mem_app_id,
                                                 (const S8*)plugin_data->file_path,
                                                 npplg_av_video_pdl_open_callback,
                                                 0);

        if (result != MDI_RES_VDOPLY_SUCCEED)
        {
            vdo_data->is_pdl_or_rtsp = KAL_FALSE;
            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_DOWNLOADING);
            plugin_data->prev_state = NPPLG_AV_VIDEO_OBJ_STATE_IDLE;

            npplg_av_main_switch_backlight(KAL_FALSE);
        }
        else
        {
            npplg_av_main_set_callback_app_id(NPPLG_AV_OBJ_TYPE_VIDEO, plugin_data->app_id);
            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_PDL_OPENING);
            vdo_data->is_pdl_or_rtsp = KAL_TRUE;
            plugin_data->prev_state = state;
        }
    }
#endif /* __MMI_VIDEO_PDL__ */
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_disable_seek_ctrl
 * DESCRIPTION
 *  This function is used to disable seek control.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_video_disable_seek_ctrl(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_obj_control_struct *rewind, *fast_forward;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rewind = npplg_av_util_get_control(plugin_data, NPPLG_AV_CTRL_TYPE_REWIND);
    fast_forward = npplg_av_util_get_control(plugin_data, NPPLG_AV_CTRL_TYPE_FAST_FORWARD);

    if (rewind != NULL)
    {
        rewind->display = NPPLG_AV_CTRL_DISP_DISABLE;
    }

    if (fast_forward != NULL)
    {
        fast_forward->display = NPPLG_AV_CTRL_DISP_DISABLE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_set_vdo_layer_clip
 * DESCRIPTION
 *  This function is used to set video layer clip.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  x_offset        [IN]        X offset
 *  y_offset        [IN]        Y offset
 * RETURNS
 *  Whether need to update LCM
 *****************************************************************************/
static kal_bool npplg_av_video_set_vdo_layer_clip(npplg_av_instance_struct *plugin_data, kal_int32 x_offset, kal_int32 y_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_rect_struct bbox, vdo, roi, tmp;
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
    kal_bool lcm_update = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    npplg_av_main_get_visible_screen_area(plugin_data, &tmp.x1, &tmp.y1, &tmp.x2, &tmp.y2);

    bbox.x1 = tmp.x1;
    bbox.y1 = tmp.y1;
    bbox.x2 = tmp.x1 + tmp.x2 - 1;
    bbox.y2 = tmp.y1 + tmp.y2 - 1;

    vdo.x1 = vdo_data->layer_x;
    vdo.y1 = vdo_data->layer_y;
    vdo.x2 = vdo.x1 + vdo_data->layer_w - 1;
    vdo.y2 = vdo.y1 + vdo_data->layer_h - 1;

    npplg_av_video_find_roi(&bbox, &vdo, &roi);
    if (roi.x1 || roi.y1 || roi.x2 || roi.y2)
    {
        gdi_layer_set_clip(roi.x1, roi.y1, roi.x2, roi.y2);
    }
    else
    {
        lcm_update = KAL_FALSE;
    }

    return lcm_update;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_free_vdo_layer
 * DESCRIPTION
 *  This function is used to free video layer.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_video_free_vdo_layer(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
    gdi_handle free_handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_FREE_VDO_LAYER, vdo_data->vdo_layer_handle, plugin_data->instance_id, plugin_data->obj_type, plugin_data->state);

#if defined(__GADGET_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)

    if (vdo_data->vdo_layer_handle != GDI_NULL_HANDLE)
    {
        if (plugin_data->app_id == NPPLG_AV_APP_ID_GOOGLE_GADGET)
        {
            g_npplg_av_context.app_cnxt[plugin_data->app_id].vdo_layer_handle = GDI_NULL_HANDLE;
            vdo_data->vdo_layer_handle = GDI_NULL_HANDLE;
            vdo_data->layer_h = 0;
            vdo_data->layer_w = 0;
            vdo_data->layer_x = 0;
            vdo_data->layer_y = 0;
            vdo_data->offset_x = 0;
            vdo_data->offset_y = 0;
            
            /* Send message to MMI to free video layer */
            npplg_av_util_send_free_vdo_layer_ind(kal_get_active_module_id(),
                                                  plugin_data->app_id,
                                                  plugin_data->instance_id);
            return;
        }
        else
        {
            /* MAUI_02726784: Should set blt layer before free layer */
            free_handle = g_npplg_av_context.app_cnxt[plugin_data->app_id].vdo_layer_handle;
            g_npplg_av_context.app_cnxt[plugin_data->app_id].vdo_layer_handle = GDI_NULL_HANDLE;
            vdo_data->vdo_layer_handle = GDI_NULL_HANDLE;

            if (g_npplg_av_context.app_cnxt[plugin_data->app_id].is_suspend_by_mmi == KAL_FALSE)
            {
                npplg_av_video_set_blt_layer(plugin_data);
            }

            if (free_handle != GDI_NULL_HANDLE)
            {
                if (vdo_data->audio_only)
                {
                    gdi_layer_free(free_handle);
                }
                else
                {
                    mdi_util_hw_layer_free(free_handle);
                }
            }

            if (g_npplg_av_context.app_cnxt[plugin_data->app_id].vdo_layer_buf != NULL)
            {
                npplg_av_main_free_noncache_memory(plugin_data->app_id, g_npplg_av_context.app_cnxt[plugin_data->app_id].vdo_layer_buf);
                g_npplg_av_context.app_cnxt[plugin_data->app_id].vdo_layer_buf = NULL;
            }
        }
    }

    vdo_data->layer_h = 0;
    vdo_data->layer_w = 0;
    vdo_data->layer_x = 0;
    vdo_data->layer_y = 0;
    vdo_data->offset_x = 0;
    vdo_data->offset_y = 0;

#else /* defined(__GADGET_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__) */

    if (vdo_data->vdo_layer_handle != GDI_NULL_HANDLE)
    {
        /* MAUI_02726784: Should set blt layer before free layer */
        free_handle = g_npplg_av_context.app_cnxt[plugin_data->app_id].vdo_layer_handle;
        g_npplg_av_context.app_cnxt[plugin_data->app_id].vdo_layer_handle = GDI_NULL_HANDLE;
        vdo_data->vdo_layer_handle = GDI_NULL_HANDLE;

        if (g_npplg_av_context.app_cnxt[plugin_data->app_id].is_suspend_by_mmi == KAL_FALSE)
        {
            npplg_av_video_set_blt_layer(plugin_data);
        }

        if (free_handle != GDI_NULL_HANDLE)
        {
            if (vdo_data->audio_only)
            {
                gdi_layer_free(free_handle);
            }
            else
            {
                mdi_util_hw_layer_free(free_handle);
            }
        }

        if (g_npplg_av_context.app_cnxt[plugin_data->app_id].vdo_layer_buf != NULL)
        {
            npplg_av_main_free_noncache_memory(plugin_data->app_id, g_npplg_av_context.app_cnxt[plugin_data->app_id].vdo_layer_buf);
            g_npplg_av_context.app_cnxt[plugin_data->app_id].vdo_layer_buf = NULL;
        }
    }

    vdo_data->layer_h = 0;
    vdo_data->layer_w = 0;
    vdo_data->layer_x = 0;
    vdo_data->layer_y = 0;
    vdo_data->offset_x = 0;
    vdo_data->offset_y = 0;

#endif /* defined(__GADGET_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__) */
}


#ifdef __MMI_VIDEO_PDL__
/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_pdl_open
 * DESCRIPTION
 *  Open PDL video
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_video_pdl_open(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
    MDI_RESULT m_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __COSMOS_MMI_PACKAGE__
    mdi_video_ply_set_scenario_type(MDI_VIDEO_SCENARIO_QVGA);
#endif
    m_result = mdi_video_progressive_open_file(g_npplg_av_context.app_cnxt[plugin_data->app_id].mem_app_id,
                                               (const S8*)plugin_data->file_path,
                                               npplg_av_video_pdl_open_callback,
                                               0);

    plugin_data->prev_state = NPPLG_AV_VIDEO_OBJ_STATE_IDLE;
    
    if (m_result != MDI_RES_VDOPLY_SUCCEED)
    {
        vdo_data->is_pdl_or_rtsp = KAL_FALSE;
        NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_DOWNLOADING);
    }
    else
    {
        npplg_av_main_set_callback_app_id(NPPLG_AV_OBJ_TYPE_VIDEO, plugin_data->app_id);
        NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_PDL_OPENING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_pdl_open_callback
 * DESCRIPTION
 *  The callback of PDL opening function (mdi_video_progressive_open_file())
 * PARAMETERS
 *  result          [IN]        Open result
 *  info            [IN]        Video info
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_video_pdl_open_callback(MDI_RESULT result, mdi_video_info_struct *info, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_struct *plugin_data;
    npplg_av_video_data_struct *vdo_data;
    npplg_av_rect_struct rect_in, rect_out;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_PDL_OPEN_RESULT, result);

    NPPLG_AV_LOCK;

    plugin_data = npplg_av_main_get_active_instance(npplg_av_main_get_callback_app_id(NPPLG_AV_OBJ_TYPE_VIDEO));
    
    if (plugin_data != NULL &&
        plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO &&
        plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_PDL_OPENING)
    {
        if (result == MDI_RES_VDOPLY_SUCCEED)
        {
            vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
            vdo_data->vdo_height = info->height;
            vdo_data->vdo_width = info->width;
            if (info->track == MDI_VIDEO_TRACK_A_ONLY)
            {
                vdo_data->audio_only = KAL_TRUE;
            }
            else
            {
                vdo_data->audio_only = KAL_FALSE;
            }

            plugin_data->seekable = KAL_TRUE;
            vdo_data->total_time = info->total_time_duration;
            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_BUFFERING);
            mdi_video_progressive_get_buf_percentage(&vdo_data->pdl_buf_percentage);
            if (vdo_data->pdl_buf_percentage < 100)
            {
                npplg_av_video_start_pdl_buf_check_timer(plugin_data);
                if (npplg_av_main_check_timer_start(plugin_data, NPPLG_AV_TIMER_UPDATE_PROCESSNG_IMG) == KAL_FALSE)
                {
                    /* Show waiting image */
                    plugin_data->processing_img_indx = 0;
                    npplg_av_util_show_processing_image(plugin_data, KAL_TRUE);
                }
            }
            else
            {
                if (plugin_data->prev_state == NPPLG_AV_VIDEO_OBJ_STATE_PAUSED ||
                    plugin_data->prev_state == NPPLG_AV_VIDEO_OBJ_STATE_PLAYING ||
                    plugin_data->prev_state == NPPLG_AV_VIDEO_OBJ_STATE_PAUSED_PLAY)
                {
                    /* Seek first because play_time may be large */
                    NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_WAITING_SEEK_RSP);

#if defined(__GADGET_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)
                    if (plugin_data->app_id != NPPLG_AV_APP_ID_GOOGLE_GADGET && vdo_data->vdo_layer_handle == GDI_NULL_HANDLE)
#else
                    if (vdo_data->vdo_layer_handle == GDI_NULL_HANDLE)
#endif /* defined(__GADGET_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__) */
                    {
                        npplg_av_video_get_best_fit_size(plugin_data);

                        if (vdo_data->audio_only == KAL_FALSE)
                        {
                            rect_in.x = vdo_data->layer_x;
                            rect_in.y = vdo_data->layer_y;
                            rect_in.w = vdo_data->layer_w;
                            rect_in.h = vdo_data->layer_h;

                            vdo_data->vdo_layer_handle = npplg_av_main_create_video_layer(plugin_data->app_id, &rect_in, &rect_out);

                            if (vdo_data->vdo_layer_handle == GDI_NULL_HANDLE)
                            {
                                mdi_video_progressive_close_file();
                                npplg_av_video_switch_to_idle_state(plugin_data);

                                NPPLG_AV_UNLOCK;
                                return;
                            }

                            vdo_data->layer_x = rect_out.x;
                            vdo_data->layer_y = rect_out.y;
                            vdo_data->layer_w = rect_out.w;
                            vdo_data->layer_h = rect_out.h;

                            /* Set blt layer */
                            npplg_av_video_set_blt_layer(plugin_data);
                        }
                    }
                    
                    mdi_video_ply_non_block_seek(vdo_data->play_time, npplg_av_video_seek_result_callback, 0);
                    npplg_av_main_set_callback_app_id(NPPLG_AV_OBJ_TYPE_VIDEO, plugin_data->app_id);
                }
                else
                {
                    npplg_av_util_invalidate_rect(plugin_data, NULL);
                    npplg_av_video_start_to_play(plugin_data);
                }
            }
        }
        else
        {
            npplg_av_video_switch_to_idle_state(plugin_data);
        }
    }

    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_start_pdl_buf_check_timer
 * DESCRIPTION
 *  Start a timer to check PDL buffer percentage
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_video_start_pdl_buf_check_timer(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (npplg_av_main_start_timer(plugin_data,
                                  NPPLG_AV_TIMER_PDL_BUF_CHECK,
                                  NPPLG_AV_PDL_BUF_CHECK_INTERVAL) == KAL_FALSE)
    {
        npplg_av_video_close(plugin_data);
        vdo_data->is_pdl_or_rtsp = KAL_FALSE;

        if (plugin_data->dl_state == NPPLG_AV_OBJ_DL_STATE_DOWNLOADING)
        {
            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_DOWNLOADING);
        }
        else if (plugin_data->dl_state == NPPLG_AV_OBJ_DL_STATE_DOWNLOAD_OK)
        {
            if (npplg_av_video_file_open(plugin_data) == KAL_TRUE)
            {
                npplg_av_video_start_to_play(plugin_data);
            }
        }
        else
        {
            ASSERT(0);
        }
    }
}
#endif /* __MMI_VIDEO_PDL__ */


/************************************************************
 * Global Function
 ************************************************************/

/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_handle_event
 * DESCRIPTION
 *  This function is used to handle event.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  event           [IN]        Event
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_video_handle_event(npplg_av_instance_struct *plugin_data, kal_uint8 event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_RESET_PLAY_PANEL)
    {
        npplg_av_video_reset_vdo_data(plugin_data);
        npplg_av_video_set_state_to_idle(plugin_data);
    }
    
    switch (event)
    {
        case NPPLG_AV_INT_EVT_PLAY:
            npplg_av_video_handle_play_event(plugin_data);
            break;

        case NPPLG_AV_INT_EVT_PAUSE:
            npplg_av_video_handle_pause_event(plugin_data);
            break;

        case NPPLG_AV_INT_EVT_STOP:
            npplg_av_video_handle_stop_event(plugin_data);
            break;

        case NPPLG_AV_INT_EVT_FAST_FORWARD_START:
            npplg_av_video_handle_seek_event(plugin_data, KAL_TRUE, KAL_TRUE);
            break;

        case NPPLG_AV_INT_EVT_FAST_FORWARD_STOP:
            npplg_av_video_handle_seek_event(plugin_data, KAL_FALSE, KAL_TRUE);
            break;

        case NPPLG_AV_INT_EVT_REWIND_START:
            npplg_av_video_handle_seek_event(plugin_data, KAL_TRUE, KAL_FALSE);
            break;

        case NPPLG_AV_INT_EVT_REWIND_STOP:
            npplg_av_video_handle_seek_event(plugin_data, KAL_FALSE, KAL_FALSE);
            break;

        case NPPLG_AV_INT_EVT_LAUNCH_MEDIA_PLAYER:
            npplg_av_video_launch_media_player(plugin_data);
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_handle_timer_event
 * DESCRIPTION
 *  This function is used to handle timer timeout event.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  timer_type      [IN]        Timer type
 * RETURNS
 *  Indicate whether the event is handled by plug-in
 * RETURN VALUE LIST
 *  KAL_TRUE            Plug-in handles the event
 *  KAL_FALSE           Plug-in ignores the event
 *****************************************************************************/
kal_int16 npplg_av_video_handle_timer_event(npplg_av_instance_struct *plugin_data, kal_uint8 timer_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
    npplg_av_obj_control_struct *update_ctrl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (timer_type == NPPLG_AV_TIMER_UPDATE_PROCESSNG_IMG)
    {
        plugin_data->processing_img_indx++;
        npplg_av_util_show_processing_image(plugin_data, KAL_TRUE);
    }
    else
    {
        switch (plugin_data->state)
        {
#ifdef __MMI_VIDEO_PDL__
            case NPPLG_AV_VIDEO_OBJ_STATE_BUFFERING:
            {
                /*
                 * In this state, there are two possible timers
                 * 1. NPPLG_AV_TIMER_UPDATE_PROCESSNG_IMG
                 * 2. NPPLG_AV_TIMER_PDL_BUF_CHECK
                 */
                if (timer_type == NPPLG_AV_TIMER_PDL_BUF_CHECK)
                {
                    mdi_video_progressive_get_buf_percentage(&vdo_data->pdl_buf_percentage);
                    if (vdo_data->pdl_buf_percentage < 100)
                    {
                        npplg_av_video_start_pdl_buf_check_timer(plugin_data);
                    }
                    else
                    {
                        if (plugin_data->prev_state == NPPLG_AV_VIDEO_OBJ_STATE_PAUSED ||
                            plugin_data->prev_state == NPPLG_AV_VIDEO_OBJ_STATE_PLAYING ||
                            plugin_data->prev_state == NPPLG_AV_VIDEO_OBJ_STATE_PAUSED_PLAY)
                        {
                            /* Seek first because play_time may be large */
                            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_WAITING_SEEK_RSP);
                            mdi_video_ply_non_block_seek(vdo_data->play_time, npplg_av_video_seek_result_callback, 0);
                            npplg_av_main_set_callback_app_id(NPPLG_AV_OBJ_TYPE_VIDEO, plugin_data->app_id);
                        }
                        else
                        {
                            npplg_av_video_start_to_play(plugin_data);
                        }
                    }
                }
                break;
            }
#endif /* __MMI_VIDEO_PDL__ */
            
            case NPPLG_AV_VIDEO_OBJ_STATE_PLAYING:
            {
                /*
                 * In this state, there are two possible timers
                 * 1. NPPLG_AV_TIMER_UPDATE_PROGRESS_BAR
                 * 2. NPPLG_AV_TIMER_HIDE_VIDEO_PLAY_PANEL
                 */
                if (timer_type == NPPLG_AV_TIMER_UPDATE_PROGRESS_BAR)
                {
                    if (plugin_data->play_panel_state == NPPLG_AV_PLAY_PANEL_STATE_DISPLAY)
                    {
                        /* Update UI - progress bar */
                        mdi_video_ply_get_cur_play_time(&vdo_data->play_time);
                        
                        update_ctrl = npplg_av_util_get_control(plugin_data, NPPLG_AV_CTRL_TYPE_PROGRESS_BAR);
                        if (update_ctrl != NULL)
                        {
                            npplg_av_util_invalidate_rect(plugin_data, update_ctrl);
                        }

                        update_ctrl = npplg_av_util_get_control(plugin_data, NPPLG_AV_CTRL_TYPE_TIME);
                        if (update_ctrl != NULL)
                        {
                            npplg_av_util_invalidate_rect(plugin_data, update_ctrl);
                        }
                        
                        npplg_av_main_start_timer(plugin_data,
                                                  NPPLG_AV_TIMER_UPDATE_PROGRESS_BAR,
                                                  NPPLG_AV_UPDATE_PROGRESS_BAR_INTERVAL);
                    }
                }
                else if (timer_type == NPPLG_AV_TIMER_HIDE_VIDEO_PLAY_PANEL)
                {
                    plugin_data->play_panel_state = NPPLG_AV_PLAY_PANEL_STATE_HIDE;
                    npplg_av_util_invalidate_rect(plugin_data, NULL);
                }
                break;
            }

            case NPPLG_AV_VIDEO_OBJ_STATE_SEEKING:
            {
                /* In this state, only one possible timer NPPLG_AV_TIMER_SEEK_REPEAT */
                if (timer_type == NPPLG_AV_TIMER_SEEK_REPEAT)
                {
                    /* Updata play time, the progress bar and start a timer */
                    if (plugin_data->seek_repeat_num > 0)
                    {
                        npplg_av_util_seek(plugin_data, KAL_TRUE);
                    }
                    else
                    {
                        npplg_av_util_seek(plugin_data, KAL_FALSE);
                    }
                }
                break;
            }

            case NPPLG_AV_VIDEO_OBJ_STATE_RESET_PLAY_PANEL:
            {
                if (timer_type == NPPLG_AV_TIMER_RESET_PLAY_PANEL)
                {
                    npplg_av_video_reset_vdo_data(plugin_data);
                    npplg_av_video_set_state_to_idle(plugin_data);
                }
                break;
            }
            
            default:
                break;
        }
    }
    
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_check_pdl_format
 * DESCRIPTION
 *  This function is used to check if the video is PDL format.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_video_check_pdl_format(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
    
#ifdef __MMI_VIDEO_PDL__
    FS_HANDLE file_handle;
    kal_uint8 *buf;
    kal_uint32 read_len;
#ifdef __MTK_TARGET__
    kal_bool is_pdl;
    MDI_RESULT m_result;
#endif /* __MTK_TARGET__ */
#endif /* __MMI_VIDEO_PDL__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plugin_data->suspend)
    {
        /* If plug-in instance is suspended due to interrupt, should not enter next state */
        return;
    }

#ifdef __MMI_VIDEO_PDL__
    if ((file_handle = FS_Open(plugin_data->file_path, FS_READ_ONLY | FS_OPEN_SHARED)) > 0)
    {
        buf = g_npplg_av_netscape_funcs[plugin_data->app_id].memalloc(NPPLG_AV_PDL_PEEK_SIZE);
        if (buf == NULL)
        {
            /* Will retry when function npplg_av_main_recv_data() is called again */
            FS_Close(file_handle);
            return;
        }
        
        if (FS_Read(file_handle, buf, NPPLG_AV_PDL_PEEK_SIZE, &read_len) < 0)
        {
            /* Will retry when function npplg_av_main_recv_data() is called again */
        }
        else if (read_len == NPPLG_AV_PDL_PEEK_SIZE)
        {
#ifdef __MTK_TARGET__
            m_result = mdi_video_progressive_is_pdl_format(buf,
                                                           NPPLG_AV_PDL_PEEK_SIZE,
                                                           &is_pdl);

            if (m_result != MDI_RES_VDOPLY_SUCCEED ||
                is_pdl == KAL_FALSE)
            {
                /* is_pdl_or_rtsp is FALSE */
                NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_DOWNLOADING);
            }
            else
            {
                /* Need to register MDI Audio interrupt callback before open video */
                vdo_data->is_pdl_or_rtsp = KAL_TRUE;
                npplg_av_video_waiting_play(plugin_data);
            }
#else /* __MTK_TARGET__ */
            /* is_pdl_or_rtsp is FALSE */
            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_DOWNLOADING);
#endif /* __MTK_TARGET__ */
        }
    }
    else
    {
        /* Will retry when function npplg_av_main_recv_data() is called again */
        return;
    }

    NPPLG_AV_MEM_FREE(plugin_data->app_id, buf);
    FS_Close(file_handle);

#else /* __MMI_VIDEO_PDL__ */

    NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_DOWNLOADING);
    vdo_data->is_pdl_or_rtsp = KAL_FALSE;

#endif /* __MMI_VIDEO_PDL__ */
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_handle_url_rsp
 * DESCRIPTION
 *  Handle download response
 * PARAMETERS
 *  plugin_data     [IN]        Video instance data
 *  download_rsp    [IN]        Download response
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_video_handle_url_rsp(npplg_av_instance_struct *plugin_data, NPReason download_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
    kal_int8 state;
    kal_bool display_error = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    plugin_data->dl_req_id = 0;
    
    switch (download_rsp)
    {
        case NPRES_DONE:
        {
            if (plugin_data->file_handle > 0)
            {
                FS_Close(plugin_data->file_handle);
                plugin_data->file_handle = 0;
            }
            
            if (plugin_data->file_path == NULL)
            {
                state = plugin_data->state;
                plugin_data->dl_state = NPPLG_AV_OBJ_DL_STATE_NULL;

                npplg_av_video_set_state_to_idle(plugin_data);

                if (state == NPPLG_AV_VIDEO_OBJ_STATE_PRE_BUFFERING ||
                    state == NPPLG_AV_VIDEO_OBJ_STATE_DOWNLOADING ||
                    state == NPPLG_AV_VIDEO_OBJ_STATE_LAUNCH_MEDIA_PLAYER)
                {
                    if (!plugin_data->suspend
#ifdef __GADGET_SUPPORT__
                        || plugin_data->app_id == NPPLG_AV_APP_ID_GOOGLE_GADGET
#endif
                       )
                    {
                        /* Only when browser is in the foreground, plug-in can let browser display error popup */
                        npplg_av_main_display_popup(plugin_data, STR_GLOBAL_FILE_NOT_FOUND);
                    }
                }
            }
            else if (FS_GetAttributes(plugin_data->file_path) < 0)
            {
                state = plugin_data->state;
                plugin_data->dl_state = NPPLG_AV_OBJ_DL_STATE_NULL;
                NPPLG_AV_MEM_FREE(plugin_data->app_id, plugin_data->file_path);

                npplg_av_video_set_state_to_idle(plugin_data);

                if (state == NPPLG_AV_VIDEO_OBJ_STATE_PRE_BUFFERING ||
                    state == NPPLG_AV_VIDEO_OBJ_STATE_DOWNLOADING ||
                    state == NPPLG_AV_VIDEO_OBJ_STATE_LAUNCH_MEDIA_PLAYER)
                {
                    if (!plugin_data->suspend
#ifdef __GADGET_SUPPORT__
                        || plugin_data->app_id == NPPLG_AV_APP_ID_GOOGLE_GADGET
#endif
                       )
                    {
                        /* Only when browser is in the foreground, plug-in can let browser display error popup */
                        npplg_av_main_display_popup(plugin_data, STR_GLOBAL_FILE_NOT_FOUND);
                    }
                }

            }
            else
            {
                plugin_data->dl_state = NPPLG_AV_OBJ_DL_STATE_DOWNLOAD_OK;

    			/* Because video is downloaded, it should be treat as video file */
                vdo_data->is_pdl_or_rtsp = KAL_FALSE;

                if (!plugin_data->suspend)
                {
                    if (plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_LAUNCH_MEDIA_PLAYER)
                    {
                        vdo_data->is_pdl_or_rtsp = KAL_FALSE;
                        npplg_av_video_set_state_to_idle(plugin_data);
                        
                        /*
                         * Launch media player after video data is downloaded
                         * Send primitive to MMI because plug-in may not run in MMI task
                         */
                        npplg_av_util_send_launch_media_player_ind(plugin_data,
                                                                   kal_get_active_module_id(),
                                                                   NPPLG_AV_PLAYER_TYPE_VIDEO,
                                                                   KAL_FALSE);
                        return;
                    }
                    else if (plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_DOWNLOADING ||
                             plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_PRE_BUFFERING)
                    {
                        npplg_av_video_waiting_play(plugin_data);
                    }
                }
                else
                {
                    if (plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_LAUNCH_MEDIA_PLAYER)
                    {
                        npplg_av_video_set_state_to_idle(plugin_data);
                    }
                }
            }
            break;
        }

        case NPRES_NETWORK_ERR:
        {
            if (!plugin_data->suspend
#ifdef __GADGET_SUPPORT__
                || plugin_data->app_id == NPPLG_AV_APP_ID_GOOGLE_GADGET
#endif
               )
            {
                display_error = KAL_TRUE;
            }
            /* Continue the following action */
        }

        case NPRES_USER_BREAK:
        {
            plugin_data->dl_state = NPPLG_AV_OBJ_DL_STATE_NULL;
            NPPLG_AV_MEM_FREE(plugin_data->app_id, plugin_data->file_path);
            
            /* Stop PDL video */
            if (vdo_data->is_pdl_or_rtsp && !plugin_data->suspend)
            {
#ifdef __MMI_VIDEO_PDL__
                switch (plugin_data->state)
                {
                    case NPPLG_AV_VIDEO_OBJ_STATE_PLAYING:
                    {
                        mdi_video_ply_stop();
                        /* Continue the following action */
                    }
                    
                    case NPPLG_AV_VIDEO_OBJ_STATE_PDL_OPENING:
                    case NPPLG_AV_VIDEO_OBJ_STATE_BUFFERING:
                    case NPPLG_AV_VIDEO_OBJ_STATE_PAUSED:
                    case NPPLG_AV_VIDEO_OBJ_STATE_PAUSED_PLAY:
                    {
                        mdi_video_progressive_close_file();
                        break;
                    }

                    case NPPLG_AV_VIDEO_OBJ_STATE_SEEKING:
                    {
                        npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_SEEK_REPEAT);
                        plugin_data->seek_repeat_num = 0;
                        plugin_data->prev_state = NPPLG_AV_VIDEO_OBJ_STATE_IDLE;
                        mdi_video_progressive_close_file();
                        break;
                    }

                    default:
                        break;
                }
#endif /* __MMI_VIDEO_PDL__ */
            }

            if (plugin_data->file_handle > 0)
            {
                FS_Close(plugin_data->file_handle);
                plugin_data->file_handle = 0;
                FS_Delete(plugin_data->file_path);
            }
            
            NPPLG_AV_MEM_FREE(plugin_data->app_id, plugin_data->file_path);
            npplg_av_video_reset_vdo_data(plugin_data);
            npplg_av_video_set_state_to_idle(plugin_data);

            if (display_error)
            {
                if (plugin_data->error == NPPLG_AV_ERROR_FILE)
                {
                    plugin_data->error = NPPLG_AV_ERROR_NULL;
                    npplg_av_main_display_popup(plugin_data, STR_GLOBAL_FILE_NOT_FOUND);
                }
                else
                {
                    npplg_av_main_display_popup(plugin_data, STR_ID_NPPLG_NETWORK_ERROR);
                }
            }
            break;
        }

        default:
            ASSERT(0);
            break;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_get_best_fit_size
 * DESCRIPTION
 *  Get the best fit size of the video
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_video_get_best_fit_size(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 dest_x, dest_y, dest_w, dest_h, layer_x, layer_y;
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* If video only has audio track, plug-in would draw a image */
    if (vdo_data->audio_only == KAL_FALSE)
    {
#ifdef __MDI_DISPLAY_FIT_INSIDE_SUPPORT__
        vdo_data->offset_x = 0;
        vdo_data->offset_y = 0;
        dest_w = plugin_data->width;
        dest_h = plugin_data->height;
#else
        gdi_image_util_fit_bbox(plugin_data->width,
                                plugin_data->height,
                                vdo_data->vdo_width,
                                vdo_data->vdo_height,
                                &vdo_data->offset_x,
                                &vdo_data->offset_y,
                                &dest_w,
                                &dest_h);
#endif
    }
    else
    {
        vdo_data->offset_x = 0;
        vdo_data->offset_y = 0;
        dest_w = plugin_data->width;
        dest_h = plugin_data->processing_img_h;
    }

    dest_x = plugin_data->x + vdo_data->offset_x;
    dest_y = plugin_data->y + vdo_data->offset_y;
    
    npplg_av_main_convert_coordinate(plugin_data, dest_x, dest_y, &layer_x, &layer_y);

    if (vdo_data->audio_only == KAL_FALSE)
    {
        if (layer_x % 2 != 0)
        {
            /* x coordinate should be even */
            layer_x++;
            vdo_data->offset_x++;
            dest_w--;
        }

        if (layer_y % 2 != 0)
        {
            /* y coordinate should be even */
            layer_y++;
            vdo_data->offset_y++;
            dest_h--;
        }

        /* Width should be even */
        if (dest_w % 2 != 0)
        {
            dest_w--;
        }

        /* Height should be even */
        if (dest_h % 2 != 0)
        {
            dest_h--;
        }
    }

    dest_w = ((dest_w <= 0) ? 2 : dest_w);
    dest_h = ((dest_h <= 0) ? 2 : dest_h);

    vdo_data->layer_x = layer_x;
    vdo_data->layer_y = layer_y;
    vdo_data->layer_w = dest_w;
    vdo_data->layer_h = dest_h;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_start_to_play
 * DESCRIPTION
 *  This function is used to handle play event.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_video_start_to_play(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vdo_data->vdo_layer_handle == GDI_NULL_HANDLE)
    {
#if defined(__GADGET_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)

        if (plugin_data->app_id == NPPLG_AV_APP_ID_GOOGLE_GADGET)
        {
            if (vdo_data->audio_only == KAL_FALSE)
            {
#ifdef __MMI_VIDEO_STREAM__
                if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
                {
                    npplg_av_stream_prepare_vdo_layer(plugin_data);
                }
                else
#endif /* __MMI_VIDEO_STREAM__ */
                npplg_av_video_prepare_vdo_layer(plugin_data);

                return;
            }
            else
            {
                /* Need to calculate the area where plug-in will draw audio only image */
                npplg_av_video_get_best_fit_size(plugin_data);
            }
        }
        else
        {
            if (vdo_data->audio_only == KAL_FALSE)
            {
                if (npplg_av_video_create_vdo_layer(plugin_data) == KAL_FALSE)
                {
                    return;
                }

                /* Set blt layer */
                npplg_av_video_set_blt_layer(plugin_data);
            }
            else
            {
                /* Need to calculate the area where plug-in will draw audio only image */
                npplg_av_video_get_best_fit_size(plugin_data);
            }
        }

#else /* defined(__GADGET_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__) */

        if (vdo_data->audio_only == KAL_FALSE)
        {
            if (npplg_av_video_create_vdo_layer(plugin_data) == KAL_FALSE)
            {
                return;
            }

            /* Set blt layer */
            npplg_av_video_set_blt_layer(plugin_data);
        }
        else
        {
            /* Need to calculate the area where plug-in will draw audio only image */
            npplg_av_video_get_best_fit_size(plugin_data);
        }

#endif /* defined(__GADGET_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__) */
    }

    plugin_data->processing = KAL_FALSE;
    npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_UPDATE_PROCESSNG_IMG);

    /* Clear the video area */
    npplg_av_util_invalidate_rect(plugin_data, NULL);

#ifdef __MMI_VIDEO_STREAM__
    if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
    {
        npplg_av_stream_play(plugin_data);
    }
    else
#endif /* __MMI_VIDEO_STREAM__ */    
    npplg_av_video_play(plugin_data);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_decide_layout
 * DESCRIPTION
 *  This function is used to decide the layout of playback controls.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_video_decide_layout(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const kal_uint8 *ctrl_array[NPPLG_AV_CFG_DIFF_VDO_PLAY_PANEL_NUM];
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Decide which controls should be drawn according to the configuration and object size */
    for (i = 0; i < NPPLG_AV_CFG_DIFF_VDO_PLAY_PANEL_NUM; i++)
    {
        ctrl_array[i] = g_npplg_av_cfg_video_play_panel[i];
    }
    npplg_av_util_compose_play_panel(plugin_data,
                                     NPPLG_AV_OBJ_TYPE_VIDEO,
                                     ctrl_array,
                                     NPPLG_AV_CFG_DIFF_VDO_PLAY_PANEL_NUM,
                                     NPPLG_AV_VDO_PANEL_MAX_SUPPORT_CTRL_NUM);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_show_additional_info
 * DESCRIPTION
 *  This function is used to show "Video" string and video image in IDLE state.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  paint_layer     [IN]        Paint layer
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_video_show_additional_info(npplg_av_instance_struct *plugin_data, gdi_handle paint_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 vdo_img_x, vdo_img_y, vdo_img_w, vdo_img_h, vdo_str_w, vdo_str_h;
    kal_uint8 *vdo_img, *vdo_str;
    GDI_RESULT ret;
    mmi_fe_color str_color;
    stFontAttribute font, medium_font = {0, 0, 0, MEDIUM_FONT, 0, 0};
    U8 arr_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Only show video string and image if state is idle*/
#if defined(__MMI_VIDEO_STREAM__)
    if ((plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO &&
         plugin_data->state != NPPLG_AV_VIDEO_OBJ_STATE_IDLE) ||
        (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING &&
         plugin_data->state != NPPLG_AV_STREAM_OBJ_STATE_IDLE))
#else
    if (plugin_data->state != NPPLG_AV_VIDEO_OBJ_STATE_IDLE)
#endif
    {
        return;
    }

    /*
     * Decide whether plug-in should display "Video" string and video image in IDLE state
     * 1. Get the string size (vdo_str_w and vdo_str_h)
     * 2. Decide whether plug-in should display "Video" string
     */
    vdo_str = (kal_uint8*)get_string(STR_GLOBAL_VIDEO);
    GetFont(&font, &arr_count);
    SetFont(medium_font, 0);
    Get_StringWidthHeight(vdo_str, &vdo_str_w, &vdo_str_h);

    if ((vdo_str_w + NPPLG_AV_CFG_VDO_BLANK_PIXEL * 2) <= plugin_data->width &&
        (vdo_str_h + NPPLG_AV_CFG_VDO_BLANK_PIXEL * 2) <= plugin_data->processing_img_h)
    {
        /* Draw the text */
        str_color.a = NPPLG_AV_CFG_VDO_STR_COLOR_A;
        str_color.r = NPPLG_AV_CFG_VDO_STR_COLOR_R;
        str_color.g = NPPLG_AV_CFG_VDO_STR_COLOR_G;
        str_color.b = NPPLG_AV_CFG_VDO_STR_COLOR_B;
        mmi_fe_set_text_color(str_color);
        mmi_fe_show_string_ext(plugin_data->x + NPPLG_AV_CFG_VDO_BLANK_PIXEL,
                               plugin_data->y + NPPLG_AV_CFG_VDO_BLANK_PIXEL,
                               vdo_str);
    }

    /*
     * 3. Get the video image size
     * 4. Decide whether plug-in should display video image
     */
    vdo_img = (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_VIDEO_SMALL);
    ret = gdi_image_get_dimension(vdo_img, &vdo_img_w, &vdo_img_h);
    if (ret == GDI_SUCCEED)
    {
        if (vdo_img_w <= plugin_data->width &&
            (vdo_str_h + NPPLG_AV_CFG_VDO_BLANK_PIXEL * 3 + vdo_img_h) <= plugin_data->processing_img_h)
        {
            vdo_img_x = plugin_data->x + (plugin_data->width - vdo_img_w) / 2;
            vdo_img_y = plugin_data->y + vdo_str_h + NPPLG_AV_CFG_VDO_BLANK_PIXEL * 2 + (plugin_data->processing_img_h - vdo_str_h - NPPLG_AV_CFG_VDO_BLANK_PIXEL * 3 - vdo_img_h) / 2;
            gdi_push_and_set_alpha_blending_source_layer(paint_layer);
            gdi_image_draw_blend2layers(vdo_img_x, vdo_img_y, vdo_img);
            gdi_pop_and_restore_alpha_blending_source_layer();
        }
    }

    SetFont(font, arr_count);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_redraw_window
 * DESCRIPTION
 *  This function is used to update the window.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_video_redraw_window(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
    kal_bool lcm_update, seek_play, update_vdo_layer = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lcm_update = KAL_TRUE;
    seek_play = KAL_FALSE;

    /* Decide the play panel */
    npplg_av_video_decide_layout(plugin_data);

    /* Video size is too small or too large */
    if (plugin_data->control_num <= 1)
    {
#ifdef __MMI_VIDEO_STREAM__
        if ((plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO &&
             plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_IDLE) ||
            (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING &&
             plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_IDLE))
#else
        if (plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_IDLE)
#endif
        {
            /* Draw the controls on the paint buffer */
            npplg_av_util_invalidate_rect(plugin_data, NULL);
        }
#ifdef __MMI_VIDEO_STREAM__
        else if ((plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO &&
                  plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_LAUNCH_MEDIA_PLAYER) ||
                 (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING &&
                  plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_LAUNCH_MEDIA_PLAYER))
#else
        else if (plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_LAUNCH_MEDIA_PLAYER)
#endif
        {
            /*
             * 1. Draw current processing image on the paint buffer immediately
             * 2. Not wait until the timer expires because the interval may be too long
             * 3. Playback controls would be cleared because play panel only has "Launch media player" icon now
             */
            npplg_av_util_show_processing_image(plugin_data, KAL_FALSE);
        }
        else if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
        {
            /*
             * If video is not in IDLE or LAUNCH_MEDIA_PLAYER state but video 
             * size becomes too small or too large, plug-in would only let user
             * launch media player to play the video.
             *
             * Stop current activity and redraw the window
             */
            if (g_npplg_av_context.app_cnxt[plugin_data->app_id].is_suspend_by_mmi == KAL_TRUE &&
                plugin_data == npplg_av_main_get_active_instance(plugin_data->app_id))
            {
                plugin_data->suspend = KAL_FALSE;
                npplg_av_video_close_by_app(plugin_data);
            }

            npplg_av_video_handle_event(plugin_data, NPPLG_AV_INT_EVT_STOP);
        }
#ifdef __MMI_VIDEO_STREAM__
        else if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
        {
            if (g_npplg_av_context.app_cnxt[plugin_data->app_id].is_suspend_by_mmi == KAL_TRUE &&
                plugin_data == npplg_av_main_get_active_instance(plugin_data->app_id))
            {
                plugin_data->suspend = KAL_FALSE;
                npplg_av_stream_close_by_app(plugin_data);
            }
            
            npplg_av_stream_handle_event(plugin_data, NPPLG_AV_INT_EVT_STOP);
        }
#endif /* __MMI_VIDEO_STREAM__ */
        return;
    }

    if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO &&
        plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_LAUNCH_MEDIA_PLAYER &&
        plugin_data->dl_state == NPPLG_AV_OBJ_DL_STATE_DOWNLOADING)
    {
        /* Disable seek control */
        npplg_av_video_disable_seek_ctrl(plugin_data);
    }

    if (g_npplg_av_context.app_cnxt[plugin_data->app_id].is_suspend_by_mmi == KAL_FALSE)
    {
        /* Pause video playing */
        if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
        {
            seek_play = npplg_av_video_update_layer_pause(plugin_data);
        }
#ifdef __MMI_VIDEO_STREAM__
        else if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
        {
            seek_play = npplg_av_stream_update_layer_pause(plugin_data);
        }
#endif /* __MMI_VIDEO_STREAM__ */
    }

    if (vdo_data->vdo_layer_handle != GDI_NULL_HANDLE)
    {
#if defined(__GADGET_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)
        if (plugin_data->app_id == NPPLG_AV_APP_ID_GOOGLE_GADGET)
        {
            update_vdo_layer = KAL_TRUE;
        }
        else
#endif /* defined(__GADGET_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__) */
        {
            /* Free old video layer */
            npplg_av_video_free_vdo_layer(plugin_data);

            /* Create new video layer */
            if (npplg_av_video_create_vdo_layer(plugin_data) == KAL_FALSE)
            {
                return;
            }

            if (g_npplg_av_context.app_cnxt[plugin_data->app_id].is_suspend_by_mmi == KAL_FALSE)
            {
                /* Process video layer */
                lcm_update = npplg_av_video_process_vdo_layer(plugin_data);

                if (vdo_data->lcm_update == KAL_FALSE)
                {
                    lcm_update = KAL_FALSE;
                }

                lcm_update = npplg_av_main_decide_video_visual_update(plugin_data->app_id, lcm_update);
            }
        }
    }
    else if (vdo_data->audio_only == KAL_TRUE)
    {
        npplg_av_video_get_best_fit_size(plugin_data);
    }

    if (g_npplg_av_context.app_cnxt[plugin_data->app_id].is_suspend_by_mmi == KAL_FALSE)
    {
        if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO &&
            plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_PAUSED &&
            update_vdo_layer == KAL_FALSE)
        {
            plugin_data->prev_state = NPPLG_AV_VIDEO_OBJ_STATE_PAUSED;
            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_WAITING_SEEK_RSP);
            if (vdo_data->vdo_layer_handle != GDI_NULL_HANDLE)
            {
                mdi_video_ply_non_block_seek_and_get_frame(vdo_data->play_time, vdo_data->vdo_layer_handle, npplg_av_video_seek_result_callback, 0);
            }
            else
            {
                mdi_video_ply_non_block_seek(vdo_data->play_time, npplg_av_video_seek_result_callback, 0);
            }
            npplg_av_main_set_callback_app_id(NPPLG_AV_OBJ_TYPE_VIDEO, plugin_data->app_id);
        }

        /* Restore the video playing */
        if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
        {
            npplg_av_video_update_layer_resume(plugin_data, seek_play, lcm_update);
        }
#ifdef __MMI_VIDEO_STREAM__
        else if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
        {
            npplg_av_stream_update_layer_resume(plugin_data, seek_play, lcm_update);
        }
#endif /* __MMI_VIDEO_STREAM__ */
    }

    /* Draw the controls on the paint buffer */
    npplg_av_util_invalidate_rect(plugin_data, NULL);

#if defined(__GADGET_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)
    if (update_vdo_layer)
    {
        npplg_av_rect_struct new_vdo_area;

        npplg_av_video_get_best_fit_size(plugin_data);
        new_vdo_area.x = vdo_data->layer_x;
        new_vdo_area.y = vdo_data->layer_y;
        new_vdo_area.w = vdo_data->layer_w;
        new_vdo_area.h = vdo_data->layer_h;
        npplg_av_util_send_update_vdo_layer_ind(kal_get_active_module_id(),
                                                plugin_data->app_id,
                                                plugin_data->instance_id,
                                                &new_vdo_area,
                                                npplg_av_main_get_transparent_color(plugin_data->app_id));
    }
#endif /* defined(__GADGET_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__) */
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_set_position
 * DESCRIPTION
 *  This function is used to update video layer (set layer position).
 *  Because only x and y are different, plug-in does not need to create new video layer.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_video_set_position(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
    kal_bool lcm_update = KAL_FALSE;
    kal_int32 pbuf_x, pbuf_y, offset_x, offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    npplg_av_main_convert_coordinate(plugin_data,
                                     plugin_data->x,
                                     plugin_data->y, 
                                     &pbuf_x,
                                     &pbuf_y);

    offset_x = (pbuf_x + vdo_data->offset_x) - vdo_data->layer_x;
    offset_y = (pbuf_y + vdo_data->offset_y) - vdo_data->layer_y;

#if defined(__GADGET_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)
    if (plugin_data->app_id == NPPLG_AV_APP_ID_GOOGLE_GADGET)
    {
        /* Update video layer position */
        vdo_data->layer_x += offset_x;
        vdo_data->layer_y += offset_y;

        /* Update video layer if video layer exists */
        if (vdo_data->vdo_layer_handle != GDI_NULL_HANDLE)
        {
            npplg_av_rect_struct new_vdo_area;

            /* (x, y) coordinate should be even */
            if ((vdo_data->layer_x % 2) != 0)
            {
                vdo_data->layer_x++;
                vdo_data->offset_x++;
            }

            if ((vdo_data->layer_y % 2) != 0)
            {
                vdo_data->layer_y++;
                vdo_data->offset_y++;
            }

            new_vdo_area.x = vdo_data->layer_x;
            new_vdo_area.y = vdo_data->layer_y;
            new_vdo_area.w = vdo_data->layer_w;
            new_vdo_area.h = vdo_data->layer_h;
            npplg_av_util_send_update_vdo_layer_ind(kal_get_active_module_id(),
                                                    plugin_data->app_id,
                                                    plugin_data->instance_id,
                                                    &new_vdo_area,
                                                    npplg_av_main_get_transparent_color(plugin_data->app_id));
        }

        return;
    }
#endif /* defined(__GADGET_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__) */

    /*
     * 1. Only x and y coordinates are different so plug-in only needs to update video layer.
     * 2. If video is playing, suspend it first
     */
    if (g_npplg_av_context.app_cnxt[plugin_data->app_id].is_suspend_by_mmi == KAL_FALSE)
    {
        if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO &&
            plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_PLAYING)
        {
            if (vdo_data->audio_only == KAL_FALSE)
            {
                mdi_video_ply_update_layer_pause();
            }
        }
#ifdef __MMI_VIDEO_STREAM__
        else if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING &&
                 plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_PLAYING)
        {
            if (vdo_data->audio_only == KAL_FALSE)
            {
                mdi_video_stream_pause();
            }
        }
#endif /* __MMI_VIDEO_STREAM__ */
    }

    /* Update video layer if video layer exists */
    if (vdo_data->vdo_layer_handle != GDI_NULL_HANDLE)
    {
        /* Update video layer position */
        vdo_data->layer_x += offset_x;
        vdo_data->layer_y += offset_y;
        
        if (vdo_data->audio_only == KAL_FALSE)
        {
            /* (x, y) coordinate should be even */
            if ((vdo_data->layer_x % 2) != 0)
            {
                vdo_data->layer_x++;
                vdo_data->offset_x++;
            }

            if ((vdo_data->layer_y % 2) != 0)
            {
                vdo_data->layer_y++;
                vdo_data->offset_y++;
            }
        }

        gdi_layer_push_and_set_active(vdo_data->vdo_layer_handle);
        gdi_layer_set_position(vdo_data->layer_x, vdo_data->layer_y);

        if (vdo_data->audio_only == KAL_FALSE)
        {
            lcm_update = npplg_av_video_set_vdo_layer_clip(plugin_data, vdo_data->layer_x, vdo_data->layer_y);
        }

        if (vdo_data->lcm_update == KAL_FALSE)
        {
            lcm_update = KAL_FALSE;
        }

        lcm_update = npplg_av_main_decide_video_visual_update(plugin_data->app_id, lcm_update);
        
        gdi_layer_pop_and_restore_active();

        if (g_npplg_av_context.app_cnxt[plugin_data->app_id].is_suspend_by_mmi == KAL_FALSE)
        {
            npplg_av_video_set_blt_layer(plugin_data);
        }
    }

    if (g_npplg_av_context.app_cnxt[plugin_data->app_id].is_suspend_by_mmi == KAL_FALSE)
    {
        if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO &&
            plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_PLAYING)
        {
            if (vdo_data->audio_only == KAL_FALSE)
            {
                mdi_video_ply_update_layer_resume(vdo_data->vdo_layer_handle,
                                                  NPPLG_AV_BLT_LAYER_FLAG,
                                                  NPPLG_AV_VDO_PLAY_LAYER_FLAG,
                                                  lcm_update,
                                                  g_npplg_av_context.app_cnxt[plugin_data->app_id].rotate);
            }
        }
#ifdef __MMI_VIDEO_STREAM__
        else if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING &&
                 plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_PLAYING)
        {
            if (vdo_data->audio_only == KAL_FALSE)
            {
                mdi_video_stream_resume(vdo_data->vdo_layer_handle,
                                        NPPLG_AV_BLT_LAYER_FLAG,
                                        NPPLG_AV_VDO_PLAY_LAYER_FLAG,
                                        lcm_update,
                                        MDI_DEVICE_SPEAKER2,
                                        g_npplg_av_context.app_cnxt[plugin_data->app_id].rotate);
            }
        }
#endif /* __MMI_VIDEO_STREAM__ */
    }

    npplg_av_util_invalidate_rect(plugin_data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_reset_vdo_data
 * DESCRIPTION
 *  This function is used to reset video data.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_video_reset_vdo_data(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    npplg_av_video_free_vdo_layer(plugin_data);
    vdo_data->play_time = 0;
#ifdef __COSMOS_MMI_PACKAGE__
    vdo_data->create_vdo_frame = KAL_FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_set_state_to_idle
 * DESCRIPTION
 *  Set state as idle state
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_video_set_state_to_idle(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_obj_control_struct *play;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(kal_get_active_module_id() != MOD_MMI);

    if ((plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO && plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_IDLE)
#ifdef __MMI_VIDEO_STREAM__
        || (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING && plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_IDLE)
#endif
       )
    {
        return;
    }
    
    plugin_data->processing = KAL_FALSE;
    npplg_av_main_stop_all_timer(plugin_data);

    if (plugin_data->deleting == KAL_FALSE)
    {
        /* Because "Play" control may be disabled, should enable it */
        play = npplg_av_util_get_control(plugin_data, NPPLG_AV_CTRL_TYPE_PLAY);
        if (play != NULL)
        {
            play->display = NPPLG_AV_CTRL_DISP_ENABLE;
        }
        
        /* Update UI */
        plugin_data->play_panel_state = NPPLG_AV_PLAY_PANEL_STATE_DISPLAY;
        npplg_av_util_update_play_control(plugin_data, KAL_FALSE, KAL_FALSE);

        /* Reset seek control */
        if (plugin_data->reset_seek_ctrl == KAL_TRUE)
        {
            npplg_av_util_update_seek_control(plugin_data);
        }
 
        npplg_av_util_invalidate_rect(plugin_data, NULL);
    }

#ifdef __MMI_VIDEO_STREAM__
    if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
    {
        plugin_data->prev_state = NPPLG_AV_STREAM_OBJ_STATE_IDLE;
        NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_STREAM_OBJ_STATE_IDLE);
    }
    else
#endif /* __MMI_VIDEO_STREAM__ */
    {
        plugin_data->prev_state = NPPLG_AV_VIDEO_OBJ_STATE_IDLE;
        NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_IDLE);
    }

    if (npplg_av_main_get_active_instance(plugin_data->app_id) == plugin_data)
    {
        if (plugin_data->suspend ||
            g_npplg_av_context.is_speech_mode == KAL_TRUE ||
            g_npplg_av_context.app_cnxt[plugin_data->app_id].is_suspend_by_mmi == KAL_TRUE)
        {
            /*
             * Set active instance to NULL
             * Clear the interrupt instance because plug-in should not activate another instance when interrupt comes
             */
            npplg_av_main_set_active_instance(NULL, KAL_TRUE, plugin_data->app_id);
        }
        else
        {
            /*
             * Set active instance to NULL
             * Plug-in may activate another instance
             */
            npplg_av_main_set_active_instance(NULL, KAL_FALSE, plugin_data->app_id);
        }
    }

    plugin_data->suspend = KAL_FALSE;
    
    if (npplg_av_main_get_active_instance(plugin_data->app_id) == NULL)
    {
        if (g_npplg_av_context.res_status == NPPLG_AV_RES_STATUS_OCCUPIED)
        {
            if (g_npplg_av_context.app_cnxt[plugin_data->app_id].is_suspend_by_mmi == KAL_TRUE)
            {
                g_npplg_av_context.res_status = NPPLG_AV_RES_STATUS_NULL;
            }
            else
            {
                g_npplg_av_context.res_status = NPPLG_AV_RES_STATUS_RELEASING;
#ifdef __COSMOS_MMI_PACKAGE__
                npplg_av_util_send_resume_background_play_ind(kal_get_active_module_id(), plugin_data->obj_type, KAL_FALSE);
#else
                npplg_av_util_send_resume_background_play_ind(kal_get_active_module_id(), plugin_data->obj_type, KAL_TRUE);
#endif
            }
        }
        else if (g_npplg_av_context.res_status == NPPLG_AV_RES_STATUS_OCCUPYING)
        {
            g_npplg_av_context.res_status = NPPLG_AV_RES_STATUS_NULL;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_process_vdo_layer
 * DESCRIPTION
 *  This function is used to process video layer before playing.
 *  This function also decide the clipping area.
 *  If the video only has audio track, plug-in would draw a image on the video layer.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  Indicate whether visual update is TRUE or FALSE
 *****************************************************************************/
kal_bool npplg_av_video_process_vdo_layer(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
    kal_bool lcm_update = KAL_TRUE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vdo_data->vdo_layer_handle != GDI_NULL_HANDLE && vdo_data->audio_only == KAL_FALSE)
    {
        /* Set clip region */
        gdi_layer_push_and_set_active(vdo_data->vdo_layer_handle);
        lcm_update = npplg_av_video_set_vdo_layer_clip(plugin_data, vdo_data->layer_x, vdo_data->layer_y);
        gdi_layer_pop_and_restore_active();

#if defined(__GADGET_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)
        if (plugin_data->app_id == NPPLG_AV_APP_ID_GOOGLE_GADGET)
        {
            return lcm_update;
        }
#endif /* defined(__GADGET_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__) */

        npplg_av_video_set_blt_layer(plugin_data);
    }

    return lcm_update;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_suspend_by_app
 * DESCRIPTION
 *  This function is used to suspend video.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_video_suspend_by_app(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_SUSPEND, plugin_data->obj_type, plugin_data->instance_id, plugin_data->state);

    /* Avoid interaction */
    NPPLG_AV_LOCK;

    npplg_av_main_stop_all_timer(plugin_data);

    switch (plugin_data->state)
    {
        case NPPLG_AV_VIDEO_OBJ_STATE_WAITING_PLAY:
        {
            if (g_npplg_av_context.res_status != NPPLG_AV_RES_STATUS_OCCUPIED)
            {
#ifdef __COSMOS_MMI_PACKAGE__
                npplg_av_video_unprepare_vdo_layer(plugin_data);
#endif /* __COSMOS_MMI_PACKAGE__ */

                NPPLG_AV_UNLOCK;
                return;
            }
            break;
        }
        
#ifdef __MMI_VIDEO_PDL__
        case NPPLG_AV_VIDEO_OBJ_STATE_PDL_OPENING:
        case NPPLG_AV_VIDEO_OBJ_STATE_BUFFERING:
        {
            mdi_video_progressive_close_file();
            break;
        }
#endif /* __MMI_VIDEO_PDL__ */

        case NPPLG_AV_VIDEO_OBJ_STATE_PLAYING:
        {
            mdi_video_ply_stop();
            mdi_video_ply_get_cur_play_time(&vdo_data->play_time);
            npplg_av_video_close(plugin_data);
            break;
        }

#ifdef __COSMOS_MMI_PACKAGE__
        case NPPLG_AV_VIDEO_OBJ_STATE_CREATE_VDO_LAYER:
        {
            vapp_npplg_av_video_free_vdo_layer(plugin_data->app_id, plugin_data->instance_id);

            /* Continue the following action */
        }
#endif

        case NPPLG_AV_VIDEO_OBJ_STATE_PAUSED:
        case NPPLG_AV_VIDEO_OBJ_STATE_PAUSED_PLAY:
        {
            npplg_av_video_close(plugin_data);
            break;
        }
        
        case NPPLG_AV_VIDEO_OBJ_STATE_SEEKING:
        {
            plugin_data->seek_repeat_num = 0;
            if (plugin_data->prev_state == NPPLG_AV_VIDEO_OBJ_STATE_PLAYING ||
                plugin_data->prev_state == NPPLG_AV_VIDEO_OBJ_STATE_PAUSED ||
                plugin_data->prev_state == NPPLG_AV_VIDEO_OBJ_STATE_PAUSED_PLAY)
            {
                npplg_av_video_close(plugin_data);

                NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, plugin_data->prev_state);
                plugin_data->prev_state = NPPLG_AV_VIDEO_OBJ_STATE_IDLE;
            }
            else
            {
#ifdef __COSMOS_MMI_PACKAGE__
                npplg_av_video_unprepare_vdo_layer(plugin_data);
#endif /* __COSMOS_MMI_PACKAGE__ */

                NPPLG_AV_UNLOCK;
                return;
            }
            break;
        }

        case NPPLG_AV_VIDEO_OBJ_STATE_WAITING_SEEK_RSP:
        {
            mdi_video_ply_stop_non_block_seek();
            npplg_av_video_close(plugin_data);

            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, plugin_data->prev_state);
            plugin_data->prev_state = NPPLG_AV_VIDEO_OBJ_STATE_IDLE;
            break;
        }

        default:
        {
            /*
             * State:
             * NPPLG_AV_VIDEO_OBJ_STATE_IDLE
             * NPPLG_AV_VIDEO_OBJ_STATE_PRE_BUFFERING
             * NPPLG_AV_VIDEO_OBJ_STATE_DOWNLOADING
             * NPPLG_AV_VIDEO_OBJ_STATE_LAUNCH_MEDIA_PLAYER
             * NPPLG_AV_VIDEO_OBJ_STATE_RESET_PLAY_PANEL
             */

#ifdef __COSMOS_MMI_PACKAGE__
            npplg_av_video_unprepare_vdo_layer(plugin_data);
#endif /* __COSMOS_MMI_PACKAGE__ */

            NPPLG_AV_UNLOCK;
            return;
        }
    }

#ifdef __COSMOS_MMI_PACKAGE__
    npplg_av_video_unprepare_vdo_layer(plugin_data);
#endif /* __COSMOS_MMI_PACKAGE__ */

    npplg_av_main_switch_backlight(KAL_FALSE);
    
    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_resume_by_app
 * DESCRIPTION
 *  This function is used to resume video.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_video_resume_by_app(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_RESUME, plugin_data->obj_type, plugin_data->instance_id, plugin_data->state);

    /* Avoid interaction */
    NPPLG_AV_LOCK;
    
    if (g_npplg_av_context.is_speech_mode == KAL_TRUE)
    {
        /* Background call */
        switch (plugin_data->state)
        {
            case NPPLG_AV_VIDEO_OBJ_STATE_IDLE:
            case NPPLG_AV_VIDEO_OBJ_STATE_SEEKING:
                break;
            
            default:
            {
                /*
                 * NPPLG_AV_VIDEO_OBJ_STATE_PRE_BUFFERING
                 * NPPLG_AV_VIDEO_OBJ_STATE_DOWNLOADING
                 * NPPLG_AV_VIDEO_OBJ_STATE_WAITING_PLAY
                 * NPPLG_AV_VIDEO_OBJ_STATE_PDL_OPENING
                 * NPPLG_AV_VIDEO_OBJ_STATE_BUFFERING
                 * NPPLG_AV_VIDEO_OBJ_STATE_PLAYING
                 * NPPLG_AV_VIDEO_OBJ_STATE_PAUSED
                 * NPPLG_AV_VIDEO_OBJ_STATE_PAUSED_PLAY
                 * NPPLG_AV_VIDEO_OBJ_STATE_WAITING_SEEK_RSP
                 * NPPLG_AV_VIDEO_OBJ_STATE_LAUNCH_MEDIA_PLAYER
                 * NPPLG_AV_VIDEO_OBJ_STATE_RESET_PLAY_PANEL
                 * NPPLG_AV_VIDEO_OBJ_STATE_CREATE_VDO_LAYER
                 */
                NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_RESET_PLAY_PANEL);
                npplg_av_util_send_mmi_resume_ind(npplg_av_main_get_app_mod_id(plugin_data->app_id),
                                                  plugin_data->instance_id,
                                                  plugin_data->app_id,
                                                  plugin_data->state);
                break;
            }
        }
    }
    else
    {
#if defined(__GADGET_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)
        if (plugin_data->app_id == NPPLG_AV_APP_ID_GOOGLE_GADGET)
        {
            npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;

            if (vdo_data->create_vdo_frame)
            {
                /* Prepare video frame */
                vapp_npplg_av_video_prepare_vdo_layer(plugin_data->app_id,
                                                      plugin_data->instance_id,
                                                      vdo_data->layer_x,
                                                      vdo_data->layer_y,
                                                      vdo_data->layer_w,
                                                      vdo_data->layer_h,
                                                      g_npplg_av_context.app_cnxt[plugin_data->app_id].transparent_color);
                vdo_data->vdo_layer_handle = vapp_npplg_av_video_get_vdo_layer_handle();
                ASSERT(vdo_data->vdo_layer_handle != GDI_NULL_HANDLE);
                g_npplg_av_context.app_cnxt[plugin_data->app_id].vdo_layer_handle = vdo_data->vdo_layer_handle;
                g_npplg_av_context.blt_layer_flag = vapp_npplg_av_video_get_display_layer_flag();
                g_npplg_av_context.hw_layer_flag = vapp_npplg_av_video_get_hw_layer_flag();
                vdo_data->create_vdo_frame = KAL_FALSE;
            }
        }
#endif /* defined(__GADGET_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__) */

        switch (plugin_data->state)
        {
            case NPPLG_AV_VIDEO_OBJ_STATE_PRE_BUFFERING:
            case NPPLG_AV_VIDEO_OBJ_STATE_DOWNLOADING:
            case NPPLG_AV_VIDEO_OBJ_STATE_RESET_PLAY_PANEL:
            case NPPLG_AV_VIDEO_OBJ_STATE_LAUNCH_MEDIA_PLAYER:
            {
                npplg_av_util_send_mmi_resume_ind(npplg_av_main_get_app_mod_id(plugin_data->app_id),
                                                  plugin_data->instance_id,
                                                  plugin_data->app_id,
                                                  plugin_data->state);
                break;
            }

            case NPPLG_AV_VIDEO_OBJ_STATE_WAITING_PLAY:
            {
                npplg_av_main_switch_backlight(KAL_TRUE);

                /* Apply the mute setting of active plug-in instance */
                npplg_av_main_set_mute(plugin_data->mute, plugin_data->app_id);
                
                /* Set volume */
                mdi_audio_set_volume(MDI_VOLUME_MEDIA, npplg_av_main_get_volume(plugin_data->app_id));
                    
                g_npplg_av_context.res_status = NPPLG_AV_RES_STATUS_OCCUPIED;
                npplg_av_util_send_suspend_background_play_rsp(npplg_av_main_get_app_mod_id(plugin_data->app_id),
                                                               plugin_data->app_id,
                                                               NPPLG_AV_OK);
                break;
            }

#ifdef __COSMOS_MMI_PACKAGE__
            case NPPLG_AV_VIDEO_OBJ_STATE_CREATE_VDO_LAYER:
#endif
#ifdef __MMI_VIDEO_PDL__        
            case NPPLG_AV_VIDEO_OBJ_STATE_PDL_OPENING:
            case NPPLG_AV_VIDEO_OBJ_STATE_BUFFERING:
#endif
            case NPPLG_AV_VIDEO_OBJ_STATE_PLAYING:
            case NPPLG_AV_VIDEO_OBJ_STATE_PAUSED_PLAY:
            {
                npplg_av_main_switch_backlight(KAL_TRUE);
                
                npplg_av_video_resume_open(plugin_data, NPPLG_AV_VIDEO_OBJ_STATE_PLAYING);

                if (plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_DOWNLOADING ||
                    plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_RESET_PLAY_PANEL)
                {
                    plugin_data->processing_img_indx = 0;
                    npplg_av_util_send_mmi_resume_ind(npplg_av_main_get_app_mod_id(plugin_data->app_id),
                                                      plugin_data->instance_id,
                                                      plugin_data->app_id,
                                                      plugin_data->state);
                }
                else
                {
                    plugin_data->processing = KAL_FALSE;
                }
                break;
            }

            case NPPLG_AV_VIDEO_OBJ_STATE_PAUSED:
            {
                npplg_av_main_switch_backlight(KAL_TRUE);
                
                npplg_av_video_resume_open(plugin_data, NPPLG_AV_VIDEO_OBJ_STATE_PAUSED);

                if (plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_DOWNLOADING)
                {
                    NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_RESET_PLAY_PANEL);
                }
                
                if (plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_RESET_PLAY_PANEL)
                {
                    npplg_av_util_send_mmi_resume_ind(npplg_av_main_get_app_mod_id(plugin_data->app_id),
                                                      plugin_data->instance_id,
                                                      plugin_data->app_id,
                                                      plugin_data->state);
                }
                break;
            }

            default:
                break;
        }
    }
    
    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_close_by_app
 * DESCRIPTION
 *  This function is used to close video.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_video_close_by_app(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __COSMOS_MMI_PACKAGE__
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_CLOSE, plugin_data->obj_type, plugin_data->instance_id, plugin_data->state);

    NPPLG_AV_LOCK;

#ifdef __COSMOS_MMI_PACKAGE__
    vdo_data->create_vdo_frame = KAL_FALSE;
#endif

    if (plugin_data->state != NPPLG_AV_VIDEO_OBJ_STATE_IDLE)
    {
        NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_RESET_PLAY_PANEL);
    }

    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_visual_update
 * DESCRIPTION
 *  This function is used to enable/disable video visual update.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  lcm_update      [IN]        Enable/disable video visual update
 *  clear_vdo_layer [IN]        Clear video layer or not
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_video_visual_update(npplg_av_instance_struct *plugin_data, kal_bool lcm_update, kal_bool clear_vdo_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
    kal_bool visual_update = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NPPLG_AV_LOCK;

    if (lcm_update == KAL_FALSE || vdo_data->lcm_update == KAL_FALSE)
    {
        visual_update = KAL_FALSE;
    }

    if (plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_PLAYING &&
        vdo_data->audio_only == KAL_FALSE)
    {
        /* Should suspend video playing before update video layer */
        mdi_video_ply_update_layer_pause();
    }

    if (vdo_data->vdo_layer_handle != GDI_NULL_HANDLE && clear_vdo_layer == KAL_TRUE)
    {
        gdi_layer_push_and_set_active(vdo_data->vdo_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }

    if (plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_PLAYING &&
        vdo_data->audio_only == KAL_FALSE)
    {
#if defined(__GADGET_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)
        if (plugin_data->app_id == NPPLG_AV_APP_ID_GOOGLE_GADGET)
        {
            mdi_video_ply_update_layer_resume(vdo_data->vdo_layer_handle,
                                              g_npplg_av_context.blt_layer_flag,
                                              g_npplg_av_context.hw_layer_flag,
                                              visual_update,
                                              g_npplg_av_context.app_cnxt[plugin_data->app_id].rotate);
        }
        else
#endif /* defined(__GADGET_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__) */
        mdi_video_ply_update_layer_resume(vdo_data->vdo_layer_handle,
                                          NPPLG_AV_BLT_LAYER_FLAG,
                                          NPPLG_AV_VDO_PLAY_LAYER_FLAG,
                                          visual_update,
                                          g_npplg_av_context.app_cnxt[plugin_data->app_id].rotate);
    }
    
    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_stop_by_app_for_screen_rotate
 * DESCRIPTION
 *  This function is used to stop video due to screen rotate.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_video_stop_by_app_for_screen_rotate(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NPPLG_AV_LOCK;

    if (plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_PLAYING)
    {
        npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_UPDATE_PROGRESS_BAR);
        npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_HIDE_VIDEO_PLAY_PANEL);
        NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_PAUSED_PLAY);
        mdi_video_ply_stop();
        mdi_video_ply_get_cur_play_time(&vdo_data->play_time);
    }

    if (vdo_data->vdo_layer_handle != GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(vdo_data->vdo_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }
    
    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_redraw_vdo_layer
 * DESCRIPTION
 *  This function is used to redraw video layer for screen rotation.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_video_redraw_vdo_layer(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO &&
        vdo_data->vdo_layer_handle != GDI_NULL_HANDLE &&
        plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_PAUSED)
    {
        npplg_av_video_process_vdo_layer(plugin_data);

        if (vdo_data->audio_only == KAL_FALSE)
        {
            plugin_data->prev_state = NPPLG_AV_VIDEO_OBJ_STATE_PAUSED;
            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_WAITING_SEEK_RSP);
            if (vdo_data->vdo_layer_handle != GDI_NULL_HANDLE)
            {
                mdi_video_ply_non_block_seek_and_get_frame(vdo_data->play_time, vdo_data->vdo_layer_handle, npplg_av_video_seek_result_callback, 0);
            }
            else
            {
                mdi_video_ply_non_block_seek(vdo_data->play_time, npplg_av_video_seek_result_callback, 0);
            }
            npplg_av_main_set_callback_app_id(NPPLG_AV_OBJ_TYPE_VIDEO, plugin_data->app_id);
        }
    }

    npplg_av_util_invalidate_rect(plugin_data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_handle_suspend_background_play_rsp
 * DESCRIPTION
 *  Handle MSG_ID_NPPLG_AV_SUSPEND_BACKGROUND_PLAY_RSP
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  result          [IN]        Result
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_video_handle_suspend_background_play_rsp(npplg_av_instance_struct *plugin_data,
                                                       kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_WAITING_PLAY)
    {
        if (g_npplg_av_context.app_cnxt[plugin_data->app_id].is_suspend_by_mmi == KAL_TRUE &&
            result == NPPLG_AV_OK)
        {
            /*
             * Ignore this message because application is in the background
             * Do nothing but still stay in WAITING_PLAY state
             */
        }
        else if (g_npplg_av_context.app_cnxt[plugin_data->app_id].is_suspend_by_mmi == KAL_FALSE && result == NPPLG_AV_OK)
        {
            if (plugin_data->dl_state == NPPLG_AV_OBJ_DL_STATE_DOWNLOAD_OK)
            {
                if (npplg_av_video_file_open(plugin_data) == KAL_TRUE)
                {
                    npplg_av_video_start_to_play(plugin_data);
                }
            }
#ifdef __MMI_VIDEO_PDL__
            else
            {
                npplg_av_video_pdl_open(plugin_data);
            }
#endif /* __MMI_VIDEO_PDL__ */
        }
        else
        {
            npplg_av_video_reset_vdo_data(plugin_data);
            npplg_av_video_set_state_to_idle(plugin_data);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_mmi_resume_ind_handler
 * DESCRIPTION
 *  This function is used to handle MMI resume indication in engine task.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_video_mmi_resume_ind_handler(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    NPPLG_AV_LOCK;

    switch (plugin_data->state)
    {
        case NPPLG_AV_VIDEO_OBJ_STATE_PRE_BUFFERING:
        case NPPLG_AV_VIDEO_OBJ_STATE_DOWNLOADING:
        {
            if (plugin_data->dl_state == NPPLG_AV_OBJ_DL_STATE_DOWNLOAD_OK)
            {
                plugin_data->processing = KAL_FALSE;
                
                /* If video is downloaded, play the video */
                npplg_av_video_waiting_play(plugin_data);
            }
            else if (plugin_data->dl_state == NPPLG_AV_OBJ_DL_STATE_DOWNLOADING)
            {
                /*
                 * If video is still downloading, start a timer to show processing image
                 * Does not need reset plugin_data->processing_img_indx as 0
                 */
                npplg_av_util_show_processing_image(plugin_data, KAL_TRUE);
            }
            else
            {
                ASSERT(0);
            }
            break;
        }

        case NPPLG_AV_VIDEO_OBJ_STATE_LAUNCH_MEDIA_PLAYER:
        {
            npplg_av_util_show_processing_image(plugin_data, KAL_TRUE);
            break;
        }
        
        case NPPLG_AV_VIDEO_OBJ_STATE_RESET_PLAY_PANEL:
        {
            npplg_av_video_reset_vdo_data(plugin_data);
            npplg_av_video_set_state_to_idle(plugin_data);
            break;
        }
        
        default:
            break;
    }

    NPPLG_AV_UNLOCK;
}


#ifdef __COSMOS_MMI_PACKAGE__
/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_prepare_vdo_layer
 * DESCRIPTION
 *  This function is used to prepare video layer before playing.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_video_prepare_vdo_layer(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
    npplg_av_rect_struct vdo_area;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    npplg_av_video_get_best_fit_size(plugin_data);

    vdo_area.x = vdo_data->layer_x;
    vdo_area.y = vdo_data->layer_y;
    vdo_area.w = vdo_data->layer_w;
    vdo_area.h = vdo_data->layer_h;

    if (vdo_area.w <= 0 || vdo_area.h <= 0)
    {
        if (g_npplg_av_context.app_cnxt[plugin_data->app_id].is_suspend_by_mmi == KAL_FALSE)
        {
            if (plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_WAITING_SEEK_RSP)
            {
                mdi_video_ply_stop_non_block_seek();
            }
            else if (plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_PLAYING)
            {
                mdi_video_ply_stop();
            }

            npplg_av_video_close(plugin_data);
            npplg_av_video_switch_to_idle_state(plugin_data);
            npplg_av_main_display_popup(plugin_data, STR_ID_NPPLG_FAIL_TO_PLAY);
        }
        else if (plugin_data == npplg_av_main_get_active_instance(plugin_data->app_id))
        {
            plugin_data->suspend = KAL_FALSE;
            npplg_av_video_close_by_app(plugin_data);
            npplg_av_video_handle_event(plugin_data, NPPLG_AV_INT_EVT_STOP);
        }
    }
    else
    {
        NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_CREATE_VDO_LAYER);
        npplg_av_util_send_create_vdo_layer_req(kal_get_active_module_id(),
                                                plugin_data->instance_id,
                                                plugin_data->app_id,
                                                &vdo_area,
                                                npplg_av_main_get_transparent_color(plugin_data->app_id));
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_unprepare_vdo_layer
 * DESCRIPTION
 *  This function is used to unprepare video layer.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_video_unprepare_vdo_layer(npplg_av_instance_struct *plugin_data)
{
#ifdef __GADGET_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plugin_data->app_id == NPPLG_AV_APP_ID_GOOGLE_GADGET &&
        vdo_data->vdo_layer_handle != GDI_NULL_HANDLE)
    {
        /* Unprepare video frame */
        vapp_npplg_av_video_unprepare_vdo_layer(plugin_data->app_id, plugin_data->instance_id);
        vdo_data->create_vdo_frame = KAL_TRUE;
        vdo_data->vdo_layer_handle = GDI_NULL_HANDLE;
        g_npplg_av_context.app_cnxt[plugin_data->app_id].vdo_layer_handle = GDI_NULL_HANDLE;
    }
#endif /* __GADGET_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_create_vdo_layer_rsp_handler
 * DESCRIPTION
 *  This function is used to handle MMI video layer response in engine task.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  vdo_layer       [IN]        Video layer handle
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_video_create_vdo_layer_rsp_handler(npplg_av_instance_struct *plugin_data, gdi_handle vdo_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_CREATE_VDO_LAYER)
    {
        if (vdo_layer == GDI_NULL_HANDLE)
        {
            if (g_npplg_av_context.app_cnxt[plugin_data->app_id].is_suspend_by_mmi == KAL_FALSE)
            {
                npplg_av_video_close(plugin_data);
                npplg_av_video_switch_to_idle_state(plugin_data);
                npplg_av_main_display_popup(plugin_data, STR_ID_NPPLG_FAIL_TO_PLAY);
            }
            else if (plugin_data == npplg_av_main_get_active_instance(plugin_data->app_id))
            {
                plugin_data->suspend = KAL_FALSE;
                npplg_av_video_close_by_app(plugin_data);
                npplg_av_video_handle_event(plugin_data, NPPLG_AV_INT_EVT_STOP);
            }
        }
        else if (g_npplg_av_context.app_cnxt[plugin_data->app_id].is_suspend_by_mmi == KAL_FALSE)
        {
            g_npplg_av_context.app_cnxt[plugin_data->app_id].vdo_layer_handle = vdo_layer;
            vdo_data->vdo_layer_handle = vdo_layer;

            if (plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_CREATE_VDO_LAYER)
            {
                plugin_data->processing = KAL_FALSE;
                npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_UPDATE_PROCESSNG_IMG);

                /* Clear the video area */
                npplg_av_util_invalidate_rect(plugin_data, NULL);

                npplg_av_video_play(plugin_data);
            }
        }
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_video_mmi_update_video_layer
 * DESCRIPTION
 *  This function is used to update video layer from MMI task.
 * PARAMETERS
 *  plugin_data         [IN]        Plug-in instance data
 *  x                   [IN]        Coordinate x
 *  y                   [IN]        Coordinate y
 *  w                   [IN]        The width of video layer
 *  h                   [IN]        The height of video layer
 *  transparent_color   [IN]        Transparent color
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_video_mmi_update_video_layer(npplg_av_instance_struct *plugin_data, kal_int32 x, kal_int32 y, kal_int32 w, kal_int32 h, gdi_color transparent_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
    kal_bool lcm_update = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO &&
        plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_PLAYING)
    {
        if (vdo_data->audio_only == KAL_FALSE)
        {
            mdi_video_ply_update_layer_pause();
        }
    }
#ifdef __MMI_VIDEO_STREAM__
    else if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING &&
             plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_PLAYING)
    {
        if (vdo_data->audio_only == KAL_FALSE)
        {
            mdi_video_stream_pause();
        }
    }
#endif /* __MMI_VIDEO_STREAM__ */

    vapp_npplg_av_video_update_vdo_layer(plugin_data->app_id, plugin_data->instance_id, x, y, w, h, transparent_color);
    vdo_data->vdo_layer_handle = vapp_npplg_av_video_get_vdo_layer_handle();
    ASSERT(vdo_data->vdo_layer_handle != GDI_NULL_HANDLE);
    g_npplg_av_context.app_cnxt[plugin_data->app_id].vdo_layer_handle = vdo_data->vdo_layer_handle;
    g_npplg_av_context.blt_layer_flag = vapp_npplg_av_video_get_display_layer_flag();
    g_npplg_av_context.hw_layer_flag = vapp_npplg_av_video_get_hw_layer_flag();

    if (vdo_data->audio_only == KAL_FALSE)
    {
        lcm_update = KAL_TRUE;
    }

    if (vdo_data->lcm_update == KAL_FALSE)
    {
        lcm_update = KAL_FALSE;
    }

    lcm_update = npplg_av_main_decide_video_visual_update(plugin_data->app_id, lcm_update);
        
    if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
    {
        if (plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_PLAYING &&
            vdo_data->audio_only == KAL_FALSE)
        {
            mdi_video_ply_update_layer_resume(vdo_data->vdo_layer_handle,
                                              g_npplg_av_context.blt_layer_flag,
                                              g_npplg_av_context.hw_layer_flag,
                                              lcm_update,
                                              g_npplg_av_context.app_cnxt[plugin_data->app_id].rotate);
        }
        else if (plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_PAUSED)
        {
            plugin_data->prev_state = NPPLG_AV_VIDEO_OBJ_STATE_PAUSED;
            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_VIDEO_OBJ_STATE_WAITING_SEEK_RSP);
            mdi_video_ply_non_block_seek_and_get_frame(vdo_data->play_time, vdo_data->vdo_layer_handle, npplg_av_video_seek_result_callback, 0);
            npplg_av_main_set_callback_app_id(NPPLG_AV_OBJ_TYPE_VIDEO, plugin_data->app_id);
        }
    }
#ifdef __MMI_VIDEO_STREAM__
    else if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING &&
             plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_PLAYING)
    {
        if (vdo_data->audio_only == KAL_FALSE)
        {
            mdi_video_stream_resume(vdo_data->vdo_layer_handle,
                                    g_npplg_av_context.blt_layer_flag,
                                    g_npplg_av_context.hw_layer_flag,
                                    lcm_update,
                                    MDI_DEVICE_SPEAKER2,
                                    g_npplg_av_context.app_cnxt[plugin_data->app_id].rotate);
        }
    }
#endif /* __MMI_VIDEO_STREAM__ */
}
#endif /* __COSMOS_MMI_PACKAGE__ */

#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
#endif /* defined(OPERA_V10_BROWSER) || defined(__GADGET_SUPPORT__) */
