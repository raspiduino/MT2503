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
*  AudioPlayerSrc.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Audio player main program
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

#if defined(__MMI_AUDIO_PLAYER__)

#if defined(__MMI_AUDIO_PLAYER_BT__)
#include "mmi_rp_app_audio_player_bt_def.h"
#endif

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif 

#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif

#ifdef __MMI_BACKGROUND_CALL__
#include "UCMGProt.h"
#endif

#include "CommonScreens.h"
#include "FileManagerGProt.h"
#include "UCMSrvGProt.h"
#include "wapadp.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "AudioPlayerDef.h"
#include "AudioPlayerPlayList.h"
#include "AudioPlayerType.h"
#include "AudioPlayerProt.h"
#include "AudioPlayerMainScreen.h"
#include "AudioPlayerResDef.h"
#include "menucuigprot.h"
#include "Mmi_frm_scenario_gprot.h"
#include "Filemgrsrvgprot.h"
#include "Gui_touch_feedback.h"
#include "fs_type.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "mmi_media_app_trc.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "fs_func.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "wgui_categories_util.h"
#include "stack_config.h"
#include "fs_errcode.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "AlertScreen.h"
#include "wgui_categories_list.h"
#include "mmi_rp_app_audioplayer_def.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_timer_gprot.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "gui.h"
#include "device.h"
#include "mmi_rp_file_type_def.h"
#include "FileMgrType.h"
#include "SimCtrlSrvGprot.h"
#include "BootupSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "Drm_gprot.h"
#include "Wgui_categories_multimedia.h"
#include "Wgui_asyncdynamic_menus.h"
#include "gpiosrvgprot.h"
#include "IdleGprot.h"

#ifdef __DRM_SUPPORT__
extern void mdi_audio_drm_disable_consume_count(void);
extern kal_char *DRM_get_content_ext(FS_HANDLE input, kal_wchar *path);
#endif /* __DRM_SUPPORT__ */ 

#ifdef __MMI_AUDIO_PLAYER_BT__
extern void mmi_bt_music_launch_dev_list(MMI_ID parent_gid);
#endif

#ifdef __MMI_AVRCP_SUPPORT__
#include "BtcmSrvGprot.h"
#include "BTMMIAVRCPGProt.h"
#endif /* __MMI_AVRCP_SUPPORT__ */

#ifdef __MMI_A2DP_SUPPORT__
#include "av_bt.h"
#endif  /* __MMI_A2DP_SUPPORT__ */

#ifdef __DM_LAWMO_SUPPORT__
#include "Dmuigprot.h"
#endif

#ifdef __MMI_NCENTER_SUPPORT__
#include "..\venusmmi\app\common\ncenter\Vsrv_ncenter.h"
#endif

#ifdef __MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__
#include "lyrics_parser.h"
#endif/*__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__*/
/*
**  Audio player code source.
*/
/* 
**  This variable is used to avoid repeating on a short file
**  too quick and cause a result to block other commands.
**  only set as true while play_completed with button down.
*/
MMI_BOOL g_mmi_audply_play_completed_after_button_down = MMI_FALSE;

/* 
**  indicate if audply just undergo longpressing so that 
**  the button up handler shall take different action.
*/
MMI_BOOL g_mmi_audply_longpressed = MMI_FALSE;

/* indicate if the state before longpress is STATE_PLAY */
//MMI_BOOL g_mmi_audply_non_play_longpressed = MMI_FALSE;

MMI_BOOL g_mmi_audply_init_done = MMI_FALSE;

#if defined(__MMI_AUDIO_PLAYER_BT__)
extern MMI_BOOL g_is_launch_from_bt;
extern MMI_BOOL g_is_enter_local_list; 
#endif

/* main control object */
audply_struct g_audply;
U32 audio_build_cache_progress = 0;
U32 g_mmi_audply_seek_target_time = 0; /*progress seeking target time*/
extern mmi_audply_playlist_cntx_struct list_cntx;
void mmi_audply_press_prev_next_button_up(U32 button_type);

#ifdef __MTK_TARGET__
__align(4)
#endif /* __MTK_TARGET__ */
U8 audio_cache[BUILD_CACHE_SIZE];
extern S16 g_audply_main_selected_button;   /* defined in AudioPlayerMainScreen.c */
extern MMI_BOOL g_audply_main_selected_button_down;     /* defined in AudioPlayerMainScreen.c */
extern void (*RedrawCategoryFunction) (void);   /* defined in wgui_categories.c */

#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
extern MMI_BOOL need_refresh_list;
extern MMI_BOOL need_reload_list;
#endif  /* __MMI_AUDIO_PLAYER_SINGLE_LIST__ */

extern audply_skin_struct g_audply_skins[NO_OF_SKIN];   /* defined in resource_audply_skins.c */

#ifdef __MMI_A2DP_SUPPORT__
extern MMI_BOOL wait_open_bt;
#endif

#if  defined(__MMI_AUDIO_PLAYER_ANIMATION__)  || defined(__MMI_FTE_SUPPORT__) 
extern audply_main_animation_struct audply_main_animation;
#endif 

#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__)
extern audply_lyric_struct audply_lyric;
extern MMI_BOOL lyric_reEntry; 
extern MMI_BOOL lyric_parse_ok;
extern CHAR *g_mmi_lyric_str_buff;
#endif
#ifdef __MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__
extern lyrics_meta_struct*  g_audply_lyrics;
#endif

extern BOOL mmi_audply_background_callback_hdlr(mdi_result result, void *user_data);

/*******************************************************/
#define AUDPLY_STATIC_FUNCTION_PROTOTYPES

static void mmi_audply_app_pre_entry(void);
//modify for audio player bt , used in audioplayerbtnowplaying.c
void mmi_audply_entry_player_screen(void);
static void mmi_audply_exit_main(void);
static void mmi_audply_seeking_exit_main(void);
static mmi_ret mmi_audply_delete_history_hdlr(mmi_event_struct *in_param);
static void mmi_audply_update_progress_target_time(U32 old_duration);
static MMI_BOOL mmi_audply_update_total_duration_by_cache(void);

#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)
static void mmi_audply_entry_main_list(void);
static void mmi_audply_init_main_list_highlight_hdlr(void);
#endif  /* __MMI_AUDPLY_MULTIPLE_LIST__ */

#ifdef __MMI_AUDIO_PLAYER_BT__
static mmi_ret mmi_audply_select_proc(mmi_event_struct *evt);
void mmi_audply_entry_select(void);
#endif//__MMI_AUDIO_PLAYER_BT__

static mmi_ret mmi_audply_main_proc(mmi_event_struct *evt);
void mmi_audply_lsk_up_hdlr(void);
void mmi_audply_rsk_up_hdlr(void);

#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
void mmi_entry_audioply_pre_list(void);
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_button_canceled
 * DESCRIPTION
 *  to cancel key down action
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_press_button_canceled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_BUTTON_CANCELED);
    
    if (g_audply_main_selected_button == AUDPLY_MAIN_DISABLED ||
        g_audply_main_selected_button_down == MMI_FALSE)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_BUTTON_CHECK_FAIL);
        return;
    }
    g_audply_main_selected_button_down = MMI_FALSE;
    g_mmi_audply_play_completed_after_button_down = MMI_FALSE;
 
    /* update button display */
    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_main_buttons();
    }
}

#ifdef __MMI_AVRCP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_bt_avrcp_cmd_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  command         [IN]        
 *  key_press       [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_audply_bt_avrcp_cmd_hdlr(U8 command, mmi_avrcp_key_events key_events) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = MMI_AVRCP_CR_ACCEPT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_AVRCP_HDLR,command,key_events);

    if (!(g_audply.in_audio_player || g_audply.background_play))
    {
        return result;
    }

    /* Use popup to indicate received messages */
#ifdef __MMI_AVRCP_DEBUG__
    U8 display_buffer[80]; //bql: build error must happen if turn __MMI_AVRCP_DEBUG__ ON

    mmi_ucs2cpy((CHAR*)display_buffer, (CHAR*)GetString(mmi_bt_avrcp_util_get_cmd_string(command)));
    switch (key_events)
    {
        case MMI_AVRCP_KEY_UP :
            mmi_ucs2cat((CHAR*)display_buffer, (CHAR*)L"\n KEY UP\0");    
            break;
        case MMI_AVRCP_KEY_DOWN:
            mmi_ucs2cat((CHAR*)display_buffer, (CHAR*)L"\n KEY DOWN\0");
            break;
        case MMI_AVRCP_KEY_CANCELED:
            mmi_ucs2cat((CHAR*)display_buffer, (CHAR*)L"\n KEY CANCELED\0");    
            break;
        default:
            break;
    }
   
    if ((command == MMI_AVRCP_POP_PLAY ||
        command == MMI_AVRCP_POP_STOP ||
        command == MMI_AVRCP_POP_PAUSE ||
        command == MMI_AVRCP_POP_FORWARD ||
        command == MMI_AVRCP_POP_BACKWARD) &&
        g_audply.in_main_screen)
    {
        /* Do nothing */
    }
    else
    {
        mmi_popup_display((WCHAR*)((UI_string_type) display_buffer), MMI_EVENT_SUCCESS, NULL);
        goto avrcp_finish;
    }
#endif /* __MMI_AVRCP_DEBUG__ */
    
    if (g_audply.wait_next_with_pop_up == MMI_TRUE)
    {
         result = MMI_AVRCP_CR_REJECT;
         goto avrcp_finish;
    }
    
    {
        MMI_BOOL bg_suspend = MMI_FALSE;
        S32 order = -1;
        U8 empty = 0;

        bg_suspend = mdi_audio_is_background_play_suspended();
        order = mdi_audio_get_background_callback_order(MDI_BACKGROUND_APP_AUDPLY);
        empty = mdi_audio_get_background_callback_register_app_num();

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_FOUR_VALS,bg_suspend,empty,order,-1);

        if (bg_suspend || (order != 0 && empty != 0))
        {
            result = MMI_AVRCP_CR_REJECT;
            goto avrcp_finish;
        }
    }

#ifdef __DM_LAWMO_SUPPORT__
    if (TRUE == mmi_dmui_is_phone_lock())
    {
        result = MMI_AVRCP_CR_REJECT;
        goto avrcp_finish;
    }
#endif

    
    if (mmi_idle_is_active())
    {
    #ifdef __USB_IN_NORMAL_MODE__
        /* check is in mass storage mode */
        if (srv_usb_is_in_mass_storage_mode())
        {
            /* phone drive is exported, cant use this app, popup message in key up */
            if(key_events == MMI_AVRCP_KEY_UP)
            {
                mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            }
            result = MMI_AVRCP_CR_REJECT;
            goto avrcp_finish;
        }
    #endif /* __USB_IN_NORMAL_MODE__ */ 

        //bql: why need to intialize some of the variable while audio player not active?
        /* initialization after re-power on */
        if (!g_mmi_audply_init_done)
        {
            /* register mdi background handler */
            g_audply.wait_next = MMI_FALSE;
            g_audply.need_replay = MMI_FALSE;
            g_audply.in_list_screen = MMI_FALSE;
            g_audply.state = STATE_IDLE;
            g_mmi_audply_play_completed_after_button_down = MMI_FALSE;

            g_audply.present_list = mmi_audply_get_current_list_drv();
        }
        //bql: r u sure if the followed logic works well?
        //mmi_audply_playlist_generate_wait_screen_entry will display waiting only when GRP_ID_AUDPLY_MAIN is exist
    #if defined(__MMI_ADUPLY_SINGLE_LIST__)        
        if (!g_mmi_audply_init_done || !mmi_audply_playlist_is_valid())
        {
            // TODO: single special function call.
            mmi_audply_need_generate_playlist();
        }
    #elif defined(__MMI_AUDPLY_MULTIPLE_LIST__)
        if (!mmi_audply_playlist_is_valid())
        {
            result = MMI_AVRCP_CR_REJECT;
            goto avrcp_finish;
        }
    #endif

        if (!g_mmi_audply_init_done)
        {
            g_audply_main_selected_button_down = MMI_FALSE;
            if (mmi_audply_playlist_is_empty())
            {
                g_audply_main_selected_button = AUDPLY_MAIN_DISABLED;
            }
            else
            {
                g_audply_main_selected_button = AUDPLY_MAIN_STOP;
            }
        }
        g_mmi_audply_init_done = MMI_TRUE;

        //bql: already check this condition in advanced!

     }
    else if (!g_audply.in_main_screen && !(g_mmi_audply_init_done))
    {
        result = MMI_AVRCP_CR_REJECT;
        goto avrcp_finish;
    }

    if (key_events == MMI_AVRCP_KEY_CANCELED)
    {
        switch (command)
        {
            case MMI_AVRCP_POP_PLAY:
            case MMI_AVRCP_POP_STOP:
            case MMI_AVRCP_POP_PAUSE:
            case MMI_AVRCP_POP_FORWARD:
            case MMI_AVRCP_POP_BACKWARD:
                mmi_audply_press_button_canceled();
                break;
            default :
                break;
        }
        /*the return value do not mean anything in key canceled event*/
        result = MMI_AVRCP_CR_REJECT;
        goto avrcp_finish;
    }

    if (g_audply.filefullname[0] == 0 
        #if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
        || need_reload_list || need_refresh_list
        #endif
        )
    {
        result = MMI_AVRCP_CR_REJECT;
        goto avrcp_finish;
    }
    switch (command)
    {
        case MMI_AVRCP_POP_PLAY:
        case MMI_AVRCP_POP_PAUSE:
            if (key_events == MMI_AVRCP_KEY_UP)
            {
                mmi_audply_press_play_button_up();
            }
            else if (key_events == MMI_AVRCP_KEY_DOWN)
            {
                mmi_audply_press_play_button_down();
            }
            break;

        case MMI_AVRCP_POP_STOP:
            if (key_events == MMI_AVRCP_KEY_UP)
            {
                mmi_audply_press_stop_button_up();
            }
            else if (key_events == MMI_AVRCP_KEY_DOWN)
            {
                mmi_audply_press_stop_button_down();
            }
            break;

        case MMI_AVRCP_POP_FORWARD:
            if (key_events == MMI_AVRCP_KEY_UP)
            {
                mmi_audply_press_next_button_up();
            }
            else if (key_events == MMI_AVRCP_KEY_DOWN)
            {
                mmi_audply_press_next_button_down();
            }            
            else if (key_events == MMI_AVRCP_KEY_LONGPRESS)
            {
                if (GetActiveScreenId() == SCR_ID_AUDPLY_MAIN )
                {
                    mmi_audply_press_next_button_longpress();
                }
                else
                {
                    result = MMI_AVRCP_CR_REJECT;
                }
                
            }
            else
            {
                result = MMI_AVRCP_CR_REJECT;
            }
            break;

        case MMI_AVRCP_POP_BACKWARD:
            if (key_events == MMI_AVRCP_KEY_UP)
            {
                mmi_audply_press_prev_button_up();
            }
            else if (key_events == MMI_AVRCP_KEY_DOWN)
            {
                mmi_audply_press_prev_button_down();
            }
            else if (key_events == MMI_AVRCP_KEY_LONGPRESS)
            {
                if (GetActiveScreenId() == SCR_ID_AUDPLY_MAIN )
                {
                    mmi_audply_press_prev_button_longpress();
                }
                else
                {
                    result = MMI_AVRCP_CR_REJECT;
                }
                
            }
            else
            {
                result = MMI_AVRCP_CR_REJECT;
            }
            break;

        default:
            result = MMI_AVRCP_CR_NOT_IMPLEMENT;
            break;
    }

avrcp_finish:

#ifdef __MMI_AVRCP_DEBUG__
	return MMI_AVRCP_CR_ACCEPT;
#else
	return result;
#endif
    
}
#endif /* __MMI_AVRCP_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_read_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_read_settings(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValueSlim(NVRAM_AUDPLY_VOLUME, &g_audply.volume, DS_BYTE);
    g_audply.volume_nvram = g_audply.volume;
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)  
#ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
    ReadValueSlim(NVRAM_AUDPLY_LIST_AUTO_GEN, &g_audply.list_auto_gen, DS_BYTE);
#else
    g_audply.list_auto_gen = 0;
#endif
#endif /* __MMI_AUDIO_PLAYER_SINGLE_LIST__ */
    ReadValueSlim(NVRAM_AUDPLY_PREFER_LIST, &g_audply.preferred_list, DS_BYTE);
    if(!srv_fmgr_drv_is_valid((U8)(g_audply.preferred_list)))
    {
        if(srv_fmgr_drv_is_valid((U8)SRV_FMGR_PUBLIC_DRV))
        {
            g_audply.preferred_list = (U8)SRV_FMGR_PUBLIC_DRV;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_SETTINGS_READ_SETTINGS, g_audply.preferred_list, __LINE__);
        }
        else if(srv_fmgr_drv_is_valid((U8)SRV_FMGR_CARD_DRV))
        {
            g_audply.preferred_list = (U8)SRV_FMGR_CARD_DRV;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_SETTINGS_READ_SETTINGS, g_audply.preferred_list, __LINE__);
        }
        else if(srv_fmgr_drv_is_valid((U8)SRV_FMGR_CARD2_DRV))
        {
            g_audply.preferred_list = (U8)SRV_FMGR_CARD2_DRV;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_SETTINGS_READ_SETTINGS, g_audply.preferred_list, __LINE__);
        }
        else
        {
            g_audply.preferred_list = 0;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_SETTINGS_READ_SETTINGS, g_audply.preferred_list, __LINE__);
        }
    }
    ReadValueSlim(NVRAM_AUDPLY_SKIN, &g_audply.skin, DS_BYTE);
    ReadValueSlim(NVRAM_AUDPLY_REPEAT, &g_audply.repeat_mode, DS_BYTE);
    ReadValueSlim(NVRAM_AUDPLY_SHUFFLE, &g_audply.random_mode, DS_BYTE);
    ReadValueSlim(NVRAM_AUDPLY_BACKGROUND_PLAY, &g_audply.background_play, DS_BYTE);
	ReadValueSlim(NVRAM_AUDPLY_REMOVE_IN_PROCESS, &g_audply.remove_process, DS_BYTE);

#if (defined(__MMI_AUDIO_PLAYER_ON_SUBLCD__) || defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__) || defined(__MMI_VUI_LAUNCHER_KEY__))
    if(!g_audply.background_play)
    {
        g_audply.background_play = 1;
        WriteValueSlim(NVRAM_AUDPLY_BACKGROUND_PLAY, &g_audply.background_play, DS_BYTE);
    }
#endif

#ifdef __MMI_SLIM_AUDIO_PLAYER__
    if(g_audply.skin != 0)
    {
        g_audply.skin = 0;
        WriteValueSlim(NVRAM_AUDPLY_SKIN, &g_audply.skin, DS_BYTE);
    }
#endif

#ifdef __MMI_AUDIO_TIME_STRETCH__
    ReadValueSlim(NVRAM_AUDIO_SPEED_VALUE, &g_audply.speed, DS_SHORT);
    if (g_audply.speed == 0xFFFF)
    {
        g_audply.speed = MDI_AUDIO_SPEED_NORMAL;
        WriteValueSlim(NVRAM_AUDIO_SPEED_VALUE, &g_audply.speed, DS_SHORT);
    }
#endif /* __MMI_AUDIO_TIME_STRETCH__ */ 

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    ReadValueSlim(NVRAM_AUDPLY_SPECTRUM_DISPLAY_STYLE, &g_audply.spectrum_style, DS_BYTE);
    if (g_audply.spectrum_style > 2)    /* check does it out of range bcoz NVRAM data is incorrect or not initialized */
    {
        g_audply.spectrum_style = 1;
        WriteValueSlim(NVRAM_AUDPLY_SPECTRUM_DISPLAY_STYLE, &g_audply.spectrum_style, DS_BYTE);
    }   
#endif

#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
    ReadValueSlim(NVRAM_AUDPLY_LYRICS_DISPLAY, &g_audply.lyrics_display, DS_BYTE);
    if (g_audply.lyrics_display > 1)    /* check does it out of range bcoz NVRAM data is incorrect or not initialized */
    {
        g_audply.lyrics_display = 0;
        WriteValueSlim(NVRAM_AUDPLY_LYRICS_DISPLAY, &g_audply.lyrics_display, DS_BYTE);
    }    
#endif

#else /* __MTK_TARGET__ */ 
//bql: in Modis, we will not load values by NVRAM but by hardcode.
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
    g_audply.list_auto_gen = 0;
#endif
    g_audply.preferred_list = (U8)SRV_FMGR_PUBLIC_DRV;
    g_audply.volume = 4;
    g_audply.skin = 0;
    g_audply.repeat_mode = 0;
    g_audply.random_mode = 0;
    g_audply.background_play = 1;

#ifdef __MMI_AUDIO_TIME_STRETCH__
    g_audply.speed = MDI_AUDIO_SPEED_NORMAL;
    g_audply.speed_set_times = 0;
#endif /* __MMI_AUDIO_TIME_STRETCH__ */ 

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    g_audply.spectrum_style = 1;
#endif

#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
    g_audply.lyrics_display = 0;
#endif

#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_write_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_write_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValueSlim(NVRAM_AUDPLY_VOLUME, &g_audply.volume, DS_BYTE);
    g_audply.volume_nvram = g_audply.volume;
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__) && defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__)   
    WriteValueSlim(NVRAM_AUDPLY_LIST_AUTO_GEN, &g_audply.list_auto_gen, DS_BYTE);
#endif /* __MMI_AUDIO_PLAYER_SINGLE_LIST__ */
    WriteValueSlim(NVRAM_AUDPLY_PREFER_LIST, &g_audply.preferred_list, DS_BYTE);
#ifndef __MMI_SLIM_AUDIO_PLAYER__  
    WriteValueSlim(NVRAM_AUDPLY_SKIN, &g_audply.skin, DS_BYTE);
#endif
    WriteValueSlim(NVRAM_AUDPLY_REPEAT, &g_audply.repeat_mode, DS_BYTE);
    WriteValueSlim(NVRAM_AUDPLY_SHUFFLE, &g_audply.random_mode, DS_BYTE);
#if (!defined(__MMI_AUDIO_PLAYER_ON_SUBLCD__) && !(defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__)||defined(__MMI_VUI_LAUNCHER_KEY__)))
    WriteValueSlim(NVRAM_AUDPLY_BACKGROUND_PLAY, &g_audply.background_play, DS_BYTE);
#endif

#ifdef __MMI_AUDIO_TIME_STRETCH__
    WriteValueSlim(NVRAM_AUDIO_SPEED_VALUE, &g_audply.speed, DS_SHORT);
#endif 

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    WriteValueSlim(NVRAM_AUDPLY_SPECTRUM_DISPLAY_STYLE, &g_audply.spectrum_style, DS_BYTE);
#endif

#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
    WriteValueSlim(NVRAM_AUDPLY_LYRICS_DISPLAY, &g_audply.lyrics_display, DS_BYTE);
#endif
}

#ifdef __DM_LAWMO_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_lawmo_lock_callback
 * DESCRIPTION
 *  This is the callback handler for the MO type of LAWMO lock.
 * PARAMETERS
 *  app_id      : [IN]      App ID
 *  cmd         : [IN]      Command
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_lawmo_lock_callback(
                mmi_dmui_app_id_enum app_id,
                mmi_dmui_cmd_enum cmd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (app_id == MMI_DMUI_APP_ID_AUDPLY)
    {
        switch (cmd)
        {
            case MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK:
            {    
                if(!g_audply.in_audio_player)
                {
                    mmi_audply_stop_playing();
                }
                mmi_dmui_lawmo_report(app_id, cmd, MMI_DMUI_RESULT_SUCCESS);                
                break;
            }
            
            case MMI_DMUI_CMD_LAWMO_UNLOCK:
            {
                mmi_dmui_lawmo_report(app_id, cmd, MMI_DMUI_RESULT_SUCCESS);    
                break;
            }

            default:
                break;
        }
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_delete_history_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_param        [?]     
 * RETURNS
 *  U8
 *****************************************************************************/
static mmi_ret mmi_audply_delete_history_hdlr(mmi_event_struct *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (in_param->evt_id)
    {
        case EVT_ID_SCRN_DEINIT :
        {
#ifdef __MMI_NCENTER_SUPPORT__

#endif
			
#ifdef __DM_LAWMO_SUPPORT__
            if (TRUE == mmi_dmui_is_phone_lock())
            {
                mmi_audply_stop_playing();
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_AUDPLY);
            }
            else
#endif
            if (!g_audply.background_play)
            {
                // There is a case that state = STATE_IDLE and need_replay = TRUE
                // and we need to prevent from replay after this function call by setting need_replay = FALSE
                g_audply.need_replay = MMI_FALSE;
                mmi_audply_stop_playing();
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_AUDPLY);
                g_mmi_audply_longpressed = MMI_FALSE ;
            }
            else //background_play
            {
                if(g_audply.state == STATE_PLAY || g_audply.wait_next == MMI_TRUE || g_audply.wait_next_with_pop_up == MMI_TRUE
#ifdef __MMI_A2DP_SUPPORT__
                    || mmi_audply_is_wait_open_bt()
#endif
                   )
                {
                    //bql: why clear all application background play except request application itself and POC 
                    //mdi_audio_clear_other_background_handler(MDI_BACKGROUND_APP_AUDPLY);
                }
                else
                {
                    if(g_audply.need_replay == MMI_FALSE)
                    {   /*during background call, press end key to stop call and entry idle screen,should not clear.*/
                    		mmi_audply_do_stop_action(MMI_FALSE);
                        mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_AUDPLY);
                    }
                }
            }
            g_audply.in_audio_player = MMI_FALSE;
			#ifdef __MMI_AUDPLY_WALK_PLAY__
			g_audply.walk.auto_walk_done = MMI_FALSE;
			#endif
        }
        break;
    default:
        break;
    }
    return MMI_RET_OK;

}

/*****************************************************************************
 * FUNCTION
 *  InitAudioPlayerApp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitAudioPlayerApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)
    mmi_audply_init_main_list_highlight_hdlr();
    mmi_audply_multiple_highlight_hdlr_init();
    mmi_audply_playlist_load_last_list();
#elif defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
    mmi_audply_single_highlight_hdlr_init();
#endif
    g_audply.wait_next_with_pop_up = MMI_FALSE;
    g_audply.state = STATE_IDLE;
    mmi_audply_read_settings();

#ifdef __MMI_A2DP_SUPPORT__
    av_bt_set_default_callback(mmi_audply_bt_open_callback);
#endif

#ifdef __MMI_AVRCP_SUPPORT__
    mmi_bt_avrcp_set_cmd_hdlr(mmi_audply_bt_avrcp_cmd_hdlr);
#endif 

#ifdef __DM_LAWMO_SUPPORT__
{
    mmi_dmui_result_enum result;
    result = mmi_dmui_lawmo_register_notify(
                MMI_DMUI_APP_ID_AUDPLY,
                MMI_DMUI_MO_TYPE_LAWMO_LOCK,
                mmi_audply_lawmo_lock_callback
                );
}
#endif

    mmi_audply_A2DP_spectrum_need_block();


#ifdef __MMI_AUDPLY_WALK_PLAY__
    mmi_audply_walk_init();
#endif  ///__MMI_AUDPLY_FS_HANDLE_PLAYLIST__

}



#if defined(__MMI_AUDIO_PLAYER_BT__) || defined(__MMI_BT_MUSIC__)

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_bt_music_disconnect_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_bt_music_disconnect_callback(MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result)
    {
        #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
        mmi_entry_audioply_pre_list();
        #else
        mmi_audply_entry_main();
        #endif
    }
}
#endif  //defined(__MMI_AUDIO_PLAYER_BT__) || defined(__MMI_BT_MUSIC__)


#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
static mmi_ret mmi_audioply_pre_list_proc(mmi_event_struct *evt)
{
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;
    switch(menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        	#ifdef __MMI_AUDPLY_WALK_PLAY__ 
            if (g_audply.play_style == AUDPLY_PLAY_STYLE_BY_FILE_ORDER)
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_AUDPLY_MY_SONGS, MMI_TRUE);
            }
            else
          #endif
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_AUDPLY_MY_SONGS, MMI_FALSE);
            }
            break;
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            if (menu_evt->highlighted_menu_id == MENU_ID_AUDPLY_MUSIC_PLAYER)
            {
                mmi_audply_app_pre_entry();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_AUDPLY_MY_SONGS)
            {            
                mmi_audply_playlist_entry_playlist();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_AUDPLY_SETTINGS)
            {                                
                mmi_audply_entry_settings();
            }
            break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}


void mmi_entry_audioply_pre_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id audioply_group_id;
    mmi_id cui_menu_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if defined(__MMI_AUDIO_PLAYER_BT__) || defined(__MMI_BT_MUSIC__)
    if (mmi_bt_music_check_connection())
    {
        mmi_bt_music_disconnect(mmi_audply_bt_music_disconnect_callback);
        //return;
    }
    #endif

    audioply_group_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUDPLY_MAIN_PRE_LIST, mmi_audioply_pre_list_proc, NULL);
    mmi_frm_group_enter(audioply_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_menu_id = cui_menu_create(audioply_group_id, 
                                  CUI_MENU_SRC_TYPE_RESOURCE,//CUI_MENU_SRC_TYPE_APPCREATE, 
                                  CUI_MENU_TYPE_APPSUB, 
                                  AUDIO_PLAYER_MAIN_PRE_LIST_MENUID, 
                                  MMI_FALSE, 
                                  NULL);

    cui_menu_run(cui_menu_id);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  HighlightAudioPlayer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightAudioPlayer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    SetLeftSoftkeyFunction(mmi_entry_audioply_pre_list, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_entry_audioply_pre_list,KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#else
    SetLeftSoftkeyFunction(mmi_audply_entry_main, KEY_EVENT_UP);
	//ChangeCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
	SetCenterSoftkeyFunction(mmi_audply_entry_main,KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_entry_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_AUDIO_PLAYER_BT__
    MMI_BOOL is_audply_playing = mmi_audply_is_playing();
    MMI_BOOL conn = mmi_bt_music_check_connection();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_LAUNCH, g_is_launch_from_bt);
    if(!g_is_launch_from_bt && !is_audply_playing && conn)
    {
        mmi_bt_music_launch_fn(GRP_ID_ROOT);
        return;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_ENTRY_LOCAL_AUDPLY);
#endif

#if defined(__MMI_BT_MUSIC__) || defined(__MMI_AUDIO_PLAYER_BT__)
    if (mmi_bt_music_check_connection())
    {
        mmi_bt_music_disconnect(mmi_audply_bt_music_disconnect_callback);
        //return;
    }
#endif//defined(__MMI_BT_MUSIC__) || defined(__MMI_AUDIO_PLAYER_BT__)

#ifdef __MMI_FTE_SUPPORT__
    gui_touch_feedback_disable_tone();
#endif
    mmi_audply_app_pre_entry();
}
	
#ifdef __MMI_AUDIO_PLAYER_BT__
static mmi_ret mmi_audply_select_proc(mmi_event_struct *evt)
{
    cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            //cui_menu_enable_tap_to_highlight(menu_evt->sender_id);
            cui_menu_set_currlist_left_softkey(menu_evt->sender_id, (UI_string_type)GetString(STR_GLOBAL_OK));
            cui_menu_set_currlist_right_softkey(menu_evt->sender_id, (UI_string_type)GetString(STR_GLOBAL_BACK));
            cui_menu_set_currlist_highlighted_id(menu_evt->sender_id, MENU_ID_AUDPLY_OPTION_LOCAL_LIST);
            break;
}
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            switch(menu_evt->highlighted_menu_id)
            {
                case MENU_ID_AUDPLY_OPTION_LOCAL_LIST :
                {
                    mmi_audply_playlist_entry_playlist();
                    break;
                }
                case MENU_ID_AUDPLY_OPTION_BT_MUSIC:
                {
                    mmi_bt_music_launch_fn(GRP_ID_ROOT);
                    break;
                }
                default:
                    break;
            }            
            break;
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(menu_evt->sender_id);
            break;
        }
        default:
            break;
    }
    return MMI_RET_OK;
}
void mmi_audply_entry_select(void)
{
    mmi_frm_group_create_ex(
        GRP_ID_AUDPLY_MAIN, 
        GRP_ID_AUDPLY_OPTION_WITH_BT, 
        mmi_audply_select_proc, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_menu_create_and_run(
        GRP_ID_AUDPLY_OPTION_WITH_BT, 
        CUI_MENU_SRC_TYPE_RESOURCE, 
        CUI_MENU_TYPE_APPSUB, 
        MENU_ID_AUDPLY_OPTION_CUI, 
        MMI_FALSE, 
        NULL);
}

#endif //__MMI_AUDIO_PLAYER_BT__

#ifdef __MMI_NCENTER_SUPPORT__

void mmi_audply_ncenter_close_app(void)
{
	mmi_audply_do_stop_action(MMI_TRUE); 
    /* USB plugin during generate. */

    if (mmi_frm_scrn_is_present(GRP_ID_AUDPLY_WAITSCREEN,SCR_ID_AUDPLY_WAITSCREEN,MMI_FRM_NODE_ALL_FLAG) || SCR_ID_AUDPLY_WAITSCREEN == mmi_frm_scrn_get_active_id())
    {
        mmi_frm_scrn_close_active_id();
        mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN);
        mmi_frm_group_close(GRP_ID_AUDPLY_LIST_BROWSER);
        mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);
    }
	mmi_audply_clear_play_seconds();
	mmi_audply_ncenter_close();

}

void mmi_audply_ncenter_close(void)
{
	if(g_audply.ghandle && g_audply.nhandle)
	{
		vsrv_ncenter_close_notification(g_audply.nhandle);
		vsrv_ncenter_close_ngroup(g_audply.ghandle);
		g_audply.ghandle = 0;
		g_audply.nhandle = 0;
	}
}

void mmi_audply_ncenter_callback(vsrv_notification_handle handle, vsrv_nintent intent, void* userData, U32 userDataSize)
{
    if (intent.type == VSRV_NINTENT_TYPE_LAUNCH)
    {
	mmi_audply_app_pre_entry();
    }
    else if(intent.type == VSRV_NINTENT_TYPE_TERMINATE)
    {
	mmi_audply_ncenter_close_app();
    }
}

void mmi_audply_ncenter_open(void)
{
    vsrv_ngroup_handle ghandle;
	vsrv_notification_handle nhandle;
	if(g_audply.ghandle == 0 && g_audply.nhandle == 0)
    {
	    ghandle = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE, GRP_ID_AUDPLY_MAIN);
    	nhandle = vsrv_ncenter_create_notification(VSRV_NOTIFICATION_TYPE_ONGOING, ghandle, 0);
		g_audply.ghandle = ghandle;
		g_audply.nhandle = nhandle;
	}
	
	vsrv_ncenter_set_ngroup_title_id(g_audply.ghandle,STR_ID_AUDPLY_TITLE);
	vsrv_ncenter_set_notification_maintext_str(g_audply.nhandle, g_audply.title);
	vsrv_ncenter_set_notification_intent_callback(g_audply.nhandle, mmi_audply_ncenter_callback, NULL, 0);
	vsrv_ncenter_set_notification_questiontext_id(g_audply.nhandle,STR_ID_AUDPLY_INQ_CLOSE_APP);
	vsrv_ncenter_notify_notification(g_audply.nhandle);
}

void mmi_audply_ncenter_update(void)
{
	vsrv_ncenter_set_notification_maintext_str(g_audply.nhandle, g_audply.title);
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_app_pre_entry
 * DESCRIPTION
 *  pre-entry of audio player. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_app_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__) && defined(__MMI_BACKGROUND_CALL__)
    if(srv_ucm_is_background_call())
    {
        mmi_ucm_entry_error_message();
        return;
    }
#endif
    /* Check if in USB mode before enter app */
#if defined(__USB_IN_NORMAL_MODE__)
    if (srv_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* defined(__USB_IN_NORMAL_MODE__) */ 

/* check the status of current driver which loading list saved. */
    if (FS_GetDevStatus(mmi_audply_get_current_list_drv(), FS_FEATURE_STATE_ENUM) == FS_DEVICE_BUSY)
    {
        mmi_popup_display_ext(
            (srv_fmgr_fs_error_get_string_and_popup_type(FS_DEVICE_BUSY, 0)), 
            (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(FS_DEVICE_BUSY), 
            NULL);
         
       return;
    }
    if (FS_GetDevStatus(SRV_FMGR_PUBLIC_DRV, FS_MOUNT_STATE_ENUM) < FS_NO_ERROR)
    {
    #if defined(__MMI_AUDIO_PLAYER_BT__)
        if(g_is_launch_from_bt)
        {
            g_is_launch_from_bt = MMI_FALSE;
        }
        else
        {
        mmi_bt_music_launch_fn(GRP_ID_ROOT);
            return;
        }
        #endif
       mmi_popup_display_ext(
        STR_GLOBAL_INSERT_MEMORY_CARD, 
        (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(FS_MEDIA_CHANGED), 
        NULL);
       return;
    }
    #if defined(__MMI_AUDIO_PLAYER_BT__)
    g_is_launch_from_bt = MMI_FALSE;
	g_is_enter_local_list = MMI_TRUE;
    #endif
    
	if (!(FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) < FS_NO_ERROR))
    {
    	if(g_audply.remove_process)
		{
			kal_wsprintf(list_cntx.current_list.path, "%c:\\", SRV_FMGR_CARD_DRV);
    		mmi_ucs2cat((CHAR*)list_cntx.current_list.path, (CHAR*)MMI_AUDPLY_DEFAULT_PATH);
			if (mmi_audply_playlist_remove_all())
		    {
		        mmi_audply_playlist_reset_ui_cntx();
		       
		    }
			g_audply.remove_process = 0;
			WriteValueSlim(NVRAM_AUDPLY_REMOVE_IN_PROCESS, &g_audply.remove_process, DS_BYTE);
		}
       // g_mmi_audply_init_done = MMI_FALSE;
	}
    if(!g_mmi_audply_init_done)
    {
        mmi_audply_playlist_module_init();
    }
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
    mmi_audply_entry_player_screen();
    #ifdef __MMI_AUDIO_PLAYER_BT__
    if(mmi_frm_group_is_present(GRP_ID_BT_MUSIC_APP))
    {
        mmi_frm_group_close(GRP_ID_BT_MUSIC_APP);
    }
    #endif
#elif defined(__MMI_AUDPLY_MULTIPLE_LIST__)
    /* always entry main list screen. */
    mmi_audply_entry_main_list();   
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_main_button_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_update_main_button_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_audply_main_selected_button_down = MMI_FALSE;

    /* need to check current condition */
    if (
        #ifdef __MMI_AUDPLY_WALK_PLAY__
        g_audply.play_style == AUDPLY_PLAY_STYLE_BY_PLAYLIST &&
        #endif  //__MMI_AUDPLY_WALK_PLAY__
        mmi_audply_playlist_is_empty() && 
       (g_audply.state == STATE_IDLE && !g_mmi_audply_longpressed))
    {
        g_audply_main_selected_button = AUDPLY_MAIN_DISABLED;
    }
    else
    {
        g_audply_main_selected_button = AUDPLY_MAIN_PLAY;
    }
}


#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
/* For KEY_DOWN_ARROW long press event:
down: not draw any icon
long: free next icon, inc volum
repeat: inc volum
up: if is down--up, draw next icon
*/
void mmi_audply_update_down_arrow_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_audply_main_selected_button == AUDPLY_MAIN_DISABLED)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_BUTTON_CHECK_FAIL);
        return;
    }

    /* change selected button & update state */
    g_audply_main_selected_button = AUDPLY_MAIN_PREV;
    g_audply_main_selected_button_down = MMI_FALSE;

    /* update button display */
    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_main_buttons();
    }

    mmi_audply_press_dec_volume_down();
}

/* For KEY_UP_ARROW long press event:
down: draw prev down icon
long: free prev icon, dec volum
repeat: dec volum
up: 
*/
void mmi_audply_update_up_arrow_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_audply_main_selected_button == AUDPLY_MAIN_DISABLED)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_BUTTON_CHECK_FAIL);
        return;
    }

    /* change selected button & update state */
    g_audply_main_selected_button = AUDPLY_MAIN_NEXT;
    g_audply_main_selected_button_down = MMI_FALSE;

    /* update button display */
    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_main_buttons();
    }

    mmi_audply_press_inc_volume_down();
}


void mmi_audply_press_prev_button_pre_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!g_audply_main_selected_button_down)
        return;

    /* update button display */
    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_main_buttons();
    }

    StartTimer(AUDPLY_DISPLAY_BUTTON_TIMER, 200, mmi_audply_press_prev_button_up);
}

void mmi_audply_press_next_button_pre_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!g_audply_main_selected_button_down)
        return;

    /* update button display */
    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_main_buttons();
    }

    StartTimer(AUDPLY_DISPLAY_BUTTON_TIMER, 200, mmi_audply_press_next_button_up);
}


#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_update_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifndef __MMI_AUDIO_PLAYER_SKIN_SLIM__
    audply_skin_struct *skin_p;
    FuncPtr button_press_hdlr[] = 
    {
        mmi_audply_press_play_button_down,  /* AUDPLY_MAIN_PLAY */
        mmi_audply_press_prev_button_down,  /* AUDPLY_MAIN_PREV */
        mmi_audply_press_next_button_down,  /* AUDPLY_MAIN_NEXT */
        mmi_audply_press_stop_button_down   /* AUDPLY_MAIN_STOP */
    };
    FuncPtr button_release_hdlr[] = 
    {
        mmi_audply_press_play_button_up,    /* AUDPLY_MAIN_PLAY */
        mmi_audply_press_prev_button_up,    /* AUDPLY_MAIN_PREV */
        mmi_audply_press_next_button_up,    /* AUDPLY_MAIN_NEXT */
        mmi_audply_press_stop_button_up     /* AUDPLY_MAIN_STOP */
    };
    #endif 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_audply_update_main_button_flag();

    /* show main screen */
    //mmi_audply_show_mainscreen(STR_ID_AUDPLY_TITLE, STR_GLOBAL_LIST, STR_GLOBAL_BACK, g_audply.skin);
#ifdef __MMI_MAINLCD_96X64__

	if(g_audply.filefullname[0] == 0)
	{
		ShowCategory223Screen(
                    STR_ID_AUDPLY_TITLE,
                    0,
                    STR_GLOBAL_LIST,
                    0,
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,
                    IMG_ID_AUDPLY_PLAY_ANIMATION,
                    0,
                    g_audply.new_play_time/4.615,
                    NULL);
	}
	else
	{
		ShowCategory223Screen_ext(
                    g_audply.title,
                    0,
                    STR_GLOBAL_LIST,
                    STR_GLOBAL_BACK,
                    IMG_ID_AUDPLY_PLAY_ANIMATION,
                    0,
                    g_audply.new_play_time/4.615,
                    NULL);
	}
#else

    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__    
        if (g_audply.state == STATE_PLAY && !g_audply.wait_next)
        {
            mmi_audply_show_mainscreen(STR_ID_AUDPLY_TITLE, STR_GLOBAL_PAUSE, STR_GLOBAL_BACK, g_audply.skin);            
        }
        else    /* g_audply.state == STATE_IDLE  ||  (g_audply.state == STATE_PAUSED) */
        {                   
            mmi_audply_show_mainscreen(STR_ID_AUDPLY_TITLE, STR_GLOBAL_PLAY, STR_GLOBAL_BACK, g_audply.skin);            
        }        
        SetKeyHandler(mmi_audply_press_play_button_down, KEY_LSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_audply_press_play_button_up, KEY_LSK, KEY_EVENT_UP);
    #elif defined(__MMI_AUDIO_PLAYER_BT__)
        mmi_audply_show_mainscreen(STR_ID_AUDPLY_TITLE, STR_GLOBAL_OPTIONS, STR_GLOBAL_BACK, g_audply.skin);
    #else
    mmi_audply_show_mainscreen(STR_ID_AUDPLY_TITLE, STR_GLOBAL_LIST, STR_GLOBAL_BACK, g_audply.skin);
    #endif

#endif /* __MMI_MAINLCD_96X64__ */ 
#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    /* re print lyric, or it will  only be written while next lyric time tag is reached. */
    if (g_audply.lyrics_display &&
        g_audply.state != STATE_IDLE &&
        mmi_audply_is_lyrics_valid())
    {
#ifndef __MMI_AUDIO_PLAYER_LYRIC_SCREEN_BASED_ASM__
        U8 new_encoding_type = PhnsetGetDefEncodingType();
        if (audply_lyric.lrc_encoding_chset != new_encoding_type)   
        {
            lyric_parse_ok = mmi_audply_init_lyric();
        }
#else
        lyric_parse_ok = mmi_audply_init_lyric();
#endif /* __MMI_AUDIO_PLAYER_LYRIC_SCREEN_BASED_ASM__ */
        mmi_audply_lyric_on_time();
    }
#elif defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
    if (g_audply.lyrics_display &&
        mmi_audply_is_lyrics_valid())
    {
	mmi_audply_prepare_lyrics();
	if(g_audply.state == STATE_PLAY && g_audply_lyrics != NULL)
	{
		mmi_audply_update_lyrics_on_time();	
	}

    }
#endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 

#ifdef __MMI_BACKGROUND_CALL__
    if( srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 ||
        srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 ||
        srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL))
    {
        /* register RSK hanlders */
        SetKeyUpHandler(mmi_frm_scrn_close_active_id, KEY_RSK);

        /* register volume inc, dec handlers */
        SetKeyDownHandler(mmi_audply_press_inc_volume_down, KEY_VOL_UP);
    	SetKeyUpHandler(mmi_audply_press_inc_volume_up, KEY_VOL_UP);
        SetKeyDownHandler(mmi_audply_press_dec_volume_down, KEY_VOL_DOWN);
    	SetKeyUpHandler(mmi_audply_press_dec_volume_up, KEY_VOL_DOWN);

        SetKeyDownHandler(mmi_audply_press_inc_volume_down, KEY_POUND);
        SetKeyUpHandler(mmi_audply_press_inc_volume_up, KEY_POUND);
        SetKeyDownHandler(mmi_audply_press_dec_volume_down, KEY_STAR);
        SetKeyUpHandler(mmi_audply_press_dec_volume_up, KEY_STAR);



    #ifdef __MMI_TOUCH_SCREEN__
        mmi_pen_register_down_handler(mmi_audply_pen_down_hdlr);
        mmi_pen_register_up_handler(mmi_audply_pen_up_hdlr);
        mmi_pen_register_move_handler(mmi_audply_pen_move_hdlr);
        mmi_pen_register_abort_handler(mmi_audply_pen_abort_hdlr);
        mmi_pen_register_repeat_handler(mmi_audply_pen_repeat_hdlr);
        mmi_pen_register_long_tap_handler(mmi_audply_pen_long_tap_hdlr);
    #endif /* __MMI_TOUCH_SCREEN__ */ 
        return;
    }
#endif

    /* register LSK, RSK hanlders */
#ifndef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    SetKeyUpHandler(mmi_audply_lsk_up_hdlr, KEY_LSK);
#endif
    SetKeyUpHandler(mmi_audply_rsk_up_hdlr, KEY_RSK);

    /* register play / pause, stop, prev, next button handlers */
    
#ifdef __MMI_AUDIO_PLAYER_SKIN_SLIM__
    /* click up */
#if !defined(__MMI_MAINLCD_96X64__) && defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__)

    SetKeyUpHandler(mmi_audply_press_play_button_up, KEY_CSK);
    SetKeyUpHandler(mmi_audply_press_prev_button_up, KEY_LEFT_ARROW);
    SetKeyUpHandler(mmi_audply_press_next_button_up, KEY_RIGHT_ARROW);
    SetKeyUpHandler(mmi_audply_press_repeat_button_up, KEY_UP_ARROW);
    SetKeyUpHandler(mmi_audply_press_shuffle_button_up, KEY_DOWN_ARROW);
    /* click down */
    SetKeyDownHandler(mmi_audply_press_play_button_down, KEY_CSK );
    SetKeyDownHandler(mmi_audply_press_prev_button_down, KEY_LEFT_ARROW);
    SetKeyDownHandler(mmi_audply_press_next_button_down, KEY_RIGHT_ARROW );
    SetKeyDownHandler(mmi_audply_press_repeat_button_down, KEY_UP_ARROW );
    SetKeyDownHandler(mmi_audply_press_shuffle_button_down, KEY_DOWN_ARROW);
    /* longpress */
    SetKeyHandler(mmi_audply_press_prev_button_longpress, KEY_LEFT_ARROW, KEY_EVENT_LONG_PRESS);
    SetKeyHandler(mmi_audply_press_next_button_longpress, KEY_RIGHT_ARROW, KEY_EVENT_LONG_PRESS);
#else/*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/
#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    SetKeyDownHandler(mmi_audply_press_prev_button_down, KEY_UP_ARROW);
	SetKeyDownHandler(mmi_audply_press_next_button_down, KEY_DOWN_ARROW);

    /* click up */
    SetKeyUpHandler(mmi_audply_press_prev_button_pre_up, KEY_UP_ARROW);
	SetKeyUpHandler(mmi_audply_press_next_button_pre_up, KEY_DOWN_ARROW);

    SetKeyHandler(mmi_audply_update_up_arrow_key_handler, KEY_UP_ARROW, KEY_LONG_PRESS);
    SetKeyHandler(mmi_audply_update_down_arrow_key_handler, KEY_DOWN_ARROW, KEY_LONG_PRESS);

    SetKeyHandler(mmi_audply_press_inc_volume_down, KEY_UP_ARROW, KEY_REPEAT);
    SetKeyHandler(mmi_audply_press_dec_volume_down, KEY_DOWN_ARROW, KEY_REPEAT);

    SetKeyHandler(mmi_idle_display, KEY_RSK, KEY_LONG_PRESS);
#else
SetKeyUpHandler(mmi_audply_press_play_button_up, KEY_UP_ARROW);
    SetKeyUpHandler(mmi_audply_press_prev_button_up, KEY_LEFT_ARROW);
    SetKeyUpHandler(mmi_audply_press_next_button_up, KEY_RIGHT_ARROW);
     /* click down */
    SetKeyDownHandler(mmi_audply_press_play_button_down, KEY_UP_ARROW);
    SetKeyDownHandler(mmi_audply_press_prev_button_down, KEY_LEFT_ARROW);
    SetKeyDownHandler(mmi_audply_press_next_button_down, KEY_RIGHT_ARROW);
    /* longpress */
    SetKeyHandler(mmi_audply_press_prev_button_longpress, KEY_LEFT_ARROW, KEY_EVENT_LONG_PRESS);
    SetKeyHandler(mmi_audply_press_next_button_longpress, KEY_RIGHT_ARROW, KEY_EVENT_LONG_PRESS);

#endif/*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/
#endif/*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/
#else
    skin_p = &g_audply_skins[g_audply.skin];
    SetKeyUpHandler(button_release_hdlr[skin_p->left_key_mapping], KEY_LEFT_ARROW);
    SetKeyUpHandler(button_release_hdlr[skin_p->right_key_mapping], KEY_RIGHT_ARROW);
    SetKeyUpHandler(button_release_hdlr[skin_p->up_key_mapping], KEY_UP_ARROW);
    SetKeyUpHandler(button_release_hdlr[skin_p->down_key_mapping], KEY_DOWN_ARROW);
    SetKeyDownHandler(button_press_hdlr[skin_p->left_key_mapping], KEY_LEFT_ARROW);
    SetKeyDownHandler(button_press_hdlr[skin_p->right_key_mapping], KEY_RIGHT_ARROW);
    SetKeyDownHandler(button_press_hdlr[skin_p->up_key_mapping], KEY_UP_ARROW);
    SetKeyDownHandler(button_press_hdlr[skin_p->down_key_mapping], KEY_DOWN_ARROW);

    /*register next / prev button long press handlers*/
    if (skin_p->left_key_mapping == AUDPLY_MAIN_PREV)
    {
        SetKeyHandler(mmi_audply_press_prev_button_longpress, KEY_LEFT_ARROW, KEY_EVENT_LONG_PRESS);
    }
    else if (skin_p->right_key_mapping == AUDPLY_MAIN_PREV)
    {
        SetKeyHandler(mmi_audply_press_prev_button_longpress, KEY_RIGHT_ARROW, KEY_EVENT_LONG_PRESS);
    }
    else if (skin_p->up_key_mapping == AUDPLY_MAIN_PREV)
    {
        SetKeyHandler(mmi_audply_press_prev_button_longpress, KEY_UP_ARROW, KEY_EVENT_LONG_PRESS);
    }
    else
    {
        SetKeyHandler(mmi_audply_press_prev_button_longpress, KEY_DOWN_ARROW, KEY_EVENT_LONG_PRESS);
    }

    if (skin_p->left_key_mapping == AUDPLY_MAIN_NEXT)
    {
        SetKeyHandler(mmi_audply_press_next_button_longpress, KEY_LEFT_ARROW, KEY_EVENT_LONG_PRESS);
    }
    else if (skin_p->right_key_mapping == AUDPLY_MAIN_NEXT)
    {
        SetKeyHandler(mmi_audply_press_next_button_longpress, KEY_RIGHT_ARROW, KEY_EVENT_LONG_PRESS);
    }
    else if (skin_p->up_key_mapping == AUDPLY_MAIN_NEXT)
    {
        SetKeyHandler(mmi_audply_press_next_button_longpress, KEY_UP_ARROW, KEY_EVENT_LONG_PRESS);
    }
    else
    {
        SetKeyHandler(mmi_audply_press_next_button_longpress, KEY_DOWN_ARROW, KEY_EVENT_LONG_PRESS);
    }
#endif
        
#ifndef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    /* register volume inc, dec handlers */
    SetKeyDownHandler(mmi_audply_press_inc_volume_down, KEY_VOL_UP);
	SetKeyUpHandler(mmi_audply_press_inc_volume_up, KEY_VOL_UP);
    SetKeyDownHandler(mmi_audply_press_dec_volume_down, KEY_VOL_DOWN);
	SetKeyUpHandler(mmi_audply_press_dec_volume_up, KEY_VOL_DOWN);

    SetKeyDownHandler(mmi_audply_press_inc_volume_down, KEY_POUND);
    SetKeyUpHandler(mmi_audply_press_inc_volume_up, KEY_POUND);
    SetKeyDownHandler(mmi_audply_press_dec_volume_down, KEY_STAR);
    SetKeyUpHandler(mmi_audply_press_dec_volume_up, KEY_STAR);
#endif
#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_register_down_handler(mmi_audply_pen_down_hdlr);
    mmi_pen_register_up_handler(mmi_audply_pen_up_hdlr);
    mmi_pen_register_move_handler(mmi_audply_pen_move_hdlr);
    mmi_pen_register_abort_handler(mmi_audply_pen_abort_hdlr);    
    #ifndef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    mmi_pen_register_repeat_handler(mmi_audply_pen_repeat_hdlr);
    mmi_pen_register_long_tap_handler(mmi_audply_pen_long_tap_hdlr);
    #endif
#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_register_volume_sync_callback(APP_AUDIOPLAYER,MDI_AUD_VOL_LEVEL_EXTEND_MUTE,mmi_audply_handfree_volume_sync_callback);
#endif

}

#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
static void mmi_audply_main_screen_init_single(void)
{
    /* register mdi background handler */
    g_audply.wait_next = MMI_FALSE;
    g_audply.need_replay = MMI_FALSE;
    g_audply.in_list_screen = MMI_FALSE;
    g_audply.state = STATE_IDLE;
    g_mmi_audply_play_completed_after_button_down = MMI_FALSE;
    /*initialize cache*/
    mmi_audply_initialize_cache();
#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    lyric_reEntry = MMI_TRUE; 
#endif
        
    mmi_audply_playlist_reset_ui_cntx();
    if (FS_GetDevStatus(g_audply.preferred_list, FS_MOUNT_STATE_ENUM) < FS_NO_ERROR)
    {
        g_audply.present_list = (U8)SRV_FMGR_PUBLIC_DRV;
    }
    else
    {
        g_audply.present_list = g_audply.preferred_list;
    }

    mmi_audply_playlist_set_default_playlist_path();
    /* check default playlist. */
    if (!g_audply.list_auto_gen && mmi_audply_playlist_is_valid())
    {
    #ifndef __MMI_AUDPLY_WALK_PLAY__   //Remove empty popup
        mmi_audply_need_load_playlist();
	#endif
    }
    mmi_audply_update_main();

    /* run SSE */
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
    gui_screen_switch_effect_run();    
#endif

    g_audply.in_main_screen = MMI_TRUE;
    g_mmi_audply_init_done = MMI_TRUE;
    #ifdef __MMI_AUDPLY_PLAYLIST_GEN_ASYN__
    if (!g_audply.is_reenter || g_audply.list_auto_gen || !mmi_audply_playlist_is_valid())
    {
        g_audply.is_reenter = MMI_TRUE;
    #else  //__MMI_BTD_BOX_UI_STYLE__
    if (g_audply.list_auto_gen || !mmi_audply_playlist_is_valid())
    {
    #endif  //__MMI_BTD_BOX_UI_STYLE__
	#ifndef __MMI_AUDPLY_WALK_PLAY__   //Remove empty popup
        mmi_audply_need_generate_playlist();
	#endif
    }
    
#if defined( __MMI_VUI_HOMESCREEN_AUDIO_PLAYER__) || defined(__MMI_VUI_LAUNCHER_KEY__)
    if(g_audply.widget_callback != NULL)
    {
        g_audply.widget_callback(g_audply.widget_callback_userdata, MMI_WIDGET_PLAYER_STATUS_CHANGE_CALLBACK, NULL);
    }
#endif

#ifdef __MMI_AUDPLY_PLAYLIST_GEN_ASYN__
    g_audply.is_reenter = MMI_TRUE;
#endif    
}
#endif  /* __MMI_AUDIO_PLAYER_SINGLE_LIST__ */


#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)
static void mmi_audply_main_screen_init_multiple(void)
{
    /* register mdi background handler */
    g_audply.wait_next = MMI_FALSE;
    g_audply.need_replay = MMI_FALSE;
    g_audply.in_list_screen = MMI_FALSE;
    g_audply.state = STATE_IDLE;
    g_mmi_audply_play_completed_after_button_down = MMI_FALSE;
    /*initialize cache*/
    mmi_audply_initialize_cache();
#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    lyric_reEntry = MMI_TRUE; 
#endif
    if (mmi_audply_playlist_is_valid())
    {
        mmi_audply_playlist_apply_picked_file();
    }
    mmi_audply_update_main();

    /* run SSE */
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
    gui_screen_switch_effect_run();    
#endif

    g_audply.in_main_screen = MMI_TRUE;
    g_mmi_audply_init_done = MMI_TRUE;

#if defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__)||defined(__MMI_VUI_LAUNCHER_KEY__)
    if(g_audply.widget_callback != NULL)
    {
        g_audply.widget_callback(g_audply.widget_callback_userdata, MMI_WIDGET_PLAYER_STATUS_CHANGE_CALLBACK, NULL);
    }
#endif

}
#endif  /* __MMI_AUDPLY_MULTIPLE_LIST__ */

static void mmi_audply_main_screen_init(void)
{
#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)
    mmi_audply_main_screen_init_multiple();
#else
    mmi_audply_main_screen_init_single();
#endif
#if 0//def __MMI_AUDPLY_WALK_PLAY__
/* under construction !*/
#endif  ///__MMI_AUDPLY_FS_HANDLE_PLAYLIST__
}

static void mmi_audply_main_screen_reentry(void)
{
#ifdef __MMI_AUDPLY_WALK_PLAY__
    if (g_audply.play_style == AUDPLY_PLAY_STYLE_BY_FILE_ORDER)
    {
        mmi_audply_update_main();
        /* run SSE */
        #ifdef __MMI_SCREEN_SWITCH_EFFECT__
        gui_screen_switch_effect_run();    
        #endif

        g_audply.in_main_screen = MMI_TRUE;
    }
    else
#endif  //__MMI_AUDPLY_WALK_PLAY__
{
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
    if (need_reload_list)
    {
        mmi_audply_need_load_playlist();
        need_reload_list = MMI_FALSE;
    }

    if (!mmi_audply_playlist_is_valid())
    {
        if (g_audply.state == STATE_IDLE)
        {
            mmi_audply_need_load_playlist();
        }
        else
        {
            /*
            ** when audio player playing an audio file, 
            ** and the play list file was deleted.
            ** audio player will play current file complete, 
            ** then clear the infomation of this file display in main screen.
            */
            mmi_audply_playlist_reset_ui_cntx();
            

        }
    }
#ifdef __DRM_SUPPORT__
     if (!mmi_audply_playlist_is_empty() && g_audply.state == STATE_IDLE && g_audply.new_play_time == 0)
     {
         S32 result = 0;
         result = mmi_audply_drm_valide_right((PU16)g_audply.filefullname);
         if(result == 1 && g_audply.duration != 0)
         {
             g_audply.seekable = MMI_TRUE;
         }
         else if(result ==2)
         {
             g_audply.seekable = MMI_FALSE;
         }
     }
#endif
     mmi_audply_update_main();

     /* run SSE */
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
     gui_screen_switch_effect_run();    
#endif

     g_audply.in_main_screen = MMI_TRUE;

     if (need_refresh_list)
     {
         mmi_audply_need_generate_playlist();
         need_refresh_list = MMI_FALSE;
     }
#else  /* __MMI_AUDIO_PLAYER_SINGLE_LIST__ */

    if (mmi_audply_playlist_is_empty() && g_audply.state == STATE_IDLE)
    {
        mmi_audply_playlist_apply_picked_file();
    }
#ifdef __DRM_SUPPORT__
    if (!mmi_audply_playlist_is_empty() &&
         g_audply.state == STATE_IDLE && g_audply.new_play_time == 0)
    {
        S32 result = 0;
        result = mmi_audply_drm_valide_right((PU16)g_audply.filefullname);
        if(result == 1 && g_audply.duration != 0)
        {
            g_audply.seekable = MMI_TRUE;
        }
        else if(result ==2)
        {
            g_audply.seekable = MMI_FALSE;
        }
    }
#endif
    mmi_audply_update_main();
    /* run SSE */
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
    gui_screen_switch_effect_run();    
#endif

    g_audply.in_main_screen = MMI_TRUE;
#endif
}
#ifdef __MMI_AUDIO_PLAYER_BT__
g_is_enter_local_list = MMI_TRUE;
#endif
}

#ifdef __MMI_AUDPLY_WALK_PLAY__
	//extern MMI_BOOL is_in_no_audio_popup;
    extern U8 Press_Prev;
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_entry_player_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_entry_player_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_ENTY_MAIN);

    //mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUDPLY_MAIN, mmi_audply_main_proc, (void*)NULL); 
    //mmi_frm_group_enter(GRP_ID_AUDPLY_MAIN, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    if(!mmi_frm_group_is_present(GRP_ID_AUDPLY_MAIN))
    {
    mmi_frm_group_create_ex(
    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
        GRP_ID_AUDPLY_MAIN_PRE_LIST,
    #else
        GRP_ID_ROOT, 
    #endif
        GRP_ID_AUDPLY_MAIN, 
        mmi_audply_main_proc, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }


#ifdef __MMI_BACKGROUND_CALL__
    if( srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 ||
        srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 ||
        srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL))
    {
        PU8 gui_buffer = NULL;

        gui_buffer = mmi_frm_scrn_get_gui_buf(GRP_ID_AUDPLY_MAIN,SCR_ID_AUDPLY_MAIN);

        if(gui_buffer == NULL)
        {
            mmi_ucm_app_entry_error_message();
            return;
        }
    }
#endif
#ifdef __DM_LAWMO_SUPPORT__
    if (TRUE == mmi_dmui_is_phone_lock())
    {
        PU8 gui_buffer = NULL;
       
        gui_buffer = mmi_frm_scrn_get_gui_buf(GRP_ID_AUDPLY_MAIN,SCR_ID_AUDPLY_MAIN);
        
        if(gui_buffer == NULL)
        {
            return;
        }
    }
#endif
    if (!mmi_frm_scrn_enter(
            GRP_ID_AUDPLY_MAIN,
            SCR_ID_AUDPLY_MAIN,
            mmi_audply_exit_main,
            mmi_audply_entry_player_screen,
            MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }



    if (g_audply.state == STATE_IDLE //need not stop all when state is pause.
        #ifdef __MMI_A2DP_SUPPORT__
        && wait_open_bt == MMI_FALSE
        #endif
        )
    {
        mdi_audio_stop_all();
    }
    mdi_audio_set_background_handler(MDI_BACKGROUND_APP_AUDPLY, mmi_audply_background_callback_hdlr, NULL);
    g_audply.in_audio_player = MMI_TRUE;
#ifdef  __MMI_TOUCH_SCREEN__
	mmi_pen_config_sampling_period(MMI_PEN_SAMPLING_PERIOD_2, MMI_PEN_SAMPLING_PERIOD_2);
#endif
    
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
/*    mmi_fe_set_antialias(MMI_FALSE);*/
#endif
    ClearKeyEvents();
    /*alloc screen based memory*/
#ifdef __MMI_AUDIO_PLAYER_LYRIC_SCREEN_BASED_ASM__
    g_mmi_lyric_str_buff = mmi_frm_scrmem_alloc(AUDPLY_LYRIC_STR_BUFF_MAX_SIZE);
#endif
#ifdef __MMI_AUDPLY_PLAYLIST_GEN_ASYN__
    if (g_audply.audio_cache_file_buf_p == NULL)
#endif
    g_audply.audio_cache_file_buf_p = mmi_frm_scrmem_alloc(BUILD_CACHE_FILE_BUF_SIZE);
#ifdef __MMI_AUDPLY_PLAYLIST_GEN_ASYN__
    if (g_audply.audio_cache_proc_buf_p == NULL)
#endif
    g_audply.audio_cache_proc_buf_p = mmi_frm_scrmem_alloc(BUILD_CACHE_PROC_BUF_SIZE);
#if !defined(__MMI_MAINLCD_240X400__) && !defined(__MMI_MAINLCD_320X480__)
    entry_full_screen();
#endif
    /* setup SSE */
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
    gui_screen_switch_effect_setup(0, 0, 0);    
#endif
    if (!g_mmi_audply_init_done)
    {
    	#ifdef __MMI_NCENTER_SUPPORT__
           g_audply.ghandle = 0;
		   g_audply.nhandle = 0;
		#endif
        mmi_audply_main_screen_init();
    }
    else
    {
        mmi_audply_main_screen_reentry();
    }

#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    mmi_audply_lyric_check_backlight(MMI_TRUE);
#endif 

#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
     mmi_frm_scrn_set_leave_proc(GRP_ID_AUDPLY_MAIN, SCR_ID_AUDPLY_MAIN, mmi_audply_delete_history_hdlr);
#endif
#ifdef __MMI_AUDPLY_PLAYLIST_GEN_ASYN__
    ReadValue(NVRAM_AUDPLY_VOLUME, &g_audply.volume, DS_BYTE, &error);
    g_audply.volume_nvram = g_audply.volume;
    if (g_audply.volume < 1)
    {
        g_audply.volume = 12;
        mdi_audio_set_volume(VOL_TYPE_MEDIA, (U8)(MDI_AUD_VOL_EX_MUTE(g_audply.volume)));
    }
    mmi_audply_press_play_button_down();
    mmi_audply_press_play_button_up();
#endif
#ifdef __MMI_AUDPLY_WALK_PLAY__
    if (g_audply.play_style == AUDPLY_PLAY_STYLE_BY_FILE_ORDER)
    {
        g_audply_main_selected_button = AUDPLY_MAIN_PLAY;
        if (!mmi_audply_is_playing())
        {
			if (!g_audply.walk.auto_walk_done && g_audply.filefullname[0] == 0)
            {
                mmi_audply_press_next_button_down();
                mmi_audply_press_next_button_up();
                g_audply.walk.auto_walk_done = MMI_TRUE;
            }
			else if(g_audply.filefullname[0] != 0)
			{
				if(mmi_walk_check_valid_file((CHAR *)g_audply.filefullname) == MMI_FALSE)
				{
					Press_Prev = 0;
					mmi_audply_press_next_button_down();
            		mmi_audply_press_next_button_up();
            		g_audply.walk.auto_walk_done = MMI_TRUE;
				}
			}
			need_refresh_list = MMI_FALSE;
			need_reload_list = MMI_FALSE;
			
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
		#endif      
        }
    }
#endif  //__MMI_AUDPLY_WALK_PLAY__
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_exit_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_exit_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_audply_seeking_exit_main();
    mmi_audply_exit_mainscreen();
    g_mmi_audply_play_completed_after_button_down = MMI_FALSE;
    g_audply_main_selected_button_down = MMI_FALSE;
    if(g_audply.state != STATE_PLAY && g_audply.volume_nvram != g_audply.volume)
    {
    WriteValueSlim(NVRAM_AUDPLY_VOLUME, &g_audply.volume, DS_BYTE);
        g_audply.volume_nvram = g_audply.volume;
    }
    WriteValueSlim(NVRAM_AUDPLY_REPEAT, &g_audply.repeat_mode, DS_BYTE);
    WriteValueSlim(NVRAM_AUDPLY_SHUFFLE, &g_audply.random_mode, DS_BYTE);

    /*free screen based memory*/
#ifdef __MMI_AUDIO_PLAYER_LYRIC_SCREEN_BASED_ASM__
    if (g_mmi_lyric_str_buff != NULL)
    {
        mmi_frm_scrmem_free(g_mmi_lyric_str_buff);
        g_mmi_lyric_str_buff = NULL ;
    }
#endif /*__MMI_AUDIO_PLAYER_LYRIC_SCREEN_BASED_ASM__*/
    if(g_audply.audio_cache_file_buf_p !=NULL)
    {
        mmi_frm_scrmem_free(g_audply.audio_cache_file_buf_p);
        g_audply.audio_cache_file_buf_p = NULL ;
    }
    if(g_audply.audio_cache_proc_buf_p!=NULL)
    {
        mmi_frm_scrmem_free(g_audply.audio_cache_proc_buf_p);
        g_audply.audio_cache_proc_buf_p = NULL ;
    }
#ifdef __MMI_NCENTER_SUPPORT__
	if(mmi_frm_is_in_backward_scenario && g_audply.state != STATE_PLAY)
	{
		mmi_audply_ncenter_close();
	}
#endif
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
/*    mmi_fe_set_antialias(MMI_TRUE);*/
#endif

#ifdef  __MMI_TOUCH_SCREEN__
	mmi_pen_config_sampling_period(MMI_PEN_SAMPLING_PERIOD_1, MMI_PEN_SAMPLING_PERIOD_2);
    ClearInputEventHandler(MMI_DEVICE_PEN);
#endif

#ifdef __BT_SPK_VOL_CONTROL__
    if(g_audply.state != STATE_PLAY)
    {
        mdi_audio_bt_clear_volume_sync_callback(APP_AUDIOPLAYER);
    }
#endif

   // mmi_frm_scrn_set_attribute(GRP_ID_AUDPLY_MAIN, SCR_ID_AUDPLY_MAIN, MMI_SCRN_ATTRIB_ADD_HISTORY);

    //GenericExitScreen(SCR_ID_AUDPLY_MAIN, mmi_audply_entry_player_screen);
#ifdef __MMI_FTE_SUPPORT__
	gui_touch_feedback_enable_tone();
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_main_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_audply_main_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
/*************************Menu CUI event***************************/
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_LIST_EXIT:
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            break;
                    
	#ifdef __MMI_AUDIO_PLAYER_BT__			
		case EVT_ID_GROUP_GOBACK:
		case EVT_ID_GROUP_GOBACK_IN_END_KEY:
		case EVT_ID_GROUP_EXIT:	
           g_is_enter_local_list = MMI_FALSE;
		    break;
	#endif /*__MMI_AUDIO_PLAYER_BT__*/
        
        default:
            break;
    }
    
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_seeking_exit_main
 * DESCRIPTION
 *  handle the exit main action in seeking process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_seeking_exit_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_SEEKING_EXIT_MAIN,g_mmi_audply_longpressed);
    if (g_mmi_audply_longpressed)
    {
        StopTimer(AUDPLY_SEEKING_TIMER);

        if (g_audply.need_to_build_cache)
        {
            /*stop budild cache*/
            mdi_audio_stop_build_cache();
        }
               
        if (g_audply.in_main_screen)
        {
           mmi_audply_redraw_main_buttons();
        }
        
        if(g_audply.state_before_longpress == STATE_PLAY)
        {
            g_audply.need_replay = MMI_FALSE; 
        }
        else
        {
            g_audply.state = g_audply.state_before_longpress;
        }
        
        g_mmi_audply_longpressed = MMI_FALSE;
    }

    // to release the two buffers cause they are using screen bassed memory
    mdi_audio_close_build_cache();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_clear_play_seconds
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_clear_play_seconds(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_audply.new_play_time = 0;
    g_audply.old_play_time = 0;
#ifdef __DRM_SUPPORT__
    g_audply.DRM_consumed = MMI_FALSE; 
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_get_play_seconds
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U32  the played time, the unit is MS
 *****************************************************************************/
U32 mmi_audply_get_play_seconds(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_audply.new_play_time;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_play_seconds
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_update_play_seconds(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    result = mdi_audio_get_progress_time(&g_audply.new_play_time); 
    if(result != MDI_AUDIO_SUCCESS)
    {
        return;
    }

#ifdef    __MMI_AUDIO_PLAYER_ON_SUBLCD__ 
    if(g_audply.in_sub_screen)
    {
        if(g_audply.new_play_time - g_audply.old_play_time > 500)
        {
        	UI_set_sub_LCD_graphics_context();
            mmi_audply_redraw_main_time();
	        UI_set_main_LCD_graphics_context();
            while (g_audply.old_play_time < g_audply.new_play_time - 500)
            {
                g_audply.old_play_time += 1000;
            }
            /*
            g_audply.old_play_time = g_audply.new_play_time;
            g_audply.old_play_time /= 1000;
            g_audply.old_play_time *= 1000;*/
        }
    }
#endif

    if (g_audply.in_main_screen)
    {
        if ((S32)g_audply.new_play_time - (S32)g_audply.old_play_time > 500) 
        {
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_UPDATE_TIME,g_audply.new_play_time ,g_audply.old_play_time,g_audply.new_play_time - g_audply.old_play_time);
            mmi_audply_redraw_main_time();
            while (g_audply.old_play_time < g_audply.new_play_time - 500)
            {
                g_audply.old_play_time += 1000;
            }
     /*   g_audply.old_play_time = g_audply.new_play_time;
            g_audply.old_play_time /= 1000;
            g_audply.old_play_time *= 1000;*/
        }
    #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
        if (g_audply.lyrics_display && mmi_audply_is_lyrics_valid())
        {
            mmi_audply_lyric_on_time();
        }
   #endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 
 #if !defined(__MMI_MAINLCD_96X64__)
        mmi_audply_redraw_main_progressbar();
#endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply.state == STATE_PLAY)
    {
        mmi_audply_update_play_seconds();
        StartTimer(AUDPLY_COUNT_PLAY_TIMER, 250, mmi_audply_timer);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_progress_target_time
 * DESCRIPTION
 *  update progress bar target time after duration updated
 * PARAMETERS
 *  U32     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_update_progress_target_time(U32 old_duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_audply_seek_target_time == old_duration)
    {
        g_mmi_audply_seek_target_time = g_audply.duration;
    }
#ifdef __MMI_TOUCH_SCREEN__    
    else if (g_mmi_audply_seek_target_time != 0 ) /*target time is in between 0 and old_duration*/
    {
        g_mmi_audply_seek_target_time = mmi_audply_get_proportional_time_from_x_ext();
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_total_duration_by_cache
 * DESCRIPTION
 *  update total duration by cache data
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL
 *****************************************************************************/
static MMI_BOOL mmi_audply_update_total_duration_by_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 duration;
    U32 old_duration = g_audply.duration;
    MMI_BOOL result = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_audio_build_cache_get_total_duration(&duration))
    {
        if (duration != old_duration)
        {
            g_audply.duration = duration;
            result = MMI_TRUE;
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_UPDATE_DUR_BY_CACHE,duration);
        }
    }

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_fast_forward
 * DESCRIPTION
 *  handling the timer and progress bar while fast forwarding
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_fast_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 duration = 0;
    U32 temp_play_time;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!g_audply.seekable && g_audply.in_main_screen)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_FAST_FORWARD_NOT_SEEKABLE);
#if !defined(__MMI_MAINLCD_96X64__)
        mmi_audply_redraw_main_progressbar();
#endif
        return;
    }

    temp_play_time = g_audply.new_play_time;
    g_audply.new_play_time += g_audply.progress_speed;

    if (g_audply.new_play_time > g_mmi_audply_seek_target_time)
    {
        g_audply.new_play_time = g_mmi_audply_seek_target_time;
    }
  
    /*check if MMI progress is faster than build progress*/
    if (g_audply.need_to_build_cache)
    {
        U32 old_duration = g_audply.duration;
        
        if (audio_build_cache_progress != 100)
        {
            if (mdi_audio_build_cache_get_cache_duration(&duration))
            {
                if (g_audply.new_play_time > duration)
                {
                    /*choose the larger one to prevent the bar from shrinking*/
                    if (temp_play_time > duration)
                    {
                        g_audply.new_play_time = temp_play_time;
                    }
                    else
                    {
                        g_audply.new_play_time = duration;
                    }
                    
                    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_FAST_FORWARD_TOO_FAST);
                }
            }
        }
        /*duration updated if TRUE*/
        if (mmi_audply_update_total_duration_by_cache())
        {
            mmi_audply_update_progress_target_time(old_duration);
            mmi_audply_determine_progress_speed();
        }
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_FAST_FORWARD, g_audply.new_play_time, duration);
    mmi_audply_redraw_main_time();
#if !defined(__MMI_MAINLCD_96X64__)
    mmi_audply_redraw_main_progressbar();
#endif
#ifdef __MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__
	  if (g_audply.lyrics_display &&
	        mmi_audply_is_lyrics_valid() && g_audply.in_main_screen)
	  {
	      mmi_audply_stop_update_lyric();
	  }
#endif
    StartTimer(AUDPLY_SEEKING_TIMER, 50, mmi_audply_fast_forward);
    
}
#if defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__)
static audply_seek_state_enum g_audio_player_state_seek;
void mmi_audply_seek_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 duration;
    U32 temp_play_time = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	StopTimer(AUDPLY_SEEKING_TIMER);
    if (!g_audply.seekable && g_audply.in_main_screen)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_FAST_FORWARD_NOT_SEEKABLE);
        mmi_audply_redraw_main_progressbar();
        return;
    }
	if (g_audply.new_play_time < g_mmi_audply_seek_target_time)
    {
        g_audply.new_play_time = g_mmi_audply_seek_target_time;
		//gui_start_timer(50, mmi_audply_seek_forward);
    }
  
    /*check if MMI progress is faster than build progress*/
    if (g_audply.need_to_build_cache)
    {
        U32 old_duration = g_audply.duration;
        
        if (audio_build_cache_progress != 100)
        {
            if (mdi_audio_build_cache_get_cache_duration(&duration))
            {
                if (g_audply.new_play_time > duration)
                {
                    /*choose the larger one to prevent the bar from shrinking*/
                    if (temp_play_time > duration)
                    {
                        g_audply.new_play_time = temp_play_time;
                    }
                    else
                    {
                        g_audply.new_play_time = duration;
                    }

                    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_FAST_FORWARD_TOO_FAST);
                }
            }
        }
        /*duration updated if TRUE*/
        if (mmi_audply_update_total_duration_by_cache())
        {
            mmi_audply_update_progress_target_time(old_duration);
            mmi_audply_determine_progress_speed();
        }


        StartTimer(AUDPLY_SEEKING_TIMER, 50, mmi_audply_seek_forward);
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_FAST_FORWARD, g_audply.new_play_time, duration);
    mmi_audply_redraw_main_time();
    mmi_audply_redraw_main_progressbar();
    g_audio_player_state_seek = AUDPLY_SEEK_STATE_NONE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_seek_rewind
 * DESCRIPTION
 *  handling the timer and progress bar redrawing while rewinding
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_seek_rewind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(AUDPLY_SEEKING_TIMER);
    if (!g_audply.seekable && g_audply.in_main_screen)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_REWIND_NOT_SEEKABLE);
        mmi_audply_redraw_main_progressbar();
        return;
    }
    if (g_audply.new_play_time >= g_mmi_audply_seek_target_time)
    {
        g_audply.new_play_time = g_mmi_audply_seek_target_time;  
    }       
    if (g_audply.need_to_build_cache)
    {
        U32 old_duration = g_audply.duration;

        /*duration updated if TRUE*/
        if (mmi_audply_update_total_duration_by_cache())
        {
            mmi_audply_update_progress_target_time(old_duration); 
            mmi_audply_determine_progress_speed();
        }

        StartTimer(AUDPLY_SEEKING_TIMER, 50, mmi_audply_seek_rewind);
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_REWIND, g_audply.new_play_time);
    mmi_audply_redraw_main_time();
    mmi_audply_redraw_main_progressbar();
#ifdef __MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__
	  if (g_audply.lyrics_display &&
	        mmi_audply_is_lyrics_valid() && g_audply.in_main_screen)
	  {
	      mmi_audply_stop_update_lyric();
	  }
#endif
    g_audio_player_state_seek = AUDPLY_SEEK_STATE_NONE;
}

void mmi_audply_update_seeking_state(audply_seek_state_enum state)
{
    g_audio_player_state_seek = state;
}
audply_seek_state_enum mmi_audply_get_seeking_state(void)
{
    return g_audio_player_state_seek;
}
#endif /*#ifdef __MMI_FTE_SUPPORT__*/
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_rewind
 * DESCRIPTION
 *  handling the timer and progress bar redrawing while rewinding
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_rewind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_audply.seekable && g_audply.in_main_screen)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_REWIND_NOT_SEEKABLE);
        mmi_audply_redraw_main_progressbar();
        return;
    }
    
    if (g_audply.new_play_time - g_mmi_audply_seek_target_time < g_audply.progress_speed) 
    {
        g_audply.new_play_time = g_mmi_audply_seek_target_time;
    }
    else
    {
        if (g_audply.new_play_time >= g_audply.progress_speed)
        {
            g_audply.new_play_time -= g_audply.progress_speed;   
        }       
    }

    if (g_audply.need_to_build_cache)
    {
        U32 old_duration = g_audply.duration;

        /*duration updated if TRUE*/
        if (mmi_audply_update_total_duration_by_cache())
        {
            mmi_audply_update_progress_target_time(old_duration); 
            mmi_audply_determine_progress_speed();
        }
    }
    #ifdef __MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__
	  if (g_audply.lyrics_display &&
	        mmi_audply_is_lyrics_valid() && g_audply.in_main_screen)
	  {
	      mmi_audply_stop_update_lyric();
	  }
#endif
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_REWIND, g_audply.new_play_time);
    mmi_audply_redraw_main_time();
    mmi_audply_redraw_main_progressbar();
    StartTimer(AUDPLY_SEEKING_TIMER, 50, mmi_audply_rewind);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_determine_progress_speed
 * DESCRIPTION
 *  determine progress speed according to song duration
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_determine_progress_speed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply.duration <= 300000) /*less than 5 mins*/
    {
        g_audply.progress_speed = 1000;
    }
    else if (g_audply.duration <= 600000) /*5 to 10 mins*/
    {
        g_audply.progress_speed = 2000;
    }
    else
    {
        g_audply.progress_speed = 4000;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_AUDPLY_TRC_PROGRESS_SPEED, g_audply.progress_speed / 1000);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_initialize_cache
 * DESCRIPTION
 *  initialize the cache
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_initialize_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(audio_cache, 0, BUILD_CACHE_SIZE); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_refresh_cache
 * DESCRIPTION
 *  initialize the cache and reset some values
 * PARAMETERS
 *  BOOL    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_refresh_cache(MMI_BOOL check_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_ENTRY_REFRESH_CACHE,check_name);

    /*refresh the build cache values*/
    if (check_name)
    {
        if (mmi_ucs2icmp((CHAR*)g_audply.filefullname, (CHAR*)g_audply.prev_filefullname))
        {
            mdi_audio_close_build_cache();
            audio_build_cache_progress = 0;
            /*initialize the cache*/
            mmi_audply_initialize_cache();
            mdi_audio_reset_build_cache_variables();
            mmi_ucs2ncpy((CHAR*)g_audply.prev_filefullname, (CHAR*)g_audply.filefullname, (SRV_FMGR_PATH_MAX_LEN+1));
            g_audply.file_name_identical = MMI_TRUE;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_REFRESH_CACHE_DONE);
        }
    }
    else
    {
        mdi_audio_close_build_cache();
        audio_build_cache_progress = 0;
        /*initialize the cache*/
        mmi_audply_initialize_cache();
        mdi_audio_reset_build_cache_variables();
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_REFRESH_CACHE_DONE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_determine_cache_ptr
 * DESCRIPTION
 *  return cache pointer for L1 build cache to use
 * PARAMETERS
 *  void
 * RETURNS
 *  cache_ptr
 *****************************************************************************/
U8* mmi_audply_determine_cache_ptr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply.need_to_build_cache)
    {
        return audio_cache;
    }
    else
    {
        return NULL;
    }
}
    

    
#ifdef __MMI_AUDIO_PLAYER_SKIN_SLIM__
#if defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__)

extern void mmi_audply_redraw_main_repeat(MMI_BOOL down);
extern void mmi_audply_touch_repeat_toggle(void);
extern void mmi_audply_redraw_main_shuffle(MMI_BOOL down);
extern void mmi_audply_touch_shuffle_toggle(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_repeat_button_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_repeat_button_down(void)
{
    
    mmi_audply_redraw_main_repeat(MMI_TRUE);

}
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_repeat_button_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_repeat_button_up(void)
{

    mmi_audply_touch_repeat_toggle();
    mmi_audply_redraw_main_repeat(MMI_FALSE);

}
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_shuffle_button_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_shuffle_button_down(void)
{

    mmi_audply_redraw_main_shuffle(MMI_TRUE);

}
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_shuffle_button_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_shuffle_button_up(void)
{

    mmi_audply_touch_shuffle_toggle();
    mmi_audply_redraw_main_shuffle(MMI_FALSE);

}
#endif

#endif /*__MMI_AUDIO_PLAYER_SKIN_SLIM__*/
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_stop_button_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_stop_button_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_STOP_BUTTON_DOWN);
    
    if (g_audply_main_selected_button == AUDPLY_MAIN_DISABLED)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_BUTTON_CHECK_FAIL);    
        return;
    }

    /* change selected button & update state */
    g_audply_main_selected_button = AUDPLY_MAIN_STOP;
    g_audply_main_selected_button_down = MMI_TRUE;

    /* update button display */
    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_main_buttons();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_stop_button_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_stop_button_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_STOP_BUTTON_UP, g_audply.state);
    
    if (g_audply_main_selected_button_down && 
       (g_audply_main_selected_button == AUDPLY_MAIN_STOP))
    {
        //bql: why update buttons only if state is idle
        MMI_BOOL need_redraw_buttons = (MMI_BOOL)(g_audply.state == STATE_IDLE);
        /* update selected button state */
        g_audply_main_selected_button_down = MMI_FALSE;
        StopTimer(AUDPLY_SEEKING_TIMER);   
        mmi_audply_stop_playing();

        g_mmi_audply_play_completed_after_button_down = MMI_FALSE;
        
        g_mmi_audply_longpressed = MMI_FALSE;

        /*when user actively stop audio player, the fail num shall reset to zero*/
        g_audply.successive_fail_num = 0;

        if (g_audply.in_main_screen)
        {
        #ifdef __DRM_SUPPORT__
            S32 result = 0;
            result = mmi_audply_drm_valide_right((PU16)g_audply.filefullname);
            if(result ==2)
            { 
                g_audply.seekable = MMI_FALSE;
                mmi_audply_redraw_main_progressbar();
            }    
        #endif

            /* update button display */
            if (need_redraw_buttons)
            {
                mmi_audply_redraw_main_buttons();
            }
        }
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_BUTTON_CHECK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_play_button_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_play_button_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_PLAY_BUTTON_DOWN,g_audply.state,g_audply.wait_next);

    if (g_audply_main_selected_button == AUDPLY_MAIN_DISABLED)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_BUTTON_CHECK_FAIL);
        return;
    }

    /* update selected button state */
    g_audply_main_selected_button_down = MMI_TRUE;

    if (g_audply.state == STATE_PLAY && !g_audply.wait_next)
    {
        g_audply_main_selected_button = AUDPLY_MAIN_PAUSE; /* change selected button */
    }
    else if (g_audply.state == STATE_PAUSED)
    {
        g_audply_main_selected_button = AUDPLY_MAIN_PLAY;  /* change selected button */
    }
    else    /* g_audply.state == STATE_IDLE */
    {
        g_audply_main_selected_button = AUDPLY_MAIN_PLAY;  /* change selected button */
    }

    /* update button display */
    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_main_buttons();

    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__  
        mmi_audply_redraw_LSK_down();
    #endif    
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_play_button_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_play_button_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_PLAY_BUTTON_UP,g_audply.state,g_audply.wait_next,0);

    if (g_audply_main_selected_button_down && 
        ((g_audply_main_selected_button == AUDPLY_MAIN_PLAY) ||
         (g_audply_main_selected_button == AUDPLY_MAIN_PAUSE)))
    {
        /* update selected button state */
        g_audply_main_selected_button_down = MMI_FALSE;

        g_audply.successive_fail_num = 0;

        StopTimer(AUDPLY_SEEKING_TIMER);
        if (g_audply.state == STATE_PLAY && !g_audply.wait_next)
        {
            mmi_audply_pause();   /* do pause action */
        #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__  
            mmi_audply_set_LSK_text(STR_GLOBAL_PLAY);
        #endif   
        }
        else if (g_audply.state == STATE_PAUSED)
        {
            mmi_audply_resume();    /* do resume action */
        #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__  
            mmi_audply_set_LSK_text(STR_GLOBAL_PAUSE);
        #endif 
        }
        else    /* g_audply.state == STATE_IDLE */
        {
            #ifdef __MMI_AUDPLY_PLAYLIST_GEN_ASYN__
            if (strcmp((char *)g_audply.filefullname, "") != 0)
            #endif
            mmi_audply_play();    /* do play action */
        #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__  
            mmi_audply_set_LSK_text(STR_GLOBAL_PAUSE);
        #endif 
        }
        g_mmi_audply_play_completed_after_button_down = MMI_FALSE;

    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
        if (g_audply.in_main_screen)
        {
            mmi_audply_redraw_LSK_up();
        }
    #endif        
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_BUTTON_CHECK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_prev_button_down
 * DESCRIPTION
 *  handle event previous button down
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_prev_button_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_PREV_BUTTON_DOWN);
    
    if (g_audply_main_selected_button == AUDPLY_MAIN_DISABLED)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_BUTTON_CHECK_FAIL);
        return;
    }

    /* change selected button & update state */
    g_audply_main_selected_button = AUDPLY_MAIN_PREV;
    g_audply_main_selected_button_down = MMI_TRUE;

#ifndef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__    
    /* update button display */
    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_main_buttons();
    }
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_prev_button_up
 * DESCRIPTION
 *  handle event previous button up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_prev_button_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_PREV_BUTTON_UP,g_audply.state,g_mmi_audply_longpressed);
    mmi_audply_press_prev_next_button_up(0);
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
				#ifdef __MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__
/* under construction !*/
                #endif 
/* under construction !*/
        #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
/* under construction !*/
        #endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_A2DP_SUPPORT__
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                    #ifdef __MMI_A2DP_SUPPORT__
/* under construction !*/
/* under construction !*/
                    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
/* under construction !*/
                #endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	    #ifdef __MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__
/* under construction !*/
	    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #if !defined(GDI_USING_HW_GIF) && !defined(GDI_USING_HW_GIF_V2) && (defined(__MMI_AUDIO_PLAYER_ANIMATION__))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif            
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


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_next_button_down
 * DESCRIPTION
 *  handle event next button down
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_next_button_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_NEXT_BUTTON_DOWN);
    
    if (g_audply_main_selected_button == AUDPLY_MAIN_DISABLED)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_BUTTON_CHECK_FAIL);
        return;
    }

    /* change selected button & update state */
    g_audply_main_selected_button = AUDPLY_MAIN_NEXT;
    g_audply_main_selected_button_down = MMI_TRUE;

#ifndef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__    
    /* update button display */
    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_main_buttons();
    }
#endif
}



/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_next_button_up
 * DESCRIPTION
 *  handle event next button up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_next_button_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_NEXT_BUTTON_UP,g_audply.state,g_mmi_audply_longpressed);
    mmi_audply_press_prev_next_button_up(1);


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
				#ifdef __MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__
/* under construction !*/
                #endif 
/* under construction !*/
        #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
/* under construction !*/
        #endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_A2DP_SUPPORT__
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                    #ifdef __MMI_A2DP_SUPPORT__
/* under construction !*/
/* under construction !*/
                    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
/* under construction !*/
                #endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #ifdef __MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__
/* under construction !*/
	    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #if !defined(GDI_USING_HW_GIF) && !defined(GDI_USING_HW_GIF_V2) && (defined(__MMI_AUDIO_PLAYER_ANIMATION__))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif               
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





/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_next_button_up
 * DESCRIPTION
 *  handle event next button up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_prev_next_button_up(U32 button_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_NEXT_BUTTON_UP,g_audply.state,g_mmi_audply_longpressed);
    
    if (g_audply_main_selected_button_down && ((g_audply_main_selected_button == AUDPLY_MAIN_NEXT)||(g_audply_main_selected_button == AUDPLY_MAIN_PREV)))
    {
        if (!g_mmi_audply_longpressed)
        {
            /* update selected button state */
            g_audply_main_selected_button_down = MMI_FALSE;

            StopTimer(AUDPLY_COUNT_PLAY_TIMER);
			StopTimer(AUDPLY_DISPLAY_LYRICS_TIMER);
			if(g_audply.in_main_screen)
			{
				#ifdef __MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__
                   mmi_audply_unprepare_lyrics();
                #endif 
			}
        #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
            gui_cancel_timer(mmi_audply_scroll_lyric_handler);
        #endif 
            /* pick the next song */
			
    		mmi_audply_clear_play_seconds();
            if(button_type == 1)
            {
            mmi_audply_playlist_pick_next();
            }
            else
            {
                mmi_audply_playlist_pick_prev();
            }
			
            if (mmi_audply_playlist_apply_picked_file())
            {
                if (g_audply.state == STATE_PLAY || g_audply.state == STATE_PAUSED ||
                    g_mmi_audply_play_completed_after_button_down || g_audply.need_replay || 
                    g_audply.wait_next == MMI_TRUE
        #ifdef __MMI_A2DP_SUPPORT__
                    || mmi_audply_is_wait_open_bt()
        #endif
                    )
                {
                    StopTimer(AUDPLY_DELAY_PLAY_TIMER);
                    g_audply.wait_next = MMI_FALSE;
                    
                    if (g_audply.state != STATE_PAUSED)
                    {
                        mmi_audply_do_stop_action(MMI_FALSE);
                    #ifdef __MMI_A2DP_SUPPORT__
                        /* since filename is changed, we have to stop av bt open, or the configuration might be wrong */
                        mmi_audply_bt_stop(KAL_FALSE, KAL_FALSE);
                    #endif
                        StartTimer(AUDPLY_DELAY_PLAY_TIMER, 700, mmi_audply_delay_play);    /* wait for 0.7 second to request play */
                        g_audply.wait_next = MMI_TRUE;
		            }
                    else
                    {
                        mmi_audply_do_stop_action(MMI_FALSE);
                    }
                }
                 g_audply.seekable = mdi_audio_is_file_seekable(g_audply.filefullname);
		        if(!g_audply.seekable)
		        {
		            g_audply.is_support_pause = MMI_FALSE;
		        }
                       
		        if (mdi_audio_get_duration(g_audply.filefullname, &(g_audply.duration)) != MDI_AUDIO_SUCCESS)
		        {
		            g_audply.duration = 0 ;
		        }       
                /* update main title, file_index, time */
                if (g_audply.in_main_screen)
                {
                #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
                    mmi_audply_stop_scroll_lyric_and_clean_screen();
                #endif 
                    mmi_audply_redraw_main_title();
                    mmi_audply_redraw_main_file_index();
                    mmi_audply_redraw_main_time();
                    mmi_audply_redraw_main_progressbar();
                }
                mmi_idle_update_service_area();    
            }
            else
            {
                mmi_audply_update_main_button_flag();     
            }

            g_mmi_audply_play_completed_after_button_down = MMI_FALSE;
            if (mdi_audio_get_duration(g_audply.filefullname, &(g_audply.duration)) != MDI_AUDIO_SUCCESS)
			{
			       g_audply.duration = 0 ;
			}   
            /* update main buttons */
            if (g_audply.in_main_screen)
            {
            	mmi_audply_redraw_main_time();
                mmi_audply_redraw_main_buttons();
            }
            else if (g_audply.in_list_screen)
            {
                asyncdynamic_list_goto_item(mmi_audply_playlist_get_current_index());
            }
        }
        else /*g_mmi_audply_longpressed*/
        {

            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_LONGPRESSED_BUTTON_UP,g_audply.seekable,g_audply.need_to_build_cache,g_audply.state_before_longpress);
            
            /*must be set to false before mmi_audply_paly() to prevent paly fail and
              then popup screen calls exit main screen to set some values incorrectly*/
            g_mmi_audply_longpressed = MMI_FALSE;
            #ifdef __MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__
		mmi_audply_stop_update_lyric();
	    #endif
            /* must be set to false before mmi_audply_play() to let play_completed to pick
               next song to play*/
            g_audply_main_selected_button_down = MMI_FALSE;

            StopTimer(AUDPLY_SEEKING_TIMER);            

            if (g_audply.seekable)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_FAST_FORWARD_STOP);

                if (g_audply.need_to_build_cache)
                {
                    /*stop budild cache*/
                    mdi_audio_stop_build_cache();
                }

                if (g_audply.state_before_longpress == STATE_PLAY || g_mmi_audply_play_completed_after_button_down)
                {
                    mmi_audply_play();
                }
            }
            else    /* unseekable, for user release longpress next/prev button, then reset selected button */
            {
                if (g_audply.state_before_longpress == STATE_PLAY)
                {
                    if (g_audply.state != STATE_PLAY)
                    {
                        mmi_audply_play();
                    }
                    else
                    {
                        g_audply_main_selected_button = AUDPLY_MAIN_PLAY;      
                    }
                }
            }
            g_mmi_audply_play_completed_after_button_down = MMI_FALSE;
            if (g_audply.in_main_screen)
            {
            #if !defined(GDI_USING_HW_GIF) && !defined(GDI_USING_HW_GIF_V2) && (defined(__MMI_AUDIO_PLAYER_ANIMATION__))
                if(audply_main_animation.img_handle != GDI_ERROR_HANDLE)
                {
                     gdi_anim_resume(audply_main_animation.img_handle);
                }
            #endif               
                mmi_audply_redraw_main_buttons();
            }
        }
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_BUTTON_CHECK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_next_button_longpress
 * DESCRIPTION
 *  fast forward by long press next button and seeking to that point
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_next_button_longpress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_NEXT_BUTTON_LONGPRESS,g_audply.state,g_audply.wait_next,g_audply.file_name_identical);

    /*when wait next, longpress shall do nothing*/
    if (g_audply.wait_next)
    {
        return;
    }

    /*when playing song while file name not identical (press next/prev song)
      shall do nothing too.*/
    if (!g_audply.file_name_identical && g_audply.state != STATE_IDLE)
    {
        return;
    }
        
    g_mmi_audply_longpressed = MMI_TRUE;
    g_audply.state_before_longpress = g_audply.state;
    if (!g_audply.seekable)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_FAST_FORWARD_NOT_SEEKABLE);
        return;
    }

    /*stop file even in MMI it looks like it's only paused for seeking*/
    /*if wait_open_bt is on, it means audio player is trying to play and currently connecting
      a2dp*/
    if (g_audply.state != STATE_IDLE 
    #ifdef __MMI_A2DP_SUPPORT__
        || wait_open_bt
    #endif
        )
    {
    #ifdef __MMI_A2DP_SUPPORT__
        if(wait_open_bt)
        {
            g_audply.state_before_longpress = STATE_PLAY;
        }
    #endif
        /*sotp playing without redrawing*/
        mmi_audply_seek_stop_playing();
        g_audply_main_selected_button = AUDPLY_MAIN_NEXT;
        g_audply_main_selected_button_down = MMI_TRUE;
#if !defined(__MMI_MAINLCD_96X64__)
        mmi_audply_redraw_main_buttons();
#endif
    }
    else
    {
        /*in case it is in idle but waiting to retore, set replay and 
        restore to false to reject from restoring*/
        g_audply.need_replay = MMI_FALSE;
        
        /*check and refresh cache*/
        mmi_audply_refresh_cache(MMI_TRUE);
    }    

    if (g_audply.need_to_build_cache && audio_build_cache_progress < 100)
    {
        /*send message to med_v to start process*/
        mdi_audio_start_build_cache(g_audply.filefullname,
                                    audio_cache, 
                                    BUILD_CACHE_SIZE,
                                    g_audply.audio_cache_file_buf_p,
                                    BUILD_CACHE_FILE_BUF_SIZE,
                                    g_audply.audio_cache_proc_buf_p,
                                    BUILD_CACHE_PROC_BUF_SIZE,
                                    mmi_audply_build_cache_fail_callback_hdlr,
                                    &audio_build_cache_progress);        
     }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_FAST_FORWARD_START);
    StopTimer(AUDPLY_COUNT_PLAY_TIMER);
	StopTimer(AUDPLY_DISPLAY_LYRICS_TIMER);
    g_mmi_audply_seek_target_time = g_audply.duration;

#if !defined(GDI_USING_HW_GIF) && !defined(GDI_USING_HW_GIF_V2) && (defined(__MMI_AUDIO_PLAYER_ANIMATION__))
    if(audply_main_animation.img_handle != GDI_ERROR_HANDLE)
    {
        gdi_anim_pause(audply_main_animation.img_handle);
    }
#endif

    StartTimer(AUDPLY_SEEKING_TIMER, 50, mmi_audply_fast_forward);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_prev_button_longpress
 * DESCRIPTION
 *  rewind by long press prev button and seek to the point.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_prev_button_longpress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_PREV_BUTTON_LONGPRESS,g_audply.state,g_audply.wait_next,g_audply.file_name_identical);
    
    /*when wait next, longpress shall do nothing*/
    if (g_audply.wait_next)
    {
        return;
    }

    if (!g_audply.file_name_identical && g_audply.state != STATE_IDLE)
    {
        return;
    }
    
    g_mmi_audply_longpressed = MMI_TRUE;
    g_audply.state_before_longpress = g_audply.state;
    if (!g_audply.seekable)
    {
        return;
    }

    /*stop file even in MMI it looks like it's only paused for seeking*/
    if (g_audply.state != STATE_IDLE
#ifdef __MMI_A2DP_SUPPORT__
        || wait_open_bt
#endif
        )
    {
    #ifdef __MMI_A2DP_SUPPORT__
        if(wait_open_bt)
        {
            g_audply.state_before_longpress = STATE_PLAY;
        }
    #endif
        mmi_audply_seek_stop_playing();
        g_audply_main_selected_button = AUDPLY_MAIN_PREV;
        g_audply_main_selected_button_down = MMI_TRUE;
        mmi_audply_redraw_main_buttons();
    }
    else
    {
        /*in case it is in idle but waiting to retore, set replay and 
        restore to false to reject from restoring*/
        g_audply.need_replay = MMI_FALSE;

        /*check and refresh cache*/
        mmi_audply_refresh_cache(MMI_TRUE);
    }

    if (g_audply.need_to_build_cache && audio_build_cache_progress < 100)
    {
        /*send message to med_v to start process*/
        mdi_audio_start_build_cache((kal_wchar*)g_audply.filefullname,
                                    audio_cache, 
                                    BUILD_CACHE_SIZE,
                                    g_audply.audio_cache_file_buf_p,
                                    BUILD_CACHE_FILE_BUF_SIZE,
                                    g_audply.audio_cache_proc_buf_p,
                                    BUILD_CACHE_PROC_BUF_SIZE,
                                    mmi_audply_build_cache_fail_callback_hdlr,
                                    &audio_build_cache_progress);    
     }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_REWIND_START);
    StopTimer(AUDPLY_COUNT_PLAY_TIMER);
	StopTimer(AUDPLY_DISPLAY_LYRICS_TIMER);
    g_mmi_audply_seek_target_time = 0;

#if !defined(GDI_USING_HW_GIF) && !defined(GDI_USING_HW_GIF_V2) && (defined(__MMI_AUDIO_PLAYER_ANIMATION__))
    if(audply_main_animation.img_handle != GDI_ERROR_HANDLE)
    {
        gdi_anim_pause(audply_main_animation.img_handle);
    }
#endif    

    StartTimer(AUDPLY_SEEKING_TIMER, 50, mmi_audply_rewind);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_inc_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_inc_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply.volume < MDI_AUD_VOL_EX_MUTE_MAX)
    {
        S16 error;

        g_audply.volume ++;

        if (g_audply.state != STATE_IDLE)
        {
#if 1 
            mdi_audio_set_volume(VOL_TYPE_MEDIA, (U8)(MDI_AUD_VOL_EX_MUTE(g_audply.volume)));
#else
/* under construction !*/
#endif
        }
        if (g_audply.in_main_screen)
        {
#if defined(__MMI_FTE_SUPPORT__) //&& !defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__)
    	    mmi_audply_redraw_main_volume_speaker(MMI_FALSE);
#endif /*#ifdef __MMI_FTE_SUPPORT__ */		
            mmi_audply_redraw_main_volumebar();
        }
        else if (g_audply.state != STATE_PLAY)
        {
            WriteValueSlim(NVRAM_AUDPLY_VOLUME, &g_audply.volume, DS_BYTE);
            g_audply.volume_nvram = g_audply.volume;
        }

    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_inc_volume_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_inc_volume_down(void)
{
#if defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_VOL_CTL__)        
    if (g_audply.volume < MDI_AUD_VOL_EX_MUTE_MAX - 1)
    {
        mmi_audply_press_inc_volume();
        mmi_audply_redraw_main_volumectrl(1, MMI_TRUE, MMI_FALSE);
        mmi_audply_redraw_main_volumectrl(0, MMI_FALSE, MMI_FALSE);
    }
    else
    {
        mmi_audply_redraw_main_volumectrl(1, MMI_FALSE, MMI_TRUE);
    }
#else
    if (g_audply.volume < MDI_AUD_VOL_EX_MUTE_MAX - 1)
    {
        mmi_audply_press_inc_volume();
    }
#endif
}
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_inc_volume_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_inc_volume_up(void)
{
#if defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_VOL_CTL__)        
    if (g_audply.volume == MDI_AUD_VOL_EX_MUTE_MAX - 1)
    {
        mmi_audply_redraw_main_volumectrl(1, MMI_FALSE, MMI_TRUE);
    }
    else
    {
        mmi_audply_redraw_main_volumectrl(1, MMI_FALSE, MMI_FALSE);
    }
#endif
}
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_dec_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_dec_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply.volume > MDI_AUD_VOL_EX_MUTE_MIN)
    {
        S16 error;

        g_audply.volume--;
  
        
        if (g_audply.state != STATE_IDLE)
        {
#if 1
            mdi_audio_set_volume(VOL_TYPE_MEDIA, (U8)(MDI_AUD_VOL_EX_MUTE(g_audply.volume)));
#else
/* under construction !*/
#endif
        }

        if (g_audply.in_main_screen)
        {
#if defined(__MMI_FTE_SUPPORT__) //&& !defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__)
	    if (!g_audply.volume)
	    {
		    mmi_audply_redraw_main_volume_speaker(MMI_TRUE);
	    }
	    else
	    {
		    mmi_audply_redraw_main_volume_speaker(MMI_FALSE);
	    }
#endif /*__MMI_FTE_SUPPORT__*/   
            mmi_audply_redraw_main_volumebar();
        }
        else if (g_audply.state != STATE_PLAY)
        {
            WriteValueSlim(NVRAM_AUDPLY_VOLUME, &g_audply.volume, DS_BYTE);
            g_audply.volume_nvram = g_audply.volume;
        }

    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_dec_volume_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_dec_volume_down(void)
{
#if defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_VOL_CTL__)        
    if (g_audply.volume > 0)
    {
        mmi_audply_press_dec_volume();
        mmi_audply_redraw_main_volumectrl(0, MMI_TRUE, MMI_FALSE);
        mmi_audply_redraw_main_volumectrl(1, MMI_FALSE, MMI_FALSE);
    }
    else
    {
        mmi_audply_redraw_main_volumectrl(0, MMI_FALSE, MMI_TRUE);
    }
#else
    if (g_audply.volume > 0)
    {
        mmi_audply_press_dec_volume();
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_dec_volume_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_dec_volume_up(void)
{
#if defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_VOL_CTL__)
    if (g_audply.volume == 0)
    {
        mmi_audply_redraw_main_volumectrl(0, MMI_FALSE, MMI_TRUE);
    }
    else
    {
        mmi_audply_redraw_main_volumectrl(0, MMI_FALSE, MMI_FALSE);
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_lsk_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_lsk_up_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_audply_redraw_LSK_up();
    #ifdef __MMI_AUDIO_PLAYER_BT__
    //mmi_audply_entry_select();
    mmi_bt_music_launch_dev_list(GRP_ID_ROOT);
    #else
    mmi_audply_playlist_entry_playlist();
    #endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_rsk_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_rsk_up_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_audply_redraw_RSK_up();
    #ifdef __MMI_AUDIO_PLAYER_BT__
    mmi_frm_group_close(GRP_ID_AUDPLY_MAIN);
    #else
    mmi_frm_scrn_close_active_id();
    #endif
}


#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_drm_consume_right
 * DESCRIPTION
 *  This function is to validate if DRM right still exists
 * PARAMETERS
 *  U16 filename    [IN]    file to be checked
 * RETURNS
 *  S8  0: not drm file, 1: drm with rights, 2: drm without rights
 *****************************************************************************/
S32 mmi_audply_drm_valide_right(U16* filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    S32 result = 0 ;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((handle = DRM_open_file((U16*)filename, FS_READ_ONLY, DRM_PERMISSION_PLAY)) >= FS_NO_ERROR)
    {
        if (DRM_get_object_method(handle, NULL) == DRM_METHOD_NONE)
        {
            result = 0; //bql: hardcode... better to change as enum or macro
        }
        else if(DRM_validate_permission(handle, NULL, DRM_PERMISSION_PLAY))
        {   
            result = 1;
        }
        else
        {
            result = 2;
        }
        DRM_close_file(handle);
    }
    else if (handle == DRM_RESULT_NO_PERMISSION)
    {
        result = 2;
    }
    else   /* file open error, but not DRM related problem */
    {
        result = 0;
    }
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_DRM_VALIDATE_RIGHT,result);
    
    return result;
}
#endif /*__DRM_SUPPORT__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_fmgr_notify_drv_pre_format_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drv     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_fmgr_notify_drv_pre_format_hdlr(CHAR drv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_mmi_audply_init_done)
    {
        /* check if the loading audio file in the driver which will be formatted. */
        if ((UI_character_type)drv == g_audply.filefullname[0])    
        {
            /* in the driver will be formatted. */
            mmi_audply_stop_playing();
        #if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)   
            /* do this only for single list. because the list is mix in multiple list. */
            mmi_audply_refresh_cache(MMI_FALSE);
        #elif defined(__MMI_AUDPLY_MULTIPLE_LIST__)
            /* do not stop timer AUDPLY_CONTINUE_PLAY_TIMER. */
        #endif  /* __MMI_AUDIO_PLAYER_SINGLE_LIST__ */
        }
    }
    /* playlist handler. */
   // mmi_audply_playlist_pre_format_hdlr((CHAR)drv);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_fmgr_notify_drv_post_format_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drv     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_fmgr_notify_drv_post_format_hdlr(CHAR drv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_mmi_audply_init_done)
    {
        /* check if the loading audio file in the driver which will be formatted. */
        if ((UI_character_type)drv == g_audply.filefullname[0])   
        {
            /* reset player screen flag. */
            g_mmi_audply_init_done = MMI_FALSE;
        }
    }
    /* playlist handler. */
    mmi_audply_playlist_post_format_hdlr((CHAR)drv);
}

mmi_ret mmi_audply_usb_plug_in_hdlr(void)
{
    /* player do not care. */
    mmi_audply_playlist_usb_plug_in_hdlr();

    return MMI_RET_OK;
}

mmi_ret mmi_audply_usb_plug_out_hdlr(void)
{
    /* player do not care. */
    mmi_audply_playlist_usb_plug_out_hdlr();

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_msdc_plug_in_hdlr
 * DESCRIPTION
 *  handle CARD plug-in event
 * PARAMETERS
 *  has_popup       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_msdc_plug_in_hdlr(U8 drv_num, PU8 drv_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 order = 0 ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_audply_init_done)
    {
    #if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
        U8 i = 0;

        for (i = 0; i < drv_num; i++)
        {
            if (g_audply.preferred_list == drv_list[i] && 
                g_audply.present_list == (U8)SRV_FMGR_PUBLIC_DRV)
            {
                    /* switch present list to preferred driver. */
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_CARD_PLUG_IN);
                
				order = mdi_audio_get_background_callback_order(MDI_BACKGROUND_APP_AUDPLY) ;
				if(order == 0)
                mmi_audply_stop_playing();
                mmi_audply_refresh_cache(MMI_FALSE);
                    break;
            }
        }
        /*
        if (g_audply.preferred_list == (U8)SRV_FMGR_CARD_DRV && 
            g_audply.present_list == (U8)SRV_FMGR_PUBLIC_DRV)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_CARD_PLUG_IN);
            
            mmi_audply_stop_playing();
            mmi_audply_refresh_cache(MMI_FALSE);
        }*/
    #elif defined(__MMI_AUDPLY_MULTIPLE_LIST__)
        /* do nothing. */
    #endif
    }
    /* playlist handler. */
    mmi_audply_playlist_msdc_plug_in_hdlr(drv_num, drv_list);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_msdc_plug_out_hdlr
 * DESCRIPTION
 *  handle CARD plug-out event
 * PARAMETERS
 *  has_popup       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_msdc_plug_out_hdlr(U8 drv_num, PU8 drv_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
	S32 order = 0 ;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_mmi_audply_init_done)
    {
    #if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
        for (i = 0; i < drv_num; i++)
        {
            if (g_audply.preferred_list == drv_list[i] &&
                g_audply.present_list == drv_list[i])
        {
            /* switch present list to PHONE */
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_CARD_PLUG_OUT);
			  order = mdi_audio_get_background_callback_order(MDI_BACKGROUND_APP_AUDPLY) ;
			if(order == 0)
            mmi_audply_stop_playing();
            mmi_audply_refresh_cache(MMI_FALSE);
                break;
            }

        }
        /*
        if (g_audply.preferred_list == (U8)SRV_FMGR_CARD_DRV &&
            g_audply.present_list == (U8)SRV_FMGR_CARD_DRV)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_CARD_PLUG_OUT);
            mmi_audply_stop_playing();
            mmi_audply_refresh_cache(MMI_FALSE);
        }*/
    #elif defined(__MMI_AUDPLY_MULTIPLE_LIST__)
        /*
        **  2 cases in multiple list:
        **      1. list in phone and audio file in memory card.
        **          - do nothing.
        **      2. list in memory card
        **          - always stop, and handler by playlist.
        */
        for (i = 0; i < drv_num; i++)
        {
            if (mmi_audply_get_current_list_drv() == drv_list[i])
        {
            /* case 1. */
            mmi_audply_stop_playing();
            mmi_audply_refresh_cache(MMI_FALSE);
                break;
        }
        }
    /*
        if (mmi_audply_get_current_list_drv() == (U8)SRV_FMGR_CARD_DRV)
        {
            // case 1.
            mmi_audply_stop_playing();
            mmi_audply_refresh_cache(MMI_FALSE);
        }
        else
        {
            // case 2.
        }*/
    #endif
    }
    mmi_audply_playlist_msdc_plug_out_hdlr(drv_num, drv_list);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_check_file_is_playing
 * DESCRIPTION
 *  check file/folder is playing or not
 * PARAMETERS
 *  S8 * path
 *  S8 is_folder
 *  S8 is_short
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_audply_check_file_is_playing(CHAR *path, MMI_BOOL is_folder, MMI_BOOL is_short, MMI_BOOL is_delete_all, const FMGR_FILTER* filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 fmgr_path_length = (U32)mmi_ucs2strlen(path);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_audply.state == STATE_PLAY || g_audply.wait_next == MMI_TRUE ||
       (g_audply.need_replay == MMI_TRUE && mdi_audio_get_background_callback_order(MDI_BACKGROUND_APP_AUDPLY) == 0))
    {
        if(is_folder)
        {
            if(mmi_ucs2nicmp(path, (CHAR *)g_audply.filefullname, fmgr_path_length) == 0 && g_audply.filefullname[fmgr_path_length] == L'\\') 
            {        
                if(is_delete_all)
                {
                    while(g_audply.filefullname[fmgr_path_length] != 0 &&
                          g_audply.filefullname[fmgr_path_length] != L'\\')
                    {
                        fmgr_path_length ++;
                    }
                    if (g_audply.filefullname[fmgr_path_length] == 0)
                    {
                        CHAR* ext_ptr = mmi_ucs2rchr((CHAR*)g_audply.filefullname, (U16)L'.');
                        if (ext_ptr != NULL)
                        {
                            ext_ptr += 2;
                        }
                        else
                        {
                            return MMI_TRUE;
                        }

                        if (!mmi_ucs2icmp((CHAR*)ext_ptr, (CHAR*)L"imy"))
                        {
                            if (FMGR_FILTER_IS_SET(filter, FMGR_TYPE_IMY))
                            {
                                return MMI_TRUE;
                            }
                            //FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_IMY);
                        }
                        else if (!mmi_ucs2icmp((CHAR*)ext_ptr, (CHAR*)L"wav"))
                        {
                            if (FMGR_FILTER_IS_SET(filter, FMGR_TYPE_WAV))
                            {
                                return MMI_TRUE;
                            }
                            //FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_WAV);
                        }
                        else if (!mmi_ucs2icmp((CHAR*)ext_ptr, (CHAR*)L"amr"))
                        {
                            if (FMGR_FILTER_IS_SET(filter, FMGR_TYPE_AMR))
                            {
                                return MMI_TRUE;
                            }
                            //FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_AMR);
                        }
                        else if (!mmi_ucs2icmp((CHAR*)ext_ptr, (CHAR*)L"awb"))
                        {
                            if (FMGR_FILTER_IS_SET(filter, FMGR_TYPE_AWB))
                            {
                                return MMI_TRUE;
                            }
                            //FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_AWB);
                        }
                        else if (FMGR_FILTER_IS_SET_AUDIO(filter))
                        {
                            return MMI_TRUE;
                        }
                        return MMI_FALSE;
                    }                       
                }
                else if(*(U16*)(path+ fmgr_path_length * 2 - 2) == L'\\' || 
                        *(U16*)(path+ fmgr_path_length * 2) == 0)
                {
                    return MMI_TRUE;
                }
            }                       
        }
        else
        {
            if(mmi_ucs2nicmp(path, (CHAR *)g_audply.filefullname, fmgr_path_length) == 0)
                return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)
static MMI_BOOL mmi_audply_check_if_need_hide_OP_link(void);
void mmi_audply_entry_player(void)
{
    mmi_audply_entry_player_screen();
}

static void mmi_audply_OP_link1(void)
{
/* http://musicstore.mob2.orange.fr */
#ifdef BROWSER_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    wap_start_browser(WAP_BROWSER_GOTO_URL, (const PU8)MMI_AUDPLY_OP_LINK1);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_entry_main_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_entry_main_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[10];
    PU8 gui_buffer = NULL;
    U16 nNumofItem = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#ifdef __DM_LAWMO_SUPPORT__
    if (TRUE == mmi_dmui_is_phone_lock())
    {
        PU8 gui_buffer = NULL;
        gui_buffer = GetCurrGuiBuffer(SCR_ID_AUDPLY_MAIN_LIST);
        if(gui_buffer == NULL)
        {
            return;
        }
    }
#endif

    if (mmi_audply_check_if_need_hide_OP_link())
    {
        mmi_frm_hide_menu_item(MENU_ID_AUDPLY_OP_LINK1);
        //mmi_frm_hide_menu_item(MENU_ID_AUDPLY_OP_LINK2);
        //mmi_frm_hide_menu_item(MENU_ID_AUDPLY_OP_LINK3);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_AUDPLY_OP_LINK1);
        //mmi_frm_unhide_menu_item(MENU_ID_AUDPLY_OP_LINK2);
        //mmi_frm_unhide_menu_item(MENU_ID_AUDPLY_OP_LINK3);
    }
    
    EntryNewScreen(SCR_ID_AUDPLY_MAIN_LIST, NULL, mmi_audply_entry_main_list, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_AUDPLY_MAIN_LIST);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    nNumofItem = GetNumOfChild_Ext(MENU_ID_AUDPLY_MAIN_LIST);
    GetSequenceStringIds_Ext(MENU_ID_AUDPLY_MAIN_LIST, nStrItemList);
    SetParentHandler(MENU_ID_AUDPLY_MAIN_LIST);

    ShowCategory15Screen(
        STR_ID_AUDPLY_TITLE,
        GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*)gIndexIconsImageList,
        1,
        0,
        gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyDownHandler(GoBackHistory, KEY_LEFT_ARROW);

    SetDelScrnIDCallbackHandler(SCR_ID_AUDPLY_MAIN_LIST, 
                                mmi_audply_delete_history_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_init_main_list_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_init_main_list_highlight_hdlr(void)
{
    SetHiliteHandler(MENU_ID_AUDPLY_NOW_PLAYING, mmi_audply_highlight_main_list_now_playing);
    SetHiliteHandler(MENU_ID_AUDPLY_LISTMGR, mmi_audply_highlight_main_list_listmgr);
    SetHiliteHandler(MENU_ID_AUDPLY_OP_LINK1, mmi_audply_highlight_main_list_op_link1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_highlight_main_list_now_playing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_highlight_main_list_now_playing(void)
{
    SetLeftSoftkeyFunction(mmi_audply_entry_player, KEY_EVENT_UP);
    SetKeyDownHandler(mmi_audply_entry_player, KEY_RIGHT_ARROW);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_highlight_main_list_listmgr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_highlight_main_list_listmgr(void)
{
    SetLeftSoftkeyFunction(mmi_audply_playlist_entry_listmgr, KEY_EVENT_UP);
    SetKeyDownHandler(mmi_audply_playlist_entry_listmgr, KEY_RIGHT_ARROW);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_highlight_main_list_op_link1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_highlight_main_list_op_link1(void)
{
    SetLeftSoftkeyFunction(mmi_audply_OP_link1, KEY_EVENT_UP);
    SetKeyDownHandler(mmi_audply_OP_link1, KEY_RIGHT_ARROW);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif
}


//extern pBOOL mmi_bootup_is_sim_valid(void);
extern MMI_BOOL srv_sim_ctrl_is_available(mmi_sim_enum sim)

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_check_if_need_hide_OP_link
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_audply_check_if_need_hide_OP_link(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL need_hide = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__FLIGHT_MODE_SUPPORT__) && defined(__MMI_TELEPHONY_SUPPORT__)
    if (srv_mode_switch_is_network_service_available())
    {
        need_hide = MMI_TRUE;
    }
    else
#endif  /* __FLIGHT_MODE_SUPPORT__ */
    {
    #if !defined(__MMI_DUAL_SIM_MASTER__)           
        if (!srv_sim_ctrl_is_available(MMI_SIM1))
        {
            need_hide = MMI_TRUE;
        }
    #else   /* __MMI_DUAL_SIM_MASTER__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif  /* __MMI_DUAL_SIM_MASTER__ */
    
    }
    return need_hide;
}
#endif  /* __MMI_AUDPLY_MULTIPLE_LIST__ */

#if defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__)||defined(__MMI_VUI_LAUNCHER_KEY__)
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_widget_button_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audply_button_enum button
 *  U16 keyType
 * RETURNS
 *  result
 *****************************************************************************/
void  mmi_audply_widget_button_action(mmi_widget_player_button_enum button, mmi_widget_player_key_event_enum keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_WIDGET_BUTTON_ACTION, button, keyType, g_mmi_audply_init_done, g_audply.state);
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__) && defined(__MMI_BACKGROUND_CALL__)
    if(keyType == MMI_WIDGET_PLAYER_KEY_UP && srv_ucm_is_background_call())
    {
        mmi_ucm_entry_error_message();
        return;
    }
#endif
    if (!g_mmi_audply_init_done || g_audply.filefullname[0] == 0)
    {
        return ;
    }
    
    if (keyType == MMI_WIDGET_PLAYER_KEY_CANCELED)
    {
        switch (button)
        {
            case MMI_WIDGET_PLAYER_PLAY_PAUSE:
            case MMI_WIDGET_PLAYER_NEXT:
            case MMI_WIDGET_PLAYER_PREV:
            case MMI_WIDGET_PLAYER_STOP:
                mmi_audply_press_button_canceled();
                break;
        }
        return;
    }

    switch (button)
    {
        case MMI_WIDGET_PLAYER_PLAY_PAUSE:
            if (keyType == MMI_WIDGET_PLAYER_KEY_UP)
            {
                if (g_audply.state != STATE_PLAY 
            #ifdef __MMI_A2DP_SUPPORT__
                    && wait_open_bt == MMI_FALSE
            #endif
                    )
                {
                    mdi_audio_stop_all();
                }
                mmi_audply_press_play_button_up();
            }
            else if (keyType == MMI_WIDGET_PLAYER_KEY_DOWN)
            {
                mmi_audply_press_play_button_down();
            }
            break;

        case MMI_WIDGET_PLAYER_STOP:
            if (keyType == MMI_WIDGET_PLAYER_KEY_UP)
            {
                mmi_audply_press_stop_button_up();
            }
            else if (keyType == MMI_WIDGET_PLAYER_KEY_DOWN)
            {
                mmi_audply_press_stop_button_down();
            }
            break;

        case MMI_WIDGET_PLAYER_NEXT:
            if (keyType == MMI_WIDGET_PLAYER_KEY_UP)
            {
                mmi_audply_press_next_button_up();
            }
            else if (keyType == MMI_WIDGET_PLAYER_KEY_DOWN)
            {
                mmi_audply_press_next_button_down();
            }  
            break;

        case MMI_WIDGET_PLAYER_PREV:
            if (keyType == MMI_WIDGET_PLAYER_KEY_UP)
            {
                mmi_audply_press_prev_button_up();
            }
            else if (keyType == MMI_WIDGET_PLAYER_KEY_DOWN)
            {
                mmi_audply_press_prev_button_down();
            }
            break;

        default:
            break;
    }
    
	return ;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_widget_get_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_widget_get_value(mmi_widget_player_get_value_enum type, void * value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_WIDGET_GET_VALUE, type, g_mmi_audply_init_done, g_audply.state);*/
    switch (type)
    {
        case MMI_WIDGET_PLAYER_TOTAL_DURATION:
            * (U64 *)value = g_audply.duration; 
            break;
            
        case MMI_WIDGET_PLAYER_FILENAME:
            mmi_ucs2cpy((CHAR*)value, (CHAR*)g_audply.title);
            break;

        case MMI_WIDGET_PLAYER_FULLPATH:
            mmi_ucs2cpy((CHAR*)value, (CHAR*)g_audply.filefullname);
            break;
            
        case MMI_WIDGET_PLAYER_CUR_STATE:
            if(g_audply.state == STATE_PLAY)
            {
                * (U8 *)value = AUDPLY_AIDGET_STATE_PLAY;
            }
            else if ( MMI_FALSE
            #ifdef __MMI_A2DP_SUPPORT__
                || mmi_audply_is_wait_open_bt()
            #endif
            )
            {
                * (U8 *)value = AUDPLY_AIDGET_STATE_PROCESS;
            }
            else
            {   /*idle state*/
                * (U8 *)value = AUDPLY_AIDGET_STATE_IDLE;
            }
            break;

        case MMI_WIDGET_PLAYER_CUR_TIME:
            * (U64 *)value = g_audply.new_play_time;
            break;
            
        default:
            ASSERT(0);
            break;
    }
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_register_callback
 * DESCRIPTION
 *  register call back handler for song change handler and status change handler.
 * PARAMETERS
 *  
 * RETURNS
 *  result
 *****************************************************************************/
void mmi_audply_widget_register_callback(void* userdata, void (*callback)(void*, mmi_widget_player_callback_enum, void*))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_audply.widget_callback = callback;
    g_audply.widget_callback_userdata = userdata;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_is_ready_to_play
 * DESCRIPTION
 *  check audio player can play or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  result
 *****************************************************************************/
MMI_BOOL mmi_audply_is_ready_to_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_IS_READY_TO_PLAY, g_mmi_audply_init_done);*/
#if defined(__USB_IN_NORMAL_MODE__)
    if (srv_usb_is_in_mass_storage_mode())
    {
        return MMI_FALSE;
    }
#endif /* defined(__USB_IN_NORMAL_MODE__) */ 
    if(g_mmi_audply_init_done && 
       g_audply.filefullname[0] != 0 
    #if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
       && !need_refresh_list 
       && !need_reload_list
    #endif
       )
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_audply_is_ready_to_play
 * DESCRIPTION
 *  check audio player can play or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  result
 *****************************************************************************/
MMI_BOOL mmi_audply_show_play_bttn(void)
{
	if((g_audply.state == STATE_PLAY) || (g_audply.wait_next && g_audply.state != STATE_PAUSED))
	{
		return MMI_TRUE;
	}
        return MMI_FALSE;
}
#endif /*__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__*/


void mmi_audply_reset_context(void)
{
    mmi_audply_clear_play_seconds();
    g_audply.seekable = MMI_FALSE;
    g_audply.need_to_build_cache = MMI_FALSE;
    g_audply.title[0] = 0;
    g_audply.filefullname[0] = 0;
}

#endif /* __MMI_AUDIO_PLAYER__ */ 
