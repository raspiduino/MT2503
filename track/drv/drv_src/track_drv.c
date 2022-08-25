/******************************************************************************
 * track_drv.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        驱动层允许外界访问的唯一接口集 ，由上层注册实体
 *
 * modification history
 * --------------------
 * v1.0   2012-07-26,  chengjun create this file
 *
 ******************************************************************************/

/****************************************************************************
* Include Files             包含头文件
*****************************************************************************/
#include "track_drv.h"
#include "track_cust_main.h"

/*****************************************************************************
 *  Define			    宏定义
*****************************************************************************/


/*****************************************************************************
* Typedef  Enum         枚举
*****************************************************************************/


/*****************************************************************************
 *  Struct			    数据结构定义
*****************************************************************************/


/*****************************************************************************
* Local variable            局部变量
*****************************************************************************/


/****************************************************************************
* Global Variable           全局变量
*****************************************************************************/


/****************************************************************************
* Global Variable - Extern          引用全局变量
*****************************************************************************/


/*****************************************************************************
 *  Global Functions	- Extern	    引用外部函数
*****************************************************************************/
extern void track_query_sim_type(kal_int8 sim_type);
/*****************************************************************************
 *  Local Functions	            本地函数
*****************************************************************************/


/*****************************************************************************
 *  Global Functions            全局函数
*****************************************************************************/
/******************************************************************************
 *  Function    -  track_drv_gps_decode_done
 * 
 *  Purpose     -  一次完整nmea 数据包解码完成
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 03-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_gps_decode_done(track_gps_data_struct *track_gps_data)
{
    if(track_gps_data->gw_mode == BD)
    {
        memcpy(&track_gps_data->gprmc, &track_gps_data->bdrmc, sizeof(track_gps_data->gprmc));
        memcpy(&track_gps_data->gpgga, &track_gps_data->bdgga, sizeof(track_gps_data->gpgga));
        memcpy(&track_gps_data->gpgsa, &track_gps_data->bdgsa, sizeof(track_gps_data->gpgsa));
        memcpy(&track_gps_data->gpgsv, &track_gps_data->bdgsv, sizeof(track_gps_data->gpgsv));
    }
    track_cust_gps_decode_done(track_gps_data);
}

/******************************************************************************
 *  Function    -  track_drv_gps_decode_ttff
 * 
 *  Purpose     -  本次GPS 打开，首次定位时间 （TTFF）
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 04-03-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_gps_decode_ttff(void)
{
    track_factoty_autotest_gpscold_ttff();
}
   
/******************************************************************************
 *  Function    -  track_drv_charger_bmt_status
 *
 *  Purpose     -  充电电池消息注册拦截
 *
 *  Description -  status : 充电电池状态
 *                       level : 电池电量等级
 *                       volt : 电池电压值(具体值得/1000000 )
 * Sample:

     switch(status)
    {
        // 充电状态
        case PMIC_USB_CHARGER_IN:
        case PMIC_CHARGER_IN:
            //track_pmic_charger_in_status();
            break;

        //充电拔出事件
        case PMIC_USB_NO_CHARGER_OUT:
        case PMIC_USB_CHARGER_OUT:
        case PMIC_CHARGER_OUT:
            //track_pmic_charger_out_status();
            break;

        //充电完成状态
        case PMIC_CHARGE_COMPLETE:
            //track_pmic_charger_completed_status();
            break;

        case PMIC_VBAT_STATUS:
            {
                //截取电压值
                switch(level)
                {
                    //低电关机事件
                    case BATTERY_LOW_POWEROFF:
                        //track_pmic_batter_low_poweroff_status();
                        break;

                    case BATTERY_LOW_TX_PROHIBIT:
                        break;

                    // 低电警告状态
                    case BATTERY_LOW_WARNING:
                        //track_pmic_batter_low_warning_status();
                        break;

                    //正常工作状态
                    case BATTERY_LEVEL_0:
                    case BATTERY_LEVEL_1:
                    case BATTERY_LEVEL_2:
                    case BATTERY_LEVEL_3:
                        //track_pmic_batter_normal_status();
                        break;

                    default:
                        break;
                }

                break;
            }

        case PMIC_INVALID_BATTERY:
        case PMIC_OVERBATTEMP:
        case PMIC_OVERVOLPROTECT:
        case PMIC_OVERCHARGECURRENT:
        case PMIC_LOWBATTEMP:
        case PMIC_CHARGING_TIMEOUT:
        case PMIC_INVALID_CHARGER:
        case PMIC_LOWCHARGECURRENT:
        case PMIC_CHARGE_BAD_CONTACT:
        case PMIC_BATTERY_BAD_CONTACT:
        case PMIC_USB_NO_CHARGER_IN:
            break;

        default:
            break;
    }
 *
 * 电量消息每分钟一次，充电事件立即响应
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 27-07-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_charger_bmt_status(pmic_status_enum status, battery_level_enum level, kal_uint32 volt)
{
    track_cust_chargestatus_vbtstatus_check(status, level, volt);
}

/******************************************************************************
 *  Function    -  track_drv_external_batter_measure_done
 * 
 *  Purpose     -  外电检测完成
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 11-03-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_external_batter_measure_done(kal_int32 ext_volt)
{
    //track_cust_external_batter_measure_done(ext_volt);
}

/******************************************************************************
 *  Function    -  track_drv_eint_trigger_response
 *
 *  Purpose     -  中断响应注册
 *
 *  Description -  eint :  中断口序号
 *                                 (参考eint_var.c 或者track_interrupt.h)
 *                       level : 当前端口电平
 *                                 (可能接三极管集电极输入，检测到的电平和实际相反)
 *
 *   初始化由驱动完成
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 27-07-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_eint_trigger_response(U8 eint, U8 level)
{
    track_cust_eint_trigger_response(eint, level);
}

/******************************************************************************
 *  Function    -  track_drv_remind_sim_type
 * 
 *  Purpose     -  SIM 卡状态更新
 * 
 *  Description - 开机5 秒后执行一次

 * sim_type : 0=无卡/1=有普通SIM 卡/ 2=有测试卡/-1=异常/  
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 28-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_remind_sim_type(kal_int8 sim_type)
{
    /*在下面添加不同SIM 卡的处理*/
    track_query_sim_type(sim_type);//白卡
}

/******************************************************************************
 *  Function    -  track_drv_watch_dog_close
 * 
 *  Purpose     -  封闭关闭外部看门狗152模块函数
 * 
 *  Description - 

 * shutdown : 0=关闭提供给152的喂狗信号，终端将在下一个周期被152重启
 *            1=关闭152后关机
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 28-9-2013,  wangqi  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_watch_dog_close(kal_uint8 shutdown)
{
    LOGD(L_DRV, L_V5, "%d",shutdown);
#if defined (__NETWORK_LICENSE__)
    LOGS("test mode (restart disable)");
#else
#if defined( __WATCH_DOG__)
    track_drv_watdog_close(shutdown);
#else
    if(shutdown)
    {
        LOGS("====colse watch dog====");
        LOGS("====device power off====");
        track_drv_sys_power_off_req();
    }
#endif /* __WATCH_DOG__ */
#endif
}
