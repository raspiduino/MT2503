
#include "MMI_features.h"
#include "MMIDataType.h"
#include "MMI_include.h"
#include "MainMenuDef.h"
#include "Mmi_rp_app_komoxo_def.h"
#include "app_ltlcom.h"
#include "wps_struct.h"

#include "kmx_os.h"

/*****************************************************************************
 *
 * Global definitions.
 *
 *****************************************************************************/

#define KMX_ENABLE_DEBUG         1

#define KMX_REPLY_SEGMENT_LEN    1024


static U8 g_kmx_channel_id;
static KMX_NET_RESPONSE_HANDLER g_kmx_net_response_handler;

static KMXSTATUS mmi_kmx_handle_event(int event, KMXPARAM param1, KMXPARAM param2);

#if KMX_ENABLE_DEBUG

void kmx_debug_hex_dump(const void* ptr, unsigned int len)
{
    char buf[128];
    const unsigned char* p;

    sprintf(buf, "KMX memory hex dump, ptr=%08X, len=%d\n", (unsigned int)ptr, len);
    kal_prompt_trace(MOD_CC, buf);

    p = ptr;
    while (len > 0)
    {
        unsigned int i, s, n;

        s = len;
        if (s > 16)
            s = 16;

        n = 0;
        for (i = 0; i < s; i++)
        {
            sprintf(buf + n, " %02X", p[i]);
            n += 3;
        }
        buf[n] = 0;

        kal_prompt_trace(MOD_CC, "%s\n", buf);

        len -= s;
        p += s;
    }
}

void kmx_debug_txt_dump(const void* ptr, unsigned int len)
{
    char buf[128];
    const unsigned char* p;

    sprintf(buf, "KMX memory txt dump, ptr=%08X, len=%d\n", (unsigned int)ptr, len);
    kal_prompt_trace(MOD_CC, buf);

    p = ptr;
    while (len > 0)
    {
        unsigned int n;

        n = 0;
        while (n < 80 && len > 0)
        {
            if (*p >= 0x20 && *p <= 0x7F)
            {
                buf[n] = *p;
                n++;
            }
            else
            {
                sprintf(buf + n, "\\%02X", *p);
                n += 3;
            }
            p++;
            len--;
        }
        buf[n] = 0;

        kal_prompt_trace(MOD_CC, "%s\n", buf);
    }
}

#endif

/*****************************************************************************
 *
 * Network support functions.
 *
 *****************************************************************************/

#if defined (__MMI_DOWNLOAD_AGENT__) && defined(BROWSER_SUPPORT)
static void mmi_kmx_set_channel_rsp(void* message);
static void mmi_kmx_unset_channel_rsp(void* message);
static void mmi_kmx_http_rsp(void* message, int mod_id , void* peer_buf);
static void mmi_kmx_read_content_req(unsigned char request_id, unsigned char seq_num);
static void mmi_kmx_read_content_rsp(void* message, int mod_id , void* peer_buf);
static void mmi_kmx_cancel_http_rsp(void* message);

static void mmi_kmx_register_network_event_handler(void)
{
    SetProtocolEventHandler((PsFuncPtr)mmi_kmx_set_channel_rsp,      MSG_ID_WPS_SET_CHANNEL_RSP);
    SetProtocolEventHandler((PsFuncPtr)mmi_kmx_unset_channel_rsp,    MSG_ID_WPS_UNSET_CHANNEL_RSP);
	SetProtocolEventHandler((PsFuncPtr)mmi_kmx_http_rsp,             MSG_ID_WPS_HTTP_RSP);
	SetProtocolEventHandler((PsFuncPtr)mmi_kmx_read_content_rsp,     MSG_ID_WPS_READ_CONTENT_RSP);
	SetProtocolEventHandler((PsFuncPtr)mmi_kmx_cancel_http_rsp,      MSG_ID_WPS_CANCEL_RSP);
}

static void mmi_kmx_clear_network_event_handler(void)
{
    SetProtocolEventHandler(0, MSG_ID_WPS_SET_CHANNEL_RSP);
    SetProtocolEventHandler(0, MSG_ID_WPS_UNSET_CHANNEL_RSP);
	SetProtocolEventHandler(0, MSG_ID_WPS_HTTP_RSP);
	SetProtocolEventHandler(0, MSG_ID_WPS_READ_CONTENT_RSP);
	SetProtocolEventHandler(0, MSG_ID_WPS_CANCEL_RSP);
}
#endif

KMXSTATUS kmx_os_net_open_channel(void)
{
    #if defined (__MMI_DOWNLOAD_AGENT__) && defined(BROWSER_SUPPORT) 
    wps_set_channel_req_struct* req;
    peer_buff_struct* peer;
    wps_set_channel_req_var_struct var;

    #if KMX_ENABLE_DEBUG
        kal_prompt_trace(MOD_CC, "KMX: kmx_os_net_open_channel\n");
    #endif

    g_kmx_channel_id = 0;

    /* construct message */

    {
        U16 msg_len;
        U8 ref_count;

        req = (wps_set_channel_req_struct*) construct_local_para(sizeof(wps_set_channel_req_struct), TD_CTRL);
        if (!req)
            return KMX_STATUS_OUT_OF_MEMORY;

        msg_len = req->msg_len;
        ref_count = req->ref_count;

        memset(req, 0, sizeof(wps_set_channel_req_struct));

        req->msg_len = msg_len;
        req->ref_count = ref_count;
        req->app_id = (kal_uint8)APP_KOMOXO;
        req->use_default = KAL_TRUE;
        req->timeout = 60;
    }

	/* pack peer buffer */

    {
        U16 len, pdu_length;

        var.static_header = 0;
        var.static_header_len = 0;

        peer = 0;
        pdu_length = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_SET_CHANNEL_REQ, &var, 0);
        if (pdu_length > 0)
        {
            peer = construct_peer_buff(pdu_length, 0, 0, TD_RESET);
            if (wps_pun_var_part(WPS_PUN_PACK, MSG_ID_WPS_SET_CHANNEL_REQ, &var, get_pdu_ptr(peer, &len)) != pdu_length)
            {
                free_peer_buff(peer);
                peer = 0;
            }
        }
    }

    /* send message */

    {
        ilm_struct* ilm;

        mmi_kmx_register_network_event_handler();

        ilm = allocate_ilm(MOD_MMI);

        ilm->local_para_ptr = (local_para_struct*)req;
        ilm->peer_buff_ptr = (peer_buff_struct*)peer;
        ilm->msg_id = MSG_ID_WPS_SET_CHANNEL_REQ;

        SEND_ILM(MOD_MMI, MOD_WPS, WPS_APP_SAP, ilm);
    }
    #endif
    return KMX_STATUS_OK;
}

#if defined (__MMI_DOWNLOAD_AGENT__) && defined(BROWSER_SUPPORT) 
static void mmi_kmx_set_channel_rsp(void* message)
{
    wps_set_channel_rsp_struct* rsp;

    rsp = (wps_set_channel_rsp_struct*)message;

    #if KMX_ENABLE_DEBUG
        kal_prompt_trace(MOD_CC, "KMX: mmi_kmx_set_channel_rsp, result=%d, channel=%d\n", rsp->result, rsp->channel_id);
    #endif

    if (rsp->result != WPS_OK)
    {
        mmi_kmx_clear_network_event_handler();
        mmi_kmx_handle_event(KMX_EVENT_CHANNEL_RESPONSE, KMX_STATUS_ERROR, 0);
        return;
    }

    g_kmx_channel_id = rsp->channel_id;
    mmi_kmx_handle_event(KMX_EVENT_CHANNEL_RESPONSE, KMX_STATUS_OK, 0);
}
#endif

void kmx_os_net_close_channel(void)
{
    #if defined (__MMI_DOWNLOAD_AGENT__) && defined(BROWSER_SUPPORT) 
    wps_unset_channel_req_struct* req;

    #if KMX_ENABLE_DEBUG
        kal_prompt_trace(MOD_CC, "KMX: kmx_os_net_close_channel\n");
    #endif

    /* construct message */

    {
        req = (wps_unset_channel_req_struct*) construct_local_para(sizeof(wps_unset_channel_req_struct), TD_CTRL);
        if (!req)
            return;

        req->channel_id = g_kmx_channel_id;
    }

    /* send message */

    {
        ilm_struct* ilm;

        ilm = allocate_ilm(MOD_MMI);

        ilm->local_para_ptr = (local_para_struct*)req;
        ilm->peer_buff_ptr = 0;
        ilm->msg_id = MSG_ID_WPS_UNSET_CHANNEL_REQ;

        SEND_ILM(MOD_MMI, MOD_WPS, WPS_APP_SAP, ilm);
    }
    #endif
}

#if defined (__MMI_DOWNLOAD_AGENT__) && defined(BROWSER_SUPPORT) 
static void mmi_kmx_unset_channel_rsp(void* message)
{
    #if KMX_ENABLE_DEBUG
    {
        wps_unset_channel_rsp_struct* rsp;

        rsp = (wps_unset_channel_rsp_struct*)message;
        kal_prompt_trace(MOD_CC, "KMX: mmi_kmx_unset_channel_rsp, result=%d\n", rsp->result);
    }
    #endif

    g_kmx_channel_id = 0;
}
#endif

KMXSTATUS kmx_os_net_send_http_request(KMX_OS_HTTP_REQUEST* request)
{
    #if defined (__MMI_DOWNLOAD_AGENT__) && defined(BROWSER_SUPPORT) 
    wps_http_req_struct* req;
    peer_buff_struct* peer;
    wps_http_req_var_struct var;

    unsigned int header_length;
    unsigned int post_data_length;

    #if KMX_ENABLE_DEBUG
        kal_prompt_trace(MOD_CC, "KMX: kmx_os_net_send_http_request\n");
    #endif

    if (request == 0 ||
        request->id == 0 ||
        request->url == 0 ||
        (request->method != KMX_HTTP_METHOD_GET && request->method != KMX_HTTP_METHOD_POST))
    {
        #if KMX_ENABLE_DEBUG
            kal_prompt_trace(MOD_CC, "Error(kmx_os_net_send_http_request) bad request param\n");
        #endif

        return KMX_STATUS_ERROR;
    }

    if (request->header != 0)
        header_length = strlen(request->header);
    else
        header_length = 0;

    if (request->method == KMX_HTTP_METHOD_POST && request->post_data != 0)
        post_data_length = strlen(request->post_data);
    else
        post_data_length = 0;

    /* construct message */

    {
	    req = (wps_http_req_struct*) construct_local_para(sizeof(wps_http_req_struct), TD_CTRL);

        req->channel_id = g_kmx_channel_id;
	    req->request_id = (unsigned char)(request->id);

        req->post_path[0] = 0;
        req->post_path[1] = 0;

        if (request->method == KMX_HTTP_METHOD_GET)
        {
	        req->method = WPS_HTTP_METHOD_GET;
            req->post_type = WPS_DATA_TYPE_BUFFER;
            req->post_total_len = 0;
        }
        else
	    {
            req->method = WPS_HTTP_METHOD_POST;
            req->post_type = WPS_DATA_TYPE_BUFFER;
            req->post_total_len = post_data_length;
        }

	    req->more_post = KAL_FALSE;
	    req->option = WPS_HTTP_OPTION_NO_CACHE | WPS_HTTP_OPTION_DO_NOT_CACHE_REPLY;
	    req->reply_path[0] = 0;
	    req->reply_path[1] = 0;
	    req->reply_type = WPS_DATA_TYPE_BUFFER;
	    req->reply_segment_len = KMX_REPLY_SEGMENT_LEN;
	}

	/* fill url */

    {
        if (header_length > 0)
        {
	        var.request_header_len = header_length;
	        var.request_header = (kal_uint8*)(request->header);
        }
        else
        {
	        var.request_header_len = 0;
	        var.request_header = 0;
        }

        if (request->method == KMX_HTTP_METHOD_GET)
        {
	        var.post_segment_len = 0;
	        var.post_segment = 0;
        }
        else
        {
	        var.post_segment_len = post_data_length;
	        var.post_segment = (kal_uint8*)(request->post_data);
        }

	    var.request_url_len = strlen(request->url);
	    var.request_url = (kal_uint8*)(request->url);
	}

	/* pack peer buffer */

    {
        U16 len, pdu_length;

        peer = 0;
	    pdu_length = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_HTTP_REQ, &var, 0);
        if (pdu_length > 0)
        {
		    peer = construct_peer_buff(pdu_length, 0, 0, TD_RESET);
		    if (wps_pun_var_part(WPS_PUN_PACK, MSG_ID_WPS_HTTP_REQ, &var, get_pdu_ptr(peer, &len)) != pdu_length)
            {
                free_peer_buff(peer);
                peer = 0;
            }
        }
	}

	/* send message */

    {
        ilm_struct* ilm;

	    ilm = allocate_ilm(MOD_MMI);

	    ilm->local_para_ptr = (local_para_struct*)req;
	    ilm->msg_id = MSG_ID_WPS_HTTP_REQ;
	    ilm->peer_buff_ptr = peer;

	    SEND_ILM(MOD_MMI, MOD_WPS, WPS_APP_SAP, ilm);
    }
    #endif
    return KMX_STATUS_OK;
}

#if defined (__MMI_DOWNLOAD_AGENT__) && defined(BROWSER_SUPPORT) 
static void mmi_kmx_http_rsp(void* message, int mod_id, void* peer_buf)
{
    wps_http_rsp_struct* rsp;
    KMX_OS_HTTP_RESPONSE response;

    rsp = (wps_http_rsp_struct*)message;

    #if KMX_ENABLE_DEBUG
        kal_prompt_trace(MOD_CC, "KMX: mmi_kmx_http_rsp, id=%d, result=%d, more=%d\n",
            rsp->request_id, rsp->result, rsp->more);
    #endif

    memset(&response, 0, sizeof(response));
    response.id = rsp->request_id;

    if (rsp->result != WPS_OK)
    {
        #if KMX_ENABLE_DEBUG
            kal_prompt_trace(MOD_CC, "KMX: mmi_kmx_http_rsp, response error\n");
        #endif  

        response.status = KMX_STATUS_ERROR;
        mmi_kmx_handle_event(KMX_EVENT_HTTP_RESPONSE, (KMXPARAM)(&response), 0);

        return;
    }

    if (rsp->more)
        response.status = KMX_STATUS_OK;
    else
        response.status = KMX_STATUS_CONNECTION_END;

	/* Get HTTP status code */

    response.flags = KMX_HTTP_FLAG_STATUS;
    response.http_status = rsp->status;

	/* Get reply header and content */

    {
        ilm_struct* ilm;
        U16 pdu_length = 0;
        wps_http_rsp_var_struct var;

        ilm = (ilm_struct*)peer_buf;
        if (wps_pun_var_part(WPS_PUN_UNPACK, MSG_ID_WPS_HTTP_RSP, &var, get_pdu_ptr(ilm->peer_buff_ptr, &pdu_length)) > 0)
        {
            #if KMX_ENABLE_DEBUG
                kal_prompt_trace(MOD_CC, "KMX: mmi_kmx_http_rsp, header_size=%d, content_size=%d\n",
                    var.reply_header_len, var.reply_segment_len);
                kmx_debug_txt_dump(var.reply_header, var.reply_header_len);
                kmx_debug_txt_dump(var.reply_segment, var.reply_segment_len);
            #endif

            if (var.reply_header_len > 0)
            {
                response.header_length = var.reply_header_len;
                response.header = (const char*)(var.reply_header);
                response.flags |= KMX_HTTP_FLAG_HEADER;
            }

            if (var.reply_segment_len > 0)
            {
                response.content_length = var.reply_segment_len;
                response.content = (const char*)(var.reply_segment);
                response.flags |= KMX_HTTP_FLAG_CONTENT;
            }
	    }
        else
        {
            #if KMX_ENABLE_DEBUG
                kal_prompt_trace(MOD_CC, "KMX: mmi_kmx_http_rsp, wps_pun_var_part() failed\n");
            #endif
        }
    }

    mmi_kmx_handle_event(KMX_EVENT_HTTP_RESPONSE, (KMXPARAM)(&response), 0);

    if (rsp->more)
        mmi_kmx_read_content_req((unsigned char)rsp->request_id, 1);
}

static void mmi_kmx_read_content_req(unsigned char request_id, unsigned char seq_num)
{
    wps_read_content_req_struct* req;

    /* construct message */
    
    {
        req = (wps_read_content_req_struct*) construct_local_para(sizeof(wps_read_content_req_struct), TD_CTRL);

        req->channel_id = g_kmx_channel_id;
        req->request_id = request_id;
        req->seq_num = seq_num;
        req->read_segnemtn_len = KMX_REPLY_SEGMENT_LEN;
    }

	/* send message */

    {
        ilm_struct* ilm;

        ilm = allocate_ilm(MOD_MMI);

        ilm->msg_id = MSG_ID_WPS_READ_CONTENT_REQ;
        ilm->local_para_ptr = (local_para_struct*)req;
        ilm->peer_buff_ptr = 0;

        SEND_ILM(MOD_MMI, MOD_WPS, WPS_APP_SAP, ilm);
    }
}

static void mmi_kmx_read_content_rsp(void* message, int mod_id, void* peer_buf)
{
    wps_read_content_rsp_struct* rsp;
    KMX_OS_HTTP_RESPONSE response;

    rsp = (wps_read_content_rsp_struct*)message;

    #if KMX_ENABLE_DEBUG
        kal_prompt_trace(MOD_CC, "KMX: mmi_kmx_read_content_rsp, id=%d, result=%d, seq=%d, more=%d\n",
            rsp->request_id, rsp->result, rsp->seq_num, rsp->more);
    #endif

    memset(&response, 0, sizeof(response));
    response.id = rsp->request_id;

    /* Treat invalid request id as a non content correct response. */
    if (rsp->result == WPS_ERROR_INVALID_REQUEST_ID)
    {
        response.status = KMX_STATUS_CONNECTION_END;            
        mmi_kmx_handle_event(KMX_EVENT_HTTP_RESPONSE, (KMXPARAM)(&response), 0);
        /* Cancel the request ? */
        return;
    }

    if (rsp->result != WPS_OK)
    {        
        #if KMX_ENABLE_DEBUG
            kal_prompt_trace(MOD_CC, "KMX: mmi_kmx_read_content_rsp, response error\n");
        #endif

        response.status = KMX_STATUS_ERROR;
        mmi_kmx_handle_event(KMX_EVENT_HTTP_RESPONSE, (KMXPARAM)(&response), 0);

        return;
    }

    if (rsp->more)
        response.status = KMX_STATUS_OK;
    else
        response.status = KMX_STATUS_CONNECTION_END;

	/* Get reply content */

    {
        ilm_struct* ilm;
        U16 pdu_length = 0;
        wps_read_content_rsp_var_struct var;

        ilm = (ilm_struct*)peer_buf;
        if (wps_pun_var_part(WPS_PUN_UNPACK, MSG_ID_WPS_READ_CONTENT_RSP, &var, get_pdu_ptr(ilm->peer_buff_ptr, &pdu_length)) > 0)
        {
            #if KMX_ENABLE_DEBUG
                kal_prompt_trace(MOD_CC, "KMX: mmi_kmx_read_content_rsp, content_size=%d\n", var.reply_segment_len);
                kmx_debug_txt_dump(var.reply_segment, var.reply_segment_len);
            #endif

            if (var.reply_segment_len > 0)
            {
                response.content_length = var.reply_segment_len;
                response.content = (const char*)(var.reply_segment);
                response.flags |= KMX_HTTP_FLAG_CONTENT;
            }
	    }
        else
        {
            #if KMX_ENABLE_DEBUG
                kal_prompt_trace(MOD_CC, "KMX: mmi_kmx_read_content_rsp, wps_pun_var_part() failed\n");
            #endif
        }
    }
    
    mmi_kmx_handle_event(KMX_EVENT_HTTP_RESPONSE, (KMXPARAM)(&response), 0);

    if (rsp->more)
        mmi_kmx_read_content_req((unsigned char)rsp->request_id, (unsigned char)(rsp->seq_num + 1));
}
#endif 

void kmx_os_net_cancel_http_request(unsigned int id)
{
    #if defined (__MMI_DOWNLOAD_AGENT__) && defined(BROWSER_SUPPORT) 
    wps_cancel_req_struct* req;

    #if KMX_ENABLE_DEBUG
        kal_prompt_trace(MOD_CC, "KMX: kmx_os_net_cancel_http_request, id=%d\n", id);
    #endif

    if (id == 0)
        return;

    /* construct message */

    {
        req = (wps_cancel_req_struct*) construct_local_para(sizeof(wps_cancel_req_struct), TD_CTRL);
        req->channel_id = g_kmx_channel_id;
        req->request_id = (unsigned char)id;
    }

	/* send message */

    {
        ilm_struct* ilm;

        ilm = allocate_ilm(MOD_MMI);

        ilm->msg_id = MSG_ID_WPS_CANCEL_REQ;
        ilm->local_para_ptr = (local_para_struct*)req;
        ilm->peer_buff_ptr = 0;

        SEND_ILM(MOD_MMI, MOD_WPS, WPS_APP_SAP, ilm);
    }
    #endif 
}

#if defined (__MMI_DOWNLOAD_AGENT__) && defined(BROWSER_SUPPORT) 
static void mmi_kmx_cancel_http_rsp(void* message)
{
#if KMX_ENABLE_DEBUG

    wps_cancel_rsp_struct* rsp;

    rsp = (wps_cancel_rsp_struct*)message;

    kal_prompt_trace(MOD_CC, "KMX: mmi_kmx_cancel_http_rsp, id=%d, result=%d\n", rsp->request_id, rsp->result);

#endif
}

static KMXSTATUS mmi_kmx_handle_event(int event, KMXPARAM param1, KMXPARAM param2)
{
    KMXSTATUS status = KMX_STATUS_OK;
    
    if (g_kmx_net_response_handler)
    {
        status = g_kmx_net_response_handler(event, param1, param2);
    }    
    
    return status;
}
#endif 

void kmx_os_net_set_response_handler(KMX_NET_RESPONSE_HANDLER handler)
{
    g_kmx_net_response_handler = handler;
}

/*****************************************************************************
 *
 * File system support functions.
 *
 *****************************************************************************/

KMXSTATUS kmx_os_fs_create_dir(const KMXWCHAR* dir)
{
    FS_HANDLE h;
    int s;

    if (!dir)
        return KMX_STATUS_INVALID_PARAMETER;

    h = FS_Open((const WCHAR*)dir, FS_OPEN_DIR | FS_READ_ONLY);

    if (h >= FS_NO_ERROR)
    {
        /* Directory already exist */        
        FS_Close(h);
        return KMX_STATUS_OK;
    }

    /* Create the directory */

    s = FS_CreateDir((const WCHAR*)dir);

    return (s >= FS_NO_ERROR) ? KMX_STATUS_OK : KMX_STATUS_ERROR;
}

KMXSTATUS kmx_os_fs_open(
    const KMXWCHAR*     file_name,
    int                 mode,
    KMX_FILE_HANDLE*    handle)
{
    FS_HANDLE h;
    UINT f;

    MMI_ASSERT(file_name);
    MMI_ASSERT(handle);

    switch (mode)
    {
        case KMX_OPEN_CREATE:
            f = FS_CREATE_ALWAYS;
            break;
        case KMX_OPEN_READ:
            f = FS_READ_ONLY;
            break;
        case KMX_OPEN_READ_WRITE:
            f = FS_READ_WRITE;
            break;
        default:
            return KMX_STATUS_INVALID_PARAMETER;
    }

    h = FS_Open(file_name, f);

    if (h < 0)
        return KMX_STATUS_ERROR;

    *handle = (KMX_FILE_HANDLE)h;

    return KMX_STATUS_OK;
}

void kmx_os_fs_close(KMX_FILE_HANDLE handle)
{
    FS_Close((FS_HANDLE)handle);
}

KMXSTATUS kmx_os_fs_seek(
    KMX_FILE_HANDLE     handle,
    int                 offset,
    int                 origin)
{
    int result;
    int whence;

    switch (origin)
    {
        case KMX_SEEK_CUR:
            whence = FS_FILE_CURRENT;
            break;
        case KMX_SEEK_END:
            whence = FS_FILE_END;
            break;
        case KMX_SEEK_SET:
            whence = FS_FILE_BEGIN;
            break;
        default:
            return KMX_STATUS_INVALID_PARAMETER;
    }

    result = FS_Seek((FS_HANDLE)handle, offset, whence);

    return (result >= FS_NO_ERROR) ? KMX_STATUS_OK : KMX_STATUS_ERROR;
}

KMXSTATUS kmx_os_fs_read(
    KMX_FILE_HANDLE     handle,
    void*               buffer,
    unsigned int        size,
    unsigned int*       read_size)
{
    int result;

    MMI_ASSERT(read_size);

    result = FS_Read((FS_HANDLE)handle, buffer, size, read_size);

    return (result == FS_NO_ERROR) ? KMX_STATUS_OK : KMX_STATUS_ERROR;
}

KMXSTATUS kmx_os_fs_write(
    KMX_FILE_HANDLE     handle,
    const void*         buffer,
    unsigned int        size,
    unsigned int*       written_size)
{
    int result;

    MMI_ASSERT(written_size);

    result = FS_Write((FS_HANDLE)handle, (void*)buffer, size, written_size);

    return (result == FS_NO_ERROR) ? KMX_STATUS_OK : KMX_STATUS_ERROR;
}
