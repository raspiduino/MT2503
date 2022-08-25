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
*  CallLogAdpOp11.c
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
*  
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
 * removed!
 * removed!
 *
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
#include "MMI_include.h"
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "AlertScreen.h"
#include "string.h"

#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "MMI_common_app_trc.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "CommonScreensResDef.h"
#include "UcmSrvGprot.h"
#include "PhbSrvGprot.h"
#include "UcSrvGprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_utility_gprot.h"
#include "Unicodexdcl.h"

#include "UcmGprot.h"
#ifdef __MMI_CM_BLACK_LIST__
#include "CallSetSrvGprot.h"
#include "CallSetGprot.h"
#endif /* __MMI_CM_BLACK_LIST__ */

#ifdef __MMI_UNIFIED_COMPOSER__
#include "UcAppGprot.h"
#endif 
#include "IdleGprot.h"
#include "NWUsabSrvGprot.h"
#include "PhbCuiGprot.h"
#include "DialerCuiGprot.h"
#include "DialerGprot.h"

#ifndef __MMI_UNIFIED_COMPOSER__
#include "SmsAppGprot.h"
#ifdef __MMI_MMS__
#include "mms_api.h"
#endif 
#endif /* __MMI_UNIFIED_COMPOSER__ */ 

#include "CallLogSrvGprot.h"
#include "CallLogSrvIprot.h"
#include "CallLogConfig.h"
#include "CallLogGprot.h"
#include "CallLogProt.h"
#include "CallLogLayout.h"
#include "CallLogAdpProt.h"
#include "CallLogViewer.h"

#ifdef __MMI_TELEPHONY_SUPPORT__

#include "mmi_rp_app_calllog_def.h"

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

#ifdef __MMI_CLOG_SLIM_FOR_MT6261__

typedef void (*MMI_CLOG_ACT_HDLR) (mmi_clog_op_inst_struct *inst);

typedef struct
{
    mmi_clog_op_mid_enum op_mid;
    MMI_CLOG_ACT_HDLR hdlr;
} mmi_clog_act_hdlr_struct;

/*----------------------------------------------------------------------------*/
/* Typedef with Structure                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/
#ifdef __MMI_CLOG_SIM_FILTER__
static void mmi_clog_act_sim_filter(mmi_clog_op_inst_struct *inst);
#endif /*__MMI_CLOG_SIM_FILTER__*/
static MMI_CLOG_ACT_HDLR mmi_clog_act_search_hdlr(mmi_clog_op_mid_enum op_mid);
static void mmi_clog_act_update_read(mmi_clog_op_inst_struct *inst);
static void mmi_clog_act_view(mmi_clog_op_inst_struct *inst);
static void mmi_clog_act_make_call(mmi_clog_op_inst_struct *inst);
static void mmi_clog_act_make_call_result(mmi_ucm_after_make_call_cb_struct *para);
static void *mmi_clog_act_create_phb_udata(srv_clog_log_struct *log);
#ifdef __OP01_FWPBW__
static void mmi_clog_act_make_ip_call(mmi_clog_op_inst_struct *inst);
#endif
#ifdef __MMI_UNIFIED_COMPOSER__
static void mmi_clog_act_send_msg(mmi_clog_op_inst_struct *inst);
#else /* __MMI_UNIFIED_COMPOSER__ */ 
static void mmi_clog_act_send_sms(mmi_clog_op_inst_struct *inst);
#ifdef __MMI_MMS__
static void mmi_clog_act_send_mms(mmi_clog_op_inst_struct *inst);
#endif /* __MMI_MMS__ */ 
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
static void mmi_clog_act_save_to_phb(mmi_clog_op_inst_struct *inst);
#ifdef __MMI_CM_BLACK_LIST__
static void mmi_clog_act_if_add_to_black_list(mmi_clog_op_inst_struct *inst);
static void mmi_clog_act_add_to_black_list(mmi_clog_op_inst_struct *inst);
#ifdef __OP01_3G__
static void mmi_clog_enter_black_list(mmi_clog_op_inst_struct *inst);
#endif
#endif /* __MMI_CM_BLACK_LIST__ */ 
#ifdef __MMI_CLOG_MARK_SEVERAL__
static void mmi_clog_enter_mark_several_list(mmi_clog_op_inst_struct *inst);
#endif /*__MMI_CLOG_MARK_SEVERAL__*/
#ifndef __MMI_CLOG_COMPUND_ACTION_EDIT_BEFORE_CALL__
static void mmi_clog_act_edit_before_call(mmi_clog_op_inst_struct *inst);
static S32 mmi_clog_act_dlr_evt_proc(mmi_event_struct *evt);
#endif  /*__MMI_CLOG_COMPUND_ACTION_EDIT_BEFORE_CALL__*/
static void mmi_clog_act_if_delete(mmi_clog_op_inst_struct *inst);
static void mmi_clog_act_delete(mmi_clog_op_inst_struct *inst);
static S32 mmi_clog_act_delete_result(SRV_CLOG_HANDLE handle, S32 pid, void *req_data, void *cnf_data, MMI_BOOL more, srv_clog_ret_enum ret);
static void mmi_clog_act_handle_srv_error(mmi_clog_op_inst_struct *inst, S32 ret);
#if (defined(__MMI_CLOG_ACCESSORIES__) && defined(__MMI_CLOG_TAB_SUPPORT__))
static void mmi_clog_act_show_advance_items(mmi_clog_op_inst_struct *inst);
#endif

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/
static const mmi_clog_act_hdlr_struct g_mmi_clog_act_hdlr_tbl[] = 
{
    {MMI_CLOG_OP_MID_VIEW, mmi_clog_act_view},
    {MMI_CLOG_OP_MID_MAKE_CALL, mmi_clog_act_make_call},

#ifdef __MMI_UNIFIED_COMPOSER__
    {MMI_CLOG_OP_MID_SEND_MSG, mmi_clog_act_send_msg},
#else /* __MMI_UNIFIED_COMPOSER__ */ 
    {MMI_CLOG_OP_MID_SEND_SMS, mmi_clog_act_send_sms},
#ifdef __MMI_MMS__
    {MMI_CLOG_OP_MID_SEND_MMS, mmi_clog_act_send_mms},
#endif 
#endif /* __MMI_UNIFIED_COMPOSER__ */ 

    {MMI_CLOG_OP_MID_SAVE_TO_PHB, mmi_clog_act_save_to_phb},
#ifdef __MMI_CM_BLACK_LIST__
    {MMI_CLOG_OP_MID_ADD_TO_BLACK_LIST, mmi_clog_act_if_add_to_black_list},
#ifdef __OP01_3G__
    {MMI_CLOG_OP_MID_ENTER_BLACK_LIST, mmi_clog_enter_black_list},
#endif 
#endif /* __MMI_CM_BLACK_LIST__ */

#ifdef __OP01_FWPBW__
    {MMI_CLOG_OP_MID_MAKE_IP_CALL, mmi_clog_act_make_ip_call},
#endif
#ifndef __MMI_CLOG_COMPUND_ACTION_EDIT_BEFORE_CALL__
    {MMI_CLOG_OP_MID_EDIT_BEFORE_CALL, mmi_clog_act_edit_before_call},
#endif /*__MMI_CLOG_COMPUND_ACTION_EDIT_BEFORE_CALL__*/
    {MMI_CLOG_OP_MID_DELETE, mmi_clog_act_if_delete},

    {MMI_CLOG_OP_MID_DELETE_ALL, mmi_clog_act_if_delete},

#ifdef __MMI_CLOG_MARK_SEVERAL__
    {MMI_CLOG_OP_MID_MARK_SEVERAL, mmi_clog_enter_mark_several_list},
#endif

#if (defined(__MMI_CLOG_ACCESSORIES__) && defined(__MMI_CLOG_TAB_SUPPORT__))
    {MMI_CLOG_OP_MID_ADVANCED, mmi_clog_act_show_advance_items},
#endif 

    /*For CMCC SIM filter*/
#ifdef __MMI_CLOG_SIM_FILTER__
    {MMI_CLOG_OP_MID_SEL_SIM_1,      mmi_clog_act_sim_filter},
#ifdef __MMI_DUAL_SIM__
/* under construction !*/
#endif
#if (MMI_MAX_SIM_NUM >= 3)
    {MMI_CLOG_OP_MID_SEL_SIM_3,      mmi_clog_act_sim_filter},
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    {MMI_CLOG_OP_MID_SEL_SIM_4,      mmi_clog_act_sim_filter},
#endif
    {MMI_CLOG_OP_MID_SEL_SIM_ALL,    mmi_clog_act_sim_filter},
#endif /*__MMI_CLOG_SIM_FILTER__*/
};

MMI_ID g_clog_sim_support = MMI_SIM_ALL;  /* For CMCC SIM filter */


/*----------------------------------------------------------------------------*/
/* Extern Function Defines                                                    */
/*----------------------------------------------------------------------------*/
extern mmi_clog_op_cntx_struct *mmi_clog_op_get_cntx(void);
extern mmi_clog_op_inst_struct *mmi_clog_op_get_inst_by_opmid(U8 op_mid);

/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/
#define MMI_CLOG_FUNC_DEFINITION
#define MMI_CLOG_ACT_INTERFACE
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_init_prop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prop        [IN/OUT]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_RET mmi_clog_act_init_prop(mmi_clog_act_prop_struct *prop)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!prop)
        return MMI_RET_ERR;

    memset(prop, 0x0, sizeof(mmi_clog_act_prop_struct));
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_apply
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_gid      [IN]        
 *  prop            [IN]         
 * RETURNS
 *  
 *****************************************************************************/
MMI_ID mmi_clog_act_apply(MMI_ID parent_gid, mmi_clog_act_prop_struct *prop)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_op_para_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    para.flags = prop->flags;
    para.handle = prop->handle;
    para.log_id = prop->log_id;
    para.sel_lt_id = MMI_CLOG_LT_ID_ALL_CALL;
    para.op_mid = (mmi_clog_op_mid_enum)MMI_CLOG_IDX2BIT(prop->act_type);

    return mmi_clog_op_run(parent_gid, &para);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_run
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_gid      [IN]        
 *  para            [IN]         
 * RETURNS
 *  
 *****************************************************************************/
void mmi_clog_act_run(mmi_clog_op_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_CLOG_ACT_HDLR hdlr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CLOG_TRC_INFO,
            TRC_MMI_CLOG_ACT_PROC,
            inst->parent_gid,
            inst->self_gid,
            inst->sel_lt_id,
            inst->op_mid,
            inst->flags,
            inst->handle,
            inst->log_id);
    
    hdlr = mmi_clog_act_search_hdlr(inst->op_mid);
    if (hdlr)
    {
        (hdlr) (inst);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_evt_alert_yes_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_act_evt_alert_yes_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_op_inst_struct *inst = (mmi_clog_op_inst_struct*) evt->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (inst->op_mid)
    {
    #ifdef __MMI_CM_BLACK_LIST__
        case MMI_CLOG_OP_MID_ADD_TO_BLACK_LIST:
            mmi_clog_act_add_to_black_list(inst);
            break;
    #endif /* __MMI_CM_BLACK_LIST__ */ 

        case MMI_CLOG_OP_MID_DELETE:
        case MMI_CLOG_OP_MID_DELETE_ALL:            
            mmi_clog_act_delete(inst);
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_alt_dismiss
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst            [IN]     
 *  alert_id        [IN]      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_act_alt_dismiss(mmi_clog_op_inst_struct *inst, MMI_ID alert_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (alert_id == inst->sub_gid)
    {
        mmi_alert_dismiss(inst->sub_gid);
        inst->sub_gid = GRP_ID_INVALID;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_evt_phb_save_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
void mmi_clog_act_evt_phb_save_hdlr(mmi_clog_op_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_phb_save_contact_close(inst->sub_gid);
    mmi_frm_group_close(inst->self_gid);
}


#define MMI_CLOG_ACT_PROC
#ifdef __MMI_CLOG_SIM_FILTER__
void mmi_clog_act_sim_filter(mmi_clog_op_inst_struct *inst)
{
    switch (inst->op_mid)
    {
        case MMI_CLOG_OP_MID_SEL_SIM_1:
            g_clog_sim_support = MMI_SIM1;
            break;
    #ifdef __MMI_DUAL_SIM__ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMI_CLOG_OP_MID_SEL_SIM_3:
            g_clog_sim_support = MMI_SIM3;
            break;
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        case MMI_CLOG_OP_MID_SEL_SIM_4:
            g_clog_sim_support = MMI_SIM4;
            break;
    #endif
        case MMI_CLOG_OP_MID_SEL_SIM_ALL:
            g_clog_sim_support = MMI_SIM_ALL;
            break;
    }

    mmi_frm_group_close(inst->self_gid);
}
#endif /*__MMI_CLOG_SIM_FILTER__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_search_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  op_mid      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_CLOG_ACT_HDLR mmi_clog_act_search_hdlr(mmi_clog_op_mid_enum op_mid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < sizeof(g_mmi_clog_act_hdlr_tbl) / sizeof(mmi_clog_act_hdlr_struct); i++)
    {
        if (g_mmi_clog_act_hdlr_tbl[i].op_mid == op_mid)
            return g_mmi_clog_act_hdlr_tbl[i].hdlr;
    }

    return NULL;
}


#define MMI_CLOG_ACT_ACTION
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_update_read
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_update_read(mmi_clog_op_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    srv_clog_update_log_req_struct req_data;
    srv_clog_log_struct log;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_clog_get_log_by_id(inst->handle, inst->log_id, SRV_CLOG_LOG_FIELD_UNREAD_NUM, &log);
    if (ret == SRV_CLOG_RET_OK && log.data.call_log.unread_num == 0)
        return;
    srv_clog_init_para(SRV_CLOG_PARA_UPDATE_LOG_REQ, &req_data);
    req_data.req_fields = SRV_CLOG_LOG_FIELD_UNREAD_NUM;
    req_data.log_data.cate = SRV_CLOG_CATE_CALL;
    req_data.log_data.data.call_log.cate = SRV_CLOG_CATE_CALL;
    req_data.log_data.data.call_log.log_id = inst->log_id;
    req_data.log_data.data.call_log.unread_num = 0;
    srv_clog_update_log(inst->handle, 0, &req_data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_view
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_view(mmi_clog_op_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    S32 ret;
//    U32 merge_style;
    mmi_clog_vr_create_struct create;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    create.handle = inst->handle;
    create.log_id = inst->log_id;
    create.mode = MMI_CLOG_VR_DEF_MODE;
    create.style = MMI_CLOG_VR_DEF_STYLE;

    if (MMI_CLOG_CHECK_BIT(inst->flags, MMI_CLOG_ACT_FLAG_PURE_VIEW))
        create.style |= MMI_CLOG_VR_STYLE_PURE_VIEW;

    //    create.lt_type = inst->lt_type;
#ifdef __MMI_CLOG_TAB_SUPPORT__
    create.lt_type = MMI_CLOG_LT_TYPE_TAB;
#else /*__MMI_CLOG_TAB_SUPPORT__*/
    create.lt_type = MMI_CLOG_LT_TYPE_LIST;
#endif /*__MMI_CLOG_TAB_SUPPORT__*/

    create.sel_lt_id = inst->sel_lt_id;
    create.sup_merge = (MMI_CLOG_STYLE_MERGE == 0 ? MMI_FALSE : MMI_TRUE);
    
/* FlowRevised    
    ret = srv_clog_get_def_style(SRV_CLOG_STYLE_TYPE_MERGE, &merge_style, NULL);
    if (ret == SRV_CLOG_RET_OK && merge_style)
        create.sup_merge = MMI_TRUE;
 */   
    inst->sub_gid = mmi_clog_vr_create_and_run(inst->self_gid, &create);

    if (MMI_CLOG_IS_GID_INVALID(inst->sub_gid))
    {
        MMI_CLOG_ASSERT(MMI_CLOG_IS_GID_INVALID(inst->sub_gid));
        mmi_frm_group_close(inst->self_gid);
        return;
    }
    mmi_clog_act_update_read(inst);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_create_phb_udata
 * DESCRIPTION
 *  
 * PARAMETERS
 *  log        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void * mmi_clog_act_create_phb_udata(srv_clog_log_struct *log)
{
    void *phb_udata = NULL;
    
    if (srv_phb_check_number_id(log->data.call_log.phb_id))
        phb_udata = srv_phb_create_cm_user_data_by_id(log->data.call_log.phb_id);
    else if (log->data.call_log.name[0] != '\0')
        phb_udata = srv_phb_create_cm_user_data(log->data.call_log.name, 0, SRV_PHB_INVALID_INDEX);

    return phb_udata;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_make_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_make_call(mmi_clog_op_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    srv_clog_log_struct log;
    mmi_ucm_make_call_para_struct call_para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_clog_get_log_by_id(inst->handle, inst->log_id, 0, &log);
    if (ret != SRV_CLOG_RET_OK)
    {
        mmi_clog_act_handle_srv_error(inst, ret);
        return;
    }

    if (MMI_CLOG_CHECK_BIT(inst->flags, MMI_CLOG_ACT_FLAG_CALL_BY_SEND_KEY))
        mmi_ucm_init_call_para_for_sendkey(&call_para);
    else
        mmi_ucm_init_call_para(&call_para);
    
    /*Voice call init*/
    call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_ALL;
    
    if (MMI_CLOG_CHECK_BIT(inst->flags, MMI_CLOG_ACT_FLAG_CALL_VOICE_ONLY))
        call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE;
    else if (MMI_CLOG_CHECK_BIT(inst->flags, MMI_CLOG_ACT_FLAG_CALL_VIDEO_ONLY))
        call_para.dial_type = SRV_UCM_VIDEO_CALL_TYPE;
    
    /* Revise it */
    if (log.data.call_log.sub_type == SRV_CLOG_CALL_TYPE_VOIP)
        call_para.dial_type = SRV_UCM_VOIP_CALL_TYPE;
        
    call_para.ucs2_num_uri = log.data.call_log.cid;
    call_para.adv_para.is_ip_dial = (MMI_BOOL)MMI_CLOG_CHECK_BIT(inst->flags, MMI_CLOG_ACT_FLAG_CALL_BY_IP_KEY);
    call_para.adv_para.after_make_call_callback = mmi_clog_act_make_call_result;

    inst->phb_udata = mmi_clog_act_create_phb_udata(&log);
    
    call_para.adv_para.after_callback_user_data = inst;
    call_para.adv_para.phb_data = inst->phb_udata;
    mmi_ucm_call_launch(inst->self_gid, &call_para);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_make_call_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_make_call_result(mmi_ucm_after_make_call_cb_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_op_inst_struct *inst;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inst = (mmi_clog_op_inst_struct*) para->user_data;
    if (!inst)
        return;
    if (inst->phb_udata)
    {
        srv_phb_destory_cm_user_data(inst->phb_udata);
        inst->phb_udata = NULL;
    }
    mmi_frm_group_close(inst->self_gid);
}


#ifdef __OP01_FWPBW__
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_make_ip_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_make_ip_call(mmi_clog_op_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_CLOG_SET_BIT(inst->flags, MMI_CLOG_ACT_FLAG_CALL_BY_IP_KEY);
    mmi_clog_act_make_call(inst);
}
#endif /* __OP01_FWPBW__ */


#ifdef __MMI_UNIFIED_COMPOSER__

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_send_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_send_msg(mmi_clog_op_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    srv_clog_log_struct log;
    mmi_uc_entry_write_struct uc_wr_data = {0};
    mmi_uc_addr_struct uc_addr = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_clog_get_log_by_id(inst->handle, inst->log_id, 0, &log);
    if (ret != SRV_CLOG_RET_OK)
    {
        mmi_clog_act_handle_srv_error(inst, ret);
        return;
    }

    if (log.data.call_log.cid[0] != '\0')
        uc_addr.addr = (kal_uint8*) log.data.call_log.cid;
    else
        uc_addr.addr = (kal_uint8*) log.data.call_log.name;

    uc_addr.type = MMI_UC_ADDRESS_TYPE_PHONE_NUMBER;
    uc_addr.group = MMI_UC_ADDRESS_GROUP_TYPE_TO;

    /* assign data value */
    uc_wr_data.addr = &uc_addr;
    uc_wr_data.addr_num = 1;
    uc_wr_data.msg_type = MMI_UC_MSG_TYPE_DEFAULT;

    mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, &uc_wr_data);
    mmi_frm_group_close(inst->self_gid);
}


#else /* __MMI_UNIFIED_COMPOSER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_send_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_send_sms(mmi_clog_op_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    srv_clog_log_struct log;
    CHAR asi_cid[SRV_CLOG_CID_MAX_LEN + 1];
    mmi_sms_write_msg_para_struct para = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /* SMS will popup error message and close wirte msg group here */
    if (mmi_sms_is_reenter_message())
        return;
    
    ret = srv_clog_get_log_by_id(inst->handle, inst->log_id, 0, &log);
    if (ret != SRV_CLOG_RET_OK)
    {
        mmi_clog_act_handle_srv_error(inst, ret);
        return;
    }

    mmi_ucs2_to_asc(asi_cid, (CHAR*) log.data.call_log.cid);
    para.ascii_addr = (U8*)asi_cid;
    para.flag = MMI_SMS_ENTRY_WRITE_REPLY;
    mmi_sms_write_msg_lanch(inst->self_gid, &para);
    mmi_frm_group_close(inst->self_gid);
}


#ifdef __MMI_MMS__
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_send_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_send_mms(mmi_clog_op_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    srv_clog_log_struct log;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_clog_get_log_by_id(inst->handle, inst->log_id, 0, &log);
    if (ret != SRV_CLOG_RET_OK)
    {
        mmi_clog_act_handle_srv_error(inst, ret);
        return;
    }

    mms_address_insert_hdlr((char*)log.data.call_log.cid);
    mmi_frm_group_close(inst->self_gid);
}
#endif /* __MMI_MMS__ */ 


#endif /* __MMI_UNIFIED_COMPOSER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_save_to_phb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_save_to_phb(mmi_clog_op_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    srv_clog_log_struct log;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_clog_get_log_by_id(inst->handle, inst->log_id, 0, &log);
    if (ret != SRV_CLOG_RET_OK)
    {
        mmi_clog_act_handle_srv_error(inst, ret);
        return;
    }
    inst->sub_gid = cui_phb_save_contact_create(inst->self_gid);
    if (MMI_CLOG_IS_GID_INVALID(inst->sub_gid))
    {
        mmi_clog_act_handle_srv_error(inst, ret);
        return;
    }

    if (log.data.call_log.name[0] != '\0')
    {
        cui_phb_save_contact_set_name(inst->sub_gid, log.data.call_log.name, NULL);
    }
    if (log.data.call_log.sub_type == SRV_CLOG_CALL_TYPE_VOIP)
    {
    #ifdef __MMI_VOIP__
        cui_phb_save_contact_set_voip(inst->sub_gid, log.data.call_log.cid);
    #endif 
    }
    else
        cui_phb_save_contact_set_number(inst->sub_gid, log.data.call_log.cid);
    cui_phb_save_contact_run(inst->sub_gid);
}


#ifdef __MMI_CM_BLACK_LIST__
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_if_add_to_black_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_if_add_to_black_list(mmi_clog_op_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inst->sub_gid = mmi_clog_confirm(
                        CNFM_TYPE_YESNO,
                        STR_ID_CLOG_IF_ADD_TO_BLACK_LIST,
                        MMI_EVENT_QUERY,
                        inst->self_gid,
                        inst,
                        0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_add_to_black_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_add_to_black_list(mmi_clog_op_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 len;
    MMI_STR_ID str_id;
    srv_clog_log_struct log;
    mmi_event_notify_enum event_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_clog_get_log_by_id(inst->handle, inst->log_id, 0, &log);
    if (ret != SRV_CLOG_RET_OK)
    {
        mmi_clog_act_handle_srv_error(inst, ret);
        return;
    }

    len = mmi_wcslen((const WCHAR*)log.data.call_log.cid);
    if (len >= 255)
        len = 255;
    ret = srv_callset_blacklist_add_number((U8) len, (WCHAR*) log.data.call_log.cid, NULL, NULL);
    str_id = srv_callset_get_result_string_id((srv_callset_result_enum) ret);

    if (ret == SRV_CALLSET_RESULT_OK)
        event_id = MMI_EVENT_SUCCESS;
    else
        event_id = MMI_EVENT_FAILURE;

    mmi_clog_popup(str_id, event_id, inst->self_gid, inst);
    mmi_clog_act_alt_dismiss(inst, inst->sub_gid);
}


#ifdef __OP01_3G__
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_black_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_enter_black_list(mmi_clog_op_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_callset_blacklist_launch();

}
#endif /* __OP01_3G__ */
#endif /* __MMI_CM_BLACK_LIST__ */ 


#ifndef __MMI_CLOG_COMPUND_ACTION_EDIT_BEFORE_CALL__
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_edit_before_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_edit_before_call(mmi_clog_op_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    srv_clog_log_struct log;
    cui_dialer_type_enum type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_clog_get_log_by_id(inst->handle, inst->log_id, 0, &log);
    if (ret != SRV_CLOG_RET_OK)
    {
        mmi_clog_act_handle_srv_error(inst, ret);
        return;
    }
    if (log.data.call_log.sub_type == SRV_CLOG_CALL_TYPE_VOIP)
        type = CUI_DIALER_TYPE_VOIP;
    else
        type = CUI_DIALER_TYPE_CLASSIC;
    inst->sub_gid = cui_dialer_create_ex(inst->self_gid, type);
    if (MMI_CLOG_IS_GID_INVALID(inst->sub_gid))
    {
        mmi_clog_popup(STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_FAILURE, inst->parent_gid, inst);
        mmi_frm_group_close(inst->self_gid);
        return;
    }

    cui_dialer_set_dial_string(inst->sub_gid, (const WCHAR*)log.data.call_log.cid);
    cui_dialer_set_launch_style(inst->sub_gid, CUI_DIALER_LAUNCH_TYPE_EDIT_BEFORE_CALL);
    cui_dialer_run(inst->sub_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_dlr_evt_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_act_dlr_evt_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 done = MMI_TRUE;
    mmi_clog_op_inst_struct *inst = (mmi_clog_op_inst_struct*) evt->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_DIALER_CLOSE_REQ:
            cui_dialer_close(((mmi_group_event_struct*) evt)->sender_id);
            inst->sub_gid = GRP_ID_INVALID;
            break;

        case EVT_ID_CUI_DIALER_BEFORE_CALL_LAUNCHED:
            mmi_clog_act_dlr_evt_dialer_before_call_hdlr(evt);
            break;

        case EVT_ID_CUI_DIALER_CLOSED_IND:
            mmi_clog_act_dlr_free_phb_udata(((mmi_group_event_struct*) evt)->sender_id);
            break;

        case EVT_ID_CUI_DIALER_CHANGE_TYPE:
        #if (defined(__MMI_VOIP__) || defined(__MMI_DIALER_SEARCH__))
            mmi_dialer_handle_dialer_change_type(evt);
        #endif /* __MMI_VOIP__ || __MMI_DIALER_SEARCH__ */
            break;

        default:
            done = MMI_FALSE;
            break;
    }
    return done;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_dlr_evt_dialer_before_call_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_act_dlr_evt_dialer_before_call_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    WCHAR *cid;
    void *phb_udata;
    srv_clog_log_struct log;
    mmi_clog_op_inst_struct *inst = (mmi_clog_op_inst_struct*) evt->user_data;
    MMI_ID sender_id = ((mmi_group_event_struct*) evt)->sender_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_clog_get_log_by_id(inst->handle, inst->log_id, 0, &log);
    if (ret == SRV_CLOG_RET_OK)
    {
        cid = (WCHAR*) cui_dialer_get_dial_string(sender_id);
        if (cid)
        {
            ret = srv_phb_compare_number(cid, log.data.call_log.cid);
            if (ret)
            {
                phb_udata = mmi_clog_act_create_phb_udata(&log);
                cui_dialer_set_phb_data(inst->sub_gid, phb_udata);
            }
            return;
        }
    }
    /* log is delete or number is changed, should destroy the PHB user data. */

    MMI_CLOG_IT_TRACE((MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_ACT_DLR_EVT_DIALER_BEFORE_CALL_HDLR, sender_id, inst->log_id, ret));

    mmi_clog_act_dlr_free_phb_udata(sender_id);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_dlr_free_phb_udata
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dlr_gid     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_act_dlr_free_phb_udata(MMI_ID dlr_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data = cui_dialer_get_phb_data(dlr_gid);
    /* Check if already free when user modify the number */
    if (!user_data)
        return;
    srv_phb_destory_cm_user_data(user_data);
    cui_dialer_set_phb_data(dlr_gid, NULL);
}
#endif /*__MMI_CLOG_COMPUND_ACTION_EDIT_BEFORE_CALL__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_if_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_if_delete(mmi_clog_op_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inst->sub_gid = mmi_clog_confirm(
                        CNFM_TYPE_YESNO,
                        (inst->op_mid == MMI_CLOG_OP_MID_DELETE) ? STR_GLOBAL_DELETE_ASK : STR_GLOBAL_DELETE_ALL_ASK,
                        MMI_EVENT_QUERY,
                        inst->self_gid,
                        inst,
                        MMI_CLOG_ALERT_FLAG_AUTO_DISMISS );//| MMI_CLOG_ALERT_FLAG_HIDE_CSK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_delete(mmi_clog_op_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_clog_lt_id_attr_struct *attr;
    srv_clog_del_all_logs_req_struct req_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_display_dummy_screen();

    if (inst->op_mid == MMI_CLOG_OP_MID_DELETE)
    {
        inst->pid = srv_clog_delete_log_by_id(inst->handle, 0, inst->log_id, mmi_clog_act_delete_result);
    }
    else if (inst->op_mid == MMI_CLOG_OP_MID_DELETE_ALL)
    {
        attr = mmi_clog_get_attr_by_lt_id(inst->sel_lt_id);
        memcpy((srv_clog_log_identity_struct*) & req_data, &attr->idt, sizeof(srv_clog_log_identity_struct));
        inst->pid = srv_clog_delete_all_logs(inst->handle, 0, &req_data, mmi_clog_act_delete_result);
    }
    if (inst->pid < SRV_CLOG_RET_OK)
    {
        mmi_clog_act_handle_srv_error(inst, inst->pid);
        return;
    }
}


#ifdef __MMI_CLOG_FPBW__ 
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_delete_cnf_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *       
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_clog_act_delete_cnf_proc(mmi_event_struct * evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {  
        case EVT_ID_POPUP_QUIT:
            mmi_frm_scrn_close_active_id(); // close dummy screen
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}
#endif /*__MMI_CLOG_FPBW__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_delete_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  pid             [IN]        
 *  req_data        [IN]         
 *  cnf_data        [IN]         
 *  more            [IN]        
 *  ret             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_act_delete_result(
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
    mmi_clog_op_inst_struct *inst;
#ifdef __MMI_CLOG_FPBW__   
    mmi_popup_property_struct property;
#endif /*__MMI_CLOG_FPBW__*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_CLOG_FPBW__ 
    mmi_frm_scrn_close_active_id(); // close dummy screen
#endif /*__MMI_CLOG_FPBW__*/
    inst = mmi_clog_op_get_inst_by_opmid(MMI_CLOG_OP_MID_DELETE|MMI_CLOG_OP_MID_DELETE_ALL);
    if (!inst)
        return SRV_CLOG_RET_OK;
    
    if (ret != SRV_CLOG_RET_OK)
    {
        mmi_clog_popup(STR_GLOBAL_UNFINISHED, MMI_EVENT_FAILURE, inst->self_gid, inst);
    }
#ifdef __MMI_CLOG_FPBW__
    else
    {
        mmi_popup_property_init(&property);
        property.callback = mmi_clog_act_delete_cnf_proc;
        property.parent_id = inst->self_gid;
        property.user_tag = (void*)inst;
        if (GRP_ID_INVALID == mmi_popup_display_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, &property))        
            mmi_frm_scrn_close_active_id(); // close dummy screen
    }
#endif /*__MMI_CLOG_FPBW__*/

    return SRV_CLOG_RET_OK;
}


#ifdef __MMI_CLOG_MARK_SEVERAL__
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_mark_several_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_enter_mark_several_list(mmi_clog_op_inst_struct *act_inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID lt_gid;
    mmi_clog_inst_struct inst; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inst.lt_type = MMI_CLOG_LT_TYPE_LIST;
    inst.handle = act_inst->handle;
    inst.sel_lt_id = act_inst->sel_lt_id;
    inst.self_gid = act_inst->parent_gid;
    lt_gid = mmi_clog_lt_create_and_run(&inst, MMI_CLOG_LT_STYLE_MARK_SEVERAL);
    MMI_CLOG_IT_ASSERT(!MMI_CLOG_IS_GID_INVALID(lt_gid));
}
#endif /* __MMI_CLOG_MARK_SEVERAL__ */


#define MMI_CLOG_ACT_MISC
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_handle_srv_error
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]         
 *  ret         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_handle_srv_error(mmi_clog_op_inst_struct *inst, S32 ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_popup(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE, inst->self_gid, inst);
    if (!MMI_CLOG_IS_GID_INVALID(inst->sub_gid))
    {
        mmi_clog_act_alt_dismiss(inst, inst->sub_gid);
    }
}


#if (defined(__MMI_CLOG_ACCESSORIES__) && defined(__MMI_CLOG_TAB_SUPPORT__))
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_show_advance_items
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_show_advance_items(mmi_clog_op_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_enter_advanced(inst->self_gid);
}
#endif /* __MMI_CLOG_ACCESSORIES__ && __MMI_CLOG_TAB_SUPPORT__ */ 


#ifndef __MMI_CLOG_COMPUND_ACTION_RESPOND_HOOK_KEY__
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_make_call_cbk
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cb_para        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_make_call_cbk(mmi_ucm_after_make_call_cb_struct* cb_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if((cb_para != NULL) && (cb_para->user_data))
        srv_phb_destory_cm_user_data(cb_para->user_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_gpio_hookkey_hdlr
 * DESCRIPTION
 *  respond hook key in earphone, if in idle and no active all, will dial the last calllog
 * PARAMETERS
 *  evt        [IN]     
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_clog_gpio_hookkey_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_idle_is_active() &&
        0 == srv_ucm_query_call_count((srv_ucm_call_state_enum)SRV_UCM_CALL_STATE_ALL, (srv_ucm_call_type_enum)SRV_UCM_CALL_TYPE_ALL, NULL))
    {
        U8 sim_id = MMI_SIM_NONE;
        if (srv_nw_usab_is_usable(MMI_SIM1))
            sim_id |= MMI_SIM1;
    #if (MMI_MAX_SIM_NUM >= 2)
        if (srv_nw_usab_is_usable(MMI_SIM2))
            sim_id |= MMI_SIM2;
    #endif
    #if (MMI_MAX_SIM_NUM >= 3)
        if (srv_nw_usab_is_usable(MMI_SIM3))
            sim_id |= MMI_SIM3;
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        if (srv_nw_usab_is_usable(MMI_SIM4))
            sim_id |= MMI_SIM4;
    #endif

        if (MMI_SIM_NONE != sim_id)
        {
            mmi_ucm_make_call_para_struct call_para;
            void *phb_data;
            S32 ret;
            srv_clog_call_log_struct *log; 
            srv_clog_get_last_log_req_struct req_data;
            srv_clog_get_last_log_cnf_struct cnf_data;
            srv_clog_init_para(SRV_CLOG_PARA_GET_LAST_LOG_CNF, &cnf_data);
            req_data.fields = SRV_CLOG_LOG_FIELD_ALL;
            SRV_CLOG_INIT_IDT(
                (srv_clog_log_identifier_struct*) & req_data,
                SRV_CLOG_CATE_CALL,
                sim_id,
                SRV_CLOG_CLT_DIALED,
                SRV_CLOG_CALL_TYPE_ALL);
            
             ret = srv_clog_get_last_log(0,
                        (const srv_clog_get_last_log_req_struct *) &req_data, &cnf_data);
            if (SRV_CLOG_RET_OK != ret)
                return MMI_RET_ERR; // don't ask other APP to handle this event again
                
            // start to make call
            log = &(cnf_data.log.data.call_log);
            mmi_ucm_init_call_para(&call_para);
            if (MMI_SIM1 == log->sim_id)
                call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE;
        #if (MMI_MAX_SIM_NUM >= 2)
            else if (MMI_SIM2 == log->sim_id)
                call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
        #endif
        #if (MMI_MAX_SIM_NUM >= 3)
            else if (MMI_SIM3 == log->sim_id)
                call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM3;
        #endif
        #if (MMI_MAX_SIM_NUM >= 4)
            else// MMI_SIM4
                call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM4;
        #endif

            call_para.ucs2_num_uri = (U16*)log->cid;
            call_para.adv_para.after_make_call_callback = mmi_clog_make_call_cbk;

            if(srv_phb_check_number_id(log->phb_id))
                phb_data = srv_phb_create_cm_user_data_by_id(log->phb_id);
            else if(log->name[0] != 0) // have name string
                phb_data = srv_phb_create_cm_user_data((U16 *)log->name, 0, SRV_PHB_INVALID_INDEX);
            else
               phb_data = NULL;

            call_para.adv_para.after_callback_user_data = phb_data;
            call_para.adv_para.phb_data = phb_data;
            mmi_ucm_call_launch(GRP_ID_ROOT, &call_para);
        }
        return MMI_RET_ERR; // don't ask other APP to handle this event again
    }          
    return MMI_RET_OK; // ask other APP to handle this event again
} 
#endif /*__MMI_CLOG_COMPUND_ACTION_RESPOND_HOOK_KEY__*/

#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */

typedef struct
{
    MMI_ID parent_gid;
    MMI_ID self_gid;
    MMI_ID sub_gid; /* for phb_cui/dialed/cui... */
    U16 flags;
    SRV_CLOG_HANDLE handle;
    SRV_CLOG_ID log_id;
    mmi_clog_lt_id_enum sel_lt_id;
    mmi_clog_op_mid_enum op_mid;
    void *phb_udata;
    S32 pid;
} mmi_clog_act_inst_struct;

typedef struct
{
    mmi_clog_act_inst_struct inst_list[MMI_CLOG_ACT_INST_MAX_NUM];
} mmi_clog_act_cntx_struct;

typedef void (*MMI_CLOG_ACT_HDLR) (mmi_clog_act_inst_struct *inst);

typedef struct
{
    mmi_clog_op_mid_enum op_mid;
    MMI_CLOG_ACT_HDLR hdlr;
} mmi_clog_act_hdlr_struct;

/*----------------------------------------------------------------------------*/
/* Typedef with Structure                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/
static mmi_clog_act_cntx_struct *mmi_clog_act_cntx_init(void);
static mmi_clog_act_cntx_struct *mmi_clog_act_get_cntx(void);
static mmi_clog_act_inst_struct *mmi_clog_act_alloc_inst(mmi_clog_act_cntx_struct *cntx);
static void mmi_clog_act_destroy_inst(mmi_clog_act_inst_struct *inst);
static void mmi_clog_act_reset_inst(mmi_clog_act_inst_struct *inst);
static mmi_clog_act_inst_struct *mmi_clog_act_get_inst_by_pid(mmi_clog_act_cntx_struct *cntx, S32 pid);
static MMI_CLOG_ACT_HDLR mmi_clog_act_search_hdlr(mmi_clog_op_mid_enum op_mid);
static MMI_RET mmi_clog_act_group_proc(mmi_event_struct *evt);
static S32 mmi_clog_act_grp_evt_proc(mmi_event_struct *evt);
static S32 mmi_clog_act_alert_evt_proc(mmi_event_struct *evt);
static S32 mmi_clog_act_phb_evt_proc(mmi_event_struct *evt);

static void mmi_clog_act_evt_phb_save_hdlr(mmi_clog_act_inst_struct *inst);

static void mmi_clog_act_evt_alert_yes_hdlr(mmi_event_struct *evt);
static void mmi_clog_act_alt_dismiss(mmi_clog_act_inst_struct *inst, MMI_ID alert_id);

static void mmi_clog_act_update_read(mmi_clog_act_inst_struct *inst);

static void mmi_clog_act_view(mmi_clog_act_inst_struct *inst);
static void mmi_clog_act_make_call(mmi_clog_act_inst_struct *inst);
static void mmi_clog_act_make_call_result(mmi_ucm_after_make_call_cb_struct *para);
static void *mmi_clog_act_create_phb_udata(srv_clog_log_struct *log);
#ifdef __OP01_FWPBW__
static void mmi_clog_act_make_ip_call(mmi_clog_act_inst_struct *inst);
#endif


#ifdef __MMI_UNIFIED_COMPOSER__
static void mmi_clog_act_send_msg(mmi_clog_act_inst_struct *inst);
#else /* __MMI_UNIFIED_COMPOSER__ */ 

static void mmi_clog_act_send_sms(mmi_clog_act_inst_struct *inst);

#ifdef __MMI_MMS__

static void mmi_clog_act_send_mms(mmi_clog_act_inst_struct *inst);
#endif /* __MMI_MMS__ */ 

#endif /* __MMI_UNIFIED_COMPOSER__ */ 

static void mmi_clog_act_save_to_phb(mmi_clog_act_inst_struct *inst);

#ifdef __MMI_CM_BLACK_LIST__
static void mmi_clog_act_if_add_to_black_list(mmi_clog_act_inst_struct *inst);
static void mmi_clog_act_add_to_black_list(mmi_clog_act_inst_struct *inst);
#ifdef __OP01_3G__
static void mmi_clog_enter_black_list(mmi_clog_act_inst_struct *inst);
#endif
#endif /* __MMI_CM_BLACK_LIST__ */ 

#ifdef __MMI_CLOG_MARK_SEVERAL__
static void mmi_clog_enter_mark_several_list(mmi_clog_act_inst_struct *inst);
#endif /*__MMI_CLOG_MARK_SEVERAL__*/

#ifndef __MMI_CLOG_COMPUND_ACTION_EDIT_BEFORE_CALL__
static void mmi_clog_act_edit_before_call(mmi_clog_act_inst_struct *inst);
static S32 mmi_clog_act_dlr_evt_proc(mmi_event_struct *evt);
#endif  /*__MMI_CLOG_COMPUND_ACTION_EDIT_BEFORE_CALL__*/

static void mmi_clog_act_if_delete(mmi_clog_act_inst_struct *inst);
static void mmi_clog_act_delete(mmi_clog_act_inst_struct *inst);
static S32 mmi_clog_act_delete_result(
            SRV_CLOG_HANDLE handle,
            S32 pid,
            void *req_data,
            void *cnf_data,
            MMI_BOOL more,
            srv_clog_ret_enum ret);

static void mmi_clog_act_handle_srv_error(mmi_clog_act_inst_struct *inst, S32 ret);

#if (defined(__MMI_CLOG_ACCESSORIES__) && defined(__MMI_CLOG_TAB_SUPPORT__))
static void mmi_clog_act_show_advance_items(mmi_clog_act_inst_struct *inst);
#endif


#ifdef __MMI_CLOG_SIM_FILTER__
static void mmi_clog_act_sim_filter(mmi_clog_act_inst_struct *inst);
#endif /*__MMI_CLOG_SIM_FILTER__*/


/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/

static const mmi_clog_act_hdlr_struct g_mmi_clog_act_hdlr_tbl[] = 
{
    {MMI_CLOG_OP_MID_VIEW, mmi_clog_act_view},
    {MMI_CLOG_OP_MID_MAKE_CALL, mmi_clog_act_make_call},

#ifdef __MMI_UNIFIED_COMPOSER__
    {MMI_CLOG_OP_MID_SEND_MSG, mmi_clog_act_send_msg},
#else /* __MMI_UNIFIED_COMPOSER__ */ 
    {MMI_CLOG_OP_MID_SEND_SMS, mmi_clog_act_send_sms},
#ifdef __MMI_MMS__
    {MMI_CLOG_OP_MID_SEND_MMS, mmi_clog_act_send_mms},
#endif 
#endif /* __MMI_UNIFIED_COMPOSER__ */ 

    {MMI_CLOG_OP_MID_SAVE_TO_PHB, mmi_clog_act_save_to_phb},
#ifdef __MMI_CM_BLACK_LIST__
    {MMI_CLOG_OP_MID_ADD_TO_BLACK_LIST, mmi_clog_act_if_add_to_black_list},
#ifdef __OP01_3G__
    {MMI_CLOG_OP_MID_ENTER_BLACK_LIST, mmi_clog_enter_black_list},
#endif 
#endif /* __MMI_CM_BLACK_LIST__ */

#ifdef __OP01_FWPBW__
    {MMI_CLOG_OP_MID_MAKE_IP_CALL, mmi_clog_act_make_ip_call},
#endif
#ifndef __MMI_CLOG_COMPUND_ACTION_EDIT_BEFORE_CALL__
    {MMI_CLOG_OP_MID_EDIT_BEFORE_CALL, mmi_clog_act_edit_before_call},
#endif /*__MMI_CLOG_COMPUND_ACTION_EDIT_BEFORE_CALL__*/
    {MMI_CLOG_OP_MID_DELETE, mmi_clog_act_if_delete},

    {MMI_CLOG_OP_MID_DELETE_ALL, mmi_clog_act_if_delete},

#ifdef __MMI_CLOG_MARK_SEVERAL__
    {MMI_CLOG_OP_MID_MARK_SEVERAL, mmi_clog_enter_mark_several_list},
#endif

#if (defined(__MMI_CLOG_ACCESSORIES__) && defined(__MMI_CLOG_TAB_SUPPORT__))
    {MMI_CLOG_OP_MID_ADVANCED, mmi_clog_act_show_advance_items},
#endif 

	/*For CMCC SIM filter*/

#ifdef __MMI_CLOG_SIM_FILTER__

	{MMI_CLOG_OP_MID_SEL_SIM_1,      mmi_clog_act_sim_filter},
	
#ifdef __MMI_DUAL_SIM__
/* under construction !*/
#endif

#if (MMI_MAX_SIM_NUM >= 3)
	{MMI_CLOG_OP_MID_SEL_SIM_3,      mmi_clog_act_sim_filter},
#endif

#if (MMI_MAX_SIM_NUM >= 4)
	{MMI_CLOG_OP_MID_SEL_SIM_4,      mmi_clog_act_sim_filter},
#endif

	{MMI_CLOG_OP_MID_SEL_SIM_ALL,    mmi_clog_act_sim_filter},

#endif /*__MMI_CLOG_SIM_FILTER__*/
};

static mmi_clog_act_cntx_struct g_mmi_clog_act_cntx;

MMI_ID g_clog_sim_support = MMI_SIM_ALL;  /* For CMCC SIM filter */


/*----------------------------------------------------------------------------*/
/* Extern Function Defines                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/

#define MMI_CLOG_ACT_INIT

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_cntx_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_clog_act_cntx_struct *mmi_clog_act_cntx_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_CLOG_ACT_INST_MAX_NUM; i++)
    {
        /* Context is already init if any instance is valid */
        if (MMI_CLOG_IS_INST_VALID(&g_mmi_clog_act_cntx.inst_list[i], MMI_CLOG_INST_TYPE_ACT))
            return &g_mmi_clog_act_cntx;
    }
    memset(&g_mmi_clog_act_cntx, 0x0, sizeof(mmi_clog_act_inst_struct));
    return &g_mmi_clog_act_cntx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_alloc_inst
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static mmi_clog_act_inst_struct *mmi_clog_act_alloc_inst(mmi_clog_act_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_CLOG_ACT_INST_MAX_NUM; i++)
    {
        if (!MMI_CLOG_CHECK_BIT(cntx->inst_list[i].flags, MMI_CLOG_CMN_INST_FLAG_IS_USED))
        {
            MMI_CLOG_SET_BIT(cntx->inst_list[i].flags, MMI_CLOG_CMN_INST_FLAG_IS_USED | MMI_CLOG_INST_TYPE_ACT);
            return &cntx->inst_list[i];
        }
    }
    MMI_CLOG_IT_ASSERT(0);
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_get_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_clog_act_cntx_struct *mmi_clog_act_get_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_mmi_clog_act_cntx;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_destroy_inst
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_destroy_inst(mmi_clog_act_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!MMI_CLOG_IS_INST_VALID(inst, MMI_CLOG_INST_TYPE_ACT))
        return;

    MMI_CLOG_IT_TRACE((
        MMI_CLOG_TRC_INFO,
        TRC_MMI_CLOG_ACT_DESTROY_INST,
        inst->parent_gid,
        inst->self_gid,
        inst->sel_lt_id,
        inst->op_mid,
        inst->flags,
        inst->handle,
        inst->log_id));

    mmi_clog_act_reset_inst(inst);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_reset_inst
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_reset_inst(mmi_clog_act_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(inst, 0x0, sizeof(mmi_clog_act_inst_struct));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_get_inst_by_pid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]         
 *  pid         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_clog_act_inst_struct *mmi_clog_act_get_inst_by_pid(mmi_clog_act_cntx_struct *cntx, S32 pid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_CLOG_ACT_INST_MAX_NUM; i++)
    {
        if (!MMI_CLOG_IS_INST_VALID(&g_mmi_clog_act_cntx.inst_list[i], MMI_CLOG_INST_TYPE_ACT))
            continue;
        if (cntx->inst_list[i].pid == pid)
            return &cntx->inst_list[i];
    }
    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_init_prop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prop        [IN/OUT]     
 * RETURNS
 *  
 *****************************************************************************/
extern MMI_RET mmi_clog_act_init_prop(mmi_clog_act_prop_struct *prop)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!prop)
        return MMI_RET_ERR;

    memset(prop, 0x0, sizeof(mmi_clog_act_prop_struct));
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_apply
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_gid      [IN]        
 *  prop            [IN]         
 * RETURNS
 *  
 *****************************************************************************/
extern MMI_ID mmi_clog_act_apply(MMI_ID parent_gid, mmi_clog_act_prop_struct *prop)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_act_para_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    para.handle = prop->handle;
    para.log_id = prop->log_id;
    para.sel_lt_id = MMI_CLOG_LT_ID_ALL_CALL;
    para.op_mid = (mmi_clog_op_mid_enum)MMI_CLOG_IDX2BIT(prop->act_type);
    para.flags = prop->flags;

    return mmi_clog_act_proc(parent_gid, &para);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_init_para
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_act_init_para(mmi_clog_act_para_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(para, 0x0, sizeof(mmi_clog_act_para_struct));
}

#define MMI_CLOG_ACT_PROC

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_gid      [IN]        
 *  para            [IN]         
 * RETURNS
 *  
 *****************************************************************************/
MMI_ID mmi_clog_act_proc(MMI_ID parent_gid, mmi_clog_act_para_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID gid;
    mmi_clog_act_cntx_struct *cntx;
    mmi_clog_act_inst_struct *inst;
    MMI_CLOG_ACT_HDLR hdlr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_CLOG_IS_GID_INVALID(parent_gid) || !para)
        return GRP_ID_INVALID;

    cntx = mmi_clog_act_cntx_init();
    inst = mmi_clog_act_alloc_inst(cntx);
    if (!inst)
        return GRP_ID_INVALID;
    inst->parent_gid = parent_gid;
    inst->handle = para->handle;
    inst->log_id = para->log_id;
    inst->sel_lt_id = para->sel_lt_id;
    inst->op_mid = para->op_mid;
    MMI_CLOG_SET_BIT(inst->flags, para->flags);

    gid = mmi_clog_alloc_gid(MMI_CLOG_GRP_TYPE_ACT);
    inst->self_gid = mmi_frm_group_create_ex(parent_gid, gid, mmi_clog_act_group_proc, inst, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    MMI_TRACE(
        MMI_CLOG_TRC_INFO,
        TRC_MMI_CLOG_ACT_PROC,
        inst->parent_gid,
        inst->self_gid,
        inst->sel_lt_id,
        inst->op_mid,
        inst->flags,
        inst->handle,
        inst->log_id);
    hdlr = mmi_clog_act_search_hdlr(inst->op_mid);
    if (hdlr)
    {
        (hdlr) (inst);
    }
    return inst->self_gid;
}

#ifdef __MMI_CLOG_SIM_FILTER__

static void mmi_clog_act_sim_filter(mmi_clog_act_inst_struct *inst)
{
	switch (inst->op_mid)
	{
		case MMI_CLOG_OP_MID_SEL_SIM_1:
			g_clog_sim_support = MMI_SIM1;
			break;
	#ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	#if (MMI_MAX_SIM_NUM >= 3)
		case MMI_CLOG_OP_MID_SEL_SIM_3:
			g_clog_sim_support = MMI_SIM3;
			break;
	#endif
	#if (MMI_MAX_SIM_NUM >= 4)
		case MMI_CLOG_OP_MID_SEL_SIM_4:
			g_clog_sim_support = MMI_SIM4;
			break;
	#endif
		case MMI_CLOG_OP_MID_SEL_SIM_ALL:
			g_clog_sim_support = MMI_SIM_ALL;
			break;
	}

	mmi_frm_group_close(inst->self_gid);
	
	
}

#endif /*__MMI_CLOG_SIM_FILTER__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_search_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  op_mid      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_CLOG_ACT_HDLR mmi_clog_act_search_hdlr(mmi_clog_op_mid_enum op_mid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < sizeof(g_mmi_clog_act_hdlr_tbl) / sizeof(mmi_clog_act_hdlr_struct); i++)
    {
        if (g_mmi_clog_act_hdlr_tbl[i].op_mid == op_mid)
            return g_mmi_clog_act_hdlr_tbl[i].hdlr;
    }
    return NULL;
}

#define MMI_CLOG_ACT_GRP


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static MMI_RET mmi_clog_act_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 done;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    done = mmi_clog_act_grp_evt_proc(evt);
    if (done)
        return MMI_RET_OK;

    done = mmi_clog_act_phb_evt_proc(evt);
    if (done)
        return MMI_RET_OK;
#ifndef __MMI_CLOG_COMPUND_ACTION_EDIT_BEFORE_CALL__
    done = mmi_clog_act_dlr_evt_proc(evt);
    if (done)
        return MMI_RET_OK;
#endif /*__MMI_CLOG_COMPUND_ACTION_EDIT_BEFORE_CALL__*/
    mmi_clog_act_alert_evt_proc(evt);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_grp_evt_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_act_grp_evt_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 done = MMI_TRUE;
    mmi_clog_act_inst_struct *inst = (mmi_clog_act_inst_struct*) evt->user_data;;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_FIRST_ENTRY:
        case EVT_ID_GROUP_ACTIVE:
        case EVT_ID_GROUP_INACTIVE:
            break;

        case EVT_ID_GROUP_DEINIT:           
            mmi_clog_act_destroy_inst(inst);
            break;

        default:
            done = MMI_FALSE;
            break;
    }
    return done;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_alert_evt_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_act_alert_evt_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 done = MMI_TRUE;
    mmi_clog_act_inst_struct *inst = (mmi_clog_act_inst_struct*) evt->user_data;
    mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*) evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
        {
            switch (alert->result)
            {
                case MMI_ALERT_NORMAL_EXIT:
                case MMI_ALERT_INTERRUPT_EXIT:
                case MMI_ALERT_NO_SHOW:
                case MMI_ALERT_CNFM_NO:
                case MMI_ALERT_CNFM_CANCEL:
                    mmi_clog_act_alt_dismiss(inst, alert->alert_id);
                    break;

                case MMI_ALERT_CNFM_YES:
                    mmi_clog_act_evt_alert_yes_hdlr(evt);
                    break;

                default:
                    break;
            }
        }

        default:
            done = MMI_FALSE;
            break;
    }
    return done;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_evt_alert_yes_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_evt_alert_yes_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_act_inst_struct *inst = (mmi_clog_act_inst_struct*) evt->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (inst->op_mid)
    {
    #ifdef __MMI_CM_BLACK_LIST__
        case MMI_CLOG_OP_MID_ADD_TO_BLACK_LIST:
            mmi_clog_act_add_to_black_list(inst);
            break;
    #endif /* __MMI_CM_BLACK_LIST__ */ 

        case MMI_CLOG_OP_MID_DELETE:
        case MMI_CLOG_OP_MID_DELETE_ALL:            
            mmi_clog_act_delete(inst);
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_alt_dismiss
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst            [IN]     
 *  alert_id        [IN]      
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_alt_dismiss(mmi_clog_act_inst_struct *inst, MMI_ID alert_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (alert_id == inst->sub_gid)
    {
        mmi_alert_dismiss(inst->sub_gid);
        inst->sub_gid = GRP_ID_INVALID;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_phb_evt_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_act_phb_evt_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 done = MMI_TRUE;
    mmi_clog_act_inst_struct *inst = (mmi_clog_act_inst_struct*) evt->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_PHB_SAVE_CONTACT:
        case EVT_ID_PHB_SAVE_CONTACT_CANCEL:
            mmi_clog_act_evt_phb_save_hdlr(inst);
            break;

        default:
            done = MMI_FALSE;
            break;
    }
    return done;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_evt_phb_save_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_clog_act_evt_phb_save_hdlr(mmi_clog_act_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_phb_save_contact_close(inst->sub_gid);
    mmi_frm_group_close(inst->self_gid);
}


#define MMI_CLOG_ACT_ACTION

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_update_read
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_update_read(mmi_clog_act_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    srv_clog_update_log_req_struct req_data;
    srv_clog_log_struct log;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_clog_get_log_by_id(inst->handle, inst->log_id, SRV_CLOG_LOG_FIELD_UNREAD_NUM, &log);
    if (ret == SRV_CLOG_RET_OK && log.data.call_log.unread_num == 0)
        return;
    srv_clog_init_para(SRV_CLOG_PARA_UPDATE_LOG_REQ, &req_data);
    req_data.req_fields = SRV_CLOG_LOG_FIELD_UNREAD_NUM;
    req_data.log_data.cate = SRV_CLOG_CATE_CALL;
    req_data.log_data.data.call_log.cate = SRV_CLOG_CATE_CALL;
    req_data.log_data.data.call_log.log_id = inst->log_id;
    req_data.log_data.data.call_log.unread_num = 0;
    srv_clog_update_log(inst->handle, 0, &req_data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_view
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_view(mmi_clog_act_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    S32 ret;
//    U32 merge_style;
    mmi_clog_vr_create_struct create;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    create.handle = inst->handle;
    create.log_id = inst->log_id;

    create.mode = MMI_CLOG_VR_DEF_MODE;
    create.style = MMI_CLOG_VR_DEF_STYLE;
    if (MMI_CLOG_CHECK_BIT(inst->flags, MMI_CLOG_ACT_FLAG_PURE_VIEW))
        create.style |= MMI_CLOG_VR_STYLE_PURE_VIEW;

    //    create.lt_type = inst->lt_type;
		
	#ifdef __MMI_CLOG_TAB_SUPPORT__
	create.lt_type = MMI_CLOG_LT_TYPE_TAB;
    #else /*__MMI_CLOG_TAB_SUPPORT__*/
    create.lt_type = MMI_CLOG_LT_TYPE_LIST;
	#endif /*__MMI_CLOG_TAB_SUPPORT__*/

    create.sel_lt_id = inst->sel_lt_id;
    create.sup_merge = (MMI_CLOG_STYLE_MERGE == 0 ? MMI_FALSE : MMI_TRUE);
    
/* FlowRevised    
    ret = srv_clog_get_def_style(SRV_CLOG_STYLE_TYPE_MERGE, &merge_style, NULL);
    if (ret == SRV_CLOG_RET_OK && merge_style)
        create.sup_merge = MMI_TRUE;
 */   
	inst->sub_gid = mmi_clog_vr_create_and_run(inst->self_gid, &create);

	if (MMI_CLOG_IS_GID_INVALID(inst->sub_gid))
	{
		MMI_CLOG_ASSERT(MMI_CLOG_IS_GID_INVALID(inst->sub_gid));
		mmi_frm_group_close(inst->self_gid);
		return;
	}
    mmi_clog_act_update_read(inst);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_make_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_make_call(mmi_clog_act_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    srv_clog_log_struct log;
    mmi_ucm_make_call_para_struct call_para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_clog_get_log_by_id(inst->handle, inst->log_id, 0, &log);
    if (ret != SRV_CLOG_RET_OK)
    {
        mmi_clog_act_handle_srv_error(inst, ret);
        return;
    }

    if (MMI_CLOG_CHECK_BIT(inst->flags, MMI_CLOG_ACT_FLAG_CALL_BY_SEND_KEY))
        mmi_ucm_init_call_para_for_sendkey(&call_para);
    else
        mmi_ucm_init_call_para(&call_para);
    
	/*Voice call init*/
    call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_ALL;
    
    if (MMI_CLOG_CHECK_BIT(inst->flags, MMI_CLOG_ACT_FLAG_CALL_VOICE_ONLY))
        call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE;
    else if (MMI_CLOG_CHECK_BIT(inst->flags, MMI_CLOG_ACT_FLAG_CALL_VIDEO_ONLY))
        call_para.dial_type = SRV_UCM_VIDEO_CALL_TYPE;
    
    /* Revise it */
    if (log.data.call_log.sub_type == SRV_CLOG_CALL_TYPE_VOIP)
        call_para.dial_type = SRV_UCM_VOIP_CALL_TYPE;
        
    call_para.ucs2_num_uri = log.data.call_log.cid;
    call_para.adv_para.is_ip_dial = (MMI_BOOL)MMI_CLOG_CHECK_BIT(inst->flags, MMI_CLOG_ACT_FLAG_CALL_BY_IP_KEY);
    call_para.adv_para.after_make_call_callback = mmi_clog_act_make_call_result;

    inst->phb_udata = mmi_clog_act_create_phb_udata(&log);
    
    call_para.adv_para.after_callback_user_data = inst;
    call_para.adv_para.phb_data = inst->phb_udata;
    mmi_ucm_call_launch(inst->self_gid, &call_para);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_create_phb_udata
 * DESCRIPTION
 *  
 * PARAMETERS
 *  log        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void * mmi_clog_act_create_phb_udata(srv_clog_log_struct *log)
{
    void *phb_udata = NULL;
    
    if (srv_phb_check_number_id(log->data.call_log.phb_id))
        phb_udata = srv_phb_create_cm_user_data_by_id(log->data.call_log.phb_id);
    else if (log->data.call_log.name[0] != '\0')
        phb_udata = srv_phb_create_cm_user_data(log->data.call_log.name, 0, SRV_PHB_INVALID_INDEX);

    return phb_udata;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_make_call_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_make_call_result(mmi_ucm_after_make_call_cb_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_act_inst_struct *inst;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inst = (mmi_clog_act_inst_struct*) para->user_data;
    if (!inst)
        return;
    if (inst->phb_udata)
    {
        srv_phb_destory_cm_user_data(inst->phb_udata);
        inst->phb_udata = NULL;
    }
    mmi_frm_group_close(inst->self_gid);
}


#ifdef __OP01_FWPBW__
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_make_ip_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_make_ip_call(mmi_clog_act_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_CLOG_SET_BIT(inst->flags, MMI_CLOG_ACT_FLAG_CALL_BY_IP_KEY);
    mmi_clog_act_make_call(inst);
}
#endif /* __OP01_FWPBW__ */


#ifdef __MMI_UNIFIED_COMPOSER__

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_send_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_send_msg(mmi_clog_act_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    srv_clog_log_struct log;
    mmi_uc_entry_write_struct uc_wr_data = {0};
    mmi_uc_addr_struct uc_addr = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_clog_get_log_by_id(inst->handle, inst->log_id, 0, &log);
    if (ret != SRV_CLOG_RET_OK)
    {
        mmi_clog_act_handle_srv_error(inst, ret);
        return;
    }

    if (log.data.call_log.cid[0] != '\0')
        uc_addr.addr = (kal_uint8*) log.data.call_log.cid;
    else
        uc_addr.addr = (kal_uint8*) log.data.call_log.name;

    uc_addr.type = MMI_UC_ADDRESS_TYPE_PHONE_NUMBER;
    uc_addr.group = MMI_UC_ADDRESS_GROUP_TYPE_TO;

    /* assign data value */
    uc_wr_data.addr = &uc_addr;
    uc_wr_data.addr_num = 1;
    uc_wr_data.msg_type = MMI_UC_MSG_TYPE_DEFAULT;

    mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, &uc_wr_data);
    mmi_frm_group_close(inst->self_gid);
}

#else /* __MMI_UNIFIED_COMPOSER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_send_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_send_sms(mmi_clog_act_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    srv_clog_log_struct log;
    CHAR asi_cid[SRV_CLOG_CID_MAX_LEN + 1];
    mmi_sms_write_msg_para_struct para = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /* SMS will popup error message and close wirte msg group here */
    if (mmi_sms_is_reenter_message())
        return;
    
    ret = srv_clog_get_log_by_id(inst->handle, inst->log_id, 0, &log);
    if (ret != SRV_CLOG_RET_OK)
    {
        mmi_clog_act_handle_srv_error(inst, ret);
        return;
    }

    mmi_ucs2_to_asc(asi_cid, (CHAR*) log.data.call_log.cid);
    para.ascii_addr = (U8*)asi_cid;
    para.flag = MMI_SMS_ENTRY_WRITE_REPLY;
    mmi_sms_write_msg_lanch(inst->self_gid, &para);
    mmi_frm_group_close(inst->self_gid);
}

#ifdef __MMI_MMS__


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_send_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_send_mms(mmi_clog_act_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    srv_clog_log_struct log;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_clog_get_log_by_id(inst->handle, inst->log_id, 0, &log);
    if (ret != SRV_CLOG_RET_OK)
    {
        mmi_clog_act_handle_srv_error(inst, ret);
        return;
    }

    mms_address_insert_hdlr((char*)log.data.call_log.cid);
    mmi_frm_group_close(inst->self_gid);
}

#endif /* __MMI_MMS__ */ 

#endif /* __MMI_UNIFIED_COMPOSER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_save_to_phb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_save_to_phb(mmi_clog_act_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    srv_clog_log_struct log;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_clog_get_log_by_id(inst->handle, inst->log_id, 0, &log);
    if (ret != SRV_CLOG_RET_OK)
    {
        mmi_clog_act_handle_srv_error(inst, ret);
        return;
    }
    inst->sub_gid = cui_phb_save_contact_create(inst->self_gid);
    if (MMI_CLOG_IS_GID_INVALID(inst->sub_gid))
    {
        mmi_clog_act_handle_srv_error(inst, ret);
        return;
    }

    if (log.data.call_log.name[0] != '\0')
    {
        cui_phb_save_contact_set_name(inst->sub_gid, log.data.call_log.name, NULL);
    }
    if (log.data.call_log.sub_type == SRV_CLOG_CALL_TYPE_VOIP)
    {
    #ifdef __MMI_VOIP__
        cui_phb_save_contact_set_voip(inst->sub_gid, log.data.call_log.cid);
    #endif 
    }
    else
        cui_phb_save_contact_set_number(inst->sub_gid, log.data.call_log.cid);
    cui_phb_save_contact_run(inst->sub_gid);
}

#ifdef __MMI_CM_BLACK_LIST__


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_if_add_to_black_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_if_add_to_black_list(mmi_clog_act_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inst->sub_gid = mmi_clog_confirm(
                        CNFM_TYPE_YESNO,
                        STR_ID_CLOG_IF_ADD_TO_BLACK_LIST,
                        MMI_EVENT_QUERY,
                        inst->self_gid,
                        inst,
                        0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_add_to_black_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_add_to_black_list(mmi_clog_act_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 len;
    MMI_STR_ID str_id;
    srv_clog_log_struct log;
    mmi_event_notify_enum event_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_clog_get_log_by_id(inst->handle, inst->log_id, 0, &log);
    if (ret != SRV_CLOG_RET_OK)
    {
        mmi_clog_act_handle_srv_error(inst, ret);
        return;
    }

    len = mmi_wcslen((const WCHAR*)log.data.call_log.cid);
    if (len >= 255)
        len = 255;
    ret = srv_callset_blacklist_add_number((U8) len, (WCHAR*) log.data.call_log.cid, NULL, NULL);
    str_id = srv_callset_get_result_string_id((srv_callset_result_enum) ret);

    if (ret == SRV_CALLSET_RESULT_OK)
        event_id = MMI_EVENT_SUCCESS;
    else
        event_id = MMI_EVENT_FAILURE;

    mmi_clog_popup(str_id, event_id, inst->self_gid, inst);
    mmi_clog_act_alt_dismiss(inst, inst->sub_gid);
}


#ifdef __OP01_3G__
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_black_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_enter_black_list(mmi_clog_act_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_callset_blacklist_launch();

}
#endif /* __OP01_3G__ */

#endif /* __MMI_CM_BLACK_LIST__ */ 

#ifndef __MMI_CLOG_COMPUND_ACTION_EDIT_BEFORE_CALL__
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_edit_before_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_edit_before_call(mmi_clog_act_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    srv_clog_log_struct log;
    cui_dialer_type_enum type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_clog_get_log_by_id(inst->handle, inst->log_id, 0, &log);
    if (ret != SRV_CLOG_RET_OK)
    {
        mmi_clog_act_handle_srv_error(inst, ret);
        return;
    }
    if (log.data.call_log.sub_type == SRV_CLOG_CALL_TYPE_VOIP)
        type = CUI_DIALER_TYPE_VOIP;
    else
        type = CUI_DIALER_TYPE_CLASSIC;
    inst->sub_gid = cui_dialer_create_ex(inst->self_gid, type);
    if (MMI_CLOG_IS_GID_INVALID(inst->sub_gid))
    {
        mmi_clog_popup(STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_FAILURE, inst->parent_gid, inst);
        mmi_frm_group_close(inst->self_gid);
        return;
    }

    cui_dialer_set_dial_string(inst->sub_gid, (const WCHAR*)log.data.call_log.cid);
    cui_dialer_set_launch_style(inst->sub_gid, CUI_DIALER_LAUNCH_TYPE_EDIT_BEFORE_CALL);
    cui_dialer_run(inst->sub_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_dlr_evt_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_act_dlr_evt_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 done = MMI_TRUE;
    mmi_clog_act_inst_struct *inst = (mmi_clog_act_inst_struct*) evt->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_DIALER_CLOSE_REQ:
            cui_dialer_close(((mmi_group_event_struct*) evt)->sender_id);
            inst->sub_gid = GRP_ID_INVALID;
            break;

        case EVT_ID_CUI_DIALER_BEFORE_CALL_LAUNCHED:
            mmi_clog_act_dlr_evt_dialer_before_call_hdlr(evt);
            break;

        case EVT_ID_CUI_DIALER_CLOSED_IND:
            mmi_clog_act_dlr_free_phb_udata(((mmi_group_event_struct*) evt)->sender_id);
            break;

        case EVT_ID_CUI_DIALER_CHANGE_TYPE:
        #if (defined(__MMI_VOIP__) || defined(__MMI_DIALER_SEARCH__))
            mmi_dialer_handle_dialer_change_type(evt);
        #endif /* __MMI_VOIP__ || __MMI_DIALER_SEARCH__ */
            break;

        default:
            done = MMI_FALSE;
            break;
    }
    return done;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_dlr_evt_dialer_before_call_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_act_dlr_evt_dialer_before_call_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    WCHAR *cid;
    void *phb_udata;
    srv_clog_log_struct log;
    mmi_clog_act_inst_struct *inst = (mmi_clog_act_inst_struct*) evt->user_data;
    MMI_ID sender_id = ((mmi_group_event_struct*) evt)->sender_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_clog_get_log_by_id(inst->handle, inst->log_id, 0, &log);
    if (ret == SRV_CLOG_RET_OK)
    {
        cid = (WCHAR*) cui_dialer_get_dial_string(sender_id);
        if (cid)
        {
            ret = srv_phb_compare_number(cid, log.data.call_log.cid);
            if (ret)
			{
                phb_udata = mmi_clog_act_create_phb_udata(&log);
                cui_dialer_set_phb_data(inst->sub_gid, phb_udata);
				
			}
			return;
        }
    }
    /* log is delete or number is changed, should destroy the PHB user data. */

    MMI_CLOG_IT_TRACE((MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_ACT_DLR_EVT_DIALER_BEFORE_CALL_HDLR, sender_id, inst->log_id, ret));

    mmi_clog_act_dlr_free_phb_udata(sender_id);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_dlr_free_phb_udata
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dlr_gid     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_act_dlr_free_phb_udata(MMI_ID dlr_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data = cui_dialer_get_phb_data(dlr_gid);
    /* Check if already free when user modify the number */
    if (!user_data)
        return;
    srv_phb_destory_cm_user_data(user_data);
    cui_dialer_set_phb_data(dlr_gid, NULL);
}

#endif /*__MMI_CLOG_COMPUND_ACTION_EDIT_BEFORE_CALL__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_if_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_if_delete(mmi_clog_act_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inst->sub_gid = mmi_clog_confirm(
                        CNFM_TYPE_YESNO,
                        (inst->op_mid == MMI_CLOG_OP_MID_DELETE) ? STR_GLOBAL_DELETE_ASK : STR_GLOBAL_DELETE_ALL_ASK,
                        MMI_EVENT_QUERY,
                        inst->self_gid,
                        inst,
                        MMI_CLOG_ALERT_FLAG_AUTO_DISMISS );//| MMI_CLOG_ALERT_FLAG_HIDE_CSK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_delete(mmi_clog_act_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_clog_lt_id_attr_struct *attr;
    srv_clog_del_all_logs_req_struct req_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (inst->op_mid == MMI_CLOG_OP_MID_DELETE)
    {
        inst->pid = srv_clog_delete_log_by_id(inst->handle, 0, inst->log_id, mmi_clog_act_delete_result);
    }
    else if (inst->op_mid == MMI_CLOG_OP_MID_DELETE_ALL)
    {
        attr = mmi_clog_get_attr_by_lt_id(inst->sel_lt_id);
        memcpy((srv_clog_log_identity_struct*) & req_data, &attr->idt, sizeof(srv_clog_log_identity_struct));
        inst->pid = srv_clog_delete_all_logs(inst->handle, 0, &req_data, mmi_clog_act_delete_result);
    }
    if (inst->pid < SRV_CLOG_RET_OK)
    {
        mmi_clog_act_handle_srv_error(inst, inst->pid);
        return;
    }
    mmi_frm_display_dummy_screen();
}

#ifdef __MMI_CLOG_FPBW__ 
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_delete_cnf_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *       
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_clog_act_delete_cnf_proc(mmi_event_struct * evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {  
        case EVT_ID_POPUP_QUIT:
            mmi_frm_scrn_close_active_id(); // close dummy screen
        break;
        default:
            break;
    }
    return MMI_RET_OK;
}
#endif /*__MMI_CLOG_FPBW__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_delete_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  pid             [IN]        
 *  req_data        [IN]         
 *  cnf_data        [IN]         
 *  more            [IN]        
 *  ret             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_act_delete_result(
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
    mmi_clog_act_inst_struct *inst;
#ifdef __MMI_CLOG_FPBW__   
    mmi_popup_property_struct property;
#endif /*__MMI_CLOG_FPBW__*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_CLOG_FPBW__ 
    mmi_frm_scrn_close_active_id(); // close dummy screen
#endif /*__MMI_CLOG_FPBW__*/
    inst = mmi_clog_act_get_inst_by_pid(mmi_clog_act_get_cntx(), pid);
    if (!inst)
        return SRV_CLOG_RET_OK;
    
    if (ret != SRV_CLOG_RET_OK)
    {
        mmi_clog_popup(STR_GLOBAL_UNFINISHED, MMI_EVENT_FAILURE, inst->self_gid, inst);
    }
#ifdef __MMI_CLOG_FPBW__
    else
	{
		mmi_popup_property_init(&property);
		property.callback = mmi_clog_act_delete_cnf_proc;
		property.parent_id = inst->self_gid;
		property.user_tag = (void*)inst;
		if (GRP_ID_INVALID == mmi_popup_display_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, &property))        
			mmi_frm_scrn_close_active_id(); // close dummy screen
	}
#endif /*__MMI_CLOG_FPBW__*/
    return SRV_CLOG_RET_OK;
}


#ifdef __MMI_CLOG_MARK_SEVERAL__

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_mark_several_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_enter_mark_several_list(mmi_clog_act_inst_struct *act_inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID lt_gid;
    mmi_clog_inst_struct inst; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inst.lt_type = MMI_CLOG_LT_TYPE_LIST;
    inst.handle = act_inst->handle;
    inst.sel_lt_id = act_inst->sel_lt_id;
    inst.self_gid = act_inst->parent_gid;
	lt_gid = mmi_clog_lt_create_and_run(&inst, MMI_CLOG_LT_STYLE_MARK_SEVERAL);
	MMI_CLOG_IT_ASSERT(!MMI_CLOG_IS_GID_INVALID(lt_gid));
}
#endif /* __MMI_CLOG_MARK_SEVERAL__ */


#define MMI_CLOG_ACT_MISC


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_handle_srv_error
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]         
 *  ret         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_handle_srv_error(mmi_clog_act_inst_struct *inst, S32 ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_popup(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE, inst->self_gid, inst);
    if (!MMI_CLOG_IS_GID_INVALID(inst->sub_gid))
    {
        mmi_clog_act_alt_dismiss(inst, inst->sub_gid);
    }
}


#if (defined(__MMI_CLOG_ACCESSORIES__) && defined(__MMI_CLOG_TAB_SUPPORT__))

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_show_advance_items
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_act_show_advance_items(mmi_clog_act_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_enter_advanced(inst->self_gid);
}

#endif /* __MMI_CLOG_ACCESSORIES__ && __MMI_CLOG_TAB_SUPPORT__ */ 


#ifndef __MMI_CLOG_COMPUND_ACTION_RESPOND_HOOK_KEY__
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_make_call_cbk
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cb_para        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_make_call_cbk(mmi_ucm_after_make_call_cb_struct* cb_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if((cb_para != NULL) && (cb_para->user_data))
		    srv_phb_destory_cm_user_data(cb_para->user_data);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_gpio_hookkey_hdlr
 * DESCRIPTION
 *  respond hook key in earphone, if in idle and no active all, will dial the last calllog
 * PARAMETERS
 *  evt        [IN]     
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_clog_gpio_hookkey_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_idle_is_active() &&
        0 == srv_ucm_query_call_count((srv_ucm_call_state_enum)SRV_UCM_CALL_STATE_ALL, (srv_ucm_call_type_enum)SRV_UCM_CALL_TYPE_ALL, NULL))
    {
        U8 sim_id = MMI_SIM_NONE;
        if (srv_nw_usab_is_usable(MMI_SIM1))
            sim_id |= MMI_SIM1;
    #if (MMI_MAX_SIM_NUM >= 2)
        if (srv_nw_usab_is_usable(MMI_SIM2))
            sim_id |= MMI_SIM2;
    #endif
    #if (MMI_MAX_SIM_NUM >= 3)
        if (srv_nw_usab_is_usable(MMI_SIM3))
            sim_id |= MMI_SIM3;
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        if (srv_nw_usab_is_usable(MMI_SIM4))
            sim_id |= MMI_SIM4;
    #endif

        if (MMI_SIM_NONE != sim_id)
        {
            mmi_ucm_make_call_para_struct call_para;
            void *phb_data;
            S32 ret;
            srv_clog_call_log_struct *log; 
            srv_clog_get_last_log_req_struct req_data;
            srv_clog_get_last_log_cnf_struct cnf_data;
            srv_clog_init_para(SRV_CLOG_PARA_GET_LAST_LOG_CNF, &cnf_data);
            req_data.fields = SRV_CLOG_LOG_FIELD_ALL;
            SRV_CLOG_INIT_IDT(
                (srv_clog_log_identifier_struct*) & req_data,
                SRV_CLOG_CATE_CALL,
                sim_id,
                SRV_CLOG_CLT_DIALED,
                SRV_CLOG_CALL_TYPE_ALL);
            
             ret = srv_clog_get_last_log(0,
                        (const srv_clog_get_last_log_req_struct *) &req_data, &cnf_data);
            if (SRV_CLOG_RET_OK != ret)
                return MMI_RET_ERR; // don't ask other APP to handle this event again
                
            // start to make call
            log = &(cnf_data.log.data.call_log);
            mmi_ucm_init_call_para(&call_para);
            if (MMI_SIM1 == log->sim_id)
                call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE;

#if (MMI_MAX_SIM_NUM >= 2)
            else if (MMI_SIM2 == log->sim_id)
                call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
#endif
#if (MMI_MAX_SIM_NUM >= 3)
            else if (MMI_SIM3 == log->sim_id)
                call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM3;
#endif
#if (MMI_MAX_SIM_NUM >= 4)
            else// MMI_SIM4
                call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM4;
#endif

            call_para.ucs2_num_uri = (U16*)log->cid;
            call_para.adv_para.after_make_call_callback = mmi_clog_make_call_cbk;

            if(srv_phb_check_number_id(log->phb_id))
                phb_data = srv_phb_create_cm_user_data_by_id(log->phb_id);
            else if(log->name[0] != 0) // have name string
                phb_data = srv_phb_create_cm_user_data((U16 *)log->name, 0, SRV_PHB_INVALID_INDEX);
            else
               phb_data = NULL;

            call_para.adv_para.after_callback_user_data = phb_data;
            call_para.adv_para.phb_data = phb_data;
            mmi_ucm_call_launch(GRP_ID_ROOT, &call_para);
        }
		return MMI_RET_ERR; // don't ask other APP to handle this event again
    }          
    return MMI_RET_OK; // ask other APP to handle this event again
} 
#endif /*__MMI_CLOG_COMPUND_ACTION_RESPOND_HOOK_KEY__*/
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */

#else 

MMI_ID g_clog_sim_support = MMI_SIM_ALL;
MMI_ID mmi_clog_act_proc(MMI_ID parent_gid, mmi_clog_act_para_struct *para)
{
}

#endif /* __MMI_TELEPHONY_SUPPORT__ */


