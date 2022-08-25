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
 *  mdi_gps.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GPS related interface hand file, such as GPS uart and NMEA parser
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
#include "MMI_features.h"

#ifndef _MDI_GPSUART_H_
#define _MDI_GPSUART_H_

#if defined(__GPS_SUPPORT__)||defined(__BT_GPS_SUPPORT__)
#include "stack_config.h"
#include "MMIDataType.h"
#include "app_ltlcom.h"
#include "fs_type.h"
#include "kal_release.h"
#include "mdi_datatype.h"
#include "fs_type.h"
#include "mmi_frm_events_gprot.h"


#define MDI_GPS_UART_PORT_MAX               3
#define MDI_GPS_UART_APP_PER_PORT_MAX       5
#define MDI_GPS_DUMMY_HANDLE                0xFF
#define MDI_GPS_DUMMY_PORT                  0xFF

#define MDI_GPS_NMEA_CATCHER_LOGGING_FLAG       (1<<0)
#define MDI_GPS_NMEA_FILE_LOGGING_FLAG          (1<<1)
#define MDI_GPS_NMEA_AGENT_LOGGING_FLAG         (1<<2)
#define MDI_GPS_NMEA_DEBUG_INFO_FLAG            (1<<3)
#define MDI_GPS_NMEA_POWER_SAVING_FLAG          (1<<4)
#define MDI_GPS_NMEA_HOTSTILL_FLAG              (1<<5)
#define MDI_GPS_NMEA_HOTSTILL_DEBUG_FLAG        (1<<6)
#define MDI_GPS_NMEA_LOGGING_DEFAULT_FLAG       (0x01)
#define MDI_GPS_NMEA_MESSAGE_MAX_LENGTH         (100)
#define MDI_GPS_NMEA_FILENAME_LENGTH            (60)
#define MDI_GPS_NMEA_FILE_LOGGING_WRITE_TIME    (20)
#define MDI_GPS_NMEA_FILE_DEBUGINOF_WRITE_TIME  (200)

#define MDI_GPS_RAW_DATA_PER_CB            (256)
#define MDI_GPS_RAW_DATA_PER_EXTEND             (1024*5)

#define MDI_GPS_NMEA_MAX_SVVIEW             20
#define MDI_GPS_NMEA_GL_MAX_SVVIEW          20
#define MDI_GPS_NMEA_GA_MAX_SVVIEW          20
#define MDI_GPS_PARSER_P_VERSION_MAX        32
#define MDI_GPS_OPEN_MODE_ERROR             0


/*Data type for callback function of NMEA data or parserred data*/
typedef enum
{
    MDI_GPS_PARSER_RAW_DATA = 0,    /*Raw data of NMEA*/
    MDI_GPS_PARSER_NMEA_GGA,        /*Data structure of GGA info*/
    MDI_GPS_PARSER_NMEA_GSA,        /*Data structure of GSA info*/
    MDI_GPS_PARSER_NMEA_GSV,        /*Data structure of GSV info*/
    MDI_GPS_PARSER_NMEA_RMC,        /*Data structure of RMC info*/
    MDI_GPS_PARSER_NMEA_VTG,        /*Data structure of VTG info*/
    MDI_GPS_PARSER_NMEA_GLL,        /*Data structure of GLL info*/
    MDI_GPS_PARSER_NMEA_GLGSA,       /*Data structure of GLGSA info*/
    MDI_GPS_PARSER_NMEA_GLGSV,       /*Data structure of GLGSV info*/
    MDI_GPS_PARSER_NMEA_GAGSA,       /*Data structure of GAGSA info*/
    MDI_GPS_PARSER_NMEA_GAGSV,       /*Data structure of GAGSV info*/
    MDI_GPS_PARSER_NMEA_BDGSA,       /*Data structure of BDGSA info*/
    MDI_GPS_PARSER_NMEA_BDGSV,       /*Data structure of BDGSV info*/
    MDI_GPS_PARSER_NMEA_SENTENCE,
    MDI_GPS_UART_EVENT_VPORT_LOST,  /*Virtual port is lost, maybe bluetooth connection is break(not support current)*/
    MDI_GPS_SHOW_AGPS_ICON,
    MDI_GPS_HIDE_AGPS_ICON,
    MDI_GPS_PARSER_NMEA_ACC,        /*Data structure of ACCURACY info*/
    MDI_GPS_PARSER_NMEA_END,
    MDI_GPS_PARSER_MA_STATUS = 255
} mdi_gps_parser_info_enum;


typedef enum
{
    MDI_GPS_PARSER_P_VERSION = 0,
    MDI_GPS_PARSER_P_GPS_MODE_SWITCH_OK,
    MDI_GPS_PARSER_P_SYSTEM_START_OK,
    MDI_GPS_PARSER_P_INTERNAL_VERSION,
    MDI_GPS_PARSER_P_GPS_FIXED,
    MDI_GPS_PARSER_P_GPS_FIXED_AND_TIME_OK,
    MDI_GPS_PARSER_P_END
} mdi_gps_parser_p_info_enum;

/*Enum of GPS work mode*/
typedef enum
{
    MDI_GPS_UART_MODE_RAW_DATA = 0,         /*Just need raw data*/
    MDI_GPS_UART_MODE_LOCATION,             /*Just need location*/
    MDI_GPS_UART_MODE_LOCATION_WITH_QOP     /*Need AGPS data with Qop*/
} mdi_gps_uart_work_mode_enum;

/*Enum of GPS command*/
typedef enum
{
    MDI_GPS_UART_GPS_WARM_START = 0,        /*Let GPS do warm start*/
    MDI_GPS_UART_GPS_HOT_START,             /*Let GPS do hot start*/
    MDI_GPS_UART_GPS_COLD_START,            /*Let GPS do cold start*/
    MDI_GPS_UART_GPS_VERSION,
    MDI_GPS_UART_GPS_ENABLE_DEBUG_INFO,    
    MDI_GPS_UART_GPS_SWITCH_MODE_MA,
    MDI_GPS_UART_GPS_SWITCH_MODE_MB,
    MDI_GPS_UART_GPS_SWITCH_MODE_NORMAL,
    MDI_GPS_UART_GPS_QUERY_POS,
    MDI_GPS_UART_GPS_QUERY_MEAS,
    MDI_GPS_UART_GPS_CLEAR_NVRAM,           /*Clear GPS NVRAM*/
    MDI_GPS_UART_GPS_AGPS_START,            /*Clear GPS data*/
    MDI_GPS_UART_GPS_SLEEP,                 /*Let GPS chip goto sleep mode*/
    MDI_GPS_UART_GPS_STOP,                  /*Let GPS chip stop*/
    MDI_GPS_UART_GPS_WAKE_UP,               /*Let GPS chip wake up from sleep mode*/
    MDI_GPS_UART_GPS_DUMMY = -1
} mdi_gps_uart_cmd_type_enum;

typedef struct
{            
    kal_int8      hour;
    kal_int8      minute;
    kal_int8      second;
    kal_int16     millisecond;
} mdi_gps_nmea_utc_time_struct;

typedef struct
{            
    kal_int8      year;
    kal_int8      month;
    kal_int8      day;
} mdi_gps_nmea_utc_date_struct;

/*GPGGA -- Global Positioning System Fix Data*/
typedef struct
{            
    double  latitude;               /*Latitude South<0  North>0*/
    double  longitude;              /*Longitude West<0 east>0*/
    float   h_precision;            /*Horizontal Dilution of precision*/
    double  altitude;               /*Antenna Altitude above/below mean-sea-level (geoid)*/
    float   unit_of_altitude;       /*Units of antenna altitude, meters*/
    float   geoidal ;               /*Geoidal separation, the difference between the WGS-84 earth*/
    float   unit_of_geoidal;        /*Units of geoidal separation, meters*/
    float   gps_age;                /*Age of differential GPS data, time in seconds since last SC104*/
    kal_uint16    station_id;       /*Differential reference station ID, 0000-1023*/
    kal_uint8     sat_in_view;      /*Number of satellites in use*/
    mdi_gps_nmea_utc_time_struct    utc_time;       /*Time (UTC)*/
    kal_int8      north_south;      /*north or south*/
    kal_int8      east_west;        /*east or west*/
    kal_int8      quality;          /*GPS Quality Indicator*/
} mdi_gps_nmea_gga_struct;


 /*GPGSA -- GNSS DOP and Active Satellites*/
typedef struct 
{           
    float   pdop;       /*PDOP in meters*/
    float   hdop;       /*HDOP in meters*/
    float   vdop;       /*VDOP in meters*/
    kal_uint16     sate_id[12]; /*ID of satellites*/
    kal_int8      op_mode;      /*Selection mode: A=auto M=manual*/
    kal_int8      fix_mode;     /*Mode*/
} mdi_gps_nmea_gsa_struct;


/*GPGSV -- GNSS Satellites in View*/
typedef struct 
{            
    kal_int16     msg_sum;              /*total number of messages*/
    kal_int16     msg_index;            /*message number*/
    kal_int16     sates_in_view;        /*satellites in view*/
    kal_int16     max_snr;              /*Max snr*/
    kal_int16     min_snr;              /*Min snr*/
    kal_int16     num_sv_trk;           /*satellite number*/
    struct
    {
        kal_uint8 sate_id;              /*satellite id*/
        kal_uint8 elevation;            /*elevation in degrees*/
        kal_int16 azimuth;              /*azimuth in degrees to true*/
        kal_uint8 snr;                  /*SNR in dB*/
    }       rsv[MDI_GPS_NMEA_MAX_SVVIEW];
} mdi_gps_nmea_gsv_struct;


/*GPRMC -- Recommended Minimum Specific GNSS Data*/
typedef struct
{            
    double   latitude;          /*latitude*/
    double   longitude;         /*longitude*/
    float   ground_speed;       /*Speed over ground, knots*/
    float   trace_degree;       /*Track mode degrees,north is 0*/
    float   magnetic;
    mdi_gps_nmea_utc_time_struct      utc_time; /*UTC time*/
    mdi_gps_nmea_utc_date_struct      utc_date; /*UTC date*/
    kal_int8      status;       /*Status, V = Navigation receiver warning*/
    kal_int8      north_south;  /*N or S*/
    kal_int8      east_west;    /*E or W*/
    kal_int8      magnetic_e_w; /*Magnetic E or W*/
    kal_int8      cmode;        /*Mode*/
    kal_int8      nav_status;   /*navigational status*/
} mdi_gps_nmea_rmc_struct;


/*GPGLL -- Geographic Position - Latitude/Longitude*/
typedef struct
{            
    double  latitude;               /*latitude*/ 
    double  longitude;              /*longitude*/
    mdi_gps_nmea_utc_time_struct      utc_time;     /*UTC time*/
    kal_int8      north_south;      /*N or S*/
    kal_int8      east_west;        /*E or W*/
    kal_int8      status;           /*Status A - Data Valid, V - Data Invalid*/
    kal_int8      mode;             /*mode*/
} mdi_gps_nmea_gll_struct;


/*GPVTG -- VTG Data*/
typedef struct
{
    float   true_heading;   /*Track Degrees*/
    float   mag_heading;    /*Magnetic Track Degrees*/
    float   hspeed_knot;    /*Speed Knots*/
    float   hspeed_km;      /*Speed Kilometers Per Hour*/
    kal_int8      mode;     /*Mode*/
} mdi_gps_nmea_vtg_struct;


typedef struct
{
    kal_char    version[MDI_GPS_PARSER_P_VERSION_MAX];
    kal_uint32  number;
} mdi_gps_p_release_struct;


typedef struct
{
    mdi_gps_p_release_struct    release;
} mdi_gps_p_info_struct;


typedef struct
{
    module_type     mod_id[MDI_GPS_UART_APP_PER_PORT_MAX];
    void            (*gps_uart_raw_cb[MDI_GPS_UART_APP_PER_PORT_MAX])(mdi_gps_parser_info_enum type, void *buffer, U32 length);           /*uart port number*/
    void            (*gps_uart_lct_cb[MDI_GPS_UART_APP_PER_PORT_MAX])(mdi_gps_parser_info_enum type, void *buffer, U32 length);           /*uart port number*/
    void            (*gps_uart_lct_qop_cb[MDI_GPS_UART_APP_PER_PORT_MAX])(mdi_gps_parser_info_enum type, void *buffer, U32 length);           /*uart port number*/
    S16             port;
    MMI_BOOL        is_opened;
    MMI_BOOL        is_ready_to_write;
    MMI_BOOL        is_data_arrive;
} mdi_gps_uart_handle_struct;


typedef struct 
{
    LOCAL_PARA_HDR
    U32 length; 
    U8  data[MDI_GPS_NMEA_MESSAGE_MAX_LENGTH]; 
}mdi_gps_uart_write_req_struct;


typedef struct 
{
    LOCAL_PARA_HDR
    U32 length; 
    U8  data[MDI_GPS_NMEA_MESSAGE_MAX_LENGTH]; 
}mdi_gps_uart_read_req_struct;


typedef struct
{
    FS_HANDLE           file_handle;            /*store the handle that logging should use*/
    FS_HANDLE           debug_info_file_handle; /*store the debug info that logging should use*/
    U32                 file_pre_allocate;      /*store the number pre-allocated*/
    U32                 debug_info_file_pre_allocate;   /*store the number pre-allocated*/
    U8                  port;                           /*store the port nubmer that logging should use*/
    MMI_BOOL            debug_info_file_pre_allocate_failed;      /*store the number pre-allocated*/
    MMI_BOOL            file_pre_allocate_failed;       /*store the number pre-allocated*/
    MMI_BOOL            catcher_logging;
    MMI_BOOL            file_logging;
    MMI_BOOL            agent_logging;
    MMI_BOOL            debug_info;
    MMI_BOOL            power_saving;
    MMI_BOOL            hot_still;
    MMI_BOOL            hot_still_debug;
    U32                 file_write_count;            
    U32                 debug_info_file_write_count; 
} mdi_gps_logging_ctx_struct;


typedef struct
{
    void (*gga_callback)(mdi_gps_nmea_gga_struct *param);
    void (*gll_callback)(mdi_gps_nmea_gll_struct *param);
    void (*gsa_callback)(mdi_gps_nmea_gsa_struct *param);
    void (*gsv_callback)(mdi_gps_nmea_gsv_struct *param);
    void (*rmc_callback)(mdi_gps_nmea_rmc_struct *param);
    void (*vtg_callback)(mdi_gps_nmea_vtg_struct *param);
    void (*sentence_callback)(const U8 *buffer, U32 length);
    module_type     mod_id;
    U16             port_num;
} mdi_gps_parser_ctx_struct;

    
typedef struct
{
    U32      counter;        /*remember the nmea buffer in bytes*/
    mdi_gps_parser_ctx_struct   parser;
    mdi_gps_logging_ctx_struct  logging;
    mdi_gps_uart_handle_struct  handle[MDI_GPS_UART_PORT_MAX];
    void (*gps_uart_p_callback)(mdi_gps_parser_p_info_enum type);
    void (*gps_uart_p_info_callback)(mdi_gps_parser_p_info_enum type,void *param);
    MMI_BOOL                    is_need_assist_data;
    kal_eventgrpid              event_id;
    kal_mutexid                 mutex;
} mdi_gps_ctx_struct;

/*****************************************************************************              
 * FUNCTION
 *    mdi_gps_uart_open
 * DESCRIPTION
 *  To open gps port, then user can get the nmea data at callback function pass to this function.
 * PARAMETERS
 *  port    :  [IN]  the port number of gps.
 *  mode    :  [IN]  the data format app want get.
 *  gps_uart_event_callback    :  [IN]  application callback function.
 * RETURNS
 *  mdi result code.
 * RETURN VALUES
 *  MDI_RES_MOTION_SUCCEED: success.
 *  MDI_RES_GPS_UART_ERR_NO_SLOT: app open too much times
*****************************************************************************/
MDI_RESULT mdi_gps_uart_open(
    U16 port,
    mdi_gps_uart_work_mode_enum mode,
    void (*gps_uart_event_callback)(mdi_gps_parser_info_enum type, void *buffer, U32 length));

/*****************************************************************************              
 * FUNCTION
 *    mdi_gps_uart_close
 * DESCRIPTION
 *  To close gps port, when last one is close will power of GPS chip automaticly.
 * PARAMETERS
 *  port    :  [IN]  the port number of gps.
 *  mode    :  [IN]  the data format app want get.
 *  gps_uart_event_callback    :  [IN]  application callback function.
 * RETURNS
 *  mdi result code.
 * RETURN VALUES
 *  MDI_RES_MOTION_SUCCEED: success.
*****************************************************************************/
MDI_RESULT mdi_gps_uart_close(
    U16 port,
    mdi_gps_uart_work_mode_enum mode, 
    void (*gps_uart_event_callback)(mdi_gps_parser_info_enum type, void *buffer, U32 length));

/*****************************************************************************              
 * FUNCTION
 *    mdi_get_gps_port
 * DESCRIPTION
 *  Get the port number of gps.
 * PARAMETERS
 *  NULL
 * RETURNS
 *  mdi result code.
 * RETURN VALUES
 *  port number.
*****************************************************************************/
extern S16 mdi_get_gps_port(void);
    
/*****************************************************************************              
 * FUNCTION
 *    mdi_gps_uart_write
 * DESCRIPTION
 *  To write special data to GPS chip, most time should not use.
 * PARAMETERS
 *  port    :  [IN]  the port number of gps.
 *  buffer  :  [IN]  the data app want pass to GPS chip.
 *  length  :  [IN]  the length of data.
 *  write   :  [IN]  the number of char write to chip.
 * RETURNS
 *  mdi result code.
 * RETURN VALUES
 *  MDI_RES_MOTION_SUCCEED: success.
*****************************************************************************/
extern MDI_RESULT   mdi_gps_uart_write(U16 port, void* buffer, U32 length, U32 *write);

/*****************************************************************************              
 * FUNCTION
 *    mdi_gps_uart_cmd
 * DESCRIPTION
 *  To write command to GPS chip, sametime maybe use for application.
 * PARAMETERS
 *  port    :  [IN]  the port number of gps.
 *  cmd     :  [IN]  the command app want pass to GPS chip.
 *  param   :  [IN]  no use current.
 * RETURNS
 *  mdi result code.
 * RETURN VALUES
 *  MDI_RES_MOTION_SUCCEED: success.
*****************************************************************************/
extern MDI_RESULT   mdi_gps_uart_cmd(U16 port, mdi_gps_uart_cmd_type_enum cmd, void *param);

extern MDI_RESULT   mdi_gps_uart_clear_nvram(void);

extern void         mdi_gps_set_work_port(U8 port);
extern void         mdi_gps_enable_parser(void);
extern MMI_BOOL     mdi_gps_disable_parser(void);
extern MMI_BOOL     mdi_gps_is_parser_enabled(void);

extern void         mdi_gps_nmea_set_catcher_logging(MMI_BOOL param);
extern void         mdi_gps_nmea_set_file_logging(MMI_BOOL param);
extern void         mdi_gps_nmea_set_agent_logging(MMI_BOOL param);
extern void         mdi_gps_nmea_set_debug_info(MMI_BOOL param);
extern void         mdi_gps_nmea_set_power_saving(MMI_BOOL param);
extern MMI_BOOL     mdi_gps_nmea_get_catcher_logging(void);
extern MMI_BOOL     mdi_gps_nmea_get_file_logging(void);
extern MMI_BOOL     mdi_gps_nmea_get_agent_logging(void);
extern MMI_BOOL     mdi_gps_nmea_get_debug_info(void);
extern MMI_BOOL     mdi_gps_nmea_get_power_saving(void);

extern MMI_BOOL     mdi_gps_uart_message_dispatcher(void *ilm_ptr);
extern void mdi_gps_eng_disable_sentence(void);
extern void mdi_gps_eng_enable_sentence(void);
extern CHAR* mdi_gps_get_firmware_version(void);
extern void* mdi_gps_register_p_callback(void (*gps_uart_p_callback)(mdi_gps_parser_p_info_enum type));
extern void* mdi_gps_register_p_info_callback(void (*gps_uart_p_info_callback)(mdi_gps_parser_p_info_enum type,void *param));
extern void mdi_gps_uart_callback_app_ind_hdler(module_type module_id, mdi_gps_parser_info_enum type, U16 port, void *buffer, U32 length);
extern void mdi_gps_nmea_set_hotstill_setting(MMI_BOOL param);
extern MMI_BOOL mdi_gps_nmea_get_hotstill_setting(void);
extern void mdi_gps_nmea_set_hotstill_debug_setting(MMI_BOOL param);
extern MMI_BOOL mdi_gps_nmea_get_hotstill_debug_setting(void);

extern MMI_ID_TYPE mdi_gps_get_mdi_error_info(MDI_RESULT error_code, mmi_event_notify_enum* popup_type);

#endif /* __MMI_GPS__ */ 
#endif /* _MDI_GPSUART_H_ */ 




