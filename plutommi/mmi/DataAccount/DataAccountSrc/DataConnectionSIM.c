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
 *  DataConnectionSIM.c
 *
 * Project:
 * --------
 *  Pluto
 *
 * Description:
 * ------------
 *  This file implement the data connection SIM feature.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifdef __TCPIP__
#include "MMI_features.h"
#if defined (__DCM_WITH_COMPRESSION_MMI_AP__) && defined(__MTK_TARGET__)
#include "mmi_ap_dcm_config.h" 
#endif
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "DtcntSrvGprot.h"
#include "DtcntSrvIprot.h"
#include "SimCtrlSrvGprot.h"
#include "cbm_api.h"
#include "cbm_consts.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "DataaccountProt.h"
#include "DataaccountGprot.h"
#include "menucuigprot.h"
#include "mmi_rp_app_dataaccount_def.h"
#include "AlertScreen.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_util.h"
#include "mmi_frm_utility_gprot.h"
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
#include "NetSetAppGprot.h"
#endif

#ifdef __MMI_PNS__
#include "PnSrvGprot.h"
#endif
/***************************************************************************** 
 * Extern Variable
 *****************************************************************************/
extern mmi_dtcnt_list_disp_struct g_mmi_dtcnt_list_item[MMI_DTCNT_PROF_MAX_ACCOUNT_NUM];
extern U32 g_mmi_dtcnt_acct_num;

/***************************************************************************** 
 * Local Variable
 *****************************************************************************/
#ifdef __MMI_AP_DCM_DTCNT__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif

static const U16 mmi_data_connection_sim_arr[] = 
{
    STR_GLOBAL_SIM_1,
    STR_GLOBAL_SIM_2,
    STR_GLOBAL_SIM_3,
    STR_GLOBAL_SIM_4
};

#ifdef __MMI_AP_DCM_DTCNT__
#pragma arm section rodata , code
#endif


#ifdef __MMI_PNS__
static srv_dtcnt_sim_type_enum g_mmi_data_connection_selected_sim_type;
#endif
/***************************************************************************** 
 * Local Function
 *****************************************************************************/
static void mmi_data_connection_sim_pre_entry_main(void);
static void mmi_data_connection_sim_entry_main(void);
static mmi_ret mmi_data_connection_sim_cui_event_proc(mmi_event_struct *evt);
static MMI_BOOL mmi_data_connection_sim_item_selected(srv_dtcnt_sim_type_enum sim_type);
static MMI_BOOL mmi_data_connection_sim_is_any_account_in_use(srv_dtcnt_sim_type_enum old_sim_type);
#ifdef __MMI_PNS__
static mmi_ret mmi_data_connection_progressing_proc(mmi_event_struct *evt);
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_data_connection_sim_main_menu_should_hide
 * DESCRIPTION
 *  shows the main menu list
 *  
 *  This is used to shows the main menu list of data connection SIM
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_data_connection_sim_main_menu_should_hide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_dtcnt_get_available_sim_num() > 1)
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_data_connection_sim_hilite_hdlr
* DESCRIPTION
*  Hilite Handler for Data Connection SIM Menu
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_data_connection_sim_hilite_hdlr(void)
{
#ifdef __TCPIP__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
#ifndef __MMI_WGUI_DISABLE_CSK__ 
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
    SetLeftSoftkeyFunction(mmi_data_connection_sim_pre_entry_main, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_data_connection_sim_pre_entry_main, KEY_EVENT_UP);
#endif /* __TCPIP__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_data_connection_sim_pre_entry_main
 * DESCRIPTION
 *  pre entry function for main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_data_connection_sim_pre_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_DATA_CONNECTION_SIM))
    {
        mmi_frm_group_close(GRP_ID_DATA_CONNECTION_SIM);
    }

#if defined (__MMI_AP_DCM_DTCNT__)
    mmi_ap_send_dcm_load_evt(DYNAMIC_CODE_COMPRESS_SETTINGS);
#endif

    mmi_frm_group_create_ex(
        GRP_ID_ROOT,
        GRP_ID_DATA_CONNECTION_SIM,
        (mmi_proc_func)mmi_data_connection_sim_cui_event_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_data_connection_sim_entry_main();
}

/* DCM compressed functions */
#ifdef __MMI_AP_DCM_DTCNT__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif

void mmi_data_connection_sim_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifndef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    menu_cui_gid = cui_menu_create(
                            GRP_ID_DATA_CONNECTION_SIM,
                            CUI_MENU_SRC_TYPE_RESOURCE,
                            CUI_MENU_TYPE_APPMAIN,
                            MENU_ID_DATA_CONNECTION_SIM,
                            MMI_TRUE,
                            NULL);
    #else
    menu_cui_gid = cui_menu_create(
                            GRP_ID_DATA_CONNECTION_SIM,
                            CUI_MENU_SRC_TYPE_APPCREATE,
                            CUI_MENU_TYPE_APPMAIN,
                            MENU_ID_DATA_CONNECTION_SIM,
                            MMI_FALSE,
                            NULL);
    #endif
    cui_menu_set_default_title_image_by_id(
        menu_cui_gid,
        GetRootTitleIcon(MENU_ID_DATA_CONNECTION_SIM));
    cui_menu_run(menu_cui_gid);
}


mmi_ret mmi_data_connection_sim_cui_event_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    srv_dtcnt_sim_type_enum sim_type = SRV_DTCNT_SIM_TYPE_1;
    MMI_BOOL ret;
    #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    WCHAR tempStr[DTCNT_DYNAMIC_SIM_NAME_MAX_LEN];
    mmi_menu_id menu_list[] = {
                                MENU_ID_DTCNT_SIM_1,
                        #if (MMI_MAX_SIM_NUM >= 2)
                                MENU_ID_DTCNT_SIM_2,
                        #endif
                        #if (MMI_MAX_SIM_NUM >= 3)
                                MENU_ID_DTCNT_SIM_3,
                        #endif
                        #if (MMI_MAX_SIM_NUM >= 4)
                                MENU_ID_DTCNT_SIM_4
                        #endif
                            };
    #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
        #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
            cui_menu_set_default_title_by_id(
                menu_evt->sender_id,
                STR_ID_DATA_CONNECTION_SIM,
                GetRootTitleIcon(MENU_ID_DATA_CONNECTION_SIM));
            cui_menu_set_currlist(
                menu_evt->sender_id,
                sizeof(menu_list)/sizeof(menu_list[0]),
                menu_list);
        #endif
            cui_menu_set_currlist_flags(
                menu_evt->sender_id, 
                CUI_MENU_NORMAL_RADIO_BUTTON_LIST);

            ret = srv_dtcnt_get_sim_preference(&sim_type);
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_DATA_CONNECTION_SIM_GET_SIM_PREFERENCE, sim_type, ret);

            cui_menu_set_radio_list_item(
                menu_evt->sender_id, 
                MENU_ID_DTCNT_SIM_1 + (sim_type - SRV_DTCNT_SIM_TYPE_1));// need to do

            for (i = 0; i < MMI_SIM_TOTAL; i++)
            {
            #ifdef __MMI_TELEPHONY_SUPPORT__
                if (srv_sim_ctrl_is_available(mmi_frm_index_to_sim(i)))
                {
                    cui_menu_set_item_hidden(
                        menu_evt->sender_id,
                        MENU_ID_DTCNT_SIM_1 + i,
                        MMI_FALSE);
                    #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                    mmi_netset_get_sim_name_with_simx_and_brace(
                        mmi_frm_index_to_sim(i),
                        tempStr,
                        DTCNT_DYNAMIC_SIM_NAME_MAX_LEN * ENCODING_LENGTH);
                    cui_menu_set_item_string(
                        menu_evt->sender_id,
                        MENU_ID_DTCNT_SIM_1 + i,
                        tempStr);
                    #endif
                }
                else
            #endif /* __MMI_TELEPHONY_SUPPORT__ */
                {
                    cui_menu_set_item_hidden(
                        menu_evt->sender_id,
                        MENU_ID_DTCNT_SIM_1 + i,
                        MMI_TRUE);
                }
            }
           break;
        }

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        {
            switch(menu_evt->highlighted_menu_id)
            {
                case MENU_ID_DTCNT_SIM_1:
                #if (MMI_MAX_SIM_NUM >= 2)
                case MENU_ID_DTCNT_SIM_2:
                #endif
                #if (MMI_MAX_SIM_NUM >= 3)
                case MENU_ID_DTCNT_SIM_3:
                #endif
                #if (MMI_MAX_SIM_NUM >= 4)
                case MENU_ID_DTCNT_SIM_4:
                #endif
                {
                    sim_type = (srv_dtcnt_sim_type_enum)(SRV_DTCNT_SIM_TYPE_1 + (menu_evt->highlighted_menu_id - MENU_ID_DTCNT_SIM_1));
                    if (mmi_data_connection_sim_item_selected(sim_type))
                    {
                        cui_menu_close(menu_evt->sender_id);
                    }
                    break;
                }
                default:
                    break;
            }
            break;
        }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;

    #if defined (__MMI_AP_DCM_DTCNT__)
        case EVT_ID_GROUP_DEINIT:
            if(!mmi_frm_app_is_launched(APP_SETTING_NEW))
            {
                mmi_ap_post_dcm_unload_evt( DYNAMIC_CODE_COMPRESS_SETTINGS);
            }
            break;
    #endif

        default:
            break;
    }
    return MMI_RET_OK;
}


MMI_BOOL mmi_data_connection_sim_item_selected(srv_dtcnt_sim_type_enum sim_type)
{
    srv_dtcnt_sim_type_enum old_sim_type = SRV_DTCNT_SIM_TYPE_1;
    MMI_BOOL ret;

    ret = srv_dtcnt_get_sim_preference(&old_sim_type);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_DATA_CONNECTION_SIM_GET_SIM_PREFERENCE, old_sim_type, ret);

    if (sim_type == old_sim_type)
    {
        return MMI_TRUE;
    }
    else
    {
    #ifdef __MMI_PNS__
        if(srv_pns_force_close_connection(mmi_data_connection_progressing_proc, NULL))
        {
            g_mmi_data_connection_selected_sim_type = sim_type;
            mmi_frm_scrn_create(
                        GRP_ID_DATA_CONNECTION_SIM,
                        SCR_ID_DTCNT_PROGRESSING,
                        mmi_data_connection_progressing_proc,
                        NULL);
            return MMI_FALSE;
        }
        else
   #endif /* __MMI_PNS__ */
        {
            // check any account in use
            if (mmi_data_connection_sim_is_any_account_in_use(old_sim_type))
            {
                // display popup
                WCHAR str[100 + 1];
                mmi_wsprintf(
                    str, 
                    100, 
                    STR_ID_DATA_CONNECTION_SIM_NOT_ALLOW_CHANGED, 
                    mmi_data_connection_sim_arr[old_sim_type - SRV_DTCNT_SIM_TYPE_1]);
                mmi_popup_display_simple(str, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
                return MMI_FALSE;
            }
            else
            {
                ret = srv_dtcnt_set_sim_preference(sim_type);
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_DATA_CONNECTION_SIM_SET_SIM_PREFERENCE, sim_type, ret);
                return MMI_TRUE;
            }
        }
    }
}


MMI_BOOL mmi_data_connection_sim_is_any_account_in_use(srv_dtcnt_sim_type_enum old_sim_type)
{
    U32 i;
    U32 acct_id;
    srv_dtcnt_sim_type_enum sim_type = SRV_DTCNT_SIM_TYPE_1;
    for (i = 0; i < g_mmi_dtcnt_acct_num; i++)
    {
        acct_id = g_mmi_dtcnt_list_item[i].profile_id;
        srv_dtcnt_get_sim_info(acct_id, &sim_type);
        // only need to check the data connection SIM's account
        if (sim_type == old_sim_type)
        {
            if (mmi_dtcnt_is_account_in_use(acct_id))
            {
                return MMI_TRUE;
            }
        }
    }
    return MMI_FALSE;
}

#ifdef __MMI_PNS__
mmi_ret mmi_data_connection_progressing_proc(mmi_event_struct *evt)
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
            mmi_frm_scrn_active_evt_struct *active_evt;
            active_evt = (mmi_frm_scrn_active_evt_struct *)evt;
			ShowCategory66Screen(
				STR_ID_DATA_CONNECTION_SIM,
				0,
				0,
				0,
				0,
				0,
				(U8*) GetString(STR_GLOBAL_PLEASE_WAIT),
				mmi_get_event_based_image(MMI_EVENT_PROGRESS),
				active_evt->gui_buffer);
            ClearAllKeyHandler();
            ClearKeyHandler(KEY_END, KEY_EVENT_UP);
            ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
            ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
            ClearKeyHandler(KEY_END, KEY_REPEAT);
            break;
        }
        case EVT_ID_SRV_PNS_FORCE_CLOSED_COMPLETE:
        {
            srv_dtcnt_sim_type_enum old_sim_type = SRV_DTCNT_SIM_TYPE_1;
            MMI_BOOL ret;

            ret = srv_dtcnt_get_sim_preference(&old_sim_type);
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_DATA_CONNECTION_SIM_GET_SIM_PREFERENCE, old_sim_type, ret);

            // check any account in use
            if (mmi_data_connection_sim_is_any_account_in_use(old_sim_type))
            {
                if(mmi_frm_group_is_in_active_serial(GRP_ID_DATA_CONNECTION_SIM))
                {
                    WCHAR str[100 + 1];
                    mmi_wsprintf(
                        str, 
                        100, 
                        STR_ID_DATA_CONNECTION_SIM_NOT_ALLOW_CHANGED, 
                        mmi_data_connection_sim_arr[old_sim_type - SRV_DTCNT_SIM_TYPE_1]);
                    mmi_popup_display_simple(str, MMI_EVENT_FAILURE, GRP_ID_DATA_CONNECTION_SIM, NULL);
                }
                mmi_frm_scrn_close(GRP_ID_DATA_CONNECTION_SIM, SCR_ID_DTCNT_PROGRESSING);
            }
            else
            {
                ret = srv_dtcnt_set_sim_preference(g_mmi_data_connection_selected_sim_type);
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_DATA_CONNECTION_SIM_SET_SIM_PREFERENCE, g_mmi_data_connection_selected_sim_type, ret);
                mmi_frm_group_close(GRP_ID_DATA_CONNECTION_SIM);
            }
            srv_pns_resume_connection();
            break;
        }

        default:
            break;
    }

    return MMI_RET_OK;
}

#ifdef __MMI_AP_DCM_DTCNT__
#pragma arm section rodata , code
#endif

#endif

#endif /* __TCPIP__ */

