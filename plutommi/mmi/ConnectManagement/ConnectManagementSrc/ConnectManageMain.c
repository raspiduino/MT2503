/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  ConnectManageMain.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is the main source file of Pluto CNMGR application.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/************************************************************
 * Include
 ************************************************************/
#include "MMI_features.h"

#if defined(__TCPIP__) && defined(__MMI_CBM_CONNECTION_MANAGER__) && defined(__PLUTO_MMI_PACKAGE__)

#include "mmi_include.h"

#include "Custom_events_notify.h"
#include "CommonScreens.h"
#include "mmi_frm_scenario_gprot.h"
#include "menucuigprot.h"

#include "l4c_common_enum.h"

#include "ConnectManageGProt.h"
#include "ConnectManageProt.h"
#include "mmi_rp_app_connectmanage_def.h"
#include "CnmgrSrvGprot.h"
#include "CnmgrSrvIprot.h"

#include "DataAccountGprot.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "GlobalResDef.h"
#include "cbm_consts.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "Unicodexdcl.h"
#include "CustDataRes.h"
#include "AlertScreen.h"
#include "gui_data_types.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "DtcntSrvGprot.h"
#include "GlobalConstants.h"
#include "wgui_categories_util.h"
#include "wgui_categories_text_viewer.h"
#include "wgui_categories_list.h"
#include "gui_inputs.h"
#include "wgui_inputs.h"
#include "CommonScreensResDef.h"
#include "stdio.h"
#include "wgui_categories_popup.h"


/************************************************************
 * Global Variable
 ************************************************************/
static mmi_cnmgr_bearer_list_struct g_cnmgr_app_bearer_list;
static U8 *g_cnmgr_app_bearer_name[SRV_CNMGR_MAX_BEARER_NUM];
static U8 *g_cnmgr_app_bearer_data_size[SRV_CNMGR_MAX_BEARER_NUM];
static mmi_cnmgr_context_struct g_cnmgr_app_context;


/************************************************************
 * Static Declaration
 ************************************************************/
static void mmi_cnmgr_entry_bearer_list(void);
static void mmi_cnmgr_show_bearer_list(mmi_scrn_essential_struct *scrn_data);
static void mmi_cnmgr_exit_bearer_list(void);
static void mmi_cnmgr_redraw_bearer_list(void);
static void mmi_cnmgr_bearer_list_screen_exit_callback(void);
static void mmi_cnmgr_bearer_list_highlight_hdlr(S32 index);
static void mmi_cnmgr_entry_bearer_list_option(void);
static mmi_ret mmi_cnmgr_evt_proc(mmi_event_struct *evt);
static void mmi_cnmgr_pre_entry_bearer_detail_info(void);
static void mmi_cnmgr_entry_bearer_detail_info(void);
static void mmi_cnmgr_show_bearer_detail_info(mmi_scrn_essential_struct *scrn_data);
static void mmi_cnmgr_exit_bearer_detail_info(void);
static void mmi_cnmgr_redraw_bearer_detail_info(void);
static void mmi_cnmgr_bearer_detail_info_screen_exit_callback(void);
static void mmi_cnmgr_disconnect_bearer_confirm(mmi_proc_func callback, U16 str_id);
static mmi_ret mmi_cnmgr_disconnect_bearer_confirm_callback(mmi_event_struct *evt);
static void mmi_cnmgr_disconnect_bearer_pre_handler(void);
static void mmi_cnmgr_disconnect_process(void);
static void mmi_cnmgr_disconnect_bearer_done(U8 result, void *user_data);
static void mmi_cnmgr_exit_disconnect_process_screen(void);
static mmi_ret mmi_cnmgr_disconnect_all_bearer_confirm_callback(mmi_event_struct *evt);
static void mmi_cnmgr_disconnect_all_bearer_pre_handler(void);
static void mmi_cnmgr_update_bearer_list(void);
static void mmi_cnmgr_register_bearer_data_update_notify_callback(void);
static void mmi_cnmgr_bearer_data_update_notify_callback(void *user_data);
static MMI_BOOL mmi_cnmgr_is_bearer_active(void);
static void mmi_cnmgr_get_select_bearer_data(void);
static void mmi_cnmgr_get_bearer_detail_info(void);
static void mmi_cnmgr_app_entry_bearer_detail_info(mmi_cnmgr_entry_screen_type_enum entry_type,
                                                   U32 acct_id,
                                                   U16 icon_id);
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_cnmgr_bearer_list_tap_callback(mmi_tap_type_enum tap_type, S32 index);
#endif


/************************************************************
 * Function
 ************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_cnmgr_entry_bearer_list
 * DESCRIPTION
 *  CNMGR main screen entry function: display bearer list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cnmgr_entry_bearer_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cnmgr_app_context.grp_id == GRP_ID_INVALID)
    {
        g_cnmgr_app_context.grp_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_cnmgr_evt_proc, (void*)NULL);
        if (g_cnmgr_app_context.grp_id != GRP_ID_INVALID)
        {
            mmi_frm_group_enter(g_cnmgr_app_context.grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        }
        else
        {
            mmi_popup_display_simple(
                (UI_string_type)GetString(STR_GLOBAL_ERROR),
                MMI_EVENT_FAILURE,
                GRP_ID_ROOT,
                NULL);
            return;
        }
    }

    if (mmi_frm_scrn_is_present(g_cnmgr_app_context.grp_id, SCR_ID_CNMGR_BEARER_LIST, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(g_cnmgr_app_context.grp_id, SCR_ID_CNMGR_BEARER_LIST);
    }

    mmi_frm_scrn_first_enter(
        g_cnmgr_app_context.grp_id,
        SCR_ID_CNMGR_BEARER_LIST,
        (FuncPtr)mmi_cnmgr_show_bearer_list,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cnmgr_show_bearer_list
 * DESCRIPTION
 *  This function is used to show bearer list screen.
 * PARAMETERS
 *  scrn_data       [IN]    Data related to the screen
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cnmgr_show_bearer_list(mmi_scrn_essential_struct *scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    U8 *gui_buffer; /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* 1. Enter screen */
    if(!mmi_frm_scrn_enter(
            g_cnmgr_app_context.grp_id,
            SCR_ID_CNMGR_BEARER_LIST,
            mmi_cnmgr_bearer_list_screen_exit_callback,
            (FuncPtr)mmi_cnmgr_show_bearer_list,
            MMI_FRM_FULL_SCRN))
    {
        /* Can not enter screen now. It can be entered later. */
        return;
    }

    /* 2. Get bearer list */
    mmi_cnmgr_update_bearer_list();
    MMI_TRACE(MMI_CNMGR_TRC_GROUP, MMI_CNMGR_SHOW_BEARER_LIST, g_cnmgr_app_bearer_list.bearer_num);

    /* 3. Get current screen to GUI buffer for history purpose */
    gui_buffer = mmi_frm_scrn_get_gui_buf(g_cnmgr_app_context.grp_id, SCR_ID_CNMGR_BEARER_LIST);
    if (gui_buffer == NULL)
    {
        g_cnmgr_app_context.list_select_idx = 0;
        g_cnmgr_app_context.list_highlight_idx = 0;
    }
    mmi_cnmgr_get_select_bearer_data();

    /* 4. Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(mmi_cnmgr_bearer_list_highlight_hdlr);

    if (g_cnmgr_app_bearer_list.bearer_num == 0)
    {
        if (g_cnmgr_app_context.enter_from_wap)
        { 
            ShowCategory7Screen(
                STR_ID_CNMGR_MAIN,
                g_cnmgr_app_context.wap_icon_id,
                0,  /* STR_GLOBAL_OPTIONS */
                0,  /* IMG_GLOBAL_OPTIONS */
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                (U8*)GetString(STR_ID_CNMGR_NO_CONNECTION),
                gui_buffer);
        }
        else
        {
            ShowCategory7Screen(
                STR_ID_CNMGR_MAIN,
                GetRootTitleIcon(MENU_ID_CNMGR_APP),
                0,  /* STR_GLOBAL_OPTIONS */
                0,  /* IMG_GLOBAL_OPTIONS */
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                (U8*)GetString(STR_ID_CNMGR_NO_CONNECTION),
                gui_buffer);
        }
        SetRightSoftkeyFunction(mmi_cnmgr_exit_bearer_list, KEY_EVENT_UP);
    }
    else
    {
        wgui_cat_block_list_effect();
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        if (g_cnmgr_app_context.enter_from_wap)
        {
            ShowCategory354Screen(
                (U8*)GetString(STR_ID_CNMGR_MAIN),
                g_cnmgr_app_context.wap_icon_id,
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                g_cnmgr_app_bearer_list.bearer_num,
                g_cnmgr_app_bearer_name,
                g_cnmgr_app_bearer_data_size,
                (PU16)gIndexIconsImageList,
                g_cnmgr_app_context.list_highlight_idx,
                gui_buffer);
        }
        else
        {
            ShowCategory354Screen(
                (U8*)GetString(STR_ID_CNMGR_MAIN),
                GetRootTitleIcon(MENU_ID_CNMGR_APP),
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                g_cnmgr_app_bearer_list.bearer_num,
                g_cnmgr_app_bearer_name,
                g_cnmgr_app_bearer_data_size,
                (PU16)gIndexIconsImageList,
                g_cnmgr_app_context.list_highlight_idx,
                gui_buffer);
        }

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        wgui_register_tap_callback(mmi_cnmgr_bearer_list_tap_callback);
#endif
        SetLeftSoftkeyFunction(mmi_cnmgr_entry_bearer_list_option, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_cnmgr_pre_entry_bearer_detail_info, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_cnmgr_exit_bearer_list, KEY_EVENT_UP);
    }

    /* 5. Register bearer list update callback */
    mmi_cnmgr_register_bearer_data_update_notify_callback();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cnmgr_exit_bearer_list
 * DESCRIPTION
 *  Exit bearer list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cnmgr_exit_bearer_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
* FUNCTION
*  mmi_cnmgr_redraw_bearer_list
* DESCRIPTION
*  Redraw bearer list screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_cnmgr_redraw_bearer_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 old_active_bearer_num = g_cnmgr_app_bearer_list.bearer_num;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cnmgr_update_bearer_list();

    MMI_TRACE(
        MMI_CNMGR_TRC_GROUP,
        MMI_CNMGR_REDRAW_BEARER_LIST,
        old_active_bearer_num,
        g_cnmgr_app_bearer_list.bearer_num);

    if (old_active_bearer_num == 0 &&
        g_cnmgr_app_bearer_list.bearer_num == 0)
    {
        return;
    }

    for (i = 0; i < g_cnmgr_app_bearer_list.bearer_num; i++)
    {
        if (g_cnmgr_app_bearer_list.bearer[i].account_id == g_cnmgr_app_context.select_bearer.account_id &&
            g_cnmgr_app_bearer_list.bearer[i].connect_type == g_cnmgr_app_context.select_bearer.connect_type)
        {
            g_cnmgr_app_context.list_select_idx = i;
            g_cnmgr_app_context.list_highlight_idx = i;
            mmi_cnmgr_get_select_bearer_data();
            break;
        }
    }
    if (i >= g_cnmgr_app_bearer_list.bearer_num)
    {
        g_cnmgr_app_context.list_select_idx = 0;
        g_cnmgr_app_context.list_highlight_idx = 0;

        if (g_cnmgr_app_bearer_list.bearer_num == 0)
        {
            memset(&g_cnmgr_app_context.select_bearer, 0, sizeof(mmi_cnmgr_bearer_detail_info_struct));
        }
        else
        {
            mmi_cnmgr_get_select_bearer_data();
        }
    }

    if (old_active_bearer_num != g_cnmgr_app_bearer_list.bearer_num)
    {
        mmi_frm_entry_new_screen(SCR_ID_DUMMY, NULL, NULL, NULL);
        mmi_frm_scrn_close_active_id();
    }
    else
    {
        RedrawCategoryFunction();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cnmgr_bearer_list_screen_exit_callback
 * DESCRIPTION
 *  Bearer list screen exit callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cnmgr_bearer_list_screen_exit_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Deregister bearer list update callback */
    srv_cnmgr_deregister_bearer_data_update_notify(mmi_cnmgr_bearer_data_update_notify_callback, NULL);
    g_cnmgr_app_context.reg_bearer_update_callback = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cnmgr_bearer_list_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of CNMGR bearer list screen
 * PARAMETERS
 *  index           [IN]    Highlight index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cnmgr_bearer_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cnmgr_app_context.list_select_idx = index;
    g_cnmgr_app_context.list_highlight_idx = index;
    mmi_cnmgr_get_select_bearer_data();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cnmgr_entry_bearer_list_option
 * DESCRIPTION
 *  Show Option menu of bearer list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cnmgr_entry_bearer_list_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_gid;
    srv_cnmgr_bearer_id_struct bearer;
    srv_cnmgr_bearer_data_struct bearer_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check if bearer is still valid first */
    bearer.account_id = g_cnmgr_app_context.select_bearer.account_id;
    bearer.connect_type = g_cnmgr_app_context.select_bearer.connect_type;
    if (srv_cnmgr_get_bearer_connection_data(&bearer, &bearer_data) == SRV_CNMGR_RESULT_SUCCESS)
    {
        memcpy(&(g_cnmgr_app_context.select_bearer.bearer_data), &bearer_data, sizeof(srv_cnmgr_bearer_data_struct));

        /* Check bearer status */
        if (g_cnmgr_app_context.select_bearer.bearer_data.bearer_status == SRV_CNMGR_BEARER_STATUS_ACTIVE)
        {
            /* Use menu CUI to show option menu */
            menu_gid = cui_menu_create(
                            g_cnmgr_app_context.grp_id,
                            CUI_MENU_SRC_TYPE_RESOURCE,
                            CUI_MENU_TYPE_OPTION,
                            MENU_ID_CNMGR_OPTION,
                            MMI_FALSE,
                            NULL);
            if (menu_gid == GRP_ID_INVALID)
            {
                mmi_popup_display_simple(
                    (UI_string_type)GetString(STR_GLOBAL_ERROR), 
                    MMI_EVENT_FAILURE,
                    g_cnmgr_app_context.grp_id,
                    NULL);
                return;
            }
            cui_menu_set_default_title_image(menu_gid, get_image(GetRootTitleIcon(IMG_ID_CNMGR_MAIN_ICON)));
            cui_menu_run(menu_gid);
        }
        else if (g_cnmgr_app_context.select_bearer.bearer_data.bearer_status == SRV_CNMGR_BEARER_STATUS_DEACTIVATING)
        {
            /* Bearer is in deactivating state. User can see bearer detail info only if bearer is activated. */
            mmi_popup_display_simple(
                (UI_string_type)GetString(STR_GLOBAL_DISCONNECTING), 
                MMI_EVENT_FAILURE,
                g_cnmgr_app_context.grp_id,
                NULL);
        }
        else
        {
            mmi_popup_display_simple(
                (UI_string_type)GetString(STR_GLOBAL_UNFINISHED), 
                MMI_EVENT_FAILURE,
                g_cnmgr_app_context.grp_id,
                NULL);
        }
    }
    else
    {
        /* Bearer is not valid anymore */
        mmi_popup_display_simple(
            (UI_string_type)GetString(STR_GLOBAL_UNFINISHED), 
            MMI_EVENT_FAILURE,
            g_cnmgr_app_context.grp_id,
            NULL);

        memset(&(g_cnmgr_app_context.select_bearer), 0, sizeof(mmi_cnmgr_bearer_detail_info_struct));
        g_cnmgr_app_context.list_select_idx = 0;
        g_cnmgr_app_context.list_highlight_idx = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cnmgr_evt_proc
 * DESCRIPTION
 *  Event proc function
 * PARAMETERS
 *  evt             [IN]    Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_cnmgr_evt_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            if (menu_evt->parent_menu_id == MENU_ID_CNMGR_OPTION &&
                g_cnmgr_app_bearer_list.bearer_num <= 1)
            {
                /* Hide "Disconnect all" option */
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_CNMGR_OPTION_DISC_ALL, MMI_TRUE);
            }
            break;
        }

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            switch (menu_evt->highlighted_menu_id)
            {
                case MENU_ID_CNMGR_OPTION_DISC:
                {
                    /* Disconnect the selected bearer */
                    mmi_cnmgr_disconnect_bearer_confirm(
                        mmi_cnmgr_disconnect_bearer_confirm_callback,
                        STR_ID_CNMGR_DISC_CONFIRM);
                    break;
                }

                case MENU_ID_CNMGR_OPTION_DISC_ALL:
                {
                    /* Disconnect all bearers */
                    mmi_cnmgr_disconnect_bearer_confirm(
                        mmi_cnmgr_disconnect_all_bearer_confirm_callback,
                        STR_ID_CNMGR_DISC_ALL_CONFIRM);
                    break;
                }

                case MENU_ID_CNMGR_OPTION_DETAIL:
                {
                    /* Display bearer detail info */
                    mmi_cnmgr_pre_entry_bearer_detail_info();
                    break;
                }
            }            
            break;
        }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(menu_evt->sender_id);
            break;
        }

        case EVT_ID_GROUP_DEINIT:
        {
            g_cnmgr_app_context.grp_id = GRP_ID_INVALID;

            /* Deregister bearer list update callback */
            srv_cnmgr_deregister_bearer_data_update_notify(mmi_cnmgr_bearer_data_update_notify_callback, NULL);
            g_cnmgr_app_context.reg_bearer_update_callback = MMI_FALSE;
            break;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cnmgr_pre_entry_bearer_detail_info
 * DESCRIPTION
 *  Check whether bearer is still valid before entering bearer detail info screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cnmgr_pre_entry_bearer_detail_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_cnmgr_is_bearer_active())
    {
        g_cnmgr_app_context.enter_from_wap = MMI_FALSE;
        mmi_cnmgr_entry_bearer_detail_info();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cnmgr_entry_bearer_detail_info
 * DESCRIPTION
 *  Entry bearer detail info screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cnmgr_entry_bearer_detail_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CNMGR_TRC_GROUP, MMI_CNMGR_ENTRY_BEARER_DETAIL_INFO);

    if (mmi_frm_scrn_is_present(g_cnmgr_app_context.grp_id, SCR_ID_CNMGR_BEARER_DETAIL, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(g_cnmgr_app_context.grp_id, SCR_ID_CNMGR_BEARER_DETAIL);
    }

    mmi_frm_scrn_first_enter(
        g_cnmgr_app_context.grp_id,
        SCR_ID_CNMGR_BEARER_DETAIL,
        (FuncPtr)mmi_cnmgr_show_bearer_detail_info,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cnmgr_show_bearer_detail_info
 * DESCRIPTION
 *  Entry bearer detail info screen: show bearer detail info
 * PARAMETERS
 *  scrn_data       [IN]    Screen data
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cnmgr_show_bearer_detail_info(mmi_scrn_essential_struct *scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer; /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CNMGR_TRC_GROUP, MMI_CNMGR_SHOW_BEARER_DETAIL_INFO);

    if(!mmi_frm_scrn_enter(
            g_cnmgr_app_context.grp_id, 
            SCR_ID_CNMGR_BEARER_DETAIL,
            mmi_cnmgr_bearer_detail_info_screen_exit_callback,
            (FuncPtr)mmi_cnmgr_show_bearer_detail_info,
            MMI_FRM_FULL_SCRN))
    {
        /* Canont enter screen now. It can be entered later. */
        return;
    }

    gui_buffer = mmi_frm_scrn_get_gui_buf(g_cnmgr_app_context.grp_id, SCR_ID_CNMGR_BEARER_DETAIL);

    mmi_cnmgr_get_bearer_detail_info();

    if (g_cnmgr_app_context.enter_from_wap)
    {
        ShowCategory74Screen(
            STR_GLOBAL_DETAILS,
            g_cnmgr_app_context.wap_icon_id,
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (PU8)subMenuData,
            MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
            gui_buffer);
    }
    else
    {
        ShowCategory74Screen(
            STR_GLOBAL_DETAILS,
            GetRootTitleIcon(MENU_ID_CNMGR_APP),
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (PU8)subMenuData,
            MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
            gui_buffer);
    }

    wgui_inputs_ml_set_style(0, GUI_MULTI_LINE_INPUT_BOX_DISABLE_CLIPBOARD);
    SetRightSoftkeyFunction(mmi_cnmgr_exit_bearer_detail_info, KEY_EVENT_UP);

    /* Register bearer data update callback */
    mmi_cnmgr_register_bearer_data_update_notify_callback();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cnmgr_exit_bearer_detail_info
 * DESCRIPTION
 *  Exit bearer detail info screen
 *  Back to Option menu or bearer list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cnmgr_exit_bearer_detail_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cnmgr_bearer_id_struct bearer;
    srv_cnmgr_bearer_data_struct bearer_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bearer.account_id = g_cnmgr_app_context.select_bearer.account_id;
    bearer.connect_type = g_cnmgr_app_context.select_bearer.connect_type;

    if (g_cnmgr_app_bearer_list.bearer_num == 0 ||
        srv_cnmgr_get_bearer_connection_data(&bearer, &bearer_data) != SRV_CNMGR_RESULT_SUCCESS)
    {
        if (mmi_frm_scrn_is_present(g_cnmgr_app_context.grp_id, SCR_ID_CNMGR_OPTION, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
        {
            mmi_frm_scrn_close(g_cnmgr_app_context.grp_id, SCR_ID_CNMGR_OPTION);
        }
    }
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
* FUNCTION
*  mmi_cnmgr_redraw_bearer_detail_info
* DESCRIPTION
*  Redraw bearer detail info screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_cnmgr_redraw_bearer_detail_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cnmgr_get_bearer_detail_info();
    wgui_cat074_change_text((U8*)subMenuData, MAX_SUBMENU_CHARACTERS * ENCODING_LENGTH, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cnmgr_bearer_detail_info_screen_exit_callback
 * DESCRIPTION
 *  Bearer detail info screen exit callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cnmgr_bearer_detail_info_screen_exit_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Deregister bearer list update callback */
    srv_cnmgr_deregister_bearer_data_update_notify(mmi_cnmgr_bearer_data_update_notify_callback, NULL);

    /* Register bearer list update callback */
    srv_cnmgr_register_bearer_data_update_notify(
        SRV_CNMGR_DATA_UPDATE_INTERVAL_DEFAULT_VALUE,
        mmi_cnmgr_bearer_data_update_notify_callback,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cnmgr_disconnect_bearer_confirm
 * DESCRIPTION
 *  Handler function for "Disconnect" menu item in Option menu
 * PARAMETERS
 *  callback        [IN]    Disconnect confirm callback
 *  str_id          [IN]    Displayed string
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cnmgr_disconnect_bearer_confirm(mmi_proc_func callback, U16 str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = g_cnmgr_app_context.grp_id;
    arg.callback = callback;
    mmi_confirm_display((UI_string_type)GetString(str_id), MMI_EVENT_QUERY, &arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cnmgr_disconnect_bearer_confirm_callback
 * DESCRIPTION
 *  Receive user's response for disconnecting connection or not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_cnmgr_disconnect_bearer_confirm_callback(mmi_event_struct *evt)
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
        {
            mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*)evt;
            switch (alert->result)
            {
                case MMI_ALERT_CNFM_YES:
                    mmi_cnmgr_disconnect_bearer_pre_handler();
                    break;

                case MMI_ALERT_CNFM_NO:
                    mmi_frm_scrn_close_active_id();
                    break;

                default:
                    break;
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
 *  mmi_cnmgr_disconnect_bearer_pre_handler
 * DESCRIPTION
 *  Disconnect bearer and show processing image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cnmgr_disconnect_bearer_pre_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cnmgr_bearer_id_struct bearer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_cnmgr_is_bearer_active())
    {
        bearer.account_id = g_cnmgr_app_context.select_bearer.account_id;
        bearer.connect_type = g_cnmgr_app_context.select_bearer.connect_type;

        if (srv_cnmgr_disconnect_bearer(&bearer, mmi_cnmgr_disconnect_bearer_done, NULL) == SRV_CNMGR_RESULT_WAIT_FOR_RSP)
        {
            mmi_cnmgr_disconnect_process();
        }
        else
        {
            mmi_cnmgr_disconnect_bearer_done(SRV_CNMGR_RESULT_SUCCESS, NULL);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cnmgr_disconnect_process
 * DESCRIPTION
 *  Display processing image when CNMGR is disconnecting connection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cnmgr_disconnect_process(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_is_present(g_cnmgr_app_context.grp_id, SCR_ID_CNMGR_DISCONNECT_PROCESS, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(g_cnmgr_app_context.grp_id, SCR_ID_CNMGR_DISCONNECT_PROCESS);
    }

    mmi_frm_scrn_enter(
        g_cnmgr_app_context.grp_id,
        SCR_ID_CNMGR_DISCONNECT_PROCESS,
        NULL,
        mmi_cnmgr_disconnect_process,
        MMI_FRM_SMALL_SCRN);

    ShowCategory66Screen(
        STR_GLOBAL_DISCONNECTING,
        GetRootTitleIcon(MENU_ID_CNMGR_APP),
        0,
        0,
        STR_GLOBAL_BACK,
        0,
        (U8*)GetString(STR_GLOBAL_DISCONNECTING),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

    /* Set RSK to abort disconnecting */
    SetRightSoftkeyFunction(mmi_cnmgr_exit_disconnect_process_screen, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cnmgr_disconnect_bearer_done
 * DESCRIPTION
 *  CNMGR service finish disconnecting bearer
 * PARAMETERS
 *  result          [IN]    Execution result
 *  user_data       [IN]    User data passed when calling CNMGR service interface
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cnmgr_disconnect_bearer_done(U8 result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SRV_CNMGR_RESULT_SUCCESS)
    {
        mmi_popup_display_simple(
            (UI_string_type)GetString(STR_GLOBAL_DONE),
            MMI_EVENT_SUCCESS,
            g_cnmgr_app_context.grp_id,
            NULL);
    }
    else
    {
        mmi_popup_display_simple(
            (UI_string_type)GetString(STR_GLOBAL_UNFINISHED),
            MMI_EVENT_FAILURE,
            g_cnmgr_app_context.grp_id,
            NULL);
    }

    if (mmi_frm_scrn_is_present(g_cnmgr_app_context.grp_id, SCR_ID_CNMGR_DISCONNECT_PROCESS, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        mmi_frm_scrn_close(g_cnmgr_app_context.grp_id, SCR_ID_CNMGR_DISCONNECT_PROCESS);
    }

    if (mmi_frm_scrn_is_present(g_cnmgr_app_context.grp_id, SCR_ID_CNMGR_OPTION, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        mmi_frm_scrn_close(g_cnmgr_app_context.grp_id, SCR_ID_CNMGR_OPTION);
    }

    if (mmi_frm_scrn_get_active_id() == SCR_ID_CNMGR_BEARER_LIST)
    {
        mmi_cnmgr_redraw_bearer_list(); 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cnmgr_exit_disconnect_process_screen
 * DESCRIPTION
 *  Go back from processing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cnmgr_exit_disconnect_process_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_is_present(g_cnmgr_app_context.grp_id, SCR_ID_CNMGR_OPTION, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        mmi_frm_scrn_close(g_cnmgr_app_context.grp_id, SCR_ID_CNMGR_OPTION);
    }

    if (mmi_frm_scrn_get_active_id() == SCR_ID_CNMGR_DISCONNECT_PROCESS)
    {
        mmi_frm_scrn_close_active_id();
    }
    else
    {
        if (mmi_frm_scrn_is_present(g_cnmgr_app_context.grp_id, SCR_ID_CNMGR_DISCONNECT_PROCESS, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
        {
            mmi_frm_scrn_close(g_cnmgr_app_context.grp_id, SCR_ID_CNMGR_DISCONNECT_PROCESS);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cnmgr_disconnect_all_bearer_confirm_callback
 * DESCRIPTION
 *  Receive user's response for disconnecting all connections or not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_cnmgr_disconnect_all_bearer_confirm_callback(mmi_event_struct *evt)
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
        {
            mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*)evt;
            switch (alert->result)
            {
                case MMI_ALERT_CNFM_YES:
                    mmi_cnmgr_disconnect_all_bearer_pre_handler();
                    break;

                case MMI_ALERT_CNFM_NO:
                    mmi_frm_scrn_close_active_id();
                    break;

                default:
                    break;
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
 *  mmi_cnmgr_disconnect_all_bearer_pre_handler
 * DESCRIPTION
 *  Disconnect all bearers and show processing image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cnmgr_disconnect_all_bearer_pre_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cnmgr_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_cnmgr_disconnect_all_bearer(mmi_cnmgr_disconnect_bearer_done, NULL);

    if (result == SRV_CNMGR_RESULT_WAIT_FOR_RSP)
    {
        mmi_cnmgr_disconnect_process();
    }
    else if (result == SRV_CNMGR_RESULT_NO_CONNECTION)
    {
        mmi_cnmgr_disconnect_bearer_done(SRV_CNMGR_RESULT_SUCCESS, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cnmgr_update_bearer_list
 * DESCRIPTION
 *  This function is used to get the latest bearer list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cnmgr_update_bearer_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cnmgr_bearer_list_struct active_bearer_list;
    CHAR data_size_str[MMI_CNMGR_MAX_DATA_SIZE_STR_LEN + 1];
    S32 i;
    float data_size;
    cbm_bearer_enum bearer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_cnmgr_app_bearer_list, 0, sizeof(mmi_cnmgr_bearer_list_struct));
    memset(&g_cnmgr_app_bearer_name, 0, sizeof(U8*) * SRV_CNMGR_MAX_BEARER_NUM);
    memset(&g_cnmgr_app_bearer_data_size, 0, sizeof(U8*) * SRV_CNMGR_MAX_BEARER_NUM);

    /* Get active bearer list */
    srv_cnmgr_get_active_bearer_list(&active_bearer_list);

    MMI_TRACE(MMI_CNMGR_TRC_GROUP, MMI_CNMGR_UPDATE_BEARER_LIST, active_bearer_list.active_node_num);

    g_cnmgr_app_bearer_list.bearer_num = active_bearer_list.active_node_num;

    for (i = 0; i < active_bearer_list.active_node_num; i++)
    {
        g_cnmgr_app_bearer_list.bearer[i].account_id = active_bearer_list.node[i].account_id;
        g_cnmgr_app_bearer_list.bearer[i].connect_type = active_bearer_list.node[i].connect_type;
        g_cnmgr_app_bearer_list.bearer[i].all_data_size = active_bearer_list.node[i].all_data_size;
        g_cnmgr_app_bearer_list.bearer[i].connect_time = active_bearer_list.node[i].connect_time;
        g_cnmgr_app_bearer_list.bearer[i].dialup_type = active_bearer_list.node[i].dialup_type;

        /* Get profile name of each bearer */
        cbm_get_bearer_type(g_cnmgr_app_bearer_list.bearer[i].account_id, &bearer);
        if (bearer & CBM_WIFI)
        {
            mmi_ucs2cpy(g_cnmgr_app_bearer_list.bearer[i].profile_name, GetString(STR_GLOBAL_WIFI));
        }
        else if (g_cnmgr_app_bearer_list.bearer[i].connect_type == SRV_CNMGR_CONNECT_TYPE_DIALUP)
        {
            mmi_ucs2cpy(g_cnmgr_app_bearer_list.bearer[i].profile_name, GetString(STR_ID_CNMGR_DETAIL_TYPE_DAILUP));
        }
        else
        {
            mmi_dtcnt_get_full_account_name(
                g_cnmgr_app_bearer_list.bearer[i].account_id,
                g_cnmgr_app_bearer_list.bearer[i].profile_name,
                MMI_CNMGR_MAX_PROFILE_NAME_LEN,
                MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);
        }
        g_cnmgr_app_bearer_name[i] = (U8*)g_cnmgr_app_bearer_list.bearer[i].profile_name;

        /* Compose data size string */
        data_size = ((float)g_cnmgr_app_bearer_list.bearer[i].all_data_size) / MMI_CNMGR_DATA_UNIT_SIZE;
        sprintf(data_size_str, "%0.2fKB", data_size);
        mmi_asc_n_to_ucs2(g_cnmgr_app_bearer_list.bearer[i].data_size_str, data_size_str, MMI_CNMGR_MAX_DATA_SIZE_STR_LEN);
        g_cnmgr_app_bearer_data_size[i] = (U8*)g_cnmgr_app_bearer_list.bearer[i].data_size_str;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cnmgr_register_bearer_data_update_notify_callback
 * DESCRIPTION
 *  This function is used to register bearer data update notify callback.
 * PARAMETERS
 *  user_data       [IN]    User data
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cnmgr_register_bearer_data_update_notify_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cnmgr_app_context.reg_bearer_update_callback == MMI_TRUE)
    {
        srv_cnmgr_deregister_bearer_data_update_notify(mmi_cnmgr_bearer_data_update_notify_callback, NULL);
    }

    srv_cnmgr_register_bearer_data_update_notify(
        SRV_CNMGR_DATA_UPDATE_INTERVAL_1_SEC,
        mmi_cnmgr_bearer_data_update_notify_callback,
        NULL);
    g_cnmgr_app_context.reg_bearer_update_callback = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cnmgr_bearer_data_update_notify_callback
 * DESCRIPTION
 *  This function is used to refresh bearer list screen.
 * PARAMETERS
 *  user_data       [IN]    User data
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cnmgr_bearer_data_update_notify_callback(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID active_screen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CNMGR_TRC_GROUP, MMI_CNMGR_BEARER_DATA_UPDATE_NOTIFY_CALLBACK);

    active_screen = mmi_frm_scrn_get_active_id();

    if (active_screen == SCR_ID_CNMGR_BEARER_LIST)
    {
        mmi_cnmgr_redraw_bearer_list(); 
    }
    else if (active_screen == SCR_ID_CNMGR_BEARER_DETAIL)
    {
        mmi_cnmgr_redraw_bearer_detail_info();

        if (g_cnmgr_app_context.select_bearer.bearer_data.bearer_status == SRV_CNMGR_BEARER_STATUS_DEACTIVE &&
            mmi_frm_scrn_is_present(g_cnmgr_app_context.grp_id, SCR_ID_CNMGR_OPTION, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
        {
            mmi_frm_scrn_close(g_cnmgr_app_context.grp_id, SCR_ID_CNMGR_OPTION);
        }
    }
    else
    {
        /* Update selected bearer data and do not refresh screen */
        srv_cnmgr_bearer_id_struct bearer;
        srv_cnmgr_bearer_data_struct bearer_data;

        bearer.account_id = g_cnmgr_app_context.select_bearer.account_id;
        bearer.connect_type = g_cnmgr_app_context.select_bearer.connect_type;
        if (srv_cnmgr_get_bearer_connection_data(&bearer, &bearer_data) == SRV_CNMGR_RESULT_SUCCESS)
        {
            memcpy(&(g_cnmgr_app_context.select_bearer.bearer_data), &bearer_data, sizeof(srv_cnmgr_bearer_data_struct));
        }
        else
        {
            g_cnmgr_app_context.select_bearer.bearer_data.bearer_status = SRV_CNMGR_BEARER_STATUS_DEACTIVE;
        }

        /* Close option menu if selected bearer is deactive */
        if (g_cnmgr_app_context.select_bearer.bearer_data.bearer_status == SRV_CNMGR_BEARER_STATUS_DEACTIVE &&
            mmi_frm_scrn_is_present(g_cnmgr_app_context.grp_id, SCR_ID_CNMGR_OPTION, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
        {
            mmi_frm_scrn_close(g_cnmgr_app_context.grp_id, SCR_ID_CNMGR_OPTION);
        }
    }
}
    

/*****************************************************************************
 * FUNCTION
 *  mmi_cnmgr_is_bearer_active
 * DESCRIPTION
 *  Check if bearer is still active before entering bearer detail info screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_cnmgr_is_bearer_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cnmgr_bearer_id_struct bearer;
    srv_cnmgr_bearer_data_struct bearer_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CNMGR_TRC_GROUP,
        MMI_CNMGR_IS_BEARER_ACTIVE,
        g_cnmgr_app_context.list_select_idx,
        g_cnmgr_app_context.select_bearer.account_id,
        g_cnmgr_app_context.select_bearer.connect_type);

    /* Check if bearer is still valid first */
    bearer.account_id = g_cnmgr_app_context.select_bearer.account_id;
    bearer.connect_type = g_cnmgr_app_context.select_bearer.connect_type;
    if (srv_cnmgr_get_bearer_connection_data(&bearer, &bearer_data) == SRV_CNMGR_RESULT_SUCCESS)
    {
        memcpy(&(g_cnmgr_app_context.select_bearer.bearer_data), &bearer_data, sizeof(srv_cnmgr_bearer_data_struct));

        /* Check bearer status */
        if (g_cnmgr_app_context.select_bearer.bearer_data.bearer_status == SRV_CNMGR_BEARER_STATUS_ACTIVE)
        {
            return MMI_TRUE;
        }
        else if (g_cnmgr_app_context.select_bearer.bearer_data.bearer_status == SRV_CNMGR_BEARER_STATUS_DEACTIVATING)
        {
            /* Bearer is in deactivating state. User can see bearer detail info only if bearer is activated. */
            mmi_popup_display_simple(
                (UI_string_type)GetString(STR_GLOBAL_DISCONNECTING), 
                MMI_EVENT_FAILURE,
                g_cnmgr_app_context.grp_id,
                NULL);
        }
        else if (g_cnmgr_app_context.select_bearer.bearer_data.bearer_status == SRV_CNMGR_BEARER_STATUS_DEACTIVE)
        {
            mmi_popup_display_simple(
                (UI_string_type)GetString(STR_ID_CNMGR_DETAIL_DISCONNECTED), 
                MMI_EVENT_FAILURE,
                g_cnmgr_app_context.grp_id,
                NULL);
        }
        else
        {
            mmi_popup_display_simple(
                (UI_string_type)GetString(STR_GLOBAL_UNFINISHED), 
                MMI_EVENT_FAILURE,
                g_cnmgr_app_context.grp_id,
                NULL);
        }
    }
    else
    {
        /* Bearer is not valid anymore */
        mmi_popup_display_simple(
            (UI_string_type)GetString(STR_ID_CNMGR_DETAIL_DISCONNECTED),
            MMI_EVENT_FAILURE,
            g_cnmgr_app_context.grp_id,
            NULL);

        memset(&(g_cnmgr_app_context.select_bearer), 0, sizeof(mmi_cnmgr_bearer_detail_info_struct));
        g_cnmgr_app_context.list_select_idx = 0;
        g_cnmgr_app_context.list_highlight_idx = 0;
    }

    if (mmi_frm_scrn_is_present(g_cnmgr_app_context.grp_id, SCR_ID_CNMGR_OPTION, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        mmi_frm_scrn_close(g_cnmgr_app_context.grp_id, SCR_ID_CNMGR_OPTION);
    }

    if (mmi_frm_scrn_is_present(g_cnmgr_app_context.grp_id, SCR_ID_CNMGR_BEARER_DETAIL, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        mmi_frm_scrn_close(g_cnmgr_app_context.grp_id, SCR_ID_CNMGR_BEARER_DETAIL);
    }

    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_cnmgr_get_select_bearer_data
* DESCRIPTION
*  Fill in selected bearer data
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_cnmgr_get_select_bearer_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cnmgr_bearer_id_struct bearer;
    srv_cnmgr_bearer_data_struct bearer_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cnmgr_app_context.select_bearer.account_id = g_cnmgr_app_bearer_list.bearer[g_cnmgr_app_context.list_select_idx].account_id;
    g_cnmgr_app_context.select_bearer.connect_type = g_cnmgr_app_bearer_list.bearer[g_cnmgr_app_context.list_select_idx].connect_type;
    g_cnmgr_app_context.select_bearer.dialup_type = g_cnmgr_app_bearer_list.bearer[g_cnmgr_app_context.list_select_idx].dialup_type;

    MMI_TRACE(
        MMI_CNMGR_TRC_GROUP,
        MMI_CNMGR_CHANGE_SELECT_BEARER,
        g_cnmgr_app_context.list_select_idx,
        g_cnmgr_app_context.list_highlight_idx,
        g_cnmgr_app_context.select_bearer.account_id,
        g_cnmgr_app_context.select_bearer.connect_type,
        g_cnmgr_app_context.select_bearer.dialup_type);

    bearer.account_id = g_cnmgr_app_context.select_bearer.account_id;
    bearer.connect_type = g_cnmgr_app_context.select_bearer.connect_type;
    if (srv_cnmgr_get_bearer_connection_data(&bearer, &bearer_data) == SRV_CNMGR_RESULT_SUCCESS)
    {
        memcpy(&(g_cnmgr_app_context.select_bearer.bearer_data), &bearer_data, sizeof(srv_cnmgr_bearer_data_struct));
    }
    else
    {
        g_cnmgr_app_context.select_bearer.bearer_data.bearer_status = SRV_CNMGR_BEARER_STATUS_DEACTIVE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cnmgr_get_bearer_detail_info
 * DESCRIPTION
 *  Compose the data shown in bearer detail info screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cnmgr_get_bearer_detail_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR temp_buf[MAX_SUBMENU_CHARACTERS];
    CHAR temp_buf_unicode[MAX_SUBMENU_CHARACTERS * ENCODING_LENGTH];
    S32 hour, min, sec, i;
    CHAR *info;
    float data_size;
    cbm_bearer_enum bearer_type;
    srv_cnmgr_bearer_id_struct bearer;
    srv_cnmgr_bearer_data_struct bearer_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    info = (CHAR*)subMenuData;

    bearer.account_id = g_cnmgr_app_context.select_bearer.account_id;
    bearer.connect_type = g_cnmgr_app_context.select_bearer.connect_type;
    if (srv_cnmgr_get_bearer_connection_data(&bearer, &bearer_data) == SRV_CNMGR_RESULT_SUCCESS)
    {
        memcpy(&(g_cnmgr_app_context.select_bearer.bearer_data), &bearer_data, sizeof(srv_cnmgr_bearer_data_struct));
    }
    else
    {
        g_cnmgr_app_context.select_bearer.bearer_data.bearer_status = SRV_CNMGR_BEARER_STATUS_DEACTIVE;
    }

    cbm_get_bearer_type(g_cnmgr_app_context.select_bearer.account_id, &bearer_type);

    mmi_ucs2cpy(info, GetString(STR_GLOBAL_DATA_ACCOUNT));
    mmi_ucs2cat(info, (const CHAR*)L":\n");
    for (i = 0; i < g_cnmgr_app_bearer_list.bearer_num; i++)
    {
        if (bearer.account_id == g_cnmgr_app_bearer_list.bearer[i].account_id)
        {
            mmi_ucs2cat(info, g_cnmgr_app_bearer_list.bearer[i].profile_name);
            break;
        }
    }
    mmi_ucs2cat(info, (const CHAR*)L"\n");

    if (g_cnmgr_app_context.select_bearer.connect_type == SRV_CNMGR_CONNECT_TYPE_LOCAL)
    {
        if (bearer_type & CBM_CSD)
        {
            srv_dtcnt_prof_str_info_qry_struct acct_data;
            CHAR dest[MAX_SUB_MENU_SIZE] = {0};

            acct_data.dest_len = MAX_SUB_MENU_SIZE;
            acct_data.dest = (S8*)dest;
            srv_dtcnt_get_csd_number(
                g_cnmgr_app_context.select_bearer.account_id,
                &acct_data,
                SRV_DTCNT_ACCOUNT_PRIMARY);

            mmi_ucs2cat(info, GetString(STR_ID_CNMGR_DETAIL_NUMBER));
            mmi_ucs2cat(info, (const CHAR*)L"\n");
            mmi_ucs2cat(info, dest);
            mmi_ucs2cat(info, (const CHAR*)L"\n");

            mmi_ucs2cat(info, GetString(STR_ID_CNMGR_DETAIL_TYPE));
            mmi_ucs2cat(info, (const CHAR*)L"\n");
            mmi_ucs2cat(info, GetString(STR_ID_CNMGR_DETAIL_TYPE_CSD));
            mmi_ucs2cat(info, (const CHAR*)L"\n");
        }
#ifdef __MMI_GPRS_FEATURES__
        else if (bearer_type & CBM_PS)
        {
            srv_dtcnt_prof_str_info_qry_struct acct_data;
            CHAR dest[MAX_SUB_MENU_SIZE] = {0};

            acct_data.dest_len = MAX_SUB_MENU_SIZE;
            acct_data.dest = (S8*)dest;
            srv_dtcnt_get_apn(
                g_cnmgr_app_context.select_bearer.account_id,
                &acct_data,
                SRV_DTCNT_ACCOUNT_PRIMARY);

            mmi_ucs2cat(info, GetString(STR_ID_CNMGR_DETAIL_APN));
            mmi_ucs2cat(info, (const CHAR*)L"\n");
            mmi_ucs2cat(info, dest);
            mmi_ucs2cat(info, (const CHAR*)L"\n");

            mmi_ucs2cat(info, GetString(STR_ID_CNMGR_DETAIL_TYPE));
            mmi_ucs2cat(info, (const CHAR*)L"\n");
            mmi_ucs2cat(info, GetString(STR_GLOBAL_GPRS));
            mmi_ucs2cat(info, (const CHAR*)L"\n");
        }
#endif /* __MMI_GPRS_FEATURES__ */
#ifdef __MMI_WLAN_FEATURES__
        else if (bearer_type & CBM_WIFI)
        {
            mmi_ucs2cat(info, GetString(STR_ID_CNMGR_DETAIL_TYPE));
            mmi_ucs2cat(info, (const CHAR*)L"\n");
            mmi_ucs2cat(info, GetString(STR_GLOBAL_WIFI));
            mmi_ucs2cat(info, (const CHAR*)L"\n");
        }
#endif /* __MMI_WLAN_FEATURES__ */
        else
        {
            mmi_ucs2cat(info, GetString(STR_ID_CNMGR_DETAIL_TYPE));
            mmi_ucs2cat(info, (const CHAR*)L"\n");
            mmi_ucs2cat(info, GetString(STR_GLOBAL_INVALID));
            mmi_ucs2cat(info, (const CHAR*)L"\n");
        }
    }
    else
    {
        mmi_ucs2cat(info, GetString(STR_ID_CNMGR_DETAIL_TYPE));
        mmi_ucs2cat(info, (const CHAR*)L"\n");
        mmi_ucs2cat(info, GetString(STR_ID_CNMGR_DETAIL_TYPE_DAILUP));
        mmi_ucs2cat(info, (const CHAR*)L"\n");
    }

    mmi_ucs2cat(info, GetString(STR_ID_CNMGR_DETAIL_STATUS));
    mmi_ucs2cat(info, (const CHAR*)L"\n");
    if (g_cnmgr_app_context.select_bearer.bearer_data.bearer_status == SRV_CNMGR_BEARER_STATUS_ACTIVE)
    {
        if ((g_cnmgr_app_context.select_bearer.bearer_data.upload_rate == 0) &&
            (g_cnmgr_app_context.select_bearer.bearer_data.download_rate == 0))
        {
            mmi_ucs2cat(info, GetString(STR_ID_CNMGR_DETAIL_NO_TRANSFER));
        }
        else
        {
            mmi_ucs2cat(info, GetString(STR_ID_CNMGR_DETAIL_TRANSFERING));
        }
    }
    else
    {
        mmi_ucs2cat(info, GetString(STR_ID_CNMGR_DETAIL_DISCONNECTED));
    }
    mmi_ucs2cat(info, (const CHAR*)L"\n");

    mmi_ucs2cat(info, GetString(STR_ID_CNMGR_DETAIL_CONN_TIME));
    mmi_ucs2cat(info, (const CHAR*)L"\n");
    hour = g_cnmgr_app_context.select_bearer.bearer_data.connect_time / MMI_CNMGR_HOUR_TO_SEC;
    min = (g_cnmgr_app_context.select_bearer.bearer_data.connect_time % MMI_CNMGR_HOUR_TO_SEC) / MMI_CNMGR_MIN_TO_SEC;
    sec = g_cnmgr_app_context.select_bearer.bearer_data.connect_time % MMI_CNMGR_MIN_TO_SEC;
    sprintf(temp_buf, "%02d:%02d:%02d", hour, min, sec);
    mmi_asc_to_ucs2(temp_buf_unicode, temp_buf);
    mmi_ucs2cat(info, temp_buf_unicode);
    mmi_ucs2cat(info, (const CHAR*)L"\n");

    if (g_cnmgr_app_context.select_bearer.connect_type != SRV_CNMGR_CONNECT_TYPE_DIALUP ||
        g_cnmgr_app_context.select_bearer.dialup_type != CSD_BEARER_DIALUP)
    {
        mmi_ucs2cat(info, GetString(STR_ID_CNMGR_DETAIL_ALL_DATA_SIZE));
        mmi_ucs2cat(info, (const CHAR*)L"\n");
        data_size = (float)g_cnmgr_app_context.select_bearer.bearer_data.all_data_size / MMI_CNMGR_DATA_UNIT_SIZE;
        sprintf(temp_buf, "%0.2fKB", data_size);
        mmi_asc_to_ucs2(temp_buf_unicode, temp_buf);
        mmi_ucs2cat(info, temp_buf_unicode);
        mmi_ucs2cat(info, (const CHAR*)L"\n");

        mmi_ucs2cat(info, GetString(STR_ID_CNMGR_DETAIL_RECEIVED_DATA_SIZE));
        mmi_ucs2cat(info, (const CHAR*)L"\n");
        data_size = (float)g_cnmgr_app_context.select_bearer.bearer_data.recv_data_size / MMI_CNMGR_DATA_UNIT_SIZE;
        sprintf(temp_buf, "%0.2fKB", data_size);
        mmi_asc_to_ucs2(temp_buf_unicode, temp_buf);
        mmi_ucs2cat(info, temp_buf_unicode);
        mmi_ucs2cat(info, (const CHAR*)L"\n");

        mmi_ucs2cat(info, GetString(STR_ID_CNMGR_DETAIL_SENT_DATA_SIZE));
        mmi_ucs2cat(info, (const CHAR*)L"\n");
        data_size = (float)g_cnmgr_app_context.select_bearer.bearer_data.sent_data_size / MMI_CNMGR_DATA_UNIT_SIZE;
        sprintf(temp_buf, "%0.2fKB", data_size);
        mmi_asc_to_ucs2(temp_buf_unicode, temp_buf);
        mmi_ucs2cat(info, temp_buf_unicode);
        mmi_ucs2cat(info, (const CHAR*)L"\n");

        mmi_ucs2cat(info, GetString(STR_ID_CNMGR_DETAIL_UPLOAD_RATE));
        mmi_ucs2cat(info, (const CHAR*)L"\n");
        data_size = (float)g_cnmgr_app_context.select_bearer.bearer_data.upload_rate / MMI_CNMGR_DATA_UNIT_SIZE;
        if (g_cnmgr_app_context.select_bearer.bearer_data.bearer_status == SRV_CNMGR_BEARER_STATUS_ACTIVE)
        {
            sprintf(temp_buf, "%0.2fKB/s", data_size);
        }
        else
        {
            sprintf(temp_buf, "0.00KB/s");
        }
        mmi_asc_to_ucs2(temp_buf_unicode, temp_buf);
        mmi_ucs2cat(info, temp_buf_unicode);
        mmi_ucs2cat(info, (const CHAR*)L"\n");

        mmi_ucs2cat(info, GetString(STR_ID_CNMGR_DETAIL_DOWNLOAD_RATE));
        mmi_ucs2cat(info, (const CHAR*)L"\n");
        data_size = (float)g_cnmgr_app_context.select_bearer.bearer_data.download_rate / MMI_CNMGR_DATA_UNIT_SIZE;
        if (g_cnmgr_app_context.select_bearer.bearer_data.bearer_status == SRV_CNMGR_BEARER_STATUS_ACTIVE)
        {
            sprintf(temp_buf, "%0.2fKB/s", data_size);
        }
        else
        {
            sprintf(temp_buf, "0.00KB/s");
        }
        mmi_asc_to_ucs2(temp_buf_unicode, temp_buf);
        mmi_ucs2cat(info, temp_buf_unicode);
        mmi_ucs2cat(info, (const CHAR*)L"\n");
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cnmgr_app_entry_bearer_detail_info
 * DESCRIPTION
 *  Enter a screen which displays bearer detail info
 * PARAMETERS
 *  entry_type :    [IN]    Entry type
 *  acct_id :       [IN]    Data account
 *  icon_id :       [IN]    Application icon
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cnmgr_app_entry_bearer_detail_info(mmi_cnmgr_entry_screen_type_enum entry_type,
                                                   U32 acct_id,
                                                   U16 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CNMGR_TRC_GROUP, MMI_CNMGR_APP_ENTRY_BEARER_DETAIL_INFO, entry_type, acct_id, icon_id);

    g_cnmgr_app_context.enter_from_wap = MMI_TRUE;
    g_cnmgr_app_context.wap_icon_id = icon_id;

    if (g_cnmgr_app_context.grp_id != GRP_ID_INVALID)
    {
        if (mmi_frm_scrn_is_present(g_cnmgr_app_context.grp_id, SCR_ID_CNMGR_BEARER_LIST, MMI_FRM_NODE_ALL_FLAG) ||
            mmi_frm_scrn_is_present(g_cnmgr_app_context.grp_id, SCR_ID_CNMGR_BEARER_DETAIL, MMI_FRM_NODE_ALL_FLAG))
        {
             mmi_popup_display_simple(
                (UI_string_type)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE),
                MMI_EVENT_FAILURE,
                GRP_ID_ROOT,
                NULL);
             return;
        }
    }

    if (entry_type == MMI_CNMGR_ENTRY_SCREEN_TYPE_BEARER_DETAIL)
    {
        if (g_cnmgr_app_context.grp_id == GRP_ID_INVALID)
        {
            g_cnmgr_app_context.grp_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_cnmgr_evt_proc, (void*)NULL);
            if (g_cnmgr_app_context.grp_id != GRP_ID_INVALID)
            {
                mmi_frm_group_enter(g_cnmgr_app_context.grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
            }
            else
            {
                mmi_popup_display_simple(
                    (UI_string_type)GetString(STR_GLOBAL_ERROR), 
                    MMI_EVENT_FAILURE,
                    GRP_ID_ROOT,
                    NULL);
                return;
            }
        }

        mmi_cnmgr_update_bearer_list();
        for (i = 0; i < SRV_CNMGR_MAX_BEARER_NUM; i++)
        {
            if (g_cnmgr_app_bearer_list.bearer[i].account_id == acct_id)
            {
                g_cnmgr_app_context.list_select_idx = i;
                mmi_cnmgr_get_select_bearer_data();
                mmi_cnmgr_entry_bearer_detail_info();
                return;
            }
        }

        mmi_popup_display_simple(
            (UI_string_type)GetString(STR_ID_CNMGR_NO_CONNECTION),
            MMI_EVENT_FAILURE,
            g_cnmgr_app_context.grp_id,
            NULL);
    }
    else if (entry_type == MMI_CNMGR_ENTRY_SCREEN_TYPE_LIST_SCREEN)
    {
        mmi_cnmgr_entry_bearer_list();
    }
    else
    {
        ASSERT(0);
    }
}


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
* FUNCTION
*  mmi_cnmgr_bearer_list_tap_callback
* DESCRIPTION
*  Execute correspoding function of selected shortcuts
* PARAMETERS
*  tap_type         [IN]    Tap type
*  index            [IN]    Tap index
* RETURNS
*  void
*****************************************************************************/
static void mmi_cnmgr_bearer_list_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM)
    {
        /* Only change highlight and do nothing in tap callback function */
        return;
    }

    if (!wgui_category_if_pop_option_menu())
    {
        mmi_cnmgr_pre_entry_bearer_detail_info();
    }	
}
#endif /* #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */


/************************************************************
 * Global Function
 ************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_cnmgr_app_init
 * DESCRIPTION
 *  This API is used to initialize connection management application.
 * PARAMETERS
 *  evt	:	        [IN]	Init event notification
 * RETURN VALUES
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_cnmgr_app_init(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_cnmgr_app_bearer_list, 0, sizeof(mmi_cnmgr_bearer_list_struct));
    memset(&g_cnmgr_app_bearer_name, 0, sizeof(U8*) * SRV_CNMGR_MAX_BEARER_NUM);
    memset(&g_cnmgr_app_bearer_data_size, 0, sizeof(U8*) * SRV_CNMGR_MAX_BEARER_NUM);
    memset(&g_cnmgr_app_context, 0, sizeof(mmi_cnmgr_context_struct));
    g_cnmgr_app_context.grp_id = GRP_ID_INVALID;

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cnmgr_entry_bearer_list_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Conn. management menu item in Connectivity screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cnmgr_entry_bearer_list_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
      
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cnmgr_app_context.enter_from_wap = MMI_FALSE;

    SetLeftSoftkeyFunction(mmi_cnmgr_entry_bearer_list, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_cnmgr_entry_bearer_list, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cnmgr_app_show_bearer_detail_info
 * DESCRIPTION
 *  This API is used to enter bearer detail info screen.
 * PARAMETERS
 *  entry_type :    [IN]    Entry type
 *  acct_id :       [IN]    Data account
 *  icon_id :       [IN]    Application icon
 * RETURN VALUES
 *  mmi_ret
 *****************************************************************************/
void mmi_cnmgr_app_show_bearer_detail_info(mmi_cnmgr_entry_screen_type_enum entry_type, U32 acct_id, U16 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    U32 ori_acct_id, real_acct_id = 0;
    cbm_account_info_struct acct_info;
    U8 bearer_status;
		
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    if (cbm_get_real_account(acct_id, &real_acct_id) == CBM_OK)
    {
        MMI_TRACE(MMI_CNMGR_TRC_GROUP, MMI_CNMGR_APP_SHOW_BEARER_DETAIL_INFO, acct_id, real_acct_id);
        acct_id = real_acct_id;
    }

    MMI_TRACE(MMI_CNMGR_TRC_GROUP, MMI_CNMGR_APP_SHOW_BEARER_DETAIL_INFO, acct_id, real_acct_id);

    /* Get the 1st original data account id */
    if (cbm_decode_data_account_id_ext(acct_id, &acct_info) == CBM_ERROR)
    {
        return;
    }

    ori_acct_id = cbm_encode_data_account_id(acct_info.account[0].account_id, acct_info.account[0].sim_id, 0, KAL_FALSE);
    if (srv_cnmgr_get_bearer_status(ori_acct_id, &bearer_status) == SRV_CNMGR_RESULT_SUCCESS)
    {
        mmi_cnmgr_app_entry_bearer_detail_info(entry_type, ori_acct_id, icon_id);
        return;
    }

    ori_acct_id = cbm_encode_data_account_id(acct_info.account[1].account_id, acct_info.account[1].sim_id, 0, KAL_FALSE);
    if (srv_cnmgr_get_bearer_status(ori_acct_id, &bearer_status) == SRV_CNMGR_RESULT_SUCCESS)
    {
        mmi_cnmgr_app_entry_bearer_detail_info(entry_type, ori_acct_id, icon_id);
        return;
    }

    ori_acct_id = cbm_encode_data_account_id(acct_info.account[0].account_id, acct_info.account[0].sim_id, 0, KAL_FALSE);
    mmi_cnmgr_app_entry_bearer_detail_info(entry_type, ori_acct_id, icon_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cnmgr_delete_bearer_detail_screen
 * DESCRIPTION
 *  Let application delete bearer detail info screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cnmgr_delete_bearer_detail_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_is_present(g_cnmgr_app_context.grp_id, SCR_ID_CNMGR_BEARER_DETAIL, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        mmi_frm_scrn_close(g_cnmgr_app_context.grp_id, SCR_ID_CNMGR_BEARER_DETAIL);
    }
}


#endif /* defined(__TCPIP__) && defined(__MMI_CBM_CONNECTION_MANAGER__) && defined(__PLUTO_MMI_PACKAGE__) */
