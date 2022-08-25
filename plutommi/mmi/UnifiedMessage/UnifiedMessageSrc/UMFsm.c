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
 * UMFsm.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"
#ifdef __UM_SUPPORT__
#include "UMDefs.h"
#include "UMProt.h"
#include "UmSrvGprot.h"
#include "MMIDataType.h"
#include "string.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "UmSrvDefs.h"
#include "mmi_common_app_trc.h"

S32 g_um_ui_fsm_invalid_pids[MMI_UM_UI_FSM_MAX_NUM_OF_INVALID_PID];

#ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__ 
static MMI_BOOL mmi_um_ui_fsm_ef_get_msg_content(U16 scrn_id, 
                                           U16 start_idx, 
                                           U16 num_of_items, 
                                           CHAR **contents);
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_init
 * DESCRIPTION
 *  The initial funciton of finite state machine.
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_fsm_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_um_ui_fsm_invalid_pids, 0, sizeof(g_um_ui_fsm_invalid_pids));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_check_invalid_pid
 * DESCRIPTION
 *  Check the pid if the invalid pid
 *
 * PARAMETERS
 *  pid:            [IN]    checked pid
 *
 * RETURNS
 *  Returns MMI_TRUE if the pid is invalid, else return MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_check_invalid_pid(S32 pid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_FALSE;
    for (i = 0; i < MMI_UM_UI_FSM_MAX_NUM_OF_INVALID_PID; i++)
    {
        if (g_um_ui_fsm_invalid_pids[i] == pid)
        {
            result = MMI_TRUE;
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_add_invalid_pid
 * DESCRIPTION
 *  Add the pid into invalid array
 *
 * PARAMETERS
 *  pid:            [IN]    added pid
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_fsm_add_invalid_pid(S32 pid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_FALSE;
    for (i = 0; i < MMI_UM_UI_FSM_MAX_NUM_OF_INVALID_PID; i++)
    {
        if (g_um_ui_fsm_invalid_pids[i] == 0)
        {
            result = MMI_TRUE;
            g_um_ui_fsm_invalid_pids[i] = pid;
            break;
        }
    }

    if (result == MMI_FALSE)
    {
        /* invalid pids array is full */
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_remove_invalid_pid
 * DESCRIPTION
 *  Remove the pid from invalid array
 *
 * PARAMETERS
 *  pid:            [IN]    Removed pid
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_fsm_remove_invalid_pid(S32 pid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_UM_UI_FSM_MAX_NUM_OF_INVALID_PID; i++)
    {
        if (g_um_ui_fsm_invalid_pids[i] == pid)
        {
            g_um_ui_fsm_invalid_pids[i] = 0;
            break;
        }
    }
}

#ifdef __MMI_UM_EL_FSM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_el_init
 * DESCRIPTION
 *  The entry list finite state machine. (initial state)
 *
 * PARAMETERS
 *  fsm_cntx            [IN]: the finite state machine context
 *  setting             [IN]: the setting for this finite state machine
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_fsm_el_init(mmi_um_ui_fsm_node_struct *fsm_cntx, mmi_um_ui_fsm_el_setting_struct setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_entry_list_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm = &(fsm_cntx->cntx.fsm_entry_list);
    memset(fsm, 0, sizeof(mmi_um_ui_fsm_entry_list_struct));
    fsm->state = MMI_UM_UI_FSM_EL_INIT;

    /* External setting */
    fsm->req_data = setting.req_data;
    fsm->scrn_id = setting.scrn_id;
    fsm->req_data_type = setting.req_data_type;
    fsm->req_folder_type= setting.req_folder_type;
    fsm_cntx->callback_hdlr = setting.scrn_callback_hdlr;

    /* Internal setting */
    fsm->pid = 0;
    fsm->req_srv_status = MMI_UM_UI_REQ_SRV_NONE;
    fsm->get_msg_num = mmi_um_ui_fsm_el_get_msg_num;
    memset(&(fsm->req_msg_num_result), 0, sizeof(srv_um_get_msg_num_result));
    fsm_cntx->type = MMI_UM_UI_FSM_ENTRY_LIST;
    fsm_cntx->event_hdlr = mmi_um_ui_fsm_event_hdlr;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_FSM_ENTRY_LIST_STATE, fsm->scrn_id, MMI_UM_UI_FSM_ENTRY_LIST, fsm->state);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_el_inside
 * DESCRIPTION
 *  The entry list finite state machine. (inside state)
 *
 * PARAMETERS
 *  fsm_cntx            [IN]: the finite state machine context
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_fsm_el_inside(mmi_um_ui_fsm_node_struct *fsm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_entry_list_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm = &(fsm_cntx->cntx.fsm_entry_list);
    fsm->state = MMI_UM_UI_FSM_EL_INSIDE;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_FSM_ENTRY_LIST_STATE, fsm->scrn_id, MMI_UM_UI_FSM_ENTRY_LIST, fsm->state);

    /* Need to get data */
    if ((fsm->req_data == MMI_TRUE) && (fsm->req_srv_status == MMI_UM_UI_REQ_SRV_NONE))
    {
        mmi_um_ui_fsm_el_update(fsm_cntx);
        return;
    }

    /* inform screen */
    fsm_cntx->callback_hdlr(fsm->scrn_id, (U16)fsm->state, (U16)fsm->req_srv_status);

    /* reset request data status */
    fsm->req_srv_status = MMI_UM_UI_REQ_SRV_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_el_update
 * DESCRIPTION
 *  The entry list finite state machine. (update state)
 *
 * PARAMETERS
 *  fsm_cntx            [IN]: the finite state machine context
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_fsm_el_update(mmi_um_ui_fsm_node_struct *fsm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_entry_list_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm = &(fsm_cntx->cntx.fsm_entry_list);
    fsm->state = MMI_UM_UI_FSM_EL_UPDATE;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_FSM_ENTRY_LIST_STATE, fsm->scrn_id, MMI_UM_UI_FSM_ENTRY_LIST, fsm->state);

    switch (fsm->req_data_type)
    {
        case MMI_UM_UI_FSM_EL_REQ_MSG_NUM:
        {
            /* check service ready status */
            if ((srv_um_ready_msg_type() & fsm->req_folder_type.msg_type) != fsm->req_folder_type.msg_type)
            {
                fsm->req_srv_status = MMI_UM_UI_REQ_SRV_WAIT_READY;
            }
            else
            {
                /* call service api to get the message num */
                fsm->req_srv_status = MMI_UM_UI_REQ_SRV_PROGRESS;
                #ifdef __MMI_TELEPHONY_SUPPORT__
                fsm->pid = srv_um_get_msg_num(
                                fsm->req_folder_type.msg_type, 
                                fsm->req_folder_type.sim_id, 
                                mmi_um_ui_fsm_el_req_msg_num_cb, 
                                fsm->scrn_id);
                #endif
            }
            /* inform screen handler */
            fsm_cntx->callback_hdlr(fsm->scrn_id, (U16)fsm->state, (U16)fsm->req_srv_status);
            break;
        }
        default:
        {
            MMI_ASSERT(0);
        }
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_el_req_msg_num_cb
 * DESCRIPTION
 *  The callback function for get_msg_num request(Service)
 *
 * PARAMETERS
 *  pid                 [IN]: Request id
 *  rsp                 [IN]: Response from service
 *  para                [IN]: Optional paramenter, it is used for screen id
 *
 * RETURNS
 *  Process result. Regards to srv_um_result_enum.
 *****************************************************************************/
S32 mmi_um_ui_fsm_el_req_msg_num_cb(S32 pid, srv_um_get_msg_num_result *rsp, S32 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_fsm_node_struct *fsm_cntx;
    mmi_um_ui_fsm_entry_list_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check pid if invalid */
    if (mmi_um_ui_fsm_check_invalid_pid(pid))
    {
        /* remove it */
        mmi_um_ui_fsm_remove_invalid_pid(pid);
        return SRV_UM_RESULT_OK;
    }
    
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx((U16)para);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_list);

    MMI_ASSERT(pid == fsm->pid);

    memcpy(&(fsm->req_msg_num_result), rsp, sizeof(srv_um_get_msg_num_result));
    fsm->pid = 0;

    /* Print the error log */
    if (rsp->error == SRV_UM_RESULT_CANCELLLED && fsm->req_srv_status == MMI_UM_UI_REQ_SRV_CANCELLING)
    {
        fsm->req_srv_status = MMI_UM_UI_REQ_SRV_CANCELLED;
    }

    if (fsm->req_srv_status == MMI_UM_UI_REQ_SRV_PROGRESS)
    {
        if (rsp->error >= SRV_UM_RESULT_OK)
        {
            /* Set status */
            fsm->req_srv_status = MMI_UM_UI_REQ_SRV_FINISH;
        }
        else
        {
            /* Set status */
            fsm->req_srv_status = MMI_UM_UI_REQ_SRV_FAIL;
        }
    }
    /* Entry inside state */
    mmi_um_ui_fsm_el_inside(fsm_cntx);
    
    return SRV_UM_RESULT_OK;
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_event_hdlr
 * DESCRIPTION
 *  The event handler of entry list finite state machine.
 *
 * PARAMETERS
 *  scrn_id             [IN]: the screen id
 *  event               [IN]: the event id
 *  arg                 [IN]: the event argument
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_event_hdlr(U16 scrn_id, U16 event, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_fsm_node_struct *fsm_cntx;
    MMI_BOOL event_process_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    
    fsm_cntx = &(scrn_cntx->fsm);

    MMI_TRACE(
        MMI_COMMON_TRC_G6_MSG, 
        TRC_MMI_UM_UI_FSM_EL_EVENT_HANDLER, 
        scrn_id, 
        MMI_UM_UI_FSM_ENTRY_LIST, 
        fsm_cntx->cntx.fsm_entry_list.state, 
        event);
    
    event_process_result = MMI_TRUE;

    switch (fsm_cntx->type)
    {
    #ifdef __MMI_UM_EL_FSM_SUPPORT__ 
        case MMI_UM_UI_FSM_ENTRY_LIST:
        {
            MMI_TRACE(
                MMI_COMMON_TRC_G6_MSG, 
                TRC_MMI_UM_UI_FSM_EL_EVENT_HANDLER, 
                scrn_id, 
                MMI_UM_UI_FSM_ENTRY_LIST, 
                fsm_cntx->cntx.fsm_entry_list.state, 
                event);
            if (event < MMI_UM_UI_FSM_EVENT_TOTAL)
            {
                event_process_result = 
                    (*fsm_el_tb[g_um_ui_fsm_el_event_table[event][fsm_cntx->cntx.fsm_entry_list.state]])(fsm_cntx, arg);
            }
            break;
        }
    #endif
        case MMI_UM_UI_FSM_ENTRY_FOLDER:
            MMI_TRACE(
                MMI_COMMON_TRC_G6_MSG, 
                TRC_MMI_UM_UI_FSM_EF_EVENT_HANDLER, 
                scrn_id, 
                MMI_UM_UI_FSM_ENTRY_FOLDER, 
                fsm_cntx->cntx.fsm_entry_folder.state, 
                event);
            /* The defined events */
            if (event < MMI_UM_UI_FSM_EVENT_TOTAL)
            {
                event_process_result = 
                    (*fsm_ef_tb[g_um_ui_fsm_ef_event_table[event][fsm_cntx->cntx.fsm_entry_folder.state]])(fsm_cntx, arg);
                /* 
                event_process_result = 
                    (*g_um_ui_fsm_ef_event_table[event][fsm_cntx->cntx.fsm_entry_folder.state])(fsm_cntx, arg);
                */
            }
            break;
#ifdef __MMI_UM_OP_FSM_SUPPORT__ 
        case MMI_UM_UI_FSM_OPERATION:
            MMI_TRACE(
                MMI_COMMON_TRC_G6_MSG, 
                TRC_MMI_UM_UI_FSM_OP_EVENT_HANDLER, 
                scrn_id, 
                MMI_UM_UI_FSM_OPERATION, 
                fsm_cntx->cntx.fsm_operation.state, 
                event);
            /* The defined events */
            if (event < MMI_UM_UI_FSM_EVENT_TOTAL)
            {
                event_process_result = 
                    (*fsm_op_tb[g_um_ui_fsm_op_event_table[event][fsm_cntx->cntx.fsm_operation.state]])(fsm_cntx, arg);
                /*
                event_process_result = 
                    (*g_um_ui_fsm_op_event_table[event][fsm_cntx->cntx.fsm_operation.state])(fsm_cntx, arg);
                */
            }
            break;
#endif /* __MMI_UM_OP_FSM_SUPPORT__ */

        default:
            break;
    }

    return event_process_result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_el_get_msg_num
 * DESCRIPTION
 *  It is used for screen handler to get the message number information
 *
 * PARAMETERS
 *  scrn_id             [IN]: Screen id
 *  msg_num             [OUT]: Message number information
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_fsm_el_get_msg_num(U16 scrn_id, srv_um_get_msg_num_result **msg_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_fsm_node_struct *fsm_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BT_MAP_CLIENT__
    scrn_cntx = mmi_um_ui_sh_get_active_user_data(); 

    if (scrn_cntx == NULL
        || scrn_cntx->scrn_id == 0 
        || scrn_cntx->group_id== 0)
    {
        scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id); 
        if (scrn_cntx == NULL)
            scrn_cntx = g_sh_get_item_scrn_cntx;
    }
#else
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);
#endif /* __MMI_BT_MAP_CLIENT__ */
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    MMI_ASSERT(msg_num != NULL);

    fsm_cntx = &(scrn_cntx->fsm);

    /* during collect data, the number of list should be 0 */
    (*msg_num) = &(fsm_cntx->cntx.fsm_entry_list.req_msg_num_result);   
}

/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_init
 * DESCRIPTION
 *  The entry folder finite state machine. (initial state)
 *
 * PARAMETERS
 *  fsm_cntx            [IN]: the finite state machine context
 *  setting             [IN]: the setting of this finite state machine
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_fsm_ef_init(mmi_um_ui_fsm_node_struct *fsm_cntx, mmi_um_ui_fsm_ef_setting_struct setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_entry_folder_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);
    memset(fsm, 0, sizeof(mmi_um_ui_fsm_entry_folder_struct));
    fsm->state = MMI_UM_UI_FSM_EF_INIT;

    /* External setting */
    fsm->scrn_id = setting.scrn_id;
    fsm->folder_mode = setting.folder_mode;
    fsm->folder_type = setting.folder_type;
    fsm_cntx->callback_hdlr = setting.scrn_callback_hdlr;

    /* Internal setting */
    fsm->folder_info.data_list_updated = MMI_TRUE;
    fsm->folder_info.data_list = NULL;
    fsm->pid = 0;
    fsm->action = MMI_UM_UI_ACTION_NONE;
    fsm->req_srv_status = MMI_UM_UI_REQ_SRV_NONE;
    fsm->get_msg_num = mmi_um_ui_fsm_ef_get_msg_num;
    fsm->get_msg_info = mmi_um_ui_fsm_ef_get_msg_info;
#ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__
    fsm->get_msg_content = mmi_um_ui_fsm_ef_get_msg_content;
#endif /* __MMI_UM_CONVERSATION_BOX_ENHANCE__ */
    fsm_cntx->type = MMI_UM_UI_FSM_ENTRY_FOLDER;
    fsm_cntx->event_hdlr = mmi_um_ui_fsm_event_hdlr;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_FSM_ENTRY_FOLDER_STATE, fsm->scrn_id, MMI_UM_UI_FSM_ENTRY_FOLDER, fsm->state);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_check_ready
 * DESCRIPTION
 *  The entry folder finite state machine. (check ready state)
 *
 * PARAMETERS
 *  fsm_cntx            [IN]: the finite state machine context
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_fsm_ef_check_ready(mmi_um_ui_fsm_node_struct *fsm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_entry_folder_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);
    fsm->state = MMI_UM_UI_FSM_EF_CHECK_READY;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_FSM_ENTRY_FOLDER_STATE, fsm->scrn_id, MMI_UM_UI_FSM_ENTRY_FOLDER, fsm->state);

    if ((fsm->folder_type.msg_type & srv_um_ready_msg_type()) != fsm->folder_type.msg_type)
    { 
        #if 0
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
        #else
        MMI_ASSERT((fsm->folder_type.msg_type & srv_um_ready_msg_type()) != fsm->folder_type.msg_type);
        #endif
        return;
    }

    /* service is ready, go to get data */
    fsm->req_srv_status = MMI_UM_UI_REQ_SRV_NONE;
    fsm->action = MMI_UM_UI_ACTION_NONE;
    
    mmi_um_ui_fsm_ef_check_data(fsm_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_check_data
 * DESCRIPTION
 *  The entry folder finite state machine. (check data state)
 *
 * PARAMETERS
 *  fsm_cntx            [IN]: the finite state machine context
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_fsm_ef_check_data(mmi_um_ui_fsm_node_struct *fsm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_entry_folder_struct *fsm;
    S32 check_msg_list;
    S32 check_msg_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);
    fsm->state = MMI_UM_UI_FSM_EF_CHECK_DATA;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_FSM_ENTRY_FOLDER_STATE, fsm->scrn_id, MMI_UM_UI_FSM_ENTRY_FOLDER, fsm->state);

    /* request data list */
    if (NULL == fsm->folder_info.data_list &&
        MMI_TRUE == fsm->folder_info.data_list_updated)
    {
        check_msg_list = mmi_um_ui_fsm_ef_srv_check_msg_list(
                                            fsm->folder_type, 
                                            &(fsm->folder_info.filter_type), 
                                            mmi_um_ui_fsm_ef_msg_list_status_cb, 
                                            fsm->scrn_id, 
                                            &(fsm->folder_info.data_list), 
                                            fsm->folder_mode);
        /* Get the message list */
        if (check_msg_list > SRV_UM_RESULT_OK)
        {
            MMI_ASSERT(fsm->folder_info.data_list != NULL);
            fsm->folder_info.data_list_updated = MMI_FALSE;
            /* > 0, it is the list id and store in the fsm */
            fsm->folder_info.list_id = check_msg_list;
        }
    }

    /* data list needs to be updated */
    if (fsm->folder_info.data_list_updated == MMI_TRUE)
    {
        if (0 < fsm->folder_info.list_id)
        {
            /* release it first */
            srv_um_release_msg_list(fsm->folder_info.list_id, MMI_TRUE);
            fsm->folder_info.list_id = 0;
            fsm->folder_info.data_list = NULL;
        }
        fsm->action = MMI_UM_UI_ACTION_GET_MSG_LIST;
        mmi_um_ui_fsm_ef_update_data(fsm_cntx);
        return;
    }

    /* Check the data list is empty. If yes, notify screen handler */
    if (NULL == fsm->folder_info.data_list)
    {
        fsm->req_srv_status = MMI_UM_UI_REQ_SRV_FINISH;
        fsm_cntx->callback_hdlr(fsm->scrn_id, (U16)fsm->state, (U16)fsm->req_srv_status);
        return;
    }
    else if (0 == fsm->folder_info.data_list->msg_number)
    {
        fsm->req_srv_status = MMI_UM_UI_REQ_SRV_FINISH;
        fsm_cntx->callback_hdlr(fsm->scrn_id, (U16)fsm->state, (U16)fsm->req_srv_status);
        return;
    }

#ifdef __MMI_UM_CONVERSATION_BOX__
    /* Need to check thread info */
    if (MMI_UM_FOLDER_MODE_THREAD_MSG == fsm->folder_mode)
    {
        check_msg_info = srv_um_check_thread_info(
                                fsm->folder_type, 
                                &(fsm->folder_info.filter_type.thread_id), 
                                1, 
                                0, 
                                1, 
                                NULL, 
                                NULL);
        if (check_msg_info < SRV_UM_RESULT_OK)
        {
            fsm->action = MMI_UM_UI_ACTION_GET_THRD_INFO;
            mmi_um_ui_fsm_ef_update_data(fsm_cntx);
            return;
        }
    }
#endif /* __MMI_UM_CONVERSATION_BOX__ */

    /* check message detail information */
    MMI_ASSERT(fsm->folder_info.num_of_req_item < MMI_UM_UI_MAX_MSG_INFO_NUM);

    /* check the last message index if overflow of data list */
    if ((fsm->folder_info.start_msg_idx + fsm->folder_info.num_of_req_item) > fsm->folder_info.data_list->msg_number)
    {
        /* the old message index is wrong, reassign it to 0 */
        fsm->folder_info.num_of_req_item = 0;
    }

    /* No need to get msg info because of the first time entry */
    if (fsm->folder_info.num_of_req_item == 0)
    {
        fsm_cntx->callback_hdlr(fsm->scrn_id, (U16)fsm->state, (U16)fsm->req_srv_status);
        return;
    }

    /* only need to check, it does not need to copy data */
    check_msg_info = mmi_um_ui_fsm_ef_srv_check_msg_info_by_ref(
                            fsm->folder_type, 
                            fsm->folder_info.data_list->list, 
                            fsm->folder_info.data_list->msg_number, 
                            fsm->folder_info.start_msg_idx, 
                            fsm->folder_info.num_of_req_item, 
                            NULL, 
                            NULL, 
                            fsm->folder_mode);

    /* Service has message detail information */
    if (check_msg_info >= SRV_UM_RESULT_OK)
    {
        #ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__ 
        if (fsm->folder_mode == MMI_UM_FOLDER_MODE_THREAD_MSG)
        {
            if (!mmi_um_ui_fsm_ef_get_msg_content(fsm->scrn_id, fsm->folder_info.start_msg_idx, fsm->folder_info.num_of_req_item, NULL))
            {
                fsm->action = MMI_UM_UI_ACTION_GET_MSG_CONTENT;
                mmi_um_ui_fsm_ef_update_data(fsm_cntx);
                return;
            }
        }
        #endif
        fsm->req_srv_status = MMI_UM_UI_REQ_SRV_FINISH;
        /* Notify screen handler */
        fsm_cntx->callback_hdlr(fsm->scrn_id, (U16)fsm->state, (U16)fsm->req_srv_status);
    }
    else
    {
        fsm->action = MMI_UM_UI_ACTION_GET_MSG_INFO;
        mmi_um_ui_fsm_ef_update_data(fsm_cntx);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_update_data
 * DESCRIPTION
 *  The entry folder finite state machine. (update data state)
 *  It may need to update the list or message inforamtion depending on the
 *  "action" varialbe value.
 *
 * PARAMETERS
 *  fsm_cntx            [IN]: the finite state machine context
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_fsm_ef_update_data(mmi_um_ui_fsm_node_struct *fsm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_entry_folder_struct *fsm;
    void *msg_list;
    void *cb_func = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);
    fsm->state = MMI_UM_UI_FSM_EF_UPDATE_DATA;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_FSM_ENTRY_FOLDER_STATE, fsm->scrn_id, MMI_UM_UI_FSM_ENTRY_FOLDER, fsm->state);

    /* check necessary variable */
    MMI_ASSERT(fsm->folder_info.num_of_req_item < MMI_UM_UI_MAX_MSG_INFO_NUM);
    
    fsm->req_srv_status = MMI_UM_UI_REQ_SRV_PROGRESS;

    switch (fsm->action)
    {
        case MMI_UM_UI_ACTION_GET_MSG_LIST:
        {
            /* Request the data list from service */
            fsm->pid = mmi_um_ui_fsm_ef_srv_get_msg_list(
                                fsm->folder_type, 
                                &(fsm->folder_info.filter_type), 
                                mmi_um_ui_fsm_ef_req_msg_list_cb, 
                                fsm->scrn_id, 
                                fsm->folder_mode);
            break;
        }
        case MMI_UM_UI_ACTION_GET_MSG_INFO:
        {
            /* Request the message information from service */
            /* shift the message list pointer */
            msg_list = fsm->folder_info.data_list->list;
            if (MMI_UM_FOLDER_MODE_DEFAULT == fsm->folder_mode
        #ifdef __MMI_UM_CONVERSATION_BOX__
                || MMI_UM_FOLDER_MODE_THREAD_MSG == fsm->folder_mode
        #endif /* __MMI_UM_CONVERSATION_BOX__ */
               )
            {
                msg_list = (void *)(((srv_um_msg_node_struct*)fsm->folder_info.data_list->list) + fsm->folder_info.start_msg_idx);
                cb_func = (void *)mmi_um_ui_fsm_ef_req_msg_info_cb;
            }
        #ifdef __MMI_UM_CONVERSATION_BOX__
            else if (MMI_UM_FOLDER_MODE_CONVERSATION_BOX == fsm->folder_mode)
            {
                msg_list = (void *)(((srv_um_thread_id_struct*)fsm->folder_info.data_list->list) + fsm->folder_info.start_msg_idx);
                cb_func = (void *)mmi_um_ui_fsm_ef_req_thread_info_cb;
            }
        #endif /* __MMI_UM_CONVERSATION_BOX__ */
            else
            {
                MMI_ASSERT(0);
            }
            fsm->pid = mmi_um_ui_fsm_ef_srv_get_msg_info(
                                fsm->folder_type, 
                                msg_list,
                                fsm->folder_info.num_of_req_item, 
                                cb_func, 
                                fsm->scrn_id, 
                                fsm->folder_mode);
            break;
        }
    #ifdef __MMI_UM_CONVERSATION_BOX__
        case MMI_UM_UI_ACTION_GET_THRD_INFO:
        {
            fsm->pid = srv_um_get_thread_info(
                                    fsm->folder_type, 
                                    &(fsm->folder_info.filter_type.thread_id), 
                                    1, 
                                    mmi_um_ui_fsm_ef_req_thread_info_cb, 
                                    fsm->scrn_id);
            break;
        }
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
    
    #ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__
        case MMI_UM_UI_ACTION_GET_MSG_CONTENT:
        {
            um_sms_id *messages = OslMalloc(fsm->folder_info.num_of_req_item * sizeof(um_sms_id)); 
            U16 *message_indexes = OslMalloc(fsm->folder_info.num_of_req_item * sizeof(U16)); 
            S32 count = 0;
            count = mmi_um_ui_fsm_ef_extract_message_need_content(
                        fsm,
                        messages,
                        message_indexes,
                        fsm->folder_info.num_of_req_item);
            mmi_um_ui_sms_get_sms_content_request(messages, 
                                          message_indexes,
                                          count, 
                                          fsm->scrn_id);
            OslMfree(messages);
            OslMfree(message_indexes);
            break;
        }
    #endif
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    /* Notify screen handler */
    fsm_cntx->callback_hdlr(fsm->scrn_id, (U16)fsm->state, (U16)fsm->req_srv_status);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_deinit
 * DESCRIPTION
 *  The entry folder finite state machine. (de-initial state)
 *
 * PARAMETERS
 *  fsm_cntx            [IN]: the finite state machine context
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_fsm_ef_deinit(mmi_um_ui_fsm_node_struct *fsm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_entry_folder_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);
    fsm->state = MMI_UM_UI_FSM_EF_DEINIT;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_FSM_ENTRY_FOLDER_STATE, fsm->scrn_id, MMI_UM_UI_FSM_ENTRY_FOLDER, fsm->state);
    
    /* release data list */
    if (0 < fsm->folder_info.list_id)
    {
        srv_um_release_msg_list(fsm->folder_info.list_id, MMI_TRUE);
    }
    fsm->folder_info.list_id = 0;
    fsm->folder_info.data_list = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_msg_list_status_cb
 * DESCRIPTION
 *  The status callback function for message list.
 *
 * PARAMETERS
 *  event               [IN]: Event coming from service
 *  list_cid            [IN]: ?
 *  para                [IN]: FSM screen id
 *
 * RETURNS
 *  Process result. Regards to srv_um_result_enum.
 *****************************************************************************/
void mmi_um_ui_fsm_ef_msg_list_status_cb(S32 event, S32 list_cid, S32 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_fsm_node_struct *fsm_cntx;
    mmi_um_ui_fsm_entry_folder_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx((U16)para);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);

    switch (event)
    {
        case SRV_UM_NOTIFY_LIST_RELEASED_IND:
        {
            /* Reset the data list */
            fsm->folder_info.data_list_updated = MMI_TRUE;
            fsm->folder_info.list_id = 0;
            fsm->folder_info.data_list = NULL;

            /* Send release event to fsm */
            mmi_um_ui_cc_send_event(fsm->scrn_id, MMI_UM_UI_EVENT_REL_DATA_LIST, NULL);
            break;
        }
        default:
        {
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_req_msg_list_cb
 * DESCRIPTION
 *  The callback function for get message list from service.
 *
 * PARAMETERS
 *  pid                 [IN]: Request id
 *  rsp                 [IN]: Response from service
 *  para                [IN]: Optional paramenter, it is used for screen id
 *
 * RETURNS
 *  Process result. Regards to srv_um_result_enum.
 *****************************************************************************/
#ifdef __MMI_UM_ULTRA_SLIM__
S32 mmi_um_ui_fsm_ef_req_list_msg_info_common_cb(S32 pid, S32 error, S32 para)
{
        /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_fsm_node_struct *fsm_cntx;
    mmi_um_ui_fsm_entry_folder_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check pid if invalid */
    if (mmi_um_ui_fsm_check_invalid_pid(pid))
    {
        /* remove it */
        mmi_um_ui_fsm_remove_invalid_pid(pid);
        return SRV_UM_RESULT_OK;
    }
    
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx((U16)para);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);

    MMI_ASSERT(pid == fsm->pid);
    MMI_ASSERT(fsm->state == MMI_UM_UI_FSM_EF_UPDATE_DATA);

    /* Print the error log */
    if (error == SRV_UM_RESULT_CANCELLLED && fsm->req_srv_status == MMI_UM_UI_REQ_SRV_CANCELLING)
    {
        fsm->req_srv_status = MMI_UM_UI_REQ_SRV_CANCELLED;
    }

    if (error >= SRV_UM_RESULT_OK)
    {
        fsm->req_srv_status = MMI_UM_UI_REQ_SRV_FINISH;
    }

    /* Reset action */
    fsm->action = MMI_UM_UI_ACTION_NONE;
    /* Reset pid */
    fsm->pid = 0;

    /* List is gotten, go to check_data to get again */
    mmi_um_ui_fsm_ef_check_data(fsm_cntx);

    return SRV_UM_RESULT_OK;
}
#endif
S32 mmi_um_ui_fsm_ef_req_msg_list_cb(S32 pid, srv_um_get_msg_list_result *rsp, S32 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_UM_ULTRA_SLIM__
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_fsm_node_struct *fsm_cntx;
    mmi_um_ui_fsm_entry_folder_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check pid if invalid */
    if (mmi_um_ui_fsm_check_invalid_pid(pid))
    {
        /* remove it */
        mmi_um_ui_fsm_remove_invalid_pid(pid);
        return SRV_UM_RESULT_OK;
    }
    
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx((U16)para);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);

    MMI_ASSERT(pid == fsm->pid);
    MMI_ASSERT(fsm->state == MMI_UM_UI_FSM_EF_UPDATE_DATA);

    /* Print the error log */
    if (rsp->error == SRV_UM_RESULT_CANCELLLED && fsm->req_srv_status == MMI_UM_UI_REQ_SRV_CANCELLING)
    {
        fsm->req_srv_status = MMI_UM_UI_REQ_SRV_CANCELLED;
    }

    if (rsp->error >= SRV_UM_RESULT_OK)
    {
        fsm->req_srv_status = MMI_UM_UI_REQ_SRV_FINISH;
    }

    /* Reset action */
    fsm->action = MMI_UM_UI_ACTION_NONE;
    /* Reset pid */
    fsm->pid = 0;

    /* List is gotten, go to check_data to get again */
    mmi_um_ui_fsm_ef_check_data(fsm_cntx);

    return SRV_UM_RESULT_OK;
#else
    return mmi_um_ui_fsm_ef_req_list_msg_info_common_cb(pid,rsp->error,para);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_req_msg_info_cb
 * DESCRIPTION
 *  The callback function for get message info from service.
 *
 * PARAMETERS
 *  pid                 [IN]: Request id
 *  rsp                 [IN]: Response from service
 *  para                [IN]: Optional paramenter, it is used for screen id
 *
 * RETURNS
 *  Process result. Regards to srv_um_result_enum.
 *****************************************************************************/
S32 mmi_um_ui_fsm_ef_req_msg_info_cb(S32 pid, srv_um_get_msg_info_result *rsp, S32 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_UM_ULTRA_SLIM__
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_fsm_node_struct *fsm_cntx;
    mmi_um_ui_fsm_entry_folder_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check pid if invalid */
    if (mmi_um_ui_fsm_check_invalid_pid(pid))
    {
        /* remove it */
        mmi_um_ui_fsm_remove_invalid_pid(pid);
        return SRV_UM_RESULT_OK;
    }
    
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx((U16)para);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);

    MMI_ASSERT(pid == fsm->pid);
    MMI_ASSERT(fsm->state == MMI_UM_UI_FSM_EF_UPDATE_DATA);

    /* Print the error log */
    if (rsp->error == SRV_UM_RESULT_CANCELLLED && fsm->req_srv_status == MMI_UM_UI_REQ_SRV_CANCELLING)
    {
        fsm->req_srv_status = MMI_UM_UI_REQ_SRV_CANCELLED;
    }

    if (rsp->error >= SRV_UM_RESULT_OK)
    {
        fsm->req_srv_status = MMI_UM_UI_REQ_SRV_FINISH;
    }

    /* Reset pid */
    fsm->pid = 0;

    /* Reset action */
    fsm->action = MMI_UM_UI_ACTION_NONE;

    mmi_um_ui_fsm_ef_check_data(fsm_cntx);

    return SRV_UM_RESULT_OK;
#else
    return mmi_um_ui_fsm_ef_req_list_msg_info_common_cb(pid,rsp->error,para);
#endif
}


#ifdef __MMI_UM_CONVERSATION_BOX__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_req_thread_info_cb
 * DESCRIPTION
 *  The callback function for get thread info from service.
 *
 * PARAMETERS
 *  pid                 [IN]: Request id
 *  rsp                 [IN]: Response from service
 *  para                [IN]: Optional paramenter, it is used for screen id
 *
 * RETURNS
 *  Process result. Regards to srv_um_result_enum.
 *****************************************************************************/
S32 mmi_um_ui_fsm_ef_req_thread_info_cb(S32 pid, srv_um_get_thread_info_result *rsp, S32 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_fsm_node_struct *fsm_cntx;
    mmi_um_ui_fsm_entry_folder_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check pid if invalid */
    if (mmi_um_ui_fsm_check_invalid_pid(pid))
    {
        /* remove it */
        mmi_um_ui_fsm_remove_invalid_pid(pid);
        return SRV_UM_RESULT_OK;
    }
    
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx((U16)para);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);

    MMI_ASSERT(pid == fsm->pid);
    MMI_ASSERT(fsm->state == MMI_UM_UI_FSM_EF_UPDATE_DATA);

    /* Print the error log */
    if (rsp->error == SRV_UM_RESULT_CANCELLLED && fsm->req_srv_status == MMI_UM_UI_REQ_SRV_CANCELLING)
    {
        fsm->req_srv_status = MMI_UM_UI_REQ_SRV_CANCELLED;
    }

    if (rsp->error >= SRV_UM_RESULT_OK)
    {
        fsm->req_srv_status = MMI_UM_UI_REQ_SRV_FINISH;
    }

    /* Reset pid */
    fsm->pid = 0;

    /* Reset action */
    fsm->action = MMI_UM_UI_ACTION_NONE;

    mmi_um_ui_fsm_ef_check_data(fsm_cntx);

    return SRV_UM_RESULT_OK;
}
#endif /* __MMI_UM_CONVERSATION_BOX__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_get_msg_num
 * DESCRIPTION
 *  Finite state machine should provide a function to get the number of 
 *  message in ths list. It is used to get the number of message for screen 
 *  handler.
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  Number of data in the data list
 *****************************************************************************/
U16 mmi_um_ui_fsm_ef_get_msg_num(U16 scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_fsm_node_struct *fsm_cntx;
    mmi_um_ui_fsm_entry_folder_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);

    if (fsm->folder_info.data_list == NULL)
    {
        return 0;
    }
    else
    {
        return fsm->folder_info.data_list->msg_number;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_get_msg_info
 * DESCRIPTION
 *  Finite state machine should provide a function to get the message detail
 *  information. It is used to get the message deatil information for 
 *  screen handler.
 *
 * PARAMETERS
 *  fsm_cntx            [IN]: the finite state machine context
 *  start_index         [IN]: the start index of request message
 *  num_of_req_item     [IN]: the number of request messages
 *  msg_info            [OUT]: the output of message deatil information
 *  thread_info         [OUT]: the output of thread detail information
 *
 * RETURNS
 *  MMI_TRUE: Has data
 *  MMI_FALSE: No data
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_ef_get_msg_info(
                    U16 scrn_id, 
                    U16 start_index, 
                    U16 num_of_req_item, 
                    srv_um_msg_info_struct ***msg_info, 
                    srv_um_thread_info_struct ***thread_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 check_msg_info;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_fsm_node_struct *fsm_cntx;
    mmi_um_ui_fsm_entry_folder_struct *fsm;
    srv_um_msg_info_struct **msg_info_buffer;
    srv_um_thread_info_struct **thread_info_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);

    fsm->folder_info.start_msg_idx = start_index;
    fsm->folder_info.num_of_req_item = num_of_req_item;

    /* Data list is equal to NULL, no data. */
    /* During get message list state, no data */
    if (fsm->folder_info.data_list == NULL ||
        (fsm->state == MMI_UM_UI_FSM_EF_UPDATE_DATA && fsm->action == MMI_UM_UI_ACTION_GET_MSG_LIST))
    {
        (*msg_info) = NULL;
        return MMI_FALSE;
    }
    
    check_msg_info = SRV_UM_RESULT_OK;
    /* checking data from service */
    msg_info_buffer = mmi_um_ui_ut_get_msg_info_buf();
    thread_info_buffer = NULL;
#ifdef __MMI_UM_CONVERSATION_BOX__
    if (NULL != thread_info)
    {
        thread_info_buffer = mmi_um_ui_ut_get_thread_info_buf();
    }
#endif /* __MMI_UM_CONVERSATION_BOX__ */ 

    check_msg_info = mmi_um_ui_fsm_ef_srv_check_msg_info_by_ref(
                            fsm->folder_type, 
                            fsm->folder_info.data_list->list, 
                            fsm->folder_info.data_list->msg_number, 
                            fsm->folder_info.start_msg_idx, 
                            fsm->folder_info.num_of_req_item, 
                            msg_info_buffer, 
                            thread_info_buffer, 
                            fsm->folder_mode);

    /* No data */
    if (check_msg_info < SRV_UM_RESULT_OK)
    {
        (*msg_info) = NULL;
    #ifdef __MMI_UM_CONVERSATION_BOX__
        if (NULL != thread_info)
        {
            (*thread_info) = NULL;
        }
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
        return MMI_FALSE;
    }
    else
    {
        (*msg_info) = msg_info_buffer;
    #ifdef __MMI_UM_CONVERSATION_BOX__
        if (NULL != thread_info)
        {
            (*thread_info) = thread_info_buffer;
        }
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
        return MMI_TRUE;
    }
}

#ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_get_msg_content
 * DESCRIPTION
 *  Finite state machine should provide a function to get the message detail
 *  information. It is used to get the message deatil information for 
 *  screen handler.
 *
 * PARAMETERS
 *  fsm_cntx            [IN]: the finite state machine context
 *  start_index         [IN]: the start index of request message
 *  num_of_req_item     [IN]: the number of request messages
 *  content             [OUT]: the output of message deatil information, NULL for check only
 *
 * RETURNS
 *  MMI_TRUE: Has data
 *  MMI_FALSE: No data
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_ef_get_msg_content(U16 scrn_id, 
                                       U16 start_idx, 
                                       U16 num_of_items, 
                                       CHAR **contents)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 check_msg_info;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_fsm_node_struct *fsm_cntx;
    mmi_um_ui_fsm_entry_folder_struct *fsm;
    um_sms_id *messages_need_content = NULL;
    CHAR **msg_content_need_content = NULL;
    U16 *message_indexes = NULL;
    S32 amount_message_need_content;
    MMI_BOOL check_result = MMI_TRUE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);

    /* these data will used in get content and extract*/
    fsm->folder_info.start_msg_idx = start_idx;
    fsm->folder_info.num_of_req_item = num_of_items;
    
    /* Data list is equal to NULL, no data. */
    /* During get message list state, no data */
    if (fsm->folder_info.data_list == NULL ||
        (fsm->state == MMI_UM_UI_FSM_EF_UPDATE_DATA && fsm->action == MMI_UM_UI_ACTION_GET_MSG_LIST))
    {
        return MMI_FALSE;
    }
    
    /* ready to check */
    messages_need_content = (um_sms_id *)OslMalloc(sizeof(um_sms_id) * num_of_items);
    message_indexes = OslMalloc(fsm->folder_info.num_of_req_item * sizeof(U16)); 
    amount_message_need_content = mmi_um_ui_fsm_ef_extract_message_need_content
                                                (fsm, 
                                                messages_need_content, 
                                                message_indexes,
                                                num_of_items);
    if (amount_message_need_content > 0)
    {
        msg_content_need_content = OslMalloc(sizeof(CHAR *) * amount_message_need_content);
		memset((CHAR*)msg_content_need_content, 0, sizeof(CHAR*) * amount_message_need_content);
        check_msg_info = mmi_um_ui_sms_check_sms_content(
            messages_need_content, 
            message_indexes,
            amount_message_need_content,
            msg_content_need_content); 
        /* all got */
        {
            S32 iter_of_all_messages = 0;
            S32 iter_of_sms = 0;
            srv_um_msg_node_struct *start_msg_node = ((srv_um_msg_node_struct *)(fsm->folder_info.data_list->list)) + start_idx;
            for(; iter_of_all_messages < num_of_items; iter_of_all_messages++)
            {
                srv_um_msg_node_struct *current_node = start_msg_node + iter_of_all_messages;
                if (current_node->msg_type == SRV_UM_MSG_SMS)
                {
                    if (NULL != contents)
                    {
                        contents[iter_of_all_messages] = (CHAR *)msg_content_need_content[iter_of_sms];
                    }
                    ++iter_of_sms;
                }
            }
            MMI_ASSERT(amount_message_need_content == iter_of_sms);
        }  
        if ((check_msg_info == SRV_UM_RESULT_OK)) 
        {
            check_result = MMI_TRUE;
        }
        else /* No data */
        {
            check_result =  MMI_FALSE;
        }
        OslMfree(msg_content_need_content);
    }
    OslMfree(messages_need_content);
    OslMfree(message_indexes);
    return check_result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_extract_message_need_content
 * DESCRIPTION
 *  The entry folder finite get messag need content. 
 *
 * PARAMETERS
 *  fsm            [IN]: the finite state machine context
 *  messages       [OUT]: messages need to get content
 *  num_of_req_item[IN]: nubmer of messages need to be checked 
 * RETURNS
 *  S32    how many messages are extracted
 *****************************************************************************/
S32 mmi_um_ui_fsm_ef_extract_message_need_content(mmi_um_ui_fsm_entry_folder_struct *fsm, 
                                                um_sms_id messages[], 
                                                U16 message_indexes[],
                                                S32 num_of_req_item)
{   
    S32 i = 0;
    S32 counter = 0;
    srv_um_msg_node_struct *start_msg_node = (srv_um_msg_node_struct *)fsm->folder_info.data_list->list + fsm->folder_info.start_msg_idx;
    for (; i < num_of_req_item; i++)
    {
        srv_um_msg_node_struct *current_node = start_msg_node + i;
        if (current_node->msg_type == SRV_UM_MSG_SMS)
        {
            messages[counter] = current_node->msg_id;
            message_indexes[counter] = fsm->folder_info.start_msg_idx + i; 
            ++counter;
        }
    }
    return counter;
}


void mmi_um_ui_fsm_ef_get_msg_content_callback(U16 scrn_id)
{
        /*----------------------------------------------------------------*/
        /* Local Variables                                                */
        /*----------------------------------------------------------------*/
        mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
        mmi_um_ui_fsm_node_struct *fsm_cntx;
        mmi_um_ui_fsm_entry_folder_struct *fsm;

        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_CONTENT_CACHE_REQUEST_SCREEN, scrn_id);
        scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);;
        if (scrn_cntx == NULL)
        {
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_CONTENT_CACHE_REQUEST_SCREEN_CNTX, scrn_cntx);
            return;
        }
        fsm_cntx = &(scrn_cntx->fsm);
        fsm = &(fsm_cntx->cntx.fsm_entry_folder);
        /* fsm callback here, only callback when all reading request is back && 
        current scrn is really waiting for reading result */
        
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_CONTENT_CACHE_REQUEST_FSM_STATUS, fsm->action);
        if (fsm->action == MMI_UM_UI_ACTION_GET_MSG_CONTENT)
        {
            mmi_um_ui_fsm_ef_check_data(fsm_cntx);
        }

}

#endif /* __MMI_UM_CONVERSATION_BOX_ENHANCE__ */

#ifdef __MMI_UM_CONVERSATION_BOX__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_get_thrd_info
 * DESCRIPTION
 *  Finite state machine should provide a function to get the thread detail
 *  information. It is used to get the thread deatil information for 
 *  screen handler.
 *
 * PARAMETERS
 *  scrn_id             [IN]: Screen id
 *  msg_info            [OUT]: the output of message deatil information
 *  thread_info         [OUT]: the output of thread detail information
 *
 * RETURNS
 *  MMI_TRUE: Has data
 *  MMI_FALSE: No data
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_ef_get_thrd_info(
                U16 scrn_id, 
                srv_um_msg_info_struct ***msg_info, 
                srv_um_thread_info_struct ***thread_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 check_thrd_info;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_fsm_node_struct *fsm_cntx;
    mmi_um_ui_fsm_entry_folder_struct *fsm;
    srv_um_msg_info_struct **msg_info_buffer;
    srv_um_thread_info_struct **thread_info_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);

    /* Data list is equal to NULL, no data. */
    /* During get message list state, no data */
    if (fsm->folder_info.data_list == NULL ||
        (fsm->state == MMI_UM_UI_FSM_EF_UPDATE_DATA && fsm->action == MMI_UM_UI_ACTION_GET_MSG_LIST))
    {
        (*msg_info) = NULL;
        return MMI_FALSE;
    }
    
    check_thrd_info = SRV_UM_RESULT_OK;
    /* checking data from service */
    msg_info_buffer = mmi_um_ui_ut_get_msg_info_buf();
    thread_info_buffer = NULL;
    if (NULL != thread_info)
    {
        thread_info_buffer = mmi_um_ui_ut_get_thread_info_buf();
    }
    check_thrd_info = srv_um_check_thread_info(
                            fsm->folder_type, 
                            &(fsm->folder_info.filter_type.thread_id), 
                            1, 
                            0, 
                            1, 
                            thread_info_buffer, 
                            msg_info_buffer);

    /* No data */
    if (check_thrd_info < SRV_UM_RESULT_OK)
    {
        (*msg_info) = NULL;
        if (NULL != thread_info)
        {
            (*thread_info) = NULL;
        }
        return MMI_FALSE;
    }
    else
    {
        (*msg_info) = msg_info_buffer;
        if (NULL != thread_info)
        {
            (*thread_info) = thread_info_buffer;
        }
        return MMI_TRUE;
    }
}
#endif /* __MMI_UM_CONVERSATION_BOX__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_get_action
 * DESCRIPTION
 *  Get the current action of finite state machine
 *
 * PARAMETERS
 *  fsm_cntx            [IN]: Finite state machine context
 *
 * RETURNS
 *  The aciton of current finite state machine
 *****************************************************************************/
U16 mmi_um_ui_fsm_ef_get_action(mmi_um_ui_fsm_node_struct *fsm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_entry_folder_struct *fsm;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);

    return (U16)fsm->action;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_set_box_identity
 * DESCRIPTION
 *  Set the box identity of this finite state machine
 *
 * PARAMETERS
 *  fsm_cntx            [IN]: Finite state machine context
 *  box_identity        [IN]: The box identity
 *
 * RETURNS
 *  The aciton of current finite state machine
 *****************************************************************************/
void mmi_um_ui_fsm_ef_set_box_identity(mmi_um_ui_fsm_node_struct *fsm_cntx, srv_um_box_identity_struct *box_identity)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_entry_folder_struct *fsm;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);

    /* Set the supporting message type */
    fsm->folder_type.msg_type = box_identity->msg_type;

    /* Set the supporting sim type */
    fsm->folder_type.sim_id = box_identity->sim_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_get_list_filter_type
 * DESCRIPTION
 *  Get the list filter type of finite state machine
 *
 * PARAMETERS
 *  fsm_cntx            [IN]: the finite state machine context
 *
 * RETURNS
 *  Pointer of sorting type
 *****************************************************************************/
srv_um_list_filter_struct *mmi_um_ui_fsm_ef_get_list_filter_type(mmi_um_ui_fsm_node_struct *fsm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &(fsm_cntx->cntx.fsm_entry_folder.folder_info.filter_type);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_set_list_filter_type
 * DESCRIPTION
 *  Set the sorting type of finite state machine
 *
 * PARAMETERS
 *  fsm_cntx            [IN]: the finite state machine context
 *  filter              [IN]: the filter type
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_fsm_ef_set_list_filter_type(mmi_um_ui_fsm_node_struct *fsm_cntx, srv_um_list_filter_struct filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&(fsm_cntx->cntx.fsm_entry_folder.folder_info.filter_type), 
           &filter, 
           sizeof(srv_um_list_filter_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_get_sim_type
 * DESCRIPTION
 *  Get the filter type of finite state machine
 *
 * PARAMETERS
 *  fsm_cntx            [IN]: the finite state machine context
 *
 * RETURNS
 *  Filter type of this FSM
 *****************************************************************************/
srv_um_sim_enum mmi_um_ui_fsm_ef_get_sim_type(mmi_um_ui_fsm_node_struct *fsm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return fsm_cntx->cntx.fsm_entry_folder.folder_type.sim_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_set_sim_type
 * DESCRIPTION
 *  Set the filter type of finite state machine
 *
 * PARAMETERS
 *  fsm_cntx            [IN]: the finite state machine context
 *  sim_type            [IN]: the sim type
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_fsm_ef_set_sim_type(mmi_um_ui_fsm_node_struct *fsm_cntx, srv_um_sim_enum sim_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm_cntx->cntx.fsm_entry_folder.folder_type.sim_id = sim_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_srv_check_msg_list
 * DESCRIPTION
 *  A wrapper function for different service function.
 *
 * PARAMETERS
 *  msg_box:            [IN]    The message box information
 *  filter:             [IN]    A filter to decide which message should be excluded
 *  cb_func:            [IN]    The callback function to notify the list is changed.
 *  user_data:          [IN]    A callback parameter in callback function
 *  list_cntx:          [OUT]   pionter to the list context
 *  mode:               [IN]    The folder mode in EntryFolder FSM.
 *
 * RETURNS
 *  srv_um_result_enum
 *
 * RETURN VALUES
 *  > 0: list context id
 *  = 0: impossible
 *  < 0: error
 *****************************************************************************/
S32 mmi_um_ui_fsm_ef_srv_check_msg_list(
                srv_um_box_identity_struct msg_box,
                srv_um_list_filter_struct *filter,
                srv_um_notify_list_handler cb_func,
                S32 user_data,
                srv_um_list_cntx_struct **list_cntx, 
                mmi_um_ui_folder_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error = 0;

    switch (mode)
    {
        case MMI_UM_FOLDER_MODE_DEFAULT:
    #ifdef __MMI_UM_CONVERSATION_BOX__
        case MMI_UM_FOLDER_MODE_THREAD_MSG:
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
        {
            error = srv_um_check_msg_list(
                                msg_box, 
                                filter, 
                                cb_func, 
                                user_data, 
                                list_cntx);
            break;
        }
    #ifdef __MMI_UM_CONVERSATION_BOX__
        case MMI_UM_FOLDER_MODE_CONVERSATION_BOX:
        {
        #ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
            error = srv_um_check_thread_list(
                                msg_box, 
                                filter, 
                                cb_func, 
                                user_data, 
                                list_cntx);
        #endif /* __SRV_UM_THREAD_MESSAGE_SUPPORT__ */
            break;
        }
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return error;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_srv_get_msg_list
 * DESCRIPTION
 *  A wrapper function for different service function.
 *
 * Parameters
 *   list_type:       [IN] type of list
 *   msg_box :        [IN] The message box information<p />
 *   filter :         [IN] A filter to decide which message should be excluded<p />
 *   cb_func :        [IN] The callback function when the response message back<p />
 *   user_data :      [IN] A callback parameter in callback function
 *   mode:            [IN]    The folder mode in EntryFolder FSM.
 *
 * Returns
 *   srv_um_result_enum
 *
 * Return Values
 *   Pos. Value :  A process identifier that use to control the whole process
 *   0 :           Impossible Value
 *   Neg. Value :  Error code
 *
 * See Also
 *   Callback Function: srv_um_get_msg_list_cb
 *   Callback Function Argument: srv_um_get_msg_list_result
 *****************************************************************************/
S32 mmi_um_ui_fsm_ef_srv_get_msg_list(
                srv_um_box_identity_struct msg_box, 
                srv_um_list_filter_struct *filter, 
                srv_um_get_list_cb cb_func, 
                S32 user_data, 
                mmi_um_ui_folder_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error = 0;

    switch (mode)
    {
        case MMI_UM_FOLDER_MODE_DEFAULT:
    #ifdef __MMI_UM_CONVERSATION_BOX__
        case MMI_UM_FOLDER_MODE_THREAD_MSG:
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
        {
            error = srv_um_get_msg_list(
                                msg_box, 
                                filter, 
                                cb_func, 
                                user_data);
            break;
        }
    #ifdef __MMI_UM_CONVERSATION_BOX__
        case MMI_UM_FOLDER_MODE_CONVERSATION_BOX:
        {
        #ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
            error = srv_um_get_thread_list(
                                msg_box, 
                                filter, 
                                cb_func, 
                                user_data);
        #endif /* __SRV_UM_THREAD_MESSAGE_SUPPORT__ */
            break;
        }
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return error;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_srv_check_msg_info
 * DESCRIPTION
 *  A wrapper function for different service function.
 *
 * PARAMETERS
 *  msg_box:            [IN]    The message box information
 *  msg_list:           [IN]    The message list
 *  list_info_size:     [IN]    Size of message list
 *  start_entry:        [IN]    The start entry in message list to get information
 *  msg_number:         [IN]    How much message to get
 *  msg_info:           [OUT]   A buffer contains message information
 *  mode:               [IN]    The folder mode in EntryFolder FSM.
 *
 * RETURNS
 *  srv_um_result_enum
 *
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 mmi_um_ui_fsm_ef_srv_check_msg_info(
                    srv_um_box_identity_struct msg_box, 
                    void *msg_list, 
                    U16 list_info_size, 
                    U16 start_entry, 
                    U16 msg_number, 
                    srv_um_msg_info_struct msg_info[], 
                    mmi_um_ui_folder_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error = 0;

    switch (mode)
    {
        case MMI_UM_FOLDER_MODE_DEFAULT:
    #ifdef __MMI_UM_CONVERSATION_BOX__
        case MMI_UM_FOLDER_MODE_THREAD_MSG:
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
        {
            error = srv_um_check_msg_info(
                                msg_box, 
                                (srv_um_msg_node_struct *)msg_list, 
                                list_info_size, 
                                start_entry, 
                                msg_number, 
                                msg_info);
            break;
        }
    #ifdef __MMI_UM_CONVERSATION_BOX__
        case MMI_UM_FOLDER_MODE_CONVERSATION_BOX:
        {
            /* Thread info does not the compatible function */
            MMI_ASSERT(0);
            break;
        }
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return error;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_srv_check_msg_info_by_ref
 * DESCRIPTION
 *  A wrapper function for different service function.
 *
 * PARAMETERS
 *  msg_box:            [IN]    The message box information
 *  msg_list:           [IN]    The message list
 *  list_info_size:     [IN]    Size of message list
 *  start_entry:        [IN]    The start entry in message list to get information
 *  msg_number:         [IN]    How much message to get
 *  msg_info:           [OUT]   A buffer contains message information
 *  thread_info:        [OUT]   A pointer array contains thread information pointers
 *  mode:               [IN]    The folder mode in EntryFolder FSM.
 *
 * RETURNS
 *  srv_um_result_enum
 *
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 mmi_um_ui_fsm_ef_srv_check_msg_info_by_ref(
                    srv_um_box_identity_struct msg_box, 
                    void *msg_list, 
                    U16 list_info_size, 
                    U16 start_entry, 
                    U16 msg_number, 
                    srv_um_msg_info_struct *msg_info[], 
                    srv_um_thread_info_struct *thread_info[], 
                    mmi_um_ui_folder_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error = 0;

    switch (mode)
    {
        case MMI_UM_FOLDER_MODE_DEFAULT:
    #ifdef __MMI_UM_CONVERSATION_BOX__
        case MMI_UM_FOLDER_MODE_THREAD_MSG:
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
        {
            error = srv_um_check_msg_info_by_ref(
                                msg_box, 
                                (srv_um_msg_node_struct *)msg_list, 
                                list_info_size, 
                                start_entry, 
                                msg_number, 
                                msg_info);
            break;
        }
    #ifdef __MMI_UM_CONVERSATION_BOX__
        case MMI_UM_FOLDER_MODE_CONVERSATION_BOX:
        {
        #ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
            error = srv_um_check_thread_info(
                                msg_box, 
                                (srv_um_thread_id_struct *)msg_list, 
                                list_info_size, 
                                start_entry, 
                                msg_number, 
                                thread_info, 
                                msg_info);
        #endif /* __SRV_UM_THREAD_MESSAGE_SUPPORT__ */
            break;
        }
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return error;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_srv_get_msg_info
 * DESCRIPTION
 *  A wrapper function for different service function.
 *
 * Parameters
 *   msg_box:        [IN]    The message box information
 *   msg_list:       [IN] The message list need to get message information
 *   msg_number:     [IN] How much message to get message information
 *   cb_func:        [IN] The callback function when the response message back
 *   user_data:      [IN] A callback parameter in callback function
 *   mode:           [IN]    The folder mode in EntryFolder FSM.
 *   
 * Returns
 *   srv_um_result_enum
 *
 * Return Values
 *   Pos. Value :  A process identifier that use to control the whole process
 *   0 :           Impossible value
 *   Neg. Value :  Error code
 *
 * See Also
 *   Callback Function: srv_um_get_msg_info_cb
 *   Callback Function Argument: srv_um_get_msg_info_result
 *****************************************************************************/
S32 mmi_um_ui_fsm_ef_srv_get_msg_info(
                    srv_um_box_identity_struct msg_box,
                    void *msg_list,
                    U16 msg_number,
                    void *cb_func,
                    S32 user_data, 
                    mmi_um_ui_folder_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error = 0;

    switch (mode)
    {
        case MMI_UM_FOLDER_MODE_DEFAULT:
    #ifdef __MMI_UM_CONVERSATION_BOX__
        case MMI_UM_FOLDER_MODE_THREAD_MSG:
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
        {
            error = srv_um_get_msg_info(
                                msg_box, 
                                (srv_um_msg_node_struct *)msg_list, 
                                msg_number, 
                                (srv_um_get_msg_info_cb)cb_func, 
                                user_data);
            break;
        }
    #ifdef __MMI_UM_CONVERSATION_BOX__
        case MMI_UM_FOLDER_MODE_CONVERSATION_BOX:
        {
        #ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
            error = srv_um_get_thread_info(
                                msg_box, 
                                (srv_um_thread_id_struct *)msg_list, 
                                msg_number, 
                                (srv_um_get_thread_info_cb)cb_func, 
                                user_data);
        #endif /* __SRV_UM_THREAD_MESSAGE_SUPPORT__ */
            break;
        }
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return error;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_get_folder_mode
 * DESCRIPTION
 *  Get the folder mode of finite state machine
 *
 * PARAMETERS
 *  fsm_cntx            [IN]: the finite state machine context
 *
 * RETURNS
 *  void
 *****************************************************************************/
mmi_um_ui_folder_mode_enum mmi_um_ui_fsm_ef_get_folder_mode(mmi_um_ui_fsm_node_struct *fsm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_folder_mode_enum mode;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mode = MMI_UM_FOLDER_MODE_TOTAL;

    if (MMI_UM_UI_FSM_ENTRY_FOLDER == fsm_cntx->type)
    {
        mode = fsm_cntx->cntx.fsm_entry_folder.folder_mode;
    }
    else
    {
        MMI_ASSERT(0);
    }

    return mode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_set_folder_mode
 * DESCRIPTION
 *  Set the folder mode of finite state machine
 *
 * PARAMETERS
 *  fsm_cntx            [IN]: the finite state machine context
 *  folder_mode         [IN]: Folder mode
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_fsm_ef_set_folder_mode(mmi_um_ui_fsm_node_struct *fsm_cntx, mmi_um_ui_folder_mode_enum folder_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm_cntx->cntx.fsm_entry_folder.folder_mode = folder_mode;
}

#ifdef  __MMI_UM_OP_FSM_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_op_init
 * DESCRIPTION
 *  The operation finite state machine. (initial state)
 *
 * PARAMETERS
 *  fsm_cntx            [IN]: the finite state machine context
 *  setting             [IN]: the setting of this finite state machine
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_fsm_op_init(mmi_um_ui_fsm_node_struct *fsm_cntx, mmi_um_ui_fsm_op_setting_struct setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_operation_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm = &(fsm_cntx->cntx.fsm_operation);
    memset(fsm, 0, sizeof(mmi_um_ui_fsm_operation_struct));

    /* External setting */
    fsm->scrn_id = setting.scrn_id;
    fsm->action_type = setting.action_type;
    fsm->num_of_mark_msg = setting.num_of_mark_msg;
    fsm->folder_type = setting.folder_type;
    fsm->data = setting.data;
    fsm_cntx->callback_hdlr = setting.scrn_callback_hdlr;

    /* Internal setting */
    fsm->pid = 0;
    fsm->state = MMI_UM_UI_FSM_OP_INIT;
    fsm->req_srv_status= MMI_UM_UI_REQ_SRV_NONE;
    fsm_cntx->type = MMI_UM_UI_FSM_OPERATION;
    fsm_cntx->event_hdlr = mmi_um_ui_fsm_event_hdlr;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_FSM_OPERATION_STATE, fsm->scrn_id, MMI_UM_UI_FSM_ENTRY_FOLDER, fsm->state);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_op_operation
 * DESCRIPTION
 *  The operation finite state machine. (operation state)
 *
 * PARAMETERS
 *  fsm_cntx            [IN]: the finite state machine context
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_fsm_op_operation(mmi_um_ui_fsm_node_struct * fsm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_operation_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm = &(fsm_cntx->cntx.fsm_operation);
    fsm->state = MMI_UM_UI_FSM_OP_OPERATION;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_FSM_OPERATION_STATE, fsm->scrn_id, MMI_UM_UI_FSM_ENTRY_FOLDER, fsm->state);

    fsm->req_srv_status = MMI_UM_UI_REQ_SRV_PROGRESS;

    switch (fsm->action_type)
    {
    #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_DELETE:
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_ARCHIVE:
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_SIM:
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_PHONE:
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_COPY_TO_SIM:
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_COPY_TO_PHONE:
        {
            mmi_um_ui_ms_cntx_struct *ms_cntx;
            
            ms_cntx = fsm->data;
            /* Set data */
            fsm->num_of_mark_msg = ms_cntx->num_of_mark;
            fsm->pid = srv_um_mark_several_op(
                                fsm->folder_type, 
                                ms_cntx->msg_table, 
                                ms_cntx->num_of_item, 
                                ms_cntx->mark_status, 
                                mmi_um_ui_ut_get_ms_action_by_fsm_type(fsm->action_type), 
                                mmi_um_ui_fsm_op_req_mark_several_op_cb, 
                                (S32) fsm->scrn_id);
            break;
        }
    #endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
        case MMI_UM_UI_ACTION_DELETE_FOLDER:
        {
            fsm->pid = srv_um_delete_folder(
                                fsm->folder_type, 
                                mmi_um_ui_fsm_op_req_delete_folder_cb, 
                                (S32) fsm->scrn_id);
            break;
        }
    #ifdef __MMI_UM_CONVERSATION_BOX__
        case MMI_UM_UI_ACTION_DELETE_THRD_MSG:
        case MMI_UM_UI_ACTION_MOV2ARC_THRD_MSG:
        {
            U32 mark_status[1];
            srv_um_thread_id_struct thread_id[1];

            /* only 1 thread_id */
            thread_id[0].type = fsm->thread_id.type;
            thread_id[0].value = fsm->thread_id.value;
            memset(mark_status, 0xff, sizeof(U32));

            /**************************************************************** 
               if number of thread list is smaller than SRV_UM_MAX_TRAVERSE_MSG_NUMBER(5), 
               service will copy the thread list into its internal ram
             ***************************************************************/
            fsm->pid = srv_um_mark_several_thread_op(
                                fsm->folder_type, 
                                thread_id, 
                                1, 
                                mark_status, 
                                mmi_um_ui_ut_get_ms_action_by_fsm_type(fsm->action_type), 
                                mmi_um_ui_fsm_op_req_ms_thread_op_cb, 
                                (S32) fsm->scrn_id);
            MMI_ASSERT(fsm->pid >= 0);
            break;
        }
        case MMI_UM_UI_ACTION_MS_DELETE_THRD_MSG:
        case MMI_UM_UI_ACTION_MS_MOV2ARC_THRD_MSG:
        {
            mmi_um_ui_ms_cntx_struct *ms_cntx;
            
            ms_cntx = fsm->data;
            /* Set data */
            fsm->num_of_mark_msg = ms_cntx->num_of_mark;
            fsm->pid = srv_um_mark_several_thread_op(
                                fsm->folder_type, 
                                ms_cntx->thrd_id_table, 
                                ms_cntx->num_of_item, 
                                ms_cntx->mark_status, 
                                mmi_um_ui_ut_get_ms_action_by_fsm_type(fsm->action_type), 
                                mmi_um_ui_fsm_op_req_ms_thread_op_cb, 
                                (S32) fsm->scrn_id);
            break;
        }
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }
    
    fsm_cntx->callback_hdlr(fsm->scrn_id, (U16)fsm->state, (U16)fsm->req_srv_status);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_op_deinit
 * DESCRIPTION
 *  The operation finite state machine. (de-initial state)
 *
 * PARAMETERS
 *  fsm_cntx            [IN]: the finite state machine context
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_fsm_op_deinit(mmi_um_ui_fsm_node_struct *fsm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_operation_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm = &(fsm_cntx->cntx.fsm_operation);
    fsm->state = MMI_UM_UI_FSM_OP_DEINIT;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_FSM_OPERATION_STATE, fsm->scrn_id, MMI_UM_UI_FSM_ENTRY_FOLDER, fsm->state);

    fsm->data = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_op_req_delete_folder_cb
 * DESCRIPTION
 *  The callback function for delete folder from service.
 *
 * PARAMETERS
 *  pid                 [IN]: Request id
 *  rsp                 [IN]: Response from service
 *  para                [IN]: Optional paramenter, it is used for screen id
 *
 * RETURNS
 *  Process result. Regards to srv_um_result_enum.
 *****************************************************************************/
S32 mmi_um_ui_fsm_op_req_delete_folder_cb(S32 pid, srv_um_delete_folder_result *rsp, S32 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_fsm_node_struct *fsm_cntx;
    mmi_um_ui_fsm_operation_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check pid if invalid */
    if (mmi_um_ui_fsm_check_invalid_pid(pid))
    {
        /* remove it */
        mmi_um_ui_fsm_remove_invalid_pid(pid);
        return SRV_UM_RESULT_OK;
    }
    
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx((U16)para);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_operation);

    MMI_ASSERT(pid == fsm->pid);

    /* Reset pid */
    fsm->pid = 0;

    /* Print the error log */
    if (rsp->error == SRV_UM_RESULT_CANCELLLED && fsm->req_srv_status == MMI_UM_UI_REQ_SRV_CANCELLING)
    {
        fsm->req_srv_status = MMI_UM_UI_REQ_SRV_CANCELLED;
    }

    /* The status may be MMI_UM_UI_REQ_SRV_CANCELLING, cancel by end user */   
    if (rsp->error >= SRV_UM_RESULT_OK)
    {
        fsm->req_srv_status = MMI_UM_UI_REQ_SRV_FINISH;
    }
    else
    {
        fsm->req_srv_status = MMI_UM_UI_REQ_SRV_FAIL;
    }
    fsm_cntx->callback_hdlr(fsm->scrn_id, (U16)fsm->state, (U16)fsm->req_srv_status);

    return SRV_UM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_op_req_mark_several_op_cb
 * DESCRIPTION
 *  The callback function for mark several operation from service.
 *
 * PARAMETERS
 *  pid                 [IN]: Request id
 *  rsp                 [IN]: Response from service
 *  para                [IN]: Optional paramenter, it is used for screen id
 *
 * RETURNS
 *  Process result. Regards to srv_um_result_enum.
 *****************************************************************************/
S32 mmi_um_ui_fsm_op_req_mark_several_op_cb(S32 pid, srv_um_mark_several_op_result *rsp, S32 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_fsm_node_struct *fsm_cntx;
    mmi_um_ui_fsm_operation_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check pid if invalid */
    if (mmi_um_ui_fsm_check_invalid_pid(pid))
    {
        /* remove it */
        mmi_um_ui_fsm_remove_invalid_pid(pid);
        return SRV_UM_RESULT_OK;
    }
    
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx((U16)para);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_operation);

    MMI_ASSERT(pid == fsm->pid);

    /* Reset the pid */
    fsm->pid = 0;

    /* Print the error log */
    if (rsp->error == SRV_UM_RESULT_CANCELLLED && fsm->req_srv_status == MMI_UM_UI_REQ_SRV_CANCELLING)
    {
        fsm->req_srv_status = MMI_UM_UI_REQ_SRV_CANCELLED;
    }

    /* The status may be MMI_UM_UI_REQ_SRV_CANCELLING, cancel by end user */
    if (rsp->no_of_fail == 0)
    {
        fsm->req_srv_status = MMI_UM_UI_REQ_SRV_FINISH;
    }
    else
    {
        fsm->req_srv_status = MMI_UM_UI_REQ_SRV_FAIL;
        fsm->num_of_fail = rsp->no_of_fail;
    }

    fsm_cntx->callback_hdlr(fsm->scrn_id, (U16)fsm->state, (U16)fsm->req_srv_status);

    return SRV_UM_RESULT_OK;
}


#ifdef __MMI_UM_CONVERSATION_BOX__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_op_req_ms_thread_op_cb
 * DESCRIPTION
 *  The callback function for mark several thread operation.
 *
 * PARAMETERS
 *  pid                 [IN]: Request id
 *  rsp                 [IN]: Response from service
 *  para                [IN]: Optional paramenter, it is used for screen id
 *
 * RETURNS
 *  Process result. Regards to srv_um_result_enum.
 *****************************************************************************/
S32 mmi_um_ui_fsm_op_req_ms_thread_op_cb(S32 pid, srv_um_mark_several_thread_op_result *rsp, S32 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_fsm_node_struct *fsm_cntx;
    mmi_um_ui_fsm_operation_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check pid if invalid */
    if (mmi_um_ui_fsm_check_invalid_pid(pid))
    {
        /* remove it */
        mmi_um_ui_fsm_remove_invalid_pid(pid);
        return SRV_UM_RESULT_OK;
    }
    
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx((U16)para);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_operation);

    MMI_ASSERT(pid == fsm->pid);

    /* Reset the pid */
    fsm->pid = 0;

    /* Print the error log */
    if (rsp->error == SRV_UM_RESULT_CANCELLLED && fsm->req_srv_status == MMI_UM_UI_REQ_SRV_CANCELLING)
    {
        fsm->req_srv_status = MMI_UM_UI_REQ_SRV_CANCELLED;
    }

    /* The status may be MMI_UM_UI_REQ_SRV_CANCELLING, cancel by end user */
    if (rsp->error == SRV_UM_RESULT_CANCELLLED || rsp->error >= SRV_UM_RESULT_OK)
    {
        if (rsp->no_of_fail == 0)
        {
            /* Success */
            fsm->req_srv_status = MMI_UM_UI_REQ_SRV_FINISH;
        }
        else
        {
            /* Fail, some process fail or not process yet. Not process is used for cancelling case */
            fsm->num_of_fail = rsp->no_of_fail;
            fsm->req_srv_status = MMI_UM_UI_REQ_SRV_FAIL;
        }
    }
    else
    {
        MMI_ASSERT(0);
    }

    fsm_cntx->callback_hdlr(fsm->scrn_id, (U16)fsm->state, (U16)fsm->req_srv_status);

    return SRV_UM_RESULT_OK;
}
#endif /* __MMI_UM_CONVERSATION_BOX__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_op_get_action
 * DESCRIPTION
 *  Get the action of operation finite state machine
 *
 * PARAMETERS
 *  fsm_cntx            [IN]: Finite state machine context
 *
 * RETURNS
 *  The aciton of current finite state machine
 *****************************************************************************/
U16 mmi_um_ui_fsm_op_get_action(mmi_um_ui_fsm_node_struct *fsm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_operation_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm = &(fsm_cntx->cntx.fsm_operation);

    MMI_ASSERT(fsm != NULL);

    return fsm->action_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_op_get_num_of_success
 * DESCRIPTION
 *  Get the number of success items
 *
 * PARAMETERS
 *  fsm_cntx            [IN]: Finite state machine context
 *
 * RETURNS
 *  The number of success of this operation
 *****************************************************************************/
U16 mmi_um_ui_fsm_op_get_num_of_success(mmi_um_ui_fsm_node_struct *fsm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_operation_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm = &(fsm_cntx->cntx.fsm_operation);

    MMI_ASSERT(fsm != NULL);

    return (fsm->num_of_mark_msg - fsm->num_of_fail);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_op_get_num_of_fail
 * DESCRIPTION
 *  Get the number of fail items
 *
 * PARAMETERS
 *  fsm_cntx            [IN]: Finite state machine context
 *
 * RETURNS
 *  The number of fail of this operation
 *****************************************************************************/
U16 mmi_um_ui_fsm_op_get_num_of_fail(mmi_um_ui_fsm_node_struct *fsm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_operation_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm = &(fsm_cntx->cntx.fsm_operation);

    MMI_ASSERT(fsm != NULL);

    return fsm->num_of_fail;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_op_set_op_type
 * DESCRIPTION
 *  Set the operation type
 *
 * PARAMETERS
 *  fsm_cntx            [IN]: Finite state machine context
 *  action_type         [IN]: Action type
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_fsm_op_set_op_type(mmi_um_ui_fsm_node_struct *fsm_cntx, mmi_um_ui_req_srv_action_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_operation_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm = &(fsm_cntx->cntx.fsm_operation);
    MMI_ASSERT(fsm != NULL);

    fsm->action_type = action;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_op_set_thrd_id
 * DESCRIPTION
 *  Set the thread id
 *
 * PARAMETERS
 *  fsm_cntx            [IN]: Finite state machine context
 *  thread_id           [IN]: Thread id
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_fsm_op_set_thrd_id(mmi_um_ui_fsm_node_struct *fsm_cntx, srv_um_thread_id_struct *thread_id)
{
#ifdef __MMI_UM_CONVERSATION_BOX__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_operation_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm = &(fsm_cntx->cntx.fsm_operation);
    MMI_ASSERT(fsm != NULL);

    fsm->thread_id.type = thread_id->type;
    fsm->thread_id.value = thread_id->value;
#endif /* __MMI_UM_CONVERSATION_BOX__ */
}

#endif/* __MMI_UM_OP_FSM_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_get_data_list_ptr
 * DESCRIPTION
 *  Get the data list pointer from the finite state machine context.
 *
 * PARAMETERS
 *  fsm_cntx            [IN]: Finite state machine context
 *
 * RETURNS
 *  The pointer of data list.
 *  NULL: no data list
 *****************************************************************************/
srv_um_list_cntx_struct *mmi_um_ui_fsm_get_data_list_ptr(mmi_um_ui_fsm_node_struct *fsm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_list_cntx_struct *data_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_list = NULL;
    
    switch (fsm_cntx->type)
    {
        case MMI_UM_UI_FSM_ENTRY_FOLDER:
        {
            data_list = fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list;
            break;
        }
        default:
        {
            break;
        }
    }

    return data_list;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_set_data_list_ptr
 * DESCRIPTION
 *  Set the data list pointer to the finite state machine context.
 *
 * PARAMETERS
 *  fsm_cntx            [IN]: Finite state machine context
 *  data_list           [IN]: Data list pointer
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_fsm_set_data_list_ptr(
                    mmi_um_ui_fsm_node_struct *fsm_cntx, 
                    srv_um_list_cntx_struct *data_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    switch (fsm_cntx->type)
    {
        case MMI_UM_UI_FSM_ENTRY_FOLDER:
        {
            fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list = data_list;
            break;
        }
        default:
        {
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_get_fsm_state
 * DESCRIPTION
 *  Get the current finite state machine state
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    Finite state machine context
 *
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_um_ui_fsm_get_fsm_state(mmi_um_ui_fsm_node_struct *fsm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    state = 0;
    
    switch (fsm_cntx->type)
    {
        case MMI_UM_UI_FSM_ENTRY_LIST:
        {
            state = fsm_cntx->cntx.fsm_entry_list.state;
            break;
        }
        case MMI_UM_UI_FSM_ENTRY_FOLDER:
        {
            state = fsm_cntx->cntx.fsm_entry_folder.state;
            break;
        }
        case MMI_UM_UI_FSM_OPERATION:
        {
            state = fsm_cntx->cntx.fsm_operation.state;
            break;
        }
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_get_fsm_req_srv_status
 * DESCRIPTION
 *  Get the current status of request service.
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    Finite state machine context
 *
 * RETURNS
 *  Status of request service
 *****************************************************************************/
U16 mmi_um_ui_fsm_get_fsm_req_srv_status(mmi_um_ui_fsm_node_struct *fsm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = 0;
    
    switch (fsm_cntx->type)
    {
        case MMI_UM_UI_FSM_ENTRY_LIST:
        {
            status = fsm_cntx->cntx.fsm_entry_list.req_srv_status;
            break;
        }
        case MMI_UM_UI_FSM_ENTRY_FOLDER:
        {
            status = fsm_cntx->cntx.fsm_entry_folder.req_srv_status;
            break;
        }
        case MMI_UM_UI_FSM_OPERATION:
        {
            status = fsm_cntx->cntx.fsm_operation.req_srv_status;
            break;
        }
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_query_status
 * DESCRIPTION
 *  Query current status of this finite state machine.
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    Finite state machine context
 *
 * RETURNS
 *  Status of request service
 *****************************************************************************/
U8 mmi_um_ui_fsm_query_status(mmi_um_ui_fsm_node_struct *fsm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 status;
    S32 num_of_finish;
    S32 num_of_total;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = 0;
    
    switch (fsm_cntx->type)
    {
        case MMI_UM_UI_FSM_ENTRY_LIST:
        case MMI_UM_UI_FSM_ENTRY_FOLDER:
        {
            MMI_ASSERT(0);
            break;
        }
        case MMI_UM_UI_FSM_OPERATION:
        {
            MMI_ASSERT(fsm_cntx->cntx.fsm_operation.pid != 0);
            status = num_of_finish = num_of_total = 0;
            srv_um_get_request_progress(fsm_cntx->cntx.fsm_operation.pid, 
                                        &num_of_finish, 
                                        &num_of_total);
            if (0 < num_of_total)
            {
                status = (num_of_finish * 100) / num_of_total;
            }
            break;
        }
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_eh_dummy
 * DESCRIPTION
 *  Dummy function for non-processed event.
 *
 * PARAMETERS
 *  scrn_id             [IN]: Screen id
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_eh_dummy(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return MMI_TRUE;
}


#ifdef __MMI_UM_EL_FSM_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_el_eh_init_init
 * DESCRIPTION
 *  Entry list finite state machine event handler.
 *  FSM state       : INIT
 *  Receive event   : INIT
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_el_eh_init_init(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_el_inside(fsm_cntx);
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_el_eh_inside_refresh
 * DESCRIPTION
 *  Entry list finite state machine event handler.
 *  FSM state       : INSIDE
 *  Receive event   : REFRESH
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_el_eh_inside_refresh(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_el_inside(fsm_cntx);
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_el_eh_inside_check
 * DESCRIPTION
 *  Entry list finite state machine event handler.
 *  FSM state       : INSIDE
 *  Receive event   : CHECK
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_el_eh_inside_check(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_el_inside(fsm_cntx);
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_el_eh_inside_unready
 * DESCRIPTION
 *  Entry list finite state machine event handler.
 *  FSM state       : INSIDE
 *  Receive event   : UNREADY
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_el_eh_inside_unready(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_el_update(fsm_cntx);
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_el_eh_update_abort
 * DESCRIPTION
 *  Entry list finite state machine event handler.
 *  FSM state       : UPDATE
 *  Receive event   : ABORT
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_el_eh_update_abort(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    S32 pid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_TRUE;

    if (fsm_cntx->cntx.fsm_entry_list.pid != 0)
    {
        fsm_cntx->cntx.fsm_entry_list.req_srv_status = MMI_UM_UI_REQ_SRV_CANCELLED;
        /* add the pid into invalid array */
        pid = fsm_cntx->cntx.fsm_entry_list.pid;
        mmi_um_ui_fsm_add_invalid_pid(pid);
        /* reset the pid of FSM */
        fsm_cntx->cntx.fsm_entry_list.pid = 0;
        
        if (srv_um_cancel_request(pid) < SRV_UM_RESULT_OK)
        {
            MMI_ASSERT(0);
        }
    }
    
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_el_eh_update_delete
 * DESCRIPTION
 *  Entry list finite state machine event handler.
 *  FSM state       : UPDATE
 *  Receive event   : DELETE
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_el_eh_update_delete(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    S32 pid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_TRUE;

    /* has action */
    if (fsm_cntx->cntx.fsm_entry_list.pid != 0)
    {
        fsm_cntx->cntx.fsm_entry_list.req_srv_status = MMI_UM_UI_REQ_SRV_CANCELLED;
        /* add the pid into invalid array */
        pid = fsm_cntx->cntx.fsm_entry_list.pid;
        mmi_um_ui_fsm_add_invalid_pid(pid);
        /* reset the pid of FSM */
        fsm_cntx->cntx.fsm_entry_list.pid = 0;
        
        /* Cancel action */
        if (srv_um_cancel_request(pid) < SRV_UM_RESULT_OK)
        {
            MMI_ASSERT(0);
        }
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_el_eh_update_check
 * DESCRIPTION
 *  Entry list finite state machine event handler.
 *  FSM state       : UPDATE
 *  Receive event   : CHECK
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_el_eh_update_check(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_entry_list_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Notify screen handler to modify the screen */
    fsm = &(fsm_cntx->cntx.fsm_entry_list);
    
    fsm_cntx->callback_hdlr(fsm->scrn_id, (U16)fsm->state, (U16)fsm->req_srv_status);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_el_eh_update_ready
 * DESCRIPTION
 *  Entry list finite state machine event handler.
 *  FSM state       : UPDATE
 *  Receive event   : READY
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_el_eh_update_ready(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fsm_cntx->cntx.fsm_entry_list.req_srv_status == MMI_UM_UI_REQ_SRV_WAIT_READY)
    {
        mmi_um_ui_fsm_el_update(fsm_cntx);
    }
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_el_eh_update_unready
 * DESCRIPTION
 *  Entry list finite state machine event handler.
 *  FSM state       : UPDATE
 *  Receive event   : UNREADY
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_el_eh_update_unready(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    S32 pid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_TRUE;

    if (fsm_cntx->cntx.fsm_entry_list.pid != 0)
    {
        fsm_cntx->cntx.fsm_entry_list.req_srv_status = MMI_UM_UI_REQ_SRV_CANCELLED;
        /* add the pid into invalid array */
        pid = fsm_cntx->cntx.fsm_entry_list.pid;
        mmi_um_ui_fsm_add_invalid_pid(pid);
        /* reset the pid of FSM */
        fsm_cntx->cntx.fsm_entry_list.pid = 0;
        
        if (srv_um_cancel_request(pid) < SRV_UM_RESULT_OK)
        {
            MMI_ASSERT(0);
        }
    }
    else
    {
        /* wait ready indication */
        fsm_cntx->cntx.fsm_entry_list.req_srv_status = MMI_UM_UI_REQ_SRV_NONE;
    }

    mmi_um_ui_fsm_el_update(fsm_cntx);
    
    return result;
}

#endif /* __MMI_UM_EL_FSM_SUPPORT__  */

/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_eh_init_init
 * DESCRIPTION
 *  Entry folder finite state machine event handler.
 *  FSM state       : INIT
 *  Receive event   : INIT
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_ef_eh_init_init(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_ef_check_ready(fsm_cntx);
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_eh_init_delete
 * DESCRIPTION
 *  Entry folder finite state machine event handler.
 *  FSM state       : INIT
 *  Receive event   : DELETE
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_ef_eh_init_delete(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_ef_deinit(fsm_cntx);
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_eh_init_kp_list
 * DESCRIPTION
 *  Entry folder finite state machine event handler.
 *  FSM state       : INIT
 *  Receive event   : EMPTY_DATA
 *
 *  This event is used to avoid re-get the data list again because it has 
 *  already known this folder is empty. It does not need to check it again.
 *  It could avoid the twinkle loading screen.
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_ef_eh_init_kp_list(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check ready first. If it is not ready, it should not set the flag as FALSE */
    if (srv_um_check_ready_type(fsm_cntx->cntx.fsm_entry_folder.folder_type.msg_type))
    {
        fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list_updated = MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_eh_cr_delete
 * DESCRIPTION
 *  Entry folder finite state machine event handler.
 *  FSM state       : CHECK_READY
 *  Receive event   : DELETE
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_ef_eh_cr_delete(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_ef_deinit(fsm_cntx);
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_eh_cr_ready
 * DESCRIPTION
 *  Entry folder finite state machine event handler.
 *  FSM state       : CHECK_READY
 *  Receive event   : READY
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_ef_eh_cr_ready(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_ef_check_ready(fsm_cntx);
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_eh_cr_check
 * DESCRIPTION
 *  Entry folder finite state machine event handler.
 *  FSM state       : CHECK_READY
 *  Receive event   : CHECK
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_ef_eh_cr_check(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_ef_check_ready(fsm_cntx);
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_eh_cd_refresh
 * DESCRIPTION
 *  Entry folder finite state machine event handler.
 *  FSM state       : CHECK_DATA
 *  Receive event   : REFRESH
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_ef_eh_cd_refresh(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list_updated = MMI_TRUE;
    mmi_um_ui_fsm_ef_check_data(fsm_cntx);
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_eh_cd_delete
 * DESCRIPTION
 *  Entry folder finite state machine event handler.
 *  FSM state       : CHECK_DATA
 *  Receive event   : DELETE
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_ef_eh_cd_delete(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_ef_deinit(fsm_cntx);
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_eh_cd_check
 * DESCRIPTION
 *  Entry folder finite state machine event handler.
 *  FSM state       : CHECK_DATA
 *  Receive event   : CHECK
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_ef_eh_cd_check(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_ef_check_data(fsm_cntx);
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_eh_cd_unready
 * DESCRIPTION
 *  Entry folder finite state machine event handler.
 *  FSM state       : CHECK_DATA
 *  Receive event   : UNREADY
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_ef_eh_cd_unready(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list_updated = MMI_TRUE;
    mmi_um_ui_fsm_ef_check_ready(fsm_cntx);
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_eh_cd_rel_list
 * DESCRIPTION
 *  Entry folder finite state machine event handler.
 *  FSM state       : CHECK_DATA
 *  Receive event   : REL_DATA_LIST
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_ef_eh_cd_rel_list(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* release and clean it */
    if (0 < fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id)
    {
        srv_um_release_msg_list(fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id, MMI_TRUE);
        fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id = 0;
        fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list = NULL;
    }
    fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list_updated = MMI_TRUE;
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_eh_cd_up_list
 * DESCRIPTION
 *  Entry folder finite state machine event handler.
 *  FSM state       : CHECK_DATA
 *  Receive event   : UPDATE_DATA_LIST
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_ef_eh_cd_up_list(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list_updated = MMI_TRUE;
    /* release data list */
    if (0 < fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id)
    {
        srv_um_release_msg_list(fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id, MMI_TRUE);
        fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id = 0;
        fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list = NULL;
    }
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_eh_ud_refresh
 * DESCRIPTION
 *  Entry folder finite state machine event handler.
 *  FSM state       : UPDATE_DATA
 *  Receive event   : REFRESH
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_ef_eh_ud_refresh(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fsm_cntx->cntx.fsm_entry_folder.action == MMI_UM_UI_ACTION_GET_MSG_INFO)
    {
        fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list_updated = MMI_TRUE;
    }
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_eh_ud_check
 * DESCRIPTION
 *  Entry folder finite state machine event handler.
 *  FSM state       : UPDATE_DATA
 *  Receive event   : CHECK
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_ef_eh_ud_check(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_entry_folder_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Notify screen handler to modify the screen */
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);
    
    fsm_cntx->callback_hdlr(fsm->scrn_id, (U16)fsm->state, (U16)fsm->req_srv_status);

    return MMI_TRUE;
}

#ifdef __MMI_UM_ULTRA_SLIM__
void mmi_um_ui_fsm_ef_eh_common_unready_rel_list(mmi_um_ui_fsm_node_struct *fsm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 pid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list_updated = MMI_TRUE;

    if (fsm_cntx->cntx.fsm_entry_folder.pid != 0)
    {
        fsm_cntx->cntx.fsm_entry_folder.req_srv_status = MMI_UM_UI_REQ_SRV_CANCELLED;
        /* release data list */
        if (0 < fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id)
        {
            srv_um_release_msg_list(fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id, MMI_TRUE);
            fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id = 0;
            fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list = NULL;
        }
        fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list_updated = MMI_TRUE;
        /* add the pid into invalid array */
        pid = fsm_cntx->cntx.fsm_entry_folder.pid;
        mmi_um_ui_fsm_add_invalid_pid(pid);
        /* reset the pid of FSM */
        fsm_cntx->cntx.fsm_entry_folder.pid = 0;
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_eh_ud_delete
 * DESCRIPTION
 *  Entry folder finite state machine event handler.
 *  FSM state       : UPDATE_DATA
 *  Receive event   : DELETE
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_ef_eh_ud_delete(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    S32 pid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_TRUE;

    /* has action */
    if (fsm_cntx->cntx.fsm_entry_folder.pid != 0)
    {
#ifndef __MMI_UM_ULTRA_SLIM__
        fsm_cntx->cntx.fsm_entry_folder.req_srv_status = MMI_UM_UI_REQ_SRV_CANCELLED;
        /* release data list */
        if (0 < fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id)
        {
            srv_um_release_msg_list(fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id, MMI_TRUE);
            fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id = 0;
            fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list = NULL;
        }
        fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list_updated = MMI_TRUE;
        /* add the pid into invalid array */
        pid = fsm_cntx->cntx.fsm_entry_folder.pid;
        mmi_um_ui_fsm_add_invalid_pid(pid);
        /* reset the pid of FSM */
        fsm_cntx->cntx.fsm_entry_folder.pid = 0;
        
        if (srv_um_cancel_request(pid) < SRV_UM_RESULT_OK)
        {
            MMI_ASSERT(0);
        }      
#else
	pid = fsm_cntx->cntx.fsm_entry_folder.pid;
    mmi_um_ui_fsm_ef_eh_common_unready_rel_list(fsm_cntx);
	if (srv_um_cancel_request(pid) < SRV_UM_RESULT_OK)
        {
            MMI_ASSERT(0);
        }
#endif
    }
    else
    {
        mmi_um_ui_fsm_ef_deinit(fsm_cntx);
    }
    
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_eh_ud_unready
 * DESCRIPTION
 *  Entry folder finite state machine event handler.
 *  FSM state       : UPDATE_DATA
 *  Receive event   : UNREADY
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_ef_eh_ud_unready(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    S32 pid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_TRUE;
#ifndef __MMI_UM_ULTRA_SLIM__
    fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list_updated = MMI_TRUE;

    if (fsm_cntx->cntx.fsm_entry_folder.pid != 0)
    {
        fsm_cntx->cntx.fsm_entry_folder.req_srv_status = MMI_UM_UI_REQ_SRV_CANCELLED;
        /* release data list */
        if (0 < fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id)
        {
            srv_um_release_msg_list(fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id, MMI_TRUE);
            fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id = 0;
            fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list = NULL;
        }
        fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list_updated = MMI_TRUE;
        /* add the pid into invalid array */
        pid = fsm_cntx->cntx.fsm_entry_folder.pid;
        mmi_um_ui_fsm_add_invalid_pid(pid);
        /* reset the pid of FSM */
        fsm_cntx->cntx.fsm_entry_folder.pid = 0;
        
        if (srv_um_cancel_request(pid) < SRV_UM_RESULT_OK)
        {
            result = MMI_FALSE;
        }
    }
#else
    if (fsm_cntx->cntx.fsm_entry_folder.pid != 0)
    {
    pid = fsm_cntx->cntx.fsm_entry_folder.pid;
    mmi_um_ui_fsm_ef_eh_common_unready_rel_list(fsm_cntx);
        if (srv_um_cancel_request(pid) < SRV_UM_RESULT_OK)
        {
            result = MMI_FALSE;
        }
    }
#endif
    
    mmi_um_ui_fsm_ef_check_ready(fsm_cntx);
    
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_eh_ud_rel_list
 * DESCRIPTION
 *  Entry folder finite state machine event handler.
 *  FSM state       : UPDATE_DATA
 *  Receive event   : REL_DATA_LIST
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_ef_eh_ud_rel_list(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 pid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Release data list */
#ifndef __MMI_UM_ULTRA_SLIM__
    if (0 < fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id)
    {
        srv_um_release_msg_list(fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id, MMI_TRUE);
        fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id = 0;
        fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list = NULL;
    }
    fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list_updated = MMI_TRUE;
    
    if (fsm_cntx->cntx.fsm_entry_folder.pid != 0)
    {
        fsm_cntx->cntx.fsm_entry_folder.req_srv_status = MMI_UM_UI_REQ_SRV_CANCELLED;
        /* add the pid into invalid array */
        pid = fsm_cntx->cntx.fsm_entry_folder.pid;
        mmi_um_ui_fsm_add_invalid_pid(pid);
        /* reset the pid of FSM */
        fsm_cntx->cntx.fsm_entry_folder.pid = 0;
        
        if (srv_um_cancel_request(pid) < SRV_UM_RESULT_OK)
        {
            MMI_ASSERT(0);
        }
    }
#else
        if (fsm_cntx->cntx.fsm_entry_folder.pid != 0)
        {
        pid = fsm_cntx->cntx.fsm_entry_folder.pid;
        mmi_um_ui_fsm_ef_eh_common_unready_rel_list(fsm_cntx);
            if (srv_um_cancel_request(pid) < SRV_UM_RESULT_OK)
            {
                MMI_ASSERT(0);
            }
        }
#endif
    /* entry check_data state */
    mmi_um_ui_fsm_ef_check_data(fsm_cntx);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_ef_eh_ud_up_list
 * DESCRIPTION
 *  Entry folder finite state machine event handler.
 *  FSM state       : UPDATE_DATA
 *  Receive event   : UPDATE_DATA_LIST
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_ef_eh_ud_up_list(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list_updated = MMI_TRUE;
    
    return MMI_TRUE;
}

#ifdef __MMI_UM_OP_FSM_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_op_eh_init_init
 * DESCRIPTION
 *  Operation finite state machine event handler.
 *  FSM state       : INIT
 *  Receive event   : INIT
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_op_eh_init_init(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_op_operation(fsm_cntx);
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_op_eh_init_delete
 * DESCRIPTION
 *  Operation finite state machine event handler.
 *  FSM state       : INIT
 *  Receive event   : DELETE
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_op_eh_init_delete(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_op_deinit(fsm_cntx);
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_op_eh_init_set_data
 * DESCRIPTION
 *  Operation finite state machine event handler.
 *  FSM state       : INIT
 *  Receive event   : SET_FSM_DATA
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_op_eh_init_set_data(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_operation_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm = &(fsm_cntx->cntx.fsm_operation);
    fsm->data = arg;
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_op_eh_op_abort
 * DESCRIPTION
 *  Operation finite state machine event handler.
 *  FSM state       : OPERATION
 *  Receive event   : ABORT
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_op_eh_op_abort(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_TRUE;

    /* has action */
    if (fsm_cntx->cntx.fsm_operation.pid != 0 &&
        fsm_cntx->cntx.fsm_operation.req_srv_status != MMI_UM_UI_REQ_SRV_CANCELLING)
    {
        fsm_cntx->cntx.fsm_operation.req_srv_status = MMI_UM_UI_REQ_SRV_CANCELLING;

        /* inform screen handler result */
        /* Callback Screen handler first because service may call fsm's callback during cancelling request */
        fsm_cntx->callback_hdlr(
                fsm_cntx->cntx.fsm_operation.scrn_id, 
                (U16)fsm_cntx->cntx.fsm_operation.state, 
                (U16)fsm_cntx->cntx.fsm_operation.req_srv_status);

        if (srv_um_cancel_request(fsm_cntx->cntx.fsm_operation.pid) < SRV_UM_RESULT_OK)
        {
            MMI_ASSERT(0);
        }
    }
    else
    {
        /* inform screen handler result */
        fsm_cntx->callback_hdlr(
                fsm_cntx->cntx.fsm_operation.scrn_id, 
                (U16)fsm_cntx->cntx.fsm_operation.state, 
                (U16)fsm_cntx->cntx.fsm_operation.req_srv_status);
    }
    
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_op_eh_op_delete
 * DESCRIPTION
 *  Operation finite state machine event handler.
 *  FSM state       : OPERATION
 *  Receive event   : DELETE
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_op_eh_op_delete(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    S32 pid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_TRUE;

    if (fsm_cntx->cntx.fsm_operation.pid != 0)
    {
        /* add the pid into invalid array */
        pid = fsm_cntx->cntx.fsm_operation.pid;
        mmi_um_ui_fsm_add_invalid_pid(pid);
        /* reset the pid of FSM */
        fsm_cntx->cntx.fsm_operation.pid = 0;
        
        if (fsm_cntx->cntx.fsm_operation.req_srv_status == MMI_UM_UI_REQ_SRV_PROGRESS)
        {
            if (srv_um_cancel_request(pid) < SRV_UM_RESULT_OK)
            {
                MMI_ASSERT(0);
            }
        }
        fsm_cntx->cntx.fsm_operation.req_srv_status = MMI_UM_UI_REQ_SRV_CANCELLED;
    }
    else
    {
        mmi_um_ui_fsm_op_deinit(fsm_cntx);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_op_eh_op_set_data
 * DESCRIPTION
 *  Operation finite state machine event handler.
 *  FSM state       : OPERATION
 *  Receive event   : SET_FSM_DATA
 *
 * PARAMETERS
 *  fsm_cntx:           [IN]    finite state machine context
 *  arg:                [IN]    argument of event
 *
 * RETURNS
 *  Processs result
 *****************************************************************************/
MMI_BOOL mmi_um_ui_fsm_op_eh_op_set_data(mmi_um_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_fsm_operation_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm = &(fsm_cntx->cntx.fsm_operation);
    
    if (fsm->req_srv_status == MMI_UM_UI_REQ_SRV_NONE)
    {
        fsm->data = arg;
    }
    
    return MMI_TRUE;
}
#endif /* __MMI_UM_OP_FSM_SUPPORT__ */
#endif /* __UM_SUPPORT__ */
