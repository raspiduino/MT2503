/***********************************************************************
*   This software/firmware and related documentation ("MediaTek Software") 
*   are protected under relevant copyright laws. The information contained 
*   herein is confidential and proprietary to MediaTek Inc. and/or its licensors.
*
*   Without the prior written permission of MediaTek Inc. and/or its licensors, 
*   any reproduction, modification, use or disclosure of MediaTek Software, and 
*   information contained herein, in whole or in part, shall be strictly prohibited.
*
*   MediaTek Inc. (C) [2008]. All rights reserved.
*
*************************************************************************/ 
/*****************************************************************************
 *
 * Filename:
 * ---------
 *   mtk_gps_type.h
 *
 * Description:
 * ------------
 *   Data types used by MTK navigation library
 *
 ****************************************************************************/

#ifndef MTK_GPS_TYPE_H
#define MTK_GPS_TYPE_H

#ifdef __cplusplus
  extern "C" {
#endif
#include <time.h>
#ifdef __GPS_MT3326__
    #define MTK_GPS_SV_MAX_NUM   16 
#else  
    #define MTK_GPS_SV_MAX_NUM   32 
#endif
#define MTK_GPS_SV_MAX_PRN      32
#define MTK_QZS_SV_MAX_PRN      5 // QZSS PRN : 193~197
#define MTK_GLEO_SV_MAX_NUM     53  // Galileo SV number, should be >= MGLEOID
#define MTK_GLON_SV_MAX_NUM     24  // Glonass SV number, should be >= MGLONID
#define MTK_BEDO_SV_MAX_NUM     37  // Beidou SV number, should be >= MBEDOID
#define MTK_GPS_ENABLE_DEBUG_MSG (0x01)

/*******************************************************************************
 * Type Definitions
 *******************************************************************************/
typedef unsigned char           mtk_uint8;
typedef signed char             mtk_int8;

typedef unsigned short int      mtk_uint16;
typedef signed short int        mtk_int16;

typedef unsigned int            mtk_uint32;
typedef signed int              mtk_int32;

typedef float                   mtk_r4;
typedef double                  mtk_r8;

#if ( defined(__ARMCC_VERSION) && (__ARMCC_VERSION < 200000 ) ) 
// for ADS1.x
#elif ( defined(__ARMCC_VERSION) && (__ARMCC_VERSION < 400000 ) ) 
// for RVCT2.x or RVCT3.x
#else
#pragma pack(4)
#endif

//*****************************************************************************
// User System Configurations
//*****************************************************************************
typedef enum
{
    HOST_USER_CONFIG_SYS_1 = 1, // user configuration in system operation
    HOST_USER_CONFIG_SYS_2 = 2,  // user configuration in GPS operation
    /*the following is use for 3336 or furture chip */
    HOST_USER_CONFIG_SYS_3 = 3,  // user configuration in Anti-Jamming Debug 
    HOST_USER_CONFIG_SYS_4 = 4,  //  user configuration for aiding data to NVRAM  
    HOST_USER_CONFIG_SYS_5 = 5,  //  user configuration for aiding almanac data to NVRAM 
    HOST_USER_CONFIG_SYS_6 = 6,  //  user configuration for aiding eph data to NVRAM 
    HOST_USER_CONFIG_SYS_7 = 7,  //  user configuration for aiding position data to NVRAM    
    HOST_USER_CONFIG_SYS_8 = 8,  //  user configuration for aiding time data to NVRAM       
    HOST_USER_CONFIG_SYS_9 = 9,  //  user configuration for clean ehp data from NVRAM     
    HOST_USER_CONFIG_SYS_10 = 10,  //  user configuration for clean alman data from NVRAM     
    HOST_USER_CONFIG_SYS_11 = 11,  //  user configuration for chn test     
    HOST_USER_CONFIG_SYS_12 = 12,  //  user configuration for jammer test     
    HOST_USER_CONFIG_SYS_13 = 13,  //  user configuration for phase test    
    HOST_USER_CONFIG_SYS_14 = 14,  //  user configuration for phase test    
    HOST_USER_CONFIG_SYS_15 = 15,  //  user configuration for time_change_notify    
    HOST_USER_CONFIG_SYS_16 = 16,  //  user configuration for time_update_notify     
    HOST_USER_CONFIG_SYS_17 = 17,  //  user configuration for debug_config 
    HOST_USER_CONFIG_SYS_18 = 18,  //  user configuration for update NVfile immedate
    HOST_USER_CONFIG_SYS_19 = 19,  //  user configuration for setting tcxo mode
    HOST_USER_CONFIG_SYS_END  //  user configuration for aiding almanac data to NVRAM 
}mtk_user_system_config;

#define USER_SYS_1_ENABLE_DEBUG ( 1 << 0)
#define USER_SYS_2_TRIGGER_PPS ( 1 << 0)

//*****************************************************************************
// User System Stauts
//*****************************************************************************
typedef enum
{
    USER_SYS_ANT_STATUS = 1
}mtk_system_status;
#define MTK_SYS_ANT_STATUS_AOK ( 1 << 0)
#define MTK_SYS_ANT_STATUS_ASHORT ( 1 << 1)



typedef enum
{
  MTK_GPS_FALSE = 0,
  MTK_GPS_TRUE = 1
} mtk_bool;

typedef enum
{
  MTK_GPS_START_DEFAULT = 0,
  MTK_GPS_START_HOT,
  MTK_GPS_START_WARM,
  MTK_GPS_START_COLD,
  MTK_GPS_START_FULL,
  MTK_GPS_START_BATTERY,
  MTK_GPS_START_AGPS
} mtk_gps_start_type;

typedef enum
{
  MTK_GPS_START_RESULT_ERROR = 0,
  MTK_GPS_START_RESULT_OK
} mtk_gps_start_result;

typedef enum
{
  MTK_GPS_MSG_FIX_READY,
  MTK_GPS_MSG_DEBUG_READY,
  MTK_GPS_MSG_CONFIG_READY,
  MTK_GPS_MSG_TEST_STATUS_READY,
  MTK_GPS_MSG_BUFFER_ENOUGH,
  MTK_GPS_MSG_AGPS_RESPONSE,
  MTK_GPS_MSG_PMTK_RESPONSE,
  MTK_GPS_MSG_FIX_PROHIBITED,
  MTK_GPS_MSG_ASSIST_READY,
  MTK_GPS_MSG_MNL_START,
  MTK_GPS_MSG_MNL_INIT_FAIL,
  MTK_GPS_MSG_MNL_BITMAP_UPDATE
} mtk_gps_notification_type;

typedef enum
{
  MTK_GPS_FIX_Q_INVALID = 0,
  MTK_GPS_FIX_Q_GPS = 1,
  MTK_GPS_FIX_Q_DGPS = 2,
  MTK_GPS_FIX_Q_EST = 6
} mtk_gps_fix_quality;

typedef enum
{
  MTK_GPS_FIX_TYPE_INVALID = 1,
  MTK_GPS_FIX_TYPE_2D = 2,
  MTK_GPS_FIX_TYPE_3D = 3
} mtk_gps_fix_type;

typedef enum
{
  MTK_DGPS_MODE_NONE = 0,
  MTK_DGPS_MODE_RTCM = 1,
  MTK_DGPS_MODE_SBAS = 2,
  MTK_DGPS_MODE_AUTO = 3
} mtk_gps_dgps_mode;

typedef enum
{
  MTK_AGPS_MODE_NONE = 1,
  MTK_AGPS_MODE_SUPL = 2,
  MTK_AGPS_MODE_EPO  = 4,
  MTK_AGPS_MODE_BEE  = 8,
  MTK_AGPS_MODE_AUTO = 16
} mtk_gps_agps_mode;

// Thread definition
typedef enum
{
    MTK_MOD_NIL = 0,
    MTK_MOD_MNL,
    MTK_MOD_DSPIN,
    MTK_MOD_PMTKIN,
    MTK_MOD_AGENT,
    MTK_MOD_BEE_GEN,
    MTK_MOD_DISPATCHER,
    MTK_MOD_RTCM,    
    MTK_MOD_END_LIST
} mtk_gps_module;

// API from Dispatcher to Agent
typedef enum
{
    MTK_AGPS_MSG_EPO = 0,
    MTK_AGPS_MSG_BEE,
    MTK_AGPS_MSG_SUPL,
    MTK_AGPS_MSG_SUPL_PMTK,
    MTK_AGPS_MSG_PROFILE,
    MTK_AGPS_MSG_SUPL_TERMINATE,  //dispatcher send terminate to indicate SUPL stop
    MTK_AGPS_MSG_REQ_NI,          //request AGPS aiding from dispatcher    
    MTK_AGPS_MSG_REQ,             //request AGPS aiding from mnl
    MTK_AGPS_MSG_TERMINATE,
    MTK_AGPS_MSG_END_LIST
} mtk_agps_agent_msg_type;

// Callback from Agent to Dispatcher
typedef enum
{
    MTK_AGPS_CB_SUPL_PMTK = 0,
#ifndef  __GPS_MT3332__
    MTK_AGPS_CB_SUPL_SI_REQ,
#else
    MTK_AGPS_CB_ASSIST_REQ,
#endif
    MTK_AGPS_CB_SUPL_NI_REQ,
    MTK_AGPS_CB_END_LIST
} mtk_agps_cb_msg_type;

// AGPS feature on/off
typedef enum
{
    MTK_AGPS_FEATURE_OFF = 0,
    MTK_AGPS_FEATURE_ON = 1
} mtk_agps_func_onoff;

typedef struct
{
  mtk_uint8 EPO_enabled;
  mtk_uint8 BEE_enabled;
  mtk_uint8 SUPL_enabled;
  mtk_uint8 SUPLSI_enabled;
  mtk_uint8 EPO_priority;
  mtk_uint8 BEE_priority;
  mtk_uint8 SUPL_priority;
} mtk_agps_user_profile;

typedef struct
{
  mtk_uint16    type;           /* message ID */
  mtk_uint16    length;         /* length of 'data' */
  char          data[1];        /* message content */
} mtk_gps_msg;

typedef struct
{
  mtk_uint16    srcMod;
  mtk_uint16    dstMod;
  mtk_uint16    type;           /* message ID */
  mtk_uint16    length;         /* length of 'data' */
  char          data[1];        /* message content */
} mtk_agps_agent_msg;

typedef enum
{
  MTK_BEE_DISABLE = 0,
  MTK_BEE_ENABLE = 1
} mtk_gps_bee_en;

typedef enum
{
  MTK_BRDC_DISABLE = 0,
  MTK_BRDC_ENABLE = 1
} mtk_gps_brdc_en;

typedef enum
{
  MTK_DBG_DISABLE = 0,
  MTK_DBG_ERR,
  MTK_DBG_WRN,
  MTK_DBG_INFO,
  MTK_DBG_END
} mtk_gps_dbg_level;


typedef enum
{
  MDBG_BOOT = 0,
  MDBG_TIME,
  MDBG_COMM,
  MDBG_MEM,
  MDBG_MSG,
  MDBG_STORE,
  MDBG_AL,
  MDBG_GPS,
  MDBG_AGPS,
#ifndef __GPS_MT3326__
  MDBG_FS,
#endif
  MDBG_ALL,
  MDBG_TYPE_END
} mtk_gps_dbg_type;

typedef enum
{
  MTK_QZSS_DISABLE = 0,
  MTK_QZSS_ENABLE = 1
} mtk_qzss_search_mode;
typedef enum
{
  MTK_NO_SPEED_FILTERING = 0,
  MTK_SPEED_FILTERING_0_POINT_2 = 1,
  MTK_SPEED_FILTERING_0_POINT_4 = 2,
  MTK_SPEED_FILTERING_0_POINT_6 = 3,
  MTK_SPEED_FILTERING_0_POINT_8 = 4,
  MTK_SPEED_FILTERING_1_POINT_0 = 5,
  MTK_SPEED_FILTERING_1_POINT_5 = 6,
  MTK_SPEED_FILTERING_2_POINT_0 = 7
} mtk_low_speed_filtering_mode;

typedef struct
{
  mtk_uint16    year;           /* years since 1900 */
  mtk_uint8     month;          /* 0-11 */
  mtk_uint8     mday;           /* 1-31 */
  mtk_uint8     hour;           /* 0-23 */
  mtk_uint8     min;            /* 0-59 */
  mtk_uint8     sec;            /* 0-59 */
  mtk_uint8     pad1;
  mtk_uint16    msec;           /* 0-999 */
  mtk_uint16    pad2;
} mtk_time;

typedef enum
{
  MTK_TCXO_NORMAL,  //normal mode 
  MTK_TCXO_PHONE    //bad mode
} mtk_gps_tcxo_mode;

typedef enum
{
  MTK_AIC_OFF,  //AIC off 
  MTK_AIC_ON    //AIC on
} mtk_gps_aic_mode;

typedef struct
{
  mtk_uint16    version;
  mtk_uint16    size;
  mtk_time      utc_time;
  mtk_int16     leap_second;            /* GPS-UTC time difference */
  mtk_uint16    WeekNo;                 /* GPS week number */
  mtk_uint32    TOW;                    /* GPS time of week (integer part) */
  mtk_uint8     fix_quality;            /* mtk_gps_fix_quality for GPGGA */
  mtk_uint8     fix_type;               /* mtk_gps_fix_type for GPGSA */
  double        clock_drift;            /* clock drift (s/s) */
  double        clock_bias;             /* clock bias (s) */
  double        LLH[4];                 /* LLH[0]: Latitude (degree) */
                                        /* LLH[1]: Longitude (degree) */
                                        /* LLH[2]: Height WGS84 (m) */
                                        /* LLH[3]: Height Mean Sea Level (m) */
  float         gspeed;                 /* 2D ground speed (m/s) */
  float         vspeed;                 /* vertical speed (m/s) */
  float         heading;                /* track angle (deg) */
  float         PDOP, HDOP, VDOP, TDOP; /* dilution of precision */
  float         EPE[3];                 /* estimated position error (m) */
                                        /* EPE[0]: North accuracy */
                                        /* EPE[1]: East accuracy */
                                        /* EPE[2]: vertical accuracy */
  float         EVE[3];                 /* estimated velocity error (m/s) */
                                        /* EVE[0]: North accuracy */
                                        /* EVE[1]: East accuracy */
                                        /* EVE[2]: vertical accuracy */
  float         Pos_2D_Accuracy; // Position Accuracy in Horizontal Direction [m]
  float         Pos_3D_Accuracy; // Position Accuracy in 3-D space [m]
  float         Vel_3D_Accuracy;  // Velocity Accuracy in 3-D space [m]
  float         DGPS_age;               /* time since last DGPS update (s) */
  mtk_uint16    DGPS_station_ID;
  mtk_uint8     DGPS_fix_mode;          /* mtk_gps_dgps_mode: 0(N/A); 1(RTCM); 2(SBAS) */
  mtk_uint8     sv_used_num;            /* for GPGSA */
  mtk_uint8     sv_in_view_num;         /* for GPGSV */
  mtk_uint8     sv_used_prn_list[MTK_GPS_SV_MAX_NUM];
  mtk_uint8     sv_in_view_prn_list[MTK_GPS_SV_MAX_NUM];
  mtk_int8      sv_in_view_elev[MTK_GPS_SV_MAX_NUM];
  mtk_uint16    sv_in_view_azim[MTK_GPS_SV_MAX_NUM];
  mtk_uint8     sv_in_view_snr[MTK_GPS_SV_MAX_NUM];
  mtk_uint8    sv_eph_valid[MTK_GPS_SV_MAX_PRN];  /*  sv ephemeris status 0: no ephemeris, 1: broadcast eph, 2: BEE ephmeris, */
  mtk_uint8    sv_eph_day[MTK_GPS_SV_MAX_PRN]; /* day of BEE  */
  mtk_uint8    fgMulti_GNSS;
} mtk_gps_position;

typedef struct
{ /* index 0~31 represents PRN 1~32, respectively */
  mtk_uint8     health[MTK_GPS_SV_MAX_PRN]; /* nonzero: healthy */
  mtk_uint8     eph[MTK_GPS_SV_MAX_PRN];  /* nonzero: ephemeris available */
  mtk_uint8     alm[MTK_GPS_SV_MAX_PRN];  /* nonzero: almanac available */
  mtk_uint8     dgps[MTK_GPS_SV_MAX_PRN]; /* nonzero: DGPS correction ready */
  mtk_uint8     codelock[MTK_GPS_SV_MAX_PRN]; /* nonzero: code lock */
  mtk_uint8     freqlock[MTK_GPS_SV_MAX_PRN]; /* nonzero: frequency lock */
  mtk_uint8     carrlock[MTK_GPS_SV_MAX_PRN]; /* nonzero: carrier lock */
  /* index 0~4 represents PRN 193~197, respectively */
  mtk_uint8     qzshealth[MTK_QZS_SV_MAX_PRN]; /* nonzero: healthy */
  mtk_uint8     qzseph[MTK_QZS_SV_MAX_PRN];  /* nonzero: ephemeris available */
  mtk_uint8     qzsalm[MTK_QZS_SV_MAX_PRN];  /* nonzero: almanac available */
  mtk_uint8     qzsdgps[MTK_QZS_SV_MAX_PRN]; /* nonzero: DGPS correction ready */
  mtk_uint8     qzscodelock[MTK_QZS_SV_MAX_PRN]; /* nonzero: code lock */
  mtk_uint8     qzsfreqlock[MTK_QZS_SV_MAX_PRN]; /* nonzero: frequency lock */
  mtk_uint8     qzscarrlock[MTK_QZS_SV_MAX_PRN]; /* nonzero: carrier lock */  
} mtk_gps_sv_info;

typedef struct
{ /* GALILEO */
  mtk_uint8     health[MTK_GLEO_SV_MAX_NUM];   /* nonzero: healthy */
  mtk_uint8     eph[MTK_GLEO_SV_MAX_NUM];      /* nonzero: ephemeris available */
  mtk_uint8     alm[MTK_GLEO_SV_MAX_NUM];      /* nonzero: almanac available */
  mtk_uint8     dgps[MTK_GLEO_SV_MAX_NUM];     /* nonzero: DGPS correction ready */
  mtk_uint8     codelock[MTK_GLEO_SV_MAX_NUM]; /* nonzero: code lock */
  mtk_uint8     freqlock[MTK_GLEO_SV_MAX_NUM]; /* nonzero: frequency lock */
  mtk_uint8     carrlock[MTK_GLEO_SV_MAX_NUM]; /* nonzero: carrier lock */
} mtk_gleo_sv_info;

typedef struct
{ /* GLONASS PRN 1~24 represents */
  mtk_uint8     health[MTK_GLON_SV_MAX_NUM];   /* nonzero: healthy */
  mtk_uint8     eph[MTK_GLON_SV_MAX_NUM];      /* nonzero: ephemeris available */
  mtk_uint8     alm[MTK_GLON_SV_MAX_NUM];      /* nonzero: almanac available */
  mtk_uint8     dgps[MTK_GLON_SV_MAX_NUM];     /* nonzero: DGPS correction ready */
  mtk_uint8     codelock[MTK_GLON_SV_MAX_NUM]; /* nonzero: code lock */
  mtk_uint8     freqlock[MTK_GLON_SV_MAX_NUM]; /* nonzero: frequency lock */
  mtk_uint8     carrlock[MTK_GLON_SV_MAX_NUM]; /* nonzero: carrier lock */
} mtk_glon_sv_info;

typedef struct
{ // Beidou
   mtk_uint8     health[MTK_BEDO_SV_MAX_NUM];   /* nonzero: healthy */
   mtk_uint8     eph[MTK_BEDO_SV_MAX_NUM];      /* nonzero: ephemeris available */
   mtk_uint8     alm[MTK_BEDO_SV_MAX_NUM];      /* nonzero: almanac available */
   mtk_uint8     dgps[MTK_BEDO_SV_MAX_NUM];     /* nonzero: DGPS correction ready */
   mtk_uint8     codelock[MTK_BEDO_SV_MAX_NUM]; /* nonzero: code lock */
   mtk_uint8     freqlock[MTK_BEDO_SV_MAX_NUM]; /* nonzero: frequency lock */
   mtk_uint8     carrlock[MTK_BEDO_SV_MAX_NUM]; /* nonzero: carrier lock */
} mtk_bedo_sv_info; 


typedef mtk_int32 (*mtk_gps_callback)(mtk_gps_notification_type msg);


typedef enum
{
  MTK_DATUM_WGS84,
  MTK_DATUM_TOKYO_M,
  MTK_DATUM_TOKYO_A,
  MTK_DATUM_USER_SETTING,
  MTK_DATUM_ADINDAN_BURKINA_FASO,
  MTK_DATUM_ADINDAN_CAMEROON,
  MTK_DATUM_ADINDAN_ETHIOPIA,
  MTK_DATUM_ADINDAN_MALI,
  MTK_DATUM_ADINDAN_MEAN_FOR_ETHIOPIA_SUDAN,
  MTK_DATUM_ADINDAN_SENEGAL,
  MTK_DATUM_ADINDAN_SUDAN,
  MTK_DATUM_AFGOOYE_SOMALIA,
  MTK_DATUM_AIN_EL_ABD1970_BAHRAIN,
  MTK_DATUM_AIN_EL_ABD1970_SAUDI_ARABIA,
  MTK_DATUM_AMERICAN_SAMOA1962_AMERICAN_SAMOA,
  MTK_DATUM_ANNA_1_ASTRO1965_COCOS_ISLAND,
  MTK_DATUM_ANTIGU_ISLAND_ASTRO1943_ANTIGUA,
  MTK_DATUM_ARC1950_BOTSWANA,
  MTK_DATUM_ARC1950_BURUNDI,
  MTK_DATUM_ARC1950_LESOTHO,
  MTK_DATUM_ARC1950_MALAWI,
  MTK_DATUM_ARC1950_MEAN_FOR_BOTSWANA,
  MTK_DATUM_ARC1950_SWAZILAND,
  MTK_DATUM_ARC1950_ZAIRE,
  MTK_DATUM_ARC1950_ZAMBIA,
  MTK_DATUM_ARC1950_ZIMBABWE,
  MTK_DATUM_ARC1960_MEAN_FOR_KENYA_TANZANIA,
  MTK_DATUM_ARC1960_KENYA,
  MTK_DATUM_ARC1960_TAMZAMIA,
  MTK_DATUM_ASCENSION_ISLAND1958_ASCENSION,
  MTK_DATUM_ASTRO_BEACONE1945_IWO_JIMA,
  MTK_DATUM_ASTRO_DOS714_ST_HELENA_ISLAND,
  MTK_DATUM_ASTRO_TERN_ISLAND_FRIG1961_TERN_ISLAND,
  MTK_DATUM_ASTRONOMICAL_STATION1952_MARCUS_ISLAND,
  MTK_DATUM_AUSTRALIAN_GEODETIC1966_AUSTRALIA_TASMANIA,
  MTK_DATUM_AUSTRALIAN_GEODETIC1984_AUSTRALIA_TASMANIA,
  MTK_DATUM_AYABELLE_LIGHTHOUSE_DJIBOUTI,
  MTK_DATUM_BELLEVUE_IGN_EFATE_ERROMANGO_ISLAND,
  MTK_DATUM_BERMUDA1957_BERMUDA,
  MTK_DATUM_BISSAU_GUUINEA_BISSAU,
  MTK_DATUM_BOGOTA_OBSERVAORY_COLOMBIA,
  MTK_DATUM_BUKIT_RIMPAH_INDONESIA,
  MTK_DATUM_CAMP_AREA_ASTRO_ANTARCTICA,
  MTK_DATUM_CAMPO_INCHAUSPE_ARGENTINA,
  MTK_DATUM_CANTON_ASTRO1966_PHOENIX_ISLAND,
  MTK_DATUM_CAPE_SOUTH_AFRICA,
  MTK_DATUM_CAPE_CANAVERAL_BAHAMAS_FLORIDA,
  MTK_DATUM_CARTHAGE_TUNISIA,
  MTK_DATUM_CHATHAM_ISLAND_ASTRO1971_NEW_ZEALAND,
  MTK_DATUM_CHUA_ASTRO_PARAGUAY,
  MTK_DATUM_CORREGO_ALEGRE_BRAZIL,
  MTK_DATUM_DABOLA_GUINEA,
  MTK_DATUM_DECEPTION_ISLAND_DECEPTION_ISLAND_ANTARCTIA,
  MTK_DATUM_DJAKARTA_BATAVIA_INDONESIA_SUMATRA,
  MTK_DATUM_DOS1968_NEW_GEORGIA_ISLAND_GIZO_ISLAND,
  MTK_DATUM_EASTER_ISLAND1967_EASTER_ISLAND,
  MTK_DATUM_ESTONIA_COORDINATE_SYSTEM1937_ESTONIA,
  MTK_DATUM_EUROPEAN1950_CYPRUS,
  MTK_DATUM_EUROPEAN1950_EGYPT,
  MTK_DATUM_EUROPEAN1950_ENGLAND_CHANNEL_ISLANDS_SCOTLAND_SHETLAND_ISLANDS,
  MTK_DATUM_EUROPEAN1950_ENGLAND_IRELAND_SCOTLAND_SHETLAND_ISLANDS,
  MTK_DATUM_EUROPEAN1950_FINLAND_NORWAY,
  MTK_DATUM_EUROPEAN1950_GREECE,
  MTK_DATUM_EUROPEAN1950_IRAN,
  MTK_DATUM_EUROPEAN1950_ITALY_SARDINIA,
  MTK_DATUM_EUROPEAN1950_ITALT_SLCILY,
  MTK_DATUM_EUROPEAN1950_MALTA,
  MTK_DATUM_EUROPEAN1950_MEAN_FOR_AUSTRIA_BELGIUM,//_DENMARK_FINLAND_FRANCE_WGERMANY_GIBRALTAR_GREECE_ITALY_LUXEMBOURG_NETHERLANDS_NORWAY_PORTUGAL_SPAIN_SWEDEN_SWITZERLAND,
  MTK_DATUM_EUROPEAN1950_MEAN_FOR_AUSTRIA_DEBNMARK,//_FRANCE_WGERMANY_NETHERLAND_SWITZERLAND,
  MTK_DATUM_EUROPEAN1950_MEAN_FOR_IRAG_ISRAEL_JORDAN,//_LEBANON_KUWAIT_SAUDI_ARABIA_SYRIA,
  MTK_DATUM_EUROPEAN1950_PORTUGAL_SPAIN,
  MTK_DATUM_EUROPEAN1950_TUNISIA,
  MTK_DATUM_EUROPEAN1979_MEAN_FOR_AUSTRIA_FINLAND_,//NETHERLANDS_NORWAY_SPAIN_SWEDEN_SWITZERLAND,
  MTK_DATUM_FORT_THOMAS1955_NEVIS_ST_KITTS_LEEWARD_ISLANDS,
  MTK_DATUM_GAN1970_REPUBLIC_OF_MALDIVES,
  MTK_DATUM_GEODETIC_DATAUM1970_NEW_ZEALAND,
  MTK_DATUM_GRACIOSA_BASE_SW1948_AZORES_FAIAL_GRACIOSA_PICO_SAO,
  MTK_DATUM_GUAM1963_GUAM,
  MTK_DATUM_GUNUNG_SEGARA_INDONESIA_KALIMANTAN,
  MTK_DATUM_GUX_1_ASTRO_GUADALCANAL_ISLAND,
  MTK_DATUM_HERAT_NORTH_AFGHANISTAN,
  MTK_DATUM_HERMANNSKOGEL_DATUM_CROATIA_SERBIA_BOSNIA_HERZEGOIVNA,
  MTK_DATUM_HJORSEY1955_ICELAND,
  MTK_DATUM_HONGKONG1963_HONGKONG,
  MTK_DATUM_HU_TZU_SHAN_TAIWAN,
  MTK_DATUM_INDIAN_BANGLADESH,
  MTK_DATUM_INDIAN_INDIA_NEPAL,
  MTK_DATUM_INDIAN_PAKISTAN,
  MTK_DATUM_INDIAN1954_THAILAND,
  MTK_DATUM_INDIAN1960_VIETNAM_CON_SON_ISLAND,
  MTK_DATUM_INDIAN1960_VIETNAM_NEAR16N,
  MTK_DATUM_INDIAN1975_THAILAND,
  MTK_DATUM_INDONESIAN1974_INDONESIA,
  MTK_DATUM_IRELAND1965_IRELAND,
  MTK_DATUM_ISTS061_ASTRO1968_SOUTH_GEORGIA_ISLANDS,
  MTK_DATUM_ISTS073_ASTRO1969_DIEGO_GARCIA,
  MTK_DATUM_JOHNSTON_ISLAND1961_JOHNSTON_ISLAND,
  MTK_DATUM_KANDAWALA_SRI_LANKA,
  MTK_DATUM_KERGUELEN_ISLAND1949_KERGUELEN_ISLAND,
  MTK_DATUM_KERTAU1948_WEST_MALAYSIA_SINGAPORE,
  MTK_DATUM_KUSAIE_ASTRO1951_CAROLINE_ISLANDS,
  MTK_DATUM_KOREAN_GEODETIC_SYSTEM_SOUTH_KOREA,
  MTK_DATUM_LC5_ASTRO1961_CAYMAN_BRAC_ISLAND,
  MTK_DATUM_LEIGON_GHANA,
  MTK_DATUM_LIBERIA1964_LIBERIA,
  MTK_DATUM_LUZON_PHILIPPINES_EXCLUDING_MINDANAO,
  MTK_DATUM_LUZON_PHILLIPPINES_MINDANAO,
  MTK_DATUM_MPORALOKO_GABON,
  MTK_DATUM_MAHE1971_MAHE_ISLAND,
  MTK_DATUM_MASSAWA_ETHIOPIA_ERITREA,
  MTK_DATUM_MERCHICH_MOROCCO,
  MTK_DATUM_MIDWAY_ASTRO1961_MIDWAY_ISLANDS,
  MTK_DATUM_MINNA_CAMEROON,
  MTK_DATUM_MINNA_NIGERIA,
  MTK_DATUM_MONTSERRAT_ISLAND_ASTRO1958_MONTSERRAT_LEEWARD_ISLAND,
  MTK_DATUM_NAHRWAN_OMAN_MASIRAH_ISLAND,
  MTK_DATUM_NAHRWAN_SAUDI_ARABIA,
  MTK_DATUM_NAHRWAN_UNITED_ARAB_EMIRATES,
  MTK_DATUM_NAPARIMA_BWI_TRINIDAD_TOBAGO,
  MTK_DATUM_NORTH_AMERICAN1927_ALASKA_EXCLUDING_ALEUTIAN_IDS,
  MTK_DATUM_NORTH_AMERICAN1927_ALASKA_ALEUTIAN_IDS_EAST_OF_180W,
  MTK_DATUM_NORTH_AMERICAN1927_ALASKA_ALEUTIAN_IDS_WEST_OF_180W,
  MTK_DATUM_NORTH_AMERICAN1927_BAHAMAS_EXCEPT_SAN_SALVADOR_ISLANDS,
  MTK_DATUM_NORTH_AMERICAN1927_BAHAMAS_SAN_SALVADOR_ISLANDS,
  MTK_DATUM_NORTH_AMERICAN1927_CANADA_ALBERTA_BRITISH_COLUMBIA,
  MTK_DATUM_NORTH_AMERICAN1927_CANADA_MANITOBA_ONTARIO,
  MTK_DATUM_NORTH_AMERICAN1927_CANADA_NEW_BRUNSWICK_NEWFOUNDLAND_NOVA_SCOTIA_QUBEC,
  MTK_DATUM_NORTH_AMERICAN1927_CANADA_NORTHWEST_TERRITORIES_SASKATCHEWAN,
  MTK_DATUM_NORTH_AMERICAN1927_CANADA_YUKON,
  MTK_DATUM_NORTH_AMERICAN1927_CANAL_ZONE,
  MTK_DATUM_NORTH_AMERICAN1927_CUBA,
  MTK_DATUM_NORTH_AMERICAN1927_GREENLAND_HAYES_PENINSULA,
  MTK_DATUM_NORTH_AMERICAN1927_MEAN_FOR_ANTIGUA_BARBADOS_BARBUDA_CAICOS, // _ISLANDS_CUBA_DOMINICAN_GRAND_CAYMAN_JAMAICA_TURKS_ISLANDS,
  MTK_DATUM_NORTH_AMERICAN1927_MEAN_FOR_BELIZE_COSTA_RICA_SALVADOR_GUATEMALA,//_HONDURAS_NICARAGUA,
  MTK_DATUM_NORTH_AMERICAN1927_MEAN_FOR_CANADA,
  MTK_DATUM_NORTH_AMERICAN1927_MEAN_FOR_CONUS,
  MTK_DATUM_NORTH_AMERICAN1927_MEAN_FOR_CONUS_EAST_OF_MISSISSIPPI_RIVER, //_INCLUDING_LOUISIANA_MISSOURI_MINNESOTA,
  MTK_DATUM_NORTH_AMERICAN1927_MEAN_FOR_CONUS_WEST_OF_MISSISSIPPI_RIVER,//_EXCLUDING_LOUISIANA_MINNESOTA_MISSOURI,
  MTK_DATUM_NORTH_AMERICAN1927_MEXICO,
  MTK_DATUM_NORTH_AMERICAN1983_ALASKA_EXCLUDING_ALEUTIAN_IDS,
  MTK_DATUM_NORTH_AMERICAN1983_ALEUTIAN_IDS,
  MTK_DATUM_NORTH_AMERICAN1983_CANADA,
  MTK_DATUM_NORTH_AMERICAN1983_CONUS,
  MTK_DATUM_NORTH_AMERICAN1983_HAHWII,
  MTK_DATUM_NORTH_AMERICAN1983_MEXICO_CENTRAL_AMERICA,
  MTK_DATUM_NORTH_SAHARA1959_ALGERIA,
  MTK_DATUM_OBSERVATORIO_METEOROLOGICO1939_AZORES_CORVO_FLORES_ISLANDS,
  MTK_DATUM_OLD_EGYPTIAN1907_EGYPT,
  MTK_DATUM_OLD_HAWAIIAN_HAWAII,
  MTK_DATUM_OLD_HAWAIIAN_KAUAI,
  MTK_DATUM_OLD_HAWAIIAN_MAUI,
  MTK_DATUM_OLD_HAWAIIAN_MEAN_FOR_HAWAII_KAUAI_MAUI_OAHU,
  MTK_DATUM_OLD_HAWAIIAN_OAHU,
  MTK_DATUM_OMAN_OMAN,
  MTK_DATUM_ORDNANCE_SURVEY_GREAT_BRITIAN1936_ENGLAND,
  MTK_DATUM_ORDNANCE_SURVEY_GREAT_BRITIAN1936_ENGLAND_ISLE_OF_MAN_WALES,
  MTK_DATUM_ORDNANCE_SURVEY_GREAT_BRITIAN1936_MEAN_FOR_ENGLAND_ISLE_OF_MAN,//_SCOTLAND_SHETLAND_ISLAND_WALES,
  MTK_DATUM_ORDNANCE_SURVEY_GREAT_BRITIAN1936_SCOTLAND_SHETLAND_ISLANDS,
  MTK_DATUM_ORDNANCE_SURVEY_GREAT_BRITIAN1936_WALES,
  MTK_DATUM_PICO_DE_LAS_NIEVES_CANARY_ISLANDS,
  MTK_DATUM_PITCAIRN_ASTRO1967_PITCAIRN_ISLAND,
  MTK_DATUM_POINT58_MEAN_FOR_BURKINA_FASO_NIGER,
  MTK_DATUM_POINTE_NOIRE1948_CONGO,
  MTK_DATUM_PORTO_SANTO1936_PORTO_SANTO_MADERIA_ISLANDS,
  MTK_DATUM_PROVISIONAL_SOUTH_AMERICAN1956_BOLOVIA,
  MTK_DATUM_PROVISIONAL_SOUTH_AMERICAN1956_CHILE_NORTHERN_NEAR_19DS,
  MTK_DATUM_PROVISIONAL_SOUTH_AMERICAN1956_CHILE_SOUTHERN_NEAN_43DS,
  MTK_DATUM_PROVISIONAL_SOUTH_AMERICAN1956_COLOMBIA,
  MTK_DATUM_PROVISIONAL_SOUTH_AMERICAN1956_ECUADOR,
  MTK_DATUM_PROVISIONAL_SOUTH_AMERICAN1956_GUYANA,
  MTK_DATUM_PROVISIONAL_SOUTH_AMERICAN1956_MEAN_FOR_BOLIVIA_CHILE,//_COLOMBIA_ECUADOR_GUYANA_PERU_VENEZUELA,
  MTK_DATUM_PROVISIONAL_SOUTH_AMERICAN1956_PERU,
  MTK_DATUM_PROVISIONAL_SOUTH_AMERICAN1956_VENEZUELA,
  MTK_DATUM_PROVISIONAL_SOUTH_CHILEAN1963_CHILE_NEAR_53DS_HITO_XV3,
  MTK_DATUM_PUERTO_RICO_PUERTO_RICO_VIRGIN_ISLANDS,
  MTK_DATUM_PULKOVO1942_RUSSIA,
  MTK_DATUM_QATAR_NATIONAL_QATAR,
  MTK_DATUM_QORNOQ_GREENLAND_SOUTH,
  MTK_DATUM_REUNION_MASCARENE_ISLAND,
  MTK_DATUM_ROME1940_ITALY_SARDINIA,
  MTK_DATUM_S42_PULKOVO1942_HUNGARY,
  MTK_DATUM_S42_PULKOVO1942_POLAND,
  MTK_DATUM_S42_PULKOVO1942_CZECHOSLAVAKIA,
  MTK_DATUM_S42_PULKOVO1942_LATIVA,
  MTK_DATUM_S42_PULKOVO1942_KAZAKHSTAN,
  MTK_DATUM_S42_PULKOVO1942_ALBANIA,
  MTK_DATUM_S42_PULKOVO1942_ROMANIA,
  MTK_DATUM_SJTSK_CZECHOSLAVAKIA_PRIOR1_JAN1993,
  MTK_DATUM_SANTO_DOS1965_ESPIRITO_SANTO_ISLAND,
  MTK_DATUM_SAO_BRAZ_AZORES_SAO_MIGUEL_SANTA_MARIA_IDS,
  MTK_DATUM_SAPPER_HILL1943_EAST_FALKLAND_ISLAND,
  MTK_DATUM_SCHWARZECK_NAMIBIA,
  MTK_DATUM_SELVAGEM_GRANDE1938_SALVAGE_ISLANDS,
  MTK_DATUM_SIERRA_LEONE1960_SIERRA_LEONE,
  MTK_DATUM_SOUTH_AMERICAN1969_ARGENTINA,
  MTK_DATUM_SOUTH_AMERICAN1969_BOLIVIA,
  MTK_DATUM_SOUTH_AMERICAN1969_BRAZIAL,
  MTK_DATUM_SOUTH_AMERICAN1969_CHILE,
  MTK_DATUM_SOUTH_AMERICAN1969_COLOMBIA,
  MTK_DATUM_SOUTH_AMERICAN1969_ECUADOR,
  MTK_DATUM_SOUTH_AMERICAN1969_ECUADOR_BALTRA_GALAPAGOS,
  MTK_DATUM_SOUTH_AMERICAN1969_GUYANA,
  MTK_DATUM_SOUTH_AMERICAN1969_MEAN_FOR_ARGENTINA_BOLIVIA_BRAZIL,//_CHILE_COLOMBIA_ECUADOR_GUYANA_PARAGUAY_PERU_TRINIDAD_TOBAGO_VENEZUELA,
  MTK_DATUM_SOUTH_AMERICAN1969_PARAGUAY,
  MTK_DATUM_SOUTH_AMERICAN1969_PERU,
  MTK_DATUM_SOUTH_AMERICAN1969_TRINIDAD_TOBAGO,
  MTK_DATUM_SOUTH_AMERICAN1969_VENEZUELA,
  MTK_DATUM_SOUTH_ASIA_SINGAPORE,
  MTK_DATUM_TANANARIVE_OBSERVATORY1925_MADAGASCAR,
  MTK_DATUM_TIMBALAI1948_BRUNEI_E_MALAYSIA_SABAH_SARAWAK,
  MTK_DATUM_TOKYO_JAPAN,
  MTK_DATUM_TOKYO_MEAN_FOR_JAPAN_SOUTH_KOREA_OKINAWA,
  MTK_DATUM_TOKYO_OKINAWA,
  MTK_DATUM_TOKYO_SOUTH_KOREA,
  MTK_DATUM_TRISTAN_ASTRO1968_TRISTAM_DA_CUNHA,
  MTK_DATUM_VITI_LEVU1916_FIJI_VITI_LEVU_ISLAND,
  MTK_DATUM_VOIROL1960_ALGERIA,
  MTK_DATUM_WAKE_ISLAND_ASTRO1952_WAKE_ATOLL,
  MTK_DATUM_WAKE_ENIWETOK1960_MARSHALL_ISLANDS,
  MTK_DATUM_WGS1972_GLOBAL_DEFINITION,
  MTK_DATUM_WGS1984_GLOBAL_DEFINITION,
  MTK_DATUM_YACARE_URUGUAY,
  MTK_DATUM_ZANDERIJ_SURINAME
} mtk_gps_datum;


/************************************************
 * defines for set_param and get_param
 ************************************************/
/*-------- keys --------*/
typedef enum
{
  MTK_PARAM_CMD_TERMINATE,
  MTK_PARAM_CMD_RESET_DSP,
  MTK_PARAM_CMD_RESET_KERNEL,
  MTK_PARAM_CMD_CONFIG,
  MTK_PARAM_CMD_TESTMODE,
  MTK_PARAM_CMD_RESTART,
  MTK_PARAM_DGPS_CONFIG,
  MTK_PARAM_NAV_CONFIG,
  MTK_PARAM_BUF_CONFIG,
  MTK_PARAM_LIB_VERSION,
  MTK_PARAM_LIB_RELEASE_INFO,
  MTK_PARAM_TCXO_SINGLE_CONFIG,
  MTK_PARAM_TCXO_MULTIPLE_CONFIG,
  MTK_PARAM_EPH_PROGRESS_CONFIG,
  MTK_PARAM_EPO_STAGE_CONFIG,
  MTK_PARAM_CMD_STOP,
  MTK_PARAM_CMD_SLEEP,
  MTK_PARAM_CMD_WAKEUP,
  MTK_PARAM_CMD_BLOCK,  
  MTK_PARAM_BEE_CONFIG,
  MTK_PARAM_BRDC_CONFIG,
  MTK_PARAM_FRAME_SYNC_RESP,  
  MTK_PARAM_CMD_CONFIG_EPO_DATA,
  MTK_PARAM_CMD_CONFIG_EPO_TIME,
  MTK_PARAM_CMD_CONFIG_EPO_POS,
  MTK_PARAM_CMD_CLR_CLK_DFT,
  MTK_MSG_EPO_REQ,
  MTK_MSG_EPO_RESP,
  MTK_MSG_BEE_REQ,
  MTK_MSG_BEE_RESP,  
  MTK_MSG_REQ_ASSIST,
  MTK_MSG_AGENT_BEE_REQ,
  MTK_MSG_AGENT_SUPL_REQ,
  MTK_MSG_BEE_IND,
  MTK_MSG_AGPS_MSG_REQ_NI,
  MTK_MSG_AGPS_MSG_SUPL_PMTK,
  MTK_MSG_AGPS_MSG_SUPL_TERMINATE,
  MTK_MSG_AGPS_MSG_PROFILE,  
  MTK_MSG_AGPS_MSG_RESET_SM,  
  MTK_MSG_VTIMER_IND,
  MTK_MSG_AL_CFG,
  MTK_MSG_AL_DEE_CFG,
  MTK_PARAM_SYSTEM_CONFIG,
  MTK_PARAM_SYSTEM_STATUS,
#ifdef __GPS_MT3332__
  MTK_PARAM_CMD_SEARCH_QZSS,
#endif
  MTK_PARAM_CMD_LOW_SPEED_FILTERING,
  MTK_PARAM_NMEA_OUTPUT,
  MTK_PARAM_CMD_RTC_CFG,
  MTK_PARAM_CMD_MNL_INIT,
  MTK_MSG_AGPS_MSG_AGENT_TERMINATE,
  MTK_PARAM_QUERY_AGC
} mtk_gps_param;

/*------- values -------*/
/* MTK_PARAM_CMD_TERMINATE : terminate GPS main thread: no payload */

/* MTK_PARAM_CMD_CONFIG : schedule an event for get/set aiding data or config:
   no payload */

/* MTK_PARAM_CMD_TESTMODE : enter/leave a test mode */
typedef enum
{
  MTK_TESTMODE_OFF = 0,
  MTK_TESTMODE_CHANNEL,
  MTK_TESTMODE_JAMMER,
  MTK_TESTMODE_PHASE,
  MTK_TESTMODE_PER,
  MTK_TESTMODE_TTICK_OVERFLOW,
  MTK_TESTMODE_ENTER_MP,
  MTK_TESTMODE_LEAVE_MP,
  MTK_TESTMODE_CW_MODE
} mtk_gps_testmode;

typedef struct
{
  mtk_gps_testmode test_mode;
  mtk_uint8     svid;
  mtk_uint8     SVid_GLO1;    // SVid_GLO1    :  201 ~214 to represent GLONASS Frequency ID
  mtk_uint8     SVid_GLO2;    // SVid_GLO2    :  for example, GLONASS FreqID = -7 ==> SVid_GLO1 = -7 +208 = 201;
  mtk_uint8     SVid_GLO3;    // SVid_GLO3    :  for example, GLONASS FreqID = 6 ==> SVid_GLO1 = 6 +208 = 214;
  mtk_uint8     SVid_BD;
  mtk_uint32    time;
  mtk_uint8     threshold;
  mtk_uint16    targetCount;
} mtk_param_testmode;

/* MTK_PARAM_CMD_RESTART : trigger restart of GPS main thread and dsp code */
typedef struct
{
  mtk_gps_start_type restart_type;      /* MTK_GPS_START_HOT, MTK_GPS_START_WARM, MTK_GPS_START_COLD, MTK_GPS_START_FULL */
} mtk_param_restart;

/* MTK_PARAM_BEE_CONFIG : configuration of bee */
typedef struct
{
  mtk_gps_bee_en bee_en;      /* MTK_BEE_DISABLE MTK_BEE_ENABLE */
} mtk_param_bee_config;

/* MTK_PARAM_BRDC_CONFIG : configuration of broadcast satellite data */
typedef struct
{
  mtk_gps_brdc_en brdc_en;      /* MTK_BRDC_DISABLE MTK_BRDC_ENABLE */
} mtk_param_brdc_config;

typedef struct
{
    mtk_uint8  ucSVid;
    mtk_uint16 u2Weekno;
    char data[24];
}MTK_AIDING_PARAM_ALMANAC;

typedef struct
{
    mtk_uint8  ucSVid;
    char data[72];
}MTK_AIDING_PARAM_EPHEMERIS;

typedef struct
{
    mtk_uint16 u2Weekno;
    double     Tow;
    float      timeRMS;
}MTK_AIDING_PARAM_TIME;

typedef struct
{
    double LLH[3];
}MTK_AIDING_PARAM_POSITION;

typedef struct
{
    mtk_uint8 SVid;
    mtk_uint8 SVid_GLO1;
    mtk_uint8 SVid_GLO2;
    mtk_uint8 SVid_GLO3;
    mtk_uint8 SVid_BD;
    mtk_int32 action;
}MTK_PARAM_CHN_TEST;

typedef struct
{
    mtk_uint16 mode;
    mtk_uint16 arg;
    mtk_int32 action;
}MTK_PARAM_JAMMER_TEST;

typedef struct
{
    mtk_int32 action;
    mtk_uint32 time;
    mtk_uint8 SVid;
}MTK_PARAM_PHASE_TEST;

typedef struct
{
    mtk_int16 Threshold;
    mtk_uint16 SVid;
    mtk_uint16 TargetCount;
}MTK_PARAM_PER_TEST;

typedef struct
{
    mtk_uint8 fgSyncGpsTime;
    mtk_int32 i4RtcDiff;
}MTK_PARAM_TIME_UPDATE_NOTIFY;

typedef struct
{
    mtk_gps_dbg_type DbgType;
    mtk_gps_dbg_level DbgLevel;
}MTK_PARAM_DEBUG_CONFIG;
/* MTK_PARAM_SYSTEM_CONFIG : configuration of system parameters */
typedef struct
{
  mtk_user_system_config system_config_type;   /* system config type */
  mtk_uint32 system_config_value;              /* set/get system config  value*/
  MTK_AIDING_PARAM_EPHEMERIS param_eph; 
  MTK_AIDING_PARAM_ALMANAC  param_almanac;
  MTK_AIDING_PARAM_POSITION param_position;
  MTK_AIDING_PARAM_TIME     param_time;
  MTK_PARAM_TIME_UPDATE_NOTIFY param_time_update_notify;
  MTK_PARAM_DEBUG_CONFIG param_debug_config;
  MTK_PARAM_CHN_TEST       param_chn_test;
  MTK_PARAM_JAMMER_TEST  param_jam_test;
  MTK_PARAM_PHASE_TEST   param_pha_test;
  MTK_PARAM_PER_TEST     param_per_test;
  mtk_gps_tcxo_mode      param_tcxo_mode; 
  mtk_int32 i4RtcDiff;
} mtk_param_system_config;

/* MTK_PARAM_SYSTEM_STATUS : status of system parameters */
typedef struct
{
  mtk_system_status system_status_type;   /* system status type */
  mtk_uint32 system_status_value;              /* set/get system status value*/
} mtk_param_system_status;

/* MTK_PARAM_DGPS_CONFIG */
typedef struct
{
  mtk_gps_dgps_mode dgps_mode;          /* Off/RTCM/SBAS */
  mtk_uint8     dgps_timeout;           /* DGPS timeout in seconds */
  mtk_bool      sbas_test_mode;         /* TRUE=test; FALSE=integrity */
  mtk_uint8     sbas_prn;               /* 0=automatic; 120-139=specific PRN */
  mtk_bool      full_correction;        /* SBAS data correction mode */
                                        /* TRUE=full [Fast/Long-Term and IONO] */
                                        /* FALSE=partial [Fast/Long-Term or IONO] */
  mtk_bool      select_corr_only;       /* satellite selection mode */
                                        /* TRUE=only SVs with corrections */
                                        /* FALSE=any SVs available */
} mtk_param_dgps_cfg;

/* MTK_PARAM_NAV_CONFIG */
typedef struct
{
  mtk_uint32    fix_interval;           /* fix interval in milliseconds */
                                        /* 1000=>1Hz, 200=>5Hz, 2000=>0.5Hz */
  mtk_gps_datum datum;                  /* datum */
  mtk_int8      elev_mask;              /* elevation angle mask in degree */
} mtk_param_nav_cfg;

/*  MTK_PARAM_BUF_CONFIG */
typedef struct
{
  mtk_uint16    buf_empty_threshold;    /* If the buffer free space reach this value
                                           then it will report to callback once */
  mtk_uint16    buf_empty_size;         /* Buffer free space in bytes, read only */
} mtk_param_buf_cfg;

/*  MTK_PARAM_AL_CONFIG : config always locate */
typedef enum
{
  MTK_AL_TYPE_NORMAL        =  0, // Navigation
  MTK_AL_TYPE_USER_PERIODIC =  1, // User periodic mode
  MTK_AL_TYPE_AUTO_PERIODIC =  9  // Auto periodic mode
} mtk_gps_al_type;

typedef struct
{
  mtk_gps_al_type type;                 /* application type */
  mtk_uint32      u4FirstRunTime;              /* run time for peridic mode, (milli-second) */
  mtk_uint32      u4FirstSlpTime;              /* sleep time for peridic mode, (milli-second)*/
  mtk_uint32      u4SecondRunTime;              /* run time for peridic mode, (milli-second) */
  mtk_uint32      u4SecondSlpTime;              /* sleep time for peridic mode, (milli-second)*/
} mtk_param_al_cfg;

typedef struct
{
  mtk_uint8       u1SV ;                /* SV number for DEE extension start criterion */
  mtk_uint8       u1SNR;              /* SNR threshold for DEE extension start criterion */
  mtk_uint32     u4ExtensionThreshold;     /* Extension time limitation for DEE, (milli-second) */
  mtk_uint32     u4ExtensionGap;              /* Extension gap limitation between neighbor DEE , (milli-second)*/
} mtk_param_al_dee_cfg;

typedef struct
{
  mtk_uint32     u4EPOWORD[18];        /* 18 words [LSB first] of one EPO segment data (total 72 bytes) */
  mtk_uint8      u1SatID;              /* 1~32 */
} mtk_param_epo_data_cfg;

typedef struct 
{
  mtk_uint16      u2YEAR ;             /* > 2000 */
  mtk_uint8       u1MONTH;             /* 1~12 */
  mtk_uint8       u1DAY;               /* 1~31*/
  mtk_uint8       u1HOUR;              /* 0~23*/
  mtk_uint8       u1MIN;               /* 0~59*/ 
  mtk_uint8       u1SEC;               /* 0~59*/ 
} mtk_param_epo_time_cfg;

typedef struct 
{
  mtk_r8           dfLAT;              /* > -90 and <90 (degree)*/
  mtk_r8           dfLON;              /* > -180 and <180 (degree)*/
  mtk_r8           dfALT;              /* (m) */ 
  mtk_uint16     u2YEAR;               /* > 2000 */
  mtk_uint8       u1MONTH;             /* 1~12 */
  mtk_uint8       u1DAY;               /* 1~31*/
  mtk_uint8       u1HOUR;              /* 0~23*/
  mtk_uint8       u1MIN;               /* 0~59*/ 
  mtk_uint8       u1SEC;               /* 0~59*/ 
} mtk_param_epo_pos_cfg;

typedef struct
{
  mtk_r4         r4TcxoOffest;        /*  TCXO offest frequency (Hz)*/
  mtk_uint8      u1SatID;              /* 1~32 */
} mtk_param_tcxo_cfg;

typedef struct
{
  mtk_r4         r4EphProgress[MTK_GPS_SV_MAX_PRN];        /* The current Eph Progress (0~1)*/
} mtk_param_eph_progress_cfg;

typedef struct
{
  mtk_uint32     u4EpoStage;              /* The invalid/valid Epo Stage in bit map format(0/1)*/
} mtk_param_epo_stage_cfg; 

typedef enum
{
  MTK_GPS_FS_RESULT_INIT = 0,           /* FS request initial value  */
  MTK_GPS_FS_RESULT_ERR,                /* FS request error and clear naram's data  */
  MTK_GPS_FS_RESULT_ERR_NOT_CLR,        /* FS request error but don't clear nvram's data */
  MTK_GPS_FS_RESULT_OK                  /* FS request success */  
} mtk_gps_fs_result;

typedef enum
{
  MTK_GPS_FS_WORK_MODE_AIDING = 0,      /* FS request for aiding phase  */
  MTK_GPS_FS_WORK_MODE_MAINTAIN         /* FS request for maintain phase  */
} mtk_gps_fs_work_mode;

/* MTK_PARAM_FRAME_SYNC_RESP : receive a result of a frame sync meas request */
typedef struct
{
  mtk_gps_fs_result eResult;            /* frame sync measurement request result */  
  mtk_r8            dfFrameTime;        /* frame time of the issued frame pulse */
} mtk_param_frame_sync_resp;
/* MTK_PARAM_QZSS_SEARCH_CONFIG : configuration of broadcast satellite data */
typedef struct
{
  mtk_qzss_search_mode qzss_en;      /* MTK_QZSS_DISABLE MTK_QZSS_ENABLE */
} mtk_param_qzss_search_mode;

/* MTK_PARAM_LOW_SPEED_FILTERING_CONFIGURATION : configuration of low speed filtering setting */
typedef struct
{
  mtk_low_speed_filtering_mode low_speed_filtering_en;      /* MTK_LOW_SPEED_FILTERING_SETTING */
} mtk_param_low_speed_filtering;

/* MTK_PARAM_QUERY_AGC : query AGC value */
typedef struct
{
  mtk_uint16 u2AGC;               /* AGC value */
} mtk_param_query_agc_value;
/*  MTK_PARAM_PMTK_CMD : receive a PMTK message for BEE safety design */
#define MTK_PMTK_CMD_MAX_SIZE            256
typedef struct
{
  char pmtk[MTK_PMTK_CMD_MAX_SIZE];         /* Buffer free space in bytes, read only */
} mtk_param_pmtk_cmd;

typedef struct
{
  mtk_uint16  u2Bitmap;
  mtk_int16   i2WeekNo;
  mtk_int32   i4Tow;

} mtk_param_agps_req;

typedef struct
{
  mtk_uint16 u2AckCmd;
  mtk_uint8 u1Flag;
} PMTKD_001_T;

typedef struct{
  mtk_r8 dfRtcDltTime;
} PMTKD_243_T;

typedef struct{
  mtk_bool fgSet; // reference location: 0 - clear,  1 - set
  mtk_r8 dfRefLat;
  mtk_r8 dfRefLon;
  mtk_r4 fRefAlt;
} PMTKD_244_T;

typedef struct
{
    mtk_uint16 u2Cmd;  // PMTK command ID:
                       // please get the data arguements in the following corresponding data structure.
    union
    {
        PMTKD_001_T rAck;              // PMTK001
    } uData;
} MTK_PMTK_RESPONSE_T;

typedef struct
{
  mtk_uint16    u2Cmd;  // PMTK command ID: if the PMTK command has data arguments,
                        // please assign the data in the following corresponding data structure.
  union
  {
    PMTKD_243_T r243;
    PMTKD_244_T r244;
  } uData;
} MTK_PMTK_DATA_T;


typedef enum
{
  MTK_IF_SW_EMULATION = 0,
  MTK_IF_UART_NO_HW_FLOW_CTRL,
  MTK_IF_UART_HW_FLOW_CTRL,
  MTK_IF_SPI,
  MTK_IF_APB
} mtk_if_type;

typedef enum
{
  MTK_PPS_DISABLE = 0,
  MTK_PPS_ENABLE_1PPS,
  MTK_PPS_ENABLE_NPPS
} mtk_pps_mode;
typedef enum
{
  MTK_CONFIG_GPS_GLONASS = 0,
  MTK_CONFIG_GPS_BEIDOU,
  MTK_CONFIG_GPS_ONLY,
  MTK_CONFIG_BEIDOU_ONLY,
  MTK_CONFIG_GLONASS_ONLY
} mtk_gnss_configuration;

/* factory default configuration for mtk_gps_init() */
typedef struct
{
  mtk_if_type   if_type;        /* interface type UART/SPI */
  mtk_pps_mode  pps_mode;       /* 1PPS mode */
  mtk_uint16    pps_duty;       /* PPS pulse high duration (ms) */
  mtk_uint8     pps_port;       /* pps output port select */
/*no need for 3336*/
#ifdef __GPS_MT3326__
  mtk_uint32    if_init_spd;    /* interface initial speed (bps of UART) */
#endif
  mtk_uint32    if_link_spd;    /* interface link speed (bps of UART) */

#ifdef __GPS_MT3326__
  mtk_uint32    hw_TCXO_Hz;     /* TCXO frequency in Hz */
  mtk_uint16    hw_TCXO_ppb;    /* TCXO clock drift in ppb (500=0.5ppm; 2500=2.5ppm) */
  mtk_uint16    internal_LNA;   /* Use internal LNA or not , 0 = not use, 1 = use internal LNA */
#else //for 3336 or new chip
  mtk_uint32    hw_Clock_Freq;  /* TCXO frequency in Hz */
  mtk_uint16    hw_Clock_Drift; /* TCXO clock drift in ppb (500=0.5ppm; 2500=2.5ppm) */    
  mtk_uint8     Int_LNA_Config; /* for 3326, 1: internal LNA, for 3336,1: high gain*/

#endif
  mtk_uint32    fix_interval;   /* fix interval in milliseconds */
                                /* 1000=>1Hz, 200=>5Hz, 2000=>0.5Hz */
/*no need for 3336*/
#ifdef __GPS_MT3326__
   double        Lat;            /* initial Latitude of a cold start (degree) */
   double        Lon;            /* initial Longitude of a cold start (degree) */
#endif

  mtk_gps_datum datum;          /* datum */
  mtk_gps_dgps_mode dgps_mode;  /* Off/RTCM/SBAS */
  mtk_gps_tcxo_mode tcxo_mode;

/*no need for 3336*/
#ifdef __GPS_MT3326__
  mtk_gps_agps_mode agps_mode;  /* Off/SUPL/EPO/BEE/Auto(BEE > EPO > SUPL) */
  mtk_uint16    opmode;         /* output the first fix ASAP */
  mtk_uint8     elev_mask;      /* elevation angle mask in degree */
  mtk_uint8     sbas_prn;       /* 0=automatic; 120-139=specific PRN */
  mtk_bool      sbas_test_mode; /* TRUE=test; FALSE=integrity */
#endif

  mtk_uint8     u1ClockType;    // FLASH_SIG_USE_16368_TCXO         0     // 16.368M integer, the most stable
                                // FLASH_SIG_USE_16369M_TCXO    1    // 16.369M integer, generated freq has bias
                                // FLASH_SIG_USE_26M_FRAC_TCXO  2    // not used
                                // FLASH_SIG_USE_26M_INT_TCXO   3    // 26M integer, generated freq has bias, 
                                // FLASH_SIG_USE_WIDERANGE_XTAL 0xFE // wide range, using crystal solution
                                // FLASH_SIG_USE_WIDERANGE      0xFF // wide range, more power consumption, no freq bias
                                /*no need for 3336*/
#ifdef __GPS_MT3326__
  mtk_bool      fgFrameAiding;  // 0: disable, 1: enable jiawangask
#endif

  mtk_uint32    reservedx;
  void*         reservedy;
  mtk_gnss_configuration  GNSSOPMode;      // In oder to make sure the GNSS configuration works correctly, 
} mtk_init_cfg;

typedef struct
{
  mtk_uint32   nmea_link_spd; //NMEA Baydrate
  mtk_bool     fgEnableHS;// Enable/Disable HS
#ifdef __GPS_MT3332__
  mtk_uint8    debug_type;       
                   // 1: Enable Agent debug
                   // 0: Disable Agent debug
#else
  mtk_uint8    DebugType;       
                // 0 : Output NMEA log to UART
                // 1: Output NMEA log to UART and File 
                // 2: Output NMEA log to UART and Output DSP Rx to application debug system
#endif
  mtk_uint8    nv_file_name[30]; // NV ram file name
  mtk_uint8    dbg_file_name[30]; // NMEA dbg file name
  mtk_uint8    dsp_dbg_file_name[30]; // DSP dbg file name
  mtk_uint8    dsp_port_name[30];  //DSP port name
  mtk_uint8    nmea_port_name[30]; //NMEA out port name
  mtk_uint8    nmeain_port_name[30];//NMEA in port name
  mtk_uint8    bee_path_name[30];  // HS patch name
  mtk_uint8    epo_file_name[30]; // epo working file
  mtk_uint8    epo_update_file_name[30]; // epo updated file
  mtk_uint8    pmtk_conn;   /*PMTK_CONNECTION_SOCKET | PMTK_CONNECTION_SERIAL*/
  mtk_int32    socket_port;  // PMTK sockect port name
  mtk_uint8    reserved;
} mtk_gps_driver_cfg;
// mtk_init_cfg.opmode defines
#define	MTK_INITCFG_OPMODE_2D_FIRSTFIX  (1 << 2)

// Task synchronization related type
typedef enum
{
  MTK_MUTEX_BIN_Q = 0,
  MTK_MUTEX_MSG_CNT,
  MTK_MUTEX_NV_HANDLE,
  MTK_MUTEX_DEBUG,
  MTK_MUTEX_MSG_Q,
  MTK_MUTEX_AGPS_MSG_CNT,
  MTK_MUTEX_AGPS_MSG_Q,  //  MTK_MUTEX_SPI,
  MTK_MUTEX_END
} mtk_mutex_enum;

typedef enum
{
  MTK_EVENT_GPS = 0,
  MTK_EVENT_HS,
  MTK_EVENT_AGENT,
  MTK_EVENT_END
} mtk_gps_event_enum;

typedef enum
{
    GPS_MNL_THREAD_UNKNOWN      = -1,
    GPS_MNL_THREAD_DSP_INPUT    = 0,
    GPS_MNL_THREAD_PMTK_INPUT   = 1,
    GPS_MNL_THREAD_BEE          = 2,
    GPS_MNL_THREAD_MNL          = 3,
    GPS_MNL_THREAD_AGENT        = 4,
    GPS_MNL_THREAD_NUM          = 5
} mtk_gps_thread_id_enum;

typedef enum
{
  MNL_STATUS_DEF = 0,
  MNL_DSP_UART_INIT_ERR,
  MNL_NMEA_UART_INIT_ERR,
  MNL_NMEAIN_UART_INIT_ERR,
  MNL_GPS_HW_CHECK_ERR,
  MNL_GPS_MUTEX_INIT_ERR,
  MNL_GPS_MUTEX_CREATE_ERR,
  MNL_MNL_THREAD_CREATE_ERR,
  MNL_MNL_THREAD_ADJUST_ERR,
  MNL_DSP_THREAD_CREATE_ERR,
  MNL_DSP_THREAD_ADJUST_ERR,
  MNL_PMTK_THREAD_CREATE_ERR,
  MNL_PMTK_THREAD_ADJUST_ERR,
  MNL_PMTK_APP_THREAD_CREATE_ERR,
  MNL_BEE_THREAD_CREATE_ERR,
  MNL_AGT_THREAD_CREATE_ERR,
  MNL_DSP_BOOT_ERR,
  MNL_INIT_SUCCESS
} mtk_gps_boot_status;

typedef enum
{
   HS_DEFAULT_STATUS,
   HS_INIT_ERR,
   HS_RUN_SUCCESS
}mtk_gps_hotstill_status;

typedef enum
{
    /*MT6620*/
    MT6620_E1 = 0,
    MT6620_E2,
    MT6620_E3,
    MT6620_E4,
    MT6620_EN,  // MUST smaller than 0x10
    /*MT6628*/
    MT6628_E1 = 0 + (0x10),
    MT6628_E2,
    MT6628_EN,  // MUST smaller then 0x20
    /*MT3332*/
    MT3332_E1 = 0 + (0x20),
    MT3332_E2,
    MT3332_EN,  // MUST smaller then 0x30
    /*MT3336*/
    MT3336_E1 = 0 + (0x30),
    MT3336_E2,
    MT3336_EN,        
    MT6572_E1 = 0 + (0x40),
    MT6572_EN,
    MT6582_E1 = 0 + (0x50),
    MT6582_EN ,       
    MT6592_E1 = 0 + (0x60),
    MT6592_EN , 
    MT6571_E1 = 0 + (0x70),
    MT6571_EN,            
    MT6630_E1 = 0 + (0x80),
    MT6630_EN
}eMTK_GPS_CHIP_TYPE;

//#define MTK_GPS_THIP_KEY          (0xFFFF6620) //
#define MTK_GPS_CHIP_KEY_MT6620   (0xFFFF6620)
#define MTK_GPS_CHIP_KEY_MT6628   (0xFFFF6628)
#define MTK_GPS_CHIP_KEY_MT3332   (0xFFFF3332)
#define MTK_GPS_CHIP_KEY_MT3336   (0xFFFF3336)
#define MTK_GPS_CHIP_KEY_MT6572   (0xFFFF6572)
#define MTK_GPS_CHIP_KEY_MT6582   (0xFFFF6582)
#define MTK_GPS_CHIP_KEY_MT6592   (0xFFFF6592)
#define MTK_GPS_CHIP_KEY_MT6571   (0xFFFF6571)
#define MTK_GPS_CHIP_KEY_MT6630   (0xFFFF6630)
/* Return value for most APIs */
#define MTK_GPS_SUCCESS                 (0)
#define MTK_GPS_ERROR                   (-1)
#define MTK_GPS_ERROR_NMEA_INCOMPLETE   (-2)
#define MTK_GPS_ERROR_TIME_CHANGED      (1)
#define MTK_GPS_NO_MSG_RECEIVED         (1)
#if defined(__L1_GPS_AUTO_TIMING_SYNC_SUPPORT__) || defined(__L1_GPS_REF_TIME_SUPPORT__)  
typedef enum _mtk_gps_frame_sync_type_enum
{
   GPS_FRAME_SYNC_TYPE1 = 0,
   GPS_FRAME_SYNC_TYPE2,
   GPS_FRAME_SYNC_TYPE3,
} mtk_gps_frame_sync_type_enum;
#endif /* (__L1_GPS_AUTO_TIMING_SYNC_SUPPORT__) || defined(__L1_GPS_REF_TIME_SUPPORT__) */

#define GPS_DELETE_EPHEMERIS        0x0001
#define GPS_DELETE_ALMANAC          0x0002
#define GPS_DELETE_POSITION         0x0004
#define GPS_DELETE_TIME             0x0008
#define GPS_DELETE_IONO             0x0010
#define GPS_DELETE_UTC              0x0020
#define GPS_DELETE_HEALTH           0x0040
#define GPS_DELETE_SVDIR            0x0080
#define GPS_DELETE_SVSTEER          0x0100
#define GPS_DELETE_SADATA           0x0200
#define GPS_DELETE_RTI              0x0400
#define GPS_DELETE_CLK              0x0800
#define GPS_DELETE_CELLDB_INFO      0x8000
#define GPS_DELETE_ALL              0xFFFF  
// assist bitmap:
 #define ASSIST_BIT_ALM   0x0001  // Satellite Almanac
 #define ASSIST_BIT_UCP   0x0002  // UTC Model
 #define ASSIST_BIT_KLB   0x0004  // Ionospheric Model
 #define ASSIST_BIT_EPH   0x0008  // Navigation Model
 #define ASSIST_BIT_DGPS 0x0010  // DGPS Corrections
 #define ASSIST_BIT_LOC   0x0020  // Reference Location
 #define ASSIST_BIT_TIME  0x0040  // Reference Time
 #define ASSIST_BIT_ACQ  0x0080  // Acquisition Assistance
 #define ASSIST_BIT_BSV   0x0100  // Real-Time Integrity
 #define ASSIST_BIT_EPO   0x0200  // Real-Time Integrity

#if ( defined(__ARMCC_VERSION) && (__ARMCC_VERSION < 200000 ) ) 
// for ADS1.x
#elif ( defined(__ARMCC_VERSION) && (__ARMCC_VERSION < 400000 ) ) 
// for RVCT2.x or RVCT3.x
#else
#pragma pack()
#endif

#define BOOT_RECV_BUF_SZ (1024)
extern unsigned char boot_recv_buf[BOOT_RECV_BUF_SZ];
extern int restart_cnt;
extern int boot_recv_buf_index;
extern int booting_flag;
extern int boot_poll_count;
extern int boot_out_count;
extern int boot_out_buf_index;

void print_boot_recv_buf();

//extern kal_uint8 send_RXilm;
extern int fgMNL_ring_empty;
extern int byte_in_mnl_ring;
extern int byte_lost_mnl_ring;
extern int fgTest_not_input_to_mnl;
#ifdef __cplusplus
   }
#endif

#endif /* MTK_GPS_TYPE_H */
