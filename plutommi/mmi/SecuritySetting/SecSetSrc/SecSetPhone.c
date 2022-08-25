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
 *  SecSetPhone.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Handling of phone security
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/****************************************************************************
 * Include
 ****************************************************************************/

#include "SecSetProt.h"
#include "SecSetSrvGprot.h"
#include "PwdCuiGprot.h"
#include "mmi_rp_app_mainmenu_def.h" /* MAIN_MENU_TITLE_SETTINGS_ICON */
#include "MMIDataType.h"
#include "mmi_rp_app_security_setting_def.h"
#include "menucuigprot.h"
#include "kal_general_types.h"
#include "wgui_categories_util.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "AlertScreen.h"
#include "mmi_frm_events_gprot.h"


/****************************************************************************
 * Global variables
 ****************************************************************************/

typedef struct
{
    mmi_id grp_id;
    mmi_id set_lock_cui;
    mmi_id change_pwd_cui;
} mmi_secset_phone_cntx_struct;


static mmi_secset_phone_cntx_struct g_mmi_secset_phone_cntx =
{
    GRP_ID_SECSET,
    0,
    0
};

#ifdef __MMI_SECSET_APP_WITH_BWUI__
typedef struct
{
    MMI_ID submenu_cui;
} mmi_secset_phone_lock_cntx_struct;

static mmi_secset_phone_lock_cntx_struct g_mmi_secset_phone_lock_cntx;

static void mmi_secset_entry_switch_phone_lock_menu(void);
#endif


/****************************************************************************
 * Functions
 ****************************************************************************/

static void mmi_secset_phone_set_lock(mmi_id grp_id);
static mmi_ret mmi_secset_phone_set_lock_proc(mmi_event_struct *evt);
static void mmi_secset_phone_change_password(mmi_id grp_id);
static mmi_ret mmi_secset_phone_change_password_proc(mmi_event_struct *evt);


mmi_ret mmi_secset_phone_menu_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_id;
    cui_menu_event_struct *menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct*)evt;
    menu_cui_id = menu_evt->sender_id;

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            if (menu_evt->parent_menu_id == MENU_ID_SECSET_PHONE_SETTING)
            {
            #ifndef __MMI_SECSET_APP_WITH_BWUI__
                MMI_BOOL phone_lock_is_enabled;

                phone_lock_is_enabled = srv_secset_phone_lock_is_enabled();
			#endif
            
                cui_menu_set_currlist_flags(menu_cui_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
                cui_menu_set_currlist_title(
                    menu_cui_id,
                    get_string(STR_ID_SECSET_PHONE_SETTING),
                    get_image(MAIN_MENU_TITLE_SETTINGS_ICON));
                #ifndef __MMI_SECSET_APP_WITH_BWUI__
                cui_menu_set_item_hint(
                    menu_cui_id,
                    MENU_ID_SECSET_PHONE_LOCK,
                    get_string(phone_lock_is_enabled ? STR_GLOBAL_ON : STR_GLOBAL_OFF));
                #endif
                cui_menu_set_access_by_shortcut(menu_evt->sender_id, MMI_FALSE);
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_HILITE:
            if (menu_evt->parent_menu_id == MENU_ID_SECSET_PHONE_SETTING)
            {
                #ifndef __MMI_SECSET_APP_WITH_BWUI__
                if (menu_evt->highlighted_menu_id == MENU_ID_SECSET_PHONE_LOCK)
                {
                    MMI_BOOL phone_lock_is_enabled;

                    phone_lock_is_enabled = srv_secset_phone_lock_is_enabled();
                
                    cui_menu_change_left_softkey_string(
                        menu_evt->sender_id,
                        get_string(phone_lock_is_enabled ? STR_GLOBAL_OFF : STR_GLOBAL_ON));
                }
                else
                #endif
                {
                    cui_menu_change_left_softkey_string(
                        menu_evt->sender_id,
                        get_string(STR_GLOBAL_OK));
                }
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            if (menu_evt->highlighted_menu_id == MENU_ID_SECSET_PHONE_LOCK)
            {
                #ifdef __MMI_SECSET_APP_WITH_BWUI__
                    mmi_secset_entry_switch_phone_lock_menu();
                #else
                mmi_secset_phone_set_lock(GRP_ID_SECSET);
                #endif
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_SECSET_CHANGE_PHONE_PASSWORD)
            {
                mmi_secset_phone_change_password(GRP_ID_SECSET);
            }
            break;
    }

    return MMI_RET_OK;
}


/*
 * Note: this function can be also launched by shortcut, see SecSet.res
 */
static void mmi_secset_phone_set_lock(mmi_id grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_phone_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = &g_mmi_secset_phone_cntx;

    cntx->grp_id = grp_id;
    
#ifdef __MMI_SECSET_APP_WITH_BWUI__
    cntx->set_lock_cui = cui_pwd_basic_create(
        cntx->grp_id,
        STR_ID_SECSET_INPUT_PHONE_PASSWORD_BWUI,
        MMI_SECSET_MIN_PHONE_PASSWORD_LEN,
        MMI_SECSET_MAX_PHONE_PASSWORD_LEN);

#else
    cntx->set_lock_cui = cui_pwd_basic_create(
        cntx->grp_id,
        STR_ID_SECSET_INPUT_PHONE_PASSWORD,
        MMI_SECSET_MIN_PHONE_PASSWORD_LEN,
        MMI_SECSET_MAX_PHONE_PASSWORD_LEN);
#endif
    cui_pwd_basic_set_proc(cntx->set_lock_cui, mmi_secset_phone_set_lock_proc, cntx);
#if 0
#if defined(UI_SMALL_PIN_EDITOR_SCREEN) && !defined(__MMI_FTE_SUPPORT__)
/* under construction !*/
#endif
#endif
    cui_pwd_basic_set_action_str(cntx->set_lock_cui, STR_GLOBAL_OK, STR_GLOBAL_BACK);

    cui_pwd_basic_run(cntx->set_lock_cui);
}


static mmi_ret mmi_secset_phone_set_lock_grp_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_RET_OK;
}


void mmi_secset_phone_set_lock_by_shortcut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_group_is_present(GRP_ID_SECSET_SHORTCUT))
    {
        mmi_frm_group_create_ex(
            GRP_ID_ROOT,
            GRP_ID_SECSET_SHORTCUT,
            mmi_secset_phone_set_lock_grp_proc,
            &g_mmi_secset_phone_cntx,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);
     /*
        mmi_frm_group_enter(
            GRP_ID_SECSET_SHORTCUT,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);
        */

        mmi_secset_phone_set_lock(GRP_ID_SECSET_SHORTCUT);
    }
    else
    {
        mmi_popup_display_ext(
            STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
            MMI_EVENT_FAILURE,
            NULL);
        
        /*
        mmi_popup_display(
            get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE),
            MMI_EVENT_FAILURE,
            NULL);
            */
    }
}


static mmi_ret mmi_secset_phone_set_lock_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_phone_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_secset_phone_cntx_struct*)evt->user_data;

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_PWD_BASIC_DONE:
        {
            cui_pwd_basic_done_evt_struct *done_evt;
			MMI_BOOL target_value;

            done_evt = (cui_pwd_basic_done_evt_struct*)evt;
            target_value = srv_secset_phone_lock_is_enabled()? MMI_FALSE: MMI_TRUE;
        
            if (srv_secset_phone_lock_set_enabled(
                    target_value,
                    done_evt->input,
                    mmi_secset_phone_set_lock_proc,
                    cntx) > 0)
            {
                mmi_secset_show_waiting(cntx->grp_id);
            }
            else
            {
                mmi_popup_display_simple(
                    get_string(STR_ID_SECSET_TEMP_FAIL),
                    MMI_EVENT_FAILURE,
                    cntx->grp_id,
                    cntx);
            }
            
            break;
        }

        case EVT_ID_SRV_SECSET_PHONE_LOCK_SET_ENABLED_RESULT:
        {
            srv_secset_phone_lock_set_enabled_result_evt_struct *result_evt;

            result_evt = (srv_secset_phone_lock_set_enabled_result_evt_struct*)evt;
            if (result_evt->success)
            {
                mmi_popup_display_simple(
                    get_string(result_evt->is_enabled ? STR_ID_SECSET_LOCKED : STR_ID_SECSET_UNLOCKED),
                    MMI_EVENT_SUCCESS,
                    cntx->grp_id,
                    cntx);
            
                cui_pwd_basic_close(cntx->set_lock_cui);
                cntx->set_lock_cui = 0;
            }
            else
            {
                mmi_popup_display_simple(
                    get_string(STR_ID_SECSET_WRONG_PHONE_PASSWORD),
                    MMI_EVENT_FAILURE,
                    cntx->grp_id,
                    cntx);

                cui_pwd_basic_clear_input(cntx->set_lock_cui);
            }

            mmi_secset_close_waiting(cntx->grp_id);

            break;
        }

        case EVT_ID_CUI_PWD_BASIC_CANCEL:
            cui_pwd_basic_close(cntx->set_lock_cui);
            cntx->set_lock_cui = 0;
            break;

        case EVT_ID_CUI_PWD_BASIC_PASSIVE_CLOSING:
            cntx->set_lock_cui = 0;
            break;
    }

    return MMI_RET_OK;
}


static void mmi_secset_phone_change_password(mmi_id grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_phone_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = &g_mmi_secset_phone_cntx;

    cntx->grp_id = grp_id;

#ifdef __MMI_SECSET_APP_WITH_BWUI__
    cntx->change_pwd_cui = cui_pwd_guard_create(
        cntx->grp_id,
        STR_ID_SECSET_OLD_PHONE_PASSWORD_BWUI,
        STR_ID_SECSET_NEW_PHONE_PASSWORD_BWUI,
        STR_ID_SECSET_CONFIRM_NEW_PHONE_PASSWORD_BWUI,
        MMI_SECSET_MIN_PHONE_PASSWORD_LEN,
        MMI_SECSET_MAX_PHONE_PASSWORD_LEN,
        MMI_SECSET_MIN_PHONE_PASSWORD_LEN,
        MMI_SECSET_MAX_PHONE_PASSWORD_LEN);

#else
    cntx->change_pwd_cui = cui_pwd_guard_create(
        cntx->grp_id,
        STR_ID_SECSET_OLD_PHONE_PASSWORD,
        STR_ID_SECSET_NEW_PHONE_PASSWORD,
        STR_ID_SECSET_CONFIRM_NEW_PHONE_PASSWORD,
        MMI_SECSET_MIN_PHONE_PASSWORD_LEN,
        MMI_SECSET_MAX_PHONE_PASSWORD_LEN,
        MMI_SECSET_MIN_PHONE_PASSWORD_LEN,
        MMI_SECSET_MAX_PHONE_PASSWORD_LEN);
#endif
    cui_pwd_guard_set_proc(cntx->change_pwd_cui, mmi_secset_phone_change_password_proc, cntx);
    cui_pwd_guard_set_diff_input_prompt(cntx->change_pwd_cui, STR_ID_SECSET_DIFF_NEW_PHONE_PASSWORD);

    cui_pwd_guard_run(cntx->change_pwd_cui);
}


static mmi_ret mmi_secset_phone_change_password_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_phone_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_secset_phone_cntx_struct*)evt->user_data;

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_PWD_GUARD_DONE:
        {
            cui_pwd_guard_done_evt_struct *done_evt;

            done_evt = (cui_pwd_guard_done_evt_struct*)evt;
            
            if (srv_secset_change_phone_password(
                    done_evt->guard,
                    done_evt->input,
                    mmi_secset_phone_change_password_proc,
                    cntx) > 0)
            {
                mmi_secset_show_waiting(cntx->grp_id);
            }
                
            break;
        }

        case EVT_ID_SRV_SECSET_CHANGE_PHONE_PASSWORD_RESULT:
        {
            srv_secset_change_phone_password_result_evt_struct *result_evt;

            result_evt = (srv_secset_change_phone_password_result_evt_struct*)evt;

            if (result_evt->success)
            {
                mmi_popup_display_simple(
                    get_string(STR_GLOBAL_DONE),
                    MMI_EVENT_SUCCESS,
                    cntx->grp_id,
                    cntx);
                    
                cui_pwd_guard_close(cntx->change_pwd_cui);
                cntx->change_pwd_cui = 0;
            }
            else
            {
                mmi_popup_display_simple(
                    get_string(STR_ID_SECSET_WRONG_PHONE_PASSWORD),
                    MMI_EVENT_FAILURE,
                    cntx->grp_id,
                    cntx);

                cui_pwd_guard_reset(cntx->change_pwd_cui);
            }

            mmi_secset_close_waiting(cntx->grp_id);

            break;
        }
    
        case EVT_ID_CUI_PWD_GUARD_CANCEL:
            cui_pwd_guard_close(cntx->change_pwd_cui);
            cntx->change_pwd_cui = 0;
            break;

        case EVT_ID_CUI_PWD_GUARD_PASSIVE_CLOSING:
            cntx->change_pwd_cui = 0;
            break;
    }

    return MMI_RET_OK;
}


#ifdef __MMI_SECSET_APP_WITH_BWUI__

static mmi_ret mmi_secset_switch_phone_lock_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt;
    mmi_menu_id CurrentMenu;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CurrentMenu=(srv_secset_phone_lock_is_enabled())? MENU_ID_SECURITY_SETTING_ON : MENU_ID_SECURITY_SETTING_OFF;

    if (cui_menu_is_menu_event(evt->evt_id))
    {
        menu_evt = (cui_menu_event_struct*)evt;

        switch (menu_evt->evt_id)
        {
            case EVT_ID_CUI_MENU_LIST_ENTRY:
                if (menu_evt->parent_menu_id == MENU_ID_SECSET_PHONE_LOCK)
                {
                    cui_menu_set_currlist_title(
                        menu_evt->sender_id,
                        get_string(STR_ID_SECSET_PHONE_LOCK),
                        get_image(MAIN_MENU_TITLE_SETTINGS_ICON));

                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
                    cui_menu_set_radio_list_item(menu_evt->sender_id, CurrentMenu);

                }
                break;
                
            case EVT_ID_CUI_MENU_ITEM_SELECT:
                if(menu_evt->highlighted_menu_id != CurrentMenu)
                {
                    mmi_secset_phone_set_lock(GRP_ID_SECSET_PHONE_LOCK);
                }
                else
                {
                    cui_menu_close(menu_evt->sender_id);
                }

                break;

            case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            {
                if (menu_evt->sender_id == g_mmi_secset_phone_lock_cntx.submenu_cui)
                {
                    g_mmi_secset_phone_lock_cntx.submenu_cui = 0;
                    cui_menu_close(menu_evt->sender_id);
                    return MMI_RET_OK;
                }
                break;
            }

            default:
                break;
        }
    
    }
    
    return MMI_RET_OK;
}


static void mmi_secset_entry_switch_phone_lock_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_phone_lock_cntx_struct   *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = &g_mmi_secset_phone_lock_cntx;
    
    mmi_frm_group_create_ex(
        GRP_ID_SECSET,
        GRP_ID_SECSET_PHONE_LOCK,
        mmi_secset_switch_phone_lock_proc,
        cntx,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    
    cntx->submenu_cui = cui_menu_create_and_run(
        GRP_ID_SECSET_PHONE_LOCK,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_FROM_RESOURCE,
        MENU_ID_SECSET_PHONE_LOCK,
        MMI_TRUE,
        cntx);

}
#endif /* __MMI_SECSET_APP_WITH_BWUI__ */

