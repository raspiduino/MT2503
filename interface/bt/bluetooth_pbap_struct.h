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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __BLUETOOTH_PBAP_STRUCT_H__
#define __BLUETOOTH_PBAP_STRUCT_H__
#include "bt_types.h"
/*****************************************************************************
* Definations
*****************************************************************************/
#define PBAP_FILTER_SIZE                8
#define BT_PBAP_MAX_DEV_NAME_LEN        80
#define BT_PBAP_MAX_FILEPATH_NAME_LEN        256

/*
 *if application provide data in buffer, adp will create temp file by itself,
 *  so define the file here(realize by the buffer data to file data mod)
 * also define the variable aim to realize  application file/buffer data to  profile buffer data
 * but not realy realize it
 *
*/
#ifdef BTMTK_ON_MAUI
#define PBAP_ADP_FILE_NAME  (L"c:\\@btmtk\\profile\\tempvcard.vcf")
//#define PBAP_ADP_FILE_NAME ( L"c:\\LGAPP\\Bluetooth\\tempvcard.vcf")
#else
//#define PBAP_ADP_FILE_NAME    (L"../tempvcard.vcf")
#define PBAP_ADP_FILE_NAME     (L"../@btmtk/profile/tempvcard.vcf")
#endif

#define PBAP_BUFFER_MOD 0x00
#define PBAP_FILE_MOD   0x01
#define PBAP_NA_MOD    0x02/*error mod  */
/*
U8 g_pbap_store_mod;
U8 g_pbap_data_file[BT_PBAP_MAX_FILEPATH_NAME_LEN];
U8* g_pbap_data_buffer;
U32 g_pbap_data_size;
*/

typedef struct _PbapVcardFilter
{
    /* Array of 8 bytes for this 64-bit filter value */
    U8 byte[PBAP_FILTER_SIZE];
} PbapVcardFilter;

typedef struct
{
    U32 lap;
    U8 uap;
    U16 nap;
} bt_pbap_bd_addr_struct;




typedef U8 PbapVcardFormat;

#define VCARD_FORMAT_21        0x00     /* Version 2.1 format */
#define VCARD_FORMAT_30        0x01     /* Version 3.0 format */

typedef U8 PbapPhonebookName;
#define PHONEBOOK_PB              0x00
#define PHONEBOOK_ICH             0x01
#define PHONEBOOK_OCH            0x02
#define PHONEBOOK_MCH            0x03
#define PHONEBOOK_CCH             0x04
#define PHONEBOOK_NONA          0x05
#define PHONEBOOK_INVALID        0x06


typedef U8 PbapPhonebookStrorage;

#define PHONEBOOK_STORAGE_TELECOM   0x00
#define PHONEBOOK_STORAGE_SIM_TELECOM     0x01
#define PHONEBOOK_STORAGE_SIM          0x02
#define PHONEBOOK_STORAGE_ROOT         0x03
#define PHONEBOOK_STORAGE_INVALID        0x06
/*SearchAttributes*/
#define PBAP_SEARCH_ATTRIB_NAME        0x00    /* Search by Name */
#define PBAP_SEARCH_ATTRIB_NUMBER      0x01    /* Search by Number */
#define PBAP_SEARCH_ATTRIB_SOUND       0x02    /* Search by Sound */

/*vcard sort order in listing*/
#define PBAP_SORT_ORDER_INDEXED        0x00    /* Indexed sorting */
#define PBAP_SORT_ORDER_ALPHA          0x01    /* Alphabetical sorting */
#define PBAP_SORT_ORDER_PHONETICAL     0x02    /* Phonetical sorting */

/*---------------------------------------------------------------------------
 * PB_MAX_NAME_LEN constant
 *
 *     Maximum number of characters allowed for pathnames + 1 (null-
 *     terminating character).
 */
#define PBAP_MAX_NAME_LEN         128
#define MAX_PBAP_SEARCH_VALUE_LENGTH PBAP_MAX_NAME_LEN

#define PBAP_INVALID_COUNT   0xFFFF

/*---------------------------------------------------------------------------
 * PbStatus type
 *
 *     This type is returned from most phonebook APIs to indicate the success
 *     or failure of the operation. In many cases, BT_STATUS_PENDING
 *     is returned, meaning that a future callback will indicate the
 *     result of the operation.
 */

typedef U8 PbStatus;

#define PB_STATUS_SUCCESS           0   /* XA_STATUS_SUCCESS */
#define PB_STATUS_FAILED            1   /* XA_STATUS_FAILED */
#define PB_STATUS_NO_RESOURCES      12  /* XA_STATUS_NO_RESOURCES */
#define PB_STATUS_NOT_FOUND         13  /* XA_STATUS_NOT_FOUND */
#define PB_STATUS_UNKNOWN_REMOTE    14  /* XA_STATUS_DEVICE_NOT_FOUND */
#define PB_STATUS_INUSE             5   /* XA_STATUS_IN_USE */
#define PB_STATUS_NOT_SUPPORTED     23  /* XA_STATUS_NOT_SUPPORTED */
#define PB_STATUS_PENDING           2   /* XA_STATUS_PENDING */
/* End of PbStatus */
typedef U8 PbapRespCode;

/* Group: Successful response codes */

#define PBRC_CONTINUE              0x10 /* Continue */
#define PBRC_STATUS_SUCCESS        0x20 /* Success */

/* Group: Failure response codes */

#define PBRC_BAD_REQUEST           0x40 /* Bad Request */
#define PBRC_UNAUTHORIZED          0x41 /* Unauthorized */
#define PBRC_FORBIDDEN             0x43 /* Forbidden - operation is understood */
#define PBRC_NOT_FOUND             0x44 /* Not Found */
#define PBRC_NOT_ACCEPTABLE        0x46 /* Not Acceptable */
#define PBRC_PRECONDITION_FAILED   0x4c /* Precondition Failed */
#define PBRC_NOT_IMPLEMENTED       0x51 /* Not Implemented */
#define PBRC_SERVICE_UNAVAILABLE   0x53 /* Service Unavailable */
#define PBRC_LINK_DISCONNECT       0x80 /* Transport connection has been disconnected. */
#define PBRC_INTERNAL_SERVER_ERR   0x50 /* OBRC_INTERNAL_SERVER_ERR */

/* End of PbapRespCode */

#define PBAP_ADP_WORK_FOLDER  (L"D:\\@pbap\\")
#define PBAP_ADP_FOLDER_FILE (L"D:\\@pbap\\folder.tmp")
#define PBAP_ADP_LIST_FILE   (L"D:\\@pbap\\list.tmp")
#define PBAP_ADP_ENTRY_FILE   (L"D:\\@pbap\\entry.tmp")

//FHANDLE PBAP_ADP_FOLDER_FILE ;
//FHANDLE PBAP_ADP_LIST_FILE;
//FHANDLE PBAP_ADP_ENTRY_FILE;
//U8 FOLDER_NAME[256];
//U8 LIST_NAME[256];
//U8 ENTRY_NAME[256];

/* End of PbapAppParmsTag */

/*****************************************************************************
* Structure
*****************************************************************************/

typedef enum
{
    PBAP_CNF_SUCCESS,
    PBAP_CNF_FAILED,
    PBAP_CNF_WRONG_CONN_NUM,
    PBAP_CNF_WRONG_STATE,
    PBAP_CNF_TOTAL
} bt_pbap_cnf_enum;

/*---------------------------------------------------------------------------
 * pbap_set_folder_type_enum type
 *
 *     Flags used in the SetFolder operation.  PBAP specification requires
 *     that the PBAP_SETPB_DONT_CREATE flag is always set.
 */
typedef enum
{
    PBAP_FORWARD_FOLDER = 0,
    PBAP_BACK_FOLDER,
    PBAP_ROOT_FOLDER
} pbap_set_folder_type_enum;

typedef struct
{
    LOCAL_PARA_HDR
    U8 security_level;
    U8 support_repositories;
} bt_pbap_register_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 register_result;
} bt_pbap_register_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
} bt_pbap_deregister_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 deregister_result;
} bt_pbap_deregister_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
} bt_pbap_abort_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
} bt_pbap_oper_success_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
} bt_pbap_disconnect_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    bt_pbap_bd_addr_struct   bd_addr;
    U8  dev_name[BT_PBAP_MAX_DEV_NAME_LEN];
} bt_pbap_authorize_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8               cnf_code;
} bt_pbap_authorize_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    bt_pbap_bd_addr_struct bd_addr;
    kal_uint8 dev_name[BT_PBAP_MAX_DEV_NAME_LEN];
} bt_pbap_connect_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U32 cm_conn_id;
    bt_pbap_bd_addr_struct bd_addr;
    U8 dev_name[BT_PBAP_MAX_DEV_NAME_LEN];
} bt_pbap_client_connect_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U32 cm_conn_id;
    U8 cnf_code;
} bt_pbap_client_connect_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U32 cm_conn_id;
    BOOL disconnect_tp_directly;
} bt_pbap_disconnect_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    U8 dev_name[BT_PBAP_MAX_DEV_NAME_LEN];
    U8 auth_option;
} bt_pbap_client_auth_challenge_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 cancel;
    /* OBEX Authentication password */
    U8 password[20];
    /* OBEX Authentication userId */
    U8 userId[20];
} bt_pbap_client_auth_challenge_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    pbap_set_folder_type_enum type;
    U16 name[PBAP_MAX_NAME_LEN / 2 + 1];
} bt_pbap_set_path_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U16 result;
} bt_pbap_set_path_rsp_struct;


typedef struct
{
    LOCAL_PARA_HDR
    U16 objectName[PBAP_MAX_NAME_LEN / 2 + 1]; /* (*.vcf) */
    PbapVcardFilter filter;
    PbapVcardFormat format;
} bt_pbap_read_entry_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    U8 result;   /* PBSTATUS */
    U8 pbap_data_file[BT_PBAP_MAX_FILEPATH_NAME_LEN];
    U8 cont;
} bt_pbap_read_entry_rsp_struct;



typedef struct
{
    LOCAL_PARA_HDR
    U16 pbName[PBAP_MAX_NAME_LEN / 2 + 1];
    PbapVcardFilter filter;
    PbapVcardFormat format;
    U16 maxListCount;
    U16 listStartOffset;

} bt_pbap_read_folder_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    U8 folderName[PBAP_MAX_NAME_LEN / 2 + 1];
    U8 searchAttribute;
    U8 searchValue[MAX_PBAP_SEARCH_VALUE_LENGTH + 1];
    U8 searchValueLength;
    U8 order;
    U16 maxListCount;
    U16 listStartOffset;

} bt_pbap_read_list_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
} bt_pbap_continue_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    U8 result;
    U8 cont;
    U16 phoneBookSize; /*0xFFFF indicates have only data*/
    U16 newMissedCalls; /*0xFFFF indicates the type is not MCH*/
    U8 pbap_data_file[BT_PBAP_MAX_FILEPATH_NAME_LEN];
} bt_pbap_read_rsp_struct;

typedef bt_pbap_read_rsp_struct bt_pbap_read_folder_rsp_struct;
typedef bt_pbap_read_rsp_struct bt_pbap_read_list_rsp_struct;

#endif//BT_HFG_STRUCT_H

