#ifndef _WPS_SAP_H
#define _WPS_SAP_H

#ifdef __BUILD_DOM__
/*****************************************************************************
* <GROUP  STK Messages>
*
* WPS STK SAP Primitives
******************************************************************************/
typedef enum {
#endif /* __BUILD_DOM__ */

    /* 
     * Configure a dedicated channel for HTTP/WSP requests. An channel can be 
     * configured to use proxy while  use_proxy is true. When use_proxy is true, 
     * prx_ip, prx_port, username, and password will be used to communicate with 
     * proxy server, thus prx_ip must not be 0.0.0.0 and if prx_port value 0 
     * means use default proxy port 8080. When the conn_type is 
     * WPS_CONN_TYPE_WSP_CO or WPS_CONN_TYPE_WSP_CL, then use_proxy is true 
     * default. However, if application simply wants to use current activated 
     * setting used in WAP, then just set use_default as true and ignore all 
     * other parameters. 
     * 
     * Static_header (if necessary) must be filled in 
     * wps_set_channel_req_var_struct and then packed in peer buffer by 
     * wps_pun_var_part() before sending to WPS. Static_header will be used in 
     * the header when establishing WSP session when conn_type is 
     * WAP_PROF_CONN_TYPE_WSP_CO and the first WSP request  of some dedicated 
     * channel with connection type WSP_CONN_TYPE_WSP_CL. If application doesn't 
     * specify static_header, then WPS will use the value currently used by WAP.
     *
     * Direction: APP -> WPS
     * Local parameter: wps_set_channel_req_struct
     * Peer buffer: wps_set_channel_req_var_struct
     */
    MSG_ID_WPS_SET_CHANNEL_REQ,	

    /* 
     * Response to the channel configuration request, and if the result is 
     * successful, then the channel ID will be used n the HTTP/WSP request.
     *
     * Direction: WPS -> APP
     * Local parameter: wps_set_channel_rsp_struct
     * Peer buffer: None
     */
    MSG_ID_WPS_SET_CHANNEL_RSP,

    /* 
     * Remove a configured channel identified by channel ID.
     *
     * Direction: APP -> WPS
     * Local parameter: wps_unset_channel_req_struct
     * Peer buffer: None
     */
    MSG_ID_WPS_UNSET_CHANNEL_REQ,

    /* 
     * Response to channel remove request. If the channel ID in request is 
     * invalid or some pending request of this channel exists, then an error is 
     * replied.
     *
     * Direction: WPS -> APP
     * Local parameter: wps_unset_channel_rsp_struct
     * Peer buffer: None
     */
    MSG_ID_WPS_UNSET_CHANNEL_RSP,

    MSG_ID_WPS_RECONFIG_CHANNEL_REQ,	
    MSG_ID_WPS_RECONFIG_CHANNEL_RSP,
    MSG_ID_WPS_TERMINATION_IND,
    MSG_ID_WPS_RELEASE_ALL_REQ,
    MSG_ID_WPS_RELEASE_ALL_RSP,

    /* 
     * Send a HTTP/WSP request with URL, http method, and http options as 
     * parameters. The request ID is assigned by application itself and it must 
     * not be a duplicate one of a pending request. The requesting side can also 
     * specify the type of reply by reply_type. If reply_type is 
     * WPS_DATA_TYPE_BUFFER, then replied content will be put in peer buffer of 
     * response primitive MSG_ID_WPS_HTTP_RSP. However the peer buffer size of a
     * primitive is limited, so one peer buffer may not contains the whole 
     * replied content. For this reason, reply_segement_length is used to 
     * sepcify the maximum size of peer buffer used to carry replied content is
     * suggested by requesting side. Thus, applications must use 
     * MSG_ID_WPS_READ_CONTENT_REQEST to get remaining content if only partial 
     * replied content is carried in the peer buffer of MSG_ID_WPS_HTTP_RSP. If 
     * reply_type is WPS_DATA_TYPE_FILE or WPS_DATA_TYPE_FILE_NO_PROG_IND, then 
     * reply content will be saved in a file path specified by reply_path. There
     * will be content downloading progress indication if the reply_type is 
     * WPS_DATA_TYPE_FILE. This request can be aborted by sending 
     * WPS MSG_ID_WPS_CANCEL_REQ.
     * 
     * If method is WPS_METHOD_POST, then post_type, post_path, post_total_len, 
     * and more_psst are respectively used to specify if post type is by buffer 
     * or by file, the file path to be posted if post_type is 
     * WPS_DATA_TYPE_FILE, the total length of post data (value 0 means 
     * unknown), and more_post is a flag used to indiate if more data is needed 
     * to be post continuously in next MSG_ID_WPS_POST_CONTENT_RES.
     * 
     * Request_url, request_header, and post_segment if HTTP method is post and 
     * post type is WPS_DATA_TYPE_BUFFER must be filled in 
     * wps_http_req_var_struct and then packed in peer buffer by 
     * wps_pun_var_part() before sending to WPS.
     *
     * Direction: APP -> WPS
     * Local parameter: wps_http_req_struct
     * Peer buffer: wps_http_req_var_struct
     */
    MSG_ID_WPS_HTTP_REQ,

    /* 
     * Response to the HTTP/WSP request. new_url is used to hold the new URL 
     * that was used to retrieve this reply If the original request was 
     * redirected. If the reply_type in MSG_ID_WPS_HTTP_REQ is 
     * WPS_DATA_TYPE_BUFFER, then the more flag is used to indicate if 
     * application needs to use MSG_ID_WPS_READ_CONTENT_REQ to retrieve 
     * remaining content.
     *
     * The new_url if available, reply_header if available, and reply_segment 
     * if the reply_type is WPS_DATA_TYPE_BUFFER are filled in 
     * wps_http_rsp_var_struct and then packed by wps_pun_var_part() into peer 
     * buffer. Application must unpack the peer buffer into 
     * wps_http_rsp_var_struct by wps_pun_var_part() before using the reply.
     *
     * Direction: WPS -> APP
     * Local parameter: wps_http_rsp_struct
     * Peer buffer: wps_http_rsp_var_struct
     */
    MSG_ID_WPS_HTTP_RSP,

    /* 
     * Read the remaining replied content  of the previous WPS_HTTP_RSP. 
     * read_segment_length specifies the suggested maximum content size in the 
     * peer buffer of MSG_ID_WPS_READ_CONTENT_RSP. seq_num is for error 
     * detection purpose, and the value must be 1 in the first 
     * MSG_ID_READ_CONTENT_REQ, and increase 1 for each following 
     * MSG_ID_READ_CONTENT_REQ.
     *
     * Direction: APP -> WPS
     * Local parameter: wps_read_content_req_struct
     * Peer buffer: None
     */
    MSG_ID_WPS_READ_CONTENT_REQ,

    /* 
     * Response to the MSG_ID_WPS_READ_CONTENT_REQ. The seq_num must be the same 
     * as the one in the corresponding MSG_ID_WPS_READ_CONTENT_REQ. The more 
     * flag is used to indicate if application needs to use 
     * MSG_ID_WPS_READ_CONTENT_REQ to retrieve remaining content.
     *
     * The reply_segment of the MSG_ID_WPS_READ_CONTENT_REQ is filled in 
     * wps_read_content_rsp_var_struct by wps_pun_var_part() in the peer buffer 
     * so the receiving application must unpack the peer buffer with 
     * wps_pun_var_part() into wps_read_content_rsp_var_struct first before 
     * using it.
     *
     * Direction: WPS -> APP
     * Local parameter: wps_read_content_rsp_struct
     * Peer buffer: wps_read_content_rsp_var_struct
     */
    MSG_ID_WPS_READ_CONTENT_RSP,

    /* 
     * Indicate post complete of the MSG_ID_WPS_HTTP_REQ while the method is 
     * POST/PUT and post_type is WPS_DATA_TYPE_BUFFER. And it also responses to 
     * the MSG_ID_WPS_POST_CONTENT_RES to notify application the result of data 
     * post. After receiving this indication and the result is successful, then 
     * application can continuously post data by MSG_ID_WPS_POST_CONTENT_RES if 
     * more data to be post. The seq_num must be 1 in the first 
     * MSG_ID_WPS_POST_CONTENT_IND and then increase 1 each time for the 
     * following MSG_ID_WPS_POST_CONTENT_ID.
     *
     * Direction: WPS -> APP
     * Local parameter: wps_post_content_ind_struct
     * Peer buffer: None
     */
    MSG_ID_WPS_POST_CONTENT_IND,

    /* 
     * Post remaining data in the HTTP/WSP POST/PUT request while the post_type 
     * in MSG_ID_WPS_HTTP_REQ is WPS_DATA_TYPE_BUFFER. seq_num is a sequence 
     * number for error detection purpose, and the value must be the same as the
     * seq_enum in previous MSG_ID_WPS_POST_CONTENT_IND. The more flag is used 
     * to indicate if application has more data to be post.
     *
     * post_segment must be filled wps_post_content_res_var_struct and then 
     * packed into peer buffer by wps_pun_var_part() before sending to WPS.
     *
     * Direction: APP -> WPS
     * Local parameter: wps_post_content_res_struct
     * Peer buffer: wps_post_content_res_var_struct
     */
    MSG_ID_WPS_POST_CONTENT_RES,

    /* 
     * Indicate downloading status of replied content of HTTP/WSP request while 
     * the reply_type in the HTTP/WSP request is specified as 
     * WPS_DATA_TYPE_FILE. seq_enum is a sequence number for error detection, 
     * and the value must be 1 in the first MSG_ID_WPS_DL_PROGRESS_IND, and 
     * increase 1 for each following MSG_ID_WPS_DL_PROGRESS_IND. status 
     * indicates current downloading status: keep downloading or complete 
     * downloading or downloading is aborted. acc_size is the accumulated size 
     * of downloading.
     *
     * Direction: WPS -> APP
     * Local parameter: wps_dl_progress_ind_struct
     * Peer buffer: None
     */
    MSG_ID_WPS_DL_PROGRESS_IND,

    /* 
     * This is the response to the download progress indication.
     *
     * Direction: APP -> WPS
     * Local parameter: wps_dl_progress_res_struct
     * Peer buffer: None
     */
    MSG_ID_WPS_DL_PROGRESS_RES,

    /* 
     * Cancel the ongoing HTTP/WSP request not completed with request ID. Not 
     * completed means that application is still waiting HTTP reply or read 
     * content response or downloading progress is ongong without receiving 
     * MSG_ID_WPS_DL_PROGRESS_IND with status 'WPS_DL_STATUS_COMPLETE'.
     *
     * Direction: APP -> WPS
     * Local parameter: wps_cancel_req_struct
     * Peer buffer: None
     */
    MSG_ID_WPS_CANCEL_REQ,

    /* 
     * Response to the cancel request.
     *
     * Direction: WPS -> APP
     * Local parameter: wps_cancel_rsp_struct
     * Peer buffer: None
     */
    MSG_ID_WPS_CANCEL_RSP,

    /* 
     * Notify application its interesting push document which ahs been 
     * downloaded and stord in the path specified by data_path, and the content 
     * type and content length of the push document.
     *
     * Direction: WPS -> APP
     * Local parameter: wps_push_ind_struct
     * Peer buffer: None
     */
    MSG_ID_WPS_PUSH_IND,

    /* 
     * This primitive is used to clear cache and cookie sharing information of 
     * all users. If the operation is specified as WPS_CLEAR_CACHE_URL_MATCH or
     * WPS_CLEAR_CACHE_URL_PREFIX, then cache_url must be filled in 
     * wps_clear_req_var_struct and then packed into peer buffer by 
     * wps_pun_var_part() before sending to WPS.
     *
     * Direction: APP -> WPS
     * Local parameter: wps_clear_req_struct
     * Peer buffer: wps_clear_req_var_struct
     */
    MSG_ID_WPS_CLEAR_REQ,

    /* 
     * Response to the clear request. Generall, the result of the request should
     * be successful except when url is empty  when operation is 
     * WPS_CLEAR_CACHE_URL_MATCH or WPS_CLEAR _CACHE_URL_PREFIX.
     *
     * Direction: WPS -> APP
     * Local parameter: wps_clear_rsp_struc
     * Peer buffer: None
     */
    MSG_ID_WPS_CLEAR_RSP,
    
    MSG_ID_WPS_CREATE_STREAM_CONNECTION_REQ,
    MSG_ID_WPS_CREATE_STREAM_CONNECTION_RSP,
    MSG_ID_WPS_STREAM_CONNECTION_CLOSED_IND,
    MSG_ID_WPS_CLOSE_STREAM_CONNECTION_REQ,
    MSG_ID_WPS_CLOSE_STREAM_CONNECTION_RSP,
    MSG_ID_WPS_STREAM_DATA_SEND_REQ,
    MSG_ID_WPS_STREAM_DATA_SEND_RSP,
    MSG_ID_WPS_STREAM_DATA_READ_REQ,
    MSG_ID_WPS_STREAM_DATA_READ_RSP,
    MSG_ID_WPS_EXT_MSG_IND,

    /* 
     * Unsolicited indication to notify WPS user application that WPS is ready 
     * to service.
     *
     * Direction: WPS -> APP
     * Local parameter: None
     * Peer buffer: None
     */
    MSG_ID_WPS_READY_IND,

    /* 
     * Indication to notify the sender of the HTTP request sents need 
     * authentication if no default username/password are provided in 
     * MSG_ID_WPS_SET_CHANNEL_REQ.
     *
     * Direction: WPS -> APP
     * Local parameter: wps_http_auth_ind_struct
     * Peer buffer: None
     */
    MSG_ID_WPS_HTTP_AUTH_IND,

    /* 
     * Response to thenotification of authentication request.
     *
     * Direction: APP -> WPS
     * Local parameter: wps_http_auth_res_struct
     * Peer buffer: None
     */
    MSG_ID_WPS_HTTP_AUTH_RES,

    /* 
     * Query WPS if it is already to provide service.
     *
     * Direction: APP -> WPS
     * Local parameter: None
     * Peer buffer: None
     */
    MSG_ID_WPS_STATUS_QUERY_REQ,

    /* 
     * Response to status query reqeust. If the status is WPS_READY_STATUS_NULL,
     * then WPS will send MSG_ID_WPS_READY_IND to the module who submit 
     * MSG_ID_WPS_STATUS_QUERY_REQ
     *
     * Direction: WPS -> APP
     * Local parameter: wps_status_query_rsp_struct
     * Peer buffer: None
     */
    MSG_ID_WPS_STATUS_QUERY_RSP,
    MSG_ID_WPS_HTTP_AUTH_INFO,
    MSG_ID_WPS_SET_COOKIE_REQ,
    
#ifdef __BUILD_DOM__
    } sap_wps_stk_enum;
#endif /* __BUILD_DOM__ */

#ifdef __BUILD_DOM__
    /*****************************************************************************
    * <GROUP  Security Messages>
    *
    * WPS Security SAP Primitives
    ******************************************************************************/
    typedef enum {
#endif /* __BUILD_DOM__ */

    /****************** Security Services **********************/

    /* This primitive is used to get the current security session information of the existing secure connection by channel ID.
    *
    * Direction: APP -> WPS
    * Local parameter: wps_sec_get_session_info_req_struct
    * Peer buffer: None
    */
    MSG_ID_WPS_SEC_GET_SESSION_INFO_REQ,

    /* This primitive is used to send response to get session information request. If success, the response contains cipher suite constant and connection type.
    *
    * Direction: WPS -> APP
    * Local parameter: wps_sec_get_session_info_req_struct
    * Peer buffer: None
    */    
    MSG_ID_WPS_SEC_GET_SESSION_INFO_RSP,
    
    /* This primitive is used to get the current used server certificate information of the existing secure connection by channel ID.
    *
    * Direction: APP -> WPS
    * Local parameter: wps_sec_get_current_cert_req_struct
    * Peer buffer: None
    */    
    MSG_ID_WPS_SEC_GET_CURRENT_CERT_REQ,

    /* This primitive is used to send response to get current used server certificate request. If success, the response contains the detail information of the server certificate.
    *
    * Direction: WPS -> APP
    * Local parameter: wps_sec_get_current_cert_rsp_struct
    * Peer buffer: None
    */    
    MSG_ID_WPS_SEC_GET_CURRENT_CERT_RSP,
    
    /* This primitive is used to verify a certificate chain, the result is returned in MSG_ID_WPS_SEC_VERIFY_CERT_CHAIN_RSP.
    *
    * Direction: APP -> WPS
    * Local parameter: wps_sec_verify_cert_chain_req_struct
    * Peer buffer: None
    */    
    MSG_ID_WPS_SEC_VERIFY_CERT_CHAIN_REQ,
    
    /* This primitive is used to send response to MSG_ID_WPS_SEC_VERIFY_CERT_CHAIN_REQ.
    *
    * Direction: WPS -> APP
    * Local parameter: wps_sec_verify_cert_chain_rsp_struct
    * Peer buffer: None
    */    
    MSG_ID_WPS_SEC_VERIFY_CERT_CHAIN_RSP,   

    /* This primitive is used to delete the specified root CA stored in the device.
    *
    * Direction: APP -> WPS
    * Local parameter: wps_sec_delete_ca_cert_req_struct
    * Peer buffer: None
    */    
    MSG_ID_WPS_SEC_DELETE_CA_CERT_REQ,

    /* This primitive is used to send response to the delete operation result.
    *
    * Direction: WPS -> APP
    * Local parameter: wps_sec_delete_ca_cert_rsp_struct
    * Peer buffer: None
    */    
    MSG_ID_WPS_SEC_DELETE_CA_CERT_RSP,   

    /* This primitive is used to notify the application that security package requires user interaction to continue.
    *
    * Direction: WPS -> APP
    * Local parameter: wps_show_confirm_dialog_ind_struct
    * Peer buffer: None
    */    
    MSG_ID_WPS_SEC_SHOW_CONFIRM_DIALOG_IND,

    /* This primitive is used to send the response to the notification of show dialog request.
    *
    * Direction: APP -> WPS
    * Local parameter: wps_show_confirm_dialog_res_struct
    * Peer buffer: None
    */    
    MSG_ID_WPS_SEC_SHOW_CONFIRM_DIALOG_RES,
    
    /* This primitive is used to get all X.509 root CA certificates stored in this device.
    *
    * Direction: APP -> WPS
    * Local parameter: None
    * Peer buffer: None
    */    
    MSG_ID_WPS_SEC_GET_X509_CA_CERT_REQ,

    /* This primitive is used to notify the application that security package requires user interaction to continue.
    *  NOTE:
    *    WPS use this message to indicate the individual X.509 root CA certificate as the result of  MSG_ID_WPS_SEC_GET_X509_CA_CERT_REQ. 
    *    For example, WPS send 5 MSG_ID_WPS_SEC_GET_X509_CA_CERT_IND to WPS user if there is 5 X.509 root ca stored in the device
    *
    * Direction: WPS -> APP
    * Local parameter: wps_sec_get_x509_ca_cert_ind_struct
    * Peer buffer: None
    */    
    MSG_ID_WPS_SEC_GET_X509_CA_CERT_IND,

    /* This primitive is used to indicate no more MSG_ID_WPS_SEC_GET_X509_CA_CERT_IND be sent to WPS user , which also indicate the total number of X.509 CA certificate sent to WPS user
    *
    * Direction: WPS -> APP
    * Local parameter: wps_sec_get_x509_ca_cert_rsp_struct
    * Peer buffer: None
    */    
    MSG_ID_WPS_SEC_GET_X509_CA_CERT_RSP,   

    /* This primitive is used to get the list of certificate stored in certificated storage. A list of certificate IDs will be returned. 
    *
    * Direction: APP -> WPS
    * Local parameter: wps_sec_get_cert_ids_req_struct
    * Peer buffer: None
    */    
    MSG_ID_WPS_SEC_GET_CERT_IDS_REQ,

    /* This primitive is used to return the list of certificate ids.
    *
    * Direction: WPS -> APP
    * Local parameter: wps_sec_get_cert_ids_rsp_struct
    * Peer buffer: None
    */    
    MSG_ID_WPS_SEC_GET_CERT_IDS_RSP,   

    /* This primitive is used to get the certificate with certificate identifier provided. 
    *
    * Direction: APP -> WPS
    * Local parameter: wps_sec_get_cert_req_struct
    * Peer buffer: None
    */    
    MSG_ID_WPS_SEC_GET_CERT_REQ,   

    /* This primitive is used to send response to MSG_ID_WPS_SEC_GET_CERT_REQ
    *
    * Direction: WPS -> APP
    * Local parameter: wps_sec_get_cert_rsp_struct
    * Peer buffer: None
    */    
    MSG_ID_WPS_SEC_GET_CERT_RSP,

#ifdef __BUILD_DOM__
} sap_wps_sec_enum;
#endif /* __BUILD_DOM__ */
    
#endif  /* _WPS_SAP_H */
