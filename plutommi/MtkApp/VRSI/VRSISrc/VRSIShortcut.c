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
 * VRSIShortcut.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for open shorcut application by VRSI.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifndef _MMI_VRSISHORTCUT_C
#define _MMI_VRSISHORTCUT_C

#if defined(__MMI_VRSI__)

/*  Include: MMI header file */
#include "ProtocolEvents.h"

/* ... Add More MMI header */
#include "med_main.h"
#include "med_api.h"
#include "mdi_audio.h"
#include "VRSIType.h"
#include "VRSIProt.h"

/* Shortcut related */
//#include "ShortcutsDefs.h"
//#include "ShortcutsProts.h"
#include "Shortcutsgprots.h"
#include "mmi_rp_srv_vrsi_def.h"



#include "MMIDataType.h"
#include "stack_config.h"
#include "kal_trace.h"
#include "CustDataRes.h"
#include "kal_general_types.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "Unicodexdcl.h"
#include "GeneralDeviceGprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "wgui_categories_util.h"
#include "GlobalResDef.h"
#include "wgui_categories_popup.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "gui_data_types.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "menucuigprot.h"
#include "CommonScreensResDef.h"
#include "wgui_categories_list.h"
/*  Include: PS header file */
/* ... Add More PS header */

/* 
 * Typedef 
 */

/* 
 * Define
 */

/* 
 * Local Variable
 */
static U16 g_vrsi_scut_index;
static U32 g_vrsi_scut_count;

/* 
 * Local Function
 */

/* 
 * Global Variable
 */
//extern S32 ShctCheckItemCanbeExecuted(U16 selitem);

/* extern void  (*left_softkey_functions[])(void); */

/* 
 * Global Function
 */

#define MMI_VRSI_SHORTCUT_CENTRAL
extern mmi_ret mmi_vrsi_settings_event_proc(mmi_event_struct *evt);

/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_scut_central_add_all
 * DESCRIPTION
 *  This function add all shortcut name as central command.
 * PARAMETERS
 *  msg     [IN]        Message from protocol events
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_scut_central_add_all(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 long_list[MMI_VRSI_MAX_ADD_ENTRY];
    U16 *name_list[MMI_VRSI_MAX_ADD_ENTRY];
    U16 i, tag_num, add_count;
    U16 id_list[MMI_VRSI_MAX_ADD_ENTRY];
    U8 is_name_list[MMI_VRSI_MAX_ADD_ENTRY];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Abort while adding central command. Will close engine in abort function, so return directly. */
    if (g_vrsi_cntx.vrsi_state != MMI_VRSI_STATE_ADDING_CMD)
    {
        return;
    }

    add_count = g_vrsi_cntx.central_count;
    g_vrsi_scut_count = mmi_shct_get_candidate_list_count();
    kal_prompt_trace(MOD_MMI, "mmi_vrsi_scut_central_add_all, count = %d",g_vrsi_scut_count);
    if (add_count < g_vrsi_scut_count)
    {
        tag_num =
            ((g_vrsi_scut_count - add_count) <
             MMI_VRSI_MAX_ADD_ENTRY) ? (g_vrsi_scut_count - add_count) : MMI_VRSI_MAX_ADD_ENTRY;

        for (i = 0; i < tag_num; i++)
        {
            MMI_STR_ID  string_id = 0;
            string_id = mmi_shct_get_str_by_candidate_list_index(i + add_count);
            name_list[i] = (U16*) GetString(string_id);
            long_list[i] = i + add_count + MMI_VRSI_CMD_SCUT_BASE;
            is_name_list[i] = FALSE;
        }

        /* Get session id for each add operation */
        g_vrsi_cntx.session_id = mdi_audio_vrsi_new_session_id();

        /* Add SI tags */
        media_aud_vrsi_add_tags(
            MOD_MMI,
            g_vrsi_cntx.session_id,
            (U8*) g_vrsi_grammar[MMI_VRSI_GRAMMAR_1],
            tag_num,
            name_list,
            long_list,
            is_name_list,
            id_list);

        add_count += tag_num;

        /* Print add fail messages. */
        mmi_vrsi_init_central_count_fail(tag_num, id_list, long_list);
    }

    g_vrsi_cntx.central_count = add_count;

    /* More central command to add */
    if (add_count < g_vrsi_scut_count)
    {
        mmi_vrsi_init_central_add_req();
    }
    else
    {
        mmi_vrsi_scut_central_add_done();
    }
    mmi_vrsi_scut_central_add_done();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_scut_central_add_done
 * DESCRIPTION
 *  This function clear flag and add another central commmand.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_scut_central_add_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Add next app's central command */
    g_vrsi_cntx.central_count = 0;
    SetProtocolEventHandler(mmi_vrsi_city_central_add_all, PRT_MMI_VRSI_ADD_CENTRAL_REQ);
    mmi_vrsi_init_central_add_req();
}

#define MMI_VRSI_SHORTCUT_RCG


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_scut_rcg_grammar1_result
 * DESCRIPTION
 *  This function get shortcut index from the recogntion result.
 * PARAMETERS
 *  tag_num         [IN]        Tag number of recognition result
 *  long_list       [IN]        Tag id list of recognition result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_scut_rcg_grammar1_result(U16 tag_num, S32 *long_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!g_vrsi_scut_count)    
    {
        g_vrsi_scut_count = mmi_shct_get_candidate_list_count();
    }    
    
    if ((long_list[0] >= MMI_VRSI_CMD_SCUT_BASE) && (long_list[0] < MMI_VRSI_CMD_SCUT_BASE + g_vrsi_scut_count))
    {
        g_vrsi_scut_index = (U16) long_list[0] - MMI_VRSI_CMD_SCUT_BASE;

        mmi_vrsi_entry_scut_open_app();
    }
    else
    {
        mmi_vrsi_scut_no_app_prompt();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_scut_open_app
 * DESCRIPTION
 *  Entry function of display opening shortcut prompt.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_scut_open_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[MMI_VRSI_MAX_PROMPT_STR * ENCODING_LENGTH];
    U16 string_id;
    MMI_BOOL entry_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    string_id = mmi_shct_get_str_by_candidate_list_index(g_vrsi_scut_index);
    mmi_ucs2cpy(str_prompt, GetString(string_id));
    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_OPENING_PROMPT));

    TurnOnBacklight(1);
    entry_ret = mmi_frm_scrn_enter(
       GRP_ID_VRSI_RCG_MAIN, 
       SCR_ID_VRSI_OPEN_SCUT_PROMPT, 
       mmi_vrsi_exit_scut_open_app, 
       mmi_vrsi_entry_scut_open_app, 
       MMI_FRM_FG_ONLY_SCRN);
    if (mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
        EnableCenterSoftkey( 0, IMG_GLOBAL_COMMON_CSK);
    }
    ShowCategory66Screen(
        STR_ID_VRSI_APP,
        GetRootTitleIcon(MENU_ID_VRSI_SETTING),
        STR_GLOBAL_OK,      /* LSK STR */
        0,                  /* LSK IMG */
        STR_GLOBAL_CANCEL,   /* RSK STR */
        0,                  /* RSK IMG */
        (U8*) str_prompt,   /* message id */
        IMG_GLOBAL_PROGRESS,   /* icon id */ 
        NULL);

    if (mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_vrsi_scut_open_app, KEY_EVENT_UP);
    }

    SetLeftSoftkeyFunction(mmi_vrsi_scut_open_app, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_vrsi_rcg_abort, KEY_EVENT_UP);

#if defined(__MMI_VRSI_TRAIN_TAG__)
    mmi_vrsi_scut_open_app_play_prompt(str_prompt);
#else 
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_scut_open_app);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_exit_scut_open_app
 * DESCRIPTION
 *  Exit function of display opening shortcut prompt.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_exit_scut_open_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vrsi_rcg_close();
}

#if defined(__MMI_VRSI_TRAIN_TAG__)


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_scut_open_app_play_prompt
 * DESCRIPTION
 *  This function play SD tags of shortcut application, if no tag trained, play tts instead.
 * PARAMETERS
 *  str_prompt      [IN]        Input prompt string
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_scut_open_app_play_prompt(S8 *str_prompt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_vrsi_util_play_tag(
                MMI_VRSI_GRAMMAR_1,
                MMI_VRSI_APP_SHORTCUT,
                (U16) (g_vrsi_scut_index + MMI_VRSI_CMD_SCUT_BASE),
                mmi_vrsi_scut_open_app_play_prompt1);
    if (result == MED_RES_OK)
    {
        return;
    }

    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_scut_open_app);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_scut_open_app_play_prompt1
 * DESCRIPTION
 *  This function play the tts prompt of open shortcut.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_scut_open_app_play_prompt1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[MMI_VRSI_MAX_PROMPT_STR * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_OPENING_PROMPT));
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_scut_open_app);
}
#endif /* defined(__MMI_VRSI_TRAIN_TAG__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_scut_open_app
 * DESCRIPTION
 *  This function execute the entry function of shortcut application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_scut_open_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_shct_launch_app_by_candidate_list_index(g_vrsi_scut_index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_scut_no_app_prompt
 * DESCRIPTION
 *  This function play tts prompt for no application found.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_scut_no_app_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[MMI_VRSI_MAX_PROMPT_STR * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_RCG_NOT_FOUND));
    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_SHORTCUT_ITEM));
    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_SPEAK_AGAIN_PROMPT));

    /* Play prompt TTS */
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_entry_rcg);
}

#define MMI_VRSI_SHORTCUT_TRAINING
#if defined(__MMI_VRSI_TRAIN_TAG__)


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_scut_list_highlight_hdlr
 * DESCRIPTION
 *  highlight function for train SD tags.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_scut_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsi_scut_index = (U16) index;
}


static pBOOL mmi_vrsi_scut_get_list_item(S32 item_idx, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id;
    vrsi_sd_tag_struct tag_list[MMI_VRSI_MAX_SD_TAG];
    S16 pError;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_VRSI_TAG_LID, 1, (void*)tag_list, MMI_VRSI_MAX_SD_TAG * sizeof(vrsi_sd_tag_struct), &pError);
    string_id = mmi_shct_get_str_by_candidate_list_index(item_idx);
    mmi_ucs2ncpy((S8*) str_buff, (S8*) GetString(string_id), MAX_SUBMENU_CHARACTERS);
    if (mmi_vrsi_train_util_get_loc_in_list(MMI_VRSI_APP_SHORTCUT, (U16)(MMI_VRSI_CMD_SCUT_BASE + item_idx), tag_list) !=
       0xff)
    {
        *img_buff_p = (PU8) GetImage(IMG_ID_VRSI_APP);
    }
    else
    {
        *img_buff_p =(PU8) GetImage(IMG_ID_VRSI_SHORTCUT);
    }
    return MMI_TRUE;
}

mmi_ret mmi_vrsi_scut_proc(mmi_event_struct *evt)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
    /*************************Menu CUI event***************************/
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            break;
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_vrsi_scut_pre_entry_train_main();
            break;
        case EVT_ID_CUI_MENU_LIST_EXIT:
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            break;
            
    /**********************Alert CUI event*************************/
        case EVT_ID_ALERT_QUIT:
            break;        
        
        default:
            break;
    }
    return MMI_RET_OK;
}

#ifdef __MMI_FTE_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_kuro_list_tap_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vrsi_shortcut_list_tap_callback(mmi_tap_type_enum tap_type,S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tag_loc;
    U16 string_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM)
    {
        return;
    }
    mmi_frm_group_create(GRP_ID_VRSI, GRP_ID_VRSI_TRAIN_OPTION_MAIN, mmi_vrsi_settings_event_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_VRSI_TRAIN_OPTION_MAIN, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    string_id = mmi_shct_get_str_by_candidate_list_index(g_vrsi_scut_index);
    g_vrsi_cntx.long_name_ptr = (U16*)GetString(string_id);
    g_vrsi_cntx.long_list[0] = MMI_VRSI_CMD_SCUT_BASE + g_vrsi_scut_index;
    g_vrsi_cntx.long_list_num = 1;

    g_vrsi_cntx.curr_app = MMI_VRSI_APP_SHORTCUT;

    tag_loc = mmi_vrsi_train_util_get_id_and_loc(MMI_VRSI_APP_SHORTCUT, g_vrsi_cntx.long_list[0], NULL);
    if(tag_loc < 0xff)
    {
        mmi_vrsi_train_option_delete_confirm();
    }
    else
    {
        mmi_vrsi_train_option_pre_add();
    }
    
    return;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_scut_list
 * DESCRIPTION
 *  Entry function of train SD tag list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_scut_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    MMI_BOOL entry_ret; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(GRP_ID_VRSI_TRAIN_TAG_MAIN, GRP_ID_VRSI_TRAIN_SHORTCUT_LIST, mmi_vrsi_scut_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_VRSI_TRAIN_SHORTCUT_LIST, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    entry_ret = mmi_frm_scrn_enter(
       GRP_ID_VRSI_TRAIN_SHORTCUT_LIST, 
       SCR_ID_VRSI_TRAIN_SHORTCUT_LIST, 
       NULL, 
       mmi_vrsi_entry_scut_list, 
       MMI_FRM_UNKNOW_SCRN);


    gui_buffer = mmi_frm_scrn_get_gui_buf(GRP_ID_VRSI_TRAIN_SHORTCUT_LIST, SCR_ID_VRSI_TRAIN_SHORTCUT_LIST);

    if (gui_buffer == NULL)
        {
        g_vrsi_scut_count = mmi_shct_get_candidate_list_count();
        g_vrsi_scut_index = 0;
        }
    if (!g_vrsi_scut_count)
        {
         ShowCategory353Screen(
           (U8*)GetString(STR_ID_VRSI_SHORTCUT_LIST),
           GetRootTitleIcon(MENU_ID_VRSI_SETTING),
           NULL,
           NULL,
           STR_GLOBAL_BACK,
           IMG_GLOBAL_BACK,
           0,
           NULL,
           NULL,
           NULL,
           1,
           0,
           NULL);
       
        ClearKeyEvents();
        }
    else
    {
        RegisterHighlightHandler(mmi_vrsi_scut_list_highlight_hdlr);
        EnableCenterSoftkey( 0, IMG_GLOBAL_OPTION_CSK);
        ShowCategory183Screen(
           get_string(STR_ID_VRSI_SHORTCUT_LIST),
           get_image(GetRootTitleIcon(MENU_ID_VRSI_SETTING)),
           get_string(STR_GLOBAL_OPTIONS),
           get_image(IMG_GLOBAL_OPTIONS),
           get_string(STR_GLOBAL_BACK),
           get_image(IMG_GLOBAL_BACK),
           g_vrsi_scut_count,
           mmi_vrsi_scut_get_list_item, 
           NULL,
           NULL,
           MMI_FALSE,
           NULL,
           gui_buffer);  
        ClearKeyEvents();
        SetCenterSoftkeyFunction(mmi_vrsi_scut_pre_entry_train_main, KEY_EVENT_UP);
        #ifdef __MMI_FTE_SUPPORT__ 
           wgui_register_tap_callback(mmi_vrsi_shortcut_list_tap_callback);
        #endif

    SetLeftSoftkeyFunction(mmi_vrsi_scut_pre_entry_train_main, KEY_EVENT_UP);
    }       
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_scut_pre_entry_train_main
 * DESCRIPTION
 *  Exit function of train SD tag list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_scut_pre_entry_train_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tag_loc;
    U16 string_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "mmi_vrsi_scut_pre_entry_train_main");
    string_id = mmi_shct_get_str_by_candidate_list_index(g_vrsi_scut_index);
    g_vrsi_cntx.long_list[0] = MMI_VRSI_CMD_SCUT_BASE + g_vrsi_scut_index;
    g_vrsi_cntx.long_list_num = 1;

    g_vrsi_cntx.curr_app = MMI_VRSI_APP_SHORTCUT;

    tag_loc = mmi_vrsi_train_util_get_id_and_loc(MMI_VRSI_APP_SHORTCUT, g_vrsi_cntx.long_list[0], NULL);

    /* Modify, Playback, or delete exists voice tag. */
    if (tag_loc < 0xff)
    {
        mmi_vrsi_entry_train_option_del();
    }
    /* No tag exists, add new tag */
    else
    {
        mmi_vrsi_entry_train_option_add();
    }
}

#endif /* defined(__MMI_VRSI_TRAIN_TAG__) */ /* #if defined(__MMI_VRSI_TRAIN_TAG__) */

#endif /* defined(__MMI_VRSI__) */ /* #if defined(__MMI_VRSI__) */
#endif /* _MMI_VRSISHORTCUT_C */ /* #ifndef _MMI_VRSISHORTCUT_C */

