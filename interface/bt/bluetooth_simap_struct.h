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
 * bluetooth_simap_struct.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   struct of local parameter for SIMAP
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __BLUETOOTH_SIMAP_STRUCT_H__
#define __BLUETOOTH_SIMAP_STRUCT_H__

#include "bt_mmi.h"
#include "bt_message.h"

/* The following defined structs for SIM Access Profile (SAP) */

#define APDU_REQ_MAX_LEN    261 /* 256 bytes for data + 5 bytes header information: CLA,INS,P1,P2,P3 */
#define APDU_RSP_MAX_LEN    258 /* 256 bytes for data + 2 bytes status word SW1 and SW2 */
#define ATR_MAX_LEN                40

#define SIMAP_INJECT_MESSAGE_LENGTH_MAX 100

/*---------------------------------------------------------------------------
 * SimDisconnectType type
 *
 *     When the server wishes to disconnect, it can send a disconnect
 *     indication to the client.  There are two types of disconnect that can
 *     be initiated by the server.
 */
typedef U8 SimDisconnectType;

/** A graceful disconnect allows the client to continue sending APDU's until
 *  while the GSM connection is terminated.  The client will then initiate
 *  the disconnect process.  Until the client initiates the disconnect process,
 *  the connection stays open.
 */
#define SIM_DISCONNECT_GRACEFUL   0x00

/** An immediate disconnect terminates the connection immediately.  No response
 *  is required from the client.  The GSM connection should be terminated
 *  immediately.
 */
#define SIM_DISCONNECT_IMMEDIATE  0x01

/* End of SimDisconnectType */

/*---------------------------------------------------------------------------
 * SimCardStatus type
 *     This type of the parameter StatusChangeis defined in the command STATUS_IND
 *     When the status of the SIM changes, the server must send the new status
 *     to the client.  During the connect procedure, the status must also be
 *     sent.
 */
typedef U8 SimCardStatus;

/** The status of the card is unknown.
 */
#define SIM_CARD_STATUS_UNKNOWN          0x00

/** The card has been reset and is available.
 */
#define SIM_CARD_STATUS_RESET            0x01

/** The card is not accessible.
 */
#define SIM_CARD_STATUS_NOT_ACCESSIBLE   0x02

/** The card has been removed.
 */
#define SIM_CARD_STATUS_REMOVED          0x03

/** The card has just been inserted.
 */
#define SIM_CARD_STATUS_INSERTED         0x04

/** The card has been recovered.
 */
#define SIM_CARD_STATUS_RECOVERED        0x05

/* End of SimCardStatus */


#ifndef __SIMAP_MAUI__
typedef void (* kal_timer_func_ptr)(void *);
#endif

/* MSG_ID_BT_SIMAP_CONNECT_IND */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    U8 cid;  /* connection id */
    U32 lap;
    U8 uap;
    U16 nap;
} bt_simap_connect_ind_struct;

/* MSG_ID_BT_SIMAP_DISCONNECT_IND */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    U8 cid;  /* connection id */

} bt_simap_disconnect_ind_struct;

/* MSG_ID_BT_SIMAP_DISCONNECT_CNF */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    BOOL result;
    U8 cid;  /* connection id */
} bt_simap_disconnect_cnf_struct;

/* MSG_ID_BT_SIMAP_ACTIVATE_CNF */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    BOOL result;
} bt_simap_activate_cnf_struct;

/* MSG_ID_BT_SIMAP_DEACTIVATE_CNF */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    BOOL result;
} bt_simap_deactivate_cnf_struct;

/* MSG_ID_BT_SIMAP_AUTH_REQ */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    U32 lap;
    U8 uap;
    U16 nap;
} bt_simap_auth_req_struct;

/* MSG_ID_BT_SIMAP_AUTH_RSP */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    BOOL result;
} bt_simap_auth_rsp_struct;

/* MSG_ID_BT_SIMAP_DISCONNECT_REQ */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    SimDisconnectType discType;
} bt_simap_disconnect_req_struct;

/* MSG_ID_BT_SIMAP_AUTH_REQ_TIMEOUT_RFCLOSE_IND */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    U32 lap;
    U8 uap;
    U16 nap;
} bt_simap_auth_req_timeout_rfclose_ind_struct;


#ifndef BTMTK_ON_MAUI
/* MSG_ID_BT_SIM_RESET_REQ */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    U8 transport_protocol_type;
} bt_sim_reset_req_struct;

/* MSG_ID_BT_SIM_APDU_REQ */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    U8 transport_protocol_type;
    U16 apdu_req_len;
    U8 apdu_req[APDU_REQ_MAX_LEN];
} bt_sim_apdu_req_struct;

/* MSG_ID_BT_SIM_CONNECT_CNF */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    U16 result;
    U8 current_transport_protocol_type;
    U8 supported_transport_protocol_type_capability;
    U16 atr_len;
    U8 atr[ATR_MAX_LEN];
} bt_sim_connect_cnf_struct;

/* MSG_ID_BT_SIM_RESET_CNF */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    U16 result;
    U8 current_transport_protocol_type;
    U16 atr_len;
    U8 atr[ATR_MAX_LEN];
} bt_sim_reset_cnf_struct;

/* MSG_ID_BT_SIM_APDU_CNF */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    U16 result;
    U16 apdu_rsp_len;
    U8 apdu_rsp[APDU_RSP_MAX_LEN];
} bt_sim_apdu_cnf_struct;

/* MSG_ID_BT_SIM_POWER_OFF_CNF */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    U16 result;
} bt_sim_power_off_cnf_struct;


/* MSG_ID_BT_SIM_DISCONNECT_CNF */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    U16 result;
} bt_sim_disconnect_cnf_struct;
#endif

/* MSG_ID_BT_SIMAP_INJECT_MESSAGE */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    U8 string[SIMAP_INJECT_MESSAGE_LENGTH_MAX];
} bt_simap_inject_req_struct;

/* MSG_ID_BT_SIMAP_CARD_STATUS_IND_SENT_IND */
typedef struct
{
    U8 ref_count;
    U16 msg_len;
    SimCardStatus status;
} bt_simap_card_status_ind_sent_ind_struct;

#endif	// __BLUETOOTH_SIMAP_STRUCT_H__

