extern "C"
{
#include "UMSrvGprot.h"
#include "smssrvgprot.h"
}
typedef struct
{
    U32     count;
    S32     list_id;
    srv_um_list_cntx_struct*    um_ctx;
    srv_um_box_identity_struct  um_box;
    srv_um_list_filter_struct   um_filter;
}avk_msg_um_ctx;

static avk_msg_um_ctx* g_p_msg_um_cntx;


static void avk_msg_um_init2(void);

void avk_msg_um_init1_cb(srv_sms_callback_struct* callback_data)
{
    if (callback_data->result)
    {
        avk_msg_um_init2();
    }
    else
    {
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();
    }
}

void avk_msg_um_init2_cb(srv_sms_callback_struct* callback_data)
{
    g_p_msg_um_cntx->count++;
    if (g_p_msg_um_cntx->count < 2)
    {
        avk_msg_um_init2();
        return;
    }
    AVK_CASE_RESULT(callback_data->result);
    AVK_ASYN_DONE();
}

S32 avk_msg_um_get_msg_num_cb(S32 pid, srv_um_get_msg_num_result* rsp, S32 user_data)
{
    if (rsp->error != 0 ||
        rsp->inbox_msg_number != 0 ||
        rsp->inbox_unread_msg_number != 0 ||
        rsp->unsent_msg_number != 0 ||
        rsp->sent_msg_number != 0 ||
        rsp->draft_msg_number != 2)
    {
        AVK_CASE_RESULT(AVK_FAIL);
    }
    else
    {
        AVK_CASE_RESULT(AVK_PASS);
    }
    AVK_ASYN_DONE();
    return 0;
}

void avk_msg_um_list_notify_handler (S32 event, S32 list_cid, S32 user_data)
{
    //do nothing
}

S32 avk_msg_um_get_list_cb(S32 pid, srv_um_get_list_result* rsp, S32 user_data)
{
    AVK_CASE_RESULT(!rsp->error);
    AVK_ASYN_DONE();
    return 0;
}

S32 avk_msg_um_get_msg_info_cb(S32 pid, srv_um_get_msg_info_result* rsp, S32 user_data)
{
    AVK_CASE_RESULT(!(rsp->error != 0 || rsp->no_of_success <= 0));
    AVK_ASYN_DONE();
    return 0;
}

S32 avk_msg_um_mark_several_op_cb(S32 pid, srv_um_mark_several_op_result* rsp, S32 user_data)
{
    AVK_CASE_RESULT(!rsp->error);
    if (AVK_GET_CASE_RESULT())
    {
        AVK_ASYN_DONE();
    }        
    return 0;
}


S32 avk_msg_um_get_thread_info_cb(S32 pid, srv_um_get_thread_info_result* rsp, S32 user_data)
{
    AVK_CASE_RESULT(!(rsp->error != 0 || rsp->no_of_success <= 0));
    AVK_ASYN_DONE();
    return 0;
}



S32 avk_msg_um_mark_several_thread_op_cb(S32 pid, srv_um_mark_several_thread_op_result* rsp, S32 user_data)
{
    AVK_CASE_RESULT(!rsp->error);
    AVK_ASYN_DONE();
    return 0;
}

S32 avk_msg_um_delete_folder_cb(S32 pid, srv_um_delete_folder_result* rsp, S32 user_data)
{
    AVK_CASE_RESULT(rsp->error == 0);
    AVK_ASYN_DONE();
    return 0;
}

static void avk_msg_um_init1(void)
{
    srv_sms_delete_msg_list((srv_sms_box_enum)0xffffffff,SRV_SMS_SIM_1,avk_msg_um_init1_cb,NULL);
}

static void avk_msg_um_init2(void)
{
    SMS_HANDLE handle;
    handle = srv_sms_get_save_handle();
    srv_sms_set_content(handle,(S8*)L"123",8);
    srv_sms_save_msg(handle,avk_msg_um_init2_cb,NULL);
}

/*****************************************************************************
 * FUNCTION
 *  init function
 * DESCRIPTION
 *  init
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_ASYN_CASE(AVK_MSG_UM_INIT,AVK_MSG_UM)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_p_msg_um_cntx = (avk_msg_um_ctx*)AVK_MALLOC(sizeof(avk_msg_um_ctx));
    if (!g_p_msg_um_cntx)
    {
        AVK_CASE_RESULT(AVK_FAIL);
        return;
    }
    g_p_msg_um_cntx->um_box.msg_type = SRV_UM_MSG_SMS;
    g_p_msg_um_cntx->um_box.msg_box_type = SRV_UM_MSG_BOX_DRAFT;
    g_p_msg_um_cntx->um_box.sim_id = SRV_UM_SIM_GSM_SIM1;

    memset(&g_p_msg_um_cntx->um_filter, 0, sizeof(srv_um_list_filter_struct));

    g_p_msg_um_cntx->count = 0;
    avk_msg_um_init1(); 
}

AVK_CASE(AVK_MSG_UM_BASE,AVK_MSG_UM_INIT)
{    
    AVK_LOG_EX(srv_um_check_support_type(SRV_UM_MSG_SMS));
    AVK_LOG_EX(srv_um_check_ready_type(SRV_UM_MSG_SMS));
    AVK_LOG_EX(srv_um_check_ready());
    AVK_LOG_EX(SRV_UM_MSG_SMS&srv_um_support_msg_type());
    AVK_LOG_EX(SRV_UM_RESULT_OK == srv_um_clear_msg_info_cache());
}

AVK_ASYN_CASE(AVK_MSG_UM_GET_NUM,AVK_MSG_UM_BASE)
{  
    if (AVK_LOG_ASYN(srv_um_get_msg_num(SRV_UM_MSG_SMS,SRV_UM_SIM_GSM_SIM1,avk_msg_um_get_msg_num_cb,NULL)) < 0)
    {
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();
    }
}

AVK_ASYN_CASE(AVK_MSG_UM_GET_LIST,AVK_MSG_UM_BASE)
{  
    if (AVK_LOG_ASYN(srv_um_get_list(SRV_UM_LIST_TYPE_MSG_NODE,
                        g_p_msg_um_cntx->um_box,&g_p_msg_um_cntx->um_filter,avk_msg_um_get_list_cb,NULL)) < 0)    
    {
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();
    }    
}


AVK_CASE(AVK_MSG_UM_CHECK_LIST,AVK_MSG_UM_GET_LIST)
{
    g_p_msg_um_cntx->list_id = srv_um_check_list(SRV_UM_LIST_TYPE_MSG_NODE,
                      g_p_msg_um_cntx->um_box,
                      &g_p_msg_um_cntx->um_filter,
                      avk_msg_um_list_notify_handler,
                      NULL,
                      &g_p_msg_um_cntx->um_ctx
                      );
    AVK_LOG_FUN(srv_um_check_list,g_p_msg_um_cntx->list_id > 0);   
}

AVK_ASYN_CASE(AVK_MSG_UM_GET_INFO,AVK_MSG_UM_CHECK_LIST)
{    
    AVK_LOG_ASYN(srv_um_get_msg_info(g_p_msg_um_cntx->um_box,
                        (srv_um_msg_node_struct*)g_p_msg_um_cntx->um_ctx->list,1,avk_msg_um_get_msg_info_cb,NULL));
}

AVK_ASYN_CASE(AVK_MSG_UM_GHECK_INFO,AVK_MSG_UM_GET_INFO)
{
    S32 res;
    srv_um_msg_info_struct info_struct;
    srv_um_msg_info_struct* info_struct_p;
    U32 mark_status[1] = {0x80000000};
    

    res = srv_um_check_msg_info(g_p_msg_um_cntx->um_box,
                (srv_um_msg_node_struct*)g_p_msg_um_cntx->um_ctx->list,g_p_msg_um_cntx->um_ctx->msg_number,0,1,&info_struct);
    AVK_LOG_FUN(srv_um_check_msg_info,0 == res);
    if (SRV_UM_RESULT_OK == res)
    {
        S32 start,total;
        S32 pid = 0;
        AVK_LOG_EX(0 == srv_um_check_msg_info_by_ref(g_p_msg_um_cntx->um_box,
                (srv_um_msg_node_struct*)g_p_msg_um_cntx->um_ctx->list,g_p_msg_um_cntx->um_ctx->msg_number,0,1,&info_struct_p));
        
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
        AVK_LOG_ASYN(pid = srv_um_mark_several_op( g_p_msg_um_cntx->um_box,
                                (srv_um_msg_node_struct*)g_p_msg_um_cntx->um_ctx->list,
                                g_p_msg_um_cntx->um_ctx->msg_number,
                                mark_status,
                                SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_ARCHIVE,
                                avk_msg_um_mark_several_op_cb,
                                NULL
                                     ));
        AVK_LOG_EX(SRV_UM_RESULT_OK == (res = srv_um_get_request_progress(pid,&start,&total)));                             
        if (SRV_UM_RESULT_OK == res)
        {
                AVK_LOG(res = srv_um_cancel_request(pid));
                if (SRV_UM_RESULT_OK == res)
                {
                    srv_um_mark_several_op( g_p_msg_um_cntx->um_box,
                                    (srv_um_msg_node_struct*)g_p_msg_um_cntx->um_ctx->list,
                                    g_p_msg_um_cntx->um_ctx->msg_number,
                                    mark_status,
                                    SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_ARCHIVE,
                                    avk_msg_um_mark_several_op_cb,
                                    NULL);
                } 

        }
        else
        {
            AVK_ASYN_DONE();
        }
#else 
    AVK_LOG_FUN_UNSUPPORTED(srv_um_mark_several_op);
    AVK_LOG_FUN_UNSUPPORTED(srv_um_get_request_progress);
    AVK_LOG_FUN_UNSUPPORTED(srv_um_cancel_request);
#endif 
    
    }
    else
    {
        AVK_ASYN_DONE();
    }
}

AVK_CASE(AVK_MSG_UM_RELEASE_LIST,AVK_MSG_UM_CHECK_LIST)
{
    AVK_LOG_EX(SRV_UM_RESULT_OK == srv_um_release_list(g_p_msg_um_cntx->list_id,MMI_TRUE)); 
}


AVK_ASYN_CASE(AVK_MSG_UM_THREAD_GET_LIST,AVK_MSG_UM_BASE)
{             
#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    if (AVK_LOG_ASYN(srv_um_get_list(SRV_UM_LIST_TYPE_THREAD,g_p_msg_um_cntx->um_box,&g_p_msg_um_cntx->um_filter,avk_msg_um_get_list_cb,NULL)) < 0)    
    {
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();
    }
#endif    
}

AVK_CASE(AVK_MSG_UM_THREAD_CHECK_LIST,AVK_MSG_UM_THREAD_GET_LIST)
{
#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    g_p_msg_um_cntx->list_id = srv_um_check_list(SRV_UM_LIST_TYPE_THREAD,
                      g_p_msg_um_cntx->um_box,
                      &g_p_msg_um_cntx->um_filter,
                      avk_msg_um_list_notify_handler,
                      NULL,
                      &g_p_msg_um_cntx->um_ctx
                      );
    AVK_LOG_FUN(srv_um_check_list,g_p_msg_um_cntx->list_id > 0);   
#endif    
}

AVK_ASYN_CASE(AVK_MSG_UM_THREAD_GET_INFO,AVK_MSG_UM_THREAD_CHECK_LIST)
{    
#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    if (AVK_LOG_ASYN(srv_um_get_thread_info(g_p_msg_um_cntx->um_box,
                        (srv_um_thread_id_struct*)g_p_msg_um_cntx->um_ctx->list,1,avk_msg_um_get_thread_info_cb,NULL))<0)
    {
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();
    }
#else
    AVK_LOG_FUN_UNSUPPORTED(srv_um_get_thread_info);
#endif    
}

AVK_ASYN_CASE(AVK_MSG_UM_THREAD_GHECK_INFO,AVK_MSG_UM_THREAD_GET_INFO)
{
#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    srv_um_thread_info_struct  thread_info;
    srv_um_thread_info_struct* thread_info_p = &thread_info;
    srv_um_msg_info_struct  info_struct;
    srv_um_msg_info_struct* info_struct_p = &info_struct;
    srv_um_thread_id_struct thread_id;
    U32 mark_status[1] = {0x80000000};
    S32 res;
    

    res = srv_um_check_thread_info(g_p_msg_um_cntx->um_box,
                    (srv_um_thread_id_struct*)g_p_msg_um_cntx->um_ctx->list,g_p_msg_um_cntx->um_ctx->msg_number,0,1,&thread_info_p,&info_struct_p);
    AVK_LOG_FUN(srv_um_check_thread_info, SRV_UM_RESULT_OK == res);
    if (SRV_UM_RESULT_OK == res)
    {
        srv_um_tsfr_address_to_thread_id(info_struct_p->address_type,info_struct_p->address,SRV_UM_SIM_GSM_SIM1,&thread_id);

        if (thread_info_p->thread_id.type == thread_id.type
            && thread_info_p->thread_id.value == thread_id.value
        #ifdef  __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__
            && thread_info_p->thread_id.sim_id == thread_id.sim_id
        #endif
            )
        {
            AVK_LOG_FUN(srv_um_tsfr_address_to_thread_id, AVK_PASS);
        }
        else
        {
            AVK_LOG_FUN(srv_um_tsfr_address_to_thread_id, AVK_FAIL);
        }

        res = srv_um_tsfr_msg_id_to_thread_id(SRV_UM_MSG_SMS,0,&thread_id);
        if (SRV_UM_RESULT_OK == res)
        {
            AVK_LOG_FUN(srv_um_tsfr_msg_id_to_thread_id,AVK_PASS);
        }
        else if (SRV_UM_RESULT_NOT_SUPPORT == res)
        {
            AVK_LOG_FUN_UNSUPPORTED(srv_um_tsfr_msg_id_to_thread_id);
        }
        else
        {
            AVK_LOG_FUN(srv_um_tsfr_msg_id_to_thread_id,AVK_FAIL);
        }

        res = srv_um_update_thread_id(&thread_id);
        if (SRV_UM_RESULT_OK == res)
        {
            AVK_LOG_FUN(srv_um_update_thread_id,AVK_PASS);
        }
        else if (SRV_UM_RESULT_NOT_SUPPORT == res)
        {
            AVK_LOG_FUN_UNSUPPORTED(srv_um_update_thread_id);
        }
        else
        {
            AVK_LOG_FUN(srv_um_update_thread_id,AVK_FAIL);
        }
       
        res = srv_um_mark_several_thread_op(  g_p_msg_um_cntx->um_box,
                                        (srv_um_thread_id_struct*)g_p_msg_um_cntx->um_ctx->list,
                                        g_p_msg_um_cntx->um_ctx->msg_number,
                                        mark_status,
                                        SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_ARCHIVE,
                                        avk_msg_um_mark_several_thread_op_cb,
                                        NULL
                                     );
        if (SRV_UM_RESULT_NOT_SUPPORT == res)                                
        {
            AVK_LOG_FUN_UNSUPPORTED(srv_um_mark_several_thread_op);
        }
        else if (res < 0)
        {
            AVK_LOG_FUN(srv_um_mark_several_thread_op, AVK_FAIL);
        }
        else
        {
            AVK_LOG_FUN_ASYN(srv_um_mark_several_thread_op);
        }                                  
    }
#else
    AVK_LOG_FUN_UNSUPPORTED(srv_um_check_thread_info);
    AVK_LOG_FUN_UNSUPPORTED(srv_um_tsfr_address_to_thread_id);
    AVK_LOG_FUN_UNSUPPORTED(srv_um_tsfr_msg_id_to_thread_id);
    AVK_LOG_FUN_UNSUPPORTED(srv_um_update_thread_id);
    AVK_LOG_FUN_UNSUPPORTED(srv_um_mark_several_thread_op);
#endif
}

AVK_CASE(AVK_MSG_UM_THREAD_RELEASE_LIST,AVK_MSG_UM_THREAD_CHECK_LIST)
{
#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    AVK_LOG_EX(SRV_UM_RESULT_OK == srv_um_release_list(g_p_msg_um_cntx->list_id,MMI_TRUE)); 
#endif    
}

AVK_ASYN_CASE(AVK_MSG_UM_DELETE_FOLDER,AVK_MSG_UM_INIT)
{
    if (AVK_LOG_ASYN(srv_um_delete_folder(g_p_msg_um_cntx->um_box,avk_msg_um_delete_folder_cb,NULL))<0)
    {
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();
    }
}

AVK_CASE(AVK_MSG_UM_DEINIT,AVK_MSG_UM)
{
    AVK_FREE(g_p_msg_um_cntx);
	AVK_CASE_RESULT(AVK_PASS);
}


