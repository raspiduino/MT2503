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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_EMAIL__


#if (defined(__XML_SUPPORT__) && defined(__WBXML_SUPPORT__))
#ifndef __MMI_EMAIL_EMN__
#define __MMI_EMAIL_EMN__
#endif /* __MMI_EMAIL_EMN__ */
#endif /* (defined(__XML_SUPPORT__) && defined(__WBXML_SUPPORT__)) */


#include "MMIDataType.h"

#include "Mmi_frm_mem_gprot.h"

#include "cbm_consts.h"
#include "cbm_api.h"
#include "USBsrvGprot.h"
#include "USBDeviceGprot.h"

#include "DtcntSrvGprot.h"
#include "DataAccountGProt.h"
#include "NwUsabSrvGprot.h"
#include "wgui_categories_util.h"

#include "NativeAppFactorySrvGprot.h"

#include "MMI_trc_Int.h" // MMI_TRACE
#include "mmi_inet_app_trc.h"
#include "emailsrvgprot.h"
#include "emailappcore.h"

#include "emailappprot.h"

#include "EmailAppLib.h"
#include "EmailAppDtcnt.h"
#include "EmailAppAccountData.h"
#include "EmailAppOperators.h"

#ifdef __MMI_URI_AGENT__
#include "EmailAppURI.h"
#endif /* __MMI_URI_AGENT__ */
#ifdef __MMI_EMAIL_OTAP__
#include "EmailAppOtap.h"
#endif /* __MMI_EMAIL_OTAP__ */

#ifdef __MMI_EMAIL_EMN__
#include "EmailAppEmn.h"
#endif

#include "EmailAppMem.h"
#include "EmailAppAccount.h"
#include "EmailAppNetwork.h"
#include "EmailAppSwitchStorage.h"
#include "EmailAppStateMgr.h"
#include "EmailAppNCenter.h"

/////////////////////////////////////////////////////////////////////////////
typedef enum
{
    MESMGR_S_NULL,
    MESMGR_S_INIT_GOING,
    MESMGR_S_INIT_FAIL,
    MESMGR_S_READY,
    MESMGR_S_PAUSED,

    MESMGR_S_DEINITED
}mmi_email_smgr_state_enum;

typedef enum
{
    MESMGR_ISS_SERVICE,
    MESMGR_ISS_APPCORE,
    MESMGR_ISS_APPLICATION,
    MESMGR_ISS_DONE
}mmi_email_smgr_init_substate_enum;

typedef struct
{
    mmi_email_smgr_state_enum s;
    mmi_email_smgr_init_substate_enum subs;

    FuncPtr cb;
    U16 init_error_string_id;

    S32 omid_acc, omid_fld, omid_msg;
}mmi_email_smgr_context_struct;


/////////////////////////////////////////////////////////////////////////////
static mmi_email_smgr_context_struct g_smgr_ctx;
static mmi_event_struct g_frmevt_temp;
#ifdef __MMI_EMAIL_IMAP_PUSH__
static BOOL g_mmi_first_int = TRUE;
#endif

/////////////////////////////////////////////////////////////////////////////
static mmi_ret post_callback(mmi_event_struct *param);
static void mmi_email_srv_init_done_callback(srv_email_init_state_enum result, S32 err_no, void *user_data);
static void mmi_email_smgr_init_fsm(void);
static void mmi_email_smgr_init_ret(S32 err_no);
static void mmi_email_smgr_init_application(void);

static void mmi_email_smgr_unread_changed_callback(srv_email_all_msg_unread_notify_type type, U32 num, void* userdata);

// OM callback
static void mmi_email_smgr_srvomact_callback(const srv_email_om_notify_struct* data);
static void mmi_email_smgr_srvomfld_callback(const srv_email_om_notify_struct* data);
static void mmi_email_smgr_srvommsg_callback(const srv_email_om_notify_struct* data);

#ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__
// Auto check notify
static void mmi_email_smgr_autocheck_notify(EMAIL_ACCT_ID account_id);
#endif /* __MMI_SLIM_EMAIL_NO_AUTO_CHECK__ */

static void mmi_email_smgr_resume(void);

static BOOL mmi_email_smgr_is_resource_ready(void);


static BOOL email_is_net_avaiable(void);


/////////////////////////////////////////////////////////////////////////////
/* private APIs */
static mmi_ret post_callback(mmi_event_struct *param)
{
    // Convert SYNC CALLBACK to ASYNC event
    mmi_email_smgr_init_fsm();
    return MMI_TRUE;
}



/*****************************************************************************
 * FUNCTION 
 *  mmi_email_smgr_init_fsm
 * DESCRIPTION 
 *  mmi email smgr init fsm
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void mmi_email_smgr_init_fsm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_INIT_FSM, g_smgr_ctx.s);

    if (g_smgr_ctx.s != MESMGR_S_INIT_GOING)
    {
        return;
    }

    switch (g_smgr_ctx.subs)
    {
    case MESMGR_ISS_SERVICE:
        srv_email_app_init_set_callback(mmi_email_srv_init_done_callback, &g_smgr_ctx);
        srv_email_init();
        break;

    case MESMGR_ISS_APPCORE:
        mmi_email_app_core_init();

#ifdef __MMI_EMAIL_IMAP_PUSH__
        mmi_email_imap_push_set_status(TRUE);
#endif /* __MMI_EMAIL_IMAP_PUSH__ */

        g_smgr_ctx.subs = MESMGR_ISS_APPLICATION;
        mmi_frm_post_event(&g_frmevt_temp, post_callback, NULL);
        break;

    case MESMGR_ISS_APPLICATION:
        mmi_email_smgr_init_application();
        break;

    case MESMGR_ISS_DONE:
        mmi_email_smgr_init_ret(g_smgr_ctx.init_error_string_id);
        break;

    default:
        ASSERT(0);
        break;
    }
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_smgr_init_ret
 * DESCRIPTION 
 *  mmi email smgr init ret
 * PARAMETERS 
 *  S32 err_no
 * RETURNS 
 *  static void 
*****************************************************************************/
static void mmi_email_smgr_init_ret(S32 err_no)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_INIT_RET, err_no);

    if (err_no == 0)
    {
#ifdef __MMI_EMAIL_EMN__
        mmi_email_emn_init();
#endif /* __MMI_EMAIL_EMN__ */

        g_smgr_ctx.s = MESMGR_S_PAUSED;
        mmi_email_smgr_resume();
    }
    else
    {
        g_smgr_ctx.s = MESMGR_S_INIT_FAIL;
    }

    if (g_smgr_ctx.cb != NULL)
    {
        g_smgr_ctx.cb();
        g_smgr_ctx.cb = NULL;
    }
#ifdef __MMI_EMAIL_IMAP_PUSH__
    g_mmi_first_int = FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_srv_init_done_callback
 * DESCRIPTION 
 *  mmi email srv init done callback
 * PARAMETERS 
 *  srv_email_init_state_enum result
 *  S32 err_no
 *  void *user_data
 * RETURNS 
 *  static void 
*****************************************************************************/
static void mmi_email_srv_init_done_callback(srv_email_init_state_enum result, S32 err_no, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SRV_INIT_DONE_CALLBACK, 0);

    if (g_smgr_ctx.s != MESMGR_S_INIT_GOING 
        || g_smgr_ctx.subs != MESMGR_ISS_SERVICE)
    {
        /* skip this notify */
        // TRACE here
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SRV_INIT_DONE_CALLBACK, -100);
        return;
    }

    if (result == SRV_EMAIL_INIT_STATE_READY)
    {
        // Ready to next sub state
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SRV_INIT_DONE_CALLBACK, 200);
        g_smgr_ctx.subs = MESMGR_ISS_APPCORE;
    }
    else
    {
        // Error
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SRV_INIT_DONE_CALLBACK, err_no);

        if (err_no == SRV_EMAIL_RESULT_FS_ERROR ||
            err_no == SRV_EMAIL_FS_ERROR)
        {
            g_smgr_ctx.init_error_string_id = 
                srv_fmgr_fs_error_get_string(srv_email_errno_get());
        }
        else
        {
            g_smgr_ctx.init_error_string_id = 
                mmi_email_util_get_error_string_id(err_no);
        }
        g_smgr_ctx.subs = MESMGR_ISS_DONE;
    }

    mmi_frm_post_event(&g_frmevt_temp, post_callback, NULL);
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_smgr_init_application
 * DESCRIPTION 
 *  mmi email smgr init application
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void mmi_email_smgr_init_application(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_INIT_APPLICATION, __LINE__);

    // Email account init
    mmi_email_account_list_init();

    /* Sync account information between SERVICE / APPCORE / APPMMI */
    mmi_email_account_list_init_wait_service_ready();

    // Data account init
    mmi_email_dataaccount_init();

    // Account data init
    email_mmi_account_data_init();

#ifdef __MMI_URI_AGENT__
    /* Init URI handler */
    mmi_email_uri_init();
#endif /* __MMI_URI_AGENT__ */

#ifdef __MMI_EMAIL_OTAP__ 
    mmi_email_otap_init();
#endif /* __MMI_EMAIL_OTAP__ */

    // Not only for EMN, also for AUTOCHECK / IDLE PUSH
    mmi_email_emn_set_new_emn_notify_flag(MMI_FALSE);

    // Create temp folder
    mmi_email_lib_create_copy_file_dir();

    /* init system bar ICON (UNREAD EMAIL ICON) */
    srv_email_acct_cache_notify_set(mmi_email_smgr_unread_changed_callback, NULL);

    /* for IDLE EMAIL NGMR list */
    mmi_email_batch_receive_init();

    /* Register OM callback */
    srv_email_om_set_notify(SRV_EMAIL_OM_NOTIFY_OBJ_ACCT, mmi_email_smgr_srvomact_callback, &g_smgr_ctx.omid_acc);
    srv_email_om_set_notify(SRV_EMAIL_OM_NOTIFY_OBJ_FLDR, mmi_email_smgr_srvomfld_callback, &g_smgr_ctx.omid_fld);
    srv_email_om_set_notify(SRV_EMAIL_OM_NOTIFY_OBJ_MSG, mmi_email_smgr_srvommsg_callback, &g_smgr_ctx.omid_msg);

    // Done
    g_smgr_ctx.subs = MESMGR_ISS_DONE;
    g_smgr_ctx.init_error_string_id = 0;
    mmi_frm_post_event(&g_frmevt_temp, post_callback, NULL);
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_smgr_unread_changed_callback
 * DESCRIPTION 
 *  mmi email smgr unread changed callback
 * PARAMETERS 
 *  srv_email_all_msg_unread_notify_type type
 *  U32 num
 *  void* userdata
 * RETURNS 
 *  static void 
*****************************************************************************/
static void mmi_email_smgr_unread_changed_callback(srv_email_all_msg_unread_notify_type type, U32 num, void* userdata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_UNREAD_CHANGED_CALLBACK, __LINE__);

    if (mmi_email_smgr_could_show_icon() &&
       type == SRV_EMAIL_ALL_MSG_UNREAD_NONE_TO_SOME)
    {
        wgui_status_icon_bar_show_icon(STATUS_ICON_UNREAD_EMAIL);
    }
    else if (type == SRV_EMAIL_ALL_MSG_UNREAD_SOME_TO_NONE)
    {
        wgui_status_icon_bar_hide_icon(STATUS_ICON_UNREAD_EMAIL);
#ifdef __OP12__
        mmi_email_vf_set_flag(FALSE);
#endif /* __OP12__ */
    }
#ifdef __MMI_OP12_TOOLBAR__
    mmi_email_tb_update_info();
#endif /* __MMI_OP12_TOOLBAR__ */
#ifdef __MMI_APP_MANAGER_SUPPORT__
    srv_appmgr_update_app_info("native.mtk.email", EVT_ID_SRV_APPMGR_UPDATE_BADGE);
#endif
}


/////////////////////////////////////////////////////////////////////////////
/* public APIs */

/*****************************************************************************
 * FUNCTION 
 *  mmi_email_smgr_first_init
 * DESCRIPTION 
 *  mmi email smgr first init
 * PARAMETERS 
 *  void
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_smgr_first_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_FIRST_INIT, __LINE__);

    g_smgr_ctx.s = MESMGR_S_NULL;
    g_frmevt_temp.evt_id = 0;
    g_frmevt_temp.size = sizeof(g_frmevt_temp);
    g_frmevt_temp.user_data = NULL;

    mmi_email_app_mem_init();
    mmi_email_smgr_init(NULL);
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_smgr_init
 * DESCRIPTION 
 *  mmi email smgr init
 * PARAMETERS 
 *  FuncPtr cb
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_smgr_init(FuncPtr cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_smgr_state_enum s;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_INIT, __LINE__);
    s = g_smgr_ctx.s;

    g_smgr_ctx.s = MESMGR_S_INIT_GOING;
    g_smgr_ctx.cb = cb;
    g_smgr_ctx.init_error_string_id = 0;

    // Wait for service init done.
    if (s == MESMGR_S_NULL)
    {
        if (srv_email_get_srv_init_state() == SRV_EMAIL_INIT_STATE_READY)
        {
            g_smgr_ctx.subs = MESMGR_ISS_APPCORE;
            mmi_email_smgr_init_fsm();
        }
        else
        {
            // Waiting for SERVICE ready
            g_smgr_ctx.subs = MESMGR_ISS_SERVICE;
            srv_email_app_init_set_callback(mmi_email_srv_init_done_callback, &g_smgr_ctx);
        }
    }
    else
    {
        // init service
        g_smgr_ctx.subs = MESMGR_ISS_SERVICE;
        mmi_email_smgr_init_fsm();
    }
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_smgr_get_init_result
 * DESCRIPTION 
 *  mmi email smgr get init result
 * PARAMETERS 
 *  void
 * RETURNS 
 *  U16 
*****************************************************************************/
U16 mmi_email_smgr_get_init_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_GET_INIT_RESULT, __LINE__);

    ASSERT(g_smgr_ctx.s == MESMGR_S_READY 
        ||g_smgr_ctx.s == MESMGR_S_INIT_FAIL);

    if (g_smgr_ctx.s == MESMGR_S_INIT_FAIL)
    {
        return g_smgr_ctx.init_error_string_id;
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION 
 *  reset_email
 * DESCRIPTION 
 *  reset email
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void reset_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_RESET_EMAIL, __LINE__);

    if (g_smgr_ctx.s != MESMGR_S_READY)
    {
        return;
    }

#ifdef __MMI_EMAIL_OTAP__
    // close OTAP screen
    mmi_email_otap_deinit();
#endif /* __MMI_EMAIL_OTAP__ */

    // Close native screen
    mmi_email_reset_curr_comp_info();
    mmi_email_reset_curr_fldr_info();
    mmi_email_reset_curr_read_info();

    mmi_email_app_network_reset();
    email_mmi_account_data_reset_status();

    if (mmi_email_get_main_group_id() != 0)
    {
        mmi_frm_group_close(mmi_email_get_main_group_id());
    }

    mmi_email_close_nmgr_screen();

#ifdef __MMI_NCENTER_SUPPORT__
    mmi_email_ncenter_deinit();
#endif /* __MMI_NCENTER_SUPPORT__ */

#ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__
    mmi_email_auto_check_stop_service();
#endif /* __MMI_SLIM_EMAIL_NO_AUTO_CHECK__ */

#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    mmi_email_hs_reset_sidebar_icon();
#endif /* defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */

#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
        mmi_email_close_hs_screen();
#endif

#ifdef __OP12__
    mmi_email_vf_set_flag(FALSE);
#endif /* __OP12__ */

#ifdef __MMI_OP12_TOOLBAR__
    mmi_email_tb_update_info();
#endif /* __MMI_OP12_TOOLBAR__ */

    wgui_status_icon_bar_hide_icon(STATUS_ICON_UNREAD_EMAIL);

    g_smgr_ctx.s = MESMGR_S_PAUSED;
}


static void mmi_email_smgr_resume(void)
{
    if (g_smgr_ctx.s != MESMGR_S_PAUSED)
    {
        return;
    }

    if (!mmi_email_smgr_is_resource_ready())
    {
        return;
    }

#ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__
    // Restart AUTO-CHECK
    mmi_email_auto_check_start_service(mmi_email_smgr_autocheck_notify);
#endif /* __MMI_SLIM_EMAIL_NO_AUTO_CHECK__ */

#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    mmi_email_hs_init_acct_info();
#endif /* defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */

    // Show Status ICON
    if (mmi_email_lib_get_total_unread_number() > 0)
    {
        wgui_status_icon_bar_show_icon(STATUS_ICON_UNREAD_EMAIL);
    }

    g_smgr_ctx.s = MESMGR_S_READY;

    mmi_email_batch_receive_init();

#ifdef __MMI_EMAIL_IMAP_PUSH__
    // Restart PUSH
    mmi_email_app_network_push_start(mmi_email_lib_get_push_account(), g_mmi_first_int);
#endif /* __MMI_EMAIL_IMAP_PUSH__ */
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_smgr_deinit
 * DESCRIPTION 
 *
 * PARAMETERS 
 *  void
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_smgr_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_DEINIT, __LINE__);

    reset_email();
    g_smgr_ctx.s = MESMGR_S_DEINITED;
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_smgr_usb_on
 * DESCRIPTION 
 *  mmi email smgr usb on
 * PARAMETERS 
 *  void
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_smgr_usb_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_USB_ON, __LINE__);
    mmi_email_smgr_deinit();
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_smgr_usb_off
 * DESCRIPTION 
 *  mmi email smgr usb off
 * PARAMETERS 
 *  void
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_smgr_usb_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_USB_OFF, __LINE__);

    switch(g_smgr_ctx.s)
    {
    case MESMGR_S_DEINITED:
    case MESMGR_S_INIT_FAIL:
    case MESMGR_S_PAUSED:
        mmi_email_smgr_init(NULL);
        break;

    default:
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_USB_OFF, -1);
        break;
    }
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_smgr_tcard_in
 * DESCRIPTION 
 *  mmi email smgr tcard in
 * PARAMETERS 
 *  CHAR driver
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_smgr_tcard_in(CHAR driver)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_TCARD_IN, driver);

    if (srv_email_get_drive() != driver)
    {
        return;
    }

    mmi_email_smgr_init(NULL);
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_smgr_tcard_out
 * DESCRIPTION 
 *  mmi email smgr tcard out
 * PARAMETERS 
 *  CHAR driver
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_smgr_tcard_out(CHAR driver)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_TCARD_OUT, __LINE__);
    if (srv_email_get_drive() != driver)
    {
        return;
    }

    reset_email();
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_smgr_network_notify
 * DESCRIPTION 
 *
 * PARAMETERS 
 *  void
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_smgr_network_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_NETWORK_NOTIFY, 0);

    if (email_is_net_avaiable())
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_NETWORK_NOTIFY, 1);
        mmi_email_smgr_resume();
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_NETWORK_NOTIFY, 6);
        reset_email();
    }
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_smgr_fmgr_formate
 * DESCRIPTION 
 *  
 * PARAMETERS 
 *  CHAR driver
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_smgr_fmgr_formate(CHAR driver)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_FMGR_FORMATE, driver);

    if (srv_email_get_drive() != driver)
    {
        return;
    }

    // Init again
    reset_email();
    mmi_email_smgr_init(NULL);
}


// Auto check notify
#ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__
/*****************************************************************************
 * FUNCTION 
 *  mmi_email_smgr_autocheck_notify
 * DESCRIPTION 
 *  mmi email smgr autocheck notify
 * PARAMETERS 
 *  EMAIL_ACCT_ID acc_id
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_smgr_autocheck_notify(EMAIL_ACCT_ID acc_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_AUTOCHECK_NOTIFY, acc_id);
    if (!mmi_email_smgr_network_check())
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_AUTOCHECK_NOTIFY, -100);
        return;
    }
    mmi_email_app_nwk_autocheck_do(acc_id);
}
#endif /* __MMI_SLIM_EMAIL_NO_AUTO_CHECK__ */


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_smgr_account_add
 * DESCRIPTION 
 *  mmi email smgr account add
 * PARAMETERS 
 *  EMAIL_ACCT_ID id
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_smgr_account_add(EMAIL_ACCT_ID id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_ACCOUNT_ADD, id);

    mmi_email_dataaccount_map_add(id);
    email_mmi_account_data_add(id);
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_smgr_account_del
 * DESCRIPTION 
 *  mmi email smgr account del
 * PARAMETERS 
 *  EMAIL_ACCT_ID id
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_smgr_account_del(EMAIL_ACCT_ID id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_ACCOUNT_DEL, id);

    mmi_email_app_nwk_delaccount(id);
    mmi_email_dataaccount_map_del(id);
    email_mmi_account_data_del(id);
    mmi_email_batch_receive_remove(id);

#ifdef __MMI_NCENTER_SUPPORT__
    mmi_email_ncenter_delaccount(id);
#endif /* __MMI_NCENTER_SUPPORT__ */
}





/*****************************************************************************
 * FUNCTION 
 *  mmi_email_smgr_is_resource_ready
 * DESCRIPTION 
 *  mmi email smgr is resource ready
 * PARAMETERS 
 *  void
 * RETURNS 
 *  BOOL 
*****************************************************************************/
static BOOL mmi_email_smgr_is_resource_ready(void)
{
    if (!email_is_net_avaiable())
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_NETWORK_CHECK, -501);
        return FALSE;
    }

    if (mmi_email_lib_is_phone_locked())
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_NETWORK_CHECK, -502);
        return FALSE;
    }

#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_NETWORK_CHECK, -504);
        return FALSE;
    }
#endif /* __USB_IN_NORMAL_MODE__ */

    if (!mmi_email_switch_storage_check(NULL, FALSE))
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_NETWORK_CHECK, -505);
        return FALSE;
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_NETWORK_CHECK, 599);
    return TRUE;
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_smgr_network_check
 * DESCRIPTION 
 *  mmi email smgr network check
 * PARAMETERS 
 *  void
 * RETURNS 
 *  BOOL 
*****************************************************************************/
BOOL mmi_email_smgr_network_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_NETWORK_CHECK, g_smgr_ctx.s);
    return (g_smgr_ctx.s == MESMGR_S_READY);
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_smgr_could_show_icon
 * DESCRIPTION 
 *  mmi email smgr could show icon
 * PARAMETERS 
 *  void
 * RETURNS 
 *  BOOL 
*****************************************************************************/
BOOL mmi_email_smgr_could_show_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_COULD_SHOW_ICON, g_smgr_ctx.s);
    return (g_smgr_ctx.s == MESMGR_S_READY);
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_smgr_could_show_ui
 * DESCRIPTION 
 *  mmi email smgr could show ui
 * PARAMETERS 
 *  void
 * RETURNS 
 *  BOOL 
*****************************************************************************/
BOOL mmi_email_smgr_could_show_ui(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!email_is_net_avaiable())
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_COULD_SHOW_UI, -10);
        return FALSE;
    }

    if (mmi_email_lib_is_phone_locked())
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_COULD_SHOW_UI, -100);
        return FALSE;
    }

    if (mmi_email_lib_is_call_interrupt())
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_COULD_SHOW_UI, -200);
        return FALSE;
    }

#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_COULD_SHOW_UI, -300);
        return FALSE;
    }
#endif /* __USB_IN_NORMAL_MODE__ */

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_COULD_SHOW_UI, 400);
    return TRUE;
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_smgr_show_ui_check
 * DESCRIPTION 
 *  mmi email smgr show ui check
 * PARAMETERS 
 *  void
 * RETURNS 
 *  BOOL 
*****************************************************************************/
BOOL mmi_email_smgr_show_ui_check(FuncPtr switch_storage_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_email_lib_is_phone_locked())
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_SHOW_UI_CHECK, -100);
        return FALSE;
    }

    if (mmi_email_lib_is_call_interrupt())
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_SHOW_UI_CHECK, -200);
        return FALSE;
    }

    if (!email_is_net_avaiable())
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_SHOW_UI_CHECK, -400);
        mmi_email_lib_error_popup(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE);
        return FALSE;
    }

#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_SHOW_UI_CHECK, -500);
        mmi_usb_app_unavailable_popup(0);
        return FALSE;
    }
#endif /* __USB_IN_NORMAL_MODE__ */

    if (!mmi_email_switch_storage_check(switch_storage_cb, TRUE))
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_SHOW_UI_CHECK, -600);
        return FALSE;
    }

    switch (g_smgr_ctx.s)
    {
    case MESMGR_S_READY:
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_SHOW_UI_CHECK, 1000);
        return TRUE;

    case MESMGR_S_INIT_FAIL:
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_SHOW_UI_CHECK, -700);
        /*Promote to switch storage ?*/
        mmi_email_util_display_popup_ext(
            0,
            NULL,
            (WCHAR*)get_string(g_smgr_ctx.init_error_string_id),
            MMI_EVENT_FAILURE);
        return FALSE;

    default:
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_SHOW_UI_CHECK, -800);
        mmi_email_lib_error_popup(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE);
        return FALSE;
    }
}








/*****************************************************************************
 * FUNCTION 
 *  mmi_email_smgr_srvomact_callback
 * DESCRIPTION 
 *  mmi email smgr srvomact callback
 * PARAMETERS 
 *  const srv_email_om_notify_struct* data
 * RETURNS 
 *  static void 
*****************************************************************************/
static void mmi_email_smgr_srvomact_callback(const srv_email_om_notify_struct* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_om_notify_acct_struct *acc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_SRVOMACT_CALLBACK, 0);
    if (data->notify_type != SRV_EMAIL_OM_NOTIFY_ACCT_MSG_NUM_CHG)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_SRVOMACT_CALLBACK, -100);
        return;
    }

    acc = (srv_email_om_notify_acct_struct*)data->data;
    email_mmi_account_data_update_inbox_number(acc->acct_id, acc->msg_unread_num, acc->msg_total_num);

    mmi_email_ui_refresh_mainmenu();
    mmi_email_ui_refresh_account(acc->acct_id);
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_smgr_srvomfld_callback
 * DESCRIPTION 
 *  mmi email smgr srvomfld callback
 * PARAMETERS 
 *  const srv_email_om_notify_struct* data
 * RETURNS 
 *  static void 
*****************************************************************************/
static void mmi_email_smgr_srvomfld_callback(const srv_email_om_notify_struct* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_om_notify_fldr_struct *fld;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_SRVOMFLD_CALLBACK, __LINE__);

    if (data->notify_type != SRV_EMAIL_OM_NOTIFY_FLDR_MSG_NUM_CHG)
    {
        return;
    }

    fld = (srv_email_om_notify_fldr_struct*)data->data;

    mmi_email_ui_refresh_account(fld->acct_id);
    mmi_email_ui_refresh_folder(fld->acct_id, fld->fldr_id);
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_smgr_srvommsg_callback
 * DESCRIPTION 
 *  mmi email smgr srvommsg callback
 * PARAMETERS 
 *  const srv_email_om_notify_struct* data
 * RETURNS 
 *  static void 
*****************************************************************************/
static void mmi_email_smgr_srvommsg_callback(const srv_email_om_notify_struct* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_om_notify_msg_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SMGR_SRVOMMSG_CALLBACK, __LINE__);

    msg = (srv_email_om_notify_msg_struct*)data->data;
    if (data->notify_type == SRV_EMAIL_OM_NOTIFY_MSG_UPDATE)
    {
        mmi_email_ui_refresh_folder(
            srv_email_msg_id_to_acct_id(msg->msg_id), 
            srv_email_msg_id_to_fldr_id(msg->msg_id));
    }

    if (data->notify_type == SRV_EMAIL_OM_NOTIFY_MSG_DEL)
    {
        mmi_email_msg_del_callback(msg->msg_id);
    }
}


static BOOL email_is_net_avaiable(void)
{
    BOOL ret = FALSE;
    if (srv_nw_usab_is_any_network_available())
    {
        ret = TRUE;
    }

#ifdef __MMI_WLAN_FEATURES__
    if (srv_dtcnt_wlan_status() != SRV_DTCNT_WLAN_STATUS_INACTIVE)
    {
        ret = TRUE;
    }
#endif /* __MMI_WLAN_FEATURES__ */

    return ret;
}

#endif /* __MMI_EMAIL__ */
