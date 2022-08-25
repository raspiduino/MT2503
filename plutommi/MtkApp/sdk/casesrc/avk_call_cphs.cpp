extern "C"
{
	#include "CphsSrvGprot.h"
}

AVK_ADD_ITEM(AVK_CALL_CPHS_AUTO,L"Auto case",AVK_CALL_CPHS);

AVK_CASE(AVK_CALL_CPHS_CASE,AVK_CALL_CPHS_AUTO) {

	#define MAX_CPHS_LEN (64)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U8 csp_data[22];
    MMI_BOOL reval;
    srv_cphs_group_enum group_name = SRV_CPHS_GROUP_OTHER_SUPP_SERVICES;
    srv_cphs_service_enum service = SRV_CPHS_SERVICE_CUG;
    mmi_sim_enum select_sim = MMI_SIM1;
    const WCHAR *wstrname = NULL;
    const WCHAR *wstrnum = NULL;
    kal_char cstrname[MAX_CPHS_LEN];
    kal_char cstrnum[MAX_CPHS_LEN];
    U8 num_msisdn = 1;
    l4csmu_addr_struct msisdn;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    
    /*srv_cphs_is_valid_csp*/
    reval = srv_cphs_is_valid_csp(MMI_SIM1); //Need to insert SIM which support CPHS
    AVK_LOG_FUN(srv_cphs_is_valid_csp,(reval == MMI_TRUE));
    
    /*srv_cphs_is_service_available*/ 
    reval = srv_cphs_is_service_available(group_name, service, select_sim);
	AVK_LOG_FUN(srv_cphs_is_service_available,(reval == MMI_TRUE));
    
    /*srv_cphs_parse_msisdn_info*//*srv_cphs_get_msisdn_name*//*srv_cphs_get_msisdn_number*/
    memset(&msisdn, 0, sizeof(l4csmu_addr_struct));
    strcpy((char *)msisdn.alpha_id, "MediaTeck");
    msisdn.alpha_id_size = strlen((char *)msisdn.alpha_id);
    strcpy((char *)msisdn.digit, "82861128");
    msisdn.digit_size = strlen((char *)msisdn.digit);
    
    srv_cphs_parse_msisdn_info(num_msisdn, &msisdn, select_sim);
    wstrname = srv_cphs_get_msisdn_name(SRV_CPHS_MSISDN_TYPE_LINE1, select_sim);
    mmi_wcs_to_asc(cstrname, (WCHAR *)wstrname);
	AVK_LOG_FUN(srv_cphs_parse_msisdn_info,(0 == strcmp((char *)msisdn.alpha_id, cstrname)));
	AVK_LOG_FUN(srv_cphs_get_msisdn_name,(0 == strcmp((char *)msisdn.alpha_id, cstrname)));
    
    
    wstrnum = srv_cphs_get_msisdn_number(SRV_CPHS_MSISDN_TYPE_LINE1, select_sim);
    mmi_wcs_to_asc(cstrnum, (WCHAR *)wstrnum);
	AVK_LOG_FUN(srv_cphs_get_msisdn_number,(0 == strcmp((char *)msisdn.digit, cstrnum)));

}

