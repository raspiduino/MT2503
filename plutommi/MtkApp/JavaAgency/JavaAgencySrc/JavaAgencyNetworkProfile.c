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
 * JavaAgencyNetworkProfile.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*************************************************************************
 * Include header files
 *************************************************************************/

/*************************************************************************
 * Include header files
 *************************************************************************/

#ifdef __J2ME__
#include "Mmi_frm_gprot.h"
#include "MMI_include.h"
#include "CommonScreens.h"  /* mmi_display_popup */


#include "inlinecuigprot.h"
#ifndef __COSMOS_MMI_PACKAGE__ 
#include "DataAccountGProt.h"
#include "Dataaccountcuigprot.h"
#else
#include "vcui_dtcnt_select_gprot.h"
#include "vapp_dtcnt_gprot.h"
#endif
#include "DtcntSrvGprot.h"  /* srv_dtcnt_bearer_enum & delete/update struct*/
#include "Cbmcuigprot.h"

#include "JavaAgencyDef.h"
#include "FunAndGamesResDef.h"
#include "JavaAgencyProt.h"
#include "JavaAgencyGProt.h"
#include "Jvm_interface.h"  /* jam_get_app_id() */
#include "Jam_interface.h"

#if defined(__MMI_WLAN_FEATURES__)
#include "NetworkSetupDefs.h"           /* mmi_netset_get_active_preferred_mode() */
#endif

#ifdef BROWSER_SUPPORT
#include "BrowserSrvGprot.h"    /* srv_brw_get_active_browser_profile() */
#endif
#include "cbm_api.h"
#include "SimCtrlSrvGprot.h" /* for sim hot swap */
#include "mmi_frm_utility_gprot.h"

static S32 mmi_java_nw_dtcnt_changed_handler(mmi_event_struct* param);
static void mmi_java_nw_dtcnt_updated_ind_hdlr(mmi_event_struct * param);
static void mmi_java_nw_dtcnt_updated_cnf_hdlr(void * msg);
static void mmi_java_nw_dtcnt_deleted_ind_hdlr(mmi_event_struct * param);
static void mmi_java_nw_dtcnt_deleted_cnf_hdlr(void * msg);

static void mmi_java_nw_get_dtcnt_name(kal_int32 account_id, CHAR * account_name, kal_int32 length);

#ifdef __PLUTO_MMI_PACKAGE__
extern void mmi_java_global_setting_java_done_hdlr(void);
#endif

void mmi_java_nw_entry_dtcnt_cui(void);
static void mmi_java_nw_get_global_setting_rsp(void *msg);
static void mmi_java_nw_set_global_setting(void);
static void mmi_java_nw_set_global_setting_rsp(void *msg);

void mmi_java_nw_get_local_setting(void);
static void mmi_java_nw_get_local_setting_rsp(void *msg);
void mmi_java_nw_set_local_setting(void);
static void mmi_java_nw_set_local_setting_rsp(void *msg);
void mmi_java_nw_pre_entry_network_settings_screen(void);
static void mmi_java_nw_entry_network_settings_screen(void);

static void mmi_java_nw_wait_for_rsp(MMI_ID gid);
static void mmi_java_nw_save_settings(void);
#if 0
/* under construction !*/
#endif 
typedef enum
{
    MMI_JAVA_NW_USE_DEFAULT_CAPTION = CUI_INLINE_ITEM_ID_BASE,
    MMI_JAVA_NW_USE_DEFAULT,    
    MMI_JAVA_NW_NETWORK_SETTING_CAPTION,
    MMI_JAVA_NW_NETWORK_SETTING,

    MMI_JAVA_NW_INLINE_TOTAL
}mmi_java_nw_inline_item_enum;

typedef enum
{
    MMI_JAVA_NW_USE_DEFAULT_NO,
    MMI_JAVA_NW_USE_DEFAULT_YES,

    MMI_JAVA_NW_USE_DEFAULT_END   
}mmi_java_nw_use_default;

#ifdef __PLUTO_MMI_PACKAGE__
U16 use_default_select_string[MMI_JAVA_NW_USE_DEFAULT_END] = {STR_GLOBAL_NO, STR_GLOBAL_YES}; 
static cui_inline_item_caption_struct use_default_caption = {STR_ID_JAVA_NW_USE_DEFAULT};
static const cui_inline_item_select_struct use_default_struct = {MMI_JAVA_NW_USE_DEFAULT_END, 0, (U16 *)use_default_select_string};
static cui_inline_item_caption_struct java_network_caption = {STR_ID_JAVA_NETWORK};
static const cui_inline_item_display_only_struct account_name_item = {STR_ID_JAVA_NETWORK};

static cui_inline_item_softkey_struct softkey = {
    {{CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
    {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
    {0, 0}}};
static const cui_inline_set_item_struct items[] = {
    {MMI_JAVA_NW_USE_DEFAULT_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_FNG_SETTING_JAVA_NET_ICON, (void *)&use_default_caption},
    {MMI_JAVA_NW_USE_DEFAULT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &use_default_struct},
    {MMI_JAVA_NW_NETWORK_SETTING_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_FNG_SETTING_JAVA_NET_ICON, (void *)&java_network_caption},
    {MMI_JAVA_NW_NETWORK_SETTING, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY , 0, &account_name_item},};
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
#endif
mmi_java_nw_cntx g_mmi_java_nw_cntx;

extern java_context_struct g_java;
extern kal_uint32 J2ME_active_nw_acc_id[MAX_VM_INSTANCE_NUM];

/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_init
 * DESCRIPTION
 *  Invoked by InitJAVA to init protocol event handlers and reset g_mmi_java_nw_cntx.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_nw_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_INIT);
    /* Protocol handler */
    SetProtocolEventHandler((PsFuncPtr) mmi_java_nw_get_global_setting_rsp, MSG_ID_MMI_JAVA_NW_GET_GLOBAL_SETTING_RSP);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_nw_set_global_setting_rsp, MSG_ID_MMI_JAVA_NW_SET_GLOBAL_SETTING_RSP);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_nw_get_local_setting_rsp, MSG_ID_MMI_JAVA_NW_GET_LOCAL_SETTING_RSP);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_nw_set_local_setting_rsp, MSG_ID_MMI_JAVA_NW_SET_LOCAL_SETTING_RSP);
    /* dtcnt update/delete protocol handler */
    SetProtocolEventHandler((PsFuncPtr) mmi_java_nw_dtcnt_updated_cnf_hdlr, MSG_ID_MMI_JAVA_NW_UPDATE_DTCNT_CNF);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_nw_dtcnt_deleted_cnf_hdlr, MSG_ID_MMI_JAVA_NW_DELETE_DTCNT_CNF);    

    memset(&g_mmi_java_nw_cntx, 0, sizeof(g_mmi_java_nw_cntx));
}

MMI_BOOL mmi_java_is_no_sim_card_available(void)
{
#if (MMI_MAX_SIM_NUM >= 2)
    if (srv_nw_usab_get_one_usable_sim() != MMI_SIM_NONE)
    {
        return MMI_FALSE;
    }
#else
    if (srv_sim_ctrl_is_available(MMI_SIM1))
    {
        return MMI_FALSE;
    }
#endif
return MMI_TRUE;
}

#ifdef __SIM_HOT_SWAP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_close_cui
 * DESCRIPTION
 *  This function is used to close local/global nw setting cui
 * PARAMETERS     
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_nw_close_cui(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    cui_inline_close(g_mmi_java_nw_cntx.sg_id_inline_editor);
    g_mmi_java_nw_cntx.sg_id_inline_editor = GRP_ID_INVALID;
    
    memset(&g_mmi_java_nw_cntx, 0, sizeof(g_mmi_java_nw_cntx));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_sim_detected_handler
 * DESCRIPTION
 *  This function is used to process sim hot swap
 * PARAMETERS     
 *  evt       [IN]     event id
 * RETURNS
 *  return MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_java_nw_sim_detected_handler(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_event_detected_evt_struct *detected_evt = (srv_sim_ctrl_event_detected_evt_struct *)evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ASSERT(detected_evt != NULL);
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_SIM_DETECTED_HANDLER, detected_evt->type);
    
    switch (detected_evt->type)
    {
        case SRV_SIM_CTRL_EVENT_DET_REMOVED:
        {
            mmi_java_nw_close_cui();            
            break;
        }
        case SRV_SIM_CTRL_EVENT_DET_INSERTED:
        {
            mmi_java_nw_close_cui();            
            break;
        }
        default:
        {
            break;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_dtcnt_changes_reg_event
 * DESCRIPTION
 *  Register event callback dynamically with user data pointer.
 * PARAMETERS
 *  evt_id :      [IN]  callback execution type.
 *  user_data :   [IN]  user data pointer.
 * RETURNS
 *  Return MMI_RET_OK if success to register callback with designated user data;
 *  return MMI_RET_ERR_HAS_BEEN_REGISTERED if the designated callback with 
 *  designated user data has been registered.
 *****************************************************************************/
mmi_ret mmi_java_nw_sim_detected_reg_event(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_cb_reg_event(EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED, mmi_java_nw_sim_detected_handler, user_data);
    return MMI_RET_OK;
}
#endif /* #ifdef __SIM_HOT_SWAP_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_dtcnt_changes_reg_event
 * DESCRIPTION
 *  Register event callback dynamically with user data pointer.
 * PARAMETERS
 *  evt_id :      [IN]  callback execution type.
 *  user_data :   [IN]  user data pointer.
 * RETURNS
 *  Return MMI_RET_OK if success to register callback with designated user data;
 *  return MMI_RET_ERR_HAS_BEEN_REGISTERED if the designated callback with 
 *  designated user data has been registered.
 *****************************************************************************/
mmi_ret mmi_java_nw_dtcnt_changes_reg_event(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND, mmi_java_nw_dtcnt_changed_handler, user_data);
    mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_ACCT_DELETE_IND, mmi_java_nw_dtcnt_changed_handler, user_data);
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_prov_callback_handler
 * DESCRIPTION
 *  function to handle the service callback
 * PARAMETERS
 *    param :      [IN]  event parameter.
 * RETURNS
 *  Return MMI_RET_OK if success;
 *****************************************************************************/
static S32 mmi_java_nw_dtcnt_changed_handler(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_DTCNT_CHANGED_HANDLER, param->evt_id);
        
    switch (param->evt_id)
    {
    case EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND:
        mmi_java_nw_dtcnt_updated_ind_hdlr(param);
        break;
    case EVT_ID_SRV_DTCNT_ACCT_DELETE_IND:
        mmi_java_nw_dtcnt_deleted_ind_hdlr(param);
        break;
    default:
        break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_dtcnt_updated_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param      [IN]            
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_java_nw_dtcnt_updated_ind_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_nw_update_dtcnt_ind_struct *ind_ptr = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_DTCNT_UPDATED_IND_HDLR);
    
    ind_ptr = (mmi_java_nw_update_dtcnt_ind_struct *) OslConstructDataPtr(sizeof(mmi_java_nw_update_dtcnt_ind_struct));
    memcpy((void *) &ind_ptr->account_info, (const void *) param, sizeof(srv_dtcnt_acct_update_ind_evt_struct));
    
    MMI_TRACE(MMI_TRACE_INFO, 
        INFO_MMI_JAVA_NW_STATE_DDDD, 
        ind_ptr->account_info.cause,
        ind_ptr->account_info.sim_id_old, 
        ind_ptr->account_info.sim_id, 
        ind_ptr->account_info.acc_id);
    
    mmi_java_send_message_from_active_mod(
        MOD_JAM, 
        MMI_J2ME_SAP, 
        MSG_ID_MMI_JAVA_NW_UPDATE_DTCNT_IND, 
        ind_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_dtcnt_updated_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param      [IN]            
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_java_nw_dtcnt_updated_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_nw_update_dtcnt_cnf_struct *cnf_ptr = (mmi_java_nw_update_dtcnt_cnf_struct *)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_DTCNT_UPDATED_CNF_HDLR, cnf_ptr->error_code);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_dtcnt_updated_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param      [IN]            
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_java_nw_dtcnt_deleted_ind_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_nw_delete_dtcnt_ind_struct *ind_ptr = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_DTCNT_DELETED_IND_HDLR);
    
    ind_ptr = (mmi_java_nw_delete_dtcnt_ind_struct *) OslConstructDataPtr(sizeof(mmi_java_nw_delete_dtcnt_ind_struct));
    memcpy((void *) &ind_ptr->account_info, (const void *) param, sizeof(srv_dtcnt_acct_delete_ind_evt_struct));
    MMI_TRACE(MMI_TRACE_INFO, INFO_MMI_JAVA_NW_STATE_DD, ind_ptr->account_info.cause, ind_ptr->account_info.del_num);

    mmi_java_send_message_from_active_mod(
        MOD_JAM, 
        MMI_J2ME_SAP, 
        MSG_ID_MMI_JAVA_NW_DELETE_DTCNT_IND, 
        ind_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_dtcnt_updated_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param      [IN]            
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_java_nw_dtcnt_deleted_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_nw_delete_dtcnt_cnf_struct *cnf_ptr = (mmi_java_nw_delete_dtcnt_cnf_struct *)msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_DTCNT_DELETED_CNF_HDLR, cnf_ptr->error_code);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_cui_proc
 * DESCRIPTION
 *  Process cui event.
 * PARAMETERS
 *  mmi_event_struct    [IN]
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_java_nw_cui_proc(mmi_event_struct *evt)
{
#ifdef __PLUTO_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_CUI_PROC, evt->evt_id);
    
    switch(evt->evt_id)
    {
        /* Inline editor cui evt */
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_ABORT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
        case EVT_ID_CUI_INLINE_SET_KEY:
        case EVT_ID_CUI_INLINE_NOTIFY:
            mmi_java_nw_inline_editor_cui_proc(evt);
            break;
        /* dtcnt cui evt */
        case CUI_DTCNT_SELECT_EVENT_RESULT_OK:
        case CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL:
        case CUI_DTCNT_SELECT_EVENT_CLOSE:
        case CUI_DTCNT_SELECT_EVENT_RESULT_FAILED:
        case CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED:
            mmi_java_nw_dtcnt_cui_proc(evt);
            cui_dtcnt_select_close(g_mmi_java_nw_cntx.sg_id_dtcnt);
            break;
        default:
            break;
    }
#endif    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_cui_inline_editor_proc
 * DESCRIPTION
 *  Process cui event.
 * PARAMETERS
 *  mmi_event_struct    [IN]
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_java_nw_inline_editor_cui_proc(mmi_event_struct *evt)
{
#ifdef __PLUTO_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_event_inline_notify_struct *event_notify;
    cui_event_inline_set_key_struct *event_set_key;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_INLINE_EDITOR_CUI_PROC, evt->evt_id);
    
    switch(evt->evt_id)
    {
        /* Inline editor cui evt */
        case EVT_ID_CUI_INLINE_SUBMIT:
            break;
        case EVT_ID_CUI_INLINE_ABORT:
            cui_inline_close(g_mmi_java_nw_cntx.sg_id_inline_editor);
            g_mmi_java_nw_cntx.sg_id_inline_editor = GRP_ID_INVALID;
            break;
        case EVT_ID_CUI_INLINE_CSK_PRESS:
            break;
        case EVT_ID_CUI_INLINE_SET_KEY:
            event_set_key = (cui_event_inline_set_key_struct *)evt;
            if ((g_mmi_java_nw_cntx.is_local && (event_set_key->item_id == MMI_JAVA_NW_NETWORK_SETTING)) ||
                (!g_mmi_java_nw_cntx.is_local && (event_set_key->item_id == mmi_java_global_setting_get_nw_inline_id())))
            {
                wgui_inline_set_lsk_function(mmi_java_nw_entry_dtcnt_cui);
            }
            break;
        case EVT_ID_CUI_INLINE_NOTIFY:
            event_notify = (cui_event_inline_notify_struct *)evt;
            switch(event_notify->event_type)
            {
                case CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM:
                    if ((g_mmi_java_nw_cntx.is_local && (event_notify->item_id == MMI_JAVA_NW_NETWORK_SETTING)) ||
                        (!g_mmi_java_nw_cntx.is_local && (event_notify->item_id == mmi_java_global_setting_get_nw_inline_id())))
                    {
                        if (!g_mmi_java_nw_cntx.is_local)
                        {
                            cui_inline_set_softkey_text(
                                g_mmi_java_nw_cntx.sg_id_inline_editor, 
                                mmi_java_global_setting_get_nw_inline_id(), 
                                MMI_LEFT_SOFTKEY, 
                                STR_GLOBAL_SELECT);
                        }
                        else if (g_mmi_java_nw_cntx.sg_id_parent == GRP_ID_JAVA_OPT)
                        {
                            cui_inline_set_softkey_text(
                                g_mmi_java_nw_cntx.sg_id_inline_editor, 
                                MMI_JAVA_NW_NETWORK_SETTING, 
                                MMI_LEFT_SOFTKEY, 
                                STR_GLOBAL_SELECT);
                        }
                    } 
                    break;
                case CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED:
                    break;
                default:
                    break;
            }
            break;
    }
#endif /*__PLUTO_MMI_PACKAGE__*/
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_dtcnt_cui_proc
 * DESCRIPTION
 *  Process cui event.
 * PARAMETERS
 *  mmi_event_struct    [IN]
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_java_nw_dtcnt_cui_proc(mmi_event_struct *evt)
{
#ifdef __PLUTO_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dtcnt_select_event_any_sim_selected_struct * dncntSelectEvt;
    cui_dtcnt_sim_enum sim;    
    srv_dtcnt_sim_type_enum sim_type;
#ifdef __MMI_MY_FAVORITE_JAVA_HYPERLINK__
    U8 attrib;
#endif 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_DTCNT_CUI_PROC, evt->evt_id);
    switch (evt->evt_id)
    {
        case CUI_DTCNT_SELECT_EVENT_RESULT_OK:   
        case CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL:
        case CUI_DTCNT_SELECT_EVENT_CLOSE:
        case CUI_DTCNT_SELECT_EVENT_RESULT_FAILED:       
            cui_dtcnt_select_close(g_mmi_java_nw_cntx.sg_id_dtcnt);
            g_mmi_java_nw_cntx.sg_id_dtcnt = GRP_ID_INVALID;
            break;
        case CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED:	
#ifdef __MMI_MY_FAVORITE_JAVA_HYPERLINK__
            attrib = g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_attributes;
            if (attrib & IS_DEFAULT_GAME)
            {
                cui_dtcnt_select_close(g_mmi_java_nw_cntx.sg_id_dtcnt);
                g_mmi_java_nw_cntx.sg_id_dtcnt = GRP_ID_INVALID;
                mmi_popup_display_ext(STR_JAVA_PERMISSION_SETTING_FAIL, MMI_EVENT_FAILURE, NULL);
            }
            else
#endif
            {
                dncntSelectEvt = (cui_dtcnt_select_event_any_sim_selected_struct*)evt;
                sim = dncntSelectEvt->selectSim;
                switch (sim)
                {
                    case CUI_DTCNT_SIM1: 
                        g_mmi_java_nw_cntx.sim_index |= NW_SIM_ID_SIM1;
                        break;
                    case CUI_DTCNT_SIM2:
                        g_mmi_java_nw_cntx.sim_index |= NW_SIM_ID_SIM2;
                        break;
                    case CUI_DTCNT_SIM3:
                        g_mmi_java_nw_cntx.sim_index |= NW_SIM_ID_SIM3;
                        break;
                    case CUI_DTCNT_SIM4:					
                        g_mmi_java_nw_cntx.sim_index |= NW_SIM_ID_SIM4;
                        break;
                    default:
                        break;
                }
                g_mmi_java_nw_cntx.network[sim].account_id = dncntSelectEvt->accountId;
                srv_dtcnt_get_sim_preference(&sim_type);
                if(sim  == sim_type -1 && !g_mmi_java_nw_cntx.is_local)/*Only global nw setting need display account name in inline cui editor*/
                {
                    mmi_java_nw_get_dtcnt_name(
                        g_mmi_java_nw_cntx.network[sim].account_id,
                        g_mmi_java_nw_cntx.account_name,
                        sizeof(g_mmi_java_nw_cntx.account_name));
                    cui_inline_set_value(
                        g_mmi_java_nw_cntx.sg_id_inline_editor,
                        mmi_java_global_setting_get_nw_inline_id(),
                        (UI_string_type)g_mmi_java_nw_cntx.account_name);            
                }
                mmi_java_nw_save_settings();
                cui_dtcnt_select_close(g_mmi_java_nw_cntx.sg_id_dtcnt);
            }
            break;            

    }
#endif
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_get_account_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  account_id      [IN]
 *  account_name    [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_nw_get_dtcnt_name(kal_int32 account_id, CHAR *account_name, kal_int32 length)
{
#ifdef __PLUTO_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //kal_int32 single_acct_id = 0;
    mmi_dtcnt_acct_valid_type_enum valid_type = MMI_DTCNT_ACCT_VALID_NONE;
    cbm_account_info_struct account_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_GET_DTCNT_NAME, account_id);
    memset(account_name, 0, length);
    memset(&account_info, 0, sizeof(account_info));
    
    valid_type = mmi_dtcnt_acct_is_valid (account_id);
    MMI_TRACE(MMI_TRACE_FUNC, INFO_MMI_JAVA_NW_STATE_D, valid_type);
    
    if (MMI_DTCNT_ACCT_VALID_FIRST == valid_type)
    {
         mmi_dtcnt_get_full_account_name(
                    account_id,
                    account_name, 
                    length, 
                    MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);
    }
    else if (MMI_DTCNT_ACCT_VALID_SECOND == valid_type)
    {
        mmi_dtcnt_get_full_account_name(
                    account_id,
                    account_name, 
                    length, 
                    MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);
    }
    else if (MMI_DTCNT_ACCT_VALID_FULL == valid_type)
    {
        mmi_dtcnt_get_full_account_name(
                    account_id,
                    account_name, 
                    length, 
                    MMI_DTCNT_GET_ACCT_NAME_TYPE_DUAL2);
    }
    else if (MMI_DTCNT_ACCT_VALID_NONE == valid_type)
    {
        mmi_ucs2cpy((CHAR *) account_name, (const CHAR *) GetString(STR_GLOBAL_EMPTY));
    }
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_get_global_setting
 * DESCRIPTION
 *  Send msg to JAM to get global network setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_nw_get_global_setting(void)
{
#ifdef __PLUTO_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_nw_get_global_setting_req_struct *req_ptr = NULL;
    kal_int32 index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_GET_GLOBAL_SETTING);
    
    memset(&g_mmi_java_nw_cntx, 0, sizeof(g_mmi_java_nw_cntx));

    g_mmi_java_nw_cntx.sg_id_parent = GRP_ID_JAVA_SETTING;
    req_ptr= (mmi_java_nw_get_global_setting_req_struct *) OslConstructDataPtr(sizeof(mmi_java_nw_get_global_setting_req_struct));
    for(index = 0; index < MMI_SIM_TOTAL; index++)
    {
        req_ptr->network[index] = &g_mmi_java_nw_cntx.network[index];
    }    

    mmi_java_send_message_from_active_mod(
        MOD_JAM, 
        MMI_J2ME_SAP, 
        MSG_ID_MMI_JAVA_NW_GET_GLOBAL_SETTING_REQ, 
        req_ptr);
    
    mmi_java_nw_wait_for_rsp(g_mmi_java_nw_cntx.sg_id_parent);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_get_global_setting_rsp
 * DESCRIPTION
 *  Receive global setting msg from JAM.
 * PARAMETERS
 *  msg [IN]: global setting
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_nw_get_global_setting_rsp(void *msg)
{
#ifdef __PLUTO_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_nw_get_global_setting_rsp_struct *rsp_ptr;
    srv_dtcnt_sim_type_enum simType = SRV_DTCNT_SIM_TYPE_1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_GET_GLOBAL_SETTING_RSP);
    
    
    rsp_ptr = (mmi_java_nw_get_global_setting_rsp_struct *) msg;
    if (rsp_ptr->error_code != NW_OP_NO_ERR)
    {
        MMI_TRACE(MMI_TRACE_STATE, INFO_MMI_JAVA_NW_STATE_D, rsp_ptr->error_code);
        mmi_popup_display_simple_ext(STR_GLOBAL_BUSY_TRY_LATER, MMI_EVENT_PROGRESS, g_mmi_java_nw_cntx.sg_id_parent, NULL);
        return;
    }
    srv_dtcnt_get_sim_preference(&simType);
    if (g_mmi_java_nw_cntx.network[simType-1].account_id == CBM_DEFAULT_ACCT_ID)
    {
        ASSERT(0);
    }
    else 
    {
        mmi_java_nw_get_dtcnt_name(g_mmi_java_nw_cntx.network[simType-1].account_id, 
                g_mmi_java_nw_cntx.account_name,
                sizeof(g_mmi_java_nw_cntx.account_name));
    }
    if (!mmi_java_need_block_msg())
    {
        mmi_java_global_setting_entry_inline_cui();
        
    }
    else 
    {
        return;
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_set_global_setting
 * DESCRIPTION
 *  set global setting to JAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_nw_set_global_setting(void)
{
#ifdef __PLUTO_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_nw_set_global_setting_req_struct *req_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_ptr = (mmi_java_nw_set_global_setting_req_struct *) OslConstructDataPtr(
                sizeof(mmi_java_nw_set_global_setting_req_struct));
    if(g_mmi_java_nw_cntx.sim_index & NW_SIM_ID_SIM1)
        req_ptr->network[0] = &g_mmi_java_nw_cntx.network[0];
    else
        req_ptr->network[0] = NULL;
#if (MMI_MAX_SIM_NUM>=2)    
    if(g_mmi_java_nw_cntx.sim_index & NW_SIM_ID_SIM2)
        req_ptr->network[1] = &g_mmi_java_nw_cntx.network[1];
    else
        req_ptr->network[1] = NULL;
#endif    
#if (MMI_MAX_SIM_NUM>=3)   
    if(g_mmi_java_nw_cntx.sim_index & NW_SIM_ID_SIM3)
        req_ptr->network[2] = &g_mmi_java_nw_cntx.network[2];
    else
        req_ptr->network[2] = NULL;
#endif
#if (MMI_MAX_SIM_NUM>=4)
    if(g_mmi_java_nw_cntx.sim_index & NW_SIM_ID_SIM4)
        req_ptr->network[3] = &g_mmi_java_nw_cntx.network[3];
    else
        req_ptr->network[3] = NULL;
#endif

    mmi_java_send_message_from_active_mod(
        MOD_JAM, 
        MMI_J2ME_SAP, 
        MSG_ID_MMI_JAVA_NW_SET_GLOBAL_SETTING_REQ, 
        req_ptr);
    mmi_java_nw_wait_for_rsp(g_mmi_java_nw_cntx.sg_id_parent);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_set_global_setting_rsp
 * DESCRIPTION
 *  Receive set global setting msg rsp from JAM.
 * PARAMETERS
 *  msg [IN]: rsp
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_nw_set_global_setting_rsp(void *msg)
{
#ifdef __PLUTO_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_nw_set_global_setting_rsp_struct *rsp_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_SET_GLOBAL_SETTING_RSP);
    
    rsp_ptr = (mmi_java_nw_set_global_setting_rsp_struct *)msg;
    
    MMI_TRACE(MMI_TRACE_STATE, INFO_MMI_JAVA_NW_STATE_D, rsp_ptr->error_code);
    if (rsp_ptr->error_code == NW_OP_NO_ERR)
    {
        mmi_java_global_setting_java_done_hdlr();
        mmi_popup_display_simple_ext(STR_GLOBAL_SAVED, MMI_EVENT_SUCCESS, g_mmi_java_nw_cntx.sg_id_parent, NULL);    
    } 
    else 
    {
        mmi_popup_display_simple_ext(STR_GLOBAL_BUSY_TRY_LATER, MMI_EVENT_PROGRESS, g_mmi_java_nw_cntx.sg_id_parent, NULL);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_get_local_setting
 * DESCRIPTION
 *  Send msg to JAM to get local network setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_nw_get_local_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_nw_get_local_setting_req_struct *req_ptr = NULL;
   // MMI_BOOL ret;
    //srv_dtcnt_sim_type_enum simType = SRV_DTCNT_SIM_TYPE_1;
    kal_int32 index = 0;
    mids_list_info_struct *mids_info = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_GET_LOCAL_SETTING);
    req_ptr= (mmi_java_nw_get_local_setting_req_struct *) OslConstructDataPtr(
            sizeof(mmi_java_nw_get_local_setting_req_struct));
    for(index = 0; index < MMI_SIM_TOTAL; index++)
    {
        req_ptr->network[index] = &g_mmi_java_nw_cntx.network[index];
    }
    mids_info = find_mids_info_by_id(
                    g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_id, 
                    MMI_FALSE);
    req_ptr->storage = (kal_char *)OslMalloc(mmi_wcslen((U16*) mids_info->mids_root) + 1);
    mmi_wcs_to_asc(req_ptr->storage, mids_info->mids_root);
    mmi_java_send_message_from_active_mod(
        MOD_JAM, 
        MMI_J2ME_SAP, 
        MSG_ID_MMI_JAVA_NW_GET_LOCAL_SETTING_REQ, 
        req_ptr);    

    mmi_java_nw_wait_for_rsp(g_mmi_java_nw_cntx.sg_id_parent);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_get_network_profile_level1_screen_para_hdlr
 * DESCRIPTION
 *  Receive global setting msg from JAM.
 * PARAMETERS
 *  msg     [IN]: local setting
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_nw_get_local_setting_rsp(void *msg)
{
#ifdef __PLUTO_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_nw_get_local_setting_rsp_struct *rsp_ptr;
    srv_dtcnt_sim_type_enum simType = SRV_DTCNT_SIM_TYPE_1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_GET_LOCAL_SETTING_RSP);
    
    rsp_ptr = (mmi_java_nw_get_local_setting_rsp_struct *) msg;

    MMI_TRACE(MMI_TRACE_STATE, INFO_MMI_JAVA_NW_STATE_D, rsp_ptr->error_code);
    if (rsp_ptr->error_code != NW_OP_NO_ERR)
    {
        mmi_popup_display_simple_ext(STR_GLOBAL_BUSY_TRY_LATER, MMI_EVENT_PROGRESS, g_mmi_java_nw_cntx.sg_id_parent, NULL);
        
        return;
    }
    srv_dtcnt_get_sim_preference(&simType);
    if (g_mmi_java_nw_cntx.network[simType-1].account_id == CBM_DEFAULT_ACCT_ID)
    {
        ASSERT(0);
    }
    else 
    {
        mmi_java_nw_get_dtcnt_name(g_mmi_java_nw_cntx.network[simType-1].account_id, 
            g_mmi_java_nw_cntx.account_name,
            sizeof(g_mmi_java_nw_cntx.account_name));
    }
    
    if (!mmi_java_need_block_msg())
    {
        mmi_java_nw_entry_network_settings_screen();
    }
    else 
    {
        return;
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_set_local_setting
 * DESCRIPTION
 *  set local setting to JAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_nw_set_local_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_nw_set_local_setting_req_struct *req_ptr = NULL;
    mids_list_info_struct *mids_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    req_ptr = (mmi_java_nw_set_local_setting_req_struct *) OslConstructDataPtr(
                sizeof(mmi_java_nw_set_local_setting_req_struct));
    if(g_mmi_java_nw_cntx.sim_index & NW_SIM_ID_SIM1)
        req_ptr->network[0] = &g_mmi_java_nw_cntx.network[0];
    else
        req_ptr->network[0] = NULL;
#if (MMI_MAX_SIM_NUM>=2)    
    if(g_mmi_java_nw_cntx.sim_index & NW_SIM_ID_SIM2)
        req_ptr->network[1] = &g_mmi_java_nw_cntx.network[1];
    else
        req_ptr->network[1] = NULL;
#endif    
#if (MMI_MAX_SIM_NUM>=3)   
    if(g_mmi_java_nw_cntx.sim_index & NW_SIM_ID_SIM3)
        req_ptr->network[2] = &g_mmi_java_nw_cntx.network[2];
    else
        req_ptr->network[2] = NULL;
#endif
#if (MMI_MAX_SIM_NUM>=4)
    if(g_mmi_java_nw_cntx.sim_index & NW_SIM_ID_SIM4)
        req_ptr->network[3] = &g_mmi_java_nw_cntx.network[3];
    else
        req_ptr->network[3] = NULL;
#endif
    mids_info = find_mids_info_by_id(
                    g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_id,
                    MMI_FALSE);
    
    
    req_ptr->storage = OslMalloc(mmi_wcslen((U16*) mids_info->mids_root) + 1);
    mmi_wcs_to_asc(req_ptr->storage, mids_info->mids_root);

    mmi_java_send_message_from_active_mod(
        MOD_JAM, 
        MMI_J2ME_SAP, 
        MSG_ID_MMI_JAVA_NW_SET_LOCAL_SETTING_REQ, 
        req_ptr);
    mmi_java_nw_wait_for_rsp(g_mmi_java_nw_cntx.sg_id_parent);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_set_local_setting_rsp
 * DESCRIPTION
 *  Receive set local setting msg rsp from JAM.
 * PARAMETERS
 *  msg [IN]: rsp
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_nw_set_local_setting_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_nw_set_local_setting_rsp_struct *rsp_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_SET_LOCAL_SETTING_RSP);
    
    rsp_ptr = (mmi_java_nw_set_local_setting_rsp_struct *)msg;
    
    MMI_TRACE(MMI_TRACE_STATE, INFO_MMI_JAVA_NW_STATE_D, rsp_ptr->error_code);
    #ifdef __PLUTO_MMI_PACKAGE__
    if (rsp_ptr->error_code == NW_OP_NO_ERR)
    {
        mmi_popup_display_simple_ext(STR_GLOBAL_SAVED, MMI_EVENT_SUCCESS, g_mmi_java_nw_cntx.sg_id_parent, NULL);
        g_mmi_java_nw_cntx.sg_id_inline_editor = GRP_ID_INVALID;
        
    } 
    else 
    {
        mmi_popup_display_simple_ext(STR_GLOBAL_BUSY_TRY_LATER, MMI_EVENT_PROGRESS, g_mmi_java_nw_cntx.sg_id_parent, NULL);        
    }
    #endif
    
    OslMfree(rsp_ptr->storage);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_wait_for_rsp
 * DESCRIPTION
 *  pop up "Please wait" screen.
 * PARAMETERS
 *  gid [IN]: parent group id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_nw_wait_for_rsp(MMI_ID gid)
{
#ifdef __PLUTO_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_frm_scrn_enter(
            gid, // @TODO make sure what the parent_id should be?
            SCR_ID_JAVA_NW_PLEASE_WAIT, 
            NULL, 
            NULL, 
            MMI_FRM_FULL_SCRN))
    {
        MMI_TRACE(MMI_TRACE_STATE, INFO_MMI_JAVA_NW_MARK_FAIL);
        return;
    }
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    ShowCategory66Screen(
        STR_GLOBAL_PLEASE_WAIT,
        mmi_java_get_title_icon(),
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_GLOBAL_PLEASE_WAIT),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        gui_buffer);
    
    ClearAllKeyHandler();
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_local_settings_hilit_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_nw_local_settings_hilit_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
         
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_mmi_java_nw_cntx, 0, sizeof(g_mmi_java_nw_cntx));
    g_mmi_java_nw_cntx.is_local = MMI_TRUE;
    
    SetLeftSoftkeyFunction(mmi_java_nw_pre_entry_network_settings_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
#ifndef __MMI_WGUI_DISABLE_CSK__
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif 
    SetCenterSoftkeyFunction(mmi_java_nw_pre_entry_network_settings_screen,KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_pre_entry_network_settings_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_nw_pre_entry_network_settings_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_java_nw_cntx.sg_id_parent = GRP_ID_JAVA_OPT;
    mmi_java_nw_get_local_setting();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_entry_network_settings_screen
 * DESCRIPTION
 *  Entry local network settings screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_nw_entry_network_settings_screen(void)
{
    mmi_java_nw_entry_dtcnt_cui();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_dtcnt_cui_close
 * DESCRIPTION
 *  Close data accoent cui if it's present
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_nw_dtcnt_cui_close(void)
{
#ifdef __COSMOS_MMI_PACKAGE__
    if (g_mmi_java_nw_cntx.sg_id_dtcnt != GRP_ID_INVALID && mmi_frm_group_is_present(g_mmi_java_nw_cntx.sg_id_dtcnt))
    {
        vcui_dtcnt_select_close(g_mmi_java_nw_cntx.sg_id_dtcnt);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_dtcnt_entry_dtcnt_cui
 * DESCRIPTION
 *  Invoke data account cui.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_nw_entry_dtcnt_cui(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dtcnt_select_run_struct dtcnt_param;
    kal_int32 vm_id = 0;
    kal_int32 index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_ENTRY_DTCNT_CUI);
#ifdef __PLUTO_MMI_PACKAGE__    
    if(mmi_java_is_no_sim_card_available())
    {
        mmi_popup_display_simple_ext(STR_GLOBAL_UNAVAILABLE_SIM, MMI_EVENT_FAILURE, g_mmi_java_nw_cntx.sg_id_parent, NULL);        
        return;
    }
#endif    
    dtcnt_param.bearers = DATA_ACCOUNT_BEARER_ALL;
    dtcnt_param.app_id = jam_get_app_id(vm_id);
    if (g_mmi_java_nw_cntx.is_local)
    {
        dtcnt_param.str_id = STR_JAVA_APP_OPTION_NETWORK_SETTINGS;
    }
    else
    {
        dtcnt_param.str_id = STR_JAVA_APP_NETWORK_SETTINGS;
    }
    
    dtcnt_param.icon_id = mmi_java_get_title_icon();

    for(index = 0;index < MMI_SIM_TOTAL;index ++)
    {
        dtcnt_param.sim_account_id[index] = g_mmi_java_nw_cntx.network[index].account_id;
    }
    dtcnt_param.sim_selection = CUI_DTCNT_SELECT_SIM_ALL;

    
    if (g_mmi_java_nw_cntx.is_local)
    {
        dtcnt_param.option = (cui_dtcnt_select_option_enum)(CUI_DTCNT_SELECT_DEFAULT | CUI_DTCNT_SELECT_NOT_SUBSCRIBE_ACCOUNT);
    }
    else 
    {
        dtcnt_param.option = (cui_dtcnt_select_option_enum)(CUI_DTCNT_SELECT_SIM | CUI_DTCNT_SELECT_BEARER_SWITCH | CUI_DTCNT_SELECT_ALLOW_SAME_BEARER_SWITCH);
    }
    dtcnt_param.type = CUI_DTCNT_SELECT_TYPE_NORMAL;
#ifdef __PLUTO_MMI_PACKAGE__
    g_mmi_java_nw_cntx.sg_id_dtcnt = cui_dtcnt_select_create(g_mmi_java_nw_cntx.sg_id_parent);
    MMI_TRACE(MMI_TRACE_STATE, INFO_MMI_JAVA_NW_STATE_D, g_mmi_java_nw_cntx.sg_id_dtcnt);
    
    cui_dtcnt_select_set_param(g_mmi_java_nw_cntx.sg_id_dtcnt, &dtcnt_param);
    cui_dtcnt_select_run(g_mmi_java_nw_cntx.sg_id_dtcnt);
#else
    g_mmi_java_nw_cntx.sg_id_dtcnt = vcui_dtcnt_select_create(g_mmi_java_nw_cntx.sg_id_parent);
    MMI_TRACE(MMI_TRACE_STATE, INFO_MMI_JAVA_NW_STATE_D, g_mmi_java_nw_cntx.sg_id_dtcnt);
    
    vcui_dtcnt_select_set_param(g_mmi_java_nw_cntx.sg_id_dtcnt, &dtcnt_param);
    vcui_dtcnt_select_run(g_mmi_java_nw_cntx.sg_id_dtcnt);
#endif
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_save_settings
 * DESCRIPTION
 *  Save settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_nw_save_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_SAVE_SETTINGS, g_mmi_java_nw_cntx.is_local);
    
    if (g_mmi_java_nw_cntx.is_local)
    {
        mmi_java_nw_set_local_setting();
    }
    else
    {
        mmi_java_nw_set_global_setting();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_save_none
 * DESCRIPTION
 *  Undo save settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
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
#endif 
/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_get_account_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  account_name ptr
 *****************************************************************************/
CHAR* mmi_java_nw_get_account_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_GET_ACCOUNT_NAME);
    return g_mmi_java_nw_cntx.account_name;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_get_inline_sg_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  inline editor sg id
 *****************************************************************************/
MMI_ID mmi_java_nw_get_inline_sg_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_GET_INLINE_SG_ID, g_mmi_java_nw_cntx.sg_id_inline_editor);

    return g_mmi_java_nw_cntx.sg_id_inline_editor;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_set_inline_sg_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sg_id_inline_editor [IN]       
 * RETURNS
 *  
 *****************************************************************************/
void mmi_java_nw_set_inline_sg_id(MMI_ID sg_id_inline_editor)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(!g_mmi_java_nw_cntx.is_local);
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_SET_INLINE_SG_ID, sg_id_inline_editor);
    
    g_mmi_java_nw_cntx.sg_id_inline_editor = sg_id_inline_editor;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_is_need_hide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  MMI_TRUE OR MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_java_nw_is_need_hide(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_hide = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_IS_NEED_HIDE);
    if (!srv_mode_switch_is_network_service_available()||
    srv_nw_usab_get_one_usable_sim() == MMI_SIM_NONE)        
    {
        is_hide = MMI_TRUE;
    }
    else
    {
        is_hide = MMI_FALSE;
    }
    MMI_TRACE(MMI_TRACE_STATE, INFO_MMI_JAVA_NW_STATE_D, is_hide);
    return is_hide;

}

#endif /* __J2ME__ */ 
