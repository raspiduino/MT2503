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
*  CallLogSrvGprsCount.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  GPRS Counter support  
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

#ifdef __MMI_CLOG_GPRS_COUNT__

/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "mmi_include.h"

#include "kal_general_types.h"
#include "kal_trace.h"

#include "MMIDataType.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_utility_gprot.h"

#include "CnmgrSrvGprot.h"

#include "CallLogSrvGprot.h"
#include "CallLogSrvIprot.h"
#include "CallLogSrvConfig.h"
#include "CallLogSrvUtils.h"
#include "CallLogSrvProt.h"


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
typedef enum
{
    SRV_CLOG_GPRS_OP_GET,
    SRV_CLOG_GPRS_OP_RESET,
    SRV_CLOG_GPRS_OP_MAX_ITEM
} srv_clog_gprs_op_enum;

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/
typedef struct
{
    srv_clog_gprs_op_enum op_type;
    mmi_sim_enum req_sim_id;
    U8 cur_sim_idx;
    U16 req_fields;
    U16 rsp_sim_id;
    const void *user_data;
    SRV_CLOG_GPRS_GET_DATA_CB get_cb;
    SRV_CLOG_GPRS_RESET_DATA_CB reset_cb;
} srv_clog_gprs_cntx_struct;

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/
static srv_clog_gprs_cntx_struct *srv_clog_gprs_cntx_p;


/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/
static srv_clog_gprs_cntx_struct* srv_clog_gprs_new_cntx(void);
static void srv_clog_gprs_free_cntx(void);
static srv_clog_gprs_cntx_struct * srv_clog_gprs_get_cntx(void);
static void srv_clog_gprs_set_cntx(srv_clog_gprs_cntx_struct *cntx,
        srv_clog_gprs_op_enum op_type,
        mmi_sim_enum req_sim_id,
        U16 req_fields,
        const void *user_data,
        SRV_CLOG_GPRS_GET_DATA_CB get_func_cb,
		SRV_CLOG_GPRS_RESET_DATA_CB reset_func_cb);


static void srv_clog_gprs_cnmgr_get_result(srv_cnmgr_connect_data_rsp_struct *connect_data, void *user_data);

static void srv_clog_gprs_parse_cnmgr_data(
                    srv_clog_gprs_data_struct *clog_data,
                    srv_cnmgr_connect_data_rsp_struct *connect_data);

static void srv_clog_gprs_cnmgr_reset_result(srv_cnmgr_reset_data_req_struct *reset_req, srv_cnmgr_result_enum result, void *user_data);


/*----------------------------------------------------------------------------*/
/* Extern Function Defines                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/

#define SRV_CLOG_GPRS_CNTX

/*****************************************************************************
 * FUNCTION
 *  srv_clog_gprs_new_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_info        [IN]        
 *  bearer_type     [IN]        
 *  data            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static srv_clog_gprs_cntx_struct* srv_clog_gprs_new_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_gprs_cntx_p = SRV_CLOG_TALLOC(SRV_CLOG_MEM_TYPE_TEMP, srv_clog_gprs_cntx_struct);
    return srv_clog_gprs_cntx_p;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_gprs_get_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_info        [IN]        
 *  bearer_type     [IN]        
 *  data            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_gprs_free_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_ZFREE(SRV_CLOG_MEM_TYPE_TEMP, srv_clog_gprs_cntx_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_gprs_get_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_info        [IN]        
 *  bearer_type     [IN]        
 *  data            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static srv_clog_gprs_cntx_struct * srv_clog_gprs_get_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_clog_gprs_cntx_p;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_gprs_get_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_info        [IN]        
 *  bearer_type     [IN]        
 *  data            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_gprs_set_cntx(srv_clog_gprs_cntx_struct *cntx,
        srv_clog_gprs_op_enum op_type,
        mmi_sim_enum req_sim_id,
        U16 req_fields,
        const void *user_data,
        SRV_CLOG_GPRS_GET_DATA_CB get_func_cb, SRV_CLOG_GPRS_RESET_DATA_CB reset_func_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->op_type = op_type;

    cntx->req_sim_id = req_sim_id;
    if (!cntx->req_sim_id)  /* for non-dual sim project */
        cntx->req_sim_id = MMI_SIM1;
    cntx->cur_sim_idx = 0;
    
    cntx->req_fields = req_fields;
    if (!cntx->req_fields)
        cntx->req_fields = SRV_CLOG_GPRS_FIELD_ALL;

    cntx->rsp_sim_id = MMI_SIM_NONE;
    cntx->user_data = user_data;
    cntx->get_cb = get_func_cb;
    cntx->reset_cb = reset_func_cb;
}



#define SRV_CLOG_GPRS_DATA_OP

/*****************************************************************************
 * FUNCTION
 *  srv_clog_gprs_get_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_data        [IN]        
 *  user_data       [IN]        
 *  func_cb         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_gprs_get_data(
        const srv_clog_gprs_get_req_struct *req_data,
        const void *user_data,
        SRV_CLOG_GPRS_GET_DATA_CB func_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    mmi_sim_enum cur_sim_id;
    srv_clog_gprs_cntx_struct *cntx = srv_clog_gprs_get_cntx();

    srv_cnmgr_result_enum ret;
    srv_cnmgr_connect_data_query_struct cnmgr_query;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!req_data || !SRV_CLOG_CHECK_BIT(MMI_SIM_ALL, req_data->sim_id) || !func_cb)
        return SRV_CLOG_RET_INVALID_PARAM;

    /* User may press key very quickly before service receive CBM callback */
    if (cntx)
        return SRV_CLOG_RET_NOT_AVAILABLE;

    cntx = srv_clog_gprs_new_cntx();

    srv_clog_gprs_set_cntx(cntx, SRV_CLOG_GPRS_OP_GET, req_data->sim_id, 0, user_data, func_cb, NULL);

    /* To get data from every SIM */
    for (i = 0; i < SRV_CLOG_SIM_IDX_MAX_ITEM; i++)
    {
        cur_sim_id = (mmi_sim_enum)SRV_CLOG_IDX2BIT(i);
        if (SRV_CLOG_CHECK_BIT(cntx->req_sim_id, cur_sim_id))
        {
            cntx->cur_sim_idx = i;

            cnmgr_query.sim_id = cur_sim_id;
            cnmgr_query.bearer_type = SRV_CNMGR_BEARER_TYPE_GPRS;
            ret = srv_cnmgr_get_connection_data(&cnmgr_query, srv_clog_gprs_cnmgr_get_result, cntx);
            if (ret != SRV_CNMGR_RESULT_SUCCESS && ret != SRV_CNMGR_RESULT_WAIT_FOR_RSP)
            {
                srv_clog_gprs_free_cntx();
                return SRV_CLOG_RET_FAIL;
            }

            return SRV_CLOG_RET_OK;
        }
    }
    return SRV_CLOG_RET_OK;

}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_gprs_reset_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_data        [IN]        
 *  user_data       [IN]        
 *  func_cb         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_gprs_reset_data(
        const srv_clog_gprs_reset_req_struct *req_data,
        const void *user_data,
        SRV_CLOG_GPRS_RESET_DATA_CB func_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    mmi_sim_enum cur_sim_id;
    srv_clog_gprs_cntx_struct *cntx = srv_clog_gprs_get_cntx();

    srv_cnmgr_result_enum ret;
    srv_cnmgr_reset_data_req_struct cnmgr_reset_data;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!req_data || !func_cb)
        return SRV_CLOG_RET_INVALID_PARAM;

    if (!SRV_CLOG_CHECK_BIT(MMI_SIM_ALL, req_data->sim_id) ||
        req_data->fields && !SRV_CLOG_CHECK_BIT(SRV_CLOG_GPRS_FIELD_ALL, req_data->fields))
        return SRV_CLOG_RET_INVALID_PARAM;

    if (cntx)
        return SRV_CLOG_RET_NOT_AVAILABLE;

    cntx = srv_clog_gprs_new_cntx();

    srv_clog_gprs_set_cntx(cntx, SRV_CLOG_GPRS_OP_RESET, req_data->sim_id,
        req_data->fields, user_data, NULL, func_cb);

    for (i = 0; i < SRV_CLOG_SIM_IDX_MAX_ITEM; i++)
    {
        cur_sim_id = (mmi_sim_enum)SRV_CLOG_IDX2BIT(i);
        if (SRV_CLOG_CHECK_BIT(cntx->req_sim_id, cur_sim_id))
        {
            cntx->cur_sim_idx = i;
            
            cnmgr_reset_data.sim_id = cur_sim_id;
            cnmgr_reset_data.bearer_type = SRV_CNMGR_BEARER_TYPE_GPRS;
            cnmgr_reset_data.connect_type = SRV_CNMGR_CONNECT_TYPE_TOTAL;
            cnmgr_reset_data.data_type = SRV_CNMGR_CONNECT_DATA_ALL_DATA;

            ret = srv_cnmgr_reset_connection_data(&cnmgr_reset_data, srv_clog_gprs_cnmgr_reset_result, cntx);
            if (ret != SRV_CNMGR_RESULT_SUCCESS && ret != SRV_CNMGR_RESULT_WAIT_FOR_RSP)
            {
                srv_clog_gprs_free_cntx();
                return SRV_CLOG_RET_FAIL;
            }
            
            return SRV_CLOG_RET_OK;
        }
        
    }
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_gprs_cnmgr_get_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_info        [IN]        
 *  bearer_type     [IN]        
 *  data            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_gprs_cnmgr_get_result(srv_cnmgr_connect_data_rsp_struct *connect_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S32 ret;
    MMI_BOOL more = MMI_FALSE;
    srv_clog_gprs_data_struct clog_data;
    srv_clog_gprs_get_req_struct req_data;
    srv_clog_gprs_cntx_struct *cntx;
    srv_cnmgr_result_enum nmgr_ret;
    srv_cnmgr_connect_data_query_struct cnmgr_query;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = srv_clog_gprs_get_cntx();

    /* check if more SIM to handle, just start from next SIM index  */
    for(i = cntx->cur_sim_idx + 1; i < SRV_CLOG_SIM_IDX_MAX_ITEM; i++)
    {
        if (SRV_CLOG_CHECK_BIT(cntx->req_sim_id, SRV_CLOG_IDX2BIT(i)))
        {
            more = MMI_TRUE;
            cntx->cur_sim_idx = i; /* Set to nex sim_idx */
            break;
        }
    }

    /* Handle current CBM data */
    srv_clog_gprs_parse_cnmgr_data(&clog_data, connect_data);
    req_data.sim_id = connect_data->query.sim_id;

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_GPRS_GET_RESULT,
        req_data.sim_id,
        clog_data.last_recved,
        clog_data.last_sent,
        clog_data.total_recved,
        clog_data.total_sent);

    ret = (cntx->get_cb) ((void*)cntx->user_data,
                          &req_data, (const srv_clog_gprs_data_struct*)&clog_data, more,
                          SRV_CLOG_RET_OK);

    if (ret == SRV_CLOG_RET_STOP)
    {
        srv_clog_gprs_free_cntx();
        return;
    }

    if (more)
    {
        cnmgr_query.sim_id = (mmi_sim_enum)SRV_CLOG_IDX2BIT(cntx->cur_sim_idx);
        cnmgr_query.bearer_type = SRV_CNMGR_BEARER_TYPE_GPRS;
        nmgr_ret = srv_cnmgr_get_connection_data(&cnmgr_query, srv_clog_gprs_cnmgr_get_result, cntx);
        if (nmgr_ret != SRV_CNMGR_RESULT_SUCCESS && nmgr_ret != SRV_CNMGR_RESULT_WAIT_FOR_RSP)
            srv_clog_gprs_free_cntx();
        return;
    }

    srv_clog_gprs_free_cntx();

}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_gprs_parse_cnmgr_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  clog_data       [?]         
 *  connect_data        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_gprs_parse_cnmgr_data(
                srv_clog_gprs_data_struct *clog_data,
                srv_cnmgr_connect_data_rsp_struct *connect_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_cnmgr_connect_data_detail_struct * detail;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(clog_data, 0x0, sizeof(srv_clog_gprs_data_struct));

    /* Local data + Dial-up data */
    for (i = 0; i < SRV_CNMGR_CONNECT_TYPE_TOTAL; i++)
    {
        detail = &connect_data->data[i];
        
        clog_data->last_sent += detail->last_sent_size;
        clog_data->last_recved += detail->last_recv_size;
        clog_data->last_time += detail->last_connect_duration;

        clog_data->total_sent += detail->total_sent_size;
        clog_data->total_recved += detail->total_recv_size;
        clog_data->total_time += detail->total_connect_duration;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_gprs_cnmgr_reset_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_gprs_cnmgr_reset_result(srv_cnmgr_reset_data_req_struct *reset_req, srv_cnmgr_result_enum result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 i;
    MMI_BOOL more = MMI_FALSE;
    srv_clog_ret_enum cb_ret;
    srv_clog_gprs_reset_req_struct req_data;
    srv_clog_gprs_cntx_struct *cntx = srv_clog_gprs_get_cntx();
    srv_cnmgr_result_enum nmgr_ret;
    srv_cnmgr_reset_data_req_struct cnmgr_reset_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_data.sim_id = (mmi_sim_enum)SRV_CLOG_IDX2BIT(cntx->cur_sim_idx);

    if (result == SRV_CNMGR_RESULT_SUCCESS)
    {
        req_data.fields = cntx->req_fields;
        cb_ret = SRV_CLOG_RET_OK;
    }
    else
    {
        req_data.fields = 0;
        cb_ret = SRV_CLOG_RET_FAIL;
    }        

    for (i = cntx->cur_sim_idx + 1; i < SRV_CLOG_SIM_IDX_MAX_ITEM; i++)
    {
        if (SRV_CLOG_CHECK_BIT(cntx->req_sim_id, SRV_CLOG_IDX2BIT(i)))
        {
            more = MMI_TRUE;
            cntx->cur_sim_idx = i; /* point to next SIM idx */
            break;
        }
    }

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_GPRS_RESET_RESULT, more, req_data.sim_id, result);

    ret = (cntx->reset_cb) ((void*)cntx->user_data, &req_data, more, cb_ret);

    if (ret == SRV_CLOG_RET_STOP)
    {
        srv_clog_gprs_free_cntx();
        return;
    }
    if (more)
    {
        cnmgr_reset_data.sim_id = (mmi_sim_enum)SRV_CLOG_IDX2BIT(cntx->cur_sim_idx);
        cnmgr_reset_data.bearer_type = SRV_CNMGR_BEARER_TYPE_GPRS;
        cnmgr_reset_data.connect_type = SRV_CNMGR_CONNECT_TYPE_TOTAL;
        cnmgr_reset_data.data_type = SRV_CNMGR_CONNECT_DATA_ALL_DATA;
        
        nmgr_ret = srv_cnmgr_reset_connection_data(&cnmgr_reset_data, srv_clog_gprs_cnmgr_reset_result, cntx);
        if (nmgr_ret != SRV_CNMGR_RESULT_SUCCESS && nmgr_ret != SRV_CNMGR_RESULT_WAIT_FOR_RSP)
            srv_clog_gprs_free_cntx();
        return;
    }
    srv_clog_gprs_free_cntx();
}


#endif /* __MMI_CLOG_GPRS_COUNT__ */ 




