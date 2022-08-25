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
 * bcm_struct.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   struct of local parameter for hfg adp sap
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
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef BCM_STRUCT_H
#define BCM_STRUCT_H

/* RHR ADD */
#include "bt_dm_struct.h"
#include "bluetooth_bm_struct.h"
#include "app_ltlcom.h"
#include "kal_general_types.h"
#include "bluetooth_struct.h"
#include "bluetooth_pbapc_struct.h"
#include "ps_public_enum.h"
/* RHR ADD end */
#define BCM_MAX_DEVICE_LIST 11

#if defined(__BT_GATTC_PROFILE__) || defined(__BT_GATTS_PROFILE__) 

#include "bt_types.h"
#include "btostypes_int.h"
//#include "bluetooth_gatts_struct.h"
//#include "bluetooth_gattc_struct.h"
    

#define MAX_L4_GATT_USERID_LEN (16 * 2)// "AB" =>  0xAB
#define MAX_L4_GATT_CONN_NUM 255
#define L4_BT_ADDR_LEN 6
#define MAX_L4_GATT_UUID_LEN (16 * 2)// "AB" =>  0xAB
#define MIN_L4_GATT_UUID_LEN (2 * 2)// "AB" =>  0xAB
#define MAX_L4_GATT_SERVICE_HANDLE 65535
#define MAX_L4_GATT_SERVICE_HANDLE_NUM 65535
#define MAX_L4_GATT_INST_NUM 255
#define MAX_L4_GATT_TRANSPORT_NUM 2
#define MAX_L4_GATT_TRANSACT_NUM 65535
#define MAX_L4_GATT_C_USER 10
#define MAX_L4_GATT_S_USER 10
#define MAX_L4_GATT_USER (MAX_L4_GATT_C_USER+MAX_L4_GATT_S_USER)
#define MAX_L4_GATT_ADV_INTERVAL_RANGE 16384
#define MAX_L4_GATT_CONN_INTERVAL_RANGE 3200
#define MAX_L4_GATT_CONN_LATENCY_RANGE 499



typedef enum{
	L4_GATT_ROLE_SERVER = 1,
	L4_GATT_ROLE_CLIENT
}L4_GATT_ROLE_ENUM;

typedef struct{
	kal_int16 conn_id;
	kal_uint8 conn_ctx;
	kal_bool is_used;
	void* reg_ctx;
	kal_uint8 bt_addr[L4_BT_ADDR_LEN];
}l4c_bcm_gatt_conn_info_struct;

typedef struct{
	kal_uint8 user_id[(MAX_L4_GATT_USERID_LEN+1)/2];
	kal_uint8 user_id_len;
	void* reg_ctx;
	kal_uint8 src_id;
	kal_bool is_used;
	L4_GATT_ROLE_ENUM role;
}l4c_bcm_gatt_srcid_userid_regctx_map_struct;


#endif

/***************************************************************************** 
* Definations
*****************************************************************************/
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 dual_sim_uart_setting;
    kal_uint8 on_off;
} bcm_power_onoff_req_struct;
    
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 result;
} bcm_power_onoff_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 name_len;
    kal_uint8 name[BTBM_ADP_MAX_NAME_LEN];
} bcm_write_local_name_req_struct;
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
} bcm_read_local_name_req_struct;
    
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 result;
} bcm_write_local_name_cnf_struct;
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 result;
    kal_uint8 name_len;
    kal_uint8 name[BTBM_ADP_MAX_NAME_LEN];
} bcm_read_local_name_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    btbm_bd_addr_t bd_addr;
} bcm_write_local_addr_req_struct;
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
} bcm_read_local_addr_req_struct;
    
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 result;
} bcm_write_local_addr_cnf_struct;
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 result;
    btbm_bd_addr_t bd_addr;
} bcm_read_local_addr_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 modenotconnected;
    kal_uint8 visable_time;
} bcm_write_scanenable_mode_req_struct;
    
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 result;
} bcm_write_scanenable_mode_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 op;//0, set; 1,read;
    kal_uint8 urc_interval;
    kal_uint8 inquiry_length;
    kal_uint8 inquiry_number;
    kal_uint32 cod;
} bcm_discovery_para_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
} bcm_discovery_struct;
    
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
    kal_uint8 op;//0, set; 1,read;
    kal_uint8 urc_interval;
    kal_uint8 inquiry_length;
    kal_uint8 inquiry_number;
    kal_uint32 cod;
} bcm_discovery_para_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 result;
    kal_uint8 total_number;
} bcm_discovery_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
} bcm_discovery_cancel_struct;
    
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 result;
    kal_uint8 total_number;
} bcm_discovery_cancel_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    btbm_bd_addr_t bd_addr;
} bcm_read_remote_name_req_struct;
    
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 result;
    btbm_bd_addr_t bd_addr;
    kal_uint8 name_len;
    kal_uint8 name[BTBM_ADP_MAX_NAME_LEN];
} bcm_read_remote_name_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    btbm_bd_addr_t bd_addr;
    kal_uint8 timeout;
} bcm_bonding_req_struct;
    
/* bond result event struct */
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 result;
    btbm_bd_addr_t dev_addr; /* device address */
    kal_uint8 name_len;
    kal_uint8 name[BTBM_ADP_MAX_NAME_LEN];
    kal_uint8  display_numeric;         /* whether display numeric */
    kal_uint8 enable_16digits_pin_code; /* whether enable 16 digits pin code */
    kal_uint8  password[16];
    kal_uint8  password_len;
} bcm_bond_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 accept;
    kal_uint8  password[16];
    kal_uint8  password_len;
} bcm_bonding_rsp_req_struct;
    
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 result;
    btbm_bd_addr_t bd_addr;
} bcm_bonding_rsp_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    btbm_bd_addr_t bd_addr;
} bcm_service_search_req_struct;
    
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 result;
    btbm_bd_addr_t bd_addr;
    kal_uint64 support_profile_map;
} bcm_service_search_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 sec_mode;
    kal_uint8 enc_mode;
} bcm_write_authentication_mode_req_struct;
    
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 result;
    kal_uint8 sec_mode;
    kal_uint8 enc_mode;
}  bcm_write_authentication_mode_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
} bcm_read_authentication_mode_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 result;
    kal_uint8 sec_mode;
    kal_uint8 enc_mode;
}  bcm_read_authentication_mode_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 op;
    btbm_bd_addr_t bd_addr;
} bcm_dev_list_op_req_struct;
    
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 op;
    kal_uint8 result;
    kal_uint8 list_number;
    btbm_bd_addr_t bd_addr[BCM_MAX_DEVICE_LIST];
} bcm_dev_list_op_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    btbm_bd_addr_t bd_addr;
    kal_uint32 profile;
} bcm_profile_state_query_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8  result;
    btbm_bd_addr_t bd_addr;
    kal_uint32 profile;
    kal_uint8 profile_state;
} bcm_profile_state_query_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
} bcm_cm_state_query_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8  result;
    kal_uint8 cm_state;
} bcm_cm_state_query_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 op;
    kal_int8  sniff_level;
} bcm_sniff_para_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8  result;
    kal_uint8 op;
    kal_int8  sniff_level;
} bcm_sniff_para_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    btbm_bd_addr_t bd_addr;
} bcm_rssi_req_struct;
    
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 result;
    btbm_bd_addr_t bd_addr;
    kal_int16 rssi;
} bcm_rssi_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint64 profile_map;
} bcm_profile_act_req_struct;
    
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 result;
    kal_uint64 acted_profile_map;
} bcm_profile_act_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 op;
    btbm_bd_addr_t bd_addr;
    kal_uint32 profile;
    kal_uint8 role;
} bcm_profile_conn_req_struct;
    
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 op;
    btbm_bd_addr_t bd_addr;
    kal_uint32 profile;
    kal_uint8 role;
    kal_uint8 result;
} bcm_profile_conn_cnf_struct;



typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint32  event;
    kal_uint8  result;
    kal_uint8  *para;
    kal_uint16  para_len;
} bcm_event_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint32 profile; 
    kal_uint32 event;
    kal_uint8  result;
    kal_uint8  *para;
    kal_uint16  para_len;
} bcm_profile_event_ind_struct;


typedef struct
{
    btbm_bd_addr_t bd_addr;
    kal_uint8 name_len;
    kal_uint8 name[BTBM_ADP_MAX_NAME_LEN];
} bcm_discovery_result_ind_struct;


typedef struct
{
    kal_int32 result;                 /* inquiry complete result */
    kal_bool is_cancelled;      /* MMI_TRUE: cancelled by MMI  * MMI_FALSE: not cancelled by MMI */
} bcm_inquiry_complete_struct;


/* security user confirm event struct */
typedef struct
{
    kal_uint8 name_len;
    kal_uint8 name[BTBM_ADP_MAX_NAME_LEN];
    btbm_bd_addr_t dev_addr; /* device address */
    kal_uint8 display_numeric;         /* whether display numeric */
    kal_uint8  password[16];
    kal_uint8  password_len;
} bcm_security_user_confirm_struct;


/* security passkey event struct */
typedef struct
{
    kal_uint8 name_len;
    kal_uint8 name[BTBM_ADP_MAX_NAME_LEN];
    btbm_bd_addr_t dev_addr; /* device address */
    kal_uint8  password[16];
    kal_uint8  password_len;
}bcm_security_passkey_struct;


typedef struct
{
    btbm_bd_addr_t dev_addr; /* device address */
    kal_uint8 num_digit;               /* numeic digit */
} bcm_security_keypress_struct;


/* pair indication struct */
typedef struct
{
    kal_uint8 name_len;
    kal_uint8 name[BTBM_ADP_MAX_NAME_LEN];
    kal_uint8 enable_16digits_pin_code;  /* whether enable 16 digits pin code */
    btbm_bd_addr_t dev_addr;   /* device address */
} bcm_pair_ind_struct;


/* paire result event struct */
typedef struct
{
    btbm_bd_addr_t dev_addr; /* device address */
    kal_int32  result;                 /* MMI_TRUE: success, MMI_FALSE: fail */
    kal_bool is_first_pair;     /* MMI_TRUE: first pair, MMI_FALSE: not first pair */
} bcm_pair_res_struct;


typedef struct
{
    btbm_bd_addr_t  dev_addr;/* device address */
    kal_uint32  profile_id;             /* profile ID */
    kal_int32  result;                 /* connect result */
} bcm_conn_res_struct;


/* mydevice delete event struct */
typedef struct
{
    kal_bool result;            /* my device delete result */
} bcm_mydev_del_struct;

typedef struct
{
    kal_bool result;            /* activate result */
} bcm_activate_struct;


typedef struct
{
    kal_bool result;            /* deactivate result */
} bcm_deactivate_struct;


typedef struct
{
    kal_bool result;            /* activate result */
} bcm_begin_activate_struct;


typedef struct
{
    kal_bool result;            /* deactivate result */
} bcm_begin_deactivate_struct;


typedef struct
{
    btbm_bd_addr_t dev_addr; /* device address */
    kal_int32 result;                 /* MMI_TRUE: success */

    //kal_bool is_first_bond;  /* MMI_TRUE: first pair, MMI_FALSE: not first pair */
} bcm_bond_res_struct;


typedef struct
{
    btbm_bd_addr_t dev_addr; /* device address */
    kal_uint32  profile_id;              /* profile ID */
    kal_bool passive;
} bcm_disconnect_ind_struct;


typedef struct
{
    btbm_bd_addr_t dev_addr;/* device address */
    kal_bool result;            /* release all device result */
} bcm_release_all_struct;


typedef struct
{
    kal_int32 result;                 /* release all service list result */
} bcm_refresh_service_list_struct;


typedef struct
{
    kal_bool result;            /* set authorize result */
} bcm_set_authorize_struct;


typedef struct
{
    kal_int32 srv_hd;                 /* service handle*/
    void* user_data;            /* user data */
    kal_bool result;            /* unblock event */
} bcm_unblock_struct;


typedef struct
{
    kal_bool result;            /* set visibility result */
    kal_bool is_from_mmi;       /* to identify whether the action is initiated by MMI
                                 * or change the visibility just by CM service due to A2DP connected */
} bcm_set_visibility_struct;


typedef struct
{
    kal_int32 result;                 /* set name result */
} bcm_set_name_struct;


typedef struct
{
    kal_int32 result;                 /* set authentication result */
} bcm_set_authentication_struct;


typedef struct
{
    kal_int32 srv_hd;                 /* service handle*/
    void* user_data;            /* user data */
    kal_bool result;            /* set SIMAP result */
} bcm_set_simap_struct;


typedef struct
{
    kal_bool result;            /* sco indication result */
} bcm_sco_ind_struct;

typedef struct
{
    btbm_bd_addr_t dev_addr; /* device address */
} bcm_read_remote_dev_name_struct;


typedef struct
{
    kal_int32 result;                 /* set limit discoverable mode result */
} bcm_set_limit_discoverable_mode_struct;


typedef struct
{
    kal_int32 result;                 /* 1: chip available, 0: chip not available */
} bcm_chip_detect_struct;


typedef struct
{
    kal_bool result;            /* bond cancel result */
} bcm_bond_cancel_result;

typedef struct
{
    kal_uint8 name_len;
    kal_uint8 name[BTBM_ADP_MAX_NAME_LEN];
    btbm_bd_addr_t dev_addr;
}bcm_spp_evt_authorize_struct;


typedef struct{
 kal_bool ret;
}bcm_spp_evt_connect_struct;


typedef struct
{
    btbm_bd_addr_t dev_addr;
}bcm_spp_evt_disconnect_struct;





/**********************************************************************************/
typedef enum
{
    SRV_BT_CM_EVENT_ACTIVATE                    = 0x00000001, /* activate */
    SRV_BT_CM_EVENT_DEACTIVATE                  = 0x00000002, /* deactivate */
    SRV_BT_CM_EVENT_INQUIRY_IND                 = 0x00000004, /* inquiry indication */
    SRV_BT_CM_EVENT_INQUIRY_COMPLETE            = 0x00000008, /* inquiry complete */

    SRV_BT_CM_EVENT_BEGIN_ACTIVATE              = 0x00000010, // begin activate
    SRV_BT_CM_EVENT_BEGIN_DEACTIVATE            = 0x00800000, // begin deactivate

    SRV_BT_CM_EVENT_BOND_RES                    = 0x00000020, /* bond result */
    SRV_BT_CM_EVENT_PAIR_IND                    = 0x00000040, /* pair indication */
    SRV_BT_CM_EVENT_PAIR_RES                    = 0x00000080, /* pair result */
//#ifdef __MMI_BT_SIMPLE_PAIR__
    SRV_BT_CM_EVENT_SECURITY_USER_CONFIRM       = 0x00000100, /* security user confirm */
    SRV_BT_CM_EVENT_SECURITY_PASSKEY_NOTIFY     = 0x00000200, /* security passkey notify */
    SRV_BT_CM_EVENT_SECURITY_KEYPRESS_NOTIFY    = 0x00000400, /* security keypress notify */
//#endif /* __MMI_BT_SIMPLE_PAIR__ */
    SRV_BT_CM_EVENT_CONNECT_REQ                 = 0x00000800, /* connect request */
    SRV_BT_CM_EVENT_CONNECT_RES                 = 0x00001000, /* connect result */
    SRV_BT_CM_EVENT_DISCONNECT_IND              = 0x00002000, /* disconnect indication */
    SRV_BT_CM_EVENT_RELEASE_ALL_CONN            = 0x00004000, /* release all connection */
    SRV_BT_CM_EVENT_REFRESH_PROFILE             = 0x00008000, /* refresh profile */
//#ifdef __MMI_BT_AUTHORIZE__
    SRV_BT_CM_EVENT_SET_AUTHORIZE               = 0x00010000, /* set authorize */
    SRV_BT_CM_EVENT_UNBLOCK                     = 0x00020000, /* unblock device */
//#endif  /* __MMI_BT_AUTHORIZE__ */
    SRV_BT_CM_EVENT_MYDEV_DEL                   = 0x00040000, /* mydevice delete */
    //SRV_BT_CM_EVENT_MYDEV_DEL_ALL             = 0x00080000,
    SRV_BT_CM_EVENT_SET_VISIBILITY              = 0x00100000, /* set visibility */
    SRV_BT_CM_EVENT_SET_NAME                    = 0x00200000, /* set name */
    SRV_BT_CM_EVENT_SET_AUTHENTICATION          = 0x00400000, /* set authentication */
//#ifdef __MMI_SIMAP_SUPPORT__
    SRV_BT_CM_EVENT_SET_SIMAP                   = 0x01000000, /* set SIMAP */
//#endif  /* __MMI_SIMAP_SUPPORT__ */
    SRV_BT_CM_EVENT_SCO_IND                     = 0x02000000, /* sco indication */
    SRV_BT_CM_EVENT_PANIC_IND                   = 0x04000000, /* panic inidation */
    SRV_BT_CM_EVENT_READ_REMOTE_DEV_NAME        = 0x08000000, /* read remote device */
    SRV_BT_CM_EVENT_SET_LIMIT_DISCOVERABLE_MODE = 0x10000000, /* set limit discoverable mode */
    SRV_BT_CM_EVENT_CHIP_DETECT                 = 0x20000000, /* chip auto detect */

//#ifdef __BT_BOND_CANCEL__
    SRV_BT_CM_EVENT_BOND_CANCEL                 = 0x40000000  /* bond cancel */
//#endif

    //SRV_BT_CM_EVENT_NOTIFY_CONNECTOR            = 0x40000000,
    //SRV_BT_CM_EVENT_ACL_LINK_EXCEED_MAX_NUM     = 0x20000000
} srv_bt_cm_event_enum;

/*spp srv for app event enum*/
typedef enum{
    SRV_SPP_EVENT_START = 0x0001,
    SRV_SPP_EVENT_BIND_FAIL = 0x0002,
    SRV_SPP_EVENT_AUTHORIZE = 0x0004,
    SRV_SPP_EVENT_CONNECT = 0x0008,
    SRV_SPP_EVENT_SCO_CONNECT = 0x0010,
    SRV_SPP_EVENT_READY_TO_WRITE = 0x0020,
    SRV_SPP_EVENT_READY_TO_READ = 0x0040,
    SRV_SPP_EVENT_DISCONNECT = 0x0080,
    SRV_SPP_EVENT_SCO_DISCONNECT = 0x0100,
    SRV_SPP_EVENT_END
}srv_spp_event_enum;

/* cm enum for external visitor */
typedef enum{
    BCM_CM_EXT_STATE_STATE_START = 0x0001,
    BCM_CM_EXT_STATE_READY, // power on finished.
    BCM_CM_EXT_STATE_PAIRING,
    BCM_CM_EXT_STATE_INQUIRING,
    BCM_CM_EXT_STATE_CONNECTING,
    BCM_CM_EXT_STATE_CONNECTED,
    BCM_CM_EXT_STATE_NUKNOWN,
    BCM_CM_EXT_STATE_END
}srv_bcm_ext_cm_state_enum;


/* spp state enum for external visitor*/
typedef enum{
    BCM_SPP_EXT_STATE_START = 0x0001,
    BCM_SPP_EXT_STATE_IDLE,
    BCM_SPP_EXT_STATE_ACTIVATE,
    BCM_SPP_EXT_STATE_AUTHORIZING,
    BCM_SPP_EXT_STATE_DISCONNECTING,
    BCM_SPP_EXT_STATE_DEACTIVATING,
    BCM_SPP_EXT_STATE_END
}srv_bcm_ext_spp_state_enum;

#ifdef __BT_OPP_PROFILE__

#define BCM_OPPC_MAX_SEND_FILES 5
#define BCM_OPP_MAX_FILE_PATH_LEN 128
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8  total_files;
    btbm_bd_addr_t addr;
    kal_uint16 * file_path[BCM_OPPC_MAX_SEND_FILES];
}bcm_opp_push_obj_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool result;
    btbm_bd_addr_t addr;
    kal_uint16 * file_path;
}bcm_opp_recv_obj_res_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    btbm_bd_addr_t addr;
}bcm_opp_abort_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool result;
}bcm_opp_abort_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_bool result;
    kal_uint8 total_files;
    btbm_bd_addr_t addr;
    kal_uint16* file_path;
}bcm_opp_push_cnf_struct;

#define BCM_BT_DEVICE_NAME_LEN 56
#define BCM_BT_OBJ_NAME_LEN 128
#define BCM_BT_OBJ_MIME_LEN 80

typedef struct
{
    LOCAL_PARA_HDR
    btbm_bd_addr_t addr;
    kal_uint8 dev_name[BCM_BT_DEVICE_NAME_LEN];
    kal_uint8 obj_mime[BCM_BT_OBJ_MIME_LEN];
    kal_uint16 obj_name[BCM_BT_OBJ_NAME_LEN];
}bcm_opp_recv_obj_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool result;
    btbm_bd_addr_t addr;
    kal_uint16 obj_name[BCM_BT_OBJ_NAME_LEN];
}bcm_opp_recv_obj_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool result;
    kal_uint32 cmd_id;
}bcm_opp_result_ind_struct;

#endif /*__BT_OPP_PROFILE__*/


#ifdef __BT_PBAP_CLIENT__

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    btbm_bd_addr_t addr;
    kal_uint32 folder;
    kal_uint32 MaxListCount;
    kal_uint32 ListStartOffset;
    kal_uint32 searchAttr;
    kal_uint8 searchVal[MAX_PBAP_CLIENT_SEARCH_VALUE_LENGTH + 1];
}bcm_pbap_get_list_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_bool result;
    kal_uint32 cmd_id;
    btbm_bd_addr_t addr;
    kal_uint16 *path;
}bcm_pbap_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    btbm_bd_addr_t addr;
    kal_uint32 folder;
    kal_uint8 obj[PBAP_MAX_NAME_LEN + 1];
    kal_uint32 filter;
}bcm_pbap_pull_entry_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    btbm_bd_addr_t addr;
    kal_uint32 folder;
    kal_uint32 MaxListCount;
    kal_uint32 ListStartOffset;
    kal_uint32 filter;
}bcm_pbap_dl_ch_req_struct;



typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool result;
    kal_uint32 cmd_id;
}bcm_pbap_result_ind_struct;


#endif /*__BT_PBAP_CLIENT__*/

#ifdef __BCM_PBAP_SERVER__

//need refine
#define SRV_PBAP_EVENT_AUTHORIZE_NOTIFY  0x0004

typedef struct
{
    U32 conn_id;                    
    btbm_bd_addr_t bt_addr;      
    U8 dev_name[80];
} bcm_pbap_auth_notify_struct;

#endif

#if defined(__BT_HFG_PROFILE__)
typedef struct
{
        LOCAL_PARA_HDR
        kal_uint8 src_id;
        kal_uint8 act;
}bcm_hfg_set_audio_path_req_struct;

typedef struct
{
        LOCAL_PARA_HDR
        kal_uint8 src_id;
        kal_uint8 result;
}bcm_hfg_set_audio_path_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
} bcm_hfg_read_audio_path_req_struct;
    
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 result;
    kal_uint8 value;
} bcm_hfg_read_audio_path_cnf_struct;

typedef struct
{

    LOCAL_PARA_HDR 
    kal_uint8 volume_type;
    kal_uint8 volume_level;
} bcm_change_volume_ind_struct;

#endif /*#if defined(__BT_HFG_PROFILE__)*/
#ifdef __BT_A2DP_PROFILE__

#define MAX_A2DP_FILE_NAME 512
typedef struct 
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
	kal_uint8 op;
	btbm_bd_addr_t bt_addr; 
	kal_wchar file_name[MAX_A2DP_FILE_NAME];
	kal_uint16 sample_rate;
	kal_uint8 stereo;

}bcm_a2dp_reconfig_start_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}bcm_a2dp_reconfig_start_cnf_struct;

#endif

#ifdef __BT_AVRCP_PROFILE__
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 command;
	kal_uint8 key_events;
}bcm_avrcp_cmd_ind_struct;

#endif

#ifdef __BT_GATTS_PROFILE__

/* MSG_ID_BCM_GATTS_REGISTER_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    void *app_ctx;   
    kal_uint8 src_id;
    /* user_ctx will be carried in register cnf to identify AP which submit registration */
    U8 user_id[16];
} bcm_gatts_register_req_struct;

/* MSG_ID_BCM_GATTS_REGISTER_CNF */
typedef struct
{
    LOCAL_PARA_HDR	
    kal_uint8 src_id;
    void *app_ctx;           
    /* reg_ctx used by registered AP as an identifier */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
    /* user_ctx in register request. Used to identify AP which subnit the registration */
    U8 user_id[16];
} bcm_gatts_register_cnf_struct;

/* MSG_ID_BT_GATTS_DEREGISTER_REQ */
typedef struct
{
    LOCAL_PARA_HDR		
    kal_uint8 src_id;
    /* identifier of registered AP */
    void *reg_ctx;
} bcm_gatts_deregister_req_struct;

/* MSG_ID_BT_GATTS_DEREGISTER_CNF */
typedef struct
{
    LOCAL_PARA_HDR	
    kal_uint8 src_id;
    void *app_ctx;           
    /* reg_ctx used by registered AP as an identifier */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
} bcm_gatts_deregister_cnf_struct;

/* MSG_ID_BT_GATTS_CONNECT_REQ */
typedef struct
{
    LOCAL_PARA_HDR	
    kal_uint8 src_id;
    /* identifier of registered AP */
    void *reg_ctx;
    /* Address of discovered device */
    U8 bd_addr[6];
    /* 0 : non-direct connect, otherwise : direct */
    U8 direct;
} bcm_gatts_connect_req_struct;

/* MSG_ID_BT_GATTS_CONNECT_CNF */
typedef struct
{
    LOCAL_PARA_HDR		
    kal_uint8 src_id;
    void *app_ctx;           
    /* identifier of registered AP */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
    /* identifier of connection if result is success */
    void *conn_ctx;
    /* Address of discovered device */
    U8 bd_addr[6];
    /* Role of local device */
    U8 LocalRole;
} bcm_gatts_connect_cnf_struct;

/* MSG_ID_BT_GATTS_CONNECTED_IND */
typedef struct
{
    LOCAL_PARA_HDR	
    kal_uint8 src_id;
    void *app_ctx;           
    /* identifier of registered AP */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
    /* identifier of connection */
    void *conn_ctx;
    /* Address of discovered device */
    U8 bd_addr[6];
    /* Role of local device */
    U8 LocalRole;
} bcm_gatts_connected_ind_struct;

/* MSG_ID_BT_GATTS_DISCONNECT_REQ */
typedef struct
{
    LOCAL_PARA_HDR
		
    kal_uint8 src_id;
    /* identifier of registered AP */
    void *reg_ctx;
    /* identifier of connection */
    void *conn_ctx;
    /* Address of discovered device */
    U8 bd_addr[6];
} bcm_gatts_disconnect_req_struct;

/* MSG_ID_BT_GATTS_DISCONNECT_CNF */
typedef struct
{
    LOCAL_PARA_HDR
		
    kal_uint8 src_id;
    void *app_ctx;           
    /* identifier of registered AP */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
    /* identifier of connection */
    void *conn_ctx;
    /* Address of discovered device */
    U8 bd_addr[6];
} bcm_gatts_disconnect_cnf_struct;

/* MSG_ID_BT_GATTS_DISCONNECTED_IND */
typedef struct
{
    LOCAL_PARA_HDR
		
    kal_uint8 src_id;
    void *app_ctx;           
    /* identifier of registered AP */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
    /* identifier of connection */
    void *conn_ctx;
    /* Address of discovered device */
    U8 bd_addr[6];
    /* TRUE: The last disconnect ind */
    U8 LastInd;
} bcm_gatts_disconnected_ind_struct;

/* MSG_ID_BT_GATTS_LISTEN_REQ */
typedef struct
{
    LOCAL_PARA_HDR
		
    kal_uint8 src_id;
    /* identifier of registered AP */
    void *reg_ctx;
    BOOL start;
} bcm_gatts_listen_req_struct;

/* MSG_ID_BT_GATTS_LISTEN_CNF */
typedef struct
{
    LOCAL_PARA_HDR
		
    kal_uint8 src_id;
    void *app_ctx;          
    /* identifier of registered AP */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
} bcm_gatts_listen_cnf_struct;

/* MSG_ID_BT_GATTS_ADD_SERVICE_REQ */
typedef struct
{
    LOCAL_PARA_HDR
		
    kal_uint8 src_id;
    /* identifier of registered AP */
    void *reg_ctx;
    /* Service uuid */
    GATT_SVC_UUID uuid;
    /* number of handles needed */
    U16 num_handles;
} bcm_gatts_add_service_req_struct;

/* MSG_ID_BT_GATTS_ADD_SERVICE_CNF */
typedef struct
{
    LOCAL_PARA_HDR
		
    kal_uint8 src_id;
    void *app_ctx;           
    /* identifier of registered AP */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
    /* Service uuid */
    GATT_SVC_UUID uuid;
    /* handle of added service */
    ATT_HANDLE service_handle;
} bcm_gatts_add_service_cnf_struct;

/* MSG_ID_BT_GATTS_ADD_INCL_SERVICE_REQ */
typedef struct
{
    LOCAL_PARA_HDR
		
    kal_uint8 src_id;
    /* identifier of registered AP */
    void *reg_ctx;
    /* Service uuid */
    ATT_HANDLE service_handle;
    /* service handle of service to be included */
    ATT_HANDLE incl_service_handle;
} bcm_gatts_add_incl_service_req_struct;

/* MSG_ID_BT_GATTS_ADD_INCL_SERVICE_CNF */
typedef struct
{
    LOCAL_PARA_HDR
		
    kal_uint8 src_id;
    void *app_ctx;           
    /* identifier of registered AP */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
    /* Service uuid */
    ATT_HANDLE service_handle;
    /* handle of incl. service record in service specified by service_uuid */
    ATT_HANDLE incl_service_handle;
} bcm_gatts_add_incl_service_cnf_struct;

/* MSG_ID_BT_GATTS_ADD_CHAR_REQ */
typedef struct
{
    LOCAL_PARA_HDR
		
    kal_uint8 src_id;
    /* identifier of registered AP */
    void *reg_ctx;
    /* Service handle */
    ATT_HANDLE service_handle;
    ATT_UUID char_uuid;
    /* properties defined in char declaration */
    U32 properties;
    /* Attribute permission */
    U32 permission;
} bcm_gatts_add_char_req_struct;

/* MSG_ID_BT_GATTS_ADD_CHAR_CNF */
typedef struct
{
    LOCAL_PARA_HDR

	
    kal_uint8 src_id;
    void *app_ctx;           
    /* identifier of registered AP */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
    /* uuid of added char */
    ATT_UUID char_uuid;
    /* Service handle */
    ATT_HANDLE service_handle;
    /* handle of char value not handle of char declaration */
    ATT_HANDLE char_handle;
} bcm_gatts_add_char_cnf_struct;

/* MSG_ID_BT_GATTS_ADD_DESCR_REQ */
typedef struct
{
    LOCAL_PARA_HDR
		
    kal_uint8 src_id;
    /* identifier of registered AP */
    void *reg_ctx;
    /* Service handle */
    ATT_HANDLE service_handle;
    /* uuid of descr to be added */
    ATT_UUID descr_uuid;
    /* Attribute permission */
    U32 permission;
} bcm_gatts_add_descr_req_struct;

/* MSG_ID_BT_GATTS_ADD_DESCR_CNF */
typedef struct
{
    LOCAL_PARA_HDR
		
    kal_uint8 src_id;
    void *app_ctx;           
    /* identifier of registered AP */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
    /* uuid of added char */
    ATT_UUID descr_uuid;
    /* Service handle */
    ATT_HANDLE service_handle;
    /* handle of char value not handle of char declaration */
    ATT_HANDLE descr_handle;
} bcm_gatts_add_descr_cnf_struct;

/* MSG_ID_BT_GATTS_START_SERVICE_REQ */
typedef struct
{
    LOCAL_PARA_HDR
		
    kal_uint8 src_id;
    /* identifier of registered AP */
    void *reg_ctx;
    /* Service handle */
    ATT_HANDLE service_handle;
    /* transport to start service. 0 : LE, 1 : BREDR, 2 : Dual */
    U8 transport;
} bcm_gatts_start_service_req_struct;

/* MSG_ID_BT_GATTS_START_SERVICE_CNF */
typedef struct
{
    LOCAL_PARA_HDR
		
    kal_uint8 src_id;
    void *app_ctx;           
    /* identifier of registered AP */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
    /* Service handle */
    ATT_HANDLE service_handle;
} bcm_gatts_start_service_cnf_struct;

/* MSG_ID_BT_GATTS_STOP_SERVICE_REQ */
typedef struct
{
    LOCAL_PARA_HDR
		
    kal_uint8 src_id;
    /* identifier of registered AP */
    void *reg_ctx;
    /* Service handle */
    ATT_HANDLE service_handle;
} bcm_gatts_stop_service_req_struct;

/* MSG_ID_BT_GATTS_STOP_SERVICE_CNF */
typedef struct
{
    LOCAL_PARA_HDR
		
    kal_uint8 src_id;
    void *app_ctx;           
    /* identifier of registered AP */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
    /* Service handle */
    ATT_HANDLE service_handle;
} bcm_gatts_stop_service_cnf_struct;

/* MSG_ID_BT_GATTS_DELETE_SERVICE_REQ */
typedef struct
{
    LOCAL_PARA_HDR
		
    kal_uint8 src_id;
    /* identifier of registered AP */
    void *reg_ctx;
    /* Service handle */
    ATT_HANDLE service_handle;
} bcm_gatts_delete_service_req_struct;

/* MSG_ID_BT_GATTS_DELETE_SERVICE_CNF */
typedef struct
{
    LOCAL_PARA_HDR
		
    kal_uint8 src_id;
    void *app_ctx;           
    /* identifier of registered AP */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
    /* Service handle */
    ATT_HANDLE service_handle;
} bcm_gatts_delete_service_cnf_struct;

/* MSG_ID_BT_GATTS_SEND_INDICATION_REQ */
typedef struct
{
    LOCAL_PARA_HDR
		
    kal_uint8 src_id;
    /* identifier of registered AP */
    void *reg_ctx;
    /* identifier of connection */
    void *conn_ctx;
    /* Attribute handle */
    ATT_HANDLE handle;
    U8 need_confirm;
    ATT_VALUE value;
} bcm_gatts_send_indication_req_struct;

/* MSG_ID_BT_GATTS_SEND_INDICATION_CNF */
typedef struct
{
    LOCAL_PARA_HDR
		
    kal_uint8 src_id;
    void *app_ctx;           
    /* identifier of registered AP */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
    /* identifier of connection */
    void *conn_ctx;
    /* Attribute handle */
    ATT_HANDLE handle;
    U8 need_confirm;
} bcm_gatts_send_indication_cnf_struct;

/* MSG_ID_BT_GATTS_SEND_RESPONSE_REQ */
typedef struct
{
    LOCAL_PARA_HDR
		
    kal_uint8 src_id;
    /* identifier of registered AP */
    void *reg_ctx;
    U8 result;
    /* identifier of connection */
    void *conn_ctx;
    /* trabsaction id */
    U16 trans_id;
    /* Attribute handle */
    ATT_HANDLE handle;
    ATT_VALUE value;
} bcm_gatts_send_response_req_struct;

/* MSG_ID_BT_GATTS_SEND_RESPONSE_CNF */
typedef bcm_gatts_send_indication_cnf_struct bcm_gatts_send_response_cnf_struct;

/* MSG_ID_BT_GATTS_READ_TX_POWER_REQ */
typedef struct
{
    LOCAL_PARA_HDR
		
    kal_uint8 src_id;
    /* identifier of registered AP */
    void *reg_ctx;
    /* Address of discovered device */
    U8 bd_addr[6];
} bcm_gatts_read_tx_power_req_struct;

/* MSG_ID_BT_GATTS_READ_TX_POWER_CNF */
typedef struct
{
    LOCAL_PARA_HDR
		
    kal_uint8 src_id;
    void *app_ctx;          
    /* identifier of registered AP */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
    /* Address of discovered device */
    U8 bd_addr[6];
    /* rssi of remote device */
    U8 tx_power;
} bcm_gatts_read_tx_power_cnf_struct;

/* Indication messages */
/* MSG_ID_BT_GATTS_READ_REQUEST_IND */
typedef struct
{
    LOCAL_PARA_HDR
		
    kal_uint8 src_id;
    void *app_ctx;           
    /* identifier of registered AP */
    void *reg_ctx;
    /* identifier of connection */
    void *conn_ctx;
    /* trabsaction id */
    U16 trans_id;
    U8 bd_addr[6];
    /* Attribute handle */
    ATT_HANDLE handle;
    U8 is_long;
    U16 offset;
} bcm_gatts_read_request_ind_struct;

/* MSG_ID_BT_GATTS_WRITE_REQUEST_IND */
typedef struct
{
    LOCAL_PARA_HDR
		
    kal_uint8 src_id;
    void *app_ctx;           
    /* identifier of registered AP */
    void *reg_ctx;
    /* identifier of connection */
    void *conn_ctx;
    /* trabsaction id */
    U16 trans_id;
    U8 bd_addr[6];
    /* Attribute handle */
    ATT_HANDLE handle;
    U8 need_rsp;
    U8 is_prepare;
    U16 offset;
    ATT_VALUE value;
} bcm_gatts_write_request_ind_struct;

/* MSG_ID_BT_GATTS_EXEC_WRITE_REQUEST_IND */
typedef struct
{
    LOCAL_PARA_HDR
		
    kal_uint8 src_id;
    void *app_ctx;           
    /* identifier of registered AP */
    void *reg_ctx;
    /* identifier of connection */
    void *conn_ctx;
    /* trabsaction id */
    U16 trans_id;
    U8 bd_addr[6];
    U8 cancel;
} bcm_gatts_exec_write_request_ind_struct;

/* MSG_ID_BT_GATTS_SET_ADV_DATA_REQ */
typedef struct
{
    LOCAL_PARA_HDR
		
    kal_uint8 src_id;
    /* identifier of registered AP */
    void *reg_ctx;
    BOOL set_scan_rsp;
    BOOL include_name;
    BOOL include_txpower;
    U16 min_interval;
    U16 max_interval;
    U16 appearance;
    U16 manufacturer_len;
    char manufacturer_data[512];
    U16 service_data_len;
    char service_data[512];
    U16 service_uuid_len;
    char service_uuid[512];
} bcm_gatts_set_adv_data_req_struct;

/* MSG_ID_BT_GATTS_SET_ADV_DATA_CNF */
typedef struct
{
    LOCAL_PARA_HDR
		
    kal_uint8 src_id;
    void *app_ctx;          
    /* identifier of registered AP */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
} bcm_gatts_set_adv_data_cnf_struct;

/* MSG_ID_BT_GATTS_UPDATE_CONNECTED_INFO */
typedef struct
{
    LOCAL_PARA_HDR
		
    kal_uint8 src_id;
    void *app_ctx;           
    /* identifier of registered AP */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
    /* identifier of connection */
    void *conn_ctx;
    /* Address of discovered device */
    U8 bd_addr[6];
    /* Role of local device */
    U8 LocalRole;
    /* name length of remote device */
    U8 dev_name_len;
    /* name of remote device */
    char dev_name[100];
} bcm_gatts_connected_info_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
} bcm_fmps_register_req_struct;

//MSG_ID_BCM_FMPS_WRITE_ALERT_IND
typedef struct
{
    LOCAL_PARA_HDR 
    U8 alert_level;
	U8 bd_addr[6];
} bcm_fmps_write_alert_ind_struct;

//MSG_ID_BCM_FMPS_CONNECTED_IND
typedef struct
{
    LOCAL_PARA_HDR 
    U8 op; //disconnected or connected
	U8 bd_addr[6];
} bcm_fmps_connected_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
} bcm_pxps_register_req_struct;

//MSG_ID_BCM_PXPS_LINKLOSS_ALERT_IND
typedef struct
{
    LOCAL_PARA_HDR 
    U8 alert_level;
	U8 bd_addr[6];
} bcm_pxps_linkloss_alert_ind_struct;

//MSG_ID_BCM_PXPS_DISCONN_ALERT_IND
typedef struct
{
    LOCAL_PARA_HDR 
    U8 alert_level;
	U8 bd_addr[6];
} bcm_pxps_disconn_alert_ind_struct;

//MSG_ID_BCM_PXPS_CONNECTED_IND
typedef struct
{
    LOCAL_PARA_HDR 
	U8 bd_addr[6];
} bcm_pxps_connected_ind_struct;

//MSG_ID_BCM_GATT_READ_ADDR
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
} bcm_gatt_read_local_addr_req_struct;

/* MSG_ID_BCM_GATT_READ_ADDR_CNF */
typedef struct
{
    LOCAL_PARA_HDR		
    kal_uint8 src_id;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
    /* Address of discovered device */
    U8 bd_addr[6];
} bcm_gatt_read_local_addr_cnf_struct;

#endif

#ifdef __BT_GATTC_PROFILE__
/* MSG_ID_BT_GATTC_SET_ADV_PARAM_REQ */
typedef struct
{
    LOCAL_PARA_HDR
	 kal_uint8 src_id;
    U16 min_interval;//range:0x0020~0x4000, N*1.25ms.default 0x0800
    U16 max_interval;//range:0x0020~0x4000, N*1.25ms.default 0x0800
} bcm_gatt_set_adv_param_req_struct;

/* MSG_ID_BT_GATTC_SET_ADV_PARAM_CNF */
typedef struct
{
    LOCAL_PARA_HDR
		
    kal_uint8 src_id;
    void *app_ctx;          
    /* identifier of registered AP */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
} bcm_gatt_set_adv_param_cnf_struct;
/* MSG_ID_BT_GATTC_CONN_PARAM_UPDATE_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    U8 bd_addr[6];//remout device address
    U16 min_interval;//range:0x0006~0x0C80, N*1.25ms.
    U16 max_interval;
    U16 timeout;//supervision timeout range:0x000A~0x0C80, N*10ms
    U16 latency;//range:0x0000~0x01F3
} bt_gatt_conn_param_update_req_struct;

/* MSG_ID_BT_GATTC_CONN_PARAM_UPDATE_CNF */
typedef struct
{
    LOCAL_PARA_HDR		
    kal_uint8 src_id;
    void *app_ctx;           
    /* identifier of registered AP */
    void *reg_ctx;
    /* Result : 0 means success, otherwise failed  */
    U8 result;
    /* identifier of connection */
    void *conn_ctx;
} bt_gatt_conn_param_update_cnf_struct;

#endif
#endif//BCM_STRUCT_H

