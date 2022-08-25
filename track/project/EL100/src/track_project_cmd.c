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
#include "track_os_paramete.h"
#include "track_nvram_default_value.h"
#include "track_cust.h"
/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/
//#define ON_OFF(value) (value==0?s_OFF:(value==1?s_ON:s_Error))


/*****************************************************************************
* Typedef  Enum         枚举
*****************************************************************************/


/*****************************************************************************
 *  Struct                              数据结构定义
 *****************************************************************************/
static char  *s_ON = {"ON"}, *s_OFF = {"OFF"}, *s_Error = {"ERROR"};

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
static void cmd_unlock(CMD_DATA_STRUCT *cmd)
{
    if(!strcmp(cmd->pars[1], "STATUS"))
    {
        sprintf(cmd->rsp_msg, "%s:%d", cmd->pars[0], G_realtime_data.lock_status);
        return;
    }
    if(!strcmp(cmd->pars[2], "ON"))
    {
        G_realtime_data.lock_status = 1;
    }
    else if(!strcmp(cmd->pars[2], "OFF"))
    {
        G_realtime_data.lock_status = 0;
    }
    if(strlen(cmd->pars[1]) != 0)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(track_is_timer_run(TRACK_CUST_SDFIND_TIMER_ID))
    {
        track_stop_timer(TRACK_CUST_SDFIND_TIMER_ID);
        //track_cust_infinite_ring_stop_voice();
        //track_cust_audio_play_voice(6/*MT_DISCONNECT*/);
    }
    if(track_is_timer_run(TRACK_CUST_LED_RESERVE_TIMER_ID))
    {
        track_stop_timer(TRACK_CUST_LED_RESERVE_TIMER_ID);
        track_cust_key_led_sleep();
    }

    sprintf(cmd->rsp_msg, "OK!");
}

static void cmd_reserve(CMD_DATA_STRUCT * cmd)
{
    int value = 0;
    kal_bool flag = 1;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d", cmd->pars[0], G_parameter.reserve);
        return;
    }
    if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(strlen(cmd->pars[1]) > 0)
    {
        value = track_fun_atoi(cmd->pars[1]);
        if(value < 1 || value > 60)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 1 (1-60)");
            return;
        }
        G_parameter.reserve = value;
    }
    track_cust_reserve();
    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
    sprintf(cmd->rsp_msg, "OK!");
}


/******************************************************************************
 *  Function    -  cmd_sdfind
 *
 *  Purpose     -  声音寻车指令
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 28-02-2017,  ZengPing  written
 * ----------------------------------------
 ******************************************************************************/
void cmd_sdfind_ring(kal_uint16 index)
{
    static kal_uint16 timer = 0;

    LOGD(L_APP, L_V6, "index = %d,timer=%d,t_time=%d", index, timer, G_parameter.sdfind.t_time);
    if(index == 0)
    {
        timer = 0;
    }

    if(index == 0 || index == 1)
    {
        timer++;
        //track_cust_play_amr_infinite_ring(7);
        if(timer < G_parameter.sdfind.t_time)
        {
            track_start_timer(TRACK_CUST_SDFIND_TIMER_ID, G_parameter.sdfind.ring_time * 1000, cmd_sdfind_ring, (void *)2);
        }
        else
        {
            track_start_timer(TRACK_CUST_SDFIND_TIMER_ID, G_parameter.sdfind.ring_time * 1000, cmd_sdfind_ring, (void *)3);
        }
    }
    else if(index ==  2)
    {
        //track_cust_infinite_ring_stop_voice();
        track_start_timer(TRACK_CUST_SDFIND_TIMER_ID, G_parameter.sdfind.delay_time * 1000, cmd_sdfind_ring, (void *)1);
    }
    else
    {
        //track_cust_infinite_ring_stop_voice();
        //track_cust_audio_play_voice(6/*MT_DISCONNECT*/);
    }
}

static void CMD_FRIDE(CMD_DATA_STRUCT * cmd)
{
    nvram_fride_struct alarm = {0};
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s,%d,%d", cmd->pars[0],
                ON_OFF(G_parameter.sfride.sw), G_parameter.sfride.alarm_type, G_parameter.sfride.t);
        return;
    }
    memcpy(&alarm, &G_parameter.sfride, sizeof(nvram_fride_struct));
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part < 1 || cmd->part > 3)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 1;
        if(cmd->part >= 2)
        {
            alarm.alarm_type = track_fun_atoi(cmd->pars[2]);
            if(alarm.alarm_type != 0)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (Only 0)");
                return;
            }
        }

        if(cmd->part == 3)
        {
            alarm.t = track_fun_atoi(cmd->pars[3]);
            if(alarm.t < 1  || alarm.t > 300)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 3 (1-300)");
                return;
            }
        }
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    memcpy(&G_parameter.sfride, &alarm, sizeof(nvram_fride_struct));

    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

static void cmd_sdfind(CMD_DATA_STRUCT * cmd)
{
    nvram_parameter_struct g_p = {0};
    kal_uint16 value = 0;
    kal_uint16  status = 0;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s,%d,%d,%d",
                cmd->pars[0], ON_OFF(G_parameter.sdfind.sw),
                G_parameter.sdfind.ring_time, G_parameter.sdfind.delay_time, G_parameter.sdfind.t_time);
        return;
    }
    else if(cmd->part > 4)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    memcpy(&g_p, &G_parameter, sizeof(nvram_parameter_struct));

    if(!strcmp(cmd->pars[1], "ON"))
    {
        g_p.sdfind.sw = 1;
        if(strlen(cmd->pars[2]) > 0)
        {
            value = track_fun_atoi(cmd->pars[2]);
            if(value < 1 || value > 300)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (1-300)");
                return;
            }
            g_p.sdfind.ring_time = value;
        }

        if(strlen(cmd->pars[3]) > 0)
        {
            value = track_fun_atoi(cmd->pars[3]);
            if(value < 1 || value > 300)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 3 (1-300)");
                return;
            }
            g_p.sdfind.delay_time = value;
        }

        if(strlen(cmd->pars[4]) > 0)
        {
            value = track_fun_atoi(cmd->pars[4]);
            if(value < 1 || value > 20)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 4 (1-20)");
                return;
            }
            g_p.sdfind.t_time = value;
        }
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        g_p.sdfind.sw = 0;
        track_stop_timer(TRACK_CUST_SDFIND_TIMER_ID);
        //track_cust_infinite_ring_stop_voice();
        //track_cust_audio_play_voice(6/*MT_DISCONNECT*/);
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    memcpy(&G_parameter, &g_p, sizeof(nvram_parameter_struct));

    if(G_parameter.sdfind.sw == 1)
    {
        cmd_sdfind_ring(0);
    }

    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

static void cmd_litimeron(CMD_DATA_STRUCT * cmd)
{

}

static void cmd_litimer(CMD_DATA_STRUCT * cmd)
{
    nvram_litmer_struct alarm = {0};
    kal_uint16 value;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s,%d,%d", cmd->pars[0],
                ON_OFF(G_parameter.Litimer_struct.sw), G_parameter.Litimer_struct.accon_up, G_parameter.Litimer_struct.accoff_up);
        return;
    }
    memcpy(&alarm, &G_parameter.Litimer_struct, sizeof(nvram_litmer_struct));
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part < 1 || cmd->part > 3)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 1;
        if(cmd->part >= 2)
        {
            value= track_fun_atoi(cmd->pars[2]);
            if((value < 5 || value > 18000) && value != 0)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (0, 5-18000)");
                return;
            }
            alarm.accon_up= value;
       }

        if(cmd->part == 3)
        {
            value= track_fun_atoi(cmd->pars[3]);
            if((value < 5 || value > 18000) && value != 0)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (0, 5-18000)");
                return;
            }
            alarm.accoff_up= value;
       }
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    memcpy(&G_parameter.Litimer_struct, &alarm, sizeof(nvram_litmer_struct));

    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/

//TRUE  表示使用项目自定义的功能，覆盖标准版
//FALSE 表示不支持该指令，同时标准版的也不会执行
static track_project_cmd_table_struct track_project_cmd_table[] =
{
    {"UNLOCK",    cmd_unlock,   TRUE          	},          // 开锁状态
    // {"LOCK",    cmd_lock,     TRUE       	},          // 开锁状态
    {"RESERVE",   cmd_reserve,   TRUE          	},          // 一键预约时间
    {"SDFIND",    cmd_sdfind,    TRUE         	},          // 声音寻车指令
    {"FRIDE",  CMD_FRIDE, TRUE        },
    {"LITIMER",cmd_litimer, TRUE     },
    {"LITIMERON",cmd_litimer,  TRUE    },
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
                LOGD(L_APP, L_V5, "this project disable %s",cmd->pars[0]);
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

