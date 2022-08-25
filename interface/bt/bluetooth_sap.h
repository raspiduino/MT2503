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
*   bluetooth_sap.h
*
* Project:
* --------
*   Maui_Software
*
* Description:
* ------------
*   This file is defines SAP for BT.
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
*
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
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
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
 * removed!
*
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
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
 * removed!
 * removed!
*
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#ifdef BTMTK_ON_MAUI
MSG_ID_BT_NOTIFY_EVM_IND = BT_MSG_CODE_BEGIN,
#else   /*  BTMTK_ON_MAUI */
/* After add/delete message group, pls modify btmtk_adp_check_msg_id_range() accordingly */
MSG_ID_BT_NOTIFY_EVM_IND = MSG_ID_BT_START,
MSG_ID_TIMER_EXPIRY,
#endif  /*  BTMTK_ON_MAUI */
MSG_ID_BT_HOST_WAKE_UP_IND,
#ifdef BTMTK_ON_MAUI
MSG_ID_BT_L2CAP_TEST_CMD_REQ,
MSG_ID_BT_SDP_TEST_ACTIVATE_REQ,
MSG_ID_BT_DATA_TO_READ_IND,
MSG_ID_BT_READY_IND,
MSG_ID_BT_L4C_AT_GENERAL_CNF,
MSG_ID_BT_L4C_TEST_CMD_CNF,
MSG_ID_BT_PCM_LB_REQ,
MSG_ID_BT_PCM_LB_CNF,
MSG_ID_BT_TEST_MODE_REQ,
MSG_ID_BT_SET_UART_RX_SPEED_LOW_REQ,
MSG_ID_BT_SET_UART_RX_SPEED_HIGH_REQ,
MSG_ID_BT_GET_BT_VERSION_REQ,
MSG_ID_BT_GET_BT_VERSION_CNF,
MSG_ID_BT_ACTIVE_UART_CHANGE_REQ,
MSG_ID_BT_WIFI_SET_CHNL_REQ,
MSG_ID_BT_ENGINEER_MODE_LOG_MASK_REQ,
MSG_ID_BT_ENGINEER_MODE_LOG_MASK_CNF,
MSG_ID_BT_ENGINEER_MODE_TXRX_TEST_REQ,
MSG_ID_BT_ENGINEER_MODE_TXRX_TEST_CNF,
MSG_ID_BT_ENGINEER_MODE_POWER_TEST_REQ,
MSG_ID_BT_ENGINEER_MODE_POWER_TEST_CNF,
MSG_ID_BT_ENGINEER_MODE_DEVICE_TEST_REQ,

MSG_ID_BT_WAKEUP_BT_CONTROLLER,

MSG_ID_BT_ENGINEER_MODE_CNF,
MSG_ID_BT_ENGINEER_MODE_NSR_TEST_ENTER_REQ,
MSG_ID_BT_ENGINEER_MODE_NSR_TEST_ENTER_CNF,   
MSG_ID_BT_ENGINEER_MODE_NSR_TEST_EXIT_REQ,   
MSG_ID_BT_ATA_POWER_ON_REQ,
MSG_ID_BT_ATA_POWER_ON_CNF,   
MSG_ID_BT_ATA_POWER_OFF_REQ,
MSG_ID_BT_ATA_POWER_OFF_CNF,   
MSG_ID_BT_ENGINEER_MODE_NSR_TEST_EXIT_CNF,
MSG_ID_BT_ENGINEER_MODE_TXRX_TEST_EXIT_REQ,
MSG_ID_BT_ENGINEER_MODE_TXRX_TEST_EXIT_CNF,

MSG_ID_BT_END = MSG_ID_BT_ENGINEER_MODE_TXRX_TEST_EXIT_CNF,
#else  /*  BTMTK_ON_MAUI */
/****************************************************************************
 *  Request Messages: WMT -> BT
 ****************************************************************************/
MSG_ID_WMT_BT_QUERY_STATE_REQ,
MSG_ID_WMT_BT_QUERY_STATE_CNF,
MSG_ID_WMT_BT_SET_BWCS_REQ,
MSG_ID_WMT_BT_QUERY_RSSI_REQ,
MSG_ID_WMT_BT_QUERY_RSSI_IND,
MSG_ID_WMT_BT_SET_RX_RANGE_REQ,
MSG_ID_WMT_BT_SET_RX_RANGE_CNF,
MSG_ID_WMT_BT_SET_DEFAULT_TX_POWER_REQ,
MSG_ID_WMT_BT_SET_DEFAULT_TX_POWER_CNF,
MSG_ID_WMT_BT_UPDATE_CONN_TX_POWER_REQ,
MSG_ID_WMT_BT_UPDATE_CONN_TX_POWER_CNF,
MSG_ID_WMT_BT_STATUS_IND,

/* + Debug message */
MSG_ID_BT_DBG_QUERY_CONTEXT_REQ,
MSG_ID_BT_DBG_QUERY_CONTEXT_CNF,
MSG_ID_BT_DBG_HCI_CONTEXT_IND,
MSG_ID_BT_DBG_ME_CONTEXT_IND,
MSG_ID_BT_DBG_RMG_CONTEXT_IND,
MSG_ID_BT_DBG_L2CAP_CONTEXT_IND,
MSG_ID_BT_DBG_RXBUF_CONTEXT_IND,
MSG_ID_BT_DBG_SDPS_CONTEXT_IND,
MSG_ID_BT_DBG_SDPC_CONTEXT_IND,
MSG_ID_BT_DBG_RFC_CONTEXT_IND,
MSG_ID_BT_DBG_A2MP_CONTEXT_IND,
MSG_ID_BT_DBG_ATT_CONTEXT_IND,
MSG_ID_BT_DBG_GATT_CONTEXT_IND,
MSG_ID_BT_DBG_WDDEV_CONTEXT_IND,
MSG_ID_BT_DBG_WDTRANS_CONTEXT_IND,
MSG_ID_BT_DBG_MANUAL_DUMP_REQ,
/* - Debug message */
MSG_ID_BT_ENGINEER_MODE_LOG_MASK_REQ,
MSG_ID_BT_ENGINEER_MODE_LOG_MASK_CNF,
MSG_ID_BT_ENGINEER_MODE_LOG_TO_FILE_REQ,
MSG_ID_BT_ENGINEER_MODE_LOG_TO_FILE_CNF,
#ifdef __MTK_BT_DUAL_PCM_SWITCH_SUPPORT__
MSG_ID_BT_SET_SCO_ACCEPT_REQ,
MSG_ID_BT_SET_SCO_ACCEPT_CNF,
MSG_ID_BT_SET_DUAL_PCM_SETTING_REQ,
MSG_ID_BT_SET_DUAL_PCM_SETTING_CNF,
MSG_ID_BT_SET_DUAL_PCM_SWITCH_REQ,
MSG_ID_BT_SET_DUAL_PCM_SWITCH_CNF,
#endif
MSG_ID_BT_TEST_MODE_REQ,
MSG_ID_BT_TEST_MODE_CNF,
MSG_ID_BT_BTTM_SWITCH_PORT_REQ,
MSG_ID_BT_BTTM_SWITCH_PORT_CNF,
MSG_ID_BT_END = MSG_ID_BT_BTTM_SWITCH_PORT_CNF,
#endif

MSG_ID_BT_SSP_DEBUG_MODE_REQ,
MSG_ID_BT_SSP_DEBUG_MODE_CNF,
MSG_ID_BT_TEST_CMD_REQ,
MSG_ID_BT_TEST_CMD_CNF,

/* GAP */
#include "bluetooth_gap_message.h"

/* SDP */
#include "bluetooth_sdp_message.h"


/* A2DP */
#ifdef __BT_A2DP_PROFILE__
#include "bluetooth_a2dp_message.h"
#endif

/* AVRCP */
#ifdef __BT_AVRCP_PROFILE__
#include "bluetooth_avrcp_message.h"
#endif

/* BIP */
#ifdef __BT_BIPI_PROFILE__
#include "bluetooth_bipi_message.h"
#endif
#ifdef __BT_BIPR_PROFILE__
#include "bluetooth_bipr_message.h"
#endif
/* BPP */
#ifdef __BT_BPP_PROFILE__
#include "bluetooth_bpp_message.h"
#endif
/* DUN */
/* FAX */
/* FTP */
#ifdef __BT_FTC_PROFILE__
#include "bluetooth_ftpc_message.h"
#endif
#ifdef __BT_FTS_PROFILE__
#include "bluetooth_ftps_message.h"
#endif
/* GOEP */
#include "bluetooth_goepc_message.h"
#include "bluetooth_goeps_message.h"
/* HFG */
/* HSG */
#ifdef __BT_HFG_PROFILE__
#include "bluetooth_hfg_message.h"
#endif

/* HandsFree */
#ifdef __BT_HF_PROFILE__
#include "bluetooth_hf_message.h"
#endif
/* HID */
#ifdef __BT_HIDD_PROFILE__
#include "bluetooth_hid_message.h"
#endif

/* OPP */
#ifdef __BT_OPP_PROFILE__
#include "bluetooth_oppc_message.h"
#include "bluetooth_opps_message.h"
#endif

/* PBAPC */
#ifdef __BT_PBAP_CLIENT__
#include "bluetooth_pbapc_message.h"
#endif

/* PBAP */
#ifdef __BT_PBAP_PROFILE__
#include "bluetooth_pbap_message.h"
#endif

/* SIMAP */
#ifdef __BT_SIM_PROFILE__
#include "bluetooth_simap_message.h"
#endif

/* SPP */
#ifdef __BT_SPP_PROFILE__
#include "bluetooth_spp_message.h"
#endif

/* JSR82 */
#ifdef __BT_JSR82__
#include "bluetooth_jsr82_message.h"
#endif

/* CHN */
#ifdef __BT_CHN_PROFILE__
#include "bluetooth_chn_message.h"
#endif //TODO

/* MAP */
#ifdef __BT_MAPC_PROFILE__   
#include "bluetooth_map_message.h"
#endif

#ifdef __BT_PRXM_PROFILE__
#include "bluetooth_prx_message.h"
#endif

/* PAN */
#ifdef __BT_PAN_PROFILE__
#include "bluetooth_pan_message.h"
#endif

/* TIME */
#ifdef __BT_TIMEC_PROFILE__
#include "bluetooth_time_message.h"
#endif

/* HDP */
#ifdef __BT_HDP_PROFILE__
#include "bluetooth_hdp_message.h"
#endif

/* HTP */
#ifdef __BT_HTP_PROFILE__
#include "bluetooth_htp_message.h"
#endif

/* FMP */
#ifdef __BT_FMP_PROFILE__
#include "bluetooth_fmp_message.h"
#endif

/* GATTC */
#ifdef __BT_GATTC_PROFILE__
#include "bluetooth_gattc_message.h"
#endif

/* GATTS */
#ifdef __BT_GATTS_PROFILE__
#include "bluetooth_gatts_message.h"
#endif

MSG_ID_BT_CUSTOM_MSG_ID_BEGIN,


/* Below is the message interface for other modules */
/* PAL */
#ifdef __BT_HS_30__
#include "pal_sap.h"
#endif

#if 0
/* under construction !*/
/* under construction !*/
#endif

#ifndef BTMTK_ON_MAUI
MSG_ID_END = 0xFFFFFFFF
#else   /* BTMTK_ON_MAUI */
// radiomod.c -> btstack, radiomod.c -> fmr
MSG_ID_BT_FORCE_RESET_START,
MSG_ID_BT_FORCE_RESET_END,
MSG_TAG_BT_SAP_END_MSG,
#endif  /* BTMTK_ON_MAUI */
