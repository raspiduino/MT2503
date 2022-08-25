/***********************************************************************
*   This software/firmware and related documentation ("MediaTek Software") 
*   are protected under relevant copyright laws. The information contained 
*   herein is confidential and proprietary to MediaTek Inc. and/or its licensors.
*
*   Without the prior written permission of MediaTek Inc. and/or its licensors, 
*   any reproduction, modification, use or disclosure of MediaTek Software, and 
*   information contained herein, in whole or in part, shall be strictly prohibited.
*
*   MediaTek Inc. (C) [2007]. All rights reserved.
*
*************************************************************************/ 
/*******************************************************************************
* Filename:
* ---------
*  gps_trc.h
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  GPS trace goes here
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
 * removed!
 * removed!
 * removed!
 * removed!
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
*******************************************************************************/
#ifndef __GPS_TRC_H__
#define __GPS_TRC_H__
#if defined(__GPS_SUPPORT__) || defined(__BT_GPS_SUPPORT__)

#include "stack_config.h"
#include "kal_trace.h"

#ifndef __GNUC__
#define GPS_TRACE(args)     kal_trace args
#define GPS_SYS_TRACE(args) tst_sys_trace args
#else
#define GPS_TRACE(args)     NULL     
#define GPS_SYS_TRACE(args) NULL  
#endif

#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "gps_trc_gen.h"
#endif /* TST Trace Defintion */
#endif
BEGIN_TRACE_MAP(MOD_GPS)

   /***************TRC MSG FOR GPS BEGIN ********************/
   /* --------------------------------------------------------------- */
   /* -----------------------   COMMON USE ID    -------------------- */
   /* --------------------------------------------------------------- */

    /* --------------------------------------------------------------- */
    /* ----------------------- MODULE NAME:GPS_UART------------------- */
    /* --------------------------------------------------------------- */
    TRC_MSG(GPS_UART_TRC_MSG_HDLR, "[GPS_UART]gps_msg_hdlr MSG ID=%d")
    TRC_MSG(GPS_UART_TRC_DROP_ONE_SENTENCE, "[GPS_UART]NMEA buffer full drop one sentence[MOD_ID=%d]")
    TRC_MSG(GPS_UART_TRC_BUFFER_READ_SIZE, "[GPS_UART]read from ring mod=%d size=%d r_p=%d w_p=%d")
    TRC_MSG(GPS_UART_TRC_NEED_INDICATION, "[GPS_UART]Address %d need indication=%d")
    TRC_MSG(GPS_UART_TRC_OPEN_REQ_HDLR, "[GPS_UART]gps_uart_open_req_hdlr")
    TRC_MSG(GPS_UART_TRC_OPEN_REQ_HDLR_SET_EVENT, "[GPS_UART]gps_uart_open_req_hdlr done and set event")
    TRC_MSG(GPS_UART_TRC_OPEN_ERROR, "[GPS_UART]open uart error")
    TRC_MSG(GPS_UART_TRC_OPEN_ADD_TO_SLOT, "[GPS_UART] gps_uart_open_add_to_slot mode=%d mod_id=%d")
    TRC_MSG(GPS_UART_TRC_OPEN_ADD_TO_SLOT_FIND_MOD, "[GPS_UART] find a module open the port")
    TRC_MSG(GPS_UART_TRC_OPEN_ADD_TO_SLOT_FIND_SLOT, "[GPS_UART] find a empty slot to add request slot=%d")
    TRC_MSG(GPS_UART_TRC_OPEN_ADD_TO_SLOT_NO_SLOT, "[GPS_UART]Issue no slot to add request")
    TRC_MSG(GPS_UART_TRC_OPEN_ADD_TO_SLOT_SUCCESS, "[GPS_UART]Add to slot success")
    TRC_MSG(GPS_UART_TRC_OPEN_FIND_PORT, "[GPS_UART]uart_open_req_hdlr find the port =%d")
    TRC_MSG(GPS_UART_TRC_OPEN_NEW_PORT, "[GPS_UART]uart_open_req_hdlr need open new port num=%d")
    TRC_MSG(GPS_UART_TRC_OPEN_PORT_STATE, "[GPS_UART]uart_open_req_hdlr port state port=%d")
    TRC_MSG(GPS_UART_TRC_OPEN_GPS_PORT, "[GPS_UART]uart_open_req_hdlr port=GPS port call GPS_init")
    TRC_MSG(GPS_UART_TRC_OPEN_REQUEST_PORT, "[GPS_UART]uart_open_req_hdlr open normal port=%d")
    TRC_MSG(GPS_UART_TRC_OPEN_PORT_FINAL_STATE, "[GPS_UART]uart_open_req_hdlr final state=%d")
    TRC_MSG(GPS_UART_TRC_OPEN_RAW_OK, "[GPS_UART]uart_open_req_hdlr open RAW mode OK")
    TRC_MSG(GPS_UART_TRC_OPEN_LCT_OK, "[GPS_UART]uart_open_req_hdlr open location mode OK")
    TRC_MSG(GPS_UART_TRC_OPEN_QOP_OK, "[GPS_UART]uart_open_req_hdlr open QOP mode OK")
    TRC_MSG(GPS_UART_TRC_OPEN_FIND_MOD_CMP, "[GPS_UART]add_to_slot mod_index=%d mod=%d request mod=%d")
    TRC_MSG(GPS_UART_TRC_OPEN_FIND_EMP_MOD, "[GPS_UART]add_to_slot find empty mod index=%d mod_id=%d")
    TRC_MSG(GPS_UART_TRC_EVENT_IND, "[GPS_UART] on_event[%d]")
    TRC_MSG(GPS_UART_TRC_ERROR, "[GPS_UART] error[%d] happened!! line=%d")
    TRC_MSG(GPS_UART_TRC_MODE_READY, "[GPS_UART] gps_uart_is_mode_ready = %d")
    TRC_MSG(GPS_UART_TRC_GPS_START_FINISH, "[GPS_UART] GPS start finish = %d")
    TRC_MSG(GPS_UART_TRC_NEXT_JOB, "[GPS_UART] next_job=%d started=%d")

    TRC_MSG(GPS_UART_TRC_CLOSE_HDLR, "[GPS_UART]uart_close_req_hdlr request close port=%d mode=%d")
    TRC_MSG(GPS_UART_TRC_CLOSE_FIND_RAW, "[GPS_UART]uart_close_req_hdlr find RAW&close it")
    TRC_MSG(GPS_UART_TRC_CLOSE_FIND_LCT, "[GPS_UART]uart_close_req_hdlr find LCT&close it")
    TRC_MSG(GPS_UART_TRC_CLOSE_FIND_QOP, "[GPS_UART]uart_close_req_hdlr find QOP&close it")
    TRC_MSG(GPS_UART_TRC_CLOSE_CHECK_PORT_CLOSE, "[GPS_UART]uart_close_req_hdlr find LCT&close it")
    TRC_MSG(GPS_UART_TRC_CLOSE_GPS_POWER_DOWN, "[GPS_UART]uart_close_req_hdlr close internal gps port")
    TRC_MSG(GPS_UART_TRC_CLOSE_UART_PORT, "[GPS_UART]uart_close_req_hdlr close uart port num=%d")
    TRC_MSG(GPS_UART_TRC_CLOSE_EXIT, "[GPS_UART]uart_close_req_hdlr close function exit")
    TRC_MSG(GPS_UART_TRC_CLOSE_SWITCH_MOD_ID, "[GPS_UART]close_switch_req request_mod_id=%d ilm_mod=%d i=%d")
    TRC_MSG(GPS_UART_TRC_CLOSE_SWITCH_REQ_COUNT, "[GPS_UART]GPS CLOSE request_mod_id=%d request_count=%d i=%d")
    TRC_MSG(GPS_UART_TRC_CLOSE_SWITCH_ABORT_REQ_MOD, "[GPS_UART]GPS CLOSE abort for request_mod_id=%d cout=%d i =%d")
    TRC_MSG(GPS_UART_TRC_CLOSE_SWITCH_ABORT_MOD_ID, "GPS CLOSE abort for mod_id=%d i =%d")
    TRC_MSG(GPS_UART_TRC_CLOSE_PORT_ALREADY_CLOSED, "[GPS_UART]port %d already closed")

    TRC_MSG(GPS_UART_TRC_INTERNAL_WRITE, "[GPS_UART]uart internal write data add=%d length=%d")
    TRC_MSG(GPS_UART_TRC_WRITE_HDLR, "[GPS_UART]uart_write_req_hdlr port:%d buffer=%d length=%d is_raw=%d cmd=%d")
    TRC_MSG(GPS_UART_TRC_GPS_CMD_WARMSTART, "[GPS_UART]GPS command WARM START")
    TRC_MSG(GPS_UART_TRC_GPS_CMD_HOTSTART, "[GPS_UART]GPS command HOT START")
    TRC_MSG(GPS_UART_TRC_GPS_CMD_COLDSTART, "[GPS_UART]GPS command COLD START")
    TRC_MSG(GPS_UART_TRC_GPS_CMD_VERSION, "[GPS_UART]GPS command get version")
    TRC_MSG(GPS_UART_TRC_GPS_CMD_ENABLE_DEBUG_INFO, "[GPS_UART]GPS command enable debug info")
    TRC_MSG(GPS_UART_TRC_GPS_CMD_SWITCH_MA, "[GPS_UART]GPS command Switch to MA mode")
    TRC_MSG(GPS_UART_TRC_GPS_CMD_SWITCH_MB, "[GPS_UART]GPS command Switch to MB mode")
    TRC_MSG(GPS_UART_TRC_GPS_CMD_SWITCH_MB_TYPE, "[GPS_UART]GPS command Switch to MB mode, typr=%d")
    TRC_MSG(GPS_UART_TRC_GPS_CMD_SWITCH_NORMAL, "[GPS_UART]GPS command Switch to Normal mode")
    TRC_MSG(GPS_UART_TRC_GPS_CMD_POS_QUERY, "[GPS_UART]GPS command Position query")
    TRC_MSG(GPS_UART_TRC_GPS_CMD_MEAS_QUERY, "[GPS_UART]GPS command measurement query")
    TRC_MSG(GPS_UART_TRC_GPS_CMD_CLEAR_NVRAM, "[GPS_UART]GPS command clear nvram")
    TRC_MSG(GPS_UART_TRC_GPS_CMD_SLEEP,   "[GPS_UART]GPS command sleep")
    TRC_MSG(GPS_UART_TRC_GPS_CMD_STOP,    "[GPS_UART]GPS command stop")
    TRC_MSG(GPS_UART_TRC_GPS_CMD_WAKE_UP, "[GPS_UART]GPS command wake up")
    TRC_MSG(GPS_UART_TRC_GPS_CMD_WRITTEN, "[GPS_W]Written:%d")
    TRC_MSG(GPS_UART_TRC_GPS_CMD_NUMBER,  "[GPS_UART]GPS command:%d")
    TRC_MSG(GPS_UART_TRC_GPS_CMD_UNPROCESSED_CMD, "[GPS_UART]GPS command Unprocessed:PMTK%d")
   /* --------------------------------------------------------------- */
   /* ----------------------- MODULE NAME:GPS_PARSER------------------- */
   /* --------------------------------------------------------------- */

    TRC_MSG(GPS_UART_TRC_ENABLE_SENTENCE, "[GPS_PARSER] enable sentence")
    TRC_MSG(GPS_UART_TRC_DISABLE_SENTENCE, "[GPS_PARSER] disable sentence")
    TRC_MSG(GPS_UART_TRC_ENABLE_PARSER, "[GPS_PARSER] enable parser")
    TRC_MSG(GPS_UART_TRC_DISABLE_PARSER, "[GPS_PARSER] disable parser")
    TRC_MSG(GPS_PARSER_TRC_SUB_FIELD, "[GPS_PARSER] sub_field error: j=%d num_cmms=%d")
    TRC_MSG(GPS_TRC_EER_OVER_CMD_MAX_FILED, "[ERR] sub_field over max field error: j=%d num_cmms=%d")
    TRC_MSG(GPS_PARSER_TRC_SUB_FIELD_STAR, "[GPS_PARSER] sub_field error: star not found")
    TRC_MSG(GPS_PARSER_TRC_GGA_FAILED, "[GPS_PARSER] $GPGGA field failed ")
    TRC_MSG(GPS_PARSER_TRC_GLL_FAILED, "[GPS_PARSER] $GPGLL field failed ")
    TRC_MSG(GPS_PARSER_TRC_GSA_FAILED, "[GPS_PARSER] $GPGSA field failed ")
    TRC_MSG(GPS_PARSER_TRC_GSV_FAILED, "[GPS_PARSER] $GPGSV field failed ")
    TRC_MSG(GPS_PARSER_TRC_RMC_FAILED, "[GPS_PARSER] $GPRMC field failed ")
    TRC_MSG(GPS_PARSER_TRC_VTG_FAILED, "[GPS_PARSER] $GPVTG field failed ")
    TRC_MSG(GPS_PARSER_TRC_ACC_FAILED, "[GPS_PARSER] $ACCURACY field failed ")
    TRC_MSG(GPS_PARSER_TRC_P_RELEASE_FAILED, "[GPS_PARSER]PMTK Release field failed")
    TRC_MSG(GPS_PARSER_TRC_P_ACQ_FAILED, "[GPS_PARSER]PMTK ACQ field failed")
    TRC_MSG(GPS_PARSER_TRC_P_BITSYNC_FAILED, "[GPS_PARSER]PMTK bitsync field failed")
    TRC_MSG(GPS_PARSER_TRC_P_SIGNAL_FAILED, "[GPS_PARSER]PMTK signal field failed")
    TRC_MSG(GPS_PARSER_TRC_P_FIX_CONTRL_FAILED, "[GPS_PARSER]PMTK fix_control field failed")
    TRC_MSG(GPS_PARSER_TRC_P_CW_RESULT_FAILED, "[GPS_PARSER]PMTK cw result field failed")
    TRC_MSG(GPS_PARSER_TRC_P_CW_SUB_FIELD_INVALID, "[GPS_PARSER]PMTK cw result sub_field invalid")
    TRC_MSG(GPS_PARSER_TRC_PRO_SENTENCE, "[GPS_PARSER] mdi_gps_nmea_process_sentence")
    TRC_MSG(GPS_PARSER_TRC_PARSER_STR, "[GPS_PARSER][state] start found")
    TRC_MSG(GPS_PARSER_TRC_PARSER_CHK_SUM, "[GPS_PARSER][state] check sum flag found")
    TRC_MSG(GPS_PARSER_TRC_PARSER_NEED_END_CR, "[GPS_PARSER][state] need CR")
    TRC_MSG(GPS_PARSER_TRC_PARSER_END_CR_OK, "[GPS_PARSER][state] END CR OK")
    TRC_MSG(GPS_PARSER_TRC_PARSER_CHK_SUM_OK, "[GPS_PARSER][state] Check sum OK")
    TRC_MSG(GPS_PARSER_TRC_CB_GGA, "[GPS_PARSER]sentenc pro GPGGA enable=%d")
    TRC_MSG(GPS_PARSER_TRC_CB_GLL, "[GPS_PARSER]sentenc pro GPGLL enable=%d")
    TRC_MSG(GPS_PARSER_TRC_CB_GSA, "[GPS_PARSER]sentenc pro GPGSA enable=%d")
    TRC_MSG(GPS_PARSER_TRC_CB_GNGSA, "[GPS_PARSER]sentenc pro GNGSA enable=%d")
    TRC_MSG(GPS_PARSER_TRC_CB_GLGSA, "[GPS_PARSER]sentenc pro GLGSA enable=%d")
    TRC_MSG(GPS_PARSER_TRC_CB_GAGSA, "[GPS_PARSER]sentenc pro GAGSA enable=%d")
    TRC_MSG(GPS_PARSER_TRC_CB_BDGSA, "[GPS_PARSER]sentenc pro BDGSA enable=%d")
    TRC_MSG(GPS_PARSER_TRC_CB_GSV, "[GPS_PARSER]sentenc pro GPGSV enable=%d is all rec=%d")
    TRC_MSG(GPS_PARSER_TRC_CB_GLGSV, "[GPS_PARSER]sentenc pro GLGSV enable=%d is all rec=%d")
    TRC_MSG(GPS_PARSER_TRC_CB_GAGSV, "[GPS_PARSER]sentenc pro GAGSV enable=%d is all rec=%d")
    TRC_MSG(GPS_PARSER_TRC_CB_BDGSV, "[GPS_PARSER]sentenc pro BDGSV enable=%d is all rec=%d")
    TRC_MSG(GPS_PARSER_TRC_CB_RMC, "[GPS_PARSER]sentenc pro GPRMC enable=%d")
    TRC_MSG(GPS_PARSER_TRC_CB_GNRMC, "[GPS_PARSER]sentenc pro GNRMC enable=%d")
    TRC_MSG(GPS_PARSER_TRC_CB_VTG, "[GPS_PARSER]sentenc pro GPVTG enable=%d")
    TRC_MSG(GPS_PARSER_TRC_FIX_POSITION_OVER, "[GPS_PARSER]POSITION FIX OVER FIRST TIME")


   /* --------------------------------------------------------------- */
   /* ----------------------- MODULE NAME:GPS_LOGGING---------------- */
   /* --------------------------------------------------------------- */
    TRC_MSG(GPS_LOG_TRC_SWITCH, "[GPS_LOG]Logging Catcher=%d file=%d Agent=%d")
    TRC_MSG(GPS_LOG_TRC_SENTENCE_TYPE, "[GPS_LOG]Sentence Catcher=%d Agent=%d")
    TRC_MSG(GPS_LOG_TRC_STC_CALLBACK, "[GPS_LOG]Send NMEA sentence to callback=%d")
    TRC_MSG(GPS_LOG_TRC_SET_GGA_CALLBACK, "[GPS_LOG]Set GGA callback=%d")
    TRC_MSG(GPS_LOG_TRC_SET_RMC_CALLBACK, "[GPS_LOG]Set RMC callback=%d")
    TRC_MSG(GPS_LOG_TRC_SET_GSA_CALLBACK, "[GPS_LOG]Set GSP callback=%d")
    TRC_MSG(GPS_LOG_TRC_SET_GSV_CALLBACK, "[GPS_LOG]Set GSV callback=%d")
    TRC_MSG(GPS_LOG_TRC_SET_STC_CALLBACK, "[GPS_LOG]Set STC callback=%d")
    TRC_MSG(GPS_LOG_TRC_MAKE_PATH_CARD_DRIVER, "[GPS_LOG]make path get card driver=%d")
    TRC_MSG(GPS_LOG_TRC_MAKE_PATH_USER_DRIVER, "[GPS_LOG]make path get user driver=%d")
    TRC_MSG(GPS_LOG_TRC_SET_CATCHER_LOGGING, "[GPS_LOG]mdi_gps_nmea_set_catcher_logging=%d")
    TRC_MSG(GPS_LOG_TRC_SET_CATCHER_LOGGING_RES, "[GPS_LOG]g_mdi_gps_cntx.logging.catcher_logging=%d")
    TRC_MSG(GPS_LOG_TRC_SET_FILE_LOGGING, "[GPS_LOG]mdi_gps_nmea_set_file_logging=%d")
    TRC_MSG(GPS_LOG_TRC_SET_FILE_LOGGING_RES, "[GPS_LOG]g_mdi_gps_cntx.logging.file_logging=%d")
    TRC_MSG(GPS_LOG_TRC_SET_AGENT_LOGGING, "[GPS_LOG]mdi_gps_nmea_set_agent_logging=%d")
    TRC_MSG(GPS_LOG_TRC_SET_AGENT_LOGGING_RES, "[GPS_LOG]g_mdi_gps_cntx.logging.agent_logging=%d")
    TRC_MSG(GPS_LOG_TRC_GET_SETTING, "[GPS_LOG]load_logging_setting catcher =%d file=%d agent=%d")
    TRC_MSG(GPS_LOG_TRC_GET_CATCHER_LOGGING, "[GPS_LOG]mdi_gps_nmea_get_catcher_logging=%d")
    TRC_MSG(GPS_LOG_TRC_GET_FILE_LOGGING, "[GPS_LOG]mdi_gps_nmea_get_file_logging=%d")
    TRC_MSG(GPS_LOG_TRC_GET_AGENT_LOGGING, "[GPS_LOG]mdi_gps_nmea_get_agent_logging=%d")
    TRC_MSG(GPS_LOG_TRC_OPEN_FILE_HANDLE, "[GPS_LOG]open file handle=%d")
    TRC_MSG(GPS_LOG_TRC_CLOSE_FILE_HANDLE, "[GPS_LOG]close file handle=%d")
    TRC_MSG(GPS_LOG_TRC_OPEN_FILE_ERROR, "[GPS_LOG]open file error=%d")
    TRC_MSG(GPS_LOG_TRC_AGENT_WRITE_REQ, "[GPS_LOG]Agent ask write data data_ptr=%d length=%d")
    TRC_MSG(GPS_LOG_TRC_AGENT_WRITE_REQ_RET, "[GPS_LOG]Agent write return written=%d")
    TRC_MSG(GPS_LOG_TRC_SET_WORK_PORT, "[GPS_LOG]gps_set_work_port=%d")
    TRC_MSG(GPS_LOG_TRC_SET_AGENT_ENABLE, "[GPS_LOG]gps_set_agent_logging enable")
    TRC_MSG(GPS_LOG_TRC_SET_AGENT_DISABLE, "[GPS_LOG]gps_set_agent_logging disable")
    TRC_MSG(GPS_LOG_TRC_SET_CATCHER_ENABLE, "[GPS_LOG]gps_set_catcher_logging enable")
    TRC_MSG(GPS_LOG_TRC_SET_CATCHER_DISABLE, "[GPS_LOG]gps_set_catcher_logging disable")
    TRC_MSG(GPS_LOG_TRC_SET_FILE_ENABLE, "[GPS_LOG]gps_set_file_logging enable")
    TRC_MSG(GPS_LOG_TRC_SET_FILE_DISABLE, "[GPS_LOG]gps_set_file_logging disable")
    TRC_MSG(GPS_LOG_TRC_SET_DEBUG_ENABLE, "[GPS_LOG]gps_set_debug_info enable")
    TRC_MSG(GPS_LOG_TRC_SET_DEBUG_DISABLE, "[GPS_LOG]gps_set_debug_info disable")
    TRC_MSG(GPS_AGPS_TRC_P_RSP_FAILED, "[GPS]Parser P response error")

#if defined(__AGPS_SUPPORT__)
   /* --------------------------------------------------------------- */
   /* ----------------------- MODULE NAME:GPS_AGPS___---------------- */
   /* --------------------------------------------------------------- */
    TRC_MSG(GPS_AGPS_TRC_CMD_TIMEOUT, "[AGPS]CMD timeout cmd=%d")
    TRC_MSG(GPS_AGPS_TRC_CMD_IN_PROCESSING, "[AGPS]processing CMD is in processing=%d")
    TRC_MSG(GPS_AGPS_TRC_CMD_START_WRITE_EXP_TIMER, "[AGPS]start CMD time exp timer")
    TRC_MSG(GPS_AGPS_TRC_NAVIGATION_WRITE, "[AGPS]navigation write index=%d sate_num=%d")
    TRC_MSG(GPS_AGPS_TRC_REF_TIME_TOW_ASSIST_WRITE, "[AGPS]ref time tow assist write index=%d sate_num=%d")
    TRC_MSG(GPS_AGPS_TRC_ALMANAC_WRITE, "[AGPS]almanac write index=%d sate_num=%d")
    TRC_MSG(GPS_AGPS_TRC_ACQUISITION_WRITE, "[AGPS]acquisition write index=%d sate_num=%d")
    TRC_MSG(GPS_AGPS_TRC_REF_LOCATION_WRITE, "[AGPS]ref_location write")
    TRC_MSG(GPS_AGPS_TRC_REF_LOCATION_WRITE_FAIL, "[AGPS]ref_location write fail")
    TRC_MSG(GPS_AGPS_TRC_IONOSPHERE_WRITE, "[AGPS]ionosphere write")
    TRC_MSG(GPS_AGPS_TRC_REF_TIME_WRITE, "[AGPS]ref_time write")
    TRC_MSG(GPS_AGPS_TRC_UTC_WRITE, "[AGPS]UTC write")
    TRC_MSG(GPS_AGPS_TRC_RTI_WRITE, "[AGPS]real time integrity write")
    TRC_MSG(GPS_AGPS_TRC_DGPS_CORRECTION_WRITE, "[AGPS]dgps correction write")
    TRC_MSG(GPS_AGPS_TRC_AGPS_PARSER, "[AGPS]AGPS PARSER cmd=%d")
    TRC_MSG(GPS_AGPS_TRC_CALC_CHECK_SUM_ERROR, "[AGPS]Check Sum Error: Sum = %d")
    TRC_MSG(GPS_AGPS_TRC_ASSIST_DATA_STATE, "[AGPS]acq=%d,nav=%d,ref_l=%d,iono=%d,ref_t=%d,utc=%d,rti=%d,dgps=%d")
    TRC_MSG(GPS_AGPS_TRC_RES_NOT_FOUND_CMD, "[AGPS]RESPONSE parser not found CMD")
    TRC_MSG(GPS_AGPS_TRC_RES_CMD_RESULT, "[AGPS]response CMD:%d result:%d")
    TRC_MSG(GPS_AGPS_TRC_NAV_SEND_ERROR, "[AGPS]send navigation error")
    TRC_MSG(GPS_AGPS_TRC_NAV_INDEX_EQU_N_SAT, "[AGPS]navigation_index = N_sat")
    TRC_MSG(GPS_AGPS_TRC_IND_REQ_FALSE, "[AGPS]assist_indication_req = KAL_FALSE")
    TRC_MSG(GPS_AGPS_TRC_POS_QOP_DECODE, "Pos_array[%d]:maj_unc=%d min_unc=%d alt_unc=%d")
    TRC_MSG(GPS_AGPS_TRC_MEAS_TICKS_NOW, "[AGPS]Meas Ticks now=%d req=%d delay=%d")
    TRC_MSG(GPS_AGPS_TRC_POS_TICKS_NOW, "[AGPS]Pos Ticks now=%d req=%d delay=%d")
    TRC_MSG(GPS_AGPS_TRC_MEAS_PARSER_FAILED, "[AGPS]Parser measurement data error")
    TRC_MSG(GPS_AGPS_TRC_ASSIST_DATA_FAILED, "[AGPS]Parser assist data bitmap error")
#if defined(__L1_GPS_AUTO_TIMING_SYNC_SUPPORT__) || defined(__L1_GPS_REF_TIME_SUPPORT__)
    TRC_MSG(GPS_AGPS_TRC_FTIME_PARSER_FAILED, "[AGPS]Parser ftime data error")
#endif
    TRC_MSG(GPS_AGPS_TRC_POS_TIMER_START, "[AGPS]Start Pos time index=%d")
    TRC_MSG(GPS_AGPS_TRC_MEAS_TIMER_START, "[AGPS]Start Meas time index=%d")
    TRC_MSG(GPS_AGPS_TRC_POS_TIMER_STOP, "[AGPS]Stop Pos time index=%d")
    TRC_MSG(GPS_AGPS_TRC_MEAS_TIMER_STOP, "[AGPS]Stop Meas time index=%d")
    TRC_MSG(GPS_AGPS_TRC_SET_POS_GPS_TASK1, "[AGPS]Set pos to GPS task latitude=%d sign=%d")
    TRC_MSG(GPS_AGPS_TRC_SET_POS_GPS_TASK2, "[AGPS]Set pos to GPS task longtitude=%d")
    TRC_MSG(GPS_AGPS_TRC_SET_POS_GPS_TASK3, "[AGPS]Set pos to GPS task altitude=%d sign=%d")
    TRC_MSG(GPS_AGPS_TRC_SET_POS_GPS_TASK4, "[AGPS]Set pos to GPS task unc_major=%d/%d unc_minor=%d/%d")
    TRC_MSG(GPS_AGPS_TRC_SET_POS_GPS_TASK5, "[AGPS]Set pos to GPS task unc_bear=%d unc_vert=%d/%d")
    TRC_MSG(GPS_AGPS_TRC_SET_POS_GPS_TASK6, "[AGPS]Set pos to GPS task confidence=%d h_speed=%d")
    TRC_MSG(GPS_AGPS_TRC_SET_POS_GPS_TASK7, "[AGPS]Set pos to GPS task bearing=%d ticks=%d")
    TRC_MSG(GPS_AGPS_TRC_POS_TO_GAD_UNC_MAJOR, "[AGPS][lcsp_pos_to_gad] unc_major[%d/%d]")
    TRC_MSG(GPS_AGPS_TRC_POS_TO_GAD_UNC_MINOR, "[AGPS][lcsp_pos_to_gad] unc_minor[%d/%d]")
    TRC_MSG(GPS_AGPS_TRC_POS_TO_GAD_UNC_VERT, "[AGPS][lcsp_pos_to_gad] unc_altitude[%d/%d]")
    TRC_MSG(GPS_AGPS_TRC_QOP_CHECK_DELAY, "[AGPS]QOP check qop_delay=%d delay_valid=%d his->ticks=%d sys_ticks=%d")
    TRC_MSG(GPS_AGPS_TRC_MAJ_MIN_UNC_DISMATCH, "[AGPS]QOP maj min his_maj=%d his_min=%d maj=%d min=%d")
    TRC_MSG(GPS_AGPS_TRC_ALTITUDE_DISMATCH, "[AGPS] QOP altitude dismatch, curr_alt_unc[%d] req_alt_unc[%d], line[%d]")
    TRC_MSG(GPS_AGPS_TRC_MEAS_INDEX_MEET_QOP, "[AGPS]index:%d meas data meet qop")
    TRC_MSG(GPS_AGPS_TRC_MEAS_INDEX_TIMEOUT, "[AGPS]Meas timeout:index=%d")
    TRC_MSG(GPS_AGPS_TRC_POS_INDEX_TIMEOUT, "[AGPS]Pos timeout:index=%d")
    TRC_MSG(GPS_AGPS_TRC_WAIT_FOR_REF_TIME_ASSIST_BITMAP, "[AGPS] wait for ref_time assist data bitmap=%d")
    TRC_MSG(GPS_AGPS_CMD_IN_PROCESSING, "[AGPS] cmd is in processing = %d")    
    TRC_MSG(GPS_AGPS_TRC_LOC_ERROR_SEND_RSP, "[AGPS] gps_loc_error_send_rsp(), enter")
    TRC_MSG(GPS_AGPS_TRC_CURRENT_ASSIST_BITMAP, "[AGPS] current assist bitmap=%d")
    TRC_MSG(GPS_AGPS_TRC_POS_VALID, "[AGPS] pos [%d] is valid")
    TRC_MSG(GPS_AGPS_TRC_MEAS_VALID, "[AGPS] meas [%d] is valid")
    TRC_MSG(GPS_AGPS_TRC_CHECK_MEAS_QOP, "[AGPS] check assist=%d, bitmap=%d, pass=%d, acquisition_valid=%d")
    TRC_MSG(GPS_AGPS_TRC_LOC_ERROR_PARSER, "[AGPS] gps_agps_loc_error_parser(), enter")
    TRC_MSG(GPS_AGPS_TRC_RET, "[AGPS] ret[%d] at line[%d]")
    TRC_MSG(GPS_AGPS_TRC_POS_REPORT_DELAY, "[AGPS] POS report delayed, curr_cnt[%d], target_cnt[%d]")
    TRC_MSG(GPS_AGPS_PROC_NEW_CMD, "[AGPS] New cmd is coming")
#endif

   /* --------------------------------------------------------------- */
   /* ----------------------- MODULE NAME:GPS_SLEEP_MODE--------------*/
   /* --------------------------------------------------------------- */
    TRC_MSG(GPS_TIMER_TRC_TIMEOUT_ID, "[GPS_TIMER] gps timer id=%d")
    TRC_MSG(GPS_SLEEP_TRC_ENABLE_SLEEP, "[GPS_SLEEP] enable gsm sleep mode, current_time=%d")
    TRC_MSG(GPS_SLEEP_TRC_DISABLE_SLEEP, "[GPS_SLEEP] disable gsm sleep mode, current_time=%d")
    TRC_MSG(GPS_SLEEP_TRC_START_TIMER, "[GPS_SLEEP] start timer, current_time=%d, timeout=%d, timer=%d")
    TRC_MSG(GPS_SLEEP_TRC_STOP_TIMER, "[GPS_SLEEP] stop timer, current_time=%d, timer=%d")
    TRC_MSG(GPS_SLEEP_TRC_UART_DATA, "[GPS_SLEEP] we can't sleep because UART still has some data!!")
    TRC_MSG(GPS_SLEEP_TRC_SEND_ACK, "[GPS_SLEEP] send ACK to GPS module!!")

   /* --------------------------------------------------------------- */
   /* ----------------------- MODULE NAME:GPS_CALIBRATION_RTC-------- */
   /* --------------------------------------------------------------- */
    TRC_MSG(GPS_RTC_TRC_UTC_INVALID_TIME, "[GPS_RTC] UTC time is invalid")
    TRC_MSG(GPS_RTC_TRC_FIRST_POWERON, "[GPS_RTC] The phone is first power on")
    TRC_MSG(GPS_RTC_TRC_CALIBRATE_RTC, "[GPS_RTC] Utilize GPS UTC time to calibrate GSM RTC time")
    TRC_MSG(GPS_RTC_TRC_ADJUST_RTC_DIFF, "[GPS_RTC] GSM's RTC time is changed!!! We need to adjust the difference")
    TRC_MSG(GPS_RTC_TRC_GSM_CURRENT_TIME, "[GPS_RTC] gsm current time, year=%d, mon=%d, day=%d, hour=%d, min=%d, sec=%d")
    TRC_MSG(GPS_RTC_TRC_GSM_CURRENT_GPS_TIME, "[GPS_RTC] gsm current gps time, wn=%d, tow=%d")
    TRC_MSG(GPS_RTC_TRC_GPS_CURRENT_TIME, "[GPS_RTC] gps current time, year=%d, mon=%d, day=%d, hour=%d, min=%d, sec=%d")
    TRC_MSG(GPS_RTC_TRC_GPS_CURRENT_GPS_TIME, "[GPS_RTC] gps current gps time, wn=%d, tow=%d")
    TRC_MSG(GPS_RTC_TRC_DIFF_CURRENT_GPS_TIME, "[GPS_RTC] diff current gps time, wn=%d, tow=%d")
    /* ----------------------- MODULE NAME:add-------- */
    TRC_MSG(GPS_UTC_TRC_AGE_TOW_RANGE, "[GPS_RTC] age_tow > 1 week || age_tow < 0 ")
    TRC_MSG(GPS_UTC_TRC_CALIBRATE_CLOCK_DRIFT_FAIL, "[GPS_RTC] Calibrate Clock Drift Fail")
    TRC_MSG(GPS_UTC_TRC_GPS_CLOCK_DRIFT, "[GPS_RTC] diff current gps time, wn=%d, tow=%d")
    TRC_MSG(GPS_RTC_TRC_PREVIOUS_RTC, "[GPS_RTC] previous RTC:year=%d, mon=%d, day=%d, hour=%d, min=%d, sec=%d")
    TRC_MSG(GPS_RTC_TRC_NEW_RTC, "[GPS_RTC] new RTC:year=%d, mon=%d, day=%d, hour=%d, min=%d, sec=%d")
    TRC_MSG(GPS_TRC_MNL_HW_CHECK_SIZE, "[GPS_INIT] MNL HW Check Size = %d !")
    TRC_MSG(GPS_TRC_MNL_HW_CHECK_DATA, "[GPS_INIT] MNL HW Check Data = 0x%x !")
    TRC_MSG(GPS_TRC_MNL_HW_CHECK_OK, "[GPS_INIT] MNL HW Check OK !")
    TRC_MSG(GPS_TRC_MNL_HW_CHECK_FAIL, "[GPS_INIT] MNL HW Check Fail...Try Again !!!")
    TRC_MSG(GPS_TRC_MNL_HW_CHECK_32K_CLOCK, "[GPS_INIT] MNL HW Check,modelpo,%d,numlpo,%d,TEST")
    TRC_MSG(GPS_TRC_MNL_HW_CHECK_POWER_PIN, "[GPS_INIT] MNL HW Check,pol_poweronGPS,%d,num_poweronGPS,%d,TEST")
    TRC_MSG(GPS_TRC_MNL_HW_CHECK_RXD_PIN, "[GPS_INIT] MNL HW Check,gps_urxd_mode,%d,num_urxd,%d,TEST")
    TRC_MSG(GPS_TRC_MNL_HW_CHECK_TXD_PIN, "[GPS_INIT] MNL HW Check,gps_utxd_mode,%d,num_utxd,%d,TEST")
    TRC_MSG(GPS_TRC_MNL_HW_CHECK_EINT_PIN, "[GPS_INIT]MNL HW Check,GPS_INO,%d,eint_pin,%d,TEST")
    TRC_MSG(GPS_TRC_MNL_INIT_GPS_STATUS, "[GPS_INIT] gps_state:(%d),if 1:init MNL; 0:not to init MNL.")
    TRC_MSG(GPS_TRC_MNL_INIT, "[GPS_INIT] MNL Init")
    TRC_MSG(GPS_TRC_READ_GPS_DSP_BIN_SECCUSS, "[GPS_INIT] success to read gps_dsp.bin!")
    TRC_MSG(GPS_TRC_READ_GPS_DSP_BIN_FAIL, "[GPS_INIT] Fail to read gps_dsp.bin!")
    TRC_MSG(GPS_TRC_MNL_INIT_OK, "[GPS_INIT] MNL Init OK !!!")
    TRC_MSG(GPS_TRC_MNL_INIT_FAIL, "[GPS_INIT] MNL Init Fail !!!")
    TRC_MSG(GPS_TRC_MNL_SHUTDOWN_GPS_STATUS, "[GPS_CLOSE] GPS_Status:(%d).0:do MNL shutdown; 1: not do GPS MNL Shutdown()!!!")
    
    TRC_MSG(GPS_TRC_MNL_SHUTDOWN, "MNL Shutdown")
    TRC_MSG(GPS_TRC_GPS_STOP_TIMER, "MNL Shutdown")
    TRC_MSG(GPS_INJECT_CMD_TRC_UART_BAUDRATE_SETTING_INVALID, "[warning]The inject string is out of range[1~4]!!!")
    TRC_MSG(GPS_INJECT_CMD_TRC_GPS_OPEN_NOTIFY, "The GPS hasn't Power ON.Turn ON GPS first!!!")
    TRC_MSG(GPS_INJECT_CMD_TRC_GPS_POWER_ON_OFF_OPEN_GPS, "[GPS_INJECT] power on GPS. left count:%d ")
    TRC_MSG(GPS_INJECT_CMD_TRC_GPS_POWER_ON_OFF_CLOSE_GPS, "[GPS_INJECT]power off GPS left count:%d ")
    TRC_MSG(GPS_INJECT_CMD_TRC_GPS_POWER_ON_OFF_COUNT, "[GPS_INJECT]power on off Count:%d. ON:%d minisecond .OFF:%d minisecond")
    TRC_MSG(GPS_TRC_GPS_ENTER_POWER_SAVEING_MODE, "[APSM] Enter Power Saving Mode")
    TRC_MSG(GPS_TRC_GPS_ENTER_NORMAL_FIX_MODE, "[APSM] Enter Normal Fix Mode")
    TRC_MSG(GPS_TRC_GPS_NORMAL_FIX_COUNT, "[APSM] gps_ps_normal_fix_count = %d")
    TRC_MSG(GPS_TRC_GPS_NO_FIX_COUNT, "[APSM] no fix = %d")
    TRC_MSG(GPS_TRC_GPS_SPEED_LOW_NORMAL_FIX_COUNT, "[APSM] speed <  10 and normal = %d")
    TRC_MSG(GPS_TRC_GPS_SPEED_HIGHNORMAL_FIX_COUNT, "[APSM] speed >= 10 and normal = %d")
    
    TRC_MSG(GPS_TRC_IS_GSM_GPS_REF_TIME_NEEDED, "time sync - is_gsm_gps_ref_time_wanted=%d")
    TRC_MSG(GPS_TRC_IS_UTRAN_GPS_REF_TIME_NEEDED, "time sync - is_utran_gps_ref_time_wanted=%d")
    TRC_MSG(GPS_PARSER_TRC_NMEA_CRC_CHECK_FAILD, "NMEA CRC error:%s")
    /* --------------------------------------------------------------- */
    /* ----------------------- MODULE NAME:GPS_META------------------- */
    /* --------------------------------------------------------------- */
    TRC_MSG(GPS_INJECT_TRC_OPERATE_AND_CMD, "[GPS_INJECT]operate_type:%d;sv_id:%d;bitmap:%d")
    TRC_MSG(GPS_META_TRC_OP_TYPE, "[GPS_META]op type:%d")
    TRC_MSG(GPS_META_TRC_INALID_OP_TYPE, "[GPS_META]don't support this op type:%d")
    TRC_MSG(GPS_META_TRC_GPS_HAS_NOT_START_YET, "[GPS_META]GPS has not start yet!!! Please start GPS first")
    TRC_MSG(GPS_META_TRC_INVALID_SV_ID, "[GPS_META]SV_id %d is invalid")
    TRC_MSG(GPS_META_TRC_INVALID_CMD_BITMAP, "[GPS_META]cmd bitmap 0x%x is invalid")
    TRC_MSG(GPS_META_TRC_QUERY_BITMAP_MASK, "[GPS_META]GPS query mp test bitmap:%x")
    TRC_MSG(GPS_META_TRC_GPS_CLOSE, "[GPS_META]GPS close")
    TRC_MSG(GPS_MNL_TRC_GPS_RECEIVED_INIT_REP_FROM_MNL, "[GPS_MNL]it has received MNL Init responce message")
    TRC_MSG(GPS_META_TRC_IS_GPS_INIT_OK, "[GPS_META]is_start_ok:%d")
    TRC_MSG(GPS_META_TRC_MP_TEST_SIGNAL, "[GPS_META]signal:%d,%d,%d,%d,%d,%d,%d.")
    TRC_MSG(GPS_META_TRC_MP_TEST_BITSYNC, "[GPS_META]bitsync:%d,%d.")
    TRC_MSG(GPS_META_TRC_MP_TEST_ACQ, "[GPS_META]acq:%d,%d.")
    TRC_MSG(GPS_META_TRC_MP_TEST_FIX_CTRL, "[GPS_META]fix_ctrl:%d,%d,%d,%d,%d.")
    TRC_MSG(GPS_META_TRC_MP_TEST_FINISHED, "[GPS_META]GPS MP test finished.")
    TRC_MSG(GPS_META_TRC_UNPROCESSED_CMD, "[GPS_META]cmd PMTK%d is un-processed.")
    /* --------------------------------------------------------------- */
    /* ----------------------- INF & WRN & ERR Log ------------------- */
    /* --------------------------------------------------------------- */
    // UART Open & Close
    TRC_MSG(GPS_TRC_INF_UART_INIT_FIN,      "[INF][UART Init]gps_uart_state_init() finish!")
    TRC_MSG(GPS_TRC_INF_UART_RESET_FIN,     "[INF][UART Init]gps_uart_state_reset() finish!")
    TRC_MSG(GPS_TRC_INF_UART_OPEN_NEW,      "[INF][UART Open]new port =%d by mod id=%d")
    TRC_MSG(GPS_TRC_INF_UART_OPEN_NEW_MODU, "[INF][UART Open]new mod id=%d, index=%d")
    TRC_MSG(GPS_TRC_INF_UART_OPEN_SET_MODE, "[INF][UART Open]mod id=%d, mode=%d")
    TRC_MSG(GPS_TRC_WRN_UART_OPEN_NO_SLOT,       "[WRN][UART Open]failed to add mod id=%d to slot")
    TRC_MSG(GPS_TRC_WRN_UART_OPEN_SEND_ERR_PORT, "[WRN][UART Open]mod id=%d send error port=%d")
    TRC_MSG(GPS_TRC_WRN_UART_OPEN_INIT_ERR_PORT, "[WRN][UART Open]cntx port should be 0xFF, but %d!")
    TRC_MSG(GPS_TRC_INF_UART_CLOSE_CLR_MODE, "[INF][UART Close]mod id=%d, clr mode=%d")
    TRC_MSG(GPS_TRC_INF_UART_CLOSE_DEL_MODU, "[INF][UART Close]del mod id=%d, index=%d")
    TRC_MSG(GPS_TRC_INF_UART_CLOSE_ALL,      "[INF][UART Close]All module detached!GPS will power off!")
    TRC_MSG(GPS_TRC_WRN_UART_CLOSE_SEND_ERR_PORT, "[WRN][UART Close]mod id=%d send port=%d, but cntx port=%d")
    TRC_MSG(GPS_TRC_WRN_UART_CLOSE_CNTX_ERR_PORT, "[WRN][UART Close]cntx port=%d, it's an abnormal value!")

    // UART Read & Write & Parser & File   
    TRC_MSG(GPS_TRC_WRN_UART_WRITE_SEND_ERR_PORT, "[WRN][UART Write]port=%d, but cntx port=%d")
    TRC_MSG(GPS_TRC_INF_UART_WRITE_CMD,           "[INF][UART Write]cmd=%d, ret=%d. Open TRACE_GROUP_1 to see more.")
    TRC_MSG(GPS_TRC_WRN_UART_READ_SEND_ERR_PORT,  "[WRN][UART Read]port=%d, but cntx port=%d")
    TRC_MSG(GPS_TRC_WRN_UART_READ_LOSE_DBG,       "[WRN][UART Read]dbg file lose %d byte!")
    
    TRC_MSG(GPS_TRC_INF_UART_NMEA_GET_FIXED,    "[INF][Paser]GPS get fixed")
    TRC_MSG(GPS_TRC_WRN_UART_NMEA_CHK_ERR,      "[WRN][Paser]NEMA crc check failed")
    TRC_MSG(GPS_TRC_WRN_UART_NMEA_PMTK_RESP,    "[INF][Paser]PMTK response cmd=%d, result=%d")
    TRC_MSG(GPS_TRC_EER_UART_NMEA_BUF_OVERFLOW, "[ERR][Paser]NEMA buffer will overflow")
    
    TRC_MSG(GPS_TRC_WRN_FILE_GET_DRIVE_FAIL, "[WRN][File]get drive failed!")
    TRC_MSG(GPS_TRC_WRN_FILE_PRE_ALLOC_FAIL, "[WRN][File]pre-alloc failed!")
    TRC_MSG(GPS_TRC_WRN_FILE_WRITE_DBG_FAIL, "[WRN][File]write dbg file failed!")
    TRC_MSG(GPS_TRC_WRN_FILE_WRITE_NMA_FAIL, "[WRN][File]write nma file failed!")
    TRC_MSG(GPS_TRC_INF_FILE_OPEN_DBG, "[INF][File]open dbg file handle=%d, mode=%x")
    TRC_MSG(GPS_TRC_INF_FILE_OPEN_NMA, "[INF][File]open nma file handle=%d, mode=%x")
    TRC_MSG(GPS_TRC_INF_FILE_CLOSE_DBG, "[INF][File]close dbg file handle=%d")
    TRC_MSG(GPS_TRC_INF_FILE_CLOSE_NMA, "[INF][File]close nma file handle=%d")

            
    // Power On & Off
    TRC_MSG(GPS_TRC_INF_POWER_NOT_1ST_ON,    "[INF][Power]Not 1st power on")
    TRC_MSG(GPS_TRC_INF_POWER_ALREADY_ON,    "[INF][Power]2nd power on GPS, but GPS already on!")
    TRC_MSG(GPS_TRC_INF_POWER_ALREADY_OFF,   "[INF][Power]2nd power off GPS, but GPS already off!")
    TRC_MSG(GPS_TRC_INF_POWER_EINT_INIT_OK,  "[INF][Power]EINT init ok, channel=%d, debounce=%d")
    TRC_MSG(GPS_TRC_INF_POWER_SET_BAUD,      "[INF][Power]Set UART baudrate=%d")
    TRC_MSG(GPS_TRC_INF_FILE_OPEN_DSP,       "[INF][File]open %c:\\gps_dsp.bin, handle=%d, mode=%x")
    TRC_MSG(GPS_TRC_WRN_FILE_GET_DRIVER_FAIL,"[WRN][File]get drive failed!")
    TRC_MSG(GPS_TRC_ERR_POWER_EINT_PIN_NUM,   "[ERR][Power]Failed to assign eint pin")
    TRC_MSG(GPS_TRC_ERR_POWER_GPIO_PIN_NUM,   "[ERR][Power]Failed to assign gpio pin")
    TRC_MSG(GPS_TRC_ERR_POWER_MNL_INIT_FAIL,  "[ERR][Power]MNL init failed!")
    
    //RTC NVRAM SLEEP 
    TRC_MSG(GPS_TRC_INF_RTC_REGISTER, "[INF][RTC]register status=%d")
    TRC_MSG(GPS_TRC_INF_NVRAM_WRITE_REQ,     "[INF][NVRAM]gps_nvram will be written in.")
    TRC_MSG(GPS_TRC_INF_NVRAM_WRITE_CNF_OK,  "[INF][NVRAM]Write OK!")
    TRC_MSG(GPS_TRC_WRN_NVRAM_WRITE_CNF_ERR, "[WRN][NVRAM]Write failed!")    
    TRC_MSG(GPS_TRC_INF_SLEEP_AUTO_POWER_SAVING,  "[INF][Sleep]Automatically enter power saving mode, resume after %d ticks")
    TRC_MSG(GPS_TRC_INF_SLEEP_START_WAKEUP_TIMER, "[INF][Sleep]Will call wakeup_handler after %d ticks, sleep enable=%d")
    
    // State Change & Inject 
    TRC_MSG(GPS_TRC_INF_STATE_CHANGE_MNL_DEBUG, "[INF][State]gps_enable_mnl_debug from %d to %d, 0:disable, not 0:enable")
    TRC_MSG(GPS_TRC_INF_STATE_CHANGE_SlEEP_FLAG,"[INF][State]gps_sleep_enable_flag from %d to %d, 1:enable, not 1:disable")
    TRC_MSG(GPS_TRC_INF_STATE_CHANGE_POWER_FLAG,"[INF][State]gps_power_saving_mode_flag from %d to %d, 1:enable, not 1:disable")
    TRC_MSG(GPS_TRC_INF_STATE_CHANGE_POWER_TYPE,"[INF][State]gps_power_saving_mode_type from %d to %d, 1:MNL do, not 1:GPS_Shutdown")
    TRC_MSG(GPS_TRC_INF_STATE_ENABLE_AUTH,      "[INF][State]Enable gps authentication")
    TRC_MSG(GPS_TRC_WRN_INJECT_ILLEGAL_CMD,     "[WRN][Inject]illegal cmd num %d")   
    TRC_MSG(GPS_TRC_WRN_INJECT_ILLEGAL_STRING,  "[WRN][Inject]illegal cmd string")
    TRC_MSG(GPS_TRC_INF_UART_OPEN_INJECT_SEND_MSG,  "[INF][UART Open]Inject send msg to open UART")
    TRC_MSG(GPS_TRC_INF_UART_CLOSE_INJECT_SEND_MSG, "[INF][UART Close]Inject send msg to close UART")
    TRC_MSG(GPS_TRC_INF_SLEEP_INJECT_SET_POWER_SAVING,  "[INF][Sleep]Inject set power saving mode %d, 0:wakeup, not 0:power saving")
    TRC_MSG(GPS_TRC_WRN_MSG_INVALID_ID, "[WRN]Invalid msg id=%d")

#ifdef __GPS_EPO_DOWNLOAD__
   // epo download trace
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_FINISH_CONNECTION, "[EPO]epo_download_finish_connection")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_ERROR_HANDLE, "[EPO]epo_download_error_handle. state:%d, error:%d, file_type:%d")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_START_TIMER, "[EPO]epo_download_start_timer, timer id:%d, period:%d, arg:%d")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_FILE_OPEN, "[EPO]epo_file_open, file_type:%d, file_index:%d")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_FILE_HANDLE, "[EPO]file_handle = %d")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_FILE_DELETE, "[EPO]epodownload_file_delete, file_type:%d, file_index:%d")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_FILE_DELETE_RET, "[EPO]delete ret = %d")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_FILE_RENAME, "[EPO]epodownload_file_rename, file_type:%d, file_index_old:%d, file_index_new:%d")    
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_FILE_RENAME_RET, "[EPO]rename ret = %d")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_UTC_TO_GPS_HOUR, "[EPO]utc_to_gps_hour,%d:%d:%d:%d")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_CURR_GPS_HOUR, "[EPO]current gps_hour:%d")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_GET_MAX_GPS_HOURS, "[EPO]epo_get_max_gps_hours")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_MAX_GPS_HOURS, "[EPO]max_gps_hours:%d")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_CHECK_FILE_EXPIRED, "[EPO]epo_check_file_expired")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_FILE_GPS_HOURS, "[EPO]check file expired. current_gps_hour:%d, max_gps_hours:%d")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_CHECK_DOWNLOAD_FINISH, "[EPO]epo_check_download_finish")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_START_CHECK_SUM, "[EPO]start check sum")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_CHECK_SUM_OK, "[EPO]check sum OK")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_CHECK_SUM_FAIL, "[EPO]check sum fail")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_START_CONNECTION, "[EPO]epo_start_connection")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_CONNECT_FAIL, "[EPO]connect fail")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_CONNECT_SEND, "[EPO]epo_connection_send")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_CONNECT_SEND_FAIL, "[EPO]send fail")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_SAVE_RECIEVE_DATA, "[EPO]epo_save_recieve_data")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_FILE_WRITE_FAIL, "[EPO]file write fail, result:%d")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_PEOCESS_HEADER, "[EPO]epo_process_header")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_CONTENT_LENGH_WRONE, "[EPO]content lengh wrong, lengh:%d")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_ETAG_ERROR, "[EPO]ETag error!")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_RECIEVING_BODY, "[EPO]recieving body")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_RECIEVING_HEAD, "[EPO]recieving head")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_CONNECTION_RECIEVE, "[EPO]epo_connection_receive")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_SOCKET_ID_ERROR, "[EPO]socket id error")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_SOCKET_READ_FAIL, "[EPO]socket read fail")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_TRY_FINISH_CURR_DOWNLOAD, "[EPO]epo_try_finish_curr_down_load")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_SOCKET_NOTIFY, "[EPO]my_socket_notify")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_WRONG_SOCKET_ID, "[EPO]wrong socket id")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_ENVENT_FILE_TYPE, "[EPO]event_type:%d, file type:%d")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_START_CONNECTION_AGAIN, "[EPO]start connection again")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_SOCKET_CLOSE_ERROR, "[EPO]socket close error")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_EPO_CONNECTIVTY_MESSAGE_HANDLER, "[EPO]epo_connectivty_message_handler")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_GET_HOST_BY_NAME_INT, "[EPO]epo_get_host_by_name_int")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_ALREADY_GET_IP, "[EPO]already get ip address")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_IP_ADDR, "[EPO]IP_ADDR:%d.%d.%d.%d")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_GET_IP_FAIL, "[EPO]get ip fail")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_GET_HOST_BY_NAME, "[EPO]epo_get_host_by_name")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_CREATE_AND_START_CONNECTION, "[EPO]epo_create_and_start_connection, file_type:%d")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_SOCKET_CREATE_FAIL, "[EPO]socket create fail")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_3_DAY_SINGLE_CHUNK, "[EPO]epo_download_3_day_single_chunk")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_IS_EXCEED_ONE_DAY, "[EPO]epo_is_download_fail_time_exceed_one_day")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_FILE_OPEN_ERROR, "[EPO]file open error:%d")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_CURR_MAX_GPS_HOURS, "[EPO]current_gps_hour:%d, gps_hours:%d")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_TIMER_CALLBACK, "[EPO]epo_download_timer_callback")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_START_3_DAY_TIMER, "[EPO]epo_start_3_day_download_timer")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_EXPIRY_TIME, "[EPO]expiry_time:%d")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_3_DAY, "[EPO]epo_download_3_day, state:%d")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_DELAY_DOWNLOAD, "[EPO]delay download")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_QEPO_GET_INDEX, "[EPO]qepo_get_download_index")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_INDEX, "[EPO]index = %d")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_DOWNLOAD_SUCCESS_HANDLE, "[EPO]epo_3_day_after_download_success_handle")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_NEXT_CHUNK, "[EPO]download next chunk")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_FINISH, "[EPO]download finish")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_QEPO_DOWNLOAD_SUCESS_HANDLE, "[EPO]epo_qepo_after_download_success_handle")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_QEPO_DOWNLOAD, "[EPO]epo_qepo_download, state:%d")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_DELETE_ALL, "[EPO]epo_delete_all")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_TRY_3_DAY_EPO_AIDING, "[EPO]epo_try_3day_epo_aiding")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_AIDING_FAIL, "[EPO]aiding fail")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_TRY_QEPO_AIDING, "[EPO]epo_try_qepo_aiding")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_FILE_OPEN_FAIL, "[EPO]file open fail")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_EPO_AIDING, "[EPO]epo_aiding")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_EPO_AIDING_INTERNAL, "[EPO]epo start aiding")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_EPO_INIT, "[EPO]epo_init")
   TRC_MSG(GPS_TRC_EPO_DOWNLOAD_CURR_SEG, "[EPO]curr seg gps hours:%d")

#endif

    // GPSAdaptor_AGPS
    TRC_MSG(GPSADAPOOR_AGPS_SET_STATE, "[AGPS_ADAPTOR]:set state %d->%d\n")
	TRC_MSG(GPSADAPOOR_AGPS_SEND_CMD, "[AGPS_ADAPTOR]:send cmd %d\n")
	TRC_MSG(GPSADAPOOR_AGPS_SEND_START_REQ, "[AGPS_ADAPTOR]:send start req\n")
	TRC_MSG(GPSADAPOOR_AGPS_RECEIVE_ACTIVATED_STATUS, "[AGPS_ADAPTOR]:receive activated status\n")
	TRC_MSG(GPSADAPOOR_AGPS_GET_MCCMNC, "[AGPS_ADAPTOR]:get mccmnc %s\n")
	TRC_MSG(GPSADAPOOR_AGPS_ALLOC_FAILURE, "[AGPS_ADAPTOR]:send start req alloc memory failure")
	TRC_MSG(GPSADAPOOR_AGPS_NO_NETWORK, "[AGPS_ADAPTOR]:no network")
	TRC_MSG(GPSADAPOOR_AGPS_STATE_MACHINE_WRONG, "[AGPS_ADAPTOR]:state machine wrong:%d")
	TRC_MSG(GPSADAPOOR_AGPS_SEND_STOP_REQ, "[AGPS_ADAPTOR]:send stop req\n")
	TRC_MSG(GPSADAPOOR_AGPS_SEND_ERR_RESPONSE, "[AGPS_ADAPTOR]:send stop req\n")
	TRC_MSG(GPSADAPOOR_AGPS_GET_PLMN_FAIL, "[AGPS_ADAPTOR]:get plmn fail\n")
	TRC_MSG(GPSADAPOOR_AGPS_GET_AGPS_UP_SETTING, "[AGPS_ADAPTOR]:get up setting(%d,%d,%d,%d)\n")
	TRC_MSG(GPSADAPOOR_AGPS_GET_AGPS_PROFILE_SETTING, "[AGPS_ADAPTOR]:get profile(%s,%d)\n")
	TRC_MSG(GPSADAPOOR_AGPS_GET_AGPS_CONFIG_SETTING, "[AGPS_ADAPTOR]:get profile(%s,%d,%d)\n")
	TRC_MSG(GPSADAPOOR_AGPS_GET_AGPS_ONOFF, "[AGPS_ADAPTOR]:agps=%d\n")
	TRC_MSG(GPSADAPTOR_AGPS_UART_P_CALLBACK, "[AGPS_ADAPTOR]:parser_p_info=%d\n")
   /***************TRC MSG FOR GPS END ********************/
END_TRACE_MAP(MOD_GPS)

#if defined(__GPS_ADAPTOR_SUPPORT__)
BEGIN_TRACE_MAP(MOD_GPSADAPTOR)

   /***************TRC MSG FOR GPS BEGIN ********************/
   /* --------------------------------------------------------------- */
   /* -----------------------   COMMON USE ID    -------------------- */
   /* --------------------------------------------------------------- */

    /* --------------------------------------------------------------- */
    /* ----------------------- MODULE NAME:GPS_UART------------------- */
    /* --------------------------------------------------------------- */
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD_TEST, "[epodownload]\n")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD_SET_FLAG, "[epodownload]:set flag %08x--->%08x\n")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD_RESET_FLAG, "[epodownload]:reset flag %08x--->%08x\n")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD_DECIDE_DELAY, "[epodownload] delay=%dmin\n")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD_NVRAM_DATE, "[epodownload]:nvram %04d-%02d-%02d-%02d-%02d-%02d\n")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD_LOCAL_DATE, "[epodownload]:local %04d-%02d-%02d-%02d-%02d-%02d\n")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD_NVRAM_READ_FAILURE, "[epodownload]:read fail\n")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD_NVRAM_READ_SUCCESS, "[epodownload]:read success\n")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD_NVRAM_WRITE_FAILURE, "[epodownload]:write fail\n")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD_NVRAM_WRITE_SUCCESS, "[epodownload]:write success\n")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD_NVRAM_SAVE_SUCCESS, "[epodownload]:save localtime to nvram success\n")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD_NVRAM_SAVE_FAILURE, "[epodownload]:save localtime to nvram fail\n")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD_TIMEOUT_TYPE, "[epodownload]:timeout type=%MTIMER_HANDLER_TYPE\n")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD_ERR_HANDLER_STATUS, "[epodownload]:retey count=%d,errcode=%MEPODOWNLOAD_ERR_CODE,flag=%08x\n")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD_ERR_HANDLER_RUNNING, "[epodownload]:err handler is running.\n")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD_CHECKSUM_SUCCESS, "[epodownload]:checksum success\n")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD_CHECKSUM_FAILURE, "[epodownload]:checksum failure\n")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD__GET_NORMAL_DRIVER, "[epodownload]:normal driver=%c\n")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD__GET_REMOVABLE_DRIVER, "[epodownload]:removable driver=%c\n")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD_DISK_FREE_SPACE, "[epodownload]:Free space=%dK.\n")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD_EPOFILE_SIZE, "[epodownload]:EPO.DAT size=%dK.\n")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD_FILE_WRITE_STATUS, "[epodownload]:len=%d ,write file len=%d, result=%d\n")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD_EPOFILE_PROPERTY_EPOFILE_SIZE, "[epodownload]:epofile sieze :%d\n")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD_EPOFILE_PROPERTY_NOT_FIND_CHECKSUM, "[epodownload]:can't find check sum\n")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD_DNS_SERVER_IP, "[epodownload]:server addr:%d.%d.%d.%d\n")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD_RECEIVE_STATUS, "[epodownload]:receive data len=%d, buf_len=%d, sum=%d\n")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD_RECEIVE_NO_DATA, "[epodownload]:no data!!!\n")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD_SUMMARY_BEFORE_EPOFILE, "[epodownload]:before epofile , recieve len=%d")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD_BEGIN, "[epodownload]:EPO download begin.\n")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD_SELECT_DAYS, "[epodownload]:select %d days epofile.\n")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD_CLOSE_EPOFILE, "[epodownload]:close epofile.\n")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD_SOCKET_ALREADY_RELEASED, "[epodownload]:socket ID has already released.\n")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD_SOCKET_RELEASED, "[epodownload]:socket ID=%d is released.\n")
    TRC_MSG(GPSADAPOOR_EPODOWNLOAD_IGNORE_CLOSED_EVENT, "[epodownload]:notify close event is ignored.\n")
    
    TRC_MSG(GPSADAPOOR_START_TIMER, "[GPS_ADAPTOR]:start timerid=%Mgps_adaptor_timer_enum,delay=%ds\n")
    TRC_MSG(GPSADAPOOR_STOP_TIMER, "[GPS_ADAPTOR]:stop timerid=%Mgps_adaptor_timer_enum\n")
    TRC_MSG(GPSADAPOOR_ALREADY_STOP_TIMER, "[GPS_ADAPTOR]:has already stopped timerid=%Mgps_adaptor_timer_enum\n")

   /***************TRC MSG FOR GPS END ********************/
END_TRACE_MAP(MOD_GPSADAPTOR)
#endif /* __GPS_ADAPTOR_SUPPORT__*/

#endif /* __GPS_SUPPORT__*/
#endif /* __GPS_TRC_H__ */
