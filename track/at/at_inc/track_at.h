/******************************************************************************
 * track_at_call.h -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        提供拦截串口返回数据和模拟串口下发指令
 *
 * modification history
 * --------------------
 * v1.0   2012-08-09,  WangQi create this file
 *
 ******************************************************************************/
 #ifndef TRACK_AT_H
 #define TRACK_AT_H
 
 #include "kal_public_defs.h"


 /*****************************************************************************
 *  Define			    宏定义
*****************************************************************************/
#define AT_ATA          "ATA\r\n"
#define AT_CLCC         "AT+CLCC\r\n"
#define AT_CHUP         "AT+CHUP\r\n"

#define SMS_AUTO_SERIAL "AT+CNMI=2,2,0,0,1\r\n"
#define CHECK_SMS_AUTO  "AT+CNMI?\r\n"
#define SMS_CSCA        "AT+CSCA?\r\n"

#define MAX_CMD_LEN         128   //命令码最大长度

#define AT_PUT_BUFFER_SIZE  1024

/*****************************************************************************
* Typedef  Enum         枚举
*****************************************************************************/
typedef enum
{
    V_A_FREE,
    V_A_HOLD,
    V_A_MAX
}enum_vs_at_state;

typedef enum  
{
    AT_VS,
    AT_CUSTOMER,
    V_A_T_MAX
}enum_at_type;  

/*****************************************************************************
 *  Struct			    数据结构定义
*****************************************************************************/
#ifdef __AT_CA__ //MagicNing  for  UART 
typedef struct  
{
    LOCAL_PARA_HDR
    kal_uint16 	put_msg_len;
    kal_uint16      dev;
}uart_put_bytes_ind_struct;  

#endif/*__AT_CA__*/


typedef kal_bool (*at_cmd_callback_handlerPtr)(char * rsp_msg, int len); 

typedef struct
{
    kal_uint8       at_length;
    enum_at_type    at_type;
    kal_uint8       at_ctx[128];
    at_cmd_callback_handlerPtr at_cmd_callback;
    char            at_head[24];
}vs_at_cmd_struct;

/*****************************************************************************
* Local variable            局部变量
*****************************************************************************/

/*****************************************************************************
 *  Local Functions	            本地函数
*****************************************************************************/
extern kal_uint16 track_get_at_port(void);
#ifdef __AT_CA__
extern void track_set_vs_at_status(enum_vs_at_state t_sta);
extern enum_vs_at_state track_get_vs_at_status(void);
extern kal_bool track_at_is_hold(void);
extern void tr_at_vs(vs_at_cmd_struct *vs_at_ctx);
extern void track_at_vs_send(char * cmd_msg);

extern void track_GSM_reset(int sec);
#endif /* __AT_CA__ */

extern void track_at_set_handfree(void);
extern void track_at_set_handset(void);
extern void track_accept_call(void);
extern void track_make_call(char * number);
extern void track_device_reset(int sec);
extern void track_at_init_setting(void);

extern void custom_cmd_send(char* cmd, kal_bool bCheckRes);

extern void track_sim_get_sms_f_s_b_rsp(int type, char * cmgl);

extern kal_bool track_vs_at_sms_at_rsp(char * rsp_data, int at_len);
#endif/*TRACK_AT_H*/
