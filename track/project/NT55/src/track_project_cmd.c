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
#include "track_cust.h"
#include "track_os_data_types.h"
#include "kal_public_defs.h"
#include "track_os_log.h"
#include "track_cmd.h"
#include "track_nvram_default_value.h"
#include "track_os_paramete.h"

/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/
//static char  *s_ON = {"ON"}, *s_OFF = {"OFF"}, *s_Error = {"ERROR"};
//#define ON_OFF(value) (value==0?s_OFF:(value==1?s_ON:s_Error))


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


/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/
#if defined(__ATECH__)
extern void track_cust_atech_data_cmd(kal_uint8 cmd,kal_uint8 *param);
#endif
//TRUE  表示使用项目自定义的功能，覆盖标准版
//FALSE 表示不支持该指令，同时标准版的也不会执行
static void cmd_acc(CMD_DATA_STRUCT * cmd)
{
	nvram_acct_struct acct={0};
	kal_uint8 value = 0;
	if(cmd->part == 0)
	{
		sprintf(cmd->rsp_msg, "ACC:%s,%d",ON_OFF(G_parameter.acct.sw),G_parameter.acct.type);
		return;
	}
	if(cmd->part > 2)
	{
		sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
		return;
	}
	memcpy(&acct,&G_parameter.acct,sizeof(nvram_acct_struct));
	if(!strcmp(cmd->pars[1],"ON"))
	{
		acct.sw = 1;
		if(cmd->part == 2)
		{
			value = track_fun_atoi(cmd->pars[2]);
			if(value >= 1 && value <= 3)
			{
				acct.type = value;
			}
			else
			{
				sprintf(cmd->rsp_msg, "Error: Parameter2 (1-3)");
			}
		}
	}
	else if(!strcmp(cmd->pars[1],"OFF"))
	{
		acct.sw = 0;
	}
	else
	{
		sprintf(cmd->rsp_msg, "Error: Parameter1 (ON/OFF)");
	}
	memcpy(&G_parameter.acct, &acct, sizeof(nvram_acct_struct));
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
		sprintf(cmd->rsp_msg, "OK!");
    }
	else
	{
		sprintf(cmd->rsp_msg, "Error!");
	}
	
}
#if defined(__ATECH__)
static cmd_atech(CMD_DATA_STRUCT *cmd)
{
	kal_uint8 command = 0;
	kal_uint8 param[3];
	if(cmd->part != 0)
	{
		command = track_fun_atoi(cmd->pars[1]);
 		if(cmd->part > 1)
 			param[0] = track_fun_atoi(cmd->pars[2]);
		if(cmd->part > 2)
			param[1] = track_fun_atoi(cmd->pars[3]);
	}
	track_cust_atech_data_cmd(command,param);
}

#endif
#if defined(__BMS_PHYLION__)
kal_uint8 split(const char *data)
{
	kal_uint8 temp = 0;
	char d1=0,d2=0;
	kal_int8 t1,t2;

	d1 = data[0];
	d2 = data[1];
	LOGD(L_UART, L_V1, "%c,%c",d1,d2);
	if('A'<=d1 && d1<='F')
		t1 = d1-'A'+10;
	if('0'<=d1 && d1<='9') 
		t1 = d1-'0';
	//temp = t1;
	if('A'<=d2 && d2<='F')
		t2 = d2-'A'+10;
	if('0'<=d2 && d2<='9')
		t2 = d2-'0';
	LOGD(L_UART, L_V1, "%x,%x",t1,t2);
	temp = (t1 << 4)|t2;
	//LOGD(L_UART, L_V1, "%x",temp);
	return temp;
}
static cmd_bmscmd(CMD_DATA_STRUCT *cmd)
{
	kal_uint8 sendbuf[30];
	kal_uint8 sumL = 0,sumH = 0,temp = 0; 
	kal_uint16 sum = 0;

	int len = strlen(cmd->pars[1]);
	if(len != 2)
	{
		sprintf(cmd->rsp_msg,"Parameter1 length error!(2)");return;
	}
	temp = split(cmd->pars[1]);
	if(temp == 0)
	{
		sprintf(cmd->rsp_msg,"Parameter1 error!");return;
	}
	sendbuf[0] = 0x3A;//起始字节
	sendbuf[1] = 0x16;//地址字节
	sendbuf[2] = temp;//命令
	sendbuf[3] = 0x01;//数据长度
	sendbuf[4] = 0x00;
	//累加校验
	sum = sendbuf[1]+sendbuf[2]+sendbuf[3]+sendbuf[4];
	sumL = sum & 0x00FF;
	sumH = (sum >> 8);
	sendbuf[5] = sumL;
	sendbuf[6] = sumH;
	sendbuf[7] = 0x0D;
	sendbuf[8] = 0x0A;//结束符
	LOGH2(L_UART, L_V1, "", sendbuf, 9);
	U_PutUARTBytes(uart_port3, sendbuf, 9);
}
#endif

static track_project_cmd_table_struct track_project_cmd_table[] =
{
    {"NONE", NULL,   FALSE},
    {"ACC", cmd_acc,   TRUE},
#if defined(__ATECH__)
	{"ATECH", cmd_atech,   TRUE},
#endif
#if defined(__BMS_PHYLION__)
	{"BMSCMD", cmd_bmscmd,   TRUE},
#endif

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
        LOGD(L_APP, L_V5, "ret=%d|%s,%s|%p", ret, cmd->pars[0], track_project_cmd_table[i].cmd_string, track_project_cmd_table[i].cmd_string);
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

