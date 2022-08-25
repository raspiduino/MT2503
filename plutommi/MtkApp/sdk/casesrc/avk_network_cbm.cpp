extern "C"
{
#include "CbmSrvGprot.h"
}

AVK_ADD_ITEM(AVK_NW_CBM_AUTO,L"Auto case",AVK_NW_CBM);
// AVK_ADD_ITEM(AVK_NW_CBM_MANU,L"Manual case",AVK_NW_CBM);
 

/*****************************************************************************
 * FUNCTION
 *  vs_nw_cbm_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret vs_nw_cbm_callback(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_cbm_highlight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_NW_CBM_AUTO_CASE1, AVK_NW_CBM_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = 0;
    kal_uint8 app_id = 0;
    MMI_BOOL success = MMI_TRUE;
    	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    /* register bearer info */
    AVK_LOG(srv_cbm_register_bearer_info(2,
    								 SRV_CBM_ACTIVATED | SRV_CBM_DEACTIVATED,
    								 SRV_CBM_BEARER_CSD | SRV_CBM_BEARER_PS | SRV_CBM_BEARER_WIFI,
    								 vs_nw_cbm_callback, NULL));

    /* Deregister bearer info */
    AVK_LOG(srv_cbm_deregister_bearer_info(2));

    /* Register bearer event */
    AVK_LOG(srv_cbm_register_bearer_event(
       SRV_CBM_BEARER_ALWAYS_ASK | SRV_CBM_BEARER_FB_L1,
       2,
       vs_nw_cbm_callback,
       NULL));

    /* Abort bearer event */
    AVK_LOG(srv_cbm_abort_app_bearer_event(2));

    /* Deregister bearer event*/
    AVK_LOG(srv_cbm_deregister_bearer_event(2));
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_cbm_02
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_NW_CBM_AUTO_CASE2, AVK_NW_CBM_AUTO)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 result = 0;
	MMI_STR_ID string_id;
	mmi_event_notify_enum popup_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	/* Allow phone network service */
	AVK_LOG(srv_cbm_set_allowed_app_nwk_srv(CBM_BEARER_GSM_GPRS, 2));

	/* check if network service disallowed */
	AVK_LOG(srv_cbm_is_nwk_srv_disallowed(SRV_CBM_BEARER_GPRS));

	/* Get network servive */
	AVK_LOG((S32)srv_cbm_get_nwk_srv_error_info((srv_cbm_result_error_enum)result, &string_id, &popup_type));
 
}
