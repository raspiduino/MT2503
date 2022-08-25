
#include "bcmadp.h"

#ifdef MMI_SRV_BT_PRXR_PROFILE 

#include "bcm_PrxrSrv.h"
#include "bcm_PrxCommon.h"
#include "bcm_PrxrApp.h"
#include "bcm_struct.h"
#include "bt_mmi.h"
#include "bcm_trc.h"
#include "bcm_btcmSrvGprot.h"

static prxr_callback_t pxp_cb_cntx;

static U8 discn_alert_level = 0;

/*****************************************************************************
 * FUNCTION
 *  pxp_srv_app_connection_state_cb
 * DESCRIPTION
 *  to notify reporter current connection state
 * PARAMETERS
 *  [bdaddr] Return remote bluetooth device addr
 *  [state] Profile current connection state
 * RETURNS
 *  void
 *****************************************************************************/
void pxp_app_connection_state_cb(char* bdaddr, int connect_state)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_CONNECT_CB,bdaddr,connect_state);
	if (PRX_STATUS_DISCONNECTED == connect_state) {
		bcm_pxps_disconn_alert_ind_struct *cnf;
		cnf = construct_local_para(sizeof(bcm_pxps_disconn_alert_ind_struct), TD_RESET);
		
		cnf->alert_level = (U8)discn_alert_level;
		memcpy(&(cnf->bd_addr), bdaddr, 6);
		bcm_send_ilm(MOD_L4C, MSG_ID_BCM_PXPS_DISCONN_ALERT_IND, cnf, NULL);	 
	} else if (PRX_STATUS_CONNECTED == connect_state) {
	    bcm_pxps_connected_ind_struct *cnf;
		cnf = construct_local_para(sizeof(bcm_pxps_connected_ind_struct), TD_RESET);
		
		memcpy(&(cnf->bd_addr), bdaddr, 6);
		bcm_send_ilm(MOD_L4C, MSG_ID_BCM_PXPS_CONNECTED_IND, cnf, NULL);	
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_alert_notify_cb
 * DESCRIPTION
 *  to notify reporter mmi task start/stop path loss alert(IAS)
 * PARAMETERS
 *  [bdaddr] Return remote bluetooth device addr
 *  [level] alert level of IAS
 * RETURNS
 *  void
 *****************************************************************************/
void pxp_app_alert_notify_cb(char* bdaddr, U8 alert_level)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	bcm_pxps_linkloss_alert_ind_struct *cnf;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_ALERT_CB, bdaddr, alert_level);
	cnf = construct_local_para(sizeof(bcm_pxps_linkloss_alert_ind_struct), TD_RESET);

	cnf->alert_level = (U8)alert_level;
	memcpy(&(cnf->bd_addr), bdaddr, 6);

	bcm_send_ilm(MOD_L4C, MSG_ID_BCM_PXPS_LINKLOSS_ALERT_IND, cnf, NULL);	 
}

/*****************************************************************************
 * FUNCTION
 *  pxp_srv_app_config_level_alert
 * DESCRIPTION
 *  to notify reporter mmi task link loss alert level config result
 * PARAMETERS
 *  [bdaddr] Return remote bluetooth device addr
 *  [level] alert level of LLS 
 * RETURNS
 *  void
 *****************************************************************************/
void pxp_app_config_level_alert_cb(char* bdaddr,U8 alert_level )
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_CONFIG_LEVEL,bdaddr,alert_level);
	discn_alert_level = alert_level;
}

/*****************************************************************************
 * FUNCTION
 *  pxp_app_event_handler
 * DESCRIPTION
 *  This function is to received service event
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void pxp_app_event_handler(U32 event, void* para)
{
    switch (event)
    {
        case SRV_BT_CM_EVENT_BEGIN_DEACTIVATE: {
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_EVENT_POWEROFF);
            pxp_app_disable();
        }
            break;

		default :
			break;
	}
}


/*****************************************************************************
 * FUNCTION
 *  fmpt_app_event_register
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *  Status of the profile initial
 *****************************************************************************/
void pxp_app_event_register(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U32 event_mask;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/	
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_EVENT_REGISTER);
	event_mask = SRV_BT_CM_EVENT_BEGIN_DEACTIVATE;
	srv_bt_cm_set_notify((srv_bt_cm_notifier)pxp_app_event_handler, event_mask, NULL);
	return; 
}

/*****************************************************************************
 * FUNCTION
 *  pxp_srv_app_power_on_to_init
 * DESCRIPTION
 *  This function is to rigister ppxp profile CBs
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void pxp_app_enable(void)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_SWITCH_ON);
    /*rigister callback to enable reporter role*/
	pxp_app_event_register();
	pxp_cb_cntx.connection_state_cb = pxp_app_connection_state_cb;
	pxp_cb_cntx.alert_notify_cb = pxp_app_alert_notify_cb;
	pxp_cb_cntx.config_level_cb = pxp_app_config_level_alert_cb;
	prxr_init(&pxp_cb_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_power_on_to_deinit
 * DESCRIPTION
 *  This function is to received service event
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void pxp_app_disable(void)
{	
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_SWITCH_OFF);
	/*derigister callback to unable reporter role*/
	prxr_deinit(&pxp_cb_cntx);
	pxp_cb_cntx.connection_state_cb = NULL;
	pxp_cb_cntx.alert_notify_cb = NULL;
	pxp_cb_cntx.config_level_cb = NULL;
	return;
}

#endif
