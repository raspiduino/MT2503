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
 *  PhoneBookpbapc.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  PBAPC
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "MMI_features.h"

#if defined(__MMI_BT_PBAP_CLIENT__)
#include "PhbpbapSrvGprot.h"

#if !defined(__MMI_PHB_PBAPC_SYNC_CONTACT__)

#include "PhoneBookpbapc.h"
#include "mmi_rp_app_bluetooth_def.h"
#include "wgui_fixed_menus.h"
#include "wgui_categories_util.h"
#include "BTMMIScrGprots.h"
//#include ".\..\..\plutommi\Framework\Scenario\mmi_frm_scenario_prot.h"
#include "CommonScreensResDef.h"
#include "wgui_include.h"
#include "BtcmSrvGprot.h"

//#define PBAPC_UNIT_TEST
//#define __MMI_TELEPHONY_SUPPORT__

U8 g_test_flag = 0;

/* user data info */
/*******************************
0xbabe0001 read pse contact from pse list call

0xbabe0002   list call select number

0xbabe0003   cui list pre select contact

0xbabe0004  pre select contact select number

0xbabe0005  notify evt

********************************/


/* global */
extern S32 g_phb_pbapc_show_symbol;
mmi_phb_pbapc_cntx_struct g_mmi_phb_pbapc_cntx;

#if defined(__MMI_PHB_QUICK_SEARCH__)
extern S32(*g_phb_pbapc_search_function) (U8 *);
#endif

MMI_ID g_grp_id;

static void mmi_phb_pbapc_con_profile_cb(srv_bt_cm_connection_type conn_type,MMI_BOOL result,MMI_BOOL is_connect);

extern void mmi_phb_launch_entry(void);

extern void mmi_phb_launch_exit(void);

#if defined(__MMI_BT_PBAP_CLIENT__)
extern MMI_BOOL g_wgui_cat199_has_default_hilight_item;
extern MMI_BOOL g_wgui_cat199_refresh_when_input_complete;
#endif

/* func */
mmi_phb_pbapc_cntx_struct *mmi_phb_pbapc_get_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_mmi_phb_pbapc_cntx;
}


void mmi_phb_pbapc_entry_list_tab(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    mmi_ret ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    if (phb_pbapc_cntx_p->list_type == 0)
    {
        phb_pbapc_cntx_p->parent_id = GRP_ID_PHB_MAIN;
    #ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
        if (!cui_tab_enter(
                GRP_ID_PHB_MAIN,
                SCR_ID_PHB_PBAP_LIST,
                mmi_phb_pbapc_exit_list_tab,
                mmi_phb_pbapc_entry_list_tab,
                MMI_FRM_FULL_SCRN
                ))
    #else
        if (!mmi_frm_scrn_tab_page_enter(
                GRP_ID_PHB_MAIN,
                SCR_PBOOK_MAIN_MENU,
                SCR_ID_PHB_PBAP_LIST,
                mmi_phb_pbapc_exit_list_tab,
                mmi_phb_pbapc_entry_list_tab,
                MMI_FRM_TAB_PAGE
                ))
    #endif
        {
            return;
        }

        phb_pbapc_cntx_p->phb_list = 2;
        g_wgui_cat199_has_default_hilight_item = MMI_FALSE;

        ret = mmi_frm_cb_reg_event(EVT_ID_PHB_PBAPC_NOTIFY, mmi_phb_pbapc_notify_evt_hdlr, (void *)0xbabe0005);

        kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_entry_list_tab(req evt)--ret: %d\n", ret);
    }
    else if (phb_pbapc_cntx_p->list_type == 1)
    {
        phb_pbapc_cntx_p->parent_id = GRP_ID_PHB_PBAPC_SELECT_CONTACT;
    #ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
        if (!cui_tab_enter(
                GRP_ID_PHB_PBAPC_SELECT_CONTACT,
                SCR_ID_PHB_PBAPC_BT,
                mmi_phb_pbapc_exit_list_tab,
                mmi_phb_pbapc_entry_list_tab,
                MMI_FRM_FULL_SCRN
                ))
    #else
        if (!mmi_frm_scrn_tab_page_enter(
                GRP_ID_PHB_PBAPC_SELECT_CONTACT,
                SCR_ID_PHB_PBAPC_TAB,
                SCR_ID_PHB_PBAPC_BT,
                mmi_phb_pbapc_exit_list_tab,
                mmi_phb_pbapc_entry_list_tab,
                MMI_FRM_TAB_PAGE
                ))
     #endif
        {
            return;
        }

        phb_pbapc_cntx_p->cui_list = 2;
    }
    else
    {
        ;
    }

    //kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_entry_list_tab--pbapc_handle: 0x%x, total_pse_contact: %d\n",
    //                                                                phb_pbapc_cntx_p->pbapc_handle, phb_pbapc_cntx_p->total_pse_contact);

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_PBAPC_ENTRY_LIST_TAB1, phb_pbapc_cntx_p->pbapc_handle, phb_pbapc_cntx_p->total_pse_contact);

    //kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_entry_list_tab--is_in_backward: %d, pbapc_connect: %d\n",
    //                                                                mmi_frm_is_in_backward_scenario(), srv_bt_cm_is_profile_connected(SRV_BT_CM_PBAPC_CONNECTION));

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_PBAPC_ENTRY_LIST_TAB2,
            mmi_frm_is_in_backward_scenario(), srv_bt_cm_is_profile_connected(SRV_BT_CM_PBAPC_CONNECTION));

    phb_pbapc_cntx_p->list_state = 1; // active

    kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_entry_list_tab(search status)--search_done: %d, show_dummy: %d, is_full: %d, symbol_show: %d\n",
                phb_pbapc_cntx_p->search_done, phb_pbapc_cntx_p->show_dummy, phb_pbapc_cntx_p->is_full, g_phb_pbapc_show_symbol);

    //if (!mmi_frm_is_in_backward_scenario())
#ifndef PBAPC_UNIT_TEST
    if(srv_bt_cm_is_profile_connected(SRV_BT_CM_PBAPC_CONNECTION))
    {
        if (phb_pbapc_cntx_p->search_done == MMI_TRUE || g_phb_pbapc_show_symbol == 1)
        {
            mmi_phb_pbapc_show_pse_list();
        }
        else if (phb_pbapc_cntx_p->pbapc_handle == NULL)
        {
            U8 *gui_buffer = NULL;

            gui_buffer = mmi_frm_scrn_get_active_gui_buf();

            if(NULL == gui_buffer)
            {
                phb_pbapc_cntx_p->pse_list_index = 0;
                phb_pbapc_cntx_p->qsearch_input_buffer[0] = 0;
            }
            //g_mmi_phb_pbapc_cntx.pbapc_handle = NULL;
            phb_pbapc_cntx_p->total_pse_contact = 0;
            phb_pbapc_cntx_p->pse_phone_num = 0;
            phb_pbapc_cntx_p->pse_sim_num = 0;
            phb_pbapc_cntx_p->data_ready = MMI_FALSE;
            mmi_phb_pbapc_show_loading(phb_pbapc_cntx_p->parent_id, SCR_ID_PHB_PROCESSING);
            //mmi_phb_pbapc_show_searching();

            /* read phone contact */
            phb_pbapc_cntx_p->read_storage = SRV_PHB_PBAP_STORAGE_PHONE_PB;

            mmi_phb_pbapc_read_pse_list();
        }
        else
        {
            // just wait rsp coming
            mmi_phb_pbapc_show_loading(phb_pbapc_cntx_p->parent_id, SCR_ID_PHB_PROCESSING);
        }
    }
    else
    {
        phb_pbapc_cntx_p->total_pse_contact = 0;

        mmi_phb_pbapc_show_pse_list();
    }
#else
    // test
    strcpy(g_mmi_phb_pbapc_cntx.pse_contact[0].entry_name, "Test1");
    strcpy(g_mmi_phb_pbapc_cntx.pse_contact[1].entry_name, "Test2");
    g_mmi_phb_pbapc_cntx.total_pse_contact = 2;
    g_mmi_phb_pbapc_cntx.pse_phone_num = 1;
    g_mmi_phb_pbapc_cntx.pse_sim_num = 1;
    mmi_phb_pbapc_show_pse_list();
#endif

#if defined(__MMI_PHB_QUICK_SEARCH__)
    g_phb_pbapc_search_function = mmi_phb_pbapc_search_function;
#endif
}


void mmi_phb_pbapc_entry_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    mmi_ret ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    if (phb_pbapc_cntx_p->list_type == 0)
    {
        phb_pbapc_cntx_p->parent_id = GRP_ID_PHB_MAIN;

        phb_pbapc_cntx_p->phb_list = 2;

        ret = mmi_frm_cb_reg_event(EVT_ID_PHB_PBAPC_NOTIFY, mmi_phb_pbapc_notify_evt_hdlr, (void *)0xbabe0005);

        kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_entry_list(req evt)--ret: %d\n", ret);
    }
    else if (phb_pbapc_cntx_p->list_type == 1)
    {
        phb_pbapc_cntx_p->parent_id = GRP_ID_PHB_PBAPC_SELECT_CONTACT;

        phb_pbapc_cntx_p->cui_list = 2;
    }
    else
    {
        ;
    }

    if (phb_pbapc_cntx_p->list_type == 0)
    {
        if (!mmi_frm_scrn_enter(
                GRP_ID_PHB_MAIN,
                SCR_ID_PHB_PBAPC_BT,
                mmi_phb_launch_exit,
                mmi_phb_launch_entry,
                MMI_FRM_FULL_SCRN
                ))
        {
            kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_entry_list(scr entry fail), list_type: %d\n",
                            phb_pbapc_cntx_p->list_type);

            return;
        }
    }
    else if (phb_pbapc_cntx_p->list_type == 1)
    {
        if (!mmi_frm_scrn_enter(
                GRP_ID_PHB_PBAPC_SELECT_CONTACT,
                SCR_ID_PHB_PBAPC_BT,
                mmi_phb_pbapc_exit_list,
                cui_phb_pbapc_select_contact_entry,
                MMI_FRM_FULL_SCRN
                ))
        {
            kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_entry_list(scr entry fail), list_type: %d\n",
                            phb_pbapc_cntx_p->list_type);

            return;
        } 
    }

    kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_entry_list(), list_type: %d\n",
                    phb_pbapc_cntx_p->list_type);

    kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_entry_list--pbapc_handle: 0x%x, total_pse_contact: %d\n",
                                                                    phb_pbapc_cntx_p->pbapc_handle, phb_pbapc_cntx_p->total_pse_contact);

    kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_entry_list--is_in_backward: %d, pbapc_connect: %d\n",
                                                                    mmi_frm_is_in_backward_scenario(), srv_bt_cm_is_profile_connected(SRV_BT_CM_PBAPC_CONNECTION));

    kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_entry_list(search status)--search_done: %d, show_dummy: %d, is_full: %d, symbol_show: %d\n",
                phb_pbapc_cntx_p->search_done, phb_pbapc_cntx_p->show_dummy, phb_pbapc_cntx_p->is_full, g_phb_pbapc_show_symbol);

    phb_pbapc_cntx_p->list_state = 1; // active
    g_wgui_cat199_has_default_hilight_item = MMI_FALSE;

#ifndef PBAPC_UNIT_TEST
    if(srv_bt_cm_is_profile_connected(SRV_BT_CM_PBAPC_CONNECTION))
    {
        if (phb_pbapc_cntx_p->search_done == MMI_TRUE || g_phb_pbapc_show_symbol == 1)
        {
            mmi_phb_pbapc_show_pse_list();
        }
        else if (phb_pbapc_cntx_p->pbapc_handle == NULL)
        {
            U8 *gui_buffer = NULL;

            gui_buffer = mmi_frm_scrn_get_active_gui_buf();

            if(NULL == gui_buffer)
            {
                phb_pbapc_cntx_p->pse_list_index = 0;
                phb_pbapc_cntx_p->qsearch_input_buffer[0] = 0;
            }
            //g_mmi_phb_pbapc_cntx.pbapc_handle = NULL;
            phb_pbapc_cntx_p->total_pse_contact = 0;
            phb_pbapc_cntx_p->pse_phone_num = 0;
            phb_pbapc_cntx_p->pse_sim_num = 0;
            phb_pbapc_cntx_p->data_ready = MMI_FALSE;
            mmi_phb_pbapc_show_loading(phb_pbapc_cntx_p->parent_id, SCR_ID_PHB_PROCESSING);
            //mmi_phb_pbapc_show_searching();

            /* read phone contact */
            phb_pbapc_cntx_p->read_storage = SRV_PHB_PBAP_STORAGE_PHONE_PB;

            mmi_phb_pbapc_read_pse_list();
        }
        else
        {
            // just wait rsp coming
            mmi_phb_pbapc_show_loading(phb_pbapc_cntx_p->parent_id, SCR_ID_PHB_PROCESSING);
        }
    }
    else
    {
        phb_pbapc_cntx_p->total_pse_contact = 0;

        mmi_phb_pbapc_show_pse_list();
    }
#else
    // test
    strcpy(g_mmi_phb_pbapc_cntx.pse_contact[0].entry_name, "Test1");
    strcpy(g_mmi_phb_pbapc_cntx.pse_contact[1].entry_name, "Test2");
    strcpy(g_mmi_phb_pbapc_cntx.pse_contact[2].entry_name, "=E6=B2=A1=E6=9C=89");
    g_mmi_phb_pbapc_cntx.total_pse_contact = 3;
    g_mmi_phb_pbapc_cntx.pse_phone_num = 2;
    g_mmi_phb_pbapc_cntx.pse_sim_num = 1;
    mmi_phb_pbapc_show_pse_list();
#endif

#if defined(__MMI_PHB_QUICK_SEARCH__)
    g_phb_pbapc_search_function = mmi_phb_pbapc_search_function;
#endif
}

mmi_imc_history_p history_data;

void mmi_phb_pbapc_exit_list_tab(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    MMI_ID group_id = 0;
    MMI_ID scrn_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    //kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_exit_list_tab--pbapc_handle: 0x%x, total_pse_contact: %d\n",
    //                                                                phb_pbapc_cntx_p->pbapc_handle, phb_pbapc_cntx_p->total_pse_contact);

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_PBAPC_EXIT_LIST_TAB, phb_pbapc_cntx_p->pbapc_handle, phb_pbapc_cntx_p->total_pse_contact);

    phb_pbapc_cntx_p->list_state = 2;

    /*
    if (phb_pbapc_cntx_p->pbapc_handle != NULL)
    {
        srv_phb_pbapc_destory_handle(phb_pbapc_cntx_p->pbapc_handle);
        phb_pbapc_cntx_p->pbapc_handle = NULL;
    }
    */

    wgui_set_menu_empty_string_by_id(STR_GLOBAL_EMPTY);

    mmi_frm_get_active_scrn_id(&group_id, &scrn_id);

    kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_exit_list_tab--gid: %d, sid: %d, picker: %d, symbol: %d\n",
                                                                    group_id, scrn_id, SCR_SYMBOL_PICKER_SCREEN, g_phb_pbapc_show_symbol);

    if(scrn_id == SCR_SYMBOL_PICKER_SCREEN)
    {
        g_phb_pbapc_show_symbol = 1;
    }
    else
    {
        g_phb_pbapc_show_symbol = 0;
    }

#if defined(__MMI_PHB_QUICK_SEARCH__)
    g_phb_pbapc_search_function = NULL;
#endif

    history_data = (mmi_imc_history_p) mmi_imc_get_editor_history_data();
}


void mmi_phb_pbapc_exit_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    MMI_ID group_id = 0;
    MMI_ID scrn_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_exit_list--pbapc_handle: 0x%x, total_pse_contact: %d\n",
                                                                    phb_pbapc_cntx_p->pbapc_handle, phb_pbapc_cntx_p->total_pse_contact);

    phb_pbapc_cntx_p->list_state = 2;

    wgui_set_menu_empty_string_by_id(STR_GLOBAL_EMPTY);

    mmi_frm_get_active_scrn_id(&group_id, &scrn_id);

    kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_exit_list--gid: %d, sid: %d, picker: %d, symbol: %d\n",
                                                                    group_id, scrn_id, SCR_SYMBOL_PICKER_SCREEN, g_phb_pbapc_show_symbol);

    if(scrn_id == SCR_SYMBOL_PICKER_SCREEN)
    {
        g_phb_pbapc_show_symbol = 1;
    }
    else
    {
        g_phb_pbapc_show_symbol = 0;
    }

#if defined(__MMI_PHB_QUICK_SEARCH__)
    g_phb_pbapc_search_function = NULL;
#endif

    history_data = (mmi_imc_history_p) mmi_imc_get_editor_history_data();
}


static void mmi_phb_pbapc_show_loading(MMI_ID parent_id, MMI_ID scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_frm_scrn_create(parent_id, scrn_id, mmi_phb_pbapc_loading_scrn_proc, NULL);
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    phb_pbapc_cntx_p->load_gid = parent_id;
    phb_pbapc_cntx_p->load_sid = scrn_id;
    kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_show_loading\n");

    mmi_phb_pbapc_entry_show_loading();
    //mmi_phb_pbapc_show_searching();
}


static MMI_RET mmi_phb_pbapc_loading_scrn_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_INACTIVE:
        {
            break;
        }

        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_phb_pbapc_entry_show_loading();
            break;
        }

        case EVT_ID_SCRN_DEINIT:
            //StopTimer(PHB_PBAPC_NOTIFYDURATION_TIMER);
            
            break;
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
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
            #endif
            break;
        }
        default:
            break;
    }

    return MMI_RET_OK;
}


static void mmi_phb_pbapc_loading_option_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    //ExitCategoryPopupScreen();
    //mmi_phb_pbapc_show_pse_list();
    kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_loading_option_back\n");

    mmi_phb_pbapc_show_loading_abort(GRP_ID_PHB_MAIN, SCR_ID_PHB_PROCESSING);
    //g_mmi_phb_pbapc_cntx.total_pse_contact = 0;
    //mmi_phb_pbapc_show_pse_list();
    //mmi_frm_scrn_close(GRP_ID_PHB_MAIN, SCR_ID_PHB_PROCESSING);
    if (phb_pbapc_cntx_p->job_type == 0)
    {
        phb_pbapc_cntx_p->total_pse_contact = 0;
        mmi_phb_pbapc_show_pse_list();
    }
    else if (phb_pbapc_cntx_p->job_type == 1)
    {
        mmi_frm_group_close(GRP_ID_PHB_PBAPC_VIEW_CONTACT);
    }
    else
    {
        ;
    }

    // cancel release handle flag
    phb_pbapc_cntx_p->flag = 0;
}

static void mmi_phb_pbapc_entry_show_loading(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = -1;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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
    #endif
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    ret = mmi_frm_scrn_enter(phb_pbapc_cntx_p->load_gid, phb_pbapc_cntx_p->load_sid, NULL, mmi_phb_pbapc_entry_show_loading, MMI_FRM_FULL_SCRN);

    if (MMI_TRUE != ret)
    {
        return;
    }

    ShowCategory62Screen(STR_GLOBAL_LOADING, IMG_SCR_PBOOK_CAPTION, NULL);
    //SetRightSoftkeyFunction(mmi_phb_pbapc_loading_option_back, KEY_EVENT_UP);

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) <= 0)
    {
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
    }

    //SetRightSoftkeyFunction(mmi_phb_pbapc_loading_option_back, KEY_EVENT_UP);

    // SetRightSoftkeyFunction(mmi_phb_pbapc_loading_abort, KEY_EVENT_UP);
}


static void mmi_phb_pbapc_pse_list_loading_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    mmi_phb_pbapc_show_loading_abort(GRP_ID_PHB_MAIN, SCR_ID_PHB_PROCESSING);

    //kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_pse_list_loading_abort--pbapc_handle: 0x%x, total_pse_contact: %d\n",
    //                                                                g_mmi_phb_pbapc_cntx.pbapc_handle, g_mmi_phb_pbapc_cntx.total_pse_contact);

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_PBAPC_LIST_LOADING_ABORT, g_mmi_phb_pbapc_cntx.pbapc_handle, g_mmi_phb_pbapc_cntx.total_pse_contact);

    //mmi_popup_display_simple_ext(STR_GLOBAL_FAILED, MMI_EVENT_FAILURE, phb_pbapc_cntx_p->parent_id, NULL);

    //phb_pbapc_cntx_p->total_pse_contact = 0;

    //mmi_phb_pbapc_show_pse_list();
}


static void mmi_phb_pbapc_show_loading_abort(MMI_ID parent_id, MMI_ID scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    if (phb_pbapc_cntx_p->job_type == 0)
    {
        phb_pbapc_cntx_p->search_done = MMI_TRUE;
    }
    //mmi_frm_scrn_close(parent_id, scrn_id);
    mmi_frm_scrn_close(phb_pbapc_cntx_p->load_gid, phb_pbapc_cntx_p->load_sid);

    phb_pbapc_cntx_p->load_gid = 0;
    phb_pbapc_cntx_p->load_sid = 0;
    //ExitCategoryPopupScreen();
    //mmi_phb_pbapc_searching_abort();
}


static S32 mmi_phb_pbapc_read_pse_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = -1;
    srv_phb_pbapc_read_list_req_struct list_req;
    srv_phb_pbapc_read_list_req_ex_struct ex_req;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    U16 search_utf8[MMI_PHB_NAME_LENGTH + 1];
    U8 search_asi[MMI_PHB_NAME_LENGTH + 1];
    S32 key_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    phb_pbapc_cntx_p->job_type = 0;

    mmi_chset_ucs2_to_utf8_string((U8 *)search_utf8, MMI_PHB_NAME_LENGTH, (U8 *)(phb_pbapc_cntx_p->qsearch_input_buffer));
    search_utf8[MMI_PHB_NAME_LENGTH] = L'\0';

    mmi_ucs2_n_to_asc(search_asi, (CHAR *)phb_pbapc_cntx_p->qsearch_input_buffer, MMI_PHB_NAME_LENGTH);
    search_asi[MMI_PHB_NAME_LENGTH] = '\0';

    key_len = mmi_ucs2strlen((S8*)phb_pbapc_cntx_p->qsearch_input_buffer);

    kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_read_pse_list--search_asi: %s, key_len: %d\n",
                    search_asi, key_len);

    if (phb_pbapc_cntx_p->pbapc_handle)
    {
        ret = SRV_PHB_PBAPC_RET_OK;
    }
    else
    {
        phb_pbapc_cntx_p->pbapc_handle = srv_phb_pbapc_create_handle(&ret);
    }

    if (ret == SRV_PHB_PBAPC_RET_OK)
    {
        ex_req.entry_count = SRV_PHB_PBAPC_MAX_READ_LIST_NUM;
        ex_req.list_entry = g_mmi_phb_pbapc_cntx.read_entry;
        /* Req head */
        list_req.handle = g_mmi_phb_pbapc_cntx.pbapc_handle;
        list_req.storage = g_mmi_phb_pbapc_cntx.read_storage;
        list_req.user_data = (void *)0xbabebabe;

        list_req.folder_name = NULL;
        list_req.query_attr = SRV_PHB_PBAP_ATTR_NAME;
        list_req.order = SRV_PHB_PBAP_SORT_ORDER_ALPHA;
        //list_req.query_pattern = (U8*)phb_pbapc_cntx_p->qsearch_input_buffer;
        list_req.query_pattern = (U8 *)search_utf8;
        list_req.query_length = mmi_ucs2strlen((S8*)phb_pbapc_cntx_p->qsearch_input_buffer);
        //list_req.query_count = MMI_PHB_PBAPC_MAX_PSE_CONTACT;
        list_req.query_count = MMI_PHB_PBAPC_MAX_PSE_CONTACT - phb_pbapc_cntx_p->pse_phone_num;
        list_req.query_offset = 0;
        list_req.query_offset = 0;
        list_req.list_req_ex = &ex_req;

        ret = srv_phb_pbapc_read_pse_list(&list_req, mmi_phb_pbapc_read_pse_list_hdlr);
    }

    if (ret != SRV_PHB_PBAPC_RET_OK)
    {
        if (ret == SRV_PHB_PBAPC_RET_HD_FULL) // wait release handle evt
        {
            phb_pbapc_cntx_p->flag = 1;

            kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_read_pse_list(wait handle release)\n");
        }
        else
        {
            //mmi_phb_pbapc_show_loading_abort(GRP_ID_PHB_PBAPC_VIEW_CONTACT, SCR_ID_PHB_PROCESSING);
            //mmi_phb_pbapc_loading_option_back();
            mmi_phb_pbapc_pse_list_loading_abort();
            //mmi_phb_pbapc_searching_abort();
            //mmi_popup_display_simple_ext(STR_GLOBAL_FAILED, MMI_EVENT_FAILURE, GRP_ID_PHB_PBAPC_VIEW_CONTACT, NULL);
        }
    }

    //kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_read_pse_list--ret: %d, read_storage: %d\n",
    //                                                                ret, g_mmi_phb_pbapc_cntx.read_storage);

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_PBAPC_READ_PSE_LIST, ret, g_mmi_phb_pbapc_cntx.read_storage);

    return ret;
}


static S32 mmi_phb_pbapc_read_pse_list_hdlr(srv_phb_pbapc_read_list_rsp_struct *list_rsp, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    srv_phb_pbapc_list_entry_struct *list_entry = NULL;
    srv_phb_pbapc_list_entry_struct *pse_contact = NULL;
    U16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    pse_contact = phb_pbapc_cntx_p->pse_contact;

    if(phb_pbapc_cntx_p->pbapc_handle != NULL && phb_pbapc_cntx_p->job_type == 0 && phb_pbapc_cntx_p->free_handle == 1)
    {
        kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_read_pse_list_hdlr, list_state: %d\n",
                        phb_pbapc_cntx_p->list_state);

        if (list_rsp->ret == 0)
        {
            if (list_rsp->is_list_valid)
            {
                if (list_rsp->more_data == 1)
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }

        if (phb_pbapc_cntx_p->list_state == 2)
        {
            srv_phb_pbapc_destory_handle(phb_pbapc_cntx_p->pbapc_handle);
            phb_pbapc_cntx_p->pbapc_handle = NULL;

            /* show loading but free_handle = 1 */
            {
                MMI_ID group_id = 0;
                MMI_ID scrn_id = 0;

                mmi_frm_get_active_scrn_id(&group_id, &scrn_id);

                if (phb_pbapc_cntx_p->load_gid == group_id &&
                    phb_pbapc_cntx_p->load_sid == scrn_id)
                {
                    phb_pbapc_cntx_p->total_pse_contact = 0;
                    phb_pbapc_cntx_p->pse_phone_num = 0;
                    phb_pbapc_cntx_p->pse_sim_num = 0;
                    phb_pbapc_cntx_p->data_ready = MMI_FALSE;
                    phb_pbapc_cntx_p->read_storage = SRV_PHB_PBAP_STORAGE_PHONE_PB;

                    mmi_phb_pbapc_read_pse_list();
                }
            }
        }
        else if (phb_pbapc_cntx_p->list_state == 1)
        {
            phb_pbapc_cntx_p->total_pse_contact = 0;
            phb_pbapc_cntx_p->pse_phone_num = 0;
            phb_pbapc_cntx_p->pse_sim_num = 0;
            phb_pbapc_cntx_p->data_ready = MMI_FALSE;
            phb_pbapc_cntx_p->read_storage = SRV_PHB_PBAP_STORAGE_PHONE_PB;

            mmi_phb_pbapc_read_pse_list();
        }

        phb_pbapc_cntx_p->free_handle = 0;

        return 0;
    }


    if (list_rsp->ret == 0)
    {
        if (list_rsp->is_list_valid)
        {
            list_entry = list_rsp->list->list_entry;

            if(phb_pbapc_cntx_p->total_pse_contact < MMI_PHB_PBAPC_MAX_PSE_CONTACT)
            {
                for (i = 0; i < list_rsp->entry_count; ++i)
                {
                    index = phb_pbapc_cntx_p->total_pse_contact;
                    pse_contact[index].entry_index = list_entry[i].entry_index;
                    memcpy(pse_contact[index].entry_name, list_entry[i].entry_name, SRV_PHB_PBAPC_MAX_ENTRY_NAME_LEN + 1);

                    mmi_phb_pbapc_revise_string(pse_contact[index].entry_name, SRV_PHB_PBAPC_MAX_ENTRY_NAME_LEN + 1);

                    if (pse_contact[index].entry_name[0] == '\0')
                    {
                        continue;
                    }

                    if (list_entry[i].entry_index == 0)
                    {
                        /* filter sim1 owner number */
                        if (SRV_PHB_PBAP_STORAGE_SIM1_PB == phb_pbapc_cntx_p->read_storage)
                        {
                            //continue;
                        }
                        /* filter null phone owner number */
                        if (list_entry[i].entry_name[0] == '\0')
                        {
                            continue;
                        }
                    }

                    phb_pbapc_cntx_p->total_pse_contact += 1;

                    if(SRV_PHB_PBAP_STORAGE_PHONE_PB == phb_pbapc_cntx_p->read_storage)
                    {
                        phb_pbapc_cntx_p->pse_phone_num += 1;
                    }
                    else
                    {
                        phb_pbapc_cntx_p->pse_sim_num += 1;
                    }

                    if(phb_pbapc_cntx_p->total_pse_contact == MMI_PHB_PBAPC_MAX_PSE_CONTACT)
                    {
                        phb_pbapc_cntx_p->data_ready = MMI_TRUE;

                        mmi_phb_pbapc_show_loading_abort(GRP_ID_PHB_MAIN, SCR_ID_PHB_PROCESSING);

                        //mmi_phb_pbapc_show_pse_list();
                        
                        //mmi_phb_pbapc_searching_abort();

                        return 1;
                    }
                }
            }

            if (list_rsp->more_data == 0)
            {
                if(SRV_PHB_PBAP_STORAGE_PHONE_PB == phb_pbapc_cntx_p->read_storage &&
                    MMI_FALSE == phb_pbapc_cntx_p->data_ready)
                {
                #ifdef MMI_PHB_PBAPC_READ_PHONE_ONLY
                    phb_pbapc_cntx_p->data_ready = MMI_TRUE;
                    mmi_phb_pbapc_show_loading_abort(GRP_ID_PHB_MAIN, SCR_ID_PHB_PROCESSING);
                    //mmi_phb_pbapc_show_pse_list();
                    //mmi_phb_pbapc_searching_abort();
                #else
                    phb_pbapc_cntx_p->read_storage = SRV_PHB_PBAP_STORAGE_SIM1_PB; // read sim contact
                    mmi_phb_pbapc_read_pse_list();
                #endif /* MMI_PHB_PBAPC_READ_PHONE_ONLY */
                }
                else if (SRV_PHB_PBAP_STORAGE_SIM1_PB == phb_pbapc_cntx_p->read_storage)
                {
                    phb_pbapc_cntx_p->data_ready = MMI_TRUE;

                    mmi_phb_pbapc_show_loading_abort(GRP_ID_PHB_MAIN, SCR_ID_PHB_PROCESSING);

                    //mmi_phb_pbapc_show_pse_list();

                    //mmi_phb_pbapc_searching_abort();
                }
                else
                {
                    MMI_ASSERT(0);
                }
            }
        }
    }
    else
    {
    #ifndef MMI_PHB_PBAPC_READ_PHONE_ONLY
        if(SRV_PHB_PBAP_STORAGE_PHONE_PB == phb_pbapc_cntx_p->read_storage &&
            MMI_FALSE == phb_pbapc_cntx_p->data_ready)
        {
            phb_pbapc_cntx_p->read_storage = SRV_PHB_PBAP_STORAGE_SIM1_PB; // read sim contact
            mmi_phb_pbapc_read_pse_list();

            return 0;
        }
    #endif /* MMI_PHB_PBAPC_READ_PHONE_ONLY */

        mmi_phb_pbapc_pse_list_loading_abort();
        //mmi_phb_pbapc_searching_abort();
    }

    return 0;
}


static S32 mmi_phb_pbapc_search_pse_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = -1;
    srv_phb_pbapc_read_list_req_struct list_req;
    srv_phb_pbapc_read_list_req_ex_struct ex_req;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    U16 search_utf8[MMI_PHB_NAME_LENGTH + 1];
    U8 search_asi[MMI_PHB_NAME_LENGTH + 1];
    S32 key_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    phb_pbapc_cntx_p->job_type = 0;

    mmi_chset_ucs2_to_utf8_string((U8 *)search_utf8, MMI_PHB_NAME_LENGTH, (U8 *)(phb_pbapc_cntx_p->qsearch_input_buffer));
    search_utf8[MMI_PHB_NAME_LENGTH] = L'\0';

    mmi_ucs2_n_to_asc(search_asi, (CHAR *)phb_pbapc_cntx_p->qsearch_input_buffer, MMI_PHB_NAME_LENGTH);
    search_asi[MMI_PHB_NAME_LENGTH] = '\0';

    key_len = mmi_ucs2strlen((S8*)phb_pbapc_cntx_p->qsearch_input_buffer);

    kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_search_pse_list--search_asi: %s, key_len: %d\n",
                    search_asi, key_len);

    if (phb_pbapc_cntx_p->pbapc_handle)
    {
        ret = SRV_PHB_PBAPC_RET_OK;
    }
    else
    {
        phb_pbapc_cntx_p->pbapc_handle = srv_phb_pbapc_create_handle(&ret);
    }

    if (ret == SRV_PHB_PBAPC_RET_OK)
    {
        ex_req.entry_count = SRV_PHB_PBAPC_MAX_READ_LIST_NUM;
        ex_req.list_entry = g_mmi_phb_pbapc_cntx.read_entry;
        /* Req head */
        list_req.handle = g_mmi_phb_pbapc_cntx.pbapc_handle;
        list_req.storage = g_mmi_phb_pbapc_cntx.read_storage;
        list_req.user_data = (void *)0xbabebabe;

        list_req.folder_name = NULL;
        list_req.query_attr = SRV_PHB_PBAP_ATTR_NAME;
        list_req.order = SRV_PHB_PBAP_SORT_ORDER_ALPHA;
        //list_req.query_pattern = (U8*)phb_pbapc_cntx_p->qsearch_input_buffer;
        list_req.query_pattern = (U8 *)search_utf8;
        list_req.query_length = mmi_ucs2strlen((S8*)phb_pbapc_cntx_p->qsearch_input_buffer);
        //list_req.query_count = MMI_PHB_PBAPC_MAX_PSE_CONTACT;
        list_req.query_count = MMI_PHB_PBAPC_MAX_PSE_CONTACT - phb_pbapc_cntx_p->pse_phone_num;
        list_req.query_offset = 0;
        list_req.query_offset = 0;
        list_req.list_req_ex = &ex_req;

        ret = srv_phb_pbapc_read_pse_list(&list_req, mmi_phb_pbapc_search_pse_list_hdlr);

        //phb_pbapc_cntx_p->pse_list_index = 0;
    }

    if (ret != SRV_PHB_PBAPC_RET_OK)
    {
        if (ret == SRV_PHB_PBAPC_RET_HD_FULL) // wait release handle evt
        {
            phb_pbapc_cntx_p->flag = 1;

            kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_read_pse_list(wait handle release)\n");
        }
        else
        {
            //mmi_phb_pbapc_show_loading_abort(GRP_ID_PHB_PBAPC_VIEW_CONTACT, SCR_ID_PHB_PROCESSING);
            //mmi_phb_pbapc_loading_option_back();
            //mmi_phb_pbapc_pse_list_loading_abort();
            mmi_phb_pbapc_searching_abort();
            //mmi_popup_display_simple_ext(STR_GLOBAL_FAILED, MMI_EVENT_FAILURE, GRP_ID_PHB_PBAPC_VIEW_CONTACT, NULL);
        }
    }

    //kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_read_pse_list--ret: %d, read_storage: %d\n",
    //                                                                ret, g_mmi_phb_pbapc_cntx.read_storage);

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_PBAPC_READ_PSE_LIST, ret, g_mmi_phb_pbapc_cntx.read_storage);

    return ret;
}


static S32 mmi_phb_pbapc_search_pse_list_hdlr(srv_phb_pbapc_read_list_rsp_struct *list_rsp, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    srv_phb_pbapc_list_entry_struct *list_entry = NULL;
    srv_phb_pbapc_list_entry_struct *pse_contact = NULL;
    U16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    pse_contact = phb_pbapc_cntx_p->pse_contact;

    if(phb_pbapc_cntx_p->pbapc_handle != NULL && phb_pbapc_cntx_p->job_type == 0 && phb_pbapc_cntx_p->free_handle == 1)
    {
        kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_search_pse_list_hdlr, list_state: %d\n",
                        phb_pbapc_cntx_p->list_state);

        if (list_rsp->ret == 0)
        {
            if (list_rsp->is_list_valid)
            {
                if (list_rsp->more_data == 1)
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }

        if (phb_pbapc_cntx_p->list_state == 2)
        {
            srv_phb_pbapc_destory_handle(phb_pbapc_cntx_p->pbapc_handle);
            phb_pbapc_cntx_p->pbapc_handle = NULL;
        }
        else if (phb_pbapc_cntx_p->list_state == 1)
        {
            phb_pbapc_cntx_p->total_pse_contact = 0;
            phb_pbapc_cntx_p->pse_phone_num = 0;
            phb_pbapc_cntx_p->pse_sim_num = 0;
            phb_pbapc_cntx_p->data_ready = MMI_FALSE;
            phb_pbapc_cntx_p->read_storage = SRV_PHB_PBAP_STORAGE_PHONE_PB;

            mmi_phb_pbapc_read_pse_list();
        }

        phb_pbapc_cntx_p->free_handle = 0;

        return 0;
    }

    if (list_rsp->ret == 0)
    {
        if (list_rsp->is_list_valid)
        {
            list_entry = list_rsp->list->list_entry;
            
            if(phb_pbapc_cntx_p->total_pse_contact < MMI_PHB_PBAPC_MAX_PSE_CONTACT)
            {
                for (i = 0; i < list_rsp->entry_count; ++i)
                {
                    index = phb_pbapc_cntx_p->total_pse_contact;
                    pse_contact[index].entry_index = list_entry[i].entry_index;
                    memcpy(pse_contact[index].entry_name, list_entry[i].entry_name, SRV_PHB_PBAPC_MAX_ENTRY_NAME_LEN + 1);

                    mmi_phb_pbapc_revise_string(pse_contact[index].entry_name, SRV_PHB_PBAPC_MAX_ENTRY_NAME_LEN + 1);

                    if (pse_contact[index].entry_name[0] == '\0')
                    {
                        continue;
                    }

                    if (list_entry[i].entry_index == 0)
                    {
                        /* filter sim1 owner number */
                        if (SRV_PHB_PBAP_STORAGE_SIM1_PB == phb_pbapc_cntx_p->read_storage)
                        {
                            //continue;
                        }
                        /* filter null phone owner number */
                        if (list_entry[i].entry_name[0] == '\0')
                        {
                            continue;
                        }
                    }

                    phb_pbapc_cntx_p->total_pse_contact += 1;

                    if(SRV_PHB_PBAP_STORAGE_PHONE_PB == phb_pbapc_cntx_p->read_storage)
                    {
                        phb_pbapc_cntx_p->pse_phone_num += 1;
                    }
                    else
                    {
                        phb_pbapc_cntx_p->pse_sim_num += 1;
                    }

                    if(phb_pbapc_cntx_p->total_pse_contact == MMI_PHB_PBAPC_MAX_PSE_CONTACT)
                    {
                        phb_pbapc_cntx_p->data_ready = MMI_TRUE;

                        //mmi_phb_pbapc_show_loading_abort(GRP_ID_PHB_MAIN, SCR_ID_PHB_PROCESSING);

                        mmi_phb_pbapc_searching_abort();

                        return 1;
                    }
                }
            }

            if (list_rsp->more_data == 0)
            {
                if(SRV_PHB_PBAP_STORAGE_PHONE_PB == phb_pbapc_cntx_p->read_storage &&
                    MMI_FALSE == phb_pbapc_cntx_p->data_ready)
                {
                #ifdef MMI_PHB_PBAPC_READ_PHONE_ONLY
                    phb_pbapc_cntx_p->data_ready = MMI_TRUE;
                    //mmi_phb_pbapc_show_loading_abort(GRP_ID_PHB_MAIN, SCR_ID_PHB_PROCESSING);
                    mmi_phb_pbapc_searching_abort();
                #else
                    phb_pbapc_cntx_p->read_storage = SRV_PHB_PBAP_STORAGE_SIM1_PB; // read sim contact
                    mmi_phb_pbapc_search_pse_list();
                #endif /* MMI_PHB_PBAPC_READ_PHONE_ONLY */
                }
                else if (SRV_PHB_PBAP_STORAGE_SIM1_PB == phb_pbapc_cntx_p->read_storage)
                {
                    phb_pbapc_cntx_p->data_ready = MMI_TRUE;

                    //mmi_phb_pbapc_show_loading_abort(GRP_ID_PHB_MAIN, SCR_ID_PHB_PROCESSING);

                    mmi_phb_pbapc_searching_abort();
                }
                else
                {
                    MMI_ASSERT(0);
                }
            }
        }
    }
    else
    {
    #ifndef MMI_PHB_PBAPC_READ_PHONE_ONLY
        if(SRV_PHB_PBAP_STORAGE_PHONE_PB == phb_pbapc_cntx_p->read_storage &&
            MMI_FALSE == phb_pbapc_cntx_p->data_ready)
        {
            phb_pbapc_cntx_p->read_storage = SRV_PHB_PBAP_STORAGE_SIM1_PB; // read sim contact
            mmi_phb_pbapc_search_pse_list();

            return 0;
        }
    #endif /* MMI_PHB_PBAPC_READ_PHONE_ONLY */

        //mmi_phb_pbapc_pse_list_loading_abort();
        mmi_phb_pbapc_searching_abort();
    }

    return 0;
}


static void mmi_phb_pbapc_show_searching(void)
{
    S32 ret = -1;

    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    phb_pbapc_cntx_p->show_dummy = MMI_TRUE;
    ret = mmi_frm_scrn_enter(phb_pbapc_cntx_p->parent_id, SCR_PHB_DUMMY, NULL, mmi_phb_pbapc_show_searching, MMI_FRM_FULL_SCRN);
    //mmi_frm_display_dummy_screen_ex(phb_pbapc_cntx_p->parent_id, SCR_PHB_DUMMY);
    kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_show_searching, ret: %d\n", ret);
    if (MMI_TRUE != ret)
    {
        return;
    }
    ShowCategory62Screen(STR_GLOBAL_LOADING, IMG_SCR_PBOOK_CAPTION, NULL);
}


static void mmi_phb_pbapc_searching_abort(void)
{
    S32 ret = -1;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_searching_abort\n");

    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    phb_pbapc_cntx_p->search_done = MMI_TRUE;
    phb_pbapc_cntx_p->show_dummy = MMI_FALSE;
    //mmi_frm_display_dummy_screen_ex(phb_pbapc_cntx_p->parent_id, SCR_PHB_DUMMY);
    mmi_frm_scrn_close(phb_pbapc_cntx_p->parent_id, SCR_PHB_DUMMY);
    //mmi_frm_display_dummy_screen();
    //mmi_frm_scrn_close_active_id();
}


static S32 mmi_phb_pbapc_find_entry_internal(U8 *keyword)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 key_length;
    S32 result_count;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    U8 search_asi[MMI_PHB_NAME_LENGTH + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    /* Count the input string length to decide behavior */
    key_length = (U8) mmi_ucs2strlen((CHAR*) keyword);

    mmi_ucs2_n_to_asc(search_asi, (CHAR *)keyword, MMI_PHB_NAME_LENGTH);
    search_asi[key_length] = '\0';

    kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_find_entry_internal--search_asi: %s, key_len: %d, state: %d\n",
                    search_asi, key_length, phb_pbapc_cntx_p->list_state);

    result_count = phb_pbapc_cntx_p->total_pse_contact;

    kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_find_entry_internal(search)--search_done: %d, show_dummy: %d, is_full: %d, input_complete: %d\n",
                phb_pbapc_cntx_p->search_done, phb_pbapc_cntx_p->show_dummy, phb_pbapc_cntx_p->is_full, g_wgui_cat199_refresh_when_input_complete);

    if (key_length >= MMI_PHB_QUICK_SEARCH_INPUT_LENGTH - 1)
    {
        if (phb_pbapc_cntx_p->is_full == MMI_TRUE)
        {
            return result_count;
        }
        if (g_wgui_cat199_refresh_when_input_complete == MMI_TRUE)
        {
            phb_pbapc_cntx_p->is_full = MMI_TRUE;
        }
    }
    else
    {
        phb_pbapc_cntx_p->is_full = MMI_FALSE;
    }

    if (phb_pbapc_cntx_p->search_done == MMI_TRUE || g_wgui_cat199_refresh_when_input_complete == MMI_FALSE ||
        !srv_bt_cm_is_profile_connected(SRV_BT_CM_PBAPC_CONNECTION) ||
        phb_pbapc_cntx_p->show_dummy == MMI_TRUE ||
        phb_pbapc_cntx_p->list_state == 2)
    {
        phb_pbapc_cntx_p->search_done = MMI_FALSE;
        if (phb_pbapc_cntx_p->show_dummy == MMI_TRUE)
        {
            return -1;
        }
    }
    else if (phb_pbapc_cntx_p->pbapc_handle == NULL)
    {
        mmi_phb_pbapc_show_searching();
        //g_mmi_phb_pbapc_cntx.pbapc_handle = NULL;
        phb_pbapc_cntx_p->total_pse_contact = 0;
        phb_pbapc_cntx_p->pse_phone_num = 0;
        phb_pbapc_cntx_p->pse_sim_num = 0;
        phb_pbapc_cntx_p->data_ready = MMI_FALSE;
        //mmi_phb_pbapc_show_loading(phb_pbapc_cntx_p->parent_id, SCR_ID_PHB_PROCESSING);
        //mmi_phb_pbapc_show_searching();

        /* read phone contact */
        phb_pbapc_cntx_p->read_storage = SRV_PHB_PBAP_STORAGE_PHONE_PB;

        // reset input_complete
        g_wgui_cat199_refresh_when_input_complete = MMI_FALSE;

        mmi_phb_pbapc_search_pse_list();
    }
    else
    {
        // just wait rsp coming
        mmi_phb_pbapc_show_loading(phb_pbapc_cntx_p->parent_id, SCR_ID_PHB_PROCESSING);
    }

    return result_count;
}


static S32 mmi_phb_pbapc_find_entry(U8 *keyword)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result_count;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result_count = mmi_phb_pbapc_find_entry_internal(keyword);

    kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_find_entry--result_count: %d\n", result_count);

#ifdef __MMI_TELEPHONY_SUPPORT__
    if (result_count == 0)
    {
        SetKeyHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
#endif

    return result_count;
}


static BOOL mmi_phb_pbapc_lsk_present_function(S32 *max_number)
{
    if (!srv_bt_cm_is_profile_connected(SRV_BT_CM_PBAPC_CONNECTION))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


static S32 mmi_phb_pbapc_search_function(U8 *keyword)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result_count = 0;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    g_wgui_cat199_refresh_when_input_complete = MMI_TRUE;

    result_count = mmi_phb_pbapc_find_entry_internal((U8 *)(phb_pbapc_cntx_p->qsearch_input_buffer));

    kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_search_function--result_count: %d\n", result_count);

    return result_count;
}


static void mmi_phb_pbapc_show_pse_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    U8 *gui_buffer = NULL;
    S32 has_lsk = MMI_FALSE;
    U16 str_id = 0, img_id = 0;
    U8 tab_index = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    //kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_show_pse_list--pbapc_handle: 0x%x, total_pse_contact: %d, pse_phone_num: %d\n",
    //            phb_pbapc_cntx_p->pbapc_handle, phb_pbapc_cntx_p->total_pse_contact, phb_pbapc_cntx_p->pse_phone_num);

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_PBAPC_SHOW_PSE_LIST,
                phb_pbapc_cntx_p->pbapc_handle, phb_pbapc_cntx_p->total_pse_contact, phb_pbapc_cntx_p->pse_phone_num);

    kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_show_pse_list(list state)--list_state: %d\n",
                phb_pbapc_cntx_p->list_state);

    // reset status bar
    //wgui_status_icon_bar_reset();

    //
    //phb_pbapc_cntx_p->symbol_show = 0;

    //UI_common_screen_exit();

    #if 1
    if (phb_pbapc_cntx_p->pbapc_handle != NULL)
    {
        srv_phb_pbapc_destory_handle(phb_pbapc_cntx_p->pbapc_handle);
        phb_pbapc_cntx_p->pbapc_handle = NULL;
    }
    #endif

    if (phb_pbapc_cntx_p->list_state != 1)
    {
        return;
    }

    UI_common_screen_exit();

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    RegisterHighlightHandler(mmi_phb_pbapc_pse_list_highlight_hdlr);

    kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_show_pse_list(gui_buffer)--gui_buffer: 0x%x\n",
                gui_buffer);

    kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_show_pse_list(search)--search_done: %d, show_dummy: %d, is_full: %d\n",
                phb_pbapc_cntx_p->search_done, phb_pbapc_cntx_p->show_dummy, phb_pbapc_cntx_p->is_full);

    if(NULL == gui_buffer)
    {
        phb_pbapc_cntx_p->pse_list_index = 0;
        //phb_pbapc_cntx_p->qsearch_input_buffer[0] = 0;
    }
    else
    {
        if (history_data)
        {
            mmi_imc_get_input_method_history(history_data);
            mmi_imc_set_input_method_history(history_data);
        }
    }
    phb_pbapc_cntx_p->search_done = MMI_FALSE;

    wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_NO_ICON);

    // reset gui buffer
    if(!srv_bt_cm_is_profile_connected(SRV_BT_CM_PBAPC_CONNECTION) || phb_pbapc_cntx_p->total_pse_contact == 0)
    {
        gui_buffer = NULL;
    }

    if(!srv_bt_cm_is_profile_connected(SRV_BT_CM_PBAPC_CONNECTION))
    {
        wgui_set_menu_empty_string_by_id(STR_ID_PHB_PBAPC_NO_CONN);
    }
    else
    {
        wgui_set_menu_empty_string_by_id(STR_GLOBAL_EMPTY);
    }
    if (phb_pbapc_cntx_p->total_pse_contact)
    {
        has_lsk = MMI_TRUE;
    }

#ifndef __MMI_PHB_QUICK_SEARCH__
    wgui_cat1032_show(
                (WCHAR*) GetString(STR_SCR_PBOOK_VIEW_CAPTION),
                (PU8) GetImage(IMG_SCR_PBOOK_CAPTION),
                has_lsk?(WCHAR*) GetString(STR_GLOBAL_OPTIONS): NULL,
                has_lsk?(PU8) GetImage(IMG_GLOBAL_OPTIONS):NULL,
                (WCHAR*) GetString(STR_GLOBAL_BACK),
                (PU8) GetImage(IMG_GLOBAL_BACK),
                phb_pbapc_cntx_p->total_pse_contact,
                mmi_phb_pbapc_pse_list_get_item,
                NULL,
                phb_pbapc_cntx_p->pse_list_index,
                1,
                0,
                0,
                gui_buffer,
                NULL);
    SetRightSoftkeyFunction(mmi_phb_pbapc_pse_list_op_option_back, KEY_EVENT_UP);
#else
    RegisterCat200SearchFunction(mmi_phb_pbapc_find_entry);
    Register_appl_present_function(mmi_phb_pbapc_lsk_present_function);
#ifdef __MMI_TELEPHONY_SUPPORT__
    if (has_lsk)
    {
        str_id = STR_GLOBAL_OK;
        img_id = IMG_GLOBAL_OK;
    }
    else if (!srv_bt_cm_is_profile_connected(SRV_BT_CM_PBAPC_CONNECTION))
    {
        str_id = STR_GLOBAL_CONNECT;
        img_id = IMG_GLOBAL_OK;
    }

    wgui_cat_set_search_icon(IMG_ID_PHB_QUICK_SEARCH_FIND);

    if (phb_pbapc_cntx_p->list_type == 0)
    {
        tab_index = MMI_PHB_MAIN_SCREEN_TAB_COUNT - 1;
    }

    ShowCategory199Screen_ext(
        (UI_string_type)GetString(str_id),
        (PU8)GetImage(img_id),
        (UI_string_type)GetString(STR_GLOBAL_BACK),
        (PU8)GetImage(IMG_GLOBAL_BACK),
        tab_index,        
        (UI_string_type)GetString(STR_SCR_PBOOK_VIEW_CAPTION),
        NULL,
        phb_pbapc_cntx_p->total_pse_contact,
        mmi_phb_pbapc_pse_list_get_item,
        NULL,
        NULL,
        NULL,
        phb_pbapc_cntx_p->pse_list_index,
        get_image(IMG_GLOBAL_L1),
        get_image(IMG_STORAGE_SIM),
        (U8*) phb_pbapc_cntx_p->qsearch_input_buffer,
        MMI_PHB_QUICK_SEARCH_INPUT_LENGTH,
        gui_buffer);
#else
    if (has_lsk)
    {
        str_id = (phb_pbapc_cntx_p->list_type == 0) ? STR_GLOBAL_VIEW : STR_GLOBAL_OK;
        img_id = IMG_GLOBAL_OK;
    }
    else if (!srv_bt_cm_is_profile_connected(SRV_BT_CM_PBAPC_CONNECTION))
    {
        str_id = STR_GLOBAL_CONNECT;
        img_id = IMG_GLOBAL_OK;
    }

    ShowCategory200Screen_ext(
        STR_SCR_PBOOK_VIEW_CAPTION,
        IMG_SCR_PBOOK_CAPTION,
        str_id,
        img_id,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        phb_pbapc_cntx_p->total_pse_contact,
        mmi_phb_pbapc_pse_list_get_item,
        NULL,
        phb_pbapc_cntx_p->pse_list_index,
        IMG_ID_PHB_QUICK_SEARCH_FIND,
        get_image(IMG_GLOBAL_L1),
        get_image(IMG_STORAGE_SIM),
        (U8*) phb_pbapc_cntx_p->qsearch_input_buffer,
        MMI_PHB_QUICK_SEARCH_INPUT_LENGTH,
        gui_buffer);
#endif /* __MMI_TELEPHONY_SUPPORT__ */

    SetCategory200RightSoftkeyFunction(mmi_phb_pbapc_pse_list_op_option_back, KEY_EVENT_UP);
#endif

    wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_DEFAULT);

    if(!srv_bt_cm_is_profile_connected(SRV_BT_CM_PBAPC_CONNECTION))
    {
        ChangeLeftSoftkey(STR_GLOBAL_CONNECT, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_phb_pbapc_pse_list_connect, KEY_EVENT_UP);
        SetCategory200LeftSoftkeyFunction(mmi_phb_pbapc_pse_list_connect, KEY_EVENT_UP);
        //wgui_set_menu_empty_string_by_id(STR_ID_PHB_PBAPC_NO_CONN);

        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_phb_pbapc_pse_list_connect, KEY_EVENT_UP);
    }
    else
    {
        if (phb_pbapc_cntx_p->total_pse_contact)
        {
            SetLeftSoftkeyFunction(mmi_phb_pbapc_pse_list_op_option, KEY_EVENT_UP);
            SetCategory200LeftSoftkeyFunction(mmi_phb_pbapc_pse_list_op_option, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(mmi_phb_pbapc_pse_list_op_option, KEY_EVENT_UP);
        }
    }

    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

#ifdef __MMI_TOUCH_SCREEN__
    wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
#endif /* __MMI_TOUCH_SCREEN__ */

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_phb_pbapc_bt_list_tap_callback);
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */

    if (phb_pbapc_cntx_p->list_type == 0 && phb_pbapc_cntx_p->total_pse_contact > 0)
    {
        SetKeyHandler(mmi_phb_pbapc_pse_list_call, KEY_SEND, KEY_EVENT_UP);

        phb_pbapc_cntx_p->phb_state = 0;
    }
    else
    {
        ClearKeyHandler(KEY_SEND, KEY_EVENT_UP);
    }
}


static void mmi_phb_pbapc_pse_list_highlight_hdlr(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    srv_phb_pbapc_list_entry_struct *pse_contact = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    pse_contact = phb_pbapc_cntx_p->pse_contact;

    if (phb_pbapc_cntx_p->list_type == 0)
    {
        phb_pbapc_cntx_p->pse_list_index = item_index;
        phb_pbapc_cntx_p->pse_entry_index = phb_pbapc_cntx_p->pse_contact[item_index].entry_index;

        if (item_index < phb_pbapc_cntx_p->pse_phone_num)
        {
            phb_pbapc_cntx_p->contact_storage  = SRV_PHB_PBAP_STORAGE_PHONE_PB;
        }
        else
        {
            phb_pbapc_cntx_p->contact_storage  = SRV_PHB_PBAP_STORAGE_SIM1_PB;
        }
    }
    else if (phb_pbapc_cntx_p->list_type == 1)
    {
        phb_pbapc_cntx_p->cui_pse_list_index = item_index;
        phb_pbapc_cntx_p->cui_pse_entry_index = phb_pbapc_cntx_p->pse_contact[item_index].entry_index;

        if (item_index < phb_pbapc_cntx_p->pse_phone_num)
        {
            phb_pbapc_cntx_p->cui_contact_storage  = SRV_PHB_PBAP_STORAGE_PHONE_PB;
        }
        else
        {
            phb_pbapc_cntx_p->cui_contact_storage  = SRV_PHB_PBAP_STORAGE_SIM1_PB;
        }
    }

    if (phb_pbapc_cntx_p->list_type == 0)
    {
        //ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OK);
        ChangeLeftSoftkey(STR_GLOBAL_VIEW, IMG_GLOBAL_OK);
    }
    else if (phb_pbapc_cntx_p->list_type == 1)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    }

    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_pbapc_pse_list_op_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_phb_pbapc_pse_list_op_option_back, KEY_EVENT_UP);

    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_phb_pbapc_pse_list_op_option, KEY_EVENT_UP);

    if (phb_pbapc_cntx_p->list_type == 0 && phb_pbapc_cntx_p->total_pse_contact > 0)
    {
        SetKeyHandler(mmi_phb_pbapc_pse_list_call, KEY_SEND, KEY_EVENT_UP);

        phb_pbapc_cntx_p->phb_state = 0;
    }
    else
    {
        ClearKeyHandler(KEY_SEND, KEY_EVENT_UP);
    }
#ifdef __MMI_TELEPHONY_SUPPORT__
#ifdef __MMI_PHB_QUICK_SEARCH__
    SetKeyHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif
#endif
}


static void mmi_phb_pbapc_pse_list_op_option_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    if (phb_pbapc_cntx_p->list_type == 0)
    {
        mmi_frm_scrn_close_active_id();

        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        mmi_frm_group_close(phb_pbapc_cntx_p->parent_id);
    }
    else if (phb_pbapc_cntx_p->list_type == 1)
    {
        cui_phb_pbapc_bt_send_select_result(NULL, 1); // select cancel
    }
}


static void mmi_phb_pbapc_pse_list_op_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
#if 0
/* under construction !*/
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    if (phb_pbapc_cntx_p->list_type == 0)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

        cui_phb_pbapc_view_pse_contact(GRP_ID_PHB_MAIN, phb_pbapc_cntx_p->pse_entry_index, phb_pbapc_cntx_p->contact_storage);

    }
    else if (phb_pbapc_cntx_p->list_type == 1)
    {
        cui_phb_pbapc_pre_select_contact();
    }
}


static void mmi_phb_pbapc_pse_list_connect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    mmi_ret gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    
    if (phb_pbapc_cntx_p->list_type == 0)
    {
        gid = GRP_ID_PHB_MAIN;
    }
    else if (phb_pbapc_cntx_p->list_type == 1)
    {
        gid = GRP_ID_PHB_PBAPC_SELECT_CONTACT;
    }
    else
    {
        gid = mmi_frm_group_get_active_id();
    }

    //kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_pse_list_connect--gid: %d, MAIN: %d, sel: %d\n",
    //            gid, GRP_ID_PHB_MAIN, GRP_ID_PHB_PBAPC_SELECT_CONTACT);
    g_grp_id = gid;
    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_PBAPC_PSE_LIST_CONNECT, gid, GRP_ID_PHB_MAIN, GRP_ID_PHB_PBAPC_SELECT_CONTACT);
    if (mmi_bt_dialer_app_is_connected())
    {
        //mmi_bt_dialer_conn_profile(gid, SRV_BT_CM_PBAPC_CONNECTION, mmi_phb_pbapc_con_profile_cb);
    }
    else
    {
        mmi_bt_dialer_show_popup(gid);
    }
}
 

static void mmi_phb_pbapc_con_profile_cb(srv_bt_cm_connection_type conn_type,MMI_BOOL result,MMI_BOOL is_connect)
{
    //kal_prompt_trace(MOD_MMI, "mmi_clog_bt_link_conn_profile_cb: result = %d", result);

    mmi_frm_scrn_close(g_grp_id,SCR_BT_CONNECTING);
  //mmi_bt_dialer_conn_profile_end(SRV_BT_CM_PBAPC_CONNECTION);
    if (!result)
    {
        mmi_frm_nmgr_popup(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_FAILURE,
        (WCHAR*)GetString(STR_BT_CONN_FAILED));

    }
}


static S32 mmi_phb_pbapc_pse_list_get_item(S32 item_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < data_size; index++)
    {
       mmi_phb_pbapc_pse_list_get_item_int((item_index + index), menu_data[index].item_list[0], &menu_data[index].image_list[0], &menu_data[index].image_list[1]);
    }
    return data_size;
}

static void mmi_phb_pbapc_pse_list_get_item_int(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p1, PU8 *img_buff_p2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    srv_phb_pbapc_list_entry_struct *pse_contact = NULL;
    U8 entry_name[SRV_PHB_PBAPC_MAX_ENTRY_NAME_LEN + 1] = "\0";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    pse_contact = phb_pbapc_cntx_p->pse_contact;

    if (phb_pbapc_cntx_p->total_pse_contact == 0) return;

    /* qp encode */
    if (pse_contact[item_index].entry_name[0] == '=')
    {
        S32 i = 0, j = 0, c = 0;
        for (i = 0; i < SRV_PHB_PBAPC_MAX_ENTRY_NAME_LEN && pse_contact[item_index].entry_name[i] != '\0'; ++i)
        {
            if (pse_contact[item_index].entry_name[i] == '=')
            {
                sscanf(pse_contact[item_index].entry_name + i, "=%02X", &c);
                entry_name[j] = c;
                i += 2;
            }
            else
            {
                entry_name[j] = pse_contact[item_index].entry_name[i];
            }
            ++j;
        }

        entry_name[j] = '\0';

        mmi_chset_utf8_to_ucs2_string((kal_uint8 *)str_buff, 2 * (mmi_chset_utf8_strlen(entry_name) + 1), entry_name);
    }
    else
    {
        mmi_chset_utf8_to_ucs2_string((kal_uint8 *)str_buff, 2 * (strlen(pse_contact[item_index].entry_name) + 1), (kal_uint8 *) pse_contact[item_index].entry_name);
    }

    if (str_buff[0] == 0)
    {
        mmi_ucs2ncpy((CHAR*) str_buff, GetString(STR_ID_PHB_UNNAMED), MAX_SUBMENU_CHARACTERS);
    }
#ifdef __MMI_PHB_QUICK_SEARCH__
    *img_buff_p1 = (item_index < phb_pbapc_cntx_p->pse_phone_num) ? get_image(IMG_STORAGE_HANDSET) : get_image(IMG_GLOBAL_SIM1);
#endif
}


mmi_ret mmi_phb_pbapc_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_DONT_CARE;
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    mmi_ret gid = GRP_ID_PHB_MAIN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_menu_cui_proc--evt_id: %d, menu_id: %d, MENU_ITEM_SELECT: %d, MENU_ID_VIEW_CONTACT: %d\n",
    //                                                                evt->evt_id, menu_evt->highlighted_menu_id, EVT_ID_CUI_MENU_ITEM_SELECT, MENU_ID_PHB_PBAPC_VIEW_CONTACT);

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_PBAPC_MENU_CUI_PROC, evt->evt_id, menu_evt->highlighted_menu_id,
                    EVT_ID_CUI_MENU_ITEM_SELECT, MENU_ID_PHB_PBAPC_VIEW_CONTACT);

    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            switch (menu_evt->highlighted_menu_id)
            {  
                /* pse list option */
                case MENU_ID_PHB_PBAPC_VIEW_CONTACT:
                {
                    if (phb_pbapc_cntx_p->list_type == 0)
                    {
                        gid = GRP_ID_PHB_MAIN;
                        //cui_phb_pbapc_view_pse_contact(GRP_ID_PHB_MAIN, phb_pbapc_cntx_p->pse_entry_index, phb_pbapc_cntx_p->contact_storage);
                    }
                    else
                    {
                        gid = GRP_ID_PHB_PBAPC_SELECT_CONTACT;
                    }

                    cui_phb_pbapc_view_pse_contact(gid, phb_pbapc_cntx_p->pse_entry_index, phb_pbapc_cntx_p->contact_storage);

                    ret = MMI_RET_OK;
                    break;
                }
                case MENU_ID_PHB_PBAPC_CALL:
                {
                    mmi_phb_pbapc_pse_list_call();
                    ret = MMI_RET_OK;
                    break;
                }

                /* view menu option */
                case MENU_ID_PHB_PBAPC_VIEW_CONTACT_SEND_SMS:
                {
                    mmi_phb_pbapc_view_contact_op_msg();
                    ret = MMI_RET_OK;
                    break;
                }
                case MENU_ID_PHB_PBAPC_VIEW_CONTACT_DIAL:
                {
                    mmi_phb_pbapc_view_contact_op_call();
                    ret = MMI_RET_OK;
                    break;
                }
                case MENU_ID_PHB_PBAPC_VIEW_CONTACT_SAVE:
                {
                    mmi_phb_pbapc_save_pse_contact();
                    ret = MMI_RET_OK;
                }

                default:
                {
                    ret = MMI_RET_DONT_CARE;
                    break;
                }
            }
            break;
        }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(menu_evt->sender_id);
            ret = MMI_RET_OK;
            break;
        }

        default:
        {
            ret = MMI_RET_DONT_CARE;
            break;
        }
    }

    return ret;
}


static void mmi_phb_pbapc_pse_list_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
#ifdef PBAPC_UNIT_TEST
    srv_phb_pbapc_read_entry_rsp_struct entry_rsp;
    U16 temp_path[260];
    mmi_phb_pbapc_cb_info_struct cb_info;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    //kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_pse_list_call--entry_index: %d, storage: %d\n",
    //                                                                phb_pbapc_cntx_p->pse_entry_index, phb_pbapc_cntx_p->contact_storage);

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_PBAPC_PSE_LIST_CALL, phb_pbapc_cntx_p->pse_entry_index, phb_pbapc_cntx_p->contact_storage);

    kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_pse_list_call--phb_state: %d\n", phb_pbapc_cntx_p->phb_state);

    if (1 == phb_pbapc_cntx_p->phb_state)
    {
        return ;
    }

    phb_pbapc_cntx_p->phb_state = 1;

#ifndef PBAPC_UNIT_TEST
    //0xbabe0001 read pse contact from pse list call
    mmi_phb_pbapc_read_pse_entry(phb_pbapc_cntx_p->pse_entry_index, phb_pbapc_cntx_p->contact_storage, (void *)0xbabe0001, mmi_phb_pbapc_pse_list_call_read_entry_cb);
#else
    /* test */
    //mmi_wcscpy(temp_path, L"E:\\entry.tmp");
    mmi_wcscpy(temp_path, L"E:\\test.vcf");
    cb_info.cb_type = 0;
    entry_rsp.entry_path = temp_path;
    entry_rsp.ret = 0;
    cb_info.type_rsp = (void *)&entry_rsp;
    mmi_phb_pbapc_pse_list_call_read_entry_cb(&cb_info);
#endif
}


static S32 mmi_phb_pbapc_pse_list_call_read_entry_cb(mmi_phb_pbapc_cb_info_struct *cb_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    srv_phb_pbapc_read_entry_rsp_struct *entry_rsp = NULL;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    mmi_ucm_make_call_para_struct call_para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    entry_rsp = (srv_phb_pbapc_read_entry_rsp_struct *)cb_info->type_rsp;

    //mmi_phb_pbapc_show_loading_abort(GRP_ID_PHB_PBAPC_VIEW_CONTACT, SCR_ID_PHB_PROCESSING);
    //kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_pse_list_call_read_entry_cb(ret)--ret: %d\n",
    //                                                                entry_rsp->ret);

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_PBAPC_PSE_LIST_CALL_READ_ENTRY_CB_RET, entry_rsp->ret);

    phb_pbapc_cntx_p->phb_state = 0;

    if (entry_rsp->ret == 0)
    {
        memset(&(phb_pbapc_cntx_p->pse_phb), 0x00, sizeof(mmi_phb_pbapc_phb_info_struct));
        mmi_phb_pbapc_parse_single_vcard_file(entry_rsp->entry_path, &(phb_pbapc_cntx_p->pse_phb));

        if (phb_pbapc_cntx_p->pse_phb.num_count == 0)
        {
            /* show no number popup */
            //kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_pse_list_call_read_entry_cb(null number call)\n");

            MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_PBAPC_PSE_LIST_CALL_READ_ENTRY_CB_N_NUM_CALL);

            mmi_ucm_init_call_para(&call_para);

            call_para.ucs2_num_uri = phb_pbapc_cntx_p->pse_phb.num[0].number;
            phb_pbapc_cntx_p->pse_phb.num[0].number[0] = L'\0'; // set num null
            call_para.adv_para.after_callback_user_data = NULL;
            call_para.adv_para.after_make_call_callback = NULL;
            call_para.adv_para.highlight_dial_type = SRV_UCM_INVALID_CALL_TYPE;
            call_para.adv_para.is_ip_dial = MMI_FALSE;
            call_para.adv_para.module_id = SRV_UCM_MODULE_ORIGIN_COMMON;
            call_para.adv_para.phb_data = NULL;
            mmi_ucm_call_launch(0, &call_para);
        }
        else if (phb_pbapc_cntx_p->pse_phb.num_count > 1)
        {
            phb_pbapc_cntx_p->op_type = 1;

            mmi_phb_pbapc_select_op_number(GRP_ID_PHB_MAIN, mmi_phb_pbapc_view_sel_num_cb, 
                                   (void *)0xbabe0002, &(phb_pbapc_cntx_p->pse_phb));
        }
        else /* just 1 number call directly */
        {
            //kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_pse_list_call_read_entry_cb(call)\n");

            MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_PBAPC_PSE_LIST_CALL_READ_ENTRY_CB_CALL);

            mmi_ucm_init_call_para(&call_para);

            call_para.ucs2_num_uri = phb_pbapc_cntx_p->pse_phb.num[0].number;
            call_para.adv_para.after_callback_user_data = NULL;
            call_para.adv_para.after_make_call_callback = NULL;
            call_para.adv_para.highlight_dial_type = SRV_UCM_INVALID_CALL_TYPE;
            call_para.adv_para.is_ip_dial = MMI_FALSE;
            call_para.adv_para.module_id = SRV_UCM_MODULE_ORIGIN_COMMON;
            call_para.adv_para.phb_data = NULL;
            mmi_ucm_call_launch(0, &call_para);
        }
    }
    else
    {
        mmi_popup_display_simple_ext(STR_GLOBAL_FAILED, MMI_EVENT_FAILURE, GRP_ID_PHB_MAIN, NULL);
        //mmi_frm_group_close(GRP_ID_PHB_PBAPC_VIEW_CONTACT);
    }

    return ret;
}


static void cui_phb_pbapc_view_pse_contact(mmi_id parent_id, U16 entry_index, srv_phb_pbap_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = -5;
#ifdef PBAPC_UNIT_TEST
    mmi_phb_pbapc_cb_info_struct cb_info;
    srv_phb_pbapc_read_entry_rsp_struct entry_rsp;
    U16 temp_path[260];
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] cui_phb_pbapc_view_pse_contact--parent_id: %d, entry_index: %d, storage: %d\n",
    //                                                                parent_id, entry_index, storage);

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_PBAPC_VIEW_PSE_CONTACT, parent_id, entry_index, storage);

    mmi_frm_group_create_ex(parent_id, GRP_ID_PHB_PBAPC_VIEW_CONTACT, mmi_phb_pbapc_view_pse_contact_proc, NULL, MMI_FRM_NODE_NONE_FLAG);

    //ret = mmi_frm_scrn_enter(GRP_ID_PHB_PBAPC_VIEW_CONTACT, SCR_PHB_DUMMY, NULL, NULL, MMI_FRM_FULL_SCRN);

    kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] cui_phb_pbapc_view_pse_contact(dummy)--ret: %d\n",
                    ret);

    mmi_phb_pbapc_show_loading(GRP_ID_PHB_PBAPC_VIEW_CONTACT, SCR_ID_PHB_PROCESSING);

#ifndef PBAPC_UNIT_TEST
    mmi_phb_pbapc_read_pse_entry(entry_index, storage, (void *)0xabcd, mmi_phb_pbapc_read_pse_contact_cb);
#else
    /* test */
    mmi_wcscpy(temp_path, L"E:\\test.vcf");
    cb_info.cb_type = 0;
    entry_rsp.entry_path = temp_path;
    entry_rsp.ret = 0;
    cb_info.type_rsp = (void *)&entry_rsp;
    mmi_phb_pbapc_read_pse_contact_cb(&cb_info);
#endif
}


static S32 mmi_phb_pbapc_read_pse_contact_cb(mmi_phb_pbapc_cb_info_struct *cb_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = -5;
    srv_phb_pbapc_read_entry_rsp_struct *entry_rsp = NULL;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    entry_rsp = (srv_phb_pbapc_read_entry_rsp_struct *)cb_info->type_rsp;

    mmi_phb_pbapc_show_loading_abort(GRP_ID_PHB_PBAPC_VIEW_CONTACT, SCR_ID_PHB_PROCESSING);

    //ret = mmi_frm_scrn_close(GRP_ID_PHB_PBAPC_VIEW_CONTACT, SCR_PHB_DUMMY);

    kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_read_pse_contact_cb--entry_rsp->ret: %d, ret: %d\n",
                    entry_rsp->ret, ret);

    if (entry_rsp->ret == 0)
    {
        memset(&(phb_pbapc_cntx_p->pse_phb), 0x00, sizeof(mmi_phb_pbapc_phb_info_struct));
        mmi_phb_pbapc_parse_single_vcard_file(entry_rsp->entry_path, &(phb_pbapc_cntx_p->pse_phb));

        if (phb_pbapc_cntx_p->pse_phb.name[0] == '\0' && phb_pbapc_cntx_p->pse_phb.num_count == 0)
        {
            mmi_frm_nmgr_popup(
                   MMI_SCENARIO_ID_DEFAULT,
                   MMI_EVENT_FAILURE,
                   (WCHAR*)GetString(STR_GLOBAL_FAILED));

            mmi_frm_group_close(GRP_ID_PHB_PBAPC_VIEW_CONTACT);
        }
        else
        {
            mmi_frm_scrn_create(GRP_ID_PHB_PBAPC_VIEW_CONTACT, SCR_ID_PHB_PBAPC_VIEW_CONTACT, mmi_phb_pbapc_view_contact_scrn_proc, NULL);
        }
    }
    else
    {
        //mmi_popup_display_simple_ext(STR_GLOBAL_FAILED, MMI_EVENT_FAILURE, GRP_ID_PHB_PBAPC_VIEW_CONTACT, NULL);
        mmi_frm_nmgr_popup(
               MMI_SCENARIO_ID_DEFAULT,
               MMI_EVENT_FAILURE,
               (WCHAR*)GetString(STR_GLOBAL_FAILED));

        mmi_frm_group_close(GRP_ID_PHB_PBAPC_VIEW_CONTACT);
    }
    return ret;
}


static MMI_RET mmi_phb_pbapc_view_contact_scrn_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_INACTIVE:
        {
            break;

        }

        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_phb_pbapc_show_pse_contact_detail();
            break;
        }

        case EVT_ID_SCRN_DEINIT:
        {
        #if defined(__MMI_WEARABLE_DEVICE__)
            if(mmi_frm_scrn_is_present(GRP_ID_PHB_PBAPC_VIEW_CONTACT, SCR_ID_PHB_PBAPC_VIEW_CONTACT, MMI_FRM_NODE_ALL_FLAG))
            {
                //mmi_frm_scrn_close(GRP_ID_PHB_PBAPC_VIEW_CONTACT, SCR_ID_PHB_PBAPC_VIEW_CONTACT);
            }

            mmi_frm_group_close(GRP_ID_PHB_PBAPC_VIEW_CONTACT);
        #endif /* defined(__MMI_WEARABLE_DEVICE__) */
            break;
        }
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        {
            break;
        }
        default:
         break;
     }

    return MMI_RET_OK;
}


static void mmi_phb_pbapc_show_pse_contact_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    CHAR *item_list[MAX_PHB_PBAPC_MAX_FIELDS * 2]; 
    S32 highlight_item = 0;
    U8 *gui_buffer = NULL;
    S32 item_num = 0;
    mmi_phb_pbapc_phb_info_struct *phb_info = NULL;
    S32 i = 0, k = 0;
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    phb_info = &(phb_pbapc_cntx_p->pse_phb);

    //kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_show_pse_contact_detail--pbapc_handle: 0x%x, num_count: %d\n",
    //            phb_pbapc_cntx_p->pbapc_handle, phb_info->num_count);

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_PBAPC_SHOW_PSE_CONTACT_DETAIL, phb_pbapc_cntx_p->pbapc_handle, phb_info->num_count);

    phb_pbapc_cntx_p->phb_state = 0;

    // reset status bar
    wgui_status_icon_bar_reset();

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    RegisterHighlightHandler(mmi_phb_pbapc_view_contact_highlight_hdlr);

    wgui_fixed_list_register_get_flags_handler(mmi_phb_pbapc_set_pse_view_flags);

    //if (phb_info->name[0])
    {
        item_list[0] = GetString(STR_ID_PHB_NAME);
        item_list[1] = (CHAR *)(phb_info->name);
        highlight_item = item_num;
        ++item_num;
    }

    for (i = 0, k = (item_num << 1); i < phb_info->num_count; ++i)
    {
        str_id = mmi_phb_pbapc_get_num_type(phb_info->num[i].type);
        item_list[k] = GetString(str_id);
        item_list[k + 1] = (CHAR *)(phb_info->num[i].number);
        k += 2;
    }
    if (phb_info->name[0])
    {
        highlight_item = 1;
    }
    else
    {
        highlight_item = 3;
    }

    if (gui_buffer)
    {
        highlight_item = (phb_pbapc_cntx_p->hlight_index << 1) + 1;
    }

    item_num += phb_info->num_count;

    if (phb_info->num_count == 0)
    {
        item_num += 1;
        item_list[2] = GetString(STR_ID_PHB_NUMBER);
        item_list[3] = NULL;
    }

    ShowCategory84Screen(
                STR_SCR_ENTRY_VIEW_CAPTION,
                GetRootTitleIcon(MAIN_MENU_PHONEBOOK_MENUID),
                0,
                0,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                item_num * 2,
                (U8 **) item_list,
                NULL,
                WGUI_CATE_ITEM_DISABLE_WITHOUT_CHANGE_TEXT_COLOR,
                highlight_item,
                gui_buffer);
}


static void mmi_phb_pbapc_view_contact_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    phb_pbapc_cntx_p->hlight_index = index >> 1;

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
    #endif

    if (phb_pbapc_cntx_p->list_type == 0)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OK);
    }
    else if (phb_pbapc_cntx_p->list_type == 1)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    }
    else
    {
        ;
    }

    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_phb_pbapc_view_contact_option, KEY_EVENT_UP);
    
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_phb_pbapc_view_contact_option, KEY_EVENT_UP);

    SetRightSoftkeyFunction(mmi_phb_pbapc_view_contact_option_back, KEY_EVENT_UP);

    // add send key call handle
    SetKeyHandler(mmi_phb_pbapc_view_contact_op_call, KEY_SEND, KEY_EVENT_UP);
}


static void mmi_phb_pbapc_view_contact_option_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    mmi_frm_scrn_close_active_id();

    if(mmi_frm_scrn_is_present(GRP_ID_PHB_PBAPC_VIEW_CONTACT, SCR_ID_PHB_PBAPC_VIEW_CONTACT, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_PHB_PBAPC_VIEW_CONTACT, SCR_ID_PHB_PBAPC_VIEW_CONTACT);
    }

    mmi_frm_group_close(GRP_ID_PHB_PBAPC_VIEW_CONTACT);
}


static void mmi_phb_pbapc_view_contact_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    MMI_ID menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    if (phb_pbapc_cntx_p->list_type == 0)
    {
        menu_gid = cui_menu_create(
                               GRP_ID_PHB_PBAPC_VIEW_CONTACT,
                               CUI_MENU_SRC_TYPE_RESOURCE,
                               CUI_MENU_TYPE_OPTION,
                               MENU_ID_PHB_PBAPC_ENTRY_VIEW_OPTIONS,
                               MMI_FALSE,
                               NULL);
     

        cui_menu_set_default_title_image(menu_gid, (UI_image_type)GetImage(IMG_SCR_PBOOK_CAPTION));

        //if(mmi_bt_is_call_supported())
        if (MMI_TRUE)
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_PBAPC_VIEW_CONTACT_DIAL, MMI_FALSE);
        }
        else
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_PBAPC_VIEW_CONTACT_DIAL, MMI_TRUE);
        }
    #ifdef __MMI_BTD_BOX_UI_STYLE__
        if(!srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION))
        {
            cui_menu_set_item_disabled(menu_gid, MENU_ID_PHB_PBAPC_VIEW_CONTACT_DIAL, MMI_TRUE);
        }
        else
        {
            cui_menu_set_item_disabled(menu_gid, MENU_ID_PHB_PBAPC_VIEW_CONTACT_DIAL, MMI_FALSE);
        }
    #endif /* __MMI_BTD_BOX_UI_STYLE__ */
        //if(mmi_bt_is_message_access_profile_supported())
        #ifndef __MMI_BTD_BOX_UI_STYLE__
        if (MMI_TRUE)
	#else /*__MMI_BTD_BOX_UI_STYLE__*/
	if (MMI_FALSE)
	#endif /*__MMI_BTD_BOX_UI_STYLE__*/
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_PBAPC_VIEW_CONTACT_SEND_SMS, MMI_FALSE);
        }
        else
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_PBAPC_VIEW_CONTACT_SEND_SMS, MMI_TRUE);
        }

    #if defined(__MMI_WEARABLE_DEVICE__)
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_PBAPC_VIEW_CONTACT_SEND_SMS, MMI_TRUE);
    #endif

    #ifdef __MMI_TELEPHONY_SUPPORT__
        // save bt contact to local
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_PBAPC_VIEW_CONTACT_SAVE, MMI_FALSE);
    #else
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_PBAPC_VIEW_CONTACT_SAVE, MMI_TRUE);
    #endif /* __MMI_TELEPHONY_SUPPORT__ */

        cui_menu_set_default_title_image_by_id(menu_gid, IMG_SCR_PBOOK_CAPTION);

        cui_menu_run(menu_gid);
    }
    else if (phb_pbapc_cntx_p->list_type == 1)
    {
        //cui_phb_pbapc_bt_send_select_result(&phb_pbapc_cntx_p->pse_phb, 0);
        cui_phb_pbapc_bt_send_select_result(&phb_pbapc_cntx_p->cui_pse_phb, 0);

        mmi_frm_group_close(GRP_ID_PHB_PBAPC_VIEW_CONTACT);
    }
}


static MMI_BOOL mmi_phb_pbapc_set_pse_view_flags(S32 index, U32* flag, U32* flag_ex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    if (index % 2 == 0)
    {
        *flag |= UI_MENUITEM_STATE_DISABLED;
    }

    if (phb_pbapc_cntx_p->list_type == 1 && index == 1)
    {
        /* don't show view page, just select number */
        //*flag |= UI_MENUITEM_STATE_DISABLED;
    }

    return MMI_TRUE;
}


static void  mmi_phb_pbapc_view_contact_op_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    mmi_sms_write_msg_para_struct op_msg_req;
    S32 index = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    /* 1. need chose number */
    if (phb_pbapc_cntx_p->hlight_index == 0 && // hlight name field
        phb_pbapc_cntx_p->pse_phb.num_count > 1)
    {
        phb_pbapc_cntx_p->op_type = 0;
        mmi_phb_pbapc_select_op_number(GRP_ID_PHB_PBAPC_VIEW_CONTACT, mmi_phb_pbapc_view_sel_num_cb, 
                                (void *)0xbabe0a, &(phb_pbapc_cntx_p->pse_phb));
    }
    else
    {
        if (phb_pbapc_cntx_p->hlight_index == 0 ||
            phb_pbapc_cntx_p->pse_phb.num_count == 1)
        {
            index = 0;
        }
        else
        {
            index = phb_pbapc_cntx_p->hlight_index - 1;
        }

        memset(&op_msg_req, 0x00, sizeof(mmi_sms_write_msg_para_struct));
        op_msg_req.ascii_addr = (U8 *)srv_phb_mem_malloc(sizeof(U8) * (MMI_PHB_NUMBER_LENGTH + 1) ,SRV_PHB_MEMORY_TYPE_CTR); 
        memset(op_msg_req.ascii_addr, 0x00, sizeof(U8) * (MMI_PHB_NUMBER_LENGTH + 1));
        mmi_wcs_n_to_asc((CHAR *) op_msg_req.ascii_addr, (WCHAR *) (phb_pbapc_cntx_p->pse_phb.num[index].number), MMI_PHB_NUMBER_LENGTH * ENCODING_LENGTH);
        op_msg_req.ascii_addr[MMI_PHB_NUMBER_LENGTH] = '\0';
        op_msg_req.flag = MMI_SMS_ENTRY_WRITE_REPLY;
        kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_view_contact_op_msg(num)--number: %s\n",
                    op_msg_req.ascii_addr);

        mmi_sms_write_msg_lanch(GRP_ID_PHB_PBAPC_VIEW_CONTACT, &op_msg_req);
        srv_phb_mem_free(op_msg_req.ascii_addr);
    }
}


static void  mmi_phb_pbapc_save_pse_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    mmi_ret gid = GRP_ID_INVALID;
    S32 index = -1;
    mmi_phb_pbapc_phb_info_struct *phb_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    phb_info = &(phb_pbapc_cntx_p->pse_phb);

    gid = cui_phb_save_contact_create(GRP_ID_PHB_PBAPC_VIEW_CONTACT);

    cui_phb_save_contact_set_name(gid, phb_info->name, NULL);

    index = 0; // always sel the 1st number
    if (phb_pbapc_cntx_p->pse_phb.num_count >= 1)
    {
        //gid = cui_phb_save_contact_create(GRP_ID_PHB_PBAPC_VIEW_CONTACT);

        //cui_phb_save_contact_set_name(gid, phb_info->name, NULL);

        cui_phb_save_contact_set_number(gid, phb_info->num[index].number);

        cui_phb_save_contact_set_phb_info(gid, phb_info);

        //cui_phb_save_contact_run(gid);
    }

    cui_phb_save_contact_run(gid);

    //kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_save_pse_contact--gid: %d, num_count: %d\n",
    //        gid, phb_info->num_count);

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_PBAPC_SAVE_PSE_CONTACT, gid, phb_info->num_count);
}


static void  mmi_phb_pbapc_view_contact_op_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    S32 index = -1;
    mmi_ucm_make_call_para_struct call_para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    /* 1. need chose number */
    if (phb_pbapc_cntx_p->hlight_index == 0 && // hlight name field
        phb_pbapc_cntx_p->pse_phb.num_count > 1)
    {
        phb_pbapc_cntx_p->op_type = 1;
        mmi_phb_pbapc_select_op_number(GRP_ID_PHB_PBAPC_VIEW_CONTACT, mmi_phb_pbapc_view_sel_num_cb, 
                                (void *)0xbabe0b, &(phb_pbapc_cntx_p->pse_phb));
    }
    else
    {
        if (phb_pbapc_cntx_p->hlight_index == 0 ||
            phb_pbapc_cntx_p->pse_phb.num_count == 1)
        {
            index = 0;
        }
        else
        {
            index = phb_pbapc_cntx_p->hlight_index - 1;
        }

        mmi_ucm_init_call_para(&call_para);

        call_para.ucs2_num_uri = phb_pbapc_cntx_p->pse_phb.num[index].number;
        call_para.adv_para.after_callback_user_data = NULL;
        call_para.adv_para.after_make_call_callback = NULL;
        call_para.adv_para.highlight_dial_type = SRV_UCM_INVALID_CALL_TYPE;
        call_para.adv_para.is_ip_dial = MMI_FALSE;
        call_para.adv_para.module_id = SRV_UCM_MODULE_ORIGIN_COMMON;
        call_para.adv_para.phb_data = NULL;
        mmi_ucm_call_launch(0, &call_para);
    }
}


static S32 mmi_phb_pbapc_view_sel_num_cb(mmi_phb_pbapc_cb_info_struct *cb_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    S32 index = -1;
    mmi_ucm_make_call_para_struct call_para;
    mmi_sms_write_msg_para_struct op_msg_req;
    mmi_phb_pbapc_sel_num_rsp_struct *sel_num_rsp;
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    sel_num_rsp = (mmi_phb_pbapc_sel_num_rsp_struct *) (cb_info->type_rsp);

    if (sel_num_rsp->ret == 0)
    {
        index = sel_num_rsp->sel_index;
        if (phb_pbapc_cntx_p->op_type == 0) // msg
        {
            memset(&op_msg_req, 0x00, sizeof(mmi_sms_write_msg_para_struct));
            op_msg_req.ascii_addr = (U8 *)srv_phb_mem_malloc(sizeof(U8) * (MMI_PHB_NUMBER_LENGTH + 1) ,SRV_PHB_MEMORY_TYPE_CTR); 
            memset(op_msg_req.ascii_addr, 0x00, sizeof(U8) * (MMI_PHB_NUMBER_LENGTH + 1));
            mmi_wcs_n_to_asc((CHAR *) op_msg_req.ascii_addr, (WCHAR *) (phb_pbapc_cntx_p->pse_phb.num[index].number), MMI_PHB_NUMBER_LENGTH * ENCODING_LENGTH);
            op_msg_req.ascii_addr[MMI_PHB_NUMBER_LENGTH] = '\0';
            op_msg_req.flag = MMI_SMS_ENTRY_WRITE_REPLY;
            kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_view_sel_num_cb(num)--number: %s\n",
                        op_msg_req.ascii_addr);

            mmi_sms_write_msg_lanch(GRP_ID_PHB_PBAPC_VIEW_CONTACT, &op_msg_req);
            srv_phb_mem_free(op_msg_req.ascii_addr);
        }
        else if (phb_pbapc_cntx_p->op_type == 1) // call
        {
            mmi_ucm_init_call_para(&call_para);

            call_para.ucs2_num_uri = phb_pbapc_cntx_p->pse_phb.num[index].number;
            call_para.adv_para.after_callback_user_data = NULL;
            call_para.adv_para.after_make_call_callback = NULL;
            call_para.adv_para.highlight_dial_type = SRV_UCM_INVALID_CALL_TYPE;
            call_para.adv_para.is_ip_dial = MMI_FALSE;
            call_para.adv_para.module_id = SRV_UCM_MODULE_ORIGIN_COMMON;
            call_para.adv_para.phb_data = NULL;
            mmi_ucm_call_launch(0, &call_para);
        }
        else
        {
            ;
        }
    }

    return ret;
}


static U16 mmi_phb_pbapc_get_num_type(U8 num_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (num_type)
    {
        case VCARD_TEL_TYPE_CELL:
            str_id = STR_ID_PHB_MOBILE_NUMBER;
            break;

        case VCARD_TEL_TYPE_HOME:
            str_id = STR_HOME_NUMBER;
            break;

        case VCARD_TEL_TYPE_WORK:
            str_id = STR_OFFICE_NUMBER;
            break;

        case VCARD_TEL_TYPE_FAX:
            str_id = STR_FAX_NUMBER;
            break;

        default:
            str_id = STR_ID_PHB_NUMBER;
            break;
    }

    return str_id;
}


static void mmi_phb_pbapc_read_pse_entry(U16 entry_index, srv_phb_pbap_storage_enum storage,
                                void *user_data, mmi_phb_pbapc_cb_func cb_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = -1;
    srv_phb_pbapc_read_entry_req_struct entry_req;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    phb_pbapc_cntx_p->job_type = 1;

    phb_pbapc_cntx_p->cb_func = cb_func;
    phb_pbapc_cntx_p->user_data = user_data;

    if (phb_pbapc_cntx_p->pbapc_handle)
    {
        ret = SRV_PHB_PBAPC_RET_OK;
    }
    else
    {
        phb_pbapc_cntx_p->pbapc_handle = srv_phb_pbapc_create_handle(&ret);
    }

    if (ret == SRV_PHB_PBAPC_RET_OK)
    {
        /* Req head */
        entry_req.handle = phb_pbapc_cntx_p->pbapc_handle;
        entry_req.storage = storage;
        entry_req.user_data = (void *)0xbabebabe;

        entry_req.entry_index = entry_index;
        entry_req.vcard_format = SRV_PHB_PBAP_VCARD_FORMAT_21;
        entry_req.vcard_filter = SRV_PHB_PBAP_VCARD_FILTER_N | SRV_PHB_PBAP_VCARD_FILTER_FN | SRV_PHB_PBAP_VCARD_FILTER_TEL;

        ret = srv_phb_pbapc_read_pse_entry(&entry_req, mmi_phb_pbapc_read_pse_entry_hdlr);
    }

    if (ret != SRV_PHB_PBAPC_RET_OK)
    {
        mmi_phb_pbapc_cb_info_struct cb_info;
        srv_phb_pbapc_read_entry_rsp_struct entry_rsp;

        mmi_phb_pbapc_show_loading_abort(GRP_ID_PHB_PBAPC_VIEW_CONTACT, SCR_ID_PHB_PROCESSING);
        mmi_popup_display_simple_ext(STR_GLOBAL_FAILED, MMI_EVENT_FAILURE, GRP_ID_PHB_PBAPC_VIEW_CONTACT, NULL);

        entry_rsp.ret = -1;
        cb_info.cb_type = 0;
        cb_info.type_rsp = (void *) &entry_rsp;
        cb_info.user_data = phb_pbapc_cntx_p->user_data;
        phb_pbapc_cntx_p->cb_func(&cb_info);

        if (phb_pbapc_cntx_p->pbapc_handle != NULL)
        {
            srv_phb_pbapc_destory_handle(phb_pbapc_cntx_p->pbapc_handle);
            phb_pbapc_cntx_p->pbapc_handle = NULL;
        }
    }
}


static S32 mmi_phb_pbapc_read_pse_entry_hdlr(srv_phb_pbapc_read_entry_rsp_struct *entry_rsp, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    mmi_phb_pbapc_cb_info_struct cb_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    cb_info.cb_type = 0;
    cb_info.type_rsp = (void *) entry_rsp;
    cb_info.user_data = phb_pbapc_cntx_p->user_data;

    if (phb_pbapc_cntx_p->pbapc_handle != NULL)
    {
        srv_phb_pbapc_destory_handle(phb_pbapc_cntx_p->pbapc_handle);
        phb_pbapc_cntx_p->pbapc_handle = NULL;
    }

    phb_pbapc_cntx_p->cb_func(&cb_info);

    return ret;
}


static mmi_ret mmi_phb_pbapc_view_pse_contact_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret menu_cui_proc = MMI_RET_DONT_CARE;
    cui_phb_save_contact_result_struct *save_evt = NULL;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    menu_cui_proc = mmi_phb_pbapc_menu_cui_proc(evt);
 
    if (menu_cui_proc == MMI_RET_OK)
    {
        return MMI_RET_OK;
    }

    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_FIRST_ENTRY:
            break;
            
        case EVT_ID_GROUP_INACTIVE:
        {
            if (mmi_frm_scrn_get_count(GRP_ID_PHB_PBAPC_VIEW_CONTACT) == 0)
            {
                //mmi_frm_group_close(GRP_ID_PHB_PBAPC_VIEW_CONTACT);
            }
            break;
        }
        case EVT_ID_GROUP_ACTIVE:
             break;
            
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
             break;

        case EVT_ID_GROUP_DEINIT:
        {
            if (phb_pbapc_cntx_p->pbapc_handle != NULL)
            {
                srv_phb_pbapc_destory_handle(phb_pbapc_cntx_p->pbapc_handle);
                phb_pbapc_cntx_p->pbapc_handle = NULL;
            }
            break;
        }

        case EVT_ID_GROUP_FOCUSED:
        case EVT_ID_GROUP_REDRAW_START:
            break;

        case EVT_ID_PHB_SAVE_CONTACT:
        case EVT_ID_PHB_SAVE_CONTACT_CANCEL:
        {
            save_evt = (cui_phb_save_contact_result_struct *) evt;

            //kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_view_pse_contact_proc(save contact)--evt->id: %d, ret: %d, sender_id\n",
            //                                                                evt->evt_id, save_evt->result, save_evt->sender_id);

            MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_PBAPC_VIEW_PSE_CONTACT_PROC, evt->evt_id, save_evt->result, save_evt->sender_id);

            cui_phb_save_contact_close(save_evt->sender_id);
            
            break;
        }

        default:
            break;
    }

    return MMI_RET_OK;
}


void mmi_phb_pbapc_select_op_number(mmi_id parent_id, mmi_phb_pbapc_cb_func sel_cb_func,
                        void *user_data, mmi_phb_pbapc_phb_info_struct *phb_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    phb_pbapc_cntx_p->sel_num_pid = parent_id;
    phb_pbapc_cntx_p->sel_cb_func = sel_cb_func;
    phb_pbapc_cntx_p->sel_num_ud = user_data;
    memcpy(&(phb_pbapc_cntx_p->sel_phb_info), phb_info, sizeof(mmi_phb_pbapc_phb_info_struct));

    mmi_frm_scrn_create(parent_id, SCR_ID_PHB_PBAPC_SEL_OP_NUM, mmi_phb_pbapc_select_op_number_proc, NULL);
}


static MMI_RET mmi_phb_pbapc_select_op_number_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_phb_pbapc_show_select_number();
            break;
        }

        default:
         break;
    }

    return MMI_RET_OK;
}


static void mmi_phb_pbapc_show_select_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    CHAR *item_list[MAX_PHB_PBAPC_MAX_FIELDS * 2]; 
    S32 highlight_item = 0;
    U8 *gui_buffer = NULL;
    mmi_phb_pbapc_phb_info_struct *phb_info = NULL;
    S32 i = 0, k = 0;
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    phb_info = &(phb_pbapc_cntx_p->sel_phb_info);

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    RegisterHighlightHandler(mmi_phb_pbapc_select_number_hlight_hdlr);

    wgui_fixed_list_register_get_flags_handler(mmi_phb_pbapc_set_pse_view_flags);

    for (i = 0, k = 0; i < phb_info->num_count; ++i)
    {
        str_id = mmi_phb_pbapc_get_num_type(phb_info->num[i].type);
        item_list[k] = GetString(str_id);
        item_list[k + 1] = (CHAR *)(phb_info->num[i].number);
        k += 2;
    }

    if (gui_buffer)
    {
        highlight_item = (phb_pbapc_cntx_p->sel_hlight_index << 1) + 1 ;
    }
    else
    {
        highlight_item = 1;
    }

    ShowCategory84Screen(
                STR_GLOBAL_SELECT,
                GetRootTitleIcon(MAIN_MENU_PHONEBOOK_MENUID),
                0,
                0,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                phb_info->num_count * 2,
                (U8 **) item_list,
                NULL,
                WGUI_CATE_ITEM_DISABLE_WITHOUT_CHANGE_TEXT_COLOR,
                highlight_item,
                gui_buffer);
}


static void mmi_phb_pbapc_select_number_hlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    phb_pbapc_cntx_p->sel_hlight_index = index >> 1;

   
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(mmi_phb_pbapc_select_num_cancel, KEY_EVENT_UP);

    ChangeLeftSoftkey(STR_GLOBAL_SELECT, IMG_GLOBAL_OK); 
    SetLeftSoftkeyFunction(mmi_phb_pbapc_select_num_ok, KEY_EVENT_UP);

    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_phb_pbapc_select_num_ok, KEY_EVENT_UP);

    if (phb_pbapc_cntx_p->list_type == 0)
    {
        SetKeyHandler(mmi_phb_pbapc_select_num_ok, KEY_SEND, KEY_EVENT_UP);
    }
}


static void mmi_phb_pbapc_select_num_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_select_num_done(0);
}


static void mmi_phb_pbapc_select_num_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_select_num_done(-1);
}


static void mmi_phb_pbapc_select_num_done(S32 ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    mmi_phb_pbapc_sel_num_rsp_struct sel_num_rsp;
    mmi_phb_pbapc_cb_info_struct cb_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    sel_num_rsp.ret = ret;
    sel_num_rsp.sel_index = phb_pbapc_cntx_p->sel_hlight_index;

    cb_info.cb_type = 1;
    cb_info.type_rsp = (void *)&sel_num_rsp;
    cb_info.user_data = phb_pbapc_cntx_p->sel_num_ud;
    phb_pbapc_cntx_p->sel_cb_func(&cb_info);

    mmi_frm_scrn_close(phb_pbapc_cntx_p->sel_num_pid, SCR_ID_PHB_PBAPC_SEL_OP_NUM);
}


static S32 mmi_phb_pbapc_parse_single_vcard_file(U16 *path, mmi_phb_pbapc_phb_info_struct *pse_phb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VP_HANDLE vp = NULL;
    vcard_object_struct *object_p;
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vp = vcard_open_parser(path, VCARD_PROPERTY_N | VCARD_PROPERTY_NICKNAME | VCARD_PROPERTY_TEL, &ret);
    if (vp)
    {
        ret = vcard_parse(vp, &object_p);

        if (ret == VCARD_RESULT_OK)
        {
            mmi_phb_pbapc_convert_vobject_to_phb(object_p, pse_phb);
        }
        vcard_close_parser(vp);
    }

    //kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_parse_single_vcard_file--ret: %d\n", ret);

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_PBAPC_PARSE_VCARD, ret);

    return ret;
}


static S32 mmi_phb_pbapc_convert_vobject_to_phb(vcard_object_struct *vcard_object, mmi_phb_pbapc_phb_info_struct *pse_phb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, index = 0, ret = 0;
    U32 field_mask = 0;
    U16 temp_name[MMI_PHB_NAME_FIELD_LENGTH + 1] = {L'\0'};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(pse_phb, 0x00, sizeof(mmi_phb_pbapc_phb_info_struct));

    if (vcard_object->n.mid && vcard_object->n.mid[0])
    {
        srv_phb_remove_invalid_name(vcard_object->n.family);
        srv_phb_remove_invalid_name(vcard_object->n.mid);
        srv_phb_remove_invalid_name(vcard_object->n.given);

        mmi_wcsncpy((WCHAR *)temp_name, vcard_object->n.mid, MMI_PHB_NAME_FIELD_LENGTH);
        mmi_wcsncat((WCHAR *)(temp_name + mmi_wcslen(temp_name)), vcard_object->n.given, MMI_PHB_NAME_FIELD_LENGTH - mmi_wcslen(temp_name));

        srv_phb_convert_to_name(
                pse_phb->name,
                temp_name,
                vcard_object->n.family,
                MMI_PHB_NAME_FIELD_LENGTH);
    }
    else
    {
        srv_phb_remove_invalid_name(vcard_object->n.family);
        srv_phb_remove_invalid_name(vcard_object->n.given);
        srv_phb_convert_to_name(
                        pse_phb->name,
                        vcard_object->n.given,
                        vcard_object->n.family,
                        MMI_PHB_NAME_FIELD_LENGTH);
    }
    if (pse_phb->name[0])
    {
        field_mask |= 0x01;
    }

    for (i = 0; i < 4; ++i)
    {
        if (vcard_object->tel[i].tel && vcard_object->tel[i].tel[0])
        {
            mmi_phb_pbapc_remove_sp_char(vcard_object->tel[i].tel);

            if (srv_phb_check_valid_number(vcard_object->tel[i].tel))
            {
                srv_phb_remove_invalid_number(vcard_object->tel[i].tel);

                index = pse_phb->num_count;
                mmi_wcsncpy(pse_phb->num[index].number, vcard_object->tel[i].tel, MMI_PHB_NUMBER_LENGTH);
                pse_phb->num[index].type = vcard_object->tel[i].type;

                ++pse_phb->num_count;
            }
        }
    }

    //kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_convert_vobject_to_phb--ret: %d, num_count: %d, field_mask: 0x%x\n",
    //            ret, pse_phb->num_count, field_mask);

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_PBAPC_CONVERT_VOBJECT_TO_PHB, ret, pse_phb->num_count, field_mask);

    return ret;
}


static S32 mmi_phb_pbapc_remove_sp_char(U16 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len = 0, i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_PHB_NUMBER_LENGTH && number[i] != L'\0'; ++i)
    {
        if (number[i] == L'-') // filter char '-'
        {
            continue;
        }

        if (number[i] == L' ') // filter space
        {
            continue;
        }
        number[len++] = number[i];
    }
    number[len] = L'\0';

    return len;
}


void mmi_phb_pbapc_set_list_type(U8 list_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    phb_pbapc_cntx_p->list_type = list_type;
    if (list_type == 0)
    {
        phb_pbapc_cntx_p->qsearch_input_buffer = phb_pbapc_cntx_p->phb_input_buffer;
    }
    else if (list_type == 1)
    {
        phb_pbapc_cntx_p->qsearch_input_buffer = phb_pbapc_cntx_p->cui_input_buffer;
    }
    else
    {
        MMI_ASSERT(0);
    }
}


mmi_ret mmi_phb_pbapc_notify_evt_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_notify_evt_struct *notify_evt = NULL;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_notify_evt_hdlr--evt_id: %d, notify_evt: %d, flag: %d, state: %d\n",
                    evt->evt_id, EVT_ID_PHB_PBAPC_NOTIFY, phb_pbapc_cntx_p->flag, phb_pbapc_cntx_p->list_state);

    if (evt->evt_id == EVT_ID_PHB_PBAPC_NOTIFY)
    {
        if (phb_pbapc_cntx_p->flag == 1)
        {
            phb_pbapc_cntx_p->flag = 0;
            mmi_phb_pbapc_read_pse_list();
        }
    }
    else if (evt->evt_id == EVT_ID_DIALER_DISCONN_EVENT_ID ||
			 evt->evt_id == EVT_ID_DIALER_CONN_EVENT_ID)
    {
        /* reset hlight tab */
        phb_pbapc_cntx_p->phb_list = 0;
        phb_pbapc_cntx_p->cui_list = 0;
    }
    else if (evt->evt_id == EVT_ID_PBAP_NOTIFY)
    {
        if (phb_pbapc_cntx_p->list_state == 1)
        {
            mmi_frm_display_dummy_screen();
            mmi_frm_scrn_close_active_id();
        }
    }

    return MMI_RET_OK;
}


static void mmi_phb_pbapc_revise_string(U8 *str, U16 buf_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, k = 0, len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* filter ; */
    len = strlen(str);

    for(i = 0; i < len && i < buf_len; ++i)
    {
        if (str[i] != ';')
        {
            str[k++] = str[i];
        }
    }

    str[k] = '\0';
}


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_phb_pbapc_bt_list_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        mmi_phb_pbapc_pse_list_op_option();

        return;
    }
    else
    {
        return;
    }
}
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */


#define LOCAL_CUI_PHB_PBAPC_SELECT_CONTACT_API

/* select contact cui */
static mmi_ret cui_phb_pbapc_select_contact_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret menu_cui_proc;
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    menu_cui_proc = mmi_phb_pbapc_menu_cui_proc(evt);

    if (menu_cui_proc == MMI_RET_OK)
    {
        return MMI_RET_OK;
    }

    switch (evt->evt_id)
    {
        case EVT_ID_SCENAIO_CHANGE:
            break;

        case EVT_ID_GROUP_INACTIVE:
        {
            break;
        }

        case EVT_ID_GROUP_FIRST_ENTRY:
            break;

        case EVT_ID_GROUP_ACTIVE:
            break;

        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
            break;

        case EVT_ID_GROUP_DEINIT:
        {
            phb_pbapc_cntx_p->qsearch_input_buffer[0] = 0;

            if (phb_pbapc_cntx_p->pbapc_handle != NULL)
            {
                phb_pbapc_cntx_p->free_handle = 1;
            }

            // cancel release handle flag
            phb_pbapc_cntx_p->flag = 0;
            phb_pbapc_cntx_p->show_dummy = 0;
        }
            break;

        case EVT_ID_GROUP_FOCUSED:
        case EVT_ID_GROUP_REDRAW_START:
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


static void cui_phb_pbapc_select_contact_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TELEPHONY_SUPPORT__
    mmi_frm_tab_struct pbapc_tab_pages_info_array[2];
#endif
    U8 tab_index = 0;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_set_list_type(1);
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

#ifdef __MMI_TELEPHONY_SUPPORT__
    pbapc_tab_pages_info_array[0].screen_id = SCR_ID_PHB_PBAPC_LOCAL;
    pbapc_tab_pages_info_array[0].tab_entry_func = cui_phb_pbapc_select_contact_local_entry;

#ifdef __MMI_PHB_UI_IN_TABS__
    pbapc_tab_pages_info_array[0].tab_icon = (U8*)GetImage(IMG_ID_PHB_TAB_LIST);
    pbapc_tab_pages_info_array[0].tab_string = NULL;
#else
    pbapc_tab_pages_info_array[0].tab_icon = NULL;
    pbapc_tab_pages_info_array[0].tab_string = GetString(STR_ID_PHB_PBAPC_LOCAL);
#endif

    pbapc_tab_pages_info_array[1].screen_id = SCR_ID_PHB_PBAPC_BT;
    pbapc_tab_pages_info_array[1].tab_entry_func = cui_phb_pbapc_select_contact_bt_entry;

#ifdef __MMI_PHB_UI_IN_TABS__
    pbapc_tab_pages_info_array[1].tab_icon = (U8*)GetImage(IMG_ID_PHB_TAB_BT_LIST);
    pbapc_tab_pages_info_array[1].tab_string = NULL;
#else
    pbapc_tab_pages_info_array[1].tab_icon = NULL;
    pbapc_tab_pages_info_array[1].tab_string = GetString(STR_ID_PHB_PBAPC_BT);
#endif

    if(!srv_bt_cm_is_profile_connected(SRV_BT_CM_PBAPC_CONNECTION))
    {
        tab_index = 0; // disconnected hlight local
    }
    else
    {
        if (phb_pbapc_cntx_p->cui_list == 0)
        {
            tab_index = 1;
        }
        else if (phb_pbapc_cntx_p->cui_list == 1)
        {
            tab_index = 0;
        }
        else if (phb_pbapc_cntx_p->cui_list == 2)
        {
            tab_index = 1;
        }
    }

    //kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] cui_phb_pbapc_select_contact_entry--cui_list: %d, tab: %d, connect: %d\n",
    //                                                                phb_pbapc_cntx_p->cui_list, tab_index, srv_bt_cm_is_profile_connected(SRV_BT_CM_PBAPC_CONNECTION));

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_PBAPC_SELECT_CONTACT_ENTRY, phb_pbapc_cntx_p->cui_list,
                tab_index, srv_bt_cm_is_profile_connected(SRV_BT_CM_PBAPC_CONNECTION));
#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    cui_tab_create(
                GRP_ID_PHB_PBAPC_SELECT_CONTACT,
                SCR_ID_PHB_PBAPC_TAB,
                pbapc_tab_pages_info_array,
                2,
                tab_index,
                NULL);
#else
    mmi_frm_scrn_tab_enter(
                    GRP_ID_PHB_PBAPC_SELECT_CONTACT,
                    SCR_ID_PHB_PBAPC_TAB,
                    cui_phb_pbapc_select_contact_exit,
                    cui_phb_pbapc_select_contact_entry,
                    pbapc_tab_pages_info_array,
                    2,
                    tab_index);
#endif
#else
    mmi_phb_pbapc_entry_list();
#endif /* __MMI_TELEPHONY_SUPPORT__ */
}


static void cui_phb_pbapc_select_contact_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


static S32 mmi_phb_pbapc_local_find_entry(U8 *keyword)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 key_length;
    S32 result_count;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    srv_phb_filter_struct filter;
    srv_phb_qsearch_filter_struct qsearch_filter;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Count the input string length to decide behavior */
    key_length = (U8) mmi_ucs2strlen((CHAR*) keyword);
    
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    phb_pbapc_cntx_p->local_contact_hlight_index = 0;

    filter.storage = PHB_STORAGE_MAX;
    filter.field_filter = SRV_PHB_ENTRY_FIELD_GSM_NUM;
    filter.name_filter = NULL;
    filter.qsearch_filter = NULL;
    filter.group_filter = NULL;

    if (key_length > 0)
    {
        qsearch_filter.key_len = key_length;
        qsearch_filter.key_word = (U16*)keyword;
        qsearch_filter.input_mode = (U16)mmi_imm_get_curr_input_mode();
        filter.qsearch_filter = &qsearch_filter;
    }

    phb_pbapc_cntx_p->local_contact_count = (U16) srv_phb_oplib_build_contact_list(&filter, phb_pbapc_cntx_p->local_contact_id, MMI_PHB_ENTRIES);
    result_count = phb_pbapc_cntx_p->local_contact_count;

    if (result_count == 0)
    {
        SetKeyHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }

    return result_count;
}


static void cui_phb_pbapc_local_show_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    U8 *gui_buffer = NULL;
    S32 has_lsk = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    if (gui_buffer == NULL)
    {
        phb_pbapc_cntx_p->local_contact_hlight_index = 0;
        phb_pbapc_cntx_p->local_qsearch_input_buffer[0] = 0;
    }

    if (phb_pbapc_cntx_p->local_contact_count)
    {
        has_lsk = MMI_TRUE;
    }

    RegisterHighlightHandler(cui_phb_pbapc_local_list_highlight_hdlr);

#ifndef __MMI_PHB_QUICK_SEARCH__
    wgui_cat1032_show(
            (WCHAR*) GetString(STR_SCR_PBOOK_VIEW_CAPTION),
            (PU8) GetImage(IMG_SCR_PBOOK_CAPTION),
            //(WCHAR*) GetString(STR_GLOBAL_OK),
            //(PU8) GetImage(IMG_GLOBAL_OK),
            has_lsk ?(WCHAR*) GetString(STR_GLOBAL_OK) : NULL,
            has_lsk ?(PU8) GetImage(IMG_GLOBAL_OK) : NULL,
            (WCHAR*) GetString(STR_GLOBAL_BACK),
            (PU8) GetImage(IMG_GLOBAL_BACK),
            phb_pbapc_cntx_p->local_contact_count,
            cui_phb_pbapc_local_get_get_item,
            NULL,
            phb_pbapc_cntx_p->local_contact_hlight_index,
            0,
            IMG_STORAGE_SIM,
            IMG_GLOBAL_SIM1,
            gui_buffer,
            NULL);
    SetRightSoftkeyFunction(cui_phb_pbapc_local_list_option_back, KEY_EVENT_UP);
#else
    RegisterCat200SearchFunction(mmi_phb_pbapc_local_find_entry);
    wgui_cat_set_search_icon(IMG_ID_PHB_QUICK_SEARCH_FIND);
    ShowCategory199Screen_ext(
        has_lsk ?(UI_string_type)GetString(STR_GLOBAL_OK) : NULL,
        has_lsk ?(PU8)GetImage(IMG_GLOBAL_OK) : NULL,
        (UI_string_type)GetString(STR_GLOBAL_BACK),
        (PU8)GetImage(IMG_GLOBAL_BACK),
        0,        
        (UI_string_type)GetString(STR_SCR_PBOOK_VIEW_CAPTION),
        NULL,
        phb_pbapc_cntx_p->local_contact_count,
        cui_phb_pbapc_local_get_get_item,
        NULL,
        NULL,
        NULL,
        phb_pbapc_cntx_p->local_contact_hlight_index,
        get_image(IMG_GLOBAL_L1),
        get_image(IMG_STORAGE_SIM),
        (U8*) phb_pbapc_cntx_p->local_qsearch_input_buffer,
        MMI_PHB_QUICK_SEARCH_INPUT_LENGTH,
        gui_buffer);
    SetCategory200RightSoftkeyFunction(cui_phb_pbapc_local_list_option_back, KEY_EVENT_UP);
#endif

    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
}


static S32 cui_phb_pbapc_local_get_get_item(S32 start_index, gui_iconlist_menu_item *menu_data, S32 num_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < num_items; i++)
    {
        cui_phb_pbapc_local_get_get_item_int((i + start_index), menu_data[i].item_list[0], &menu_data[i].image_list[0], &menu_data[i].image_list[1]);
    }

    return num_items;
}


static pBOOL cui_phb_pbapc_local_get_get_item_int(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p1, PU8 *img_buff_p2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    U16 contact_id = SRV_PHB_INVALID_INDEX;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    contact_id = phb_pbapc_cntx_p->local_contact_id[item_index];

    srv_phb_get_name(contact_id, str_buff, 2 * MMI_PHB_NAME_FIELD_LENGTH + 1);

    if (str_buff[0] == 0)
    {
        mmi_ucs2ncpy((CHAR*) str_buff, GetString(STR_ID_PHB_UNNAMED), MAX_SUBMENU_CHARACTERS);
    }

    mmi_phb_contact_get_item_image(contact_id, img_buff_p1, img_buff_p2);

    return TRUE;
}


static void cui_phb_pbapc_local_list_highlight_hdlr(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    U16 *local_contact_id = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    local_contact_id = phb_pbapc_cntx_p->local_contact_id;

    phb_pbapc_cntx_p->local_contact_hlight_index = item_index;

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(cui_phb_pbapc_local_list_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(cui_phb_pbapc_local_list_option_back, KEY_EVENT_UP);

    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(cui_phb_pbapc_local_list_option, KEY_EVENT_UP);

#ifdef __MMI_PHB_QUICK_SEARCH__
    SetKeyHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif
}


static void cui_phb_pbapc_local_list_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    cui_phb_pbapc_select_contact_rsp_struct sel_rsp;
    cui_phb_pbapc_select_contact_ret_struct sel_ret;
    mmi_phb_contact_id contact_id;
    U32 field_mask = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    contact_id = phb_pbapc_cntx_p->local_contact_id[phb_pbapc_cntx_p->local_contact_hlight_index];

    memset(&sel_ret, 0x00, sizeof(cui_phb_pbapc_select_contact_ret_struct));

    MMI_FRM_INIT_EVENT(&sel_rsp, EVT_ID_PHB_PBAPC_SEL_CONTACT);

    sel_rsp.sender_id = GRP_ID_PHB_PBAPC_SELECT_CONTACT;
    sel_rsp.cb_user_data = phb_pbapc_cntx_p->cui_sel_contact_ud;
    sel_rsp.rsp_type = MMI_PHB_PBAPC_SEL_RESULT;
    sel_rsp.rsp = (void *)&sel_ret;

    /* sel ok result */
    sel_ret.ret = MMI_PHB_PBAPC_SEL_RET_OK;
    sel_ret.contact_type = MMI_PHB_PBAPC_CONTACT_LOCAL;
    sel_ret.contact_id = contact_id;
    sel_ret.sub_id = 0;

    srv_phb_get_name(contact_id, sel_ret.name, MMI_PHB_PBAPC_MAX_NAME_LEN);
    sel_ret.name[MMI_PHB_PBAPC_MAX_NAME_LEN] = L'\0';
    srv_phb_get_number(contact_id, sel_ret.number, MMI_PHB_PBAPC_MAX_NUM_LEN);
    sel_ret.number[MMI_PHB_PBAPC_MAX_NUM_LEN] = L'\0';

    field_mask = 0;
    if (sel_ret.name[0])
    {
        field_mask |= 0x01;
    }
    
    if (sel_ret.number[0])
    {
        field_mask |= 0x02;
    }

    //kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] cui_phb_pbapc_local_list_option--pid: %d, 0x%x\n",
    //                                                                phb_pbapc_cntx_p->cui_sel_contact_pid, field_mask);

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_PBAPC_LOCAL_LIST_OPTION, phb_pbapc_cntx_p->cui_sel_contact_pid, field_mask);

    cui_phb_send_data_to_sa(GRP_ID_PHB_PBAPC_SELECT_CONTACT, &sel_rsp);

    cui_phb_pbapc_select_contact_send_req_close();
}


static void cui_phb_pbapc_local_list_option_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    cui_phb_pbapc_select_contact_rsp_struct sel_rsp;
    cui_phb_pbapc_select_contact_ret_struct sel_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    memset(&sel_ret, 0x00, sizeof(cui_phb_pbapc_select_contact_ret_struct));

    MMI_FRM_INIT_EVENT(&sel_rsp, EVT_ID_PHB_PBAPC_SEL_CONTACT);

    sel_rsp.sender_id = GRP_ID_PHB_PBAPC_SELECT_CONTACT;
    sel_rsp.cb_user_data = phb_pbapc_cntx_p->cui_sel_contact_ud;
    sel_rsp.rsp_type = MMI_PHB_PBAPC_SEL_RESULT;
    sel_rsp.rsp = (void *)&sel_ret;

    /* sel ok cancle */
    sel_ret.ret = MMI_PHB_PBAPC_SEL_RET_CANCEL;

    //kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] cui_phb_pbapc_local_list_option_back--pid: %d\n",
    //                                                                phb_pbapc_cntx_p->cui_sel_contact_pid);

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_PBAPC_LOCAL_LIST_OPTION_BACK, phb_pbapc_cntx_p->cui_sel_contact_pid);

    cui_phb_send_data_to_sa(GRP_ID_PHB_PBAPC_SELECT_CONTACT, &sel_rsp);

    cui_phb_pbapc_select_contact_send_req_close();
}


static void cui_phb_pbapc_select_contact_send_req_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    cui_phb_pbapc_select_contact_rsp_struct sel_rsp;
    cui_phb_pbapc_select_contact_req_close_struct req_close;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    memset(&req_close, 0x00, sizeof(cui_phb_pbapc_select_contact_req_close_struct));

    MMI_FRM_INIT_EVENT(&sel_rsp, EVT_ID_PHB_PBAPC_SEL_CONTACT);

    sel_rsp.sender_id = GRP_ID_PHB_PBAPC_SELECT_CONTACT;
    sel_rsp.cb_user_data = phb_pbapc_cntx_p->cui_sel_contact_ud;
    sel_rsp.rsp_type = MMI_PHB_PBAPC_SEL_REQ_CLOSE;
    sel_rsp.rsp = (void *)&req_close;

    req_close.ret = MMI_PHB_PBAPC_SEL_RET_OK;

    //kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] cui_phb_pbapc_select_contact_send_req_close--pid: %d\n",
    //                                                                phb_pbapc_cntx_p->cui_sel_contact_pid);

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_PBAPC_SEL_SEND_REQ_CLOSE, phb_pbapc_cntx_p->cui_sel_contact_pid);

    cui_phb_send_data_to_sa(GRP_ID_PHB_PBAPC_SELECT_CONTACT, &sel_rsp);
}


static void cui_phb_pbapc_bt_send_select_result(mmi_phb_pbapc_phb_info_struct *pse_phb, S32 ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    cui_phb_pbapc_select_contact_rsp_struct sel_rsp;
    cui_phb_pbapc_select_contact_ret_struct sel_ret;
    S32 index = 0;
    U32 field_mask = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    memset(&sel_ret, 0x00, sizeof(cui_phb_pbapc_select_contact_ret_struct));

    MMI_FRM_INIT_EVENT(&sel_rsp, EVT_ID_PHB_PBAPC_SEL_CONTACT);

    sel_rsp.sender_id = GRP_ID_PHB_PBAPC_SELECT_CONTACT;
    sel_rsp.cb_user_data = phb_pbapc_cntx_p->cui_sel_contact_ud;
    sel_rsp.rsp_type = MMI_PHB_PBAPC_SEL_RESULT;
    sel_rsp.rsp = (void *)&sel_ret;

    if (ret == 0)
    {
        index = phb_pbapc_cntx_p->hlight_index - 1;

        /* sel ok result */
        sel_ret.ret = MMI_PHB_PBAPC_SEL_RET_OK;
        sel_ret.contact_type = MMI_PHB_PBAPC_CONTACT_BT;
        sel_ret.entry_index = phb_pbapc_cntx_p->cui_pse_entry_index;
        sel_ret.storage = phb_pbapc_cntx_p->cui_contact_storage;
        sel_ret.num_type = pse_phb->num[index].type;

        mmi_wcsncpy(sel_ret.name, pse_phb->name, MMI_PHB_PBAPC_MAX_NAME_LEN);
        sel_ret.name[MMI_PHB_PBAPC_MAX_NAME_LEN] = L'\0';

        mmi_wcsncpy(sel_ret.number, pse_phb->num[index].number, MMI_PHB_PBAPC_MAX_NUM_LEN);
        sel_ret.number[MMI_PHB_PBAPC_MAX_NUM_LEN] = L'\0';

        field_mask = 0;
        if (sel_ret.name[0])
        {
            field_mask |= 0x01;
        }

        if (sel_ret.number[0])
        {
            field_mask |= 0x02;
        }
    }
    else if (ret == 1)
    {
        sel_ret.ret = MMI_PHB_PBAPC_SEL_RET_CANCEL;
    }

    //kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] cui_phb_pbapc_bt_send_select_result--ret: %d, field_mask: 0x%x\n",
    //                                                                ret, field_mask);

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_PBAPC_SEND_SEL_RESULT, ret, field_mask);

    cui_phb_send_data_to_sa(GRP_ID_PHB_PBAPC_SELECT_CONTACT, &sel_rsp);

    cui_phb_pbapc_select_contact_send_req_close();
}


static void cui_phb_pbapc_bt_send_select_result_ext(mmi_phb_pbapc_phb_info_struct *pse_phb, S32 index, S32 ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    cui_phb_pbapc_select_contact_rsp_struct sel_rsp;
    cui_phb_pbapc_select_contact_ret_struct sel_ret;
    U32 field_mask = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    memset(&sel_ret, 0x00, sizeof(cui_phb_pbapc_select_contact_ret_struct));

    MMI_FRM_INIT_EVENT(&sel_rsp, EVT_ID_PHB_PBAPC_SEL_CONTACT);

    sel_rsp.sender_id = GRP_ID_PHB_PBAPC_SELECT_CONTACT;
    sel_rsp.cb_user_data = phb_pbapc_cntx_p->cui_sel_contact_ud;
    sel_rsp.rsp_type = MMI_PHB_PBAPC_SEL_RESULT;
    sel_rsp.rsp = (void *)&sel_ret;

    if (ret == 0)
    {
        /* sel ok result */
        sel_ret.ret = MMI_PHB_PBAPC_SEL_RET_OK;
        sel_ret.contact_type = MMI_PHB_PBAPC_CONTACT_BT;
        sel_ret.entry_index = phb_pbapc_cntx_p->cui_pse_entry_index;
        sel_ret.storage = phb_pbapc_cntx_p->cui_contact_storage;
        sel_ret.num_type = pse_phb->num[index].type;

        mmi_wcsncpy(sel_ret.name, pse_phb->name, MMI_PHB_PBAPC_MAX_NAME_LEN);
        sel_ret.name[MMI_PHB_PBAPC_MAX_NAME_LEN] = L'\0';

        mmi_wcsncpy(sel_ret.number, pse_phb->num[index].number, MMI_PHB_PBAPC_MAX_NUM_LEN);
        sel_ret.number[MMI_PHB_PBAPC_MAX_NUM_LEN] = L'\0';

        field_mask = 0;
        if (sel_ret.name[0])
        {
            field_mask |= 0x01;
        }

        if (sel_ret.number[0])
        {
            field_mask |= 0x02;
        }
    }
    else if (ret == 1)
    {
        sel_ret.ret = MMI_PHB_PBAPC_SEL_RET_CANCEL;
    }

    //kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] cui_phb_pbapc_bt_send_select_result_ext--ret: %d, field_mask: 0x%x\n",
    //                                                                ret, field_mask);

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_PBAPC_SEND_SEL_RESULT_EXT, ret, field_mask);

    cui_phb_send_data_to_sa(GRP_ID_PHB_PBAPC_SELECT_CONTACT, &sel_rsp);

    cui_phb_pbapc_select_contact_send_req_close();
}


static void cui_phb_pbapc_select_contact_local_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    srv_phb_filter_struct filter;
    U8 *gui_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    if (!cui_tab_enter(
            GRP_ID_PHB_PBAPC_SELECT_CONTACT,
            SCR_ID_PHB_PBAPC_LOCAL,
            cui_phb_pbapc_select_contact_local_exit,
            cui_phb_pbapc_select_contact_local_entry,
            MMI_FRM_FULL_SCRN
            ))
#else
    if (!mmi_frm_scrn_tab_page_enter(
            GRP_ID_PHB_PBAPC_SELECT_CONTACT,
            SCR_ID_PHB_PBAPC_TAB,
            SCR_ID_PHB_PBAPC_LOCAL,
            cui_phb_pbapc_select_contact_local_exit,
            cui_phb_pbapc_select_contact_local_entry,
            MMI_FRM_TAB_PAGE
            ))
#endif
    {
        return;
    }

    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    g_wgui_cat199_has_default_hilight_item = MMI_FALSE;

    phb_pbapc_cntx_p->cui_list = 1;

    //kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] cui_phb_pbapc_select_contact_local_entry--is_in_backward: %d\n",
    //                                                                mmi_frm_is_in_backward_scenario());

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_PBAPC_SEL_LOCAL_ENTRY, mmi_frm_is_in_backward_scenario());

    if (!mmi_frm_is_in_backward_scenario())
    {
        if (srv_phb_startup_is_phb_ready())
        {
            if (phb_pbapc_cntx_p->local_contact_id == NULL)
            {
                phb_pbapc_cntx_p->local_contact_id = srv_phb_mem_malloc(sizeof(U16) * MMI_PHB_ENTRIES, SRV_PHB_MEMORY_TYPE_ADM);
            }

            filter.storage = PHB_STORAGE_MAX;
            filter.field_filter = SRV_PHB_ENTRY_FIELD_GSM_NUM;
            filter.name_filter = NULL;
            filter.qsearch_filter = NULL;
            filter.group_filter = NULL;

            phb_pbapc_cntx_p->local_contact_count = (U16) srv_phb_oplib_build_contact_list(&filter, phb_pbapc_cntx_p->local_contact_id, MMI_PHB_ENTRIES);
        
            cui_phb_pbapc_local_show_list();
        }
     }
     else
     {
         cui_phb_pbapc_local_show_list();
     }
}


static void cui_phb_pbapc_select_contact_local_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


static void cui_phb_pbapc_select_contact_bt_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_cat199_has_default_hilight_item = MMI_FALSE;
    mmi_phb_pbapc_entry_list_tab();
}


static void cui_phb_pbapc_select_contact_bt_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_exit_list_tab();
}


static void cui_phb_pbapc_pre_select_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    //kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] cui_phb_pbapc_pre_select_contact--entry_index: %d, storage: %d\n",
    //                                                                phb_pbapc_cntx_p->pse_entry_index, phb_pbapc_cntx_p->contact_storage);

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_PBAPC_PRE_SEL_CONTACT, phb_pbapc_cntx_p->cui_pse_entry_index, phb_pbapc_cntx_p->cui_contact_storage);

    if (phb_pbapc_cntx_p->job_type == 1)
    {
        return ;
    }
    //0xbabe0003   cui list pre select contact
    mmi_phb_pbapc_read_pse_entry(phb_pbapc_cntx_p->cui_pse_entry_index, phb_pbapc_cntx_p->cui_contact_storage, (void *)0xbabe0003, cui_phb_pbapc_pre_select_contact_cb);
}


static S32 cui_phb_pbapc_pre_select_contact_cb(mmi_phb_pbapc_cb_info_struct *cb_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    srv_phb_pbapc_read_entry_rsp_struct *entry_rsp = NULL;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    entry_rsp = (srv_phb_pbapc_read_entry_rsp_struct *)cb_info->type_rsp;

    //mmi_phb_pbapc_show_loading_abort(GRP_ID_PHB_PBAPC_VIEW_CONTACT, SCR_ID_PHB_PROCESSING);
    //kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] cui_phb_pbapc_pre_select_contact_cb(ret)--ret: %d\n",
    //                                                                entry_rsp->ret);

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_PBAPC_PRE_SEL_CONTACT_CB_RET, entry_rsp->ret);

    if (entry_rsp->ret == 0)
    {
        memset(&(phb_pbapc_cntx_p->cui_pse_phb), 0x00, sizeof(mmi_phb_pbapc_phb_info_struct));
        mmi_phb_pbapc_parse_single_vcard_file(entry_rsp->entry_path, &(phb_pbapc_cntx_p->cui_pse_phb));

        if (phb_pbapc_cntx_p->cui_pse_phb.num_count == 0)
        {
            /* show no number popup */
            cui_phb_pbapc_bt_send_select_result_ext(&(phb_pbapc_cntx_p->cui_pse_phb), 0, 0);
        }
        else if (phb_pbapc_cntx_p->cui_pse_phb.num_count > 1)
        {
            // phb_pbapc_cntx_p->op_type = 1;
            mmi_phb_pbapc_select_op_number(GRP_ID_PHB_PBAPC_SELECT_CONTACT, cui_phb_pbapc_pre_select_contact_number_cb,
                                   (void *)0xbabe0004, &(phb_pbapc_cntx_p->cui_pse_phb));
        }
        else /* just 1 number send ret directly */
        {
            //kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] cui_phb_pbapc_pre_select_contact_cb(send ret)\n");
            MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_PBAPC_PRE_SEL_CONTACT_CB_SEND_RET);
            cui_phb_pbapc_bt_send_select_result_ext(&(phb_pbapc_cntx_p->cui_pse_phb), 0, 0);
        }
    }
    else
    {
        mmi_popup_display_simple_ext(STR_GLOBAL_FAILED, MMI_EVENT_FAILURE, GRP_ID_PHB_PBAPC_SELECT_CONTACT, NULL);
        cui_phb_pbapc_bt_send_select_result_ext(&(phb_pbapc_cntx_p->cui_pse_phb), 0, 1);
    }

    return ret;
}


static S32 cui_phb_pbapc_pre_select_contact_number_cb(mmi_phb_pbapc_cb_info_struct *cb_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    S32 index = -1;
    mmi_phb_pbapc_sel_num_rsp_struct *sel_num_rsp;
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    sel_num_rsp = (mmi_phb_pbapc_sel_num_rsp_struct *) (cb_info->type_rsp);

    if (sel_num_rsp->ret == 0)
    {
        index = sel_num_rsp->sel_index;
        cui_phb_pbapc_bt_send_select_result_ext(&(phb_pbapc_cntx_p->cui_pse_phb), index, 0);
    }
    else
    {
        cui_phb_pbapc_bt_send_select_result_ext(&(phb_pbapc_cntx_p->cui_pse_phb), 0, 1);
    }

    return ret;
}



#define EXTERN_CUI_PHB_PBAPC_SELECT_CONTACT_API


mmi_ret cui_phb_pbapc_select_contact_create(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    mmi_ret gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    phb_pbapc_cntx_p->cui_sel_contact_pid = parent_id;
    phb_pbapc_cntx_p->cui_sel_contact_ud = NULL;

    gid = mmi_frm_group_create_ex(parent_id, GRP_ID_PHB_PBAPC_SELECT_CONTACT, cui_phb_pbapc_select_contact_proc, NULL, MMI_FRM_NODE_NONE_FLAG);


    //kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] cui_phb_pbapc_select_contact_create--parent_id: %d, gid: %d\n",
    //                                                                parent_id, gid);

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_PBAPC_SEL_CONTACT_CREATE, parent_id, gid);

    return gid;
}


void cui_phb_pbapc_select_contact_run(mmi_id sel_contact_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GRP_ID_PHB_PBAPC_SELECT_CONTACT != sel_contact_gid)
    {
        MMI_ASSERT(0);
    }

    cui_phb_pbapc_select_contact_entry();
}


void cui_phb_pbapc_select_contact_set_user_data(mmi_id sel_contact_gid, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GRP_ID_PHB_PBAPC_SELECT_CONTACT != sel_contact_gid)
    {
        MMI_ASSERT(0);
    }

    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    phb_pbapc_cntx_p->cui_sel_contact_ud = user_data;
}


void cui_phb_pbapc_select_contact_close(mmi_id sel_contact_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GRP_ID_PHB_PBAPC_SELECT_CONTACT != sel_contact_gid)
    {
        MMI_ASSERT(0);
    }

    //kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] cui_phb_pbapc_select_contact_close--sel_contact_gid: %d\n",
    //                                                                sel_contact_gid);

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_PBAPC_SEL_CONTACT_CLOSE, sel_contact_gid);

    mmi_phb_pbapc_set_list_type(0);

    mmi_frm_group_close(sel_contact_gid);
}


#define MAX_PBAPC_BQB_MAX_FIELDS                        (6)

typedef struct
{
    S32 hlight_index;
    SRV_PHB_PBAPC_HANDLE pbapc_handle;
} mmi_pbapc_bqb_context_struct;


mmi_pbapc_bqb_context_struct g_mmi_pbapc_bqb_cntx;

S32 g_pbap_bqb_flag = 0;


MMI_BOOL mmi_pbapc_is_bqb_test()
{
    return srv_bt_cm_get_bqb_test_flag();
}


void mmi_pbapc_bqb_start()
{
    mmi_frm_group_create_ex(GRP_ID_PHB_MAIN, GRP_ID_PHB_PBAPC_VIEW_CONTACT, mmi_pbapc_bqb_grp_proc, NULL, MMI_FRM_NODE_NONE_FLAG);

    mmi_frm_scrn_create(GRP_ID_PHB_PBAPC_VIEW_CONTACT, SCR_ID_PHB_PBAPC_VIEW_CONTACT, mmi_pbapc_bqb_scr_proc, NULL);
}


static mmi_ret mmi_pbapc_bqb_grp_proc(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}

static mmi_ret mmi_pbapc_bqb_scr_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_INACTIVE:
        {
            break;

        }

        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_pbapc_bqb_show();
            break;
        }

        case EVT_ID_SCRN_DEINIT:
            
        break;
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        {
            break;
        }
        default:
         break;
    }

    return MMI_RET_OK;
}


static void mmi_pbapc_bqb_show()
{
    CHAR *item_list[MAX_PBAPC_BQB_MAX_FIELDS]; 
    S32 highlight_item = 0;
    U8 *gui_buffer = NULL;
    S32 item_num = 0;


    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    RegisterHighlightHandler(mmi_pbapc_bqb_highlight_hdlr);


    item_list[0] = (CHAR *)(L"PBD/BV-1-C(Download)");
    item_list[1] = (CHAR *)(L"PDF/BV-1-I(Retrieve)");
    item_list[2] = (CHAR *)(L"PDF/BV-6-I(Abort)");
    item_list[3] = (CHAR *)(L"SSM/BV-2-C(Close)");

    item_num = 4;

    ShowCategory84Screen(
                STR_ID_PBAP_BQB_TEST,
                GetRootTitleIcon(MAIN_MENU_PHONEBOOK_MENUID),
                0,
                0,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                item_num,
                (U8 **) item_list,
                NULL,
                WGUI_CATE_ITEM_DISABLE_WITHOUT_CHANGE_TEXT_COLOR,
                highlight_item,
                gui_buffer);
}


static void mmi_pbapc_bqb_highlight_hdlr(S32 index)
{

    g_mmi_pbapc_bqb_cntx.hlight_index = index;

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_pbapc_bqb_option, KEY_EVENT_UP);

    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_pbapc_bqb_option, KEY_EVENT_UP);

    SetRightSoftkeyFunction(mmi_pbapc_bqb_back, KEY_EVENT_UP);
}

extern void srv_pbapc_bqb_disconnect_req();

static void mmi_pbapc_bqb_option()
{
    S32 index = 0;

    index = g_mmi_pbapc_bqb_cntx.hlight_index;

    if (index == 0)
    {
        mmi_pbapc_bqb_read_folder();
    }
    else if (index == 1)
    {
        mmi_pbapc_bqb_read_folder();
    }
    else if (index == 2)
    {
        //mmi_pbapc_bqb_abort();
        mmi_pbapc_bqb_read_folder();
        g_pbap_bqb_flag = 1;
    }
    else if (index == 3)
    {
        //srv_pbapc_bqb_disconnect_req();

        if (g_mmi_pbapc_bqb_cntx.pbapc_handle)
        {
            srv_phb_pbapc_destory_handle(g_mmi_pbapc_bqb_cntx.pbapc_handle);
            g_mmi_pbapc_bqb_cntx.pbapc_handle = NULL;
        }

        g_pbap_bqb_flag = 0;
    }
}


static void mmi_pbapc_bqb_back()
{
    if (g_mmi_pbapc_bqb_cntx.pbapc_handle)
    {
        srv_phb_pbapc_destory_handle(g_mmi_pbapc_bqb_cntx.pbapc_handle);
        g_mmi_pbapc_bqb_cntx.pbapc_handle = NULL;
    }

    mmi_frm_group_close(GRP_ID_PHB_PBAPC_VIEW_CONTACT);
}


static void mmi_pbapc_bqb_read_folder()
{
    S32 ret = -1;
    srv_phb_pbapc_read_folder_req_struct folder_req;


    g_mmi_pbapc_bqb_cntx.pbapc_handle = srv_phb_pbapc_create_handle(&ret);

    /* Req head */
    folder_req.handle = g_mmi_pbapc_bqb_cntx.pbapc_handle;
    folder_req.storage = SRV_PHB_PBAP_STORAGE_PHONE_PB;
    folder_req.user_data = (void *)0xb0b;

    folder_req.folder_name = NULL;
    folder_req.vcard_format = SRV_PHB_PBAP_VCARD_FORMAT_21;
    folder_req.vcard_filter = SRV_PHB_PBAP_VCARD_FILTER_ALL;
    folder_req.list_count = 52;
    folder_req.list_offset = 0;

    ret = srv_phb_pbapc_read_pse_folder(&folder_req, mmi_pbapc_bqb_read_folder_cb);
}


static S32 mmi_pbapc_bqb_read_folder_cb(srv_phb_pbapc_read_folder_rsp_struct *folder_rsp, void *user_data)
{
    srv_phb_pbapc_destory_handle(g_mmi_pbapc_bqb_cntx.pbapc_handle);
    g_mmi_pbapc_bqb_cntx.pbapc_handle = NULL;

    return 0;
}

extern  void srv_pbapc_abort_req(pbap_set_folder_type_enum folder_type,U16 * name);

static void mmi_pbapc_bqb_abort()
{
    srv_pbapc_abort_req(0, NULL);
}

#endif

#endif /* defined(__MMI_BT_PBAP_CLIENT__) */

