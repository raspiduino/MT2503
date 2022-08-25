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
 *  EmailAppNetwork.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to implement the Email memory management functions.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_EMAIL__

#include "fs_func.h"
#include "fs_type.h"
#include "fs_errcode.h"

#include "MMIDataType.h"

#include "GlobalResDef.h"
#include "mmi_rp_app_email_def.h"

#include "cbmsrvgprot.h"
#include "cbmcuigprot.h"

#include "emailsrvgprot.h"

#include "EmailAppProt.h"
#include "EmailAppEmn.h"
#include "EmailAppLib.h"
#include "EmailAppNetwork.h"
#include "EmailAppAccountData.h"
#include "EmailAppStateMgr.h"
#include "EmailAppNCenter.h"
#include "Wgui_categories_util.h"
#include "EmailAppSso.h"



#if (defined(__XML_SUPPORT__) && defined(__WBXML_SUPPORT__))
#ifndef __MMI_EMAIL_EMN__
#define __MMI_EMAIL_EMN__
#endif /* __MMI_EMAIL_EMN__ */
#endif /* (defined(__XML_SUPPORT__) && defined(__WBXML_SUPPORT__)) */


#define PUSH_ICON_NULL 0
#define PUSH_ICON_IDLE 1
#define PUSH_ICON_BUSY 2
#define PUSH_ICON_FAIL 3


typedef enum
{
    MENWK_T_NULL,
    
    MENWK_T_EMN,
    MENWK_T_IMAPPUSH,
    MENWK_T_AUTOCHECK,

    MENWK_T_USERREFRESH,
    MENWK_T_USERSEND,
    MENWK_T_USERDOWNLOAD,

    MENWK_T_MAX
}mmi_email_nwk_type_enum;

typedef enum
{
    MEANWK_S_NULL,

    MEANWK_S_INIT,
    MEANWK_S_CONNECT,
    MEANWK_S_SEND,
    MEANWK_S_RECEIVE,
    MEANWK_S_DOWNLOAD,
    MEANWK_S_IDLE,
    MEANWK_S_DISCONNECT,

    MEANWK_S_MAX
}mmi_email_nwk_status_enum;

typedef struct
{
    EMAIL_ACCT_ID acc_id; // Set INVALID once action done
    mmi_email_nwk_type_enum t;

    mmi_email_nwk_status_enum s;

    EMAIL_ACCT_HANDLE acct_handle;
    EMAIL_MSG_HANDLE msg_handle;
    EMAIL_REQ_ID srv_req_id;
    EMAIL_FLDR_ID outbox_id;

    BOOL is_connected;  // Rememer INCOMING connection during SENDING
    BOOL is_send_done; // Re-connect for RECEVING if broken during SENDING
    BOOL disconnect_for_refresh; // DISCONNECT-CONNECT-RECEIVE to refresh. POP3 protocol limitation

    BOOL need_re_refresh; // Request comes repeately
    BOOL need_re_send; // Request comes repeately

    mmi_id cmb_grp_id, cbm_id; // 
    srv_cbm_bearer_event_type_enum cbm_type; 

    S32 ret_major_recv, ret_major_send; // Major error code
    S32 ret_minor_recv, ret_minor_send; // Minor error code

    U32 recved_unread_count; /* UNREAD messages received INBOX */
    U32 recved_total_count; /* Total messages received */

    /* For OUTBOX message status */
    BOOL outbox_is_sending; /* For OUTBOX context MENU */
    EMAIL_MSG_ID outbox_ongoing_id; /* Message ID of Current SENDING */
    U32 outbox_failed_count; /* Number of messages failed to send */
    EMAIL_MSG_ID outbox_failed_id[SRV_EMAIL_GLOBAL_MAX_MSG_NUM]; /* Messages ID failed to send */
}mmi_email_nwk_context_struct;


typedef struct
{
    U32 count;
    mmi_email_nwk_type_enum t[MMI_EMAIL_MAX_ACCTS];
    EMAIL_ACCT_ID acc_id[MMI_EMAIL_MAX_ACCTS];

    mmi_email_nwk_context_struct nwk;
}mmi_email_autoconnection_struct;


#ifdef __MMI_EMAIL_IMAP_PUSH__
typedef struct
{
    EMAIL_ACCT_ID acc_id; // Push status is depends on NWK status
    mmi_email_nwk_context_struct nwk;
    U32 retry_count;
}mmi_email_imappush_context_struct;
#endif /* __MMI_EMAIL_IMAP_PUSH__ */

typedef struct
{
    EMAIL_ACCT_ID acc_id; // User status depends on NWK status
    mmi_email_nwk_type_enum t; // For confirm 
    BOOL foreground; // Send request from foreground or background

    // For download message
    EMAIL_FLDR_ID fld_id;
    EMAIL_MSG_ID msg_id;
    EMAIL_ATTCH_ID attach_id;
    srv_email_retrieve_option_enum ret_opt;

    S32 down_size;

    mmi_id grp_id; // Loading screen

}mmi_email_useraction_context_struct;


/* Global context for three type connections */
static EMAIL_ACCT_ID g_frozen_acc_id;
static mmi_email_autoconnection_struct g_auto_ctx;
#ifdef __MMI_EMAIL_IMAP_PUSH__
static mmi_email_imappush_context_struct g_push_ctx;
#endif /* __MMI_EMAIL_IMAP_PUSH__ */
static mmi_email_useraction_context_struct g_user_ctx;


/* local function */
static void network_fsm(mmi_email_nwk_context_struct *ctx);
static void network_close(mmi_email_nwk_context_struct *p);
static void network_reset(mmi_email_nwk_context_struct *p);
static void network_abort(mmi_email_nwk_context_struct *p);

static mmi_ret pump_callback(mmi_event_struct *param);
static void fsm_pump(mmi_email_nwk_context_struct *ctx);

static void fsm_enter(mmi_email_nwk_context_struct *ctx, mmi_email_nwk_type_enum t, EMAIL_ACCT_ID acc_id);
static void fsm_report(mmi_email_nwk_context_struct *ctx);

static void report_user_download(mmi_email_nwk_context_struct *ctx);
static void report_user_refresh(mmi_email_nwk_context_struct *ctx);
static void report_user_send(mmi_email_nwk_context_struct *ctx);

#ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__
static void report_user_autocheck(mmi_email_nwk_context_struct *ctx);
#endif /* __MMI_SLIM_EMAIL_NO_AUTO_CHECK__ */

#ifdef __MMI_EMAIL_EMN__
static void report_user_emn(mmi_email_nwk_context_struct *ctx);
#endif /* __MMI_EMAIL_EMN__ */


#ifdef __MMI_EMAIL_IMAP_PUSH__
static void report_user_push(mmi_email_nwk_context_struct *ctx);
#endif /* __MMI_EMAIL_IMAP_PUSH__ */

static void email_srv_callback(srv_email_result_struct *result,EMAIL_REQ_ID req_id,void *user_data);
static void email_srv_procedue(srv_email_nwk_proc_struct *data);

static void email_srv_connect_callback(srv_email_result_struct *result, mmi_email_nwk_context_struct *ctx);
static void email_srv_refresh_callback(srv_email_result_struct *result, mmi_email_nwk_context_struct *ctx);
static void email_srv_send_callback(srv_email_result_struct *result, mmi_email_nwk_context_struct *ctx);
static void email_srv_disconnect_callback(srv_email_result_struct *result, mmi_email_nwk_context_struct *ctx);
static void email_srv_download_callback(srv_email_result_struct *result, mmi_email_nwk_context_struct *ctx);

static void auto_q_add(EMAIL_ACCT_ID acc_id, mmi_email_nwk_type_enum t);
static void auto_q_consume(void);
static void auto_q_delete(EMAIL_ACCT_ID acc_id);

static BOOL auto_refresh(EMAIL_ACCT_ID acc_id, mmi_email_nwk_type_enum t);

static mmi_email_nwk_context_struct* steal_user_nwk(EMAIL_ACCT_ID acc_id);

static srv_email_result_enum msg_download(mmi_email_nwk_context_struct *p);

static void save_erorr_code(srv_email_result_struct *result, mmi_email_nwk_context_struct *ctx, BOOL is_incoming);
static void on_disconnected(mmi_email_nwk_context_struct *ctx);
static void on_sending(mmi_email_nwk_context_struct *ctx, srv_email_sending_data_struct *send);
static void on_receiving(mmi_email_nwk_context_struct *ctx, srv_email_receiving_data_struct *recv);
static void on_refresh(mmi_email_nwk_context_struct *ctx);

static void outbox_send_begin(mmi_email_nwk_context_struct *ctx);
static void outbox_send_done(mmi_email_nwk_context_struct *ctx);

static mmi_email_nwk_context_struct *get_nwk_by_accid(EMAIL_ACCT_ID acc_id);

static void user_confirm(void);
static void user_abort(EMAIL_ACCT_ID acc_id, mmi_email_nwk_type_enum t);
static void user_refresh(EMAIL_ACCT_ID acc_id, BOOL confirmed);
static void user_send(EMAIL_ACCT_ID acc_id, BOOL foreground, BOOL confirmed);
static void user_download(
        mmi_id grp_id, 
        EMAIL_ACCT_ID acc_id, 
        EMAIL_FLDR_ID fld_id, 
        EMAIL_MSG_ID msg_id, 
        EMAIL_ATTCH_ID attach_id, 
        srv_email_retrieve_option_enum ret_opt,
        BOOL confirmed);
static void user_download_abort(void);


static void start_auto_q_timer(void);
static void stop_auto_q_timer(void);
static void auto_q_timer_callback(void);

#ifdef __MMI_EMAIL_IMAP_PUSH__
static void start_push_retry_timer(void);
static void stop_push_retry_timer(void);
static void push_retry_timer_callback(void);
static void set_push_icon(U32 s);
#endif /* __MMI_EMAIL_IMAP_PUSH__ */


#undef ASSERT
#define ASSERT(a)
//////////////////////////////////////////////////////////////////////////////////////

/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_network_reset
 * DESCRIPTION 
 *  mmi email app network reset
 * PARAMETERS 
 *  void
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_app_network_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NETWORK_RESET, __LINE__);
#ifdef __MMI_EMAIL_IMAP_PUSH__
    network_reset(&g_push_ctx.nwk);
#endif /* __MMI_EMAIL_IMAP_PUSH__ */

    network_reset(&g_auto_ctx.nwk);

    g_frozen_acc_id = EMAIL_ACCT_INVALID_ID;
    memset(&g_auto_ctx, 0, sizeof(mmi_email_autoconnection_struct));
    memset(&g_user_ctx, 0, sizeof(mmi_email_useraction_context_struct));

    stop_auto_q_timer();

#ifdef __MMI_EMAIL_IMAP_PUSH__
    memset(&g_push_ctx, 0, sizeof(mmi_email_imappush_context_struct));
    set_push_icon(PUSH_ICON_NULL);
    stop_push_retry_timer();
#endif /* __MMI_EMAIL_IMAP_PUSH__ */
}


//////////////////////////////////////////////////////////////////////////////////////
#ifdef __MMI_EMAIL_IMAP_PUSH__

/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_network_push_start
 * DESCRIPTION 
 *  mmi email app network push start
 * PARAMETERS 
 *  EMAIL_ACCT_ID acc_id
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_app_network_push_start(EMAIL_ACCT_ID acc_id, BOOL first_power_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NETWORK_PUSH_START, acc_id);

    ASSERT(g_push_ctx.acc_id == EMAIL_ACCT_INVALID_ID);
    ASSERT(g_push_ctx.nwk.acc_id == EMAIL_ACCT_INVALID_ID);
    ASSERT(g_push_ctx.nwk.t == MENWK_T_NULL);
    ASSERT(g_push_ctx.nwk.s == MEANWK_S_NULL);

    g_push_ctx.acc_id = acc_id;

    if (acc_id == EMAIL_ACCT_INVALID_ID)
    {
        return;
    }

    set_push_icon(PUSH_ICON_FAIL);

    if (!mmi_email_smgr_network_check())
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NETWORK_PUSH_START, -1);
        return;
    }

    // Disconnect this account if it is working by AUTO connection
    if (g_auto_ctx.nwk.acc_id == acc_id)
    {
        network_abort(&g_auto_ctx.nwk);
    }

    // Remove this account from AUTO Q if any
    auto_q_delete(acc_id);

    // Start PUSH 
    if (first_power_on)
    {
        g_push_ctx.retry_count = 999;
    }
    else
    {
        g_push_ctx.retry_count = 0;
    }
    start_push_retry_timer();
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_network_push_stop
 * DESCRIPTION 
 *  mmi email app network push stop
 * PARAMETERS 
 *  void
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_app_network_push_stop(BOOL to_change)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_nwk_context_struct* nwkp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NETWORK_PUSH_STOP, __LINE__);
    nwkp = &g_push_ctx.nwk;
    network_abort(nwkp);

    g_push_ctx.acc_id = EMAIL_ACCT_INVALID_ID;

    if (!to_change)
    {
        set_push_icon(PUSH_ICON_NULL);
    }
}
#endif /* __MMI_EMAIL_IMAP_PUSH__ */


//////////////////////////////////////////////////////////////////////////////////////
#ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__

/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_nwk_autocheck_do
 * DESCRIPTION 
 *  mmi email app nwk autocheck do
 * PARAMETERS 
 *  EMAIL_ACCT_ID acc_id
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_app_nwk_autocheck_do(EMAIL_ACCT_ID acc_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NWK_AUTOCHECK_DO, acc_id);
    if (!mmi_email_smgr_network_check())
    {
        // Just skip it
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NWK_AUTOCHECK_DO, -1);
        return;
    }

#ifdef __MMI_SSO__
    if (mmi_email_sso_is_cloud_account(acc_id))
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NWK_AUTOCHECK_DO, -2);
        return;
    }
#endif /* __MMI_SSO__ */

    auto_refresh(acc_id, MENWK_T_AUTOCHECK);
}
#endif /* __MMI_SLIM_EMAIL_NO_AUTO_CHECK__ */


#ifdef __MMI_EMAIL_EMN__
/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_nwk_emn_do
 * DESCRIPTION 
 *  mmi email app nwk emn do
 * PARAMETERS 
 *  EMAIL_ACCT_ID acc_id
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_app_nwk_emn_do(EMAIL_ACCT_ID acc_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NWK_EMN_DO, acc_id);
    if (!mmi_email_smgr_network_check())
    {
        // Take it as processed
        mmi_email_receive_emn_result_handler(acc_id);
        return;
    }

    ret = auto_refresh(acc_id, MENWK_T_EMN);
    if (!ret)
    {
        mmi_email_receive_emn_result_handler(acc_id);
    }
}
#endif /* __MMI_EMAIL_EMN__ */



/*****************************************************************************
 * FUNCTION 
 *  auto_refresh
 * DESCRIPTION 
 *  auto refresh
 * PARAMETERS 
 *  EMAIL_ACCT_ID acc_id
 *  mmi_email_nwk_type_enum t
 * RETURNS 
 *  static BOOL 
*****************************************************************************/
static BOOL auto_refresh(EMAIL_ACCT_ID acc_id, mmi_email_nwk_type_enum t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_nwk_context_struct* nwkp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_AUTO_REFRESH, 0);
    ASSERT(acc_id != EMAIL_ACCT_INVALID_ID);

#ifdef __MMI_EMAIL_IMAP_PUSH__
    if (g_push_ctx.acc_id == acc_id)
    {
        // Should NOT happen.just skip it
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_AUTO_REFRESH, -1);
        return FALSE;
    }
#endif /* __MMI_EMAIL_IMAP_PUSH__ */

    nwkp = &g_auto_ctx.nwk;
    if (nwkp->s == MEANWK_S_NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_AUTO_REFRESH, 1);
        fsm_enter(nwkp, t, acc_id);
        return TRUE;
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_AUTO_REFRESH, 2);
    ASSERT(nwkp->acc_id != EMAIL_ACCT_INVALID_ID);
    auto_q_add(acc_id, t);
    return TRUE;
}


//////////////////////////////////////////////////////////////////////////////////////

/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_nwk_user_enter
 * DESCRIPTION 
 *  mmi email app nwk user enter
 * PARAMETERS 
 *  EMAIL_ACCT_ID acc_id
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_app_nwk_user_enter(EMAIL_ACCT_ID acc_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NWK_USER_ENTER, acc_id);
    ASSERT(acc_id != EMAIL_ACCT_INVALID_ID);
    ASSERT(g_user_ctx.acc_id == EMAIL_ACCT_INVALID_ID);

    g_user_ctx.acc_id = acc_id;
    mmi_email_batch_receive_remove(g_user_ctx.acc_id);
    // This flag will impact the decision when REQUEST done.
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_nwk_user_leave
 * DESCRIPTION 
 *  mmi email app nwk user leave
 * PARAMETERS 
 *  void
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_app_nwk_user_leave(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NWK_USER_LEAVE, __LINE__);
    ASSERT(g_user_ctx.acc_id != EMAIL_ACCT_INVALID_ID);
    if (g_auto_ctx.nwk.s == MEANWK_S_IDLE)
    {
        // TODO...
        network_reset(&g_auto_ctx.nwk);
        start_auto_q_timer();
    }

    // Remove below for NCenter 2.0
#ifndef __MMI_NCENTER_SUPPORT__
    mmi_email_batch_receive_remove(g_user_ctx.acc_id);
#endif /* __MMI_NCENTER_SUPPORT__ */

    g_user_ctx.acc_id = EMAIL_ACCT_INVALID_ID;
}


//////////////////////////////////////////////////////////////////////////////////////

/*****************************************************************************
 * FUNCTION 
 *  user_confirm
 * DESCRIPTION 
 *  user confirm
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void user_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_user_ctx.t)
    {
    case MENWK_T_USERREFRESH:
        user_refresh(g_user_ctx.acc_id, TRUE);
        break;

    case MENWK_T_USERSEND:
        user_send(g_user_ctx.acc_id, g_user_ctx.foreground, TRUE);
        break;

    case MENWK_T_USERDOWNLOAD:
        user_download(g_user_ctx.grp_id, 
            g_user_ctx.acc_id, 
            g_user_ctx.fld_id, 
            g_user_ctx.msg_id, 
            g_user_ctx.attach_id, 
            g_user_ctx.ret_opt, 
            TRUE);
        break;

    default:
        ASSERT(0);
        break;
    }
}


void mmi_email_app_nwk_user_abort(EMAIL_ACCT_ID acc_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_nwk_context_struct *nwkp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nwkp = get_nwk_by_accid(acc_id);
    if (nwkp == NULL)
    {
        return;
    }

    if (nwkp->s == MEANWK_S_NULL || nwkp->s == MEANWK_S_IDLE)
    {
        return;
    }

    network_abort(nwkp);
}


/*****************************************************************************
 * FUNCTION 
 *  user_abort
 * DESCRIPTION 
 *  user abort
 * PARAMETERS 
 *  EMAIL_ACCT_ID acc_id
 *  mmi_email_nwk_type_enum t
 * RETURNS 
 *  static void 
*****************************************************************************/
static void user_abort(EMAIL_ACCT_ID acc_id, mmi_email_nwk_type_enum t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_nwk_context_struct *nwkp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(acc_id != EMAIL_ACCT_INVALID_ID);
    ASSERT(g_user_ctx.acc_id == acc_id);
    ASSERT(g_frozen_acc_id == EMAIL_ACCT_INVALID_ID);

    nwkp = get_nwk_by_accid(acc_id);
    if (nwkp == NULL)
    {
        return;
    }

    switch (t)
    {
    case MENWK_T_USERREFRESH:
        if (nwkp->t != MENWK_T_USERREFRESH
            && nwkp->t != MENWK_T_EMN
            && nwkp->t != MENWK_T_AUTOCHECK
            && nwkp->t != MENWK_T_IMAPPUSH)
        {
            return;
        }
        break;

    case MENWK_T_USERSEND:
        if (nwkp->t != MENWK_T_USERSEND)
        {
            return;
        }
        break;

    case MENWK_T_USERDOWNLOAD:
        if (nwkp->t != MENWK_T_USERDOWNLOAD)
        {
            return;
        }
        break;

    default:
        ASSERT(0);
        break;
    }

    if (nwkp->s == MEANWK_S_NULL || nwkp->s == MEANWK_S_IDLE)
    {
        return;
    }

    network_abort(nwkp);
}

//////////////////////////////////////////////////////////////////////////////////////

/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_nwk_user_refresh
 * DESCRIPTION 
 *  mmi email app nwk user refresh
 * PARAMETERS 
 *  EMAIL_ACCT_ID acc_id
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_app_nwk_user_refresh(EMAIL_ACCT_ID acc_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NWK_USER_REFRESH, acc_id);
    user_refresh(acc_id, FALSE);
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_nwk_user_refresh_stop
 * DESCRIPTION 
 *  mmi email app nwk user refresh stop
 * PARAMETERS 
 *  EMAIL_ACCT_ID acc_id
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_app_nwk_user_refresh_stop(EMAIL_ACCT_ID acc_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NWK_USER_REFRESH_STOP, acc_id);
    user_abort(acc_id, MENWK_T_USERREFRESH);
}


/*****************************************************************************
 * FUNCTION 
 *  user_refresh
 * DESCRIPTION 
 *  user refresh
 * PARAMETERS 
 *  EMAIL_ACCT_ID acc_id
 *  BOOL confirmed
 * RETURNS 
 *  static void 
*****************************************************************************/
static void user_refresh(EMAIL_ACCT_ID acc_id, BOOL confirmed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_nwk_context_struct *nwkp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_USER_REFRESH, 0);
    ASSERT(acc_id != EMAIL_ACCT_INVALID_ID);
    ASSERT(g_user_ctx.acc_id == acc_id);

    if (!mmi_email_smgr_network_check())
    {
        // Should has been checked before call this API
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_USER_REFRESH, -1);
        return;
    }

    if (g_frozen_acc_id == acc_id)
    {
        ASSERT(0);
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_USER_REFRESH, -2);
        return;
    }


#ifdef __MMI_EMAIL_IMAP_PUSH__
    // Use PUSH connection
    nwkp = &g_push_ctx.nwk;
    if (g_push_ctx.acc_id == acc_id)
    {
        // Push account
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_USER_REFRESH, 3);
        if (nwkp->s == MEANWK_S_NULL || nwkp->s == MEANWK_S_IDLE)
        {
            fsm_enter(nwkp, MENWK_T_USERREFRESH, acc_id);
        }
        else if (nwkp->t == MENWK_T_USERSEND)
        {
            // POPUP Busy
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_USER_REFRESH, -4);
            mmi_email_lib_error_popup(STR_EMAIL_CANNOT_REFRESH_WHEN_SENDING_ID);
        }
        else
        {
            // TODO... re-refresh again after refresh done
            nwkp->need_re_refresh = TRUE;
        }
        return;
    }
#endif /* __MMI_EMAIL_IMAP_PUSH__ */


    // Use AUTO connection
    nwkp = &g_auto_ctx.nwk;
    if (nwkp->acc_id == EMAIL_ACCT_INVALID_ID)
    {
        // Free now, do it.
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_USER_REFRESH, 5);
        ASSERT(nwkp->s == MEANWK_S_NULL);
        ASSERT(nwkp->t == MENWK_T_NULL);

        fsm_enter(nwkp, MENWK_T_USERREFRESH, acc_id);
        return;
    }

    if (nwkp->acc_id == acc_id)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_USER_REFRESH, 6);
        ASSERT(nwkp->s != MEANWK_S_NULL);
        if (nwkp->s == MEANWK_S_IDLE)
        {
            fsm_enter(nwkp, MENWK_T_USERREFRESH, acc_id);
        }
        else if (nwkp->t == MENWK_T_USERSEND)
        {
            // POPUP Busy
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_USER_REFRESH, -7);
            mmi_email_lib_error_popup(STR_EMAIL_CANNOT_REFRESH_WHEN_SENDING_ID);
        }
        else
        {
            nwkp->need_re_refresh = TRUE;
        }
        return;
    }

    // Stop other account's AUTO connection
    if (confirmed)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_USER_REFRESH, 8);
        network_abort(nwkp);
        fsm_enter(nwkp, MENWK_T_USERREFRESH, acc_id);
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_USER_REFRESH, 9);
        g_user_ctx.t = MENWK_T_USERREFRESH;
        g_user_ctx.acc_id = acc_id;
        mmi_email_util_display_confirm(
            GRP_ID_ROOT,
            user_confirm,
            mmi_frm_scrn_close_active_id,
            NULL,
            TRUE,
            GetString(STR_EMAIL_CONFIRM_ABORT_OTHER_ACCOUNT_NETWORK),
            MMI_EVENT_QUERY);
    }
}


/////////////////////////////////////////////////////////////////////

/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_nwk_user_send
 * DESCRIPTION 
 *  mmi email app nwk user send
 * PARAMETERS 
 *  EMAIL_ACCT_ID acc_id
 *  BOOL foreground
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_app_nwk_user_send(EMAIL_ACCT_ID acc_id, BOOL foreground)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NWK_USER_SEND, acc_id, foreground);
    user_send(acc_id, foreground, FALSE);
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_nwk_user_send_stop
 * DESCRIPTION 
 *  mmi email app nwk user send stop
 * PARAMETERS 
 *  EMAIL_ACCT_ID acc_id
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_app_nwk_user_send_stop(EMAIL_ACCT_ID acc_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NWK_USER_SEND_STOP, acc_id);
    user_abort(acc_id, MENWK_T_USERSEND);
}


/*****************************************************************************
 * FUNCTION 
 *  user_send
 * DESCRIPTION 
 *  user send
 * PARAMETERS 
 *  EMAIL_ACCT_ID acc_id
 *  BOOL foreground
 *  BOOL confirmed
 * RETURNS 
 *  static void 
*****************************************************************************/
static void user_send(EMAIL_ACCT_ID acc_id, BOOL foreground, BOOL confirmed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_nwk_context_struct *nwkp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_USER_SEND, 0);
    //ASSERT(g_user_ctx.acc_id == acc_id);

    if (!mmi_email_smgr_network_check())
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_USER_SEND, -1);
        return;
    }

    // Check if resource ready
    if (g_frozen_acc_id == acc_id)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_USER_SEND, -2);
        ASSERT(0);
        return;
    }

    nwkp = steal_user_nwk(acc_id);
    ASSERT(nwkp != NULL);
    if (nwkp->acc_id != EMAIL_ACCT_INVALID_ID && nwkp->acc_id != acc_id)
    {
        if (foreground)
        {
            if (confirmed)
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_USER_SEND, 3);
                network_abort(nwkp);
                fsm_enter(nwkp, MENWK_T_USERSEND, acc_id);
            }
            else
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_USER_SEND, 4);

                // Confirm to abort other account's action
                g_user_ctx.t = MENWK_T_USERSEND;
                g_user_ctx.acc_id = acc_id;
                g_user_ctx.foreground = foreground;

                mmi_email_util_display_confirm(
                    GRP_ID_ROOT,
                    user_confirm,
                    mmi_frm_scrn_close_active_id,
                    NULL,
                    TRUE,
                    GetString(STR_EMAIL_CONFIRM_ABORT_OTHER_ACCOUNT_NETWORK),
                    MMI_EVENT_QUERY);
            }
        }
        else
        {
            // Add into Q
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_USER_SEND, 5);
            auto_q_add(acc_id, MENWK_T_USERSEND);
        }
        return;
    }

    if (nwkp->s == MEANWK_S_NULL || nwkp->s == MEANWK_S_IDLE)
    {
        // Avaiable
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_USER_SEND, 6);
        fsm_enter(nwkp, MENWK_T_USERSEND, acc_id);
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_USER_SEND, 7);
        // Busy
        if (foreground && nwkp->t != MENWK_T_USERSEND)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_USER_SEND, -8);
            mmi_email_lib_error_popup(STR_EMAIL_CANNOT_SEND_WHEN_UPDATING_ID);
        }
        else
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_USER_SEND, 9);
            // TODO...
            nwkp->need_re_send = TRUE;
        }
    }
}


/////////////////////////////////////////////////////////////////////


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_nwk_user_download
 * DESCRIPTION 
 *  mmi email app nwk user download
 * PARAMETERS 
 *           mmi_id grp_id
 *  EMAIL_ACCT_ID acc_id
 *  EMAIL_FLDR_ID fld_id
 *  EMAIL_MSG_ID msg_id
 *  EMAIL_ATTCH_ID attach_id
 *  srv_email_retrieve_option_enum ret_opt
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_app_nwk_user_download(
        mmi_id grp_id, 
        EMAIL_ACCT_ID acc_id, 
        EMAIL_FLDR_ID fld_id, 
        EMAIL_MSG_ID msg_id, 
        EMAIL_ATTCH_ID attach_id, 
        srv_email_retrieve_option_enum ret_opt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NWK_USER_DOWNLOAD, grp_id, acc_id, fld_id, msg_id, attach_id, ret_opt);
    user_download(grp_id, acc_id, fld_id, msg_id, attach_id, ret_opt, FALSE);
}


/*****************************************************************************
 * FUNCTION 
 *  user_download_abort
 * DESCRIPTION 
 *  user download abort
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void user_download_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_USER_DOWNLOAD_ABORT, __LINE__);
    user_abort(g_user_ctx.acc_id, MENWK_T_USERDOWNLOAD);
    mmi_email_lib_loading_ui_close();
}


/*****************************************************************************
 * FUNCTION 
 *  user_download
 * DESCRIPTION 
 *  user download
 * PARAMETERS 
 *           mmi_id grp_id
 *  EMAIL_ACCT_ID acc_id
 *  EMAIL_FLDR_ID fld_id
 *  EMAIL_MSG_ID msg_id
 *  EMAIL_ATTCH_ID attach_id
 *  srv_email_retrieve_option_enum ret_opt
 *  BOOL confirmed
 * RETURNS 
 *  static void 
*****************************************************************************/
static void user_download(
        mmi_id grp_id, 
        EMAIL_ACCT_ID acc_id, 
        EMAIL_FLDR_ID fld_id, 
        EMAIL_MSG_ID msg_id, 
        EMAIL_ATTCH_ID attach_id, 
        srv_email_retrieve_option_enum ret_opt,
        BOOL confirmed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_nwk_context_struct *nwkp;
    U16 str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_USER_DOWNLOAD, 0);
    ASSERT(g_user_ctx.acc_id == acc_id);

    if (!mmi_email_smgr_network_check())
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_USER_DOWNLOAD, -1);
        return;
    }

    // Check if resource ready
    if (g_frozen_acc_id == acc_id)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_USER_DOWNLOAD, -2);
        ASSERT(0);
        return;
    }

    nwkp = steal_user_nwk(acc_id);
    ASSERT(nwkp != NULL);

    g_user_ctx.acc_id = acc_id;
    g_user_ctx.grp_id = grp_id;
    g_user_ctx.fld_id = fld_id;
    g_user_ctx.msg_id = msg_id;
    g_user_ctx.attach_id = attach_id;
    g_user_ctx.ret_opt = ret_opt;
    if (nwkp->t != MENWK_T_NULL)
    {
        if (!confirmed)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_USER_DOWNLOAD, 3);
            g_user_ctx.t = MENWK_T_USERDOWNLOAD;

            if (nwkp->acc_id == acc_id)
            {
                // Stop own account's background work
                str_id = STR_EMAIL_CONFIRM_ABORT_OWN_ACCOUNT_NETWORK;
            }
            else
            {
                // Stop other account's background work
                str_id = STR_EMAIL_CONFIRM_ABORT_OTHER_ACCOUNT_NETWORK;
            }
            mmi_email_util_display_confirm(
                GRP_ID_ROOT,
                user_confirm,
                mmi_frm_scrn_close_active_id,
                NULL,
                TRUE,
                GetString(str_id),
                MMI_EVENT_QUERY);
            return;
        }

        // Stop other action
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_USER_DOWNLOAD, 4);
        network_abort(nwkp);
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_USER_DOWNLOAD, 5);
    mmi_email_lib_loading_ui_show(g_user_ctx.grp_id, 
        (WCHAR*)GetString(STR_GLOBAL_RECEIVING), 
        user_download_abort);
    fsm_enter(nwkp, MENWK_T_USERDOWNLOAD, acc_id);
}


//////////////////////////////////////////////////////////////////////////////////////
// Delete account from ACCOUNT SETTING

/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_nwk_delaccount
 * DESCRIPTION 
 *  mmi email app nwk delaccount
 * PARAMETERS 
 *  EMAIL_ACCT_ID acc_id
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_app_nwk_delaccount(EMAIL_ACCT_ID acc_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_nwk_context_struct *nwkp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NWK_DELACCOUNT, acc_id);
    ASSERT(g_user_ctx.acc_id == EMAIL_ACCT_INVALID_ID);

    nwkp = get_nwk_by_accid(acc_id);
    if (nwkp != NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NWK_DELACCOUNT, -1);
        network_abort(nwkp);
    }

#ifdef __MMI_EMAIL_IMAP_PUSH__
    // Push account
    if (g_push_ctx.acc_id == acc_id)
    {
        g_push_ctx.acc_id = EMAIL_ACCT_INVALID_ID;
        set_push_icon(PUSH_ICON_NULL);
    }
#endif /* __MMI_EMAIL_IMAP_PUSH__ */

    // Remove it from AUTO-CHECK Q
    auto_q_delete(acc_id);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_nwk_user_is_connected
 * DESCRIPTION 
 *  mmi email app nwk user is connected
 * PARAMETERS 
 *  EMAIL_ACCT_ID acc_id
 * RETURNS 
 *  BOOL 
*****************************************************************************/
BOOL mmi_email_app_nwk_user_is_connected(EMAIL_ACCT_ID acc_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_nwk_context_struct *nwk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nwk = get_nwk_by_accid(acc_id);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NWK_USER_IS_CONNECTED, acc_id, (nwk != NULL));
    return (nwk != NULL);
}

// Disconnect forcelly before EDIT ACCOUNT

/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_nwk_user_disconnect
 * DESCRIPTION 
 *  mmi email app nwk user disconnect
 * PARAMETERS 
 *  EMAIL_ACCT_ID acc_id
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_app_nwk_user_disconnect(EMAIL_ACCT_ID acc_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_nwk_context_struct *nwk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NWK_USER_DISCONNECT, acc_id);
    nwk = get_nwk_by_accid(acc_id);
    if (nwk == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NWK_USER_DISCONNECT, -2);
        return;
    }

    network_abort(nwk);
}

/* For SEND ALL / STOP SEND MENU*/

/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_nwk_is_sending
 * DESCRIPTION 
 *  mmi email app nwk is sending
 * PARAMETERS 
 *  EMAIL_ACCT_ID acc_id
 * RETURNS 
 *  BOOL 
*****************************************************************************/
BOOL mmi_email_app_nwk_is_sending(EMAIL_ACCT_ID acc_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_nwk_context_struct *nwk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NWK_IS_SENDING, acc_id);
    ASSERT(g_user_ctx.acc_id == acc_id);

    nwk = get_nwk_by_accid(acc_id);
    if (nwk == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NWK_IS_SENDING, -100);
        return FALSE;
    }

    switch (nwk->t)
    {
    case MENWK_T_USERSEND:
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NWK_IS_SENDING, 200);
        return TRUE;

    default:
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NWK_IS_SENDING, -300);
        return FALSE;
    }
}

/* For Refresh / Stop MENU */

/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_nwk_is_refreshing
 * DESCRIPTION 
 *  mmi email app nwk is refreshing
 * PARAMETERS 
 *  EMAIL_ACCT_ID acc_id
 * RETURNS 
 *  BOOL 
*****************************************************************************/
BOOL mmi_email_app_nwk_is_refreshing(EMAIL_ACCT_ID acc_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_nwk_context_struct *nwk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NWK_IS_REFRESHING, acc_id);
    ASSERT(g_user_ctx.acc_id == acc_id);

    nwk = get_nwk_by_accid(acc_id);
    if (nwk == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NWK_IS_REFRESHING, -100);
        return FALSE;
    }

    switch (nwk->t)
    {
#ifdef __MMI_EMAIL_EMN__
    case MENWK_T_EMN:
#endif /* __MMI_EMAIL_EMN__ */

#ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__
    case MENWK_T_AUTOCHECK:
#endif /* __MMI_SLIM_EMAIL_NO_AUTO_CHECK__ */

#ifdef __MMI_EMAIL_IMAP_PUSH__
    case MENWK_T_IMAPPUSH:
#endif /* __MMI_EMAIL_IMAP_PUSH__ */

    case MENWK_T_USERREFRESH:
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NWK_IS_REFRESHING, 200);
        return TRUE;

    default:
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NWK_IS_REFRESHING, -300);
        return FALSE;
    }
}

// For message status in OUTBOX

/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_nwk_is_outbox_sending
 * DESCRIPTION 
 *  mmi email app nwk is outbox sending
 * PARAMETERS 
 *  EMAIL_ACCT_ID acc_id
 * RETURNS 
 *  BOOL 
*****************************************************************************/
BOOL mmi_email_app_nwk_is_outbox_sending(EMAIL_ACCT_ID acc_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_nwk_context_struct *nwk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NWK_IS_OUTBOX_SENDING, acc_id);
    ASSERT(g_user_ctx.acc_id == acc_id);

    nwk = get_nwk_by_accid(acc_id);
    if (nwk == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NWK_IS_OUTBOX_SENDING, -100);
        return FALSE;
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NWK_IS_OUTBOX_SENDING, nwk->outbox_is_sending);
    return nwk->outbox_is_sending;
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_nwk_is_msg_sending
 * DESCRIPTION 
 *  mmi email app nwk is msg sending
 * PARAMETERS 
 *  EMAIL_ACCT_ID acc_id
 *  EMAIL_MSG_ID msg_id
 * RETURNS 
 *  BOOL 
*****************************************************************************/
BOOL mmi_email_app_nwk_is_msg_sending(EMAIL_ACCT_ID acc_id, EMAIL_MSG_ID msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_nwk_context_struct *nwk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NWK_IS_MSG_SENDING, acc_id, msg_id);
    ASSERT(acc_id != EMAIL_ACCT_INVALID_ID);
    ASSERT(msg_id != EMAIL_MSG_INVALID_ID);

    nwk = get_nwk_by_accid(acc_id);
    if (nwk == NULL)
    {
        ASSERT(0);
        return FALSE;
    }
    return (nwk->outbox_ongoing_id == msg_id);
}



/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_nwk_is_msg_sendfail
 * DESCRIPTION 
 *  mmi email app nwk is msg sendfail
 * PARAMETERS 
 *  EMAIL_ACCT_ID acc_id
 *  EMAIL_MSG_ID msg_id
 * RETURNS 
 *  BOOL 
*****************************************************************************/
BOOL mmi_email_app_nwk_is_msg_sendfail(EMAIL_ACCT_ID acc_id, EMAIL_MSG_ID msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    mmi_email_nwk_context_struct *nwk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NWK_IS_MSG_SENDFAIL, acc_id, msg_id);
    ASSERT(acc_id != EMAIL_ACCT_INVALID_ID);
    ASSERT(msg_id != EMAIL_MSG_INVALID_ID);

    nwk = get_nwk_by_accid(acc_id);
    if (nwk == NULL)
    {
        ASSERT(0);
        return FALSE;
    }

    for (i = 0; i < nwk->outbox_failed_count; i++)
    {
        if (nwk->outbox_failed_id[i] == msg_id)
        {
            return TRUE;
        }
    }

    return FALSE;
}

// Freeze account during EDIT ACCOUNT / MARK SERVERAL

/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_nwk_freeze
 * DESCRIPTION 
 *  mmi email app nwk freeze
 * PARAMETERS 
 *  EMAIL_ACCT_ID acc_id
 *  BOOL is_freeze
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_app_nwk_freeze(EMAIL_ACCT_ID acc_id, BOOL is_freeze)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    // TODO...
    // Check if connected, if refresh before MARK
#ifdef __MMI_EMAIL_IMAP_PUSH__
    EMAIL_ACCT_ID tmp_acc_id;
#endif 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_NWK_FREEZE, acc_id, is_freeze);
    if (is_freeze)
    {
        ASSERT(acc_id != EMAIL_ACCT_INVALID_ID);
        ASSERT(g_frozen_acc_id == EMAIL_ACCT_INVALID_ID);
        g_frozen_acc_id = acc_id;

        // Pause all refresh action
        // TODO...
    }
    else
    {
#ifdef __MMI_EMAIL_IMAP_PUSH__
        tmp_acc_id = g_frozen_acc_id;
#endif 
        ASSERT(g_frozen_acc_id != EMAIL_ACCT_INVALID_ID);
        g_frozen_acc_id = EMAIL_ACCT_INVALID_ID;

#ifdef __MMI_EMAIL_IMAP_PUSH__
        // Restart AUTO-CHECK Q or PUSH
        if (g_push_ctx.acc_id == tmp_acc_id)
        {
            g_push_ctx.retry_count = 0; // TODO.. 0 OR 1 OR --
            start_push_retry_timer();
        }
#endif /* __MMI_EMAIL_IMAP_PUSH__ */

        start_auto_q_timer();
    }
}


///////////////////////////////////////////////////////////////////////////////////
#ifdef __MMI_EMAIL_IMAP_PUSH__

/*****************************************************************************
 * FUNCTION 
 *  set_push_icon
 * DESCRIPTION 
 *  set push icon
 * PARAMETERS 
 *  U32 s
 * RETURNS 
 *  static void 
*****************************************************************************/
static void set_push_icon(U32 s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static last_s = PUSH_ICON_NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_SET_PUSH_ICON, last_s);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_SET_PUSH_ICON, s);

    if (last_s == s)
    {
        return;
    }

    switch (s)
    {
    case PUSH_ICON_IDLE:
        wgui_status_icon_bar_show_icon(STATUS_ICON_PUSH_CONNECT);
        wgui_status_icon_bar_hide_icon(STATUS_ICON_PUSH_RECEIVE);
        wgui_status_icon_bar_hide_icon(STATUS_ICON_PUSH_FAIL);
        break;

    case PUSH_ICON_BUSY:
        wgui_status_icon_bar_hide_icon(STATUS_ICON_PUSH_CONNECT);
        wgui_status_icon_bar_show_icon(STATUS_ICON_PUSH_RECEIVE);
        wgui_status_icon_bar_hide_icon(STATUS_ICON_PUSH_FAIL);
        break;

    case PUSH_ICON_FAIL:
        wgui_status_icon_bar_hide_icon(STATUS_ICON_PUSH_CONNECT);
        wgui_status_icon_bar_hide_icon(STATUS_ICON_PUSH_RECEIVE);
        wgui_status_icon_bar_show_icon(STATUS_ICON_PUSH_FAIL);
        break;

    case PUSH_ICON_NULL:
    default:
        wgui_status_icon_bar_hide_icon(STATUS_ICON_PUSH_CONNECT);
        wgui_status_icon_bar_hide_icon(STATUS_ICON_PUSH_RECEIVE);
        wgui_status_icon_bar_hide_icon(STATUS_ICON_PUSH_FAIL);
        break;
    }

    last_s = s;
}
#endif /* __MMI_EMAIL_IMAP_PUSH__ */


/*****************************************************************************
 * FUNCTION 
 *  *get_nwk_by_accid
 * DESCRIPTION 
 *  *get nwk by accid
 * PARAMETERS 
 *  EMAIL_ACCT_ID acc_id
 * RETURNS 
 *  static mmi_email_nwk_context_struct 
*****************************************************************************/
static mmi_email_nwk_context_struct *get_nwk_by_accid(EMAIL_ACCT_ID acc_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_nwk_context_struct *nwk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(acc_id != EMAIL_ACCT_INVALID_ID);

    if (g_auto_ctx.nwk.acc_id == acc_id)
    {
        nwk = &g_auto_ctx.nwk;;
    }
#ifdef __MMI_EMAIL_IMAP_PUSH__
    else if (g_push_ctx.nwk.acc_id == acc_id)
    {
        nwk = &g_push_ctx.nwk;
    }
#endif /* __MMI_EMAIL_IMAP_PUSH__ */
    else
    {
        nwk = NULL;
    }

    if (nwk != NULL && nwk->s == MEANWK_S_NULL)
    {
        ASSERT(0);
        nwk->acc_id = EMAIL_ACCT_INVALID_ID;
        nwk = NULL;
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_GET_NWK_BY_ACCID, acc_id, nwk);
    return nwk;
}


/*****************************************************************************
 * FUNCTION 
 *  auto_q_add
 * DESCRIPTION 
 *  auto q add
 * PARAMETERS 
 *  EMAIL_ACCT_ID acc_id
 *  mmi_email_nwk_type_enum t
 * RETURNS 
 *  static void 
*****************************************************************************/
static void auto_q_add(EMAIL_ACCT_ID acc_id, mmi_email_nwk_type_enum t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_AUTO_Q_ADD, acc_id, t);
    for (i = 0; i < g_auto_ctx.count; i++)
    {
        if (g_auto_ctx.acc_id[i] == acc_id)
        {
            // EMN has high priority than AUTO-CHECK
            if (t == MENWK_T_EMN)
            {
                g_auto_ctx.t[i] = MENWK_T_EMN;
            }
            return;
        }
    }

    ASSERT(g_auto_ctx.count < MMI_EMAIL_MAX_ACCTS);
    g_auto_ctx.acc_id[g_auto_ctx.count] = acc_id;
    g_auto_ctx.t[g_auto_ctx.count] = t;

    g_auto_ctx.count++;
    ASSERT(g_auto_ctx.count <= MMI_EMAIL_MAX_ACCTS);
}


/*****************************************************************************
 * FUNCTION 
 *  auto_q_consume
 * DESCRIPTION 
 *  auto q consume
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void auto_q_consume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    EMAIL_ACCT_ID acc_id;
    mmi_email_nwk_type_enum t;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_AUTO_Q_CONSUME, 0);
    if (g_auto_ctx.count == 0)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_AUTO_Q_CONSUME, -100);
        return;
    }

    if (g_auto_ctx.nwk.acc_id != EMAIL_ACCT_INVALID_ID)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_AUTO_Q_CONSUME, -200);
        // Busy
        return;
    }

    if (g_auto_ctx.acc_id[0] == g_frozen_acc_id)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_AUTO_Q_CONSUME, -300);
        // current is setting
        // Will be resumed after quit EDIT mode
        return;
    }

    acc_id = g_auto_ctx.acc_id[0];
    t = g_auto_ctx.t[0];

    g_auto_ctx.count--;
    for (i = 0; i < g_auto_ctx.count; i++)
    {
        g_auto_ctx.acc_id[i] = g_auto_ctx.acc_id[i + 1];
        g_auto_ctx.t[i] = g_auto_ctx.t[i + 1];
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_AUTO_Q_CONSUME, 400);
    fsm_enter(&g_auto_ctx.nwk, t, acc_id);
}


/*****************************************************************************
 * FUNCTION 
 *  auto_q_delete
 * DESCRIPTION 
 *  auto q delete
 * PARAMETERS 
 *  EMAIL_ACCT_ID acc_id
 * RETURNS 
 *  static void 
*****************************************************************************/
static void auto_q_delete(EMAIL_ACCT_ID acc_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_AUTO_Q_DELETE, acc_id);
    for (i = 0; i < g_auto_ctx.count; i++)
    {
        if (g_auto_ctx.acc_id[i] == acc_id)
        {
            break;
        }
    }

    if (i == g_auto_ctx.count || g_auto_ctx.count == 0)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_AUTO_Q_DELETE, -100);
        return;
    }

    g_auto_ctx.count--;
    for (; i < g_auto_ctx.count; i++)
    {
        g_auto_ctx.acc_id[i] = g_auto_ctx.acc_id[i + 1];
        g_auto_ctx.t[i] = g_auto_ctx.t[i + 1];
    }
}


////////////////////////////////////////////////////////////////////////////

/*****************************************************************************
 * FUNCTION 
 *  start_auto_q_timer
 * DESCRIPTION 
 *  start auto q timer
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void start_auto_q_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_START_AUTO_Q_TIMER, __LINE__);
    StartTimer(EMAIL_MMI_AUTO_Q_TIMER_ID, 1000, auto_q_timer_callback);
}


/*****************************************************************************
 * FUNCTION 
 *  stop_auto_q_timer
 * DESCRIPTION 
 *  stop auto q timer
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void stop_auto_q_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_STOP_AUTO_Q_TIMER, __LINE__);
    StopTimer(EMAIL_MMI_AUTO_Q_TIMER_ID);
}


/*****************************************************************************
 * FUNCTION 
 *  auto_q_timer_callback
 * DESCRIPTION 
 *  auto q timer callback
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void auto_q_timer_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_AUTO_Q_TIMER_CALLBACK, __LINE__);
    auto_q_consume();
}

#ifdef __MMI_EMAIL_IMAP_PUSH__

/*****************************************************************************
 * FUNCTION 
 *  start_push_retry_timer
 * DESCRIPTION 
 *  start push retry timer
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void start_push_retry_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 delay = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_START_PUSH_RETRY_TIMER, g_push_ctx.retry_count);
    switch (g_push_ctx.retry_count)
    {
    case 0:
        delay = 1000 * 3; // 3 secondes
        break;

    case 1:
        delay = 1000 * 60 * 2; // 2 minutes
        break;

    case 2:
        delay = 1000 * 60 * 30; // Half an hour
        break;

    case 3:
        delay = 1000 * 60 * 60 * 6; // 6 hours
        break;

    case 999:
        delay = 1000 * 30; // 30 secondes, specail case, Wait 30 seconds for SYS POWNER ON INIT
        g_push_ctx.retry_count = 0;
        break;

    default:
        return; // No retry anymore
    }

    StartTimer(EMAIL_MMI_PUSH_RETRY_TIMER_ID, delay, push_retry_timer_callback);
    g_push_ctx.retry_count++;
}


/*****************************************************************************
 * FUNCTION 
 *  stop_push_retry_timer
 * DESCRIPTION 
 *  stop push retry timer
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void stop_push_retry_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_STOP_PUSH_RETRY_TIMER, __LINE__);
    StopTimer(EMAIL_MMI_PUSH_RETRY_TIMER_ID);
}


/*****************************************************************************
 * FUNCTION 
 *  push_retry_timer_callback
 * DESCRIPTION 
 *  push retry timer callback
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void push_retry_timer_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_PUSH_RETRY_TIMER_CALLBACK, 0);
    if (g_push_ctx.acc_id == EMAIL_ACCT_INVALID_ID)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_PUSH_RETRY_TIMER_CALLBACK, -100);
        return;
    }

    if (g_push_ctx.acc_id == g_frozen_acc_id)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_PUSH_RETRY_TIMER_CALLBACK, -200);
        // current is setting
        // Will be resumed after quit EDIT mode
        return;
    }

    if (g_push_ctx.nwk.t != MENWK_T_NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_PUSH_RETRY_TIMER_CALLBACK, -300);
        return;
    }

    if (!mmi_email_smgr_network_check())
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_PUSH_RETRY_TIMER_CALLBACK, -400);
        start_push_retry_timer();
        return;
    }

    // Start PUSH 
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_PUSH_RETRY_TIMER_CALLBACK, 500);
    fsm_enter(&g_push_ctx.nwk, MENWK_T_IMAPPUSH, g_push_ctx.acc_id);
}
#endif /* __MMI_EMAIL_IMAP_PUSH__ */


////////////////////////////////////////////////////////////////////////////

/*****************************************************************************
 * FUNCTION 
 *  steal_user_nwk
 * DESCRIPTION 
 *  steal user nwk
 * PARAMETERS 
 *  EMAIL_ACCT_ID acc_id
 * RETURNS 
 *  static mmi_email_nwk_context_struct* 
*****************************************************************************/
static mmi_email_nwk_context_struct* steal_user_nwk(EMAIL_ACCT_ID acc_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_nwk_context_struct *nwkp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_STEAL_USER_NWK, acc_id);
    // ASSERT(g_user_ctx.acc_id == acc_id);

    // Steal NETWORK resouce from PUSH or AUTOCHECK
#ifdef __MMI_EMAIL_IMAP_PUSH__
    if (g_push_ctx.acc_id == acc_id)
    {
        nwkp = &g_push_ctx.nwk;
    }
    else
#endif /* __MMI_EMAIL_IMAP_PUSH__ */
    {
        nwkp = &g_auto_ctx.nwk;
    }

    return nwkp;
}


/*****************************************************************************
 * FUNCTION 
 *  fsm_init_context_value
 * DESCRIPTION 
 *  fsm init context value
 * PARAMETERS 
 *  mmi_email_nwk_context_struct *nwkp
 * RETURNS 
 *  static void 
*****************************************************************************/
static void fsm_init_context_value(mmi_email_nwk_context_struct *nwkp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_FSM_INIT_CONTEXT_VALUE, __LINE__);

    nwkp->disconnect_for_refresh = FALSE;
    nwkp->is_send_done = FALSE;

    nwkp->need_re_refresh = FALSE;
    nwkp->need_re_send = FALSE;

    nwkp->ret_major_recv = 0;
    nwkp->ret_major_send = 0;

    nwkp->ret_minor_recv = 0;
    nwkp->ret_minor_send = 0;

    nwkp->recved_unread_count = 0;
    nwkp->recved_total_count = 0;
}


/*****************************************************************************
 * FUNCTION 
 *  fsm_enter
 * DESCRIPTION 
 *  fsm enter
 * PARAMETERS 
 *  mmi_email_nwk_context_struct *nwkp
 *  mmi_email_nwk_status_enum t
 *  EMAIL_ACCT_ID acc_id
 * RETURNS 
 *  static void 
*****************************************************************************/
static void fsm_enter(mmi_email_nwk_context_struct *nwkp, mmi_email_nwk_type_enum t, EMAIL_ACCT_ID acc_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_nwk_status_enum s = MEANWK_S_NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_FSM_ENTER, acc_id, t, nwkp);
    ASSERT(nwkp->t == MENWK_T_NULL);
    ASSERT(t != MENWK_T_NULL);

    if (nwkp->acc_id != EMAIL_ACCT_INVALID_ID &&
        nwkp->acc_id != acc_id)
    {
        //
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_FSM_ENTER, 100, t, nwkp);
        ASSERT(0);
        network_abort(nwkp);
    }

    if (nwkp->s != MEANWK_S_NULL 
        && nwkp->s != MEANWK_S_IDLE)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_FSM_ENTER, 200, t, nwkp);
        ASSERT(0);
        network_abort(nwkp);
    }
    ASSERT(nwkp->s == MEANWK_S_NULL || nwkp->s == MEANWK_S_IDLE);

    if (!email_mmi_lib_is_valid_account(acc_id))
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_FSM_ENTER, -300, t, nwkp);
        WARRING();
        return;
    }

    /* Init flags */
    fsm_init_context_value(nwkp);
    nwkp->acc_id = acc_id;

    switch (t)
    {
    case MENWK_T_EMN:
    case MENWK_T_IMAPPUSH:
    case MENWK_T_AUTOCHECK:
    case MENWK_T_USERREFRESH:
        if (nwkp->s == MEANWK_S_IDLE)
        {
            if (email_mmi_account_data_is_imap_accid(nwkp->acc_id))
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_FSM_ENTER, 400, t, nwkp);
                s = MEANWK_S_SEND;
            }
            else
            {
                // Disconnect firstly for POP3 protocol
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_FSM_ENTER, 500, t, nwkp);
                nwkp->disconnect_for_refresh = TRUE;
                s = MEANWK_S_DISCONNECT;
            }
        }
        else
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_FSM_ENTER, 600, t, nwkp);
            s = MEANWK_S_INIT;
        }

        nwkp->t = t;
        nwkp->s = s;
        outbox_send_begin(nwkp);
        email_mmi_account_data_set_refresh_status(acc_id, EMACC_S_RECEIVING);
        
#ifdef __MMI_NCENTER_SUPPORT__
        mmi_email_ncenter_ongoing_start(acc_id, MMI_TRUE);
#endif /* __MMI_NCENTER_SUPPORT__ */

#ifdef __MMI_EMAIL_IMAP_PUSH__
        if (acc_id == g_push_ctx.acc_id)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_FSM_ENTER, 700, t, nwkp);
            set_push_icon(PUSH_ICON_BUSY);
        }
#endif /* __MMI_EMAIL_IMAP_PUSH__ */
        break;

    case MENWK_T_USERSEND:
        if (nwkp->s == MEANWK_S_IDLE)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_FSM_ENTER, 800, t, nwkp);
            s = MEANWK_S_SEND;
        }
        else
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_FSM_ENTER, 900, t, nwkp);
            s = MEANWK_S_INIT;
        }

        nwkp->t = t;
        nwkp->s = s;
        outbox_send_begin(nwkp);
        email_mmi_account_data_set_send_status(acc_id, EMACC_S_SENDING);
#ifdef __MMI_NCENTER_SUPPORT__
        mmi_email_ncenter_ongoing_start(acc_id, MMI_FALSE);
#endif /* __MMI_NCENTER_SUPPORT__ */
        break;

    case MENWK_T_USERDOWNLOAD:
        if (nwkp->s == MEANWK_S_IDLE)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_FSM_ENTER, 1000, t, nwkp);
            s = MEANWK_S_DOWNLOAD;
        }
        else
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_FSM_ENTER, 2000, t, nwkp);
            s = MEANWK_S_INIT;
        }
        break;

    default:
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_FSM_ENTER, -3000, t, nwkp);

        ASSERT(0);
        break;
    }

    nwkp->t = t;
    nwkp->s = s;

    // Lets GO
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_FSM_ENTER, 9999, t, nwkp);
    fsm_pump(nwkp);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*****************************************************************************
 * FUNCTION 
 *  init_done
 * DESCRIPTION 
 *  init done
 * PARAMETERS 
 *  mmi_email_nwk_context_struct* ctx
 *  BOOL ret
 * RETURNS 
 *  static BOOL 
*****************************************************************************/
static BOOL init_done(mmi_email_nwk_context_struct* ctx, BOOL ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!ret)
    {
        ctx->s = MEANWK_S_NULL;
        return TRUE;
    }

    switch (ctx->t)
    {
    case MENWK_T_AUTOCHECK:
    case MENWK_T_EMN:
    case MENWK_T_USERREFRESH:
    case MENWK_T_IMAPPUSH:
    case MENWK_T_USERDOWNLOAD:
        ctx->s = MEANWK_S_CONNECT;
        break;

    case MENWK_T_USERSEND:
        ctx->s = MEANWK_S_SEND;
        break;

    default:
        ASSERT(0);
        break;
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION 
 *  connect_done
 * DESCRIPTION 
 *  connect done
 * PARAMETERS 
 *  mmi_email_nwk_context_struct* ctx
 *  BOOL ret
 * RETURNS 
 *  static BOOL 
*****************************************************************************/
static BOOL connect_done(mmi_email_nwk_context_struct* ctx, BOOL ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ret)
    {
        ctx->is_connected = TRUE;

#ifdef __MMI_EMAIL_IMAP_PUSH__
        /* Reset retyr timer */
        if (ctx->acc_id == g_push_ctx.acc_id)
        {
            g_push_ctx.retry_count = 1;
        }
#endif /* __MMI_EMAIL_IMAP_PUSH__ */

    }

    switch (ctx->t)
    {
    case MENWK_T_AUTOCHECK:
    case MENWK_T_EMN:
    case MENWK_T_USERREFRESH:
    case MENWK_T_IMAPPUSH:
        if (ctx->is_send_done)
        {
            // Re-connect done after send finished
            if (ret)
            {
                ctx->s = MEANWK_S_RECEIVE;
            }
            else
            {
                // Failed.
                return TRUE;
            }
        }
        else
        {
            // First connect
            ctx->s = MEANWK_S_SEND;
            ctx->is_send_done = TRUE;
        }
        break;

    case MENWK_T_USERDOWNLOAD:
        if (ret)
        {
            ctx->s = MEANWK_S_DOWNLOAD;
        }
        else
        {
            //Failed
            return TRUE;
        }
        break;

    case MENWK_T_USERSEND:
    default:
        ASSERT(0);
        break;
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION 
 *  send_done
 * DESCRIPTION 
 *  send done
 * PARAMETERS 
 *  mmi_email_nwk_context_struct* ctx
 *  BOOL ret
 * RETURNS 
 *  static BOOL 
*****************************************************************************/
static BOOL send_done(mmi_email_nwk_context_struct* ctx, BOOL ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // Incoming server maybe BROKEN after send done; or even NOT connected at all
    if (ctx->need_re_send)
    {
        ctx->s = MEANWK_S_SEND;
        return FALSE;
    }

    switch (ctx->t)
    {
    case MENWK_T_USERSEND:
        if (ctx->is_connected)
        {
            ctx->s = MEANWK_S_IDLE;
        }
        else
        {
            ctx->s = MEANWK_S_INIT;
        }
        return TRUE;

    case MENWK_T_EMN:
    case MENWK_T_IMAPPUSH:
    case MENWK_T_AUTOCHECK:
    case MENWK_T_USERREFRESH:
        if (ctx->is_connected)
        {
            ctx->s = MEANWK_S_RECEIVE;
            return FALSE;
        }
        else
        {
            ctx->s = MEANWK_S_INIT;
            return TRUE;
        }
        //break;

    case MENWK_T_USERDOWNLOAD:
    default:
        ASSERT(0);
        break;
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION 
 *  receive_done
 * DESCRIPTION 
 *  receive done
 * PARAMETERS 
 *  mmi_email_nwk_context_struct* ctx
 *  BOOL ret
 * RETURNS 
 *  static BOOL 
*****************************************************************************/
static BOOL receive_done(mmi_email_nwk_context_struct* ctx, BOOL ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ctx->t)
    {

    case MENWK_T_IMAPPUSH:
    case MENWK_T_AUTOCHECK:
    case MENWK_T_EMN:
    case MENWK_T_USERREFRESH:
    case MENWK_T_USERSEND:
        if (!ctx->is_connected)
        {
            return TRUE;
        }

        if (ctx->acc_id == g_user_ctx.acc_id
#ifdef __MMI_EMAIL_IMAP_PUSH__
            || ctx->acc_id == g_push_ctx.acc_id
#endif /* __MMI_EMAIL_IMAP_PUSH__ */
            )
        {
            if (ctx->need_re_refresh)
            {
                ctx->s = MEANWK_S_RECEIVE;
                return FALSE;
            }
            else if (ctx->need_re_send)
            {
                ctx->s = MEANWK_S_SEND;
                return FALSE;
            }
            else
            {
                ctx->s = MEANWK_S_IDLE;
                return TRUE;
            }
        }
        else
        {
            ctx->s = MEANWK_S_DISCONNECT;
            return FALSE;
        }
       // break;

    case MENWK_T_USERDOWNLOAD:
    default:
        ASSERT(0);
        break;
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION 
 *  download_done
 * DESCRIPTION 
 *  download done
 * PARAMETERS 
 *  mmi_email_nwk_context_struct* ctx
 *  BOOL ret
 * RETURNS 
 *  static BOOL 
*****************************************************************************/
static BOOL download_done(mmi_email_nwk_context_struct* ctx, BOOL ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ctx->t)
    {
    case MENWK_T_USERDOWNLOAD:
        if (ctx->acc_id == g_user_ctx.acc_id 
            || ctx->acc_id == g_user_ctx.acc_id)
        {
            ctx->s = MEANWK_S_IDLE;
            return TRUE;
        }
        else
        {
            ctx->s = MEANWK_S_DISCONNECT;
            return FALSE;
        }
        //break;

    case MENWK_T_AUTOCHECK:
    case MENWK_T_EMN:
    case MENWK_T_USERREFRESH:
    case MENWK_T_IMAPPUSH:
    case MENWK_T_USERSEND:
    default:
        ASSERT(0);
        break;
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION 
 *  disconnect_done
 * DESCRIPTION 
 *  disconnect done
 * PARAMETERS 
 *  mmi_email_nwk_context_struct* ctx
 *  BOOL ret
 * RETURNS 
 *  static BOOL 
*****************************************************************************/
static BOOL disconnect_done(mmi_email_nwk_context_struct* ctx, BOOL ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ctx->is_connected = FALSE;

    // Disconnect to refresh
    if (ctx->disconnect_for_refresh)
    {
        ctx->disconnect_for_refresh = FALSE;
        ctx->s = MEANWK_S_CONNECT;
        return FALSE;
    }
    else
    {
        network_close(ctx);
        ctx->s = MEANWK_S_NULL;
        return TRUE;
    }
}


/*****************************************************************************
 * FUNCTION 
 *  next_state
 * DESCRIPTION 
 *  next state
 * PARAMETERS 
 *  mmi_email_nwk_context_struct* ctx
 *  BOOL ret
 * RETURNS 
 *  static void 
*****************************************************************************/
static void next_state(mmi_email_nwk_context_struct* ctx, BOOL ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL done = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_NEXT_STATE, ctx->acc_id, ctx, ctx->s, ret, done);

    switch (ctx->s)
    {
    case MEANWK_S_INIT:
        done = init_done(ctx, ret);
        break;

    case MEANWK_S_CONNECT:
        done = connect_done(ctx, ret);
        break;

    case MEANWK_S_SEND:
        done = send_done(ctx, ret);
        break;

    case MEANWK_S_RECEIVE:
        done =  receive_done(ctx, ret);
        break;

    case MEANWK_S_DOWNLOAD:
        done = download_done(ctx, ret);
        break;

    case MEANWK_S_DISCONNECT:
        done = disconnect_done(ctx, ret);
        break;

    case MEANWK_S_IDLE:
    default:
        ASSERT(0);
        return;
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_NEXT_STATE, ctx->acc_id, ctx, ctx->s, ret, done);
    if (done)
    {
        fsm_report(ctx);
    }
    else
    {
        fsm_pump(ctx);
    }
}


/*****************************************************************************
 * FUNCTION 
 *  email_srv_callback
 * DESCRIPTION 
 *  email srv callback
 * PARAMETERS 
 *  srv_email_result_struct *result
 *  EMAIL_REQ_ID req_id
 *  void *user_data
 * RETURNS 
 *  void 
*****************************************************************************/
void email_srv_callback(srv_email_result_struct *result,EMAIL_REQ_ID req_id,void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_nwk_context_struct *ctx;
    ctx = (mmi_email_nwk_context_struct*)user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(ctx != NULL);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_EMAIL_SRV_CALLBACK, 0);
    if (req_id != ctx->srv_req_id)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_EMAIL_SRV_CALLBACK, -100);
        return;
    }

    switch (ctx->s)
    {
    case MEANWK_S_CONNECT:
        email_srv_connect_callback(result, ctx);
        break;

    case MEANWK_S_SEND:
        email_srv_send_callback(result, ctx);
        break;

    case MEANWK_S_RECEIVE:
        email_srv_refresh_callback(result, ctx);
        break;

    case MEANWK_S_DOWNLOAD:
        email_srv_download_callback(result, ctx);
        break;

    case MEANWK_S_DISCONNECT:
        email_srv_disconnect_callback(result, ctx);
        break;

    default:
        break;
    }
}


/*****************************************************************************
 * FUNCTION 
 *  save_erorr_code
 * DESCRIPTION 
 *  save erorr code
 * PARAMETERS 
 *  srv_email_result_struct *result
 *  mmi_email_nwk_context_struct *ctx
 *  BOOL is_incoming
 * RETURNS 
 *  static void 
*****************************************************************************/
static void save_erorr_code(srv_email_result_struct *result, mmi_email_nwk_context_struct *ctx, BOOL is_incoming)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_SAVE_ERORR_CODE, result->result, result->major, result->minor);
    if (result->result)
    {
        return;
    }

    if (is_incoming)
    {
        if (ctx->ret_major_recv == 0)
        {
            ctx->ret_major_recv = result->major;
            ctx->ret_minor_recv = result->minor;
        }
    }
    else
    {
        if (ctx->ret_major_send == 0)
        {
            ctx->ret_major_send = result->major;
            ctx->ret_minor_send = result->minor;
        }
    }

}


/*****************************************************************************
 * FUNCTION 
 *  email_srv_connect_callback
 * DESCRIPTION 
 *  email srv connect callback
 * PARAMETERS 
 *  srv_email_result_struct *result
 *  mmi_email_nwk_context_struct *ctx
 * RETURNS 
 *  static void 
*****************************************************************************/
static void email_srv_connect_callback(srv_email_result_struct *result, mmi_email_nwk_context_struct *ctx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_EMAIL_SRV_CONNECT_CALLBACK, __LINE__);
    save_erorr_code(result, ctx, TRUE);
    next_state(ctx, result->result);
}


/*****************************************************************************
 * FUNCTION 
 *  email_srv_refresh_callback
 * DESCRIPTION 
 *  email srv refresh callback
 * PARAMETERS 
 *  srv_email_result_struct *result
 *  mmi_email_nwk_context_struct *ctx
 * RETURNS 
 *  static void 
*****************************************************************************/
static void email_srv_refresh_callback(srv_email_result_struct *result, mmi_email_nwk_context_struct *ctx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_EMAIL_SRV_REFRESH_CALLBACK, __LINE__);
    save_erorr_code(result, ctx, TRUE);
    next_state(ctx, result->result);
}


/*****************************************************************************
 * FUNCTION 
 *  email_srv_download_callback
 * DESCRIPTION 
 *  email srv download callback
 * PARAMETERS 
 *  srv_email_result_struct *result
 *  mmi_email_nwk_context_struct *ctx
 * RETURNS 
 *  static void 
*****************************************************************************/
static void email_srv_download_callback(srv_email_result_struct *result, mmi_email_nwk_context_struct *ctx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_EMAIL_SRV_DOWNLOAD_CALLBACK, __LINE__);

    save_erorr_code(result, ctx, TRUE);

    srv_email_msg_clear_callback(ctx->msg_handle);
    srv_email_msg_clear_proc_callback(ctx->msg_handle);

    next_state(ctx, result->result);
}


/*****************************************************************************
 * FUNCTION 
 *  email_srv_send_callback
 * DESCRIPTION 
 *  email srv send callback
 * PARAMETERS 
 *  srv_email_result_struct *result
 *  mmi_email_nwk_context_struct *ctx
 * RETURNS 
 *  static void 
*****************************************************************************/
static void email_srv_send_callback(srv_email_result_struct *result, mmi_email_nwk_context_struct *ctx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_EMAIL_SRV_SEND_CALLBACK, __LINE__);
    save_erorr_code(result, ctx, FALSE);
    next_state(ctx, result->result);
}


/*****************************************************************************
 * FUNCTION 
 *  email_srv_disconnect_callback
 * DESCRIPTION 
 *  email srv disconnect callback
 * PARAMETERS 
 *  srv_email_result_struct *result
 *  mmi_email_nwk_context_struct *ctx
 * RETURNS 
 *  static void 
*****************************************************************************/
static void email_srv_disconnect_callback(srv_email_result_struct *result, mmi_email_nwk_context_struct *ctx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_EMAIL_SRV_DISCONNECT_CALLBACK, __LINE__);
    // Do NOT care the result of dis-connect action
    next_state(ctx, result->result);
}


/*****************************************************************************
 * FUNCTION 
 *  pump_callback
 * DESCRIPTION 
 *  pump callback
 * PARAMETERS 
 *  mmi_event_struct *param
 * RETURNS 
 *  static mmi_ret 
*****************************************************************************/
static mmi_ret pump_callback(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_PUMP_CALLBACK, __LINE__);
    network_fsm((mmi_email_nwk_context_struct*)param->user_data);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION 
 *  fsm_pump
 * DESCRIPTION 
 *  fsm pump
 * PARAMETERS 
 *  mmi_email_nwk_context_struct *ctx
 * RETURNS 
 *  static void 
*****************************************************************************/
static void fsm_pump(mmi_email_nwk_context_struct *ctx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_FSM_PUMP, __LINE__);

    evt.evt_id = 0;
    evt.size = sizeof(mmi_event_struct);
    evt.user_data = ctx;

    mmi_frm_post_event(&evt, pump_callback, ctx);
}


/*****************************************************************************
 * FUNCTION 
 *  report_user_download
 * DESCRIPTION 
 *  report user download
 * PARAMETERS 
 *  mmi_email_nwk_context_struct *ctx
 * RETURNS 
 *  static void 
*****************************************************************************/
static void report_user_download(mmi_email_nwk_context_struct *ctx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_REPORT_USER_DOWNLOAD, 0);
    ASSERT(g_user_ctx.acc_id == ctx->acc_id);

    // Close loading screen
    mmi_email_lib_loading_ui_close();

    if (ctx->msg_handle != EMAIL_MSG_INVALID_HANDLE)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_REPORT_USER_DOWNLOAD, 400);

        srv_email_msg_clear_callback(ctx->msg_handle);
        srv_email_msg_clear_proc_callback(ctx->msg_handle);
    }

    mmi_email_read_pf_update_info(ctx->msg_handle, ctx->ret_major_recv, ctx->ret_minor_recv, g_user_ctx.down_size);

    if (ctx->msg_handle != EMAIL_MSG_INVALID_HANDLE)
    {
        srv_email_msg_destroy(ctx->msg_handle);
        ctx->msg_handle = EMAIL_MSG_INVALID_HANDLE;
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_REPORT_USER_DOWNLOAD, 500);
}


/*****************************************************************************
 * FUNCTION 
 *  report_user_send
 * DESCRIPTION 
 *  report user send
 * PARAMETERS 
 *  mmi_email_nwk_context_struct *ctx
 * RETURNS 
 *  static void 
*****************************************************************************/
static void report_user_send(mmi_email_nwk_context_struct *ctx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_REPORT_USER_SEND, ctx->ret_major_send);

    if (ctx->ret_major_send == 0)
    {
        email_mmi_account_data_set_send_status(ctx->acc_id, EMACC_S_NORMAL);
    }
    else
    {
        email_mmi_account_data_set_send_status(ctx->acc_id, EMACC_S_SENDFAIL);
    }

#ifdef __MMI_NCENTER_SUPPORT__
    mmi_email_ncenter_ongoing_done(ctx->acc_id);
#endif /* __MMI_NCENTER_SUPPORT__ */
}

static BOOL is_memory_card_plugout_error(S32 major, S32 minor)
{
    if (major != SRV_EMAIL_RESULT_FS_ERROR)
    {
        return FALSE;
    }

    if (minor == FS_MEDIA_CHANGED 
        || minor == FS_MSDC_READ_SECTOR_ERROR
        || minor == FS_MSDC_WRITE_SECTOR_ERROR)
    {
        return TRUE;
    }

    return FALSE;
}

/*****************************************************************************
 * FUNCTION 
 *  UI_report
 * DESCRIPTION 
 *  UI report
 * PARAMETERS 
 *  mmi_email_nwk_context_struct *ctx
 * RETURNS 
 *  static void 
*****************************************************************************/
static void UI_report(mmi_email_nwk_context_struct *ctx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_batch_receive_result_struct ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_UI_REPORT, ctx->ret_major_recv, ctx->ret_minor_recv);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_UI_REPORT, ctx->ret_major_send, ctx->ret_minor_send);
    if (ctx->ret_major_send != 0)
    {
        email_mmi_account_data_set_send_status(ctx->acc_id, EMACC_S_SENDFAIL);
    }
    else
    {
        email_mmi_account_data_set_send_status(ctx->acc_id, EMACC_S_NORMAL);
    }

    if (ctx->ret_major_recv != 0)
    {
        email_mmi_account_data_set_refresh_status(ctx->acc_id, EMACC_S_RECEIVEFAIL);
    }
    else
    {
        email_mmi_account_data_set_refresh_status(ctx->acc_id, EMACC_S_NORMAL);
    }

#ifdef __MMI_NCENTER_SUPPORT__
    mmi_email_ncenter_ongoing_done(ctx->acc_id);
#endif /* __MMI_NCENTER_SUPPORT__ */

    if (is_memory_card_plugout_error(ctx->ret_major_recv, ctx->ret_minor_recv)
        || !mmi_email_smgr_network_check())
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_UI_REPORT, -2, -2);
        return;
    }

    ret.result = (ctx->ret_major_recv == 0);
    ret.unread_count = ctx->recved_unread_count;
    ret.total_count = ctx->recved_total_count;
    ret.error_code = 0;
    if (!ret.result)
    {
        ret.error_code = mmi_email_util_get_err_code(ctx->ret_major_recv, ctx->ret_minor_recv);
    }
    ret.acct_id = ctx->acc_id;

    email_mmi_account_data_update_inbox_number(ctx->acc_id, 0xFFFFFFFF, 0xFFFFFFFF);
    mmi_email_batch_receive_report(&ret, (MMI_BOOL)(ctx->acc_id == g_user_ctx.acc_id));
}


/*****************************************************************************
 * FUNCTION 
 *  report_user_refresh
 * DESCRIPTION 
 *  report user refresh
 * PARAMETERS 
 *  mmi_email_nwk_context_struct *ctx
 * RETURNS 
 *  static void 
*****************************************************************************/
static void report_user_refresh(mmi_email_nwk_context_struct *ctx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_REPORT_USER_REFRESH, __LINE__);
    UI_report(ctx);
}

#ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__
/*****************************************************************************
 * FUNCTION 
 *  report_user_autocheck
 * DESCRIPTION 
 *  report user autocheck
 * PARAMETERS 
 *  mmi_email_nwk_context_struct *ctx
 * RETURNS 
 *  static void 
*****************************************************************************/
static void report_user_autocheck(mmi_email_nwk_context_struct *ctx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_REPORT_USER_AUTOCHECK, __LINE__);

    UI_report(ctx);

    // Re-start this account's AUTO-CHECK
    mmi_email_auto_check_start(ctx->acc_id);
}
#endif /* __MMI_SLIM_EMAIL_NO_AUTO_CHECK__ */


#ifdef __MMI_EMAIL_EMN__
/*****************************************************************************
 * FUNCTION 
 *  report_user_emn
 * DESCRIPTION 
 *  report user emn
 * PARAMETERS 
 *  mmi_email_nwk_context_struct *ctx
 * RETURNS 
 *  static void 
*****************************************************************************/
static void report_user_emn(mmi_email_nwk_context_struct *ctx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_REPORT_USER_EMN, __LINE__);

    UI_report(ctx);
    mmi_email_receive_emn_result_handler(ctx->acc_id);
}
#endif /* __MMI_EMAIL_EMN__ */


#ifdef __MMI_EMAIL_IMAP_PUSH__
/*****************************************************************************
 * FUNCTION 
 *  report_user_push
 * DESCRIPTION 
 *  report user push
 * PARAMETERS 
 *  mmi_email_nwk_context_struct *ctx
 * RETURNS 
 *  static void 
*****************************************************************************/
static void report_user_push(mmi_email_nwk_context_struct *ctx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_REPORT_USER_PUSH, __LINE__);
    UI_report(ctx);
}
#endif /* __MMI_EMAIL_IMAP_PUSH__ */


/*****************************************************************************
 * FUNCTION 
 *  fsm_report
 * DESCRIPTION 
 *  fsm report
 * PARAMETERS 
 *  mmi_email_nwk_context_struct *ctx
 * RETURNS 
 *  static void 
*****************************************************************************/
static void fsm_report(mmi_email_nwk_context_struct *ctx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_FSM_REPORT, __LINE__);
    // One action is DONE.
    switch (ctx->t)
    {
    case MENWK_T_USERDOWNLOAD:
        report_user_download(ctx);
        break;

#ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__
    case MENWK_T_AUTOCHECK:
        report_user_autocheck(ctx);
        break;
#endif /* __MMI_SLIM_EMAIL_NO_AUTO_CHECK__ */

#ifdef __MMI_EMAIL_EMN__
    case MENWK_T_EMN:
        report_user_emn(ctx);
        break;
#endif /* __MMI_EMAIL_EMN__ */

    case MENWK_T_USERREFRESH:
        report_user_refresh(ctx);
        break;

#ifdef __MMI_EMAIL_IMAP_PUSH__
    case MENWK_T_IMAPPUSH:
        report_user_push(ctx);
        break;
#endif /* __MMI_EMAIL_IMAP_PUSH__ */

    case MENWK_T_USERSEND:
        report_user_send(ctx);
        break;

    default:
        ASSERT(0);
        break;
    }

    if (ctx->t != MENWK_T_USERDOWNLOAD)
    {
        outbox_send_done(ctx);
    }

#ifdef __MMI_EMAIL_IMAP_PUSH__
    if (ctx == &g_push_ctx.nwk)
    {
        if (ctx->s == MEANWK_S_IDLE)
        {
            set_push_icon(PUSH_ICON_IDLE);
        }
        else
        {
            start_push_retry_timer();
            set_push_icon(PUSH_ICON_FAIL);
        }
    }
#endif /* __MMI_EMAIL_IMAP_PUSH__ */

    if (ctx == &g_auto_ctx.nwk)
    {
        start_auto_q_timer();
    }

    // Action done
    ctx->t = MENWK_T_NULL;
    if (ctx->s != MEANWK_S_IDLE)
    {
        // TODO...
        network_reset(ctx);
    }

    if (ctx->s == MEANWK_S_IDLE 
        && ctx->need_re_refresh 
        && (ctx->acc_id == g_user_ctx.acc_id
#ifdef __MMI_EMAIL_IMAP_PUSH__
            || ctx->acc_id == g_push_ctx.acc_id
#endif /* __MMI_EMAIL_IMAP_PUSH__ */
            )
        )
    {
        on_refresh(ctx);
    }
}


/*****************************************************************************
 * FUNCTION 
 *  network_fsm
 * DESCRIPTION 
 *  network fsm
 * PARAMETERS 
 *  mmi_email_nwk_context_struct *ctx
 * RETURNS 
 *  static void 
*****************************************************************************/
static void network_fsm(mmi_email_nwk_context_struct *ctx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum ret_srv = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_FSM, ctx->s, ret_srv);

    switch (ctx->s)
    {
    case MEANWK_S_INIT:
        srv_email_acct_create(0, &ctx->acct_handle);
        ret_srv = srv_email_acct_open(ctx->acct_handle, ctx->acc_id);

        srv_email_acct_register_callback(ctx->acct_handle, email_srv_callback, ctx);
        srv_email_acct_register_proc_callback(ctx->acct_handle, email_srv_procedue, ctx);

        ASSERT(ret_srv != SRV_EMAIL_RESULT_WOULDBLOCK);
        break;

    case MEANWK_S_CONNECT:
        ret_srv = srv_email_acct_connect(ctx->acct_handle, MMI_TRUE, &ctx->srv_req_id);
        break;

    case MEANWK_S_SEND:
        ctx->need_re_send = FALSE;
        ret_srv = SRV_EMAIL_RESULT_SUCC;
        if (mmi_email_lib_get_outbox_number(ctx->acct_handle, &ctx->outbox_id) > 0)
        {
            ret_srv = srv_email_acct_send(ctx->acct_handle, mmi_email_account_save_sent_emails(ctx->acc_id), &ctx->srv_req_id);
        }
        break;

    case MEANWK_S_RECEIVE:
        ctx->need_re_refresh = FALSE;
        ret_srv = srv_email_acct_receive(ctx->acct_handle, SRV_EMAIL_RECEIVE_NEW_EMAIL, &ctx->srv_req_id);
        break;

    case MEANWK_S_DOWNLOAD:
        ret_srv = msg_download(ctx);
        break;

    case MEANWK_S_DISCONNECT:
        ret_srv = srv_email_acct_disconnect(ctx->acct_handle, MMI_TRUE, MMI_FALSE, &ctx->srv_req_id);
        break;

    default:
        ASSERT(0);
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_FSM, ctx->s, -999);
        return;
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_FSM, ctx->s, ret_srv);
    if (ret_srv == SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        // Wait for async callback
        return;
    }

    if (ret_srv != SRV_EMAIL_RESULT_SUCC)
    {
        // Save error code
        static srv_email_result_struct temp;

        temp.result = MMI_FALSE;

        if (ret_srv == SRV_EMAIL_RESULT_FS_ERROR)
        {
            temp.major = ret_srv;
            temp.minor = srv_email_errno_get();
        }
        else
        {
            temp.major = SRV_EMAIL_MAIL_ERROR;
            temp.minor = ret_srv;
        }

        save_erorr_code(&temp, ctx, ctx->s != MEANWK_S_SEND);
    }

    next_state(ctx, (ret_srv == SRV_EMAIL_RESULT_SUCC));
}


/*****************************************************************************
 * FUNCTION 
 *  network_abort
 * DESCRIPTION 
 *  network abort
 * PARAMETERS 
 *  mmi_email_nwk_context_struct *p
 * RETURNS 
 *  static void 
*****************************************************************************/
static void network_abort(mmi_email_nwk_context_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_ABORT, __LINE__);
    if (p->t != MENWK_T_NULL)
    {
        ASSERT(p->s != MEANWK_S_IDLE && p->s != MEANWK_S_NULL);
        network_close(p);
        fsm_report(p);
    }

    network_reset(p);
}


/*****************************************************************************
 * FUNCTION 
 *  network_reset
 * DESCRIPTION 
 *  network reset
 * PARAMETERS 
 *  mmi_email_nwk_context_struct *p
 * RETURNS 
 *  static void 
*****************************************************************************/
static void network_reset(mmi_email_nwk_context_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_RESET, __LINE__);

    network_close(p);
    memset(p, 0, sizeof(mmi_email_nwk_context_struct));
}


/*****************************************************************************
 * FUNCTION 
 *  network_close
 * DESCRIPTION 
 *  network close
 * PARAMETERS 
 *  mmi_email_nwk_context_struct *p
 * RETURNS 
 *  static void 
*****************************************************************************/
static void network_close(mmi_email_nwk_context_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_CLOSE, __LINE__);

    if (p->msg_handle != EMAIL_MSG_INVALID_HANDLE)
    {
        srv_email_msg_clear_callback(p->msg_handle);
        srv_email_msg_clear_proc_callback(p->msg_handle);
        srv_email_msg_destroy(p->msg_handle);

        p->msg_handle = EMAIL_MSG_INVALID_HANDLE;
    }

    if (p->acct_handle != EMAIL_ACCT_INVALID_HANDLE)
    {
        srv_email_acct_clear_callback(p->acct_handle);
        srv_email_acct_clear_proc_callback(p->acct_handle);
        srv_email_acct_destroy(p->acct_handle);

        p->acct_handle = EMAIL_ACCT_INVALID_HANDLE;
    }

    p->is_connected = FALSE;
    p->s = MEANWK_S_NULL;

#ifdef __MMI_EMAIL_IMAP_PUSH__
    if (p->acc_id == g_push_ctx.acc_id && g_push_ctx.acc_id != EMAIL_ACCT_INVALID_ID)
    {
        set_push_icon(PUSH_ICON_FAIL);
    }
#endif /* __MMI_EMAIL_IMAP_PUSH__ */
}


/*****************************************************************************
 * FUNCTION 
 *  msg_download
 * DESCRIPTION 
 *  msg download
 * PARAMETERS 
 *  mmi_email_nwk_context_struct *p
 * RETURNS 
 *  static srv_email_result_enum 
*****************************************************************************/
static srv_email_result_enum msg_download(mmi_email_nwk_context_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;
    srv_email_acct_info_struct *acct_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_MSG_DOWNLOAD, 0);

    acct_info = OslMalloc(sizeof(srv_email_acct_info_struct));
    result = srv_email_acct_read(p->acct_handle, acct_info);
    g_user_ctx.down_size = acct_info->download_size;
    OslMfree(acct_info);

    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_MSG_DOWNLOAD, -100);
        WARRING();
        return result;
    }

    result = srv_email_msg_create(0, &p->msg_handle);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_MSG_DOWNLOAD, -200);
        WARRING();
        return result;
    }

    result = srv_email_msg_open(
        p->msg_handle,
        g_user_ctx.acc_id,
        g_user_ctx.fld_id,
        g_user_ctx.msg_id);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_MSG_DOWNLOAD, -300);
        return result;
    }

    result = srv_email_msg_retrieve(
        p->msg_handle,
        g_user_ctx.ret_opt,
        g_user_ctx.attach_id,
        &p->srv_req_id);
    if (result != SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_MSG_DOWNLOAD, -400);
        return result;
    }

    srv_email_msg_regist_callback(
        p->msg_handle,
        email_srv_callback,
        p);
    srv_email_msg_regist_proc_callback(
        p->msg_handle,
        email_srv_procedue,
        p);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_MSG_DOWNLOAD, 500);
    return SRV_EMAIL_RESULT_WOULDBLOCK;
}

static MMI_RET cmb_group_proc(mmi_event_struct *evt)
{
    cui_evt_cbm_bearer_select_struct* cbm_evt;
    mmi_email_nwk_context_struct *ctx;

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_CBM_OK:
        case EVT_ID_CUI_CBM_FAIL:
        case EVT_ID_CUI_CBM_CANCEL:
            cbm_evt = (cui_evt_cbm_bearer_select_struct*)evt;
            ctx = (mmi_email_nwk_context_struct*)evt->user_data;

            if (SRV_CBM_BEARER_ALWAYS_ASK == ctx->cbm_type)
            {
                cui_cbm_always_ask_close(cbm_evt->sender_id);
            }
            else if (SRV_CBM_BEARER_FB_L1 == ctx->cbm_type)
            {
                cui_cbm_always_ask_close(cbm_evt->sender_id);
            }
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


static mmi_id cmb_create_group(mmi_email_nwk_context_struct *ctx)
{
    ctx->cmb_grp_id = 
        mmi_frm_group_create_ex(
            GRP_ID_ROOT,
            GRP_ID_AUTO_GEN,
            cmb_group_proc,
            ctx,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);

    return ctx->cmb_grp_id;
}


/*****************************************************************************
 * FUNCTION 
 *  email_srv_procedue
 * DESCRIPTION 
 *  email srv procedue
 * PARAMETERS 
 *  srv_email_nwk_proc_struct *data
 * RETURNS 
 *  static void 
*****************************************************************************/
static void email_srv_procedue(srv_email_nwk_proc_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_nwk_context_struct *ctx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_EMAIL_SRV_PROCEDUE, data->status);

    ctx = (mmi_email_nwk_context_struct*)data->user_data;
    switch (data->status)
    {
        case SRV_EMAIL_NWK_CBM_QUERYING:
            {
                cui_cbm_parameter_struct cbm_param = {0};
                srv_email_cbm_querying_struct *query = (srv_email_cbm_querying_struct*)data->status_data;
                srv_cbm_bearer_event_struct *cbm_data = (srv_cbm_bearer_event_struct*)query->cbm_data;
                cbm_param.account_id = cbm_data->account_id;
                cbm_param.res.icon_id = IMG_EMAIL_APP1_ID;
                cbm_param.res.str_id = STR_GLOBAL_EMAIL;
                cbm_param.fb_query_type = CUI_CBM_QUERY_FB_NORM;

                if (cbm_data->type == SRV_CBM_BEARER_ALWAYS_ASK)
                {
                    ctx->cbm_type = cbm_data->type;
                    ctx->cbm_id = cui_cbm_always_ask_create(cmb_create_group(ctx));
                    cui_cbm_always_ask_set_param(ctx->cbm_id, &cbm_param);
                    cui_cbm_always_ask_run(ctx->cbm_id);
                }
                else if (cbm_data->type == SRV_CBM_BEARER_FB_L1)
                {
                    ctx->cbm_type = cbm_data->type;
                    ctx->cbm_id = cui_cbm_bearer_fallback_create(cmb_create_group(ctx));
                    cui_cbm_bearer_fallback_set_param(ctx->cbm_id, &cbm_param);
                    cui_cbm_bearer_fallback_run(ctx->cbm_id);
                }
            }
            break;

        case SRV_EMAIL_NWK_QUERYING:
            {
                srv_email_querying_data_struct *query = (srv_email_querying_data_struct*)data->status_data;
                (*query->callback)(MMI_FALSE, query->username, query->password, query->user_data);
            }
            break;

        case SRV_EMAIL_NWK_UPDATING:
            break;

        case SRV_EMAIL_NWK_SENDING:
            on_sending(ctx, (srv_email_sending_data_struct*)data->status_data);
            break;

        case SRV_EMAIL_NWK_RECEIVING:
            on_receiving(ctx, (srv_email_receiving_data_struct*)data->status_data);
            break;

        case SRV_EMAIL_NWK_SYNCING:
            break;

        case SRV_EMAIL_NWK_DELETING:
            break;

        case SRV_EMAIL_NWK_LISTING_FOLDER:
            break;

        case SRV_EMAIL_NWK_DISCONNECTING:
            break;

        case SRV_EMAIL_NWK_NEED_REFRESH:
            on_refresh(ctx);
            break;

        case SRV_EMAIL_NWK_DISCONNECTED:
            on_disconnected(ctx);
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION 
 *  on_refresh
 * DESCRIPTION 
 *  on refresh
 * PARAMETERS 
 *  mmi_email_nwk_context_struct *nwk
 * RETURNS 
 *  static void 
*****************************************************************************/
static void on_refresh(mmi_email_nwk_context_struct *nwk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO...
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_ON_REFRESH, 0);

    if (nwk->acc_id != g_user_ctx.acc_id 
#ifdef __MMI_EMAIL_IMAP_PUSH__
        && nwk->acc_id != g_push_ctx.acc_id
#endif /* __MMI_EMAIL_IMAP_PUSH__ */
        )
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_ON_REFRESH, -100);
        return;
    }

    if (nwk->acc_id == g_frozen_acc_id)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_ON_REFRESH, -200);
        return;
    }

    if (nwk->s != MEANWK_S_IDLE)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_ON_REFRESH, -300);
        nwk->need_re_refresh = TRUE;
        return;
    }

#ifdef __MMI_EMAIL_IMAP_PUSH__
    if (nwk->acc_id == g_push_ctx.acc_id)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_ON_REFRESH, 400);
        fsm_enter(nwk, MENWK_T_IMAPPUSH, nwk->acc_id);
    }
    else
#endif /* __MMI_EMAIL_IMAP_PUSH__ */
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_ON_REFRESH, 500);
        fsm_enter(nwk, MENWK_T_USERREFRESH, nwk->acc_id);
    }
}


/*****************************************************************************
 * FUNCTION 
 *  outbox_send_begin
 * DESCRIPTION 
 *  outbox send begin
 * PARAMETERS 
 *  mmi_email_nwk_context_struct *ctx
 * RETURNS 
 *  static void 
*****************************************************************************/
static void outbox_send_begin(mmi_email_nwk_context_struct *ctx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_OUTBOX_SEND_BEGIN, __LINE__);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(ctx != NULL);
    ctx->outbox_is_sending = TRUE;
    ctx->outbox_ongoing_id = EMAIL_MSG_INVALID_ID;
    ctx->outbox_failed_count = 0;

    mmi_email_ui_refresh_folder(ctx->acc_id, ctx->outbox_id);
    mmi_email_ui_close_outboxmsg(ctx->acc_id);
}


/*****************************************************************************
 * FUNCTION 
 *  outbox_send_done
 * DESCRIPTION 
 *  outbox send done
 * PARAMETERS 
 *  mmi_email_nwk_context_struct *ctx
 * RETURNS 
 *  static void 
*****************************************************************************/
static void outbox_send_done(mmi_email_nwk_context_struct *ctx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_OUTBOX_SEND_DONE, __LINE__);

    ASSERT(ctx != NULL);
    ctx->outbox_is_sending = FALSE;
    ctx->outbox_ongoing_id = EMAIL_MSG_INVALID_ID;
    ctx->outbox_failed_count = 0;

    mmi_email_ui_refresh_folder(ctx->acc_id, ctx->outbox_id);
}


/*****************************************************************************
 * FUNCTION 
 *  outbox_add_failed_msg
 * DESCRIPTION 
 *  outbox add failed msg
 * PARAMETERS 
 *  mmi_email_nwk_context_struct *ctx
 * RETURNS 
 *  static void 
*****************************************************************************/
static void outbox_add_failed_msg(mmi_email_nwk_context_struct *ctx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_OUTBOX_ADD_FAILED_MSG, __LINE__);
    ASSERT(ctx->acc_id != EMAIL_ACCT_INVALID_ID);
    ASSERT(ctx->outbox_ongoing_id != EMAIL_MSG_INVALID_ID);

    for (i = 0; i < ctx->outbox_failed_count; i++)
    {
        if (ctx->outbox_failed_id[i] == ctx->outbox_ongoing_id)
        {
            return;
        }
    }

    ASSERT(ctx->outbox_failed_count < SRV_EMAIL_GLOBAL_MAX_MSG_NUM);
    ctx->outbox_failed_id[ctx->outbox_failed_count++] = ctx->outbox_ongoing_id;
}


/*****************************************************************************
 * FUNCTION 
 *  on_sending
 * DESCRIPTION 
 *  on sending
 * PARAMETERS 
 *  mmi_email_nwk_context_struct *ctx
 *  srv_email_sending_data_struct *send
 * RETURNS 
 *  static void 
*****************************************************************************/
static void on_sending(mmi_email_nwk_context_struct *ctx, srv_email_sending_data_struct *send)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_ON_SENDING, __LINE__);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!send->result && ctx->outbox_ongoing_id != EMAIL_MSG_INVALID_ID)
    {
        outbox_add_failed_msg(ctx);
    }

    ctx->outbox_ongoing_id = send->msg_id;
    mmi_email_ui_refresh_folder(ctx->acc_id, ctx->outbox_id);
}


/*****************************************************************************
 * FUNCTION 
 *  on_receiving
 * DESCRIPTION 
 *  on receiving
 * PARAMETERS 
 *  mmi_email_nwk_context_struct *ctx
 *  srv_email_receiving_data_struct *recv
 * RETURNS 
 *  static void 
*****************************************************************************/
static void on_receiving(mmi_email_nwk_context_struct *ctx, srv_email_receiving_data_struct *recv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_type_enum receive_fldr_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_ON_RECEIVING, 0);
    receive_fldr_type = srv_email_fldr_id_to_fldr_type(ctx->acc_id, recv->fldr_id);

    if (receive_fldr_type != SRV_EMAIL_FLDR_TYPE_INBOX)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_ON_RECEIVING, -1);
        return;
    }

    ctx->recved_total_count = recv->received_num;
    if (recv->new_msg_received && !(recv->new_msg_flag & EMAIL_MSG_FLAG_SEEN))
    {
        ctx->recved_unread_count++;

#ifdef __OP12__
        mmi_email_vf_set_flag(TRUE);
#endif /* __OP12__ */
    }

    if (recv->new_msg_received && recv->received_num == 1)
    {
        mmi_email_util_play_receive_tone();
    }
}


/*****************************************************************************
 * FUNCTION 
 *  on_disconnected
 * DESCRIPTION 
 *  on disconnected
 * PARAMETERS 
 *  mmi_email_nwk_context_struct *ctx
 * RETURNS 
 *  static void 
*****************************************************************************/
static void on_disconnected(mmi_email_nwk_context_struct *ctx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_NETWORK_ON_DISCONNECTED, __LINE__);
    ctx->is_connected = FALSE;

    if (ctx->t == MENWK_T_NULL)
    {
#ifdef __MMI_EMAIL_IMAP_PUSH__
        if (ctx->acc_id == g_push_ctx.acc_id)
        {
            // Retry PUSH
            g_push_ctx.retry_count = 1;
            start_push_retry_timer();
            set_push_icon(PUSH_ICON_FAIL);
        }
#endif /* __MMI_EMAIL_IMAP_PUSH__ */

        // Reset connection
        network_reset(ctx);

        return;
    }

    // Dot care 
    switch(ctx->t)
    {
        // Broken during action
    default:
        break;
    }
}

#endif /* __MMI_EMAIL__ */

