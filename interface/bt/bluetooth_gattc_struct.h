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
 *   bluetooth_gattc_struct.h
 *
 * Project:
 * --------
 *   BlueAngel
 *
 * Description:
 * ------------
 *   This file defines SAP for MTK Bluetooth GATT client.
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef __BLUETOOTH_GATTC_STRUCT_H_
#define __BLUETOOTH_GATTC_STRUCT_H_

/* MSG_ID_BT_GATTC_REGISTER_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    void *app_ctx;        
    /* user_ctx will be carried in register cnf to identify AP which submit registration */
    U8 user_id[16];
} bt_gattc_register_req_struct;

/* MSG_ID_BT_GATTC_REGISTER_CNF */
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
} bt_gattc_register_cnf_struct;

/* MSG_ID_BT_GATTC_DEREGISTER_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
} bt_gattc_deregister_req_struct;

/* MSG_ID_BT_GATTC_DEREGISTER_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    void *app_ctx;           
    /* reg_ctx used by registered AP as an identifier */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
} bt_gattc_deregister_cnf_struct;

/* MSG_ID_BT_GATTC_SCAN_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
} bt_gattc_scan_req_struct;

/* MSG_ID_BT_GATTC_SCAN_RESULT_IND */
typedef struct
{
    LOCAL_PARA_HDR
    void *app_ctx;           
    /* identifier of registered AP */
    void *reg_ctx;
    /* Address of discovered device */
    U8 bd_addr[6];
    /* rssi of remote device */
    S32 rssi;
    /* length of EIR */
    U8 eir_len;
    /* raw EIR data */
    U8 eir[255];
} bt_gattc_scan_result_ind_struct;

/* MSG_ID_BT_GATTC_SCAN_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    void *app_ctx;           
    /* reg_ctx used by registered AP as an identifier */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
} bt_gattc_scan_cnf_struct;

/* MSG_ID_BT_GATTC_SCAN_CANCEL_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
} bt_gattc_scan_cancel_req_struct;

/* MSG_ID_BT_GATTC_SCAN_CANCEL_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    void *app_ctx;          
    /* reg_ctx used by registered AP as an identifier */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
} bt_gattc_scan_cancel_cnf_struct;

/* MSG_ID_BT_GATTC_CONNECT_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
    /* Address of discovered device */
    U8 bd_addr[6];
    /* 0 : non-direct connect, otherwise : direct */
    U8 direct;
} bt_gattc_connect_req_struct;

/* MSG_ID_BT_GATTC_CONNECT_CNF */
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
} bt_gattc_connect_cnf_struct;

/* MSG_ID_BT_GATTC_CONNECTED_IND */
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
} bt_gattc_connected_ind_struct;

/* MSG_ID_BT_GATTC_DISCONNECT_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
    /* identifier of connection */
    void *conn_ctx;
    /* Address of discovered device */
    U8 bd_addr[6];
} bt_gattc_disconnect_req_struct;

/* MSG_ID_BT_GATTC_DISCONNECT_CNF */
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
} bt_gattc_disconnect_cnf_struct;

/* MSG_ID_BT_GATTC_DISCONNECTED_IND */
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
} bt_gattc_disconnected_ind_struct;

/* MSG_ID_BT_GATTC_LISTEN_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
    BOOL start;
} bt_gattc_listen_req_struct;

/* MSG_ID_BT_GATTC_LISTEN_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    void *app_ctx;          
    /* identifier of registered AP */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
} bt_gattc_listen_cnf_struct;

/* MSG_ID_BT_GATTC_SET_ADV_DATA_REQ */
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
} bt_gattc_set_adv_data_req_struct;

/* MSG_ID_BT_GATTC_SET_ADV_DATA_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    void *app_ctx;          
    /* identifier of registered AP */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
} bt_gattc_set_adv_data_cnf_struct;

/* MSG_ID_BT_GATTC_REFRESH_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
    /* Address of discovered device */
    U8 bd_addr[6];
} bt_gattc_refresh_req_struct;

/* MSG_ID_BT_GATTC_REFRESH_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    void *app_ctx;          
    /* identifier of registered AP */
    void *reg_ctx;
    /* 0 means success, 2 means pending, otherwise failed */
    U8 result;
} bt_gattc_refresh_cnf_struct;

/* MSG_ID_BT_GATTC_SEARCH_SERVICE_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
    /* identifier of connection */
    void *conn_ctx;
    ATT_UUID uuid;
} bt_gattc_search_service_req_struct;

/* MSG_ID_BT_GATTC_SEARCH_SERVICE_RESULT_IND */
typedef struct
{
    LOCAL_PARA_HDR
    void *app_ctx;          
    /* identifier of registered AP */
    void *reg_ctx;
    /* identifier of connection */
    void *conn_ctx;
    GATT_SVC_UUID uuid;
} bt_gattc_search_service_result_ind_struct;

/* MSG_ID_BT_GATTC_SEARCH_SERVICE_CNF */
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
} bt_gattc_search_service_cnf_struct;

/* MSG_ID_BT_GATTC_GET_INCL_SERVICE_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
    /* identifier of connection */
    void *conn_ctx;
    /* uuid of service which contains the incl. service specified by incl_svc_uuid */
    GATT_SVC_UUID svc_uuid;
    /* NULL or incl. service uuid returned in previous search */
    GATT_SVC_UUID incl_svc_uuid;
} bt_gattc_get_incl_service_req_struct;

/* MSG_ID_BT_GATTC_GET_INCL_SERVICE_CNF */
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
    /* uuid of service which contains the incl. service specified by incl_svc_uuid */
    GATT_SVC_UUID svc_uuid;
    /* incl. service uuid found which immediatly follwing the incl_svc_uuid in search request.
    *   If incl_svc_uuid in search request is NULL, return first incl. svc in service
    *   specified by svc_uuid.
    */
    GATT_SVC_UUID incl_svc_uuid;
} bt_gattc_get_incl_service_cnf_struct;

/* MSG_ID_BT_GATTC_GET_CHAR_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
    /* identifier of connection */
    void *conn_ctx;
    /* uuid of service which contains the incl. service specified by incl_svc_uuid */
    GATT_SVC_UUID svc_uuid;
    /* NULL or char uuid returned in previous search */
    ATT_UUID char_uuid;
} bt_gattc_get_char_req_struct;

/* MSG_ID_BT_GATTC_GET_CHAR_CNF */
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
    /* uuid of service which contains the incl. service specified by incl_svc_uuid */
    GATT_SVC_UUID svc_uuid;
    /* uuid of char which is found immediatly follwing the char specified in search request.
    *   If char_uuid in previous search request is NULL, return first char in service
    *   specified by svc_uuid.
    */
    ATT_UUID char_uuid;
    U8 properties;
} bt_gattc_get_char_cnf_struct;

/* MSG_ID_BT_GATTC_GET_DESCR_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
    /* identifier of connection */
    void *conn_ctx;
    /* uuid of service which contains the descr specified by descr_uuid */
    GATT_SVC_UUID svc_uuid;
    /* uuid of char which contains the descr specified by descr_uuid */
    ATT_UUID char_uuid;
    /* NULL or descr uuid returned in previous search */
    ATT_UUID descr_uuid;
} bt_gattc_get_descr_req_struct;

/* MSG_ID_BT_GATTC_GET_DESCR_CNF */
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
    /* uuid of service which contains the descr specified by descr_uuid */
    GATT_SVC_UUID svc_uuid;
    /* uuid of char which contains the descr specified by descr_uuid */
    ATT_UUID char_uuid;
    /* uuid of descr which is found immediatly follwing the descr specified in previous search request.
    *   If descr_uuid in previous search request is NULL, return first descr in char specified by char_uuid in service
    *   specified by svc_uuid.
    */
    ATT_UUID descr_uuid;
} bt_gattc_get_descr_cnf_struct;

/* MSG_ID_BT_GATTC_READ_CHAR_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
    /* identifier of connection */
    void *conn_ctx;
    /* uuid of service which contains the descr specified by descr_uuid */
    GATT_SVC_UUID svc_uuid;
    /* uuid of char which contains the descr specified by descr_uuid */
    ATT_UUID char_uuid;
    /* Authentication requirement for reading char specified by char_uuid */
    U32 auth_req;
} bt_gattc_read_char_req_struct;

/* MSG_ID_BT_GATTC_READ_CHAR_CNF */
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
    GATT_SVC_UUID svc_uuid;
    ATT_UUID char_uuid;
    ATT_VALUE value;
} bt_gattc_read_char_cnf_struct;

/* MSG_ID_BT_GATTC_WRITE_CHAR_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
    /* identifier of connection */
    void *conn_ctx;
    /* Type of write. 1 : write no response, 2 : write with response 3 : prepare wirte */
    U32 write_type;
    GATT_SVC_UUID svc_uuid;
    ATT_UUID char_uuid;
    /* Authentication requirement for writing char specified by char_uuid */
    U32 auth_req;
    ATT_VALUE value;
} bt_gattc_write_char_req_struct;

/* MSG_ID_BT_GATTC_WRITE_CHAR_CNF */
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
    GATT_SVC_UUID svc_uuid;
    ATT_UUID char_uuid;
} bt_gattc_write_char_cnf_struct;

/* MSG_ID_BT_GATTC_READ_DESCR_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
    /* identifier of connection */
    void *conn_ctx;
    /* uuid of service which contains the descr specified by descr_uuid */
    GATT_SVC_UUID svc_uuid;
    /* uuid of char which contains the descr specified by descr_uuid */
    ATT_UUID char_uuid;
    /* Authentication requirement for reading char specified by char_uuid */
    ATT_UUID descr_uuid;
    /* Authentication requirement for reading char specified by char_uuid */
    U32 auth_req;
} bt_gattc_read_descr_req_struct;

/* MSG_ID_BT_GATTC_READ_DESCR_CNF */
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
    GATT_SVC_UUID svc_uuid;
    ATT_UUID char_uuid;
    ATT_UUID descr_uuid;
    ATT_VALUE value;
} bt_gattc_read_descr_cnf_struct;

/* MSG_ID_BT_GATTC_WRITE_DESCR_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
    /* identifier of connection */
    void *conn_ctx;
    /* Type of write. 1 : write no response, 2 : write with response 3 : prepare wirte */
    U32 write_type;
    GATT_SVC_UUID svc_uuid;
    ATT_UUID char_uuid;
    ATT_UUID descr_uuid;
    /* Authentication requirement for writing char specified by char_uuid */
    U32 auth_req;
    ATT_VALUE value;
} bt_gattc_write_descr_req_struct;

/* MSG_ID_BT_GATTC_WRITE_DESCR_CNF */
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
    GATT_SVC_UUID svc_uuid;
    ATT_UUID char_uuid;
    ATT_UUID descr_uuid;
} bt_gattc_write_descr_cnf_struct;

/* MSG_ID_BT_GATTC_EXEC_WRITE_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
    /* identifier of connection */
    void *conn_ctx;
    /* 0 : cancel execute, 1 : execute */
    U8 exeute;
} bt_gattc_exec_write_req_struct;

/* MSG_ID_BT_GATTC_EXEC_WRITE_CNF */
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
} bt_gattc_exec_write_cnf_struct;

/* MSG_ID_BT_GATTC_REGISTER_NOTIFICATION_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
    /* Address of discovered device */
    U8 bd_addr[6];
    GATT_SVC_UUID svc_uuid;
    ATT_UUID char_uuid;
} bt_gattc_register_notification_req_struct;

/* MSG_ID_BT_GATTC_REGISTER_NOTIFICATION_CNF */
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
    GATT_SVC_UUID svc_uuid;
    ATT_UUID char_uuid;
} bt_gattc_register_notification_cnf_struct;

/* MSG_ID_BT_GATTC_DEREGISTER_NOTIFICATION_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
    /* Address of discovered device */
    U8 bd_addr[6];
    GATT_SVC_UUID svc_uuid;
    ATT_UUID char_uuid;
} bt_gattc_deregister_notification_req_struct;

/* MSG_ID_BT_GATTC_DEREGISTER_NOTIFICATION_CNF */
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
    GATT_SVC_UUID svc_uuid;
    ATT_UUID char_uuid;
} bt_gattc_deregister_notification_cnf_struct;

/* MSG_ID_BT_GATTC_READ_RSSI_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
    /* Address of discovered device */
    U8 bd_addr[6];
} bt_gattc_read_rssi_req_struct;

/* MSG_ID_BT_GATTC_READ_RSSI_CNF */
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
    S32 rssi;
} bt_gattc_read_rssi_cnf_struct;

/* MSG_ID_BT_GATTC_GET_DEVICE_TYPE_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* identifier of registered AP */
    void *reg_ctx;
    /* Address of discovered device */
    U8 bd_addr[6];
} bt_gattc_get_device_type_req_struct;

/* MSG_ID_BT_GATTC_GET_DEVICE_TYPE_CNF */
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
    /* Device type. 0 : unknown, 1 : BLE, 2 : BREDR, 3 : DUAL */
    U8 dev_type;
} bt_gattc_get_device_type_cnf_struct;

/* MSG_ID_BT_GATTC_NOTIFICATION_IND */
typedef struct
{
    LOCAL_PARA_HDR
    void *app_ctx;          
    /* identifier of registered AP */
    void *reg_ctx;
    /* identifier of connection */
    void *conn_ctx;
    /* Address of discovered device */
    U8 bd_addr[6];
    GATT_SVC_UUID svc_uuid;
    ATT_UUID char_uuid;
    U8 is_notify;       
    ATT_VALUE value;
} bt_gattc_notification_ind_struct;

/* MSG_ID_BT_GATTC_CONN_PARAM_UPDATE_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    U8 bd_addr[6];//remout device address
    U16 MaskBit;//1:set corresponding param.Bit[0]:min_interval, [1]:max_interval,[2]:timeout,[3]:latency,
    U16 min_interval;//range:0x0006~0x0C80, N*1.25ms.
    U16 max_interval;
    U16 timeout;//supervision timeout range:0x000A~0x0C80, N*10ms
    U16 latency;//range:0x0000~0x01F3
} bt_gattc_conn_param_update_req_struct;

/* MSG_ID_BT_GATTC_CONN_PARAM_UPDATE_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    /* Result : 0 means success, otherwise failed  */
    U8 result;
} bt_gattc_conn_param_update_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U16 min_interval;//range:0x0020~0x4000, N*1.25ms.default 0x0800
    U16 max_interval;//range:0x0020~0x4000, N*1.25ms.default 0x0800
    U8 adv_type;//default 0
    U8 own_addr_type;//default 0
    U8 direct_addr_type;//default 0
    //U8 direct_addr[6];
    U8 chnl_map;
    U8 filter;//default 0
    U16 MaskBit;//1:set corresponding param.Bit[0]:min_interval, [1]:max_interval,[2]:adv_type,[3]:own_addr_type,[4]:direct_addr_type,[1]:should be 1,[6]chnl_map,[7]filter,0xFF: All
} bt_gattc_set_adv_param_req_struct;

/* MSG_ID_BT_GATTC_CONN_PARAM_UPDATE_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    /* Result : 0 means success, otherwise failed  */
    U8 result;
} bt_gattc_set_adv_param_cnf_struct;

/* MSG_ID_BT_GATTC_START_RESEARCH_SERVICE_IND */
typedef struct
{
    LOCAL_PARA_HDR
    void *app_ctx;     
    /* identifier of registered AP */
    void *reg_ctx;
    /* identifier of connection */
    void *conn_ctx;
    /* Address of discovered device */
    U8 bd_addr[6];
} bt_gattc_start_research_service_ind_struct;

/* MSG_ID_BT_GATTC_RESEARCH_SERVICE_IND */
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
} bt_gattc_research_service_ind_struct;

/* MSG_ID_BT_GATTC_UPDATE_CONNECTED_INFO */
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
} bt_gattc_connected_info_struct;

#endif /* __BLUETOOTH_GATTC_STRUCT_H_ */

