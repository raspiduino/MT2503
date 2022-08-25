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
 *  EmailAppMRE.c
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"

#ifdef __MMI_EMAIL__

#ifdef __DRM_SUPPORT__
#include "Drm_gprot.h"
#include "RightsMgrGProt.h"
#endif /* __DRM_SUPPORT__ */

#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif

#include "app_mine.h"
#include "conversions.h"
#include "filemgrsrvgprot.h"
#include "emailsrvgprot.h"
#include "EmailAppGProt.h"
#include "EmailAppProt.h"
#include "mmi_inet_app_trc.h"
#include "EmailAppStateMgr.h"
#include "EmailAppLib.h"

typedef enum
{
    MRE_FSM_STATE_NULL,
    MRE_FSM_STATE_INIT,
    MRE_FSM_STATE_COMPOSE_INT,
    MRE_FSM_STATE_SIGNATURE_INIT,
    MRE_FSM_STATE_COMPOSE_BASIC,
    MRE_FSM_STATE_COMPOSE_ATTA_COPY,
    MRE_FSM_STATE_COMPOSE_SAVE,
    MRE_FSM_STATE_DONE,
}mre_fsm_state_enum;

/////////////////////////////////////////////////////////////////////////////////
typedef struct
{
    U32 fsm_state;

    EMAIL_ACCT_ID acct_id;
    EMAIL_ACCT_HANDLE acct_handle;

    EMAIL_FLDR_ID fld_id;

    EMAIL_MSG_ID msg_id;
    EMAIL_MSG_HANDLE msg_handle;

    EMAIL_REQ_ID req_id;

    S32 user_id;
    mmi_email_app_mre_send_param_struct *para;
    void *user_data;
    mmi_email_app_mre_send_result_callback cb;
    MMI_BOOL is_save_to_sent;

    S32 attach_file_num;
    S32 att_copy_idx;
    S32 att_total_size;

    S32 fs_async_id;
}mmi_email_mre_cntx_struct;

/////////////////////////////////////////////////////////////////////////////////
static mmi_email_mre_cntx_struct g_mre_cntx;

static S32 g_mre_req_id;

/////////////////////////////////////////////////////////////////////////////////
static
mmi_email_app_mre_send_error_code_enum
mmi_email_mre_init_signature(void);

static
mmi_email_app_mre_send_error_code_enum
mmi_email_mre_compose_basic(void);

static
mmi_email_app_mre_send_error_code_enum
mmi_email_app_mre_open_default_account(void);

static
mmi_email_app_mre_send_error_code_enum
mmi_email_app_mre_get_outbox_id(void);

static
mmi_email_app_mre_send_error_code_enum
mmi_email_app_mre_set_sender(mmi_email_app_mre_send_param_struct *para);

static
mmi_email_app_mre_send_error_code_enum
mmi_email_app_mre_set_recipient(mmi_email_app_mre_send_param_struct *para);

static
void 
mmi_email_app_mre_copy_addr(
    srv_email_addr_struct *srv_addr,
    mmi_email_app_send_addr_struct *mmi_addr);

static
mmi_email_app_mre_send_error_code_enum
mmi_email_app_mre_att_copy(void);

static mmi_ret mmi_email_app_mre_att_async_copy_callback(mmi_event_struct *param);

static
mmi_email_app_mre_send_error_code_enum
mmi_email_app_mre_save(void);

static 
void 
mmi_email_app_mre_save_callback(
    srv_email_result_struct *result,
    EMAIL_REQ_ID req_id,
    void *user_data);

static
mmi_email_app_mre_send_error_code_enum
mmi_email_app_mre_fsm(void);

static void mmi_email_app_mre_cleanup(void);

static void mmi_email_app_mre_response(mmi_email_app_mre_send_error_code_enum ret);
static void mmi_email_app_mre_copy_para(mmi_email_app_mre_send_param_struct *para);

/////////////////////////////////////////////////////////////////////////////////

/*****************************************************************************
 * FUNCTION 
 *  mmi_email_is_mre_busy
 * DESCRIPTION 
 *  mmi email is mre busy
 * PARAMETERS 
 *  void
 * RETURNS 
 *  BOOL 
*****************************************************************************/
BOOL mmi_email_is_mre_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, 
        EMAILAPP_FUNC_MMI_EMAIL_IS_MRE_BUSY, 
        (g_mre_cntx.fsm_state != MRE_FSM_STATE_NULL));
    return (g_mre_cntx.fsm_state != MRE_FSM_STATE_NULL);
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_mre_send_error_code_enum  mmi_email_app_mre_check_para
 * DESCRIPTION 
 *  mmi email app mre send error code enum  mmi email app mre check para
 * PARAMETERS 
 *  mmi_email_app_mre_send_param_struct *para
 * RETURNS 
 *  static mmi_email_app_mre_send_error_code_enum  
*****************************************************************************/
static 
mmi_email_app_mre_send_error_code_enum 
mmi_email_app_mre_check_para(mmi_email_app_mre_send_param_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_CHECK_PARA, __LINE__);
    if (para == NULL)
    {
        return MMI_EMAIL_APP_MRE_ERROR_CODE_INVLAID_PARAM;
    }

    if (para->to_num + para->cc_num + para->bcc_num == 0)
    {
        return MMI_EMAIL_APP_MRE_ERROR_CODE_NO_RECIPIENT;
    }

    if (para->to_num + para->cc_num + para->bcc_num > MMI_EMAIL_MAX_ADDR_NUM)
    {
        return MMI_EMAIL_APP_MRE_ERROR_CODE_INVLAID_PARAM;
    }

    if (para->attach_file_num > MMI_EMAIL_MAX_ATTACH_NUMBER)
    {
        return MMI_EMAIL_APP_MRE_ERROR_CODE_INVLAID_PARAM;
    }

    if (para->attach_file_num > 0 && para->attch_file_list == NULL)
    {
        return MMI_EMAIL_APP_MRE_ERROR_CODE_INVLAID_PARAM;
    }

    return MMI_EMAIL_APP_MRE_ERROR_CODE_SUCCESS;
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_mre_copy_para
 * DESCRIPTION 
 *  mmi email app mre copy para
 * PARAMETERS 
 *  mmi_email_app_mre_send_param_struct *para
 * RETURNS 
 *  static void 
*****************************************************************************/
static void mmi_email_app_mre_copy_para(mmi_email_app_mre_send_param_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    srv_email_attach_struct *comp_att_list;
    WCHAR *content;
    S32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_COPY_PARA, __LINE__);

    comp_att_list = mmi_email_comp_get_attlist();
    for (i = 0; i < para->attach_file_num; i++)
    {
        memset(&comp_att_list[i], 0, sizeof(srv_email_attach_struct));
        mmi_wcsncpy(comp_att_list[i].path, para->attch_file_list[i], SRV_EMAIL_MAX_FILE_NAME_LEN);
        comp_att_list[i].path[SRV_EMAIL_MAX_FILE_NAME_LEN] = 0;
    }
    g_mre_cntx.attach_file_num = para->attach_file_num;
    g_mre_cntx.para = para;

    /* Copy content */
    content = mmi_email_comp_get_content_buffer();
    content[0] = 0;

    len = 0;
    if (para->content != NULL)
    {
        len = mmi_wcslen(para->content);
        if (len > MMI_EMAIL_MAX_CONT_LEN)
        {
            len = MMI_EMAIL_MAX_CONT_LEN;
        }
        mmi_wcsncpy(content, para->content, len);
        content[len] = 0;
    }
}

/* MRE Background send */

/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_mre_send
 * DESCRIPTION 
 *  mmi email app mre send
 * PARAMETERS 
 *       mmi_email_app_mre_send_param_struct *para
 *  mmi_email_app_mre_send_result_callback cb
 *  void* user_data
 *  S32* req_id
 * RETURNS 
 *  mmi_email_app_mre_send_error_code_enum  
*****************************************************************************/
mmi_email_app_mre_send_error_code_enum 
mmi_email_app_mre_send(
    mmi_email_app_mre_send_param_struct *para, 
    mmi_email_app_mre_send_result_callback cb, 
    void* user_data,
    S32* req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_app_mre_send_error_code_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_SEND, 0);

    /* Check parameter */
    ret = mmi_email_app_mre_check_para(para);
    if (ret != MMI_EMAIL_APP_MRE_ERROR_CODE_SUCCESS)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_SEND, 1);
        return MMI_EMAIL_APP_MRE_ERROR_CODE_INVLAID_PARAM;
    }

    /* Check if allowed */
    if (!mmi_email_smgr_network_check())
    {
        return MMI_EMAIL_APP_MRE_ERROR_CODE_EMAIL_NOT_AVAIABLE;
    }

    memset(&g_mre_cntx, 0, sizeof(mmi_email_mre_cntx_struct));
    mmi_email_app_mre_copy_para(para);
    g_mre_cntx.fsm_state = MRE_FSM_STATE_INIT;

    ret = mmi_email_app_mre_fsm();

    if (ret != MMI_EMAIL_APP_MRE_ERROR_CODE_WOULDBLOCK &&
        ret != MMI_EMAIL_APP_MRE_ERROR_CODE_SUCCESS)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_SEND, ret);
        mmi_email_app_mre_cleanup();
        return ret;
    }

    if (ret == MMI_EMAIL_APP_MRE_ERROR_CODE_WOULDBLOCK)
    {
        g_mre_req_id++;
        g_mre_cntx.user_id = *req_id = g_mre_req_id;
        g_mre_cntx.cb = cb;
        g_mre_cntx.user_data = user_data;
        g_mre_cntx.is_save_to_sent = para->is_save_to_sent;
        return ret;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_mre_fsm
 * DESCRIPTION 
 *  mmi email app mre fsm
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static mmi_email_app_mre_send_error_code_enum 
*****************************************************************************/
static
mmi_email_app_mre_send_error_code_enum
mmi_email_app_mre_fsm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_app_mre_send_error_code_enum ret = MMI_EMAIL_APP_MRE_ERROR_CODE_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (1)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_FSM, g_mre_cntx.fsm_state);

        switch (g_mre_cntx.fsm_state)
        {
        case MRE_FSM_STATE_INIT:
            ret = mmi_email_app_mre_open_default_account();
            break;

        case MRE_FSM_STATE_COMPOSE_INT:
            ret =mmi_email_app_mre_get_outbox_id();
            break;

        case MRE_FSM_STATE_SIGNATURE_INIT:
            ret = mmi_email_mre_init_signature();
            break;

        case MRE_FSM_STATE_COMPOSE_BASIC:
            ret = mmi_email_mre_compose_basic();
            break;

        case MRE_FSM_STATE_COMPOSE_ATTA_COPY:
            ret = mmi_email_app_mre_att_copy();
            break;

        case MRE_FSM_STATE_COMPOSE_SAVE:
            ret = mmi_email_app_mre_save();
            break;

        case MRE_FSM_STATE_DONE:
            mmi_email_app_mre_response(MMI_EMAIL_APP_MRE_ERROR_CODE_SUCCESS);
            return MMI_EMAIL_APP_MRE_ERROR_CODE_SUCCESS;

        default:
            ASSERT(0);
            break;
        }

        if (ret == MMI_EMAIL_APP_MRE_ERROR_CODE_SUCCESS)
        {
            g_mre_cntx.fsm_state++;
        }
        else
        {
            return ret;
        }
    }
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_mre_cleanup
 * DESCRIPTION 
 *  mmi email app mre cleanup
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void mmi_email_app_mre_cleanup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_CLEANUP, __LINE__);

    if (g_mre_cntx.fsm_state == MRE_FSM_STATE_NULL)
    {
        return;
    }

    switch (g_mre_cntx.fsm_state)
    {
    case MRE_FSM_STATE_COMPOSE_SAVE:
        /* abort save */
        if (g_mre_cntx.msg_handle != EMAIL_MSG_INVALID_HANDLE)
        {
            srv_email_msg_abort(g_mre_cntx.msg_handle, g_mre_cntx.req_id);
            g_mre_cntx.req_id = EMAIL_REQ_INVALID_ID;
            srv_email_msg_clear_callback(g_mre_cntx.msg_handle);
        }
        break;

    case MRE_FSM_STATE_COMPOSE_ATTA_COPY:
        /* abort copy */
        if (g_mre_cntx.fs_async_id > 0)
        {
            srv_fmgr_async_abort(g_mre_cntx.fs_async_id, MMI_TRUE);
            g_mre_cntx.fs_async_id = 0;
        }
        break;

    default:
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_SEND_ABORT, __LINE__);
        break;
    }

    if (g_mre_cntx.msg_handle != EMAIL_MSG_INVALID_HANDLE)
    {
        srv_email_msg_destroy(g_mre_cntx.msg_handle);
        g_mre_cntx.msg_handle = EMAIL_MSG_INVALID_HANDLE;
    }

    if (g_mre_cntx.acct_handle != EMAIL_ACCT_INVALID_HANDLE)
    {
        srv_email_acct_destroy(g_mre_cntx.acct_handle);
        g_mre_cntx.acct_handle = EMAIL_ACCT_INVALID_HANDLE;
    }

    g_mre_cntx.fsm_state = MRE_FSM_STATE_NULL;
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_mre_send_abort_interal
 * DESCRIPTION 
 *  mmi email app mre send abort interal
 * PARAMETERS 
 * RETURNS 
 *  MMI_BOOL 
*****************************************************************************/
void mmi_email_app_mre_send_abort_interal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mre_cntx.fsm_state == MRE_FSM_STATE_NULL)
    {
        return;
    }

    mmi_email_app_mre_response(MMI_EMAIL_APP_MRE_ERROR_CODE_EMAIL_BUSY);
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_mre_send_abort
 * DESCRIPTION 
 *  mmi email app mre send abort
 * PARAMETERS 
 *  S32 req_id
 * RETURNS 
 *  MMI_BOOL 
*****************************************************************************/
MMI_BOOL mmi_email_app_mre_send_abort(S32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_SEND_ABORT, req_id);
    if (req_id != g_mre_cntx.user_id)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_SEND_ABORT, 1);
        return MMI_FALSE;
    }

    if (g_mre_cntx.fsm_state == MRE_FSM_STATE_NULL)
    {
        return MMI_FALSE;
    }

    mmi_email_app_mre_send_abort_interal();
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_mre_open_default_account
 * DESCRIPTION 
 *  mmi email app mre open default account
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static mmi_email_app_mre_send_error_code_enum 
*****************************************************************************/
static
mmi_email_app_mre_send_error_code_enum
mmi_email_app_mre_open_default_account(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum result;

    EMAIL_ACCT_ID acct_id;
    EMAIL_ACCT_HANDLE acct_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_OPEN_DEFAULT_ACCOUNT, __LINE__);

    /* Default account ID */
    result = srv_email_acct_get_default(&acct_id);
    if (result != SRV_EMAIL_RESULT_SUCC || acct_id == EMAIL_ACCT_INVALID_ID)
    {
        return MMI_EMAIL_APP_MRE_ERROR_CODE_EMAIL_NOT_READY;
    }
    g_mre_cntx.acct_id = acct_id;

    /* Open account */
    result = srv_email_acct_create(0, &acct_handle);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        return MMI_EMAIL_APP_MRE_ERROR_CODE_EMAIL_NOT_READY;
    }
    g_mre_cntx.acct_handle = acct_handle;

    result = srv_email_acct_open(acct_handle, acct_id);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_acct_destroy(acct_handle);
        return MMI_EMAIL_APP_MRE_ERROR_CODE_EMAIL_NOT_READY;
    }

    return MMI_EMAIL_APP_MRE_ERROR_CODE_SUCCESS;
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_mre_get_outbox_id
 * DESCRIPTION 
 *  mmi email app mre get outbox id
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static mmi_email_app_mre_send_error_code_enum 
*****************************************************************************/
static
mmi_email_app_mre_send_error_code_enum
mmi_email_app_mre_get_outbox_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum result;
    S32 fld_cnt = 4;
    EMAIL_FLDR_ID fld_id[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_GET_OUTBOX_ID, __LINE__);
    ASSERT(g_mre_cntx.acct_handle != EMAIL_ACCT_INVALID_HANDLE);

    result = srv_email_acct_get_fldr_id(g_mre_cntx.acct_handle, 
        SRV_EMAIL_ACCT_FLDR_TYPE_BASIC, 0, &fld_cnt, fld_id);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        return MMI_EMAIL_APP_MRE_ERROR_CODE_EMAIL_NOT_READY;
    }

    g_mre_cntx.fld_id = fld_id[1];
    return MMI_EMAIL_APP_MRE_ERROR_CODE_SUCCESS; 
}

// Util

/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_mre_copy_addr
 * DESCRIPTION 
 *  mmi email app mre copy addr
 * PARAMETERS 
 *  srv_email_addr_struct *srv_addr
 *  mmi_email_app_send_addr_struct *mmi_addr
 * RETURNS 
 *  static void 
*****************************************************************************/
static void mmi_email_app_mre_copy_addr(srv_email_addr_struct *srv_addr,mmi_email_app_send_addr_struct *mmi_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_COPY_ADDR, __LINE__);

    ASSERT(srv_addr != NULL);
    ASSERT(mmi_addr != NULL);

    srv_addr->disp_charset = MMI_CHSET_UCS2;
    srv_addr->disp_name_len = mmi_addr->addr_name == NULL ? 0 : mmi_wcslen((WCHAR*)mmi_addr->addr_name);

    srv_addr->disp_name[0] = 0;
    if (mmi_addr->addr_name != NULL)
    {
        mmi_wcscpy(srv_addr->disp_name, (WCHAR*)mmi_addr->addr_name);
    }

    srv_addr->email_addr[0] = 0;
    if (mmi_addr->addr_mail != NULL)
    {
        mmi_wcscpy(srv_addr->email_addr, (WCHAR*)mmi_addr->addr_mail);
    }
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_mre_init_signature
 * DESCRIPTION 
 *  mmi email mre init signature
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static mmi_email_app_mre_send_error_code_enum 
*****************************************************************************/
static
mmi_email_app_mre_send_error_code_enum
mmi_email_mre_init_signature(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_sig_struct *sig_info;
    mmi_email_app_core_result_enum core_ret;
    srv_email_attach_struct *comp_att_list;
    srv_email_attach_struct *comp_att;
    WCHAR *content;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_MRE_INIT_SIGNATURE, __LINE__);

    sig_info = OslMalloc(sizeof(mmi_email_sig_struct));
    if (sig_info == NULL)
    {
        return MMI_EMAIL_APP_MRE_ERROR_CODE_SUCCESS;
    }

    core_ret = mmi_email_sig_get_signature(g_mre_cntx.acct_id, sig_info);
    if (core_ret == MMI_EMAIL_SUCCESS)
    {
        S32 i, len, total_att;

        /* Copy content */
        content = mmi_email_comp_get_content_buffer();
        len = mmi_wcslen(content);
        if (len + mmi_wcslen(sig_info->text) <= MMI_EMAIL_MAX_CONT_LEN)
        {
            mmi_wcscpy(content + len, sig_info->text);
        }

        /* Copy attachment */
        total_att = g_mre_cntx.attach_file_num;
        comp_att_list = mmi_email_comp_get_attlist();
        for (i = 0; i < sig_info->image_num && total_att < MMI_EMAIL_MAX_ATTACH_NUMBER; i++)
        {
            comp_att = &comp_att_list[total_att];
            memset(comp_att, 0, sizeof(srv_email_attach_struct));

            core_ret = mmi_email_sig_get_image_path(g_mre_cntx.acct_id, i, comp_att->path, SRV_FMGR_PATH_MAX_LEN);
            if (core_ret == MMI_EMAIL_SUCCESS)
            {
                //mmi_wcscpy(comp_att_list[i].path, s);
                total_att++;
            }
        }
        g_mre_cntx.attach_file_num = total_att;
        ASSERT(g_mre_cntx.attach_file_num <= MMI_EMAIL_MAX_ATTACH_NUMBER);
    }
    OslMfree(sig_info);

    return MMI_EMAIL_APP_MRE_ERROR_CODE_SUCCESS;
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_mre_send_error_code_enum mmi_email_mre_compose_basic
 * DESCRIPTION 
 *  mmi email app mre send error code enum mmi email mre compose basic
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static  
*****************************************************************************/
static 
mmi_email_app_mre_send_error_code_enum
mmi_email_mre_compose_basic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_app_mre_send_error_code_enum ret;
    srv_email_result_enum srv_ret;
    EMAIL_MSG_HANDLE msg_handle;
    srv_email_msg_update_basic_info_struct *basic_info;
    mmi_email_app_mre_send_param_struct *para;
    WCHAR *content;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_MRE_COMPOSE_BASIC, __LINE__);

    // Create message handler
    srv_ret = srv_email_msg_create(0, &msg_handle);
    if (srv_ret != SRV_EMAIL_RESULT_SUCC)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_MRE_COMPOSE_BASIC, __LINE__);
        return MMI_EMAIL_APP_MRE_ERROR_CODE_EMAIL_NOT_READY;
    }
    g_mre_cntx.msg_handle = msg_handle;

    // New message
    srv_ret = srv_email_msg_set_new(msg_handle);
    if (srv_ret != SRV_EMAIL_RESULT_SUCC)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_MRE_COMPOSE_BASIC, __LINE__);
        return MMI_EMAIL_APP_MRE_ERROR_CODE_EMAIL_NOT_READY;
    }

    para = g_mre_cntx.para;

    // Update basic info
    basic_info = OslMalloc(sizeof(srv_email_msg_update_basic_info_struct));
    basic_info->acct_id = g_mre_cntx.acct_id;
    basic_info->fldr_id = g_mre_cntx.fld_id;
    basic_info->priority = para->priority;
    basic_info->flag = EMAIL_MSG_FLAG_SEEN;
    srv_ret = srv_email_msg_update_basic_info(
        msg_handle,
        basic_info);
    OslMfree(basic_info);
    if (srv_ret != SRV_EMAIL_RESULT_SUCC)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_MRE_COMPOSE_BASIC, __LINE__);
        return MMI_EMAIL_APP_MRE_ERROR_CODE_EMAIL_NOT_READY;
    }

    // Sender
    ret = mmi_email_app_mre_set_sender(para);
    if (ret != MMI_EMAIL_APP_MRE_ERROR_CODE_SUCCESS)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_MRE_COMPOSE_BASIC, __LINE__);
        return ret;
    }

    // Recipient
    ret = mmi_email_app_mre_set_recipient(para);
    if (ret != MMI_EMAIL_APP_MRE_ERROR_CODE_SUCCESS)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_MRE_COMPOSE_BASIC, __LINE__);
        return ret;
    }

    // Subject
    if (para->subject != NULL)
    {
        srv_ret = srv_email_msg_update_subject(
            msg_handle,
            para->subject,
            MMI_CHSET_UCS2,
            mmi_wcslen(para->subject) + 1);
        if (srv_ret != SRV_EMAIL_RESULT_SUCC)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_MRE_COMPOSE_BASIC, __LINE__);
            return MMI_EMAIL_APP_MRE_ERROR_CODE_EMAIL_NOT_READY;
        }
    }

    // Content
    content = mmi_email_comp_get_content_buffer();
    if (content != NULL && content[0] != 0)
    {
        srv_email_msg_update_content_struct cont_buf;

        cont_buf.buff = content;
        cont_buf.buff_len = mmi_wcslen(content) + 1;
        cont_buf.buff_type = MMI_TRUE;
        cont_buf.charset = MMI_CHSET_UCS2;
        srv_ret = srv_email_msg_update_content(
            msg_handle,
            &cont_buf);
        if (srv_ret != SRV_EMAIL_RESULT_SUCC)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_MRE_COMPOSE_BASIC, __LINE__);
            return MMI_EMAIL_APP_MRE_ERROR_CODE_EMAIL_NOT_READY;
        }
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_MRE_COMPOSE_BASIC, __LINE__);
    return MMI_EMAIL_APP_MRE_ERROR_CODE_SUCCESS;
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_mre_set_sender
 * DESCRIPTION 
 *  mmi email app mre set sender
 * PARAMETERS 
 *  mmi_email_app_mre_send_param_struct *para
 * RETURNS 
 *  static mmi_email_app_mre_send_error_code_enum 
*****************************************************************************/
static
mmi_email_app_mre_send_error_code_enum
mmi_email_app_mre_set_sender(mmi_email_app_mre_send_param_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;
    srv_email_acct_info_struct *acct_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_SET_SENDER, __LINE__);
    ASSERT(para != NULL);

    acct_info = OslMalloc(sizeof(srv_email_acct_info_struct));
    result = srv_email_acct_read(g_mre_cntx.acct_handle, acct_info);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        OslMfree(acct_info);
        return MMI_EMAIL_APP_MRE_ERROR_CODE_EMAIL_NOT_READY;
    }

    // Update FROM
    if (para->from != NULL)
    {
        srv_email_addr_struct *srv_addr;

        srv_addr = OslMalloc(sizeof(srv_email_addr_struct));
        mmi_email_app_mre_copy_addr(srv_addr, para->from);
        result = srv_email_msg_update_sender(
                    g_mre_cntx.msg_handle,
                    srv_addr);

        OslMfree(srv_addr);
    }
    else
    {
        // Get from account 
        if (mmi_wcslen(acct_info->email_addr.email_addr))
        {
            result = srv_email_msg_update_sender(
                g_mre_cntx.msg_handle,
                &(acct_info->email_addr));
        }
    }

    // Update reply-to
    if (result == SRV_EMAIL_RESULT_SUCC &&
        mmi_wcslen(acct_info->reply_to_addr.email_addr))
    {
        result = srv_email_msg_update_reply_to(
                    g_mre_cntx.msg_handle,
                    &(acct_info->reply_to_addr));
    }

    OslMfree(acct_info);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_SET_SENDER, result);
        return MMI_EMAIL_APP_MRE_ERROR_CODE_EMAIL_NOT_READY;
    }

    return MMI_EMAIL_APP_MRE_ERROR_CODE_SUCCESS;
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_mre_set_recipient
 * DESCRIPTION 
 *  mmi email app mre set recipient
 * PARAMETERS 
 *  mmi_email_app_mre_send_param_struct *para
 * RETURNS 
 *  static mmi_email_app_mre_send_error_code_enum 
*****************************************************************************/
static
mmi_email_app_mre_send_error_code_enum
mmi_email_app_mre_set_recipient(mmi_email_app_mre_send_param_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_email_addr_struct *srv_addr;
    srv_email_result_enum srv_ret = (srv_email_result_enum)MMI_EMAIL_APP_MRE_ERROR_CODE_NO_RECIPIENT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_SET_RECIPIENT, __LINE__);
    ASSERT(para != NULL);
    srv_addr = mmi_email_comp_get_addlist();

    // To
    if (para->to_num > 0 && para->to != NULL)
    {
        for (i = 0; i < para->to_num; i++)
        {
            mmi_email_app_mre_copy_addr(&srv_addr[i], &para->to[i]);
        }

        srv_ret = srv_email_msg_update_recipient(
            g_mre_cntx.msg_handle,
            SRV_EMAIL_ADDR_TYPE_TO,
            para->to_num,
            srv_addr);

        if (srv_ret != SRV_EMAIL_RESULT_SUCC)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_SET_RECIPIENT, __LINE__);
            return MMI_EMAIL_APP_MRE_ERROR_CODE_EMAIL_NOT_READY;
        }
    }

    // Cc
    if (para->cc_num > 0 && para->cc != NULL)
    {
        for (i = 0; i < para->cc_num; i++)
        {
            mmi_email_app_mre_copy_addr(&srv_addr[i], &para->cc[i]);
        }

        srv_ret = srv_email_msg_update_recipient(
            g_mre_cntx.msg_handle,
            SRV_EMAIL_ADDR_TYPE_CC,
            para->cc_num,
            srv_addr);

        if (srv_ret != SRV_EMAIL_RESULT_SUCC)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_SET_RECIPIENT, __LINE__);
            return MMI_EMAIL_APP_MRE_ERROR_CODE_EMAIL_NOT_READY;
        }
    }

    // BCC
#ifdef __MMI_EMAIL_BCC__
    if (para->bcc_num > 0 && para->bcc != NULL)
    {
        for (i = 0; i < para->bcc_num; i++)
        {
            mmi_email_app_mre_copy_addr(&srv_addr[i], &para->bcc[i]);
        }

        srv_ret = srv_email_msg_update_recipient(
            g_mre_cntx.msg_handle,
            SRV_EMAIL_ADDR_TYPE_BCC,
            para->bcc_num,
            srv_addr);

        if (srv_ret != SRV_EMAIL_RESULT_SUCC)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_SET_RECIPIENT, __LINE__);
            return MMI_EMAIL_APP_MRE_ERROR_CODE_EMAIL_NOT_READY;
        }
    }
#endif /* __MMI_EMAIL_BCC__ */

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_SET_RECIPIENT, __LINE__);
    return MMI_EMAIL_APP_MRE_ERROR_CODE_SUCCESS;
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_mre_att_copy
 * DESCRIPTION 
 *  mmi email app mre att copy
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static mmi_email_app_mre_send_error_code_enum 
*****************************************************************************/
static
mmi_email_app_mre_send_error_code_enum
mmi_email_app_mre_att_copy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *file_path, *copy_file_path;
    WCHAR *file_name_ptr = NULL;
    WCHAR *file_ext_ptr = NULL;
    BOOL is_drm_obj = FALSE;

#ifdef __DRM_SUPPORT__
    S32 mime_type = 0, mime_subtype = 0;
    S32 fwd_flag = 0;
#endif /* __DRM_SUPPORT__ */

    S32 fileLen = 0;
    S32 f_handle, f_result;
    srv_email_attach_struct *comp_att;
    srv_email_attach_struct *comp_att_list;
    U32 attr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_ATT_COPY, __LINE__);

    comp_att_list = mmi_email_comp_get_attlist();

    if (g_mre_cntx.att_copy_idx >= g_mre_cntx.attach_file_num)
    {
        srv_email_msg_update_attach(
            g_mre_cntx.msg_handle,
            g_mre_cntx.attach_file_num,
            comp_att_list);
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_ATT_COPY, g_mre_cntx.att_copy_idx);
        return MMI_EMAIL_APP_MRE_ERROR_CODE_SUCCESS;
    }
    comp_att = &comp_att_list[g_mre_cntx.att_copy_idx];
    file_path = comp_att_list[g_mre_cntx.att_copy_idx].path;

    /* Get file size */
    f_handle = FS_Open((U16*)file_path, FS_READ_ONLY | FS_OPEN_SHARED);
    if (f_handle < 0)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_ATT_COPY, f_handle);
        return MMI_EMAIL_APP_MRE_ERROR_CODE_FILESYSTEM_ERROR;
    }

    fileLen = 0;
    f_result = FS_GetFileSize(f_handle, (UINT*)(&fileLen));
    FS_Close(f_handle);

    if (f_result < 0)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_ATT_COPY, f_result);
        return MMI_EMAIL_APP_MRE_ERROR_CODE_FILESYSTEM_ERROR;
    }

    g_mre_cntx.att_total_size += fileLen;
    if (g_mre_cntx.att_total_size > MMI_EMAIL_TOTAL_MAX_ATTACH_SIZE)
    {
        return MMI_EMAIL_APP_MRE_ERROR_CODE_ATT_TOO_LARGE;
    }
    comp_att->size = fileLen;

#ifdef __DRM_SUPPORT__
    mmi_email_util_get_mine_type(file_path, &mime_type, &mime_subtype);
    if (mime_subtype == MIME_SUBTYPE_DRM_MESSAGE)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_ATT_COPY, __LINE__);
        return MMI_EMAIL_APP_MRE_ERROR_CODE_DRM_FORBIDDEN;
    }

    fwd_flag = mmi_rmgr_check_forward((U16*)file_path);
    if (!(fwd_flag & MMI_RMGR_USAGE_SEND))
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_ATT_COPY, __LINE__);
        return MMI_EMAIL_APP_MRE_ERROR_CODE_DRM_FORBIDDEN;
    }

    if (fwd_flag < 0)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_ATT_COPY, __LINE__);
        return MMI_EMAIL_APP_MRE_ERROR_CODE_DRM_FORBIDDEN;
    }

    mmi_email_drm_is_file_lock(
        file_path,
        &is_drm_obj);
    comp_att->drm_object = (MMI_BOOL)is_drm_obj;
    if (comp_att->drm_object)
    {
        comp_att->mime_type = MIME_TYPE_APPLICATION;
        comp_att->mime_subtype = MIME_SUBTYPE_DRM_CONTENT;
        mmi_email_util_get_mine_type(
            file_path,
            &comp_att->drm_type,
            &comp_att->drm_subtype);
        comp_att->mime_type = MIME_TYPE_UNKNOWN;
        comp_att->mime_subtype = MIME_SUBTYPE_UNRECOGNIZED;
    }
    else
#endif /* __DRM_SUPPORT__ */
    {
        mmi_email_util_get_mine_type(
            file_path,
            &comp_att->mime_type,
            &comp_att->mime_subtype);
    }

    comp_att->charset = MMI_CHSET_UCS2;
    mmi_wcscpy(comp_att->path, file_path);
    file_name_ptr = srv_fmgr_path_get_filename_ptr(file_path);
    file_ext_ptr = srv_fmgr_path_get_extension_ptr(file_path);
    if (file_ext_ptr != NULL && file_name_ptr != NULL)
    {
        S32 file_name_len = mmi_wcslen(file_name_ptr);
        S32 file_ext_len = mmi_wcslen(file_ext_ptr);
        if (file_ext_len >= EMAIL_ATTCH_FILE_NAME_LEN)
        {
            mmi_wcsncpy(comp_att->name, file_name_ptr, EMAIL_ATTCH_FILE_NAME_LEN);
        }
        else
        {
            if (file_name_len - file_ext_len > EMAIL_ATTCH_FILE_NAME_LEN - file_ext_len - 1)
            {
                mmi_wcsncpy(comp_att->name, file_name_ptr, EMAIL_ATTCH_FILE_NAME_LEN - file_ext_len - 1);
                kal_wsprintf(
                    comp_att->name + (EMAIL_ATTCH_FILE_NAME_LEN - file_ext_len - 1),
                    "%c%w",
                    '.',
                    file_ext_ptr);
            }
            else
            {
                srv_fmgr_fs_path_get_display_name(
                    file_path,
                    comp_att->name,
                    sizeof(comp_att->name));
            }
        }
    }
    else
    {
        srv_fmgr_fs_path_get_display_name(
            file_path,
            comp_att->name,
            sizeof(comp_att->name));
    }
    comp_att->name_len = mmi_wcslen(comp_att->name);
    comp_att->size = fileLen;
    comp_att->downloaded = MMI_TRUE;

    /////////////////
    copy_file_path = OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(WCHAR));
    kal_wsprintf(copy_file_path, "%scopy_file\\", srv_email_get_root_path());
    if (!mmi_email_util_dir_exist(copy_file_path))
    {
        if (FS_CreateDir(copy_file_path) != FS_NO_ERROR)
        {
            OslMfree(copy_file_path);
            return MMI_EMAIL_APP_MRE_ERROR_CODE_FILESYSTEM_ERROR;
        }
    }

    kal_wsprintf(copy_file_path, "%scopy_file\\att%d.dat", srv_email_get_root_path(), g_mre_cntx.att_copy_idx);
    attr = FS_GetAttributes(copy_file_path);
    if (attr & FS_ATTR_READ_ONLY)
    {
        FS_SetAttributes(copy_file_path, (U8)(attr & ~(FS_ATTR_READ_ONLY)));
    }
    FS_Delete((U16*)copy_file_path);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_ATT_COPY, __LINE__);
    g_mre_cntx.fs_async_id =
        srv_fmgr_async_copy(
            file_path,
            copy_file_path,
            0,
            mmi_email_app_mre_att_async_copy_callback,
            NULL);
    mmi_wcscpy(file_path, copy_file_path);
    OslMfree(copy_file_path);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_ATT_COPY, g_mre_cntx.fs_async_id);

    if (g_mre_cntx.fs_async_id <= 0)
    {
        // trigger here
        mmi_email_app_mre_response(MMI_EMAIL_APP_MRE_ERROR_CODE_FILESYSTEM_ERROR);
        return MMI_EMAIL_APP_MRE_ERROR_CODE_FILESYSTEM_ERROR;
    }

    return MMI_EMAIL_APP_MRE_ERROR_CODE_WOULDBLOCK;
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_mre_att_async_copy_callback
 * DESCRIPTION 
 *  mmi email app mre att async copy callback
 * PARAMETERS 
 *  mmi_event_struct *param
 * RETURNS 
 *  static mmi_ret 
*****************************************************************************/
static mmi_ret mmi_email_app_mre_att_async_copy_callback(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_async_done_event_struct *async_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_ATT_ASYNC_COPY_CALLBACK, __LINE__);
    if (param->evt_id != EVT_ID_SRV_FMGR_ASYNC_DONE)
    {
        /* We DONT care events but EVT_ID_SRV_FMGR_ASYNC_DONE */
        return MMI_RET_OK;
    }

    if (g_mre_cntx.fsm_state != MRE_FSM_STATE_COMPOSE_ATTA_COPY)
    {
        /* Skip it */
        return MMI_RET_OK;
    }

    async_evt = (srv_fmgr_async_done_event_struct*)param;
    if (async_evt->result != 0)
    {
        mmi_email_app_mre_response(MMI_EMAIL_APP_MRE_ERROR_CODE_FILESYSTEM_ERROR);
        return MMI_RET_OK;
    }

    /* Copy next attachment */
    g_mre_cntx.att_copy_idx++;
    mmi_email_app_mre_fsm();
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_mre_save
 * DESCRIPTION 
 *  mmi email app mre save
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static mmi_email_app_mre_send_error_code_enum 
*****************************************************************************/
static
mmi_email_app_mre_send_error_code_enum
mmi_email_app_mre_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum srv_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_SAVE, __LINE__);

    // Save it
    srv_email_msg_regist_callback(
        g_mre_cntx.msg_handle,
        mmi_email_app_mre_save_callback,
        (void*)(&g_mre_cntx));

    srv_ret = srv_email_msg_save_new(
        g_mre_cntx.msg_handle,
        g_mre_cntx.acct_id,
        g_mre_cntx.fld_id,
        &g_mre_cntx.msg_id,
        &g_mre_cntx.req_id);
    if (srv_ret == SRV_EMAIL_RESULT_SUCC)
    {
        return MMI_EMAIL_APP_MRE_ERROR_CODE_SUCCESS;
    }

    if (srv_ret == SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        return MMI_EMAIL_APP_MRE_ERROR_CODE_WOULDBLOCK;
    }

    if (srv_ret == SRV_EMAIL_RESULT_FAIL)
    {
        return MMI_EMAIL_APP_MRE_ERROR_CODE_FILESYSTEM_ERROR;
    }

    return MMI_EMAIL_APP_MRE_ERROR_CODE_UNKNOWN_ERROR;
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_mre_save_callback
 * DESCRIPTION 
 *  mmi email app mre save callback
 * PARAMETERS 
 *  srv_email_result_struct *result
 *  EMAIL_REQ_ID req_id
 *  void *user_data
 * RETURNS 
 *  static void 
*****************************************************************************/
static void mmi_email_app_mre_save_callback(srv_email_result_struct *result,
                EMAIL_REQ_ID req_id,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_SAVE_CALLBACK, __LINE__);
    if (g_mre_cntx.fsm_state != MRE_FSM_STATE_COMPOSE_SAVE)
    {
        /* Skip it */
        return;
    }

    /* Destory message */
    ASSERT(g_mre_cntx.msg_handle != EMAIL_MSG_INVALID_HANDLE);
    srv_email_msg_clear_callback(g_mre_cntx.msg_handle);
    srv_email_msg_destroy(g_mre_cntx.msg_handle);
    g_mre_cntx.msg_handle = EMAIL_MSG_INVALID_HANDLE;

    if (!result->result)
    {
        /* Failed to save message */
        mmi_email_app_mre_response(MMI_EMAIL_APP_MRE_ERROR_CODE_SAVE_FAIL);
        return;
    }

    g_mre_cntx.fsm_state++;
    mmi_email_app_mre_fsm();
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_app_mre_response
 * DESCRIPTION 
 *  mmi email app mre response
 * PARAMETERS 
 *  mmi_email_app_mre_send_error_code_enum ret
 * RETURNS 
 *  static void 
*****************************************************************************/
static void mmi_email_app_mre_response(mmi_email_app_mre_send_error_code_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_app_mre_send_result_callback cb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MRE_RESPONSE, __LINE__);

    ASSERT(g_mre_cntx.fsm_state != MRE_FSM_STATE_NULL);
    cb = g_mre_cntx.cb;

    mmi_email_app_mre_cleanup();

    if (cb)
    {
        cb(ret, g_mre_cntx.user_data);
    }
}


#endif /* __MMI_EMAIL__ */
