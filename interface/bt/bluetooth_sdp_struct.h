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
 *   bluetooth_sdp_struct.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __BLUETOOTH_SDP_STRUCT_H_
#define __BLUETOOTH_SDP_STRUCT_H_

#include "bluetooth_struct.h"

#define BT_SDPDB_MAX_ATTR_NO (15)
#define BT_SDPDB_MAX_ATTR_SIZE (80)
#define BT_SDPDB_MAX_SERVICE_RECORD_NO 10
#ifdef BTMTK_ON_LINUX
#define BT_SDPDB_MAX_SERVICE_RECORD_SIZE 256
#endif

typedef enum
{
    BTSDPDBAPP_SUCCESS,
    BTSDPDBAPP_FAILED,
    BTSDPDBAPP_SDP_REGISTER_FAILED,
    BTSDPDBAPP_INVALID_HANDLE,
    BTSDPDBAPP_SDP_DEREGISTER_FAILED,
    BTSDPDBAPP_SDP_DDB_FULL,
    BTSDPDBAPP_SDP_RECORD_SYNTAX_ERROR,
    BTSDPDBAPP_SDP_RECORD_TOO_LARGE,
    BTSDPDBAPP_SDP_RECORD_ATTRIBUTE_BUFFER_TOO_SMALL
} bt_sdpdb_result;

typedef enum
{
    BT_APP_REGISTER_RECORD = 1,
    BT_APP_UPDATE_RECORD
} bt_sdpdb_op_type;

typedef struct
{
    LOCAL_PARA_HDR
    U32 uuid;
} bt_sdpdb_register_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U32 uuid;
} bt_sdpdb_deregister_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 result;
    U32 uuid;
} bt_sdpdb_register_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 result;
    U32 uuid;
} bt_sdpdb_deregister_cnf_struct;

typedef struct
{
    U16 id;
    U16 len;
    U8 value[BT_SDPDB_MAX_ATTR_SIZE];
} bt_sdpdb_attr_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 attr_no;
    bt_sdpdb_attr_struct attrs[BT_SDPDB_MAX_ATTR_NO];
} bt_sdpdb_add_record_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 result;
} bt_sdpdb_add_record_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U32 identify;
} bt_app_sdpdb_get_handle_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    bt_sdpdb_result result;
    U32 handle;
    U32 identify;
} bt_app_sdpdb_get_handle_cnf_struct;

/* MSG_ID_BT_SDPDB_REGISTER_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    U32 handle;
    bt_sdpdb_op_type type;
#ifdef BTMTK_ON_LINUX
    U8 record_raw[BT_SDPDB_MAX_SERVICE_RECORD_SIZE];
    U16 record_raw_length;
    U32 identify;
#else
    U8 *record_raw;
    U16 record_raw_length;
    U8 *attribs_buffer;
    U16 attribs_buffer_size;
#endif
} bt_app_sdpdb_register_req_struct;

/* MSG_ID_BT_SDPDB_REGISTER_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    bt_sdpdb_result result;
    U32 handle;
    U32 identify;
} bt_app_sdpdb_register_cnf_struct;

/* MSG_ID_BT_SDPDB_DEREGISTER_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    U32 handle;
} bt_app_sdpdb_deregister_req_struct;

/* MSG_ID_BT_SDPDB_DEREGISTER_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    bt_sdpdb_result result;
    U32 handle;
} bt_app_sdpdb_deregister_cnf_struct;

/* MSG_ID_BT_SDPDB_RETRIEVE_RECOED_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    U32 handle;
} bt_app_sdpdb_retrieve_record_req_struct;

/* MSG_ID_BT_SDPDB_RETRIEVE_RECOED_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    U8 result;
    U32 handle;
    U8 *record;
    U16 record_size;
} bt_app_sdpdb_retrieve_record_cnf_struct;

#endif /* __BLUETOOTH_BM_STRUCT_H_ */

