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
* SoundEffect.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   This file is intends to setup sound effect.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
//#include "MMI_include.h"

//#include "SettingDefs.h"
//#include "SettingsGdcl.h"
//#include "settingstructs.h"
//#include "settinggprots.h"
//#include "ProtocolEvents.h"
#include "CommonScreens.h"
//#include "SettingProt.h"
//#include "SettingProfile.h"
#include "SoundEffect.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#if defined(__MMI_AUDIO_EQUALIZER__)
//#include "UserProfilesResDef.h"
#endif
#include "RestoreGprot.h"
#include "custom_nvram_config.h"

#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
//#include "nvram_default_audio.h"
#include "Nvram_interface.h"
#endif


#include "InlineCuiGProt.h"
#include "MenuCuiGProt.h"
#include "FsEditorCuiGProt.h"

#include "MMI_features.h"
#include "gui_data_types.h"
#include "MMIDataType.h"
#include "wgui_categories_multimedia.h"
#include "GlobalResDef.h"
#ifdef __MMI_SOUND_EFFECT__
#include "mmi_rp_app_soundeffect_def.h"
#endif
#include "mmi_frm_scenario_gprot.h"
#include "CommonScreensResDef.h"
#include "AlertScreen.h"
#include "kal_general_types.h"
#include "CustDataRes.h"
#include "wgui_categories_util.h"
#include "GlobalConstants.h"
#include "mmi_frm_history_gprot.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "mmi_frm_events_gprot.h"
#include "gui_typedef.h"
#include "MMI_media_app_trc.h"
#include "mmi_media_app_trc.h"
#include "kal_trace.h"
#include "nvram_common_defs.h"
#include "Unicodexdcl.h"
#include "string.h"
#include "mmi_rp_app_uiframework_def.h"
#include "mmi_frm_input_gprot.h"
#include "ImeGprot.h"

/*************************************************************************************
 * Global Context Define
 *************************************************************************************/

sound_effect_cntx_struct g_settings_sound;

static BOOL g_sound_effect_init_ok;//mtk28101 add

#ifdef __MMI_SOUND_EFFECT__

#ifdef __MMI_AUDIO_BASS_ENHANCEMENT__
UI_string_type g_settings_bass_enhancement_inline[2];
S32 g_settings_bass_enhancement;
S32 g_settings_selected_bass_enhancement;
#endif

#if defined(__MMI_AUDIO_EQUALIZER__) ||  defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
S32 g_settings_selected_audio_effect; /* indicate which audio effect to apply */
S32 g_settings_current_audio_effect; /* when user choose back option, the _current_ variables can be used to reset */
S32 g_settings_current_audio_effect_prev;
S32 g_settings_current_effect_index;
UI_string_type g_settings_audio_effects_inline1[NO_OF_SETTINGS_SOUND_EFFECTS];
UI_string_type g_settings_audio_effects_inline2[MAX_EQUALIZER_NUM]; /*use MAX_EQUALIZER_NUM since currently it is the largest one*/
#endif

#if defined(__MMI_AUDIO_EQUALIZER__)
audio_equalizer_struct g_settings_audio_equalizer;
static audio_equalizer_band_struct g_settings_audio_equalizer_band;
U16 current_audio_equalizer_index;

#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
U16 g_settings_eq_rename_flag ;
wgui_cat334_info_struct g_audio_equalizer_current_setting_info; /* to store the values of currently accessed equalizer setting */
S16 temp_level[NUM_OF_BARS_IN_A_SETTING];
#endif /* __MMI_EDITABLE_AUDIO_EQUALIZER__ */ 
#endif /* __MMI_AUDIO_EQUALIZER__ */ 

#if defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
audio_3d_effect_struct g_mmi_aud_3d_cntx;

#ifdef __MMI_AUDIO_REVERB_EFFECT__
U16 current_audio_reverb_index;
#endif

#ifdef __MMI_AUDIO_SURROUND_EFFECT__
U16 current_audio_surround_index;
#endif
#endif /* __MMI_AUDIO_REVERB_EFFECT__ || __MMI_AUDIO_SURROUND_EFFECT__*/
#endif /* __MMI_SOUND_EFFECT__ */ 



/*************************************************************************************
 * Inline Structure Define
 *************************************************************************************/

#define MMI_SETTINGS_BASS_ENHANCEMENT_SELECT       (CUI_INLINE_ITEM_ID_BASE)
#define MMI_SETTINGS_AUDIO_EFFECT_LEVEL_1          (CUI_INLINE_ITEM_ID_BASE + 1)
#define MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_EMPTY    (CUI_INLINE_ITEM_ID_BASE + 2)
#define MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_SELECT   (CUI_INLINE_ITEM_ID_BASE + 3)

#define BASS_ENHANCEMENT_INLINE_DEFINE
#ifdef __MMI_AUDIO_BASS_ENHANCEMENT__

static const U16 g_settings_bass_enhancement_select_str[] = 
{
    STR_GLOBAL_OFF,
    STR_GLOBAL_ON
};

const cui_inline_item_select_struct g_settings_bass_enhancement_select = 
{
    2, 0, (U16 *)g_settings_bass_enhancement_select_str
};

static const cui_inline_set_item_struct g_settings_bass_enhancement_inline_item[1] =
{
    {MMI_SETTINGS_BASS_ENHANCEMENT_SELECT,    CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,     0,  (void*)&g_settings_bass_enhancement_select},
};

static const cui_inline_struct g_settings_bass_enhancement_inline_screen = 
{
    1,
    STR_ID_SETTING_BASS_ENHANCEMENT,
    0,
    CUI_INLINE_SCREEN_DISABLE_DONE | CUI_INLINE_SCREEN_DEFAULT_TEXT,
    0,
    g_settings_bass_enhancement_inline_item
};
#endif


#define AUDIO_EFFECT_INLINE_DEFINE
#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)

static const U16 g_settings_audio_effect_level1_select_str[] = 
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

const cui_inline_item_select_struct g_settings_audio_effect_level1_select = 
{
#ifdef __MMI_AUDIO_EQUALIZER__
    1+
#endif
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    1+
#endif
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    1+
#endif
    1, 0, (U16 *)g_settings_audio_effect_level1_select_str
};


#ifdef __MMI_AUDIO_EQUALIZER__

static const U16 g_settings_audio_eq_select_str[] = 
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

const cui_inline_item_select_struct g_settings_audio_effect_level2_eq_select = 
{
    MAX_EQUALIZER_NUM, 0, (U16 *)g_settings_audio_eq_select_str
};

const cui_inline_set_item_struct g_settings_audio_effect_level2_eq =
{
    MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_SELECT,
    CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,
    0,
    (void*)&g_settings_audio_effect_level2_eq_select
};
#endif /*defined(__MMI_AUDIO_EQUALIZER__)*/

#ifdef __MMI_AUDIO_REVERB_EFFECT__

static const U16 g_settings_audio_reverb_select_str[] = 
{
    STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET1,
    STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET2,
    STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET3,
    STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET4,
    STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET5,
    STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET6
};

const cui_inline_item_select_struct g_settings_audio_effect_level2_reverb_select = 
{
    MAX_AUDIO_REVERB_EFFECT_NUM, 0, (U16 *)g_settings_audio_reverb_select_str
};

const cui_inline_set_item_struct g_settings_audio_effect_level2_reverb =
{
    MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_SELECT,
    CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,
    0,
    (void*)&g_settings_audio_effect_level2_reverb_select
};
#endif /* __MMI_AUDIO_REVERB_EFFECT__ */ 

#ifdef __MMI_AUDIO_SURROUND_EFFECT__

static const U16 g_settings_audio_surround_select_str[] = 
{
    STR_ID_SETTING_AUDIO_SURROUND_MODE1,
    STR_ID_SETTING_AUDIO_SURROUND_MODE2,
};

const cui_inline_item_select_struct g_settings_audio_effect_level2_surround_select = 
{
    AUD_SURROUND_TOTAL, 0, (U16 *)g_settings_audio_surround_select_str
};

const cui_inline_set_item_struct g_settings_audio_effect_level2_surround =
{
    MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_SELECT,
    CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,
    0,
    (void*)&g_settings_audio_effect_level2_surround_select
};
#endif /* __MMI_AUDIO_SURROUND_EFFECT__ */

static const cui_inline_item_display_only_struct g_settings_audio_effect_level2_empty_display =
{
    STR_GLOBAL_EMPTY
};

const cui_inline_set_item_struct g_settings_audio_effect_level2_empty =
{
    MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_EMPTY,
    CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_DISABLE | CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW,
    0,
    (void*)&g_settings_audio_effect_level2_empty_display
};

static const cui_inline_set_item_struct g_settings_audio_effect_inline_item[2] =
{
    {MMI_SETTINGS_AUDIO_EFFECT_LEVEL_1,    CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,     0,  (void*)&g_settings_audio_effect_level1_select},
    {MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_EMPTY,    CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_DISABLE | CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW,     0,  (void*)&g_settings_audio_effect_level2_empty_display},
};

static const cui_inline_struct g_settings_audio_effect_inline_screen = 
{
    2,
    STR_ID_SETTING_AUDIO_EFFECT,
    0,
    CUI_INLINE_SCREEN_DISABLE_DONE,
    0,
    g_settings_audio_effect_inline_item
};
#endif


/*************************************************************************************
 * Static / Extern Functions
 *************************************************************************************/

#if defined(__MMI_AUDIO_EQUALIZER__) ||  defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
static void mmi_settings_entry_audio_effect_group(void);
static void mmi_settings_audio_effect_init(void);
static void mmi_settings_audio_effect_switch_level_1(S32 index);
static void mmi_settings_audio_effect_switch_level_2(S32 index);
static void mmi_settings_audio_effect_settings_done(void);

#if defined(__MMI_AUDIO_EQUALIZER__) 
static void mmi_settings_audio_eq_init(void);
#endif /*__MMI_AUDIO_EQUALIZER__*/

#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
extern void mmi_aud_eq_init_image_specific_vals(void);
static void mmi_settings_audio_equalizer_restore_factory_default_confirm(void);
static void mmi_settings_entry_audio_equalizer_setting_options(void);
static void mmi_settings_audio_equalizer_restore_factory_default_ext(void);
#ifdef __MMI_TOUCH_SCREEN__
static void mmi_settings_audio_equalizer_change_sound_level(U8 bar, U16 level);
#endif /*__MMI_TOUCH_SCREEN__*/
#endif

#ifdef __MMI_AUDIO_REVERB_EFFECT__
static void mmi_settings_audio_reverb_init(void);
static void mmi_settings_audio_reverb_effect_init(U16 index);
#endif

#ifdef __MMI_AUDIO_SURROUND_EFFECT__
static void mmi_settings_audio_surround_init(void);
static void mmi_settings_audio_surround_effect_init(U16 index);
#endif

#endif /*defined(__MMI_AUDIO_EQUALIZER__) ||  defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)*/

#ifdef __MMI_AUDIO_BASS_ENHANCEMENT__
static void mmi_settings_bass_enhancement_done(void);
static void mmi_settings_entry_bass_enhancement(void);
static void mmi_settings_bass_enhancement_init(void);
#endif /*__MMI_AUDIO_BASS_ENHANCEMENT__*/

/*****************************************************************************
 * FUNCTION
 *  InitSoundEffect
 * DESCRIPTION
 *  This function is for initializing the Sound efeects application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitSoundEffect(void)
{
#ifdef __MMI_SOUND_EFFECT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
    /* Init Audio EQ Effect */
#ifdef __MMI_AUDIO_EQUALIZER__
    mmi_settings_audio_eq_init();
#endif

    /* Init Audio Reverb Effect */
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    mmi_settings_audio_reverb_init();
#endif 

    /* Init Audio Surround Effect */
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    mmi_settings_audio_surround_init();
#endif

    /* Init Audio Effect */
    g_settings_sound.audio_inline_gid = 0;
    mmi_settings_audio_effect_init();
#endif /*__MMI_AUDIO_EQUALIZER__ || __MMI_AUDIO_REVERB_EFFECT__ || __MMI_AUDIO_SURROUND_EFFECT__*/

#ifdef __MMI_AUDIO_BASS_ENHANCEMENT__
    g_settings_sound.bass_inline_gid = 0;
    mmi_settings_bass_enhancement_init();
#endif

#endif /* __MMI_SOUND_EFFECT__ */ 

#if defined(__MMI_AUDIO_VOCAL_REMOVAL__) || defined(__MMI_AUDIO_PITCH_SHIFTING__)
    g_settings_sound.selected_track_effect = MMI_SETTINGS_TRACK_EFFECTS_NONE;
#endif
	g_sound_effect_init_ok = TRUE;//mtk28101 add

}

#ifdef __MMI_SOUND_EFFECT__

/*****************************************************************************
 * FUNCTION
 *  mmi_ret mmi_settings_sound_effect_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 * mmi_event_struct*    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_settings_sound_effect_proc(mmi_event_struct* event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 


    switch(event->evt_id)
    {
    #ifdef __MMI_AUDIO_BASS_ENHANCEMENT__
        /*Bass Enhancement Inline Cui*/
        case EVT_ID_CUI_INLINE_NOTIFY:
        {
            //cui_event_inline_notify_struct *notify = (cui_event_inline_notify_struct *)event;
            break;
        }

        case EVT_ID_CUI_INLINE_CSK_PRESS:
        case EVT_ID_CUI_INLINE_SUBMIT:
        {
            cui_event_inline_submit_struct *submit = (cui_event_inline_submit_struct *)event;

            /* Bass Enhnacemnet */
            if(submit->sender_id == g_settings_sound.bass_inline_gid)
            {
                mmi_settings_bass_enhancement_done();
            }

            break;
        }
        
        case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_event_inline_abort_struct *abort = (cui_event_inline_abort_struct*)event;
            cui_inline_close(abort->sender_id);
            break;
        }
    #endif

        /* Sound Effect Menu Cui*/
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)event;
            switch(menu_evt->highlighted_menu_id)
            {
            #if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
                case MENU_SETTING_AUDIO_EFFECT:
                {
                    mmi_settings_entry_audio_effect_group();
                    break;
                }
            #endif
            #ifdef __MMI_AUDIO_BASS_ENHANCEMENT__                
                case MNEU_SETTING_BASS_ENHANCEMENT:
                {
                    mmi_settings_entry_bass_enhancement();
                    break;
                }
            #endif

                default:
                    break;
            }
            break;
        }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(g_settings_sound.sound_menu_gid);
            g_settings_sound.sound_menu_gid = 0 ;
            mmi_frm_group_close(GRP_ID_SETTING_SOUND_EFFECT);
            break;
        }

        /* Popup*/
        case EVT_ID_POPUP_QUIT:
        {
            mmi_event_popoupcallback_result_struct *popup = (mmi_event_popoupcallback_result_struct*)event;
            MMI_SETTING_SE_POPUP_ENUM* type = (MMI_SETTING_SE_POPUP_ENUM*)popup->user_tag;

            switch(*type)
            {
                case MMI_SETTINGS_SE_POPUP_GROUP_END_BASS:
                {
                #ifdef __MMI_AUDIO_BASS_ENHANCEMENT__
                    cui_inline_close(g_settings_sound.bass_inline_gid);
                    g_settings_sound.bass_inline_gid = 0;
                #endif
                    break;
                }
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
 *  mmi_settings_entry_sound_effect_list
 * DESCRIPTION
 *  This function is entry function for the sound effect list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_entry_sound_effect_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_settings_sound.sound_menu_gid = cui_menu_create(
                                        GRP_ID_SETTING_SOUND_EFFECT, 
                                        CUI_MENU_SRC_TYPE_RESOURCE, 
                                        CUI_MENU_TYPE_APPMAIN, 
                                        MENU_SETTING_SOUND_EFFECT, 
                                        MMI_FALSE, 
                                        NULL);

    cui_menu_set_default_title_image(g_settings_sound.sound_menu_gid, (UI_image_type)GetImage(GetRootTitleIcon(MENU_SETTING_SOUND_EFFECT)));

    cui_menu_run(g_settings_sound.sound_menu_gid);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_entry_sound_effect_group
 * DESCRIPTION
 *  This function is entry function for the sound effect list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_entry_sound_effect_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    if(mmi_frm_group_is_present(GRP_ID_SETTING_SOUND_EFFECT))
    {
        mmi_frm_group_close(GRP_ID_SETTING_SOUND_EFFECT);
    }

    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SETTING_SOUND_EFFECT, mmi_settings_sound_effect_proc, NULL);
    mmi_frm_group_enter(GRP_ID_SETTING_SOUND_EFFECT,0);

    mmi_settings_entry_sound_effect_list();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_sound_effect_highlight_hdlr
 * DESCRIPTION
 *  This function is highlight handler for the sound effect menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_sound_effect_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetLeftSoftkeyFunction(mmi_settings_entry_sound_effect_group, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_settings_entry_sound_effect_group, KEY_EVENT_UP);

}

#ifdef __MMI_AUDIO_BASS_ENHANCEMENT__

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_entry_bass_enhancement
 * DESCRIPTION
 *  This function is entry function for bass enhancement screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_entry_bass_enhancement(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_settings_sound.bass_inline_gid = cui_inline_create(GRP_ID_SETTING_SOUND_EFFECT, &g_settings_bass_enhancement_inline_screen);

    cui_inline_set_title_icon(g_settings_sound.bass_inline_gid, GetRootTitleIcon(MENU_SETTING_SOUND_EFFECT));
    cui_inline_set_value(g_settings_sound.bass_inline_gid, MMI_SETTINGS_BASS_ENHANCEMENT_SELECT, (void*)g_settings_bass_enhancement);
    
    cui_inline_run(g_settings_sound.bass_inline_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_bass_enhancement_write_nvram
 * DESCRIPTION
 *  This function is to write bass enhancement settings back to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_bass_enhancement_write_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 write_value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_settings_bass_enhancement < __BES_BASS_SUPPORT___TOTAL)
    {
        write_value = (U8)g_settings_bass_enhancement;
    }
    else
    {
        MMI_ASSERT(FALSE);
    }
    WriteValue(NVRAM_BYTE_AUDIO_BASS_ENHANCEMENT_INDEX, &write_value, DS_BYTE, &error);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_bass_enhancement_read_nvram
 * DESCRIPTION
 *  This function is to read bass enhancement settings from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_bass_enhancement_read_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 read_value;
    U8 write_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_BYTE_AUDIO_BASS_ENHANCEMENT_INDEX, &read_value, DS_BYTE, &error);
    
    if (read_value < __BES_BASS_SUPPORT___TOTAL)
    {
        g_settings_bass_enhancement = read_value;
        return;
    }

    g_settings_bass_enhancement = __BES_BASS_SUPPORT___OFF;
    write_value = g_settings_bass_enhancement;
    WriteValue(NVRAM_BYTE_AUDIO_BASS_ENHANCEMENT_INDEX, &write_value, DS_BYTE, &error);
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_bass_enhancement_init
 * DESCRIPTION
 *  This function is to init bass enhancement
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_bass_enhancement_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result = MDI_AUDIO_SUCCESS;
    S16 error;
    U8 write_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_settings_bass_enhancement_read_nvram();

    switch(g_settings_bass_enhancement)
    {
        case __BES_BASS_SUPPORT___OFF:
        {
            mdi_audio_bass_enhance_turn_off();
            break;
        }

        case __BES_BASS_SUPPORT___ON:
        {
            result = mdi_audio_bass_enhance_turn_on();
            break;
        }

        default:
            break;
    }

    if(result != MDI_AUDIO_SUCCESS)
    {
        g_settings_bass_enhancement = __BES_BASS_SUPPORT___OFF;
        write_value = g_settings_bass_enhancement;
        WriteValue(NVRAM_BYTE_AUDIO_BASS_ENHANCEMENT_INDEX, &write_value, DS_BYTE, &error);        
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_reverb_apply
 * DESCRIPTION
 *  This function is to apply reverb effect
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_settings_bass_enhancement_apply(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result = MDI_AUDIO_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(index)
    {
        case __BES_BASS_SUPPORT___OFF:
        {
            g_settings_bass_enhancement = __BES_BASS_SUPPORT___OFF;
            result = mdi_audio_bass_enhance_turn_off();
            break;
        }

        case __BES_BASS_SUPPORT___ON:
        {
            g_settings_bass_enhancement = __BES_BASS_SUPPORT___ON;
            result = mdi_audio_bass_enhance_turn_on();
            break;
        }

        default:
            break;
    }

    if (result != MDI_AUDIO_SUCCESS)
    {
        g_settings_bass_enhancement = __BES_BASS_SUPPORT___OFF;
    }

    /* Write result back to NVRAM */
    mmi_settings_bass_enhancement_write_nvram();

    return (MMI_BOOL)result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_bass_enhancement_done
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_bass_enhancement_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result = MDI_AUDIO_SUCCESS; 
    U8 selected_value;
    mmi_popup_property_struct arg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cui_inline_get_value(g_settings_sound.bass_inline_gid, MMI_SETTINGS_BASS_ENHANCEMENT_SELECT, &selected_value);

    /*setting not change*/
    if(g_settings_bass_enhancement != selected_value)
    {
        result = mmi_settings_bass_enhancement_apply(selected_value);
    }

    if(result == MDI_AUDIO_SUCCESS )
    {
/*bql: apply new UE design to avoid success popup */
#if 1
        g_settings_sound.pop_up_type = MMI_SETTINGS_SE_POPUP_GROUP_END_BASS;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
        cui_inline_close(g_settings_sound.bass_inline_gid);
        g_settings_sound.bass_inline_gid = 0;
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    }
    else
    {
        g_settings_sound.pop_up_type = MMI_SETTINGS_SE_POPUP_GROUP_END_BASS;

        mmi_popup_property_init(&arg);
        arg.parent_id = GRP_ID_SETTING_SOUND_EFFECT;
        arg.user_tag = (void*)&g_settings_sound.pop_up_type;

        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, &arg);

    }
    
}

#endif /*__MMI_AUDIO_BASS_ENHANCEMENT__*/


#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_effect_switch_level_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_audio_effect_switch_level_1(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    if(index == g_settings_current_audio_effect)
    {
        return;
    }

    switch(index)
    {
        case SETTINGS_SOUND_EFFECTS_NONE:
        {
            cui_inline_insert_item(g_settings_sound.audio_inline_gid, MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_SELECT, (cui_inline_set_item_struct *)&g_settings_audio_effect_level2_empty);
            cui_inline_delete_item(g_settings_sound.audio_inline_gid, MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_SELECT);
            g_settings_current_audio_effect = index;
            break;
        }
            
    #ifdef __MMI_AUDIO_EQUALIZER__
        case SETTINGS_SOUND_EFFECTS_EQ:
        {
            for (i = 0; i < MAX_EQUALIZER_NUM; i++)
            {
            #ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
                g_settings_audio_effects_inline2[i] = (UI_string_type) g_settings_audio_equalizer.setting_name[i];
            #else 
                g_settings_audio_effects_inline2[i] = (UI_string_type) GetString(g_settings_audio_eq_select_str[i]);
            #endif
            }

            if(g_settings_current_audio_effect == SETTINGS_SOUND_EFFECTS_NONE)
            {
                cui_inline_insert_item(g_settings_sound.audio_inline_gid, MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_EMPTY, (cui_inline_set_item_struct *)&g_settings_audio_effect_level2_eq);
                cui_inline_delete_item(g_settings_sound.audio_inline_gid, MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_EMPTY);
            }

            cui_inline_set_item_select(
                g_settings_sound.audio_inline_gid,
                (U16)MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_SELECT,
                MAX_EQUALIZER_NUM,
                (PU8 *)g_settings_audio_effects_inline2,
                (U8)current_audio_equalizer_index);

            g_settings_current_effect_index = current_audio_equalizer_index ;
            g_settings_current_audio_effect = index;
            break;
        }
    #endif
    
    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        case SETTINGS_SOUND_EFFECTS_REVERB:
        {
            if(g_settings_current_audio_effect != SETTINGS_SOUND_EFFECTS_NONE)
            {
                for (i = 0; i < MAX_AUDIO_REVERB_EFFECT_NUM; i++)
                {
                    g_settings_audio_effects_inline2[i] = (UI_string_type) GetString(g_settings_audio_reverb_select_str[i]);
                }

                cui_inline_set_item_select(
                    g_settings_sound.audio_inline_gid,
                    (U16)MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_SELECT,
                    MAX_AUDIO_REVERB_EFFECT_NUM,
                    (PU8 *)g_settings_audio_effects_inline2,
                    (U8)current_audio_reverb_index);
            }
            else
            {
                cui_inline_insert_item(g_settings_sound.audio_inline_gid, MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_EMPTY, (cui_inline_set_item_struct *)&g_settings_audio_effect_level2_reverb);
                cui_inline_delete_item(g_settings_sound.audio_inline_gid, MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_EMPTY);
                cui_inline_set_value(g_settings_sound.audio_inline_gid, MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_SELECT, (void*)current_audio_reverb_index);
            }

            g_settings_current_effect_index = current_audio_reverb_index ;
            g_settings_current_audio_effect = index;
            break;
        }
    #endif

    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        case SETTINGS_SOUND_EFFECTS_SURROUND:
        {
            if(g_settings_current_audio_effect != SETTINGS_SOUND_EFFECTS_NONE)
            {
                for(i = 0 ; i < AUD_SURROUND_TOTAL ; i++)
                {
                    g_settings_audio_effects_inline2[i] = (UI_string_type) GetString(g_settings_audio_surround_select_str[i]);
                }

                cui_inline_set_item_select(
                    g_settings_sound.audio_inline_gid,
                    (U16)MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_SELECT,
                    AUD_SURROUND_TOTAL,
                    (PU8*) g_settings_audio_effects_inline2,
                    (U8)current_audio_surround_index);
            }
            else
            {
                cui_inline_insert_item(g_settings_sound.audio_inline_gid, MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_EMPTY, (cui_inline_set_item_struct *)&g_settings_audio_effect_level2_surround);
                cui_inline_delete_item(g_settings_sound.audio_inline_gid, MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_EMPTY);
                cui_inline_set_value(g_settings_sound.audio_inline_gid, MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_SELECT, (void*)current_audio_surround_index);
            }

            g_settings_current_effect_index = current_audio_surround_index ;
            g_settings_current_audio_effect = index;
            break;
        }
    #endif
    
        default:
            MMI_ASSERT(FALSE); /*shall not happen*/
            break;
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_effect_switch_level_2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_audio_effect_switch_level_2(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(g_settings_current_audio_effect)
    {
    #ifdef __MMI_AUDIO_EQUALIZER__
        case SETTINGS_SOUND_EFFECTS_EQ :
        {
            current_audio_equalizer_index = index; 
        #ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
            cui_inline_set_softkey_text(
                g_settings_sound.audio_inline_gid,
                MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_SELECT,
                MMI_LEFT_SOFTKEY,
                STR_GLOBAL_OPTIONS);
        #endif
            break;
        }
    #endif
    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        case SETTINGS_SOUND_EFFECTS_REVERB :
        {
            current_audio_reverb_index = index ;
        #ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
            cui_inline_set_softkey_text(
                g_settings_sound.audio_inline_gid,
                MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_SELECT,
                MMI_LEFT_SOFTKEY,
                STR_GLOBAL_OK);
        #endif
            break;
        }
    #endif
    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        case SETTINGS_SOUND_EFFECTS_SURROUND :
        {
            current_audio_surround_index = index ;
        #ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
            cui_inline_set_softkey_text(
                g_settings_sound.audio_inline_gid,
                MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_SELECT,
                MMI_LEFT_SOFTKEY,
                STR_GLOBAL_OK);
        #endif
            break;
        }
    #endif
        default :
            break;
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_entry_audio_effect
 * DESCRIPTION
 *  This function is entry function for the audio effect main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_entry_audio_effect(void)
{

    g_settings_sound.audio_inline_gid = cui_inline_create(GRP_ID_SETTING_AUDIO_EFFECT, &g_settings_audio_effect_inline_screen);

    cui_inline_set_title_icon(g_settings_sound.audio_inline_gid, GetRootTitleIcon(MENU_SETTING_SOUND_EFFECT));

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

    switch(g_settings_current_audio_effect)
    {
        case SETTINGS_SOUND_EFFECTS_NONE:
        {
            break;
        }
    #ifdef __MMI_AUDIO_EQUALIZER__
        case SETTINGS_SOUND_EFFECTS_EQ:
        {
            U16 i ;

            cui_inline_insert_item(g_settings_sound.audio_inline_gid, MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_EMPTY, (cui_inline_set_item_struct *)&g_settings_audio_effect_level2_eq);
            cui_inline_delete_item(g_settings_sound.audio_inline_gid, MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_EMPTY);
            cui_inline_set_value(g_settings_sound.audio_inline_gid, MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_SELECT, (void*)current_audio_equalizer_index);

            for (i = 0; i < MAX_EQUALIZER_NUM; i++)
            {
            #ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
                g_settings_audio_effects_inline2[i] = (UI_string_type) g_settings_audio_equalizer.setting_name[i];
            #else 
                g_settings_audio_effects_inline2[i] = (UI_string_type) GetString(g_settings_audio_eq_select_str[i]);
            #endif
            }

            cui_inline_set_item_select(
                g_settings_sound.audio_inline_gid,
                (U16)MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_SELECT,
                MAX_EQUALIZER_NUM,
                (PU8 *)g_settings_audio_effects_inline2,
                (U8)current_audio_equalizer_index);

            g_settings_current_effect_index = current_audio_equalizer_index;
            break;
        }
    #endif
    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        case SETTINGS_SOUND_EFFECTS_REVERB:
        {
            cui_inline_insert_item(g_settings_sound.audio_inline_gid, MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_EMPTY, (cui_inline_set_item_struct *)&g_settings_audio_effect_level2_reverb);
            cui_inline_delete_item(g_settings_sound.audio_inline_gid, MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_EMPTY);
            cui_inline_set_value(g_settings_sound.audio_inline_gid, MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_SELECT, (void*)current_audio_reverb_index);
            g_settings_current_effect_index = current_audio_reverb_index;
            break;
        }
    #endif
    #ifdef __MMI_AUDIO_SURROUND_EFFECT__    
        case SETTINGS_SOUND_EFFECTS_SURROUND:
        {
            cui_inline_insert_item(g_settings_sound.audio_inline_gid, MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_EMPTY, (cui_inline_set_item_struct *)&g_settings_audio_effect_level2_surround);
            cui_inline_delete_item(g_settings_sound.audio_inline_gid, MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_EMPTY);
            cui_inline_set_value(g_settings_sound.audio_inline_gid, MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_SELECT, (void*)current_audio_surround_index);
            g_settings_current_effect_index = current_audio_surround_index;
            break;
        }
    #endif
        default:
            break;
    }
        

    cui_inline_set_value(g_settings_sound.audio_inline_gid, MMI_SETTINGS_AUDIO_EFFECT_LEVEL_1, (void*)g_settings_selected_audio_effect);
    
    cui_inline_run(g_settings_sound.audio_inline_gid);

    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_effect_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 * mmi_event_struct*    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_settings_audio_effect_proc(mmi_event_struct* event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    mmi_popup_property_struct arg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    switch(event->evt_id)
    {
        /*Audio Effect Inline Cui*/
        case EVT_ID_CUI_INLINE_NOTIFY:
        {
            cui_event_inline_notify_struct *notify = (cui_event_inline_notify_struct *)event;
            if(notify->sender_id == g_settings_sound.audio_inline_gid)
            {
                switch(notify->event_type)
                {
                    case CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED:
                    {
                        S32 index = (S32)notify->param;

                        if(notify->item_id == MMI_SETTINGS_AUDIO_EFFECT_LEVEL_1)
                        {
                            mmi_settings_audio_effect_switch_level_1(index);
                        }
                        else if(notify->item_id == MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_SELECT)
                        {
                            mmi_settings_audio_effect_switch_level_2(index);
                        }
                        else
                        {
                            ASSERT(0);
                        }
                        
                    }
                }
            }
            break;
        }

        case EVT_ID_CUI_INLINE_CSK_PRESS:
        case EVT_ID_CUI_INLINE_SUBMIT:
        {
            cui_event_inline_submit_struct *submit = (cui_event_inline_submit_struct *)event;

            if(submit->sender_id == g_settings_sound.audio_inline_gid)
            {
            #ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
                if(g_settings_current_audio_effect == SETTINGS_SOUND_EFFECTS_EQ &&
                   submit->item_id == MMI_SETTINGS_AUDIO_EFFECT_LEVEL_2_SELECT &&
                   event->evt_id == EVT_ID_CUI_INLINE_SUBMIT)
                {
                    mmi_settings_entry_audio_equalizer_setting_options();
                }
                else
            #endif
                {
                    mmi_settings_audio_effect_settings_done();
                }
            }
            
            break;
        }
        
        case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_event_inline_abort_struct *abort = (cui_event_inline_abort_struct*)event;
            cui_inline_close(abort->sender_id);
            mmi_frm_group_close(GRP_ID_SETTING_AUDIO_EFFECT);
            break;
        }

    #ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
        /* Menu Cui*/
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)event;
            switch(menu_evt->highlighted_menu_id)
            {
                case MENU_SETTING_AUDIO_EQUALIZER_SET_OPT_SELECT:
                {
                    mmi_settings_audio_effect_settings_done();
                    break;
                }
                
                case MENU_SETTING_AUDIO_EQUALIZER_SET_OPT_EDIT:
                {
                    mmi_settings_entry_audio_equalizer_setting_edit(GRP_ID_SETTING_AUDIO_EFFECT);
                    break;
                }
                
                case MENU_SETTING_AUDIO_EQUALIZER_SET_OPT_RENAME:
                {
                    mmi_settings_entry_audio_equalizer_setting_rename(GRP_ID_SETTING_AUDIO_EFFECT);
                    break;
                }
                
                case MENU_SETTING_AUDIO_EQUALIZER_SET_OPT_RESET:
                {
                    mmi_settings_audio_equalizer_restore_factory_default_confirm();
                    break;
                }
            }
            break;
        }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(g_settings_sound.eq_opt_menu_gid);
            g_settings_sound.eq_opt_menu_gid = 0;
            break;
        }

        /* Editor Cui*/
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
        {
            /* Empty */
            if(cui_fseditor_get_text_len(g_settings_sound.eq_editor_gid) == 0)
            {
                g_settings_sound.pop_up_type = MMI_SETTINGS_SE_POPUP_EQ_RENAME_INVALID;

                mmi_popup_property_init(&arg);
                arg.parent_id = GRP_ID_SETTING_AUDIO_EFFECT;
                arg.user_tag = (void*)&g_settings_sound.pop_up_type;

                mmi_popup_display((WCHAR*)GetString(STR_ID_SETTING_AUDIO_EQUALIZER_SETTING_INVALID_NAME), MMI_EVENT_FAILURE, &arg);

            }
            else
            {
                cui_fseditor_get_text(
                    g_settings_sound.eq_editor_gid,
                    (WCHAR*)g_settings_audio_equalizer.setting_name[current_audio_equalizer_index],
                    (SETTING_NAME_MAX_LEN+1)*ENCODING_LENGTH);

                RENAME_BIT_ON(g_settings_eq_rename_flag,current_audio_equalizer_index);

                mmi_settings_audio_eq_write_to_nvram();

/*bql: apply new UE design to avoid success popup */
#if 1

                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__                    
                cui_fseditor_close(g_settings_sound.eq_editor_gid);
#endif

#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

            }
            break;
        }

        case EVT_ID_CUI_FSEDITOR_ABORT:
        {
            cui_fseditor_close(g_settings_sound.eq_editor_gid);
            break;
        }
    #endif /*__MMI_EDITABLE_AUDIO_EQUALIZER__*/

        /* Popup, Confirm */
        case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct *)event;

            switch(alert->result)
            {
                case MMI_POPUP_NORMAL_EXIT:
                case MMI_POPUP_INTERRUPT_EXIT:
                {
                    mmi_event_popoupcallback_result_struct *popup = (mmi_event_popoupcallback_result_struct*)event;
                    MMI_SETTING_SE_POPUP_ENUM* type = (MMI_SETTING_SE_POPUP_ENUM*)popup->user_tag;

                    switch(*type)
                    {
                        case MMI_SETTINGS_SE_POPUP_GROUP_END_AUDIO:
                        {
                            mmi_frm_group_close(GRP_ID_SETTING_AUDIO_EFFECT);
                            break;
                        }

                        case MMI_SETTINGS_SE_POPUP_EQ_OPTIONS_EDIT:
                        {
                            mmi_frm_scrn_close(GRP_ID_SETTING_AUDIO_EFFECT,SCR_ID_SETTING_AUDIO_EQUALIZER_OPTIONS_EDIT);
                            break;
                        }

                        case MMI_SETTINGS_SE_POPUP_EQ_RENAME_SUCCESS:
                        {
                        #ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__                    
                            cui_fseditor_close(g_settings_sound.eq_editor_gid);
                        #endif
                            break;
                        }
                    }   
                    break;
                }

                case MMI_ALERT_CNFM_YES:
                case MMI_ALERT_CNFM_OK:
                {
                #ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
                    mmi_settings_audio_equalizer_restore_factory_default_ext();
                #endif
                    break;
                }

                case MMI_ALERT_CNFM_NO:
                {
                    mmi_frm_scrn_close_active_id();
                    break;
                }
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
 *  mmi_settings_entry_audio_effect_group
 * DESCRIPTION
 *  This function is entry function for the audio effect main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_entry_audio_effect_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    if(mmi_frm_group_is_present(GRP_ID_SETTING_AUDIO_EFFECT))
    {
        mmi_frm_group_close(GRP_ID_SETTING_AUDIO_EFFECT);
    }

    mmi_frm_group_create(GRP_ID_SETTING_SOUND_EFFECT, GRP_ID_SETTING_AUDIO_EFFECT, mmi_settings_audio_effect_proc, NULL);
    mmi_frm_group_enter(GRP_ID_SETTING_AUDIO_EFFECT,0);

    mmi_settings_entry_audio_effect();
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_turn_off_audio_effect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_turn_off_audio_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_SND_EFFECT_TURN_OFF,g_settings_selected_audio_effect);

#ifdef __MMI_AUDIO_EQUALIZER__
    if(g_settings_selected_audio_effect == SETTINGS_SOUND_EFFECTS_EQ)
    {
        mdi_audio_eq_turn_off();
    }
    else
#endif
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    if(g_settings_selected_audio_effect == SETTINGS_SOUND_EFFECTS_REVERB)
    {
        mdi_audio_reverb_turn_off();

        wgui_status_icon_bar_hide_icon(STATUS_ICON_REVERB_SOUND);
    }
    else
#endif
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    if(g_settings_selected_audio_effect == SETTINGS_SOUND_EFFECTS_SURROUND)
    {
        mdi_audio_surround_turn_off();

        wgui_status_icon_bar_hide_icon(STATUS_ICON_AUD_SURROUND);
    }
    else
#endif
    {
        /* shall not get in this option*/
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_turn_on_audio_effect
 * DESCRIPTION
 *  based on current settings, turn on audio effect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_turn_on_audio_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_AUDIO_EQUALIZER__
    if(g_settings_selected_audio_effect == SETTINGS_SOUND_EFFECTS_EQ)
    {
        mdi_audio_eq_set_magnitude((CHAR*)g_settings_audio_equalizer_band.magnitude[g_settings_audio_equalizer_band.index]);
        mdi_audio_eq_turn_on();
    }
    else
#endif
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    if(g_settings_selected_audio_effect == SETTINGS_SOUND_EFFECTS_REVERB)
    {
        mmi_settings_audio_reverb_effect_init(g_mmi_aud_3d_cntx.reverb_index);
    }
    else
#endif
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    if(g_settings_selected_audio_effect == SETTINGS_SOUND_EFFECTS_SURROUND)
    {
        mmi_settings_audio_surround_effect_init(g_mmi_aud_3d_cntx.surround_index);
    }
    else
#endif
    {
        /*SETTINGS_SOUND_EFFECTS_NONE*/
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_effect_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_audio_effect_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 error ;
    U8 write_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    ReadValue(NVRAM_BYTE_AUDIO_EFFECT_INDEX, &g_settings_selected_audio_effect, DS_BYTE, &error);
    if(g_settings_selected_audio_effect >= NO_OF_SETTINGS_SOUND_EFFECTS)
    {
       g_settings_selected_audio_effect = 0 ; 
       write_value = g_settings_selected_audio_effect ;
       WriteValue(NVRAM_BYTE_AUDIO_SURROUND_INDEX, &write_value, DS_BYTE, &error);
    }

    mmi_settings_turn_on_audio_effect();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_effect_write_nvram
 * DESCRIPTION
 *  This function is to write effect index back to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_effect_write_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 write_value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_settings_selected_audio_effect < NO_OF_SETTINGS_SOUND_EFFECTS)
    {
        write_value = (U8) g_settings_selected_audio_effect;
    }
    else
    {
        MMI_ASSERT(FALSE);
    }

    WriteValue(NVRAM_BYTE_AUDIO_EFFECT_INDEX, &write_value, DS_BYTE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_effect_settings_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_audio_effect_settings_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL result = MDI_AUDIO_SUCCESS;
#ifdef __MMI_AUDIO_SURROUND_BIND_EARPHONE__
    BOOL surround_popup = FALSE;
#endif
    mmi_popup_property_struct arg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(g_settings_current_audio_effect)
    {
    #ifdef __MMI_AUDIO_EQUALIZER__
        case SETTINGS_SOUND_EFFECTS_EQ :
        {
            if(g_settings_selected_audio_effect != g_settings_current_audio_effect)
            {
                mmi_settings_turn_off_audio_effect();
            }
            result = mmi_settings_audio_eq_apply((S16) current_audio_equalizer_index);
            break;
        }
    #endif
    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        case SETTINGS_SOUND_EFFECTS_REVERB :
        {
            if(g_settings_selected_audio_effect != g_settings_current_audio_effect)
            {
                mmi_settings_turn_off_audio_effect();
            }
            result = mmi_settings_audio_reverb_apply(current_audio_reverb_index);
            break;
        }
    #endif
    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        case SETTINGS_SOUND_EFFECTS_SURROUND :

            if(g_settings_selected_audio_effect != g_settings_current_audio_effect)
            {
                mmi_settings_turn_off_audio_effect();
            }
            
            result = mmi_settings_audio_surround_apply(current_audio_surround_index);
        #ifdef __MMI_AUDIO_SURROUND_BIND_EARPHONE__
            surround_popup = TRUE;
        #endif
            break;
    #endif
        case SETTINGS_SOUND_EFFECTS_NONE :
        {
            mmi_settings_turn_off_audio_effect();
            g_settings_selected_audio_effect = SETTINGS_SOUND_EFFECTS_NONE;            
            break;
        }
        default:
            break;
    }

    g_settings_selected_audio_effect = g_settings_current_audio_effect;
    
    mmi_settings_audio_effect_write_nvram();
    
    if(result == MDI_AUDIO_SUCCESS )
    {
    #ifdef __MMI_AUDIO_SURROUND_BIND_EARPHONE__
        if(surround_popup)
        {
            g_settings_sound.pop_up_type = MMI_SETTINGS_SE_POPUP_GROUP_END_AUDIO;

            mmi_popup_property_init(&arg);
            arg.parent_id = GRP_ID_SETTING_AUDIO_EFFECT;
            arg.user_tag = (void*)&g_settings_sound.pop_up_type;

            mmi_popup_display((WCHAR*)GetString(STR_ID_SETTING_AUDIO_SURROUND_PLUG_EAPHONE), MMI_EVENT_INFO, &arg);
        }
        else
    #endif
        {
        /*bql: apply new UE design to avoid success popup */
#if 1
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
            mmi_frm_group_close(GRP_ID_SETTING_AUDIO_EFFECT);
#else
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
    else
    {
        g_settings_sound.pop_up_type = MMI_SETTINGS_SE_POPUP_GROUP_END_AUDIO;

        mmi_popup_property_init(&arg);
        arg.parent_id = GRP_ID_SETTING_AUDIO_EFFECT;
        arg.user_tag = (void*)&g_settings_sound.pop_up_type;

        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, &arg);

    }

}

#endif /*#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__) */

#ifdef __MMI_AUDIO_EQUALIZER__


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_equalizer_restore_factory_default
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_eq_transfer_magnitude(MMI_BOOL to_bar_num)
{
    S32 i;
    
#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
	kal_prompt_trace(MOD_MMI_MEDIA_APP, "[SOUNDEFFECT]mmi_settings_audio_eq_transfer_magnitude: to_bar_num:%d ", to_bar_num);
	if (to_bar_num)
	{
		/* init bar */
		memset(g_settings_audio_equalizer.magnitude[0], 
				0xFF, 
				MAX_EQUALIZER_NUM * NUM_OF_BARS_IN_A_SETTING * sizeof(signed char));
		g_settings_audio_equalizer.count = g_settings_audio_equalizer_band.count;
		g_settings_audio_equalizer.index = g_settings_audio_equalizer_band.index;
		memcpy(
		  g_settings_audio_equalizer.setting_name[0],
		  g_settings_audio_equalizer_band.setting_name[0],
		  MAX_EQUALIZER_NUM * ((SETTING_NAME_MAX_LEN + 1) *ENCODING_LENGTH) * sizeof(signed char));
		/* band to bar */
		for (i = 0; i < g_settings_audio_equalizer_band.count; i++)
		{
		    mdi_audio_eq_transfer_magnitude(g_settings_audio_equalizer_band.magnitude[i], g_settings_audio_equalizer.magnitude[i], NUM_OF_BARS_IN_A_SETTING, MMI_TRUE);
		}
		
		/*
		memcpy(
		  g_settings_audio_equalizer.magnitude[0],
		  g_settings_audio_equalizer_band.magnitude[0],
		  MAX_EQUALIZER_NUM * NUM_OF_BARS_IN_A_SETTING * sizeof(signed char)); */
	}
	else
	{
		/* init band */
		memset(g_settings_audio_equalizer_band.magnitude[0], 
				0xFF, 
				MAX_EQUALIZER_NUM * NUM_OF_BARS_IN_A_SETTING_NVRAM * sizeof(signed char));
		g_settings_audio_equalizer_band.count = g_settings_audio_equalizer.count;
		g_settings_audio_equalizer_band.index = g_settings_audio_equalizer.index;
		memcpy(
		  g_settings_audio_equalizer_band.setting_name[0],
		  g_settings_audio_equalizer.setting_name[0],
		  MAX_EQUALIZER_NUM * ((SETTING_NAME_MAX_LEN + 1) *ENCODING_LENGTH) * sizeof(signed char));
		/* bar to band */
		for (i = 0; i < g_settings_audio_equalizer_band.count; i++)
		{
		    mdi_audio_eq_transfer_magnitude(g_settings_audio_equalizer.magnitude[i], g_settings_audio_equalizer_band.magnitude[i], NUM_OF_BARS_IN_A_SETTING, MMI_FALSE);
		}
		
		/*
		memcpy(
		  g_settings_audio_equalizer_band.magnitude[0],
		  g_settings_audio_equalizer.magnitude[0],
		  MAX_EQUALIZER_NUM * NUM_OF_BARS_IN_A_SETTING * sizeof(signed char));*/
	}
#else
//bql
	kal_prompt_trace(MOD_MMI_MEDIA_APP, "[SOUNDEFFECT]mmi_settings_audio_eq_transfer_magnitude: to_bar_num:%d ", to_bar_num);
	if (to_bar_num)
	{
		g_settings_audio_equalizer.count = g_settings_audio_equalizer_band.count;
		g_settings_audio_equalizer.index = g_settings_audio_equalizer_band.index;
	}
	else
	{
		g_settings_audio_equalizer_band.count = g_settings_audio_equalizer.count;
		g_settings_audio_equalizer_band.index = g_settings_audio_equalizer.index;
	}
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_eq_read_from_nvram
 * DESCRIPTION
 *  This function is for reading the NVRAM data for audio equalizer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_audio_eq_read_from_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ReadRecord(NVRAM_EF_AUDIO_EQUALIZER_LID, 1, (void*)&g_settings_audio_equalizer_band, sizeof(g_settings_audio_equalizer_band), &error);

    if(g_settings_audio_equalizer_band.index >= MAX_EQUALIZER_NUM)
    {
        g_settings_audio_equalizer_band.index = 0;
    }
    if(g_settings_audio_equalizer_band.count == 0)
    {
       g_settings_audio_equalizer_band.count = MAX_EQUALIZER_NUM ;
    }
//bql
	g_settings_audio_equalizer.count = g_settings_audio_equalizer_band.count;
	g_settings_audio_equalizer.index = g_settings_audio_equalizer_band.index;
	
#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
    ReadValue(NVRAM_EDITABLE_EQ_RENAME_FLAG, &g_settings_eq_rename_flag, DS_SHORT, &error);
    if(g_settings_eq_rename_flag == 0xFFFF)
    {
        g_settings_eq_rename_flag = 0 ;
	WriteValue(NVRAM_EDITABLE_EQ_RENAME_FLAG, &g_settings_eq_rename_flag, DS_SHORT, &error);
    }
	/* to band */
	/*
    memcpy(
      g_settings_audio_equalizer_band.magnitude[0],
      g_settings_audio_equalizer.magnitude[0],
      MAX_EQUALIZER_NUM * NUM_OF_BARS_IN_A_SETTING_NVRAM * sizeof(signed char)); */
      
	/* to bar */
	mmi_settings_audio_eq_transfer_magnitude(MMI_TRUE);

#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_eq_write_to_nvram
 * DESCRIPTION
 *  This function is for writing to NVRAM the audio equalizer values.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_eq_write_to_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* to band */
	mmi_settings_audio_eq_transfer_magnitude(MMI_FALSE);
    WriteRecord(NVRAM_EF_AUDIO_EQUALIZER_LID, 1, (void*)&g_settings_audio_equalizer_band, NVRAM_EF_AUDIO_EQUALIZER_SIZE, &error);

#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
    WriteValue(NVRAM_EDITABLE_EQ_RENAME_FLAG, &g_settings_eq_rename_flag, DS_SHORT, &error);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_eq_init
 * DESCRIPTION
 *  This function is to init audio eq
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_audio_eq_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
    mmi_aud_eq_init_image_specific_vals();
#ifdef __MMI_TOUCH_SCREEN__
    g_audio_equalizer_current_setting_info.pen_handler = mmi_settings_audio_equalizer_change_sound_level;
#endif 
    g_audio_equalizer_current_setting_info.total_bars = NUM_OF_BARS_IN_A_SETTING;
    g_audio_equalizer_current_setting_info.curr_level = (PU16)temp_level;
    g_audio_equalizer_current_setting_info.total_levels = EQ_TOTAL_LEVELS;
#endif
    mmi_settings_audio_eq_read_from_nvram();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_eq_apply
 * DESCRIPTION
 *  This function is for selecting a particular setting.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_settings_audio_eq_apply(S16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result = MDI_AUDIO_SUCCESS;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_settings_audio_equalizer.index = index;

    mmi_settings_audio_eq_write_to_nvram();
    /*only turned on when no track effect is applied*/
#if defined(__MMI_AUDIO_VOCAL_REMOVAL__) || defined(__MMI_AUDIO_PITCH_SHIFTING__)
    if(g_settings_sound.selected_track_effect == MMI_SETTINGS_TRACK_EFFECTS_NONE)
#endif
    {
        mdi_audio_eq_set_magnitude((CHAR*)g_settings_audio_equalizer_band.magnitude[index]);
        result = mdi_audio_eq_turn_on();
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_SND_EFFECT_EQ_APPLY,index,result);

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_eq_rename_by_language
 * DESCRIPTION
 *  Sets EQ names according to current language.
 *  This is an external API called by language
 * PARAMETERS
 *  void
 * RETURNS
 * 
 *****************************************************************************/
void mmi_settings_audio_eq_rename_by_language(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < MAX_EQUALIZER_NUM; ++i)
    {
    #ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
        if (!RENAME_BIT_TEST(g_settings_eq_rename_flag,i))   /* User not modify yet */
    #endif
            mmi_ucs2ncpy(
                (CHAR*) g_settings_audio_equalizer.setting_name[i],
                GetString((U16) (STR_ID_SETTING_AUDIO_EQUALIZER_SET_1 + i)),
                SETTING_NAME_MAX_LEN);
    }

    if (TRUE != g_sound_effect_init_ok)
    {    
    	mmi_settings_audio_eq_init();
    }    

    mmi_settings_audio_eq_write_to_nvram();

}


#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
void mmi_settings_audio_equalizer_restore_factory_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;    
    U8* default_value_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_frm_reset_record(NVRAM_RESET_CERTAIN, 
                         0,
                         NVRAM_EF_AUDIO_EQUALIZER_LID, 
                         1,
                         NVRAM_EF_AUDIO_EQUALIZER_TOTAL);

    nvram_get_default_value(NVRAM_EF_AUDIO_EQUALIZER_LID,1,&default_value_p);

    memcpy(
      &g_settings_audio_equalizer_band,
      default_value_p,
      sizeof(g_settings_audio_equalizer_band));

    for (i = 0; i < MAX_EQUALIZER_NUM; ++i)
    {
            mmi_ucs2ncpy(
                (CHAR*) g_settings_audio_equalizer_band.setting_name[i],
                GetString((U16) (STR_ID_SETTING_AUDIO_EQUALIZER_SET_1 + i)),
                SETTING_NAME_MAX_LEN);
    }

    if (g_settings_selected_audio_effect == SETTINGS_SOUND_EFFECTS_EQ )
    {
        mdi_audio_eq_set_magnitude((CHAR*)g_settings_audio_equalizer_band.magnitude[current_audio_equalizer_index]);
    }

    g_settings_eq_rename_flag = 0 ;

	/* to bar */
	mmi_settings_audio_eq_transfer_magnitude(MMI_TRUE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_equalizer_restore_factory_default_ext
 * DESCRIPTION
 *  This function is for restoring the settings to default values.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_audio_equalizer_restore_factory_default_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_settings_audio_equalizer_restore_factory_default();

    current_audio_equalizer_index = g_settings_audio_equalizer.index;

    g_settings_sound.pop_up_type = MMI_SETTINGS_SE_POPUP_NORMAL;

    mmi_popup_property_init(&arg);
    arg.parent_id = GRP_ID_SETTING_AUDIO_EFFECT;
    arg.user_tag = (void*)&g_settings_sound.pop_up_type;
    /*bql: apply new UE design to avoid success popup */
#if 1
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
#else
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_equalizer_restore_factory_default_confirm
 * DESCRIPTION
 *  Show the confir pop up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_audio_equalizer_restore_factory_default_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);

    g_settings_sound.pop_up_type = MMI_SETTINGS_SE_COMFIRM_EQ_RESTORE;

    arg.parent_id = GRP_ID_SETTING_AUDIO_EFFECT;
    arg.user_tag = (void*)&g_settings_sound.pop_up_type;

    mmi_confirm_display((WCHAR*)GetString(STR_ID_SETTING_AUDIO_EQUALIZER_REST_FACT_DEFAULT_CONFIRM), MMI_EVENT_QUERY, &arg);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_entry_audio_equalizer_setting_options
 * DESCRIPTION
 *  This function is for entering the audio equalizer settings options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_entry_audio_equalizer_setting_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_settings_sound.eq_opt_menu_gid = cui_menu_create(
                                        GRP_ID_SETTING_AUDIO_EFFECT, 
                                        CUI_MENU_SRC_TYPE_RESOURCE, 
                                        CUI_MENU_TYPE_OPTION, 
                                        MENU_SETTING_AUDIO_EQUALIZER_SET_OPT, 
                                        MMI_FALSE, 
                                        NULL);

    cui_menu_set_default_title_image(g_settings_sound.eq_opt_menu_gid, (UI_image_type)GetImage(GetRootTitleIcon(MENU_SETTING_SOUND_EFFECT)));

    cui_menu_run(g_settings_sound.eq_opt_menu_gid);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_equalizer_save_values
 * DESCRIPTION
 *  This function is for saving the values of the edited setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_audio_equalizer_save_values(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    mmi_popup_property_struct arg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1. copy the values to the global audio equalizer setting structure */
    for (index = 0; index < NUM_OF_BARS_IN_A_SETTING; index++)
    {
        g_settings_audio_equalizer.magnitude[current_audio_equalizer_index][index] =
            g_audio_equalizer_current_setting_info.curr_level[index] - (EQ_TOTAL_LEVELS/2);
    }
    /* reset the modification flag */
    g_settings_sound.eq_setting_modified = MMI_FALSE;
    mmi_settings_audio_eq_write_to_nvram();
    if (g_settings_audio_equalizer.index == current_audio_equalizer_index && g_settings_selected_audio_effect == SETTINGS_SOUND_EFFECTS_EQ )
    {
        mdi_audio_eq_set_magnitude((CHAR*)g_settings_audio_equalizer_band.magnitude[current_audio_equalizer_index]);
    }

    /*bql: apply new UE design to avoid success popup */
#if 1
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
    mmi_frm_scrn_close(GRP_ID_SETTING_AUDIO_EFFECT,SCR_ID_SETTING_AUDIO_EQUALIZER_OPTIONS_EDIT);
#else
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
 *  mmi_settings_audio_equalizer_delete_history_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_param     
 * RETURNS
 *  U8
 *****************************************************************************/
static void mmi_settings_audio_equalizer_delete_history_hdlr(void)// *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_settings_sound.eq_setting_modified = MMI_FALSE;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_equalizer_setting_edit_RSK_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_audio_equalizer_setting_edit_RSK_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset the modification flag */
    g_settings_sound.eq_setting_modified = MMI_FALSE;
    mmi_frm_scrn_close_active_id();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_equalizer_activate_previous_bar
 * DESCRIPTION
 *  This function is for activating the previous bar.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_audio_equalizer_activate_previous_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  bar_index ;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    bar_index = (NUM_OF_BARS_IN_A_SETTING + (g_audio_equalizer_current_setting_info.curr_act_bar -1)) % NUM_OF_BARS_IN_A_SETTING ;
    g_audio_equalizer_current_setting_info.curr_act_bar = bar_index;

    RedrawCategory334Screen();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_equalizer_activate_next_bar
 * DESCRIPTION
 *  This function is for activating the next bar in the editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_audio_equalizer_activate_next_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 bar_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    bar_index = (NUM_OF_BARS_IN_A_SETTING + (g_audio_equalizer_current_setting_info.curr_act_bar +1)) % NUM_OF_BARS_IN_A_SETTING ;
    g_audio_equalizer_current_setting_info.curr_act_bar = bar_index;

    RedrawCategory334Screen();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_equalizer_increment_sound_level
 * DESCRIPTION
 *  This function is to increase the sound level.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_audio_equalizer_increment_sound_level(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 sound_level = g_audio_equalizer_current_setting_info.curr_level[
        g_audio_equalizer_current_setting_info.curr_act_bar];
    S16 delta = (S16) EQ_TOTAL_LEVELS / g_audio_equalizer_current_setting_info.total_steps;
    S16 magnitude = (S16) g_settings_audio_equalizer.magnitude[current_audio_equalizer_index]
        [g_audio_equalizer_current_setting_info.curr_act_bar] + (EQ_TOTAL_LEVELS/2);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sound_level += delta;

    if (sound_level > UPPER_LIMIT_SOUND_LEVEL)
    {
        sound_level = UPPER_LIMIT_SOUND_LEVEL;
    }

    g_audio_equalizer_current_setting_info.curr_level[
         g_audio_equalizer_current_setting_info.curr_act_bar] = sound_level;

    if (!g_settings_sound.eq_setting_modified && sound_level != magnitude)
    {
        g_settings_sound.eq_setting_modified = MMI_TRUE;
        ChangeLeftSoftkey(STR_GLOBAL_SAVE, 0);
        SetLeftSoftkeyFunction(mmi_settings_audio_equalizer_save_values, KEY_EVENT_UP);
        ChangeCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_settings_audio_equalizer_save_values, KEY_EVENT_UP);
    }
    RedrawCategory334Screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_equalizer_decrement_sound_level
 * DESCRIPTION
 *  This function is for decreasing the sound level.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_audio_equalizer_decrement_sound_level(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 sound_level = g_audio_equalizer_current_setting_info.curr_level[
        g_audio_equalizer_current_setting_info.curr_act_bar];
    S16 delta = (S16) EQ_TOTAL_LEVELS / g_audio_equalizer_current_setting_info.total_steps;
    S16 magnitude = (S16) g_settings_audio_equalizer.magnitude[current_audio_equalizer_index]
        [g_audio_equalizer_current_setting_info.curr_act_bar] + (EQ_TOTAL_LEVELS/2);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sound_level -= delta;

    if ( sound_level < LOWER_LIMIT_SOUND_LEVEL)
    {
        sound_level = LOWER_LIMIT_SOUND_LEVEL;
    }

    g_audio_equalizer_current_setting_info.curr_level[
        g_audio_equalizer_current_setting_info.curr_act_bar] = sound_level;

    if (!g_settings_sound.eq_setting_modified && sound_level != magnitude)
    {
        g_settings_sound.eq_setting_modified = MMI_TRUE;
        ChangeLeftSoftkey(STR_GLOBAL_SAVE, 0);
        SetLeftSoftkeyFunction(mmi_settings_audio_equalizer_save_values, KEY_EVENT_UP);
        ChangeCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_settings_audio_equalizer_save_values, KEY_EVENT_UP);
    }

    RedrawCategory334Screen();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_equalizer_edit_leave_scrn_proc
 * DESCRIPTION
 *  webcam leave proc function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_settings_audio_equalizer_edit_leave_scrn_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_SCRN_DELETE_REQ:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        case EVT_ID_SCRN_GOBACK:
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
            mmi_settings_audio_equalizer_delete_history_hdlr();
            break;
            
        default:
            return MMI_RET_ERR;
    }
    return MMI_RET_ALLOW_CLOSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_entry_audio_equalizer_setting_edit
 * DESCRIPTION
 *  This function is for entering the editing screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_entry_audio_equalizer_setting_edit(MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8  index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_group_is_present(GRP_ID_SETTING_AUDIO_EFFECT))
    {
        mmi_frm_group_create(parent_id, GRP_ID_SETTING_AUDIO_EFFECT, mmi_settings_audio_effect_proc, NULL);
        mmi_frm_group_enter(GRP_ID_SETTING_AUDIO_EFFECT,MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }

    mmi_frm_scrn_enter(GRP_ID_SETTING_AUDIO_EFFECT, SCR_ID_SETTING_AUDIO_EQUALIZER_OPTIONS_EDIT, NULL, mmi_settings_entry_audio_equalizer_setting_edit, 0);

    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_SETTING_AUDIO_EFFECT, SCR_ID_SETTING_AUDIO_EQUALIZER_OPTIONS_EDIT);

    if (!guiBuffer)
    {
        /* initially the first bar is to be activated. */
        g_audio_equalizer_current_setting_info.curr_act_bar = 0;

        /* initalize the temp sound level to current global eq magnitudes*/
        for (index = 0; index < NUM_OF_BARS_IN_A_SETTING; index++)
        {
            g_audio_equalizer_current_setting_info.curr_level[index] = 
                (S16)g_settings_audio_equalizer.magnitude[current_audio_equalizer_index][index] + (EQ_TOTAL_LEVELS/2);
        }

        g_audio_equalizer_current_setting_info.bg_image = (PU8)GetImage(SOUND_EFFECT_AUDIO_EQ_BG);
        g_audio_equalizer_current_setting_info.act_bar_image = (PU8)GetImage(SOUND_EFFECT_AUDIO_EQ_ACTIVE_BAR);
        g_audio_equalizer_current_setting_info.act_ind_image = (PU8)GetImage(SOUND_EFFECT_AUDIO_EQ_VAL_INDICATOR);		

        ShowCategory334Screen(
            (UI_string_type)GetString(STR_ID_SETTING_AUDIO_EQUALIZER_CAPTION),
            (PU8)GetImage(GetRootTitleIcon(MENU_SETTING_SOUND_EFFECT)),
            NULL,
            NULL,
            (UI_string_type)GetString(STR_GLOBAL_BACK),
            (PU8)GetImage(IMG_GLOBAL_BACK),
            &g_audio_equalizer_current_setting_info,
            guiBuffer);
    }
    else
    {

        g_audio_equalizer_current_setting_info.bg_image = (PU8)GetImage(SOUND_EFFECT_AUDIO_EQ_BG);
        g_audio_equalizer_current_setting_info.act_bar_image = (PU8)GetImage(SOUND_EFFECT_AUDIO_EQ_ACTIVE_BAR);
        g_audio_equalizer_current_setting_info.act_ind_image = (PU8)GetImage(SOUND_EFFECT_AUDIO_EQ_VAL_INDICATOR);		
    
        if (g_settings_sound.eq_setting_modified)
        {
            ShowCategory334Screen(
                (UI_string_type)GetString(STR_ID_SETTING_AUDIO_EQUALIZER_CAPTION),
                (PU8)GetImage(GetRootTitleIcon(MENU_SETTING_SOUND_EFFECT)),
                (UI_string_type)GetString(STR_GLOBAL_SAVE),
                NULL,
                (UI_string_type)GetString(STR_GLOBAL_BACK),
                (PU8)GetImage(IMG_GLOBAL_BACK),
                &g_audio_equalizer_current_setting_info,
                guiBuffer);
            SetLeftSoftkeyFunction(mmi_settings_audio_equalizer_save_values, KEY_EVENT_UP);
            ChangeCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(mmi_settings_audio_equalizer_save_values, KEY_EVENT_UP);
        }
        else
        {
            ShowCategory334Screen(
                (UI_string_type)GetString(STR_ID_SETTING_AUDIO_EQUALIZER_CAPTION),
                (PU8)GetImage(GetRootTitleIcon(MENU_SETTING_SOUND_EFFECT)),
                NULL,
                NULL,
                (UI_string_type)GetString(STR_GLOBAL_BACK),
                (PU8)GetImage(IMG_GLOBAL_BACK),
                &g_audio_equalizer_current_setting_info,
                guiBuffer);
        }
    }
    SetKeyHandler(mmi_settings_audio_equalizer_activate_previous_bar, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_settings_audio_equalizer_activate_previous_bar, KEY_LEFT_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(mmi_settings_audio_equalizer_activate_previous_bar, KEY_LEFT_ARROW, KEY_EVENT_LONG_PRESS);

    SetKeyHandler(mmi_settings_audio_equalizer_activate_next_bar, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_settings_audio_equalizer_activate_next_bar, KEY_RIGHT_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(mmi_settings_audio_equalizer_activate_next_bar, KEY_RIGHT_ARROW, KEY_EVENT_LONG_PRESS);

    SetKeyHandler(mmi_settings_audio_equalizer_increment_sound_level, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_settings_audio_equalizer_increment_sound_level, KEY_UP_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(mmi_settings_audio_equalizer_increment_sound_level, KEY_UP_ARROW, KEY_EVENT_LONG_PRESS);

    SetKeyHandler(mmi_settings_audio_equalizer_decrement_sound_level, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_settings_audio_equalizer_decrement_sound_level, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(mmi_settings_audio_equalizer_decrement_sound_level, KEY_DOWN_ARROW, KEY_EVENT_LONG_PRESS);

    SetKeyHandler(mmi_settings_audio_equalizer_increment_sound_level, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_settings_audio_equalizer_increment_sound_level, KEY_VOL_UP, KEY_EVENT_REPEAT);
    SetKeyHandler(mmi_settings_audio_equalizer_increment_sound_level, KEY_VOL_UP, KEY_EVENT_LONG_PRESS);

    SetKeyHandler(mmi_settings_audio_equalizer_decrement_sound_level, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_settings_audio_equalizer_decrement_sound_level, KEY_VOL_DOWN, KEY_EVENT_REPEAT);
    SetKeyHandler(mmi_settings_audio_equalizer_decrement_sound_level, KEY_VOL_DOWN, KEY_EVENT_LONG_PRESS);

    SetRightSoftkeyFunction(mmi_settings_audio_equalizer_setting_edit_RSK_hdlr, KEY_EVENT_UP);

    mmi_frm_scrn_set_leave_proc(
        GRP_ID_SETTING_AUDIO_EFFECT, 
        SCR_ID_SETTING_AUDIO_EQUALIZER_OPTIONS_EDIT,
        mmi_settings_audio_equalizer_edit_leave_scrn_proc);


}


#ifdef __MMI_TOUCH_SCREEN__

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_equalizer_change_sound_level
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bar      [IN]
 *  level    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_audio_equalizer_change_sound_level(U8 bar, U16 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 magnitude = (S16) g_settings_audio_equalizer.magnitude[current_audio_equalizer_index]
        [bar] + (EQ_TOTAL_LEVELS/2);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    g_audio_equalizer_current_setting_info.curr_level[bar] = level;
    g_audio_equalizer_current_setting_info.curr_act_bar = bar;

    if (!g_settings_sound.eq_setting_modified && level != magnitude)
    {
        g_settings_sound.eq_setting_modified = MMI_TRUE;
        ChangeLeftSoftkey(STR_GLOBAL_SAVE, 0);
        SetLeftSoftkeyFunction(mmi_settings_audio_equalizer_save_values, KEY_EVENT_UP);
        ChangeCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_settings_audio_equalizer_save_values, KEY_EVENT_UP);
    }

    RedrawCategory334Screen();
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


/* renaming related functions */
/*****************************************************************************
 * FUNCTION
 *  mmi_settings_entry_audio_equalizer_setting_rename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_entry_audio_equalizer_setting_rename(MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_frm_group_is_present(GRP_ID_SETTING_AUDIO_EFFECT))
    {
        mmi_frm_group_create(parent_id, GRP_ID_SETTING_AUDIO_EFFECT, mmi_settings_audio_effect_proc, NULL);
        mmi_frm_group_enter(GRP_ID_SETTING_AUDIO_EFFECT,MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }

    if (( g_settings_sound.eq_editor_gid= cui_fseditor_create(GRP_ID_SETTING_AUDIO_EFFECT)) != NULL)
    {
        WCHAR* temp_str;
        temp_str = get_ctrl_buffer((SETTING_NAME_MAX_LEN+1)*ENCODING_LENGTH);

        mmi_ucs2cpy(
            (CHAR*) temp_str,
            (CHAR*) g_settings_audio_equalizer.setting_name[current_audio_equalizer_index]);

        cui_fseditor_set_title(
            g_settings_sound.eq_editor_gid, 
            STR_ID_SETTING_AUDIO_EQUALIZER_SETTIN_NAME_EDIT_TITLE, 
            GetRootTitleIcon(MENU_SETTING_SOUND_EFFECT));
        
        cui_fseditor_set_text(
            g_settings_sound.eq_editor_gid, 
            (WCHAR*) temp_str, 
            (SETTING_NAME_MAX_LEN+1)*ENCODING_LENGTH,
            SETTING_NAME_MAX_LEN);

        cui_fseditor_set_input_method(g_settings_sound.eq_editor_gid, IMM_INPUT_TYPE_SENTENCE, NULL, 0);
        cui_fseditor_run(g_settings_sound.eq_editor_gid);

        free_ctrl_buffer(temp_str);
    }

}

#endif /* __MMI_EDITABLE_AUDIO_EQUALIZER__ */ 
#endif /* __MMI_AUDIO_EQUALIZER */

#ifdef __MMI_AUDIO_REVERB_EFFECT__

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_reverb_read_nvram
 * DESCRIPTION
 *  This function is to read reverb setting from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_audio_reverb_read_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 read_value;
    U8 write_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_BYTE_AUDIO_REVERB_INDEX, &read_value, DS_BYTE, &error);

    if (read_value < MAX_AUDIO_REVERB_EFFECT_NUM)
    {
        g_mmi_aud_3d_cntx.reverb_index = read_value;
        return;
    }

    g_mmi_aud_3d_cntx.reverb_index = 0;
    write_value = g_mmi_aud_3d_cntx.reverb_index ;
    WriteValue(NVRAM_BYTE_AUDIO_REVERB_INDEX, &write_value, DS_BYTE, &error);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_reverb_write_nvram
 * DESCRIPTION
 *  This function is to write reverb settings back to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_audio_reverb_write_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 write_value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_aud_3d_cntx.reverb_index <= MAX_AUDIO_REVERB_EFFECT_NUM)
    {
        write_value = (U8) g_mmi_aud_3d_cntx.reverb_index;
    }
    else
    {
        MMI_ASSERT(FALSE);
    }

    WriteValue(NVRAM_BYTE_AUDIO_REVERB_INDEX, &write_value, DS_BYTE, &error);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_reverb_init
 * DESCRIPTION
 *  This function is to init reverb effect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_audio_reverb_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Read value from NVRAM and set reverb effect if turned on */
    mmi_settings_audio_reverb_read_nvram();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_reverb_apply
 * DESCRIPTION
 *  This function is to apply reverb effect
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_settings_audio_reverb_apply(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result = MDI_AUDIO_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_mmi_aud_3d_cntx.reverb_index = index;

    /*only turned on when no track effect is applied*/
#if defined(__MMI_AUDIO_VOCAL_REMOVAL__) || defined(__MMI_AUDIO_PITCH_SHIFTING__)
    if(g_settings_sound.selected_track_effect == MMI_SETTINGS_TRACK_EFFECTS_NONE)
#endif
    {
        mdi_audio_reverb_set_mode(index);
        result = mdi_audio_reverb_turn_on();

        if (result != MDI_AUDIO_SUCCESS)
        {
            g_mmi_aud_3d_cntx.reverb_index = 0;
            wgui_status_icon_bar_reset_icon_display(STATUS_ICON_REVERB_SOUND);
        }
        else
        {
            wgui_status_icon_bar_set_icon_display(STATUS_ICON_REVERB_SOUND);
        }

        wgui_status_icon_bar_update();
    }

    /* Write result back to NVRAM */
    mmi_settings_audio_reverb_write_nvram();

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_SND_EFFECT_REVERB_APPLY,index,result);

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_reverb_effect_init
 * DESCRIPTION
 *  This function is to set reverb effect at the initialize time
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_audio_reverb_effect_init(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Set and turn on audio reverb effect */
    if (index <= MAX_AUDIO_REVERB_EFFECT_NUM)
    {
        mdi_audio_reverb_set_mode(index);
        result = mdi_audio_reverb_turn_on();

        if (result == MDI_AUDIO_SUCCESS)
        {
            wgui_status_icon_bar_show_icon(STATUS_ICON_REVERB_SOUND);
            return;
        }
    }

    wgui_status_icon_bar_hide_icon(STATUS_ICON_REVERB_SOUND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_reverb_get_status
 * DESCRIPTION
 *  This function is to get reverb effect on/off setting
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE: on
 *  MMI_FALSE: off
 *****************************************************************************/
MMI_BOOL mmi_settings_audio_reverb_get_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_settings_selected_audio_effect == SETTINGS_SOUND_EFFECTS_REVERB)
	{
		return MMI_TRUE;
	}

	return MMI_FALSE;
}

#endif /*__MMI_AUDIO_REVERB_EFFECT__*/


#ifdef __MMI_AUDIO_SURROUND_EFFECT__

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_reverb_read_nvram
 * DESCRIPTION
 *  This function is to read surround setting from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_audio_surround_read_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 read_value;
    U8 write_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_BYTE_AUDIO_SURROUND_INDEX, &read_value, DS_BYTE, &error);

    if (read_value < AUD_SURROUND_TOTAL)
    {
        g_mmi_aud_3d_cntx.surround_index = read_value;
        return;
    }

    g_mmi_aud_3d_cntx.surround_index = 0;
    write_value = g_mmi_aud_3d_cntx.surround_index;
    WriteValue(NVRAM_BYTE_AUDIO_SURROUND_INDEX, &write_value, DS_BYTE, &error);
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_surround_write_nvram
 * DESCRIPTION
 *  This function is to write surround settings back to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_audio_surround_write_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 write_value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_aud_3d_cntx.surround_index <= AUD_SURROUND_TOTAL)
    {
        write_value = (U8) g_mmi_aud_3d_cntx.surround_index;
    }
    else
    {
        MMI_ASSERT(FALSE);
    }

    WriteValue(NVRAM_BYTE_AUDIO_SURROUND_INDEX, &write_value, DS_BYTE, &error);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_surround_init
 * DESCRIPTION
 *  This function is to init audio surround effect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_audio_surround_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Read value from NVRAM and set surround effect if turned on */
    mmi_settings_audio_surround_read_nvram();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_surround_effect_init
 * DESCRIPTION
 *  This function is to set surround effect at the initialize time
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_settings_audio_surround_effect_init(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

   if (index < AUD_SURROUND_TOTAL)
   {
        mdi_audio_surround_turn_on((U8)(index));
        wgui_status_icon_bar_show_icon(STATUS_ICON_AUD_SURROUND);
        g_mmi_aud_3d_cntx.surround_index = index;

        return;
    }
    wgui_status_icon_bar_hide_icon(STATUS_ICON_AUD_SURROUND);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_surround_apply
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_settings_audio_surround_apply(U16 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result = MDI_AUDIO_SUCCESS;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*only turned on when no track effect is applied*/
#if defined(__MMI_AUDIO_VOCAL_REMOVAL__) || defined(__MMI_AUDIO_PITCH_SHIFTING__)
    if(g_settings_sound.selected_track_effect == MMI_SETTINGS_TRACK_EFFECTS_NONE)
#endif
    {
        if(mode < AUD_SURROUND_TOTAL)
        {
            result = mdi_audio_surround_turn_on((U8) (mode));
            wgui_status_icon_bar_set_icon_display(STATUS_ICON_AUD_SURROUND);
        }

        g_mmi_aud_3d_cntx.surround_index = mode;
        wgui_status_icon_bar_update();
    }
    
    mmi_settings_audio_surround_write_nvram();

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_SND_EFFECT_SURROUND_APPLY,mode,result);
    return result;

}


#endif /* __MMI_AUDIO_SURROUND_EFFECT__ */

#endif /* __MMI_SOUND_EFFECT__ */ 

#if defined(__MMI_AUDIO_VOCAL_REMOVAL__) || defined(__MMI_AUDIO_PITCH_SHIFTING__)
/*****************************************************************************
 * FUNCTION
 *  mmi_settings_apply_track_effect
 * DESCRIPTION
 *  for application to chose which track effect to trun on and the level stands 
 *  for how the track effect to be applied
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_apply_track_effect(MMI_SETTINGS_TRACK_EFFECTS_ENUM track_effect,S32 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SOUND_EFFECTS_APPLY_TRACK_EFFECT, g_settings_sound.selected_track_effect, track_effect, level);
    
    switch(track_effect)
    {
    #ifdef __MMI_AUDIO_VOCAL_REMOVAL__
        case MMI_SETTINGS_TRACK_EFFECTS_VOCAL_REMOVAL:
        {
            /*turn off key signature*/
        #ifdef __MMI_AUDIO_PITCH_SHIFTING__
            if(g_settings_sound.selected_track_effect == MMI_SETTINGS_TRACK_EFFECTS_PITCH_SHIFTING)
            {
                mdi_audio_pitch_shifting_turn_off();
            }
        #endif

            if(level == MMI_SETTINGS_VOCAL_REMOVAL_OFF)
            {
                if(g_settings_sound.selected_track_effect == MMI_SETTINGS_TRACK_EFFECTS_VOCAL_REMOVAL)
                {
                    mdi_audio_vocal_removal_turn_off();
                }

            #if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
                mmi_settings_turn_on_audio_effect();
            #endif

                g_settings_sound.selected_track_effect = MMI_SETTINGS_TRACK_EFFECTS_NONE;

                return;
            }

            /*turn off audio effects*/
        #if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
            if(g_settings_sound.selected_track_effect == MMI_SETTINGS_TRACK_EFFECTS_NONE)
            {
                mmi_settings_turn_off_audio_effect();
            }
        #endif

            /*turn on human voice remove*/
            result = mdi_audio_vocal_removal_turn_on();
            if(result != MDI_AUDIO_SUCCESS)
            {
            #if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
                mmi_settings_turn_on_audio_effect();
            #endif
                g_settings_sound.selected_track_effect = MMI_SETTINGS_TRACK_EFFECTS_NONE;
            }
            else
            {
                g_settings_sound.selected_track_effect = MMI_SETTINGS_TRACK_EFFECTS_VOCAL_REMOVAL;
            }

            break;
        }
    #endif

    #ifdef __MMI_AUDIO_PITCH_SHIFTING__
        case MMI_SETTINGS_TRACK_EFFECTS_PITCH_SHIFTING:
        {
            /*turn off human voice remove*/
        #ifdef __MMI_AUDIO_VOCAL_REMOVAL__
            if(g_settings_sound.selected_track_effect == MMI_SETTINGS_TRACK_EFFECTS_VOCAL_REMOVAL)
            {
                mdi_audio_vocal_removal_turn_off();
            }
        #endif

            if(level == MMI_SETTINGS_PITCH_SHIFTING_0)
            {
                if(g_settings_sound.selected_track_effect == MMI_SETTINGS_TRACK_EFFECTS_PITCH_SHIFTING)
                {
                    mdi_audio_pitch_shifting_turn_off();
                }
            #if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
                mmi_settings_turn_on_audio_effect();
            #endif

                g_settings_sound.selected_track_effect = MMI_SETTINGS_TRACK_EFFECTS_NONE;
                return;
            }

            /*turn off audio effects*/
        #if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
            if(g_settings_sound.selected_track_effect == MMI_SETTINGS_TRACK_EFFECTS_NONE)
            {
                mmi_settings_turn_off_audio_effect();
            }
        #endif
        
            result = mdi_audio_pitch_shifting_set_level((S16)level);
            if(result == MDI_AUDIO_SUCCESS)
            {
                result = mdi_audio_pitch_shifting_turn_on();
            }

            if(result != MDI_AUDIO_SUCCESS)
            {
            #if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
                mmi_settings_turn_on_audio_effect();
            #endif
                g_settings_sound.selected_track_effect = MMI_SETTINGS_TRACK_EFFECTS_NONE;
            }
            else
            {
                g_settings_sound.selected_track_effect = MMI_SETTINGS_TRACK_EFFECTS_PITCH_SHIFTING;
            }

            break;
        }    
    #endif
        case MMI_SETTINGS_TRACK_EFFECTS_NONE:
        {
        #ifdef __MMI_AUDIO_VOCAL_REMOVAL__
            if(g_settings_sound.selected_track_effect == MMI_SETTINGS_TRACK_EFFECTS_VOCAL_REMOVAL)
            {
                mdi_audio_vocal_removal_turn_off();
            }
        #endif

        #ifdef __MMI_AUDIO_PITCH_SHIFTING__
            if(g_settings_sound.selected_track_effect == MMI_SETTINGS_TRACK_EFFECTS_PITCH_SHIFTING)
            {
                mdi_audio_pitch_shifting_turn_off();
            }
        #endif

        #if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
            mmi_settings_turn_on_audio_effect();
        #endif

            g_settings_sound.selected_track_effect = MMI_SETTINGS_TRACK_EFFECTS_NONE;

            break;
        }
    }

}
#endif  /*defined(__MMI_AUDIO_VOCAL_REMOVAL__) || defined(__MMI_AUDIO_PITCH_SHIFTING__)*/

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_turn_off__sound_effects
 * DESCRIPTION
 *  for some application does not wish to apply sound effect, this api could turn off
 *  all sound effects currently turned on. but, after the application finish it's 
 *  audio playing, they have the responsibility to turn it on again
 *  
 *  if application who is using this api to turn off sound effecs also needs to 
 *  suspend mdi_audio,then it needs to suspend mdi_audio first and then turn off 
 *  sound effects or mdi_audio playing application might turn on sound effect for 
 *  turn off track effects which is exclusive with sound effects
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_turn_off_sound_effects(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
    mmi_settings_turn_off_audio_effect();
#endif
#ifdef __MMI_AUDIO_BASS_ENHANCEMENT__
    mdi_audio_bass_enhance_turn_off();
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_turn_on_sound_effects
 * DESCRIPTION
 *  turn on sound effects
 *
 *  if application who is using this api to turn on sound effecs also needs to 
 *  resume mdi_audio, then it needs to turn on sound effects first and then
 *  resume mdi_audio.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_turn_on_sound_effects(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_AUDIO_BASS_ENHANCEMENT__
    mdi_result result;
    S16 error;
    U8 write_value;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
    mmi_settings_turn_on_audio_effect();
#endif

#ifdef __MMI_AUDIO_BASS_ENHANCEMENT__

    result = MDI_AUDIO_SUCCESS;

    switch(g_settings_bass_enhancement)
    {
        case __BES_BASS_SUPPORT___OFF:
        {
            mdi_audio_bass_enhance_turn_off();
            break;
        }

        case __BES_BASS_SUPPORT___ON:
        {
            result = mdi_audio_bass_enhance_turn_on();
            break;
        }

        default:
            break;
    }

    if(result != MDI_AUDIO_SUCCESS)
    {
        g_settings_bass_enhancement = __BES_BASS_SUPPORT___OFF;
        write_value = g_settings_bass_enhancement;
        WriteValue(NVRAM_BYTE_AUDIO_BASS_ENHANCEMENT_INDEX, &write_value, DS_BYTE, &error);        
    }
#endif

}

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
#endif //0
