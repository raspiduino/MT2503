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
*  CallLogSrvCallCost.c
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

#include "MMI_features.h"

#ifdef __MMI_CLOG_CALL_COST__
/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "mmi_include.h"

#include "string.h"

#include "kal_general_types.h"
#include "kal_trace.h"
#include "ps_public_enum.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "l4c_common_enum.h"
#include "mmi_msg_struct.h"

#include "MMIDataType.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "Unicodexdcl.h"

#include "mmi_frm_utility_gprot.h"
#include "mmi_frm_queue_gprot.h"

#include "CallLogSrvGprot.h"
#include "CallLogSrvIprot.h"
#include "CallLogSrvConfig.h"
#include "CallLogSrvUtils.h"
#include "CallLogSrvProt.h"


/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/
#define SRV_CLOG_CCOST_INVALID_CCM_VALUE        (0x00FFFFFF)
#define SRV_CLOG_CCOST_INVALID_CURRENCY_CHAR    (0xFF)
#define SRV_CLOG_CCOST_MAX_PS_CURRENCY_SIZE     (3)
#define SRV_CLOG_CCOST_MAX_PS_PPU_SIZE          (18)
#define SRV_CLOG_CCOST_PS_PPU_INT_SIZE          (11)

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/
typedef enum
{
    SRV_CLOG_CCOST_OP_GET,
    SRV_CLOG_CCOST_OP_SET,
    SRV_CLOG_CCOST_OP_MAX_ITEM
} srv_clog_ccost_op_enum;

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/
typedef struct
{
    srv_clog_ccost_op_enum op_type;
    mmi_sim_enum sim_id;
    U8 req_fields;
    mmi_sim_enum rsp_sim_id;
    U8 rsp_fields[SRV_CLOG_SIM_IDX_MAX_ITEM];
    void *user_data;
    SRV_CLOG_CCOST_GET_CB get_cb;
    SRV_CLOG_CCOST_SET_CB set_cb;
    srv_clog_ccost_data_struct data[SRV_CLOG_SIM_IDX_MAX_ITEM];
    srv_clog_ret_enum ret[SRV_CLOG_SIM_IDX_MAX_ITEM];
} srv_clog_ccost_cntx_struct;

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/
static srv_clog_ccost_cntx_struct *srv_clog_ccost_cntx_p;

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/
/* Context */
static srv_clog_ccost_cntx_struct * srv_clog_ccost_new_cntx(void);
static void srv_clog_ccost_free_cntx(void);
static srv_clog_ccost_cntx_struct *srv_clog_ccost_get_cntx(void);
static void srv_clog_ccost_set_cntx(srv_clog_ccost_cntx_struct *cntx,
                                    srv_clog_ccost_op_enum op_type,
                                    mmi_sim_enum sim_id, 
                                    U32 fields,
                                    const void *user_data,
                                    SRV_CLOG_CCOST_GET_CB get_func_cb,
                                    SRV_CLOG_CCOST_SET_CB set_func_cb);


/* Get data */
static void srv_clog_ccost_cp_data(const srv_clog_ccost_data_struct *src, srv_clog_ccost_data_struct *dst);
static void srv_clog_ccost_async_get_data(mmi_sim_enum sim_id, U32 fields);
static void srv_clog_ccost_send_get_ccm_req(mmi_sim_enum sim_id);
static void srv_clog_ccost_send_cc_get_acm_req(mmi_sim_enum sim_id);
static void srv_clog_ccost_send_cc_get_max_acm_req(mmi_sim_enum sim_id);
static void srv_clog_ccost_send_smu_get_puc_req(mmi_sim_enum sim_id);
static U8 srv_clog_ccost_cc_get_ccm_rsp_hdlr(void *local_param, int mod_id, void *ilm);
static U8 srv_clog_ccost_cc_get_acm_rsp_hdlr(void *local_param, int mod_id, void *ilm);
static U8 srv_clog_ccost_cc_get_max_acm_rsp_hdlr(void *local_param, int mod_id, void *ilm);
static U8 srv_clog_ccost_smu_get_puc_rsp_hdlr(void *local_param, int mod_id, void *ilm);

/* Set data */
static void srv_clog_ccost_async_set_data(
                mmi_sim_enum sim_id,
                U32 fields,
                const srv_clog_ccost_data_struct *data,
                const WCHAR *pin);

static void srv_clog_ccost_send_cc_reset_ccm_req(
                mmi_sim_enum sim_id,
                const srv_clog_ccost_data_struct *data,
                const WCHAR *pin);
static void srv_clog_ccost_send_cc_reset_acm_req(
                mmi_sim_enum sim_id,
                const srv_clog_ccost_data_struct *data,
                const WCHAR *pin);
static void srv_clog_ccost_send_cc_set_max_acm_req(
                mmi_sim_enum sim_id,
                const srv_clog_ccost_data_struct *data,
                const WCHAR *pin);
static void srv_clog_ccost_send_smu_set_puc_req(
                mmi_sim_enum sim_id,
                const srv_clog_ccost_data_struct *data,
                const WCHAR *pin);

static U8 srv_clog_ccost_cc_reset_ccm_rsp_hdlr(void *local_param, int mod_id, void *ilm);
static U8 srv_clog_ccost_cc_reset_acm_rsp_hdlr(void *local_param, int mod_id, void *ilm);
static U8 srv_clog_ccost_cc_set_max_acm_rsp_hdlr(void *local_param, int mod_id, void *ilm);
static U8 srv_clog_ccost_smu_set_puc_rsp_hdlr(void *local_param, int mod_id, void *ilm);

/* Misc */
static S32 srv_clog_ccost_cb_result(srv_clog_ccost_cntx_struct *cntx, mmi_sim_enum sim_id);
static S32 srv_clog_ccost_process(srv_clog_ccost_cntx_struct *cntx, mmi_sim_enum sim_id);
static void srv_clog_ccost_currency_ps2mmi(const CHAR *ps_cur, WCHAR *mmi_cur);
static void srv_clog_ccost_currency_mmi2ps(const WCHAR *mmi_cur, CHAR *ps_cur);
static void srv_clog_ccost_ppu_ps2mmi(const CHAR *ps_ppu, WCHAR *mmi_ppu);
static void srv_clog_ccost_ppu_mmi2pi(const WCHAR *mmi_ppu, CHAR *ps_ppu);

/*----------------------------------------------------------------------------*/
/* Extern Function Defines                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/

#define SRV_CLOG_CCOST_CNTX

/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_new_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src     [IN]        
 *  dst     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static srv_clog_ccost_cntx_struct * srv_clog_ccost_new_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_ccost_cntx_p = SRV_CLOG_TALLOC(SRV_CLOG_MEM_TYPE_TEMP, srv_clog_ccost_cntx_struct);
    return srv_clog_ccost_cntx_p;
}

/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_free_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src     [IN]        
 *  dst     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_ccost_free_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_ZFREE(SRV_CLOG_MEM_TYPE_TEMP, srv_clog_ccost_cntx_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_get_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src     [IN]        
 *  dst     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static srv_clog_ccost_cntx_struct *srv_clog_ccost_get_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_clog_ccost_cntx_p;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_set_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src     [IN]        
 *  dst     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_ccost_set_cntx(srv_clog_ccost_cntx_struct *cntx,
                                    srv_clog_ccost_op_enum op_type,
                                    mmi_sim_enum sim_id, 
                                    U32 fields,
                                    const void *user_data,
                                    SRV_CLOG_CCOST_GET_CB get_func_cb,
                                    SRV_CLOG_CCOST_SET_CB set_func_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->op_type = op_type;
    cntx->sim_id = sim_id;
    if (!cntx->sim_id) /* for non-dual sim project */
        cntx->sim_id = MMI_SIM1;
    
    cntx->req_fields = fields;
    if (!cntx->req_fields)
        cntx->req_fields = SRV_CLOG_CCOST_FIELD_ALL;
    /* reset response data */
    cntx->rsp_sim_id = MMI_SIM_NONE;
    for (i = 0; i < SRV_CLOG_SIM_IDX_MAX_ITEM; i++)
    {
        cntx->rsp_fields[i] = 0;
        cntx->ret[i] = SRV_CLOG_RET_OK;
        srv_clog_ccost_cp_data(NULL, &cntx->data[i]);
    }

    cntx->user_data = (void*)user_data;
    cntx->get_cb = get_func_cb;
    cntx->set_cb = set_func_cb;
}


#define SRV_CLOG_CCOST_GET_DATA


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_get_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id          [IN]        
 *  fields          [IN]        
 *  user_data       [IN]        
 *  func_cb         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_ccost_get_data(mmi_sim_enum sim_id, U32 fields, const void *user_data, SRV_CLOG_CCOST_GET_CB func_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_ccost_cntx_struct *cntx = srv_clog_ccost_get_cntx();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SRV_CLOG_CHECK_BIT(MMI_SIM_ALL, sim_id) || 
        !SRV_CLOG_CHECK_BIT(SRV_CLOG_CCOST_FIELD_ALL, fields)||
        !func_cb)
    {
        return SRV_CLOG_RET_INVALID_PARAM;
    }
    if (cntx)
        return SRV_CLOG_RET_NOT_AVAILABLE;

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_CCOST_GET_DATA, sim_id, fields);

    cntx = srv_clog_ccost_new_cntx();
    srv_clog_ccost_set_cntx(cntx, SRV_CLOG_CCOST_OP_GET, sim_id, fields, user_data, func_cb, NULL);

    srv_clog_ccost_async_get_data(sim_id, fields);
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_cp_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src     [IN]        
 *  dst     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_ccost_cp_data(const srv_clog_ccost_data_struct *src, srv_clog_ccost_data_struct *dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!src)
    {
        dst->last = 0;
        dst->total = 0;
        dst->max = 0;
        dst->ppu[0] = '\0';
        dst->currency[0] = '\0';
    }
    else
    {
        dst->last = src->last;
        dst->total = src->total;
        dst->max = src->max;
        mmi_wcscpy(dst->currency, (const WCHAR*)src->currency);
        mmi_wcscpy(dst->ppu, (const WCHAR*)src->ppu);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_async_get_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 *  fields      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_ccost_async_get_data(mmi_sim_enum sim_id, U32 fields)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_CCOST_FIELD_LAST))
        srv_clog_ccost_send_get_ccm_req(sim_id);
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_CCOST_FIELD_TOTAL))
        srv_clog_ccost_send_cc_get_acm_req(sim_id);
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_CCOST_FIELD_MAX))
        srv_clog_ccost_send_cc_get_max_acm_req(sim_id);
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_CCOST_FIELD_PUC))
        srv_clog_ccost_send_smu_get_puc_req(sim_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_send_get_ccm_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_ccost_send_get_ccm_req(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_send_l4c_ilm(sim_id, MSG_ID_MMI_CC_GET_CCM_REQ, NULL);
    
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_CC_GET_CCM_RSP, 
        (PsIntFuncPtr) srv_clog_ccost_cc_get_ccm_rsp_hdlr, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_send_cc_get_acm_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_ccost_send_cc_get_acm_req(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_send_l4c_ilm(sim_id, MSG_ID_MMI_CC_GET_ACM_REQ, NULL);
    
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_CC_GET_ACM_RSP, 
        (PsIntFuncPtr) srv_clog_ccost_cc_get_acm_rsp_hdlr, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_send_cc_get_max_acm_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_ccost_send_cc_get_max_acm_req(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_send_l4c_ilm(sim_id, MSG_ID_MMI_CC_GET_MAX_ACM_REQ, NULL);
    
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_CC_GET_MAX_ACM_RSP, 
        (PsIntFuncPtr) srv_clog_ccost_cc_get_max_acm_rsp_hdlr, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_send_smu_get_puc_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_ccost_send_smu_get_puc_req(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_send_l4c_ilm(sim_id, MSG_ID_MMI_SMU_GET_PUC_REQ, NULL);

    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_SMU_GET_PUC_RSP, 
        (PsIntFuncPtr) srv_clog_ccost_smu_get_puc_rsp_hdlr, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_cc_get_ccm_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_param     [?]         
 *  mod_id          [IN]        
 *  ilm             [?]         
 * RETURNS
 *  
 *****************************************************************************/
static U8 srv_clog_ccost_cc_get_ccm_rsp_hdlr(void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 sim_idx;
    mmi_sim_enum sim_id;
    mmi_cc_get_ccm_rsp_struct *rsp;
    srv_clog_ccost_cntx_struct *cntx = srv_clog_ccost_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cntx)
        return 0;

    SRV_CLOG_ASSERT(cntx->op_type == SRV_CLOG_CCOST_OP_GET);

    rsp = (mmi_cc_get_ccm_rsp_struct*) local_param;

    sim_id = mmi_frm_l4c_mod_to_sim((module_type)mod_id);
    SRV_CLOG_BIT2IDX(sim_id, sim_idx);

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_CCOST_GET_DATA_RSP, 1, sim_id, rsp->result, rsp->ccm);

    cntx->rsp_fields[sim_idx] |= SRV_CLOG_CCOST_FIELD_LAST;

    if (rsp->result == MMI_TRUE)
    {
        cntx->data[sim_idx].last = rsp->ccm;

        if (rsp->ccm == SRV_CLOG_CCOST_INVALID_CCM_VALUE)
        {
            cntx->data[sim_idx].last = 0;
        }
    }
    else
    {
        cntx->ret[sim_idx] = SRV_CLOG_RET_FAIL;
    }
    srv_clog_ccost_process(cntx, sim_id);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_cc_get_acm_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_param     [?]         
 *  mod_id          [IN]        
 *  ilm             [?]         
 * RETURNS
 *  
 *****************************************************************************/
static U8 srv_clog_ccost_cc_get_acm_rsp_hdlr(void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 sim_idx;
    mmi_sim_enum sim_id;
    mmi_cc_get_acm_rsp_struct *rsp;
    srv_clog_ccost_cntx_struct *cntx = srv_clog_ccost_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cntx)
        return 0;

    SRV_CLOG_ASSERT(cntx->op_type == SRV_CLOG_CCOST_OP_GET);
    rsp = (mmi_cc_get_acm_rsp_struct*) local_param;
    sim_id = mmi_frm_l4c_mod_to_sim((module_type)mod_id);
    SRV_CLOG_BIT2IDX(sim_id, sim_idx);

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_CCOST_GET_DATA_RSP, 2, sim_id, rsp->result, rsp->acm);

    cntx->rsp_fields[sim_idx] |= SRV_CLOG_CCOST_FIELD_TOTAL;

    if (rsp->result == MMI_TRUE)
    {
        cntx->data[sim_idx].total = rsp->acm;
    }
    else
    {
        cntx->ret[sim_idx] = SRV_CLOG_RET_FAIL;
    }

    srv_clog_ccost_process(cntx, sim_id);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_cc_get_max_acm_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_param     [?]         
 *  mod_id          [IN]        
 *  ilm             [?]         
 * RETURNS
 *  
 *****************************************************************************/
static U8 srv_clog_ccost_cc_get_max_acm_rsp_hdlr(void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 sim_idx;
    mmi_sim_enum sim_id;
    mmi_cc_get_max_acm_rsp_struct *rsp;
    srv_clog_ccost_cntx_struct *cntx = srv_clog_ccost_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cntx)
        return 0;
    SRV_CLOG_ASSERT(cntx->op_type == SRV_CLOG_CCOST_OP_GET);

    rsp = (mmi_cc_get_max_acm_rsp_struct*) local_param;
    sim_id = mmi_frm_l4c_mod_to_sim((module_type)mod_id);
    SRV_CLOG_BIT2IDX(sim_id, sim_idx);

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_CCOST_GET_DATA_RSP, 3, sim_id, rsp->result, rsp->acm_max);

    cntx->rsp_fields[sim_idx] |= SRV_CLOG_CCOST_FIELD_MAX;

    if (rsp->result == MMI_TRUE)
    {
        cntx->data[sim_idx].max = rsp->acm_max;
    }
    else
    {
        cntx->ret[sim_idx] = SRV_CLOG_RET_FAIL;
    }
    srv_clog_ccost_process(cntx, sim_id);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_smu_get_puc_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_param     [?]         
 *  mod_id          [IN]        
 *  ilm             [?]         
 * RETURNS
 *  
 *****************************************************************************/
static U8 srv_clog_ccost_smu_get_puc_rsp_hdlr(void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 sim_idx;
    mmi_sim_enum sim_id;
    mmi_smu_get_puc_rsp_struct *rsp;
    srv_clog_ccost_cntx_struct *cntx = srv_clog_ccost_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cntx)
        return 0;
    SRV_CLOG_ASSERT(cntx->op_type == SRV_CLOG_CCOST_OP_GET);
    rsp = (mmi_smu_get_puc_rsp_struct*) local_param;
    sim_id = mmi_frm_l4c_mod_to_sim((module_type)mod_id);
    SRV_CLOG_BIT2IDX(sim_id, sim_idx);

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_CCOST_GET_DATA_RSP, 4, sim_id, rsp->result, 0);

    cntx->rsp_fields[sim_idx] |= SRV_CLOG_CCOST_FIELD_PUC;
    if (rsp->result == MMI_TRUE)
    {
        srv_clog_ccost_currency_ps2mmi((const CHAR*)rsp->currency, srv_clog_ccost_cntx_p->data[sim_idx].currency);
        srv_clog_ccost_ppu_ps2mmi((const CHAR*)rsp->ppu, srv_clog_ccost_cntx_p->data[sim_idx].ppu);
    }
    else
    {
        cntx->ret[sim_idx] = SRV_CLOG_RET_FAIL;
    }

    srv_clog_ccost_process(cntx, sim_id);
    return 0;
}

#define SRV_CLOG_CCOST_SET_DATA


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id          [IN]        
 *  fields          [IN]        
 *  data            [IN]        
 *  pin             [IN]        
 *  user_data       [IN]        
 *  func_cb         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_ccost_set_data(
        mmi_sim_enum sim_id,
        U32 fields,
        const srv_clog_ccost_data_struct *data,
        const WCHAR *pin,
        const void *user_data,
        SRV_CLOG_CCOST_SET_CB func_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_ccost_cntx_struct *cntx = srv_clog_ccost_get_cntx();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SRV_CLOG_CHECK_BIT(MMI_SIM_ALL, sim_id) || 
        fields && !SRV_CLOG_CHECK_BIT(SRV_CLOG_CCOST_FIELD_ALL_RESET, fields) ||
        !data || !func_cb)
    {
        return SRV_CLOG_RET_INVALID_PARAM;
    }

    if (cntx)
        return SRV_CLOG_RET_NOT_AVAILABLE;

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_CCOST_SET_DATA, sim_id, fields, data->last, data->total, data->max);

    cntx = srv_clog_ccost_new_cntx();
    srv_clog_ccost_set_cntx(cntx, SRV_CLOG_CCOST_OP_SET, sim_id, fields, user_data, NULL, func_cb);

    srv_clog_ccost_async_set_data(sim_id, fields, data, pin);
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_async_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 *  fields      [IN]        
 *  data        [IN]        
 *  pin         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_ccost_async_set_data(
                mmi_sim_enum sim_id,
                U32 fields,
                const srv_clog_ccost_data_struct *data,
                const WCHAR *pin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_CCOST_FIELD_LAST))
        srv_clog_ccost_send_cc_reset_ccm_req(sim_id, data, pin);
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_CCOST_FIELD_TOTAL))
        srv_clog_ccost_send_cc_reset_acm_req(sim_id, data, pin);
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_CCOST_FIELD_MAX))
        srv_clog_ccost_send_cc_set_max_acm_req(sim_id, data, pin);
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_CCOST_FIELD_PUC))
        srv_clog_ccost_send_smu_set_puc_req(sim_id, data, pin);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_send_cc_reset_ccm_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 *  data        [IN]        
 *  pin         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_ccost_send_cc_reset_ccm_req(
                mmi_sim_enum sim_id,
                const srv_clog_ccost_data_struct *data,
                const WCHAR *pin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_send_l4c_ilm(sim_id, MSG_ID_MMI_CC_RESET_CCM_REQ, NULL);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_CC_RESET_CCM_RSP, 
        (PsIntFuncPtr) srv_clog_ccost_cc_reset_ccm_rsp_hdlr, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_send_cc_reset_acm_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 *  data        [IN]        
 *  pin         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_ccost_send_cc_reset_acm_req(
                mmi_sim_enum sim_id,
                const srv_clog_ccost_data_struct *data,
                const WCHAR *pin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_reset_acm_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = SRV_CLOG_NEW_ILM_DATA(mmi_cc_reset_acm_req_struct);
    if (pin)
        mmi_wcs_n_to_asc((CHAR*) req->pin, (WCHAR*) pin, (MAX_SIM_PASSWD_LEN - 1) * ENCODING_LENGTH);
    else
        req->pin[0] = '\0';
    srv_clog_send_l4c_ilm(sim_id, MSG_ID_MMI_CC_RESET_ACM_REQ, req);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_CC_RESET_ACM_RSP, 
        (PsIntFuncPtr) srv_clog_ccost_cc_reset_acm_rsp_hdlr, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_send_cc_set_max_acm_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 *  data        [IN]        
 *  pin         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_ccost_send_cc_set_max_acm_req(
                mmi_sim_enum sim_id,
                const srv_clog_ccost_data_struct *data,
                const WCHAR *pin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_set_max_acm_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = SRV_CLOG_NEW_ILM_DATA(mmi_cc_set_max_acm_req_struct);
    if (pin)
        mmi_wcs_n_to_asc((CHAR*) req->pin, (WCHAR*) pin, (MAX_SIM_PASSWD_LEN - 1) * ENCODING_LENGTH);
    else
        req->pin[0] = '\0';
    req->val = data->max;

    srv_clog_send_l4c_ilm(sim_id, MSG_ID_MMI_CC_SET_MAX_ACM_REQ, req);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_CC_SET_MAX_ACM_RSP, 
        (PsIntFuncPtr) srv_clog_ccost_cc_set_max_acm_rsp_hdlr, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_send_smu_set_puc_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 *  data        [IN]        
 *  pin         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_ccost_send_smu_set_puc_req(
                mmi_sim_enum sim_id,
                const srv_clog_ccost_data_struct *data,
                const WCHAR *pin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_set_puc_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = SRV_CLOG_NEW_ILM_DATA(mmi_smu_set_puc_req_struct);
    if (pin)
        mmi_wcs_n_to_asc((CHAR*) req->pin, (WCHAR*) pin, (MAX_SIM_PASSWD_LEN - 1) * ENCODING_LENGTH);
    else
        req->pin[0] = '\0';
    srv_clog_ccost_currency_mmi2ps(data->currency, (CHAR*) req->currency);
    srv_clog_ccost_ppu_mmi2pi(data->ppu, (CHAR*) req->ppu);

    srv_clog_send_l4c_ilm(sim_id, MSG_ID_MMI_SMU_SET_PUC_REQ, req);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_SMU_SET_PUC_RSP, 
        (PsIntFuncPtr) srv_clog_ccost_smu_set_puc_rsp_hdlr, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_cc_reset_ccm_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_param     [?]         
 *  mod_id          [IN]        
 *  ilm             [?]         
 * RETURNS
 *  
 *****************************************************************************/
static U8 srv_clog_ccost_cc_reset_ccm_rsp_hdlr(void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 sim_idx;
    mmi_sim_enum sim_id;
    mmi_cc_reset_ccm_rsp_struct *rsp;
    srv_clog_ccost_cntx_struct *cntx = srv_clog_ccost_get_cntx();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_ASSERT(cntx && cntx->op_type == SRV_CLOG_CCOST_OP_SET);

    rsp = (mmi_cc_reset_ccm_rsp_struct*) local_param;
    sim_id = mmi_frm_l4c_mod_to_sim((module_type)mod_id);
    SRV_CLOG_BIT2IDX(sim_id, sim_idx);

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_CCOST_SET_DATA_RSP, 1, sim_id, rsp->result, rsp->cause);

    cntx->rsp_fields[sim_idx] |= SRV_CLOG_CCOST_FIELD_LAST;

    if (rsp->result != MMI_TRUE)
    {
        cntx->ret[sim_idx] = SRV_CLOG_RET_FAIL;
    }

    srv_clog_ccost_process(cntx, sim_id);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_cc_reset_acm_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_param     [?]         
 *  mod_id          [IN]        
 *  ilm             [?]         
 * RETURNS
 *  
 *****************************************************************************/
static U8 srv_clog_ccost_cc_reset_acm_rsp_hdlr(void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 sim_idx;
    mmi_sim_enum sim_id;
    mmi_cc_reset_acm_rsp_struct *rsp;
    srv_clog_ccost_cntx_struct *cntx = srv_clog_ccost_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_ASSERT(cntx && cntx->op_type == SRV_CLOG_CCOST_OP_SET);

    rsp = (mmi_cc_reset_acm_rsp_struct*) local_param;
    sim_id = mmi_frm_l4c_mod_to_sim((module_type)mod_id);
    SRV_CLOG_BIT2IDX(sim_id, sim_idx);

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_CCOST_SET_DATA_RSP, 2, sim_id, rsp->result, rsp->cause);

    cntx->rsp_fields[sim_idx] |= SRV_CLOG_CCOST_FIELD_TOTAL;

    if (rsp->result != MMI_TRUE)
    {
        cntx->ret[sim_idx] = SRV_CLOG_RET_FAIL;
    }
    srv_clog_ccost_process(cntx, sim_id);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_cc_set_max_acm_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_param     [?]         
 *  mod_id          [IN]        
 *  ilm             [?]         
 * RETURNS
 *  
 *****************************************************************************/
static U8 srv_clog_ccost_cc_set_max_acm_rsp_hdlr(void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 sim_idx;
    mmi_sim_enum sim_id;
    mmi_cc_set_max_acm_rsp_struct *rsp;
    srv_clog_ccost_cntx_struct *cntx = srv_clog_ccost_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_ASSERT(cntx && cntx->op_type == SRV_CLOG_CCOST_OP_SET);

    rsp = (mmi_cc_set_max_acm_rsp_struct*) local_param;
    sim_id = mmi_frm_l4c_mod_to_sim((module_type)mod_id);
    SRV_CLOG_BIT2IDX(sim_id, sim_idx);

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_CCOST_SET_DATA_RSP, 3, sim_id, rsp->result, rsp->cause);

    cntx->rsp_fields[sim_idx] |= SRV_CLOG_CCOST_FIELD_MAX;

    if (rsp->result != MMI_TRUE)
    {
        cntx->ret[sim_idx] = SRV_CLOG_RET_FAIL;
    }
    srv_clog_ccost_process(cntx, sim_id);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_smu_set_puc_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_param     [?]         
 *  mod_id          [IN]        
 *  ilm             [?]         
 * RETURNS
 *  
 *****************************************************************************/
static U8 srv_clog_ccost_smu_set_puc_rsp_hdlr(void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 sim_idx;
    mmi_sim_enum sim_id;
    mmi_smu_set_puc_rsp_struct *rsp;
    srv_clog_ccost_cntx_struct *cntx = srv_clog_ccost_get_cntx();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_ASSERT(cntx && cntx->op_type == SRV_CLOG_CCOST_OP_SET);

    rsp = (mmi_smu_set_puc_rsp_struct*) local_param;
    sim_id = mmi_frm_l4c_mod_to_sim((module_type)mod_id);
    SRV_CLOG_BIT2IDX(sim_id, sim_idx);

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_CCOST_SET_DATA_RSP, 4, sim_id, rsp->result, rsp->cause);

    cntx->rsp_fields[sim_idx] |= SRV_CLOG_CCOST_FIELD_PUC;

    if (rsp->result != MMI_TRUE)
    {
        cntx->ret[sim_idx] = SRV_CLOG_RET_FAIL;
    }
    srv_clog_ccost_process(cntx, sim_id);
    return 0;

}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_process
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static S32 srv_clog_ccost_process(srv_clog_ccost_cntx_struct *cntx, mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 sim_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if need to wait next response */
    SRV_CLOG_ASSERT(SRV_CLOG_CHECK_BIT(cntx->sim_id, sim_id));
    SRV_CLOG_BIT2IDX(sim_id, sim_idx);

    if (!SRV_CLOG_CHECK_BIT_GRP(cntx->req_fields, cntx->rsp_fields[sim_idx], cntx->req_fields))
        return SRV_CLOG_RET_WAITING;

    return srv_clog_ccost_cb_result(cntx, sim_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_cb_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 *  sim_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_ccost_cb_result(srv_clog_ccost_cntx_struct *cntx, mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    MMI_BOOL more = MMI_FALSE;
    U32 sim_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_BIT2IDX(sim_id, sim_idx);
    if (cntx->op_type == SRV_CLOG_CCOST_OP_GET)
    {
        SRV_CLOG_SET_BIT(cntx->rsp_sim_id, sim_id);
        if (cntx->rsp_sim_id != cntx->sim_id)
            more = MMI_TRUE;

        ret = (cntx->get_cb) (cntx->user_data, sim_id, cntx->rsp_fields[sim_idx], &cntx->data[sim_idx], more, cntx->ret[sim_idx]);
        if (more == MMI_TRUE && ret != SRV_CLOG_RET_STOP)
        {
            return SRV_CLOG_RET_CONTINUE;
        }
    }
    else
    {
        ret = (cntx->set_cb) (cntx->user_data, sim_id, cntx->req_fields, cntx->ret[sim_idx]);
    }
    srv_clog_ccost_free_cntx();
    return SRV_CLOG_RET_OK;
}

#define SRV_CLOG_CCOST_MISC


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_currency_ps2mmi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ps_cur      [IN]        
 *  mmi_cur     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_ccost_currency_ps2mmi(const CHAR *ps_cur, WCHAR *mmi_cur)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    CHAR asc_cur[SRV_CLOG_CCOST_MAX_CURRENCY_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(asc_cur, 0, SRV_CLOG_CCOST_MAX_CURRENCY_LEN + 1);

    for (i = 0; i < SRV_CLOG_CCOST_MAX_PS_CURRENCY_SIZE && ps_cur[i] != SRV_CLOG_CCOST_INVALID_CURRENCY_CHAR; i++)
    {
        asc_cur[i] = ps_cur[i];
    }

    mmi_asc_to_ucs2((CHAR*) mmi_cur, (CHAR*) asc_cur);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_currency_mmi2ps
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_cur     [IN]        
 *  ps_cur      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_ccost_currency_mmi2ps(const WCHAR *mmi_cur, CHAR *ps_cur)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcs_n_to_asc(ps_cur, (WCHAR*) mmi_cur, SRV_CLOG_CCOST_MAX_PS_CURRENCY_SIZE * ENCODING_LENGTH);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_ppu_ps2mmi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ps_ppu      [IN]        
 *  mmi_ppu     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_ccost_ppu_ps2mmi(const CHAR *ps_ppu, WCHAR *mmi_ppu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 j = 0;
    U32 len;
    CHAR asc_ppu[SRV_CLOG_CCOST_MAX_PPU_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(asc_ppu, 0, SRV_CLOG_CCOST_MAX_PPU_LEN + 1);

    /*
     * PPU is a number string without dot, it has 18 chars, 
     * the first 11 char is integer, and th next 7 chars is decimal, zero is filled if no not char is used,
     * such as transfer number $19.26 to PPU is "190 0000 0000  260 0000", no dot char in it.
     * To parse it, need to remove the zero pending chars and add dot char.
     */
    for (i = 0; i < SRV_CLOG_CCOST_MAX_PS_PPU_SIZE; i++)
    {
        if (i < SRV_CLOG_CCOST_PS_PPU_INT_SIZE - 1)
        {
            if (j != 0 || ps_ppu[i] != '0')
            {
                asc_ppu[j++] = ps_ppu[i];
            }
        }
        else if (i == SRV_CLOG_CCOST_PS_PPU_INT_SIZE - 1)
        {
            asc_ppu[j++] = ps_ppu[i];
            asc_ppu[j++] = '.'; /* add dot to float value */
        }
        else
        {
            asc_ppu[j++] = ps_ppu[i];
        }
    }

    len = strlen(asc_ppu);
    for (i = len - 1; asc_ppu[i] != '.'; i--)
    {
        if (asc_ppu[i] == '0')
        {
            asc_ppu[i] = 0; /* remove 0 in decimal, such as remove 19.2000->19.2 */
        }
        else
        {
            break;
        }
    }
    if (asc_ppu[i] == '.')  /* if no decimal, remove the dot, such as 19.000 -> 19 */
    {
        asc_ppu[i] = 0;
    }
    mmi_asc_to_ucs2((CHAR*) mmi_ppu, asc_ppu);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_ppu_mmi2pi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_ppu     [IN]        
 *  ps_ppu      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_ccost_ppu_mmi2pi(const WCHAR *mmi_ppu, CHAR *ps_ppu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 num = 0;
    U32 count = 0;
    CHAR asc_ppu[SRV_CLOG_CCOST_MAX_PPU_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcs_n_to_asc(asc_ppu, (WCHAR*) mmi_ppu, SRV_CLOG_CCOST_MAX_PPU_LEN * ENCODING_LENGTH);

    memset(ps_ppu, '0', SRV_CLOG_CCOST_MAX_PS_PPU_SIZE);

    while (count < (SRV_CLOG_CCOST_MAX_PPU_LEN + 1) && asc_ppu[count] != 0)
    {
        if (asc_ppu[count] <= '9' && asc_ppu[count] >= '0')
        {
            num++;
        }
        if (asc_ppu[count++] == '.')
        {
            break;
        }
    }
    /* overflow */
    if ((count > 11 && num > SRV_CLOG_CCOST_PS_PPU_INT_SIZE) || count == 0)
    {
        return;
    }

    if (count == num)   /* integer only */
    {
        for (i = 0; i < count; i++)
        {
            ps_ppu[SRV_CLOG_CCOST_PS_PPU_INT_SIZE - 1 - i] = asc_ppu[count - i - 1];
        }
        return;
    }

    /* save integer part */
    for (i = 0; i < count - 1; i++)
    {
        ps_ppu[SRV_CLOG_CCOST_PS_PPU_INT_SIZE - 1 - i] = asc_ppu[count - i - 2];        /* count includes dot */
    }

    /* with decimal point */
    i = 0;
    while (asc_ppu[count + i] != 0)
    {
        ps_ppu[SRV_CLOG_CCOST_PS_PPU_INT_SIZE + i] = asc_ppu[count + i];
        i++;
        if (i == (SRV_CLOG_CCOST_MAX_PS_PPU_SIZE - SRV_CLOG_CCOST_PS_PPU_INT_SIZE))
            break;
    }
}

#endif /* __MMI_CLOG_CALL_COST__ */

