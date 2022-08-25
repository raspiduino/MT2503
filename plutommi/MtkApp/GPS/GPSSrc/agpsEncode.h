
#ifndef _INC_AGPSENCODE_H_
#define _INC_AGPSENCODE_H_


#define CP_MAX_SATELLITE_INFO 32
#define CP_MAX_GPS_ASSISTANCE_DATA_LEN 38

/* This structure is used to define satellite information */
typedef struct
{
    kal_uint8           sat_id;                 /* Satellite ID */
    kal_uint8           iODE;                   /* iODE */
} cp_mmi_satellite_info_struct;

/* This structure is used to define navigation model */
typedef struct
{
    kal_uint16                      gps_week;                       /* GPS week info. */
    kal_uint8                       gps_toe;                        /* GPS toe */
    kal_uint8                       nsat;                           /* Number of satellite */
    kal_uint8                       toe_limit;                      /* toe limit */
    kal_bool                        sat_info_used;                  /* If satellite info present */
    cp_mmi_satellite_info_struct    sat_info[CP_MAX_SATELLITE_INFO];/* Satellite information */
} cp_mmi_navigation_model_struct;

/* This structure is used to define the request of assistance data */
typedef struct
{
    kal_bool                            almanac;                    /* If alamanac needed */
    kal_bool                            utc_model;                  /* If utc model needed */
    kal_bool                            ionospheric_model;          /* If ionospheric model needed */
    kal_bool                            dgps_correction;            /* If dgps correction needed */
    kal_bool                            ref_location;               /* If reference location needed */
    kal_bool                            ref_time;                   /* If reference time needed */
    kal_bool                            acquisition_assist;         /* If acquisition assistence data needed */
    kal_bool                            realtime_integrity;         /* If realtime integrity needed */
    kal_bool                            navigation_model;           /* If navigation model needed */
    cp_mmi_navigation_model_struct      nav_model_data;             /* Navigation model data */
} cp_mmi_req_assist_data_struct;

/* accord to ts49.031 R6 */
kal_uint8 AsnEncode_SS2_gpsAssistanceData(cp_mmi_req_assist_data_struct *gpsData, kal_uint8 *encodeBuf);

#endif /*_INC_AGPSENCODE_H_*/

