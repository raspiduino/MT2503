/***********************************************************************
*   This software/firmware and related documentation ("MediaTek Software") 
*   are protected under relevant copyright laws. The information contained 
*   herein is confidential and proprietary to MediaTek Inc. and/or its licensors.
*
*   Without the prior written permission of MediaTek Inc. and/or its licensors, 
*   any reproduction, modification, use or disclosure of MediaTek Software, and 
*   information contained herein, in whole or in part, shall be strictly prohibited.
*
*   MediaTek Inc. (C) [2005]. All rights reserved.
*
*************************************************************************/ 
/*******************************************************************************
 * Filename:
 * ---------
 *  gps_common.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/
#ifndef _GPS_COMMON_H_
#define _GPS_COMMON_H_

#if defined(__GPS_SUPPORT__)||defined(__BT_GPS_SUPPORT__)

/* [Klocwork] GPS_PARSER_P_VERSION_MAX: 32 -> 64 */
#define GPS_PARSER_P_VERSION_MAX        64

#define GPS_NMEA_MAX_SVVIEW             20
#define GL_NMEA_MAX_SVVIEW             20
#define GA_NMEA_MAX_SVVIEW             20
#define GPS_NMEA_MESSAGE_MAX_LENGTH         (100)

/* mdi_datatype.h UART port 7000 */
#define RES_GPS_UART_SUCCEED                            0
#define RES_GPS_UART_ERR_PORT_NUMBER_WRONG              -7002
#define RES_GPS_UART_ERR_PORT_ERR_UNKNOW                -7005
#define RES_GPS_UART_ERR_NO_SLOT                        -7007

/*Data type for callback function of NMEA data or parserred data*/
typedef enum
{
    GPS_PARSER_RAW_DATA = 0,    /*Raw data of NMEA*/
    GPS_PARSER_NMEA_GGA,        /*Data structure of GGA info*/
    GPS_PARSER_NMEA_GLL,        /*Data structure of GLL info*/
    GPS_PARSER_NMEA_GSA,        /*Data structure of GSA info*/
    GPS_PARSER_NMEA_GSV,        /*Data structure of GSV info*/
    GPS_PARSER_NMEA_RMC,        /*Data structure of RMC info*/
    GPS_PARSER_NMEA_VTG,        /*Data structure of VTG info*/
    GPS_PARSER_NMEA_SENTENCE,   
    GPS_UART_EVENT_VPORT_LOST,  /*Virtual port is lost, maybe bluetooth connection is break(not support current)*/
    GPS_SHOW_AGPS_ICON,
    GPS_HIDE_AGPS_ICON,
    GPS_PARSER_NMEA_GLGSV,        /*Data structure of GLGSV info*/
	GPS_PARSER_NMEA_GLGSA,        /*Data structure of GLGSA info*/
    GPS_PARSER_NMEA_GAGSA,        /*Data structure of GAGSA info*/
    GPS_PARSER_NMEA_GAGSV,        /*Data structure of GAGSV info*/   
    GPS_PARSER_NMEA_BDGSA,        /*Data structure of BDGSA info*/
    GPS_PARSER_NMEA_BDGSV,        /*Data structure of BDGSV info*/ 
    GPS_PARSER_NMEA_ACC,
    GPS_PARSER_NMEA_END,
    GPS_PARSER_MA_STATUS = 255
} gps_common_parser_info_enum;


/*Enum of GPS command*/
typedef enum
{
    GPS_UART_GPS_WARM_START = 0,        /*Let GPS do warm start*/
    GPS_UART_GPS_HOT_START,             /*Let GPS do hot start*/
    GPS_UART_GPS_COLD_START,            /*Let GPS do cold start*/
    GPS_UART_GPS_VERSION,
    GPS_UART_GPS_ENABLE_DEBUG_INFO,    
    GPS_UART_GPS_SWITCH_MODE_MA,
    GPS_UART_GPS_SWITCH_MODE_MB,
    GPS_UART_GPS_SWITCH_MODE_NORMAL,
    GPS_UART_GPS_QUERY_POS,
    GPS_UART_GPS_QUERY_MEAS,
    GPS_UART_GPS_CLEAR_NVRAM,           /*Clear GPS NVRAM*/
    GPS_UART_GPS_AGPS_START,            /*Clear GPS data*/
    GPS_UART_GPS_SLEEP,                 /*Let GPS chip goto sleep mode*/
    GPS_UART_GPS_STOP,                  /*Let GPS chip stop*/
    GPS_UART_GPS_WAKE_UP,               /*Let GPS chip wake up from sleep mode*/
    GPS_UART_GPS_DUMMY = -1
} gps_common_uart_cmd_type_enum;

/*Enum of GPS work mode*/
typedef enum
{
    GPS_UART_MODE_RAW_DATA = 0,         /*Just need raw data*/
    GPS_UART_MODE_LOCATION,             /*Just need location*/
    GPS_UART_MODE_LOCATION_WITH_QOP,     /*Need AGPS data with Qop*/
    GPS_UART_MODE_DEBUG_RAW_DATA,       /*by pass mode*/
#ifdef __GPS_ADAPTOR_SUPPORT__
    GPS_UART_MODE_NMEA_DATA,             /*Just for iot devcie*/
#endif
} gps_common_uart_work_mode_enum;

typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint32 length; 
    kal_uint8  data[GPS_NMEA_MESSAGE_MAX_LENGTH]; 
}gps_common_uart_write_req_struct;

typedef struct
{            
    kal_int8      hour;
    kal_int8      minute;
    kal_int8      second;
    kal_int16     millisecond;
} gps_common_nmea_utc_time_struct;

typedef struct
{            
    kal_int8      year;
    kal_int8      month;
    kal_int8      day;
} gps_common_nmea_utc_date_struct;

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
    gps_common_nmea_utc_time_struct    utc_time;       /*Time (UTC)*/
    kal_int8      north_south;      /*north or south*/
    kal_int8      east_west;        /*east or west*/
    kal_int8      quality;          /*GPS Quality Indicator*/
} gps_common_nmea_gga_struct;


 /*GPGSA -- GNSS DOP and Active Satellites*/
typedef struct 
{           
    float   pdop;       /*PDOP in meters*/
    float   hdop;       /*HDOP in meters*/
    float   vdop;       /*VDOP in meters*/
    kal_uint16     sate_id[12]; /*ID of satellites*/
    kal_int8      op_mode;      /*Selection mode: A=auto M=manual*/
    kal_int8      fix_mode;     /*Mode*/
	kal_int8      system_id;  /*1:GP;2:GL;3:GA */
} gps_common_nmea_gsa_struct;


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
    }       rsv[GPS_NMEA_MAX_SVVIEW];
	kal_int16     signal_id;            /*0:all signals;1:G1 C/A;2:G1 P......*/
} gps_common_nmea_gsv_struct;


/*GPRMC -- Recommended Minimum Specific GNSS Data*/
typedef struct
{            
    double   latitude;          /*latitude*/
    double   longitude;         /*longitude*/
    float   ground_speed;       /*Speed over ground, knots*/
    float   trace_degree;       /*Track mode degrees,north is 0*/
    float   magnetic;
    gps_common_nmea_utc_time_struct      utc_time; /*UTC time*/
    gps_common_nmea_utc_date_struct      utc_date; /*UTC date*/
    kal_int8      status;       /*Status, V = Navigation receiver warning*/
    kal_int8      north_south;  /*N or S*/
    kal_int8      east_west;    /*E or W*/
    kal_int8      magnetic_e_w; /*Magnetic E or W*/
    kal_int8      cmode;        /*Mode*/
	kal_int8      nav_status; /* navigational   status*/
} gps_common_nmea_rmc_struct;


/*GPGLL -- Geographic Position - Latitude/Longitude*/
typedef struct
{            
    double  latitude;               /*latitude*/ 
    double  longitude;              /*longitude*/
    gps_common_nmea_utc_time_struct      utc_time;     /*UTC time*/
    kal_int8      north_south;      /*N or S*/
    kal_int8      east_west;        /*E or W*/
    kal_int8      status;           /*Status A - Data Valid, V - Data Invalid*/
    kal_int8      mode;             /*mode*/
} gps_common_nmea_gll_struct;


/*GPVTG -- VTG Data*/
typedef struct
{
    float   true_heading;   /*Track Degrees*/
    float   mag_heading;    /*Magnetic Track Degrees*/
    float   hspeed_knot;    /*Speed Knots*/
    float   hspeed_km;      /*Speed Kilometers Per Hour*/
    kal_int8      mode;     /*Mode*/
} gps_common_nmea_vtg_struct;

/*GPACCURACY-- ACCURACY Data*/
typedef struct
{
    float accuracy;    /*accuracy*/
}gps_common_nmea_accuracy_struct;

typedef struct
{
    gps_common_nmea_gga_struct    gga; //for gps system only 
    gps_common_nmea_gsa_struct    gsa; //for gps system only
    gps_common_nmea_gsv_struct    gsv; //for gps system only
    gps_common_nmea_rmc_struct    rmc; //for gps/Multi_GNSS system both
    gps_common_nmea_vtg_struct    vtg; //for gps system only
    gps_common_nmea_gll_struct    gll; //for gps system only
    gps_common_nmea_gsa_struct    glgsa; //for glonass system only
    gps_common_nmea_gsv_struct    glgsv; //for glonass/Multi_GNSS system both
    gps_common_nmea_gsa_struct    gagsa; //for galileo system only
    gps_common_nmea_gsv_struct    gagsv; //for galileo/Multi_GNSS system both
    gps_common_nmea_gsa_struct    bdgsa; //for BD system only
    gps_common_nmea_gsv_struct    bdgsv; //for BD system only
    gps_common_nmea_accuracy_struct acc;//for  accuracy request
}gps_common_nmea_info_struct;


typedef struct
{
    kal_char    version[GPS_PARSER_P_VERSION_MAX];
    kal_uint32  number;
} gps_common_p_release_struct;

typedef struct
{
    gps_common_p_release_struct    release;
} gps_common_p_info_struct;

typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint16   port;
    kal_char*    buffer;
    kal_uint32   length;
}gps_uart_log_write_struct;

//gps modem common API 
extern void gps_power_on_req(gps_common_uart_work_mode_enum work_mode);
extern void gps_power_off_req(gps_common_uart_work_mode_enum work_mode);
extern kal_uint32 gps_uart_command_write(void* buffer, kal_uint32 length, kal_uint32 *write);
extern kal_uint8 gps_uart_get_nmea_location(gps_common_nmea_info_struct *nmea_ptr);

#endif 
#endif /* _GPS_COMMON_H_ */ 




