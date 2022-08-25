extern "C"
{
#include "SSSrvGprot.h"
}

AVK_ADD_ITEM(AVK_CALL_SS_AUTO,L"Auto case",AVK_CALL_SS);
AVK_ADD_ITEM(AVK_CALL_SS_MANU,L"Manual case",AVK_CALL_SS);

mmi_ret avk_call_ss_act_cb(mmi_event_struct *param)
{
    AVK_MANU_SHOW_SCR(L"pass",NULL,NULL);

    return MMI_TRUE;
}

mmi_ret avk_call_ss_cb(mmi_event_struct *param)
{
    srv_ss_rsp_evt_struct* evt = (srv_ss_rsp_evt_struct*)param;
    AVK_CASE_RESULT(!evt->rsp.result);
    AVK_ASYN_DONE();
    return MMI_TRUE;
}

AVK_MANUAL_CASE(AVK_CALL_SS_MANU_CASE1,AVK_CALL_SS_MANU)
{
    srv_ss_operation_req_struct req;
    srv_ss_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = SRV_SS_RESULT_OK;       
    if (AVK_LOG(srv_ss_is_available(MMI_SIM1)))
    {
        memset(&req, 0, sizeof(srv_ss_operation_req_struct));

        req.sim = MMI_SIM1;
        mmi_wcscat((WCHAR*)req.string, (WCHAR*)L"#123#");
        AVK_LOG_EX(srv_ss_is_valid_ss_string(MMI_SIM1,mmi_ucs2strlen((CHAR*)req.string),req.string));
        
        AVK_LOG_MANUAL(result = srv_ss_act_req(SRV_SS_ACT_SS_OPERATION, &req, avk_call_ss_act_cb, NULL));
        AVK_LOG(srv_ss_get_result_string(result));
        if (result != SRV_SS_RESULT_OK && result != SRV_SS_RESULT_BUSY)
        {
            AVK_MANU_SHOW_SCR(L"fail",NULL,NULL);    
        }
    }
    else
    {
        AVK_MANU_SHOW_SCR(L"srv unavailable",NULL,NULL);
    }
}


AVK_CASE(AVK_CALL_SS_AUTO_CASE1,AVK_CALL_SS_AUTO)
{
#ifdef __MMI_SS_SHOW_CAUSE__
    srv_ss_cause_str_struct str;
#endif
    //just invoke, nothing need to test
    AVK_LOG(srv_ss_get_status_string(SRV_SS_STATUS_ACTIVATED));
    AVK_LOG(srv_ss_get_bs_string(SRV_SS_BS_CODE_ALL_TELESERVICES));
    AVK_LOG(srv_ss_get_call_forward_type_string(SRV_SS_CALL_FORWARD_CFU));
    AVK_LOG(srv_ss_get_call_bar_type_string(SRV_SS_CALL_BAR_BAOC));
    AVK_LOG(srv_ss_get_call_wait_string());
    AVK_LOG(srv_ss_get_call_id_type_string(SRV_SS_CALL_ID_CLIP));
    AVK_LOG(srv_ss_get_cnap_string());
    AVK_LOG(srv_ss_get_ccbs_string());
    AVK_LOG(srv_ss_get_emlpp_string());
    
#ifdef __MMI_SS_SHOW_CAUSE__
    AVK_LOG_NORMAL(srv_ss_get_cause_string(CM_RADIO_LINK_FAIL, &str));
#else
    AVK_LOG_FUN_UNSUPPORTED(srv_ss_get_cause_string);
#endif    
    //
    AVK_LOG_EX(srv_ss_is_valid_call_forward_number(MMI_SIM1,5,(WCHAR*)L"10086"));

    AVK_LOG_EX(srv_ss_check_capability(MMI_SIM1, SRV_SS_ACT_CALL_FORWARD, SRV_SS_CALL_FORWARD_CFALL, SRV_SS_ALL_CALL));
}

