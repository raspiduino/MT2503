/******************************************************************************
 * track_command.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        对 指令进行操作
 *
 * modification history
 * --------------------
 * v1.0   2012-07-22,  wangqi create this file
 *
 ******************************************************************************/


/****************************************************************************
* Include Files             包含头文件
*****************************************************************************/
#include "track_cmd.h"
#include "track_os_data_types.h"

#include "stack_msgs.h"
#include "stack_ltlcom.h"
#include "track_os_log.h"
#include "track_os_timer.h"
#include "track_at_context.h"
#include "track_at.h"
#include "track_at_sms.h"
#include "track_os_ell.h"
/*****************************************************************************
 *  Define			    宏定义
*****************************************************************************/
#define  SHORTCUT_CMD_TABLE_LENGTH (sizeof(SMS_cmd_Shortcut) / sizeof(char*))
#define  TEST_CMD_TOTAL (sizeof(cmd_Test) / sizeof(char*))
/*****************************************************************************
* Typedef  Enum         枚举
*****************************************************************************/


/*****************************************************************************
 *  Struct			    数据结构定义
*****************************************************************************/
/*和以下全词匹配的(  字母不分大小写)，可以无条件执行 */
static const char * SMS_cmd_Shortcut[] =
{
    "DW",
    "POSITION",
    "123",
    "JT",
    "111",
    "000",
    "SLEEP",
    "WAKE",
};

/*以下为测试指点，不验证密码*/
static const char * cmd_Test[] =
{
    "CA",
    "LOG",
    "GPSTC",
    "TEST",
    "DRV_TEST",
    "BMT",
    "ID",
    "CS"
};
/*****************************************************************************
* Local variable            局部变量
*****************************************************************************/

static CMD_DATA_STRUCT gps_rcv_data;//接收到的数据
static GPS_SMS_STRUCT  gps_rcv_sms;//接收到的短信息


/****************************************************************************
* Global Variable           全局变量
*****************************************************************************/

/****************************************************************************
* Global Variable - Extern          引用全局变量
*****************************************************************************/


/*****************************************************************************
 *  Global Functions	- Extern	    引用外部函数
*****************************************************************************/

/*****************************************************************************
 *  Local Functions	            本地函数
*****************************************************************************/
//void custom_write_to_uart(kal_uint8 * buffer, kal_uint16 length, kal_bool stuff);



static kal_bool is_test_cmd(char *cmd_ptr)
{
    U8 index;
    for(index = 0; index < TEST_CMD_TOTAL ; index++)
    {
        if(strcmp(cmd_Test[index], cmd_ptr) == 0)
        {
            return KAL_TRUE;
        }
    }
    return KAL_FALSE;
}

/******************************************************************************
 *  Function    -  is_shortcut_cmd
 *
 *  Purpose     -  是快捷指令码?
 *
 *  Description - 执行操作无需带# 号(  和密码)
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 22-02-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static kal_bool is_shortcut_cmd(char *cmd_ptr, int cLen)
{
    U8 index;

    if((cLen -= 2) > 0)
    {
        if(*(cmd_ptr + cLen) == 0x0D)
        {
            *(cmd_ptr + cLen) = 0;//remove 0x0a in end of str
        }
    }
    for(index = 0; index < SHORTCUT_CMD_TABLE_LENGTH ; index++)
    {
        if(strcmp(SMS_cmd_Shortcut[index], cmd_ptr) == 0)
        {
            return KAL_TRUE;
        }
    }
    return KAL_FALSE;
}

/******************************************************************************
 *  Function    -  track_cmd_check_authentication
 *
 *  Purpose     -  密码校验
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 24-02-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
kal_bool track_cmd_check_authentication(CMD_DATA_STRUCT * command)
{
    if(is_test_cmd(command->pars[CM_Main]))
    {
        return KAL_TRUE;
    }
#if defined(__NF2318__)
//NF2318没有短信密码功能
#else
    if(track_cust_password_sw())
    {
        char password[20] = {0};
        int len;
        len = strlen(command->pars[1]);
        if(len >= 20)
        {
            return KAL_FALSE;   // 验证密码
        }
        memcpy(password, command->rcv_msg_source + (command->pars[1] - command->rcv_msg), len);
        command->cmd_pwd_type = track_cust_password_check(password);
#if defined (__SAME_GT02__)
        if(command->cmd_pwd_type == 2)
        {
            command->supercmd = 1;
        }
#endif 
        if(!command->cmd_pwd_type || command->part == 0)
        {
            return KAL_FALSE;   // 验证密码
        }
        else
        {
            static char *blank = "";
            char *pars[GPS_COMMA_UNIT_MAX] = {0};
            int i;
            LOGD(L_APP, L_V5, "%d", sizeof(command->pars));
            memcpy(pars, command->pars, sizeof(command->pars));
            memset(command->pars, 0, sizeof(command->pars));
            command->pars[0] = pars[0];
            for(i = 2; i < GPS_COMMA_UNIT_MAX; i++)
            {
                command->pars[i - 1] = pars[i];
            }
            command->pars[GPS_COMMA_UNIT_MAX - 1] = blank;
            command->part--;
        }
    }
#endif
    return KAL_TRUE;
}

/******************************************************************************
 *  Function    -  track_cmd_send_rsp
 *
 *  Purpose     -  经过指令操作后，发出相应的短信信息或者串口信息
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 *wangqi此处由于网络测试指令没有接口传入电话号码所以模拟网络指令不能通过短信的方式传送
 影响此处接口统一稍后想办法解决
 * ----------------------------------------
 ******************************************************************************/
extern void track_socket_queue_send_netcmd_reg(kal_uint8* data, int len, kal_uint8 packet_type, kal_uint32 no);
void track_cmd_send_rsp(Cmd_Type cm_type, kal_int16 len, char * rsp_msg, kal_uint8 sign)
{
    LOGD(L_CMD, L_V5, "rsp_msg=%s,%d", rsp_msg, len);

    if(cm_type == CM_AT)
    {
        //rmmi_write_to_uart((kal_uint8*)Message, strlen(Message), KAL_TRUE);
        if(len)
        {
            //custom_write_to_uart((kal_uint8*)rsp_msg, len, KAL_TRUE);   /*chengjun  2012-04-12*/
            LOGS("%s", rsp_msg);
        }
    }
    else if(cm_type == CM_VS_EX)
    {
        if(len)
        {
            //custom_write_to_uart((kal_uint8*)rsp_msg, len, KAL_TRUE);   /*chengjun  2012-04-12*/
            LOGS("行车卫士##%s", rsp_msg);
        }
    }
    else if(cm_type == CM_ONLINE)
    {
        /*please insert function */
        LOGD(L_CMD, L_V5, "sign:%d,len:%d,%s", sign, len, rsp_msg);
        if(len <= 0)
        {
            return;
        }
        track_socket_queue_send_netcmd_reg(rsp_msg, len, 0, 0);

        //track_cust_at_simulation_online_cmd(rsp_msg, len, sign);

    }
    else
    {
        ASSERT(0);
    }


}

void track_cmd_sms_rsp(CMD_DATA_STRUCT * cmds)
{
#if defined(__AT_CA__)
    sms_msg_struct ssms = {0};

    if(strlen(cmds->return_sms.ph_num) && cmds->rsp_length)
    {
        //custom_write_to_uart((kal_uint8*)cmds->rsp_msg, cmds->rsp_length, KAL_TRUE);   /*chengjun  2012-04-12*/

        if(cmds->return_sms.reply_character_encode == GSM_UCS2)
        {
            ssms.codetype = KAL_FALSE;
        }
        else
        {
            ssms.codetype = KAL_TRUE;
        }
        ssms.nocount = 1;
        ssms.ctxlen = cmds->rsp_length;
        ssms.ctx = cmds->rsp_msg;
        ssms.numbers[0] = cmds->return_sms.ph_num;

        track_sms_sender(&ssms);

    }
#endif /* __AT_CA__ */
}
/*****************************************************************************
 *  Global Functions            全局函数
*****************************************************************************/


/******************************************************************************
 * FUNCTION:  - 查找短信的指令标志头 *
 * DESCRIPTION: - *    查找短信的指令标志头 *
 * Input:
 * Output:
 * Returns: *
 * modification history
 * --------------------
 * v1.0  , 17-04-2010,    written
 * --------------------
 ******************************************************************************/
static char* parse_sms_head(char *data)
{
    char* SMS_str = NULL;
    char SMS_Head[15] = {"GT_CM="};

    SMS_str = strstr(data, SMS_Head);

    if(SMS_str == NULL)
    {
        return data;
    }
    else
    {
        return (SMS_str + strlen(SMS_Head));
        //SMS_str- &data[0] 指令头的起始位置
        //return (SMS_str - &data[0] + data + strlen(SMS_Head));
    }
}


/*---------------------------------------------------------------------------------------
 * FUNCTION			gps_smscmd_feedback
 *
 * DESCRIPTION		短信指令执行回执
 *
 * PARAMETERS		BOOL is_right		执行成功或失败
 *					void *sms_string	特殊返回信息
 *
 * RETURNS			NULL
 *
 *---------------------------------------------------------------------------------------*/
static void gps_smscmd_feedback(BOOL is_right, void *sms_string)
{
    char temp[100] = {0};
    S8 *data_ptr = (S8*)sms_string;

    memset(gps_rcv_data.rsp_msg, 0, CM_PARAM_LONG_LEN_MAX);

    if(is_right == KAL_TRUE)
    {
        strcpy(temp, "Success!");
    }

    if(is_right == KAL_FALSE)
    {
        strcpy(temp, "Fail!");
    }

    if(is_right == 0x11)
    {
        strcat(temp, data_ptr);
    }

    if((data_ptr != NULL) && (is_right != 0x11))
    {
        strcat(temp, data_ptr);
    }

    LOGD(L_CMD, L_V4, "return %s", temp);

    memcpy((char *)gps_rcv_data.rsp_msg, temp, strlen(temp));
    gps_rcv_data.rsp_length = strlen(temp);
    strcpy((char *)gps_rcv_data.return_sms.ph_num, (char *)gps_rcv_sms.num);
}

/******************************************************************************
 *  Function    -  track_cmd_analyse
 *
 *  Purpose     -  短信指令分段拆分
 *
 *  Description - void *data	短信内容
 *                        U8 data_len	短信长度
 *
 * modification history
 * ----------------------------------------
 *
 * ----------------------------------------
 ******************************************************************************/
kal_bool track_cmd_analyse(CMD_DATA_STRUCT * command)
{
    char        *p, *data_ptr, split_ch = ',';
    int         cmd_Len, par_len;
      char sim_id[10] = {0};

    extern nvram_parameter_struct              G_parameter ;

    LOGD(L_CMD, L_V5, "analyse:%d,%s", command->rcv_length, command->rcv_msg);
    if(command == NULL || command->rcv_msg == NULL || command->rcv_length < 1)
    {
        return KAL_FALSE;
    }
    memcpy(command->rcv_msg_source, command->rcv_msg, CM_PARAM_LONG_LEN_MAX);
    track_fun_toUpper(command->rcv_msg);    //转换成大写
    //LOGD(L_CMD, L_V6, "track_fun_toUpper %s", head_ptr);
    data_ptr = parse_sms_head(command->rcv_msg);    //查找有没有"GT_CM="字符

    cmd_Len = strlen(data_ptr);

    /*快捷指令处理*/
    if(is_shortcut_cmd(data_ptr, cmd_Len))
    {
#if defined (__SAME_GT02__)
        if(G_parameter.Permission.password_sw)
        {
            strcat(data_ptr , ",");
            strcat(data_ptr , G_parameter.Permission.password);
            cmd_Len = cmd_Len + strlen(G_parameter.Permission.password) + 1;
            strcat(command->rcv_msg_source , ",");
            strcat(command->rcv_msg_source  , G_parameter.Permission.password);
        }
#endif

        data_ptr[cmd_Len] = '#';
        cmd_Len++;
    }
#if defined(__NF2318__)
		p = strstr(data_ptr,"=");
		if(p != NULL)
		{
			strncpy(p, ",", 1);
		}
#endif
    if(command->return_sms.cm_type == CM_SMS && data_ptr[cmd_Len - 1] != '#')
    {
#ifdef __NT32__
        p=strstr(data_ptr,"#");
         strncpy(sim_id, (char*)track_drv_get_imsi(0), 5);
        if(p!=NULL&&(strcmp(sim_id,"46006")==0||strcmp(sim_id,"46004")==0))
        {
          *p=0;
           cmd_Len=p-data_ptr;
        }
        else
#endif /* __NT32__ */
        {
          return KAL_FALSE;
        }
    }
    if(data_ptr[cmd_Len - 3] == '#' && data_ptr[cmd_Len - 2] == 0x0D && data_ptr[cmd_Len - 1] == 0x0A)
    {
        data_ptr[cmd_Len - 3] = 0;
    }
    else if(data_ptr[cmd_Len - 2] == '#' && data_ptr[cmd_Len - 1] == 0x0D)
    {
        data_ptr[cmd_Len - 2] = 0;
    }
    else if(data_ptr[cmd_Len - 1] == '#')
    {
        data_ptr[cmd_Len - 1] = 0;
    }
    else
    {
        LOGH(L_CMD, L_V6, data_ptr, cmd_Len);
    }

    par_len = track_fun_str_analyse(data_ptr, command->pars, GPS_COMMA_UNIT_MAX, NULL, "\r\n", split_ch);

    if(par_len > GPS_COMMA_UNIT_MAX || par_len <= 0)
    {
        return KAL_FALSE;
    }
    
#if defined (__SAME_GT02__)
//nc
#else
    if(track_cmd_super_cmd(command))
    {
        int i;
        command->supercmd = 1;
        for(i = 0; i + 1 < par_len; i++)
        {
            command->pars[i] = command->pars[i + 1];
        }
        par_len--;
    }
#endif /* __SAME_GT02__ */

    /*使用str_analyse解出包含有指令头,如果要等到参数个数要减去头和密码*/
    if((par_len - CM_Par1) > 0)
    {
        command->part = par_len - CM_Par1;
    }
    else
    {
        command->part = 0;
    }

    return KAL_TRUE;
}

kal_int8 track_command_operate(CMD_DATA_STRUCT * command)
{
    if(track_cmd_analyse(command))
    {
        LOGD(L_CMD, L_V4, " part:%d, supercmd:%d", command->part, command->supercmd);
        if(command->supercmd != 1 && command->return_sms.cm_type == CM_SMS && !track_cust_sos_and_center_permit(command->return_sms.ph_num))
        {
            LOGD(L_CMD, L_V4, "无权限使用指令！");
            return 0;
        }
        if(track_execute_command(command))
        {
            return 0;
        }

        if(track_project_command(command))
        {
            return 0;
        }
        else
        {
            LOGD(L_CMD, L_V6, " track_cust_at_cmdpart:%d", command->part);
            track_cust_cmd(command);
        }
    }
    else
    {
        memset(command, 0, sizeof(CMD_DATA_STRUCT));

    }
    return 0;
}

#if defined (__GPS_TRACK__)
/******************************************************************************
 *  Function    -  custom_cmd_send
 *
 *  Purpose     -  发送命令到串口
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 20-05-2010,  jwj  written
 * ----------------------------------------
 ******************************************************************************/
void custom_cmd_send(char* cmd, kal_bool bCheckRes)
{
    kal_uint16 DataLen = 0;

    DataLen = strlen(cmd);
    if(!DataLen)
    {
        return;
    }

    if(!bCheckRes)
    {
        if(DataLen > MAX_CMD_LEN)
        {
            DataLen = MAX_CMD_LEN;
        }
        //custom_write_to_uart((kal_uint8*)cmd, DataLen, KAL_TRUE);   /*chengjun  2012-04-12*/
        LOGS("%s", cmd);
    }
}
/******************************************************************************
 *  Function    -  l4c_send_to_tcpip_app
 *
 *  Purpose     -  L4C 向TRACK  发送消息
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 *
 * ----------------------------------------
 ******************************************************************************/
static void l4c_send_to_track_app(msg_type msgid, void* data_ptr, kal_uint16 length, kal_uint16 target)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *Message;
    cmd_req_struct *myMsgPtr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if((data_ptr == NULL) || (length >= CM_PARAM_LEN_MAX))
    {
        return;
    }

    myMsgPtr = (cmd_req_struct*) construct_local_para(sizeof(cmd_req_struct), TD_CTRL);
    if(myMsgPtr == NULL)
    {
        track_cust_restart(38, 0);
    }
    track_log_switch(0x03);
    memset(myMsgPtr->cmd_data , 0, CM_PARAM_LEN_MAX);
    memcpy(myMsgPtr->cmd_data, data_ptr , length);
    myMsgPtr->cmd_length = length ;
    myMsgPtr->target = target ;

    Message = (ilm_struct *)allocate_ilm(MOD_L4C);
    if(Message == NULL)
    {
        track_cust_restart(39, 0);
    }
    Message->src_mod_id = MOD_L4C;
    Message->dest_mod_id = MOD_MMI;
    Message->sap_id = INVALID_SAP;
    Message->msg_id = (msg_type)msgid;
    Message->local_para_ptr = (local_para_struct*) myMsgPtr;
    Message->peer_buff_ptr = NULL;
    msg_send_ext_queue(Message);

}



void track_at_get_ctx_from_l4c(void *msg)
{
    cmd_req_struct *localBuff_p = (cmd_req_struct*)msg;
    CMD_DATA_STRUCT at_cmd = {0};
    kal_uint8 tem0A[2] = {0x0a, 0x0};

    if(localBuff_p->cmd_data && localBuff_p->cmd_length
            && (localBuff_p->cmd_length < CM_PARAM_LEN_MAX))
    {
        memset(&at_cmd, 0, sizeof(CMD_DATA_STRUCT));
        memcpy(&at_cmd.rcv_msg, localBuff_p->cmd_data, localBuff_p->cmd_length);
        at_cmd.rcv_length = localBuff_p->cmd_length;
        at_cmd.return_sms.cm_type = localBuff_p->target;

        if(at_cmd.return_sms.cm_type == CM_AT)
        {
            track_command_operate(&at_cmd);
        }
        else if(at_cmd.return_sms.cm_type == CM_TEST_ONLINE)
        {
            LOGD(L_CMD, L_V3, "%s", at_cmd.rcv_msg);
            at_cmd.return_sms.cm_type = CM_AT;
            //track_cust_recv_online_cmd(at_cmd.rcv_msg,at_cmd.rcv_length,at_cmd.return_sms.cm_type);
        }
        else if(at_cmd.return_sms.cm_type == CM_VS_AT)
        {
            track_at_vs_send(at_cmd.rcv_msg);
        }
        else
        {
            LOGD(L_CON, L_V3, "COMMAND TARGET ERROR %d", at_cmd.return_sms.cm_type);
        }
    }
}
/******************************************************************************
 *  Function    -  track_custom_cmd_parse
 *
 *  Purpose     -  对串口字符串进行解析
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 20-05-2010,  jwj  written
 * ----------------------------------------
 ******************************************************************************/
kal_bool track_cmd_parse(kal_uint8*cmd_name, void * full_cmd_string)
{
    char *p = NULL, cm_t = 0xFF;

    track_fun_toUpper((char *) cmd_name);
    LOGD(L_CMD, L_V8, "track_fun_toUpper %s", cmd_name);

    if(strcmp((char *)cmd_name, "GT_CM") == 0)
    {
        cm_t = CM_AT;
        p = full_cmd_string;
    }
    else if(strcmp((char *)cmd_name, "GT_OL") == 0)
    {
        track_fun_toUpper((char *)full_cmd_string);
        p = strstr((char*)full_cmd_string, "GT_OL");
        if(NULL == p)
        {
            p = full_cmd_string;
        }
        else
        {
            p = p + 6;
        }

        cm_t = CM_TEST_ONLINE;
    }
    else if(strcmp((char*)cmd_name, "GT_AT") == 0)
    {
        p = strstr((char*)full_cmd_string, "=");
        if(NULL == p)
        {
            p = full_cmd_string;
        }
        else
        {
            p = p + 1;
        }
        cm_t = CM_VS_AT;
    }
    else if(strcmp((char*)cmd_name, "GT_EX") == 0)
    {
        p = strstr((char*)full_cmd_string, "=");
        if(NULL == p)
        {
            p = full_cmd_string;
        }
        else
        {
            p = p + 1;
        }
        cm_t = CM_VS_EX;
    }
    else
    {
        return KAL_FALSE;
    }
    //无延迟回显
    //custom_write_to_uart((kal_uint8 *)full_cmd_string, strlen((char *)full_cmd_string), KAL_TRUE);

    if(track_get_at_port() != 4)
    {
        LOGS("%s", (char*)full_cmd_string);
    }
    l4c_send_to_track_app(MSG_ID_AT_CMD_RSP, p, strlen((char *)p), cm_t);

    return KAL_TRUE;
}
#endif /* __GPS_TRACK__ */

