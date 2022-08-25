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
 * VoiceRedial.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Voice Shortcut.
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
 *------------------------------------------------------------------------------
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_VRSDSHORTCUT_C
#define _MMI_VRSDSHORTCUT_C

#if defined(__MMI_VRSD__) && defined(__MMI_VRSD_SHORTCUT__)

/*  Include: MMI header file */
#include "CommonScreens.h"
#include "nvram_user_defs.h"
#include "MessagesExDcl.h"
#include "SettingProfile.h"
#include "wgui_softkeys.h"

/* Med */
#include "med_global.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_main.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"

/* Shortcut related */
#include "ShortcutsDefs.h"
#include "ShortcutsProts.h"

#include "VRSDResDef.h"
#include "VRSD.h"
#include "VRSDShortcut.h"
#include "MainMenuDef.h"

/* 
 * Typedef 
 */

/* 
 * Define
 */

/* 
 * Local Variable
 */
static U16 g_vrsdscut_highlight = 0;
static U16 g_vrsdscut_list_id = 0;

/* 
 * Local Function
 */

/* 
 * Global Variable
 */

/* extern void  (*left_softkey_functions[])(void); */
extern S32 ShctCheckItemCanbeExecuted(U16 selitem);
/* 
 * Global Function
 */

#define MMI_VRSD_SHORTCUT_INIT


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdscut_init
 * DESCRIPTION
 *  This function initialize Voice Dial application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsdscut_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vrsd_register_rcg_callback(MMI_VRSD_APP_SHORTCUT, mmi_vrsdscut_rcg_callback);

    mmi_vrsdscut_init_highlight_handler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdscut_init_highlight_handler
 * DESCRIPTION
 *  This function initialize Voice Dial application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsdscut_init_highlight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_VRSD_SHORTCUT, mmi_vrsdscut_highlight_app);
   
    SetHiliteHandler(MENU_ID_VRSD_SHORTCUT_MAIN_ADD, mmi_vrsdscut_highlight_option_add);
    SetHiliteHandler(MENU_ID_VRSD_SHORTCUT_MAIN_CHANGE, mmi_vrsdscut_highlight_option_change);
    SetHiliteHandler(MENU_ID_VRSD_SHORTCUT_MAIN_DELETE, mmi_vrsdscut_highlight_option_del);
}

#define MMI_VRSD_SHORTCUT_LIST


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdscut_highlight_app
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdscut_highlight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    SetLeftSoftkeyFunction(mmi_vrsdscut_entry_list, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_vrsdscut_entry_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdscut_entry_list
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdscut_entry_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 *guiBuffer;
    U16 ShctCandList[SHCT_MAX_CANDI_LIST];  /* All shortcut candidate */
    U16 ImageList[SHCT_MAX_CANDI_LIST];
    vrsd_tag_struct tag_list[MMI_VRSD_MAX_TAG];
    S16 pError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VRSD_SHORTCUT_LIST, NULL, mmi_vrsdscut_entry_list, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VRSD_SHORTCUT_LIST);

    /* Read Voice Tag List */
    ReadRecord(NVRAM_EF_VRSD_TAG_LID, 1, (void*)tag_list, MMI_VRSD_MAX_TAG * sizeof(vrsd_tag_struct), &pError);

    /* Assign shortcut string and image */
    for (i = 0; i < g_shct_cntx.NumCandShct; i++)
    {
        ShctCandList[i] = ShctGetStringID(g_shct_cntx.CandShctList[i]);

        /* Check if shortcut item has voice tag */
        if (mmi_vrsd_util_get_tag_id_in_list(MMI_VRSD_APP_SHORTCUT, i, tag_list) != 0xffff)
        {
            ImageList[i] = IMG_ID_VRSD_APP;
        }
        else
        {
            ImageList[i] = IMG_ID_VRSD_SHORTCUT;
        }
    }

    if (guiBuffer == NULL)
    {
        g_vrsdscut_highlight = 0;
    }

    RegisterHighlightHandler(mmi_vrsdscut_list_highlight_hdlr);

    ShowCategory15Screen(
        STR_ID_VRSD_SHORTCUT,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_shct_cntx.NumCandShct,
        ShctCandList,
        (U16*) ImageList,
        LIST_MENU,
        g_vrsdscut_highlight,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_vrsdscut_entry_tag_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_vrsdscut_entry_tag_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdscut_exit_list
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdscut_exit_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(VRSD_DIAL_PLAYBACK_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdscut_list_highlight_hdlr
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  index       [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdscut_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsdscut_highlight = (U16) index;

    StopTimer(VRSD_DIAL_PLAYBACK_TIMER);
    StartTimer(VRSD_DIAL_PLAYBACK_TIMER, MMI_VRSD_PLAY_TAG_DELAY, mmi_vrsdscut_list_playback_tag);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdscut_list_playback_tag
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdscut_list_playback_tag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 tag_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tag_id = mmi_vrsd_util_get_tag_id(MMI_VRSD_APP_SHORTCUT, g_vrsdscut_highlight);
    if (tag_id != 0xffff)
    {
        mmi_vrsd_playback_req(tag_id, NULL);
    }
}

#define MMI_VRSD_SHORTCUT_OPTION


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdscut_highlight_option_add
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdscut_highlight_option_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vrsdscut_add_tag, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdscut_highlight_option_change
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdscut_highlight_option_change(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vrsdscut_change_tag, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdscut_highlight_option_del
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdscut_highlight_option_del(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vrsdscut_del_tag_confirm, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdscut_entry_tag_option
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdscut_entry_tag_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[4];
    U16 nNumofItem;

    U32 HideItemId = -1;
    U32 maskingByte = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VRSD_SHORTCUT_OPTION, NULL, mmi_vrsdscut_entry_tag_option, NULL);
   
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VRSD_SHORTCUT_OPTION);
    SetParentHandler(MENU_ID_VRSD_SHORTCUT_MAIN_MENU);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* Register all highlight handler again, because RsetBit() may change the highlight handler when hide menu. */
    mmi_vrsdscut_init_highlight_handler();

    mmi_frm_unhide_menu_item(MENU_ID_VRSD_SHORTCUT_MAIN_ADD);
    /* Display Change and Delete. */
    if (mmi_vrsd_util_get_tag_id(MMI_VRSD_APP_SHORTCUT, g_vrsdscut_highlight) != 0xffff)
    {
        mmi_frm_hide_menu_item(MENU_ID_VRSD_SHORTCUT_MAIN_ADD);
    }

    nNumofItem = GetNumOfChild_Ext(MENU_ID_VRSD_SHORTCUT_MAIN_MENU);
    GetSequenceStringIds_Ext(MENU_ID_VRSD_SHORTCUT_MAIN_MENU, nStrItemList);
    
    if (mmi_vrsd_util_get_tag_id(MMI_VRSD_APP_SHORTCUT, g_vrsdscut_highlight) == 0xffff)
    {
        nNumofItem = 1; /* Display add only */
    }

    ShowCategory15Screen(
        STR_ID_VRSD_SHORTCUT,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdscut_add_tag
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdscut_add_tag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_vrsd_cntx.vrtag_id = mmi_vrsd_util_get_tag_id(MMI_VRSD_APP_NONE, 0xffff)) != 0xffff) /* Use 0xffff as parameter to get "empty tag id" */
    {
        mmi_vrsd_train_init(MMI_VRSD_APP_SHORTCUT, g_vrsdscut_highlight, mmi_vrsdscut_train_result_callback);
    }
    else    /* No empty tag available */
    {
    	//failure
		mmi_display_popup(
			(UI_string_type)GetString(STR_ID_VRSD_NO_EMPTY_TAG),
			MMI_EVENT_FAILURE);
       
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdscut_change_tag
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdscut_change_tag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_vrsd_cntx.vrtag_id = mmi_vrsd_util_get_tag_id(MMI_VRSD_APP_SHORTCUT, g_vrsdscut_highlight)) != 0xffff)
    {
        mmi_vrsd_train_init(MMI_VRSD_APP_SHORTCUT, g_vrsdscut_highlight, mmi_vrsdscut_train_result_callback);
    }
    else
    {
    	//failure
		mmi_display_popup(
			(UI_string_type)GetString(STR_GLOBAL_EMPTY),
			MMI_EVENT_FAILURE);
      
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdscut_train_result_callback
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  result      [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdscut_train_result_callback(U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == MMI_VRSD_TRN_SUCCESS)
    {
    	//success
	mmi_display_popup(
			(UI_string_type)GetString(STR_GLOBAL_DONE),
			MMI_EVENT_SUCCESS);
       
    }
    else
    {
    	//failure
		mmi_display_popup(
			(UI_string_type)GetString(STR_GLOBAL_FAILURE),
			MMI_EVENT_FAILURE);
      
    }

    DeleteUptoScrID(SCR_ID_VRSD_SHORTCUT_LIST);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdscut_del_tag_confirm
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdscut_del_tag_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_display_popup_confirm(
            (UI_string_type)GetString(STR_GLOBAL_YES),
            (PU8)GetImage(IMG_GLOBAL_YES),
            (UI_string_type)GetString(STR_GLOBAL_NO),
            (PU8)GetImage(IMG_GLOBAL_NO),
            (UI_string_type)GetString(STR_ID_VRSD_DELETE_TAG_QUESTION),
            MMI_EVENT_QUERY);


    SetLeftSoftkeyFunction(mmi_vrsdscut_del_tag, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdscut_del_tag
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdscut_del_tag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 tag_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((tag_id = mmi_vrsd_util_get_tag_id(MMI_VRSD_APP_SHORTCUT, g_vrsdscut_highlight)) != 0xffff)
    {
        mmi_vrsd_del_tag_req(tag_id);
    }
    else
    {
    	//failure
		mmi_display_popup(
			(UI_string_type)GetString(STR_GLOBAL_EMPTY),
			MMI_EVENT_FAILURE);
       
    }

    DeleteUptoScrID(SCR_ID_VRSD_SHORTCUT_LIST);
}

#define MMI_VRSD_SHORTCUT_RCG


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdscut_rcg_callback
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  appref_id       [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdscut_rcg_callback(U16 appref_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (appref_id < g_shct_cntx.NumCandShct)
    {
        g_vrsdscut_list_id = appref_id;

        /* playback */
        mmi_vrsd_playback_req(g_vrsd_cntx.vrtag_id, mmi_vrsdscut_rcg_action);
    }
    else
    {
    	//failure
		mmi_display_popup(
			(UI_string_type)GetString(STR_ID_VRSD_NO_MATCH),
			MMI_EVENT_FAILURE);
        
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdscut_rcg_action
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdscut_rcg_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (ShctCheckItemCanbeExecuted(g_shct_cntx.CandShctList[g_vrsdscut_list_id]) == 0)
    {  
    #if defined(__MMI_DEDICATED_KEY_SHORTCUTS__)
        g_shct_cntx.IsKeyRetrieving = TRUE; /* To avoid blinking RSK and LSK when change highlight */
    #endif 
        (mmi_frm_get_hilite_hdlr(g_shct_cntx.CandShctList[g_vrsdscut_list_id])) ();
    #if defined(__MMI_DEDICATED_KEY_SHORTCUTS__)
         g_shct_cntx.IsKeyRetrieving = FALSE;
    #endif 
        /* left_softkey_functions[KEY_EVENT_UP](); */
        (get_softkey_function(KEY_EVENT_UP,MMI_LEFT_SOFTKEY))();
    }
}
#endif /* defined(__MMI_VRSD__) && defined(__MMI_VRSD_SHORTCUT__) */ /* #if defined(__MMI_VRSD__) && defined(__MMI_VRSD_SHORTCUT__) */
#endif /* _MMI_VRSDSHORTCUT_C */ /* #ifndef _MMI_VRSDSHORTCUT_C */

