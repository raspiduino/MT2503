#ifndef __GATT_SERVER_FACTORY_SRV_H__
#define __GATT_SERVER_FACTORY_SRV_H__

#include "bcm_GattSrv.h"
#include "bcm_GattsSrv.h"
#include "bcmadp.h"

#define __GATT_SRV_MEM_USE_ADM__ //use ADM buffer

#define SRV_STORE_IN_XML_FILE   KAL_FALSE

/****************************************************************************
* data define
****************************************************************************/
// callback function for srv_gatts_profile_factory_get_services
typedef void (*factory_srvs_got_callback)(OS_STATUS status, void* reg_ctx);

// callback function for srv_gatts_profile_factory_clear_services
typedef void (*factory_srvs_cleared_callback)(OS_STATUS status, void* reg_ctx);

// callback function for srv_gatts_profile_factory_add_services
typedef void (*factory_srvs_added_callback)(OS_STATUS status, void* reg_ctx);

// callback function for srv_gatts_profile_factory_delete_services
typedef void (*factory_srvs_deleted_callback)(OS_STATUS status, void* reg_ctx);


//Enum for profile and profile id.
typedef enum
{
    PROFILE_ID_FINDME = 0,
    PROFILE_ID_PXP = 1,
    PROFILE_ID_TIME = 2,
    PROFILE_ID_ANP = 3,
    PROFILE_ID_PAS = 4,
    PROFILE_ID_SOGP = 5,
    /*add for Pedometer begain*/ 
    PROFILE_ID_PEDOMETER = 6,
    /*add for Pedometer end*/ 
	/*add for Pedometer begain*/ 
    PROFILE_ID_BAS = 7,
    /*add for Pedometer end*/
} gatt_profile_id_enum;

//Enum for the states of processing addservice request
typedef enum
{
    FACTORY_STS_IDLE = (0),
    FACTORY_STS_PROCESSING,
    FACTORY_STS_PENDING,
    FACTORY_STS_SRVS_GOT,
} gatts_factory_state_enum;

typedef struct
{
    ListEntry   filelist;
    BOOL        bInitialized;
} gatts_file_lst_struct;


typedef enum
{
    TYPE_UNKNOW = (0),
    TYPE_SERVICE,
    TYPE_CHARACTERISTIC,
    TYPE_DESCRIPTOR,
    TYPE_INCLUDE_SRV,
} decl_type_enum;

typedef enum
{
    FACTORY_SRVS_OPER_STATE_IDLE = (0),
    FACTORY_SRVS_OPER_STATE_ADDING,
    FACTORY_SRVS_OPER_STATE_DELETING,
} factory_srvs_oper_state_enum;

typedef struct
{
    ListEntry               declnode;
    decl_type_enum          type;
    ATT_UUID                uuid;
    ATT_HANDLE              handle;
    ATT_HANDLE              srvhandle;
    ATT_HANDLE              charhandle;
    U8                      isprimary;
    GATT_CHAR_PROPERTIES    prop;
    GATT_PERMISSION         permission;
    U16                     handlenum;
}gatts_service_decl_struct;


typedef struct
{
    decl_type_enum          type;
    U8*                     uuid;
    U8                      isprimary;
    GATT_CHAR_PROPERTIES    prop;
    GATT_PERMISSION         permission;
}gatts_profile_srv_decl_struct;

typedef struct
{
#ifdef MMI_SRV_CHECK_SERVICE_UUID
    S32                             id;
#else
    gatt_profile_id_enum            id;
#endif
    gatts_profile_srv_decl_struct*  profile_decl;
    U32                             decl_num;
} gatt_profile_decl_tbl;


typedef U32 factory_xml_parser_state;
#define FACTORY_STATE_XML_IDLE                  0x00001
#define FACTORY_STATE_XML_PARSE_DEP_FILE        0x00002
#define FACTORY_STATE_PARSE_SERVICE             0x00004
#define FACTORY_STATE_PARSE_CHAR                0x00008
#define FACTORY_STATE_PARSE_PROP                0x00010
#define FACTORY_STATE_PARSE_PERMISSION          0x00020
#define FACTORY_STATE_PARSE_DES                 0x00040




typedef struct
{
    gatts_service_decl_struct*   srvnode;
    factory_srvs_oper_state_enum    state;
    ATT_HANDLE              lastchhdl;
} GATTS_FACTORY_SRVS_OPER;



/* Structure used to store GATT profile services.
 * This structure should be vaild after receiving factory_srvs_got_cb with success state.
*/
typedef struct
{
    ListEntry   srvlist;
    BOOL        bInitialized;
} gatts_srvs_lst_struct;

//Gatts profile factory callback.
typedef struct
{ 
    factory_srvs_got_callback       factory_srvs_got_cb;
    factory_srvs_cleared_callback   factory_srvs_cleared_cb;
    factory_srvs_added_callback     factory_srvs_added_cb;
    factory_srvs_deleted_callback   factory_srvs_deleted_cb;
}gatts_factory_callback_struct;



typedef struct
{
    ListEntry                       node;
    void*                           reg_ctx;// Ctx alloced by gatts.
    bt_uuid_struct*                 apid;   // id from user layer
    gatts_callback_struct           gatts_cb;   // callback for gatts to user
    gatts_factory_callback_struct*  factory_cb; // callback for factory to user 
    register_server_callback        user_reg_cb;// callback for factory to user after calling srv_gatts_profile_factory_register
    deregister_server_callback      user_dereg_cb;// callback for factory to user after calling srv_gatts_profile_factory_register
    gatts_srvs_lst_struct*          services;
    gatts_factory_state_enum        status;
#ifdef MMI_SRV_CHECK_SERVICE_UUID
    S32                             profile_id;
#else
    gatt_profile_id_enum            profile_id;
#endif
    ListEntry*                      fileslst;  // profile dep services xml files list.
    GATTS_FACTORY_SRVS_OPER         srvsoper;
} factory_user_struct;

typedef struct
{
    factory_user_struct*            user;   // The user which is processing currently.
    factory_xml_parser_state        state;
} facory_xml_parser_struct;


typedef struct
{
    ListEntry   userList;
    BOOL        bInitialized;
    facory_xml_parser_struct    parser;
} srvs_factory_ctx_struct;

/****************************************************************************
* function define
****************************************************************************/

void srv_gatts_profile_factory_init();
void srv_gatts_profile_factory_deinit();


//Register gatts profile callback. Callback functions about add-services will be replaced by this register function.
void srv_gatts_profile_factory_register(bt_uuid_struct* uuid, gatts_callback_struct* gatts_cb, 
                                                                    gatts_factory_callback_struct* factory_cb);
//Deregister a server application from the stack.
void srv_gatts_profile_factory_deregister(void* reg_ctx);

//Get gatts profile services by profile id. gatts_services_struct fill be filled without handle.
#ifdef MMI_SRV_CHECK_SERVICE_UUID
OS_STATUS srv_gatts_profile_factory_get_services(void* reg_ctx, S32 id, gatts_srvs_lst_struct* services);
#else
OS_STATUS srv_gatts_profile_factory_get_services(void* reg_ctx, gatt_profile_id_enum id, gatts_srvs_lst_struct* services);
#endif

//Clear used resource in profile factory. If this function is called, the parameter service structure will be set to empty.
void srv_gatts_profile_factory_clear_services(void* reg_ctx, gatts_srvs_lst_struct* services);

//Add gatts profile services  to gatt stack.
void srv_gatts_profile_factory_add_services(void* reg_ctx, gatts_srvs_lst_struct* services);

//Delete gatts profile services from gatt stack.
void srv_gatts_profile_factory_delete_services(void* reg_ctx, gatts_srvs_lst_struct* services);

//Crete service declare list before add service
S32 srv_gatts_profile_factory_create_srv_list(gatts_profile_srv_decl_struct *srv_list, U32 decl_num);

//Delete service from profile table
OS_STATUS srv_gatts_profile_factory_delete_srv_list(S32 profile_id);


#endif // __GATT_SERVER_FACTORY_SRV_H__
