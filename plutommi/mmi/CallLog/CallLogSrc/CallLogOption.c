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
*  CallLogOption.c
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
#include "MMIDataType.h"

#if defined(__MMI_TELEPHONY_SUPPORT__) || defined(__MMI_BT_PBAP_CLIENT__)

#include "kal_public_api.h"
#include "kal_general_types.h"

#ifndef __MMI_UNIFIED_COMPOSER__
#include "SmsSrvGprot.h"
#ifdef __MMI_MMS__
#include "mms_api.h"
#endif 
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
#include "Phbsrvgprot.h"
#include "PhbCuiGprot.h"

#include "menucuigprot.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "MMI_common_app_trc.h"
#include "string.h"
#include "GlobalResDef.h"
#include "CommonScreensResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_util.h"
#include "mmi_rp_app_mainmenu_def.h"

#include "CallLogSrvGprot.h"
#include "CallLogConfig.h"
#include "CallLogGprot.h"
#include "CallLogProt.h"
#include "mmi_rp_app_calllog_def.h"

#include "DialerCuiGprot.h"

#include "SimCtrlSrvGprot.h"
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
    /* Base  for function */
    MMI_CLOG_OP_MID_GRP_ALL = 0xFFFFFF,
    MMI_CLOG_OP_MID_GRP_ACT_ALL = MMI_CLOG_OP_MID_GRP_ALL & ~MMI_CLOG_OP_MID_ADVANCED,
    MMI_CLOG_OP_MID_GRP_TAB_ONLY = MMI_CLOG_OP_MID_DELETE_ALL | MMI_CLOG_OP_MID_ADVANCED,
    MMI_CLOG_OP_MID_GRP_DEL = MMI_CLOG_OP_MID_DELETE | MMI_CLOG_OP_MID_DELETE_ALL,
    MMI_CLOG_OP_MID_GRP_BASE = MMI_CLOG_OP_MID_VIEW | MMI_CLOG_OP_MID_MAKE_CALL | MMI_CLOG_OP_MID_SAVE_TO_PHB | MMI_CLOG_OP_MID_MARK_SEVERAL,
    MMI_CLOG_OP_MID_GRP_MSG = MMI_CLOG_OP_MID_SEND_MSG | MMI_CLOG_OP_MID_SEND_SMS | MMI_CLOG_OP_MID_SEND_MMS,
    MMI_CLOG_OP_MID_GRP_OP11_ONLY = MMI_CLOG_OP_MID_CLEAR_EVENT | MMI_CLOG_OP_MID_CLEAR_ALL_EVENTS | MMI_CLOG_OP_MID_GOTO,

    /* Enable menu group for scenario */
    MMI_CLOG_OP_MID_GRP_NO_LOG = MMI_CLOG_OP_MID_ADVANCED,
    MMI_CLOG_OP_MID_GRP_EMP_CID = MMI_CLOG_OP_MID_VIEW | MMI_CLOG_OP_MID_GRP_DEL | MMI_CLOG_OP_MID_MARK_SEVERAL | MMI_CLOG_OP_MID_ADVANCED,
    /* MMI_CLOG_OP_MID_GRP_AP = MMI_CLOG_OP_MID_GRP_ALL & ~ MMI_CLOG_OP_MID_GRP_EMP_CID, */

    /* Enable menu group for different type */
    MMI_CLOG_OP_MID_GRP_LT_LIST = MMI_CLOG_OP_MID_GRP_ALL & ~(MMI_CLOG_OP_MID_GRP_OP11_ONLY | MMI_CLOG_OP_MID_GRP_TAB_ONLY),
    MMI_CLOG_OP_MID_GRP_LT_TAB = MMI_CLOG_OP_MID_GRP_ALL & ~(MMI_CLOG_OP_MID_GRP_OP11_ONLY),
    MMI_CLOG_OP_MID_GRP_LIST_VIEWER = MMI_CLOG_OP_MID_GRP_LT_LIST & ~(MMI_CLOG_OP_MID_VIEW | MMI_CLOG_OP_MID_MARK_SEVERAL),
    MMI_CLOG_OP_MID_GRP_TAB_VIEWER = MMI_CLOG_OP_MID_GRP_LT_TAB & ~(MMI_CLOG_OP_MID_VIEW | MMI_CLOG_OP_MID_GRP_TAB_ONLY | MMI_CLOG_OP_MID_MARK_SEVERAL),
    MMI_CLOG_OP_MID_GRP_VUI = MMI_CLOG_OP_MID_GRP_BASE | MMI_CLOG_OP_MID_GRP_MSG,
    MMI_CLOG_OP_MID_GRP_OP11 = MMI_CLOG_OP_MID_GRP_BASE | MMI_CLOG_OP_MID_GRP_MSG | MMI_CLOG_OP_MID_GRP_OP11_ONLY,
    MMI_CLOG_OP_MID_GRP_MAX_ITEM
} mmi_clog_op_mid_grp_enum;

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/
typedef struct
{
    mmi_clog_op_mid_idx_enum mid_idx;
    MMI_MENU_ID menu_id;
} mmi_clog_op_menu_map_struct;

typedef struct
{
    /* mmi_clog_op_type_enum type; */ /* Slim it as it can be array index */
    mmi_clog_op_mid_grp_enum mid_grp;
} mmi_clog_op_type_mid_map_struct;

#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
typedef struct
{
    U16 flags;
    MMI_ID self_gid;
    MMI_ID parent_gid;
    MMI_ID mc_gid;
    mmi_clog_op_type_enum type;
    mmi_clog_lt_id_enum sel_lt_id;
    SRV_CLOG_HANDLE handle;
    SRV_CLOG_ID log_id; /* if 0, means empty */
} mmi_clog_op_inst_struct;

typedef struct
{
    mmi_clog_op_inst_struct inst_list[MMI_CLOG_OP_INST_MAX_NUM];
} mmi_clog_op_cntx_struct;
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */


/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/

static const mmi_clog_op_menu_map_struct g_mmi_clog_op_menu_map_tbl[] = 
{
    {MMI_CLOG_OP_MID_IDX_VIEW,                      MENU_ID_CLOG_VIEW},
    {MMI_CLOG_OP_MID_IDX_MAKE_CALL,                 MENU_ID_CLOG_MAKE_CALL},

#ifdef __MMI_UNIFIED_COMPOSER__
    {MMI_CLOG_OP_MID_IDX_SEND_MSG,                  MENU_ID_CLOG_SEND_MSG},
#else /* __MMI_UNIFIED_COMPOSER__ */ 
    {MMI_CLOG_OP_MID_IDX_SEND_SMS,                  MENU_ID_CLOG_SEND_SMS},
#ifdef __MMI_MMS__
    {MMI_CLOG_OP_MID_IDX_SEND_MMS,                  MENU_ID_CLOG_SEND_MMS},
#endif 
#endif /* __MMI_UNIFIED_COMPOSER__ */ 

    {MMI_CLOG_OP_MID_IDX_SAVE_TO_PHB,               MENU_ID_CLOG_SAVE_TO_PHB},

#ifdef __MMI_CM_BLACK_LIST__
    {MMI_CLOG_OP_MID_IDX_ADD_TO_BLACK_LIST,         MENU_ID_CLOG_ADD_TO_BLACK_LIST},
#ifdef __OP01_3G__
    {MMI_CLOG_OP_MID_IDX_ENTER_BLACK_LIST,          MENU_ID_CLOG_ENTER_BLACK_LIST},
#endif 
#endif /* __MMI_CM_BLACK_LIST__ */

#ifdef __OP01_FWPBW__
    {MMI_CLOG_OP_MID_IDX_MAKE_IP_CALL,              MENU_ID_CLOG_MAKE_IP_CALL},
#endif

#ifndef __MMI_CLOG_COMPUND_ACTION_EDIT_BEFORE_CALL__
    {MMI_CLOG_OP_MID_IDX_EDIT_BEFORE_CALL,          MENU_ID_CLOG_EDIT_BEFORE_CALL},
#endif /* __MMI_CLOG_COMPUND_ACTION_EDIT_BEFORE_CALL__*/

    {MMI_CLOG_OP_MID_IDX_DELETE,                    MENU_ID_CLOG_DELETE},
    {MMI_CLOG_OP_MID_IDX_DELETE_ALL,                MENU_ID_CLOG_DELETE_ALL},

#ifdef __MMI_CLOG_MARK_SEVERAL__
    {MMI_CLOG_OP_MID_IDX_MARK_SEVERAL,              MENU_ID_CLOG_MARK_SEVERAL},
#endif

#ifdef __MMI_CLOG_TAB_SUPPORT__
#if (defined(__MMI_CLOG_CALL_TIME__) || defined(__MMI_CLOG_CALL_COST__) || defined(__MMI_CLOG_SMS_COUNT__) || defined(__MMI_CLOG_GPRS_COUNT__))
    {MMI_CLOG_OP_MID_IDX_ADVANCED,                  MENU_ID_CLOG_ADVANCED},
#endif
#endif /* __MMI_CLOG_TAB_SUPPORT__ */

    /* For CMCC */
#ifdef __MMI_CLOG_SIM_FILTER__
    {MMI_CLOG_OP_MID_IDX_SEL_SIM_1,               MENU_ID_CLOG_SIM_1},
#ifdef __MMI_DUAL_SIM__
/* under construction !*/
#endif /*__MMI_DUAL_SIM__*/
#if (MMI_MAX_SIM_NUM >= 3)
    {MMI_CLOG_OP_MID_IDX_SEL_SIM_3,               MENU_ID_CLOG_SIM_3},
#endif /*MMI_MAX_SIM_NUM >= 3*/
#if (MMI_MAX_SIM_NUM >= 4)
    {MMI_CLOG_OP_MID_IDX_SEL_SIM_4,               MENU_ID_CLOG_SIM_4},
#endif /*MMI_MAX_SIM_NUM >= 4*/
    {MMI_CLOG_OP_MID_IDX_SEL_SIM_ALL,             MENU_ID_CLOG_SIM_ALL},
#endif /*__MMI_CLOG_SIM_FILTER__*/
};

/* Slim it by remove array index field, please check mmi_clog_op_type_enum once update it */
static const mmi_clog_op_type_mid_map_struct g_mmi_clog_op_type_mid_map_tbl[] = 
{
    {/* MMI_CLOG_OP_TYPE_LT_LIST, */            MMI_CLOG_OP_MID_GRP_LT_LIST},
    {/* MMI_CLOG_OP_TYPE_LIST_VIEWER, */        MMI_CLOG_OP_MID_GRP_LIST_VIEWER},

#ifdef __MMI_CLOG_TAB_SUPPORT__
    {/* MMI_CLOG_OP_TYPE_LT_TAB, */             MMI_CLOG_OP_MID_GRP_LT_TAB},
    {/* MMI_CLOG_OP_TYPE_TAB_VIEWER, */         MMI_CLOG_OP_MID_GRP_TAB_VIEWER},
#endif /* __MMI_CLOG_TAB_SUPPORT__ */

#if defined (__MMI_VUI_HOMESCREEN__)
    {/* MMI_CLOG_OP_TYPE_VUI, */                MMI_CLOG_OP_MID_GRP_VUI},
#endif
};

static mmi_clog_op_cntx_struct g_mmi_clog_op_cntx;

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/
#define MMI_CLOG_OP_FUNC_DECLARATION
#if defined(__MMI_CLOG_ADP__) && defined(__MMI_VUI_HOMESCREEN__) 
static MMI_RET mmi_clog_op_init_para(mmi_clog_op_para_struct *para);
#endif /* defined(__MMI_CLOG_ADP__) && defined(__MMI_VUI_HOMESCREEN__)  */
static mmi_clog_op_cntx_struct *mmi_clog_op_get_cntx(void);
static mmi_clog_op_inst_struct *mmi_clog_op_alloc_inst(mmi_clog_op_cntx_struct *cntx);
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
static mmi_clog_op_inst_struct * mmi_clog_op_init_inst(MMI_ID parent_gid, mmi_clog_op_para_struct *para);
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
static void mmi_clog_op_destroy_inst(mmi_clog_op_inst_struct *inst);
static U32 mmi_clog_op_type2mid(mmi_clog_op_type_enum type);
static void mmi_clog_op_hide_menu(mmi_clog_op_inst_struct *inst);
static void mmi_clog_op_hide_l1_menu(mmi_clog_op_inst_struct *inst);
static void mmi_clog_op_enable_menu(mmi_clog_op_inst_struct *inst, U32 enb_mid_grp);
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
static mmi_clog_op_mid_enum mmi_clog_op_get_mid_by_menu_id(MMI_MENU_ID menu_id);
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
static mmi_clog_op_mid_enum mmi_clog_op_get_enb_ap_mid(mmi_clog_op_inst_struct *inst, srv_clog_log_struct *log);
static mmi_clog_op_mid_enum mmi_clog_op_get_enb_int_mid(mmi_clog_op_inst_struct *inst, srv_clog_log_struct *log);
static MMI_RET mmi_clog_op_group_proc(mmi_event_struct *evt);
static void mmi_clog_op_evt_mm_entry_hdlr(cui_menu_event_struct *evt);
static void mmi_clog_op_evt_mm_select_hdlr(cui_menu_event_struct *evt);
static void mmi_clog_op_evt_mm_close_hdlr(cui_menu_event_struct *evt);

/*----------------------------------------------------------------------------*/
/* Extern Function Defines                                                    */
/*----------------------------------------------------------------------------*/
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
extern void mmi_clog_act_run(mmi_clog_op_inst_struct *inst);
extern void mmi_clog_act_alt_dismiss(mmi_clog_op_inst_struct *inst, MMI_ID alert_id);
extern void mmi_clog_act_evt_alert_yes_hdlr(mmi_event_struct *evt);
extern void mmi_clog_act_evt_phb_save_hdlr(mmi_clog_op_inst_struct *inst);
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */

/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/
#define MMI_CLOG_OP_FUNC_DEFINITION
#define MMI_CLOG_OP_INIT
#if defined(__MMI_CLOG_ADP__) && defined(__MMI_VUI_HOMESCREEN__) 
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_op_init_para
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_RET mmi_clog_op_init_para(mmi_clog_op_para_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!para)
        return MMI_RET_ERR;

    memset(para, 0x0, sizeof(mmi_clog_op_para_struct));
    return MMI_RET_OK;
}
#endif /* defined(__MMI_CLOG_ADP__) && defined(__MMI_VUI_HOMESCREEN__)  */


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_op_get_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mmi_clog_op_cntx_struct *mmi_clog_op_get_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_mmi_clog_op_cntx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_op_alloc_inst
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
mmi_clog_op_inst_struct *mmi_clog_op_alloc_inst(mmi_clog_op_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
    if (MMI_CLOG_OP_INST_MAX_NUM == 1) /* For slim */
    {
        MMI_CLOG_SET_BIT(cntx->inst_list[0].flags, MMI_CLOG_CMN_INST_FLAG_IS_USED | MMI_CLOG_INST_TYPE_OP);
        return &cntx->inst_list[0];
    }
    else
    {
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
        for (i = 0; i < MMI_CLOG_OP_INST_MAX_NUM; i++)
        {
            if (!MMI_CLOG_CHECK_BIT(cntx->inst_list[i].flags, MMI_CLOG_CMN_INST_FLAG_IS_USED))
            {
                MMI_CLOG_SET_BIT(cntx->inst_list[i].flags, MMI_CLOG_CMN_INST_FLAG_IS_USED | MMI_CLOG_INST_TYPE_OP);
                return &cntx->inst_list[i];
            }
        }
        MMI_CLOG_ASSERT(0);
        return NULL;
#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
    }
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
}


#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_op_init_inst
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_gid      [IN]        
 *  para            [IN]         
 * RETURNS
 *  
 *****************************************************************************/
mmi_clog_op_inst_struct *mmi_clog_op_init_inst(MMI_ID parent_gid, mmi_clog_op_para_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_op_cntx_struct *cntx;
    mmi_clog_op_inst_struct *inst;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = mmi_clog_op_get_cntx();

    if(para->type == MMI_CLOG_OP_TYPE_LT_LIST
      #ifdef __MMI_CLOG_TAB_SUPPORT__
        || para->type == MMI_CLOG_OP_TYPE_LT_TAB
      #endif
        || MMI_CLOG_CHECK_BIT(para->op_mid, MMI_CLOG_OP_MID_VIEW)
    )
    {
        inst = &cntx->inst_list[0];
        inst->self_gid = GRP_ID_CLOG_OPTION;
    }
    else
    {
        inst = &cntx->inst_list[1];
        inst->self_gid = GRP_ID_CLOG_OPTION_VIEWER;
    }
    
    MMI_CLOG_SET_BIT(inst->flags, MMI_CLOG_CMN_INST_FLAG_IS_USED | MMI_CLOG_INST_TYPE_OP);

    inst->parent_gid = parent_gid;
    inst->type = para->type;
    inst->sel_lt_id = para->sel_lt_id;
    inst->handle = para->handle;
    inst->log_id = para->log_id;
    inst->op_mid = para->op_mid;
    MMI_CLOG_SET_BIT(inst->flags, para->flags);
#ifdef __MMI_VUI_HOMESCREEN__
    if (para->type == MMI_CLOG_OP_TYPE_VUI)
        MMI_CLOG_SET_BIT(inst.flags, MMI_CLOG_ACT_FLAG_PURE_VIEW);
#endif
    inst->self_gid = mmi_frm_group_create_ex(parent_gid, inst->self_gid, mmi_clog_op_group_proc, inst, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    MMI_CLOG_IT_TRACE((
            MMI_CLOG_TRC_INFO,
            TRC_MMI_CLOG_OP_ENTER,
            inst->parent_gid,
            inst->self_gid,
            inst->mc_gid,
            inst->type,
            inst->sel_lt_id,
            inst->handle,
            inst->log_id,
            inst->op_mid,
            inst->flags));

    return inst;
}
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_op_destroy_inst
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_op_destroy_inst(mmi_clog_op_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!MMI_CLOG_IS_INST_VALID(inst, MMI_CLOG_INST_TYPE_OP))
        return;

    MMI_CLOG_IT_TRACE((
        MMI_CLOG_TRC_INFO,
        TRC_MMI_CLOG_OP_DESTROY_INST,
        inst->parent_gid,
        inst->self_gid,
        inst->mc_gid,
        inst->type,
        inst->sel_lt_id,
        inst->handle,
        inst->log_id,
        inst->flags));

    memset(inst, 0x0, sizeof(mmi_clog_op_inst_struct));
}


#define MMI_CLOG_OP_UTIL
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_op_get_inst_by_opmid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]         
 *  pid         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_clog_op_inst_struct *mmi_clog_op_get_inst_by_opmid(U8 op_mid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    mmi_clog_op_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = mmi_clog_op_get_cntx();

    for (i = 0; i < MMI_CLOG_OP_INST_MAX_NUM; i++)
    {
        if (MMI_CLOG_IS_INST_VALID(&g_mmi_clog_op_cntx.inst_list[i], MMI_CLOG_INST_TYPE_OP)
            && MMI_CLOG_CHECK_BIT(cntx->inst_list[i].op_mid, op_mid)
           )
        {
            return &cntx->inst_list[i];
        }
    }

    return NULL;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_op_type2mid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_clog_op_type2mid(mmi_clog_op_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_CLOG_IT_ASSERT(type < sizeof(g_mmi_clog_op_type_mid_map_tbl) / sizeof(mmi_clog_op_type_mid_map_struct));

    return g_mmi_clog_op_type_mid_map_tbl[type].mid_grp; 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_op_hide_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_op_hide_menu(mmi_clog_op_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_op_hide_l1_menu(inst);
    
#ifdef __MMI_CLOG_CALL_COST__
    mmi_clog_check_cphs_service(inst->mc_gid);
#endif /* __MMI_CLOG_CALL_COST__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_op_hide_l1_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_op_hide_l1_menu(mmi_clog_op_inst_struct *inst)
{
#ifdef __MMI_TELEPHONY_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 enb_mid = MMI_CLOG_OP_MID_GRP_ALL;
    srv_clog_log_struct log_data;
    srv_clog_log_struct *log = NULL;
    srv_clog_num_info_struct num_info;
    const mmi_clog_lt_id_attr_struct *attr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_clog_get_log_by_id(inst->handle, inst->log_id, 0, &log_data);
    if (ret == SRV_CLOG_RET_OK)
        log = &log_data;

    enb_mid &= mmi_clog_op_type2mid(inst->type);
    enb_mid &= mmi_clog_op_get_enb_ap_mid(inst, log);
    enb_mid &= mmi_clog_op_get_enb_int_mid(inst, log);

    attr = mmi_clog_get_attr_by_lt_id(inst->sel_lt_id);
    ret = srv_clog_get_list_num_info(inst->handle, &attr->idt, &num_info);
    if (ret == SRV_CLOG_RET_OK)
    {
        if (num_info.num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS] == 0 && inst->type == MMI_CLOG_OP_TYPE_LT_LIST)
        {
            cui_menu_set_currlist_left_softkey(inst->mc_gid, NULL);
        }
    }

    MMI_CLOG_IT_TRACE((
        MMI_CLOG_TRC_INFO,
        TRC_MMI_CLOG_OP_HIDE_L1_MENU,
        enb_mid,
        inst->type,
        inst->sel_lt_id,
        ret,
        num_info.num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS]));

    mmi_clog_op_enable_menu(inst, enb_mid);
#endif /* __MMI_TELEPHONY_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_op_enable_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]         
 *  mid_grp     [IN]        
 *  enable      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_op_enable_menu(mmi_clog_op_inst_struct *inst, U32 enb_mid_grp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < sizeof(g_mmi_clog_op_menu_map_tbl) / sizeof(mmi_clog_op_menu_map_struct); i++)
    {
        /* If not find it in enable bit map, just hide it, if find, unhide it */
        cui_menu_set_item_hidden(inst->mc_gid,
            g_mmi_clog_op_menu_map_tbl[i].menu_id,
            (MMI_BOOL)!MMI_CLOG_CHECK_BIT(enb_mid_grp, MMI_CLOG_IDX2BIT(g_mmi_clog_op_menu_map_tbl[i].mid_idx)));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_op_get_mid_by_menu_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_clog_op_mid_enum mmi_clog_op_get_mid_by_menu_id(MMI_MENU_ID menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < sizeof(g_mmi_clog_op_menu_map_tbl) / sizeof(mmi_clog_op_menu_map_struct); i++)
    {
        if (g_mmi_clog_op_menu_map_tbl[i].menu_id == menu_id)
            return (mmi_clog_op_mid_enum)MMI_CLOG_IDX2BIT(g_mmi_clog_op_menu_map_tbl[i].mid_idx);
    }
    
    MMI_CLOG_ASSERT(0);
    return MMI_CLOG_OP_MID_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_op_get_enb_ap_mid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 *  log         [IN]     
 * RETURNS
 *  
 *****************************************************************************/
mmi_clog_op_mid_enum mmi_clog_op_get_enb_ap_mid(mmi_clog_op_inst_struct *inst, srv_clog_log_struct *log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_op_mid_enum enb_mid = (mmi_clog_op_mid_enum)MMI_CLOG_OP_MID_GRP_ALL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_UNIFIED_COMPOSER__
#ifdef __MMI_MMS__
    if (!mms_is_ready())
        MMI_CLOG_CLEAR_BIT(enb_mid, MMI_CLOG_OP_MID_SEND_MMS);
#endif /* __MMI_MMS__ */ 
#endif /* __MMI_UNIFIED_COMPOSER__ */ 

#ifdef __MMI_VOIP__
    if (!log || log->data.call_log.sub_type == SRV_CLOG_CALL_TYPE_VOIP)
        MMI_CLOG_CLEAR_BIT(enb_mid, MMI_CLOG_OP_MID_GRP_MSG);
#endif /* __MMI_VOIP__ */ 

    if (!log || srv_phb_check_number_id(log->data.call_log.phb_id) || mmi_ucs2strlen((CHAR*)log->data.call_log.name))
        MMI_CLOG_CLEAR_BIT(enb_mid, MMI_CLOG_OP_MID_SAVE_TO_PHB);

    return enb_mid;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_op_get_enb_int_mid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 *  log         [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static mmi_clog_op_mid_enum mmi_clog_op_get_enb_int_mid(mmi_clog_op_inst_struct *inst, srv_clog_log_struct *log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    srv_clog_num_info_struct num_info;
    const mmi_clog_lt_id_attr_struct *attr;
    mmi_clog_op_mid_enum enb_mid = (mmi_clog_op_mid_enum)MMI_CLOG_OP_MID_GRP_ALL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (inst->type == MMI_CLOG_OP_TYPE_LIST_VIEWER
#ifdef __MMI_CLOG_TAB_SUPPORT__
        || inst->type == MMI_CLOG_OP_MID_GRP_TAB_VIEWER
#endif
        )
    {
        MMI_CLOG_CLEAR_BIT(enb_mid, MMI_CLOG_OP_MID_VIEW);
        MMI_CLOG_CLEAR_BIT(enb_mid, MMI_CLOG_OP_MID_ADVANCED);
    }

    attr = mmi_clog_get_attr_by_lt_id(inst->sel_lt_id);
    ret = srv_clog_get_list_num_info(inst->handle, &attr->idt, &num_info);

    if (ret == SRV_CLOG_RET_OK)
    {
        if (num_info.num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS] == 1)
            MMI_CLOG_CLEAR_BIT(enb_mid, MMI_CLOG_OP_MID_DELETE_ALL);
    #ifdef __MMI_CLOG_MARK_SEVERAL__
        if (num_info.num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS] == 0)
            MMI_CLOG_CLEAR_BIT(enb_mid, MMI_CLOG_OP_MID_MARK_SEVERAL);
    #endif
    }

    if (SRV_CLOG_IS_ELM_INVALID(inst->log_id))  /* no log case */
    {
        enb_mid &= MMI_CLOG_OP_MID_GRP_NO_LOG;
    }
    else
    {
        if (log->data.call_log.cid[0] == '\0')  /* empty cid */
            enb_mid &= MMI_CLOG_OP_MID_GRP_EMP_CID;
        /* not check log number = 1 yet */
    }

    return enb_mid;
}


#define MMI_CLOG_OP_ACTION
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_op_enter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_gid      [IN]        
 *  para            [IN]         
 * RETURNS
 *  
 *****************************************************************************/
MMI_ID mmi_clog_op_enter(MMI_ID parent_gid, mmi_clog_op_para_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_op_inst_struct *inst;
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__  /*For dynamic sim daynamic UI*/
    //srv_clog_log_struct  log;
    MMI_BOOL inserted_sim = MMI_FALSE;
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_CLOG_IS_GID_INVALID(parent_gid) || !para)
        return GRP_ID_INVALID;

#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
    inst = mmi_clog_op_init_inst(parent_gid, para);
#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    inst = mmi_clog_op_alloc_inst(mmi_clog_op_get_cntx());
    inst->parent_gid = parent_gid;
    inst->type = para->type;
    inst->sel_lt_id = para->sel_lt_id;
    inst->handle = para->handle;
    inst->log_id = para->log_id;
    MMI_CLOG_SET_BIT(inst->flags, para->flags);

    inst->self_gid = mmi_clog_alloc_gid(MMI_CLOG_GRP_TYPE_OP);
    inst->self_gid = mmi_frm_group_create_ex(parent_gid, inst->self_gid, mmi_clog_op_group_proc, inst, MMI_FRM_NODE_SMART_CLOSE_FLAG);
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    inst->mc_gid = cui_menu_create(
                    inst->self_gid,
                    CUI_MENU_SRC_TYPE_RESOURCE,
                    CUI_MENU_TYPE_OPTION,
                    MENU_ID_CLOG_OPTION,
                    MMI_TRUE,
                    inst);

#ifdef __MMI_BT_PBAP_CLIENT__
    cui_menu_set_item_hidden(inst->mc_gid,MMI_CLOG_OP_MID_DELETE_ALL, MMI_TRUE);
#endif
                    
#ifdef __MMI_CLOG_SIM_FILTER__
  #ifndef __MMI_CLOG_TAB_SUPPORT__
    if (inst->type == MMI_CLOG_OP_TYPE_LIST_VIEWER)
  #else
    if (inst->type == MMI_CLOG_OP_TYPE_TAB_VIEWER)
  #endif
    {
        cui_menu_set_item_disabled(inst->mc_gid,MENU_ID_CLOG_SIM_1,MMI_TRUE);

    #ifdef __MMI_DUAL_SIM__
/* under construction !*/
    #endif
    #if (MMI_MAX_SIM_NUM >= 3)
        cui_menu_set_item_disabled(inst->mc_gid,MENU_ID_CLOG_SIM_3,MMI_TRUE);
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        cui_menu_set_item_disabled(inst->mc_gid,MENU_ID_CLOG_SIM_4,MMI_TRUE);
    #endif
        cui_menu_set_item_disabled(inst->mc_gid,MENU_ID_CLOG_SIM_ALL,MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_disabled(inst->mc_gid,MENU_ID_CLOG_SIM_1,MMI_FALSE);
    #ifdef __MMI_DUAL_SIM__
/* under construction !*/
    #endif
    #if (MMI_MAX_SIM_NUM >= 3)
        cui_menu_set_item_disabled(inst->mc_gid,MENU_ID_CLOG_SIM_3,MMI_FALSE);
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        cui_menu_set_item_disabled(inst->mc_gid,MENU_ID_CLOG_SIM_4,MMI_FALSE);
    #endif
        cui_menu_set_item_disabled(inst->mc_gid,MENU_ID_CLOG_SIM_ALL,MMI_FALSE);
    }
#endif /*__MMI_CLOG_SIM_FILTER__*/

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__  /*For dynamic sim daynamic UI*/
    //srv_clog_get_log_by_id(NULL,inst->log_id,SRV_CLOG_LOG_FIELD_IDENTITY,&log);
    cui_menu_set_item_disabled(inst->mc_gid,MENU_ID_CLOG_MAKE_CALL,MMI_FALSE);

    if (srv_sim_ctrl_is_inserted(MMI_SIM1)== MMI_TRUE)
    {
        inserted_sim = MMI_TRUE;
    }
  #ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
  #endif /*__MMI_DUAL_SIM__*/
  #if (MMI_MAX_SIM_NUM >= 3)
    if (srv_sim_ctrl_is_inserted(MMI_SIM3)== MMI_TRUE)
    {
        inserted_sim = MMI_TRUE;
    }
  #endif /*MMI_MAX_SIM_NUM >= 3*/
  #if (MMI_MAX_SIM_NUM >= 4)
    if (srv_sim_ctrl_is_inserted(MMI_SIM4)== MMI_TRUE)
    {
        inserted_sim = MMI_TRUE;
    }
  #endif /*MMI_MAX_SIM_NUM >= 4*/
	
    if (inserted_sim == MMI_FALSE)
    {
        cui_menu_set_item_disabled(inst->mc_gid,MENU_ID_CLOG_MAKE_CALL,MMI_TRUE);

    }
#endif /*__MMI_DYNAMIC_SIM_DYNAMIC_UI__*/

#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
    MMI_CLOG_IT_TRACE((
        MMI_CLOG_TRC_INFO,
        TRC_MMI_CLOG_OP_ENTER,
        inst->parent_gid,
        inst->self_gid,
        inst->mc_gid,
        inst->type,
        inst->sel_lt_id,
        inst->handle,
        inst->log_id,
        inst->flags));
#endif/* __MMI_CLOG_SLIM_FOR_MT6261__ */
    mmi_clog_op_hide_menu(inst);

#ifndef __MMI_CLOG_SLIM__
    cui_menu_set_default_title_image_by_id(inst->mc_gid, GetRootTitleIcon(MAIN_MENU_CALL_LOG));
#endif /* __MMI_CLOG_SLIM__*/
    cui_menu_run(inst->mc_gid);

    return inst->self_gid;
}


#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
MMI_ID mmi_clog_op_run(MMI_ID parent_gid, mmi_clog_op_para_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_op_inst_struct *inst;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_CLOG_IS_GID_INVALID(parent_gid) || !para)
        return GRP_ID_INVALID;

    inst = mmi_clog_op_init_inst(parent_gid, para);

    mmi_clog_act_run(inst);

    return inst->self_gid;
}
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */


#define MMI_CLOG_OP_EVENT
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_op_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_RET mmi_clog_op_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
    #ifdef __MMI_CLOG_SLIM_FOR_MT6261__
        case EVT_ID_GROUP_FIRST_ENTRY:
        case EVT_ID_GROUP_ACTIVE:
        case EVT_ID_GROUP_INACTIVE:
            break;
    #endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
        case EVT_ID_GROUP_DEINIT:
            mmi_clog_op_destroy_inst((mmi_clog_op_inst_struct*) evt->user_data);
            break;

        case EVT_ID_CUI_MENU_LIST_ENTRY:
            mmi_clog_op_evt_mm_entry_hdlr((cui_menu_event_struct*) evt);
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_clog_op_evt_mm_select_hdlr((cui_menu_event_struct*) evt);
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            mmi_clog_op_evt_mm_close_hdlr((cui_menu_event_struct*) evt);
            break;
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
        case EVT_ID_PHB_SAVE_CONTACT:
        case EVT_ID_PHB_SAVE_CONTACT_CANCEL:
            mmi_clog_act_evt_phb_save_hdlr((mmi_clog_op_inst_struct*) evt->user_data);
            break;

    #ifndef __MMI_CLOG_COMPUND_ACTION_EDIT_BEFORE_CALL__
        case EVT_ID_CUI_DIALER_CLOSE_REQ:
            cui_dialer_close(((mmi_group_event_struct*) evt)->sender_id);
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
    #endif /*__MMI_CLOG_COMPUND_ACTION_EDIT_BEFORE_CALL__*/
     
        case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*) evt;
            switch (alert->result)
            {
                case MMI_ALERT_NORMAL_EXIT:
                case MMI_ALERT_INTERRUPT_EXIT:
                case MMI_ALERT_NO_SHOW:
                case MMI_ALERT_CNFM_NO:
                case MMI_ALERT_CNFM_CANCEL:
                    mmi_clog_act_alt_dismiss((mmi_clog_op_inst_struct*) evt->user_data, alert->alert_id);
                    break;

                case MMI_ALERT_CNFM_YES:
                    mmi_clog_act_evt_alert_yes_hdlr(evt);
                    break;

        default:
            break;
    }
        }
            break;            
#endif 
        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_op_evt_mm_entry_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
void mmi_clog_op_evt_mm_entry_hdlr(cui_menu_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_CLOG_FPBW__
    cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
#endif /*__MMI_CLOG_FPBW__*/

#ifdef __MMI_CLOG_TAB_SUPPORT__
    cui_menu_set_non_leaf_item(evt->sender_id, MENU_ID_CLOG_ADVANCED, MMI_FALSE);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_op_evt_mm_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
void mmi_clog_op_evt_mm_select_hdlr(cui_menu_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
    U32 mid;
#endif/* __MMI_CLOG_SLIM_FOR_MT6261__ */
    mmi_clog_op_inst_struct *inst;
#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
    mmi_clog_act_para_struct para;
#endif/* __MMI_CLOG_SLIM_FOR_MT6261__ */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inst = (mmi_clog_op_inst_struct*) evt->user_data;
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
    inst->op_mid = mmi_clog_op_get_mid_by_menu_id(evt->highlighted_menu_id);
    mmi_clog_act_run(inst);
#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    mid = mmi_clog_op_get_mid_by_menu_id(evt->highlighted_menu_id);
	
    para.handle = inst->handle;
    para.log_id = inst->log_id;
    para.sel_lt_id = inst->sel_lt_id;
    para.op_mid = (mmi_clog_op_mid_enum)mid;
	para.flags = 0;
#if defined (__MMI_VUI_HOMESCREEN__)
    if (inst->type == MMI_CLOG_OP_TYPE_VUI)
        MMI_CLOG_SET_BIT(para.flags, MMI_CLOG_ACT_FLAG_PURE_VIEW);
#endif /* __MMI_VUI_HOMESCREEN__ */

    MMI_CLOG_IT_TRACE((
        MMI_CLOG_TRC_INFO,
        TRC_MMI_CLOG_OP_EVT_MM_SELECT_HDLR,
        inst->parent_gid,
        inst->self_gid,
        inst->sel_lt_id,
        mid,
        inst->handle,
        inst->log_id));

    mmi_clog_act_proc(inst->parent_gid, &para);
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_op_evt_mm_close_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
void mmi_clog_op_evt_mm_close_hdlr(cui_menu_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_op_inst_struct *inst = evt->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!MMI_CLOG_IS_INST_VALID(inst, MMI_CLOG_INST_TYPE_OP))
        return ;

    cui_menu_close(inst->mc_gid);
    inst->mc_gid = GRP_ID_INVALID;
}

#endif /* __MMI_TELEPHONY_SUPPORT__ || __MMI_BT_PBAP_CLIENT__ */


