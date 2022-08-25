extern "C"
{
  #include "CallSetSrvGprot.h"
}

AVK_ADD_ITEM(AVK_CALL_SET_AUTO,L"Auto case",AVK_CALL_SET);

mmi_ret tst_callset_caller_id_set_get_mode_cb(mmi_event_struct *info)
{
    #ifdef __MMI_CALLSET_CALLER_ID__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_result_struct *data = (srv_callset_result_struct*)(((srv_callset_rsp_evt_struct*)info)->data);
    //MMI_ID *menu_gid_p = (MMI_ID*)(info->user_data);
    mmi_sim_enum vsim = MMI_SIM1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (data->result == SRV_CALLSET_RESULT_OK)
    {
        //mmi_popup_display_simple(get_string(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
    }
    else /* fail */
    {
        //mmi_popup_display_simple(
        //    get_string(srv_callset_get_result_string_id(data->result)),
        //    MMI_EVENT_FAILURE,
        //    GRP_ID_ROOT,
        //    NULL);
    }

	AVK_LOG_FUN(srv_callset_caller_id_get_mode,(SRV_CALLSET_CALLER_ID_SHOW == srv_callset_caller_id_get_mode(vsim)));
    AVK_ASYN_DONE();
    
    #endif /*__MMI_CALLSET_CALLER_ID__*/
    return MMI_RET_OK;
}
AVK_ASYN_CASE(AVK_CALL_SET_CALLERID_SETGET,AVK_CALL_SET_AUTO) 
{
	#ifdef __MMI_CALLSET_CALLER_ID__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_cid_set_mode_struct info;
    srv_callset_result_enum reval;
    mmi_sim_enum vsim = MMI_SIM1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    info.mode = SRV_CALLSET_CALLER_ID_SHOW;
    info.sim = vsim;

    reval = srv_callset_caller_id_set_mode(&info, tst_callset_caller_id_set_get_mode_cb, &vsim);
	AVK_LOG_FUN(srv_callset_caller_id_set_mode,(SRV_CALLSET_RESULT_OK == reval));
    #else
       AVK_LOG_FUN_UNSUPPORTED(srv_callset_caller_id_set_mode);
	   AVK_LOG_FUN_UNSUPPORTED(srv_callset_caller_id_get_mode);
	   AVK_ASYN_DONE();
    #endif /*__MMI_CALLSET_CALLER_ID__*/

}

mmi_ret tst_callset_line_switch_set_get_mode_cb(mmi_event_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_result_struct *data = (srv_callset_result_struct*)(((srv_callset_rsp_evt_struct*)info)->data);
    //MMI_ID *menu_gid_p = (MMI_ID*)(info->user_data);
    mmi_sim_enum vsim = MMI_SIM1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (data->result == SRV_CALLSET_RESULT_OK)
    {
        //mmi_popup_display_simple(
        //    get_string(STR_GLOBAL_DONE), 
        //    MMI_EVENT_SUCCESS,
        //    GRP_ID_ROOT,
        //    NULL);
    }
    else
    {
        //mmi_popup_display_simple(
        //    get_string(srv_callset_get_result_string_id(data->result)), 
        //    MMI_EVENT_FAILURE,
        //    GRP_ID_ROOT,
        //    NULL);
    }

	AVK_LOG_FUN(srv_callset_line_switch_get_id,(SRV_CALLSET_LINE1 == srv_callset_line_switch_get_id(vsim)));
    AVK_ASYN_DONE();
    return MMI_RET_OK;
} 
AVK_ASYN_CASE(AVK_CALL_SET_LINESWITCH_SETGET,AVK_CALL_SET_AUTO) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_line_switch_struct info;
    srv_callset_result_enum reval;
    mmi_sim_enum vsim = MMI_SIM1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    info.line_id = SRV_CALLSET_LINE1;
    info.sim = vsim;
    
    reval = srv_callset_line_switch_set_id(&info, tst_callset_line_switch_set_get_mode_cb, &vsim);
	AVK_LOG_FUN(srv_callset_line_switch_set_id,(SRV_CALLSET_RESULT_OK == reval));
   
}

AVK_CASE(AVK_CALL_SET_CUG,AVK_CALL_SET_AUTO) 
{
    #ifdef __MMI_CALLSET_CUG__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_result_enum reval;
    mmi_sim_enum select_sim = MMI_SIM1;
    srv_callset_cug_set_item_struct cug_setitem;
    srv_callset_cug_get_item_struct cug_getitem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cug_setitem.cug_id = 0;
    mmi_wcscpy((WCHAR *)cug_setitem.name, (const WCHAR *)L"MTK Group");
    
    /*srv_callset_cug_set_item*/
    reval = srv_callset_cug_set_item(select_sim, &cug_setitem);
	AVK_LOG_FUN(srv_callset_cug_set_item,(SRV_CALLSET_RESULT_OK == reval));
   
    /*srv_callset_cug_get_item*/
    memset(&cug_getitem, 0, sizeof(srv_callset_cug_set_item_struct));
    reval = srv_callset_cug_get_item(select_sim, cug_setitem.cug_id, &cug_getitem);
	AVK_LOG_FUN(srv_callset_cug_get_item,((SRV_CALLSET_RESULT_OK == reval)&&(0 == mmi_wcscmp(cug_getitem.name, cug_setitem.name))));

    
    /*srv_callset_cug_get_actviated_id*/
    /*srv_callset_cug_activate*/
    /*srv_callset_cug_deactivate*/
    
    #else
      AVK_LOG_FUN_UNSUPPORTED(srv_callset_cug_set_item);
	  AVK_LOG_FUN_UNSUPPORTED(srv_callset_cug_get_item);
    #endif /*__MMI_CALLSET_CUG__*/
}

AVK_CASE(AVK_CALL_SET_BLACKLIST,AVK_CALL_SET_AUTO) 
{
    #ifdef __MMI_CM_BLACK_LIST__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_blacklist_mode_enum vblacklist_mode = SRV_CALLSET_BLACKLIST_OFF;
    kal_wchar * blacklist_num = (WCHAR *)L"13501148834";
    U8 blacklist_numlen = 0;
    U8 blacklist_index = 0;
    srv_callset_result_enum reval;
    srv_callset_bl_item_struct vblacklist_setitem;
    srv_callset_bl_item_struct vblacklist_getitem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /*srv_callset_blacklist_set_mode*/
	AVK_LOG_FUN(srv_callset_blacklist_set_mode,(SRV_CALLSET_RESULT_OK==srv_callset_blacklist_set_mode(vblacklist_mode, NULL)));
    
    /*srv_callset_blacklist_get_mode*/
	AVK_LOG_FUN(srv_callset_blacklist_get_mode,((srv_callset_blacklist_get_mode(NULL))== vblacklist_mode));
    
    /*srv_callset_blacklist_switch_mode*/
    vblacklist_mode = SRV_CALLSET_BLACKLIST_FROM_LIST;
    reval = srv_callset_blacklist_switch_mode(vblacklist_mode, MMI_TRUE, NULL);
	AVK_LOG_FUN(srv_callset_blacklist_switch_mode,(SRV_CALLSET_RESULT_OK == reval));
    
    /*srv_callset_blacklist_set_number*/
    vblacklist_setitem.index = 0;
    mmi_wcscpy((WCHAR *)vblacklist_setitem.number, (const WCHAR *)L"13501148834");
    vblacklist_setitem.adv_param = NULL;
    reval = srv_callset_blacklist_set_number(&vblacklist_setitem);
	AVK_LOG_FUN(srv_callset_blacklist_set_number,((SRV_CALLSET_RESULT_OK == reval)||(SRV_CALLSET_RESULT_DUPLICATE== reval)));
    
    /*srv_callset_blacklist_get_item*/
    memset(&vblacklist_getitem, 0 , sizeof(vblacklist_getitem));
    reval = srv_callset_blacklist_get_item(&vblacklist_getitem);
	AVK_LOG_FUN(srv_callset_blacklist_get_item,((SRV_CALLSET_RESULT_OK == reval)&&(0 == mmi_wcscmp(vblacklist_getitem.number, vblacklist_setitem.number))));
 
    /*srv_callset_blacklist_add_number*/
    blacklist_numlen = mmi_wcslen(blacklist_num);
    reval = srv_callset_blacklist_add_number(blacklist_numlen, blacklist_num, NULL, &blacklist_index);
	AVK_LOG_FUN(srv_callset_blacklist_add_number,(SRV_CALLSET_RESULT_DUPLICATE == reval));
	
    /*srv_callset_blacklist_delete_number*/

    /*srv_callset_blacklist_is_blocked_number*/
	AVK_LOG_FUN(srv_callset_blacklist_is_blocked_number,(MMI_TRUE== srv_callset_blacklist_is_blocked_number(blacklist_numlen, blacklist_num, NULL)));
    
    #else
       AVK_LOG_FUN_UNSUPPORTED(srv_callset_blacklist_set_mode);
	   AVK_LOG_FUN_UNSUPPORTED(srv_callset_blacklist_get_mode);
	   AVK_LOG_FUN_UNSUPPORTED(srv_callset_blacklist_switch_mode);
	   AVK_LOG_FUN_UNSUPPORTED(srv_callset_blacklist_set_number);
	   AVK_LOG_FUN_UNSUPPORTED(srv_callset_blacklist_get_item);
	   AVK_LOG_FUN_UNSUPPORTED(srv_callset_blacklist_add_number);
	   AVK_LOG_FUN_UNSUPPORTED(srv_callset_blacklist_is_blocked_number);
    #endif /*__MMI_CM_BLACK_LIST__*/
}

AVK_CASE(AVK_CALL_SET_BLACKLIST_NEW,AVK_CALL_SET_AUTO) 
{
	#ifdef __MMI_CM_BLACK_LIST__
       srv_callset_blacklist_adv_param_struct adv_param;
	   AVK_LOG(!srv_callset_blacklist_init_advanced_param(&adv_param));
       AVK_LOG(SRV_CALLSET_RESULT_NOT_FOUND == srv_callset_blacklist_delete_number(4,(WCHAR *)L"1111",NULL,NULL));
	#else
	   AVK_LOG_FUN_UNSUPPORTED(srv_callset_blacklist_init_advanced_param);
	   AVK_LOG_FUN_UNSUPPORTED(srv_callset_blacklist_delete_number);
	#endif
}
AVK_CASE(AVK_CALL_SET_WHITELIST,AVK_CALL_SET_AUTO) 
{
    #ifdef __MMI_CM_WHITE_LIST__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_whitelist_mode_enum vwhitelist_mode = SRV_CALLSET_WHITELIST_OFF;
    kal_wchar * whitelist_num = (WCHAR *)L"13501148834";
    U8 whitelist_numlen = 0;
    srv_callset_result_enum reval;
    srv_callset_wl_item_struct vwhitelist_setitem;
    srv_callset_wl_item_struct vwhitelist_getitem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*srv_callset_whitelist_set_mode*/
	AVK_LOG(SRV_CALLSET_RESULT_OK==srv_callset_whitelist_set_mode(vwhitelist_mode, NULL));
     
    /*srv_callset_whitelist_get_mode*/
	AVK_LOG((srv_callset_whitelist_get_mode(NULL))== vwhitelist_mode);
    
    /*srv_callset_whitelist_switch_mode*/
    vwhitelist_mode = SRV_CALLSET_WHITELIST_FROM_LIST;
    reval = srv_callset_whitelist_switch_mode(vwhitelist_mode, MMI_TRUE, NULL);
	AVK_LOG_FUN(srv_callset_whitelist_switch_mode,(SRV_CALLSET_RESULT_OK == reval));
   
    /*srv_callset_whitelist_set_number*/
    vwhitelist_setitem.index = 0;
    mmi_wcscpy(vwhitelist_setitem.number, (const WCHAR *)L"13501148834");
    vwhitelist_setitem.adv_param = NULL;
    reval = srv_callset_whitelist_set_number(&vwhitelist_setitem);
	AVK_LOG_FUN(srv_callset_whitelist_set_number,(SRV_CALLSET_RESULT_OK == reval)||(SRV_CALLSET_RESULT_DUPLICATE == reval));

    /*srv_callset_whitelist_get_item*/
    memset(&vwhitelist_getitem, 0 , sizeof(vwhitelist_getitem));
    reval = srv_callset_whitelist_get_item(&vwhitelist_getitem);
	AVK_LOG_FUN(srv_callset_whitelist_get_item,((SRV_CALLSET_RESULT_OK == reval)&&(0 == mmi_wcscmp(vwhitelist_getitem.number, vwhitelist_setitem.number))));
   
    
    /*srv_callset_whitelist_add_number*/
    /*srv_callset_whitelist_delete_number*/
    /*srv_callset_whitelist_is_auto_answer_number*/
    whitelist_numlen = mmi_wcslen(whitelist_num);
	AVK_LOG(MMI_TRUE== srv_callset_whitelist_is_auto_answer_number(whitelist_numlen, whitelist_num, NULL));
    
    #else
      AVK_LOG_FUN_UNSUPPORTED(srv_callset_whitelist_set_mode);
	  AVK_LOG_FUN_UNSUPPORTED(srv_callset_whitelist_get_mode);
	  AVK_LOG_FUN_UNSUPPORTED(srv_callset_whitelist_switch_mode);
	  AVK_LOG_FUN_UNSUPPORTED(srv_callset_whitelist_set_number);
	  AVK_LOG_FUN_UNSUPPORTED(srv_callset_whitelist_get_item);
	  AVK_LOG_FUN_UNSUPPORTED(srv_callset_whitelist_is_auto_answer_number);
    #endif /*__MMI_CM_WHITE_LIST__*/
}

AVK_CASE(AVK_CALL_SET_REDIAL,AVK_CALL_SET_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    /*srv_callset_redial_set_mode*/
    /*srv_callset_redial_get_mode*/
    srv_callset_redial_set_mode(SRV_CALLSET_REDIAL_AUTO);
    AVK_LOG_FUN(srv_callset_redial_set_mode,(SRV_CALLSET_REDIAL_AUTO == srv_callset_redial_get_mode()));
	AVK_LOG_FUN(srv_callset_redial_get_mode,(SRV_CALLSET_REDIAL_AUTO == srv_callset_redial_get_mode()));
	
    /*srv_callset_auto_redial_set_mode, srv_callset_auto_redial_get_mode*/
    srv_callset_auto_redial_set_mode(MMI_TRUE);
	AVK_LOG_FUN(srv_callset_auto_redial_set_mode,(MMI_TRUE == srv_callset_auto_redial_get_mode()));
	AVK_LOG_FUN(srv_callset_auto_redial_get_mode,(MMI_TRUE == srv_callset_auto_redial_get_mode()));

}

AVK_CASE(AVK_CALL_SET_IPNUMBER,AVK_CALL_SET_AUTO)
{
    #ifdef __IP_NUMBER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ip_index = 0;
    U8 ipnum_len = 0;
    WCHAR * ipnum = (WCHAR *)L"17951";
    srv_callset_result_enum reval;
    srv_callset_ip_number_item_struct ipnum_get;
    srv_callset_ip_number_struct ipnum_get2;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    /*srv_callset_ip_number_set_number*/
    ipnum_len = mmi_wcslen(ipnum);
    reval = srv_callset_ip_number_set_number(ip_index, ipnum_len, ipnum);
	AVK_LOG_FUN(srv_callset_ip_number_set_number,(SRV_CALLSET_RESULT_OK == reval));

    /*srv_callset_ip_number_get_item*/
    memset(&ipnum_get, 0, sizeof(srv_callset_ip_number_item_struct));
    reval = srv_callset_ip_number_get_item(ip_index, &ipnum_get);
	AVK_LOG_FUN(srv_callset_ip_number_get_item,((SRV_CALLSET_RESULT_OK == reval) && (0 == mmi_wcscmp(ipnum_get.number,ipnum))));
    
    /*srv_callset_ip_number_activate*/
    reval = srv_callset_ip_number_activate(MMI_SIM1, ip_index);
	AVK_LOG_FUN(srv_callset_ip_number_activate,(SRV_CALLSET_RESULT_OK == reval));
    
    /*srv_callset_ip_number_get_activated_number*/
    memset(&ipnum_get2, 0, sizeof(srv_callset_ip_number_struct));
    reval = srv_callset_ip_number_get_activated_number(MMI_SIM1, &ipnum_get2);
	AVK_LOG_FUN(srv_callset_ip_number_get_activated_number,((SRV_CALLSET_RESULT_OK == reval) && (0 == mmi_wcscmp(ipnum_get2.number,ipnum))));
    
    /*srv_callset_ip_number_deactivate*/
    reval = srv_callset_ip_number_deactivate(MMI_SIM1, ip_index);
	AVK_LOG_FUN(srv_callset_ip_number_deactivate,(SRV_CALLSET_RESULT_OK == reval));
	
    #else
      AVK_LOG_FUN_UNSUPPORTED(srv_callset_ip_number_set_number);
	  AVK_LOG_FUN_UNSUPPORTED(srv_callset_ip_number_get_item);
	  AVK_LOG_FUN_UNSUPPORTED(srv_callset_ip_number_activate);
	  AVK_LOG_FUN_UNSUPPORTED(srv_callset_ip_number_get_activated_number);
	  AVK_LOG_FUN_UNSUPPORTED(srv_callset_ip_number_deactivate);
    #endif /*__IP_NUMBER__*/
    
}

AVK_CASE(AVK_CALL_SET_TIME_DISPLAY,AVK_CALL_SET_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

   /*srv_callset_call_time_display_set_mode*/
   /*srv_callset_call_time_display_get_mode*/
   srv_callset_call_time_display_set_mode(MMI_TRUE);
   AVK_LOG_FUN(srv_callset_call_time_display_set_mode,(MMI_TRUE == srv_callset_call_time_display_get_mode()));
   AVK_LOG_FUN(srv_callset_call_time_display_get_mode,(MMI_TRUE == srv_callset_call_time_display_get_mode()));
   
}

AVK_CASE(AVK_CALL_SET_CTR,AVK_CALL_SET_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_ctr_struct ctr_infoset;
    srv_callset_ctr_struct ctr_infoget;
    srv_callset_result_enum reval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    ctr_infoset.mode = SRV_CALLSET_CTR_MODE_SINGLE;
    ctr_infoset.time =SRV_CALLSET_CTR_MIN_SINGLE_TIME;
 
    /*srv_callset_ctr_set_mode*/
    reval = srv_callset_ctr_set_mode(&ctr_infoset);
	AVK_LOG_FUN(srv_callset_ctr_set_mode,(SRV_CALLSET_RESULT_OK == reval));
 
    /*srv_callset_ctr_get_mode*/
    memset(&ctr_infoget, 0, sizeof(srv_callset_ctr_struct));
    reval = srv_callset_ctr_get_mode(&ctr_infoget);
	AVK_LOG_FUN(srv_callset_ctr_get_mode,((SRV_CALLSET_RESULT_OK == reval) && (ctr_infoget.time == ctr_infoset.time)));
    
}

AVK_CASE(AVK_CALL_SET_ANSWER_MODE,AVK_CALL_SET_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_answer_mode_enum vanswer_set = SRV_CALLSET_ANSWER_MODE_ANYKEY;
    srv_callset_answer_mode_enum vanswer_get = SRV_CALLSET_ANSWER_MODE_OFF;
    srv_callset_result_enum reval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    
    /*srv_callset_answer_mode_set_mode*//*srv_callset_answer_mode_get_mode*/   
    reval = srv_callset_answer_mode_set_mode(vanswer_set);
    vanswer_get = srv_callset_answer_mode_get_mode();
	AVK_LOG_FUN(srv_callset_answer_mode_set_mode,((SRV_CALLSET_RESULT_OK == reval) && (vanswer_set == vanswer_get)));
	AVK_LOG_FUN(srv_callset_answer_mode_get_mode,((SRV_CALLSET_RESULT_OK == reval) && (vanswer_set == vanswer_get)));
     
    /*srv_callset_answer_mode_get_status*/
    vanswer_get = srv_callset_answer_mode_get_status();
	AVK_LOG_FUN(srv_callset_answer_mode_get_status,(vanswer_set == vanswer_get));
    
    /*srv_callset_answer_mode_switch_mode*/
    reval = srv_callset_answer_mode_switch_mode(vanswer_set, MMI_TRUE);
	AVK_LOG_FUN(srv_callset_answer_mode_switch_mode,(SRV_CALLSET_RESULT_OK == reval));
    
}

AVK_CASE(AVK_CALL_SET_QUICKEND,AVK_CALL_SET_AUTO)
{
    #ifdef __MMI_CH_QUICK_END__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL get_mode = MMI_FALSE;
    U16 get_time = 0, set_time = SRV_CALLSET_AUTO_QUICK_END_MIN + 8;
    srv_callset_result_enum reval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    
    /*srv_callset_auto_quick_end_set_mode*/
    reval = srv_callset_auto_quick_end_set_mode(MMI_TRUE, set_time);
	AVK_LOG_FUN(srv_callset_auto_quick_end_set_mode,(SRV_CALLSET_RESULT_OK == reval));
    
    /*srv_callset_auto_quick_end_get_mode*/
    reval = srv_callset_auto_quick_end_get_mode(&get_mode, &get_time);
	AVK_LOG_FUN(srv_callset_auto_quick_end_get_mode,((SRV_CALLSET_RESULT_OK == reval) && (MMI_TRUE == get_mode) && (set_time == get_time)));
    
    /*srv_callset_auto_quick_end_get_time*/
	AVK_LOG_FUN(srv_callset_auto_quick_end_get_time,(set_time == (U16)srv_callset_auto_quick_end_get_time()));
   
    #else
      AVK_LOG_FUN_UNSUPPORTED(srv_callset_auto_quick_end_set_mode); 
	  AVK_LOG_FUN_UNSUPPORTED(srv_callset_auto_quick_end_get_mode);
	  AVK_LOG_FUN_UNSUPPORTED(srv_callset_auto_quick_end_get_time);
    #endif /*__MMI_CH_QUICK_END__*/
    
}

AVK_CASE(AVK_CALL_SET_REJECTBYSMS,AVK_CALL_SET_AUTO)
{
    #ifdef __MMI_UCM_REJECT_BY_SMS__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL mode = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    
    /*srv_callset_reject_by_sms_set_mode*//*srv_callset_reject_by_sms_get_mode*/
    srv_callset_reject_by_sms_set_mode(mode);
	AVK_LOG_FUN(srv_callset_reject_by_sms_set_mode,(mode == srv_callset_reject_by_sms_get_mode()));
	AVK_LOG_FUN(srv_callset_reject_by_sms_get_mode,(mode == srv_callset_reject_by_sms_get_mode()));
	
    /*srv_callset_reject_by_sms_get_setting*/
    /*srv_callset_reject_by_sms_set_setting*/
	srv_callset_reject_by_sms_set_setting(SRV_CALLSET_REJ_BY_SMS_END_CALL_AFTER_SEND);
	AVK_LOG_FUN(srv_callset_reject_by_sms_set_setting,(SRV_CALLSET_REJ_BY_SMS_END_CALL_AFTER_SEND == srv_callset_reject_by_sms_get_setting()));
	AVK_LOG_FUN(srv_callset_reject_by_sms_get_setting,(SRV_CALLSET_REJ_BY_SMS_END_CALL_AFTER_SEND == srv_callset_reject_by_sms_get_setting()));
    
    #else
      AVK_LOG_FUN_UNSUPPORTED(srv_callset_reject_by_sms_set_mode);
	  AVK_LOG_FUN_UNSUPPORTED(srv_callset_reject_by_sms_get_mode);
    #endif /*__MMI_UCM_REJECT_BY_SMS__*/
    
}


AVK_CASE(AVK_CALL_SET_CONNECT_NOTICE,AVK_CALL_SET_AUTO)
{ 
    #ifdef __MMI_CONNECT_NOTICE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL mode = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    /*srv_callset_connect_notice_set_mode*//*srv_callset_connect_notice_get_mode*/
    srv_callset_connect_notice_set_mode(mode);
	AVK_LOG_FUN(srv_callset_connect_notice_set_mode,(mode == srv_callset_connect_notice_get_mode()));
	AVK_LOG_FUN(srv_callset_connect_notice_get_mode,(mode == srv_callset_connect_notice_get_mode()));

    #else
      AVK_LOG_FUN_UNSUPPORTED(srv_callset_connect_notice_set_mode);
	  AVK_LOG_FUN_UNSUPPORTED(srv_callset_connect_notice_get_mode);
    #endif /*__MMI_CONNECT_NOTICE__*/
    
}


AVK_CASE(AVK_CALL_SET_CTM,AVK_CALL_SET_AUTO) 
{
    #if defined (__MMI_CM_WHITE_LIST__) && defined (__CTM_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_ctm_setting_struct ctm_setinfo;
    srv_callset_ctm_setting_struct ctm_getinfo;
    srv_callset_result_enum reval;
	srv_callset_whitelist_adv_param_struct w_adv_param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    ctm_setinfo.mode = MMI_TRUE;
    ctm_setinfo.setting = SRV_CALLSET_CTM_SETTING_HCO;

    /*srv_callset_ctm_set_mode*/
    reval = srv_callset_ctm_set_mode(&ctm_setinfo);
	AVK_LOG_FUN(srv_callset_ctm_set_mode,(SRV_CALLSET_RESULT_OK == reval));
    
    /*srv_callset_ctm_get_mode*/
    memset(&ctm_getinfo, 0, sizeof(srv_callset_ctm_setting_struct));
    ctm_getinfo.mode = srv_callset_ctm_get_mode();
	AVK_LOG_FUN(srv_callset_ctm_get_mode,(ctm_setinfo.mode == ctm_getinfo.mode));

    /*srv_callset_ctm_get_setting*/    
    ctm_getinfo.setting = srv_callset_ctm_get_setting();
	AVK_LOG_FUN(srv_callset_ctm_get_setting,(ctm_setinfo.setting== ctm_getinfo.setting));
    
    /*srv_callset_ctm_permit_switch_setting*/
    reval = srv_callset_ctm_permit_switch_setting();
	AVK_LOG_FUN(srv_callset_ctm_permit_switch_setting,(SRV_CALLSET_RESULT_OK == reval)); 
    
    /*srv_callset_ctm_permit_set_mode*/
    reval = srv_callset_ctm_permit_set_mode(&ctm_setinfo);
	AVK_LOG_FUN(srv_callset_ctm_permit_set_mode,(SRV_CALLSET_RESULT_OK == reval));
    
    /*srv_callset_ctm_is_tty_on*/
	AVK_LOG_FUN(srv_callset_ctm_is_tty_on,(srv_callset_ctm_is_tty_on()));

	/*srv_callset_whitelist_init_advanced_param*/
    AVK_LOG(!srv_callset_whitelist_init_advanced_param(&w_adv_param));

	/*srv_callset_whitelist_add_number*/
    AVK_LOG(!srv_callset_whitelist_add_number(10,(WCHAR *)L"1234",NULL,NULL));

	/*srv_callset_whitelist_delete_number*/
    AVK_LOG(!srv_callset_whitelist_delete_number(10,(WCHAR *)L"1234",NULL,NULL)); 
    
    #else
       AVK_LOG_FUN_UNSUPPORTED(srv_callset_ctm_set_mode);
       AVK_LOG_FUN_UNSUPPORTED(srv_callset_ctm_get_mode);
       AVK_LOG_FUN_UNSUPPORTED(srv_callset_ctm_get_setting);
       AVK_LOG_FUN_UNSUPPORTED(srv_callset_ctm_permit_switch_setting);
       AVK_LOG_FUN_UNSUPPORTED(srv_callset_ctm_permit_set_mode);
       AVK_LOG_FUN_UNSUPPORTED(srv_callset_ctm_is_tty_on);
	   AVK_LOG_FUN_UNSUPPORTED(srv_callset_whitelist_init_advanced_param);
	   AVK_LOG_FUN_UNSUPPORTED(srv_callset_whitelist_add_number);
	   AVK_LOG_FUN_UNSUPPORTED(srv_callset_whitelist_delete_number);
    #endif /*__CTM_SUPPORT__*/
}


AVK_CASE(AVK_CALL_SET_OTHER,AVK_CALL_SET_AUTO) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    srv_callset_result_enum reval = SRV_CALLSET_RESULT_NOT_AVAILABLE;
    srv_callset_cfu_status_enum reval_cfu;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*srv_callset_get_result_string_id*/
	AVK_LOG_FUN(srv_callset_get_result_string_id,(STR_GLOBAL_NOT_AVAILABLE==srv_callset_get_result_string_id(reval)));
     
	/*srv_callset_cfu_get_status*/
	reval_cfu = srv_callset_cfu_get_status(MMI_SIM1);
	AVK_LOG_FUN(srv_callset_cfu_get_status,(reval_cfu >= SRV_CALLSET_CFU_NOT_SUPPORT));
    
}
