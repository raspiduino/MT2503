/******************************************************************************
 * track_os_paramete.h -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        通用头文件
 *
 * modification history
 * --------------------
 * v1.0   2012-07-14,  jwj create this file
 *
 ******************************************************************************/

#ifndef _TRACK_PARAMETE_H
#define _TRACK_PARAMETE_H

/****************************************************************************
* Include Files             包含头文件
*****************************************************************************/
#include "track_os_data_types.h"
#include "track_version.h"
#include "track_os_log.h"
#include "track_project_common_define.h"

/*****************************************************************************
 *  Define			    宏定义
*****************************************************************************/
#ifdef __TRACK_DISK_NVRAM__
#define MAX_APN_LEN             100
#define MAX_PDP_ADDR_LEN        16
#define TCM_MAX_PEER_ACL_ENTRIES	 	10

#define MAX_GPRS_USER_NAME_LEN 32
#define MAX_GPRS_PASSWORD_LEN  32
#define MAX_GPRS_APN_LEN       100
#define MAX_GPRS_IP_ADDR       4 /* IP address length */
#define TRACK_MAX_URL_SIZE                 99       // URL 允许最大的字符数

#if defined(__NF2318__)
#define BACKUP_DATA_MAX                  500       // NVRAM最大允许备份条数
#else
#define BACKUP_DATA_MAX                  1000       // NVRAM最大允许备份条数
#endif
#if defined(__GT740__)
#define BACKUP_DATA_PACKET_MAX             150
#elif defined(__NF2318__)
#define BACKUP_DATA_PACKET_MAX             160
#else
#define BACKUP_DATA_PACKET_MAX             45
#endif

#define TRACK_DEFINE_SOS_COUNT              3       // 支持 SOS 号码的个数

#define TRACK_DEFINE_FN_COUNT               2       // 支持 亲情 号码的个数
#define TRACK_DEFINE_WN_COUNT               15
#define TRACK_DEFINE_PHONE_NUMBER_LEN_MAX  21       // 电话号码最大允许长度
#if defined(__GT300S__)||defined(__GT370__)|| defined (__GT380__)
#define TRACK_DEFINE_FENCE_SUM              5       // 电子围栏个数
#else
#define TRACK_DEFINE_FENCE_SUM              1       // 电子围栏个数
#endif


#define NVRAM_EF_GPS_BACKUP_DATA_SIZE sizeof(BACKUP_GPS_DATA)
#define NVRAM_EF_GPS_BACKUP_DATA_TOTAL BACKUP_DATA_MAX
#define NVRAM_EF_LOGD_TOTAL     1
#define NVRAM_EF_LOGD_SIZE      sizeof(nvram_ef_logd_struct)
#define NVRAM_EF_REALTIME_SIZE sizeof(nvram_realtime_struct)
#define NVRAM_EF_DISPLACEMENT_REALTIME_TOTAL 1

#define NVRAM_EF_PARAMETER_SIZE sizeof(nvram_parameter_struct)

#define NVRAM_EF_IMPORTANCE_PARAMETER_SIZE sizeof(nvram_importance_parameter_struct)
#define NVRAM_EF_PHONE_NUMBER_SIZE sizeof(nvram_phone_number_struct)

//#define NVRAM_EF_DRV__IMP_BACKUP_SIZE   sizeof(nvram_drv_importance_backup_struct)

/*****************************************************************************
* Typedef  Enum         枚举
*****************************************************************************/
typedef enum
{
    LOG_AUTO,
    LOG_SERIAL,
    LOG_CATCHER,
    LOG_2FILE,
    LOG_MAX
} log_target_enum;

/*****************************************************************************
 *  Struct			    数据结构定义
*****************************************************************************/
typedef struct
{
    kal_uint8                filename[20];
    kal_uint8                index;
    kal_uint8                not_read;
} audio_file_struct;

typedef struct
{
    kal_uint8   zone;
    kal_uint8   time;
    kal_uint8   time_min;
    kal_uint8   timezone_auto;
} nvram_gps_time_zone_struct;

typedef struct
{
    kal_uint8 sw;
    kal_uint16 up_interval_time;
} nvram_gpsup_struct;

typedef struct
{
    kal_uint8                                   sw;                   // ON/OFF；
    kal_uint8                                   car;                  // Car Type NO (1 仅OBD， 2 丰田， 4 本田， 5 大众， 6 通用)
    kal_uint8                                   upload_type;          // 上传类型
    kal_uint8                                   hard_acceleration;    // 急加速门限值
    kal_uint8                                   rapid_deceleration;   // 急减速门限值
    char                                        ver[20];              // OBD 版本
    kal_uint16                                  upload_time;          // 定时上报数据的间隔时间
    kal_uint16                                  displacement;         // 车辆排量
    kal_uint16                                  fuel_consumption;     // 车辆百公里平均油耗
    kal_uint32                                  total_mileage;        // 标定默认总里程
} nvram_obd_parameter_struct;

typedef struct
{
    kal_uint16  version;                                         //1为谷米，2为通用，3为外贸，4为图强
    kal_uint8   support_sensor;                                 //是否支持sensor,0为不支持，1为支持
    kal_uint8   support_WM;                                 //是否为外贸版，主要控制apn修改，0为不是，1为是
    kal_uint8   server_lock;                                  //是否锁定域名，0为不锁定，1为锁定
} app_version_struct;


/*  begin  NVRAM备份定位数据   */
typedef struct
{
    kal_uint16  len;
    kal_uint8   buf[BACKUP_DATA_PACKET_MAX];
} BACKUP_GPS_DATA;

typedef struct
{
    kal_uint8           logd_module[L_MAX];
    kal_uint8           log_sw;
    log_target_enum     logd_target;
    char                log_file_name[32];
} nvram_ef_logd_struct;

typedef struct
{
    kal_uint8           sw;             // 0=无效  1=启用
    kal_uint8           in_out;         // 0：IN,入围栏报警，1：OUT出围栏报警，2：为空,进/出围栏报警；默认为进出围栏都报警
    kal_uint8           alarm_type;     // 报警类型（0 仅GPRS，1 SMS+GPRS）
    kal_uint8           square;         // 0=圆形  1=矩形
    kal_uint32          radius;         // 半径(米)
    float               lon;
    float               lat;
    float               lon2;
    float               lat2;
} nvram_electronic_fence_struct;

typedef struct
{
    kal_uint8           sw;             // 开启超速报警（默认为关闭）
    kal_uint8           threshold;      // 超速门限范围（km/h）：1-255 ，默认 100km/h
    kal_uint8           alarm_type;     // 报警上报方式（0 仅GPRS；1 SMS+GPRS）
    kal_uint16          delay_time;     // 时间范围（秒）：5-600S  ，默认 20S；
} nvram_speed_limit_alarm_struct;

typedef struct
{
    kal_uint8           sw;                         //
    kal_uint8           alarm_type;                 // 上报方式（默认为 1）(0=only GPRS,1=GPRS+SMS,2=GPRS+SMS+Call,3=GPRS+CALL)
    kal_uint16          delay_time_off;             // 范围：2-60 S,默认 5S
    kal_uint16          delay_time_on;              // 范围：1-3600 S,默认 300S
    kal_uint16          delay_time_acc_on_to_off;   // ACC ON to OFF 跳变禁止报警时间，默认 180 秒
#ifdef __NT31__
    kal_uint16          send_alarm_time;   //  断开报警不停发送报警包的间隔时间，默认为0
#endif /* __NT32__ */

} nvram_power_fails_alarm_struct;

typedef struct
{
    kal_uint8           sw;                     // 震动报警 开/关
    kal_uint8           alarm_type;             // (0=only GPRS,1=GPRS+SMS,2=GPRS+SMS+CALL,3=GPRS+CALL)
    kal_uint16          detection_time;         // 检测时间（秒），默认为：10
    kal_uint16          detection_count;        // 在检测时间内，检测满足的次数，默认为：5
    kal_uint8           sampling_interval;      // 检测次数采样最短间隔，默认为：1
    kal_uint32          alarm_interval;         // 最短报警间隔（秒）
    kal_uint32          alarm_delay_time;       // 报警延时（秒），默认为：180
    kal_uint8           sensitivity_level;      // 灵敏度等级，默认值为：16
} nvram_vibrates_alarm_struct;
typedef struct
{
    kal_uint8           sw;                     // 震动报警 开/关
    kal_uint8           alarm_type;             // (0=only GPRS,1=GPRS+SMS,2=GPRS+SMS+CALL,3=GPRS+CALL)
    kal_uint8                               door_status;
} nvram_door_alarm_struct;
typedef struct
{
    kal_uint8           sw;
    kal_uint8           alarm_type;                      // (0=only GPRS,1=GPRS+SMS)
} nvram_low_power_alarm_struct;

typedef struct
{
    kal_uint8           sw;                              // SOS报警是否启用（默认为开启）
    kal_uint8           alarm_type;                      // SOS报警上报方式（默认为 1）(0=only GPRS,1=GPRS+SMS,2=GPRS+SMS+Call,3=GPRS+CALL)
#if defined(__SPANISH__)
    kal_uint8           key_type;                        // 0  短按（按一次就触发）; 1  长按（时间3秒）(默认)
    char                alarm_sms_head[100];             // 用于自定义报警提醒短信内容
#endif
} nvram_sos_alarm_struct;

typedef struct
{
    kal_uint8           sw;                              // 位移报警开关（开：1，关：0）
    kal_uint8           alarm_type;                      // 0～2；0 仅GPRS，1 SMS+GPRS，2 GPRS+SMS+电话,3=GPRS+CALL；默认值：1
    kal_uint16          radius;                          // 位移半径（单位：米）100～1000；默认值：300
} nvram_displacement_alarm_struct;

typedef struct
{
    kal_uint8           sw;                              // 停车超时开关（开：1，关：0）
    kal_uint8           alarm_type;                      // 报警类型（0 仅GPRS，1 SMS+GPRS）
    kal_uint16          time;                            // 停车时长；5～3600分钟；停车时长；默认值：60
} nvram_carpark_alarm_struct;

typedef struct
{
    kal_uint8           sw;                              // 疲劳驾驶报警（开：1，关：0）默认开
    kal_uint8           alarm_type;                      // 报警上报方式（0 仅GPRS；1 SMS+GPRS）默认0
    kal_uint16          delay_time;                      // 1～3600分钟；疲劳驾驶持续时间，默认240分钟
    kal_uint16          delay_reset;                     // 1～3600分钟；驾驶清零计时时间，默认20分钟
} nvram_fatigue_driving_alarm_struct;

typedef struct
{
    kal_uint8           sw;                              // GPS盲区报警（开：1，关：0）
    kal_uint8           alarm_type;                      // 报警上报方式（0 仅GPRS；1 SMS+GPRS）
    kal_uint8           in_blind_area;                   // 1～10分钟；进入盲区报警延时上报时间；默认值：3分钟
    kal_uint8           out_blind_area;                  // 1～10分钟；离开盲区延时上报时间；默认值：1分钟
} nvram_blind_area_alarm_struct;

typedef struct
{
    kal_uint8           sw;                              // ON/OFF；默认值：ON
    kal_uint8           alarm_type;                      // 报警上报方式（0 仅 GPRS，1 SMS+GPRS；默认值：1）
    kal_uint16          threshold;                       // 10～360；默认值：125
    kal_uint16          recover_threshold;               // 10～360；默认值：130
    kal_uint16          detection_time;                  // 1～300秒；默认值：10 秒
} nvram_power_extbatalm_struct;

typedef struct
{
    kal_uint8           sw;                              // ON/OFF；默认值：ON
    kal_uint8           alarm_type;                      // 报警上报方式（0 仅 GPRS，1 SMS+GPRS；默认值：1）
    kal_uint16          threshold;                       // 10～360；10倍的伏特，默认115为11.5V
    kal_uint16          recover_threshold;               // 10～360；10倍的伏特，默认120为12.0V
    kal_uint16          detection_time;                  // 1～300秒；默认值：10 秒
} nvram_power_extbatcut_struct;

typedef struct
{
    kal_uint8           sw;                              // ON/OFF；默认值：ON
    kal_uint8           alarm_type;                      // 报警上报方式（0 仅 GPRS，1 SMS+GPRS, 2 SMS+GPRS+CALL,3 GPRS+CALL；默认值：1）
} nvram_teardown_struct;
typedef struct
{
    kal_uint8           sw;                              // ON/OFF；默认值：ON
    kal_uint8           sacn_timer;                      // 搜索时间
    kal_uint16          work_timer;                      // 工作间隔时间
} nvram_wifi_struct;
typedef struct
{
    kal_uint16          acc_l_threshold_vbat;                       // 10～360；默认值：132
    kal_uint16          acc_h_thresholdvbat;               // 10～360；默认值：135
} nvram_ext_vbat_check_acc_struct;

typedef struct
{
    kal_uint8                      mode;                 // 0/1,0 定时上传，1 定距上传
    kal_uint16                     interval_acc_on;      // 0、5～18000秒，ACC ON 状态下上传间隔；默认值：10
    kal_uint16                     interval_acc_off;     // 0、5～18000秒，ACC OFF 状态下上传间隔；默认值：0
    kal_uint16                     distance;             // 0、50～10000米，定距距离；默认值：300
} nvram_gps_report_mode_struct;

typedef struct
{
    kal_uint16                     detection_time;       // 检测时间（秒），默认为：10
    kal_uint16                     detection_count;      // 震动激活GPS触发次数门限，在检测时间内，检测满足的次数，默认为：3
    kal_uint8                      sampling_interval;    // 检测次数采样最短间隔，默认为：1
} nvram_vibrates_start_gps_struct;

typedef struct
{
    kal_uint8                      sw;                   // 拐点补传开启/关闭
    kal_uint8                      angleOfDeflection;    // 30～180度，默认值：60度，偏转角度
    kal_uint8                      detection_time;       // 2～10秒，默认值：5秒，检测时间
} nvram_gps_anglerep_struct;

typedef struct
{
    kal_uint8                      sw;                   // 定距上传 开启/关闭
    kal_uint16                     distance;             // 0、50～10000米，定距距离；默认值：300
} nvram_gps_fixed_distance_struct;

typedef struct
{
    kal_uint8                      sw;                   // 定时上传 开启/关闭
    kal_uint16                     interval_acc_on;      // 0、5～18000秒，ACC ON 状态下上传间隔；默认值：10
    kal_uint16                     interval_acc_off;     // 0、5～18000秒，ACC OFF 状态下上传间隔；默认值：0
    kal_uint16                     lbs_interval;         // 保存单位 秒
    kal_uint16                     mode1_gps_time;       // gt300模式一GPS时间间隔
} nvram_gps_fixed_time_interval_struct;

typedef struct
{
    kal_uint8                            static_filter_sw;              // 静态数据过滤开关
    kal_uint16                           static_filter_distance;        // 静态数据最小距离(米)默认值:100米
    kal_uint8                            ephemeris_interval;            // GPS 星历更新时间设置；60～240分钟，默认值：60分钟
    kal_uint8                            accrep;                        // ACC状态变化立即上报功能开启/关闭
    kal_uint8                            location_timeout;              // 搜星超时(分)
    nvram_vibrates_start_gps_struct      vibrates;                      // 震动唤醒GPS的条件
    nvram_gps_anglerep_struct            anglerep;                      // 拐点补传
    nvram_gps_fixed_distance_struct      Fd;                            // 定距上传
    nvram_gps_fixed_time_interval_struct Fti;                           // 定时上传
} nvram_gps_work_struct;

typedef struct
{
    kal_uint8                      sw;                   // 里程统计 开启/关闭
    kal_uint32                     mileage;              // 里程 km/h
    kal_uint32                     K;              //  系数k，默认1000

} nvram_mileage_statistics_struct;

typedef struct
{
    char                           password[20];         // 用户密码
    char                           superCmd[20];         // 超级指令头
    kal_uint8                      password_sw;          // 密码控制指令开/关
    kal_uint8                      Permit;               // SOS与中心号码权限控制，默认为0
    kal_uint8                      SOSPermit;            // 参数的查询设置权限，默认为0
    kal_uint8                      AlarmNumCount;        // 报警的发送号码个数，默认为1
    kal_uint8                      MonPermit;            // 监听权限控制，默认为2
} nvram_Permission_settings_struct;

typedef struct
{
    kal_uint8                      sw;                   // GPRS阻塞报警
    kal_uint8                      link;                 // GPRS重连次数
} nvram_GPRS_Obstruction_struct;

typedef struct
{
    kal_uint8                      sw;                   // ON/OFF；SENSOR 检测静止上报最后位置开关；默认值：OFF
    kal_uint16                     detection_time;       // 10～300 秒；时间范围；默认值：180 秒
    kal_uint16                     speed;                // 运动判断的最小速度；默认值：6km/h
    kal_uint16                     count;                // 0～100 连续监测的个数
} nvram_staticrep_struct;

typedef struct
{
    kal_uint8                      sw;                   // ON/OFF；盲区报警开关
    kal_uint16                     blind_in_time;        // gps退出盲区之后gps定位进入盲区多久报告
    kal_uint16                     blind_out_time;       // gps在进入盲区之后gps定位推出盲区多久报告
    kal_uint8                      alarm_type;           // M=0 仅GPRS;M=1 SMS+GPRS；默认上报方式为1//
} nvram_blind_struct;

typedef struct
{
    kal_uint8                      sw;                   // ON/OFF；开机报警开关
    kal_uint8                      alarm_type;           // M=0 仅GPRS;M=1 SMS+GPRS；默认上报方式为1//
} nvram_boot_struct;

typedef struct
{
    kal_uint8                      sw;                   // ON/OFF；伪基站报警
    kal_uint8                      alarm_type;           // M 上报方式
    kal_uint16                     alarm_filter;         //伪基站标志有效时间，单位 分
} nvram_FCFALM_struct;

typedef struct
{
    kal_uint8                      sw;                   // ON/OFF；
    kal_uint8                      mode;                 // 检测模式；
    kal_uint32                     lock_on_time;         // 每次锁的时间；默认值：3000 毫秒
    kal_uint32                     lock_off_time;        // 每次锁释放的间隔时间，默认值：40毫秒
    kal_uint32                     lock_continue_time;   // 在手动解锁之前循环锁持续的时间，默认值：20秒
} nvram_motor_lock_struct;

typedef struct
{
    kal_bool                       custom_apn_valid;
    char                           apn[MAX_GPRS_APN_LEN];
    char                           username[MAX_GPRS_USER_NAME_LEN];
    char                           password[MAX_GPRS_PASSWORD_LEN];
} nvram_GPRS_APN_struct;

typedef struct
{
    kal_uint8   url[TRACK_MAX_URL_SIZE];
    kal_uint8   conecttype;       // 1=domain ;0=IP
    kal_uint8   server_ip[4];     // 十进制
    kal_uint16  server_port;      // 十进制
    kal_uint8   soc_type;         // 0=TCP;1=UDP
    kal_uint8   server_type;      // 1=动态域名
    kal_uint8   lock;             // 锁定修改
    kal_uint8   ip_update;        // ip更新
} nvram_server_addr_struct;
typedef struct
{
	kal_uint8 url[TRACK_MAX_URL_SIZE];//从服务器获取之后的http链接
	kal_uint8 isdownload;//是否已经下载完成 0-完成 1-未完成
	kal_uint8 filestyle;//固件域名还是mp3域名 1- mp3  2 固件
	kal_uint32 file_length;//文件总大小
	kal_uint32 load_length;//已下载大小
	kal_uint8 etag;//是否更新
	kal_uint8 voice_Id[3];//语音ID
}nvram_http_server_url_struct;
#if 1
typedef struct
{
	kal_uint8 isdownload;//是否已经下载完成 0-完成 1-未完成
	kal_uint8 filestyle;//固件域名还是mp3域名 1- mp3  2 固件
	kal_uint32 file_length;//文件总大小
	kal_uint32 load_length;//已下载大小
	kal_uint8 etag;//是否更新
	kal_uint8 voice_Id[3];//语音ID
}nvram_http_server_struct;
#endif
typedef struct
{
    kal_uint8                      sw;                   // ON/OFF；
    kal_uint8                      at_least_pack;        // GPS定位数据打包发送至少需要满足的数量；2～25，默认值为：10
    kal_uint8                      batch_paket;          // 一般数据发送组包个数；1～25，默认值为：10
} nvram_group_package_struct;

typedef struct
{
    kal_uint8                      sw;                   // ON/OFF；
    kal_uint8                      last_position_valid;  // 是否自动注入上一次定位点
    kal_uint8                      server_mode;          // 0 与应用相同服务器，透传数据方式传输； 1 独立服务器，独立地址传输
    kal_uint32                     next_update_time;     // 服务器分配下次更新时间
} nvram_agps_struct;


typedef enum
{
    WORK_MODE_1 = 1,                //定时定位工作模式
    WORK_MODE_2,                    //智能定位模式->默认模式
    WORK_MODE_3,                    //深度休眠模式
    WORK_MODE_4,                    //Tracker工作模式
    WORK_MODE_MAX          // 4
} track_enum_work_mode;

typedef struct
{
    kal_uint8                   sw;                  // ON/OFF；
    track_enum_work_mode        mode;                // 终端工作模式
    //注  GT370 -- chengjun  2017-04-11
    //1=为需求里的模式1，T>120s
    //2=为需求里的模式1，T<120s
    //3=为需求里的模式2，定时开机，超长待机
    kal_uint16          mode3_timer;                 // 间隔时间，分钟为单位
    kal_uint16          datetime;                    //起始时间
    kal_uint16          mode1_timer;                 // 模式1的间隔时间，分钟为单位
    kal_uint8           teardown_mode;               //防拆模式/开盖模式，总结就是进入异常了
    kal_uint8           teardown_time;               //防拆时间，异常模式持续时间
} nvram_work_mode_struct;

typedef struct
{
    kal_uint8                      sw;                   // ON/OFF；换卡报警开关
    kal_uint8                      simalm_type;           // M=0 仅GPRS;M=1 SMS+GPRS；默认上报方式为0
    kal_uint8                      sim_imsi[16];
} nvram_sim_alm_struct;

typedef struct
{
    kal_uint8                      sw;                   // ON/OFF；开机报警开关
    kal_uint8                      type;           // 0在线指令，1短信指令
    kal_uint8                      Number[TRACK_DEFINE_PHONE_NUMBER_LEN_MAX];
} nvram_smstc_struct;

typedef struct
{
    kal_uint8                      sw;                  // ON/OFF
    kal_uint16                     t1;                  // 上传间隔；10~3600秒，默认60秒；
    kal_uint16                     t2;                  // GPS不定位启动LBS传点间隔，10-3600秒，默认60秒；
} nvram_lbson_struct;

typedef struct
{
    char                           wifiname[20];
    char                           wifipasw[20];
} nvram_wifi_param_struct;

typedef struct
{
    kal_uint8                      mode;                // 外挂单片机工作模式
    kal_uint16                     mode1_par1;          // 对于模式1下的参数
    kal_uint16                     mode1_par2;          // 对于模式1下的参数
    kal_uint16                     mode2_par1;          // 对于模式2下的参数
    kal_uint16                     mode2_par2;          // 对于模式2下的参数
    U32                            mode3_par1;
    kal_uint16                     mode3_par2;          // 对于模式3下的参数
    U8                             mode4_par1;
    kal_uint16                     mode4_par2[12];          // 对于模式4下的参数
    kal_uint32                     mode1_time;          // 模式一持续工作时间
    kal_uint8                      premode;                // 记录防拆前的模式
} nvram_ext_chip_struct;

typedef struct
{
    kal_uint8 gsm_volt_low_calibration_count;// 单片机传递小于2.85V电压次数
    kal_uint8 gsm_calibration_status;// 校准标志
    kal_uint8 bat_low_time;//低于2.75的次数
    float comsultion_ele;// 消耗的电量
    U8 first_calibration_ele;//电压校准的电量百分比
    kal_uint32 bat_lowtimep;// 低于2.75时间
    kal_uint32 bat_syntimep;// 高于2.75时间
    kal_uint32 gsm_calibration_time[5];// 校准电压的时间
} track_work_time;

typedef struct
{
    kal_bool gps_fix_sw;//gps定位开关
    kal_bool wf_lbs_fix_sw;//WF定位开关
    kal_uint8 fix_level;//定位优先级，默认1 GPS>WF
} track_fixmode_struct;

typedef struct
{
    kal_uint8 sw;
    kal_uint16 mode1_startTime;
    kal_uint16 mode1_endTime;
    kal_uint16 mode2_sensorOutTime;//震动超时时间进入飞行
} track_fly_mode_struct;

typedef struct
{
    U8 sw;
    U8 alarm_type;    // 报警上报方式（0 仅 GPRS，1 SMS+GPRS, 2 SMS+GPRS+CALL,3 GPRS+CALL；默认值：1）
} nvram_drop_alarm;

typedef struct
{
    kal_uint8                    sw;  // ON/OFF；信息传输开关，默认开
    kal_uint16                    time;          //上传间隔，默认60S
} nvram_info_up_struct;

#if defined(__BMS_PHYLION__)
typedef struct
{
	kal_uint8 otherData1;//按位 bit7 预留 bit6 转把故障 bit5 电机霍尔故障 bit4 欠压保护 bit3 防飞车保护 bit2 堵转保护 bit1 电机状态（1 处于运行状态） bit0 刹车 （1 处于刹车状态） 
	kal_uint8 otherData2;//按位 bit2 预留 bit1 锁电机信号回馈 bit0ECU控制使能回馈 （1 控制器不工作）纯电动 纯助力 电动助力混合 bit7 1 0 1 bit6 0 1 1 bit5~bit3 控制器转把限速状态回馈 90% 85% 80% 75% 70% bit5 1 1 0 0 0 bit4 0 0 1 1 0 bit3 1 0 1 0 1 
	kal_uint8 voltageH;//霍尔变化高字节
	kal_uint8 voltageL;//霍尔变化低字节
	kal_uint8 relativeCapacity;//相对容量
	kal_uint8 currentH;//实时电流高字节
	kal_uint8 currentL;//实时电流低字节
	kal_uint8 leftCapatiryH;//剩余容量高字节
	kal_uint8 leftCapatiryL;//剩余容量低字节
	kal_uint8 absoluteCapacity;//绝对容量百分比
	kal_uint8 absoluteFullCapacity[2];//绝对满电电容
	kal_uint8 circulationOfBat[2];//电池组循环次数
	kal_uint8 valtage[28];//电池1-14号电池电压电压
	kal_uint8 totalValtage[2];//电池组总电压
	kal_uint8 temperature[2];//电池组内部温度
	kal_uint8 chargeInterval[2];//当前充电间隔时间
	kal_uint8 largeChargeInterval[2];//最大充电间隔时间
	kal_uint8 barCode[20];//成品条形码//1.2.0有20和16位的兼容情况
	kal_uint8 versionNum[2];//版本号
	kal_uint8 valtageManufacturer[16];//电池制造厂商
	kal_uint8 relativeCapacityPer;//相对容量百分比
	kal_uint8 absoluteCapacityPer;//绝对容量百分比
}controller_data_struct;
typedef struct
{
	kal_uint8 brake;//刹车
    kal_uint8 ele_sta;//电机状态
    kal_uint8 locked_rotor;//堵转保护
    kal_uint8 flying_car;//防飞车保护
    kal_uint8 uder_voltage;//防欠压保护
    kal_uint8 holzer_fault;//电机霍尔故障
    kal_uint8 malfunction;//转把故障
    kal_uint8 locked_ele;//锁电机信号
    kal_uint8 turn_limit;//转把限速状态
    kal_uint8 con_mode;//控制器模式(电动，纯电动)
    kal_uint8 ecu_enable;//ecu控制使能状态
    kal_uint8 holzer_stah;//0.5 秒内三个霍尔变化的个数高字节
    kal_uint8 holzer_stal;//0.5 秒内三个霍尔变化的个数低字节
}vehicle_status_struct;
#endif
#if defined(__NF2318__)
typedef struct
{
	kal_uint16 deviceID;//设备ID
    //kal_uint8  SequenceNumber[11];                                 //终端序列号
    kal_uint8  rcv;//检测是否丢失数据 默认值99
	kal_uint8 publickey[128];//设备公钥
	kal_uint8 TEA_KEY[16];//XxTEA加密密钥
	kal_uint8 dfttimeout;//服务器应答超时时间设置 1-60
	kal_uint8 dftlockvoiceplayt;//还车语音延时播报设置
	kal_uint8 sleept;//进入休眠时间设置
	kal_uint8 volume;//语音音量大小设置
	kal_uint16 xctime;//寻车语音播放时间
	kal_uint8 btsw;//蓝牙开关
	kal_uint8 diameter;//车轮直径设置
	kal_uint8 alnicounum;//设置电机磁钢对数
	kal_uint8 lockdomain;//锁定域名设置
	kal_uint8 alarmreq;//报警间隔
	kal_uint8 dftoutpoffiltert;//外电检测过滤时间设置
	kal_uint16 viblmg;//震动灵敏度 mg 0-2000
	kal_uint8 senspkset;//语音播报出发设置
	kal_uint8 wheelmovtime;//轮动检测设置
	kal_uint8 wheelmov;//轮动判断设置  脉冲个数
	kal_uint32 dormantfreq;//半休眠间隔时间 
	char       bt_name[20];//蓝牙名称
#if defined(__EL100_XYT__)
    kal_uint8 auth_len;//鉴权码长度
    kal_uint8 auth_code[32];//鉴权码
#endif
}ste_parameter_struct;
typedef struct
{
	kal_uint8 ele;//电机状态 0  不锁 1 锁
	//kal_uint8 wheel;//后轮锁状态0 不锁 1锁 这个移走
	kal_uint8 lease;//租赁状态// 1开锁 0锁车
	kal_uint8 findcar;//远程寻车开关 0 关闭 1 打开
	kal_uint8 vechile_sw;//车辆开关，模拟的一种
	//kal_uint8 exbatlock;//电池锁状态 0 不锁 1 锁 这个移走
	kal_uint8 sleep;//休眠 0 无休眠 15半休眠  16 全休眠
	kal_uint8 encode_type;//是否加密  1 不加密，0 加密
	kal_uint8 pwrsave;//运维模式 1 进入 0 退出
	kal_uint8 btadvtype;//测试代码用，1 动态使用sn号广播  0 写死700000001广播 默认 1
}ste_status_struct;//终端状态
typedef struct
{
	kal_uint8 con_mode;//电动车模式
	kal_uint8 turn_limit;//转把限速
	kal_uint8 locked_ele;//锁电机信号
	kal_uint8 soc;//相对容量百分比
	kal_uint32 totalmileage;//总里程统计
	kal_uint32 oncemileage;//单次里程
}ele_data_struct;
typedef struct
{
	kal_uint8 isload;//是否已经下载
	kal_uint8 voice_id[3];//语音ID
}voice_id_struct;//语音文件ID

typedef struct
{
	voice_id_struct void_id[100];//先写上20条语音文件 增加到100条 Liujw 2019-7-19
}voice_list_struct;//要下载的语音ID列表
typedef struct
{
	kal_uint8 osdswitch;//开关 默认 1
	kal_uint8 osdspeed;//时速 0-60 默认15KM/H
	kal_uint8 osdtimeinterval;//超速提醒间隔 0- 60 默认 3fenzhong
	kal_uint8 osdmaxstatus;//是否超过总时长
	kal_uint16 osdtimemax;//提醒总时长0-1800 默认 0
	kal_uint8 osdvoiceid[3];//超速语音ID 默认 00000E
	kal_uint8 osdringid[3];//超速铃声ID   默认 00000F
}osd_struct;//超速报警
#endif
typedef struct
{
    char                                build_date[15];
    char                                build_time[15];
    char                                version_string[20];
    char                                version_string2[20];
    nvram_GPRS_APN_struct               apn;
    nvram_server_addr_struct            server;
    nvram_server_addr_struct            server2;
    nvram_server_addr_struct            mserver2[4];
    nvram_server_addr_struct            dserver;
#if defined(__BACKUP_SERVER__)
    nvram_server_addr_struct             bserver;
#endif
    app_version_struct                           app_version;

#if defined (__LUYING__)
    nvram_server_addr_struct            server4;    //录音上报服务端地址
#endif /* __LUYING__ */
#if defined(__NF2318__)
	kal_uint8 rcv;//增加一个标识位 默认99
    kal_uint8  SequenceNumber[11];                                 //终端序列号
    char								device_id[17];				//设备ID号
#if defined(__EL100_XYT__)
    kal_uint8                           cs_code;                    // 厂商代码
    kal_uint8                           identify[12];               // 识别码
#endif
#endif
} nvram_importance_parameter_struct;

#if defined(__ACC_ALARM__)
typedef struct
{
    kal_bool                               accalm_sw;                            //ACC报警包开关
    kal_uint8                              accalm_type;                          //ACC报警类型
    kal_uint8                              accalm_time;                          //ACC报警包检测时间
    kal_uint8                              accalm_cause;                          //ACC报警包触发条件0，ACC变化触发；1，ACC变OFF触发；2，acc变ON触发 默认0
} nvram_accalm_struct;
#endif

#if defined (__CUST_BT__)
typedef struct
{
    kal_bool                               sw;                              //BT模块开关
    kal_uint8                              broadcast_time;                  //广播时间
    kal_uint8                              listen_time;                     //监听时间
    kal_uint16                             sleep_time;                      //监听时间
} nvram_bt_struct;
#endif /* __CUST_BT__ */

typedef struct
{
    kal_uint8                      sw;                   // ON/OFF 开盖报警
    kal_uint8                      alarm_type;           // M=0 仅GPRS;M=1 SMS+GPRS；默认上报方式为0
} nvram_open_shell_alarm_struct;

typedef struct
{
    kal_uint8                                   sw;                   // 声音寻车指令ON/OFF；
    kal_uint16                                 ring_time;         //响铃时间
    kal_uint16                                 delay_time;      //间隔时间
    kal_uint16                                 t_time;              //次数
} nvram_sdfind_struct;


typedef struct
{
    kal_uint8                                   sw;                   // 锂电池信息上传ON/OFF；
    kal_uint16                                 accon_up;         //
    kal_uint16                                 accoff_up;      //
} nvram_litmer_struct;

typedef struct
{
    kal_uint8                      sw;                   // bms通讯模块异常报警
    kal_uint8                      alarm_type;           // M=0 仅GPRS;M=1 SMS+GPRS；默认上报方式为0
    kal_uint8                      readtimer;//读取间隔
} nvram_bmsfault_struct;

typedef struct
{
    kal_uint8                      sw;                   // ON/OFF 非法骑行报警
    kal_uint8                      alarm_type;           // M=0 仅；默认上报方式为0
    U16 t;                   //霍尔信号输出时间(10秒)
} nvram_fride_struct;

typedef struct
{
    kal_uint8                      sw;                  // ON/OFF
    kal_uint16                     t1;                  // 上传间隔；5~18000秒，默认10秒；
    kal_uint16                     t2;                  // 持续时间(单位:分钟)，0表示无限制，默认5分钟
} nvram_sv_struct;

typedef struct
{
	kal_uint8					   sw;					//ON/OFF
	kal_uint8					   type;				//acc 检测方式：1 adc检测外电，2 obd检测,3 sensor检测 ，默认3
}nvram_acct_struct;

#if defined (__NT13V__)
typedef struct
{
    kal_uint16 count_down_time;
}nvram_device_sleep_time_struct;
#endif

#if defined (__NF2319__)
typedef struct
{
	kal_uint8					   state;					//命令参数
	kal_uint8					   speed;				//速度比例，上电默认75%
}nvram_ctrl_struct;

#endif /* __NF2319__ */
typedef struct
{
	kal_uint8 sw;//开关
	kal_uint8 interval;//采集间隔  H 默认1
}bat_temp_struct;//电池温度采集

typedef struct
{
    char                                   sos_num[4/*TRACK_DEFINE_SOS_COUNT*/][TRACK_DEFINE_PHONE_NUMBER_LEN_MAX];
    char                                   centerNumber[TRACK_DEFINE_PHONE_NUMBER_LEN_MAX];
    char                                   url[100];                       // URL设置
    kal_uint8                              monitor_delay;                  // 监听延时，范围：5-18S。默认设置 10S
    kal_uint8                              lang;                           // 1 表示为中文，0 表示为英文，用于地址查询
    kal_uint8                              gprson;                         // 1 开启GPRS   0 关闭GPRS
    kal_uint32                             hbt_acc_on;                     // 心跳包设置间隔(分钟)  ACC ON 上传间隔
    kal_uint32                             hbt_acc_off;                    // 心跳包设置间隔(分钟)  ACC OFF 上传间隔
    kal_uint8                              callmode;                       // 来电响铃方式 0 铃声 1震动 2铃声+震动  3静音
    kal_uint8                              redial_count;                   // 电话重拨次数
    kal_uint8                              monitoring_delay;               // 监听延时；0、5～18秒；设置远程监听延时；默认值为：10秒
    kal_uint8                              call_get_addr_sw;               // 来电呼叫自动返回地址（1 有效， 0 禁用）
    kal_uint16                             sensor_gps_work;                // 0～300分钟，检测到一次震动，开启 GPS 工作的时间
    kal_uint8                              led_sleep;                      // LED休眠，1 (休眠有效，跟GPS开关绑定关联同开同关)，2 (常开，与GPS开关无关), 3 (常关)
    kal_uint16                             defense_time;                   // 延时进入设防时间，默认值为：10分钟(600秒)
    kal_uint8                              oil_sw;                         // 断油电功能（1 有效， 0 禁用）
    nvram_gps_work_struct                  gps_work;                       // GPS工作模式
    nvram_vibrates_alarm_struct            vibrates_alarm;                 // 震动报警
    nvram_power_fails_alarm_struct         power_fails_alarm;              // 断电报警设置
    nvram_speed_limit_alarm_struct         speed_limit_alarm;              // 超速报警设置
    nvram_Permission_settings_struct       Permission;                     // 权限设置
    nvram_sos_alarm_struct                 sos_alarm;                      // SOS报警设置
    nvram_blind_struct                     gps_blind;                      // GPS盲区设置
    nvram_staticrep_struct                 staticrep;                      // 静止上报最后位置开关指令
    nvram_displacement_alarm_struct        displacement_alarm;             // 位移报警
    nvram_agps_struct                      agps;                           // AGPS
    nvram_boot_struct                      boot;                           // 开机报警开关
    nvram_group_package_struct             group_package;                  // 组包个数
    nvram_mileage_statistics_struct        mileage_statistics;             // 里程统计
    nvram_carpark_alarm_struct             carpark_alarm;                  // 停车超时报警
    nvram_gps_time_zone_struct             zone;                           // 时区设置
    nvram_low_power_alarm_struct           low_power_alarm;                // 低电报警设置
    nvram_fatigue_driving_alarm_struct     fatigue_driving_alarm;          // 疲劳驾驶提醒
    nvram_electronic_fence_struct          fence[TRACK_DEFINE_FENCE_SUM];  // 电子围栏设置
    nvram_motor_lock_struct                motor_lock;                     // 电动车锁电机
    nvram_work_mode_struct                 work_mode;                      // 终端工作模式
    nvram_power_extbatalm_struct           power_extbatalm;                // 外部电源低电报警
    nvram_power_extbatcut_struct           power_extbatcut;                // 外部低电切断保护
    nvram_GPRS_Obstruction_struct          gprs_obstruction_alarm;         // GPRS 阻塞报警
    nvram_door_alarm_struct                door_alarm;                     // 门报警
    nvram_obd_parameter_struct             obd;                            // OBD
    nvram_ext_vbat_check_acc_struct        vbat_check_acc;                 // GT500电压检测acc功能
    kal_uint8                              accalm_sw;                       // 0 表示为ACC切换无短信通知，1 表示为ACC切换有短信通知
    kal_uint8                              speed_limit;                     // 电动车限速阀值
    nvram_boot_struct                      pwroff;                          // 关机报警开关
    nvram_sim_alm_struct                   sim_alarm;                       // 换卡报警
    kal_uint8                              pwrlimit_sw;                     // 限制关机功能,只用于有开关机键的项目
    kal_uint8                              lcd_on_time;                     // GW100LCD自动关屏时间
    kal_int32                              adc4_offset;                     // ADC4补偿值
    kal_uint16                             mode3_work_interval;             // 休眠模式下定时上报间隔分钟
    kal_uint8                              mode3_up_counts;                 // 休眠模式下单次工作上报次数
    nvram_ext_chip_struct                  extchip;                         // extchip
    nvram_wifi_param_struct                wifi_param;                      // ap 用户名+密码
    nvram_smstc_struct                     smstc;                           // 1 开启smstc   0 关闭smstc
    kal_uint8                              defense_mode;                    // 自动设防模式 X=0  自动设防模式；X=1 手动设防模式，2 为遥控报警，默认X=1
    nvram_info_up_struct                   info_up;                         // (几米国际)外接电源电压信息上传开关
    nvram_teardown_struct                  teardown_str;                    // 防拆报警,默认开启,报警方式1,SMS+GPRS
    nvram_wifi_struct                      wifi;
    nvram_lbson_struct                     lbson;                           // LBS传点设置
    nvram_FCFALM_struct                    fcfalm;                          // 伪基站报警
    kal_uint8                              flycut;                          // 飞行模式开关
    kal_uint8                              paramFileCrc[2];                 // 在线下载配置参数文件的MD5
    kal_uint8                              dwd_epo_sw;                      // EPO下载开关
    kal_uint8                              PW5;                             // 5V电源输出状态
#if defined(__ACC_ALARM__)
    nvram_accalm_struct                    accalm;                          // 06F定制版，ACC报警
#endif
#if defined(__GT740__)
    track_work_time         cal_wk_time_struct;
    kal_uint8    new_position_sw;   //启用新定位包上传开关 默认关
    kal_uint8    cal_time_sw;    //电量次数计算开关，默认开
    nvram_gpsup_struct             gpsup_struct;    //静态补传
#endif

    kal_uint8 fake_cell_enable;     //防伪基站使能
    kal_uint8 fake_cell_to_ams;     //伪基站信息是否上报AMS

    kal_uint8 gpsDup;               //gps位置数据上报开关

#if defined (__CUST_BT__) && defined(__NT33__)
    nvram_bt_struct bt;
#endif /* __CUST_BT__ */
    kal_uint8    gpswake;  //唤醒GPS 默认0
#if defined (__GT370__)|| defined (__GT380__)
    nvram_open_shell_alarm_struct open_shell_alarm;
#endif /* __GT370__ */
    kal_uint8 fake_cell_auto_temp;  //临时自动开关防伪功能 0=临时关闭，按需恢复，0xFF=恢复后不处理
#if defined(__SPANISH__)
    kal_uint8 itp_sw;                //94包传输开关
#endif
    track_fixmode_struct fixmode;//定位优先级
    nvram_sv_struct                         sv;                             //卫星信息上传设置
    kal_uint8                               sw_nbver;                       //无电池版本设置指令
#if defined(__DROP_ALM__)
    nvram_drop_alarm drop_alm;  //跌倒报警默认开
#endif
    kal_uint8  jc_mode;//0 双向通话； 1 监听  默认值：0
    kal_uint8  answer;// 按键接听 0，自动接听 1
#if defined (__EL100__)
    char                                    ecrckey[50];                          //加密密匙
    kal_uint16                          reserve;                            //一键预约时间
    nvram_sdfind_struct           sdfind;                               //声音寻车指令
    nvram_fride_struct        sfride;
#endif /* __GB100__ */
#if defined(__SMT_BMS__)
    nvram_litmer_struct    Litimer_struct;//默认on 
    nvram_bmsfault_struct   Bmsfault_struct;//默认on 
#endif
#if defined(__NT55__)
	nvram_acct_struct 		acct;	////acc 检测方式：1 adc检测外电，2 obd检测,3 sensor检测 ，默认3
#endif

#if defined (__NT13V__)
    nvram_device_sleep_time_struct  device_sleep_time;
#endif
#if defined (__NF2319__)
    nvram_ctrl_struct        ctrl;      //控制器参数设置
#endif /* __NF2319__ */
#if defined(__NF2318__)
	ele_data_struct		ele_data;//控制器命令存储
	ste_parameter_struct 			    ste_param;//7号数据
	ste_status_struct				ste_status;//终端状态
#endif
	bat_temp_struct		bat_temp;//电池温度采集
	osd_struct			osd;//超速报警
	kal_uint8			voice_ver[4];//语音版本
	kal_uint8			bwtopen;//后轮锁开锁 单位秒*10
	kal_uint8			bwtclose;//后轮锁关锁
	kal_uint8			eletopen;//电池锁开锁
	kal_uint8			eletclose;//电池锁关锁
	kal_uint8			BMSOC;//不让bms初始化的开关，0-开  1-关
	kal_uint8			viblvoicesw;//语音报警开关，1-开0-关
	kal_uint32          voicefilesize;//已经下载的语音文件大小
	kal_uint8             encode_token[16];//20190717
	kal_uint8        bt_token_mark;
	kal_uint8       encode_token_s[50];//蓝牙密码字符串保存
	kal_uint8       new_encode_token_s[50];//蓝牙密码字符串保存
} nvram_parameter_struct;

typedef struct
{
    char                                   fn_num[TRACK_DEFINE_FN_COUNT][TRACK_DEFINE_PHONE_NUMBER_LEN_MAX];
    char                                   white_num[TRACK_DEFINE_WN_COUNT][TRACK_DEFINE_PHONE_NUMBER_LEN_MAX];
    kal_uint8                              almrep[TRACK_DEFINE_SOS_COUNT];
	//voice_list_struct voice_list;//存储需要下载的语音列表
	//kal_uint8           voice_max;//需要下载的原因总条数
} nvram_phone_number_struct;

typedef struct
{
    // nvram_importance_parameter_struct  importance_parameter;
    // char                                   sos_num[4/*TRACK_DEFINE_SOS_COUNT*/][TRACK_DEFINE_PHONE_NUMBER_LEN_MAX];
    // nvram_ext_vbat_check_acc_struct        vbat_check_acc;                 // GT500电压检测acc功能
//   kal_int32                              adc4_offset;        // ADC4补偿值
    //  kal_uint16                             sensor_gps_work;                // 0～300分钟，检测到一次震动，开启 GPS 工作的时间
    //   kal_uint8       defense_mode;                               // 自动设防模式 X=0  自动设防模式；X=1 手动设防模式，2 为遥控报警，默认X=1
    //  nvram_phone_number_struct   PHONE_NUMBER;
    kal_uint8 data[2000];
} nvram_drv_importance_backup_struct;


typedef struct
{
    kal_uint8 fake_cell_flg;
    //0=正常,无报警
    //1=检测到伪基站信息，需要继续判断GPRS
    //2=在搜到伪基站的有效时间内GPRS断网10分以上，可以报警了 ，报警后再恢复0
    //chengjun  2017-02-15

    //搜到伪基站的时间、地点缓存到AMS,最多存4个
    kal_uint8 fake_cell_count;
    kal_uint32 alm_sec[4];
    float alm_longitude[4];
    float alm_latitude[4];

    //最后一次搜到伪基站的地点
    float last_longitude;
    float last_latitude;

} fake_cell_info_notes_struct;


typedef struct
{
    kal_uint8       in_or_out[TRACK_DEFINE_FENCE_SUM];          // 电子围栏 当前是出于围栏内(1)还是围栏外(2)
    kal_uint8       lowBattery;                                 // 低电报警发送标记
    kal_uint8       lowExtBattery;                              // 外部电源低电报警发送标记
    kal_uint8       disExtBattery;                              // 外部电源断开发送标记
    kal_uint8       flag;                                       // 位移报警 标记
    float           longitude;                                  // 位移报警
    float           latitude;                                   // 位移报警
    kal_uint32      netLogControl;                              // 在线网络上报日志控制
    kal_uint8       reStartSystemCount;                         // 20分钟重启连续计数
    kal_uint8       defences_status;                            // 设防状态  1 撤防，2 预设防，3 设防
    kal_uint8       key_status;                                 // GT02D按键状态  0 关闭LED显示    1 开启LED显示
    kal_uint8       oil_status;                                 // 油电状态（0 油电正常；1 油电断开；2 请求断开，GPS未定位；3 请求断开，未发因超速延缓执行的短信；4 请求断开，已发因超速延缓执行的短信）
    kal_uint8       oil_cmd_source;                             // 断油电指令来源
    kal_uint8       acc_last_status;                            // 用于记录ACC状态，防止开机后的状态与上次关机前一致
    kal_uint8       poweroff;                                   // 低电关机报警发送标记  24byte
    kal_uint8       power_saving_mode;                          // 省电模式(0:正常模式;1:省电模式)
    kal_uint8       reconnect_send_flg;                         // 是否发送阻塞报警短信(0不发送，1发送)
    kal_uint8       restart_system_limited_service;             // L4C_RAC_LIMITED_SERVICE 重启计数
    kal_uint8       blind_status;                               // GPS盲区状态，0为进入盲区，1为盲区外
    kal_uint8       defense_mode;                               // 设防模式： 0 自动设防模式；   1 手动设防模式；   2 自动设防手动撤防；默认1
    kal_uint8       location_switch;                            // 定位数据上传开关  0 关闭  1 打开
#if !defined(__NF2318__)
    kal_uint8       timeslot[3][8][5];
#endif
    kal_uint8       disExtBattery2;                             // 外部电压6v之下报警后设置为1, 6v之上为0
    kal_uint8       sim_alm;                                    // 换卡报警标志位
    kal_uint16      flashtime;
#if defined (__LUYING__)
	kal_uint8       audio_count;                                // 音频文件数 默认0
    kal_uint8       record_time;                                // 时长，默认10
    audio_file_struct audio_file[5];                            // 音频文件
#endif
    kal_uint16      work3_countdowm;                            // 休眠模式开启工作倒计时
    kal_uint8       server_ip[4];                               // 域名解析得到的IP地址备份
    kal_uint8       oil_lock_status;                            //断油电锁定状态,0:不锁定;1:锁定 V20 433模块适用
    kal_uint8       switch_down;//防拆开关,1按下,默认0
    kal_uint8       mech_sensor_count;
    kal_uint16       mech_sensor_invel_time;
#if defined(__GT740__)
    kal_uint8        tracking_mode;//追踪模式
    kal_uint32        tracking_time;//追踪模式时间
    kal_uint8        tracking_status_mode;//原有状态模式
#endif
    kal_uint8        glp;
    kal_uint8        up_param;
    kal_uint8       ams_log;                          //710保存LOG开关
    kal_uint8       ams_push;                         //710上传LOG开关
    kal_uint8       TPRO_COUNT;                       //定位包协议次数
    kal_uint8       nw_reset_sign;                    // 联网重启标记
#if defined (__BAT_TEMP_TO_AMS__)
    kal_int8        temperature_data[70][5];
    kal_uint8       temp_count;
#endif /* __BAT_TEMP_TO_AMS__ */

    kal_uint8       power_fails_flg;
#if defined(__CUST_FAKECELL__)
    fake_cell_info_notes_struct fake_cell_info_notes;   //防伪基站消息记录
#endif
    U16  MainCellId;
    kal_uint8       nw_sign;                    // 重启标志
    kal_uint32      logBlocksEnd;               // log end
    kal_uint32      logBlocksBegin;             // log begin
    kal_uint8       AMS_HEX_sw_log;             // sw_log
    kal_uint16      lock_status;                 //锁状态

#if defined (__LUYING__)
    kal_uint8         record_file;//存在文件的录音的开始个数
    kal_uint8         record_up;//上传到平台的录音的开始个数
    kal_uint8         record_cnt;//录音的开始总个数
    kal_uint8         record_stamp[6];
    kal_uint8         record_last_time;
#endif /* __LUYING__ */
#if defined(__NF2318__)//以上43
	kal_uint8 		acc_alarm;//acc告警状态1 告警  0  解除告警
	kal_uint8		controller_alarm;//控制器通讯故障 1 告警  0 解除
	kal_uint8       rearwheelalarm;//后轮锁异常告警
	kal_uint8       elelockalarm;//电池锁异常告警
	nvram_http_server_struct  http_server;//http文件下载参数存储
	kal_uint8           file_update_style;//已经对比完版本信息 有固件更新 00000001 有语音更新 00000010  
	kal_uint8			fota_update;//固件升级标识
	//kal_uint8 ele;//电机状态 0  不锁 1 锁
	kal_uint8 wheel;//后轮锁状态0 不锁 1锁
	kal_uint8 exbatlock;//电池锁状态 0 不锁 1 锁
	kal_uint16      lock_counts;//锁车次数
	kal_uint16      unlock_counts;//开锁次数
	kal_uint16		exbat_lockcounts;//电池锁关锁次数
	kal_uint16		exbat_unlockcounts;//电池锁开锁次数
	kal_uint8		sleep;//当前休眠状态 0 无休眠 15半休眠  16 全休眠
	kal_uint8		httpdowncount;//httpy一天内未下载成功计数
	kal_uint8		httpdowndate[3];//日期
	voice_list_struct voice_list;//存储需要下载的语音列表
	kal_uint8           voice_max;//需要下载的音源总条数
	kal_uint8 voice_version_tmp[4];//临时存储语音版本号
	kal_uint32      temp_voicesize;//临时存放本次语音下载的总大小
	kal_uint8  bms_alarm[7];//bms状态报警#endif	
	kal_uint8       acc_fault_alarm;//ACC异常报警标志，1告警//20190715} nvram_realtime_struct;
	kal_uint8   controller_alarm_type[5];
	//-------------20191010
	kal_uint8 lesea_off_to_sta;//0没有关锁动作 1 正在走关锁流程 2 关锁流程走完但是后轮锁失败
	kal_uint8 lesea_off_to_volume_sta;//连续关锁是否播放语音 0 第一次播放  1已经播放过了  不播放
#endif
} nvram_realtime_struct;


/*****************************************************************************
* Local variable            局部变量
*****************************************************************************/


/****************************************************************************
* Global Variable           全局变量
*****************************************************************************/


/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/
extern nvram_parameter_struct G_parameter;
//extern nvram_realtime_struct G_realtime_data;
extern nvram_importance_parameter_struct G_importance_parameter_data;
extern nvram_phone_number_struct G_phone_number;
extern nvram_parameter_struct* OTA_NVRAM_EF_PARAMETER_DEFAULT ;
extern nvram_importance_parameter_struct* OTA_NVRAM_EF_IMPORTANCE_PARAMETER_DEFAULT  ;
extern  nvram_phone_number_struct* OTA_NVRAM_EF_PHONE_NUMBER_DEFAULT;
extern   nvram_ef_logd_struct* OTA_NVRAM_EF_LOGD_DEFAULT;
extern   nvram_realtime_struct* OTA_NVRAM_EF_REALTIME_DEFAULT ;
/*****************************************************************************
 *  Local Functions	            本地函数
*****************************************************************************/
static void track_system_bootup_delay(void);

/*****************************************************************************
 *  Global Functions            全局函数
*****************************************************************************/

#endif /* __TRACK_DISK_NVRAM__ */


#endif  /* _TRACK_PARAMETE_H */


