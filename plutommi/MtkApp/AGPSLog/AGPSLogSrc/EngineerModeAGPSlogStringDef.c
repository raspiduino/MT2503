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
 *  EngineerModeAGPSlogStringDef.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  String definitions for AGPS log formatter
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMI_features.h"
#include "EngineerModeAGPSlogProt.h"

#ifdef __AGPS_LOG_SUPPORT__

#include "kal_general_types.h"
#include "EngineerModeAGPSlogGprot.h"

/*****************************************************************************
 * Typedef
 *****************************************************************************/

typedef struct
{
    kal_uint32 id;
    const kal_char* string;
} em_agpslog_string_mapping_entry;


/*****************************************************************************
 * Local Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  em_agpslog_search_string_table
 * DESCRIPTION
 *  Find & return the string field of the id-matched entry
 * PARAMETERS
 *  id              [IN]    ID
 *  table           [IN]    Definition table
 *  n_entries       [IN]    Number of entries in the table
 * RETURNS
 *  String for the ID; or emtpy string if not found
 *****************************************************************************/
static const kal_char* em_agpslog_search_string_table(
    const kal_uint32 id,
    const em_agpslog_string_mapping_entry* table,
    const kal_uint32 n_entries)
{
    kal_uint32 i;

    for (i = 0; i < n_entries; i++)
    {
        if (table[i].id == id)
            return ((const kal_char*)table[i].string);
    }

    return (const kal_char*)("");
}


/*****************************************************************************
 * Global Function
 *****************************************************************************/

/* -------------------------- String definitions --------------------------- */

/*****************************************************************************
 * FUNCTION
 *  em_agpslog_get_proc_name_string
 * DESCRIPTION
 *  Get procedure name string from em_agpslog_procedure_enum
 * PARAMETERS
 *  proc        [IN]    em_agpslog_procedure_enum
 * RETURNS
 *  String
 *****************************************************************************/
const kal_char* em_agpslog_get_proc_name_string(em_agpslog_procedure_enum proc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const em_agpslog_string_mapping_entry table[] =
    {
        { EM_AGPSLOG_PROC_BEARER_ACT,   "Bearer activation"     },
        { EM_AGPSLOG_PROC_IP_CONN,      "IP connection"         },
        { EM_AGPSLOG_PROC_ADT,          "Assistance data transmission" },
        { EM_AGPSLOG_PROC_POS_CAL,      "Position calculation"  }
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return em_agpslog_search_string_table(proc, table, EM_AGPSLOG_PROC_TOTAL);
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_get_direction_string
 * DESCRIPTION
 *  Get direction string from em_agpslog_direction_enum
 * PARAMETERS
 *  dir        [IN]    em_agpslog_direction_enum
 * RETURNS
 *  String
 *****************************************************************************/
const kal_char* em_agpslog_get_direction_string(em_agpslog_direction_enum dir)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const em_agpslog_string_mapping_entry table[] =
    {
        { EM_AGPSLOG_DIRECTION_RX,   "Rx" },
        { EM_AGPSLOG_DIRECTION_TX,   "Tx" }
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return em_agpslog_search_string_table(dir, table, EM_AGPSLOG_DIRECTION_TOTAL);
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_get_supl_pos_mth_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos_mth        [IN]    em_agpslog_supl_position_method_enum
 * RETURNS
 *  String
 *****************************************************************************/
const kal_char* em_agpslog_get_supl_pos_mth_string(em_agpslog_supl_position_method_enum pos_mth)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const em_agpslog_string_mapping_entry table[] =
    {
        { EM_AGPSLOG_SUPL_POS_MTH_MA,           "MA"         },
        { EM_AGPSLOG_SUPL_POS_MTH_MB,           "MB"         },
        { EM_AGPSLOG_SUPL_POS_MTH_AUTONOMOUS,   "Autonomous" }
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return em_agpslog_search_string_table(pos_mth, table, EM_AGPSLOG_SUPL_POS_MTH_TOTAL);
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_get_supl_session_type_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s_type        [IN]    em_agpslog_supl_session_type_enum
 * RETURNS
 *  String
 *****************************************************************************/
const kal_char* em_agpslog_get_supl_session_type_string(em_agpslog_supl_session_type_enum s_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const em_agpslog_string_mapping_entry table[] =
    {
        { EM_AGPSLOG_SUPL_SESSION_TYPE_NI,  "NI" },
        { EM_AGPSLOG_SUPL_SESSION_TYPE_SI,  "SI" }
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return em_agpslog_search_string_table(s_type, table, EM_AGPSLOG_SUPL_SESSION_TYPE_TOTAL);
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_get_supl_message_type_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg        [IN]    em_agpslog_supl_message_type_enum
 * RETURNS
 *  String
 *****************************************************************************/
const kal_char* em_agpslog_get_supl_message_type_string(em_agpslog_supl_message_type_enum msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const em_agpslog_string_mapping_entry table[] =
    {
        { EM_AGPSLOG_SUPL_MESSAGE_TYPE_INIT,        "Init" },
        { EM_AGPSLOG_SUPL_MESSAGE_TYPE_START,       "Start" },
        { EM_AGPSLOG_SUPL_MESSAGE_TYPE_RESPONSE,    "Response" },
        { EM_AGPSLOG_SUPL_MESSAGE_TYPE_POS_INIT,    "Pos init" },
        { EM_AGPSLOG_SUPL_MESSAGE_TYPE_POS,         "Pos" },
        { EM_AGPSLOG_SUPL_MESSAGE_TYPE_END,         "End" }
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return em_agpslog_search_string_table(msg, table, EM_AGPSLOG_SUPL_MESSAGE_TYPE_TOTAL);
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_get_supl_status_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status        [IN]    em_agpslog_supl_status_enum
 * RETURNS
 *  String
 *****************************************************************************/
const kal_char* em_agpslog_get_supl_status_string(em_agpslog_supl_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const em_agpslog_string_mapping_entry table[] =
    {
        { EM_AGPSLOG_SUPL_STATUS_UNSPECIFIED,           "Unspecified" },
        { EM_AGPSLOG_SUPL_STATUS_SYSTEM_FAILURE,        "SystemFailure" },
        { EM_AGPSLOG_SUPL_STATUS_PROTOCOL_ERROR,        "ProtocolError" },
        { EM_AGPSLOG_SUPL_STATUS_DATA_MISSING,          "DataMissing" },
        { EM_AGPSLOG_SUPL_STATUS_UNEXPECTED_DATA_VALUE, "UnexpectedDataValue" },
        { EM_AGPSLOG_SUPL_STATUS_POS_METHOD_FAILURE,    "PosMethodFailure" },
        { EM_AGPSLOG_SUPL_STATUS_POS_METHOD_MISMATCH,   "PosMethodMismatch" },
        { EM_AGPSLOG_SUPL_STATUS_POS_PROTOCOL_MISMATCH, "PosProtocolMismatch" },
        { EM_AGPSLOG_SUPL_STATUS_TARGET_SET_NOT_REACHABLE,      "TargetSETNotReachable" },
        { EM_AGPSLOG_SUPL_STATUS_VERSION_NOT_SUPPORTED, "VersionNotSupported" },
        { EM_AGPSLOG_SUPL_STATUS_RESOURCE_SHORTAGE,     "ResourceShortage" },
        { EM_AGPSLOG_SUPL_STATUS_INAVLID_SESSION_ID,    "InavlidSessionId" },
        { EM_AGPSLOG_SUPL_STATUS_UNEXPECTED_MESSAGE,    "UnexpectedMessage" },
        { EM_AGPSLOG_SUPL_STATUS_NONPROXY_MODE_NOT_SUPPORTED,   "NonProxyModeNotSupported" },
        { EM_AGPSLOG_SUPL_STATUS_PROXY_MODE_NOT_SUPPORTED,      "ProxyModeNotSupported" },
        { EM_AGPSLOG_SUPL_STATUS_POSITIONING_NOT_PERMITTED,     "PositioningNotPermitted" },
        { EM_AGPSLOG_SUPL_STATUS_AUTH_NET_FAILURE,              "AuthNetFailure" },
        { EM_AGPSLOG_SUPL_STATUS_AUTH_SUPL_INIT_FAILURE,        "AuthSuplInitFailure" },
        { EM_AGPSLOG_SUPL_STATUS_CONSENT_DENIED_BY_USER,        "ConsentDeniedByUser" },
        { EM_AGPSLOG_SUPL_STATUS_CONSENT_GRANTED_BY_USER,       "ConsentGrantedByUser" }
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return em_agpslog_search_string_table(status, table, EM_AGPSLOG_SUPL_STATUS_TOTAL);
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_get_rrlp_message_type_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg        [IN]    em_agpslog_rrlp_message_type_enum
 * RETURNS
 *  String
 *****************************************************************************/
const kal_char* em_agpslog_get_rrlp_message_type_string(em_agpslog_rrlp_message_type_enum msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const em_agpslog_string_mapping_entry table[] =
    {
        { EM_AGPSLOG_RRLP_MESSAGE_TYPE_ASSISTANCE_DATA,     "Assist Data" },
        { EM_AGPSLOG_RRLP_MESSAGE_TYPE_ASSISTANCE_DATA_ACK, "Assist Data Ack" },
        { EM_AGPSLOG_RRLP_MESSAGE_TYPE_POSITION_REQUEST,    "Pos Req" },
        { EM_AGPSLOG_RRLP_MESSAGE_TYPE_POSITION_RESPONSE,   "Pos Rsp" },
        { EM_AGPSLOG_RRLP_MESSAGE_TYPE_POSITION_RESPONSE_WITH_LOC_ERR, "Pos Rsp with Loc Err" },
        { EM_AGPSLOG_RRLP_MESSAGE_TYPE_MEASUREMENT_REQUEST, "Meas Req" },
        { EM_AGPSLOG_RRLP_MESSAGE_TYPE_MEASUREMENT_RESPONSE, "Meas Rsp" },
        { EM_AGPSLOG_RRLP_MESSAGE_TYPE_PROTOCOL_ERR, "Protocol Err" }
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return em_agpslog_search_string_table(msg, table, EM_AGPSLOG_RRLP_MESSAGE_TYPE_TOTAL);
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_get_gps_conn_status_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status        [IN]    em_agpslog_gps_conn_status_enum
 * RETURNS
 *  String
 *****************************************************************************/
const kal_char* em_agpslog_get_gps_conn_status_string(em_agpslog_gps_conn_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const em_agpslog_string_mapping_entry table[] =
    {
        { EM_AGPSLOG_GPS_CONN_STATUS_OFF,   "Off" },
        { EM_AGPSLOG_GPS_CONN_STATUS_ON,    "On" }
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return em_agpslog_search_string_table(status, table, EM_AGPSLOG_GPS_CONN_STATUS_TOTAL);
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_get_gps_start_type_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s_type        [IN]    em_agpslog_gps_start_type_enum
 * RETURNS
 *  String
 *****************************************************************************/
const kal_char* em_agpslog_get_gps_start_type_string(em_agpslog_gps_start_type_enum s_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const em_agpslog_string_mapping_entry table[] =
    {
        { EM_AGPSLOG_GPS_START_TYPE_COLD,   "Cold" },
        { EM_AGPSLOG_GPS_START_TYPE_WARM,   "Warm" },
        { EM_AGPSLOG_GPS_START_TYPE_HOT,    "Hot" }
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return em_agpslog_search_string_table(s_type, table, EM_AGPSLOG_GPS_START_TYPE_TOTAL);
}

#endif /* __AGPS_LOG_SUPPORT__ */
