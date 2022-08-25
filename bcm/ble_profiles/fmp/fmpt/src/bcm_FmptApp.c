#include "bcmadp.h"

#ifdef MMI_SRV_BT_FMPT_PROFILE 
#include "bcm_FmptSrv.h"
#include "bcm_FmptApp.h"
#include "bcm_struct.h"
#include "bcm_trc.h"
#include "bcm_FmpCommon.h"
#include "bcm_btcmSrvGprot.h"

static fmpt_callback_t fmpt_cb_cntx;

/*****************************************************************************
 * FUNCTION
 *  fmpt_app_connection_cb
 * DESCRIPTION
 *  to notify reporter current connection state
 * PARAMETERS
 *  [bdaddr] Return remote bluetooth device addr
 *  [state] Profile current connection state
 * RETURNS
 *  void
 *****************************************************************************/
void fmpt_app_connection_cb(char* bdaddr, int connect_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_FMPAPP_REMOTER_CNNC, bdaddr,connect_state);
	if ((FMP_STATUS_CONNECTED == connect_state) || (FMP_STATUS_DISCONNECTED == connect_state)) {
		bcm_fmps_connected_ind_struct *cnf;
		cnf = construct_local_para(sizeof(bcm_fmps_connected_ind_struct), TD_RESET);
		if (FMP_STATUS_CONNECTED == connect_state) {
	        cnf->op = 1;//connected
		} else {	
			cnf->op = 0;//disconnected
		}
		memcpy(&(cnf->bd_addr), bdaddr, 6);
		bcm_send_ilm(MOD_L4C, MSG_ID_BCM_FMPS_CONNECTED_IND, cnf, NULL);	
	}

}


/*****************************************************************************
 * FUNCTION
 *  fmpt_app_alert_notify_cb
 * DESCRIPTION
 *  to notify reporter mmi task start/stop path loss alert(IAS)
 * PARAMETERS
 *  [bdaddr] Return remote bluetooth device addr
 *  [level] alert level of IAS
 * RETURNS
 *  void
 *****************************************************************************/
void fmpt_app_alert_notify_cb(char* bdaddr, U8 alert_level)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	bcm_fmps_write_alert_ind_struct *cnf;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_FMPAPP_REMOTER_ALERT, bdaddr, alert_level);
	cnf = construct_local_para(sizeof(bcm_fmps_write_alert_ind_struct), TD_RESET);

	cnf->alert_level = (U8)alert_level;
	memcpy(&(cnf->bd_addr), bdaddr, 6);

	bcm_send_ilm(MOD_L4C, MSG_ID_BCM_FMPS_WRITE_ALERT_IND, cnf, NULL);   
}

/*****************************************************************************
 * FUNCTION
 *  fmpt_app_event_handler
 * DESCRIPTION
 *  This function is to received service event
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void fmpt_app_event_handler(U32 event, void* para)
{
    switch (event)
    {

        case SRV_BT_CM_EVENT_BEGIN_DEACTIVATE: {	
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_FMPAPP_EVENT_POWEROFF);
            fmpt_app_disable();
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
void fmpt_app_event_register(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U32 event_mask;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/	
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_FMPAPP_EVENT_REGISTER);
	event_mask = SRV_BT_CM_EVENT_BEGIN_DEACTIVATE;
	srv_bt_cm_set_notify((srv_bt_cm_notifier)fmpt_app_event_handler, event_mask, NULL);
	return; 
}

void fmpt_app_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_FMPAPP_SWITCH_ON);
    /*rigister callback to enable target role*/
    fmpt_app_event_register();
    fmpt_cb_cntx.connection_state_cb = fmpt_app_connection_cb;
    fmpt_cb_cntx.alert_notify_cb = fmpt_app_alert_notify_cb;
    fmpt_init(&fmpt_cb_cntx);
    return;
}


void fmpt_app_disable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_FMPAPP_SWITCH_OFF);
    /*to disable target role*/
    fmpt_deinit(&fmpt_cb_cntx);
    fmpt_cb_cntx.connection_state_cb = NULL;
    fmpt_cb_cntx.alert_notify_cb = NULL;
    return;
}
#endif

