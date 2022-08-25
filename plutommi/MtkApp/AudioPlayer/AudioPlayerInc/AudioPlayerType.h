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
*  AudioPlayerType.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Audio player type definition
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
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#ifndef _AUDIO_PLAYER_TYPE_H
#define _AUDIO_PLAYER_TYPE_H

/*
 * Need to include:
 * (1) gui_data_types.h
 * (3) kal_release.h
 * (4) Conversions.h
 * (5) FrameworkStruct.h
 * (6) GlobalConstants.h
 * (7) FileMgr.h
 * (8) AudioPlayerDef.h
 */
 #include "MMI_features.h"
 #include "MMIDataType.h"
 #include "gui_data_types.h"
 #include "kal_general_types.h"
 #include "AudioPlayerDef.h"
#ifdef __MMI_AUDIO_PLAYER__

//#include "aud_id3_parser.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "Conversions.h"

//#include "AudioPlayerPlayList.h"
#include "Filemgrsrvgprot.h"
//#include "FilemgrCuiGprot.h"

#if defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__)||defined(__MMI_VUI_LAUNCHER_KEY__)
#include "MediaAppWidgetDef.h"
#endif

#ifdef __MMI_NCENTER_SUPPORT__
#include "..\venusmmi\app\common\ncenter\Vsrv_ncenter.h"
#endif

#ifdef __MMI_AUDPLY_WALK_PLAY__
#include "AudioPlayerWalk.h"
#endif  //__MMI_AUDPLY_WALK_PLAY__


typedef struct
{
    U32 duration; /*song duration in MS*/
    U32 progress_speed; /*progress speed choosed according to duration*/

    /* settings */
    U8 list_auto_gen;
    U8 preferred_list;
	U8 remove_process;
    U8 skin;
    U8 repeat_mode;     /* 0: off, 1: repeat one, 2: repeat all */
    U8 random_mode;     /* 0: off, 1: on */
    U8 background_play; /* o: off, 1: on */
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__ 
    U8 spectrum_style;  /* 0: off,  1, 2(, 3): styles */
#endif 
#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
    U8 lyrics_display;  /* o: off, 1: on */
#endif
#ifdef __MMI_NCENTER_SUPPORT__
      vsrv_ngroup_handle ghandle;
      vsrv_notification_handle nhandle;
#endif
    /* present play list */
    U8 present_list;

    /* cmd & states */
    UI_character_type title[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
#ifdef __MMI_SUBLCD__
    UI_character_type sub_title[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
#endif
    UI_character_type filefullname[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    /*the file name that cache content belongs to*/
    UI_character_type prev_filefullname[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    MMI_BOOL file_name_identical;
    U8 state;
    U8 state_before_longpress;
    MMI_BOOL seekable; /*indicate if it is seekable or not*/
    MMI_BOOL need_to_build_cache; /*need to build cache to seek*/

    U8* audio_cache_file_buf_p ; /*ptr for build cache file buffer*/
    U8* audio_cache_proc_buf_p ; /*ptr for build cache process buffer*/

    MMI_BOOL wait_next;
    MMI_BOOL need_replay;  /*inidcate if it needs to be replayed once it is suspeneded, effect mmi_audply_background_callback_hdlr()*/
    U32 successive_fail_num; /*indicate the total number of successively play file*/

#if defined(MT6223) || defined(MT6223P)
    MMI_BOOL support_A2DP;
#endif

#ifdef __DRM_SUPPORT__
    MMI_BOOL DRM_consumed ;
#endif

    MMI_BOOL is_support_pause;

    MMI_BOOL in_main_screen;
    MMI_BOOL in_list_screen;
    MMI_BOOL in_audio_player;
    MMI_BOOL wait_next_with_pop_up;
#ifdef __MMI_AUDPLY_PLAYLIST_GEN_ASYN__
    MMI_BOOL is_reenter;   //to generate playlist
#endif
#ifdef __MMI_FTE_SUPPORT__
    audply_pen_states_enum curr_pen_state;
#endif
    U8 volume;
    U8 volume_nvram; /*store volume value in nvram*/
    
    /* duration */
    U32 old_play_time;  /*the lastest play time shown on main screen*/
    U32 new_play_time;  /*the latest play time get from hardware*/


    MMI_BOOL is_subLCD_shown;

#ifdef __MMI_AUDIO_TIME_STRETCH__
    U16 speed;
    U8 speed_set_times;
//#ifdef __MMI_A2DP_SUPPORT__
//    MMI_BOOL speed_changed; /*for a2dp reconfig check*/
//#endif
#endif /* __MMI_AUDIO_TIME_STRETCH__ */ 
#ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__
    MMI_BOOL in_sub_screen;       /*audio player on sub LCD main screen*/
    MMI_BOOL in_sub_list_screen; /*audio player on sub LCD play list screen*/
#endif
#if defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__)|| defined(__MMI_VUI_LAUNCHER_KEY__)
    void(* widget_callback)(void*, mmi_widget_player_callback_enum, void*);
    void* widget_callback_userdata;
#endif
#ifdef __MMI_AUDPLY_WALK_PLAY__
    audply_play_style play_style;
    mmi_audply_walk_struct walk;
#endif  //__MMI_AUDPLY_WALK_PLAY__
} audply_struct;


typedef struct
{
    S16 x, y;
    S16 w, h;
}audply_main_rect_struct;

#ifdef __MMI_AUDIO_PLAYER_SKIN_SLIM__
typedef struct
{
    PU8 audply_main_bg_img;
    S16 audply_main_bg_panel_x;
	S16 audply_main_bg_panel_y;
    PU8 audply_main_bg_panel_img;
    gdi_color audply_main_bg_color;
    PU8 audply_main_bg_title_img;
    audply_main_rect_struct audply_main_bg_title;
    PU8 audply_main_bg_progress_img;
    audply_main_rect_struct audply_main_bg_progress;
    PU8 audply_main_bg_volume_img;
    audply_main_rect_struct audply_main_bg_volume;
    gdi_color audply_main_bg_softkey_color;
    PU8 audply_main_bg_button_img;
    PU8 audply_main_button_img_hilite;
    PU8 audply_main_button_img_disable;
} audply_main_bg_struct;
#endif

typedef struct
{
    S16 x, y;
    S16 w, h;
} audply_main_title_struct;

#ifdef __MMI_AUDIO_PLAYER_SKIN_SLIM__
typedef struct
{
    S16 x1, y1;
    S16 x2, y2;
    U16 num_id[10];
    U16 col_id;
} audply_main_time_struct;
#else
typedef struct
{
    S16 x, y;
    S16 w, h;
} audply_main_time_struct;
#endif

typedef struct
{
    S16 x, y;
    S16 w, h;
} audply_main_file_index_struct;

typedef struct
{
    S16 x, y;
    S16 w, h;
    PU8 list_icon[NO_OF_LIST];
} audply_main_playlisticon_struct;

typedef struct
{
    S16 x, y;
    S16 w, h;
    S16 ind_len;
    PU8 ind_img;
    U8  bar_direction; /* 0:horizonal, 1: vertical */
} audply_main_volumebar_struct;

typedef struct
{
    S16 x, y;
    S16 w, h;
#ifdef __MMI_FTE_SUPPORT__    
    PU8 img_bg;
#endif    
    PU8 img;
    PU8 img_fail ;
}audply_main_progressbar_struct;

typedef struct
{
    S16 x, y;
    S16 w, h;
    PU8 up_img, down_img, disable_img;
    MMI_BOOL down;
} audply_main_volumectrl_struct;

#ifdef __MMI_TOUCH_SCREEN__
typedef struct
{
    S16 x, y;
    S16 w, h;
    PU8 up_img, down_img;
    MMI_BOOL down;
} audply_main_setting_struct;
#endif /* __MMI_TOUCH_SCREEN__ */ 

typedef struct
{
    S16 x, y;
    S16 w, h;
    PU8 off_img, disabled_img, down_img;
} audply_main_button_struct;

#if  defined(__MMI_AUDIO_PLAYER_ANIMATION__)  || defined(__MMI_FTE_SUPPORT__)
typedef struct
{
    S16 x, y;
    S16 w, h;
    gdi_handle img_handle;
    PU8 animation_img;
} audply_main_animation_struct;
#endif /* __MMI_AUDIO_PLAYER_ANIMATION__  || __MMI_FTE_SUPPORT__ */ 


#ifdef __MMI_FTE_SUPPORT__
typedef struct
{
    S16 x, y;
    S16 w, h;
}audply_main_spec_animation_struct;
#endif /*__MMI_FTE_SUPPORT__*/

#if defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__) || defined(__MMI_AUDIO_PLAYER_SKIN_SLIM__)
typedef struct
{
    S16 x, y;
    S16 w, h;
    PU8 off_up_img, all_up_img, one_up_img;
    PU8 off_down_img, all_down_img, one_down_img;
    MMI_BOOL down;
} audply_main_repeat_struct;
typedef struct
{
    S16 x, y;
    S16 w, h;
    PU8 off_up_img, on_up_img;
    PU8 off_down_img, on_down_img;
    MMI_BOOL down;
} audply_main_shuffle_struct;
#endif /* __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__ */ 

#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__

#define FIND_TAG_END                                              \
do{                                                                 \
   if ((cur_char = (U16*)mmi_ucs2chr((CHAR*)cur_char, L']')) == NULL)\
         return MMI_TRUE;                                             \
   else                                                           \
      status = TAG_END;                                           \
}while(0)

#define TRIM_LEFT                                                  \
do{                                                                  \
   cur_char = (U16*)mmi_ucs2trim_left((CHAR*)cur_char,(CHAR*)L" \t\r\n");\
   if (!cur_char)                                                  \
      return MMI_TRUE;                                                 \
}while(0)

typedef struct audply_lyric_line
{
    S32 time;
    CHAR *line_lyric1;
    struct audply_lyric_line *next;
} audply_lyric_line_struct;

typedef struct
{
    MMI_BOOL is_ready;
    S32 lyric_count;
    UI_character_type lyric_file_path[((SRV_FMGR_PATH_MAX_LEN+1) + 5) *ENCODING_LENGTH];
    audply_lyric_line_struct lyric[AUDPLY_LYRIC_MAX_LINE_COUNT];

    audply_lyric_line_struct *first_line;
    audply_lyric_line_struct *cur_line;
    S32 offset_time;
    mmi_chset_enum lrc_encoding_chset;
} audply_lyric_struct;

typedef struct
{
    S16 start_x;
    S16 start_y;
    S32 width;
    S32 height;
    color lyric_fg_color;
    color lyric_border_color;
    GDI_HANDLE target_layer;
} audply_lyric_printing_struct;

#endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 

#ifdef __MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__
#define MMI_AUDPLY_UI_UPDATE_PLAY_TIME 400
#define MMI_AUDPLY_LYRICS_MAX_LINE		5
#define MMI_AUDPLY_LYRICS_GAP_H               2 
#define MMI_AUDPLY_LYRICS_FOCUS_COLOR_FG      gui_color(84, 203, 227)
#define MMI_AUDPLY_LYRICS_FOCUS_COLOR_BG      gui_color(128, 128, 0)
#define MMI_AUDPLY_LYRICS_NORMAL_COLOR_FG     gui_color(203, 203, 203)
#define MMI_AUDPLY_LYRICS_NORMAL_COLOR_BG     gui_color(101, 101, 101)



typedef struct
{
    S16 x;
    S16 y;    
    S16 w;
    S16 h;

} mmi_audply_rect_struct;

typedef struct
{
    S16 r;
    S16 g;    
    S16 b;

} mmi_audply_color_struct;


typedef struct
{    
    mmi_audply_rect_struct rgn_txt;
    mmi_audply_rect_struct rgn_clip;
	mmi_audply_color_struct color;
    U16 last_time;
    U16 curr_time;
    U16 next_time;
    U16 line_focus_id;
    U16 time_out;
    U16 line_id[MMI_AUDPLY_LYRICS_MAX_LINE+1];  /*add 1 for scroll display*/ 
    U8  line_focus;
    U8  line_count;
    U8  font_height;
    U8  line_height;
	U8  is_ready;
    
} mmi_audply_lyrics_box_struct;

#endif/*__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__ */


#endif /* __MMI_AUDIO_PLAYER__ */ 

#endif /* _AUDIO_PLAYER_TYPE_H */ 

