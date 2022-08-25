/******************************************************************************
 * track_drv_network_license.c - 
 * 
 * Copyright .
 * 
 * DESCRIPTION: - 
 *
 *      入网许可认证   	__NETWORK_LICENSE__
 *
 *          车载无屏产品 CTA/3C/CE/FCC 认证软件
 *----------------------------------------------------------------------------------
 * 
 *  1、屏蔽连接服务器和重启机制，避免影响正常的射频测试；
 *
 *  2、开机30秒自动附着网络，方便建立GPRS测试连接；
 *
 *  3、按键拨打112，没有按键则开机20s自动呼叫112，方便射频建立连接；所有来电自动接听。
 *
 *-----------------------------------------------------------------------------------
 * modification history
 * --------------------
 * v1.0   2013-04-02,  chengjun create this file
 * 
 ******************************************************************************/

#if defined (__NETWORK_LICENSE__)

/****************************************************************************
*  Include Files                        包含头文件
*****************************************************************************/
#include "stack_ltlcom.h"
#include "stack_msgs.h"
#include "stdlib.h"
#include "kal_public_defs.h"
#include "track_os_data_types.h"
#include "track_os_timer.h"
#include "l4c_common_enum.h"
#include "GlobalConstants.h"

/*****************************************************************************
*  Define                               宏定义
******************************************************************************/

/*****************************************************************************
*  Typedef  Enum                        枚举定义
*****************************************************************************/

/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	type;   /* l4c_gprs_connect_type_enum */
}nw_set_gprs_connect_type_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool	result;
}nw_set_gprs_connect_type_rsp_struct;
    
/*****************************************************************************
*  Local variable                       局部变量
*****************************************************************************/

/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/

/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/
extern void track_press_key_dial_112(void);
/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/
/******************************************************************************
 *  Function    -  track_drv_make_call_112
 * 
 *  Purpose     -  主叫112
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 02-04-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_drv_make_call_112(void)
{
    track_press_key_dial_112();
}

#if 1
/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/
#endif


/******************************************************************************
 *  Function    -  track_drv_network_license_key_make_call
 * 
 *  Purpose     -  矩阵键盘的注册呼叫112
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 02-04-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_network_license_key_make_call(void)
{
#if defined(__GT300S__)||defined(__GT300S__)
//矩阵键盘--注册按键响应
    track_drv_set_key_handler(track_drv_make_call_112, KEY_SOS, KEY_EVENT_DOWN);

#else
//没有按键--开机20秒主动呼叫，提前注册

#endif
}

/******************************************************************************
 *  Function    -  track_drv_network_license_eint_make_call
 * 
 *  Purpose     -  中断型按键响应呼叫112
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 02-04-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_network_license_eint_make_call(void)
{
#if defined (__GT300S__)
//矩阵键盘--注册按键响应

#elif defined(__NT36__)
//中断型按键--中断触发回调
    track_drv_make_call_112();

#else
//没有按键--开机20秒主动呼叫，提前注册

#endif

}

/******************************************************************************
 *  Function    -  track_drv_network_license_auto_make_call
 * 
 *  Purpose     -  没有按键的开机注册20秒后呼叫112
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 02-04-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_network_license_auto_make_call(int ms)
{
    //没有按键--开机20秒主动呼叫，提前注册
    tr_start_timer(NETWORK_LICENSE_AUTO_MAKE_CALL_TIMER_ID,ms,track_drv_make_call_112);
}

/******************************************************************************
 *  Function    -  track_drv_network_license_auto_answer_action
 * 
 *  Purpose     -  所有来电自动接听
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 02-04-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_network_license_auto_answer_action(void)
{
    track_send_at_accept_call();
}
#if 0//已经在网络连接的时候创建//modify by zengping & liujunwu

/******************************************************************************
 *  Function    -  track_drv_network_license_gprs_attach_req
 * 
 *  Purpose     -  GPRS附着请求
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 02-04-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_network_license_gprs_attach_req(void)
{
    ilm_struct *ilm_ptr;
    nw_set_gprs_connect_type_req_struct *myMsgPtr = NULL;

    myMsgPtr = (nw_set_gprs_connect_type_req_struct*) construct_local_para(sizeof(nw_set_gprs_connect_type_req_struct),TD_CTRL);
    myMsgPtr->type = L4C_WHEN_NEEDED;

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->dest_mod_id = MOD_L4C;
    ilm_ptr->sap_id = INVALID_SAP;
    ilm_ptr->msg_id = (msg_type) MSG_ID_MMI_NW_SET_GPRS_CONNECT_TYPE_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) myMsgPtr;
    ilm_ptr->peer_buff_ptr = NULL;
    msg_send_ext_queue(ilm_ptr);  
}


/******************************************************************************
 *  Function    -  track_drv_network_license_gprs_attach_rsp
 * 
 *  Purpose     -  GPRS附着响应 
 * 
 *  Description -  MOD工程裁剪，L4C收到了设置请求后，但不返回结果，因此该函数不会被执行! 
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 02-04-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_network_license_gprs_attach_rsp(void *msg)
{
    nw_set_gprs_connect_type_rsp_struct *gprs_type=(nw_set_gprs_connect_type_rsp_struct *)msg;

    LOGS("gprs_attach result=%d",gprs_type->result);    
}
#endif /* 0 */


#endif /* __NETWORK_LICENSE__ */

