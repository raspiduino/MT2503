/******************************************************************************
 * track_cust_smartBms.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *      BMS模块通信协议
 *
 * modification history
 * --------------------
 * v1.0   2017-08-02,  xzq create this file
 *
 ******************************************************************************/
#if defined __SMT_BMS__

/****************************************************************************
*  Include Files                        包含头文件
*****************************************************************************/
#include "stack_msgs.h"
#include "stack_ltlcom.h"
#include "drvsignals.h"
#include "track_drv.h"
#include "track_os_ell.h"
#include "track_os_paramete.h"
#include "c_vector.h"
#include "track_cust.h"

/*****************************************************************************
*  Define                               宏定义
******************************************************************************/

/*****************************************************************************
*  Typedef  Enum                        枚举定义
*****************************************************************************/

/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/

/*****************************************************************************
*  Local variable                       局部变量
*****************************************************************************/
static c_vector* vec_bms_comm_queue = NULL;
static kal_uint8 evt_arr[]={BMS_EVT_TEMP,BMS_EVT_FULLVOL,BMS_EVT_ELE,BMS_EVT_ELE,BMS_EVT_RRAT,BMS_EVT_ABRAT,BMS_EVT_RCAP,BMS_EVT_FULLCAP,BMS_EVT_CYCTIME,BMS_EVT_VOL1,BMS_EVT_VOL2,BMS_EVT_CURCHRINVELTIME,BMS_EVT_MAXCHRINVELTIME};
typedef void(*fun_bmsPtr)(U8*);

typedef struct
{
    const U8 evt;
    fun_bmsPtr fun_ptr;
}bms_ptr_srtuct;

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
void track_cust_bms_read_data(U8 event);
void track_cust_bms_write_task(void*par);
/*****************************************************************************/

static void evt_08(U8 *data)
{
    LOGD(L_APP, L_V5, "");
    LOGH(L_APP, L_V6, data, strlen((char*)data));
    track_stop_timer(TRACK_CUST_BMS_WRITE_CHECK_TIMER_ID);
}

static void evt_09(U8 *data)
{
    LOGD(L_APP, L_V5, "");
    track_stop_timer(TRACK_CUST_BMS_WRITE_CHECK_TIMER_ID);
}

static bms_ptr_srtuct bms_evt_table[]=
{
    {0x08,evt_08}
   ,{0x09,evt_09}
   ,{0x0a,evt_08}
   ,{0x0d,evt_08}
   ,{0x0e,evt_08}
   ,{0x0f,evt_08}
   ,{0x10,evt_09}
   ,{0x17,evt_09}
    ,{0xff,NULL}
};

void track_bms_queue_init()
{
    if(NULL == vec_bms_comm_queue)
    {
        VECTOR_CreateInstance(vec_bms_comm_queue);
    }
}

/******************************************************************************
 *  Function    -  track_cust_packet_bmscomm
 *
 *  Purpose     - 存储命令字指令
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-10-2017,  Xzq  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_bmscomm_queue(U8 event,kal_uint8* data, int len )
{
    int v_size;
    bms_vec_write_struct*buf;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    LOGD(L_APP, L_V5,  "data_len=%d, packet_type=0x%0X", len, event);

    if(len > MAX_BMS_COMM_LEN || len <= 0)
    {
        LOGD(L_APP, L_V5,  "数据长度超出范围");
        return;
    }
    else
    {
        v_size = VECTOR_Size(vec_bms_comm_queue);
        if(v_size >= 50)
        {
            LOGD(L_APP, L_V1, "内存报警队列数值已经满%d条，删除早期数据，保留最新数据!!!", v_size);
            VECTOR_Erase2(vec_bms_comm_queue, 0, 15, KAL_TRUE);
        }
        buf = (bms_vec_write_struct*)Ram_Alloc(5, sizeof(bms_vec_write_struct));
        if(buf)
        {
            buf->len = len;
            buf->packet_type = event;
            memcpy(buf->buffer , data , len);
            VECTOR_PushBack(vec_bms_comm_queue, buf);
        }
        else
        {
            LOGD(L_APP, L_V1, "Ram_Alloc 申请临时内存空间失败!!!");
            track_cust_restart(49, 0);
        }
        track_cust_bms_write_task((void*)99);
    }
}

void track_cust_bms_comm_default_alarm()
{

}

/******************************************************************************
 *  Function    -  track_cust_packet_bmscomm
 *
 *  Purpose     - 存储命令字指令
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-10-2017,  Xzq  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_resend_logic()
{
    if(track_project_save_switch(99,sw_bms_comm_lock))
    {
        LOGD(L_APP, L_V5, "超时未回复,重新发送命令!!!!");
        
        track_project_save_switch(0,sw_bms_comm_lock);
        
    }
    track_cust_bms_write_task((void*)99);
}
/******************************************************************************
 *  Function    -  track_cust_bms_write_task
 *
 *  Purpose     - bms命令字发送模块
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-10-2013,  Xzq  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_bms_write_task(void*par)
{
    U8 parameter=(U8)par;
    int v_size_bms = VECTOR_Size(vec_bms_comm_queue);
    LOGD(L_APP, L_V5, "%d",parameter);
    if(parameter!=99)
    {
        if(v_size_bms)
        {
            bms_vec_write_struct* data;
            if(data->packet_type==parameter)
            {
                VECTOR_Erase2(vec_bms_comm_queue, 0, 1, KAL_FALSE);
                v_size_bms = VECTOR_Size(vec_bms_comm_queue);
            }
            else
            {
                LOGD(L_APP, L_V5, "非已发送指令回复!!!不删除存储指令。继续发送");
            }
        }
    }
    if(track_project_save_switch(99,sw_bms_comm_lock))
    {
        LOGD(L_APP, L_V5, "已发命令还未答复!!!");
        return;
    }
    else if(v_size_bms>0)
    {
        c_vector* vec_queue_tmp = NULL;
        bms_vec_write_struct* data;
        tr_start_timer(TRACK_CUST_BMS_WRITE_CHECK_TIMER_ID, 2000, track_cust_resend_logic);
        track_project_save_switch(1,sw_bms_comm_lock);
        vec_queue_tmp = vec_bms_comm_queue;
        if(vec_queue_tmp!=NULL)
        {
            data = VECTOR_At(vec_queue_tmp, 0);
            LOGH(L_APP,L_V5,data->buffer,data->len);
            LOGD(L_APP, L_V5, "%d",data->len);

            if(data)
            {
                track_drv_bms_write(data->buffer, data->len);
            }
            else
            {
                LOGD(L_APP, L_V1, "ERROR: vec_bms_comm_queue");
                VECTOR_Erase(vec_queue_tmp, 1, 1);
            }    
        }
    }
    
}

void track_cust_bms_packet_event(U8 event)
{
    U8 data[10]={0},len;
    LOGD(L_APP, L_V5, "EVENT %d", event);
    switch(event)
    {
        case BMS_EVT_TEMP:
        case BMS_EVT_FULLVOL:
        case BMS_EVT_ELE:
        case BMS_EVT_RRAT:
        case BMS_EVT_ABRAT:
        case BMS_EVT_RCAP:
        case BMS_EVT_FULLCAP:
        case BMS_EVT_CYCTIME:
        {
            len=1; 
            track_drv_write_packet_bms_data(event,NULL,1);
            break;
        }
        case BMS_EVT_VOL1:
        case BMS_EVT_VOL2:
        case BMS_EVT_CURCHRINVELTIME:
        case BMS_EVT_MAXCHRINVELTIME:
        {
            len=1; 
            data[0]==0x0b;
            track_drv_write_packet_bms_data(event,data,1);
            break;
         }
        default:
            LOGD(L_APP, L_V5, "NO EVENT ID %d", event);
            return;
    }
#if 0
    size = 1/*起始位*/+3+len+2/*校验*/+2/*结束*/;
    data = (U8*)Ram_Alloc(5, size);
    data[i++]=0x16;
    data[i++]=event;
    data[i++]=len;
    data[i]=tmpdata;
    BmsEncodeData(data,size);
    track_cust_bmscomm_queue(event,data,size);
    Ram_Free(data);
#endif
}


void track_cust_get_libattery_inf()
{
    int i=0;
    for(;i<sizeof(evt_arr);i++)
    {
        track_cust_bms_packet_event(evt_arr[i]);
    }
}

void track_cust_bms_event_handle(void *msg)
{
    bms_event_msg_struct * bms_msg = (bms_event_msg_struct*)msg;
    U8 event,i,size,msgdata[BMS_UART_BUFF_LEN_MAX]={0};
    event = bms_msg->bms.event;
    memcpy(msgdata,bms_msg->bms.data,BMS_UART_BUFF_LEN_MAX);
    LOGD(L_APP, L_V5, "event:0x%0X", event);
    LOGH(L_APP, L_V7, msgdata, BMS_UART_BUFF_LEN_MAX);
    size = sizeof(bms_evt_table)/sizeof(bms_ptr_srtuct);
    for(i=0;i<size;i++)
    {
        int ret;
        if(event==bms_evt_table[i].evt)
        {
            if(bms_evt_table[i].fun_ptr!=NULL)
            {
                bms_evt_table[i].fun_ptr(msgdata);
                track_project_save_switch(0,sw_bms_comm_lock);
                track_cust_bms_write_task((void*)bms_evt_table[i].evt);
            }
        }
    }
#if 0
    switch(event)
    {
        case BMS_EVT_TEMP:
            break;
        case BMS_EVT_FULLVOL:
            break;
        case BMS_EVT_ELE:
            break;
         case BMS_EVT_RRAT:
            break;
         case BMS_EVT_ABRAT:
            break;
         case BMS_EVT_RCAP:
            break;
         case BMS_EVT_FULLCAP:
            break;
         case BMS_EVT_CYCTIME:
            break;
         case BMS_EVT_VOL1:
            break;
         case BMS_EVT_VOL2:
            break;
         case BMS_EVT_CURCHRINVELTIME:
            break;
         case BMS_EVT_MAXCHRINVELTIME:
            break;

        default:
                LOGD(L_APP, L_V5, "NO EVENT ID %d", event);

            break;
    }
    #endif
}



#endif
