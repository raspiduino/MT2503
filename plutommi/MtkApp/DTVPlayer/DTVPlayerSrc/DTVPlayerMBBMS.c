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
 * MobileTVPlayerMBBMS.c
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __CMMB_CAS_MBBMS_SUPPORT__
#include "GlobalConstants.h"
#include "kal_release.h"
#include "MMIDataType.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "stack_common.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "app_buff_alloc.h"
#include "wps_struct.h"
#include "fat_fs.h"
#include "xml_def.h"
#include "xmlgen.h"
#include "xmlgen_def.h"
#include "mmi_frm_events_gprot.h"
#include "DebugInitDef_Int.h"
#include "MMI_media_app_trc.h"
#include "DTVPlayerMBBMS.h"
#include "kal_public_api.h"


/*****************************************************************************
 * Define
 *****************************************************************************/
#define MMI_DTV_MBBMS_WPS_TIME_OUT              (30)
#define MMI_DTV_MBBMS_WPS_REQUEST_ID_BASE       (0x100)
#define MMI_DTV_MBBMS_WPS_REQUEST_ID_MAX        (0x200)
#define MMI_DTV_MBBMS_REDIRECT_OPTION_ONEVENT   (0x01)
#define MMI_DTV_MBBMS_REDIRECT_OPTION_GO        (0x02)
#define MMI_DTV_MBBMS_REDIRECT_ONEVENT          "onevent"
#define MMI_DTV_MBBMS_REDIRECT_ONEVENT_TYPE     "type"
#define MMI_DTV_MBBMS_REDIRECT_ONEVENT_TYPE_VAL "onenterforward"
#define MMI_DTV_MBBMS_REDIRECT_GO               "go"
#define MMI_DTV_MBBMS_REDIRECT_GO_HREF          "href"
#define MMI_DTV_MBBMS_REDIRECT_CONTENT_TYPE     "text/vnd.wap.wml"


/*****************************************************************************
 * Enum
 *****************************************************************************/
/* mtv mbbms states */
typedef enum
{
    MMI_DTV_MBBMS_STATE_IDLE,
    MMI_DTV_MBBMS_STATE_DOWNLOADING,
    MBBMS_STATE_ALL
} mmi_dtv_mbbms_state_enum;


/*****************************************************************************
 * Struct
 *****************************************************************************/
typedef struct
{
    dtv_func_ptr                        on_mbbms;   /* callback function */
    mmi_dtv_mbbms_state_enum            state;      /* current status */
    U8                                  channel_id; /* wps channel id */
    U32                                 req_id;     /* current request id */
    mmi_dtv_mbbms_dcnt_struct           dcnt_info;  /* data account information */
    mmi_dtv_mbbms_download_req_struct   curr_req;   /* current request data */
} mmi_dtv_mbbms_cntx;


/*****************************************************************************
 * Declarations
 *****************************************************************************/
static mmi_dtv_mbbms_cntx *dtv_mbbms_cntx_p = NULL;
static MMI_BOOL dtv_mbbms_service_ready = MMI_FALSE;
static U32 dtv_mbbms_redirect_flag = 0;
static U32 mmi_dtv_mbbms_get_next_req_id(void);
static void mmi_dtv_mbbms_wps_set_channel_req(void);
static MMI_BOOL mmi_dtv_mbbms_wps_set_channel_rsp(void *msg_struct);
static void mmi_dtv_mbbms_wps_unset_channel_req(void);
static void mmi_dtv_mbbms_wps_cancel_req(void);
static void mmi_dtv_mbbms_wps_http_req(void);
static MMI_BOOL mmi_dtv_mbbms_wps_http_rsp(void *msg_struct, int mod_id, void *ilm_info);
static void mmi_dtv_mbbms_xml_start_elem_hdlr(void *data, const kal_char *el, const kal_char **attr, kal_int32 error);
static void mmi_dtv_mbbms_error_hdlr(mmi_dtv_mbbms_ret_enum ret);


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_mbbms_open
 * DESCRIPTION
 *  open mtv mbbms, initialization of mbbms service
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mmi_dtv_mbbms_ret_enum mmi_dtv_mbbms_open(dtv_func_ptr on_mbbms, mmi_dtv_mbbms_dcnt_struct *dcnt_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 mem_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if mtv mbbms is on service, it should not be called again */
    if (dtv_mbbms_service_ready)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_COMMON_FAIL, __LINE__);
        return MMI_DTV_MBBMS_ERR_FAIL;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_MBBMS_OPEN);

    /* alloc memory for mtv mbbms context */
    mem_size = sizeof(mmi_dtv_mbbms_cntx);
    dtv_mbbms_cntx_p = (mmi_dtv_mbbms_cntx*)get_ctrl_buffer(mem_size);
    if (!dtv_mbbms_cntx_p)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_COMMON_FAIL, __LINE__);
        return MMI_DTV_MBBMS_ERR_FAIL;
    }
    memset((void*)dtv_mbbms_cntx_p, 0, mem_size);

    /* initialization */
    dtv_mbbms_cntx_p->on_mbbms = on_mbbms;
    dtv_mbbms_cntx_p->req_id = 0;
    dtv_mbbms_cntx_p->channel_id = 0xFF;
    dtv_mbbms_cntx_p->state = MMI_DTV_MBBMS_STATE_IDLE;
    memcpy((void*)&dtv_mbbms_cntx_p->dcnt_info, (void*)dcnt_ptr, sizeof(mmi_dtv_mbbms_dcnt_struct));

    /* mtv mbbms service is ready now */
    dtv_mbbms_service_ready = MMI_TRUE;
    return MMI_DTV_MBBMS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_mbbms_close
 * DESCRIPTION
 *  close mtv mbbms service, free resource
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mmi_dtv_mbbms_ret_enum mmi_dtv_mbbms_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if mtv mbbms is not on service, it should be called */
    if (!dtv_mbbms_service_ready)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_COMMON_FAIL, __LINE__);
        return MMI_DTV_MBBMS_ERR_SRV_UNAVAILABLE;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_MBBMS_CLOSE);

    /* cancle the current request */
    if (dtv_mbbms_cntx_p->state == MMI_DTV_MBBMS_STATE_DOWNLOADING)
    {
        mmi_dtv_mbbms_wps_cancel_req();
    }

    /* unset channel if needed */
    if (dtv_mbbms_cntx_p->channel_id != 0xFF)
    {
        mmi_dtv_mbbms_wps_unset_channel_req();
    }

    /* clean up */
    dtv_mbbms_cntx_p->state = MMI_DTV_MBBMS_STATE_IDLE;
    free_ctrl_buffer(dtv_mbbms_cntx_p);
    dtv_mbbms_service_ready = MMI_FALSE;
    return MMI_DTV_MBBMS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_mbbms_download
 * DESCRIPTION
 *  download file
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mmi_dtv_mbbms_ret_enum mmi_dtv_mbbms_download(mmi_dtv_mbbms_download_req_struct *req_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check service is ready or not */
    if (!dtv_mbbms_service_ready)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_COMMON_FAIL, __LINE__);
        return MMI_DTV_MBBMS_ERR_SRV_UNAVAILABLE;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_MBBMS_DOWNLOAD, dtv_mbbms_cntx_p->state);

    /* state and req_data check */
    if (dtv_mbbms_cntx_p->state != MMI_DTV_MBBMS_STATE_IDLE)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_COMMON_FAIL, __LINE__);
        return MMI_DTV_MBBMS_ERR_SRV_UNAVAILABLE;
    }
    else if (!req_data)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_COMMON_FAIL, __LINE__);
        return MMI_DTV_MBBMS_ERR_INVALID_DATA;
    }

    /* check the url and filepath length */
    if ((strlen((char*)req_data->req_url) > MMI_DTV_MBBMS_REQ_URL_LEN) ||
        (mmi_ucs2strlen((CHAR*)req_data->file_path) > MMI_DTV_MBBMS_MAX_FILE_LEN))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_COMMON_FAIL, __LINE__);
        return MMI_DTV_MBBMS_ERR_INVALID_DATA;
    }

    /* save the request data */
    memcpy((void*)&dtv_mbbms_cntx_p->curr_req, req_data, sizeof(mmi_dtv_mbbms_download_req_struct));
    dtv_mbbms_cntx_p->state = MMI_DTV_MBBMS_STATE_DOWNLOADING;

    /* check if channel is set or not */
    if (dtv_mbbms_cntx_p->channel_id == 0xFF)
    {
        mmi_dtv_mbbms_wps_set_channel_req();
    }
    else
    {
        mmi_dtv_mbbms_wps_http_req();
    }

    return MMI_DTV_MBBMS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_mbbms_cancel_download
 * DESCRIPTION
 *  cancel download file
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mmi_dtv_mbbms_ret_enum mmi_dtv_mbbms_cancel_download(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check service is ready or not */
    if (!dtv_mbbms_service_ready)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_COMMON_FAIL, __LINE__);
        return MMI_DTV_MBBMS_ERR_SRV_UNAVAILABLE;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_MBBMS_CANCEL_DOWNLOAD, dtv_mbbms_cntx_p->state);

    /* check the state */
    if (dtv_mbbms_cntx_p->state != MMI_DTV_MBBMS_STATE_DOWNLOADING)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_COMMON_FAIL, __LINE__);
        return MMI_DTV_MBBMS_ERR_SRV_UNAVAILABLE;
    }
    else
    {
        mmi_dtv_mbbms_wps_cancel_req();
        dtv_mbbms_cntx_p->state = MMI_DTV_MBBMS_STATE_IDLE;
        return MMI_DTV_MBBMS_OK;
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_mbbms_get_next_req_id
 * DESCRIPTION
 *  get next request id, make sure that id is betwwen MMI_DTV_MBBMS_WPS_REQUEST_ID_BASE
 *  and MMI_DTV_MBBMS_WPS_REQUEST_ID_MAX.
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static U32 mmi_dtv_mbbms_get_next_req_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ++dtv_mbbms_cntx_p->req_id;
    if (dtv_mbbms_cntx_p->req_id > MMI_DTV_MBBMS_WPS_REQUEST_ID_MAX)
    {
        dtv_mbbms_cntx_p->req_id = MMI_DTV_MBBMS_WPS_REQUEST_ID_BASE;
    }
    return dtv_mbbms_cntx_p->req_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_mbbms_wps_set_channel_req
 * DESCRIPTION
 *  set channel request to WPS
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_mbbms_wps_set_channel_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_set_channel_req_struct *set_channel_req = NULL;
    wps_set_channel_req_var_struct set_channel_req_var;
    peer_buff_struct *peer_buff_ptr = NULL;
    kal_uint32 pdu_length;
    kal_uint16 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_MBBMS_WPS_SET_CHANNEL_REQ,
        dtv_mbbms_cntx_p->state, dtv_mbbms_cntx_p->dcnt_info.use_proxy, dtv_mbbms_cntx_p->dcnt_info.app_id,
        dtv_mbbms_cntx_p->dcnt_info.net_id, dtv_mbbms_cntx_p->dcnt_info.prx_ip[0], dtv_mbbms_cntx_p->dcnt_info.prx_ip[1],
        dtv_mbbms_cntx_p->dcnt_info.prx_ip[2], dtv_mbbms_cntx_p->dcnt_info.prx_ip[3], dtv_mbbms_cntx_p->dcnt_info.prx_port);

    /* construct local para */
    set_channel_req = (wps_set_channel_req_struct*)construct_local_para(sizeof(wps_set_channel_req_struct), TD_RESET);
    set_channel_req->use_default = MMI_FALSE;
    set_channel_req->conn_type = WPS_CONN_TYPE_HTTP;
    set_channel_req->net_id = dtv_mbbms_cntx_p->dcnt_info.net_id;
    set_channel_req->use_proxy = dtv_mbbms_cntx_p->dcnt_info.use_proxy;
    memcpy((void*)set_channel_req->prx_addr, (void*)dtv_mbbms_cntx_p->dcnt_info.prx_ip, 4);
    set_channel_req->prx_port = dtv_mbbms_cntx_p->dcnt_info.prx_port;
    set_channel_req->app_id = dtv_mbbms_cntx_p->dcnt_info.app_id;
    set_channel_req->req_id = mmi_dtv_mbbms_get_next_req_id();
    set_channel_req->timeout = MMI_DTV_MBBMS_WPS_TIME_OUT;
    set_channel_req_var.static_header_len = 0;
    set_channel_req_var.static_header = NULL;

    /* pack peer buff */
    pdu_length = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_SET_CHANNEL_REQ, &set_channel_req_var, NULL);
    if (pdu_length > 0)
    {
        peer_buff_ptr = construct_peer_buff(pdu_length, 0, 0, TD_RESET);
        if (wps_pun_var_part(WPS_PUN_PACK, MSG_ID_WPS_SET_CHANNEL_REQ, &set_channel_req_var,
            get_peer_buff_pdu(peer_buff_ptr, &len)) != pdu_length)
        {
            free_peer_buff(peer_buff_ptr);
            peer_buff_ptr = NULL;
        }
    }

    /* construct message and send */
    mmi_frm_send_ilm(MOD_WPS, MSG_ID_WPS_SET_CHANNEL_REQ, (oslParaType*)set_channel_req, (oslPeerBuffType*)peer_buff_ptr);
    mmi_frm_set_protocol_event_handler(MSG_ID_WPS_SET_CHANNEL_RSP, (PsIntFuncPtr)mmi_dtv_mbbms_wps_set_channel_rsp, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_mbbms_wps_set_channel_rsp
 * DESCRIPTION
 *  set channel response from WPS
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_dtv_mbbms_wps_set_channel_rsp(void *msg_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_set_channel_rsp_struct *rsp = (wps_set_channel_rsp_struct*)msg_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if service has been closed, no need to handle */
    if (!dtv_mbbms_service_ready)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_COMMON_FAIL, __LINE__);
        mmi_dtv_mbbms_error_hdlr(MMI_DTV_MBBMS_ERR_FAIL);
        return MMI_FALSE;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_MBBMS_WPS_SET_CHANNEL_RSP,
        dtv_mbbms_cntx_p->state, dtv_mbbms_cntx_p->req_id, rsp->result, rsp->channel_id);

    /* check if this response belongs to mbbms */
    if (rsp->req_id != dtv_mbbms_cntx_p->req_id)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_COMMON_FAIL, __LINE__);
        mmi_dtv_mbbms_error_hdlr(MMI_DTV_MBBMS_ERR_FAIL);
        return MMI_FALSE;
    }

    mmi_frm_clear_protocol_event_handler(MSG_ID_WPS_SET_CHANNEL_RSP, (PsIntFuncPtr)mmi_dtv_mbbms_wps_set_channel_rsp);

    /* check response result */
    if (rsp->result == WPS_OK)
    {
        /* save channel id */
        dtv_mbbms_cntx_p->channel_id = rsp->channel_id;

        /* send http request */
        mmi_dtv_mbbms_wps_http_req();
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_COMMON_FAIL, __LINE__);
        mmi_dtv_mbbms_error_hdlr(MMI_DTV_MBBMS_ERR_FAIL);
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_mbbms_wps_unset_channel_req
 * DESCRIPTION
 *  unset channel request to WPS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_mbbms_wps_unset_channel_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_unset_channel_req_struct *unset_channel_req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_MBBMS_WPS_SET_UNCHANNEL_REQ,
        dtv_mbbms_cntx_p->state, dtv_mbbms_cntx_p->channel_id);

    /* check if the channel id valid */
    if (dtv_mbbms_cntx_p->channel_id == 0xFF)
    {
        return;
    }

    /* construct local para */
    unset_channel_req = (wps_unset_channel_req_struct*)construct_local_para(sizeof(wps_unset_channel_req_struct), TD_RESET);
    unset_channel_req->channel_id = dtv_mbbms_cntx_p->channel_id;

    /* send message, and no need to hdlr response */
    mmi_frm_send_ilm(MOD_WPS, MSG_ID_WPS_UNSET_CHANNEL_REQ, (oslParaType*)unset_channel_req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_mbbms_wps_cancel_req
 * DESCRIPTION
 *  cancel request to WPS
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_mbbms_wps_cancel_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_cancel_req_struct *cancel_req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_MBBMS_WPS_CANCEL_REQ, dtv_mbbms_cntx_p->state);

    /* construct local para */
    cancel_req = (wps_cancel_req_struct*)construct_local_para(sizeof(wps_cancel_req_struct), TD_RESET);
    cancel_req->channel_id = dtv_mbbms_cntx_p->channel_id;
    cancel_req->request_id = dtv_mbbms_cntx_p->req_id;

    /* send message, and no need to hdlr response */
    mmi_frm_send_ilm(MOD_WPS, MSG_ID_WPS_CANCEL_REQ, (oslParaType*)cancel_req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_mbbms_wps_http_req
 * DESCRIPTION
 *  download http request
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_mbbms_wps_http_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_req_struct *http_req = NULL;
    wps_http_req_var_struct http_req_var = {0};
    peer_buff_struct *peer_buff_ptr = NULL;
    kal_int32 pdu_length;
    kal_uint16 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_MBBMS_WPS_HTTP_REQ, dtv_mbbms_cntx_p->state);

    /* construct local para */
    http_req = (wps_http_req_struct*)construct_local_para(sizeof(wps_http_req_struct), TD_RESET);
    http_req->channel_id = dtv_mbbms_cntx_p->channel_id;
    http_req->request_id = mmi_dtv_mbbms_get_next_req_id();
    http_req->method = WPS_HTTP_METHOD_GET;
    http_req->option = WPS_HTTP_OPTION_NO_CACHE | WPS_HTTP_OPTION_DO_NOT_CACHE_REPLY;
    http_req->reply_type = WPS_DATA_TYPE_FILE_NO_PROG_IND;
    mmi_ucs2cpy((CHAR*)http_req->reply_path, (CHAR*)dtv_mbbms_cntx_p->curr_req.file_path);

    /* request url */
    http_req_var.request_url_len = strlen((char*)dtv_mbbms_cntx_p->curr_req.req_url);
    http_req_var.request_url = (kal_uint8*)get_ctrl_buffer(http_req_var.request_url_len + 1);
    strcpy((char*)http_req_var.request_url, (char*)dtv_mbbms_cntx_p->curr_req.req_url);
    http_req_var.request_header = NULL;
    http_req_var.request_header_len = 0;
    http_req_var.post_segment = NULL;
    http_req_var.post_segment_len = 0;

    /* pack peer buff */
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

    /* free ctrl buff */
    free_ctrl_buffer(http_req_var.request_url);

    /* send message */
    mmi_frm_send_ilm(MOD_WPS, MSG_ID_WPS_HTTP_REQ, (oslParaType*)http_req, (oslPeerBuffType*)peer_buff_ptr);
    mmi_frm_set_protocol_event_handler(MSG_ID_WPS_HTTP_RSP, (PsIntFuncPtr)mmi_dtv_mbbms_wps_http_rsp, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_mbbms_wps_http_rsp
 * DESCRIPTION
 *  download http response
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_dtv_mbbms_wps_http_rsp(void *msg_struct, int mod_id, void *ilm_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_rsp_struct *rsp = (wps_http_rsp_struct*)msg_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if service has been closed, no need to handle */
    if (!dtv_mbbms_service_ready)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_COMMON_FAIL, __LINE__);
        mmi_dtv_mbbms_error_hdlr(MMI_DTV_MBBMS_ERR_FAIL);
        return MMI_FALSE;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_MBBMS_WPS_HTTP_RSP,
        dtv_mbbms_cntx_p->state, dtv_mbbms_cntx_p->req_id, rsp->request_id, rsp->result,
        rsp->status, rsp->content_length, rsp->more);

    /* check if this response belongs to mbbms */
    if (rsp->request_id != dtv_mbbms_cntx_p->req_id)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_COMMON_FAIL, __LINE__);
        mmi_dtv_mbbms_error_hdlr(MMI_DTV_MBBMS_ERR_FAIL);
        return MMI_FALSE;
    }

    mmi_frm_clear_protocol_event_handler(MSG_ID_WPS_HTTP_RSP, (PsIntFuncPtr)mmi_dtv_mbbms_wps_http_rsp);

    /* if current state is not downloading, no need to handle */
    if (dtv_mbbms_cntx_p->state != MMI_DTV_MBBMS_STATE_DOWNLOADING)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_COMMON_FAIL, __LINE__);
        mmi_dtv_mbbms_error_hdlr(MMI_DTV_MBBMS_ERR_FAIL);
        return MMI_FALSE;
    }

    /* check response result */
    if (rsp->result != WPS_OK || rsp->status != 200)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_COMMON_FAIL, __LINE__);
        mmi_dtv_mbbms_error_hdlr(MMI_DTV_MBBMS_ERR_FAIL);
        return MMI_FALSE;
    }

    /* check the content type */
    if (strstr((char*)rsp->content_type, (char*)MMI_DTV_MBBMS_REDIRECT_CONTENT_TYPE))
    {
        /* if the content type contains "text/vnd.wap.wml", we need to parse the redirect url */
        XML_PARSER_STRUCT xml_parser;
        kal_int32 xml_result;
        dtv_mbbms_redirect_flag = 0;
        xml_result = xml_new_parser(&xml_parser);
        if (xml_result != XML_RESULT_OK)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_COMMON_FAIL, __LINE__);
            mmi_dtv_mbbms_error_hdlr(MMI_DTV_MBBMS_ERR_FAIL);
            return MMI_FALSE;
        }

        /* register start, end and data hdlr */
        xml_register_element_handler(&xml_parser, mmi_dtv_mbbms_xml_start_elem_hdlr, NULL);
        xml_register_data_handler(&xml_parser, NULL);
        xml_result = xml_parse(&xml_parser, dtv_mbbms_cntx_p->curr_req.file_path);
        xml_close_parser(&xml_parser);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_MBBMS_XML_RESULT, xml_result, dtv_mbbms_redirect_flag);

        if ((xml_result == XML_RESULT_OK) &&
            (dtv_mbbms_redirect_flag & MMI_DTV_MBBMS_REDIRECT_OPTION_ONEVENT) &&
            (dtv_mbbms_redirect_flag & MMI_DTV_MBBMS_REDIRECT_OPTION_GO))
        {
            /* resend the http request */
            mmi_dtv_mbbms_wps_http_req();
            return MMI_TRUE;
        }
        else
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_COMMON_FAIL, __LINE__);
            mmi_dtv_mbbms_error_hdlr(MMI_DTV_MBBMS_ERR_FAIL);
            return MMI_FALSE;
        }
    }

    dtv_mbbms_cntx_p->state = MMI_DTV_MBBMS_STATE_IDLE;
    dtv_mbbms_cntx_p->on_mbbms(MMI_DTV_MBBMS_OK, dtv_mbbms_cntx_p->curr_req.file_path);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_mbbms_xml_start_elem_hdlr
 * DESCRIPTION
 *  xml parser start element handler, for redirect url check
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_mbbms_xml_start_elem_hdlr(void *data, const kal_char *el, const kal_char **attr, kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (error != XML_NO_ERROR)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_COMMON_FAIL, __LINE__);
        return;
    }

    /* parse onevent */
    if (strcmp(el, MMI_DTV_MBBMS_REDIRECT_ONEVENT) == 0)
    {
        while(attr[index] != NULL && attr[index + 1] != NULL)
        {
            /* onevent type */
            if (strcmp(attr[index], MMI_DTV_MBBMS_REDIRECT_ONEVENT_TYPE) == 0)
            {
                if (strcmp(attr[index + 1], MMI_DTV_MBBMS_REDIRECT_ONEVENT_TYPE_VAL) == 0)
                {
                    dtv_mbbms_redirect_flag |= MMI_DTV_MBBMS_REDIRECT_OPTION_ONEVENT;
                }
            }
            index += 2;
        }
        return;
    }

    /* parse go */
    if ((strcmp(el, MMI_DTV_MBBMS_REDIRECT_GO) == 0) &&
        (dtv_mbbms_redirect_flag & MMI_DTV_MBBMS_REDIRECT_OPTION_ONEVENT))
    {
        while(attr[index] != NULL && attr[index + 1] != NULL)
        {
            /* href */
            if (strcmp(attr[index], MMI_DTV_MBBMS_REDIRECT_GO_HREF) == 0)
            {
                if (strlen(attr[index + 1]) < MMI_DTV_MBBMS_REQ_URL_LEN)
                {
                    strcpy((char*)dtv_mbbms_cntx_p->curr_req.req_url, attr[index + 1]);
                    dtv_mbbms_redirect_flag |= MMI_DTV_MBBMS_REDIRECT_OPTION_GO;
                }
            }
            index += 2;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mbbms_error_hdlr
 * DESCRIPTION
 *  error hdlr for mbbms
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_mbbms_error_hdlr(mmi_dtv_mbbms_ret_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_MBBMS_ERROR_HDLR, ret);

    dtv_mbbms_cntx_p->state = MMI_DTV_MBBMS_STATE_IDLE;
    dtv_mbbms_cntx_p->on_mbbms(ret, NULL);
}

#endif  /* __CMMB_CAS_MBBMS_SUPPORT__ */

