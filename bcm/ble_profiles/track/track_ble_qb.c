/******************************************************************************
 * track_ble_qb.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        BLE GATT协议处理 ，QB项目定制功能
 *
 * modification history
 * --------------------
 * v1.0   2017-09-12,  chengjun create this file
 *
 ******************************************************************************/
#if defined (__BLE_QB__)

/****************************************************************************
* Include Files 					 包含头文件
*****************************************************************************/
//for gatts
#include "track_ble_gatt.h"
#include "Bcm_btcmSrvGprot.h"
#include "bcm_btcmApp.h"
#include "btostypes.h"
#include "bluetooth_gap_struct.h"
#include "bcm_GattSrv.h"
#include "bcm_Prxr_def.h"
#include "track_ble_qb.h"

/*****************************************************************************
 *	Define				 宏定义
*****************************************************************************/




/*****************************************************************************
* Typedef	Enum
*****************************************************************************/


/*****************************************************************************
 *	Struct				 数据结构定义
*****************************************************************************/
static const unsigned char ble_qb_aes_key[16] = {0x20, 0x57, 0x2f, 0x52, 0x36, 0x4b, 0x3f, 0x47, 0x30, 0x50, 0x41, 0x58, 0x11, 0x63, 0x2d, 0x2b};
static const unsigned char ble_qb_password[6] = {0x30, 0x30, 0x30, 0x30, 0x30, 0x30};


/*****************************************************************************
 *	Local Functions 	 本地函数
*****************************************************************************/

/*****************************************************************************
* Local variable				 局部变量
*****************************************************************************/
static kal_uint8 ble_token[4] = {0};


/****************************************************************************
* Global Variable - Extern		 全局变量
*****************************************************************************/

/****************************************************************************
* Global Variable - Extern			 引用全局变量
*****************************************************************************/
extern PrxrCntx  g_prxr_cntx;

/*****************************************************************************
 *	Global Functions	 - Extern		 引用外部函数
*****************************************************************************/


/*****************************************************************************
 *	Local Functions 	 本地函数
*****************************************************************************/
void track_gatt_update_random_token(void)
{
    kal_uint32 ticks = kal_get_systicks();
    //ticks 转成4Byte的密码
    if(ticks < 0xFFFF)
    {
        ticks += 0x12345;
    }

    ble_token[0] = (ticks & 0xFF);
    ble_token[1] = ((ticks >> 16) & 0xFF);
    ble_token[2] = ((ticks >> 20) & 0xFF);
    ble_token[3] = ((ticks >> 8) & 0xFF);
}


U32 track_qb_ble_send_data(kal_uint16 server_uuid, kal_uint16 char_uuid, U8* buf, U16 len)
{
    gatts_service_decl_struct *svc_list = (gatts_service_decl_struct *)mmi_GetHeadList(&g_prxr_cntx.srv_list.srvlist);
    PrxrConnCntx        *pConnNode = (PrxrConnCntx *)mmi_GetHeadList(&g_prxr_cntx.conn_list);
    PrxrConnCntx        *pConnNext = NULL;
    gatt_conn_struct    gatt_conn;
    ATT_VALUE           *att_value = NULL;
    ATT_UUID            svc_uuid;
    ATT_UUID            chr_uuid;
    int                 type = 0;
    U16                 svc_uuid16 = 0;
    U16                 chr_uuid16 = 0;
    U32                 send_size = 0;

    if(buf == NULL)
    {
        return send_size;
    }

    if(!mmi_IsListEmpty(&g_prxr_cntx.conn_list))
    {
        while((ListEntry *)pConnNode != &g_prxr_cntx.conn_list)
        {

            pConnNext = (PrxrConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
            if(pConnNode->conn_status == PRX_STATUS_CONNECTED) //CONNECTED
            {
                char log[100] = {0};
                gatt_conn.reg_ctx = g_prxr_cntx.reg_ctx;
                gatt_conn.conn_ctx = pConnNode->conn_ctx;

                while((ListEntry *)svc_list != &g_prxr_cntx.srv_list.srvlist)
                {
                    if(svc_list->type == TYPE_CHARACTERISTIC)
                    {
                        type = prxr_find_uuid_by_handle(svc_list->handle, &svc_uuid, &chr_uuid);
                        if(type != TYPE_CHARACTERISTIC)
                        {
                            //break;
                        }
                        svc_uuid16 = convert_array_to_uuid16(svc_uuid);
                        chr_uuid16 = convert_array_to_uuid16(chr_uuid);
                        if(chr_uuid16 == char_uuid)
                        {
                            send_size = len;
                            if(len > 16)
                            {
                                len = 16;
                            }
                            att_value = (ATT_VALUE *)get_ctrl_buffer(sizeof(ATT_VALUE));
                            memcpy(att_value->value, buf, len);

                            sprintf(log, "%04X >> (%d) %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X\r\n", char_uuid,len, \
                                    buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6], buf[7], buf[8], buf[9], buf[10], buf[11], buf[12], buf[13], buf[14], buf[15]);
                            U_PutUARTBytes(0, (kal_uint8*)log, strlen(log));

                            att_value->len = len;
                            srv_gatts_send_indication(&gatt_conn, svc_list->handle, FALSE, att_value);
                            free_ctrl_buffer(att_value);
                            att_value = NULL;
                            //break;
                            return send_size;
                        }
                    }

                    svc_list = (gatts_service_decl_struct *)mmi_GetNextNode(&svc_list->declnode);
                }
            }

            pConnNode = pConnNext;
        }
    }
    return send_size;
}
/******************************************************************************
 *  Function    -  track_qb_ble_write_decode
 *
 *  Purpose     -  固定16字节的数据，先解密，再分包解析
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-09-13,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_qb_ble_write_decode(kal_uint8 *buff,kal_uint16 len)
{
    static kal_uint8 aes_init_done = 0;

    kal_uint8 rece_aes[16];//接收的密文
    kal_uint8 decode[16];//解密后的明文
    kal_uint8 output[16] = {0}; //要发出的明文
    kal_uint8 send_aes[16];//要发出的密文

    kal_uint8 ret=0;
    
#if defined (__BLE_DEBUG_LOG__)
    char testLog[128] = {0};
#endif /* __BLE_DEBUG_LOG__ */

    memcpy(rece_aes, buff, 16);

    if(aes_init_done == 0)
    {
        aes_init_done = 1;
        AES_Init(ble_qb_aes_key);
    }

    AES_Decrypt(decode, rece_aes, 16, NULL);

#if defined (__BLE_DEBUG_LOG__)
    sprintf(testLog, "ble rece << %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X \r\n", \
            decode[0], decode[1], decode[2], decode[3], decode[4], decode[5], decode[6], decode[7], \
            decode[8], decode[9], decode[10], decode[11], decode[12], decode[13], decode[14], decode[15]);
    U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));
#endif /* __BLE_DEBUG_LOG__ */

    if((decode[0] == 0x06) && (decode[1] == 0x01) && (decode[2] == 0x01) && (decode[3] == 0x01))
    {
        //head
        output[0] = 0x06;
        output[1] = 0x02;
        output[2] = 0x07;
        //token
        output[3] = ble_token[0];
        output[4] = ble_token[1];
        output[5] = ble_token[2];
        output[6] = ble_token[3];
        //chip type
        output[7] = 0x01;
        //sw version
        output[8] = 0x01;
        output[9] = 0x00;
        //other fill

        AES_Encrypt(output, send_aes, 16, NULL);

        track_qb_ble_send_data(0xFEE7,0x36F6,send_aes, 16);
    }
    else if((decode[0] == 0x05) && (decode[1] == 0x01) && (decode[2] == 0x06))
    {
        if( (memcmp(ble_qb_password, &decode[3], 6)==0) && (memcmp(ble_token, &decode[9], 4)==0) )
        {
            ret=1;
        }

        if(ret==1)
        {
#if defined (__BLE_DEBUG_LOG__)
            sprintf(testLog, "允许开锁\r\n");
            U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));
#endif /* __BLE_DEBUG_LOG__ */

            ret=0;//0表示成功，1表示失败
        }
        
        //head
        output[0] = 0x05;
        output[1] = 0x02;
        output[2] = 0x01;
        //ret
        output[3] = ret;
        //other fill

        AES_Encrypt(output, send_aes, 16, NULL);

        track_qb_ble_send_data(0xFEE7,0x36F6,send_aes, 16);
    }
    else
    {
#if defined (__BLE_DEBUG_LOG__)
        sprintf(testLog, "what?\r\n");
        U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));
#endif /* __BLE_DEBUG_LOG__ */

    }

}

void track_qb_request_read_callback(gatt_conn_struct *conn, U16 trans_id, BD_ADDR *bd_addr,
                                    ATT_HANDLE attr_handle, U16 offset, BOOL is_long)
{
    PrxrConnCntx    *pConnNode = (PrxrConnCntx *)mmi_GetHeadList(&g_prxr_cntx.conn_list);
    ATT_UUID         svc_uuid;
    ATT_UUID         chr_uuid;
    int              type = prxr_find_uuid_by_handle(attr_handle, &svc_uuid, &chr_uuid);
    U16              svc_uuid16 = convert_array_to_uuid16(svc_uuid);
    U16              chr_uuid16 = convert_array_to_uuid16(chr_uuid);
    ATT_VALUE        att_value;
    PrxrReq         *pNode = NULL;

#if defined (__BLE_DEBUG_LOG__)
    {
        char testLog[128] = {0};
        sprintf(testLog, "## track_qb_request_read_callback %d\r\n", type);
        U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));

        sprintf(testLog, "read  %x,%x,%d\r\n", svc_uuid16, chr_uuid16, offset);
        U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));
    }
#endif /*__BLE_DEBUG_LOG__*/

    if(type == TYPE_CHARACTERISTIC)
    {
        if((chr_uuid16 == TX_POWER_CHAR_UUID) && (svc_uuid16 == TX_POWER_SERVICE))
        {
            pNode = (PrxrReq *)get_ctrl_buffer(sizeof(PrxrReq));
            pNode->att_handle = attr_handle;
            memcpy(pNode->bdaddr, bd_addr->addr, BD_ADDR_SIZE);
            pNode->gatt_conn.reg_ctx = conn->reg_ctx;
            pNode->gatt_conn.conn_ctx = conn->conn_ctx;
            pNode->req_type = PRXR_REQ_READ_TXPOWER;
            pNode->trans_id = trans_id;
            pNode->offset = offset;
            mmi_InsertTailList(&g_prxr_cntx.req_list, &pNode->req_node);
            srv_gatts_read_tx_power(conn->reg_ctx, bd_addr);
        }
        else if((chr_uuid16 == ALERT_LEVEL_CHAR_UUID) && (svc_uuid16 == LINK_LOSS_SERVICE))
        {
            while((ListEntry *)pConnNode != &g_prxr_cntx.conn_list)
            {
                if(memcmp(bd_addr->addr, pConnNode->bdaddr, BD_ADDR_SIZE) == 0)
                {
                    att_value.len = 1;
                    att_value.value[offset] = pConnNode->lls_alert_level;
                    srv_gatts_send_response(conn, trans_id, OS_STATUS_SUCCESS, attr_handle, &att_value);
                    break;
                }
                pConnNode = (PrxrConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
            }
        }
        else if((chr_uuid16 == 0x2A27) && (svc_uuid16 == 0x180A))
        {
            att_value.len=sprintf(&att_value.value[offset],"%s","MT2503 BLE");
            srv_gatts_send_response(conn, trans_id, OS_STATUS_SUCCESS, attr_handle, &att_value);	
        }
        else if((chr_uuid16 == 0x2A28) && (svc_uuid16 == 0x180A))
        {
            att_value.len=sprintf(&att_value.value[offset],"%s","NTT3 QB");//按项目和协议区分
            srv_gatts_send_response(conn, trans_id, OS_STATUS_SUCCESS, attr_handle, &att_value);	
        }        
        else
        {
            att_value.len = 1;
            att_value.value[offset] = GATT_ERROR_REQUEST_NOT_SUPPORT;
            srv_gatts_send_response(conn, trans_id, OS_STATUS_FAILED, attr_handle, &att_value);
        }
    }
    else
    {
        att_value.len = 1;
        att_value.value[offset] = GATT_ERROR_REQUEST_NOT_SUPPORT;
        srv_gatts_send_response(conn, trans_id, OS_STATUS_FAILED, attr_handle, &att_value);
    }
}

void track_qb_request_write_callback(gatt_conn_struct *conn, U16 trans_id, BD_ADDR *bd_addr,
                                     ATT_HANDLE attr_handle, ATT_VALUE *value, U16 offset,
                                     BOOL need_rsp, BOOL is_prep)
{
    PrxrConnCntx    *pConnNode = (PrxrConnCntx *)mmi_GetHeadList(&g_prxr_cntx.conn_list);
    ATT_UUID         svc_uuid;
    ATT_UUID         chr_uuid;
    int              type = prxr_find_uuid_by_handle(attr_handle, &svc_uuid, &chr_uuid);
    U16              svc_uuid16 = convert_array_to_uuid16(svc_uuid);
    U16              chr_uuid16 = convert_array_to_uuid16(chr_uuid);
    ATT_VALUE        att_value;
    PrxrReq         *pNode = NULL;

#if defined (__BLE_DEBUG_LOG__)
    {
        char testLog[128] = {0};
        sprintf(testLog, "## track_qb_request_write_callback %d,%d,%d;%X,%X\r\n", type, need_rsp, offset, svc_uuid16, chr_uuid16);
        U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));

        sprintf(testLog, "(%d) - %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X \r\n", value->len, \
                value->value[0], value->value[1], value->value[2], value->value[3], value->value[4], value->value[5], value->value[6], value->value[7], \
                value->value[8], value->value[9], value->value[10], value->value[11], value->value[12], value->value[13], value->value[14], value->value[15]);
        U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));
    }
#endif /*__BLE_DEBUG_LOG__*/

    if(type == TYPE_CHARACTERISTIC)
    {
        while((ListEntry *)pConnNode != &g_prxr_cntx.conn_list)
        {
            if(memcmp(bd_addr->addr, pConnNode->bdaddr, BD_ADDR_SIZE) == 0)
            {
                if(svc_uuid16 == LINK_LOSS_SERVICE && chr_uuid16 == ALERT_LEVEL_CHAR_UUID)
                {
                    pConnNode->lls_alert_level = value->value[offset];
                    srv_gatts_send_response(conn, trans_id, OS_STATUS_SUCCESS, attr_handle, value);
                    if(g_prxr_cntx.callback)
                    {
                        g_prxr_cntx.callback->config_level_cb(bd_addr->addr, value->value[offset]);
                    }
                }
                else if(svc_uuid16 == 0xFEE7 && chr_uuid16 == 0x36F5)
                {
                    srv_gatts_send_response(conn, trans_id, OS_STATUS_SUCCESS, attr_handle, value);
                    track_qb_ble_write_decode(value->value,value->len);
                }
                else if(svc_uuid16 == IMMEDIATE_ALERT_SERVICE && chr_uuid16 == ALERT_LEVEL_CHAR_UUID)
                {
                    if(g_prxr_cntx.callback)
                    {
                        g_prxr_cntx.callback->alert_notify_cb(bd_addr->addr, value->value[offset]);
                    }
                }
                else
                {
                    att_value.len = 1;
                    att_value.value[offset] = GATT_ERROR_REQUEST_NOT_SUPPORT;
                    srv_gatts_send_response(conn, trans_id, OS_STATUS_FAILED, attr_handle, &att_value);
                }
                return;
            }
            pConnNode = (PrxrConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
        }
    }
    else if(type == TYPE_DESCRIPTOR)
    {
#if defined (__BLE_DEBUG_LOG__)
        {
            char testLog[64] = {0};

            if(value->value[0] == 0x01)
            {
                sprintf(testLog, "订阅 %02X %02X\r\n", value->value[0], value->value[1]);
            }
            else
            {
                sprintf(testLog, "取消订阅 %02X %02X\r\n", value->value[0], value->value[1]);
            }
            U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));
        }
#endif /*__BLE_DEBUG_LOG__*/
        att_value.len = 1;
        att_value.value[offset] = value->value[0];
        srv_gatts_send_response(conn, trans_id, OS_STATUS_SUCCESS, attr_handle, &att_value);
    }
    else
    {
        att_value.len = 1;
        att_value.value[offset] = GATT_ERROR_REQUEST_NOT_SUPPORT;
        srv_gatts_send_response(conn, trans_id, OS_STATUS_FAILED, attr_handle, &att_value);
    }
}

#endif /* __BLE_QB__ */

