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
 *  APNControlList.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intended for the implementation of "ACL" feature.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include 
 *****************************************************************************/
/* Write your #include header file here */

#include "MMI_features.h"

#ifdef __MMI_ACL_SUPPORT__

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "GlobalResDef.h"
#include "GlobalMenuItems.h"
#include "CommonScreensResDef.h"
#include "AlertScreen.h"
#include "wgui_inputs.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "SettingResDef.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "mmi_rp_app_phonebook_def.h"
#include "wgui_categories_util.h"
#include "wgui_categories_list.h"
#include "GlobalConstants.h"
#include "ps_public_enum.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "mmi_frm_events_gprot.h"
#include "gui_typedef.h"
#include "ImeGprot.h"
#include "wgui_categories_inputs.h"
#include "wgui_categories_popup.h"
#include "custom_events_notify.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_msg_struct.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_msgs.h"
#include "stack_config.h"
#include "ps_public_struct.h"
#include "l3_inc_enums.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "CustMenuRes.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_rp_app_apn_control_def.h"

#include "APNControlList.h"
#include "PhoneBookGprot.h"
#include "PhoneBookProt.h"
#include "PhoneBookResDef.h"
#include "MainMenuDef.h"
#include "CommonScreens.h"
#include "SettingProfileEnum.h"
#include "SettingDefs.h"
#include "SettingGprots.h"
#include "GSM7BitDefaultAlphabet.h"

#include "SimCtrlSrvGprot.h"
#include "MenuCuiGprot.h"
#include "FSEditorCuiGprot.h"
#include "SecSetCuiGprot.h"
#include "mmi_frm_utility_gprot.h"

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
/* Define your local variable here */
/* Local variable are those variable only be used within this .c file. */

static mmi_acl_cntx_struct g_mmi_acl_cntx;
static mmi_acl_list_struct g_mmi_acl_list[MMI_SECSET_MAX_ACL_ENTRIES];

/* Declare your local function here */

static void mmi_secset_acl_entry_main(void);
static void mmi_secset_acl_entry_list(void);
static void mmi_secset_acl_entry_option(void);
static void mmi_secset_acl_entry_add_apn_prepare(void);
static void mmi_secset_acl_entry_edit_apn_prepare(void);
static void mmi_secset_acl_entry_add_apn(void);
static void mmi_secset_acl_entry_add_option(void);

static void mmi_secset_acl_save_confirm(void);
static void mmi_secset_acl_delete_confirm(void);

static void mmi_secset_pre_get_acl_list_req(void);
static void mmi_secset_get_acl_list_req(void);
static void mmi_secset_get_acl_list_rsp(void *info);

static void mmi_secset_add_acl_entry_req(void);
static void mmi_secset_add_acl_entry_rsp(void *info);

static void mmi_secset_set_acl_entry_req(void);
static void mmi_secset_set_acl_entry_rsp(void *info);

static void mmi_secset_del_acl_entry_req(void);
static void mmi_secset_del_acl_entry_rsp(void *info);

static void mmi_secset_pre_set_acl_mode_req(void);
static void mmi_secset_set_acl_mode_req(void);
static void mmi_secset_set_acl_mode_rsp(void *info);

static mmi_ret mmi_secset_leave_acl_list_req(mmi_event_struct *evt);
static void mmi_secset_get_pin2_status_req(void);
static void mmi_secset_go_back_history(void);
static MMI_BOOL mmi_secset_check_valid_apn(U16 *apn_name);

#ifdef DYNAMIC_ALLOCATE
static void mmi_secset_free_acl_list(void);
#endif

static mmi_ret mmi_secset_acl_entry_main_proc(mmi_event_struct *evt);
static mmi_ret mmi_secset_acl_entry_option_proc(mmi_event_struct *evt);
static mmi_ret mmi_secset_acl_entry_add_apn_proc(mmi_event_struct *evt);
static mmi_ret mmi_secset_acl_entry_add_option_proc(mmi_event_struct *evt);

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
/* Write your global variable here */
/* 
 * Global variable shall be declared in the XxxxProt.h (not XXXGprot.h),
 * it shall be accessible by files within the same module.
 */

mmi_acl_cntx_struct *const mmi_acl_p = &g_mmi_acl_cntx;

/***************************************************************************** 
 * Local Function
 *****************************************************************************/
/* Write your local function here */
/*
 * Local function can only be called within this .C file, it shall be declared as static.
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_acl_entry_group_main_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt         [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_secset_acl_entry_group_main_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;
    U16 menu_id = (U16) (U32) menu_evt->app_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            break;

        case EVT_ID_GROUP_ACTIVE:
            if (mmi_frm_is_in_backward_scenario() && mmi_frm_scrn_get_count(GRP_ID_PHB_EXTRA_NUMBER) == 0)
            {
                mmi_frm_group_close(GRP_ID_PHB_EXTRA_NUMBER);
            }
            break;

        case EVT_ID_CUI_MENU_LIST_ENTRY:
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            if (menu_id == MENU_ID_SECSET_ACL_MAIN)
            {
                mmi_secset_acl_entry_main_proc(evt);
            }
            else if (menu_id == MENU_ID_SECSET_ACL_OPTION)
            {
                mmi_secset_acl_entry_option_proc(evt);
            }
            else if (menu_id == MENU_ID_SECSET_ACL_INPUT_OPTION)
            {
                mmi_secset_acl_entry_add_option_proc(evt);
            }
            break;

        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
        case EVT_ID_CUI_FSEDITOR_CSK_PRESSED:
        case EVT_ID_CUI_FSEDITOR_ABORT:
        case EVT_ID_CUI_FSEDITOR_CHANGED:
            mmi_secset_acl_entry_add_apn_proc(evt);
            break;

        case EVT_ID_CUI_VERIFY_RESULT:
        {
            cui_verify_result_evt_struct *result_evt = (cui_verify_result_evt_struct*)evt;
            if (result_evt->success)
            {
                if (mmi_acl_p->verify_cb != NULL)
                {
                    mmi_acl_p->verify_cb();
                }
            }
            cui_verify_close(result_evt->sender_id);
            break;
        }

        case EVT_ID_CUI_VERIFY_CANCEL:
        {
            cui_verify_cancel_evt_struct *cancel_evt = (cui_verify_cancel_evt_struct*)evt;
            cui_verify_close(cancel_evt->sender_id);
            break;
        }

        case EVT_ID_ALERT_QUIT:
            {
                mmi_alert_result_evt_struct *alert_result = (mmi_alert_result_evt_struct*) evt;

                mmi_phb_confirm_display_handle(alert_result);
            }
            break;

        default:
            break;
    }

    if (cui_menu_is_menu_event(evt->evt_id))
    {
        wgui_inputs_options_menu_handler(evt, GRP_ID_PHB_EXTRA_NUMBER);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_acl_entry_group_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_secset_acl_entry_group_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_PHB_EXTRA_NUMBER, mmi_secset_acl_entry_group_main_proc, NULL);
    mmi_frm_group_enter(GRP_ID_PHB_EXTRA_NUMBER, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_secset_acl_entry_main();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_acl_entry_main_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt         [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_secset_acl_entry_main_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

            if (mmi_secset_get_acl_mode(g_mmi_acl_cntx.sim_id) == 1)
            {
                cui_menu_set_item_hint(menu_evt->sender_id, MENU_ID_SECSET_ACL_MODE, (UI_string_type) GetString(STR_GLOBAL_ON));
            }
            else
            {
                cui_menu_set_item_hint(menu_evt->sender_id, MENU_ID_SECSET_ACL_MODE, (UI_string_type) GetString(STR_GLOBAL_OFF));
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_HILITE:
            if (mmi_secset_get_acl_mode(g_mmi_acl_cntx.sim_id) == 1)
            {
                if (menu_evt->highlighted_menu_id == MENU_ID_SECSET_ACL_MODE)
                {
                    cui_menu_change_left_softkey_string(menu_evt->sender_id, (UI_string_type) GetString(STR_GLOBAL_OFF));
                }
                else
                {
                    cui_menu_change_left_softkey_string(menu_evt->sender_id, (UI_string_type) GetString(STR_GLOBAL_OK));
                }
            }
            else
            {
                if (menu_evt->highlighted_menu_id == MENU_ID_SECSET_ACL_MODE)
                {
                    cui_menu_change_left_softkey_string(menu_evt->sender_id, (UI_string_type) GetString(STR_GLOBAL_ON));
                }
                else
                {
                    cui_menu_change_left_softkey_string(menu_evt->sender_id, (UI_string_type) GetString(STR_GLOBAL_OK));
                }
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            if (menu_evt->highlighted_menu_id == MENU_ID_SECSET_ACL_MODE)
            {
                mmi_secset_pre_set_acl_mode_req();
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_SECSET_ACL_LIST)
            {
                mmi_secset_pre_get_acl_list_req();
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_acl_entry_main
 * DESCRIPTION
 *  entry for "Security setup->APN control"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_secset_acl_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_id = cui_menu_create(
                GRP_ID_PHB_EXTRA_NUMBER,
                CUI_MENU_SRC_TYPE_RESOURCE,
                CUI_MENU_TYPE_FROM_RESOURCE,
                MENU_ID_SECSET_ACL_MAIN,
                MMI_FALSE,
                (void*) (U32) MENU_ID_SECSET_ACL_MAIN);

    cui_menu_set_default_title(
        menu_id,
        (UI_string_type) GetString(STR_ID_SECSET_ACL_MAIN),
        (UI_image_type) GetImage(MAIN_MENU_TITLE_SETTINGS_ICON));

    cui_menu_run(menu_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_acl_list_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for "APN control->APN control list"
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_secset_acl_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_acl_cntx.hilite_item = (U16) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_acl_entry_list
 * DESCRIPTION
 *  entry for "APN control->APN control list"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_secset_acl_entry_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *list_of_items[MMI_SECSET_MAX_ACL_ENTRIES];
    U16 icons_list[MMI_SECSET_MAX_ACL_ENTRIES];
    U8 *gui_buffer;
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_enter(GRP_ID_PHB_EXTRA_NUMBER, SCR_ID_SECSET_ACL_LIST, NULL, mmi_secset_acl_entry_list, MMI_FRM_UNKNOW_SCRN);

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    for (index = 0; index < g_mmi_acl_cntx.acl_count; index++)
    {
    #ifndef DYNAMIC_ALLOCATE
        if (g_mmi_acl_list[index].acl_entry.apn[0] != '\0')
        {
            list_of_items[index] = (U8*) g_mmi_acl_list[index].acl_entry.apn;
        }
    #else /* DYNAMIC_ALLOCATE */
        if ((g_mmi_acl_list[index].acl_entry.apn_data[0] != 0) ||
            (g_mmi_acl_list[index].acl_entry.apn_data[1] != 0))
        {
            list_of_items[index] = g_mmi_acl_list[index].acl_entry.apn_data;
        }
    #endif /* DYNAMIC_ALLOCATE */
        else
        {
            list_of_items[index] = (U8*) GetString(STR_ID_SECSET_ACL_NETWORK_PROVIDED);
        }
        icons_list[index] = IMG_STORAGE_SIM;
    }

    if (g_mmi_acl_cntx.acl_count > 0)
    {
        if (g_mmi_acl_cntx.hilite_item >= g_mmi_acl_cntx.acl_count)
        {
            g_mmi_acl_cntx.hilite_item = g_mmi_acl_cntx.acl_count - 1;
        }
        else if (g_mmi_acl_cntx.is_new == MMI_TRUE)
        {
            g_mmi_acl_cntx.hilite_item = g_mmi_acl_cntx.acl_count - 1;
        }
        gui_buffer = NULL;
    }

    RegisterHighlightHandler(mmi_secset_acl_list_highlight_hdlr);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    if (g_mmi_acl_cntx.acl_count == 0)
    {
        list_of_items[0] = (U8*) GetString(STR_GLOBAL_EMPTY_LIST);

        ShowCategory6Screen(
            STR_ID_SECSET_ACL_LIST_CAPTION,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_GLOBAL_ADD,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            1,
            list_of_items,
            NULL,
            0,
            gui_buffer);

        SetLeftSoftkeyFunction(mmi_secset_acl_entry_add_apn_prepare, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_secset_acl_entry_add_apn_prepare, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
    else
    {
        ShowCategory53Screen(
            STR_ID_SECSET_ACL_LIST_CAPTION,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            g_mmi_acl_cntx.acl_count,
            list_of_items,
            icons_list,
            NULL,
            0,
            g_mmi_acl_cntx.hilite_item,
            gui_buffer);

        SetLeftSoftkeyFunction(mmi_secset_acl_entry_option, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_secset_acl_entry_edit_apn_prepare, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }

    /* If MMI leave "APN control list" */
    mmi_frm_scrn_set_leave_proc(GRP_ID_PHB_EXTRA_NUMBER, SCR_ID_SECSET_ACL_LIST, mmi_secset_leave_acl_list_req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_acl_entry_option_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt         [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_secset_acl_entry_option_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            if (menu_evt->highlighted_menu_id == MENU_ID_SECSET_ACL_ADD)
            {
                mmi_secset_acl_entry_add_apn_prepare();
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_SECSET_ACL_EDIT)
            {
                mmi_secset_acl_entry_edit_apn_prepare();
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_SECSET_ACL_DELETE)
            {
                mmi_secset_acl_delete_confirm();
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_acl_entry_option
 * DESCRIPTION
 *  entry for "APN control list->Options"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_secset_acl_entry_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_id = cui_menu_create(
                GRP_ID_PHB_EXTRA_NUMBER,
                CUI_MENU_SRC_TYPE_RESOURCE,
                CUI_MENU_TYPE_FROM_RESOURCE,
                MENU_ID_SECSET_ACL_OPTION,
                MMI_FALSE,
                (void*) (U32) MENU_ID_SECSET_ACL_OPTION);

    cui_menu_run(menu_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_acl_entry_add_apn_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt         [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_secset_acl_entry_add_apn_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
            cui_fseditor_get_text(
                g_mmi_acl_cntx.editor_id,
                g_mmi_acl_cntx.apn_name,
                MAX_APN_LEN * ENCODING_LENGTH);
            mmi_secset_acl_entry_add_option();
            break;

        case EVT_ID_CUI_FSEDITOR_CSK_PRESSED:
            cui_fseditor_get_text(
                g_mmi_acl_cntx.editor_id,
                g_mmi_acl_cntx.apn_name,
                MAX_APN_LEN * ENCODING_LENGTH);
            mmi_secset_acl_save_confirm();
            break;

        case EVT_ID_CUI_FSEDITOR_ABORT:
            g_mmi_acl_cntx.is_new = MMI_FALSE;
            cui_fseditor_close(g_mmi_acl_cntx.editor_id);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_acl_entry_add_apn_prepare
 * DESCRIPTION
 *  entry for "APN control list->Add"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_secset_acl_entry_add_apn_prepare(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_mmi_acl_cntx.apn_name, 0, MAX_APN_LEN * ENCODING_LENGTH);
    g_mmi_acl_cntx.is_new = MMI_TRUE;
    mmi_secset_acl_entry_add_apn();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_acl_entry_edit_apn_prepare
 * DESCRIPTION
 *  entry for "APN control list->Edit"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_secset_acl_entry_edit_apn_prepare(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef DYNAMIC_ALLOCATE
    mmi_ucs2cpy((CHAR *) g_mmi_acl_cntx.apn_name,
        (CHAR *) g_mmi_acl_list[g_mmi_acl_cntx.hilite_item].acl_entry.apn);
#else /* DYNAMIC_ALLOCATE */
    mmi_ucs2cpy((CHAR *) g_mmi_acl_cntx.apn_name,
        (CHAR *) g_mmi_acl_list[g_mmi_acl_cntx.hilite_item].acl_entry.apn_data);
#endif /* DYNAMIC_ALLOCATE */
    g_mmi_acl_cntx.is_new = MMI_FALSE;
    mmi_secset_acl_entry_add_apn();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_acl_entry_add_apn
 * DESCRIPTION
 *  entry for "APN control list->Add"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_secset_acl_entry_add_apn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id editor_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_mmi_acl_cntx.acl_count == MMI_SECSET_MAX_ACL_ENTRIES) && (g_mmi_acl_cntx.is_new == MMI_TRUE))
    {
        mmi_popup_display((WCHAR*) GetString(STR_ID_SECSET_ACL_MEMORY_FULL), MMI_EVENT_FAILURE, NULL);
    }
    else
    {
        editor_id = cui_fseditor_create(GRP_ID_PHB_EXTRA_NUMBER);

        g_mmi_acl_cntx.editor_id = editor_id;

        cui_fseditor_set_title(editor_id, STR_ID_SECSET_ACL_NAME, MAIN_MENU_TITLE_SETTINGS_ICON);
        cui_fseditor_set_softkey_text(editor_id, MMI_LEFT_SOFTKEY, STR_GLOBAL_OPTIONS);
        cui_fseditor_set_softkey_icon(editor_id, MMI_CENTER_SOFTKEY, IMG_GLOBAL_SAVE_CSK);
        cui_fseditor_set_text(
            editor_id,
            g_mmi_acl_cntx.apn_name,
            MAX_APN_LEN * ENCODING_LENGTH,
            MAX_APN_LEN - 1);
        cui_fseditor_set_input_method(
            editor_id,
            IMM_INPUT_TYPE_ENGLISH_SENTENCE,
            NULL,
            INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
        cui_fseditor_run(editor_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_acl_entry_add_option_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt         [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_secset_acl_entry_add_option_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            if (menu_evt->highlighted_menu_id == MENU_ID_SECSET_ACL_SAVE)
            {
                mmi_secset_acl_save_confirm();
            }
            else
            {
                /* Please do not return or close menu cui because edit option menu item
                   is not processed, it will be handled in the edit option proc */
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_acl_entry_add_option
 * DESCRIPTION
 *  entry for "Add->Options"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_secset_acl_entry_add_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_id = cui_menu_create(
                GRP_ID_PHB_EXTRA_NUMBER,
                CUI_MENU_SRC_TYPE_RESOURCE,
                CUI_MENU_TYPE_FROM_RESOURCE,
                MENU_ID_SECSET_ACL_INPUT_OPTION,
                MMI_FALSE,
                (void*) (U32) MENU_ID_SECSET_ACL_INPUT_OPTION);

    cui_menu_run(menu_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_acl_save_confirm
 * DESCRIPTION
 *  confirm screen for "Add->Options->Done"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_secset_acl_save_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_sim_ctrl_pwd_is_enabled(g_mmi_acl_cntx.sim_id, SRV_SIM_CTRL_PWD_TYPE_CHV2))
    {
        mmi_phb_confirm_display(
            (mmi_ucs2strlen((PS8) g_mmi_acl_cntx.apn_name) != 0) ?
                (UI_string_type) GetString(STR_GLOBAL_SAVE_ASK) :
                (UI_string_type) GetString(STR_ID_SECSET_ACL_ADD_DEFAULT_QUERY),
            GRP_ID_PHB_EXTRA_NUMBER,
            (g_mmi_acl_cntx.is_new == MMI_TRUE) ? 
                mmi_secset_add_acl_entry_req :
                mmi_secset_set_acl_entry_req,
            mmi_secset_go_back_history,
            MMI_TRUE);
        return;
    }

    mmi_acl_p->verify_cb =
        (g_mmi_acl_cntx.is_new == MMI_TRUE) ? mmi_secset_add_acl_entry_req : mmi_secset_set_acl_entry_req;

    mmi_phb_confirm_display(
        (mmi_ucs2strlen((CHAR *) g_mmi_acl_cntx.apn_name) != 0) ?
            (UI_string_type) GetString(STR_GLOBAL_SAVE_ASK) :
            (UI_string_type) GetString(STR_ID_SECSET_ACL_ADD_DEFAULT_QUERY),
        GRP_ID_PHB_EXTRA_NUMBER,
        mmi_secset_get_pin2_status_req,
        mmi_secset_go_back_history,
        MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_acl_delete_confirm
 * DESCRIPTION
 *  confirm screen for "APN control list->Delete"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_secset_acl_delete_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_sim_ctrl_pwd_is_enabled(g_mmi_acl_cntx.sim_id, SRV_SIM_CTRL_PWD_TYPE_CHV2))
    {
        mmi_phb_confirm_display(
            (UI_string_type) GetString(STR_ID_SECSET_ACL_DELETE_ASK),
            GRP_ID_PHB_EXTRA_NUMBER,
            mmi_secset_del_acl_entry_req,
            mmi_frm_scrn_close_active_id,
            MMI_FALSE);
        return;
    }

    mmi_acl_p->verify_cb = mmi_secset_del_acl_entry_req;

    mmi_phb_confirm_display(
        (UI_string_type) GetString(STR_ID_SECSET_ACL_DELETE_ASK),
        GRP_ID_PHB_EXTRA_NUMBER,
        mmi_secset_get_pin2_status_req,
        mmi_frm_scrn_close_active_id,
        MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_acl_entry_saving
 * DESCRIPTION
 *  waiting screen for "Add->Options->Done->Input PIN2"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_secset_acl_entry_saving(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(GRP_ID_PHB_EXTRA_NUMBER, SCR_ID_SECSET_ACL_SAVING, NULL, mmi_secset_acl_entry_saving, MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    ShowCategory66Screen(
        STR_ID_SECSET_ACL_LIST_CAPTION,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_GLOBAL_SAVING),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

    /* Keep in saving screen and no input can be accepted */
    ClearInputEventHandler(MMI_DEVICE_ALL);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_acl_entry_deleting
 * DESCRIPTION
 *  waiting screen for "APN control list->Delete->Input PIN2"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_secset_acl_entry_deleting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(GRP_ID_PHB_EXTRA_NUMBER, SCR_ID_SECSET_ACL_DELETING, NULL, mmi_secset_acl_entry_deleting, MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    ShowCategory66Screen(
        STR_ID_SECSET_ACL_LIST_CAPTION,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_GLOBAL_DELETING),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

    /* Keep in deleting screen and no input can be accepted */
    ClearInputEventHandler(MMI_DEVICE_ALL);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_acl_entry_waiting
 * DESCRIPTION
 *  waiting screen for "APN control->APN control list"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_secset_acl_entry_waiting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(GRP_ID_PHB_EXTRA_NUMBER, SCR_ID_SECSET_ACL_WAITING, NULL, mmi_secset_acl_entry_waiting, MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    ShowCategory66Screen(
        STR_ID_SECSET_ACL_LIST_CAPTION,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_GLOBAL_PLEASE_WAIT),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

    /* Keep in waiting screen and no input can be accepted */
    ClearInputEventHandler(MMI_DEVICE_ALL);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_reload_acl_list
 * DESCRIPTION
 *  reload acl list after adding/editing/deleting an acl entry
 * PARAMETERS
 *  evt         [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_secset_reload_acl_list(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
    case EVT_ID_ALERT_QUIT:
        mmi_secset_pre_get_acl_list_req();
        break;

    default:
        break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_pre_get_acl_list_req
 * DESCRIPTION
 *  before sending "get acl list" request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_secset_pre_get_acl_list_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_secset_acl_entry_waiting();

    g_mmi_acl_cntx.acl_count = 0;
#ifdef DYNAMIC_ALLOCATE
    mmi_secset_free_acl_list();
#endif
    mmi_secset_get_acl_list_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_get_acl_list_req
 * DESCRIPTION
 *  send "get acl list" request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_secset_get_acl_list_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ps_get_acl_entries_req_struct *local_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_secset_get_acl_list_rsp, MSG_ID_MMI_PS_GET_ACL_ENTRIES_RSP);

    local_ptr =
        (mmi_ps_get_acl_entries_req_struct*) OslConstructDataPtr(sizeof(mmi_ps_get_acl_entries_req_struct));
    local_ptr->start_index = g_mmi_acl_cntx.acl_count; /* acl index starts from 0 */
    local_ptr->max_read_entries = TCM_MAX_PEER_ACL_ENTRIES;

    mmi_frm_send_ilm(mmi_frm_sim_to_l4c_mod(g_mmi_acl_cntx.sim_id), MSG_ID_MMI_PS_GET_ACL_ENTRIES_REQ, (oslParaType*) local_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_get_acl_list_rsp
 * DESCRIPTION
 *  response of "get acl list"
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_secset_get_acl_list_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ps_get_acl_entries_rsp_struct *local_ptr;
    S32 i = 0, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_ps_get_acl_entries_rsp_struct*) info;

    if (local_ptr->result.flag == L4C_OK)
    {
        i = g_mmi_acl_cntx.acl_count;
        g_mmi_acl_cntx.acl_count += local_ptr->num_of_entries;

        if (g_mmi_acl_cntx.acl_count > MMI_SECSET_MAX_ACL_ENTRIES)
        {
            g_mmi_acl_cntx.acl_count = MMI_SECSET_MAX_ACL_ENTRIES;
        }

        for (; i < g_mmi_acl_cntx.acl_count; i++, j++)
        {
        #ifndef DYNAMIC_ALLOCATE
            mmi_asc_to_ucs2((CHAR *) g_mmi_acl_list[i].acl_entry.apn, (CHAR *) local_ptr->acl_list[j].apn);
        #else /* DYNAMIC_ALLOCATE */
            g_mmi_acl_list[i].acl_entry.apn_data =
                CovertStringForPlatform(
                    local_ptr->acl_list[j].apn,
                    (U16) strlen((CHAR *) local_ptr->acl_list[j].apn),
                    MMI_8BIT_DCS,
                    (PU16) &g_mmi_acl_list[i].acl_entry.apn_len);
        #endif /* DYNAMIC_ALLOCATE */
        }

        /* if (local_ptr->num_of_entries == TCM_MAX_PEER_ACL_ENTRIES) */
        if (local_ptr->more_flag && g_mmi_acl_cntx.acl_count < MMI_SECSET_MAX_ACL_ENTRIES)
        {
            mmi_secset_get_acl_list_req();
        }
        else
        {
            mmi_secset_acl_entry_list();
        }
    }
    else if (local_ptr->result.flag == 1 && local_ptr->result.cause == 5)
    {
        mmi_secset_acl_entry_list();
    }
    else
    {
        mmi_popup_display((WCHAR*) GetString(STR_ID_SECSET_ACL_TRY_LATER), MMI_EVENT_FAILURE, NULL);
    }
    mmi_frm_scrn_close(GRP_ID_PHB_EXTRA_NUMBER, SCR_ID_SECSET_ACL_WAITING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_add_acl_entry_req
 * DESCRIPTION
 *  send "add acl entry" request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_secset_add_acl_entry_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ps_add_acl_entry_req_struct *local_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_secset_acl_entry_saving();

    SetProtocolEventHandler(mmi_secset_add_acl_entry_rsp, MSG_ID_MMI_PS_ADD_ACL_ENTRY_RSP);

    local_ptr =
        (mmi_ps_add_acl_entry_req_struct*) OslConstructDataPtr(sizeof(mmi_ps_add_acl_entry_req_struct));
    mmi_ucs2_to_asc((CHAR *) local_ptr->acl_entry.apn, (CHAR *) g_mmi_acl_cntx.apn_name);

    mmi_frm_send_ilm(mmi_frm_sim_to_l4c_mod(g_mmi_acl_cntx.sim_id), MSG_ID_MMI_PS_ADD_ACL_ENTRY_REQ, (oslParaType*) local_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_add_acl_entry_rsp
 * DESCRIPTION
 *  response of "add acl entry"
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_secset_add_acl_entry_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ps_add_acl_entry_rsp_struct *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (mmi_ps_add_acl_entry_rsp_struct*) info;

    if (localPtr->result.flag == L4C_OK)
    {
        mmi_popup_property_struct arg;

        mmi_popup_property_init(&arg);
        arg.callback = mmi_secset_reload_acl_list;
        mmi_popup_display((WCHAR*) GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS, &arg);
    }
    else if (localPtr->result.cause == TCM_ACL_SIM_FILE_FULL)
    {
        mmi_popup_display((WCHAR*) GetString(STR_ID_SECSET_ACL_EF_SIZE_FULL), MMI_EVENT_FAILURE, NULL);
    }
    else
    {
        mmi_popup_display((WCHAR*) GetString(STR_ID_SECSET_ACL_TRY_LATER), MMI_EVENT_FAILURE, NULL);
    }

    mmi_frm_scrn_close(GRP_ID_PHB_EXTRA_NUMBER, SCR_ID_SECSET_ACL_SAVING);
    cui_fseditor_close(g_mmi_acl_cntx.editor_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_set_acl_entry_req
 * DESCRIPTION
 *  send "edit acl entry" request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_secset_set_acl_entry_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ps_set_acl_entry_req_struct *local_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_secset_acl_entry_saving();

    SetProtocolEventHandler(mmi_secset_set_acl_entry_rsp, MSG_ID_MMI_PS_SET_ACL_ENTRY_RSP);

    local_ptr =
        (mmi_ps_set_acl_entry_req_struct*) OslConstructDataPtr(sizeof(mmi_ps_set_acl_entry_req_struct));
    local_ptr->index = g_mmi_acl_cntx.hilite_item;
    mmi_ucs2_to_asc((CHAR *) local_ptr->acl_entry.apn, (CHAR *) g_mmi_acl_cntx.apn_name);

    mmi_frm_send_ilm(mmi_frm_sim_to_l4c_mod(g_mmi_acl_cntx.sim_id), MSG_ID_MMI_PS_SET_ACL_ENTRY_REQ, (oslParaType*) local_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_set_acl_entry_rsp
 * DESCRIPTION
 *  response of "edit acl entry"
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_secset_set_acl_entry_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ps_set_acl_entry_rsp_struct *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (mmi_ps_set_acl_entry_rsp_struct*) info;

    if (localPtr->result.flag == L4C_OK)
    {
        mmi_popup_property_struct arg;

        mmi_popup_property_init(&arg);
        arg.callback = mmi_secset_reload_acl_list;
        mmi_popup_display((WCHAR*) GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS, &arg);
    }
    else if (localPtr->result.cause == TCM_ACL_SIM_FILE_FULL)
    {
        mmi_popup_display((WCHAR*) GetString(STR_ID_SECSET_ACL_EF_SIZE_FULL), MMI_EVENT_FAILURE, NULL);
    }
    else
    {
        mmi_popup_display((WCHAR*) GetString(STR_ID_SECSET_ACL_TRY_LATER), MMI_EVENT_FAILURE, NULL);
    }

    mmi_frm_scrn_close(GRP_ID_PHB_EXTRA_NUMBER, SCR_ID_SECSET_ACL_SAVING);
    cui_fseditor_close(g_mmi_acl_cntx.editor_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_del_acl_entry_req
 * DESCRIPTION
 *  send "delete acl entry" request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_secset_del_acl_entry_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ps_del_acl_entry_req_struct *local_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_secset_acl_entry_deleting();

    SetProtocolEventHandler(mmi_secset_del_acl_entry_rsp, MSG_ID_MMI_PS_DEL_ACL_ENTRY_RSP);

    local_ptr =
        (mmi_ps_del_acl_entry_req_struct*) OslConstructDataPtr(sizeof(mmi_ps_del_acl_entry_req_struct));
    local_ptr->del_all = MMI_FALSE;
    local_ptr->index = g_mmi_acl_cntx.hilite_item;
    mmi_ucs2_to_asc((CHAR *) local_ptr->acl_entry.apn, (CHAR *) g_mmi_acl_cntx.apn_name);

    mmi_frm_send_ilm(mmi_frm_sim_to_l4c_mod(g_mmi_acl_cntx.sim_id), MSG_ID_MMI_PS_DEL_ACL_ENTRY_REQ, (oslParaType*) local_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_del_acl_entry_rsp
 * DESCRIPTION
 *  response of "delete acl entry"
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_secset_del_acl_entry_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ps_del_acl_entry_rsp_struct *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (mmi_ps_del_acl_entry_rsp_struct*) info;

    if (localPtr->result.flag == L4C_OK)
    {
        mmi_popup_property_struct arg;

        mmi_popup_property_init(&arg);
        arg.callback = mmi_secset_reload_acl_list;
        mmi_popup_display((WCHAR*) GetString(STR_GLOBAL_DELETED), MMI_EVENT_SUCCESS, &arg);
    }
    else
    {
        mmi_popup_display((WCHAR*) GetString(STR_ID_SECSET_ACL_TRY_LATER), MMI_EVENT_FAILURE, NULL);
    }

    mmi_frm_scrn_close(GRP_ID_PHB_EXTRA_NUMBER, SCR_ID_SECSET_ACL_DELETING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_pre_set_acl_mode_req
 * DESCRIPTION
 *  before sending "set acl mode" request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_secset_pre_set_acl_mode_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_sim_ctrl_pwd_is_enabled(g_mmi_acl_cntx.sim_id, SRV_SIM_CTRL_PWD_TYPE_CHV2))
    {
        mmi_secset_set_acl_mode_req();
        return;
    }

    mmi_acl_p->verify_cb = mmi_secset_set_acl_mode_req;
    mmi_secset_get_pin2_status_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_set_acl_mode_req
 * DESCRIPTION
 *  send "set acl mode" request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_secset_set_acl_mode_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ps_set_acl_mode_req_struct *local_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_secset_set_acl_mode_rsp, MSG_ID_MMI_PS_SET_ACL_MODE_RSP);

    local_ptr = OslConstructDataPtr(sizeof(mmi_ps_set_acl_mode_req_struct));
    local_ptr->on_off = (mmi_secset_get_acl_mode(g_mmi_acl_cntx.sim_id) == 1) ? 0 : 1;

    mmi_frm_send_ilm(mmi_frm_sim_to_l4c_mod(g_mmi_acl_cntx.sim_id), MSG_ID_MMI_PS_SET_ACL_MODE_REQ, (oslParaType*) local_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_set_acl_mode_rsp
 * DESCRIPTION
 *  response of "set acl mode"
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_secset_set_acl_mode_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ps_set_acl_mode_rsp_struct *local_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_ps_set_acl_mode_rsp_struct*) (info);

    if (local_ptr->result == 1)
    {
        if (mmi_secset_get_acl_mode(g_mmi_acl_cntx.sim_id) == 0)
        {
            mmi_secset_set_acl_mode(g_mmi_acl_cntx.sim_id, 1);
            mmi_popup_display((WCHAR*) GetString(STR_ID_SECSET_ACL_IS_ON), MMI_EVENT_SUCCESS, NULL);
        }
        else
        {
            mmi_secset_set_acl_mode(g_mmi_acl_cntx.sim_id, 0);
            mmi_popup_display((WCHAR*) GetString(STR_ID_SECSET_ACL_IS_OFF), MMI_EVENT_SUCCESS, NULL);
        }
    }
    else
    {
        mmi_popup_display((WCHAR*) GetString(STR_ID_SECSET_ACL_TRY_LATER), MMI_EVENT_FAILURE, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_leave_acl_list_req
 * DESCRIPTION
 *  send "leave acl list" request
 * PARAMETERS
 *  evt         [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_secset_leave_acl_list_req(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
    case EVT_ID_SCRN_DEINIT:
        g_mmi_acl_cntx.hilite_item = 0;
        g_mmi_acl_cntx.is_new = MMI_FALSE;

    #ifdef DYNAMIC_ALLOCATE
        mmi_secset_free_acl_list();
    #endif

        mmi_frm_send_ilm(mmi_frm_sim_to_l4c_mod(g_mmi_acl_cntx.sim_id), MSG_ID_MMI_PS_LEAVE_ACL_MENU_REQ, NULL, NULL);
        break;

    default:
        break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_get_pin2_status_req
 * DESCRIPTION
 *  before sending "get pin2 status" request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_secset_get_pin2_status_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id verify_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_secset_check_valid_apn(g_mmi_acl_cntx.apn_name))
    {
        mmi_popup_display((WCHAR*) GetString(STR_GLOBAL_INVALID_INPUT), MMI_EVENT_FAILURE, NULL);
        return;
    }
    else
    {
        verify_id = cui_verify_create(GRP_ID_PHB_EXTRA_NUMBER, CUI_VERIFY_TYPE_CHV2);
        cui_verify_set_sim(verify_id, g_mmi_acl_cntx.sim_id);
        cui_verify_run(verify_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_go_back_history
 * DESCRIPTION
 *  go back from "Add->Options->Done"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_secset_go_back_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_fseditor_close(g_mmi_acl_cntx.editor_id);
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_check_valid_apn
 * DESCRIPTION
 *  check if it is a valid apn
 * PARAMETERS
 *  apn_name        [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_secset_check_valid_apn(U16 *apn_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *str = apn_name;
    WCHAR valid_chars[] = 
    {
        L'A', L'B', L'C', L'D', L'E', L'F', L'G', L'H', L'I', L'J',
        L'K', L'L', L'M', L'N', L'O', L'P', L'Q', L'R', L'S', L'T',
        L'U', L'V', L'W', L'X', L'Y', L'Z',
        L'a', L'b', L'c', L'd', L'e', L'f', L'g', L'h', L'i', L'j',
        L'k', L'l', L'm', L'n', L'o', L'p', L'q', L'r', L's', L't',
        L'u', L'v', L'w', L'x', L'y', L'z',
        L'0', L'1', L'2', L'3', L'4', L'5', L'6', L'7', L'8', L'9',
        L'-', L'.'
    };
    S32 length = mmi_ucs2strlen((CHAR *) valid_chars);
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*str)
    {
        for (i = 0; i < length; i++)
        {
            if (*str == valid_chars[i])
            {
                break;
            }
        }

        if (i == length)
        {
            return MMI_FALSE;
        }

        str++;
    }

    return MMI_TRUE;
}

#ifdef DYNAMIC_ALLOCATE

/*****************************************************************************
 * FUNCTION
 *  mmi_secset_free_acl_list
 * DESCRIPTION
 *  free acl list buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_secset_free_acl_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_SECSET_MAX_ACL_ENTRIES; i++)
    {
        if (g_mmi_acl_list[i].acl_entry.apn_data != NULL)
        {
            OslMfree(g_mmi_acl_list[i].acl_entry.apn_data);
            g_mmi_acl_list[i].acl_entry.apn_data = NULL;
        }
    }
}

#endif /* DYNAMIC_ALLOCATE */

/***************************************************************************** 
 * Global Function 
 *****************************************************************************/
/* Write your global function here */
/* 
 * Global functions shall be declared in XxxProt.h or XxxGprot.h.
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_init_acl
 * DESCRIPTION
 *  initialization of "ACL (APN Control List)"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_secset_init_acl(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_acl_cntx.acl_count = 0;
    g_mmi_acl_cntx.is_new = MMI_FALSE;
    g_mmi_acl_cntx.hilite_item = 0;

    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_PS_GET_ACL_MODE_RSP, (PsIntFuncPtr) mmi_secset_get_acl_mode_rsp, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_acl_set_menu_item_properties
 * DESCRIPTION
 *  Set the properties of given menu item
 * PARAMETERS
 *  menu_cui        [IN]        
 *  sim             [IN]        
 *  menu_item_id    [IN]        
 *  mode            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_secset_acl_set_menu_item_properties(
        mmi_id menu_cui,
        mmi_sim_enum sim,
        mmi_menu_id menu_item_id,
        U8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_STR_ID hint_str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mode == 0xFF)
    {
        mmi_frm_hide_menu_item(menu_item_id);
    }
    else
    {
        hint_str = (mmi_secset_get_acl_mode(sim) == 1) ?
            STR_GLOBAL_ON : STR_GLOBAL_OFF;
        cui_menu_set_item_hint(menu_cui, menu_item_id, get_string(hint_str));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_acl_main_menu_proc
 * DESCRIPTION
 *  Menu proc for security setting main menu
 * PARAMETERS
 *  evt     [IN]    cui_menu_event_struct*
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_secset_acl_main_menu_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct*)evt;
    
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            if (cui_menu_get_index_in_currlist_from_menu_id(
                    menu_evt->sender_id,
                    MENU_ID_SECSET_ACL_MAIN) != CUI_MENU_INDEX_NOT_FOUND)
            {
                mmi_secset_acl_set_menu_item_properties(
                    menu_evt->sender_id,
                    MMI_SIM1,
                    MENU_ID_SECSET_ACL_MAIN,
                    mmi_acl_p->acl_mode[0]);
            }
#if (MMI_MAX_SIM_NUM >= 2)
            else if (cui_menu_get_index_in_currlist_from_menu_id(
                        menu_evt->sender_id,
                        MENU_ID_SECSET_ACL_SIM2) != CUI_MENU_INDEX_NOT_FOUND)
            {
                mmi_secset_acl_set_menu_item_properties(
                    menu_evt->sender_id,
                    MMI_SIM2,
                    MENU_ID_SECSET_ACL_SIM2,
                    mmi_acl_p->acl_mode[1]);
            }
#if (MMI_MAX_SIM_NUM >= 3)
            else if (cui_menu_get_index_in_currlist_from_menu_id(
                        menu_evt->sender_id,
                        MENU_ID_SECSET_ACL_SIM3) != CUI_MENU_INDEX_NOT_FOUND)
            {
                mmi_secset_acl_set_menu_item_properties(
                    menu_evt->sender_id,
                    MMI_SIM3,
                    MENU_ID_SECSET_ACL_SIM3,
                    mmi_acl_p->acl_mode[2]);
            }
#if (MMI_MAX_SIM_NUM >= 4)
            else if (cui_menu_get_index_in_currlist_from_menu_id(
                        menu_evt->sender_id,
                        MENU_ID_SECSET_ACL_SIM4) != CUI_MENU_INDEX_NOT_FOUND)
            {
                mmi_secset_acl_set_menu_item_properties(
                    menu_evt->sender_id,
                    MMI_SIM4,
                    MENU_ID_SECSET_ACL_SIM4,
                    mmi_acl_p->acl_mode[3]);
            }
#endif /* MMI_MAX_SIM_NUM >= 4 */
#endif /* MMI_MAX_SIM_NUM >= 3 */
#endif /* MMI_MAX_SIM_NUM >= 2 */
            else
            {
                /* The menu items we care are not in current list, ignore */
            }
            break;
    
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            if (menu_evt->highlighted_menu_id == MENU_ID_SECSET_ACL_MAIN)
            {
                g_mmi_acl_cntx.sim_id = MMI_SIM1;
                mmi_secset_acl_entry_group_main();
            }
#if (MMI_MAX_SIM_NUM >= 2)
            else if (menu_evt->highlighted_menu_id == MENU_ID_SECSET_ACL_SIM2)
            {
                g_mmi_acl_cntx.sim_id = MMI_SIM2;
                mmi_secset_acl_entry_group_main();
            }
#if (MMI_MAX_SIM_NUM >= 3)
            else if (menu_evt->highlighted_menu_id == MENU_ID_SECSET_ACL_SIM3)
            {
                g_mmi_acl_cntx.sim_id = MMI_SIM3;
                mmi_secset_acl_entry_group_main();
            }
#if (MMI_MAX_SIM_NUM >= 4)
            else if (menu_evt->highlighted_menu_id == MENU_ID_SECSET_ACL_SIM4)
            {
                g_mmi_acl_cntx.sim_id = MMI_SIM4;
                mmi_secset_acl_entry_group_main();
            }
#endif /* MMI_MAX_SIM_NUM >= 4 */
#endif /* MMI_MAX_SIM_NUM >= 3 */
#endif /* MMI_MAX_SIM_NUM >= 2 */
            else
            {
                /* Other menu item of security setting, should not handle */
            }
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_get_acl_mode_req
 * DESCRIPTION
 *  send "get acl mode" request
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_secset_get_acl_mode_req(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_send_ilm(mmi_frm_sim_to_l4c_mod(sim_id), MSG_ID_MMI_PS_GET_ACL_MODE_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_get_acl_mode_rsp
 * DESCRIPTION
 *  response of "get acl mode"
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_secset_get_acl_mode_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ps_get_acl_mode_rsp_struct *local_ptr;
    mmi_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_id = mmi_frm_l4c_mod_to_sim((module_type)mod_src);

    local_ptr = (mmi_ps_get_acl_mode_rsp_struct*) (info);

    switch (local_ptr->dial_mode)
    {
        case 0: /* ACL_NOT_SUPPORT */
            mmi_secset_set_acl_mode(sim_id, 0xFF);
            break;
        case 1: /* ACL_DISABLE */
            mmi_secset_set_acl_mode(sim_id, 0);
            break;
        case 2: /* ACL_ENABLE */
            mmi_secset_set_acl_mode(sim_id, 1);
            break;
        default:
            /* Shall not enter here */
            MMI_ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_get_acl_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  ACL mode, 1 for enabled, 0 for disabled
 *****************************************************************************/
U8 mmi_secset_get_acl_mode(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_acl_cntx.acl_mode[mmi_frm_sim_to_index(sim_id)];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_set_acl_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 *  acl_mode    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_secset_set_acl_mode(mmi_sim_enum sim_id, U8 acl_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_acl_cntx.acl_mode[mmi_frm_sim_to_index(sim_id)] = acl_mode;
}

#endif /* __MMI_ACL_SUPPORT__ */

