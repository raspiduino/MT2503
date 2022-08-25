extern "C"
{
#include "MMI_features.h"
#include "CallLogSrvGprot.h"
}

#define AVK_CALL_CALLLOG_NUM    1

typedef struct
{
    SRV_CLOG_HANDLE log_handle;
    SRV_CLOG_ID     log_id;
}avk_call_calllog_ctx;

static avk_call_calllog_ctx* g_avk_call_calllog_ctx;


S32 avk_call_calllog_cb(SRV_CLOG_HANDLE handle, S32 pid,
                            void *req_data, void *cnf_data, MMI_BOOL more, srv_clog_ret_enum ret)
{
    AVK_CASE_RESULT((SRV_CLOG_RET_OK == ret));
    AVK_ASYN_DONE();
    return SRV_CLOG_RET_STOP;
}

AVK_CASE(AVK_CALL_LOG_INIT,AVK_CALL_LOG)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_create_struct creat_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(AVK_LOG(!srv_clog_is_ready()))
    {
        AVK_CASE_RESULT(AVK_FAIL);
    }
    else
    {
        //**************************************************************************
        //srv_clog_create & srv_clog_init_para
        //**************************************************************************
        g_avk_call_calllog_ctx = (avk_call_calllog_ctx*)AVK_MALLOC(sizeof(avk_call_calllog_ctx));
        if (!g_avk_call_calllog_ctx)
        {
            AVK_CASE_RESULT(AVK_FAIL);
            return;
        }
        AVK_LOG(srv_clog_init_para(SRV_CLOG_PARA_CREATE, &creat_data));
        g_avk_call_calllog_ctx->log_handle = srv_clog_create(&creat_data);
        AVK_LOG_FUN(srv_clog_create,!SRV_CLOG_IS_ELM_INVALID(g_avk_call_calllog_ctx->log_handle));
        
        AVK_LOG(srv_clog_get_user_data(g_avk_call_calllog_ctx->log_handle));
    }  
}

AVK_ASYN_CASE(AVK_CALL_LOG_DEL_ALL,AVK_CALL_LOG_INIT)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = SRV_CLOG_RET_OK;
    srv_clog_del_all_logs_req_struct req_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_init_para(SRV_CLOG_PARA_DEL_ALL_LOGS_REQ, &req_data);
    AVK_LOG_ASYN(result = srv_clog_delete_all_logs(g_avk_call_calllog_ctx->log_handle, 0, &req_data, avk_call_calllog_cb));
    if (result < SRV_CLOG_RET_OK)
    {
        AVK_ASYN_DONE();
    }
}

AVK_ASYN_CASE(AVK_CALL_LOG_ADD,AVK_CALL_LOG_INIT)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = SRV_CLOG_RET_OK;
    srv_clog_log_struct log_data;
    srv_clog_call_log_struct *call_log;       
    SRV_PHB_ID  phb_id={0,0,0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    log_data.cate = SRV_CLOG_CATE_CALL;
    call_log = &log_data.data.call_log;
    call_log->cate = SRV_CLOG_CATE_CALL;
    call_log->sim_id = 0;
    call_log->log_type = SRV_CLOG_CLT_MISSED;
    call_log->sub_type = 0;
    call_log->log_id = SRV_CLOG_INVALID_ELM;
    call_log->phb_id = phb_id;
    call_log->timestamp[SRV_CLOG_LASTEST_TIME_IDX] = 0;
    call_log->duration[SRV_CLOG_LASTEST_TIME_IDX] = 0;
    call_log->total_num = 1;

    call_log->unread_num = 1;
    call_log->is_new_event = 1;


    call_log->is_private_cid = 0;
    mmi_wcscpy((WCHAR*) call_log->cid, (const WCHAR*)L"123456789");
    mmi_wcscpy((WCHAR*) call_log->name, (const WCHAR*)L"Mary"); 

    AVK_LOG_ASYN(result = srv_clog_add_log(g_avk_call_calllog_ctx->log_handle, 0, 
								(const srv_clog_add_log_req_struct*)&log_data, NULL, avk_call_calllog_cb));
    if (result < SRV_CLOG_RET_OK)
    { 
        AVK_ASYN_DONE();
    }    
}

AVK_CASE(AVK_CALL_LOG_NUM,AVK_CALL_LOG_INIT)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    U32 num_list;
	srv_clog_log_identity_struct identity;
    srv_clog_num_info_struct num_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AVK_LOG_EX(0 != srv_clog_get_unread_missed_call_num());

    AVK_LOG_EX(0 != srv_clog_get_sim_unread_missed_call_num(&num_list,1));
    srv_clog_init_para(SRV_CLOG_PARA_IDENTITY, &identity);
    identity.sim_id = MMI_SIM1|MMI_SIM2;
    identity.log_type = SRV_CLOG_CLT_ALL;
    identity.sub_type = SRV_CLOG_CALL_TYPE_NON_VOIP;

    result = srv_clog_get_list_num_info(g_avk_call_calllog_ctx->log_handle, &identity, &num_info);
    if (0 == result)
    {
        if ( num_info.num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS] != 1)          
        {
            AVK_LOG_FUN(srv_clog_get_list_num_info,AVK_FAIL);
        }
        else
        {
            AVK_LOG_FUN(srv_clog_get_list_num_info,AVK_PASS);
        }
    }
    else
    {
        AVK_LOG_FUN(srv_clog_get_list_num_info,AVK_FAIL);
    }
}

AVK_ASYN_CASE(AVK_CALL_LOG_UPDATE_ALL,AVK_CALL_LOG_INIT)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = SRV_CLOG_RET_OK;
    srv_clog_update_all_logs_req_struct req_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	srv_clog_init_para(SRV_CLOG_PARA_UPDATE_ALL_LOGS_REQ, &req_data);
    req_data.cate = SRV_CLOG_CATE_CALL;
    req_data.log_type = SRV_CLOG_CLT_MISSED;
    req_data.sim_id = MMI_SIM1 | MMI_SIM2;
    req_data.sub_type = SRV_CLOG_CALL_TYPE_ALL;
    req_data.req_fields = SRV_CLOG_LOG_FIELD_IS_NEW_EVENT;

    AVK_LOG_ASYN(result = srv_clog_update_all_logs(g_avk_call_calllog_ctx->log_handle, 0, &req_data, avk_call_calllog_cb));
    if (result < SRV_CLOG_RET_OK)
    {
        AVK_ASYN_DONE();
    }
}

AVK_CASE(AVK_CALL_LOG_GET_LIST_ID,AVK_CALL_LOG_INIT)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
	srv_clog_log_struct log;
    srv_clog_get_list_log_ids_req_struct log_ids_req_data;
    srv_clog_get_list_log_ids_cnf_struct log_ids_cnf_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	    
    srv_clog_init_para(SRV_CLOG_PARA_GET_LIST_LOG_IDS_REQ, &log_ids_req_data);
    srv_clog_init_para(SRV_CLOG_PARA_GET_LIST_LOG_IDS_CNF, &log_ids_cnf_data);                                                      

    log_ids_req_data.start_by = SRV_CLOG_BY_ID;
    log_ids_req_data.log_num = SRV_CLOG_LOG_ID_LIST_MAX_NUM;

    
    log_ids_req_data.start_elm = log_ids_cnf_data.next_start_elm;
    AVK_LOG_EX(srv_clog_get_list_log_ids(g_avk_call_calllog_ctx->log_handle, &log_ids_req_data, &log_ids_cnf_data) == SRV_CLOG_RET_OK);
    
    g_avk_call_calllog_ctx->log_id = log_ids_cnf_data.log_ids[0];

    if (srv_clog_get_log_by_id(g_avk_call_calllog_ctx->log_handle, log_ids_cnf_data.log_ids[0], SRV_CLOG_LOG_FIELD_CID, &log) != SRV_CLOG_RET_OK)
    {
        AVK_LOG_FUN(srv_clog_get_log_by_id,AVK_FAIL);
    }
    else
    {
        AVK_LOG_FUN(srv_clog_get_log_by_id,AVK_PASS);
//        AVK_LOG_FUN(srv_clog_update_log,MMI_FALSE == log.data.call_log.is_new_event);
    }
        
}


AVK_ASYN_CASE(AVK_CALL_LOG_UPDATE,AVK_CALL_LOG_INIT)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = SRV_CLOG_RET_OK;
    srv_clog_update_log_req_struct req_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    srv_clog_init_para(SRV_CLOG_PARA_UPDATE_LOG_REQ, &req_data);
    req_data.req_fields = SRV_CLOG_LOG_FIELD_IS_NEW_EVENT;
    req_data.log_data.cate = SRV_CLOG_CATE_CALL;
    req_data.log_data.data.call_log.log_id = g_avk_call_calllog_ctx->log_id;
    req_data.log_data.data.call_log.is_new_event = MMI_FALSE;

    AVK_LOG_ASYN(result = srv_clog_update_log(g_avk_call_calllog_ctx->log_handle, 0, &req_data, avk_call_calllog_cb));
    if (result < SRV_CLOG_RET_OK)
    {
        AVK_ASYN_DONE();
    }
}

AVK_CASE(AVK_CALL_LOG_GET_LIST_LOG,AVK_CALL_LOG_INIT)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_get_list_log_req_struct log_req_data;    
    srv_clog_get_list_log_cnf_struct log_cnf_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    memset(&log_req_data, 0, sizeof(log_req_data));
    memset(&log_cnf_data, 0, sizeof(log_cnf_data));

	log_req_data.log_type = SRV_CLOG_CLT_ALL;    
	log_req_data.get_by = SRV_CLOG_BY_IDX;
    log_req_data.get_elm = 0;
    log_req_data.fields = 0; // all fields


	AVK_LOG_EX(SRV_CLOG_RET_OK == srv_clog_get_list_log(g_avk_call_calllog_ctx->log_handle,
                          (const srv_clog_get_list_log_req_struct *)&log_req_data, 
                          &log_cnf_data));
}

AVK_CASE(AVK_CALL_LOG_GET_LAST_LOG,AVK_CALL_LOG_INIT)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_get_last_log_req_struct req_data;
    srv_clog_get_last_log_cnf_struct cnf_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	srv_clog_init_para(SRV_CLOG_PARA_GET_LAST_LOG_REQ, &req_data);
    req_data.fields = SRV_CLOG_LOG_FIELD_IDENTITY;
    SRV_CLOG_INIT_IDT(
        (srv_clog_log_identifier_struct*) & req_data,
        SRV_CLOG_CATE_CALL,
        MMI_SIM1 | MMI_SIM2,
        SRV_CLOG_CLT_ALL,
        SRV_CLOG_CALL_TYPE_ALL);
    AVK_LOG_EX(SRV_CLOG_RET_OK == srv_clog_get_last_log
                                            (g_avk_call_calllog_ctx->log_handle, 
                                            (const srv_clog_get_last_log_req_struct*)&req_data, 
                                            &cnf_data));
}


#ifndef __MMI_CONTACT_SLIM__
AVK_ASYN_CASE(AVK_CALL_LOG_SEARCH,AVK_CALL_LOG_INIT)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = SRV_CLOG_RET_OK;
    srv_clog_search_list_log_ids_req_struct search_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    srv_clog_init_para(SRV_CLOG_PARA_SEARCH_LIST_LOG_IDS_REQ,&search_req);
    AVK_LOG_ASYN(result = srv_clog_search_list_log_ids(g_avk_call_calllog_ctx->log_handle,0,&search_req,avk_call_calllog_cb));
    if (result < 0)
	{
	    AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();
	}
}
#endif /* ifndef __MMI_CONTACT_SLIM__ */


AVK_ASYN_CASE(AVK_CALL_LOG_DEL,AVK_CALL_LOG_INIT)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (AVK_LOG_ASYN(srv_clog_delete_log_by_id(g_avk_call_calllog_ctx->log_handle,0,g_avk_call_calllog_ctx->log_id,avk_call_calllog_cb)) < 0)
    {
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();
    }
}

AVK_CASE(AVK_CALL_DEINIT,AVK_CALL_LOG)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    AVK_LOG_EX(SRV_CLOG_RET_OK == srv_clog_destroy(g_avk_call_calllog_ctx->log_handle));
    AVK_FREE(g_avk_call_calllog_ctx);
}

