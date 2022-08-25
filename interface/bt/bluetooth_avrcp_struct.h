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
 *   bluetooth_avrcp_struct.h
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
#ifndef __BLUETOOTH_AVRCP_STRUCT_H_
#define __BLUETOOTH_AVRCP_STRUCT_H_

#include "bt_types.h"
#include "bluetooth_struct.h"

/* AVRCP device roles */
#define BT_AVRCP_TG		        0
#define BT_AVRCP_CT		        1
#define BT_AVRCP_CT_TG			2 /*support CT+TG*/
#define BT_AVRCP_MAX_CHANNEL    (BT_PROFILES_LINK_NUM) /* One Target and one Controller */
#define BT_AVRCP_ROLE_UNDEF		255

/* command/response types */
#define BT_AVRCP_CR_CONTROL				    (0x00)
#define BT_AVRCP_CR_STATUS					(0x01)
#define BT_AVRCP_CR_SPECIFIC_INUIRY		    (0x02)
#define BT_AVRCP_CR_NOTIFY					(0x03)
#define BT_AVRCP_CR_GENERAL_INQUIRY		    (0x04)
#define BT_AVRCP_CR_ACCEPT					(0x09)
#define BT_AVRCP_CR_REJECT					(0x0A)
#define BT_AVRCP_CR_NOT_IMPLEMENT		    (0x08)
#define BT_AVRCP_CR_STABLE					(0x0c)

/* sub_unit types */
#define BT_AVRCP_SUBUNIT_TYPE_UNIT_INFO		(0x1f)
#define BT_AVRCP_SUBUNIT_TYPE_SUBUNIT_INFO	(0x1f)
#define BT_AVRCP_SUBUNIT_TYPE_PASS_THROUGH	(0x09) /* Panel subunit */

/* sub_unit ID */
#define BT_AVRCP_SUBUNIT_ID_UNIT_INFO		(0x07)
#define BT_AVRCP_SUBUNIT_ID_SUBUNIT_INFO	(0x07)
#define BT_AVRCP_SUBUNIT_ID_PASS_THROUGH	(0x00)

/* opcodes */
#define BT_AVRCP_OP_UNIT_INFO			    (0x30)
#define BT_AVRCP_OP_SUBUNIT_INFO			(0x31)
#define BT_AVRCP_OP_VENDOR				    (0x00)
#define BT_AVRCP_OP_PASS_THROUGH			(0x7c)


#define BT_AVRCP_MAX_CMD_FRAME_SIZE          200     /* AV13 use large cmd */
#define BT_AVRCP_MAX_RSP_FRAME_SIZE          2048    /* AV13 as a controller, target's response could be a large data*/
#define BT_AVRCP_MAX_IND_CMD_NUM             10      /* Maximum indication send to MMI if confirm not send back yet */
#define BT_AVRCP_MAX_AV_FRAME_SIZE           512     /* Defined by AV/C spec */
#define BT_AVRCP_MAX_BROWSE_BUFFER_SIZE      1024    /* Local buffer limitation */

/* AVRCP Error code - Message for CT */
#define BT_AVRCP_RESULT_SUCCESS            0x1000
#define BT_AVRCP_RESULT_ERROR              0x1001
#define BT_AVRCP_RESULT_INVALID_ROLE       0x1002
#define BT_AVRCP_RESULT_INTERNAL_ERROR     0x1003
#define BT_AVRCP_RESULT_CHANNEL_NOT_FOUND  0x1004


#define BT_AVRCP_RESULT_TIMEOUT         0x1003
#define BT_AVRCP_RESULT_BAD_STATE       0x1004
#define BT_AVRCP_RESULT_BUSY            0x1005

/* AVRCP Error/Status code AVRCP spec 6.15.3 status and error codes */
#define BT_AVRCP_ERRCODE_INVALID_CMD            0x00 // All cmds
#define BT_AVRCP_ERRCODE_INVALID_PARAM          0x01 // All cmds
#define BT_AVRCP_ERRCODE_NOT_FOUND              0x02 // All cmds
#define BT_AVRCP_ERRCODE_INTERNAL_ERROR         0x03 // All cmds
#define BT_AVRCP_ERRCODE_OPERATION_COMPLETE     0x04 // All cmds except CType is reject
#define BT_AVRCP_ERRCODE_UID_CHANGED            0x05 // All cmds
#define BT_AVRCP_ERRCODE_RESERVED               0x06 // All cmds
#define BT_AVRCP_ERRCODE_INVALID_DIRECTION      0x07 // change path cmd
#define BT_AVRCP_ERRCODE_NOT_A_DIRECTORY        0x08 // change path cmd
#define BT_AVRCP_ERRCODE_NOT_EXIST              0x09 // change path, playitem, addtonowplaying, getitemattributes
#define BT_AVRCP_ERRCODE_INVALID_SCOPE          0x0a // get folder itmes, play items, addtonowplaying, getitemattributes
#define BT_AVRCP_ERRCODE_RANGE_OUT_OF_BOUNDS    0x0b // getfolderitems
#define BT_AVRCP_ERRCODE_UID_IS_DIRECTORY       0x0c // play items, addtonowplaying
#define BT_AVRCP_ERRCODE_MEDIA_IN_USE           0x0d // play items, addtonowplaying
#define BT_AVRCP_ERRCODE_NOW_PLAYING_FULL       0x0e // addtonowplaying
#define BT_AVRCP_ERRCODE_SEARCH_NOT_SUPPORTED   0x0f // search
#define BT_AVRCP_ERRCODE_SEARCH_IN_PROGRESS     0x10 // search
#define BT_AVRCP_ERRCODE_INVALID_PLAYER_ID      0x11 // setaddressedplayer, setbrowsedplayer
#define BT_AVRCP_ERRCODE_PLAYER_NOT_BROWSABLE   0x12 // setbrowsedplayer
#define BT_AVRCP_ERRCODE_PLAYER_NOT_ADDRESSED   0x13 // search, setbrowsedplayer
#define BT_AVRCP_ERRCODE_INVALID_SEARCH_RESULT  0x14 // get folder itmes
#define BT_AVRCP_ERRCODE_NO_AVAILABLE_PLAYER    0x15 // All cmds
#define BT_AVRCP_ERRCODE_PLAYER_CHANGED         0x16 // register notification

/* PASS THROUGH PDU_ID - AV/C  PANEL subunit spec */
#define BT_AVRCP_OPERATION_ID_PLAY              0x44
#define BT_AVRCP_OPERATION_ID_STOP              0x45
#define BT_AVRCP_OPERATION_ID_PAUSE             0x46
#define BT_AVRCP_OPERATION_ID_FORWARD           0x4B
#define BT_AVRCP_OPERATION_ID_BACKWARD          0x4C
#define BT_AVRCP_OPERATION_ID_FASTFORWARD       0x49
#define BT_AVRCP_OPERATION_ID_REWIND            0x48
#define BT_AVRCP_OPERATION_ID_VOLUME_UP         0x41
#define BT_AVRCP_OPERATION_ID_VOLUME_DOWN       0x42
#define BT_AVRCP_OPERATION_ID_VOLUME_DOWN       0x42
#define BT_AVRCP_OPERATION_ID_VENDOR_UNIQUE     0x7E
#define BT_AVRCP_OPERATION_ID_VENDOR_NEXT_GROUP       0x0000
#define BT_AVRCP_OPERATION_ID_VENDOR_PREVIOUS_GROUP   0x0001

/* AVRCP V1.3 */
#define BT_AVRCP_MAX_ATTRIBUTE_NUM			    4			// Max number of player application setting attributes
#define BT_AVRCP_MAX_ATTRIBUTE_VALUE_NUM	    4			// Max number of player application setting attibute value
#define BT_AVRCP_MAX_EVENT_NUM			        20			// Max number of event supported (TG)
#define BT_AVRCP_MAX_MEDIA_ATTRIBUTE_ID         7			// Max number of media attibute ID supported (TG)
#define BT_AVRCP_MAX_PLAYERS_NUM		        20			// Max number of Available players
#define BT_AVRCP_MAX_FILE_ATTRIBUTE   			7			// Max number of a file's attributes 
#define BT_AVRCP_MAX_ATTRIBUTE_STRING_SIZE      80          // Max string leng for text
#define BT_AVRCP_MAX_VALUE_STRING_SIZE          80          // Max string leng for text
#define BT_AVRCP_MAX_GET_ELEMENT_ATTR_NUM       10          // Max number of media elements which be querying in once
#define BT_AVRCP_MAX_GET_ELEMENT_ITEM_SIZE      8           // Max number of media elements which be querying in once
#define BT_AVRCP_MAX_PLAYER_NAME_SIZE           60          // Max string leng for text
#define BT_AVRCP_MAX_FOLDER_DEPTH_NUM           60          // Max folder depth

#define BT_AVRCP_MAX_ELEMENET_BUFFER_SIZE       512
#define BT_AVRCP_MAX_FOLDER_BUFFER_SIZE         512
#define BT_AVRCP_MAX_SEARCH_TEXT_SIZE           128

#define AVRCP_MEDIA_DATA_RSP_FIELNAME           L"avrcp_media.bin"

#define AVRCP_SCOPE_PLAYER_LIST                 0x00
#define AVRCP_SCOPE_FILE_SYSTEM                 0x01
#define AVRCP_SCOPE_SEARCH                      0x02
#define AVRCP_SCOPE_NOW_PLAYING                 0x03

#define AVRCP_MAX_EVENT_NUM                                       0x0d
#define AVRCP_NOTIFY_EVENT_PLAYBACK_STATUS_CHANGED                0x01
#define AVRCP_NOTIFY_EVENT_TRACK_CHANGED                          0x02
#define AVRCP_NOTIFY_EVENT_TRACK_REACHED_END                      0x03
#define AVRCP_NOTIFY_EVENT_TRACK_REACHED_START                    0x04
#define AVRCP_NOTIFY_EVENT_PLAYBACK_POS_CHANGED                   0x05
#define AVRCP_NOTIFY_EVENT_BATT_STATUS_CHANGED                    0x06
#define AVRCP_NOTIFY_EVENT_SYSTEM_STATUS_CHANGED                  0x07
#define AVRCP_NOTIFY_EVENT_PLAYER_APPLICATION_SETTING_CHANGED     0x08
#define AVRCP_NOTIFY_EVENT_NOW_PLAYING_CONTENT_CHANGED            0x09
#define AVRCP_NOTIFY_EVENT_AVAILABLE_PLAYERS_CHANGED              0x0a
#define AVRCP_NOTIFY_EVENT_ADDRESSED_PLAYER_CHANGED               0x0b
#define AVRCP_NOTIFY_EVENT_UIDS_CHANGED                           0x0c
#define AVRCP_NOTIFY_EVENT_VOLUME_CHANGED                         0x0d

typedef struct _bt_avrcp_dev_addr_struct
{
    U32 lap;
    U8  uap;
    U16 nap; // non-significant 32..47
} bt_avrcp_dev_addr_struct;


/* ===================================================== */

typedef struct
{
    LOCAL_PARA_HDR
#ifndef BTMTK_ON_MAUI
    U8 chnl_num;    
#endif
    U8 local_role;
    U8 version; /* 0 for highest option. 10 for 1.0  13 for 1.3. 14 for v1.4 */
    U8 sdpfeature; /* */
} bt_avrcp_activate_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
#ifndef BTMTK_ON_MAUI
    U8 chnl_num;	
#endif
    U16 result;
    U8 version; /* 10 for 1.0.  13 for 1.3. 14 for v1.4 */
} bt_avrcp_activate_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 chnl_num;
} bt_avrcp_deactivate_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 chnl_num;
    U16 result;
} bt_avrcp_deactivate_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
#ifndef BTMTK_ON_MAUI
    U8 chnl_num;    
#endif
    U8 local_role;    
    bt_avrcp_dev_addr_struct device_addr;
} bt_avrcp_connect_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 chnl_num;
    U8 connect_id;
    U16 result;
    bt_avrcp_dev_addr_struct device_addr;
    U16 browse_channel; // is browse channel
    U16 remote_tg_support_feature;
    U16 remote_ct_support_feature;
} bt_avrcp_connect_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 chnl_num;
    U8 connect_id;
    bt_avrcp_dev_addr_struct device_addr;
    U8 device_name_size;
    U8 device_name[60];
    U16 psm_value; // notify the connection of AVCTP or AVCTP_BROWSING
} bt_avrcp_connect_ind_struct;

#ifdef BTMTK_ON_MAUI
typedef struct
{
    LOCAL_PARA_HDR
    U8 chnl_num;
    bt_avrcp_dev_addr_struct device_addr;
} bt_avrcp_connect_ind_req_struct;
#endif

typedef struct
{
    LOCAL_PARA_HDR
    U8 chnl_num;
    BOOL accept_conn;
    U16 psm_value;
} bt_avrcp_connect_ind_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 chnl_num;
} bt_avrcp_disconnect_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    U8 chnl_num;
    U8 connect_id;
    U16 result;
} bt_avrcp_disconnect_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 chnl_num;
    U8 connect_id;
} bt_avrcp_disconnect_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   c_type;
    U8   subunit_type;
    U8   subunit_id;
    U16  data_len;
    U8   frame_data[BT_AVRCP_MAX_CMD_FRAME_SIZE];
} bt_avrcp_cmd_frame_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   c_type;
    U8   subunit_type;
    U8   subunit_id;
    U16  data_len;
    U8   frame_data[BT_AVRCP_MAX_CMD_FRAME_SIZE];
} bt_avrcp_cmd_frame_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   c_type;
    U8   subunit_type;
    U8   subunit_id;
    U16  data_len;
    U16  profile_id;
    U8   frame_data[BT_AVRCP_MAX_CMD_FRAME_SIZE];
} bt_avrcp_cmd_frame_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   c_type;
    U8   subunit_type;
    U8   subunit_id;
    U16  data_len;
    U16  profile_id;
    U8   frame_data[BT_AVRCP_MAX_CMD_FRAME_SIZE];
} bt_avrcp_cmd_frame_ind_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 accept;
} bt_avrcp_connect_accept_res;

typedef struct
{
    LOCAL_PARA_HDR
    U8 chnl_num;
    U8 local_role;
} bt_avrcp_browse_connect_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 chnl_num;
    U8 connect_id;
    U16 result;
    U16 bws_mtu;
} bt_avrcp_browse_connect_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 chnl_num;
    U8 connect_id;
    U16 bws_mtu;
} bt_avrcp_browse_connect_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 chnl_num;
} bt_avrcp_browse_disconnect_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 chnl_num;
} bt_avrcp_browse_disconnect_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 chnl_num;
    U8 seq_id;    
#ifdef BTMTK_ON_MAUI    
    U8 local_role; /* 0: controller 1: target 0xff: oppsite local role*/

#else
    U8 query_role; /* 0: controller 1: target 0xff: oppsite local role*/
#endif
} bt_avrcp_sdp_query_req_struct;

#ifdef BTMTK_ON_MAUI    
typedef struct
{
    LOCAL_PARA_HDR
    U8 chnl_num;
    U16 result;
    U16 version;
    U16 remote_support_feature;
} bt_avrcp_sdp_query_cnf_struct;
#endif
typedef struct
{
    LOCAL_PARA_HDR
    U8 chnl_num;
    U8 seq_id;    
#ifdef BTMTK_ON_MAUI    
    U16 status;
    bt_avrcp_dev_addr_struct device_addr;
#else
    U8 status;
#endif
    U16 tg_version;
    U16 remote_tg_support_feature;
    U16 ct_version;
    U16 remote_ct_support_feature;
} bt_avrcp_sdp_query_ind_struct;

/***************** AVRCP 1.3 TG ******************/
/* reject: AVCTP header. error_code: AVRCP spec 6.15.3 */
#define LOCAL_PARA_AVRCP_REJECT \
    U8	reject; \
    U8	error_code;

/* MSG_ID_BT_AVRCP_GET_CAPABILITIES_IND */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   capability_id; /* 0x03 avrcp_event_suppport */
} bt_avrcp_get_capabilities_ind_struct;

/* MSG_ID_BT_AVRCP_GET_CAPABILITIES_RSP */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_REJECT
    U8   capability_id;
    U8   count; // capability count
    U8   capability[BT_AVRCP_MAX_EVENT_NUM]; // 2..n spec 6.4.1
} bt_avrcp_get_capabilities_rsp_struct;

/* MSG_ID_BT_AVRCP_LIST_PLAYERAPP_ATTRIBUTE_IND */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
} bt_avrcp_list_playerapp_attribute_ind_struct;

/* MSG_ID_BT_AVRCP_LIST_PLAYERAPP_ATTRIBUTE_RSP */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   count;
    LOCAL_PARA_AVRCP_REJECT
    U8   attribute_id[BT_AVRCP_MAX_ATTRIBUTE_NUM];
} bt_avrcp_list_playerapp_attribute_rsp_struct;

/* MSG_ID_BT_AVRCP_LIST_PLAYERAPP_VALUE_IND */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   attribute_id; // query the possible values of this attribute id
} bt_avrcp_list_playerapp_value_ind_struct;

/* MSG_ID_BT_AVRCP_LIST_PLAYERAPP_VALUE_RSP */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_REJECT
    U8   attribute_id;
    U8   count; //availabe values[]
    U8   attribute_values[BT_AVRCP_MAX_ATTRIBUTE_VALUE_NUM]; //possiblel setting values
} bt_avrcp_list_playerapp_value_rsp_struct;

/* MSG_ID_BT_AVRCP_GET_CURPLAYERAPP_VALUE_IND */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   count;
    U8   attribute_id[BT_AVRCP_MAX_ATTRIBUTE_NUM];
} bt_avrcp_get_curplayerapp_value_ind_struct;

/* MSG_ID_BT_AVRCP_GET_CURPLAYERAPP_VALUE_RSP */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_REJECT
    U8   count;
    U8   attribute_id[BT_AVRCP_MAX_ATTRIBUTE_NUM];
    U8   attribute_value[BT_AVRCP_MAX_ATTRIBUTE_NUM]; // value of index of attribute id
} bt_avrcp_get_curplayerapp_value_rsp_struct;

/* MSG_ID_BT_AVRCP_SET_PLAYERAPP_VALUE_IND */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   count;
    U8   attribute_id[BT_AVRCP_MAX_ATTRIBUTE_NUM];
    U8   values[BT_AVRCP_MAX_ATTRIBUTE_NUM]; // value of index of attribute id
} bt_avrcp_set_playerapp_value_ind_struct;

/* MSG_ID_BT_AVRCP_SET_PLAYERAPP_VALUE_RSP */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_REJECT
} bt_avrcp_set_playerapp_value_rsp_struct; //Ack the set-value ( not take effect yet by spec 6.5.4)

/* MSG_ID_BT_AVRCP_GET_PLAYERAPP_ATTRIBUTETEXT_IND */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   count;
    U8   attribute_id[BT_AVRCP_MAX_ATTRIBUTE_NUM];
} bt_avrcp_get_playerapp_attributetext_ind_struct;

/* MSG_ID_BT_AVRCP_GET_PLAYERAPP_ATTRIBUTETEXT_RSP */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_REJECT
    U8   count;
    U8   attribute_id[BT_AVRCP_MAX_ATTRIBUTE_NUM];
    U16  charset[BT_AVRCP_MAX_ATTRIBUTE_NUM];
    U8   attribute_string_len[BT_AVRCP_MAX_ATTRIBUTE_NUM];
    U8   attribute_string[BT_AVRCP_MAX_ATTRIBUTE_NUM][BT_AVRCP_MAX_ATTRIBUTE_STRING_SIZE]; // 4*40=160 Byte. Note!
} bt_avrcp_get_playerapp_attributetext_rsp_struct;

/* MSG_ID_BT_AVRCP_GET_PLAYERAPP_VALUETEXT_IND */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   attribute_id; // query all text of attribute values of a specific attribute id
    U8   count;        // available number of attribute values
    U8   value_ids[BT_AVRCP_MAX_ATTRIBUTE_VALUE_NUM];
} bt_avrcp_get_playerapp_valuetext_ind_struct;

/* MSG_ID_BT_AVRCP_GET_PLAYERAPP_VALUETEXT_RSP */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_REJECT
    U8   attribute_id;
    U8   count;
    U8   value_ids[BT_AVRCP_MAX_ATTRIBUTE_VALUE_NUM];
    U16  charset[BT_AVRCP_MAX_ATTRIBUTE_VALUE_NUM]; // results
    U8   value_string_len[BT_AVRCP_MAX_ATTRIBUTE_VALUE_NUM]; // query results
    U8   value_string[BT_AVRCP_MAX_ATTRIBUTE_VALUE_NUM][BT_AVRCP_MAX_ATTRIBUTE_STRING_SIZE]; // 4*40=160 Byte. Note!
} bt_avrcp_get_playerapp_valuetext_rsp_struct;

/* MSG_ID_BT_AVRCP_INFORM_DISPLAY_CHARSET_IND */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   count; // useless? in spec. figure 26.2. the counter is always 1
    U16  charset_ids[BT_AVRCP_MAX_ATTRIBUTE_NUM]; // in spec. 6.5.7. the charset_id is not a array.
} bt_avrcp_inform_display_charset_ind_struct;

/* MSG_ID_BT_AVRCP_INFORM_DISPLAY_CHARSET_RSP */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_REJECT
} bt_avrcp_inform_display_charset_rsp_struct;

/* MSG_ID_BT_AVRCP_INFORM_BATTERY_STATUSOFCT_IND */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   battery_status; // spec. 6.5.8
} bt_avrcp_inform_battery_statusofct_ind_struct;

/* MSG_ID_BT_AVRCP_INFORM_BATTERY_STATUSOFCT_RSP */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_REJECT
} bt_avrcp_inform_battery_statusofct_rsp_struct;

/* MSG_ID_BT_AVRCP_GET_ELEMENT_ATTRIBUTES_IND */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   identifier[8];
    U8   count;
    U32  attributes[BT_AVRCP_MAX_GET_ELEMENT_ATTR_NUM];
} bt_avrcp_get_element_attributes_ind_struct;

/* MSG_ID_BT_AVRCP_GET_ELEMENT_ATTRIBUTES_RSP */
typedef struct
{
    U32  attribute_id;
    U16  charset;
    U16  value_len;
    U16  value_text_offset; // NOTE: it should be put in another data field
} bt_avrcp_element_attributes_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_REJECT
    U8   count; // spec 6.6.1
    bt_avrcp_element_attributes_struct elements[BT_AVRCP_MAX_GET_ELEMENT_ATTR_NUM];
    U8   element_data[BT_AVRCP_MAX_ELEMENET_BUFFER_SIZE];
} bt_avrcp_get_element_attributes_rsp_struct;

/* MSG_ID_BT_AVRCP_GET_PLAYERSTATUS_IND */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
} bt_avrcp_get_playerstatus_ind_struct;

/* MSG_ID_BT_AVRCP_GET_PLAYERSTATUS_RSP */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_REJECT
    U32  song_length; // spec 6.7.1
    U32  song_position; // spec 6.7.1
    U8   play_status; // spec 6.7.1
} bt_avrcp_get_playerstatus_rsp_struct;

/* MSG_ID_BT_AVRCP_REGISTER_NOTIFICATION_IND */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   event_id; // spec appendix H
    U32  playback_interval; // spec 6.7.1 only available when event_id is EVENT_PLAYBACK_POS_CHANGED
} bt_avrcp_register_notification_ind_struct;

/* MSG_ID_BT_AVRCP_REGISTER_NOTIFICATION_RSP */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_REJECT
    U8   is_interim; // figure 26.3 interim message(0x01) rsp (0x00)
    U8   event_id; // spec appendix H. below fields are defined by event_id
    U8   status;   // all EVENT except belows
    U8   identifier[8]; // EVENT_TRACK_CHANGED
    U8   count;  //EVENT_PLAYER_APPLICATION_SETTING_CHANGED
    U8   attribute_id[BT_AVRCP_MAX_ATTRIBUTE_NUM];  //EVENT_PLAYER_APPLICATION_SETTING_CHANGED
    U8   attribute_value[BT_AVRCP_MAX_ATTRIBUTE_NUM];  //EVENT_PLAYER_APPLICATION_SETTING_CHANGED
    U16  id; // EVENT_ADDRESSEDPLAYER_CHANGED
    U16  uid_counter; // EVENT_ADDRESSEDPLAYER_CHANGED or EVENT_UID_CHANGED
    U8   volume; // EVENT_VOLUME_CHANGED
    U32  pos; // EVENT_POS_CHANGED
} bt_avrcp_register_notification_rsp_struct;

/* MSG_ID_BT_AVRCP_ABORT_CONTINUERESPONSE_IND */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   pdu_id; // AVRCP specific AV/C command's PDU ID. AVRCP spec. table 4.5
} bt_avrcp_abort_continueresponse_ind_struct;

/* MSG_ID_BT_AVRCP_ABORT_CONTINUERESPONSE_RSP */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_REJECT
    U8   pdu_id; // AVRCP specific AV/C command's PDU ID. AVRCP spec. table 4.5
} bt_avrcp_abort_continueresponse_rsp_struct;

/* MSG_ID_BT_AVRCP_SET_ABSOLUTE_VOLUME_IND */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   volume;
} bt_avrcp_set_absolute_volume_ind_struct;

/* MSG_ID_BT_AVRCP_SET_ABSOLUTE_VOLUME_RSP */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_REJECT
    U8   volume;
} bt_avrcp_set_absolute_volume_rsp_struct;

/* MSG_ID_BT_AVRCP_SET_ADDRESSEDPLAYER_IND */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U16  player_id;
} bt_avrcp_set_addressedplayer_ind_struct;

/* MSG_ID_BT_AVRCP_SET_ADDRESSEDPLAYER_RSP */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_REJECT
    U8   status; // spec 6.15.3
} bt_avrcp_set_addressedplayer_rsp_struct;

/***************** AVRCP 1.4 TG ******************/
/* MSG_ID_BT_AVRCP_GET_PLAYERITEMS_IND - Browing channel */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   scope; // spec 6.10.1 6.10.4.2 scope=0x00
    U16  start_item;
    U16  end_item;
    U8   count;
    U32  attribute_ids[BT_AVRCP_MAX_ATTRIBUTE_NUM];
} bt_avrcp_get_playeritems_ind_struct;


typedef struct
{
    U8   item_type; // media play item list spec 6.10.4.2
    U16  item_len;
    U16  player_id;
    U8   major_play_type;
    U8   player_sub_type[4];
    U8   play_status;
    U8   feature_bitmask[16];
    U16  charset;
    U16  name_len;
    U8   name[BT_AVRCP_MAX_PLAYER_NAME_SIZE];
} avrcp_media_player_item;

typedef struct
{
    U32 attribute_id;
    U16 charset;
    U16 attribute_value_len;           // store the length
    U16 attribute_value_string_offset; // store the offset in data buffer
} bt_avrcp_attrbute_struct;

typedef struct
{
    U8   item_type;    // player, folder item, element item list spec 6.10.2.2
    U16  item_length;  // player, folder item, element item
    U8   uid[8];       // player, folder item, element item
    U16  player_id;    // player item
    U8   specific_type;// player, folder item, element item
    U8   is_playable;  // player, folder item
    U32  sub_type;     // player item
    U8   status;       // player item
    U8   mask[16];     // player item
    U16  charset;      // player, folder item, element item
    U16  name_length;  // player, folder item, element item
    U16  name_offset;  // player, folder item, element item
    U8   attribute_count; // element item
    bt_avrcp_attrbute_struct attributes[BT_AVRCP_MAX_MEDIA_ATTRIBUTE_ID]; // element item
} avrcp_folder_mixed_item;

/* MSG_ID_BT_AVRCP_GET_PLAYERITEMS_RSP - Browing channel */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_REJECT
    U8   status; // spec. 6.15.3
    U16  uid_counter;
    U16  counter;
    avrcp_media_player_item players[BT_AVRCP_MAX_PLAYERS_NUM];
} bt_avrcp_get_playeritems_rsp_struct;

/* MSG_ID_BT_AVRCP_GET_FOLDERITEMS_IND - Browing channel */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   scope; // spec 6.10.1 6.10.4.2 scope=0x01,0x02,0x03
    U32  start_item;
    U32  end_item;
    U8   count;
    U32  attribute_ids[BT_AVRCP_MAX_ATTRIBUTE_NUM];
} bt_avrcp_get_folderitems_ind_struct;

/* MSG_ID_BT_AVRCP_GET_FOLDERITEMS_RSP - Browing channel */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_REJECT
    U8   status;
    U16  uid_counter;
    U16  counter;
    avrcp_folder_mixed_item items[BT_AVRCP_MAX_GET_ELEMENT_ITEM_SIZE];
    U8   data[BT_AVRCP_MAX_FOLDER_BUFFER_SIZE];    /// Assume the l2cap mtu is 1024
    U16  data_len;
} bt_avrcp_get_folderitems_rsp_struct;

/* MSG_ID_BT_AVRCP_SET_BROWSEDPLAYER_IND - Browing channel */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U16  player_id;
} bt_avrcp_set_browsedplayer_ind_struct;

/* MSG_ID_BT_AVRCP_SET_BROWSEDPLAYER_RSP - Browing channel */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_REJECT
    U8   status; // spec 6.9.3
    U16  uid_counter;
    U32  num_of_items;
    U16  char_set;
    U8   folder_depth;
    U16  foldername_len[BT_AVRCP_MAX_FOLDER_DEPTH_NUM];
    U16  foldername_offset[BT_AVRCP_MAX_FOLDER_DEPTH_NUM];
    U8   folder_data[BT_AVRCP_MAX_FOLDER_BUFFER_SIZE];
} bt_avrcp_set_browsedplayer_rsp_struct;

/* MSG_ID_BT_AVRCP_CHANGE_PATH_IND - Browing channel */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U16  uid_counter;
    U8   direction;
    U8  folder_uid[8];
} bt_avrcp_change_path_ind_struct;

/* MSG_ID_BT_AVRCP_CHANGE_PATH_RSP - Browing channel */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_REJECT
    U8   status;
    U32  num_of_items;
} bt_avrcp_change_path_rsp_struct;

/* MSG_ID_BT_AVRCP_GET_ITEMATTRIBUTES_IND - Browing channel */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   scope;
    U8   uid[8];
    U16  uid_counter;
    U8   count;
    U32   attribute_ids[BT_AVRCP_MAX_MEDIA_ATTRIBUTE_ID];
} bt_avrcp_get_itemattributes_ind_struct;

/* MSG_ID_BT_AVRCP_GET_ITEMATTRIBUTES_RSP - Browing channel */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_REJECT
    U8   status;
    U8   counter;
    U32  attribute_id[BT_AVRCP_MAX_GET_ELEMENT_ITEM_SIZE]; // spec 6.10.2.3.1
    U16  charset[BT_AVRCP_MAX_GET_ELEMENT_ITEM_SIZE]; // spec 6.10.2.3.1
    U16  attribute_value_len[BT_AVRCP_MAX_GET_ELEMENT_ITEM_SIZE]; // spec 6.10.2.3.1
    U8   attribute_value_string[BT_AVRCP_MAX_GET_ELEMENT_ITEM_SIZE][BT_AVRCP_MAX_VALUE_STRING_SIZE]; // spec 6.10.2.3.1
} bt_avrcp_get_itemattributes_rsp_struct; // spec 6.10.4.3

/* MSG_ID_BT_AVRCP_PLAY_ITEMS_IND */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   scope;
    U8   uid[8];
    U16  uid_counter;
} bt_avrcp_play_items_ind_struct; // spec. 6.12.1

/* MSG_ID_BT_AVRCP_PLAY_ITEMS_RSP */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_REJECT
    U8   status;
} bt_avrcp_play_items_rsp_struct;

/* MSG_ID_BT_AVRCP_SEARCH_IND - Browing channel */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U16  charset;
    U16  length;
    U8   search_string[BT_AVRCP_MAX_SEARCH_TEXT_SIZE];
} bt_avrcp_search_ind_struct; // spec.6.11

/* MSG_ID_BT_AVRCP_SEARCH_RSP - Browing channel */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_REJECT
    U8   status;
    U16  uid_counter;
    U32  found_num_of_items; // spec 6.11
} bt_avrcp_search_rsp_struct;

/* MSG_ID_BT_AVRCP_ADD_TONOWPLAYING_IND */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   scope;
    U8  uid[8];
    U16  uid_counter;
} bt_avrcp_add_tonowplaying_ind_struct;

/* MSG_ID_BT_AVRCP_ADD_TONOWPLAYING_RSP */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_REJECT
    U8   status;
} bt_avrcp_add_tonowplaying_rsp_struct;


/***************** AVRCP 1.3 CT ******************/
/* reject: AVCTP header. error_code: AVRCP spec 6.15.3 */
#define LOCAL_PARA_AVRCP_RESULT \
    U16	result; \
    U8	error_code;

/* MSG_ID_BT_AVRCP_GET_CAPABILITIES_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   capability_id; /* 0x03 avrcp_event_suppport */
} bt_avrcp_get_capabilities_req_struct;

/* MSG_ID_BT_AVRCP_GET_CAPABILITIES_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_RESULT
    U8   capability_id;
    U8   count; // capability count
    U8   capability[BT_AVRCP_MAX_EVENT_NUM]; // 2..n spec 6.4.1
    U8   company_id_size;
    U8   company_id[BT_AVRCP_MAX_ATTRIBUTE_STRING_SIZE];
} bt_avrcp_get_capabilities_cnf_struct;

/* MSG_ID_BT_AVRCP_LIST_PLAYERAPP_ATTRIBUTE_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
} bt_avrcp_list_playerapp_attribute_req_struct;

/* MSG_ID_BT_AVRCP_LIST_PLAYERAPP_ATTRIBUTE_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_RESULT
    U8   count;
    U8   attribute_ids[BT_AVRCP_MAX_ATTRIBUTE_NUM];
} bt_avrcp_list_playerapp_attribute_cnf_struct;

/* MSG_ID_BT_AVRCP_LIST_PLAYERAPP_VALUE_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   attribute_id; // query the possible values of this attribute id
} bt_avrcp_list_playerapp_value_req_struct;

/* MSG_ID_BT_AVRCP_LIST_PLAYERAPP_VALUE_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_RESULT
    U8   attribute_id;
    U8   count; //availabe values[]
    U8   attribute_values[BT_AVRCP_MAX_ATTRIBUTE_VALUE_NUM]; //possiblel setting values
} bt_avrcp_list_playerapp_value_cnf_struct;

/* MSG_ID_BT_AVRCP_GET_CURPLAYERAPP_VALUE_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   count;
    U8   attribute_ids[BT_AVRCP_MAX_ATTRIBUTE_NUM];
} bt_avrcp_get_curplayerapp_value_req_struct;

/* MSG_ID_BT_AVRCP_GET_CURPLAYERAPP_VALUE_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_RESULT
    U8   count;
    U8   attribute_ids[BT_AVRCP_MAX_ATTRIBUTE_NUM];
    U8   attribute_values[BT_AVRCP_MAX_ATTRIBUTE_NUM]; // value of reqex of attribute id
} bt_avrcp_get_curplayerapp_value_cnf_struct;

/* MSG_ID_BT_AVRCP_SET_PLAYERAPP_VALUE_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   count;
    U8   attribute_ids[BT_AVRCP_MAX_ATTRIBUTE_NUM];
    U8   values[BT_AVRCP_MAX_ATTRIBUTE_NUM]; // value of reqex of attribute id
} bt_avrcp_set_playerapp_value_req_struct;

/* MSG_ID_BT_AVRCP_SET_PLAYERAPP_VALUE_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_RESULT
} bt_avrcp_set_playerapp_value_cnf_struct; //Ack the set-value ( not take effect yet by spec 6.5.4)

/* MSG_ID_BT_AVRCP_GET_PLAYERAPP_ATTRIBUTETEXT_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   count;
    U8   attribute_ids[BT_AVRCP_MAX_ATTRIBUTE_NUM];
} bt_avrcp_get_playerapp_attributetext_req_struct;

/* MSG_ID_BT_AVRCP_GET_PLAYERAPP_ATTRIBUTETEXT_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_RESULT
    U8   count;
    U8   attribute_id[BT_AVRCP_MAX_ATTRIBUTE_NUM];
    U16  charset[BT_AVRCP_MAX_ATTRIBUTE_NUM];
    U8   attribute_string_len[BT_AVRCP_MAX_ATTRIBUTE_NUM];
    U8   attribute_string[BT_AVRCP_MAX_ATTRIBUTE_NUM][BT_AVRCP_MAX_ATTRIBUTE_STRING_SIZE]; // 4*40=160 Byte. Note!
} bt_avrcp_get_playerapp_attributetext_cnf_struct;

/* MSG_ID_BT_AVRCP_GET_PLAYERAPP_VALUETEXT_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   attribute_id; // query all text of attribute values of a specific attribute id
    U8   count;        // available number of attribute values
    U8   value_ids[BT_AVRCP_MAX_ATTRIBUTE_VALUE_NUM];
} bt_avrcp_get_playerapp_valuetext_req_struct;

/* MSG_ID_BT_AVRCP_GET_PLAYERAPP_VALUETEXT_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_RESULT
    U8   attribute_id;
    U8   count;
    U8   value_ids[BT_AVRCP_MAX_ATTRIBUTE_VALUE_NUM];
    U16  charset[BT_AVRCP_MAX_ATTRIBUTE_VALUE_NUM]; // results
    U8   value_string_len[BT_AVRCP_MAX_ATTRIBUTE_VALUE_NUM]; // query results
    U8   value_string[BT_AVRCP_MAX_ATTRIBUTE_VALUE_NUM][BT_AVRCP_MAX_ATTRIBUTE_STRING_SIZE]; // 4*40=160 Byte. Note!
} bt_avrcp_get_playerapp_valuetext_cnf_struct;

/* MSG_ID_BT_AVRCP_INFORM_DISPLAY_CHARSET_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   count; // useless? in spec. figure 26.2. the counter is always 1
    U16  charset_ids[BT_AVRCP_MAX_ATTRIBUTE_NUM]; // in spec. 6.5.7. the charset_id is not a array.
} bt_avrcp_inform_display_charset_req_struct;

/* MSG_ID_BT_AVRCP_INFORM_DISPLAY_CHARSET_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_RESULT
} bt_avrcp_inform_display_charset_cnf_struct;

/* MSG_ID_BT_AVRCP_INFORM_BATTERY_STATUSOFCT_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   battery_status; // spec. 6.5.8
} bt_avrcp_inform_battery_statusofct_req_struct;

/* MSG_ID_BT_AVRCP_INFORM_BATTERY_STATUSOFCT_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_RESULT
} bt_avrcp_inform_battery_statusofct_cnf_struct;

/* MSG_ID_BT_AVRCP_GET_ELEMENT_ATTRIBUTES_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   identifier[8];
    U8   count;
    U32  attributes[BT_AVRCP_MAX_GET_ELEMENT_ATTR_NUM];
} bt_avrcp_get_element_attributes_req_struct;

/* MSG_ID_BT_AVRCP_GET_ELEMENT_ATTRIBUTES_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_RESULT
    U8   count; // spec 6.6.1
    bt_avrcp_element_attributes_struct elements[BT_AVRCP_MAX_GET_ELEMENT_ATTR_NUM];
    U8   element_data[BT_AVRCP_MAX_ELEMENET_BUFFER_SIZE];
} bt_avrcp_get_element_attributes_cnf_struct;

/* MSG_ID_BT_AVRCP_GET_PLAYERSTATUS_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
} bt_avrcp_get_playerstatus_req_struct;

/* MSG_ID_BT_AVRCP_GET_PLAYERSTATUS_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_RESULT
    U32  song_length; // spec 6.7.1
    U32  song_position; // spec 6.7.1
    U8   play_status; // spec 6.7.1
} bt_avrcp_get_playerstatus_cnf_struct;

/* MSG_ID_BT_AVRCP_REGISTER_NOTIFICATION_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   event_id; // spec appendix H
    U32  playback_interval; // spec 6.7.1 only available when event_id is EVENT_PLAYBACK_POS_CHANGED
} bt_avrcp_register_notification_req_struct;

/* MSG_ID_BT_AVRCP_REGISTER_NOTIFICATION_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_RESULT
    U8   is_interim; // figure 26.3 interim message(0x01) cnf (0x00)
    U8   event_id; // spec appendix H. below fields are defined by event_id(0x01~0x0d)
    U8   status;   // all EVENT except belows
    U8   identifier[8]; // EVENT_TRACK_CHANGED
    U8   count;  //EVENT_PLAYER_APPLICATION_SETTING_CHANGED
    U8   attribute_id[BT_AVRCP_MAX_ATTRIBUTE_NUM];  //EVENT_PLAYER_APPLICATION_SETTING_CHANGED
    U8   attribute_value[BT_AVRCP_MAX_ATTRIBUTE_NUM];  //EVENT_PLAYER_APPLICATION_SETTING_CHANGED
    U16  id; // EVENT_ADDRESSEDPLAYER_CHANGED
    U16  uid_counter; // EVENT_ADDRESSEDPLAYER_CHANGED or EVENT_UID_CHANGED
    U8   volume; // EVENT_VOLUME_CHANGED
    U32  pos; // EVENT_POS_CHANGED
} bt_avrcp_register_notification_cnf_struct;

/* MSG_ID_BT_AVRCP_ABORT_CONTINUERESPONSE_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   pdu_id; // AVRCP specific AV/C command's PDU ID. AVRCP spec. table 4.5
} bt_avrcp_abort_continueresponse_req_struct;

/* MSG_ID_BT_AVRCP_ABORT_CONTINUERESPONSE_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_RESULT
    U8   pdu_id; // AVRCP specific AV/C command's PDU ID. AVRCP spec. table 4.5
} bt_avrcp_abort_continueresponse_cnf_struct;

/* MSG_ID_BT_AVRCP_SET_ABSOLUTE_VOLUME_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   volume;
} bt_avrcp_set_absolute_volume_req_struct;

/* MSG_ID_BT_AVRCP_SET_ABSOLUTE_VOLUME_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_RESULT
    U8   volume;
} bt_avrcp_set_absolute_volume_cnf_struct;

/* MSG_ID_BT_AVRCP_SET_ADDRESSEDPLAYER_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U16  player_id;
} bt_avrcp_set_addressedplayer_req_struct;

/* MSG_ID_BT_AVRCP_SET_ADDRESSEDPLAYER_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_RESULT
    U8   status; // spec 6.15.3
} bt_avrcp_set_addressedplayer_cnf_struct;

/***************** AVRCP 1.4 CT ******************/
/* MSG_ID_BT_AVRCP_GET_PLAYERITEMS_REQ - Browing channel */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   scope; // spec 6.10.1 6.10.4.2 scope=0x00
    U32  start_item;
    U32  end_item;
    U8   count;
    U32  attribute_ids[BT_AVRCP_MAX_ATTRIBUTE_NUM];
} bt_avrcp_get_playeritems_req_struct;


/* MSG_ID_BT_AVRCP_GET_PLAYERITEMS_CNF - Browing channel */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_RESULT
    U8   status; // spec. 6.15.3
    U16  uid_counter;
    U16  counter;
    avrcp_media_player_item players[BT_AVRCP_MAX_PLAYERS_NUM];
} bt_avrcp_get_playeritems_cnf_struct;



/* MSG_ID_BT_AVRCP_GET_FOLDERITEMS_REQ - Browing channel */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   scope; // spec 6.10.1 6.10.4.2 scope=0x01,0x02,0x03
    U32  start_item;
    U32  end_item;
    U8   count;
    U32  attribute_ids[BT_AVRCP_MAX_ATTRIBUTE_NUM];
} bt_avrcp_get_folderitems_req_struct;

/* MSG_ID_BT_AVRCP_GET_FOLDERITEMS_CNF - Browing channel */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_RESULT
    U8   status;
    U16  uid_counter;
    U16  counter;
    avrcp_folder_mixed_item items[BT_AVRCP_MAX_GET_ELEMENT_ITEM_SIZE];
    U16  data_len;
    U8   data[BT_AVRCP_MAX_FOLDER_BUFFER_SIZE];
} bt_avrcp_get_folderitems_cnf_struct;

/* MSG_ID_BT_AVRCP_SET_BROWSEDPLAYER_REQ - Browing channel */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U16  player_id;
} bt_avrcp_set_browsedplayer_req_struct;

/* MSG_ID_BT_AVRCP_SET_BROWSEDPLAYER_CNF - Browing channel */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_RESULT
    U8   status; // spec 6.9.3
    U16  uid_counter;
    U32  num_of_items;
    U16  char_set;
    U8   folder_depth;
    U16  foldername_len[BT_AVRCP_MAX_FOLDER_DEPTH_NUM];
    U16  foldername_offset[BT_AVRCP_MAX_FOLDER_DEPTH_NUM];
    U8   folder_data[BT_AVRCP_MAX_ELEMENET_BUFFER_SIZE];
} bt_avrcp_set_browsedplayer_cnf_struct;

/* MSG_ID_BT_AVRCP_CHANGE_PATH_REQ - Browing channel */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U16  uid_counter;
    U8   direction;
    U8  folder_uid[8];
} bt_avrcp_change_path_req_struct;

/* MSG_ID_BT_AVRCP_CHANGE_PATH_CNF - Browing channel */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_RESULT
    U8   status;
    U32  num_of_items;
} bt_avrcp_change_path_cnf_struct;

/* MSG_ID_BT_AVRCP_GET_ITEMATTRIBUTES_REQ - Browing channel */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   scope;
    U8   uid[8];
    U16  uid_counter;
    U8   count;
    U32  attribute_ids[BT_AVRCP_MAX_MEDIA_ATTRIBUTE_ID];
} bt_avrcp_get_itemattributes_req_struct;

/* MSG_ID_BT_AVRCP_GET_ITEMATTRIBUTES_CNF - Browing channel */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_RESULT
    U8   status;
    U8   counter;
    U32  attribute_id[BT_AVRCP_MAX_GET_ELEMENT_ITEM_SIZE]; // spec 6.10.2.3.1
    U16  charset[BT_AVRCP_MAX_GET_ELEMENT_ITEM_SIZE]; // spec 6.10.2.3.1
    U16  attribute_value_len[BT_AVRCP_MAX_GET_ELEMENT_ITEM_SIZE]; // spec 6.10.2.3.1
    U8   attribute_value_string[BT_AVRCP_MAX_GET_ELEMENT_ITEM_SIZE][BT_AVRCP_MAX_VALUE_STRING_SIZE]; // spec 6.10.2.3.1
} bt_avrcp_get_itemattributes_cnf_struct; // spec 6.10.4.3

/* MSG_ID_BT_AVRCP_PLAY_ITEMS_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   scope;
    U8   uid[8];
    U16  uid_counter;
} bt_avrcp_play_items_req_struct; // spec. 6.12.1

/* MSG_ID_BT_AVRCP_PLAY_ITEMS_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_RESULT
    U8   status;
} bt_avrcp_play_items_cnf_struct;

/* MSG_ID_BT_AVRCP_SEARCH_REQ - Browing channel */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U16  charset;
    U16  length;
    U8   search_string[BT_AVRCP_MAX_SEARCH_TEXT_SIZE];
} bt_avrcp_search_req_struct; // spec.6.11

/* MSG_ID_BT_AVRCP_SEARCH_CNF - Browing channel */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_RESULT
    U8   status;
    U16  uid_counter;
    U32  found_num_of_items; // spec 6.11
} bt_avrcp_search_cnf_struct;

/* MSG_ID_BT_AVRCP_ADD_TONOWPLAYING_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    U8   scope;
    U8  uid[8];
    U16  uid_counter;
} bt_avrcp_add_tonowplaying_req_struct;

/* MSG_ID_BT_AVRCP_ADD_TONOWPLAYING_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    U8   chnl_num;
    U8   seq_id;
    LOCAL_PARA_AVRCP_RESULT
    U8   status;
} bt_avrcp_add_tonowplaying_cnf_struct;



typedef struct
{
    U8 ref_count;
    U16 msg_len;
    U8 test_cmd_content[256];
} bt_avrcp_test_cmd_req_struct;


#endif /* __BLUETOOTH_AVRCP_STRUCT_H_ */

