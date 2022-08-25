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
 *   JavaAgencyUITextBox.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __J2ME__

#include "MMI_include.h"

#include "JavaAgencyUITextBox.h"
#include "JavaAgencyUICommon.h"
#include "JavaAgencyDef.h"

#include "CommonScreens.h"
#include "CommonScreensResDef.h"
#include "CommonScreensProt.h"

#include "wgui_softkeys.h"

/* added for phone book */
#ifdef __COSMOS_MMI_PACKAGE__
#include "vcui_phb_gprot.h"
#else
#include "PhbCuiGprot.h"
#endif
#include "PhbSrvGprot.h"
/* added for phone book end */

#include "jam_internal.h"
#include "jui_interface.h"
#include "JavaAgencyGProt.h"

#include "SettingResDef.h"      /* added for "Writing lauange" */

#include "mmi_rp_srv_editor_def.h"

#ifdef __COSMOS_MMI_PACKAGE__
#include "vapp_java_srv.h"
#include "JavaAgencyUIOptionMenu.h"
#include "mmi_frm_mem_gprot.h"
#endif
#include "wgui_categories_util.h"
#include "ImmProt.h"
#include "mmi_frm_prot.h"

#ifndef __COSMOS_MMI_PACKAGE__
#define MMI_JAVA_UI_TEXTBOX_UPDATE_TITLE(title, title_length)  mmi_java_ui_textbox_update_title(title,title_length)
#define MMI_JAVA_UI_TEXTBOX_UPDATE_TICKER(ticker, ticker_length)  mmi_java_ui_textbox_update_ticker(ticker,ticker_length)
#define MMI_JAVA_UI_TEXTBOX_UPDATE_COMMANDS(command_label,command_label_length,command_id, command_num) mmi_java_ui_textbox_update_commands(command_label,command_label_length,command_id, command_num)
#else
#define MMI_JAVA_UI_TEXTBOX_UPDATE_TITLE(title, title_length)  mmi_java_ui_textbox_update_component(JAVA_UI_TEXTBOX_TITLE)
#define MMI_JAVA_UI_TEXTBOX_UPDATE_TICKER(ticker, ticker_length)  mmi_java_ui_textbox_update_component(JAVA_UI_TEXTBOX_TICKER)
#define MMI_JAVA_UI_TEXTBOX_UPDATE_COMMANDS(command_label,command_label_length,command_id, command_num) mmi_java_ui_textbox_update_component(JAVA_UI_TEXTBOX_COMMAND)
#endif

extern void jvm_end_key_handler(void);  // TODO:::

static void mmi_java_ui_textbox_entry_screen(void);
static void mmi_java_ui_textbox_exit_screen(void);
static void mmi_java_ui_textbox_option_entry_screen(void);
static void mmi_java_ui_textbox_option_exit_screen(void);
static void mmi_java_ui_textbox_customize_key(void);
static void mmi_java_ui_textbox_search_number(void);
#if  !defined (J2ME_SLIM_MEMORY_SUPPORT)
static void mmi_java_ui_textbox_number_empty(void);
#endif
static void mmi_java_ui_textbox_common_empty(void);
static void mmi_java_ui_textbox_not_empty(void);
mmi_ret mmi_java_ui_textbox_set_number(mmi_event_struct *evt);
mmi_ret mmi_java_ui_textbox_set_number_prepare_proc(mmi_frm_asm_evt_struct *evt);
static void mmi_java_ui_textbox_option_highlight_handler(S32 index);
static void mmi_java_ui_textbox_option_leftkey_handler(void);
static void mmi_java_ui_textbox_rightkey_handler(void);
static void mmi_java_ui_textbox_endkey_handler(void);
static void mmi_java_ui_textbox_resume_screen(void);
static void mmi_java_ui_textbox_show_screen(kal_bool resumeCallback, kal_int32 previous_screen, kal_int32 next_screen);
static void mmi_java_ui_textbox_sort_command(void);
static void mmi_java_ui_textbox_update_text(
                kal_uint16 *text_buffer,
                kal_int32 max_length,
                kal_int32 constraint,
                kal_bool editable);
static void mmi_java_ui_textbox_set_title_data(kal_uint16 *title, kal_int32 title_length);
static void mmi_java_ui_textbox_set_ticker_data(kal_uint16 *ticker, kal_int32 ticker_length);
static void mmi_java_ui_textbox_set_commands_data(
                kal_uint16 **command_label,
                kal_int32 *command_label_length,
                kal_int32 *command_id,
                kal_int32 *command_type,
                kal_int32 command_num);
#ifdef __COSMOS_MMI_PACKAGE__
static void mmi_java_ui_textbox_update_component(kal_uint32 component_type);
#endif
static void mmi_java_ui_textbox_update_title(kal_uint16 *title, kal_int32 title_length);
static void mmi_java_ui_textbox_update_ticker(kal_uint16 *titcker, kal_int32 ticker_length);
static void mmi_java_ui_textbox_update_commands(
                kal_uint16 **command_label,
                kal_int32 *command_label_length,
                kal_int32 *command_id,
                kal_int32 command_num);

static kal_bool mmi_java_ui_textbox_is_display_option(void);
static kal_int32 mmi_java_ui_textbox_add_extra_symbol(
                    kal_uint8 *out,
                    kal_int32 out_max,
                    kal_uint8 **in,
                    kal_int32 in_max);
static kal_bool mmi_java_ui_textbox_is_need_add_extra_symbol(void);

static void mmi_java_ui_ime_common_scr_entry_callback(kal_uint16 old_scr_id, kal_uint16 new_scr_id);
static void mmi_java_ui_ime_common_scr_exit_callback(kal_uint16 old_scr_id, kal_uint16 new_scr_id);

mmi_java_ui_textbox_data_struct g_mmi_java_ui_textbox;

static kal_uint8 **mmi_java_ui_textbox_option_menu_label = NULL;
static kal_uint8 **mmi_java_ui_textbox_option_menu_icons = NULL;

static kal_int32 mmi_java_ui_textbox_option_menu_selected_index = -1;
static kal_int32 mmi_java_ui_textbox_option_menu_inputmethod_index = -1;
static kal_int32 mmi_java_ui_textbox_option_menu_insertsymbol_index = -1;

static kal_uint8 *mmi_java_ui_textbox_gui_buffer;
static kal_bool mmi_java_ui_textbox_is_data_updated = KAL_FALSE;
static kal_bool mmi_java_ui_textbox_is_editor_updated = KAL_FALSE;

MMI_ID mmi_java_ui_textbox_phone_number_id;
MMI_ID mmi_java_ui_textbox_phone_number_group_id = GRP_ID_INVALID;

static MMI_JAVA_UI_SCREEN_TYPE_ENUM mmi_java_ui_textbox_screen_type = MMI_JAVA_UI_SCREEN_TYPE_JAVA;

static kal_bool mmi_java_ui_textbox_is_first_enter = KAL_TRUE;

#ifdef __COSMOS_MMI_PACKAGE__
//static mmi_java_ui_option_menu_data_struct g_mmi_java_ui_textbox_option_menu_list;
#endif

/* Java JTWI spec */
static const U8 *JTWISymbol[5] = 
{
    (U8 *) "\x5e\0\0",  /* circumflex accent */
    (U8 *) "\x60\0\0",  /* grave acent */
    (U8 *) "\x7c\0\0",  /* vertical bar */
    (U8 *) "\xa1\0\0",  /* inverted exclamation */
    (U8 *) "\xbf\0\0",  /* inverted question mark */
};


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_ui_textbox_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler((PsFuncPtr) mmi_java_ui_textbox_show_req, MSG_ID_MMI_JAVA_UI_TEXTBOX_SHOW_REQ);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_ui_textbox_hide_req, MSG_ID_MMI_JAVA_UI_TEXTBOX_HIDE_REQ);

    SetProtocolEventHandler(
        (PsFuncPtr) mmi_java_ui_textbox_update_title_req,
        MSG_ID_MMI_JAVA_UI_TEXTBOX_UPDATE_TITLE_REQ);
    SetProtocolEventHandler(
        (PsFuncPtr) mmi_java_ui_textbox_update_ticker_req,
        MSG_ID_MMI_JAVA_UI_TEXTBOX_UPDATE_TICKER_REQ);
    SetProtocolEventHandler(
        (PsFuncPtr) mmi_java_ui_textbox_update_command_req,
        MSG_ID_MMI_JAVA_UI_TEXTBOX_UPDATE_COMMAND_REQ);
    SetProtocolEventHandler(
        (PsFuncPtr) mmi_java_ui_textbox_update_text_req,
        MSG_ID_MMI_JAVA_UI_TEXTBOX_UPDATE_TEXT_REQ);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_ui_textbox_bring_2_top_req, MSG_ID_MMI_JAVA_UI_TEXTBOX_SHOW_RSP);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_ui_textbox_option_menu_hide_req, MSG_ID_MMI_JAVA_UI_TEXTBOX_HIDE_RSP);
    
    mmi_java_ui_common_register_is_need_add_extra_symbol_callback(mmi_java_ui_textbox_is_need_add_extra_symbol);
    mmi_java_ui_common_register_add_extra_symbol_callback(mmi_java_ui_textbox_add_extra_symbol);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_customize_key
 * DESCRIPTION
 *  This function will remap keypad
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_textbox_customize_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_java_ui_textbox.is_editable)
    {
        mmi_imm_config_change_input_mode(MMI_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_option_exit_screen
 * DESCRIPTION
 *  this function exit the fullscreen editor option menu
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_textbox_option_exit_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 nextScreenId = GetActiveScreenId();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* GenericExitScreen(MMIAPI_SCREEN_FULLSCREEN_EDITOR_OPTION, mmiapi_goto_textbox_editor_option); */
    if (mmi_java_ui_textbox_option_menu_icons)
    {
        applib_mem_screen_free(mmi_java_ui_textbox_option_menu_icons);
        mmi_java_ui_textbox_option_menu_icons = NULL;
    }

    if (mmi_java_ui_textbox_option_menu_label)
    {
        applib_mem_screen_free(mmi_java_ui_textbox_option_menu_label);
        mmi_java_ui_textbox_option_menu_label = NULL;
    }

    if (!jam_is_enter_in_fg_mmi_screen_2(nextScreenId))
    {
        mmi_java_ui_textbox_screen_type = MMI_JAVA_UI_SCREEN_TYPE_UNKNOWN;
    }

    jam_exit_fg_mmi_screen_callback(SCR_ID_JAVA_UI_TEXTBOX_EDITOR_OPTION, GetActiveScreenId(), NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_option_entry_screen
 * DESCRIPTION
 *  this function will goto edit option menu.
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_textbox_option_entry_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *guiBuffer;
    kal_int16 nNumofItem;
    kal_bool displayInputMethod = KAL_FALSE;
    kal_int16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_enter(GRP_ID_JAVA_APP, SCR_ID_JAVA_UI_TEXTBOX_EDITOR_OPTION, mmi_java_ui_textbox_option_exit_screen, NULL, MMI_FRM_FULL_SCRN); /* 10A */
    guiBuffer = (U8*) mmi_frm_scrn_get_gui_buf(GRP_ID_JAVA_APP, SCR_ID_JAVA_UI_TEXTBOX_EDITOR_OPTION);

    nNumofItem = g_mmi_java_ui_textbox.command_num;

    mmi_java_ui_textbox_option_menu_inputmethod_index = -1;
    mmi_java_ui_textbox_option_menu_insertsymbol_index = -1;

#if defined(__MMI_IMC_CAPITAL_SWITCH__)
    if (mmi_imm_get_current_allowed_writing_language_num() > 1)
    {
        displayInputMethod = KAL_TRUE;
    }
#else /* defined(__MMI_IMC_CAPITAL_SWITCH__) */ 
    if (mmi_imm_get_current_allowed_input_mode_num() > 1)
    {
        displayInputMethod = KAL_TRUE;
    }
#endif /* defined(__MMI_IMC_CAPITAL_SWITCH__) */ 

    if (displayInputMethod && g_mmi_java_ui_textbox.is_editable)
    {
        nNumofItem += 1;
        mmi_java_ui_textbox_option_menu_inputmethod_index = nNumofItem - 1;
    }

#if defined(__MMI_EDITOR_OPTION_MENU_STYLE_1__) || defined (__MMI_EDITOR_OPTION_MENU_STYLE_2__) || defined (__MMI_EDITOR_OPTION_MENU_STYLE_3__)
    if (g_mmi_java_ui_textbox.is_editable)
    {
        nNumofItem += 1;
        mmi_java_ui_textbox_option_menu_insertsymbol_index = nNumofItem - 1;
    }
#endif /* defined(__MMI_EDITOR_OPTION_MENU_STYLE_1__) || defined (__MMI_EDITOR_OPTION_MENU_STYLE_2__) || defined (__MMI_EDITOR_OPTION_MENU_STYLE_3__) */ 

    mmi_java_ui_textbox_option_menu_label = (U8 **) applib_mem_screen_alloc(nNumofItem * sizeof(U8*));

    for (i = 0; i < g_mmi_java_ui_textbox.command_num; i++)
    {
        mmi_java_ui_textbox_option_menu_label[i] = (U8*) g_mmi_java_ui_textbox.command_label[i];
    }

    if (displayInputMethod && g_mmi_java_ui_textbox.is_editable)
    {
    #if defined(__MMI_IMC_CAPITAL_SWITCH__)
        mmi_java_ui_textbox_option_menu_label[mmi_java_ui_textbox_option_menu_inputmethod_index] =
            (U8*) get_string(STR_INPUT_METHOD_WRITING_LANGUAGE /* STR_ID_PHNSET_PREFERED_WRITING_LANG */ );
    #else /* defined(__MMI_IMC_CAPITAL_SWITCH__) */ 
        mmi_java_ui_textbox_option_menu_label[mmi_java_ui_textbox_option_menu_inputmethod_index] =
            (U8*) get_string(STR_GLOBAL_INPUT_METHOD);
    #endif /* defined(__MMI_IMC_CAPITAL_SWITCH__) */ 
    }
#if defined(__MMI_EDITOR_OPTION_MENU_STYLE_1__) || defined (__MMI_EDITOR_OPTION_MENU_STYLE_2__) || defined (__MMI_EDITOR_OPTION_MENU_STYLE_3__)
    if (g_mmi_java_ui_textbox.is_editable)
    {
        mmi_java_ui_textbox_option_menu_label[mmi_java_ui_textbox_option_menu_insertsymbol_index] =
            (U8*) get_string(STR_INPUT_METHOD_MENU_INSERT_SYMBOLS);
    }
#endif /* defined(__MMI_EDITOR_OPTION_MENU_STYLE_1__) || defined (__MMI_EDITOR_OPTION_MENU_STYLE_2__) || defined (__MMI_EDITOR_OPTION_MENU_STYLE_3__) */ 

    mmi_java_ui_textbox_option_menu_icons = (U8 **) applib_mem_screen_alloc(nNumofItem * sizeof(U8*));
    for (i = 0; i < nNumofItem; i++)
    {
        mmi_java_ui_textbox_option_menu_icons[i] = (U8*) get_image(gIndexIconsImageList[i]);
    }

    RegisterHighlightHandler(mmi_java_ui_textbox_option_highlight_handler);

    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory170Screen(
        (U8*) get_string(STR_GLOBAL_OPTIONS),
        (U8*) get_image(mmi_java_get_title_icon()),
        (U8*) get_string(STR_GLOBAL_OK),
        (U8*) get_image(IMG_GLOBAL_OK),
        (U8*) get_string(STR_GLOBAL_BACK),
        (U8*) get_image(IMG_GLOBAL_BACK),
        (S32) nNumofItem,
        (U8 **) mmi_java_ui_textbox_option_menu_label,
        (U8 **) mmi_java_ui_textbox_option_menu_icons,
        0,
        0,
        guiBuffer);

    /* don't need to key handler when there is no menu */
    if (nNumofItem > 0)
    {
        SetKeyHandler(mmi_java_ui_textbox_option_leftkey_handler, KEY_RIGHT_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_UP);

        SetLeftSoftkeyFunction(mmi_java_ui_textbox_option_leftkey_handler, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

        SetCenterSoftkeyFunction(mmi_java_ui_textbox_option_leftkey_handler, KEY_EVENT_UP);     /* 10A Key Rule */
    }

    SetKeyHandler(mmi_java_ui_textbox_endkey_handler, KEY_END, KEY_EVENT_DOWN);

    jam_resume_fg_mmi_screen_callback(
        SCR_ID_JAVA_UI_TEXTBOX_EDITOR,
        SCR_ID_JAVA_UI_TEXTBOX_EDITOR_OPTION,
        mmi_java_ui_textbox_screen_type,
        mmi_java_ui_textbox_screen_type);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_option_highlight_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_textbox_option_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < 0)
        return;

    mmi_java_ui_textbox_option_menu_selected_index = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_option_leftkey_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_textbox_option_leftkey_handler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_java_ui_textbox.is_editable)
    {
        if (mmi_java_ui_textbox_option_menu_selected_index == mmi_java_ui_textbox_option_menu_inputmethod_index)
        {
            RegisterInputMethodScreenCloseFunction(mmi_frm_scrn_close_active_id);       /* 10A */
            EntryInputMethodScreen();
            return;
        }
        else if (mmi_java_ui_textbox_option_menu_selected_index == mmi_java_ui_textbox_option_menu_insertsymbol_index)
        {
            RegisterInputMethodScreenCloseFunction(mmi_frm_scrn_close_active_id);

        #if defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__)
            mmi_ime_commonscreens_config_is_java_screens(MMI_TRUE);
        #endif 

            EntrySymbolPickerScreenFromMenuList();
            return;
        }
    }

    if (jui_widget_is_auto_back_from_mmi())
        GoBackHistory();    /* don't go back history  and wait vm to repaint the new screen */

    /* kal_trace(TRACE_STATE, FUNC_J2ME_JUI_SELECT_MENU_SHOW, mmiapi_textbox_editor_menu_id_buffer[mmi_java_ui_textbox_option_menu_selected_index],mmi_java_ui_textbox_option_menu_selected_index); */
    jam_notify_vm();
    //jui_widget_run_command(mmiapi_textbox_editor_menu_id_buffer[mmi_java_ui_textbox_option_menu_selected_index]);
    //JUI MVM event listener
    jui_widget_mvm_fire_event_listener_void_int(
        g_mmi_java_ui_textbox.vm_id,
        JUI_EVENT_RUN_COMMAND,
        g_mmi_java_ui_textbox.command_id[mmi_java_ui_textbox_option_menu_selected_index]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_set_number
 * DESCRIPTION
 *  set the phone number into edior buffer
 * PARAMETERS
 *  evt             [?]         
 *  number(?)       [IN]        Entry's phonenumber
 *  name(?)         [IN]        Entry's name
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_java_ui_textbox_set_number(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_node_struct  scrn_node_info;
#ifndef __COSMOS_MMI_PACKAGE__
    cui_phb_select_contact_result_struct *select_contact_result;
    S8 *number;
#else
    vcui_phb_list_result_event_struct *result;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_FIRST_ENTRY:
        case EVT_ID_GROUP_INACTIVE:
            break;

        case EVT_ID_GROUP_ACTIVE:
            break;

        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
            break;

        case EVT_ID_GROUP_DEINIT:
            break;
#ifndef __COSMOS_MMI_PACKAGE__
        case EVT_ID_PHB_SELECT_CONTACT:
            select_contact_result = (cui_phb_select_contact_result_struct*) evt;
               /**
                * Do something self here
                */

            number = (S8*) (select_contact_result->select_data);
            if (number)
            {
                mmi_ucs2ncpy((S8*) g_mmi_java_ui_textbox.text, (PS8) number, g_mmi_java_ui_textbox.text_max_size - 1);
                mmi_java_ui_textbox_is_data_updated = KAL_TRUE;
            }
            scrn_node_info.id = SCR_ID_JAVA_UI_TEXTBOX_EDITOR;
            scrn_node_info.entry_proc = (mmi_proc_func) &mmi_java_ui_textbox_entry_screen;
            mmi_frm_scrn_replace(
                GRP_ID_JAVA_APP,
                SCR_ID_JAVA_UI_TEXTBOX_EDITOR,
                &scrn_node_info);
            /* GoBackToHistory(MMIAPI_SCREEN_FULLSCREEN_EDITOR); */
               /**
                * Caller should call CUI close function to release CUI resource
                */
            cui_phb_list_select_contact_close(mmi_java_ui_textbox_phone_number_id);
            mmi_java_ui_textbox_phone_number_group_id = GRP_ID_INVALID;
            break;
        case EVT_ID_PHB_SELECT_CONTACT_CANCEL:
               /**
                * Do something self here
               */

               /**
                * Caller should call CUI close function to release CUI resource
                */
            cui_phb_list_select_contact_close(mmi_java_ui_textbox_phone_number_id);
            mmi_java_ui_textbox_phone_number_group_id = GRP_ID_INVALID;
            break;
#else
        case EVT_ID_CUI_PHB_LIST_RESULT:
            result = (vcui_phb_list_result_event_struct*) evt;
            if (result->result && result->select_count == 1)
            {
                vcui_phb_list_get_selected_contact_data(
                    mmi_java_ui_textbox_phone_number_id,
                    g_mmi_java_ui_textbox.text,
                    g_mmi_java_ui_textbox.text_max_size - 1);
                mmi_java_ui_textbox_is_data_updated = KAL_TRUE;
                
            }
            scrn_node_info.id = SCR_ID_JAVA_UI_TEXTBOX_EDITOR;
            scrn_node_info.entry_proc = &mmi_java_ui_textbox_entry_screen;
            mmi_frm_scrn_replace(
                GRP_ID_JAVA_APP,
                SCR_ID_JAVA_UI_TEXTBOX_EDITOR,
                &scrn_node_info);
            vcui_phb_list_close(mmi_java_ui_textbox_phone_number_id);
            mmi_java_ui_textbox_phone_number_group_id = GRP_ID_INVALID;
            break;

        case EVT_ID_ASM_FORCE_FREE:
            vcui_phb_list_close(mmi_java_ui_textbox_phone_number_id);
            mmi_java_ui_textbox_phone_number_group_id = GRP_ID_INVALID;
            break;
#endif
        default:
            break;
    }

    return MMI_RET_OK;
}

#ifdef __COSMOS_MMI_PACKAGE__
/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_set_number_prepare_proc
 * DESCRIPTION
 *  set the phone number into edior buffer
 * PARAMETERS
 *  evt             [?]         
 *  number(?)       [IN]        Entry's phonenumber
 *  name(?)         [IN]        Entry's name
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_java_ui_textbox_set_number_prepare_proc(mmi_frm_asm_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_ASM_CANCELED:
            break;
        case EVT_ID_ASM_PREPARED:
            mmi_java_ui_textbox_phone_number_id = vcui_phb_list_create(VAPP_JAVA_TEXTBOX);
	
			vcui_phb_list_set_drag_ncenter_flag(mmi_java_ui_textbox_phone_number_id, MMI_FALSE);
            vcui_phb_list_set_req_type(mmi_java_ui_textbox_phone_number_id, VAPP_PHB_LIST_SINGLE_SELECTOR);
	
            vcui_phb_list_set_req_field(mmi_java_ui_textbox_phone_number_id, MMI_PHB_CONTACT_FIELD_NUMBER);
	
            vcui_phb_list_run(mmi_java_ui_textbox_phone_number_id);
			
            break;
        default:
            break;
    }

    return MMI_RET_OK;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_search_number
 * DESCRIPTION
 *  this function will goto edit option menu.
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_textbox_search_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __COSMOS_MMI_PACKAGE__
    /* mmi_phb_list_pre_entry_for_number_and_email(MMI_PHB_ENTRY_FIELD_ALL_NUMBER, mmiapi_textbox_editor_set_number); */

    mmi_java_ui_textbox_phone_number_group_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_java_ui_textbox_set_number, NULL);

    mmi_frm_group_enter(mmi_java_ui_textbox_phone_number_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    /* mmi_frm_group_entry_ex(GRP_ID_ROOT, APP_JAVA, mmiapi_fullscreen_editor_set_number, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG); */

     /** 
     * Caller should keep the CUI group id, because all operation about CUI depends on it
     */
    mmi_java_ui_textbox_phone_number_id = cui_phb_list_select_contact_create(mmi_java_ui_textbox_phone_number_group_id);
#ifdef __MMI_NCENTER_SUPPORT__
	cui_phb_list_select_contact_set_ncenter(mmi_java_ui_textbox_phone_number_id, KAL_TRUE);
#endif
    cui_phb_list_select_contact_set_field_filter(mmi_java_ui_textbox_phone_number_id, SRV_PHB_ENTRY_FIELD_GSM_NUM);

    cui_phb_list_select_contact_run(mmi_java_ui_textbox_phone_number_id);
#else
    mmi_java_ui_textbox_phone_number_group_id = mmi_frm_group_create_ex(GRP_ID_ROOT, VAPP_JAVA_TEXTBOX, mmi_java_ui_textbox_set_number, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
			
    mmi_frm_asm_prepare(VAPP_JAVA_TEXTBOX, 0, (mmi_proc_func)mmi_java_ui_textbox_set_number_prepare_proc, NULL, 0);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_delete_phb_cui
 * DESCRIPTION
 *  this function will delete phb cui of TextBox.
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_ui_textbox_delete_phb_cui(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_java_ui_textbox_phone_number_group_id != GRP_ID_INVALID)
    {
#ifndef __COSMOS_MMI_PACKAGE__
        mmi_frm_group_close(mmi_java_ui_textbox_phone_number_group_id);
#else
        mmi_frm_group_close(VAPP_JAVA_TEXTBOX);
#endif
        mmi_java_ui_textbox_phone_number_group_id = GRP_ID_INVALID;
    }

}

#if  !defined (J2ME_SLIM_MEMORY_SUPPORT)

/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_number_empty
 * DESCRIPTION
 *  LSK handle when number input is empty
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_textbox_number_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeRightSoftkey(STR_GLOBAL_SEARCH, IMG_GLOBAL_OK);
    SetCategory5RightSoftkeyFunction(mmi_java_ui_textbox_search_number, KEY_EVENT_UP);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_common_empty
 * DESCRIPTION
 *  LSK handle when text input is empty
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_textbox_common_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_java_ui_textbox.command_num >= 2)
    {
        ChangeRightSoftkeyByString((UI_string_type) g_mmi_java_ui_textbox.command_label[1], 0);
        SetCategory5RightSoftkeyFunction(mmi_java_ui_textbox_rightkey_handler, KEY_EVENT_UP);
    }
#ifndef __COSMOS_MMI_PACKAGE__
    else if (g_mmi_java_ui_textbox.command_num == 1 && mmi_java_ui_textbox_is_display_option())
    {
        ChangeRightSoftkeyByString((UI_string_type) g_mmi_java_ui_textbox.command_label[0], 0);
        SetCategory5RightSoftkeyFunction(mmi_java_ui_textbox_rightkey_handler, KEY_EVENT_UP);
    }
#endif
}

static void mmi_java_ui_textbox_not_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeRightSoftkey(0, 0);
    SetCategory5RightSoftkeyFunction(NULL, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_leftkey_handler
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_textbox_leftkey_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jam_notify_vm();
    /* jui_widget_run_command(mmiapi_textbox_editor_menu_id_buffer[0]); */

    jui_widget_mvm_fire_event_listener_void_int(
        g_mmi_java_ui_textbox.vm_id,
        JUI_EVENT_RUN_COMMAND,
        g_mmi_java_ui_textbox.command_id[0]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_rightkey_handler
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_textbox_rightkey_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 command_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_mmi_java_ui_textbox.command_num > 0);

    jam_notify_vm();
    /* jui_widget_run_command(mmiapi_textbox_editor_menu_id_buffer[1]); */

    if (g_mmi_java_ui_textbox.command_num == 1)
        command_index = 0;
    else
        command_index = 1;

    jui_widget_mvm_fire_event_listener_void_int(
        g_mmi_java_ui_textbox.vm_id,
        JUI_EVENT_RUN_COMMAND,
        g_mmi_java_ui_textbox.command_id[command_index]);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_endkey_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_textbox_endkey_handler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_end_key_handler();
}


#ifdef __COSMOS_MMI_PACKAGE__
/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_homekey_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_textbox_homekey_handler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_home_key_handler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_backkey_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_textbox_backkey_handler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_java_ui_textbox.is_back2java = KAL_TRUE;/*MAUI_03309642*/
    jvm_back_key_handler();
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_exit_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_textbox_exit_screen()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;
    MMI_ID screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __COSMOS_MMI_PACKAGE__
        vapp_java_ui_textbox_exit();
    #else
    mmi_frm_get_active_scrn_id(&group_id, &screen_id);

    if (!jam_is_enter_in_fg_mmi_screen_2(screen_id))
    {
        mmi_java_ui_textbox_screen_type = MMI_JAVA_UI_SCREEN_TYPE_UNKNOWN;
    }

    jam_exit_fg_mmi_screen_callback((kal_uint16) SCR_ID_JAVA_UI_TEXTBOX_EDITOR, screen_id, NULL);
    #endif

    if (g_mmi_java_ui_textbox.bring2Back_callback != NULL)
        g_mmi_java_ui_textbox.bring2Back_callback(g_mmi_java_ui_textbox.vm_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_entry_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_textbox_entry_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;
    MMI_ID screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jui_lcd_mutex_lock();

    if (mmi_frm_scrn_is_present(GRP_ID_JAVA_APP, SCR_ID_JAVA_UI_TEXTBOX_EDITOR, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_JAVA_APP, SCR_ID_JAVA_UI_TEXTBOX_EDITOR);
    }

    mmi_frm_get_active_scrn_id(&group_id, &screen_id);  /* 10A */
    /* exit screen if the current screen is same to the new screen */
    if (screen_id == SCR_ID_JAVA_UI_TEXTBOX_EDITOR && mmi_java_ui_textbox_is_first_enter == KAL_TRUE)
    {
        jam_exit_fg_mmi_screen_callback(
            (kal_uint16) SCR_ID_JAVA_UI_TEXTBOX_EDITOR,
            (kal_uint16) SCR_ID_JAVA_UI_TEXTBOX_EDITOR,
            NULL);
#ifndef __COSMOS_MMI_PACKAGE__
                gdi_layer_lock_frame_buffer();
                ExitCategory5Screen();
                gdi_layer_unlock_frame_buffer();
                UI_common_screen_pre_exit();
                UI_common_screen_exit();
#else
               //mmi_frm_scrn_close(GRP_ID_JAVA_APP,SCR_ID_JAVA_UI_TEXTBOX_EDITOR);

                //vapp_java_ui_textbox_exit();
		//mmi_java_ui_textbox_exit_screen();
                //UI_common_screen_pre_exit();
                //UI_common_screen_exit();
                //vfx_mmi_screen_entered();
                vapp_java_ui_textbox_resume();
                jui_lcd_mutex_unlock();
                return;
#endif
    }

    mmi_java_ui_textbox_is_first_enter = KAL_TRUE;

    if (!mmi_frm_scrn_enter(GRP_ID_JAVA_APP, SCR_ID_JAVA_UI_TEXTBOX_EDITOR, mmi_java_ui_textbox_exit_screen, mmi_java_ui_textbox_resume_screen, MMI_FRM_FULL_SCRN))  /* 10A */
    {
        mmi_java_ui_textbox_is_first_enter = KAL_FALSE;
        jui_lcd_mutex_unlock();
        return;
    }
	
    mmi_java_ui_textbox_screen_type = MMI_JAVA_UI_SCREEN_TYPE_JAVA_MMI;

    //ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#ifdef __COSMOS_MMI_PACKAGE__
    vapp_java_ui_textbox_launch(&g_mmi_java_ui_textbox);
    SetKeyHandler(mmi_java_ui_textbox_homekey_handler, KEY_HOME, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_java_ui_textbox_backkey_handler, KEY_BACK, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_java_ui_textbox_endkey_handler, KEY_END, KEY_EVENT_DOWN);
#else

    mmi_java_ui_textbox_show_screen(
        (kal_bool)(screen_id != SCR_ID_JAVA_UI_TEXTBOX_EDITOR),
        MMI_JAVA_UI_SCREEN_TYPE_JAVA,
        mmi_java_ui_textbox_screen_type);

#endif
    jui_lcd_mutex_unlock();

    gdi_lcd_repaint_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_resume_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_textbox_resume_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;
    MMI_ID screen_id;
    MMI_JAVA_UI_SCREEN_TYPE_ENUM previous_type = mmi_java_ui_textbox_screen_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_java_ui_textbox_is_first_enter)
    {
        mmi_java_ui_textbox_entry_screen();
        return;
    }
	
    mmi_frm_get_active_scrn_id(&group_id, &screen_id);  /* 10A */

    if (!mmi_frm_scrn_enter(GRP_ID_JAVA_APP, SCR_ID_JAVA_UI_TEXTBOX_EDITOR, mmi_java_ui_textbox_exit_screen, mmi_java_ui_textbox_resume_screen, MMI_FRM_FULL_SCRN))  /* 10A */
    {
        return;
    }

    mmi_java_ui_textbox_screen_type = MMI_JAVA_UI_SCREEN_TYPE_JAVA_MMI;

    //ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#ifdef __COSMOS_MMI_PACKAGE__
    vapp_java_ui_textbox_launch(&g_mmi_java_ui_textbox);
    SetKeyHandler(mmi_java_ui_textbox_homekey_handler, KEY_HOME, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_java_ui_textbox_backkey_handler, KEY_BACK, KEY_EVENT_DOWN);
#else
    mmi_java_ui_textbox_show_screen(
        (kal_bool)(!mmi_is_redrawing_bk_screens()),
        previous_type,
        MMI_JAVA_UI_SCREEN_TYPE_JAVA_MMI);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_show_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  resumeCallback      [IN]        
 *  previous_screen     [IN]        
 *  next_screen         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_textbox_show_screen(kal_bool resumeCallback, kal_int32 previous_screen, kal_int32 next_screen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 *leftKeyStr = NULL;
    kal_uint16 *rightKeyStr = NULL;
    kal_uint8 *ticker = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
////#ifdef __MMI_SCREEN_ROTATE__
////    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
////#endif 

    mmi_java_ui_textbox_gui_buffer = (U8*) mmi_frm_scrn_get_gui_buf(GRP_ID_JAVA_APP, SCR_ID_JAVA_UI_TEXTBOX_EDITOR);
    if (mmi_java_ui_textbox_is_editor_updated || mmi_java_ui_textbox_is_data_updated)
    {
        mmi_java_ui_textbox_gui_buffer = NULL;
        if (!mmi_is_redrawing_bk_screens())
        {
            mmi_java_ui_textbox_is_editor_updated = KAL_FALSE;
            mmi_java_ui_textbox_is_data_updated = KAL_FALSE;
        }
    }
    if (mmi_java_ui_textbox_is_display_option())
    {
        leftKeyStr = (kal_uint16*) get_string(STR_GLOBAL_OPTIONS);
        if(g_mmi_java_ui_textbox.is_editable &&
           (g_mmi_java_ui_textbox.constraints & (~INPUT_TYPE_OVERRIDE_DEFAULT)) == IMM_INPUT_TYPE_PHONE_NUMBER)
        {
#if  !defined (J2ME_SLIM_MEMORY_SUPPORT)
            rightKeyStr = (kal_uint16*) get_string(STR_GLOBAL_SEARCH);
#endif
        }
        else
        {
            if (g_mmi_java_ui_textbox.command_num >= 2)
            {
                rightKeyStr = g_mmi_java_ui_textbox.command_label[1];
            }
            else if (g_mmi_java_ui_textbox.command_num == 1) 
            {
                rightKeyStr = g_mmi_java_ui_textbox.command_label[0];
            }
        }
    }
    else
    {
        if (g_mmi_java_ui_textbox.command_num > 0)
        {
            leftKeyStr = g_mmi_java_ui_textbox.command_label[0];
            if (g_mmi_java_ui_textbox.command_num == 2)
            {
                rightKeyStr = g_mmi_java_ui_textbox.command_label[1];
            }
        }
    }


    if (g_mmi_java_ui_textbox.is_editable)
    {
        if ((g_mmi_java_ui_textbox.constraints & (~INPUT_TYPE_OVERRIDE_DEFAULT)) == IMM_INPUT_TYPE_PHONE_NUMBER)
        {
#if  !defined (J2ME_SLIM_MEMORY_SUPPORT)
            RegisterInputBoxEmptyFunction(mmi_java_ui_textbox_number_empty);
#endif
        }
        else if (g_mmi_java_ui_textbox.command_num > 0)
        {
            RegisterInputBoxEmptyFunction(mmi_java_ui_textbox_common_empty);
        }
        else
        {
            RegisterInputBoxEmptyFunction(NULL);
        }
		RegisterInputBoxNotEmptyFunction(mmi_java_ui_textbox_not_empty);
    }

    if (g_mmi_java_ui_textbox.ticker_length >= 0)
        ticker = (kal_uint8*) g_mmi_java_ui_textbox.ticker;
    else
        ticker = NULL;

    gdi_layer_lock_frame_buffer();

    wgui_cat2002_show(
        (UI_string_type) g_mmi_java_ui_textbox.title,
        (PU8) get_image(mmi_java_get_title_icon()),
        (UI_string_type) leftKeyStr,
        0,
        (UI_string_type) rightKeyStr,
        0,
        ticker,
        (U8*) g_mmi_java_ui_textbox.text,
        g_mmi_java_ui_textbox.text_max_size,
        g_mmi_java_ui_textbox.constraints,
        NULL,
        g_mmi_java_ui_textbox.is_editable,
        KAL_FALSE,
        mmi_java_ui_textbox_gui_buffer);

    if (mmi_java_ui_textbox_is_display_option())
    {
        ChangeCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
        SetLeftSoftkeyFunction(mmi_java_ui_textbox_option_entry_screen, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_java_ui_textbox_option_entry_screen, KEY_EVENT_UP);
		
        if (!g_mmi_java_ui_textbox.is_editable && rightKeyStr)
        {
            ChangeRightSoftkeyByString((UI_string_type)g_mmi_java_ui_textbox.command_label[1], 0);
            SetRightSoftkeyFunction(mmi_java_ui_textbox_rightkey_handler, KEY_EVENT_UP);
        }
    }
    else
    {
        if (g_mmi_java_ui_textbox.command_num > 0)
        {
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            ChangeLeftSoftkeyByString((UI_string_type) g_mmi_java_ui_textbox.command_label[0], 0);
            SetLeftSoftkeyFunction(mmi_java_ui_textbox_leftkey_handler, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(mmi_java_ui_textbox_leftkey_handler, KEY_EVENT_UP);

            if (g_mmi_java_ui_textbox.command_num == 2)
            {
                ChangeRightSoftkeyByString((UI_string_type) g_mmi_java_ui_textbox.command_label[1], 0);
                wgui_inputs_category_set_rsk_func(mmi_java_ui_textbox_rightkey_handler);
            }
        }
        else
        {
            ChangeCenterSoftkey(0, 0);
        }
    }

#ifdef __MMI_CLIPBOARD__
    wgui_inputs_ml_set_style(0, GUI_MULTI_LINE_INPUT_BOX_DISABLE_CLIPBOARD);
    /* //disabled clipboard */
#endif /* __MMI_CLIPBOARD__ */ 

    reset_softkey(MMI_LEFT_SOFTKEY);
    reset_softkey(MMI_RIGHT_SOFTKEY);

    gdi_layer_unlock_frame_buffer();

    if (resumeCallback)
        jam_resume_fg_mmi_screen_callback(0, SCR_ID_JAVA_UI_TEXTBOX_EDITOR, previous_screen, next_screen);

    gdi_lcd_repaint_all();

    SetKeyHandler(mmi_java_ui_textbox_endkey_handler, KEY_END, KEY_EVENT_DOWN);

#ifdef __COSMOS_MMI_PACKAGE__
    SetKeyHandler(mmi_java_ui_textbox_homekey_handler, KEY_HOME, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_java_ui_textbox_backkey_handler, KEY_BACK, KEY_EVENT_DOWN);
#endif

    if (g_mmi_java_ui_textbox.bring2Top_callback != NULL)
        g_mmi_java_ui_textbox.bring2Top_callback(g_mmi_java_ui_textbox.vm_id);

    /* customize key */
    mmi_java_ui_textbox_customize_key();

    mmi_ime_register_editor_common_scr_entry_callback(mmi_java_ui_ime_common_scr_entry_callback);
    mmi_ime_register_editor_common_scr_exit_callback(mmi_java_ui_ime_common_scr_exit_callback);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_sort_command
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_textbox_sort_command()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 data;
    kal_uint16 i;
    kal_int32 id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_java_ui_textbox.command_num > 1)
    {
        for (i = 0; i < JUI_MAX_COMMAND_LABLE_LENGTH; i++)
        {
            data = g_mmi_java_ui_textbox.command_label[0][i];
            g_mmi_java_ui_textbox.command_label[0][i] = g_mmi_java_ui_textbox.command_label[1][i];
            g_mmi_java_ui_textbox.command_label[1][i] = data;
        }

        id = g_mmi_java_ui_textbox.command_id[0];
        g_mmi_java_ui_textbox.command_id[0] = g_mmi_java_ui_textbox.command_id[1];
        g_mmi_java_ui_textbox.command_id[1] = id;

        id = g_mmi_java_ui_textbox.command_label_length[0];
        g_mmi_java_ui_textbox.command_label_length[0] = g_mmi_java_ui_textbox.command_label_length[1];
        g_mmi_java_ui_textbox.command_label_length[1] = id;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_show_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_struct      [?]         
 *  mod_src(?)      [IN]        
 *  msg         [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_ui_textbox_show_req(void *msg_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    mmi_java_ui_textbox_show_req_struct *msg = (mmi_java_ui_textbox_show_req_struct*) msg_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg != NULL);
    memset(&g_mmi_java_ui_textbox, 0x00, sizeof(mmi_java_ui_textbox_data_struct));

    if (msg->title != NULL && msg->title_length > 0)
        memcpy(g_mmi_java_ui_textbox.title, msg->title, (msg->title_length) * sizeof(kal_uint16));

    if (msg->ticker != NULL && msg->ticker_length > 0)
        memcpy(g_mmi_java_ui_textbox.ticker, msg->ticker, (msg->ticker_length) * sizeof(kal_uint16));

    g_mmi_java_ui_textbox.title_length = msg->title_length;
    g_mmi_java_ui_textbox.ticker_length = msg->ticker_length;
    for (i = 0; i < msg->text_length; i++)
    {
        msg->buffer[i] = msg->text_buffer[i];
    }
    msg->buffer[msg->text_length] = 0;
    g_mmi_java_ui_textbox.text = msg->buffer;
    g_mmi_java_ui_textbox.text_max_size = msg->max_size;
    g_mmi_java_ui_textbox.constraints = msg->constraints;

    g_mmi_java_ui_textbox.is_editable = msg->is_editable;

    g_mmi_java_ui_textbox.command_num = msg->command_num;
    if (msg->command_num > 0)
    {
        memcpy(g_mmi_java_ui_textbox.command_id, msg->command_id, (msg->command_num) * sizeof(kal_int32));
        memcpy(g_mmi_java_ui_textbox.command_type, msg->command_type, (msg->command_num) * sizeof(kal_int32));
        memcpy(
            g_mmi_java_ui_textbox.command_label_length,
            msg->command_label_lenght,
            (msg->command_num) * sizeof(kal_int32));
    }

    for (i = 0; i < JUI_MAX_COMMAND_SUPPORT && i < msg->command_num; i++)
    {
        memcpy(
            g_mmi_java_ui_textbox.command_label[i],
            msg->command_label[i],
            msg->command_label_lenght[i] * sizeof(kal_uint16));
    }
    g_mmi_java_ui_textbox.bring2Top_callback = msg->bring2Top_callback;
    g_mmi_java_ui_textbox.bring2Back_callback = msg->bring2Back_callback;

    g_mmi_java_ui_textbox.vm_id = msg->vm_id;

    if (jui_widget_is_auto_sort_commands())
        mmi_java_ui_textbox_sort_command(); /* no need to exchange in mvm */

    mmi_java_ui_textbox_is_data_updated = KAL_TRUE;
    ClearKeyEvents();   /* clear all keypad buffer */
    mmi_ime_delete_editor_common_scr_with_sg(GRP_ID_JAVA_APP, SCR_ID_JAVA_UI_TEXTBOX_EDITOR);
    mmi_ime_delete_editor_common_scr_with_sg(GRP_ID_JAVA_APP, SCR_ID_JAVA_UI_TEXTBOX_EDITOR_OPTION);
    //DeleteScreenIfPresent(MMIAPI_SCREEN_TEXTBOX_EDITOR);
    ////mmi_frm_scrn_close(GRP_ID_JAVA_APP,MMIAPI_SCREEN_TEXTBOX_EDITOR);

    if (jam_is_own_java_screen(msg->vm_id) || jam_is_own_mmi_screen(msg->vm_id))
        mmi_java_ui_textbox_entry_screen();

    if (msg->callback != NULL)
        msg->callback(msg->vm_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_hide_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_struct      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_ui_textbox_hide_req(void *msg_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_ui_textbox_show_req_struct *msg = (mmi_java_ui_textbox_show_req_struct*) msg_struct;
    MMI_ID group_id, screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg != NULL);
    ASSERT(msg->vm_id == g_mmi_java_ui_textbox.vm_id);

    mmi_ime_delete_editor_common_scr_with_sg(GRP_ID_JAVA_APP, SCR_ID_JAVA_UI_TEXTBOX_EDITOR);
    mmi_ime_delete_editor_common_scr_with_sg(GRP_ID_JAVA_APP, SCR_ID_JAVA_UI_TEXTBOX_EDITOR_OPTION);

    mmi_frm_get_active_scrn_id(&group_id, &screen_id);


    if (screen_id == SCR_ID_JAVA_UI_TEXTBOX_EDITOR || screen_id == SCR_ID_JAVA_UI_TEXTBOX_EDITOR_OPTION)
    {
        mmi_frm_scrn_close_active_id();
        mmi_frm_scrn_close(GRP_ID_JAVA_APP, SCR_ID_JAVA_UI_TEXTBOX_EDITOR);

        /* jvm_post_repaint_event(); */
        jui_widget_mvm_fire_event_listener_void_void(msg->vm_id, JUI_EVENT_REPAINT);
    }
    else if (mmi_frm_scrn_is_present(GRP_ID_JAVA_APP, SCR_ID_JAVA_UI_TEXTBOX_EDITOR, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_JAVA_APP, SCR_ID_JAVA_UI_TEXTBOX_EDITOR);

        /* jvm_post_repaint_event(); */
        jui_widget_mvm_fire_event_listener_void_void(msg->vm_id, JUI_EVENT_REPAINT);
    }

    memset(&g_mmi_java_ui_textbox, 0x00, sizeof(mmi_java_ui_textbox_data_struct));

    if (msg->callback != NULL)
        msg->callback(msg->vm_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_update_title_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_struct      [?]     [?]
 *  mod_src(?)      [IN](?)
 *  msg         [?](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_ui_textbox_update_title_req(void *msg_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_ui_textbox_show_req_struct *msg = (mmi_java_ui_textbox_show_req_struct*) msg_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg != NULL);
    ASSERT(msg->vm_id == g_mmi_java_ui_textbox.vm_id);

    mmi_java_ui_textbox_set_title_data(msg->title, msg->title_length);

    MMI_JAVA_UI_TEXTBOX_UPDATE_TITLE(msg->title, msg->title_length);

    if (msg->callback != NULL)
        msg->callback(msg->vm_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_update_ticker_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_struct      [?]     [?]
 *  mod_src(?)      [IN](?)
 *  msg         [?](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_ui_textbox_update_ticker_req(void *msg_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_ui_textbox_show_req_struct *msg = (mmi_java_ui_textbox_show_req_struct*) msg_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg != NULL);
    ASSERT(msg->vm_id == g_mmi_java_ui_textbox.vm_id);

    mmi_java_ui_textbox_set_ticker_data(msg->ticker,msg->ticker_length);

    MMI_JAVA_UI_TEXTBOX_UPDATE_TICKER(msg->ticker, msg->ticker_length);

    if (msg->callback != NULL)
        msg->callback(msg->vm_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_update_text_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_struct      [?]     [?]
 *  mod_src(?)      [IN](?)
 *  msg         [?](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_ui_textbox_update_text_req(void *msg_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_ui_textbox_show_req_struct *msg = (mmi_java_ui_textbox_show_req_struct*) msg_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg != NULL);
    ASSERT(msg->vm_id == g_mmi_java_ui_textbox.vm_id);
    
#ifdef __COSMOS_MMI_PACKAGE__
    memcpy(g_mmi_java_ui_textbox.text, msg->buffer, msg->max_size * sizeof(kal_uint16));
    g_mmi_java_ui_textbox.text[msg->max_size] = 0;                
    g_mmi_java_ui_textbox.text_max_size = msg->max_size;

    if (msg->constraints >= 0)
    {
        g_mmi_java_ui_textbox.constraints = msg->constraints;
        g_mmi_java_ui_textbox.is_editable = msg->is_editable;
    }

    mmi_java_ui_textbox_update_component(JAVA_UI_TEXTBOX_TEXT);
#else
    mmi_java_ui_textbox_update_text(msg->buffer, msg->max_size, msg->constraints, msg->is_editable);
#endif

    if (msg->callback != NULL)
        msg->callback(msg->vm_id);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_update_command_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_struct      [?]     [?]
 *  mod_src(?)      [IN](?)
 *  msg         [?](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_ui_textbox_update_command_req(void *msg_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_ui_textbox_show_req_struct *msg = (mmi_java_ui_textbox_show_req_struct*) msg_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg != NULL);

    if(msg->vm_id == g_mmi_java_ui_textbox.vm_id)
    {
        mmi_java_ui_textbox_set_commands_data(
            msg->command_label,msg->command_label_lenght,msg->command_id,msg->command_type,msg->command_num);
        
        MMI_JAVA_UI_TEXTBOX_UPDATE_COMMANDS(
            msg->command_label,
            msg->command_label_lenght,
            msg->command_id,
            msg->command_num);
    }

    if (msg->callback != NULL)
        msg->callback(msg->vm_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_bring_2_top_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_struct      [?]     [?]
 *  mod_src(?)      [IN](?)
 *  msg         [?](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_ui_textbox_bring_2_top_req(void *msg_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_ui_textbox_show_req_struct *msg = (mmi_java_ui_textbox_show_req_struct*) msg_struct;
    MMI_ID group_id;
    MMI_ID screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg != NULL);

    mmi_frm_get_active_scrn_id(&group_id, &screen_id);
    if (screen_id == SCR_ID_JAVA_UI_TEXTBOX_EDITOR)
    {
        if (msg->callback != NULL)
            msg->callback(msg->vm_id);
        return;
    }
	
    /*MAUI_03239797*/
    /*we terminate java in textbox screen, g_mmi_java_ui_textbox won't be reset. 
    next time show textbox, we might direct call bring 2 top. then the data in g_mmi_java_ui_textbox is invalid. we need to use data in msg_struct*/
    /*if(msg->vm_id == g_mmi_java_ui_textbox.vm_id && g_mmi_java_ui_textbox.text != NULL) //text == NULL meens textbox is never displayed
    {
        mmi_java_ui_textbox_resume_screen();
        if (msg->callback != NULL)
            msg->callback(msg->vm_id);
    }
    else
    {*/
        mmi_java_ui_textbox_show_req(msg_struct);
    //}


}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_option_menu_hide_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_struct      [?]         
 *  mod_src(?)      [IN]        
 *  msg         [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_ui_textbox_option_menu_hide_req(void *msg_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_ui_textbox_show_req_struct *msg = (mmi_java_ui_textbox_show_req_struct*) msg_struct;
    MMI_ID group_id;
    MMI_ID screen_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg != NULL);
    ASSERT(msg->vm_id == g_mmi_java_ui_textbox.vm_id);
 
    mmi_frm_get_active_scrn_id(&group_id, &screen_id);   
    if(screen_id == SCR_ID_JAVA_UI_TEXTBOX_EDITOR_OPTION)
        mmi_frm_scrn_close_active_id();

    if (msg->callback != NULL)
        msg->callback(msg->vm_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_is_visible
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vm_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool mmi_java_ui_textbox_is_visible(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;
    MMI_ID screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_java_ui_textbox.vm_id == vm_id)
    {
        mmi_frm_get_active_scrn_id(&group_id, &screen_id);
        if((screen_id == SCR_ID_JAVA_UI_TEXTBOX_EDITOR) 
            || (screen_id == SCR_ID_JAVA_UI_TEXTBOX_EDITOR_OPTION))
            return KAL_TRUE;
    }

    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_update_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer              [?]         
 *  max_size            [IN]        
 *  constraints         [IN]        
 *  is_editable         [IN]        
 *  editable(?)         [IN]        
 *  constraint(?)       [IN]        
 *  max_length(?)       [IN]        
 *  text_buffer     [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_textbox_update_text(
                kal_uint16 *buffer,
                kal_int32 max_size,
                kal_int32 constraints,
                kal_bool is_editable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool editable_change = KAL_FALSE;
    kal_uint8 *leftKeyStr = NULL;
    kal_uint8 *rightKeyStr = NULL;

    MMI_ID group_id;
    MMI_ID screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_prompt_trace(MOD_J2ME,"[MMIAPI]update text"); */
    if (g_mmi_java_ui_textbox.is_editable != is_editable)
        editable_change = KAL_TRUE;

    //gdi_layer_lock_frame_buffer();

    memcpy(g_mmi_java_ui_textbox.text, buffer, max_size * sizeof(kal_uint16));
    g_mmi_java_ui_textbox.text[max_size] = 0;

    g_mmi_java_ui_textbox.text_max_size = max_size;

    if (wgui_cat2002_is_vk_state()) /* check vk,MAUI_02258397 */
    {
        //gdi_layer_unlock_frame_buffer();
        return;
    }

    if (jam_mvm_get_vm_state(0) == JVM_LONG_EVENT_STATE)    /* TODO */
    {
        //gdi_layer_unlock_frame_buffer();
        return;
    }

    mmi_frm_get_active_scrn_id(&group_id, &screen_id);
    if (constraints >= 0)
    {
        g_mmi_java_ui_textbox.constraints = constraints;
        g_mmi_java_ui_textbox.is_editable = is_editable;

        if (editable_change)
        {
            mmi_java_ui_textbox_is_editor_updated = KAL_TRUE;
        }
        if (screen_id != SCR_ID_JAVA_UI_TEXTBOX_EDITOR)
        {
            mmi_ime_delete_editor_common_scr_with_sg(GRP_ID_JAVA_APP, SCR_ID_JAVA_UI_TEXTBOX_EDITOR);
            mmi_ime_delete_editor_common_scr_with_sg(GRP_ID_JAVA_APP, SCR_ID_JAVA_UI_TEXTBOX_EDITOR_OPTION);
        }

        if (screen_id == SCR_ID_JAVA_UI_TEXTBOX_EDITOR_OPTION)
        {
            mmi_frm_scrn_close_active_id();
        }
        else
        {
            mmi_java_ui_textbox_is_editor_updated = KAL_FALSE;
        }

        gdi_layer_lock_frame_buffer();

        /* customize key */
        mmi_java_ui_textbox_customize_key();    /* after disppear option screen and then customize option */

        if (screen_id == SCR_ID_JAVA_UI_TEXTBOX_EDITOR)
        {
            wgui_cat2002_change_input_type(constraints, NULL);

            if (editable_change)
            {

                if (mmi_java_ui_textbox_is_display_option())
                {
                    leftKeyStr = (U8*) get_string(STR_GLOBAL_OPTIONS);
                    if(g_mmi_java_ui_textbox.is_editable &&
                       (g_mmi_java_ui_textbox.constraints & (~INPUT_TYPE_OVERRIDE_DEFAULT)) == IMM_INPUT_TYPE_PHONE_NUMBER)
                    {
#if  !defined (J2ME_SLIM_MEMORY_SUPPORT)
                        rightKeyStr = (kal_uint8*) get_string(STR_GLOBAL_SEARCH);
#endif
                    }
                    else
                    {
                        if (g_mmi_java_ui_textbox.command_num >= 2)
                        {
                            rightKeyStr = (kal_uint8*) g_mmi_java_ui_textbox.command_label[1];
                        }
                        else if (g_mmi_java_ui_textbox.command_num == 1) 
                        {
                            rightKeyStr = (kal_uint8*) g_mmi_java_ui_textbox.command_label[0];
                        }
                    }
                }
                else
                {

                    if (g_mmi_java_ui_textbox.command_num > 0)
                    {
                        leftKeyStr = (kal_uint8*) g_mmi_java_ui_textbox.command_label[0];
                        if (g_mmi_java_ui_textbox.command_num == 2)
                        {
                            rightKeyStr = (kal_uint8*) g_mmi_java_ui_textbox.command_label[1];
                        }
                    }
                }

                reset_softkey(MMI_LEFT_SOFTKEY);
                reset_softkey(MMI_RIGHT_SOFTKEY);

                if (is_editable)
                {
                    wgui_cat2002_activate_editor(
                        (UI_string_type) leftKeyStr,
                        0,
                        (UI_string_type) rightKeyStr,
                        0,
                        (U8*) g_mmi_java_ui_textbox.text,
                        g_mmi_java_ui_textbox.text_max_size,
                        g_mmi_java_ui_textbox.constraints,
                        NULL);
                }
                else
                {
                    wgui_cat2002_inactivate_editor(
                        (UI_string_type) leftKeyStr,
                        0,
                        (UI_string_type) rightKeyStr,
                        0,
                        (UI_string_type) g_mmi_java_ui_textbox.text,
                        g_mmi_java_ui_textbox.text_max_size);

                }

                if (mmi_java_ui_textbox_is_display_option())
                {
                    ChangeCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
                    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
                    SetLeftSoftkeyFunction(mmi_java_ui_textbox_option_entry_screen, KEY_EVENT_UP);
                    SetCenterSoftkeyFunction(mmi_java_ui_textbox_option_entry_screen, KEY_EVENT_UP);

                    if (!g_mmi_java_ui_textbox.is_editable && rightKeyStr)
                    {
                        ChangeRightSoftkeyByString((UI_string_type)g_mmi_java_ui_textbox.command_label[1], 0);
                        SetRightSoftkeyFunction(mmi_java_ui_textbox_rightkey_handler, KEY_EVENT_UP);
                    }
                }
                else
                {
                    if (g_mmi_java_ui_textbox.command_num > 0)
                    {
                        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
                        SetLeftSoftkeyFunction(mmi_java_ui_textbox_leftkey_handler, KEY_EVENT_UP);
                        SetCenterSoftkeyFunction(mmi_java_ui_textbox_leftkey_handler, KEY_EVENT_UP);

                        if (g_mmi_java_ui_textbox.command_num > 1)
                        {
                            SetRightSoftkeyFunction(mmi_java_ui_textbox_rightkey_handler, KEY_EVENT_UP);
                        }
                    }
                    else
                    {
                        ChangeCenterSoftkey(0, 0);
                    }
                }

                /* kal_prompt_trace(MOD_J2ME,"editable change"); */
            }

        #ifdef __MMI_CLIPBOARD__
            wgui_inputs_ml_set_style(0, GUI_MULTI_LINE_INPUT_BOX_DISABLE_CLIPBOARD);
            /* //disabled clipboard */
        #endif /* __MMI_CLIPBOARD__ */ 

            if (g_mmi_java_ui_textbox.is_editable)
            {
                if ((g_mmi_java_ui_textbox.constraints & (~INPUT_TYPE_OVERRIDE_DEFAULT)) == IMM_INPUT_TYPE_PHONE_NUMBER)
                {
#if  !defined (J2ME_SLIM_MEMORY_SUPPORT)
                    RegisterInputBoxEmptyFunction(mmi_java_ui_textbox_number_empty);
#endif
                }
                else if(g_mmi_java_ui_textbox.command_num > 0)
                {
                    RegisterInputBoxEmptyFunction(mmi_java_ui_textbox_common_empty);
                }
                else
                {
                    RegisterInputBoxEmptyFunction(NULL);
                }
            }
        }

        gdi_layer_unlock_frame_buffer();
    }

    if (screen_id == SCR_ID_JAVA_UI_TEXTBOX_EDITOR_OPTION)
    {
        mmi_frm_scrn_close_active_id();
    }

    gdi_layer_lock_frame_buffer();
	
    mmi_frm_get_active_scrn_id(&group_id, &screen_id);
    if (screen_id == SCR_ID_JAVA_UI_TEXTBOX_EDITOR)
    {
        wgui_cat2002_change_text(
            (UI_string_type) g_mmi_java_ui_textbox.text,
            g_mmi_java_ui_textbox.text_max_size,
            KAL_FALSE);
    }
    else
    {
        mmi_java_ui_textbox_is_data_updated = KAL_TRUE;
    }

    gdi_layer_unlock_frame_buffer();

    gdi_lcd_repaint_all();
}

static void mmi_java_ui_textbox_set_title_data(kal_uint16 *title, kal_int32 title_length)
{
    memset(g_mmi_java_ui_textbox.title, 0x00, (JUI_MAX_TITLE_LENGTH + 1) * sizeof(kal_uint16));
    if (title_length >= 0)
    {
        memcpy(g_mmi_java_ui_textbox.title, title, title_length * sizeof(kal_uint16));
    }
    g_mmi_java_ui_textbox.title_length = title_length;
}

static void mmi_java_ui_textbox_set_ticker_data(kal_uint16 *ticker, kal_int32 ticker_length)
{
    memset(g_mmi_java_ui_textbox.ticker, 0x00, (JUI_MAX_TICKER_LENGTH + 1) * sizeof(kal_uint16));

    if (ticker_length >= 0)
        memcpy(g_mmi_java_ui_textbox.ticker, ticker, (ticker_length + 1) * sizeof(kal_uint16));
    g_mmi_java_ui_textbox.ticker_length = ticker_length;
}

static void mmi_java_ui_textbox_set_commands_data(
                kal_uint16 **command_label,
                kal_int32 *command_label_length,
                kal_int32 *command_id,
                kal_int32 *command_type,
                kal_int32 command_num)
{
    kal_int32 i;
	
    memset(g_mmi_java_ui_textbox.command_id, 0x00, JUI_MAX_COMMAND_SUPPORT * sizeof(kal_int32));
    memcpy(g_mmi_java_ui_textbox.command_id, command_id, command_num * sizeof(kal_int32));

    memset(g_mmi_java_ui_textbox.command_type, 0x00, JUI_MAX_COMMAND_SUPPORT * sizeof(kal_int32));
    memcpy(g_mmi_java_ui_textbox.command_type, command_type, command_num * sizeof(kal_int32));

    memset(g_mmi_java_ui_textbox.command_label_length, 0x00, JUI_MAX_COMMAND_SUPPORT * sizeof(kal_int32));
    memcpy(g_mmi_java_ui_textbox.command_label_length, command_label_length, command_num * sizeof(kal_int32));

    memset(
        g_mmi_java_ui_textbox.command_label,
        0x00,
        JUI_MAX_COMMAND_SUPPORT * (JUI_MAX_COMMAND_LABLE_LENGTH + 1) * sizeof(kal_uint16));
    for (i = 0; i < command_num; i++)
        memcpy(g_mmi_java_ui_textbox.command_label[i], command_label[i], command_label_length[i] * sizeof(kal_uint16));

    g_mmi_java_ui_textbox.command_num = command_num;

}

#ifdef __COSMOS_MMI_PACKAGE__
/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_update_component
 * DESCRIPTION
 *  
 * PARAMETERS
 *  title               [?]         [?]         [?]
 *  title_length        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_textbox_update_component(kal_uint32 component_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;
    MMI_ID screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     mmi_frm_get_active_scrn_id(&group_id, &screen_id);

    if (screen_id == SCR_ID_JAVA_UI_TEXTBOX_EDITOR)
    {
        vapp_java_ui_textbox_update_component(component_type);
    }
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_update_title
 * DESCRIPTION
 *  
 * PARAMETERS
 *  title               [?]         [?]         [?]
 *  title_length        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_textbox_update_title(kal_uint16 *title, kal_int32 title_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;
    MMI_ID screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_get_active_scrn_id(&group_id, &screen_id);

    if (GetActiveScreenId() == SCR_ID_JAVA_UI_TEXTBOX_EDITOR_OPTION)
    {
        mmi_frm_scrn_close_active_id();
    }

    /* update title data */
    if (screen_id == SCR_ID_JAVA_UI_TEXTBOX_EDITOR)
    {
        if (title_length >= 0)
        {
            wgui_cat2002_change_title((UI_string_type) g_mmi_java_ui_textbox.title, mmi_java_get_title_icon());
        }
        else
        {
            wgui_cat2002_change_title((UI_string_type) NULL, mmi_java_get_title_icon());
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_update_ticker
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ticker              [?]         [?]         [?]
 *  ticker_length       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_textbox_update_ticker(kal_uint16 *ticker, kal_int32 ticker_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //MMI_BOOL tickerChanged = KAL_FALSE;

    MMI_ID group_id;
    MMI_ID screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*if (g_mmi_java_ui_textbox.ticker_length != ticker_length &&
        (g_mmi_java_ui_textbox.ticker_length == -1 || ticker_length == -1))
        tickerChanged = KAL_TRUE;*/

    mmi_frm_get_active_scrn_id(&group_id, &screen_id);

    if (screen_id == SCR_ID_JAVA_UI_TEXTBOX_EDITOR_OPTION )
    {
        mmi_frm_scrn_close_active_id();
    }

    /* update ticker data */
    if (screen_id == SCR_ID_JAVA_UI_TEXTBOX_EDITOR)
    {
        if (ticker_length >= 0)
        {
            wgui_cat2002_change_ticker((UI_string_type) g_mmi_java_ui_textbox.ticker, KAL_TRUE);
        }
        else
        {
            wgui_cat2002_change_ticker((UI_string_type) NULL, KAL_TRUE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_update_commands
 * DESCRIPTION
 *  
 * PARAMETERS
 *  command_label               [IN]        
 *  command_label_length        [?]         [?]
 *  command_id                  [?]         [?]
 *  command_num                 [IN]        
 *  menu_num(?)                 [IN](?)
 *  menu_list(?)                [IN](?)
 *  menu_ids        [?](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_textbox_update_commands(
                kal_uint16 **command_label,
                kal_int32 *command_label_length,
                kal_int32 *command_id,
                kal_int32 command_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //kal_int32 i;

    MMI_ID group_id;
    MMI_ID screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_get_active_scrn_id(&group_id, &screen_id);

    //gdi_layer_lock_frame_buffer();
    if (screen_id != SCR_ID_JAVA_UI_TEXTBOX_EDITOR)
    {
        mmi_ime_delete_editor_common_scr_with_sg(GRP_ID_JAVA_APP, SCR_ID_JAVA_UI_TEXTBOX_EDITOR);
        mmi_ime_delete_editor_common_scr_with_sg(GRP_ID_JAVA_APP, SCR_ID_JAVA_UI_TEXTBOX_EDITOR_OPTION);
    }

    /* goback the main editor screen */
    if (screen_id == SCR_ID_JAVA_UI_TEXTBOX_EDITOR_OPTION)
    {
        mmi_frm_scrn_close_active_id();
    }

    gdi_layer_lock_frame_buffer();

    if (jui_widget_is_auto_sort_commands())
        mmi_java_ui_textbox_sort_command(); /* no need in MVM */

    if (screen_id == SCR_ID_JAVA_UI_TEXTBOX_EDITOR)
    {
        mmi_imc_reset_ime_state();
        if (g_mmi_java_ui_textbox.is_editable)
		{
            wgui_inputs_ml_set_RSK();       /* added for MAUI_01911290 */
			if(mmi_frm_kbd_is_key_supported(KEY_CLEAR) && g_mmi_java_ui_textbox.command_num == 0)
			{
				ChangeRightSoftkey(0, 0);
			}
		}
        else
            ChangeRightSoftkey(NULL, NULL); /* MAUI_02126037,set right softkey is NULL */

        if (mmi_java_ui_textbox_is_display_option())
        {
            ChangeCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
            SetLeftSoftkeyFunction(mmi_java_ui_textbox_option_entry_screen, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(mmi_java_ui_textbox_option_entry_screen, KEY_EVENT_UP);
            if((g_mmi_java_ui_textbox.constraints & (~INPUT_TYPE_OVERRIDE_DEFAULT)) != IMM_INPUT_TYPE_PHONE_NUMBER)
            {
                if (g_mmi_java_ui_textbox.command_num == 0)
                {
                    ChangeRightSoftkeyByString(NULL, 0);
                    SetRightSoftkeyFunction(NULL, KEY_EVENT_UP);
                }
            }
        }
        else
        {

            if (g_mmi_java_ui_textbox.command_num > 0)
            {
                ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
                ChangeLeftSoftkeyByString((UI_string_type) g_mmi_java_ui_textbox.command_label[0], 0);
                SetLeftSoftkeyFunction(mmi_java_ui_textbox_leftkey_handler, KEY_EVENT_UP);
                SetCenterSoftkeyFunction(mmi_java_ui_textbox_leftkey_handler, KEY_EVENT_UP);

                if (g_mmi_java_ui_textbox.command_num == 2)
                {
                    ChangeRightSoftkeyByString((UI_string_type) g_mmi_java_ui_textbox.command_label[1], 0);
                    SetRightSoftkeyFunction(mmi_java_ui_textbox_rightkey_handler, KEY_EVENT_UP);
                }
            }
            else
            {
                ChangeLeftSoftkeyByString(NULL, 0);
                SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
                /* ResetCenterSoftkey(); */
                ChangeCenterSoftkey(0, 0);

				if(g_mmi_java_ui_textbox.text[0] == 0)
				{
				    ChangeRightSoftkeyByString(NULL, 0);
				    SetRightSoftkeyFunction(NULL, KEY_EVENT_UP);
				}
            }
        }
    }

    gdi_layer_unlock_frame_buffer();

    gdi_lcd_repaint_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_is_display_option
 * DESCRIPTION
 *  If the option menu of this texbox should be displayed.
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static kal_bool mmi_java_ui_textbox_is_display_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool displayInputMethod = KAL_FALSE;
    kal_bool displayInsertSymbol = KAL_FALSE;
    kal_uint8 tmp_menu_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
    if (mmi_imm_get_current_allowed_writing_language_num() > 1)
    {
        displayInputMethod = KAL_TRUE;
    }
#else /* defined(__MMI_IMC_CAPITAL_SWITCH__) */ 
    if (mmi_imm_get_required_mode_list_count((U32)g_mmi_java_ui_textbox.constraints) > 1)
    {
        displayInputMethod = KAL_TRUE;
    }
#endif /* defined(__MMI_IMC_CAPITAL_SWITCH__) */ 

#if defined(__MMI_EDITOR_OPTION_MENU_STYLE_1__) || defined (__MMI_EDITOR_OPTION_MENU_STYLE_2__) || defined (__MMI_EDITOR_OPTION_MENU_STYLE_3__)
    if (g_mmi_java_ui_textbox.is_editable)
    {
        displayInsertSymbol = KAL_TRUE;
    }
#endif /* defined(__MMI_EDITOR_OPTION_MENU_STYLE_1__) || defined (__MMI_EDITOR_OPTION_MENU_STYLE_2__) || defined (__MMI_EDITOR_OPTION_MENU_STYLE_3__) */ 

    if (g_mmi_java_ui_textbox.is_editable)
    {
        tmp_menu_num = 1;
    }
    else
    {
        tmp_menu_num = 2;
    }

    if ((g_mmi_java_ui_textbox.is_editable && (displayInputMethod || displayInsertSymbol)) ||
        g_mmi_java_ui_textbox.command_num > tmp_menu_num)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_ime_common_scr_entry_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  old_scr_id      [IN]        
 *  new_scr_id      [IN]        
 *  screen_id(?)        [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_ime_common_scr_entry_callback(kal_uint16 old_scr_id, kal_uint16 new_scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jam_resume_fg_mmi_screen_callback(
        old_scr_id,
        new_scr_id,
        mmi_java_ui_textbox_screen_type,
        MMI_JAVA_UI_SCREEN_TYPE_JAVA_MMI);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_ime_common_scr_exit_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  old_scr_id      [IN]        
 *  new_scr_id      [IN]        
 *  screen_id(?)        [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_ime_common_scr_exit_callback(kal_uint16 old_scr_id, kal_uint16 new_scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jam_exit_fg_mmi_screen_callback(old_scr_id, new_scr_id, NULL);
    if (!jam_is_enter_in_fg_mmi_screen_2(new_scr_id))
    {
        mmi_ime_register_editor_common_scr_entry_callback(NULL);
        mmi_ime_register_editor_common_scr_exit_callback(NULL);

        mmi_java_ui_textbox_screen_type = MMI_JAVA_UI_SCREEN_TYPE_UNKNOWN;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_add_extra_symbol
 * DESCRIPTION
 *  Add extra symbols into symbol table
 * CALLS
 *  
 * PARAMETERS
 *  out         [?]         [?]         [?]
 *  out_max     [IN]        
 *  in          [IN]        
 *  in_max      [IN]        
 * RETURNS
 *  S32         numbers of symbols to add
 *****************************************************************************/
kal_int32 mmi_java_ui_textbox_add_extra_symbol(kal_uint8 *out, kal_int32 out_max, kal_uint8 **in, kal_int32 in_max)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < sizeof(JTWISymbol) / 4; i++)
    {
        memcpy(out + in_max * 4 + i * 4, *(JTWISymbol + i), 4);
    }
    return (in_max + sizeof(JTWISymbol) / 4);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_is_need_add_extra_symbol
 * DESCRIPTION
 *  Add extra symbols into symbol table
 * CALLS
 *  
 * PARAMETERS
 *  void
 *  in_max(?)       [IN]        
 *  in(?)           [IN]        
 *  out_max(?)      [IN]        
 *  out         [?]         [?](?)
 * RETURNS
 *  S32         numbers of symbols to add
 *****************************************************************************/
kal_bool mmi_java_ui_textbox_is_need_add_extra_symbol()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 previousScrnId;
    kal_uint16 currScrnId;
    kal_uint16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_is_present(GRP_ID_JAVA_APP, SCR_ID_JAVA_UI_TEXTBOX_EDITOR, MMI_FRM_NODE_ALL_FLAG))
    {
        return KAL_FALSE;
    }

    currScrnId = SCR_ID_JAVA_UI_TEXTBOX_EDITOR;

    i = 1;
    previousScrnId = mmi_frm_scrn_get_neighbor_id(GRP_ID_JAVA_APP, currScrnId, MMI_FRM_NODE_BEFORE_FLAG);
    while (previousScrnId != SCR_ID_INVALID)    /* 10A */
    {
        currScrnId = previousScrnId;
        i++;
        previousScrnId = mmi_frm_scrn_get_neighbor_id(GRP_ID_JAVA_APP, currScrnId, MMI_FRM_NODE_BEFORE_FLAG);
    }

    if ((mmi_frm_scrn_get_count(GRP_ID_JAVA_APP) - i) > 2)
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_get_screen_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  U16         screen type
 *****************************************************************************/
kal_uint16 mmi_java_ui_textbox_get_screen_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return (kal_uint16)mmi_java_ui_textbox_screen_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textbox_set_screen_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_java_ui_textbox_set_screen_type(kal_uint16 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_java_ui_textbox_screen_type = (MMI_JAVA_UI_SCREEN_TYPE_ENUM)type;
}

#endif /* __J2ME__ */ 

