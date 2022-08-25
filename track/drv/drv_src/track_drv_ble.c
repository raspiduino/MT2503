/******************************************************************************
 * track_ble_gatt.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        BLE GATT 控制驱动，MMI与BCM模块通信
 *
 * modification history
 * --------------------
 * v1.0   2017-05-18,  chengjun create this file
 *
 ******************************************************************************/
#if defined (__BLE_GATT__)


/****************************************************************************
* Include Files 					 包含头文件
*****************************************************************************/
#include "track_drv_ble.h"
#include "track_os_ell.h"
#include "bt_types.h"
#include "bluetooth_gatts_struct.h"
#include "bluetooth_gap_struct.h"
#include "bcm_struct.h"

/*****************************************************************************
 *	Define				 宏定义
*****************************************************************************/


/*****************************************************************************
* Typedef	Enum
*****************************************************************************/


/*****************************************************************************
 *	Struct				 数据结构定义
*****************************************************************************/


/*****************************************************************************
* Local variable				 局部变量
*****************************************************************************/
static U8 btaddr_str[20]={0};
/****************************************************************************
* Global Variable - Extern		 全局变量
*****************************************************************************/
BD_ADDR track_bt_addr={0};
/****************************************************************************
* Global Variable - Extern			 引用全局变量
*****************************************************************************/
//extern gatts_callback_struct bcm_gatts_cbs;


/*****************************************************************************
 *	Global Functions	 - Extern		 引用外部函数
*****************************************************************************/

extern kal_uint8* track_cust_deviceSN();

/*****************************************************************************
 *	Local Functions 	 本地函数
*****************************************************************************/
static kal_uint8* textMD5(kal_uint8 *data, kal_uint8 *outdata, kal_uint32 len)
{
	applib_md5_ctx md5_ctx;
	U8 hash_result[16] = {0};

	OTA_applib_md5_init(&md5_ctx);
	OTA_applib_md5_update(&md5_ctx, (kal_uint8 *)data, len);
	OTA_applib_md5_final(hash_result, &md5_ctx);
	memcpy(outdata, hash_result, 16);
	return hash_result;
}

/******************************************************************************
 *  Function    -  track_ble_gatt_switch
 * 
 *  Purpose     -  track MMI向BCM发请求开启或关闭蓝牙
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-05-23,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_ble_gatt_switch(kal_uint8 on)
{
	//ilm_struct *send_ilm;
	kal_uint8 adv_sn[16];
	kal_uint8 serialnum[5];
	track_ble_switch_msg_struct *myMsgPtr = NULL;
	myMsgPtr = (track_ble_switch_msg_struct*) construct_local_para(sizeof(track_ble_switch_msg_struct), TD_RESET);
	myMsgPtr->ble_switch = on;
	#if 0//defined(__BLE_N07__)
	sprintf(myMsgPtr->name_data, "%s",G_parameter.ste_param.bt_name);
	//myMsgPtr->devicesn[0]是否使用新sn号码 myMsgPtr->devicesn[1] sn号码长度
	track_cust_str_to_hex();
	myMsgPtr->devicesn[0] = G_parameter.ste_status.btadvtype;//0 测试代码写死示例   1 使用新的 16进制代码
	myMsgPtr->devicesn[1] = 16;//广播数据长度
	textMD5(track_cust_deviceSN(),adv_sn,5);
	memcpy(&myMsgPtr->devicesn[2], adv_sn, 16);
	LOGH(L_APP, L_V5, adv_sn, 16);
	//sprintf(myMsgPtr->devicesn, "%s", G_importance_parameter_data.SequenceNumber);
	#endif
	track_fun_msg_send(MSG_ID_BCM_TRACK_BLE_SWITCH_REQ, myMsgPtr, MOD_MMI, MOD_BCM);
}

/******************************************************************************
 *  Function    -  track_drv_ble_gatt_switch
 * 
 *  Purpose     -  打开蓝牙，启动gatt服务
 * 
 *  Description -  需要几秒钟才开始工作
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-05-23,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
kal_uint8 track_drv_ble_gatt_switch(kal_uint8 status)
{
    static kal_uint8 pre_status = 0xFF;

    LOGD(L_DRV, L_V5, "%d,%d", status, pre_status);

    if(status == pre_status)
    {
    	return 2;
    }
	
    if(status == 0 || status == 1)
    {
        track_ble_gatt_switch(status);
        pre_status = status;
    }
    return pre_status;
}

void track_drv_reply_ble(U8 *data,kal_uint8 len)
{
    //ilm_struct *send_ilm;
    track_reply_ble_msg_struct *myMsgPtr = NULL;
    myMsgPtr = (track_reply_ble_msg_struct*) construct_local_para(sizeof(track_reply_ble_msg_struct), TD_RESET);
	
	LOGH(L_APP, L_V1, data, len);
    //len=len>10?10:len;
    myMsgPtr->reply_data[0] = len;
    memcpy(&myMsgPtr->reply_data[1],data,len);   
    track_fun_msg_send(MSG_ID_BCM_TRACK_BLE_WRITE_REQ, myMsgPtr, MOD_MMI, MOD_BCM);
}

void track_drv_read_from_ble(void* msg)
{
	LOGD(L_APP, L_V5, "行运兔收到蓝牙消息");
#if defined(__EL100__)
    track_project_deal_ble_msg(msg);
#elif defined(__NF2318__)
	track_nf2318_blt_msg(msg);
#endif
}

kal_uint8* track_drv_ble_get_mac(kal_uint8 flag)
{
    if(flag == 1)
    {
        return track_bt_addr.addr;
    }
    else if(flag == 2)
    {
        return btaddr_str;
    }
}


void track_read_btaddr_data(void)
{
    nvram_ef_btradio_mtk_bt_chip_struct read_struct;
    kal_uint8 str[17] = {0};

    Track_nvram_read(NVRAM_EF_BTRADIO_MTK_BT_CHIP_LID, 1, (void *)&read_struct, NVRAM_EF_BTRADIO_MTK_BT_CHIP_SIZE);

    memcpy(track_bt_addr.addr,read_struct.BDAddr,6);
    HexToStr(btaddr_str, track_bt_addr.addr, 6);    
    LOGD(L_DRV, L_V6, "%02X,%02X,%02X,%02X,%02X,%02X", &track_bt_addr.addr[0], &track_bt_addr.addr[1], &track_bt_addr.addr[2], &track_bt_addr.addr[3], &track_bt_addr.addr[4], &track_bt_addr.addr[5]);

    LOGD(L_DRV, L_V5, "蓝牙地址=%s", btaddr_str);

}

//记得释放指针
U8* track_drv_rever_addr(U8 * str, U8 len)
{
    U8 *tmp =(U8*) Ram_Alloc(1,len+1);
    U8  i = 0, j = len;
    if(tmp!=NULL)
    {
        for (; i < len; i++)
        {
        	//if (str[j - 1]!= 0)
        	{
        		tmp[i] = str[j - 1];
        		j--;
        	}
        }
        tmp[len]=0;
    }
    return tmp;
}

/******************************************************************************
 *  Function    -  track_drv_write_le_mac
 * 
 *  Purpose     -  写入广播出去的地址接口
 * 
 *  Description - 广播地址顺序与传入mac 相反
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-08-30,  xzq  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_write_le_mac(U8 *mac)
{    
    bt_bm_change_le_address_req_struct *res_msg;
    res_msg = (bt_bm_change_le_address_req_struct*) construct_local_para(sizeof(bt_bm_change_le_address_req_struct), TD_RESET);
    memcpy(res_msg->addr,mac,sizeof(res_msg->addr));
    track_fun_msg_send(MSG_ID_BT_BM_CHANGE_LE_ADDRESS_REQ,(void*)res_msg, MOD_MMI, MOD_BT);
    //srv_bt_cm_send_msg(MOD_BT,BT_APP_SAP,MSG_ID_BT_BM_CHANGE_LE_ADDRESS_REQ,(void*)res_msg,NULL);
    //mmi_frm_send_ilm(MOD_BT, MSG_ID_BT_BM_CHANGE_LE_ADDRESS_REQ, (oslParaType*)res_msg, NULL);
}

/******************************************************************************
 *  Function    -  track_drv_read_le_mac_req
 * 
 *  Purpose     -  读取广播地址接口
 * 
 *  Description -
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-08-30,  xzq  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_read_le_mac_req()
{
    bt_gatts_get_random_addr_req_struct *req = NULL;
    req = (bt_gatts_get_random_addr_req_struct*) construct_local_para(sizeof(bt_gatts_get_random_addr_req_struct), TD_RESET);     

    if (req) 
    {
        track_fun_msg_send(MSG_ID_BT_GATTS_GET_RANDOM_ADDR_REQ,(void*)req, MOD_MMI, MOD_BT);
    }
}

void track_drv_read_le_mac_cnf(void *msg)
{
    bcm_gatt_read_local_addr_cnf_struct *cnf = (bcm_gatt_read_local_addr_cnf_struct *)msg;
    U8* pTemp=NULL;
    static U8 count=0;
    LOGD(L_DRV, L_V1, "读取MAC地址回复!!");
    if(count>5)return;
    if (cnf) 
    {
        LOGH(L_DRV,L_V3,cnf->bd_addr,BD_ADDR_SIZE);
        pTemp = track_drv_rever_addr(cnf->bd_addr,BD_ADDR_SIZE);
        if(pTemp)
        {
            LOGH(L_DRV,L_V2,pTemp,BD_ADDR_SIZE);
            if(memcmp(pTemp,track_bt_addr.addr,BD_ADDR_SIZE))
            {                
                LOGD(L_DRV, L_V1, "LE MAC ERROR %s", btaddr_str);
                track_drv_syn_le_btaddr();
                count++;
            }
            Ram_Free(pTemp);
        }
    }    
}


/******************************************************************************
 *  Function    -  track_drv_syn_le_btaddr
 * 
 *  Purpose     - 同步地址
 * 
 *  Description -
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-08-30,  xzq  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_syn_le_btaddr()
{
    //if(track_bt_addr.addr[0]!=0&&track_bt_addr.addr[1]!=0&&track_bt_addr.addr[2]!=0)   //delete by chengjun 
    {
        U8* pTemp;
        pTemp = track_drv_rever_addr(track_bt_addr.addr,BD_ADDR_SIZE);
        if(pTemp)
        {
            track_drv_write_le_mac(pTemp);

            LOGH(L_DRV,L_V4,pTemp,BD_ADDR_SIZE);
                
            Ram_Free(pTemp);

            tr_start_timer(TRACK_CUST_GATTS_READ_LE_MAC_TIMER_ID,1000,track_drv_read_le_mac_req);
        }
    }
}

void drv_ble_msg_init()
{
    //SetProtocolEventHandler(track_drv_read_le_mac_cnf, MSG_ID_BT_GATTS_GET_RANDOM_ADDR_CNF);
    //SetProtocolEventHandler(track_drv_read_from_ble, MSG_ID_BCM_TRACK_DATA_TC);
}

#endif /* __BLE_GATT__ */

