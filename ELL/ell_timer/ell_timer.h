/******************************************************************************
 * track_os_timer.h -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        自定义定时器
 *
 * modification history
 * --------------------
 * v1.0   2012-07-15,  chengjun create this file
 *
 ******************************************************************************/
#ifndef _ELL_TIMER_H
#define _ELL_TIMER_H

/****************************************************************************
* Include Files             包含头文件
*****************************************************************************/
#include "kal_public_defs.h"

/*****************************************************************************
 *  Define			    宏定义
*****************************************************************************/


/*****************************************************************************
* Typedef  Enum         枚举
*****************************************************************************/
typedef enum
{
/*DRV begin*/
    ELL_WATCH_DOG_TIMER_ID,
/*DRV end*/
    
/*NET begin*/
    ELL_RESTART_TIMER_ID,
    ELL_20MIN_RESTART_TIMER_ID,
    ELL_SOCKET_SEND_TIMER_ID,
    ELL_SOC_TIMEOUT_TIMER_ID,
    ELL_SOC_CONN_TIMEOUT_TIMER_ID,
    ELL_SOC_RECONNECT_TIMER_ID,
    ELL_SOC_SEND_TIMER_ID,
    ELL_SOC_SEND_OVER_TIMER_ID,
    ELL_SERVER_OVERTIME_TIMER_ID,
    ELL_SERVER_SEND_REQ_OVERTIME_TIMER_ID,
    ELL_SEND_DATA_OVERTIME_TIMER_ID,
/*NET end*/

    /* Imp: Please do not modify this */
    MAX_NUM_OF_ELL_TIMER,
} ell_timer_enum;


/*****************************************************************************
 *  Struct			    数据结构定义
*****************************************************************************/
typedef void (*FuncPtr) (void);
typedef void (*Func_Ptr)(void *);

/*****************************************************************************
* Local variable            局部变量
*****************************************************************************/

/****************************************************************************
* Global Variable           全局变量
*****************************************************************************/

/*****************************************************************************
 *  Local Functions	            本地函数
*****************************************************************************/

/*****************************************************************************
 *  Global Functions            全局函数
*****************************************************************************/
/*
void track_os_intoTaskMsgQueue(kal_hisr_func_ptr app);
void track_os_intoTaskMsgQueueExt(kal_timer_func_ptr app, void *arg);
void track_os_task_expiry(void *local_para_ptr);*/
#endif  /* _ELL_TIMER_H */
