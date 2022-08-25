/******************************************************************************
 * track_at_sms.h -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *
 *
 * modification history
 * --------------------
 * v1.0   2012-09-07,  wangqi create this file
 *
 ******************************************************************************/
#ifndef TR_SMSH
#define TR_SMSH
#ifdef __AT_CA__
#include "Ps_public_struct.h"
#include "track_os_data_types.h"
/*****************************************************************************
*  Define			    宏定义
*****************************************************************************/
#define  SMS_ADDRESS_MAX_SIZE       16
#define  GROUP_SEND_MAX	            6
#define  SMS7BITMAX                 160
#define  SMSUCS2MAX                 140

#define  LONG_SMS_7BIT_MAX          152
#define  LONG_SMS_UCS2_MAX          134
// 用户信息编码方式
#define GSM_7BIT                    0
#define GSM_8BIT                    4
#define GSM_UCS2                    8

#define SMS_MAX_SIZE                640     //可支持4条短信

#define SMS_SENDER_BOX_LENGTH       10      //只处理前10条收件箱
#define SMS_RESEND_LIMIT            3
#define SMS_RESEND_INTERVAL_TIME    60000
/*****************************************************************************
* Typedef  Enum         枚举
*****************************************************************************/
typedef enum
{
    SMS_PDU_INVALID = 0,
    SMS_PDU_DELIVER,
    SMS_PDU_SUBMIT,
    SMS_PDU_STATUS_REPORT
} SmsPduType;

typedef enum
{
    sSTANDBY,
    sSEND_HEAD,
    sSEND_CTX,
    sSEND_WAIT,
    sSS_MAX
} SMS_STATUS_ENUM;

typedef enum
{
    sSENDOK,
    sCTXTOOLONG,
    sSIMERROR,
    sNUMBERERROR,
    sSENDERROR,
    sSENDHEADOVER,
    sSENDOVERTIME,
    sSENDUNKNOW,
    sSSR_MAX
} SMS_SEND_RESULT_ENUM;

typedef enum
{
    SMS_MS_MT,//直接发送对方
    SMS_SENDER_BOX,//存发件箱
    SMS_DIR_MAX
}SMS_DIRECTION;

/*****************************************************************************
*  Struct			    数据结构定义
*****************************************************************************/
typedef struct
{
    kal_uint8           nocount;
    kal_uint8           num_type;
    char*               numbers[GROUP_SEND_MAX];//phone numbers
    kal_bool            codetype;   //isascii?
    char*               ctx;
    kal_uint16          ctxlen;//内容长度unicode为汉字长度*2
    kal_uint32          index;//序列号
    SMS_DIRECTION       smsdir;
} sms_msg_struct;

typedef struct
{
    kal_uint32              index;
    SMS_DIRECTION           dir;
    SMS_STATUS_ENUM         status;
    SMS_SEND_RESULT_ENUM    result;
} sms_send_rsp_struct;

// 短消息参数结构，编码/解码共用
// 其中，字符串以0结尾
typedef struct
{
    char            SCA[16];       // 短消息服务中心号码(SMSC地址)
    kal_uint8       SCAL;          //SCA号码长度
    kal_uint8       MR;            //
    kal_uint8       P_TYPE;
    kal_uint8       ODAL;          // 呼入呼出号码长度
    char            TPA[32];       // 目标号码或回复号码(TP-DA或TP-RA)
    char            TP_PID;        // 用户信息协议标识(TP-PID)
    char            TP_DCS;        // 用户信息编码方式(TP-DCS)
    char            TP_SCTS[16];   // 服务时间戳字符串(TP_SCTS), 接收时用到
    char            TP_UD[SMS_MAX_SIZE];    // 原始用户信息(编码前或解码后的TP-UD)
    kal_uint32      index;         // 短消息序号，在读取时用到
    kal_uint16      TP_UDL;         //user data length
    kal_uint8       TP_Max_p;       //短信内容一共有多少包
    kal_uint8       TP_Seq_p;       //当前包号
    kal_uint16      TP_Unique;       //分包后同步唯一标识
    kal_uint8       TP_Rev;//一共收到多少个包
} SM_PARAM;

typedef struct
{
    char            SCA[16];       // 短消息服务中心号码(SMSC地址)
    kal_uint8       SCAL;          // SCA号码长度
    kal_uint8       MR;            //
    kal_uint8       P_TYPE;
    kal_uint8       ODAL;          // 呼入呼出号码长度
    char            TPA[32];       // 目标号码或回复号码(TP-DA或TP-RA)
    char            TP_PID;        // 用户信息协议标识(TP-PID)
    char            TP_DCS;        // 用户信息编码方式(TP-DCS)
    char            TP_SCTS[16];   // 服务时间戳字符串(TP_SCTS), 接收时用到
    char*           TP_UD;         // 短信内容
    kal_uint16      TP_UDL;        // 短信内容长度
    kal_uint32      index;         // 短消息序号，在读取时用到
    kal_uint8       TP_Max_p;      // 短信内容一共有多少包
    kal_uint8       TP_Seq_p;      // 当前包号
    kal_uint16      TP_Unique;     // 分包后同步唯一标识
    kal_uint8       TP_Rev;        // 一共收到多少个包
} track_sms_param;

typedef struct
{
    kal_uint8	fo;
    kal_uint8	scts[7];
    l4c_number_struct	sca_number;
    l4c_number_struct	oa_number;
    kal_uint8	pid; /* smsal_pid_enum */
    kal_uint8	dcs; /* smsal_dcs_enum */
    kal_uint8	ori_dcs;
    kal_uint16	index;
    kal_uint16	dest_port;
    kal_uint16	src_port;
    kal_uint8	mti;
    kal_uint8	display_type;
    kal_uint8	storage_type;
    smsal_concat_struct concat_info;
    kal_uint8    count;
    kal_uint16	data_len[16];
    kal_uint8	*pdata[16];
} mmi_sms_delivers_struct;


typedef struct
{
    char            sms_ctx[SMS_MAX_SIZE];
    kal_uint16      sms_len;//发送内容的字符个数
    kal_uint16      sms_size;//数组的真实长度
    kal_uint16      sp_size;//AT长度120 分包后
    kal_uint8       sms_error_conut;//发送错误次数
    kal_uint8       sms_overtime_count;//发送内容或者头部超时
    kal_uint32		sms_index;//应用层发送序列号
    SMS_STATUS_ENUM sms_status;
    SMS_DIRECTION   sms_dir;
    kal_uint8       smscodetype;//发送时的唯一标号作用于分包短信
} sms_submit_pdu;



typedef struct
{
    char            encode_number[64];
    char            encode_ctx[1024];
    char*           readptr;
    int             inumlen;
    int             ictxlen;
    int             tpacket;
    int             curpacket;
    int             sendlen;
    int             index;
    SMS_DIRECTION   sms_dir;
    kal_uint16      ctxlimit;
    kal_uint8       smscodetype;
    kal_uint8       tp_index;//发送时唯一识别标致

} sms_ctx_encode_struct;

typedef void (*sms_get_senderbox_handlerPtr)(void); 
/*****************************************************************************
* Local variable            局部变量
*****************************************************************************/

/****************************************************************************
* Global Variable           全局变量
*****************************************************************************/

/*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/

/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/

/*****************************************************************************
 *  Local Functions	            本地函数
*****************************************************************************/


/*****************************************************************************
 *  Global Functions            全局函数
*****************************************************************************/
extern void track_sms_set_auto_to_serial(void);
extern void track_sms_receive(int sms_length, char * sms_context);

/******************************************************************************
 * FUNCTION:  - track_app_sms_rsp
 * DESCRIPTION: -短信AT发送结果 
 * Input:
 * Output:
 * modification history
 * --------------------
 * v1.0  , 26-10-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
extern kal_bool track_sms_send_rsp(kal_int8 result);


/******************************************************************************
 * FUNCTION:  - track_sms_sender
 * DESCRIPTION: -支持最多 GROUP_SEND_MAX 个号码群发短信
 * Input:
    kal_uint8       nocount; // 发送给多少个号码
    char*           numbers[GROUP_SEND_MAX];//phone numbers
    kal_bool        codetype;//isascii? //是否为ASCII码?
    char*           ctx;//短信内容
    kal_uint16      ctxlen;//内容长度unicode为汉字长度*2
    kal_uint32      index;//序列号
 * Output:
 * modification history
 * --------------------
 * v1.0  , 26-10-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
extern void track_sms_sender(sms_msg_struct *sms_send);
extern kal_bool track_sms_get_send_status(void);

extern void track_sim_clean_allsms(void);
extern void track_sim_clean_read_sms_reveicebox(void);
extern void track_sim_read_unreadsms_reveicebox(void);
extern void track_sim_clean_reveicebox(void);
extern void track_sim_clean_senderbox(void);
extern void track_sim_sms_set_revicer(sms_get_senderbox_handlerPtr callback);
extern kal_uint8 track_sim_get_sms_from_senderbox(void);

extern void track_sms_clean_out_vec(void);
#endif
#endif/*TR_SMSH*/
