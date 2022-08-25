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
 * bluetooth_spp_struct.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   struct of local parameter for SPP DUN FAX
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
#ifndef __BLUETOOTH_SPP_STRUCT_H__
#define __BLUETOOTH_SPP_STRUCT_H__

#include "bt_types.h"
#include "bt_mmi.h"
#if defined (BTMTK_ON_WIN32) || defined (BTMTK_ON_WISESDK)
// #include "win_service.h"
#endif  /* BTMTK_ON_MAUI */
#include "bt_message.h"
#ifdef BTMTK_ON_MAUI
#include "uart_sw.h"
#endif  /* BTMTK_ON_MAUI */


/*****************************************************************************
* Definations
*****************************************************************************/
#define MAX_MSG_BUFFER_SIZE 256 //(MAX_ILM_BUFFER_SIZE)
#define SPP_ADP_UART_PUT_BYTE_BUFFER_LENGTH ((MAX_MSG_BUFFER_SIZE < 128)?64:(MAX_MSG_BUFFER_SIZE - 128))
#define SPP_ADP_UART_GET_BYTE_BUFFER_LENGTH ((MAX_MSG_BUFFER_SIZE < 128)?64:(MAX_MSG_BUFFER_SIZE - 128))
#define SPP_MAX_SERVICE_NAME_LENGTH 50

/* Profile ID */
#define SPP_PROFILE (0)
#define DUN_PROFILE (1)
#define HFG_PROFILE (2)
#define FAX_PROFILE (3)

/* Define Error code for SPP Client connection */
#define SPPC_CONNECT_SUCCESS       0x0000
#define SPPC_CREATE_ACL_LINK_ERROR 0x0001
#define SPPC_SDP_QUERY_REQ_FAILED  0x0002
#define SPPC_SDP_QUERY_REQ_INVALID_PARM 0x0003
#define SPPC_SDP_QUERY_RSP_FAILED 0x0004
#define SPPC_SERVICE_LEVEL_CON_FAILED 0x0005
#define SPPC_NOT_CONNECTED_BUT_RECV_CLOSED 0x0006
#define SPPC_NO_AVAILABLE_CLI_DEVS 0x0007

#ifdef BTMTK_ON_MAUI
#define SPPC_TX_RX_BUFFER_ASSIGN_ERROR 0x0008 
#endif
/* Define Error code for SPP Client/Server disconnection: 2007-0711 */
#define SPP_DISCONNECT_SUCCESS 0x0000
#define NOT_SUCCESS_RETURN_FROM_SPP_DISC_FUNC 0x0001


/*****************************************************************************
* Typedef
*****************************************************************************/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#ifdef BTMTK_ON_MAUI
#define MSG_ID_BT_SPP_CONNECT_IND_RES MSG_ID_BT_SPP_CONNECT_IND_RSP
#endif

#ifndef BTMTK_ON_MAUI
/* In MAUI, these wrapper should be removed. */
#define MSG_ID_UART_PLUGOUT_IND MSG_ID_BT_SPP_UART_PLUGOUT_IND
#define MSG_ID_UART_READY_TO_READ_IND MSG_ID_BT_SPP_UART_READY_TO_READ_IND
#define MSG_ID_UART_READY_TO_WRITE_IND MSG_ID_BT_SPP_UART_READY_TO_WRITE_IND
#endif  /* BTMTK_ON_MAUI */

#ifdef __SPP_SHARED_MEMORY__
#define SPP_PUT_DATA_SHARED_BUFFER_SIZE (1024 * 16)
#define SPP_GET_DATA_SHARED_BUFFER_SIZE (1024 * 16)
#define SPP_PUT_ASHM_NAME "mtk.bt.profile.spp.put.ashm"
#define SPP_GET_ASHM_NAME "mtk.bt.profile.spp.get.ashm"
#endif	/* __SPP_SHARED_MEMORY__ */

/*****************************************************************************
* Structure
*****************************************************************************/

/* MSG_ID_BT_SPP_CONNECT_REQ */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    U32 lap;
    U8 uap;
    U16 nap;
    U8 server_chnl_num;
#ifndef BTMTK_ON_MAUI
    U16 uuid;
#else
    U8 uuid[16];
    U8* txBufPtr;  /* User set tx/rx buffer */
    U8* rxBufPtr;
    U32 txBufSize; /* User set tx/rx buffer size */
    U32 rxBufSize;
    U32 req_id;  
    U8 sec_level;
#endif /*BTMTK_ON_MAUI*/
} bt_spp_connect_req_struct;

/* MSG_ID_BT_SPP_SEND_DATA_REQ */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
} bt_spp_send_data_req_struct;

/* MSG_ID_BT_SPP_GET_DATA_REQ */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
} bt_spp_get_data_req_struct;

/* MSG_ID_BT_SPP_CONNECT_IND */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    U8 cid;  /* connection id */
    U32 lap;
    U8 uap;
    U16 nap;
} bt_spp_connect_ind_struct;

/* MSG_ID_BT_SPP_DISCONNECT_REQ */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
} bt_spp_disconnect_req_struct;

typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
} bt_spp_audio_connect_req_struct;

typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
} bt_spp_audio_disconnect_req_struct;

/* MSG_ID_BT_SPP_DISCONNECT_IND */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
} bt_spp_disconnect_ind_struct;

typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    U8 result;
} bt_spp_audio_connect_cnf_struct;

typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
} bt_spp_audio_connect_ind_struct;

typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    U8 result;
} bt_spp_audio_disconnect_cnf_struct;

typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
} bt_spp_audio_disconnect_ind_struct;

/* MSG_ID_BT_SPP_DISCONNECT_CNF */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port;     /* virtual port number */
    U8 cid;      /* connection id */
    U32 lap;
    U8 uap;
    U16 nap;
    U8 result;   /* This is result field of this returned cnf msg */
} bt_spp_disconnect_cnf_struct;

/* MSG_ID_BT_SPP_AUTH_REQ */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */

} bt_spp_auth_req_struct;

/* MSG_ID_BT_SPP_CONNECT_IND_REQ */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    U32 lap;
    U8 uap;
    U16 nap;
#ifdef BTMTK_ON_MAUI
	U8 dev_name[SPP_MAX_SERVICE_NAME_LENGTH];
#endif
} bt_spp_connect_ind_req_struct;

/* MSG_ID_BT_SPP_CONNECT_IND_RSP */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    U32 lap;
    U8 uap;
    U16 nap;
#ifdef BTMTK_ON_MAUI
	U8 *txBufPtr;  /* User set tx/rx buffer */
	U8 *rxBufPtr;
	U32 txBufSize; /* User set tx/rx buffer size */
	U32 rxBufSize;
#endif /*BTMTK_ON_MAUI*/
    U8 result;
} bt_spp_connect_ind_rsp_struct;

/* MSG_ID_BT_DUN_CONNECT_IND_REQ */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    U32 lap;
    U8 uap;
    U16 nap;
} bt_dun_connect_ind_req_struct;

/* MSG_ID_BT_DUN_CONNECT_IND_RSP */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    U32 lap;
    U8 uap;
    U16 nap;
    U8 result;
} bt_dun_connect_ind_rsp_struct;

/* MSG_ID_BT_DUN_DISCONNECT_CNF */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port;     /* virtual port number */
    U8 cid;      /* connection id */
    U32 lap;
    U8 uap;
    U16 nap;
    U8 result;   /* This is result field of this returned cnf msg */
} bt_dun_disconnect_cnf_struct;


/* MSG_ID_BT_FAX_CONNECT_IND_REQ */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    U32 lap;
    U8 uap;
    U16 nap;
} bt_fax_connect_ind_req_struct;

/* MSG_ID_BT_FAX_CONNECT_IND_RSP */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    U32 lap;
    U8 uap;
    U16 nap;
    U8 result;
} bt_fax_connect_ind_rsp_struct;

/* MSG_ID_BT_FAX_DISCONNECT_CNF */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port;     /* virtual port number */
    U8 cid;      /* connection id */
    U32 lap;
    U8 uap;
    U16 nap;
    U8 result;   /* This is result field of this returned cnf msg */
} bt_fax_disconnect_cnf_struct;


/* MSG_ID_BT_SPP_CONNECT_CNF */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port;             /* virtual port number */
    U8 cid;              /* connection id */
    U32 lap;
    U8 uap;
    U16 nap;
    U8 result;           /* This is result field of this returned cnf msg */
    U8 server_chnl_num;
#ifdef BTMTK_ON_MAUI
	U32 req_id;
#endif /*BTMTK_ON_MAUI*/
} bt_spp_connect_cnf_struct;

/* MSG_ID_BT_SPP_AUTH_RSP */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port;     /* virtual port number */
    BOOL result;    /* TRUE: accepted by MMI */
} bt_spp_auth_rsp_struct;

/* MSG_ID_BT_SPP_UART_OWNER_IND */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port;
    U8 profile;
} bt_spp_uart_owner_ind_struct;

/* MSG_ID_BT_SPP_UART_OWNER_CNF */

typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port;
} bt_spp_uart_owner_cnf_struct;

/* MSG_ID_BT_SPP_UART_PLUGOUT_CNF */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port;
} bt_spp_uart_plugout_cnf_struct;

/* MSG_ID_BT_SPP_SCO_RSSI_IND */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    U8 bd_address[6];
    U8 rssi_value;
} bt_spp_sco_rssi_ind_struct;

/* MSG_ID_BT_DUN_CONNECT_REQ */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    U32 lap;
    U8 uap;
    U16 nap;
    U8 server_chnl_num;
} bt_dun_connect_req_struct;

/* MSG_ID_BT_DUN_CONNECT_IND */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    U8 cid;  /* connection id */
    U32 lap;
    U8 uap;
    U16 nap;
} bt_dun_connect_ind_struct;

/* MSG_ID_BT_DUN_DISCONNECT_REQ */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
} bt_dun_disconnect_req_struct;

/* MSG_ID_BT_DUN_DISCONNECT_IND */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
} bt_dun_disconnect_ind_struct;

/* MSG_ID_BT_DUN_AUTH_RSP : add 2007-01-12 */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port;     /* virtual port number */
    BOOL result;    /* TRUE: accepted by MMI */
} bt_dun_auth_rsp_struct;

/* MSG_ID_BT_DUN_CONNECT_CNF */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port;             /* virtual port number */
    U8 cid;              /* connection id */
    U32 lap;
    U8 uap;
    U16 nap;
    U8 result;           /* This is result field of this returned cnf msg */
    U8 server_chnl_num;
} bt_dun_connect_cnf_struct;

/* MSG_ID_BT_FAX_CONNECT_IND */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    U8 cid;  /* connection id */
    U32 lap;
    U8 uap;
    U16 nap;
} bt_fax_connect_ind_struct;

/* MSG_ID_BT_FAX_DISCONNECT_REQ */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
} bt_fax_disconnect_req_struct;

/* MSG_ID_BT_FAX_DISCONNECT_IND */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
} bt_fax_disconnect_ind_struct;

/* MSG_ID_BT_FAX_AUTH_RSP : add 2007-01-12 */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port;     /* virtual port number */
    BOOL result;    /* TRUE: accepted by MMI */
} bt_fax_auth_rsp_struct;

/* MSG_ID_BT_FAX_CONNECT_CNF */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port;             /* virtual port number */
    U8 cid;              /* connection id */
    U32 lap;
    U8 uap;
    U16 nap;
    U8 result;           /* This is result field of this returned cnf msg */
    U8 server_chnl_num;
} bt_fax_connect_cnf_struct;



/////////////////////////////////////////////////////////////////
// External ADP <==> Internal ADP
/////////////////////////////////////////////////////////////////
/* Wrapper for original structure */
/* MSG_ID_BT_SPP_CONNECT_REQ */
typedef bt_spp_connect_req_struct btmtk_spp_connect_req_struct;

/* MSG_ID_BT_SPP_SEND_DATA_REQ */
typedef bt_spp_send_data_req_struct btmtk_spp_send_data_req_struct;

/* MSG_ID_BT_SPP_GET_DATA_REQ */
typedef bt_spp_get_data_req_struct btmtk_spp_get_data_req_struct;

/* MSG_ID_BT_SPP_CONNECT_IND */
typedef bt_spp_connect_ind_struct btmtk_spp_connect_ind_struct;

/* MSG_ID_BT_SPP_DISCONNECT_REQ */
typedef bt_spp_disconnect_req_struct btmtk_spp_disconnect_req_struct;

typedef bt_spp_audio_connect_req_struct btmtk_spp_audio_connect_req_struct;

typedef bt_spp_audio_disconnect_req_struct btmtk_spp_audio_disconnect_req_struct;

/* MSG_ID_BT_SPP_DISCONNECT_IND */
typedef bt_spp_disconnect_ind_struct btmtk_spp_disconnect_ind_struct;

typedef bt_spp_audio_connect_cnf_struct btmtk_spp_audio_connect_cnf_struct;

typedef bt_spp_audio_connect_ind_struct btmtk_spp_audio_connect_ind_struct;

typedef bt_spp_audio_disconnect_cnf_struct btmtk_spp_audio_disconnect_cnf_struct;

typedef bt_spp_audio_disconnect_ind_struct btmtk_spp_audio_disconnect_ind_struct;

/* MSG_ID_BT_SPP_DISCONNECT_CNF */
typedef bt_spp_disconnect_cnf_struct btmtk_spp_disconnect_cnf_struct;

/* MSG_ID_BT_SPP_AUTH_REQ */
typedef bt_spp_auth_req_struct btmtk_spp_auth_req_struct;

/* MSG_ID_BT_DUN_AUTH_REQ */
typedef bt_spp_auth_req_struct btmtk_dun_auth_req_struct;

/* MSG_ID_BT_FAX_AUTH_REQ */
typedef bt_spp_auth_req_struct btmtk_fax_auth_req_struct;

/* MSG_ID_BT_SPP_CONNECT_IND_REQ */
typedef bt_spp_connect_ind_req_struct btmtk_spp_connect_ind_req_struct;

/* MSG_ID_BT_SPP_CONNECT_IND_RES */
typedef bt_spp_connect_ind_rsp_struct btmtk_spp_connect_ind_rsp_struct;
#ifdef BTMTK_ON_MAUI
typedef bt_spp_connect_ind_rsp_struct bt_spp_connect_ind_res_struct;
#endif

/* MSG_ID_BT_DUN_CONNECT_IND_REQ */
typedef bt_dun_connect_ind_req_struct btmtk_dun_connect_ind_req_struct;

/* MSG_ID_BT_DUN_CONNECT_IND_RES */
typedef bt_dun_connect_ind_rsp_struct btmtk_dun_connect_ind_rsp_struct;

/* MSG_ID_BT_DUN_DISCONNECT_CNF */
typedef bt_dun_disconnect_cnf_struct btmtk_dun_disconnect_cnf_struct;

/* MSG_ID_BT_FAX_CONNECT_IND_REQ */
typedef bt_fax_connect_ind_req_struct btmtk_fax_connect_ind_req_struct;

/* MSG_ID_BT_FAX_CONNECT_IND_RES */
typedef bt_fax_connect_ind_rsp_struct btmtk_fax_connect_ind_rsp_struct;

/* MSG_ID_BT_FAX_DISCONNECT_CNF */
typedef bt_fax_disconnect_cnf_struct btmtk_fax_disconnect_cnf_struct;

/* MSG_ID_BT_SPP_CONNECT_CNF */
typedef bt_spp_connect_cnf_struct btmtk_spp_connect_cnf_struct;

/* MSG_ID_BT_SPP_AUTH_RSP */
typedef bt_spp_auth_rsp_struct btmtk_spp_auth_rsp_struct;

/* MSG_ID_BT_SPP_UART_OWNER_IND */
typedef bt_spp_uart_owner_ind_struct btmtk_spp_uart_owner_ind_struct;

/* MSG_ID_BT_SPP_UART_OWNER_CNF */
typedef bt_spp_uart_owner_cnf_struct btmtk_spp_uart_owner_cnf_struct;

/* MSG_ID_BT_SPP_UART_PLUGOUT_CNF */
typedef bt_spp_uart_plugout_cnf_struct btmtk_spp_uart_plugout_cnf_struct;

/* MSG_ID_BT_SPP_SCO_RSSI_IND */
typedef bt_spp_sco_rssi_ind_struct btmtk_spp_sco_rssi_ind_struct;

/* MSG_ID_BT_DUN_CONNECT_REQ */
typedef bt_dun_connect_req_struct btmtk_dun_connect_req_struct;

/* MSG_ID_BT_DUN_CONNECT_IND */
typedef bt_dun_connect_ind_struct btmtk_dun_connect_ind_struct;

/* MSG_ID_BT_DUN_DISCONNECT_REQ */
typedef bt_dun_disconnect_req_struct btmtk_dun_disconnect_req_struct;

/* MSG_ID_BT_DUN_DISCONNECT_IND */
typedef bt_dun_disconnect_ind_struct btmtk_dun_disconnect_ind_struct;

/* MSG_ID_BT_DUN_AUTH_RSP : add 2007-01-12 */
typedef bt_dun_auth_rsp_struct btmtk_dun_auth_rsp_struct;

/* MSG_ID_BT_DUN_CONNECT_CNF */
typedef bt_dun_connect_cnf_struct btmtk_dun_connect_cnf_struct;

/* MSG_ID_BT_FAX_CONNECT_IND */
typedef bt_fax_connect_ind_struct btmtk_fax_connect_ind_struct;

/* MSG_ID_BT_FAX_DISCONNECT_REQ */
typedef bt_fax_disconnect_req_struct btmtk_fax_disconnect_req_struct;

/* MSG_ID_BT_FAX_DISCONNECT_IND */
typedef bt_fax_disconnect_ind_struct btmtk_fax_disconnect_ind_struct;

/* MSG_ID_BT_FAX_AUTH_RSP : add 2007-01-12 */
typedef bt_fax_auth_rsp_struct btmtk_fax_auth_rsp_struct;

typedef bt_fax_connect_cnf_struct btmtk_fax_connect_cnf_struct;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/* MSG_ID_BT_SPP_REGISTER_CALLBACK_CNF */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    U8 profile;
} btmtk_spp_register_callback_cnf_struct;

typedef btmtk_spp_register_callback_cnf_struct bt_spp_register_callback_cnf_struct;

////////////////////
/* UART related API */

/* MSG_ID_BT_SPP_UART_PUT_BYTES_REQ */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    //module_type owner;
    U16 length;
#ifdef __SPP_SHARED_MEMORY__
    U8 *buffer;
#else
    U8 buffer[SPP_ADP_UART_PUT_BYTE_BUFFER_LENGTH];
#endif	/* __SPP_SHARED_MEMORY__ */
} btmtk_spp_uart_put_bytes_req_struct;

typedef btmtk_spp_uart_put_bytes_req_struct bt_spp_uart_put_bytes_req_struct;

/* MSG_ID_BT_SPP_UART_PUT_BYTES_CNF */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    U16 length;
    U8 profile;
} btmtk_spp_uart_put_bytes_cnf_struct;

typedef btmtk_spp_uart_put_bytes_cnf_struct bt_spp_uart_put_bytes_cnf_struct;

/* MSG_ID_BT_SPP_UART_GET_BYTES_REQ */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    //module_type owner;
    U16 length;
} btmtk_spp_uart_get_bytes_req_struct;

typedef btmtk_spp_uart_get_bytes_req_struct bt_spp_uart_get_bytes_req_struct;

/* MSG_ID_BT_SPP_UART_GET_BYTES_CNF */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    U16 length;
#ifdef __SPP_SHARED_MEMORY__
    U8 *buffer;
#else
    U8 buffer[SPP_ADP_UART_GET_BYTE_BUFFER_LENGTH];
#endif	/* __SPP_SHARED_MEMORY__ */
    U8 profile;
} btmtk_spp_uart_get_bytes_cnf_struct;

typedef btmtk_spp_uart_get_bytes_cnf_struct bt_spp_uart_get_bytes_cnf_struct;

/* MSG_ID_BT_SPP_UART_OPEN_REQ */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    //module_type owner;
} btmtk_spp_uart_open_req_struct;

typedef btmtk_spp_uart_open_req_struct bt_spp_uart_open_req_struct;

/* MSG_ID_BT_SPP_UART_OPEN_CNF */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    BOOL result;
    U8 profile;
} btmtk_spp_uart_open_cnf_struct;

typedef btmtk_spp_uart_open_cnf_struct bt_spp_uart_open_cnf_struct;

/* MSG_ID_BT_SPP_UART_CLOSE_REQ */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    //module_type owner;
} btmtk_spp_uart_close_req_struct;

typedef btmtk_spp_uart_close_req_struct bt_spp_uart_close_req_struct;

/* MSG_ID_BT_SPP_UART_CLOSE_CNF */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    U8 profile;
} btmtk_spp_uart_close_cnf_struct;

typedef btmtk_spp_uart_close_cnf_struct bt_spp_uart_close_cnf_struct;

/* MSG_ID_BT_SPP_UART_GET_BYTES_AVAIL_REQ */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
} btmtk_spp_uart_get_bytes_avail_req_struct;

typedef btmtk_spp_uart_get_bytes_avail_req_struct bt_spp_uart_get_bytes_avail_req_struct;

/* MSG_ID_BT_SPP_UART_GET_BYTES_AVAIL_CNF */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    U16 length;
    U8 profile;
} btmtk_spp_uart_get_bytes_avail_cnf_struct;

typedef btmtk_spp_uart_get_bytes_avail_cnf_struct bt_spp_uart_get_bytes_avail_cnf_struct;

/* MSG_ID_BT_SPP_UART_GET_TX_ROOM_LEFT_REQ */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
} btmtk_spp_uart_get_tx_room_left_req_struct;

typedef btmtk_spp_uart_get_tx_room_left_req_struct bt_spp_uart_get_tx_room_left_req_struct;

/* MSG_ID_BT_SPP_UART_GET_TX_ROOM_LEFT_CNF */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    U16 length;
    U8 profile;
} btmtk_spp_uart_get_tx_room_left_cnf_struct;

typedef btmtk_spp_uart_get_tx_room_left_cnf_struct bt_spp_uart_get_tx_room_left_cnf_struct;


/* MSG_ID_BT_SPP_UART_SET_OWNER_REQ */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    //module_type owner;
} btmtk_spp_uart_set_owner_req_struct;

typedef btmtk_spp_uart_set_owner_req_struct bt_spp_uart_set_owner_req_struct;

/* MSG_ID_BT_SPP_UART_SET_OWNER_CNF */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    U8 profile;
} btmtk_spp_uart_set_owner_cnf_struct;

typedef btmtk_spp_uart_set_owner_cnf_struct bt_spp_uart_set_owner_cnf_struct;

/* MSG_ID_BT_SPP_UART_CTRL_DCD_REQ */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    IO_level sdcd;
    //module_type owner;
} btmtk_spp_uart_ctrl_dcd_req_struct;

typedef btmtk_spp_uart_ctrl_dcd_req_struct bt_spp_uart_ctrl_dcd_req_struct;

/* MSG_ID_BT_SPP_UART_CTRL_DCD_CNF */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    U8 profile;
} btmtk_spp_uart_ctrl_dcd_cnf_struct;

typedef btmtk_spp_uart_ctrl_dcd_cnf_struct bt_spp_uart_ctrl_dcd_cnf_struct;

/* MSG_ID_BT_SPP_UART_CTRL_BREAK_REQ */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    IO_level sbreak;
    //module_type owner;
} btmtk_spp_uart_ctrl_break_req_struct;

typedef btmtk_spp_uart_ctrl_break_req_struct bt_spp_uart_ctrl_break_req_struct;

/* MSG_ID_BT_SPP_UART_CTRL_BREAK_CNF */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    U8 profile;
} btmtk_spp_uart_ctrl_break_cnf_struct;

typedef btmtk_spp_uart_ctrl_break_cnf_struct bt_spp_uart_ctrl_break_cnf_struct;

/* MSG_ID_BT_SPP_UART_GET_OWNER_ID_REQ */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
} btmtk_spp_uart_get_owner_id_req_struct;

typedef btmtk_spp_uart_get_owner_id_req_struct bt_spp_uart_get_owner_id_req_struct;

/* MSG_ID_BT_SPP_UART_GET_OWNER_ID_CNF */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    //module_type owner;
    U8 profile;
} btmtk_spp_uart_get_owner_id_cnf_struct;

typedef btmtk_spp_uart_get_owner_id_cnf_struct bt_spp_uart_get_owner_id_cnf_struct;

/* MSG_ID_BT_SPP_UART_CLR_RX_BUFFER_REQ */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    //module_type owner;
} btmtk_spp_uart_clr_rx_buffer_req_struct;

typedef btmtk_spp_uart_clr_rx_buffer_req_struct bt_spp_uart_clr_rx_buffer_req_struct;

/* MSG_ID_BT_SPP_UART_CLR_RX_BUFFER_CNF */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    U8 profile;
} btmtk_spp_uart_clr_rx_buffer_cnf_struct;

typedef btmtk_spp_uart_clr_rx_buffer_cnf_struct bt_spp_uart_clr_rx_buffer_cnf_struct;

/* MSG_ID_BT_SPP_UART_CLR_TX_BUFFER_REQ */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    //module_type owner;
} btmtk_spp_uart_clr_tx_buffer_req_struct;

typedef btmtk_spp_uart_clr_tx_buffer_req_struct bt_spp_uart_clr_tx_buffer_req_struct;

/* MSG_ID_BT_SPP_UART_CLR_TX_BUFFER_CNF */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    U8 profile;
} btmtk_spp_uart_clr_tx_buffer_cnf_struct;

typedef btmtk_spp_uart_clr_tx_buffer_cnf_struct bt_spp_uart_clr_tx_buffer_cnf_struct;

/* MSG_ID_BT_SPP_UART_DATA_AVAILABLE_IND */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    U16 length;
#ifdef __SPP_SHARED_MEMORY__
    U8 *buffer;
#else
    U8 buffer[SPP_ADP_UART_GET_BYTE_BUFFER_LENGTH];
#endif	/* __SPP_SHARED_MEMORY__ */
    U8 profile;
} btmtk_spp_uart_data_available_ind_struct;

typedef btmtk_spp_uart_data_available_ind_struct bt_spp_uart_data_available_ind_struct;

/* MSG_ID_BT_SPP_UART_DATA_AVAILABLE_IND_RSP */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    U16 length;
} btmtk_spp_uart_data_available_ind_rsp_struct;

typedef btmtk_spp_uart_data_available_ind_rsp_struct bt_spp_uart_data_available_ind_rsp_struct;

#ifdef __SPP_SHARED_MEMORY__
/* MSG_ID_BT_UART_ASSIGN_BUFFER_REQ */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
    U8 *getBufPtr;
    U16 getBufSize;
} btmtk_spp_uart_assign_buffer_req_struct;

typedef btmtk_spp_uart_assign_buffer_req_struct bt_spp_uart_assign_buffer_req_struct;

/* MSG_ID_BT_UART_ASSIGN_BUFFER_CNF */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    UART_PORT port; /* virtual port number */
} btmtk_spp_uart_assign_buffer_cnf_struct;

typedef btmtk_spp_uart_assign_buffer_cnf_struct bt_spp_uart_assign_buffer_cnf_struct;
#endif	/* __SPP_SHARED_MEMORY__ */

/* MSG_ID_BT_SPP_UART_PLUGOUT_IND */
typedef struct
{
    U8 	ref_count;
    U16 	msg_len;			/* LOCAL_PARA_HDR */
    UART_PORT 	port;
    U8 profile;
} btmtk_spp_uart_plugout_ind_struct;

typedef btmtk_spp_uart_plugout_ind_struct bt_spp_uart_plugout_ind_struct;

/* MSG_ID_BT_SPP_UART_READY_TO_READ_IND */
typedef struct
{
    U8 	ref_count;
    U16 	msg_len;			/* LOCAL_PARA_HDR */
    UART_PORT 	port;
    U8 profile;
} btmtk_spp_uart_ready_to_read_ind_struct;

typedef btmtk_spp_uart_ready_to_read_ind_struct bt_spp_uart_ready_to_read_ind_struct;

/* MSG_ID_BT_SPP_UART_READY_TO_WRITE_IND */
typedef struct
{
    U8 	ref_count;
    U16 	msg_len;			/* LOCAL_PARA_HDR */
    UART_PORT 	port;
    U8 profile;
} btmtk_spp_uart_ready_to_write_ind_struct;

typedef btmtk_spp_uart_ready_to_write_ind_struct bt_spp_uart_ready_to_write_ind_struct;

/* MSG_ID_BT_SPP_ACTIVATE_REQ */
typedef struct
{
    U8		ref_count;
    U16 	msg_len;			/* LOCAL_PARA_HDR */
    char 	svcName[SPP_MAX_SERVICE_NAME_LENGTH]; 
#ifndef BTMTK_ON_MAUI
    U16			svcUUID;
    U8*		getBufPtr;
    U16		getBufSize;
#else
	U8		svcUUID[16];
	module_type owner;
	U8		secLevel;
	U32 	req_id;
#endif /*BTMTK_ON_MAUI*/
} btmtk_spp_activate_req_struct;

typedef btmtk_spp_activate_req_struct bt_spp_activate_req_struct;

/* MSG_ID_BT_SPP_ACTIVATE_CNF */
typedef struct
{
    U8 	ref_count;
    U16 	msg_len;			/* LOCAL_PARA_HDR */
    UART_PORT 	port;
    BT_BOOL		result;
#ifdef BTMTK_ON_MAUI
    U8		uuid[16];
    U32 	req_id;
#endif /*BTMTK_ON_MAUI*/
} btmtk_spp_activate_cnf_struct;

typedef btmtk_spp_activate_cnf_struct bt_spp_activate_cnf_struct;

/* MSG_ID_BT_SPP_DEACTIVATE_REQ */
typedef struct
{
    U8 	ref_count;
    U16 	msg_len;			/* LOCAL_PARA_HDR */
    UART_PORT 	port;
} btmtk_spp_deactivate_req_struct;

typedef btmtk_spp_deactivate_req_struct bt_spp_deactivate_req_struct;

/* MSG_ID_BT_SPP_DEACTIVATE_CNF */
typedef struct
{
    U8 	ref_count;
    U16 	msg_len;			/* LOCAL_PARA_HDR */
    UART_PORT 	port;
    BT_BOOL		result;
} btmtk_spp_deactivate_cnf_struct;

typedef btmtk_spp_deactivate_cnf_struct bt_spp_deactivate_cnf_struct;

/* MSG_ID_BT_DUN_ACTIVATE_CNF */
typedef struct
{
    U8 	ref_count;
    U16 	msg_len;			/* LOCAL_PARA_HDR */
    UART_PORT 	port;
    BT_BOOL		result;
} btmtk_dun_activate_cnf_struct;

typedef btmtk_dun_activate_cnf_struct bt_dun_activate_cnf_struct;

/* MSG_ID_BT_DUN_DEACTIVATE_REQ */
typedef struct
{
    U8 	ref_count;
    U16 	msg_len;			/* LOCAL_PARA_HDR */
    UART_PORT 	port;
} btmtk_dun_deactivate_req_struct;

typedef btmtk_dun_deactivate_req_struct bt_dun_deactivate_req_struct;

/* MSG_ID_BT_DUN_DEACTIVATE_CNF */
typedef struct
{
    U8 	ref_count;
    U16 	msg_len;			/* LOCAL_PARA_HDR */
    UART_PORT 	port;
    BT_BOOL		result;
} btmtk_dun_deactivate_cnf_struct;

typedef btmtk_dun_deactivate_cnf_struct bt_dun_deactivate_cnf_struct;

/* MSG_ID_BT_FAX_ACTIVATE_CNF */
typedef struct
{
    U8 	ref_count;
    U16 	msg_len;			/* LOCAL_PARA_HDR */
    UART_PORT 	port;
    BT_BOOL		result;
} btmtk_fax_activate_cnf_struct;

typedef btmtk_fax_activate_cnf_struct bt_fax_activate_cnf_struct;


/* MSG_ID_BT_FAX_DEACTIVATE_REQ */
typedef struct
{
    U8 	ref_count;
    U16 	msg_len;			/* LOCAL_PARA_HDR */
    UART_PORT 	port;
} btmtk_fax_deactivate_req_struct;

typedef btmtk_fax_deactivate_req_struct bt_fax_deactivate_req_struct;

/* MSG_ID_BT_FAX_DEACTIVATE_CNF */
typedef struct
{
    U8 	ref_count;
    U16 	msg_len;			/* LOCAL_PARA_HDR */
    UART_PORT 	port;
    BT_BOOL		result;
} btmtk_fax_deactivate_cnf_struct;

typedef btmtk_fax_deactivate_cnf_struct bt_fax_deactivate_cnf_struct;

/* MSG_ID_BT_FAX_CONNECT_REQ */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    U32 lap;
    U8 uap;
    U16 nap;
    U8 server_chnl_num;
} btmtk_fax_connect_req_struct;

typedef btmtk_fax_connect_req_struct bt_fax_connect_req_struct;


#endif	// __BLUETOOTH_SPP_STRUCT_H__


