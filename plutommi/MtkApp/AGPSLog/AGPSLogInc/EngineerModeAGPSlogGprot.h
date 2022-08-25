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
 *  EngineerModeAGPSlogGProt.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Global prototype definitions (Opened APIs)
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

#ifndef ENGINEER_MODE_AGPSLOG_GPROT_H
#define ENGINEER_MODE_AGPSLOG_GPROT_H

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMI_features.h"


#ifndef __EM_AGPSLOG_DEBUG_ON_VC__
#include "kal_general_types.h"
#else /* _EM_AGPSLOG_DEBUG_ON_VC */
#include "Adaptation.h"
#endif /* _EM_AGPSLOG_DEBUG_ON_VC */

/*****************************************************************************
 * Constant Definition
 *****************************************************************************/

/* Maximum number of concurrent sessions which SUPL will instantiate. */
#define EM_AGPSLOG_MAX_CONCURRENT_SESSION_NUM 3

/*****************************************************************************
 * Typedef
 *****************************************************************************/

typedef enum
{
    EM_AGPSLOG_PROCEDURE_DURATION,

    /* MMI */
    EM_AGPSLOG_MMI_DATE_TIME,
    EM_AGPSLOG_MMI_BATTERY_INFO,

    /* SUPL */
    EM_AGPSLOG_SUPL_VERSION,
    EM_AGPSLOG_SUPL_SESSION_ID,
    EM_AGPSLOG_SUPL_POSITION_METHOD,
    EM_AGPSLOG_SUPL_SESSION_TYPE,
    EM_AGPSLOG_SUPL_MESSAGE_TYPE,
    EM_AGPSLOG_SUPL_STATUS_CODE,
    EM_AGPSLOG_SUPL_SLP_ADDRESS,
    EM_AGPSLOG_SUPL_SSL,

    /* RRLP */
    EM_AGPSLOG_RRLP_MESSAGE_TYPE,
    EM_AGPSLOG_RRLP_ASSISTANCE_DATA_CONTENT,

    /* GPS */
    EM_AGPSLOG_GPS_ACCURACY,
    EM_AGPSLOG_GPS_SATELLITE_INFO,
    EM_AGPSLOG_GPS_POSITION_RESULT,
    EM_AGPSLOG_GPS_CONNECTIVITY_STATUS,
    EM_AGPSLOG_GPS_START_TYPE,
    
    /* --- Add new log type before this wall --- */
    EM_AGPSLOG_TYPE_TOTAL,

    /* Definied for for parser */
    EM_AGPSLOG_TYPE_COMMENT,
    EM_AGPSLOG_TYPE_UNKNOWN
} em_agpslog_type_enum;

/* -------- For procedure time log -------- */

typedef enum
{
    EM_AGPSLOG_PROC_BEARER_ACT,
    EM_AGPSLOG_PROC_IP_CONN,
    EM_AGPSLOG_PROC_ADT, /* Assitance Data Transmission */
    EM_AGPSLOG_PROC_POS_CAL,
    /* -------------------------------- */
    EM_AGPSLOG_PROC_TOTAL
} em_agpslog_procedure_enum;


typedef enum
{
    EM_AGPSLOG_DIRECTION_RX,
    EM_AGPSLOG_DIRECTION_TX,
    /* -------------------------------- */
    EM_AGPSLOG_DIRECTION_TOTAL
} em_agpslog_direction_enum;


/* -------- For SUPL --------- */

typedef enum
{
    EM_AGPSLOG_SUPL_POS_MTH_MA,
    EM_AGPSLOG_SUPL_POS_MTH_MB,
    EM_AGPSLOG_SUPL_POS_MTH_AUTONOMOUS,
    /* ----------------------------- */
    EM_AGPSLOG_SUPL_POS_MTH_TOTAL
} em_agpslog_supl_position_method_enum;

typedef enum
{
    EM_AGPSLOG_SUPL_SESSION_TYPE_NI,
    EM_AGPSLOG_SUPL_SESSION_TYPE_SI,
    /* ---------------------------------- */
    EM_AGPSLOG_SUPL_SESSION_TYPE_TOTAL
} em_agpslog_supl_session_type_enum;

typedef enum
{
    EM_AGPSLOG_SUPL_MESSAGE_TYPE_INIT,
    EM_AGPSLOG_SUPL_MESSAGE_TYPE_START,
    EM_AGPSLOG_SUPL_MESSAGE_TYPE_RESPONSE,
    EM_AGPSLOG_SUPL_MESSAGE_TYPE_POS_INIT,
    EM_AGPSLOG_SUPL_MESSAGE_TYPE_POS,
    EM_AGPSLOG_SUPL_MESSAGE_TYPE_END,
    /* ---------------------------------- */
    EM_AGPSLOG_SUPL_MESSAGE_TYPE_TOTAL
} em_agpslog_supl_message_type_enum;

typedef enum
{
    EM_AGPSLOG_SUPL_STATUS_UNSPECIFIED,
    EM_AGPSLOG_SUPL_STATUS_SYSTEM_FAILURE,
    EM_AGPSLOG_SUPL_STATUS_PROTOCOL_ERROR,
    EM_AGPSLOG_SUPL_STATUS_DATA_MISSING,
    EM_AGPSLOG_SUPL_STATUS_UNEXPECTED_DATA_VALUE,
    EM_AGPSLOG_SUPL_STATUS_POS_METHOD_FAILURE,
    EM_AGPSLOG_SUPL_STATUS_POS_METHOD_MISMATCH,
    EM_AGPSLOG_SUPL_STATUS_POS_PROTOCOL_MISMATCH,
    EM_AGPSLOG_SUPL_STATUS_TARGET_SET_NOT_REACHABLE,
    EM_AGPSLOG_SUPL_STATUS_VERSION_NOT_SUPPORTED,
    EM_AGPSLOG_SUPL_STATUS_RESOURCE_SHORTAGE,
    EM_AGPSLOG_SUPL_STATUS_INAVLID_SESSION_ID,
    EM_AGPSLOG_SUPL_STATUS_UNEXPECTED_MESSAGE,
    EM_AGPSLOG_SUPL_STATUS_NONPROXY_MODE_NOT_SUPPORTED,
    EM_AGPSLOG_SUPL_STATUS_PROXY_MODE_NOT_SUPPORTED,
    EM_AGPSLOG_SUPL_STATUS_POSITIONING_NOT_PERMITTED,
    EM_AGPSLOG_SUPL_STATUS_AUTH_NET_FAILURE,
    EM_AGPSLOG_SUPL_STATUS_AUTH_SUPL_INIT_FAILURE,
    EM_AGPSLOG_SUPL_STATUS_CONSENT_DENIED_BY_USER,
    EM_AGPSLOG_SUPL_STATUS_CONSENT_GRANTED_BY_USER,
    /* ---------------------------------- */
    EM_AGPSLOG_SUPL_STATUS_TOTAL
} em_agpslog_supl_status_enum;

/* -------- For RRLP --------- */

typedef enum
{
    EM_AGPSLOG_RRLP_MESSAGE_TYPE_ASSISTANCE_DATA,
    EM_AGPSLOG_RRLP_MESSAGE_TYPE_ASSISTANCE_DATA_ACK,
    EM_AGPSLOG_RRLP_MESSAGE_TYPE_POSITION_REQUEST,
    EM_AGPSLOG_RRLP_MESSAGE_TYPE_POSITION_RESPONSE,
    EM_AGPSLOG_RRLP_MESSAGE_TYPE_POSITION_RESPONSE_WITH_LOC_ERR,
    EM_AGPSLOG_RRLP_MESSAGE_TYPE_MEASUREMENT_REQUEST,
    EM_AGPSLOG_RRLP_MESSAGE_TYPE_MEASUREMENT_RESPONSE,
    EM_AGPSLOG_RRLP_MESSAGE_TYPE_PROTOCOL_ERR,
    /* ---------------------------------- */
    EM_AGPSLOG_RRLP_MESSAGE_TYPE_TOTAL
} em_agpslog_rrlp_message_type_enum;

/* -------- For GPS --------- */

typedef enum
{
    EM_AGPSLOG_GPS_CONN_STATUS_OFF,
    EM_AGPSLOG_GPS_CONN_STATUS_ON,
    /* -------------------------------- */
    EM_AGPSLOG_GPS_CONN_STATUS_TOTAL
} em_agpslog_gps_conn_status_enum;

typedef enum
{
    EM_AGPSLOG_GPS_START_TYPE_COLD,
    EM_AGPSLOG_GPS_START_TYPE_WARM,
    EM_AGPSLOG_GPS_START_TYPE_HOT,
    /* -------------------------------- */
    EM_AGPSLOG_GPS_START_TYPE_TOTAL
} em_agpslog_gps_start_type_enum;


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * Global Function
 *****************************************************************************/

#ifdef __AGPS_LOG_SUPPORT__

/* Do NOT call following functions directly! */
extern void em_agpslog_init(void);
extern void em_agpslog_void(const em_agpslog_type_enum log_type);
extern void em_agpslog_u8(const em_agpslog_type_enum log_type, const kal_uint8 val);
extern void em_agpslog_u8_u8(const em_agpslog_type_enum log_type, const kal_uint8 v1, const kal_uint8 v2);
extern void em_agpslog_u16(const em_agpslog_type_enum log_type, const kal_uint16 val);
extern void em_agpslog_u16_u16(const em_agpslog_type_enum log_type, const kal_uint16 v1, const kal_uint16 v2);
extern void em_agpslog_float(const em_agpslog_type_enum log_type, const float val);

/* For UI use */
extern void mmi_em_agpslog_init(void);

/***************************** Service part ****************************/

extern kal_bool em_agpslog_start_session(const kal_uint32 session_id);
extern kal_bool em_agpslog_set_active_session(const kal_uint32 session_id);
extern void em_agpslog_end_session(const kal_uint32 session_id);

#define em_agpslog_procedure_duration(proc_type, ms) \
    em_agpslog_u16_u16(EM_AGPSLOG_PROCEDURE_DURATION, (kal_uint16)(proc_type), (ms))

/* For MMI */
extern void em_agpslog_mmi_date_time(void);
#define em_agpslog_mmi_battery_info(mAh) \
    em_agpslog_u16(EM_AGPSLOG_MMI_BATTERY_INFO, (mAh))

/* For SUPL */
extern void em_agpslog_supl_version(
    const kal_uint8 major,
    const kal_uint8 minor,
    const kal_uint8 serv_ind);
extern void em_agpslog_supl_session_id(const kal_char *session_id);
#define em_agpslog_supl_position_method(mth) \
    em_agpslog_u8(EM_AGPSLOG_SUPL_POSITION_METHOD, (kal_uint8)(mth))
#define em_agpslog_supl_session_type(s_type) \
    em_agpslog_u8(EM_AGPSLOG_SUPL_SESSION_TYPE, (kal_uint8)(s_type))

/* dir: em_agpslog_direction_enum, m_type: em_agpslog_supl_message_type_enum */
#define em_agpslog_supl_message_type(dir, m_type) \
    em_agpslog_u8_u8(EM_AGPSLOG_SUPL_MESSAGE_TYPE, (kal_uint8)(dir), (kal_uint8)(m_type))

/* status: em_agpslog_supl_status_enum */
#define em_agpslog_supl_status_code(status) \
    em_agpslog_u8(EM_AGPSLOG_SUPL_STATUS_CODE, (kal_uint8)(status))

/* ip_addr: network IP address.
   addr_len: the length of ip_addr
   For IPv4, ip_addr has 4 elements exactly and the addr_len should be 4 */
extern void em_agpslog_supl_SLP(
    const kal_uint8 *ip_addr,
    const kal_uint8 addr_len,
    const kal_uint16 port);

/* For RRLP */

/* m_type: em_agpslog_rrlp_message_type_enum */
#define em_agpslog_rrlp_message_type(m_type) \
    em_agpslog_u8(EM_AGPSLOG_RRLP_MESSAGE_TYPE, (kal_uint8)(m_type))

// TODO: em_agpslog_rrlp_ADC(ADC)

/* For GPS */
#define em_agpslog_gps_accuracy(accu) \
    em_agpslog_float(EM_AGPSLOG_GPS_ACCURACY, (accu))

#define em_agpslog_gps_satellite_info(SV_id, strength) \
    em_agpslog_u16_u16(EM_AGPSLOG_GPS_SATELLITE_INFO, \
        (kal_uint16)(SV_id), (strength))

extern void em_agpslog_gps_position_result(
    const float longitude,
    const float latitude,
    const float altitude,
    const float velocity,
    const float direction);
#define em_agpslog_gps_connectivity_status(c_status) \
    em_agpslog_u8(EM_AGPSLOG_GPS_CONNECTIVITY_STATUS, (kal_uint8)(c_status))
#define em_agpslog_gps_start_type(s_type) \
    em_agpslog_u8(EM_AGPSLOG_GPS_START_TYPE, (kal_uint8)(s_type))


#else /* __AGPS_LOG_SUPPORT__ */

#define em_agpslog_init()
#define mmi_em_agpslog_init()


#define em_agpslog_start_session(session_id)
#define em_agpslog_set_active_session(session_id)
#define em_agpslog_end_session(session_id)

#define em_agpslog_procedure_duration(proc_type, ms)

/* For MMI */
#define em_agpslog_mmi_date_time()
#define em_agpslog_mmi_battery_info(mAh)

/* For SUPL */
#define em_agpslog_supl_version(major, minor, serv_ind)
#define em_agpslog_supl_session_id(session_id)
#define em_agpslog_supl_position_method(mth)
#define em_agpslog_supl_session_type(s_type)
#define em_agpslog_supl_message_type(dir, m_type)
#define em_agpslog_supl_status_code(status)
#define em_agpslog_supl_SLP(ip_addr, addr_len, port)

/* For RRLP */
#define em_agpslog_rrlp_message_type(m_type)
// TODO: em_agpslog_rrlp_ADC(ADC)

/* For GPS */
#define em_agpslog_gps_accuracy(accu)
#define em_agpslog_gps_satellite_info(SV_id, strength)
#define em_agpslog_gps_position_result(longitude, latitude, altitude, velocity, direction)
#define em_agpslog_gps_connectivity_status(c_status)
#define em_agpslog_gps_start_type(s_type)

#endif /* __AGPS_LOG_SUPPORT__ */

#endif /* ENGINEER_MODE_AGPSLOG_GPROT_H */
