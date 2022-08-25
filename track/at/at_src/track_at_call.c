/******************************************************************************
 * track_at_call.c -
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
#include "Device.h"
#include "string.h"
#include "stack_msgs.h"
#include "stack_ltlcom.h"

#include "track_at.h"
#include "track_os_timer.h"
#include "track_at_call.h"

#include "track_os_ell.h"

/*****************************************************************************
 *  Define			    宏定义
*****************************************************************************/

/*****************************************************************************
* Typedef  Enum         枚举
*****************************************************************************/
#define MAKECALL_OVERTIME       20000
#define MAKECALL_OVERTIME_LIMET 3
/*****************************************************************************
*  Struct			    数据结构定义
*****************************************************************************/
typedef struct
{
    track_call_state_enum call_state;
    char                call_number[25];
    call_type_enum      call_type;//0 for in 1for out
    kal_bool                call_ring;

} call_msg_struct;
typedef struct
{
    char                cnumber[25];
    kal_uint8           callcounts;
    kal_uint8           callerror_counts;
    kal_uint8           callbusy_counts;
} make_call_info_struct;


/*****************************************************************************
* Local variable            局部变量
*****************************************************************************/
static call_msg_struct  call_msg = {0};
static make_call_info_struct  make_call = {0};
/****************************************************************************
* Global Variable           全局变量
*****************************************************************************/

/*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/
extern kal_uint8 track_fun_check_phone_number(char *number);
/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/

/*****************************************************************************
 *  Local Functions	            本地函数
*****************************************************************************/
static void track_make_call_handle(char *number);

/*****************************************************************************
 *  Global Functions            全局函数
*****************************************************************************/

static void track_call_state_notice_mmi(kal_uint16 type, kal_uint16 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables               track_cust_call_status_change                                 */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;
    call_state_struct *myMsgPtr = NULL;

    myMsgPtr = (call_state_struct*) construct_local_para(sizeof(call_state_struct), TD_CTRL);
    if(myMsgPtr == NULL)
    {
        track_cust_restart(31, 0);
    }
    myMsgPtr->type = type ;
    myMsgPtr->status = status ;

    ilm_ptr = (ilm_struct*)allocate_ilm(MOD_MMI);
    if(ilm_ptr == NULL)
    {
        track_cust_restart(37, 0);
    }
    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->dest_mod_id = MOD_MMI;
    ilm_ptr->sap_id = INVALID_SAP;
    ilm_ptr->msg_id = (msg_type) MSG_ID_CALL_STATUS_NOTICE;
    ilm_ptr->local_para_ptr = (local_para_struct*) myMsgPtr;
    ilm_ptr->peer_buff_ptr = NULL;
    msg_send_ext_queue(ilm_ptr);

}


void track_at_query_incomming_number(void)
{
    LOGD(L_CMD, L_V2, "");
    track_at_vs_send(AT_CLCC);
}

void track_send_at_accept_call(void)
{
    track_at_vs_send(AT_ATA);
    LOGD(L_CMD, L_V2, "ACCEPT CALL");
}


void track_hangup_call(void)
{
    LOGD(L_CMD, L_V5, "call_state:%d", call_msg.call_state);
    track_stop_timer(TRACK_CALL_OVERTIME_TEIMER_ID);
    track_stop_timer(TRACK_CALL_WAIT_TEIMER_ID);

    memset(&call_msg, 0, sizeof(call_msg_struct));

    track_at_vs_send(AT_CHUP);
}


static void make_call_overtime(void)
{
    if(call_msg.call_state == TR_CALL_CONNECT)
    {
        return;
    }
    make_call.callcounts ++;

    LOGD(L_CMD, L_V5, "=====超call_state:%d, type:%d, counts:%d",
         call_msg.call_state, call_msg.call_type, make_call.callcounts);

    if(call_msg.call_type == CALL_MO_OUT)
    {
        call_msg.call_type = CALL_FREE;
        if(call_msg.call_state < TR_CALL_RING)
        {
            call_msg.call_state = TR_CALL_UNKNOW;
        }
    }

    if(make_call.callcounts <= MAKECALL_OVERTIME_LIMET)
    {
        track_hangup_call();
        track_start_timer(TRACK_CALL_OVERTIME_TEIMER_ID, 2000, track_make_call_handle, make_call.cnumber);
    }
    else
    {
        track_call_state_notice_mmi(CALL_MO_OUT, CALL_MO_ATUNRSP);
    }
}

static kal_bool make_call_error(void)
{
    LOGD(L_CMD, L_V5, "call_state:%d, type:%d, counts:%d",
         call_msg.call_state, call_msg.call_type, make_call.callerror_counts);

    if(call_msg.call_state == TR_CALL_CONNECT)
    {
        return KAL_FALSE;
    }

    make_call.callerror_counts++;

    if(make_call.callerror_counts <= MAKECALL_OVERTIME_LIMET && strlen(make_call.cnumber))
    {
        track_start_timer(TRACK_CALL_OVERTIME_TEIMER_ID, 1000, track_make_call, make_call.cnumber);
        return KAL_TRUE;
    }
    return KAL_FALSE;
}

static void track_at_temp_save_out_number(char * out_number)
{
    char cnumber[25] = {0};
    snprintf(cnumber, 24, "%s", out_number);
    LOGD(L_CMD, L_V5,"track_at_temp_save_out_number %s,%s", out_number, cnumber);
    memset(make_call.cnumber, 0, sizeof(make_call.cnumber));
    snprintf(make_call.cnumber, sizeof(make_call.cnumber), "%s", cnumber);
}

static void track_at_daly_make_call(char * out_number)
{
    LOGD(L_CMD, L_V5, "%d, %s,%s,%d", call_msg.call_state, out_number, make_call.cnumber, make_call.callbusy_counts);
    if(call_msg.call_state != TR_CALL_CONNECT)
    {
        make_call.callbusy_counts ++;
    }
    else
    {
        make_call.callbusy_counts = 0;
    }

    if(make_call.callbusy_counts == 10)
    {
        memset(&call_msg, 0, sizeof(call_msg_struct));
        track_hangup_call();
        track_call_state_notice_mmi(CALL_MO_OUT, CALL_MO_ATUNRSP);
        return;
    }
    
    if(KAL_FALSE == track_is_timer_run(TRACK_CALL_WAIT_TEIMER_ID))
    {
        track_at_temp_save_out_number(out_number);
        track_start_timer(TRACK_CALL_WAIT_TEIMER_ID, 5000, track_make_call_handle, make_call.cnumber);
    }
}

static void track_make_call_handle(char *number)
{
    kal_uint8 nsize = 0;
    static char call_cmd[32] = {0};
    
    nsize = strlen(number);
    LOGD(L_CMD, L_V5, "%s:%s,%d", number, make_call.cnumber, nsize);
    if(nsize < 3)
    {
        memset(&call_msg, 0, sizeof(call_msg_struct));
        track_call_state_notice_mmi(CALL_MO_OUT, CALL_MO_NUMBERERROR);
        return;
    }
    snprintf(call_cmd, 25, "ATD%s;\r\n", number);

    call_msg.call_type = CALL_MO_OUT;
    call_msg.call_state = TR_CALL_DAILING;
    
    track_at_vs_send(call_cmd);
    
    tr_start_timer(TRACK_CALL_OVERTIME_TEIMER_ID, MAKECALL_OVERTIME, make_call_overtime);
}
/******************************************************************************
 * FUNCTION:  - track_make_call *
 * DESCRIPTION: - 休眠模式有可能AT丢失打电话前请先退出休眠 *
 * Input:
 * Output:
 * Returns:
 *
 * modification history
 * --------------------
 * v1.0  , 08-09-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
void track_make_call(char * number)
{
    kal_uint8 nsize = 0;


    LOGD(L_CMD, L_V5, "at:%d,status:%d,%d number:%s",
         track_at_is_hold(), call_msg.call_state, strlen(number), number);

    if(track_is_in_call())
    {
        track_at_daly_make_call(number);
        track_call_state_notice_mmi(CALL_MO_OUT, CALL_MO_BUSY);
        return;
    }

    if(track_drv_get_sim_type() != 1)
    {
        track_call_state_notice_mmi(CALL_MO_OUT, CALL_MO_SIMERROR);
        return;
    }

    if(track_sms_get_send_status())
    {
        track_at_daly_make_call(number);
        track_call_state_notice_mmi(CALL_MO_OUT, CALL_MO_SMS_BUSY);
        return;
    }

    nsize = track_fun_check_phone_number(number);
    if(nsize > 0 && nsize < 25)
    {

        memset(call_msg.call_number, 0, sizeof(call_msg.call_number));
        snprintf(call_msg.call_number, sizeof(make_call.cnumber), "%s", number);

        memset(&make_call, 0, sizeof(make_call_info_struct));
        track_at_temp_save_out_number(call_msg.call_number);
        
        track_make_call_handle(number);

    }
    else
    {
        track_call_state_notice_mmi(CALL_MO_OUT, CALL_MO_NUMBERERROR);
        LOGD(L_CMD, L_V1, "ATD ERROR number length:%d", nsize);
    }


}

void track_press_key_dial_112(void)
{
    LOGS("Dail \"112\"");
    track_at_vs_send("ATD112;\r\n");
}

static void track_set_incomming_call_number(char * inc_number)
{

    LOGD(L_CMD, L_V5, "===num:%s", inc_number);
    if(inc_number == NULL)
    {
        return;//没有来电显示暂时不接听
    }
    if(strlen(inc_number) > 25)
    {
        return;
    }
    sprintf(call_msg.call_number, "%s", inc_number);

}

char* track_get_incomming_call_number(void)
{
    return call_msg.call_number;
}

kal_bool track_is_in_call(void)
{
    LOGD(L_CMD, L_V5, "call_state:%d", call_msg.call_state);
    return (kal_bool)(call_msg.call_state >= TR_CALL_RING && call_msg.call_state < TR_CALL_DISCONNECT);
}

kal_bool track_is_calling(void)
{
    return (kal_bool)(call_msg.call_state == TR_CALL_CONNECT);
}

kal_uint16 track_get_call_state(void)
{
    return (kal_uint16)call_msg.call_state;
}

kal_uint16 track_get_incall_type(void)
{
    /*CALL_MT_IN  CALL_MO_OUT*/
	return call_msg.call_type;
}
/*****************************************************************************
*打电话状态:
*1.来电
*2.接通
*3.挂断
******************
*1.拨号
*2.接通/对方挂机
*3.挂断
*****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	call_id;
    l4c_number_struct	num;
    kal_uint8	call_type;
    kal_uint8	signal_value_present;
    kal_uint8	signal_value;
    kal_uint8	no_cli_cause;
} track_cc_call_ring_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	    call_id;
    kal_uint8	    call_type;
    kal_uint16      cause;
    kal_uint8	    diag;
} track_cc_calll_disc_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	    flag;
    kal_uint8      cause;
    kal_uint8	    call_id_mode;
} track_cc_calll_rsp_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	    call_id;
} track_cc_calll_accept_req_ind_struct;

/****************************************
L4C层发送消息部分
****************************************/
void track_l4c_send_msg_track_mmi(msg_type msgtype, void * msg, void * peer_msg)
{
    ilm_struct *ilm_ptr;
#ifdef __L4C_API__
    ilm_ptr = (ilm_struct*)allocate_ilm(MOD_L4C);
    ilm_ptr->src_mod_id = MOD_L4C;
    ilm_ptr->dest_mod_id = MOD_MMI;
    ilm_ptr->sap_id = MMI_L4C_SAP;
#else
    ilm_ptr = (ilm_struct *)allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->dest_mod_id = (module_type)MOD_MMI;
    ilm_ptr->sap_id = INVALID_SAP;
#endif /* __L4C_API__ */
    ilm_ptr->msg_id = (msg_type) msgtype;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg;
    ilm_ptr->peer_buff_ptr = peer_msg;
    msg_send_ext_queue(ilm_ptr);
}

void track_l4c_sendmsg_call_ring_ind(l4c_number_struct* number, kal_uint8 call_type, kal_uint8 call_id)
{//track_call_ring_ind()
    track_cc_call_ring_ind_struct *myMsgPtr = NULL;
    LOGD(L_CMD, L_V5, "==num:%s,call_type:%d", number->number, call_type);
    myMsgPtr = (track_cc_call_ring_ind_struct*) construct_local_para(sizeof(track_cc_call_ring_ind_struct), TD_CTRL);

    myMsgPtr->num.length = number->length;
    myMsgPtr->num.type = number->type;
    memcpy(myMsgPtr->num.number, number->number , MAX_CC_ADDR_LEN);
    myMsgPtr->call_type = call_type ;
    track_l4c_send_msg_track_mmi(MSG_ID_MMI_CC_CALL_RING_IND, myMsgPtr, NULL);

}

void track_l4c_cc_call_accept_req_ind(kal_uint8 call_id)
{
//track_calll_accept_req_lind
    track_cc_calll_accept_req_ind_struct *myMsgPtr = NULL;
    LOGD(L_CMD, L_V5, "===call_id:%d", call_id);
    myMsgPtr = (track_cc_calll_accept_req_ind_struct*) construct_local_para(sizeof(track_cc_calll_accept_req_ind_struct), TD_CTRL);
    myMsgPtr->call_id = call_id;
    track_l4c_send_msg_track_mmi(MSG_ID_MMI_CC_CALL_ACCEPT_REQ_IND, myMsgPtr, NULL);

}

//MSG_ID_MMI_CC_CALL_CONNECT_IND
void track_l4c_cc_call_connect_lind(l4c_number_struct *num, kal_uint8 call_type, kal_uint8 call_id)
{
    track_cc_call_ring_ind_struct *myMsgPtr = NULL;
    LOGD(L_CMD, L_V5, "===number_type:%d,num:%s,call_type:%d,%d", num->type, num->number, call_type, call_id);
    myMsgPtr = (track_cc_call_ring_ind_struct*) construct_local_para(sizeof(track_cc_call_ring_ind_struct), TD_CTRL);
    myMsgPtr->num.length = num->length;
    myMsgPtr->num.type = num->type;
    memcpy(myMsgPtr->num.number, num->number , MAX_CC_ADDR_LEN);
    myMsgPtr->call_type = call_type ;
    track_l4c_send_msg_track_mmi(MSG_ID_MMI_CC_CALL_CONNECT_IND, myMsgPtr, NULL);

}

/******************************************************************************
 *  Function    -  track_l4c_cc_exe_ata_lrsp
 *  Purpose     -  //正常接听l4c_cc_exe_ata_lrsp() ======flag:0,cause:0,mode:0
 *  Description -  ATA指令的返回函数
 *  modification history
 * ----------------------------------------
 * v1.0  , 01-05-2013,  wangqi  written
 * ----------------------------------------
 ******************************************************************************/
void track_l4c_cc_exe_ata_lrsp(kal_uint8 flag , kal_uint16 cause, kal_uint8 call_mode)
{
    track_cc_calll_rsp_struct *myMsgPtr = NULL;

    //track_calll_ata_setup_lrsp_lind
    LOGD(L_CMD, L_V5, "===flag:%d,cause:%d,mode:%d", flag , cause, call_mode);
    //停止ata的定时器

    myMsgPtr = (track_cc_calll_rsp_struct*) construct_local_para(sizeof(track_cc_calll_rsp_struct), TD_CTRL);
    myMsgPtr->flag = flag;
    myMsgPtr->cause = cause;
    myMsgPtr->call_id_mode = call_mode ;

    track_l4c_send_msg_track_mmi(MSG_ID_MMI_CC_ATA_RSP, myMsgPtr, NULL);
}

void track_l4c_cc_call_setup_req_ind(l4c_number_struct* number, kal_uint8 call_type, kal_bool cug_option)
{
    //MSG_ID_MMI_CC_DIAL_REQ_IND
    LOGD(L_CMD, L_V5, "==num:%s,call_type:%d,option:%d", number->number, call_type, cug_option);
    //停定时器

}


void track_l4c_cc_exe_call_setup_lrsp(kal_uint8 flag , kal_uint16 cause, kal_uint8 call_id)
{
    //track_calll_ata_setup_lrsp_lind
    //l4c_cc_exe_call_setup_lrsp() ======0,cause:0,call_id:1,diag:0
    //===flag:0,cause:0,call_id:1
    track_cc_calll_rsp_struct *myMsgPtr = NULL;

    LOGD(L_CMD, L_V5, "===flag:%d,cause:%d,call_id:%d", flag , cause, call_id);

    myMsgPtr = (track_cc_calll_rsp_struct*) construct_local_para(sizeof(track_cc_calll_rsp_struct), TD_CTRL);
    myMsgPtr->flag = flag;
    myMsgPtr->cause = cause;
    myMsgPtr->call_id_mode = call_id ;

    track_l4c_send_msg_track_mmi(MSG_ID_MMI_CC_DIAL_IND, myMsgPtr, NULL);
}

void track_l4c_sendmsg_call_disc_release_lind(kal_uint8 action, kal_uint8 call_id, kal_uint16 cause, kal_uint8 call_type, kal_uint8 diag)
{
    track_cc_calll_disc_ind_struct *myMsgPtr = NULL;
    LOGD(L_CMD, L_V5, "===%dcall_id:%d,call_type:%d,cause:%d,%d", action, call_id, call_type, cause, diag);
    //停止chup的定时器
    myMsgPtr = (track_cc_calll_disc_ind_struct*) construct_local_para(sizeof(track_cc_calll_disc_ind_struct), TD_CTRL);
    myMsgPtr->call_id = call_id;
    myMsgPtr->call_type = call_type;
    myMsgPtr->cause = cause;
    myMsgPtr->diag = diag;
    myMsgPtr->call_type = call_type ;
    if(0 == action)
    {
        //track_l4c_send_msg_track_mmi(MSG_ID_MMI_CC_CALL_DISCONNECT_IND, myMsgPtr, NULL);
    }
    else if(1 == action)
    {
        track_l4c_send_msg_track_mmi(MSG_ID_MMI_CC_CALL_RELEASE_IND, myMsgPtr, NULL);
    }

}

/****************************************
MMI层对消息处理部分
****************************************/
#if 0
MSG_ID_MMI_CC_CALL_CONNECT_IND,
MSG_ID_MMI_CC_CALL_DISCONNECT_IND,
MSG_ID_MMI_CC_CALL_RELEASE_IND,
MSG_ID_MMI_CC_SPEECH_IND,
#endif
void track_call_status(track_call_state_enum status)
{
    switch(status)
    {
        case TR_CALL_RING:
            call_msg.call_type = CALL_MT_IN;
            call_msg.call_state = TR_CALL_RING;
            break;

        case TR_CALL_CONNECT:
            call_msg.call_state = TR_CALL_CONNECT;
            //track_at_set_handfree();/*06B通话加在免提MIC上所以要切其它项目酌情*/
            break;

        case TR_CALL_DISCONNECT:
            call_msg.call_state = TR_CALL_DISCONNECT;
            break;
        default:
            break;
    }

    LOGD(L_CMD, L_V5, "===call_type:%d;call_state=%d", call_msg.call_type, call_msg.call_state);

    if(call_msg.call_state != TR_CALL_UNKNOW)
    {
        track_call_state_notice_mmi(call_msg.call_type, call_msg.call_state);
    }
}

void track_call_ring_ind(void * msg)
{/*MSG_ID_MMI_CC_CALL_RING_IND*/
    track_cc_call_ring_ind_struct *ptr = (track_cc_call_ring_ind_struct *) msg;
    LOGD(L_CMD, L_V5, "===num:%s,call_type:%d", ptr->num.number, ptr->call_type);

    track_call_status(TR_CALL_RING);
    track_set_incomming_call_number(ptr->num.number);
}

void track_calll_ata_setup_lrsp_lind(call_ata_setup_lrsp_enum setup_type, void * msg)
{/*MSG_ID_MMI_CC_DIAL_IND  track_l4c_cc_exe_call_setup_lrsp*/
    track_cc_calll_rsp_struct *ptr = (track_cc_calll_rsp_struct *) msg;
    LOGD(L_CMD, L_V5, "===%d,flag:%d,cause:%d,call_id:%d", setup_type, ptr->flag , ptr->cause, ptr->call_id_mode);
    //停定时器

    if(CALL_SETUP_LRSP == setup_type)
    {
        if(ptr->flag == 0 && track_is_timer_run(TRACK_CALL_OVERTIME_TEIMER_ID))
        {
            LOGD(L_CMD, L_V5, "---Stop TRACK_CALL_OVERTIME_TEIMER_ID---");
            track_stop_timer(TRACK_CALL_OVERTIME_TEIMER_ID);
        }
    }
    else if(CALL_SETUP_ATA == setup_type)
    {
        /*l4c_cc_call_setup_req_ind */
        LOGD(L_CMD, L_V5, "---ATA---");
    }
    else
    {
        LOGD(L_CMD, L_V5, "---Hi, I am Ghost! How are you!---");
    }
}

void track_calll_accept_req_lind(void * msg)
{
    track_cc_calll_accept_req_ind_struct *ptr = (track_cc_calll_accept_req_ind_struct *) msg;
    LOGD(L_CMD, L_V5, "===call_id:%d", ptr->call_id);

    track_call_status(TR_CALL_CONNECT);
}

void track_call_connect_ind(void * msg)
{
    track_cc_call_ring_ind_struct *ptr = (track_cc_call_ring_ind_struct *) msg;
    LOGD(L_CMD, L_V5, "===num:%s,call_type:%d", ptr->num.number, ptr->call_type);

}

void track_calll_release_lind(kal_uint8 action, void * msg)
{
    track_cc_calll_disc_ind_struct *ptr = (track_cc_calll_disc_ind_struct *) msg;
    LOGD(L_CMD, L_V5, "===%dcall_id:%d,call_type:%d,cause:%d,%d", action, ptr->call_id, ptr->call_type, ptr->cause, ptr->diag);

    track_call_status(TR_CALL_DISCONNECT);
}

