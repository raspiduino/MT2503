#ifndef __PRXR_DEF_H__
#define __PRXR_DEF_H__

//#ifdef MMI_SRV_BT_PRXR_PROFILE 

#include "bt_mmi.h"
#include "stack_msgs.h"
#include "bcm_PrxCommon.h"
#include "bcm_PrxrSrv.h"
#include "bcm_GattServicesFactorySrv.h"
#include "bcm_GattSrv.h"
#include "bcm_GattsSrv.h"

typedef enum {
	PRXR_OP_INIT = 0,
	PRXR_OP_GET_SERVICE,
	PRXR_OP_ADD_SERVICE,
	PRXR_OP_DEL_SERVICE,
	PRXR_OP_DEINIT,
}PRXR_OP_CODE;

typedef enum {
	PRXR_REQ_READ_TXPOWER = 0,
}PRXR_REQ_TYPE;

typedef struct {
	ListEntry            req_node;
	gatt_conn_struct     gatt_conn;
	char                 bdaddr[BD_ADDR_SIZE];
	PRXR_REQ_TYPE        req_type;
	U16                  trans_id;
	ATT_HANDLE           att_handle;
	U16                  offset;
	ATT_VALUE		     att_value;
}PrxrReq;


typedef struct {
    ListEntry             conn_node;
	void                 *conn_ctx;
	int                   conn_status;
	U8                    lls_alert_level;
	char                  bdaddr[BD_ADDR_SIZE];
}PrxrConnCntx;

typedef struct {
	void                 *reg_ctx;
	prxr_callback_t      *callback;
	PRX_STATUS            state;
	bt_uuid_struct        uid;
	ListEntry             conn_list; 
	ListEntry             req_list;
	int                   op_flag;
	gatts_srvs_lst_struct srv_list;
	gatts_service_decl_struct *srv_node;
}PrxrCntx;

//#endif

#endif
