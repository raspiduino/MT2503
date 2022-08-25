extern "C"
{
#if ((defined __HTTP_INTERFACE__ ) ||(defined WAP_SEC_SUPPORT))
#include "InetSrvGprot.h"
#include "Wps_struct.h"
#endif 

}

AVK_ADD_ITEM(AVK_NW_WPS_AUTO,L"Auto case",AVK_NW_WPS);
//AVK_ADD_ITEM(AVK_NW_WPS_MANU,L"Manual case",AVK_NW_WPS);


#if ((defined __HTTP_INTERFACE__ ) ||(defined WAP_SEC_SUPPORT))
S32 session_handle = 0;
S32 request_handle = 0;
static void vs_nw_http_show_pop_up();
#endif 


static void vs_nw_wps_003_read_content_req(void);
static void vs_nw_wps_003_dl_progress_ind(void *MsgStruct);
static void vs_nw_wps_003_read_content_rsp(void *MsgStruct);

#if ((defined __HTTP_INTERFACE__ ) ||(defined WAP_SEC_SUPPORT))

/*****************************************************************************
 * FUNCTION
 *  vs_nw_wps_001_end
 * DESCRIPTION
 *  wps connection result confirm
 * PARAMETERS
 *  p       [?]     
 *  ilm_ptr     [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
void vs_nw_wps_001_end(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_rsp_struct *http_rsp = (wps_http_rsp_struct*) p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ClearProtocolEventHandler(MSG_ID_WPS_HTTP_RSP);
    if (http_rsp->result == WPS_OK)
    {
        AVK_LOG_FUN(vs_nw_wps_001_end, AVK_PASS);
        AVK_CASE_RESULT(AVK_PASS);   
        
        if (http_rsp->more)
        {
            vs_seq_num = 0;
            vs_nw_wps_003_read_content_req();
        }
    }
    else
    {
        AVK_LOG_FUN(vs_nw_wps_001_end, AVK_FAIL);
        AVK_CASE_RESULT(AVK_FAIL);   

    }
    AVK_ASYN_DONE();
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_wps_001_rsp
 * DESCRIPTION
 *  send wps connection msg
 * PARAMETERS
 *  MsgStruct       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void vs_nw_wps_001_rsp(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_set_channel_rsp_struct *p = (wps_set_channel_rsp_struct*) MsgStruct;

    wps_http_req_struct *http_req;
    peer_buff_struct *peer_buff_ptr;
    wps_http_req_var_struct http_req_var;
    kal_uint16 pdu_length;

    char url[] = "http://vis-test.ziyitong.com"; 
	CHAR buf[10];
	S32 ret_drv;
	U16 fullname[80];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ClearProtocolEventHandler(MSG_ID_WPS_SET_CHANNEL_RSP);
	memset(&http_req_var, 0, sizeof(wps_http_req_var_struct));
    if (p->result == WPS_OK)
    {
		AVK_LOG_FUN(vs_nw_wps_001_rsp, AVK_PASS);

        http_req = (wps_http_req_struct*) construct_local_para(sizeof(wps_http_req_struct), TD_CTRL|TD_RESET);
        http_req->channel_id = p->channel_id;
        vs_channel_id = p->channel_id;
        http_req->request_id = 0;
        http_req->method = WPS_HTTP_METHOD_GET;
        http_req->more_post = KAL_FALSE;
        http_req->option = WPS_HTTP_OPTION_NO_CACHE | WPS_HTTP_OPTION_DO_NOT_CACHE_REPLY;
        http_req->reply_path[0] = '\0';
        http_req->reply_path[1] = '\0';
        http_req->reply_type = WPS_DATA_TYPE_FILE;

		ret_drv = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
		if (ret_drv >= 0)
		{
			sprintf(buf, "%c:\\", (U8)ret_drv);
			memset(fullname,0,sizeof(fullname));
			mmi_asc_to_ucs2((CHAR*)fullname, buf);		
			mmi_ucs2cat((CHAR*)fullname, (CHAR*)L"wpstest.txt");
			mmi_ucs2cpy((CHAR*)http_req->reply_path, (CHAR*)fullname);
		}
        http_req->reply_segment_len = 1024;

        /* fill url in the wps_http_req_var_struct first */
        http_req_var.request_header_len = 0;
        http_req_var.request_header = NULL;
        http_req_var.post_segment_len = 0;
        http_req_var.post_segment = NULL;
        http_req_var.request_url_len = strlen(url);
        http_req_var.request_url = (kal_uint8*) get_ctrl_buffer((kal_uint16) (http_req_var.request_url_len + 1));
        strcpy((char*)http_req_var.request_url, url);

        /* then get the size of the buffer which needs for the packing */
        pdu_length = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_HTTP_REQ, &http_req_var, NULL);
        peer_buff_ptr = (peer_buff_struct *)construct_peer_buff(pdu_length, 0, 0, TD_CTRL);

        /* then pack the wps_http_req_var_struct into the peer buffer */
        wps_pun_var_part(WPS_PUN_PACK, MSG_ID_WPS_HTTP_REQ, &http_req_var, (kal_uint8 *)get_peer_buff_pdu(peer_buff_ptr, &pdu_length));
        free_ctrl_buffer(http_req_var.request_url);

        /* send message */
       
		msg_send6(MOD_MMI, MOD_WPS, WPS_APP_SAP, MSG_ID_WPS_HTTP_REQ, (local_para_struct*) http_req, peer_buff_ptr);

        SetProtocolEventHandler((PsFuncPtr) vs_nw_wps_001_end, MSG_ID_WPS_HTTP_RSP);
        SetProtocolEventHandler((PsFuncPtr) vs_nw_wps_003_dl_progress_ind, MSG_ID_WPS_DL_PROGRESS_IND);
        SetProtocolEventHandler((PsFuncPtr) vs_nw_wps_003_read_content_rsp, MSG_ID_WPS_READ_CONTENT_RSP);
    }

}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_wps_001_req
 * DESCRIPTION
 *  send set channel id of wps
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_ASYN_CASE(AVK_NW_WPS_AUTO_CASE1, AVK_NW_WPS_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_set_channel_req_struct *set_channel_req;
    wps_set_channel_req_var_struct set_channel_req_var;
    peer_buff_struct *peer_buff_ptr = NULL;
    U16 len, pdu_length;
    U16 msg_len; 
	U8	ref_count;

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
    pdu_length = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_SET_CHANNEL_REQ, &set_channel_req_var, NULL);

    if (pdu_length > 0)
    {
        peer_buff_ptr = (peer_buff_struct *)construct_peer_buff(pdu_length, 0, 0, TD_RESET);
        if (wps_pun_var_part
            (WPS_PUN_PACK, MSG_ID_WPS_SET_CHANNEL_REQ, &set_channel_req_var,
             (kal_uint8 *)get_peer_buff_pdu(peer_buff_ptr, &len)) != pdu_length)
        {
            free_peer_buff(peer_buff_ptr);
            peer_buff_ptr = NULL;
        }
    }

    /* send message */
	msg_send6(MOD_MMI, MOD_WPS, WPS_APP_SAP, MSG_ID_WPS_SET_CHANNEL_REQ, (local_para_struct*) set_channel_req, peer_buff_ptr);

    /* set callback function for the message */
    SetProtocolEventHandler((PsFuncPtr) vs_nw_wps_001_rsp, MSG_ID_WPS_SET_CHANNEL_RSP);
}

/*****************************************************************************
 * FUNCTION
 *  vs_nw_wps_002_unset_channel_rsp
 * DESCRIPTION
 *  wsp response message handler
 * PARAMETERS
 *  MsgStruct       [?]         
 *  index(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vs_nw_wps_002_unset_channel_rsp(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_unset_channel_rsp_struct *p = (wps_unset_channel_rsp_struct*) MsgStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p->channel_id == vs_channel_id && p->result == WPS_OK)
    {
        AVK_LOG_FUN(vs_nw_wps_002_unset_channel_rsp, AVK_PASS);
        AVK_CASE_RESULT(AVK_PASS);   

    }
    else
    {
        AVK_LOG_FUN(vs_nw_wps_002_unset_channel_rsp, AVK_FAIL);
        AVK_CASE_RESULT(AVK_FAIL);   

    }

    ClearProtocolEventHandler(MSG_ID_WPS_UNSET_CHANNEL_RSP);

    AVK_ASYN_DONE();
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_wps_002_unset_channel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_ASYN_CASE(AVK_NW_WPS_AUTO_CASE1_2, AVK_NW_WPS_AUTO_CASE1)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_unset_channel_req_struct *unset_channel_req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    unset_channel_req = (wps_unset_channel_req_struct*)
        construct_local_para(sizeof(wps_unset_channel_req_struct), TD_CTRL);

    unset_channel_req->channel_id = vs_channel_id;
    msg_send6(MOD_MMI, MOD_WPS, WPS_APP_SAP, MSG_ID_WPS_UNSET_CHANNEL_REQ, (local_para_struct*) unset_channel_req, NULL);

    SetProtocolEventHandler((PsFuncPtr) vs_nw_wps_002_unset_channel_rsp, MSG_ID_WPS_UNSET_CHANNEL_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_wps_003_read_content_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_nw_wps_003_read_content_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_read_content_req_struct *read_content_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    read_content_req =
        (wps_read_content_req_struct*) construct_local_para(sizeof(wps_read_content_req_struct), TD_CTRL);

    read_content_req->channel_id = vs_channel_id;

    read_content_req->request_id = vs_request_id;
    read_content_req->seq_num = ++vs_seq_num;
    read_content_req->read_segnemtn_len = 512;  /* assign the default length to read for more content */

    msg_send6(MOD_MMI, MOD_WPS, WPS_APP_SAP, MSG_ID_WPS_READ_CONTENT_REQ, (local_para_struct*) read_content_req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_wps_003_read_content_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_nw_wps_003_read_content_rsp(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_read_content_rsp_struct *p = (wps_read_content_rsp_struct*) MsgStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p->result == WPS_OK)
    {
        if (p->more)
        {
            vs_nw_wps_003_read_content_req();
        }
        else
        {
            AVK_LOG_FUN(vs_nw_wps_003_read_content_rsp, AVK_PASS);
            AVK_CASE_RESULT(AVK_PASS);            
        }
        return;
    }

    AVK_LOG_FUN(vs_nw_wps_003_read_content_rsp, AVK_FAIL);
    AVK_CASE_RESULT(AVK_FAIL);
    AVK_ASYN_DONE();


    return;
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_wps_003_dl_progress_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_nw_wps_003_dl_progress_ind(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_dl_progress_ind_struct *p = (wps_dl_progress_ind_struct*) MsgStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vs_dl_status = p->status;
    if (p->status == WPS_DL_STATUS_COMPLETE)
    {
        AVK_LOG_FUN(vs_nw_wps_003_dl_progress_ind, AVK_PASS);
        AVK_CASE_RESULT(AVK_PASS);
    }
    else if (p->status == WPS_DL_STATUS_DOWNLOADING)
    {
		wps_dl_progress_res_struct *progress_res;
		/*----------------------------------------------------------------*/
		/* Code Body                                                                                               */
		/*----------------------------------------------------------------*/
		progress_res = (wps_dl_progress_res_struct *)construct_local_para(sizeof(wps_dl_progress_res_struct), TD_CTRL|TD_RESET);
		progress_res->request_id = p->request_id;
		progress_res->channel_id = vs_channel_id;
		progress_res->seq_num = p->seq_num;
		
        msg_send6(MOD_MMI, MOD_WPS, WPS_APP_SAP, MSG_ID_WPS_DL_PROGRESS_RES, (local_para_struct *)progress_res, NULL);

        AVK_LOG_FUN(vs_nw_wps_003_dl_progress_ind, AVK_PASS);
        AVK_CASE_RESULT(AVK_PASS);

    }
    else if (p->status == WPS_DL_STATUS_ABORT)
    {
        AVK_LOG_FUN(vs_nw_wps_003_dl_progress_ind, AVK_PASS);
        AVK_CASE_RESULT(AVK_PASS);
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_wps_send_wps_http_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  http_method     [IN]        
 *  url             [?]         
 *  post_data       [?]         
 *  file_path       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_nw_wps_send_wps_http_req(U8 http_method, CHAR *url, CHAR *post_data, CHAR *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_req_struct *http_req;
    wps_http_req_var_struct http_req_var;
    peer_buff_struct *peer_buff_ptr = NULL;
    U16 pdu_length;
    U16 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    http_req = (wps_http_req_struct*) construct_local_para(sizeof(wps_http_req_struct), TD_CTRL);
    http_req->channel_id = vs_channel_id;
    http_req->request_id = vs_request_id;
    http_req->method = http_method;
    http_req->option = WPS_HTTP_OPTION_ALWAYS_CACHE;    /* WPS_HTTP_OPTION_NO_CACHE; */

    memset(&http_req_var,0, sizeof(wps_http_req_var_struct));

    http_req_var.request_url_len = (kal_uint32) strlen(url);
    http_req_var.request_url = (kal_uint8*) get_ctrl_buffer((kal_uint16) (http_req_var.request_url_len + 1));
    strcpy((char*)http_req_var.request_url, url);
    http_req_var.request_header_len = 0;
    http_req_var.request_header = NULL;

    if (http_method == WPS_HTTP_METHOD_POST)
    {
        ASSERT(post_data != NULL);
        http_req->reply_type = WPS_DATA_TYPE_BUFFER;
        http_req->reply_segment_len = 0;    /* no use here */
        http_req->post_type = WPS_DATA_TYPE_BUFFER;
        http_req->post_path[0] = '\0';
        http_req->post_path[1] = '\0';
        http_req->post_total_len = strlen(post_data);
        http_req->more_post = MMI_FALSE;
        http_req_var.post_segment_len = strlen(post_data);
        http_req_var.post_segment = (kal_uint8*) post_data;
        http_req_var.request_header_len = 0;
        http_req_var.request_header = NULL;
    }
    else
    {
        /* ASSERT(file_path != NULL && mmi_ucs2strlen((S8 *) file_path) < 256); */
        http_req->reply_type = WPS_DATA_TYPE_FILE;
        mmi_ucs2cpy((CHAR*) http_req->reply_path, (CHAR*) L"D:\\Audio\\123.txt"); /* (S8 *) file_path); */
        http_req->reply_segment_len = 512;
        http_req->post_type = WPS_DATA_TYPE_BUFFER;
        http_req->post_path[0] = '\0';
        http_req->post_path[1] = '\0';
        http_req->post_total_len = 0;
        http_req->more_post = MMI_FALSE;
        http_req_var.post_segment_len = 0;
        http_req_var.post_segment = NULL;
    }

    pdu_length = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_HTTP_REQ, &http_req_var, NULL);

    if (pdu_length > 0)
    {
        peer_buff_ptr = (peer_buff_struct *)construct_peer_buff(pdu_length, 0, 0, TD_RESET);
        if (wps_pun_var_part(WPS_PUN_PACK, MSG_ID_WPS_HTTP_REQ, &http_req_var, (kal_uint8 *)get_peer_buff_pdu(peer_buff_ptr, &len)) !=
            pdu_length)
        {
            free_peer_buff(peer_buff_ptr);
            peer_buff_ptr = NULL;
        }
    }
    free_ctrl_buffer(http_req_var.request_url);

    msg_send6(MOD_MMI, MOD_WPS, WPS_APP_SAP, MSG_ID_WPS_HTTP_REQ, (local_para_struct*) http_req, peer_buff_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_wps_003_http_auth_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void vs_nw_wps_003_http_auth_ind(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_auth_res_struct *http_auth_res;
    //wps_http_auth_ind_struct *http_auth_ind = (wps_http_auth_ind_struct*) MsgStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	http_auth_res = (wps_http_auth_res_struct*) construct_local_para(sizeof(wps_http_auth_res_struct), TD_CTRL);
	http_auth_res->channel_id = vs_channel_id;
	http_auth_res->request_id = vs_request_id;
	strcpy((CHAR*) http_auth_res->username, (CHAR*) "ajt");
	strcpy((CHAR*) http_auth_res->password, (CHAR*) "dmw");

    msg_send6(MOD_MMI, MOD_WPS, WPS_APP_SAP, MSG_ID_WPS_HTTP_AUTH_RES, (local_para_struct*) http_auth_res, NULL);
	
    AVK_LOG_FUN(vs_nw_wps_003_http_auth_ind, AVK_PASS);
    AVK_CASE_RESULT(AVK_PASS);

}

void vs_nw_wps_003_end(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //wps_http_rsp_struct *http_rsp = (wps_http_rsp_struct*) p;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AVK_LOG_FUN(vs_nw_wps_003_end, AVK_PASS);
    AVK_CASE_RESULT(AVK_PASS);
    AVK_ASYN_DONE();
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_wps_003_http_auth
 * DESCRIPTION
 *  send http req msg
 * PARAMETERS
 *  MsgStruct       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void vs_nw_wps_003_http_auth(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_set_channel_rsp_struct *p = (wps_set_channel_rsp_struct*) MsgStruct;
    char url[] = "http://210.61.82.14/";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p == NULL || (p != NULL && p->result == WPS_OK))
    {
        AVK_LOG_FUN(vs_nw_wps_003_http_auth, AVK_PASS);
        vs_nw_wps_send_wps_http_req(WPS_HTTP_METHOD_GET, (CHAR*) url, NULL, NULL);
        SetProtocolEventHandler((PsFuncPtr) vs_nw_wps_003_end, MSG_ID_WPS_HTTP_RSP);
        SetProtocolEventHandler((PsFuncPtr) vs_nw_wps_003_http_auth_ind, MSG_ID_WPS_HTTP_AUTH_IND);

    }
    else
    {
        AVK_LOG_FUN(vs_nw_wps_003_http_auth, AVK_FAIL);
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();
    }
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_wps_set_chanel
 * DESCRIPTION
 *  send set channel id of wps
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_nw_wps_set_chanel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_set_channel_req_struct *set_channel_req;
    wps_set_channel_req_var_struct set_channel_req_var;
    peer_buff_struct *peer_buff_ptr = NULL;
    U16 len, pdu_length;
    U16 msg_len, ref_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* construct message */
    set_channel_req = (wps_set_channel_req_struct*) construct_local_para(sizeof(wps_set_channel_req_struct), TD_CTRL);
    msg_len = set_channel_req->msg_len;
    ref_count = set_channel_req->ref_count;
    memset(set_channel_req, 0, sizeof(wps_set_channel_req_struct));
    set_channel_req->msg_len = msg_len;
    set_channel_req->ref_count = (kal_uint8)ref_count;
    set_channel_req->app_id = (kal_uint8)APP_DEVAPP;
    set_channel_req->use_default = KAL_TRUE;

    set_channel_req_var.static_header_len = 0;
    set_channel_req_var.static_header = NULL;
    pdu_length = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_SET_CHANNEL_REQ, &set_channel_req_var, NULL);

    if (pdu_length > 0)
    {
        peer_buff_ptr = (peer_buff_struct *)construct_peer_buff(pdu_length, 0, 0, TD_RESET);
        if (wps_pun_var_part
            (WPS_PUN_PACK, MSG_ID_WPS_SET_CHANNEL_REQ, &set_channel_req_var,
             (kal_uint8 *)get_peer_buff_pdu(peer_buff_ptr, &len)) != pdu_length)
        {
            free_peer_buff(peer_buff_ptr);
            peer_buff_ptr = NULL;
        }
    }

    /* send message */
	msg_send6(MOD_MMI, MOD_WPS, WPS_APP_SAP, MSG_ID_WPS_SET_CHANNEL_REQ, (local_para_struct*) set_channel_req, peer_buff_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_wps_003
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_ASYN_CASE(AVK_NW_WPS_AUTO_CASE3, AVK_NW_WPS_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vs_channel_id == 0xFF)
    {
        vs_nw_wps_set_chanel();
        /* set callback function for the message */
        SetProtocolEventHandler((PsFuncPtr) vs_nw_wps_003_http_auth, MSG_ID_WPS_SET_CHANNEL_RSP);
    }
    else
    {
        vs_nw_wps_003_http_auth(NULL);
    }
}



/*****************************************************************************
 * FUNCTION
 *  vs_nw_wps_004_clear_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_nw_wps_004_clear_rsp(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_clear_rsp_struct *p = (wps_clear_rsp_struct*) MsgStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p->result == WPS_OK)
    {
        AVK_LOG_FUN(vs_nw_wps_004_clear_rsp, AVK_PASS);
        AVK_CASE_RESULT(AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(vs_nw_wps_004_clear_rsp, AVK_FAIL);
        AVK_CASE_RESULT(AVK_FAIL);
    }

    AVK_ASYN_DONE();

}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_wps_006_clear_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_ASYN_CASE(AVK_NW_WPS_AUTO_CASE3_2, AVK_NW_WPS_AUTO_CASE3)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_clear_req_struct *clear_cache;
    wps_clear_req_var_struct clear_req_var;
    kal_uint16 pdu_length;
    peer_buff_struct *peer_buff_ptr;
    char url[] = "http://vis-test.ziyitong.com/";   /* "http://210.61.82.14/"; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_cache = (wps_clear_req_struct*) construct_local_para(sizeof(wps_clear_req_struct), TD_RESET);

    clear_cache->channel_id = vs_channel_id;
    clear_cache->request_id = vs_request_id;
    clear_cache->operation = WPS_CLEAR_CACHE_URL_MATCH;

    clear_req_var.cache_url = (kal_uint8*) url;
    clear_req_var.cache_url_len = strlen(url);

    pdu_length = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_CLEAR_REQ, &clear_req_var, NULL);
    peer_buff_ptr = (peer_buff_struct *)construct_peer_buff(pdu_length, 0, 0, TD_RESET);
    wps_pun_var_part(WPS_PUN_PACK, MSG_ID_WPS_CLEAR_REQ, &clear_req_var, (kal_uint8 *)get_peer_buff_pdu(peer_buff_ptr, &pdu_length));

    msg_send6(MOD_MMI, MOD_WPS, WPS_APP_SAP, MSG_ID_WPS_CLEAR_REQ, (local_para_struct*) clear_cache, peer_buff_ptr);

    SetProtocolEventHandler((PsFuncPtr) vs_nw_wps_004_clear_rsp, MSG_ID_WPS_CLEAR_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_wps_005_post_content_res
 * DESCRIPTION
 *  
 * PARAMETERS
 *  post_data       [?]         
 *  post_len        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vs_nw_wps_005_post_content_res(kal_uint8 *post_data, kal_uint32 post_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_post_content_res_struct *http_post_rsp;
    peer_buff_struct *peer_buff_ptr;
    wps_post_content_res_var_struct http_post_rsp_var;

    kal_uint16 pdu_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    http_post_rsp = (wps_post_content_res_struct*) construct_local_para(sizeof(wps_post_content_res_struct), TD_CTRL);

    http_post_rsp->channel_id = vs_channel_id;
    http_post_rsp->request_id = vs_request_id;
    http_post_rsp->seq_num = 0;
    http_post_rsp->more = KAL_FALSE;
    http_post_rsp_var.post_segment_len = post_len;
    http_post_rsp_var.post_segment = post_data;

    pdu_length = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_POST_CONTENT_RES, &http_post_rsp_var, NULL);
    peer_buff_ptr = (peer_buff_struct *)construct_peer_buff(pdu_length, 0, 0, TD_CTRL);

    wps_pun_var_part(
        WPS_PUN_PACK,
        MSG_ID_WPS_POST_CONTENT_RES,
        &http_post_rsp_var,
        (kal_uint8 *)get_peer_buff_pdu(peer_buff_ptr, &pdu_length));

    msg_send6(MOD_MMI, MOD_WPS, WPS_APP_SAP, MSG_ID_WPS_POST_CONTENT_RES, (local_para_struct*) http_post_rsp, peer_buff_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_wps_005_post_content_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void vs_nw_wps_005_post_content_ind(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_post_content_ind_struct *p = (wps_post_content_ind_struct*) MsgStruct;
    char post_data[] = "abcdefg";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vs_seq_num = p->seq_num;

    if (p->result == WPS_OK)
    {
        AVK_LOG_FUN(vs_nw_wps_005_post_content_ind, AVK_PASS);
        vs_nw_wps_005_post_content_res((kal_uint8*) post_data, strlen(post_data));
    }
    else
    {
        AVK_LOG_FUN(vs_nw_wps_005_post_content_ind, AVK_FAIL);
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();
    }

}

void vs_nw_wps_005_end(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //wps_http_rsp_struct *http_rsp = (wps_http_rsp_struct*) p;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AVK_LOG_FUN(MSG_ID_WPS_SET_CHANNEL_RSP, AVK_PASS);
    AVK_CASE_RESULT(AVK_PASS);
    AVK_ASYN_DONE();
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_wps_005_post_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void vs_nw_wps_005_post_req(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_set_channel_rsp_struct *p = (wps_set_channel_rsp_struct*) MsgStruct;
    char url[] = "http://210.61.82.14/";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p == NULL || (p != NULL && p->result == WPS_OK))
    {
        vs_nw_wps_send_wps_http_req(WPS_HTTP_METHOD_POST, (CHAR*) url, "abcdefghijklmn", NULL);
        SetProtocolEventHandler((PsFuncPtr) vs_nw_wps_005_end, MSG_ID_WPS_HTTP_RSP);
        SetProtocolEventHandler((PsFuncPtr) vs_nw_wps_005_post_content_ind, MSG_ID_WPS_POST_CONTENT_IND);
    }
    else
    {
        AVK_LOG_FUN(vs_nw_wps_005_post_req, AVK_FAIL);
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();
        
    }
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_wps_005
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_ASYN_CASE(AVK_NW_WPS_AUTO_CASE5, AVK_NW_WPS_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vs_channel_id == 0xFF)
    {
        vs_nw_wps_set_chanel();
        /* set callback function for the message */
        SetProtocolEventHandler((PsFuncPtr) vs_nw_wps_005_post_req, MSG_ID_WPS_SET_CHANNEL_RSP);
    }
    else
    {
        vs_nw_wps_005_post_req(NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_wps_008_status_query_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_nw_wps_008_status_query_rsp(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_status_query_rsp_struct *p = (wps_status_query_rsp_struct*) MsgStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(MSG_ID_WPS_STATUS_QUERY_RSP);
    if (p->status == KAL_TRUE)
    {
        AVK_LOG_FUN(vs_nw_wps_008_status_query_rsp, AVK_PASS);
        AVK_CASE_RESULT(AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(vs_nw_wps_008_status_query_rsp, AVK_FAIL);
        AVK_CASE_RESULT(AVK_FAIL);        
    }
    AVK_ASYN_DONE();
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_wps_009_ready_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_nw_wps_008_ready_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //wps ready
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_wps_008_status_query_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_ASYN_CASE(AVK_NW_WPS_AUTO_CASE6, AVK_NW_WPS_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_send6(MOD_MMI, MOD_WPS, WPS_APP_SAP, MSG_ID_WPS_STATUS_QUERY_REQ, NULL, NULL);

    SetProtocolEventHandler((PsFuncPtr) vs_nw_wps_008_status_query_rsp, MSG_ID_WPS_STATUS_QUERY_RSP);
    SetProtocolEventHandler((PsFuncPtr) vs_nw_wps_008_ready_ind, MSG_ID_WPS_READY_IND);
}

#endif /* ((defined __HTTP_INTERFACE__ ) ||(defined WAP_SEC_SUPPORT)) */

