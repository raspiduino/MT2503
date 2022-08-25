extern "C"
{
/**** Data Acccount related *****/
#include "DataAccountGProt.h"
#include "DtcntSrvGprot.h"
#include "DtcntSrvIprot.h"
/**Data Account End **/
}

AVK_ADD_ITEM(AVK_NW_DA_AUTO,L"Auto case",AVK_NW_DA);
AVK_ADD_ITEM(AVK_NW_DA_MANU,L"Manual case",AVK_NW_DA);



/***** Data Account ************/
kal_uint8 g_avk_nw_da_app_id = 0;
kal_uint32 g_avk_nw_da_account_id = 0;
extern srv_dtcnt_prof_csd_struct g_data_account_csd_profile_srv;
/***** Data Account End************/

void vs_nw_data_acc_ready_check_cb(void)
{
}


/*****************************************************************************
 * FUNCTION
 *  AVK_NW_DA_AUTO_CASE1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_NW_DA_AUTO_CASE1, AVK_NW_DA_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_connection_type_enum  conn_type = (srv_dtcnt_connection_type_enum)1;
    kal_uint32 encoded_id = 0;

    S32 result = 0;
    U32 acc_id_out = 0;
    //S8 *default_acc_name = NULL;
#ifndef  __COSMOS_MMI_PACKAGE__
    U32 first_account = 0;
#endif
    //MMI_BOOL ret = MMI_FALSE, suc = MMI_TRUE;
    S8 buf[65];
    srv_dtcnt_prof_str_info_qry_struct out_acc_name;
    srv_dtcnt_prof_str_info_qry_struct out_apn;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Initialise */
    g_avk_nw_da_account_id = CBM_DEFAULT_ACCT_ID;

    out_apn.dest = NULL;
    out_acc_name.dest = NULL;
    AVK_LOG(srv_dtcnt_get_apn(g_avk_nw_da_account_id, &out_apn, SRV_DTCNT_ACCOUNT_PRIMARY));
    
#ifndef  __COSMOS_MMI_PACKAGE__
    /* Get default name */
    AVK_LOG_EX(NULL != GetString(mmi_dtcnt_get_default_name_str_id()));

    /* Get invalid string ID */
    AVK_LOG_EX(NULL != GetString(mmi_dtcnt_get_invalid_name_str_id()));
#endif 

    /* Get account name */
    AVK_LOG(srv_dtcnt_get_account_name(g_avk_nw_da_account_id, &out_acc_name, SRV_DTCNT_ACCOUNT_PRIMARY));

#ifndef  __COSMOS_MMI_PACKAGE__
    /* get full account name */
    memset(buf, 0, 65); 
    AVK_LOG_EX(mmi_dtcnt_get_full_account_name(first_account, (S8*)buf, MAX_DATA_ACCOUNT_NAME_LEN, MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE));
#endif 

	cbm_register_app_id(&g_avk_nw_da_app_id);

    /* Encode account Id */
    encoded_id = cbm_encode_data_account_id(g_avk_nw_da_account_id, CBM_SIM_ID_SIM1, 
                                      g_avk_nw_da_app_id, KAL_FALSE);
#ifndef  __COSMOS_MMI_PACKAGE__
    /* Check for validity */
    AVK_LOG_EX(mmi_dtcnt_acct_is_valid(encoded_id));
#endif  

    /* Get Auto account ID */
    AVK_LOG(0 != srv_dtcnt_get_auto_acc_id(encoded_id, &acc_id_out));

    /* get bearer type */
    result = 0;
    result = srv_dtcnt_get_bearer_type(g_avk_nw_da_account_id, (srv_dtcnt_account_enum)1);
    switch(result)
    {
        case SRV_DTCNT_BEARER_UNKNOWN:     
        case SRV_DTCNT_BEARER_CSD:        
        case SRV_DTCNT_BEARER_GPRS:       
        case SRV_DTCNT_BEARER_WIFI:
            AVK_LOG_FUN(srv_dtcnt_get_bearer_type, AVK_PASS);
            break;
        default:
            AVK_LOG_FUN(srv_dtcnt_get_bearer_type, AVK_FAIL);
    }
    
    /* get connection type */
    //ret = MMI_FALSE;
    srv_dtcnt_get_connection_type(g_avk_nw_da_account_id, &conn_type);

    if((conn_type == SRV_DTCNT_CONN_TYPE_WAP) || (conn_type == SRV_DTCNT_CONN_TYPE_HTTP))  
    {
        AVK_LOG_FUN(srv_dtcnt_get_connection_type, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_dtcnt_get_connection_type, AVK_FAIL);
    }

    /*get CSD no. */
    memset(buf, 0, 25);
    AVK_LOG_EX(0 == srv_dtcnt_get_csd_number(g_avk_nw_da_account_id, &out_apn, SRV_DTCNT_ACCOUNT_PRIMARY));

#ifndef  __COSMOS_MMI_PACKAGE__
    /* Data Account ready check */
    AVK_LOG_EX(mmi_dtcnt_ready_check((FuncPtr)vs_nw_data_acc_ready_check_cb, MMI_TRUE));
#endif 
    
#ifdef __MMI_OP01_DCD__
    /* get DCD */
    AVK_LOG_EX(mmi_dtcnt_get_dcd_acct_id());
#endif /*__MMI_OP01_DCD__*/
}
/*****************************************************************************
 * FUNCTION
 *  vs_nw_data_acc_02
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_NW_DA_AUTO_CASE2, AVK_NW_DA_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //srv_dtcnt_prof_str_info_qry_struct out_homepage;
    srv_dtcnt_prof_proxy_info_struct out_px_info;
    srv_dtcnt_sim_type_enum sim_info;
    U32 acc_id_out = 0;
    //S32 value = 0;
    //srv_dtcnt_result_enum result = (srv_dtcnt_result_enum)0;
    //MMI_BOOL ret = MMI_FALSE, suc = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //out_homepage.dest = NULL;
    /* Get valid account ID */
    g_avk_nw_da_account_id = 0;
    AVK_LOG(cbm_get_valid_account_id(CBM_BEARER_GSM_GPRS, &g_avk_nw_da_account_id));
    
#ifdef __MMI_GPRS_FEATURES__
#ifndef  __COSMOS_MMI_PACKAGE__
    AVK_LOG_EX(mmi_dtcnt_set_GPRS_APN_for_project_mode("CMWAP", CBM_ALL_NWK_ACCT_ID));
#endif /*__MMI_GPRS_FEATURES__*/
#endif 
    
    /* Is read only */
    AVK_LOG(srv_dtcnt_acct_is_read_only(g_avk_nw_da_account_id));
    
    /* Get account ID by APN */
    AVK_LOG_EX(0 == srv_dtcnt_get_acc_id_by_apn("cmwap", &acc_id_out));

    /* get proxy info */
    AVK_LOG(srv_dtcnt_get_proxy_info( g_avk_nw_da_account_id, 
                                    &out_px_info, 
                                    SRV_DTCNT_ACCOUNT_PRIMARY));
    
    /* Get SIM Info */
    AVK_LOG(srv_dtcnt_get_sim_info(g_avk_nw_da_account_id, &sim_info));
}

/*****************************************************************************
 * FUNCTION
 *  vs_nw_data_acc_ready_clbk
 * DESCRIPTION
 *  callback for mmi_dtcnt_ready_check
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_nw_data_acc_ready_clbk(void *user_data, srv_dtcnt_wlan_req_res_enum res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

/*****************************************************************************
 * FUNCTION
 *  vs_nw_data_acc_delete_clbk
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_nw_data_acc_delete_clbk(U32 deleting_acc_id, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}
/*****************************************************************************
 * FUNCTION
 *  vs_nw_data_acc_03
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_NW_DA_AUTO_CASE3, AVK_NW_DA_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_store_prof_data_struct qry;
    U32 acc_prof_id = 0;
    //MMI_BOOL ret = MMI_FALSE, suc = MMI_TRUE;
    //U8 buf[] = "Hello";
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    qry.prof_data = NULL;

    /* query profile by account ID */
    AVK_LOG_EX(SRV_DTCNT_RESULT_FAILED != srv_dtcnt_store_qry_prof(acc_prof_id,&qry));
    
    /* delete profile */
    AVK_LOG_EX(SRV_DTCNT_RESULT_FAILED != srv_dtcnt_store_delete_prof(acc_prof_id, 
                                          MMI_TRUE, 
                                          NULL, 
                                          vs_nw_data_acc_delete_clbk));
    /* config prof */
    AVK_LOG_EX(SRV_DTCNT_RESULT_FAILED != srv_dtcnt_store_config(SRV_DTCNT_PROF_CONFIG_ALL_ENABLE, 
                                    SRV_DTCNT_BEARER_GPRS));
    
    /* Commit */
    AVK_LOG(SRV_DTCNT_RESULT_FAILED != srv_dtcnt_store_commit());

}

/*****************************************************************************
 * FUNCTION
 *  vs_nw_data_acc_wlan_clbk
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_nw_data_acc_wlan_clbk(
            U32 job_id,
            void *user_data,
            srv_dtcnt_wlan_scan_result_struct *scan_res)
{

}

/*****************************************************************************
 * FUNCTION
 *  vs_nw_data_acc_04
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_NW_DA_AUTO_CASE4, AVK_NW_DA_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WLAN_FEATURES__

    srv_dtcnt_prof_wlan_struct profile;
    srv_dtcnt_prof_str_info_qry_struct ssid_out;
    S32 rssi_out = 0;
    S32 result = 0;
    //U32 value;
    U8 buf[] = "hello";
    //MMI_BOOL suc = MMI_TRUE, ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* WLAN features */

    /* Initialise */
    AVK_LOG_EX(srv_dtcnt_wlan_init(vs_nw_data_acc_ready_clbk, 
                                              (void *) buf));

    /* init profile */
    memset(&profile, 0, sizeof(srv_dtcnt_prof_wlan_struct));
    srv_dtcnt_wlan_init_profile(&profile);
    if(profile.network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA)
    {
        AVK_LOG_FUN(srv_dtcnt_wlan_init_profile, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_dtcnt_wlan_init_profile, AVK_FAIL);
    }

    /* get connected AP's signal strength */
    AVK_LOG(srv_dtcnt_wlan_get_connected_ap_rssi(&rssi_out));
    
    /* get AP's SSID */
    AVK_LOG(srv_dtcnt_wlan_get_connected_ap_ssid(&ssid_out));
    
    /* Scan the AP list for applications */
    AVK_LOG_EX(srv_dtcnt_wlan_scan(vs_nw_data_acc_wlan_clbk,(void *) buf));
    
    /* Get the WLAN status */
    result = srv_dtcnt_wlan_status();
    switch(result)
    {
        case SRV_DTCNT_WLAN_STATUS_INACTIVE:  
        case SRV_DTCNT_WLAN_STATUS_ACTIVE:       
        case SRV_DTCNT_WLAN_STATUS_CONNECTED:    
        case SRV_DTCNT_WLAN_STATUS_INVALID_MAC:
            AVK_LOG_FUN(srv_dtcnt_wlan_status, AVK_PASS);
            break;
        default:
            AVK_LOG_FUN(srv_dtcnt_wlan_status, AVK_FAIL);
    }
    
    /* deinitialise WLAN*/
    AVK_LOG_EX(srv_dtcnt_wlan_deinit((srv_dtcnt_wlan_cb_func_ptr)vs_nw_data_acc_wlan_clbk, (void *)buf));
  
    /* disconnect the WLAN */
    AVK_LOG_EX(SRV_DTCNT_RESULT_STATE_ERROR != srv_dtcnt_wlan_disconnect());
#else
    AVK_LOG_FUN_UNSUPPORTED(srv_dtcnt_wlan_init);
#endif /*__MMI_WLAN_FEATURES__*/
}
/*****************************************************************************
 * FUNCTION
 *  vs_nw_data_acc_exit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_nw_data_acc_exit(void)
{
    cbm_deregister_app_id(g_avk_nw_da_app_id);
}



