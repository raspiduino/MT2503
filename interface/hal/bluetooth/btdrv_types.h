/*******************************************************************************
 * 
 * Filename:
 * ---------
 *	btdrv_types.h
 *
 * Project:
 * --------
 *   MAUI MTK Bluetooth Chip
 *
 * Description:
 * ------------
 *   This file contains data types whtich are both used in BT driver and BT stack
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef BTDRV_TYPES_H
#define BTDRV_TYPES_H

#include "kal_public_api.h"
#include "btdrv_config.h"
#include "xatypes.h"
#include "xastatus.h"
#include "bt_feature.h"
extern void kal_assert_fail_native(char* expr, char* file, kal_uint32 line);
extern void BtRadio_Restart_Req(void);


//Osapi.h
/*****************************************************************/
/*****************************************************************/
/*****************************************************************/

#ifndef __BT_SHRINK_SIZE__ 
#if defined(DEBUG_KAL)
#define Assert(exp) (((exp) != 0) ? (void)0 : (void)kal_assert_fail_native(#exp, __FILE__, __LINE__))
#else 
#define Assert(exp)  (((exp) != 0) ? (void)0 : (void)BtRadio_Restart_Req())
#endif 
#define AssertEval(exp) Assert(exp)

#else /* __BT_SHRINK_SIZE__ */

#define Assert(exp) (((exp) != 0) ? (void)0 : (void)BtRadio_Restart_Req()) //(void)0 : (void)MTK_BT_Assert())
#define AssertEval(exp) Assert(exp)

#endif /* __BT_SHRINK_SIZE__ */

/*---------------------------------------------------------------------------
 * TimeT type
 *
 *     Indicates an amount of time in system ticks or milliseconds. This must
 *     be a 32-bit value because some timeouts may exceed 5 minutes.
 */
typedef U32 TimeT;


//utils.h
/*****************************************************************/
/*****************************************************************/
/*****************************************************************/


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


#define IsEntryAvailable(Entry) (\
    ((Entry)->Flink == 0))    


//bttypes.h
/*****************************************************************/
/*****************************************************************/
/*****************************************************************/
/*---------------------------------------------------------------------------
 * BtStatus type
 *
 *     This type is returned from most stack APIs to indicate the success
 *     or failure of the operation. In many cases, BT_STATUS_PENDING
 *     is returned, meaning that a future callback will indicate the
 *     result of the operation.
 */
typedef XaStatus BtStatus;

#define BT_STATUS_SUCCESS           XA_STATUS_SUCCESS
#define BT_STATUS_FAILED            XA_STATUS_FAILED
#define BT_STATUS_PENDING           XA_STATUS_PENDING
#define BT_STATUS_BUSY              XA_STATUS_BUSY
#define BT_STATUS_NO_RESOURCES      XA_STATUS_NO_RESOURCES
#define BT_STATUS_NOT_FOUND         XA_STATUS_NOT_FOUND
#define BT_STATUS_DEVICE_NOT_FOUND  XA_STATUS_DEVICE_NOT_FOUND
#define BT_STATUS_CONNECTION_FAILED XA_STATUS_CONNECTION_FAILED
#define BT_STATUS_TIMEOUT           XA_STATUS_TIMEOUT
#define BT_STATUS_NO_CONNECTION     XA_STATUS_NO_CONNECTION
#define BT_STATUS_INVALID_PARM      XA_STATUS_INVALID_PARM
#define BT_STATUS_IN_PROGRESS       XA_STATUS_IN_PROGRESS
#define BT_STATUS_RESTRICTED        XA_STATUS_RESTRICTED
#define BT_STATUS_INVALID_TYPE      XA_STATUS_INVALID_TYPE
#define BT_STATUS_HCI_INIT_ERR      XA_STATUS_HCI_INIT_ERR
#define BT_STATUS_NOT_SUPPORTED     XA_STATUS_NOT_SUPPORTED
#define BT_STATUS_IN_USE            XA_STATUS_IN_USE
#define BT_STATUS_SDP_CONT_STATE    XA_STATUS_CONTINUE
#define BT_STATUS_CANCELLED         XA_STATUS_CANCELLED
#define BT_STATUS_NOSERVICES        XA_STATUS_NOSERVICES
#define BT_STATUS_SCO_REJECT        MTK_STATUS_SCO_REJECT
#define BT_STATUS_CHIP_REASON       MTK_STATUS_CHIP_REASON
#define BT_STATUS_BLOCK_LIST        MTK_STAUTS_BLOCK_LIST
#define BT_STATUS_SCATTERNET_REJECT MTK_STATUS_SCATTERNET_REJECT
/* End of BtStatus */

/*---------------------------------------------------------------------------
 * BtPacket structure
 *
 *     Represents a packet of data. These packets may be used by applications
 *     to provide data to the stack. Certain stack events may also provide
 *     data to the application enclosed in a BtPacket structure.
 */
typedef struct _BtPacket
{
        ListEntry node; /* Used internally by the stack. */
    
        U8 *data;       /* Points to a buffer of user data.  */
        U16 dataLen;    /* Indicates the length of "data" in bytes. */
    
        U8 flags;   /*
                     * Must be initialized to BTP_FLAG_NONE by
                     * applications running on top of L2CAP. Other
                     * higher layer protocols must never modify this
                     * value.
                     */
        U8 priority_type;
#if defined (__BT_2_1_AUTO_FLUSH__)
        U8 timebound;
#endif
    
        /* Group: The following fields are for internal use only by the stack. */
        void *ulpContext;
        U8 *tail;
        U16 tailLen;
    
#if XA_STATISTICS == XA_ENABLED
        U32 rfc_timer;
        U32 hci_timer;
        U32 l2cap_timer;
#endif /* XA_STATISTICS == XA_ENABLED */
    
        U16 llpContext;
        U16 remoteCid;
    
#if L2CAP_FLOW_NON_BASIC_MODE == XA_ENABLED
        U16 segStart;
        U16 segNum;
        U8 fcs[2];
        U16 internalUsed; /* For streamming mode, used to record the txSeq*/
        U8 pollFinal;
#endif /* L2CAP_FLOW_NON_BASIC_MODE == XA_ENABLED */
    
        U8 hciPackets;
        U8 headerLen;
        U8 header[BT_PACKET_HEADER_LEN];

} BtPacket;



//hci.h
/*****************************************************************/
/*****************************************************************/
/*****************************************************************/


/*
 * An event was received from the host controller. Events occur in response
 * to commands sent by the host, although several events can be received
 * for a single command.
 *
 * The "hciEvent" callback parameter contains the data associated with the
 * command. The "status" field will always indicate success, and the
 * "hciHandle" field is not used.
 */
#define HCI_CONTROLLER_EVENT 1

/*
 * Either SCO or ACL data was received from another device. This data can
 * be found in the "rxBuff" field. The type of data (ACL or SCO)
 * is identified in the rxBuff->flags field. The "hciHandle" field will also
 * be set with the ACL or SCO connection handle. The "status" field will
 * always indicate success.
 */
#define HCI_DATA_IND         2

/*
 * A transmitted ACL or SCO packet is free to be re-used by
 * higher layers. The returned packet is identified in the "packet" field,
 * and the "hciHandle" field indicates the connection on which the packet
 * was sent.
 *
 * If the "status" field indicates success, the packet was successfully sent
 * to the host controller, but the remote device might not have received
 * the data yet.
 *
 * If the "status" field indicates failure, the packet was not sent
 * successfully due to link disconnection or a transport error.
 */
#define HCI_PACKET_HANDLED   3

/*
 * A transmitted command is free to be re-used by higher layers.
 * The returned command is identified in the "cmd" field. The
 * "hciHandle" field is not used.
 *
 * If the "status" field indicates success, the command was successfully
 * transmitted to the host controller. One or more events will follow
 * in response.
 *
 * If the "status" field indicates failure, the command could not be
 * sent due to a transport error.
 */
#define HCI_COMMAND_HANDLED  4



//hcitrans.h
/*****************************************************************/
/*****************************************************************/
/*****************************************************************/


/** The radio module has completed initialization.  If initialization was 
 * successful, then the "Status" parameter of the callback function should
 * be set to BT_STATUS_SUCCESS.  If the initialization failed, then the
 * "Status" parameter should be set to BT_STATUS_FAILED.
 */
#define RADIO_INIT_STATUS    1


//host.h
/*****************************************************************/
/*****************************************************************/
/*****************************************************************/

/* HCI States */
#define HCI_STATE_SHUTDOWN        0
#define HCI_STATE_INIT            1
#define HCI_STATE_DEINIT          2
#define HCI_STATE_READY           4



//hci.h
/*****************************************************************/
/*****************************************************************/
/*****************************************************************/


/*---------------------------------------------------------------------------
 * HciCommandType type
 *
 *     Commands are indicated to the HCI layer when calling
 *     HCI_SendCommand. A command type from the list below is specified
 *     in the "opCode" parameter to this function. Additional
 *     command-specific information is provided in the "cmd" parameter.
 */
typedef U16 HciCommandType;

typedef enum  
{
    HCC_INQUIRY                      = 0x0401,
    HCC_INQUIRY_CANCEL               = 0x0402,
    HCC_START_PERIODIC_INQ_MODE      = 0x0403,
    HCC_EXIT_PERIODIC_INQ_MODE       = 0x0404,
    HCC_CREATE_CONNECTION            = 0x0405,
    HCC_DISCONNECT                   = 0x0406,
    HCC_ADD_SCO_CONNECTION           = 0x0407, /* Not in 1.2 */
    HCC_CREATE_CONNECTION_CANCEL     = 0x0408, /* 1.2 */
    HCC_ACCEPT_CON_REQ               = 0x0409,
    HCC_REJECT_CON_REQ               = 0x040A,
    HCC_LINK_KEY_REQ_REPL            = 0x040B,
    HCC_LINK_KEY_REQ_NEG_REPL        = 0x040C,
    HCC_PIN_CODE_REQ_REPL            = 0x040D,
    HCC_PIN_CODE_REQ_NEG_REPL        = 0x040E,
    HCC_CHNG_CONN_PACKET_TYPE        = 0x040F,
    HCC_AUTH_REQ                     = 0x0411,
    HCC_SET_CONN_ENCRYPT             = 0x0413,
    HCC_CHNG_CONN_LINK_KEY           = 0x0415,
    HCC_MASTER_LINK_KEY              = 0x0417,
    HCC_REM_NAME_REQ                 = 0x0419,
    HCC_REM_NAME_REQ_CANCEL          = 0x041A, /* 1.2 */
    HCC_READ_REMOTE_FEATURES         = 0x041B,
    HCC_READ_REMOTE_EXT_FEATURES     = 0x041C, /* 1.2 */
    HCC_READ_REMOTE_VERSION          = 0x041D,
    HCC_READ_CLOCK_OFFSET            = 0x041F,
    HCC_READ_LMP_HANDLE              = 0x0420, /* 1.2 */
    HCC_EXCHANGE_FIXED_INFO          = 0x0421, /* 1.2 */
    HCC_EXCHANGE_ALIAS_INFO          = 0x0422, /* 1.2 */
    HCC_PRIVATE_PAIRING_REQ_REPL     = 0x0423, /* 1.2 */
    HCC_PRIVATE_PAIRING_REQ_NEG_REPL = 0x0424, /* 1.2 */
    HCC_GENERATED_ALIAS              = 0x0425, /* 1.2 */
    HCC_ALIAS_ADDRESS_REQ_REPL       = 0x0426, /* 1.2 */
    HCC_ALIAS_ADDRESS_REQ_NEG_REPL   = 0x0427, /* 1.2 */
    HCC_SETUP_SYNC_CONNECTION        = 0x0428, /* 1.2 */
    HCC_ACCEPT_SYNC_CON_REQ          = 0x0429, /* 1.2 */
    HCC_REJECT_SYNC_CON_REQ          = 0x042A, /* 1.2 */
    HCC_IO_CAPABILITY_REPL           = 0x042B, /* 2.1 */
    HCC_USER_CONFIRM_REPL            = 0x042C, /* 2.1 */
    HCC_USER_CONFIRM_NEG_REPL        = 0x042D, /* 2.1 */
                                      
    HCC_IO_CAPABILITY_NEG_REPL       = 0x0434, /* 2.1 */
    
    /* Group: Link policy commands */
    HCC_HOLD_MODE                    = 0x0801,
    HCC_SNIFF_MODE                   = 0x0803,
    HCC_EXIT_SNIFF_MODE              = 0x0804,
    HCC_PARK_MODE                    = 0x0805,
    HCC_EXIT_PARK_MODE               = 0x0806,
    HCC_QOS_SETUP                    = 0x0807,
    HCC_ROLE_DISCOVERY               = 0x0809,
    HCC_SWITCH_ROLE                  = 0x080B,
    HCC_READ_LINK_POLICY             = 0x080C,
    HCC_WRITE_LINK_POLICY            = 0x080D,
    HCC_READ_DEFAULT_LINK_POLICY     = 0x080E, /* 1.2 */
    HCC_WRITE_DEFAULT_LINK_POLICY    = 0x080F, /* 1.2 */
    HCC_FLOW_SPECIFICATION           = 0x0810, /* 1.2 */
    HCC_SNIFF_SUBRATING              = 0x0811, /* 2.1 */
    
    /* Group: Host controller and baseband commands */
    HCC_SET_EVENT_MASK               = 0x0C01,
    HCC_RESET                        = 0x0C03,
    HCC_EVENT_FILTER                 = 0x0C05,
    HCC_FLUSH                        = 0x0C08,
    HCC_READ_PIN_TYPE                = 0x0C09,
    HCC_WRITE_PIN_TYPE               = 0x0C0A,
    HCC_CREATE_NEW_UNIT_KEY          = 0x0C0B,
    HCC_READ_STORED_LINK_KEY         = 0x0C0D,
    HCC_WRITE_STORED_LINK_KEY        = 0x0C11,
    HCC_DEL_STORED_LINK_KEY          = 0x0C12,
    HCC_CHNG_LOCAL_NAME              = 0x0C13,
    HCC_READ_LOCAL_NAME              = 0x0C14,
    HCC_READ_CONN_ACCEPT_TIMEOUT     = 0x0C15,
    HCC_WRITE_CONN_ACCEPT_TIMEOUT    = 0x0C16,
    HCC_READ_PAGE_TIMEOUT            = 0x0C17,
    HCC_WRITE_PAGE_TIMEOUT           = 0x0C18,
    HCC_READ_SCAN_ENABLE             = 0x0C19,
    HCC_WRITE_SCAN_ENABLE            = 0x0C1A,
    HCC_READ_PAGE_SCAN_ACTIVITY      = 0x0C1B,
    HCC_WRITE_PAGE_SCAN_ACTIVITY     = 0x0C1C,
    HCC_READ_INQ_SCAN_ACTIVITY       = 0x0C1D,
    HCC_WRITE_INQ_SCAN_ACTIVITY      = 0x0C1E,
    HCC_READ_AUTH_ENABLE             = 0x0C1F,
    HCC_WRITE_AUTH_ENABLE            = 0x0C20,
    HCC_READ_ENCRYPT_MODE            = 0x0C21,
    HCC_WRITE_ENCRYPT_MODE           = 0x0C22,
    HCC_READ_CLASS_OF_DEVICE         = 0x0C23,
    HCC_WRITE_CLASS_OF_DEVICE        = 0x0C24,
    HCC_READ_VOICE_SETTING           = 0x0C25,
    HCC_WRITE_VOICE_SETTING          = 0x0C26,
    HCC_READ_AUTO_FLUSH_TIMEOUT      = 0x0C27,
    HCC_WRITE_AUTO_FLUSH_TIMEOUT     = 0x0C28,
    HCC_READ_NUM_BC_RETRANSMIT       = 0x0C29,
    HCC_WRITE_NUM_BC_RETRANSMIT      = 0x0C2A,
    HCC_READ_HOLD_MODE_ACTIVITY      = 0x0C2B,
    HCC_WRITE_HOLD_MODE_ACTIVITY     = 0x0C2C,
    HCC_READ_XMIT_POWER_LEVEL        = 0x0C2D,
    HCC_READ_SCO_FC_ENABLE           = 0x0C2E,
    HCC_WRITE_SCO_FC_ENABLE          = 0x0C2F,
    HCC_SET_CTRLR_TO_HOST_FLOW_CTRL  = 0x0C31,
    HCC_HOST_BUFFER_SIZE             = 0x0C33,
    HCC_HOST_NUM_COMPLETED_PACKETS   = 0x0C35,
    HCC_READ_LINK_SUPERV_TIMEOUT     = 0x0C36,
    HCC_WRITE_LINK_SUPERV_TIMEOUT    = 0x0C37,
    HCC_READ_NUM_IAC                 = 0x0C38,
    HCC_READ_CURRENT_IAC_LAP         = 0x0C39,
    HCC_WRITE_CURRENT_IAC_LAP        = 0x0C3A,
    HCC_READ_PAGE_SCAN_PERIOD_MODE   = 0x0C3B,
    HCC_WRITE_PAGE_SCAN_PERIOD_MODE  = 0x0C3C,
    HCC_READ_PAGE_SCAN_MODE          = 0x0C3D, /* Not in 1.2 */
    HCC_WRITE_PAGE_SCAN_MODE         = 0x0C3E, /* Not in 1.2 */
    HCC_SET_AFH_HOST_CHAN_CLASS      = 0x0C3F, /* 1.2 */
    HCC_READ_INQ_SCAN_TYPE           = 0x0C42, /* 1.2 */
    HCC_WRITE_INQ_SCAN_TYPE          = 0x0C43, /* 1.2 */
    HCC_READ_INQ_MODE                = 0x0C44, /* 1.2 */
    HCC_WRITE_INQ_MODE               = 0x0C45, /* 1.2 */
    HCC_READ_PAGE_SCAN_TYPE          = 0x0C46, /* 1.2 */
    HCC_WRITE_PAGE_SCAN_TYPE         = 0x0C47, /* 1.2 */
    HCC_READ_AFH_CHAN_ASSESS_MODE    = 0x0C48, /* 1.2 */
    HCC_WRITE_AFH_CHAN_ASSESS_MODE   = 0x0C49, /* 1.2 */
    HCC_READ_ANONYMITY_MODE          = 0x0C4A, /* 1.2 */
    HCC_WRITE_ANONYMITY_MODE         = 0x0C4B, /* 1.2 */
    HCC_READ_ALIAS_AUTH_ENABLE       = 0x0C4C, /* 1.2 */
    HCC_WRITE_ALIAS_AUTH_ENABLE      = 0x0C4D, /* 1.2 */
    HCC_READ_ANON_ADDR_CHNG_PARM     = 0x0C4E, /* 1.2 */
    HCC_WRITE_ANON_ADDR_CHNG_PARM    = 0x0C4F, /* 1.2 */
    HCC_RESET_FIXED_ADDR_COUNTER     = 0x0C50, /* 1.2 */
    HCC_WRITE_EXT_INQUIRY_RESPONSE   = 0x0C52, /* 2.1 */
    HCC_WRITE_SIMPLE_PAIRING_MODE    = 0x0C56, /* 2.1 */
    
    /* Group: Informational parameters */
    HCC_READ_LOCAL_VERSION           = 0x1001,
    HCC_READ_LOCAL_COMMANDS          = 0x1002, /* 1.2 */
    HCC_READ_LOCAL_FEATURES          = 0x1003,
    HCC_READ_LOCAL_EXT_FEATURES      = 0x1004, /* 1.2 */
    HCC_READ_BUFFER_SIZE             = 0x1005,
    HCC_READ_COUNTRY_CODE            = 0x1007, /* Not in 1.2 */
    HCC_READ_BD_ADDR                 = 0x1009,
    
    /* Group: Status parameters */
    HCC_READ_FAILED_CONTACT_COUNT    = 0x1401,
    HCC_RESET_FAILED_CONTACT_COUNT   = 0x1402,
    HCC_GET_LINK_QUALITY             = 0x1403,
    HCC_READ_RSSI                    = 0x1405,
    HCC_READ_AFH_CHANNEL_MAP         = 0x1406, /* 1.2 */
    HCC_READ_CLOCK                   = 0x1407, /* 1.2 */
    
    /* Group: Testing commands */
    HCC_READ_LOOPBACK_MODE           = 0x1801,
    HCC_WRITE_LOOPBACK_MODE          = 0x1802,
    HCC_ENABLE_DUT                   = 0x1803,
    HCC_WRITE_SSP_DEBUG_MODE         = 0x1804,
    
    /* James 20070522, for peripheral test */
    /* Group: Peripheral test commands */
    HCC_UART_PERIPHERAL_REQ          = 0xFCF0,
    HCC_UART_TEST_REQ                = 0xFCF1,
    HCC_DMA_TEST_REQ                 = 0xFCF2,
    HCC_GPIO_TEST_REQ                = 0xFCF3,
    HCC_WDT_TEST_REQ                 = 0xFCF4,
    HCC_PATCH_TEST_REQ               = 0xFCF5,
    
    HCC_MT66XX_Enabled_FLOW_CONTROL  = 0xFCEF,
    FC1A	                         = 0xFC1A,    
    FC1B	                         = 0xFC1B,
    FC1C	                         = 0xFC1C,
    FC1D	                         = 0xFC1D,    
    FC1E	                         = 0xFC1E,        
    FC56	                         = 0xFC56,
    FC57	                         = 0xFC57,
    FC58	                         = 0xFC58,
    FC59	                         = 0xFC59,
    FC5A	                         = 0xFC5A,
    FC5B	                         = 0xFC5B,
    HCC_SET_PINCODE_RSP_TIMEOUT      = 0xFC66,
    FC71	                         = 0xFC71,
    HCC_DUAL_PCM_SET_VALUE           = 0xFC72,
    FC73	                         = 0xFC73,
    FC74	                         = 0xFC74,    
    FC75	                         = 0xFC75,    
    FC76	                         = 0xFC76,
    FC77	                         = 0xFC77,
    FC78	                         = 0xFC78,
    FC79	                         = 0xFC79,    
    FC7A	                         = 0xFC7A,
    FC7B	                         = 0xFC7B,    
    FC7C	                         = 0xFC7C,    
    FC7D	                         = 0xFC7D,
    FC7E	                         = 0xFC7E,
    FC7F	                         = 0xFC7F,
    HCC_CLEAR_ENCRYPTION_STATE       = 0xFC82,
    HCC_DUAL_PCM_SWITCH              = 0xFC90,
    FCB0	                         = 0xFCB0,
    FCB1	                         = 0xFCB1,
    FCB2	                         = 0xFCB2,
    FCB3	                         = 0xFCB3,    
    FCB4	                         = 0xFCB4,
    FCB5	                         = 0xFCB5,
    FCB6	                         = 0xFCB6,
    FCB7	                         = 0xFCB7,
    FCB8	                         = 0xFCB8,
    FCB9	                         = 0xFCB9,
    FCBA	                         = 0xFCBA,
    FCBB	                         = 0xFCBB,
    FCBC	                         = 0xFCBC,
    FCBD	                         = 0xFCBD,
    FCBE	                         = 0xFCBE,
    FCBF	                         = 0xFCBF,
    FCC0                             = 0xFCC0,
    FCC1                             = 0xFCC1,
    FCC2                             = 0xFCC2,
    FCC3                             = 0xFCC3,
    FCC4                             = 0xFCC4,
    FCD0 	                         = 0xFCD0,
    FCD1 	                         = 0xFCD1,    
    FCD2	                         = 0xFCD2,
    FCDF	                         = 0xFCDF
} _HciCommandType;

/*---------------------------------------------------------------------------
 * HciEventType type
 *
 *     These events are indicated by HCI to the Management Entity during
 *     a HCI_CONTROLLER_EVENT callback. The event type is found in the
 *     "hciEvent->event" field of the callback parameters structure
 *     (HciCallbackParms).
 */
typedef U8 HciEventType;

typedef enum 
{
    HCE_INQUIRY_COMPLETE                                    = 0x01,
    HCE_INQUIRY_RESULT                                      = 0x02,
    HCE_CONNECT_COMPLETE                                    = 0x03,
    HCE_CONNECT_REQUEST                                     = 0x04,
    HCE_DISCONNECT_COMPLETE                                 = 0x05,
    HCE_AUTH_COMPLETE                                       = 0x06,
    HCE_REMOTE_NAME_REQ_COMPLETE                            = 0x07,
    HCE_ENCRYPT_CHNG                                        = 0x08,
    HCE_CHNG_CONN_LINK_KEY_COMPLETE                         = 0x09,
    HCE_MASTER_LINK_KEY_COMPLETE                            = 0x0A,
    HCE_READ_REMOTE_FEATURES_COMPLETE                       = 0x0B,
    HCE_READ_REMOTE_VERSION_COMPLETE                        = 0x0C,
    HCE_QOS_SETUP_COMPLETE                                  = 0x0D,
    HCE_COMMAND_COMPLETE                                    = 0x0E,
    HCE_COMMAND_STATUS                                      = 0x0F,
    HCE_HARDWARE_ERROR                                      = 0x10,
    HCE_FLUSH_OCCURRED                                      = 0x11,
    HCE_ROLE_CHANGE                                         = 0x12,
    HCE_NUM_COMPLETED_PACKETS                               = 0x13,
    HCE_MODE_CHNG                                           = 0x14,
    HCE_RETURN_LINK_KEYS                                    = 0x15,
    HCE_PIN_CODE_REQ                                        = 0x16,
    HCE_LINK_KEY_REQ                                        = 0x17,
    HCE_LINK_KEY_NOTIFY                                     = 0x18,
    HCE_LOOPBACK_COMMAND                                    = 0x19,
    HCE_DATA_BUFFER_OVERFLOW                                = 0x1A,
    HCE_MAX_SLOTS_CHNG                                      = 0x1B,
    HCE_READ_CLOCK_OFFSET_COMPLETE                          = 0x1C,
    HCE_CONN_PACKET_TYPE_CHNG                               = 0x1D,
    HCE_QOS_VIOLATION                                       = 0x1E,
    HCE_PAGE_SCAN_MODE_CHANGE                               = 0x1F, /* Not in 1.2 */
    HCE_PAGE_SCAN_REPETITION_MODE                           = 0x20,
    HCE_FLOW_SPECIFICATION_COMPLETE                         = 0x21, /* 1.2 */
    HCE_INQUIRY_RESULT_WITH_RSSI                            = 0x22, /* 1.2 */
    HCE_READ_REMOTE_EXT_FEAT_COMPLETE                       = 0x23, /* 1.2 */
    HCE_FIXED_ADDRESS                                       = 0x24, /* 1.2 */
    HCE_ALIAS_ADDRESS                                       = 0x25, /* 1.2 */
    HCE_GENERATE_ALIAS_REQ                                  = 0x26, /* 1.2 */
    HCE_ACTIVE_ADDRESS                                      = 0x27, /* 1.2 */
    HCE_ALLOW_PRIVATE_PAIRING                               = 0x28, /* 1.2 */
    HCE_ALIAS_ADDRESS_REQ                                   = 0x29, /* 1.2 */
    HCE_ALIAS_NOT_RECOGNIZED                                = 0x2A, /* 1.2 */
    HCE_FIXED_ADDRESS_ATTEMPT                               = 0x2B, /* 1.2 */
    HCE_SYNC_CONNECT_COMPLETE                               = 0x2C, /* 1.2 */
    HCE_SYNC_CONN_CHANGED                                   = 0x2D, /* 1.2 */
    HCE_SNIFF_SUBRATING_EVENT                               = 0x2E, /* Posh_assert */
    HCE_INQUIRY_RESULT_WITH_EIR                             = 0x2F, /* 2.1 */
    HCE_ENCRYPTION_KEY_REFRESH_COMPLETE_EVENT               = 0x30, /* Posh_assert */
    HCE_IO_CAPABILITY_REQUEST                               = 0x31, /* 2.1 */
    HCE_IO_CAPABILITY_RESPONSE                              = 0x32, /* 2.1 */
    HCE_USER_CONFIRM_REQUSEST                               = 0x33, /* 2.1 */
    HCE_USER_PASSKEY_REQUEST_EVENT                          = 0x34, /* Posh_assert */
    HCE_REMOTE_OOB_DATA_REQUEST_EVENT                       = 0x35, /* Posh_assert */
    HCE_SIMPLE_PAIRING_COMPLETE                             = 0x36, /* 2.1 */
    HCE_LINK_SUPERVISION_TIMEOUT_CHNG                       = 0x38, /* 2.1 */
    HCE_ENHANCED_FLUSH_COMPLETE                             = 0x39, /* 2.1 */
    HCE_USER_PASSKEY_NOTIFICATION                           = 0x3B, /* 2.1 */
    HCE_USER_KEYPRESS                                       = 0x3C, /* 2.1 */
    HCE_REMOTE_HOST_SUPPORTED_FEATURES_NOTIFICATION_EVENT   = 0x3D,    /* Posh_assert */
    HCE_UART_SETTING_COMPLETE                               = 0xF0,
    HCE_PROP_BT_INFO_UPDATE                                   = 0xFC, /* Proprietary HCI interface 20110627 */
    HCE_BLUETOOTH_LOGO                                      = 0xFE,
    HCE_VENDOR_SPECIFIC                                     = 0xFF    
} _HciEventType;

/*---------------------------------------------------------------------------
 * HciHandle type
 *
 * The HciHandle contains an 12-bit connection identifier as well as
 * two bits for packet boundary flags and two bits for broadcast flags.
 * These fields are combined together to exchange information about the
 * packet data exchanged between the Host Controller and L2CAP.
 *
 */
typedef U16 HciHandle;

/*---------------------------------------------------------------------------
 * HciEvent structure
 *
 *     When the host controller generates events, these events are passed
 *     to the ME_Callback function with a callback event type of
 *     HCI_CONTROLLER_EVENT. The contents of the HCI event are found in
 *     the callback parameters "hciEvent" field.
 *
 *     The parameters buffer contains a set of event-specific parameters.
 *     The format and description for these parameters can be found in
 *     the Bluetooth HCI specification.
 */
typedef struct _HciEvent
{
    HciEventType event; /* The type of HCI event received  */
    U8 len;             /* Length of the event parameters */
    U8 *parms;          /* Event-specific parameters */
} HciEvent;


/*---------------------------------------------------------------------------
 * HciBuffer structure
 *
 *     Represents a buffer of data received from the hardware by the
 *     transport. Except for "node", all of the fields in this structure
 *     must be initialized before providing it to the HCI layer with
 *     HCI_BufferInd.
 */
typedef struct _HciBuffer
{
    ListEntry node; /* Node element for linked list management. */
    U16 len;        /* Length of data in "buffer". */
    U8 *buffer;     /* Pointer to received data buffer. */
    U8 flags;   /*
                 * Flags to identify the type of packet.
                 * Actually uses the HciBufFlags type.
                 */
#if XA_STATISTICS == XA_ENABLED
    U32 hci_timer;
#endif /* XA_STATISTICS == XA_ENABLED */
} HciBuffer;

typedef struct _HciMetaBuffer
{
    U16 con_hdl;
    U16 len;    /* Length of data in "buffer". */
    U8 *buffer; /* Pointer to received data buffer. */
} HciMetaBuffer;


/*---------------------------------------------------------------------------
 * HciCommand structure
 * 
 *     Represents an HCI command to be sent to the host controller when
 *     calling HCI_SendCommand.
 *
 *     The parameters buffer contains a set of command-specific parameters.
 *     The format and description for these parameters can be found in
 *     the Bluetooth HCI specification.
 */
typedef struct _HciCommand
{
    ListEntry node; /* For internal use only */

    U8 header[3];   /* For internal use only */

    /*
     * Command-specific parameters provided by the caller of
     * HCI_SendCommand. Note that the length of this buffer is
     * limited to HCI_CMD_PARM_LEN in btconfig.h. If a larger paramters
     * buffer is required, override this configuration setting
     * in overide.h.
     */
    U8 parms[HCI_CMD_PARM_LEN];

} HciCommand;

typedef struct _HciReducedCommand
{
    ListEntry node; /* For internal use only */

    U8 header[3];   /* For internal use only */

    /*
     * Command-specific parameters provided by the caller of
     * HCI_SendCommand. Note that the length of this buffer is
     * limited to HCI_CMD_PARM_LEN in btconfig.h. If a larger paramters
     * buffer is required, override this configuration setting
     * in overide.h.
     */
    U8 parms[10];

} HciReducedCommand;


/*---------------------------------------------------------------------------
 * HciCallbackParms structure
 *
 *     To indicate different kinds of events to the Management Entity,
 *     the HCI layer calls the ME_Callback function with an HciCallbackEvent
 *     and a callback parameters structure (this one).
 *
 *     Different fields in the "ptr" union are valid depending on the
 *     event type. See the definition for HciCallbackEvent for more
 *     information.
 */
typedef struct _HciCallbackParms
{
    BtStatus status;    /* May indicate the status of an operation */
    HciHandle hciHandle;        /*
                                 * May indicate the HCI handle concerned with the
                                 * event.
                                 */
    U8 morePacketWaiting;
    /*
     * Group: Only one of the following fields may be valid. The correct
     * field to use will depend on the HciCallbackEvent received by
     * the ME_Callback.
     */
    union
    {
        HciEvent *hciEvent;         /* Host controller event      */
        HciBuffer *rxBuff;          /* Received packet  */
        BtPacket *packet;           /* Returned transmit packet   */
        HciCommand *cmd;            /* Host controller command    */
        HciMetaBuffer *rxMetaBuff;  /* Received packet  */
        U8 txNumber;
    } ptr;
} HciCallbackParms;

/*---------------------------------------------------------------------------
 * RadioHandlerCallback type
 *
 *     Called by the HCI driver to allow radio initialization.
 */
typedef void (*RadioHandlerCallback) (U8 event, HciCallbackParms *parms);



//eventmgr.h
/*****************************************************************/
/*****************************************************************/
/*****************************************************************/

/*
 * Forward reference of EvmTimer. 
 */
typedef struct _EvmTimer EvmTimer;

/*---------------------------------------------------------------------------
 * Callback used to notify a stack component that the timer expired.
 */
typedef void (*EvmTimerNotify) (EvmTimer *);

/****************************************************************************
 *
 * Data Structures
 *
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * EvmTimer structure
 *
 *     Represents a stack timer. This structure is for use by
 *     internal stack components only.
 */
struct _EvmTimer
{
    ListEntry node;         /* Used internally by the Event Manager */
    void *context;          /* Context area for use by callers */
    EvmTimerNotify func;    /* Function to call when timer fires */

    /* === Internal use only === */
    TimeT time;         /* Amount of time to wait */
    TimeT startTime;    /* System time when the timer started */
};



// Hcitrans.h  
/*****************************************************************/
/*****************************************************************/
/*****************************************************************/

/*---------------------------------------------------------------------------
 * RadioEvent type
 *
 *     When a radio module is initialized or shut down, it can be done 
 *     synchronously or asynchronously.  If completed asynchronously, the 
 *     status of the process is sent through a callback function as an event.  
 *     The following events describe this status.
 */
typedef U8 RadioEvent;

/*---------------------------------------------------------------------------
 * RadioCallback type
 *
 *     Called by the radio module initialization and shutdown code to indicate 
 *     it's initialization or shutdown state.  The "Event" parameter contains 
 *     the appropriate event (see RadioEvent), and the "Status" parameter 
 *     contains the status of the event.
 */
typedef void (*RadioCallback) (RadioEvent Event, BtStatus Status);


/////////////////////////////////////////////////////////////////
typedef struct _t_version_info_
{
    unsigned char ver;
    char Str_Chip[20];
    char Str_Lmp[10];
    char Str_Patch[20];
}t_version_info;

#endif
 
