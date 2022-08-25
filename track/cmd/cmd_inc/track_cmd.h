/******************************************************************************
 * track_cmd.h -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        指令解析
 *
 * modification history
 * --------------------
 * v1.0   2012-07-21,  WangQi create this file
 *
 ******************************************************************************/

#ifndef _TRACK_COMMANDS_H
#define _TRACK_COMMANDS_H

/****************************************************************************
* Include Files                   		包含头文件
*****************************************************************************/
#include "kal_public_defs.h"
#include "track_os_data_types.h"
#include "custom_nvram_editor_data_item.h"
#include "track_os_ell.h"
#include "track_os_paramete.h"

/*****************************************************************************
 *  Define					宏定义
*****************************************************************************/
#define CM_PARAM_LONG_LEN_MAX  320
#define CM_PARAM_LEN_MAX 100
#define CM_HEAD_PWD_MXA 32

#define GPS_COMMA_UNIT_MAX 16

/*****************************************************************************
* Typedef  Enum
*****************************************************************************/

typedef enum
{
    CM_AT,              //AT来源的指令
    CM_SMS,             //短信来源的指令
    CM_ONLINE,          //网络来源的指令
    CM_ONLINE2,         //网络来源的指令
    CM_PARAM_CMD,
    CM_TEST_ONLINE,
    CM_VS_AT,
    CM_VS_EX,
    CMD_NET2,
    #if defined(__NF2318__)
    CMD_ONLINE_NF2318,
    #endif
    CMD_MAX_TYPE
} Cmd_Type;

typedef enum
{
    CM_Main,
#if defined(__GT02B__)
    CM_PWD,
#endif
    CM_Par1,
    CM_Par2,
    CM_Par3,
    CM_Par4,
    CM_Par5,
    CM_Par6,
    CM_Par7,
    CM_Par8,
    CMD_MAX_Pars
} Cmd_Pars;



/*****************************************************************************
 *  Struct					数据结构定义
*****************************************************************************/

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8           cmd_data[CM_PARAM_LEN_MAX];
    kal_uint16          cmd_length;
    kal_uint16          target;
} cmd_req_struct;

typedef enum
{
    Error_110,
    CMD_Cmd_Ret_Code
} Cmd_Ret_Code;

typedef struct
{
    kal_uint8           reply_character_encode; // 0 ASCII   1 UTF-16BE   2 GB2312
    kal_uint8           num_type;               // 号码类型//145国际 160 国内//129 10086 飞信
    kal_uint8           stamp[4];               // 标记位，当前用于网络下发的指令需要保存服务器提供的序列号
    char                ph_num[CM_HEAD_PWD_MXA];// 来源  国外卡需要在电话号码前加入+号，否则会出现短信无法发出问题
    Cmd_Type            cm_type;
} cmd_return_struct;

typedef struct
{
    U8                  part;//参数个数
    char                rcv_msg_source[CM_PARAM_LONG_LEN_MAX];
    char                rcv_msg[CM_PARAM_LONG_LEN_MAX];
    U16                 rcv_length;
    char                *pars[GPS_COMMA_UNIT_MAX];
    Cmd_Ret_Code        rsp_code;
    char                rsp_msg[CM_PARAM_LONG_LEN_MAX];
    U16                 rsp_length;
    kal_uint8           supercmd;               // 为1 的表示当前的指令属于特殊权限指令，否则属于正常指令
    kal_uint8           cmd_pwd_type;           // 1 当前指令匹配用户密码；2 当前指令匹配超级密码；3 当前指令与用户密码和超级密码都匹配
    kal_uint8           character_encode;       // 0 ASCII   1 UTF-16BE   2 GB2312
    kal_uint8           flag;                   // 个别项目使用的特殊标记
    cmd_return_struct   return_sms;
} CMD_DATA_STRUCT;

typedef struct
{
    Cmd_Type            cm_type;
    char                ph_num[CM_HEAD_PWD_MXA];//来源
    kal_uint8           character_encode;       // 0 ASCII   GSM_UCS2 UTF-16BE
} CMD_DATA_STRUCT2;

typedef struct
{
    U16                 sms_index;
    U16                 len;  //短信息长度
    char                content[320];
    char                num[21];
} GPS_SMS_STRUCT;

typedef void (*FuncPtrEx) (CMD_DATA_STRUCT *);

typedef struct
{
    const S8            *cmd_string;
    FuncPtrEx           func_ptr;
    BOOL                valid;
} CMD_ENGINE_STRUCT;


/****************************************************************************
* Global Variable           引用的全局变量
*****************************************************************************/

/****************************************************************************
* Global Variable - Extern          引用全局函数
*****************************************************************************/
extern kal_int8 track_command_operate(CMD_DATA_STRUCT * command);
extern BOOL track_cmd_check_authentication(CMD_DATA_STRUCT * _cmd);
extern void track_cmd_send_rsp(Cmd_Type cm_type,kal_int16 len,char * rsp_msg,kal_uint8 sign);
extern void track_cmd_sms_rsp(CMD_DATA_STRUCT * cmds);
extern void bosch_motion_sensor_NvramData_write(U16 time);//复位传感器设置
#endif  /* _TRACK_COMMANDS_H */
