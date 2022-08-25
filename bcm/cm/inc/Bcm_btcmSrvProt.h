/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 * BtcmSrvProt.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is the internal header file for BT CM
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef BT_CM_SRV_PROT_H
#define BT_CM_SRV_PROT_H
// RHR: add
//#include "TimerEvents.h"
#include "kal_general_types.h"
// RHR: add

//#include "bluetooth_bm_struct.h"
#include "Bcm_btcmSrvGprot.h"
#include "bcmadp.h"
#include "nvram_data_items.h"
#include "kal_public_defs.h"
#include "bcm_struct.h"
#include "Bcm_btcmUtility.h"
/***************************************************************************** 
* Macro
*****************************************************************************/
#ifdef __BCM_SUPPORT__

//#ifndef __SRV_BT_CM_DEBUG_INTENAL__
#define __SRV_BT_CM_DEBUG_INTENAL__

#ifdef __MMI_BT_SLIM__
#ifndef _MMI_BT_ULTRA_SLIM_
#define _MMI_BT_ULTRA_SLIM_
#endif 
#endif
//#endif

MMI_BOOL SRV_BT_CM_GET_FLAG(U32 flag);

void SRV_BT_CM_SET_FLAG(U32 flag);

void SRV_BT_CM_RESET_FLAG(U32 flag);

MMI_BOOL SRV_BT_CM_GET_RAMFLAG(U32 ram_flag);

void SRV_BT_CM_SET_RAMFLAG(U32 ram_flag);

void SRV_BT_CM_RESET_RAMFLAG(U32 ram_flag);

void SRV_BT_CM_STATE_TRANS(U32 state);

void SRV_BT_CM_TMP_STATE_TRANS(U32 state);


/***************************************************************************** 
* Definations
*****************************************************************************/
#define SRV_BT_CM_PASSKEY_MAX_LEN            16
#define SRV_BT_CM_POWER_ON_TIMER_DUR         30000
#define SRV_BT_CM_RELEASE_ALL_CONN_TIMER_DUR 45000  /* 45  sec */
#define SRV_BT_CM_POWER_OFF_TIMER_DUR        25000  /* 25  sec */
#define SRV_BT_CM_CMD_TIMER_DUR              210000 /* 210 sec */

/* <GROUP MMI BT flag bit-wise ram flag defination(Not stored in NVRAM)>
   swap 2 BT */
#define SRV_BT_CM_RAMMASK_IS_SWAP2BT               0x00000001
// remove to MMI
/* <GROUP MMI BT flag bit-wise ram flag defination(Not stored in NVRAM)>
   auto power switch */
//#define SRV_BT_CM_RAMMASK_IS_AUTO_PWR_SWITCH       0x00000002
/* <GROUP MMI BT flag bit-wise ram flag defination(Not stored in NVRAM)>
   is ready or not */
#define SRV_BT_CM_RAMMASK_IS_READY                 0x00000004
/* <GROUP MMI BT flag bit-wise ram flag defination(Not stored in NVRAM)>
   icon blinking status */
// remote to MMI
//#define SRV_BT_CM_RAMMASK_IS_ICON_BLINKING         0x00000008
/* <GROUP MMI BT flag bit-wise ram flag defination(Not stored in NVRAM)>
   first pair request */
#define SRV_BT_CM_RAMMASK_FIRST_PAIR_REQ           0x00000010
/* <GROUP MMI BT flag bit-wise ram flag defination(Not stored in NVRAM)>
   reject the pair request */
#define SRV_BT_CM_RAMMASK_REJECT_PAIR_REQ          0x00000020
/* <GROUP MMI BT flag bit-wise ram flag defination(Not stored in NVRAM)>
   reach max acl link */
//#define SRV_BT_CM_RAMMASK_REACH_MAX_ACL_LINK       0x00000040
/* <GROUP MMI BT flag bit-wise ram flag defination(Not stored in NVRAM)>
   force to set visibility as off */
//#define SRV_BT_CM_RAMMASK_FORCE_TO_SET_VIS_BE_OFF  0x00000080
/* <GROUP MMI BT flag bit-wise ram flag defination(Not stored in NVRAM)>
   SAP activate */
//#define SRV_BT_CM_RAMMASK_IS_SIMAP_ACTIVATE        0x00000100
/* <GROUP MMI BT flag bit-wise ram flag defination(Not stored in NVRAM)>
   auto power off */
//#define SRV_BT_CM_RAMMASK_IS_AUTO_PWR_OFF          0x00000200

/* <GROUP MMI BT flag bit-wise ram flag defination(Not stored in NVRAM)>
   temp visibility */
#define SRV_BT_CM_RAMMASK_IS_TEMP_VIS              0x00000400
/* <GROUP MMI BT flag bit-wise ram flag defination(Not stored in NVRAM)>
   16 digit passkey */
//#define SRV_BT_CM_RAMMASK_IS_16_DIGIT_PASSKEY      0x00000800


/* <GROUP MMI BT flag bit-wise ram flag defination(Not stored in NVRAM)>
   auto power switch only */
//#define SRV_BT_CM_RAMMASK_IS_AUTO_PWR_SWITCH_ONLY  0x00001000
/* <GROUP MMI BT flag bit-wise ram flag defination(Not stored in NVRAM)>
   limit visibility */
#define SRV_BT_CM_RAMMASK_LIMIT_VIS                0x00002000

#define SRV_BT_CM_RAMMASK_PRE_DEACTIVATING         0x00004000

#define SRV_BT_CM_RAMMASK_POST_DEACTIVATING        0x00008000


/* <GROUP MMI BT flag bit-wise flag defination(stored in NVRAM)>
   to check the nvram sanity */
//#define SRV_BT_CM_MASK_GUARD              0x00000001

/* <GROUP MMI BT flag bit-wise flag defination(stored in NVRAM)>
   BT is power on or not */
#define SRV_BT_CM_MASK_ACTIVATED          0x00000002
/* <GROUP MMI BT flag bit-wise flag defination(stored in NVRAM)>
   need to restore BT status or not */
#define SRV_BT_CM_MASK_RESTORE_BT         0x00000004
/* <GROUP MMI BT flag bit-wise flag defination(stored in NVRAM)>
   DM reset */
//#define SRV_BT_CM_MASK_DM_RESET           0x00000008
/* <GROUP MMI BT flag bit-wise flag defination(stored in NVRAM)>
   SRV_BT_CM_MASK_GUARD | SRV_BT_CM_MASK_ACTIVATED | SRV_BT_CM_MASK_RESTORE_BT */
#define SRV_BT_CM_MASK_NON_SYS_SETTING    0x0000000F
/* <GROUP MMI BT flag bit-wise flag defination(stored in NVRAM)>
   to check the nvram sanity */
//#define SRV_BT_CM_MASK_SYS_GUARD          0x00000010

/* <GROUP MMI BT flag bit-wise flag defination(stored in NVRAM)>
   visibility setting */
#define SRV_BT_CM_MASK_VIS                0x00000020
/* <GROUP MMI BT flag bit-wise flag defination(stored in NVRAM)>
   authentication setting */
#define SRV_BT_CM_MASK_AUTH               0x00000040

/* <GROUP MMI BT flag bit-wise flag defination(stored in NVRAM)>
   0: Leave in Phone, 1: To Earphone */
//#define SRV_BT_CM_MASK_AUDPATH            0x00000080

/* <GROUP MMI BT flag bit-wise flag defination(stored in NVRAM)>
   SRV_BT_CM_MASK_SYS_GUARD|SRV_BT_CM_MASK_VIS|SRV_BT_CM_MASK_AUTH|SRV_BT_CM_MASK_AUDPATH */
/* <GROUP MMI BT flag bit-wise flag defination(stored in NVRAM)>
   0: normal power off, 1: timeout power off */
#define SRV_BT_CM_MASK_POWER_ON_TIME_OUT  0x00000100
#define SRV_BT_CM_MASK_POWER_OFF_TIME_OUT 0x00000200
#define SRV_BT_CM_MASK_SYS_SETTING        0x000000F0


/* <GROUP MMI BT flag bit-wise ram flag defination(Not stored in NVRAM)>
   auto power switch */
//#define SRV_BT_CM_RAMMASK_IS_AUTO_PWR_SWITCH       0x00000002

/* <GROUP MMI BT flag bit-wise ram flag defination(Not stored in NVRAM)>
   icon blinking status */
//#define SRV_BT_CM_RAMMASK_IS_ICON_BLINKING         0x00000008



/* <GROUP MMI BT bit-wise flag defination of device attribute>
   authorize */
#define SRV_BT_CM_DEVICE_ATTRIBUTE_AUTHORIZE       0x00000001
/* <GROUP MMI BT bit-wise flag defination of device attribute>
   user defined name */
#define SRV_BT_CM_DEVICE_ATTRIBUTE_USER_DEFINED_NAME 0x00000002
/* <GROUP MMI BT bit-wise flag defination of device attribute>
   blocked */
#define SRV_BT_CM_DEVICE_ATTRIBUTE_BLOCK           0x00000004

#define SRV_BT_CM_DEVICE_ATTRIBUTE_HIDD           0x00000008
/* <GROUP MMI BT flag bit-wise flag for service deactivated or not>
   HFP */
#define SRV_BT_CM_HFP_DEACTIVATED               0x00000001
/* <GROUP MMI BT flag bit-wise flag for service deactivated or not>
   HSP */
#define SRV_BT_CM_HSP_DEACTIVATED               0x00000002
/* <GROUP MMI BT flag bit-wise flag for service deactivated or not>
   OPS */
#define SRV_BT_CM_OPS_DEACTIVATED               0x00000004
/* <GROUP MMI BT flag bit-wise flag for service deactivated or not>
   FTS */
#define SRV_BT_CM_FTS_DEACTIVATED               0x00000008
/* <GROUP MMI BT flag bit-wise flag for service deactivated or not>
   SPP */
#define SRV_BT_CM_SPP_DEACTIVATED               0x00000010
/* <GROUP MMI BT flag bit-wise flag for service deactivated or not>
   DUN */
#define SRV_BT_CM_DUN_DEACTIVATED               0x00000020
/* <GROUP MMI BT flag bit-wise flag for service deactivated or not>
   A2DP */
#define SRV_BT_CM_A2DP_DEACTIVATED              0x00000040
/* <GROUP MMI BT flag bit-wise flag for service deactivated or not>
   AVRCP */
#define SRV_BT_CM_AVRCP_DEACTIVATED             0x00000080
/* <GROUP MMI BT flag bit-wise flag for service deactivated or not>
   AVRCP_CT */
#define SRV_BT_CM_AVRCP_CT_DEACTIVATED          0x00000100
/* <GROUP MMI BT flag bit-wise flag for service deactivated or not>
   FTC */
#define SRV_BT_CM_FTC_DEACTIVATED               0x00000200
/* <GROUP MMI BT flag bit-wise flag for service deactivated or not>
   BPP */
#define SRV_BT_CM_BPP_DEACTIVATED               0x00000400
/* <GROUP MMI BT flag bit-wise flag for service deactivated or not>
   SIMAP */
#define SRV_BT_CM_SIMAP_DEACTIVATED             0x00000800
/* <GROUP MMI BT flag bit-wise flag for service deactivated or not>
   FAX */
#define SRV_BT_CM_FAX_DEACTIVATED               0x00001000
/* <GROUP MMI BT flag bit-wise flag for service deactivated or not>
   HID */
#define SRV_BT_CM_HIDD_DEACTIVATED              0x00002000
/* <GROUP MMI BT flag bit-wise flag for service deactivated or not>
   BIP */
#define SRV_BT_CM_BIP_DEACTIVATED               0x00004000
/* <GROUP MMI BT flag bit-wise flag for service deactivated or not>
   PBAP */
#define SRV_BT_CM_PBAP_DEACTIVATED              0x00008000
/* <GROUP MMI BT flag bit-wise flag for service deactivated or not>
   OPC */
#define SRV_BT_CM_OPC_DEACTIVATED               0x00010000
/* <GROUP MMI BT flag bit-wise flag for service deactivated or not>
   SYNCML_DEV */
#define SRV_BT_CM_SYNCML_DEV_DEACTIVATED        0x00020000

#define SRV_BT_CM_TEMP_VISIBLE_TIMER_DUR        60000    /* 60 sec */


/***************************************************************************** 
* typedef 
*****************************************************************************/
// typedef enum
// {
//     SRV_BT_CM_HS_CONNECTING_STATE_IDLE = 0,
//     SRV_BT_CM_HS_CONNECTING_STATE_HFP_CONNECTING,
//     SRV_BT_CM_HS_CONNECTING_STATE_HSP_CONNECTING,
//     SRV_BT_CM_HS_CONNECTING_STATE_LAST
// } srv_bt_cm_hs_conn_state_enum;

// typedef enum
// {
//     SRV_BT_CM_HS_NOT_SHOW_CONNECT_SCR = 0,
//     SRV_BT_CM_HS_SHOW_CONNECT_SCR,
//     SRV_BT_CM_HS_CONNECT_SCR_SHOW_last
// } srv_bt_cm_hs_connect_scr_show_enum;





typedef struct
{
    event_scheduler *event_scheduler_ptr;
    bcm_timer_info_struct timer_pool[BCM_MAX_TIMER_NUM];

    
    kal_uint8 curr_usr; // used to remember src_id from atci
    msg_type curr_req;  // used to remember what action is it now.
    module_type  curr_req_src;      /* Source module ID of the message. */
    kal_uint8 op;   // we use this op to diff some req's op for cnf. it's not a well design.
    
    kal_uint8 urc_interval;//inquiry time interval, should have a default value
    kal_uint8 inquiry_length;//inquiry time last, should have a default value
    kal_uint8 inquiry_number;//max inquery number, should have a default value
    kal_uint32 cod;//inquery filter, should have a default value

    srv_bt_cm_bt_addr dev_addr; // used to trans currently operated dev_addr between 
    kal_uint64 profile_map;//used to save profile active information.
    kal_uint64 act_profile_map;//used to save profile active information.
    kal_uint64 deact_profile_map;//used to save profile deactive information.
    kal_uint64 full_map;//used to mask howmany (de)activate request finished.

    kal_uint32 cm_handle;// defaultlly, BCM will hold only one CM instance.

    kal_uint8 ext_cm_state; // an enum to ind cm state for external.
    kal_uint8 cm_pair_state;//for distinguish which pair way currently used.
    
}bcm_context_struct;

extern bcm_context_struct *BCM_PTR;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
typedef struct
{
    srv_bt_cm_dev_struct_int dev_list[SRV_BT_CM_MAX_DEVICE_LIST];           /* device list: 168 * SRV_BT_CM_MAX_DEVICE_LIST(20) */
} srv_bt_cm_nvram_dev_list_struct;
#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__PLUTO_MMI_PACKAGE__) && defined(__LOW_COST_SUPPORT_COMMON__) // SLIM:memory reduction
/* under construction !*/
#endif                                         // SLIM:memory reduction
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef struct
{
    U32 profile_id;
    U32 conn_id;
} srv_bt_cm_conn_cnf_struct;

typedef void (*srv_bt_cm_func_ptr_void_ptr)(void*);

/* operation callback structure */
typedef struct
{
    U32 operation_type;                      /* operation table */
    srv_bt_cm_func_ptr_void_ptr cb_func_ptr; /* callback function pointer */
} srv_bt_cm_operation_cb_struct;


typedef MMI_BOOL (*srv_bt_cm_func_ptr_addr)(srv_bt_cm_bt_addr);
/* for registering pairing function call */
typedef struct
{
    U32 profile_uuid;                 /* profile UUID */
    srv_bt_cm_func_ptr_addr func_ptr; /* callback function pointer */
} srv_bt_cm_pairing_permission_struct;

typedef struct
{
    /* remember the visibility before set it success */
    U8 tmp_visibility_type;

    /* pairing Dev Info */
    U8 action_index;

    /* bth a2dp prohibit visibility flag */
    U8 a2dp_prohibit_vis;

    U8 host_security_level;

    U8 discovered_dev_num;

    /* to store the number of service before refreshing service list */
    U8 stored_ser_list_num;
#ifdef __BT_DIALER_SUPPORT__
	MMI_BOOL bt_dialor_mode;
#endif 
#ifdef __MMI_BT_DIALER_SUPPORT__
	MMI_BOOL bt_dialor_app_mode;
#endif

#ifdef __BT_AUTO_DETECT_SUPPORT__
    U8 chip_avail;
#endif

    srv_bt_cm_state_enum state;
    srv_bt_cm_state_enum tmp_state;

    /* bth flag(shall be stored in NVRAM) */
    U32 flag;

    /* bth ram flag(shall not be sotored in NVRAM) */
    U32 ram_flag;

    /* bth service deactivate flag */
    U32 deactivate_flag;

    U16 paired_dev_num;
    U16 recent_dev_num;
    srv_bt_cm_dev_struct_int dev_list[SRV_BT_CM_MAX_DEVICE_LIST];
    U8 paired_idx_list[SRV_BT_CM_MAX_PAIRED_DEVICE_LIST];
    U8 recent_idx_list[SRV_BT_CM_MAX_USED_DEVICE_LIST];
    srv_bt_cm_dev_struct temp_dev;

    srv_bt_cm_connect_struct existed_conn[SRV_BT_CM_MAX_CONNECTION];

    /* discovery List */
    srv_bt_cm_dev_struct discovered_list[SRV_BT_CM_MAX_DISCOVERY_RESULTS_IN_LIST];

    /* host Dev Info */
    srv_bt_cm_dev_struct host_dev;

    /* last HID Dev Info */
	#if defined(__MMI_HIDD_SUPPORT__)
    U32 idx_of_last_hid_dev;
	#endif
    U8* host_name_setting;

    /* to keep disconnecting conneciton id */
    U32 disconnect_con_id;

    /* connection id of connected 2nd hfg */
    /* profile id of connect accept confirm */
    srv_bt_cm_conn_cnf_struct conn_cnf[SRV_BT_CM_MAX_CONNECTION];

    /* For JSR82 */
    /* BCC */
    /* Register operation callback function */
	#ifdef __SUPPORT_JBT__
    srv_bt_cm_operation_cb_struct operation_cb_tbl[SRV_BT_CM_OPER_TYPE_TOTAL];
	#endif
    /* for registering pairing function call */
    /* Register callback */
    /* to check if doing the pairing process or not,
     * if one profile app is doing abort or disconnect, pairing process is not required. */
    /* then BT CM shall reject the pairing directly */
    srv_bt_cm_pairing_permission_struct pair_permission_cb;

#ifdef __DM_LAWMO_SUPPORT__
    srv_dm_lawmo_lock_report_cb_func_type lawmo_lock_cb;
#endif
    
} srv_bt_cm_cntx_struct;


/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
/* Context access */
extern srv_bt_cm_cntx_struct g_srv_bt_cm_cntx;
//extern srv_bt_cm_supported_profile_struct support_profile_tbl[];

/* supported profile callback table structure */
typedef struct
{
    U32 profile_id;                  /* profile UUID */
    profile_activate activater;      /* activate */
    profile_deactivate deactivater;  /* deactivate */
    //profile_connect connector;       /* connect */
    profile_disconnect disconnector; /* disconnect */
    U32 deactivate_flag;             /* indicate whether deactivate */
} srv_bt_cm_profile_struct_int;

extern srv_bt_cm_profile_struct_int g_srv_bt_cm_profile_tbl[SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE];


/***************************************************************************** 
 * Functions
 *****************************************************************************/
#define Main
/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_init_event_handler
 * DESCRIPTION
 *  This function is to init event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_init_event_handler(void);
    
    
/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_is_name_duplicated
 * DESCRIPTION
 *  This function is to check if name is duplicated with other paired device, if yes, will add a prefix.
 * PARAMETERS
 *  name_p                  [OUT]       name pointer
 *  skip_paired_index       [IN]          the index of paired device to skip
 * RETURNS
 *  MMI_BOOL        TRUE : the name is duplicated
 *                  FALSE : the name is not duplicated
 *****************************************************************************/
//MMI_BOOL srv_bt_cm_is_name_duplicated(kal_uint8* name_p, U8 skip_paired_index);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_activate_profiles
 * DESCRIPTION
 *  This function is to process activat profile request and invoke activate functions of profiles
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_activate_profiles_int(MMI_BOOL flight_mode);

/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_copy_addr
 * DESCRIPTION
 *  This function is to copy address
 * PARAMETERS
 *  dest       [IN]           destination address
 *  src           [IN]        source address
 * RETURNS
 *****************************************************************************/

extern void srv_bt_cm_copy_addr(void *dest,void *src);
/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_background_disconnect
 * DESCRIPTION
 *  This function is to process disconnect request
 * PARAMETERS
 *  conn_id       [IN]            connection id
 *  conn_type           [IN]             connection type
 * RETURNS
 *  MMI_BOOL        TRUE : the profile is supported
                    FALSE : the profile is not supported
 *****************************************************************************/
//MMI_BOOL srv_bt_cm_background_disconnect(U32 conn_id, srv_bt_cm_connection_type conn_type);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_is_all_supported_profiles_activated
 * DESCRIPTION
 *  This function is to check if all supported profiles are activated
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL        TRUE : all supported profiles are activated
                    FALSE : not all supported profiles are activated
 *****************************************************************************/
MMI_BOOL srv_bt_cm_is_all_supported_profiles_activated(MMI_BOOL flight_mode);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_is_all_supported_profiles_deactivated
 * DESCRIPTION
 *  This function is to check if all supported profiles are deactivated
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL        TRUE : all supported profiles are deactivated
                    FALSE : not all supported profiles are deactivated
 *****************************************************************************/
MMI_BOOL srv_bt_cm_is_all_supported_profiles_deactivated(void);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_set_deactivate_flag
 * DESCRIPTION
 *  This function is to set deactivate flag
 * PARAMETERS
 *  prof_flag       [IN]            profile flag
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_set_deactivate_flag(U32 prof_flag);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_reset_deactivate_flag
 * DESCRIPTION
 *  This function is to reset deactivate flag
 * PARAMETERS
 *  prof_flag       [IN]            profile flag
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_reset_deactivate_flag(U32 prof_flag);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_is_pairing_permitted
 * DESCRIPTION
 *  This function is to check if pairing is permitted
 * PARAMETERS
 *  srv_bt_cm_bt_addr dev_addr, specify the device address
 * RETURNS
 *  MMI_BOOL    MMI_TRUE    permitted
 *              MMI_FALSE   not permitted
 *****************************************************************************/
MMI_BOOL srv_bt_cm_is_pairing_permitted(srv_bt_cm_bt_addr dev_addr);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_set_a2dp_prohibit_vis
 * DESCRIPTION
 *  This function is to set A2DP prohibit visibility
 * PARAMETERS
 *  setting     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_set_a2dp_prohibit_vis(MMI_BOOL setting);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_increase_paired_dev_num
 * DESCRIPTION
 *  This function is to increase g_srv_bt_cm_cntx.paired_dev_num
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_increase_paired_dev_num(void);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_decrease_paired_dev_num
 * DESCRIPTION
 *  This function is decrease g_srv_bt_cm_cntx.paired_dev_num
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_decrease_paired_dev_num(void);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_set_action_index
 * DESCRIPTION
 *  This function is to set g_srv_bt_cm_cntx.action_index
 * PARAMETERS
 *  index
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_set_action_index(U32 index);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_echo_conn_cnf_stack
 * DESCRIPTION
 *  This function is echo the conn_cnf stack info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_echo_conn_cnf_stack(void);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_push_conn_cnf_stack
 * DESCRIPTION
 *  This function is push conn cnf structure into stack
 * PARAMETERS
 *  profile_id :     connection confirm profile id
 *  conn_id    :     connection confirm index of device
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_push_conn_cnf_stack(U32 profile_id, U32 conn_id);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_pop_conn_cnf_stack
 * DESCRIPTION
 *  This function is to popup conn cnf structure out of stack
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_bt_cm_conn_cnf_struct
 *****************************************************************************/
srv_bt_cm_conn_cnf_struct* srv_bt_cm_pop_conn_cnf_stack(void);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_clear_top_conn_cnf_stack
 * DESCRIPTION
 *  This function is to set top of conn cnf structure stack as zero
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
//void srv_bt_cm_clear_top_conn_cnf_stack(void);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_clear_specific_conn_cnf_stack
 * DESCRIPTION
 *  This function is to set specific conn cnf structure stack as zero
 * PARAMETERS
 *  conn_id : profile ID
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_bt_cm_clear_specific_conn_cnf_stack(U32 conn_id);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_connect_paired_headset_with_index
 * DESCRIPTION
 *  This function is to process connect headset, with paired index as parameter
 * PARAMETERS
 *  paired_index : the paired device index 
 *  show_prgs_scr : to show progressing screen or not
 * RETURNS
 *  MMI_BOOL        TRUE : success to connect
 *                  FALSE : otherwise
 *****************************************************************************/
//MMI_BOOL srv_bt_cm_connect_paired_headset_with_index(U32 paired_index, srv_bt_cm_hs_connect_scr_show_enum prgs_scr);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_connect_headset
 * DESCRIPTION
 *  This function is to process connect headset
 * PARAMETERS
 *  dev_addr : bd_addr of headset
 *  conn_cb : connection callback function
 * RETURNS
 *  MMI_BOOL        TRUE : success to connect
 *                  FALSE : otherwise
 *****************************************************************************/
//MMI_BOOL srv_bt_cm_connect_headset(srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_headset_connect_callback conn_cb);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_disconnect_headset
 * DESCRIPTION
 *  This function is to process disconnect headset
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL        TRUE : success to disconnect
 *                  FALSE : otherwise
 *****************************************************************************/
//MMI_BOOL srv_bt_cm_disconnect_headset(void);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_cancel_connect_headset
 * DESCRIPTION
 *  This function is to process cancel connect headset
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL        TRUE : success to cancel connect
 *                  FALSE : otherwise
 *****************************************************************************/
//MMI_BOOL srv_bt_cm_cancel_connect_headset(void);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_get_active_hfp_connect_id
 * DESCRIPTION
 *  This function is to get current active hfp/hsp connection id
 * PARAMETERS
 *  void
 * RETURNS
 *  U8          active HFP connection id
 *****************************************************************************/
U8 srv_bt_cm_get_active_hfp_connect_id(void);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_set_connectable
 * DESCRIPTION
 *  This function is to set connectable request
 * PARAMETERS
 *  connectable     [IN]            the connectable mode value
 * RETURNS
 *  MMI_BOOL        return TRUE
 *****************************************************************************/
//MMI_BOOL srv_bt_cm_set_connectable(MMI_BOOL connectable);


// #ifdef __DM_LAWMO_SUPPORT__
// /*****************************************************************************
//  * FUNCTION
//  *  srv_bt_cm_lawmo_cb_hdlr
//  * DESCRIPTION
//  *  This function is to LAWMO callback handler 
//  * PARAMETERS
//  *  app_id : application id
//  *  cmd : command code
//  * RETURNS
//  *  void
//  *****************************************************************************/
// void srv_bt_cm_lawmo_cb_hdlr(U8 app_id, U8 cmd);
// #endif /*__DM_LAWMO_SUPPORT__*/


#define Prmt 
/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_antenna_on_req_hdler
 * DESCRIPTION
 *  This function is to handle antenna on req, it sends MSG_ID_BT_POWERON_REQ
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_antenna_on_req_hdler(void);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_antenna_on_rsp_hdler
 * DESCRIPTION
 *  This function is to handle antenna on cnf, it just reset SRV_BT_CM_RAMMASK_IS_READY
 * PARAMETERS
 *  msg         [IN]        inter layer message             
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_bt_cm_antenna_on_rsp_hdler(void* msg);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_antenna_off_req_hdler
 * DESCRIPTION
 *  This function is to handle antenna off request, it sends MSG_ID_BT_POWEROFF_REQ
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_antenna_off_req_hdler(void);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_antenna_off_rsp_hdler
 * DESCRIPTION
 *  This function is to handler antenna off response
 *      1. reset SRV_BT_CM_RAMMASK_IS_READY
 *      2. invoke mmi_bt_scr_cb_deactivate callback function
 * PARAMETERS
 *  msg         [IN]        inter layer message             
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_bt_cm_antenna_off_rsp_hdler(void* msg);


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_restart_req_ind_hdler
 * DESCRIPTION
 *  This function is to handle restart request indication, it invokes mmi_bt_scr_cb_panic_ind callback
 * PARAMETERS
 *  msg         [IN]        inter layer message                          
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_restart_req_ind_hdler(void* msg);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_restart_rsp_hdler
 * DESCRIPTION
 *  This function is to handle restart response, send antenna on req to BTH
 * PARAMETERS
 *  msg         [IN]        inter layer message                          
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_restart_rsp_hdler(void* msg);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_discovery_req_hdler
 * DESCRIPTION
 *  This function is to handle CM discovery request, it sends MSG_ID_BT_BM_DISCOVERY_REQ
 * PARAMETERS
 *  max_response        [IN]            max discovery result in response
 *  timeout             [IN]                the discovery timeout timer
 *  cod                 [IN]                  class of device
 *  name_discovery      [IN]            whether to do name discovery or not
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_discovery_req_hdler(U8 max_response, U16 timeout, U32 cod, MMI_BOOL name_discovery);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_discovery_result_ind_hdler
 * DESCRIPTION
 *  This function is to handle discovery result indication and to process found device
 * PARAMETERS
 *  msg         [IN]        inter layer message                          
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_discovery_result_ind_hdler(void* msg);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_discovery_cnf_hdler
 * DESCRIPTION
 *  This function is to handler discovery confirm and invoke mmi_bt_scr_cb_inquiry_cfm callback
 * PARAMETERS
 *  msg         [IN]        inter layer message                          
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_discovery_cnf_hdler(void* msg);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_cancel_discovery_req_hdler
 * DESCRIPTION
 *  This function is to handle cancel discovery request, it sends MSG_ID_BT_BM_DISCOVERY_CANCEL_REQ
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_cancel_discovery_req_hdler(void);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_cancel_discovery_cnf_hdler
 * DESCRIPTION
 *  This function is to handle cancel discovery confirm and invoke mmi_bt_scr_cb_inquiry_cancel callback
 * PARAMETERS
 *  msg         [IN]        inter layer message              
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_cancel_discovery_cnf_hdler(void* msg);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_set_local_name_req_hdler
 * DESCRIPTION
 *  This function is to handle set locak name request and send MSG_ID_BT_BM_WRITE_LOCAL_NAME_REQ
 * PARAMETERS
 *  name_len        [IN]            name length
 *  name            [IN]             name
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_set_local_name_req_hdler(U8 name_len, U8* name);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_set_local_name_cnf_hdler
 * DESCRIPTION
 *  This function is to handle set local name confirm
 * PARAMETERS
 *  msg         [IN]        inter layer message              
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_set_local_name_cnf_hdler(void* msg);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_read_local_bd_addr_req_hdler
 * DESCRIPTION
 *  This function is to handle read local bd addr request and send MSG_ID_BT_BM_READ_LOCAL_ADDR_REQ
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_read_local_bd_addr_req_hdler(void);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_read_local_bd_addr_cnf_hdler
 * DESCRIPTION
 *  This function is to handle read local bd addr confirm and set local name
 * PARAMETERS
 *  msg         [IN]        inter layer message              
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_bt_cm_read_local_bd_addr_cnf_hdler(void* msg);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_read_remote_name_req_hdler
 * DESCRIPTION
 *  This function is to handle read remote name request and send MSG_ID_BT_BM_READ_REMOTE_NAME_REQ
 * PARAMETERS
 *  bt_add      [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_read_remote_name_req_hdler(srv_bt_cm_bt_addr* dev_addr);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_read_remote_name_cnf_hdler
 * DESCRIPTION
 *  This function is to handle read remote name confirm
 * PARAMETERS
 *  msg         [IN]        inter layer message              
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_read_remote_name_cnf_hdler(void* msg);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_sdc_search_req_hdler
 * DESCRIPTION
 *  This function is to handle SDC search request and send MSG_ID_BT_BM_SERVICE_SEARCH_REQ
 * PARAMETERS
 *  bt_add          [IN]            bd addr
 *  sdap_len        [IN]           SDAP length
 *  sdap_uuid       [IN]           SDAP UUID
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_sdc_search_req_hdler(srv_bt_cm_bt_addr bt_add, U8 sdap_len, U16* sdap_uuid);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_sdc_search_ind_hdler
 * DESCRIPTION
 *  This function is to handle SDC search indication 
 * PARAMETERS
 *  msg         [IN]        inter layer message              
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_bt_cm_sdc_search_ind_hdler(void* msg);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_sdc_search_cnf_hdler
 * DESCRIPTION
 *  This function is to handle SDC search confirm
 * PARAMETERS
 *  msg         [IN]        inter layer message              
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_bt_cm_sdc_search_cnf_hdler(void* msg);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_link_connect_accept_ind_hdler
 * DESCRIPTION
 *  This function is to handle if reaching max number of paired device 
 * PARAMETERS
 *  msg     [IN]    msg structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_link_connect_accept_ind_hdler(void* msg);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_bond_req_hdler
 * DESCRIPTION
 *  This function is to handle bond request and send MSG_ID_BT_BM_BONDING_REQ
 * PARAMETERS
 *  bt_add          [IN]            bd addr
 *  sdap_len        [IN]           SDAP length
 *  sdap_uuid       [IN]          SDAP UUID
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_bond_req_hdler(srv_bt_cm_bt_addr bt_add, U8 sdap_len, U16* sdap_uuid);

MMI_BOOL srv_bt_cm_check_rejecting_state(void *bd_add);

/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_bond_ind_hdler
 * DESCRIPTION
 *  This function is to handle bond indication
 * PARAMETERS
 *  msg         [IN]        inter layer message              
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_bond_ind_hdler(void* msg);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_bond_cnf_hdler
 * DESCRIPTION
 *  This function is to handle bond confirm
 * PARAMETERS
 *  msg         [IN]        inter layer message              
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_bond_cnf_hdler(void* msg);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_debond_req_hdler
 * DESCRIPTION
 *  This function is to handle debond request and send MSG_ID_BT_BM_DELETE_TRUST_REQ
 * PARAMETERS
 *  dev_addr:    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_debond_req_hdler(srv_bt_cm_bt_addr* dev_addr);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_debond_cnf_hdler
 * DESCRIPTION
 *  This function is to handle debond confirm
 * PARAMETERS
 *  msg         [IN]        inter layer message              
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_debond_cnf_hdler(void* msg);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_passkey_ind_hdler
 * DESCRIPTION
 *  This function is to handle passkey indication
 * PARAMETERS
 *  msg         [IN]        inter layer message              
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_passkey_ind_hdler(void* msg);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_passkey_ind_rsp_hdler
 * DESCRIPTION
 *  This function is to handle passkey indication and send MSG_ID_BT_BM_PIN_CODE_RSP
 * PARAMETERS
 *  bt_add          [IN]            bd addr
 *  pin_len         [IN]            pin code length
 *  pin_code        [IN]           pin code
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_passkey_ind_rsp_hdler(srv_bt_cm_bt_addr bt_add, U8 pin_len, U8* pin_code);


#ifdef __MMI_BT_SIMPLE_PAIR__
/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_security_user_confirm_ind_hdler
 * DESCRIPTION
 *  This function is to handle the numeric comparison indication of secure simple pairing
 * PARAMETERS
 *  msg         [IN]       ilm message from lower layer      
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_security_user_confirm_ind_hdler(void* msg);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_security_user_confirm_rsp_hdler
 * DESCRIPTION
 *  This function is to respond the numeric comparison indication of secure simple pairing
 * PARAMETERS
 *  bt_add         [IN]        device address             
 *  accept         [IN]        end user response for the numeric comparison
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_security_user_confirm_rsp_hdler(srv_bt_cm_bt_addr bt_add, U8 accept);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_security_passkey_notify_ind_hdler
 * DESCRIPTION
 *  This function is to handle the passkey entry(notification) indication of secure simple pairing
 * PARAMETERS
 *  msg         [IN]       ilm message from lower layer      
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_security_passkey_notify_ind_hdler(void* msg);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_security_keypress_notify_ind_hdler
 * DESCRIPTION
 *  This function is to handle the passkey entry(notification) keypress indication of secure simple pairing
 *  MMI can use indication to display how many digits inputted from remote device
 * PARAMETERS
 *  msg         [IN]       ilm message from lower layer      
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_security_keypress_notify_ind_hdler(void* msg);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_security_keypress_notify_rsp_hdler
 * DESCRIPTION
 *  This function is to respond the passkey entry(notification) keypress indication of secure simple pairing
 *  to notify that MMI had updated the passkey entry(notification) screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
//void srv_bt_cm_security_keypress_notify_rsp_hdler(void);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_security_keypress_notify_cancel_req_hdler
 * DESCRIPTION
 *  This function is to respond the passkey entry(notification) keypress indication of secure simple pairing
 * PARAMETERS
 *  bt_add         [IN]        device address             
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_security_keypress_notify_cancel_req_hdler(srv_bt_cm_bt_addr bt_add);
#endif /* __MMI_BT_SIMPLE_PAIR__ */


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_block_active_link_req_hdler
 * DESCRIPTION
 *  This function is to release the existed active link after add this device to block list
 * PARAMETERS
 *  bt_add         [IN]        device address             
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_block_active_link_req_hdler(srv_bt_cm_bt_addr bt_add);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_block_active_link_cnf_hdler
 * DESCRIPTION
 *  This function is to handle the cnf of block active link request and invoke srv_bt_cm_block_list_update_req_hdler
 * PARAMETERS
 *  msg         [IN]       ilm message from lower layer      
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_block_active_link_cnf_hdler(void* msg);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_block_list_update_req_hdler
 * DESCRIPTION
 *  This function is to update the block list to BM of btstack
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_block_list_update_req_hdler(void);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_block_list_update_cnf_hdler
 * DESCRIPTION
 *  This function is to handle the cnf of updating block list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_block_list_update_cnf_hdler(void* msg);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_security_level_req_hdler
 * DESCRIPTION
 *  This function is to handle security level request and send MSG_ID_BT_BM_WRITE_AUTHENTICATION_MODE_REQ
 * PARAMETERS
 *  auth_flag       [IN]            authentication flag
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_security_level_req_hdler(MMI_BOOL auth_flag);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_security_level_cnf_hdler
 * DESCRIPTION
 *  This function is to handle security level confirm
 * PARAMETERS
 *  msg         [IN]        inter layer message              
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_security_level_cnf_hdler(void* msg);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_write_scanenable_mode_req_hdler
 * DESCRIPTION
 *  This function is to handle write scanenable mode request and send MSG_ID_BT_BM_WRITE_SCANENABLE_MODE_REQ
 * PARAMETERS
 *  connected_mode          [IN]            connected mode
 *  non_connected_mode      [IN]          non-connected mode
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_write_scanenable_mode_req_hdler(U8 connected_mode);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_write_scanenable_mode_cnf_hdler
 * DESCRIPTION
 *  This function is to handle write scanenable mode confirm
 * PARAMETERS
 *  msg         [IN]        inter layer message              
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_bt_cm_write_scanenable_mode_cnf_hdler(void* msg);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_link_state_ind_hdler
 * DESCRIPTION
 *  This function is to handle link state indication
 * PARAMETERS
 *  msg         [IN]        inter layer message              
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_link_state_ind_hdler(void* msg);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_allow_acl_link_establishment_req_hdler
 * DESCRIPTION
 *  This function is to handle allow ACL link establishment request and send MSG_ID_BT_BM_LINK_ALLOW_REQ
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_allow_acl_link_establishment_req_hdler(void);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_allow_acl_link_establishment_cnf_hdler
 * DESCRIPTION
 *  This function is to handle allow ACL link establishment confirm
 * PARAMETERS
 *  msg         [IN]        inter layer message              
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_bt_cm_allow_acl_link_establishment_cnf_hdler(void* msg);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_disallow_acl_link_establishment_cnf_hdler
 * DESCRIPTION
 *  This function is to handle disallow ACL link establishment confirm
 * PARAMETERS
 *  msg         [IN]        inter layer message              
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_bt_cm_disallow_acl_link_establishment_cnf_hdler(void* msg);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_copy_n_utf8_chars
 * DESCRIPTION
 *  to copy n chars to dest string
 * PARAMETERS
 *  dest                 [IN]        dest buffer 
 *  size_of_dest     [IN]        max size of dest buffer
 *  src                   [IN]        src buffer 
 *  charNum          [IN]        number of char to be copied
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_copy_n_utf8_chars(U8* dest, U16 size_of_dest, U8* src, U8 char_num);


/*****************************************************************************
 * <GROUP Ext_other>
 * FUNCTION
 *  srv_bt_cm_deactivate_profiles_req
 * DESCRIPTION
 *  This function is to process deactivate profiles request and invoke the deactivate function of profiles
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_deactivate_profiles(void);


/*********************************************************************************/
typedef struct
{
    S32                srv_hd;
    srv_bt_cm_notifier notifier;
    U32                event_mask;
    void*              user_data;
} srv_bt_cm_hdlr_struct;

#ifndef __BCM_SUPPORT__
typedef enum
{
    EVENT_ID_BT_CM_START = SRV_BTCM_BASE + 1,
    EVENT_ID_BT_CM_POWER_ON,
    EVENT_ID_BT_CM_SET_AUTHORIZE,
    //EVENT_ID_BT_CM_NOTIFY_CONNECTOR,
    EVENT_ID_BT_CM_END_OF_ENUM
} srv_bt_cm_post_event_enum;
#endif

typedef struct
{
    MMI_EVT_PARAM_HEADER
    U32 event;
    void* data_p;
} srv_bt_cm_post_event_struct;

mmi_ret srv_bt_cm_post_event_proc(mmi_event_struct* para);

void srv_bt_cm_notify(U32 event, void* para);
void srv_bt_cm_post_notify(U32 event, void *para);

//U32 srv_bt_cm_get_paired_dev_index(const srv_bt_cm_bt_addr* dev_addr);

U8 srv_bt_cm_get_action_item_index(void);

void srv_bt_cm_nvram_write_info(U16 LID, void* para);

//U32 srv_bt_cm_get_dev_index(const srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_dev_type_enum dev_type);


const srv_bt_cm_dev_struct* srv_bt_cm_get_dev_info_by_addr(
    const srv_bt_cm_bt_addr* dev_addr,
    srv_bt_cm_dev_type_enum dev_type);


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_dev_add_int
 * DESCRIPTION
 *  this function is to add a device into corresponding device list
 *  according to device type
 * PARAMETERS
 *  dev     :    [IN]    device
 *  dev_type:    [IN]    device type
 *  
 * RETURNS
 *  
 ******************************************************************************/
S32 srv_bt_cm_dev_add_int(const srv_bt_cm_dev_struct* dev, srv_bt_cm_dev_type_enum dev_type);


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_dev_delete_int
 * DESCRIPTION
 *  this function is to delete a device according to device type
 * PARAMETERS
 *  dev_addr:    [IN]    device address
 *  dev_type:    [IN]    device type
 *  
 * RETURNS
 *  S32 return the delete device result
 ******************************************************************************/
S32 srv_bt_cm_dev_delete_int(const srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_dev_type_enum dev_type);


#ifdef __BT_BOND_CANCEL__
void srv_bt_cm_bond_cancel_req_hdler(srv_bt_cm_bt_addr* dev_addr);


void srv_bt_cm_bond_cancel_cnf_hdler(void* msg);
#endif

mmi_ret srv_bt_cm_uart_hdlr(mmi_event_struct *evt);

#ifdef __MMI_BT_DIALER_SUPPORT__
void srv_bt_cm_remote_name_ind_hdler(void* msg);
void srv_bt_cm_discovery_update_ind_hdler(void* msg);

void srv_bt_cm_dialer_init();

#endif

#endif /* __MMI_BT_SUPPORT__ */

#endif /* BT_CM_SRV_PROT_H */
