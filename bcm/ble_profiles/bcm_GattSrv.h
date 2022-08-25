#ifndef __GATT_SRV_H__
#define __GATT_SRV_H__

#include "bt_mmi.h"
#include "custom_bcm_btcm_config.h"

typedef U32 GATT_CHAR_PROPERTIES;
#define GATT_CHAR_PROP_BROADCAST         0x01
#define GATT_CHAR_PROP_READ              0x02
#define GATT_CHAR_PROP_WRITE_WO_RESPONSE 0x04
#define GATT_CHAR_PROP_WRITE             0x08
#define GATT_CHAR_PROP_NOTIFY            0x10
#define GATT_CHAR_PROP_INDICATE          0x20
#define GATT_CHAR_PROP_SIGNED_WRITE      0x40
#define GATT_EXT_PROP                    0x80

typedef U32 GATT_PERMISSION;
#define GATT_PERM_READ                   (1 << 0) /* bit 0 */
#define GATT_PERM_READ_ENCRYPTED         (1 << 1) /* bit 1 */
#define GATT_PERM_READ_ENC_MITM          (1 << 2) /* bit 2 */
#define GATT_PERM_WRITE                  (1 << 4) /* bit 4 */
#define GATT_PERM_WRITE_ENCRYPTED        (1 << 5) /* bit 5 */
#define GATT_PERM_WRITE_ENC_MITM         (1 << 6) /* bit 6 */
#define GATT_PERM_WRITE_SIGNED           (1 << 7) /* bit 7 */
#define GATT_PERM_WRITE_SIGNED_MITM      (1 << 8) /* bit 8 */

typedef U8 GATT_TRANSPORT;
#define GATT_TRANSPORT_LE                0x00
#define GATT_TRANSPORT_BR_EDR            0x01
#define GATT_TRANSPORT_LE_BR_EDR         0x02

typedef U8 GATT_ERROR_RESPONSE;
#define GATT_ERROR_INVALID_HANDLE                   0x01  //The attribute handle given was not valid on this server
#define GATT_ERROR_READ_NOT_PERMITTED     		    0x02  //The attribute cannot be read
#define GATT_ERROR_WRITE_NOT_PERMITTED    		    0x03  //The attribute cannot be write
#define GATT_ERROR_INVALID_PDU            		    0x04  //The attribute pdu was invalid
#define GATT_ERROR_INSUFFICIENT_AUTHENTICATION      0x05  //The attribute requires authentication before it can be read or writen
#define GATT_ERROR_REQUEST_NOT_SUPPORT    		    0x06  //The attribute server does not support the request received from the client
#define GATT_ERROR_INVALID_OFFSET         		    0x07  //Offset specified was past the end of the attribute
#define GATT_ERROR_INSUFFICIENT_AUTHORIZATION	    0x08  //The attribute requires authorization before it can be read or written
#define GATT_ERROR_PREPARE_QUEUE_FULL     		    0x09  //Too many prepare writes have been queued
#define GATT_ERROR_ATTRIBUTE_NOT_FOUND    		    0x0A  //No attribute found within the given attribute handle range
#define GATT_ERROR_ATTRIBUTE_NOT_LONG     		    0x0B  //The attribute cannot be read or written using the read blob request
#define GATT_ERROR_INSUFFICIENT_ENCRYP_KEY_SIZE     0x0C  //the encrption key size used for encrypting this link is insufficient
#define GATT_ERROR_INVALID_ATTRIBUTE_VALUE_LENGTH   0x0D  //The attribute value length is invalid for the operation.
#define GATT_ERROR_UNLIKELY_ERROR                   0x0E  //The attribute request that was requested has encountered an error that was unlikely, 
                                                          //and therefore could not be completed as requested.
#define GATT_ERROR_INSUFFICIENT_ENCRYPTION          0x0F  //The attribute requires encryption before it can be read or written
#define GATT_ERROR_UNSUPPORTED_GROUP_TYPE           0x10  //the attribute type is not a supported grouping attribute as defined by a higher layer specification
#define GATT_ERROR_INSUFFICIENT_RESOURCES           0x11  //Insufficient resources to complete the request.

typedef struct 
{
   U8 uu[16];
}bt_uuid_struct;

typedef struct
{
    void *reg_ctx;
    void *conn_ctx;
}gatt_conn_struct;

typedef struct
{
    gatt_conn_struct *conn;
    BD_ADDR *bd_addr;
    BOOL connected;
    BOOL is_ind;
} gattsrv_conn_struct;

#ifdef MMI_SRV_CONN_STATE_IND

#define MAX_LE_DEV_NUM      4
#define INVALID_DEVICE_NUM  0xFF

//Role
#define BCR_MASTER          0x00 //Master role
#define BCR_SLAVE           0x01 //Slave role

//disconnect reason
#define DISC_REASON_LOCAL_TERMINATED    0x16 /* Terminated by local host */
#define DISC_REASON_LMP_RESPONSE_TIMEOUT    0x22 /* LMP Response Timeout */
#define DISC_BY_LOCAL_HOST(result) ((result == DISC_REASON_LOCAL_TERMINATED) || (result == DISC_REASON_LMP_RESPONSE_TIMEOUT))

enum
{
    GET_DEVICE_NONE = 0x00,
    GET_DEVICE_EXIST,
    GET_DEVICE_VALID,
};

typedef struct
{
    BOOL is_conn;   //TRUE:connect or FALSE:disconnect
    BOOL is_ind;    //TRUE:passive or FALSE:initial
    BD_ADDR dev_addr; //device address
    U8 result;      //TRUE:sucessful or FALSE:unsucessful
    U8 LastInd;     //TRUE:the last disconnect ind
    U8 reason;
}gatt_conn_state;

typedef struct
{
    BD_ADDR dev_addr; //device address
    BOOL is_ind_cm_conn; //is indicate cm connect state ?
    BOOL is_ind_cm_disconn; //is indicate cm disconnect state ?
    BOOL is_update_name; //is update device name to cm ?
}gatt_conn_state_ind_struct;
#endif

/****************************************************************************
* function define
****************************************************************************/
#define gatt_send_msg_to_bt(msg_id, local_param_ptr) \
    gatt_send_msg(MOD_MMI, MOD_BT, BT_APP_SAP, (msg_id), (local_param_ptr))

void gatt_send_msg(module_type src_id, module_type dst_id, U16 sap_id, U16 msg_id, void *local_param_ptr);

U16 convert_array_to_uuid16(ATT_UUID uu);

void convert_uuid16_to_array(U16 uuid16, ATT_UUID *uu);

/*---------------------------------------------------------------------------
 *
 * ListEntry is for creating doubly linked circular lists. They can be used as
 * either a list head, or as part of another structure to allow that
 * structure to be a link node.
 */
#ifndef LISTS_DEFINED
#define LISTS_DEFINED

typedef struct _ListEntry
{
    struct _ListEntry *Flink;
    struct _ListEntry *Blink;

} ListEntry;
#endif /* LISTS_DEFINED */

//#include "kal_public_api.h"

extern void kal_assert_fail_native(char* expr, char* file, kal_uint32 line);


#define Assert(exp)  (((exp) != 0) ? (void)0 : kal_assert_fail_native(#exp, __FILE__, __LINE__))
#define AssertEval(exp) (((exp) != 0) ? (void)0 : kal_assert_fail_native(#exp, __FILE__, __LINE__))


extern void mmi_InitializeListHead(ListEntry *list);

extern void mmi_InitializeListEntry(ListEntry *list);

#define mmi_IsEntryAvailable(Entry) (\
                                 ((Entry)->Flink == 0))

extern U8 mmi_IsListEmpty(ListEntry *list);

#define mmi_GetHeadList(ListHead) (ListHead)->Flink

#define mmi_GetTailList(ListHead) (ListHead)->Blink

#define mmi_GetNextNode(Node)     (Node)->Flink

#define mmi_GetPrevNode(Node)     (Node)->Blink

#define mmi_IsNodeConnected(n) (((n)->Blink->Flink == (n)) && ((n)->Flink->Blink == (n)))

void _mmi_InsertTailList(ListEntry *head, ListEntry *entry);
extern void mmi_InsertTailList(ListEntry *head, ListEntry *entry);

void _mmi_InsertHeadList(ListEntry *head, ListEntry *entry);

#define mmi_InsertHeadList(a, b) (Assert(mmi_IsListCircular(a)), \
                              _mmi_InsertHeadList(a, b),       \
                              Assert(mmi_IsListCircular(a)))

ListEntry *_mmi_RemoveHeadList(ListEntry *head);
extern ListEntry *mmi_RemoveHeadList(ListEntry *head);

void mmi_RemoveEntryList(ListEntry *entry);
BOOL mmi_IsNodeOnList(ListEntry *head, ListEntry *node);
BOOL mmi_IsListCircular(ListEntry *list);
void mmi_MoveList(ListEntry *dest, ListEntry *src);
void mmi_InsertList(ListEntry *dest, ListEntry *src, U8 front);
#ifdef MMI_SRV_CONN_STATE_IND
void gatt_conn_state_handle(gatt_conn_state msg);
void gatt_update_remote_device_name(U8 *dev_name, BD_ADDR *dev_addr);
void gatt_conn_clear_state(BD_ADDR *bd_addr);
#endif

#endif

