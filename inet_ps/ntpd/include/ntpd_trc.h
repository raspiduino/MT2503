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
 
/*******************************************************************************
 * Filename:
 * ---------
 *	ntpd_trc.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is trace map definition.
 *
 * Author:
 * -------
 *	
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _NTPD_TRC_H
#define _NTPD_TRC_H


/* In resourcegen, data type in kal_release.h will conflict with others */
#include "kal_trace.h"

#include "stack_config.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "kal_public_api.h"

#define NTPD_TRC_G1_FSM	        TRACE_GROUP_1
#define NTPD_TRC_G2_FD	        TRACE_GROUP_2
#define NTPD_TRC_G2_DATA_TRAN	        TRACE_GROUP_3
#define NTPD_TRC_G2_CMD	        TRACE_GROUP_4
#define MMI_CONN_TRC_G9_NTPD TRACE_GROUP_1

#if defined(__TST_MODULE__)
#define DEBUG_INFORMATION 1
#endif 

#ifdef DEBUG_INFORMATION
    #ifndef __GNUC__
        #define NTPD_TRACE kal_trace
    #else 
      #ifdef WIN32
        #define NTPD_TRACE kal_trace   
      #else
        /* Only target compiler know (...) in the macro */
        #define NTPD_TRACE(...)        
      #endif
    #endif 
#else /* DEBUG_INFORMATION */ 
    #define NTPD_TRACE kal_trace   
#endif /* DEBUG_INFORMATION */ 


#define NTPD_PROMPT_TRACE(TAG,x)                    kal_prompt_trace(TAG,"%s,%d:%s",__FILE__,__LINE__,x)

#ifdef __NTPD_DEBUG_TRC__
#define ntpd_debug_trace  kal_prompt_trace
#else
#define ntpd_debug_trace(...)    
#endif

#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "ntpd_trc_gen.h"
#endif /* TST Trace Defintion */
#endif

BEGIN_TRACE_MAP(MOD_NTPD)

	/*****************************************************************************************************************
	 * main flow trace
	 *****************************************************************************************************************/
TRC_MSG(FUNC_NTPD_NETWORK_INIT, "[NTPD] ntpd_network_init()")
TRC_MSG(FUNC_NTPD_CREATE_MEM, "[NTPD] ntpd_create_mem_pool()")
TRC_MSG(FUNC_NTPD_NOTIFY_APP, "[NTPD] ntpd_notify_app()")
TRC_MSG(FUNC_NTPD_ADD_SERVER, "[NTPD] ntpd_add_server()")
TRC_MSG(FUNC_NTPD_SERVER_SEND, "[NTPD] ntpd_server_send()")
TRC_MSG(FUNC_NTPD_FIND_SERVER, "[NTPD] ntpd_find_server()")
TRC_MSG(FUNC_NTPD_RECV_PROC, "[NTPD] ntpd_recv_proc()")
TRC_MSG(FUNC_NTPD_RECV_PROC_NO, "[NTPD] ntpd_recv_proc: %d")
TRC_MSG(FUNC_NTPD_INPUT, "[NTPD] ntpd_input()")
TRC_MSG(FUNC_NTPD_HDLR_SOC_NOTIFY_IND, "[NTPD] ntpd_hdlr_soc_notify_ind() %d")
TRC_MSG(FUNC_NTPD_HDLR_BEARER_INFO_IND, "[NTPD] ntpd_hdlr_cbm_bearer_info_ind() %d")
TRC_MSG(FUNC_NTPD_START_TIMER, "[NTPD] ntpd_start_timer()")
TRC_MSG(FUNC_NTPD_SEND_PACKET, "[NTPD] ntpd_send_packet()")
TRC_MSG(FUNC_NTP_TRANSMIT_PACKET, "[NTPD] ntp_transmit_packet()")
TRC_MSG(FUNC_NTP_TRANSMIT_PACKET_NO, "[NTPD] ntp_transmit_packet: %d")
TRC_MSG(FUNC_NTPD_HDLR_GET_HOST_BY_NAME_IND, "[NTPD] ntpd_hdlr_get_host_by_name_ind()")
TRC_MSG(FUNC_NTPD_HDLR_GET_HOST_NO, "[NTPD] ntpd_hdlr_get_host_by_name_ind: %d")
TRC_MSG(FUNC_NTPD_GETHOSTBYNAME, "[NTPD] ntpd_gethostbyname()")
TRC_MSG(FUNC_NTPD_GETHOSTBYNAME_NO, "[NTPD] ntpd_gethostbyname: %d")
TRC_MSG(FUNC_NTPD_CREATE_SOCKET, "[NTPD] ntpd_create_socket()")
TRC_MSG(FUNC_NTPD_SOCKET_BIND, "[NTPD] ntpd_socket_bind()")
TRC_MSG(FUNC_NTPD_SOCKET_BIND_NO, "[NTPD] ntpd_socket_bind: %d")
TRC_MSG(FUNC_NTPD_OPEN, "[NTPD] ntpd_open()")
TRC_MSG(FUNC_NTPD_OPEN_NO, "[NTPD] ntpd_open: %d")
TRC_MSG(FUNC_NTPD_SYNC, "[NTPD] ntpd_sync()")
TRC_MSG(FUNC_NTPD_SYNC_NO, "[NTPD] ntpd_sync: %d")
TRC_MSG(FUNC_NTPD_SERVER_SYNC, "[NTPD] ntpd_server_sync()")
TRC_MSG(FUNC_NTPD_SERVER_SYNC_NO, "[NTPD] ntpd_sync: %d")    
TRC_MSG(FUNC_NTPD_SYNC_ABORT, "[NTPD] ntpd_sync_abort()")
TRC_MSG(FUNC_NTPD_CLOSE, "[NTPD] ntpd_close()")
TRC_MSG(NTPD_ENTER_CLOCK_FILTER, "[NTPD] ntpd_clock_filter(), refid = [%u], next = [%u]")
TRC_MSG(NTPD_CLOCK_FILTER_OFFSET, "[NTPD] ntpd_clock_filter(), offset.i = [%d], offset.f = [%d]")
TRC_MSG(NTPD_PEER_DISPERSION,"[NTPD-PS] peer->dispersion = [%u]")
TRC_MSG(NTPD_REACH_NUM,"[NTPD-PS] reach is [%u]")
TRC_MSG(NTPD_ENTER_CLOCK_INTERSECTION, "[NTPD] ntpd_clock_intersection_selection()")
TRC_MSG(NTPD_CLOCK_SELECT_OFFSET, "[NTPD] ntpd_clock_select(), offset.i = [%d], offset.f = [%d]")
TRC_MSG(NTPD_CLOCK_INTERSECTION_BOUNDARY, "[NTPD] ntpd_clock_intersection_selection(), bottom = [%d], top = [%d]")
TRC_MSG(NTPD_CLOCK_INTERSECTION_NO_SERVER, "[NTPD] ntpd_clock_intersection_selection(), no server!")
TRC_MSG(NTPD_ENTER_CLOCK_CLUSTER_SELECT, "[NTPD] ntpd_clock_clustering_selection()")
TRC_MSG(NTPD_CLOCK_CLUSTER_SELECT_NO_SERVER, "[NTPD] ntpd_clock_clustering_selection(), no server!")
TRC_MSG(NTPD_ENTER_CLOCK_SLECT, "[NTPD] ntpd_clock_select()")
TRC_MSG(NTPD_SELECT_SYNC_SERVER, "[NTPD] ntpd_clock_clustering_selection(), ref_id = [%u]")
TRC_MSG(NTPD_RECV_TIMESTAMP_ORG, "[NTPD] ntpd_recv_proc, org.i = [%d], org.f = [%d]")
TRC_MSG(NTPD_RECV_TIMESTAMP_REC, "[NTPD] ntpd_recv_proc, recv.i = [%d], recv.f = [%d]")
TRC_MSG(NTPD_RECV_TIMESTAMP_SORG, "[NTPD] ntpd_recv_proc, sorg.i = [%d], sorg.f = [%d]")
TRC_MSG(NTPD_RECV_TIMESTAMP_DEST, "[NTPD] ntpd_recv_proc, reach.i = [%d], reach.f = [%d]")

TRC_MSG(SRV_NTP_INIT,                   "[NTP SRV] srv_ntp_init(), start/done: %d")
TRC_MSG(SRV_NTP_CONFIG_INIT,            "[NTP SRV] srv_ntp_config_init(), ret: %d")
TRC_MSG(SRV_NTP_SYS_DRIVE_INIT,         "[NTP SRV] srv_ntp_sys_drive_init(), drive: %c")
TRC_MSG(SRV_NTP_APP_ID_INIT,            "[NTP SRV] srv_ntp_app_id_init(), app_id: %d")
TRC_MSG(SRV_NTP_AUTO_SYNC_TIMER_START,  "[NTP SRV] srv_ntp_auto_sync_timer_start()")
TRC_MSG(SRV_NTP_AUTO_SYNC_RESULT_PROC,  "[NTP SRV] srv_ntp_auto_sync_result_proc(), result: %d, offset: %d")
TRC_MSG(SRV_NTP_AUTO_SYNC_TIMER_PROC,   "[NTP SRV] srv_ntp_auto_sync_timer_proc()")
TRC_MSG(SRV_NTP_CONFIG_RESET,           "[NTP SRV] srv_ntp_config_reset(), sim num: %d, dtcnt 1:%X, 2:%X, 3:%X, 4:%X")
TRC_MSG(SRV_NTP_CONFIG_READ_WRITE,      "[NTP SRV] srv_ntp_config_read_write(), fs_type: %d, ret: %d")
TRC_MSG(SRV_NTP_AVAILABILITY_SET,       "[NTP SRV] srv_ntp_availability_set(), is_available: %d, ret: %d")
TRC_MSG(SRV_NTP_DATA_ACCT_SET,          "[NTP SRV] srv_ntp_data_acct_set(), data_acct: %d, sim :%d, ret: %d")
TRC_MSG(SRV_NTP_UPDATE_TIME_TO_PHONE,   "[NTP SRV] srv_ntp_update_time_to_phone(), Date:%04d/%02d/%02d %02d:%02d:%02d")
TRC_MSG(SRV_NTP_SYNC_CALLBACK,          "[NTP SRV] srv_ntp_sync_callback(), result: %d, offset: %d")
TRC_MSG(SRV_NTP_SYNC,                   "[NTP SRV] srv_ntp_sync(), ret: %d, line: %d")
TRC_MSG(SRV_NTP_EVT_HDLR,               "[NTP SRV] srv_ntp_evt_hdlr(), line: %d")

END_TRACE_MAP(MOD_NTPD)

#endif	/* _NTPD_TRC_H */

