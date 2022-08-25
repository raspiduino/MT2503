/******************************************************************************
 * track_at.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        提供电话控制接口
 *
 * modification history
 * --------------------
 * v1.0   2012-08-09,  WangQi create this file
 *
 ******************************************************************************/
#include "Device.h"

#include "track_os_data_types.h"

#include "stack_ltlcom.h"
#include "track_os_timer.h"
#include "track_at.h"
#include "track_cmd.h"
#include "track_at_sms.h"
#include "track_at_call.h"
#include "track_at_sim.h"
#include "string.h"
#include "stdlib.h"

#include "c_RamBuffer.h"
#include "c_vector.h"
#include "tst_def.h"
/*****************************************************************************
 *  Define			    宏定义
*****************************************************************************/

#define AT_ESAM         "AT+ESAM=2\r\n"
/************************************************************************
CSMCC_SETUP_MSG(MTcall)			 1	1
CSMCC_DISCONNECT_MSG 			 2	2
CSMCC_ALERT_MSG				 3	4
CSMCC_CALL_PROCESS_MSG			 4	8
CSMCC_SYNC_MSG				 5	16
CSMCC_PROGRESS_MSG			 6	32
CSMCC_CALL_CONNECTED_MSG		 7	64
CSMCC_ALL_CALLS_DISC_MSG 		 8	128
CSMCC_CALL_ID_ASSIGN_MSG		 9	256
CSMCC_STATE_CHANGE_HELD			 10	512
CSMCC_STATE_CHANGE_ACTIVE		 11	1024
CSMCC_STATE_CHANGE_DISCONNECTED 	 12	2048
CSMCC_STATE_CHANGE_MO_DISCONNECTING	 13	4096

CSMCC_SETUP_MSG + CSMCC_DISCONNECT_MSG + CSMCC_STATE_CHANGE_MO_DISCONNECTING
1+2+4096 = 4099
************************************************************************/
#define AT_ECPI          "AT+ECPI=64\r\n"
#define AT_CFUN          "AT+CFUN=1,1\r\n"


/*****************************************************************************
* Typedef  Enum         枚举
*****************************************************************************/


/*****************************************************************************
 *  Struct			    数据结构定义
*****************************************************************************/

typedef struct
{
    kal_uint8       vs_ctx[160]; //MagicNing 用于存放AT指令
    kal_uint16      vs_len;
} vs_at_struct;

/*****************************************************************************
* Local variable            局部变量
*****************************************************************************/
static kal_uint16     AT_PORT = 99;

#ifdef __AT_CA__

//static at_ca_struct   AT_Put_Buf = {0};
//static kal_uint8    AT_Put_Buf[512] = {0};//缓存单个AT的返回包
//static kal_uint16   AT_Put_Buf_Count = 0;//单个AT的返回包长度
static int VSAT_LEN = sizeof(vs_at_struct);
//static int ATCA_LEN = sizeof(at_ca_struct);

//static at_ca_struct get_Put_Buf = {0};
//static kal_uint8    at_p_buf[1024]={0};//缓存AT的返回包
//static kal_uint8    *AT_P_ENDPTR = &at_p_buf[0] + 1024;

//static kal_uint8    *inp = &at_p_buf[0];
//static kal_uint8    *outp = &at_p_buf[0];

static vs_at_struct vs_at = {0};
//static kal_bool   vs_at_send_flag = KAL_FALSE; //AT指令标识
static kal_uint16   in_buf_limit = sizeof(vs_at.vs_ctx) - 1;


static c_vector* vec_drv_hisr_vsat = NULL;
static c_vector* vec_mmi_vsat = NULL;
//static c_vector* vec_acti_rsp = NULL;

static vs_at_cmd_struct vs_at_cmd = {0};
/*****************************************************************************
* Local variable            全局变量
*****************************************************************************/
enum_vs_at_state vs_at_status = V_A_FREE;
kal_bool ishanld = KAL_FALSE;
/*****************************************************************************
 *  Local Functions	            本地函数
*****************************************************************************/
static void at_vs_way(vs_at_cmd_struct *vs_sms_ctx);
static void sys_reset(void);
void track_uart_data_analysis(kal_int8 type, char *rsp_data, kal_uint32 len);
static kal_bool track_is_customer_cmd(const void * cmdctx, int at_len);
static int get_vsat_size(void);
static void send_vsat_in_vec(void);
#endif

/*************************************/
/*  ATCI TASK 直接调用，MMI 不能调用 */
/*************************************/
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8    type;
    kal_uint16   len;
} uart_put_bytes_ind2_struct;

/******************************************************************************
 *  Function    -  track_atci_at_command_buf
 *
 *  Purpose     -  ATCI 模拟串口数据的缓冲区维护
 *
 *  Description -  mode
 *                  1    = 读数据
 *                  2    = 写数据
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 15-05-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_bool track_atci_at_command_buf(kal_uint8 mode, kal_uint8 *data, kal_uint16 *len)
{
    static kal_uint8 buf[256] = {0};
    static kal_uint16 buflen = 0;
    if(mode == 1 && buflen > 0)
    {
        memcpy(data, buf, buflen);
        *len = buflen;
        buflen = 0;
        return KAL_TRUE;
    }
    else if(mode == 2 && (*len) < 256)
    {
        buflen = *len;
        memcpy(buf, data, buflen);
        return KAL_TRUE;
    }
    return KAL_FALSE;
}


/******************************************************************************
 *  Function    -  track_at_send_msg_ind
 *
 *  Purpose     -  MOD_ATCI 在读取完成缓存数据后发送消息通知 MMI 下发下一个数据
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 15-05-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_at_send_msg_ind(void)
{
    ilm_struct *Message;

    LOGD(L_SYS, L_V4, "");
    Message = (ilm_struct *)allocate_ilm(MOD_ATCI);
    if(Message == NULL)
    {
        track_cust_restart(41, 0);
    }
    Message->src_mod_id = MOD_ATCI;
    Message->dest_mod_id = MOD_MMI;
    Message->sap_id = INVALID_SAP;
    Message->msg_id = (msg_type)MSG_ID_TRACK_DATA_ATCI_TO_MMI_IND;
    Message->local_para_ptr = NULL;
    Message->peer_buff_ptr = NULL;
    msg_send_ext_queue(Message);
}

/******************************************************************************
 *  Function    -  track_at_send_data_rsq
 *
 *  Purpose     -  ACTI返回数据通知MMI
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 15-05-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_at_send_data_rsq(kal_uint8 type, kal_uint8 *data, U16 *len)
{
    ilm_struct *Message;
    uart_put_bytes_ind2_struct *myMsgPtr = NULL;
    LOGD(L_SYS, L_V6, "type:%d, len:%d", type, *len);
    if(*len >= 2000)
    {
        track_cust_restart(39, 0);
        return;
    }
    myMsgPtr = (uart_put_bytes_ind2_struct*)construct_local_para(sizeof(uart_put_bytes_ind2_struct) + (*len) + 2, TD_RESET);
    if(myMsgPtr == NULL)
    {
        track_cust_restart(40, 0);
        return;
    }
    myMsgPtr->type = type;
    myMsgPtr->len = *len;
    memcpy((kal_uint8 *)myMsgPtr + sizeof(uart_put_bytes_ind2_struct), data, myMsgPtr->len);
    Message = (ilm_struct *)allocate_ilm(MOD_ATCI);
    if(Message == NULL)
    {
        track_cust_restart(40, 0);
        return;
    }
    Message->src_mod_id = MOD_ATCI;
    Message->dest_mod_id = MOD_MMI;
    Message->sap_id = INVALID_SAP;
    Message->msg_id = (msg_type)MSG_ID_TRACK_DATA_ATCI_TO_MMI_REQ;
    Message->local_para_ptr = (local_para_struct*) myMsgPtr;
    Message->peer_buff_ptr = NULL;
    msg_send_ext_queue(Message);
}

/***********************/
/*  新的模拟AT指令接口 */
/***********************/
static kal_bool g_at_send_valid = KAL_TRUE;
/******************************************************************************
 *  Function    -  track_at_to_atci_send
 *
 *  Purpose     -  需要发送至ATCI，模拟串口发送至ATCI的数据
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 15-05-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_bool track_at_to_atci_send(kal_uint8 *data, kal_uint16 len)
{
    ilm_struct *ilm ;
    uart_ready_to_read_ind_struct* localPtr;
    kal_uint8 *buf;

    if(!g_at_send_valid)
    {
        return KAL_FALSE;
    }
    g_at_send_valid = KAL_FALSE;

    if(len >= 256)
    {
        LOGD(L_CMD, L_V1, "ERROR: 暂定限制单次数据最多发送不超过256字节数据 %d", len);
        return KAL_FALSE;
    }

    localPtr = (uart_ready_to_read_ind_struct*)
               construct_local_para(sizeof(uart_ready_to_read_ind_struct) + len + 2, TD_RESET/*0*//*TD_CTRL*/);
    if(localPtr == NULL)
    {
        LOGD(L_CMD, L_V1, "error 1");
        track_cust_restart(45, 0);
        return KAL_FALSE;
    }
    ilm = (ilm_struct*)allocate_ilm(MOD_MMI);
    if(ilm == NULL)
    {
        LOGD(L_CMD, L_V1, "error 2");
        track_cust_restart(44, 0);
        return KAL_FALSE;
    }

    localPtr->port = 6; //暂定为串口6，这个数值仅仅为了让接收的时候可以拦截处理，只要不是系统已经在使用的串口编号即可
    buf = (kal_uint8 *)((kal_uint8 *)localPtr + sizeof(uart_ready_to_read_ind_struct));
    memcpy(buf, &len, 2);
    memcpy(buf + 2, data, len);

    ilm->peer_buff_ptr = NULL;
    ilm->local_para_ptr = (local_para_struct*) localPtr;
    ilm->msg_id = MSG_ID_UART_READY_TO_READ_IND;
    ilm->sap_id = DRIVER_PS_SAP;
    ilm->src_mod_id = MOD_MMI;
    ilm->dest_mod_id = MOD_ATCI;
    msg_send_ext_queue(ilm);
    return KAL_TRUE;
}

/******************************************************************************
 *  Function    -  track_at_data_atci_to_mmi_ind
 *
 *  Purpose     -  MMI 收到 ATCI 发送来告知可以发送下一段模拟串口数据的通知
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 15-05-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_at_data_atci_to_mmi_ind(void)
{
    LOGD(L_SYS, L_V4, "ATCI通知模拟AT指令已经完成读取");
    g_at_send_valid = KAL_TRUE;
    
    if(get_vsat_size() && (KAL_FALSE == track_is_timer_run(TRACK_SEND_VSAT_TIMER_ID)))
    {
        tr_start_timer(TRACK_SEND_VSAT_TIMER_ID, 1000, send_vsat_in_vec);
    }
}

/******************************************************************************
 *  Function    -  track_at_put_cmd2_rsp
 *
 *  Purpose     -  MMI 收到 ATCI 发送来的截取部分数据
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 15-05-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_at_put_cmd2_rsp(void * msg)
{
    uart_put_bytes_ind2_struct *myMsgPtr = (uart_put_bytes_ind2_struct *)msg;
    kal_uint8 *buf = (kal_uint8*)myMsgPtr + sizeof(uart_put_bytes_ind2_struct);
    LOGD(L_SYS, L_V4, "(type:%d,len:%d) {%s}", myMsgPtr->type, myMsgPtr->len, buf);
    LOGH(L_SYS, L_V6, buf, myMsgPtr->len);
	
    if(myMsgPtr->type == 1)
    {
        // 接收自来自外部串口0的数据
        CMD_DATA_STRUCT at_cmd = {0};
        if(buf && myMsgPtr->len < CM_PARAM_LEN_MAX)
        {
            memcpy(&at_cmd.rcv_msg, buf, myMsgPtr->len);
            at_cmd.rcv_length = myMsgPtr->len;
            at_cmd.return_sms.cm_type = CM_AT;
            track_command_operate(&at_cmd);
        }
        else
        {
            LOGD(L_SYS, L_V1, "长度异常");
        }
    }
    else if(myMsgPtr->type == 2)
    {
        // 拦截L4层需要从串口发送出去的数据
        
#if 0//defined(__BMS_PHYLION__)
		tr_stop_timer(TRACK_CUST_BMS_INIT_TIMER_ID);
#endif
        track_uart_data_analysis(0, buf, myMsgPtr->len);
    }
}
/***************************/
/*  新的模拟AT指令接口 END */
/***************************/

void track_at_vs_cmd_rsp_handle_over(void)
{
    memset(&vs_at_cmd, 0, sizeof(vs_at_cmd_struct));
}


void track_uart_data_analysis(kal_int8 type, char *rsp_data, kal_uint32 len)
{
    char *p = NULL, *p2 = NULL, *cmgl = NULL, *ptr_cmd_head = NULL;
    static char last_rsp[32] = {0};

    if(type == 1)
    {
        memcpy(last_rsp, rsp_data, (len >= 32 ? 31 : len));
        LOGD(L_CMD, L_V8, "记录下发的模拟指令");
        return;
    }
#if defined __CUSTOM_WIFI_FEATURES_SWITCH__
    if (strstr(rsp_data, "+EWIFIAP"))
    {
        LOGD(L_CMD, L_V7, "WIFI指令回复");

           if(track_is_testmode())
           {
               LOGS("%s",rsp_data);
               return;
           }
           LOGD(L_CMD, L_V5, "%s",rsp_data);
	    track_drv_wifi_hotspot(rsp_data,len);
		return;
	}
#endif
    if(len >= 9/*自定义AT头长度*/ && track_is_customer_cmd(rsp_data, len))
    {
        // 外部自定义AT指令不应该在这收到，应该在SIO_CMD_GET_BYTES就被拦截
        LOGD(L_CMD, L_V9, "自定义AT指令，在此处不处理");
        if(len < 32)
        {
            memset(last_rsp, 0, sizeof(last_rsp));
            memcpy(last_rsp, rsp_data, len);
        }
#if defined(__GT740__)
		if(track_is_testmode())
		{
			if(strstr(rsp_data, "AT+EWIFI"))
			{
				LOGS("{%s}",rsp_data);
			}
		}
#endif
        return;
    }

    // 回显L4输出得数据
    //LOGS("L4:{%s}", rsp_data);
    LOGS("%s", rsp_data);

    //track_at_rsp_data_hdlr(&rsp_msg);

    /*+EGMR: "358688000000158"*/
    if(vs_at_cmd.at_cmd_callback)
    {
        if(vs_at_cmd.at_cmd_callback(rsp_data, len))
        {
            track_at_vs_cmd_rsp_handle_over();
        }
    }

    /*读收件箱的回执*/
    {
        static char tmpbuf[1000];
        static int i = 0;
        char *p;
        cmgl = strstr(rsp_data, "+CMGL:");
        if(cmgl)
        {
            if(i + len > 999)
            {
                LOGD(L_CMD, L_V8, "receive CMGL size too long 1");
                return;
            }
            memcpy(&tmpbuf[i], rsp_data, len);
            i += len;
        }
        else if(i > 0)
        {
            if(i + len > 999)
            {
                LOGD(L_CMD, L_V8, "receive CMGL size too long 2");
                return;
            }
            memcpy(&tmpbuf[i], rsp_data, len);
            i += len;
            p = strstr(tmpbuf, "\r\n");
            if(p == NULL)
            {
                LOGD(L_CMD, L_V8, "receive CMGL section 1");
                return;
            }
            p = strstr(p + 2, "\r\n");
            if(p == NULL)
            {
                LOGD(L_CMD, L_V8, "receive CMGL section 2");
                return;
            }
            p = strstr(p + 2, "\r\n");
            if(p == NULL)
            {
                LOGD(L_CMD, L_V8, "receive CMGL section 3");
                return;
            }
            track_sim_get_sms_f_s_b_rsp(1, tmpbuf);
            memset(tmpbuf, 0, 1000);
            i = 0;
        }
    }

    if(type == 0 && len == 2 && rsp_data[0] == 0x0D && rsp_data[1] == 0x0A)
    {
        LOGD(L_CMD, L_V8, "仅仅有换行的忽略处理");
        return;
    }


    if(strstr(rsp_data, "OK"))
    {
        char ch = 0;
        if((ptr_cmd_head = strstr(last_rsp, "AT+CMGL=")) && cmgl == NULL)
        {
            track_sim_get_sms_f_s_b_rsp(0, ptr_cmd_head);
            LOGD(L_CMD, L_V8, "[AT+CMGL=] OK!");
        }
        else if(strstr(last_rsp, "AT+ESAM="))
        {
            tr_stop_timer(TRACK_AT_HAND_FREE_TIMER_ID);
            LOGD(L_CMD, L_V8, "[AT+ESAM=]1 OK!");
        }

    }
    //else if(strstr(rsp_data, "ERROR"))
    {

    }
    if (strstr(rsp_data, "+ICCID"))
    {
          LOGD(L_CMD, L_V7, "ICCID");
	    track_drv_iccid(rsp_data,len);
		return;
	}
     //解析EADC值
    if(strstr(rsp_data, "+EADC:"))
    {
        LOGD(L_CMD, L_V7, "EADC结果");

        if(track_is_testmode())
        {
            LOGS("%s", rsp_data);
            return;
        }
        LOGD(L_CMD, L_V5, "%s", rsp_data);
        track_drv_eadc_data_decode(rsp_data, len);
        return;
    }
    if(len < 32)
    {
        memset(last_rsp, 0, sizeof(last_rsp));
        memcpy(last_rsp, rsp_data, len);
    }
}






/***********************/
/*   */
/***********************/

kal_uint16 track_get_at_port(void)
{
    extern UART_PORT * OTA_PS_UART_PORT;
    if(AT_PORT == 99)
    {
        //AT_PORT = (PS_UART_PORT == 99 ? 0 : PS_UART_PORT);
        if(* OTA_PS_UART_PORT == 99 || OTA_PS_UART_PORT == NULL)
        {
            AT_PORT = 0;
        }
        else
        {
            AT_PORT = * OTA_PS_UART_PORT;
        }
    }
    return AT_PORT;
}

#ifdef __AT_CA__
/*MMI层保持同步*/
#if 1
static void track_at_vs_push(vs_at_cmd_struct *vs_sms_ctx)
{
    vs_at_cmd_struct *mmi_va_struct = (vs_at_cmd_struct*)Ram_Alloc(1, sizeof(vs_at_cmd_struct));

    if(NULL == vec_mmi_vsat)
    {
        VECTOR_CreateInstance(vec_mmi_vsat);
    }

    if(mmi_va_struct && vs_sms_ctx)
    {
        memset(mmi_va_struct, 0, sizeof(vs_at_cmd_struct));
        memcpy(mmi_va_struct, vs_sms_ctx, sizeof(vs_at_cmd_struct));
        VECTOR_PushBack(vec_mmi_vsat, mmi_va_struct);
    }
    else
    {
        LOGD(L_CMD, L_V5, "i need a bigger place :");
    }

    LOGD(L_CMD, L_V8, "vector_size:%d", VECTOR_Size(vec_mmi_vsat));

}

static void track_at_vs_fatch(vs_at_cmd_struct *outstruct)
{
    vs_at_cmd_struct* vatruct = NULL;
    if(NULL == vec_mmi_vsat)
    {
        VECTOR_CreateInstance(vec_mmi_vsat);
    }
    else if(VECTOR_Size(vec_mmi_vsat))
    {
        vatruct = VECTOR_At(vec_mmi_vsat, 0);
        if(vatruct == NULL)
        {
            LOGD(L_CON, L_V3, "VECTOR_At == NULL!!!!!ERROR");
            outstruct->at_length = 0;
            VECTOR_Erase(vec_mmi_vsat, 0, 1);
        }
        else
        {
            memcpy(outstruct, vatruct, sizeof(vs_at_cmd_struct));
            VECTOR_Erase(vec_mmi_vsat, 0, 1);
            Ram_Free(vatruct);
            vatruct = NULL;
        }

    }
    else
    {
        outstruct->at_length = 0;
    }

    LOGD(L_CMD, L_V8, "vector_size:%d,at:%d", VECTOR_Size(vec_mmi_vsat), outstruct->at_length);

}
static int get_vsat_size(void)
{
    if(vec_mmi_vsat)
    {
        return VECTOR_Size(vec_mmi_vsat);
    }
    return 0;
}

static void send_vsat_in_vec(void)
{
    vs_at_cmd_struct get_vsat = {0};
    int vs_cmd_size = get_vsat_size();

    LOGD(L_CMD, L_V5, "%d,at hold:%d", vs_cmd_size, track_at_is_hold());
    if(vs_cmd_size)
    {
        if(track_at_is_hold())
        {
            tr_start_timer(TRACK_SEND_VSAT_TIMER_ID, 2000, send_vsat_in_vec);
        }
        else
        {
            track_at_vs_fatch(&get_vsat);
            if(get_vsat.at_length > 0)
            {
                at_vs_way(&get_vsat);
            }
            else if(vs_cmd_size)
            {
                tr_start_timer(TRACK_SEND_VSAT_TIMER_ID, 800, send_vsat_in_vec);
            }
            if(vs_cmd_size > 60)//大约5分钟
            {
                LOGD(L_CON, L_V1, "at hold die restart device in 5Min %d===", get_vsat.at_length);
                if(KAL_FALSE == track_is_timer_run(TRACK_POWER_RESET_TIMER_ID))
                {
                    tr_start_timer(TRACK_POWER_RESET_TIMER_ID, 5 * 1000, sys_reset);
                }
            }
        }
    }
    else
    {
        LOGD(L_CMD, L_V5, "no cmd in vec===");
    }
}
#endif


void track_at_put_init(void)
{
    LOGD(L_CON, L_V5, "======track_at_put_init");
    memset(&vs_at, 0, VSAT_LEN);
}


/******************************************************************************
    以上为缓存部分
 * --------------------
    以下为串口附加功能处理部分
******************************************************************************/
/******************************************************************************
 * FUNCTION:  - track_set_vs_at_status *
 * DESCRIPTION: - 设置AT指令状态当发短信头后要锁定等待发短信内容
 * Input:
 * Output:
 * Returns:
 *
 * modification history
 * --------------------
 * v1.0  , 30-10-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
void track_set_vs_at_status(enum_vs_at_state t_sta)
{
    LOGD(L_CMD, L_V5, "last:%d ,%d<--", vs_at_status, t_sta);
    vs_at_status = t_sta;
}
/******************************************************************************
 * FUNCTION:  - track_get_vs_at_status *
 * DESCRIPTION: - 获取AT指令目前状态
 * Input:
 * Output:
 * Returns:
 *
 * modification history
 * --------------------
 * v1.0  , 31-08-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
enum_vs_at_state track_get_vs_at_status(void)
{
    LOGD(L_CMD, L_V5, "%d <--", vs_at_status);

    return vs_at_status;
}
/******************************************************************************
 * FUNCTION:  - track_at_is_hold *
 * DESCRIPTION: - AT指令发送状态，是否为不可用状态
 * Input:
 * Output:
 * Returns:
 *
 * modification history
 * --------------------
 * v1.0  , 30-10-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
kal_bool track_at_is_hold(void)
{
    return (kal_bool)vs_at_status;
}

#if 0
static DCL_HANDLE tr_at_get_handle(void)
{
    static DCL_HANDLE handle = -1;

    if(handle == -1)
    {
        handle = DclSerialPort_Open(track_get_at_port(), 0);  //MagicNing  最好在这里检查一下UART的所有者是不是ATCI
    }
    return handle;
}
#endif /* 0 */

kal_bool track_vs_at_sms_at_rsp(char * rsp_data, int at_len)
{
    char * p = NULL, * p2 = NULL;
    kal_bool clear_sms_cb = KAL_FALSE;

    LOGD(L_CMD, L_V5, "");
    
    if(rsp_data == NULL || at_len == 0 || ishanld)
    {
        //RamBuffer_Free(rsp_msg);
        return KAL_TRUE;
    }

    if(strstr(rsp_data, ">"))
    {
        LOGD(L_CMD, L_V5, ">>>>>>");
        track_sms_send_rsp(1);
    }
    else if(strstr(rsp_data, vs_at_cmd.at_ctx))
    {
        LOGD(L_CMD, L_V5, "======");
        track_sms_send_rsp(2);
    }

    if(strstr(rsp_data, "OK"))
    {
        LOGD(L_CMD, L_V5, "SEDN or Write MSG OK");
        clear_sms_cb = track_sms_send_rsp(0);
    }
    else if(strstr(rsp_data, "ERROR"))
    {
        LOGD(L_CMD, L_V5, "SEDN or Write MSG ERROR");
        track_sms_send_rsp(-1);
        clear_sms_cb = KAL_TRUE;
    }
    else
    {
        LOGD(L_CMD, L_V1, "is not ok ,not error yet ?");
        clear_sms_cb = KAL_FALSE;
    }

    return clear_sms_cb;
}

static kal_bool track_is_customer_cmd(const void * cmdctx, int at_len)
{
    char cst_cmd_head[16] = {0};

    //at_len = (at_len > 15 ? 15 : at_len);
    if(at_len > 15)
    {
        at_len = 15;
    }

    memset(cst_cmd_head, 0, 16);
    memcpy(cst_cmd_head, cmdctx, at_len);
    track_fun_toUpper(cst_cmd_head);
    LOGD(L_CMD, L_V8, "track_fun_toUpper {%s}", cst_cmd_head);
    if (strstr(cst_cmd_head, "AT^GT_"))
    {
        return KAL_TRUE;
    }
    return KAL_FALSE;
}


#if 0
低调调的分割
#endif
#include "Tst_def.h"

void track_send_at_to_l4c(kal_uint8 *data_ptr, kal_uint16 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *Message;
    tst_inject_string_struct *myMsgPtr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    LOGD(L_CMD, L_V5, "");

    if((data_ptr == NULL) || (length >= 128/*INJECT_STRING_TO_MODULE_MAX_LENGTH*/))
    {
        return;
    }

    myMsgPtr = (tst_inject_string_struct*) construct_local_para(sizeof(tst_inject_string_struct), TD_CTRL);
    if(myMsgPtr == NULL)
    {
        track_cust_restart(38, 0);
    }
    memset(myMsgPtr->string , 0, 128/*INJECT_STRING_TO_MODULE_MAX_LENGTH*/);
    memcpy(myMsgPtr->string, data_ptr , length);
    myMsgPtr->params_len = length ;
    myMsgPtr->ref_count = 1 ;
    myMsgPtr->index = 0 ;
    
    Message = (ilm_struct *)allocate_ilm(MOD_MMI);
    if(Message == NULL)
    {
        track_cust_restart(39, 0);
    }
    Message->src_mod_id = MOD_MMI;
    Message->dest_mod_id = MOD_L4C;
    Message->sap_id = INVALID_SAP;
    Message->msg_id = (msg_type)MSG_ID_TST_INJECT_STRING;
    Message->local_para_ptr = (local_para_struct*) myMsgPtr;
    Message->peer_buff_ptr = NULL;
    msg_send_ext_queue(Message);

}

static void at_vs_way(vs_at_cmd_struct *vs_sms_ctx)
{
    static int way_index = 0;

    if(vs_sms_ctx == NULL || vs_sms_ctx->at_ctx == NULL || vs_sms_ctx->at_length == 0)
    {
        LOGD(L_CMD, L_V1, "return");
        return;
    }
    if(track_is_customer_cmd(vs_sms_ctx->at_ctx, vs_sms_ctx->at_length))
    {
        LOGD(L_CMD, L_V5, "is cusotmer at");
        return;
    }
    if(MAX_CMD_LEN <= vs_sms_ctx->at_length)
    {
        vs_sms_ctx->at_length = MAX_CMD_LEN - 1;
    }

    memcpy(&vs_at_cmd , vs_sms_ctx, sizeof(vs_at_cmd_struct));
    LOGD(L_CMD, L_V5, "模拟AT:%d", way_index++);

    if(track_get_at_port() == 4 || 1 == track_drv_uart1_mode(0xff))
    {
        track_send_at_to_l4c(vs_sms_ctx->at_ctx, vs_sms_ctx->at_length);
    }
    else
    {
        track_at_to_atci_send(vs_sms_ctx->at_ctx, vs_sms_ctx->at_length);
    }
    track_uart_data_analysis(1, vs_sms_ctx->at_ctx, vs_sms_ctx->at_length);

}

void tr_at_vs_ctx(vs_at_cmd_struct *vs_sms_ctx)
{

    if(vs_sms_ctx == NULL || vs_sms_ctx->at_ctx == NULL)
    {
        LOGD(L_CMD, L_V1, "return");
        return;
    }
    if(vs_sms_ctx->at_length > 127)
    {
        vs_sms_ctx->at_length = 127;
    }

    at_vs_way(vs_sms_ctx);

}

void tr_at_vs(vs_at_cmd_struct *vs_at_ctx)
{
    static kal_bool slock = KAL_FALSE;

    if(vs_at_ctx == NULL || vs_at_ctx->at_ctx == NULL)
    {
        LOGD(L_CMD, L_V1, "return");
        return;
    }
    if(vs_at_ctx->at_length > 127)
    {
        vs_at_ctx->at_length = 127;
    }

    if(slock || track_at_is_hold() || get_vsat_size())
    {
        track_at_vs_push(vs_at_ctx);
        LOGD(L_CON, L_V3, "!!has one vsat in vec,before at:%d size:%d %d--->", track_at_is_hold(), get_vsat_size(), slock);

        if(KAL_FALSE == track_is_timer_run(TRACK_SEND_VSAT_TIMER_ID))
        {
            tr_start_timer(TRACK_SEND_VSAT_TIMER_ID, 1000, send_vsat_in_vec);
        }
    }
    else
    {
        slock = KAL_TRUE;
        at_vs_way(vs_at_ctx);
        slock = KAL_FALSE;

    }
}

/******************************************************************************
 * FUNCTION:  - track_at_vs_send *
 * DESCRIPTION: -  *    在MMI层直接调用此函数下发AT指令到底层  *
 * Input: char * cmd_msg 标准字符串，请以 \0  结尾
 * Output:
 * Returns:
 * modification history
 * --------------------
 * v1.0  , 01-09-2012,    written
 * --------------------
 ******************************************************************************/
void track_at_vs_send(char * cmd_msg)
{
    kal_uint16 at_len = 0;
    vs_at_cmd_struct vs_sms = {0};

    if(cmd_msg == NULL)
    {
        LOGD(L_CMD, L_V1, "return");
        return;
    }
    at_len = strlen(cmd_msg);
    if(at_len > MAX_CMD_LEN - 1)
    {
        at_len = MAX_CMD_LEN - 1;
    }
    LOGD(L_CMD, L_V6, "%d,%s", at_len, cmd_msg);

    memcpy(vs_sms.at_ctx, cmd_msg, at_len);
    vs_sms.at_cmd_callback = NULL;
    snprintf(vs_sms.at_head, sizeof(vs_sms.at_head), "NULL");
    vs_sms.at_type = AT_CUSTOMER;
    vs_sms.at_length = at_len;

    tr_at_vs(&vs_sms);
}


void track_at_vs_send_sms(vs_at_cmd_struct *vs_sms_ctx)
{

    if(vs_sms_ctx->at_ctx == NULL)
    {
        LOGD(L_CMD, L_V1, "return");
        return;
    }
    if(vs_sms_ctx->at_length > 127)
    {
        vs_sms_ctx->at_length = 127;
    }

    at_vs_way(vs_sms_ctx);
}

kal_uint8 not_reset(kal_uint8 reset)
{
    static kal_uint8 _reset = 0;
    if(reset == 0 || reset == 1)
    {
        _reset = reset;
    }
    return _reset;
}
/******************************************************************************
            以上为模拟串口处理部分
            以下为AT指令下发部分
 ******************************************************************************/
/******************************************************************************
 * FUNCTION:  - track_device_reset *
 * DESCRIPTION: -
 *    使用AT指令进行GSM重启，send AT+CFUN=0  and AT+CFUN=1
AT+CFUN = 0 turn off radio and SIM power. (supported only for feature phone with feature phone)
AT+CFUN = 1, 1 or AT+CFUN=4,1 can reset the target. (supported only for feature phone)
AT+CFUN = 1 can enter normal mode. (supported only for module solution)
AT+CFUN = 4 can enter flight mode. (supported only for module solution)
 *
 * modification history
 * --------------------
 * v1.0  , 10-08-2012,    written
 * --------------------
 ******************************************************************************/
static void sys_reset(void)
{
    if(not_reset(0xFF) == 1)
    {
        LOGS("=====sys_reset=not reset return====");
        return;
    }
#if defined (__NETWORK_LICENSE__)
    //LOGS("test mode (restart disable)");
#else
    OTA_sys_assert_reset();
#endif /* __NETWORK_LICENSE__ */
}

void track_at_set_handfree(void)
{
    LOGD(L_CMD, L_V2, "");
    track_at_vs_send(AT_ESAM);
    tr_start_timer(TRACK_AT_HAND_FREE_TIMER_ID, 5 * 1000, track_at_set_handfree);
}

/******************************************************************************
 * FUNCTION:  - track_at_set_ecpi
 * DESCRIPTION: - 设置通话时状态自动更新
 * Input:
 * Output:
 * Returns:
 * modification history
 * --------------------
 * v1.0  , 07-11-2012,  wangqi  written
 * --------------------
 ******************************************************************************/

void track_at_init_setting(void)
{
    track_sim_main();
    track_sim_sms_set_revicer(track_sim_get_sms_callback);//接收查询发件箱结果

    LOGD(L_CON, L_V4, "");
}

#endif /* __AT_CA__ */

void track_device_reset(int sec)
{
    LOGD(L_CON, L_V3, "%d", sec);//return;//temp
    if(sec < 0)
    {
        sec = 1;
    }
    if(sec == 0)
    {
        sys_reset();
    }
    else
    {
#ifdef __NULL_SERVER__
        tr_start_timer(TRACK_POWER_RESET_TIMER_ID, sec*1000, sys_reset);
#endif /* __NULL_SERVER__ */
        track_check_tick(3, (char*)sec);
    }
}



