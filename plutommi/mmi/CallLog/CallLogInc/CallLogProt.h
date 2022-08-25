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
 *  CallLogProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef MMI_CALL_LOG_PROT_H
#define MMI_CALL_LOG_PROT_H

/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMI_features.h"
/* System service layer */

/* FRM layer */
#include "GlobalResDef.h"
#include "wgui_categories_list.h"
#include "MMIDataType.h"
#include "mmi_res_range_def.h"
#include "kal_general_types.h"
#include "app_datetime.h"
#include "AlertScreen.h"
#include "mmi_frm_events_gprot.h"
/* External service layer */

/* External APP layer */

/* External CUI layer */

/* Internal service layer */
#include "CallLogSrvGprot.h"

/* Internal APP layer */
#include "CallLogGprot.h"
#include "CallLogConfig.h"
#include "PbapSrvGprot.h"




/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/
#define  MMI_CLOG_MAX(a, b)                          ((a) > (b) ? (a) : (b))
#define  MMI_CLOG_MAX3(a, b, c)                      (MMI_CLOG_MAX(a, MMI_CLOG_MAX(b, c)))
#define  MMI_CLOG_ROUND(max_size, seg_size)          (((max_size) + (seg_size) - 1) / (seg_size))

#define  MMI_CLOG_IS_GID_INVALID(gid)                ((gid) == GRP_ID_INVALID)
#define  MMI_CLOG_CHECK_BIT(flag, bit)               ((flag) & (bit))
#define  MMI_CLOG_SET_BIT(flag, bit)                 ((flag) |= (bit))
#define  MMI_CLOG_CLEAR_BIT(flag, bit)               ((flag) &= ~(bit))

#define  MMI_CLOG_IDX2BIT(idx)                       ((0x01) << (idx))

#define MMI_CLOG_BIT2IDX(bit)                        (mmi_clog_bit2idx(bit))

#define MMI_CLOG_IS_INST_VALID(inst, type)           (inst && MMI_CLOG_CHECK_BIT((inst)->flags, (MMI_CLOG_CMN_INST_FLAG_IS_USED|(type))))

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/

typedef FuncPtr MMI_CLOG_KEY_HDLR;

/*----------------------------------------------------------------------------*/
/* Constants                                                                  */
/*----------------------------------------------------------------------------*/

#define MMI_CLOG_TMP_BUF_LEN                         (255)
#define MMI_CLOG_TMP_BUF_SIZE                        (MMI_CLOG_TMP_BUF_LEN * ENCODING_LENGTH + ENCODING_LENGTH)

#define MMI_CLOG_CMN_INST_FLAG_BASE                  (8)
#define MMI_CLOG_CMN_INST_FLAG_IS_USED               (0x0001 << MMI_CLOG_CMN_INST_FLAG_BASE)
#define MMI_CLOG_CMN_INST_FLAG_EXT_HANDLE            (0x0002 << MMI_CLOG_CMN_INST_FLAG_BASE)
#define MMI_CLOG_CMN_INST_FLAG_TYPE_BASE             (2 + MMI_CLOG_CMN_INST_FLAG_BASE)

#define  MMI_CLOG_LT_CLT_IMG_MAX_NUM                 (SRV_CLOG_CLT_IDX_ALL)

/* context flags */
//#define MMI_CLOG_CNTX_FLAG_IS_INIT                 (0x0001)
#define MMI_CLOG_CNTX_FLAG_IS_READY                  (0x0002)
#define MMI_CLOG_CNTX_FLAG_NEED_WIPE_DATA            (0x0004)
#define MMI_CLOG_CNTX_FLAG_HAS_NEW_EVENT             (0x0008)

#define MMI_CLOG_ALERT_FLAG_AUTO_DISMISS             (0x0001)
#define MMI_CLOG_ALERT_FLAG_HIDE_CSK                 (0x0002)
#define MMI_CLOG_ALERT_FLAG_ENTER_HISTORY            (0x0004)

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/
/* Add compile option to it as use it as array index for slim */
typedef enum
{
    MMI_CLOG_GRP_TYPE_NM,
    MMI_CLOG_GRP_TYPE_MM,
    MMI_CLOG_GRP_TYPE_LT,
    MMI_CLOG_GRP_TYPE_VR,
    MMI_CLOG_GRP_TYPE_OP,
    MMI_CLOG_GRP_TYPE_ACT,

#ifdef __MMI_CLOG_CALL_TIME__    
    MMI_CLOG_GRP_TYPE_CTIME,
#endif

#ifdef __MMI_CLOG_CALL_COST__
    MMI_CLOG_GRP_TYPE_CCOST,
#endif

#ifdef __MMI_CLOG_SMS_COUNT__
    MMI_CLOG_GRP_TYPE_SMS_COUNT,
#endif

#ifdef __MMI_CLOG_GPRS_COUNT__
    MMI_CLOG_GRP_TYPE_GPRS_COUNT,
#endif
    MMI_CLOG_GRP_MAX_ITEM
} mmi_clog_grp_type_enum;

typedef enum
{
    MMI_CLOG_INST_TYPE_CLOG = 0x0001 << MMI_CLOG_CMN_INST_FLAG_TYPE_BASE,
    MMI_CLOG_INST_TYPE_LT = 0x0002 << MMI_CLOG_CMN_INST_FLAG_TYPE_BASE,
    MMI_CLOG_INST_TYPE_VR = 0x0004 << MMI_CLOG_CMN_INST_FLAG_TYPE_BASE,
    MMI_CLOG_INST_TYPE_OP = 0x0008 << MMI_CLOG_CMN_INST_FLAG_TYPE_BASE,
    MMI_CLOG_INST_TYPE_ACT = 0x0010 << MMI_CLOG_CMN_INST_FLAG_TYPE_BASE,
    MMI_CLOG_INST_TYPE_MAX_ITEM
} mmi_clog_inst_type_enum;


typedef enum
{
    MMI_CLOG_KEY_LSK,
    MMI_CLOG_KEY_CSK,
    MMI_CLOG_KEY_RSK,
    MMI_CLOG_KEY_SOFTKEY_MAX_ITEM,
    MMI_CLOG_KEY_SEND = MMI_CLOG_KEY_SOFTKEY_MAX_ITEM,
#ifdef __MMI_IP_KEY__
/* under construction !*/
#endif
    MMI_CLOG_KEY_MAX_ITEM
} mmi_clog_key_enum;

typedef enum
{
    MMI_CLOG_LT_TYPE_LIST,
    MMI_CLOG_LT_TYPE_TAB,
    MMI_CLOG_LT_TYPE_MAX_ITEM
} mmi_clog_lt_type_enum;

/* best not to modify the orders */
typedef enum
{
    MMI_CLOG_LT_ID_DIALED_CALL,
    MMI_CLOG_LT_ID_MISSED_CALL,
    MMI_CLOG_LT_ID_RECVED_CALL,
#ifndef __MMI_CLOG_COMPUND_ACTION_REJECT_CALL__
    MMI_CLOG_LT_ID_REJED_CALL,
#endif /*__MMI_CLOG_COMPUND_ACTION_REJECT_CALL__*/
    MMI_CLOG_LT_ID_ALL_CALL,
    MMI_CLOG_LT_ID_UNKNOWN,
    MMI_CLOG_LT_ID_MAX_ITEM = MMI_CLOG_LT_ID_UNKNOWN    /* Only use in lauch to enter the mainmenu */
} mmi_clog_lt_id_enum;

/*app for bt dialer*/
#ifdef __MMI_BT_PBAP_CLIENT__
    typedef enum
    {
    #ifdef __MMI_TELEPHONY_SUPPORT__
        MMI_CLOG_LT_ID_LOCAL,
    #endif
    #if SRV_PBAPC_LINK_NUM >= 2
        MMI_CLOG_LT_ID_BT_V3,
    #endif
        MMI_CLOG_LT_ID_BT
    }
    mmi_clog_lt_bt_id_enum;
#endif

/* Add compile option to this enum as use it as array index to slim */
typedef enum
{
    MMI_CLOG_OP_TYPE_LT_LIST,
    MMI_CLOG_OP_TYPE_LIST_VIEWER,

#ifdef __MMI_CLOG_TAB_SUPPORT__
    MMI_CLOG_OP_TYPE_LT_TAB,
    MMI_CLOG_OP_TYPE_TAB_VIEWER,
#endif /* __MMI_CLOG_TAB_SUPPORT__ */ 

#if defined (__MMI_VUI_HOMESCREEN__)
    MMI_CLOG_OP_TYPE_VUI,
#endif    
    MMI_CLOG_OP_TYPE_MAX_ITEM
} mmi_clog_op_type_enum;

/* Define this just to slim g_mmi_clog_op_menu_map_tbl[]*/
typedef enum
{
    MMI_CLOG_OP_MID_IDX_NONE = 0x0000,
    MMI_CLOG_OP_MID_IDX_VIEW = MMI_CLOG_ACT_VIEW,
    MMI_CLOG_OP_MID_IDX_MAKE_CALL = MMI_CLOG_ACT_MAKE_CALL,
    MMI_CLOG_OP_MID_IDX_SEND_MSG = MMI_CLOG_ACT_SEND_MSG,
    MMI_CLOG_OP_MID_IDX_SEND_SMS = MMI_CLOG_ACT_SEND_SMS,
    MMI_CLOG_OP_MID_IDX_SEND_MMS = MMI_CLOG_ACT_SEND_MMS,
    MMI_CLOG_OP_MID_IDX_SAVE_TO_PHB = MMI_CLOG_ACT_SAVE_TO_PHB,
    MMI_CLOG_OP_MID_IDX_ADD_TO_BLACK_LIST,
    MMI_CLOG_OP_MID_IDX_ENTER_BLACK_LIST,
    MMI_CLOG_OP_MID_IDX_MAKE_IP_CALL,
    MMI_CLOG_OP_MID_IDX_DELETE,
    MMI_CLOG_OP_MID_IDX_DELETE_ALL,
    MMI_CLOG_OP_MID_IDX_CLEAR_EVENT,
#ifndef __MMI_CLOG_COMPUND_ACTION_EDIT_BEFORE_CALL__
    MMI_CLOG_OP_MID_IDX_EDIT_BEFORE_CALL,
#endif /*__MMI_CLOG_COMPUND_ACTION_EDIT_BEFORE_CALL__*/
    MMI_CLOG_OP_MID_IDX_CLEAR_ALL_LOG_EVENTS,
    MMI_CLOG_OP_MID_IDX_GOTO,
    MMI_CLOG_OP_MID_IDX_ADVANCED,
    MMI_CLOG_OP_MID_IDX_CLEAR_ALL_EVENTS,
    MMI_CLOG_OP_MID_IDX_MARK_SEVERAL,

	/* For CMCC sim filter */

#ifdef __MMI_CLOG_SIM_FILTER__
    
    MMI_CLOG_OP_MID_IDX_SEL_SIM_1,
 #ifdef __MMI_DUAL_SIM__
/* under construction !*/
 #endif

 #if (MMI_MAX_SIM_NUM >= 3)
    MMI_CLOG_OP_MID_IDX_SEL_SIM_3,
 #endif

 #if (MMI_MAX_SIM_NUM >= 4)
    MMI_CLOG_OP_MID_IDX_SEL_SIM_4,
 #endif
    MMI_CLOG_OP_MID_IDX_SEL_SIM_ALL,

#endif /*__MMI_CLOG_SIM_FILTER__*/

    MMI_CLOG_OP_MID_IDX_MAX_ITEM
} mmi_clog_op_mid_idx_enum;

typedef enum
{
    MMI_CLOG_OP_MID_NONE                        = 0x0000,
    MMI_CLOG_OP_MID_VIEW                        = MMI_CLOG_IDX2BIT(MMI_CLOG_ACT_VIEW),
    MMI_CLOG_OP_MID_MAKE_CALL                   = MMI_CLOG_IDX2BIT(MMI_CLOG_ACT_MAKE_CALL),
    MMI_CLOG_OP_MID_SEND_MSG                    = MMI_CLOG_IDX2BIT(MMI_CLOG_ACT_SEND_MSG),
    MMI_CLOG_OP_MID_SEND_SMS                    = MMI_CLOG_IDX2BIT(MMI_CLOG_ACT_SEND_SMS),
    MMI_CLOG_OP_MID_SEND_MMS                    = MMI_CLOG_IDX2BIT(MMI_CLOG_ACT_SEND_MMS),
    MMI_CLOG_OP_MID_SAVE_TO_PHB                 = MMI_CLOG_IDX2BIT(MMI_CLOG_ACT_SAVE_TO_PHB),
    MMI_CLOG_OP_MID_ADD_TO_BLACK_LIST           = MMI_CLOG_IDX2BIT(MMI_CLOG_OP_MID_IDX_ADD_TO_BLACK_LIST),
    MMI_CLOG_OP_MID_ENTER_BLACK_LIST            = MMI_CLOG_IDX2BIT(MMI_CLOG_OP_MID_IDX_ENTER_BLACK_LIST),
    MMI_CLOG_OP_MID_MAKE_IP_CALL                = MMI_CLOG_IDX2BIT(MMI_CLOG_OP_MID_IDX_MAKE_IP_CALL),
    MMI_CLOG_OP_MID_DELETE                      = MMI_CLOG_IDX2BIT(MMI_CLOG_OP_MID_IDX_DELETE),
    MMI_CLOG_OP_MID_DELETE_ALL                  = MMI_CLOG_IDX2BIT(MMI_CLOG_OP_MID_IDX_DELETE_ALL),
    MMI_CLOG_OP_MID_CLEAR_EVENT                 = MMI_CLOG_IDX2BIT(MMI_CLOG_OP_MID_IDX_CLEAR_EVENT),
#ifndef __MMI_CLOG_COMPUND_ACTION_EDIT_BEFORE_CALL__
    MMI_CLOG_OP_MID_EDIT_BEFORE_CALL            = MMI_CLOG_IDX2BIT(MMI_CLOG_OP_MID_IDX_EDIT_BEFORE_CALL),
#endif /*__MMI_CLOG_COMPUND_ACTION_EDIT_BEFORE_CALL__*/
    MMI_CLOG_OP_MID_CLEAR_ALL_LOG_EVENTS        = MMI_CLOG_IDX2BIT(MMI_CLOG_OP_MID_IDX_CLEAR_ALL_LOG_EVENTS),
    MMI_CLOG_OP_MID_GOTO                        = MMI_CLOG_IDX2BIT(MMI_CLOG_OP_MID_IDX_GOTO),
    MMI_CLOG_OP_MID_ADVANCED                    = MMI_CLOG_IDX2BIT(MMI_CLOG_OP_MID_IDX_ADVANCED),
    MMI_CLOG_OP_MID_CLEAR_ALL_EVENTS            = MMI_CLOG_IDX2BIT(MMI_CLOG_OP_MID_IDX_CLEAR_ALL_EVENTS),
    MMI_CLOG_OP_MID_MARK_SEVERAL                = MMI_CLOG_IDX2BIT(MMI_CLOG_OP_MID_IDX_MARK_SEVERAL),

	/* For CMCC sim filter */
	
#ifdef __MMI_CLOG_SIM_FILTER__

	MMI_CLOG_OP_MID_SEL_SIM_1                   = MMI_CLOG_IDX2BIT(MMI_CLOG_OP_MID_IDX_SEL_SIM_1),
#ifdef __MMI_DUAL_SIM__
/* under construction !*/
#endif

#if (MMI_MAX_SIM_NUM >= 3)
    MMI_CLOG_OP_MID_SEL_SIM_3                   = MMI_CLOG_IDX2BIT(MMI_CLOG_OP_MID_IDX_SEL_SIM_3),
#endif

#if (MMI_MAX_SIM_NUM >= 4)
    MMI_CLOG_OP_MID_SEL_SIM_4                   = MMI_CLOG_IDX2BIT(MMI_CLOG_OP_MID_IDX_SEL_SIM_4),
#endif

    MMI_CLOG_OP_MID_SEL_SIM_ALL                 = MMI_CLOG_IDX2BIT(MMI_CLOG_OP_MID_IDX_SEL_SIM_ALL),

#endif /*__MMI_CLOG_SIM_FILTER__*/
    
    MMI_CLOG_OP_MID_MAX_ITEM
} mmi_clog_op_mid_enum;

/*----------------------------------------------------------------------------*/
/* typedef in structure                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/
typedef struct
{
    MMI_STR_ID str_id;
    MMI_IMG_ID img_id;
} mmi_clog_key_struct;

typedef struct
{
    const mmi_clog_key_struct *softkey[MMI_CLOG_KEY_SOFTKEY_MAX_ITEM];
    const MMI_CLOG_KEY_HDLR hdlr[MMI_CLOG_KEY_MAX_ITEM];
} mmi_clog_key_tbl_struct;

typedef struct
{
    srv_clog_clt_enum clt_type;
    MMI_IMG_ID img_id;
} mmi_clog_lt_clt_img_map_struct;

typedef struct
{
    mmi_sim_enum sim_id;
    srv_clog_call_type_enum call_type;
    mmi_clog_lt_clt_img_map_struct img_map[MMI_CLOG_LT_CLT_IMG_MAX_NUM];
} mmi_clog_lt_clt_img_struct;

typedef struct
{
    U32 total_num;
    const mmi_clog_lt_clt_img_struct *img_list;
} mmi_clog_lt_img_tbl_struct;

typedef struct
{
    mmi_clog_lt_id_enum lt_id;
    MMI_MENU_ID menu_id;
    srv_clog_log_identity_struct idt;   /* may add other attrs */
} mmi_clog_lt_id_attr_struct;

typedef struct
{
    U32 total_num;
    const mmi_clog_lt_id_attr_struct *attrs[MMI_CLOG_LT_ID_MAX_NUM];
} mmi_clog_lt_id_attr_tbl_struct;

typedef struct
{
    U16 total_num;
    mmi_clog_lt_id_enum lt_ids[MMI_CLOG_LT_ID_MAX_NUM];
} mmi_clog_lt_enb_ids_struct;

typedef struct
{
    U16 tab_num;
    mmi_clog_lt_id_enum lt_ids[MMI_CLOG_LT_ID_MAX_NUM];
}mmi_clog_tab_id_struct;

#ifdef __MMI_BT_PBAP_CLIENT__
typedef struct
{
    U16 tab_num;
#if SRV_PBAPC_LINK_NUM >= 2
#ifndef __MMI_TELEPHONY_SUPPORT__
    mmi_clog_lt_bt_id_enum lt_ids[SRV_PBAPC_LINK_NUM];
#else
    mmi_clog_lt_bt_id_enum lt_ids[SRV_PBAPC_LINK_NUM + 1];
#endif
#else
    mmi_clog_lt_bt_id_enum lt_ids[2];
#endif
}mmi_clog_bt_tab_id_struct;
#endif

typedef struct
{
    U16 flags;

    MMI_ID self_gid;
    MMI_ID mm_gid;  /* main menu group id */
    MMI_ID alert_gid;
    MMI_MENU_ID sel_menu_id;
    mmi_clog_lt_type_enum lt_type;
    mmi_clog_lt_id_enum sel_lt_id;

    SRV_CLOG_HANDLE handle;
    S32 srv_pid;
} mmi_clog_inst_struct;

typedef struct
{
    U16 flags;
    mmi_clog_inst_struct inst_list[MMI_CLOG_INST_MAX_NUM];
} mmi_clog_cntx_struct;

/******************** Calllog Option *************************/
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
typedef struct
{
    U32 flags;
    SRV_CLOG_HANDLE handle;
    SRV_CLOG_ID log_id;
    mmi_clog_lt_id_enum sel_lt_id;
    mmi_clog_op_type_enum type;    
    mmi_clog_op_mid_enum op_mid;    
} mmi_clog_op_para_struct;

typedef struct
{
    U16 flags;
    MMI_ID parent_gid;
    MMI_ID self_gid;
    MMI_ID sub_gid; /* for phb_cui/dialed/cui... */
    MMI_ID mc_gid;
    mmi_clog_op_type_enum type;
    mmi_clog_lt_id_enum sel_lt_id;
    SRV_CLOG_HANDLE handle;
    SRV_CLOG_ID log_id; /* if 0, means empty */
    mmi_clog_op_mid_enum op_mid;
    void *phb_udata;
    S32 pid;
} mmi_clog_op_inst_struct;

typedef struct
{
    mmi_clog_op_inst_struct inst_list[MMI_CLOG_OP_INST_MAX_NUM];
} mmi_clog_op_cntx_struct;

#else

typedef struct
{
    mmi_clog_op_type_enum type;
    mmi_clog_lt_id_enum sel_lt_id;
    SRV_CLOG_HANDLE handle;
    SRV_CLOG_ID log_id;
    U32 flags;
} mmi_clog_op_para_struct;

typedef struct
{
    SRV_CLOG_HANDLE handle;
    SRV_CLOG_ID log_id;
    mmi_clog_lt_id_enum sel_lt_id;
    mmi_clog_op_mid_enum op_mid;
    U32 flags;
} mmi_clog_act_para_struct;
#endif

/******************** Calllog Event *************************/
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
    mmi_clog_op_mid_enum op_mid;
    SRV_CLOG_ID log_id;
    mmi_clog_lt_id_enum sel_lt_id;
} mmi_clog_act_evt_start_apply_struct;

typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
    mmi_clog_op_mid_enum op_mid;
    SRV_CLOG_ID log_id;
    mmi_clog_lt_id_enum sel_lt_id;
} mmi_clog_act_evt_apply_done_struct;

/*----------------------------------------------------------------------------*/
/* Extern Global Variable                                                     */
/*----------------------------------------------------------------------------*/
extern const mmi_clog_key_struct g_mmi_clog_csk_common;
extern const mmi_clog_key_struct g_mmi_clog_csk_call;
extern const mmi_clog_key_struct g_mmi_clog_lsk_option;
extern const mmi_clog_key_struct g_mmi_clog_rsk_back;

extern const mmi_clog_lt_img_tbl_struct g_mmi_clog_lt_img_tbl;
extern const mmi_clog_lt_id_attr_tbl_struct g_mmi_clog_lt_id_attr_tbl;
extern const mmi_clog_lt_enb_ids_struct g_mmi_clog_lt_enb_ids;
#ifdef __MMI_BT_PBAP_CLIENT__
extern const mmi_clog_bt_tab_id_struct g_mmi_clog_bt_link_tab_id;
#endif
/*----------------------------------------------------------------------------*/
/* Extern Function                                                            */
/*----------------------------------------------------------------------------*/

/*---------------------- Config ----------------------------------------------*/
extern void mmi_clog_check_cfg_data(void);
extern const mmi_clog_lt_id_attr_struct *mmi_clog_get_attr_by_lt_id(mmi_clog_lt_id_enum lt_id);
extern const mmi_clog_lt_id_attr_struct *mmi_clog_get_attr_by_menu_id(MMI_MENU_ID menu_id);
extern MMI_IMG_ID mmi_clog_get_image(const srv_clog_log_identity_struct *idt);

/*---------------------- Misc ------------------------------------------------*/
extern void mmi_clog_print(CHAR *format, ...);
extern WCHAR *mmi_clog_w_cpy(WCHAR *dst, const WCHAR *src, U32 dst_len);

extern U32 mmi_clog_bit2idx(U32 bit);
extern S32 mmi_clog_is_cid_empty(srv_clog_log_struct *log);
extern S32 mmi_clog_is_name_empty(srv_clog_log_struct *log);

extern void mmi_clog_time_utc2app(U32 timestamp, applib_time_struct *app_time);
extern void mmi_clog_duration_val2app(U32 duration, U32 *hour, U32 *min, U32 *sec);
extern MMI_ID mmi_clog_alloc_gid(mmi_clog_grp_type_enum type);
extern MMI_ID mmi_clog_get_valid_act_gid(void);
extern S32 mmi_clog_is_scrn_in_active(MMI_ID gid, MMI_ID scrn_id);
extern void *mmi_clog_get_inst_by_act_gid(void);
extern MMI_ID mmi_clog_confirm(
                mmi_confirm_type_enum type,
                MMI_STR_ID str_id,
                mmi_event_notify_enum evt,
                MMI_ID parent_gid,
                void *user_data,
                U32 flags);

extern MMI_ID mmi_clog_popup(MMI_STR_ID str_id, mmi_event_notify_enum evt, MMI_ID parent_gid, void *user_data);

extern void mmi_clog_update_status_icon(void);

#ifdef __MMI_CLOG_CALL_COST__
extern void mmi_clog_check_cphs_service(MMI_ID menu_gid);
#endif

extern void mmi_clog_update_mini_tab_bar(void);

extern MMI_STR_ID mmi_clog_get_clt_str_id(srv_clog_clt_enum clt);

/*---------------------- Context ---------------------------------------------*/
extern S32 mmi_clog_is_ready(void);
extern void mmi_clog_receive_new_event(void);
extern void mmi_clog_clear_all_new_events(void);

mmi_clog_cntx_struct *mmi_clog_get_cntx(void);

#ifdef __MMI_CLOG_EVENT_REFRESH_SUPPORT__
/*---------------------- Event refresh ---------------------------------------*/
extern MMI_RET mmi_clog_mm_srv_evt_hdlr(mmi_event_struct *evt);
extern MMI_RET mmi_clog_lt_srv_evt_hdlr(mmi_event_struct *evt);

#endif /* __MMI_CLOG_EVENT_REFRESH_SUPPORT__ */

/*---------------------- Main menu -------------------------------------------*/
extern void mmi_clog_launch_ex(MMI_ID parent_gid, mmi_clog_lt_type_enum lt_type, mmi_clog_lt_id_enum lt_id);

/*---------------------- Action ----------------------------------------------*/
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
MMI_ID mmi_clog_op_run(MMI_ID parent_gid, mmi_clog_op_para_struct *para);
#else
void mmi_clog_act_init_para(mmi_clog_act_para_struct *para);
MMI_ID mmi_clog_act_proc(MMI_ID parent_gid, mmi_clog_act_para_struct *para);
#endif

/*---------------------- Option ----------------------------------------------*/
extern MMI_RET mmi_clog_op_init_para(mmi_clog_op_para_struct *para);
extern MMI_ID mmi_clog_op_enter(MMI_ID parent_gid, mmi_clog_op_para_struct *para);


/*---------------------- Sub Modules -----------------------------------------*/
#ifdef __MMI_CLOG_ACCESSORIES__

typedef struct
{
    mmi_sim_enum sim_id;
    MMI_MENU_ID menu_id;
} mmi_clog_sub_menu_map_struct;

#ifdef __MMI_CLOG_TAB_SUPPORT__
extern void mmi_clog_enter_advanced(MMI_ID parent_gid);
#endif 

extern S32 mmi_clog_enter_accessories(MMI_MENU_ID menu_id, MMI_ID parent_gid);

#ifdef __MMI_CLOG_CALL_TIME__
extern void mmi_clog_enter_ctime(MMI_ID parent_gid);
#endif

#ifdef __MMI_CLOG_CALL_COST__
extern void mmi_clog_enter_ccost(MMI_ID parent_gid);
#endif

#ifdef __MMI_CLOG_SMS_COUNT__
extern void mmi_clog_enter_sms_counter(MMI_ID parent_gid);
#endif

#ifdef __MMI_CLOG_GPRS_COUNT__
extern void mmi_clog_enter_gprs_counter(MMI_ID parent_gid);
#endif 

#endif /* __MMI_CLOG_ACCESSORIES__ */

#ifdef __MMI_BT_PBAP_CLIENT__
extern void mmi_clog_pbapc_select_hdlr(MMI_MENU_ID sel_menu_id, MMI_ID gid);
extern MMI_BOOL g_only_update_data;
extern void mmi_clog_pbapc_show_category(S32 error_code, U8 *gui_buffer);

extern void mmi_clog_pbapc_processing_abort(void);
//extern srv_phb_pbap_storage_enum mmi_clog_pbapc_menu_to_storage_path(MMI_MENU_ID sel_menu_id);
//extern void mmi_clog_pbapc_processing_show_ex(MMI_ID parent_id, mmi_clog_pbapc_op_type_enum type, srv_phb_pbap_storage_enum sel_lt_storage);


#endif

#ifndef __MMI_CLOG_COMPUND_ACTION_EDIT_BEFORE_CALL__
extern void mmi_clog_act_dlr_evt_dialer_before_call_hdlr(mmi_event_struct *evt);
extern void mmi_clog_act_dlr_free_phb_udata(MMI_ID dlr_gid);
#endif /*__MMI_CLOG_COMPUND_ACTION_EDIT_BEFORE_CALL__*/

#endif /* MMI_CALL_LOG_PROT_H */ 

