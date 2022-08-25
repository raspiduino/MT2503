/******************************************************************************
 * track_project_cmd.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        各项目特殊的指令解析，优先级最高，和标准版同名的，只解析本文件的指令
 *
 * modification history
 * --------------------
 * v1.0   2017-06-30,  chengjun create this file
 *
 ******************************************************************************/

/****************************************************************************
* Include Files                         包含头文件
*****************************************************************************/
#include "track_os_data_types.h"
#include "kal_public_defs.h"
#include "track_os_log.h"
#include "track_cmd.h"

#include "track_cust.h"
#include "Conversions.h"
#include <math.h>
#include "us_timer.h"
#include "uem_context.h"
#include "track_at_call.h"
#include "track_os_ell.h"
#include "track_nvram_default_value.h"
#include "track_version.h"
#include "track_os_paramete.h"

/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/


/*****************************************************************************
* Typedef  Enum         枚举
*****************************************************************************/


/*****************************************************************************
 *  Struct                              数据结构定义
 *****************************************************************************/
typedef void(*Func_CustRecvPtr)(CMD_DATA_STRUCT*);

typedef struct
{
    const char           *cmd_string;
    Func_CustRecvPtr     func_ptr;
    BOOL                valid;
} track_project_cmd_table_struct;

/*****************************************************************************
 *  Global Functions			全局变量
 *****************************************************************************/


/*****************************************************************************
 *  Local Functions			本地函数
 *****************************************************************************/
 static void track_cust_cmd_device_time_count_down(void);


 void track_cust_device_sleep_time_init(void)
{
    LOGD(L_APP, L_V5, "sleep %d", G_parameter.device_sleep_time.count_down_time);
    if(G_parameter.device_sleep_time.count_down_time == 0)
    {
        return;
    }
    
    track_cust_flymode_set(51);//进入飞行
    if(G_parameter.device_sleep_time.count_down_time > 10)
    {
        tr_start_timer(TRACK_CUST_DEVICE_SLEEP_TIME_COUNT_DOWN_TIMER_ID, 600 * 1000, track_cust_cmd_device_time_count_down);
    }
    else
    {
        tr_start_timer(TRACK_CUST_DEVICE_SLEEP_TIME_COUNT_DOWN_TIMER_ID, G_parameter.device_sleep_time.count_down_time * 60 * 1000, track_cust_cmd_device_time_count_down);
    }
}

static void track_cust_cmd_device_time_count_down(void)
{
    LOGD(L_APP, L_V5, "sleep %d", G_parameter.device_sleep_time.count_down_time);
    
    if(G_parameter.device_sleep_time.count_down_time > 10)
    {
        G_parameter.device_sleep_time.count_down_time -= 10;
        if(G_parameter.device_sleep_time.count_down_time > 10)
        {
            tr_start_timer(TRACK_CUST_DEVICE_SLEEP_TIME_COUNT_DOWN_TIMER_ID, 600 * 1000, track_cust_cmd_device_time_count_down);
        }
        else
        {
            tr_start_timer(TRACK_CUST_DEVICE_SLEEP_TIME_COUNT_DOWN_TIMER_ID, G_parameter.device_sleep_time.count_down_time * 60 * 1000, track_cust_cmd_device_time_count_down);
        }
    }
    else
    {
        track_cust_flymode_set(50);//退出飞行
        G_parameter.device_sleep_time.count_down_time = 0;
    }
    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
}

static void cmd_sleep(CMD_DATA_STRUCT *cmd)
{
    nvram_device_sleep_time_struct sleep = {0};
    kal_int32 var;

    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d", cmd->pars[0], G_parameter.device_sleep_time.count_down_time);
        return;
    }

    if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }

    memcpy(&sleep, &G_parameter.device_sleep_time, sizeof(nvram_device_sleep_time_struct));

    var = track_fun_atoi(cmd->pars[1]);
    if(var < 0  || var > 36000)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (0-36000)");
        return;
    }

    sleep.count_down_time = (kal_uint16)var; 

    memcpy(&G_parameter.device_sleep_time, &sleep, sizeof(nvram_device_sleep_time_struct));

    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }

    if(G_parameter.device_sleep_time.count_down_time > 0)
    {
        track_cust_flymode_set(51);//进入飞行
        if(G_parameter.device_sleep_time.count_down_time > 10)
        {
            tr_start_timer(TRACK_CUST_DEVICE_SLEEP_TIME_COUNT_DOWN_TIMER_ID, 600 * 1000, track_cust_cmd_device_time_count_down);
        }
        else
        {
            tr_start_timer(TRACK_CUST_DEVICE_SLEEP_TIME_COUNT_DOWN_TIMER_ID, G_parameter.device_sleep_time.count_down_time * 60 * 1000, track_cust_cmd_device_time_count_down);
        }
    }
    else
    {
        if(G_parameter.device_sleep_time.count_down_time != 0)
        {
            track_cust_flymode_set(50);//退出飞行
        }
    }
}

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/

//TRUE  表示使用项目自定义的功能，覆盖标准版
//FALSE 表示不支持该指令，同时标准版的也不会执行
static track_project_cmd_table_struct track_project_cmd_table[] =
{
    {"WF", NULL,   FALSE},
    {"SLEEP", cmd_sleep,   TRUE},
};


kal_bool track_project_command(CMD_DATA_STRUCT * cmd)
{
    int i, size, ret;
    kal_bool find = KAL_FALSE, pass_status = KAL_FALSE;
    size = sizeof(track_project_cmd_table) / sizeof(track_project_cmd_table_struct);

    LOGD(L_APP, L_V5, "num_type:%d, len:%d, data:%s   [%d/%d]%s|%s|%s|%s|%s",
         cmd->return_sms.num_type, cmd->rcv_length, cmd->rcv_msg_source, cmd->part, size, cmd->pars[0], cmd->pars[1], cmd->pars[2], cmd->pars[3], cmd->pars[4]);

    if(cmd->rcv_length >= 1024)
    {
        return KAL_TRUE;
    }

    for(i = 0; i < size; i++)
    {
        ret = strcmp(cmd->pars[0], track_project_cmd_table[i].cmd_string);
        LOGD(L_APP, L_V9, "ret=%d|%s,%s|%p", ret, cmd->pars[0], track_project_cmd_table[i].cmd_string, track_project_cmd_table[i].cmd_string);
        if(!ret)
        {
            find = KAL_TRUE;
            cmd->rsp_length = 0;
            memset(cmd->rsp_msg, 0, sizeof(cmd->rsp_msg));
            track_is_sms_cmd(1);

            if(!track_project_cmd_table[i].valid)
            {
                LOGD(L_APP, L_V5, "this project disable %s", cmd->pars[0]);
                return KAL_TRUE;
            }

            pass_status = track_cmd_check_authentication(cmd);
            if(cmd->supercmd == 1 || cmd->return_sms.cm_type != CM_SMS || pass_status)
            {
                if(track_project_cmd_table[i].func_ptr != NULL)
                {
                    track_is_recv_cmd_after_boot(1);
                    track_project_cmd_table[i].func_ptr(cmd);
                    break;
                }
            }
            else
            {
                LOGD(L_APP, L_V4, "Password error!");
                sprintf(cmd->rsp_msg, "Password error!");      //密码错误
            }
            break;
        }
    }
    if(find)
    {
        /*  指令解析执行体只填充信息，全部在此发出*/
        track_cust_cmd_reply(&cmd->return_sms, cmd->rsp_msg, cmd->rsp_length);
        return KAL_TRUE;        // 执行操作后删除短信
    }
    else
    {
        LOGD(L_APP, L_V5, "invalid project command!");
        return KAL_FALSE;
    }
}

