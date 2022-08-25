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
*  AudioPlayerDef.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Audio player main screen
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
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#ifndef AUDIO_PLAYER_DEF_H
#define AUDIO_PLAYER_DEF_H

#include "MMI_features.h"
#include "MMIDataType.h"

#ifdef __MMI_AUDIO_PLAYER__

#if defined(__MMI_AUDPLY_MULTILPE_LIST__)
    #undef __MMI_AUDIO_PLAYER_SINGLE_LIST__
    #undef __MMI_AUDIO_PLAYER_ON_SUBLCD__
#endif

#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
    #undef __MMI_AUDPLY_MULTILPE_LIST__
#endif

#if defined(__MMI_SLIM_IMG_RES__) || defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__)
	#define __MMI_AUDIO_PLAYER_SKIN_SLIM__
#endif


#if defined(__MMI_AUDIO_PLAYER_SKIN_SLIM__)
    #undef __MMI_AUDIO_PLAYER_SKIN_SHOW_VOL_CTL__
#else
    #define __MMI_AUDIO_PLAYER_SKIN_SHOW_VOL_CTL__
#endif


#define MMI_AUDPLY_NOT_ALLOW_PLAY   (-1)

typedef enum
{
    LIST_FROM_PHONE,
    LIST_FROM_CARD,
    NO_OF_LIST
} audply_playlist_enum;

typedef enum
{
    SKIN1,
#ifndef __MMI_SLIM_AUDIO_PLAYER__
#ifndef __MMI_AUDIO_PLAYER_SKIN_SLIM__
SKIN2,
SKIN3,
#endif
#endif /* __MMI_SLIM_AUDIO_PLAYER__ */ 
    NO_OF_SKIN
} audply_skin_enum;

/*skins for sub LCD SKIN1_SUB for 96X64 SKIN2_SUB for 128X128*/

typedef enum
{
    REPEAT_OFF,
    REPEAT_ONE,
    REPEAT_ALL
} audply_repeat_enum;

typedef enum
{
    SHUFFLE_OFF,
    SHUFFLE_ON
} audply_shuffle_enum;

typedef enum
{
    HORIZONTAL_VOL_BAR,
    VERTICAL_VOL_BAR
} audply_vol_bar_enum;

typedef enum
{
    NON_UCS2,
    UCS2_LITTLE_ENDIAN,
    UCS2_BIG_ENDIAN
} audply_UCS2_encode_enum;

typedef enum
{
    AUDPLY_MAIN_DISABLED = -1,
    AUDPLY_MAIN_PLAY = 0,
    AUDPLY_MAIN_PREV,
    AUDPLY_MAIN_NEXT,
    AUDPLY_MAIN_STOP,
    AUDPLY_MAIN_PAUSE,
    NO_OF_AUDPLY_MAIN_BUTTONS
} audply_main_buttons_enum;

typedef enum
{
    AUDPLY_MAIN_UP,
    AUDPLY_MAIN_DOWN,
    AUDPLY_MAIN_DISABLE,

    NO_OF_AUDPLY_BUTTONS_STATE
} audply_buttons_state_enum;

#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
#define  AUDPLY_LYRIC_MAX_LINE_COUNT      200   /* pre-defined number of lyirc lines */
#define  AUDPLY_LYRIC_STR_BUFF_MAX_SIZE   (8 * 1024)  /* pre-defined max lyric string buffer size : bytes */
#define  AUDPLY_LYRIC_TMP_BUFF_MAX_SIZE   128   /* pre-defined max lyric buffer size for one line : bytes ; must be two bytes aligned */

typedef enum
{
    LINE_START,
    LINE_END,
    TAG_START,
    TAG_END,
    TAG_LYRIC1,
    TAG_TIME1,
    TAG_TIME2,
    TAG_TIME3,
    TAG_MS,
    TAG_ID_AR,
    TAG_ID_TI,
    TAG_ID_AL,
    TAG_ID_BY,
    TAG_ID_OFFSET
} audply_lyric_parse_status_enum;

#endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 

#ifdef __MMI_TOUCH_SCREEN__
typedef enum
{
    AUDPLY_PEN_NONE,
    AUDPLY_PEN_LSK,
    AUDPLY_PEN_RSK,
    AUDPLY_PEN_SEEK,
    AUDPLY_PEN_MAIN_PREV,
    AUDPLY_PEN_MAIN_NEXT,
    AUDPLY_PEN_MAIN_STOP,
    AUDPLY_PEN_MAIN_PLAY,
    AUDPLY_PEN_MAIN_SETTING,
//    AUDPLY_PEN_MAIN_PLAY_LIST,
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__    
    AUDPLY_PEN_MAIN_REPEAT,
    AUDPLY_PEN_MAIN_SHUFFLE,
#endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/
    AUDPLY_PEN_MAIN_VOLUME_INC,
    AUDPLY_PEN_MAIN_VOLUME_DEC,
    AUDPLY_PEN_COUNT
} AUDPLY_PEN_STATE;
#endif
#ifdef __MMI_FTE_SUPPORT__
typedef enum
{
	AUDPLY_PEN_CURR_NONE,
	AUDPLY_PEN_PRESSED,
	AUDPLY_PEN_RELEASED
}audply_pen_states_enum;
#endif

#define BUILD_CACHE_SIZE (2*1024)  /*audio build cache size*/
#define BUILD_CACHE_FILE_BUF_SIZE 1024 /*audio build cache file buffer size*/
#define BUILD_CACHE_PROC_BUF_SIZE (32*1024) /*audio build cache process buffer size*/

typedef enum
{
#ifdef DAF_DECODE
    DAF_FORMAT_FOR_CACHE,
#ifdef MUSICAM_DECODE    
    MP2_FORMAT_FOR_CACHE,
#endif
#endif 
    AMR_FORMAT_FOR_CACHE,
#ifdef AAC_DECODE
    AAC_FORMAT_FOR_CACHE,
#endif 
#ifdef AMRWB_DECODE
    AWB_FORMAT_FOR_CACHE,
#endif 
#ifdef BSAC_DECODE
/* under construction !*/
#endif
#ifdef __DRM_V02__
    ODF_FORMAT_FOR_CACHE,
#endif
    WAV_FORMAT_FOR_CACHE,

    /*number of file types,counting from BEGINING, defines in 
    audio_file_lower_exts that need to build cache to seek*/
    NEED_TO_BUILD_CACHE_NUM
} need_to_build_cache_format_enum;

typedef enum
{
    
    AMR_FORMAT_NOT_SUPPORT_A2DP,
    NOT_SUPPORT_A2DP_NUM
} not_support_a2dp_enum;

typedef enum
{
    AUDPLY_PLAYER_SETTING =0 ,
    AUDPLY_DISPLAY_SETTING,
    AUDPLY_SOUND_EFFECT_SETTING,
    AUDPLY_BT_SETTING  
}two_layer_settings_enum;


typedef enum
{
#ifdef DAF_DECODE
    AUDPLY_AUDIO_FILE_TYPE_DAF,
#ifdef MUSICAM_DECODE    
    AUDPLY_AUDIO_FILE_TYPE_MP2,
#endif
#endif 
    AUDPLY_AUDIO_FILE_TYPE_AMR,
#ifdef AAC_DECODE
    AUDPLY_AUDIO_FILE_TYPE_AAC,
#endif 
#ifdef AMRWB_DECODE
    AUDPLY_AUDIO_FILE_TYPE_AWB,
#endif 
#ifdef BSAC_DECODE
/* under construction !*/
#endif
#ifdef __DRM_V02__
    AUDPLY_AUDIO_FILE_TYPE_ODF,
#endif
    AUDPLY_AUDIO_FILE_TYPE_WAV,
    AUDPLY_AUDIO_FILE_TYPE_MID,
    AUDPLY_AUDIO_FILE_TYPE_MIDI,
    AUDPLY_AUDIO_FILE_TYPE_IMY,
//    AUDPLY_AUDIO_FILE_TYPE_VM,
#ifdef AIFF_DECODE
    AUDPLY_AUDIO_FILE_TYPE_AIF,
    AUDPLY_AUDIO_FILE_TYPE_AIFF,
    AUDPLY_AUDIO_FILE_TYPE_AIFC,
#endif /* AIFF_DECODE */
#ifdef AU_DECODE
    AUDPLY_AUDIO_FILE_TYPE_AU,
    AUDPLY_AUDIO_FILE_TYPE_SND,
#endif /* AU_DECODE */
#ifdef M4A_DECODE
    AUDPLY_AUDIO_FILE_TYPE_M4A,
#endif 
#ifdef YAMAHA_MA3
    AUDPLY_AUDIO_FILE_TYPE_MMF,
#endif 
#ifdef WMA_DECODE
    AUDPLY_AUDIO_FILE_TYPE_WMA,
#endif 
#if defined(__MMI_PURE_AUDIO__)
    AUDPLY_AUDIO_FILE_TYPE_3GP,
    AUDPLY_AUDIO_FILE_TYPE_MP4,
#endif

#ifdef __RM_DEC_SUPPORT__
	AUDPLY_AUDIO_FILE_TYPE_RA,
#endif   
	
#ifdef __APE_DECODE__
	AUDPLY_AUDIO_FILE_TYPE_APE,
#endif   

    NO_AUDIO_FILE_TYPES
} audply_audio_file_type_enum;

#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__)
typedef struct
{
    S16 x, y;
    S16 w, h;
    PU8 up_img, dis_img;
} audply_main_push_button_struct;
#endif

#if defined(__MMI_TOUCH_SCREEN__) || defined (__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__)
typedef struct
{
    S16 x;
    S16 y;
} audply_point_struct;

typedef struct
{
    const audply_point_struct *points;
    S16 num;
} audply_polygon_area_struct;
#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_FTE_SUPPORT__


#if defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__)

typedef struct
{
    U16 bg_image_id;
    S16 bg_panel_x, bg_panel_y;
    U16 bg_panel_id;
    U16 option_up_id, option_down_id, back_up_id, back_down_id;
    U8 bg_color_r, bg_color_g, bg_color_b;
	S16 lsk_pos_x, lsk_pos_y;
    U16 lsk_up_img_id, lsk_down_img_id;
	S16 rsk_pos_x, rsk_pos_y;
    U16 rsk_up_img_id, rsk_down_img_id;
    U16 fg_down_id;
    U16 fg_disable_id;
    U8 text_border_color_r, text_border_color_g, text_border_color_b;
    U8 text_fg_color_r, text_fg_color_g, text_fg_color_b;
    U8 text_bg_color_r, text_bg_color_g, text_bg_color_b;
    S16 file_index_x, file_index_y;
    S16 file_index_w, file_index_h;
    S16 title_x, title_y;
    S16 title_w, title_h;
    U16 bg_title_image_id;
    S16 speaker_x, speaker_y, speaker_w, speaker_h;
    U16 speaker_up_id;
    U16 speaker_down_id;
    U16 speaker_mute_up_id;
    U16 speaker_mute_down_id;
	
    S16 volumebar_x, volumebar_y;
    S16 volumebar_w, volumebar_h;
    S16 volumebar_ind_len;
    U8  volumebar_direction;
    U16 bg_volume_image_id;
    U16 volumebar_ind_image_id;
    S16 progressbar_x, progressbar_y;
    S16 progressbar_w, progressbar_h;
    U16 bg_progress_image_id;
    U16 progressbar_image_id;
    U16 progressbar_fail_image_id;
    S16 prev_button_x, prev_button_y;
    U16 bg_button_id;
    U16 prev_button_image_id;
    U16 prev_button_dis_image_id;
    S16 next_button_x, next_button_y;
    U16 next_button_image_id;
    U16 next_button_dis_image_id;
    S16 play_button_x, play_button_y;
    U16 play_button_image_id;
    U16 play_button_dis_image_id;
    U16 pause_button_image_id;
    S16 stop_button_x, stop_button_y;
    U16 stop_button_image_id;
#ifdef __MMI_AUDIO_PLAYER_ANIMATION__
    S16 animation_x, animation_y;
    U16 animation_image_id;
#endif /* __MMI_AUDIO_PLAYER_ANIMATION__ */ 
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    S16 spectrum_display_x, spectrum_display_y;
    S16 spectrum_display_w, spectrum_display_h;
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 

#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
    U8 lyric_fg_color_r, lyric_fg_color_g, lyric_fg_color_b;
    U8 lyric_border_color_r, lyric_border_color_g, lyric_border_color_b;
    S16 lyric_display_x, lyric_display_y;
    S16 lyric_display_w, lyric_display_h;
#endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 
#if defined( __MMI_AUDIO_SPECTRUM_DISPLAY__) && (defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)) 
    U8 spectrum_lyrics_exclusive ;
#endif
    S16 repeat_x, repeat_y;
    U16 repeat_off_image_id, repeat_all_image_id, repeat_one_image_id;
    S16 shuffle_x, shuffle_y;
    U16 shuffle_off_image_id, shuffle_on_image_id;
#ifdef __MMI_TOUCH_SCREEN__
    audply_polygon_area_struct seek_area;
    audply_polygon_area_struct prev_button_area;
    audply_polygon_area_struct next_button_area;
    audply_polygon_area_struct play_button_area;
    audply_polygon_area_struct stop_button_area;
    audply_polygon_area_struct repeat_area;
    audply_polygon_area_struct shuffle_area;
#endif /* __MMI_TOUCH_SCREEN__ */ 
    S16 time_left_x, time_left_y;
    S16 time_right_x, time_right_y;
    U16 ticks_image_id[11];
#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    S16 line_img_x, line_img_y;
    S16 line_img_w, line_img_h;
    U16 line_img_id;
#endif
} audply_skin_struct;

#else

typedef struct
{
    U16 bg_image_id;
    U8 text_border_color_r, text_border_color_g, text_border_color_b;
    U8 text_fg_color_r, text_fg_color_g, text_fg_color_b;
    U8 text_bg_color_r, text_bg_color_g, text_bg_color_b;
	  /*left soft key*/
    S16 lsk_pos_x, lsk_pos_y;           
    U16 lsk_up_img_id;
    U16 lsk_down_img_id;
      /* Right soft key*/
    S16 rsk_pos_x, rsk_pos_y;           
    U16 rsk_up_img_id;
    U16 rsk_down_img_id;	  
	  
    S16 title_x, title_y;
    S16 title_w, title_h;
    S16 time_x, time_y;
    S16 time_w, time_h;
    S16 file_index_x, file_index_y;
    S16 file_index_w, file_index_h;
	S16 playlisticon_x, playlisticon_y;
    U16 playlisticon_images_id[NO_OF_LIST];
	S16 playlisticon_w,playlisticon_h; 
    S16 volumebar_x, volumebar_y, volumebar_ind_len;
    U8  volumebar_direction;
    U16 volumebar_ind_image_id;
	/*File duration*/
	S16 time_pos_x, time_pos_y;
    U16 time_base_number_img_id;
    U16 time_colon_img_id;
    U16 time_bias_img_id;    
	
	/* Progress Bar */
    S16 progressbar_x, progressbar_y;
    U16 progressbar_image_id_bg;
    U16 progressbar_image_id_fg;
   	U16 progressbar_image_id_mg;
    U16 progressbar_fail_image_id;
  
  /* Progress button button*/
    S16 progressbar_btn_x,progressbar_btn_y;
    U16 progressbar_btn_img_id;
    U16 progressbar_btn_img_hl_id;

    S16 prev_button_x, prev_button_y;
    U16 prev_button_off_image_id, prev_button_disabled_image_id, prev_button_down_image_id;
    S16 next_button_x, next_button_y;
    U16 next_button_off_image_id, next_button_disabled_image_id, next_button_down_image_id;
    S16 play_button_x, play_button_y;
    U16 play_button_off_image_id, play_button_disabled_image_id, play_button_down_image_id;
    U16 pause_button_off_image_id, pause_button_down_image_id;
    S16 stop_button_x, stop_button_y;
    U16 stop_button_off_image_id, stop_button_disabled_image_id, stop_button_down_image_id;
    S16 animation_x, animation_y;
    U16 animation_image_id;

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    S16 spectrum_display_x, spectrum_display_y;
    S16 spectrum_display_w, spectrum_display_h;
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 

#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
    U8 lyric_fg_color_r, lyric_fg_color_g, lyric_fg_color_b;
    U8 lyric_border_color_r, lyric_border_color_g, lyric_border_color_b;
    S16 lyric_display_x, lyric_display_y;
    S16 lyric_display_w, lyric_display_h;
#endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 
#if defined( __MMI_AUDIO_SPECTRUM_DISPLAY__) && (defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__))
    U8 spectrum_lyrics_exclusive ;
#endif

    S16 repeat_x, repeat_y;
    U16 repeat_off_up_image_id, repeat_all_up_image_id, repeat_one_up_image_id;
    U16 repeat_off_down_image_id, repeat_all_down_image_id, repeat_one_down_image_id;

    S16 shuffle_x, shuffle_y;
    U16 shuffle_off_up_image_id, shuffle_on_up_image_id;
    U16 shuffle_off_down_image_id, shuffle_on_down_image_id;    

    S16 volume_inc_x, volume_inc_y;
    U16 volume_inc_up_image_id, volume_inc_down_image_id, volume_inc_disable_image_id;
    S16 volume_dec_x, volume_dec_y;
    U16 volume_dec_up_image_id, volume_dec_down_image_id, volume_dec_disable_image_id;
	S16 volume_spk_pos_x, volume_spk_pos_y;
	U16 volume_spk_out_up_img_id;  
    U16 volume_spk_out_down_img_id;  
    U16 volume_spk_mute_up_img_id; 
    U16 volume_spk_mute_down_img_id; 
    
    S16 spec_animation_x, spec_animation_y;
    S16 spec_animation_w, spec_animation_h;
    
#ifdef __MMI_TOUCH_SCREEN__
    S16 setting_x, setting_y;
    U16 setting_up_image_id, setting_down_image_id;
    audply_polygon_area_struct seek_area;
    audply_polygon_area_struct volume_inc_area;
    audply_polygon_area_struct volume_dec_area;
    audply_polygon_area_struct prev_button_area;
    audply_polygon_area_struct next_button_area;
    audply_polygon_area_struct play_button_area;
    audply_polygon_area_struct stop_button_area;
    audply_polygon_area_struct setting_area;

    audply_polygon_area_struct repeat_area;
    audply_polygon_area_struct shuffle_area;

#endif /* __MMI_TOUCH_SCREEN__ */ 
    U8 up_key_mapping, down_key_mapping, left_key_mapping, right_key_mapping;
} audply_skin_struct;

#endif //__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__


#elif defined(__MMI_AUDIO_PLAYER_SKIN_SLIM__)

typedef struct
{
    U8 bg_color_r, bg_color_g, bg_color_b;
    U16 fg_down_id;
    U16 fg_disable_id;
    U8 text_border_color_r, text_border_color_g, text_border_color_b;
    U8 text_fg_color_r, text_fg_color_g, text_fg_color_b;
    U8 text_bg_color_r, text_bg_color_g, text_bg_color_b;
    S16 file_index_x, file_index_y;
    S16 file_index_w, file_index_h;
    S16 title_x, title_y;
    S16 title_w, title_h;
    U16 bg_title_image_id;
    S16 volumebar_x, volumebar_y;
    S16 volumebar_w, volumebar_h;
    S16 volumebar_ind_len;
    U8  volumebar_direction;
    U16 bg_volume_image_id;
    U16 volumebar_ind_image_id;
    S16 progressbar_x, progressbar_y;
    S16 progressbar_w, progressbar_h;
    U16 bg_progress_image_id;
    U16 progressbar_image_id;
    U16 progressbar_fail_image_id;
    S16 prev_button_x, prev_button_y;
    U16 bg_button_id;
    U16 prev_button_image_id;
    S16 next_button_x, next_button_y;
    U16 next_button_image_id;
    S16 play_button_x, play_button_y;
    U16 play_button_image_id;
    U16 pause_button_image_id;
    S16 stop_button_x, stop_button_y;
    U16 stop_button_image_id;
#ifdef __MMI_AUDIO_PLAYER_ANIMATION__
    S16 animation_x, animation_y;
    U16 animation_image_id;
#endif /* __MMI_AUDIO_PLAYER_ANIMATION__ */ 
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    S16 spectrum_display_x, spectrum_display_y;
    S16 spectrum_display_w, spectrum_display_h;
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 

#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
    U8 lyric_fg_color_r, lyric_fg_color_g, lyric_fg_color_b;
    U8 lyric_border_color_r, lyric_border_color_g, lyric_border_color_b;
    S16 lyric_display_x, lyric_display_y;
    S16 lyric_display_w, lyric_display_h;
#endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 
#if defined( __MMI_AUDIO_SPECTRUM_DISPLAY__) && (defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)) 
    U8 spectrum_lyrics_exclusive ;
#endif
    S16 repeat_x, repeat_y;
    U16 repeat_off_image_id, repeat_all_image_id, repeat_one_image_id;
    S16 shuffle_x, shuffle_y;
    U16 shuffle_off_image_id, shuffle_on_image_id;
#ifdef __MMI_TOUCH_SCREEN__
    audply_polygon_area_struct seek_area;
    audply_polygon_area_struct prev_button_area;
    audply_polygon_area_struct next_button_area;
    audply_polygon_area_struct play_button_area;
    audply_polygon_area_struct stop_button_area;
    audply_polygon_area_struct repeat_area;
    audply_polygon_area_struct shuffle_area;
#endif /* __MMI_TOUCH_SCREEN__ */ 
    S16 time_left_x, time_left_y;
    S16 time_right_x, time_right_y;
    U16 ticks_image_id[11];
} audply_skin_struct;
//end __MMI_AUDIO_PLAYER_SKIN_SLIM__
#else

typedef struct
{
    U16 bg_image_id;
    U8 text_border_color_r, text_border_color_g, text_border_color_b;
    U8 text_fg_color_r, text_fg_color_g, text_fg_color_b;
    U8 text_bg_color_r, text_bg_color_g, text_bg_color_b;
    S16 title_x, title_y;
    S16 title_w, title_h;
    S16 time_x, time_y;
    S16 time_w, time_h;
    S16 file_index_x, file_index_y;
    S16 file_index_w, file_index_h;
    S16 playlisticon_x, playlisticon_y;
    U16 playlisticon_images_id[NO_OF_LIST];
    S16 volumebar_x, volumebar_y, volumebar_ind_len;
    U8  volumebar_direction;
    U16 volumebar_ind_image_id;
    S16 progressbar_x, progressbar_y;
    U16 progressbar_image_id;
    U16 progressbar_fail_image_id;
    S16 prev_button_x, prev_button_y;
    U16 prev_button_off_image_id, prev_button_disabled_image_id, prev_button_down_image_id;
    S16 next_button_x, next_button_y;
    U16 next_button_off_image_id, next_button_disabled_image_id, next_button_down_image_id;
    S16 play_button_x, play_button_y;
    U16 play_button_off_image_id, play_button_disabled_image_id, play_button_down_image_id;
    U16 pause_button_off_image_id, pause_button_down_image_id;
    S16 stop_button_x, stop_button_y;
    U16 stop_button_off_image_id, stop_button_disabled_image_id, stop_button_down_image_id;
#ifdef __MMI_AUDIO_PLAYER_ANIMATION__
    S16 animation_x, animation_y;
    U16 animation_image_id;
#endif /* __MMI_AUDIO_PLAYER_ANIMATION__ */ 
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    S16 spectrum_display_x, spectrum_display_y;
    S16 spectrum_display_w, spectrum_display_h;
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 

#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
    U8 lyric_fg_color_r, lyric_fg_color_g, lyric_fg_color_b;
    U8 lyric_border_color_r, lyric_border_color_g, lyric_border_color_b;
    S16 lyric_display_x, lyric_display_y;
    S16 lyric_display_w, lyric_display_h;
#endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 
#if defined( __MMI_AUDIO_SPECTRUM_DISPLAY__) && (defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__))
    U8 spectrum_lyrics_exclusive ;
#endif
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
    S16 repeat_x, repeat_y;
    U16 repeat_off_up_image_id, repeat_all_up_image_id, repeat_one_up_image_id;
#ifdef __MMI_TOUCH_SCREEN__
    U16 repeat_off_down_image_id, repeat_all_down_image_id, repeat_one_down_image_id;
#endif
    S16 shuffle_x, shuffle_y;
    U16 shuffle_off_up_image_id, shuffle_on_up_image_id;
#ifdef __MMI_TOUCH_SCREEN__
    U16 shuffle_off_down_image_id, shuffle_on_down_image_id;    
#endif
#endif /* __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__ */ 
    S16 volume_inc_x, volume_inc_y;
    U16 volume_inc_up_image_id, volume_inc_down_image_id, volume_inc_disable_image_id;
    S16 volume_dec_x, volume_dec_y;
    U16 volume_dec_up_image_id, volume_dec_down_image_id, volume_dec_disable_image_id;
#ifdef __MMI_TOUCH_SCREEN__
    S16 setting_x, setting_y;
    U16 setting_up_image_id, setting_down_image_id;
    audply_polygon_area_struct seek_area;
    audply_polygon_area_struct volume_inc_area;
    audply_polygon_area_struct volume_dec_area;
    audply_polygon_area_struct prev_button_area;
    audply_polygon_area_struct next_button_area;
    audply_polygon_area_struct play_button_area;
    audply_polygon_area_struct stop_button_area;
    audply_polygon_area_struct setting_area;
//    audply_polygon_area_struct play_list_area;
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__    
    audply_polygon_area_struct repeat_area;
    audply_polygon_area_struct shuffle_area;
#endif /* __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__ */     
#endif /* __MMI_TOUCH_SCREEN__ */ 
    U8 up_key_mapping, down_key_mapping, left_key_mapping, right_key_mapping;
} audply_skin_struct;

#endif /*__MMI_FTE_SUPPORT__*/


typedef enum
{
    AUDPLY_ACTION_COPY,
    AUDPLY_ACTION_DELETE,
    AUDPLY_ACTION_DELETE_FAIL,
    AUDPLY_ACTION_RENAME,
    AUDPLY_ACTION_MOVE,
    AUDPLY_ACTION_DELETE_ALL,
    MAX_AUDPLY_ACTION
} AUDPLY_UPDATE_LIST_ACTION_ENUM;

#ifdef __MMI_FTE_SUPPORT__
typedef enum
{
	AUDPLY_SEEK_STATE_NONE,
	AUDPLY_SEEK_STATE_FORWARD,
	AUDPLY_SEEK_STATE_REWIND,
	AUDPLY_SEEK_STATE_TOTAL
}audply_seek_state_enum;
#endif

#endif /* __MMI_AUDIO_PLAYER__ */ 

typedef enum
{
    STATE_IDLE,
    STATE_PLAY,
    STATE_PAUSED,
    NO_OF_STATE
} audply_state_enum;

typedef enum
{
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
	AUDPLY_SETTING_STORAGE,
#ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__

	AUDPLY_SETTING_LIST_AUTO_GEN,
#endif
#endif
#ifndef __MMI_SLIM_AUDIO_PLAYER__
	AUDPLY_SETTING_SKIN,
#endif
	AUDPLY_SETTING_REPEAT,
	AUDPLY_SETTING_SHUFFLE,
#if (!defined(__MMI_AUDIO_PLAYER_ON_SUBLCD__) && !(defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__)||defined(__MMI_VUI_LAUNCHER_KEY__)))
	AUDPLY_SETTING_BACKGROUND_PLAY,
#endif
#ifdef __MMI_AUDIO_TIME_STRETCH__
    AUDPLY_SETTING_TIME_STRETCH,
#endif
#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
    AUDPLY_SETTING_SOUND_EFFECT,
    AUDPLY_SETTING_SOUND_EFFECT_INDEX,
#endif
#ifdef __MMI_AUDIO_BASS_ENHANCEMENT__
    AUDPLY_SETTING_BASS_ENHANCEMENT,
    AUDPLY_SETTING_BASS_ENHANCEMENT_INDEX,
#endif
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    AUDPLY_SETTING_SPECTRUM_DISPLAY,
#endif
#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
    AUDPLY_SETTING_LYRICS_DISPLAY,
#endif
#ifdef __MMI_A2DP_SUPPORT__
    AUDPLY_SETTING_BLUETOOTH_A2DP_OUTPUT,
    AUDPLY_SETTING_BLUETOOTH_A2DP_HEADSET,
#endif /* __MMI_A2DP_SUPPORT__ */
    AUDPLY_SETTING_ITEM_COUNT
} AUDPLY_SETTING_ITEM_ENUM;

typedef enum
{
    MMI_AUDPLY_PLAYER_SETTING,
    MMI_AUDPLY_DISPLAY_SETTING,
    MMI_AUDPLY_SOUND_EFFECT_SETTING,
    MMI_AUDPLY_BT_SETTING,
    MMI_AUDPLY_SETTING_TOTAL   
}AUDPLY_SETTING_ENUM;



#endif /* AUDIO_PLAYER_DEF_H */ 

