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
 *  PhoneBookPBAP.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  phonebook access profile
 *
 * Author:
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
#include "MMI_features.h"
#ifdef __MMI_BT_SUPPORT__
#if defined(__MMI_PBAP_SUPPORT__)


#include "Conversions.h"
#include "BtcmSrvGprot.h"

#include "BTMMIScr.h"
#include "BTMMIScrGprots.h"
#include "Bluetooth_struct.h"
#include "PhoneBookPbap.h"

#include "PbapSrvGprot.h"
#include "BTMMIPbapGprots.h"
#include "BTMMIPbap.h"

#include "MMIDataType.h"
#include "mmi_frm_scenario_gprot.h"
#include "string.h"
#include "kal_general_types.h"
#include "NotificationGprot.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_bluetooth_def.h"
#include "mmi_frm_history_gprot.h"
#include "Unicodexdcl.h"
#include "wgui_inputs.h"
#include "wgui_categories_inputs.h"
#include "ImeGprot.h"
#include "GlobalConstants.h"
#include "wgui_categories_util.h"
static S32 mmi_pbap_event_hdlr(S32 srv_hd, U32 event_id, void *para);
static void mmi_pbap_init(void);


static void mmi_pbap_auth_input_validation_func(U8 *text, U8 *cursor, S32 length);
static void mmi_pbap_authentication_confirm_hdlr(void);
static MMI_BOOL mmi_pbap_entry_authentication_confirm(mmi_scenario_id scen_id, void *arg);
static void mmi_pbap_entry_authentication_confirm_scr(void);
static mmi_ret mmi_pbap_entry_authentication_confirm_proc(mmi_event_struct *evt);
static mmi_ret mmi_pbap_entry_authentication_confirm_scr_proc(mmi_event_struct *evt);
static void mmi_pbap_auth_send(void);
static void mmi_pbap_auth_reject(void);

static void mmi_bt_pbap_authorize_rsp_hdler(srv_bt_cm_bt_addr *bd_addr,U32 profile_id, U32 result);
static void mmi_pbap_get_dev_name(U8 *name_buf);

static void mmi_pbap_start_ind_hdlr(void *para);
static void mmi_pbap_stop_ind_hdlr(void *para);
static void mmi_pbap_authorize_ind_hdlr(void *para);
static void mmi_pbap_authentication_ind_hdlr(void *para);
static void mmi_pbap_connect_ind_hdlr(void *para);
static void mmi_pbap_disconnect_ind_hdlr(void *para);


mmi_pbap_struct mmi_pbap_cntx;
mmi_pbap_struct *mmi_pbap_p = &mmi_pbap_cntx;


/*****************************************************************************
 * FUNCTION
 *  mmi_pbap_init
 * DESCRIPTION
 *  Displays the details of the selected phonebook entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_pbap_event_hdlr(S32 srv_hd, U32 event_id, void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_hd <= 0)
        return SRV_PBAP_RESULT_INVALID_HANDLE;
    
    switch(event_id)
    {
        case SRV_PBAP_EVENT_START:
            mmi_pbap_start_ind_hdlr(para);
            break;
            
        case SRV_PBAP_EVENT_STOP:
            mmi_pbap_stop_ind_hdlr(para);
            break;
            
        case SRV_PBAP_EVENT_AUTHORIZE_NOTIFY:
            mmi_pbap_authorize_ind_hdlr(para);
            break;
            
        case SRV_PBAP_EVENT_AUTHENTICATION_NOTIFY:
            mmi_pbap_authentication_ind_hdlr(para);
            break;
            
        case SRV_PBAP_EVENT_CONN_NOTIFY:
            mmi_pbap_connect_ind_hdlr(para);
            break;
            
        case SRV_PBAP_EVENT_DISCONN_NOTIFY:
            mmi_pbap_disconnect_ind_hdlr(para);
            break;
  
        default:
            break;
    }

    return SRV_PBAP_RESULT_OK;
}
#define MMI_PBAP_INIT


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_pbap_init
 * DESCRIPTION
 *  Displays the details of the selected phonebook entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_pbap_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbap_init();
    mmi_pbap_init();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pbap_init
 * DESCRIPTION
 *  init the app context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pbap_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 event_mask;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&mmi_pbap_cntx, 0, sizeof(mmi_pbap_cntx));

    mmi_pbap_p->srv_hd = srv_pbap_open();

    event_mask = SRV_PBAP_EVENT_START |
                 SRV_PBAP_EVENT_STOP |
                 SRV_PBAP_EVENT_AUTHORIZE_NOTIFY |
                 SRV_PBAP_EVENT_AUTHENTICATION_NOTIFY |
                 SRV_PBAP_EVENT_CONN_NOTIFY |
                 SRV_PBAP_EVENT_DISCONN_NOTIFY;

    srv_pbap_set_notify(mmi_pbap_p->srv_hd, event_mask, mmi_pbap_event_hdlr);
}

#define MMI_PBAP_DEINIT
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_pbap_deinit
 * DESCRIPTION
 *  Displays the details of the selected phonebook entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_pbap_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbap_deinit();

    srv_pbap_close(mmi_pbap_p->srv_hd);
    mmi_pbap_p->srv_hd = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_pbap_disconnect_client
 * DESCRIPTION
 *  Displays the details of the selected phonebook entry
 * PARAMETERS
 *  bd_addr     [IN]        
 *  conn_id     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_pbap_disconnect_client(srv_bt_cm_bt_addr bd_addr, U32 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //bt_pbap_disconnect_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_pbap_p->disconnect_from_cm = MMI_TRUE;
    srv_pbap_disconnect_client(conn_id);    
}



#define MMI_PBAP_AUTHENTICATION

/*****************************************************************************
 * FUNCTION
 *  mmi_pbap_interrupt_request_hdlr
 * DESCRIPTION
 *  display authentication screen
 * PARAMETERS
 *  S8 *path: ASCII encoding
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pbap_authentication_confirm_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_nmgr_notify_by_app(
            MMI_SCENARIO_ID_BT_ACCESS_REQ,
            MMI_EVENT_INFO,
            mmi_pbap_entry_authentication_confirm,
            NULL);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_pbap_interrupt_notify_hdlr
 * DESCRIPTION
 *  display authentication screen
 * PARAMETERS
 *  S8 *path: ASCII encoding
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_pbap_entry_authentication_confirm(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pbap_p->gid = mmi_frm_group_create(
                            GRP_ID_ROOT, 
                            GRP_ID_PBAP_AUTHENTICATION, 
                            mmi_pbap_entry_authentication_confirm_proc, 
                            NULL);
    
    mmi_frm_group_enter(mmi_pbap_p->gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    mmi_pbap_entry_authentication_confirm_scr();
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pbap_entry_authenticating
 * DESCRIPTION
 *  This function is used to entry the authenticating screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pbap_entry_authentication_confirm_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U8  utf8_char_cnt = 0, ucs2_str_len = 0;
    U8  *guiBuffer;  
    U8  *inputBuffer;
    //U8  ui_tmp[4];
    U8  dev_name_tmp[SRV_BT_CM_BD_NAME_UCS2_LEN];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_PBAP_LOG(MMI_PBAP_SERVER_ENTRY_AUTHENICATING);

    if (mmi_frm_scrn_enter(
            mmi_pbap_p->gid, 
            SCR_PBAP_AUTHENTICATING_ID, 
            NULL, 
            mmi_pbap_entry_authentication_confirm_scr, 
            MMI_FRM_FULL_SCRN))
    {
        mmi_frm_start_scenario(MMI_SCENARIO_ID_BT_ACCESS_REQ);
        
#ifdef __MMI_FRM_HISTORY__
        guiBuffer = GetCurrGuiBuffer(SCR_PBAP_AUTHENTICATING_ID);
        inputBuffer = GetCurrInputBuffer(SCR_PBAP_AUTHENTICATING_ID);
#endif
        if (inputBuffer == NULL)
        {
            memset(mmi_pbap_p->auth_scr_input_buff, 0, MMI_PBAP_AUTH_INPUT_BUFF_SIZE);
            memset(mmi_pbap_p->auth_scr_ui_buff, 0, MMI_PBAP_AUTH_UI_BUFF_SIZE);
            memset(dev_name_tmp, 0, SRV_BT_CM_BD_NAME_UCS2_LEN);

            mmi_pbap_get_dev_name(dev_name_tmp);

            mmi_wcscpy(mmi_pbap_p->auth_scr_ui_buff, (U16 *)L"PBAP");
            /* "(" string + "Device name" + ")" string*/
            if (dev_name_tmp[0]!= 0)
            {
                mmi_wcscat(mmi_pbap_p->auth_scr_ui_buff, (U16 *)L"(");            
                mmi_wcscat(mmi_pbap_p->auth_scr_ui_buff, (U16*)dev_name_tmp);
                mmi_wcscat(mmi_pbap_p->auth_scr_ui_buff, (U16 *)L")");
            }
            /* ":" string */
            mmi_wcscat(mmi_pbap_p->auth_scr_ui_buff, (U16 *)L":");
            
        }
        /* inputbuffer != NULL */
        else
        {
            mmi_wcscpy(mmi_pbap_p->auth_scr_input_buff, (U16 *) inputBuffer);
            /* donot need to update ui_buffer */
        }

        RegisterInputBoxValidationFunction(mmi_pbap_auth_input_validation_func);
        ShowCategory111Screen_ext(
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (U8*)mmi_pbap_p->auth_scr_ui_buff,
            IMM_INPUT_TYPE_NUMERIC_PASSWORD,
            (U8*) (mmi_pbap_p->auth_scr_input_buff),
            (GOEP_MAX_PASSWD_SIZE + 1),
            NULL,
            0,
            guiBuffer);
        
        SetLeftSoftkeyFunction(mmi_pbap_auth_send, KEY_EVENT_UP);    
        if (mmi_ucs2strlen((S8*) (mmi_pbap_p->auth_scr_input_buff)) < 1)
        {
            ChangeLeftSoftkey(0, 0);
        }

        SetCategory111RightSoftkeyFunction(mmi_pbap_auth_reject, KEY_EVENT_UP);
        //SetKeyHandler(mmi_pbap_auth_reject, KEY_END, KEY_EVENT_DOWN);

        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_pbap_auth_send,KEY_EVENT_UP);

        mmi_frm_scrn_set_leave_proc(mmi_pbap_p->gid, SCR_PBAP_AUTHENTICATING_ID, mmi_pbap_entry_authentication_confirm_scr_proc);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_pbap_entry_authentication_confirm_proc
 * DESCRIPTION
 *  This function is used to exit the authenticating screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_pbap_entry_authentication_confirm_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            mmi_pbap_p->gid = 0;
            mmi_frm_end_scenario(MMI_SCENARIO_ID_BT_ACCESS_REQ);
            break;

        case EVT_ID_GROUP_INACTIVE:
            
            break;
            
        default:
            break;
          
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pbap_exit_authenticating
 * DESCRIPTION
 *  This function is used to exit the authenticating screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 static mmi_ret mmi_pbap_entry_authentication_confirm_scr_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
            mmi_pbap_auth_reject();
            break;
            
        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pbap_auth_send
 * DESCRIPTION
 *  This function is to send a authentication response to BT
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pbap_auth_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tmp_ascii_buf[MMI_PBAP_AUTH_INPUT_BUFF_SIZE/2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_ucs2_to_asc((S8*)tmp_ascii_buf, (S8*)mmi_pbap_p->auth_scr_input_buff);

    srv_pbap_accept_conn(mmi_pbap_p->srv_hd, tmp_ascii_buf);

    mmi_frm_scrn_set_leave_proc(mmi_pbap_p->gid, SCR_PBAP_AUTHENTICATING_ID, NULL);
    mmi_frm_group_close(mmi_pbap_p->gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pbap_auth_reject
 * DESCRIPTION
 *  This function is to send a authentication response with cancel flag to BT
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pbap_auth_reject(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //bt_pbap_auth_cnf_struct * rsp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbap_reject_conn(mmi_pbap_p->srv_hd);

    mmi_frm_scrn_set_leave_proc(mmi_pbap_p->gid, SCR_PBAP_AUTHENTICATING_ID, NULL);
    mmi_frm_group_close(mmi_pbap_p->gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pbap_auth_input_validation_func
 * DESCRIPTION
 *  This function is to check the input buffer of authenticating screen
 * PARAMETERS
 *  text        [?]             
 *  cursor      [?]             
 *  length      [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pbap_auth_input_validation_func(U8 *text, U8 *cursor, S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((length) < 1)
    {
        ChangeLeftSoftkey(0, 0);
    }
    else
    {
        EnableLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pbap_get_dev_name
 * DESCRIPTION
 *  This function is to get the bt device name from context
 * PARAMETERS
 *  name_buf        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pbap_get_dev_name(U8 *name_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 utf8_char_cnt = 0;
    U16 ucs2_str_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* copy dev_name to MMI screen */
    /* get byte count for convert utf8 string to UCS2 string */
    /* get character count of utf8 string */
    /* +1 is for UCS2 NULL terminate */
    /* *ENCODING_LENGTH is for byte count of one UCS2 character */
    utf8_char_cnt =
        (U16) ((mmi_chset_utf8_strlen((U8*) mmi_pbap_p->dev_name) + 1)
               * ENCODING_LENGTH);

    if (utf8_char_cnt > SRV_BT_CM_BD_NAME_UCS2_LEN)
    {
        ucs2_str_len =
            (U16) mmi_chset_utf8_to_ucs2_string(
                    name_buf,
                    SRV_BT_CM_BD_NAME_UCS2_LEN,
                    (U8*) mmi_pbap_p->dev_name);
    }
    else
    {
        ucs2_str_len =
            (U16) mmi_chset_utf8_to_ucs2_string(
                    name_buf,
                     utf8_char_cnt,
                    (U8*) mmi_pbap_p->dev_name);
    }

    /* allow (MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters  */
    /* so for UCS2 encoding, need MMI_BT_SCR_BD_NAME_LEN bytes */

    /* shall check if there is any two_byte character mixed in one_bye UCS2 string */
    /* if yes, then truncate the string to meet above rules((MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters) */
    if (mmi_bt_test_ucs2((U16 *) name_buf, (U16) (ucs2_str_len / ENCODING_LENGTH)))
    {
        mmi_bt_truncate_ucs2_string(
            (U16 *) name_buf,
            (ucs2_str_len / ENCODING_LENGTH),
            (U16) ((SRV_BT_CM_BD_FNAME_LEN - 2) / 3));
    }
}


#define MMI_PBAP_AUTHRIZE

/*BT concurrency*/
/****************************************************************************** 
 * FUNCTION
 *  mmi_pbap_connection_authorize_rsp_hdler
 * DESCRIPTION
 *  register callback in CM callback function table
 * PARAMETERS
 *  bd_addr    [IN]
 *  result    [IN]
 *  
 * RETURNS
 *  void
 ******************************************************************************/
static void mmi_bt_pbap_authorize_rsp_hdler(srv_bt_cm_bt_addr *bd_addr,U32 profile_id, U32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (profile_id == SRV_BT_CM_OBEX_PBA_PROFILE_UUID)
    {
        if (result)
        {
            srv_pbap_accept_conn(mmi_pbap_p->srv_hd, NULL);
        }
        else
        {
            srv_pbap_reject_conn(mmi_pbap_p->srv_hd);
        }
    }
}


#define MMI_PBAP_CALLBACK_FUNC

/*****************************************************************************
 * FUNCTION
 *  mmi_pbap_start_notify_hdlr
 * DESCRIPTION
 *  notify cm sdp register result
 * PARAMETERS
 *  S8 *path: ASCII encoding
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pbap_start_ind_hdlr(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* call activate cnf to CM */
    //srv_bt_cm_activate_cnf_hdler((U32) SRV_BT_CM_OBEX_PBA_PROFILE_UUID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pbap_stop_notify_hdlr
 * DESCRIPTION
 *  notify cm sdp deregister result
 * PARAMETERS
 *  S8 *path: ASCII encoding
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pbap_stop_ind_hdlr(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    //srv_bt_cm_deactivate_cnf_hdler((U32) SRV_BT_CM_OBEX_PBA_PROFILE_UUID);

    //srv_pbap_close(mmi_pbap_p->srv_hd);

    //mmi_pbap_p->srv_hd = 0;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_pbap_authorize_notify_hdlr
 * DESCRIPTION
 *  notify cm authorize
 * PARAMETERS
 *  S8 *path: ASCII encoding
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pbap_authorize_ind_hdlr(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbap_auth_notify_struct *auth_notify = (srv_pbap_auth_notify_struct *)para;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_authorize_ind_notify(
        auth_notify->dev_name,
        &(auth_notify->bt_addr),
        SRV_BT_CM_OBEX_PBA_PROFILE_UUID,
        (void *) mmi_bt_pbap_authorize_rsp_hdler);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pbap_authentication_notify_hdlr
 * DESCRIPTION
 *  display authentication screen
 * PARAMETERS
 *  S8 *path: ASCII encoding
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pbap_authentication_ind_hdlr(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbap_authentication_notify_struct *authentication_notify = (srv_pbap_authentication_notify_struct *)para;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strcpy((S8*) mmi_pbap_p->dev_name, (S8*) authentication_notify->dev_name);
    
    mmi_pbap_authentication_confirm_hdlr();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_pbap_connect_notify_hdlr
 * DESCRIPTION
 *  notify cm connect result
 * PARAMETERS
 *  S8 *path: ASCII encoding
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pbap_connect_ind_hdlr(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_popup[60];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(
        str_popup,
        "%w%w",
        (WCHAR*)GetString(STR_BT_PROF_PBAP),
        (WCHAR*)GetString(STR_BT_CONN_ED)
        );
    mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_SUCCESS, (WCHAR*)str_popup);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pbap_disconnect_notify_hdlr
 * DESCRIPTION
 *  notify cm disconnect result
 * PARAMETERS
 *  S8 *path: ASCII encoding
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pbap_disconnect_ind_hdlr(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbap_disconn_notify_struct *disconn_notify = (srv_pbap_disconn_notify_struct *)para;
    U16 popup_string[50];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* call disconnect ind to notify CM */
    mmi_bt_authorize_screen_close(SRV_BT_CM_OBEX_PBA_PROFILE_UUID);

    mmi_frm_nmgr_cancel_deferred_scenario(
        MMI_SCENARIO_ID_BT_ACCESS_REQ, 
        mmi_pbap_entry_authentication_confirm, 
        NULL);

    if (!disconn_notify->disconnect_from_cm)
    {
        kal_wsprintf(popup_string, "%w%w", (WCHAR*)GetString(STR_BT_PROF_PBAP), (WCHAR*)GetString(STR_BT_DISCON_ED));
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, popup_string);
    }
}

#endif /* __MMI_PBAP_NEW_SUPPORT__ */
#endif /* __MMI_BT_SUPPORT__ */ 

