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
 *  Sample_Wps.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Sample code for WPS
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/
#include "APPSDKFrameworkGProt.h"
#include "APPSDKSystemServiceGProt.h"
#include "APPSDKNetworkGProt.h"

typedef struct
{
	U8 channel_id;
	U8 request_id;
	U8 seq_num;
	U32	data_size;
	U32 account_id;
} mmi_sample_wps_cntx_struct;

mmi_sample_wps_cntx_struct g_sample_wps_cntx;

/****************************************************************************
*
*  [Sample]
*  Purpose   : How to create HTTP session and get data from network 
*  Function  : How to send message to WPS module to download data  
*  Notice    : 
*  Branch    : 08A, 08B, MAUI
*  API Ref   : 
*               
*  
*
*****************************************************************************/

static void mmi_sample_wps_set_channel_rsp(void *MsgStruct);
static void mmi_sample_wps_http_req(U8 channel_id, S8 *url);
static void mmi_sample_wps_http_rsp(void *MsgStruct, int mod_id , void *peer_buf);
static void mmi_sample_wps_read_content_req(void);
static void mmi_sample_wps_read_content_rsp(void *MsgStruct, int mod_id , void *peer_buf);

/*****************************************************************************
 * FUNCTION
 *  mmi_sample_wps_set_channel_req
 * DESCRIPTION
 *  send set channel request to WPS module
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sample_wps_set_channel_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    wps_set_channel_req_struct *set_channel_req;
    wps_set_channel_req_var_struct set_channel_req_var;
    peer_buff_struct *peer_buff_ptr = NULL;
    U16 msg_len, len, pdu_length;
    U8 ref_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* construct message */
    set_channel_req = (wps_set_channel_req_struct*) construct_local_para(sizeof(wps_set_channel_req_struct), TD_CTRL);
    msg_len = set_channel_req->msg_len;
    ref_count = set_channel_req->ref_count;
    memset(set_channel_req, 0, sizeof(wps_set_channel_req_struct));
    set_channel_req->msg_len = msg_len;
    set_channel_req->ref_count = ref_count;
    set_channel_req->app_id = (kal_uint8)APP_DEVAPP;
    set_channel_req->use_default = KAL_TRUE;

    set_channel_req_var.static_header_len = 0;
    set_channel_req_var.static_header = NULL;

	/*pack peer buffer */
    pdu_length = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_SET_CHANNEL_REQ, &set_channel_req_var, NULL);
    if (pdu_length > 0)
    {
        peer_buff_ptr = construct_peer_buff(pdu_length, 0, 0, TD_RESET);
        if (wps_pun_var_part(WPS_PUN_PACK, MSG_ID_WPS_SET_CHANNEL_REQ, &set_channel_req_var,
             get_pdu_ptr(peer_buff_ptr, &len)) != pdu_length)
        {
            free_peer_buff(peer_buff_ptr);
            peer_buff_ptr = NULL;
        }
    }

    ilm_ptr = allocate_ilm(MOD_MMI); /*allocate memory*/
    ilm_ptr->local_para_ptr = (local_para_struct*) set_channel_req;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buff_ptr;
    ilm_ptr->msg_id = MSG_ID_WPS_SET_CHANNEL_REQ;
    /* send message */
    SEND_ILM(MOD_MMI, MOD_WPS, WPS_APP_SAP, ilm_ptr);
    
	/* set callback function for the message */
    SetProtocolEventHandler((PsFuncPtr) mmi_sample_wps_set_channel_rsp, MSG_ID_WPS_SET_CHANNEL_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_wps_set_channel_rsp
 * DESCRIPTION
 *  handle wps module "set channel" response
 * PARAMETERS
 *  MsgStruct       [IN]     response date struct 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sample_wps_set_channel_rsp(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_set_channel_rsp_struct *p = (wps_set_channel_rsp_struct*) MsgStruct;
    S8 url[] = "http://.........."; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p->result == WPS_OK)
    {
		/* success in set channel */

		g_sample_wps_cntx.channel_id = p->channel_id;
		/*send http request*/
		mmi_sample_wps_http_req(g_sample_wps_cntx.channel_id, url);
    }
	else
	{
		/* failed case */
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sample_wps_http_req
 * DESCRIPTION
 *  send http request to WPS module
 * PARAMETERS
 *  channel_id		[IN]	set channel response result
 *  url				[IN]	request http URL
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sample_wps_http_req(U8 channel_id, S8 *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    wps_http_req_struct *http_req;
    peer_buff_struct *peer_buff_ptr = NULL;
    wps_http_req_var_struct http_req_var;
    U16 pdu_length, len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* construct message */
	http_req = (wps_http_req_struct*) construct_local_para(sizeof(wps_http_req_struct), TD_CTRL);
	http_req->request_id = 0;
	http_req->method = WPS_HTTP_METHOD_GET;
	http_req->more_post = KAL_FALSE;
	http_req->option = WPS_HTTP_OPTION_NO_CACHE | WPS_HTTP_OPTION_DO_NOT_CACHE_REPLY;
	http_req->reply_path[0] = '\0';
	http_req->reply_path[1] = '\0';
	http_req->reply_type = WPS_DATA_TYPE_BUFFER;
	http_req->reply_segment_len = 512;
	
	/* fill url in the wps_http_req_var_struct first */
	http_req_var.request_header_len = 0;
	http_req_var.request_header = NULL;
	http_req_var.post_segment_len = 0;
	http_req_var.post_segment = NULL;
	http_req_var.request_url_len = strlen((char *)url);
	/*allocate memory*/
	http_req_var.request_url = (kal_uint8 *) get_ctrl_buffer((kal_uint16) (http_req_var.request_url_len + 1));
	strcpy((char *)http_req_var.request_url, (char *)url);
	
	/* then get the size of the buffer which needs for the packing */

	/*pack peer buffer */
	pdu_length = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_HTTP_REQ, &http_req_var, NULL);
    if (pdu_length > 0)
    {
		peer_buff_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);
		/* then pack the wps_http_req_var_struct into the peer buffer */
		if (wps_pun_var_part(WPS_PUN_PACK, MSG_ID_WPS_HTTP_REQ, &http_req_var, get_pdu_ptr(peer_buff_ptr, &len)) !=
			pdu_length)
        {
            free_peer_buff(peer_buff_ptr);
            peer_buff_ptr = NULL;
        }
    }
	
	/*free memory*/
	free_ctrl_buffer(http_req_var.request_url);
	
	ilm_ptr = allocate_ilm(MOD_MMI); /*allocate memory*/
	ilm_ptr->local_para_ptr = (local_para_struct*) http_req;
	ilm_ptr->msg_id = MSG_ID_WPS_HTTP_REQ;
	ilm_ptr->peer_buff_ptr = peer_buff_ptr;
	/* send message */
	SEND_ILM(MOD_MMI, MOD_WPS, WPS_APP_SAP, ilm_ptr);

	/* set callback function for the message */
	SetProtocolEventHandler((PsFuncPtr) mmi_sample_wps_http_rsp, MSG_ID_WPS_HTTP_RSP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sample_wps_http_rsp
 * DESCRIPTION
 *  wps connection result confirm
 * PARAMETERS
 *  MsgStruct       [IN]     response date struct 
 *  Mod_id			[IN]     Module ID 
 *  Peer_buf		[IN]     ILM struct 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sample_wps_http_rsp(void *MsgStruct, int mod_id , void *peer_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_rsp_struct *http_rsp = (wps_http_rsp_struct*) MsgStruct;
    wps_http_rsp_var_struct http_rsp_var;
    U16 pdu_length = 0;
    ilm_struct *ilm_info = (ilm_struct*)peer_buf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (http_rsp->result == WPS_OK)
    {/* success in http request */

		/* segment number: start from 1 */
		g_sample_wps_cntx.seq_num = 1;
		
		/*unpack peer buffer*/
        if (wps_pun_var_part(WPS_PUN_UNPACK, MSG_ID_WPS_HTTP_RSP, &http_rsp_var, get_pdu_ptr(ilm_info->peer_buff_ptr, &pdu_length)) > 0)
        {
            /* recode data size */
            g_sample_wps_cntx.data_size = http_rsp_var.reply_segment_len;
			
			/* Add some code to read data from http_rsp_var.reply_segment, 
			   length is http_rsp_var.reply_segment_len */

		}			
        if (http_rsp->more)
        {
			/* more contents need to read from http request*/
            mmi_sample_wps_read_content_req();
        }
    }
    else
    {
		/* failed case */
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sample_wps_read_content_req
 * DESCRIPTION
 *  send read content to WPS module
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sample_wps_read_content_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    wps_read_content_req_struct *read_content_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* construct message */
    read_content_req =
        (wps_read_content_req_struct*) construct_local_para(sizeof(wps_read_content_req_struct), TD_CTRL);

    read_content_req->channel_id = g_sample_wps_cntx.channel_id;
    read_content_req->request_id = g_sample_wps_cntx.request_id;
    read_content_req->seq_num = g_sample_wps_cntx.seq_num;
    read_content_req->read_segnemtn_len = 512;  /* assign the default length to read for more content */

    ilm_ptr = allocate_ilm(MOD_MMI); /*allocate memory*/
    ilm_ptr->msg_id = MSG_ID_WPS_READ_CONTENT_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) read_content_req;
    ilm_ptr->peer_buff_ptr = NULL;

	/* send message*/
    SEND_ILM(MOD_MMI, MOD_WPS, WPS_APP_SAP, ilm_ptr);

	/* set callback function for the message */
	SetProtocolEventHandler((PsFuncPtr) mmi_sample_wps_read_content_rsp, MSG_ID_WPS_READ_CONTENT_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_wps_read_content_rsp
 * DESCRIPTION
 *  WPS module response about read content request
 * PARAMETERS
 *  MsgStruct       [IN]     response date struct 
 *  Mod_id			[IN]     Module ID 
 *  Peer_buf		[IN]     ILM struct 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sample_wps_read_content_rsp(void *MsgStruct, int mod_id , void *peer_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_read_content_rsp_struct *p = (wps_read_content_rsp_struct*) MsgStruct;
    wps_read_content_rsp_var_struct read_content_rsp_var;
    U16 pdu_length = 0;
    ilm_struct *ilm_info = (ilm_struct*)peer_buf;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p->result == WPS_OK)
    {
		g_sample_wps_cntx.seq_num ++;
		/*unpack peer buffer*/
        if (wps_pun_var_part(WPS_PUN_UNPACK, MSG_ID_WPS_READ_CONTENT_RSP, &read_content_rsp_var, get_pdu_ptr(ilm_info->peer_buff_ptr, &pdu_length)) > 0)
        {
            /* calculate data size */
            g_sample_wps_cntx.data_size += read_content_rsp_var.reply_segment_len;
            
			/* Add some code to read data from read_content_rsp_var.reply_segment, 
			   length is read_content_rsp_var.reply_segment_len */

		}
        if (p->more)
        {
			/* more contents need to read*/
            mmi_sample_wps_read_content_req();
        }
        else
        {
			/* wps read contents is over */
        }
    }

    return;
}



