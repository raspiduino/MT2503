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

static S32 mmi_java_nw_dtcnt_changed_handler(mmi_event_struct* param);
static void mmi_java_nw_dtcnt_updated_ind_hdlr(mmi_event_struct * param);
static void mmi_java_nw_dtcnt_updated_cnf_hdlr(void * msg);
static void mmi_java_nw_dtcnt_deleted_ind_hdlr(mmi_event_struct * param);
static void mmi_java_nw_dtcnt_deleted_cnf_hdlr(void * msg);

static void mmi_java_nw_get_dtcnt_name(kal_int32 account_id, S8 * account_name, kal_int32 length);

extern void mmi_fng_setting_java_done_hdlr(void);

static mmi_ret mmi_java_nw_always_ask_bearer_fallback_cui_proc(mmi_event_struct *evt);

void mmi_java_nw_entry_dtcnt_cui(void);
static void mmi_java_nw_entry_always_ask_cui(void);
static void mmi_java_nw_entry_bearer_fallback_cui(void);

static void mmi_java_nw_recv_always_ask_ind(void *msg);
void mmi_java_nw_set_always_ask_cnf(void);
static void mmi_java_nw_recv_bearer_fallback_ind(void *msg);
static void mmi_java_nw_set_bearer_fallback_cnf(void);

static void mmi_java_nw_recv_install_ind(void *msg);

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
static void mmi_java_nw_save_none(void);
static void mmi_java_nw_save_settings_confirm(void);

static void mmi_java_set_audio_volume_req(U8 volume);

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
static const cui_inline_struct g_mmi_java_nw_inline_editor = {
        (U8)(MMI_JAVA_NW_INLINE_TOTAL - CUI_INLINE_ITEM_ID_BASE), 
        STR_JAVA_APP_OPTION_NETWORK_SETTINGS,
        0,
        CUI_INLINE_SCREEN_LOOP,
        &softkey,
        items};   
mmi_java_nw_cntx g_mmi_java_nw_cntx;

extern java_context_struct g_java;
extern kal_uint32 J2ME_active_nw_acc_id;

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
    SetProtocolEventHandler((PsFuncPtr) mmi_java_nw_recv_always_ask_ind, MSG_ID_MMI_JAVA_NW_ALWAYS_ASK_IND);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_nw_recv_bearer_fallback_ind, MSG_ID_MMI_JAVA_NW_BEARER_FALLBACK_IND);
    /* dtcnt update/delete protocol handler */
    SetProtocolEventHandler((PsFuncPtr) mmi_java_nw_dtcnt_updated_cnf_hdlr, MSG_ID_MMI_JAVA_NW_UPDATE_DTCNT_CNF);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_nw_dtcnt_deleted_cnf_hdlr, MSG_ID_MMI_JAVA_NW_DELETE_DTCNT_CNF);    
#ifdef BROWSER_SUPPORT
    SetProtocolEventHandler((PsFuncPtr) mmi_java_nw_recv_install_ind, MSG_ID_MMI_JAVA_NW_INSTALL_IND);
#endif

    memset(&g_mmi_java_nw_cntx, 0, sizeof(g_mmi_java_nw_cntx));
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
        case  CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED:   
            mmi_java_nw_dtcnt_cui_proc(evt);
            break;
        /* Always ask & bearer fallback cui evt */
        case EVT_ID_CUI_CBM_OK:
        case EVT_ID_CUI_CBM_FAIL:
        case EVT_ID_CUI_CBM_CANCEL:
            mmi_java_nw_always_ask_bearer_fallback_cui_proc(evt);
            break;
        default:
            break;
    }
    
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
            if (g_mmi_java_nw_cntx.sg_id_parent == GRP_ID_JAVA_OPT)
            {
                cui_inline_get_value(
                    g_mmi_java_nw_cntx.sg_id_inline_editor, 
                    MMI_JAVA_NW_USE_DEFAULT, 
                    (void *)&g_mmi_java_nw_cntx.network.Use_default);
            }
            mmi_java_nw_save_settings_confirm();
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
                (!g_mmi_java_nw_cntx.is_local && (event_set_key->item_id == mmi_java_get_nw_inline_item_id())))
            {
                if (!g_mmi_java_nw_cntx.is_local || 
                    (g_mmi_java_nw_cntx.is_local && !g_mmi_java_nw_cntx.network.Use_default))
                {
                    SetLeftSoftkeyFunction(mmi_java_nw_entry_dtcnt_cui, KEY_EVENT_UP);
                    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
                    SetCenterSoftkeyFunction(mmi_java_nw_entry_dtcnt_cui,KEY_EVENT_UP);
                }
            }
            break;
        case EVT_ID_CUI_INLINE_NOTIFY:
            event_notify = (cui_event_inline_notify_struct *)evt;
            switch(event_notify->event_type)
            {
                case CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM:
                    if ((g_mmi_java_nw_cntx.is_local && (event_notify->item_id == MMI_JAVA_NW_NETWORK_SETTING)) ||
                        (!g_mmi_java_nw_cntx.is_local && (event_notify->item_id == mmi_java_get_nw_inline_item_id())))
                    {
                        if (!g_mmi_java_nw_cntx.is_local)
                        {
                            cui_inline_set_softkey_text(
                                g_mmi_java_nw_cntx.sg_id_inline_editor, 
                                mmi_java_get_nw_inline_item_id(), 
                                MMI_LEFT_SOFTKEY, 
                                STR_GLOBAL_SELECT);
                        }
                        else if (!g_mmi_java_nw_cntx.network.Use_default &&
                                 (g_mmi_java_nw_cntx.sg_id_parent == GRP_ID_JAVA_OPT))
                        {
                            cui_inline_set_softkey_text(
                                g_mmi_java_nw_cntx.sg_id_inline_editor, 
                                MMI_JAVA_NW_NETWORK_SETTING, 
                                MMI_LEFT_SOFTKEY, 
                                STR_GLOBAL_SELECT);
                        }
                        else if (g_mmi_java_nw_cntx.network.Use_default &&
                                 (g_mmi_java_nw_cntx.sg_id_parent == GRP_ID_JAVA_OPT))
                        {
                            cui_inline_set_softkey_text(
                                g_mmi_java_nw_cntx.sg_id_inline_editor, 
                                MMI_JAVA_NW_NETWORK_SETTING, 
                                MMI_LEFT_SOFTKEY, 
                                NULL);
                        }
                    } 
                    break;
                case CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED:
                    if (g_mmi_java_nw_cntx.is_local && (event_notify->item_id == MMI_JAVA_NW_USE_DEFAULT))
                    {
                        cui_inline_get_value(
                            g_mmi_java_nw_cntx.sg_id_inline_editor, 
                            MMI_JAVA_NW_USE_DEFAULT, 
                            (void *)&g_mmi_java_nw_cntx.network.Use_default);
                        if (g_mmi_java_nw_cntx.network.Use_default)
                        {
                            cui_inline_set_item_attributes(
                            g_mmi_java_nw_cntx.sg_id_inline_editor, 
                            MMI_JAVA_NW_NETWORK_SETTING, 
                            CUI_INLINE_SET_ATTRIBUTE, 
                            CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW);
                        }
                        else
                        {
                            cui_inline_set_item_attributes(
                                g_mmi_java_nw_cntx.sg_id_inline_editor, 
                                MMI_JAVA_NW_NETWORK_SETTING, 
                                CUI_INLINE_RESET_ATTRIBUTE, 
                                CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW);
                        }
                    }
                    break;
                default:
                    break;
            }
            break;
    }
    
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
#ifndef __COSMOS_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dtcnt_select_event_any_sim_selected_struct *event_internal;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_DTCNT_CUI_PROC, evt->evt_id);
    switch (evt->evt_id)
    {      
        case CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED:
            event_internal = (cui_dtcnt_select_event_any_sim_selected_struct *)evt;
            MMI_TRACE(MMI_TRACE_STATE, INFO_MMI_JAVA_NW_STATE_DD, g_mmi_java_nw_cntx.network.account_id, event_internal->accountId);
            g_mmi_java_nw_cntx.network.account_id = event_internal->accountId;
                
            mmi_java_nw_get_dtcnt_name(g_mmi_java_nw_cntx.network.account_id, 
                g_mmi_java_nw_cntx.account_name, 
                sizeof(g_mmi_java_nw_cntx.account_name));
                
            cui_inline_set_screen_attributes(
                g_mmi_java_nw_cntx.sg_id_inline_editor, 
                CUI_INLINE_SET_ATTRIBUTE, 
                CUI_INLINE_SCREEN_CHANGED);
            if (g_mmi_java_nw_cntx.is_local)
            {
                if (g_mmi_java_nw_cntx.network.Use_default)
                {
                    cui_inline_set_item_attributes(
                        g_mmi_java_nw_cntx.sg_id_inline_editor, 
                        MMI_JAVA_NW_NETWORK_SETTING, 
                        CUI_INLINE_SET_ATTRIBUTE, 
                        CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW);
                }
                else
                { 
                    cui_inline_set_item_attributes(
                        g_mmi_java_nw_cntx.sg_id_inline_editor, 
                        MMI_JAVA_NW_NETWORK_SETTING, 
                        CUI_INLINE_RESET_ATTRIBUTE, 
                        CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW);
                }
                
                cui_inline_set_value(
                    g_mmi_java_nw_cntx.sg_id_inline_editor, 
                    MMI_JAVA_NW_USE_DEFAULT, 
                    (void *) g_mmi_java_nw_cntx.network.Use_default);
                cui_inline_set_value(
                    g_mmi_java_nw_cntx.sg_id_inline_editor, 
                    MMI_JAVA_NW_NETWORK_SETTING, 
                    (UI_string_type) g_mmi_java_nw_cntx.account_name);
            }
            else
            {
                cui_inline_set_value(
                    g_mmi_java_nw_cntx.sg_id_inline_editor, 
                    mmi_java_get_nw_inline_item_id(), 
                    (UI_string_type) g_mmi_java_nw_cntx.account_name);
            }
            
            cui_dtcnt_select_close(g_mmi_java_nw_cntx.sg_id_dtcnt);
            g_mmi_java_nw_cntx.sg_id_dtcnt = GRP_ID_INVALID;
            break;
        case CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL:
        case CUI_DTCNT_SELECT_EVENT_CLOSE:  
        case CUI_DTCNT_SELECT_EVENT_RESULT_FAILED:   
        //case CUI_DTCNT_SELECT_EVENT_RESULT_OK:
            cui_dtcnt_select_close(g_mmi_java_nw_cntx.sg_id_dtcnt);
            g_mmi_java_nw_cntx.sg_id_dtcnt = GRP_ID_INVALID;
            break;
            break;

    }
#endif
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_always_ask_bearer_fallback_cui_proc
 * DESCRIPTION
 *  Process cui event.
 * PARAMETERS
 *  mmi_event_struct    [IN]
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_java_nw_always_ask_bearer_fallback_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_evt_cbm_bearer_select_struct *event_internal;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_ALWAYS_ASK_BEARER_FALLBACK_CUI_PROC, evt->evt_id);
    
    event_internal = (cui_evt_cbm_bearer_select_struct *)evt;
    switch(event_internal->evt_id)
    {
        case EVT_ID_CUI_CBM_OK:
            if (event_internal->sender_id == g_mmi_java_nw_cntx.sg_id_always_ask)
            {
                g_mmi_java_nw_cntx.always_ask_ptr->network.account_id = 
                    event_internal->selected_account_id;
                g_mmi_java_nw_cntx.always_ask_ptr->is_done = MMI_TRUE;
                g_mmi_java_nw_cntx.always_ask_ptr->is_cancel = MMI_FALSE;
                mmi_java_nw_set_always_ask_cnf();
                
                cui_cbm_always_ask_close(g_mmi_java_nw_cntx.sg_id_always_ask);
                g_mmi_java_nw_cntx.sg_id_always_ask = GRP_ID_INVALID;
            }
            else if (event_internal->sender_id == g_mmi_java_nw_cntx.sg_id_bearer_fallback)
            {
                g_mmi_java_nw_cntx.bearer_fallback_ptr->network.account_id = 
                    event_internal->selected_account_id;
                g_mmi_java_nw_cntx.bearer_fallback_ptr->is_done = MMI_TRUE;
                g_mmi_java_nw_cntx.bearer_fallback_ptr->is_cancel = MMI_FALSE;
                mmi_java_nw_set_bearer_fallback_cnf();
            
                cui_cbm_bearer_fallback_close(g_mmi_java_nw_cntx.sg_id_bearer_fallback);
                g_mmi_java_nw_cntx.sg_id_bearer_fallback = GRP_ID_INVALID;
            }
            mmi_frm_group_close(g_mmi_java_nw_cntx.sg_id_parent);
            break;
        /* error occus or cancel */
        case EVT_ID_CUI_CBM_FAIL:
            if (event_internal->sender_id == g_mmi_java_nw_cntx.sg_id_always_ask)
            {
                g_mmi_java_nw_cntx.always_ask_ptr->is_done = MMI_TRUE;
                g_mmi_java_nw_cntx.always_ask_ptr->is_fail = MMI_TRUE;
                mmi_java_nw_set_always_ask_cnf();
            
                cui_cbm_always_ask_close(g_mmi_java_nw_cntx.sg_id_always_ask);
                g_mmi_java_nw_cntx.sg_id_always_ask = GRP_ID_INVALID;
            }
            else if (event_internal->sender_id == g_mmi_java_nw_cntx.sg_id_bearer_fallback)
            {
                g_mmi_java_nw_cntx.bearer_fallback_ptr->is_done = MMI_TRUE;
                g_mmi_java_nw_cntx.bearer_fallback_ptr->is_fail = MMI_TRUE;
                mmi_java_nw_set_bearer_fallback_cnf();
            
                cui_cbm_bearer_fallback_close(g_mmi_java_nw_cntx.sg_id_bearer_fallback);
                g_mmi_java_nw_cntx.sg_id_bearer_fallback = GRP_ID_INVALID;
            }
            mmi_frm_group_close(g_mmi_java_nw_cntx.sg_id_parent);
            break;
        case EVT_ID_CUI_CBM_CANCEL:
            if (event_internal->sender_id == g_mmi_java_nw_cntx.sg_id_always_ask)
            {
                g_mmi_java_nw_cntx.always_ask_ptr->is_done = MMI_TRUE;
                g_mmi_java_nw_cntx.always_ask_ptr->is_cancel = MMI_TRUE;
                mmi_java_nw_set_always_ask_cnf();
            
                cui_cbm_always_ask_close(g_mmi_java_nw_cntx.sg_id_always_ask);
                g_mmi_java_nw_cntx.sg_id_always_ask = GRP_ID_INVALID;
            }
            else if (event_internal->sender_id == g_mmi_java_nw_cntx.sg_id_bearer_fallback)
            {
                g_mmi_java_nw_cntx.bearer_fallback_ptr->is_done = MMI_TRUE;
                g_mmi_java_nw_cntx.bearer_fallback_ptr->is_cancel = MMI_TRUE;
                mmi_java_nw_set_bearer_fallback_cnf();
            
                cui_cbm_bearer_fallback_close(g_mmi_java_nw_cntx.sg_id_bearer_fallback);
                g_mmi_java_nw_cntx.sg_id_bearer_fallback = GRP_ID_INVALID;
            }
            mmi_frm_group_close(g_mmi_java_nw_cntx.sg_id_parent);
            break;
    }
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
void mmi_java_nw_get_dtcnt_name(kal_int32 account_id, S8 *account_name, kal_int32 length)
{
#ifdef __PLUTO_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 single_acct_id = 0;
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
         cbm_decode_data_account_id_ext(account_id, &account_info);
         single_acct_id = cbm_encode_data_account_id(account_info.account[0].account_id, 
                                account_info.account[0].sim_id, 
                                account_info.app_id, 
                                account_info.account[0].is_always_ask);
         mmi_dtcnt_get_full_account_name(
                    single_acct_id,
                    account_name, 
                    length, 
                    MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);
    }
    else if (MMI_DTCNT_ACCT_VALID_SECOND == valid_type)
    {
        cbm_decode_data_account_id_ext(account_id, &account_info);
        single_acct_id = cbm_encode_data_account_id(account_info.account[1].account_id, 
                                account_info.account[1].sim_id, 
                                account_info.app_id, 
                                account_info.account[1].is_always_ask);
        mmi_dtcnt_get_full_account_name(
                    single_acct_id,
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
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifndef __COSMOS_MMI_PACKAGE__
    mmi_java_nw_get_global_setting_req_struct *req_ptr = NULL;
    #else
    mmi_vjava_nw_get_global_setting_req_struct *req_ptr = NULL;
    #endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_GET_GLOBAL_SETTING);
    
    memset(&g_mmi_java_nw_cntx, 0, sizeof(g_mmi_java_nw_cntx));
    g_mmi_java_nw_cntx.sg_id_parent = GRP_ID_JAVA_SETTING;
#ifndef __COSMOS_MMI_PACKAGE__    
    req_ptr= (mmi_java_nw_get_global_setting_req_struct *) OslConstructDataPtr(sizeof(mmi_java_nw_get_global_setting_req_struct));
#else
    req_ptr= (mmi_vjava_nw_get_global_setting_req_struct *) OslConstructDataPtr(sizeof(mmi_vjava_nw_get_global_setting_req_struct));
#endif
    req_ptr->network = &g_mmi_java_nw_cntx.network;
    mmi_java_send_message_from_active_mod(
        MOD_JAM, 
        MMI_J2ME_SAP, 
        MSG_ID_MMI_JAVA_NW_GET_GLOBAL_SETTING_REQ, 
        req_ptr);
    
    mmi_java_nw_wait_for_rsp(g_mmi_java_nw_cntx.sg_id_parent);

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
    S8* default_acc_name;
    
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
    
    MMI_TRACE(MMI_TRACE_STATE, INFO_MMI_JAVA_NW_STATE_D, rsp_ptr->network->account_id);
    if (g_mmi_java_nw_cntx.network.account_id == CBM_DEFAULT_ACCT_ID)
    {
        default_acc_name = GetString(mmi_dtcnt_get_default_name_str_id());
        mmi_wcscpy((WCHAR *) g_mmi_java_nw_cntx.account_name, (const WCHAR *) default_acc_name);
        g_mmi_java_nw_cntx.network.account_id |= 0x3E00;
    }
    else 
    {
        mmi_java_nw_get_dtcnt_name(g_mmi_java_nw_cntx.network.account_id, 
                g_mmi_java_nw_cntx.account_name,
                sizeof(g_mmi_java_nw_cntx.account_name));
            
        /* mmi_dtcnt_get_full_account_name(
                g_mmi_java_nw_cntx.network.account_id,
                g_mmi_java_nw_cntx.account_name, 
                sizeof(g_mmi_java_nw_cntx.account_name), 
                MMI_DTCNT_GET_ACCT_NAME_TYPE_DUAL2); */
    }
    if (!mmi_java_need_block_msg())
    {
        mmi_java_entry_setting_with_inline_cui();
        
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
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifndef __COSMOS_MMI_PACKAGE__
    mmi_java_nw_set_global_setting_req_struct *req_ptr = NULL;
    #else
    mmi_vjava_nw_set_global_setting_req_struct *req_ptr = NULL;
    #endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_SET_GLOBAL_SETTING, g_mmi_java_nw_cntx.network.account_id);
    #ifndef __COSMOS_MMI_PACKAGE__
    req_ptr = (mmi_java_nw_set_global_setting_req_struct *) OslConstructDataPtr(
                sizeof(mmi_java_nw_set_global_setting_req_struct));
    #else
    req_ptr = (mmi_vjava_nw_set_global_setting_req_struct *) OslConstructDataPtr(
                sizeof(mmi_vjava_nw_set_global_setting_req_struct));    
    #endif
    req_ptr->network = &g_mmi_java_nw_cntx.network;
    mmi_java_send_message_from_active_mod(
        MOD_JAM, 
        MMI_J2ME_SAP, 
        MSG_ID_MMI_JAVA_NW_SET_GLOBAL_SETTING_REQ, 
        req_ptr);
    mmi_java_nw_wait_for_rsp(g_mmi_java_nw_cntx.sg_id_parent);
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
        mmi_fng_setting_java_done_hdlr();
        mmi_popup_display_simple_ext(STR_GLOBAL_SAVED, MMI_EVENT_SUCCESS, g_mmi_java_nw_cntx.sg_id_parent, NULL);    
        cui_inline_close(g_mmi_java_nw_cntx.sg_id_inline_editor);
        g_mmi_java_nw_cntx.sg_id_inline_editor = GRP_ID_INVALID;
        /* MAUI_02324267 */
        mmi_java_set_audio_volume_req(g_mmi_java_aud_volume_level);
    } 
    else 
    {
        mmi_popup_display_simple_ext(STR_GLOBAL_BUSY_TRY_LATER, MMI_EVENT_PROGRESS, g_mmi_java_nw_cntx.sg_id_parent, NULL);
    }

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
    #ifndef __COSMOS_MMI_PACKAGE__
    mmi_java_nw_get_local_setting_req_struct *req_ptr = NULL;
    #else
    mmi_vjava_nw_get_local_setting_req_struct *req_ptr = NULL;
    MMI_BOOL ret;
    srv_dtcnt_sim_type_enum simType = SRV_DTCNT_SIM_TYPE_1;
    #endif
    mids_list_info_struct *mids_info = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_GET_LOCAL_SETTING);
    #ifndef __COSMOS_MMI_PACKAGE__
    req_ptr= (mmi_java_nw_get_local_setting_req_struct *) OslConstructDataPtr(
                sizeof(mmi_java_nw_get_local_setting_req_struct));
    req_ptr->network = &g_mmi_java_nw_cntx.network;
    #else
    req_ptr= (mmi_vjava_nw_get_local_setting_req_struct *) OslConstructDataPtr(
            sizeof(mmi_vjava_nw_get_local_setting_req_struct));
    req_ptr->network[0] = &g_mmi_java_nw_cntx.network;
    req_ptr->network[1] = &g_mmi_java_nw_cntx.network2;

    #endif
    mids_info = find_mids_info_by_id(
                    g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_id, 
                    MMI_FALSE);
    req_ptr->storage = (kal_char *)OslMalloc(mmi_wcslen((U16*) mids_info->mids_root) + 1);
    mmi_wcs_to_asc((S8*) req_ptr->storage, (U16*) mids_info->mids_root);
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
    S8 *default_acc_name;
    
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

    MMI_TRACE(
        MMI_TRACE_STATE, 
        INFO_MMI_JAVA_NW_STATE_DD, 
        rsp_ptr->network->Use_default, 
        rsp_ptr->network->account_id);
    OslMfree(rsp_ptr->storage);

    if (g_mmi_java_nw_cntx.network.account_id == CBM_DEFAULT_ACCT_ID)
    {
        default_acc_name = GetString(mmi_dtcnt_get_default_name_str_id());
        mmi_wcscpy((WCHAR *) g_mmi_java_nw_cntx.account_name, (const WCHAR *) default_acc_name);
        g_mmi_java_nw_cntx.network.account_id |= 0x3E00;
    }
    else 
    {
        mmi_java_nw_get_dtcnt_name(g_mmi_java_nw_cntx.network.account_id, 
            g_mmi_java_nw_cntx.account_name,
            sizeof(g_mmi_java_nw_cntx.account_name));
        
        /* mmi_dtcnt_get_full_account_name(
                    g_mmi_java_nw_cntx.network.account_id,
                    g_mmi_java_nw_cntx.account_name, 
                    sizeof(g_mmi_java_nw_cntx.account_name), 
                    MMI_DTCNT_GET_ACCT_NAME_TYPE_DUAL2); */
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
    #ifndef __COSMOS_MMI_PACKAGE__
    mmi_java_nw_set_local_setting_req_struct *req_ptr = NULL;
    #else
    mmi_vjava_nw_set_local_setting_req_struct *req_ptr = NULL;
    #endif
    mids_list_info_struct *mids_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_TRACE_FUNC, 
        FUNC_MMI_JAVA_NW_SET_LOCAL_SETTING, 
        g_mmi_java_nw_cntx.network.Use_default, 
        g_mmi_java_nw_cntx.network.account_id);
    #ifndef __COSMOS_MMI_PACKAGE__
    req_ptr = (mmi_java_nw_set_local_setting_req_struct *) OslConstructDataPtr(
                sizeof(mmi_java_nw_set_local_setting_req_struct));
    req_ptr->network = &g_mmi_java_nw_cntx.network;
    #else
    req_ptr = (mmi_vjava_nw_set_local_setting_req_struct *) OslConstructDataPtr(
                sizeof(mmi_vjava_nw_set_local_setting_req_struct));
    if(g_mmi_java_nw_cntx.sim_index & NW_SIM_ID_SIM1)
        req_ptr->network[0] = &g_mmi_java_nw_cntx.network;
    else
        req_ptr->network[0] = NULL;
    if(g_mmi_java_nw_cntx.sim_index & NW_SIM_ID_SIM2)
        req_ptr->network[1] = &g_mmi_java_nw_cntx.network2;
    else
        req_ptr->network[1] = NULL;

    if(g_mmi_java_nw_cntx.sim_index & NW_WIFI)
    {
        req_ptr->network[0] = &g_mmi_java_nw_cntx.network;
        req_ptr->network[0]->wifi_only = g_mmi_java_nw_cntx.network.wifi_only;
    }
    #endif
    
    mids_info = find_mids_info_by_id(
                    g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_id,
                    MMI_FALSE);
    
    
    req_ptr->storage = OslMalloc(mmi_wcslen((U16*) mids_info->mids_root) + 1);
    mmi_wcs_to_asc((S8*) req_ptr->storage, (U16*) mids_info->mids_root);

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
    #ifndef __COSMOS_MMI_PACKAGE__
    if (rsp_ptr->error_code == NW_OP_NO_ERR)
    {
        mmi_popup_display_simple_ext(STR_GLOBAL_SAVED, MMI_EVENT_SUCCESS, g_mmi_java_nw_cntx.sg_id_parent, NULL);
        cui_inline_close(g_mmi_java_nw_cntx.sg_id_inline_editor);
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
#ifndef __COSMOS_MMI_PACKAGE__
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
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
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
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 icon = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_TRACE_FUNC, 
        FUNC_MMI_JAVA_NW_ENTRY_NETWORK_SETTINGS_SCREEN, 
        g_mmi_java_nw_cntx.network.Use_default, 
        g_mmi_java_nw_cntx.network.account_id);
    
    g_mmi_java_nw_cntx.sg_id_inline_editor = cui_inline_create(
        g_mmi_java_nw_cntx.sg_id_parent, 
        &g_mmi_java_nw_inline_editor);
    MMI_TRACE(MMI_TRACE_STATE, INFO_MMI_JAVA_NW_STATE_D, g_mmi_java_nw_cntx.sg_id_inline_editor);
    
    icon = mmi_java_get_title_icon();
    cui_inline_set_title(
        g_mmi_java_nw_cntx.sg_id_inline_editor, 
        STR_JAVA_APP_OPTION_NETWORK_SETTINGS, 
        icon);
    cui_inline_set_value(
        g_mmi_java_nw_cntx.sg_id_inline_editor, 
        MMI_JAVA_NW_USE_DEFAULT, 
        (void *) g_mmi_java_nw_cntx.network.Use_default);
    cui_inline_set_value(
        g_mmi_java_nw_cntx.sg_id_inline_editor, 
        MMI_JAVA_NW_NETWORK_SETTING, 
        (UI_string_type) g_mmi_java_nw_cntx.account_name);
    
    cui_inline_set_softkey_text(
        g_mmi_java_nw_cntx.sg_id_inline_editor, 
        MMI_JAVA_NW_USE_DEFAULT, 
        MMI_LEFT_SOFTKEY, 
        NULL);

    if (g_mmi_java_nw_cntx.network.Use_default)
    {
        cui_inline_set_item_attributes(
            g_mmi_java_nw_cntx.sg_id_inline_editor, 
            MMI_JAVA_NW_NETWORK_SETTING, 
            CUI_INLINE_SET_ATTRIBUTE, 
            CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW);
    }
    else
    {
        cui_inline_set_item_attributes(
            g_mmi_java_nw_cntx.sg_id_inline_editor, 
            MMI_JAVA_NW_NETWORK_SETTING, 
            CUI_INLINE_RESET_ATTRIBUTE, 
            CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW);
    }
    cui_inline_run(g_mmi_java_nw_cntx.sg_id_inline_editor);
    
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
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_ENTRY_DTCNT_CUI);
    
    dtcnt_param.bearers = DATA_ACCOUNT_BEARER_ALL;
    dtcnt_param.app_id = jam_get_app_id();
    if (g_mmi_java_nw_cntx.is_local)
    {
        dtcnt_param.str_id = STR_JAVA_APP_OPTION_NETWORK_SETTINGS;
    }
    else
    {
        dtcnt_param.str_id = STR_JAVA_APP_NETWORK_SETTINGS;
    }
    
    dtcnt_param.icon_id = mmi_java_get_title_icon();
    #ifdef __PLUTO_MMI_PACKAGE__
    dtcnt_param.sim_account_id[0] = g_mmi_java_nw_cntx.network.account_id;
    dtcnt_param.sim_selection = CUI_DTCNT_SELECT_SIM1;
    #else
    dtcnt_param.sim1_account_id = g_mmi_java_nw_cntx.network.account_id;
    dtcnt_param.sim2_account_id = g_mmi_java_nw_cntx.network2.account_id;
    dtcnt_param.sim_selection = CUI_DTCNT_SELECT_DUAL_SIM;
    #endif
    
    if (g_mmi_java_nw_cntx.is_local)
    {
        dtcnt_param.option = CUI_DTCNT_SELECT_DEFAULT | CUI_DTCNT_SELECT_NOT_SUBSCRIBE_ACCOUNT;
    }
    else 
    {
        dtcnt_param.option = CUI_DTCNT_SELECT_SIM | CUI_DTCNT_SELECT_BEARER_SWITCH | CUI_DTCNT_SELECT_ALLOW_SAME_BEARER_SWITCH;
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
 *  mmi_java_nw_recv_always_ask_ind
 * DESCRIPTION
 *  Receive always ask indication msg and invoke always ask CUI procedure.
 * PARAMETERS
 *  msg [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_nw_recv_always_ask_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jam_nw_always_ask_data_struct *ind_ptr;
    kal_int32 vm_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_RECV_ALWAYS_ASK_IND);
    
    ASSERT(msg != NULL);
    memset(&g_mmi_java_nw_cntx, 0, sizeof(g_mmi_java_nw_cntx));
    
    ind_ptr = (jam_nw_always_ask_data_struct *)msg;
    g_mmi_java_nw_cntx.always_ask_ptr = ind_ptr->always_ask_data;
    
    if (mmi_java_nw_is_need_hide() || 
        (jam_mvm_get_vm_state(vm_id) == JVM_TERMINATE_STATE) ||
        (jam_mvm_get_vm_state(vm_id) == JVM_TERMINATING_STATE))
    {
        srv_cbm_abort_app_bearer_event(jam_get_app_id());
        g_mmi_java_nw_cntx.always_ask_ptr->is_cancel = MMI_TRUE;
        g_mmi_java_nw_cntx.always_ask_ptr->is_done = MMI_TRUE;
        mmi_java_nw_set_always_ask_cnf();
    }
    else
    {
        mmi_java_nw_entry_always_ask_cui();
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_entry_always_ask_cui
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_nw_entry_always_ask_cui(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_cbm_parameter_struct param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_ENTRY_ALWAYS_ASK_CUI);
    #ifdef __PLUTO_MMI_PACKAGE__
    g_mmi_java_nw_cntx.sg_id_parent =
        mmi_frm_group_create_ex(
            GRP_ID_ROOT,
            GRP_ID_AUTO_GEN,
            mmi_java_nw_always_ask_bearer_fallback_cui_proc,
            NULL,
            MMI_FRM_NODE_NONE_FLAG);
    
    g_mmi_java_nw_cntx.sg_id_always_ask = cui_cbm_always_ask_create(g_mmi_java_nw_cntx.sg_id_parent);
    #elif defined(__COSMOS_MMI_PACKAGE__)
    g_mmi_java_nw_cntx.sg_id_always_ask = vcui_cbm_always_ask_create(g_mmi_java_nw_cntx.sg_id_parent);
    #endif
    MMI_TRACE(
        MMI_TRACE_STATE, 
        INFO_MMI_JAVA_NW_STATE_DD, 
        g_mmi_java_nw_cntx.sg_id_always_ask, 
        g_mmi_java_nw_cntx.always_ask_ptr->network.account_id);

    param.account_id = g_mmi_java_nw_cntx.always_ask_ptr->network.account_id;
    param.res.str_id = STR_JAVA_APP_OPTION_NETWORK_SETTINGS;//STR_ID_VJAVA_APP_OPTION_NETWORK_SETTINGS
    param.res.icon_id = mmi_java_get_title_icon();
     #ifdef __PLUTO_MMI_PACKAGE__
    cui_cbm_always_ask_set_param(
        g_mmi_java_nw_cntx.sg_id_always_ask, 
        &param);
    cui_cbm_always_ask_run(g_mmi_java_nw_cntx.sg_id_always_ask);
    #elif defined(__COSMOS_MMI_PACKAGE__)
    vcui_cbm_always_ask_set_param(
        g_mmi_java_nw_cntx.sg_id_always_ask, 
        &param);
    vcui_cbm_always_ask_run(g_mmi_java_nw_cntx.sg_id_always_ask);   
    #endif
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_set_always_ask_cnf
 * DESCRIPTION
 *  Send always ask cnf msg back to JAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_nw_set_always_ask_cnf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jam_nw_always_ask_data_struct *cnf_ptr = NULL;
    kal_int32 vm_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_TRACE_FUNC, 
        FUNC_MMI_JAVA_NW_SET_ALWAYS_ASK_CNF, 
        g_mmi_java_nw_cntx.always_ask_ptr->is_cancel, 
        g_mmi_java_nw_cntx.always_ask_ptr->is_done, 
        g_mmi_java_nw_cntx.always_ask_ptr->network.account_id);

    J2ME_active_nw_acc_id = g_mmi_java_nw_cntx.always_ask_ptr->network.account_id;
    cnf_ptr = (jam_nw_always_ask_data_struct *) OslConstructDataPtr(sizeof(jam_nw_always_ask_data_struct));
    cnf_ptr->always_ask_data = g_mmi_java_nw_cntx.always_ask_ptr;
    mmi_java_send_message_from_active_mod(
        MOD_JAM, 
        MMI_J2ME_SAP, 
        MSG_ID_MMI_JAVA_NW_ALWAYS_ASK_CNF, 
        cnf_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_recv_bearer_fallback_ind
 * DESCRIPTION
 *  Receive bearer fallback indication msg and invoke bearer fallback CUI procedure.
 * PARAMETERS
 *  msg [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_nw_recv_bearer_fallback_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jam_nw_bearer_fallback_struct *ind_ptr;
    kal_int32 vm_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_RECV_BEARER_FALLBACK_IND);
    
    ASSERT(msg != NULL);
    memset(&g_mmi_java_nw_cntx, 0, sizeof(g_mmi_java_nw_cntx));
    
    ind_ptr = (jam_nw_bearer_fallback_struct *)msg;
    g_mmi_java_nw_cntx.bearer_fallback_ptr = ind_ptr->bearer_fallback_data;

    if (mmi_java_nw_is_need_hide() || 
        (jam_mvm_get_vm_state(vm_id) == JVM_TERMINATE_STATE) ||
        (jam_mvm_get_vm_state(vm_id) == JVM_TERMINATING_STATE))
    {
        srv_cbm_abort_app_bearer_event(jam_get_app_id());
        g_mmi_java_nw_cntx.bearer_fallback_ptr->is_cancel = MMI_TRUE;
        g_mmi_java_nw_cntx.bearer_fallback_ptr->is_done = MMI_TRUE;
        mmi_java_nw_set_bearer_fallback_cnf();
    }
    else
    {
        mmi_java_nw_entry_bearer_fallback_cui();
    }
    
}

static void mmi_java_nw_entry_bearer_fallback_cui(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_cbm_parameter_struct param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_ENTRY_BEARER_FALLBACK_CUI);
    g_mmi_java_nw_cntx.sg_id_parent = 
    mmi_frm_group_create_ex(
        GRP_ID_ROOT,
        GRP_ID_AUTO_GEN,
        mmi_java_nw_always_ask_bearer_fallback_cui_proc,
        NULL,
        MMI_FRM_NODE_NONE_FLAG);
    g_mmi_java_nw_cntx.sg_id_bearer_fallback = cui_cbm_bearer_fallback_create(g_mmi_java_nw_cntx.sg_id_parent);
    MMI_TRACE(
        MMI_TRACE_STATE, 
        INFO_MMI_JAVA_NW_STATE_DD, 
        g_mmi_java_nw_cntx.sg_id_bearer_fallback, 
        g_mmi_java_nw_cntx.bearer_fallback_ptr->network.account_id);
    
    param.account_id = g_mmi_java_nw_cntx.bearer_fallback_ptr->network.account_id;
    param.res.str_id = STR_JAVA_APP_OPTION_NETWORK_SETTINGS;
    param.res.icon_id = mmi_java_get_title_icon();
    param.fb_query_type = CUI_CBM_QUERY_FB_NORM;
    cui_cbm_bearer_fallback_set_param(
        g_mmi_java_nw_cntx.sg_id_bearer_fallback, 
        &param);
    cui_cbm_bearer_fallback_run(g_mmi_java_nw_cntx.sg_id_bearer_fallback);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_set_always_ask_cnf
 * DESCRIPTION
 *  Send always ask cnf msg back to JAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_nw_set_bearer_fallback_cnf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jam_nw_bearer_fallback_struct *cnf_ptr = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_TRACE_FUNC, 
        FUNC_MMI_JAVA_NW_SET_BEARER_FALLBACK_CNF, 
        g_mmi_java_nw_cntx.bearer_fallback_ptr->is_cancel, 
        g_mmi_java_nw_cntx.bearer_fallback_ptr->is_done, 
        g_mmi_java_nw_cntx.bearer_fallback_ptr->network.account_id);
    
    J2ME_active_nw_acc_id = g_mmi_java_nw_cntx.bearer_fallback_ptr->network.account_id;
    cnf_ptr = (jam_nw_bearer_fallback_struct *) OslConstructDataPtr(sizeof(jam_nw_bearer_fallback_struct));
    cnf_ptr->bearer_fallback_data = g_mmi_java_nw_cntx.bearer_fallback_ptr;
    mmi_java_send_message_from_active_mod(
        MOD_JAM, 
        MMI_J2ME_SAP, 
        MSG_ID_MMI_JAVA_NW_BEARER_FALLBACK_CNF, 
        cnf_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_recv_install_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_nw_recv_install_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef BROWSER_SUPPORT    
    jam_nw_install_data_struct *ind_ptr = NULL;
    jam_nw_install_data_struct *rsp_ptr = NULL;
#endif /* #ifdef BROWSER_SUPPORT */    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_RECV_INSTALL_IND);
    
#ifdef BROWSER_SUPPORT    
    ind_ptr = (jam_nw_install_data_struct *)msg;

    rsp_ptr = (jam_nw_install_data_struct *) OslConstructDataPtr(
                sizeof(jam_nw_install_data_struct));
    rsp_ptr->is_success = srv_brw_get_active_browser_profile(ind_ptr->active_prof);

    rsp_ptr->active_prof = ind_ptr->active_prof;

    mmi_java_send_message_from_active_mod(
        MOD_JAM, 
        MMI_J2ME_SAP, 
        MSG_ID_MMI_JAVA_NW_INSTALL_CNF, 
        rsp_ptr);
#endif /* #ifdef BROWSER_SUPPORT */

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
static void mmi_java_nw_save_none(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_SAVE_NONE, g_mmi_java_nw_cntx.is_local);
    
    if (g_mmi_java_nw_cntx.is_local)
    {
        cui_inline_close(g_mmi_java_nw_cntx.sg_id_inline_editor);
        mmi_frm_scrn_close_active_id();
        g_mmi_java_nw_cntx.sg_id_inline_editor = GRP_ID_INVALID;
    }
    else
    {
        cui_inline_close(g_mmi_java_nw_cntx.sg_id_inline_editor);
        g_mmi_java_nw_cntx.sg_id_inline_editor = GRP_ID_INVALID;
        mmi_frm_group_close(GRP_ID_JAVA_SETTING);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_save_settings_confirm
 * DESCRIPTION
 *  Pop up saving confirm screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_nw_save_settings_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_SAVE_SETTINGS_CONFIRM);
    do {
        	mmi_confirm_property_struct arg;
        	mmi_confirm_property_init(&arg, CNFM_TYPE_USER_DEFINE);
        	arg.softkey[0].str = (WCHAR *)((UI_string_type) get_string(STR_GLOBAL_YES));
        	arg.softkey[2].str = (WCHAR *)((UI_string_type) get_string(STR_GLOBAL_NO));
        	arg.callback = (mmi_proc_func)NULL;
        	arg.parent_id = g_mmi_java_nw_cntx.sg_id_parent;
        	mmi_confirm_display_ext(STR_GLOBAL_SAVE_ASK, MMI_EVENT_QUERY, &arg);
// TODO: please remove softkey register and move softkey hdlr below, then fill this callback to arg.callback above
	} while(0);
    
    SetLeftSoftkeyFunction(mmi_java_nw_save_settings, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_java_nw_save_settings, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_java_nw_save_none, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_nw_get_account_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  account_id
 *****************************************************************************/
U32 mmi_java_nw_get_account_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_GET_ACCOUNT_ID, g_mmi_java_nw_cntx.network.account_id);

    return g_mmi_java_nw_cntx.network.account_id;
}


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
S8* mmi_java_nw_get_account_name(void)
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
    S32 prefer_mode = -1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_NW_IS_NEED_HIDE);
    
#ifndef __WIFI_SUPPORT__
    if (mmi_java_is_no_network_service() ||!srv_mode_switch_is_network_service_available())
    {
        is_hide = MMI_TRUE;
    }
    else
    {
    	is_hide = MMI_FALSE;		
    }
#else
#ifdef __MMI_WLAN_FEATURES__
    prefer_mode = mmi_netset_get_active_preferred_mode();
#endif
if (!srv_mode_switch_is_network_service_available()||
    mmi_java_is_no_network_service() && (MMI_JAVA_NW_P_GSM_ONLY == prefer_mode))        
    {
        is_hide = MMI_TRUE;
    }
    else
    {
    	is_hide = MMI_FALSE;		
    }
#endif

    MMI_TRACE(MMI_TRACE_STATE, INFO_MMI_JAVA_NW_STATE_D, is_hide);
    return is_hide;

}


static void mmi_java_set_audio_volume_req(U8 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_set_audio_volume_struct *req_ptr = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    //MMI_TRACE(MMI_TRACE_FUNC, FUNC_MMI_JAVA_SET_AUDIO_VOLUME, volume);

    req_ptr = (mmi_java_set_audio_volume_struct *) OslConstructDataPtr(
                sizeof(mmi_java_set_audio_volume_struct));
    req_ptr->volume = volume;
    mmi_java_send_message_from_active_mod(
        MOD_JAM, 
        MMI_J2ME_SAP, 
        MSG_ID_MMI_JAVA_SET_AUDIO_VOLUME_REQ, 
        req_ptr);
    
}
#endif /* __J2ME__ */ 
