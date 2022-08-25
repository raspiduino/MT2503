#ifndef __GATTC_SRV_H__
#define __GATTC_SRV_H__

#include "bt_types.h"
#include "btostypes.h"
#include "bluetooth_gattc_struct.h"
#include "bcm_GattSrv.h"

/****************************************************************************
* data define
****************************************************************************/
/* authentication requirement */
typedef U8 GATTC_AUTH_REQ;
#define GATTC_AUTH_REQ_NONE              0
#define GATTC_AUTH_REQ_NO_MITM           1   /* unauthenticated encryption */
#define GATTC_AUTH_REQ_MITM              2   /* authenticated encryption */
#define GATTC_AUTH_REQ_SIGNED_NO_MITM    3
#define GATTC_AUTH_REQ_SIGNED_MITM       4

typedef U8 GATTC_WRITE_TYPE;
#define GATTC_WRITE_TYPE_NO_RSP          1
#define GATTC_WRITE_TYPE_REQUEST         2
#define GATTC_WRITE_TYPE_PREPARE         3

typedef U8 GATTC_DEV_TYPE;
#define GATTC_DEV_TYPE_UNKNOWN           0
#define GATTC_DEV_TYPE_LE                1
#define GATTC_DEV_TYPE_BR_EDR            2
#define GATTC_DEV_TYPE_BR_EDR_LE         3

/*add for low power begain*/
#ifdef __MMI_BLE_LOW_POWER__
#define GATT_SRV_MAX_PROFILE_NUM (15)

typedef enum
{
	CONNECTION_PRIORITY_DEFAULT,
    CONNECTION_PRIORITY_HIGH_SPEED,
    CONNECTION_PRIORITY_LOW_POWER,
    CONNECTION_PRIORITY_BALANCE
}CONN_PRIO_ENUM;

/*add for low power begain*/
typedef enum
{
	GATTC_ADV_INTERVAL_DEFAULT,
	GATTC_ADV_INTERVAL_FAST_CONN,
    GATTC_ADV_INTERVAL_REDUCE_POWER
}gattc_adv_interval_enum;

typedef struct
{
	CONN_PRIO_ENUM curr_priority;// current connection parameter priority
    U32 high_speed[GATT_SRV_MAX_PROFILE_NUM];
    U32 balance[GATT_SRV_MAX_PROFILE_NUM];
    U32 low_power[GATT_SRV_MAX_PROFILE_NUM];
    //U32 default_prio[15];
}gattc_conn_prio_struct;

typedef struct
{
	BOOL is_confirmed;
    U8 bd_addr[BD_ADDR_SIZE];//remote device address
	U32 set_times;
	gattc_conn_prio_struct conn_info;//	
}gattc_conn_param_struct;

#endif /* __MMI_BLE_LOW_POWER__ */

/*add for low power end*/

typedef struct
{
    GATT_SVC_UUID *svc_uuid;
    ATT_UUID *char_uuid;
} gattc_char_struct;

typedef struct
{
    GATT_SVC_UUID *svc_uuid;
    ATT_UUID *char_uuid;
    ATT_UUID *descr_uuid;
} gattc_descr_struct;

/** BT-GATT Client callback structure. */

/** Callback invoked in response to register */
typedef void (*register_client_callback)(void *reg_ctx, OS_STATUS status, bt_uuid_struct *app_uuid);

/** Callback invoked in response to deregister */
typedef void (*deregister_client_callback)(void *reg_ctx, OS_STATUS status);

/** Callback for scan results */
typedef void (*scan_result_callback)(void *reg_ctx, BD_ADDR *bd_addr, S32 rssi, U8 eir_len, U8 *eir);

/** Callback indicating that a remote device has connected or been disconnected */
typedef void (*connection_callback)(gatt_conn_struct *conn, BOOL connected, BD_ADDR *bd_addr);

/** Callback indicating that a remote device has connected or been disconnected */
typedef void (*connection_ext_callback)(gattsrv_conn_struct *conn);

/** Callback triggered in response to listen */
typedef void (*listen_callback)(void *reg_ctx, OS_STATUS status);

/** Callback triggered in response to set_adv_data */
typedef void (*set_adv_data_callback)(void *reg_ctx, OS_STATUS status);

/**
 * Invoked in response to search_service when the GATT service search
 * has been completed.
 */
typedef void (*search_complete_callback)(gatt_conn_struct *conn, OS_STATUS status);

/** Reports GATT services on a remote device */
typedef void (*search_result_callback)(gatt_conn_struct *conn, GATT_SVC_UUID *uuid);

/** GATT characteristic enumeration result callback */
typedef void (*get_characteristic_callback)(gatt_conn_struct *conn, OS_STATUS status,
                                gattc_char_struct *char_info, GATT_CHAR_PROPERTIES properties);

/** GATT descriptor enumeration result callback */
typedef void (*get_descriptor_callback)(gatt_conn_struct *conn, OS_STATUS status, gattc_descr_struct *descr_info);

/** GATT included service enumeration result callback */
typedef void (*get_included_service_callback)(gatt_conn_struct *conn, OS_STATUS status,
                                GATT_SVC_UUID *svc_uuid, GATT_SVC_UUID *incl_svc_uuid);

/** Callback invoked in response to [de]register_for_notification */
typedef void (*register_for_notification_callback)(void *reg_ctx, OS_STATUS status, 
                                BD_ADDR *bd_addr, gattc_char_struct *char_info);

/**
 * Remote device notification callback, invoked when a remote device sends
 * a notification or indication that a client has registered for.
 */
typedef void (*notify_callback)(gatt_conn_struct *conn, BD_ADDR *bd_addr,
                                gattc_char_struct *char_info, ATT_VALUE *value, BOOL is_notify);

/** Reports result of a GATT read operation */
typedef void (*read_characteristic_callback)(gatt_conn_struct *conn, OS_STATUS status,
                                gattc_char_struct *char_info, ATT_VALUE *value);

/** GATT write characteristic operation callback */
typedef void (*write_characteristic_callback)(gatt_conn_struct *conn, OS_STATUS status,
                                gattc_char_struct *char_info);

/** Callback invoked in response to read_descriptor */
typedef void (*read_descriptor_callback)(gatt_conn_struct *conn, OS_STATUS status,
                                gattc_descr_struct *descr_info, ATT_VALUE *value);                                

/** Callback invoked in response to write_descriptor */
typedef void (*write_descriptor_callback)(gatt_conn_struct *conn, OS_STATUS status,
                                gattc_descr_struct *descr_info);    

/** GATT execute prepared write callback */
typedef void (*execute_write_callback)(gatt_conn_struct *conn, OS_STATUS status);

/** Callback triggered in response to read_remote_rssi */
typedef void (*read_remote_rssi_callback)(void *reg_ctx, OS_STATUS status, BD_ADDR *bd_addr, S32 rssi);

/** Callback triggered in response to get_device_type */
typedef void (*get_device_type_callback)(void *reg_ctx, OS_STATUS status, BD_ADDR *bd_addr, GATTC_DEV_TYPE dev_type);

/** Callback triggered in response to service change */
typedef void (*research_service_callback)(gatt_conn_struct *conn, OS_STATUS status, BD_ADDR *bd_addr);

/* status : Used by message handler to return result of request */
typedef struct
{
    register_client_callback            register_client_cb;
    scan_result_callback                scan_result_cb;
    connection_callback                 connection_cb;
    listen_callback                     listen_cb;
    set_adv_data_callback               set_adv_data_cb;
    search_complete_callback            search_complete_cb;
    search_result_callback              search_result_cb;
    get_characteristic_callback         get_characteristic_cb;
    get_descriptor_callback             get_descriptor_cb;
    get_included_service_callback       get_included_service_cb;
    register_for_notification_callback  register_for_notification_cb;
    notify_callback                     notify_cb;
    read_characteristic_callback        read_characteristic_cb;
    write_characteristic_callback       write_characteristic_cb;
    read_descriptor_callback            read_descriptor_cb;
    write_descriptor_callback           write_descriptor_cb;
    execute_write_callback              execute_write_cb;
    read_remote_rssi_callback           read_remote_rssi_cb;
    get_device_type_callback            get_device_type_cb;
    deregister_client_callback          deregister_client_cb;
    research_service_callback           research_service_cb; //2014/11/09
    connection_ext_callback             connection_ext_cb; //add for external parameter, 20150110
}gattc_callback_struct;

/****************************************************************************
* function define
****************************************************************************/
void srv_gattc_init(void);
void srv_gattc_register(bt_uuid_struct *app_uuid, gattc_callback_struct *callback);
void srv_gattc_deregister(void *reg_ctx);
void srv_gattc_scan(void *reg_ctx, BOOL start);
void srv_gattc_connect(void *reg_ctx, BD_ADDR *bd_addr, BOOL direct);
void srv_gattc_disconnect(gatt_conn_struct *conn, BD_ADDR *bd_addr);
void srv_gattc_listen(void *reg_ctx, BOOL start);
void srv_gattc_set_adv_data(void *reg_ctx, BOOL set_scan_rsp, BOOL include_name, BOOL include_txpower, 
                                U16 min_interval, U16 max_interval, U16 appearance,
                                U16 manufacturer_len, char *manufacturer_data,
                                U16 service_data_len, char *service_data,
                                U16 service_uuid_len, char *service_uuid);
void srv_gattc_refresh(void *reg_ctx, BD_ADDR *bd_addr);
void srv_gattc_search_service(gatt_conn_struct *conn, bt_uuid_struct *filter_uuid);
void srv_gattc_get_included_service(gatt_conn_struct *conn, GATT_SVC_UUID *svc_uuid, 
                                GATT_SVC_UUID *start_incl_svc_uuid);
void srv_gattc_get_characteristic(gatt_conn_struct *conn, GATT_SVC_UUID *svc_uuid, ATT_UUID *start_char_uuid);
void srv_gattc_get_descriptor(gatt_conn_struct *conn, gattc_char_struct *char_info, ATT_UUID *start_descr_uuid);
void srv_gattc_read_characteristic(gatt_conn_struct *conn, gattc_char_struct *char_info, GATTC_AUTH_REQ auth_req);
void srv_gattc_write_characteristic(gatt_conn_struct *conn, gattc_char_struct *char_info, 
                                ATT_VALUE *value, GATTC_WRITE_TYPE write_type, GATTC_AUTH_REQ auth_req);
void srv_gattc_read_descriptor(gatt_conn_struct *conn, gattc_descr_struct *descr_info, GATTC_AUTH_REQ auth_req);
void srv_gattc_write_descriptor(gatt_conn_struct *conn, gattc_descr_struct *descr_info, 
                                ATT_VALUE *value, GATTC_WRITE_TYPE write_type, GATTC_AUTH_REQ auth_req);
void srv_gattc_execute_write(gatt_conn_struct *conn, U8 exeute);
void srv_gattc_register_for_notification(void *reg_ctx, BD_ADDR *bd_addr, gattc_char_struct *char_info);
void srv_gattc_deregister_for_notification(void *reg_ctx, BD_ADDR *bd_addr, gattc_char_struct *char_info);
void srv_gattc_read_remote_rssi(void *reg_ctx, BD_ADDR *bd_addr);
void srv_gattc_get_device_type(void *reg_ctx, BD_ADDR *bd_addr);

/*for low power begain*/
#ifdef __MMI_BLE_LOW_POWER__
/*****************************************************************************
 * FUNCTION
 *  srv_gattc_set_adv_interval_cnf
 * DESCRIPTION
 *  This function is to handle adv interval setting confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gattc_set_adv_interval_cnf(void *msg);

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_set_adv_interval
 * DESCRIPTION
 *  send advertise interval to client
 * PARAMETERS
 *  profile_id              [IN]  please see gattprofilesrvdeclaration.c, and pass your Profile ID   
 *  adv_interval          [IN]   adv interval pattern    
 *            
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gattc_set_adv_interval(U32 profile_id, gattc_adv_interval_enum adv_interval);

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_conn_param_update_cnf
 * DESCRIPTION
 *  This function is to handle conn interval update confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gattc_conn_param_update_cnf(void *msg);

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_conn_param_update
 * DESCRIPTION
 *  send connection interval to client
 * PARAMETERS
 *  profile_id              [IN]  please see gattprofilesrvdeclaration.c    
 *  bd_addr              [IN]   remote device's address           
 *  connectionPriority   [IN]  if need high transfer speed, please pass CONNECTION_PRIORITY_HIGH_SPEED; 
 *              if need Low power, please pass CONNECTION_PRIORITY_LOW_POWER;default:CONNECTION_PRIORITY_LOW_POWER
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gattc_conn_param_update(U32 profile_id, char *bd_addr, CONN_PRIO_ENUM connectionPriority);


void srv_gatt_set_adv_param_req(U16 min_interval, U16 max_interval);
void srv_gatt_conn_param_update_req(char *bd_addr, U16 min_interval, U16 max_interval, U16 timeout, U16 latency);

#endif /*__MMI_BLE_LOW_POWER__*/
/*for low power end*/

#endif
