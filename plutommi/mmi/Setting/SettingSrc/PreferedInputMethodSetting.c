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
 *  imesettings.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 * UI for IME settings for Phone settings
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *******************************************************************************/
/* Commented so that it is not included for cosmos project */ 
#ifdef __PLUTO_MMI_PACKAGE__
#include "mmi_rp_app_mainmenu_def.h"
#endif 
#include "mmi_rp_srv_editor_def.h"
#include "MMI_include.h"
#include "CUSTOM_EVENTS_NOTIFY.h"
#include "commonscreensresdef.h"
#include "mainmenudef.h"
#include "IMERes.h"
#include "ImeGprot.h"
#include "ProtocolEvents.h"
//#include "HardwareEvents.h"
#include "Thrdosinterface.h"
#include "OSThreadInterfaceGprot.h"
#include "MainMenuDef.h"
#include "settinggprots.h"
#include "SettingsGexdcl.h"
#include "SettingProfile.h"
#include "SettingProt.h"
#include "SettingDefs.h"
#include "PreferedInputMethodProt.h"
#include "PhoneSetupGprots.h"
#include "CommonScreens.h"
#include "Wgui_categories_util.h"
#include "wgui_fixed_menus.h" /* Added for build error due to RHR */ 
#include "immprot.h"
#ifdef __MMI_IME_PLUG_IN__
#include "ImeSDKGprot.h"
#endif
#ifdef __MMI_PREFER_INPUT_METHOD__
    U8 *inputMethodList[IMM_INPUT_MODE_MAX_NUM]; /* have to keep it here for memory reduction */ 
#endif
    U8 g_writing_langItemListState[16] ;
    U8 g_totalLang = 0;
MMI_ID g_active_imesettings_group ;
MMI_ID g_active_imesettings_screen ;
mmi_ret mmi_ime_settings_input_mode_screen_popup_handler_for_sg(mmi_event_struct *param);
#if defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_PREFER_WRITING_LANG__)
static void mmi_imesettings_writing_lang_entry_screen_with_sg(mmi_id g_id);
extern ime_writing_lang_struct g_ime_writing_lang_array[MAX_WRITING_LANG]; 
static U8 g_current_writinglang_index = 0;
static void mmi_imesettings_writing_lang_entry_mixed_lang_screen(void);
static void mmi_imesettings_writing_lang_save(void);
#if defined(__MMI_MIXED_LANG_SUPPORT__)&& !defined (__MMI_EDITOR_OPTION_MENU_STYLE_3__)
    static MMI_BOOL currWLangIsMain = MMI_TRUE;
    static U8 currWritingSubLangIdx = 0;
#endif /* __MMI_MIXED_LANG_SUPPORT__ */
#endif /* defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__) */ 


#ifdef __MMI_PREFER_INPUT_METHOD__
extern mmi_imm_input_mode_enum  MMI_all_prefered_input_mode_set[IMM_INPUT_MODE_MAX_NUM];
static U16 gnInputMethods = 0;
U16 currInputMethodIndex = 0;
void mmi_ime_settings_highlight_current_inputmethod(S32 index);
void mmi_imesettings_enter_screen_prefered_inputmethod();
void  mmi_imesettings_enter_screen_prefered_inputmethod_sg(mmi_id g_id);
#endif
#if defined (__MMI_IME_V3__)
static mmi_ret mmi_imesettings_main_menu_entry_handler(cui_menu_event_struct *param, MMI_ID parent_gid);
static mmi_ret mmi_imesettings_sub_menu_tap_handler(cui_menu_event_struct *param, MMI_ID parent_gid);
static void EntryAdvanceSetting(MMI_ID parent_gid);
extern void mmi_imesetting_set_menu_launch_param(void);
static mmi_ret mmi_ime_menu_handler_ext(mmi_event_struct *param);
static mmi_ret mmi_imesettings_wlang_confirm_callback_ext(mmi_event_struct *evt);
static void mmi_imesettings_writinglangscreenrskhandler_ext(void);
#if defined(__MMI_IME_PHONETIC_PREDICTION_SETTING__)
static void mmi_imesettings_association_entry_screen(mmi_id g_id);
#endif
#if defined(__MMI_IME_FUZZY_PINYIN__)

extern ime_fuzzy_pinyin_struct g_ime_fuzzy_pinyin_array[MAX_FUZZY_PINYIN];
extern U32 g_mmi_imm_enabled_fuzzy_pinyin;
extern U8 g_fuzzy_pinyin_state[MAX_FUZZY_PINYIN-1] ;
static void mmi_imesetting_fuzzy_pinyin_save(void);
static void mmi_imesettings_fuzzy_pinyin_setting_entry_screen(void);
static void mmi_imesettings_entry_fuzzy_pinyin_setting(mmi_id g_id);
#endif
typedef enum
{
	AUTO_SPC_AND_CAP_MENU = 0,
	FEEDBACK_SETTING_MENU,
	FUZZY_PINYIN_MENU,
	CONFIRM_POPUP_NONE
}confirm_popup_grp_enum ;
static confirm_popup_grp_enum g_confirm_popup ;
#if defined(__MMI_IME_AUTO_CAPITALIZATION_SETTING__) || defined(__MMI_IME_AUTO_SPACE_SETTING__)
#if defined(__MMI_IME_AUTO_CAPITALIZATION_SETTING__)
    #define IS_AUTO_CAPS_ENABLE (mmi_imm_memory_card_is_auto_capitalization_enabled())
#endif
enum auto_space_auto_cap
{
#if defined(__MMI_IME_AUTO_SPACE_SETTING__)
    AUTO_SPACE,
#endif
#if defined(__MMI_IME_AUTO_CAPITALIZATION_SETTING__)
    AUTO_CAP,
#endif
    IME_MAX_AUTO_CAP_ITEM_COUNT
};
#else
#define AUTO_SPACE 0
#define IME_MAX_AUTO_CAP_ITEM_COUNT 1
#endif

#define IME_MAX_FEEDBACK_ITEM_COUNT 2
U8 g_auto_cap_space_state[IME_MAX_AUTO_CAP_ITEM_COUNT] ;
U8 g_touch_feedback_state[IME_MAX_FEEDBACK_ITEM_COUNT] ;
#endif
extern void mmi_ime_commonscreens_lang_yes_hdlr(void);
#ifdef __MMI_IME_V3__
extern void mmi_ime_commonscreens_yes_hdlr(void);
#endif

extern void EntryKeyboardLanguageSettingScr(MMI_ID parent_gid);
extern void mmi_imesettings_save_screen(void );
extern void mmi_imm_write_prefered_writing_lang_to_nvram(void);
extern void mmi_ime_commonscreens_screen_close(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_settings_back
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_settings_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_scrn_close(mmi_frm_group_get_active_id(), mmi_frm_scrn_get_active_id());
}




#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imesettings_main_writing_lang_highlight
 * DESCRIPTION
 *  This function is highlight handler for Prefered WritingLang setting screen
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imesettings_writing_lang_highlight(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* update selected index */
#if defined __MMI_MIXED_LANG_SUPPORT__  && !defined (__MMI_EDITOR_OPTION_MENU_STYLE_3__)

    if (currWLangIsMain)
    {
        g_current_writinglang_index = (U8) index;
    }
    else
    {
        currWritingSubLangIdx = (U8) index;
    }
#else /* __MMI_MIXED_LANG_SUPPORT__ */
    g_current_writinglang_index = (U8) index;
#endif /* __MMI_MIXED_LANG_SUPPORT__ */

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imesettings_writing_lang_save
 * DESCRIPTION
 *  Save current preferred writing language and go back to prev screen
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imesettings_writing_lang_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 value; 
     mmi_popup_property_struct callback_popup;
 
#if defined(__MMI_MIXED_LANG_SUPPORT__) && !defined (__MMI_EDITOR_OPTION_MENU_STYLE_3__)
    U8 i, j;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_MIXED_LANG_SUPPORT__) && !defined (__MMI_EDITOR_OPTION_MENU_STYLE_3__)
    if (!currWLangIsMain)
    {
        /* if main language support mix language */
        if (g_ime_writing_lang_array[g_current_writinglang_index].mixed_lang_support)
        {
            i = 0;
            j = (U8) currWritingSubLangIdx;
            do
            {
                if (g_ime_writing_lang_array[i].mixed_lang_support)
                {
                    if (j == 0)
                        break;
                    j--;
                }
                i++;
            } while (g_ime_writing_lang_array[i - 1].lang_id != IME_WRITING_LANG_NONE);
            MMI_ASSERT(i < MAX_WRITING_LANG);
            value = g_ime_writing_lang_array[i].lang_id;
        }
        else
        {
            value = IME_WRITING_LANG_NONE;
        }

        mmi_imm_set_sub_lang((mmi_imm_support_writing_lang_enum)value);
        mmi_imm_write_prefered_sub_writing_lang_to_nvram();
    }
    else
#endif /* defined(__MMI_MIXED_LANG_SUPPORT__) */ 
    {
        MMI_ASSERT(g_current_writinglang_index < MAX_WRITING_LANG);
        value = g_ime_writing_lang_array[g_current_writinglang_index].lang_id;
        mmi_imm_set_main_lang((mmi_imm_support_writing_lang_enum)value);
        mmi_imm_write_prefered_writing_lang_to_nvram();
        value = g_ime_writing_lang_array[g_current_writinglang_index].default_input_mode;
        mmi_imm_set_prefer_input_mode((mmi_imm_input_mode_enum)value);
        mmi_imm_write_prefered_writing_lang_to_nvram();
#if defined __MMI_MIXED_LANG_SUPPORT__ && !defined (__MMI_EDITOR_OPTION_MENU_STYLE_3__)
        /* if main language not support mix language set sub language to NONE */
        if (!g_ime_writing_lang_array[g_current_writinglang_index].mixed_lang_support)
        {
            value = IME_WRITING_LANG_NONE;
            mmi_imm_set_sub_lang((mmi_imm_support_writing_lang_enum)value); 
            mmi_imm_write_prefered_sub_writing_lang_to_nvram();
        }
#endif /* __MMI_MIXED_LANG_SUPPORT__ */

    }
    mmi_imesettings_save_screen();
    mmi_popup_property_init(& callback_popup);
    callback_popup.parent_id = mmi_frm_group_get_active_id();
    callback_popup.callback = mmi_ime_settings_input_mode_screen_popup_handler_for_sg;
    mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS, &callback_popup);
   
   
}


#if !defined (__MMI_EDITOR_OPTION_MENU_STYLE_3__)

/*****************************************************************************
 * FUNCTION
 *  mmi_imesettings_writing_lang_entry_screen
 * DESCRIPTION
 *  Entry function for writing language screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imesettings_writing_lang_entry_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_id = mmi_frm_group_get_active_id();
    mmi_imesettings_writing_lang_entry_screen_with_sg(g_id);


}

/*****************************************************************************
 * FUNCTION
 *  mmi_imesettings_writing_lang_entry_screen_with_sg
 * DESCRIPTION
 *  Entry function for writing language screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imesettings_writing_lang_entry_screen_with_sg(mmi_id g_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type langList[MAX_WRITING_LANG];
    U8 *pGuiBuffer;
    U8 hilite_item = 0;
    U8 i;
    U8 totalLang = 0;
    U16 title_id = 0;

#if defined(__MMI_MIXED_LANG_SUPPORT__) &&!defined (__MMI_EDITOR_OPTION_MENU_STYLE_3__)
    U8 j;
    S16 currLangSetting = currWLangIsMain ? mmi_imm_get_main_lang() : mmi_imm_get_sub_lang();
#else /* defined(__MMI_MIXED_LANG_SUPPORT__) */ 
#define currLangSetting mmi_imm_get_main_lang()
#endif /* defined(__MMI_MIXED_LANG_SUPPORT__) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MIXED_LANG_SUPPORT__) && !defined (__MMI_EDITOR_OPTION_MENU_STYLE_3__)
    if (currWLangIsMain)    /* main language */
    {
        hilite_item = g_current_writinglang_index;
        title_id = STR_IME_SETTINGS_WRITING_LANGUAGE_MAIN;
    }
    else    /* sub language */
    {
        hilite_item = currWritingSubLangIdx;
        title_id = STR_IME_SETTINGS_WRITING_LANGUAGE_SUB;
    }
#else /* __MMI_MIXED_LANG_SUPPORT__ */
    hilite_item = g_current_writinglang_index;
    title_id = STR_IME_SETTINGS_WRITING_LANGUAGE;
#endif /* __MMI_MIXED_LANG_SUPPORT__ */

#if defined(__MMI_MIXED_LANG_SUPPORT__) && !defined (__MMI_EDITOR_OPTION_MENU_STYLE_3__)
    /* sub language list */
    if (!currWLangIsMain)
    {
        if (g_ime_writing_lang_array[g_current_writinglang_index].mixed_lang_support)
        {
            /* init sub writing language list with main language support mixed language */
            i = j = 0;
            do
            {
                if (g_ime_writing_lang_array[i].mixed_lang_support)
                {
                    langList[j] = g_ime_writing_lang_array[i].lang_str_ptr;
                    if (currLangSetting == g_ime_writing_lang_array[i].lang_id)
                    {
                        currWritingSubLangIdx = j;
                        hilite_item = currWritingSubLangIdx;
                    }
                    j++;
                }
                i++;
            } while (g_ime_writing_lang_array[i - 1].lang_id != IME_WRITING_LANG_NONE);
            totalLang = j;
        }
        else
        {
            i = 0;
            do
            {
                if (IME_WRITING_LANG_NONE == g_ime_writing_lang_array[i].lang_id)
                {
                    langList[0] = g_ime_writing_lang_array[i].lang_str_ptr;
                    hilite_item = 0;
                    break;
                }
                i++;
            } while (g_ime_writing_lang_array[i - 1].lang_id != IME_WRITING_LANG_NONE);
            totalLang = 1;
        }
    }
    else
#endif /* defined(__MMI_MIXED_LANG_SUPPORT__) */ 
    {
        /* init main writing language list */
        i = 0;
        do
        {
            langList[i] = g_ime_writing_lang_array[i].lang_str_ptr;

            if (currLangSetting == g_ime_writing_lang_array[i].lang_id)
            {
                g_current_writinglang_index = i;
                hilite_item=g_current_writinglang_index;
            }

            i++;
        } while (g_ime_writing_lang_array[i].lang_id != IME_WRITING_LANG_NONE); /* exclude None */
        totalLang = i;
    }

    MMI_ASSERT(totalLang <= MAX_WRITING_LANG);

    mmi_frm_scrn_enter(g_id , SCR_ID_PHNSET_PREFERRED_WRITING_LANG, NULL, mmi_imesettings_writing_lang_entry_screen, 0);

    /* Get current screen info into gui buffer  for history purposes */
    pGuiBuffer =  mmi_frm_scrn_get_active_gui_buf();
    /* Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(mmi_imesettings_writing_lang_highlight);
    /* Display Screen */
#ifdef __PLUTO_MMI_PACKAGE__
    ShowCategory36Screen(
        title_id,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        totalLang,
        (U8 **) langList,
        hilite_item,
        pGuiBuffer);
#endif 

    SetRightSoftkeyFunction(mmi_ime_settings_back, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_imesettings_writing_lang_save, KEY_EVENT_UP);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_imesettings_writing_lang_save, KEY_EVENT_UP);
    register_center_softkey_to_enter_key();
    redraw_center_softkey();  
    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imesettings_main_writing_lang_hint
 * DESCRIPTION
 *  This function is hint handling function
 *  for Phonesetup -> Writing language
 *  Functionality:
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imesettings_main_writing_lang_hint(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    mmi_imm_support_writing_lang_enum main_lang_id = mmi_imm_get_main_lang();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    while(g_ime_writing_lang_array[i].lang_id != IME_WRITING_LANG_NONE)
    {
        if(g_ime_writing_lang_array[i].lang_id == IME_WRITING_LANG_123)
            g_ime_writing_lang_array[i].lang_str_ptr = (UI_string_type)GetString(STR_ID_IME_WRITING_LANGUAGE_123);
        i++;
    }
    g_ime_writing_lang_array[i].lang_str_ptr = (UI_string_type)GetString(STR_GLOBAL_NONE);
    i = 0;
    do
    {
        if (main_lang_id == g_ime_writing_lang_array[i].lang_id)
        {
            mmi_ucs2cpy((S8*) hintData[index], (S8*) g_ime_writing_lang_array[i].lang_str_ptr);
            g_current_writinglang_index = i;
            return;
        }
        i++;
    } while (g_ime_writing_lang_array[i - 1].lang_id != IME_WRITING_LANG_NONE);

}


#else

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_advancedoptions_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void  mmi_imesettings_wlang_save()
{


    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
#ifndef __MMI_IME_FTE_ENHANCE__
    mmi_popup_property_struct callback_popup;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for ( i = 0 ; i < g_totalLang ; i ++)
    {
        mmi_imm_config_enabled_writing_languages(i ,g_writing_langItemListState[i] );
    }
    /* in case main language has now been disabled , set to English */
    if (! mmi_imm_is_enabled_wlang(mmi_imm_get_main_lang()))
    {
        mmi_imm_set_main_lang(IME_WRITING_LANG_ABC);
    }
#if defined(__MMI_MIXED_LANG_SUPPORT__)
    if(! mmi_imm_is_enabled_wlang(mmi_imm_get_sub_lang()))
    {
      mmi_imm_set_sub_lang(IME_WRITING_LANG_NONE);
    }
#endif
    #ifndef __MMI_IME_FTE_ENHANCE__
    mmi_popup_property_init(& callback_popup);
    callback_popup.parent_id = mmi_frm_group_get_active_id();
    mmi_imesettings_save_screen();

    callback_popup.callback = mmi_ime_settings_input_mode_screen_popup_handler_for_sg;
    mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS, &callback_popup);
    #endif
}



void mmi_imesettings_main_writing_lang_hint ()
{

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imesettings_writinglangscreencskhandler
 * DESCRIPTION
 *  Entry function for writing language screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_imesettings_writinglangscreencskhandler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /*  english cannot be disabled */
   if ( g_current_writinglang_index == 0 )
        return;
    standard_check_list_handle_item_select(g_current_writinglang_index);   
    if ( g_writing_langItemListState[g_current_writinglang_index])
        g_writing_langItemListState[g_current_writinglang_index] = MMI_FALSE;
    else
    g_writing_langItemListState[g_current_writinglang_index] = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imesettings_disable_menu_english
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

MMI_BOOL mmi_imesettings_disable_menu_english(S32 index, U32 *flag, U32 *flag_ex)
{
    if (index ==0 )
    {
        *flag |= UI_MENUITEM_STATE_DISABLED;
		*flag_ex |= UI_MENUITEM_EXT_SHOW_DISABLED ;
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imesettings_writing_lang_entry_screen
 * DESCRIPTION
 *  Entry function for writing language screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imesettings_writing_lang_entry_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_id = mmi_frm_group_get_active_id();
    mmi_imesettings_writing_lang_entry_screen_with_sg(g_id);


}

/*****************************************************************************
 * FUNCTION
 *  mmi_imesettings_wlang_confirm_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

mmi_ret mmi_imesettings_wlang_confirm_callback (mmi_event_struct *evt)
{
   /*--------------------------------------------------------------*/
   /* Local Variables                                                */
   /*--------------------------------------------------------------*/
   
   /*--------------------------------------------------------------*/
   /* Code Body                                                      */
   /*--------------------------------------------------------------*/
  switch (evt->evt_id)
   {
       case EVT_ID_ALERT_QUIT :
               {
                       mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct *)evt;
                       switch(alert->result)
                       {
                               case MMI_ALERT_CNFM_YES:
                                  /* to remove this popup */
					mmi_ime_commonscreens_lang_yes_hdlr();
				break;
				case MMI_ALERT_CNFM_NO:
				//#if !defined (__MMI_IME_V3__)
					mmi_ime_commonscreens_screen_close();
					mmi_ime_commonscreens_screen_close();
				//#endif
				break;
			}
		}
	}
	return MMI_RET_OK;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_lang_yes_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_lang_yes_hdlr(void)
{
	/*--------------------------------------------------------------*/
	/* Local Variables                                                */
	/*--------------------------------------------------------------*/
	mmi_popup_property_struct callback_popup;
   /*--------------------------------------------------------------*/
   /* Code Body                                                */
   /*--------------------------------------------------------------*/
    mmi_imesettings_wlang_save();
    mmi_ime_commonscreens_screen_close();

    mmi_popup_property_init(& callback_popup);
    callback_popup.parent_id = mmi_frm_group_get_active_id();
    mmi_imesettings_save_screen();

    callback_popup.callback = mmi_ime_settings_input_mode_screen_popup_handler_for_sg;
    mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS, &callback_popup);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_yes_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_IME_V3__
void mmi_ime_commonscreens_yes_hdlr(void)
{
    /*--------------------------------------------------------------*/
    /* Local Variables                                                */
    /*--------------------------------------------------------------*/
    mmi_popup_property_struct callback_popup;
    /*--------------------------------------------------------------*/
    /* Code Body                                              */
    /*--------------------------------------------------------------*/
    switch(g_confirm_popup)
    {
    case AUTO_SPC_AND_CAP_MENU: 
        {
#if defined(__MMI_IME_AUTO_SPACE_SETTING__)
            //Auto space and capitalization setting need to save here : interface neededs
            if (mmi_imm_memory_card_is_auto_space_enabled())
            {
                mmi_imm_config_auto_space((MMI_BOOL)g_auto_cap_space_state[AUTO_SPACE]);
            }                                 
#endif

#if defined(__MMI_IME_AUTO_CAPITALIZATION_SETTING__)
            if (IS_AUTO_CAPS_ENABLE)
            {
                mmi_imm_config_auto_capitalization((MMI_BOOL) g_auto_cap_space_state[AUTO_CAP]);
            }
#endif
        }
        break;
    case FEEDBACK_SETTING_MENU:
        {
            //Feedback setting need to save here : interface needed
            mmi_imm_config_vibration((MMI_BOOL)g_touch_feedback_state[0]);
            mmi_imm_config_sound_feedback((MMI_BOOL)g_touch_feedback_state[1]);
        }
        break ;
#if defined(__MMI_IME_FUZZY_PINYIN__)
    case FUZZY_PINYIN_MENU :
        {
            //Fuzzy pinyin setting need to save here : interface needed
            mmi_imesetting_fuzzy_pinyin_save();
        }
        break;
#endif
    case CONFIRM_POPUP_NONE:
    default:
        mmi_imesettings_wlang_save();
        break;
    }
    mmi_ime_commonscreens_screen_close();

    mmi_popup_property_init(& callback_popup);
    callback_popup.parent_id = mmi_frm_group_get_active_id();
    mmi_imesettings_save_screen();

    callback_popup.callback = mmi_ime_settings_input_mode_screen_popup_handler_for_sg;
    mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS, &callback_popup);
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_imesettings_writinglangscreenrskhandler
 * DESCRIPTION
 *  Entry function for writing language screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
   
void mmi_imesettings_writinglangscreenrskhandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_popup;
    mmi_confirm_property_init(&confirm_popup,CNFM_TYPE_YESNO);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

/* On the basis of selection in Popup */
    confirm_popup.f_auto_map_empty_softkey = MMI_FALSE;
    confirm_popup.parent_id = mmi_frm_group_get_active_id() ;
    confirm_popup.callback = mmi_imesettings_wlang_confirm_callback;
    mmi_confirm_display((UI_string_type)GetString(STR_GLOBAL_SAVE_ASK), MMI_EVENT_QUERY, &confirm_popup);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	SetCenterSoftkeyFunction(mmi_ime_commonscreens_lang_yes_hdlr, KEY_EVENT_UP);
	register_center_softkey_to_enter_key();
	redraw_center_softkey();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_imesettings_writing_lang_entry_screen_with_sg
 * DESCRIPTION
 *  Entry function for writing language screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imesettings_writing_lang_entry_screen_with_sg(mmi_id g_id)
{
	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type langList[MAX_WRITING_LANG];
    U8 *pGuiBuffer;
    U8 hilite_item = 0;
    U8 i;
    U16 title_id = 0;
	U16 title_icon = 0 ;
    U16  bitfield;
    bitfield = mmi_imm_get_enabled_writing_languages();

#define currLangSetting mmi_imm_get_main_lang()

	#ifdef __PLUTO_MMI_PACKAGE__
	title_icon = MAIN_MENU_TITLE_SETTINGS_ICON ;
	#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //#ifndef __COSMOS_MMI_PACKAGE__
    #if 1
#ifdef __MMI_IME_V3__
	title_id = STR_ID_ML_SETTING ;
#else
    title_id = STR_IME_SETTINGS_WRITING_LANGUAGE;
#endif

    {
        /* init main writing language list */
        i = 0;
        do
        {
            langList[i] = g_ime_writing_lang_array[i].lang_str_ptr;

            if (currLangSetting == g_ime_writing_lang_array[i].lang_id)
                g_current_writinglang_index = i;

            i++;
        } while (g_ime_writing_lang_array[i].lang_id != IME_WRITING_LANG_123 && i < MAX_WRITING_LANG); /* exclude None */
        g_totalLang = i;
    }

    MMI_ASSERT(g_totalLang <= MAX_WRITING_LANG);
    mmi_frm_scrn_enter(g_id , SCR_ID_PHNSET_PREFERRED_WRITING_LANG, NULL, mmi_imesettings_writing_lang_entry_screen, MMI_FRM_UNKNOW_SCRN);

    /* Get current screen info into gui buffer  for history purposes */
    pGuiBuffer =  mmi_frm_scrn_get_active_gui_buf();
    /* Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(mmi_imesettings_writing_lang_highlight);
    /* Display Screen */
	if (!pGuiBuffer)
	{
    for ( i = 0 ; i < g_totalLang ; i++)
    {
        g_writing_langItemListState[i] = (bitfield >> ( 15 -i)) & 0x1;

		}
    }
/* to make sure english cannot be  disabled */
    wgui_fixed_list_register_get_flags_handler(mmi_imesettings_disable_menu_english);
	if(g_totalLang == 1)
	{
		/*Only English Language Enable User cant off this language so for change feature better to just show this option to 
		user with rsk as Back key only No rsk and center key rsp*/
  //#ifdef __PLUTO_MMI_PACKAGE__
    ShowCategory12Screen(title_id, 
                        title_icon, 
						0,
                        0,
                        STR_GLOBAL_BACK,
                        IMG_GLOBAL_BACK,
                        g_totalLang,
                        (U8 **) langList,
                        g_writing_langItemListState,
                        0, 
                        pGuiBuffer);
 //#endif 
    SetRightSoftkeyFunction(mmi_ime_settings_back, KEY_EVENT_UP);
			return ;
	}
#ifndef __MMI_IME_FTE_ENHANCE__
  #ifdef __PLUTO_MMI_PACKAGE__
    ShowCategory12Screen(title_id, 
                        title_icon, 
                        STR_GLOBAL_SAVE,
                        0,
                        STR_GLOBAL_BACK,
                        IMG_GLOBAL_BACK,
                        g_totalLang,
                        (U8 **) langList,
                        g_writing_langItemListState,
                        0, 
                        pGuiBuffer);
 #endif 
    #ifdef __MMI_TOUCH_SCREEN__

    MMI_fixed_list_menu.disable_up_select = MMI_FALSE;                 
    wgui_register_list_tap_callback(mmi_imesettings_writinglangscreencskhandler);
    #endif
    SetRightSoftkeyFunction(mmi_ime_settings_back, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_imesettings_wlang_save, KEY_EVENT_UP);
    EnableCenterSoftkey(0, IMG_GLOBAL_MARK_CSK);
    SetCenterSoftkeyFunction(mmi_imesettings_writinglangscreencskhandler, KEY_EVENT_UP);
    register_center_softkey_to_enter_key();
    redraw_center_softkey();
#else
#ifdef __MMI_IME_V3__
	SetCheckboxToggleRightSoftkeyFunctions(mmi_imesettings_writinglangscreenrskhandler_ext,mmi_ime_settings_back);
#else
	SetCheckboxToggleRightSoftkeyFunctions(mmi_imesettings_writinglangscreenrskhandler,mmi_ime_settings_back);
#endif
	//#ifdef __PLUTO_MMI_PACKAGE__
	ShowCategory140Screen(
        title_id,
        title_icon,
        g_totalLang,
        (U8 **) langList,
        g_writing_langItemListState,
        0,
        pGuiBuffer);
  // #endif
#endif  /* __COSMOS_MMI_PACKAGE__ */

	#endif

}

#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_imesettings_writing_lang_highlighthandler
 * DESCRIPTION
 *  This function is highlight handler for Preferred WritingLang setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imesettings_writing_lang_highlighthandler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
#if defined(__MMI_MIXED_LANG_SUPPORT__)  && !defined (__MMI_EDITOR_OPTION_MENU_STYLE_3__)
    SetLeftSoftkeyFunction(mmi_imesettings_writing_lang_entry_mixed_lang_screen, KEY_EVENT_UP);
#else /* defined(__MMI_MIXED_LANG_SUPPORT__) */ 
    SetLeftSoftkeyFunction(mmi_imesettings_writing_lang_entry_screen, KEY_EVENT_UP);
#endif /* defined(__MMI_MIXED_LANG_SUPPORT__) */ 
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
#if defined(__MMI_MIXED_LANG_SUPPORT__)&& !defined (__MMI_EDITOR_OPTION_MENU_STYLE_3__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imesettings_main_writing_lang_highlight
 * DESCRIPTION
 *  This function is highlight handler for Prefered WritingLang setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imesettings_main_writing_lang_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_imesettings_writing_lang_entry_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    currWLangIsMain = MMI_TRUE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_imesettings_sub_writing_lang_highlight
 * DESCRIPTION
 *  This function is highlight handler for Prefered WritingLang setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imesettings_sub_writing_lang_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imesettings_main_writing_lang_highlight();
    currWLangIsMain = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imesettings_sub_writing_lang_hint
 * DESCRIPTION
 *  This function is hint handling function
 *  for Phonesetup -> Sub Writing language
 *  Functionality:
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imesettings_sub_writing_lang_hint(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    mmi_imm_support_writing_lang_enum sub_lang_id = mmi_imm_get_sub_lang();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ime_writing_lang_array[g_current_writinglang_index].mixed_lang_support)
    {
        do
        {
            if (sub_lang_id == g_ime_writing_lang_array[i].lang_id)
            {
                mmi_ucs2cpy((S8*) hintData[index], (S8*) g_ime_writing_lang_array[i].lang_str_ptr);
                currWritingSubLangIdx = i;
                return;
            }
            i++;
        } while (g_ime_writing_lang_array[i - 1].lang_id != IME_WRITING_LANG_NONE);
    }
    else
    {
        do
        {
            if (IME_WRITING_LANG_NONE == g_ime_writing_lang_array[i].lang_id)
            {
                mmi_ucs2cpy((S8*) hintData[index], (S8*) g_ime_writing_lang_array[i].lang_str_ptr);
                currWritingSubLangIdx = i;
                return;
            }
            i++;
        } while (g_ime_writing_lang_array[i - 1].lang_id != IME_WRITING_LANG_NONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imesettings_writing_lang_entry_mixed_lang_screen
 * DESCRIPTION
 *  Entry function
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imesettings_writing_lang_entry_mixed_lang_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[4];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;         /* Stores no of children in the submenu */
    U16 nDispAttribute;     /* Stores display attribue */
    U8 *guiBuffer;          /* Buffer holding history data */
    U8 *ItemType[4];
    U8 *StringItem[4];
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Call Exit Handler */
    EntryNewScreen(SCR_ID_PHNSET_MIXED_LANG, NULL, mmi_imesettings_writing_lang_entry_mixed_lang_screen, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer =  mmi_frm_scrn_get_active_gui_buf();

    /* 3. Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild_Ext(MENU_ID_PHNSET_PREFERED_WRITING_LANG);
    MMI_ASSERT(nNumofItem <= 4);

    /* 4. Get attribute of menu to be displayed */
    nDispAttribute = GetDispAttributeOfItem(MENU_ID_PHNSET_PREFERED_WRITING_LANG);

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds_Ext(MENU_ID_PHNSET_PREFERED_WRITING_LANG, nStrItemList);
    for (i = 0; i < nNumofItem; i++)
        StringItem[i] = (U8*) GetString(nStrItemList[i]);

    /* 6 Set current parent id */
    SetParentHandler(MENU_ID_PHNSET_PREFERED_WRITING_LANG);

    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 8 Construct the Hints List */
    ConstructHintsList(MENU_ID_PHNSET_PREFERED_WRITING_LANG, ItemType);

    #ifdef __PLUTO_MMI_PACKAGE__
    ShowCategory354Screen(
        (U8*) GetString(STR_IME_SETTINGS_WRITING_LANGUAGE),
        MAIN_MENU_TITLE_SETTINGS_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        StringItem,
        ItemType,
        (PU16) gIndexIconsImageList,
        0,
        guiBuffer);
    #endif 

    /* 9.Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}
#endif /* defined(__MMI_MIXED_LANG_SUPPORT__) */ 
#endif /* defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__) */ 


#ifdef __MMI_PREFER_INPUT_METHOD__

/*****************************************************************************
 * FUNCTION
 *  mmi_imesettings_init_prefered_inputmethod_list
 * DESCRIPTION
 *  initialization function for input method screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imesettings_init_prefered_inputmethod_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imm_get_prefer_input_mode_list(MMI_all_prefered_input_mode_set, IMM_INPUT_MODE_MAX_NUM);
    gnInputMethods = mmi_imm_get_prefer_input_mode_string_list(inputMethodList, IMM_INPUT_MODE_MAX_NUM);    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_settings_inputmethodsettings_highlight
 * DESCRIPTION
 *  highlight handler for input method selection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_settings_inputmethodsettings_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetLeftSoftkeyFunction(mmi_imesettings_enter_screen_prefered_inputmethod, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imesettings_enter_screen_prefered_inputmethod
 * DESCRIPTION
 *  Entry function for input method screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imesettings_enter_screen_prefered_inputmethod()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_id = mmi_frm_group_get_active_id();
    mmi_imesettings_enter_screen_prefered_inputmethod_sg(g_id);


}
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_set_pref_input_mode_menu_hint
 * DESCRIPTION
 *  Entry function for input method screen
 * PARAMETERS
 *  MMI_ID menucui_id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_set_pref_input_mode_menu_hint(MMI_ID menucui_id)
{
#ifndef __COSMOS_MMI_PACKAGE__
	/*----------------------------------------------------------------*/
	/* Local Variables																		 */
	/*----------------------------------------------------------------*/
    U32 i ;
    mmi_imm_input_mode_enum input_mode = 0;
    const sIMEModeDetails * mode_detail; 
    /*----------------------------------------------------------------*/
    /* Code Body																		     */
    /*----------------------------------------------------------------*/
	mmi_imesettings_init_prefered_inputmethod_list();
    mmi_imm_get_prefer_input_mode_list(MMI_all_prefered_input_mode_set, IMM_INPUT_MODE_MAX_NUM);
	i = 0;
    input_mode = mmi_imm_get_prefer_input_mode();
    if(input_mode == IMM_INPUT_MODE_NONE)
        input_mode = mmi_imm_get_current_input_mode();

    mode_detail = mmi_imm_get_input_mode_array_item(input_mode);
    #if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
    if (!mmi_imm_is_smart_alphabetic_input_modes_enabled())
    {
        mode_detail = mmi_imm_get_corresponding_multitap_mode(mode_detail->imm_mode_id, mode_detail->Mode_Special_Attrib & IME_MODE_CASE_MASK);
    }
    MMI_ASSERT(mode_detail);
    #endif
    while (MMI_all_prefered_input_mode_set[i] != mode_detail->imm_mode_id)
    {
        if (MMI_all_prefered_input_mode_set[i] == IMM_INPUT_MODE_NONE)
        {
            i = 0;
            break;
        }
        else
        {
            i++;
        }

    }
	//Set the default input method in case when dont get set input method
	if(MMI_all_prefered_input_mode_set[i] == IMM_INPUT_MODE_NONE)
	{
		i = 0;
	}
	cui_menu_set_item_hint(
		menucui_id,
		MENU_SETTING_PREFERED_INPUT_METHOD,
		(WCHAR*)inputMethodList[i]);
#endif
}
/*****************************************************************************
 * FUNCTION
 *  mmi_imesettings_enter_screen_prefered_inputmethod_sg
 * DESCRIPTION
 *  Entry function for input method screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void  mmi_imesettings_enter_screen_prefered_inputmethod_sg(mmi_id g_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *pGuiBuffer;
    U32 i;
    const sIMEModeDetails * mode_detail = mmi_imm_get_input_mode_array_item(mmi_imm_get_prefer_input_mode()); 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imesettings_init_prefered_inputmethod_list();

    i = 0;
    #if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
    if (!mmi_imm_is_smart_alphabetic_input_modes_enabled())
    {
        mode_detail = mmi_imm_get_corresponding_multitap_mode(mode_detail->imm_mode_id, mode_detail->Mode_Special_Attrib & IME_MODE_CASE_MASK);
    }
    MMI_ASSERT(mode_detail);
    #endif
    while (MMI_all_prefered_input_mode_set[i] != mode_detail->imm_mode_id)
    {
        if (MMI_all_prefered_input_mode_set[i] == IMM_INPUT_MODE_NONE)
        {
            i = 0;
            break;
        }
        else
        {
            i++;
        }

    }
    currInputMethodIndex = i;
    mmi_frm_scrn_enter(g_id , SCR_INPUT_METHOD_SELECTION, NULL, mmi_imesettings_enter_screen_prefered_inputmethod, 0);
    pGuiBuffer =  mmi_frm_scrn_get_active_gui_buf();
    RegisterHighlightHandler(mmi_ime_settings_highlight_current_inputmethod);
    
    #ifdef __PLUTO_MMI_PACKAGE__
    ShowCategory36Screen(
        STR_MENU_INPUT_METHOD,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        gnInputMethods,
        (U8 **) inputMethodList,
        currInputMethodIndex,
        pGuiBuffer);
   #endif 
    SetRightSoftkeyFunction(mmi_ime_settings_back, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_imesettings_select_inputmethod_handler, KEY_EVENT_UP);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_imesettings_select_inputmethod_handler, KEY_EVENT_UP);
    register_center_softkey_to_enter_key();
    redraw_center_softkey();  
    return;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_ime_settings_highlight_current_inputmethod
 * DESCRIPTION
 *  upate selected index
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_settings_highlight_current_inputmethod(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    currInputMethodIndex = (U8) index;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imesettings_select_inputmethod_handler
 * DESCRIPTION
 *  Exit function for input method screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imesettings_select_inputmethod_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 data;
    S16 error;
    U16 index;
    mmi_popup_property_struct callback_popup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetCurrHiliteID();
    mmi_imm_set_inputmethod(currInputMethodIndex);
    mmi_imm_write_prefered_input_method_to_nvram(mmi_imm_get_prefer_input_mode());
    mmi_ucs2cpy((PS8) hintData[index], (PS8) inputMethodList[currInputMethodIndex]);
    RedrawCategoryFunction();
    Category52ChangeItemDescription(index, hintData[index]);
    mmi_imesettings_save_screen();
    mmi_popup_property_init(& callback_popup);
    callback_popup.parent_id = mmi_frm_group_get_active_id();
    callback_popup.callback = mmi_ime_settings_input_mode_screen_popup_handler_for_sg;
    mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, &callback_popup);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imesettings_get_inputmethodindex
 * DESCRIPTION
 *  function that return input method index 
 * PARAMETERS
 *  inputType       [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_imesettings_get_inputmethodindex(U16 inputType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    while (MMI_all_prefered_input_mode_set[i] != inputType)
    {
        if (MMI_all_prefered_input_mode_set[i] == IMM_INPUT_MODE_NONE)
        {
            i = 0;
            break;
        }
        else
        {
            i++;
        }

    }
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imesettings_init_prefered_inputmethod
 * DESCRIPTION
 *  initialization function for input method screen
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imesettings_init_prefered_inputmethod(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gnInputMethods = mmi_imm_get_prefer_input_mode_string_list(inputMethodList, IMM_INPUT_MODE_MAX_NUM);    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HintPhnsetPreferedInputMethod
 * DESCRIPTION
 *  This function is hint handling function
 *  for Phonesetup -> Language
 *  Functionality:
 * PARAMETERS
 *  index       [IN]            
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/

void HintPhnsetPreferedInputMethod(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U16 data = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imesettings_init_prefered_inputmethod();
    mmi_ucs2cpy ( (PS8) hintData[index], (PS8) inputMethodList[mmi_imesettings_get_inputmethodindex(mmi_imm_get_prefer_input_mode())] );
    return;
}

#endif /* __MMI_PREFER_INPUT_METHOD__ */ 

#if defined (__MMI_MIXED_LANG_SUPPORT__) || defined (__MMI_PREFER_WRITING_LANG__) || defined  (__MMI_PREFER_INPUT_METHOD__) || defined (__MMI_IME_PLUG_IN_SETTING__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imesettings_menu_handler
 * DESCRIPTION
 *  Phonesettings event handler for Mixed,prefered langauge and prefered input mode
 * PARAMETERS
 *  cui_menu_event_struct       [IN]    event structure        
 *  MMI_ID        [IN]       parent id 
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_imesettings_menu_handler(cui_menu_event_struct *evt, MMI_ID parent_gid)
{

	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    mmi_ret ret = MMI_RET_OK;
    S32 list_num = 0;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_ITEM_SELECT:
#ifndef __COSMOS_MMI_PACKAGE__
#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
#ifndef __MMI_IME_V3__
        if (menu_evt->highlighted_menu_id == MENU_ID_PHNSET_PREFERED_WRITING_LANG)
        {
            mmi_imesettings_writing_lang_entry_screen_with_sg(parent_gid);
            return MMI_RET_OK;
        }
#endif
#endif

#if defined  (__MMI_PREFER_INPUT_METHOD__)
        if (menu_evt->highlighted_menu_id == MENU_SETTING_PREFERED_INPUT_METHOD)
        {
            mmi_imesettings_enter_screen_prefered_inputmethod_sg(parent_gid);
            return MMI_RET_OK;
        }
#endif
#endif 

#if defined(__MMI_IME_PLUG_IN_SETTING__)
        if (menu_evt->highlighted_menu_id == MENU_SETTING_SDK_IME_SETTING)
        {
            mmi_ime_sdk_call_setting_cb(parent_gid);
            return MMI_RET_OK;
        }
#endif
        break;

    default:
        break;
    }
    return MMI_RET_DONT_CARE;

}
#endif
#if defined (__MMI_IME_V3__)
mmi_ret mmi_imesettings_menu_handler_ext(cui_menu_event_struct *evt, MMI_ID parent_gid)
{
   switch (evt->evt_id)
    {
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        return mmi_imesettings_main_menu_entry_handler(evt, parent_gid);
    case EVT_ID_CUI_MENU_ITEM_SELECT:
    case EVT_ID_CUI_MENU_ITEM_TAP:
         return mmi_imesettings_sub_menu_tap_handler(evt, parent_gid);
    default:
        break;
    }
    return MMI_RET_DONT_CARE;
}
static mmi_ret mmi_imesettings_main_menu_entry_handler(cui_menu_event_struct *param, MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param->parent_menu_id == MENU_ITEM_IME_SETTING /*||
		param->parent_menu_id == MENU_ID_ADVANCE_SETTING*/)
    {
#ifdef __MMI_HANDWRITING_MEMORY_CARD_SUPPORT__
        if(!mmi_imm_get_handwriting_setting()/*!mmi_imc_is_handwriting_disabled()*/)
		{
		    MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_IMESETTINGS_MAIN_MENU_ENTRY_HANDLER);
			cui_menu_set_item_hidden(param->sender_id, MENU_ID_HW_SETTING, MMI_TRUE);
			cui_menu_set_item_hidden(param->sender_id, MENU_ID_FOLO_KEYBRD, MMI_TRUE);
		}
#endif

#if defined (__MMI_IME_AUTO_CAPITALIZATION_SETTING__) && defined(__MMI_IME_AUTO_SPACE_SETTING__)
        if (!(mmi_imm_memory_card_is_auto_capitalization_enabled() || mmi_imm_is_auto_space_enabled()))
        {
            cui_menu_set_item_hidden(param->sender_id, MENU_ID_ENGLISH_SETTING, MMI_TRUE);
        }
#elif defined (__MMI_IME_AUTO_CAPITALIZATION_SETTING__) && !defined(__MMI_IME_AUTO_SPACE_SETTING__)
        if (!mmi_imm_memory_card_is_auto_capitalization_enabled())
        {
            cui_menu_set_item_hidden(param->sender_id, MENU_ID_ENGLISH_SETTING, MMI_TRUE);
        }

#elif !defined (__MMI_IME_AUTO_CAPITALIZATION_SETTING__) && defined(__MMI_IME_AUTO_SPACE_SETTING__)
        if (!mmi_imm_memory_card_is_auto_space_enabled())
        {
            cui_menu_set_item_hidden(param->sender_id, MENU_ID_ENGLISH_SETTING, MMI_TRUE);
        }
#endif
        mmi_imesetting_set_menu_launch_param();
        return MMI_RET_OK;
    }
#if defined(__MMI_IME_PHONETIC_PREDICTION_SETTING__) || defined(__MMI_IME_FUZZY_PINYIN__)
	else if(param->parent_menu_id == MENU_ID_CHINESE_SETTING)
	{
		cui_menu_set_currlist_flags(param->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
		 return MMI_RET_OK;
	}
#endif
    return MMI_RET_DONT_CARE;
}

void mmi_imesetting_set_menu_launch_param(void)
{
	MMI_ID get_active_id = mmi_frm_group_get_active_id();
    //cui_menu_set_currlist_title(get_active_id, (WCHAR*) GetString(STR_MENU_INPUT_METHOD), NULL);
    cui_menu_set_currlist_flags(get_active_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
	cui_menu_set_currlist_left_softkey(get_active_id, (WCHAR*)GetString(STR_GLOBAL_OK));
    cui_menu_set_currlist_right_softkey(get_active_id, (WCHAR*)GetString(STR_GLOBAL_BACK));  
}
static void mmi_imesettings_entry_feedback_setting(mmi_id g_id);
static void mmi_imesettings_feedback_setting_entry_screen(void);


static void mmi_imesettings_entry_space_capitalization_setting(mmi_id g_id);
static void mmi_imesettings_space_capitalization_entry_screen(void);

#if defined(__MMI_IME_FUZZY_PINYIN__)
static void mmi_imesettings_fuzzy_pinyin_setting_entry_screen(void)
{
	mmi_id g_id ;
    /*mmi_frm_group_create(
        GRP_ID_ROOT,
		//parent_gid,
        GRP_ID_FUZZY_PINYIN_MENU,
        mmi_ime_menu_handler_ext,
        NULL);
    
    mmi_frm_group_enter(GRP_ID_FUZZY_PINYIN_MENU, MMI_FRM_NODE_SMART_CLOSE_FLAG); */
	g_id = mmi_frm_group_get_active_id();
	mmi_imesettings_entry_fuzzy_pinyin_setting(g_id);
}

U8 temp_langList[IME_FUZZY_PINYIN_MAX][20]= {0,} ;
static void mmi_imesettings_entry_fuzzy_pinyin_setting(mmi_id g_id)
{
	U16 title_id = STR_ID_FUZZY_PINYIN;
	U8 index = 0 ;
	U32 fuzzy_str_len ;
	/*Max fuzzy pinyin item list count*/
	U8 fuzzy_max_count = IME_FUZZY_PINYIN_MAX ;
	
	/*Get All Item state and String*/
	U8 *langList[IME_FUZZY_PINYIN_MAX] ;
    for(index ; index <IME_FUZZY_PINYIN_MAX ; index++)
	{
		//need to reset the fuzzy selection array
		g_fuzzy_pinyin_state[index] = 0 ;
		 fuzzy_str_len = strlen(g_ime_fuzzy_pinyin_array[index].fuzzy_str_ptr) ;
		 mmi_asc_n_to_ucs2((CHAR *)&temp_langList [index], (CHAR*)(g_ime_fuzzy_pinyin_array[index].fuzzy_str_ptr),fuzzy_str_len);
		 langList[index] = &temp_langList [index][0] ;
		if(g_mmi_imm_enabled_fuzzy_pinyin & g_ime_fuzzy_pinyin_array[index].fuzzy_id)
		{
			g_fuzzy_pinyin_state[index] = 1 ;
		}
	}

	//UI_string_type langList[3] = {L"Auto sapce", L"Auto capitalization", L"Association"};
	mmi_frm_scrn_enter(g_id , GRP_ID_AUTO_SPC_AND_CAP_MENU, NULL, mmi_imesettings_fuzzy_pinyin_setting_entry_screen, 0);
	
	SetCheckboxToggleRightSoftkeyFunctions(mmi_imesettings_writinglangscreenrskhandler_ext,mmi_ime_settings_back);
	ShowCategory140Screen(
        title_id,
        NULL,//MAIN_MENU_TITLE_SETTINGS_ICON,
        fuzzy_max_count,
        (U8 **) langList,
        g_fuzzy_pinyin_state,
        0,
        mmi_frm_scrn_get_active_gui_buf());
}

void mmi_imesetting_fuzzy_pinyin_save(void)
{
	U8 index ;
	U32 data ;
	U16 error ;
	for(index=0 ; index < IME_FUZZY_PINYIN_MAX ; index++)
	{
		if (g_fuzzy_pinyin_state[index] == 0)
		{
			g_mmi_imm_enabled_fuzzy_pinyin &= ~g_ime_fuzzy_pinyin_array[index].fuzzy_id;
		}
		else
		{
			g_mmi_imm_enabled_fuzzy_pinyin |= (g_ime_fuzzy_pinyin_array[index].fuzzy_id);
		}
	}
	data = g_mmi_imm_enabled_fuzzy_pinyin;
	WriteValue((U16)NVRAM_SETTING_ENABLED_FUZZY_PINYIN, (void*)&data, (U8)DS_SHORT, (S16*)&error);
}

#endif

#if defined(__MMI_IME_PHONETIC_PREDICTION_SETTING__)
 static U16 association_highlighted_index ;
 void mmi_imesettings_association_hilite_handler(S32 index)
{
    association_highlighted_index = (U8) index;
    return;
}

  void mmi_imesettings_select_association_handler(void)
 {
		mmi_popup_property_struct callback_popup;
		if(association_highlighted_index)
		{
			mmi_imm_config_chinese_word_prediction(MMI_FALSE);
		}
		else
		{
			mmi_imm_config_chinese_word_prediction(MMI_TRUE);
		}
		mmi_imesettings_save_screen();
		mmi_popup_property_init(& callback_popup);
		callback_popup.parent_id = mmi_frm_group_get_active_id();
		callback_popup.callback = mmi_ime_settings_input_mode_screen_popup_handler_for_sg;
		mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, &callback_popup);
 }

static void mmi_imesettings_association_entry_screen_ext(void);
void mmi_imesettings_association_entry_screen(mmi_id g_id)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *pGuiBuffer;
	U8 *itemlist[2];
	U8 item_count ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //get total item count
   item_count = 2;
 
   //get all  strings
	itemlist[0] = (U8*) GetString((U16)(STR_GLOBAL_ON ));
	itemlist[1] = (U8*) GetString((U16)(STR_GLOBAL_OFF));

   //get highlighted index
	if(mmi_imm_is_chinese_word_prediction_enabled() )
	{
		association_highlighted_index = 0 ;
	}
	else
	{
		association_highlighted_index = 1 ;
	}

    mmi_frm_scrn_enter(g_id , GRP_ID_ADVANCE_SETTING_MENU, NULL, mmi_imesettings_association_entry_screen_ext, MMI_FRM_UNKNOW_SCRN);
    pGuiBuffer =  mmi_frm_scrn_get_active_gui_buf();
    RegisterHighlightHandler(mmi_imesettings_association_hilite_handler);
    
    ShowCategory36Screen(
        STR_ID_IME_ASSOCIATION,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        2,
        (U8 **) itemlist,
        association_highlighted_index,
        pGuiBuffer);
  
    SetRightSoftkeyFunction(mmi_ime_settings_back, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_imesettings_select_association_handler, KEY_EVENT_UP);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_imesettings_select_association_handler, KEY_EVENT_UP);
    register_center_softkey_to_enter_key();
    redraw_center_softkey();  
    return;
}

static void mmi_imesettings_association_entry_screen_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_id = mmi_frm_group_get_active_id();
    mmi_imesettings_association_entry_screen(g_id);
}

#endif
static void mmi_imesettings_feedback_setting_entry_screen(void)
{
	mmi_id g_id ;
    mmi_frm_group_create(
        GRP_ID_ROOT,
		//parent_gid,
        GRP_ID_FEEDBACK_SETTING_MENU,
        mmi_ime_menu_handler_ext,
        NULL);

    mmi_frm_group_enter(GRP_ID_FEEDBACK_SETTING_MENU, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	g_id = mmi_frm_group_get_active_id();
	mmi_imesettings_entry_feedback_setting(g_id);
}

static void mmi_imesettings_space_capitalization_entry_screen(void)
{
	mmi_id g_id ;
    mmi_frm_group_create(
        mmi_frm_group_get_active_id(),
		//GRP_ID_ROOT,
		//parent_gid,
        GRP_ID_AUTO_SPC_AND_CAP_MENU,
        mmi_ime_menu_handler_ext,
        NULL);
    
    mmi_frm_group_enter(GRP_ID_AUTO_SPC_AND_CAP_MENU, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	g_id = mmi_frm_group_get_active_id();
	mmi_imesettings_entry_space_capitalization_setting(g_id);
}

static void mmi_imesettings_entry_feedback_setting(mmi_id g_id)
{
	U16 title_id = STR_ID_TOUCH_FEEDBACK;
	UI_string_type* langList[IME_MAX_FEEDBACK_ITEM_COUNT] ;
	langList[0] = (UI_string_type*) GetString((U16)(STR_ID_IME_VIBRATION));
	langList[1] = (UI_string_type*) GetString((U16)(STR_ID_IME_SOUND_FEEDBACK));
	g_touch_feedback_state[0] = (U8)mmi_imm_is_vibration_enabled();
	g_touch_feedback_state[1] = (U8)mmi_imm_is_sound_feedback_enabled();
	mmi_frm_scrn_enter(g_id , GRP_ID_FEEDBACK_SETTING_MENU, NULL, mmi_imesettings_feedback_setting_entry_screen, MMI_FRM_UNKNOW_SCRN);
	SetCheckboxToggleRightSoftkeyFunctions(mmi_imesettings_writinglangscreenrskhandler_ext,mmi_ime_settings_back);
	ShowCategory140Screen(
        title_id,
        0,//MAIN_MENU_TITLE_SETTINGS_ICON,
        2,
        (U8 **) langList,
        g_touch_feedback_state,
        0,
        mmi_frm_scrn_get_active_gui_buf());
}
static void mmi_imesettings_entry_space_capitalization_setting_ext(void);
static void mmi_imesettings_entry_space_capitalization_setting(mmi_id g_id)
{
	U16 title_id = STR_ID_ENGLISH_SETTING;
	U8 is_auto_space_enable ;
	U8 is_Auto_cap_enable ;
    U32 index = 0;
	UI_string_type* langList[IME_MAX_AUTO_CAP_ITEM_COUNT] ;
#if defined(__MMI_IME_AUTO_CAPITALIZATION_SETTING__) && defined(__MMI_IME_AUTO_SPACE_SETTING__)
    if (mmi_imm_memory_card_is_auto_space_enabled())
    {
        is_auto_space_enable = (U8)mmi_imm_is_auto_space_enabled() ;
        g_auto_cap_space_state[AUTO_SPACE] = is_auto_space_enable ; 
        langList[AUTO_SPACE] = (UI_string_type*) GetString((U16)(STR_ID_IME_AUTO_SPACE));
        index ++;
    }
    if (IS_AUTO_CAPS_ENABLE)
    {
        is_Auto_cap_enable  = (U8)mmi_imm_is_auto_capitalization_enabled();
        g_auto_cap_space_state[AUTO_CAP] = is_Auto_cap_enable ;
        langList[AUTO_CAP] = (UI_string_type*) GetString((U16)(STR_INPUT_METHOD_AUTO_CAPITALIZATION));
        index ++;
    }
#elif defined(__MMI_IME_AUTO_CAPITALIZATION_SETTING__)
    if (IS_AUTO_CAPS_ENABLE)
    {
        is_Auto_cap_enable  = (U8)mmi_imm_is_auto_capitalization_enabled();
        g_auto_cap_space_state[AUTO_CAP] = is_Auto_cap_enable ;
        langList[AUTO_CAP] = (UI_string_type*) GetString((U16)(STR_INPUT_METHOD_AUTO_CAPITALIZATION));
        index ++;
    }
#elif defined(__MMI_IME_AUTO_SPACE_SETTING__)
    if (mmi_imm_memory_card_is_auto_space_enabled())
    {
        is_auto_space_enable = (U8)mmi_imm_is_auto_space_enabled() ;
        g_auto_cap_space_state[AUTO_SPACE] = is_auto_space_enable ; 
        langList[AUTO_SPACE] = (UI_string_type*) GetString((U16)(STR_ID_IME_AUTO_SPACE));
        index ++;
    }
#else
    langList[AUTO_SPACE] = NULL;
#endif

	mmi_frm_scrn_enter(g_id , GRP_ID_AUTO_SPC_AND_CAP_MENU, NULL, mmi_imesettings_entry_space_capitalization_setting_ext, MMI_FRM_UNKNOW_SCRN);
	SetCheckboxToggleRightSoftkeyFunctions(mmi_imesettings_writinglangscreenrskhandler_ext,mmi_ime_settings_back);
	ShowCategory140Screen(
        title_id,
        0,//MAIN_MENU_TITLE_SETTINGS_ICON,
        index,//IME_MAX_AUTO_CAP_ITEM_COUNT
        (U8 **) langList,
        g_auto_cap_space_state,
        0,
        mmi_frm_scrn_get_active_gui_buf());
}
static void mmi_imesettings_entry_space_capitalization_setting_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_id = mmi_frm_group_get_active_id();
    mmi_imesettings_entry_space_capitalization_setting(g_id);
}

static mmi_ret mmi_imesettings_sub_menu_tap_handler(cui_menu_event_struct *param, MMI_ID parent_gid)
{
	 switch(param->highlighted_menu_id)
	 {
		case MENU_ID_MULTI_LANGUAGE :
		{
			mmi_imesettings_writing_lang_entry_screen_with_sg(parent_gid);
			return MMI_RET_OK ;
		}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_NO_HANDWRITING__)
		case MENU_ID_HW_SETTING :
		{
			EntryHandWritingSettingScr(parent_gid);
			return MMI_RET_OK ;
		}
#if defined (__MMI_IME_V3__)
#if !((!defined(__MMI_NO_HANDWRITING__) && defined(__MMI_IME_V3__) && defined(__MMI_VIRTUAL_KEYBOARD__)) && !defined(__MMI_IME_VK_TYPE_QWERTY__) &&  !defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__))
		case MENU_ID_FOLO_KEYBRD :
		{
			EntryKeyboardLanguageSettingScr(parent_gid);
			return MMI_RET_OK ;
		}
#endif
#endif
#endif
#if defined(__MMI_IME_AUTO_SPACE_SETTING__) || defined (__MMI_IME_AUTO_CAPITALIZATION_SETTING__)
		case MENU_ID_ENGLISH_SETTING:
			{
				mmi_imesettings_space_capitalization_entry_screen();
				return MMI_RET_OK ;
			}
#endif

//#if defined (__MMI_TOUCH_FEEDBACK_SUPPORT__)
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
//#endif			
#if defined(__MMI_IME_FUZZY_PINYIN__)
		case MENU_ID_FUZZY_PINYIN_SETTING:
			{
				mmi_imesettings_entry_fuzzy_pinyin_setting(parent_gid);
				return MMI_RET_OK ;
			}
#endif
#if defined(__MMI_IME_PHONETIC_PREDICTION_SETTING__)
		case MENU_ID_ASSOCIATION:
			{
				mmi_imesettings_association_entry_screen(parent_gid);
				return MMI_RET_OK ;
			}
#endif
		default :
			return MMI_RET_DONT_CARE;

	 }
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_imesettings_save_screen
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/

void mmi_imesettings_save_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

   g_active_imesettings_group = mmi_frm_group_get_active_id() ;
   g_active_imesettings_screen = mmi_frm_scrn_get_active_id() ; 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_settings_input_mode_screen_popup_handler_for_sg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_ime_settings_input_mode_screen_popup_handler_for_sg(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   return mmi_frm_scrn_close(g_active_imesettings_group, g_active_imesettings_screen);
}
#if defined (__MMI_IME_V3__)
/*****************************************************************************
 * FUNCTION
 *  EntryInputMethodSetting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void EntryInputMethodSetting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID main_menu_cui_id;
    MMI_ID group_id, scrn_id;
    mmi_group_node_struct node_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // get current activate screen group id
    mmi_frm_get_active_scrn_id(&group_id, &scrn_id);
    // get group info of current screen group
    mmi_frm_group_get_info(group_id,&node_info);
    // pass the parent group id to menu cui hack to resolve MAUI_03189815 MAUI_03313210
    if (1)// current screen is belong to option menu
    {
        mmi_frm_group_create(
            //GRP_ID_ROOT,
		    node_info.parent,
            GRP_ID_IME_MENU,
            mmi_ime_menu_handler,
            NULL);
    }
    else
    {
        mmi_frm_group_create(
            group_id,
            GRP_ID_IME_MENU,
            mmi_ime_menu_handler,
            NULL);
    }
    
    
    mmi_frm_group_enter(GRP_ID_IME_MENU, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    
    main_menu_cui_id = cui_menu_create(
        GRP_ID_IME_MENU,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_APPMAIN,
		MENU_ITEM_IME_SETTING,
        MMI_FALSE,
        NULL);

    #ifdef __PLUTO_MMI_PACKAGE__
    cui_menu_set_default_title_image(main_menu_cui_id, (UI_image_type)GetImage(MAIN_MENU_TITLE_SETTINGS_ICON));
	#endif
    cui_menu_run(main_menu_cui_id);
    
}

static mmi_ret mmi_ime_menu_handler_ext(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menucui_event;
    mmi_ret ret = MMI_RET_DONT_CARE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Menu CUI event */
    if (cui_menu_is_menu_event(param->evt_id))
    {
        menucui_event = (cui_menu_event_struct*)param;
		switch(param->evt_id)
		{
			case EVT_ID_CUI_MENU_CLOSE_REQUEST:
				cui_menu_close(((cui_menu_event_struct*)param)->sender_id);
				return MMI_RET_OK;
			default:
			break ;
		}
		ret = mmi_imesettings_menu_handler_ext(menucui_event, /*GRP_ID_IME_MENU*/menucui_event->parent_menu_id);
        return ret;                 
    }
    return MMI_RET_OK;
}
void EntryAdvanceSetting(MMI_ID parent_gid)
{
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
    #ifdef __PLUTO_MMI_PACKAGE__
/* under construction !*/
	#endif
/* under construction !*/
#endif   
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_menu_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

mmi_ret mmi_ime_menu_handler(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menucui_event;
    mmi_ret ret = MMI_RET_DONT_CARE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Menu CUI event */
    if (cui_menu_is_menu_event(param->evt_id))
    {
        menucui_event = (cui_menu_event_struct*)param;
		switch(param->evt_id)
		{
			case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            case EVT_ID_CUI_MENU_LIST_DEINIT:
				cui_menu_close(((cui_menu_event_struct*)param)->sender_id);
				return MMI_RET_OK;
			default:
			break ;
		}
		ret = mmi_imesettings_menu_handler_ext(menucui_event, GRP_ID_IME_MENU);
        return ret;                 
    }
    return MMI_RET_OK;
}

void mmi_imesettings_writinglangscreenrskhandler_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_popup;
    mmi_confirm_property_init(&confirm_popup,CNFM_TYPE_YESNO);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

/* On the basis of selection in Popup */
    confirm_popup.f_auto_map_empty_softkey = MMI_FALSE;
    confirm_popup.parent_id = mmi_frm_group_get_active_id() ;
	switch(confirm_popup.parent_id)
	{
		case GRP_ID_AUTO_SPC_AND_CAP_MENU :
			g_confirm_popup = AUTO_SPC_AND_CAP_MENU ;
			confirm_popup.user_tag = &g_confirm_popup ;
			break ;
		case GRP_ID_FEEDBACK_SETTING_MENU:
			g_confirm_popup = FEEDBACK_SETTING_MENU ;
			confirm_popup.user_tag = &g_confirm_popup ;
			break ;
#if defined(__MMI_IME_FUZZY_PINYIN__)
		case GRP_ID_FUZZY_PINYIN_MENU:
			g_confirm_popup = FUZZY_PINYIN_MENU;
			confirm_popup.user_tag = &g_confirm_popup ;
			break ;
#endif
		default :
			g_confirm_popup = CONFIRM_POPUP_NONE;
			confirm_popup.user_tag = &g_confirm_popup ;	
			break ;
	}
    confirm_popup.callback = mmi_imesettings_wlang_confirm_callback_ext;
    mmi_confirm_display((UI_string_type)GetString(STR_GLOBAL_SAVE_ASK), MMI_EVENT_QUERY, &confirm_popup);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
//	SetCenterSoftkeyFunction(mmi_ime_commonscreens_lang_yes_hdlr, KEY_EVENT_UP);
	register_center_softkey_to_enter_key();
	redraw_center_softkey();

}

mmi_ret mmi_imesettings_wlang_confirm_callback_ext(mmi_event_struct *evt)
{
   /*--------------------------------------------------------------*/
   /* Local Variables                                                */
   /*--------------------------------------------------------------*/
   
   /*--------------------------------------------------------------*/
   /* Code Body                                                      */
   /*--------------------------------------------------------------*/
  switch (evt->evt_id)
   {
       case EVT_ID_ALERT_QUIT :
               {
                       mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct *)evt;
                       switch(alert->result)
                       {
                         case MMI_ALERT_CNFM_YES:
							mmi_ime_commonscreens_yes_hdlr();
							break;
						case MMI_ALERT_CNFM_NO:
							mmi_ime_commonscreens_screen_close();
							mmi_ime_commonscreens_screen_close();
				break;
			}
		}
	}
	return MMI_RET_OK;
}
#endif
