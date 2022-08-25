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
*  AudioPlayerProt.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Audio player proto-type
*
* Author:
* -------
 * -------
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
*==============================================================================
*******************************************************************************/

#ifndef _AUDIO_PLAYER_PROT_H
#define _AUDIO_PLAYER_PROT_H

/*
 * Need to include:
 * (1) MMIDataType.h
 * (2) mdi_datatype.h
 */

#ifdef __MMI_AUDIO_PLAYER__


#ifdef __MMI_A2DP_SUPPORT__
#include "BtcmSrvGprot.h"
#include "BTMMIScr.h"
#endif
#include "custom_btcm_config.h"
#if defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__) || defined(__MMI_VUI_LAUNCHER_KEY__)
#include "MediaAppWidgetDef.h"
#endif


#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_rp_file_type_def.h"
#include "gui_data_types.h"

#ifdef WIN32
#define AUDPLY_TRACE0(tr, f)              printf(f)
#define AUDPLY_TRACE1(tr, f, a1)          printf(f, a1)
#define AUDPLY_TRACE2(tr, f, a1, a2)      printf(f, a1, a2)
#define AUDPLY_TRACE3(tr, f, a1, a2, a3)  printf(f, a1, a2, a3)
#else
#define AUDPLY_TRACE0(tr, f)              MMI_TRACE(MMI_MEDIA_TRC_G2_APP, tr)
#define AUDPLY_TRACE1(tr, f, a1)          MMI_TRACE(MMI_MEDIA_TRC_G2_APP, tr, a1)
#define AUDPLY_TRACE2(tr, f, a1, a2)      MMI_TRACE(MMI_MEDIA_TRC_G2_APP, tr, a1, a2)
#define AUDPLY_TRACE3(tr, f, a1, a2, a3)  MMI_TRACE(MMI_MEDIA_TRC_G2_APP, tr, a1, a2, a3)
#endif

#ifdef AUDPLY_DEBUG
#ifdef WIN32
#define AUDPLY_DEBUG0(f)              printf(f)
#define AUDPLY_DEBUG1(f, a1)          printf(f, a1)
#define AUDPLY_DEBUG2(f, a1, a2)      printf(f, a1, a2)
#define AUDPLY_DEBUG3(f, a1, a2, a3)  printf(f, a1, a2, a3)
#else
#define AUDPLY_DEBUG0(f)              kal_prompt_trace(MOD_MMI_MEDIA_APP, f)
#define AUDPLY_DEBUG1(f, a1)          kal_prompt_trace(MOD_MMI_MEDIA_APP, f, a1)
#define AUDPLY_DEBUG2(f, a1, a2)      kal_prompt_trace(MOD_MMI_MEDIA_APP, f, a1, a2)
#define AUDPLY_DEBUG3(f, a1, a2, a3)  kal_prompt_trace(MOD_MMI_MEDIA_APP, f, a1, a2, a3)
#endif
#else
#define AUDPLY_DEBUG0(f)              
#define AUDPLY_DEBUG1(f, a1)          
#define AUDPLY_DEBUG2(f, a1, a2)      
#define AUDPLY_DEBUG3(f, a1, a2, a3)  
#endif

/* interface from AudioPlayerSettings.c */
extern void mmi_audply_entry_two_layers_settings(void);
extern void mmi_audply_entry_settings(void);

#if defined(__MMI_AUDIO_TIME_STRETCH__)
extern void mmi_audply_speed_set_speed(void);
extern void mmi_audply_speed_close(void);
extern S32 mmi_audply_speed_check_before_play(U16 speed);
#endif /* __MMI_AUDIO_TIME_STRETCH__ */

#ifdef __BT_SPK_VOL_CONTROL__
extern MMI_BOOL mmi_audply_handfree_volume_sync_callback(U8 volume, MMI_BOOL is_mute);
#endif

/* interface from AudioPlayerMsgHandler.c */
extern void mmi_audply_bt_open_callback(srv_bt_cm_bt_addr *address, kal_int32 result);
extern void mmi_audply_delay_play(void);
extern void mmi_audply_build_cache_fail_callback_hdlr(void *inMsg);
extern MMI_BOOL mmi_audply_is_wait_open_bt(void);
extern void mmi_audply_switch_bt_output(void);
extern void mmi_audply_turn_off_bt_output(void);
extern void mmi_audply_sync_bt_output(void);
extern void mmi_audply_bt_stop(MMI_BOOL stop_codec, MMI_BOOL notify_opener);
extern void mmi_audply_check_a2dp(MMI_BOOL bt_a2dp_output, MMI_BOOL back_to_main);
extern U16 mmi_audply_get_string_for_a2dp(MMI_BOOL bt_a2dp_output);
extern void mmi_audply_delay_play(void);

extern void mmi_audply_play(void);
extern void mmi_audply_pause(void);
extern void mmi_audply_resume(void);
extern void mmi_audply_stop_playing(void);
extern void mmi_audply_seek_stop_playing(void);
extern void mmi_audply_encoding_type_change_callback(void);
extern void mmi_audply_build_cache_fail_callback_hdlr(void *inMsg);
extern MMI_BOOL mmi_audply_is_play_activated(void);
extern MMI_BOOL mmi_audply_is_playing(void);
extern void mmi_audply_do_stop_action(MMI_BOOL clear_bg_handler);
extern MMI_BOOL mmi_audply_playlist_remove_all(void);

extern void mmi_audply_fmgr_notify_hdlr(CHAR drv);
extern void mmi_audply_update_list_hdlr(const CHAR* old_path, const CHAR* new_path, U8 action_type, MMI_BOOL is_folder);

/* interface from AudioPlayerSrc.c */
extern void mmi_audply_entry_player(void);

extern void mmi_audply_read_settings(void);
extern void mmi_audply_write_settings(void);

extern void InitAudioPlayerApp(void);
extern void mmi_audply_A2DP_spectrum_need_block(void);
extern void HighlightAudioPlayer(void);
extern void mmi_audply_update_main_button_flag(void);
extern void mmi_audply_entry_main(void);

extern void mmi_audply_timer(void);
extern void mmi_audply_update_play_seconds(void);
extern U32 mmi_audply_get_play_seconds(void);
extern void mmi_audply_clear_play_seconds(void);
extern void mmi_audply_determine_progress_speed(void);
extern void mmi_audply_initialize_cache(void);
extern void mmi_audply_refresh_cache(MMI_BOOL check_name);
extern U8* mmi_audply_determine_cache_ptr(void);
extern void mmi_audply_update_main(void);

extern void mmi_audply_rewind(void);
extern void mmi_audply_fast_forward(void);

extern void mmi_audply_press_stop_button_up(void);
extern void mmi_audply_press_play_button_up(void);
extern void mmi_audply_press_prev_button_up(void);
extern void mmi_audply_press_next_button_up(void);
extern void mmi_audply_press_stop_button_down(void);
extern void mmi_audply_press_play_button_down(void);
extern void mmi_audply_press_prev_button_down(void);
extern void mmi_audply_press_next_button_down(void);
extern void mmi_audply_press_next_button_longpress(void);
extern void mmi_audply_press_prev_button_longpress(void);
extern void mmi_audply_reset_context(void);
#ifdef __MMI_AUDIO_PLAYER_SKIN_SLIM__
extern void mmi_audply_press_repeat_button_down(void);
extern void mmi_audply_press_repeat_button_up(void);
extern void mmi_audply_press_shuffle_button_down(void);
extern void mmi_audply_press_shuffle_button_up(void);
#endif
#ifdef __MMI_TOUCH_SCREEN__
extern void mmi_audply_touch_progress_seeking(S16 cor_x);
extern void mmi_audply_touch_progress_hdlr(S16 cor_x);
extern void mmi_audply_touch_progress_pen_up(void);
#endif

extern void mmi_audply_press_inc_volume(void);
extern void mmi_audply_press_inc_volume_up(void);
extern void mmi_audply_press_inc_volume_down(void);
extern void mmi_audply_press_dec_volume(void);
extern void mmi_audply_press_dec_volume_up(void);
extern void mmi_audply_press_dec_volume_down(void);

#ifdef __DRM_SUPPORT__
extern S32 mmi_audply_drm_valide_right(U16* filename);
#endif

extern void mmi_audply_fmgr_notify_drv_pre_format_hdlr(CHAR drv);
extern void mmi_audply_fmgr_notify_drv_post_format_hdlr(CHAR drv);
extern void mmi_audply_msdc_plug_in_hdlr(U8 drv_nmu, PU8 drv_list);
extern void mmi_audply_msdc_plug_out_hdlr(U8 drv_nmu, PU8 drv_list);
extern MMI_BOOL mmi_audply_check_file_is_playing(CHAR *path, MMI_BOOL is_folder, MMI_BOOL is_short, MMI_BOOL is_delete_all, const FMGR_FILTER *filter);

#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)
extern void mmi_audply_highlight_main_list_now_playing(void);
extern void mmi_audply_highlight_main_list_listmgr(void);
extern void mmi_audply_highlight_main_list_op_link1(void);
#endif  /* __MMI_AUDPLY_MULTIPLE_LIST__ */


#if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__)
extern void mmi_audply_calc_spectrum(MMI_BOOL on);
extern mmi_ret mmi_audply_turn_on_spectrum(void);
extern mmi_ret mmi_audply_turn_off_spectrum(void);
extern void mmi_audply_spectrum_display_start(void);
extern void mmi_audply_spectrum_display_stop(void);
#endif

#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__)
extern void mmi_audply_stop_scroll_lyric_and_clean_screen(void);
extern void mmi_audply_scroll_lyric_handler(void);
extern void mmi_audply_redraw_lyric(void);
extern void mmi_audply_lyric_on_time(void);
extern void mmi_audply_lyric_check_backlight(MMI_BOOL on);
extern void mmi_audply_stop_lyric(void);
extern MMI_BOOL mmi_audply_init_lyric(void);
#endif

extern void mmi_audply_entry_detail(void);

extern mmi_ret mmi_audply_usb_plug_in_hdlr(void);
extern mmi_ret mmi_audply_usb_plug_out_hdlr(void);
extern mmi_ret mmi_audply_lcd_sleep_in_handler(mmi_event_struct *event);


#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
extern MMI_BOOL mmi_audply_plst_notify_default_storage_change_pre_check(CHAR new_storage_letter);
extern void mmi_audply_plst_notify_default_storage_change(CHAR new_storage_letter);
#endif	/* __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__ */

#if defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__) || defined(__MMI_VUI_LAUNCHER_KEY__)
/*for widget player*/
typedef enum
{
    AUDPLY_AIDGET_STATE_IDLE,
    AUDPLY_AIDGET_STATE_PLAY,
    AUDPLY_AIDGET_STATE_PROCESS,
    AUDPLY_AIDGET_STATE_TOTAL
} audply_widget_state_enum;
extern void mmi_audply_widget_register_callback(void* userdata, void (*callback)(void*, mmi_widget_player_callback_enum, void*));
extern MMI_BOOL mmi_audply_widget_get_value(mmi_widget_player_get_value_enum type, void * value);
extern void  mmi_audply_widget_button_action(mmi_widget_player_button_enum button, mmi_widget_player_key_event_enum keyType);
extern MMI_BOOL mmi_audply_is_ready_to_play(void);
extern MMI_BOOL mmi_audply_show_play_bttn(void);

#endif
#ifdef __MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__
extern void mmi_audply_prepare_lyrics(void);
extern void mmi_audply_update_lyrics(void);
extern void mmi_audply_draw_lyrics(void);
extern void mmi_audply_update_lyrics_on_time(void);
extern void mmi_audply_stop_update_lyric(void);
extern void mmi_audply_unprepare_lyrics(void);
#endif
#endif /* __MMI_AUDIO_PLAYER__ */ 
extern void mmi_audply_reset_skin_layer(void);

/* single play */
#ifndef __MMI_MEDIA_PLAYER_AUDIO__
extern MMI_BOOL mmi_audply_is_single_play_activated(void);
extern void mmi_audply_init_single_play(void);
extern void mmi_audply_single_play(UI_string_type filefullname, void (*exit_callback_func) (void),U16 title_icon);
extern void mmi_audply_exit_single_play(void);
extern void mmi_audply_do_single_stop_action(void);
#endif

extern mmi_ret mmi_auddply_play_event_callback_hdlr(mmi_event_struct *event);

extern void mmi_audply_display_popup(S32 result, FuncPtr callback, FuncPtr InterrCallBack);
extern U16 mmi_audply_err_str(S32 result);
#ifdef __MMI_NCENTER_SUPPORT__

extern void mmi_audply_ncenter_close(void);
extern void mmi_audply_ncenter_open(void);
#endif

#endif /* _AUDIO_PLAYER_PROT_H */ 

