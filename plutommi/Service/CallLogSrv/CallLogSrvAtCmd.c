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
*  CallLogSrvAtCmd.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  CallLog AT Command Support
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
#include "mmi_include.h"

#include "kal_general_types.h"
#include "ps_public_enum.h"
#include "ps_public_struct.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "mmi_msg_struct.h"

#include "common_nvram_editor_data_item.h"

#include "l4c_common_enum.h"
#include "l4c2phb_enums.h"
#include "l4c_aux_struct.h"

#include "MMIDataType.h"
#include "mmi_frm_utility_gprot.h"
#include "mmi_frm_queue_gprot.h"

#include "CallLogSrvGprot.h"
#include "CallLogSrvIprot.h"
#include "CallLogSrvConfig.h"
#include "CallLogSrvUtils.h"
#include "CallLogSrvComp.h"
#include "CallLogSrvProt.h"


#ifdef __MMI_CLOG_ATCMD_SUPPORT__

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
typedef enum
{
    SRV_CLOG_AT_OP_WRITE,
    SRV_CLOG_AT_OP_DELETE,
    SRV_CLOG_AT_OP_MAX_TIEM
} srv_clog_at_op_enum;

typedef struct
{
    int mod_id;
    srv_clog_at_op_enum at_op;
    U8 src_id;
    U8 type;
    U16 index;
} srv_clog_at_cntx_struct;

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/
static U32 srv_clog_at_get_max_size(srv_clog_cntx_struct *cntx, mmi_sim_enum sim_id, srv_clog_clt_enum clt_id);

static U8 srv_clog_at_l4c_read_clog_req_ind_hdlr(void *local_param, int mod_id, void *ilm);
static void srv_clog_at_send_l4c_read_clog_res_req(
                int mod_id,
                mmi_l4c_read_clog_req_ind_struct *ind,
                const srv_clog_si_struct *si_log,
                srv_clog_ret_enum ret);

static U8 srv_clog_at_l4c_write_clog_req_ind_hdlr(void *local_param, int mod_id, void *ilm);
static S32 srv_clog_at_write_result_hdlr(
            SRV_CLOG_HANDLE handle,
            S32 pid,
            void *req_data,
            void *cnf_data,
            MMI_BOOL more,
            srv_clog_ret_enum ret);
static void srv_clog_at_send_l4c_write_clog_res_req(int mod_id, U8 src_id, U16 index, srv_clog_ret_enum ret);
static U8 srv_clog_at_l4c_delete_clog_req_ind_hdlr(void *local_param, int mod_id, void *ilm);
static S32 srv_clog_at_delete_result_hdlr(
            SRV_CLOG_HANDLE handle,
            S32 pid,
            void *req_data,
            void *cnf_data,
            MMI_BOOL more,
            srv_clog_ret_enum ret);
static void srv_clog_at_send_l4c_delete_clg_res_req(int mod_id, U8 src_id, U16 index, srv_clog_ret_enum ret);
static void srv_clog_at_send_l4c_update_status_res_req(
                U32 sim_idx,
                U32 clt_idx,
                U32 used_num,
                const srv_clog_si_struct *si_log);

static void srv_clog_at_set_cntx_info(
                srv_clog_at_cntx_struct *user_data,
                srv_clog_at_op_enum op,
                int mod_id,
                void *ind);
static void srv_clog_at_set_idt(srv_clog_log_identity_struct *idt, int mod_id, U8 l4c_type);

/*----------------------------------------------------------------------------*/
/* Extern Function Defines                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/

#define SRV_CLOG_AT_INIT


/*****************************************************************************
 * FUNCTION
 *  srv_clog_at_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_at_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_L4C_READ_CLOG_REQ_IND, 
        (PsIntFuncPtr) srv_clog_at_l4c_read_clog_req_ind_hdlr, MMI_FALSE);

    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_L4C_WRITE_CLOG_REQ_IND, 
        (PsIntFuncPtr) srv_clog_at_l4c_write_clog_req_ind_hdlr, MMI_FALSE);

    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_L4C_DELETE_CLOG_REQ_IND, 
        (PsIntFuncPtr) srv_clog_at_l4c_delete_clog_req_ind_hdlr, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_at_get_max_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx            [IN] Context         
 *  sim_id          [IN] SIM id        
 *  clt_id          [IN] Call log type        
 * RETURNS
 *  
 *****************************************************************************/
static U32 srv_clog_at_get_max_size(srv_clog_cntx_struct *cntx, mmi_sim_enum sim_id, srv_clog_clt_enum clt_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32  num_style;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if limited by log type or by SIM id */
    srv_clog_stl_get_style(cntx->comp->style_mgr, SRV_CLOG_STYLE_TYPE_NUM, &num_style, NULL);
    if (!SRV_CLOG_CHECK_BIT(num_style, SRV_CLOG_STYLE_NUM_SIM_LIMITED))
        sim_id = (mmi_sim_enum)MMI_SIM_ALL;
    return srv_clog_pi_get_clt_max_size(sim_id, clt_id);
}


#define SRV_CLOG_AT_READ


/*****************************************************************************
 * FUNCTION
 *  srv_clog_at_l4c_read_clog_req_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_param     [?]         
 *  mod_id          [IN]        
 *  ilm             [?]         
 * RETURNS
 *  
 *****************************************************************************/
static U8 srv_clog_at_l4c_read_clog_req_ind_hdlr(void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim_id;
    srv_clog_ret_enum ret;
    srv_clog_clt_enum clt_id;
    srv_clog_si_struct *si_log;
    srv_clog_log_identity_struct idt;
    srv_clog_idx_info_enum info_type;
    mmi_l4c_read_clog_req_ind_struct *ind;
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
    srv_clog_cntx_struct *cntx = srv_clog_cntx_p;
#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind = (mmi_l4c_read_clog_req_ind_struct*) local_param;
    if (!srv_clog_is_ready())
    {
        srv_clog_at_send_l4c_read_clog_res_req(mod_id, ind, NULL, SRV_CLOG_RET_NOT_FOUND);
        return 0;
    }

    sim_id = mmi_frm_l4c_mod_to_sim((module_type)mod_id);
    clt_id = srv_clog_clt_l4c2bit(ind->type);

    if (ind->index >= srv_clog_at_get_max_size(cntx, sim_id, clt_id))
    {
        srv_clog_at_send_l4c_read_clog_res_req(mod_id, ind, NULL, SRV_CLOG_RET_NOT_FOUND);
        return 0;
    }

    srv_clog_at_set_idt(&idt, mod_id, ind->type);

    srv_clog_idx_refresh(cntx->comp->idx_tbl, SRV_CLOG_LIST_LEVEL_STORE, &idt, &info_type);
    si_log = srv_clog_idx_peek_si_by_idx(cntx->comp->idx_tbl, info_type, ind->index);
    if (!si_log)
        ret = SRV_CLOG_RET_NOT_FOUND;
    else
        ret = SRV_CLOG_RET_OK;

    SRV_CLOG_DUMP_LOG(ind->index, si_log);

    srv_clog_at_send_l4c_read_clog_res_req(mod_id, ind, (const srv_clog_si_struct*)si_log, ret);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_at_send_l4c_read_clog_res_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mod_id      [IN]        
 *  ind         [?]         
 *  si_log      [IN]        
 *  ret         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_at_send_l4c_read_clog_res_req(
                int mod_id,
                mmi_l4c_read_clog_req_ind_struct *ind,
                const srv_clog_si_struct *si_log,
                srv_clog_ret_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_l4c_read_clog_res_req_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    res = SRV_CLOG_NEW_ILM_DATA(mmi_l4c_read_clog_res_req_struct);
    res->phb_src = ind->src_id;
    res->type = ind->type;
    res->index = ind->index;
    srv_clog_ret_clog2l4c(ret, &res->result);
    srv_clog_log_si2l4c(si_log, &res->entry);
    mmi_frm_send_ilm((module_type)mod_id, MSG_ID_MMI_L4C_READ_CLOG_RES_REQ, (oslParaType*) res, NULL);
}

#define SRV_CLOG_AT_WRITE


/*****************************************************************************
 * FUNCTION
 *  srv_clog_at_l4c_write_clog_req_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_param     [?]         
 *  mod_id          [IN]        
 *  ilm             [?]         
 * RETURNS
 *  
 *****************************************************************************/
static U8 srv_clog_at_l4c_write_clog_req_ind_hdlr(void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_clt_idx_enum clt_idx;
    mmi_sim_enum sim_id;
//    srv_clog_sim_idx_enum sim_idx;
    srv_clog_clt_enum clt_type;
    const mmi_l4c_write_clog_req_ind_struct *ind;
    srv_clog_create_struct create = {0};
    SRV_CLOG_HANDLE handle;
    srv_clog_at_cntx_struct *write_udata;
    srv_clog_log_struct cmn_log;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind = (const mmi_l4c_write_clog_req_ind_struct*)local_param;

    if (!srv_clog_is_ready())
    {
        srv_clog_at_send_l4c_write_clog_res_req(mod_id, ind->src_id, ind->index, SRV_CLOG_RET_NOT_READY);
        return 0;
    }
    SRV_CLOG_ASSERT(ind->type < PHB_LN_NONE);
    clt_idx = srv_clog_clt_l4c2idx(ind->type);
    sim_id = mmi_frm_l4c_mod_to_sim((module_type)mod_id);

    /*
     * SRV_CLOG_BIT2IDX(sim_id, sim_idx);
     * not check the index as L4C not support it, it may be give a wrong index here.
     *
     * if (ind->index >= srv_clog_pi_get_clt_max_size(sim_idx, clt_idx))
     * {
     * srv_clog_at_send_l4c_write_clog_res_req(mod_id, ind->src_id, ind->index, SRV_CLOG_RET_NOT_FOUND);
     * return 0;
     * }
     */

    write_udata = SRV_CLOG_TALLOC(SRV_CLOG_MEM_TYPE_TEMP, srv_clog_at_cntx_struct);
    srv_clog_at_set_cntx_info(write_udata, SRV_CLOG_AT_OP_WRITE, mod_id, (void*)ind);
    create.user_data = write_udata;
    handle = srv_clog_create(&create);

    clt_type = (srv_clog_clt_enum)SRV_CLOG_IDX2BIT(clt_idx);
    srv_clog_log_l4c2cmn((const l4c_phb_ln_entry_struct*)&ind->entry, sim_id, clt_type, &cmn_log);
    srv_clog_add_log(handle, 0, (const srv_clog_log_struct*)&cmn_log, NULL, srv_clog_at_write_result_hdlr);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_at_write_result_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  pid             [IN]        
 *  req_data        [?]         
 *  cnf_data        [?]         
 *  more            [IN]        
 *  ret             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_at_write_result_hdlr(
            SRV_CLOG_HANDLE handle,
            S32 pid,
            void *req_data,
            void *cnf_data,
            MMI_BOOL more,
            srv_clog_ret_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_at_cntx_struct *write_udata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    write_udata = srv_clog_get_user_data(handle);
    srv_clog_at_send_l4c_write_clog_res_req(write_udata->mod_id, write_udata->src_id, write_udata->index, ret);
    SRV_CLOG_MFREE(SRV_CLOG_MEM_TYPE_TEMP, write_udata);
    srv_clog_destroy(handle);
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_at_send_l4c_write_clog_res_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mod_id      [IN]        
 *  src_id      [IN]        
 *  index       [IN]        
 *  ret         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_at_send_l4c_write_clog_res_req(int mod_id, U8 src_id, U16 index, srv_clog_ret_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_l4c_write_clog_res_req_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    res = SRV_CLOG_NEW_ILM_DATA(mmi_l4c_write_clog_res_req_struct);
    res->phb_src = src_id;
    res->index = index;
    srv_clog_ret_clog2l4c(ret, &res->result);

    mmi_frm_send_ilm((module_type)mod_id, MSG_ID_MMI_L4C_WRITE_CLOG_RES_REQ, (oslParaType*) res, NULL);
}

#define SRV_CLOG_AT_DELETE


/*****************************************************************************
 * FUNCTION
 *  srv_clog_at_l4c_delete_clog_req_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_param     [?]         
 *  mod_id          [IN]        
 *  ilm             [?]         
 * RETURNS
 *  
 *****************************************************************************/
static U8 srv_clog_at_l4c_delete_clog_req_ind_hdlr(void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_CLOG_ID log_id;
    mmi_sim_enum sim_id;
    srv_clog_idx_info_enum info_type;
    srv_clog_clt_enum clt_id;
    srv_clog_log_identity_struct idt;
    mmi_l4c_delete_clog_req_ind_struct *ind;
    SRV_CLOG_HANDLE handle;
    srv_clog_at_cntx_struct *delete_udata;
    srv_clog_create_struct create;
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
    srv_clog_cntx_struct *cntx = srv_clog_cntx_p;
#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind = (mmi_l4c_delete_clog_req_ind_struct*) local_param;

    if (!srv_clog_is_ready())
    {
        srv_clog_at_send_l4c_delete_clg_res_req(mod_id, ind->src_id, ind->index, SRV_CLOG_RET_NOT_READY);
        return 0;
    }

    sim_id = mmi_frm_l4c_mod_to_sim((module_type)mod_id);

    clt_id = srv_clog_clt_l4c2bit(ind->type);
    if (ind->index >= srv_clog_at_get_max_size(cntx, sim_id, clt_id))
    {
        srv_clog_at_send_l4c_delete_clg_res_req(mod_id, ind->src_id, ind->index, SRV_CLOG_RET_NOT_FOUND);
        return 0;
    }

    srv_clog_at_set_idt(&idt, mod_id, ind->type);
    srv_clog_idx_refresh(cntx->comp->idx_tbl, SRV_CLOG_LIST_LEVEL_STORE, &idt, &info_type);
    log_id = srv_clog_idx_idx2id(cntx->comp->idx_tbl, info_type, ind->index);
    if (SRV_CLOG_IS_ELM_INVALID(log_id))
    {
        srv_clog_at_send_l4c_delete_clg_res_req(mod_id, ind->src_id, ind->index, SRV_CLOG_RET_NOT_FOUND);
        return 0;
    }

    delete_udata = SRV_CLOG_TALLOC(SRV_CLOG_MEM_TYPE_TEMP, srv_clog_at_cntx_struct);
    srv_clog_at_set_cntx_info(delete_udata, SRV_CLOG_AT_OP_DELETE, mod_id, ind);
    create.user_data = delete_udata;
    handle = srv_clog_create(&create);
    if (SRV_CLOG_IS_ELM_INVALID(handle))
    {
        SRV_CLOG_MFREE(SRV_CLOG_MEM_TYPE_TEMP, delete_udata);
        srv_clog_at_send_l4c_delete_clg_res_req(mod_id, ind->src_id, ind->index, SRV_CLOG_RET_FAIL);
        return 0;
    }

    srv_clog_delete_log_by_id(handle, 0, log_id, srv_clog_at_delete_result_hdlr);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_at_delete_result_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  pid             [IN]        
 *  req_data        [?]         
 *  cnf_data        [?]         
 *  more            [IN]        
 *  ret             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_at_delete_result_hdlr(
            SRV_CLOG_HANDLE handle,
            S32 pid,
            void *req_data,
            void *cnf_data,
            MMI_BOOL more,
            srv_clog_ret_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_at_cntx_struct *delete_udata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    delete_udata = srv_clog_get_user_data(handle);
    srv_clog_at_send_l4c_delete_clg_res_req(delete_udata->mod_id, delete_udata->src_id, delete_udata->index, ret);
    SRV_CLOG_MFREE(SRV_CLOG_MEM_TYPE_TEMP, delete_udata);
    srv_clog_destroy(handle);
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_at_send_l4c_delete_clg_res_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mod_id      [IN]        
 *  src_id      [IN]        
 *  index       [IN]        
 *  ret         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_at_send_l4c_delete_clg_res_req(int mod_id, U8 src_id, U16 index, srv_clog_ret_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_l4c_delete_clog_res_req_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    res = SRV_CLOG_NEW_ILM_DATA(mmi_l4c_delete_clog_res_req_struct);
    res->phb_src = src_id;
    res->index = index;
    srv_clog_ret_clog2l4c(ret, &res->result);

    mmi_frm_send_ilm((module_type)mod_id, MSG_ID_MMI_L4C_DELETE_CLOG_RES_REQ, (oslParaType*) res, NULL);
}

#define SRV_CLOG_AT_UPDATE


/*****************************************************************************
 * FUNCTION
 *  srv_clog_at_send_l4c_update_status_res_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_idx         [IN]        
 *  clt_idx         [IN]        
 *  used_num        [IN]        
 *  si_log          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_at_send_l4c_update_status_res_req(
                U32 sim_idx,
                U32 clt_idx,
                U32 used_num,
                const srv_clog_si_struct *si_log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_l4c_clog_update_status_res_req_struct *ind;
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
    srv_clog_cntx_struct *cntx = srv_clog_cntx_p;
#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clt_idx == SRV_CLOG_CLT_IDX_REJED)
        return;
    ind = SRV_CLOG_NEW_ILM_DATA(mmi_l4c_clog_update_status_res_req_struct);
    ind->type = srv_clog_clt_idx2l4c((srv_clog_clt_idx_enum)clt_idx);
    ind->total = srv_clog_at_get_max_size(cntx, (mmi_sim_enum)SRV_CLOG_IDX2BIT(sim_idx), (srv_clog_clt_enum)SRV_CLOG_IDX2BIT(clt_idx));
    ind->used = used_num;
    ind->free = ind->total - used_num;
    ind->with_first_entry = (si_log == NULL ? KAL_FALSE : KAL_TRUE);
    srv_clog_log_si2l4c(si_log, &ind->first_entry);
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
    srv_clog_send_l4c_ilm((mmi_sim_enum)sim_idx, MSG_ID_MMI_L4C_CLOG_UPDATE_STATUS_RES_REQ, (oslParaType*) ind);
#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    srv_clog_send_l4c_ilm((mmi_sim_enum)SRV_CLOG_IDX2BIT(sim_idx), MSG_ID_MMI_L4C_CLOG_UPDATE_STATUS_RES_REQ, (oslParaType*) ind);
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_at_set_cntx_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  user_data       [?]         
 *  op              [IN]        
 *  mod_id          [IN]        
 *  ind             [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_at_set_cntx_info(
                srv_clog_at_cntx_struct *user_data,
                srv_clog_at_op_enum op,
                int mod_id,
                void *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_l4c_write_clog_req_ind_struct *write_ind;
    mmi_l4c_delete_clog_req_ind_struct *delete_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data->at_op = op;
    user_data->mod_id = mod_id;
    switch (op)
    {
        case SRV_CLOG_AT_OP_WRITE:
            write_ind = (mmi_l4c_write_clog_req_ind_struct*) ind;
            user_data->src_id = write_ind->src_id;
            user_data->type = write_ind->type;
            user_data->index = write_ind->index;
            break;

        case SRV_CLOG_AT_OP_DELETE:
            delete_ind = (mmi_l4c_delete_clog_req_ind_struct*) ind;
            user_data->src_id = delete_ind->src_id;
            user_data->type = delete_ind->type;
            user_data->index = delete_ind->index;
            break;

        default:
            SRV_CLOG_ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_at_set_idt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idt             [?]         
 *  mod_id          [IN]        
 *  l4c_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_at_set_idt(srv_clog_log_identity_struct *idt, int mod_id, U8 l4c_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idt->cate = SRV_CLOG_CATE_CALL;
    idt->sim_id = mmi_frm_l4c_mod_to_sim((module_type)mod_id);
    idt->log_type = SRV_CLOG_IDX2BIT(srv_clog_clt_l4c2idx(l4c_type));
    idt->sub_type = SRV_CLOG_CALL_TYPE_ALL;
}

#define SRV_CLOG_AT_IF


/*****************************************************************************
 * FUNCTION
 *  srv_clog_at_notify_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_at_notify_ready(srv_clog_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 j;
    srv_clog_num_info_struct num_info;
    srv_clog_log_identity_struct idt;
    srv_clog_si_struct *si_log = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idt.cate = SRV_CLOG_CATE_CALL;
    idt.sub_type = SRV_CLOG_CALL_TYPE_ALL;

    for (i = 0; i < SRV_CLOG_SIM_IDX_MAX_ITEM; i++)
    {
        idt.sim_id = SRV_CLOG_IDX2BIT(i);
        for (j = 0; j < SRV_CLOG_CLT_IDX_MAX_ITEM; j++)
        {
            if (j == SRV_CLOG_CLT_IDX_REJED || j == SRV_CLOG_CLT_IDX_ALL)
                continue;

            idt.log_type = SRV_CLOG_IDX2BIT(j);

            if (j == SRV_CLOG_CLT_IDX_DIALED)
                si_log = srv_clog_idx_get_last_log(cntx->comp->idx_tbl, &idt);
            else
                si_log = NULL;
            srv_clog_idx_get_num_info(cntx->comp->idx_tbl, &idt, &num_info);
            srv_clog_at_send_l4c_update_status_res_req(i, j, num_info.num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS], si_log);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_at_notify_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  cntx        [?]         
 *  props       [IN]        
 *  idt         [?]         
 *  si_log      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_at_notify_update(
        srv_clog_at_update_enum type,
        srv_clog_cntx_struct *cntx,
    #ifdef __MMI_CLOG_SLIM_FOR_MT6261__
        U8 props,
    #else /* __MMI_CLOG_SLIM_FOR_MT6261__ */
        U32 props,
    #endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
        srv_clog_log_identity_struct *idt,
        srv_clog_si_struct *si_log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 j;
    U32 cate_idx;
    U32 sim_idx;
    U32 clt_idx;
    U32 st_idx;
    srv_clog_num_info_struct num_info;
    srv_clog_log_identity_struct new_idt;
    srv_clog_si_struct *new_si_log = si_log;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == SRV_CLOG_AT_UPDATE_UPD_ALL || type == SRV_CLOG_AT_UPDATE_DEL_ALL)
    {
        if (!SRV_CLOG_CHECK_BIT(idt->cate, SRV_CLOG_CATE_CALL))
            return;
        if (type == SRV_CLOG_AT_UPDATE_UPD_ALL)
        {
            if (idt->log_type != SRV_CLOG_CLT_DIALED)
                return;
        }
        /* send event to notify */
        new_idt.cate = SRV_CLOG_CATE_CALL;
        new_idt.sub_type = SRV_CLOG_CALL_TYPE_ALL;

        for (i = 0; i < SRV_CLOG_SIM_IDX_MAX_ITEM; i++)
        {
            if (!SRV_CLOG_CHECK_BIT(idt->sim_id, SRV_CLOG_IDX2BIT(i)))
                continue;
            for (j = 0; j < SRV_CLOG_CLT_IDX_MAX_ITEM; j++)
            {
                if (type == SRV_CLOG_AT_UPDATE_UPD_ALL && j != SRV_CLOG_CLT_IDX_DIALED ||
                    !SRV_CLOG_CHECK_BIT(idt->log_type, SRV_CLOG_IDX2BIT(j)))
                    continue;
                new_idt.sim_id = SRV_CLOG_IDX2BIT(i);
                new_idt.log_type = SRV_CLOG_IDX2BIT(j);
                srv_clog_idx_get_num_info(cntx->comp->idx_tbl, &new_idt, &num_info);
                if (j == SRV_CLOG_CLT_IDX_DIALED)
                    new_si_log = srv_clog_idx_get_last_log(cntx->comp->idx_tbl, &new_idt);
                else
                    new_si_log = NULL;
                srv_clog_at_send_l4c_update_status_res_req(
                    i,
                    j,
                    num_info.num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS],
                    new_si_log);
            }

        }
        return;
    }

    srv_clog_pi_p2idx(props, &cate_idx, &sim_idx, &clt_idx, &st_idx);
#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
    cate_idx = SRV_CLOG_PI_P2IDX(props, SRV_CLOG_LSP_CATE, SRV_CLOG_LSP_CATE_POS);
    if (cate_idx != SRV_CLOG_CATE_IDX_CALL)
        return;
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    if (type == SRV_CLOG_AT_UPDATE_UPD && clt_idx != SRV_CLOG_CLT_IDX_DIALED)
        return;

    new_idt.cate = SRV_CLOG_CATE_CALL;
    new_idt.sim_id = SRV_CLOG_IDX2BIT(sim_idx);
    new_idt.log_type = SRV_CLOG_IDX2BIT(clt_idx);
    new_idt.sub_type = SRV_CLOG_CALL_TYPE_ALL;

    if (clt_idx == SRV_CLOG_CLT_IDX_DIALED)
    {
        new_si_log = srv_clog_idx_get_last_log(cntx->comp->idx_tbl, &new_idt);
        if (type == SRV_CLOG_AT_UPDATE_UPD)
        {
            /* check if last dialed log are updated */
        #ifdef __MMI_CLOG_SLIM_FOR_MT6261__
            if (SRV_CLOG_SILOG_GET_LOG_ID(si_log) != SRV_CLOG_SILOG_GET_LOG_ID(new_si_log))
        #else /* __MMI_CLOG_SLIM_FOR_MT6261__ */
            if (SRV_CLOG_SI_GET_LOG_ID(si_log) != SRV_CLOG_SI_GET_LOG_ID(new_si_log))
        #endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
                return;
        }
    }
    else
    {
        new_si_log = NULL;
    }

    srv_clog_idx_get_num_info(cntx->comp->idx_tbl, &new_idt, &num_info);

    srv_clog_at_send_l4c_update_status_res_req(
        sim_idx,
        clt_idx,
        num_info.num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS],
        new_si_log);
}


#endif /* __MMI_CLOG_ATCMD_SUPPORT__ */


