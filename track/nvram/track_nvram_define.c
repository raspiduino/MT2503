
#if defined(__NF2318__)
#define BACKUP_DATA_MAX                  500       // NVRAM最大允许备份条数
#else
#define BACKUP_DATA_MAX                  1000       // NVRAM最大允许备份条数
#endif
#if defined(__GT740__)
#define BACKUP_DATA_PACKET_MAX             150// 这个文件已经废了
#elif defined(__NF2318__)
#define BACKUP_DATA_PACKET_MAX             160// 这个文件已经废了
#else
#define BACKUP_DATA_PACKET_MAX             45
#endif
#define TRACK_MAX_URL_SIZE                 99       // URL 允许最大的字符数

#if defined(__GT300S__) || defined(__GT370__)|| defined (__GT380__)
#define TRACK_DEFINE_FENCE_SUM              5       // 电子围栏个数
#else
#define TRACK_DEFINE_FENCE_SUM              1       // 电子围栏个数
#endif

#define NVRAM_EF_SYS_ABNORMAL_LID_VERNO                     "000"  
#define NVRAM_EF_GPS_POSITION_LID_VERNO                     "001"
#define NVRAM_EF_GPS_BACKUP_DATA_PARAM_LID_VERNO            "001"
#define NVRAM_EF_CHECK_OTA_LID_VERNO                        "000"

#define NVRAM_EF_SYS_ABNORMAL_TOTAL	1
#define NVRAM_EF_SYS_ABNORMAL_SIZE	sizeof(nvram_sys_abnormal_data_struct)

#define NVRAM_EF_GPS_POSITION_TOTAL 1
#define NVRAM_EF_GPS_POSITION_SIZE sizeof(nvram_gps_last_data_struct)

#define NVRAM_EF_GPS_BACKUP_DATA_PARAM_TOTAL 1
#define NVRAM_EF_GPS_BACKUP_DATA_PARAM_SIZE sizeof(nvram_gps_backup_data_param_struct)


#define NVRAM_EF_CHECK_OTA_SIZE sizeof(nvram_check_ota_struct)
#define NVRAM_EF_CHECK_OTA_TOTAL 1 

#define NVRAM_EF_DRV_PARAMETER_SIZE sizeof(nvram_drv_parameter_struct)


#define NVRAM_EF_DRV__IMP_BACKUP_SIZE   sizeof(nvram_drv_importance_backup_struct)


#if defined( __TRACK_DISK_NVRAM__)

#else

#define NVRAM_EF_PARAMETER_TOTAL 1
#define NVRAM_EF_IMPORTANCE_PARAMETER_TOTAL 1
#define NVRAM_EF_DRV_PARAMETER_TOTAL 1
#define NVRAM_EF_PHONE_NUMBER_TOTAL 1

#endif /* __TRACK_DISK_NVRAM__ */

