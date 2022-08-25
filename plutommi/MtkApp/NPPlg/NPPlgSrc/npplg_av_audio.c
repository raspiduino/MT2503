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
 *   npplg_av_audio.c
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   Implement audio plug-in instance
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(OPERA_V10_BROWSER) || defined(__GADGET_SUPPORT__)

/************************************************************
 * Include
 ************************************************************/
#include "stack_config.h"

/* MDI header file */
#include "mdi_audio.h"

/* Media header file */
#include "med_api.h"
#include "med_main.h"

/* A/V Plug-in header file */
#include "npplg_av_include.h"
#include "npplg_av_main.h"
#include "npplg_av_audio.h"
#include "npplg_av_util.h"
#include "npplg_av_custom_config.h"
#include "mmi_rp_app_npplg_def.h"
#include "npplg_struct.h"

#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "mmi_media_app_trc.h"
#include "kal_trace.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "kal_public_api.h"
#include "fs_func.h"
#include "GlobalResDef.h"
#include "app_ltlcom.h"
#include "stack_msgs.h"
#include "aud_main.h"
#include "kal_active_module.h"


/************************************************************
 * Static Declaration
 ************************************************************/
static void npplg_av_audio_start_build_cache(npplg_av_instance_struct *plugin_data);
static void npplg_av_audio_build_cache_process(npplg_av_instance_struct *plugin_data);
static void npplg_av_audio_stop_build_cache(npplg_av_instance_struct *plugin_data);
static void npplg_av_audio_redraw_and_play(npplg_av_instance_struct *plugin_data);
static void npplg_av_audio_waiting_play(npplg_av_instance_struct *plugin_data);
static void npplg_av_audio_play(npplg_av_instance_struct *plugin_data);
static void npplg_av_audio_handle_play_event(npplg_av_instance_struct *plugin_data);
#ifdef __COSMOS_MMI_PACKAGE__
static void npplg_av_audio_handle_auto_play_event(npplg_av_instance_struct *plugin_data);
#endif
static void npplg_av_audio_handle_pause_event(npplg_av_instance_struct *plugin_data);
static void npplg_av_audio_handle_stop_event(npplg_av_instance_struct *plugin_data);
static void npplg_av_audio_handle_seek_event(npplg_av_instance_struct *plugin_data, kal_bool start, kal_bool forward);
static void npplg_av_audio_set_state_to_idle(npplg_av_instance_struct *plugin_data);
static void npplg_av_audio_decide_layout(npplg_av_instance_struct *plugin_data);
static void npplg_av_audio_show_processing_image(npplg_av_instance_struct *plugin_data);


/************************************************************
 * Global Variable
 ************************************************************/


/************************************************************
 * Local Function
 ************************************************************/

/*****************************************************************************
 * FUNCTION
 *  npplg_av_audio_start_build_cache
 * DESCRIPTION
 *  Start to build audio cache
 * PARAMETERS
 *  plugin_data     [IN]        Plugin instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_audio_start_build_cache(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_audio_data_struct *aud_data = (npplg_av_audio_data_struct*)plugin_data->obj_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_BUILD_CACHE, plugin_data->instance_id);

#ifndef __MTK_TARGET__

    /* Build cache APIs do not work on MoDIS */
    aud_data->cache_status = NPPLG_AV_AUDIO_CACHE_STATUS_BUILT_OK;
    plugin_data->seekable = KAL_TRUE;

#ifndef MED_NOT_PRESENT

    /* Check if audio file is seekable */
    plugin_data->seekable = media_aud_check_is_file_seekable(kal_get_active_module_id(), plugin_data->file_path);

#endif /* MED_NOT_PRESENT */

    /* Redraw the window and play the audio */
    npplg_av_audio_redraw_and_play(plugin_data);

#else /* __MTK_TARGET__ */

#if defined(MED_NOT_PRESENT) || !defined(__RICH_AUDIO_PROFILE__)

    /* Can not build cache by aud_util function */
    aud_data->cache_status = NPPLG_AV_AUDIO_CACHE_STATUS_BUILT_FAIL;
    plugin_data->seekable = KAL_FALSE;
    npplg_av_audio_redraw_and_play(plugin_data);

#else /* defined(MED_NOT_PRESENT) || !defined(__RICH_AUDIO_PROFILE__) */

    aud_data->build_cache_progress = 0;

    /* Check if audio file is seekable */
    plugin_data->seekable = media_aud_check_is_file_seekable(kal_get_active_module_id(), plugin_data->file_path);

    /* Check if need to build cache */
    if (mdi_audio_is_duration_need_build_cache(plugin_data->file_path) == MMI_TRUE)
    {
        if (plugin_data->seekable)
        {
            /* Need to build cache */
            if (aud_data->cache_file_buf == NULL)
            {
                aud_data->cache_file_buf = (kal_uint8*)g_npplg_av_netscape_funcs[plugin_data->app_id].memalloc(sizeof(kal_uint8) * NPPLG_AV_AUDIO_BUILD_CACHE_FILE_BUF_SIZE);
                if (aud_data->cache_file_buf == NULL)
                {
                    aud_data->cache_status = NPPLG_AV_AUDIO_CACHE_STATUS_BUILT_FAIL;
                    plugin_data->seekable = KAL_FALSE;

                    if (aud_data->cache_proc_buf != NULL)
                    {
                        NPPLG_AV_MEM_FREE(plugin_data->app_id, aud_data->cache_proc_buf);
                    }
                    
                    npplg_av_audio_redraw_and_play(plugin_data);
                    return;
                }
            }

            if (aud_data->cache_proc_buf == NULL)
            {
                aud_data->cache_proc_buf = (kal_uint8*)g_npplg_av_netscape_funcs[plugin_data->app_id].memalloc(sizeof(kal_uint8) * NPPLG_AV_AUDIO_BUILD_CACHE_PROC_BUF_SIZE);
                if (aud_data->cache_file_buf == NULL)
                {
                    NPPLG_AV_MEM_FREE(plugin_data->app_id, aud_data->cache_file_buf);
                    aud_data->cache_status = NPPLG_AV_AUDIO_CACHE_STATUS_BUILT_FAIL;
                    plugin_data->seekable = KAL_FALSE;
                    npplg_av_audio_redraw_and_play(plugin_data);
                    return;
                }
            }
            
            if (aud_util_build_cache_start(plugin_data->file_path,
                                           aud_data->cache,
                                           NPPLG_AV_AUDIO_BUILD_CACHE_SIZE,
                                           aud_data->cache_file_buf,
                                           NPPLG_AV_AUDIO_BUILD_CACHE_FILE_BUF_SIZE,
                                           aud_data->cache_proc_buf,
                                           NPPLG_AV_AUDIO_BUILD_CACHE_PROC_BUF_SIZE))
            {
                /* Start a timer to query if the cache progress reaches 100 */
                if (npplg_av_main_start_timer(plugin_data,
                                              NPPLG_AV_TIMER_AUDIO_BUILD_CACHE_CHECK,
                                              NPPLG_AV_AUDIO_BUILD_CACHE_CHECK_INTERVAL) == KAL_FALSE)
                {
                    /* Can not start a timer -> play the audio directly and disable seek function */
                    npplg_av_audio_stop_build_cache(plugin_data);
                    aud_data->cache_status = NPPLG_AV_AUDIO_CACHE_STATUS_BUILT_FAIL;
                    plugin_data->seekable = KAL_FALSE;
                    npplg_av_audio_redraw_and_play(plugin_data);
                    return;
                }
                
                aud_data->cache_status = NPPLG_AV_AUDIO_CACHE_STATUS_BUILDING;
                NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_AUDIO_OBJ_STATE_BUILDING_CACHE);
            }
            else
            {
                /* Fail to start building cache */
                NPPLG_AV_MEM_FREE(plugin_data->app_id, aud_data->cache_file_buf);
                NPPLG_AV_MEM_FREE(plugin_data->app_id, aud_data->cache_proc_buf);
                aud_data->cache_status = NPPLG_AV_AUDIO_CACHE_STATUS_BUILT_FAIL;
                plugin_data->seekable = KAL_FALSE;
                npplg_av_audio_redraw_and_play(plugin_data);
            }
        }
        else
        {
            aud_data->cache_status = NPPLG_AV_AUDIO_CACHE_STATUS_BUILT_FAIL;
            npplg_av_audio_redraw_and_play(plugin_data);
        }
    }
    else
    {
        /* Not need to build cache */
        aud_data->cache_status = NPPLG_AV_AUDIO_CACHE_STATUS_BUILT_OK;

        /* Redraw the window and play the audio */
        npplg_av_audio_redraw_and_play(plugin_data);
    }

#endif /* defined(MED_NOT_PRESENT) || !defined(__RICH_AUDIO_PROFILE__) */
#endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_audio_build_cache_process
 * DESCRIPTION
 *  Continue building cache
 * PARAMETERS
 *  plugin_data     [IN]    Plugin
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_audio_build_cache_process(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_audio_data_struct *aud_data = (npplg_av_audio_data_struct*)plugin_data->obj_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if((aud_data->build_cache_progress == 100) ||
       aud_util_build_cache_process(&(aud_data->build_cache_progress)))
    {
        if(aud_data->build_cache_progress == 100)
        {
            /* Finish building cache -> Free memory and play audio */
            aud_data->total_time = aud_util_build_cache_get_duration();
            npplg_av_audio_stop_build_cache(plugin_data);
            aud_data->cache_status = NPPLG_AV_AUDIO_CACHE_STATUS_BUILT_OK;
            plugin_data->seekable = KAL_TRUE;
            npplg_av_audio_redraw_and_play(plugin_data);
            return;
        }
        else if (npplg_av_main_start_timer(plugin_data,
                                           NPPLG_AV_TIMER_AUDIO_BUILD_CACHE_CHECK,
                                           NPPLG_AV_AUDIO_BUILD_CACHE_CHECK_INTERVAL) == KAL_TRUE)
        {
            /* Continue building cache */
            return;
        }
    }

    /* Fail to build cache */
    npplg_av_audio_stop_build_cache(plugin_data);
    aud_data->cache_status = NPPLG_AV_AUDIO_CACHE_STATUS_BUILT_FAIL;
    plugin_data->seekable = KAL_FALSE;
    npplg_av_audio_redraw_and_play(plugin_data);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_audio_stop_build_cache
 * DESCRIPTION
 *  Stop build cache
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_audio_stop_build_cache(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_audio_data_struct *aud_data = (npplg_av_audio_data_struct*)plugin_data->obj_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_util_build_cache_stop();

    if (kal_get_active_module_id() != MOD_MMI)
    {
        /* Free memory */
        NPPLG_AV_MEM_FREE(plugin_data->app_id, aud_data->cache_file_buf);
        NPPLG_AV_MEM_FREE(plugin_data->app_id, aud_data->cache_proc_buf);
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_audio_redraw_and_play
 * DESCRIPTION
 *  Decide layout, redraw the window and play the audio
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_audio_redraw_and_play(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    plugin_data->processing = KAL_FALSE;
    npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_UPDATE_PROCESSNG_IMG);

    plugin_data->play_panel_state = NPPLG_AV_PLAY_PANEL_STATE_DISPLAY;
    npplg_av_audio_decide_layout(plugin_data);
    npplg_av_util_disable_play_control(plugin_data, KAL_FALSE);
    npplg_av_util_invalidate_rect(plugin_data, NULL);
    npplg_av_audio_waiting_play(plugin_data);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_audio_waiting_play
 * DESCRIPTION
 *  Waiting for audio resource
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_audio_waiting_play(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 action;
#ifdef __COSMOS_MMI_PACKAGE__
    npplg_av_audio_data_struct *aud_data = (npplg_av_audio_data_struct*)plugin_data->obj_data;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Change state */
    NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_AUDIO_OBJ_STATE_WAITING_PLAY);

    switch (g_npplg_av_context.res_status)
    {
        case NPPLG_AV_RES_STATUS_NULL:
        {
            ASSERT(kal_get_active_module_id() != MOD_MMI);

#ifdef __COSMOS_MMI_PACKAGE__
            npplg_av_main_suspend_background_play(plugin_data->app_id, aud_data->suspend_bgplay);
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
            action = NPPLG_AV_ACTION_SET_VOLUME | NPPLG_AV_ACTION_TURN_OFF_BACKLIGHT | NPPLG_AV_ACTION_OPEN_AUDIO | NPPLG_AV_ACTION_SEND_PLAY_IND;
#ifdef __COSMOS_MMI_PACKAGE__
            if (!aud_data->suspend_bgplay)
            {
                action = action | NPPLG_AV_ACTION_TERMINATE_BGPLAY;
            }
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
 *  npplg_av_audio_play
 * DESCRIPTION
 *  Start to play audio
 * PARAMETERS
 *  plugin_data     [IN]        Plugin instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_audio_play(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_audio_data_struct *aud_data = (npplg_av_audio_data_struct*)plugin_data->obj_data;
    kal_int32 mma_ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_PLAY_AUDIO, plugin_data->instance_id, aud_data->cache_status, plugin_data->seekable);

    plugin_data->processing = KAL_FALSE;
    npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_UPDATE_PROCESSNG_IMG);

    media_mma_aud_set_start_time(kal_get_active_module_id(),
                                 aud_data->mma_handle,
                                 aud_data->player.media_type,
                                 aud_data->play_time);
    
    mma_ret = media_mma_aud_play(kal_get_active_module_id(),
                                 aud_data->mma_handle,
                                 aud_data->player.media_type);

    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_PLAY_RESULT, mma_ret); 

    if (mma_ret == MED_RES_OK)
    {
        g_npplg_av_context.session_id++;
        NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_AUDIO_OBJ_STATE_PLAYING);
        
        /* Update UI - Change "Play" control to "Pause" control or "Stop" control */
        npplg_av_util_update_play_control(plugin_data, KAL_TRUE, KAL_TRUE);

        /* Start a timer to update progress bar */
        npplg_av_main_start_timer(plugin_data,
                                  NPPLG_AV_TIMER_UPDATE_PROGRESS_BAR,
                                  NPPLG_AV_UPDATE_PROGRESS_BAR_INTERVAL);
    }
    else
    {
        /* Reset state to idle */
        aud_data->play_time = 0;
        npplg_av_audio_set_state_to_idle(plugin_data);

        if (mma_ret != MED_RES_END_OF_FILE)
        {
            npplg_av_main_display_popup(plugin_data, STR_ID_NPPLG_FAIL_TO_PLAY);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_audio_handle_play_event
 * DESCRIPTION
 *  This function is used to handle play event.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_audio_handle_play_event(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_audio_data_struct *aud_data = (npplg_av_audio_data_struct*)plugin_data->obj_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch (plugin_data->state)
    {
        case NPPLG_AV_AUDIO_OBJ_STATE_IDLE:
        {
            if (aud_data->only_launch_aud_player == KAL_TRUE &&
                plugin_data->dl_state == NPPLG_AV_OBJ_DL_STATE_DOWNLOAD_OK)
            {
                /* This audio has been downloaded. Check if the file still exists */
                if (FS_GetAttributes(plugin_data->file_path) < 0)
                {
                    plugin_data->dl_state = NPPLG_AV_OBJ_DL_STATE_NULL;
                    NPPLG_AV_MEM_FREE(plugin_data->app_id, plugin_data->file_path);
                    aud_data->player.file_path = NULL;
                    npplg_av_main_display_popup(plugin_data, STR_GLOBAL_FILE_NOT_FOUND);
                    return;
                }

                /* Launch media player -> send primitive to MMI because plug-in may not run in MMI task */
                npplg_av_util_send_launch_media_player_ind(plugin_data,
                                                           kal_get_active_module_id(),
                                                           NPPLG_AV_PLAYER_TYPE_AUDIO,
                                                           KAL_FALSE);
            }
            else
            {
                if (plugin_data->dl_state == NPPLG_AV_OBJ_DL_STATE_DOWNLOAD_OK &&
                    (aud_data->cache_status == NPPLG_AV_AUDIO_CACHE_STATUS_BUILT_OK ||
                     aud_data->cache_status == NPPLG_AV_AUDIO_CACHE_STATUS_BUILT_FAIL))
                {
                    /* This audio has been downloaded. Check if the file still exists */
                    if (FS_GetAttributes(plugin_data->file_path) < 0)
                    {
                        npplg_av_main_remove_instance_from_list(&(g_npplg_av_context.app_cnxt[plugin_data->app_id].auto_play_queue), plugin_data);
                        
                        plugin_data->dl_state = NPPLG_AV_OBJ_DL_STATE_NULL;
                        aud_data->cache_status = NPPLG_AV_AUDIO_CACHE_STATUS_IDLE;
                        NPPLG_AV_MEM_FREE(plugin_data->app_id, plugin_data->file_path);
                        aud_data->player.file_path = NULL;
                        
                        npplg_av_main_display_popup(plugin_data, STR_GLOBAL_FILE_NOT_FOUND);
                        return;
                    }

                    /* Set this instance as the active instance */
                    npplg_av_main_set_active_instance(plugin_data, KAL_FALSE, plugin_data->app_id);
                    
                    npplg_av_util_disable_play_control(plugin_data, KAL_TRUE);
                    npplg_av_audio_waiting_play(plugin_data);
                }
                else
                {
                    /* Set this instance as the active instance */
                    npplg_av_main_set_active_instance(plugin_data, KAL_FALSE, plugin_data->app_id);
                    
                    /* Show waiting image */
                    npplg_av_audio_show_processing_image(plugin_data);

                    if (plugin_data->dl_state == NPPLG_AV_OBJ_DL_STATE_NULL)
                    {
                        /* Download the audio */
                        npplg_av_main_start_download(plugin_data, NPPLG_AV_AUDIO_OBJ_STATE_DOWNLOADING);
                    }
                    else if (plugin_data->dl_state == NPPLG_AV_OBJ_DL_STATE_DOWNLOADING)
                    {
                        /* Enter downloading state */
                        NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_AUDIO_OBJ_STATE_DOWNLOADING);
                    }
                    else if (aud_data->cache_status == NPPLG_AV_AUDIO_CACHE_STATUS_IDLE)
                    {
                        /* Start to build cache */
                        npplg_av_audio_start_build_cache(plugin_data);
                    }
                    else
                    {
                        ASSERT(0);
                    }
                }
            }
            break;
        }

        case NPPLG_AV_AUDIO_OBJ_STATE_PAUSED:
        {
            /* Enter playing state */
            npplg_av_audio_play(plugin_data);
            break;
        }

        default:
            break;
    }
}


#ifdef __COSMOS_MMI_PACKAGE__
/*****************************************************************************
 * FUNCTION
 *  npplg_av_audio_handle_auto_play_event
 * DESCRIPTION
 *  This function is used to handle auto play event.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_audio_handle_auto_play_event(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_audio_data_struct *aud_data = (npplg_av_audio_data_struct*)plugin_data->obj_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch (plugin_data->state)
    {
        case NPPLG_AV_AUDIO_OBJ_STATE_IDLE:
        {
            if (aud_data->only_launch_aud_player == KAL_FALSE &&
                plugin_data->dl_state == NPPLG_AV_OBJ_DL_STATE_DOWNLOAD_OK)
            {
                /* This audio has been downloaded. Check if the file still exists */
                if (FS_GetAttributes(plugin_data->file_path) < 0)
                {
                    plugin_data->dl_state = NPPLG_AV_OBJ_DL_STATE_NULL;
                    aud_data->cache_status = NPPLG_AV_AUDIO_CACHE_STATUS_IDLE;
                    NPPLG_AV_MEM_FREE(plugin_data->app_id, plugin_data->file_path);
                    aud_data->player.file_path = NULL;
                    return;
                }

                aud_data->suspend_bgplay = KAL_TRUE;

                if (aud_data->cache_status == NPPLG_AV_AUDIO_CACHE_STATUS_BUILT_OK ||
                    aud_data->cache_status == NPPLG_AV_AUDIO_CACHE_STATUS_BUILT_FAIL)
                {
                    /* Set this instance as the active instance */
                    npplg_av_main_set_active_instance(plugin_data, KAL_FALSE, plugin_data->app_id);
                    
                    npplg_av_util_disable_play_control(plugin_data, KAL_TRUE);
                    npplg_av_audio_waiting_play(plugin_data);
                }
                else
                {
                    /* Set this instance as the active instance */
                    npplg_av_main_set_active_instance(plugin_data, KAL_FALSE, plugin_data->app_id);
                    
                    /* Show waiting image */
                    npplg_av_audio_show_processing_image(plugin_data);

                    if (aud_data->cache_status == NPPLG_AV_AUDIO_CACHE_STATUS_IDLE)
                    {
                        /* Start to build cache */
                        npplg_av_audio_start_build_cache(plugin_data);
                    }
                    else
                    {
                        ASSERT(0);
                    }
                }
            }
            break;
        }

        default:
            break;
    }
}
#endif /* __COSMOS_MMI_PACKAGE__ */


/*****************************************************************************
 * FUNCTION
 *  npplg_av_audio_handle_pause_event
 * DESCRIPTION
 *  This function is used to handle pause event.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_audio_handle_pause_event(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_audio_data_struct *aud_data = (npplg_av_audio_data_struct*)plugin_data->obj_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (plugin_data->state)
    {
        case NPPLG_AV_AUDIO_OBJ_STATE_PLAYING:
        {
            npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_UPDATE_PROGRESS_BAR);
            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_AUDIO_OBJ_STATE_PAUSED);

            media_mma_aud_stop(kal_get_active_module_id(),
                               aud_data->mma_handle,
                               aud_data->player.media_type);

            g_npplg_av_context.session_id++;

            aud_data->play_time = media_mma_aud_get_current_time(kal_get_active_module_id(),
                                                                 aud_data->mma_handle,
                                                                 aud_data->player.media_type);

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
 *  npplg_av_audio_handle_stop_event
 * DESCRIPTION
 *  This function is used to handle stop event.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_audio_handle_stop_event(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_audio_data_struct *aud_data = (npplg_av_audio_data_struct*)plugin_data->obj_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (plugin_data->state)
    {
        case NPPLG_AV_AUDIO_OBJ_STATE_PLAYING:
        {
            media_mma_aud_stop(kal_get_active_module_id(),
                               aud_data->mma_handle,
                               aud_data->player.media_type);

            g_npplg_av_context.session_id++;
            break;
        }
        
        case NPPLG_AV_AUDIO_OBJ_STATE_IDLE:
            return;

        case NPPLG_AV_AUDIO_OBJ_STATE_DOWNLOADING:
        {
            /* When A/V Plug-in is downloading the audio, the instance is deleted by Opera */
            npplg_av_main_abort_download_req(plugin_data);
            break;
        }
            
        case NPPLG_AV_AUDIO_OBJ_STATE_BUILDING_CACHE:
        {
            /* When A/V Plug-in is building audio cache, the instance is deleted by Opera */
            npplg_av_audio_stop_build_cache(plugin_data);
            aud_data->cache_status = NPPLG_AV_AUDIO_CACHE_STATUS_IDLE;
            plugin_data->seekable = KAL_FALSE;
            break;
        }
        
        default:
            break;
    }

    /* Reset data */
    aud_data->play_time = 0;
    plugin_data->seek_repeat_num = 0;

    npplg_av_audio_set_state_to_idle(plugin_data);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_audio_handle_seek_event
 * DESCRIPTION
 *  This function is used to handle seek event (fast forward or rewind).
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  forward         [IN]        TRUE: fast forward, FALSE: rewind
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_audio_handle_seek_event(npplg_av_instance_struct *plugin_data, kal_bool start, kal_bool forward)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_audio_data_struct *aud_data = (npplg_av_audio_data_struct*)plugin_data->obj_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (start && plugin_data->seekable)
    {
        switch (plugin_data->state)
        {
            case NPPLG_AV_AUDIO_OBJ_STATE_PLAYING:
            {
                npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_UPDATE_PROGRESS_BAR);

                media_mma_aud_stop(kal_get_active_module_id(),
                                   aud_data->mma_handle,
                                   aud_data->player.media_type);

                g_npplg_av_context.session_id++;

                aud_data->play_time = media_mma_aud_get_current_time(kal_get_active_module_id(),
                                                                     aud_data->mma_handle,
                                                                     aud_data->player.media_type);
                /* Continue the following action */
            }

            case NPPLG_AV_AUDIO_OBJ_STATE_IDLE:
            case NPPLG_AV_AUDIO_OBJ_STATE_PAUSED:
            {
                plugin_data->seek_repeat_num = 0;

                /* Updata play time, the progress bar and start a timer */
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
        NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_AUDIO_OBJ_STATE_SEEKING);
    }
    else if (!start && plugin_data->state == NPPLG_AV_AUDIO_OBJ_STATE_SEEKING)
    {
        npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_SEEK_REPEAT);
        NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, plugin_data->prev_state);
        plugin_data->prev_state = NPPLG_AV_AUDIO_OBJ_STATE_IDLE;
        plugin_data->seek_repeat_num = 0;

        if (!plugin_data->suspend && plugin_data->state == NPPLG_AV_AUDIO_OBJ_STATE_PLAYING)
        {
            /* Play the audio only if previous state is playing state */
            npplg_av_audio_play(plugin_data);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_audio_set_state_to_idle
 * DESCRIPTION
 *  Set state as idle state
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_audio_set_state_to_idle(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_audio_data_struct *aud_data = (npplg_av_audio_data_struct*)plugin_data->obj_data;
    kal_bool resume_bgplay = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(kal_get_active_module_id() != MOD_MMI);

#ifdef __COSMOS_MMI_PACKAGE__
    resume_bgplay = aud_data->suspend_bgplay;
    aud_data->suspend_bgplay = KAL_FALSE;
#endif
    
    if (aud_data->mma_handle != NULL)
    {
        media_mma_aud_close(kal_get_active_module_id(), aud_data->mma_handle, aud_data->player.media_type);
        aud_data->mma_handle = 0;
    }

    plugin_data->processing = KAL_FALSE;
    npplg_av_main_stop_all_timer(plugin_data);

    /* Update UI */
    plugin_data->play_panel_state = NPPLG_AV_PLAY_PANEL_STATE_DISPLAY;

    if (plugin_data->deleting == KAL_FALSE)
    {
        npplg_av_audio_decide_layout(plugin_data);
        npplg_av_util_invalidate_rect(plugin_data, NULL);
    }

    NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_AUDIO_OBJ_STATE_IDLE);

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
                npplg_av_util_send_resume_background_play_ind(kal_get_active_module_id(), plugin_data->obj_type, resume_bgplay);
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
 *  npplg_av_audio_decide_layout
 * DESCRIPTION
 *  This function is used to decide the layout of playback controls.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_audio_decide_layout(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const kal_uint8 *ctrl_array[NPPLG_AV_CFG_DIFF_AUD_PLAY_PANEL_NUM];
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < NPPLG_AV_CFG_DIFF_AUD_PLAY_PANEL_NUM; i++)
    {
        ctrl_array[i] = g_npplg_av_cfg_audio_play_panel[i];
    }
    npplg_av_util_compose_play_panel(plugin_data,
                                     NPPLG_AV_OBJ_TYPE_AUDIO,
                                     ctrl_array,
                                     NPPLG_AV_CFG_DIFF_AUD_PLAY_PANEL_NUM,
                                     NPPLG_AV_AUD_PANEL_MAX_SUPPORT_CTRL_NUM);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_audio_show_waiting_image
 * DESCRIPTION
 *  This function is used to prepare to show processing image.
 *  1. Set play_panel_state as NPPLG_AV_PLAY_PANEL_STATE_HIDE because plug-in would use audio object area to draw processing image
 *  2. Reset processing_img_indx
 *  3. Call utility function to show processing image
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_audio_show_processing_image(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    plugin_data->play_panel_state = NPPLG_AV_PLAY_PANEL_STATE_HIDE;
    plugin_data->processing_img_indx = 0;
    npplg_av_util_show_processing_image(plugin_data, KAL_TRUE);
}


/************************************************************
 * Global Function
 ************************************************************/

/*****************************************************************************
 * FUNCTION
 *  npplg_av_audio_free_data
 * DESCRIPTION
 *  This function is used to free memory used by audio data.
 * PARAMETERS
 *  plugin_data     [IN]        Plugin instance data
 *  data            [IN]        Audio data pointer
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_audio_free_data(npplg_av_instance_struct *plugin_data, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_audio_data_struct *aud_data = (npplg_av_audio_data_struct*)data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NPPLG_AV_MEM_FREE(plugin_data->app_id, aud_data->cache_file_buf);
    NPPLG_AV_MEM_FREE(plugin_data->app_id, aud_data->cache_proc_buf);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_audio_handle_url_rsp
 * DESCRIPTION
 *  Handle download response
 * PARAMETERS
 *  plugin_data     [IN]        Audio instance data
 *  download_rsp    [IN]        Download response
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_audio_handle_url_rsp(npplg_av_instance_struct *plugin_data, NPReason download_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    npplg_av_audio_data_struct *aud_data = (npplg_av_audio_data_struct*)plugin_data->obj_data;
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

                if (plugin_data->state != NPPLG_AV_AUDIO_OBJ_STATE_IDLE)
                {
                    npplg_av_audio_set_state_to_idle(plugin_data);
                }

                if (state == NPPLG_AV_AUDIO_OBJ_STATE_DOWNLOADING)
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
                aud_data->player.file_path = NULL;

                if (plugin_data->state != NPPLG_AV_AUDIO_OBJ_STATE_IDLE)
                {
                    npplg_av_audio_set_state_to_idle(plugin_data);
                }

                if (state == NPPLG_AV_AUDIO_OBJ_STATE_DOWNLOADING)
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
                
                if (plugin_data->state == NPPLG_AV_AUDIO_OBJ_STATE_DOWNLOADING)
                {
                    if (!plugin_data->suspend)
                    {
                        /*
                         * When plug-in is downloading the audio, user starts to play the audio.
                         * After the audio is downloaded, plug-in should start to play the audio.
                         *
                         * If this audio is normal audio (not 3gp and 3gpp), plug-in play it inside browser.
                         * Before plug-in play the audio, plug-in should first build audio cache to let seek smoothly.
                         *
                         * If this audio is 3gp or 3gpp, plug-in should launch audio player because media MMA does not
                         * support 3gp and 3gpp.
                         */
                        if (aud_data->only_launch_aud_player)
                        {
                            npplg_av_audio_set_state_to_idle(plugin_data);

                            /* Launch media player -> send primitive to MMI because plug-in may not run in MMI task */
                            npplg_av_util_send_launch_media_player_ind(plugin_data,
                                                                       kal_get_active_module_id(),
                                                                       NPPLG_AV_PLAYER_TYPE_AUDIO,
                                                                       KAL_FALSE);
                        }
                        else
                        {
                            /* Start to build cache */
                            npplg_av_audio_start_build_cache(plugin_data);
                        }
                    }
                    else
                    {
                        if (aud_data->only_launch_aud_player)
                        {
                            npplg_av_audio_set_state_to_idle(plugin_data);
                        }
                    }
                }
                else
                {
                    if (aud_data->only_launch_aud_player == KAL_FALSE)
                    {
                        /* Can not play 3gp and 3gpp inside browser */
                        npplg_av_main_add_auto_play_instance(plugin_data);
                    }
                }
            }
            break;
        }

        case NPRES_NETWORK_ERR:
        {
            if (plugin_data->state == NPPLG_AV_AUDIO_OBJ_STATE_DOWNLOADING)
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
            aud_data->player.file_path = NULL;
            plugin_data->dl_state = NPPLG_AV_OBJ_DL_STATE_NULL;

            if (plugin_data->state != NPPLG_AV_AUDIO_OBJ_STATE_IDLE)
            {
                npplg_av_audio_set_state_to_idle(plugin_data);
            }

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
 *  npplg_av_audio_handle_timer_event
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
kal_int16 npplg_av_audio_handle_timer_event(npplg_av_instance_struct *plugin_data, kal_uint8 timer_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_audio_data_struct *aud_data = (npplg_av_audio_data_struct*)plugin_data->obj_data;
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
            case NPPLG_AV_AUDIO_OBJ_STATE_BUILDING_CACHE:
            {
                /*
                 * In this state, there are two possible timer types:
                 * 1. NPPLG_AV_TIMER_UPDATE_PROCESSNG_IMG
                 * 2. NPPLG_AV_TIMER_AUDIO_BUILD_CACHE_CHECK
                 */
                if (aud_data->cache_status == NPPLG_AV_AUDIO_CACHE_STATUS_BUILDING &&
                    timer_type == NPPLG_AV_TIMER_AUDIO_BUILD_CACHE_CHECK)
                {
                    npplg_av_audio_build_cache_process(plugin_data);
                }
                break;
            }

            case NPPLG_AV_AUDIO_OBJ_STATE_PLAYING:
            {
                /* In this state, only one possible timer NPPLG_AV_TIMER_UPDATE_PROGRESS_BAR */
                if (timer_type == NPPLG_AV_TIMER_UPDATE_PROGRESS_BAR)
                {
                    /* Update UI - progress bar */
                    aud_data->play_time = media_mma_aud_get_current_time(kal_get_active_module_id(),
                                                                         aud_data->mma_handle,
                                                                         aud_data->player.media_type);
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
                break;
            }

            case NPPLG_AV_AUDIO_OBJ_STATE_SEEKING:
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

            case NPPLG_AV_AUDIO_OBJ_STATE_RESET_PLAY_PANEL:
            {
                if (timer_type == NPPLG_AV_TIMER_RESET_PLAY_PANEL)
                {
                    aud_data->play_time = 0;
                    npplg_av_audio_set_state_to_idle(plugin_data);
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
 *  npplg_av_audio_handle_event
 * DESCRIPTION
 *  This function is used to handle event.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  event           [IN]        Event
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_audio_handle_event(npplg_av_instance_struct *plugin_data, kal_uint8 event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_audio_data_struct *aud_data = (npplg_av_audio_data_struct*)plugin_data->obj_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plugin_data->state == NPPLG_AV_AUDIO_OBJ_STATE_RESET_PLAY_PANEL)
    {
        aud_data->play_time = 0;
        npplg_av_audio_set_state_to_idle(plugin_data);
    }
    
    switch (event)
    {
        case NPPLG_AV_INT_EVT_PLAY:
            npplg_av_audio_handle_play_event(plugin_data);
            break;

#ifdef __COSMOS_MMI_PACKAGE__
        case NPPLG_AV_INT_EVT_AUTO_PLAY:
            npplg_av_audio_handle_auto_play_event(plugin_data);
            break;
#endif

        case NPPLG_AV_INT_EVT_PAUSE:
            npplg_av_audio_handle_pause_event(plugin_data);
            break;

        case NPPLG_AV_INT_EVT_STOP:
            npplg_av_audio_handle_stop_event(plugin_data);
            break;

        case NPPLG_AV_INT_EVT_FAST_FORWARD_START:
            npplg_av_audio_handle_seek_event(plugin_data, KAL_TRUE, KAL_TRUE);
            break;

        case NPPLG_AV_INT_EVT_FAST_FORWARD_STOP:
            npplg_av_audio_handle_seek_event(plugin_data, KAL_FALSE, KAL_TRUE);
            break;

        case NPPLG_AV_INT_EVT_REWIND_START:
            npplg_av_audio_handle_seek_event(plugin_data, KAL_TRUE, KAL_FALSE);
            break;

        case NPPLG_AV_INT_EVT_REWIND_STOP:
            npplg_av_audio_handle_seek_event(plugin_data, KAL_FALSE, KAL_FALSE);
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_audio_redraw_window
 * DESCRIPTION
 *  This function is used to update the window.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_audio_redraw_window(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Decide the play panel */
    npplg_av_audio_decide_layout(plugin_data);
    
    if (plugin_data->state == NPPLG_AV_AUDIO_OBJ_STATE_BUILDING_CACHE ||
        plugin_data->state == NPPLG_AV_AUDIO_OBJ_STATE_DOWNLOADING)
    {
        /* Redraw processing image */
        npplg_av_util_show_processing_image(plugin_data, KAL_FALSE);
    }
    else
    {
        if (plugin_data->state == NPPLG_AV_AUDIO_OBJ_STATE_PLAYING ||
            (plugin_data->state == NPPLG_AV_AUDIO_OBJ_STATE_SEEKING &&
             plugin_data->prev_state == NPPLG_AV_AUDIO_OBJ_STATE_PLAYING))
        {
            /* Change "Play" control to "Pause" control or "Stop" control */
            npplg_av_util_update_play_control(plugin_data, KAL_TRUE, KAL_FALSE);
        }

        /* Draw the controls on the paint buffer */
        npplg_av_util_invalidate_rect(plugin_data, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_audio_play_callback
 * DESCRIPTION
 *  This function is the callback function for audio play.
 * PARAMETERS
 *  result          [IN]        Audio play result
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_audio_play_callback(kal_int32 handle, kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_audio_play_res_struct *play_res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_PLAY_RESULT, result); 

    play_res = (npplg_av_audio_play_res_struct*)
                    construct_local_para(sizeof(npplg_av_audio_play_res_struct), TD_CTRL | TD_RESET);

    play_res->mma_handle = handle;
    play_res->result = result;
    play_res->session_id = g_npplg_av_context.session_id;

    npplg_av_util_send_ilm(kal_get_active_module_id(),
                           g_npplg_av_context.app_cnxt[g_npplg_av_context.play_app_id].mod_id,
                           MSG_ID_NPPLG_AV_AUDIO_PLAY_RES,
                           play_res,
                           NULL);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_audio_suspend_by_app
 * DESCRIPTION
 *  This function is used to suspend audio.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_audio_suspend_by_app(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_audio_data_struct *aud_data = (npplg_av_audio_data_struct*)plugin_data->obj_data;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_SUSPEND, plugin_data->obj_type, plugin_data->instance_id, plugin_data->state);

    NPPLG_AV_LOCK;
    
    npplg_av_main_stop_all_timer(plugin_data);

    switch (plugin_data->state)
    {
        case NPPLG_AV_AUDIO_OBJ_STATE_BUILDING_CACHE:
        {
            /* Stop building cache since MDI Audio has only one context and plug-in can not build cache in background */
            npplg_av_audio_stop_build_cache(plugin_data);
            aud_data->cache_status = NPPLG_AV_AUDIO_CACHE_STATUS_IDLE;
            plugin_data->seekable = KAL_FALSE;
            break;
        }

        case NPPLG_AV_AUDIO_OBJ_STATE_WAITING_PLAY:
        {
            if (aud_data->mma_handle != NULL)
            {
                media_mma_aud_close(kal_get_active_module_id(), aud_data->mma_handle, aud_data->player.media_type);
                aud_data->mma_handle = 0;
            }
            break;
        }
        
        case NPPLG_AV_AUDIO_OBJ_STATE_PLAYING:
        {
            media_mma_aud_stop(kal_get_active_module_id(),
                               aud_data->mma_handle,
                               aud_data->player.media_type);

            g_npplg_av_context.session_id++;

            aud_data->play_time = media_mma_aud_get_current_time(kal_get_active_module_id(),
                                                                 aud_data->mma_handle,
                                                                 aud_data->player.media_type);

            media_mma_aud_close(kal_get_active_module_id(), aud_data->mma_handle, aud_data->player.media_type);
            aud_data->mma_handle = 0;
            break;
        }

        case NPPLG_AV_AUDIO_OBJ_STATE_PAUSED:
        {
            media_mma_aud_close(kal_get_active_module_id(), aud_data->mma_handle, aud_data->player.media_type);
            aud_data->mma_handle = 0;
            break;
        }

        case NPPLG_AV_AUDIO_OBJ_STATE_SEEKING:
        {
            plugin_data->seek_repeat_num = 0;

            if (plugin_data->prev_state == NPPLG_AV_AUDIO_OBJ_STATE_PAUSED ||
                plugin_data->prev_state == NPPLG_AV_AUDIO_OBJ_STATE_PLAYING)
            {
                media_mma_aud_close(kal_get_active_module_id(), aud_data->mma_handle, aud_data->player.media_type);
                aud_data->mma_handle = 0;
            }

            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, plugin_data->prev_state);
            plugin_data->prev_state = NPPLG_AV_AUDIO_OBJ_STATE_IDLE;
            break;
        }

        default:
            break;
    }

    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_audio_resume_by_app
 * DESCRIPTION
 *  This function is used to resume audio.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_audio_resume_by_app(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_audio_data_struct *aud_data = (npplg_av_audio_data_struct*)plugin_data->obj_data;
    kal_int32 mma_ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_RESUME, plugin_data->obj_type, plugin_data->instance_id, plugin_data->state);

    NPPLG_AV_LOCK;

    if (g_npplg_av_context.is_speech_mode == KAL_TRUE)
    {
        /* Background call */
        switch (plugin_data->state)
        {
            case NPPLG_AV_AUDIO_OBJ_STATE_IDLE:
            case NPPLG_AV_AUDIO_OBJ_STATE_SEEKING:
                break;

            default:
            {
                /*
                 * NPPLG_AV_AUDIO_OBJ_STATE_DOWNLOADING
                 * NPPLG_AV_AUDIO_OBJ_STATE_BUILDING_CACHE
                 * NPPLG_AV_AUDIO_OBJ_STATE_WAITING_PLAY
                 * NPPLG_AV_AUDIO_OBJ_STATE_PLAYING
                 * NPPLG_AV_AUDIO_OBJ_STATE_PAUSED
                 * NPPLG_AV_AUDIO_OBJ_STATE_RESET_PLAY_PANEL
                 */
                NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_AUDIO_OBJ_STATE_RESET_PLAY_PANEL);
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
        switch (plugin_data->state)
        {
            case NPPLG_AV_AUDIO_OBJ_STATE_DOWNLOADING:
            case NPPLG_AV_AUDIO_OBJ_STATE_BUILDING_CACHE:
            case NPPLG_AV_AUDIO_OBJ_STATE_RESET_PLAY_PANEL:
            {
                npplg_av_util_send_mmi_resume_ind(npplg_av_main_get_app_mod_id(plugin_data->app_id),
                                                  plugin_data->instance_id,
                                                  plugin_data->app_id,
                                                  plugin_data->state);
                break;
            }

            case NPPLG_AV_AUDIO_OBJ_STATE_WAITING_PLAY:
            {
                aud_data->mma_handle = media_mma_aud_open(kal_get_active_module_id(), &(aud_data->player), &mma_ret);

                if (mma_ret == MED_RES_OK)
                {
                    /* Set audio output path */
                    mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER2);
                    
                    if (aud_data->cache_status != NPPLG_AV_AUDIO_CACHE_STATUS_BUILT_OK ||
                        aud_data->total_time == 0)
                    {
                        aud_data->total_time = media_mma_aud_get_duration(kal_get_active_module_id(), aud_data->mma_handle, aud_data->player.media_type);
                    }
                    else
                    {
                        media_mma_set_cache_table(kal_get_active_module_id(), aud_data->mma_handle, aud_data->cache);
                    }

                    /* Apply the mute setting of active plug-in instance */
                    npplg_av_main_set_mute(plugin_data->mute, plugin_data->app_id);
                    
                    /* Set volume */
                    mdi_audio_set_volume(MDI_VOLUME_MEDIA, npplg_av_main_get_volume(plugin_data->app_id));

                    g_npplg_av_context.res_status = NPPLG_AV_RES_STATUS_OCCUPIED;

                    npplg_av_util_send_suspend_background_play_rsp(npplg_av_main_get_app_mod_id(plugin_data->app_id),
                                                                   plugin_data->app_id,
                                                                   NPPLG_AV_OK);
                }
                else
                {
                    mdi_audio_clear_interrupt_callback();
                    g_npplg_av_context.res_status = NPPLG_AV_RES_STATUS_NULL;

#ifdef __COSMOS_MMI_PACKAGE__
                    if (aud_data->suspend_bgplay)
                    {
                        mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_ASYNC_APP);
                    }
#else
                    mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_ASYNC_APP);
#endif
                    npplg_av_util_send_suspend_background_play_rsp(npplg_av_main_get_app_mod_id(plugin_data->app_id),
                                                                   plugin_data->app_id,
                                                                   NPPLG_AV_FAIL);
                }
                break;
            }
            
            case NPPLG_AV_AUDIO_OBJ_STATE_PLAYING:
            {
                aud_data->mma_handle = media_mma_aud_open(kal_get_active_module_id(), &(aud_data->player), &mma_ret);

                if (mma_ret == MED_RES_OK)
                {
                    /* Set audio output path */
                    mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER2);
                                        
                    npplg_av_util_send_mmi_resume_ind(npplg_av_main_get_app_mod_id(plugin_data->app_id),
                                                      plugin_data->instance_id,
                                                      plugin_data->app_id,
                                                      plugin_data->state);
                }
                else
                {
                    NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_AUDIO_OBJ_STATE_RESET_PLAY_PANEL);
                    mdi_audio_clear_interrupt_callback();
                    g_npplg_av_context.res_status = NPPLG_AV_RES_STATUS_NULL;
#ifdef __COSMOS_MMI_PACKAGE__
                    if (aud_data->suspend_bgplay)
                    {
                        mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_ASYNC_APP);
                    }
#else
                    mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_ASYNC_APP);                    
#endif
                    npplg_av_util_send_mmi_resume_ind(npplg_av_main_get_app_mod_id(plugin_data->app_id),
                                                      plugin_data->instance_id,
                                                      plugin_data->app_id,
                                                      plugin_data->state);
                }
                break;
            }

            case NPPLG_AV_AUDIO_OBJ_STATE_PAUSED:
            {
                aud_data->mma_handle = media_mma_aud_open(kal_get_active_module_id(), &(aud_data->player), &mma_ret);

                if (mma_ret != MED_RES_OK)
                {
                    NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_AUDIO_OBJ_STATE_RESET_PLAY_PANEL);
                    mdi_audio_clear_interrupt_callback();
                    g_npplg_av_context.res_status = NPPLG_AV_RES_STATUS_NULL;
#ifdef __COSMOS_MMI_PACKAGE__
                    if (aud_data->suspend_bgplay)
                    {
                        mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_ASYNC_APP);
                    }
#else
                    mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_ASYNC_APP);                    
#endif
                    npplg_av_util_send_mmi_resume_ind(npplg_av_main_get_app_mod_id(plugin_data->app_id),
                                                      plugin_data->instance_id,
                                                      plugin_data->app_id,
                                                      plugin_data->state);
                }
                else
                {
                    /* Set audio output path */
                    mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER2);
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
 *  npplg_av_audio_close_by_app
 * DESCRIPTION
 *  This function is used to close audio.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_audio_close_by_app(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_CLOSE, plugin_data->obj_type, plugin_data->instance_id, plugin_data->state);

    NPPLG_AV_LOCK;

    if (plugin_data->state != NPPLG_AV_AUDIO_OBJ_STATE_IDLE)
    {
        NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_AUDIO_OBJ_STATE_RESET_PLAY_PANEL);
    }

    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_audio_handle_suspend_background_play_rsp
 * DESCRIPTION
 *  Handle MSG_ID_NPPLG_AV_SUSPEND_BACKGROUND_PLAY_RSP
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  result          [IN]        Result
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_audio_handle_suspend_background_play_rsp(npplg_av_instance_struct *plugin_data,
                                                       kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_audio_data_struct *aud_data = (npplg_av_audio_data_struct*)plugin_data->obj_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plugin_data->state == NPPLG_AV_AUDIO_OBJ_STATE_WAITING_PLAY)
    {
        if (g_npplg_av_context.app_cnxt[plugin_data->app_id].is_suspend_by_mmi == KAL_TRUE &&
            result == NPPLG_AV_OK)
        {
            /*
             * Ignore this message because application is in the background
             * Do nothing but still stay in WAITING_PLAY state
             */
        }
        else if (g_npplg_av_context.app_cnxt[plugin_data->app_id].is_suspend_by_mmi == KAL_FALSE &&
                 result == NPPLG_AV_OK &&
                 aud_data->mma_handle != NULL)
        {
            npplg_av_audio_play(plugin_data);
        }
        else
        {
            aud_data->play_time = 0;
            npplg_av_audio_set_state_to_idle(plugin_data);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_audio_play_result_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_audio_play_result_handler(npplg_av_instance_struct *plugin_data, kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_audio_data_struct *aud_data;
    npplg_av_obj_control_struct *progress_bar, *time_ctrl;
    kal_uint32 play_time;
    kal_bool display_error = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plugin_data != NULL && plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_AUDIO)
    {
        switch (result)
        {
            case MED_RES_END_OF_FILE:
            case MED_RES_TERMINATED:
                break;

            case MED_RES_ERROR:
            case MED_RES_DECODER_NOT_SUPPORT:
            {
                display_error = KAL_TRUE;
                break;
            }

            default:
            {
                /* Ignore this result */
                return;
            }
        }

        /* Cancel the timer of updating progress bar */
        npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_UPDATE_PROGRESS_BAR);

        aud_data = (npplg_av_audio_data_struct*)plugin_data->obj_data;

        progress_bar = npplg_av_util_get_control(plugin_data, NPPLG_AV_CTRL_TYPE_PROGRESS_BAR);
        time_ctrl = npplg_av_util_get_control(plugin_data, NPPLG_AV_CTRL_TYPE_TIME);
        play_time = media_mma_aud_get_current_time(kal_get_active_module_id(),
                                                   aud_data->mma_handle,
                                                   aud_data->player.media_type);

        media_mma_aud_close(kal_get_active_module_id(), aud_data->mma_handle, aud_data->player.media_type);
        aud_data->mma_handle = 0;

        if ((progress_bar != NULL || time_ctrl != NULL) &&
            play_time == aud_data->total_time)
        {
            npplg_av_main_stop_all_timer(plugin_data);
            
            /* Fill the progress bar completely */
            aud_data->play_time = play_time;

            if (progress_bar != NULL)
            {
                npplg_av_util_invalidate_rect(plugin_data, progress_bar);
            }

            if (time_ctrl != NULL)
            {
                npplg_av_util_invalidate_rect(plugin_data, time_ctrl);
            }
            
            plugin_data->seek_repeat_num = 0;

            /* Start a timer to redraw the play panel */
            npplg_av_main_start_timer(plugin_data,
                                      NPPLG_AV_TIMER_RESET_PLAY_PANEL,
                                      NPPLG_AV_RESET_PLAY_PANEL_INTERVAL);

            NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, NPPLG_AV_AUDIO_OBJ_STATE_RESET_PLAY_PANEL);
            return;
        }

        aud_data->play_time = 0;
        plugin_data->seek_repeat_num = 0;
        npplg_av_audio_set_state_to_idle(plugin_data);

        if (display_error)
        {
            npplg_av_main_display_popup(plugin_data, STR_ID_NPPLG_FAIL_TO_PLAY);
        }
    }
}



/*****************************************************************************
 * FUNCTION
 *  npplg_av_audio_mmi_resume_ind_handler
 * DESCRIPTION
 *  This function is used to handle MMI resume indication in engine task.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_audio_mmi_resume_ind_handler(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_audio_data_struct *aud_data = (npplg_av_audio_data_struct*)plugin_data->obj_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    NPPLG_AV_LOCK;

    switch (plugin_data->state)
    {
        case NPPLG_AV_AUDIO_OBJ_STATE_DOWNLOADING:
        {
            if (plugin_data->dl_state == NPPLG_AV_OBJ_DL_STATE_DOWNLOAD_OK)
            {
                if (aud_data->only_launch_aud_player)
                {
                    npplg_av_audio_set_state_to_idle(plugin_data);                    
                }
                else
                {
                    /* Start to build cache */
                    npplg_av_audio_start_build_cache(plugin_data);
                }
            }
            else
            {
                npplg_av_util_show_processing_image(plugin_data, KAL_TRUE);
            }
            break;
        }

        case NPPLG_AV_AUDIO_OBJ_STATE_BUILDING_CACHE:
        {
            npplg_av_audio_start_build_cache(plugin_data);
            break;
        }
        
        case NPPLG_AV_AUDIO_OBJ_STATE_PLAYING:
        {
            npplg_av_audio_play(plugin_data);
            break;
        }

        case NPPLG_AV_AUDIO_OBJ_STATE_RESET_PLAY_PANEL:
        {
            aud_data->play_time = 0;
            npplg_av_audio_set_state_to_idle(plugin_data);
            break;
        }
        
        default:
            break;
    }

    NPPLG_AV_UNLOCK;
}

#endif /* defined(OPERA_V10_BROWSER) || defined(__GADGET_SUPPORT__) */

