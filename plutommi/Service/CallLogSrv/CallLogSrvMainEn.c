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
*  CallLogSrvMainEn.c
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

#include "kal_general_types.h"
#include "kal_trace.h"

#include "MMIDataType.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"

#include "CallLogSrvGprot.h"
#include "CallLogSrvIprot.h"
#include "CallLogSrvConfig.h"
#include "CallLogSrvUtils.h"
#include "CallLogSrvComp.h"
#include "CallLogSrvProt.h"
#include "CallLogSrvStore.h"


/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/
// function init
static void srv_clog_cntx_init(void);
static void srv_clog_others_init(void);
static void srv_clog_style_init(void);
// function core
static S32 srv_clog_load_logs_hdlr();
static S32 srv_clog_parse_logs_hdlr();
static void srv_clog_init_done();
static mmi_sim_enum srv_clog_sim_id_phb2mmi(phb_storage_enum phb_store_type);
// function result
static U8 srv_clog_message_hdlr(void *local_param, int mod_id, void *ilm);
static U8 srv_clog_sim_phb_last_number_ready_ind_hdlr(void *local_param, int mod_id, void *ilm);
static void srv_clog_cb_add_log_result(SRV_CLOG_BASE_CB func_cb, SRV_CLOG_ID log_id, srv_clog_ret_enum ret);
static void srv_clog_cb_update_log_result(SRV_CLOG_BASE_CB func_cb, srv_clog_update_log_req_struct* req_data, SRV_CLOG_ID log_id, U32 updated_fields, S32 ret);
static void srv_clog_cb_update_all_logs_result(SRV_CLOG_BASE_CB func_cb, srv_clog_update_all_logs_req_struct *req_data, U32 init_value, srv_clog_ret_enum ret);
static void srv_clog_cb_delete_log_by_id_result(SRV_CLOG_BASE_CB func_cb, SRV_CLOG_ID log_id, srv_clog_ret_enum ret);
static void srv_clog_cb_delete_logs_result(SRV_CLOG_BASE_CB func_cb, U32 total_num, U32 deleted_num, srv_clog_ret_enum ret);

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/
srv_clog_cntx_struct *srv_clog_cntx_p;

/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/
#define SRV_CLOG_MAIN_FUNC_DEFINITION


#define SRV_CLOG_MAIN_INIT
/*****************************************************************************
 * FUNCTION
 *  srv_clog_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET srv_clog_init(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_clog_is_init())
        return MMI_RET_OK;

    SRV_CLOG_IT_TRACE((SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_INIT, 0));

    srv_clog_mem_init();

    srv_clog_cntx_init();

    srv_clog_others_init();

    srv_clog_message_init();

    srv_clog_style_init();

    SRV_CLOG_IT_TRACE((SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_INIT, 1));

    srv_clog_start();

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_cntx_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_cntx_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_cntx_p = SRV_CLOG_TALLOC(SRV_CLOG_MEM_TYPE_SYS, srv_clog_cntx_struct);
    memset(srv_clog_cntx_p, 0x0, sizeof(srv_clog_cntx_struct));

    srv_clog_cntx_p->comp = srv_clog_comp_create(SRV_CLOG_MEM_TYPE_SYS);
    srv_clog_comp_create_elments(SRV_CLOG_MEM_TYPE_SYS, srv_clog_cntx_p->comp, srv_clog_cntx_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_others_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_others_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_CLOG_ATCMD_SUPPORT__
    /* Init AT command module */
    srv_clog_at_init();
#endif /* __MMI_CLOG_ATCMD_SUPPORT__ */

#ifdef __MMI_CLOG_SIM_SYNC_SUPPORT__
    /* Init SIM Sync module */
    srv_clog_sim_init();
#endif /* __MMI_CLOG_SIM_SYNC_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_style_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_style_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_set_def_style(SRV_CLOG_STYLE_TYPE_NUM, SRV_CLOG_STYLE_NUM, NULL);
    srv_clog_set_def_style(SRV_CLOG_STYLE_TYPE_MERGE, SRV_CLOG_STYLE_MERGE, NULL);
    srv_clog_set_def_style(SRV_CLOG_STYLE_TYPE_PHB_SYNC, SRV_CLOG_STYLE_PHB_SYNC, NULL);
    srv_clog_set_def_style(SRV_CLOG_STYLE_TYPE_SIM_SYNC, SRV_CLOG_STYLE_SIM_SYNC, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_is_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_is_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (srv_clog_cntx_p != NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_is_initializing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_is_initializing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (srv_clog_cntx_p->state < SRV_CLOG_STATE_READY);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_is_phase1_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_is_phase1_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_clog_is_init())
        return MMI_FALSE;

    return ((srv_clog_cntx_p->state >= SRV_CLOG_STATE_PHASE1_READY)
             && (srv_clog_cntx_p->state < SRV_CLOG_STATE_READY));
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_is_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_is_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_clog_is_init())
        return MMI_FALSE;

    return (srv_clog_cntx_p->state >= SRV_CLOG_STATE_READY);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_is_busy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_is_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (srv_clog_cntx_p->state > SRV_CLOG_STATE_READY);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_new_log_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 * RETURNS
 *  
 *****************************************************************************/
SRV_CLOG_ID srv_clog_new_log_id(srv_clog_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->max_log_id += SRV_CLOG_LOG_ID_STEP_LEN;
    return cntx->max_log_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_reset_log_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 * RETURNS
 *  
 *****************************************************************************/
SRV_CLOG_ID srv_clog_reset_log_id(srv_clog_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->max_log_id = SRV_CLOG_LOG_ID_START;
    return cntx->max_log_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_new_log_id_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 *  log_id      [?]     
 * RETURNS
 *  
 *****************************************************************************/
SRV_CLOG_ID srv_clog_new_log_id_ex(srv_clog_cntx_struct *cntx, U32 *log_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *log_id += SRV_CLOG_LOG_ID_STEP_LEN;
    return *log_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_reserve_log_ids
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 *  count       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
SRV_CLOG_ID srv_clog_reserve_log_ids(srv_clog_cntx_struct *cntx, U32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_CLOG_ID start_log_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->max_log_id = srv_clog_revise_log_id(cntx->max_log_id);
    start_log_id = cntx->max_log_id;
    cntx->max_log_id += SRV_CLOG_LOG_ID_STEP_LEN * count;
    return start_log_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_revise_log_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  log_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
SRV_CLOG_ID srv_clog_revise_log_id(SRV_CLOG_ID log_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (log_id <= SRV_CLOG_LOG_ID_START)
        return log_id + SRV_CLOG_LOG_ID_START;
    return log_id;
}


#define SRV_CLOG_MAIN_EXT_API


/*****************************************************************************
 * FUNCTION
 *  srv_clog_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  create      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
SRV_CLOG_HANDLE srv_clog_create(const srv_clog_create_struct *create)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_destroy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_destroy(SRV_CLOG_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_get_user_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *srv_clog_get_user_data(SRV_CLOG_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return NULL;
}


#define SRV_CLOG_MAIN_EVENT
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
void srv_clog_message_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler(
            MSG_ID_SRV_CLOG_JOB_CONTINUE_IND,
            (PsIntFuncPtr) srv_clog_message_hdlr,
            MMI_FALSE);
    
    mmi_frm_set_protocol_event_handler(
            MSG_ID_MMI_PHB_LAST_NUMBER_READY_IND, 
            (PsIntFuncPtr) srv_clog_sim_phb_last_number_ready_ind_hdlr, 
            MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_message_send
 * DESCRIPTION
 *  
 * PARAMETERS
 *  user_data       [?]         
 *  trans_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_message_send(void *user_data, srv_clog_state_enum trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_evt_struct *ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind = SRV_CLOG_NEW_ILM_DATA(srv_clog_evt_struct);
    ind->trans_id = trans_id;

    mmi_frm_send_ilm(MOD_MMI, MSG_ID_SRV_CLOG_JOB_CONTINUE_IND, (oslParaType*) ind, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_evt_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_param     [?]         
 *  mod_id          [IN]        
 *  ilm             [?]         
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_clog_message_hdlr(void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_evt_struct *ind = (srv_clog_evt_struct*) local_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_cntx_p->state = ind->trans_id;
    
    switch(srv_clog_cntx_p->state)
    {
        case SRV_CLOG_STATE_LOAD:
            srv_clog_load_logs_hdlr();
            break;

        case SRV_CLOG_STATE_PARSE:
            srv_clog_parse_logs_hdlr();
            break;

    #ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__
        case SRV_CLOG_STATE_REVISE:
            srv_clog_revise_logs_hdlr();
        #ifdef __MMI_CLOG_SIM_SYNC_SUPPORT__
            srv_clog_message_send(NULL, SRV_CLOG_STATE_SIM_SYNC);
        #else
            srv_clog_message_send(NULL, SRV_CLOG_STATE_READY);
        #endif
            break;
    #endif /* __MMI_CLOG_PHB_SYNC_SUPPORT__ */

    #ifdef __MMI_CLOG_SIM_SYNC_SUPPORT__
        case SRV_CLOG_STATE_SIM_SYNC:
            srv_clog_sim_sync_hdlr();
            break;
    #endif /* __MMI_CLOG_SIM_SYNC_SUPPORT__ */

        case SRV_CLOG_STATE_READY:
            srv_clog_init_done();
            break;
    }

    return 0;
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
U8 srv_clog_sim_phb_last_number_ready_ind_hdlr(void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_id = mmi_frm_l4c_mod_to_sim((module_type)mod_id);
    SRV_CLOG_SET_BIT(srv_clog_cntx_p->flags, sim_id << SRV_CLOG_CNTX_FLAG_PHB_READY_POS);

    if (!SRV_CLOG_CHECK_BIT_GRP(srv_clog_cntx_p->flags, SRV_CLOG_CNTX_FLAG_PHB_READY_TOTAL, SRV_CLOG_CNTX_FLAG_PHB_READY_TOTAL))
        return 0;
#ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__
    srv_clog_revise_logs_hdlr();
#endif
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_emit_init_para_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt_para        [?]         
 *  evt_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_emit_init_para_event(srv_clog_evt_log_op_struct *evt_para, U16 evt_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(evt_para, evt_id);
    evt_para->user_data = srv_clog_get_user_data(NULL);
    evt_para->handle = 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_emit_ready_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_emit_ready_event()
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
    evt.sup_merge = srv_clog_stl_support_merge(srv_clog_cntx_p->comp->style_mgr);
    evt.sup_thread = 0;

    srv_clog_get_sim_unread_missed_call_num((U32*) &evt.ur_mclt_num, SRV_CLOG_SIM_IDX_MAX_ITEM);

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
 *  add_ret         [IN]        
 *  new_log_id      [IN]        
 *  new_props       [IN]        
 *  old_log_id      [IN]        
 *  old_props       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_emit_add_log_event(
                 srv_clog_add_log_ret_enum add_ret,
                SRV_CLOG_ID new_log_id,
                U8 new_types,
                SRV_CLOG_ID old_log_id,
                U8 old_types)
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

    srv_clog_emit_init_para_event((srv_clog_evt_log_op_struct*) & evt, EVT_ID_SRV_CLOG_ADD_LOG);
    evt.add_ret = add_ret;
    evt.new_idf.log_id = new_log_id;
    srv_clog_pi_p2i(new_types, (srv_clog_log_identity_struct*) & evt.new_idf);
    evt.old_idf.log_id = old_log_id;
    if (evt.add_ret == SRV_CLOG_ADD_LOG_RET_PURE_ADD)
        SRV_CLOG_INIT_IDT((srv_clog_log_identity_struct*) & evt.old_idf, 0, 0, 0, 0);
    else
        srv_clog_pi_p2i(old_types, (srv_clog_log_identity_struct*) & evt.old_idf);

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_EMIT_ADD_LOG_EVENT,
        0,
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
 *  fields      [IN]        
 *  si_log      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_emit_update_log_event(U32 fields, srv_clog_si_struct *si_log)
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

    srv_clog_emit_init_para_event((srv_clog_evt_log_op_struct*) & evt, EVT_ID_SRV_CLOG_UPDATE_LOG);
    evt.fields = fields;
    if (evt.fields == 0)
        evt.fields = SRV_CLOG_LOG_FIELD_ALL;

    srv_clog_si_log_si2cmn(si_log, 0, &evt.log);

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_EMIT_UPDATE_LOG_EVENT,
        0,
        fields,
        SRV_CLOG_SILOG_GET_LOG_ID(si_log),
        SRV_CLOG_SILOG_GET_TYPE_ID(si_log));

    MMI_FRM_CB_EMIT_EVENT(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_emit_update_all_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fields      [IN]        
 *  idt         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_emit_update_all_event(U32 fields, srv_clog_log_identity_struct *idt)
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

    srv_clog_emit_init_para_event((srv_clog_evt_log_op_struct*) & evt, EVT_ID_SRV_CLOG_UPDATE_ALL);
    evt.fields = fields;
    if (evt.fields == 0)
        evt.fields = SRV_CLOG_LOG_FIELD_ALL;

    srv_clog_pi_cp_i(idt, &evt.idt);

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_EMIT_UPDATE_ALL_EVENT,
        0,
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
 *  log_id      [IN]        
 *  props       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_emit_del_log_event(SRV_CLOG_ID log_id, U8 types)
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

    srv_clog_emit_init_para_event((srv_clog_evt_log_op_struct*) & evt, EVT_ID_SRV_CLOG_DEL_LOG);
    srv_clog_pi_p2i(types, (srv_clog_log_identity_struct*) & evt.idf);
    evt.idf.log_id = log_id;

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_EMIT_DEL_LOG_EVENT, 0, log_id, types);

    MMI_FRM_CB_EMIT_EVENT(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_emit_del_logs_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idt         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_emit_del_logs_event(srv_clog_log_identity_struct *idt)
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

    srv_clog_emit_init_para_event((srv_clog_evt_log_op_struct*) & evt, EVT_ID_SRV_CLOG_DEL_ALL);
    srv_clog_pi_cp_i(idt, &evt.idt);

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_EMIT_DEL_ALL_EVENT,
        0,
        idt->cate,
        idt->sim_id,
        idt->log_type,
        idt->sub_type);

    MMI_FRM_CB_EMIT_EVENT(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_add_log_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_data        [?]     
 *  log_id         [?]     
 *  ret         [?]     
 *  func_cb         [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_add_log_notify(SRV_CLOG_ID log_id,
        srv_clog_add_log_req_struct* req_data,        
        SRV_CLOG_BASE_CB func_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_add_log_ret_enum add_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_cb_add_log_result(func_cb, log_id, req_data->ret);

#ifdef __MMI_CLOG_ATCMD_SUPPORT__
    /* AT command */
    srv_clog_at_notify_update(
        SRV_CLOG_AT_UPDATE_ADD,
        srv_clog_cntx_p,
        SRV_CLOG_SILOG_GET_TYPE_ID(&req_data->si_log),
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
        add_ret,
        log_id,
        SRV_CLOG_SILOG_GET_TYPE_ID(&req_data->si_log),
        req_data->old_log_id,
        req_data->old_type);
}


#define SRV_CLOG_MAIN_CORE
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

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_cntx_p->state = SRV_CLOG_STATE_INIT;

    SRV_CLOG_DUMP(SRV_CLOG_DUMP_TYPE_STL);

    SRV_CLOG_IT_TRACE((SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_START, -1));

    srv_clog_message_send(NULL, SRV_CLOG_STATE_LOAD);

    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_load_logs_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_load_logs_hdlr()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 cursor = 0;
    U32 nums_per;
    U32 max_times;
    srv_clog_si_tbl_struct *si_tbl;
    srv_clog_st_log_struct* cnf_data;
    S32 ret = SRV_CLOG_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    si_tbl = srv_clog_cntx_p->comp->si_tbl;

    cnf_data = srv_clog_comp_new_para(SRV_CLOG_ST_MULTI_LOGS_PER_LOAD_MAX_NUM*NVRAM_EF_CLOG_LOG_SIZE);

    max_times = SRV_CLOG_NUM_ROUNDING(NVRAM_EF_CLOG_LOG_TOTAL, SRV_CLOG_ST_MULTI_LOGS_PER_LOAD_MAX_NUM);

    for (i = 0; i < max_times; i++)
    {
        if (i != max_times - 1) /* check if it is the last batch */
            nums_per = SRV_CLOG_ST_MULTI_LOGS_PER_LOAD_MAX_NUM;
        else
            nums_per = SRV_CLOG_LOG_MAX_NUM - cursor;

        ret = srv_clog_st_read_logs(cursor, nums_per*CUSTOM_CLOG_NUM_PER_RECORD, cnf_data);

        if (ret >= 0)
        {
            ret = srv_clog_si_tbl_parse(si_tbl, (CUSTOM_CLOG_NUM_PER_RECORD*cursor),
                cnf_data, (CUSTOM_CLOG_NUM_PER_RECORD*nums_per));
            cursor += nums_per;
        }
        else
        {
            ASSERT(0);
            break;
        }

        if (cursor >= NVRAM_EF_CLOG_LOG_TOTAL)
        {
            ret = SRV_CLOG_RET_OK;
            break;
        }
    }
    
    SRV_CLOG_IT_TRACE((
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_LOAD_LOGS_HDLR,
        cursor,
        0,
        srv_clog_si_tbl_total_num(si_tbl)));

    srv_clog_message_send(NULL, SRV_CLOG_STATE_PARSE);

    srv_clog_mfree(SRV_CLOG_MEM_TYPE_TEMP, cnf_data);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_parse_logs_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_parse_logs_hdlr()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_idx_parse(srv_clog_cntx_p->comp->idx_tbl);
    srv_clog_cntx_p->max_log_id = srv_clog_si_tbl_get_max_log_id(srv_clog_cntx_p->comp->si_tbl);

#if defined(__MMI_CLOG_PHB_SYNC_SUPPORT__)
    srv_clog_message_send(NULL, SRV_CLOG_STATE_REVISE);
#elif defined(__MMI_CLOG_SIM_SYNC_SUPPORT__)
    srv_clog_message_send(NULL, SRV_CLOG_STATE_SIM_SYNC);
#else
    srv_clog_message_send(NULL, SRV_CLOG_STATE_READY);
#endif

    return SRV_CLOG_RET_OK;
}


#ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_clog_revise_logs_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_revise_logs_hdlr()
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
    U32 cursor;
    U32 total_num;
    U32 max_read_size;
    U32 write_num;
#ifdef __MMI_CLOG_SIM_SYNC_SUPPORT__
    U32 sync_style = 0;
#endif /* __MMI_CLOG_SIM_SYNC_SUPPORT__ */
    srv_clog_si_tbl_struct *si_tbl = srv_clog_cntx_p->comp->si_tbl;
    srv_clog_log_identity_struct idt = 
        {
            SRV_CLOG_CATE_CALL,
            SRV_CLOG_SIM_ID_ALL,
            SRV_CLOG_CLT_ALL,
            SRV_CLOG_CALL_TYPE_ALL
        };

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!srv_clog_is_phase1_ready())
        return;
    
    SRV_CLOG_SET_INVALID_PHB_ID(invalid_phb_id);

        /* Check if delete all old logs, if so, no need to revise as all are deleted */
#ifdef __MMI_CLOG_SIM_SYNC_SUPPORT__
    srv_clog_stl_get_style(srv_clog_cntx_p->comp->style_mgr, SRV_CLOG_STYLE_TYPE_SIM_SYNC, &sync_style, NULL);
    if (SRV_CLOG_CHECK_BIT(sync_style, SRV_CLOG_STYLE_SIM_SYNC_CLEAR_OLD))
    {
        SRV_CLOG_IT_TRACE((SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_REVISE_LOGS_HDLR_CHECK_STYLE, sync_style));
        return SRV_CLOG_RET_OK;
    }
#endif /* __MMI_CLOG_SIM_SYNC_SUPPORT__ */ 

    /* Check L4PHB is ready or not */
    if (!SRV_CLOG_CHECK_BIT_GRP(srv_clog_cntx_p->flags, SRV_CLOG_CNTX_FLAG_PHB_READY_TOTAL, SRV_CLOG_CNTX_FLAG_PHB_READY_TOTAL))
    {
        /* My be the SIM card is locked when initializing, but user can make SOS call at that time */
        MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_REVISE_LOGS_HDLR_CHECK_READY, srv_clog_cntx_p->flags, 0, 0);
        return SRV_CLOG_RET_NOT_READY;
    }

    /* Check if any SIM replaced */
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        if (srv_clog_is_single_sim_replaced((mmi_sim_enum)SRV_CLOG_IDX2BIT(i)))
        {
            SRV_CLOG_IT_TRACE((SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_REVISE_LOGS_HDLR_SIM_REPLACED,
                    srv_clog_cntx_p->flags, changed_sim_grp, SRV_CLOG_IDX2BIT(i)));

            SRV_CLOG_SET_BIT(changed_sim_grp, SRV_CLOG_IDX2BIT(i));
        }
    }

    if (!changed_sim_grp)
    {
        MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_REVISE_LOGS_HDLR_SIM_NOT_REPLACED,
                srv_clog_cntx_p->flags, 0, 0, changed_sim_grp);

        return SRV_CLOG_RET_OK;
    }
        
    total_num = srv_clog_si_tbl_total_num(si_tbl);
    update_count = 0;

    for (cursor = 0; cursor < SRV_CLOG_LOG_MAX_NUM && cursor < total_num; cursor++)
    {
        si_log = srv_clog_si_tbl_index(si_tbl, cursor);

        if (!srv_clog_si_log_is_valid(si_log))
            continue;

        update_count++; /* count of logs */

        /* Dump Logs without valid PHB id */
    #ifdef __SRV_CLOG_DUMP__
        if (!SRV_CLOG_IS_PHB_ID_VALID(SRV_CLOG_SILOG_GET_PHB_ID(si_log)))
        {
            MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_REVISE_LOGS_HDLR_CHECK_PHB_ID,
                    0, 0, total_num, cursor, SRV_CLOG_SILOG_GET_PHB_ID(si_log));

            SRV_CLOG_DUMP_LOG(cursor, si_log);
        }
    #endif /* __SRV_CLOG_DUMP__ */

        /* Check if SIM Storage */
        phb_store_type = (phb_storage_enum)srv_phb_get_storage(srv_phb_get_store_index_by_number_id(SRV_CLOG_SILOG_GET_PHB_ID(si_log)));
        if (phb_store_type == PHB_STORAGE_NVRAM)
        {
            MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_REVISE_LOGS_HDLR_CHECK_PHB_STORAGE,
                    phb_store_type, SRV_CLOG_SILOG_GET_LOG_ID(si_log), SRV_CLOG_SILOG_GET_PHB_ID(si_log));

            continue;
        }

        /* Check if the SIM card to create this log is replaced */
        sim_id = srv_clog_sim_id_phb2mmi(phb_store_type);
        if (!SRV_CLOG_CHECK_BIT(changed_sim_grp, sim_id))
        {
            MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_REVISE_LOGS_HDLR_CHECK_LOG_SIM_ID,
                   cursor, changed_sim_grp, sim_id, SRV_CLOG_SILOG_GET_LOG_ID(si_log), SRV_CLOG_SILOG_GET_PHB_ID(si_log));

            continue;
        }

        SRV_CLOG_IT_TRACE((SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_REVISE_LOGS_HDLR_FIND_ONE_LOG,
                total_num, cursor, changed_sim_grp, sim_id, SRV_CLOG_SILOG_GET_LOG_ID(si_log), SRV_CLOG_SILOG_GET_PHB_ID(si_log)));

        SRV_CLOG_DUMP_LOG(cursor, si_log);

            /* update log: set invalid phb_id, remove name and emit update event */
        srv_clog_si_update_phb_info(si_log, SRV_CLOG_LOG_FIELD_PHB_ID, invalid_phb_id, NULL);
    }

    // write all logs to nvram
    srv_clog_st_write_logs(0, SRV_CLOG_LOG_MAX_NUM, &si_tbl->data[0]);

    srv_clog_emit_update_all_event(SRV_CLOG_LOG_FIELD_ALL, (srv_clog_log_identity_struct*) &idt);
    
    update_count++;

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_REVISE_LOGS_HDLR_REVISE_DONE,
            update_count, SRV_CLOG_SILOG_GET_LOG_ID(si_log), SRV_CLOG_SILOG_GET_PHB_ID(si_log), SRV_CLOG_SILOG_GET_TYPE_ID(si_log));

    SRV_CLOG_DUMP_LOG(cursor, si_log);

    if (cursor < total_num)
        return SRV_CLOG_RET_CONTINUE;

    return SRV_CLOG_RET_OK;
}
#endif



/*****************************************************************************
 * FUNCTION
 *  srv_clog_init_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_init_done()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* should set to ready before emit callback event because other AP may to get data in this event. */
    srv_clog_cntx_p->state = SRV_CLOG_STATE_READY;

#ifdef __MMI_CLOG_ATCMD_SUPPORT__
    srv_clog_at_notify_ready(srv_clog_cntx_p);
#endif

    srv_clog_emit_ready_event();

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_INIT_DONE, 0, srv_clog_cntx_p->max_log_id, srv_clog_cntx_p->max_pid);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_add_log_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_data        [?]
 *  log_id         [?]
 *  func_cb         [?]
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_add_log_hdlr(SRV_CLOG_ID log_id,
        srv_clog_add_log_req_struct *req_data,        
        SRV_CLOG_BASE_CB func_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_si_tbl_struct *si_tbl = srv_clog_cntx_p->comp->si_tbl;
    srv_clog_idx_tbl_struct *idx_tbl = srv_clog_cntx_p->comp->idx_tbl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_idx_add_prepare(idx_tbl, req_data);

    if (req_data->need_merge)   /* pure merge case, merge new log (replace), no matter full or not */
    {
        /* pure merge or pure replace, should first delete old one */
        srv_clog_idx_delete_id(idx_tbl, req_data->old_log_id);

        /* the sort order may be changed */        
        if (SRV_CLOG_TIME_DETAIL_MAX_NUM > 1) /* update old timestamp and duration info to new log */
        {
            srv_clog_si_struct *old_si_log = srv_clog_si_tbl_index(si_tbl, req_data->old_sit_idx);

            /* copy old timestamp and duration to new log's sturct, but only need copy (SRV_CLOG_TIME_DETAIL_MAX_NUM - 1) */
            memcpy(&req_data->si_log.timestamp[1], &old_si_log->timestamp[0], sizeof(old_si_log->timestamp[0]) * (SRV_CLOG_TIME_DETAIL_MAX_NUM - 1));//memmove
            memcpy(&req_data->si_log.duration[1], &old_si_log->duration[0], sizeof(old_si_log->duration[0]) * (SRV_CLOG_TIME_DETAIL_MAX_NUM - 1));
        }

        srv_clog_si_tbl_delete_index(si_tbl, req_data->old_sit_idx);
        req_data->ret = srv_clog_si_tbl_add_update(si_tbl, req_data);
        if (req_data->ret == SRV_CLOG_RET_OK)
            req_data->ret= srv_clog_st_write_logs(req_data->old_sit_idx, req_data->old_sit_idx+1, &si_tbl->data[0]);
    }
    else if (!req_data->need_merge && req_data->is_full)    /* add new but full, delete the oldest one */
    {
        U32 write_min;
        U32 write_max;

        /* pure merge or pure replace, should first delete old one */
        srv_clog_idx_delete_id(idx_tbl, req_data->old_log_id);

        /* the sort order may be changed */
        req_data->ret = srv_clog_si_tbl_delete_index(si_tbl, req_data->old_sit_idx);
        req_data->ret = srv_clog_si_tbl_add_update(si_tbl, req_data);

        write_min = req_data->old_sit_idx<req_data->best_sit_idx?req_data->old_sit_idx:req_data->best_sit_idx;
        write_max = req_data->old_sit_idx>req_data->best_sit_idx?req_data->old_sit_idx:req_data->best_sit_idx;
        
        if (req_data->ret == SRV_CLOG_RET_OK)
            srv_clog_st_write_logs(write_min, write_max+1, si_tbl->data);
    }
    else    /* add and not full, pure add case */
    {
        req_data->ret = srv_clog_si_tbl_add_update(si_tbl, req_data);
        req_data->ret = srv_clog_st_write_logs(req_data->best_sit_idx, req_data->best_sit_idx+1, si_tbl->data);
    }

    if (req_data->ret == SRV_CLOG_RET_OK)
    {
//        if (req_data->need_merge || !req_data->need_merge && req_data->is_full)
//        {
//            /* pure merge or pure replace, should first delete old one */
//            srv_clog_idx_delete_id(idx_tbl, req_data->old_log_id);
//        }
                
        req_data->ret = srv_clog_idx_add_update(idx_tbl, req_data);
        srv_clog_add_log_notify(log_id, req_data, func_cb);
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_update_log_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_data        [?]     
 *  log_id         [?]     
 *  func_cb         [?]      
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_update_log_hdlr(SRV_CLOG_ID log_id,
        srv_clog_update_log_req_struct *req_data,        
        SRV_CLOG_BASE_CB func_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 sit_idx;
    srv_clog_si_struct  *si_log;
    srv_clog_si_tbl_struct *si_tbl = srv_clog_cntx_p->comp->si_tbl;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if has this log */
    ret = srv_clog_si_tbl_id2idx(si_tbl, log_id, &sit_idx);
    if (ret == SRV_CLOG_RET_NOT_FOUND)
    {
        srv_clog_cb_update_log_result(func_cb, req_data, log_id, 0, ret);
    #ifdef __MMI_CLOG_CALL_TIME__
        srv_clog_log_call_time(req_data); /* Write Total call duration to NVRAM */
    #endif /* __MMI_CLOG_CALL_TIME__ */
        return ret;
    }

    si_log = srv_clog_si_tbl_index(si_tbl, (U16) sit_idx);    
    srv_clog_si_log_update_log(si_log, &req_data->log_data, req_data->req_fields);

    ret = srv_clog_st_write_logs(sit_idx, sit_idx+1, &si_tbl->data[0]);
    if (ret != SRV_CLOG_RET_OK)
    {
        SRV_CLOG_IT_TRACE((
            SRV_CLOG_TRC_INFO,
            TRC_SRV_CLOG_UDPATE_LOG_HDLR,
            log_id,
            sit_idx,
            ret,
            SRV_CLOG_SILOG_GET_TYPE_ID(si_log)));

        srv_clog_cb_update_log_result(func_cb, req_data, log_id, 0, ret);

        return ret;
    }
    
    srv_clog_cb_update_log_result(func_cb, req_data, log_id, req_data->req_fields, SRV_CLOG_RET_OK);
    srv_clog_si_log_si2cmn(si_log, 0, &req_data->log_data);
#ifdef __MMI_CLOG_CALL_TIME__
    srv_clog_log_call_time(req_data);
#endif /* __MMI_CLOG_CALL_TIME__ */
#ifdef __MMI_CLOG_ATCMD_SUPPORT__
    srv_clog_at_notify_update(SRV_CLOG_AT_UPDATE_UPD, srv_clog_cntx_p, SRV_CLOG_SILOG_GET_TYPE_ID(si_log), NULL, si_log);
#endif
    srv_clog_emit_update_log_event(req_data->req_fields, si_log);

    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_update_all_logs_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_data        [?]     
 *  func_cb         [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_update_all_logs_hdlr(
    srv_clog_update_all_logs_req_struct *req_data,
    SRV_CLOG_BASE_CB func_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 cursor = 0;
    U32 ur_num;
    srv_clog_si_struct *si_log;
    srv_clog_si_tbl_struct *si_tbl = srv_clog_cntx_p->comp->si_tbl;    
    srv_clog_ret_enum ret = SRV_CLOG_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_CLOG_LOG_MAX_NUM; i++)
    {
        si_log = srv_clog_si_tbl_index(si_tbl, i);
        if (!srv_clog_si_log_is_valid(si_log) ||
            !srv_clog_pi_is_ip_sub((srv_clog_log_identity_struct*) req_data, SRV_CLOG_SILOG_GET_TYPE_ID(si_log)))
            continue;
        
        /* Only support unread number field here */
        ur_num = SRV_CLOG_SILOG_GET_UNREADNUM(si_log);
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
            !SRV_CLOG_CHECK_BIT(SRV_CLOG_SILOG_GET_TYPE_ID(si_log), SRV_CLOG_TDP_NEW_EVENT))
        {
            continue;
        }

        srv_clog_si_log_update_cmn_info(si_log, req_data);
    }

    ret = srv_clog_st_write_logs(0, SRV_CLOG_LOG_MAX_NUM, &(si_tbl->data[0]));

    srv_clog_cb_update_all_logs_result(func_cb, req_data, cursor, ret);

#ifdef __MMI_CLOG_ATCMD_SUPPORT__
    srv_clog_at_notify_update(SRV_CLOG_AT_UPDATE_UPD_ALL, srv_clog_cntx_p, 0, (srv_clog_log_identity_struct*) req_data, NULL);
#endif
    srv_clog_emit_update_all_event(req_data->req_fields, (srv_clog_log_identity_struct*) req_data);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_delete_log_by_id_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  func_cb        [?]     
 *  log_id        [?]    
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_delete_log_by_id_hdlr(SRV_CLOG_ID log_id, SRV_CLOG_BASE_CB func_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 sit_idx;
    srv_clog_si_struct *si_log;
    U8 type_id;
    srv_clog_si_tbl_struct *si_tbl = srv_clog_cntx_p->comp->si_tbl;
    srv_clog_idx_tbl_struct *idx_tbl = srv_clog_cntx_p->comp->idx_tbl;
    S32 ret = SRV_CLOG_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_clog_si_tbl_id2idx(si_tbl, log_id, &sit_idx);

    if (ret != SRV_CLOG_RET_OK)
    {
        srv_clog_cb_delete_log_by_id_result(func_cb, log_id, (srv_clog_ret_enum)ret);
        return ret;
    }

    si_log = srv_clog_si_tbl_index(si_tbl, sit_idx);
    type_id = SRV_CLOG_SILOG_GET_TYPE_ID(si_log);

    ret = srv_clog_idx_delete_id(idx_tbl, log_id);
    ret = srv_clog_si_tbl_delete_index(si_tbl, sit_idx);
    ret = srv_clog_st_write_logs(sit_idx, sit_idx+1, &si_tbl->data[0]);

    SRV_CLOG_IT_TRACE((SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_DELETE_LOG_BY_ID_HDLR, log_id, sit_idx, ret, type_id));

    srv_clog_cb_delete_log_by_id_result(func_cb, log_id, (srv_clog_ret_enum)ret);

#ifdef __MMI_CLOG_ATCMD_SUPPORT__
    srv_clog_at_notify_update(SRV_CLOG_AT_UPDATE_DEL, srv_clog_cntx_p, type_id, NULL, NULL);
#endif
    srv_clog_emit_del_log_event(log_id, type_id);

return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_delete_logs_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_data        [?]     
 *  func_cb         [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_delete_logs_hdlr(srv_clog_log_identity_struct *req_data,
    SRV_CLOG_BASE_CB func_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 j;
    srv_clog_si_struct *si_log;
    srv_clog_idx_info_enum info_type;
    U32 sit_idx;
    U32 sit_min = SRV_CLOG_LOG_MAX_NUM;
    U32 sit_max = 0;
    srv_clog_idx_tbl_struct *idx_tbl = srv_clog_cntx_p->comp->idx_tbl;
    srv_clog_si_tbl_struct *si_tbl = srv_clog_cntx_p->comp->si_tbl;
    U32 total_num;
    U32 cursor = 0;
    srv_clog_ret_enum ret = SRV_CLOG_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_idx_refresh(
        idx_tbl,
        SRV_CLOG_LIST_LEVEL_SORT,
        req_data,
        &info_type);

    total_num = srv_clog_idx_total_num(idx_tbl, info_type);
    if (total_num == 0)   /* empty */
    {
        srv_clog_cb_delete_logs_result(func_cb, total_num, total_num, SRV_CLOG_RET_OK);
        return SRV_CLOG_RET_OK;
    }

    for (i = cursor, j = 0; i < total_num; i++)
    {
        sit_idx = srv_clog_idx_index(idx_tbl, info_type, i);
        
    #ifdef __MMI_CLOG_MARK_SEVERAL__
        si_log = srv_clog_si_tbl_index(si_tbl, sit_idx);
    
        if (SRV_CLOG_IS_ELM_INVALID(req_data->log_ids[j]))
            break; /* finish delete multi logs, so need stop */
        if (SRV_CLOG_SILOG_GET_LOG_ID(si_log) != req_data->log_ids[j])
            continue;
        else /* need to delete this log */
            j++;
    #endif /* __MMI_CLOG_MARK_SEVERAL__ */

        sit_min = sit_min>sit_idx?sit_idx:sit_min;
        sit_max = sit_max>sit_idx?sit_max:sit_idx;

        srv_clog_si_tbl_delete_index(si_tbl, sit_idx);
    }

    ret = srv_clog_st_write_logs(sit_min, sit_max+1, &(si_tbl->data[0]));

    ret = (srv_clog_ret_enum)srv_clog_idx_reset(idx_tbl, SRV_CLOG_IDX_INFO_BASE);

    srv_clog_cb_delete_logs_result(func_cb, total_num, cursor, ret);

#ifdef __MMI_CLOG_ATCMD_SUPPORT__
    srv_clog_at_notify_update(
        SRV_CLOG_AT_UPDATE_DEL_ALL,
        srv_clog_cntx_p,
        0,
        req_data,
        NULL);
#endif /* __MMI_CLOG_ATCMD_SUPPORT__ */

    srv_clog_emit_del_logs_event(req_data);

    /* Check if can reset log id */
    if (0 == srv_clog_si_tbl_total_num(si_tbl))
        srv_clog_reset_log_id(srv_clog_cntx_p);

    return ret;
}


#ifndef __MMI_CONTACT_SLIM__
/*****************************************************************************
 * FUNCTION
 *  srv_clog_search_list_log_ids_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_data        [?]     
 *  func_cb         [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_search_list_log_ids_hdlr(srv_clog_search_list_log_ids_req_struct* req_data,
    SRV_CLOG_BASE_CB func_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 idx_tbl_idx;
    srv_clog_idx_info_enum info_type;
    srv_clog_search_list_log_ids_cnf_struct *cnf_data;    
    srv_clog_idx_tbl_struct *idx_tbl = srv_clog_cntx_p->comp->idx_tbl;
    srv_clog_ret_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf_data = srv_clog_comp_new_para(sizeof(srv_clog_search_list_log_ids_cnf_struct));
    memset(cnf_data, 0x0, sizeof(srv_clog_search_list_log_ids_cnf_struct));

    srv_clog_pi_cp_i((srv_clog_log_identity_struct*) req_data, (srv_clog_log_identity_struct*) cnf_data);
    cnf_data->search_fields = req_data->search_fields;
    cnf_data->start_by = req_data->start_by;
    cnf_data->start_elm = req_data->start_elm;
    srv_clog_idx_refresh(
        idx_tbl,
        SRV_CLOG_LIST_LEVEL_SORT,
        (srv_clog_log_identity_struct*) req_data,
        &info_type);

    do
    {
        if (req_data->start_by == SRV_CLOG_BY_IDX)
        {
            idx_tbl_idx = req_data->start_elm;
            if (idx_tbl_idx >= srv_clog_idx_total_num(idx_tbl, info_type))
            {
                ret = SRV_CLOG_RET_NOT_FOUND;
                srv_clog_cb_search_list_log_ids_result(func_cb, req_data, cnf_data, ret);
    
                return SRV_CLOG_RET_NOT_FOUND;
            }
        }
        else
        {
            ret = srv_clog_idx_id2idx(idx_tbl, info_type, req_data->start_elm, &idx_tbl_idx, NULL);
            if (ret != SRV_CLOG_RET_OK)
            {
                ret = SRV_CLOG_RET_NOT_FOUND;
                srv_clog_cb_search_list_log_ids_result(func_cb, req_data, cnf_data, ret);
                return SRV_CLOG_RET_NOT_FOUND;
            }
        }

        ret = (srv_clog_ret_enum)srv_clog_idx_search_ids_by_idx(idx_tbl, info_type, req_data, cnf_data, idx_tbl_idx);
        ret = srv_clog_cb_search_list_log_ids_result(func_cb, req_data, cnf_data, ret);
        if (ret == SRV_CLOG_RET_STOP)
            break;
        if (cnf_data->next_elm != SRV_CLOG_INVALID_ELM)
            req_data->start_elm = cnf_data->next_elm;
        /* CB NOTIFY */
    } while (ret == SRV_CLOG_RET_OK && cnf_data->next_elm != SRV_CLOG_INVALID_ELM);

    srv_clog_mfree(SRV_CLOG_MEM_TYPE_TEMP, cnf_data);

    return ret;
}
#endif /* __MMI_CONTACT_SLIM__ */


#ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__
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
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_revise_logs_hdlr();
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
mmi_sim_enum srv_clog_sim_id_phb2mmi(phb_storage_enum phb_store_type)
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


#define SRV_CLOG_MAIN_RESULT
/*****************************************************************************
 * FUNCTION
 *  srv_clog_cb_add_log_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  log_id        [?]         
 *  ret         [?]         
 *  func_cb         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_cb_add_log_result(
        SRV_CLOG_BASE_CB func_cb,
        SRV_CLOG_ID log_id,
        srv_clog_ret_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_add_log_cnf_struct cnf_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!func_cb)
        return;

    cnf_data.log_id = log_id;
    cnf_data.ret = ret;
    (func_cb) (0, 0, NULL, &cnf_data, MMI_FALSE, ret);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_cb_update_log_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  func_cb                [?]         
 *  req_data                 [?]         
 *  log_id      [IN]        
 *  updated_fields      [IN]        
 *  ret                 [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_cb_update_log_result(
        SRV_CLOG_BASE_CB func_cb,
        srv_clog_update_log_req_struct* req_data,
        SRV_CLOG_ID log_id,
        U32 updated_fields,
        S32 ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_update_log_cnf_struct cnf_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!func_cb)
        return;

    cnf_data.log_id = log_id;
    cnf_data.req_fields = req_data->req_fields;
    cnf_data.updated_fields = updated_fields;
    cnf_data.ret = (srv_clog_ret_enum)ret;
    (func_cb) (0, 1, req_data, &cnf_data, MMI_FALSE, (srv_clog_ret_enum)ret);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_cb_update_all_logs_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_data        [?]     
 *  func_cb         [?]     
 *  init_value         [?]    
 *  ret         [?]    
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_cb_update_all_logs_result(
        SRV_CLOG_BASE_CB func_cb,
        srv_clog_update_all_logs_req_struct *req_data,
        U32 init_value,
        srv_clog_ret_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_update_all_logs_cnf_struct cnf_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!func_cb)
        return;

    cnf_data.req_fields = req_data->req_fields;
    cnf_data.updated_fields = req_data->req_fields;
    cnf_data.num_updated = init_value;
    cnf_data.ret = ret;
    (func_cb) (0, 0, req_data, (void*)&cnf_data, MMI_FALSE, cnf_data.ret);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_cb_delete_log_by_id_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  func_cb        [?]         
 *  log_id         [?]         
 *  ret         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_cb_delete_log_by_id_result(
        SRV_CLOG_BASE_CB func_cb,
        SRV_CLOG_ID log_id,
        srv_clog_ret_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!func_cb)
        return;

    (func_cb) (0, 0, (void*)log_id, (void*)log_id, MMI_FALSE, ret);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_cb_delete_logs_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  func_cb        [?]     
 *  total_num         [?]     
 *  deleted_num         [?]
 *  ret         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_cb_delete_logs_result(
        SRV_CLOG_BASE_CB func_cb,
        U32 total_num,
        U32 deleted_num,
        srv_clog_ret_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_del_all_logs_cnf_struct del_all_cnf_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!func_cb)
        return;

    del_all_cnf_data.total_num = total_num;
    del_all_cnf_data.deleted_num = deleted_num;
    del_all_cnf_data.ret = ret;        
    (func_cb) (0, 0, NULL, &del_all_cnf_data, MMI_FALSE, del_all_cnf_data.ret);
}


#ifndef __MMI_CONTACT_SLIM__
/*****************************************************************************
 * FUNCTION
 *  srv_clog_cb_search_list_log_ids_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_data        [?]     
 *  cnf_data        [?]    
 *  func_cb        [?]    
 *  ret        [?]    
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_cb_search_list_log_ids_result(
    SRV_CLOG_BASE_CB func_cb,
    srv_clog_search_list_log_ids_req_struct *req_data,
    srv_clog_search_list_log_ids_cnf_struct *cnf_data,    
    srv_clog_ret_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL more = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!func_cb)
        return SRV_CLOG_RET_OK;

    if (cnf_data->id_num >= SRV_CLOG_LOG_ID_LIST_MAX_NUM)
        more = MMI_TRUE; /* still have query data */
    return (func_cb) (0, 0, req_data, cnf_data, more, ret);
}
#endif /* __MMI_CONTACT_SLIM__ */


#ifdef __MMI_CLOG_CALL_TIME__
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
}
#endif /* __MMI_CLOG_CALL_TIME__ */


