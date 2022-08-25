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
 * WgtMgrAppSettings.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
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
 *
 * removed!
 * removed!
 * removed!
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
 *==============================================================================
 *******************************************************************************/
/* MMI */
#include "MMI_features.h"
#ifdef __MMI_GADGET_SUPPORT__
/************************************************************************/
/* Include Header                                                       */
/************************************************************************/
/* CUI  */
#include "InlineCuiGprot.h"
#include "DataAccountCuiGprot.h"

/* data account */
#include "DataAccountGProt.h"

/* Widget Manager Service */
#include "WgtMgrSrvGprot.h"
#include "WgtMgrSrvIprot.h"

/* Widget Manager Application */
#include "WgtMgrAppIprot.h"
#include "mmi_rp_app_wgtmgr_def.h"


#include "MMIDataType.h"
#include "DtcntSrvGprot.h"
#include "kal_general_types.h"
#include "GlobalResDef.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "gui_typedef.h"
#include "GlobalConstants.h"
#include "wgui_categories_util.h"
#include "AlertScreen.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "CommonScreensResDef.h"
#include "app_mem.h"
#include "DebugInitDef_Int.h"
#include "Menucuigprot.h"
#include "SimCtrlSrvGprot.h"

/************************************************************************/
/* Structure and Definition                                             */
/************************************************************************/
typedef struct
{
    mmi_id cui_id;
    mmi_id sub_cui_id;
    //U32 dtcnt_id;
    //WCHAR dtcnt_name[MAX_DATA_ACCOUNT_NAME_LEN + DATA_ACCOUNT_NAME_SUFFIX_LEN + 1];
} mmi_wgtmgr_settings_cntx_struct;


/************************************************************************/
/* Internal Function Declaration                                        */
/************************************************************************/
static void mmi_wgtmgr_entry_data_account(void);
static void mmi_wgtmgr_entry_network_access(void);
static mmi_ret mmi_wgtmgr_settings_proc(mmi_event_struct *evt);

/************************************************************************/
/* Golbal Variable                                                      */
/************************************************************************/
static mmi_wgtmgr_settings_cntx_struct *g_mmi_wgtmgr_settings_cntx_p = NULL;

/************************************************************************/
/* Local Function Definition                                            */
/************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_entry_data_account
 * DESCRIPTION
 *  This function is used to create data account menu with data account CUI
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_entry_data_account(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id cui_id;
    cui_dtcnt_select_run_struct info;
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* create data account select CUI */
    cui_id = cui_dtcnt_select_create(GRP_ID_WGTMGR_SETTINGS);

    info.AppMenuID = MENU_ID_WGTMGR_SETTINGS;
    info.bearers = DATA_ACCOUNT_BEARER_GPRS | DATA_ACCOUNT_BEARER_WIFI;
    //info.option = CUI_DTCNT_SELECT_SIM | CUI_DTCNT_SELECT_WITHOUT_PROXY_ONLY;
    info.option = CUI_DTCNT_SELECT_DEFAULT | CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY;
    info.type = CUI_DTCNT_SELECT_TYPE_NORMAL;
    info.sim_selection = CUI_DTCNT_SELECT_SIM_ALL;
#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_MAINLCD_320X480__)	
    info.icon_id = IMG_NONE;
#else
    info.icon_id = IMG_ID_WGTMGR_APP;
#endif
    info.app_id = srv_wgtmgr_get_da_app_id();	
    info.str_id = STR_GLOBAL_DATA_ACCOUNT;
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        info.sim_account_id[i] = srv_wgtmgr_get_default_data_account(i);
    }

    cui_dtcnt_select_set_param(cui_id, &info);

    /* run data account select CUI */
    cui_dtcnt_select_run(cui_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_entry_network_access
 * DESCRIPTION
 *  This function is used to change network access settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_entry_network_access(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_wgtmgr_settings_cntx_struct *cntx_p = g_mmi_wgtmgr_settings_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* create menu CUI */
    cntx_p->sub_cui_id = cui_menu_create(
                 GRP_ID_WGTMGR_SETTINGS, 
                 CUI_MENU_SRC_TYPE_RESOURCE, 
                 CUI_MENU_TYPE_APPSUB, 
                 MENU_ID_WGTMGR_NETWORK_ACCESS, 
                 MMI_TRUE, 
                 NULL);
    
#if !defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_MAINLCD_320X480__)	
    cui_menu_set_default_title_image_by_id(cntx_p->sub_cui_id, IMG_ID_WGTMGR_APP);
#endif

    /* run menu CUI */
    cui_menu_run(cntx_p->sub_cui_id);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_settings_proc
 * DESCRIPTION
 *  This function is the proc function of settings
 * PARAMETERS
 *  evt : [IN] the group event
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_wgtmgr_settings_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_wgtmgr_settings_cntx_struct *cntx_p = g_mmi_wgtmgr_settings_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            if (cntx_p != NULL)
            {
                OslMfree(cntx_p);
                g_mmi_wgtmgr_settings_cntx_p = NULL;
            }        
            break;

        case CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED:
        {
            cui_dtcnt_select_event_any_sim_selected_struct *result = 
                (cui_dtcnt_select_event_any_sim_selected_struct *)evt;

            /* set data account */
            srv_wgtmgr_set_default_data_account(result->selectSim, result->accountId);

            break;
        }

        case CUI_DTCNT_SELECT_EVENT_RESULT_OK:
        case CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL:
        case CUI_DTCNT_SELECT_EVENT_CLOSE:
        {
            cui_dtcnt_select_event_struct *result = (cui_dtcnt_select_event_struct *)evt;
            /* simply close the CUI */
            cui_dtcnt_select_close(result->sender_id);            
            break;
        }		

        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            cui_menu_event_struct *result = (cui_menu_event_struct *)evt;

            if (result->parent_menu_id == MENU_ID_WGTMGR_SETTINGS)
            {
                /* set menu cui item icon */
                cui_menu_set_item_image(cntx_p->cui_id, MENU_ID_WGTMGR_NETWORK_ACCESS, IMG_GLOBAL_L1);
                cui_menu_set_item_image(cntx_p->cui_id, MENU_ID_WGTMGR_DATA_ACCOUNT, IMG_GLOBAL_L2);
            }
            else if (result->parent_menu_id == MENU_ID_WGTMGR_NETWORK_ACCESS)
            {
                if (srv_wgtmgr_get_network_access() == SRV_WGTMGR_NETWORK_ACCESS_ALLOW)
                {
                    /* set cui highlighted item to ALLOW */
                    cui_menu_set_currlist_highlighted_id(
                        cntx_p->sub_cui_id, 
                        MENU_ID_WGTMGR_NETWORK_ACCESS_ALLOW);
                }        
                else
                {
                    /* set cui highlighted item to ALWAY ASK */
                    cui_menu_set_currlist_highlighted_id(
                        cntx_p->sub_cui_id, 
                        MENU_ID_WGTMGR_NETWORK_ACCESS_ALWAYS_ASK);
                }
            }
        
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        {
            cui_menu_event_struct *result = (cui_menu_event_struct *)evt;

            if (result->parent_menu_id == MENU_ID_WGTMGR_SETTINGS)
            {
                if (result->highlighted_menu_id == MENU_ID_WGTMGR_DATA_ACCOUNT)
                {
                    if (srv_sim_ctrl_any_sim_is_available() == MMI_TRUE)
                    {
                        /* enter data account settings screen */
                        mmi_wgtmgr_entry_data_account();
                    }
                    else
                    {
                        /* display popup "Unvavilable sim" */
                        mmi_popup_display_simple(get_string(STR_GLOBAL_UNAVAILABLE_SIM), MMI_EVENT_WARNING, GRP_ID_WGTMGR_MAIN, NULL);
                    }
                }      
                else
                {
                    /* enter network access setting screen */
                    mmi_wgtmgr_entry_network_access();
                }
            }
            else if (result->parent_menu_id == MENU_ID_WGTMGR_NETWORK_ACCESS)
            {
                /* set network acces flag to widget manager service */
                if (result->highlighted_menu_id == MENU_ID_WGTMGR_NETWORK_ACCESS_ALLOW)
                {
                    srv_wgtmgr_set_network_access(SRV_WGTMGR_NETWORK_ACCESS_ALLOW);  
                }
                else 
                {
                    srv_wgtmgr_set_network_access(SRV_WGTMGR_NETWORK_ACCESS_ALWAYS_ASK);
                }

                /* show success popup */
                mmi_popup_display_simple(get_string(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS, GRP_ID_WGTMGR_MAIN, NULL);
                cui_menu_close(result->sender_id);
            }

            break;
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_event_struct *result = (cui_menu_event_struct *)evt;
            
            cui_menu_close(result->sender_id);

            /* close setting group */
            if (result->parent_menu_id == MENU_ID_WGTMGR_SETTINGS)
            {
                mmi_wgtmgr_leave_option_menu();
            }

            break;
        }
        case EVT_ID_CUI_MENU_LIST_EXIT:
        {
            break;
        }
    }

    return MMI_RET_OK;
}

/************************************************************************/
/* Global Function Definition                                            */
/************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_entry_settings
 * DESCRIPTION
 *  This function is used to create settings menu with inline CUI
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wgtmgr_entry_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id cui_id;
    mmi_wgtmgr_settings_cntx_struct *cntx_p = g_mmi_wgtmgr_settings_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* cntx_p shall be NULL when entering settings */
    MMI_ASSERT(cntx_p == NULL);

    /* allocate memory for setting cntx */
    cntx_p = (mmi_wgtmgr_settings_cntx_struct *)OslMalloc(sizeof(mmi_wgtmgr_settings_cntx_struct));

    /* cntx_p shall not be NULL after allocating control buffer */
    MMI_ASSERT(cntx_p != NULL);

    /* record the cntx address */
    g_mmi_wgtmgr_settings_cntx_p = cntx_p;

    /* create the screen group for settings menu */
    mmi_frm_group_create(GRP_ID_WGTMGR_OPTIONS, GRP_ID_WGTMGR_SETTINGS, mmi_wgtmgr_settings_proc, NULL);

    /* enter the screen group for settings menu */
    mmi_frm_group_enter(GRP_ID_WGTMGR_SETTINGS, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    /* create menu CUI */
    cui_id = cui_menu_create(
                 GRP_ID_WGTMGR_SETTINGS, 
                 CUI_MENU_SRC_TYPE_RESOURCE, 
                 CUI_MENU_TYPE_APPSUB, 
                 MENU_ID_WGTMGR_SETTINGS, 
                 MMI_FALSE, 
                 NULL);

#if !defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_MAINLCD_320X480__)	
    cui_menu_set_default_title_image_by_id(cui_id, IMG_ID_WGTMGR_APP);
#endif

    /* store the cui id */
    cntx_p->cui_id = cui_id;

    /* check the data account */
    srv_wgtmgr_check_data_account();

    /* run menu CUI */
    cui_menu_run(cui_id);

}
#endif /* __MMI_GADGET_SUPPORT__ */
