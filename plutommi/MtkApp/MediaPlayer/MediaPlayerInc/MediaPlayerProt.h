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
*  MediaPlayerProt.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Media player internal proto-type
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef MEDIA_PLAYER_PROT_H
#define MEDIA_PLAYER_PROT_H

#ifdef __MMI_MEDIA_PLAYER__
#define MEDPLY_DEBUG

/*===================== Include =====================*/
//#include "ProfilesSrvGprot.h"

#include "MediaPlayerGProt.h"
#include "MediaPlayerPlayList.h"
#include "MediaPlayerEnumDef.h"
#include "Gdi_datatype.h"
#if defined (__PLST_SERVICE_DB_SUPPORT__)
#include "PlstSrvGprot.h"
#endif
#if defined(__MMI_A2DP_SUPPORT__)
#include "BtcmSrvGprot.h"
#endif
#include "mdi_video.h"
#include "mmi_features_mediaplayer.h"

//#include "FileMgrGProt.h"
#include "FileMgrSrvGProt.h"

#ifdef __MMI_KURO_SUPPORT__
//#include "kurodepends.h"
//#include "kurodatatype.h"
#include "kurotypedef.h"
//#include "kuroapi.h"
#endif

#if defined(__MMI_AUDIO_VOCAL_REMOVAL__) || defined(__MMI_AUDIO_PITCH_SHIFTING__)
//#include "SoundEffect.h"
#endif

#ifdef __MMI_URI_AGENT__
#include "UriAgentSrvGprot.h"
#endif /* __MMI_URI_AGENT__ */

#include "mmi_frm_gestures_gprot.h"
#include "menucuigprot.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mdi_datatype.h"
#include "MediaAppWidgetDef.h"
#include "gui_data_types.h"
#include "app_ltlcom.h"
#include "mmi_frm_events_gprot.h"
#include "AlertScreen.h"
#include "mmi_frm_input_gprot.h"
#include "FileMgrCUIGProt.h"
#ifdef __MMI_NCENTER_SUPPORT__
#include "vsrv_ncenter.h"
#endif


/*===================== Define/Debug =====================*/
#ifdef WIN32
#define MEDPLY_TRACE0(tr)              //printf(tr)
#define MEDPLY_TRACE1(tr, a1)          //printf(tr, a1)
#define MEDPLY_TRACE2(tr, a1, a2)      //printf(tr, a1, a2)
#define MEDPLY_TRACE3(tr, a1, a2, a3)  //printf(tr, a1, a2, a3)
#else
#define MEDPLY_TRACE0(tr)              MMI_TRACE(MMI_MEDIA_TRC_G2_APP, tr)
#define MEDPLY_TRACE1(tr, a1)          MMI_TRACE(MMI_MEDIA_TRC_G2_APP, tr, a1)
#define MEDPLY_TRACE2(tr, a1, a2)      MMI_TRACE(MMI_MEDIA_TRC_G2_APP, tr, a1, a2)
#define MEDPLY_TRACE3(tr, a1, a2, a3)  MMI_TRACE(MMI_MEDIA_TRC_G2_APP, tr, a1, a2, a3)
#endif

#ifdef MEDPLY_DEBUG
#ifdef WIN32
#define MEDPLY_DEBUG0(f)              printf(f)
#define MEDPLY_DEBUG1(f, a1)          printf(f, a1)
#define MEDPLY_DEBUG2(f, a1, a2)      printf(f, a1, a2)
#define MEDPLY_DEBUG3(f, a1, a2, a3)  printf(f, a1, a2, a3)
#else
#define MEDPLY_DEBUG0(f)              kal_prompt_trace(MOD_MMI_MEDIA_APP, f)
#define MEDPLY_DEBUG1(f, a1)          kal_prompt_trace(MOD_MMI_MEDIA_APP, f, a1)
#define MEDPLY_DEBUG2(f, a1, a2)      kal_prompt_trace(MOD_MMI_MEDIA_APP, f, a1, a2)
#define MEDPLY_DEBUG3(f, a1, a2, a3)  kal_prompt_trace(MOD_MMI_MEDIA_APP, f, a1, a2, a3)
#endif
#else
#define MEDPLY_DEBUG0(f)              
#define MEDPLY_DEBUG1(f, a1)          
#define MEDPLY_DEBUG2(f, a1, a2)      
#define MEDPLY_DEBUG3(f, a1, a2, a3)  
#endif

#define ClrBitSet( index, bitset )     ((bitset)[(index)>>3] &= ~(1<<((index)&0x07)))
#define SetBitSet( index, bitset )     ((bitset)[(index)>>3] |= (1<<((index)&0x07)))
#define IsBitSetOn( index, bitset )    ((bitset)[(index)>>3] & (1<<((index)&0x07)))

#define MEDPLY_INTRO_PLAY_DURATION  5000 /*5 sec*/

#define MEDPLY_FTE_PEN_MOVE_MIN_TICKS  8 /*at least 8 ticks to handle a pen move*/
#define MEDPLY_PEN_LONGPRESSED_MS  900 /*900 ms to make a long press */

#ifndef __MMI_MEIDA_PLAYER_EXTENDED_URL__
    #define MEDPLY_URL_MAX_LENGTH (SRV_FMGR_PATH_MAX_LEN+1) + 1
#else
    #define MEDPLY_URL_MAX_LENGTH 520
#endif

#ifdef MOTION_SENSOR_SUPPORT
#define MMI_MEDPLY_MOTION_AVAILABLE_TIME   (85)
#endif


typedef enum
{
    MEDPLY_MENU_CUI_MAIN_MENU,
    MEDPLY_MENU_CUI_PLAYER_SCREEN_OPT,
    MEDPLY_MENU_CUI_FILE_LIST_OPT,
    MEDPLY_MENU_CUI_TYPE_LIST_OPT,
    MEDPLY_MENU_CUI_PLST_LIST_OPT,

    MEDPLY_MENU_CUI_MULTISEL_LIST_OPTION,
    MEDPLY_MENU_CUI_MULTIADD_LIST_OPTION,
    
#ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
    MEDPLY_MENU_CUI_FILE_LIST_SEARCH_OPT,
    MEDPLY_MENU_CUI_TYPE_LIST_SEARCH_OPT,
#endif /* __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__ */

    MEDPLY_MENU_CUI_TOTAL
} mmi_medply_listui_menu_cui_user_data_enum;

/*===================== Struct =====================*/
typedef struct
{
    /* duration */
    U64 duration;                  /*song duration in MS*/
    U64 old_play_time;  /*the lastest play time shown on main screen*/
    U64 current_time;   /*the current play time*/


    U32 progress_speed;            /*progress speed choosed according to duration*/

    MMI_BOOL selected_button_down; /*indicate if the selected button is pressed*/
    MMI_BOOL mute;                 /*indicate if media player is set to mute or not*/

#ifdef __MMI_MEDIA_PLAYER_AUDIO__
#if defined(__MMI_MEDIA_PLAYER_A2DP_BLOCK_SPECTRUM__) || defined(__MMI_MEDIA_PLAYER_A2DP_BLOCK_PITCH_SHIFT__)
    MMI_BOOL A2DP_blocked;      /* shared with signle player sinece it will be reset whenevet it is interrupted */
#endif
    MMI_BOOL is_audio_seekable;
    U32 audio_build_cache_process ; /*indicate the percentage of current build cache process*/
    U32 audio_cached_duration;   /*indicate the cached duration*/
#endif /*__MMI_MEDIA_PLAYER_AUDIO__*/

    MMI_BOOL seekable;                  /*indicate if it is seekable or not*/
    MMI_BOOL need_to_build_cache;       /*need to build cache to seek*/
    MMI_BOOL build_cache_failed;        /*indicate build cache fail as not seekable detail*/
    MMI_BOOL wait_next_with_pop_up;
    MMI_BOOL fullscreen;               /*indicate if it is in full screen, shared with single player */
#ifdef __MMI_TVOUT__
    MMI_BOOL tvout_fullscreen;          /*indicate if it is in full screen of tvout mode, shared with single player */
#endif

#ifdef __MMI_MEDIA_PLAYER_SNAPSHOT__
    MMI_BOOL enable_snapshot;
    U16 filename_seq_no;
#endif

#if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__) || defined(__MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__)
    MMI_BOOL DRM_consumed;       /*this flag also used for judge whether add to recent play,
                                   since the criteria of adding file to recent play is similar to DRM consuming*/
#endif /*(__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)*/

    MMI_BOOL continue_to_play;  /*indicate if continue play procedure*/
    MMI_BOOL self_stop;         /*indicate that current mdi stop action is executed by media player actively, 
                                  so in play callback, it shall ignore the terminated callback*/
    MMI_BOOL pop_up;            /*indicate the exit screen is caused by self pop up, so that no need to enter 
                                  to other state, the state changing will be handled by media player controller*/
    MMI_BOOL fs_error_pop_up;    /* To indicate if need to show FS error popups like file not found consecutively - MAUI_03333013 */

    MMI_BOOL from_mte;

    MMI_BOOL in_main_screen;
    MMI_BOOL in_list_screen;
    MMI_BOOL in_media_player;
    MMI_BOOL is_setting_init;
    MMI_BOOL reset_menu;
    MMI_BOOL has_3d_mode;
    MMI_BOOL has_2d_mode;
    MMI_BOOL has_subtitle;

#ifdef __MMI_A2DP_SUPPORT__
    MMI_BOOL inquiry_paused; /*indicate if media is paused for bt inquirying*/
    MMI_BOOL bt_success_during_inquiry; /*indicate that bt callback with ok while it is inquirying*/

#ifdef __MMI_MEDIA_PLAYER_VIDEO__    
    MMI_BOOL bt_connect_fail; /*indicate if bt has been connect for this file once and failed, so that media player 
                                will not try to connect bt every switching between vdieo and pure audio*/
#endif /*__MMI_MEDIA_PLAYER_VIDEO__*/

#endif /*__MMI_A2DP_SUPPORT__*/

#ifdef MOTION_SENSOR_SUPPORT
    U32 motion_reg_time;
    mdi_handle tilt_handle; /* shared with single player */
#endif

    void(* widget_callback)(void*, mmi_widget_player_callback_enum,void*);
    void* widget_callback_userdata;

    void* mem_pool_p;
    void* adm_id_p;
    void* medply_adm_id_p;

    mmi_medply_media_type_enum media_type;
    mmi_medply_media_format_enum media_format;

    S32 apply_result;

#ifdef __MMI_TOUCH_SCREEN__
#ifdef __MMI_MEDIA_PLAYER_FTE__
    U32 pen_event_dur;
#endif
    U8 pen_on_object; /*indicate pen lies on which medply touch object*/
#endif /*__MMI_TOUCH_SCREEN__*/

    signed char selected_button;   /*indicate which button is currently selected by user, if all
                                     buttons are disabled, MEDPLY_MAIN_DISABLED(-1) will be assigned*/

    /* cmd & states */
    UI_character_type title[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
    UI_character_type filefullpath[MEDPLY_URL_MAX_LENGTH];
    UI_character_type idle_string[(MMI_MEDPLY_MAX_ARTISRT_LEN - 1) + SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 3 + 1];   /* artist max length = 80, title max length = 80, maybe has " - " between them. */

    U16 speed;

#ifdef __MMI_AUDIO_PITCH_SHIFTING__
    S16 pitch;
#endif

    U8 affected_button_down;         /*indicate which affected button is pressed by user,
                                       affected button means change state shall reset the button down, 
                                       ex: camera, fullscreen*/
    U8 unaffected_button_down;       /*indicate which unaffected button is pressed by user, 
                                       unaffected button means change state shll not reset the button down,
                                       ex: soft key, mute*/
                                       
#if defined(__MMI_AUDIO_VOCAL_REMOVAL__)||defined(__MMI_AUDIO_PITCH_SHIFTING__)||defined(__MMI_KURO_SUPPORT__)||defined(__MMI_MEDIA_PLAYER_FTE__)
    U8 media_based_button_down;      /*indicate which media_based button is pressed by user, 
                                       media_based button means only change media file shall reset the button down,
                                       ex: pitch, voice_remove, activate*/
#endif

    U8  volume;                    /*volume level of media player, range is 0~16, 0 stands for mute*/


#ifdef __MMI_AUDIO_VOCAL_REMOVAL__
    U8 vocal_removal;
    MMI_BOOL vocal_removal_enabled;
#endif

#ifdef __MMI_KURO_SUPPORT__
    mmi_medply_kuro_activate_type activate_type ;
#endif

#ifdef __MMI_MEDIA_PLAYER_STREAM__
    UI_character_type url_path[MEDPLY_URL_MAX_LENGTH];
    /*stream title*/
    CHAR stream_title[(MDI_VIDEO_INFO_TITLE_CHAR_COUNT+1)*ENCODING_LENGTH];
    MMI_BOOL bearer_pause;
#endif

    mmi_medply_state_enum state;
    mmi_medply_state_enum prev_state;

    /* vdo info*/
#if defined(__MMI_MEDIA_PLAYER_STREAM__) || defined(__MMI_MEDIA_PLAYER_VIDEO__)    
    mdi_video_track_enum track;
    U8 aud_channel_no;
    U16 aud_sample_rate;
    U16 width;
    U16 height;    
#endif

#ifdef __MMI_MEDIA_PLAYER_AUDIO__
    U8* audio_cache_file_buf_p ; /*ptr for build cache file buffer*/
    U8* audio_cache_proc_buf_p ; /*ptr for build cache process buffer*/
#endif /*__MMI_MEDIA_PLAYER_AUDIO__*/

#ifdef __MMI_AUDIO_TIME_STRETCH__
    U8 speed_set_times;
#endif

#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
    U8 subtitle_font_size;  /*subtitle font size, share with single player*/
#endif

#ifdef __MMI_NCENTER_SUPPORT__
    vsrv_ngroup_handle ncenter_ghandle;
    vsrv_notification_handle ncenter_nhandle;
#endif
} medply_struct;

typedef struct
{
    U64 duration;                           /*song duration in MS*/
    U64 current_time;                       /*the current play time*/
#ifdef __MMI_VIDEO_PDL__
    U64 pdl_video_max_play_time;    /*pdl video downloaded in ms*/
#endif

    U32 progress_speed;                     /*progress speed choosed according to duration*/    

    UI_character_type filefullpath[MEDPLY_URL_MAX_LENGTH];

#ifdef __MMI_MEDIA_PLAYER_STREAM__
    UI_character_type url_path[MEDPLY_URL_MAX_LENGTH];
    MMI_BOOL bearer_pause;
#endif

    UI_character_type specified_title[(SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1)];

#ifdef __MMI_KURO_SUPPORT__
    mmi_medply_kuro_activate_type activate_type ;
    MMI_BOOL is_kuro_type;
#endif

    MMI_BOOL continue_to_play;              /*indicate if continue play procedure*/
    MMI_BOOL self_stop;                     /*indicate that current mdi stop action is executed by media player 
                                              actively,so in play callback, it shall ignore the terminated callback*/    

#ifdef __MMI_MEDIA_PLAYER_INTRO_PLAY__
    MMI_BOOL pop_up;                        /*indicate the exit screen is caused by self pop up, currently used in
                                              single player by intro play only.*/
    MMI_BOOL intro_play;                    /*indicate if it is under intro play mode*/
    MMI_BOOL wait_next_with_pop_up;
    MMI_BOOL intro_play_finish;             /* indicate if intro play finished*/
#endif /*__MMI_MEDIA_PLAYER_INTRO_PLAY__*/

#if defined(__MMI_MEDIA_PLAYER_AUDIO__)
    MMI_BOOL is_audio_seekable;
    U32 audio_build_cache_process ; /*indicate the percentage of current build cache process*/
    U32 audio_cached_duration;   /*indicate the cached duration*/
    void (*audio_exit_callback_func)(void); /*callback function for single audio play*/
#endif

#ifdef __DRM_SUPPORT__
    MMI_BOOL DRM_consumed;
#endif /*__DRM_SUPPORT__*/

    MMI_BOOL seekable;                      /*indicate if it is seekable or not*/
    MMI_BOOL need_to_build_cache;           /*need to build cache to seek*/
    MMI_BOOL build_cache_failed;            /*indicate build cache fail as not seekable detail*/

    MMI_BOOL mute;                          /*indicate if media player is set to mute or not*/
    MMI_BOOL is_short;                      /*indicate if the file path is short*/

    mmi_medply_media_type_enum media_type;

    MMI_BOOL has_3d_mode;
    MMI_BOOL has_2d_mode;

    MMI_BOOL selected_button_down;          /*indicate if the selected button is pressed*/
    MMI_BOOL has_subtitle;
    MMI_BOOL async_open_bearer;
#ifdef __MMI_NCENTER_SUPPORT__
    vsrv_ngroup_handle ncenter_ghandle;
#endif     


#ifdef __MMI_URI_AGENT__
    srv_uriagent_appid_enum ura_appid;
    srv_uriagent_uri_request_hdlr_cb uri_agent_cb;
    CHAR* temp_url_p;
    U8 confirm_count;
#endif

#if defined(__MMI_VIDEO_PDL__) || defined(__MMI_AUDIO_PDL__)
    S32 pdl_session_id;
#ifdef __MMI_AUDIO_PDL__
    mdi_handle pdl_audio_handle;
#endif
    U8 pdl_state;
    U8 pdl_media_type;
#endif /*defined(__MMI_VIDEO_PDL__) || defined(__MMI_AUDIO_PDL__)*/

    /* vdo info*/
#if defined(__MMI_MEDIA_PLAYER_STREAM__) || defined(__MMI_MEDIA_PLAYER_VIDEO__)    
    mdi_video_track_enum track;
    U16 aud_sample_rate;
    U16 width;
    U16 height;
    U8 aud_channel_no;
#endif

#ifdef __MMI_AUDIO_PITCH_SHIFTING__
    S16 pitch;
#endif

    signed char selected_button;            /*indicate which button is currently selected by user*/

    U8 volume;                             /*volume level of single player*/
    mmi_medply_single_state_enum state;
    U8 affected_button_down;              /*indicate which affected button is pressed by user,
                                            affected button means change state shall reset the button down, 
                                            ex: camera, fullscreen*/

    U8 unaffected_button_down;              /*indicate which unaffected button is pressed by user, 
                                              unaffected button means change state shll not reset the button down,
                                              ex: soft key, mute*/
#if defined(__MMI_AUDIO_VOCAL_REMOVAL__)||defined(__MMI_AUDIO_PITCH_SHIFTING__)||defined(__MMI_KURO_SUPPORT__)||defined(__MMI_MEDIA_PLAYER_FTE__)
    U8 media_based_button_down;             /*indicate which affected button is pressed by user,
                                               affected button means change state shall reset the button down, 
                                               ex: pitch, voice_remove, activate */
#endif

#ifdef __MMI_AUDIO_VOCAL_REMOVAL__
    U8 vocal_removal;
    MMI_BOOL vocal_removal_enabled;
#endif

#ifdef __MMI_MEDIA_PLAYER_AUDIO__
    U8* audio_cache_file_buf_p ; /*ptr for build cache file buffer*/
    U8* audio_cache_proc_buf_p ; /*ptr for build cache process buffer*/
#endif /*__MMI_MEDIA_PLAYER_AUDIO__*/

#ifdef __MMI_TOUCH_SCREEN__
    U8 pen_on_object; /*indicate pen lies on which medply touch object*/
#endif
    
}medply_single_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    CHAR rtsp_url[(MEDPLY_URL_MAX_LENGTH+1)*ENCODING_LENGTH];
} mmi_medply_rtsp_url_data_struct;

typedef struct
{
    U16 file_format;
    UI_character_type ext_name[6];
} mmi_medply_support_format_struct;

typedef struct
{
    U16 file_format;
    U8 file_type;
    U8 need_build_cache;
    U16 image_id;
    UI_character_type ext_name[6];
} mmi_medply_fileinfo_struct;

typedef struct
{
    U16 str_id;
    U32 event_id;
} mmi_medply_popup_info_struct;


/*===================== Internal Extern =====================*/

/**** Context ****/
extern medply_struct g_medply;
extern medply_single_struct g_single;
extern const mmi_medply_fileinfo_struct media_file_info_table[];

#ifdef __MTK_TARGET__
extern __align(4) U8 g_medply_audio_cache[MEDPLY_BUILD_CACHE_SIZE];
#else
extern U8 g_medply_audio_cache[MEDPLY_BUILD_CACHE_SIZE];
#endif /*__MTK_TARGET__*/

extern MMI_BOOL mmi_medply_check_if_no_network_link(void);

/*****************************************/
/****         Controller              ****/
/*****************************************/
/* ~~ Common ~~ */
extern void mmi_medply_set_continue_flag(MMI_BOOL flag);
extern void mmi_medply_set_self_stop_flag(MMI_BOOL flag);
extern void mmi_medply_set_pop_up_flag(void);
extern void mmi_medply_register_key_hdlrs(mmi_medply_main_screen_status_enum screen_status);
extern void mmi_medply_back_to_normal_screen(void);
extern void mmi_medply_play_completed(MMI_BOOL with_pop_up, MMI_BOOL continue_play);
extern void mmi_medply_stop_wait_next_timer(void);
extern void mmi_medply_pop_up_start_wait_next_timer(void);
extern void mmi_medply_pop_up_wait_next_callback(void);
extern void mmi_medply_clear_key_down(void);
#ifdef __MMI_TOUCH_SCREEN__
extern void mmi_medply_clear_pen_down(void);
#endif
extern mmi_ret mmi_medply_pop_up_proc(mmi_event_struct *param);
extern void mmi_medply_display_popup_with_sg(U16 string_id, mmi_event_notify_enum event_id);

extern void mmi_medply_enter_core_states(mmi_medply_state_enum entered_core_state);
extern void mmi_medply_clear_play_seconds(void);
extern void mmi_medply_set_curret_time(U64);
extern void mmi_medply_display_popup_for_all_file_fail(void);
extern void mmi_medply_display_popup(MDI_RESULT result, MMI_BOOL wait_next_callback);
extern MMI_BOOL mmi_medply_get_build_cache_process(U64 *cached_dur);

extern void mmi_medply_entry_main(void);
extern void mmi_medply_entry_main_menu(void);
extern void mmi_medply_entry_main_menu_option(void);
extern void mmi_medply_history_insert_url(CHAR* url_p, CHAR* name_p, MMI_BOOL is_single);

extern void mmi_medply_background_prepare(void);

#ifdef __BT_SPK_VOL_CONTROL__
extern MMI_BOOL mmi_medply_handfree_volume_sync_callback(U8 volume, MMI_BOOL is_mute);
#endif

#ifdef __MMI_A2DP_SUPPORT__
extern void mmi_medply_bt_open_callback(S32 result);
extern void mmi_medply_bt_stop(MMI_BOOL notify_opener);
#ifdef __MMI_AUDIO_TIME_STRETCH__
extern void mmi_medply_bt_sync_speed(void);
#endif
#endif /*__MMI_A2DP_SUPPORT__*/

extern MMI_BOOL mmi_medply_is_button_disabled(mmi_medply_disabled_button_enum button);
#ifdef __MMI_KURO_SUPPORT__
extern MMI_BOOL mmi_medply_is_kuro_file(void);
extern void mmi_medply_kuro_get_informaion(void);
#endif
extern void mmi_medply_toggle_full_screen(void);
extern void mmi_medply_play_from_play_list(void);
extern void mmi_medply_stop_from_play_list(void);

#ifdef __MMI_AUDIO_TIME_STRETCH__
extern void mmi_medply_change_speed(U16 index);
extern void mmi_medply_settings_close_speed(void);
#endif /*__MMI_AUDIO_TIME_STRETCH__*/


/* ~~~~~~~ Audio ~~~~~~~ */
#ifdef __MMI_MEDIA_PLAYER_AUDIO__
/*audio cache*/
extern void mmi_medply_refresh_cache(void);
extern void mmi_medply_initialize_cache(void);

/*action funcs*/
extern void mmi_medply_audio_play(void);
extern void mmi_medply_audio_pause(void);
extern void mmi_medply_audio_stop(void);
extern void mmi_medply_audio_seek_stop(void);

/*callback hdlrs*/
extern void mmi_medply_build_cache_fail_callback_hdlr(void *inMsg);
extern void mmi_medply_build_cache_update_dur_hdlr(void);

extern void mmi_medply_enter_audio_states(mmi_medply_state_enum entered_audio_state);

#ifdef __MMI_KURO_SUPPORT__
extern void mmi_medply_kuro_activate_confirm(void);
extern void mmi_medply_kuro_activate_all(void);
extern MMI_BOOL mmi_medply_kuro_check_is_downloading(void);
extern void mmi_medply_kuro_check_sms_callback(kal_uint32 albumkey, kal_uint16 sms_result);
#endif /*__MMI_KURO_SUPPORT__*/

#ifdef __MMI_MEDIA_PLAYER_A2DP_BLOCK_PITCH_SHIFT__
void mmi_medply_block_pitch_shift(void);
void mmi_medply_unblock_pitch_shift(void);
#endif

#endif /*__MMI_MEDIA_PLAYER_AUDIO__*/


/* ~~~~~~~ Video ~~~~~~~ */
#ifdef __MMI_MEDIA_PLAYER_VIDEO__
/*action funcs*/
extern MMI_BOOL mmi_medply_video_open(void);
extern void mmi_medply_video_play(void);
extern void mmi_medply_video_stop(void);
extern void mmi_medply_video_pause(void);
extern void mmi_medply_video_close(void);


/*callback hdlrs*/
extern void mmi_medply_video_seek_callback_hdlr(MDI_RESULT result, void *user_data);
extern void mmi_medply_enter_video_states(mmi_medply_state_enum entered_video_state);
extern void mmi_medply_video_audio_interrupt_callback_hdlr(MDI_RESULT result, void* user_data);
#endif /*__MMI_MEDIA_PLAYER_VIDEO__*/


/* ~~~~~~~ Stream ~~~~~~~ */
#ifdef __MMI_MEDIA_PLAYER_STREAM__
/*action funcs*/
extern void mmi_medply_stream_stop(void);
extern void mmi_medply_stream_pause(void);
extern void mmi_medply_stream_play(void);
extern void mmi_medply_stream_buffer(void);
extern MMI_BOOL mmi_medply_stream_connect(void);
extern MMI_BOOL mmi_medply_stream_init(void);
extern void mmi_medply_stream_deinit(void);

/*callback hdlrs*/
extern void mmi_medply_enter_stream_states(mmi_medply_state_enum entered_stream_state);
#endif /*__MMI_MEDIA_PLAYER_STREAM__*/


/* ~~~~~~~ SnapShot ~~~~~~~ */
#ifdef __MMI_MEDIA_PLAYER_SNAPSHOT__
extern void mmi_medply_take_snapshot(void);
#endif

/* ~~~~~~~ Single ~~~~~~~ */
extern void mmi_medply_init_single_app(void);
#if defined(__DRM_SUPPORT__)
extern U8 mmi_medply_drm_valide_right(U16* filename);
#endif
extern MMI_BOOL mmi_medply_is_single_player_activated(void);
extern void mmi_medply_single_entry_main(void);
extern void mmi_medply_single_register_key_hdlrs(mmi_medply_main_screen_status_enum screen_status);

/*audio*/
#ifdef __MMI_MEDIA_PLAYER_AUDIO__
extern void mmi_medply_single_build_cache_fail_callback_hdlr(void *inMsg);
extern void mmi_medply_single_build_cache_update_dur_hdlr(void);
extern void mmi_medply_single_audio_play(void);
#endif

/*video*/
#ifdef __MMI_MEDIA_PLAYER_VIDEO__
extern void mmi_medply_single_video_seek_callback_hdlr(MDI_RESULT result, void *user_data);
extern void mmi_medply_single_video_pause(void);
extern void mmi_medply_single_video_play(void);
extern MMI_BOOL mmi_medply_single_video_open(void);
extern void mmi_medply_single_video_close(void);
#endif

/*stream*/
#ifdef __MMI_MEDIA_PLAYER_STREAM__
extern void mmi_medply_rtsp_url_hdlr(void *msg_ptr);
extern MMI_BOOL mmi_medply_single_stream_init(void);
extern void mmi_medply_single_stream_deinit(void);
extern void mmi_medply_single_stream_connect(void);
extern void mmi_medply_single_stream_buffer(void);
extern void mmi_medply_single_stream_play(void);
#endif

/*intro play*/
#ifdef __MMI_MEDIA_PLAYER_INTRO_PLAY__
extern void mmi_medply_single_intro_popup_callback(void);
extern void mmi_medply_single_intro_play_time_out_hdlr(void);
extern void mmi_medply_single_pop_up_wait_next_callback(void);
extern void mmi_medply_single_wait_next_time_out(void);
extern void mmi_medply_single_play_completed(MMI_BOOL with_pop_up);
extern void mmi_medply_single_intro_play(void);
extern mmi_ret mmi_medply_single_audio_play_popup_callback(mmi_alert_result_evt_struct *evt);
#endif /*__MMI_MEDIA_PLAYER_INTRO_PLAY__*/

/*pdl*/
#ifdef __MMI_VIDEO_PDL__
extern MMI_BOOL mmi_medply_single_pdl_video_update_download_percent(void);
extern void mmi_medply_single_pdl_video_play(void);
extern void mmi_medply_single_pdl_video_pause(void);
extern void mmi_medply_single_pdl_video_seek_callback_hdlr(MDI_RESULT result, void *user_data);
extern MMI_BOOL mmi_medply_single_pdl_video_open(void);
extern void mmi_medply_single_pdl_video_update_buffer_percent(void);
#endif
#ifdef __MMI_AUDIO_PDL__
extern void mmi_medply_single_pdl_audio_play(void);
extern MMI_BOOL mmi_medply_single_pdl_audio_open(void);
#endif

#ifdef __MMI_NCENTER_SUPPORT__
extern void mmi_medply_ncenter_add_app_item(void);
extern void mmi_medply_ncenter_clear_app_item(void);
extern void mmi_medply_ncenter_update_media(void);
#endif

/* mediaplayer main menus */
#if defined(__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
extern void mmi_medply_plstui_allmedia_entry(void);
#endif /*__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__*/
#if defined(__MMI_MEDIA_PLAYER_STREAM__)
#if defined(__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__) || defined(__MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__)
extern void mmi_medply_plst_entry_bookmark(void);
#endif /*__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__*/
#endif  /* __MMI_MEDIA_PLAYER_STREAM__ */

#if defined(__MMI_MEDIA_PLAYER_STREAM__) || defined(__MMI_KURO_DOWNLOAD_SUPPORT__)
extern void mmi_medply_settings_get_data_account_id(U32 *data_account_id);
#endif

/*****************************************/
/****           MainScreen            ****/
/*****************************************/
/*
**  Module Name: Main Screen UI 
**  Description: define main screen struct, enum, macro and extern api
*/
#include "MMI_features.h"
#include "Conversions.h"
#include "Gui_windows.h"

#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif

typedef struct
{ 
    gdi_handle  layer_hdl;
    gdi_handle  layer_subtitle_hdl;
    U32         layer_blt_flag;
    U32         layer_play_flag;
    U32         layer_subtitle_flag;
    U16         layer_lcd_rotate;
    U16         idp_rotate;
    U16         video_width;
    U16         video_height;
        
} mmi_medply_video_play_para_struct;

extern void mmi_medply_main_screen_init(void);
extern void mmi_medply_main_screen_prepare(void);
extern void mmi_medply_main_screen_unprepare(void);
extern void mmi_medply_main_screen_prepare_view(void);
extern void mmi_medply_main_screen_unprepare_view(void);
extern void mmi_medply_main_screen_redraw(void);
extern void mmi_medply_main_screen_reset(void);
extern U8   mmi_medply_main_screen_delete(void* p);
extern void mmi_medply_main_screen_blt(void);

extern void mmi_medply_main_screen_set_and_draw_button(
                mmi_medply_regn_id_enum id,
                mmi_medply_regn_status_enum status);
extern void mmi_medply_main_screen_update_title(void);

#ifdef __MMI_MEDIA_PLAYER_FTE__
extern MMI_BOOL mmi_medply_main_screen_show_user_rating(void);
extern MMI_BOOL mmi_medply_main_screen_show_volme_tuning(void);
extern void mmi_medply_main_screen_update_mute(void);
extern void mmi_medply_main_screen_update_vol(void);
extern U8 mmi_medply_main_screen_update_touch_volume(S16 x, U8 is_hilight);
#else
extern void mmi_medply_main_screen_draw_volume(U8 volume);
#endif

#ifdef __MMI_AUDIO_PITCH_SHIFTING__
extern void mmi_medply_main_screen_draw_tune(S16 level);
#endif /*__MMI_AUDIO_PITCH_SHIFTING__*/
extern void mmi_medply_main_screen_draw_duration(void);
extern void mmi_medply_main_screen_draw_cache(void);

extern void mmi_medply_main_screen_draw_lkey_down(void);
extern void mmi_medply_main_screen_draw_rkey_down(void);
extern void mmi_medply_main_screen_draw_lkey_up(void);
extern void mmi_medply_main_screen_draw_rkey_up(void);

extern void mmi_medply_main_screen_clear_video_layer(void);
extern void mmi_medply_main_screen_get_video_parameter(
                mmi_medply_video_play_para_struct* video_layer_info_p);

extern void mmi_medply_main_screen_set_clip_rgn(S16 x, S16 y, S16 w, S16 h);
extern void mmi_medply_main_screen_set_full_screen(MMI_BOOL full_f); 
extern void mmi_medply_main_screen_video_updated(void);

#ifdef __MMI_TOUCH_SCREEN__
extern U8   mmi_medply_main_screen_get_pt_rgn(mmi_pen_point_struct pt);
extern void mmi_medply_main_screen_duration_pen_down(S16 x);
extern void mmi_medply_main_screen_duration_pen_move(S16 x);
extern void mmi_medply_main_screen_duration_pen_up(S16 x);
#endif  /*#ifdef __MMI_TOUCH_SCREEN__*/

extern void mmi_medply_main_screen_duration_seek_prev(void);
extern void mmi_medply_main_screen_duration_seek_next(void);
extern void mmi_medply_main_screen_duration_seek_done(void);

extern void mmi_medply_main_screen_show_loading(U8 percent);
extern void mmi_medply_main_screen_hide_loading(void);
extern void mmi_medply_main_screen_play_animation(U8 animation);
extern void mmi_medply_main_screen_stop_animation(U8 animation);

extern void mmi_medply_main_screen_set_file_path(U16* filename, MMI_BOOL file_f);
extern void mmi_medply_main_screen_set_status_and_ani(U8 status, U8 ani);
extern void mmi_medply_change_status(MMI_BOOL blt_f);
extern void mmi_medply_get_ui_status(U8* ui_status, U8* id_ani);

/*FTE*/
#ifdef __MMI_MEDIA_PLAYER_FTE__
extern void mmi_medply_main_screen_update_vol(void);
extern void mmi_medply_main_screen_update_mute(void);
extern void mmi_medply_main_screen_gesture_hdl(mmi_frm_gesture_event_enum event);
extern MMI_BOOL mmi_medply_main_screen_show_kuro_setting(void);
extern MMI_BOOL mmi_medply_check_gesture_valid(mmi_frm_gesture_rect_struct *rgn);
extern void mmi_medply_main_screen_close_popup_setting(void);
extern U8 mmi_medply_main_screen_update_rating(S16 x);
#endif

/* settings ListUI*/
#ifdef __MMI_MEDIA_PLAYER_PLST_DB_STYLE__
extern void mmi_medlpy_listui_fmgr_res_handle(cui_file_selector_result_event_struct *file_select);
extern void mmi_medply_settings_repeat_change(U8 index);
extern void mmi_medply_settings_shuff_change(U8 index);
#endif

/*
**  Module Name: Main Screen UI 
**  Add done.
*/

extern void mmi_medply_asm_delete(void);
/*****************************************/
/****           PlayList              ****/
/*****************************************/
extern void mmi_medply_shuffle_change_callback(U8 new_value);
extern void mmi_medply_plst_hilite_hdlr_init(void);
extern S32 mmi_medply_plst_module_init(void);
extern void mmi_medply_plst_module_deinit(void);
extern S32 mmi_medply_plst_load_last(void);
extern void mmi_medply_plst_entry_listmgr(void);
extern void mmi_medply_plst_entry_bookmark(void);
//extern void mmi_medply_plst_entry_playlist(void);
extern void mmi_medply_plst_entry_details(void);
extern void mmi_medply_plst_entry_now_playing(void);
#if defined(__MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__)
extern void mmi_medply_plst_entry_all_audio(void);
extern void mmi_medply_plst_entry_all_video(void);
extern S32 mmi_medply_plst_listmgr_list_all(void);
#endif /* __MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__ */

extern void mmi_medply_plst_get_error_string(S32 error_code, MMI_ID_TYPE* str_id, mmi_event_notify_enum *event_type);
extern S32 mmi_medply_plst_set_pick_index(S32 index);
extern void mmi_medply_plst_set_start(S32 index);
extern S32 mmi_medply_plst_do_pick(void);
extern S32 mmi_medply_plst_pick_next(void);
extern S32 mmi_medply_plst_pick_prev(void);

extern S32 mmi_medply_plst_apply_picked_file(void);

extern MMI_BOOL mmi_medply_plst_curr_is_empty(void);
extern MMI_BOOL mmi_medply_plst_curr_is_valid(void);

extern S32 mmi_medply_plst_curr_get_curr_index(void);
extern S32 mmi_medply_plst_curr_get_total(void);

extern U16 mmi_medply_util_is_support_format(const UI_string_type ext);
extern U16 mmi_medply_util_get_file_icon(U16 file_format);
extern void mmi_medply_util_extract_ext(const UI_string_type filename, UI_string_type ext);
extern void mmi_medply_util_split_filename_ext(const UI_string_type filename, UI_string_type filename_without_ext, UI_string_type ext);
extern void mmi_medply_util_extract_filename(UI_string_type filename, const UI_string_type path);
extern void mmi_medply_util_fill_idle_display_str(void);
extern U32 mmi_medply_determine_progress_speed(U64 duration);

extern void mmi_medply_plst_increase_played_counter(void);
extern void mmi_medply_plst_reset_played_counter(void);
extern void mmi_medply_plst_notify_file_not_available(mmi_medply_fail_play_enum type);/* added for eservice issue - 02017632 */

/* multiple extern */
#if (defined(__MMI_MEDIA_PLAYER__) && defined(__MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__)&& !defined(__MMI_MEDIA_PLAYER_PLST_DB_STYLE__)) 
extern S32 mmi_medply_plst_generate_append_internal(UI_string_type path, MMI_BOOL is_short, MMI_BOOL write_back_file_immediately);
extern S32 mmi_medply_plst_generate_init(U16 initiate_parent_id,U16 initiate_scr_id, mmi_medply_plst_generate_setting_struct in_setting);
extern void mmi_medply_plst_generate_deinit(void);

extern void mmi_medply_editor_close_function(void);
extern MMI_BOOL mmi_medply_plst_save_last_path(UI_string_type path);
extern S32 mmi_medply_plst_write_back_to_file(mmi_medply_plst_struct* list);
extern void mmi_medply_plst_reload_list(void);
extern void mmi_medply_plst_util_clear_gui_buffer(U16 scr_id);
extern S32 mmi_medply_plst_listmgr_create_part3(UI_string_type path);
extern S32 mmi_medply_plst_open(UI_string_type file_path);
extern void mmi_medply_entry_editor(void);
extern void mmi_medply_plst_listmgr_init(void);
#endif
#ifdef __MMI_MEDIA_PLAYER_PLST_DB_STYLE__
extern void mmi_medply_listui_entry_all_song_list(void);
extern void mmi_medply_listui_entry_all_video_list(void);
extern void mmi_medply_listui_entry_artist_list(void);
extern void mmi_medply_listui_reg_motion(void);
extern void mmi_medply_listui_dereg_motion(void);
extern void mmi_medply_listui_entry_album_list(void);
extern void mmi_medply_listui_entry_genre_list(void);
extern void mmi_medply_listui_entry_plst_list(void);
extern void mmi_medply_listui_entry_refresh_lib(void);
extern void mmi_medply_listui_reset_lib_req(void);
extern void mmi_medply_listui_entry_input_url(void);

extern void mmi_medply_plst_util_clear_gui_buffer(U16 scr_id);
extern void mmi_medply_entry_main_menu_scr(void);
extern MMI_BOOL mmi_medply_listui_allow_entry_main_menu(void);
extern void mmi_medply_listui_library_open_fail(S32 error);
extern void mmi_meply_plst_reset_all(void);
extern void mmi_medply_plst_store_rating(U8 rating);
extern void mmi_medply_plst_store_rating_smart(U8 rating);
extern void mmi_medply_plst_store_rating_flush(void);
extern void mmi_medply_prepare_mediaplayer(void);

extern void mmi_medply_listui_entry_curr_plst_list(void);

extern mmi_ret mmi_medply_listui_song_list_option_cui_proc(cui_menu_event_struct *menu_evt);
extern mmi_ret mmi_medply_listui_type_list_option_cui_proc(cui_menu_event_struct *menu_evt);
extern mmi_ret mmi_medply_listui_plst_list_option_cui_proc(cui_menu_event_struct *menu_evt);
extern mmi_ret mmi_medply_listui_multisel_option_cui_proc(cui_menu_event_struct *menu_evt);
extern mmi_ret mmi_medply_listui_multiadd_option_cui_proc(cui_menu_event_struct *menu_evt);
extern mmi_ret mmi_medply_listui_editor_cui_proc(mmi_event_struct *evt);
#ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
extern mmi_ret mmi_medply_listui_inline_cui_proc(mmi_event_struct *evt);
extern mmi_ret mmi_medply_listui_song_list_search_option_cui_proc(cui_menu_event_struct *menu_evt);
extern mmi_ret mmi_medply_listui_type_list_search_option_cui_proc(cui_menu_event_struct *menu_evt);
#endif

extern void mmi_medply_listui_set_goback_inendkey(MMI_BOOL flag);
extern MMI_BOOL mmi_medply_listui_is_goback_inendkey(void);
/* Menu CUI */
extern void mmi_medply_listui_set_main_menu_cui_grp_id(mmi_id menu_id);
extern MMI_BOOL mmi_medply_listui_is_main_menu_grp_created(void);

#ifdef __MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__
extern MMI_BOOL mmi_medply_listui_exit_image_flow(void);
extern mmi_ret  mmi_medply_listui_imgfl_delete_callback(mmi_event_struct *param);
extern MMI_BOOL mmi_medply_listui_imgflow_listsrv_init(
            S32(*callback)(srv_plst_cb_evt_enum cb_event, S32 result, U32 ca_para_2));
extern MMI_BOOL mmi_medply_listui_imgflow_listsrv_deinit(void);
extern S32 mmi_medply_listui_imgflow_get_count(U32* total);
extern S32 mmi_medply_listui_imgflow_get_item_name(srv_plst_list_get_display_struct* item_display);
extern S32 mmi_medply_listui_imgflow_get_artist(srv_plst_list_get_display_struct* item_display);
extern S32 mmi_medply_listui_imgflow_get_artwork_aync(srv_plst_list_get_display_struct* param_artwork);
extern S32 mmi_medply_listui_imgflow_get_artwork_aync_stop(void);
extern S32 mmi_medply_listui_imgflow_get_focus_idx(void);
extern void mmi_medply_listui_imgflow_set_focus_idx(U32 index);
extern MMI_BOOL mmi_medply_listui_imgflow_play(U32 index);
#ifdef MOTION_SENSOR_SUPPORT
#include  "SensorSrvGport.h"

/*
extern void mmi_medply_listui_tilt_hdlr(mdi_motion_angle_enum direction,
                                 mdi_motion_action_enum action,
                                 mdi_motion_tilt_detail_struct *detail,
                                 void *user_data);*/

extern void mmi_medply_listui_tilt_hdlr(srv_sensor_type_enum sensor_type, void *sensor_data,
							void *user_data);

MMI_BOOL mmi_medply_listui_check_motion_valid(MMI_ID scr_id);
#endif /* MOTION_SENSOR_SUPPORT */
#endif /* __MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__ */
#else

/* media player main menu list proc */
extern mmi_ret mmi_medply_event_proc(mmi_event_struct *evt);


#endif /* __MMI_MEDIA_PLAYER_PLST_DB_STYLE__ */

#ifdef __MMI_KURO_SUPPORT__
extern S32 mmi_medply_plst_get_kurofile_path(UI_string_type filepath);
extern S32 mmi_medply_kuro_check_current_kuro_folder_exist(void);
extern S32 mmi_medply_kuro_check_current_playlist_folder_exist(void);
#endif

#ifdef __MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__
extern S32 mmi_medply_plst_add_to_recent_played(void);
extern void mmi_medply_plst_module_corrupt_scr(void);
#endif

#ifdef __MMI_MEDIA_PLAYER_INTRO_PLAY__
extern S32 mmi_medply_plst_single_apply_picked_file(void);
extern S32 mmi_medply_plst_single_do_pick(void);
#endif	/* __MMI_MEDIA_PLAYER_INTRO_PLAY__ */
/*****************************************/
/****           Settings              ****/
/*****************************************/
extern void mmi_medply_settings_entry_main(void);
extern void mmi_medply_init_settings(void);
extern MMI_BOOL mmi_medply_settings_read_value(mmi_medply_settings_type_enum enum_value, void * data_value);
extern MMI_BOOL mmi_medply_settings_write_value(mmi_medply_settings_type_enum enum_value, void* data_value); 
extern MMI_BOOL mmi_medply_settings_write_value_ext(mmi_medply_settings_type_enum enum_value, void* data_value, MMI_BOOL is_flush);
extern mdi_result mmi_medply_settings_check_and_set_audio_speed(void);
extern MMI_BOOL mmi_medply_settings_is_audio_speed_normal(void);
extern MMI_BOOL mmi_medply_settings_check_mute_from_video_speed(void);
extern mdi_result mmi_medply_settings_check_and_set_pure_audio_speed(void);
extern void mmi_medply_setting_deinit_hdlr(void);
extern U8 mmi_medply_setting_get_preview_file_drv_letter(void);
extern MMI_BOOL mmi_medply_setting_check_drm_display_perm(PU16 filepath);
extern void mmi_medply_del_all_app_screen(void);
extern void mmi_medply_entry_video_recoder(void);

#ifdef __MMI_MEDIA_PLAYER_STREAM__
/*for WLAN prefer use*/
extern void mmi_medply_register_bear_event(mmi_proc_func callback);
extern void mmi_medply_deregister_bear_event(void);
extern void mmi_medply_register_bear_info(mmi_proc_func callback);
extern void mmi_medply_deregister_bear_info(void);
#endif

#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
void mmi_medply_settings_subtitle_iso_startup(void);
void mmi_medply_settings_subtitle_iso_shutdown(void);
void mmi_medply_settings_subtitle_iso_add_iso_element(U32 track_index, U32 iso_element);
void mmi_medply_settings_subtitle_iso_set_active_iso(U32 track_index, U32 iso_element);
#endif


#if defined(__MMI_A2DP_SUPPORT__)
extern void mmi_medply_settings_check_a2dp(MMI_BOOL bt_a2dp_output);
extern MMI_BOOL mmi_medply_settings_is_output_to_bt(void);
extern srv_bt_cm_bt_addr* mmi_medply_settings_get_bt_headset(void);
#endif /* defined(__MMI_A2DP_SUPPORT__)*/

#ifdef __MMI_TOUCH_SCREEN__ 
extern void mmi_medply_settings_toggle_repeat(void);
extern void mmi_medply_settings_toggle_shuffle(void);
#endif /*__MMI_TOUCH_SCREEN__*/

#ifdef __MMI_VIDEO_3D_ANAGLYPH__
void mmi_medply_settings_toggle_play_mode(void);
#endif


#ifdef __MMI_KURO_SUPPORT__
extern U16 mmi_medply_kuro_function_display_err_popup(KURO_FUN_CODE status,mmi_event_notify_enum *result_type);
extern void mmi_medply_kuro_get_activate_folder(UI_string_type folderpath);
extern S32 mmi_medply_kuro_get_activate_filepath(UI_string_type filepath);
extern void mmi_medply_kuro_allocate_asm(void);
extern void mmi_medply_kuro_free_asm(void);
#endif

#ifndef __MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__
MMI_BOOL mmi_medply_plst_curr_title_is_short(void);
#endif

#if defined (__PLST_SERVICE_DB_SUPPORT__)
extern S32 mmi_medply_list_extapp_startup(S32 *p_handle, 
                    S32(*callback)(srv_plst_cb_evt_enum cb_event, S32 result, U32 ca_para_2));
void mmi_medply_list_extapp_logoff(void);
extern S32 mmi_medply_plst_add_to_recent_played(void);
#endif /*defined (__PLST_SERVICE_DB_SUPPORT__)*/

#ifdef __MMI_MEDIA_PLAYER_VIDEO__
MDI_RESULT mmi_medply_adption_video_seek_and_get_frame(U64 time, 
                                   gdi_handle player_layer_handle
                                   #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
                                   , gdi_handle subtitle_layer_handle
                                   #endif
                                   );
MDI_RESULT mmi_medply_adption_video_non_block_seek_and_get_frame(
            U64 time,
            gdi_handle player_layer_handle,
            #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
            gdi_handle subtitle_layer_handle,
            #endif
            mdi_seek_result_callback seek_result_callback,
            void *user_data);
MDI_RESULT mmi_medply_adption_video_play(
            gdi_handle player_layer_handle,
            U32 blt_layer_flag,
            U32 play_layer_flag,
            #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
            gdi_handle subtitle_layer_handle,
            U32 subtitle_layer_flag,
            #endif
            U16 repeat_count,
            BOOL is_visual_update,
            BOOL is_play_audio,
            U8 audio_path,
            U16 rotate,
            S16 play_speed,
            mdi_play_finish_callback play_finish_callback,
            void *user_data);
MDI_RESULT mmi_medply_adption_video_update_layer_resume(
            gdi_handle player_layer_handle,
            U32 blt_layer_flag,
            U32 play_layer_flag,
            #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
            gdi_handle subtitle_layer_handle,
            U32 subtitle_layer_flag,
            #endif
            BOOL is_visual_update,
            U16 rotate); 
MDI_RESULT mmi_medply_adption_video_get_frame(gdi_handle player_layer_handle
                                         #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
                                         ,gdi_handle subtitle_layer_handle
                                         #endif
                                          );
#endif

#endif /*__MMI_MEDIA_PLAYER__*/

#endif /* MEDIA_PLAYER_PROT_H */ 

