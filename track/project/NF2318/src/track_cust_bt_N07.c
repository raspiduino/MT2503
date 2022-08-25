#if defined(__BLE_N07__)
/****************************************************************************
***file author: xiongweiming
***creat date:2019-12-11
***introduction:
****************行运兔蓝牙协议
****************************************************************************/
/****************************************************************************
*  Include Files						包含头文件
*****************************************************************************/
#include "track_cust.h"
#include "c_vector.h"
#include "track_fun_XxTEA.h"
#include "track_ble_gatt.h"
/*****************************************************************************
*  Local variable                       局部变量
*****************************************************************************/
typedef struct
{
	char phone_num[11];//默认的电话号码
	char new_user_num[11];//用户刚注册的号码
}blue_app_inf;


/****************************************************************************
*  Global Variable						全局变量
*****************************************************************************/
static blue_app_inf bt_info = {{"13188888888"},{0}};


/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/


/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/
extern kal_uint8 get_speed(void);
extern void track_cust_lease_overtimer(void* arg);
extern kal_uint8 track_mode_lease_off(U8 type);


/*****************************************************************************
*  Global Functions - Extern            原始所有代码暂时保存
******************************************************************************/
controller_data_struct cData_bt = {0};
kal_uint8 BT_VERSION[1] = {0x01};
extern kal_uint8 controller_status;
extern void track_cust_exbatlock_overtime(void* param);
extern void track_cust_rearwheel_overtime(void* param);
extern void track_cust_vehicle_status(kal_uint8 *src);
extern void track_cmd_resetbt(void* param);
void track_bt_cmd_overtime(U8 PN, U8 exe);
//20的SN压缩到16位
void bett_sn_20to16(kal_uint8*data16,kal_uint8*data20);
//---------蓝牙重置
//extern void track_get_bt_passwort(char * data);//20190717
extern void track_cust_N07_paket_92(U8 exeresult,kal_uint8 * id);//
extern kal_uint8 get_bett_sn(kal_uint8 value);//返回电磁SN是16还是20位的标志
#if 0
static U8 bt_gsm_level(void)
{
    int tmp, ret;
    tmp = track_cust_get_rssi(-1);
    LOGD(L_APP, L_V6, "rssi=%d", tmp);
    if(tmp == 99)
        ret = 0;
    else if(tmp == 0)
        ret = 0;
    else if(tmp <= 3)
        ret = 1;
    else if(tmp <= 6)
        ret = 2;
    else if(tmp <= 9)
        ret = 3;
    else if(tmp <= 12)
        ret = 4;
    else if(tmp <= 17)
        ret = 5;
    else if(tmp <= 21)
        ret = 6;
    else if(tmp <= 24)
        ret = 7;
    else if(tmp <= 28)
        ret = 8;
    else
        ret = 9;
    return ret;
}
#endif
static kal_uint16 bt_signal()
{
    kal_uint16 signal = 0;
    U8 sat = 0;
    U8 vbat = 0;
    U8 gsm = 0;
    track_gps_data_struct *gpsLastPoint = NULL;

    //gps状态
    if(track_cust_gps_status() > 2)
    {
        signal = 1;
        gpsLastPoint = track_drv_get_gps_data();
        sat = gpsLastPoint->gpgga.sat + gpsLastPoint->bdgga.sat;
        if(sat > 9) sat = 9;
    }
    else
    {
        gpsLastPoint = track_cust_backup_gps_data(2, NULL);
        if(gpsLastPoint->bdrmc.status >= 2) signal = 2;
    }
    vbat = track_cust_get_battery_level();
    gsm = track_cust_get_rssi_level();//bt_gsm_level();

    LOGD(L_APP, L_V5, "%d,%d,%d,%d", signal, sat, vbat, gsm);
    signal = signal | ((sat & 0x00FF) << 2) | ((vbat & 0x00FF) << 6) | ((gsm & 0x00FF) << 10);
    LOGD(L_APP, L_V5, "%d", signal);
    return signal;
}

static kal_uint16 bt_ste_status()
{
    kal_uint16 tmp = 0;
    kal_uint8 vehicl_status[2] = {0};
    track_cust_vehicle_status(vehicl_status);
    tmp = ((vehicl_status[0] & 0x00FF) << 8) | vehicl_status[1];
    LOGD(L_APP, L_V5, "0x%04X", tmp);
    return tmp;
}

static void track_cust_timet(U8 *sendbuf)
{
    kal_uint32 sec = 0;
    sec = OTA_app_getcurrtime();
    track_fun_reverse_32(sendbuf, sec);
}

static void track_cust_N07BT_pack(kal_uint8 PN, kal_uint8 result, kal_uint8* data, kal_uint16 len)
{
    kal_uint8 *sendData;
    kal_uint16 size = 0;
    int i = 0;
    if(PN != 0x20 && PN != 0x21)
    {
        size = 2 + 5 + len;
    }
    else
    {
        size = 2 + 1 + len;
    }
    sendData = (U8*)Ram_Alloc(5, size);
    sendData[i++] = 0x4F;//信息头
    sendData[i++] = PN;//信息头
    sendData[i++] = result;//指令结果 0x00 成功  0x01 失败 0x02 已经是当前状态
    if(PN != 0x20 && PN != 0x21)
    {
        track_cust_timet(&sendData[i]);//系统时间
        i += 4;
    }
    memcpy(&sendData[i], data, len);
    LOGH2(L_APP, L_V5, "", sendData, size);
    track_drv_reply_ble(sendData, size);
    Ram_Free(sendData);
}

void bt_rsp_app_01(U8 PN, U8 exe)
{
    kal_uint8 data[9];
    kal_uint16 signal = bt_signal();
    kal_uint16 stestatus = bt_ste_status();
    data[0] = (signal & 0xFF00) >> 8;
    data[1] = signal & 0x00FF;
    data[2] = (stestatus & 0xFF00) >> 8;
    data[3] = stestatus & 0x00FF;
    data[4] = cData_bt.relativeCapacityPer;
    data[5] = cData_bt.totalValtage[0];
    data[6] = cData_bt.totalValtage[1];
    data[7] = cData_bt.temperature[0];
    data[8] = cData_bt.temperature[1];

    track_cust_N07BT_pack(PN, exe, data, 9);
}
void bt_rsp_app_02(U8 PN, U8 exe)
{
    kal_uint8 data[4];
    kal_uint16 stestatus = bt_ste_status();
    data[0] = (stestatus & 0xFF00) >> 8;
    data[1] = stestatus & 0x00FF;
    data[2] = cData_bt.totalValtage[0];
    data[3] = cData_bt.totalValtage[1];

    track_cust_N07BT_pack(PN, exe, data, 4);
}
static void bt_rsp_app_03(U8 PN, U8 exe)
{
    kal_uint8 data[16];
    kal_uint8 data_20[20]={0};
    if(get_bett_sn(99) == 0)//16位电池SN
    {
    	memcpy(data, cData_bt.barCode, 16);
    }
    else if( get_bett_sn(99) == 1)//20位电池SN要进行压缩
    {
    	memcpy(data_20, cData_bt.barCode, 20);
    	bett_sn_20to16(data,data_20);//压缩到16位
    }

    track_cust_N07BT_pack(PN, exe, data, 16);
}

static void bt_rsp_app_04(U8 PN, U8 exe)
{
    kal_uint8 data[14];

    track_gps_data_struct *gd = NULL;
    LBS_Multi_Cell_Data_Struct *lbs = track_drv_get_lbs_data();
    gd = track_drv_get_gps_data();

    track_fun_reverse_16(&data[0], lbs->MainCell_Info.mnc);
    track_fun_reverse_16(&data[2], lbs->MainCell_Info.lac);
    track_fun_reverse_16(&data[4], lbs->MainCell_Info.cell_id);
    track_fun_LongitudeLatitudeToHex(&data[6], gd->gprmc.Latitude);
    track_fun_LongitudeLatitudeToHex(&data[10], gd->gprmc.Longitude);

    track_cust_N07BT_pack(PN, exe, data, 14);

}
static void bt_rsp_app_05(U8 PN, U8 exe)
{
    kal_uint8 data[8];
    kal_uint32 mileage = 0;
    kal_uint32 totalmi = 0;
    //track_cust_timet(&data[0]);
    track_fun_reverse_32(&data[0], G_parameter.ele_data.oncemileage);

    track_fun_reverse_32(&data[4], G_parameter.ele_data.totalmileage);
    track_cust_N07BT_pack(PN, exe, data, 8);

}/*
static void bt_rsp_version(U8 PN, U8 exe)
{
	kal_uint8 data[6];
	data[0] = 0x00;
	track_cust_timet(&data[1]);
	data[5] = BT_VERSION[0];

    track_cust_N07BT_pack(PN, exe, data, 6);
}*/
//static unsigned char encode_token[16] = {0x87, 0x32, 0x87, 0xe4, 0x47, 0x3c, 0x15, 0x8e, 0x2e, 0x87, 0x3d, 0xaf, 0x65, 0xbd, 0x7b, 0xa8};
//unsigned char encode_token[16] = {0x65, 0x83, 0x04, 0x14, 0x4f, 0x5a, 0xd2, 0x76, 0xb4, 0xae, 0x15, 0x7b, 0x25, 0x31, 0xf2, 0x2e};
kal_uint8 bt_pass_start = 0;
extern void bt_pass_change_d_s(kal_uint8 * data_d,kal_uint8 * data_s,kal_uint8 type);
static unsigned char btpasswrold[16]={0};
//----------------20191009
extern kal_uint8 track_get_lesea_off_sta(kal_uint8 value);//关锁标志0正常关锁成功，1 进行时 2 失败 流程走完
//--------
void track_cust_N07BT_recv1(kal_uint8 *data, kal_uint16 len)
{
    U8 exe = 99;
	kal_uint8 get_bt_new[16];//
    kal_uint16 playtimes = 0;
    int declen = 0;
    kal_uint8 PN = 0;
    kal_uint8 tmp[20];

    memcpy(tmp, data, 20);
    //track_get_bt_passwort(get_bt_new);//获得新密码
    if(get_token_type() == 1)
    {
        //sg_xxtea_set_key(encode_token);
    	if(G_parameter.bt_token_mark)//
    	{
    		memset(get_bt_new,0x00,16);
    		bt_pass_change_d_s(get_bt_new,G_parameter.new_encode_token_s,0);
    		/*LOGD(L_APP, L_V5,"0x%0.2x 0x%0.2x 0x%0.2x 0x%0.2x 0x%0.2x 0x%0.2x 0x%0.2x 0x%0.2x 0x%0.2x 0x%0.2x 0x%0.2x 0x%0.2x 0x%0.2x 0x%0.2x 0x%0.2x 0x%0.2x",
    		get_bt_new[0],get_bt_new[1],get_bt_new[2],get_bt_new[3],get_bt_new[4],get_bt_new[5],get_bt_new[6],get_bt_new[7],get_bt_new[8],
    		get_bt_new[9],get_bt_new[10],get_bt_new[11],get_bt_new[12],get_bt_new[13],get_bt_new[14],get_bt_new[15]);*/
        	sg_xxtea_set_key(get_bt_new);//
        }
        else
        {
        	if(bt_pass_start == 0)
        	{
        		LOGD(L_APP, L_V1,"----------> frist time btpass to d");
				bt_pass_start++;
				memset(btpasswrold,0x00,16);
				bt_pass_change_d_s(btpasswrold,G_parameter.encode_token_s,0);
        	}
        	sg_xxtea_set_key(btpasswrold);
			//sg_xxtea_set_key(G_parameter.encode_token);
        }
    }
    else
    {
        sg_xxtea_set_key(G_parameter.ste_param.TEA_KEY);
    }
    declen = sg_xxtea_decrypt(tmp, 20, 16);
    #if 0
    //--------------------------
    {
		sg_xxtea_set_key(btpasswrold);
		declen2 = sg_xxtea_decrypt(tmp2, 20, 16);
		if((declen2 < 0) || tmp2[0] != 0x4F)
		{
			LOGD(L_APP, L_V1,"------------------------------------>>>>>::%02x %d 我也不晓得说什么1111111111111111",tmp2[0],declen2);
		}
		else
		{
			LOGD(L_APP, L_V1,"------------------------------------>>>>>::%02x  %d 我也不晓得说什么2222222222222222",tmp2[0],declen2);
		}
		
    }
    //---------------------------
    #endif
    if((declen < 0) || tmp[0] != 0x4F)
    {
        LOGD(L_APP, L_V1, "Error!!!蓝牙数据超长或者当前TOKEN已经过期！%d", declen);
        //新密码连接失败
    	if(G_parameter.bt_token_mark)
    	{
    		LOGD(L_APP, L_V1,"------> new BT pass wrod change in defeated");
    		memset(G_parameter.new_encode_token_s,0x00,50);//失败清空
    		//Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
    		track_cust_N07_paket_92(0x01,NULL);//
    	}
        track_cmd_resetbt((void*)0);
        return;
    }
    //新蓝牙密码连接成功
    if(G_parameter.bt_token_mark)
    {
    	LOGD(L_APP, L_V1,"------> new BT pass wrod change successful");
    	
    	//memcpy(G_parameter.encode_token,get_bt_new,16);//一代新码换旧码
    	//bt_pass_change_d_s(get_bt_new,G_parameter.encode_token_s,1);
    	memcpy(G_parameter.encode_token_s,G_parameter.new_encode_token_s,50);
    	bt_pass_start = 0;
    	track_cust_N07_paket_92(0x00,NULL);//
    	//Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
    }
    
    //LOGD(L_APP, L_V5, "%X,%X", data[0],data[1]);
    track_bms_struct_copy(&cData_bt);
    LOGH(L_APP, L_V5, tmp, declen);
    if(tmp[0] == 0x4F)
    {
        PN = tmp[1];
    }
    if(PN == 0x00) //查询版本信息
    {
        track_cust_N07BT_pack(PN, 0x00, BT_VERSION, 1);
        //bt_rsp_version(PN,0x00);
    }
    else if(PN == 0x0B) //车辆开启
    {
        if((track_cust_get_lease_desired() == 1 || track_is_timer_run(TRACK_CUST_LEASE_ON_PRECONDITION_TIMER_ID)) && track_is_timer_run(TRACK_CUST_ONLINE_COMMAND_RESULT_DELAY_TIMER_ID))
        {
            LOGD(L_APP, L_V5, "---------------->GPRS Open Lock Now !start BlueTooth timer!");
            track_start_timer(TRACK_CUST_BLUETOOTH_COMMAND_RESULT_DELAY_TIMER_ID, 10 * 1000, track_cust_lease_overtimer, (void*)1);
            return;
        }
        if(track_cust_get_lease_desired() == 0)
        {
            LOGD(L_APP, L_V5, "---------------->1 Execute Lease OFF CMD,Do not execute Lease ON CMD[BT]");//这种情况怎么办呢，他妈的我就遇到了，执行开锁的时候，来了关锁我返回
            return;
        }
        if(track_cust_get_lease_desired() == 1)
        {
            LOGD(L_APP, L_V5, "---------------->2 Execute Lease ON CMD,Do not execute Lease ON CMD[BT]");//这种情况怎么办呢，他妈的我就遇到了，执行开锁的时候，来了关锁我返回
            return;
        }
        if(G_parameter.ste_status.lease == 1 && G_realtime_data.defences_status != 1)
        {
            LOGD(L_APP, L_V5, "已经开锁");
            bt_rsp_app_01(PN, 2);
        }
        else
        {
            track_start_timer(TRACK_CUST_BLUETOOTH_COMMAND_RESULT_DELAY_TIMER_ID, 10 * 1000, track_cust_lease_overtimer, (void*)1);
            track_cust_lease_on_precondition((void*)0);
#if 0
            exe = track_mode_lease_on(0);
            if(exe == 99)
            {
                tr_stop_timer(TRACK_CUST_BLUETOOTH_COMMAND_RESULT_DELAY_TIMER_ID);
                track_bt_cmd_overtime(0x0B, 0x01);
            }
#endif
            //bt_rsp_app_01(PN, exe);

        }
    }
    else if(PN == 0x01) //车辆关闭 0x0C
    {
        if(track_cust_get_lease_desired() == 0 && track_is_timer_run(TRACK_CUST_ONLINE_COMMAND_RESULT_DELAY_TIMER_ID))
        {
            //网络关锁
            LOGD(L_APP, L_V5, "---------------->5 GPRS Lock Now !start BlueTooth timer![==BT==]");
            track_start_timer(TRACK_CUST_BLUETOOTH_COMMAND_RESULT_DELAY_TIMER_ID, 10 * 1000, track_cust_lease_overtimer, (void*)1);
            return;
        }
        if(track_cust_get_lease_desired() == 1)
        {
            LOGD(L_APP, L_V5, "---------------->3 Execute Lease On CMD,Do not execute Lease OFF CMD[==BT==]");//这种情况怎么办呢，他妈的我就遇到了，执行开锁的时候，来了关锁我返回
            return;
        }
        if(track_cust_get_lease_desired() == 0)
        {
            //正在关锁，又来关锁，抛弃
            LOGD(L_APP, L_V5, "---------------->4 Execute Lease OFF CMD,Do not execute Lease OFF CMD[==BT==]");//这种情况怎么办呢，他妈的我就遇到了，执行开锁的时候，来了关锁我返回
            return;
        }
        //if(G_parameter.ste_status.lease == 0 && G_realtime_data.defences_status != 1)
        //是否关锁成功
        if(G_parameter.ste_status.lease == 0 && G_realtime_data.defences_status != 1 && track_get_lesea_off_sta(99) == 0)
        {
            LOGD(L_APP, L_V5, "已经关锁");
            bt_rsp_app_01(PN, 2);
        }
        else
        {
        	if(track_get_lesea_off_sta(99) != 1)//
        	{//
        	LOGD(L_APP, L_V5, "蓝牙关锁开始");//
        	//track_get_lesea_off_sta(1);//标志设置为正在进行关锁流程，
            track_start_timer(TRACK_CUST_BLUETOOTH_COMMAND_RESULT_DELAY_TIMER_ID, 10 * 1000, track_cust_lease_overtimer, (void*)1);
            exe = track_mode_lease_off(0);
            if(exe == 0x02)
            {
                tr_stop_timer(TRACK_CUST_BLUETOOTH_COMMAND_RESULT_DELAY_TIMER_ID);
                bt_rsp_app_01(PN, 0x01);
            }
            }//
            else//
            {
            	LOGD(L_APP, L_V5, "上次关锁流程未完成");
				bt_rsp_app_01(PN, 0x01);
            }//
        }
    }
    else if(PN == 0x02) //撤防
    {
        track_mode_disarm();
        bt_rsp_app_02(PN, 0x00);
    }
    else if(PN == 0x09) //寻车开启
    {
        //G_parameter.ste_status.findcar = 1;
        //寻车
        if(!track_is_timer_run(TRACK_CUST_TEST_RING_TIMER_ID))//(G_parameter.ste_status.lease == 0 && !track_is_timer_run(TRACK_CUST_TEST_RING_TIMER_ID))
        {
            //playtimes = G_parameter.ste_param.xctime / 5;
            if(track_set_audio_file_play(99))return;//不寻车
            track_acc_status((void *)2);//GPIO_WriteIO(1, ELE_LOCK_GPIO);
            track_cust_playtime(1);
            xc_play((void *)0);
            exe = 0x00;
        }
        else
        {
            exe = 0x01;
        }
        bt_rsp_app_02(PN, exe);
    }
    else if(PN == 0x11) //关闭远程寻车
    {
        //G_parameter.ste_status.findcar = 0;
        if(track_is_timer_run(TRACK_CUST_TEST_RING_TIMER_ID))
        {
            tr_stop_timer(TRACK_CUST_TEST_RING_TIMER_ID);

            if(G_parameter.ste_status.lease == 0 || G_realtime_data.defences_status == 1)
            {
                track_acc_status((void *)0);//GPIO_WriteIO(0, ELE_LOCK_GPIO);
            }
            exe = 0x00;
        }
        else
        {
            exe = 0x01;
        }
        bt_rsp_app_02(PN, exe);
    }
    else if(PN == 0x0F) //打开电池锁
    {
        if(G_realtime_data.exbatlock == 0)
        {
            exe = 0x00;//0x02;
            bt_rsp_app_01(PN, exe);
        }
        else
        {
            track_start_timer(TRACK_CUST_BLUETOOTH_ELELOCK_DELAY_TIMER_ID, 5 * 1000, track_cust_exbatlock_overtime, (void *)0);
            track_cust_ele_on_gpio((void*)1);
        }
        //exe = 0;
        //bt_rsp_app_01(PN, exe);
    }
    else if(PN == 0x10) //关闭电池锁
    {
        if(G_realtime_data.exbatlock == 1)
        {
            exe = 0x00;//0x02;
            bt_rsp_app_01(PN, exe);
        }
        else
        {
            track_start_timer(TRACK_CUST_BLUETOOTH_ELELOCK_DELAY_TIMER_ID, 5 * 1000, track_cust_exbatlock_overtime, (void *)1);
            track_cust_ele_off_gpio((void*)1);
        }
        //track_cust_ele_off_gpio((void*)1);
        //exe = 0;
        //bt_rsp_app_01(PN, exe);
    }
    else if(PN == 0x16) //打开后轮锁
    {
        if(G_realtime_data.wheel == 0)
        {
            bt_rsp_app_02(PN, 0x00);//0x02
        }
        else
        {
            track_start_timer(TRACK_CUST_BLUETOOTH_REARLOCK_DELAY_TIMER_ID, 5 * 1000, track_cust_rearwheel_overtime, (void *)0);
            track_cust_gate_off_gpio((void*)1);
        }
        return;
    }
    else if(PN == 0x17) //关闭后轮锁
    {
        if(G_realtime_data.wheel == 1)
        {
            bt_rsp_app_02(PN, 0x00);//0x02
        }
        else
        {
            if(track_cust_not_wheel_lock() == 1)
            {
                bt_rsp_app_02(0x17, 0x01);
                return;
            }
            track_start_timer(TRACK_CUST_BLUETOOTH_REARLOCK_DELAY_TIMER_ID, 5 * 1000, track_cust_rearwheel_overtime, (void *)1);
            track_cust_gate_on_gpio((void*)1);
        }
        return;
    }
    else if(PN == 0x03) //重启终端
    {
        track_cust_restart(2, 20);
        bt_rsp_app_02(PN, 0x00);
    }
    else if(PN == 0x0A) //重启蓝牙
    {
        bt_rsp_app_02(PN, 0x00);
        //track_cmd_resetbt((void*)0);
        //track_os_intoTaskMsgQueueExt(track_cmd_resetbt, (void*)0);
        track_start_timer(TRACK_CUST_BLE_RESET_TIMER_ID, 5000, track_cmd_resetbt, (void*)0);
    }
    else if(PN == 0x20) //获取电池条形码信息
    {
        bt_rsp_app_03(PN, 0x00);
    }
    else if(PN == 0x21) //查询定位信息
    {
        bt_rsp_app_04(PN, 0x00);
    }
    else if(PN == 0x22) //查询单词里程和总里程信息
    {
        bt_rsp_app_05(PN, 0x00);
    }
}
/*
void track_nf2318_blt_msg(void* msg)
{
    kal_uint8 msglen = 0;
    track_reply_ble_msg_struct *myMsgPtr = (track_reply_ble_msg_struct *)msg;
    msglen = myMsgPtr->reply_data[1];

    LOGD(L_APP, L_V5, "type=%X,msglen=%d", myMsgPtr->reply_data[0], msglen);
    if(msglen != 20)
    {
        LOGD(L_APP, L_V5, "蓝牙数据错误!");
        return;
    }
    if(track_getIsDownLoadFile() == 2)
    {
        return;
    }
    //if(myMsgPtr->reply_data[0])
    {
        track_cust_N07BT_recv1(&myMsgPtr->reply_data[2], msglen);
    }

}*/
void track_bt_cmd_overtime(U8 PN, U8 exe)
{
    bt_rsp_app_01(PN, exe);
}


//把电池20位SN压缩成16位蓝牙发送
void bett_sn_20to16(kal_uint8*data16,kal_uint8*data20)
{
	int i;
	int n =1;
	kal_uint8 tmp;
	data16[0]='$';
	for(i = 0; i < 6; i++)
	{
		tmp = (data20[i]-'A')+1;
        if(tmp>=10)tmp=0;
        data20[i] = tmp;
        if(i%2==1)
        {
            data16[n]=(data20[i-1]<<4)|data20[i];
            n++;
        }
    }
    n = 14;
    for(i=16 ;i<20;i++)
    {
        tmp = data20[i]-48;
        data20[i] = tmp;
        if((i%2) == 1)
        {
            data16[n]=(data20[i-1]<<4)|data20[i];
            n++;
        }
    }
    memcpy(&data16[4],&data20[6],10);
}

/******************************************************************************
 *  Function    -  track_cust_save_device_id_to_bcm
 * 
 *  Purpose     -  发送蓝牙设备号到BCM层
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_save_device_id_to_bcm(void)
{
	kal_uint8 *sendData;
    kal_uint16 size = 22;

	sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        LOGD(L_APP, L_V1, "ERROR: Ram_Alloc");
        return;
    }

    memset(sendData, 0, size);

	sendData[0] = 0x01;//自己加上去区别回复包的
    sendData[1] = 0x02;//自己加上去区别回复包的
    sendData[2] = 0x03;//自己加上去区别回复包的
    sendData[3] = 0x04;//自己加上去区别回复包的
    sendData[4] = 0x05;//自己加上去区别回复包的

	memcpy(&sendData[5],G_importance_parameter_data.device_id,17);
	//LOGH2(L_APP, L_V5, "", sendData, size);
	track_drv_reply_ble(sendData, size);
	
	Ram_Free(sendData);
}

/******************************************************************************
 *  Function    -  track_ble_modify_device_id
 * 
 *  Purpose     -  修改设备ID
 * 
 *  Description -   只有成功，每次下发都覆盖之前的ID
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-18,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
void track_ble_modify_device_id(kal_uint8 *data, kal_uint16 len)
{
	kal_uint8 *sendData;
    kal_uint16 size = 4;

    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        LOGD(L_APP, L_V1, "ERROR: Ram_Alloc");
        return;
    }

    memset(sendData, 0, size);

	sendData[0] = 0x03;//包长度
    sendData[1] = 0x97;//功能号
    sendData[2] = 0x01;//客户说直接覆盖以前的ID
    sendData[3] = 0x98;//校验和

	memcpy(G_importance_parameter_data.device_id,&data[2],len);
	//LOGH2(L_APP, L_V5, "", sendData, size);
	track_drv_reply_ble(sendData, size);	
	tr_start_timer(TRACK_CUST_BT_DEVICE_ID_TIMER_ID, 2000, track_cust_save_device_id_to_bcm);
    Ram_Free(sendData);
}

/******************************************************************************
 *  Function    -  track_ble_user_num_clear
 * 
 *  Purpose     -  蓝牙断开清除用户保存的号码
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-16,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
void track_ble_user_num_clear(char *num)
{
	memcpy(bt_info.new_user_num,num,11);
}

/******************************************************************************
 *  Function    -  track_cust_xyt_pack_app
 *
 *  Purpose     -  APP握手回复包
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-11,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_xyt_pack_app(kal_uint8 app)
{
    kal_uint8 *sendData;
    kal_uint16 size = 4;
    kal_uint8 par = app;

    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        LOGD(L_APP, L_V1, "ERROR: Ram_Alloc");
        return;
    }

    memset(sendData, 0, size);
    sendData[0] = 0x03;//包长度
    sendData[1] = 0x91;//功能号
    if(par == 1)
    {
        sendData[2] = 0x01;//APP状态
        sendData[3] = 0x92;//校验和
    }
    else if(par == 2)
    {
        sendData[2] = 0x02;//APP状态
        sendData[3] = 0x93;//校验和
    }

    LOGH2(L_APP, L_V5, "", sendData, size);
    track_drv_reply_ble(sendData, size);
    Ram_Free(sendData);
}


/******************************************************************************
 *  Function    -  track_cust_xyt_login_app
 *
 *  Purpose     -  注册APP账号回复包
 *
 *  Description - 1 已注册
 *			     2 注册成功
 *			     3 注册失败
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-11,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_xyt_login_app(kal_uint8 *data, kal_uint16 len)
{
    kal_uint8 *sendData;
    kal_uint16 size = 4;
	kal_uint8 num[11]={0};
    int i;

    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        LOGD(L_APP, L_V1, "ERROR: Ram_Alloc");
        return;
    }
    memset(sendData, 0, size);

	memcpy(num,&data[2],11);//APP传过来的电话号码

	if(memcmp(bt_info.phone_num,num,11) == 0 && memcmp(bt_info.new_user_num,num,11) == 0)
	{
		LOGD(L_APP, L_V5, "已注册");
		sendData[0] = 0x03;//包长度
    	sendData[1] = 0x92;//功能号
    	sendData[2] = 0x04;//已注册
        sendData[3] = 0x96;//校验和
	}
	else if(memcmp(bt_info.phone_num,num,11) == 0 && memcmp(bt_info.new_user_num,num,11) != 0)
	{
		LOGD(L_APP, L_V5, "注册成功");
		memcpy(bt_info.new_user_num,num,11);
		LOGH2(L_APP, L_V5, "", bt_info.new_user_num, 11);
		sendData[0] = 0x03;//包长度
    	sendData[1] = 0x92;//功能号
    	sendData[2] = 0x01;//注册成功
        sendData[3] = 0x93;//校验和
	}
	else 
	{
		LOGD(L_APP, L_V5, "注册失败");
		sendData[0] = 0x03;//包长度
    	sendData[1] = 0x92;//功能号
    	sendData[2] = 0x02;//注册失败
        sendData[3] = 0x94;//校验和
	}
	
    LOGH2(L_APP, L_V5, "", sendData, size);
    track_drv_reply_ble(sendData, size);
    Ram_Free(sendData);
}

/******************************************************************************
 *  Function    -  track_cust_xyt_legalize_app
 * 
 *  Purpose     -  APP认证回复包
 * 
 *  Description - app : 1 认证成功
 *			     app : 2 认证失败
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-11,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_xyt_legalize_app(kal_uint8 *data, kal_uint16 len)
{
    kal_uint8 *sendData;
    kal_uint16 size = 4;
	kal_uint8 num[11]={0};

    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        LOGD(L_APP, L_V1, "ERROR: Ram_Alloc");
        return;
    }

    memset(sendData, 0, size);

	memcpy(num,&data[2],11);//APP传过来的电话号码
	
    sendData[0] = 0x03;//包长度
    sendData[1] = 0x93;//功能号

    if(memcmp(bt_info.new_user_num,num,11) == 0)
    {
        sendData[2] = 0x01;//认证成功
        sendData[3] = 0x94;//校验和
    }
    else 
    {
        sendData[2] = 0x02;//认证失败
        sendData[3] = 0x95;//校验和
    }

    LOGH2(L_APP, L_V5, "", sendData, size);
    track_drv_reply_ble(sendData, size);
    Ram_Free(sendData);
}

/******************************************************************************
 *  Function    -  track_cust_xyt_cmd
 * 
 *  Purpose     -  操作命令
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-11,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_xyt_cmd(kal_uint8 cmd[])
{
    kal_uint8 *sendData;
    kal_uint16 size = 7;
  
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        LOGD(L_APP, L_V1, "ERROR: Ram_Alloc");
        return;
    }
    memset(sendData, 0, size);
		
    sendData[0] = 0x06;//包长度
    sendData[1] = 0xB1;//功能号

	if(cmd[2] == 0x01)//车辆开启
	{
		sendData[2] = 0x05;
		sendData[3] = 0x00;
		sendData[4] = 0x00;//预留位
		sendData[5] = 0x00;//预留位
		sendData[6] = 0xB6;//校验和
	}
	else if(cmd[2] == 0x02)//车辆关闭
	{
		sendData[2] = 0x02;
		sendData[3] = 0x00;
		sendData[4] = 0x00;//预留位
		sendData[5] = 0x00;//预留位
		sendData[6] = 0xB3;//校验和
	}
	else if(cmd[2] == 0x04)//撤防
	{
		sendData[2] = 0x04;
		sendData[3] = 0x00;
		sendData[4] = 0x00;//预留位
		sendData[5] = 0x00;//预留位
		sendData[6] = 0xB5;//校验和
	}
	else if(cmd[2] == 0x08)//设防
	{
		sendData[2] = 0x08;
		sendData[3] = 0x00;
		sendData[4] = 0x00;//预留位
		sendData[5] = 0x00;//预留位
		sendData[6] = 0xB9;//校验和
	}
	else if(cmd[3] == 0x02)//寻车
	{
		sendData[2] = 0x00;
		sendData[3] = 0x02;
		sendData[4] = 0x00;//预留位
		sendData[5] = 0x00;//预留位
		sendData[6] = 0xB3;//校验和
	}
	else if(cmd[3]== 0x01)//开坐垫锁
	{
		sendData[2] = 0x00;
		sendData[3] = 0x01;
		sendData[4] = 0x00;//预留位
		sendData[5] = 0x00;//预留位
		sendData[6] = 0xB2;//校验和
	}
		
    LOGH2(L_APP, L_V5, "", sendData, size);
    track_drv_reply_ble(sendData, size);
    Ram_Free(sendData);
}

/******************************************************************************
 *  Function    -  track_cust_xyt_open_lock
 * 
 *  Purpose     -  车辆开启
 * 
 *  Description -   用于区分操作指令，其他地方调用车辆启动功能
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-17,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_xyt_open_lock(kal_uint8 lock)
{
	kal_uint8 *sendData;
    kal_uint16 size = 7;
	kal_uint8 par = lock;
  
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        LOGD(L_APP, L_V1, "ERROR: Ram_Alloc");
        return;
    }
    memset(sendData, 0, size);
		
    sendData[0] = 0x06;//包长度
    sendData[1] = 0xB1;//功能号
    if(par == 1)//车辆开启
    {
		sendData[2] = 0x05;
		sendData[3] = 0x00;
		sendData[4] = 0x00;//预留位
		sendData[5] = 0x00;//预留位
		sendData[6] = 0xB6;//校验和
	}
	else//车辆关闭
	{
		sendData[2] = 0x02;
		sendData[3] = 0x00;
		sendData[4] = 0x00;//预留位
		sendData[5] = 0x00;//预留位
		sendData[6] = 0xB3;//校验和
	}

	LOGH2(L_APP, L_V5, "", sendData, size);
    track_drv_reply_ble(sendData, size);
    Ram_Free(sendData);
}
/******************************************************************************
 *  Function    -  track_cust_xyt_bt_recv1
 *
 *  Purpose     -  收到蓝牙APP的数据包
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-11,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_xyt_bt_recv1(kal_uint8 *data, kal_uint16 len)
{
    kal_uint8 tmp[20];
	U8 exe = 99;
	char num[11] = {0};
	
    memcpy(tmp, data, len);
    LOGH2(L_APP, L_V1, " ", tmp, len);

    if(tmp[1] == 0x81 && len == 4) //APP握手
    {
        LOGD(L_APP, L_V5, "APP握手");
        if(tmp[2] == 0x01 && tmp[3] == 0x82)//APP正常连接
        {
            track_cust_xyt_pack_app(1);
        }
        else if(tmp[2] == 0x02 && tmp[3] == 0x83)//APP共享连接
        {
            track_cust_xyt_pack_app(2);
        }
    }
    else if(tmp[1] == 0x82 && len == 20) //注册APP账号
    {
        LOGD(L_APP, L_V5, "注册APP账户");
        track_cust_xyt_login_app(data,len);
    }
    else if(tmp[1] == 0x83 && len == 20) //APP认证
    {
		LOGD(L_APP, L_V5, "APP认证");
        track_cust_xyt_legalize_app(data,len);
    }
    else if(tmp[1] == 0xA1 && len == 7 && tmp[2] == 0x05) //车辆开启
    {
		LOGD(L_APP, L_V5, "操作命令");
		if((track_cust_get_lease_desired() == 1 || track_is_timer_run(TRACK_CUST_LEASE_ON_PRECONDITION_TIMER_ID)) && track_is_timer_run(TRACK_CUST_ONLINE_COMMAND_RESULT_DELAY_TIMER_ID))
        {
            LOGD(L_APP, L_V5, "---------------->GPRS Open Lock Now !start BlueTooth timer!");
            track_start_timer(TRACK_CUST_BLUETOOTH_COMMAND_RESULT_DELAY_TIMER_ID, 10 * 1000, track_cust_lease_overtimer, (void*)1);
            return;
        }
        if(track_cust_get_lease_desired() == 0)
        {
            LOGD(L_APP, L_V5, "---------------->1 Execute Lease OFF CMD,Do not execute Lease ON CMD[BT]");//这种情况怎么办呢，他妈的我就遇到了，执行开锁的时候，来了关锁我返回
            return;
        }
        if(track_cust_get_lease_desired() == 1)
        {
            LOGD(L_APP, L_V5, "---------------->2 Execute Lease ON CMD,Do not execute Lease ON CMD[BT]");//这种情况怎么办呢，他妈的我就遇到了，执行开锁的时候，来了关锁我返回
            return;
        }
        if(G_parameter.ste_status.lease == 1 && G_realtime_data.defences_status != 1)
        {
            LOGD(L_APP, L_V5, "已经开锁");
			track_cust_xyt_open_lock(1);//车辆开启
        }
        else
        {
			//track_cust_play_amr_ring();//用这个接口直接播放语音
            track_start_timer(TRACK_CUST_BLUETOOTH_COMMAND_RESULT_DELAY_TIMER_ID, 10 * 1000, track_cust_lease_overtimer, (void*)1);
            track_cust_lease_on_precondition((void*)0);
        }
    }
	else if(tmp[1] == 0xA1 && len == 7 && tmp[2] == 0x02)//车辆关闭
	{
		if(track_cust_get_lease_desired() == 0 && track_is_timer_run(TRACK_CUST_ONLINE_COMMAND_RESULT_DELAY_TIMER_ID))
        {
            //网络关锁
            LOGD(L_APP, L_V5, "---------------->5 GPRS Lock Now !start BlueTooth timer![==BT==]");
            track_start_timer(TRACK_CUST_BLUETOOTH_COMMAND_RESULT_DELAY_TIMER_ID, 10 * 1000, track_cust_lease_overtimer, (void*)1);
            return;
        }
        if(track_cust_get_lease_desired() == 1)
        {
            LOGD(L_APP, L_V5, "---------------->3 Execute Lease On CMD,Do not execute Lease OFF CMD[==BT==]");//这种情况怎么办呢，他妈的我就遇到了，执行开锁的时候，来了关锁我返回
            return;
        }
        if(track_cust_get_lease_desired() == 0)
        {
            //正在关锁，又来关锁，抛弃
            LOGD(L_APP, L_V5, "---------------->4 Execute Lease OFF CMD,Do not execute Lease OFF CMD[==BT==]");//这种情况怎么办呢，他妈的我就遇到了，执行开锁的时候，来了关锁我返回
            return;
        }
        //if(G_parameter.ste_status.lease == 0 && G_realtime_data.defences_status != 1)
        //是否关锁成功
        if(G_parameter.ste_status.lease == 0 && G_realtime_data.defences_status != 1 && track_get_lesea_off_sta(99) == 0)
        {
            LOGD(L_APP, L_V5, "已经关锁");
            track_cust_xyt_open_lock(0);//关闭状态
        }
        else
        {
        	if(track_get_lesea_off_sta(99) != 1)
        	{
	        	LOGD(L_APP, L_V5, "蓝牙关锁开始");
	        	//track_get_lesea_off_sta(1);//标志设置为正在进行关锁流程，
	            track_start_timer(TRACK_CUST_BLUETOOTH_COMMAND_RESULT_DELAY_TIMER_ID, 10 * 1000, track_cust_lease_overtimer, (void*)1);
	            exe = track_mode_lease_off(0);
				LOGD(L_APP, L_V5, "关锁exe = %x",exe);
	            if(exe == 0x02)
	            {
	                tr_stop_timer(TRACK_CUST_BLUETOOTH_COMMAND_RESULT_DELAY_TIMER_ID);
	                track_cust_xyt_open_lock(1);//开启状态
	            }
            }
            else
            {
            	LOGD(L_APP, L_V5, "上次关锁流程未完成");
				track_cust_xyt_open_lock(1);//开启状态
            }
        }
	}
	else if(tmp[1] == 0xA1 && len == 7 && tmp[2] == 0x04) //撤防
    {
		LOGD(L_APP, L_V5, "撤防");
        track_mode_disarm();
        track_cust_xyt_cmd(tmp);
    }
	else if(tmp[1] == 0xA1 && len == 7 && tmp[2] == 0x08) //设防
	{
		LOGD(L_APP, L_V5, "设防");
		track_mode_fortify();
		track_cust_xyt_cmd(tmp);
	}
	else if(tmp[1] == 0xA1 && len == 7 && tmp[3] == 0x01) //开坐垫锁
	{
		LOGD(L_APP, L_V5, "开坐垫");
		track_cust_xyt_cmd(tmp);
	}
	else if(len == 11 && tmp[0] == 0x31 && tmp[1] == 0x33 && tmp[2] == 0x31 && tmp[5]== 0x38 && tmp[7]== 0x38 && tmp[10]== 0x38)
	{
		LOGD(L_APP, L_V5, "蓝牙断开");
		track_ble_user_num_clear(num);
	}
	else if(len == 20 && tmp[0] == 0x13 && tmp[1] == 0x87)//修改设备ID
	{
		LOGD(L_APP, L_V5, "设备ID修改");
		track_ble_modify_device_id(data,17);
	}

/*
客户暂时不需要寻车功能
else if(tmp[1] == 0xA1 && len == 7 && tmp[3] == 0x02) //寻车
{
	LOGD(L_APP, L_V5, "寻车");	
	if(track_is_timer_run(TRACK_CUST_TEST_RING_TIMER_ID))
	{
		tr_stop_timer(TRACK_CUST_TEST_RING_TIMER_ID);
	}
	 
	if(track_set_audio_file_play(99))
	{
		return;//不寻车
	}	
	
	track_acc_status((void *)2);//打开电门锁
	track_cust_playtime(3);
	xc_play((void *) 0);

	track_cust_xyt_cmd(tmp);
}
*/	
}


void track_nf2318_blt_msg(void* msg)
{
    kal_uint8 msglen = 0;
    track_reply_ble_msg_struct *myMsgPtr = (track_reply_ble_msg_struct *)msg;
    msglen = myMsgPtr->reply_data[1];

    LOGD(L_APP, L_V5, "type=%X,msglen=%d", myMsgPtr->reply_data[0], msglen);
    if(msglen > 20)
    {
        LOGD(L_APP, L_V5, "蓝牙数据错误!");
        return;
    }

	track_cust_xyt_bt_recv1(&myMsgPtr->reply_data[2], msglen);
}
#endif


