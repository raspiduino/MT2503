/******************************************************************************
 * track_ble_gb.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        BLE GATT协议处理 ，GB100项目定制功能
 *
 * modification history
 * --------------------
 * v1.0   2017-09-12,  chengjun create this file
 *
 ******************************************************************************/
#if defined (__BLE_GB__)

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
#define TEST_SUEECSS    0xFE
#define TEST_FAIL       0xFF



/*****************************************************************************
* Typedef	Enum
*****************************************************************************/


/*****************************************************************************
 *	Struct				 数据结构定义
*****************************************************************************/

/*****************************************************************************
 *	Local Functions 	 本地函数
*****************************************************************************/

/*****************************************************************************
* Local variable				 局部变量
*****************************************************************************/
static unsigned char ble_gb_aes_key[16] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4f, 0x1f, 0x4a, 0x09, 0x3e, 0x23, 0x6a, 0x29, 0x6b, 0x3f};
static unsigned char ble_gb_rang_data[6];
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
extern unsigned char *gatts_get_ble_mac_addr(void);

/*****************************************************************************
 *	Local Functions 	 本地函数
*****************************************************************************/
///往TRACK透传信息
void track_ble_tc_data(BLE_EVT type, U8 *data, U8 len)
{
    track_reply_ble_msg_struct *msg_p;
    msg_p = (track_reply_ble_msg_struct*)construct_local_para(sizeof(track_reply_ble_msg_struct), TD_RESET);
    msg_p->reply_data[0] = type;
    if(data!=NULL)
    {
        memcpy(&msg_p->reply_data[1], data, len);
    }
    srv_bt_cm_send_msg(MOD_MMI, INVALID_SAP, MSG_ID_BCM_TRACK_DATA_TC, (void*)msg_p, NULL);
}


void track_gatt_update_random_key(void)
{
    kal_uint32 ticks = kal_get_systicks();

    //ticks 转成6Byte的随机数作为秘钥头
    if(ticks < 0xFFFF)
    {
        ticks += 0x12345;
    }

    ble_gb_rang_data[0] = (ticks & 0xFF);
    ble_gb_rang_data[1] = ((ticks >> 16) & 0xFF);
    ble_gb_rang_data[2] = ((ticks >> 4) & 0xFF);
    ble_gb_rang_data[3] = ((ticks >> 8) & 0xFF);
    ble_gb_rang_data[4] = ((ticks >> 20) & 0xFF);
    ble_gb_rang_data[5] = ((ticks >> 12) & 0xFF);
}


kal_uint8 *track_gb_get_rand_data(void)
{
    return ble_gb_rang_data;
}

U32 track_gb_ble_send_data(kal_uint16 server_uuid, kal_uint16 char_uuid, U8* buf, U16 len)
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
            if(pConnNext == NULL)
            {
                return send_size;
            }
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
                            att_value = (ATT_VALUE *)get_ctrl_buffer(sizeof(ATT_VALUE));

                            if(att_value == NULL)
                            {
                                sprintf(log, " error att_value %d\r\n", att_value);
                                U_PutUARTBytes(0, (kal_uint8*)log, strlen(log));
                                return send_size;
                            }

                            memcpy(att_value->value, buf, len);

                            sprintf(log, "%04X >> (%d) %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X\r\n", char_uuid, len, \
                                    buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6], buf[7], buf[8], buf[9], \
                                    buf[10], buf[11], buf[12], buf[13], buf[14], buf[15], buf[16], buf[17], buf[18], buf[19]);
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
                    if(svc_list == NULL)
                    {
                        return send_size;
                    }
                }
            }

            pConnNode = pConnNext;
        }
    }
    return send_size;
}


/******************************************************************************
 *  Function    -  track_gb_ble_write_decode
 *
 *  Purpose     -  分包解析
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-09-13,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_gb_ble_write_decode(kal_uint8 *buff, kal_uint16 len)
{
    kal_uint8 send_data[20]={0};//要发出包
    kal_uint8 *ble_addr;

#if defined (__BLE_DEBUG_LOG__)
    char testLog[128] = {0};
#endif /* __BLE_DEBUG_LOG__ */

    if((len == 1) && (buff[0] == 0x03))
    {
#if defined (__BLE_DEBUG_LOG__)
        sprintf(testLog, "获取加密Key\r\n");
        U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));
#endif /* __BLE_DEBUG_LOG__ */


        //0x42 0x54 0x52 协议文档也是醉了，一会52一会50
        send_data[0] = 0x42;
        send_data[1] = 0x54;
        send_data[2] = 0x50;
        send_data[3] = 0x06;
        memcpy(&send_data[4], track_gb_get_rand_data(), 6);

        track_gb_ble_send_data(0xFE00, 0xFE02, send_data, 10);
    }
    else if((len == 20) && (buff[0] == 0x01))
    {
        static kal_uint8 source_data[16];
        static kal_uint8 aes_data[16];
        kal_uint8 unlock_result=0x04;

#if defined (__BLE_DEBUG_LOG__)
        sprintf(testLog, "rece  %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X\r\n", \
                buff[0], buff[1], buff[2], buff[3], buff[4], buff[5], buff[6], buff[7], \
                buff[8], buff[9], buff[10], buff[11], buff[12], buff[13], buff[14], buff[15],\
                buff[16], buff[17], buff[18], buff[19]);
        U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));

#endif /* __BLE_DEBUG_LOG__ */
        memcpy(source_data, &buff[5], 4);
        memcpy(&source_data[4], track_gb_get_rand_data(), 6);

        ble_addr = gatts_get_ble_mac_addr();

        source_data[10] = ble_addr[5];
        source_data[11] = ble_addr[4];
        source_data[12] = ble_addr[3];
        source_data[13] = ble_addr[2];
        source_data[14] = ble_addr[1];
        source_data[15] = ble_addr[0];


        ble_gb_aes_key[0] = buff[9];
        ble_gb_aes_key[1] = buff[10];
        ble_gb_aes_key[2] = buff[11];
        ble_gb_aes_key[3] = buff[12];
        ble_gb_aes_key[4] = buff[13];
        ble_gb_aes_key[5] = buff[14];


        AES_Init(ble_gb_aes_key);
        AES_Encrypt(source_data, aes_data, 16, NULL);

#if defined (__BLE_DEBUG_LOG__)

        sprintf(testLog, "source_data  %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X \r\n", \
                source_data[0], source_data[1], source_data[2], source_data[3], source_data[4], source_data[5], source_data[6], source_data[7], \
                source_data[8], source_data[9], source_data[10], source_data[11], source_data[12], source_data[13], source_data[14], source_data[15]);
        U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));


        sprintf(testLog, "ble_gb_aes_key  %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X \r\n", \
                ble_gb_aes_key[0], ble_gb_aes_key[1], ble_gb_aes_key[2], ble_gb_aes_key[3], ble_gb_aes_key[4], ble_gb_aes_key[5], ble_gb_aes_key[6], ble_gb_aes_key[7], \
                ble_gb_aes_key[8], ble_gb_aes_key[9], ble_gb_aes_key[10], ble_gb_aes_key[11], ble_gb_aes_key[12], ble_gb_aes_key[13], ble_gb_aes_key[14], ble_gb_aes_key[15]);
        U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));

        sprintf(testLog, "aes_data  %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X \r\n", \
                aes_data[0], aes_data[1], aes_data[2], aes_data[3], aes_data[4], aes_data[5], aes_data[6], aes_data[7], \
                aes_data[8], aes_data[9], aes_data[10], aes_data[11], aes_data[12], aes_data[13], aes_data[14], aes_data[15]);
        U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));


#endif /* __BLE_DEBUG_LOG__ */

        if ((aes_data[0]==buff[1]) && (aes_data[1]==buff[2]) && (aes_data[2]==buff[3]) && (aes_data[3]==buff[4]))
        {
            sprintf(testLog, "开锁 密码正确\r\n");
            U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));
            unlock_result=0x02;
        }
        else
        {
            sprintf(testLog, "开锁 解密有问题\r\n");
            U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));        
            unlock_result=0x04;
        }

        track_ble_tc_data(BLE_EVT_UNLOCK,NULL,0);

        send_data[0] = 0x42;
        send_data[1] = 0x54;
        send_data[2] = 0x52;
        send_data[3] = 0x03;

        send_data[4] = unlock_result;
        send_data[5] = 0x00;
        send_data[6] = 0x01;

        track_gb_ble_send_data(0xFE00, 0xFE02, send_data, 7);
    }
}


/******************************************************************************
 *  Function    -  track_gb_ble_factory_test
 *
 *  Purpose     -  对接厂测工具
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-09-15,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_gb_ble_factory_test(kal_uint8 *buff, kal_uint16 len)
{
    kal_uint8 send_data[20];//要发出包
    kal_uint8 send_len = 0;
    kal_uint8 cmd = buff[0];

#if defined (__BLE_DEBUG_LOG__)
    char testLog[128] = {0};
#endif /* __BLE_DEBUG_LOG__ */

    if(len != 1)
    {
#if defined (__BLE_DEBUG_LOG__)
        sprintf(testLog, "len not support\r\n");
        U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));
#endif /* __BLE_DEBUG_LOG__ */
        return;
    }

    send_data[0] = cmd;
    send_data[1] = 0x11;

    switch(cmd)
    {
        case 0x01:
            break;

        case 0x02://进入运输模式
#if defined (__BLE_DEBUG_LOG__)
            sprintf(testLog, "进入运输模式\r\n");
            U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));
#endif /* __BLE_DEBUG_LOG__ */
            break;

        case 0x03://喇叭开
#if defined (__BLE_DEBUG_LOG__)
            sprintf(testLog, "喇叭开\r\n");
            U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));
#endif /* __BLE_DEBUG_LOG__ */
            break;

        case 0x04://喇叭关
#if defined (__BLE_DEBUG_LOG__)
            sprintf(testLog, "喇叭关\r\n");
            U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));
#endif /* __BLE_DEBUG_LOG__ */
            break;

        case 0x05://LED亮
#if defined (__BLE_DEBUG_LOG__)
            sprintf(testLog, "LED亮\r\n");
            U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));
#endif /* __BLE_DEBUG_LOG__ */
            break;

        case 0x06://LED灭
#if defined (__BLE_DEBUG_LOG__)
            sprintf(testLog, "LED灭\r\n");
            U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));
#endif /* __BLE_DEBUG_LOG__ */
            break;

        case 0x07://SENSOR测试
            send_data[2] = TEST_SUEECSS;
            send_len = 3;
            break;

        case 0x08://SIM卡检测
            send_data[2] = TEST_SUEECSS;
            send_len = 3;
            break;

        case 0x09://电池电压上报
            send_data[2] = 0x10;
            send_data[3] = 0x1B;
            send_len = 4;
            break;

        case 0x0A://GSM信号上报
            send_data[2] = 32;
            send_len = 3;
            break;

        case 0x0B://GPS状态上报
            send_data[2] = 0x03;
            send_data[3] = 0xC9;
            send_data[4] = 0x43;
            send_len = 5;
            break;

        case 0x0C://WIFI开启
            break;

        case 0x0D://WIFI搜索
            break;

        case 0x0E://GSM软件版本上报
            memcpy(&send_data[2], "chengJun", 8);
            send_len = 10;
            break;

        default:
            break;
    }

    if(send_len > 0)
    {
        track_gb_ble_send_data(0xFE00, 0xFEFF, send_data, send_len);
    }
}

void track_gb_request_read_callback(gatt_conn_struct *conn, U16 trans_id, BD_ADDR *bd_addr,
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
        else if((svc_uuid16 == 0x180F) && (chr_uuid16 == 0x2A19))//电池电量百分比
        {
            att_value.len = 1;
            att_value.value[offset] = 43;
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

void track_gb_request_write_callback(gatt_conn_struct *conn, U16 trans_id, BD_ADDR *bd_addr,
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
        sprintf(testLog, "## track_gb_request_write_callback %d,%d,%d;%X,%X\r\n", type, need_rsp, offset, svc_uuid16, chr_uuid16);
        U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));
        memset(testLog,0x00,sizeof(testLog));
        if(value->len == 1)
        {
            sprintf(testLog, "(%d) - %02X\r\n", value->len, value->value[0]);
        }
        else
        {
            sprintf(testLog, "(%d) - %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X\r\n", value->len, \
                    value->value[0], value->value[1], value->value[2], value->value[3], value->value[4], value->value[5], value->value[6], value->value[7], \
                    value->value[8], value->value[9], value->value[10], value->value[11], value->value[12], value->value[13], value->value[14], value->value[15], \
                    value->value[16], value->value[17], value->value[18], value->value[19]);
        }
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
                else if(svc_uuid16 == 0xFE00 && chr_uuid16 == 0xFE01)
                {
                    srv_gatts_send_response(conn, trans_id, OS_STATUS_SUCCESS, attr_handle, value);
                    track_gb_ble_write_decode(value->value, value->len);
                }
                else if(svc_uuid16 == 0xFE00 && chr_uuid16 == 0xFEFF)
                {
                    srv_gatts_send_response(conn, trans_id, OS_STATUS_SUCCESS, attr_handle, value);
                    track_gb_ble_factory_test(value->value, value->len);
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

#endif /* __BLE_GB__ */

