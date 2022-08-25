#if defined(__NF2318__)
/*******************************************************************************************
 * Filename:track_cust_controller_protocol.h
 * Author :Liujw
 * Date :2017-08-02
 * Comment:7号电单车控制器串口通讯协议
 *通讯方式：串口通讯（TTL0V-5V）。 波特率：9600bps，8bit数据位，1位停止位，无校验位。 
 ******************************************************************************************/
 /**引用头文件**/
#include "track_cust.h"
#include "track_os_ell.h"
/*
*局部变量定义
*/
/*
*
*
*/
void track_cust_status_recover(void);

extern void track_cust_module_speed_limit(track_gps_data_struct *gps_data,kal_uint8 tmpspeed);
#if 0
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
	kal_uint8 barCode[16];//成品条形码
	kal_uint8 versionNum[2];//版本号
	kal_uint8 valtageManufacturer[16];//电池制造厂商
	kal_uint8 relativeCapacityPer;//相对容量百分比
	kal_uint8 absoluteCapacityPer;//绝对容量百分比
}struct_controller_data;
#endif
#endif
