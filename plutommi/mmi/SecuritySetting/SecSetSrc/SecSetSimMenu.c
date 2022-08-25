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
 *  SecSetSim.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Handling of SIM security
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "PwdCuiGprot.h"
#include "mmi_rp_app_mainmenu_def.h" /* MAIN_MENU_TITLE_SETTINGS_ICON */
#include "MMIDataType.h"
#include "SimCtrlSrvGprot.h"
#include "menucuigprot.h"
#include "AlertScreen.h"
#include "GlobalResDef.h"
#include "wgui_categories_util.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_rp_app_security_setting_def.h"
#include "kal_general_types.h"
#include "MMI_features.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_mem_gprot.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "CommonScreensResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "CustMenuRes.h"
#include "NetSetAppGprot.h"
#include "MMI_ap_dcm_config.h" /* DCM about Security Setting */

/****************************************************************************
 * Context
 ****************************************************************************/
#if defined(__MMI_TELEPHONY_SUPPORT__)

typedef struct
{
    mmi_sim_enum sim;
    srv_sim_ctrl_pwd_type_enum chv_type;
    mmi_id submenu_cui;
    mmi_id set_chv_lock_cui; /* cui_pwd_basic */
    mmi_id change_pwd_cui;   /* cui_pwd_guard */
    mmi_secset_ubchv_handle ubchv_handle;
} mmi_secset_sim_cntx_struct;

static mmi_secset_sim_cntx_struct g_mmi_secset_sim_cntx =
{
    MMI_SIM_NONE,
    SRV_SIM_CTRL_PWD_TYPE_CHV1, /* We don't care */
    0,
    0,
    0,
    0
};

#ifdef __MMI_SECSET_APP_WITH_BWUI__
typedef struct
{
    mmi_sim_enum sim;
    MMI_ID submenu_cui;
} mmi_secset_sim_chv1_cntx_struct;

static mmi_secset_sim_chv1_cntx_struct g_mmi_secset_sim_chv1_cntx =
{
	MMI_SIM_NONE,
	0	
};
mmi_menu_id MENU_ID_SECSET_SIMX_CHV1_LOCK[MMI_MAX_SIM_NUM] =
{
	MENU_ID_SECSET_SIM1_CHV1_LOCK,
#if (MMI_MAX_SIM_NUM >= 2)		
	MENU_ID_SECSET_SIM2_CHV1_LOCK,
#if (MMI_MAX_SIM_NUM >= 3)		
	MENU_ID_SECSET_SIM3_CHV1_LOCK,
#if (MMI_MAX_SIM_NUM >= 4)	
	MENU_ID_SECSET_SIM4_CHV1_LOCK
#endif
#endif
#endif
};

static void mmi_secset_entry_sim_switch_chv1_menu(mmi_sim_enum sim);
#endif

/****************************************************************************
 * Functions
 ****************************************************************************/

static mmi_ret mmi_secset_sim_menu_proc(const cui_menu_event_struct *menu_evt);
static mmi_ret mmi_secset_sim_menu_on_entry(const cui_menu_event_struct *menu_evt);
static mmi_ret mmi_secset_sim_menu_on_highlight(const cui_menu_event_struct *menu_evt);
static mmi_ret mmi_secset_sim_menu_on_selected(const cui_menu_event_struct *menu_evt);

static void mmi_secset_sim_set_chv1_enabled(mmi_sim_enum sim);
static mmi_ret mmi_secset_sim_set_chv_lock_input_proc(mmi_event_struct *evt);
//static mmi_ret mmi_secset_sim_set_chv_lock_result_proc(mmi_event_struct *evt);

static void mmi_secset_sim_change_chv(mmi_sim_enum sim, srv_sim_ctrl_pwd_type_enum chv_type);
static mmi_ret mmi_secset_sim_change_chv_input_proc(mmi_event_struct *evt);
//static mmi_ret mmi_secset_sim_change_chv_result_proc(mmi_event_struct *evt);
static mmi_ret mmi_secset_sim_set_or_change_chv_result_proc(mmi_event_struct *evt);

static void mmi_secset_sim_popup_chv_blocked(mmi_secset_sim_cntx_struct *cntx);
static mmi_ret mmi_secset_sim_show_ubchv_after_popup(mmi_event_struct *evt);
static void mmi_secset_sim_show_ubchv(
                mmi_secset_sim_cntx_struct *cntx,
                mmi_sim_enum sim,
                srv_sim_ctrl_pwd_type_enum chv_type);
static mmi_ret mmi_secset_sim_ubchv_proc(mmi_event_struct *evt);

#ifdef __MMI_SECSET_SLIM_FOR_61__
static const MMI_MENU_ID SIM_ITEM_ID[MMI_SIM_TOTAL] =
    {
//#if defined(__MMI_TELEPHONY_SUPPORT__)
        MENU_ID_SECSET_SIM1_ENTRY,
#if (MMI_MAX_SIM_NUM >= 2)
        MENU_ID_SECSET_SIM2_ENTRY,
#endif
#if (MMI_MAX_SIM_NUM >= 3)
        MENU_ID_SECSET_SIM3_ENTRY,
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        MENU_ID_SECSET_SIM4_ENTRY
#endif
//#endif/*__MMI_TELEPHONY_SUPPORT__*/
    };
#endif/*__MMI_SECSET_SLIM_FOR_61__*/

#ifdef __MMI_AP_DCM_SECSET__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif

static void mmi_secset_sim_show_menu(
                mmi_secset_sim_cntx_struct *cntx,
                mmi_sim_enum sim,
                mmi_menu_id menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    if (!srv_sim_ctrl_is_inserted(sim))
    {
        mmi_popup_display_simple(
            get_string(STR_ID_SECSET_INSERT_SIM_PROMPT),
            MMI_EVENT_FAILURE,
            GRP_ID_SECSET,
            NULL);
        return;
    }
#endif
    
    if (!srv_sim_ctrl_is_available(sim))
    {
        mmi_popup_display_simple(
            get_string(STR_GLOBAL_NOT_AVAILABLE),
            MMI_EVENT_FAILURE,
            GRP_ID_SECSET,
            NULL);
    }
    else
    {
        /*
         * Create menu on GRP_ID_SECSET, so that the menu event can be
         * broadcasted to the registered procs. (see mmi_secset_grp_proc())
         */
        cntx->sim = sim;
        cntx->submenu_cui = cui_menu_create_and_run(
            GRP_ID_SECSET,
            CUI_MENU_SRC_TYPE_RESOURCE,
            CUI_MENU_TYPE_FROM_RESOURCE,
            menu_id,
            MMI_TRUE,
            cntx);
            
        //cui_menu_run(cntx->submenu_cui);
    }
}

#ifndef __MMI_SECSET_SLIM_FOR_61__
static MMI_MENU_ID mmi_secset_sim_get_menu_item_id(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const MMI_MENU_ID SIM_ITEM_ID[MMI_SIM_TOTAL] =
    {
//#if defined(__MMI_TELEPHONY_SUPPORT__)
        MENU_ID_SECSET_SIM1_ENTRY,
#if (MMI_MAX_SIM_NUM >= 2)
        MENU_ID_SECSET_SIM2_ENTRY,
#endif
#if (MMI_MAX_SIM_NUM >= 3)
        MENU_ID_SECSET_SIM3_ENTRY,
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        MENU_ID_SECSET_SIM4_ENTRY
#endif
//#endif/*__MMI_TELEPHONY_SUPPORT__*/
    };

    S32 sim_index = mmi_frm_sim_to_index(sim);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return SIM_ITEM_ID[sim_index];
}
#endif/*__MMI_SECSET_SLIM_FOR_61__*/


mmi_ret mmi_secset_sim_main_menu_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_sim_cntx_struct *cntx;
    cui_menu_event_struct *menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct*)evt;
    cntx = &g_mmi_secset_sim_cntx;
    
    switch (evt->evt_id)
    {
       case EVT_ID_CUI_MENU_LIST_ENTRY:
            if (menu_evt->parent_menu_id == MENU_ID_SECSET_MAIN_MENU)
            {
                S32 i;
                mmi_sim_enum sim;
                MMI_MENU_ID menu_id;
                
            #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                S32 n_inserted;
            
                n_inserted = srv_sim_ctrl_get_num_of_inserted();

                if (n_inserted == 0)
                {
                  //#if defined(__MMI_TELEPHONY_SUPPORT__)
                    /* Still show one item */
                    mmi_frm_unhide_menu_item(MENU_ID_SECSET_SIM1_ENTRY);
                    /* The string should not contain SIM number */
                    cui_menu_set_item_string_by_id(
                        menu_evt->sender_id,
                        MENU_ID_SECSET_SIM1_ENTRY,
                        STR_ID_SECSET_SIM_SETTING);
                  //#endif/**/
                        
                    /* Hide other SIMs */
                    for (i = 1; i < MMI_SIM_TOTAL; i++)
                    {
                     #ifndef __MMI_SECSET_SLIM_FOR_61__
                        sim = mmi_frm_index_to_sim(i);
                        menu_id = mmi_secset_sim_get_menu_item_id(sim);
					 #else
					    menu_id = SIM_ITEM_ID[i];
					 #endif/*__MMI_SECSET_SLIM_FOR_61__*/
                        mmi_frm_hide_menu_item(menu_id);
                    }
                }
                else
                {
                    for (i = 0; i < MMI_SIM_TOTAL; i++)
                    {
                      #ifndef __MMI_SECSET_SLIM_FOR_61__
                        sim = mmi_frm_index_to_sim(i);
                        menu_id = mmi_secset_sim_get_menu_item_id(sim);
					  #else
					    sim = mmi_frm_index_to_sim(i);
					    menu_id = SIM_ITEM_ID[i];
					  #endif/*__MMI_SECSET_SLIM_FOR_61__*/

                        if (srv_sim_ctrl_is_inserted(sim))
                        {
                            const WCHAR *sim_name;
                            
                            if (n_inserted == 1)
                            {
                                cui_menu_set_item_string_by_id(
                                    menu_evt->sender_id,
                                    menu_id,
                                    STR_ID_SECSET_SIM_SETTING);
                            }
                            mmi_frm_unhide_menu_item(menu_id);

                            sim_name = mmi_netset_get_sim_name(sim);
                            if (sim_name != NULL && sim_name[0] != L'\0')
                            {
                                cui_menu_set_item_hint(
                                    menu_evt->sender_id,
                                    menu_id,
                                    (WCHAR*)sim_name);
                            }
                        }
                        else
                        {
                            mmi_frm_hide_menu_item(menu_id);
                        }
                    }
                }
                
            #else /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */

                for (i = 0; i < MMI_SIM_TOTAL; i++)
                {
                  #ifndef __MMI_SECSET_SLIM_FOR_61__
                    sim = mmi_frm_index_to_sim(i);
                    menu_id = mmi_secset_sim_get_menu_item_id(sim);
				  #else
				    sim = mmi_frm_index_to_sim(i);
					menu_id = SIM_ITEM_ID[i];
				  #endif/*__MMI_SECSET_SLIM_FOR_61__*/

                    if (srv_sim_ctrl_is_available(sim))
                    {
                        mmi_frm_unhide_menu_item(menu_id);
                    }
                    else
                    {
                        mmi_frm_hide_menu_item(menu_id);
                    }
                }
                
            #endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */    
            }
            else
            {
                mmi_secset_sim_menu_proc(menu_evt);
            }
            
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
//#if defined(__MMI_TELEPHONY_SUPPORT__)
            if (menu_evt->highlighted_menu_id == MENU_ID_SECSET_SIM1_ENTRY)
            {
                mmi_secset_sim_show_menu(cntx, MMI_SIM1, MENU_ID_SECSET_SIM1_MENU);
            }
#if (MMI_MAX_SIM_NUM >= 2)
            else if (menu_evt->highlighted_menu_id == MENU_ID_SECSET_SIM2_ENTRY)
            {
                mmi_secset_sim_show_menu(cntx, MMI_SIM2, MENU_ID_SECSET_SIM2_MENU);
            }
#endif /* MMI_MAX_SIM_NUM >= 2 */

#if (MMI_MAX_SIM_NUM >= 3)
	     else if (menu_evt->highlighted_menu_id == MENU_ID_SECSET_SIM3_ENTRY)
            {
                mmi_secset_sim_show_menu(cntx, MMI_SIM3, MENU_ID_SECSET_SIM3_MENU);
            }
#endif /* MMI_MAX_SIM_NUM >= 3 */

#if (MMI_MAX_SIM_NUM == 4)
	     else if (menu_evt->highlighted_menu_id == MENU_ID_SECSET_SIM4_ENTRY)
            {
                mmi_secset_sim_show_menu(cntx, MMI_SIM4, MENU_ID_SECSET_SIM4_MENU);
            }
#endif /* MMI_MAX_SIM_NUM == 4 */
            else
//#endif/*__MMI_TELEPHONY_SUPPORT__*/
            {
                mmi_secset_sim_menu_proc(menu_evt);
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            if (menu_evt->sender_id == cntx->submenu_cui)
            {
                cui_menu_close(cntx->submenu_cui);
                cntx->submenu_cui = 0;
            }
            break;

        default:
            mmi_secset_sim_menu_proc(menu_evt);
            break;
    }

    return MMI_RET_OK;
}


static mmi_ret mmi_secset_sim_menu_proc(const cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            mmi_secset_sim_menu_on_entry(menu_evt);
            break;

        case EVT_ID_CUI_MENU_ITEM_HILITE:
            mmi_secset_sim_menu_on_highlight(menu_evt);
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_secset_sim_menu_on_selected(menu_evt);
            break;
    }

    return MMI_RET_OK;
}


#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
static void mmi_secset_sim_set_title_for_single(const cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_id = menu_evt->sender_id;

    cui_menu_set_currlist_title(
        menu_cui_id,
        get_string(STR_ID_SECSET_SIM_SETTING),
        get_image(MAIN_MENU_TITLE_SETTINGS_ICON));
}
#endif


static mmi_ret mmi_secset_sim_menu_on_entry(const cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_id;
	#ifndef __MMI_SECSET_APP_WITH_BWUI__
    MMI_BOOL chv1_is_enabled;
	#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_id = menu_evt->sender_id;
    
    switch (menu_evt->parent_menu_id)
    {
        case MENU_ID_SECSET_SIM1_MENU:
#if (MMI_MAX_SIM_NUM >= 2)
        #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
            if (srv_sim_ctrl_get_num_of_inserted() <= 1)
            {
                mmi_secset_sim_set_title_for_single(menu_evt);
            }
            else
        #endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
            {
                cui_menu_set_currlist_title(
                    menu_cui_id,
                    get_string(STR_ID_SECSET_SIM1_SETTING),
                    get_image(MAIN_MENU_TITLE_SETTINGS_ICON));
            }
#else
            cui_menu_set_currlist_title(
                menu_cui_id,
                get_string(STR_ID_SECSET_SIM_SETTING),
                get_image(MAIN_MENU_TITLE_SETTINGS_ICON));
#endif
            cui_menu_set_currlist_flags(menu_cui_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
        
	 #ifndef __MMI_SECSET_SLIM_FOR_61__
        #ifndef __MMI_SECSET_APP_WITH_BWUI__
            chv1_is_enabled = srv_sim_ctrl_pwd_is_enabled(MMI_SIM1, SRV_SIM_CTRL_PWD_TYPE_CHV1);
            cui_menu_set_item_hint(
                menu_cui_id,
                MENU_ID_SECSET_SIM1_CHV1_LOCK,
                get_string(chv1_is_enabled ? STR_GLOBAL_ON : STR_GLOBAL_OFF));
        #endif
            cui_menu_set_access_by_shortcut(menu_evt->sender_id, MMI_FALSE);
	 #endif/*__MMI_SECSET_SLIM_FOR_61__*/
            
            break;

#if (MMI_MAX_SIM_NUM >= 2)
        case MENU_ID_SECSET_SIM2_MENU:
        #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
            if (srv_sim_ctrl_get_num_of_inserted() <= 1)
            {
                mmi_secset_sim_set_title_for_single(menu_evt);
            }
            else
        #endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
            {
                cui_menu_set_currlist_title(
                    menu_cui_id,
                    get_string(STR_ID_SECSET_SIM2_SETTING),
                    get_image(MAIN_MENU_TITLE_SETTINGS_ICON));
            }
            cui_menu_set_currlist_flags(menu_cui_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
        
	  #ifndef __MMI_SECSET_SLIM_FOR_61__
		#ifndef __MMI_SECSET_APP_WITH_BWUI__
            chv1_is_enabled = srv_sim_ctrl_pwd_is_enabled(MMI_SIM2, SRV_SIM_CTRL_PWD_TYPE_CHV1);
            cui_menu_set_item_hint(
                menu_cui_id,
                MENU_ID_SECSET_SIM2_CHV1_LOCK,
                get_string(chv1_is_enabled ? STR_GLOBAL_ON : STR_GLOBAL_OFF));
		#endif
	  #endif/*__MMI_SECSET_SLIM_FOR_61__*/

            break;
#endif /* (MMI_MAX_SIM_NUM >= 2) */

#if (MMI_MAX_SIM_NUM >= 3)
        case MENU_ID_SECSET_SIM3_MENU:
        #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
            if (srv_sim_ctrl_get_num_of_inserted() <= 1)
            {
                mmi_secset_sim_set_title_for_single(menu_evt);
            }
            else
        #endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
            {
                cui_menu_set_currlist_title(
                    menu_cui_id,
                    get_string(STR_ID_SECSET_SIM3_SETTING),
                    get_image(MAIN_MENU_TITLE_SETTINGS_ICON));
            }
            cui_menu_set_currlist_flags(menu_cui_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
        
		#ifndef __MMI_SECSET_APP_WITH_BWUI__
            chv1_is_enabled = srv_sim_ctrl_pwd_is_enabled(MMI_SIM3, SRV_SIM_CTRL_PWD_TYPE_CHV1);
            cui_menu_set_item_hint(
                menu_cui_id,
                MENU_ID_SECSET_SIM3_CHV1_LOCK,
                get_string(chv1_is_enabled ? STR_GLOBAL_ON : STR_GLOBAL_OFF));
		#endif
            cui_menu_set_access_by_shortcut(menu_evt->sender_id, MMI_FALSE);
            break;
#endif /* MMI_MAX_SIM_NUM >= 3 */

#if (MMI_MAX_SIM_NUM == 4)
        case MENU_ID_SECSET_SIM4_MENU:
        #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
            if (srv_sim_ctrl_get_num_of_inserted() <= 1)
            {
                mmi_secset_sim_set_title_for_single(menu_evt);
            }
            else
        #endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
            {
                cui_menu_set_currlist_title(
                    menu_cui_id,
                    get_string(STR_ID_SECSET_SIM4_SETTING),
                    get_image(MAIN_MENU_TITLE_SETTINGS_ICON));
            }
            cui_menu_set_currlist_flags(menu_cui_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            
		#ifndef __MMI_SECSET_APP_WITH_BWUI__
            chv1_is_enabled = srv_sim_ctrl_pwd_is_enabled(MMI_SIM4, SRV_SIM_CTRL_PWD_TYPE_CHV1);
            cui_menu_set_item_hint(
                menu_cui_id,
                MENU_ID_SECSET_SIM4_CHV1_LOCK,
                get_string(chv1_is_enabled ? STR_GLOBAL_ON : STR_GLOBAL_OFF));
		#endif

            cui_menu_set_access_by_shortcut(menu_evt->sender_id, MMI_FALSE);            
            break;
#endif /* MMI_MAX_SIM_NUM == 4 */

        default:
            break;
    }

    return MMI_RET_OK;
}


static mmi_ret mmi_secset_sim_menu_on_highlight(const cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_id;
	#ifndef __MMI_SECSET_APP_WITH_BWUI__
    MMI_BOOL chv1_is_enabled;
	#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_id = menu_evt->sender_id;

#if (MMI_MAX_SIM_NUM >= 2)
    if (menu_evt->parent_menu_id == MENU_ID_SECSET_SIM1_MENU ||
        menu_evt->parent_menu_id == MENU_ID_SECSET_SIM2_MENU 
#if (MMI_MAX_SIM_NUM >= 3)
        ||menu_evt->parent_menu_id == MENU_ID_SECSET_SIM3_MENU 
#endif /* MMI_MAX_SIM_NUM >= 3 */
#if (MMI_MAX_SIM_NUM == 4)
        ||menu_evt->parent_menu_id == MENU_ID_SECSET_SIM4_MENU
#endif /* MMI_MAX_SIM_NUM == 4 */
        )
#else /*MMI_MAX_SIM_NUM >= 2 */
    if (menu_evt->parent_menu_id == MENU_ID_SECSET_SIM1_MENU)
#endif /* MMI_MAX_SIM_NUM >= 2 */
    {
     #ifdef __MMI_SECSET_SLIM_FOR_61__
	    if(menu_evt->highlighted_menu_id == MENU_ID_SECSET_SIM1_CHV1_LOCK)
			chv1_is_enabled = srv_sim_ctrl_pwd_is_enabled(MMI_SIM1, SRV_SIM_CTRL_PWD_TYPE_CHV1);
	  #if (MMI_MAX_SIM_NUM >= 2)
		if(menu_evt->highlighted_menu_id == MENU_ID_SECSET_SIM2_CHV1_LOCK)
			chv1_is_enabled = srv_sim_ctrl_pwd_is_enabled(MMI_SIM2, SRV_SIM_CTRL_PWD_TYPE_CHV1);
	  #endif

        if(menu_evt->highlighted_menu_id == MENU_ID_SECSET_SIM1_CHV1_LOCK 
		  #if (MMI_MAX_SIM_NUM >= 2)
			|| menu_evt->highlighted_menu_id == MENU_ID_SECSET_SIM2_CHV1_LOCK
		  #endif
			)
		   cui_menu_change_left_softkey_string(
                    menu_cui_id,
                    get_string(chv1_is_enabled ? STR_GLOBAL_OFF : STR_GLOBAL_ON));
		else
		   cui_menu_set_currlist_left_softkey(menu_cui_id, get_string(STR_GLOBAL_OK));	
	 #else
        switch (menu_evt->highlighted_menu_id)
        {
            case MENU_ID_SECSET_SIM1_CHV1_LOCK:
            #ifndef __MMI_SECSET_APP_WITH_BWUI__
                chv1_is_enabled = srv_sim_ctrl_pwd_is_enabled(MMI_SIM1, SRV_SIM_CTRL_PWD_TYPE_CHV1);
                
                cui_menu_change_left_softkey_string(
                    menu_cui_id,
                    get_string(chv1_is_enabled ? STR_GLOBAL_OFF : STR_GLOBAL_ON));
            #endif
                break;

#if (MMI_MAX_SIM_NUM >= 2)
            case MENU_ID_SECSET_SIM2_CHV1_LOCK:
			#ifndef __MMI_SECSET_APP_WITH_BWUI__	
                chv1_is_enabled = srv_sim_ctrl_pwd_is_enabled(MMI_SIM2, SRV_SIM_CTRL_PWD_TYPE_CHV1);
                
                cui_menu_change_left_softkey_string(
                    menu_cui_id,
                    get_string(chv1_is_enabled ? STR_GLOBAL_OFF : STR_GLOBAL_ON));
			#endif	
                
                break;
#endif /* MMI_MAX_SIM_NUM >= 2 */

#if (MMI_MAX_SIM_NUM >= 3)
            case MENU_ID_SECSET_SIM3_CHV1_LOCK:
			#ifndef __MMI_SECSET_APP_WITH_BWUI__	
                chv1_is_enabled = srv_sim_ctrl_pwd_is_enabled(MMI_SIM3, SRV_SIM_CTRL_PWD_TYPE_CHV1);
                
                cui_menu_change_left_softkey_string(
                    menu_cui_id,
                    get_string(chv1_is_enabled ? STR_GLOBAL_OFF : STR_GLOBAL_ON));
			#endif	
                
                break;
#endif /* MMI_MAX_SIM_NUM >= 3 */

#if (MMI_MAX_SIM_NUM == 4)			
	     case MENU_ID_SECSET_SIM4_CHV1_LOCK:
		 #ifndef __MMI_SECSET_APP_WITH_BWUI__ 	
                chv1_is_enabled = srv_sim_ctrl_pwd_is_enabled(MMI_SIM4, SRV_SIM_CTRL_PWD_TYPE_CHV1);
                
                cui_menu_change_left_softkey_string(
                    menu_cui_id,
                    get_string(chv1_is_enabled ? STR_GLOBAL_OFF : STR_GLOBAL_ON));
		 #endif
                
                break;
#endif /* MMI_MAX_SIM_NUM == 4 */

            default:
                cui_menu_set_currlist_left_softkey(menu_cui_id, get_string(STR_GLOBAL_OK));
                break;
        }
	 #endif/*__MMI_SECSET_SLIM_FOR_61__*/
    }

    return MMI_RET_OK;
}


static mmi_ret mmi_secset_sim_menu_on_selected(const cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->highlighted_menu_id)
    {
        case MENU_ID_SECSET_SIM1_CHV1_LOCK:
        #ifdef __MMI_SECSET_APP_WITH_BWUI__
        	mmi_secset_entry_sim_switch_chv1_menu(MMI_SIM1);
        #else
            mmi_secset_sim_set_chv1_enabled(MMI_SIM1);
        #endif
            break;
            
        case MENU_ID_SECSET_SIM1_CHANGE_CHV1:
            mmi_secset_sim_change_chv(MMI_SIM1, SRV_SIM_CTRL_PWD_TYPE_CHV1);
            break;

        case MENU_ID_SECSET_SIM1_CHANGE_CHV2:
            mmi_secset_sim_change_chv(MMI_SIM1, SRV_SIM_CTRL_PWD_TYPE_CHV2);
            break;

#if (MMI_MAX_SIM_NUM >= 2)
        case MENU_ID_SECSET_SIM2_CHV1_LOCK:
	    #ifdef __MMI_SECSET_APP_WITH_BWUI__
        	mmi_secset_entry_sim_switch_chv1_menu(MMI_SIM2);
        #else
            mmi_secset_sim_set_chv1_enabled(MMI_SIM2);
		#endif
            break;

        case MENU_ID_SECSET_SIM2_CHANGE_CHV1:
            mmi_secset_sim_change_chv(MMI_SIM2, SRV_SIM_CTRL_PWD_TYPE_CHV1);
            break;

        case MENU_ID_SECSET_SIM2_CHANGE_CHV2:
            mmi_secset_sim_change_chv(MMI_SIM2, SRV_SIM_CTRL_PWD_TYPE_CHV2);
            break;
#endif /* (MMI_MAX_SIM_NUM >= 2) */

#if (MMI_MAX_SIM_NUM >= 3)
        case MENU_ID_SECSET_SIM3_CHV1_LOCK:
	    #ifdef __MMI_SECSET_APP_WITH_BWUI__
        	mmi_secset_entry_sim_switch_chv1_menu(MMI_SIM3);
        #else
            mmi_secset_sim_set_chv1_enabled(MMI_SIM3);
		#endif
            break;

        case MENU_ID_SECSET_SIM3_CHANGE_CHV1:
            mmi_secset_sim_change_chv(MMI_SIM3, SRV_SIM_CTRL_PWD_TYPE_CHV1);
            break;

        case MENU_ID_SECSET_SIM3_CHANGE_CHV2:
            mmi_secset_sim_change_chv(MMI_SIM3, SRV_SIM_CTRL_PWD_TYPE_CHV2);
            break;
#endif /* (MMI_MAX_SIM_NUM >= 3) */

#if (MMI_MAX_SIM_NUM == 4)
	 case MENU_ID_SECSET_SIM4_CHV1_LOCK:
	 	#ifdef __MMI_SECSET_APP_WITH_BWUI__
        	mmi_secset_entry_sim_switch_chv1_menu(MMI_SIM4);
        #else
            mmi_secset_sim_set_chv1_enabled(MMI_SIM4);
		#endif
            break;

        case MENU_ID_SECSET_SIM4_CHANGE_CHV1:
            mmi_secset_sim_change_chv(MMI_SIM4, SRV_SIM_CTRL_PWD_TYPE_CHV1);
            break;

        case MENU_ID_SECSET_SIM4_CHANGE_CHV2:
            mmi_secset_sim_change_chv(MMI_SIM4, SRV_SIM_CTRL_PWD_TYPE_CHV2);
            break;
#endif /* (MMI_MAX_SIM_NUM == 4) */

        default:
            break;
    }

    return MMI_RET_OK;
}


static void mmi_secset_sim_set_chv1_enabled(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_sim_cntx_struct *cntx;
    WCHAR *remaining_attempts_prompt;
    WCHAR input_prompt[MMI_SECSET_SIM_MAX_STR_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = &g_mmi_secset_sim_cntx;
    
    cntx->sim = sim;
    cntx->chv_type = SRV_SIM_CTRL_PWD_TYPE_CHV1;

    /* We should not show SIM menu if SIM is unavailable due to CHV1 blocked */
    MMI_ASSERT(!srv_sim_ctrl_pwd_is_blocked(cntx->sim, cntx->chv_type));

    mmi_secset_sim_get_string(
        cntx->sim,
        cntx->chv_type,
        MMI_SECSET_STR_INPUT_CHV,
        input_prompt,
        MMI_SECSET_SIM_MAX_STR_LEN);
    cntx->set_chv_lock_cui = cui_pwd_basic_create_dynamic_str(
        GRP_ID_SECSET,
        input_prompt,
        MMI_SECSET_MIN_CHV_LEN,
        MMI_SECSET_MAX_CHV_LEN);
    cui_pwd_basic_set_proc(cntx->set_chv_lock_cui, mmi_secset_sim_set_chv_lock_input_proc, cntx);
#if 0
#if defined(UI_SMALL_PIN_EDITOR_SCREEN) && !defined(__MMI_FTE_SUPPORT__)
/* under construction !*/
#endif
#endif
    cui_pwd_basic_set_action_str(cntx->set_chv_lock_cui, STR_GLOBAL_OK, STR_GLOBAL_BACK);

    remaining_attempts_prompt = (WCHAR*)mmi_malloc((CUI_PWD_MAX_EXTRA_MSG_STR_LEN + 30) * sizeof(WCHAR));
    mmi_secset_n_attempts_to_str(
        srv_sim_ctrl_get_n_remaining_attempts(cntx->sim, cntx->chv_type),
        remaining_attempts_prompt,
        CUI_PWD_MAX_EXTRA_MSG_STR_LEN);
    cui_pwd_basic_set_extra_msg(cntx->set_chv_lock_cui, remaining_attempts_prompt);
    mmi_mfree(remaining_attempts_prompt);
    
    cui_pwd_basic_run(cntx->set_chv_lock_cui);
}


static mmi_ret mmi_secset_sim_set_chv_lock_input_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_sim_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_secset_sim_cntx_struct*)evt->user_data;

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_PWD_BASIC_DONE:
        {
            cui_pwd_basic_done_evt_struct *done_evt;
            MMI_BOOL target_value;

            done_evt = (cui_pwd_basic_done_evt_struct*)evt;
			target_value = srv_sim_ctrl_pwd_is_enabled(cntx->sim, cntx->chv_type)? MMI_FALSE: MMI_TRUE;

            MMI_TRACE(MMI_SECSET_TRC_GROUP, TRC_MMI_SECSET_SIM_SET_CHV_LOCK_INPUT_DONE,
                cntx->sim, cntx->chv_type, target_value);
            
            if (srv_sim_ctrl_set_enabled(
                    cntx->sim,
                    cntx->chv_type,
                    done_evt->input,
                    target_value,
                    mmi_secset_sim_set_or_change_chv_result_proc,
                    cntx) > 0)
            {
                mmi_secset_show_waiting(GRP_ID_SECSET);
            }
            else
            {
                mmi_popup_display_simple(
                    get_string(STR_ID_SECSET_TEMP_FAIL),
                    MMI_EVENT_FAILURE,
                    GRP_ID_SECSET,
                    cntx);
                cui_pwd_basic_close(cntx->set_chv_lock_cui);
                cntx->set_chv_lock_cui = 0;
            }
        
            break;
        }

        case EVT_ID_CUI_PWD_BASIC_CANCEL:
            cui_pwd_basic_close(cntx->set_chv_lock_cui);
            cntx->set_chv_lock_cui = 0;
            break;
            
        case EVT_ID_CUI_PWD_BASIC_PASSIVE_CLOSING:
            cntx->set_chv_lock_cui = 0;
            /* Allow closing */
            break;
    }

    return MMI_RET_OK;
}


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


static void mmi_secset_sim_change_chv(mmi_sim_enum sim, srv_sim_ctrl_pwd_type_enum chv_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_sim_cntx_struct *cntx;
    WCHAR *remaining_attempts_prompt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(chv_type == SRV_SIM_CTRL_PWD_TYPE_CHV1 ||
        chv_type == SRV_SIM_CTRL_PWD_TYPE_CHV2);
        
    cntx = &g_mmi_secset_sim_cntx;

    if (srv_sim_ctrl_pwd_is_blocked(sim, chv_type))
    {
        srv_sim_ctrl_pwd_type_enum corr_ubchv_type;

        cntx->sim = sim;
        cntx->chv_type = chv_type;

        if (chv_type == SRV_SIM_CTRL_PWD_TYPE_CHV1)
        {
            corr_ubchv_type = SRV_SIM_CTRL_PWD_TYPE_UBCHV1;
        }
        else
        {
            corr_ubchv_type = SRV_SIM_CTRL_PWD_TYPE_UBCHV2;
        }
    
        if (srv_sim_ctrl_pwd_is_blocked(sim, corr_ubchv_type))
        {
           mmi_secset_sim_display_popup(
                sim,
                corr_ubchv_type,
                MMI_SECSET_STR_UBCHV_BLOCKED,
                MMI_EVENT_FAILURE,
                GRP_ID_SECSET,
                cntx);
        }
        else
        {
            mmi_secset_sim_popup_chv_blocked(cntx);
        }
    }
    else if (!srv_sim_ctrl_pwd_is_enabled(sim, chv_type))
    {
       mmi_secset_sim_display_popup(
            sim,
            chv_type,
            MMI_SECSET_STR_CHV_DISABLED,
            MMI_EVENT_FAILURE,
            GRP_ID_SECSET,
            cntx);
    }
    else
    {
        WCHAR *old_chv_prompt, *new_chv_prompt, *confirm_chv_prompt;
    
        cntx->sim = sim;
        cntx->chv_type = chv_type;

        old_chv_prompt = (WCHAR*)mmi_malloc((MMI_SECSET_SIM_MAX_STR_LEN + 1) * 3 * sizeof(WCHAR));
        new_chv_prompt = old_chv_prompt + MMI_SECSET_SIM_MAX_STR_LEN + 1;
        confirm_chv_prompt = new_chv_prompt + MMI_SECSET_SIM_MAX_STR_LEN + 1;
        mmi_secset_sim_get_string(
            cntx->sim,
            cntx->chv_type,
            MMI_SECSET_STR_OLD_CHV,
            old_chv_prompt,
            MMI_SECSET_SIM_MAX_STR_LEN);
        mmi_secset_sim_get_string(
            cntx->sim,
            cntx->chv_type,
            MMI_SECSET_STR_NEW_CHV,
            new_chv_prompt,
            MMI_SECSET_SIM_MAX_STR_LEN);
        mmi_secset_sim_get_string(
            cntx->sim,
            cntx->chv_type,
            MMI_SECSET_STR_CONFIRM_CHV,
            confirm_chv_prompt,
            MMI_SECSET_SIM_MAX_STR_LEN);
            
        cntx->change_pwd_cui = cui_pwd_guard_create_dynamic_str(
            GRP_ID_SECSET,
            old_chv_prompt,
            new_chv_prompt,
            confirm_chv_prompt,
            MMI_SECSET_MIN_CHV_LEN,
            MMI_SECSET_MAX_CHV_LEN,
            MMI_SECSET_MIN_CHV_LEN,
            MMI_SECSET_MAX_CHV_LEN);
        cui_pwd_guard_set_proc(cntx->change_pwd_cui, mmi_secset_sim_change_chv_input_proc, cntx);
        if (chv_type == SRV_SIM_CTRL_PWD_TYPE_CHV1 || chv_type == SRV_SIM_CTRL_PWD_TYPE_UBCHV1)
        {
            cui_pwd_guard_set_diff_input_prompt(cntx->change_pwd_cui, STR_ID_SECSET_CHV1_NOT_MATCH);
        }
        else
        {
            cui_pwd_guard_set_diff_input_prompt(cntx->change_pwd_cui, STR_ID_SECSET_CHV2_NOT_MATCH);
        }
        
        /* Set # of remaining attempts message */
        remaining_attempts_prompt = (WCHAR*)mmi_malloc(
            (CUI_PWD_MAX_EXTRA_MSG_STR_LEN + 30) * sizeof(WCHAR));
        mmi_secset_n_attempts_to_str(
            srv_sim_ctrl_get_n_remaining_attempts(cntx->sim, cntx->chv_type),
            remaining_attempts_prompt,
            CUI_PWD_MAX_EXTRA_MSG_STR_LEN);
        cui_pwd_guard_set_guard_extra_msg(cntx->change_pwd_cui, remaining_attempts_prompt);
        mmi_mfree(remaining_attempts_prompt);

        cui_pwd_guard_run(cntx->change_pwd_cui);

        mmi_mfree(old_chv_prompt);
    }
}


static mmi_ret mmi_secset_sim_change_chv_input_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_sim_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cntx = (mmi_secset_sim_cntx_struct*)evt->user_data;
    
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_PWD_GUARD_DONE:
        {
            cui_pwd_guard_done_evt_struct *done_evt;

            done_evt = (cui_pwd_guard_done_evt_struct*)evt;

            MMI_TRACE(MMI_SECSET_TRC_GROUP, TRC_MMI_SECSET_SIM_CHANGE_CHV_INPUT_DONE,
                cntx->sim, cntx->chv_type);
        
            if (srv_sim_ctrl_change_password(
                    cntx->sim,
                    cntx->chv_type,
                    done_evt->guard,
                    done_evt->input,
                    mmi_secset_sim_set_or_change_chv_result_proc,
                    cntx) > 0)
            {
                mmi_secset_show_waiting(GRP_ID_SECSET);
            }
            else
            {
                mmi_popup_display_simple(
                    get_string(STR_ID_SECSET_TEMP_FAIL),
                    MMI_EVENT_FAILURE,
                    GRP_ID_SECSET,
                    cntx);
                cui_pwd_guard_close(cntx->change_pwd_cui);
                cntx->change_pwd_cui = 0;
            }
                
            break;
        }

        case EVT_ID_CUI_PWD_GUARD_CANCEL:
            cui_pwd_guard_close(cntx->change_pwd_cui);
            cntx->change_pwd_cui = 0;
            break;

        case EVT_ID_CUI_PWD_GUARD_PASSIVE_CLOSING:
            /* Allow closing */
            cntx->change_pwd_cui = 0;
            break;
    }

    return MMI_RET_OK;
}


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
static mmi_ret mmi_secset_sim_set_or_change_chv_result_proc(mmi_event_struct * evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_sim_cntx_struct *cntx;
    srv_sim_ctrl_set_enabled_result_evt_struct *result_evt;
    WCHAR *remaining_attempts_prompt;
    U16 str_id = 0;
    mmi_id *ptr_instance_id = NULL;
    
    void (*cui_pwd_close)(mmi_id instance_id) = NULL;
    void (*cui_pwd_reset)(mmi_id instance_id) = NULL;
    void (*cui_pwd_set_extra_msg)(mmi_id instance_id, const WCHAR *extra_msg) = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_secset_sim_cntx_struct*)evt->user_data;

    mmi_secset_close_waiting(GRP_ID_SECSET); 

    result_evt = (srv_sim_ctrl_set_enabled_result_evt_struct*)evt;

    MMI_TRACE(MMI_SECSET_TRC_GROUP, TRC_MMI_SECSET_SIM_SET_OR_CHANGE_CHV_RESULT,
        result_evt->success, result_evt->fail_cause, result_evt->sim, result_evt->type);

    switch(evt->evt_id)
    {

        case EVT_ID_SRV_SIM_CTRL_SET_ENABLED_RESULT:
            ptr_instance_id = &cntx->set_chv_lock_cui;
            cui_pwd_close = cui_pwd_basic_close;
            cui_pwd_reset = cui_pwd_basic_reset;
            cui_pwd_set_extra_msg = cui_pwd_basic_set_extra_msg;
            str_id = (result_evt->is_enabled ? STR_ID_SECSET_LOCKED : STR_ID_SECSET_UNLOCKED);
            
            break;

        case EVT_ID_SRV_SIM_CTRL_CHANGE_PASSWORD_RESULT:
            ptr_instance_id = &cntx->change_pwd_cui;
            cui_pwd_close = cui_pwd_guard_close;
            cui_pwd_reset = cui_pwd_guard_reset;
            cui_pwd_set_extra_msg = cui_pwd_guard_set_guard_extra_msg;
            str_id = STR_GLOBAL_DONE;         
               
            break;

    }

    if (*ptr_instance_id == 0)
    {
        /* Screen may be closed during the processing */
        return MMI_RET_OK;
    }
    
    if (result_evt->success)
    {
        mmi_popup_display_simple(
        get_string(str_id),
            MMI_EVENT_SUCCESS,
            GRP_ID_SECSET,
            cntx);
        cui_pwd_close(*ptr_instance_id);
        *ptr_instance_id = 0;
    }
    else if (result_evt->fail_cause == SRV_SIM_CTRL_FAIL_CAUSE_WRONG_PASSWORD)
    {
        if (srv_sim_ctrl_pwd_is_blocked(result_evt->sim, cntx->chv_type))
        {
            mmi_secset_sim_popup_chv_blocked(cntx);

            cui_pwd_close(*ptr_instance_id);
            *ptr_instance_id = 0;
        }
        else
        {
            /* Update # of remaining attempts message */
            remaining_attempts_prompt = (WCHAR*)mmi_malloc(
                (CUI_PWD_MAX_EXTRA_MSG_STR_LEN + 30) * sizeof(WCHAR));
            mmi_secset_n_attempts_to_str(
            srv_sim_ctrl_get_n_remaining_attempts(cntx->sim, cntx->chv_type),
                remaining_attempts_prompt,
                CUI_PWD_MAX_EXTRA_MSG_STR_LEN);
            cui_pwd_set_extra_msg(*ptr_instance_id, remaining_attempts_prompt);
            mmi_mfree(remaining_attempts_prompt);

            mmi_secset_sim_display_popup(
                result_evt->sim,
                result_evt->type,
                MMI_SECSET_STR_WRONG_CHV,
                MMI_EVENT_FAILURE,
                GRP_ID_SECSET,
                cntx);

            cui_pwd_reset(*ptr_instance_id);
        }
    }
    else
    {
        mmi_secset_sim_display_error_popup(
            result_evt->sim,
            result_evt->type,
            result_evt->fail_cause,
            GRP_ID_SECSET,
            cntx);
            
        cui_pwd_close(*ptr_instance_id);
        *ptr_instance_id = 0;
    }


    return MMI_RET_OK;
}


static void mmi_secset_sim_popup_chv_blocked(mmi_secset_sim_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx->chv_type == SRV_SIM_CTRL_PWD_TYPE_CHV1)
    {
        mmi_secset_hpveri_display_ubchv1(GRP_ID_SECSET, cntx->sim);
    }
    else if (cntx->chv_type == SRV_SIM_CTRL_PWD_TYPE_CHV2)
    {
        WCHAR message[MMI_SECSET_SIM_MAX_STR_LEN + 1];
        
        mmi_secset_sim_get_string(
            cntx->sim,
            cntx->chv_type,
            MMI_SECSET_STR_CHV_BLOCKED,
            message,
            MMI_SECSET_SIM_MAX_STR_LEN);
    
        if (srv_sim_ctrl_pwd_is_blocked(cntx->sim, SRV_SIM_CTRL_PWD_TYPE_UBCHV2))
        {
            /* Only popup, not show UBCHV screen */
            mmi_popup_display_simple(
                message,
                MMI_EVENT_FAILURE,
                GRP_ID_SECSET,
                cntx);
        }
        else
        {
            mmi_popup_property_struct popup_arg;
        
            mmi_popup_property_init(&popup_arg);
            popup_arg.parent_id = GRP_ID_SECSET;
            popup_arg.callback = mmi_secset_sim_show_ubchv_after_popup;
            popup_arg.user_tag = cntx;

	    #ifndef __MMI_SECSET_SLIM_FOR_61__
            if (!mmi_popup_display(
                    message,
                    MMI_EVENT_FAILURE,
                    &popup_arg))
            {
                mmi_secset_sim_show_ubchv(cntx, cntx->sim, cntx->chv_type);
            }
	    #else if
		    mmi_popup_display(message,MMI_EVENT_FAILURE,&popup_arg);
		#endif/*__MMI_SECSET_SLIM_FOR_61__*/
        }
    }
}


static mmi_ret mmi_secset_sim_show_ubchv_after_popup(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_sim_cntx_struct *cntx;
    mmi_alert_result_evt_struct *popup_evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_POPUP_QUIT)
    {
        popup_evt = (mmi_alert_result_evt_struct*)evt;
        cntx = (mmi_secset_sim_cntx_struct*)popup_evt->user_tag;
        if (mmi_frm_group_is_present(GRP_ID_SECSET))
        {
            mmi_secset_sim_show_ubchv(cntx, cntx->sim, cntx->chv_type);
        }
    }

    return MMI_RET_OK;
}


static void mmi_secset_sim_show_ubchv(
                mmi_secset_sim_cntx_struct *cntx,
                mmi_sim_enum sim,
                srv_sim_ctrl_pwd_type_enum chv_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->sim = sim;
    
  #ifndef __MMI_SECSET_SLIM_FOR_61__
    if (chv_type == SRV_SIM_CTRL_PWD_TYPE_CHV2 ||
        chv_type == SRV_SIM_CTRL_PWD_TYPE_UBCHV2)
    {
        cntx->chv_type = SRV_SIM_CTRL_PWD_TYPE_UBCHV2;
    }
    else
    {
        MMI_ASSERT(0);
    }
  #else
    cntx->chv_type = SRV_SIM_CTRL_PWD_TYPE_UBCHV2;
  #endif/*__MMI_SECSET_SLIM_FOR_61__*/

    if (srv_sim_ctrl_pwd_is_blocked(sim, cntx->chv_type))
    {
        /* No next screen after popup */
        return;
    }

    /* Check the status again, something may change during the popup */
    cntx->ubchv_handle = mmi_secset_ubchv_create(
        GRP_ID_SECSET,
        cntx->sim,
        cntx->chv_type,
        mmi_secset_sim_ubchv_proc,
        cntx);

    mmi_secset_ubchv_run(cntx->ubchv_handle);
}


static mmi_ret mmi_secset_sim_ubchv_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_sim_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_secset_sim_cntx_struct*)evt->user_data;

    if (cntx->ubchv_handle == MMI_SECSET_UBCHV_INVALID_HANDLE)
    {
        /* Screen may be closed during the processing */
        return MMI_RET_OK;
    }
    
    switch (evt->evt_id)
    {
        case EVT_ID_SECSET_UBCHV_UNBLOCKED:
            mmi_popup_display_simple(
                get_string(STR_GLOBAL_DONE),
                MMI_EVENT_SUCCESS,
                GRP_ID_SECSET,
                cntx);
            mmi_secset_ubchv_close(cntx->ubchv_handle);
            cntx->ubchv_handle = MMI_SECSET_UBCHV_INVALID_HANDLE;
            break;
        
        case EVT_ID_SECSET_UBCHV_BLOCKED:
            mmi_secset_sim_display_popup(
                cntx->sim,
                cntx->chv_type,
                MMI_SECSET_STR_UBCHV_BLOCKED,
                MMI_EVENT_FAILURE,
                GRP_ID_SECSET,
                cntx);
            mmi_secset_ubchv_close(cntx->ubchv_handle);
            cntx->ubchv_handle = MMI_SECSET_UBCHV_INVALID_HANDLE;
            break;
            
        case EVT_ID_SECSET_UBCHV_SIM_ERROR:
            mmi_secset_sim_display_popup(
                cntx->sim,
                cntx->chv_type,
                MMI_SECSET_STR_SIM_ERROR,
                MMI_EVENT_FAILURE,
                GRP_ID_SECSET,
                cntx);
            mmi_secset_ubchv_close(cntx->ubchv_handle);
            cntx->ubchv_handle = MMI_SECSET_UBCHV_INVALID_HANDLE;
            break;
    
        case EVT_ID_SECSET_UBCHV_CANCEL:
            mmi_secset_ubchv_close(cntx->ubchv_handle);
            cntx->ubchv_handle = MMI_SECSET_UBCHV_INVALID_HANDLE;
            break;

        case EVT_ID_SECSET_UBCHV_PASSIVE_CLOSING:
            cntx->ubchv_handle = MMI_SECSET_UBCHV_INVALID_HANDLE;
            break;
    }

    return MMI_RET_OK;
}

#ifdef __MMI_AP_DCM_SECSET__
#pragma arm section rodata , code
#endif


void mmi_secset_sim_close_screens_of_type(mmi_sim_enum sim, srv_sim_ctrl_pwd_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_sim_cntx_struct *cntx;
    MMI_BOOL type_match = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = &g_mmi_secset_sim_cntx;
    
    if (!mmi_frm_group_is_present(GRP_ID_SECSET))
    {
        return;
    }

    if (cntx->sim != sim)
    {
        return;
    }

  #ifndef __MMI_SECSET_SLIM_FOR_61__
    //type_match = MMI_FALSE;
    if ((type == SRV_SIM_CTRL_PWD_TYPE_CHV1 || type == SRV_SIM_CTRL_PWD_TYPE_UBCHV1) &&
        (cntx->chv_type == SRV_SIM_CTRL_PWD_TYPE_CHV1 || cntx->chv_type == SRV_SIM_CTRL_PWD_TYPE_UBCHV1))
    {
        type_match = MMI_TRUE;
    }
    else if ((type == SRV_SIM_CTRL_PWD_TYPE_CHV2 || type == SRV_SIM_CTRL_PWD_TYPE_UBCHV2) &&
        (cntx->chv_type == SRV_SIM_CTRL_PWD_TYPE_CHV2 || cntx->chv_type == SRV_SIM_CTRL_PWD_TYPE_UBCHV2))
    {
        type_match = MMI_TRUE;
    }
  #else
    if ((type == SRV_SIM_CTRL_PWD_TYPE_CHV2 || type == SRV_SIM_CTRL_PWD_TYPE_UBCHV2) &&
        (cntx->chv_type == SRV_SIM_CTRL_PWD_TYPE_CHV2 || cntx->chv_type == SRV_SIM_CTRL_PWD_TYPE_UBCHV2))
    {
        type_match = MMI_TRUE;
    }
  #endif

    if (!type_match)
    {
        return;
    }

    if (cntx->set_chv_lock_cui != 0)
    {
        cui_pwd_basic_close(cntx->set_chv_lock_cui);
        cntx->set_chv_lock_cui = 0;
    }
    if (cntx->change_pwd_cui != 0)
    {
        cui_pwd_guard_close(cntx->change_pwd_cui);
        cntx->change_pwd_cui = 0;
    }
    if (cntx->ubchv_handle != MMI_SECSET_UBCHV_INVALID_HANDLE)
    {
        mmi_secset_ubchv_close(cntx->ubchv_handle);
        cntx->ubchv_handle = MMI_SECSET_UBCHV_INVALID_HANDLE;
    }

    cntx->sim = MMI_SIM_NONE;
}


static void mmi_secset_sim_close_related_screens(
    mmi_secset_sim_cntx_struct *cntx,
    mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx->sim != sim)
    {
        return;
    }

    if (cntx->submenu_cui != 0)
    {
        cui_menu_close(cntx->submenu_cui);
        cntx->submenu_cui = 0;
    }
    if (cntx->set_chv_lock_cui != 0)
    {
        cui_pwd_basic_close(cntx->set_chv_lock_cui);
        cntx->set_chv_lock_cui = 0;
    }
    if (cntx->change_pwd_cui != 0)
    {
        cui_pwd_guard_close(cntx->change_pwd_cui);
        cntx->change_pwd_cui = 0;
    }
    if (cntx->ubchv_handle != MMI_SECSET_UBCHV_INVALID_HANDLE)
    {
        mmi_secset_ubchv_close(cntx->ubchv_handle);
        cntx->ubchv_handle = MMI_SECSET_UBCHV_INVALID_HANDLE;
    }

    cntx->sim = MMI_SIM_NONE;
}


mmi_ret mmi_secset_on_sim_availability_changed(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_availability_changed_evt_struct *availability_changed;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    availability_changed = (srv_sim_ctrl_availability_changed_evt_struct*)evt;

    MMI_TRACE(MMI_SECSET_TRC_GROUP, TRC_MMI_SECSET_SIM_AVAILABILITY_CHANGED,
        availability_changed->sim,
        availability_changed->is_available_before, availability_changed->unavailable_cause_before,
        availability_changed->is_available_now, availability_changed->unavailable_cause);

    mmi_secset_hpveri_on_sim_availability_changed(evt);

    if (!availability_changed->is_available_now)
    {
        mmi_secset_sim_cntx_struct *cntx;
    
        cntx = &g_mmi_secset_sim_cntx;
        mmi_secset_sim_close_related_screens(cntx, availability_changed->sim);
    }

    return MMI_RET_OK;
}


#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
mmi_ret mmi_secset_sim_on_event_detected(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_event_detected_evt_struct *detected_evt;
    mmi_secset_sim_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    detected_evt = (srv_sim_ctrl_event_detected_evt_struct*)evt;
    cntx = &g_mmi_secset_sim_cntx;

    switch (detected_evt->type)
    {
        case SRV_SIM_CTRL_EVENT_DET_REMOVED:
        case SRV_SIM_CTRL_EVENT_DET_INSERTED:
        case SRV_SIM_CTRL_EVENT_DET_RECOVERY_START:
        case SRV_SIM_CTRL_EVENT_DET_RECOVERY_END:
            /* Close all SIM related screens directly */
            if (cntx->submenu_cui != 0)
            {
                cui_menu_close(cntx->submenu_cui);
                cntx->submenu_cui = 0;
            }
            if (cntx->set_chv_lock_cui != 0)
            {
                cui_pwd_basic_close(cntx->set_chv_lock_cui);
                cntx->set_chv_lock_cui = 0;
            }
            if (cntx->change_pwd_cui != 0)
            {
                cui_pwd_guard_close(cntx->change_pwd_cui);
                cntx->change_pwd_cui = 0;
            }
            if (cntx->ubchv_handle != MMI_SECSET_UBCHV_INVALID_HANDLE)
            {
                mmi_secset_ubchv_close(cntx->ubchv_handle);
                cntx->ubchv_handle = MMI_SECSET_UBCHV_INVALID_HANDLE;
            }

            cntx->sim = MMI_SIM_NONE;

            mmi_secset_hpveri_on_sim_number_changed(evt);
            
            break;
    }

    return MMI_RET_OK;
}
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */


#ifdef __MMI_SECSET_APP_WITH_BWUI__

static mmi_ret mmi_secset_sim_switch_chv1_grp_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt;
    mmi_menu_id CurrentMenu;
    mmi_secset_sim_chv1_cntx_struct   *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	cntx = (mmi_secset_sim_chv1_cntx_struct *) evt->user_data;
    CurrentMenu=(srv_sim_ctrl_pwd_is_enabled(cntx->sim, SRV_SIM_CTRL_PWD_TYPE_CHV1))?MENU_ID_SECURITY_SETTING_ON : MENU_ID_SECURITY_SETTING_OFF;

    if (cui_menu_is_menu_event(evt->evt_id))
    {
        menu_evt = (cui_menu_event_struct*)evt;

        switch (menu_evt->evt_id)
        {
            case EVT_ID_CUI_MENU_LIST_ENTRY:
                if (menu_evt->parent_menu_id == MENU_ID_SECSET_SIMX_CHV1_LOCK[mmi_frm_sim_to_index(cntx->sim)])
                {
                    cui_menu_set_currlist_title(
                        menu_evt->sender_id,
                        get_string(STR_ID_SECSET_CHV1_LOCK),
                        get_image(MAIN_MENU_TITLE_SETTINGS_ICON));

                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
                    cui_menu_set_radio_list_item(menu_evt->sender_id, CurrentMenu);

                }
                break;
                
            case EVT_ID_CUI_MENU_ITEM_SELECT:
                if(menu_evt->highlighted_menu_id != CurrentMenu && !srv_sim_ctrl_pwd_is_blocked(cntx->sim, SRV_SIM_CTRL_PWD_TYPE_CHV1))
                {
                   	mmi_secset_sim_set_chv1_enabled(cntx->sim);
                }
                else
                {
                    cui_menu_close(menu_evt->sender_id);
                }

                break;

            case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            {
                if (menu_evt->sender_id == g_mmi_secset_sim_chv1_cntx.submenu_cui)
                {
                    g_mmi_secset_sim_chv1_cntx.submenu_cui = 0;
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


static void mmi_secset_entry_sim_switch_chv1_menu(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_sim_chv1_cntx_struct   *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = &g_mmi_secset_sim_chv1_cntx;
	cntx->sim = sim;
    
    mmi_frm_group_create_ex(
        GRP_ID_SECSET,
        GRP_ID_SECSET_SIM_SWITCH_CHV1,
        mmi_secset_sim_switch_chv1_grp_proc,
        cntx,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    
    cntx->submenu_cui = cui_menu_create_and_run(
        GRP_ID_SECSET_SIM_SWITCH_CHV1,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_FROM_RESOURCE,
        MENU_ID_SECSET_SIMX_CHV1_LOCK[mmi_frm_sim_to_index(sim)],
        MMI_TRUE,
        cntx);

}
#endif /* __MMI_SECSET_APP_WITH_BWUI__ */
#endif/*#if defined(__MMI_TELEPHONY_SUPPORT__)*/
