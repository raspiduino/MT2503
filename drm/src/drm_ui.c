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
 *  drm_mmi.c
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
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifdef __DRM_SUPPORT__
#ifdef __DRM_V02__

#include "kal_release.h"        /* Basic data type */
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "app_buff_alloc.h"
#include "stack_timer.h"
#include "syscomp_config.h"
#include "task_config.h"
#include "custom_config.h"
#include "app_str.h"

#ifndef MMI_ON_HARDWARE_P
#define MMI_ON_HARDWARE_P
#endif 

#ifndef __UCS2_ENCODING
#define __UCS2_ENCODING
#endif 

#include "MMI_features.h"
#include "PixtelDataTypes.h"
#include "CustDataRes.h"
#include "RightsMgrResDef.h"

#include "drm_trace.h"
#include "drm_def.h"
#include "drm_ui.h"
#include "drm_msg.h"
#include "drm_http.h"

static drmt_mmi_get_auth_cb get_auth_callback = NULL;

/*
 * static drmt_mmi_dl_progress_cb dl_progress_callback = NULL;
 * static drmt_mmi_alert_user_cb alert_user_callback = NULL;
 * static drmt_mmi_notify_info_cb notify_info_callback = NULL;
 */
static drmt_mmi_get_confirm_cb get_confirm_callback = NULL;
static drmt_mmi_open_url_cb open_url_callback = NULL;


/*****************************************************************************
 * FUNCTION
 *  drmt_mmi_send_ilm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]         [?]         [?]
 *  peer_buff_ptr       [?]         [?]         [?]
 *  ilm_id              [IN]        
 *  dst_id(?)           [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
static void drmt_mmi_send_ilm(void *local_para_ptr, void *peer_buff_ptr, msg_type ilm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = allocate_ilm(MOD_DRMT);
    ilm_ptr->local_para_ptr = (local_para_struct*) local_para_ptr;
    ilm_ptr->msg_id = ilm_id;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buff_ptr;

    SEND_ILM(MOD_DRMT, MOD_MMI, DRMT_MMI_SAP, ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  drmt_mmi_send_get_auth_req
 * DESCRIPTION
 * PARAMETERS
 *  callback        [IN]        
 * RETURNS
 *****************************************************************************/
kal_bool drmt_mmi_send_get_auth_req(drmt_mmi_get_auth_cb callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    drmt_get_auth_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (drmt_get_auth_req_struct*) construct_local_para(sizeof(drmt_get_auth_req_struct), TD_RESET);

    get_auth_callback = callback;

    drmt_mmi_send_ilm(NULL, NULL, MSG_ID_DRMT_GET_AUTH_REQ);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_mmi_recv_get_auth_cnf
 * DESCRIPTION
 * PARAMETERS
 *  current_ilm     [?]     [?]
 * RETURNS
 *****************************************************************************/
kal_bool drmt_mmi_recv_get_auth_cnf(ilm_struct *current_ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_get_auth_cnf_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_UI_DEBUG(
        "[DRM] receive confirm message from mmi %d",
        (TRACE_GROUP_UI, DRM_UI_GET_CONFIRM_MESSAGE, current_ilm->msg_id));

    if (current_ilm->msg_id != MSG_ID_DRMT_GET_AUTH_CNF)
    {
        return KAL_FALSE;
    }

    p = (drmt_get_auth_cnf_struct*) current_ilm->local_para_ptr;

    if (get_auth_callback)
    {
        (*get_auth_callback) ((const kal_uint8*)(p->username), p->user_len,
                              (const kal_uint8*)(p->password), p->pass_len);
        get_auth_callback = NULL;
    }

    return KAL_TRUE;
}

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
#endif

/*****************************************************************************
 * FUNCTION
 *  drmt_mmi_send_get_user_confirm_req
 * DESCRIPTION
 * PARAMETERS
 *  session         [IN]        
 *  title           [IN]        
 *  image           [IN]        
 *  category        [IN]        
 *  info            [IN]        
 *  callback        [IN]        
 * RETURNS
 *****************************************************************************/
kal_bool drmt_mmi_send_get_user_confirm_req(
            kal_uint16 session,
            kal_uint16 title,
            kal_uint16 image,
            kal_uint16 category,
            const kal_wchar *info,
            drmt_mmi_get_confirm_cb callback)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_get_user_confirm_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (drmt_get_user_confirm_req_struct*) construct_local_para(sizeof(drmt_get_user_confirm_req_struct), TD_RESET);

    msg->session_id = session;
    msg->title = title;
    msg->image = image;
    msg->category = category;

    if (info)
    {
        app_ucs2_strncpy((kal_int8*) msg->msg, (kal_int8*) info, 255);
    }

    get_confirm_callback = callback;

    drmt_mmi_send_ilm(msg, NULL, MSG_ID_DRMT_GET_USER_CONFIRM_REQ);
    return KAL_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  drmt_mmi_recv_get_user_confirm_cnf
 * DESCRIPTION
 * PARAMETERS
 *  current_ilm     [?]     [?]
 * RETURNS
 *****************************************************************************/
kal_bool drmt_mmi_recv_get_user_confirm_cnf(ilm_struct *current_ilm)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_get_user_confirm_cnf_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_UI_DEBUG(
        "[DRM] receive confirm message from mmi %d",
        (TRACE_GROUP_UI, DRM_UI_GET_CONFIRM_MESSAGE, current_ilm->msg_id));

    if (current_ilm->msg_id != MSG_ID_DRMT_GET_USER_CONFIRM_CNF)
    {
        return KAL_FALSE;
    }

    p = (drmt_get_user_confirm_cnf_struct*) current_ilm->local_para_ptr;

    if (get_confirm_callback)
    {
        (*get_confirm_callback) (p->result);
        get_confirm_callback = NULL;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_mmi_send_alert_user_ind
 * DESCRIPTION
 * PARAMETERS
 *  type            [IN]        
 *  info            [IN]        
 *  callback        [IN]        
 * RETURNS
 *****************************************************************************/
kal_bool drmt_mmi_send_alert_user_ind(kal_int8 type, const kal_wchar *info, drmt_mmi_alert_user_cb callback)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_alert_user_ind_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (drmt_alert_user_ind_struct*) construct_local_para(sizeof(drmt_alert_user_ind_struct), TD_RESET);

    msg->type = type;

    if (info)
    {
        app_ucs2_strncpy((kal_int8*) msg->msg, (kal_int8*) info, 31);
    }

    drmt_mmi_send_ilm(msg, NULL, MSG_ID_DRMT_ALERT_USER_IND);
    return KAL_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  drmt_mmi_recv_alert_user_rsp
 * DESCRIPTION
 * PARAMETERS
 *  current_ilm     [?]     [?]
 * RETURNS
 *****************************************************************************/
kal_bool drmt_mmi_recv_alert_user_rsp(ilm_struct *current_ilm)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_alert_user_rsp_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_UI_DEBUG(
        "[DRM] receive confirm message from mmi %d",
        (TRACE_GROUP_UI, DRM_UI_GET_CONFIRM_MESSAGE, current_ilm->msg_id));

    if (current_ilm->msg_id != MSG_ID_DRMT_ALERT_USER_RSP)
    {
        return KAL_FALSE;
    }
    p = (drmt_alert_user_rsp_struct*) current_ilm->local_para_ptr;
    return KAL_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  drmt_mmi_send_notify_info_ind
 * DESCRIPTION
 * PARAMETERS
 *  title           [IN]        
 *  image           [IN]        
 *  info            [IN]        
 *  callback        [IN]        
 * RETURNS
 *****************************************************************************/
kal_bool drmt_mmi_send_notify_info_ind(
            kal_uint16 title,
            kal_uint16 image,
            const kal_wchar *info,
            drmt_mmi_notify_info_cb callback)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_notify_info_ind_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (drmt_notify_info_ind_struct*) construct_local_para(sizeof(drmt_notify_info_ind_struct), TD_RESET);

    msg->image = image;
    msg->title = title;

    if (info)
    {
        app_ucs2_strncpy((kal_int8*) msg->msg, (kal_int8*) info, 511);
    }

    drmt_mmi_send_ilm(msg, NULL, MSG_ID_DRMT_NOTIFY_INFO_IND);
    return KAL_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  drmt_mmi_recv_notify_info_rsp
 * DESCRIPTION
 * PARAMETERS
 *  current_ilm     [?]     [?]
 * RETURNS
 *****************************************************************************/
kal_bool drmt_mmi_recv_notify_info_rsp(ilm_struct *current_ilm)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_notify_info_rsp_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_UI_DEBUG(
        "[DRM] receive confirm message from mmi %d",
        (TRACE_GROUP_UI, DRM_UI_GET_CONFIRM_MESSAGE, current_ilm->msg_id));

    if (current_ilm->msg_id != MSG_ID_DRMT_NOTIFY_INFO_RSP)
    {
        return KAL_FALSE;
    }
    p = (drmt_notify_info_rsp_struct*) current_ilm->local_para_ptr;
    return KAL_TRUE;

}
/*****************************************************************************
 * FUNCTION
 *  drmt_mmi_send_open_url_req
 * DESCRIPTION
 * PARAMETERS
 *  option          [IN]        
 *  url             [IN]        
 *  callback        [IN]        
 * RETURNS
 *****************************************************************************/
kal_bool drmt_mmi_send_open_url_req(kal_uint8 option, const kal_char *url, drmt_mmi_open_url_cb callback)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_open_url_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (drmt_open_url_req_struct*) construct_local_para(sizeof(drmt_open_url_req_struct), TD_RESET);

    if (url)
    {
        app_asc_str_n_to_ucs2_str((kal_int8*) msg->url, (kal_int8*) url, 767);
    }
    msg->option = option;
    open_url_callback = callback;

    drmt_mmi_send_ilm(msg, NULL, MSG_ID_DRMT_OPEN_URL_REQ);
    return KAL_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  drmt_mmi_recv_open_url_cnf
 * DESCRIPTION
 * PARAMETERS
 *  current_ilm     [?]     [?]
 * RETURNS
 *****************************************************************************/
kal_bool drmt_mmi_recv_open_url_cnf(ilm_struct *current_ilm)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_open_url_cnf_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_UI_DEBUG(
        "[DRM] receive confirm message from mmi %d",
        (TRACE_GROUP_UI, DRM_UI_GET_CONFIRM_MESSAGE, current_ilm->msg_id));

    if (current_ilm->msg_id != MSG_ID_DRMT_OPEN_URL_CNF)
    {
        return KAL_FALSE;
    }
    p = (drmt_open_url_cnf_struct*) current_ilm->local_para_ptr;

    if (open_url_callback)
    {
        (*open_url_callback) (p->result);
        open_url_callback = NULL;
    }

    return KAL_TRUE;
}

#define HIGH_LEVEL_BLOCKING_API

static drmt_get_confirm_result_enum user_confirm_reuslt = DRMT_CONFIRM_NO;


/*****************************************************************************
 * FUNCTION
 *  drmt_mmi_get_user_confirm_hdlr
 * DESCRIPTION
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void drmt_mmi_get_user_confirm_hdlr(drmt_get_confirm_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_confirm_reuslt = result;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_mmi_clean_screen
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *****************************************************************************/
kal_int32 drmt_mmi_clean_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_clean_screen_ind_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (drmt_clean_screen_ind_struct*) construct_local_para(sizeof(drmt_clean_screen_ind_struct), TD_RESET);

    drmt_mmi_send_ilm(msg, NULL, MSG_ID_DRMT_CLEAN_SCREEN_IND);
    return KAL_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  drmt_mmi_display_msg
 * DESCRIPTION
 * PARAMETERS
 *  session     [IN]        
 *  message     [IN]        
 *  UIType      [IN]        
 * RETURNS
 *****************************************************************************/
kal_int32 drmt_mmi_display_msg(kal_uint16 session, const kal_wchar *message, int UIType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret = DRMT_CONFIRM_YES;
    kal_bool abort_received;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_UI_DEBUG("[DRM] UIType = %d", (TRACE_GROUP_UI, DRM_UI_324EE1E4B544F83ECD611E4734A1D96D, UIType));

    if (UIType == DRMT_MBYesNo_Popup && kal_wstrlen(message) > 32)
    {
        UIType = DRMT_MBYesNo_Text;
    }

    if (UIType == DRMT_MBError_Text)
    {
        drmt_mmi_send_notify_info_ind(0, 0, message, NULL);
    }
    else if (UIType == DRMT_MBError_Popup)
    {
        drmt_mmi_send_alert_user_ind(DRMT_ALERT_ERROR, message, NULL);
    }
    else if (UIType == DRMT_MBInfo)
    {
        drmt_mmi_send_notify_info_ind(0, 0, message, NULL);
    }
    else if (UIType == DRMT_MBWarning)
    {
        drmt_mmi_send_alert_user_ind(DRMT_ALERT_WARNING, message, NULL);
    }
    else if (UIType == DRMT_MBNotify)
    {
        drmt_mmi_send_alert_user_ind(DRMT_ALERT_OK, message, NULL);
    }
    else if (UIType == DRMT_MBYesNo_Text)
    {
        drmt_mmi_send_get_user_confirm_req(
            session,
            0,
            IMG_GLOBAL_QUESTION,
            DRMT_CONFIRM_TEXT_VIEW_CATEGORY,
            message,
            drmt_mmi_get_user_confirm_hdlr);

        if (KAL_TRUE == drmt_get_next_msg(drmt_mmi_recv_get_user_confirm_cnf, KAL_TRUE, &abort_received, KAL_FALSE))
        {
            DRM_UI_DEBUG(
                "[DRM] User Ret:%d",
                (TRACE_GROUP_UI, DRM_UI_9C799241E9357A8D5B75A35CEB06F908, user_confirm_reuslt));

            ret = user_confirm_reuslt;
        }
        else
        {
            DRM_UI_DEBUG("[DRM] User Cancel", (TRACE_GROUP_UI, DRM_UI_5CB9240A57CD8D60476A5B395404C138));

            ret = DRMT_CONFIRM_CANCEL;
        }
    }
    else if (UIType == DRMT_MBYesNo_Popup)
    {
        drmt_mmi_send_get_user_confirm_req(
            session,
            0,
            IMG_GLOBAL_QUESTION,
            DRMT_CONFIRM_NOTIFICATION_CATEGORY,
            message,
            drmt_mmi_get_user_confirm_hdlr);

        if (KAL_TRUE == drmt_get_next_msg(drmt_mmi_recv_get_user_confirm_cnf, KAL_TRUE, &abort_received, KAL_FALSE))
        {
            DRM_UI_DEBUG(
                "[DRM] User Ret:%d",
                (TRACE_GROUP_UI, DRM_UI_9C799241E9357A8D5B75A35CEB06F908, user_confirm_reuslt));
            ret = user_confirm_reuslt;
        }
        else
        {
            DRM_UI_DEBUG("[DRM] User Cancel", (TRACE_GROUP_UI, DRM_UI_5CB9240A57CD8D60476A5B395404C138));
            ret = DRMT_CONFIRM_CANCEL;
        }
    }
    else
    {
        ret = DRMT_CONFIRM_NO;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_mmi_open_url_hdlr
 * DESCRIPTION
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static drmt_browser_error_enum open_url_result = DRMT_BROWSER_NO_ERROR;

static void drmt_mmi_open_url_hdlr(kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    open_url_result = result;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_mmi_open_url
 * DESCRIPTION
 * PARAMETERS
 *  url     [IN]        
 * RETURNS
 *****************************************************************************/
kal_int32 drmt_mmi_open_url(const kal_char *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (url == NULL)
    {
        return KAL_FALSE;
    }

    drmt_mmi_send_open_url_req(DRMT_BROWSER_GOTO_URL, url, drmt_mmi_open_url_hdlr);

    if (KAL_TRUE == drmt_get_next_msg(drmt_mmi_recv_open_url_cnf, KAL_TRUE, NULL, KAL_TRUE))
    {
        if (open_url_result == DRMT_BROWSER_NO_ERROR)
        {
            ret = KAL_TRUE;
        }
        else
        {
            ret = KAL_FALSE;
        }
    }
    else
    {
        ret = KAL_FALSE;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_mmi_get_string
 * DESCRIPTION
 * PARAMETERS
 *  string_id       [IN]        
 * RETURNS
 *****************************************************************************/
kal_wchar *drmt_mmi_get_string(kal_uint16 string_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_wchar*) GetString((U16) string_id);
}
#endif /* __DRM_V02__ */ 
#endif /* __DRM_SUPPORT__ */ /* __DRM_SUPPORT */

