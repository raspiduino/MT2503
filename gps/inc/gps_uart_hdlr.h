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
*  gps_uart_hdlr.h
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  GPS related function define in GPS task, such as GPS uart and NMEA parser
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
*******************************************************************************/
#ifndef __GPS_UART_HDLR_H__
#define __GPS_UART_HDLR_H__

#include "fs_type.h"
#include "gps_struct.h"
#include "gps_common.h"
#include "gps2lcsp_struct.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "stack_config.h"
#include "app_ltlcom.h"
#include "stack_msgs.h"

#if defined(__GPS_SUPPORT__)||defined(__BT_GPS_SUPPORT__)
/*config*/
#define GPS_AREA_EVENTS_SUPPORT_NUM         (5)


/*defination*/
#define GPS_UART_EARTH_RADIUS               (6378137)
#define PI                                  (3.1415926)

#define GPS_UART_OPEN_FINISH_EVENT          (0x0001)
#define GPS_UART_READ_FINISH_EVENT          (0x0002)
#define GPS_UART_WRITE_FINISH_EVENT         (0x0004)
#define GPS_UART_CLOSE_FINISH_EVENT         (0x0008)
#ifdef __GPS_ADAPTOR_SUPPORT__
#define GPS_UART_RING_BUF_SIZE              (16*1024)  
#else
#define GPS_UART_RING_BUF_SIZE              (8*1024)  
#endif
#define GPS_UART_RING_MIN_PER_IND           (100)
#define GPS_UART_RING_EXP_INTERVAL          (100)
#define GPS_UART_RING_SENTENCE_NUM          (30)

#define GPS_UART_RAW_BUF_SIZE               (30)
#define GPS_UART_MAX_MOD_PER_PORT           (3)
#define GPS_DUMMY_PORT                      (0xff)
#define GPS_UART_CHECK_VER_INTERVAL         (3000)
#define GPS_UART_CHECK_CHIP_ID_INTERVAL     (3100)
#define GPS_UART_ENABLE_DEBUG_INFO_INTERVAL (3200)
#define GPS_UART_AUTHENTICATION_INTERVAL    (3000)
#define GPS_UART_MODIS_UART_SM_INTERVAL     (800)
#define GPS_TRACE_MAX_LENGTH                 100
#define GPS_UART_SWITCH_MODE_INTERVAL       (1000)

#define GPS_DUMMY_HANDLE                0xFF
#define GPS_NMEA_BUFFER_SIZE            256
#define GPS_PARSER_MAX_SUB_FEILD        16
#define GPS_PARSER_GGA_FEILDS           14
#define GPS_PARSER_GLL_FEILDS           7
#define GPS_PARSER_GSA_FEILDS           18
#define GPS_PARSER_GSV_FEILDS           20
#define GPS_PARSER_RMC_FEILDS           13
#define GPS_PARSER_VTG_FEILDS           9
#define GPS_PARSER_ACC_FEILDS           1

#define GPS_PARSER_SENTECE_BUF_SIZE     GPS_NMEA_BUFFER_SIZE
#define GPS_PARSER_SENTECE_BUF_NUM      5
#define GPS_PARSER_P_RSP_MAX            20
#define GPS_PARSER_POS_FEILDS           20
#define GPS_PARSER_MEAS_FEILDS          30
#define GPS_CMD_MAX_FEILDS              64  //the longest cmd is PMTKALM 
#if defined(__L1_GPS_AUTO_TIMING_SYNC_SUPPORT__) || defined(__L1_GPS_REF_TIME_SUPPORT__)  
#define GPS_PARSER_FTIME_FEILDS         10
#define GPS_PARSER_FSYNC_MEAS_FEILDS    5
#define GPS_PARSER_FSYNC_ENABLE_SLEEP_FEILDS         5
#endif

#define GPS_PARSER_P_CMD_LENGTH         3
#define GPS_PARSER_P_CMD_DATA_START     9
#define GPS_PARSER_P_CMD_010            10          /*GPS System boot up finished*/
#define GPS_PARSER_P_CMD_705            705         /*GPS Version*/
#define GPS_PARSER_P_CMD_704            704         /*GPS Version*/
#define GPS_PARSER_P_CMD_714            714         /*Clock Drift Information*/

#define GPS_PARSER_P_CMD_HEAD           "$PMTK%03d"

#define GPS_PARSER_P_CMD_RESPONSE                   001
#define GPS_PARSER_P_CMD_MODE_SWITCH                290
/*Assist data part*/
#define GPS_PARSER_P_CMD_REQUEST_ASSIST             730
/*Assist data part*/
#define GPS_PARSER_P_CMD_ASSIST_NULL                0
#define GPS_PARSER_P_CMD_ASSIST_RTI                 717
#define GPS_PARSER_P_CMD_ASSIST_ACQUISITION         718
#define GPS_PARSER_P_CMD_ASSIST_ALMANAC             711
#define GPS_PARSER_P_CMD_ASSIST_UTC                 716
#define GPS_PARSER_P_CMD_ASSIST_IONOSPHERE          715
#define GPS_PARSER_P_CMD_ASSIST_NAVIGATION_MODEL    710
#define GPS_PARSER_P_CMD_ASSIST_DGPS_CORRECTION     720
#define GPS_PARSER_P_CMD_ASSIST_REF_LOCATION        713
#define GPS_PARSER_P_CMD_ASSIST_REF_TIME            712
#define GPS_PARSER_P_CMD_ASSIST_TOW_ASSIST          725

#define GPS_PARSER_P_CMD_POS                        731
#define GPS_PARSER_P_CMD_LOC_ERROR                  733
#define GPS_PARSER_P_CMD_MEAS                       732
#define GPS_PARSER_P_CMD_MEAS_REQ                   485
/*GPS MP test command */
#define GPS_PARSER_P_CMD_TEST_FINISHED              812 /* MP test finished */
#define GPS_PARSER_P_CMD_TEST_ACQ                   813 /* result of TEST_ACQ*/
#define GPS_PARSER_P_CMD_TEST_BITSYNC               814 /* result of TEST_BITSYNC */
#define GPS_PARSER_P_CMD_TEST_SIGNAL                815 /* result of TEST_SIGNAL */
#define GPS_PARSER_P_CMD_TEST_FIXTRL                500 /* MP test mode fix control nmea update(Hz) */
#define GPS_PARSER_P_CMD_TEST_VERSION               GPS_PARSER_P_CMD_705 /* fw version */
#define GPS_PARSER_P_CMD_CW_TEST_RESULT             817 /* CW test result */

#define GPS_PARSER_P_CMD_VALID_OK                   3

#if defined(__L1_GPS_AUTO_TIMING_SYNC_SUPPORT__) || defined(__L1_GPS_REF_TIME_SUPPORT__)  
/* Fine Time Assistance */
#define GPS_PARSER_P_CMD_ASSIST_FINE_TIME           719
/* Get Fine Time Info */
#define GPS_PARSER_P_CMD_FTIME                      734
#define GPS_PARSER_P_CMD_FTIME_ERROR                735
#define GPS_PARSER_P_CMD_FRAME_SYNC_MEAS_REQ        736
#define GPS_PARSER_P_CMD_FRAME_SYNC_ENABLE_SLEEP    738
#define GPS_PARSER_P_CMD_FTIME_REQ                  484
#endif

#define GPS_PARSER_P_CMD_VALID_OK                   3

/* [Klocwork] GPS_NMEA_SEND_BUFFER_SIZE: 300 -> 500 */
#define GPS_NMEA_SEND_BUFFER_SIZE               500
#define GPS_NMEA_SEND_TEMP_BUFFER_SIZE          50
#define GPS_NMEA_SEND_NAVIGATION_W_SIZE         24
#define GPS_NMEA_SEND_ALMANAC_W_SIZE            8


#define GPS_PARSER_P_MAX_SUB_FEILD      16
#define GPS_PARSER_P_RELEASE_FEILDS     5
/* Klockwork issue fix 20120712
 * A pair stands for one SAT (SatIDX, IODEx) and NSAT is 16 max, plus 13 front fields of 730, total is 45
 * (original only consider number of prefix as 5, i.e. total 37).
 * But in general, GPS will only see about 8~9 SATs while acquisition
 */
#define GPS_PARSER_P_730_FEILDS         (GPS_ASSIST_DATA_SUB_ITEMS_FEILDS * 2 + 13)
/*add for meta MP test */
#define GPS_MP_TEST_BITMAP_MASK             0x0f

#define GPS_PARSER_P_TEST_ACQ_FEILDS        2
#define GPS_PARSER_P_TEST_BITSYNC_FEILDS    2
#define GPS_PARSER_P_TEST_SIGNAL_FEILDS     7
#define GPS_PARSER_P_TEST_RELEASE_FEILDS    2
#define GPS_PARSER_P_TEST_FIX_CONTRL_FEILDS 5
#define GPS_PARSER_P_CW_TEST_RESULT_FEILDS  3


#define GPS_RET_CODE_ERROR              (-1)
#define GPS_RET_CODE_OK                 0

#define GPS_NMEA_BITMAP_GGA     (1<<0)
#define GPS_NMEA_BITMAP_GSA     (1<<1)
#define GPS_NMEA_BITMAP_GSV     (1<<2)
#define GPS_NMEA_BITMAP_RMC     (1<<3)
#define GPS_NMEA_BITMAP_VTG     (1<<4)
#define GPS_NMEA_BITMAP_GLL     (1<<5)
#define GPS_NMEA_BITMAP_GLGSV    (1<<6)
#define GPS_NMEA_BITMAP_GLGSA    (1<<7)
#define GPS_NMEA_BITMAP_GAGSA    (1<<8)
#define GPS_NMEA_BITMAP_GAGSV    (1<<9)
#define GPS_NMEA_BITMAP_BDGSA    (1<<10)
#define GPS_NMEA_BITMAP_BDGSV    (1<<11)
#define GPS_NMEA_BITMAP_ACCURACY     (1<<12)


/*Version*/
typedef struct
{
    kal_char    version[GPS_PARSER_P_VERSION_MAX];
    kal_uint32  number;
} gps_p_release_struct;


typedef struct
{
    kal_char    command[GPS_PARSER_P_RSP_MAX];
    kal_uint16  command_num;
    kal_char    result;
} gps_p_response_struct;


typedef struct
{
    gps_p_release_struct    release;
} gps_p_info_struct;


typedef enum
{
    GPS_NMEA_STR = 0,
    GPS_NMEA_DATA,
    GPS_NMEA_CHECKSUM1,
    GPS_NMEA_CHECKSUM2,
    GPS_NMEA_END_CR,
    GPS_NMEA_END_LF
} gps_parser_state;

typedef enum
{
    GPS_NEXT_JOB_IDLE = 0,
    GPS_NEXT_JOB_CLEAR_NVRAM,
    GPS_NEXT_JOB_CLOSE_PORT,
    GPS_NEXT_JOB_END
} gps_next_job_enum;



typedef struct
{
    gps_parser_state         state;
    gps_common_nmea_info_struct nmea;              /*parser work buffer*/
    gps_common_nmea_info_struct nmea_to_app;       /*store parsered data to app*/
    gps_common_p_info_struct    p_info;       /*store parsered data to app*/
    kal_mutexid              mutex;
    kal_uint8                sentence_buffer_index;
    kal_char                 sentence_buffer[GPS_PARSER_SENTECE_BUF_NUM][GPS_PARSER_SENTECE_BUF_SIZE];
    kal_bool                 is_enabled;
    kal_bool                 sentence_enabled;
    kal_bool                 is_init_GPS_RTC;
    kal_bool                 is_gps_fixed;
    kal_bool                 is_gps_time_syn;
    kal_bool                 is_cw_test_enabled;
    kal_bool                 is_cnr_test_enabled;
    kal_bool                 is_fix_test_enabled;
    kal_uint32               cnr_test_sv_id;
} gps_parser_context_struct;

//GPS AREA EVENT
typedef struct
{
    gps_area_event_add_req_struct event;
    kal_bool    is_valid;
    module_type module;
} gps_area_events_single_struct;

typedef struct
{
    gps_area_events_single_struct events[GPS_AREA_EVENTS_SUPPORT_NUM];
} gps_area_events_context_struct;

typedef struct
{
    kal_bool    catcher_logging;
    kal_bool    file_logging;
    kal_bool    agent_logging;
    kal_bool    debug_info;
    FS_HANDLE           file_handle;                    /*store the handle that logging should use*/
    FS_HANDLE           debug_info_file_handle;         /*store the debug info that logging should use*/
    kal_uint32          file_pre_allocate;              /*store the number pre-allocated*/
    kal_uint32          debug_info_file_pre_allocate;   /*store the number pre-allocated*/
    kal_uint8           port;                           /*store the port nubmer that logging should use*/
    kal_bool            debug_info_file_pre_allocate_failed;      /*store the status pre-allocated*/
    kal_bool            file_pre_allocate_failed;                 /*store the status pre-allocated*/
    kal_bool            power_saving;
    kal_bool            hot_still;
    kal_bool            hot_still_debug;
    kal_uint32          file_write_count;            
    kal_uint32          debug_info_file_write_count; 
} gps_logging_ctx_struct;


typedef struct
{
    kal_bool        is_need_indicate;
    kal_bool        is_read_flag;       /* assist to detect ring buffer overflow */
    kal_uint32      read_p;
    kal_uint32      lost_byte_count;  
} gps_uart_ring_buffer_read_struct;

typedef struct
{
    gps_uart_ring_buffer_read_struct        read[GPS_UART_MAX_MOD_PER_PORT];
    kal_char                                buffer[GPS_UART_RING_BUF_SIZE];
    kal_uint32                              write_p;
    kal_mutexid                             mutex;
} gps_uart_ring_buffer_struct;

typedef struct
{
    kal_bool        is_need_indicate;
    kal_uint32      sentence_start_p[GPS_UART_RING_SENTENCE_NUM];
    kal_uint16      sentence_length[GPS_UART_RING_SENTENCE_NUM];
    kal_uint8       read_index;
    module_type     mod_id;
} gps_uart_ring_sentence_buffer_read_struct;

typedef struct
{
    gps_uart_ring_sentence_buffer_read_struct        read[GPS_UART_MAX_MOD_PER_PORT];
    kal_char                                buffer[GPS_UART_RING_BUF_SIZE];
    kal_uint32                              write_p;
    kal_uint32                              write_index;
    kal_mutexid                             mutex;
} gps_uart_ring_sentence_buffer_struct;

typedef struct
{
    gps_uart_ring_buffer_struct        ring;
    gps_uart_ring_sentence_buffer_struct    nmea_ring;
    module_type     mod_id[GPS_UART_MAX_MOD_PER_PORT];
    kal_char        buffer[GPS_UART_RAW_BUF_SIZE];
    kal_bool        is_raw_data_mode[GPS_UART_MAX_MOD_PER_PORT];
    kal_bool        is_location_mode[GPS_UART_MAX_MOD_PER_PORT];
    kal_bool        is_need_location_ind[GPS_UART_MAX_MOD_PER_PORT];
    kal_bool        is_debug_raw_data_mode[GPS_UART_MAX_MOD_PER_PORT];
    kal_uint16       nmea_to_app_bit[GPS_UART_MAX_MOD_PER_PORT];   /*store parsered data btimap to app*/
    kal_bool        is_lct_with_qop_mode[GPS_UART_MAX_MOD_PER_PORT];
#ifdef __GPS_ADAPTOR_SUPPORT__
    kal_bool	   is_nmea_data_mode[GPS_UART_MAX_MOD_PER_PORT];
#endif
    kal_uint16      port_num;
    
    kal_int16       last_switch_mode;       /*mb ma*/
    kal_int16       org_gps_mode;       /*mb ma*/
    kal_int16       curr_gps_mode;      /*mb ma*/
    kal_int16       prefer_gps_mode;    /*mb ma*/
    kal_int16       query_gps_mode;    /*mb ma*/
    module_type     request_mod_id[GPS_UART_MAX_MOD_PER_PORT];
    kal_uint8       request_count[GPS_UART_MAX_MOD_PER_PORT];
} gps_port_cntx_struct;


typedef struct 
{
    kal_uint32 v_drv_counter;
    kal_char   v_drv_buf[GPS_NMEA_BUFFER_SIZE];
    gps_parser_context_struct   parser;
    gps_logging_ctx_struct      logging;
    gps_port_cntx_struct        port;
    gps_area_events_context_struct  area_events;
    kal_bool                    is_timer_started;
    kal_bool                    is_start_ok;
    gps_next_job_enum           next_job;
    gps_p_response_struct       response;
    kal_eventgrpid              event_id; //for GPS modem load power ON/OFF GPS
}gps_uart_context_struct;


extern kal_bool     gps_msg_hdlr(ilm_struct *ilm_ptr);
extern void         gps_set_work_port(kal_uint8 port);
extern void         gps_enable_parser(void);
extern kal_bool     gps_disable_parser(void);
extern kal_bool     gps_is_parser_enabled(void);

extern kal_int16 gps_uart_read_data_nmea(module_type module_id, kal_uint8 port, kal_uint8 *buffer, kal_uint16 length,kal_uint32 *readed);
extern kal_int16 gps_uart_read_data_dbg(kal_uint8 port, kal_uint8 *buffer, kal_uint16 length,kal_uint32 *readed);
extern void gps_logging_catcher_enable(void);
extern void gps_logging_catcher_disable(void);
extern void gps_logging_agent_enable(void);
extern void gps_logging_agent_disable(void);
extern void gps_nmea_eng_sentence_disable(void);
extern void gps_nmea_eng_sentence_enable(void);
extern void gps_debug_info_enable(void);
extern void gps_debug_info_disable(void);
extern void gps_mnl_debug_info_enable(void);
extern void gps_mnl_debug_info_disable(void);
extern void gps_power_saving_mode_enable(void);
extern void gps_power_saving_mode_disable(void);
extern void gps_logging_file_enable(void);
extern void gps_logging_file_disable(void);
extern void gps_uart_enable_authentication(void);

extern kal_char* gps_p_get_fireware_version(void);
    
extern void gps_send_msg(msg_type msg_id,module_type dst_mod, void* local_param_ptr);
extern kal_uint32 gps_uart_write_internal(kal_int16 port,kal_uint8* data_p,kal_uint32 length);
extern kal_bool gps_find_sub_field(
                const kal_char* str,
                kal_int32 num_cmms,
                kal_char sub[][GPS_PARSER_MAX_SUB_FEILD],
                kal_uint8 *found_fields);
extern kal_bool gps_is_integer(const kal_char *str);
extern kal_bool gps_is_float(const kal_char *str);
extern kal_bool gps_uart_write_gps_cmd(kal_uint16 port,gps_common_uart_cmd_type_enum cmd,void *param);
extern void gps_nmea_get_gsv_from_buffer(gps_common_nmea_gsv_struct* gsv);
extern kal_uint16 gps_get_nmea_location(kal_uint8 port,gps_common_nmea_info_struct *nmea_ptr);
extern kal_bool gps_p_response_parser(const kal_char* str, gps_p_response_struct* data);
extern kal_bool gps_uart_is_mode_ready(void);
extern kal_int16 gps_get_work_mode(void);
extern void gps_uart_restore2prefer_mode(void);
extern kal_uint32 gps_uart_clear_on_broad_gps_nvram(void);
extern kal_bool gps_is_start_finished(void);
extern void gps_uart_reset_query_mode(void);
extern void gps_set_hotstill_shutdown_mode(kal_bool shutdown);
extern void gps_set_hotstill_debug_mode(kal_bool enable);
extern void gps_uart_state_init(void);
extern void gps_uart_state_reset(void);
extern int register_agps_uart(char *name, int len);

#ifndef __MNL_SUPPORT__
extern void gps_epo_reset(void);
extern void gps_uart_epo_send_assistance_data (void);
#endif

#ifdef UNIT_TEST
extern void gps_uart_ready_to_read_ind(ilm_struct *ilm_ptr);
#endif
#endif /*__GPS_SUPPORT__*/
#endif /*__GPS_UART_HDLR_H__*/


