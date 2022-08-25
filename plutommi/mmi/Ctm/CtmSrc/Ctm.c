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
 *  Modification Notice:
 *  --------------------------
 *  This software is modified by MediaTek Inc. and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   Ctm.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Cellular Text telephone Modem Application
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __CTM_SUPPORT__

#include "UcmSrvGprot.h" /* srv_ucm_act_request */
#include "UcmResDef.h"

#include "CtmSrvGprot.h"

#include "CtmGprot.h"
#include "CtmProt.h"
#include "mmi_rp_app_ctm_def.h"
#include "fseditorcuigprot.h"

#include "CommonScreensResDef.h"
#include "AlertScreen.h" /* mmi_alert_result_evt_struct */
#include "TimerEvents.h"
#include "wgui_categories_util.h"


static mmi_ctm_cntxt_struct g_mmi_ctm_cntxt;
mmi_ctm_cntxt_struct *ctm_p = &g_mmi_ctm_cntxt;

mmi_imm_input_mode_enum g_ctm_required_input_modes[] = {
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC,
    IMM_INPUT_MODE_123_SYMBOLS,
    IMM_INPUT_MODE_SMART_UPPERCASE_ABC,
    IMM_INPUT_MODE_NONE   };


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_init
 * DESCRIPTION
 *  To Initialize the CTM Call application
 *  
 *  This function sets up the handlers required for event flow and
 *  application management
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(ctm_p, 0, sizeof(mmi_ctm_cntxt_struct));
    ctm_p->grp_id = GRP_ID_INVALID;
    ctm_p->conn_confirm_id = GRP_ID_INVALID;
}


/* Static function begin */
/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_alert_dismiss
 * DESCRIPTION
 *  dismiss the popup message "Connecting"
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ctm_alert_dismiss(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID conn_confirm_id = ctm_p->conn_confirm_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (conn_confirm_id != GRP_ID_INVALID)
    {
        mmi_alert_dismiss(conn_confirm_id);
        ctm_p->conn_confirm_id = GRP_ID_INVALID;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_group_close
 * DESCRIPTION
 *  close CTM screen group
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ctm_group_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ctm_p->grp_id != GRP_ID_INVALID)
    {
        mmi_frm_group_close(ctm_p->grp_id);
        ctm_p->grp_id = GRP_ID_INVALID;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_group_proc
 * DESCRIPTION
 *  proc of CTM screen group
 * PARAMETERS
 *  param    
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_ctm_group_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_group_event_struct *editor_event = NULL;
    MMI_ID editor_id = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param->evt_id)
    {
        case EVT_ID_GROUP_ACTIVE:
            break;
        case EVT_ID_GROUP_INACTIVE:        
            break;
        case EVT_ID_GROUP_DEINIT:
            break;

        case EVT_ID_CUI_FSEDITOR_SUBMMIT:  
            editor_event = (mmi_group_event_struct *)param;
            editor_id = editor_event->sender_id;
            cui_fseditor_get_text(editor_id, (WCHAR *)ctm_p->editor_buffer, MMI_CTM_MAX_EDITOR_BUFFER_LEN);
            mmi_ctm_edit_done();
            /* Close fseditor and back to SCR_ID_CTM_TALKING. */
            cui_fseditor_close(editor_id);
            break; 
            
        case EVT_ID_CUI_FSEDITOR_ABORT:
            editor_event = (mmi_group_event_struct *)param;
            editor_id = editor_event->sender_id;
            cui_fseditor_close(editor_id);
            break;
            
         case EVT_ID_CUI_FSEDITOR_EMPTY:
            editor_event = (mmi_group_event_struct *)param;
            editor_id = editor_event->sender_id;
            cui_fseditor_set_custom_options_menu(editor_id, MMI_TRUE, NULL, 0);
            break;
            
        case EVT_ID_CUI_FSEDITOR_NOT_EMPTY:
            editor_event = (mmi_group_event_struct *)param;
            editor_id = editor_event->sender_id;
            cui_fseditor_set_custom_options_menu(editor_id, MMI_FALSE, NULL, 0);
            break;
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_popup_callback
 * DESCRIPTION
 *  proc of CTM popup
 * PARAMETERS
 *  param    
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_ctm_popup_callback(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *alert = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/       
    switch(param->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
        {
            alert = (mmi_alert_result_evt_struct *)param;

            switch(alert->result)
            {
                case MMI_ALERT_NORMAL_EXIT:
                case MMI_ALERT_INTERRUPT_EXIT:
                case MMI_ALERT_NO_SHOW:
                    mmi_ctm_group_close();
                    break;
                
            }
            break;
        }
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_prepare_group
 * DESCRIPTION
 *  prepare CTM screen group
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_ID mmi_ctm_prepare_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID grp_id = ctm_p->grp_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/       
    if (grp_id != GRP_ID_INVALID)
    {
        mmi_frm_group_close(grp_id);
        grp_id = GRP_ID_INVALID;
    }

    grp_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_CTM, mmi_ctm_group_proc, NULL);
    if (grp_id != GRP_ID_INVALID)
    {
        grp_id = mmi_frm_group_enter(grp_id,MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }    

    return grp_id;
}
/* Static function end */

/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_entry_connect_animation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_entry_connect_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg,CNFM_TYPE_USER_DEFINE);
    /* If group is in inactive state, the message should not be shown */
    arg.parent_id = ctm_p->grp_id;
    arg.f_auto_dismiss = MMI_FALSE;
    arg.f_enter_history = MMI_TRUE;

    ctm_p->conn_confirm_id = mmi_confirm_display((UI_string_type) GetString(STR_ID_CTM_CONNECTING), MMI_EVENT_PROGRESS, &arg);                
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_entry_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_entry_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 length;
    MMI_ID editor_id = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_id = cui_fseditor_create(ctm_p->grp_id);
    if (editor_id != GRP_ID_INVALID)
    {
        /* Set fseditor parameters. */

        /* Set title */
        cui_fseditor_set_title(editor_id, STR_GLOBAL_EDIT, 0);

        /* Set Text 
           Because MMI_CTM_MAX_EDITOR_BUFFER_LEN < CUI_FSEDITOR_MAX_BUFFER_SIZE,
           We don't need to prepare editor buffer for fseditor */
        length = MMI_CTM_MAX_EDITOR_COUNT - ctm_p->pending_len;
        cui_fseditor_set_text(editor_id, NULL, 0, length);

        /* Set input method */
        cui_fseditor_set_characters_filter(editor_id, MMI_TRUE, L" -Z");

        cui_fseditor_set_input_method(editor_id, IMM_INPUT_TYPE_USER_SPECIFIC, g_ctm_required_input_modes, 0);

        /* Run!! */
        cui_fseditor_run(editor_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_edit_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_edit_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* allow press OK in the editor */
    len = mmi_ucs2strlen((CHAR*)ctm_p->editor_buffer);
    if (!len)
    {
        /* there won't be any rsp from L4C for now if send text length is 0
         * event L4C responds with send_text_rsp fail, there is still problems
         * with sending an empty string (will keep retrying over and over again) */
        /* not allow to send an empty string */
        return;
    }

    mmi_ucs2ncat((CHAR*)ctm_p->pending_buffer, (CHAR*)ctm_p->editor_buffer, (MMI_CTM_MAX_EDITOR_COUNT-mmi_ucs2strlen((CHAR*)ctm_p->pending_buffer)));
    ctm_p->pending_len = mmi_ucs2strlen((CHAR*)ctm_p->pending_buffer);
    memset(ctm_p->editor_buffer, 0, MMI_CTM_MAX_EDITOR_BUFFER_LEN);

    if (ctm_p->sent_len == 0)
    {
        /* not sending, trigger the send text request */
        mmi_ctm_req_send_text();
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_entry_talking
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_entry_talking(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 lsk = 0;
    MMI_BOOL show_highlight = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* group id may not be prepared if caller is mmi_ctm_ind_connect. */
    if (ctm_p->grp_id == GRP_ID_INVALID)
    {
        ctm_p->grp_id = mmi_ctm_prepare_group();
        if (ctm_p->grp_id == GRP_ID_INVALID)
        {
            return;
        }
    }

    if (!mmi_frm_scrn_enter(ctm_p->grp_id, SCR_ID_CTM_TALKING, NULL, mmi_ctm_entry_talking, MMI_FRM_UNKNOW_SCRN))
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, FUNC_MMI_CTM_RSP_CONNECT);         
        return;
    }

    /* dismiss message box "Connecting" */
    mmi_ctm_alert_dismiss();
    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, FUNC_MMI_CTM_ENTRY_TALKING);

    if (MMI_CTM_MAX_EDITOR_COUNT - ctm_p->pending_len > 0)
    {
        lsk = STR_GLOBAL_EDIT;
    }

    if (ctm_p->pending_len != 0)
    {
        show_highlight = MMI_TRUE;
    }

    ShowCategory430Screen(
        STR_ID_CTM_CONVERSATION,
        0,
        lsk,
        0,
        STR_ID_CTM_DROP,
        0,
        ctm_p->remote_buffer,
        ctm_p->remote_len,
        ctm_p->local_buffer,
        ctm_p->local_len,
        show_highlight,
        MMI_CTM_MAX_EDITOR_COUNT,
        ctm_p->pending_buffer,
        0,
        (PU8) GetString(STR_ID_CTM_REMOTE),
        (PU8) GetString(STR_ID_CTM_LOCAL),
        NULL);

    SetLeftSoftkeyFunction(mmi_ctm_entry_editor, KEY_EVENT_UP);
    if (lsk)
    {
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_ctm_entry_editor, KEY_EVENT_UP);
    }

    SetRightSoftkeyFunction(mmi_ctm_drop, KEY_EVENT_UP);
    SetKeyHandler(mmi_ctm_drop, KEY_END, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_drop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_drop(void)
{
    srv_ucm_act_request(SRV_UCM_END_ALL_ACT, NULL, NULL, NULL);
}




/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_ctm_ind_hdlr(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    srv_ctm_ind_struct *ind = (srv_ctm_ind_struct*)para;

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_CTM_IND_HDLR, ind->ind);

    switch (ind->ind)
    {
        case SRV_CTM_IND_CLOSE:
            mmi_ctm_ind_close();
            break;

        case SRV_CTM_IND_CONNECT:
            mmi_ctm_ind_connect();
            break;

        case SRV_CTM_IND_RECEIVE_TEXT:
            mmi_ctm_ind_receive_text((srv_ctm_receive_text_ind_struct*)(ind->ptr));
            break;

        case SRV_CTM_IND_TTY_DEVICE_STATUS:
            mmi_ctm_ind_tty_dev_status(((srv_ctm_tty_device_status_struct*)(ind->ptr))->is_plug_in);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_ind_close
 * DESCRIPTION
 *  close ind handler
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_ctm_ind_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ctm_p->state = MMI_CTM_STATE_IDLE;

    mmi_ctm_group_close();

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_connect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_connect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      
    if (srv_ctm_prmt_connect() == MMI_TRUE)
    {
        ctm_p->grp_id = mmi_ctm_prepare_group();
        if (ctm_p->grp_id == GRP_ID_INVALID)
        {
            return;
        }
        
        ctm_p->state = MMI_CTM_STATE_CONNECTING;
        srv_ctm_act_req(SRV_CTM_ACT_CONNECT, NULL, mmi_ctm_rsp_connect);
        mmi_ctm_entry_connect_animation();
    }
    else if (ctm_p->state == MMI_CTM_STATE_CONNECTED)
    {
        /* back to ctm chat screen */
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, FUNC_MMI_CTM_CONNECT_STATE_IS_CONNECTED);         
    }
    else
    {
        mmi_ctm_group_close();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_rsp_connect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_rsp_connect(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    mmi_popup_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    result = ((srv_ctm_rsp_struct*)info)->result;

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, FUNC_MMI_CTM_RSP_CONNECT);    
    
    if (ctm_p->state == MMI_CTM_STATE_CONNECTING)
    {
        if (result == MMI_TRUE)
        {
            /* connect OK */
            ctm_p->state = MMI_CTM_STATE_CONNECTED;

            mmi_ctm_cntxt_reset_buffer();

            /* enter chat screen */
            mmi_frm_nmgr_notify_by_app(
                          MMI_SCENARIO_ID_IN_CALL,
                          MMI_EVENT_NON_TONE,
                          mmi_ctm_entry_talking_cb, NULL);
        }
        else
        {
            /* connect fail */
            /* Revised for new popup mechanism */
            ctm_p->state = MMI_CTM_STATE_IDLE;

            mmi_popup_property_init(&arg);
            arg.callback = mmi_ctm_popup_callback;
            /* If group is in inactive state, the message should not be shown */
            arg.parent_id = ctm_p->grp_id;

            mmi_popup_display((UI_string_type) GetString(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE, &arg);            
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_cntxt_reset_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_cntxt_reset_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(ctm_p->remote_buffer, 0, MMI_CTM_MAX_DATA_BUFFER_LEN);
    memset(ctm_p->local_buffer, 0, MMI_CTM_MAX_DATA_BUFFER_LEN);
    memset(ctm_p->pending_buffer, 0, MMI_CTM_MAX_EDITOR_BUFFER_LEN);
    memset(ctm_p->editor_buffer, 0, MMI_CTM_MAX_EDITOR_BUFFER_LEN);
    ctm_p->remote_len = 0;
    ctm_p->local_len = 0;
    ctm_p->pending_len = 0;
    ctm_p->sent_len = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_ind_connect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        srv_ctm_ind_struct     
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_ctm_ind_connect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (ctm_p->state == MMI_CTM_STATE_IDLE || ctm_p->state == MMI_CTM_STATE_CONNECTING)
    {
        ctm_p->state = MMI_CTM_STATE_CONNECTED;
        mmi_ctm_cntxt_reset_buffer();
    }

    /* enter chat screen */
     mmi_frm_nmgr_notify_by_app(
                  MMI_SCENARIO_ID_IN_CALL,
                  MMI_EVENT_NON_TONE,
                  mmi_ctm_entry_talking_cb, NULL);


    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_op_start_action_cb
 * DESCRIPTION
 *  call back to display the processing screen
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_ctm_entry_talking_cb(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_ctm_entry_talking();

    return MMI_TRUE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_req_send_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [IN]        
 *  length      [IN]        
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_req_send_text(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ctm_send_text_req_struct info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, FUNC_MMI_CTM_SEND_TEXT_REQ);
    
    memset(&info, 0, sizeof(srv_ctm_send_text_ind_struct));
    
    mmi_ucs2ncpy((CHAR*)info.text, (CHAR*)ctm_p->pending_buffer, CTM_SEND_TEXT_CHAR_MAX_NUM);

    ctm_p->sent_len = mmi_ucs2strlen((CHAR*)info.text);
    
    srv_ctm_act_req(SRV_CTM_ACT_SEND_TEXT, &info, mmi_ctm_rsp_send_text);     
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_rsp_send_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]     srv_ctm_send_text_rsp_struct
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_rsp_send_text(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 finished_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = ((srv_ctm_rsp_struct*)info)->result;

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, FUNC_MMI_CTM_RSP_SEND_TEXT);

    if (result == MMI_TRUE)
    {
        finished_len = ctm_p->sent_len;
        ctm_p->sent_len = 0;

        /* update the local buffer */
        if ((MMI_CTM_MAX_DATA_COUNT - ctm_p->local_len) > finished_len)
        {
            ctm_p->local_len += finished_len;
            mmi_ucs2ncat((CHAR*)ctm_p->local_buffer, (CHAR*)ctm_p->pending_buffer, finished_len);
        }
        else
        {
            /* too much data, only keep the last sentence */
            memset(ctm_p->local_buffer, 0, MMI_CTM_MAX_DATA_BUFFER_LEN);
            ctm_p->local_len = finished_len;
            mmi_ucs2ncpy((CHAR*)ctm_p->local_buffer, (CHAR*)ctm_p->pending_buffer, finished_len);
        }


        /* update the pending buffer */
        ctm_p->pending_len -= finished_len;
        if (ctm_p->pending_len > 0)
        {
            mmi_ucs2cpy((CHAR*)ctm_p->pending_buffer, (CHAR*)&(ctm_p->pending_buffer[finished_len << 1]));
        }
        else
        {
            memset(ctm_p->pending_buffer, 0, MMI_CTM_MAX_EDITOR_BUFFER_LEN);
        }

        /* update the talking screen */
        if (mmi_frm_scrn_get_active_id() == SCR_ID_CTM_TALKING)
        {
            if (finished_len > 0)
            {
                UpdateCategory430LSK(STR_GLOBAL_EDIT, 0);
            }
        
            if (ctm_p->pending_len == 0)
            {
                ConfigureCategory430SendingBox(MMI_FALSE, 0);
            }
            else
            {
                ConfigureCategory430SendingBox(MMI_TRUE, 0);
            }
        }

        /* send the remaining data in the pending buffer */
        if (ctm_p->pending_len > 0)
        {
            mmi_ctm_req_send_text();
        }
    }
    else
    {
        ctm_p->sent_len = 0;
        /* start a timer, prevent ctm from stack overflow due to keep re-trying */
        StartTimer(CM_NOTIFYDURATION_TIMER, 2000, (FuncPtr)mmi_ctm_req_send_text);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_ind_recv_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_ctm_ind_receive_text(srv_ctm_receive_text_ind_struct *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 space, len;
    PU16 text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    len = ind->text_len;
    text = ind->text;

    space = MMI_CTM_MAX_DATA_COUNT - ctm_p->remote_len;
    if (space > len)
    {
        ctm_p->remote_len += len;
        mmi_ucs2cat((CHAR*)ctm_p->remote_buffer, (CHAR*)text);
    }
    else
    {
        /* too many data, keep the last sentence */
        ctm_p->remote_len = MMI_CTM_MAX_EDITOR_COUNT;
        mmi_ucs2cpy((CHAR*)ctm_p->remote_buffer, (CHAR*)(ctm_p->remote_buffer + (((MMI_CTM_MAX_DATA_COUNT - 1) - (MMI_CTM_MAX_EDITOR_COUNT - len))<< 1)));
        mmi_ucs2cat((CHAR*)ctm_p->remote_buffer, (CHAR*)text);
    }

    /* check group id and screen id */
    if (mmi_frm_group_get_active_id() == ctm_p->grp_id &&
        mmi_frm_scrn_get_active_id() == SCR_ID_CTM_TALKING)
    {
        UpdateCategory430LogBox(MMI_TRUE, MMI_FALSE);
    }

    return 0;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_ind_tty_dev_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_ind_tty_dev_status(MMI_BOOL is_plug_in)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (is_plug_in)
    {
        mmi_popup_display_simple(get_string(STR_ID_CTM_TTY_PLUG_IN), MMI_EVENT_INFO, GRP_ID_ROOT, NULL);
    }
    else
    {
        mmi_popup_display_simple(get_string(STR_ID_CTM_TTY_PLUG_OUT), MMI_EVENT_INFO, GRP_ID_ROOT, NULL);
    }
}

#endif /* __CTM_SUPPORT__ */
 
