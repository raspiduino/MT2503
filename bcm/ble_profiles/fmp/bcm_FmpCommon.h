#ifndef __FMP_COMMON_H__
#define __FMP_COMMON_H__

#include "bt_mmi.h"
#include "bluetooth_gattc_struct.h"
#include "bcm_GattSrv.h"

/*
  *  Define the Find Me enable status
  *  (Locator/Target)
  *
  */
typedef U8 FMP_STATUS;

#define FMP_STATUS_DISABLED      0
#define FMP_STATUS_ENABLING      1
#define FMP_STATUS_ENABLED       2
#define FMP_STATUS_DISABLING     3

/*
  *  Define the Find Me current connection status
  *  (Locator/Target)
  *
  */
typedef U8 FMP_CONNECTION_STATUS;

#define FMP_STATUS_DISCONNECTED    0
#define FMP_STATUS_CONNECTING      1
#define FMP_STATUS_CONNECTED       2
#define FMP_STATUS_DISCONNECTING   3

/*
  *  Define the Find Me alert level
  *
  */
typedef U8 FMP_ALERT_LEVEL_TYPE;

#define FMP_ALERT_LEVEL_NO         0
#define FMP_ALERT_LEVEL_MILD       1
#define FMP_ALERT_LEVEL_HIGH       2

/*
  *  Define the Find Me service type
  *
  */
typedef U8 FMP_SERVICE_TYPE;

#define IAS_SERVICE_TYPE           0  //Immediate Alert Service, 0x1802
#define FMP_SERVICE_NUM            1  //Proximity Service Number

#define IMMEDIATE_ALERT_SERVICE    0x1802  //Immediate Alert Service, 0x1802
#define ALERT_LEVEL_CHAR_UUID      0x2A06  //Alert Level Characteristic, 0x2A06
#ifdef MMI_BLE_IAS_ALERT_STATUS_CHAR
#define ALERT_STATUS_CHAR_UUID      0x2ABC  //Alert Status Characteristic, 0x2ABC
#endif

typedef struct {
	ListEntry      char_node;
	ATT_UUID       char_uuid;
}FmpCharList;

typedef struct {
	ListEntry      svc_node;
	GATT_SVC_UUID  svc_uuid;
	ListEntry      char_list;
}FmpSvcList;

typedef struct {
	BOOL                  isSupported;
	ListEntry             svc_list;
	ATT_VALUE             char_value;
}FmpSrvInfo;

#endif
