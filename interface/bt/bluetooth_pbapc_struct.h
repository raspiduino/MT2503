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
 * bt_pbap_struct.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   struct of local parameter for pbap
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __BLUETOOTH_PBAPC_STRUCT_H__
#define __BLUETOOTH_PBAPC_STRUCT_H__
#include "bt_types.h"
#include "bluetooth_pbap_struct.h"

#ifdef __BT_PBAP_CLIENT__

/*****************************************************************************
* Definations
*****************************************************************************/

#define PBAPC_ADP_WORK_FOLDER     (L"Z:\\@pbapc\\")
#define PBAPC_ADP_FOLDER_FILE        (L"Z:\\@pbapc\\folder.tmp")
#define PBAPC_ADP_LIST_FILE   (L"Z:\\@pbapc\\list.tmp")
#define PBAPC_ADP_ENTRY_FILE   (L"Z:\\@pbapc\\entry.tmp")
/*--------------------------- Begin of the PBAP Client ------------------*/

#ifndef PBAP_MAX_PASSWORD_LEN
#define PBAP_MAX_PASSWORD_LEN       20
#endif

#ifndef PBAP_MAX_USERID_LEN
#define PBAP_MAX_USERID_LEN         20
#endif

#ifndef FHANDLE
typedef signed int FHANDLE;
#endif /* FHANDLE */

#ifndef FHANDLE_INVALID_VALUE
#define FHANDLE_INVALID_VALUE -10
#endif /* FHANDLE_INVALID_VALUE */

#ifndef MAX_PBAP_CLIENT_SEARCH_VALUE_LENGTH
#define MAX_PBAP_CLIENT_SEARCH_VALUE_LENGTH 32
#endif

/* Puplic Data Structures */
typedef enum
{
    PBAPC_REQ_NONE,
    PBAPC_REQ_ENABLE,
    PBAPC_REQ_DISABLE,
    PBAPC_REQ_CONNECT,
    PBAPC_REQ_SET_PATH,
    PBAPC_REQ_PULL_ENTRY,
    PBAPC_REQ_PULL_LIST,
    PBAPC_REQ_PULL_PB,
    PBAPC_REQ_ABORT,
    PBAPC_REQ_DISCONNECT,
    PBAPC_REQ_LAST
} bt_pbapc_request_type;

typedef enum
{
    PBAP_STATE_IDLE,
    PBAP_STATE_TP_CONNECTING,
    PBAP_STATE_OBEX_CONNECTING,
    PBAP_STATE_CONNECTED,
    PBAP_STATE_PULLING,
    PBAP_STATE_SETTING_PATH,
    PBAP_STATE_DISCONNECTING,
    PBAP_STATE_MAX
} bt_pbap_conn_state;


/* Activate the PCE */
typedef struct
{
    LOCAL_PARA_HDR
} bt_pbapc_enable_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    bt_pbap_cnf_enum register_result;
} bt_pbapc_enable_cnf_struct;

/* Deactivate the PCE */
typedef struct
{
    LOCAL_PARA_HDR
} bt_pbapc_disable_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    bt_pbap_cnf_enum deregister_result;
} bt_pbapc_disable_cnf_struct;

/* PCE Connect Request */
typedef struct
{
    LOCAL_PARA_HDR
    bt_pbap_bd_addr_struct bd_addr;/* local bt device address(lap, uap, nap) */
} bt_pbapc_connect_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    /* allocated during the connection establishmen to indicate the connection */
    kal_uint8	conn_id;
    bt_pbap_cnf_enum	cnf_code;
    bt_pbap_bd_addr_struct bd_addr;/* local bt device address(lap, uap, nap) */
} bt_pbapc_connect_cnf_struct;

/* Client Disconnect confirmation(Confirmation of disconnect indication and request) */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	conn_id;
} bt_pbapc_disconnect_req_struct;

/* Client Disconnect confirmation(Confirmation of disconnect indication and request) */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	conn_id;
    bt_pbap_cnf_enum cnf_code;
} bt_pbapc_disconnect_cnf_struct;

/* Client Disconnect Indication */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	conn_id;
} bt_pbapc_disconnect_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	conn_id;
    bt_pbap_cnf_enum cnf_code;
} bt_pbapc_abort_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	conn_id;
} bt_pbapc_abort_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 cancel;
    bt_pbap_bd_addr_struct bd_addr;/* local bt device address(lap, uap, nap) */
    /* OBEX Authentication password */
    kal_uint8 password[PBAP_MAX_PASSWORD_LEN];
    /* OBEX Authentication userId */
    kal_uint8 userId[PBAP_MAX_USERID_LEN];
} bt_pbapc_auth_challenge_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    /*don't use the following two paramters now please */
    bt_pbap_bd_addr_struct bd_addr;/* local bt device address(lap, uap, nap) */
    kal_uint8 auth_option;
} bt_pbapc_auth_challenge_ind_struct;


/* PCE SetPath Request(SetPhoneBook) */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	conn_id;
    pbap_set_folder_type_enum type; /* Forward, Back or Root folder */
    /* Maximum number of characters allowed for pathnames + 1 (null-
     * terminating character */
    kal_uint8                 name[PBAP_MAX_NAME_LEN / 2 + 1];
} bt_pbapc_set_path_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	conn_id;
    bt_pbap_cnf_enum	cnf_code;
} bt_pbapc_set_path_cnf_struct;


/* PCE get vCard Request(PullvCardEntry) */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	conn_id;
    kal_uint8 		pbap_data_file[BT_PBAP_MAX_FILEPATH_NAME_LEN];	// UCS-2
    kal_uint8		objectName[PBAP_MAX_NAME_LEN / 2 + 1];				// UCS-2
    PbapVcardFilter	filter;
    PbapVcardFormat	format;
} bt_pbapc_read_entry_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	conn_id;
    bt_pbap_cnf_enum	cnf_code;
} bt_pbapc_read_entry_cnf_struct;

/* PCE get vCard Listing(PullvCardListing) */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	conn_id;
    kal_uint8  pbap_data_file[BT_PBAP_MAX_FILEPATH_NAME_LEN];	// UCS-2
    kal_uint8  folderName[PBAP_MAX_NAME_LEN / 2 + 1];				// UCS-2
    kal_uint8  searchAttribute;
    kal_uint8  searchValue[MAX_PBAP_CLIENT_SEARCH_VALUE_LENGTH + 1]; // UTF-8
    kal_uint8  searchValueLength;
    kal_uint8  order;
    kal_uint16 maxListCount;
    kal_uint16 listStartOffset;
} bt_pbapc_read_list_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	conn_id;
    bt_pbap_cnf_enum  cnf_code;
    kal_uint16 phoneBookSize; /*0xFFFF indicates have only data*/
    kal_uint16 newMissedCalls; /*0xFFFF indicates the type is not MCH*/
} bt_pbapc_read_list_cnf_struct;


/* PCE get PhoneBook(PullPhoneBook) */
typedef struct
{
    LOCAL_PARA_HDR

    kal_uint8	conn_id;
    kal_uint8 		pbap_data_file[BT_PBAP_MAX_FILEPATH_NAME_LEN]; // UCS-2
    kal_uint8		folderName[PBAP_MAX_NAME_LEN / 2 + 1];			// UCS-2
    PbapVcardFilter	filter;
    PbapVcardFormat	format;
    kal_uint16		maxListCount;
    kal_uint16		listStartOffset;
} bt_pbapc_read_folder_req_struct;

typedef struct
{
    LOCAL_PARA_HDR

    kal_uint8	conn_id;
    bt_pbap_cnf_enum  cnf_code;
    kal_uint16 phoneBookSize; /*0xFFFF indicates have only data*/
    kal_uint16 newMissedCalls; /*0xFFFF indicates the type is not MCH*/
} bt_pbapc_read_folder_cnf_struct;

/*--------------------------- end of the PBAP Client --------------------*/
#endif /* __BT_PBAP_CLIENT__ */

#endif//__BLUETOOTH_PBAPC_STRUCT_H__

