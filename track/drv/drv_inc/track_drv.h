/******************************************************************************
 * track_drv.h - 
 * 
 * Copyright .
 * 
 * DESCRIPTION: - 
 *        驱动层对外接口 
 * 
 * modification history
 * --------------------
 * v1.0   2012-07-26,  chengjun create this file
 * 
 ******************************************************************************/
#ifndef DRV_INC_H
#define DRV_INC_H
/****************************************************************************
* Include Files             包含头文件                                             
*****************************************************************************/
#include "GlobalConstants.h"
#include "track_drv_gps_drive.h"
#include "track_drv_gps_decode.h"
#include "track_drv_led.h"
#include "track_drv_pmu.h"
#include "track_drv_eint_gpio.h"
#include "track_drv_lbs_data.h"
#include "track_drv_system_param.h"
#include "track_drv_sensor.h"
#include "track_drv_key.h"
#include "track_drv_bt.h"
#include "track_drv_smartBms.h"
#include "track_os_paramete.h"

/*****************************************************************************
 *  Define			    宏定义
*****************************************************************************/
#if defined __GPS_MT3333__
#define GPS_UART_PORT               uart_port2
#define U_TX            12 
#define U_TX_M          1
#define U_RX            17
#define U_RX_M          1
#elif defined(__BD_AT6558__)
#define GPS_UART_PORT               uart_port3
#define U_TX                1
#define U_TX_M          3
#define U_RX                0
#define U_RX_M          3
#else
#define GPS_UART_PORT               uart_port2
#define U_TX            21 
#define U_TX_M          1
#define U_RX            20
#define U_RX_M          1
#endif

#define RUNING_TIME_SEC ((kal_get_systicks() - 0) / KAL_TICKS_1_SEC)

#define BD_ADDR_SIZE 6


/***************************************************************************** 
* Typedef  Enum         枚举
*****************************************************************************/


/*****************************************************************************
 *  Struct			    数据结构定义
*****************************************************************************/
typedef struct _BD_ADDR
{
    U8 addr[BD_ADDR_SIZE];
} BD_ADDR;

/*****************************************************************************
 *  Global Functions            全局函数
*****************************************************************************/



/*****************************************************************************
* Local variable				 局部变量
*****************************************************************************/

/****************************************************************************
* Global Variable - Extern			 引用全局变量
*****************************************************************************/
#if defined (__BLE_GATT__)
extern BD_ADDR track_bt_addr;
#endif


/*************GPS***********/
/****************************************************************************/
 /****************************************************************************
 * Function  :   track_drv_gps_switch
 
 * Description : GPS 开关
 
 * Parameters
 *  status: [in] 
 *     0=关闭
 *     1=优先开热启动，开不了就冷启动
 *     2=冷启动
 *
 * Return
 *  0=关/1=本次为热启动/2=本次为冷启动
 *  error:  -1=本次操作和先前相同不执行/-2= 传入参数错误

 ***************************************************************************/
extern kal_int8 track_drv_gps_switch(U32 status);
 /****************************************************************************
 * Function  :   track_drv_gps_cold_restart
 
 * Description : GPS 冷启动(先关闭GPS，清除星历，再启动)
 
 * Parameters
 
 * Return
 *  none

 ***************************************************************************/
extern void track_drv_gps_cold_restart(void);
  /****************************************************************************
 * Function  :   track_drv_gps_claer_eph
 
 * Description : 清除GPS 星历
 
 * Parameters
 *   
 * Return
 *  none

 ***************************************************************************/
extern void track_drv_gps_claer_eph(void);

 /****************************************************************************
 * Function  :   track_drv_get_gps_
 
 * Description : 读取GPS 解析后的数据
 
 * Parameters
 *  gps_zda: [IN] memcpy 最新数据
 
 * Return
 *  none

 ***************************************************************************/
extern gps_gpgga_struct * track_drv_get_gps_GGA(void);
extern gps_gpgsa_struct * track_drv_get_gps_GSA(void);
extern gps_gpgsv_struct * track_drv_get_gps_GSV(void);
extern gps_gprmc_struct* track_drv_get_gps_RMC(void);
extern gps_gpvtg_struct * track_drv_get_gps_VTG(void);
extern track_gps_data_struct * track_drv_get_gps_data(void);

/****************************************************************************/
/*********** Sensor**********/
/****************************************************************************/
/******************************************************************************
 *  Function    -  track_drv_sensor_on
 * 
 *  Description     -  开启sensor 检测
 * 
 *  Parameters   level  [in] : sensor 检测灵敏度等级 
 *                       FuncPtr  [in] : sensor 触发回调函数
 * 
 * Return
 *  
 ******************************************************************************/
extern kal_int8 track_drv_sensor_on(kal_uint8 level , FuncPtr FuncPtr);
/******************************************************************************
 *  Function    -  track_drv_sensor_off
 * 
 *  Description     -  关闭sensor 检测
 * 
 *  Parameters   no
 * 
 * Return
 *  
 ******************************************************************************/
extern kal_int8 track_drv_sensor_off(void);
/******************************************************************************
 *  Function    -  track_drv_sensor_threshold_start
 * 
 *  Description     -  开启sensor 检测
 * 
 *  Parameters   threshold  [in] : sensor 检测灵敏度 
 *                       FuncPtr  [in] : sensor 触发回调函数
 * 
 * Return
 *  none
 ******************************************************************************/
extern void track_drv_sensor_threshold_start(kal_uint8 threshold , FuncPtr callback);
/******************************************************************************
 *  Function    -  track_drv_get_sensor_type
 * 
 *  Description     -  获取sensor 类型
 * 
 *  Parameters   no
 * 
 * Return
 *  sensor_type_enum
 ******************************************************************************/
extern sensor_type_enum track_drv_get_sensor_type(void);
/****************************************************************************/
/*********** Interrupt ***** **/
/****************************************************************************/
//注册拦截


/****************************************************************************/
/******* Charge batter ********/
/****************************************************************************/
extern void track_drv_bmt_charging_result(char *bmt);

 /****************************************************************************
 * Function  :   track_drv_get_batter_voltage
 
 * Description :读取电池电压
 
 * Parameters 
 *   
 * Return
 *  返回值需要/1000000 才是真实结果
 *
 ***************************************************************************/
extern kal_int32 track_drv_get_batter_voltage(void);

 /****************************************************************************
 * Function  :   track_drv_get_external_batter
 
 * Description :读取外部充电电瓶的电压值
 
 * Parameters   flag [in]   
 *
 *  0 = 获取外电测量ADC原始值
 *  1 = 获取外接电池电压
 *   
 * Return
 *  返回值需要/1000000 才是真实结果
 *
 ***************************************************************************/
extern kal_int32 track_drv_get_external_batter(kal_uint8 flag);
 /****************************************************************************
 * Function  :   track_drv_sleep_enable
 
 * Description : 禁止/允许中断休眠
 
 * Parameters   
 *                     mod   [in]  控制的模块
                        enable [in]  TRUE   =  允许休眠
 *                                        FALSE = 禁止休眠
 * Return
 *    
 *      -1=参数错误
 *      -2=已经允许休眠
 *      -3=已经禁止休眠
 *      1=进入休眠
 *      0=退出休眠
 *
 ***************************************************************************/
extern kal_int8 track_drv_sleep_enable(sleep_mod_enum mod ,BOOL enable);

/******************************************************************************
 *  Function    -  track_drv_check_sleep_status
 * 
 *  Purpose     -  查询驱动休眠状态
 * 
 * Return -  8bite 
 *                        bite 位为0表示该模块禁止休眠，有一位为0即表示没有休眠
 *                        return 0xFF 表示现在全部进入休眠
 * ----------------------------------------
 ******************************************************************************/
kal_uint8 track_drv_check_sleep_status(void);
/****************************************************************************/
  /****************************************************************************
 * Function  :   track_drv_led_status_lock
 
 * Description : LED 指示灯控制
 
 * Parameters
 *       status [in]   1     =  锁LED 状态，后续操作无效/  0 = 解锁
 *                       0xFF  =  查询当前锁状态
 * 
 * Return
 *  当前锁状态
 *  -1 = 参数错误
 *  
 ***************************************************************************/
extern kal_int8 track_drv_led_status_lock(U8 status);
/****************************************************************************/
/*************LBS***********/
/****************************************************************************/
 /****************************************************************************
 * Function  :   track_drv_lbs_info_switch
 
 * Description : LBS 开关
 
 * Parameters
 *  status: [in] 0=关/1=开
 
 * Return
 *  0=关/1=开
 * -1=本次操作和先前相同不执行/-2= 传入参数错误

 ***************************************************************************/
extern kal_int8 track_drv_lbs_info_switch(U8 status);
 /****************************************************************************
 * Function  :   track_drv_get_lbs_data
 
 * Description : 读取LBS  解析后的数据
 
 * Parameters
 *  
 
 * Return
 *  &Last_Multi_Cell_Info

 ***************************************************************************/
extern LBS_Multi_Cell_Data_Struct * track_drv_get_lbs_data(void);
/****************************************************************************
 * Function  :   track_drv_convert_rxlev_to_rssi
 
 * Description : 基站信号等级逆转换为信号强度
 
 * Parameters
 * rxlev :[in] 基站信号等级 
 
 * Return
 *  信号强度

 ***************************************************************************/
extern kal_int16 track_drv_convert_rxlev_to_rssi(kal_int16 rxlev);
/****************************************************************************
 * Function  :   track_drv_get_service_cell_level
 
 * Description : 获取服务小区信号等级
 
 * Parameters
 * no
 
 * Return
 *  主基站信号等级( GSM 信号强度参考值)
 
 *  正常范围0-31
 *  0xFF 表示无效值

 ***************************************************************************/
extern kal_uint8 track_drv_get_service_cell_level(void);

/****************************************************************************/
/**********Watch dog*********/
/****************************************************************************/
/******************************************************************************
 *  Function    -  track_drv_watdog_init
 * 
 *  Description     -  初始化看门狗
 * 
 *  Parameters   no
 * 
 * Return
 *  none
 ******************************************************************************/
extern void track_drv_watdog_init(void);


/****************************************************************************/
/********** GPIO ********/
/****************************************************************************/
 /****************************************************************************
 * Function  :   track_drv_gpio_cut_oil_elec
 
 * Description : 切断/恢复油电
 
 * Parameters   state [in]  1   =  切断油电
 *                                     0   =  恢复油电
 *   
 * Return
 *   0/1   =  执行成功
 *    -1    =  GPIO 操作失败
 *
 *  IO 口初始化由驱动完成
 ***************************************************************************/
extern kal_int8 track_drv_gpio_cut_oil_elec(kal_int8 state);
/****************************************************************************/
/********** time ********/
/****************************************************************************/
/******************************************************************************
 *  Function    -  track_drv_utc_timezone_to_rtc
 * 
 *  Description    时区校准
 * 
 *  Parameters   
 *  in_dt [in]  时间日期
 *  timezone [in] 时区
 * 
 * Return
 *  out_dt [out] 校准后的时间日期

*备注
*  track_drv_utc_timezone_to_rtc -将GTM0 校准到当前时区
*  track_drv_rtc_to_gmt0 - 将本地时间日期逆转到GMT0
 ******************************************************************************/
extern void track_drv_utc_timezone_to_rtc(applib_time_struct *out_dt, applib_time_struct *in_dt, nvram_gps_time_zone_struct timezone);

extern void track_drv_rtc_to_gmt0(applib_time_struct *out_dt, applib_time_struct *in_dt, nvram_gps_time_zone_struct timezone);

/******************************************************************************
 *  Function    -  track_drv_update_time_to_system
 * 
 *  Description    将时间日期下载到终端 
 * 
 *  Parameters   
 *  utcTime [in]  时间日期
 * 
 * Return
 *  none
 ******************************************************************************/
extern void track_drv_update_time_to_system(applib_time_struct utcTime);


/****************************************************************************/
/********** system param ********/
/****************************************************************************/
/******************************************************************************
 *  Function    -  track_drv_get_imei/track_drv_get_imsi
 * 
 *  Description    读取终端IMEI /IMSI
 * 
 *  Parameters   
 *  flag [in]         0     = 获取ASCII 码字符
 *                其他 = 获取十六进制
 * Return
 *  kal_uint8 *
 * 
 *  示例备注
 *   IMEI ="353419030099621"
                03 53 41 90 30 09 96 21 
*    IMSI="460021075219613"
                04 60 02 10 75 21 96 13 
                
 * 0=字符串，其他是16 进制数组，其中最高位补0
 * 不插卡时IMSI  全0
 ******************************************************************************/
extern kal_uint8* track_drv_get_imei(kal_uint8 flag);
extern kal_uint8* track_drv_get_imsi(kal_uint8 flag);
/******************************************************************************
 *  Function    -  track_drv_get_chip_id
 * 
 *  Description   获取基带芯片随机ID
 * 
 *  Parameters   该值意义不大
 * 
 * Return
 *  kal_uint8* 
 *
 * chip_rid 是随机值，不是唯一的，重复的概率为1/2 的128 次方
 ******************************************************************************/
extern kal_uint8* track_drv_get_chip_id(void);

/******************************************************************************
 *  Function    -  track_drv_get_sim_type
 * 
 *  Purpose     -  查询SIM 卡状态/类型
 * 
 *  Parameters   
 *  no
 * 
 * Return
 *  0=无卡/1=有普通SIM 卡/ 2=有测试卡/-1=未初始化/-2=异常/
 * 
 ******************************************************************************/
extern kal_int8 track_drv_get_sim_type(void);

/******************************************************************************
 *  Function    -  Track_nvram_read/Track_nvram_write
 * 
 *  Purpose     -  NVRAM 读写操作
 * 
 *  Parameters   
 * 
 * Return
 * 
 ******************************************************************************/
extern kal_bool Track_nvram_read(nvram_lid_enum LID, kal_uint16 rec_index, void *buffer, kal_uint32 buffer_size);
extern kal_bool Track_nvram_write(nvram_lid_enum LID, kal_uint16 rec_index, void *buffer, kal_uint32 buffer_size);

extern kal_bool track_drv_epo_aid_interface();
extern void track_cust_secset_interface();
extern void track_Drv_gps_glp_Set(void* op);
extern void track_drv_set_gps_glp_mode(U8 arg);
extern void track_cust_aiding_reftime (applib_time_struct *currTime);
#endif
