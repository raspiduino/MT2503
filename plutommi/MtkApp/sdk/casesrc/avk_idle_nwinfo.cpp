extern "C"
{
  #include "NwInfoSrvGprot.h"
}

AVK_ADD_ITEM(AVK_IDLE_INFO_AUTO,L"Auto case",AVK_IDLE_INFO);
AVK_ADD_ITEM(AVK_IDLE_INFO_MANU,L"Manual case",AVK_IDLE_INFO);


AVK_CASE(AVK_IDLE_INFO_CASE_AUTO,AVK_IDLE_INFO_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum v_sim;
    U8 signal_level;
    MMI_BOOL bool_reval;
    mmi_network_enum nw_enum;
    srv_nw_info_service_availability_enum nw_info_reval;
    srv_nw_band_enum nw_band_reval;    
    srv_nw_info_location_info_struct locate_info;    
    kal_char char_plmn[SRV_MAX_PLMN_LEN+1];

    #ifdef __SRV_NW_INFO_CIPHER_SUPPORT__
      srv_nw_info_cipher_info_struct cipher_info;
    #endif
    
    #ifdef __HOMEZONE_SUPPORT__
        srv_nw_info_homezone_info_struct homezone_info;
    #endif
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v_sim = MMI_SIM1;

    /*srv_nw_info_get_service_availability*/
    nw_info_reval = srv_nw_info_get_service_availability(v_sim);
	AVK_LOG_FUN(srv_nw_info_get_service_availability,((nw_info_reval >= SRV_NW_INFO_SA_FULL_SERVICE ) && (nw_info_reval < SRV_NW_INFO_SA_END_OF_ENUM)));

    //SRV_NW_BAND_GSM900      = 0x02,     /* GSM900 */
    //SRV_NW_BAND_DCS1800     = 0x08,     /* DCS1800 */
    //SRV_NW_BAND_PCS1900     = 0x10,     /* PCS1900 */
    //SRV_NW_BAND_GSM450      = 0x20,     /* GSM450 */
    //SRV_NW_BAND_GSM480      = 0x40,     /* GSM480 */
    //SRV_NW_BAND_GSM850      = 0x80,     /* GSM850 */
    //SRV_NW_BAND_OTHERS      = 0xf0,     /* Other band not defined above. */   
    
    /*srv_nw_info_get_camp_on_band*/
    nw_band_reval = srv_nw_info_get_camp_on_band(v_sim);
	AVK_LOG_FUN(srv_nw_info_get_camp_on_band,((SRV_NW_BAND_GSM900 == nw_band_reval) || (SRV_NW_BAND_DCS1800 == nw_band_reval)||
        (SRV_NW_BAND_PCS1900 == nw_band_reval) || (SRV_NW_BAND_GSM450 == nw_band_reval)||
        (SRV_NW_BAND_GSM480 == nw_band_reval) || (SRV_NW_BAND_GSM850 == nw_band_reval)||(SRV_NW_BAND_OTHERS == nw_band_reval)));
        
    /*srv_nw_info_sim_is_rejected*/
    /*need valid sim*/
	AVK_LOG(MMI_FALSE == srv_nw_info_sim_is_rejected(v_sim));
    
    /*srv_nw_info_is_roaming*/
	AVK_LOG(MMI_FALSE == srv_nw_info_is_roaming(v_sim));
        
    /*srv_nw_info_get_signal_strength_in_percentage*/
    signal_level = srv_nw_info_get_signal_strength_in_percentage(v_sim);
	AVK_LOG_FUN(srv_nw_info_get_signal_strength_in_percentage,((signal_level >= 0 ) && (signal_level <= 100)));

    memset(&locate_info, 0, sizeof(locate_info));
    /*srv_nw_info_get_location_info*/
    bool_reval = srv_nw_info_get_location_info(v_sim, &locate_info);
	AVK_LOG_FUN(srv_nw_info_get_location_info,((MMI_TRUE == bool_reval) && (locate_info.plmn[0] != 0)));
    
    /*srv_nw_info_get_nw_plmn*/
    memset(char_plmn, 0, SRV_MAX_PLMN_LEN+1);
    bool_reval = srv_nw_info_get_nw_plmn(v_sim, char_plmn, SRV_MAX_PLMN_LEN+1);
	AVK_LOG_FUN(srv_nw_info_get_nw_plmn,((MMI_TRUE == bool_reval) && (char_plmn[0] != 0)));

    /*srv_nw_info_get_protocol*/
    nw_enum = srv_nw_info_get_protocol(v_sim);
	AVK_LOG_FUN(srv_nw_info_get_protocol,((MMI_GSM == nw_enum) || (MMI_WCDMA == nw_enum)));
        
    /*srv_nw_info_cell_supports*/
	AVK_LOG_FUN(srv_nw_info_cell_supports,((srv_nw_info_cell_supports(v_sim, MMI_GPRS))||(srv_nw_info_cell_supports(v_sim, MMI_EDGE))
        ||(srv_nw_info_cell_supports(v_sim, MMI_HSDPA))||(srv_nw_info_cell_supports(v_sim, MMI_HSUPA))));
        
    #ifdef __SRV_NW_INFO_CIPHER_SUPPORT__
        /*srv_nw_info_get_cipher_info*/
        memset(&cipher_info, 0xFF, sizeof(cipher_info));
        bool_reval = srv_nw_info_get_cipher_info(v_sim, &cipher_info);
		
		AVK_LOG_FUN(srv_nw_info_get_cipher_info,( 0xFF != cipher_info.ps_status));
    #else
        AVK_LOG_FUN_UNSUPPORTED(srv_nw_info_get_cipher_info);
    #endif
    
    #ifdef __HOMEZONE_SUPPORT__
        /*srv_nw_info_get_homezone_info*/
        memset(&homezone_info, 0, sizeof(homezone_info));
        bool_reval = srv_nw_info_get_homezone_info(v_sim, &homezone_info);
        //bool_reval == homezone_info.is_in_homezone
        /*Just check it can call */
		AVK_LOG_FUN(srv_nw_info_get_homezone_info,(MMI_FALSE == bool_reval));
    #else
		AVK_LOG_FUN_UNSUPPORTED(srv_nw_info_get_homezone_info);
    #endif
 
}

void avk_idle_nwinfo_channal_support(void)
{
	mmi_sim_enum v_sim;
	v_sim = MMI_SIM1;
	
	/*srv_nw_info_channel_supports*/
	AVK_LOG_FUN(srv_nw_info_channel_supports,((srv_nw_info_channel_supports(v_sim, MMI_GPRS))||(srv_nw_info_channel_supports(v_sim, MMI_EDGE))
        ||(srv_nw_info_channel_supports(v_sim, MMI_HSDPA))||(srv_nw_info_channel_supports(v_sim, MMI_HSUPA))));
    AVK_ASYN_DONE();       
}

AVK_MANUAL_CASE(AVK_IDLE_INFO_CASE_MANU,AVK_IDLE_INFO_MANU)
{
	AVK_MANU_SHOW_TIPS(L"Please Send MMS to SIM1, when E icon showed, press OK to run",avk_idle_nwinfo_channal_support);	
}
