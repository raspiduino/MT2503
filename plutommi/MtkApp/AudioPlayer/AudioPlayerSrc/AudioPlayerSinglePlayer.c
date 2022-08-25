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

/*******************************************************************************
* Filename:
* ---------
*   AudioPlayerSinglePlayer.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Audio player Single player
*
* Author:
* -------
*  
*
*==============================================================================
*           HISTORY
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#include "MMI_features.h"

#ifndef __MMI_MEDIA_PLAYER_AUDIO__
#ifdef __MMI_FILE_MANAGER__
#include "mdi_datatype.h"

#include "mdi_audio.h"
#include "AudioPlayerDef.h"
#include "AudioPlayerProt.h"
#include "Mmi_frm_scenario_gprot.h"

#ifdef __MMI_BACKGROUND_CALL__
#include "CommonScreens.h"
#endif
/*DRM related*/
#include "DRM_gprot.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gui_data_types.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "mmi_rp_app_audioplayer_def.h"
#include "wgui_categories_util.h"
#include "device.h"
#include "kal_public_api.h"
#include "mmi_frm_timer_gprot.h"
#include "AudioPlayerResDef.h"
#include "GlobalResDef.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_multimedia.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "fs_type.h"
#include "drm_def.h"
#include "fs_errcode.h"
    

/*
**  static variables definition.
*/
static U8 single_volume = 0;
static U8 single_volume_nvram = 0;
static U8 single_play_state = STATE_IDLE;
static U32 single_play_duration = 0;
static kal_uint32 single_play_time = 0;
static MMI_BOOL in_single_play_screen = MMI_FALSE;
static void (*single_play_exit_callback_func)(void) = NULL;
static U16 audply_single_play_title_icon = 0;


#if defined( __MMI_BT_DIALER_SUPPORT__) || defined( __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__)
static void (*temp_single_play_exit_callback_func)(void) = NULL;
static U16 temp_audply_single_play_title_icon = 0;
static UI_string_type temp_filepath = NULL;
#endif
/*
**  static function prototypes.
*/
static void mmi_audply_single_inc_volume(void);
static void mmi_audply_single_dec_volume(void);
static void mmi_audply_single_play_timer(void);
static void mmi_audply_entry_play_animation(void);
static S32 mmi_audply_do_single_play_action(UI_string_type filefullname);
static void mmi_audply_single_play_callback_hdlr(mdi_result result, void *user_data);
static mmi_ret mmi_audply_single_proc(mmi_event_struct *evt);

#define AUDPLY_SINGLE_PLAY_SOURCE_CODE

#ifdef __BT_SPK_VOL_CONTROL__
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_single_handfree_volume_sync_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_audply_single_handfree_volume_sync_callback(U8 volume, MMI_BOOL is_mute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(volume <= MDI_AUD_VOL_NUM);

    single_volume = volume;

    mdi_audio_set_volume(VOL_TYPE_MEDIA, MDI_AUD_VOL_MUTE(single_volume));
    return MMI_TRUE;
}
#endif/*__BT_SPK_VOL_CONTROL__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_is_play_activated
 * DESCRIPTION
 *  indicate whether will audio player (or single song) play or attempt to play song soon
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_is_single_play_activated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)(single_play_state == STATE_PLAY);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_init_single_play
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_init_single_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   // S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValueSlim(NVRAM_AUDPLY_SINGLE_VOL, &single_volume, DS_BYTE);
    if (single_volume == 0xFFFF)
    {
        single_volume = MDI_AUD_VOL_3;
        WriteValueSlim(NVRAM_AUDPLY_SINGLE_VOL, &single_volume, DS_BYTE);
    }
    
    if( single_volume > MDI_AUD_VOL_NUM - 1)
    {
        single_volume = MDI_AUD_VOL_3;
        WriteValueSlim(NVRAM_AUDPLY_SINGLE_VOL, &single_volume, DS_BYTE);
    }
    single_volume_nvram = single_volume;
}


#if defined( __MMI_BT_DIALER_SUPPORT__) || defined( __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__)
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_single_bt_music_disconnect_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_single_bt_music_disconnect_callback(MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result)
    {
        mmi_audply_single_play(temp_filepath, temp_single_play_exit_callback_func, temp_audply_single_play_title_icon);
    }
}
#endif /* __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_single_play
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filefullname            [IN]        Void (*exit_callback_func)(void)
 *  exit_callback_func      [IN]
 *  title_icon              [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_single_play(UI_string_type filefullname, void (*exit_callback_func)(void), U16 title_icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BT_MUSIC__) || defined(__MMI_AUDIO_PLAYER_BT__)
    if (mmi_bt_music_check_connection())
    {
        temp_filepath = filefullname;
        temp_single_play_exit_callback_func = exit_callback_func;
        temp_audply_single_play_title_icon = title_icon;
        mmi_bt_music_disconnect(mmi_audply_single_bt_music_disconnect_callback);
        //return;
    }
#endif

    single_play_exit_callback_func = exit_callback_func;

#ifdef __MMI_BACKGROUND_CALL__
    if(srv_ucm_is_background_call())
    {
        if (single_play_exit_callback_func != NULL)
        {
            single_play_exit_callback_func();
            single_play_exit_callback_func = NULL;
        }
        mmi_ucm_entry_error_message();
        return;
    }
#endif

    mdi_audio_suspend_background_play();

#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_register_volume_sync_callback(APP_SINGLE_AUDIO,MDI_AUD_VOL_LEVEL_NORMAL_MUTE,mmi_audply_single_handfree_volume_sync_callback);
#endif
    result = mmi_audply_do_single_play_action(filefullname);
    if (result == MDI_AUDIO_SUCCESS)
    {
    #ifdef __MMI_AUDIO_PLAYER__        
        if (title_icon == 0)
        {
            title_icon = GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID);
        }
    #endif
        audply_single_play_title_icon = title_icon ;
        mmi_audply_entry_play_animation();
    }
    else
    {
        mdi_audio_resume_background_play();
    #ifdef __BT_SPK_VOL_CONTROL__
        mdi_audio_bt_clear_volume_sync_callback(APP_SINGLE_AUDIO);
    #endif        
        if (single_play_exit_callback_func != NULL)
        {
            single_play_exit_callback_func();
            single_play_exit_callback_func = NULL;
        }
        mmi_audply_display_popup(result, NULL, NULL);
    } 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_exit_single_play
 * DESCRIPTION
 *  exit audply single play
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_exit_single_play(void)
{
    /*do nothing*/
#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    mmi_frm_scrn_close(GRP_ID_AUDPLY_PLAY_ANIMATION, SCR_ID_AUDPLY_PLAY_ANIMATION);
#endif
}

#define AUDPLY_SINGLE_PLAY_STATIC_FUNCTION
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_single_inc_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_single_inc_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (single_volume < MDI_AUD_VOL_NUM - 1)
    {
        mdi_audio_set_volume(VOL_TYPE_MEDIA, MDI_AUD_VOL_MUTE(++single_volume));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_single_dec_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_single_dec_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (single_volume > 0)
    {
        mdi_audio_set_volume(VOL_TYPE_MEDIA,MDI_AUD_VOL_MUTE(--single_volume));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_single_play_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_single_play_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 current_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&current_time);
    single_play_duration = current_time - single_play_time;
    StartTimer(AUDPLY_SINGLE_PLAY_TIMER, 500, mmi_audply_single_play_timer);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_delete_play_animation_history_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param_p     [?]     
 * RETURNS
 *  U8
 *****************************************************************************/
static mmi_ret mmi_audply_play_animation_proc(mmi_event_struct* event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event->evt_id)
    {
        case EVT_ID_ON_KEY:
        {
            mmi_frm_key_evt_struct *p = (mmi_frm_key_evt_struct *)event;
            if (p->key_type == KEY_EVENT_DOWN)
            {
                 if (p->key_code == KEY_VOL_UP || p->key_code == KEY_POUND)  
                 {
                    mmi_audply_single_inc_volume();
                    return MMI_RET_KEY_HANDLED;
                 }
                 else if (p->key_code == KEY_VOL_DOWN || p->key_code == KEY_STAR) 
                 {
                    mmi_audply_single_dec_volume();
                    return MMI_RET_KEY_HANDLED;
                 }
            }
            break;
        }
        case EVT_ID_SCRN_INACTIVE:
        {
            in_single_play_screen = MMI_FALSE;
            break;
        }
        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_frm_scrn_active_evt_struct * p =
                        (mmi_frm_scrn_active_evt_struct *)event;
            
            in_single_play_screen = MMI_TRUE;
            if (single_play_state == STATE_PLAY)
            {
                ShowCategory223Screen(
                    STR_ID_AUDPLY_TITLE,
                    audply_single_play_title_icon,
                    0,
                    0,
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,
                    IMG_ID_AUDPLY_PLAY_ANIMATION,
                    1,
                    single_play_duration,
                    p->gui_buffer);
            }
            break;
        }
        case EVT_ID_SCRN_DEINIT:
        {
            if (single_play_state != STATE_IDLE)
            {
                mmi_audply_do_single_stop_action();
            }
        
            if (single_play_exit_callback_func!=NULL)
            {
                single_play_exit_callback_func();
                single_play_exit_callback_func = NULL;
            }
            mdi_audio_resume_background_play();
        
#ifdef __BT_SPK_VOL_CONTROL__
            mdi_audio_bt_clear_volume_sync_callback(APP_SINGLE_AUDIO);
#endif
            if (single_volume_nvram != single_volume)
            {
                WriteValueSlim(NVRAM_AUDPLY_SINGLE_VOL, &single_volume, DS_BYTE);
                single_volume_nvram = single_volume;
            }
            break;
        }
        default:
            break;
    }
    
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_entry_play_animation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_entry_play_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
    mmi_frm_group_create_ex(
         GRP_ID_ROOT, 
         GRP_ID_AUDPLY_PLAY_ANIMATION, 
         mmi_audply_single_proc, 
         NULL, 
         MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_create(
         GRP_ID_AUDPLY_PLAY_ANIMATION, 
         SCR_ID_AUDPLY_PLAY_ANIMATION, 
         mmi_audply_play_animation_proc,   
         NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_single_proc
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_audply_single_proc(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_do_single_play_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filefullname        [IN]        
 *  mdi_result result(?)
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_audply_do_single_play_action(UI_string_type filefullname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
    FS_HANDLE handle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = DRM_open_file(filefullname, FS_READ_ONLY, DRM_PERMISSION_PLAY);
    if (handle >= FS_NO_ERROR)
    {
        DRM_close_file(handle);
    }
    else
    {
        if (handle == FS_MEDIA_CHANGED)
        {
            handle = FS_FILE_NOT_FOUND;
        }
        return (S32)handle;
    }
    //bql
    //dummy macro [#define MDI_AUD_PTH_EX(x) (x)]
    result = mdi_audio_play_file_with_vol_path(
                filefullname,
                DEVICE_AUDIO_PLAY_ONCE,
                NULL,
                mmi_audply_single_play_callback_hdlr,
                NULL,
                MDI_AUD_VOL_MUTE(single_volume),
                MDI_AUD_PTH_EX(MDI_DEVICE_SPEAKER2));

    single_play_duration = 0; //bql: indicate how long has been played
    if (result == MDI_AUDIO_SUCCESS)
    {
        single_play_state = STATE_PLAY;
        kal_get_time(&single_play_time); //bql: indicate current play point kal time
        StartTimer(AUDPLY_SINGLE_PLAY_TIMER, 500, mmi_audply_single_play_timer); //bql: start a timer to update single_play_duration
    }
    else
    {
        single_play_state = STATE_IDLE;
    }

    return (S32) result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_do_single_stop_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_do_single_stop_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    single_play_state = STATE_IDLE;
    mdi_audio_stop_file();
    StopTimer(AUDPLY_SINGLE_PLAY_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_single_play_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_single_play_callback_hdlr(mdi_result result, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (single_play_state == STATE_IDLE)
    {
        return;
    }

    switch (result)
    {
        case MDI_AUDIO_END_OF_FILE:
        #if 0 //bql: same with MDI_AUDIO_TERMINATED
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
        case MDI_AUDIO_TERMINATED:
            single_play_state = STATE_IDLE;
            StopTimer(AUDPLY_SINGLE_PLAY_TIMER);
            if (in_single_play_screen)
            {
                mmi_frm_scrn_close_active_id();
            }
            else
            {
                if (mmi_frm_group_is_present(GRP_ID_AUDPLY_PLAY_ANIMATION))
                {
                    mmi_frm_scrn_close(GRP_ID_AUDPLY_PLAY_ANIMATION,SCR_ID_AUDPLY_PLAY_ANIMATION);
                }
            }
            break;
        case MDI_AUDIO_DRM_TIMEOUT:
            single_play_state = STATE_IDLE;
            StopTimer(AUDPLY_SINGLE_PLAY_TIMER);
            mmi_audply_do_single_stop_action();
            mmi_audply_display_popup(result, NULL, NULL);
            if (mmi_frm_group_is_present(GRP_ID_AUDPLY_PLAY_ANIMATION))
            {
                mmi_frm_scrn_close(GRP_ID_AUDPLY_PLAY_ANIMATION,SCR_ID_AUDPLY_PLAY_ANIMATION);
            }
            break;
        default:
            single_play_state = STATE_IDLE;
            StopTimer(AUDPLY_SINGLE_PLAY_TIMER);
            mmi_audply_display_popup(result, NULL, NULL);
            if (mmi_frm_group_is_present(GRP_ID_AUDPLY_PLAY_ANIMATION))
            {
                mmi_frm_scrn_close(GRP_ID_AUDPLY_PLAY_ANIMATION,SCR_ID_AUDPLY_PLAY_ANIMATION);
            }
            break;
    }
}
#endif/*__MMI_FILE_MANAGER__*/
#endif /*__MMI_MEDIA_PLAYER_AUDIO__*/
