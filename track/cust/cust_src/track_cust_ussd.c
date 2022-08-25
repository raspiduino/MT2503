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
typedef enum
{
    SRV_SS_ACT_IDLE = 0, /* no action */
    SRV_SS_ACT_CALL_FORWARD,    /* call forwarding. srv_ss_call_forward_req_struct, srv_ss_call_forward_rsp_struct */
    SRV_SS_ACT_CALL_BAR,    /* call barring. srv_ss_call_bar_req_struct, srv_ss_call_bar_rsp_struct */
    SRV_SS_ACT_CALL_WAIT,   /* call waiting. srv_ss_call_wait_req_struct, srv_ss_call_wait_rsp_struct */
    SRV_SS_ACT_CALL_IDENTIFICATION, /* calling/connected line dentification. request is not supported for now (use SRV_SS_ACT_SS_OPERATION instead), srv_ss_call_id_rsp_struct */
    SRV_SS_ACT_CNAP, /* calling name presentation. request is not supported for now (use SRV_SS_ACT_SS_OPERATION instead), srv_ss_cnap_rsp_struct */
    SRV_SS_ACT_CCBS, /* completion of calls to busy subscriber. request is not supported for now (use SRV_SS_ACT_SS_OPERATION instead), srv_ss_ccbs_rsp_struct */
    SRV_SS_ACT_EMLPP, /* eMLPP. request is not supported for now (use SRV_SS_ACT_SS_OPERATION instead), srv_ss_emlpp_rsp_struct */
    SRV_SS_ACT_USSD, /* USSD. use SRV_SS_ACT_SS_OPERATION for request, srv_ss_ussd_rsp_struct */
    SRV_SS_ACT_SS_OPERATION, /* send any ss strings. srv_ss_operation_req_struct, cast according to opcode in srv_ss_rsp_struct */
    SRV_SS_ACT_ABORT, /* abort ss session. srv_ss_abort_req_struct, NULL (always success) */
    SRV_SS_ACT_TOTAL /* max enum */
} srv_ss_act_enum;

typedef enum
{
    SRV_SS_RESULT_OK = 0 ,  /* success. result is OK */
    SRV_SS_RESULT_INVALID_INPUT,    /* fail. the input parameter is invalid input */
    SRV_SS_RESULT_BUSY, /* fail. ss service is waiting for response or is in ss session */
    SRV_SS_RESULT_NOT_AVAILABLE, /* fail. not available */
    SRV_SS_RESULT_ABORT, /* fail. action is aborted */
    SRV_SS_RESULT_INVALID_NUMBER,      /* fail. the input parameter is invalid number */
    SRV_SS_RESULT_CMD_NOT_SUPPORT, /* fail. the command is not supported by ss service for now */
    SRV_SS_RESULT_PASSWD_WRONG, /* fail. wrong password */
    SRV_SS_RESULT_PASSWD_BLOCK, /* fail. password blocked */ 
    SRV_SS_RESULT_AUTO_REJECT,  /* fail. it's caused by auto reject */
    SRV_SS_RESULT_SESSION_NOT_EXIST, /* ss session doesn't exist */
    SRV_SS_RESULT_ERROR_WITH_PS_CAUSE,    /* fail. error with ps cause, used in responses by the protocol stack */
    SRV_SS_RESULT_UNSPECIFIED_ERROR,    /* fail. it's general error */
    SRV_SS_RESULT_END_OF_ENUM   /* Max result cause */
} srv_ss_result_enum;

/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/
typedef struct
{
    kal_uint8	ref_count;
    kal_uint8    lp_reserved;
    kal_uint16	msg_len;
    l4c_result_struct	result;
    kal_uint8	para_present;
    kal_uint8	op_code;
    kal_uint8	dcs;
    kal_uint8	ussd_str[MAX_DIGITS_USSD];
    kal_uint8	length;
    kal_uint8	ussd_version;
} mmi_ss_ussd_rsp_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 ton_npi;
   kal_uint8 length;
   kal_uint8 ss_dcs;
   kal_uint8 ss_string[MAX_DIGITS_USSD];
   kal_bool change_phase_req;
   kal_uint8 type_of_modification;
   kal_uint8 cf_number_length; /* [MAUI_01722785] add cf number interface */
   kal_uint8 explicit_ss_op; //MAUI_02553565 explicit SS operation
} l4ccsm_ciss_ss_parse_req_struct;

/*****************************************************************************
*  Local variable                       局部变量
*****************************************************************************/
static Cmd_Type g_cm_type = 0;
static char g_ph_num[CM_HEAD_PWD_MXA] = {0};
static kal_uint8 g_num_type = 0;
static kal_uint8 g_stamp[4] = {0};

/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/

/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/

/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/

#if 0
#endif /* 0 */
/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/


void track_ussd(mmi_ss_ussd_rsp_struct *par)
{
    char *str = "Can not analyse.", *p;
    if(strlen(par->ussd_str) > 0)
    {
        p = par->ussd_str;
    }
    else
    {
        p = str;
    }
    if(g_cm_type == CM_SMS)
    {
        track_cust_sms_send(g_num_type, g_ph_num, KAL_TRUE, p, strlen(p));
    }
   else if(g_cm_type == CM_ONLINE)
    {
        track_cust_paket_msg_upload(g_stamp, KAL_FALSE, p, strlen(p));
    }
    LOGS("USSD Recv: %s", p);
}

void track_ussd_send(char *ussd_str, kal_uint8 len)
{
    l4ccsm_ciss_ss_parse_req_struct *myMsgPtr = NULL;
    if(len >= MAX_DIGITS_USSD)
    {
        return;
    }
    if(ussd_str[len-2] == 0x0D && ussd_str[len-1] == 0x0A)
    {
        len -= 2;
    }
    else if(ussd_str[len-1] == 0x0D)
    {
        len--;
    }
    myMsgPtr = (l4ccsm_ciss_ss_parse_req_struct*) construct_local_para(sizeof(l4ccsm_ciss_ss_parse_req_struct), TD_RESET);
    myMsgPtr->ton_npi = 0x81;
    myMsgPtr->ss_dcs = 0x0f;
    myMsgPtr->length = len;
    memcpy(myMsgPtr->ss_string, ussd_str, myMsgPtr->length);
    track_fun_msg_send(MSG_ID_L4CCSM_CISS_SS_PARSE_REQ, myMsgPtr, MOD_MMI, MOD_CSM);
}

void track_ussd_req(CMD_DATA_STRUCT *cmd, char *data, kal_uint8 len)
{
    LOGD(L_APP, L_V5, "cm_type:%d, ph_num:%s, data:%s", cmd->return_sms.cm_type, cmd->return_sms.ph_num, data);
    g_cm_type = cmd->return_sms.cm_type;
    if(g_cm_type == CM_SMS)
    {
        g_num_type = cmd->return_sms.num_type;
        memcpy(g_ph_num, cmd->return_sms.ph_num, CM_HEAD_PWD_MXA);
    }
    else if(g_cm_type == CM_ONLINE)
    {
        memcpy(g_stamp, cmd->return_sms.stamp, 4);
    }
    track_ussd_send(data, len);
}

