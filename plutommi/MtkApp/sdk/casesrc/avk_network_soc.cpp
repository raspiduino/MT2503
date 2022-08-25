extern "C"
{
#include "soc_api.h"
#include "cbm_api.h"
/**** Data Acccount related *****/
#include "DataAccountGProt.h"
#include "DtcntSrvGprot.h"
#include "DtcntSrvIprot.h"
/**Data Account End **/
}

AVK_ADD_ITEM(AVK_NW_SOC_AUTO,L"Auto case",AVK_NW_SOC);
 
/**************socket************************/
static S8 handle =  0;
static kal_int8 s = 0; //server handle
static sockaddr_struct addr;
MMI_BOOL is_test_all = MMI_FALSE;
MMI_BOOL success = MMI_TRUE;
MMI_BOOL is_server_created = MMI_FALSE;
kal_int8 server_soc_id;

static kal_uint8 vs_channel_id = 0xFF;
static kal_uint8 vs_request_id = 0;
static kal_uint8 vs_seq_num = 0;
static S32 vs_dl_status;
static kal_uint32 vs_account_id;
static kal_uint8 vs_app_id;

kal_uint8 addr_buf[4];

void avk_case4_cb(void *msg_ptr);
void avk_case5_cb(void *msg_ptr);
/**************socket end********************/


/*****************************************************************************
 * FUNCTION
 *  vs_nw_socket_001_con_notify
 * DESCRIPTION
 *  the callback function for message
 * PARAMETERS
 *  msg_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void vs_nw_socket_001_con_notify(void *msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_soc_notify_ind_struct *soc_notify = (app_soc_notify_ind_struct*) msg_ptr;
	kal_int32 ret = 0;
	kal_uint8 data_buf[1024];
	MMI_BOOL is_ready = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (handle != soc_notify->socket_id)
	{
		return;
	}
	
    switch (soc_notify->event_type) 
    {

        case SOC_WRITE:
            break;

        case SOC_READ:
			/* Check if socket is ready for reading */
			is_ready = soc_ready_for_read(handle);

			kal_prompt_trace( MOD_SOC, "vs_nw_socket_001_con_notify SOC_READ, is_ready=%d", is_ready);
			if(is_ready)
			{
			    AVK_LOG_FUN(soc_ready_for_read, AVK_PASS);

				memset(data_buf, 0, 1024);
				ret = soc_recv(soc_notify->socket_id, data_buf, 600, 0);
				if(ret == strlen((char*)data_buf) )
				{
					AVK_LOG_FUN(soc_recv, AVK_PASS);
                    AVK_CASE_RESULT(AVK_PASS);
				}
				else
				{
					AVK_LOG_FUN(soc_recv, AVK_FAIL);
                    AVK_CASE_RESULT(AVK_FAIL);
				}
			}
			else
			{
                AVK_LOG_FUN(soc_ready_for_read, AVK_FAIL);
                AVK_CASE_RESULT(AVK_FAIL);
			}
            
			/* Close the socket */
            soc_close(soc_notify->socket_id);
			kal_prompt_trace( MOD_SOC, "vs_nw_socket_001_con_notify, soc_close socketid=%d", soc_notify->socket_id);
			AVK_CASE_RESULT(AVK_PASS);
			AVK_ASYN_DONE();     
            break;
            
        case SOC_CONNECT:
			/* send data */
			kal_prompt_trace( MOD_SOC, "vs_nw_socket_001_con_notify SOC_CONNECT, soc_notify->result=%d",soc_notify->result);
			if(soc_notify->result != 0)
			{
				AVK_LOG_EX(0 < soc_send(soc_notify->socket_id, "GET / HTTP/1.1\r\n\r\n", strlen("GET / HTTP/1.1\r\n\r\n"), 0));

				/* enable the socket reading */
				//soc_read_notify(handle, KAL_TRUE);
            }
			else
			{
				kal_prompt_trace( MOD_SOC, "vs_nw_socket_001_con_notify SOC_CONNECT, soc_close socketid=%d", soc_notify->socket_id);
				soc_close(soc_notify->socket_id);
			    AVK_CASE_RESULT(AVK_FAIL);
			}
			break;

        case SOC_CLOSE:
		    //AVK_CASE_RESULT(AVK_FAIL);
		    kal_prompt_trace( MOD_SOC, "vs_nw_socket_001_con_notify SOC_CLOSE");
		    AVK_CASE_RESULT(AVK_PASS);
			AVK_ASYN_DONE();
		    
            break;
            
    }

}

/*****************************************************************************
 * FUNCTION
 *  vs_nw_socket_set_account_id
 * DESCRIPTION
 *  socket
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_nw_socket_set_account_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_int32 i; 
	U16 vs_apn[32];
	S8 temp[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vs_account_id = cbm_encode_data_account_id(CBM_DEFAULT_ACCT_ID, CBM_SIM_ID_SIM1, vs_app_id, KAL_FALSE);
}


static MMI_BOOL vs_get_host_by_name(void* inMsg)
{
    app_soc_get_host_by_name_ind_struct* dns_ind = (app_soc_get_host_by_name_ind_struct*)inMsg;

	kal_prompt_trace( MOD_SOC, "vs_get_host_by_name dns_ind->result=%d", dns_ind->result);
	
    if (dns_ind && dns_ind->result != FALSE)
    {
        sockaddr_struct addr;

        memset(&addr, 0x00, sizeof(addr));
        memcpy(addr.addr, dns_ind->addr, dns_ind->addr_len);
		memcpy(addr_buf, dns_ind->addr, dns_ind->addr_len);
        addr.addr_len = dns_ind->addr_len;
        addr.port = 80;

		kal_prompt_trace( MOD_SOC, "vs_get_host_by_name handle=%d", handle);
        switch (soc_connect(handle, &addr))
        {
        case SOC_SUCCESS:
        case SOC_WOULDBLOCK:
			kal_prompt_trace( MOD_SOC, "vs_get_host_by_name soc_connect return soc_connect or SOC_WOULDBLOCK");
			AVK_LOG_FUN(vm_get_host_by_name, AVK_PASS);
            mmi_frm_set_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, (PsIntFuncPtr)vs_nw_socket_001_con_notify, MMI_TRUE);
            break;

        default:          
			kal_prompt_trace( MOD_SOC, "vs_get_host_by_name soc_connect return default");
			AVK_LOG_FUN(vm_get_host_by_name, AVK_FAIL);
			AVK_CASE_RESULT(AVK_FAIL);
			AVK_ASYN_DONE();      
            break;
        }

        return MMI_TRUE;
    }
    else                                // dns analyse error.
    {
        AVK_LOG_FUN(vm_get_host_by_name, AVK_FAIL);
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();               
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_socket_001_connect
 * DESCRIPTION
 *  socket
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_ASYN_CASE(AVK_NW_SOC_AUTO_CASE1, AVK_NW_SOC_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 result;
    kal_uint8 option = 0, option_set = 0, option_get = 0;
	cbm_app_info_struct app_info;
	kal_int8 ret = 0;
	kal_uint8 addr_len = 0;
	soc_linger_struct linger_val;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, (PsIntFuncPtr)vs_nw_socket_001_con_notify);
	mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, (PsIntFuncPtr)avk_case4_cb);
	mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, (PsIntFuncPtr)avk_case5_cb);
	mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND, (PsIntFuncPtr)vs_get_host_by_name);

	memset(&app_info, 0, sizeof(app_info));
	app_info.app_icon_id = GetRootTitleIcon(IMG_GLOBAL_OK);
	app_info.app_str_id = STR_ID_AVK;
	app_info.app_type = DTCNT_APPTYPE_MRE_NET;//DTCNT_APPTYPE_MRE_WAP;
	cbm_register_app_id_with_app_info(&app_info, &vs_app_id);
	vs_nw_socket_set_account_id();

	/* Create socket */
    handle = soc_create(SOC_PF_INET, SOC_SOCK_STREAM, 0, MOD_MMI, vs_account_id);
    if (handle < 0)
    {
        AVK_LOG_FUN(soc_create, AVK_FAIL);
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();
    }
    else
    {
        AVK_LOG_FUN(soc_create, AVK_PASS);
    }

	option = SOC_READ | SOC_WRITE | SOC_ACCEPT | SOC_CONNECT | SOC_CLOSE;
	result = soc_setsockopt(handle, SOC_ASYNC, &option, sizeof(kal_uint8));
	option = KAL_TRUE;
	result = soc_setsockopt(handle, SOC_NBIO, &option, sizeof(option));
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	
	ret = soc_gethostbyname(KAL_FALSE,
					 MOD_MMI, 
					 100, 
					 "www.mediatek.com", 
					 addr_buf, 
					 &addr_len,
					 0,
					 vs_account_id);

	kal_prompt_trace( MOD_SOC, "AVK_ASYN_CASE soc_gethostbyname return =%d", ret);
    if (ret == SOC_SUCCESS)             // success
    {
        addr.addr[0] = addr_buf[0];    
        addr.addr[1] = addr_buf[1];
        addr.addr[2] = addr_buf[2];
        addr.addr[3] = addr_buf[3];
        addr.addr_len = addr_len;
        addr.port = 80;       
		AVK_LOG_FUN(soc_gethostbyname, AVK_PASS);
    }
    else if (ret == SOC_WOULDBLOCK)         // block
    {
        mmi_frm_set_protocol_event_handler(MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND, (PsIntFuncPtr)vs_get_host_by_name, MMI_TRUE);
		AVK_LOG_FUN(soc_gethostbyname, AVK_PASS);
        return;
    }
    else                                    // error
    {
        AVK_LOG_FUN(soc_gethostbyname, AVK_FAIL);
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();   
		return;
	}

	kal_prompt_trace( MOD_SOC, "AVK_ASYN_CASE soc_connect handle =%d", handle);
    /* socket connect */
    result = soc_connect((kal_int8) handle, &addr);
	kal_prompt_trace( MOD_SOC, "AVK_ASYN_CASE soc_connect return =%d", result);
    if (result == SOC_SUCCESS)
    {
		AVK_LOG_FUN(soc_connect, AVK_PASS);
		mmi_frm_set_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, (PsIntFuncPtr)vs_nw_socket_001_con_notify, MMI_TRUE);
    }
	else if (result == SOC_WOULDBLOCK)
	{
		AVK_LOG_FUN(soc_connect, AVK_PASS);
		mmi_frm_set_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, (PsIntFuncPtr)vs_nw_socket_001_con_notify, MMI_TRUE);
	}
    else
    {
        AVK_LOG_FUN(soc_connect, AVK_FAIL);
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();        
    }
}



/*****************************************************************************
 * FUNCTION
 *  vs_nw_socket_002
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_NW_SOC_AUTO_CASE2, AVK_NW_SOC_AUTO)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	sockaddr_struct sock_add;
	kal_int32 detailed_cause = 0;
	kal_uint8 ip_addr[4], cksum_buf[4] = "abc";
	MMI_BOOL ret  = MMI_FALSE;
	MMI_BOOL ip_validity = MMI_FALSE;
	kal_int8 ip_ret = 0, close = 0, error = 0; 
	cbm_app_info_struct app_info;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, (PsIntFuncPtr)vs_nw_socket_001_con_notify);
	mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, (PsIntFuncPtr)avk_case4_cb);
	mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, (PsIntFuncPtr)avk_case5_cb);
	mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND, (PsIntFuncPtr)vs_get_host_by_name);

	memset(&app_info, 0, sizeof(app_info));
	app_info.app_icon_id = GetRootTitleIcon(IMG_GLOBAL_OK);
	app_info.app_str_id = STR_ID_AVK;
	app_info.app_type = DTCNT_APPTYPE_MRE_NET;//DTCNT_APPTYPE_MRE_WAP;
	cbm_register_app_id_with_app_info(&app_info, &vs_app_id);
	vs_nw_socket_set_account_id();

	/* Create socket */
    handle = soc_create(SOC_PF_INET, SOC_SOCK_STREAM, 0, MOD_MMI, vs_account_id);
    if (handle < 0)
    {
        AVK_LOG_FUN(soc_create, AVK_FAIL);
		return;
    }
    else
    {
        AVK_LOG_FUN(soc_create, AVK_PASS);
    }


	/* check for IP validity */
	AVK_LOG_EX(soc_ip_check("74.125.153.104", ip_addr, &ip_validity));

	/* Get the local IP */
	memset(ip_addr, 0, 4);
	AVK_LOG_EX(SOC_SUCCESS == soc_getlocalip(ip_addr));

	/* get account local IP */
	memset(ip_addr, 0, 4);
	AVK_LOG_EX(soc_get_account_localip( handle, ip_addr) == SOC_SUCCESS);

	/* Get local IP by account ID */
	memset(ip_addr, 0, 4);
	AVK_LOG_EX(soc_get_localip_by_account(0x3e, ip_addr) != SOC_SUCCESS);
	
	/* Get socket address */
	memset(&sock_add, 0, sizeof(sockaddr_struct));
	AVK_LOG_EX(soc_getsockaddr(handle, KAL_TRUE, &sock_add) == SOC_SUCCESS);
	
	/* Set the last error */
	error = 4;
	detailed_cause = 4;
	AVK_LOG(soc_set_last_error(handle, error, detailed_cause));
	
	/* get last socket error*/
	error = 0;
	detailed_cause = 0;
	AVK_LOG(soc_get_last_error(handle, &error, &detailed_cause));

	/* Compute the checksum */
	AVK_LOG_EX(0 < soc_cksum((kal_uint16 *)cksum_buf, 4));

	/* set the module */
	AVK_LOG_EX(soc_set_module(handle, MOD_MMI));

	/* close the socket */
	if(handle != 0)
	{	
		AVK_LOG_EX(soc_close(handle) == SOC_SUCCESS);
	}

}




/*****************************************************************************
 * FUNCTION
 *  AVK_NW_SOC_AUTO_CASE3
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_NW_SOC_AUTO_CASE3, AVK_NW_SOC_AUTO)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	soc_dns_naptr_struct entry_naptr;
	soc_dns_srv_struct entry_srv;
	kal_uint32 data = 0, domain_length = 0;
	MMI_BOOL timer_set = MMI_FALSE;
	kal_uint16 sec = 0;
	kal_int8 close = 0;
	kal_uint8 addr[4];
	kal_uint8 addr_host2[12];
	kal_uint8 addr_domain[35];
	kal_uint8 addr_len = 0;
	kal_uint8 out_entry = 0;
	cbm_app_info_struct app_info;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, (PsIntFuncPtr)vs_nw_socket_001_con_notify);
	mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, (PsIntFuncPtr)avk_case4_cb);
	mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, (PsIntFuncPtr)avk_case5_cb);
	mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND, (PsIntFuncPtr)vs_get_host_by_name);

	memset(&app_info, 0, sizeof(app_info));
	app_info.app_icon_id = GetRootTitleIcon(IMG_GLOBAL_OK);
	app_info.app_str_id = STR_ID_AVK;
	app_info.app_type = DTCNT_APPTYPE_MRE_NET;//DTCNT_APPTYPE_MRE_WAP;
	cbm_register_app_id_with_app_info(&app_info, &vs_app_id);
	vs_nw_socket_set_account_id();

	/* Create socket */               
    handle = soc_create(SOC_PF_INET, SOC_SOCK_STREAM, 0, MOD_MMI, vs_account_id);
    if (handle < 0)
    {
        AVK_LOG_FUN(soc_create, AVK_FAIL);
    }
    else
    {
        AVK_LOG_FUN(soc_create, AVK_PASS);
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
#endif	
	AVK_LOG_EX(soc_htonl(1000));

	/* soc htons */
	AVK_LOG_EX(soc_htons(1000));

	/* get host by name */
	memset(addr, 0 , 4);
	vs_nw_socket_set_account_id();

	kal_prompt_trace( MOD_SOC, "AVK_CASE soc_gethostbyname ");
	AVK_LOG_EX(soc_gethostbyname(KAL_FALSE,
							 MOD_MMI, 
							 100, 
							 "www.baidu.com", 
							 addr, 
							 &addr_len,
							 0,
							 vs_account_id));

	/* get multiple hosts */
	memset(addr_host2, 0 , 12);
	addr_len = 0;
	kal_prompt_trace( MOD_SOC, "AVK_CASE soc_gethostbyname2 ");
	AVK_LOG_EX(soc_gethostbyname2 (KAL_FALSE,
							 MOD_MMI, 
							 100, 
							 "www.baidu.com", 
							 addr_host2, 
							 &addr_len,
							 0,
							 vs_account_id,
							 3,
							 &out_entry));
	
		
	/*  get host by address */
	memset(addr_domain, 0 , 35);
	addr_len = 4;
	domain_length = 35;
	kal_prompt_trace( MOD_SOC, "AVK_CASE soc_gethostbyaddr ");
	AVK_LOG_EX(soc_gethostbyaddr(KAL_FALSE,
                           MOD_MMI,
                           100,
                           (kal_char *)addr_domain,
			               &domain_length,
                           addr,
                           addr_len,
                           0,
                           vs_account_id));
	
	
	/* get hostname by naptr */
	out_entry = 0;
	memset(&entry_naptr, 0, sizeof(soc_dns_naptr_struct));

	kal_prompt_trace( MOD_SOC, "AVK_CASE soc_gethostbynaptr ");
	AVK_LOG_EX(soc_gethostbynaptr(MOD_MMI, 
								100, 
								"www.baidu.com", 
								0, 
								vs_account_id, 
								&entry_naptr, 
								1, 
								&out_entry));


	/* get host by srv */
	out_entry = 0;
	memset(&entry_srv, 0, sizeof(soc_dns_srv_struct));
	kal_prompt_trace( MOD_SOC, "AVK_CASE soc_gethostbysrv ");
	AVK_LOG_EX(soc_gethostbysrv(MOD_MMI, 
								100, 
								"www.baidu.com", 
								0, 
								vs_account_id, 
								&entry_srv, 
								1, 
								&out_entry));

	/* abort DNS query */
	memset(addr, 0 , 4);
	kal_prompt_trace( MOD_SOC, "AVK_CASE soc_gethostbyname ");
	AVK_LOG_EX(soc_gethostbyname(KAL_FALSE,
							 MOD_MMI, 
							 100, 
							 "www.baidu.com", 
							 addr, 
							 &addr_len,
							 0,
							 vs_account_id));

	kal_prompt_trace( MOD_SOC, "AVK_CASE soc_abort_dns_query ");
	AVK_LOG_EX(soc_abort_dns_query(KAL_TRUE, 
								MOD_MMI, 
								KAL_FALSE, 
								0, 
								KAL_FALSE, 
								0, 
								KAL_FALSE, 
								0) == SOC_SUCCESS);
		
	/* close the socket */
	if(handle != 0)
	{	
		kal_prompt_trace( MOD_SOC, "AVK_CASE soc_close ");
		AVK_LOG_EX(soc_close(handle) == SOC_SUCCESS);
	}

}




/*****************************************************************************
 * FUNCTION
 *  vs_nw_socket_002_server_notify
 * DESCRIPTION
 *  the callback function for message
 * PARAMETERS
 *  msg_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void avk_case4_cb(void *msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 option;
    app_soc_notify_ind_struct *soc_notify = (app_soc_notify_ind_struct*) msg_ptr;
    char send_buffer[10];
    char recv_buffer[10];
    soc_msghdr_struct msghdr;
    soc_iovec_struct iov;
    kal_int32 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_prompt_trace( MOD_SOC, "avk_case4_cb soc_notify->event_type=%d soc_notify->result=%d", soc_notify->event_type, soc_notify->result);
	if (s != soc_notify->socket_id)
	{
		return;
	}
	
    switch (soc_notify->event_type)
    {
        case SOC_WRITE:
            strcpy(send_buffer, "abcde");
            /* To test soc_sendmsg, change interface of test case 02 server */
            //soc_send(server_soc_id, (kal_uint8*) send_buffer, 5, 0);
            memset(&msghdr, 0, sizeof(msghdr));
            iov.iov_buf = (void *)send_buffer;
            iov.iov_len = 5;
            msghdr.iov = (soc_iovec_struct *)&iov;
            msghdr.iov_num = 1;
            error = soc_sendmsg((kal_int8)server_soc_id, (soc_msghdr_struct *)&msghdr, 0);

			kal_prompt_trace( MOD_SOC, "avk_case4_cb soc_sendmsg return %d ",error);
            if(error > 0)
            {
                AVK_LOG_FUN(soc_sendmsg, AVK_PASS);
            }
            else
            {
                soc_close(soc_notify->socket_id);
                AVK_LOG_FUN(soc_sendmsg, AVK_FAIL);
                AVK_CASE_RESULT(AVK_FAIL);
                AVK_ASYN_DONE();
            }
            break;

        case SOC_READ:
            /* To test soc_recvmsg, change interface of test case 02 server */
            //soc_recv(server_soc_id, (kal_uint8*) recv_buffer, 5, 0);
            memset(&msghdr, 0, sizeof(soc_msghdr_struct));
            iov.iov_buf = recv_buffer;
            iov.iov_len = 5;
            msghdr.iov = &iov;
            msghdr.iov_num = 1;
            error = soc_recvmsg((kal_int8) server_soc_id, &msghdr, 0);

			kal_prompt_trace( MOD_SOC, "avk_case4_cb soc_recvmsg return %d ",error);
            if(error > 0)
            {
                AVK_LOG_FUN(soc_recvmsg, AVK_PASS);
            }
            else
            {
                soc_close(soc_notify->socket_id);
                AVK_LOG_FUN(soc_recvmsg, AVK_FAIL);
                AVK_CASE_RESULT(AVK_FAIL);
                AVK_ASYN_DONE();
            }

            AVK_LOG_NORMAL(soc_read_notify(server_soc_id, KAL_FALSE));
            break;

        case SOC_CONNECT:
			kal_prompt_trace( MOD_SOC, "avk_case4_cb soc_recvmsg soc_connect");
			if(soc_notify->result != 0)
            {
                /* To test soc_sendmsg, change interface of test case 02 server */
                //soc_send(server_soc_id, (kal_uint8*) send_buffer, 5, 0);
                memset(&msghdr, 0, sizeof(msghdr));
                iov.iov_buf = (void *)send_buffer;
                iov.iov_len = 5;
                msghdr.iov = (soc_iovec_struct *)&iov;
                msghdr.iov_num = 1;
                error = soc_sendmsg((kal_int8)server_soc_id, (soc_msghdr_struct *)&msghdr, 0);

				kal_prompt_trace( MOD_SOC, "avk_case4_cb soc_recvmsg soc_connect soc_sendmsg return %d", error);
                if(error > 0)
                {
                    AVK_LOG_FUN(soc_sendmsg, AVK_PASS);
                }
                else
                {
                    soc_close(soc_notify->socket_id);
                    AVK_LOG_FUN(soc_sendmsg, AVK_FAIL);
                    AVK_CASE_RESULT(AVK_FAIL);
                    AVK_ASYN_DONE();
                }

            }
            else
            {
                soc_close(soc_notify->socket_id);
                AVK_CASE_RESULT(AVK_FAIL);
                AVK_ASYN_DONE();
            }
            break;

        case SOC_ACCEPT:
			kal_prompt_trace( MOD_SOC, "avk_case4_cb soc_recvmsg SOC_ACCEPT ");
            AVK_LOG(server_soc_id = soc_accept(soc_notify->socket_id, NULL));
            option = SOC_READ | SOC_WRITE | SOC_ACCEPT | SOC_CONNECT | SOC_CLOSE;
            AVK_LOG(soc_setsockopt(server_soc_id, SOC_ASYNC, &option, sizeof(kal_uint8)));
            AVK_LOG(soc_close(soc_notify->socket_id));
            AVK_CASE_RESULT(AVK_PASS);
            AVK_ASYN_DONE();
            break;

        case SOC_CLOSE:
			kal_prompt_trace( MOD_SOC, "avk_case4_cb soc_recvmsg SOC_CLOSE ");
            soc_close(soc_notify->socket_id);
            AVK_CASE_RESULT(AVK_PASS);
            AVK_ASYN_DONE();
            break;
    }

}

/*****************************************************************************
 * FUNCTION
 *  vs_nw_socket_002_client_notify
 * DESCRIPTION
 *  the callback function for message
 * PARAMETERS
 *  msg_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void avk_case5_cb(void *msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_soc_notify_ind_struct *soc_notify = (app_soc_notify_ind_struct*) msg_ptr;
    char send_buffer[] = "Hello";
    char recv_buffer[10];
	kal_int32 error;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	kal_prompt_trace( MOD_SOC, "avk_case5_cb soc_notify->event_type=%d soc_notify->result=%d", soc_notify->event_type, soc_notify->result);
    switch (soc_notify->event_type)
    {
    	if (soc_notify->socket_id == server_soc_id)
		{
        case SOC_WRITE:
			
            error = soc_send(server_soc_id, (kal_uint8*) send_buffer, 5, 0);
			kal_prompt_trace( MOD_SOC, "avk_case5_cb soc_send error %d", error);
            if(error > 0)
            {
                AVK_LOG_FUN(soc_send, AVK_PASS);
            }
            else
            {
                soc_close(soc_notify->socket_id);
                AVK_LOG_FUN(soc_send, AVK_FAIL);
                AVK_CASE_RESULT(AVK_FAIL);
                AVK_ASYN_DONE();
            }            
            break;
            
        case SOC_READ:
			memset(recv_buffer, 0, 10);
            error = soc_recv(soc_notify->socket_id, (kal_uint8*) recv_buffer, 5, 0);
			kal_prompt_trace( MOD_SOC, "avk_case5_cb soc_recv error %d", error);
            if(error > 0)
            {
                AVK_LOG_FUN(soc_send, AVK_PASS);
            }
            else
            {
                soc_close(soc_notify->socket_id);
                AVK_LOG_FUN(soc_send, AVK_FAIL);
                AVK_CASE_RESULT(AVK_FAIL);
                AVK_ASYN_DONE();
            }            

            AVK_LOG(soc_close(soc_notify->socket_id));
            AVK_LOG(soc_shutdown(s, SHUT_RDWR));

            break;
            
		case SOC_ACCEPT:
            if (soc_notify->result)
            {
				sockaddr_struct addr;
				soc_getlocalip(addr.addr);
				addr.addr_len = sizeof(long);
				addr.port = (unsigned short)88;
				
				server_soc_id = soc_accept(soc_notify->socket_id, &addr);
				kal_prompt_trace( MOD_SOC, "avk_case5_cb SOC_ACCEPT ");
                if(server_soc_id > 0)
                {
                    AVK_LOG_FUN(soc_accept, AVK_PASS);
                }
                else
                {
                    soc_close(soc_notify->socket_id);
                    AVK_LOG_FUN(soc_accept, AVK_FAIL);
                    AVK_CASE_RESULT(AVK_FAIL);
                    AVK_ASYN_DONE();
                }
            }
			break;
            
        case SOC_CONNECT:
			if(soc_notify->result != 0)
            {
                error = soc_send(soc_notify->socket_id, (kal_uint8*) send_buffer, 5, 0);
				kal_prompt_trace( MOD_SOC, "avk_case5_cb SOC_CONNECT soc_send return %d ", error);
                if(error > 0)
                {
                    AVK_LOG_FUN(soc_send, AVK_PASS);
                }
                else
                {
                    soc_close(soc_notify->socket_id);
                    AVK_LOG_FUN(soc_send, AVK_FAIL);
                    AVK_CASE_RESULT(AVK_FAIL);
                    AVK_ASYN_DONE();
                }
                
            }
            else
            {
                soc_close(soc_notify->socket_id);
                AVK_CASE_RESULT(AVK_FAIL);
                AVK_ASYN_DONE();
            }
            break;
            
        case SOC_CLOSE:
            soc_close(soc_notify->socket_id);
            AVK_CASE_RESULT(AVK_PASS);
            AVK_ASYN_DONE();
            break;
    }
    }

}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_socket_002_server
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_ASYN_CASE(AVK_NW_SOC_AUTO_CASE4, AVK_NW_SOC_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8  result;
    sockaddr_struct addr;
    kal_uint8 option;
	kal_int32 accountid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //SetProtocolEventHandler(avk_case4_cb, MSG_ID_APP_SOC_NOTIFY_IND);
	mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, (PsIntFuncPtr)vs_nw_socket_001_con_notify);
	mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, (PsIntFuncPtr)avk_case4_cb);
	mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, (PsIntFuncPtr)avk_case5_cb);
	mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND, (PsIntFuncPtr)vs_get_host_by_name);

	is_test_all = MMI_FALSE;
	//accountid = cbm_encode_data_account_id(CBM_LOOPBACK_ACCT_ID, (cbm_sim_id_enum)0/*CBM_SIM_ID_SIM1*/, vs_app_id, KAL_FALSE);
	accountid = cbm_encode_data_account_id(CBM_DEFAULT_ACCT_ID, (cbm_sim_id_enum)0/*CBM_SIM_ID_SIM1*/, vs_app_id, KAL_FALSE);

	//cbm_open_bearer(accountid);
    s = soc_create(SOC_PF_INET, SOC_SOCK_STREAM, 0, MOD_MMI, accountid);
    if (s < 0)
    {
        AVK_LOG_FUN(soc_create, AVK_FAIL);
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();
        return;
    }
    AVK_LOG_FUN(soc_create, AVK_PASS);
    
	/* set NBIO */
	is_server_created = MMI_TRUE;
	option = KAL_TRUE;
	AVK_LOG(soc_setsockopt(s, SOC_NBIO, &option, sizeof(option)));

    /* Set async mode */
    option = SOC_READ | SOC_WRITE | SOC_ACCEPT | SOC_CONNECT | SOC_CLOSE;
    result = soc_setsockopt(s, SOC_ASYNC, &option, sizeof(kal_uint8));
	kal_prompt_trace( MOD_SOC, "AVK_ASYN_CASE 4 SOC_CONNECT soc_setsockopt return %d ", result);
    if (result != SOC_SUCCESS && is_server_created)
    {
        AVK_LOG_FUN(soc_setsockopt, AVK_FAIL);
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();        
        return;
    }
	else if(result == SOC_SUCCESS)
    {
	    AVK_LOG_FUN(soc_setsockopt, AVK_PASS);
	}
	else 
    {
		AVK_LOG_FUN(soc_setsockopt, AVK_FAIL);
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();        
        return;
    }

    /* Get Default IP */
	
    addr.addr[0] = 127;
    addr.addr[1] = 0;
    addr.addr[2] = 0;
    addr.addr[3] = 1;
	
	//AVK_LOG(soc_getlocalip(addr.addr));
    addr.addr_len = sizeof(long);
    addr.port = 80;

    result = soc_bind((kal_int8) s, &addr);
	kal_prompt_trace( MOD_SOC, "AVK_ASYN_CASE 4 SOC_CONNECT soc_bind return %d ", result);
	if (result < 0)
    {
        AVK_LOG_FUN(soc_bind, AVK_FAIL);
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();     
    }
    else
    {
        AVK_LOG_FUN(soc_bind, AVK_PASS);
    }
    
    result = soc_listen(s, 3);
	kal_prompt_trace( MOD_SOC, "AVK_ASYN_CASE 4 SOC_CONNECT soc_listen return %d ", result);
	if (result < 0)
    {
        AVK_LOG_FUN(soc_listen, AVK_FAIL);
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();     
    }
    else
    {
        AVK_LOG_FUN(soc_listen, AVK_PASS);
    }
    mmi_frm_set_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, (PsIntFuncPtr)avk_case4_cb, MMI_TRUE);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    AVK_CASE_RESULT(AVK_PASS);
    AVK_ASYN_DONE();
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_socket_002_client
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_ASYN_CASE(AVK_NW_SOC_AUTO_CASE5, AVK_NW_SOC_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 s, result;
    sockaddr_struct addr;
    kal_uint8 option;
	kal_uint32 account_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    success = MMI_TRUE;

	mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, (PsIntFuncPtr)vs_nw_socket_001_con_notify);
	mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, (PsIntFuncPtr)avk_case4_cb);
	mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, (PsIntFuncPtr)avk_case5_cb);
	mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND, (PsIntFuncPtr)vs_get_host_by_name);

	//account_id = cbm_encode_data_account_id(CBM_LOOPBACK_ACCT_ID, CBM_SIM_ID_SIM1, vs_app_id, KAL_FALSE);
	account_id = cbm_encode_data_account_id(CBM_DEFAULT_ACCT_ID, CBM_SIM_ID_SIM1, vs_app_id, KAL_FALSE);
	
    handle = soc_create(SOC_PF_INET, SOC_SOCK_STREAM, 0, MOD_MMI, account_id);

    if (handle < 0)
    {
        AVK_LOG_FUN(soc_create, AVK_FAIL);
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();   
        return;
    }
    else
    {
        AVK_LOG_FUN(soc_create, AVK_PASS);
    }
    
	option = SOC_READ | SOC_WRITE | SOC_ACCEPT | SOC_CONNECT | SOC_CLOSE;
	result = soc_setsockopt(handle, SOC_ASYNC, &option, sizeof(kal_uint8));
	option = KAL_TRUE;
	result = soc_setsockopt(handle, SOC_NBIO, &option, sizeof(option));


    /* INADDR_ANY */
        addr.addr[0] = 127;    
        addr.addr[1] = 0;
        addr.addr[2] = 0;
        addr.addr[3] = 1;

    //soc_getlocalip(addr.addr);
    addr.addr_len = sizeof(long);
    addr.port = (unsigned short)80;

    result = soc_connect(handle, &addr);
	kal_prompt_trace( MOD_SOC, "AVK_ASYN_CASE 5 SOC_CONNECT soc_listen return %d ", result);
    if (result == SOC_SUCCESS)
    {
		AVK_LOG_FUN(soc_connect, AVK_PASS);
		mmi_frm_set_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, (PsIntFuncPtr)avk_case5_cb, MMI_TRUE);
    }
	else if (result == SOC_WOULDBLOCK)
	{
		AVK_LOG_FUN(soc_connect, AVK_PASS);
		mmi_frm_set_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, (PsIntFuncPtr)avk_case5_cb, MMI_TRUE);
	}
    else
    {
        AVK_LOG_FUN(soc_connect, AVK_FAIL);
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();        
    }

}

