#ifndef __PRXR_SRV_H__
#define __PRXR_SRV_H__

//#ifdef MMI_SRV_BT_PRXR_PROFILE 

#include "bt_mmi.h"

#ifndef BtStatus

typedef int BtStatus;
#define BT_STATUS_SUCCESS  0
#define BT_STATUS_FAILED   1
#define BT_STATUS_PENDING  2

#endif

/** BT-Proximity callback defination. */

/** Callback invoked in response to connect/disconnect for Monitor/Reporter*/
typedef void (*prxr_connection_state_callback)(char *bdaddr, int state);

/** Callback for config alert level */
typedef void (*prxr_config_level_callback)(char *bd_addr, U8 level);

/** Callback for start/stop alert level */
typedef void (*prxr_alert_notify_callback)(char *bd_addr, U8 level);

/* define proximity monitor role callback funtion*/
typedef struct
{
    prxr_connection_state_callback           connection_state_cb;
    prxr_config_level_callback               config_level_cb;
	prxr_alert_notify_callback               alert_notify_cb;
}prxr_callback_t;

BtStatus prxr_init(prxr_callback_t *cb);

BtStatus prxr_deinit();
U32 prxr_send_data(void* buf, U32 len); //add for MMI_BLE_IAS_ALERT_STATUS_CHAR

//#endif

#endif
