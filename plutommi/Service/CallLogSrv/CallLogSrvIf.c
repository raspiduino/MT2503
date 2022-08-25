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
*  CallLogSrvIf.c
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
#include "mmi_include.h"

#ifdef __MMI_TELEPHONY_SUPPORT__
#include "string.h"

#include "kal_general_types.h"
#include "kal_trace.h"

#include "custom_voip_config.h"
#include "custom_phb_config.h"
#include "custom_calllog.h"
#include "nvram_common_defs.h"
#include "common_nvram_editor_data_item.h"

#include "MMIDataType.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"

#include "ProcedureGprot.h"

#include "CallLogSrvGprot.h"
#include "CallLogSrvIprot.h"
#include "CallLogSrvConfig.h"
#include "CallLogSrvUtils.h"
#include "CallLogSrvComp.h"
#include "CallLogSrvProt.h"

#include "ShutDownSrvGprot.h"


/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/
static SRV_CLOG_ID srv_clog_cmn_get_log_id(srv_clog_log_struct *log);

static S32 srv_clog_get_idt(
            srv_clog_inst_struct *inst,
            srv_clog_log_identity_struct *src_idt,
            srv_clog_log_identity_struct *out_idt);

static srv_clog_job_struct* srv_clog_alloc_job_with_info(
            srv_clog_job_type_enum job_type,
            SRV_CLOG_HANDLE handle,
            S32 pid,
            SRV_CLOG_BASE_CB func_cb,
            void *req_data,
            U32 para_size);

static void srv_clog_revise_add_req(srv_clog_log_struct *log, SRV_CLOG_ID log_id);
static void srv_clog_log_call_req_to_cmn(srv_clog_log_call_req_struct *call_req, srv_clog_log_struct *cmn_log);

/*----------------------------------------------------------------------------*/
/* Extern Function Defines                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/

#define SRV_CLOG_IF_EVT


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sat_refresh_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id          [IN]        
 *  ef_file_idx     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_sat_refresh_hdlr(mmi_sim_enum sim_id, U16 ef_file_idx)
{
#ifdef __MMI_CLOG_SIM_SYNC_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_clog_sim_sat_refresh_hdlr(sim_id, ef_file_idx);
#else /* __MMI_CLOG_SIM_SYNC_SUPPORT__ */ 
    return SRV_CLOG_RET_OK;
#endif /* __MMI_CLOG_SIM_SYNC_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_shutdown_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arg         [?]         
 *  id_info     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
extern mmi_frm_proc_result_enum srv_clog_shutdown_hdlr(void *arg, const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CLOG_SIM_SYNC_SUPPORT__
    return srv_clog_sim_shutdown_hdlr(arg, id_info);
#else 
    return MMI_FRM_PROC_RESULT_COMPLETED;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_shutdown_evt_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt             [?]         
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET srv_clog_shutdown_evt_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CLOG_SIM_SYNC_SUPPORT__
    srv_clog_sim_shutdown_evt_hdlr(evt);
#else /* __MMI_CLOG_SIM_SYNC_SUPPORT__ */
    if (evt->evt_id == EVT_ID_SRV_SHUTDOWN_HANDLER_RESET)
    {
        srv_clog_evt_init();
    }
#endif /* __MMI_CLOG_SIM_SYNC_SUPPORT__ */

    return MMI_RET_OK;
}


#ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  srv_clog_phb_evt_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_RET srv_clog_phb_evt_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_clog_phb_sync_evt_hdlr(evt);
}
#endif /* __MMI_CLOG_PHB_SYNC_SUPPORT__ */


#define SRV_CLOG_IF_NUM


/*****************************************************************************
 * FUNCTION
 *  srv_clog_get_unread_missed_call_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_clog_get_unread_missed_call_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_clog_get_sim_unread_missed_call_num(NULL, 0);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_get_sim_unread_missed_call_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  num_list        [?]         
 *  sim_num         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_clog_get_sim_unread_missed_call_num(U32 *num_list, U32 sim_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_clog_is_ready())
        return 0;

    return srv_clog_idx_get_ur_mclt_num(cntx->comp->idx_tbl, num_list, sim_num);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_get_list_num_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  identity        [IN]        
 *  num_info        [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_get_list_num_info(
        SRV_CLOG_HANDLE handle,
        const srv_clog_log_identity_struct *identity,
        srv_clog_num_info_struct *num_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    srv_clog_comp_struct *comp;
    srv_clog_log_identity_struct idt;
    srv_clog_inst_struct *inst = SRV_CLOG_INST(handle);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_PARAM_CHECK(srv_clog_pi_is_i_invalid(identity) || !num_info, SRV_CLOG_RET_INVALID_PARAM);
    
    if (!srv_clog_is_ready())
        return SRV_CLOG_RET_NOT_READY;

    comp = srv_clog_get_cur_comp(srv_clog_get_cntx(), handle);
    srv_clog_get_idt(inst, (srv_clog_log_identity_struct*) identity, &idt);
    
    ret = srv_clog_idx_get_num_info(comp->idx_tbl, &idt, num_info);

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_GET_LIST_NUM_INFO,
        handle,
        idt.cate,
        idt.sim_id,
        idt.log_type,
        idt.sub_type,
        num_info->num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS],
        num_info->num[SRV_CLOG_LOG_NUM_TYPE_UNREAD_NUM],
        ret);

    return ret;
}

#define SRV_CLOG_IF_SYNC_ACT


/*****************************************************************************
 * FUNCTION
 *  srv_clog_get_idt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [?]     
 *  src_idt     [?]     
 *  out_idt     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_get_idt(
            srv_clog_inst_struct *inst,
            srv_clog_log_identity_struct *src_idt,
            srv_clog_log_identity_struct *out_idt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_log_identity_struct *tmp_idt = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (inst)
        tmp_idt = &inst->idt;
    
    srv_clog_pi_merge_ii(tmp_idt, src_idt, out_idt);
    
    srv_clog_pi_revise_i(out_idt, MMI_TRUE);
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_get_list_log_ids
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  req_data        [IN]        
 *  cnf_data        [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_get_list_log_ids(
        SRV_CLOG_HANDLE handle,
        const srv_clog_get_list_log_ids_req_struct *req_data,
        srv_clog_get_list_log_ids_cnf_struct *cnf_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_inst_struct *inst = SRV_CLOG_INST(handle);
    srv_clog_comp_struct *comp;
    srv_clog_idx_info_enum info_type;
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_PARAM_CHECK (!req_data || !cnf_data, SRV_CLOG_RET_INVALID_PARAM);
    SRV_CLOG_PARAM_CHECK(srv_clog_pi_is_i_invalid((const srv_clog_log_identity_struct*)req_data), SRV_CLOG_RET_INVALID_PARAM);
    SRV_CLOG_PARAM_CHECK(req_data->log_num > SRV_CLOG_LOG_ID_LIST_MAX_NUM, SRV_CLOG_RET_INVALID_PARAM);


    comp = srv_clog_get_cur_comp(cntx, handle);
    srv_clog_get_idt(inst, (srv_clog_log_identity_struct*) req_data, (srv_clog_log_identity_struct*) cnf_data);
    
    cnf_data->start_by = req_data->start_by;
    cnf_data->start_elm = req_data->start_elm;

    srv_clog_idx_refresh(
        comp->idx_tbl,
        SRV_CLOG_LIST_LEVEL_SORT,
        (srv_clog_log_identity_struct*) cnf_data,
        &info_type);
    cnf_data->ret = (srv_clog_ret_enum)srv_clog_idx_get_list_ids(comp->idx_tbl, info_type, req_data, cnf_data);

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_GET_LIST_LOG_IDS,
        handle,
        cnf_data->cate,
        cnf_data->sim_id,
        cnf_data->log_type,
        cnf_data->sub_type,
        cnf_data->start_by,
        cnf_data->start_elm,
        cnf_data->log_num,
        cnf_data->next_start_elm,
        cnf_data->ret);

    return cnf_data->ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_get_list_log
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  req_data        [IN]        
 *  cnf_data        [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_get_list_log(
        SRV_CLOG_HANDLE handle,
        const srv_clog_get_list_log_req_struct *req_data,
        srv_clog_get_list_log_cnf_struct *cnf_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_inst_struct *inst = SRV_CLOG_INST(handle);
    srv_clog_comp_struct *comp;
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_PARAM_CHECK (!req_data || !cnf_data, SRV_CLOG_RET_INVALID_PARAM);
    SRV_CLOG_PARAM_CHECK(srv_clog_pi_is_i_invalid((const srv_clog_log_identity_struct*)req_data), SRV_CLOG_RET_INVALID_PARAM);
    SRV_CLOG_PARAM_CHECK(req_data->get_by >= SRV_CLOG_BY_MAX_ITEM ||
        req_data->get_by == SRV_CLOG_BY_ID && req_data->get_elm == SRV_CLOG_INVALID_ELM ||
        req_data->get_by == SRV_CLOG_BY_IDX && req_data->get_elm >= SRV_CLOG_LOG_MAX_NUM, SRV_CLOG_RET_INVALID_PARAM);


    cnf_data->get_by = req_data->get_by;
    cnf_data->get_elm = req_data->get_elm;
    cnf_data->fields = req_data->fields;

    comp = srv_clog_get_cur_comp(cntx, handle);
    srv_clog_get_idt(inst, (srv_clog_log_identity_struct*) req_data, (srv_clog_log_identity_struct*) cnf_data);

    cnf_data->ret = (srv_clog_ret_enum)srv_clog_idx_get_list_log(
                        comp->idx_tbl,
                        SRV_CLOG_LIST_LEVEL_SORT,
                        (srv_clog_get_list_log_req_struct*) req_data,
                        cnf_data);

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_GET_LIST_LOG,
        handle,
        req_data->cate,
        req_data->sim_id,
        req_data->log_type,
        req_data->sub_type,
        req_data->get_by,
        req_data->get_elm,
        req_data->fields,
        cnf_data->ret);

    return cnf_data->ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_get_log_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  log_id      [IN]        
 *  fields      [IN]        
 *  log         [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_get_log_by_id(SRV_CLOG_HANDLE handle, SRV_CLOG_ID log_id, U32 fields, srv_clog_log_struct *log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_PARAM_CHECK (SRV_CLOG_IS_ELM_INVALID(log_id) || !log, SRV_CLOG_RET_INVALID_PARAM);

    if (!srv_clog_is_ready())
        return SRV_CLOG_RET_NOT_READY;

    ret = srv_clog_idx_get_log_by_id(cntx->comp->idx_tbl, SRV_CLOG_IDX_INFO_UNKNOWN, log_id, fields, log);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_get_last_log
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  req_data        [IN]        
 *  cnf_data        [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_get_last_log(
        SRV_CLOG_HANDLE handle,
        const srv_clog_get_last_log_req_struct *req_data,
        srv_clog_get_last_log_cnf_struct *cnf_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_inst_struct *inst = SRV_CLOG_INST(handle);
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();
    srv_clog_comp_struct *comp;
    srv_clog_si_struct *si_log;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_PARAM_CHECK (!req_data || !cnf_data, SRV_CLOG_RET_INVALID_PARAM);
    SRV_CLOG_PARAM_CHECK (srv_clog_pi_is_i_invalid((const srv_clog_log_identity_struct*)req_data), SRV_CLOG_RET_INVALID_PARAM);

    comp = srv_clog_get_cur_comp(cntx, handle);
    srv_clog_get_idt(inst, (srv_clog_log_identity_struct*) req_data, (srv_clog_log_identity_struct*) cnf_data);

    cnf_data->fields = req_data->fields;
    si_log = srv_clog_idx_get_last_log(comp->idx_tbl, (srv_clog_log_identity_struct*) cnf_data);

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_GET_LAST_LOG,
        handle,
        req_data->cate,
        req_data->sim_id,
        req_data->log_type,
        req_data->sub_type,
        req_data->fields,
        si_log != NULL ? SRV_CLOG_RET_OK : SRV_CLOG_RET_NOT_FOUND);

    if (si_log == NULL)
    {
        cnf_data->ret = SRV_CLOG_RET_NOT_FOUND;
        return SRV_CLOG_RET_NOT_FOUND;
    }
    srv_clog_si_log_si2cmn(si_log, req_data->fields, &cnf_data->log);

    SRV_CLOG_DUMP_LOG(SRV_CLOG_IDX_INVALID_IDX, si_log);

    return SRV_CLOG_RET_OK;
}

#define SRV_CLOG_IF_ASYNC_ACT


/*****************************************************************************
 * FUNCTION
 *  srv_clog_alloc_and_set_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  pid             [IN]        
 *  req_data        [IN]        
 *  func_cb         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_clog_job_struct* srv_clog_alloc_job_with_info(
        srv_clog_job_type_enum job_type,
        SRV_CLOG_HANDLE handle,
        S32 pid,
        SRV_CLOG_BASE_CB func_cb,
        void *req_data,
        U32 para_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_job_struct *job;
    srv_clog_comp_struct *comp;
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_clog_is_init())
        srv_clog_init(NULL);

    comp = srv_clog_get_cur_comp(cntx, handle);
    if (srv_clog_get_inst_priority(handle))
        job = srv_clog_job_submit_head(comp->job_mgr, job_type);
    else
        job = srv_clog_job_submit_tail(comp->job_mgr, job_type);
    if (!pid)
        pid = srv_clog_new_pid(cntx);
    job->pid = pid;
    job->handle = handle;
    job->func_cb = func_cb;
    job->comp = comp;
    job->req_data = srv_clog_job_new_para(job, para_size);
    if (job->req_data && req_data)
        memcpy(job->req_data, req_data, para_size);
    return job;
}



/*****************************************************************************
 * FUNCTION
 *  srv_clog_log_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  pid             [IN]        
 *  req_data        [IN]        
 *  log_id          [?]         
 *  func_cb         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_log_call(
        SRV_CLOG_HANDLE handle,
        S32 pid,
        const srv_clog_log_call_req_struct *req_data,
        SRV_CLOG_ID *log_id,
        SRV_CLOG_BASE_CB func_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_log_struct cmn_log;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_PARAM_CHECK (!req_data, SRV_CLOG_RET_INVALID_PARAM);
    SRV_CLOG_PARAM_CHECK(srv_clog_pi_is_i_invalid((const srv_clog_log_identity_struct*)req_data), SRV_CLOG_RET_INVALID_PARAM);

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_LOG_CALL,
        handle,
        pid,
        req_data->cate,
        req_data->sim_id,
        req_data->log_type,
        req_data->sub_type,
        req_data->phb_id,
        req_data->timestamp,
        req_data->is_private_cid);

    srv_clog_log_call_req_to_cmn((srv_clog_log_call_req_struct*) req_data, &cmn_log);
    return srv_clog_add_log(handle, pid, (const srv_clog_log_struct*)&cmn_log, log_id, func_cb);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_log_call_req_to_cmn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  call_req        [?]     
 *  cmn_log         [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_log_call_req_to_cmn(srv_clog_log_call_req_struct *call_req, srv_clog_log_struct *cmn_log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_call_log_struct *call_log;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cmn_log->cate = SRV_CLOG_CATE_CALL;
    call_log = &cmn_log->data.call_log;
    srv_clog_pi_cp_i((srv_clog_log_identity_struct*) call_req, (srv_clog_log_identity_struct*) call_log);
    call_log->log_id = SRV_CLOG_INVALID_ELM;
    call_log->phb_id = call_req->phb_id;
    call_log->timestamp[SRV_CLOG_LASTEST_TIME_IDX] = call_req->timestamp;
    call_log->duration[SRV_CLOG_LASTEST_TIME_IDX] = 0;
    call_log->total_num = 1;
    if (call_log->log_type == SRV_CLOG_CLT_MISSED)
    {
        call_log->unread_num = 1;
        call_log->is_new_event = 1;
    }
    else
    {
        call_log->unread_num = 0;
        call_log->is_new_event = 0;
    }
    call_log->is_private_cid = call_req->is_private_cid;
    mmi_wcsncpy((WCHAR*) call_log->cid, (const WCHAR*)call_req->cid, SRV_CLOG_CID_MAX_LEN);
    mmi_wcsncpy((WCHAR*) call_log->name, (const WCHAR*)call_req->name, SRV_CLOG_NAME_MAX_LEN);

    if (SRV_PHB_INVALID_INDEX == call_log->phb_id.contact_index)  // FDN will reset name, don't save it
    {
        memset(call_log->name, 0x0, SRV_CLOG_NAME_MAX_LEN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_log_duration
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  pid             [IN]        
 *  req_data        [IN]        
 *  func_cb         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_log_duration(
        SRV_CLOG_HANDLE handle,
        S32 pid,
        const srv_clog_log_duration_req_struct *req_data,
        SRV_CLOG_BASE_CB func_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    srv_clog_log_struct *log;
    srv_clog_update_log_req_struct update_req = { 0 };
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_PARAM_CHECK (!req_data || SRV_CLOG_IS_ELM_INVALID(req_data->log_id), SRV_CLOG_RET_INVALID_PARAM);

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_LOG_DURATION,
        handle,
        pid,
        req_data->log_id,
        req_data->duration,
        func_cb == NULL ? 0 : 1);

    update_req.req_fields = SRV_CLOG_LOG_FIELD_DURATION;
    log = &update_req.log_data;
    log->cate = SRV_CLOG_CATE_CALL;
    log->data.call_log.log_id = req_data->log_id;
    /* Please note: UCM may give improper log type here, but we do not care it indeed.*/
    srv_clog_pi_cp_i((srv_clog_log_identity_struct *)req_data, (srv_clog_log_identity_struct *)&log->data.call_log);
    log->data.call_log.duration[SRV_CLOG_LASTEST_TIME_IDX] = req_data->duration;

    ret = srv_clog_update_log(handle, pid, (const srv_clog_update_log_req_struct*)&update_req, func_cb);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_add_log
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  pid         [IN]        
 *  log         [IN]        
 *  log_id      [?]         
 *  func_cb     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_add_log(
        SRV_CLOG_HANDLE handle,
        S32 pid,
        const srv_clog_add_log_req_struct *log,
        SRV_CLOG_ID *log_id,
        SRV_CLOG_BASE_CB func_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_job_struct *job;
    SRV_CLOG_ID new_log_id;
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();
    srv_clog_si_struct *si_log;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_PARAM_CHECK (!log || srv_clog_pi_is_i_invalid((const srv_clog_log_identity_struct*)&log->data), SRV_CLOG_RET_INVALID_PARAM);

    job = srv_clog_alloc_job_with_info(SRV_CLOG_JOB_TYPE_ADD_NEW_LOG, handle, pid,func_cb, 
          NULL, sizeof(srv_clog_job_add_log_req_struct));

    /* General new log id */
    new_log_id = srv_clog_new_log_id(cntx);
#ifdef __MMI_CLOG_SIM_SYNC_SUPPORT__
    /* This flag is only used for SIM sync now */
    if (SRV_CLOG_CHECK_BIT(srv_clog_get_inst_flags(handle), SRV_CLOG_INST_FLAG_HAS_LOG_ID))
        new_log_id = log->data.call_log.log_id;
#endif /* __MMI_CLOG_SIM_SYNC_SUPPORT__ */

    if (log_id)
        *log_id = new_log_id;

    srv_clog_revise_add_req((srv_clog_log_struct*) log, new_log_id);

    job->log_id = new_log_id;
    si_log = &(((srv_clog_job_add_log_req_struct*) job->req_data)->si_log);
    srv_clog_si_log_cmn2si((srv_clog_log_struct*) log, si_log);


    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_ADD_LOG,
        handle,
        job->pid,
        new_log_id,
        SRV_CLOG_SI_GET_P(si_log),
        SRV_CLOG_SI_GET_PHB_ID(si_log),
        log->data.call_log.timestamp[SRV_CLOG_LASTEST_TIME_IDX],
        func_cb == NULL ? 0 : 1);

    srv_clog_process_new_job(cntx, NULL, job);
    return job->pid;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_revise_add_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  log         [?]         
 *  log_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_revise_add_req(srv_clog_log_struct *log, SRV_CLOG_ID log_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    log->data.call_log.log_id = log_id;

#ifndef __MMI_CLOG_PHB_SYNC_SUPPORT__
    SRV_CLOG_SET_INVALID_PHB_ID(log->data.call_log.phb_id);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_update_log
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  pid             [IN]        
 *  req_data        [IN]        
 *  func_cb         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_update_log(
        SRV_CLOG_HANDLE handle,
        S32 pid,
        const srv_clog_update_log_req_struct *req_data,
        SRV_CLOG_BASE_CB func_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_job_struct *job;
    //srv_clog_comp_struct *comp;
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();
    srv_clog_log_identity_struct *idt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_PARAM_CHECK (!req_data, SRV_CLOG_RET_INVALID_PARAM);
    SRV_CLOG_PARAM_CHECK(srv_clog_pi_is_i_invalid((const srv_clog_log_identity_struct*)&req_data->log_data.data) , SRV_CLOG_RET_INVALID_PARAM);

    job = srv_clog_alloc_job_with_info(SRV_CLOG_JOB_TYPE_UPDATE_LOG, handle, pid, func_cb, 
         (void*)req_data, sizeof(srv_clog_update_log_req_struct));

    job->log_id = srv_clog_cmn_get_log_id((srv_clog_log_struct*) & req_data->log_data);

    idt = (srv_clog_log_identity_struct*) (&req_data->log_data.data.call_log);
    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_UPDATE_LOG,
        handle,
        job->pid,
        job->log_id,
        req_data->req_fields,
        idt->cate,
        idt->sim_id,
        idt->log_type,
        idt->sub_type,
        req_data->log_data.data.call_log.unread_num,
        req_data->log_data.data.call_log.duration[SRV_CLOG_LASTEST_TIME_IDX]);

    srv_clog_process_new_job(cntx, NULL, job);
    return job->pid;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_cmn_get_log_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  log     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static SRV_CLOG_ID srv_clog_cmn_get_log_id(srv_clog_log_struct *log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return log->data.call_log.log_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_update_all_logs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  pid             [IN]        
 *  req_data        [IN]        
 *  func_cb         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_update_all_logs(
        SRV_CLOG_HANDLE handle,
        S32 pid,
        const srv_clog_update_all_logs_req_struct *req_data,
        SRV_CLOG_BASE_CB func_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_job_struct *job;
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_PARAM_CHECK (!req_data, SRV_CLOG_RET_INVALID_PARAM);
    SRV_CLOG_PARAM_CHECK (srv_clog_pi_is_i_invalid((const srv_clog_log_identity_struct*)req_data), SRV_CLOG_RET_INVALID_PARAM);

    job = srv_clog_alloc_job_with_info(SRV_CLOG_JOB_TYPE_UPDATE_ALL_LOGS, handle, pid,func_cb,
         (void*)req_data, sizeof(srv_clog_update_all_logs_req_struct));

    srv_clog_get_idt(SRV_CLOG_INST(handle), 
        (srv_clog_log_identity_struct*) req_data, (srv_clog_log_identity_struct*) job->req_data);

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_UPDATE_ALL_LOGS,
        handle,
        job->pid,
        req_data->req_fields,
        req_data->cate,
        req_data->sim_id,
        req_data->log_type,
        req_data->sub_type,
        req_data->read);

    srv_clog_process_new_job(cntx, NULL, job);
    return job->pid;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_delete_log_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  pid             [IN]        
 *  log_id          [IN]        
 *  func_cb         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_delete_log_by_id(SRV_CLOG_HANDLE handle, S32 pid, SRV_CLOG_ID log_id, SRV_CLOG_BASE_CB func_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();
    srv_clog_job_struct *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_PARAM_CHECK (log_id > cntx->max_log_id, SRV_CLOG_RET_INVALID_PARAM);

    job = srv_clog_alloc_job_with_info(SRV_CLOG_JOB_TYPE_DEL_LOG_BY_ID, handle, pid, func_cb, NULL, 0);

    job->log_id = log_id;

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_DELETE_LOG_BY_ID, handle, job->pid, log_id, func_cb == NULL ? 0 : 1);

    srv_clog_process_new_job(cntx, NULL, job);
    return job->pid;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_delete_all_logs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  pid             [IN]        
 *  req_data        [IN]        
 *  func_cb         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_delete_all_logs(
        SRV_CLOG_HANDLE handle,
        S32 pid,
        const srv_clog_del_all_logs_req_struct *req_data,
        SRV_CLOG_BASE_CB func_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();
    srv_clog_job_struct *job;
    srv_clog_inst_struct *inst = SRV_CLOG_INST(handle);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_PARAM_CHECK (!req_data, SRV_CLOG_RET_INVALID_PARAM);
    SRV_CLOG_PARAM_CHECK(srv_clog_pi_is_i_invalid((const srv_clog_log_identity_struct*)req_data), SRV_CLOG_RET_INVALID_PARAM);

    job = srv_clog_alloc_job_with_info(SRV_CLOG_JOB_TYPE_DEL_ALL_LOGS, handle, pid, func_cb, 
         (void*)req_data,  sizeof(srv_clog_del_all_logs_req_struct));

    srv_clog_get_idt(inst, (srv_clog_log_identity_struct*) req_data, (srv_clog_log_identity_struct*) job->req_data);

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_DELETE_ALL_LOGS,
        handle,
        job->pid,
        req_data->cate,
        req_data->sim_id,
        req_data->log_type,
        req_data->sub_type,
        func_cb == NULL ? 0 : 1);

    srv_clog_process_new_job(cntx, NULL, job);
    return job->pid;
}


#ifdef __MMI_CLOG_MARK_SEVERAL__
/*****************************************************************************
 * FUNCTION
 *  srv_clog_delete_multi_logs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  pid             [IN]        
 *  req_data        [IN]        
 *  func_cb         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_delete_multi_logs(
        SRV_CLOG_HANDLE handle,
        S32 pid,
        const srv_clog_del_multi_logs_req_struct *req_data,
        SRV_CLOG_BASE_CB func_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();
    srv_clog_job_struct *job;
    srv_clog_inst_struct *inst = SRV_CLOG_INST(handle);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_PARAM_CHECK (!req_data, SRV_CLOG_RET_INVALID_PARAM);
    SRV_CLOG_PARAM_CHECK(srv_clog_pi_is_i_invalid((const srv_clog_log_identity_struct*)req_data), SRV_CLOG_RET_INVALID_PARAM);

    job = srv_clog_alloc_job_with_info(SRV_CLOG_JOB_TYPE_DEL_MULTI_LOGS, handle, pid, func_cb, 
         (void*)req_data,  sizeof(srv_clog_del_multi_logs_req_struct));

    srv_clog_get_idt(inst, (srv_clog_log_identity_struct*) req_data, (srv_clog_log_identity_struct*) job->req_data);

    srv_clog_process_new_job(cntx, NULL, job);
    return job->pid;
}
#endif /* __MMI_CLOG_MARK_SEVERAL__ */


/*****************************************************************************
 * FUNCTION
 *  srv_clog_search_list_log_ids
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  pid             [IN]        
 *  req_data        [IN]        
 *  func_cb         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_search_list_log_ids(
        SRV_CLOG_HANDLE handle,
        S32 pid,
        const srv_clog_search_list_log_ids_req_struct *req_data,
        SRV_CLOG_BASE_CB func_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();
    srv_clog_job_struct *job;
    srv_clog_inst_struct *inst = SRV_CLOG_INST(handle);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_PARAM_CHECK(!req_data || !func_cb, SRV_CLOG_RET_INVALID_PARAM);
    SRV_CLOG_PARAM_CHECK(srv_clog_pi_is_i_invalid((const srv_clog_log_identity_struct*)req_data), SRV_CLOG_RET_INVALID_PARAM);

    job = srv_clog_alloc_job_with_info(SRV_CLOG_JOB_TYPE_SEARCH_LIST_IDS, handle, pid, func_cb, 
        (void*)req_data, sizeof(srv_clog_search_list_log_ids_req_struct));

    srv_clog_get_idt(inst, (srv_clog_log_identity_struct*) req_data, (srv_clog_log_identity_struct*) job->req_data);

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_SEARCH_LIST_LOG_IDS,
        handle,
        job->pid,
        req_data->cate,
        req_data->sim_id,
        req_data->log_type,
        req_data->sub_type);

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_SEARCH_LIST_LOG_IDX_CONDITION,
        req_data->start_by,
        req_data->start_elm,
        req_data->search_fields,
        req_data->phb_idx_num,
        req_data->phb_idx[0]);

    srv_clog_process_new_job(cntx, NULL, job);
    return job->pid;
}

#endif /* __MMI_TELEPHONY_SUPPORT__ */


