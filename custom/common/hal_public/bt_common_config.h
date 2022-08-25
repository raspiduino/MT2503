#ifndef _BT_COMMON_CONFIG_H_
#define _BT_COMMON_CONFIG_H_
#include "kal_general_types.h"
 
//VIRTUAL_PORTS_NUM will be defined in make file and option.mak

/* SPP port context buffer attributions */
#define SPP_RX_CREDIT (6)
/* SPP High water mark value, must be larger than one packet size */
#if (SPP_RX_CREDIT < 2)
#error For High Water Mark check, SPP_RX_CREDIT must be larger than 2
#endif 
#if defined (__BTMODULE_MT6261__) || defined (__BTMODULE_MT6260__) || defined (__BTMODULE_MT6601__) || defined (__BTMODULE_MT6611__) || defined (__BTMODULE_MT6612__) || defined (__BTMODULE_MT6616__) || defined (__BTMODULE_MT6622__) || defined (__BTMODULE_MT6626__) || defined (__BTMODULE_MT6236__)|| defined(__BTMODULE_MT6256__) || defined(__BTMODULE_MT6276__) || defined(__BTMODULE_MT6255__)
#define SPP_PACKET_SIZE  990*SPP_RX_CREDIT 
#else
#define SPP_PACKET_SIZE  330*SPP_RX_CREDIT 
#endif

/* customer shoulde malloc tx/rx buffer for spp data transmission */
#define SPP_MIN_RX_BUFSIZE     SPP_PACKET_SIZE 
#define SPP_MIN_TX_BUFSIZE     SPP_PACKET_SIZE 
/* note. SPP_PACKET_SIZE should larger then 1.5K */

//If DUMP_DATA_FROM_SPP_SRV 1: The received data from SPP server will be dumped in catcher log
#define DUMP_DATA_FROM_SPP_SRV 0
//If DUMP_DATA_FROM_SPP_CLI 1: The received data from SPP client will be dumped in catcher log
#define DUMP_DATA_FROM_SPP_CLI 0

/* Define the Number of SPP Servers ports*/
#if defined (__BT_SPP_CLI_NO_SCO__) || defined (__BT_SPP_CLI_WITH_SCO__)
#define NUM_SPP_SERVERS 2
#else
#define NUM_SPP_SERVERS 1
#endif

/* spp client port for sdk service */
#define NUM_SPP_CLIENTS 1

/* Add the assert check for NUM_SPP_SERVERS */
#if (NUM_SPP_SERVERS > 4)
#error The number of NUM_SPP_SERVERS should not be larger than 4
#endif 

#if defined (__BT_SPP_CLI_NO_SCO__) || defined (__BT_SPP_CLI_WITH_SCO__)
#define BT_SPP_VIRTUAL_PORTS_NUM  VIRTUAL_PORTS_NUM+NUM_SPP_SERVERS-1
/* define spp context buffer size to manage spp port:  */
#define SPP_CONTEXT_BUFFER_SIZE   4400
/* define spp server sdp context buffer size for storing service record */
#define SPP_SRV_SDP_CONTEXT_BUFFER_SIZE  600
#else
#define BT_SPP_VIRTUAL_PORTS_NUM  VIRTUAL_PORTS_NUM
/* define spp context buffer size to manage spp port:  */
#define SPP_CONTEXT_BUFFER_SIZE   1400
/* define spp server sdp context buffer size for storing service record */
#define SPP_SRV_SDP_CONTEXT_BUFFER_SIZE  100
#endif

#ifdef MULTI_RF_CHANNEL
/* number of RFCOMM channels registered in each spp port*/
extern int spp_ch_number[];
/* 
 * Define the total Number of SPP Servers = sum of spp_ch_number + NUM_SPP_SCO_SRVS
 * YOU SHOULD MODIFY THIS NUMBER VERY CAREFULLY!!
*/
#define TOTAL_NUM_SPP_SERVERS 1
#endif

/* 
 * The BTGet_Report_RSSI_Timer_Period(),BTGet_Decide_Report_RSSI_Sniff_Mode(),BTGet_Decide_SPP_SCO_Enter_Sniff_Mode()
 * and CUSTOM_SPP_SCO_XXX definitions are used by SPP if __BT_SPP_CLI_WITH_SCO__ or __BT_SPP_SRV_WITH_SCO__ is defined
 */
extern kal_uint16 BTGet_Report_RSSI_Timer_Period(void);
extern kal_uint8 BTGet_Decide_Report_RSSI_Sniff_Mode(void);
extern kal_uint8 BTGet_Decide_SPP_SCO_Enter_Sniff_Mode(void);
/* Define how many number of ms to ask the rssi value periodly: Currently, default value is 3000ms defined as follows */
#define CUSTOM_SPP_SCO_READ_RSSI_TIMER_PERIOD_IN_MS 2000
/* 0: Not report RSSI value in sniff mode; 1: report RSSI value in sniff mode */
#define CUSTOM_SPP_SCO_REPORT_RSSI_VALUE_IN_SNIFF_MODE 1 
/* 0: Not enable the functionality of entering sniff mode if SPP with SCO is connected then in idle state */
#define CUSTOM_SPP_SCO_ENABLE_ENTER_SNIFF_FEATURE 0

/* If need check first data is specific pattern,set CUSTOM_SPP_CHECK_CLIENT_FIRSRT_CONN_DATA as 1; otherwise as 0*/
/* If the fisrt data is specific patern, then spp data will be sent to MOD_ATCI; otherwise sent to MOD_MMI*/
/* If  set CUSTOM_SPP_CHECK_CLIENT_FIRSRT_CONN_DATA as 0, SPP data will be sent to MOD_MMI*/
#ifdef __BCM_SUPPORT__
#define CUSTOM_SPP_CHECK_CLIENT_FIRSRT_CONN_DATA 1
#else
#define CUSTOM_SPP_CHECK_CLIENT_FIRSRT_CONN_DATA 0
#endif

/* 
 * If the BtStack supports the capability for MOD_MMI to get a RSSI value of its connected ACL link via sending message 
 * Then: Set CUSTOM_MMI_BT_READ_RSSI as 1; otherwise as 0
 * If the CUSTOM_MMI_BT_READ_RSSI is changed, please clean and remake btstack,btadp,btprofiles and custom
 */
#define CUSTOM_MMI_BT_READ_RSSI 1

/********************************/
/* Configuration for HFP        */
/********************************/
#ifdef __BT_HFG_PROFILE__
/*---------------------------------------------------------------------------
 * HFG_FEATURE_THREE_WAY_CALLS constant
 *     Three way calls.  This value can be used when defining the capabilities 
 *     of the audio gateway application.
 */
#ifndef HFG_FEATURE_THREE_WAY_CALLS
#define HFG_FEATURE_THREE_WAY_CALLS      0x00000001
#endif
/*---------------------------------------------------------------------------
 * HFG_FEATURE_ECHO_NOISE constant
 *     Echo canceling and/or noise reduction function.  This value can be used 
 *     when defining the capabilities of the audio gateway application.
 */
#ifndef HFG_FEATURE_ECHO_NOISE
#define HFG_FEATURE_ECHO_NOISE           0x00000002
#endif
/*---------------------------------------------------------------------------
 * HFG_FEATURE_VOICE_RECOGNITION constant
 *     Voice recognition function.  This value can be used when defining the 
 *     capabilities of the audio gateway application.
 */
#ifndef HFG_FEATURE_VOICE_RECOGNITION
#define HFG_FEATURE_VOICE_RECOGNITION    0x00000004
#endif
/*---------------------------------------------------------------------------
 * HFG_FEATURE_RING_TONE constant
 *     In-band ring tone.  This value can be used when defining the capabilities 
 *     of the audio gateway application.
 */
#ifndef HFG_FEATURE_RING_TONE
#define HFG_FEATURE_RING_TONE            0x00000008
#endif
/*---------------------------------------------------------------------------
 * HFG_FEATURE_VOICE_TAG constant
 * Attach a phone number to a voice tag.  This value can be used when defining 
 * the capabilities of the audio gateway application.
 */
#ifndef HFG_FEATURE_VOICE_TAG
#define HFG_FEATURE_VOICE_TAG            0x00000010
#endif
/*---------------------------------------------------------------------------
 * HFG_FEATURE_REJECT constant
 *     Reject a call.  This value can be used when defining the capabilities 
 *     of the audio gateway application. 
 */
#ifndef HFG_FEATURE_REJECT
#define HFG_FEATURE_REJECT               0x00000020
#endif
/*---------------------------------------------------------------------------
 * HFG_FEATURE_ENHANCED_CALL_STATUS constant
 *     This device is capable of supporting enhanced call status features
 *     like call listing and call held indications.
 */
#ifndef HFG_FEATURE_ENHANCED_CALL_STATUS
#define HFG_FEATURE_ENHANCED_CALL_STATUS 0x00000040
#endif
/*---------------------------------------------------------------------------
 * HFG_FEATURE_ENHANCED_CALL_CTRL constant
 *     This device is capable of supporting enhanced call control features
 *     like call specifying specific lines to put on hold.
 */
#ifndef HFG_FEATURE_ENHANCED_CALL_CTRL
#define HFG_FEATURE_ENHANCED_CALL_CTRL   0x00000080
#endif
/*---------------------------------------------------------------------------
 * HFG_FEATURE_EXTENDED_ERRORS constant
 *     This device is capable of sending extended error codes.
 */
#ifndef HFG_FEATURE_EXTENDED_ERRORS
#define HFG_FEATURE_EXTENDED_ERRORS      0x00000100
#endif
#endif /*__BT_HFG_PROFILE__*/

/********************************/
/* End of configuration for HFP */
/********************************/


/********************************/
/* Configuration for HID        */
/********************************/
#ifdef __BT_HIDD_PROFILE__

#ifndef CUSTOM_HID_DESCRIPTOR_LEN
#define CUSTOM_HID_DESCRIPTOR_LEN 154
#if CUSTOM_HID_DESCRIPTOR_LEN > 65535
#error "CUSTOM_HID_DESCRIPTOR_LEN must be less than 65535"
#endif
#endif

#ifndef CUSTOM_HID_DESCRIPTOR
#define CUSTOM_HID_DESCRIPTOR \
    0x05,01,0x09,0x06,0xA1, \
    0x01,0x85,0x01,0x05,0x07, \
    0x19,0xE0,0x29,0xE7,0x15, \
    0x00,0x25,0x01,0x75,0x01, \
    0x95,0x08,0x81,0x02,0x95, \
    0x01,0x75,0x08,0x81,0x03, \
    0x95,0x05,0x75,0x01,0x05, \
    0x08,0x19,0x01,0x29,0x05, \
    0x91,0x02,0x95,0x01,0x75, \
    0x03,0x91,0x03,0x95,0x06, \
    0x75,0x08,0x15,0x00,0x25,\
    0x65,0x05,0x07,0x19,0x00,\
    0x29,0x65,0x81,0x00,0xC0,\
    0x05,0x01,0x09,0x02,0xA1,\
    0x01,0x85,0x02,0x09,0x01,\
    0xA1,0x00,0x05,0x09,0x19,\
    0x01,0x29,0x03,0x15,0x00,\
    0x25,0x01,0x95,0x03,0x75,\
    0x01,0x81,0x02,0x95,0x01,\
    0x75,0x05,0x81,0x03,0x05,\
    0x01,0x09,0x30,0x09,0x31,\
    0x15,0x81,0x25,0x7F,0x75,\
    0x08,0x95,0x02,0x81,0x06,\
    0xC0,0xC0,0x05,0x0c,0x09,\
    0x01,0xa1,0x01,0x85,0x03,\
    0x15,0x00,0x25,0x01,0x75,\
    0x01,0x95,0x06,0x09,0xCD,\
    0x09,0xE9,0x09,0xEA,0x09,\
    0xB5,0x09,0xB6,0x09,0xB7,\
    0x81,0x02,0x95,0x01,0x75,\
    0x02,0x81,0x03,0xC0
#endif

#endif

/********************************/
/* End of configuration for HID */
/********************************/

extern kal_bool bt_custom_read_address_from_nvram(void);

// for radiomod.c to get the default flowcontrol of the BB chip
kal_uint8 BtRadio_Get_Deafult_Flowcontrol_Setting(void);

/*
* The return value will be used as page timeout  when we page other device or request name of other device,
* the measurement is slot, 1 slot=0.000625s,for example: 0x3800 slots = 8.96s
* Specification value range:0x0001-0xFFFF,default vaue is 5.12s
*/

kal_uint32 BTGet_Custom_Page_Timeout(void);

#ifdef __MTK_BT_DUAL_PCM_SWITCH_SUPPORT__ 
void BtRadio_HW_Set_Switch_PCM(kal_uint8 pcm_slect);
#endif


/************************************************************************
************************************************************************/
//Modem_Only project
//Below API just provided when BLUETOOTH_SUPPORT = NONE,if not, occure redefined error
#if (!defined (__BTMTK__)) 
void BtRadio_PCM_GPIOSetup(kal_uint8 enable);
kal_bool BtRadio_Get_PCM_ShortSync(void);
kal_bool BtRadio_Get_PCM_LSBFirst(void);
kal_bool BtRadio_Get_PCM_SignExtension(void);
#endif

/*
 * terrence,2013/06/26,BT dialer feature:Low power solution
 * API used by MTK
 */
#ifdef __BT_DIALER_SUPPORT__

kal_bool Custom_BTDialer_LowPower_Support(void);
kal_uint8 Custom_BTDialer_TXPower_Level(void);

#endif

/*
 * terrence,2013/08/02,Class of device setting
 *return:
 *--kal_true:use cod
 *--kal_false:do not use cod
 *parameter:cod value setting by custom
 */
kal_bool Custom_Config_Get_BT_COD(kal_uint32 * cod);

void Custom_Config_Set_BT_COD(kal_uint32 cod, kal_bool use_custom_cod);


void Custom_Config_Get_BQB_COD(kal_bool * bqb_cod);
void Custom_Config_Set_BQB_COD(kal_bool bqb_cod);

#ifndef __BT_DISABLE_SSP_SUPPORT__
/**
 * get current SSP setting.
 *
 * @param    void
 *
 * @return 
 * @retval KAL_TRUE       support SSP
 * @retval KAL_FALSE      not support
 *
 * @authors    mawei
 * @date          2013/9/16
 */
kal_bool Custom_Config_Get_BT_SSP_Support(void);
#endif

kal_uint8* Custom_BTPairing_AutoAccept_Pincode(kal_uint8 * pin_size);
kal_bool BTParing_Fixed_PinCode_Only_Support(void);


/************************************************************************
************************************************************************/
//carefully!!!! usually custom should not change sniff parameter

void Custom_Set_BT_Sniff_Parameter(kal_int8 sniff_level);

kal_int8 Custom_Get_BT_Sniff_Parameter(void);
/************************************************************************
************************************************************************/

/************************************************************************
************************************************************************/
//Pairing method
typedef enum 
{
	 PIN_AND_SSP = 0,							//Pairing need UI and user should confirm,normal case for product,such as phone/mid,we support both pin and ssp
	 FIXED_PIN_ONLY,							//Pairing no need UI,auto accept pairing ,only adopt FIXED PIN CODE method
	 FIXED_PIN_AND_SSP_JUST_WORK				//Pairing no need UI,auto accept pairing ,adopt FIXED PIN CODE and JUST WORK of SSP
}Pairing_Type;

//terrence,2013/12/31,unify pairing method config
void Custom_Set_BT_Pairing_Method(Pairing_Type config_type);
Pairing_Type Custom_Get_BT_Pairing_Method(void);

kal_bool BTParing_Fixed_PinCode_Only_Support(void);
kal_bool Custom_BTPairing_AutoAccept_Support(void);
kal_uint8* Custom_BTPairing_AutoAccept_Pincode(kal_uint8 * pin_size);

/************************************************************************
************************************************************************/



#endif /* _BT_COMMON_CONFIG_H_ */
