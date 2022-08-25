extern "C"
{
 #include "ModeSwitchSrvGprot.h"
}

AVK_ADD_ITEM(AVK_SET_MODE_AUTO,L"Auto case",AVK_SET_MODE);

static mmi_ret vs_appser_setting_switchmode_progress_leave_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	AVK_ASYN_DONE();
	
    return MMI_TRUE;	
}

void vs_appser_setting_switchmode_cb(srv_mode_switch_type_enum sel_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

     switch (sel_mode)
     {
         case SRV_MODE_SWITCH_ALL_OFF:
             //mmi_popup_display_simple(L"All SIMs are turn off", MMI_EVENT_SUCCESS, GRP_ID_AVK, NULL);
             break;
         case SRV_MODE_SWITCH_SIM1:
             //mmi_popup_display_simple(L"SIM1 only or Single SIM", MMI_EVENT_SUCCESS, GRP_ID_AVK, NULL);
             break;
         case SRV_MODE_SWITCH_SIM2:
             //mmi_popup_display_simple(L"SIM2 only", MMI_EVENT_SUCCESS, GRP_ID_AVK, NULL);
             break;
         /*When single SIM SRV_MODE_SWITCH_SIM_ALL==SRV_MODE_SWITCH_SIM1, build error, so comment*/
         /*case SRV_MODE_SWITCH_SIM_ALL:*/
         /*    mmi_popup_display_simple(L"Dual SIM", MMI_EVENT_SUCCESS, GRP_ID_AVK, NULL);*/
         /*    break;*/
     }
 
     //mmi_frm_scrn_close(GRP_ID_AVK, SCR_ID_VS_APPSER_SETTING_SWITCHMOD);
     AVK_ASYN_DONE();
     
}


AVK_ASYN_CASE(AVK_SET_MODE_AUTO_RF,AVK_SET_MODE_AUTO)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	/*srv_mode_switch_switch_rf_mode*/
	//vs_appser_setting_switchmode_entry_progress();
	if (AVK_LOG_ASYN(srv_mode_switch_switch_rf_mode(SRV_MODE_SWITCH_SIM_ALL, (mmi_proc_func)vs_appser_setting_switchmode_cb, NULL)))
	{
	  AVK_CASE_RESULT(AVK_PASS);	
	}else{
	  AVK_CASE_RESULT(AVK_FAIL);
	  AVK_ASYN_DONE();	  	
	}
	  
}

void vs_appser_setting_switchmode_cbresult(U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == 0) // switch failed
    {       
       AVK_CASE_RESULT(AVK_FAIL);
    }else{
       AVK_CASE_RESULT(AVK_PASS);
    }
	AVK_ASYN_DONE();
}

AVK_ASYN_CASE(AVK_SET_MODE_AUTO_NWMODE,AVK_SET_MODE_AUTO)
{
	#if (MMI_MAX_SIM_NUM == 1)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL reval=MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!AVK_LOG_ASYN(srv_mode_switch_switch_network_mode(SRV_MODE_SWITCH_SIM_ALL, (mmi_proc_func)vs_appser_setting_switchmode_cbresult, NULL)))
    {
		AVK_CASE_RESULT(AVK_FAIL);
		AVK_ASYN_DONE();
	}

    #else
       AVK_LOG_FUN_UNSUPPORTED(srv_mode_switch_switch_network_mode);
	   AVK_ASYN_DONE();
    #endif
}


AVK_ASYN_CASE(AVK_SET_MODE_AUTO_NWMODEEXT,AVK_SET_MODE_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MMI_BOOL reval=MMI_FALSE;
	srv_mode_switch_req_struct switch_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&switch_info, 0x00, sizeof(srv_mode_switch_req_struct));
    switch_info.wlan=0xFF; //0xFF:Do not care
    switch_info.bt=0xFF;   //0xFF:Do not care
    switch_info.gsm=0x03;  //0x00: OFF, 0x03: ON
    reval = srv_mode_switch_switch_network_mode_ext(switch_info, (mmi_proc_func)vs_appser_setting_switchmode_cbresult, NULL);
	AVK_LOG_FUN(srv_mode_switch_switch_network_mode_ext,reval);
    
	if (!reval)
    {
		AVK_CASE_RESULT(AVK_FAIL);
		AVK_ASYN_DONE();
	}

}

AVK_CASE(AVK_SET_MODE_AUTO_OTHER,AVK_SET_MODE_AUTO)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     
	 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mode_switch_set_current_mode(SRV_MODE_SWITCH_SIM_ALL);
	AVK_LOG_FUN(srv_mode_switch_set_current_mode,(SRV_MODE_SWITCH_ON==srv_mode_switch_get_network_mode(MMI_SIM1)));
	AVK_LOG_FUN(srv_mode_switch_get_network_mode,(SRV_MODE_SWITCH_ON==srv_mode_switch_get_network_mode(MMI_SIM1)));

	AVK_LOG(SRV_MODE_SWITCH_SIM_ALL==srv_mode_switch_get_current_mode());

        
    #if (MMI_MAX_SIM_NUM >= 2)
	AVK_LOG(SRV_MODE_SWITCH_ON==srv_mode_switch_get_pre_network_mode(MMI_SIM1));//prefer mode before flight mode
    
    #else
      AVK_LOG_FUN_UNSUPPORTED(srv_mode_switch_get_pre_network_mode);
    #endif

	AVK_LOG(!srv_mode_switch_is_switching());
    AVK_LOG(MMI_TRUE==srv_mode_switch_is_network_service_available());

    

    srv_mode_switch_enable_query_mode(MMI_TRUE);//fight mode query
    AVK_LOG_FUN(srv_mode_switch_enable_query_mode,(MMI_TRUE==srv_mode_switch_is_query_mode_enabled()));
	AVK_LOG_FUN(srv_mode_switch_is_query_mode_enabled,(MMI_TRUE==srv_mode_switch_is_query_mode_enabled()));
    
}
