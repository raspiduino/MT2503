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
 *   npplg_av_stream.c
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   Implement plug-in instance for video streaming
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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

#if defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__MMI_VIDEO_STREAM__)

/* MDI header file */
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mdi_video.h"

/* Media player */
#ifdef __PLUTO_MMI_PACKAGE__
#include "MediaAppGprot.h"
#endif

/* A/V Plug-in header file */
#include "npplg_av_include.h"
#include "npplg_av_main.h"
#include "npplg_av_video.h"
#include "npplg_av_stream.h"
#include "npplg_av_util.h"
#include "npplg_av_custom_config.h"
#include "mmi_rp_app_npplg_def.h"
#include "npplg_struct.h"

#include "kal_general_types.h"
#include "MMIDataType.h"
#ifdef __PLUTO_MMI_PACKAGE__
#include "MediaPlayerGProt.h"
#endif
#include "fs_func.h"
#include "GlobalResDef.h"
#include "kal_active_module.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "mmi_media_app_trc.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "stack_config.h"
#include "gdi_include.h"
#include "lcd_if.h"
#include "gdi_const.h"

#ifdef __COSMOS_MMI_PACKAGE__
#include "vapp_npplg_av_include.h"
#endif


/************************************************************
 * Static Declaration
 ************************************************************/
static void npplg_av_stream_launch_media_player(npplg_av_instance_struct *plugin_data);
static void npplg_av_stream_handle_play_event(npplg_av_instance_struct *plugin_data);
static void npplg_av_stream_handle_stop_event(npplg_av_instance_struct *plugin_data);
static void npplg_av_stream_handle_pause_event(npplg_av_instance_struct *plugin_data);
static void npplg_av_stream_handle_seek_event(npplg_av_instance_struct *plugin_data, kal_bool start, kal_bool forward);
static void npplg_av_stream_waiting_play(npplg_av_instance_struct *plugin_data);
static kal_bool npplg_av_stream_init_and_connect(npplg_av_instance_struct *plugin_data, kal_bool display_popup);
static kal_bool npplg_av_stream_connect(npplg_av_instance_struct *plugin_data, kal_bool display_popup);
static MDI_RESULT npplg_av_stream_start_buffering(npplg_av_instance_struct *plugin_data);
static void npplg_av_stream_connect_result_callback(MDI_RESULT result, mdi_video_info_struct *info, void *user_data);
static void npplg_av_stream_buffering_result_callback(MDI_RESULT result, mdi_video_info_struct *info, void *user_data);
static void npplg_av_stream_play_result_callback(MDI_RESULT result, void *user_data);
static void npplg_av_stream_switch_to_idle_state(npplg_av_instance_struct *plugin_data);


/************************************************************
 * Local Function
 ************************************************************/

/*****************************************************************************
 * FUNCTION
 *  npplg_av_stream_launch_media_player
 * DESCRIPTION
 *  Launch media player to play the video streaming
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_stream_launch_media_player(npplg_av_instance_struct *plugin_data)
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
        case NPPLG_AV_STREAM_OBJ_STATE_IDLE:
        {
            if (vdo_data->is_pdl_or_rtsp)
            {
                /*
                 * RTSP link
                 *
                 * Launch media player -> send primitive to MMI because plug-in may not run in MMI task
                 */
                npplg_av_util_send_launch_media_player_ind(plugin_data,
                                                           kal_get_active_module_id(),
                                                           NPPLG_AV_PLAYER_TYPE_STREAM,
                                                           KAL_TRUE);
                return;
            }
            else if (plugin_data->dl_state == NPPLG_AV_OBJ_DL_STATE_DOWNLOAD_OK)
            {
                /* .sdp file has been downloaded. Check if the file still exists */
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
                                                           NPPLG_AV_PLAYER_TYPE_STREAM,
                                                           KAL_FALSE);
                return;
            }
            else
            {
                /*
                 * .sdp file is not downloaded, plug-in should download it first.
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
                    npplg_av_main_start_download(plugin_data, NPPLG_AV_STREAM_OBJ_STATE_LAUNCH_MEDIA_PLAYER);
                }
                else if (plugin_data->dl_state == NPPLG_AV_OBJ_DL_STATE_DOWNLOADING)
                {
                    /*
                     * Enter LAUNCH_MEDIA_PLAYER state
                     * When plug-in finishes downloading, it will launch media player
                     */
                    NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_STREAM_OBJ_STATE_LAUNCH_MEDIA_PLAYER);
                }
                else
                {
                    ASSERT(0);
                }
            }
            return;
        }

        case NPPLG_AV_STREAM_OBJ_STATE_INITED:
        case NPPLG_AV_STREAM_OBJ_STATE_INITED_PLAY:
        {
            break;
        }

        case NPPLG_AV_STREAM_OBJ_STATE_DOWNLOADING:
        {
            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_STREAM_OBJ_STATE_LAUNCH_MEDIA_PLAYER);
            return;
        }

        case NPPLG_AV_STREAM_OBJ_STATE_PLAYING:
        {
            mdi_video_stream_stop();
            mdi_video_stream_disconnect();
            break;
        }
        
        case NPPLG_AV_STREAM_OBJ_STATE_BUFFERING:
#ifdef __COSMOS_MMI_PACKAGE__
        case NPPLG_AV_STREAM_OBJ_STATE_CREATE_VDO_LAYER:
#endif
        {
            mdi_video_stream_stop_buffering();
            mdi_video_stream_disconnect();
            break;
        }
        
        case NPPLG_AV_STREAM_OBJ_STATE_CONNECTED:
        case NPPLG_AV_STREAM_OBJ_STATE_CONNECTING:
        {
            mdi_video_stream_disconnect();
            break;
        }

        case NPPLG_AV_STREAM_OBJ_STATE_PAUSED_PLAY:
        {
            if (plugin_data->seekable)
            {
                mdi_video_stream_disconnect();
            }
            break;
        }

        default:
            return;
    }

    mdi_video_stream_deinit();
    npplg_av_stream_switch_to_idle_state(plugin_data);
    
    if (vdo_data->is_pdl_or_rtsp)
    {
        /*
         * RTSP link
         *
         * Launch media player -> send primitive to MMI because plug-in may not run in MMI task
         */

        npplg_av_util_send_launch_media_player_ind(plugin_data,
                                                   kal_get_active_module_id(),
                                                   NPPLG_AV_PLAYER_TYPE_STREAM,
                                                   KAL_TRUE);
    }
    else
    {
        /* Launch media player -> send primitive to MMI because plug-in may not run in MMI task */
        npplg_av_util_send_launch_media_player_ind(plugin_data,
                                                   kal_get_active_module_id(),
                                                   NPPLG_AV_PLAYER_TYPE_STREAM,
                                                   KAL_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_stream_handle_play_event
 * DESCRIPTION
 *  This function is used to handle play event.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_stream_handle_play_event(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch (plugin_data->state)
    {
        case NPPLG_AV_STREAM_OBJ_STATE_IDLE:
        {
            if (!vdo_data->is_pdl_or_rtsp &&
                plugin_data->dl_state != NPPLG_AV_OBJ_DL_STATE_DOWNLOAD_OK)
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
                    /* Download .sdp file */
                    npplg_av_main_start_download(plugin_data, NPPLG_AV_STREAM_OBJ_STATE_DOWNLOADING);
                }
                else if (plugin_data->dl_state == NPPLG_AV_OBJ_DL_STATE_DOWNLOADING)
                {
                    /*
                     * Enter DOWNLOADING state
                     * When plug-in finishes downloading, it will play the video streaming
                     */
                    NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_STREAM_OBJ_STATE_DOWNLOADING);
                }
            }
            else
            {
                /* .sdp file has been downloaded. Check if the file still exists */
                if (!vdo_data->is_pdl_or_rtsp &&
                    plugin_data->dl_state == NPPLG_AV_OBJ_DL_STATE_DOWNLOAD_OK &&
                    FS_GetAttributes(plugin_data->file_path) < 0)
                {
                    plugin_data->dl_state = NPPLG_AV_OBJ_DL_STATE_NULL;
                    NPPLG_AV_MEM_FREE(plugin_data->app_id, plugin_data->file_path);
                    npplg_av_main_display_popup(plugin_data, STR_GLOBAL_FILE_NOT_FOUND);
                    return;
                }

                /* Set this instance as the active instance */
                npplg_av_main_set_active_instance(plugin_data, KAL_FALSE, plugin_data->app_id);
                
                npplg_av_stream_waiting_play(plugin_data);
            }
            break;
        }

        case NPPLG_AV_STREAM_OBJ_STATE_LAUNCH_MEDIA_PLAYER:
        {
            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_STREAM_OBJ_STATE_DOWNLOADING);
            break;
        }

        case NPPLG_AV_STREAM_OBJ_STATE_INITED:
        case NPPLG_AV_STREAM_OBJ_STATE_INITED_PLAY:
        {
            npplg_av_stream_connect(plugin_data, KAL_TRUE);
            break;
        }

        case NPPLG_AV_STREAM_OBJ_STATE_CONNECTED:
        {
            ASSERT(plugin_data->seekable);

            ret = npplg_av_stream_start_buffering(plugin_data);

            if (ret != MDI_RES_VDOPLY_SUCCEED)
            {
                /* Get the error string id from MDI and display error popup */
                npplg_av_util_display_mdi_error_popup(ret, plugin_data);
            }
            break;
        }

        case NPPLG_AV_STREAM_OBJ_STATE_PAUSED_PLAY:
        {
            if (plugin_data->seekable)
            {
                ret = npplg_av_stream_start_buffering(plugin_data);

                if (ret != MDI_RES_VDOPLY_SUCCEED)
                {
                    /* Get the error string id from MDI and display error popup */
                    npplg_av_util_display_mdi_error_popup(ret, plugin_data);
                }
            }
            else
            {
                npplg_av_stream_connect(plugin_data, KAL_TRUE);
            }
            break;
        }

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_stream_handle_stop_event
 * DESCRIPTION
 *  This function is used to handle stop event.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_stream_handle_stop_event(npplg_av_instance_struct *plugin_data)
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
        case NPPLG_AV_STREAM_OBJ_STATE_IDLE:
            return;

        case NPPLG_AV_STREAM_OBJ_STATE_LAUNCH_MEDIA_PLAYER:
        case NPPLG_AV_STREAM_OBJ_STATE_DOWNLOADING:
        {
            if (vdo_data->is_pdl_or_rtsp == KAL_FALSE)
            {
                npplg_av_main_abort_download_req(plugin_data);
            }
            npplg_av_video_set_state_to_idle(plugin_data);
            return;
        }

        case NPPLG_AV_STREAM_OBJ_STATE_PLAYING:
        {
            mdi_video_stream_stop();
            break;
        }
        
        case NPPLG_AV_STREAM_OBJ_STATE_BUFFERING:
        {
            mdi_video_stream_stop_buffering();
            break;
        }
        
        case NPPLG_AV_STREAM_OBJ_STATE_CONNECTED:
        case NPPLG_AV_STREAM_OBJ_STATE_CONNECTING:
            break;

        case NPPLG_AV_STREAM_OBJ_STATE_SEEKING:
        {
            npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_SEEK_REPEAT);
            plugin_data->seek_repeat_num = 0;
            if (plugin_data->prev_state == NPPLG_AV_STREAM_OBJ_STATE_IDLE)
            {
                npplg_av_stream_switch_to_idle_state(plugin_data);
                return;
            }
            plugin_data->prev_state = NPPLG_AV_STREAM_OBJ_STATE_IDLE;
            break;
        }

        case NPPLG_AV_STREAM_OBJ_STATE_INITED:
        case NPPLG_AV_STREAM_OBJ_STATE_INITED_PLAY:
        {
            mdi_video_stream_deinit();
            npplg_av_stream_switch_to_idle_state(plugin_data);
            return;
        }

        case NPPLG_AV_STREAM_OBJ_STATE_PAUSED_PLAY:
        {
            if (plugin_data->seekable == KAL_FALSE)
            {
                mdi_video_stream_deinit();
                npplg_av_stream_switch_to_idle_state(plugin_data);
                return;
            }
            break;
        }

        case NPPLG_AV_STREAM_OBJ_STATE_RESET_PLAY_PANEL:
        {
            npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_RESET_PLAY_PANEL);

            /* Continue following action */
        }

        case NPPLG_AV_STREAM_OBJ_STATE_WAITING_PLAY:
        {
            npplg_av_stream_switch_to_idle_state(plugin_data);
            return;
        }

#ifdef __COSMOS_MMI_PACKAGE__
        case NPPLG_AV_STREAM_OBJ_STATE_CREATE_VDO_LAYER:
        {
            mdi_video_stream_stop_buffering();
            mdi_video_stream_disconnect();
            mdi_video_stream_deinit();
            npplg_av_stream_switch_to_idle_state(plugin_data);
            npplg_av_util_send_free_vdo_layer_ind(kal_get_active_module_id(),
                                                  plugin_data->app_id,
                                                  plugin_data->instance_id);
            return;
        }
#endif /* __COSMOS_MMI_PACKAGE__ */

        default:
            return;
    }

    mdi_video_stream_disconnect();
    mdi_video_stream_deinit();
    npplg_av_stream_switch_to_idle_state(plugin_data);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_stream_handle_pause_event
 * DESCRIPTION
 *  This function is used to handle pause event.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_stream_handle_pause_event(npplg_av_instance_struct *plugin_data)
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
        case NPPLG_AV_STREAM_OBJ_STATE_INITED:
        case NPPLG_AV_STREAM_OBJ_STATE_CONNECTED:
        {
            break;
        }

        case NPPLG_AV_STREAM_OBJ_STATE_INITED_PLAY:
        {
            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_STREAM_OBJ_STATE_INITED);
            break;
        }
        
        case NPPLG_AV_STREAM_OBJ_STATE_CONNECTING:
        {
            mdi_video_stream_disconnect();
            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_STREAM_OBJ_STATE_INITED);
            break;
        }

        case NPPLG_AV_STREAM_OBJ_STATE_BUFFERING:
#ifdef __COSMOS_MMI_PACKAGE__
        case NPPLG_AV_STREAM_OBJ_STATE_CREATE_VDO_LAYER:
#endif
        {
            ASSERT(plugin_data->seekable);
            
            mdi_video_stream_stop_buffering();
            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_STREAM_OBJ_STATE_CONNECTED);
            break;
        }
        
        case NPPLG_AV_STREAM_OBJ_STATE_PLAYING:
        {
            npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_UPDATE_PROGRESS_BAR);
            npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_HIDE_VIDEO_PLAY_PANEL);
            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_STREAM_OBJ_STATE_CONNECTED);
            mdi_video_stream_stop();
            mdi_video_stream_get_cur_play_time(&vdo_data->play_time);

            /* Change "Pause" control to "Play" control */
            npplg_av_util_update_play_control(plugin_data, KAL_FALSE, KAL_TRUE);
            return;
        }

        case NPPLG_AV_STREAM_OBJ_STATE_PAUSED_PLAY:
        {
            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_STREAM_OBJ_STATE_CONNECTED);

            /* Change "Pause" control to "Play" control */
            npplg_av_util_update_play_control(plugin_data, KAL_FALSE, KAL_TRUE);
            return;
        }

        default:
            return;
    }

    plugin_data->processing = KAL_FALSE;
    npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_UPDATE_PROCESSNG_IMG);

    /* Change "Pause" control to "Play" control */
    npplg_av_util_update_play_control(plugin_data, KAL_FALSE, KAL_FALSE);
    npplg_av_util_invalidate_rect(plugin_data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_stream_handle_seek_event
 * DESCRIPTION
 *  This function is used to handle seek event (fast forward or rewind).
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  forward         [IN]        TRUE: fast forward, FALSE: rewind
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_stream_handle_seek_event(npplg_av_instance_struct *plugin_data, kal_bool start, kal_bool forward)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (start && plugin_data->seekable)
    {
        switch (plugin_data->state)
        {
            case NPPLG_AV_STREAM_OBJ_STATE_PLAYING:
            {
                npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_UPDATE_PROGRESS_BAR);
                npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_HIDE_VIDEO_PLAY_PANEL);
                mdi_video_stream_stop();
                mdi_video_stream_get_cur_play_time(&vdo_data->play_time);
                /* Continue the following action */
            }

            case NPPLG_AV_STREAM_OBJ_STATE_IDLE:
            case NPPLG_AV_STREAM_OBJ_STATE_CONNECTED:
            {
                plugin_data->seek_repeat_num = 0;

                /* Update the progress bar and start a timer */
                npplg_av_util_seek(plugin_data, forward);
                break;
            }

            case NPPLG_AV_STREAM_OBJ_STATE_BUFFERING:
            {
                plugin_data->seek_repeat_num = 0;
                mdi_video_stream_stop_buffering();
                npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_STREAM_BUF_CHECK);
                npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_UPDATE_PROCESSNG_IMG);

                /* Update the progress bar and start a timer */
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
        NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_STREAM_OBJ_STATE_SEEKING);
    }
    else if (!start && plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_SEEKING)
    {
        /* Receive mouse up event -> stop seeking */
        npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_SEEK_REPEAT);
        plugin_data->seek_repeat_num = 0;
        NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, plugin_data->prev_state);
        plugin_data->prev_state = NPPLG_AV_STREAM_OBJ_STATE_IDLE;

        if (plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_PLAYING ||
            plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_BUFFERING)
        {
            npplg_av_stream_start_buffering(plugin_data);
        }
    }
}



/*****************************************************************************
 * FUNCTION
 *  npplg_av_stream_waiting_play
 * DESCRIPTION
 *  Waiting for audio resource
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_stream_waiting_play(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 action;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Change state */
    NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_STREAM_OBJ_STATE_WAITING_PLAY);

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
 *  npplg_av_stream_init_and_connect
 * DESCRIPTION
 *  This function is used to init and connect video stream.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  display_popup   [IN]        Plug-in can let application display error popup or not
 * RETURNS
 *  The execution result
 *****************************************************************************/
static kal_bool npplg_av_stream_init_and_connect(npplg_av_instance_struct *plugin_data, kal_bool display_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mdi_video_stream_init(g_npplg_av_context.app_cnxt[plugin_data->app_id].mem_app_id);
    if (result < 0)
    {
        if (display_popup)
        {
            /* Get the error string id from MDI and display error popup */
            npplg_av_util_display_mdi_error_popup(result, plugin_data);
        }
        return KAL_FALSE;
    }

    NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_STREAM_OBJ_STATE_INITED);
    
    return npplg_av_stream_connect(plugin_data, display_popup);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_stream_connect
 * DESCRIPTION
 *  This function is used to connect video stream.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  display_popup   [IN]        Plug-in can let application display error popup or not
 * RETURNS
 *  The execution result
 *****************************************************************************/
static kal_bool npplg_av_stream_connect(npplg_av_instance_struct *plugin_data, kal_bool display_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
    MDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vdo_data->is_pdl_or_rtsp)
    {
        /* RTSP link */
        kal_wchar *ucs2_link = npplg_av_util_cvt_utf8_to_ucs2(plugin_data->url, plugin_data->app_id);

        if (ucs2_link == NULL)
        {
            mdi_video_stream_deinit();
            if (display_popup)
            {
                npplg_av_main_display_popup(plugin_data, STR_GLOBAL_ERROR);
            }
            return KAL_FALSE;
        }

#ifdef __COSMOS_MMI_PACKAGE__
        mdi_video_stream_set_scenario(MDI_VIDEO_SCENARIO_QVGA);
#endif
        result = mdi_video_stream_connect(npplg_av_main_get_data_account(plugin_data->app_id), /* Use browser setting here. If browser add streaming setting, can change to use it */
                                          MDI_VIDEO_STREAM_RTSP_URL,
                                          (kal_char*)ucs2_link,
                                          KAL_FALSE,
                                          NULL,
                                          0,
                                          KAL_FALSE,
                                          0,
                                          0,
                                          npplg_av_stream_connect_result_callback,
                                          NULL);

        npplg_av_main_free_memory(plugin_data->app_id, ucs2_link);
    }
    else
    {
        /* .sdp file has been downloaded. Check if the file still exists */
        if (FS_GetAttributes(plugin_data->file_path) < 0)
        {
            mdi_video_stream_deinit();
            if (display_popup)
            {
                npplg_av_main_display_popup(plugin_data, STR_GLOBAL_FILE_NOT_FOUND);
            }
            return KAL_FALSE;
        }

#ifdef __COSMOS_MMI_PACKAGE__
        mdi_video_stream_set_scenario(MDI_VIDEO_SCENARIO_QVGA);
#endif
        result = mdi_video_stream_connect(npplg_av_main_get_data_account(plugin_data->app_id),
                                          MDI_VIDEO_STREAM_SDP_FILE,
                                          (kal_char*)plugin_data->file_path,
                                          KAL_FALSE,
                                          NULL,
                                          0,
                                          KAL_FALSE,
                                          0,
                                          0,
                                          npplg_av_stream_connect_result_callback,
                                          NULL);
    }
    
    if (result < 0)
    {
        mdi_video_stream_deinit();        
        if (display_popup)
        {
            /* Get the error string id from MDI and display error popup */
            npplg_av_util_display_mdi_error_popup(result, plugin_data);
        }
        return KAL_FALSE;
    }
    else
    {
        npplg_av_main_set_callback_app_id(NPPLG_AV_OBJ_TYPE_STREAMING, plugin_data->app_id);
        
        /* Disable "Play" control */
        npplg_av_util_disable_play_control(plugin_data, KAL_FALSE);

        /* Show waiting image */
        plugin_data->processing_img_indx = 0;
        npplg_av_util_show_processing_image(plugin_data, KAL_TRUE);
        
        NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_STREAM_OBJ_STATE_CONNECTING);
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_stream_start_buffering
 * DESCRIPTION
 *  This function is used to start buffering.
 * PARAMETERS
 *  result      [IN]        Connect result
 *  info        [IN]        Stream info
 * RETURNS
 *  void
 *****************************************************************************/
static MDI_RESULT npplg_av_stream_start_buffering(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mdi_video_stream_start_buffering(vdo_data->play_time, npplg_av_stream_buffering_result_callback, NULL);

    if (ret == MDI_RES_VDOPLY_SUCCEED)
    {
        npplg_av_main_set_callback_app_id(NPPLG_AV_OBJ_TYPE_STREAMING, plugin_data->app_id);
        
        /* Disable "Play" control */
        npplg_av_util_disable_play_control(plugin_data, KAL_FALSE);

        /* Show waiting image */
        plugin_data->processing_img_indx = 0;
        npplg_av_util_show_processing_image(plugin_data, KAL_TRUE);
        
        NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_STREAM_OBJ_STATE_BUFFERING);

        /* Start timer to check buffer percentage */
        npplg_av_main_start_timer(plugin_data, NPPLG_AV_TIMER_STREAM_BUF_CHECK, NPPLG_AV_STREAM_BUF_CHECK_INTERVAL);
    }
    else
    {
        mdi_video_stream_disconnect();
        mdi_video_stream_deinit();
        npplg_av_stream_switch_to_idle_state(plugin_data);
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_stream_connect_result_callback
 * DESCRIPTION
 *  This function is the callback of mdi_video_stream_connect().
 * PARAMETERS
 *  result      [IN]        Connect result
 *  info        [IN]        Stream info
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_stream_connect_result_callback(MDI_RESULT result, mdi_video_info_struct *info, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_struct *plugin_data;
    npplg_av_video_data_struct *vdo_data;
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_STREAM_CONNECT_RESULT, result);

    NPPLG_AV_LOCK;

    plugin_data = npplg_av_main_get_active_instance(npplg_av_main_get_callback_app_id(NPPLG_AV_OBJ_TYPE_STREAMING));
    
    if (plugin_data != NULL && plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
    {
        if (plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_CONNECTING)
        {
            vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;

            if (result == MDI_RES_VDOPLY_SUCCEED)
            {
                /* Connection is establised */
                if (info->track == MDI_VIDEO_TRACK_A_ONLY)
                {
                    vdo_data->audio_only = KAL_TRUE;
                }
                else
                {
                    vdo_data->audio_only = KAL_FALSE;
                }

                plugin_data->seekable = info->is_seekable;                
                vdo_data->total_time = info->total_time_duration;

                if (plugin_data->seekable == KAL_FALSE)
                {
                    /* If non-seekable, mdi_video_stream_start_buffering() should use 0 as the first parameter */
                    vdo_data->play_time = 0;
                }

                NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_STREAM_OBJ_STATE_CONNECTED);

                ret = mdi_video_stream_start_buffering(vdo_data->play_time, npplg_av_stream_buffering_result_callback, NULL);

                if (ret == MDI_RES_VDOPLY_SUCCEED)
                {
                    npplg_av_main_set_callback_app_id(NPPLG_AV_OBJ_TYPE_STREAMING, plugin_data->app_id);
                    NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_STREAM_OBJ_STATE_BUFFERING);

                    /* Start timer to check buffer percentage */
                    npplg_av_main_start_timer(plugin_data, NPPLG_AV_TIMER_STREAM_BUF_CHECK, NPPLG_AV_STREAM_BUF_CHECK_INTERVAL);

                    NPPLG_AV_UNLOCK;
                    return;
                }
                else
                {
                    mdi_video_stream_disconnect();
                }
            }
            else
            {
                ret = result;
            }

            mdi_video_stream_deinit();
            npplg_av_stream_switch_to_idle_state(plugin_data);
                
            /* Get the error string id from MDI and display error popup */
            npplg_av_util_display_mdi_error_popup(ret, plugin_data);
        }
        else if (result == MDI_RES_VDOPLY_ERR_NETWORK_DISCONNECT)
        {
            /*
             * Server may disconnect connection when streaming is not in connecting state.
             * MDI will call connect_result_callback to tell plug-in that connection is disconnected.
             */
            if ((plugin_data->state != NPPLG_AV_STREAM_OBJ_STATE_IDLE &&
                 plugin_data->state != NPPLG_AV_STREAM_OBJ_STATE_DOWNLOADING &&
                 plugin_data->state != NPPLG_AV_STREAM_OBJ_STATE_WAITING_PLAY &&
                 plugin_data->state != NPPLG_AV_STREAM_OBJ_STATE_LAUNCH_MEDIA_PLAYER &&
                 plugin_data->state != NPPLG_AV_STREAM_OBJ_STATE_RESET_PLAY_PANEL) ||
                (plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_SEEKING &&
                 plugin_data->prev_state != NPPLG_AV_STREAM_OBJ_STATE_IDLE))
            {
                mdi_video_stream_deinit();
                npplg_av_stream_switch_to_idle_state(plugin_data);
                    
                /* Get the error string id from MDI and display error popup */
                npplg_av_util_display_mdi_error_popup(result, plugin_data);
            }
        }
    }

    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_stream_buffering_result_callback
 * DESCRIPTION
 *  This function is the callback of mdi_video_stream_start_buffering().
 * PARAMETERS
 *  result      [IN]        Buffering result
 *  info        [IN]        Stream info
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_stream_buffering_result_callback(MDI_RESULT result, mdi_video_info_struct *info, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_struct *plugin_data;
    npplg_av_video_data_struct *vdo_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_STREAM_BUFFERING_RESULT, result);

    NPPLG_AV_LOCK;

    plugin_data = npplg_av_main_get_active_instance(npplg_av_main_get_callback_app_id(NPPLG_AV_OBJ_TYPE_STREAMING));

    if (plugin_data != NULL && plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
    {
        if (result == MDI_RES_VDOPLY_ONLY_VIDEO_TRACK_ERROR ||
            result == MDI_RES_VDOPLY_ONLY_AUDIO_TRACK_ERROR)
        {
            NPPLG_AV_UNLOCK;
            return;
        }

        npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_STREAM_BUF_CHECK);
        vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;

        vdo_data->vdo_height = info->height;
        vdo_data->vdo_width = info->width;
   
        if (result == MDI_RES_VDOPLY_SUCCEED)
        {
            npplg_av_video_start_to_play(plugin_data);
        }
        else
        {
            mdi_video_stream_disconnect();
            mdi_video_stream_deinit();
            npplg_av_stream_switch_to_idle_state(plugin_data);
            /* Get the error string id from MDI and display error popup */
            npplg_av_util_display_mdi_error_popup(result, plugin_data);
        }
    }

    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_stream_play_result_callback
 * DESCRIPTION
 *  This function is the callback of mdi_video_stream_play().
 * PARAMETERS
 *  result      [IN]        Play result
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_stream_play_result_callback(MDI_RESULT result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_struct *plugin_data;
    npplg_av_video_data_struct *vdo_data;
    npplg_av_obj_control_struct *progress_bar, *time_ctrl;
    MDI_RESULT ret;
    kal_bool display_error = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_STREAM_PLAY_RESULT, result);

    NPPLG_AV_LOCK;

    plugin_data = npplg_av_main_get_active_instance(npplg_av_main_get_callback_app_id(NPPLG_AV_OBJ_TYPE_STREAMING));
    
    if (plugin_data != NULL && plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
    {
        vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
        if (result == MDI_RES_VDOPLY_SUCCEED)
        {
            progress_bar = npplg_av_util_get_control(plugin_data, NPPLG_AV_CTRL_TYPE_PROGRESS_BAR);
            time_ctrl = npplg_av_util_get_control(plugin_data, NPPLG_AV_CTRL_TYPE_TIME); 
                
            if (plugin_data->seekable &&
                vdo_data->total_time > 0 &&
                (progress_bar != NULL || time_ctrl != NULL) &&
                plugin_data->play_panel_state == NPPLG_AV_PLAY_PANEL_STATE_DISPLAY)
            {
                plugin_data->processing = KAL_FALSE;
                npplg_av_main_stop_all_timer(plugin_data);
                
                /* Fill the progress bar completely */
                vdo_data->play_time = vdo_data->total_time;

                if (progress_bar != NULL)
                {
                    npplg_av_util_invalidate_rect(plugin_data, progress_bar);
                }

                if (time_ctrl != NULL)
                {
                    npplg_av_util_invalidate_rect(plugin_data, time_ctrl);
                }

                mdi_video_stream_disconnect();
                mdi_video_stream_deinit();

                npplg_av_video_reset_vdo_data(plugin_data);

                /* Start a timer to redraw the play panel */
                npplg_av_main_start_timer(plugin_data,
                                          NPPLG_AV_TIMER_RESET_PLAY_PANEL,
                                          NPPLG_AV_RESET_PLAY_PANEL_INTERVAL);

                NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_STREAM_OBJ_STATE_RESET_PLAY_PANEL);

                NPPLG_AV_UNLOCK;
                return;
            }
        }
        else if (result == MDI_RES_VDOPLY_ONLY_VIDEO_TRACK_ERROR ||
                 result == MDI_RES_VDOPLY_ONLY_AUDIO_TRACK_ERROR)
        {
            NPPLG_AV_UNLOCK;
            return;
        }
        else if (result < 0)
        {
            display_error = KAL_TRUE;
        }
        else if (result == MDI_RES_VDOPLY_STREAM_BUFFER_UNDERFLOW ||
                 result == MDI_RES_VDOPLY_STREAM_BUFFER_OVERFLOW)
        {
            if (plugin_data->seekable)
            {
                mdi_video_stream_get_cur_play_time(&vdo_data->play_time);
                ret = mdi_video_stream_start_buffering(vdo_data->play_time, npplg_av_stream_buffering_result_callback, NULL);

                if (ret == MDI_RES_VDOPLY_SUCCEED)
                {
                    npplg_av_main_set_callback_app_id(NPPLG_AV_OBJ_TYPE_STREAMING, plugin_data->app_id);
                    npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_HIDE_VIDEO_PLAY_PANEL);
                    npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_UPDATE_PROGRESS_BAR);
                    
                    /* Disable "Play" control */
                    npplg_av_util_disable_play_control(plugin_data, KAL_FALSE);

                    /* Show waiting image */
                    plugin_data->processing_img_indx = 0;
                    npplg_av_util_show_processing_image(plugin_data, KAL_TRUE);
                    
                    NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_STREAM_OBJ_STATE_BUFFERING);

                    /* Start timer to check buffer percentage */
                    npplg_av_main_start_timer(plugin_data, NPPLG_AV_TIMER_STREAM_BUF_CHECK, NPPLG_AV_STREAM_BUF_CHECK_INTERVAL);

                    NPPLG_AV_UNLOCK;
                    return;
                }
            }
            else
            {
                mdi_video_stream_disconnect();
                
                if (vdo_data->is_pdl_or_rtsp)
                {
                    /* RTSP link */
                    kal_wchar *ucs2_link = npplg_av_util_cvt_utf8_to_ucs2(plugin_data->url, plugin_data->app_id);

                    if (ucs2_link == NULL)
                    {
                        mdi_video_stream_deinit();
                        npplg_av_stream_switch_to_idle_state(plugin_data);
                        npplg_av_main_display_popup(plugin_data, STR_GLOBAL_ERROR);

                        NPPLG_AV_UNLOCK;
                        return;
                    }

#ifdef __COSMOS_MMI_PACKAGE__
                    mdi_video_stream_set_scenario(MDI_VIDEO_SCENARIO_QVGA);
#endif
                    ret = mdi_video_stream_connect(npplg_av_main_get_data_account(plugin_data->app_id),
                                                   MDI_VIDEO_STREAM_RTSP_URL,
                                                   (kal_char*)ucs2_link,
                                                   KAL_FALSE,
                                                   NULL,
                                                   0,
                                                   KAL_FALSE,
                                                   0,
                                                   0,
                                                   npplg_av_stream_connect_result_callback,
                                                   NULL);

                    npplg_av_main_free_memory(plugin_data->app_id, ucs2_link);
                }
                else
                {
#ifdef __COSMOS_MMI_PACKAGE__
                    mdi_video_stream_set_scenario(MDI_VIDEO_SCENARIO_QVGA);
#endif
                    ret = mdi_video_stream_connect(npplg_av_main_get_data_account(plugin_data->app_id),
                                                   MDI_VIDEO_STREAM_SDP_FILE,
                                                   (kal_char*)plugin_data->file_path,
                                                   KAL_FALSE,
                                                   NULL,
                                                   0,
                                                   KAL_FALSE,
                                                   0,
                                                   0,
                                                   npplg_av_stream_connect_result_callback,
                                                   NULL);
                }
                
                if (ret < 0)
                {
                    mdi_video_stream_deinit();        
                    npplg_av_stream_switch_to_idle_state(plugin_data);

                    /* Get the error string id from MDI and display error popup */
                    npplg_av_util_display_mdi_error_popup(result, plugin_data);
                }
                else
                {
                    npplg_av_main_set_callback_app_id(NPPLG_AV_OBJ_TYPE_STREAMING, plugin_data->app_id);
                    npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_HIDE_VIDEO_PLAY_PANEL);
                    npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_UPDATE_PROGRESS_BAR);
                    
                    /* Disable "Play" control */
                    npplg_av_util_disable_play_control(plugin_data, KAL_FALSE);

                    /* Show waiting image */
                    plugin_data->processing_img_indx = 0;
                    npplg_av_util_show_processing_image(plugin_data, KAL_TRUE);
                    
                    NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_STREAM_OBJ_STATE_CONNECTING);
                }

                NPPLG_AV_UNLOCK;
                return;
            }
        }
        
        mdi_video_stream_disconnect();
        mdi_video_stream_deinit();
        npplg_av_stream_switch_to_idle_state(plugin_data);

        if (display_error)
        {
            /* Get the error string id from MDI and display error popup */
            npplg_av_util_display_mdi_error_popup(result, plugin_data);
        }
    }

    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_stream_switch_to_idle_state
 * DESCRIPTION
 *  This function is used to switch to idle state.
 *  1. Free video data
 *  2. Set state to idle state
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_stream_switch_to_idle_state(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    npplg_av_video_reset_vdo_data(plugin_data);
    npplg_av_video_set_state_to_idle(plugin_data);
}


/************************************************************
 * Global Function
 ************************************************************/

/*****************************************************************************
 * FUNCTION
 *  npplg_av_stream_handle_event
 * DESCRIPTION
 *  This function is used to handle event.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  event           [IN]        Event
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_stream_handle_event(npplg_av_instance_struct *plugin_data, kal_uint8 event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_RESET_PLAY_PANEL)
    {
        npplg_av_video_reset_vdo_data(plugin_data);
        npplg_av_video_set_state_to_idle(plugin_data);
    }
    
    switch (event)
    {
        case NPPLG_AV_INT_EVT_PLAY:
            npplg_av_stream_handle_play_event(plugin_data);
            break;

        case NPPLG_AV_INT_EVT_PAUSE:
            npplg_av_stream_handle_pause_event(plugin_data);
            break;

        case NPPLG_AV_INT_EVT_STOP:
            npplg_av_stream_handle_stop_event(plugin_data);
            break;

        case NPPLG_AV_INT_EVT_FAST_FORWARD_START:
            npplg_av_stream_handle_seek_event(plugin_data, KAL_TRUE, KAL_TRUE);
            break;

        case NPPLG_AV_INT_EVT_FAST_FORWARD_STOP:
            npplg_av_stream_handle_seek_event(plugin_data, KAL_FALSE, KAL_TRUE);
            break;

        case NPPLG_AV_INT_EVT_REWIND_START:
            npplg_av_stream_handle_seek_event(plugin_data, KAL_TRUE, KAL_FALSE);
            break;

        case NPPLG_AV_INT_EVT_REWIND_STOP:
            npplg_av_stream_handle_seek_event(plugin_data, KAL_FALSE, KAL_FALSE);
            break;

        case NPPLG_AV_INT_EVT_LAUNCH_MEDIA_PLAYER:
            npplg_av_stream_launch_media_player(plugin_data);
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_stream_handle_timer_event
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
kal_int16 npplg_av_stream_handle_timer_event(npplg_av_instance_struct *plugin_data, kal_uint8 timer_type)
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
            case NPPLG_AV_STREAM_OBJ_STATE_BUFFERING:
            {
                /*
                 * There are only two possible timer in this state:
                 * 1. NPPLG_AV_TIMER_UPDATE_PROCESSNG_IMG
                 * 2. NPPLG_AV_TIMER_STREAM_BUF_CHECK
                 * 3. NPPLG_AV_TIMER_UPDATE_PROGRESS_BAR (if click object when play panel is hidden)
                 */
                if (timer_type == NPPLG_AV_TIMER_STREAM_BUF_CHECK)
                {
                    mdi_video_stream_get_buf_percentage(&vdo_data->pdl_buf_percentage);

                    /* Start timer to check buffer percentage */
                    npplg_av_main_start_timer(plugin_data, NPPLG_AV_TIMER_STREAM_BUF_CHECK, NPPLG_AV_STREAM_BUF_CHECK_INTERVAL);
                }
                break;
            }

            case NPPLG_AV_STREAM_OBJ_STATE_PLAYING:
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
                        mdi_video_stream_get_cur_play_time(&vdo_data->play_time);
                        
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

            case NPPLG_AV_STREAM_OBJ_STATE_SEEKING:
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

            case NPPLG_AV_STREAM_OBJ_STATE_RESET_PLAY_PANEL:
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
 *  npplg_av_stream_handle_url_rsp
 * DESCRIPTION
 *  Handle download response
 * PARAMETERS
 *  plugin_data     [IN]        Audio instance data
 *  download_rsp    [IN]        Download response
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_stream_handle_url_rsp(npplg_av_instance_struct *plugin_data, NPReason download_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
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

                if (state == NPPLG_AV_STREAM_OBJ_STATE_DOWNLOADING)
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

                if (state == NPPLG_AV_STREAM_OBJ_STATE_DOWNLOADING)
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
                
                if (!plugin_data->suspend)
                {
                    if (plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_LAUNCH_MEDIA_PLAYER)
                    {
                        npplg_av_video_set_state_to_idle(plugin_data);
                        
                        /*
                         * Launch media player after video data is downloaded
                         * Send primitive to MMI because plug-in may not run in MMI task
                         */
                        npplg_av_util_send_launch_media_player_ind(plugin_data,
                                                                   kal_get_active_module_id(),
                                                                   NPPLG_AV_PLAYER_TYPE_STREAM,
                                                                   KAL_FALSE);
                    }
                    else if (plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_DOWNLOADING)
                    {
                        npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_UPDATE_PROCESSNG_IMG);
                        npplg_av_stream_waiting_play(plugin_data);
                    }
                }
                else
                {
                    if (plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_LAUNCH_MEDIA_PLAYER)
                    {
                        npplg_av_video_set_state_to_idle(plugin_data);
                    }
                }
            }
            break;
        }

        case NPRES_NETWORK_ERR:
        {
            if (plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_DOWNLOADING)
            {
                if (!plugin_data->suspend
#ifdef __GADGET_SUPPORT__
                    || plugin_data->app_id == NPPLG_AV_APP_ID_GOOGLE_GADGET
#endif
                   )
                {
                    display_error = KAL_TRUE;
                }
            }
            /* Continue the following action */
        }

        case NPRES_USER_BREAK:
        {
            if (plugin_data->file_handle > 0)
            {
                FS_Close(plugin_data->file_handle);
                plugin_data->file_handle = 0;
                FS_Delete(plugin_data->file_path);
            }
            NPPLG_AV_MEM_FREE(plugin_data->app_id, plugin_data->file_path);
            plugin_data->dl_state = NPPLG_AV_OBJ_DL_STATE_NULL;
            npplg_av_video_set_state_to_idle(plugin_data);

            if (display_error)
            {
                /*
                 * Plug-in display error popup because user starts to play the audio.
                 * Plug-in should not let browser display error popup if browser is in the background.
                 */
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
 *  npplg_av_stream_play
 * DESCRIPTION
 *  Play the video streaming
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_stream_play(npplg_av_instance_struct *plugin_data)
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
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_PLAY_STREAM, plugin_data->instance_id, plugin_data->state);

    mdi_video_stream_enable_partial_display();

    /* Process video layer */
    lcm_update = npplg_av_video_process_vdo_layer(plugin_data);
    if (vdo_data->lcm_update == KAL_FALSE)
    {
        lcm_update = KAL_FALSE;
    }

    lcm_update = npplg_av_main_decide_video_visual_update(plugin_data->app_id, lcm_update);

    mdi_video_stream_set_brightness(MDI_VIDEO_BRIGHTNESS_0);
    mdi_video_stream_set_contrast(MDI_VIDEO_CONTRAST_0);
    
    /* Play the video streaming */
#if defined(__GADGET_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)
    if (plugin_data->app_id == NPPLG_AV_APP_ID_GOOGLE_GADGET)
    {
        result = mdi_video_stream_play(vdo_data->vdo_layer_handle,
                                       g_npplg_av_context.blt_layer_flag,
                                       g_npplg_av_context.hw_layer_flag,
                                       lcm_update,
                                       MDI_DEVICE_SPEAKER2,
                                       g_npplg_av_context.app_cnxt[plugin_data->app_id].rotate,
                                       npplg_av_stream_play_result_callback,
                                       NULL);
    }
    else
#endif /* defined(__GADGET_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__) */
    result = mdi_video_stream_play(vdo_data->vdo_layer_handle,
                                   NPPLG_AV_BLT_LAYER_FLAG,
                                   NPPLG_AV_VDO_PLAY_LAYER_FLAG,
                                   lcm_update,
                                   MDI_DEVICE_SPEAKER2,
                                   g_npplg_av_context.app_cnxt[plugin_data->app_id].rotate,
                                   npplg_av_stream_play_result_callback,
                                   NULL);

    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_STREAM_PLAY_RESULT, result);

    if (result == MDI_RES_VDOPLY_SUCCEED)
    {
        npplg_av_main_set_callback_app_id(NPPLG_AV_OBJ_TYPE_STREAMING, plugin_data->app_id);
        NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_STREAM_OBJ_STATE_PLAYING);

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
        mdi_video_stream_disconnect();
        mdi_video_stream_deinit();
        npplg_av_stream_switch_to_idle_state(plugin_data);

        /* Get the error string id from MDI and display error popup */
        npplg_av_util_display_mdi_error_popup(result, plugin_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_stream_update_layer_pause
 * DESCRIPTION
 *  This function is used to pause video before plug-in update video layer.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  Indicate whether plug-in should resume playing later
 *****************************************************************************/
kal_bool npplg_av_stream_update_layer_pause(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool seek_play = KAL_FALSE;
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_PLAYING)
    {
        if (vdo_data->audio_only == KAL_FALSE)
        {
#if defined(__GADGET_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)
            if (plugin_data->app_id != NPPLG_AV_APP_ID_GOOGLE_GADGET)
#endif
            /* Should suspend video playing before update video layer */
            mdi_video_stream_pause();
        }

        /* Change "Play" control to "Pause" control or "Stop" control */
        npplg_av_util_update_play_control(plugin_data, KAL_TRUE, KAL_FALSE);
    }
    else if (plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_DOWNLOADING ||
             plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_CONNECTING ||
             plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_BUFFERING ||
             plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_LAUNCH_MEDIA_PLAYER)
    {
        /* Disable "Play" control */
        npplg_av_util_disable_play_control(plugin_data, KAL_FALSE);
    }
    else if (plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_PAUSED_PLAY)
    {
        /* Change "Play" control to "Pause" control or "Stop" control */
        npplg_av_util_update_play_control(plugin_data, KAL_TRUE, KAL_FALSE);
    }

    /* If window is resized in seeking state, stop seeking */
    if (plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_SEEKING)
    {
        if (plugin_data->prev_state == NPPLG_AV_STREAM_OBJ_STATE_PLAYING ||
            plugin_data->prev_state == NPPLG_AV_STREAM_OBJ_STATE_BUFFERING)
        {
            /* Should enter buffering state later */
            seek_play = KAL_TRUE;
        }
        else
        {
            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, plugin_data->prev_state);
        }
        npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_SEEK_REPEAT);
        plugin_data->seek_repeat_num = 0;
        plugin_data->prev_state = NPPLG_AV_STREAM_OBJ_STATE_IDLE;
    }

    return seek_play;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_stream_update_layer_resume
 * DESCRIPTION
 *  This function is used to resume video after plug-in update video layer.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_stream_update_layer_resume(npplg_av_instance_struct *plugin_data, kal_bool seek_play, kal_bool lcm_update)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_PLAYING)
    {
        if (vdo_data->audio_only == KAL_FALSE)
        {
#if defined(__GADGET_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)
            if (plugin_data->app_id != NPPLG_AV_APP_ID_GOOGLE_GADGET)
#endif
            mdi_video_stream_resume(vdo_data->vdo_layer_handle,
                                    NPPLG_AV_BLT_LAYER_FLAG,
                                    NPPLG_AV_VDO_PLAY_LAYER_FLAG,
                                    lcm_update,
                                    MDI_DEVICE_SPEAKER2,
                                    g_npplg_av_context.app_cnxt[plugin_data->app_id].rotate);
        }
    }
    else if (seek_play && plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_SEEKING)
    {
        npplg_av_stream_start_buffering(plugin_data);
    }
    else if (plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_BUFFERING ||
             plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_CONNECTING ||
             plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_DOWNLOADING ||
             plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_LAUNCH_MEDIA_PLAYER)
    {
        /* Redraw processing image */
        npplg_av_util_show_processing_image(plugin_data, KAL_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_stream_suspend_by_app
 * DESCRIPTION
 *  This function is used to suspend video streaming.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_stream_suspend_by_app(npplg_av_instance_struct *plugin_data)
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
        case NPPLG_AV_STREAM_OBJ_STATE_INITED:
        {
            mdi_video_stream_deinit();

#ifdef __COSMOS_MMI_PACKAGE__
            npplg_av_video_unprepare_vdo_layer(plugin_data);
#endif /* __COSMOS_MMI_PACKAGE__ */

            NPPLG_AV_UNLOCK;
            return;
        }
        
        case NPPLG_AV_STREAM_OBJ_STATE_CONNECTING:
        case NPPLG_AV_STREAM_OBJ_STATE_CONNECTED:
            break;

#ifdef __COSMOS_MMI_PACKAGE__
        case NPPLG_AV_STREAM_OBJ_STATE_CREATE_VDO_LAYER:
        {
            vapp_npplg_av_video_free_vdo_layer(plugin_data->app_id, plugin_data->instance_id);

            /* Continue the following action */
        }
#endif

        case NPPLG_AV_STREAM_OBJ_STATE_BUFFERING:
        {
            mdi_video_stream_stop_buffering();
            break;
        }
        
        case NPPLG_AV_STREAM_OBJ_STATE_PLAYING:
        {
            mdi_video_stream_stop();
            mdi_video_stream_get_cur_play_time(&vdo_data->play_time);
            break;
        }

        case NPPLG_AV_STREAM_OBJ_STATE_SEEKING:
        {
            plugin_data->seek_repeat_num = 0;
            if (plugin_data->prev_state == NPPLG_AV_STREAM_OBJ_STATE_IDLE)
            {
#ifdef __COSMOS_MMI_PACKAGE__
                npplg_av_video_unprepare_vdo_layer(plugin_data);
#endif /* __COSMOS_MMI_PACKAGE__ */

                NPPLG_AV_UNLOCK;
                return;
            }
            
            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, plugin_data->prev_state);
            plugin_data->prev_state = NPPLG_AV_STREAM_OBJ_STATE_IDLE;
            break;
        }

        case NPPLG_AV_STREAM_OBJ_STATE_PAUSED_PLAY:
        {
            if (plugin_data->seekable == KAL_FALSE)
            {
                mdi_video_stream_deinit();

#ifdef __COSMOS_MMI_PACKAGE__
                npplg_av_video_unprepare_vdo_layer(plugin_data);
#endif /* __COSMOS_MMI_PACKAGE__ */

                NPPLG_AV_UNLOCK;
                return;
            }
            break;
        }
        
        default:
        {
            /* IDLE, DOWNLOADING, LAUNCH_MEDIA_PLAYER, RESET_PLAY_PANEL, WAITING_PLAY */

#ifdef __COSMOS_MMI_PACKAGE__
            npplg_av_video_unprepare_vdo_layer(plugin_data);
#endif /* __COSMOS_MMI_PACKAGE__ */

            NPPLG_AV_UNLOCK;
            return;
        }
    }

    mdi_video_stream_disconnect();
    mdi_video_stream_deinit();

#ifdef __COSMOS_MMI_PACKAGE__
    npplg_av_video_unprepare_vdo_layer(plugin_data);
#endif /* __COSMOS_MMI_PACKAGE__ */

    npplg_av_main_switch_backlight(KAL_FALSE);
    
    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_stream_resume_by_app
 * DESCRIPTION
 *  This function is used to resume video streaming.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_stream_resume_by_app(npplg_av_instance_struct *plugin_data)
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
            case NPPLG_AV_STREAM_OBJ_STATE_IDLE:
            case NPPLG_AV_STREAM_OBJ_STATE_SEEKING:
                break;
            
            default:
            {
                /*
                 * NPPLG_AV_STREAM_OBJ_STATE_DOWNLOADING
                 * NPPLG_AV_STREAM_OBJ_STATE_WAITING_PLAY
                 * NPPLG_AV_STREAM_OBJ_STATE_INITED
                 * NPPLG_AV_STREAM_OBJ_STATE_CONNECTING
                 * NPPLG_AV_STREAM_OBJ_STATE_CONNECTED
                 * NPPLG_AV_STREAM_OBJ_STATE_BUFFERING
                 * NPPLG_AV_STREAM_OBJ_STATE_PLAYING
                 * NPPLG_AV_STREAM_OBJ_STATE_LAUNCH_MEDIA_PLAYER
                 * NPPLG_AV_STREAM_OBJ_STATE_RESET_PLAY_PANEL
                 * NPPLG_AV_STREAM_OBJ_STATE_PAUSED_PLAY
                 * NPPLG_AV_STREAM_OBJ_STATE_CREATE_VDO_LAYER
                 */
                NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_STREAM_OBJ_STATE_RESET_PLAY_PANEL);
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
            case NPPLG_AV_STREAM_OBJ_STATE_DOWNLOADING:
            case NPPLG_AV_STREAM_OBJ_STATE_LAUNCH_MEDIA_PLAYER:
            case NPPLG_AV_STREAM_OBJ_STATE_RESET_PLAY_PANEL:
            {
                npplg_av_util_send_mmi_resume_ind(npplg_av_main_get_app_mod_id(plugin_data->app_id),
                                                  plugin_data->instance_id,
                                                  plugin_data->app_id,
                                                  plugin_data->state);
                break;
            }

            case NPPLG_AV_STREAM_OBJ_STATE_WAITING_PLAY:
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

            case NPPLG_AV_STREAM_OBJ_STATE_INITED:
            case NPPLG_AV_STREAM_OBJ_STATE_CONNECTED:
            {
                npplg_av_main_switch_backlight(KAL_TRUE);
                
                if (mdi_video_stream_init(g_npplg_av_context.app_cnxt[plugin_data->app_id].mem_app_id) < 0)
                {
                    NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_STREAM_OBJ_STATE_RESET_PLAY_PANEL);
                    npplg_av_util_send_mmi_resume_ind(npplg_av_main_get_app_mod_id(plugin_data->app_id),
                                                      plugin_data->instance_id,
                                                      plugin_data->app_id,
                                                      plugin_data->state);

                    npplg_av_main_switch_backlight(KAL_FALSE);
                }
                else
                {
                    if (plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_CONNECTED)
                    {
                        NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_STREAM_OBJ_STATE_INITED);
                    }
                }
                break;
            }
            
            case NPPLG_AV_STREAM_OBJ_STATE_CONNECTING:
            case NPPLG_AV_STREAM_OBJ_STATE_BUFFERING:
            case NPPLG_AV_STREAM_OBJ_STATE_PLAYING:
            case NPPLG_AV_STREAM_OBJ_STATE_PAUSED_PLAY:
#ifdef __COSMOS_MMI_PACKAGE__
            case NPPLG_AV_STREAM_OBJ_STATE_CREATE_VDO_LAYER:
#endif
            {
                npplg_av_main_switch_backlight(KAL_TRUE);
                
                if (mdi_video_stream_init(g_npplg_av_context.app_cnxt[plugin_data->app_id].mem_app_id) < 0)
                {
                    NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_STREAM_OBJ_STATE_RESET_PLAY_PANEL);
                    npplg_av_util_send_mmi_resume_ind(npplg_av_main_get_app_mod_id(plugin_data->app_id),
                                                      plugin_data->instance_id,
                                                      plugin_data->app_id,
                                                      plugin_data->state);

                    npplg_av_main_switch_backlight(KAL_FALSE);
                }
                else
                {
                    NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_STREAM_OBJ_STATE_INITED_PLAY);
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
 *  npplg_av_stream_close_by_app
 * DESCRIPTION
 *  This function is used to close video streaming.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_stream_close_by_app(npplg_av_instance_struct *plugin_data)
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

    if (plugin_data->state != NPPLG_AV_STREAM_OBJ_STATE_IDLE)
    {
        NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_STREAM_OBJ_STATE_RESET_PLAY_PANEL);
    }
    
    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_stream_visual_update
 * DESCRIPTION
 *  This function is used to enable/disable video visual update.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  lcm_update      [IN]        Enable/disable video visual update
 *  clear_vdo_layer [IN]        Clear video layer or not
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_stream_visual_update(npplg_av_instance_struct *plugin_data, kal_bool lcm_update, kal_bool clear_vdo_layer)
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

    if (plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_PLAYING)
    {
        if (vdo_data->audio_only == KAL_FALSE)
        {
            /* Should suspend video playing before update video layer */
            mdi_video_stream_pause();
        }
    }

    if (vdo_data->vdo_layer_handle != GDI_NULL_HANDLE && clear_vdo_layer == KAL_TRUE)
    {
        gdi_layer_push_and_set_active(vdo_data->vdo_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }

    if (plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_PLAYING)
    {
        if (vdo_data->audio_only == KAL_FALSE)
        {
#if defined(__GADGET_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)
            if (plugin_data->app_id == NPPLG_AV_APP_ID_GOOGLE_GADGET)
            {
                mdi_video_stream_resume(vdo_data->vdo_layer_handle,
                                        g_npplg_av_context.blt_layer_flag,
                                        g_npplg_av_context.hw_layer_flag,
                                        visual_update,
                                        MDI_DEVICE_SPEAKER2,
                                        g_npplg_av_context.app_cnxt[plugin_data->app_id].rotate);
            }
            else
#endif /* defined(__GADGET_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__) */
            mdi_video_stream_resume(vdo_data->vdo_layer_handle,
                                    NPPLG_AV_BLT_LAYER_FLAG,
                                    NPPLG_AV_VDO_PLAY_LAYER_FLAG,
                                    visual_update,
                                    MDI_DEVICE_SPEAKER2,
                                    g_npplg_av_context.app_cnxt[plugin_data->app_id].rotate);
        }
    }
    
    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_stream_stop_by_app_for_screen_rotate
 * DESCRIPTION
 *  This function is used to stop video streaming due to screen rotate.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_stream_stop_by_app_for_screen_rotate(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NPPLG_AV_LOCK;

    if (plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_PLAYING)
    {
        npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_UPDATE_PROGRESS_BAR);
        npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_HIDE_VIDEO_PLAY_PANEL);
        mdi_video_stream_stop();
        mdi_video_stream_get_cur_play_time(&vdo_data->play_time);

        /* Change "Pause" control or "Stop" control to "Play" control */
        npplg_av_util_update_play_control(plugin_data, KAL_FALSE, KAL_FALSE);

        if (!plugin_data->seekable)
        {
            mdi_video_stream_disconnect();
        }

        NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_STREAM_OBJ_STATE_PAUSED_PLAY);
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
 *  npplg_av_stream_handle_suspend_background_play_rsp
 * DESCRIPTION
 *  Handle MSG_ID_NPPLG_AV_SUSPEND_BACKGROUND_PLAY_RSP
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  result          [IN]        Result
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_stream_handle_suspend_background_play_rsp(npplg_av_instance_struct *plugin_data,
                                                        kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_WAITING_PLAY)
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
            if (npplg_av_stream_init_and_connect(plugin_data, KAL_TRUE) == KAL_FALSE)
            {
                /* Fail to init or connect */
                npplg_av_stream_switch_to_idle_state(plugin_data);
            }
        }
        else
        {
            npplg_av_stream_switch_to_idle_state(plugin_data);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_stream_mmi_resume_ind_handler
 * DESCRIPTION
 *  This function is used to handle MMI resume indication in engine task.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_stream_mmi_resume_ind_handler(npplg_av_instance_struct *plugin_data)
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
        case NPPLG_AV_STREAM_OBJ_STATE_DOWNLOADING:
        {
            if (plugin_data->dl_state == NPPLG_AV_OBJ_DL_STATE_DOWNLOAD_OK)
            {
                npplg_av_stream_waiting_play(plugin_data);
            }
            else if (plugin_data->dl_state == NPPLG_AV_OBJ_DL_STATE_DOWNLOADING)
            {
                /*
                 * If .sdp is still downloading, start a timer to show processing image
                 * Does not need reset plugin_data->processing_img_indx as 0
                 */
                npplg_av_main_start_timer(plugin_data,
                                          NPPLG_AV_TIMER_UPDATE_PROCESSNG_IMG,
                                          NPPLG_AV_UPDATE_PROCESSING_IMG_DELAY);
            }
            else
            {
                ASSERT(0);
            }
            break;
        }

        case NPPLG_AV_STREAM_OBJ_STATE_INITED_PLAY:
        {
            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_STREAM_OBJ_STATE_INITED);
    
            if (npplg_av_stream_connect(plugin_data, KAL_TRUE) == KAL_FALSE)
            {
                npplg_av_stream_switch_to_idle_state(plugin_data);
            }
            break;
        }

        case NPPLG_AV_STREAM_OBJ_STATE_LAUNCH_MEDIA_PLAYER:
        {
            /*
             * 1. Still downloading video
             * 2. Start a timer to show processing image
             * 3. Does not need reset plugin_data->processing_img_indx as 0
             */
            npplg_av_util_show_processing_image(plugin_data, KAL_TRUE);
            break;
        }
        
        case NPPLG_AV_STREAM_OBJ_STATE_RESET_PLAY_PANEL:
        {
            npplg_av_stream_switch_to_idle_state(plugin_data);
            
            if (plugin_data->error == NPPLG_AV_ERROR_NETWORK)
            {
                plugin_data->error = NPPLG_AV_ERROR_NULL;
                npplg_av_main_display_popup(plugin_data, STR_ID_NPPLG_NETWORK_ERROR);
            }
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
 *  npplg_av_stream_prepare_vdo_layer
 * DESCRIPTION
 *  This function is used to prepare video layer before playing.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_stream_prepare_vdo_layer(npplg_av_instance_struct *plugin_data)
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
            mdi_video_stream_stop_buffering();
            mdi_video_stream_disconnect();
            mdi_video_stream_deinit();
            npplg_av_stream_switch_to_idle_state(plugin_data);
            npplg_av_main_display_popup(plugin_data, STR_ID_NPPLG_FAIL_TO_PLAY);
        }
        else if (plugin_data == npplg_av_main_get_active_instance(plugin_data->app_id))
        {
            plugin_data->suspend = KAL_FALSE;
            npplg_av_stream_close_by_app(plugin_data);
            npplg_av_stream_handle_event(plugin_data, NPPLG_AV_INT_EVT_STOP);
        }
    }
    else
    {
        NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_STREAM_OBJ_STATE_CREATE_VDO_LAYER);
        npplg_av_util_send_create_vdo_layer_req(kal_get_active_module_id(),
                                                plugin_data->instance_id,
                                                plugin_data->app_id,
                                                &vdo_area,
                                                npplg_av_main_get_transparent_color(plugin_data->app_id));
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_stream_create_vdo_layer_rsp_handler
 * DESCRIPTION
 *  This function is used to handle MMI video layer response in engine task.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  vdo_layer       [IN]        Video layer handle
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_stream_create_vdo_layer_rsp_handler(npplg_av_instance_struct *plugin_data, gdi_handle vdo_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_CREATE_VDO_LAYER ||
        plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_CONNECTED)
    {
        if (vdo_layer == GDI_NULL_HANDLE)
        {
            if (g_npplg_av_context.app_cnxt[plugin_data->app_id].is_suspend_by_mmi == KAL_FALSE)
            {
                if (plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_CREATE_VDO_LAYER)
                {
                    mdi_video_stream_stop_buffering();
                }

                mdi_video_stream_disconnect();
                mdi_video_stream_deinit();
                npplg_av_stream_switch_to_idle_state(plugin_data);

                if (plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_CREATE_VDO_LAYER)
                {
                    npplg_av_main_display_popup(plugin_data, STR_ID_NPPLG_FAIL_TO_PLAY);
                }
            }
            else if (plugin_data == npplg_av_main_get_active_instance(plugin_data->app_id))
            {
                plugin_data->suspend = KAL_FALSE;
                npplg_av_stream_close_by_app(plugin_data);
                npplg_av_stream_handle_event(plugin_data, NPPLG_AV_INT_EVT_STOP);
            }
        }
        else if (g_npplg_av_context.app_cnxt[plugin_data->app_id].is_suspend_by_mmi == KAL_FALSE)
        {
            g_npplg_av_context.app_cnxt[plugin_data->app_id].vdo_layer_handle = vdo_layer;
            vdo_data->vdo_layer_handle = vdo_layer;

            if (plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_CREATE_VDO_LAYER)
            {
                plugin_data->processing = KAL_FALSE;
                npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_UPDATE_PROCESSNG_IMG);

                /* Clear the video area */
                npplg_av_util_invalidate_rect(plugin_data, NULL);

                npplg_av_stream_play(plugin_data);
            }
        }
    }
    else
    {
        ASSERT(0);
    }
}
#endif /* __COSMOS_MMI_PACKAGE__ */

#endif /* defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__MMI_VIDEO_STREAM__) */
#endif /* defined(OPERA_V10_BROWSER) || defined(__GADGET_SUPPORT__) */
