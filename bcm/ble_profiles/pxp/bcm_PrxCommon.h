#ifndef __PRX_COMMON_H__
#define __PRX_COMMON_H__

#include "bt_mmi.h"
#include "bluetooth_gattc_struct.h"
#include "bcm_GattSrv.h"

/*
  *  Define the proximity enable status
  *  (Monitor/Reporter)
  *
  */
typedef U8 PRX_STATUS;

#define PRX_STATUS_DISABLED      0
#define PRX_STATUS_ENABLING      1
#define PRX_STATUS_ENABLED       2
#define PRX_STATUS_DISABLING     3

/*
  *  Define the proximity current connection status
  *  (Monitor/Reporter)
  *
  */
typedef U8 PRX_CONNECTION_STATUS;

#define PRX_STATUS_DISCONNECTED    0
#define PRX_STATUS_CONNECTING      1
#define PRX_STATUS_CONNECTED       2
#define PRX_STATUS_DISCONNECTING   3

/*
  *  Define the proximity alert level
  *
  */
typedef U8 PRX_ALERT_LEVEL_TYPE;

#define PRX_ALERT_LEVEL_NO         0
#define PRX_ALERT_LEVEL_MILD       1
#define PRX_ALERT_LEVEL_HIGH       2
#define PRX_ALERT_LEVEL_MILD_RANGE      3
#define PRX_ALERT_LEVEL_HIGH_RANGE       4
/*
  *  Define the proximity service type
  *
  */
typedef U8 PRX_SERVICE_TYPE;

#define LLS_SERVICE_TYPE           0  //Link Loss service, 0x1803
#define TPS_SERVICE_TYPE           1  //Tx Power Service, 0x1804
#define IAS_SERVICE_TYPE           2  //Immediate Alert Service, 0x1802
#define PRX_SERVICE_NUM            3  //Proximity Service Number

#define LINK_LOSS_SERVICE          0x1803  //Link Loss service, 0x1803
#define TX_POWER_SERVICE           0x1804  //Tx Power Service, 0x1804
#define IMMEDIATE_ALERT_SERVICE    0x1802  //Immediate Alert Service, 0x1802

#define ALERT_LEVEL_CHAR_UUID      0x2A06  //Link Loss service, 0x1803
#define TX_POWER_CHAR_UUID         0x2A07  //Tx Power Service, 0x1804
#ifdef MMI_BLE_IAS_ALERT_STATUS_CHAR
#define ALERT_STATUS_CHAR_UUID     0x2ABC  //Alert Status Characteristic, 0x2ABC
#endif

typedef struct {
	ListEntry      char_node;
	ATT_UUID       char_uuid;
}PrxCharList;

typedef struct {
	ListEntry       svc_node;
	GATT_SVC_UUID   svc_uuid;
	ListEntry       char_list;
}PrxSvcList;

typedef struct {
	BOOL                  isSupported;
	ListEntry             svc_list;
	ATT_VALUE             char_value;
}PrxSrvInfo;

#endif
