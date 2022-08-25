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
 *  drm_http.c
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifdef __DRM_SUPPORT__
#ifdef __DRM_V02__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kal_release.h"        /* Basic data type */
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "app_buff_alloc.h"     /* ctrl buffer alloc */
#include "syscomp_config.h"
#include "task_config.h"

#include "wapadp.h"
#include "wap_ps_struct.h"
#include "app_str.h"
#include "app_ua.h"

#include "drm_trace.h"
#include "drm_gprot.h"
#include "drm_main.h"
#include "drm_http.h"
#include "drm_util.h"
#include "drm_prot.h"

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

typedef struct
{
    kal_uint8 req_id;
    kal_uint32 msg_id;

    union
    {
        struct
        {
            kal_uint16 status;
            kal_uint8 protocol;
            kal_uint8 content_type[256];
            kal_uint32 content_length;
            kal_bool more;
        } http_req;

        struct
        {
            kal_uint16 status;
            kal_uint8 seq_num;
            kal_uint32 acc_size;
        } progress;

        struct
        {
            kal_uint8 auth_type;
            kal_uint8 realm[256];
            kal_uint8 realm_len;
        } auth;
    } rsp;

    kal_uint32 reply_header_len;
    kal_uint8 *reply_header;
    kal_uint32 reply_segment_len;
    kal_uint8 *reply_segment;
} drmt_http_general_rsp_struct;

static kal_int16 drmt_http_channel_id = -1;
static drmt_http_general_rsp_struct drmt_http_response = {0};
static kal_uint8 drmt_http_error_num = WPS_OK;

#define drm_http_send_msg(data, peer, msg, dst)    drm_send_msg(MOD_DRMT, dst, msg, data, peer)

#define DRMT_HTTP_WPS_MAX_INPUT_BUFFER  2000


/*****************************************************************************
 * FUNCTION
 *  drmt_http_update_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void drmt_http_update_result(kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_HTTP_DEBUG(
        "[DRM] drmt_http_update_result %d",
        (TRACE_GROUP_HTTP, DRM_HTTP_47DF204AB1C7161AD0D7195F1F1421BC, result));

    drmt_http_error_num = result;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_http_init_response_buffer
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void drmt_http_init_response_buffer(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_HTTP_DEBUG(
        "[DRM] drmt_http_init_response_buffer",
        (TRACE_GROUP_HTTP, DRM_HTTP_F9BCE59EE962CFD6E2B3D3C8CF37F38F));

    drmt_http_error_num = WPS_OK;

    if (drmt_http_response.reply_header)
    {
        free_ctrl_buffer(drmt_http_response.reply_header);
    }

    if (drmt_http_response.reply_segment)
    {
        free_ctrl_buffer(drmt_http_response.reply_segment);
    }

    memset(&drmt_http_response, 0, sizeof(drmt_http_general_rsp_struct));
}

#define HTTP_MESSAGE


/*****************************************************************************
 * FUNCTION
 *  drmt_http_send_auth_res
 * DESCRIPTION
 * PARAMETERS
 *  channel_id          [IN]        
 *  request_id          [IN]        
 *  user_name           [?]         [?]         [?]
 *  user_name_len       [IN]        
 *  passwd              [?]         [?]         [?]
 *  passwd_len          [IN]        
 * RETURNS
 *****************************************************************************/
kal_bool drmt_http_send_auth_res(
            kal_uint8 channel_id,
            kal_uint8 request_id,
            kal_uint8 *user_name,
            kal_int32 user_name_len,
            kal_uint8 *passwd,
            kal_int32 passwd_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_auth_res_struct *auth_res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_HTTP_DEBUG("[DRM] drmt_http_send_auth_res", (TRACE_GROUP_HTTP, DRM_HTTP_B33BE014D4DD386953F52C4417B591FD));

    auth_res = (wps_http_auth_res_struct*) construct_local_para(sizeof(wps_http_auth_res_struct), TD_RESET);
    auth_res->channel_id = channel_id;
    auth_res->request_id = request_id;

    if (user_name_len >= WPS_MAX_AUTH_USERNAME_LENGTH)
    {
        user_name_len = WPS_MAX_AUTH_USERNAME_LENGTH - 1;
    }
    if (passwd_len >= WPS_MAX_AUTH_PASSWORD_LENGTH)
    {
        passwd_len = WPS_MAX_AUTH_PASSWORD_LENGTH - 1;
    }
    memcpy(auth_res->username, user_name, user_name_len);
    auth_res->username[user_name_len] = 0;
    memcpy(auth_res->password, passwd, passwd_len);
    auth_res->password[passwd_len] = 0;

    drm_http_send_msg(auth_res, NULL, MSG_ID_WPS_HTTP_AUTH_RES, MOD_WPS);
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_http_recv_auth_ind
 * DESCRIPTION
 * PARAMETERS
 *  current_ilm     [?]     [?]     [?]
 * RETURNS
 *****************************************************************************/
kal_bool drmt_http_recv_auth_ind(ilm_struct *current_ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_auth_ind_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_ilm->msg_id != MSG_ID_WPS_HTTP_AUTH_IND)
    {
        return KAL_FALSE;
    }
    DRM_HTTP_DEBUG("[DRM] drmt_http_recv_auth_ind", (TRACE_GROUP_HTTP, DRM_HTTP_093AB9DBFD772D0C0B57D5799EE4993E));

    drmt_http_init_response_buffer();

    p = (wps_http_auth_ind_struct*) current_ilm->local_para_ptr;

    drmt_http_response.req_id = p->request_id;
    drmt_http_response.msg_id = MSG_ID_WPS_HTTP_AUTH_IND;

    drmt_http_response.rsp.auth.auth_type = p->auth_type;
    drmt_http_response.rsp.auth.realm_len = p->realm_len;

    if (p->realm_len > 0)
    {
        memcpy(drmt_http_response.rsp.auth.realm, p->realm, p->realm_len);
    }
    else
    {
        drmt_http_response.rsp.auth.realm[0] = 0;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_http_send_set_channel_req
 * DESCRIPTION
 *  send setup channel request
 * PARAMETERS
 *  void
 *  Message(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool drmt_http_send_set_channel_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_set_channel_req_struct *set_channel_req;
    peer_buff_struct *peer_buff_ptr = NULL;
    wps_set_channel_req_var_struct set_channel_req_var;
    kal_uint16 len, pdu_length;
    kal_uint16 msg_len, ref_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (drmt_http_channel_id != -1)
    {
        EXT_ASSERT(0, 0, 0, 0);  /* we allow only one channal at one time */
        return KAL_FALSE;
    }
    DRM_HTTP_DEBUG(
        "[DRM] drmt_http_send_set_channel_req",
        (TRACE_GROUP_HTTP, DRM_HTTP_991D76F05BA11DED2DFFED85DD5B9B83));

    set_channel_req = (wps_set_channel_req_struct*) construct_local_para(sizeof(wps_set_channel_req_struct), TD_RESET);
    msg_len = set_channel_req->msg_len;
    ref_count = set_channel_req->ref_count;
    memset(set_channel_req, 0, sizeof(wps_set_channel_req_struct));
    set_channel_req->msg_len = msg_len;
    set_channel_req->ref_count = ref_count;
    set_channel_req->use_default = KAL_TRUE;

    set_channel_req_var.static_header_len = len = strlen("User-Agent: ") + strlen((kal_char*) applib_inet_get_user_agent_string()) + strlen("\r\n");
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
    set_channel_req_var.static_header = (kal_uint8*) get_ctrl_buffer((len + 1));

    sprintf((kal_char*) set_channel_req_var.static_header, "User-Agent: %s\r\n", (kal_char*) applib_inet_get_user_agent_string());
#if 0
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

    pdu_length = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_SET_CHANNEL_REQ, &set_channel_req_var, NULL);

    if (pdu_length > 0)
    {
        peer_buff_ptr = construct_peer_buff(pdu_length, 0, 0, TD_RESET);
        if (wps_pun_var_part
            (WPS_PUN_PACK, MSG_ID_WPS_SET_CHANNEL_REQ, &set_channel_req_var,
             get_pdu_ptr(peer_buff_ptr, &len)) != pdu_length)
        {
            free_peer_buff(peer_buff_ptr);
            peer_buff_ptr = NULL;
        }
    }

    free_ctrl_buffer(set_channel_req_var.static_header);

    drm_http_send_msg(set_channel_req, peer_buff_ptr, MSG_ID_WPS_SET_CHANNEL_REQ, MOD_WPS);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_http_recv_set_channel_rsp
 * DESCRIPTION
 *  Handler function to handle set channel response, save channel_id to context
 * PARAMETERS
 *  current_ilm     [?]     [?]     [?]
 *  Message(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool drmt_http_recv_set_channel_rsp(ilm_struct *current_ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_set_channel_rsp_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_ilm->msg_id != MSG_ID_WPS_SET_CHANNEL_RSP)
    {
        return KAL_FALSE;
    }
    DRM_HTTP_DEBUG(
        "[DRM] drmt_http_recv_set_channel_rsp",
        (TRACE_GROUP_HTTP, DRM_HTTP_398028D815C883686BDF5A31D999CF59));

    drmt_http_init_response_buffer();

    p = (wps_set_channel_rsp_struct*) current_ilm->local_para_ptr;

    drmt_http_response.msg_id = MSG_ID_WPS_SET_CHANNEL_RSP;

    if (p->result == WPS_OK)
    {
        drmt_http_channel_id = p->channel_id;
    }
    else
    {
        drmt_http_channel_id = -1;
    }

    drmt_http_update_result(p->result);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_http_send_unset_channel_req
 * DESCRIPTION
 *  Send "Unset channel" request to wap to destory channel
 * PARAMETERS
 *  void
 * RETURNS
 *  KAL_TRUE: OK
 *  KAL_FALSE: FAIL
 *****************************************************************************/
kal_bool drmt_http_send_unset_channel_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    wps_unset_channel_req_struct *unset_channel_req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_HTTP_DEBUG(
        "[DRM] drmt_http_send_unset_channel_req",
        (TRACE_GROUP_HTTP, DRM_HTTP_5BD927F2AECE14896A7B3AAC41849900));

    if (drmt_http_channel_id >= 0)
    {
        unset_channel_req =
            (wps_unset_channel_req_struct*) construct_local_para(sizeof(wps_unset_channel_req_struct), TD_RESET);
        unset_channel_req->channel_id = drmt_http_channel_id;
        drm_http_send_msg(unset_channel_req, NULL, MSG_ID_WPS_UNSET_CHANNEL_REQ, MOD_WPS);
        return KAL_TRUE;
    }
    else
    {
        /* ASSERT(0); */
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_http_recv_unset_channel_rsp
 * DESCRIPTION
 *  Handler function: To handle "unset channel response", reset the channel_id
 * PARAMETERS
 *  current_ilm     [?]     [?]     [?]
 *  Message(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool drmt_http_recv_unset_channel_rsp(ilm_struct *current_ilm)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_unset_channel_rsp_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_ilm->msg_id != MSG_ID_WPS_UNSET_CHANNEL_RSP)
    {
        return KAL_FALSE;
    }
    DRM_HTTP_DEBUG(
        "[DRM] drmt_http_recv_unset_channel_rsp",
        (TRACE_GROUP_HTTP, DRM_HTTP_C3F43EF7955CB0B0B6C6841F658B4BB1));

    drmt_http_init_response_buffer();

    p = (wps_unset_channel_rsp_struct*) current_ilm->local_para_ptr;

    drmt_http_response.msg_id = MSG_ID_WPS_UNSET_CHANNEL_RSP;

    if (p->result == WPS_OK)
    {
        drmt_http_channel_id = -1;
    }
    else
    {
        /* we must unset channel successful */
        drmt_http_channel_id = -1;
    }

    drmt_http_update_result(p->result);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_http_send_http_req
 * DESCRIPTION
 *  Send a "http request" to WAP task
 * PARAMETERS
 *  channel_id              [IN]        
 *  request_id              [IN]        Request_id, to regonize different action, reference to drmt_Http_request_id_enum
 *  http_method             [IN]        POST or GET
 *  url                     [IN]        Server url
 *  url_len                 [IN]        
 *  header                  [?]         [?]         [?]
 *  header_len              [IN]        
 *  post_segment            [?]         [?]         [?]
 *  post_segment_len        [IN]        
 *  post_total_len          [IN]        
 *  filepath                [IN]        Post file or write file
 *  more_post               [IN]        
 * RETURNS
 *  KAL_TRUE:  OK
 *  KAL_FALSE: FAIL
 *****************************************************************************/
kal_bool drmt_http_send_http_req(
            kal_int16 channel_id,
            kal_uint8 request_id,
            kal_uint8 http_method,
            kal_uint8 *url,
            kal_uint32 url_len,
            kal_uint8 *header,
            kal_int32 header_len,
            kal_uint8 *post_segment,
            kal_int32 post_segment_len,
            kal_int32 post_total_len,
            kal_uint16 *filepath,
            kal_bool more_post)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    wps_http_req_struct *http_req;
    wps_http_req_var_struct http_req_var;
    peer_buff_struct *peer_buff_ptr = NULL;
    kal_uint16 pdu_length;
    kal_uint16 len;
    static kal_uint16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(http_method == WPS_HTTP_METHOD_GET ||
           /* http_method == WPS_HTTP_METHOD_HEAD || */
           http_method == WPS_HTTP_METHOD_POST ||
           //            http_method == WPS_HTTP_METHOD_PUT  ||
           //            http_method == WPS_HTTP_METHOD_DELETE ||
           KAL_FALSE);

    EXT_ASSERT(url != NULL, 0, 0, 0);
    EXT_ASSERT(url_len + header_len + post_segment_len <= 2048, 0, 0, 0);

    DRM_HTTP_DEBUG("[DRM] drmt_http_send_http_req", (TRACE_GROUP_HTTP, DRM_HTTP_F656286C82B6AACD9A4F8CD4C01CD2D5));

    drmt_http_init_response_buffer();

    http_req = (wps_http_req_struct*) construct_local_para(sizeof(wps_http_req_struct), TD_RESET);
    http_req->channel_id = channel_id;
    http_req->request_id = request_id;
    http_req->method = http_method;
    http_req->option = WPS_HTTP_OPTION_NO_CACHE;

    if (http_method != WPS_HTTP_METHOD_GET)
    {
    #ifdef __POST_RESPONSE_BY_FILE__
        count++;
        http_req->reply_type = WPS_DATA_TYPE_FILE_NO_PROG_IND;
        kal_wsprintf(http_req->reply_path, "%s__temp__.%04d", DRM_DEFAULT_TEMP_PATH, count);
        drmt_http_response.reply_segment_len = kal_wstrlen(http_req->reply_path);
        drmt_http_response.reply_segment = (kal_uint8*) get_ctrl_buffer(drmt_http_response.reply_segment_len + 1);
        kal_sprintf((char*)drmt_http_response.reply_segment, "%s__temp__.%04d", DRM_DEFAULT_TEMP_PATH, count);
    #else /* __POST_RESPONSE_BY_FILE__ */ 
        http_req->reply_type = WPS_DATA_TYPE_BUFFER;
        http_req->reply_path[0] = '\0';
        http_req->reply_path[1] = '\0';
        http_req->reply_segment_len = DRMT_HTTP_WPS_MAX_INPUT_BUFFER;
    #endif /* __POST_RESPONSE_BY_FILE__ */ 
    }
    else
    {
        if (filepath != NULL)
        {
            http_req->reply_type = WPS_DATA_TYPE_FILE_NO_PROG_IND;
            app_ucs2_strncpy((kal_int8*) http_req->reply_path, (const kal_int8*)filepath, 255);
            http_req->reply_segment_len = 0;
        }
        else
        {
            http_req->reply_type = WPS_DATA_TYPE_FILE_NO_PROG_IND;
            count++;
            kal_wsprintf(http_req->reply_path, "%s__temp__.%04d", DRM_DEFAULT_TEMP_PATH, count);
            drmt_http_response.reply_segment_len = kal_wstrlen(http_req->reply_path);
            drmt_http_response.reply_segment = (kal_uint8*) get_ctrl_buffer(drmt_http_response.reply_segment_len + 1);
            kal_sprintf((char*)drmt_http_response.reply_segment, "%s__temp__.%04d", DRM_DEFAULT_TEMP_PATH, count);
            http_req->reply_segment_len = 0;
        }
    }

    if (http_method != WPS_HTTP_METHOD_POST)
    {
        http_req->post_type = 0;
        http_req->post_path[0] = '\0';
        http_req->post_path[1] = '\0';
        http_req->post_total_len = 0;
        http_req->more_post = KAL_FALSE;
    }
    else
    {
        if (filepath == NULL)
        {
            http_req->post_type = WPS_DATA_TYPE_BUFFER;
            http_req->post_path[0] = '\0';
            http_req->post_path[1] = '\0';
            http_req->post_total_len = post_total_len;
            http_req->more_post = more_post;
        }
        else
        {
            http_req->post_type = WPS_DATA_TYPE_FILE;
            app_ucs2_strncpy((kal_int8*) http_req->post_path, (const kal_int8*)filepath, 255);
            http_req->post_total_len = post_total_len;
            http_req->more_post = KAL_FALSE;
        }
    }

    http_req_var.request_url_len = url_len;
    http_req_var.request_url = url;
    http_req_var.request_header_len = header_len;
    http_req_var.request_header = header;

    if (http_method != WPS_HTTP_METHOD_POST)
    {
        http_req_var.post_segment_len = 0;
        http_req_var.post_segment = NULL;
    }
    else
    {
        http_req_var.post_segment_len = (kal_uint32) post_segment_len;
        http_req_var.post_segment = (kal_uint8*) post_segment;
    }

    pdu_length = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_HTTP_REQ, &http_req_var, NULL);

    if (pdu_length > 0)
    {
        peer_buff_ptr = construct_peer_buff(pdu_length, 0, 0, TD_RESET);
        if (wps_pun_var_part(WPS_PUN_PACK, MSG_ID_WPS_HTTP_REQ, &http_req_var, get_pdu_ptr(peer_buff_ptr, &len)) !=
            pdu_length)
        {
            free_peer_buff(peer_buff_ptr);
            peer_buff_ptr = NULL;
        }
    }

    drm_http_send_msg(http_req, peer_buff_ptr, MSG_ID_WPS_HTTP_REQ, MOD_WPS);

    return KAL_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  drmt_http_recv_http_rsp
 * DESCRIPTION
 *  Handler function: To handle "http response". We will save content_type at oma_content
 * PARAMETERS
 *  current_ilm     [?]     [?]     [?]
 *  Message(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool drmt_http_recv_http_rsp(ilm_struct *current_ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_rsp_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_ilm->msg_id != MSG_ID_WPS_HTTP_RSP)
    {
        return KAL_FALSE;
    }
    DRM_HTTP_DEBUG("[DRM] drmt_http_recv_http_rsp", (TRACE_GROUP_HTTP, DRM_HTTP_B9B6AA63AEC98753274A2974689F4C87));

    p = (wps_http_rsp_struct*) current_ilm->local_para_ptr;

    drmt_http_response.req_id = p->request_id;
    drmt_http_response.msg_id = MSG_ID_WPS_HTTP_RSP;

    if (p->result == WPS_OK)
    {
        drmt_http_response.rsp.http_req.content_length = p->content_length;
        drmt_http_response.rsp.http_req.status = p->status;
        drmt_http_response.rsp.http_req.more = p->more;
        drmt_http_response.rsp.http_req.protocol = p->protocol;
        if (p->content_length > 0)
        {
            strcpy((char*)&drmt_http_response.rsp.http_req.content_type, (char*)&p->content_type);
            /* memcpy(drmt_http_response.rsp.http_req.content_type, p->content_type, p->content_length); */
        }
        else
        {
            drmt_http_response.rsp.http_req.content_type[0] = 0;
        }
    }
    else
    {
        drmt_http_response.rsp.http_req.content_length = 0;
        drmt_http_response.rsp.http_req.status = 0;
        drmt_http_response.rsp.http_req.more = 0;
        drmt_http_response.rsp.http_req.protocol = 0;
        drmt_http_response.rsp.http_req.content_type[0] = 0;
    }

    drmt_http_update_result(p->result);

    if (current_ilm->peer_buff_ptr)
    {
        wps_http_rsp_var_struct http_rsp_var;
        kal_uint16 pdu_length = 0;

        if (wps_pun_var_part
            (WPS_PUN_UNPACK, current_ilm->msg_id, &http_rsp_var,
             get_pdu_ptr(current_ilm->peer_buff_ptr, &pdu_length)) > 0)
        {
            drmt_http_response.reply_header_len = http_rsp_var.reply_header_len;
            if (drmt_http_response.reply_header_len > 0)
            {
                drmt_http_response.reply_header = (kal_uint8*) get_ctrl_buffer(http_rsp_var.reply_header_len + 1);

                if (drmt_http_response.reply_header == NULL)
                {
                    drmt_http_update_result(WPS_ERROR_NO_RESOURCE);
                    return KAL_TRUE;
                }
                memcpy(drmt_http_response.reply_header, http_rsp_var.reply_header, drmt_http_response.reply_header_len);
                drmt_http_response.reply_header[drmt_http_response.reply_header_len] = 0;
            }

            if (drmt_http_response.reply_segment_len == 0)  /* reply by buffer, or reply by file */
            {
                drmt_http_response.reply_segment_len = http_rsp_var.reply_segment_len;
                if (drmt_http_response.reply_segment_len > 0)
                {
                    drmt_http_response.reply_segment =
                        (kal_uint8*) get_ctrl_buffer(http_rsp_var.reply_segment_len + 1);
                    if (drmt_http_response.reply_segment == NULL)
                    {
                        drmt_http_update_result(WPS_ERROR_NO_RESOURCE);
                        return KAL_TRUE;
                    }
                    memcpy(
                        drmt_http_response.reply_segment,
                        http_rsp_var.reply_segment,
                        drmt_http_response.reply_segment_len);
                    drmt_http_response.reply_segment[drmt_http_response.reply_segment_len] = 0;
                }
            }
        }
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_http_send_cancel_req
 * DESCRIPTION
 *  Send "cancel request" to WAP task to cancel an action.
 * PARAMETERS
 *  channel_id      [IN]        
 *  request_id      [IN]        Action, reference to drmt_Http_request_id_enum
 * RETURNS
 *  KAL_TRUE:  OK
 *  KAL_FALSE:  false
 *****************************************************************************/
kal_bool drmt_http_send_cancel_req(kal_uint8 channel_id, kal_uint8 request_id)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_cancel_req_struct *abort_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_HTTP_DEBUG("[DRM] drmt_http_send_cancel_req", (TRACE_GROUP_HTTP, DRM_HTTP_2B451F88170F7C49D4492815F5EBED68));

    abort_req = (wps_cancel_req_struct*) construct_local_para(sizeof(wps_cancel_req_struct), TD_RESET);
    abort_req->request_id = request_id;
    abort_req->channel_id = channel_id;
    drm_http_send_msg(abort_req, NULL, MSG_ID_WPS_CANCEL_REQ, MOD_WPS);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_http_recv_cancel_rsp
 * DESCRIPTION
 *  Handler function: To handle "cancel response".
 * PARAMETERS
 *  current_ilm     [?]     [?]     [?]
 *  Message(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool drmt_http_recv_cancel_rsp(ilm_struct *current_ilm)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_cancel_rsp_struct *p;;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_ilm->msg_id != MSG_ID_WPS_CANCEL_RSP)
    {
        return KAL_FALSE;
    }
    DRM_HTTP_DEBUG("[DRM] drmt_http_recv_cancel_rsp", (TRACE_GROUP_HTTP, DRM_HTTP_FF33BA6B80C6B95C9E90BE80E1EB5DA2));

    drmt_http_init_response_buffer();

    p = (wps_cancel_rsp_struct*) current_ilm->local_para_ptr;

    drmt_http_response.req_id = p->request_id;
    drmt_http_response.msg_id = MSG_ID_WPS_CANCEL_RSP;

    drmt_http_update_result(p->result);
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_http_recv_dl_progress_ind
 * DESCRIPTION
 *  Handler function: To handle "progress indication". We will save status,
 *  sequence number, and total size to oma_context
 * PARAMETERS
 *  current_ilm     [?]     [?]     [?]
 *  Message(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool drmt_http_recv_dl_progress_ind(ilm_struct *current_ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_dl_progress_ind_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_ilm->msg_id != MSG_ID_WPS_DL_PROGRESS_IND)
    {
        return KAL_FALSE;
    }
    DRM_HTTP_DEBUG(
        "[DRM] drmt_http_recv_dl_progress_ind",
        (TRACE_GROUP_HTTP, DRM_HTTP_62AB0A6842C64D64337F0D6C2844A8B4));

    drmt_http_init_response_buffer();

    p = (wps_dl_progress_ind_struct*) current_ilm->local_para_ptr;

    drmt_http_response.req_id = p->request_id;
    drmt_http_response.msg_id = MSG_ID_WPS_DL_PROGRESS_IND;
    drmt_http_response.rsp.progress.status = p->status;
    drmt_http_response.rsp.progress.seq_num = p->seq_num;
    drmt_http_response.rsp.progress.acc_size = p->acc_size;

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_http_send_dl_progress_res
 * DESCRIPTION
 *  Send "progress rsp" to WAP task
 * PARAMETERS
 *  channel_id      [IN]        
 *  request_id      [IN]        Action, reference to drmt_Http_request_id_enum
 *  seq_num         [IN]        
 * RETURNS
 *  KAL_TRUE:  OK
 *  KAL_FALSE:  false
 *****************************************************************************/
kal_bool drmt_http_send_dl_progress_res(kal_uint8 channel_id, kal_uint8 request_id, kal_int32 seq_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_dl_progress_res_struct *progress_res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_HTTP_DEBUG(
        "[DRM] drmt_http_send_dl_progress_res",
        (TRACE_GROUP_HTTP, DRM_HTTP_7DCA9DC6EF1471F10F6435AFE15D994C));

    progress_res = (wps_dl_progress_res_struct*) construct_local_para(sizeof(wps_dl_progress_res_struct), TD_RESET);
    progress_res->request_id = request_id;
    progress_res->channel_id = channel_id;
    progress_res->seq_num = seq_num;
    drm_http_send_msg(progress_res, NULL, MSG_ID_WPS_DL_PROGRESS_RES, MOD_WPS);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_http_send_clear_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  channel_id      [IN]        
 *  request_id      [IN]        
 *  url             [?]         [?]         [?]         [?]
 *  url_len         [IN]        
 *  url_length(?)       [IN](?)(?)
 *  conn_id(?)          [IN](?)(?)
 * RETURNS
 *  
 *****************************************************************************/
kal_bool drmt_http_send_clear_req(kal_uint8 channel_id, kal_uint8 request_id, kal_uint8 *url, kal_int32 url_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_clear_req_struct *clear_cache;
    wps_clear_req_var_struct clear_req_var;
    kal_uint16 pdu_length;
    peer_buff_struct *peer_buff_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_HTTP_DEBUG("[DRM] drmt_http_send_clear_req", (TRACE_GROUP_HTTP, DRM_HTTP_847BA39B9FC798C9429637B706DBF3EE));

    clear_cache = (wps_clear_req_struct*) construct_local_para(sizeof(wps_clear_req_struct), TD_RESET);

    clear_cache->channel_id = channel_id;
    clear_cache->request_id = request_id;
    clear_cache->operation = WPS_CLEAR_CACHE_URL_MATCH;

    clear_req_var.cache_url = url;
    clear_req_var.cache_url_len = url_len;

    pdu_length = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_CLEAR_REQ, &clear_req_var, NULL);
    peer_buff_ptr = construct_peer_buff(pdu_length, 0, 0, TD_RESET);
    wps_pun_var_part(WPS_PUN_PACK, MSG_ID_WPS_CLEAR_REQ, &clear_req_var, get_pdu_ptr(peer_buff_ptr, &pdu_length));

    drm_http_send_msg(clear_cache, peer_buff_ptr, MSG_ID_WPS_CLEAR_REQ, MOD_WPS);
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_http_recv_clear_rsp
 * DESCRIPTION
 * PARAMETERS
 *  current_ilm     [?]     [?]     [?]
 * RETURNS
 *****************************************************************************/
kal_bool drmt_http_recv_clear_rsp(ilm_struct *current_ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_clear_rsp_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_ilm->msg_id != MSG_ID_WPS_CLEAR_RSP)
    {
        return KAL_FALSE;
    }
    DRM_HTTP_DEBUG("[DRM] drmt_http_recv_clear_rsp", (TRACE_GROUP_HTTP, DRM_HTTP_5E7A9F272888D69854C3AD39F2E2C125));

    drmt_http_init_response_buffer();

    p = (wps_clear_rsp_struct*) current_ilm->local_para_ptr;

    drmt_http_response.msg_id = MSG_ID_WPS_CLEAR_RSP;
    drmt_http_response.req_id = p->request_id;

    drmt_http_update_result(p->result);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_http_send_read_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  channel_id      [IN]        
 *  request_id      [IN]        
 *  seq_no          [IN]        
 *  conn_id(?)      [IN](?)(?)
 * RETURNS
 *  
 *****************************************************************************/
kal_bool drmt_http_send_read_req(kal_uint8 channel_id, kal_uint8 request_id, kal_uint8 seq_no)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_read_content_req_struct *read_content_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_HTTP_DEBUG(
        "[DRM] drmt_http_send_read_req, seq=%d",
        (TRACE_GROUP_HTTP, DRM_HTTP_349010A885BD081ADADDFD2C270D0C6F, seq_no));

    read_content_req =
        (wps_read_content_req_struct*) construct_local_para(sizeof(wps_read_content_req_struct), TD_RESET);

    read_content_req->channel_id = channel_id;

    read_content_req->request_id = request_id;
    read_content_req->seq_num = seq_no;
    read_content_req->read_segnemtn_len = DRMT_HTTP_WPS_MAX_INPUT_BUFFER;

    drmt_http_init_response_buffer();

    drm_http_send_msg(read_content_req, NULL, MSG_ID_WPS_READ_CONTENT_REQ, MOD_WPS);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_http_recv_read_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  current_ilm     [?]     [?]     [?]
 *  seq_no(?)       [IN](?)(?)
 *  conn_id(?)      [IN](?)(?)
 * RETURNS
 *  
 *****************************************************************************/
kal_bool drmt_http_recv_read_rsp(ilm_struct *current_ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_read_content_rsp_struct *p = (wps_read_content_rsp_struct*) current_ilm->local_para_ptr;
    wps_read_content_rsp_var_struct http_read_content_rsp_var;
    kal_uint16 pdu_length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_ilm->msg_id != MSG_ID_WPS_READ_CONTENT_RSP)
    {
        return KAL_FALSE;
    }

    DRM_HTTP_DEBUG("[DRM] drmt_http_recv_read_rsp", (TRACE_GROUP_HTTP, DRM_HTTP_5E7A9F272888D69854C3AD39F2E2C126));

    drmt_http_response.msg_id = MSG_ID_WPS_READ_CONTENT_RSP;
    drmt_http_response.req_id = p->request_id;
    drmt_http_response.rsp.http_req.more = p->more;

    drmt_http_update_result(p->result);

    if (p->result == WPS_OK && current_ilm->peer_buff_ptr)
    {
        if (wps_pun_var_part
            (WPS_PUN_UNPACK, current_ilm->msg_id, &http_read_content_rsp_var,
             get_pdu_ptr(current_ilm->peer_buff_ptr, &pdu_length)) > 0)
        {
            drmt_http_response.reply_segment_len = http_read_content_rsp_var.reply_segment_len;

            if (drmt_http_response.reply_segment_len > 0)
            {
                drmt_http_response.reply_segment =
                    (kal_uint8*) get_ctrl_buffer(drmt_http_response.reply_segment_len + 1);
                if (drmt_http_response.reply_segment == NULL)
                {
                    drmt_http_update_result(WPS_ERROR_NO_RESOURCE);
                    return KAL_TRUE;
                }
                memcpy(
                    drmt_http_response.reply_segment,
                    http_read_content_rsp_var.reply_segment,
                    drmt_http_response.reply_segment_len);
                drmt_http_response.reply_segment[drmt_http_response.reply_segment_len] = 0;

            }
        }
    }

    return KAL_TRUE;
}

#define GET_MESSAGE_CONTENT


/*****************************************************************************
 * FUNCTION
 *  drmt_http_get_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  result(?)       [IN](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 drmt_http_get_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drmt_http_error_num;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_http_get_channel_id
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *****************************************************************************/
kal_int16 drmt_http_get_channel_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drmt_http_channel_id;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_http_get_request_id
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *****************************************************************************/
kal_uint8 drmt_http_get_request_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drmt_http_response.req_id;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_http_get_message_id
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *****************************************************************************/
kal_uint32 drmt_http_get_message_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drmt_http_response.msg_id;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_http_check_more
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *****************************************************************************/
kal_bool drmt_http_check_more(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ASSERT(drmt_http_response.msg_id == MSG_ID_WPS_HTTP_RSP); */

    return drmt_http_response.rsp.http_req.more;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_http_get_contenttype
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *****************************************************************************/
kal_uint8 *drmt_http_get_contenttype(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(drmt_http_response.msg_id == MSG_ID_WPS_HTTP_RSP);

    return drmt_http_response.rsp.http_req.content_type;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_http_get_contentlen
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *****************************************************************************/
kal_uint32 drmt_http_get_contentlen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(drmt_http_response.msg_id == MSG_ID_WPS_HTTP_RSP);

    return drmt_http_response.rsp.http_req.content_length;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_http_get_status
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *****************************************************************************/
kal_uint16 drmt_http_get_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(drmt_http_response.msg_id == MSG_ID_WPS_HTTP_RSP);

    return drmt_http_response.rsp.http_req.status;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_http_get_reply_header_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 drmt_http_get_reply_header_length(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drmt_http_response.reply_header_len;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_http_get_reply_header
 * DESCRIPTION
 *  
 * PARAMETERS
 *  header      [?]     [?]     [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
kal_bool drmt_http_get_reply_header(kal_uint8 *header)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (drmt_http_response.reply_header)
    {
        memcpy(header, drmt_http_response.reply_header, drmt_http_response.reply_header_len);
        header[drmt_http_response.reply_header_len] = 0;
        free_ctrl_buffer(drmt_http_response.reply_header);
        drmt_http_response.reply_header = NULL;
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  drmt_http_get_reply_segment_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 drmt_http_get_reply_segment_length(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drmt_http_response.reply_segment_len;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_http_get_reply_segment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  seg     [?]     [?]     [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
kal_bool drmt_http_get_reply_segment(kal_uint8 *seg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (drmt_http_response.reply_segment)
    {
        memcpy(seg, drmt_http_response.reply_segment, drmt_http_response.reply_segment_len);
        seg[drmt_http_response.reply_segment_len] = 0;
        free_ctrl_buffer(drmt_http_response.reply_segment);
        drmt_http_response.reply_segment = NULL;

        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  drmt_http_get_progress_status
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *****************************************************************************/
kal_uint16 drmt_http_get_progress_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(drmt_http_response.msg_id == MSG_ID_WPS_DL_PROGRESS_IND);

    return drmt_http_response.rsp.progress.status;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_http_get_progress_seqno
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *****************************************************************************/
kal_uint8 drmt_http_get_progress_seqno(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(drmt_http_response.msg_id == MSG_ID_WPS_DL_PROGRESS_IND);

    return drmt_http_response.rsp.progress.seq_num;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_http_get_progress_accsize
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *****************************************************************************/
kal_uint32 drmt_http_get_progress_accsize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(drmt_http_response.msg_id == MSG_ID_WPS_DL_PROGRESS_IND);

    return drmt_http_response.rsp.progress.acc_size;
}

#endif /* __DRM_V02__ */ 
#endif /* __DRM_SUPPORT__ */ 

