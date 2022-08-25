/*******************************************************************************************
 * Filename:track_cust_platform_N07.h
 * Author :Liujw
 * Date :2017-07-31
 * Comment:7号电单车云平台通讯协议
 ******************************************************************************************/
#if !defined(__NUM_SEVEN__)
#define __NUM_SEVEN__
/**引用头文件**/
#include "track_cust.h"
#include "track_os_ell.h"
/*
*局部变量定义
*/
/*
*结构体定义
*/
typedef enum
{
    SYSTEM_RESET = 0x00,//系统重启后的登陆
    RECONNECT = 0x01, //通信链路故障恢复后的登陆
    SERVERID_CHANGE = 0x02,//域名切换后的登陆
    WAKEUP = 0x03,//全休眠恢复后的登陆
    FOTA_UPDATE = 0x04,//固件更新后登陆
    LOGINMAX = 99//最大
} enum_login_reason; //登陆原因

typedef enum
{
    RESET_NO_RESION,//未知原因重启
    RESET_GPS_10MIN,//gps10分钟输出错误，重启
    RESET_NO_LOGIN, //gprs30分钟未登陆成功
    RESET_NO_HEARTBEAT,//未收到心跳包
    RESET_HEARTBEAT_NOTARRIVE,//心跳包超时没有收到
    RESET_REVISE_USER,//用户被修改
    RESET_REVISE_SIM,//终端sim卡被修改
    RESET_RECEIVE_ACTIVATE_SMS,//收到激活短信
    RESET_RECEIVE_RELOGIN_SMS,//收到重登陆指令
    RESET_RESETTING_SMS_ONLINE,//收到用户发送的复位指令
    RESET_SHUTDOWM_SMS_ONLINE,//收到用户发送的关机指令
    RESET_NOACTIVATE_SMS_ONLINE,//用户下发免激活指令
    RESET_APN_CHANGED,//APN被修改时
    RESET_SERVER_CHANGED,//域名被修改
    RESET_ONLINE_MODE_CHANGED,//上网模式改变
    RESET_COMM_MODE_CHANGED,//TCP、UDP切换后
    RESET_TID_CHANGED,//终端的TID被修改
    RESET_GSENSOR_ERROR,//当gsensor经过一定的次数还没有修复后
    RESET_SIM_IN,//当sim卡插入时
    RESET_SUPERNUM_CHANGED,//当终端的超级号码更改时
    RESET_PDP_ACTIVATED_MORE,//当设备的PDP激活次数超过系统规定的时间时，重启一次系统
    RESET_LOADERROR_FROM_FLASH,//设备从FLASH中加载重启原因发生错误
    RESET_REMOTE_UPDATE,//设备远程升级之后的自动重启功能
    RESET_FACTORY,//用户下发格式化指令
    RESET_SELF_CHECKING,//系统自修复重启机制
} enum_reset_type;

typedef enum
{
    CMD_KEEPBYTE = 0x00,//保留
    CMD_FORTIFICATION   = 0x01,//远程设防
    CMD_DISCARM = 0x02,//远程撤防
    CMD_REMOTE_RESET = 0x03,//远程重启
    CMD_REMOTE_SHUTDOWN = 0x04,//远程关机
    CMD_FACTORY = 0x05,//恢复出厂设置
    //0x06 0x07保留
    CMD_GPS_FIX = 0x08,//立即定位
    CMD_FIND_CAR = 0x09,//寻车
    CMD_RESET_BT = 0x0A,//重启蓝牙
    CMD_UNLOCKING = 0x0B,//远程开锁
    CMD_LOCKING = 0x0C,//远程加锁
    CMD_BAT_STATUS = 0x0D,//查询终端电池信息
    CMD_CONTROLLER = 0x0E,//主动查询控制器信息
    CMD_OPEN_BAT = 0x0F,//远程打开电池锁
    CMD_CLOSE_BAT = 0x10,//远程关闭电池锁
    CMD_CLOSE_FINDCAR = 0x11,//远程关闭寻车
    CMD_RESET_ALL = 0x12,//远程重启整个系统
    CMD_FACTORY_CONTRALLER = 0x13,//格式化主控制器
    CMD_EXUSB_ENABLE = 0x14,//外部usb使能
    CMD_EXUSB_DISABLE = 0x15,//外部usb失能
    CMD_OPEN_BOSS_OF_WHEEL = 0x16,//远程打开轮毂锁
    CMD_CLOSE_BOSS_OF_WHEEL = 0x17,//远程关闭轮毂锁
} enum_control_command; //控制指令

typedef enum
{
    MOD_BT7 = 1,//蓝牙功能
    MOD_WIFI = 2,//wifi功能
    MOD_EXBAT_LOCK = 4,//电池锁功能
    MOD_LOUDSPEAKER = 8,//语音喇叭功能
    MOD_SMS_CONTROL = 10,//短信控制功能
    MOD_MESSAGE_COLLECTION = 20,//一线制控制信息采集
} enum_fun_module; //终端功能

typedef struct
{
    kal_uint8 borrow;//车辆借还状态 1-还车状态 0-借车状态
    kal_uint8 moving;//车辆运动状态 1-运动状态 0-静止状态
    kal_uint8 ele_locking;//电机加锁状态 1-电机为解锁状态 0-电机为加锁状态
    kal_uint8 acc_status;//车辆acc状态 1-供电装填 0 断电状态
    kal_uint8 sleeping;//车辆休眠状态 0- 车辆未休眠 1- 车辆半休眠 2-车辆全休眠
    kal_uint8 bt_connect;//蓝牙连接状态 1-蓝牙为连接状态 0-蓝牙为未连接状态
    kal_uint8 bat_lock;//电池锁状态 1-电池锁加锁状态 0-电池锁打开状态
    kal_uint8 riding;//终端骑行状态 1-车辆为骑行装填 0-车辆为非骑行状态
    kal_uint8 exbat_in;//外接电池是否在位 1外接电源在位 0-外接电源不在位
    kal_uint8 handle_status;//转把可使用状态 1-转把可使用可拧把骑行 0-转把失败，可使用助力
    kal_uint8 behind_wheel;//车辆后轮锁状态 1-后轮解锁状态 0-后轮加锁状态
} struct_terminal_status; //终端的一些实时状态


extern void track_cust_no7_paket_86(U8 exeresult, U8 result, kal_uint8* id);
extern void track_cust_no7_paket_8C(U8 *voiceid, U8 exe);
extern kal_uint8 get_speed(void);
extern U8 AUDIO_file_play(kal_uint8 *audioID);
#endif

