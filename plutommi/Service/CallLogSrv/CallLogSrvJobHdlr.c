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
*  CallLogSrvJobHdlr.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/


/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMI_features.h"

#ifdef __MMI_TELEPHONY_SUPPORT__
#include "mmi_include.h"

#include "string.h"

#include "kal_general_types.h"
#include "kal_trace.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "stack_config.h"

#include "custom_calllog.h"
#include "common_nvram_editor_data_item.h"

#include "l4c2phb_enums.h"

#include "MMIDataType.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_utility_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_cb_mgr_gprot.h"

#include "PhbSrvGprot.h"

#include "mmi_rp_srv_calllog_def.h"

#include "CallLogSrvGprot.h"
#include "CallLogSrvIprot.h"
#include "CallLogSrvConfig.h"
#include "CallLogSrvUtils.h"
#include "CallLogSrvStore.h"
#include "CallLogSrvComp.h"
#include "CallLogSrvProt.h"

/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/
#define SRV_CLOG_NUM_ROUNDING(num, size)             (((num) + (size) - 1) / (size))

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/
typedef S32(*SRV_CLOG_JOB_HDLR) (srv_clog_cntx_struct *cntx, srv_clog_job_struct *job);

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

typedef enum
{
    SRV_CLOG_JOB_REVISE_LOGS_STATE_INIT,
    SRV_CLOG_JOB_REVISE_LOGS_STATE_START,
    SRV_CLOG_JOB_REVISE_LOGS_STAE_MAX_ITEM
}srv_clog_job_revise_logs_state_enum;


/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/
typedef struct
{
    /* U8 job_type; */ /* Comment it for slim, use this field as array index */
    SRV_CLOG_JOB_HDLR hdlr;
} srv_clog_job_hdlr_struct;

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/

static U8 srv_clog_job_continue_ind_hdlr(void *local_param, int mod_id, void *ilm);
static U8 srv_clog_sim_phb_last_number_ready_ind_hdlr(void *local_param, int mod_id, void *ilm);

/* Event initialization */

static void srv_clog_init_log_event_para(srv_clog_evt_log_op_struct *para, U16 evt_id, SRV_CLOG_HANDLE handle);
static void srv_clog_emit_ready_event(srv_clog_cntx_struct *cntx);
static void srv_clog_emit_add_log_event(
                SRV_CLOG_HANDLE handle,
                srv_clog_add_log_ret_enum add_ret,
                SRV_CLOG_ID new_log_id,
                U32 new_props,
                SRV_CLOG_ID old_log_id,
                U32 old_props);
static void srv_clog_emit_update_all_event(SRV_CLOG_HANDLE handle, U32 fields, srv_clog_log_identity_struct *idt);
static void srv_clog_emit_del_log_event(SRV_CLOG_HANDLE handle, SRV_CLOG_ID log_id, U32 props);
static void srv_clog_emit_del_all_event(SRV_CLOG_HANDLE handle, srv_clog_log_identity_struct *idt);

/* Job handling flow */
static srv_clog_job_struct *srv_clog_submit_next_init_job(srv_clog_cntx_struct *cntx, srv_clog_job_type_enum cur_type);
static srv_clog_job_type_enum srv_clog_get_next_init_job_type(
                                srv_clog_cntx_struct *cntx,
                                srv_clog_job_type_enum cur_job_type);
static SRV_CLOG_JOB_HDLR srv_clog_search_hdlr(U32 job_type);
static S32 srv_clog_process_done(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job);
static void srv_clog_init_done(srv_clog_cntx_struct *cntx);
static S32 srv_clog_process_next_job(srv_clog_cntx_struct *cntx);

static void srv_clog_send_job_continue_ind(void *user_data, U32 trans_id);

static S32 srv_clog_load_logs_hdlr(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job);
static S32 srv_clog_parse_logs_hdlr(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job);

#ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__
static S32 srv_clog_revise_logs_hdlr(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job);
static mmi_sim_enum srv_clog_sim_id_phb2mmi(phb_storage_enum phb_store_type);
#endif /* __MMI_CLOG_PHB_SYNC_SUPPORT__ */

static S32 srv_clog_add_log_hdlr(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job);
static void srv_clog_add_log_notify(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job);
static void srv_clog_cb_add_log_result(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job, srv_clog_ret_enum ret);

static S32 srv_clog_update_log_hdlr(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job);
static void srv_clog_log_call_time(srv_clog_update_log_req_struct *req_data);

static void srv_clog_cb_update_log_result(
                srv_clog_cntx_struct *cntx,
                srv_clog_job_struct *job,
                U32 updated_fields,
                S32 ret);
static S32 srv_clog_update_all_logs_hdlr(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job);
static void srv_clog_cb_update_all_logs_result(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job);

static S32 srv_clog_delete_log_by_id_hdlr(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job);
static void srv_clog_cb_delete_log_by_id_result(
                srv_clog_cntx_struct *cntx,
                srv_clog_job_struct *job,
                srv_clog_ret_enum ret);

static S32 srv_clog_delete_all_logs_hdlr(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job);
static void srv_clog_cb_delete_all_logs_result(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job);

#ifndef __MMI_CONTACT_SLIM__
static S32 srv_clog_search_list_log_ids_hdlr(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job);
static S32 srv_clog_cb_search_list_log_ids_result(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job);
#endif

static void srv_clog_start_first_job(srv_clog_cntx_struct *cntx, srv_clog_job_type_enum first_job_type);

static void srv_clog_cmn_set_log_id(srv_clog_log_struct *log, SRV_CLOG_ID new_log_id);
static void srv_clog_cmn_revise_log_id(srv_clog_job_type_enum job_type, void *req_data, SRV_CLOG_ID new_log_id);
static S32 srv_clog_revise_max_log_id(srv_clog_cntx_struct *cntx);

/*----------------------------------------------------------------------------*/
/* Extern Function Defines                                                    */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/
/* It use srv_clog_job_type_enum as array index from the 2nd element */
static const srv_clog_job_hdlr_struct g_srv_clog_job_hdlr_tbl[] = 
{
    /* Init jobs */
    {/* SRV_CLOG_JOB_TYPE_LOAD_LOGS, */             srv_clog_load_logs_hdlr},
    {/* SRV_CLOG_JOB_TYPE_PARSE_LOGS, */            srv_clog_parse_logs_hdlr},

#ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__
    {/* SRV_CLOG_JOB_TYPE_REVISE_LOGS, */           srv_clog_revise_logs_hdlr},
#endif

#ifdef __MMI_CLOG_SIM_SYNC_SUPPORT__
    {/* SRV_CLOG_JOB_TYPE_SIM_SYNC, */              srv_clog_sim_sync_hdlr},
#endif 
    {/* SRV_CLOG_JOB_TYPE_INIT_DONE, */             NULL},  /* A waste have to do now */

    /* Common jobs */
    {/* SRV_CLOG_JOB_TYPE_ADD_NEW_LOG, */           srv_clog_add_log_hdlr},
    {/* SRV_CLOG_JOB_TYPE_UPDATE_LOG, */            srv_clog_update_log_hdlr},
    {/* SRV_CLOG_JOB_TYPE_UPDATE_ALL_LOGS, */       srv_clog_update_all_logs_hdlr},
    {/* SRV_CLOG_JOB_TYPE_DEL_LOG_BY_ID, */         srv_clog_delete_log_by_id_hdlr},
    {/* SRV_CLOG_JOB_TYPE_DEL_ALL_LOGS, */          srv_clog_delete_all_logs_hdlr},

#ifdef __MMI_CLOG_MARK_SEVERAL__
    {/* SRV_CLOG_JOB_TYPE_DEL_MULTI_LOGS, */        srv_clog_delete_all_logs_hdlr},
#endif

#ifndef __MMI_CONTACT_SLIM__
    {/* SRV_CLOG_JOB_TYPE_SEARCH_LIST_IDS, */       srv_clog_search_list_log_ids_hdlr},
#else
    {/* SRV_CLOG_JOB_TYPE_SEARCH_LIST_IDS, */       NULL}, /* for 60 slim */
#endif

#ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__
    {/* SRV_CLOG_JOB_TYPE_UPDATE_PHB_EVT, */        srv_clog_phb_job_hdlr},
#endif
};

/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/

#define SRV_CLOG_JH_INIT


/*****************************************************************************
 * FUNCTION
 *  srv_clog_evt_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_evt_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler(
        MSG_ID_SRV_CLOG_JOB_CONTINUE_IND,
        (PsIntFuncPtr) srv_clog_job_continue_ind_hdlr,
        MMI_FALSE);

    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_PHB_LAST_NUMBER_READY_IND, 
            (PsIntFuncPtr) srv_clog_sim_phb_last_number_ready_ind_hdlr, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_phb_last_number_ready_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_param     [?]         
 *  mod_id          [IN]        
 *  ilm             [?]         
 * RETURNS
 *  
 *****************************************************************************/
static U8 srv_clog_sim_phb_last_number_ready_ind_hdlr(void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim_id;
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_id = mmi_frm_l4c_mod_to_sim((module_type)mod_id);
    SRV_CLOG_SET_BIT(cntx->flags, sim_id << SRV_CLOG_CNTX_FLAG_PHB_READY_POS);

    if (!SRV_CLOG_CHECK_BIT_GRP(cntx->flags, SRV_CLOG_CNTX_FLAG_PHB_READY_TOTAL, SRV_CLOG_CNTX_FLAG_PHB_READY_TOTAL))
        return 0;

    srv_clog_continue_process_job(cntx);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_send_job_continue_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  user_data       [?]         
 *  trans_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_send_job_continue_ind(void *user_data, U32 trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_job_continue_ind_struct *ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind = SRV_CLOG_NEW_ILM_DATA(srv_clog_job_continue_ind_struct);
    ind->trans_id = trans_id;
    ind->user_data = user_data;
    ind->para = NULL;

    mmi_frm_send_ilm(MOD_MMI, MSG_ID_SRV_CLOG_JOB_CONTINUE_IND, (oslParaType*) ind, NULL);
}

#define SRV_CLOG_JH_EVENT


/*****************************************************************************
 * FUNCTION
 *  srv_clog_init_log_event_para
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt_para        [?]         
 *  evt_id          [IN]        
 *  handle          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_init_log_event_para(srv_clog_evt_log_op_struct *evt_para, U16 evt_id, SRV_CLOG_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(evt_para, evt_id);
    evt_para->user_data = srv_clog_get_user_data(handle);
    evt_para->handle = handle;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_emit_ready_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_emit_ready_event(srv_clog_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_evt_srv_ready_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_ASSERT(srv_clog_is_ready());

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_CLOG_READY);
    evt.sup_merge = srv_clog_stl_support_merge(cntx->comp->style_mgr);
//FlowReserved
//    evt.sup_thread = srv_clog_stl_support_thread(cntx->comp->style_mgr);
    evt.sup_thread = 0;

    srv_clog_get_sim_unread_missed_call_num((U32*) & evt.ur_mclt_num, SRV_CLOG_SIM_IDX_MAX_ITEM);

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_EMIT_READY_EVENT,
        evt.sup_merge,
        evt.sup_thread,
        evt.ur_mclt_num[SRV_CLOG_SIM_IDX_SIM1],
        SRV_CLOG_TRC_SIM_VAL(MMI_SIM2, evt.ur_mclt_num[SRV_CLOG_SIM_IDX_SIM2]));

    MMI_FRM_CB_EMIT_EVENT(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_emit_add_log_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  add_ret         [IN]        
 *  new_log_id      [IN]        
 *  new_props       [IN]        
 *  old_log_id      [IN]        
 *  old_props       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_emit_add_log_event(
                SRV_CLOG_HANDLE handle,
                srv_clog_add_log_ret_enum add_ret,
                SRV_CLOG_ID new_log_id,
                U32 new_props,
                SRV_CLOG_ID old_log_id,
                U32 old_props)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_evt_add_log_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_clog_is_ready())
        return;

    srv_clog_init_log_event_para((srv_clog_evt_log_op_struct*) & evt, EVT_ID_SRV_CLOG_ADD_LOG, handle);
    evt.add_ret = add_ret;
    evt.new_idf.log_id = new_log_id;
    srv_clog_pi_p2i(new_props, (srv_clog_log_identity_struct*) & evt.new_idf);
    evt.old_idf.log_id = old_log_id;
    if (evt.add_ret == SRV_CLOG_ADD_LOG_RET_PURE_ADD)
        SRV_CLOG_INIT_IDT((srv_clog_log_identity_struct*) & evt.old_idf, 0, 0, 0, 0);
    else
        srv_clog_pi_p2i(old_props, (srv_clog_log_identity_struct*) & evt.old_idf);

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_EMIT_ADD_LOG_EVENT,
        handle,
        evt.add_ret,
        evt.new_idf.log_id,
        evt.new_idf.cate,
        evt.new_idf.sim_id,
        evt.new_idf.log_type,
        evt.new_idf.sub_type,
        evt.old_idf.log_id,
        evt.old_idf.cate,
        evt.old_idf.sim_id,
        evt.old_idf.log_type,
        evt.old_idf.sub_type);

    MMI_FRM_CB_EMIT_EVENT(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_emit_update_log_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  fields      [IN]        
 *  si_log      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_emit_update_log_event(SRV_CLOG_HANDLE handle, U32 fields, srv_clog_si_struct *si_log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_evt_update_log_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_clog_is_ready())
        return;

    srv_clog_init_log_event_para((srv_clog_evt_log_op_struct*) & evt, EVT_ID_SRV_CLOG_UPDATE_LOG, handle);
    evt.fields = fields;
    if (evt.fields == 0)
        evt.fields = SRV_CLOG_LOG_FIELD_ALL;

    srv_clog_si_log_si2cmn(si_log, 0, &evt.log);

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_EMIT_UPDATE_LOG_EVENT,
        handle,
        fields,
        SRV_CLOG_SI_GET_LOG_ID(si_log),
        SRV_CLOG_SI_GET_P(si_log));

    MMI_FRM_CB_EMIT_EVENT(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_emit_update_all_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  fields      [IN]        
 *  idt         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_emit_update_all_event(SRV_CLOG_HANDLE handle, U32 fields, srv_clog_log_identity_struct *idt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_evt_update_all_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_clog_is_ready())
        return;

    srv_clog_init_log_event_para((srv_clog_evt_log_op_struct*) & evt, EVT_ID_SRV_CLOG_UPDATE_ALL, handle);
    evt.fields = fields;
    if (evt.fields == 0)
        evt.fields = SRV_CLOG_LOG_FIELD_ALL;

    srv_clog_pi_cp_i(idt, &evt.idt);

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_EMIT_UPDATE_ALL_EVENT,
        handle,
        fields,
        idt->cate,
        idt->sim_id,
        idt->log_type,
        idt->sub_type);

    MMI_FRM_CB_EMIT_EVENT(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_emit_del_log_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  log_id      [IN]        
 *  props       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_emit_del_log_event(SRV_CLOG_HANDLE handle, SRV_CLOG_ID log_id, U32 props)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_evt_del_log_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_clog_is_ready())
        return;

    srv_clog_init_log_event_para((srv_clog_evt_log_op_struct*) & evt, EVT_ID_SRV_CLOG_DEL_LOG, handle);
    srv_clog_pi_p2i(props, (srv_clog_log_identity_struct*) & evt.idf);
    evt.idf.log_id = log_id;

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_EMIT_DEL_LOG_EVENT, handle, log_id, props);

    MMI_FRM_CB_EMIT_EVENT(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_emit_del_all_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  idt         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_emit_del_all_event(SRV_CLOG_HANDLE handle, srv_clog_log_identity_struct *idt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_evt_del_all_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_clog_is_ready())
        return;

    srv_clog_init_log_event_para((srv_clog_evt_log_op_struct*) & evt, EVT_ID_SRV_CLOG_DEL_ALL, handle);
    srv_clog_pi_cp_i(idt, &evt.idt);

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_EMIT_DEL_ALL_EVENT,
        handle,
        idt->cate,
        idt->sim_id,
        idt->log_type,
        idt->sub_type);

    MMI_FRM_CB_EMIT_EVENT(&evt);
}


#define SRV_CLOG_JH_JOB_MGR


/*****************************************************************************
 * FUNCTION
 *  srv_clog_start
 * DESCRIPTION
 *  this API should be called in boot up
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_clog_is_init())
        return SRV_CLOG_RET_NOT_INIT;

    SRV_CLOG_DUMP(SRV_CLOG_DUMP_TYPE_STL);

    SRV_CLOG_IT_TRACE((SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_START, SRV_CLOG_JOB_TYPE_CMN_INIT));

    cntx->state = SRV_CLOG_STATE_INITING;
    srv_clog_start_first_job(cntx, SRV_CLOG_JOB_TYPE_CMN_INIT);
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_start_first_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx                [?]         
 *  first_job_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_start_first_job(srv_clog_cntx_struct *cntx, srv_clog_job_type_enum first_job_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_job_struct *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = srv_clog_submit_next_init_job(cntx, first_job_type);

    SRV_CLOG_ASSERT(job);

    srv_clog_async_process(cntx, job);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_submit_next_init_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx            [?]         
 *  cur_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_clog_job_struct *srv_clog_submit_next_init_job(srv_clog_cntx_struct *cntx, srv_clog_job_type_enum cur_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_job_struct *job;
    srv_clog_job_type_enum next_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* It's the first time to start the initialized job, need to add a new job node */
    next_type = srv_clog_get_next_init_job_type(cntx, cur_type);

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SUBMIT_NEXT_INIT_JOB, cur_type, next_type);
    if (next_type == SRV_CLOG_JOB_TYPE_INIT_DONE)
        return NULL;
    job = srv_clog_job_submit_head(cntx->comp->job_mgr, next_type);
    job->pid = srv_clog_new_pid(cntx);
    return job;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_get_next_init_job_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx                [?]         
 *  cur_job_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_clog_job_type_enum srv_clog_get_next_init_job_type(
                                srv_clog_cntx_struct *cntx,
                                srv_clog_job_type_enum cur_job_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_job_type_enum next_job_type = SRV_CLOG_JOB_TYPE_INIT_DONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cur_job_type)
    {
        case SRV_CLOG_JOB_TYPE_CMN_INIT:
            next_job_type = SRV_CLOG_JOB_TYPE_LOAD_LOGS;
            break;

        case SRV_CLOG_JOB_TYPE_LOAD_LOGS:
            next_job_type = SRV_CLOG_JOB_TYPE_PARSE_LOGS;
            break;

        case SRV_CLOG_JOB_TYPE_PARSE_LOGS:
    #ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__
            next_job_type = SRV_CLOG_JOB_TYPE_REVISE_LOGS;
            break;
            
        case SRV_CLOG_JOB_TYPE_REVISE_LOGS:    
    #endif /* __MMI_CLOG_PHB_SYNC_SUPPORT__ */

    #ifdef __MMI_CLOG_SIM_SYNC_SUPPORT__
            if (srv_clog_stl_support_sim_sync(cntx->comp->style_mgr))
                next_job_type = SRV_CLOG_JOB_TYPE_SIM_SYNC;
            else
                next_job_type = SRV_CLOG_JOB_TYPE_INIT_DONE;
            break;

        case SRV_CLOG_JOB_TYPE_SIM_SYNC:
    #endif /* __MMI_CLOG_SIM_SYNC_SUPPORT__ */       
            next_job_type = SRV_CLOG_JOB_TYPE_INIT_DONE;
            break;

        default:
            SRV_CLOG_ASSERT(0);
            break;
    }
    return next_job_type;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_async_process
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 *  job         [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_async_process(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_ASYNC_PROCESS,
        job == NULL ? -1 : job->job_type,
        job == NULL ? 0 : job->pid);

    srv_clog_send_job_continue_ind((void*)cntx, (U32) (job == NULL ? 0 : job->pid));
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_job_continue_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_param     [?]         
 *  mod_id          [IN]        
 *  ilm             [?]         
 * RETURNS
 *  
 *****************************************************************************/
static U8 srv_clog_job_continue_ind_hdlr(void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_job_continue_ind_struct *ind = (srv_clog_job_continue_ind_struct*) local_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_continue_process_job((srv_clog_cntx_struct*) ind->user_data);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_process_new_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 *  job_mgr     [?]     
 *  job         [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_process_new_job(srv_clog_cntx_struct *cntx, srv_clog_job_mgr_struct *job_mgr, srv_clog_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    S32 num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!job_mgr)
        job_mgr = job->comp->job_mgr;
    
    num = srv_clog_job_num(job_mgr);
    ret = (num <= 1 || srv_clog_job_is_blocked(job_mgr) || srv_clog_job_index(job_mgr, 0) == job);

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_PROCESS_NEW_JOB, job->job_type, job->job_state, job->proc_state, ret);

    if (ret)
        srv_clog_async_process(cntx, job);
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_continue_process_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_continue_process_job(srv_clog_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = SRV_CLOG_RET_OK;
    srv_clog_job_struct *job;
    SRV_CLOG_JOB_HDLR hdlr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_clog_job_is_empty(cntx->comp->job_mgr))
    {
        MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_CONTINUE_PROCESS_JOB_EMPTY);
        return SRV_CLOG_RET_OK;
    }

    job = srv_clog_job_index(cntx->comp->job_mgr, 0);

    MMI_TRACE
        (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_CONTINUE_PROCESS_JOB_START,
         job->job_type, job->job_state, job->proc_state, job->cursor, job->init_value);

    if (job->job_state == SRV_CLOG_JOB_STATE_READY)
    {
        job->job_state = SRV_CLOG_JOB_STATE_HANDLING;
    }
    else if (job->job_state == SRV_CLOG_JOB_STATE_CANCELED || 
        job->job_state == SRV_CLOG_JOB_STATE_FINISHED)
    {
        return srv_clog_process_done(cntx, job);
    }
    hdlr = srv_clog_search_hdlr(job->job_type);
    if (hdlr)
        ret = (*hdlr) (cntx, job);

    SRV_CLOG_DUMP(SRV_CLOG_DUMP_TYPE_ALL);

    MMI_TRACE
        (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_CONTINUE_PROCESS_JOB_DONE,
         job->job_type, job->job_state, job->proc_state, job->cursor, job->init_value);

    if (job->job_state == SRV_CLOG_JOB_STATE_WAITING)
    {
        return SRV_CLOG_RET_WAITING;    /* revise return code */
    }
    if (hdlr == NULL || 
        job->job_state == SRV_CLOG_JOB_STATE_CANCELED || 
        job->job_state == SRV_CLOG_JOB_STATE_FINISHED ||
        job->job_state == SRV_CLOG_JOB_STATE_PENDING)
    {
        return srv_clog_process_done(cntx, job);
    }
    ret = srv_clog_async_process(cntx, job);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_search_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static SRV_CLOG_JOB_HDLR srv_clog_search_hdlr(U32 job_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_IT_ASSERT(job_type < SRV_CLOG_JOB_TYPE_MAX_ITEM);

    return g_srv_clog_job_hdlr_tbl[job_type].hdlr;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_process_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 *  job         [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_process_done(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 job_num;
    srv_clog_job_struct *new_job;
    srv_clog_job_struct *next_job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* First to remove those jobs handled */
    next_job = srv_clog_job_index(cntx->comp->job_mgr, 0);
    while (next_job &&
        (next_job->job_state == SRV_CLOG_JOB_STATE_CANCELED || next_job->job_state == SRV_CLOG_JOB_STATE_FINISHED))
    {
        SRV_CLOG_IT_TRACE((
            SRV_CLOG_TRC_INFO,
            TRC_SRV_CLOG_PROCESS_NEXT_JOB_DONE,
            next_job->job_type,
            next_job->job_state,
            next_job->proc_state));

        srv_clog_job_remove_head(cntx->comp->job_mgr);
        srv_clog_job_free(next_job);
        next_job = srv_clog_job_index(cntx->comp->job_mgr, 0);
    }
    if (next_job && next_job->job_state == SRV_CLOG_JOB_STATE_WAITING)
        return SRV_CLOG_RET_OK;

    if (next_job && next_job->job_state == SRV_CLOG_JOB_STATE_PENDING)
        next_job = srv_clog_job_remove_head(cntx->comp->job_mgr);
        
    if (cntx->state == SRV_CLOG_STATE_INITING)
    {
        /* May start SIM Sync before ready on Modis: Temp solution as SIM sync is just before init done job */
        if (job->job_type > SRV_CLOG_JOB_TYPE_INIT_DONE && !srv_clog_job_num(cntx->comp->job_mgr))
        {
            srv_clog_init_done(cntx);
        }
        else if (job->job_type <= SRV_CLOG_JOB_TYPE_INIT_DONE)
        {
            new_job = srv_clog_submit_next_init_job(cntx, (srv_clog_job_type_enum)job->job_type);
            if (!new_job)   /* All initialized jobs are done */
                srv_clog_init_done(cntx);
        }
    }
    if (next_job && next_job->job_state == SRV_CLOG_JOB_STATE_PENDING)
    {
        srv_clog_job_add_tail(cntx->comp->job_mgr, next_job);
        job_num = srv_clog_job_num(cntx->comp->job_mgr);
        if ( job_num == 1)
            return SRV_CLOG_RET_OK;
    }
    srv_clog_process_next_job(cntx);
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_init_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_init_done(srv_clog_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* should set to ready before emit callback event because other AP may to get data in this event. */
    cntx->state = SRV_CLOG_STATE_READY;

#ifdef __MMI_CLOG_ATCMD_SUPPORT__
    srv_clog_at_notify_ready(cntx);
#endif

    srv_clog_emit_ready_event(cntx);

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_INIT_DONE, 0, cntx->max_log_id, cntx->max_pid);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_process_next_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_process_next_job(srv_clog_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_job_struct *next_job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    next_job = srv_clog_job_index(cntx->comp->job_mgr, 0);
    if (!next_job)
    {
        MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_PROCESS_NEXT_JOB_FREE);

        return SRV_CLOG_RET_OK;
    }
    srv_clog_async_process(cntx, next_job);
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_revise_max_log_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_revise_max_log_id(srv_clog_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 num;
    srv_clog_job_struct *job;
    U32 max_log_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get from history */
    cntx->max_log_id = srv_clog_si_get_max_log_id(cntx->comp->si_tbl);

    /* Check if any new log added before service is ready */
    max_log_id = cntx->max_log_id;
    num = srv_clog_job_num(cntx->comp->job_mgr);
    for (i = 0; i < num; i++)
    {
        job = srv_clog_job_index(cntx->comp->job_mgr, i);
        if (job->job_type == SRV_CLOG_JOB_TYPE_ADD_NEW_LOG || job->job_type == SRV_CLOG_JOB_TYPE_UPDATE_LOG)
        {
            if (job->log_id <= SRV_CLOG_LOG_ID_START)
            {
                job->cursor = job->log_id;
                job->log_id += max_log_id;
                if (job->log_id > cntx->max_log_id)
                    cntx->max_log_id = job->log_id;
                srv_clog_cmn_revise_log_id((srv_clog_job_type_enum)job->job_type, job->req_data, job->log_id);
            }
            else
                job->cursor = 0;    /* not used */
        }
    }
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_cmn_revise_log_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job_type        [IN]        
 *  req_data        [?]         
 *  new_log_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_cmn_revise_log_id(srv_clog_job_type_enum job_type, void *req_data, SRV_CLOG_ID new_log_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_job_add_log_req_struct *new_req;
    srv_clog_update_log_req_struct *update_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (job_type == SRV_CLOG_JOB_TYPE_ADD_NEW_LOG)
    {
        new_req = (srv_clog_job_add_log_req_struct*) req_data;
        SRV_CLOG_SI_SET_LOG_ID(&new_req->si_log, new_log_id);
    }
    else if (job_type == SRV_CLOG_JOB_TYPE_UPDATE_LOG)
    {
        update_req = (srv_clog_update_log_req_struct*) req_data;
        srv_clog_cmn_set_log_id(&update_req->log_data, new_log_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_cmn_set_log_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  log             [?]         
 *  new_log_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_cmn_set_log_id(srv_clog_log_struct *log, SRV_CLOG_ID new_log_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    log->data.call_log.log_id = new_log_id;
}

#define SRV_CLOG_JH_JOB_HDLR


/*****************************************************************************
 * FUNCTION
 *  srv_clog_load_logs_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 *  job         [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_load_logs_hdlr(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 read_num;
    U32 max_read_size;
    S32 ret = SRV_CLOG_RET_OK;
    srv_clog_si_tbl_struct *si_tbl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    si_tbl = cntx->comp->si_tbl;
    if (!job->cnf_data)        
    {
        job->cnf_data = srv_clog_job_new_para(job, 
            sizeof(srv_clog_st_log_struct) * SRV_CLOG_ST_MULTI_LOGS_PER_LOAD_MAX_NUM);
    }
    max_read_size = SRV_CLOG_NUM_ROUNDING(SRV_CLOG_LOG_MAX_NUM - job->cursor, SRV_CLOG_ST_MULTI_LOGS_PER_LOAD_MAX_NUM);

    for (i = 0; i < max_read_size; i++)
    {
        if (i != max_read_size - 1) /* check if it is the last batch */
            read_num = SRV_CLOG_ST_MULTI_LOGS_PER_LOAD_MAX_NUM;
        else
            read_num = SRV_CLOG_LOG_MAX_NUM - job->cursor;
        ret = srv_clog_st_read_logs(
                job->cursor,
                read_num,
                (srv_clog_st_log_struct*) job->cnf_data);
        if (ret >= 0)
        {
            ret = srv_clog_si_parse(si_tbl, job->cursor, (srv_clog_st_log_struct*) job->cnf_data, read_num);
            job->cursor += read_num;
        }
        else
        {
            job->init_value++;
            break;
        }
        if (job->cursor >= SRV_CLOG_LOG_MAX_NUM)
        {
            ret = SRV_CLOG_RET_OK;
            break;
        }
        if (i >= SRV_CLOG_ST_MULTI_OP_MAX_NUM)
        {
            /* Not release job->cnf_data */
            ret = SRV_CLOG_RET_CONTINUE;
            break;
        }
    }
    
    if (ret == SRV_CLOG_RET_CONTINUE)
        return ret;

    SRV_CLOG_IT_TRACE((
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_LOAD_LOGS_HDLR,
        job->cursor,
        job->init_value,
        srv_clog_si_total_num(si_tbl)));

    job->job_state = SRV_CLOG_JOB_STATE_FINISHED;
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_parse_logs_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 *  job         [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_parse_logs_hdlr(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_idx_parse(cntx->comp->idx_tbl);
    srv_clog_revise_max_log_id(cntx);
    job->job_state = SRV_CLOG_JOB_STATE_FINISHED;
    return SRV_CLOG_RET_OK;
}


#ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_clog_revise_logs_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 *  job         [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_revise_logs_hdlr(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 update_count;
    mmi_sim_enum sim_id;
    U32 changed_sim_grp = 0;
    SRV_PHB_ID invalid_phb_id;
    srv_clog_si_struct *si_log;
    phb_storage_enum phb_store_type;
    srv_clog_st_log_struct st_log;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (job->proc_state == SRV_CLOG_JOB_REVISE_LOGS_STATE_INIT || job->proc_state == SRV_CLOG_JOB_REVISE_LOGS_STATE_START)
    {
#ifdef __MMI_CLOG_SIM_SYNC_SUPPORT__
        U32 sync_style = 0;

        /* Check if delete all old logs, if so, no need to revise as all are deleted */
        srv_clog_stl_get_style(cntx->comp->style_mgr, SRV_CLOG_STYLE_TYPE_SIM_SYNC, &sync_style, NULL);
        if (SRV_CLOG_CHECK_BIT(sync_style, SRV_CLOG_STYLE_SIM_SYNC_CLEAR_OLD))
        {
            SRV_CLOG_IT_TRACE((SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_REVISE_LOGS_HDLR_CHECK_STYLE, sync_style));

            job->job_state = SRV_CLOG_JOB_STATE_FINISHED;
            return SRV_CLOG_RET_OK;
        }
#endif /* __MMI_CLOG_SIM_SYNC_SUPPORT__ */ 

        /* Check L4PHB is ready or not */
        if (!SRV_CLOG_CHECK_BIT_GRP(cntx->flags, SRV_CLOG_CNTX_FLAG_PHB_READY_TOTAL, SRV_CLOG_CNTX_FLAG_PHB_READY_TOTAL))
        {
            /* My be the SIM card is locked when initializing, but user can make SOS call at that time */
            job->job_state = SRV_CLOG_JOB_STATE_PENDING;
            
            MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_REVISE_LOGS_HDLR_CHECK_READY, cntx->flags, job->job_state, job->proc_state);

            return SRV_CLOG_RET_CONTINUE;
        }
        /* Check if any SIM replaced */
        for (i = 0; i < MMI_SIM_TOTAL; i++)
        {
            if (srv_clog_is_single_sim_replaced((mmi_sim_enum)SRV_CLOG_IDX2BIT(i)))
            {
                SRV_CLOG_IT_TRACE((SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_REVISE_LOGS_HDLR_SIM_REPLACED, 
                    cntx->flags, changed_sim_grp, SRV_CLOG_IDX2BIT(i)));

                SRV_CLOG_SET_BIT(changed_sim_grp, SRV_CLOG_IDX2BIT(i));
            }
        }
        if (!changed_sim_grp)
        {
            MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_REVISE_LOGS_HDLR_SIM_NOT_REPLACED,
                cntx->flags, job->job_state, job->proc_state, changed_sim_grp);

            job->job_state = SRV_CLOG_JOB_STATE_FINISHED;
            return SRV_CLOG_RET_OK;
        }
        
        job->job_state = SRV_CLOG_JOB_STATE_HANDLING; //should keep this 
        job->init_value = srv_clog_si_total_num(cntx->comp->si_tbl);
        job->proc_state = SRV_CLOG_JOB_REVISE_LOGS_STATE_START;
    }
    if (job->proc_state == SRV_CLOG_JOB_REVISE_LOGS_STATE_START)
    {
        SRV_CLOG_SET_INVALID_PHB_ID(invalid_phb_id);
        for (update_count = 0; job->cursor < SRV_CLOG_LOG_MAX_NUM && job->cursor2 < job->init_value; job->cursor++)
        {
            if (update_count >= SRV_CLOG_ST_SINGLE_OP_MAX_NUM)
            {
                SRV_CLOG_IT_TRACE((SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_REVISE_LOGS_HDLR_ASYNC_UPDATE,
                    job->job_state, job->proc_state, job->init_value, job->cursor, update_count));

                return SRV_CLOG_RET_CONTINUE;
            }
            si_log = srv_clog_si_index(cntx->comp->si_tbl, job->cursor);
            if (!srv_clog_si_is_valid(si_log))
                continue;
            job->cursor2++; /* count of logs */

            /* Dump Logs without valid PHB id */
        #ifdef __SRV_CLOG_DUMP__
            if (!SRV_CLOG_IS_PHB_ID_VALID(SRV_CLOG_SI_GET_PHB_ID(si_log)))
            {
                MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_REVISE_LOGS_HDLR_CHECK_PHB_ID,
                   job->job_state, job->proc_state, job->init_value, job->cursor, SRV_CLOG_SI_GET_PHB_ID(si_log));

                SRV_CLOG_DUMP_LOG(job->cursor, si_log);
            }
       #endif /* __SRV_CLOG_DUMP__ */

            /* Check if SIM Storage */
            phb_store_type = (phb_storage_enum)srv_phb_get_storage(srv_phb_get_store_index_by_number_id(SRV_CLOG_SI_GET_PHB_ID(si_log)));
            if (phb_store_type == PHB_STORAGE_NVRAM)
            {
                MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_REVISE_LOGS_HDLR_CHECK_PHB_STORAGE,
                    phb_store_type, SRV_CLOG_SI_GET_LOG_ID(si_log), SRV_CLOG_SI_GET_PHB_ID(si_log));
                continue;
            }
            /* Check if the SIM card to create this log is replaced */
            sim_id = srv_clog_sim_id_phb2mmi(phb_store_type);
            if (!SRV_CLOG_CHECK_BIT(changed_sim_grp, sim_id))
            {
                MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_REVISE_LOGS_HDLR_CHECK_LOG_SIM_ID,
                   job->cursor, changed_sim_grp, sim_id, SRV_CLOG_SI_GET_LOG_ID(si_log), SRV_CLOG_SI_GET_PHB_ID(si_log));
                continue;
            }

            SRV_CLOG_IT_TRACE((SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_REVISE_LOGS_HDLR_FIND_ONE_LOG,
                    job->init_value, job->cursor, changed_sim_grp, sim_id, SRV_CLOG_SI_GET_LOG_ID(si_log), SRV_CLOG_SI_GET_PHB_ID(si_log)));

            SRV_CLOG_DUMP_LOG(job->cursor, si_log);

            /* update log: set invalid phb_id, remove name and emit update event */
            srv_clog_si_update_phb_info(si_log, SRV_CLOG_LOG_FIELD_PHB_ID|SRV_CLOG_LOG_FIELD_NAME,
                invalid_phb_id, NULL, NULL);
            srv_clog_si_si2st(si_log, &st_log);
            srv_clog_st_write_log(job->cursor, &st_log);
            srv_clog_emit_update_log_event(job->handle, SRV_CLOG_LOG_FIELD_PHB_ID|SRV_CLOG_LOG_FIELD_NAME, si_log);
            update_count++;

            MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_REVISE_LOGS_HDLR_REVISE_DONE,
                    update_count, SRV_CLOG_SI_GET_LOG_ID(si_log), SRV_CLOG_SI_GET_PHB_ID(si_log), SRV_CLOG_SI_GET_P(si_log));

            SRV_CLOG_DUMP_LOG(job->cursor, si_log);

        }
        if (job->cursor < job->init_value)
            return SRV_CLOG_RET_CONTINUE;
        job->job_state = SRV_CLOG_JOB_STATE_FINISHED;

    }

    return SRV_CLOG_RET_OK;


}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_revise_log_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void                   
 * RETURNS
 *  
 *****************************************************************************/
void srv_clog_revise_log_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_job_struct  *job;
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = srv_clog_job_submit_head(cntx->comp->job_mgr, SRV_CLOG_JOB_TYPE_REVISE_LOGS);
    
    job->pid = srv_clog_new_pid(cntx);
    srv_clog_process_new_job(cntx, cntx->comp->job_mgr, job);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_id_phb2mmi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  phb_store_type          [?]         
 * RETURNS
 *  
 *****************************************************************************/
static mmi_sim_enum srv_clog_sim_id_phb2mmi(phb_storage_enum phb_store_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    static const phb_storage_enum phb_storage_list[] = 
        {
            PHB_STORAGE_SIM,
#if (defined(MMI_MAX_SIM_NUM) && MMI_MAX_SIM_NUM >= 2)                
            PHB_STORAGE_SIM2,
#endif

#if (defined(MMI_MAX_SIM_NUM) && MMI_MAX_SIM_NUM >= 3)                
            PHB_STORAGE_SIM3,
#endif

#if (defined(MMI_MAX_SIM_NUM) && MMI_MAX_SIM_NUM >= 4)                
            PHB_STORAGE_SIM4
#endif
        };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        if (phb_storage_list[i] == phb_store_type)
            break;
    }

    if (i == MMI_SIM_TOTAL)
        return MMI_SIM_NONE;
    
    return (mmi_sim_enum)SRV_CLOG_IDX2BIT(i);
}

#endif /* __MMI_CLOG_PHB_SYNC_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  srv_clog_add_log_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 *  job         [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_add_log_hdlr(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_comp_struct *comp;
    srv_clog_job_add_log_req_struct *req_data;
    srv_clog_st_log_struct st_log;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    comp = job->comp;
    req_data = (srv_clog_job_add_log_req_struct*) job->req_data;
    srv_clog_idx_add_prepare(comp->idx_tbl, req_data);
    srv_clog_si_si2st(&req_data->si_log, &st_log);

    if (req_data->need_merge)   /* pure merge case, merge new log (replace), no matter full or not */
    {
    if (SRV_CLOG_TIME_DETAIL_MAX_NUM > 1) /* update old timestamp and duration info to new log */
    {
        srv_clog_si_struct *old_si_log = srv_clog_si_index(comp->si_tbl, req_data->old_sit_idx);

    #if (defined(__MMI_CLOG_SLIM__) && !defined(__MMI_VOIP__))
        srv_clog_si_struct new_si_log;
        srv_clog_si_st2si(&st_log, &new_si_log);
        /* copy old timestamp and duration to new log's sturct, but only need copy (SRV_CLOG_TIME_DETAIL_MAX_NUM - 1) */
        memmove(&new_si_log.base_log.timestamp[1], &old_si_log->base_log.timestamp[0], sizeof(old_si_log->base_log.timestamp[0]) * (SRV_CLOG_TIME_DETAIL_MAX_NUM - 1));
        memmove(&new_si_log.duration[1], &old_si_log->duration[0], sizeof(old_si_log->duration[0]) * (SRV_CLOG_TIME_DETAIL_MAX_NUM - 1));
        srv_clog_si_si2st(&new_si_log, &st_log);
    #else
        srv_clog_st_log_struct old_st_log;
        srv_clog_call_info_struct *old_call_info;
        srv_clog_call_info_struct *new_call_info;
        srv_clog_si_si2st(old_si_log, &old_st_log);
        old_call_info = (srv_clog_call_info_struct*) &old_st_log;
        new_call_info = (srv_clog_call_info_struct*) &st_log;
        /* copy old timestamp and duration to new log's sturct, but only need copy (SRV_CLOG_TIME_DETAIL_MAX_NUM - 1) */
        memmove(&new_call_info->timestamp[1], &old_call_info->timestamp[0], sizeof(old_call_info->timestamp[0]) * (SRV_CLOG_TIME_DETAIL_MAX_NUM - 1));
        memmove(&new_call_info->duration[1], &old_call_info->duration[0], sizeof(old_call_info->duration[0]) * (SRV_CLOG_TIME_DETAIL_MAX_NUM - 1));
    #endif
    
        srv_clog_si_st2si(&st_log, &req_data->si_log); /* will use si_log to update si table and idx table */
    }

        job->ret = srv_clog_st_write_log(req_data->old_sit_idx, &st_log);
    }
    else if (!req_data->need_merge && req_data->is_full)    /* add new but full, delete the oldest one */
    {
        if (req_data->old_sit_idx != req_data->best_sit_idx)
            job->ret = srv_clog_st_delete_log(req_data->old_sit_idx);
        if (job->ret == SRV_CLOG_RET_OK)
            srv_clog_st_write_log(req_data->best_sit_idx, &st_log);
    }
    else    /* add and not full, pure add case */
    {
        job->ret = srv_clog_st_write_log(req_data->best_sit_idx, &st_log);
    }

    if (job->ret == SRV_CLOG_RET_OK)
    {   
        /* pure merge or pure replace, should first delete old one */
        if (req_data->need_merge || !req_data->need_merge && req_data->is_full)
        {
            /* the sort order may be changed */
            srv_clog_idx_delete_id(comp->idx_tbl, req_data->old_log_id);
            srv_clog_si_delete_index(comp->si_tbl, req_data->old_sit_idx);
        }
        job->ret = (srv_clog_ret_enum)srv_clog_si_add_update(comp->si_tbl, (srv_clog_job_add_log_req_struct*) job->req_data);
        job->ret = (srv_clog_ret_enum)srv_clog_idx_add_update(comp->idx_tbl, (srv_clog_job_add_log_req_struct*) job->req_data);
        srv_clog_add_log_notify(cntx, job);
    }
    job->job_state = SRV_CLOG_JOB_STATE_FINISHED;
    return SRV_CLOG_RET_OK;


}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_add_log_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 *  job         [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_add_log_notify(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_add_log_ret_enum add_ret;
    srv_clog_job_add_log_req_struct *req_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_data = (srv_clog_job_add_log_req_struct*) job->req_data;

    /* Callback */
    srv_clog_cb_add_log_result(cntx, job, job->ret);

#ifdef __MMI_CLOG_ATCMD_SUPPORT__
    /* AT command */
    srv_clog_at_notify_update(
        SRV_CLOG_AT_UPDATE_ADD,
        cntx,
        SRV_CLOG_SI_GET_P(&req_data->si_log),
        NULL,
        &req_data->si_log);
#endif /* __MMI_CLOG_ATCMD_SUPPORT__ */

    /* Sevice event */
    if (req_data->need_merge)
        add_ret = SRV_CLOG_ADD_LOG_RET_PURE_MERGE;
    else if (req_data->is_full)
        add_ret = SRV_CLOG_ADD_LOG_RET_REPLACE_OLDEST;
    else
        add_ret = SRV_CLOG_ADD_LOG_RET_PURE_ADD;
    srv_clog_emit_add_log_event(
        job->handle,
        add_ret,
        job->log_id,
        SRV_CLOG_SI_GET_P(&req_data->si_log),
        req_data->old_log_id,
        req_data->old_props);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_cb_add_log_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]         
 *  job         [?]         
 *  ret         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_cb_add_log_result(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job, srv_clog_ret_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_add_log_cnf_struct cnf_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!job->func_cb)
        return;

    if (job->cursor)
        cnf_data.log_id = job->cursor;
    else
        cnf_data.log_id = job->log_id;
    cnf_data.ret = ret;
    (job->func_cb) (job->handle, job->pid, NULL, &cnf_data, MMI_FALSE, ret);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_update_log_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 *  job         [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_update_log_hdlr(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 sit_idx;
    srv_clog_comp_struct *comp;
    srv_clog_si_struct *cur_si_log;
    srv_clog_si_struct temp_si_log;
    srv_clog_update_log_req_struct *req_data;
    srv_clog_st_log_struct  st_log;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if has this log */
    comp = job->comp;
    req_data = (srv_clog_update_log_req_struct*) job->req_data;
    ret = srv_clog_si_id2idx(comp->si_tbl, job->log_id, &sit_idx);
    if (ret == SRV_CLOG_RET_NOT_FOUND)
    {
        srv_clog_cb_update_log_result(cntx, job, 0, ret);
        srv_clog_log_call_time(req_data); /* Write Total call duration to NVRAM */
        job->job_state = SRV_CLOG_JOB_STATE_FINISHED;
        return ret;
    }
    cur_si_log = srv_clog_si_index(comp->si_tbl, (U16) sit_idx);
    memcpy(&temp_si_log, cur_si_log, sizeof(srv_clog_si_struct));
    srv_clog_si_update_log(&temp_si_log, &req_data->log_data, req_data->req_fields);
    srv_clog_si_si2st(&temp_si_log, &st_log);
    ret = srv_clog_st_write_log(sit_idx, &st_log);
    if (ret != SRV_CLOG_RET_OK)
    {
        SRV_CLOG_IT_TRACE((
            SRV_CLOG_TRC_INFO,
            TRC_SRV_CLOG_UDPATE_LOG_HDLR,
            job->log_id,
            sit_idx,
            ret,
            SRV_CLOG_SI_GET_P(cur_si_log)));

        srv_clog_cb_update_log_result(cntx, job, 0, ret);
        return ret;
    }
    
    srv_clog_si_update_log(cur_si_log, &req_data->log_data, req_data->req_fields);
    srv_clog_cb_update_log_result(cntx, job, req_data->req_fields, SRV_CLOG_RET_OK);

    srv_clog_si_log_si2cmn(cur_si_log, 0, &req_data->log_data);
    srv_clog_log_call_time(req_data);

#ifdef __MMI_CLOG_ATCMD_SUPPORT__
    srv_clog_at_notify_update(SRV_CLOG_AT_UPDATE_UPD, cntx, SRV_CLOG_SI_GET_P(cur_si_log), NULL, cur_si_log);
#endif
    srv_clog_emit_update_log_event(job->handle, req_data->req_fields, cur_si_log);
    job->job_state = SRV_CLOG_JOB_STATE_FINISHED;
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_log_call_time
 * DESCRIPTION
 *  Note: when happen missed call, UCM also wirte duration (which mean ring time, not call time);
 *  so we need check if it is missed call
 * PARAMETERS
 *  req_data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_log_call_time(srv_clog_update_log_req_struct *req_data)
{
#ifdef __MMI_CLOG_CALL_TIME__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_call_log_struct *clog = &(req_data->log_data.data.call_log);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_IT_ASSERT(clog->cate == SRV_CLOG_CATE_CALL);
    SRV_CLOG_IT_ASSERT(SRV_CLOG_CHECK_BIT(req_data->req_fields, SRV_CLOG_LOG_FIELD_DURATION) &&
        clog->duration[SRV_CLOG_LASTEST_TIME_IDX]);

    if (clog->log_type == SRV_CLOG_CLT_MISSED)
        return;

    srv_clog_ctime_update_data(
        (mmi_sim_enum)clog->sim_id,
        (srv_clog_call_type_enum)clog->sub_type,
        (srv_clog_clt_enum)clog->log_type,
        clog->duration[SRV_CLOG_LASTEST_TIME_IDX]);

    SRV_CLOG_IT_TRACE((
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_LOG_CALL_TIME,
        clog->log_type,
        clog->sim_id,
        clog->sub_type,
        clog->duration[SRV_CLOG_LASTEST_TIME_IDX]));

#endif /* __MMI_CLOG_CALL_TIME__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_cb_update_log_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx                [?]         
 *  job                 [?]         
 *  updated_fields      [IN]        
 *  ret                 [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_cb_update_log_result(
                srv_clog_cntx_struct *cntx,
                srv_clog_job_struct *job,
                U32 updated_fields,
                S32 ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_update_log_cnf_struct cnf_data;
    srv_clog_update_log_req_struct *req_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!job->func_cb)
        return;

    req_data = (srv_clog_update_log_req_struct*) job->req_data;
    if (job->cursor)
        cnf_data.log_id = job->cursor;
    else
        cnf_data.log_id = job->log_id;
    cnf_data.req_fields = req_data->req_fields;
    cnf_data.updated_fields = updated_fields;
    cnf_data.ret = (srv_clog_ret_enum)ret;
    (job->func_cb) (job->handle, job->pid, job->req_data, &cnf_data, MMI_FALSE, (srv_clog_ret_enum)ret);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_update_all_logs_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 *  job         [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_update_all_logs_hdlr(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 j;
    U32 ur_num;
    srv_clog_si_struct *si_log;
    srv_clog_st_log_struct st_log;
    srv_clog_update_all_logs_req_struct *req_data = (srv_clog_update_all_logs_req_struct*) job->req_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = job->cursor, j = 0; i < SRV_CLOG_LOG_MAX_NUM; i++)
    {
        si_log = srv_clog_si_index(job->comp->si_tbl, i);
        if (!srv_clog_si_is_valid(si_log) ||
            !srv_clog_pi_is_ip_sub((srv_clog_log_identity_struct*) req_data, SRV_CLOG_SI_GET_P(si_log)))
            continue;
        
        /* Only support unread number field here */
        ur_num = SRV_CLOG_SI_GET_URNUM(si_log);
        if (ur_num == 0 &&
            SRV_CLOG_CHECK_BIT_GRP(
                req_data->req_fields,
                SRV_CLOG_LOG_FIELD_UNREAD_NUM,
                SRV_CLOG_LOG_FIELD_UNREAD_NUM))
        {
            continue;
        }
        if (SRV_CLOG_CHECK_BIT_GRP
            (req_data->req_fields, SRV_CLOG_LOG_FIELD_IS_NEW_EVENT, SRV_CLOG_LOG_FIELD_IS_NEW_EVENT) &&
            !SRV_CLOG_CHECK_BIT(SRV_CLOG_SI_GET_P(si_log), SRV_CLOG_LSP_NEW_EVENT))
        {
            continue;
        }
        srv_clog_si_update_cmn_info(si_log, req_data);
        srv_clog_si_si2st(si_log, &st_log);
        job->ret = srv_clog_st_write_log(i, &st_log);  /* not check result */
        if (job->ret == SRV_CLOG_RET_OK)
            job->init_value++;
        j++;
        if (j >= SRV_CLOG_ST_SINGLE_OP_MAX_NUM)
        {
            job->cursor = i;
            return SRV_CLOG_RET_CONTINUE;
        }
    }
    job->cursor = i;
    if (job->cursor < SRV_CLOG_LOG_MAX_NUM)
        return SRV_CLOG_RET_CONTINUE;
    srv_clog_cb_update_all_logs_result(cntx, job);

#ifdef __MMI_CLOG_ATCMD_SUPPORT__
    srv_clog_at_notify_update(SRV_CLOG_AT_UPDATE_UPD_ALL, cntx, 0, (srv_clog_log_identity_struct*) req_data, NULL);
#endif
    srv_clog_emit_update_all_event(job->handle, req_data->req_fields, (srv_clog_log_identity_struct*) req_data);
    job->job_state = SRV_CLOG_JOB_STATE_FINISHED;
return SRV_CLOG_RET_OK;

    
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_cb_update_all_logs_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 *  job         [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_cb_update_all_logs_result(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_update_all_logs_cnf_struct cnf_data;
    srv_clog_update_all_logs_req_struct *req_data = (srv_clog_update_all_logs_req_struct*) job->req_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!job->func_cb)
        return;

    cnf_data.req_fields = req_data->req_fields;
    cnf_data.updated_fields = req_data->req_fields;
    cnf_data.num_updated = job->init_value;
    cnf_data.ret = job->ret;
    (job->func_cb) (job->handle, job->pid, job->req_data, (void*)&cnf_data, MMI_FALSE, cnf_data.ret);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_delete_log_by_id_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 *  job         [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_delete_log_by_id_hdlr(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = SRV_CLOG_RET_OK;
    U32 sit_idx;
    srv_clog_comp_struct *comp;
    srv_clog_si_struct *si_log;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    comp = job->comp;
    ret = srv_clog_si_id2idx(comp->si_tbl, job->log_id, &sit_idx);

    if (ret != SRV_CLOG_RET_OK)
    {
        srv_clog_cb_delete_log_by_id_result(cntx, job, (srv_clog_ret_enum)ret);
        job->job_state = SRV_CLOG_JOB_STATE_FINISHED;
        return ret;
    }
    si_log = srv_clog_si_index(comp->si_tbl, sit_idx);
    job->init_value = SRV_CLOG_SI_GET_P(si_log);
    ret = srv_clog_st_delete_log((SRV_CLOG_ID) sit_idx);
    if (ret != SRV_CLOG_RET_OK)
    {
        srv_clog_cb_delete_log_by_id_result(cntx, job, (srv_clog_ret_enum)ret);
        job->job_state = SRV_CLOG_JOB_STATE_FINISHED;
        return ret;
    }

    SRV_CLOG_IT_TRACE((SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_DELETE_LOG_BY_ID_HDLR, job->log_id, sit_idx, ret, job->init_value));

    ret = srv_clog_idx_delete_id(comp->idx_tbl, job->log_id);
    ret = srv_clog_si_delete_index(comp->si_tbl, sit_idx);

    srv_clog_cb_delete_log_by_id_result(cntx, job, SRV_CLOG_RET_OK);

#ifdef __MMI_CLOG_ATCMD_SUPPORT__
    srv_clog_at_notify_update(SRV_CLOG_AT_UPDATE_DEL, cntx, job->init_value, NULL, NULL);
#endif
    srv_clog_emit_del_log_event(job->handle, job->log_id, job->init_value);
    job->job_state = SRV_CLOG_JOB_STATE_FINISHED;
return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_cb_delete_log_by_id_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]         
 *  job         [?]         
 *  ret         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_cb_delete_log_by_id_result(
                srv_clog_cntx_struct *cntx,
                srv_clog_job_struct *job,
                srv_clog_ret_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!job->func_cb)
        return;

    (job->func_cb) (job->handle, job->pid, (void*)job->log_id, (void*)job->log_id, MMI_FALSE, ret);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_delete_all_logs_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 *  job         [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_delete_all_logs_hdlr(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 j;
    S32 ret;
    srv_clog_comp_struct *comp;
    srv_clog_si_struct *si_log;
    srv_clog_idx_info_enum info_type;
    U32 sit_idx;
    srv_clog_idx_tbl_struct *idx_tbl;
    srv_clog_si_tbl_struct *si_tbl;
#ifdef __MMI_CLOG_MARK_SEVERAL__
    srv_clog_del_multi_logs_req_struct *req;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CLOG_MARK_SEVERAL__
    req = (srv_clog_del_multi_logs_req_struct *)job->req_data;
#endif
    comp = job->comp;
    idx_tbl = comp->idx_tbl;
    si_tbl = comp->si_tbl;
    srv_clog_idx_refresh(
        comp->idx_tbl,
        SRV_CLOG_LIST_LEVEL_SORT,
        (srv_clog_log_identity_struct*) job->req_data,
        &info_type);
    job->u16val1 = info_type;
    job->init_value = srv_clog_idx_total_num(comp->idx_tbl, info_type, NULL);
    if (job->init_value == 0)   /* empty */
    {
        srv_clog_cb_delete_all_logs_result(cntx, job);
        job->job_state = SRV_CLOG_JOB_STATE_FINISHED;
        return SRV_CLOG_RET_OK;
    }

    for (i = job->cursor, j = 0; i < job->init_value; i++)
    {
        sit_idx = srv_clog_idx_index(idx_tbl, info_type, i);
        si_log = srv_clog_si_index(si_tbl, sit_idx);
        if (!srv_clog_si_is_valid(si_log))
            continue;

    #ifdef __MMI_CLOG_MARK_SEVERAL__
        if (job->job_type == SRV_CLOG_JOB_TYPE_DEL_MULTI_LOGS)
        {
            if (job->cursor2 >= SRV_CLOG_DEL_MULTI_LOG_MAX_NUM || SRV_CLOG_IS_ELM_INVALID(req->log_ids[job->cursor2]))
                break; /* finish delete multi logs, so need stop */
            if (SRV_CLOG_SI_GET_LOG_ID(si_log) != req->log_ids[job->cursor2])
                continue;
            else /* need to delete this log */
                job->cursor2++;
        }
    #endif /* __MMI_CLOG_MARK_SEVERAL__ */
        ret = srv_clog_st_delete_log(sit_idx);
        if (ret != SRV_CLOG_RET_OK)
            job->ret = SRV_CLOG_RET_PARTIAL_DELETED;    /* deleted failed */
        else
            srv_clog_si_delete_index(comp->si_tbl, sit_idx);
        j++;
        if (j >= SRV_CLOG_ST_SINGLE_OP_MAX_NUM)
        {
            job->cursor += j;
            return SRV_CLOG_RET_CONTINUE;
        }
    }
    /* All logs are deleted */
    job->ret = (srv_clog_ret_enum)srv_clog_idx_reset(comp->idx_tbl, SRV_CLOG_IDX_INFO_BASE);
    srv_clog_cb_delete_all_logs_result(cntx, job);

#ifdef __MMI_CLOG_ATCMD_SUPPORT__
    srv_clog_at_notify_update(
        SRV_CLOG_AT_UPDATE_DEL_ALL,
        cntx,
        0,
        (srv_clog_log_identity_struct*) job->req_data,
        NULL);
#endif /* __MMI_CLOG_ATCMD_SUPPORT__ */

    srv_clog_emit_del_all_event(job->handle, (srv_clog_log_identity_struct*) job->req_data);
    /* Check if can reset log id, no log and no job expecially add_log job */
    if (0 == srv_clog_si_total_num(comp->si_tbl) && 0 == srv_clog_job_num(comp->job_mgr))
        srv_clog_reset_log_id(cntx);
    job->job_state = SRV_CLOG_JOB_STATE_FINISHED;
return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_cb_delete_all_logs_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 *  job         [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_cb_delete_all_logs_result(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 left_num;
    srv_clog_comp_struct *comp;
    srv_clog_del_all_logs_cnf_struct del_all_cnf_data;
    srv_clog_del_multi_logs_cnf_struct del_multi_cnf_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!job->func_cb)
        return;
    comp = srv_clog_get_cur_comp(cntx, job->handle);
    left_num = srv_clog_idx_total_num(comp->idx_tbl, (srv_clog_idx_info_enum)job->u16val1, NULL);
    if (job->job_type == SRV_CLOG_JOB_TYPE_DEL_ALL_LOGS)
    {
        del_all_cnf_data.total_num = job->init_value;
        del_all_cnf_data.deleted_num = job->init_value - left_num;
        del_all_cnf_data.ret = job->ret;        
        (job->func_cb) (job->handle, job->pid, NULL, &del_all_cnf_data, MMI_FALSE, del_all_cnf_data.ret);
    }
    else
    {
        del_multi_cnf_data.total_num = job->init_value;
        del_multi_cnf_data.deleted_num = job->init_value - left_num;
        del_multi_cnf_data.ret = job->ret;        
        (job->func_cb) (job->handle, job->pid, NULL, &del_multi_cnf_data, MMI_FALSE, del_multi_cnf_data.ret);
    }
}


#ifndef __MMI_CONTACT_SLIM__
/*****************************************************************************
 * FUNCTION
 *  srv_clog_search_list_log_ids_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 *  job         [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_search_list_log_ids_hdlr(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    srv_clog_comp_struct *comp;
    srv_clog_search_list_log_ids_req_struct *req_data;
    srv_clog_search_list_log_ids_cnf_struct *cnf_data;
    srv_clog_idx_info_enum info_type;
    U32 idx_tbl_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    comp = job->comp;

    job->cnf_data = srv_clog_job_new_para(job, sizeof(srv_clog_search_list_log_ids_cnf_struct));
    memset(job->cnf_data, 0x0, sizeof(srv_clog_search_list_log_ids_cnf_struct));
    req_data = (srv_clog_search_list_log_ids_req_struct*) job->req_data;
    cnf_data = (srv_clog_search_list_log_ids_cnf_struct*) job->cnf_data;

    srv_clog_pi_cp_i((srv_clog_log_identity_struct*) req_data, (srv_clog_log_identity_struct*) cnf_data);
    cnf_data->search_fields = req_data->search_fields;
    cnf_data->start_by = req_data->start_by;
    cnf_data->start_elm = req_data->start_elm;
    srv_clog_idx_refresh(
        comp->idx_tbl,
        SRV_CLOG_LIST_LEVEL_SORT,
        (srv_clog_log_identity_struct*) req_data,
        &info_type);

    do
    {
        if (req_data->start_by == SRV_CLOG_BY_IDX)
        {
            idx_tbl_idx = req_data->start_elm;
            if (idx_tbl_idx >= srv_clog_idx_total_num(comp->idx_tbl, info_type, NULL))
            {
                job->ret = SRV_CLOG_RET_NOT_FOUND;
                srv_clog_cb_search_list_log_ids_result(cntx, job);
                job->job_state = SRV_CLOG_JOB_STATE_FINISHED;
                return SRV_CLOG_RET_NOT_FOUND;
            }
        }
        else
        {
            ret = srv_clog_idx_id2idx(comp->idx_tbl, info_type, req_data->start_elm, &idx_tbl_idx, NULL);
            if (ret != SRV_CLOG_RET_OK)
            {
                job->ret = SRV_CLOG_RET_NOT_FOUND;
                srv_clog_cb_search_list_log_ids_result(cntx, job);
                job->job_state = SRV_CLOG_JOB_STATE_FINISHED;
                return SRV_CLOG_RET_NOT_FOUND;
            }
        }

        job->ret = (srv_clog_ret_enum)srv_clog_idx_search_ids_by_idx(comp->idx_tbl, info_type, req_data, cnf_data, idx_tbl_idx);
        ret = srv_clog_cb_search_list_log_ids_result(cntx, job);
        if (ret == SRV_CLOG_RET_STOP)
            break;
        if (cnf_data->next_elm != SRV_CLOG_INVALID_ELM)
            req_data->start_elm = cnf_data->next_elm;
        /* CB NOTIFY */
    } while (job->ret == SRV_CLOG_RET_OK && cnf_data->next_elm != SRV_CLOG_INVALID_ELM);

    job->job_state = SRV_CLOG_JOB_STATE_FINISHED;
    return job->ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_cb_search_list_log_ids_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 *  job         [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_cb_search_list_log_ids_result(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL more = MMI_FALSE;
    srv_clog_search_list_log_ids_req_struct *req_data;
    srv_clog_search_list_log_ids_cnf_struct *cnf_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!job->func_cb)
        return SRV_CLOG_RET_OK;

    req_data = (srv_clog_search_list_log_ids_req_struct*) job->req_data;
    cnf_data = (srv_clog_search_list_log_ids_cnf_struct*) job->cnf_data;
    if (cnf_data->id_num >= SRV_CLOG_LOG_ID_LIST_MAX_NUM)
        more = MMI_TRUE; /* still have query data */
    return (job->func_cb) (job->handle, job->pid, req_data, cnf_data, more, job->ret);
}
#endif /* __MMI_CONTACT_SLIM__ */

#endif /* __MMI_TELEPHONY_SUPPORT__ */
