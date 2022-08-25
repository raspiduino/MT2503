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
 *   as2l4c_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************
 *  FILENAME : as2l4c_struct.h
 *  SYNOPSIS : 
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */
#ifndef _AS2L4C_STRUCT_H
#define _AS2L4C_STRUCT_H

//#include "kal_non_specific_general_types.h"
#include "l3_inc_enums.h"
#include "nbr_public_struct.h"
#include "kal_general_types.h"
#include "ps_public_enum.h"
#if defined(__ENABLE_MYBCCH__)
#include "em_struct.h"
#include "mcd_l3_inc_struct.h"
#endif

#include "mcd_l3_inc_struct.h"
#if defined(__PLMN_LIST_WITH_CELL_INFO__)
#include "l3_inc_local.h"
#endif

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} l4cps_nbr_cell_info_start_req_struct, l4cps_nbr_cell_info_stop_req_struct;

typedef l4c_nbr_cell_info_reg_cnf_struct l4cps_nbr_cell_info_start_cnf_struct;
typedef l4c_nbr_cell_info_ind_struct l4cps_nbr_cell_info_ind_struct;

#ifdef __PLMN_LIST_PREF_SUPPORT__
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    plmn_list_preference_enum preference;
} l4cas_set_plmn_list_preference_req_struct;
#endif

#ifdef __DYNAMIC_HSPA_PREFERENCE__
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
	#if defined(__RMMI_UT__) || defined(__L1_STANDALONE__)
	    kal_uint8 hspa_preference;
	#else
	    hspa_preference_enum hspa_preference;
	#endif
} l4cas_set_hspa_preference_req_struct;
#endif /* __DYNAMIC_HSPA_PREFERENCE__ */

/* rx_level revision -------------------------------- */

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
	kal_uint8 current_band;
	kal_int32 rssi_in_qdbm; /* 1 means invalid */
	kal_uint8 ber;
} l4cps_gas_cell_power_level_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
	kal_uint8 ber; /* 99 means invalid */
	kal_int32 rssi_in_qdbm; /* valid range: -101*4 ~ -25*4 */
	kal_int32 RSCP_in_qdbm; /* valid range: -120*4 ~ -20*4 */
    kal_int32 EcN0_in_qdbm; /* valid range: - 25*4 ~   0*4 */
} l4cps_uas_cell_power_level_ind_struct;

/* -------------------------------- rx_level revision */
#if defined(__AT_RRC_TRACE_SUPPORT__)
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool  trace_on;
}l4cas_set_rrc_peer_trace_req_struct;

#define RRC_PEER_TRACE_MAX_MESSAGE_LEN 30
#define RRC_PEER_TRACE_MAX_MESSAGE_TYPE_LEN 50

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 message[RRC_PEER_TRACE_MAX_MESSAGE_LEN];
    kal_uint8 message_type[RRC_PEER_TRACE_MAX_MESSAGE_TYPE_LEN];
    
}l4cas_rrc_peer_trace_ind_struct;
#endif

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool is_abort_molr;
} l4c_lcsp_agps_cp_abort_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool is_etws_needed;      /* KAL_FALSE = ETWS off, KAL_TRUE = ETWS on */
    kal_bool is_etws_security_needed;  /* KAL_FALSE = ETWS security off, KAL_TRUE = ETWS security off */
    kal_bool is_etws_testing_on;  /* KAL_FALSE = don't send test purpose ETWS to MMI, KAL_TRUE= send test purpose ETWS to MMI*/
} l4cas_etws_setting_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 warning_type;   /*Byte 0 is MSB*, format follows 23.041 9.3.24*/
    kal_uint16 message_id;     /*Byte 0 is MSB*/
    kal_uint16 serial_nubmer;  /*Byte 0 is MSB*/
    kal_bool  is_security_information_valid;
    kal_uint8 etws_security_information[L4C_MAX_ETWS_SECURITY_INFO_LEN];  /* Only valid when is_security_information_valid = KAL_TRUE, format follows 23.041 9.3.25 */
} l4cas_etws_information_ind_struct;

#ifdef GAS_PKT_M2M_BAR_CELL

typedef struct 
{
    lai_struct lai;
    kal_uint16 cell_id;
    kal_uint32 bar_time;
} l4cas_bar_cell_control_info_struct;


typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    bar_cell_control_enum control;
    kal_uint8 num;
    l4cas_bar_cell_control_info_struct info[RR_NUM_OF_MAX_BAR_CELL];
} l4cas_bar_cell_control_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 num;
    l4cas_bar_cell_control_info_struct info[RR_NUM_OF_MAX_BAR_CELL];
} l4cas_bar_cell_control_cnf_struct;

#endif /* GAS_PKT_M2M_BAR_CELL */

#if defined(__GEMINI_MONITOR_PAGE_DURING_TRANSFER__)    
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool is_turn_on;
} rsvas_monitor_peer_pch_switch_req_struct;
#endif /* __GEMINI_MONITOR_PAGE_DURING_TRANSFER__ */

#if defined(__SINGLE_AP_DUAL_MODEM__)
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 sim_config;   /* bitmap */
} rsvas_sim_status_config_req_struct;
#endif /* __SINGLE_AP_DUAL_MODEM__ */

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    l4c_prefer_rat_enum prefer_rat;
} l4cas_set_prefer_rat_req_struct;

#if defined(__ENABLE_MYBCCH__)
typedef enum {
    MYBCCH_READ,                        // $mybcch?
    MYBCCH_TEST,                        // $mybcch=?
    MYBCCH_BCCH_ALL,                    // $mybcch=2
    MYBCCH_INVALID
} mybcch_mode_enum;

typedef struct {
    LOCAL_PARA_HDR
    mybcch_mode_enum       mode;        // identify among request using same msg    
} l4cps_get_mybcch_info_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    mybcch_mode_enum       mode;
    kal_bool               lock_status;                            // KAL_TRUE if locked
    kal_uint16             gas_serv_arfcn;                         // serving cell
    global_cell_id_struct  gas_serv_info;
    plmn_id_struct         gas_serv_plmn;
    kal_uint16             gas_nbr_arfcn[6];                       // neighbor cell
    global_cell_id_struct  gas_nbr_info[6];
    plmn_id_struct         gas_nbr_plmn[6];
    kal_uint16             lock_arfcn[MAX_NUM_CELL_LOCK_ARFCN];    // user input of arfcn to lock
} l4cps_get_mybcch_info_cnf_struct;
#endif

#if defined(__NORMAL_MODE_CAPID_CAL_SUPPORT__)
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool is_cal_success;
    kal_uint32 capid;
} l4cas_capid_cal_result_ind_struct;
#endif /* __NORMAL_MODE_CAPID_CAL_SUPPORT__ */


typedef struct{
    LOCAL_PARA_HDR
    kal_uint8     band;
    kal_uint8     power_class;
}l4cas_set_user_pwc_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    kal_bool      is_set_success;
}l4cas_set_user_pwc_cnf_struct;

typedef struct{
    LOCAL_PARA_HDR
    kal_uint8     gsm400_curr_power_class;
    kal_uint8     gsm900_curr_power_class;
    kal_uint8     gsm1800_curr_power_class;
    kal_uint8     gsm1900_curr_power_class;
    kal_uint8     gsm400_def_power_class;
    kal_uint8     gsm900_def_power_class;
    kal_uint8     gsm1800_def_power_class;
    kal_uint8     gsm1900_def_power_class;
}l4cas_get_user_pwc_cnf_struct;

typedef struct{
    LOCAL_PARA_HDR
    kal_uint8     gsm400_sup_power_class;
    kal_uint8     gsm900_sup_power_class;
    kal_uint8     gsm1800_sup_power_class;
    kal_uint8     gsm1900_sup_power_class;
}l4cas_get_supported_pwc_cnf_struct;

#ifdef __PLMN_LIST_WITH_CELL_INFO__
typedef struct{
    LOCAL_PARA_HDR
    as_plmn_list_struct    plmn_list;
}l4cas_plmn_list_info_ind_struct;
#endif /* __PLMN_LIST_WITH_CELL_INFO__ */
#endif /* _AS2L4C_STRUCT_H */
