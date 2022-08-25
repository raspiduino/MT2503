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
 * NetSetAppProt.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file is defines internal interface of network setup application.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __NETSET_APP_PROT_H__
#define __NETSET_APP_PROT_H__

#include "MMI_features.h"

#include "MMIDataType.h"

#include "L4c_common_enum.h"    /* for MAX_PLMN_LIST_LEN */
#include "MenuCuiGprot.h"

/* auto add by kw_check begin */
#include "l4c_aux_struct.h"
#include "mmi_msg_struct.h"
#include "kal_non_specific_general_types.h"
/* auto add by kw_check end */
#include "PhoneSetupSlim.h"
/***************************************************************************** 
* Typedef for Network Setup
*****************************************************************************/
typedef struct
{
    U8 select_mode;
    U8 rat;

    U8 reg_fail_flag;
    U8 sel_plmn_index;
    l4c_rat_plmn_info_struct sel_plmn;
    //U16 NoOfPLMNSupported;
    //U8 PowerOnNWStatus;
#ifndef __MMI_NETSET_SLIM__
    /* forbid PLMN list for register failed */
    U8 forbid_mark[MAX_PLMN_LIST_LEN];
    l4c_rat_plmn_info_struct forbid_plmn[MAX_PLMN_LIST_LEN];
#endif

    /* temp point to PLMN list response message */
    mmi_nw_get_plmn_list_rsp_struct *plmn_list;
    
#ifdef __MMI_GPRS_FEATURES__
    U8 gprs;
#endif /* __MMI_GPRS_FEATURES__ */

#if 0
#if defined(__OP12__) && defined(__NBR_CELL_INFO__)
/* under construction !*/
#endif /* #if defined(__OP12__) && defined(__NBR_CELL_INFO__) */
#endif

#ifdef __MONITOR_PAGE_DURING_TRANSFER__
    U8 pch_status;
#endif /* __MONITOR_PAGE_DURING_TRANSFER__ */

#ifdef __UMTS_FDD_MODE__
#ifdef __HSPA_PREFERENCE_SETTING__
#ifdef __DYNAMIC_HSPA_PREFERENCE__
	U8 hspa_status;
#endif /* __DYNAMIC_HSPA_PREFERENCE__ */
#endif /* __HSPA_PREFERENCE_SETTING__ */
#endif
} mmi_netset_cntx_struct;


typedef struct  
{
    U16 *plmn_mark_icons;
    U8 *plmn_name[MAX_PLMN_LIST_LEN];
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
/* under construction !*/
#endif /* defined(__GSM_RAT__) && defined(__UMTS_RAT__) */ 

} mmi_netset_nw_search_disp_cntx_struct;

extern mmi_netset_cntx_struct *g_netset_cntx_ptr;

/***************************************************************************** 
* External Function
*****************************************************************************/
/* get network subitem status */
extern void mmi_netset_retrieve_sim_menu_data(void);

#ifdef __MMI_GPRS_FEATURES__
extern MMI_BOOL mmi_netset_is_gprs_connection_setting_available(mmi_sim_enum sim);
extern void mmi_netset_get_gprs_mode_req(void);
#endif /* __MMI_GPRS_FEATURES__ */

#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
/* under construction !*/
#endif /* #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) */

#ifdef __UMTS_FDD_MODE__
#ifdef __HSPA_PREFERENCE_SETTING__
#ifdef __DYNAMIC_HSPA_PREFERENCE__
extern MMI_BOOL mmi_netset_is_hspa_setting_available(void);
extern void mmi_netset_get_hspa_status_req(void);
#endif /* __DYNAMIC_HSPA_PREFERENCE__ */
#endif /* __HSPA_PREFERENCE_SETTING__ */
#endif

#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
/* under construction !*/
#ifdef __UMTS_FDD_MODE__
/* under construction !*/
#endif
/* under construction !*/
#ifdef __UMTS_TDD128_MODE__
/* under construction !*/
#endif
/* under construction !*/
#else /* #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) */
#define STR_ID_NETSET_ITEM_3G STR_ID_NETSET_ITEM_WCDMA
#endif /* #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) */

/* get current SIM */
extern mmi_sim_enum mmi_netset_get_active_sim(void);

#define MMI_NETSET_CURRENT_SIM mmi_netset_get_active_sim()

extern MMI_ID mmi_netset_get_sub_menu_id(void);

#ifdef __MMI_WLAN_FEATURES__
extern void mmi_netset_entry_pref_mode(mmi_id parent_gid);
#endif
/* Network Setup MENU CUI API */
extern MMI_BOOL mmi_netsel_is_available_to_entry(void);
#ifdef __MANUAL_MODE_NW_SEL__
extern void mmi_entry_netsel_select_mode(cui_menu_event_struct* evt);
extern void mmi_set_netsel_select_mode(mmi_menu_id mode);
#ifndef __MMI_MAINLCD_96X64__
extern CHAR* mmi_hint_netsel_select_mode(void);
#endif
#endif /* __MANUAL_MODE_NW_SEL__ */

#ifdef __MMI_GPRS_FEATURES__
extern void mmi_entry_netset_gprs_mode(mmi_id parent_id, mmi_id menu_id);
extern void mmi_netset_set_gprs_state(mmi_menu_id gprs);
extern CHAR* mmi_hint_netset_gprs_connection(void);
#endif /* __MMI_GPRS_FEATURES__ */

#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
#ifndef __MMI_MAINLCD_96X64__
/* under construction !*/
#endif
/* under construction !*/
#endif /* #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) */

/* Network Setup Preferred Network List */
extern void mmi_entry_netsel_auto(void);
extern void mmi_entry_netsel_manual(void);

extern void mmi_entry_netset_pref_list(void);
extern void mmi_entry_netset_pref_list_opt_add(void);
extern void mmi_entry_netset_pref_list_opt_new(void);
extern void mmi_entry_netset_pref_list_opt_edit(void);
extern void mmi_entry_netset_pref_list_opt_del(void);

extern mmi_ret mmi_netset_pref_list_proc(mmi_event_struct *param);
/* Network Setup Preferred Network List */

#ifdef __MONITOR_PAGE_DURING_TRANSFER__
extern void mmi_netset_update_pch_hint(void);
extern void mmi_entry_netset_pch_menu(cui_menu_event_struct *evt);
extern void mmi_netset_set_pch_confirm(mmi_menu_id pch);
extern CHAR* mmi_hint_netset_pch_menu(void);
#endif
#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
extern void mmi_netset_pch_sync_check(void);
#endif
#ifdef __UMTS_FDD_MODE__
#ifdef __HSPA_PREFERENCE_SETTING__
#ifdef __DYNAMIC_HSPA_PREFERENCE__
extern void mmi_entry_netset_hspa_menu(cui_menu_event_struct *evt);
extern void mmi_netset_set_hspa_confirm(mmi_menu_id pch);
extern CHAR* mmi_hint_netset_hspa_menu(void);
#endif /* __DYNAMIC_HSPA_PREFERENCE__ */
#endif /* __HSPA_PREFERENCE_SETTING__ */
#endif

extern void mmi_netset_update_main_menu_hint(void);
extern void mmi_update_pref_list_option_menu(cui_menu_event_struct *evt);

#ifdef __MMI_3G_SWITCH__
/*****************************************************************************
* FUNCTION
*  mmi_netset_entry_3g_switch_menu
* DESCRIPTION
*  Entry 3g service swtich screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
extern void mmi_netset_entry_3g_switch_menu(mmi_event_struct *evt);

/*****************************************************************************
* FUNCTION
*  mmi_netset_3g_switch_set_menu_hint
* DESCRIPTION
*  set 3g service swtich menu hint
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
extern CHAR* mmi_netset_3g_switch_get_menu_hint(void);

#endif 

#endif /* __NETSET_APP_PROT_H__ */

