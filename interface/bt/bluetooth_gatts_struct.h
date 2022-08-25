/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

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
 *   bluetooth_gatts_struct.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is defines SAP for MTK Bluetooth.
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef __BLUETOOTH_GATTS_STRUCT_H_
#define __BLUETOOTH_GATTS_STRUCT_H_

/* MSG_ID_BT_GATTS_REGISTER_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    void *app_ctx;           
    /* user_ctx will be carried in register cnf to identify AP which submit registration */
    U8 user_id[16];
} bt_gatts_register_req_struct;

/* MSG_ID_BT_GATTS_REGISTER_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    void *app_ctx;           
    /* reg_ctx used by registered AP as an identifier */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
    /* user_ctx in register request. Used to identify AP which subnit the registration */
    U8 user_id[16];
} bt_gatts_register_cnf_struct;

/* MSG_ID_BT_GATTS_DEREGISTER_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
} bt_gatts_deregister_req_struct;

/* MSG_ID_BT_GATTS_DEREGISTER_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    void *app_ctx;           
    /* reg_ctx used by registered AP as an identifier */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
} bt_gatts_deregister_cnf_struct;

/* MSG_ID_BT_GATTS_CONNECT_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
    /* Address of discovered device */
    U8 bd_addr[6];
    /* 0 : non-direct connect, otherwise : direct */
    U8 direct;
} bt_gatts_connect_req_struct;

/* MSG_ID_BT_GATTS_CONNECT_CNF */
typedef struct
{
    LOCAL_PARA_HDR
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
} bt_gatts_connect_cnf_struct;

/* MSG_ID_BT_GATTS_CONNECTED_IND */
typedef struct
{
    LOCAL_PARA_HDR
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
} bt_gatts_connected_ind_struct;

/* MSG_ID_BT_GATTS_DISCONNECT_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
    /* identifier of connection */
    void *conn_ctx;
    /* Address of discovered device */
    U8 bd_addr[6];
} bt_gatts_disconnect_req_struct;

/* MSG_ID_BT_GATTS_DISCONNECT_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    void *app_ctx;           
    /* identifier of registered AP */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
    /* identifier of connection */
    void *conn_ctx;
    /* Address of discovered device */
    U8 bd_addr[6];
} bt_gatts_disconnect_cnf_struct;

/* MSG_ID_BT_GATTS_DISCONNECTED_IND */
typedef struct
{
    LOCAL_PARA_HDR
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
} bt_gatts_disconnected_ind_struct;

/* MSG_ID_BT_GATTS_LISTEN_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
    BOOL start;
} bt_gatts_listen_req_struct;

/* MSG_ID_BT_GATTS_LISTEN_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    void *app_ctx;          
    /* identifier of registered AP */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
} bt_gatts_listen_cnf_struct;

/* MSG_ID_BT_GATTS_ADD_SERVICE_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
    /* Service uuid */
    GATT_SVC_UUID uuid;
    /* number of handles needed */
    U16 num_handles;
} bt_gatts_add_service_req_struct;

/* MSG_ID_BT_GATTS_ADD_SERVICE_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    void *app_ctx;           
    /* identifier of registered AP */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
    /* Service uuid */
    GATT_SVC_UUID uuid;
    /* handle of added service */
    ATT_HANDLE service_handle;
} bt_gatts_add_service_cnf_struct;

/* MSG_ID_BT_GATTS_ADD_INCL_SERVICE_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
    /* Service uuid */
    ATT_HANDLE service_handle;
    /* service handle of service to be included */
    ATT_HANDLE incl_service_handle;
} bt_gatts_add_incl_service_req_struct;

/* MSG_ID_BT_GATTS_ADD_INCL_SERVICE_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    void *app_ctx;           
    /* identifier of registered AP */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
    /* Service uuid */
    ATT_HANDLE service_handle;
    /* handle of incl. service record in service specified by service_uuid */
    ATT_HANDLE incl_service_handle;
} bt_gatts_add_incl_service_cnf_struct;

/* MSG_ID_BT_GATTS_ADD_CHAR_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
    /* Service handle */
    ATT_HANDLE service_handle;
    ATT_UUID char_uuid;
    /* properties defined in char declaration */
    U32 properties;
    /* Attribute permission */
    U32 permission;
} bt_gatts_add_char_req_struct;

/* MSG_ID_BT_GATTS_ADD_CHAR_CNF */
typedef struct
{
    LOCAL_PARA_HDR
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
} bt_gatts_add_char_cnf_struct;

/* MSG_ID_BT_GATTS_ADD_DESCR_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
    /* Service handle */
    ATT_HANDLE service_handle;
    /* uuid of descr to be added */
    ATT_UUID descr_uuid;
    /* Attribute permission */
    U32 permission;
} bt_gatts_add_descr_req_struct;

/* MSG_ID_BT_GATTS_ADD_DESCR_CNF */
typedef struct
{
    LOCAL_PARA_HDR
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
} bt_gatts_add_descr_cnf_struct;

/* MSG_ID_BT_GATTS_START_SERVICE_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
    /* Service handle */
    ATT_HANDLE service_handle;
    /* transport to start service. 0 : LE, 1 : BREDR, 2 : Dual */
    U8 transport;
} bt_gatts_start_service_req_struct;

/* MSG_ID_BT_GATTS_START_SERVICE_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    void *app_ctx;           
    /* identifier of registered AP */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
    /* Service handle */
    ATT_HANDLE service_handle;
} bt_gatts_start_service_cnf_struct;

/* MSG_ID_BT_GATTS_STOP_SERVICE_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
    /* Service handle */
    ATT_HANDLE service_handle;
} bt_gatts_stop_service_req_struct;

/* MSG_ID_BT_GATTS_STOP_SERVICE_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    void *app_ctx;           
    /* identifier of registered AP */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
    /* Service handle */
    ATT_HANDLE service_handle;
} bt_gatts_stop_service_cnf_struct;

/* MSG_ID_BT_GATTS_DELETE_SERVICE_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
    /* Service handle */
    ATT_HANDLE service_handle;
} bt_gatts_delete_service_req_struct;

/* MSG_ID_BT_GATTS_DELETE_SERVICE_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    void *app_ctx;           
    /* identifier of registered AP */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
    /* Service handle */
    ATT_HANDLE service_handle;
} bt_gatts_delete_service_cnf_struct;

/* MSG_ID_BT_GATTS_SEND_INDICATION_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
    /* identifier of connection */
    void *conn_ctx;
    /* Attribute handle */
    ATT_HANDLE handle;
    U8 need_confirm;
    ATT_VALUE value;
} bt_gatts_send_indication_req_struct;

/* MSG_ID_BT_GATTS_SEND_INDICATION_CNF */
typedef struct
{
    LOCAL_PARA_HDR
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
} bt_gatts_send_indication_cnf_struct;

/* MSG_ID_BT_GATTS_SEND_RESPONSE_REQ */
typedef struct
{
    LOCAL_PARA_HDR
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
} bt_gatts_send_response_req_struct;

/* MSG_ID_BT_GATTS_SEND_RESPONSE_CNF */
typedef bt_gatts_send_indication_cnf_struct bt_gatts_send_response_cnf_struct;

/* MSG_ID_BT_GATTS_READ_TX_POWER_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
    /* Address of discovered device */
    U8 bd_addr[6];
} bt_gatts_read_tx_power_req_struct;

/* MSG_ID_BT_GATTS_READ_TX_POWER_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    void *app_ctx;          
    /* identifier of registered AP */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
    /* Address of discovered device */
    U8 bd_addr[6];
    /* rssi of remote device */
    U8 tx_power;
} bt_gatts_read_tx_power_cnf_struct;

/* Indication messages */
/* MSG_ID_BT_GATTS_READ_REQUEST_IND */
typedef struct
{
    LOCAL_PARA_HDR
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
} bt_gatts_read_request_ind_struct;

/* MSG_ID_BT_GATTS_WRITE_REQUEST_IND */
typedef struct
{
    LOCAL_PARA_HDR
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
} bt_gatts_write_request_ind_struct;

/* MSG_ID_BT_GATTS_EXEC_WRITE_REQUEST_IND */
typedef struct
{
    LOCAL_PARA_HDR
    void *app_ctx;           
    /* identifier of registered AP */
    void *reg_ctx;
    /* identifier of connection */
    void *conn_ctx;
    /* trabsaction id */
    U16 trans_id;
    U8 bd_addr[6];
    U8 cancel;
} bt_gatts_exec_write_request_ind_struct;

/* MSG_ID_BT_GATTS_SET_ADV_DATA_REQ */
typedef struct
{
    LOCAL_PARA_HDR
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
} bt_gatts_set_adv_data_req_struct;

/* MSG_ID_BT_GATTS_SET_ADV_DATA_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    void *app_ctx;          
    /* identifier of registered AP */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
} bt_gatts_set_adv_data_cnf_struct;

/* MSG_ID_BT_GATTS_UPDATE_CONNECTED_INFO */
typedef struct
{
    LOCAL_PARA_HDR
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
} bt_gatts_connected_info_struct;

/* MSG_ID_BT_GATTS_GET_RANDOM_ADDR_REQ*/
typedef struct
{
    LOCAL_PARA_HDR
} bt_gatts_get_random_addr_req_struct;

/* MSG_ID_BT_GATTS_GET_RANDOM_ADDR_CNF*/
typedef struct
{
    LOCAL_PARA_HDR
    U8 result;
    /* Address of discovered device */
    U8 bd_addr[6];
} bt_gatts_get_random_addr_cnf_struct;


/***************************************************/
#endif /* __BLUETOOTH_GATTS_STRUCT_H_ */

