extern "C"
{
#include "ucmsrvgprot.h"
}

void avk_call_ucm_after_dail()
{
    U16 *number = (U16*)L"10086";
    srv_ucm_index_info_struct index_struct[SRV_UCM_MAX_CALL];
    S32 group_index[SRV_UCM_MAX_GROUP];
        
    AVK_LOG_EX(0 < srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, index_struct));
    if (AVK_FAIL == AVK_GET_CASE_RESULT())
    {
        goto case_fail;
    }
    else
    {
        srv_ucm_call_info_struct call_info_struct;
        srv_ucm_caller_res_struct caller_res;

        AVK_LOG_EX(srv_ucm_query_call_data(index_struct[0],&call_info_struct));
        if (AVK_PASS == AVK_GET_CASE_RESULT())
        {
            AVK_LOG_EX(srv_ucm_query_call_exist(&call_info_struct.uid_info,SRV_UCM_CALL_STATE_ALL));
            AVK_LOG(srv_ucm_get_caller_res_info(call_info_struct.uid_info, &caller_res));
            AVK_LOG_EX(srv_ucm_query_index_by_id(&call_info_struct.uid_info,index_struct));
            
            //kinds of permits
            AVK_LOG(srv_ucm_query_mute_permit(call_info_struct.uid_info));
            AVK_LOG(srv_ucm_query_loudspeaker_permit(call_info_struct.uid_info));
            AVK_LOG(srv_ucm_query_sndrec_permit(call_info_struct.uid_info));
            AVK_LOG(srv_ucm_query_bgs_in_call_permit(call_info_struct.uid_info));
            AVK_LOG(srv_ucm_query_bgs_incoming_call_permit(call_info_struct.uid_info));
            AVK_LOG(srv_ucm_query_bgs_outgoing_call_permit(SRV_UCM_CALL_TYPE_ALL));
            AVK_LOG(srv_ucm_query_switch_bt_audio_path_permit(call_info_struct.uid_info));
            AVK_LOG(srv_ucm_query_connect_last_bt_device_permit(call_info_struct.uid_info));
            AVK_LOG(srv_ucm_query_connect_ctm_permit(call_info_struct.uid_info));
        }
    }

    
    AVK_LOG_EX(0 < srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL,SRV_UCM_CALL_TYPE_ALL,MMI_FALSE,group_index));
    if (AVK_PASS == AVK_GET_CASE_RESULT())
    {
        
        srv_ucm_group_info_struct group_info_struct;
        AVK_LOG_EX(1 == srv_ucm_query_group_data(group_index[0],&group_info_struct));
        if (AVK_PASS == AVK_GET_CASE_RESULT())
        {
            AVK_LOG_EX(srv_ucm_query_group_exist(group_info_struct.group_id,SRV_UCM_CALL_TYPE_ALL,SRV_UCM_CALL_STATE_ALL));
            AVK_LOG_EX(srv_ucm_query_group_index_by_group_id(group_info_struct.group_id,SRV_UCM_VOICE_CALL_TYPE,group_index));
        }
        
#ifdef __MMI_BACKGROUND_CALL__            
        AVK_LOG(srv_ucm_query_app_exit());
        AVK_LOG(srv_ucm_is_background_call());
#else
        AVK_LOG_FUN_UNSUPPORTED(srv_ucm_query_app_exit);
        AVK_LOG_FUN_UNSUPPORTED(srv_ucm_is_background_call);
#endif            
        AVK_LOG(srv_ucm_query_disconnecting_call_count(SRV_UCM_CALL_STATE_ALL,SRV_UCM_VOICE_CALL_TYPE_ALL,NULL));
        AVK_LOG_EX(!srv_ucm_is_emergency_call());
        AVK_LOG(srv_ucm_is_incoming_call());
        AVK_LOG(srv_ucm_is_any_call());
        AVK_LOG(srv_ucm_is_pending_action());
        AVK_LOG(srv_ucm_is_emergency_number(SRV_UCM_VOICE_CALL_TYPE_ALL,(U8*)number));
        AVK_LOG(srv_ucm_is_valid_dtmf_digit(SRV_UCM_VOICE_CALL_TYPE_ALL,123));
        AVK_LOG(srv_ucm_query_error_message(SRV_UCM_RESULT_OK));
    }
    
    AVK_LOG_EX(srv_ucm_is_outgoing_call());
    if (AVK_PASS == AVK_GET_CASE_RESULT())
    {
        AVK_LOG(srv_ucm_intercept(SRV_UCM_VOICE_CALL_TYPE, number, SRV_UCM_MODULE_ORIGIN_COMMON));
    }
    
    AVK_MANU_SHOW_SCR(L"Call 10086 pass?",NULL,NULL);
    return;
case_fail:
    AVK_MANU_SHOW_SCR(L"fail!",NULL,NULL);
}

mmi_ret avk_call_ucm_dial_cb(mmi_event_struct *param)
{
    avk_call_ucm_after_dail();
    return MMI_TRUE;
}


AVK_MANUAL_CASE(AVK_CALL_UCM_MANU1,AVK_CALL_UCM)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *number = (U16*)L"10086";
    srv_ucm_dial_act_req_struct check_act_req;   

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AVK_LOG_EX(!srv_ucm_is_busy());
    AVK_LOG_EX(srv_ucm_is_call_srv_available(SRV_UCM_CALL_TYPE_ALL));
    AVK_LOG_EX(!srv_ucm_is_call_srv_tmp_unavailable(SRV_UCM_CALL_TYPE_ALL));
    if (AVK_FAIL == AVK_GET_CASE_RESULT())
    {
        goto case_fail;
    }

    AVK_LOG_EX(srv_ucm_is_valid_number(SRV_UCM_VOICE_CALL_TYPE_ALL,(U8*)number));
    if (AVK_FAIL == AVK_GET_CASE_RESULT())
    {
        goto case_fail;
    }
    
    mmi_ucs2cpy((CHAR*)check_act_req.num_uri, (CHAR*)number);
    check_act_req.is_ip_dial =MMI_FALSE;
    check_act_req.module_id = SRV_UCM_MODULE_ORIGIN_COMMON;
    check_act_req.phb_data = NULL;
    check_act_req.call_type = SRV_UCM_VOICE_CALL_TYPE;

    AVK_LOG_EX(srv_ucm_query_act_permit(SRV_UCM_DIAL_ACT, &check_act_req) == SRV_UCM_RESULT_OK);
    if (AVK_FAIL == AVK_GET_CASE_RESULT())
    {
        goto case_fail;
    }
    
    AVK_LOG_NORMAL(srv_ucm_act_request(SRV_UCM_DIAL_ACT, &check_act_req, NULL, avk_call_ucm_dial_cb));
    AVK_LOG_EX(SRV_UCM_DIAL_ACT == srv_ucm_query_curr_action());

    return;
case_fail:
    AVK_MANU_SHOW_SCR(L"fail!",NULL,NULL);
}

