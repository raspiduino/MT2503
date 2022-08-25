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
*  AudioPlayerSettings.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Audio player Setting module
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_AUDIO_PLAYER__)
#include "inlinecuigprot.h"
#include "menucuigprot.h"

/* settings module's include files. */
#define SETTINGS_INCLUDE
#include "SettingResDef.h"
#include "Conversions.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "CommonScreens.h"
//#include "gpioInc.h"
#if defined(__MMI_A2DP_SUPPORT__)
#include "av_bt.h"
#include "AVBTResDef.h"
#include "BTMMIA2DPScr.h"
#endif /* __MMI_A2DP_SUPPORT__ */
#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__) || defined(__MMI_AUDIO_BASS_ENHANCEMENT__)
#include "SettingDefs.h"
#include "SoundEffect.h"
#include "mmi_rp_app_soundeffect_def.h"
#endif /* #if defined(__MMI_AUDIO_EQUALIZER__) ||  defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__) */ 

#include "AudioPlayerDef.h"
#include "AudioPlayerResDef.h"
#include "AudioPlayerType.h"
#include "AudioPlayerMainScreen.h"
#include "AudioPlayerProt.h"
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_audioplayer_def.h"
#include "gui_data_types.h"
#include "kal_general_types.h"
#include "wgui_inline_edit.h"
#include "CustDataRes.h"
#include "stack_config.h"
#include "kal_trace.h"
#include "wgui_categories_util.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "mmi_frm_scenario_gprot.h"
#include "FileMgrSrvGProt.h"
#include "fs_func.h"
#include "fs_type.h"
#include "fs_errcode.h"
#include "mmi_frm_events_gprot.h"
#include "AlertScreen.h"
#include "AudioPlayerPlayList.h"

#include "gpiosrvgprot.h"

#if !(defined(__MMI_AUDIO_EQUALIZER__) ||  defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__))
S32 g_settings_current_audio_effect;
#endif

/******************************enum begin*************************************/
 
typedef enum
{
    MMI_AUDPLY_ONE_LAYER_SETTINGS,
    MMI_AUDPLY_PLAYER_SETTINGS,
    MMI_AUDPLY_DISPLAY_SETTINGS,
    MMI_AUDPLY_SOUND_EFFECT_SETTINGS
}mmi_audply_settings_style_enum;

/******************************common setting zone begin*************************************/
static const U16 onoff_str[]= {STR_GLOBAL_OFF, STR_GLOBAL_ON};

static MMI_ID_TYPE audply_setting_item_icons[] = 
{
    IMG_GLOBAL_L1,
    0,
    IMG_GLOBAL_L2,
    0,
    IMG_GLOBAL_L3,
    0,
    IMG_GLOBAL_L4,
    0,
    IMG_GLOBAL_L5,
    0
};

/*static const cui_inline_item_softkey_struct mmi_audply_common_inline_softkey = 
{
    {
        {STR_GLOBAL_OK, 0},
        {STR_GLOBAL_BACK, 0},
        {0, IMG_GLOBAL_COMMON_CSK}
    }
};*/
/******************************common setting zone end*************************************/

/******************************player setting zone begin*************************************/
typedef enum
{
    ITEM_ID_PLAYER_SETTING_BEGIN    = CUI_INLINE_ITEM_ID_BASE + 0,

    ITEM_ID_PREFER_LIST_CAPTION,
    ITEM_ID_PREFER_LIST_ITEM, 
    ITEM_ID_AUTO_GEN_CAPTION,
    ITEM_ID_AUTO_GEN_ITEM,
    ITEM_ID_REPEAT_CAPTION,
    ITEM_ID_REPEAT_ITEM,
    ITEM_ID_SHUFFLE_CAPTION,
    ITEM_ID_SHUFFLE_ITEM,
    ITEM_ID_BG_PLAY_CAPTION,
    ITEM_ID_BG_PLAY_ITEM,
    
    ITEM_ID_PLAYER_SETTING_END,
    ITEM_ID_PLAYER_SETTING_NUM = ITEM_ID_PLAYER_SETTING_END - ITEM_ID_PLAYER_SETTING_BEGIN - 1
}mmi_audply_player_setting_item_enum;

static const cui_inline_item_caption_struct mmi_audply_prefer_list_caption = {STR_ID_AUDPLY_SETTINGS_PREFER_LIST};
#ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
static const cui_inline_item_caption_struct mmi_audply_auto_gen_caption = {STR_ID_AUDPLY_SETTINGS_LIST_AUTO_GEN};
#endif
static const cui_inline_item_caption_struct mmi_audply_repeat_caption = {STR_ID_AUDPLY_SETTINGS_REPEAT};
static const cui_inline_item_caption_struct mmi_audply_shuffle_caption = {STR_ID_AUDPLY_SETTINGS_SHUFFLE};
static const cui_inline_item_caption_struct mmi_audply_bg_play_caption = {STR_ID_AUDPLY_SETTINGS_BACKGROUND_PLAY};

#if 0//def __MMI_AUDPLY_WALK_PLAY__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  //__MMI_AUDPLY_WALK_PLAY__
static const U16 repeat_str[] = {STR_GLOBAL_OFF, STR_ID_AUDPLY_SETTINGS_ONE, STR_ID_AUDPLY_SETTINGS_ALL};

/*
static const cui_inline_item_select_struct mmi_audply_prefer_list_item_struct= 
{
    2, 0, (U16 *)&onoff_str[0]
};
*/
#ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
static const cui_inline_item_select_struct mmi_audply_auto_gen_item_struct= 
{
    2, 0, (U16 *)&onoff_str[0]
};
#endif
static const cui_inline_item_select_struct mmi_audply_repeat_item_struct= 
{
    3, 0, (U16 *)&repeat_str[0]
};

static const cui_inline_item_select_struct mmi_audply_shuffle_item_struct= 
{
    2, 0, (U16 *)&onoff_str[0]
};
static const cui_inline_item_select_struct mmi_audply_bg_play_item_struct= 
{
    2, 0, (U16 *)&onoff_str[0]
};

static const cui_inline_set_item_struct mmi_audply_player_setting_inline_item[] = 
{
    {ITEM_ID_PREFER_LIST_CAPTION,   CUI_INLINE_ITEM_TYPE_CAPTION,   0,  (void*)&mmi_audply_prefer_list_caption},
    {ITEM_ID_PREFER_LIST_ITEM,      CUI_INLINE_ITEM_TYPE_SELECT,    0,  NULL},
    #ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
    {ITEM_ID_AUTO_GEN_CAPTION,      CUI_INLINE_ITEM_TYPE_CAPTION,   0,  (void*)&mmi_audply_auto_gen_caption},
    {ITEM_ID_AUTO_GEN_ITEM,         CUI_INLINE_ITEM_TYPE_SELECT,    0,  (void*)&mmi_audply_auto_gen_item_struct},
    #endif
    {ITEM_ID_REPEAT_CAPTION,        CUI_INLINE_ITEM_TYPE_CAPTION,   0,  (void*)&mmi_audply_repeat_caption},
    {ITEM_ID_REPEAT_ITEM,           CUI_INLINE_ITEM_TYPE_SELECT,    0,  (void*)&mmi_audply_repeat_item_struct},
    {ITEM_ID_SHUFFLE_CAPTION,       CUI_INLINE_ITEM_TYPE_CAPTION,   0,  (void*)&mmi_audply_shuffle_caption},
    {ITEM_ID_SHUFFLE_ITEM,          CUI_INLINE_ITEM_TYPE_SELECT,    0,  (void*)&mmi_audply_shuffle_item_struct},
    {ITEM_ID_BG_PLAY_CAPTION,       CUI_INLINE_ITEM_TYPE_CAPTION,   0,  (void*)&mmi_audply_bg_play_caption},
    {ITEM_ID_BG_PLAY_ITEM,          CUI_INLINE_ITEM_TYPE_SELECT,    0,  (void*)&mmi_audply_bg_play_item_struct},
};

static const cui_inline_struct mmi_audply_player_setting_inline_screen = 
{
    ITEM_ID_PLAYER_SETTING_NUM,
    STR_ID_AUDPLY_PLAYER_SETTINGS,
    0,
    CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE, 
    NULL, 
    mmi_audply_player_setting_inline_item 
};

/******************************player setting zone end*************************************/

/******************************display setting zone begin*************************************/
typedef enum
{
    ITEM_ID_DISPLAY_SETTING_BEGIN    = CUI_INLINE_ITEM_ID_BASE + 0,

    ITEM_ID_SKIN_CAPTION,
    ITEM_ID_SKIN_ITEM, 
    ITEM_ID_SPECTRUM_CAPTION,
    ITEM_ID_SPECTRUM_ITEM,
    ITEM_ID_LYRICS_CAPTION,
    ITEM_ID_LYRICS_ITEM,
    
    ITEM_ID_DISPLAY_SETTING_END,
    ITEM_ID_DISPLAY_SETTING_NUM = ITEM_ID_DISPLAY_SETTING_END - ITEM_ID_DISPLAY_SETTING_BEGIN - 1
}mmi_audply_display_setting_item_enum;

static const cui_inline_item_caption_struct mmi_audply_skin_caption = {STR_ID_AUDPLY_SETTINGS_SKIN};
static const cui_inline_item_caption_struct mmi_audply_spectrum_caption = {STR_ID_AUDPLY_SETTINGS_SPECTRUM_DISPLAY_STYLE};
static const cui_inline_item_caption_struct mmi_audply_lyrics_caption = {STR_ID_AUDPLY_SETTINGS_LYRICS_DISPLAY};

static const U16 skin_str[] = 
{
#ifndef __MMI_AUDIO_PLAYER_SKIN_SLIM__
     STR_ID_AUDPLY_SETTINGS_SKIN1, 
     STR_ID_AUDPLY_SETTINGS_SKIN2, 
     STR_ID_AUDPLY_SETTINGS_SKIN3
#else
     0,
     0,
     0
#endif
};

static const U16 spectrum_str[] = 
{
    STR_GLOBAL_OFF, 
     STR_ID_AUDPLY_SETTINGS_SPECTRUM_DISPLAY_STYLE_1, 
    STR_ID_AUDPLY_SETTINGS_SPECTRUM_DISPLAY_STYLE_2
};

static const cui_inline_item_select_struct mmi_audply_skin_item_struct= 
{
    3, 0, (U16 *)&skin_str[0]
};

static const cui_inline_item_select_struct mmi_audply_spectrum_item_struct= 
{
    3, 0, (U16 *)&spectrum_str[0]
};

static const cui_inline_item_select_struct mmi_audply_lyrics_item_struct= 
{
    2, 0, (U16 *)&onoff_str[0]
};
#ifndef __MMI_AUDPLY_SINGLE_LAYER_SETTING__
static const cui_inline_set_item_struct mmi_audply_display_setting_inline_item[] = 
{
    {ITEM_ID_SKIN_CAPTION,      CUI_INLINE_ITEM_TYPE_CAPTION,   0,  (void*)&mmi_audply_skin_caption},
    {ITEM_ID_SKIN_ITEM,         CUI_INLINE_ITEM_TYPE_SELECT,    0,  (void*)&mmi_audply_skin_item_struct},
    {ITEM_ID_SPECTRUM_CAPTION,  CUI_INLINE_ITEM_TYPE_CAPTION,   0,  (void*)&mmi_audply_spectrum_caption},
    {ITEM_ID_SPECTRUM_ITEM,     CUI_INLINE_ITEM_TYPE_SELECT,    0,  (void*)&mmi_audply_spectrum_item_struct},
    {ITEM_ID_LYRICS_CAPTION,    CUI_INLINE_ITEM_TYPE_CAPTION,   0,  (void*)&mmi_audply_lyrics_caption},
    {ITEM_ID_LYRICS_ITEM,       CUI_INLINE_ITEM_TYPE_SELECT,    0,  (void*)&mmi_audply_lyrics_item_struct},
};

static const cui_inline_struct mmi_audply_display_setting_inline_screen = 
{
    ITEM_ID_DISPLAY_SETTING_NUM,
#if !defined(__MMI_AUDIO_PLAYER_SKIN_SLIM__) || defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_SPECTRUM_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
    STR_ID_AUDPLY_DISPLAY_SETTINGS,
#else
    0,
#endif
    0,
    CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE, 
    NULL, 
    mmi_audply_display_setting_inline_item 
};
#endif

/******************************display setting zone end*************************************/

/******************************sound effect setting zone begin*************************************/
typedef enum
{
    ITEM_ID_SOUND_EFFECT_SETTING_BEGIN    = CUI_INLINE_ITEM_ID_BASE + 0,

    ITEM_ID_AUDIO_EFFECT_CAPTION,
    ITEM_ID_AUDIO_EFFECT_ITEM_1,
    ITEM_ID_AUDIO_EFFECT_ITEM_2, 
    ITEM_ID_BASS_CAPTION,
    ITEM_ID_BASS_ITEM,
    ITEM_ID_PLAY_SPEED_CAPTION,
    ITEM_ID_PLAY_SPEED_ITEM,
    
    ITEM_ID_SOUND_EFFECT_SETTING_END,
    ITEM_ID_SOUND_EFFECT_SETTING_NUM = ITEM_ID_SOUND_EFFECT_SETTING_END - ITEM_ID_SOUND_EFFECT_SETTING_BEGIN - 1
}mmi_audply_sound_effect_setting_item_enum;

static const cui_inline_item_caption_struct mmi_audply_audio_effect_caption = {
#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
    STR_ID_SETTING_AUDIO_EFFECT
#else
    0
#endif
};
static const cui_inline_item_caption_struct mmi_audply_bass_caption = {
#ifdef __MMI_AUDIO_BASS_ENHANCEMENT__
    STR_ID_SETTING_BASS_ENHANCEMENT
#else
    0
#endif	
};

static const cui_inline_item_caption_struct mmi_audply_play_speed_caption = {
#ifdef __MMI_AUDIO_TIME_STRETCH__
  STR_ID_AUDPLY_SPEED
#else
  0
#endif  
};

static const U16 audio_effect_item_str[] = 
{
    STR_GLOBAL_OFF 
#ifdef __MMI_AUDIO_EQUALIZER__		
    ,STR_ID_SETTING_AUDIO_EQUALIZER 
#endif

#ifdef __MMI_AUDIO_REVERB_EFFECT__
    ,STR_ID_SETTING_AUDIO_REVERB_EFFECT
#endif

#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    ,STR_ID_SETTING_AUDIO_SURROUND_EFFECT
#endif    
};
#if !defined(__MMI_EDITABLE_AUDIO_EQUALIZER__) && defined (__MMI_AUDIO_EQUALIZER__)
static const U16 audio_equalizer_list_str[] = 
{
    STR_ID_SETTING_AUDIO_EQUALIZER_SET_1,
    STR_ID_SETTING_AUDIO_EQUALIZER_SET_2,
    STR_ID_SETTING_AUDIO_EQUALIZER_SET_3,
    STR_ID_SETTING_AUDIO_EQUALIZER_SET_4,
    STR_ID_SETTING_AUDIO_EQUALIZER_SET_5,
    STR_ID_SETTING_AUDIO_EQUALIZER_SET_6,
    STR_ID_SETTING_AUDIO_EQUALIZER_SET_7,
    STR_ID_SETTING_AUDIO_EQUALIZER_SET_8
};
#endif
#ifdef __MMI_AUDIO_REVERB_EFFECT__
static const U16 audio_reverb_list_str[] = 
{
    STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET1,
    STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET2,
    STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET3,
    STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET4,
    STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET5,
    STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET6
};
#endif
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
static const U16 audio_surround_list_str[] = 
{
    STR_ID_SETTING_AUDIO_SURROUND_MODE1,
    STR_ID_SETTING_AUDIO_SURROUND_MODE2
};
#endif
static const U16 play_speed_str[] = 
{
    STR_GLOBAL_NORMAL, 
    STR_GLOBAL_FAST, 
#ifdef __MMI_AUDIO_TIME_STRETCH__
    STR_ID_AUDPLY_SPEED_FAST2,
    STR_ID_AUDPLY_SPEED_SLOW2,
#else
    0,
    0,
#endif
    STR_GLOBAL_SLOW
};

static const cui_inline_item_select_struct mmi_audply_audio_effect_item_struct= 
{
#ifdef __MMI_AUDIO_EQUALIZER__
    1 +
#endif
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    1 +
#endif

#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    1 +
#endif    
    1, 0, (U16 *)&audio_effect_item_str[0]
};

static const cui_inline_item_select_struct mmi_audply_bass_item_struct= 
{
    2, 0, (U16 *)&onoff_str[0]
};

static const cui_inline_item_select_struct mmi_audply_play_speed_item_struct= 
{
    5, 0, (U16 *)&play_speed_str[0]
};

#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_TIME_STRETCH__) || \
    (defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__) || defined(__MMI_AUDIO_BASS_ENHANCEMENT__))
static const cui_inline_set_item_struct mmi_audply_sound_effect_inline_item[] = 
{
    {ITEM_ID_AUDIO_EFFECT_CAPTION,  CUI_INLINE_ITEM_TYPE_CAPTION,   0,  (void*)&mmi_audply_audio_effect_caption},
    {ITEM_ID_AUDIO_EFFECT_ITEM_1,   CUI_INLINE_ITEM_TYPE_SELECT,    0,  (void*)&mmi_audply_audio_effect_item_struct},
    {ITEM_ID_AUDIO_EFFECT_ITEM_2,   CUI_INLINE_ITEM_TYPE_SELECT,    0,  NULL},
    {ITEM_ID_BASS_CAPTION,          CUI_INLINE_ITEM_TYPE_CAPTION,   0,  (void*)&mmi_audply_bass_caption},
    {ITEM_ID_BASS_ITEM,             CUI_INLINE_ITEM_TYPE_SELECT,    0,  (void*)&mmi_audply_bass_item_struct},
    {ITEM_ID_PLAY_SPEED_CAPTION,    CUI_INLINE_ITEM_TYPE_CAPTION,   0,  (void*)&mmi_audply_play_speed_caption},
    {ITEM_ID_PLAY_SPEED_ITEM,       CUI_INLINE_ITEM_TYPE_SELECT,    0,  (void*)&mmi_audply_play_speed_item_struct},
};

static const cui_inline_struct mmi_audply_sound_effect_inline_screen = 
{
    ITEM_ID_SOUND_EFFECT_SETTING_NUM,
#if (defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_TIME_STRETCH__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__) || defined(__MMI_AUDIO_BASS_ENHANCEMENT__))
    STR_ID_AUDPLY_SOUND_EFFECT_SETTINGS,
#else
    0,
#endif
    0,
    CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE, 
    NULL, 
    mmi_audply_sound_effect_inline_item 
};
#endif
/******************************sound effect setting zone end*************************************/

/*sunxd*/
/******************************one layer setting zone begin*************************************/
typedef enum
{
    ITEM_SETTING_BEGIN    = CUI_INLINE_ITEM_ID_BASE + 0,
#if !defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__)
    ITEM_PREFER_LIST_CAPTION,
    ITEM_PREFER_LIST_ITEM, 
#ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
    ITEM_AUTO_GEN_CAPTION,
    ITEM_AUTO_GEN_ITEM,
#endif
    ITEM_SKIN_CAPTION,
    ITEM_SKIN_ITEM, 

    ITEM_REPEAT_CAPTION,
    ITEM_REPEAT_ITEM,
    ITEM_SHUFFLE_CAPTION,
    ITEM_SHUFFLE_ITEM,
#endif  //!defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__)
    ITEM_BG_PLAY_CAPTION,
    ITEM_BG_PLAY_ITEM,

    ITEM_BT_SETTING_ITEM,
    
    ITEM_AUDIO_EFFECT_CAPTION,
    ITEM_AUDIO_EFFECT_ITEM_1,
    ITEM_AUDIO_EFFECT_ITEM_2, 
    ITEM_BASS_CAPTION,
    ITEM_BASS_ITEM,
    ITEM_PLAY_SPEED_CAPTION,
    ITEM_PLAY_SPEED_ITEM,

    ITEM_SPECTRUM_CAPTION,
    ITEM_SPECTRUM_ITEM,
    ITEM_LYRICS_CAPTION,
    ITEM_LYRICS_ITEM,
   
    #if 0//def __MMI_AUDPLY_WALK_PLAY__
/* under construction !*/
/* under construction !*/
    #endif  //__MMI_AUDPLY_WALK_PLAY__
    ITEM_SETTING_END,
    ITEM_SETTING_NUM = ITEM_SETTING_END - ITEM_SETTING_BEGIN - 1
}mmi_audply_setting_item_enum;

static const cui_inline_item_display_only_struct bt_setting_str = 
{
    STR_ID_AUDPLY_SETTINGS_BLUETOOTH
};

static const cui_inline_set_item_struct mmi_audply_setting_inline_item[] = 
{
#if 0//def __MMI_AUDPLY_WALK_PLAY__
/* under construction !*/
/* under construction !*/
#endif  //__MMI_AUDPLY_WALK_PLAY__
#if !defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__)
    {ITEM_PREFER_LIST_CAPTION,  CUI_INLINE_ITEM_TYPE_CAPTION,   0,  (void*)&mmi_audply_prefer_list_caption},
    {ITEM_PREFER_LIST_ITEM,     CUI_INLINE_ITEM_TYPE_SELECT,    0,  NULL},
#ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
    {ITEM_AUTO_GEN_CAPTION,     CUI_INLINE_ITEM_TYPE_CAPTION,   0,  (void*)&mmi_audply_auto_gen_caption},
    {ITEM_AUTO_GEN_ITEM,        CUI_INLINE_ITEM_TYPE_SELECT,    0,  (void*)&mmi_audply_auto_gen_item_struct},
#endif
    {ITEM_SKIN_CAPTION,         CUI_INLINE_ITEM_TYPE_CAPTION,   0,  (void*)&mmi_audply_skin_caption},
    {ITEM_SKIN_ITEM,            CUI_INLINE_ITEM_TYPE_SELECT,    0,  (void*)&mmi_audply_skin_item_struct},

    {ITEM_REPEAT_CAPTION,       CUI_INLINE_ITEM_TYPE_CAPTION,   0,  (void*)&mmi_audply_repeat_caption},
    {ITEM_REPEAT_ITEM,          CUI_INLINE_ITEM_TYPE_SELECT,    0,  (void*)&mmi_audply_repeat_item_struct},
    {ITEM_SHUFFLE_CAPTION,      CUI_INLINE_ITEM_TYPE_CAPTION,   0,  (void*)&mmi_audply_shuffle_caption},
    {ITEM_SHUFFLE_ITEM,         CUI_INLINE_ITEM_TYPE_SELECT,    0,  (void*)&mmi_audply_shuffle_item_struct},
#endif  //!defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__)
    {ITEM_BG_PLAY_CAPTION,      CUI_INLINE_ITEM_TYPE_CAPTION,   0,  (void*)&mmi_audply_bg_play_caption},
    {ITEM_BG_PLAY_ITEM,         CUI_INLINE_ITEM_TYPE_SELECT,    0,  (void*)&mmi_audply_bg_play_item_struct},

    {ITEM_BT_SETTING_ITEM,      CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,    0,  (void*)&bt_setting_str},

    {ITEM_AUDIO_EFFECT_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION,   0,  (void*)&mmi_audply_audio_effect_caption},
    {ITEM_AUDIO_EFFECT_ITEM_1,  CUI_INLINE_ITEM_TYPE_SELECT,    0,  (void*)&mmi_audply_audio_effect_item_struct},
    {ITEM_AUDIO_EFFECT_ITEM_2,  CUI_INLINE_ITEM_TYPE_SELECT,    0,  (void*)&mmi_audply_audio_effect_item_struct},
    {ITEM_BASS_CAPTION,         CUI_INLINE_ITEM_TYPE_CAPTION,   0,  (void*)&mmi_audply_bass_caption},
    {ITEM_BASS_ITEM,            CUI_INLINE_ITEM_TYPE_SELECT,    0,  (void*)&mmi_audply_bass_item_struct},
    {ITEM_PLAY_SPEED_CAPTION,   CUI_INLINE_ITEM_TYPE_CAPTION,   0,  (void*)&mmi_audply_play_speed_caption},
    {ITEM_PLAY_SPEED_ITEM,      CUI_INLINE_ITEM_TYPE_SELECT,    0,  (void*)&mmi_audply_play_speed_item_struct},

    {ITEM_SPECTRUM_CAPTION,  CUI_INLINE_ITEM_TYPE_CAPTION,   0,  (void*)&mmi_audply_spectrum_caption},
    {ITEM_SPECTRUM_ITEM,     CUI_INLINE_ITEM_TYPE_SELECT,    0,  (void*)&mmi_audply_spectrum_item_struct},
    {ITEM_LYRICS_CAPTION,    CUI_INLINE_ITEM_TYPE_CAPTION,   0,  (void*)&mmi_audply_lyrics_caption},
    {ITEM_LYRICS_ITEM,       CUI_INLINE_ITEM_TYPE_SELECT,    0,  (void*)&mmi_audply_lyrics_item_struct},

};

static const cui_inline_struct mmi_audply_setting_inline_screen = 
{
    ITEM_SETTING_NUM,
    STR_ID_AUDPLY_PLAYER_SETTINGS,
    0,
    CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE, 
    NULL, 
    mmi_audply_setting_inline_item 
};
/******************************one layer setting zone end*************************************/


static mmi_ret mmi_audply_settings_group_proc(mmi_event_struct* evt);
#if defined(__MMI_AUDIO_EQUALIZER__) ||  defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)    
static void mmi_audply_set_audio_effect_item(mmi_id inline_gid);
static void mmi_audply_set_one_layer_audio_effect_item(mmi_id inline_id);
#endif
static U16 g_audply_current_setting;
static U16 g_audply_current_item;

extern MMI_BOOL g_audply_A2DP_spectrum_need_blocked;

/* settings */
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
static S32 selected_list_auto_gen;
static S32 selected_preferred_list;
//static UI_string_type g_mmi_audply_settings_list_auto_gen[2];
U8 g_flag_memory_card_not_present = 0;
#endif

#ifndef __MMI_AUDIO_PLAYER_SKIN_SLIM__
static S32 selected_skin;
#endif

static S32 selected_repeat_mode;        /* 0: off, 1: repeat one, 2: repeat all */
static S32 selected_random_mode;        /* 0: off, 1: on */

#if (!defined(__MMI_AUDIO_PLAYER_ON_SUBLCD__) && !(defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__) ||defined(__MMI_VUI_LAUNCHER_KEY__)))
static S32 selected_background_play;    /* 0: off, 1: on */
#endif

#ifdef __MMI_AUDIO_TIME_STRETCH__
static S32 selected_speed_index;
static UI_string_type g_mmi_audply_settings_speed[MDI_AUDIO_MAX_SPEED_NUM];
#endif

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
static S32 selected_spectrum_style;
#endif 

#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
static S32 selected_lyrics_style;
#endif

#if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__)
MMI_BOOL g_audply_spectrum_blocked = MMI_FALSE;
#endif

/*used as staic val for bt power on callback*/
MMI_BOOL settings_done_back_to_main = MMI_FALSE;

static U16 g_mmi_audply_two_layer_settings_highlighted_item = 0;

extern wgui_inline_item wgui_inline_items[];        /* wgui_inline_edit.c */
extern void (*RedrawCategoryFunction) (void);   /* defined in wgui_categories.c */

#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
extern MMI_BOOL need_refresh_list;
extern MMI_BOOL need_reload_list;
#endif  /* __MMI_AUDIO_PLAYER_SINGLE_LIST__ */

extern audply_struct g_audply;
extern audply_skin_struct g_audply_skins[NO_OF_SKIN];   /* defined in resource_audply_skins.c */

/* settings module's static function prototypes. */
#define SETTINGS_PROTOTYPE

#if defined(__MMI_AUDIO_EQUALIZER__) ||/* defined(__MMI_AUDIO_TIME_STRETCH__) || */defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
static void mmi_audply_audio_effect_inlineitem_highlight_hdlr_1(S32 index);
static void mmi_audply_audio_effect_inlineitem_highlight_hdlr_2(S32 index);
#endif
#ifndef __MMI_AUDPLY_SINGLE_LAYER_SETTING__
#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_TIME_STRETCH__) || \
    (defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__) || defined(__MMI_AUDIO_BASS_ENHANCEMENT__))
static void mmi_audply_entry_sound_effect_settings(void);
#endif  /* defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_TIME_STRETCH__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)*/
static void mmi_audply_sound_effect_settings_confirm_done(void);
static void mmi_audply_sound_effect_settings_done(mmi_id inline_gid);
#endif
#if defined(__MMI_AUDIO_TIME_STRETCH__)
static U16 mmi_audply_speed_get_index(U16 speed);
static U16 mmi_audply_speed_get_speed(U16 index);
static MMI_BOOL mmi_audply_apply_change_in_setting(U16 index);
#endif /* __MMI_AUDIO_TIME_STRETCH__ */

//#if !defined(__MMI_AUDIO_PLAYER_SKIN_SLIM__) || defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_SPECTRUM_DISPLAY__)   
#ifndef __MMI_AUDPLY_SINGLE_LAYER_SETTING__
static void mmi_audply_entry_display_settings(void);
static void mmi_audply_display_settings_done(mmi_id inline_gid);

//#endif

static void mmi_audply_entry_player_settings(void);

static void mmi_audply_player_settings_done(mmi_id inline_gid);
#endif
static void mmi_audply_settings_inline_set_storage(MMI_ID inline_id);
static void mmi_audply_settings_LSK(mmi_id inline_gid);
#ifndef __MMI_AUDPLY_SINGLE_LAYER_SETTING__
static void mmi_audply_two_layer_settings_LSK(void);
#endif

static mmi_ret mmi_audply_settings_cui_hdlr_menu(mmi_event_struct *evt);


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_settings_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_focus_change_hdlr(mmi_event_struct* evt)
{
#if defined(__MMI_AUDIO_EQUALIZER__) ||  defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__) || defined(__MMI_AUDPLY_WALK_PLAY__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_event_inline_notify_struct *inline_evt = (cui_event_inline_notify_struct *)evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply_current_setting == MMI_AUDPLY_SOUND_EFFECT_SETTINGS &&
        inline_evt->item_id == ITEM_ID_AUDIO_EFFECT_ITEM_1 &&
        g_settings_current_audio_effect != inline_evt->param)
    {
        mmi_audply_audio_effect_inlineitem_highlight_hdlr_1(inline_evt->param);
        mmi_audply_set_audio_effect_item(inline_evt->sender_id);
    }
    else if(g_audply_current_setting == MMI_AUDPLY_SOUND_EFFECT_SETTINGS &&
            inline_evt->item_id == ITEM_ID_AUDIO_EFFECT_ITEM_2)
    {
        mmi_audply_audio_effect_inlineitem_highlight_hdlr_2(inline_evt->param);
    }
    else if(g_audply_current_setting == MMI_AUDPLY_ONE_LAYER_SETTINGS &&
            inline_evt->item_id == ITEM_AUDIO_EFFECT_ITEM_1 &&
        g_settings_current_audio_effect != inline_evt->param)
    {
        mmi_audply_audio_effect_inlineitem_highlight_hdlr_1(inline_evt->param);
        mmi_audply_set_one_layer_audio_effect_item(inline_evt->sender_id);
    }
    else if (g_audply_current_setting == MMI_AUDPLY_ONE_LAYER_SETTINGS &&
            inline_evt->item_id == ITEM_AUDIO_EFFECT_ITEM_2)
    {
        mmi_audply_audio_effect_inlineitem_highlight_hdlr_2(inline_evt->param);
    }
    #if 0//def __MMI_AUDPLY_WALK_PLAY__
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
    #endif  //__MMI_AUDPLY_WALK_PLAY__
#endif

}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_settings_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_audply_settings_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_event_inline_notify_struct *inline_evt = (cui_event_inline_notify_struct *)evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        /*************************Menu CUI event***************************/
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_LIST_EXIT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            mmi_audply_settings_cui_hdlr_menu(evt);
            break;
        }

        /*************************Inline CUI event***************************/
        case EVT_ID_CUI_INLINE_NOTIFY:
        {
            if (inline_evt->event_type == CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED)
            {
                mmi_audply_focus_change_hdlr(evt);
            }
            else if (inline_evt->event_type == CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM && 
                     g_audply_current_setting == MMI_AUDPLY_ONE_LAYER_SETTINGS)
            {
                g_audply_current_item = inline_evt->param;
            }
               break;
            }

        case EVT_ID_CUI_INLINE_SET_KEY:
            {
                /*cui_event_inline_set_key_struct *set_key_evt = (cui_event_inline_set_key_struct*)evt;
                
                #if defined(__MMI_A2DP_SUPPORT__) && !defined(__MMI_A2DP_HIDE_BT_SETTINGS__)
                if (set_key_evt->item_id == ITEM_BT_SETTING_ITEM)
                {
                    ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);
                    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
                    SetLeftSoftkeyFunction(mmi_a2dp_entry_bluetooth_settings, KEY_EVENT_UP);
                    SetCenterSoftkeyFunction(mmi_a2dp_entry_bluetooth_settings, KEY_EVENT_UP);
                }
                else
                #endif
                {
                    cui_inline_set_softkey_text(
                        inline_evt->sender_id, 
                        set_key_evt->item_id, 
                        MMI_LEFT_SOFTKEY, 
                        STR_GLOBAL_SAVE);
                }*/
                break;
            }



        case EVT_ID_CUI_INLINE_CSK_PRESS:
        case EVT_ID_CUI_INLINE_SUBMIT:
        {
            switch(g_audply_current_setting)
            {
           #ifndef __MMI_AUDPLY_SINGLE_LAYER_SETTING__
                case MMI_AUDPLY_PLAYER_SETTINGS:
                {
                    mmi_audply_player_settings_done(inline_evt->sender_id);
                    break;
                }
                case MMI_AUDPLY_DISPLAY_SETTINGS:
                {
                    mmi_audply_display_settings_done(inline_evt->sender_id);
                    break;
                }
                case MMI_AUDPLY_SOUND_EFFECT_SETTINGS:
                {
                    mmi_audply_sound_effect_settings_done(inline_evt->sender_id);
                    break;
                }
           #endif
                case MMI_AUDPLY_ONE_LAYER_SETTINGS:
                {
                    if (g_audply_current_item != ITEM_BT_SETTING_ITEM)
                    {
                        mmi_audply_settings_LSK(inline_evt->sender_id);
                    }
                    else
                    {
                    #if defined(__MMI_A2DP_SUPPORT__) && !defined(__MMI_A2DP_HIDE_BT_SETTINGS__)
                        mmi_a2dp_entry_bluetooth_settings();
                    #endif
                    }
                    break;
                }
            }
            if (!g_flag_memory_card_not_present)
            {
                cui_inline_close(inline_evt->sender_id);
            }
            g_flag_memory_card_not_present = 0;
            break;
        }
        
        case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_inline_close(inline_evt->sender_id);
            break;
        }
        default:
        {
            break;
        }
            }
    
    return MMI_RET_OK;
        }


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_cui_hdlr_menu
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_audply_settings_cui_hdlr_menu(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            if (menu_evt->parent_menu_id == MENU_ID_AUDPLY_SETTINGS_LIST)
        {
                i = 0;
                cui_menu_enable_tap_to_highlight(menu_evt->sender_id);
                cui_menu_set_item_image(menu_evt->sender_id, MENU_ID_AUDPLY_PLAYER_SETTING, IMG_GLOBAL_L1);

            #if !defined(__MMI_AUDIO_PLAYER_SKIN_SLIM__) || defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_SPECTRUM_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)  
                i++;
                cui_menu_set_item_image(menu_evt->sender_id, MENU_ID_AUDPLY_DISPLAY_SETTING, IMG_GLOBAL_L1 + i);
            #endif

            #if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_TIME_STRETCH__) || \
                (defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__) || defined(__MMI_AUDIO_BASS_ENHANCEMENT__))
                i++;
                cui_menu_set_item_image(menu_evt->sender_id, MENU_ID_AUDPLY_SOUND_EFFECT_SETTING, IMG_GLOBAL_L1 + i);
            #endif

            #if defined(__MMI_A2DP_SUPPORT__) && !defined(__MMI_A2DP_HIDE_BT_SETTINGS__)
                if (!mmi_bt_is_to_display_bt_menu())
               {
                  cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_AUDPLY_BT_SETTING, MMI_TRUE);
               }
	       else
	       { 
	          cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_AUDPLY_BT_SETTING, MMI_FALSE);
                i++;
                cui_menu_set_item_image(menu_evt->sender_id, MENU_ID_AUDPLY_BT_SETTING, IMG_GLOBAL_L1 + i);

	       }
			    
            #endif /*__MMI_A2DP_SUPPORT__*/
                cui_menu_set_currlist_left_softkey(menu_evt->sender_id, (UI_string_type)GetString(STR_GLOBAL_OK));
                cui_menu_set_currlist_right_softkey(menu_evt->sender_id, (UI_string_type)GetString(STR_GLOBAL_BACK));
            }
           
            break;
        }

        case EVT_ID_CUI_MENU_ITEM_HILITE:
            {
            g_mmi_audply_two_layer_settings_highlighted_item = menu_evt->highlighted_menu_id;
            break;
        }

        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
                {
#ifndef __MMI_AUDPLY_SINGLE_LAYER_SETTING__
            mmi_audply_two_layer_settings_LSK();
#endif
            break;
        }
                   
        case EVT_ID_CUI_MENU_LIST_EXIT:
        {
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
    

#if defined(__MMI_A2DP_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_get_string_for_a2dp
 * DESCRIPTION
 *  get popup string for A2DP.
 * PARAMETERS
 *  MMI_BOOL       [IN]
 *  MMI_BOOL       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_audply_get_string_for_a2dp(MMI_BOOL bt_a2dp_output)
{
    /* there is no popup or some screen on top of bluetooth settings screen */
    #ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
     if (g_audply_A2DP_spectrum_need_blocked)
    {
          if (bt_a2dp_output && g_audply.spectrum_style != 0 && g_audply.in_audio_player)
          {
            return STR_ID_AUDPLY_A2DP_BLOCK_SPECTRUM;
          }
    }
    
    #endif

    return 0;
    
 }
#endif /*__MMI_A2DP_SUPPORT__*/


#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_audio_effect_inlineitem_highlight_hdlr_2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_audio_effect_inlineitem_highlight_hdlr_2(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_settings_current_audio_effect)
    {
    #ifdef __MMI_AUDIO_EQUALIZER__
        case SETTINGS_SOUND_EFFECTS_EQ :
            current_audio_equalizer_index = index; 
            break;
    #endif
    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        case SETTINGS_SOUND_EFFECTS_REVERB :
            current_audio_reverb_index = index;
            break;
    #endif
    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        case SETTINGS_SOUND_EFFECTS_SURROUND :
            current_audio_surround_index = index;
            break;
    #endif
        default :
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_audio_effect_inlineitem_highlight_hdlr_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_audio_effect_inlineitem_highlight_hdlr_1(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_settings_current_audio_effect_prev == index)
    {
        return;
    }
    switch (index)
    {
        case SETTINGS_SOUND_EFFECTS_NONE:
            g_settings_current_audio_effect = index;            
            break;
            
    #ifdef __MMI_AUDIO_EQUALIZER__
        case SETTINGS_SOUND_EFFECTS_EQ:
            g_settings_current_effect_index = current_audio_equalizer_index;
            g_settings_current_audio_effect = index;
            break;
    #endif

    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        case SETTINGS_SOUND_EFFECTS_REVERB:
            g_settings_current_effect_index = current_audio_reverb_index;
            g_settings_current_audio_effect = index;
            break;
    #endif

    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        case SETTINGS_SOUND_EFFECTS_SURROUND:
            g_settings_current_effect_index = current_audio_surround_index;
            g_settings_current_audio_effect = index;
            break;
    #endif
        default:
            break;
    }

}
#endif
#ifndef __MMI_AUDPLY_SINGLE_LAYER_SETTING__
#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_TIME_STRETCH__) || \
    (defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__) || defined(__MMI_AUDIO_BASS_ENHANCEMENT__))
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_entry_sound_effect_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_entry_sound_effect_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id inline_id;
    U16 i = 0, j = 0;
    U16 count = 0;
    MMI_ID_TYPE item_icons[7] = {0}; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inline_id = cui_inline_create(GRP_ID_AUDPLY_SETTINGS, &mmi_audply_sound_effect_inline_screen);

    if (inline_id == GRP_ID_INVALID)
    {
        return;
    }
    g_audply_current_setting = MMI_AUDPLY_SOUND_EFFECT_SETTINGS;

#if defined(__MMI_AUDIO_EQUALIZER__) ||  defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
        g_settings_current_audio_effect = g_settings_selected_audio_effect;
    #ifdef __MMI_AUDIO_EQUALIZER__
        current_audio_equalizer_index = g_settings_audio_equalizer.index;
    #endif
    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        current_audio_reverb_index = g_mmi_aud_3d_cntx.reverb_index;
    #endif
    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        current_audio_surround_index = g_mmi_aud_3d_cntx.surround_index;
    #endif
    g_settings_current_audio_effect_prev = g_settings_current_audio_effect;

    g_settings_audio_effects_inline1[count++] = (UI_string_type)GetString((U16)(STR_GLOBAL_OFF));
#ifdef __MMI_AUDIO_EQUALIZER__
    g_settings_audio_effects_inline1[count++] = (UI_string_type)GetString((U16)(STR_ID_SETTING_AUDIO_EQUALIZER));
#endif
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    g_settings_audio_effects_inline1[count++] = (UI_string_type)GetString((U16)(STR_ID_SETTING_AUDIO_REVERB_EFFECT));
#endif
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    g_settings_audio_effects_inline1[count++] = (UI_string_type)GetString((U16)(STR_ID_SETTING_AUDIO_SURROUND_EFFECT));        
#endif

    cui_inline_set_item_select(inline_id, 
                   ITEM_ID_AUDIO_EFFECT_ITEM_1, 
                   count, 
                   (PU8 *)g_settings_audio_effects_inline1, 
                   g_settings_current_audio_effect);
    mmi_audply_set_audio_effect_item(inline_id);
    item_icons[i++] = IMG_GLOBAL_L1;
    item_icons[i++] = 0;
    item_icons[i++] = 0;
    j++;
#else
    cui_inline_delete_item(inline_id, ITEM_ID_AUDIO_EFFECT_CAPTION);
    cui_inline_delete_item(inline_id, ITEM_ID_AUDIO_EFFECT_ITEM_1);
    cui_inline_delete_item(inline_id, ITEM_ID_AUDIO_EFFECT_ITEM_2);
#endif

#ifdef __MMI_AUDIO_BASS_ENHANCEMENT__
    g_settings_selected_bass_enhancement = g_settings_bass_enhancement;
    cui_inline_set_value(inline_id, ITEM_ID_BASS_ITEM, (void *)g_settings_bass_enhancement);
    item_icons[i++] = IMG_GLOBAL_L1 + j;
    item_icons[i++] = 0;
    j++;
#else
    cui_inline_delete_item(inline_id, ITEM_ID_BASS_CAPTION);
    cui_inline_delete_item(inline_id, ITEM_ID_BASS_ITEM);
#endif

#ifdef __MMI_AUDIO_TIME_STRETCH__
    cui_inline_set_value(inline_id, ITEM_ID_PLAY_SPEED_ITEM, (void *)selected_speed_index);
    item_icons[i++] = IMG_GLOBAL_L1 + j;
    item_icons[i++] = 0;
    j++;
#else
    cui_inline_delete_item(inline_id, ITEM_ID_PLAY_SPEED_CAPTION);
    cui_inline_delete_item(inline_id, ITEM_ID_PLAY_SPEED_ITEM);
#endif /* __MMI_AUDIO_TIME_STRETCH__ */ 


    cui_inline_set_icon_list(inline_id, &item_icons[0]);
    cui_inline_set_title_icon(inline_id, GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID));
    cui_inline_run(inline_id);

    }    
#endif

#endif/* __MMI_AUDPLY_SINGLE_LAYER_SETTING__*/

#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_sound_effect_focus_changed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_set_one_layer_audio_effect_item(mmi_id inline_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    S32 inline_num = 0;
    U16 count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_settings_current_audio_effect)
    {
    #ifdef __MMI_AUDIO_EQUALIZER__
        case SETTINGS_SOUND_EFFECTS_EQ :
            for (i = 0; i < g_settings_audio_equalizer.count; i++)
            {
            #ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
                g_settings_audio_effects_inline2[i] = (UI_string_type)g_settings_audio_equalizer.setting_name[i];
            #else 
                g_settings_audio_effects_inline2[i] = (UI_string_type)GetString(audio_equalizer_list_str[i]);
            #endif
            }
            inline_num = g_settings_audio_equalizer.count;
            g_settings_current_effect_index = current_audio_equalizer_index;
            break;
    #endif
    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        case SETTINGS_SOUND_EFFECTS_REVERB :
            for (i = 0; i <= MAX_AUDIO_REVERB_EFFECT_NUM; i++)
            {
                g_settings_audio_effects_inline2[i] = (UI_string_type)GetString(audio_reverb_list_str[i]);
            }
            inline_num = MAX_AUDIO_REVERB_EFFECT_NUM;
            g_settings_current_effect_index = current_audio_reverb_index;
            break;
    #endif
    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        case SETTINGS_SOUND_EFFECTS_SURROUND :
                for(i = 0 ; i < AUD_SURROUND_TOTAL ; i++)
                {
                    g_settings_audio_effects_inline2[i] = (UI_string_type)GetString(audio_surround_list_str[i]);
                }
                inline_num = AUD_SURROUND_TOTAL;
                g_settings_current_effect_index = current_audio_surround_index;
            break;
    #endif
        default:
            break;
    }

    g_settings_audio_effects_inline1[count++] = (UI_string_type)GetString((U16)(STR_GLOBAL_OFF));
#ifdef __MMI_AUDIO_EQUALIZER__
    g_settings_audio_effects_inline1[count++] = (UI_string_type)GetString((U16)(STR_ID_SETTING_AUDIO_EQUALIZER));
#endif
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    g_settings_audio_effects_inline1[count++] = (UI_string_type)GetString((U16)(STR_ID_SETTING_AUDIO_REVERB_EFFECT));
#endif
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    g_settings_audio_effects_inline1[count++] = (UI_string_type)GetString((U16)(STR_ID_SETTING_AUDIO_SURROUND_EFFECT));        
#endif
    
    g_settings_current_audio_effect_prev = g_settings_current_audio_effect;

    cui_inline_set_item_select(inline_id, 
                   ITEM_AUDIO_EFFECT_ITEM_1, 
        NO_OF_SETTINGS_SOUND_EFFECTS,
                   (PU8 *)g_settings_audio_effects_inline1, 
                   g_settings_current_audio_effect);

    if (g_settings_current_audio_effect != SETTINGS_SOUND_EFFECTS_NONE)
    {
        cui_inline_set_item_attributes(
            inline_id, 
            ITEM_AUDIO_EFFECT_ITEM_2, 
            CUI_INLINE_SET_ATTRIBUTE, 
            INLINE_ITEM_TYPE_SELECT);
        cui_inline_set_item_select(
            inline_id, 
            ITEM_AUDIO_EFFECT_ITEM_2, 
            inline_num,
            (PU8 *)g_settings_audio_effects_inline2, 
            g_settings_current_effect_index);
    }
    else
    {
        cui_inline_set_item_attributes(
                inline_id, 
                ITEM_AUDIO_EFFECT_ITEM_2, 
                CUI_INLINE_SET_ATTRIBUTE, 
                INLINE_ITEM_TYPE_CAPTION);
        cui_inline_set_value(inline_id, ITEM_AUDIO_EFFECT_ITEM_2, GetString(STR_GLOBAL_EMPTY));
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_sound_effect_focus_changed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_set_audio_effect_item(mmi_id inline_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    S32 inline_num = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_settings_current_audio_effect)
    {
    #ifdef __MMI_AUDIO_EQUALIZER__
        case SETTINGS_SOUND_EFFECTS_EQ :
            for (i = 0; i < g_settings_audio_equalizer.count; i++)
            {
            #ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
                g_settings_audio_effects_inline2[i] = (UI_string_type)g_settings_audio_equalizer.setting_name[i];
            #else 
                g_settings_audio_effects_inline2[i] = (UI_string_type)GetString(audio_equalizer_list_str[i]);
            #endif
            }
            inline_num = g_settings_audio_equalizer.count;
            g_settings_current_effect_index = current_audio_equalizer_index;
            break;
    #endif
    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        case SETTINGS_SOUND_EFFECTS_REVERB :
            for (i = 0; i <= MAX_AUDIO_REVERB_EFFECT_NUM; i++)
            {
                g_settings_audio_effects_inline2[i] = (UI_string_type)GetString(audio_reverb_list_str[i]);
            }
            inline_num = MAX_AUDIO_REVERB_EFFECT_NUM;
            g_settings_current_effect_index = current_audio_reverb_index;
            break;
    #endif
    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        case SETTINGS_SOUND_EFFECTS_SURROUND :
            if(g_settings_current_audio_effect == SETTINGS_SOUND_EFFECTS_SURROUND)
            {
                for(i = 0 ; i < AUD_SURROUND_TOTAL ; i++)
                {
                    g_settings_audio_effects_inline2[i] = (UI_string_type)GetString(audio_surround_list_str[i]);
                }
                inline_num = AUD_SURROUND_TOTAL;
                g_settings_current_effect_index = current_audio_surround_index;
            }
            break;
    #endif
        default:
            break;
    }

    g_settings_current_audio_effect_prev = g_settings_current_audio_effect;

    if (g_settings_current_audio_effect != SETTINGS_SOUND_EFFECTS_NONE)
    {
        cui_inline_set_item_attributes(
            inline_id, 
            ITEM_ID_AUDIO_EFFECT_ITEM_2, 
            CUI_INLINE_SET_ATTRIBUTE, 
            INLINE_ITEM_TYPE_SELECT);
        cui_inline_set_item_select(
            inline_id, 
            ITEM_ID_AUDIO_EFFECT_ITEM_2, 
            inline_num, 
            (PU8 *)g_settings_audio_effects_inline2, 
            g_settings_current_effect_index);
    }
    else
    {
        cui_inline_set_item_attributes(
                inline_id, 
                ITEM_ID_AUDIO_EFFECT_ITEM_2, 
                CUI_INLINE_SET_ATTRIBUTE, 
                INLINE_ITEM_TYPE_DISPLAY_ONLY);
        cui_inline_set_value(inline_id, ITEM_ID_AUDIO_EFFECT_ITEM_2, GetString(STR_GLOBAL_EMPTY));
    }
}
#endif
    
#ifndef __MMI_AUDPLY_SINGLE_LAYER_SETTING__
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_sound_effect_settings_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_sound_effect_settings_confirm_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_AUDIO_TIME_STRETCH__
    S16 error;
#endif 
#if defined(__MMI_A2DP_SUPPORT__) && defined(__MMI_AUDIO_TIME_STRETCH__)
    U16 prev_speed = g_audply.speed;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check format and apply change begore apply speed */
#ifdef __MMI_AUDIO_TIME_STRETCH__
#ifdef __MMI_A2DP_SUPPORT__
    /* check if need to reopen av bt */
    if (prev_speed == MDI_AUDIO_SPEED_NORMAL && prev_speed != g_audply.speed &&
        mmi_a2dp_is_output_to_bt() && av_bt_is_mp3_cfg())
    {
        mmi_audply_sync_bt_output();
    }
#endif /* __MMI_BT_MTK_SUPPORT__ && __MMI_A2DP_SUPPORT__ */

    WriteValueSlim(NVRAM_AUDIO_SPEED_VALUE, &g_audply.speed, DS_SHORT);
#endif /* __MMI_AUDIO_TIME_STRETCH__ */ 

#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
    if (g_settings_selected_audio_effect != g_settings_current_audio_effect || 
       g_settings_current_audio_effect == SETTINGS_SOUND_EFFECTS_NONE)
    {
        mmi_settings_turn_off_audio_effect();
    }

    switch (g_settings_current_audio_effect)
    {
    #ifdef __MMI_AUDIO_EQUALIZER__
        case SETTINGS_SOUND_EFFECTS_EQ :
            mmi_settings_audio_eq_apply((S16)current_audio_equalizer_index);
            break;
    #endif
    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        case SETTINGS_SOUND_EFFECTS_REVERB :
            mmi_settings_audio_reverb_apply((U16)current_audio_reverb_index);
            break;
    #endif
    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        case SETTINGS_SOUND_EFFECTS_SURROUND :
            mmi_settings_audio_surround_apply((U16)current_audio_surround_index);
            break;
    #endif
        default :
            break;
    }

    g_settings_selected_audio_effect = g_settings_current_audio_effect;
    mmi_settings_audio_effect_write_nvram();

#endif /*__MMI_AUDIO_EQUALIZER__ || __MMI_AUDIO_REVERB_EFFECT__ || __MMI_AUDIO_SURROUND_EFFECT__*/
#ifdef __MMI_AUDIO_BASS_ENHANCEMENT__
    if(g_settings_bass_enhancement != g_settings_selected_bass_enhancement)
    {
        mmi_settings_bass_enhancement_apply(g_settings_selected_bass_enhancement);
    }
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_sound_effect_settings_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_sound_effect_settings_done(mmi_id inline_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_AUDIO_BASS_ENHANCEMENT__
    cui_inline_get_value(inline_gid, ITEM_ID_BASS_ITEM, &g_settings_selected_bass_enhancement);
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check format and apply change begore apply speed */
#ifdef __MMI_AUDIO_TIME_STRETCH__
    cui_inline_get_value(inline_gid, ITEM_ID_PLAY_SPEED_ITEM, &selected_speed_index);
    if (!mmi_audply_apply_change_in_setting((U16)selected_speed_index))
    {
        mmi_popup_display_simple((WCHAR*)GetString(STR_ID_AUDPLY_UNSUPPORTED_SPEED), 
                                 MMI_EVENT_FAILURE, 
                                 GRP_ID_ROOT, 
                                 NULL);
        return;
    }
#endif /* __MMI_AUDIO_TIME_STRETCH__ */ 

#if defined(__MMI_AUDIO_EQUALIZER__) ||  defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
#ifdef __MMI_AUDIO_SURROUND_BIND_EARPHONE__
    if(g_settings_current_audio_effect == SETTINGS_SOUND_EFFECTS_SURROUND)
    {
        mmi_audply_sound_effect_settings_confirm_done();
        mmi_popup_display_simple((WCHAR*)GetString(STR_ID_SETTING_AUDIO_SURROUND_PLUG_EAPHONE), 
                                 MMI_EVENT_INFO, 
                                 GRP_ID_ROOT, 
                                 NULL);
    }
    else
#endif /* __MMI_AUDIO_SURROUND_BIND_EARPHONE__ */
#endif
    {
        mmi_audply_sound_effect_settings_confirm_done();
    }
}

#endif/*__MMI_AUDPLY_SINGLE_LAYER_SETTING__*/
#if defined(__MMI_AUDIO_TIME_STRETCH__)
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_speed_get_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  speed       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U16 mmi_audply_speed_get_index(U16 speed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     *   Slow2 | Slow1 | Normal | Fast1 | Fast2
     *     3           4            0           1          2
     */
    switch (speed)
    {
        case MDI_AUDIO_SPEED_SLOW1:
            index = 4;
            break;
        case MDI_AUDIO_SPEED_SLOW2:
            index = 3;
            break;
        case MDI_AUDIO_SPEED_FAST1:
            index = 1;
            break;
        case MDI_AUDIO_SPEED_FAST2:
            index = 2;
            break;
        case MDI_AUDIO_SPEED_NORMAL:
        default:
            break;
    }

    return index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_speed_get_speed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U16 mmi_audply_speed_get_speed(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 speed = MDI_AUDIO_SPEED_NORMAL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     *   Slow2 | Slow1 | Normal | Fast1 | Fast2
     *     3           4            0           1          2
     */
    switch (index)
    {
        case 1:
            speed = MDI_AUDIO_SPEED_FAST1;
            break;
        case 2:
            speed = MDI_AUDIO_SPEED_FAST2;
            break;
        case 3:
            speed = MDI_AUDIO_SPEED_SLOW2;
            break;
        case 4:
            speed = MDI_AUDIO_SPEED_SLOW1;
            break;
        case 0:
        default:
            break;
    }
    return speed;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_apply_change_in_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_audply_apply_change_in_setting(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 new_speed;
    mdi_result set_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_speed = mmi_audply_speed_get_speed(index);

    if (g_audply.speed != new_speed)
    {
        if (g_audply.state == STATE_PLAY)
        {
            /* Check format when change speed from normal speed */
            if ((g_audply.speed == MDI_AUDIO_SPEED_NORMAL) && (new_speed != MDI_AUDIO_SPEED_NORMAL))
            {
                if (mmi_audply_speed_check_before_play(new_speed) != MDI_AUDIO_SUCCESS)
                {
                    return MMI_FALSE;
                }
            }

            /* Set speed while playing */
            if (g_audply.state == STATE_PLAY)
            {
                set_result = mdi_audio_stretch_set_speed(new_speed);

                /* Set fail during playing, don't apply value */
                if (set_result != MDI_AUDIO_SUCCESS)
                {
                    return MMI_FALSE;
                }

                /* Only increase once if turn on in setting menu while playing */
                if (g_audply.speed_set_times == 0)
                {
                    g_audply.speed_set_times++;
                }
            }
        }

        g_audply.speed = new_speed;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_speed_set_speed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_speed_set_speed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result set_result;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_result = mdi_audio_stretch_set_speed(g_audply.speed);

    /* Restore speed to normal when set fail */
    if (set_result != MDI_AUDIO_SUCCESS)
    {
        g_audply.speed = MDI_AUDIO_SPEED_NORMAL;
        WriteValueSlim(NVRAM_AUDIO_SPEED_VALUE, &g_audply.speed, DS_SHORT);
    }

    g_audply.speed_set_times++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_speed_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_speed_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply.speed_set_times == 1)
    {
        mdi_audio_stretch_close();
    }

    if (g_audply.speed_set_times > 0)
    {
        g_audply.speed_set_times--;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_speed_check_before_play
 * DESCRIPTION
 *  (Note) This function shold only be called before request to play a file.
 * PARAMETERS
 *  speed       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_audply_speed_check_before_play(U16 speed) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result = MDI_AUDIO_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check speed only when speed is not normal */
    if (speed != MDI_AUDIO_SPEED_NORMAL)
    {
        result = mdi_audio_stretch_check_file_format((void*)g_audply.filefullname);
    }

    /*in case DRM file can not open, only check for speed*/
    if(result != MDI_AUDIO_UNSUPPORTED_SPEED)
    {
        result = MDI_AUDIO_SUCCESS;
    }

    return (S32) result;
}
#endif /* __MMI_AUDIO_TIME_STRETCH__ */ 

#ifndef __MMI_AUDPLY_SINGLE_LAYER_SETTING__

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_entry_display_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_entry_display_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_AUDIO_PLAYER_SKIN_SLIM__    
    S32 skin = g_audply.skin;
#endif

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    S32 spectrum_style = g_audply.spectrum_style;
#endif
#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
    S32 lyrics_style = g_audply.lyrics_display;
#endif
    mmi_id inline_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inline_id = cui_inline_create(GRP_ID_AUDPLY_SETTINGS, &mmi_audply_display_setting_inline_screen);

    if (inline_id == GRP_ID_INVALID)
    {
        return;
    }
    g_audply_current_setting = MMI_AUDPLY_DISPLAY_SETTINGS;
    
    /* skin */
#ifdef __MMI_AUDIO_PLAYER_SKIN_SLIM__ 
    cui_inline_delete_item(inline_id, ITEM_ID_SKIN_CAPTION);
    cui_inline_delete_item(inline_id, ITEM_ID_SKIN_ITEM);
#else
    cui_inline_set_value(inline_id, ITEM_ID_SKIN_ITEM, (void *)skin);
#endif /* __MMI_AUDIO_PLAYER_SKIN_SLIM__ */ 


#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    #ifdef __MMI_AUDIO_PLAYER_SKIN_SLIM__
    if (mmi_audply_is_spectrum_valid())
    #else
    if (g_audply_skins[skin].spectrum_display_x >= 0)
    #endif
    {
        cui_inline_set_value(inline_id, ITEM_ID_SPECTRUM_ITEM, (void *)spectrum_style);
    }
    else
    {
        cui_inline_delete_item(inline_id, ITEM_ID_SPECTRUM_CAPTION);
        cui_inline_delete_item(inline_id, ITEM_ID_SPECTRUM_ITEM);
    }
#else
    cui_inline_delete_item(inline_id, ITEM_ID_SPECTRUM_CAPTION);
    cui_inline_delete_item(inline_id, ITEM_ID_SPECTRUM_ITEM);
#endif /*__MMI_AUDIO_SPECTRUM_DISPLAY__*/

#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
    #ifdef __MMI_AUDIO_PLAYER_SKIN_SLIM__
    if (mmi_audply_is_lyrics_valid())
    #else
    if (g_audply_skins[skin].lyric_display_x >= 0)
    #endif
    {
        cui_inline_set_value(inline_id, ITEM_ID_LYRICS_ITEM, (void *)lyrics_style);
    }
    else
{
        cui_inline_delete_item(inline_id, ITEM_ID_LYRICS_CAPTION);
        cui_inline_delete_item(inline_id, ITEM_ID_LYRICS_ITEM);    
}
#else
    cui_inline_delete_item(inline_id, ITEM_ID_LYRICS_CAPTION);
    cui_inline_delete_item(inline_id, ITEM_ID_LYRICS_ITEM);    
#endif /*__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__*/

    cui_inline_set_icon_list(inline_id, &audply_setting_item_icons[0]);
    cui_inline_set_title_icon(inline_id, GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID));
    cui_inline_run(inline_id);
}

#endif

#ifndef __MMI_AUDPLY_SINGLE_LAYER_SETTING__

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_display_settings_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_display_settings_done(mmi_id inline_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_AUDIO_PLAYER_SKIN_SLIM__
    MMI_BOOL skin_changed;
    U8 skin = 0;
#endif
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    MMI_BOOL style_changed;
    U8 spectrum_style = 0;
#endif
#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
    MMI_BOOL lyrics_changed;
    U8 lyrics_display = 0;
#endif
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_AUDIO_PLAYER_SKIN_SLIM__	
    cui_inline_get_value(inline_gid, ITEM_ID_SKIN_ITEM, &skin);
#endif

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    cui_inline_get_value(inline_gid, ITEM_ID_SPECTRUM_ITEM, &spectrum_style);
#endif

#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
    cui_inline_get_value(inline_gid, ITEM_ID_LYRICS_ITEM, &lyrics_display);
#endif

    /* apply it */
#ifndef __MMI_AUDIO_PLAYER_SKIN_SLIM__    
    skin_changed = (MMI_BOOL)( skin != g_audply.skin);
    g_audply.skin = (U8)skin;

#endif

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__ 
    style_changed = (MMI_BOOL)(spectrum_style != g_audply.spectrum_style) ;
    if (mmi_audply_is_spectrum_valid())
    {
        g_audply.spectrum_style = (U8) spectrum_style;
    }
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 

#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
    lyrics_changed = (MMI_BOOL)(lyrics_display != g_audply.lyrics_display) ;
    if (mmi_audply_is_lyrics_valid())
    {
        g_audply.lyrics_display = (U8) lyrics_display;
    }
#endif

    /* save to nvram */
#ifndef __MMI_AUDIO_PLAYER_SKIN_SLIM__
    WriteValueSlim(NVRAM_AUDPLY_SKIN, &g_audply.skin, DS_BYTE);
#endif
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    WriteValueSlim(NVRAM_AUDPLY_SPECTRUM_DISPLAY_STYLE, &g_audply.spectrum_style, DS_BYTE);
#endif    
#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
    WriteValueSlim(NVRAM_AUDPLY_LYRICS_DISPLAY, &g_audply.lyrics_display, DS_BYTE);
#endif


    /* go back */
    settings_done_back_to_main = MMI_FALSE;
#ifndef __MMI_AUDIO_PLAYER_SKIN_SLIM__
    if (skin_changed)
    {
        settings_done_back_to_main = MMI_TRUE;
    }
#endif    
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    if (mmi_audply_is_spectrum_valid() && style_changed)
    {
        settings_done_back_to_main = MMI_TRUE;
    }
#endif     
#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
    if (mmi_audply_is_lyrics_valid() && lyrics_changed)
    {
        settings_done_back_to_main = MMI_TRUE;
    }        
#endif 

#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
    if (settings_done_back_to_main)
    {
        /* TODO: Change it to group api*/
        mmi_frm_group_close(GRP_ID_AUDPLY_SETTINGS);
        mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);
        if (mmi_frm_group_is_present(GRP_ID_AUDPLY_LIST_BROWSER))
        {
            mmi_frm_group_close(GRP_ID_AUDPLY_LIST_BROWSER);
        }
    }
    else
    {
        mmi_frm_scrn_close_active_id();
    }
#elif defined(__MMI_AUDPLY_MULTIPLE_LIST__)
    {
        mmi_frm_scrn_close_active_id();
    }
#endif  /* __MMI_AUDIO_PLAYER_SINGLE_LIST__ */
}

#endif

#ifndef __MMI_AUDPLY_SINGLE_LAYER_SETTING__
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_entry_player_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_entry_player_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 list_auto_gen = (S32)g_audply.list_auto_gen;
    S32 repeat_mode = (S32)g_audply.repeat_mode;
    S32 random_mode = (S32)g_audply.random_mode;
#if (defined(__MMI_AUDIO_PLAYER_ON_SUBLCD__) || defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__) || defined(__MMI_VUI_LAUNCHER_KEY__))
#else
    S32 background_play = (S32)g_audply.background_play;
#endif
    mmi_id inline_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inline_id = cui_inline_create(GRP_ID_AUDPLY_SETTINGS, &mmi_audply_player_setting_inline_screen);
 
    if (inline_id != GRP_ID_INVALID) 
    {
        g_audply_current_setting = MMI_AUDPLY_PLAYER_SETTINGS;

    #if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)    
        mmi_audply_settings_inline_set_storage(inline_id);
        cui_inline_set_value(inline_id, ITEM_ID_AUTO_GEN_ITEM, (void *)list_auto_gen);
    #else
        cui_inline_delete_item(inline_id, ITEM_ID_PREFER_LIST_CAPTION);
        cui_inline_delete_item(inline_id, ITEM_ID_PREFER_LIST_ITEM);
        #ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
        cui_inline_delete_item(inline_id, ITEM_ID_AUTO_GEN_CAPTION);
        #endif
        cui_inline_delete_item(inline_id, ITEM_ID_AUTO_GEN_ITEM);
    #endif

        cui_inline_set_value(inline_id, ITEM_ID_REPEAT_ITEM, (void *)repeat_mode);
        cui_inline_set_value(inline_id, ITEM_ID_SHUFFLE_ITEM, (void *)random_mode);

    #if (defined(__MMI_AUDIO_PLAYER_ON_SUBLCD__) || defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__) || defined(__MMI_VUI_LAUNCHER_KEY__))
        cui_inline_delete_item(inline_id, ITEM_ID_BG_PLAY_CAPTION);
        cui_inline_delete_item(inline_id, ITEM_ID_BG_PLAY_ITEM);
    #else
        cui_inline_set_value(inline_id, ITEM_ID_BG_PLAY_ITEM, (void *)background_play);
    #endif
        cui_inline_set_icon_list(inline_id, &audply_setting_item_icons[0]);
        cui_inline_set_title_icon(inline_id, GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID));
        cui_inline_run(inline_id);
    }
}

#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_inline_set_storage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_settings_inline_set_storage(MMI_ID inline_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  total_drv_num;
    SRV_FMGR_DRVLIST_HANDLE drv_list;
    S32 i;
    U8 drv;
    U8 *storage_str_p[SRV_FMGR_DRV_TOTAL];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drv_list = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ALL);
    total_drv_num = (U8)srv_fmgr_drivelist_count(drv_list); 
    for(i = 0; i < total_drv_num; i++)
    {
        drv = srv_fmgr_drivelist_get_drv_letter(drv_list, i);
        storage_str_p[i] = (U8*)get_string(srv_fmgr_drv_get_string(drv));
    }
    srv_fmgr_drivelist_get_drv_letter(drv_list, selected_preferred_list);
    srv_fmgr_drivelist_destroy(drv_list);

    if (total_drv_num > 1)
    {
        cui_inline_set_item_select(inline_id, 
            ITEM_ID_PREFER_LIST_ITEM, 
            total_drv_num, 
            (U8 **) storage_str_p,
            selected_preferred_list);
    }
    else
    {
        cui_inline_delete_item(inline_id,  ITEM_ID_PREFER_LIST_CAPTION);
        cui_inline_delete_item(inline_id,  ITEM_ID_PREFER_LIST_ITEM);
    }
}


#ifndef __MMI_AUDPLY_SINGLE_LAYER_SETTING__
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_player_settings_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_player_settings_done(mmi_id inline_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 preferred_list = 0;
    U8 list_auto_gen = 0;
    U8 repeat_mode = 0;
    U8 random_mode = 0;
    U8 background_play = 0;
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
    S32 result;
    CHAR driveletter;
    SRV_FMGR_DRVLIST_HANDLE drv_list;
    MMI_BOOL list_auto_gen_changed; 
    U8 old_present_list = g_audply.present_list;
    MMI_BOOL prefferred_changed;
#endif  /* __MMI_AUDIO_PLAYER_SINGLE_LIST__ */    
    /* if we turn list auto gen ON, we need to regen the list */
    MMI_BOOL repeat_mode_changed;
    MMI_BOOL random_mode_changed;
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_get_value(inline_gid, ITEM_ID_PREFER_LIST_ITEM, &preferred_list);
    #ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
    cui_inline_get_value(inline_gid, ITEM_ID_AUTO_GEN_ITEM, &list_auto_gen);
    #endif
    cui_inline_get_value(inline_gid, ITEM_ID_REPEAT_ITEM, &repeat_mode);
    cui_inline_get_value(inline_gid, ITEM_ID_SHUFFLE_ITEM, &random_mode);
    cui_inline_get_value(inline_gid, ITEM_ID_BG_PLAY_ITEM, &background_play);

    list_auto_gen_changed = (MMI_BOOL)(g_audply.list_auto_gen != list_auto_gen); 
    repeat_mode_changed = (MMI_BOOL)(repeat_mode != g_audply.repeat_mode);
    random_mode_changed = (MMI_BOOL)(random_mode != g_audply.random_mode);
    
    g_audply.repeat_mode = (U8)repeat_mode;
    g_audply.random_mode = (U8)random_mode;
    WriteValueSlim(NVRAM_AUDPLY_REPEAT, &g_audply.repeat_mode, DS_BYTE);
    WriteValueSlim(NVRAM_AUDPLY_SHUFFLE, &g_audply.random_mode, DS_BYTE);
    
#if (!defined(__MMI_AUDIO_PLAYER_ON_SUBLCD__) && !(defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__)||defined(__MMI_VUI_LAUNCHER_KEY__)))
    g_audply.background_play = (U8)background_play;
    WriteValueSlim(NVRAM_AUDPLY_BACKGROUND_PLAY, &g_audply.background_play, DS_BYTE);
#endif

#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)    

    drv_list = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ALL);
    driveletter = srv_fmgr_drivelist_get_drv_letter(drv_list, preferred_list);
    srv_fmgr_drivelist_destroy(drv_list);
    result = FS_GetDevStatus(driveletter, FS_MOUNT_STATE_ENUM);
   
	if (result < FS_NO_ERROR)
    {
        mmi_popup_display_simple((WCHAR*)(get_string(srv_fmgr_fs_error_get_string(FS_DRIVE_NOT_FOUND))), MMI_EVENT_ERROR, GRP_ID_ROOT, NULL);
		g_flag_memory_card_not_present = 1;

        return;
    }



    g_audply.list_auto_gen = (U8)list_auto_gen;
    prefferred_changed = (MMI_BOOL)(g_audply.preferred_list != driveletter);
    g_audply.preferred_list = driveletter;
    if(prefferred_changed)
    {
        g_audply.duration = 0;
    }

    /* save to nvram */
    #ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
    WriteValueSlim(NVRAM_AUDPLY_LIST_AUTO_GEN, &g_audply.list_auto_gen, DS_BYTE);
    #endif
    WriteValueSlim(NVRAM_AUDPLY_PREFER_LIST, &g_audply.preferred_list, DS_BYTE);
#ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
    if (list_auto_gen_changed)
    {
        if (g_audply.list_auto_gen)
        {
            mmi_audply_stop_playing();
            need_refresh_list = MMI_TRUE;
        }
        else
        {
            need_refresh_list = MMI_FALSE;
        }
    }
    #endif
    if (prefferred_changed)
    {
        /* update present list */
        g_audply.present_list = mmi_audply_get_current_list_drv();

        if (g_audply.present_list != old_present_list)
        {
            mmi_audply_stop_playing();
            need_reload_list = MMI_TRUE;
        }
        /* if the present list is changed and list auto gen is ON, we need to regen the list */
        #ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
        if (g_audply.list_auto_gen && need_reload_list)
        {
            need_refresh_list = MMI_TRUE;
        }
        #endif
    }

    if (!need_reload_list &&
        (repeat_mode_changed || random_mode_changed) &&
        mmi_audply_playlist_get_current_index() >= 0)
    {
        S32 index = mmi_audply_playlist_get_current_index();
        mmi_audply_playlist_set_start(index);
        mmi_audply_playlist_set_pick_index(index);
    }
#else
    if ((repeat_mode_changed || random_mode_changed) &&
        mmi_audply_playlist_get_current_index() >= 0)
    {
        S32 index = mmi_audply_playlist_get_current_index();
        mmi_audply_playlist_set_start(index);
        mmi_audply_playlist_set_pick_index(index);
    }
#endif  /* __MMI_AUDIO_PLAYER_SINGLE_LIST__ */ 

	mmi_frm_scrn_close_active_id();
	
}

#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_entry_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_entry_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id inline_id;
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__) 
    U8 total_drv_num;
    U8 drv;
    SRV_FMGR_DRVLIST_HANDLE drv_list;
    U8 *storage_str_p[SRV_FMGR_DRV_TOTAL];
#endif
    U16 i = 0;
    U16 image_i = 0;
    U16 n_items = 0;
    MMI_ID_TYPE item_icons[AUDPLY_SETTING_ITEM_COUNT * 2];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create_ex(
    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
        GRP_ID_AUDPLY_MAIN_PRE_LIST,
    #else
        GRP_ID_ROOT, 
    #endif
        GRP_ID_AUDPLY_SETTINGS, 
        mmi_audply_settings_group_proc, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    inline_id = cui_inline_create(GRP_ID_AUDPLY_SETTINGS, &mmi_audply_setting_inline_screen);

    if (inline_id == GRP_ID_INVALID)
    {
        return;
    }
    g_audply_current_setting = MMI_AUDPLY_ONE_LAYER_SETTINGS;


    #if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__) && !defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__)
#ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
        selected_list_auto_gen = g_audply.list_auto_gen;
#endif
        drv_list = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ALL);
        total_drv_num = (U8)srv_fmgr_drivelist_count(drv_list); 
        for(i = 0; i < total_drv_num; i++)
        {
            drv = srv_fmgr_drivelist_get_drv_letter(drv_list, i);
            storage_str_p[i] = (U8*)get_string(srv_fmgr_drv_get_string(drv));
        }
        selected_preferred_list = srv_fmgr_drivelist_get_index_by_drv_letter(drv_list, g_audply.preferred_list);
        srv_fmgr_drivelist_destroy(drv_list);
    #endif
    #ifndef __MMI_AUDIO_PLAYER_SKIN_SLIM__        
        selected_skin = g_audply.skin;
    #endif
        selected_repeat_mode = g_audply.repeat_mode;
        selected_random_mode = g_audply.random_mode;
    #if (!defined(__MMI_AUDIO_PLAYER_ON_SUBLCD__) && !(defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__)||defined(__MMI_VUI_LAUNCHER_KEY__)))
        selected_background_play = g_audply.background_play;
    #endif

    
    #if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
        g_settings_current_audio_effect = g_settings_selected_audio_effect;
    #ifdef __MMI_AUDIO_EQUALIZER__
        current_audio_equalizer_index = (U16)g_settings_audio_equalizer.index;
    #endif
    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        current_audio_reverb_index = g_mmi_aud_3d_cntx.reverb_index;
    #endif
    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        current_audio_surround_index = g_mmi_aud_3d_cntx.surround_index;
    #endif
    #endif /*__MMI_AUDIO_EQUALIZER__ || __MMI_AUDIO_REVERB_EFFECT__ || __MMI_AUDIO_SURROUND_EFFECT__*/

    #ifdef __MMI_AUDIO_BASS_ENHANCEMENT__
        g_settings_selected_bass_enhancement = g_settings_bass_enhancement;
    #endif

    #ifdef __MMI_AUDIO_TIME_STRETCH__
        selected_speed_index = (S32) mmi_audply_speed_get_index(g_audply.speed);
    #endif 

    #ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__  
        selected_spectrum_style = g_audply.spectrum_style;
    #endif 
    #if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
        selected_lyrics_style = g_audply.lyrics_display;
    #endif

#if !defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__)
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
    drv_list = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ALL);
    total_drv_num = (U8)srv_fmgr_drivelist_count(drv_list); 
    for(i = 0; i < total_drv_num; i++)
    {
        drv = srv_fmgr_drivelist_get_drv_letter(drv_list, i);
        storage_str_p[i] = (U8*)get_string(srv_fmgr_drv_get_string(drv));
    }
    srv_fmgr_drivelist_get_drv_letter(drv_list, selected_preferred_list);
    srv_fmgr_drivelist_destroy(drv_list);


    if (total_drv_num > 1)
    {
        cui_inline_set_item_select(inline_id, 
            ITEM_PREFER_LIST_ITEM, 
            total_drv_num, 
            (U8 **) storage_str_p,
            selected_preferred_list);
        item_icons[n_items++] = IMG_GLOBAL_L1 + (image_i++);
        item_icons[n_items++] = 0;
    }
    else
    {
        cui_inline_delete_item(inline_id, ITEM_PREFER_LIST_CAPTION);
        cui_inline_delete_item(inline_id,  ITEM_PREFER_LIST_ITEM);
    }
#ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
    cui_inline_set_value(inline_id, ITEM_AUTO_GEN_ITEM, (void *)selected_list_auto_gen);
    item_icons[n_items++] = IMG_GLOBAL_L1 + (image_i++);
    item_icons[n_items++] = 0;
#endif
#else
    cui_inline_delete_item(inline_id, ITEM_PREFER_LIST_CAPTION);
    cui_inline_delete_item(inline_id, ITEM_PREFER_LIST_ITEM);
    cui_inline_delete_item(inline_id, ITEM_AUTO_GEN_CAPTION);
    cui_inline_delete_item(inline_id, ITEM_AUTO_GEN_ITEM);
#endif

#ifdef __MMI_AUDIO_PLAYER_SKIN_SLIM__ 
    cui_inline_delete_item(inline_id, ITEM_SKIN_CAPTION);
    cui_inline_delete_item(inline_id, ITEM_SKIN_ITEM);
#else
    cui_inline_set_value(inline_id, ITEM_SKIN_ITEM, (void *)selected_skin);
    item_icons[n_items++] = IMG_GLOBAL_L1 + (image_i++);
    item_icons[n_items++] = 0;
#endif /* __MMI_AUDIO_PLAYER_SKIN_SLIM__ */ 

    cui_inline_set_value(inline_id, ITEM_REPEAT_ITEM, (void *)selected_repeat_mode);
    item_icons[n_items++] = IMG_GLOBAL_L1 + (image_i++);
    item_icons[n_items++] = 0;

    cui_inline_set_value(inline_id, ITEM_SHUFFLE_ITEM, (void *)selected_random_mode);
    item_icons[n_items++] = IMG_GLOBAL_L1 + (image_i++);
    item_icons[n_items++] = 0;
#endif  //!defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__)

#if (defined(__MMI_AUDIO_PLAYER_ON_SUBLCD__) || defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__) ||defined(__MMI_VUI_LAUNCHER_KEY__))
    cui_inline_delete_item(inline_id, ITEM_BG_PLAY_CAPTION);
    cui_inline_delete_item(inline_id, ITEM_BG_PLAY_ITEM);
#else
    cui_inline_set_value(inline_id, ITEM_BG_PLAY_ITEM, (void *)selected_background_play);
    item_icons[n_items++] = IMG_GLOBAL_L1 + (image_i++);
    item_icons[n_items++] = 0;
#endif

#if defined(__MMI_A2DP_SUPPORT__) && !defined(__MMI_A2DP_HIDE_BT_SETTINGS__)
    if (!mmi_bt_is_to_display_bt_menu())
    {
       cui_inline_delete_item(inline_id, ITEM_BT_SETTING_ITEM);

    }
    else
   {
    item_icons[n_items++] = IMG_GLOBAL_L1 + (image_i++);
   }
#else
    cui_inline_delete_item(inline_id, ITEM_BT_SETTING_ITEM);
#endif /* __MMI_BT_MTK_SUPPORT__ && __MMI_A2DP_SUPPORT__ */


#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
    mmi_audply_set_one_layer_audio_effect_item(inline_id);
    item_icons[n_items++] = IMG_GLOBAL_L1 + (image_i++);
    item_icons[n_items++] = 0;
    item_icons[n_items++] = 0;
#else 
    cui_inline_delete_item(inline_id, ITEM_AUDIO_EFFECT_CAPTION);
    cui_inline_delete_item(inline_id, ITEM_AUDIO_EFFECT_ITEM_1);
    cui_inline_delete_item(inline_id, ITEM_AUDIO_EFFECT_ITEM_2);
#endif /*defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)*/

#ifdef __MMI_AUDIO_BASS_ENHANCEMENT__
    cui_inline_set_value(inline_id, ITEM_BASS_ITEM, (void *)g_settings_selected_bass_enhancement);
    item_icons[n_items++] = IMG_GLOBAL_L1 + (image_i++);
    item_icons[n_items++] = 0;
#else
    cui_inline_delete_item(inline_id, ITEM_BASS_CAPTION);
    cui_inline_delete_item(inline_id, ITEM_BASS_ITEM);
#endif


#ifdef __MMI_AUDIO_TIME_STRETCH__
    cui_inline_set_value(inline_id, ITEM_PLAY_SPEED_ITEM, (void *)selected_speed_index);
    item_icons[n_items++] = IMG_GLOBAL_L1 + (image_i++);
    item_icons[n_items++] = 0;
#else
    cui_inline_delete_item(inline_id, ITEM_PLAY_SPEED_CAPTION);
    cui_inline_delete_item(inline_id, ITEM_PLAY_SPEED_ITEM);
#endif /* __MMI_AUDIO_TIME_STRETCH__ */ 

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    if (mmi_audply_is_spectrum_valid())
    {
        cui_inline_set_value(inline_id, ITEM_SPECTRUM_ITEM, (void *)selected_spectrum_style);
        item_icons[n_items++] = IMG_GLOBAL_L1 + (image_i++);
        item_icons[n_items++] = 0;
    }
    else
    {
        cui_inline_delete_item(inline_id, ITEM_SPECTRUM_CAPTION);
        cui_inline_delete_item(inline_id, ITEM_SPECTRUM_ITEM);
    }
#else
    cui_inline_delete_item(inline_id, ITEM_SPECTRUM_CAPTION);
    cui_inline_delete_item(inline_id, ITEM_SPECTRUM_ITEM);
#endif /*__MMI_AUDIO_SPECTRUM_DISPLAY__*/

#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
    if(mmi_audply_is_lyrics_valid())
    {
        cui_inline_set_value(inline_id, ITEM_LYRICS_ITEM, (void *)selected_lyrics_style);
        item_icons[n_items++] = IMG_GLOBAL_L1 + (image_i++);
        item_icons[n_items++] = 0;
    }
    else
    {
        cui_inline_delete_item(inline_id, ITEM_LYRICS_CAPTION);
        cui_inline_delete_item(inline_id, ITEM_LYRICS_ITEM);
    }
#else
    cui_inline_delete_item(inline_id, ITEM_LYRICS_CAPTION);
    cui_inline_delete_item(inline_id, ITEM_LYRICS_ITEM);
#endif /*__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__*/

#if 0//def __MMI_AUDPLY_WALK_PLAY__
/* under construction !*/
#endif  //__MMI_AUDPLY_WALK_PLAY__
    cui_inline_set_icon_list(inline_id, &item_icons[0]);
    cui_inline_set_title_icon(inline_id, GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID));
    cui_inline_run(inline_id);

}



/*****************************************************************************
 * FUNCTION
 *  mmi_audply_settings_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_settings_LSK(mmi_id inline_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
	S32 result;
    CHAR driveletter;
    SRV_FMGR_DRVLIST_HANDLE drv_list;
    /* if we turn list auto gen ON, we need to regen the list */
    U8 repeat_mode = 0;
    U8 random_mode = 0;
    MMI_BOOL repeat_mode_changed = MMI_FALSE;
    MMI_BOOL random_mode_changed = MMI_FALSE;
#endif
#if 0//def __MMI_AUDPLY_WALK_PLAY__
/* under construction !*/
#endif  //__MMI_AUDPLY_WALK_PLAY__
#ifndef __MMI_AUDIO_PLAYER_SKIN_SLIM__
    U8 skin = 0;
    MMI_BOOL skin_changed = MMI_FALSE;
#endif
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
    U8 list_auto_gen = 0;
    U8 preferred_list = 0;
    U8 old_present_list = g_audply.present_list;
#endif  /* __MMI_AUDIO_PLAYER_SINGLE_LIST__ */

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    U8 spectrum_style = 0;
    MMI_BOOL style_changed;
#endif
#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
    U8 lyrics_style = 0;
    MMI_BOOL lyrics_changed;
#endif
#if (!defined(__MMI_AUDIO_PLAYER_ON_SUBLCD__) && !(defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__) ||defined(__MMI_VUI_LAUNCHER_KEY__)))
    U8 background_play = 0;
#endif

#ifdef __MMI_AUDIO_BASS_ENHANCEMENT__
    U8 bass_enhancement = 0;
#endif
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
#if !defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__)
    cui_inline_get_value(inline_gid, ITEM_REPEAT_ITEM, &repeat_mode);
    repeat_mode_changed = (MMI_BOOL)(repeat_mode != g_audply.repeat_mode);
    cui_inline_get_value(inline_gid, ITEM_SHUFFLE_ITEM, &random_mode);
    /* if we turn list auto gen ON, we need to regen the list */
    random_mode_changed = (MMI_BOOL)(random_mode != g_audply.random_mode);
#endif  //!defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__)
#endif

#ifndef __MMI_AUDIO_PLAYER_SKIN_SLIM__    
    cui_inline_get_value(inline_gid, ITEM_SKIN_ITEM, &skin);
    skin_changed = (MMI_BOOL)(skin != g_audply.skin);
#endif

#if 0//def __MMI_AUDPLY_WALK_PLAY__
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
#endif  //__MMI_AUDPLY_WALK_PLAY__

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    cui_inline_get_value(inline_gid, ITEM_SPECTRUM_ITEM, &spectrum_style);
    style_changed = (MMI_BOOL)(spectrum_style != g_audply.spectrum_style) ;
#endif

#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
    cui_inline_get_value(inline_gid, ITEM_LYRICS_ITEM, &lyrics_style);
    lyrics_changed = (MMI_BOOL)(lyrics_style != g_audply.lyrics_display) ;
#endif

    /* check format and apply change begore apply speed */
#ifdef __MMI_AUDIO_TIME_STRETCH__
    cui_inline_get_value(inline_gid, ITEM_PLAY_SPEED_ITEM, &selected_speed_index);
    if (!mmi_audply_apply_change_in_setting((U16) selected_speed_index))
    {
        mmi_popup_display_simple((WCHAR*)GetString(STR_ID_AUDPLY_UNSUPPORTED_SPEED), 
                                 MMI_EVENT_FAILURE, 
                                 GRP_ID_ROOT, 
                                 NULL);
        g_flag_memory_card_not_present = 1;
        return;
    }
#endif /* __MMI_AUDIO_TIME_STRETCH__ */ 

#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__) && !defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__)
#ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
    cui_inline_get_value(inline_gid, ITEM_AUTO_GEN_ITEM, &list_auto_gen);
#endif
    cui_inline_get_value(inline_gid, ITEM_PREFER_LIST_ITEM, &preferred_list);
    need_refresh_list = (MMI_BOOL)(list_auto_gen && (g_audply.list_auto_gen != list_auto_gen));
    /* apply it */
    g_audply.list_auto_gen = (U8)list_auto_gen;

	drv_list = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ALL);
    driveletter = srv_fmgr_drivelist_get_drv_letter(drv_list, preferred_list);
    srv_fmgr_drivelist_destroy(drv_list);
    if(driveletter != g_audply.preferred_list)
		{
    result = FS_GetDevStatus(driveletter, FS_MOUNT_STATE_ENUM);
    if (result < FS_NO_ERROR)
    {
//revise FS_DRIVE_NOT_FOUND to global string STR_GLOBAL_INSERT_MEMORY_CARD for UE syncronized with other app like SoundRec
//This is caused by Filemanager String Slim side effect
        mmi_popup_display_simple((WCHAR*)(get_string(STR_GLOBAL_INSERT_MEMORY_CARD)), MMI_EVENT_ERROR, GRP_ID_ROOT, NULL);
		g_flag_memory_card_not_present = 1;
            return;
        }
	   }
    g_audply.preferred_list = driveletter;
#endif  /* defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__) && !defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__) */
    
#if !defined(__MMI_AUDIO_PLAYER_SKIN_SLIM__) && !defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__)
    g_audply.skin = (U8)skin;
#endif  //!defined(__MMI_AUDIO_PLAYER_SKIN_SLIM__) && !defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__)
    g_audply.repeat_mode = (U8)repeat_mode;
    g_audply.random_mode = (U8)random_mode;
#if (!defined(__MMI_AUDIO_PLAYER_ON_SUBLCD__) && !(defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__)||defined(__MMI_VUI_LAUNCHER_KEY__)))
    cui_inline_get_value(inline_gid, ITEM_BG_PLAY_ITEM, &background_play);
    g_audply.background_play = (U8)background_play;
	#ifdef __MMI_BTD_BOX_UI_STYLE__
    if (!g_audply.background_play)
    {
       mmi_audply_stop_playing();
    }
#endif
#endif

#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
    if (g_settings_selected_audio_effect != g_settings_current_audio_effect || 
        g_settings_current_audio_effect == SETTINGS_SOUND_EFFECTS_NONE)
    {
        mmi_settings_turn_off_audio_effect();
    }

    switch (g_settings_current_audio_effect)
    {
    #ifdef __MMI_AUDIO_EQUALIZER__
        case SETTINGS_SOUND_EFFECTS_EQ :
            mmi_settings_audio_eq_apply((S16)current_audio_equalizer_index);
            g_settings_selected_audio_effect = g_settings_current_audio_effect;
            break;
    #endif
    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        case SETTINGS_SOUND_EFFECTS_REVERB :
            mmi_settings_audio_reverb_apply(current_audio_reverb_index);
            g_settings_selected_audio_effect = g_settings_current_audio_effect;            
            break;
    #endif
    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        case SETTINGS_SOUND_EFFECTS_SURROUND :
            mmi_settings_audio_surround_apply(current_audio_surround_index);
            g_settings_selected_audio_effect = g_settings_current_audio_effect;            
            break;
    #endif
        default :
			g_settings_selected_audio_effect = g_settings_current_audio_effect;            
            break;
    }
    mmi_settings_audio_effect_write_nvram();
#endif /* __MMI_AUDIO_EQUALIZER__ || __MMI_AUDIO_REVERB_EFFECT__ || __MMI_AUDIO_SURROUND_EFFECT__ */
#ifdef __MMI_AUDIO_BASS_ENHANCEMENT__
    cui_inline_get_value(inline_gid, ITEM_BASS_ITEM, &bass_enhancement);
    if(g_settings_bass_enhancement != bass_enhancement)
    {
        mmi_settings_bass_enhancement_apply(bass_enhancement);
    }
#endif

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__ 
    if (mmi_audply_is_spectrum_valid())
    {
        g_audply.spectrum_style = (U8)spectrum_style;

        if (style_changed && g_audply.state == STATE_PLAY)
        {
        }
    }
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */

#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
    if (mmi_audply_is_lyrics_valid())
    {
        g_audply.lyrics_display = (U8)lyrics_style;
    }
#endif

    /* save to nvram */
    mmi_audply_write_settings();

#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
    /* update present list */
    g_audply.present_list = mmi_audply_get_current_list_drv();

    if(g_audply.present_list != old_present_list)
    {
        need_reload_list = MMI_TRUE;
         g_audply.duration = 0;
    }

    /* if the present list is changed and list auto gen is ON, we need to regen the list */
    #ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
    if (g_audply.list_auto_gen && need_reload_list)
    {
        need_refresh_list = MMI_TRUE;
    }
    #endif
    if (need_refresh_list)
    {
        need_reload_list = MMI_TRUE;
    }

    if (!need_reload_list &&
        (repeat_mode_changed || random_mode_changed) &&
        mmi_audply_playlist_get_current_index() >= 0)
    {
        S32 index = mmi_audply_playlist_get_current_index();
        mmi_audply_playlist_set_start(index);
        mmi_audply_playlist_set_pick_index(index);
    }
#endif  /* __MMI_AUDIO_PLAYER_SINGLE_LIST__ */
    /* go back */
    settings_done_back_to_main = MMI_FALSE;    
#ifndef __MMI_AUDIO_PLAYER_SKIN_SLIM__    
    if (skin_changed)
    {
        settings_done_back_to_main = MMI_TRUE;
    }
#endif

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    if (mmi_audply_is_spectrum_valid() && style_changed)
    {
        settings_done_back_to_main = MMI_TRUE;
    }
#endif    

#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
    if (mmi_audply_is_lyrics_valid() && lyrics_changed)
    {
        settings_done_back_to_main = MMI_TRUE;
    }        
#endif 

#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
    if (settings_done_back_to_main)
    {
		mmi_frm_group_close(GRP_ID_AUDPLY_SETTINGS);
		mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);
		mmi_frm_group_close(GRP_ID_AUDPLY_LIST_BROWSER);

    }
    else
    {
		mmi_frm_group_close(GRP_ID_AUDPLY_SETTINGS);

    }
#elif defined(__MMI_AUDPLY_MULTIPLE_LIST__)
    {
		mmi_frm_group_close(GRP_ID_AUDPLY_SETTINGS);
    }
#endif

}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_entry_two_layers_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_entry_two_layers_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    //MMI_ID cui_gid = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUDPLY_SETTINGS, mmi_audply_settings_group_proc, (void*)NULL); 
    //mmi_frm_group_enter(GRP_ID_AUDPLY_SETTINGS, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_group_create_ex(
        GRP_ID_ROOT, 
        GRP_ID_AUDPLY_SETTINGS, 
        mmi_audply_settings_group_proc, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    //cui_gid = cui_menu_create(GRP_ID_AUDPLY_SETTINGS,
    //                          CUI_MENU_SRC_TYPE_RESOURCE,
    //                          CUI_MENU_TYPE_APPSUB,
    //                          MENU_ID_AUDPLY_SETTINGS_LIST,
    //                          MMI_TRUE, 
    //                          NULL);
    //cui_menu_set_default_title_by_id(cui_gid,(STR_GLOBAL_SETTINGS),(GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID)));
    //cui_menu_run(cui_gid);

    cui_menu_create_and_run(
        GRP_ID_AUDPLY_SETTINGS, 
        CUI_MENU_SRC_TYPE_RESOURCE, 
        CUI_MENU_TYPE_APPSUB, 
        MENU_ID_AUDPLY_SETTINGS_LIST, 
        MMI_TRUE, 
        NULL);
}
#ifndef __MMI_AUDPLY_SINGLE_LAYER_SETTING__


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_two_layer_settings_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_two_layer_settings_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
    SRV_FMGR_DRVLIST_HANDLE drv_list;
#endif    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
    selected_list_auto_gen = g_audply.list_auto_gen;
    drv_list = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ALL);
    selected_preferred_list = srv_fmgr_drivelist_get_index_by_drv_letter(drv_list, g_audply.preferred_list);
    srv_fmgr_drivelist_destroy(drv_list);
#endif  /* __MMI_AUDIO_PLAYER_SINGLE_LIST__ */

    selected_repeat_mode = g_audply.repeat_mode;
    selected_random_mode = g_audply.random_mode;

#if (!defined(__MMI_AUDIO_PLAYER_ON_SUBLCD__) && !(defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__)|| defined(__MMI_VUI_LAUNCHER_KEY__)))  
    selected_background_play = g_audply.background_play;
#endif

#ifndef __MMI_AUDIO_PLAYER_SKIN_SLIM__    
    selected_skin = g_audply.skin;
#endif

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__  
    selected_spectrum_style = g_audply.spectrum_style;
#endif 

#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
    selected_lyrics_style = g_audply.lyrics_display;
#endif

#ifdef __MMI_AUDIO_TIME_STRETCH__
    selected_speed_index = (S32)mmi_audply_speed_get_index(g_audply.speed);
#endif 

    switch (g_mmi_audply_two_layer_settings_highlighted_item)
    {
        case MENU_ID_AUDPLY_PLAYER_SETTING: /* Player Setting*/
            mmi_audply_entry_player_settings();
            break;
            
        #if !defined(__MMI_AUDIO_PLAYER_SKIN_SLIM__) || defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) || defined(__MMI_AUDIO_SPECTRUM_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)   
        case MENU_ID_AUDPLY_DISPLAY_SETTING: /* Display Setting */
            mmi_audply_entry_display_settings();
            break;
        #endif
    
#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_TIME_STRETCH__) || \
    (defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__) || defined(__MMI_AUDIO_BASS_ENHANCEMENT__))
        case MENU_ID_AUDPLY_SOUND_EFFECT_SETTING:
            mmi_audply_entry_sound_effect_settings();
            break;
    #endif
        
        #if defined(__MMI_A2DP_SUPPORT__) && !defined(__MMI_A2DP_HIDE_BT_SETTINGS__)
        case MENU_ID_AUDPLY_BT_SETTING: /* Bluetooth Setting */
            mmi_a2dp_entry_bluetooth_settings();
            break;
        #endif
    
        default:
            return;
    }
}
#endif
#endif /* __MMI_AUDIO_PLAYER__ */

