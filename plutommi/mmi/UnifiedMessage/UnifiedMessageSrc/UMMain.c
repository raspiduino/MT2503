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
 * UMMain.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"
#ifdef __UM_SUPPORT__
#include "UMGProt.h"
#include "UMDefs.h"
#include "UmSrvStruct.h"
#include "UMProt.h"
#include "UMSrvGprot.h"
#include "mmi_rp_app_unifiedmessage_def.h"
#include "MessagesMiscell.h"
#include "Mms_api.h"


#include "IdleNotificationManagerGprot.h"
#include "SimCtrlSrvGprot.h"
#include "NetworkSetupDefs.h"
#include "UmSrvDefs.h"
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "kal_general_types.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "string.h"
#include "NetSetSrvGprot.h"
#include "NetSetAppGprot.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "mmi_common_app_trc.h"

/* UI Global variables */
mmi_um_ui_cntx_struct g_um_ui_cntx;
mmi_um_ui_cntx_struct *g_um_ui_p = &g_um_ui_cntx;
srv_um_msg_info_struct *g_um_ui_msg_info_buf_p[MMI_UM_UI_MAX_MSG_INFO_NUM];
#ifdef __MMI_UM_CONVERSATION_BOX__
srv_um_thread_info_struct *g_um_ui_thread_info_buf_p[MMI_UM_UI_MAX_MSG_INFO_NUM];

#endif /* __MMI_UM_CONVERSATION_BOX__ */
#ifdef __MMI_UM_EL_FSM_SUPPORT__
typedef enum
{
    MMI_UM_EL_FSM_DUMMY,

    MMI_UM_EL_FSM_INIT_INIT,
        
    MMI_UM_EL_FSM_INSIDE_REF,
    MMI_UM_EL_FSM_INSIDE_CHECK,
    MMI_UM_EL_FSM_INSIDE_UNREADY,
    
    MMI_UM_EL_FSM_UPDATE_ABORT,
    MMI_UM_EL_FSM_UPDATE_DELETE,
    MMI_UM_EL_FSM_UPDATE_CHECK,
    MMI_UM_EL_FSM_UPDATE_READY,
    MMI_UM_EL_FSM_UPDATE_UNREADY
} mmi_um_el_fsm_event_handler_enum;

const mmi_um_ui_fsm_event_hdlr_node fsm_el_tb[] = 
{
    mmi_um_ui_fsm_eh_dummy,
        
    mmi_um_ui_fsm_el_eh_init_init, 

    mmi_um_ui_fsm_el_eh_inside_refresh,
    mmi_um_ui_fsm_el_eh_inside_check,
    mmi_um_ui_fsm_el_eh_inside_unready,
    
    mmi_um_ui_fsm_el_eh_update_abort, 
    mmi_um_ui_fsm_el_eh_update_delete, 
    mmi_um_ui_fsm_el_eh_update_check, 
    mmi_um_ui_fsm_el_eh_update_ready, 
    mmi_um_ui_fsm_el_eh_update_unready 
};
const U8 g_um_ui_fsm_el_event_table[MMI_UM_UI_FSM_EVENT_TOTAL][MMI_UM_UI_FSM_EL_TOTAL] = 
{
    {MMI_UM_EL_FSM_INIT_INIT,       MMI_UM_EL_FSM_DUMMY,            MMI_UM_EL_FSM_DUMMY}, 
    {MMI_UM_EL_FSM_DUMMY,           MMI_UM_EL_FSM_INSIDE_REF,       MMI_UM_EL_FSM_DUMMY}, 
    {MMI_UM_EL_FSM_DUMMY,           MMI_UM_EL_FSM_DUMMY,            MMI_UM_EL_FSM_UPDATE_ABORT}, 
    {MMI_UM_EL_FSM_DUMMY,           MMI_UM_EL_FSM_DUMMY,            MMI_UM_EL_FSM_UPDATE_DELETE}, 
    {MMI_UM_EL_FSM_DUMMY,           MMI_UM_EL_FSM_INSIDE_CHECK,     MMI_UM_EL_FSM_UPDATE_CHECK}, 
    {MMI_UM_EL_FSM_DUMMY,           MMI_UM_EL_FSM_DUMMY,            MMI_UM_EL_FSM_UPDATE_READY}, 
    {MMI_UM_EL_FSM_DUMMY,           MMI_UM_EL_FSM_INSIDE_UNREADY,   MMI_UM_EL_FSM_UPDATE_UNREADY}, 
};
#endif /* __MMI_UM_EL_FSM_SUPPORT__ */

typedef enum
{
    MMI_UM_EF_FSM_DUMMY,
    MMI_UM_EF_FSM_INIT_INIT,
    MMI_UM_EF_FSM_INIT_DEL,
    MMI_UM_EF_FSM_INIT_KEP,
    
    MMI_UM_EF_FSM_CR_DELETE,
    MMI_UM_EF_FSM_CR_CHECK,
    MMI_UM_EF_FSM_CR_READY,

    MMI_UM_EF_FSM_CD_REF,
    MMI_UM_EF_FSM_CD_CHECK,
    MMI_UM_EF_FSM_CD_UNREADY,
    MMI_UM_EF_FSM_CD_UP_LIST,
    MMI_UM_EF_FSM_CD_REL_LIST,
    MMI_UM_EF_FSM_CD_DELETE,
    
    MMI_UM_EF_FSM_UD_REF,
    MMI_UM_EF_FSM_UD_DELETE,
    MMI_UM_EF_FSM_UD_CHECK,
    MMI_UM_EF_FSM_UD_UNREADY,
    MMI_UM_EF_FSM_UD_UP_LIST,
    MMI_UM_EF_FSM_UD_REL_LIST
    
} mmi_um_ef_fsm_event_handler_enum;

const mmi_um_ui_fsm_event_hdlr_node fsm_ef_tb[] = 
{
    mmi_um_ui_fsm_eh_dummy,
        
    mmi_um_ui_fsm_ef_eh_init_init, 
    mmi_um_ui_fsm_ef_eh_init_delete,
    mmi_um_ui_fsm_ef_eh_init_kp_list, 
        
    mmi_um_ui_fsm_ef_eh_cr_delete,
    mmi_um_ui_fsm_ef_eh_cr_check,
    mmi_um_ui_fsm_ef_eh_cr_ready,
    
    mmi_um_ui_fsm_ef_eh_cd_refresh, 
    mmi_um_ui_fsm_ef_eh_cd_check, 
    mmi_um_ui_fsm_ef_eh_cd_unready, 
    mmi_um_ui_fsm_ef_eh_cd_up_list,
    mmi_um_ui_fsm_ef_eh_cd_rel_list,
    mmi_um_ui_fsm_ef_eh_cd_delete,
        
    mmi_um_ui_fsm_ef_eh_ud_refresh, 
    mmi_um_ui_fsm_ef_eh_ud_delete, 
    mmi_um_ui_fsm_ef_eh_ud_check, 
    mmi_um_ui_fsm_ef_eh_ud_unready, 
    mmi_um_ui_fsm_ef_eh_ud_up_list, 
    mmi_um_ui_fsm_ef_eh_ud_rel_list
    
};

const U8 g_um_ui_fsm_ef_event_table[MMI_UM_UI_FSM_EVENT_TOTAL][MMI_UM_UI_FSM_EF_TOTAL] =
{
    {MMI_UM_EF_FSM_INIT_INIT,       MMI_UM_EF_FSM_DUMMY,     MMI_UM_EF_FSM_DUMMY,       MMI_UM_EF_FSM_DUMMY,    MMI_UM_EF_FSM_DUMMY}, 
    {MMI_UM_EF_FSM_DUMMY,           MMI_UM_EF_FSM_DUMMY,     MMI_UM_EF_FSM_CD_REF,      MMI_UM_EF_FSM_UD_REF,                      MMI_UM_EF_FSM_DUMMY}, 
    {MMI_UM_EF_FSM_DUMMY,           MMI_UM_EF_FSM_DUMMY,     MMI_UM_EF_FSM_DUMMY,       MMI_UM_EF_FSM_DUMMY,    MMI_UM_EF_FSM_DUMMY}, 
    {MMI_UM_EF_FSM_INIT_DEL,        MMI_UM_EF_FSM_CR_DELETE, MMI_UM_EF_FSM_CD_DELETE,   MMI_UM_EF_FSM_UD_DELETE,                     MMI_UM_EF_FSM_DUMMY}, 
    {MMI_UM_EF_FSM_DUMMY,           MMI_UM_EF_FSM_CR_CHECK,  MMI_UM_EF_FSM_CD_CHECK,    MMI_UM_EF_FSM_UD_CHECK,                      MMI_UM_EF_FSM_DUMMY}, 
    {MMI_UM_EF_FSM_DUMMY,           MMI_UM_EF_FSM_CR_READY,  MMI_UM_EF_FSM_DUMMY,       MMI_UM_EF_FSM_DUMMY,    MMI_UM_EF_FSM_DUMMY}, 
    {MMI_UM_EF_FSM_DUMMY,           MMI_UM_EF_FSM_DUMMY,     MMI_UM_EF_FSM_CD_UNREADY,  MMI_UM_EF_FSM_UD_UNREADY,                     MMI_UM_EF_FSM_DUMMY}, 
    {MMI_UM_EF_FSM_DUMMY,           MMI_UM_EF_FSM_DUMMY,     MMI_UM_EF_FSM_CD_REL_LIST, MMI_UM_EF_FSM_UD_REL_LIST,    MMI_UM_EF_FSM_DUMMY}, 
    {MMI_UM_EF_FSM_DUMMY,           MMI_UM_EF_FSM_DUMMY,     MMI_UM_EF_FSM_CD_UP_LIST,  MMI_UM_EF_FSM_UD_UP_LIST,    MMI_UM_EF_FSM_DUMMY}, 
    {MMI_UM_EF_FSM_INIT_KEP,        MMI_UM_EF_FSM_DUMMY,     MMI_UM_EF_FSM_DUMMY,       MMI_UM_EF_FSM_DUMMY,    MMI_UM_EF_FSM_DUMMY}, 
    {MMI_UM_EF_FSM_DUMMY,           MMI_UM_EF_FSM_DUMMY,     MMI_UM_EF_FSM_DUMMY,       MMI_UM_EF_FSM_DUMMY,    MMI_UM_EF_FSM_DUMMY}
};

#ifdef __MMI_UM_OP_FSM_SUPPORT__ 
const mmi_um_ui_fsm_event_hdlr_node fsm_op_tb[] = 
{
    mmi_um_ui_fsm_op_eh_init_init, 
    mmi_um_ui_fsm_op_eh_op_abort, 
    mmi_um_ui_fsm_op_eh_init_delete, 
    mmi_um_ui_fsm_op_eh_op_delete, 
    mmi_um_ui_fsm_op_eh_init_set_data, 
    mmi_um_ui_fsm_op_eh_op_set_data, 
    mmi_um_ui_fsm_eh_dummy
};
const U8 g_um_ui_fsm_op_event_table[MMI_UM_UI_FSM_EVENT_TOTAL][MMI_UM_UI_FSM_OP_TOTAL] =
{
    {0,     6,             6}, 
    {6,            6,             6}, 
    {6,            1,       6}, 
    {2,   3,      6}, 
    {6,            6,             6}, 
    {6,            6,             6}, 
    {6,            6,             6}, 
    {6,            6,             6}, 
    {6,            6,             6}, 
    {6,            6,             6}, 
    {4, 5,    6}
};
#endif /* __MMI_UM_OP_FSM_SUPPORT__ */

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
mmi_um_ui_ms_cntx_struct g_um_ui_ms_table;
mmi_um_ui_ms_cntx_struct *g_um_ui_ms_table_p = &g_um_ui_ms_table;
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
#ifdef __MMI_ICON_BAR_SUPPORT__
const U16 g_um_ui_sh_tb_icon_table[MMI_UM_UI_TB_FOLDER_TOTAL][MMI_UM_UI_MAX_TB_ICON] =
{
/*Inbox  */ {IMG_GLOBAL_TOOLBAR_REPLY_MESSAGE,      IMG_GLOBAL_TOOLBAR_FORWARD_MESSAGE,     IMG_GLOBAL_TOOLBAR_DELETE},
/*Draft  */ {IMG_GLOBAL_TOOLBAR_SEND_MESSAGE,       IMG_GLOBAL_TOOLBAR_EDIT,                IMG_GLOBAL_TOOLBAR_DELETE},
/*Unsent */ {IMG_GLOBAL_TOOLBAR_SEND_MESSAGE,       IMG_GLOBAL_TOOLBAR_EDIT,                IMG_GLOBAL_TOOLBAR_DELETE},
/*Sent   */ {IMG_GLOBAL_TOOLBAR_FORWARD_MESSAGE,    IMG_GLOBAL_TOOLBAR_DELETE,              0                        },
/*Archive*/ {IMG_GLOBAL_TOOLBAR_REPLY_MESSAGE,      IMG_GLOBAL_TOOLBAR_FORWARD_MESSAGE,     IMG_GLOBAL_TOOLBAR_DELETE},
/*SIM    */ {IMG_UM_COPY_TOOLBAR,                   IMG_UM_MOVE_TOOLBAR,                    IMG_GLOBAL_TOOLBAR_DELETE}, 
/*Conbox */ {IMG_GLOBAL_TOOLBAR_REPLY_MESSAGE,      IMG_GLOBAL_TOOLBAR_CALL,                IMG_GLOBAL_TOOLBAR_DELETE}, 
/*ThrdMsg*/ {IMG_GLOBAL_TOOLBAR_REPLY_MESSAGE,      IMG_GLOBAL_TOOLBAR_FORWARD_MESSAGE,     IMG_GLOBAL_TOOLBAR_DELETE},
/*Report */ {0,                                     0,                                      0                        }
};
const U16 g_um_ui_sh_tb_disable_icon_table[MMI_UM_UI_TB_FOLDER_TOTAL][MMI_UM_UI_MAX_TB_ICON] =
{
/*Inbox  */ {IMG_GLOBAL_TOOLBAR_REPLY_MESSAGE_DISABLED,     IMG_GLOBAL_TOOLBAR_FORWARD_MESSAGE_DISABLED,        IMG_GLOBAL_TOOLBAR_DELETE_DISABLED},
/*Draft  */ {IMG_GLOBAL_TOOLBAR_SEND_MESSAGE_DISABLED,      IMG_GLOBAL_TOOLBAR_EDIT_DISABLED,                   IMG_GLOBAL_TOOLBAR_DELETE_DISABLED},
/*Unsent */ {IMG_GLOBAL_TOOLBAR_SEND_MESSAGE_DISABLED,      IMG_GLOBAL_TOOLBAR_EDIT_DISABLED,                   IMG_GLOBAL_TOOLBAR_DELETE_DISABLED},
/*Sent   */ {IMG_GLOBAL_TOOLBAR_FORWARD_MESSAGE_DISABLED,   IMG_GLOBAL_TOOLBAR_DELETE_DISABLED,                 0                                 },
/*Archive*/ {IMG_GLOBAL_TOOLBAR_REPLY_MESSAGE_DISABLED,     IMG_GLOBAL_TOOLBAR_FORWARD_MESSAGE_DISABLED,        IMG_GLOBAL_TOOLBAR_DELETE_DISABLED},
/*SIM    */ {IMG_UM_DISABLED_COPY_TOOLBAR,                  IMG_UM_DISABLED_MOVE_TOOLBAR,                       IMG_GLOBAL_TOOLBAR_DELETE_DISABLED},
/*Conbox */ {IMG_GLOBAL_TOOLBAR_REPLY_MESSAGE_DISABLED,     IMG_GLOBAL_TOOLBAR_CALL_DISABLED,                   IMG_GLOBAL_TOOLBAR_DELETE_DISABLED}, 
/*ThrdMsg*/ {IMG_GLOBAL_TOOLBAR_REPLY_MESSAGE_DISABLED,     IMG_GLOBAL_TOOLBAR_FORWARD_MESSAGE_DISABLED,        IMG_GLOBAL_TOOLBAR_DELETE_DISABLED},
/*Report */ {0,                                             0,                                                  0                                 }
};
const U16 g_um_ui_sh_tb_str_table[MMI_UM_UI_TB_FOLDER_TOTAL][MMI_UM_UI_MAX_TB_ICON] =
{
/*Inbox  */ {STR_GLOBAL_REPLY,      STR_GLOBAL_FORWARD,     STR_GLOBAL_DELETE},
/*Draft  */ {STR_GLOBAL_SEND,       STR_GLOBAL_EDIT,        STR_GLOBAL_DELETE},
/*Unsent */ {STR_GLOBAL_RESEND,     STR_GLOBAL_EDIT,        STR_GLOBAL_DELETE},
/*Sent   */ {STR_GLOBAL_FORWARD,    STR_GLOBAL_DELETE,      0                },
/*Archive*/ {STR_GLOBAL_REPLY,      STR_GLOBAL_FORWARD,     STR_GLOBAL_DELETE},
/*SIM    */ {STR_UM_COPY_ID,        STR_UM_MOVE_ID,         STR_GLOBAL_DELETE},
/*Conbox */ {STR_GLOBAL_REPLY,      STR_GLOBAL_DIAL,        STR_GLOBAL_DELETE}, 
/*ThrdMsg*/ {STR_GLOBAL_REPLY,      STR_GLOBAL_FORWARD,     STR_GLOBAL_DELETE},
/*Report */ {0,                     0,                      0                }
};
const mmi_um_ui_sh_tb_action_cb g_um_ui_sh_tb_action_table[MMI_UM_UI_TB_FOLDER_TOTAL][MMI_UM_UI_MAX_TB_ICON] =
{
/*Inbox  */ {mmi_um_ui_sh_general_folder_tb_reply,      mmi_um_ui_sh_general_folder_tb_forward,    mmi_um_ui_sh_general_folder_tb_delete},
/*Draft  */ {mmi_um_ui_sh_general_folder_tb_send,       mmi_um_ui_sh_general_folder_tb_edit,       mmi_um_ui_sh_general_folder_tb_delete},
/*Unsent */ {mmi_um_ui_sh_general_folder_tb_resend,     mmi_um_ui_sh_general_folder_tb_edit,       mmi_um_ui_sh_general_folder_tb_delete},
/*Sent   */ {mmi_um_ui_sh_general_folder_tb_forward,    mmi_um_ui_sh_general_folder_tb_delete,     NULL                                 },
/*Archive*/ {mmi_um_ui_sh_general_folder_tb_reply,      mmi_um_ui_sh_general_folder_tb_forward,    mmi_um_ui_sh_general_folder_tb_delete},
/*SIM    */ {mmi_um_ui_sh_general_folder_tb_copy,       mmi_um_ui_sh_general_folder_tb_move,       mmi_um_ui_sh_general_folder_tb_delete}, 
/*Conbox */ {mmi_um_ui_sh_cs_tb_reply,                  mmi_um_ui_sh_cs_tb_call,                   mmi_um_ui_sh_cs_tb_delete}, 
/*ThrdMsg*/ {mmi_um_ui_sh_general_folder_tb_reply,      mmi_um_ui_sh_general_folder_tb_forward,    mmi_um_ui_sh_general_folder_tb_delete},
/*Report */ {NULL,                                      NULL,                                      NULL                                 }
};
const mmi_um_ui_sh_tb_check_action_cb g_um_ui_sh_tb_check_action_table[MMI_UM_UI_TB_FOLDER_TOTAL][MMI_UM_UI_MAX_TB_ICON] =
{
/*Inbox  */ {mmi_um_ui_adp_check_reply_msg,             mmi_um_ui_adp_check_forward_msg,            mmi_um_ui_adp_check_delete_msg},
/*Draft  */ {mmi_um_ui_adp_check_send_msg,              mmi_um_ui_adp_check_edit_msg,               mmi_um_ui_adp_check_delete_msg},
/*Unsent */ {mmi_um_ui_adp_check_resend_msg,            mmi_um_ui_adp_check_edit_msg,               mmi_um_ui_adp_check_delete_msg},
/*Sent   */ {mmi_um_ui_adp_check_forward_msg,           mmi_um_ui_adp_check_delete_msg,             NULL                          },
/*Archive*/ {mmi_um_ui_adp_check_reply_msg,             mmi_um_ui_adp_check_forward_msg,            mmi_um_ui_adp_check_delete_msg},
/*SIM    */ {mmi_um_ui_adp_check_copy_msg,              mmi_um_ui_adp_check_move_msg,               mmi_um_ui_adp_check_delete_msg},
/*Conbox */ {mmi_um_ui_sh_cs_check_reply,               mmi_um_ui_sh_cs_check_call,                 mmi_um_ui_sh_cs_check_delete}, 
/*ThrdMsg*/ {mmi_um_ui_adp_check_reply_msg,             mmi_um_ui_adp_check_forward_msg,            mmi_um_ui_adp_check_delete_msg},
/*Report */ {NULL,                                      NULL,                                       NULL                          }
};
#endif /* __MMI_ICON_BAR_SUPPORT__ */

const U16 g_um_ui_show_hide_menu[] =
{
    0
};

/*****************************************************************************
 * FUNCTION
 *  mmi_um_check_new_msg
 * DESCRIPTION
 *  check if new msg arrives
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 mmi_um_check_new_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_get_current_msg_box_type
 * DESCRIPTION
 *  get the type of current msg box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_um_msg_box_enum mmi_um_get_current_msg_box_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_msg_box_enum curr_active_box_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_active_box_type = mmi_um_ui_cc_get_active_scrn_msg_box();

    return curr_active_box_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_is_available
 * DESCRIPTION
 *  check if unified message is available
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_TELEPHONY_SUPPORT__
kal_bool mmi_um_is_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if MMS and WAP push is available */
#ifdef __MMI_MMS_IN_UM__
    if (!mms_is_reentrant())
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_IS_AVAILABLE_WAP_BUSY);
        return KAL_FALSE;
    }
#endif /* __MMI_MMS_IN_UM__ */

    /* Check if SMS is available */
    if (IsMessagesReEntering())
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_IS_AVAILABLE_SMS_BUSY);
        return KAL_FALSE;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_IS_AVAILABLE);

    return KAL_TRUE;
}

#endif
#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_set_message_list_sort_type
 * DESCRIPTION
 *  Set the sorting type to UM
 * PARAMETERS
 *  index:              [IN]    The selected index of sorting type
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_set_message_list_sort_type(kal_uint16 index)
{
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_prepare_sort_selection_list
 * DESCRIPTION
 *  Provide the sort menu item list for message application.
 * PARAMETERS
 *  menu_item_str_id            [IN]: buffer for string id
 *  max_menu_item               [IN]: maximum size of buffer
 *
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint16 mmi_um_prepare_sort_selection_list(kal_uint16 *menu_item_str_id, kal_uint16 max_menu_item)
{
    return 0;
}
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */


#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */




/*****************************************************************************
 * FUNCTION
 *  mmi_um_init
 * DESCRIPTION
 *  Initialize Unified Message application
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ui_init();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_msg_ind
 * DESCRIPTION
 *  set msg to be highlighted
 * PARAMETERS
 *  msg_type:           [IN]    Specified message type
 *  msg_box_type        [IN]    Specified message box type
 *  msg_id              [IN]    Specified message id
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_msg_ind(srv_um_msg_enum msg_type, srv_um_msg_box_enum msg_box_type, kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_sh_hilite_folder_info_struct hilite_folder;
            
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hilite_folder.hilite_info.msg_id = msg_id;
    hilite_folder.hilite_info.msg_type = msg_type;
    hilite_folder.hilite_info.index = 0;

    hilite_folder.folder_info.msg_box_type = msg_box_type;
    hilite_folder.folder_info.msg_type = msg_type;
    hilite_folder.folder_info.sim_id = SRV_UM_SIM_UNCLASSIFIED;

    mmi_um_ui_cc_send_event(0, MMI_UM_UI_EVENT_HIGHLIGHT_CHANGE, (void *)&hilite_folder);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_init
 * DESCRIPTION
 *  Initialize Unified Message UI
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set all zero */
    memset(g_um_ui_p, 0, sizeof(g_um_ui_cntx));
    
    /* setting init */
    g_um_ui_p->setting.support_msg_type = srv_um_support_msg_type();
    g_um_ui_p->setting.scrn_id_counter = 0;

    /* set message information buffer */
    memset(g_um_ui_msg_info_buf_p, 0, sizeof(g_um_ui_msg_info_buf_p));
#ifdef __MMI_UM_CONVERSATION_BOX__
    memset(g_um_ui_thread_info_buf_p, 0, sizeof(g_um_ui_thread_info_buf_p));
#endif /* __MMI_UM_CONVERSATION_BOX__ */
#ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__
    mmi_um_ui_sms_content_manager_init();
#endif /* __MMI_UM_CONVERSATION_BOX_ENHANCE__ */
    /* Finite state machine init */
    mmi_um_ui_fsm_init();
    
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
    memset(g_um_ui_ms_table_p, 0, sizeof(mmi_um_ui_ms_cntx_struct));
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */

	/******* Register Unified Message application ID to ASM1.0 Framework *********/
#ifndef __MMI_SUPPORT_ASMV2__
		applib_mem_ap_register(
			APPLIB_MEM_AP_ID_UM,
			STR_GLOBAL_OK,
			0,
			mmi_um_ui_app_mem_stop_callback);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_int_is_available
 * DESCRIPTION
 *  Internal checking UM is available.
 *  No_SIM / BT access profile / wifi only will let UM unavailalbe.
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  MMI_TRUE: UM is available
 *  MMI_FALSE: UM is unavailable
 *****************************************************************************/
MMI_BOOL mmi_um_ui_int_is_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_available;
    mmi_um_ui_cc_scrn_cntx_setting_struct setting;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_available = MMI_TRUE;
    memset(&setting, 0, sizeof(mmi_um_ui_cc_scrn_cntx_setting_struct));
    
    setting.folder.msg_type = g_um_ui_p->setting.support_msg_type;
    setting.folder.sim_id = SRV_UM_SIM_ALL;
#ifdef __MMI_TELEPHONY_SUPPORT__
    is_available = (MMI_BOOL)((setting.folder.msg_type & srv_um_ready_msg_type()) == setting.folder.msg_type);
#else
    is_available = (MMI_BOOL)(setting.folder.msg_type == setting.folder.msg_type);
#endif
    return is_available;
}


#ifdef __MMI_UM_ITERATOR_VIEWER__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_query_indexing
 * DESCRIPTION
 *  Query the current indexing information for specified message id.
 *  If UM could return the result immediately, UM will fill up the result
 *  variable and return MMI_TRUE.
 *  If UM could not return the result immediately, UM will return MMI_FALSE
 *  and call your callback while the result finished. Once your callback is
 *  executed, you should call mmi_um_query_indexing again to get the data.
 *  Note. You should only display a loading screen while launch your viewer.
 *
 * PARAMETERS
 *  info                [IN]: The query information including message id, 
 *                            callback function and your user data
 *  result              [OUT]: The output file of the query result
 *  user_data           [IN]: UM's user data. You should keep the user data
 *                            while UM call launch your screen like option
 *                            screen or viewer screen.
 *
 * RETURNS
 *  UM could return the data immediately or not.
 *
 * RETURN VALUES
 *  MMI_TRUE: UM fill the result variable.
 *  MMI_FALSE: UM has no data and feedback you to display a loading or other
 *             waiting screen.
 *****************************************************************************/
MMI_BOOL mmi_um_query_indexing(
                mmi_um_iter_viewer_info_struct *info, 
                mmi_um_iter_viewer_result_struct *result, 
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL search_result;
    U16 i;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    srv_um_list_cntx_struct *data_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    search_result = MMI_FALSE;
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    data_list = mmi_um_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));
    if (NULL == data_list)
    {
        /* No data */
        mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_QUERY_INDEXING, (void *)info);
        search_result = MMI_FALSE;
    }
    else
    {
        /* external app should allocate a memory to store the result */
        MMI_ASSERT(NULL != result);
        /* search index */
        for (i = 0 ; i < data_list->msg_number ; i++)
        {
            if (info->msg_id == ((srv_um_msg_node_struct *)data_list->list)[i].msg_id &&
                info->msg_type == ((srv_um_msg_node_struct *)data_list->list)[i].msg_type)
            {
                /* hit */
                break;
            }
        }
        MMI_ASSERT(i < data_list->msg_number);

        /* Set data */
        memset(result, 0, sizeof(mmi_um_iter_viewer_result_struct));
        result->index_number = i + 1;   /* display the correct index */
        result->total_number = data_list->msg_number;
        if (i == 0)
        {
            /* First one */
            result->next_msg_id = ((srv_um_msg_node_struct *)data_list->list)[i + 1].msg_id;
            result->next_msg_type = ((srv_um_msg_node_struct *)data_list->list)[i + 1].msg_type;
            result->next_launch_func_ptr = mmi_um_ui_adp_get_viewer_ptr(result->next_msg_type);
        }
        else if (i == (data_list->msg_number - 1))
        {
            /* Last one */
            result->prev_msg_id = ((srv_um_msg_node_struct *)data_list->list)[i - 1].msg_id;
            result->prev_msg_type = ((srv_um_msg_node_struct *)data_list->list)[i - 1].msg_type;
            result->prev_launch_func_ptr = mmi_um_ui_adp_get_viewer_ptr(result->prev_msg_type);
        }
        else
        {
            result->prev_msg_id = ((srv_um_msg_node_struct *)data_list->list)[i - 1].msg_id;
            result->next_msg_id = ((srv_um_msg_node_struct *)data_list->list)[i + 1].msg_id;
            result->prev_msg_type = ((srv_um_msg_node_struct *)data_list->list)[i - 1].msg_type;
            result->next_msg_type = ((srv_um_msg_node_struct *)data_list->list)[i + 1].msg_type;
            result->prev_launch_func_ptr = mmi_um_ui_adp_get_viewer_ptr(result->prev_msg_type);
            result->next_launch_func_ptr = mmi_um_ui_adp_get_viewer_ptr(result->next_msg_type);
        }

        /* Change the highlight as the current viewed message */
        scrn_cntx->screen_hdlr.hilite_info.index = i;
        scrn_cntx->screen_hdlr.hilite_info.msg_id = info->msg_id;
        scrn_cntx->screen_hdlr.hilite_info.msg_type = info->msg_type;

        search_result = MMI_TRUE;
    }

    return search_result;
}
#endif /* __MMI_UM_ITERATOR_VIEWER__ */


#ifdef __MMI_UM_CONVERSATION_BOX__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_check_conversation_box_setting
 * DESCRIPTION
 *  Checking the conversation box setting. If it turns on the conversation
 *  box, it will return MMI_TRUE. Else, it will return MMI_FALSE
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  The conversation box setting status
 *
 * RETURN VALUES
 *  MMI_TRUE: Conversation box turns on.
 *  MMI_FALSE: Conversation box turns off.
 *****************************************************************************/
MMI_BOOL mmi_um_check_conversation_box_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 select;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_UM_CONVERSATION_BOX_SETTING, &select, DS_BYTE, &error);
    if (select != 0 && select != 1)
    {
        /* Value is wrong, reset as default value */
    #ifdef __OP01__
        select = 0;
    #else
        select = 1;
    #endif
        WriteValue(NVRAM_UM_CONVERSATION_BOX_SETTING, &select, DS_BYTE, &error);
    }

    if (1 == select)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}
#endif /* __MMI_UM_CONVERSATION_BOX__ */
#endif /* __UM_SUPPORT__ */
