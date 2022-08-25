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
* SoundEffect.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   This file is the header file of sound effect setup.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef _SOUND_EFFECT_H_
#define _SOUND_EFFECT_H_

#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gui_data_types.h"
#include "nvram_default_audio.h"

#define MAX_EQUALIZER_NUM  8    /* double check if NVRAM_EF_AUDIO_EQUALIZER_COUNT == MAX_EQUALIZER_NUM */
#define NUM_OF_BARS_IN_A_SETTING  8
#define NUM_OF_BARS_IN_A_SETTING_NVRAM NVRAM_EF_AUDIO_EQUALIZER_BAND_NUM
#define UPPER_LIMIT_SOUND_LEVEL   255
#define LOWER_LIMIT_SOUND_LEVEL   0
#define EQ_TOTAL_LEVELS           256
#define SETTING_NAME_MAX_LEN      23


#define RENAME_BIT_TEST(b, a)        (( (b) & (0x1 << (a))) >> (a))
#define RENAME_BIT_ON(b, a)            ( (b) |= (0x1 << (a)))

typedef enum
{
    SETTINGS_SOUND_EFFECTS_INLINE_LEVEL_1,
    SETTINGS_SOUND_EFFECTS_INLINE_LEVEL_2,
    NO_OF_SETTINGS_SOUND_EFFECTS_INLINE_LEVELS
}AUDIO_SOUND_EFFECTS_LEVEL_ENUM;

typedef enum
{
    SETTINGS_SOUND_EFFECTS_NONE,
#ifdef __MMI_AUDIO_EQUALIZER__
    SETTINGS_SOUND_EFFECTS_EQ,
#endif
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    SETTINGS_SOUND_EFFECTS_REVERB,
#endif
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    SETTINGS_SOUND_EFFECTS_SURROUND,
#endif
    NO_OF_SETTINGS_SOUND_EFFECTS
}AUDIO_SOUND_EFFECTS_ENUM;

typedef enum
{
    MMI_SETTINGS_TRACK_EFFECTS_NONE,
#ifdef __MMI_AUDIO_VOCAL_REMOVAL__ 
    MMI_SETTINGS_TRACK_EFFECTS_VOCAL_REMOVAL,
#endif
#ifdef __MMI_AUDIO_PITCH_SHIFTING__
    MMI_SETTINGS_TRACK_EFFECTS_PITCH_SHIFTING,
#endif
    MMI_SETTINGS_TRACK_EFFECTS_TOTAL
}MMI_SETTINGS_TRACK_EFFECTS_ENUM;

#ifdef __MMI_AUDIO_VOCAL_REMOVAL__ 
typedef enum
{
    MMI_SETTINGS_VOCAL_REMOVAL_ON,
    MMI_SETTINGS_VOCAL_REMOVAL_OFF,
    MMI_SETTINGS_VOCAL_REMOVAL_TOTAL
}MMI_SETTINGS_VOCAL_REMOVAL_ENUM;
#endif

#ifdef __MMI_AUDIO_PITCH_SHIFTING__
typedef enum
{
    MMI_SETTINGS_PITCH_SHIFTING_N4 = -4,
    MMI_SETTINGS_PITCH_SHIFTING_N3,
    MMI_SETTINGS_PITCH_SHIFTING_N2,
    MMI_SETTINGS_PITCH_SHIFTING_N1,
    MMI_SETTINGS_PITCH_SHIFTING_0,
    MMI_SETTINGS_PITCH_SHIFTING_P1,
    MMI_SETTINGS_PITCH_SHIFTING_P2,
    MMI_SETTINGS_PITCH_SHIFTING_P3,
    MMI_SETTINGS_PITCH_SHIFTING_P4,
    MMI_SETTINGS_PITCH_SHIFTING_END_OF_ENUM
}MMI_SETTINGS_PITCH_SHIFTING_ENUM;
#endif

typedef enum
{
    AUDIO_MIC_IN_CALL,
    AUDIO_MIC_APP,
    AUDIO_MIC_SET_NUM
} AUDIO_MIC_SET_ENUM;

typedef enum
{
    MMI_SETTINGS_SE_POPUP_GROUP_END_AUDIO,
    MMI_SETTINGS_SE_POPUP_GROUP_END_BASS,    
    MMI_SETTINGS_SE_POPUP_NORMAL,
    MMI_SETTINGS_SE_POPUP_EQ_OPTIONS_EDIT,
    MMI_SETTINGS_SE_POPUP_EQ_RENAME_SUCCESS,
    MMI_SETTINGS_SE_POPUP_EQ_RENAME_INVALID,
    MMI_SETTINGS_SE_COMFIRM_EQ_RESTORE,
    MMI_SETTINGS_SE_END_OF_ENUM
}MMI_SETTING_SE_POPUP_ENUM;

#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
typedef struct
{
    S16 sound_level[NUM_OF_BARS_IN_A_SETTING];
    U8 active_bar;
} equalizer_setting_info;
#endif /* __MMI_EDITABLE_AUDIO_EQUALIZER__ */ 

typedef struct
{
    unsigned char levels[AUDIO_MIC_SET_NUM];
    MMI_BOOL is_init;
} audio_mic_volume_struct;


typedef struct
{
#ifdef __MMI_SOUND_EFFECT__
    MMI_ID sound_menu_gid;
    MMI_SETTING_SE_POPUP_ENUM pop_up_type;
#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
    MMI_ID audio_inline_gid;
#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
    MMI_ID eq_opt_menu_gid;
    MMI_ID eq_editor_gid;
    MMI_BOOL eq_setting_modified;
#endif /*__MMI_EDITABLE_AUDIO_EQUALIZER__*/
#endif /*defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)*/
#ifdef __MMI_AUDIO_BASS_ENHANCEMENT__
    MMI_ID bass_inline_gid;
#endif /*__MMI_AUDIO_BASS_ENHANCEMENT__*/
#endif /*__MMI_SOUND_EFFECT__*/
#if defined(__MMI_AUDIO_VOCAL_REMOVAL__) || defined(__MMI_AUDIO_PITCH_SHIFTING__)
    MMI_SETTINGS_TRACK_EFFECTS_ENUM selected_track_effect;
#endif /*defined(__MMI_AUDIO_VOCAL_REMOVAL__) || defined(__MMI_AUDIO_PITCH_SHIFTING__)*/
    audio_mic_volume_struct audio_mic_volume;

}sound_effect_cntx_struct;


typedef struct
{
    S16 count;
    S16 index;
    signed char magnitude[MAX_EQUALIZER_NUM][NUM_OF_BARS_IN_A_SETTING];
    unsigned char setting_name[MAX_EQUALIZER_NUM][(SETTING_NAME_MAX_LEN + 1) *ENCODING_LENGTH];
} audio_equalizer_struct;

typedef struct
{
    S16 count;
    S16 index;
    signed char magnitude[MAX_EQUALIZER_NUM][NUM_OF_BARS_IN_A_SETTING_NVRAM];
    unsigned char setting_name[MAX_EQUALIZER_NUM][(SETTING_NAME_MAX_LEN + 1) *ENCODING_LENGTH];
} audio_equalizer_band_struct;


extern audio_equalizer_struct g_settings_audio_equalizer;

extern void InitSoundEffect(void);
extern void mmi_settings_sound_effect_highlight_hdlr(void);

#ifdef __MMI_AUDIO_BASS_ENHANCEMENT__

typedef enum
{
    __BES_BASS_SUPPORT___OFF,
    __BES_BASS_SUPPORT___ON,
    __BES_BASS_SUPPORT___TOTAL
} audio_bass_enhancement_enum;

extern UI_string_type g_settings_bass_enhancement_inline[2];
extern S32 g_settings_bass_enhancement;
extern S32 g_settings_selected_bass_enhancement;

extern void mmi_settings_bass_enhancement_highlight_hdlr(void);
extern MMI_BOOL mmi_settings_bass_enhancement_apply(U16 index);
#endif /*__MMI_AUDIO_BASS_ENHANCEMENT__*/

#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)

extern UI_string_type g_settings_audio_effects_inline1[NO_OF_SETTINGS_SOUND_EFFECTS];
extern UI_string_type g_settings_audio_effects_inline2[MAX_EQUALIZER_NUM];
extern S32 g_settings_selected_audio_effect;
extern S32 g_settings_current_effect_index;
extern S32 g_settings_current_audio_effect_prev;
extern S32 g_settings_current_audio_effect;
extern U16 current_audio_equalizer_index;
extern U16 current_audio_reverb_index;
extern U16 current_audio_surround_index;

extern void mmi_settings_turn_off_audio_effect(void);
extern void mmi_settings_audio_effect_write_nvram(void);
#endif

#ifdef __MMI_AUDIO_EQUALIZER__
extern void mmi_settings_audio_eq_write_to_nvram(void);
extern BOOL mmi_settings_audio_eq_apply(S16 index);
extern void mmi_settings_audio_eq_rename_by_language(void);

#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
extern U16 g_settings_eq_rename_flag;
extern void mmi_settings_audio_equalizer_restore_factory_default(void);
extern void mmi_settings_audio_equalizer_opt_edit_highlight_hdlr(void);
extern void mmi_settings_audio_equalizer_opt_rename_highlight_hdlr(void);
extern void mmi_settings_audio_equalizer_opt_reset_highlight_hdlr(void);

/* select functions */
extern void mmi_settings_audio_equalizer_setting_select(void);

/* editing functions */
extern void mmi_settings_entry_audio_equalizer_setting_edit(MMI_ID parent_id);

/* renaming functions */
extern void mmi_settings_entry_audio_equalizer_setting_rename(MMI_ID parent_id);

#endif /* __MMI_EDITABLE_AUDIO_EQUALIZER__ */ 
#endif /* __MMI_AUDIO_EQUALIZER__ */

#if defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)

typedef struct
{
    U16 reverb_index;
    U16 surround_index;    
} audio_3d_effect_struct;

extern audio_3d_effect_struct g_mmi_aud_3d_cntx;

#ifdef __MMI_AUDIO_REVERB_EFFECT__

#define MAX_AUDIO_REVERB_EFFECT_NUM  6

//extern void mmi_settings_audio_reverb_init(void);
extern BOOL mmi_settings_audio_reverb_apply(U16 index);
extern MMI_BOOL mmi_settings_audio_reverb_get_status(void);
#endif /*__MMI_AUDIO_REVERB_EFFECT__*/


#ifdef __MMI_AUDIO_SURROUND_EFFECT__

typedef enum
{
    AUD_SURROUND_MODE1,
    AUD_SURROUND_MODE2,
    AUD_SURROUND_TOTAL
} audio_surround_mode_enum;

extern BOOL mmi_settings_audio_surround_apply(U16 mode);
#endif /*__MMI_AUDIO_SURROUND_EFFECT__*/

#endif /*__MMI_AUDIO_REVERB_EFFECT__ || __MMI_AUDIO_SURROUND_EFFECT__*/

#endif /* _SOUND_EFFECT_H_ */ 

extern void mmi_settings_turn_off_sound_effects(void);
extern void mmi_settings_turn_on_sound_effects(void);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0

