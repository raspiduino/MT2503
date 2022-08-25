#ifndef __FMPT_SRV_H__
#define __FMPT_SRV_H__

//#ifdef MMI_SRV_BT_FMPT_PROFILE 

#include "bt_mmi.h"

#ifndef BtStatus

typedef int BtStatus;
#define BT_STATUS_SUCCESS  0
#define BT_STATUS_FAILED   1
#define BT_STATUS_PENDING  2

#endif


/** BT-Findme callback defination. */

/** Callback invoked in response to connect/disconnect for Monitor/Reporter*/
typedef void (*fmpt_connection_state_callback)(char *bdaddr, int state);

/** Callback for start/stop alert level */
typedef void (*fmpt_alert_notify_callback)(char *bd_addr, U8 level);

/* define proximity monitor role callback funtion*/
typedef struct
{
    fmpt_connection_state_callback           connection_state_cb;
	fmpt_alert_notify_callback               alert_notify_cb;
}fmpt_callback_t;

BtStatus fmpt_init(fmpt_callback_t *cb);

BtStatus fmpt_deinit();

U32 fmpt_send_data(void* buf, U32 len); //add for MMI_BLE_IAS_ALERT_STATUS_CHAR

//#endif

#endif
