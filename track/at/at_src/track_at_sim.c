/******************************************************************************
 * track_at_sim.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *
 *
 * modification history
 * --------------------
 * v1.0   2012-11-17,  wangqi create this file
 *
 ******************************************************************************/
/****************************************************************************
* Include Files             包含头文件
*****************************************************************************/
#include "track_at_sim.h"
#include "track_at.h"
#include "track_at_sms.h"
#include "track_os_timer.h"
#include "track_os_data_types.h"

#include "c_RamBuffer.h"
#include "c_vector.h"

/*****************************************************************************
 *  Define			    宏定义
*****************************************************************************/
#define BACK_MSG_MAX_LENGTH     137             //140-2-1
/*****************************************************************************
* Typedef  Enum         枚举
*****************************************************************************/


/*****************************************************************************
*  Struct			    数据结构定义
*****************************************************************************/

typedef struct
{
    kal_uint8                   *backup_buf;
    int                         backup_len;
    
    kal_uint8                   packets;
    kal_uint8                   send_sucess;//发送成功次数
    
    kal_uint8                   read_index;//一共读到的备份指令信息条数
    kal_uint8                   r_saved_total;//读到的信息内记录总条数

    char *                      read_msg;
    kal_uint16                  read_msg_len;


    kal_timer_func_ptr          backup_sucess_ind;
    kal_timer_func_ptr          read_msg_ind;
} bsms_cmd_struct;

typedef struct
{
    kal_uint16                  back_crc;
    kal_uint8                   packet_total_cur;
    kal_uint8                   ctx[BACK_MSG_MAX_LENGTH];
} backup_sos_para_struct;


/*****************************************************************************
* Local variable            局部变量
*****************************************************************************/
static bsms_cmd_struct          bsms = {0};

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

void track_sim_handle_senderbox(kal_timer_func_ptr read_callback)
{
    LOGD(L_CMD, L_V4, "");

    if(track_sim_get_sms_from_senderbox())
    {
        tr_start_timer(TRACK_SIM_READ_SB_TIMER_ID, 5000, track_sim_handle_senderbox);
    }

    bsms.read_msg_ind = read_callback;
}

static int backup_sms_ciphertext_conver(char* string, kal_uint8 sign)
{
    int index = 0;
    while(* string && index++ < 160)
    {
        * string ^= sign;
        string++;
    }
    return index;
}


static void send_sms_to_senderbox(char * ctx, int ilength)
{
    sms_msg_struct ssms = {0};
    memset(&ssms, 0, sizeof(sms_msg_struct));
    ssms.codetype = KAL_TRUE;
    ssms.ctxlen = ilength;
    ssms.ctx = ctx;
    ssms.nocount = 1;
    ssms.smsdir = SMS_SENDER_BOX;
    ssms.numbers[0] = "";
    track_sms_sender(&ssms);
    LOGD(L_CMD, L_V5, "---->>len:%d,over<<----", ilength);
}



static void backup_msg_callback(int type)
{
    LOGD(L_CMD, L_V5, "---->>type:%d----", type);
    sim_read_senderbox_lock(0);
    if(bsms.backup_sucess_ind != NULL)
    {
        bsms.backup_sucess_ind((void *)type);
    }
    if(bsms.backup_buf)
    {
        Ram_Free(bsms.backup_buf);
        bsms.backup_buf = NULL;
    }
}

static void backup_to_senderbox(void)
{
    kal_bool ret;
    kal_uint8 *ptr_sos = NULL , total_p = 0 , cur_index = 0;
    int  modelen = 0, buf_len = 0;

    sms_msg_struct ssms = {0};
    backup_sos_para_struct backup_sos = {0};

    LOGD(L_CMD, L_V5, "");

    if(bsms.backup_buf == NULL || 0 == bsms.backup_len)
    {
        LOGD(L_CMD, L_V5, "backup_buf:%d,backup_len:%d----------", bsms.backup_buf, bsms.backup_len);
        backup_msg_callback(-1);
        return;
    }
    ptr_sos = bsms.backup_buf;
    buf_len = bsms.backup_len;

    total_p = (kal_uint8)(buf_len / BACK_MSG_MAX_LENGTH) ; //分包整包数

    modelen = buf_len % BACK_MSG_MAX_LENGTH;//分完整包后剩余长度

    LOGD(L_CMD, L_V5, "total_p:%d,modelen:%d------------------", total_p, modelen);

    if(total_p > 6)
    {
        LOGD(L_CMD, L_V5, "----backup msg too long-----");
        backup_msg_callback(-2);
        return;
    }
    
    bsms.packets = total_p;
    bsms.send_sucess = 0;
    do
    {
        memset(&ssms, 0, sizeof(sms_msg_struct));

        backup_sos.packet_total_cur = (total_p << 4) + cur_index;

        if(cur_index == total_p)
        {
            ssms.ctxlen = modelen;
        }
        else
        {
            ssms.ctxlen = BACK_MSG_MAX_LENGTH;
        }

        memcpy(backup_sos.ctx, ptr_sos, ssms.ctxlen);
        backup_sos.back_crc = GetCrc16((U8 *)&backup_sos.packet_total_cur, ssms.ctxlen + 1);

        ptr_sos += ssms.ctxlen;

        LOGD(L_CMD, L_V5, "---packet_total_cur:%x--crc:%x--", backup_sos.packet_total_cur, backup_sos.back_crc);

        ssms.codetype = KAL_FALSE;
        ssms.ctxlen += 3;
        ssms.ctx = (char*)&backup_sos;
        LOGH(L_CMD, L_V5, ssms.ctx, ssms.ctxlen);
        ssms.nocount = 1;
        ssms.smsdir = SMS_SENDER_BOX;
        ssms.numbers[0] = "\0";
        track_sms_sender(&ssms);

        cur_index++;

    }
    while(cur_index <= total_p);

    LOGD(L_CMD, L_V5, "total_p:%d,cur_index:%d--------------------", total_p, cur_index);
    
    //track_start_timer(TRACK_SIM_W_CALLBACK_TIMER_ID, 4 * (total_p + 1) * 1000 ,backup_msg_callback, (void *) 0);
    //backup_msg_callback(0);
    track_start_timer(TRACK_SIM_W_CALLBACK_TIMER_ID,5 * (total_p + 1) * 1000,backup_msg_callback, (void *) -3);
}


void track_sim_sendmsg_rsp(sms_send_rsp_struct *rsps)
{

    LOGD(L_CMD, L_V5, "total:%d,sucess:%d,result:%d,status:%d------------"
        ,bsms.packets,bsms.send_sucess,rsps->result,rsps->result);

    
    if(rsps->result == sSENDOK)
    {
        if(bsms.send_sucess == bsms.packets)
        {
            tr_stop_timer(TRACK_SIM_W_CALLBACK_TIMER_ID);
            bsms.send_sucess = 0;
            backup_msg_callback(0);
        }
        
        bsms.send_sucess++;
    }
}
kal_int8 track_sim_backup_msg(void *buf, int buf_len, kal_timer_func_ptr callback)
{
    LOGD(L_CMD, L_V5, "");

    if(sim_read_senderbox_lock(2) != 0)
    {
        return -1;
    }


    sim_read_senderbox_lock(1);
    bsms.backup_buf = (kal_uint8 *)Ram_Alloc(1, buf_len);
    
    if(bsms.backup_buf == NULL)
    {
        //sim_read_senderbox_lock(0);
        return -2;
    }
    bsms.backup_sucess_ind = callback;
    bsms.send_sucess = 0;

    bsms.backup_len = buf_len;
    memcpy(bsms.backup_buf, buf, bsms.backup_len);

    track_sim_clean_senderbox();

    tr_start_timer(TRACK_SIM_WRITE_SB_TIMER_ID, 3000, backup_to_senderbox);

    return 0;
}

static kal_int8 track_set_sms_to_buffer(backup_sos_para_struct *r_msg)
{
    kal_uint16 cur_msg_index = 0;

    LOGD(L_CMD, L_V5, "-----------VVVVV---------------------------VVVVV--------------");

    cur_msg_index = r_msg->packet_total_cur & 0x0F;
    bsms.r_saved_total = (r_msg->packet_total_cur >> 4) & 0x0F;


    if(NULL == bsms.read_msg)
    {
        bsms.read_msg_len = (bsms.r_saved_total + 1) * BACK_MSG_MAX_LENGTH;
        bsms.read_msg = (kal_uint8 *)Ram_Alloc(1, bsms.read_msg_len);

        if(NULL == bsms.read_msg)
        {
            LOGD(L_CMD, L_V5, "---ram_alloc fail error!-----");
            return -2;
        }
        memset(bsms.read_msg, 0, bsms.read_msg_len);
    }

    LOGD(L_CMD, L_V5, "---r_saved_total:%d,cur:%d!-readlen:%d----", bsms.r_saved_total, cur_msg_index, bsms.read_msg_len);

    if(bsms.r_saved_total)
    {
        char *ptrin = NULL, *ptreof = NULL;
        ptrin = bsms.read_msg + cur_msg_index * BACK_MSG_MAX_LENGTH;
        ptreof = bsms.read_msg + bsms.read_msg_len;
        LOGD(L_CMD, L_V5, "begin:%x,eof:%x,cur:%x", bsms.read_msg, ptreof, ptrin);
        if(ptrin < bsms.read_msg || ptrin > ptreof - BACK_MSG_MAX_LENGTH)
        {
            LOGD(L_CMD, L_V5, "---ram_alloc find place error!-----");
            return -3;
        }
        memcpy(ptrin, r_msg->ctx, BACK_MSG_MAX_LENGTH);
    }
    else
    {
        memcpy(bsms.read_msg, r_msg->ctx, BACK_MSG_MAX_LENGTH);
    }

    bsms.read_index++;

    LOGH(L_CMD, L_V5, bsms.read_msg, bsms.read_msg_len);

    LOGD(L_CMD, L_V5, "--------^^^^^-----have read:%d,cur:%d----------^^^^^----------", bsms.read_index, cur_msg_index);

    return 0;
}



static kal_int8 tr_sim_handle_back_sms(SM_PARAM * sms_get)
{
    //char *p = NULL;
    kal_int8 ret = -1;
    kal_uint16 newcrc = 0;
    kal_uint16 oldcrc = 0;
    backup_sos_para_struct read_msg = {0};

    LOGD(L_CMD, L_V5, ":%d,DSC:%d,UDL:%d",
         sms_get->index, sms_get->TP_DCS, sms_get->TP_UDL);


    if(sms_get->TP_UDL < 4 && sms_get->TP_UDL > SMSUCS2MAX) /*CRC+smstotal+ctx*/
    {
        LOGD(L_CMD, L_V5, "msg length erorr!%d", sms_get->TP_UDL);
        return 0;
    }

    if(sms_get->TP_DCS == GSM_UCS2) //其它备份信息用GSM_UCS2保存
    {

        //LOGD(L_CMD, L_V5, ":%x,%x",*sms_get->TP_UD,*(sms_get->TP_UD+1));
        //分解

        memcpy(&oldcrc, sms_get->TP_UD, 2);
        //oldcrc = (kal_uint16)sms_get->TP_UD;

        newcrc = GetCrc16((U8*)(sms_get->TP_UD + 2), sms_get->TP_UDL - 2);
        LOGD(L_CMD, L_V5, "crc old:%x,new:%x,udl:%d", oldcrc, newcrc, sms_get->TP_UDL);
        //验证CRC
        //将信息存储入Buffer
        if(oldcrc == newcrc)
        {
            memset(&read_msg, 0, sizeof(backup_sos_para_struct));
            read_msg.back_crc = newcrc;
            read_msg.packet_total_cur = *(sms_get->TP_UD + 2);

            memcpy(&read_msg.ctx, sms_get->TP_UD + 3, sms_get->TP_UDL - 3);

            ret = track_set_sms_to_buffer(&read_msg);
        }
        else
        {
            LOGD(L_CMD, L_V5, "CRC Error!");
            ret = -4;
        }

        LOGD(L_CMD, L_V5, "ret:%d read total packet:%d,r_saved_total:%d,read_index:%d"
             , ret, read_msg.packet_total_cur, bsms.r_saved_total, bsms.read_index);

    }

    return ret;
}

/******************************************************************************
 * FUNCTION:  - track_drv_get_sim_sms_callback
 * DESCRIPTION: - 获取收件箱所有信息后调用此接口进行备份信息分解
 * modification history
 * --------------------
 * v1.0  , 09-12-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
void track_sim_get_sms_callback(void)
{
    SM_PARAM sms_get = {0};
    read_msg_struct read_ind = {0};

    LOGD(L_CMD, L_V5, "vec_outbox:%d", get_vec_out_size());

    if(sim_read_senderbox_lock(2))
    {
        tr_start_timer(TRACK_OUTBOX_READY_TIMER_ID, 3000, track_sim_get_sms_callback);
    }//TODO ?
    else if(get_vec_out_size() == 0)
    {
        //短信为空
        read_ind.error_msg = -1;
        if(bsms.read_msg_ind != NULL)
        {
            bsms.read_msg_ind(&read_ind);
        }
    }
    else
    {
        //memset(&bsms,0,sizeof(bsms_cmd_struct));
        bsms.read_index = 0;//一共读到的备份指令信息条数
        bsms.r_saved_total = 0 ; //读到的信息内记录总条数

        bsms.read_msg = NULL;//??????
        bsms.read_msg_len = 0;
        while(track_sms_get_out_sms(&sms_get) /*&& bsms.cread_back_sms > BACK_SMS_MAX*/)
        {
            tr_sim_handle_back_sms(&sms_get);
            LOGD(L_CMD, L_V5, "read_index:%d<-----------", bsms.read_index);
            //临时关闭调试多条备份if(bsms.cread_back_sms == BACK_SMS_MAX) break;
        }

        track_sms_clean_out_vec();

        LOGD(L_CMD, L_V4, "结r_saved_total:%d,read_index:%d", bsms.r_saved_total, bsms.read_index);

        if(bsms.read_index == bsms.r_saved_total + 1)
        {
            read_ind.error_msg = 0;
            read_ind.msg_ctx = bsms.read_msg;
            read_ind.msg_len = bsms.read_msg_len;
        }
        else
        {
            LOGD(L_CMD, L_V5, "read sim msg error");
            //读取短信不正确
            read_ind.error_msg = -2;
            track_sim_clean_senderbox();
        }
        LOGD(L_CMD, L_V5, "---------------------");
        if(bsms.read_msg_ind)
        {
            bsms.read_msg_ind(&read_ind);
        }
        if(bsms.read_msg)
        {
            Ram_Free(bsms.read_msg);
            bsms.read_msg = NULL;
        }
    }
}

void track_sim_main(void)
{
    memset(&bsms, 0, sizeof(bsms_cmd_struct));
    //track_sim_clean_allsms();//清空收件箱
    //tr_start_timer(TRACK_SIM_READ_SB_TIMER_ID, 3000, track_sim_handle_senderbox);
}

