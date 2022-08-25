#ifndef __FMPT_DEF_H__
#define __FMPT_DEF_H__

//#ifdef MMI_SRV_BT_FMPT_PROFILE 

#include "bt_mmi.h"
#include "stack_msgs.h"
#include "bcm_FmpCommon.h"
#include "bcm_FmptSrv.h"
#include "bcm_GattServicesFactorySrv.h"
#include "bcm_GattSrv.h"
#include "bcm_GattsSrv.h"

typedef enum {
	FMPT_OP_INIT = 0,
	FMPT_OP_GET_SERVICE,
	FMPT_OP_ADD_SERVICE,
	FMPT_OP_DEL_SERVICE,
	FMPT_OP_DEINIT,
}FMPT_OP_CODE;

typedef struct {
    ListEntry             conn_node;
	void                 *conn_ctx;
	int                   conn_status;
	char                  bdaddr[BD_ADDR_SIZE];
}FmptConnCntx;

typedef struct {
	void                 *reg_ctx;
	fmpt_callback_t      *callback;
	FMP_STATUS            state;
	bt_uuid_struct        uid;
	ListEntry             conn_list; 
	int                   op_flag;
	gatts_srvs_lst_struct srv_list;
}FmptCntx;

#endif
