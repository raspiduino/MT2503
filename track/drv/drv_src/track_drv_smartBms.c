/******************************************************************************
 * track_drv_smartBms.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *       与BMS模块通信 
 *
 * modification history
 * --------------------
 * v1.0   2017-08-02,  xzq create this file
 *
 ******************************************************************************/
#if defined __SMT_BMS__
#include "track_os_log.h"
#include "track_os_ell.h"
#include "track_drv_system_param.h"
#include "track_drv_smartBms.h"
#include "track_drv_uart.h"
void track_drv_send_bms_event(bms_event_msg *bms_msg_body)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;
    bms_event_msg_struct *bms_msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bms_msg = (bms_event_msg_struct*) construct_local_para(sizeof(bms_event_msg_struct), TD_RESET);
    bms_msg->bms.event = bms_msg_body->event;
    memcpy(bms_msg->bms.data, bms_msg_body->data, BMS_UART_BUFF_LEN_MAX);

    ilm_ptr = (ilm_struct *)allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->dest_mod_id = MOD_MMI;
    ilm_ptr->sap_id = INVALID_SAP;
    ilm_ptr->msg_id = (msg_type) MSG_ID_BMS_EVENTS_ID;
    ilm_ptr->local_para_ptr = (local_para_struct*) bms_msg;
    ilm_ptr->peer_buff_ptr = NULL;
    msg_send_ext_queue(ilm_ptr);
}

U16 crcBMS(const kal_uint8 *data,U8 len)
{
    U16 crc=0,i=0;
    while(i<len)
    {
        crc+=data[i++];
    }
    return crc;
}

kal_bool crc_cmd_BMS(const kal_uint8 *data,U8 len,U16 crc)
{
    U16 sum=0;
    U8 i=0;
    while(i<len)
    {
        LOGD(L_DRV, L_V8, "%d,%d",sum,data[i]);
        sum +=data[i++];
    }
    if(sum==crc)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

void track_drv_bms_recdata(kal_uint8* data, U8 len)
{
    kal_uint8 cmd;
    kal_uint8* p_buff;
    static kal_uint8 first=1;
    bms_event_msg bms_evt = {0};
    kal_uint8 i,j=0,datalen,l_data;
    U16 crc=0;
    if(data == NULL)
    {
        return;
    }

    LOGH(L_DRV, L_V4, data, len);
    
    if((len >= BMS_UART_BUFF_LEN_MAX) || (len <= 3))
    {
        return;
    }

    i=0;
    if(data[i++]==BMS_HEAD && data[i++]==BMS_ADD)
    {
        bms_evt.event = data[i++];
        datalen = data[i++];
        l_data=i;//数据位置
        i+=datalen;
        crc = crc |data[i+1];//高位在后
        crc<<8;
        crc = crc |data[i++];
        
        if(!crc_cmd_BMS(&data[1], datalen+3,crc))
        {
             LOGD(L_APP, L_V1, "CRC error!!!%x",crc);
             return;
        }
        memcpy(bms_evt.data, &data[l_data], datalen);

        track_drv_send_bms_event(&bms_evt);
    }

    
}

void BmsEncodeData(U8 *bms, U8 len)
{
    U16 tmp1;
    bms[0]=0x3A;

    //CRC校验
    tmp1 = crcBMS(&bms[1], len-5);
    bms[len - 3] = (tmp1 & 0xFF00) >> 8;
    bms[len - 4] = (tmp1 & 0x00FF);
    
    bms[len-2]=0x0D;
    bms[len-1]=0x0A;
    
}

//发包例子  3A 16 08 01 00 1F 00 0D 0A
//透传
void track_drv_write_packet_bms_data(U8 event,U8 *pData,U8 len)
{
    U8 *data=NULL;
    U8 size=0,i=1,j=0;
    size = 1/*起始位*/+3+len+2/*校验*/+2/*结束*/;
    data = (U8*)Ram_Alloc(1, size);
    LOGD(L_DRV, L_V3, "%d len %d", event, len);
    if(data==NULL)
    {
        return;
    }
    data[i++]=0x16;
    data[i++]=event;
    if(NULL==pData)
    {
        data[i++]=1;
        data[i]=0;
    }
    else
    {
        data[i++]=len;
        while(len>0)
        {
            data[i++]=pData[j++];
            len--;
        }
    }
    BmsEncodeData(data,size);
    track_cust_bmscomm_queue(event,data,size);
    Ram_Free(data);
}

void track_drv_bms_write(U8 *pData,int len)
{
    track_drv_uart_write(EXT_UART_PORT,pData, len);
}

#endif
