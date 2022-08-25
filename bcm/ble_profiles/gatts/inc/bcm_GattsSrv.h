#ifndef __GATTS_SRV_H__
#define __GATTS_SRV_H__

#include "bt_types.h"
#include "btostypes.h"
#include "bluetooth_gatts_struct.h"
#include "bcm_GattSrv.h"

/****************************************************************************
* data define
****************************************************************************/
/** BT-GATT Server callback structure. */

/** Callback invoked in response to register */
typedef void (*register_server_callback)(void *reg_ctx, OS_STATUS status, bt_uuid_struct *app_uuid);

/** Callback invoked in response to deregister */
typedef void (*deregister_server_callback)(void *reg_ctx, OS_STATUS status);

/** Callback indicating that a remote device has connected or been disconnected */
typedef void (*connection_callback)(gatt_conn_struct *conn, BOOL connected, BD_ADDR *bd_addr);

/** Callback indicating that a remote device has connected or been disconnected */
typedef void (*connection_ext_callback)(gattsrv_conn_struct *conn);

/** Callback triggered in response to listen */
typedef void (*listen_callback)(void *reg_ctx, OS_STATUS status);

/** Callback invoked in response to create_service */
typedef void (*service_added_callback)(OS_STATUS status, void *reg_ctx,
                GATT_SVC_UUID *srvc_id, ATT_HANDLE srvc_handle);

/** Callback indicating that an included service has been added to a service */
typedef void (*included_service_added_callback)(OS_STATUS status, void *reg_ctx,
                ATT_HANDLE srvc_handle, ATT_HANDLE incl_srvc_handle);

/** Callback invoked when a characteristic has been added to a service */
typedef void (*characteristic_added_callback)(OS_STATUS status, void *reg_ctx,
                ATT_UUID *uuid, ATT_HANDLE srvc_handle, ATT_HANDLE char_handle);

/** Callback invoked when a descriptor has been added to a characteristic */
typedef void (*descriptor_added_callback)(OS_STATUS status, void *reg_ctx,
                ATT_UUID *uuid, ATT_HANDLE srvc_handle, ATT_HANDLE descr_handle);

/** Callback invoked in response to start_service */
typedef void (*service_started_callback)(OS_STATUS status, void *reg_ctx,
                                         ATT_HANDLE srvc_handle);

/** Callback invoked in response to stop_service */
typedef void (*service_stopped_callback)(OS_STATUS status, void *reg_ctx,
                                         ATT_HANDLE srvc_handle);

/** Callback triggered when a service has been deleted */
typedef void (*service_deleted_callback)(OS_STATUS status, void *reg_ctx,
                                         ATT_HANDLE srvc_handle);

/**
 * Callback invoked when a remote device has requested to read a characteristic
 * or descriptor. The application must respond by calling send_response
 */
typedef void (*request_read_callback)(gatt_conn_struct *conn, U16 trans_id, BD_ADDR *bd_addr,
                                      ATT_HANDLE attr_handle, U16 offset, BOOL is_long);

/**
 * Callback invoked when a remote device has requested to write to a
 * characteristic or descriptor.
 */
typedef void (*request_write_callback)(gatt_conn_struct *conn, U16 trans_id, BD_ADDR *bd_addr,
                                       ATT_HANDLE attr_handle, ATT_VALUE *value, U16 offset,
                                       BOOL need_rsp, BOOL is_prep);

/** Callback invoked when a previously prepared write is to be executed */
typedef void (*request_exec_write_callback)(gatt_conn_struct *conn, U16 trans_id,
                                            BD_ADDR *bd_addr, BOOL cancel);

/**
 * Callback triggered in response to send_response if the remote device
 * sends a confirmation.
 */
typedef void (*response_confirmation_callback)(gatt_conn_struct *conn, OS_STATUS status, U8 need_confirm, ATT_HANDLE handle);

/** Callback triggered in response to read_tx_power */
typedef void (*read_tx_power_callback)(void *reg_ctx, OS_STATUS status, BD_ADDR *bd_addr, U8 tx_power);

typedef struct
{
    register_server_callback        register_server_cb;
    connection_callback             connection_cb;
    listen_callback                 listen_cb;    
    service_added_callback          service_added_cb;
    included_service_added_callback included_service_added_cb;
    characteristic_added_callback   characteristic_added_cb;
    descriptor_added_callback       descriptor_added_cb;
    service_started_callback        service_started_cb;
    service_stopped_callback        service_stopped_cb;
    service_deleted_callback        service_deleted_cb;
    request_read_callback           request_read_cb;
    request_write_callback          request_write_cb;
    request_exec_write_callback     request_exec_write_cb;
    response_confirmation_callback  response_confirmation_cb;
    read_tx_power_callback          read_tx_power_cb;
    deregister_server_callback      deregister_server_cb;
    connection_ext_callback         connection_ext_cb; //add for external parameter, 20150110
    response_confirmation_callback  indication_cb;
}gatts_callback_struct;

/****************************************************************************
* function define
****************************************************************************/
void srv_gatts_init(void);
void srv_gatts_register(bt_uuid_struct *uuid, gatts_callback_struct *callback);
void srv_gatts_deregister(void *reg_ctx);
void srv_gatts_connect(void *reg_ctx, BD_ADDR *bd_addr, BOOL direct);
void srv_gatts_disconnect(gatt_conn_struct *conn, BD_ADDR *bd_addr);
void srv_gatts_listen(void *reg_ctx, BOOL start);
void srv_gatts_set_adv_data(void *reg_ctx, BOOL set_scan_rsp, BOOL include_name, BOOL include_txpower, 
                                U16 min_interval, U16 max_interval, U16 appearance,
                                U16 manufacturer_len, char *manufacturer_data,
                                U16 service_data_len, char *service_data,
                                U16 service_uuid_len, char *service_uuid);
void srv_gatts_add_service(void *reg_ctx, GATT_SVC_UUID *srvc_id, U16 num_handles);
void srv_gatts_add_included_service(void *reg_ctx, ATT_HANDLE service_handle, ATT_HANDLE included_handle);
void srv_gatts_add_characteristic(void *reg_ctx, 
                                  ATT_HANDLE service_handle, ATT_UUID *uuid,
                                  GATT_CHAR_PROPERTIES properties, GATT_PERMISSION permission);
void srv_gatts_add_descriptor(void *reg_ctx, ATT_HANDLE service_handle,
                              ATT_UUID *uuid, GATT_PERMISSION permission);
void srv_gatts_start_service(void *reg_ctx, ATT_HANDLE service_handle,
                             GATT_TRANSPORT transport);
void srv_gatts_stop_service(void *reg_ctx, ATT_HANDLE service_handle);
void srv_gatts_delete_service(void *reg_ctx, ATT_HANDLE service_handle);
void srv_gatts_send_indication(gatt_conn_struct *conn, ATT_HANDLE attribute_handle,
                               BOOL need_confirm, ATT_VALUE *value);
void srv_gatts_send_response(gatt_conn_struct *conn, U16 trans_id,
                             U8 status, ATT_HANDLE handle, ATT_VALUE *value);
void srv_gatts_read_tx_power(void *reg_ctx, BD_ADDR *bd_addr);

void srv_gatts_read_random_addr(void);


#endif
