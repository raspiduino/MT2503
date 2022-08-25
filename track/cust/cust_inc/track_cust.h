#ifndef _TRACK_CUST_H
#define _TRACK_CUST_H

/****************************************************************************
*  Include Files                        包含头文件
*****************************************************************************/
#include "MMIDataType.h"
#include "app_datetime.h"
#include "track_cust_main.h"
#include "track_at_sms.h"
#include "track_drv_Eint_gpio.h"
#include "track_drv.h"
#include "track_cmd.h"
#include "track_fun_common.h"
#include "track_soc_Lcon.h"
#include "track_cust_paket.h"
#include "track_cust_led.h"
#include "track_cust_audio.h"
#include "c_RamBuffer.h"
#include "track_os_ell.h"
#include "track_os_paramete.h"
#include "track_cust_wifi.h"
/*****************************************************************************
*  Define                               宏定义
**************************
****************************************************/
#define TRACK_ALARM_DELAY_TIME_SECONDS 120000     /* 报警延时 */

#define TRACK_MAX_LOOP                 20

#define VOICE_FILES_SIZE				4194304//4*1024*1024

#if defined(__GT740__)
#define  LOWER_BATTERY_LEVEL 3600000
#else
#define  LOWER_BATTERY_LEVEL 3650000
#endif
#if defined( __GT740__)
#define MAX_RUN_TIME_MIN 5
#endif

#define DEFAULT_FEB_TIMESEC 1422748800
#define DEFAULT_SYS_TIMESEC 1420070400
#define RUNING_TIME_SEC ((kal_get_systicks() - 0) / KAL_TICKS_1_SEC)
extern kal_bool g_GT03D;

#if defined (__LUYING__)
#define  RECORD_INTERVAL   30
#endif

typedef enum
{
    sw_hallsig_alm=0,
    sw_bms_comm_lock,
    sw_max
}sw_type;

#define LOCATION_MODE_TIMEOUT_SEC 30

#if defined( __TRACK_DISK_NVRAM__)
typedef enum
{
    NVRAM_EF_PARAMETER_LID            =  0,
    NVRAM_EF_IMPORTANCE_PARAMETER_LID ,
    NVRAM_EF_PHONE_NUMBER_LID,
    IMPORT_PARAM_ORG_LID,
    DISK1_LAST_LID,
    DISK1_BACKUP_LID,
    NVRAM_EF_LOGD_LID,
    NVRAM_EF_REALTIME_LID,
    NVRAM_EF_GPS_BACKUP_DATA_LID,
    DISK1_NVRAM_MAX
} DISK1_NVRAM_ITEM;
#endif /* __TRACK_DISK_NVRAM__ */

#define OBD_FILE_PATH           "OBD.BIN"
#define OBD_MD5_FILE_PATH       "OBD.MD5"
#define FOTA_FILE_PATH          "TRACK.BIN"
#define FOTA_MD5_FILE_PATH      "TRACK.MD5"

#define OTA_FILE_PATH_TMP       "test.tmp"
#define OTA_FILE_PATH           "test.ell"
#define MD5_FILE_PATH           "test.md5"


//static char  *s_ON = {"ON"}, *s_OFF = {"OFF"}, *s_Error = {"ERROR"};
#define ON_OFF(value) (value==0? ("OFF"):(value==1?("ON"):("ERROR")))

/*****************************************************************************
*  Typedef  Enum                        枚举定义
*****************************************************************************/
#if defined(__NF2318__)	
typedef enum
{
	ALARM_EXBAT_LOW = 0x00,//备用电池低电报警
	ALARM_VIB		= 0x01,//震动报警
	ALARM_OPEN_ACC	= 0x02,//非法打开电门锁报警
	ALARM_BMS_WARNING = 0x03,//BMS异常报警
	ALARM_CHARGE_OUT = 0x04,//断电报警
	ALARM_MOVING	= 0x05,//轮动报警
	ALARM_VEHICLE_FAULT = 0x06,//车辆故障报警
	ALARM_BT_ALARM		= 0x07,//蓝牙模块通讯异常报警
	ALARM_CONTROLER_WARNING 	= 0x08,//控制器通讯报警
	ALARM_EXBAT_LOCK_WARNING		= 0x09,//电池锁报警
	ALARM_REARWHEEL_LOCK_WARNING	= 0x10,//后轮涨闸锁告警
	ALARM_BMS_COV = 0x11,//过压保护
	ALARM_BMS_CUV = 0x12,//低压保护
	ALARM_BMS_OC = 0x13,//充电电流保护
	ALARM_BMS_TOVER2 = 0x14,//低温温度保护
	ALARM_BMS_LEVEL1_OLOAD = 0x15,//放电过流一级
	ALARM_BMS_LEVEL2_OLOAD = 0x16,//放电过流二级
	ALARM_BMS_TOVER = 0x17,//高温温度保护 
	ALARM_CONTROLLER_LOCKED_ROTOR = 0x22,//堵转保护
	ALARM_CONTROLLER_FLYING_CAR = 0x23,//防飞车保护
	ALARM_CONTROLLER_UNDER_VOLTAGE = 0x24,//欠压保护
	ALARM_CONTROLLER_HOLZER_FAULT = 0x25,//电机霍尔故障
	ALARM_CONTROLLER_MALFUNCTION = 0x26,//转把故障
	ALARM_ACC_FAULT = 0X27,//acc故障与预期结果不符合
}enum_no7_alarm_type;//终端报警信息
#endif
typedef enum
{
    TR_CUST_ALARM_NORMAL                    =    0,   //正常
    TR_CUST_ALARM_SOS                       =    1,   //SOS 求救
    TR_CUST_ALARM_PowerFailure              =    2,   //断电报警
    TR_CUST_ALARM_Vibration                 =    3,   //震动报警
    TR_CUST_ALARM_InFence                   =    4,   //进围栏报警
    TR_CUST_ALARM_OutFence                  =    5,   //出围栏报警
    TR_CUST_ALARM_Speed_Limit               =    6,   //超速报警
    
    TR_CUST_ALARM_displacement              =    9,   //位移报警
    TR_CUST_ALARM_IN_blind                  = 0x0A,   //进GPS盲区报警
    TR_CUST_ALARM_OUT_blind                 = 0x0B,   //出GPS盲区报警
    TR_CUST_ALARM_boot                      = 0x0C,   //开机报警
    TR_CUST_ALARM_gps_successfully          = 0x0D,   //GPS第一次定位报警
    TR_CUST_ALARM_Ext_LowBattery            = 0x0E,   //外电低电报警
    TR_CUST_ALARM_Ext_PowerFailure          = 0x0F,   //外电低电保护报警
    TR_CUST_ALARM_SIM_ALARM                 = 0x10,   //换卡报警
    TR_CUST_ALARM_PWROFF                    = 0x11,   //手动按键关机提醒
    TR_CUST_ALARM_Ext_LowBattery_Fly        = 0x12,   //外电低电保护后进入飞行模式提醒
    TR_CUST_ALARM_PRE_REMOVE                = 0x13,   //拆卸报警  
    TR_CUST_ALARM_door                      = 0x14,   //门报警
    TR_CUST_ALARM_LowBattery_PWROFF         = 0x15,   //内部电池低电即将关机提醒
    TR_CUST_ALARM_SOD                       = 0x16,   //声控报警
    TR_CUST_ALARM_FAKECELL                  = 0x17,   //伪基站报警
    TR_CUST_ALARM_OPEN_SHELL                = 0x18,   //开盖报警（拆外壳）
    TR_CUST_ALARM_LowBattery                = 0x19,   //低电报警
    TR_CUST_ALARM_INTO_DEEP_SLEEP_MODE      = 0x20,   //进入深度休眠报警
    TR_CUST_ALARM_ACC_ON                    = 0x21,   //ACC开（实际值应该是0xFE，但由于非连续值，影响代码逻辑判断）
    TR_CUST_ALARM_ACC_OFF                   = 0x22,   //ACC关（实际值应该是0xFF，但由于非连续值，影响代码逻辑判断）
    TR_CUST_ALARM_DROP_ALM                  = 0x23,   //跌倒报警
    TR_CUST_ALARM_CHARGE_IN_ALM             = 0x24,   //充电器接入报警
    
    //                                      = 0x62,   //等于98，特殊用途
    //                                      = 0x63,   //等于99，特殊用途
    
    //                                      = 0xFE,   //已占用
    //                                      = 0xFF,   //已占用
    TR_CUST_ALARM_MAX
}enum_alarm_type;

typedef enum
{
    MOTOR_UNLOCK,       // 0
    MOTOR_LOCK,
    MOTOR_ACC_LOW,      // 2
    MOTOR_ACC_HIGH,
    MOTOR_REQ,          // 4
    MOTOR_END_REQ,
    MOTOR_END1,         // 6
    MOTOR_END2,
    MOTOR_END3,         // 8
    MOTOR_END4,
    MOTOR_END5,         // 10
    MOTOR_END6,
    MOTOR_END7,         // 12
    MOTOR_SENSOR_IND
} track_enum_motor;

typedef enum
{
    GPS_STAUS_OFF,       // 0
    GPS_STAUS_ON,
    GPS_STAUS_SCAN,      // 2
    GPS_STAUS_2D,
    GPS_STAUS_3D          // 4
} track_enum_gps_staus;

typedef enum
{
	WF_FIX=0,
	GPS_FIX,
	LBS_FIX
}track_location_level;
/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/
typedef struct
{
    kal_bool            addUrl;
    Cmd_Type            cm_type;
    char                phone_num[CM_HEAD_PWD_MXA];
    char                msg_en[CM_PARAM_LONG_LEN_MAX];
    char                msg_cn[CM_PARAM_LONG_LEN_MAX];
    kal_uint16          msg_cn_len;
    kal_uint8           stamp[4];               // 标记位，当前用于网络下发的指令需要保存服务器提供的序列号
    kal_uint8           not_need_almrep;//不需要验证almrep为1,需要验证为0
   kal_uint8            is_sos_alarm_type;//是否为sos报警类型
} struct_msg_send;
typedef enum
{
    SMS_NORMAL_MODE,     //正常模式
    SMS_AIRPLANE_MODE,   //飞行模式
} track_enum_sms_staus;

/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/
extern nvram_parameter_struct G_parameter;
extern nvram_realtime_struct G_realtime_data;
extern nvram_importance_parameter_struct G_importance_parameter_data;
extern nvram_phone_number_struct G_phone_number;
extern kal_uint8 set_ele_lock;//0-不锁 1-锁

/*****************************************************************************
*  Functions Define                     函数声明
******************************************************************************/
extern char *track_get_app_version(void);
extern track_gps_data_struct * track_drv_get_gps_data(void);

extern float track_fun_get_GPS_2Points_distance(float lat1, float lon1, float lat2, float lon2);

extern void track_cust_init(void);
extern void track_cust_sensor_init(void);
extern void track_cust_gps_decode_done(track_gps_data_struct *track_gps_data);
extern void track_cust_eint_trigger_response(U8 eint, U8 level);
extern void track_cust_chargestatus_vbtstatus_check(pmic_status_enum status, battery_level_enum level, kal_uint32 volt);
extern void track_cust_periodic_restart(void *arg);
extern void track_cust_call_incomming_number(char *inc_number);
extern void track_cust_call_status(kal_uint16 callState);
extern void track_cust_call(char *number);
extern void track_cust_call_hangup(void);
extern void track_cust_call_accept(void);
extern char *track_cust_call_get_incomming_number(void);
extern void track_cust_net_conn(void);
extern void track_cust_sms_send(kal_uint8 number_type, char *number, kal_bool isChar, kal_uint8 *data, kal_uint16 len);
extern void track_cust_module_get_addr(CMD_DATA_STRUCT *cmd);
extern void track_cust_module_recv_addr(char *number, kal_uint8 *content, int content_len, kal_uint16 sn);
extern void track_cust_module_power_fails(void *arg);
extern void track_cust_module_alarm_vibrates(void *arg);
extern kal_bool track_cust_module_alarm_msg_send(struct_msg_send *msg, track_gps_data_struct *gps_data);
extern void track_cust_status_defences_change(void *arg);
extern void track_cust_add_position(void);
extern void track_cust_paket_13(kal_uint8* data, kal_uint16 *len, kal_uint16 *sn);
extern kal_uint16 track_cust_paket_1A(track_gps_data_struct *gd, char *number);
extern kal_uint16 track_cust_paket_position(track_gps_data_struct *gd, LBS_Multi_Cell_Data_Struct *lbs, kal_uint8 packet_type, kal_uint8 packet_status);
extern void cust_packet_log(kal_uint8 errorid, kal_uint8 type, kal_uint8 filter, kal_uint16 sn, float _distance, float lat, float lon);
extern kal_uint8 track_cust_make_call(void *arg);
extern track_gps_data_struct *track_cust_backup_gps_data(kal_uint8 type, track_gps_data_struct *new_data);
extern kal_bool track_is_testmode(void);
extern kal_int8 track_cust_get_sim_status(void);
extern nvram_gps_time_zone_struct* track_mcc_to_timezone(void);
extern void track_cust_write_sim_backup_for_parameter(void);
extern void track_soc_gprs_reconnect(void *arg);
extern void track_soc_disconnect(void);
extern void track_check_tick(kal_uint8 st, char *outstring);
extern void track_cust_sim_backup_for_parameter(void);
extern void track_cust_led_first_start(void);
extern track_enum_gps_staus track_cust_gps_status(void);
extern void track_cust_module_alarm_blind(void);
//extern void track_cust_alarm_boot(void);
extern void track_cust_alarm_gps_successfully(void);
extern track_gps_data_struct *track_cust_gpsdata_alarm(void);
//extern void track_cust_stop_update_LBS(void);
//extern void track_cust_update_LBS(void);
extern enum_alarm_type track_cust_alarm_type(enum_alarm_type type);
extern void track_cust_gps_send_data(kal_uint32 status);
extern kal_uint8 track_cust_get_work_mode(void);
extern void track_cust_gps_check_nofix(kal_uint8 flag);
extern char *track_domain_decode(kal_uint8 *data);
extern void track_domain_encode(char *src, kal_uint8 *dec);
extern void track_cust_gps_off_req(void *arg);
extern void track_cust_gps_work_req(void *arg);
extern kal_uint16 track_get_incall_type(void);
extern void track_cust_check_sos_incall(CMD_DATA_STRUCT * Cmds, kal_int8 state);
extern void track_cust_agps_start(void);
extern kal_bool track_cust_is_upload_UTC_time(void);
kal_uint8 track_project_save_switch(U8 op, sw_type type);
extern void track_cust_set_vcama(kal_bool ON, kal_uint32 ldo_volt);
extern void track_cust_send_lbs(void *par);
extern void track_cust_get_lbs_data(void * arg);
extern void track_cust_instant_contract_position_data(kal_uint8 flag);
extern void track_cust_secset_interface();
extern void track_cust_aiding_reftime (applib_time_struct *currTime);
extern void track_drv_ext_vbat_measure_modify_parameters();
extern void heartbeat_packets(void *arg);

#if defined(__FLY_MODE__)
extern kal_bool track_cust_flymode_set(U32 mode);
extern kal_bool track_cust_isbatlow(void);
#endif /* __FLY_MODE__ */

#if defined(__WIFI__)
extern void track_drv_wifi_work_mode(void);
extern void track_cust_sensor_to_rest_supp_wifihot();
#endif /* __WIFI__ */
#if defined(__NOFIX_GPSDUP__)
extern void track_gps_no_location_dup_updata(void);
#endif
extern void led_level_state_switch();
extern void track_cust_sendlbs_limit(void);
extern U32 track_cust_mode3_extchange(U32 startTime_mins, U16 interval_mins);
extern void track_cust_mode1_gpsfix_overtime();
extern kal_bool track_is_notquit(void);
#if defined(__NF2318__)
extern void track_cust_N07_paket_87(kal_uint8 *data,kal_uint16 len);
extern void track_cust_no7_paket_88(kal_uint8 *data,kal_uint16 len);
extern void track_cust_N07_paket_02(track_gps_data_struct * gd, LBS_Multi_Cell_Data_Struct * lbs);
extern void track_vechile_status_msg(U8 type,U8 status);
extern kal_uint8 track_cust_vehicle_moving(U8 from);
extern void track_mode_shift(void* arg);
extern void track_bms_struct_copy(controller_data_struct *c_data_struct);
extern void track_cust_get_controller_data(vehicle_status_struct *v_status);
extern U8 track_getIsDownLoadFile();
extern void track_cust_shock_overtime();
extern void track_cust_lease_on_precondition(void* arg);
#endif
#endif  /* _TRACK_CUST_H */


