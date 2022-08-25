#if !defined(__NF2318__)
/*******************************************************************************************
 * Filename:
 * Author :
 * Date :
 * Comment:
 ******************************************************************************************/

/****************************************************************************
*  Include Files                        包含头文件
*****************************************************************************/
#include "track_cust.h"

/*****************************************************************************
*  Define                               宏定义
******************************************************************************/

/*****************************************************************************
*  Typedef  Enum                        枚举定义
*****************************************************************************/

/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/


/*****************************************************************************
*  Local variable                       局部变量
*****************************************************************************/
static kal_uint8 g_lock_status = 0;   // 0 不在锁电机流程中  1 锁电机流程中  2 准备退出锁电机
static kal_uint8 g_acc_status = 0;
static kal_bool  g_req_end = KAL_FALSE;
/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/

/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/
extern kal_uint8 track_cust_status_acc(void);
//extern kal_uint8 track_cust_motor_lock(kal_int8 value);

/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/
static void lock_change_from_timer(void *arg);
//void track_motor_lock_change_status(track_enum_motor par);
#if 0
#endif /* 0 */
/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/

/******************************************************************************
 *  Function    -  lock_change
 *
 *  Purpose     -  锁电机的流程
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void lock_change(track_enum_motor par)
{
    LOGD(L_APP, L_V6, "锁电机状态变化 %d,%d", par, g_lock_status);
    switch(par)
    {
        case MOTOR_UNLOCK:
        {
            if(g_lock_status == 0)    
            {
                return;
            }
            if(track_cust_status_charger() == 0)
            {
                LOGD(L_APP, L_V4, "ERROR: 外电被断开，锁电机流程 退出");
                track_cust_motor_lock(0);
                return;
            }
            if(g_acc_status == 0)
            {
                LOGD(L_APP, L_V5, "解锁电机动作取消，并结束锁电机流程，因为当前电平已经是低电平，处于解锁状态");
            }
            else
            {
                LOGD(L_APP, L_V5, "解锁，等待 ACC低 状态确认 解锁成功");
                // 解锁，等待 ACC低 状态确认 (这里是否出现解锁了ACC不变为低的情况)
                track_cust_motor_lock(0);
                track_start_timer(
                    TRACK_CUST_MODULE_MOTOR_LOCK_STATUS_OVERTIME_TIMER_ID, 
                    2000, 
                    lock_change_from_timer, 
                    (void *)MOTOR_END1);
            }
        }
        break;
        
        case MOTOR_LOCK:
        {
            if(g_lock_status == 0)    
            {
                return;
            }
            if(track_cust_status_charger() == 0)
            {
                LOGD(L_APP, L_V4, "ERROR: 外电被断开，锁电机流程 退出");
                track_cust_motor_lock(0);
                return;
            }
            if(g_acc_status == 1)
            {
                LOGD(L_APP, L_V5, "锁电机动作取消，并结束锁电机流程，因为当前电平已经是高电平，处于锁电机状态");
                lock_change(MOTOR_END2);
            }
            else
            {
                LOGD(L_APP, L_V5, "锁电机，等待 ACC高 状态确认 锁成功");
                // 锁电机，由于电机不能长时间持续锁，会导致电机损坏，因此锁与解锁交替进行
                track_cust_motor_lock(1);
                track_start_timer(
                    TRACK_CUST_MODULE_MOTOR_LOCK_STATUS_OVERTIME_TIMER_ID, 
                    2000, 
                    lock_change_from_timer, 
                    (void *)MOTOR_END3);
            }
        }
        break;
        
        case MOTOR_END1: // 解锁失败，可以判定是当前钥匙开启，正常退出锁电机流程
        {
            if(track_cust_status_charger() != 0)
            {
                track_cust_motor_lock(0);
                // 终止锁电机流程
                track_stop_timer(TRACK_CUST_MODULE_MOTOR_LOCK_STATUS_OVERTIME_TIMER_ID);
                track_stop_timer(TRACK_CUST_MODULE_MOTOR_LOCK_CINTINUE_TIMER_ID);
                track_stop_timer(TRACK_CUST_MODULE_MOTOR_LOCK_TIMER_ID);
                g_lock_status = 0;
                LOGD(L_APP, L_V5, "钥匙插入 锁电机流程 结束");
                acc_status_high();
                return;
            }
        }
        case MOTOR_END2: // 锁动作之前已经检测到ACC高，可以判定当前钥匙开启
        case MOTOR_END3: // 锁电机异常，判断是否未接外电
        case MOTOR_END4: // 振动触发锁电机流程延时结束，锁电机流程结束
        case MOTOR_END5: // ACC低 当前锁电机流程已经被标记为需要退出
        case MOTOR_END6: // ACC高 当前锁电机流程已经被标记为需要退出
        {
            if(track_cust_motor_lock(99) == 1)
            {
                track_cust_motor_lock(0);
                g_req_end = KAL_TRUE;
            }
        }
        case MOTOR_END7: // 触发锁电机流程，流程结束，锁电机流程中未再次检测到振动被延时工作
        {
            if(g_acc_status)
            {
                LOGD(L_APP, L_V5, "请求 锁电机流程结束 %d", par);
                g_req_end = KAL_TRUE;
            }
            else
            {
                LOGD(L_APP, L_V5, "锁电机流程 结束");
                g_lock_status = 0;
            }
            track_cust_motor_lock(0);
            // 终止锁电机流程
            track_stop_timer(TRACK_CUST_MODULE_MOTOR_LOCK_STATUS_OVERTIME_TIMER_ID);
            track_stop_timer(TRACK_CUST_MODULE_MOTOR_LOCK_CINTINUE_TIMER_ID);
            track_stop_timer(TRACK_CUST_MODULE_MOTOR_LOCK_TIMER_ID);
        }
        break;
    }
}

/******************************************************************************
 *  Function    -  lock_change_from_timer
 *
 *  Purpose     -  超时的函数调用
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void lock_change_from_timer(void *arg)
{
    kal_uint32 par = (kal_uint32)arg;
    LOGD(L_APP, L_V5, "%d", par);
    lock_change((track_enum_motor)par);
}

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/

/******************************************************************************
 *  Function    -  track_motor_lock_change_status
 *
 *  Purpose     -  锁电机动作调用接口
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_motor_lock_change_status(track_enum_motor par)
{
    if(G_parameter.motor_lock.sw == 0)
    {
        return;
    }

    LOGD(L_APP, L_V6, "锁电机外部请求 %d,%d", par, g_lock_status);

    switch(par)
    {
        case MOTOR_SENSOR_IND:
        {
            if(g_lock_status == 0)
            {
                if(G_parameter.motor_lock.mode == 1 && g_acc_status == 0 && track_cust_status_defences() == 2)
                {   // 设防状态下，检到震动立即锁电机
                    track_motor_lock_change_status(MOTOR_REQ);
                }
            }
        }
        break;
        
        case MOTOR_ACC_LOW:
        {
            g_acc_status = 0;
            if(g_lock_status == 0)
            {
                return;
            }
            if(g_req_end)
            {
                g_lock_status = 0;
                lock_change(MOTOR_END5);
                LOGD(L_APP, L_V5, "锁电机流程时间到 退出");
                return;
            }
            if(track_cust_status_charger() == 0)
            {
                LOGD(L_APP, L_V4, "ERROR: 外电被断开，锁电机流程 退出");
                track_cust_motor_lock(0);
                return;
            }
            // 等待 ACC低 通知，启动延时检测
            LOGD(L_APP, L_V5, "解锁成功。当前收到ACC低的信号，延时%d毫秒锁电机", G_parameter.motor_lock.lock_off_time);
            track_stop_timer(TRACK_CUST_MODULE_MOTOR_LOCK_STATUS_OVERTIME_TIMER_ID);
            track_start_timer(
                TRACK_CUST_MODULE_MOTOR_LOCK_TIMER_ID, 
                G_parameter.motor_lock.lock_off_time, 
                lock_change_from_timer, 
                (void *)MOTOR_LOCK);
        }
        break;

        case MOTOR_ACC_HIGH:
        {
            g_acc_status =1;
            if(g_lock_status == 0)
            {
                return;
            }
            if(g_req_end)
            {
                g_lock_status = 0;
                lock_change(MOTOR_END6);
                LOGD(L_APP, L_V5, "锁电机流程时间到 退出");
                return;
            }
            if(track_cust_status_charger() == 0)
            {
                LOGD(L_APP, L_V4, "ERROR: 外电被断开，锁电机流程 退出");
                track_cust_motor_lock(0);
                return;
            }

            // 在检测时间内出现ACC高，确认是用户钥匙解锁，停止继续锁电机的动作
            LOGD(L_APP, L_V5, "锁成功。当前收到ACC高的信号 延时%d毫秒解锁电机", G_parameter.motor_lock.lock_on_time);
            // 处于锁电机的状态下，忽略ACC检测结果
            track_stop_timer(TRACK_CUST_MODULE_MOTOR_LOCK_STATUS_OVERTIME_TIMER_ID);
            track_start_timer(
                TRACK_CUST_MODULE_MOTOR_LOCK_TIMER_ID, 
                G_parameter.motor_lock.lock_on_time, 
                lock_change_from_timer, 
                (void *)MOTOR_UNLOCK);
        }
        break;

        case MOTOR_REQ:
        {
            // 锁电机流程请求
            if(track_cust_status_charger() == 0)
            {
                LOGD(L_APP, L_V4, "ERROR: 外电未接入");
                return;
            }
            else if(track_cust_status_defences() != 2)
            {
                LOGD(L_APP, L_V4, "ERROR: 未处于设防状态");
                return;
            }
            else if(g_acc_status == 1)
            {
                LOGD(L_APP, L_V4, "ERROR: ACC处于高");
                return;
            }
            if(g_lock_status == 0)
            {
                g_lock_status = 1;
                g_req_end = KAL_FALSE;
                LOGD(L_APP, L_V5, "锁电机流程启动");
                lock_change(MOTOR_LOCK);
                track_start_timer(
                    TRACK_CUST_MODULE_MOTOR_LOCK_CINTINUE_TIMER_ID, 
                    G_parameter.motor_lock.lock_continue_time * 1000, 
                    lock_change_from_timer, 
                    (void *)MOTOR_END7);
            }
            else
            {
                LOGD(L_APP, L_V5, "Sensor 延长 锁电机流程");
                // 锁电机流程中，检测到振动，锁电机持续时间顺延
                track_start_timer(
                    TRACK_CUST_MODULE_MOTOR_LOCK_CINTINUE_TIMER_ID, 
                    G_parameter.motor_lock.lock_continue_time * 1000, 
                    lock_change_from_timer, 
                    (void *)MOTOR_END4);
            }
        }
        break;

        case MOTOR_END_REQ:
        {
            LOGD(L_APP, L_V5, "请求锁电机流程结束");
            lock_change(MOTOR_END7);
        }
        break;
    }
}

/******************************************************************************
 *  Function    -  track_cust_motor_lock_status_check
 *
 *  Purpose     -  锁电机状态查询
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_bool track_cust_motor_lock_status_check(void)
{
    if(g_lock_status == 0 || G_parameter.motor_lock.sw == 0)
    {
        return KAL_FALSE;
    }
    else
    {
        return KAL_TRUE;
    }
}
#endif
