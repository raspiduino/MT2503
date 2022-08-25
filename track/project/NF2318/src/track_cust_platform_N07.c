#if defined(__NF2318__)
/****************************************************************************
***file author: Liujw
***creat date:2017-12-07
***introduction:
****************7号平台协议
****************运用加密 XxTEA加密方式，RSA加密方式，MD5加密方式
****************************************************************************/
#include "track_cust.h"
#include "c_vector.h"
#include "track_fun_XxTEA.h"
#include "track_cust_platform_N07.h"
/****************************************************************************
***宏定义
****************************************************************************/
#define BMS_CMD_NUM 15
#define __PLATFORM_LOG__
/****************************************************************************
***枚举
****************************************************************************/
#if 0
kal_uint8 RSA_LIST[128] =
{
    0xc6, 0x69, 0xa3, 0xc2, 0x79, 0x06, 0x18, 0xae, 0x82, 0xdf, 0xef, 0x07, 0x6e, 0xa6, 0x9f, 0x9d, 0xa2, 0x10,
    0xe5, 0x0d, 0xe6, 0xf0, 0x11, 0x3d, 0xbf, 0x7d, 0x95, 0x3b, 0xb1, 0x2a, 0xab, 0x4b, 0xa7, 0xc4, 0xab, 0xac,
    0xdd, 0x1a, 0x23, 0xa2, 0x01, 0x13, 0x7f, 0x52, 0x68, 0x54, 0xb4, 0x28, 0xee, 0x52, 0x41, 0x66, 0xe1, 0x0c,
    0xd3, 0xfb, 0x2c, 0xc9, 0x79, 0xf1, 0x7c, 0x6d, 0x27, 0x1d, 0x2a, 0x17, 0xdc, 0x8d, 0xe4, 0x77, 0xd0, 0xe3,
    0x1c, 0xb3, 0x37, 0xcb, 0x31, 0x7b, 0x5b, 0xea, 0xf9, 0x1e, 0x06, 0xb8, 0x4e, 0x25, 0x0f, 0xda, 0xdd, 0xb1,
    0xd8, 0xd7, 0xac, 0xfa, 0x1e, 0x7c, 0xdd, 0x51, 0x80, 0x30, 0xa4, 0x04, 0x15, 0x9b, 0x10, 0x3e, 0xba, 0x4a,
    0xa6, 0x08, 0xc7, 0x49, 0x37, 0xcf, 0xf1, 0x60, 0x53, 0x72, 0x13, 0xc7, 0xb5, 0x36, 0xfa, 0x7d, 0x27, 0xdb,
    0x0f, 0x55
};
static kal_uint8 COMMAND_COLLE[] = {"SOFTVERSION;GSM;VBAT;VIN;DEVICESN;DEVICESTATUS;BATVER;BATMANUFACTURE;BATSN;VIBL;\
FREQ;PULSE;DOMAIN;BLEKG;SLEEPT;MAXECUSPEED;DFTOUTPOFFILTERT;DFTLOCKVOICEPLAYT;DIAMETER;ALNICONUM;DFTTIMEOUT;BTNAME;"
                                   };//SWITCHMODESOC ALARMFREQ
#endif

/****************************************************************************
***静态变量
****************************************************************************/
static kal_uint8 NEW_BT_password[16];//20190717,新的蓝牙密码，
static char *publicKey = "10001";
static kal_bool Login_N07PLAT_Success = KAL_FALSE;
kal_uint8 verlen = 12;//版本长度
kal_uint8 verlist[12] = {0}; //版本信息
static kal_uint8 serialNumberStr[11] = {"700000001F"};
static kal_uint8 serialNumberHex[5] = {0x70, 0x00, 0x00, 0x00, 0x1F};
//static char *version = {"1.2.17"};
static kal_uint8 hardwarever[4] = {0x00, 0x02, 0x00, 0x00}; //硬件版本
static kal_uint8 softwarever[4] = {0x10, 0x01, 0x02, 0x00}; //软件版本
static kal_uint8 audioVersion[4] = {0};//临时存储语音版本号

static kal_uint8 reset_type = 0;
static kal_uint16 g_SerialNumber = 0;
static kal_uint8 login_reason = 0x00;//0x00 重启登陆 0x01 链路故障登陆  0x02 域名切换 0x03休眠后登陆 0x04版本更新后登陆
static kal_uint8 msgID[32] = {0};
static float meliage = 0;
static U8 querycmdcount = 0;
static U8 setcmdcount = 0;
static kal_uint8 wifi_info[71];
static kal_uint8 first_login = 0;
static kal_uint8 factoryname[8] = {0x4B, 0x4B, 0x53, 0x00, 0x00, 0x00, 0x00, 0x00}; //厂家名称 KKS
static kal_uint8 h_buf[512] = {0};
static kal_uint16 o_len = 0;
static kal_uint8 serverUTC[9] = {0};
static kal_uint8 Mounteddata[900];//装载数据
static kal_uint16 Mountedlen = 0;
static short sensor_x = 0, sensor_y = 0, sensor_z = 0;
static kal_uint8 currentSpeed = 0;
static kal_bool Get_Last_Position = KAL_FALSE;
//paging指令标志
kal_uint8 instructions_paging_status = 0;
static kal_uint8 msgID2[32]={0};//记录12的MSGID
//缓存三条语音ID
static kal_uint8  down_voice_id[3][3] = {{0},{0},{0}};
static kal_uint8  voice_volume = 0,voice_volume_0=0,voice_volume_1=0,voice_volume_2=0;//缓存中的语音ID对应得音量
static kal_uint8 voice_number_id = 0;
static kal_uint8 play_voice_sta_num_id = 0 ;
//------20191009
//static kal_uint8 lesea_off_test = 0;//0没有关锁动作 1 正在走关锁流程 2 关锁流程走完但是后轮锁失败
//static kal_uint8 lesea_off_test_volume_sta = 0;//连续关锁是否播放语音 0 第一次播放  1已经播放过了  不播放
/***************************************************************************
***局部函数
****************************************************************************/
static kal_uint16 DataPacketEncodeAA(U8 cmdcode, U8 *sendData, kal_uint16 len, kal_uint8 en_type);
void track_cust_N07_paket_8B();
void track_cust_cmd_online_fix_rsp();
controller_data_struct cData_temp = {0};
static void track_cust_authentication();
static void setMD5(void * arg);
U8 track_set_audio_file_play(U8 arg);
void track_cust_voice_list_sort(voice_list_struct ls, kal_uint8 mem);
/*---------2019------------*/
void track_cust_N07_paket_12(kal_uint8 *data, kal_uint8 len, kal_uint8 entype);//20190717
void track_signal_intensity(U8 *sendbuf, track_gps_data_struct *gd);
//void track_get_bt_passwort(kal_uint8 * data);//20190717
void track_cust_N07_paket_92(U8 exeresult,kal_uint8 * id);//20190717
//语音缓存
kal_uint8 voice_sub_down_id(kal_uint8 * data_id,kal_uint8 vol_voice);
kal_uint8 track_get_voice_volume(void);
void Substantiv_voice_id(kal_uint8 voice_sta);
kal_uint8 track_get_voice_numid_sta(void);
kal_uint8 play_sub_voice(kal_uint8 *number_id,kal_uint8  sta);
kal_uint8 track_get_violue_status(kal_uint8 * data);
kal_uint8 track_get_lesea_off_sta(kal_uint8 value);



/****************************************************************************
***全局变量
****************************************************************************/
U8 tokenType = 1;//1 固定token 0 动态token
extern kal_uint8 ota_login;
/***************************************************************************
***引用外部函数
****************************************************************************/
extern track_wifi_struct wifi_status;
extern void track_soc_send(void *par);
extern controller_data_struct cData;
extern void track_cust_playtime(kal_uint16 c);
extern kal_uint8 controller_status;
extern kal_uint16 controller_hall;
extern kal_uint8 track_mode_lease_on(U8 type);
extern kal_uint8 track_mode_lease_off(U8 type);
extern kal_uint8 track_mode_disarm();
extern int track_cust_bms_upload(int param);
extern void track_cust_server_msgid_info(kal_uint8* id);
extern void track_cust_lease_overtimer(void* arg);
extern void track_cust_exbatlock_overtime(void* param);
extern void track_cust_rearwheel_overtime(void* param);
extern kal_uint8 track_bms_data_send(void* arg);
extern void track_cust_test_http(char *filename, kal_uint8 voice_id);
extern void AUDIO_file_delete(U8 par);
extern void HTTP_abnormal_restart_roll_back();
extern void HTTP_web(char *web, kal_uint16 len);
extern void track_cust_set_lease_play_audio(kal_uint8 *src);
extern void track_audio_file_checking(void* arg);
extern void track_cmd_resetbt(void* param);
//--------20190916
extern U8 get_token_type();
extern kal_uint8 track_cust_get_speelt_sta(kal_uint8 value);
extern void speed_voice_play();
/***************************************************************************
****************************************************************************
****************************************************************************/
U8 track_cust_querycmd()
{
    return querycmdcount;
}
void track_cust_set_query_count()//查询的计数
{
    LOGD(L_BMS, L_V1, "");
    querycmdcount = 0;
}
U8 track_cust_setcmd()
{
    return setcmdcount;
}
void track_cust_set_count()//设置的计数
{
    LOGD(L_BMS, L_V1, "");
    setcmdcount = 0;
}

/******************************************************************************
 *  Function    -  track_cust_deviceSN
 *
 *  Purpose     -  设备序列号
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 2017-07-28,  Liujw  written
 * ----------------------------------------
*******************************************************************************/
kal_uint8* track_cust_deviceSN()
{
    return serialNumberHex;
}
static void track_cust_timet(U8 *sendbuf)
{
    kal_uint32 sec = 0;
    sec = OTA_app_getcurrtime();
    track_fun_reverse_32(sendbuf, sec);
}
kal_uint8* get_imei(U8 flag)
{
    static int done = 0;
    static kal_uint8 imei_str[16] = {0};
    static kal_uint8 imei_hex[8] = {0};
    int i = 0, j = 0;
    if(flag == 0) done = 0;
    if(done == 0)
    {
        //imei_str = track_drv_get_imsi(0);
        memcpy(imei_str, track_drv_get_imei(0), 16);
        LOGD(L_DRV, L_V5, "IMEI=%s", imei_str);
        for(i = 0, j = 0; j < 8; i++)
        {
            imei_hex[j++] = ((imei_str[i] & 0x0F) << 4) | (imei_str[i+1] & 0x0F);
            i++;
        }
        imei_hex[7] = imei_hex[7] | 0x0F;
        done = 1;
    }
    return imei_hex;
}
static kal_uint8* get_imsi()
{
    static int done = 0;
    static kal_uint8 imsi_str[16] = {0};
    static kal_uint8 imsi_hex[8] = {0};
    int i = 0, j = 0;
    //imsi_str = track_drv_get_imsi(0);
    if(done == 0)
    {
        memcpy(imsi_str, track_drv_get_imsi(0), 16);
        LOGD(L_DRV, L_V5, "IMSI=%s", imsi_str);
        for(i = 0, j = 0; j < 8; i++)
        {
            imsi_hex[j++] = ((imsi_str[i] & 0x0F) << 4) | (imsi_str[i+1] & 0x0F);
            i++;
        }
        imsi_hex[7] = imsi_hex[7] | 0x0F;
        done = 1;
    }
    return imsi_hex;
}

/******************************************************************************
 *  Function    -  track_cust_reset_type
 *
 *  Purpose     -  重启原因
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 2017-07-31,  Liujw  written
 * ----------------------------------------
*******************************************************************************/
kal_uint8 track_cust_reset_type(enum_reset_type rt)
{
    if(rt != 99)
    {
        reset_type = rt;
    }
    return reset_type;
}
/**
**登陆原因
**/
kal_uint8 track_cust_login(enum_login_reason par)
{
    if(par != 99)
    {
        login_reason = par;
    }
    return login_reason;
}


/******************************************************************************
 *  Function    -  track_cust_fun_module
 *
 *  Purpose     -  终端功能
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 2017-07-31,  Liujw  written
 * ----------------------------------------
*******************************************************************************/
kal_uint8 track_cust_fun_module()
{
    return MOD_BT7 | MOD_WIFI | MOD_EXBAT_LOCK | MOD_LOUDSPEAKER | MOD_SMS_CONTROL | MOD_MESSAGE_COLLECTION;
}
void msl_altitudeHex(kal_uint8* dec, float src)
{
    kal_uint16 tmp = 0;
    tmp = src * 10;
    track_fun_reverse_16(dec, tmp);

}

void track_cust_vehicle_status(kal_uint8 *src)
{
    kal_uint16 tmp = 0;
    kal_uint8 l_tmp = 0, h_tmp = 0;
    kal_uint8 chargein = 0;
    kal_uint8 bt_status[20] = {0};
    kal_uint8 btconn = 0;//蓝牙状态 连接 未连接
    kal_uint8 issleep = 0;//未休眠	01 半休眠 10 全休眠
    kal_uint8 isride = 0;//骑行状态
    kal_uint8 accsta = 0;//acc状态
    kal_uint8 WheelFault = 0;//后轮锁故障
    kal_uint8 ExtBatFault = 0;//电池锁故障
    vehicle_status_struct v_state = {0};
    track_cust_get_controller_data(&v_state);
    if(track_cust_vehicle_moving(7) != 0)
    {
        l_tmp = 1;
    }
    else
    {
        l_tmp = 0;
    }

    if(set_ele_lock)
    {
        l_tmp |= 2;
    }
    else
    {
        l_tmp |= 0;
    }

    if(track_cust_status_acc() == 1)
    {
        accsta = 1;
    }
    else
    {
        accsta = 0;
    }
    l_tmp |= (accsta << 2);

    if(G_realtime_data.sleep == 15)
    {
        issleep = 8;
    }
    else if(G_realtime_data.sleep == 16)
    {
        issleep = 16;
    }
    l_tmp |= issleep;//<< 3;

    OTA_track_ble_bt_status(bt_status);
    btconn = bt_status[1];
    l_tmp |= btconn << 5;

    if(GPIO_ReadIO(14) == 1)
    {
        G_realtime_data.exbatlock = 0;
    }
    else
    {
        G_realtime_data.exbatlock = 1;
    }
    if(G_realtime_data.elelockalarm == 1)
    {
        ExtBatFault = 3;
    }
    else
    {
        ExtBatFault = G_realtime_data.exbatlock;
    }
    l_tmp |= ExtBatFault << 6;
#ifdef __PLATFORM_LOG__
    LOGD(L_BMS, L_V7, "电池中断口%d,%d;后轮中断口%d,%d;真实蓝牙开关:%d", track_GPIO_ReadIO(14), GPIO_ReadIO(14), track_GPIO_ReadIO(2), GPIO_ReadIO(2), bt_status[0]);
    LOGD(L_BMS, L_V7, "终端状态低%02X,运动状态:%d;电机锁状态:%d,ACC状态:%d,睡眠状态:%d;蓝牙连接状态:%d,电池锁状态:%d", l_tmp, track_cust_vehicle_moving(7), set_ele_lock, track_cust_status_acc(), issleep, btconn, G_realtime_data.exbatlock);
#endif
    if(!track_cust_status_acc())
    {
        v_state.ele_sta = 0;
    }
    h_tmp = v_state.ele_sta;

    if(track_cust_status_charger())
    {
        chargein = 1;
    }
    h_tmp |= chargein << 1;

    if(v_state.malfunction == 0)
    {
        h_tmp |= 4;//转把
    }
    if(G_realtime_data.rearwheelalarm == 1 && G_parameter.ste_status.lease == 0)//后轮锁
    {
        WheelFault = 3;
    }
    else
    {
        WheelFault = G_realtime_data.wheel;
    }

    h_tmp |= WheelFault << 3;

#ifdef __PLATFORM_LOG__
    LOGD(L_BMS, L_V7, "终端状态高%02X,骑行状态:%d;外电状态:%d,转把状态:%d,后轮锁状态:%d", h_tmp, v_state.ele_sta, chargein, v_state.malfunction, G_realtime_data.wheel);
#endif
    LOGD(L_BMS, L_V5, "终端状态高0x%02X,低:0x%02X", h_tmp, l_tmp);

    src[0] = h_tmp;
    src[1] = l_tmp;
}
static void track_terminal_signal(U8 *sendbuf, track_gps_data_struct *gd)
{
    kal_uint16 signalStatus = 0;
    kal_uint8 fix = 0, sat = 0;
    kal_uint16 vbat = 0, gsm = 0;
    if(track_cust_gps_status() > 2)
    {
        fix = 1;
    }
    else if(gd->gprmc.status > 0)
    {
        fix = 2;
    }
    if((gd->gpgga.sat + gd->bdgga.sat) > 9)
    {
        sat = 9;
    }
    else
    {
        sat = gd->gpgga.sat + gd->bdgga.sat;
    }
    vbat = track_cust_get_battery_level();
    gsm = track_cust_get_rssi_level();
#ifdef __PLATFORM_LOG__
    //LOGD(L_BMS, L_V7, "信号状态,fix%d;sat:%d,vbat:%d,gsm:%d", fix,sat,vbat,gsm);
#endif
    //计算结果
    sat = sat << 2;
    vbat = vbat << 6;
    gsm = gsm << 10;
    signalStatus = fix | sat | vbat | gsm;
#ifdef __PLATFORM_LOG__
    //LOGD(L_BMS, L_V7, "信号状态2,fix%d;sat:%d,vbat:%d,gsm:%d", fix,sat,vbat,gsm);
#endif
    LOGD(L_BMS, L_V5, "signalStatus:%X", signalStatus);

    track_fun_reverse_16(sendbuf, signalStatus);

}
static void track_project_reverse_32(kal_uint8 *dec, kal_int32 src)
{
    dec[0] = (kal_int8)((src & 0xFF000000) >> 24);
    dec[1] = (kal_int8)((src & 0x00FF0000) >> 16);
    dec[2] = (kal_int8)((src & 0x0000FF00) >> 8);
    dec[3] = (kal_int8)(src & 0x000000FF);
}
static void track_project_LongitudeLatitudeToHex(kal_uint8 *dec, float value, kal_uint8 sw)
{
    kal_int32 tpp;
    kal_uint32 tmp;
    tmp = value * 1800000;

    if(sw == 'S' || sw == 'W')
    {
        tpp = 0 - tmp;
        track_project_reverse_32(dec, tpp);

    }
    else
    {
        track_project_reverse_32(dec, tmp);
    }
}

/******************************************************************************
 *  Function    -  track_gps_data_packet
 *
 *  Purpose     -  GPS数据打包
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 2017-07-31,  Liujw  written
 * ----------------------------------------
*******************************************************************************/
static void track_gps_data_packet(U8 *sendbuf, track_gps_data_struct *gd)
{
    track_project_LongitudeLatitudeToHex(&sendbuf[0], gd->gprmc.Latitude, gd->gprmc.NS);
    track_project_LongitudeLatitudeToHex(&sendbuf[4], gd->gprmc.Longitude, gd->gprmc.EW);
    msl_altitudeHex(&sendbuf[8], gd->gpgga.msl_altitude); //海拔高度
    sendbuf[10] = (kal_uint8)gd->gprmc.Course / 2;
    sendbuf[11] = (kal_uint8)gd->gprmc.Speed;
    track_terminal_signal(&sendbuf[12], gd);
    track_signal_intensity (&sendbuf[14], gd);
}
static void DataPackingLbs_8(U8 *sendbuf, LBS_Multi_Cell_Data_Struct *lbs)
{
    track_fun_reverse_16(&sendbuf[0], lbs->MainCell_Info.mcc);
    sendbuf[2] = (U8)lbs->MainCell_Info.mnc;
    track_fun_reverse_16(&sendbuf[4], lbs->MainCell_Info.lac);
    track_fun_reverse_16(&sendbuf[6], lbs->MainCell_Info.cell_id);
}
kal_uint8 track_wifi_information()
{
    //kal_uint8 mac[6];
    int i = 0, j = 0;
    kal_uint8 sum = wifi_status.wifi_sum;
    if(sum > 3) sum = 3;
    wifi_info[j++] = sum;
    LOGD(L_BMS, L_V5, "xxxxxxxxxxxsum=%d", sum);
    if(sum != 0)
    {
        for(i = 0; i < sum; i++)
        {
            memcpy(&wifi_info[j], track_fun_stringtohex(wifi_status.wifi_mac[i], 6), 6);
            j += 6;
            wifi_info[j] = wifi_status.wifi_rssi[i];
            j++;
        }

        sum = sum * 7 + 1;
    }
    LOGH(L_APP, L_V5, wifi_info, sum);
    return sum;
}
void track_cust_str_to_hex()
{
    char sn_tmp[12];
    kal_uint8 sn_data[5];
    int i = 0, j = 0;
    sprintf(sn_tmp, "%sF", G_importance_parameter_data.SequenceNumber);
    LOGD(L_APP, L_V5, "%s", sn_tmp);
    for(i = 0; i < 5; i++)
    {
        if('A' <= sn_tmp[j] && sn_tmp[j] <= 'F')
        {
            serialNumberHex[i] = sn_tmp[j++] - 'A' + 10;
        }
        else if('0' <= sn_tmp[j] && sn_tmp[j] <= '9')
        {
            serialNumberHex[i] = sn_tmp[j++] - '0';
        }
        serialNumberHex[i] = serialNumberHex[i] << 4;
        if('A' <= sn_tmp[j] && sn_tmp[j] <= 'F')
        {
            serialNumberHex[i] |= sn_tmp[j++] - 'A' + 10;
        }
        else if('0' <= sn_tmp[j] && sn_tmp[j] <= '9')
        {
            serialNumberHex[i] |= sn_tmp[j++] - '0';
        }
    }
    LOGH(L_APP, L_V5, serialNumberHex, 5);
}
static kal_uint8 get_firmware_version_list()
{
    memcpy(verlist, hardwarever, 4);//硬件版本
    memcpy(&verlist[4], softwarever, 4);//软件版本
    memcpy(&verlist[8], G_parameter.voice_ver, 4);
    return 12;
}
/******************************************************************************
 *  Function    -  track_cust_get_version
 *
 *  Purpose     -  版本号
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 2017-08-01,  Liujw  written
 * ----------------------------------------
*******************************************************************************/
kal_uint8 track_cust_get_version()
{
    //int firstver = 8,secondver = 14;

    return 0x01;//(firstver << 4)|secondver;//新版改为01

}
static kal_uint16 getSerialNumber()
{
    if(g_SerialNumber >= 255)
        g_SerialNumber = 1;
    else
        g_SerialNumber ++;
    return g_SerialNumber;
}
static int BCD_TO_NUM(kal_uint8 *src, char* dec)
{
    char tt[15] = {0};
    int i = 0, j = 0;
    kal_uint8 tmp[11];
    kal_uint8 num1 = 0, num2  = 0;
    for(i = 0; i < 10; i++)
    {
        num1 = (src[i] & 0xF0) >> 4;
        num2 = src[i] & 0x0F;
        if(num1 != 0x0F)
        {
            j += sprintf(tt + j, "%c", (num1 + '0'));
        }
        else break;
        if(num2 != 0x0F)
        {
            j += sprintf(tt + j, "%c", (num2 + '0'));
        }
        else break;
    }
    j += sprintf(tt + j, "\0");
    sprintf(dec, "%s", tt);
    LOGD(L_BMS, L_V5, "%d,%s", j, tt);
    return j;
}

static void track_fun_NUM_to_BCD(char* Src, kal_uint8 *Dec)
{
    int i = 0, j = 0;
    kal_uint8 BCD[10];
    LOGD(L_BMS, L_V4, "%s", Src);
    for(i = 0; i < 10; i++)
    {
        //LOGD(L_BMS, L_V4, "%x", (Src[j]-'0'));
        if(Src[j] == 'F')
        {
            BCD[i] = ((Src[j++] - 'A' + 10) << 4); // |(Src[j++]-'0');
        }
        else
        {
            BCD[i] = ((Src[j++] - '0') << 4); // |(Src[j++]-'0');
        }
        if(Src[j] == 'F')
        {
            BCD[i] = BCD[i] | (Src[j++] - 'A' + 10);
        }
        else
        {
            BCD[i] = BCD[i] | (Src[j++] - '0');
        }
    }
    memcpy(Dec, BCD, 10);
}
kal_uint8 bms_soh()
{
    kal_uint16 tmp = 0;
    float tmp2 = 0;
    float tmp1  = 0;
    kal_uint8 result = 0;
    tmp = (cData_temp.leftCapatiryH & 0x00FF) << 8 | cData_temp.leftCapatiryL;
    //LOGD(L_APP, L_V5, "tmp:0x%04X,0x%02X,0x%02X,0x%02X", tmp,cData_temp.relativeCapacityPer,cData_temp.absoluteFullCapacity[0],cData_temp.absoluteFullCapacity[1]);
    tmp1 = (float)tmp / (float)cData_temp.relativeCapacityPer;
    tmp2 = (float)((cData_temp.absoluteFullCapacity[0] & 0x00FF) << 8 | cData_temp.absoluteFullCapacity[1]) * 1.00;
#ifdef __PLATFORM_LOG__
    //LOGD(L_APP, L_V5, "tmp1:%f,tmp2:%f",tmp1,tmp2);//0x%04X
#endif
    result = (tmp1 * 100 / tmp2) * 100;
    return result;
}
//void track_cust_clear_speed()
//{
//	currentSpeed = 0;
//}
void track_cust_clear_meliage()
{
    meliage  = 0;
}
/*
V=N*π*D*2/6n;
*/
kal_uint8 get_speed(void)
{
    static int multipleT = 1;
    kal_uint8 speed = 0;
    float tmp = 0.0;
    float diameter = (float)G_parameter.ste_param.diameter;
    float alnicounum = (float)G_parameter.ste_param.alnicounum;

    tmp = controller_hall * 3.1415926 * diameter * 2.0 * 0.0254;
    //LOGD(L_BMS, L_V1, "瞬时速度temp:%02f", tmp);
    tmp = tmp / (6.0 * alnicounum);
    meliage += tmp * 0.5;
    if(G_parameter.ele_data.oncemileage == 0)
    {
        multipleT = 1;
    }
    if(meliage >= 200 || (tmp == 0 && meliage > 0))
    {
        G_parameter.ele_data.oncemileage += meliage;
        G_parameter.ele_data.totalmileage += meliage;
        if(G_parameter.ele_data.oncemileage >= (3000 * multipleT))
        {
            Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
            multipleT += 1;
        }
        meliage = 0;
    }
    tmp = tmp * 3.6;
    //LOGD(L_BMS, L_V1, "瞬时速度1:%02f", tmp);
    speed = tmp;
    currentSpeed = speed;
    LOGD(L_DRV, L_V6, "瞬时速度:%d,%d,里程:%f,%d,%02f", speed, currentSpeed, meliage, G_parameter.ele_data.oncemileage, tmp);
    return speed;
}

/**
**Author:Liujw Date:2017/12/9
**命令数据段打包,将数据段进行XxTEA加密
**加密方式：0x00 XxTEA,0x01 AES,0x02 RSA ,0xFF 明文
**执行结果 0x00 成功;0x01 失败;0x02 报文错误;0x03 参数错误 ;0xFF 未知错误
**/
static kal_uint8 xxTEA_K[16] = {0};//{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}; //实际为云平台回复认证报文包里的数据，加上设备序列号做MD5

static void CommandDataSection(kal_uint8* loaddata, kal_uint16 len, U8 exe, U8 cmdcode, kal_uint8 packet_type, kal_uint8 en_type)
{
    U8 *p_data = NULL;
    kal_uint16 tempLength = 0;
    int encryptLength = 0;

    if(len > 500)
    {
        LOGD(L_BMS, L_V1, "测试数据超长:%d", len);
        return;
    }
    if(serialNumberHex[0] == 0x70 && serialNumberHex[1] == 0x00 && serialNumberHex[2] == 0x00 && serialNumberHex[3] == 0x00 && serialNumberHex[4] == 0x1F)
    {
        LOGD(L_APP, L_V1, "******MESSAGE:SN invalid2******");
        return;
    }
    p_data = (U8*)Ram_Alloc(5, 640);
    if(p_data == NULL)
    {
        LOGD(L_DRV, L_V1, "申请内存出错");
        return;
    }
    memset(p_data, 0, 640);
    p_data[0] = getSerialNumber();
    p_data[1] = exe;//执行结果
    track_cust_timet(&p_data[2]);
    p_data[6] = packet_type;//数据类型 0 实时，1 缓存
    p_data[7] = 0x00;
    memcpy(&p_data[8], loaddata, len);

    tempLength = 8 + len;
    if(G_parameter.ste_status.encode_type == 1)
    {
        en_type = 0xFF;
    }
    LOGH2(L_BMS, L_V7, "", p_data, tempLength);

    if(en_type == 0x00)
    {
        sg_xxtea_set_key(G_parameter.ste_param.TEA_KEY);
        encryptLength = sg_xxtea_encrypt(p_data, tempLength);
    }
    else
    {
        encryptLength = tempLength;
    }
    //LOGH2(L_BMS, L_V5, "", p_data, encryptLength);

    DataPacketEncodeAA(cmdcode, p_data, encryptLength, en_type);
    Ram_Free(p_data);
}


/******************************************************************************
 *  Function    -  DataPacketEncodeAA
 *
 *  Purpose     -  AA协议打包
 *
 *  Description -
				0x00 XxTEA 加密方式
				0x01 AES 加密
				0x02 RSA 加密
				0xFF 当采用明文的传输的时候使用
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 2017-07-28,  Liujw  written
 *2019-5-22 Liujw modify,保留位改为修订版本号位，改成0x00[动态蓝牙token] 0x01[固定蓝牙token]
 * 客户要求改成固定token仅限蓝牙连接
 * ----------------------------------------
*******************************************************************************/
static kal_uint16 DataPacketEncodeAA(U8 cmdcode, U8 *sendData, kal_uint16 len, kal_uint8 en_type)
{
    U16 tmp;
    U8 *p1_Data = NULL;
    kal_uint32 no = 0;

    if(len + 12 > 672)
    {
        LOGD(L_APP, L_V1, "数据长度超过512,返回！！len:%d,entype:%d,cmdcode:%d", len, en_type, cmdcode);
        return 0;
    }
    p1_Data = (U8*)Ram_Alloc(5, 672);
    if(p1_Data == NULL)
    {
        LOGD(L_APP, L_V1, "申请内存出错");
        return 0;
    }
    memset(p1_Data, 0, 672);
    //LOGD(L_APP, L_V5, "");
    //起始位
    p1_Data[0] = 0xAA;
    p1_Data[1] = 0xBB;

    //长度
    len += 10;
    p1_Data[2] = (len & 0xFF00) >> 8;
    p1_Data[3] = len & 0x00FF;

    //版本号
    p1_Data[4] = track_cust_get_version();

    //报文码命令码
    p1_Data[5] = cmdcode;
    //加密方式
    p1_Data[6] = en_type;//加密方式

    //保留 修订版本号
    p1_Data[7] = tokenType;

    //命令数据
    memcpy(&p1_Data[8], sendData, len);

    //CRC校验
    tmp = GetCrc16(&p1_Data[2], len - 4);
    p1_Data[len - 2] = (tmp & 0xFF00) >> 8;
    p1_Data[len - 1] = (tmp & 0x00FF);

    //return tmp;
    no = p1_Data[9];
    LOGH2(L_BMS, L_V6, "", p1_Data, len);

    if(cmdcode == 0x00 || cmdcode == 0x01  || cmdcode == 0x03  || cmdcode == 0x0A  || cmdcode == 0x8B || cmdcode == 0x92)// || cmdcode == 0x0E || cmdcode == 0x0F )
    {
        track_soc_write_req(p1_Data, len, cmdcode, no);
    }
    else if(cmdcode == 0x05)
    {
        //track_soc_write_req(data, len, 0x13, no);
        Socket_write_req(0, p1_Data, len, 4, 0x13, no, 1);
    }
    else if(cmdcode == 0x02)
    {
        track_socket_queue_position_send_reg(p1_Data, len, cmdcode, no);
    }
    else if(cmdcode == 0x86 || cmdcode == 0x87 || cmdcode == 0x88 || cmdcode == 0x8C || cmdcode == 0x0E || cmdcode == 0x0F)
    {
        track_socket_queue_send_netcmd_reg(p1_Data, len, cmdcode, no);
    }
    else if(cmdcode == 0x04)
    {
        track_socket_queue_alarm_send_reg(p1_Data, len, cmdcode, no);
    }
    else
    {
        ;
    }
    Ram_Free(p1_Data);
    return 1;
#if 0
    0x01 执行失败。
    0x02 报文错误。
    0x03 参数错误。
    0xFF 未知错误。
#endif
}
static void CommandDataSection1(kal_uint8* loaddata, kal_uint16 len, U8 exe, U8 cmdcode, kal_uint8 packet_type, kal_uint8 en_type)
{
    U8 *p_data = NULL;
    kal_uint16 templength = 0;
    int encryptLength = 0;
    if(len > 500)
    {
        LOGD(L_BMS, L_V1, "测试数据超长:%d", len);
        return;
    }
    if(serialNumberHex[0] == 0x70 && serialNumberHex[1] == 0x00 && serialNumberHex[2] == 0x00 && serialNumberHex[3] == 0x00 && serialNumberHex[4] == 0x1F)
    {
        LOGD(L_APP, L_V1, "******MESSAGE:SN invalid3******");
        return;
    }
    p_data = (U8*)Ram_Alloc(5, 640);
    if(p_data == NULL)
    {
        LOGD(L_DRV, L_V1, "申请内存出错");
        return;
    }
    memset(p_data, 0, 640);
    //LOGD(L_BMS, L_V7, "%d", cmdcode);
    p_data[0] = getSerialNumber();
    p_data[1] = exe;//执行结果
    track_cust_timet(&p_data[2]);
    p_data[6] = packet_type;//数据类型 0 实时，1 缓存
    p_data[7] = 0x00;
    memcpy(&p_data[8], loaddata, len);

    templength = 8 + len;
    if(G_parameter.ste_status.encode_type == 1)
    {
        en_type = 0xFF;
    }
    encryptLength = templength;
#ifdef __PLATFORM_LOG__
    LOGH2(L_BMS, L_V6, "", p_data, encryptLength);
#endif
    LOGD(L_APP, L_V5, "--------------> encryptLength len = %d ",encryptLength);

    DataPacketEncodeAA(cmdcode, p_data, encryptLength, en_type);
    Ram_Free(p_data);
}
kal_uint16 DataPacketEncodeAA_repacket(U8 cmdcode, U8 *sendData, kal_uint16 len, kal_uint8 en_type, kal_uint8 packet_type, kal_uint8 *outbuff)
{
    U16 tmp;
    //kal_uint8 data[1000];
    U8 *p_data = NULL;
    kal_uint32 no = 0;

    int enlen = 0;

    if(len > 700)
    {
        LOGD(L_APP, L_V1, "数据长度超过700,返回！！len:%d,entype:%d,cmdcode:%d", len, en_type, cmdcode);
        return 0;
    }

    p_data = (U8*)Ram_Alloc(5, 1024);
    if(p_data == NULL)
    {
        return 0;
    }
    //LOGD(L_BMS, L_V5, "cmdcode:%d,en_type:%d,ptype:%d",cmdcode,en_type,packet_type);

    LOGH2(L_BMS, L_V6, "", sendData, len);
    memset(p_data, 0, 1024);
    memset(Mounteddata, 0, 900);
    //起始位
    p_data[0] = 0xAA;
    p_data[1] = 0xBB;

    //长度
    //len += 10;
    p_data[2] = 0;//(len & 0xFF00) >> 8;
    p_data[3] = 0;//len & 0x00FF;

    //版本号
    p_data[4] = sendData[4];//track_cust_get_version();

    //报文码命令码
    p_data[5] = cmdcode;
    //加密方式
    p_data[6] = en_type;//加密方式

    //保留 //修订版本号
    p_data[7] = tokenType;
    //定位包和报警包在这里备份
    Mountedlen = len - 10;
    memcpy(Mounteddata, &sendData[8], Mountedlen);

    Mounteddata[6] = packet_type;
    if(G_parameter.ste_status.encode_type == 0)
    {
        sg_xxtea_set_key(G_parameter.ste_param.TEA_KEY);
        enlen = sg_xxtea_encrypt(Mounteddata, Mountedlen);
    }
    else
    {
        enlen = Mountedlen;
        p_data[6] = 0xFF;
    }
    //命令数据
    memcpy(&p_data[8], Mounteddata, enlen);
    enlen = enlen + 10;
    p_data[2] = (enlen & 0xFF00) >> 8;
    p_data[3] = enlen & 0x00FF;

    //CRC校验
    tmp = GetCrc16(&p_data[2], enlen - 4);
    p_data[enlen - 2] = (tmp & 0xFF00) >> 8;
    p_data[enlen - 1] = (tmp & 0x00FF);

    //return tmp;
    no = p_data[9];

#ifdef __PLATFORM_LOG__
    LOGH2(L_BMS, L_V5, "", p_data, enlen);
#endif

    memcpy(outbuff, p_data, enlen);
    memset(Mounteddata, 0, 900);
    Mountedlen = 0;
    Ram_Free(p_data);
    return enlen;
#if 0
    0x01 执行失败。
    0x02 报文错误。
    0x03 参数错误。
    0xFF 未知错误。
#endif
}

/**
**Author:Liujw Date:2017/12/7
**Description:认证报文，终端需要有云端的公钥，用云端的公钥加密自己的公钥的数字签名
**云端有私钥和终端的公钥
**终端把云端公钥加密后的数字签名上传给云端
**终端收到云端的回复，用云端的公钥验证回复中的数字签名来判断是否是合法的云端
**尼玛好绕口啊
**/


static textMD5(kal_uint8 *data, kal_uint8 *outdata, kal_uint32 len)
{
    applib_md5_ctx md5_ctx;
    U8 hash_result[16] = {0};

    OTA_applib_md5_init(&md5_ctx);
    OTA_applib_md5_update(&md5_ctx, (kal_uint8 *)data, len);
    OTA_applib_md5_final(hash_result, &md5_ctx);
    memcpy(outdata, hash_result, 16);
}
static void setMD5(void * arg)
{
    kal_uint8 first = 0;
    kal_uint8 par = (kal_uint8)arg;
    if(par == 0)
    {
        first = 0;
        //return;
    }
    if(first == 0)
    {
        textMD5(serverUTC, xxTEA_K, 9);
        memcpy(G_parameter.ste_param.TEA_KEY, xxTEA_K, 16);
        //Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
        LOGD(L_APP, L_V9, "获得服务器UTC时间%X,%X,%X,%X,%X,%X,%X,%X,%X", serverUTC[0], serverUTC[1], serverUTC[2], serverUTC[3]\
             , serverUTC[4], serverUTC[5], serverUTC[6], serverUTC[7], serverUTC[8]);
        first = 1;
    }

}
void track_cust_NO7_packet_00_encode_msg(kal_uint8 *data, int len, kal_uint8 isEncode)
{
    DataPacketEncodeAA(0x00, data, len, isEncode);
}
/**
**Author:Liujw Date:2017/12/8
**Description:打包设备序列号
**/
void track_cust_n07_packet_00(void)
{
    U8 *authenData = NULL;
    kal_uint8 DeviceID[5];
    int size  = 0;
    size = 13;
    if(serialNumberHex[0] == 0x70 && serialNumberHex[1] == 0x00 && serialNumberHex[2] == 0x00 && serialNumberHex[3] == 0x00 && serialNumberHex[4] == 0x1F)
    {
        LOGD(L_APP, L_V1, "******MESSAGE:SN invalid1******");
        return;
    }
    authenData = (U8*)Ram_Alloc(5, size);
    memcpy(DeviceID, serialNumberHex, 5);
    LOGH(L_APP, L_V5, serialNumberHex, 5);
    //CommandDataSection(DeviceID, 5, 0xFF, 0x00, 0x00, 0x02);//0x02
    if(authenData == NULL)
    {
        LOGD(L_DRV, L_V1, "申请内存出错");
        return;
    }
    memset(authenData, 0, size);
    authenData[0] = getSerialNumber();
    authenData[1] = 0xFF;//执行结果
    track_cust_timet(&authenData[2]);
    authenData[6] = 0;//数据类型 0 实时，1 缓存
    authenData[7] = 0x00;
    memcpy(&authenData[8], serialNumberHex, 5);
    if(G_parameter.ste_status.encode_type == 0)//加密
    {
        RSA_data_handle_req(size, authenData, 1);
    }
    else
    {
        track_cust_NO7_packet_00_encode_msg(authenData, size, 0xFF);
    }
    Ram_Free(authenData);
}
/******************************************************************************
 *  Function    -  track_cust_no7_paket_01
 *
 *  Purpose     -  登陆包
 *
 *  Description -  track_cust_no7_paket_01
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-28,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/

void track_cust_no7_paket_01()
{
    kal_uint8 *sendData = NULL;
    kal_uint8 i = 0;
    int size = 0;

    verlen = get_firmware_version_list();
    size = 5 + 1 + 8 + 8 + 1 + 8 + verlen;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    //setMD5((void*)1);
    //序列号
    memcpy(&sendData[i], track_cust_deviceSN(), 5);
    i += 5;
    //登陆原因
    sendData[i] = track_cust_login(99);
    i += 1;
    //IMSI
    memcpy(&sendData[i], get_imsi(), 8);
    i += 8;
    //IMEI
    memcpy(&sendData[i], get_imei(1), 8);
    i += 8;
    //终端功能
    //sendData[i] = track_cust_fun_module();
    //i+=1;
    //厂商ID
    sendData[i] = 0x00;
    i++;
    //厂家编码
    memcpy(&sendData[i], factoryname, 8);
    i += 8;

    memcpy(&sendData[i], verlist, verlen);
    i += verlen;

    //LOGD(L_APP, L_V5, "%d", i);
#ifdef __PLATFORM_LOG__
    //LOGH2(L_BMS, L_V5, "", sendData, i);
#endif
    CommandDataSection(sendData, size, 0xFF, 0x01, 0x00, 0x00);
    Ram_Free(sendData);
}
/**
**服务器返回包，带UTC密钥
**/
static U8 track_cust_N07_80(kal_uint8 *data, kal_uint16 len, kal_uint8 entype)
{
    kal_uint8 outdata[256];
    //kal_uint8 serverUTC[9];
    kal_uint8 outlen;
    static int counts = 0;
    long timestamp = 0;
    applib_time_struct result = {0};

    LOGH2(L_APP, L_V5, "", data, len);
    if(entype == 0xFF)
    {
        if(len == 128)
        {
            //新的密钥
            memcpy(G_parameter.ste_param.publickey, data, 128);
            Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
            track_cust_keycontent_init();
            return 0;
        }
        else
        {
            if(data[1] != 0x00)
            {
                LOGD(L_APP, L_V5, "认证报文回复失败,%02X", data[1]);
                return 0;
            }
            memset(serverUTC, 0, 9);
            memcpy(serverUTC, serialNumberHex, 5);
            memcpy(&serverUTC[5], &data[2], 4);
            setMD5((void*)0);
            timestamp = ((data[2] & 0x000000FF) << 24) | ((data[3] & 0x000000FF) << 16) | ((data[4] & 0x000000FF) << 8) | data[5];
            applib_dt_utc_sec_2_mytime(timestamp, &result, 0);
            LOGD(L_APP, L_V5, "服务器日期:%d-%02d-%02d,时间:%02d:%02d:%02d", result.nYear, result.nMonth, result.nDay, result.nHour, result.nMin, result.nSec);
            track_fun_update_time_to_system(2, (applib_time_struct *)(&result));
            return 1;
        }
    }
    else
    {
        RSA_data_handle_req(len, data, 0);
        //counts ++;
    }
    LOGD(L_APP, L_V7, "次数累计,%d", counts);
    return 2;
}
void track_cust_n07_C0(kal_uint8 *data, int len)
{
    ;
#if 0  //该函数以前做RSA密钥更新的，新协议中去掉
    kal_uint8 tempkey[256] = {0};
    memcpy(tempkey, &data[8], 128);
    LOGH2(L_APP, L_V5, "", tempkey, 128);
    memcpy(G_parameter.ste_param.publickey, tempkey, 128);

    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
#endif
}


/******************************************************************************
 *  Function    -  track_cust_N07_paket_02
 *
 *  Purpose     -  定位数据包
 *
 *  Description -  track_cust_N07_paket_02
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-28,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/

void track_cust_N07_paket_02(track_gps_data_struct *gd, LBS_Multi_Cell_Data_Struct *lbs)
{
    kal_uint8 *sendData = NULL;

    int size, i = 0;
    kal_uint8 wifilen = 0;
    kal_uint32 exVBAT = 0;

    wifilen = track_wifi_information();
    if(wifilen == 0)
    {
        //size = 5 + 14 + 8 + 21 + 1 + 1; //
        size = 5 + 24 + 8 + 21 + 1 + 1;
    }
    else
    {
        //size = 5 + 14 + 8 + 21 + wifilen + 1; //
        size = 5 + 24 + 8 + 21 + wifilen + 1;
    }
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    track_bms_struct_copy(&cData_temp);
    memset(sendData, 0, size);

    //序列号
    memcpy(&sendData[i], track_cust_deviceSN(), 5);
    i += 5;

    //GPS信息
    track_gps_data_packet(&sendData[i], gd);
    i += 24;
    //LBS 基站信息
    DataPackingLbs_8(&sendData[i], lbs);
    i += 8;
    // 相对SOC
    sendData[i++] = cData_temp.relativeCapacityPer;
    //可用剩余流量
    sendData[i++] = cData_temp.leftCapatiryH;
    sendData[i++] = cData_temp.leftCapatiryL;
    //SOH 预留
    sendData[i++] = bms_soh();

    //LOGD(L_BMS, L_V5, "SOH=%d", sendData[i-1]);
    //骑行电流
    sendData[i++] = cData_temp.currentH;
    sendData[i++] = cData_temp.currentL;
    //控制器温度
#if 0
    if(cData_temp.temperature[0] == 0 && cData_temp.temperature[1] == 0)
    {
        sendData[i++] = 0;
    }
    else
    {
        sendData[i++] = (((cData_temp.temperature[0] << 8) | cData_temp.temperature[1]) - 2731) / 10;
    }
#else
    sendData[i++] = cData_temp.temperature[0];
    sendData[i++] = cData_temp.temperature[1];
#endif
    if(cData_temp.totalValtage[0] == 0 && cData_temp.totalValtage[1] == 0)
    {
        //exVBAT = track_cust_get_ext_volt();
        exVBAT = (float)track_cust_get_ext_volt() / 1000.0;
        LOGD(L_BMS, L_V5, "电池电压3:%d", exVBAT);

        sendData[i] = exVBAT >> 8;
        i += 1;
        sendData[i] = exVBAT & 0x00FF;
        i += 1;
    }
    else
    {
        //电瓶电压
        memcpy(&sendData[i], &cData_temp.totalValtage[0], 2);
        i += 2;
    }
    //总里程
    track_fun_reverse_32(&sendData[i], G_parameter.ele_data.totalmileage);
    i += 4;
    //单次里程数
    track_fun_reverse_32(&sendData[i], G_parameter.ele_data.oncemileage);
    i += 4;
    //霍尔速度
    sendData[i++] = 0x00;
    sendData[i++] = currentSpeed;//get_speed();
    //车辆状态
    track_cust_vehicle_status(&sendData[i]);
    i += 2;
    if(wifilen == 0)
    {
        sendData[i++] = 0x00;//wifi
    }
    else
    {
        memcpy(&sendData[i], wifi_info, wifilen);
        i += wifilen;
    }

    CommandDataSection1(sendData, size, 0xFF, 0x02, 0x00, 0x00);

    Ram_Free(sendData);
}
void bms_sigle_battery_voltage(kal_uint8 *buf, U8 param)
{
    int i = 0, j = 1;
    if(param == 1)
    {
        for(i = 0; i < 14; i += 2)
        {
            buf[i+1] = cData_temp.valtage[j-1];
            buf[i] = cData_temp.valtage[j];
            j += 2;
        }
    }
    else
    {
        j = 15;
        for(i = 0; i < 14; i += 2)
        {
            buf[i+1] = cData_temp.valtage[j-1];
            buf[i] = cData_temp.valtage[j];
            j += 2;
        }
    }
    LOGH(L_APP, L_V5, buf, 14);
}

/******************************************************************************
 *  Function    -  track_cust_N07_paket_03
 *
 *  Purpose     -  电池状态数据包
 *
 *  Description -  track_cust_N07_paket_03
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-28,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/

void track_cust_N07_paket_03()
{
    kal_uint8 *sendData = NULL;

    int size, i = 0;
	//return;

    size = 5 + 1 + 2 + 1 + 2 + 1 + 2 + 2 + 2 + 2 + 14 + 14 + 2 + 2 + 20/*16*/ + 2 + 16;

    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);
    track_bms_struct_copy(&cData_temp);

    //序列号
    memcpy(&sendData[i], track_cust_deviceSN(), 5);
    i += 5;

    //相对SOC
    sendData[i++] = cData_temp.relativeCapacityPer;
    //可用剩余流量
    sendData[i++] = cData_temp.leftCapatiryH;
    sendData[i++] = cData_temp.leftCapatiryL;
    //绝对SOC
    sendData[i++] = cData_temp.absoluteCapacityPer;
    //绝对满电电容
    sendData[i++] = cData_temp.absoluteFullCapacity[0];
    sendData[i++] = cData_temp.absoluteFullCapacity[1];
    //相对SOH
    sendData[i++] = bms_soh();

    //LOGD(L_BMS, L_V5, "SOH=%d", sendData[i-1]);
    //内部温度
    sendData[i++] = cData_temp.temperature[0];
    sendData[i++] = cData_temp.temperature[1];
    //实时电流
    sendData[i++] = cData_temp.currentH;
    sendData[i++] = cData_temp.currentL;
    //电压
    sendData[i++] = cData_temp.totalValtage[0];
    sendData[i++] = cData_temp.totalValtage[1];
    //循环次数
    sendData[i++] = cData_temp.circulationOfBat[0];
    sendData[i++] = cData_temp.circulationOfBat[1];
    //1-7节电池电压
    bms_sigle_battery_voltage(&sendData[i], 1);
    i += 14;
    //8-14节电池电压
    bms_sigle_battery_voltage(&sendData[i], 2);
    i += 14;
    //当前充电间隔时间
    sendData[i++] = cData_temp.chargeInterval[0];
    sendData[i++] = cData_temp.chargeInterval[1];
    //最大充电间隔时间
    sendData[i++] = cData_temp.largeChargeInterval[0];
    sendData[i++] = cData_temp.largeChargeInterval[1];
    //读写成品条形码
    memcpy(&sendData[i], &cData_temp.barCode[0], 20);
    i += 20;
    //读版本号
    sendData[i++] = cData_temp.versionNum[0];
    sendData[i++] = cData_temp.versionNum[1];
    //电池组制造厂名称
    memcpy(&sendData[i], &cData_temp.valtageManufacturer[0], 16);
    i += 16;

#ifdef __PLATFORM_LOG__
    LOGD(L_BMS, L_V5, "电池数据:%d,%d", i, size);
#endif
    CommandDataSection(sendData, size, 0xFF, 0x03, 0x00, 0x00);

    Ram_Free(sendData);
}

/******************************************************************************
 *  Function    -  track_cust_N07_paket_04
 *
 *  Purpose     -  告警数据包
 *
 *  Description -  track_cust_N07_paket_04
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-28,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_N07_paket_04(kal_uint8 alarm_type, kal_uint8 alarm_status)
{
    kal_uint8 *sendData = NULL;

    int size, i = 0;
    kal_uint16 g_sensor = 0;
    float tmp_sensor = 0;

    size = 9;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);

    //序列号
    memcpy(&sendData[i], track_cust_deviceSN(), 5);
    i += 5;
    LOGD(L_BMS, L_V5, "告警类型:%d,%d", alarm_type, alarm_status);
    //告警类型
    sendData[i++] = alarm_type;
    //告警状态
    sendData[i++] = alarm_status;//0x01 产生告警 0x00 告警消失
    //告警内容 ，故障告警填写控制器数据  ，震动告警，填写g_sensor 数据mg，其他默认0
    if(alarm_type == ALARM_VEHICLE_FAULT)//车辆故障告警
    {
        sendData[i++] = controller_status | 0x7C;
        sendData[i++] = 0x00;
    }
    else if(alarm_type == ALARM_VIB)
    {
        if(sensor_x > sensor_y && sensor_x > sensor_z) g_sensor = sensor_x;
        if(sensor_y > sensor_x && sensor_y > sensor_z) g_sensor = sensor_y;
        if(sensor_z > sensor_y && sensor_z > sensor_x) g_sensor = sensor_z;
        tmp_sensor = (float)g_sensor * 1.024;
        g_sensor = tmp_sensor;
        if(g_sensor == 0) g_sensor = 30;
        sendData[i++] = (g_sensor & 0xFF00) >> 8;
        sendData[i++] = g_sensor & 0x00FF;
    }
    else
    {
        sendData[i++] = 0x00;
        sendData[i++] = 0x00;
    }
    CommandDataSection1(sendData, size, 0xFF, 0x04, 0x00, 0x00);
    Ram_Free(sendData);
}

/******************************************************************************
 *  Function    -  track_cust_N07_paket_05
 *
 *  Purpose     -  心跳包
 *
 *  Description -  track_cust_N07_paket_05
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-28,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/

void track_cust_N07_paket_05()
{
    kal_uint8 *sendData = NULL;

    int size;
    kal_uint8 i = 0;
    kal_uint32 exVBAT = 0;
    track_gps_data_struct *gd = track_drv_get_gps_data();

    size = 14;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);
    track_bms_struct_copy(&cData_temp);

    //序列号
    memcpy(&sendData[i], track_cust_deviceSN(), 5);
    i += 5;
    //信号状态
    track_terminal_signal(&sendData[i], gd);
    i += 2;
    //车辆状态
    //sendData[i] = 0x00;
    track_cust_vehicle_status(&sendData[i]);
    i += 2;
    //电瓶电压
    if(cData_temp.totalValtage[0] == 0 && cData_temp.totalValtage[1] == 0)
    {
        //exVBAT = track_cust_get_ext_volt();
        exVBAT = (float)track_cust_get_ext_volt() / 1000.0;
        LOGD(L_BMS, L_V5, "电池电压1:%d", exVBAT);
        sendData[i] = exVBAT >> 8;
        i += 1;
        sendData[i] = exVBAT & 0x00FF;
        i += 1;
    }
    else
    {
        LOGD(L_BMS, L_V5, "电池电压2:%d,%d", cData_temp.totalValtage[0], cData_temp.totalValtage[1]);
        sendData[i] = cData_temp.totalValtage[0];
        i += 1;
        sendData[i] = cData_temp.totalValtage[1];
        i += 1;
    }
    //相对SOC
    sendData[i] = cData_temp.relativeCapacityPer;
    i += 1;
    //可用剩余流量
    sendData[i] = cData_temp.leftCapatiryH;
    i += 1;
    sendData[i] = cData_temp.leftCapatiryL;
    i += 1;
    if(track_soc_login_status())
    {
        CommandDataSection(sendData, size, 0xFF, 0x05, 0x00, 0x00);
    }
    Ram_Free(sendData);
}

/******************************************************************************
 *  Function    -  track_cust_no7_paket_06
 *
 *  Purpose     -  远程控制数据包（服务器下发）
 *
 *  Description -  track_cust_no7_paket_06
 *	result=0 执行成功	result=1 执行失败
 *
 * modification history
 * modify by Liujw 20190823
 * 对于同时收到同一个操作的开锁或者关锁指令，保存MGSID，等到第一条执行完毕后，同时回复结果
 * ----------------------------------------
 * v1.0  , 2017-07-28,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_N07_paket_06(kal_uint8 *data, kal_uint8 len, kal_uint8 entype, kal_uint16 execode)
{
    int declen = 0;
    kal_uint8 cmd_type = 0;
    kal_uint16 playtimes = 0;
    U8 result = 1, exresult = 0, playResult = 0;
    kal_uint8 voice_ID[3];
    //kal_uint8 msgID[32];
    if(track_getIsDownLoadFile() == 2)
    {
        return;
    }
    if(execode == 0)
    {
        if(entype == 0xFF)
        {
            declen = len;
        }
        else
        {
            sg_xxtea_set_key(G_parameter.ste_param.TEA_KEY);
            declen = sg_xxtea_decrypt(data, len, 0);
        }
        if(declen > 128)
        {
            //大于128个字节，认为加密秘钥失效错误
            LOGD(L_APP, L_V1, "Warning!!!,Length error");
            return;
        }
        LOGH(L_BMS, L_V5, data, declen);
        if((declen - 8) < 36)
        {
            LOGD(L_APP, L_V1, "Warning!!!,The length of this command is error!,Attention please");
            return;
        }
        cmd_type = data[8];
        memcpy(voice_ID, &data[9], 3);
        //voice_ID[0] = 0x00;
        //voice_ID[1] = 0x04;
        //voice_ID[2] = 0x03;
        //LOGD(L_APP, L_V5, "VOICEID=%02X,%02X,%02X", voice_ID[0], voice_ID[1], voice_ID[2]);
        memcpy(msgID, &data[12], 32);
        //LOGH2(L_APP,L_V5, "MSGID=", msgID, 32);
        if(cmd_type == 0x02 || cmd_type == 0x03 || cmd_type == 0x05 || cmd_type == 0x09 || cmd_type == 0x0A || cmd_type == 0x0B || cmd_type == 0x01 || cmd_type == 0x0D || cmd_type == 0x0F || cmd_type == 0x10 || cmd_type == 0x11 || cmd_type == 0x16 || cmd_type == 0x17)
        {
            tr_start_timer(TRACK_CUST_ONLINE_CMD_FIX_TIMER_ID, 2000, track_cust_cmd_online_fix_rsp);
        }
    }

    LOGD(L_APP, L_V5, "cmd_type:%d,execode:%d,VOICEID=%02X,%02X,%02X", cmd_type, execode, voice_ID[0], voice_ID[1], voice_ID[2]);
    if(cmd_type == 0x02 || execode == 302)
    {
        //车辆撤防
        track_mode_disarm();
        result = 0x00;
    }
    else if(cmd_type == 0x03)
    {
        //远程重启
        track_cust_restart(2, 20);
        result = 0x00;
    }
    else if(cmd_type == 0x05)
    {
        //恢复出厂设置
        track_factory();
        result = 0x00;
    }
    else if(cmd_type == 0x08)
    {
        //立即定位
        track_cust_N07_paket_02(track_drv_get_gps_data(), track_drv_get_lbs_data());
        result = 0x00;
    }
    else if(cmd_type == 0x09  || execode == 307)
    {
        //寻车
        if(1)//(G_parameter.ste_status.lease == 0)
        {
            //playtimes = G_parameter.ste_param.xctime / 5;
            if(track_set_audio_file_play(99))return;//不寻车
            track_acc_status((void *)2);
            track_cust_playtime(1);
            xc_play((void *) 0);
            result = 0x00;
        }
        else
        {
            result = 0x01;
        }
    }
    else if(cmd_type == 0x0A)
    {
        //重启蓝牙模块
        extern void track_cmd_resetbt(void * param);
        track_cmd_resetbt((void*)0);
        result = 0x00;
    }
    else if(cmd_type == 0x11  || execode == 308)
    {
        //关闭寻车
        if(track_is_timer_run(TRACK_CUST_TEST_RING_TIMER_ID))
        {
            tr_stop_timer(TRACK_CUST_TEST_RING_TIMER_ID);
            if(G_parameter.ste_status.lease == 0 || G_realtime_data.defences_status == 1)
            {
                track_acc_status((void *)0);
            }
            result = 0x00;
        }
    }
    else if(cmd_type == 0x0B || execode == 301)
    {
        //车辆开启
        if((track_cust_get_lease_desired() == 1 || track_is_timer_run(TRACK_CUST_LEASE_ON_PRECONDITION_TIMER_ID)) && track_is_timer_run(TRACK_CUST_BLUETOOTH_COMMAND_RESULT_DELAY_TIMER_ID))//标明已经在处理开锁
        {
            LOGD(L_APP, L_V5, "---------------->BT Open Lock Now !Record MsgID and VoiceID,start online timer!");
            track_cust_set_lease_play_audio(voice_ID);
            track_start_timer(TRACK_CUST_ONLINE_COMMAND_RESULT_DELAY_TIMER_ID, 10 * 1000, track_cust_lease_overtimer, (void*)0);
            track_cust_server_msgid_info(msgID);
            return;
        }
        if(track_cust_get_lease_desired() == 0)
        {
            //这是一种过滤，不要在开锁状态下有关锁动作，保证流程顺利执行，遇到这种情况，不要操作了
            if(execode == 0)
                track_cust_no7_paket_86(0x01, 0x01, msgID); //执行之后，返回服务器
            else
                track_cust_sms_command(1);
            LOGD(L_APP, L_V5, "---------------->1 Execute Lease OFF CMD,Do not execute Lease ON CMD[==GPRS==]");//这种情况怎么办呢，他妈的我就遇到了，执行开锁的时候，来了关锁我返回
            return;
        }
        if(track_cust_get_lease_desired() == 1)
        {
            //这是一种过滤，在正在执行网络开锁的情况下又收到开锁直接返回
            track_cust_server_msgid_info_tmp(msgID);
            LOGD(L_APP, L_V5, "---------------->2 Execute Lease ON CMD,Do not execute Lease ON CMD[==GPRS==]");//这种情况怎么办呢，他妈的我就遇到了，执行开锁的时候，来了关锁我返回
            return;
        }
        if(G_parameter.ste_status.lease == 1 && G_realtime_data.defences_status != 1)
        {
            LOGD(L_APP, L_V5, "已经开锁，直接返回状态00");
            if(execode == 0)
                track_cust_no7_paket_86(0x00, 0x00, msgID); //执行之后，返回服务器
            else
                track_cust_sms_command(0);
            return;
        }
        track_cust_set_lease_play_audio(voice_ID);
        track_start_timer(TRACK_CUST_ONLINE_COMMAND_RESULT_DELAY_TIMER_ID, 10 * 1000, track_cust_lease_overtimer, (void*)0);
        track_cust_server_msgid_info(msgID);

        track_cust_lease_on_precondition((void*)1);
    }
    else if(cmd_type == 0x01 || execode == 304)
    {
        //车辆关闭
        if(track_cust_get_lease_desired() == 0 && track_is_timer_run(TRACK_CUST_BLUETOOTH_COMMAND_RESULT_DELAY_TIMER_ID))
        {
            ///蓝牙在关锁
            LOGD(L_APP, L_V5, "---------------->5 Execute Lease OFF From BT,Do not execute Lease OFF CMD[GPRS]");
            track_cust_set_lease_play_audio(voice_ID);
            track_cust_server_msgid_info(msgID);
            track_start_timer(TRACK_CUST_ONLINE_COMMAND_RESULT_DELAY_TIMER_ID, 10 * 1000, track_cust_lease_overtimer, (void*)0);
            return;
        }
        if(track_cust_get_lease_desired() == 1)
        {
            LOGD(L_APP, L_V5, "---------------->3 Execute Lease On CMD,Do not execute Lease OFF CMD[GPRS]");//这种情况怎么办呢，他妈的我就遇到了，执行开锁的时候，来了关锁我返回
            if(execode == 0)
                track_cust_no7_paket_86(0x01, 0x02, msgID); //执行之后，返回服务器
            else
                track_cust_sms_command(0);
            return;
        }
        if(track_cust_get_lease_desired() == 0)
        {
            //正在执行关锁，直接不理
            track_cust_server_msgid_info_tmp(msgID);
            LOGD(L_APP, L_V5, "---------------->4 Execute Lease OFF CMD,Do not execute Lease OFF CMD[GPRS]");//这种情况怎么办呢，他妈的我就遇到了，执行开锁的时候，来了关锁我返回
            return;
        }
        if(G_parameter.ste_status.lease == 0 && G_realtime_data.defences_status != 1)
        {
        #if 0
            LOGD(L_APP, L_V5, "已经关锁，直接返回状态00");
            if(execode == 0)
                track_cust_no7_paket_86(0x00, 0x00, NULL); //执行之后，返回服务器
            else
                track_cust_sms_command(0);
            return;
        #endif
        	if(track_get_lesea_off_sta(99) == 0)
        	{
				LOGD(L_APP, L_V5, "已经关锁，直接返回状态00");
            	if(execode == 0)
                	track_cust_no7_paket_86(0x00, 0x00, NULL); //执行之后，返回服务器
            	else
                	track_cust_sms_command(0);
            	return;
        	}
        }
        //-------------------
        if(track_get_lesea_off_sta(99) == 1)
        {
			LOGD(L_APP, L_V5, "上次关锁流程还没完成，直接返回状态00");
            if(execode == 0)
                track_cust_no7_paket_86(0x01, 0x01, NULL); //上次关锁流程未结束，直接返回失败
            else
                track_cust_sms_command(0);
            return;
        }
        //track_get_lesea_off_sta(1);
        //-------------
        track_start_timer(TRACK_CUST_ONLINE_COMMAND_RESULT_DELAY_TIMER_ID, 10 * 1000, track_cust_lease_overtimer, (void*)0);
        track_cust_server_msgid_info(msgID);
        track_cust_set_lease_play_audio(voice_ID);
        result = track_mode_lease_off(0);

        LOGD(L_APP, L_V5, "1result:%d", result);

        if(result == 0x02)
        {
            tr_stop_timer(TRACK_CUST_ONLINE_COMMAND_RESULT_DELAY_TIMER_ID);
            exresult = 1;
            if(track_get_code() == 1)
            {
                track_cust_sms_command(result);
            }
            else
            {
                track_cust_no7_paket_86(exresult, result, msgID);
            }
        }
        else
        {
            result = (result == 1) ? 0 : 1;
        }
        LOGD(L_APP, L_V5, "result:%d", result);
    }
    else if(cmd_type == 0x0D)
    {
        //查询电池终端信息
        track_cust_N07_paket_03();

        exresult = 0x00;
        if(!track_cust_status_charger())
        {
            result = 0x03;
        }
    }
    else if(cmd_type == 0x0F || execode == 305)
    {
        //打开电池锁

        LOGD(L_APP, L_V5, "当前电池锁状态:%d", G_realtime_data.exbatlock);
        if(G_realtime_data.exbatlock == 0)
        {
            result = 0x00;
            if(track_get_code() == 1)
                track_cust_sms_command(result);
            else
                track_cust_no7_paket_86(result, result, NULL);

        }
        else
        {
            track_cust_server_msgid_info(msgID);
            track_start_timer(TRACK_CUST_ONLINE_ELELOCK_DELAY_TIMER_ID, 5 * 1000, track_cust_exbatlock_overtime, (void *)2);
            track_cust_ele_on_gpio((void*)1);
        }
        return;
    }
    else if(cmd_type == 0x10 || execode == 306)
    {
        //关闭电池锁
        if(G_realtime_data.exbatlock == 1)
        {
            result = 0x00;
            if(track_get_code() == 1)
                track_cust_sms_command(result);
            else
                track_cust_no7_paket_86(result, result, NULL);
            return;
        }
        else
        {
            track_cust_server_msgid_info(msgID);
            track_start_timer(TRACK_CUST_ONLINE_ELELOCK_DELAY_TIMER_ID, 5 * 1000, track_cust_exbatlock_overtime, (void *)3);
            track_cust_ele_off_gpio((void*)1);

        }
        return;
    }
    else if(cmd_type == 0x16 || execode == 343)
    {
        //打开后轮涨闸锁

        LOGD(L_APP, L_V5, "wheel:%d,%d", G_realtime_data.wheel, GPIO_ReadIO(2));
        if(G_realtime_data.wheel == 0)
        {
            if(track_get_code() == 1)
                track_cust_sms_command(0);
            else
                track_cust_no7_paket_86(0x00, 0x00, NULL);
        }
        else
        {
            track_cust_server_msgid_info(msgID);
            track_start_timer(TRACK_CUST_ONLINE_REARLOCK_DELAY_TIMER_ID, 5 * 1000, track_cust_rearwheel_overtime, (void *)2);
            track_cust_gate_off_gpio((void*)1);
        }
        return;
    }
    else if(cmd_type == 0x17 || execode == 344)
    {
        //关闭后轮涨闸锁

        LOGD(L_APP, L_V5, "wheel:%d,%d", G_realtime_data.wheel, GPIO_ReadIO(2));
       // if((track_cust_vehicle_moving(11) & 6) == 0)
       if(track_cust_vehicle_moving(46) == 0)
        {
            if(G_realtime_data.wheel == 1)
            {
                if(track_get_code() == 1)
                    track_cust_sms_command(0);
                else
                    track_cust_no7_paket_86(0x00, 0x00, NULL);
            }
            else
            {
                track_cust_server_msgid_info(msgID);
                if(track_cust_not_wheel_lock() == 1)
                {
                    track_cust_rearwheel_overtime((void *)3);
                    return;
                }
                track_start_timer(TRACK_CUST_ONLINE_REARLOCK_DELAY_TIMER_ID, 5 * 1000, track_cust_rearwheel_overtime, (void *)3);
                track_cust_gate_on_gpio((void*)1);
            }
        }
        else
        {
            if(track_get_code() == 1)
                track_cust_sms_command(1);
            else
                track_cust_no7_paket_86(0x01, 0x01, NULL);
        }
        return;
    }
    if(cmd_type != 0x0B && cmd_type != 0x01 && execode != 301 && execode != 304)
    {
        if(execode == 0)
        {
            if(result == 0x03)
            {
                track_cust_no7_paket_86(exresult, result, NULL); //执行之后，返回服务器
            }
            else
            {
                track_cust_no7_paket_86(result, result, NULL); //执行之后，返回服务器
            }
        }
        else
        {
            track_cust_sms_command(result);
        }

        if(voice_ID[0] != 0 || voice_ID[1] != 0 || voice_ID[2] != 0)
        {
            /*track_set_audio_file_play(1);
            playResult = AUDIO_file_play(voice_ID);
            if(playResult == 1)
                track_set_audio_file_play(0);
                */
            voice_sub_down_id(voice_ID,0x0E);
        }
    }

}
static void track_N07_query_cmd(kal_uint8 *data, kal_uint16 len)
{
    char *p = NULL, *q = NULL;
    kal_uint8 stamp[4] = {0x07, 0x00, 0x00, 0x01};
    kal_uint8 cmddata[50] = {0};
    kal_uint8 cmdlen = 0;
    memset(msgID, 0, 32);//保存服务器信息ID
    memcpy(msgID, &data[len-32], 32);
    q = strstr(data, "=");
    if(q != NULL)
    {
        //memset(msgID, 0, 32);
        track_cust_N07_paket_87(data, 0);
        return;
    }
    p = strstr(data, ";");
    do
    {
        if(p != NULL)
        {
            querycmdcount++ ;
            strncpy(p, "#", 1);
            cmdlen = p - data;
            memset(cmddata, 0, 50);
            if(cmdlen <= 50)
            {
                memcpy(cmddata, data, cmdlen);
            }
            //begin 放到这里检查是否还有指令
            data = p + 1;
            p = NULL;
            p = strstr(data, ";");
            if(p == NULL)
            {
                querycmdcount = 254;
            }
            //end
            if(cmdlen < CM_PARAM_LONG_LEN_MAX - 2)
            {
                CMD_DATA_STRUCT cmd = {0};
                cmd.return_sms.cm_type = CMD_ONLINE_NF2318;
                cmd.rcv_length = cmdlen;
                if(cmdlen > 50)
                {
                    LOGD(L_BMS, L_V1, "N07 cmdlen > 50");
                    if(p == NULL)
                    {
                        cmd.rcv_length = 11;
                        memset(cmddata, 0, 50);
                        sprintf(cmddata, "NORMALINFO#");
                    }
                    else
                    {
                        continue;
                    }
                }
                memcpy(cmd.return_sms.stamp, stamp, 4);
                strcpy(cmd.rcv_msg, cmddata);
                track_command_operate(&cmd);
            }
        }
        else
        {
            LOGD(L_BMS, L_V6, "没有找到分隔符;");
        }

    }
    while(p != NULL);
}
static void track_N08_set_cmd(kal_uint8 *data, kal_uint16 len)
{
    char *p = NULL;//,*q = NULL;
    kal_uint8 stamp[4] = {0x07, 0x00, 0x00, 0x02};
    kal_uint8 cmddata[50] = {0};
    kal_uint8 cmdlen = 0;
    memset(msgID, 0, 32);//保存服务器信息ID
    memcpy(msgID, &data[len-32], 32);
    p = strstr(data, ";");

    do
    {
        if(p != NULL)
        {
            setcmdcount ++;
            strncpy(p, "#", 1);
            cmdlen = p - data;
            memset(cmddata, 0, 50);
            if(cmdlen <= 50)
            {
                memcpy(cmddata, data, cmdlen);
            }
            //begin 放到这里检查是否还有指令
            data = p + 1;
            p = NULL;
            p = strstr(data, ";");
            if(p == NULL)
            {
                setcmdcount = 254;
            }
            if(cmdlen < CM_PARAM_LONG_LEN_MAX - 2)
            {
                CMD_DATA_STRUCT cmd = {0};
                cmd.return_sms.cm_type = CMD_ONLINE_NF2318;
                cmd.rcv_length = cmdlen;
                if(cmdlen > 50)
                {
                    LOGD(L_BMS, L_V1, "N08 cmdlen > 50");
                    if(p == NULL)
                    {
                        cmd.rcv_length = 13;
                        memset(cmddata, 0, 50);
                        sprintf(cmddata, "NORMALINFO=1#");
                    }
                    else
                    {
                        continue;
                    }
                }
                memcpy(cmd.return_sms.stamp, stamp, 4);
                strcpy(cmd.rcv_msg, cmddata);
                track_command_operate(&cmd);
            }
        }
        else
        {
            LOGD(L_BMS, L_V6, "没有找到分隔符;");
        }
    }
    while(p != NULL);
}

/******************************************************************************
 *  Function    -  track_cust_N07_packet_07
 *
 *  Purpose     -  远程查询参数（服务器下发）
 *
 *  Description -  track_cust_N07_packet_07
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-28,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_N07_packet_07(kal_uint8 *data, kal_int16 len, kal_uint8 entype)
{
    int declen = 0;
    kal_uint8 cmd_type = 0;
    if(entype == 0xFF)
    {
        declen = len;
    }
    else
    {
        sg_xxtea_set_key(G_parameter.ste_param.TEA_KEY);
        declen = sg_xxtea_decrypt(data, len, 0);
    }
    LOGH(L_APP, L_V5, data, declen);
    //LOGD(L_APP, L_V5,"%s", data);
    querycmdcount = 0;
    track_cmd_set_attr();
    track_N07_query_cmd(&data[8], declen - 8);
}
/******************************************************************************
 *  Function    -  track_cust_N07_paket_08
 *
 *  Purpose     -  远程设置参数（服务器下发）
 *
 *  Description -  track_cust_N07_paket_08
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-28,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_N07_paket_08(kal_uint8 *data, kal_uint16 len, kal_uint8 entype)
{
    int declen = 0;
    kal_uint8 cmd_type = 0;
    if(entype == 0xFF)
    {
        declen = len;
    }
    else
    {
        sg_xxtea_set_key(G_parameter.ste_param.TEA_KEY);
        declen = sg_xxtea_decrypt(data, len, 0);
    }
    LOGH(L_APP, L_V5, data, declen);
    setcmdcount = 0;
    track_cmd_set_attr();
    track_N08_set_cmd(&data[8], declen - 8);
}
#if 0
/******************************************************************************
 *  Function    -  track_cust_no7_paket_09
 *
 *  Purpose     -  远程查询设置（服务器下发）
 *
 *  Description -  track_cust_no7_paket_09
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-28,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/

void track_cust_no7_paket_09()
{
    kal_uint8 *sendData;
    kal_uint16 no, zone;
    int size, ver, i;

    size = 10 + 5 + 4 + 2;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);

    //序列号
    i = 10;
    memcpy(sendData[i], track_cust_deviceSN(), 5);
    i += 5;
    //同步参数时间戳
    track_cust_timet(&sendData[i]);
    i += 4;

    no = DataPacketEncodeAA(0x09, sendData, i);

    track_soc_write_req(sendData, size, 1, no);

    Ram_Free(sendData);
}
#endif
/******************************************************************************
 *  Function    -  track_cust_N07_paket_0A
 *
 *  Purpose     -  远程查询设置（服务器下发）
 *
 *  Description -  track_cust_N07_paket_0A
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-28,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/

void track_cust_N07_paket_0A(kal_uint8 *Telnumber, kal_uint8 Telength, kal_uint8 *message, kal_uint16 messageLen)
{
    kal_uint8 *sendData = NULL;
    int size = 0, i = 0;

    size = Telength + messageLen + 5;

    //LOGD(L_BMS, L_V5, "%d,号码%d", Telength,messageLen);
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);

    //序列号
    memcpy(sendData, track_cust_deviceSN(), 5);
    i += 5;
    //短信发送者号码
    memcpy(&sendData[i], Telnumber, Telength);
    i += Telength;
    //短信内容
    memcpy(&sendData[i], message, messageLen);
    i += messageLen;
    LOGD(L_BMS, L_V5, "长度:%d", i);

    CommandDataSection(sendData, size, 0xFF, 0x0A, 0x00, 0x00);
    Ram_Free(sendData);
}

/******************************************************************************
 *  Function    -  track_cust_N07_paket_0B
 *
 *  Purpose     -  后台短信转发（服务器下发）
 *
 *  Description -  track_cust_N07_paket_0B
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-28,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/


void track_cust_N07_paket_0B(kal_uint8 *msg, kal_uint16 msglen, kal_uint8 entype)
{
    kal_uint8 telephone[10];
    char telnum[25];
    int temlen = 0;
    int len = 0;
    kal_uint8 cmd_type = 0;
    kal_uint8 smsptr[1024];
    kal_uint8 smstmp[1024];
    if(entype == 0xFF)
    {
        len = msglen;
    }
    else
    {
        sg_xxtea_set_key(G_parameter.ste_param.TEA_KEY);
        len = sg_xxtea_decrypt(msg, msglen, 0);
    }

    LOGH(L_BMS, L_V5, msg, len);
    memcpy(telephone, &msg[8], 10);
    temlen = BCD_TO_NUM(telephone, telnum);
    temlen = len - 18;
    memcpy(smsptr, &msg[18], temlen);

    LOGH(L_BMS, L_V5, smsptr, temlen);
    len = track_fun_UTF8_to_UCS(smsptr, temlen, smstmp, 1024);
    track_cust_sms_send(0, telnum, KAL_FALSE, smstmp, len);

    track_cust_N07_paket_8B();
}
#if 0
void checkmsg(kal_uint8 *msg, kal_uint16 msglen)
{
    kal_uint8 telephone[10];
    char telnum[25];
    int temlen = 0;
    int len = 0;
    kal_uint8 cmd_type = 0;
    kal_uint8 smsptr[1024];
    kal_uint8 smstmp[1024];

    len = msglen;
    LOGH(L_BMS, L_V5, msg, len);
    memcpy(telephone, &msg[8], 10);
    temlen = BCD_TO_NUM(telephone, telnum);
    temlen = len - 18;
    memcpy(smsptr, &msg[18], temlen);

    LOGH(L_BMS, L_V5, smsptr, temlen);
    len = track_fun_UTF8_to_UCS(smsptr, temlen, smstmp, 1024);
    track_cust_sms_send(0, telnum, KAL_FALSE, smstmp, len);

    track_cust_N07_paket_8B();

}
#endif
/******************************************************************************
 *  Function    -  track_cust_N07_paket_0C
 *
 *  Purpose     -  远程语音数据包（服务器下发）
 *
 *  Description -  track_cust_N07_paket_0C
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-28,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/

void track_cust_N07_paket_0C(kal_uint8 *data, kal_uint8 len, kal_uint8 entype)
{
    U8 exe = 0;
    int voiceid = 0;
    int declen = 0;
    kal_uint8 voice_vol = 0;//语音音量
    kal_uint8 cmd_type[3];
    kal_uint16 playtimes = 0;
    //kal_uint8 msgID[32];
    if(entype == 0xFF)
    {
        declen = len;
    }
    else
    {
        sg_xxtea_set_key(G_parameter.ste_param.TEA_KEY);
        declen = sg_xxtea_decrypt(data, len, 0);
    }
    LOGH(L_APP, L_V5, data, declen);
    memcpy(cmd_type, &data[8], 3);
    //memcpy(msgID, &data[11], 32);
    voice_vol = data[11];
    memcpy(msgID, &data[12], 32);
    //LOGD(L_APP,L_V5, "VOICEID=%02X,%02X,%02X", cmd_type[0],cmd_type[1],cmd_type[2]);
    //LOGH2(L_APP,L_V5, "MSGID=", msgID, 32);
    if(cmd_type[0] == 0x00 && cmd_type[1] == 0x00 && cmd_type[2] == 0x01)
    {
        voiceid = 2;//开锁成功
    }
    else if(cmd_type[0] == 0x00 && cmd_type[1] == 0x00 && cmd_type[2] == 0x02)
    {
        voiceid = 6;//开锁成功
    }
    else if(cmd_type[0] == 0x00 && cmd_type[1] == 0x00 && cmd_type[2] == 0x03)
    {
        voiceid = 7;//前方没有指定停车点了
    }
    else if(cmd_type[0] == 0x00 && cmd_type[1] == 0x00 && cmd_type[2] == 0x04)
    {
        voiceid = 8;//偷车报警
    }
    else if(cmd_type[0] == 0x00 && cmd_type[1] == 0x00 && cmd_type[2] == 0x05)
    {
        voiceid = 1;//偷车报警
    }
    else if(cmd_type[0] == 0x00 && cmd_type[1] == 0x00 && cmd_type[2] == 0x06)
    {
        voiceid = 11;//锁车成功
    }
    else if(cmd_type[0] == 0x00 && cmd_type[1] == 0x00 && cmd_type[2] == 0x07)
    {
        voiceid = 9;//限行区域提醒
    }
    else if(cmd_type[0] == 0x00 && cmd_type[1] == 0x00 && cmd_type[2] == 0x08)
        {}
    else if(cmd_type[0] == 0x00 && cmd_type[1] == 0x00 && cmd_type[2] == 0x09)
    {
        voiceid = 10;
    }
    else if(cmd_type[0] == 0x00 && cmd_type[1] == 0x00 && cmd_type[2] == 0x0A)
    {
        voiceid = 3;
    }
    else if(cmd_type[0] == 0x00 && cmd_type[1] == 0x00 && cmd_type[2] == 0x0B)
    {
        voiceid = 4;
    }
    else if(cmd_type[0] == 0x00 && cmd_type[1] == 0x00 && cmd_type[2] == 0x0C)
    {
        voiceid = 5;
    }
    else if(cmd_type[0] == 0x00 && cmd_type[1] == 0x00 && cmd_type[2] == 0x0D)
    {
        voiceid = 12;
    }
    if(voiceid > 0)
    {
        //track_set_audio_file_play(1);
        play_voice(voiceid);
        //
    	track_cust_no7_paket_8C(cmd_type, exe);
    }
    /*else
    {
        exe = 1;
        track_set_audio_file_play(1);
        exe = AUDIO_file_play(cmd_type);
        if(exe == 1)
            track_set_audio_file_play(0);
    }
    track_cust_no7_paket_8C(cmd_type, exe);
    */
    else
    {
    	LOGD(L_APP, L_V5, "---------->>volume : %d",voice_vol);
    	if(voice_vol < 0 || voice_vol > 100)
    	{
    		exe = 1;
			track_cust_no7_paket_8C(cmd_type, exe);
			return;
    	}
    	else if(voice_vol != 0)
    	{
			voice_vol = (voice_vol /10) + 1;
			if(voice_vol > 6)
			{
				voice_vol = 6;
			}
    	}
		exe = voice_sub_down_id(cmd_type,voice_vol);
		if(exe == 1)//满了三条
		{
			track_cust_no7_paket_8C(cmd_type, exe);
		}
    }
}
/******************************************************************************
 *  Function    -  track_cust_N07_paket_0E
 *
 *  Purpose     -  远程语音数据包（服务器下发）
 *
 *  Description -  track_cust_N07_paket_0E
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-28,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_N07_paket_0E()
{
    kal_uint8 *sendData = NULL;

    int size, i = 0;

    size = 6;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);

    //序列号
    memcpy(&sendData[i], track_cust_deviceSN(), 5);
    i += 5;
    sendData[i++] = 0x00;//语音编号
    CommandDataSection1(sendData, size, 0xFF, 0x0E, 0x00, 0x00);
    Ram_Free(sendData);
}
/******************************************************************************
 *  Function    -  track_cust_N07_paket_0F
 *
 *  Purpose     -  获取HTTP现在服务器地址
 *
 *  Description -  track_cust_N07_paket_0F
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-28,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_N07_paket_0F(kal_uint8 *data, kal_uint8 style, kal_uint8 len)
{
    kal_uint8 *sendData = NULL;

    int size, i = 0;

    //size = 6 + len;
    size = 9 + len;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);

    //序列号
    memcpy(&sendData[i], track_cust_deviceSN(), 5);
    i += 5;
    //20190723硬件版本号
    memcpy(&sendData[i],&hardwarever[1],3);
    i += 3;
    sendData[i++] = style;//语音编号
    //if(style == 0x00)
    if(style == 0x30)
    {
        LOGD(L_APP, L_V5, "请求语音");
    }
    //else//(style == 0x01)
    else if(style >=0x10 && style < 0x20)
    {
        LOGD(L_APP, L_V5, "固件升级");
    }
    memcpy(&sendData[i], data, len);
    i += len;
    //
    LOGD(L_APP, L_V5, "--------------> len = %d ",size);
    CommandDataSection1(sendData, size, 0xFF, 0x0F, 0x00, 0x00);
    Ram_Free(sendData);
}

#if 0
/******************************************************************************
 *  Function    -  track_cust_no7_paket_0D
 *
 *  Purpose     -  终端请求固件升级
 *
 *  Description -  track_cust_no7_paket_0D
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-28,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/

void track_cust_no7_paket_0D()
{
    kal_uint8 *sendData;
    kal_uint16 no, zone;
    int size, ver, i;

    size = 10 + 5 + 11 + 2;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);

    //序列号
    i = 10;
    memcpy(sendData[i], track_cust_deviceSN(), 5);
    i += 5;
    //客户代码
    sendData[i] = 0x01;
    i += 2;
    //硬件型号
    sendData[i] = 0x01;
    i += 2;
    //需要下载固件版本号
    sendData[i] = 0x01;
    i += 3;
    //固件类型
    sendData[i] = 0x01;
    i += 1;
    //分块机制
    sendData[i] = 0x01;
    i += 1;
    //数据块编号
    sendData[i] = 0x01;
    i += 2;

    no = DataPacketEncodeAA(0x0D, sendData, i);

    track_soc_write_req(sendData, size, 1, no);

    Ram_Free(sendData);
}
#endif
void track_cust_N07_paket_85(kal_uint8 *data, kal_uint8 len, kal_uint8 entype)
{
    static U8 rollBack = 0;
    int decodeLength = 0, i = 0, j = 9;
    U8 manufacturersID = 0, versions = 0, versionTmp = 0, fileUpdateStyle = 0;
    kal_uint8 voiceVersionTemp[4] = {0};
    kal_uint8 softVersionTemp[4] = {0};

    if(entype == 0xFF)
    {
        decodeLength = len;
    }
    else
    {
        sg_xxtea_set_key(G_parameter.ste_param.TEA_KEY);
        decodeLength = sg_xxtea_decrypt(data, len, 0);
    }
    LOGH(L_BMS, L_V5, data, decodeLength);
    manufacturersID = data[8];
    decodeLength -= 9;
    if(decodeLength > 1 && decodeLength % 4 == 0)
    {
        versions = decodeLength / 4;
        LOGD(L_APP, L_V5, "获取版本号%d个", versions);
    }
    else
    {
        LOGD(L_APP, L_V1, "ERROR 无版本信息或版本信息数据长度不对%d", decodeLength);
        return;
    }

    for(i = 0; i < decodeLength; i += 4)
    {
        j += i;
        if(data[j] == 0x10)
        {
            memcpy(softVersionTemp, &data[j], 4);
        }
        if(data[j] == 0x30)
        {
            memcpy(voiceVersionTemp, &data[j], 4);
        }
        versionTmp ++;
    }
    if(versionTmp != versions)
    {
        LOGD(L_APP, L_V1, "ERROR!版本个数校验错误,返回:%d:%d", versions, versionTmp);
        return;
    }
    LOGD(L_APP, L_V5, "OTA VERSION:Local[%02X.%02X.%02X.%02X]-Server[%02X.%02X.%02X.%02X];AUDIO VERSION:Local[%02X.%02X.%02X.%02X]-Server[%02X.%02X.%02X.%02X];Temp ADUION:[%02X.%02X.%02X.%02X]", \
         softwarever[0], softwarever[1], softwarever[2], softwarever[3], softVersionTemp[0], softVersionTemp[1], softVersionTemp[2], softVersionTemp[3], \
         G_parameter.voice_ver[0], G_parameter.voice_ver[1], G_parameter.voice_ver[2], G_parameter.voice_ver[3], \
         voiceVersionTemp[0], voiceVersionTemp[1], voiceVersionTemp[2], voiceVersionTemp[3], G_realtime_data.voice_version_tmp[0], \
         G_realtime_data.voice_version_tmp[1], G_realtime_data.voice_version_tmp[2], G_realtime_data.voice_version_tmp[3]);

    fileUpdateStyle = G_realtime_data.file_update_style;
    if(fileUpdateStyle != 0)
    {
        if(rollBack == 0)
        {
            HTTP_abnormal_restart_roll_back();
            rollBack = 1;
        }
        LOGD(L_APP, L_V1, "已经在数据更新了，忽略版本对比！[%d]", fileUpdateStyle);
        return;
    }
    else
    {
        rollBack = 0;
    }
    if((softVersionTemp[0] == softwarever[0]) && (softVersionTemp[1] != softwarever[1] || softVersionTemp[2] != softwarever[2] || softVersionTemp[3] != softwarever[3]))
    {
        fileUpdateStyle |= 1;
    }/*G_parameter.voice_ver[0]*/
    else if((voiceVersionTemp[0] == 0x30) && (voiceVersionTemp[1] != G_parameter.voice_ver[1] || voiceVersionTemp[2] != G_parameter.voice_ver[2] || voiceVersionTemp[3] != G_parameter.voice_ver[3]))
    {
        memset(audioVersion, 0, 4);
        memcpy(audioVersion, voiceVersionTemp, 4);
        fileUpdateStyle |= 2;
    }
    G_realtime_data.file_update_style = fileUpdateStyle;
    Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
    if((fileUpdateStyle & 1))
    {
        LOGD(L_APP, L_V4, "OTA版本有更新,向服务器请求HTTP下载地址");
        //track_cust_N07_paket_0F(softVersionTemp, 0x01, 4);20190723内容3位
        track_cust_N07_paket_0F(&softVersionTemp[1], softVersionTemp[0], 3);
    }
    else if((fileUpdateStyle & 2))
    {
        LOGD(L_APP, L_V4, "有新的语音版本需要下载，向服务器请求语音包数据,3s");
        tr_start_timer(TRACK_CUST_VOICE_8F_TIMER_ID, 3000, track_cust_N07_paket_0E);
    }
    else
    {
        LOGD(L_APP, L_V4, "没有OTA和语音版本需要更新");
    }
}

/******************************************************************************
 *  Function    -  track_cust_no7_paket_86
 *
 *  Purpose     -  远程控制数据包（终端上报）
 *
 *  Description -  track_cust_no7_paket_86
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-28,  Liujw  written
 * v1.1 ,2018-5-17 Liujw modify  增加result 记录扩展的执行结果 ，见平台协议1.0.7
 * ----------------------------------------
 ******************************************************************************/
void track_cust_no7_paket_86(U8 exeresult, U8 result, kal_uint8* id)
{
    kal_uint8 *sendData = NULL;

    int size, i = 0;
    //1.0.7版本需求，装载数据中又增加一个执行结果,加尼玛呀
    //size = 33;
    size = 32;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);

    //执行结果
    //sendData[i] = result;
    //i = 1;
    //MSGID

    LOGH2(L_APP, L_V5, "MSGID=", msgID, 32);

    if(id == NULL)
    {
        memcpy(&sendData[i], msgID, 32);
    }
    else
    {
        memcpy(&sendData[i], id, 32);

        LOGH2(L_APP, L_V5, "id=", id, 32);
    }
    i += 32;
    //LOGD(L_APP, L_V5, "指令包回复,exeresult=%d",exeresult);
    //CommandDataSection1(sendData, size, exeresult, 0x86, 0x00, 0x00);
    CommandDataSection1(sendData, size, result, 0x86, 0x00, 0x00);
    Ram_Free(sendData);
}


/******************************************************************************
 *  Function    -  track_cust_N07_paket_87
 *
 *  Purpose     -  远程参数查询（终端上报）
 *
 *  Description -  track_cust_N07_paket_87
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-28,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_N07_paket_87(kal_uint8 *data, kal_uint16 len)
{
    kal_uint8 *sendData = NULL;
    int size, i = 0;
    U8 exe = 0;

    size = len + 32;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);

    //参数名与参数值
    if(len > 0)
        memcpy(sendData, data, len);
    i = len;
    //MSGID
    memcpy(&sendData[i], msgID, 32);
    i += 32;
    if(len == 0) exe = 0x03;
    CommandDataSection1(sendData, size, exe, 0x87, 0x00, 0x00);

    Ram_Free(sendData);
}


/******************************************************************************
 *  Function    -  track_cust_no7_paket_88
 *
 *  Purpose     -  远程设置查询（终端上报）
 *
 *  Description -  track_cust_no7_paket_88
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-28,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_no7_paket_88(kal_uint8 *data, kal_uint16 len)
{
    kal_uint8 *sendData = NULL;
    int size, i;

    size = len + 32;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);

    //参数名与参数值
    memcpy(sendData, data, len);
    i = len;
    //MSGID
    memcpy(&sendData[i], msgID, 32);
    i += 32;
    CommandDataSection1(sendData, size, 0x00, 0x88, 0x00, 0x00);


    Ram_Free(sendData);
}
/******************************************************************************
 *  Function    -  track_cust_N07_paket_8B
 *
 *  Purpose     -  后台短信转发（终端上报）
 *
 *  Description -  track_cust_N07_paket_8B
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-28,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_N07_paket_8B()
{
    kal_uint8 sendData[1];

    int size, i = 0;

    //转发结果
    sendData[0] = 0x00;
    CommandDataSection(sendData, 1, 0xFF, 0x8B, 0x00, 0x00);
}
/******************************************************************************
 *  Function    -  track_cust_no7_paket_8C
 *
 *  Purpose     -  远程语音数据包（终端上报）
 *
 *  Description -  track_cust_no7_paket_8C
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-28,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_no7_paket_8C(U8 *voiceid, U8 exe)
{
    kal_uint8 *sendData = NULL;

    int size, i = 0;

    size = 35;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);

    //语音ID
    //sendData[i++] = voiceid;
    memcpy(&sendData[i], voiceid, 3);
    i += 3;
    //MSGid
    memcpy(&sendData[i], msgID, 32);

    //CommandDataSection(sendData, size, 0x00, 0x8C, 0x00, 0x00);
    CommandDataSection1(sendData, size, exe, 0x8C, 0x00, 0x00);

    Ram_Free(sendData);
}
void track_nvram_write()
{
    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
}

static int App_AUDIO_id_macth(kal_uint8 *audioID, U8 type)
{
    static kal_uint8 fileData[2048] = {0};
    int dataLength = 0, i = 0;
    int finder = 0;
    static int audioFileLength = 0;
    U8 _audioName[20] = {0};

    if(type == 0)
    {
        LOGD(5, 5, "%d,%d", audioFileLength, type);
        audioFileLength = 0;
        memset(fileData, 0, 2048);
        return -1;
    }
    if(audioFileLength <= 0 && type == 3)
    {
        audioFileLength = AUDIO_file_init(0, fileData, 0);
        AUDIO_file_init(2, NULL, 0);
        LOGD(5, 5, "%d,%d", audioFileLength, type);
        if(audioFileLength < 0) audioFileLength = 0;
        return audioFileLength;
    }
    if(audioID == NULL)
    {
        return 0;
    }

    if(audioFileLength > 0)
    {
        for(i = 0; i < audioFileLength; i++)
        {
            if(fileData[i] == 0x23 && (((i + 1) % 5) == 0) && fileData[i-4] == audioID[0] && fileData[i-3] == audioID[1] && fileData[i-2] == audioID[2])
            {
                finder = 1;
                break;
            }
        }
    }
	LOGD(5, 6, "%d",finder);
    return finder;

}
void track_cust_audio_file_del(void* arg)
{
    U8 par = (U8)arg;
    LOGD(5, 5, "%d,%d", par,G_realtime_data.file_update_style);
	if(G_realtime_data.file_update_style == 0)
	{
		return;
	}
    AUDIO_file_delete(1);//对比列表，多余的语音ID干掉
    AUDIO_file_init(2, NULL, 0);
    if(par == 1)
    {
        memcpy(G_parameter.voice_ver, audioVersion, 4);
        G_realtime_data.file_update_style &= 1;
        G_realtime_data.voice_max = 0;
        memset(&G_realtime_data.voice_list, 0, sizeof(voice_list_struct));
        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
        tr_start_timer(TRACK_CUST_NVRAM_WRITE_DELEY_TIMER_ID, 2000, track_nvram_write);
        if(track_soc_login_status())
        {
            track_start_timer(TRACK_CUST_VOICE_VERSION_UPDATE_RECONNECT_TIMER_ID, 60 * 1000, track_soc_gprs_reconnect, (void *)21);
        }
        return;//测试情况下先关掉
    }
    else
    {
        memcpy(G_realtime_data.voice_version_tmp, audioVersion, 4);
        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
    }
    if(!G_realtime_data.http_server.isdownload)
    {
        //track_audio_file_checking((void*)1);
        track_start_timer(TRACK_HTTP_AUDIO_FILE_REQUEST_OVERTIME_TIMER_ID, 2 * 1000, track_audio_file_checking, (void*)1);
    }

}
/******************************************************************************
 *  Function    -  track_cust_N07_paket_8E
 *
 *  Purpose     -  获取到的语音列表
 *
 *  Description -  要将语音ID进行排序放置
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-07-22,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_N07_paket_8E(kal_uint8 *data, kal_uint16 len, kal_uint8 entype)
{
    int decodeLength = 0;
    kal_uint8 dataType = 99;
    kal_uint16 audioNum = 0, totalNumber = 0;
    kal_uint16 _audioLength = 0;
    int i = 0, j = 0, k = 0, l = 0; //l 给已经存在的语音用
    voice_list_struct audioTemp = {0};
    voice_list_struct audio_exist = {0};//给已经存在的语音用
    U8 result = 1;
    int Voice_Id_File = 0;

    if(G_realtime_data.voice_version_tmp[0] == 0x30 || track_is_timer_run(TRACK_CUST_VOICE_GET_LIST_TIMER_ID))
    {
        //假如出现已经获取了ID，又需要获取的情况，不处理
        LOGD(L_APP, L_V1, "Error1");
        return;
    }
	if(G_realtime_data.file_update_style == 0)
	{
		return;
	}
    if(entype == 0xFF)
    {
        decodeLength = len;
    }
    else
    {
        sg_xxtea_set_key(G_parameter.ste_param.TEA_KEY);
        decodeLength = sg_xxtea_decrypt(data, len, 0);
    }
    LOGH(L_BMS, L_V5, data, decodeLength);
    dataType = data[8];
    audioNum = ((data[9] & 0x00FF) << 8) | data[10];
    if(audioNum > 100 || dataType != 0)//dataType不是0，目前必须是0，不是0我不知道要怎么处理，返回 2019-7-19 条数限制改为100
    {
        //既然没有需要下载的语音、那么就把语音更新的标志清掉，认为出问题了，不去升级，指令还原吗？
        G_realtime_data.file_update_style &= 1;
        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
        LOGD(L_APP, L_V1, "ERROR0!need %d,exceed 100,or type 0x00:[%d],return", audioNum, dataType);
        return;
    }
    totalNumber = audioNum;
    LOGD(L_APP, L_V5, "datatype=%d,v_number=%d,totalNumber=%d", dataType, audioNum, totalNumber);
    if(audioNum != 0)
    {
        _audioLength = decodeLength - 11;
        j = _audioLength / 3;
        if(j != audioNum)
        {
            LOGD(L_APP, L_V1, "ERROR!need %d,actually %d,not pair return", audioNum, j);
            return;
        }
        Voice_Id_File = App_AUDIO_id_macth(NULL, 3);
        for(i = 0; i < _audioLength; i += 3)
        {
            if(Voice_Id_File > 0 && App_AUDIO_id_macth(&data[11+i], 1))
            {
                audioNum--;
                memcpy(audio_exist.void_id[l].voice_id, &data[11+i], 3);
                audio_exist.void_id[l].isload = 1;
                //LOGH(L_APP, L_V6, audio_exist.void_id[l].voice_id, 3);
                l++;
            }
            else
            {
                //这里要将语音ID，从小到大排序
                memcpy(audioTemp.void_id[k].voice_id, &data[11+i], 3);
                audioTemp.void_id[k].isload = 0;
                //LOGH(L_APP, L_V6, audioTemp.void_id[k].voice_id, 3);
                k++;
            }
            if((i + 3) > 300) break;
        }
    }
    App_AUDIO_id_macth(NULL, 0);
    //track_cust_voice_list_sort(audio_exist, (totalNumber - audioNum));
    //track_cust_voice_list_sort(audioTemp, audioNum);
    LOGD(L_APP, L_V5, "compare result:%d,last:%d", audioNum, (totalNumber - audioNum));
    G_realtime_data.voice_max = totalNumber;//audioNum;
    memset(&G_realtime_data.voice_list, 0, sizeof(voice_list_struct));
    memcpy(&G_realtime_data.voice_list, &audioTemp, sizeof(voice_list_struct));
    //把已经存在的语音存下来
    if((totalNumber - audioNum) > 0)
    {
        memcpy(&G_realtime_data.voice_list.void_id[audioNum], audio_exist.void_id, ((totalNumber - audioNum) * 4));
    }
    LOGH(L_APP, L_V6, G_realtime_data.voice_list.void_id, 400);
#if 0
    if(dataType != 0)
    {
        LOGD(L_APP, L_V1, "Error！！！ 什么情况，0x8E数据包 数据类型不是0,[%d],返回", dataType);
        G_realtime_data.file_update_style &= 1;
        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
        return;
    }
#endif
#if 1
    if(audioNum == 0)
    {
        track_start_timer(TRACK_CUST_VOICE_GET_LIST_TIMER_ID, 2000, track_cust_audio_file_del, (void *) 1);
    }
    else
    {
        track_start_timer(TRACK_CUST_VOICE_GET_LIST_TIMER_ID, 2000, track_cust_audio_file_del, (void *) 2);
    }
#endif
#if 0
    AUDIO_file_delete(1);//对比列表，多余的语音ID干掉

    if(audioNum == 0)
    {
        //既然没有需要下载的语音、那么就把语音更新的标志清掉
        memset(G_parameter.voice_ver, 0, 4);
        memcpy(G_parameter.voice_ver, audioVersion, 4);
        //保存需要下载语音ID号
        Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
        G_realtime_data.file_update_style &= 1;
        //如果不需要下载，下载列表里面的删掉
        G_realtime_data.voice_max = 0;
        memset(&G_realtime_data.voice_list, 0, sizeof(voice_list_struct));
        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
        tr_start_timer(TRACK_CUST_VOICE_GET_LIST_TIMER_ID, 2000, track_nvram_write);
        if(track_soc_login_status())
        {
            track_start_timer(TRACK_CUST_VOICE_VERSION_UPDATE_RECONNECT_TIMER_ID, 60 * 1000, track_soc_gprs_reconnect, (void *)21);
        }
        return;//测试情况下先关掉
    }
    else
    {
        memset(G_realtime_data.voice_version_tmp, 0, 4);
        memcpy(G_realtime_data.voice_version_tmp, audioVersion, 4);
        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
    }
    //AUDIO_file_delete();
    if(!G_realtime_data.http_server.isdownload)
    {
        track_audio_file_checking((void*)1);
    }
#endif
}

void track_cust_N07_paket_8F(kal_uint8 *data, kal_uint16 len, kal_uint8 entype)
{
    kal_uint8 HTTP_LINK[500] = {0};
    int decodeLength = 0;
    int webLength = 0;
    kal_uint8 exeResult = 99;
    kal_uint8 dataType = 99;
    int i = 0, j = 0;
    kal_uint8 audioID[3] = {0};
    kal_uint8 otaVersion[4] = {0};
    U8 result = 1;
    if(G_realtime_data.http_server.filestyle != 0)
    {
        //请求了下载链接，又来一个0x0F
        LOGD(L_APP, L_V1, "Error1111,%d", G_realtime_data.http_server.filestyle);
        return;
    }
	if(G_realtime_data.file_update_style == 0)
	{
		return;
	}
    if(entype == 0xFF)
    {
        decodeLength = len;
    }
    else
    {
        sg_xxtea_set_key(G_parameter.ste_param.TEA_KEY);
        decodeLength = sg_xxtea_decrypt(data, len, 0);
    }
    LOGH(L_BMS, L_V5, data, decodeLength);
    exeResult = data[8];
    if(exeResult == 0x01)
    {
        LOGD(L_APP, L_V1, "响应失败");
        return;
    }
    dataType = data[9];
    /*if(getFileUpdateStatus())
    {
    	LOGD(L_APP, L_V1, "ERROR 有数据在更新，不接受新的更新路径");
    	return;
    }*/
    //if(dataType == 0x00)20190723,好像改了成了30
    if(dataType == 0x30)
    {
        memcpy(audioID, &data[10], 3);
        webLength = decodeLength - 13;
        if(webLength > 259)
        {
            LOGD(L_APP, L_V1, "error0，link addr259[%d]!", webLength);
            return;
        }
        memcpy(HTTP_LINK, &data[13], webLength);
        //memset(G_importance_parameter_data.http_server.url, 0, 99);

        tr_stop_timer(TRACK_HTTP_AUDIO_FILE_REQUEST_OVERTIME_TIMER_ID);
        memset(&G_realtime_data.http_server, 0, sizeof(nvram_http_server_struct));
        HTTP_web(HTTP_LINK, webLength);
        memcpy(G_realtime_data.http_server.voice_Id, audioID, 3);
        G_realtime_data.http_server.filestyle = 1;
    }
    //else if(dataType == 0x01)//固件升级
    //20190723
    else if(dataType >=0x10 && dataType < 0x20)
    {
        //memcpy(otaVersion, &data[10], 4);
        //webLength = decodeLength - 14;
        otaVersion[0] = dataType;//
        memcpy(&otaVersion[1], &data[10], 3);//固定3字节,但是以前是4个字节，不改以前逻辑，把数据装成以前得4个字节，虽然没什么卵用
        webLength = decodeLength - 13;
        if(webLength > 259)
        {
            LOGD(L_APP, L_V1, "error1，link addr259[%d]!", webLength);
            return;
        }
        //memcpy(HTTP_LINK, &data[14], webLength);
        memcpy(HTTP_LINK, &data[13], webLength);
        /*
        改连接长度，平台给的连接长度大过99字节 2018-6-12
        */
#if 0
        if(0)//(!strstr(HTTP_LINK, ".BIN"))//平台的连接不带文件后缀名，操 加你吗的密，有人会偷你家的东西吗
        {
            HTTP_LINK[webLength+14] = '\0';
            LOGD(L_APP, L_V1, "%s", HTTP_LINK);
            LOGD(L_APP, L_V1, "错误，估计格式与实际格式不一致！不请求");
            return;
        }
        else
#endif
            memset(&G_realtime_data.http_server, 0, sizeof(nvram_http_server_struct));
        G_realtime_data.http_server.filestyle = 2;
        //memset(G_importance_parameter_data.http_server.url, 0, 99);
        //memcpy(G_importance_parameter_data.http_server.url, HTTP_LINK, webLength);
        HTTP_web(HTTP_LINK, webLength);
    }
    G_realtime_data.http_server.isdownload = 1;//请求http服务器标志位
    Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);

    LOGD(L_APP, L_V6, "向HTTP服务器请求升级数据");
    track_cust_test_http(NULL, 0);
}

void track_cust_N07_cmd_recv(kal_uint8 cmdcode, kal_uint8 entype, kal_uint8 * data, kal_uint16 len)
{
    U8 login_style = 0;
    kal_uint16 crc = 0;
    kal_uint8 c_l = 0, c_h = 0;
    static U8 writeTEA = 0;
    LOGD(L_BMS, L_V5, "报文码:%.2X,加密方式:%.2X,len:%d", cmdcode, entype, len);
    LOGH(L_BMS, L_V7, data, len);
    crc = GetCrc16(&data[2], len - 4);
    c_h = (crc & 0xFF00) >> 8;
    c_l = crc & 0x00FF;
    if(c_h != data[len-2] || c_l != data[len-1])
    {
        LOGD(L_BMS, L_V1, "crc 校验出错！！！%02X,%02X,%02X,%02X", c_h, c_l, data[len-2], data[len-1]);
        return;
    }
    if(cmdcode != 0x80 && cmdcode != 0x81 && !track_soc_login_status())
    {
        LOGD(L_BMS, L_V1, "Not link.0x%02X", cmdcode);
        return;
    }
    if(cmdcode == 0x80)
    {
        login_style = track_cust_N07_80(&data[8], len - 10, entype);
        get_imsi();
        get_imei(1);
        if(login_style == 1)
        {
            if(ota_login == 1)
            {
                LOGD(L_BMS, L_V1, "ota_login");
                ota_login = 0;
                G_realtime_data.fota_update = 1;//临时抢救措施，后续只要realtime结构体不改变，则不用
            }
            if(G_realtime_data.fota_update == 1)
            {
                track_cust_login(FOTA_UPDATE);
            }
            get_firmware_version_list();
            tr_start_timer(TRACK_LOGIN_DATA_SEND_DELAY_TIMER_ID, 1000, track_cust_no7_paket_01);//track_cust_no7_paket_01();
            tr_stop_timer(TRACK_CUST_NET_LOGIN_RESEND_TIMER_ID);
            tr_stop_timer(TRACK_CUST_NET_LOGIN_TIMEOUT_TIMER_ID);
        }
    }
    else if(cmdcode == 0xC0)
    {
        track_cust_n07_C0(data, len);
    }
    else if(cmdcode == 0x81)
    {
        //登陆报文回复
        if(G_realtime_data.fota_update == 1)
        {
            G_realtime_data.fota_update = 0;
            Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
        }
        tr_stop_timer(TRACK_CUST_NET_LOGIN_TIMEOUT_TIMER_ID);
        tr_stop_timer(TRACK_CUST_NET_LOGIN_RESEND_TIMER_ID);
        tr_stop_timer(TRACK_CUST_NET_CONN_BAKDATA_TIMER_ID);
        if(!track_soc_login_status())
        {
            track_cust_gpsmode_net_new_conn();
        }

        LED_GSM_StatusSet(GPRS_CONNECT_STATE);
        track_set_login_status(KAL_TRUE);
        track_soc_conn_status(KAL_TRUE);
        if(!Login_N07PLAT_Success)
        {
            Login_N07PLAT_Success = KAL_TRUE;
        }

        track_soc_send((void*)99);
        track_os_intoTaskMsgQueueExt(track_soc_send, (void*)9);
        track_os_intoTaskMsgQueueExt(heartbeat_packets, (void*)113);
        track_cust_bms_upload(0);

        track_start_timer(TRACK_CUST_BMS_DATA_SEND_OVERTIME_TIMER_ID, 10 * 1000, track_bms_data_send, (void*)0);
        writeTEA = 0;
        LOGD(L_BMS, L_V5, "Ligin Success!%d,%d,%d", Login_N07PLAT_Success, track_soc_login_status(), G_parameter.voicefilesize);
        /*
        		if(G_parameter.voicefilesize == 0)
                {
                    G_parameter.voicefilesize = AUDIO_get_total_size();//读一次语音文件大小
                    if(G_parameter.voicefilesize > 0)
                        Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);

                }
        */
    }
    else if(cmdcode == 0x82)
    {
        if(G_parameter.ste_status.lease == 1)
        {
            track_cust_gprs_conn_fail((void*)1);
            track_check_tick(1, NULL);
            tr_stop_timer(TRACK_CUST_NET_HEARTBEAT_OVER_TIMER_ID);
            heartbeat_packets((void*)33);
        }

        track_soc_send((void*)99);
        LOGD(L_BMS, L_V9, "0x82");
    }
    else if(cmdcode == 0x83)
    {
        if(track_bms_data_send((void*)9) == 1)
        {
            track_bms_data_send((void*)1);
        }
        LOGD(L_BMS, L_V9, "0x83");
    }
    else if(cmdcode == 0x84)
    {
        LOGD(L_BMS, L_V9, "0x84");
        track_soc_send((void*)98);
    }
    else if(cmdcode == 0x85)
    {
        //track_soc_send((void*)98);
        track_cust_gprs_conn_fail((void*)1);
        track_check_tick(1, NULL);
        tr_stop_timer(TRACK_CUST_NET_HEARTBEAT_OVER_TIMER_ID);
        if(first_login == 0)
        {
            track_cust_login(0x01);//首次联网后，将重连原因改成gprs故障
            first_login = 1;
        }
        if(writeTEA < 2)
        {
            //有两次心跳，就认为有效链接上了，存储一下XXTEA密码,也就是写一次Nvram
            writeTEA ++;
            if(writeTEA == 2)
            {
            	if(get_token_type() != 1)
    			{
                	Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
                }
                LOGD(L_BMS, L_V1, "storage XXTEA PK");
                return;
            }
        }
        //增加一个存储解析到的域名的功能
        track_cust_ip_addr_link();

        track_http_download_manager();
        if(G_realtime_data.httpdowncount >= 15)
        {
            LOGD(L_BMS, L_V1, "次数上限");
            return;
        }

        if(track_getIsDownLoadFile() > 0)
        {
            LOGD(L_BMS, L_V1, "有文件下载，不对比版本");
            return;
        }
        if(track_is_timer_run(TRACK_CUST_VOICE_8F_TIMER_ID) || track_is_timer_run(TRACK_CUST_VOICE_GET_LIST_TIMER_ID))
        {
            LOGD(L_BMS, L_V1, "request voice list now");
            return;
        }
        //LOGD(L_APP, L_V5, "测试版本");
        //获取版本信息,对照是否需要升级
        //是否要判断震动或者轮动\霍尔状态下，不去升级
        if((len - 10 > 0) && G_parameter.ste_status.lease == 0 && (track_cust_vehicle_moving(11) & 6) == 0) //有版本信息等你妈
        {
            track_cust_N07_paket_85(&data[8], len - 10, entype);
        }
    }
    else if(cmdcode == 0x06)
    {
        LOGD(L_BMS, L_V9, "0x06");
        //return;
        track_cust_N07_paket_06(&data[8], len - 10, entype, 0);
    }
    else if(cmdcode == 0x07)
    {

        //return;
        LOGD(L_BMS, L_V9, "0x07");
        track_cust_N07_packet_07(&data[8], len - 10, entype);
    }
    else if(cmdcode == 0x08)
    {
        LOGD(L_BMS, L_V9, "0x08");

        //return;
        track_cust_N07_paket_08(&data[8], len - 10, entype);
    }
    else if(cmdcode == 0xC6)
    {
        ;
    }
    else if(cmdcode == 0x0B)
    {
        //return;
        track_cust_N07_paket_0B(&data[8], len - 10, entype);
    }
    else if(cmdcode == 0x0C)
    {
        //return;
        track_cust_N07_paket_0C(&data[8], len - 10, entype);
    }
#if 1
    else if(cmdcode == 0x8E)
    {
        track_cust_N07_paket_8E(&data[8], len - 10, entype);
    }
    else if(cmdcode == 0x8F)
    {
        track_cust_N07_paket_8F(&data[8], len - 10, entype);
    }
    else if(cmdcode == 0x12)
    {
		track_cust_N07_paket_12(&data[8], len - 10, entype);
    }
    else
    {
        LOGD(L_APP, L_V1, "%d,RESPONSE NO HANDLE!!!", cmdcode);
    }
#endif
}
void track_cust_N07_data(kal_uint8* data, kal_int32 len)
{
    //track_cust_N07_cmd_recv(data[5], data[6], data, len);

#if 1
    kal_uint8 cmd = 0, addid = 0, cmdlen = 0;
    kal_uint8  j = 0, k = 0,  m = 0;
    kal_uint16 i = 0, l = 0;
    static kal_bool find = KAL_FALSE;
    static kal_uint32 t_len = 0;
    static kal_uint8 buf[1024];
    //kal_uint8 h_buf[300];
    kal_uint8 head = 0, end = 0;
    //kal_uint16 o_len = 0;
    kal_uint8 finder = 0;
    LOGH2(L_APP, L_V5, "", data, len);
    if(len <= 0) return;
    if(t_len + len > 1024)
    {
        memset(buf, 0, 1024);
        t_len = 0;
        return;//出现这种情况，认为电池芯片出错
    }
    memcpy(&buf[t_len], data, len);
    t_len += len;
    for(i = 0; i < t_len; i++)//用while比用for要好多了，因为i++可以自己写
    {
        if(buf[i] == 0xAA && buf[i+1] == 0xBB)//如果出现AABBAABB.......的拼包问题，则会长时间断网，所有的回复解析不到
        {
            if(i + 3 >= t_len)break;
            head = buf[i+2];
            end = buf[i+3];
            o_len = (head & 0x00FF) << 8;
            o_len |= (end & 0x00FF);
            LOGD(L_APP, L_V9, "%d", o_len);
            if(i + o_len > t_len) break;
            memset(h_buf, 0, 512);

            if(o_len <= 512)//单条数据包超过512，先抛弃
            {
                memcpy(h_buf, &buf[i], o_len);
                //这里将RSA解密单独提取出来
                if(h_buf[5] == 0x80)
                {
                    finder = 1;
                }
                else
                {
                    track_cust_N07_cmd_recv(h_buf[5], h_buf[6], h_buf, o_len);
                }
            }
            l = (i + o_len);
            i = l - 1;//因为for里面有i++,这里就要减去1，下标；本身是没有错的
            if(finder == 1) break;
        }
    }

    LOGD(L_APP, L_V5, "l=%d,t_len=%d,finder=%d", l, t_len, finder);
    if(l < t_len)
    {
        kal_uint8 *tempbuf = NULL;
        int last = t_len - l;
        tempbuf = (U8*)Ram_Alloc(6, last);
        if(tempbuf == NULL)
        {
            LOGD(L_BMS, L_V1, "Error! tempbuf not range");

            memset(buf, 0, 1024);
            t_len = 0;
            return;
        }
        memcpy(tempbuf, &buf[l], last);
        memset(buf, 0, 1024);
        memcpy(buf, tempbuf, last);
        t_len = last;
        Ram_Free(tempbuf);
        tempbuf = NULL;
        LOGD(L_APP, L_V5, "处理剩余数据");
    }
    else
    {
        memset(buf, 0, 1024);
        t_len = 0;
    }
    if(finder == 1)
    {
        track_os_intoTaskMsgQueue(track_cust_authentication);
        finder = 0;
    }
#endif
}

void track_cust_N07_sms_relay(track_sms_param *sms_rev)
{
    kal_uint8 TelNum[32] = {0};
    kal_uint8 TelBCD[10] = {0};
    kal_uint8 srctmp[320];
    kal_uint8 desttmp[1000];
    U8 len = 0;
    kal_int32 msglen = 0;
    LOGD(L_BMS, L_V5, "号码%s", sms_rev->TPA);
    LOGH(L_BMS, L_V9, sms_rev->TP_UD, sms_rev->TP_UDL);
    len = sprintf(TelNum, "%sFFFFFFFFFFFFFFFFFFFF", sms_rev->TPA);
    track_fun_NUM_to_BCD(TelNum, TelBCD);
    //track_cust_N07_paket_0A(sms_rev->TPA, 10, sms_rev->TP_UD, sms_rev->TP_UDL);
    //track_cust_N07_paket_0A(TelBCD, 10, sms_rev->TP_UD, sms_rev->TP_UDL);

    if(!track_soc_login_status()) return;
    if(sms_rev->TP_DCS == GSM_7BIT || sms_rev->TP_DCS == GSM_8BIT)
    {
        track_cust_N07_paket_0A(TelBCD, 10, sms_rev->TP_UD, sms_rev->TP_UDL);
    }
    else if(sms_rev->TP_DCS == GSM_UCS2)
    {
        memcpy(srctmp, sms_rev->TP_UD, sms_rev->TP_UDL);
        //	E6 88 91 E7 88 B1 E4 BD A0	我爱你 UTF-8 16进制
        msglen	= track_fun_UCS_to_UTF8(sms_rev->TP_UD, sms_rev->TP_UDL, &desttmp, 1000);
        track_cust_N07_paket_0A(TelBCD, 10, desttmp, msglen);
    }
    else
    {
        LOGD(L_APP, L_V5, "TP_DCS:%d TP_UDL:%d", sms_rev->TP_DCS, sms_rev->TP_UDL);
    }
}
VOID ALARM_get_position(track_gps_data_struct *new_data)
{
    float Contrast_Dist = 0.0;
    static track_gps_data_struct *Last_Comm_Position = NULL;
    LBS_Multi_Cell_Data_Struct *lbs = track_drv_get_lbs_data();

    if(new_data == NULL) return;

    if(Get_Last_Position == KAL_FALSE)
    {
        Get_Last_Position = KAL_TRUE;
        Last_Comm_Position = track_cust_backup_gps_data(2, NULL);
    }
    LOGD(L_GPS, L_V4, "%.6f,%.6f,%.6f,%.6f,", Last_Comm_Position->gprmc.Latitude, Last_Comm_Position->gprmc.Longitude, new_data->gprmc.Latitude, new_data->gprmc.Longitude);
    Contrast_Dist = track_fun_get_GPS_2Points_distance(Last_Comm_Position->gprmc.Latitude, Last_Comm_Position->gprmc.Longitude, new_data->gprmc.Latitude, new_data->gprmc.Longitude);
    if(Contrast_Dist < 0) Contrast_Dist = -Contrast_Dist;
    LOGD(L_BMS, L_V5, "---->get distance:%.6f", Contrast_Dist);
    //if(Contrast_Dist >= 100 || instructions_paging_status == 1)
    {
        //Contrast_Dist = 0;
        //instructions_paging_status = 0;
        tr_stop_timer(TRACK_CUST_PAGING_OVERTIME_TIMER_ID);
        if(Contrast_Dist >= 100 || instructions_paging_status == 1)
        {
            Contrast_Dist = 0;
            instructions_paging_status = 0;
            track_cust_backup_gps_data(3, new_data);
            track_cust_N07_paket_02(new_data, lbs);

            if(track_is_timer_run(TRACK_CUST_WORK_MODE_GPSUPDATE_OVERTIME_TIMER_ID))
            {
                tr_stop_timer(TRACK_CUST_WORK_MODE_GPSUPDATE_OVERTIME_TIMER_ID);
                track_cust_gps_send_data(0);
            }
        }
        Get_Last_Position = KAL_FALSE;
    }
}
void track_cust_paging_overtime(void *arg)
{
    kal_uint8 par = (kal_uint8)arg;
    Get_Last_Position = KAL_FALSE;
    instructions_paging_status = 0;

    LOGD(L_BMS, L_V5, "paging指令超时处理,%d,par:%d,%d", track_cust_gps_status(), par, Get_Last_Position);

    //超时donoting
#if 0
    if((par == 1 || par == 0) && track_cust_gps_status() > 2)
    {
        track_gps_data_struct *gd = track_cust_backup_gps_data(0, NULL);//track_drv_get_gps_data();//这里应该是用最新定位的数据点
        LBS_Multi_Cell_Data_Struct *lbs = track_drv_get_lbs_data();
        track_cust_N07_paket_02(gd, lbs);
        if(par == 1)
        {
            track_cust_backup_gps_data(3, gd);
        }
    }
#endif
}
//2019-7-9  获取GPS数据使用 最新一条定位点
void track_cust_paging_packet(void)
{
    track_gps_data_struct *gd = track_cust_backup_gps_data(2, NULL); //这里上传上一次有效点速度改为0？//track_drv_get_gps_data();
    LBS_Multi_Cell_Data_Struct *lbs = track_drv_get_lbs_data();

    LOGD(L_BMS, L_V5, "gd->gprmc.status:%d,%d", gd->gprmc.status, gd->gprmc.Speed);
    if(track_cust_gps_status() > 2)
    {
        track_start_timer(TRACK_CUST_PAGING_OVERTIME_TIMER_ID, 3 * 60 * 1000, track_cust_paging_overtime, (void*)0);
    }
    else
    {
        if(gd->gprmc.status > 0)
        {
            //gd->gprmc.Speed = 0;
            //gd->status = 1;
            LOGD(L_BMS, L_V5, "last location!!");
            track_cust_N07_paket_02(gd, lbs);
        }
        track_cust_gps_work_req((void*)13);
        track_start_timer(TRACK_CUST_PAGING_OVERTIME_TIMER_ID, 3 * 60 * 1000, track_cust_paging_overtime, (void*)0);

        /*if(track_cust_gps_status() < 3)
        {
            track_cust_gps_work_req((void*)13);
            track_start_timer(TRACK_CUST_PAGING_OVERTIME_TIMER_ID, 3 * 60 * 1000, track_cust_paging_overtime, (void*)0);
        }*/
    }

}
/******************************************************************************
 *  Function    -  track_cust_paging_command
 *
 *  Purpose     -  报警后定位点的上传函数
 *
 *  Description -  NULL
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-07-10,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_paging_command(void)
{
    kal_uint32 time = 2000;
    LOGD(L_BMS, L_V5, "");
    if(track_drv_wifi_status(99) == 0)
    {
        track_drv_wifi_cmd(1);
        //track_drv_wifi_cmd(2);
        track_start_timer(TRACK_CUST_WIFI_WORK_TIMER_ID, 600, track_drv_wifi_cmd, (void*)2);
    }
    else
    {
        track_drv_wifi_cmd(2);
        time = 600;
    }

    if(track_cust_gps_status() < 3)
    {
        track_cust_gps_work_req((void*)13);
    }
    tr_start_timer(TRACK_CUST_PAGING_OVERTIME_TIMER_ID, time, track_cust_paging_packet);
}
#if 0
void test_md5()
{
    kal_uint8 result[16];
    static kal_uint8 ss[11] = {"700000001"};
    textMD5(ss, result, 9);
    LOGH(L_APP, L_V5, result, 16);
    textMD5(serialNumberStr, result, 10);
    LOGH(L_APP, L_V5, result, 16);
    textMD5(serialNumberHex, result, 5);
    LOGH(L_APP, L_V5, result, 16);
}
#endif
void track_cust_cmd_online_fix_rsp()
{
    track_cust_N07_paket_02(track_drv_get_gps_data(), track_drv_get_lbs_data());
}
static void track_cust_authentication()
{
    track_cust_N07_cmd_recv(h_buf[5], h_buf[6], h_buf, o_len);
}
void track_cust_NO7_packet_00_decode_msg(kal_uint8 *data, int len)
{
    long timestamp = 0;
    applib_time_struct result = {0};

    if(data[1] != 0x00)
    {
        LOGD(L_APP, L_V5, "认证报文回复失败,%02X", data[1]);
        return;
    }
    memset(serverUTC, 0, 9);
    memcpy(serverUTC, serialNumberHex, 5);
    memcpy(&serverUTC[5], &data[2], 4);
    timestamp = ((data[2] & 0x000000FF) << 24) | ((data[3] & 0x000000FF) << 16) | ((data[4] & 0x000000FF) << 8) | data[5];
    //LOGD(L_APP, L_V5, "timestamp:%d",timestamp);
    setMD5((void*)0);
    get_imsi();
    get_imei(1);
    get_firmware_version_list();
    if(G_realtime_data.fota_update == 1)
    {
        track_cust_login(FOTA_UPDATE);
    }
    tr_stop_timer(TRACK_CUST_NET_LOGIN_RESEND_TIMER_ID);
    tr_stop_timer(TRACK_CUST_NET_LOGIN_TIMEOUT_TIMER_ID);
    track_os_intoTaskMsgQueue(track_cust_no7_paket_01);
    applib_dt_utc_sec_2_mytime(timestamp, &result, 0);
    LOGD(L_APP, L_V5, "服务器时间:%d-%02d-%02d %02d:%02d:%02d", result.nYear, result.nMonth, result.nDay, result.nHour, result.nMin, result.nSec);
    track_fun_update_time_to_system(2, (applib_time_struct *)(&result));
    /*
    if(1)
    {
    	extern void track_soc_disconnect(void);
    	track_soc_disconnect();
    }
    */
}
/******************************************************************************
 *  Function    -  track_cust_driver_behaviour
 *
 *  Purpose     -  驾驶行为：sensor x y z 三轴数据获取
 *
 *  Description -  return Null
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 25-09-2017,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_driver_behaviour()
{
    short x, y, z;
    static short tmp_x, tmp_y, tmp_z;
    sensor_type_enum sensor_type;
    sensor_type = track_drv_get_sensor_type();
    if(sensor_type != SENSOR_KXTJ31057)
    {
        LOGD(L_APP, L_V7, "not 1057%d", sensor_type);
        return;
    }
    if(G_parameter.ste_status.lease == 0)
    {
        track_drv_sensor_get_xyz(&x, &y, &z);
        sensor_x = tmp_x - x;
        if(sensor_x < 0)sensor_x = -sensor_x;
        sensor_y = tmp_y - y;
        if(sensor_y < 0)sensor_y = -sensor_y;
        sensor_z = tmp_z - z;
        if(sensor_z < 0)sensor_z = -sensor_z;
        tmp_x = x;
        tmp_y = y;
        tmp_z = z;
    }
    LOGD(L_APP, L_V9, "x:%d,y:%d,z:%d,%d,%d,%d,%d,%d,%d", x, y, z, tmp_x, tmp_y, tmp_z, sensor_x, sensor_y, sensor_z);
    tr_start_timer(TRACK_CUST_SENSOR_READ_TIMER_ID, 1000, track_cust_driver_behaviour);
}
char *track_get_appversion()
{
    static char appversion[10];
    sprintf(appversion, "%d.%d.%d", softwarever[1], softwarever[2], softwarever[3]);
    return appversion;
}
char *track_get_hardversion()
{
    static char hw[10];
    sprintf(hw, "%d.%d.%d", hardwarever[1], hardwarever[2], hardwarever[3]);
    return hw;
}
void track_get_hardversionHex(kal_uint8 *src)
{
    memcpy(src, &hardwarever[1], 3);
}
void track_get_softversionHex(kal_uint8 *src)
{
    memcpy(src, &softwarever[1], 3);
}
U8 get_token_type()
{
    return tokenType;
}
U8 track_set_audio_file_play(U8 arg)
{
    static U8 audioPlayByFile = 0;
    if(arg != 99)
    {
        audioPlayByFile = arg;
    }
    LOGD(L_APP, L_V9, "audioPlayByFile:%d", audioPlayByFile);
    return audioPlayByFile;
}
void track_cust_voice_list_sort(voice_list_struct ls, kal_uint8 mem)
{
    kal_uint32 frontId = 0, nextId = 0;
    int i = 0, j = 0;
    voice_id_struct tmp_vis = {0};
    for(i = 0; i < (mem - 1); i++)
    {
        //LOGD(L_APP, L_V5, "%d-%d", frontId, nextId);
        for(j = 0; j < mem - 1 - i; j++)
        {
            frontId = ((ls.void_id[j].voice_id[0] & 0x0000FF) << 16) | ((ls.void_id[j].voice_id[1] & 0x0000FF) << 8) | ls.void_id[j].voice_id[2];
            nextId = ((ls.void_id[j+1].voice_id[0] & 0x0000FF) << 16) | ((ls.void_id[j+1].voice_id[1] & 0x0000FF) << 8) | ls.void_id[j+1].voice_id[2];
            if(frontId > nextId)
            {
                memcpy(&tmp_vis, &ls.void_id[j], sizeof(voice_id_struct));
                memcpy(&ls.void_id[j], &ls.void_id[j+1], sizeof(voice_id_struct));
                memcpy(&ls.void_id[j+1], &tmp_vis, sizeof(voice_id_struct));
                //LOGH(L_APP, L_V5, ls.void_id[j].voice_id, 3);
                //LOGH(L_APP, L_V5, ls.void_id[j+1].voice_id, 3);
            }
        }
    }
    LOGH(L_APP, L_V5, ls.void_id, (mem * 4));
}
#if 0
typedef struct
{
    int         iDrvLetter;
    WCHAR       wfile_name[64];
    FS_HANDLE   wfile_hd;
    kal_uint32  writen_size;
#if !defined (__REMOVE_LOG_TO_FILE__)
    c_string*   string;
#endif /* __REMOVE_LOG_TO_FILE__ */

} FAT_FILE_ST;

//一下会增加一个SN号和加密秘钥的备份文件
static  WCHAR       sn_file_name[40];
static FAT_FILE_ST sn_file = {0};//语音文件读写
//数据长度 SN[5]+CRC[2]+SN[128]+CRC[2]=137
int sn_file_write(kal_uint8 * data, int len, int offset)
{
    kal_uint32   file_operate_size;
    int fs_seek = 0, fs_write = 0;

    fs_seek = FS_Seek(sn_file.wfile_hd, offset, 0);
    if(fs_seek < 0)
    {
        LOGD(L_DRV, L_V1, "fs_seek error %d", fs_seek);
        return -1;
    }

    fs_write = FS_Write(sn_file.wfile_hd, (void*)data, len, &file_operate_size);
    if(fs_write < 0)
    {
        LOGD(L_DRV, L_V5, "ret fs_write:%d fs_seek=%d", fs_write, fs_seek);
        return -2;
    }
    FS_Commit(sn_file.wfile_hd);
    return file_operate_size;
}

int sn_file_read(void * data, int length, int  Offset)
{
    kal_uint32   file_operate_size;
    int fs_seek = 0, fs_write = 0;

    LOGD(L_DRV, L_V5, "");

    fs_seek = FS_Seek(sn_file.wfile_hd, Offset, FS_FILE_BEGIN);
    if(fs_seek < FS_NO_ERROR)
    {
        LOGD(L_DRV, L_V5, "FS_Seek %d", fs_seek);
        return -2;
    }

    fs_write = FS_Read(sn_file.wfile_hd, (void *)data, length , &file_operate_size);
    if(fs_write < FS_NO_ERROR)
    {
        FS_Close(fs_write);
        LOGD(L_DRV, L_V5, "ret fs_write:%d fs_seek=%d", fs_write, fs_seek);
        return -3;
    }
    FS_Commit(sn_file.wfile_hd);
    return file_operate_size;
}

void sn_file_init(kal_uint8 op)
{
    kal_uint32   file_operate_size;
    static U8 first = 0;
    if(first == 0)
    {
        first = 1;
        OTA_kal_wsprintf(sn_file_name, "%s", "SNFILEBAK");
        OTA_kal_wsprintf(sn_file.wfile_name, "%s", sn_file_name);
        sn_file.wfile_hd = FS_Open(sn_file_name , FS_CREATE | FS_READ_WRITE);

        if(sn_file.wfile_hd < 0)
        {
            LOGD(L_DRV, L_V1, "ERROR %d", sn_file.wfile_hd);
        }
    }
    if(op == 1)//close
    {
        FS_Close(sn_file.wfile_hd);
        first = 0;
    }
    else if(op == 2)
    {
        FS_Close(sn_file.wfile_hd);
        FS_Delete(sn_file_name);
    }
    else if(op == 9)
    {
        first = 0;
    }
}
void track_cust_sn_bak(kal_uint8 * data, U8 type)
{
    U16 tmp, tmp1, tmp2, tmp3;
    kal_uint8 dataTmp[256] = {0};
    kal_uint8 dataTmp1[256] = {0};
    kal_uint8 snTmp[12] = {0};
    static U8 op = 0;
    if(op == 0)
    {
        sn_file_init(0);
        op = 1;
    }
    if(type == 1)//sn
    {
        tmp = GetCrc16(G_importance_parameter_data.SequenceNumber, 11);
        tmp1 = GetCrc16(G_parameter.ste_param.publickey, 128);
        LOGD(L_DRV, L_V1, "crc:0x%02X,0x%02X", tmp, tmp1);
        LOGH2(L_DRV, L_V1, "SN", &dataTmp[0], 256);
        sn_file_read(&dataTmp[0], 256, 0);
        LOGH2(L_DRV, L_V1, "SN", &dataTmp[0], 256);
        memcpy(dataTmp, G_importance_parameter_data.SequenceNumber, 11);
        dataTmp[11] = (tmp & 0xFF00) >> 8;
        dataTmp[12] = tmp & 0x00FF;
        memcpy(&dataTmp[13], G_parameter.ste_param.publickey, 128);
        dataTmp[141] = (tmp1 & 0xFF00) >> 8;
        dataTmp[142] = tmp1 & 0x00FF;
        LOGH2(L_DRV, L_V1, "SN", &dataTmp[0], 256);
        sn_file_write(&dataTmp[0], 256, 0);

        sn_file_read(&dataTmp1[0], 256, 0);
        memcpy(snTmp, &dataTmp1[0], 11);
        tmp2 = GetCrc16(snTmp, 11);
        tmp3 = GetCrc16(&dataTmp[13], 128);
        snTmp[12] = '\0';
        LOGD(L_DRV, L_V1, "crc:0x%02X,0x%02X,%s;%s", tmp2, tmp3, snTmp, G_importance_parameter_data.SequenceNumber);
        LOGH2(L_DRV, L_V1, "SN", &dataTmp1[0], 256);
    }
}
#endif
#endif
void track_instructions_get_paging(void)
{
    instructions_paging_status = 1;
    track_cust_paging_command();
}
//gps信号强度排序打包
void track_signal_intensity(U8 *sendbuf, track_gps_data_struct *gd)
{
	int i,j,k;
	kal_uint8 gsv_id[32],gsv_qd[32];
	kal_uint8 temp;
	memset(gsv_id,0x00,32);
	memset(gsv_qd,0x00,32);
	memcpy(gsv_id,gd->bdgsv.Satellite_ID,32);
	memcpy(gsv_qd,gd->bdgsv.SNR,32);
    //LOGH(L_APP, L_V5, gsv_id,32);
    //LOGH(L_APP, L_V5, gsv_qd,32);
	for (j = 0; j < 31; j++)
 	{
  		for (i = 0; i < 31 - j; i++)
  		{
   			if (gsv_qd[i] < gsv_qd[i + 1])
   			{
    			temp = gsv_qd[i];
   				gsv_qd[i] = gsv_qd[i + 1];
    			gsv_qd[i + 1] = temp;
    			temp = gsv_id[i];
   				gsv_id[i] = gsv_id[i + 1];
    			gsv_id[i + 1] = temp;
   			}
  		}
 	} 
 	for(i = 0,j=0 ;i <5&&j<10 ;i++,j+=2)
 	{
		if(gsv_qd[i]>0)
		{
			sendbuf[j]=gsv_id[i];
			sendbuf[j+1]=gsv_qd[i];
		}
		else
		{
			sendbuf[j]=0x00;
			sendbuf[j+1]=0x00;
		}
 	}
	
}


void track_cust_N07_paket_92(U8 exeresult,kal_uint8 * id)
{
	
	kal_uint8 *sendData = NULL;
	kal_uint8 size = 32;
	sendData = (U8*)Ram_Alloc(5, size);
	if(id == NULL)
	{
		memcpy(sendData,msgID2,32);
	}
	else
	{
		memcpy(sendData,id,32);
	}
	G_parameter.bt_token_mark = 0;
	LOGD(L_APP, L_V5,"exeresult =%x",exeresult);
	Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
	CommandDataSection(sendData, size, exeresult, 0x92, 0x00, 0x00);
	Ram_Free(sendData);
}
//--------------

//-----------------
void bt_pass_change_d_s(kal_uint8 * data_d,kal_uint8 * data_s,kal_uint8 type);
void track_cust_N07_paket_12(kal_uint8 *data, kal_uint8 len, kal_uint8 entype)
{
	int decodeLength = 0;
	kal_uint8 tybe_id;
	kal_uint8 time_this[8];
	//kal_uint8 NEW_BT_password[16];
	kal_uint8 bt_status[20]={0};
	kal_uint8 btconn = 0;//蓝牙连接状态
	kal_uint8 checkout [8];
	if(entype == 0xFF)
	{
		decodeLength = len;
	}
	else
	{
		sg_xxtea_set_key(G_parameter.ste_param.TEA_KEY);
        decodeLength = sg_xxtea_decrypt(data, len, 0);
	}
	memset(msgID2, 0, 32);
	memset(time_this,0x00,8);
	memset(NEW_BT_password,0x00,16);
	memset(checkout,0x00,8);
	memcpy(time_this,&data[2],4);
	tybe_id = data[8];
	memcpy(NEW_BT_password,&data[9],16);
	memcpy(checkout,&data[57],8);
	memcpy(msgID2, &data[25], 32);
	sg_xxtea_set_key(NEW_BT_password);
	sg_xxtea_encrypt(time_this,4);//到底是8位还是4位我母鸡呀
	OTA_track_ble_bt_status(bt_status);
	btconn = bt_status[1];
	LOGD(L_APP, L_V5,"tybe_id = %d  btconn = %d  checkout = %d",tybe_id,btconn,memcmp(time_this,checkout,0x08));
	if(memcmp(time_this,checkout,0x08))//密码校验错误
	{
		track_cust_N07_paket_92(0x01,NULL);
		return;
	}
	memset(G_parameter.new_encode_token_s,0x00,50);//保存新密码
	bt_pass_change_d_s(NEW_BT_password,G_parameter.new_encode_token_s,1);

	if(tybe_id == 0x02)
	{
		if(btconn)//蓝牙以连接
		{
			memset(NEW_BT_password,0x00,16);
			track_cust_N07_paket_92(0x0F,NULL);
			return;
		}
		G_parameter.bt_token_mark = 1;//是否下发蓝牙新密码 1是
	}
	if(tybe_id == 0x01)
	{
		if(btconn)//蓝牙以连接,断开蓝牙连接
		{
			track_cmd_resetbt((void*)0);	
		}
		G_parameter.bt_token_mark = 1;
	}
    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);

}

//==========
//===================================================
kal_uint8 track_get_voice_numid_sta(void)
{
	return play_voice_sta_num_id;
}
kal_uint8 play_sub_voice(kal_uint8 *number_id,kal_uint8  sta)
{
	kal_uint8 exe = 0;
	track_set_audio_file_play(1);
    exe = AUDIO_file_play(number_id);
    
	LOGD(L_APP, L_V5,"---->music_ID:%02x %02x %02x sta:%x exe:%d",number_id[0],number_id[1],number_id[2],sta,exe);

    if((sta & 0x8) == 0)//0c包回复报文
    {
    	track_cust_no7_paket_8C(number_id, exe);
    }
    if(exe == 1 || exe == 9)
    {
        track_set_audio_file_play(0);
        //语音播放失败，返回失败，清理该语音ID
        Substantiv_voice_id(track_get_voice_numid_sta());
    }

    return 0;
}
void Substantiv_voice_id(kal_uint8 voice_sta)
{
	LOGD(L_APP, L_V5,"---->have music is runing yes(1) or no(0): %d   voice_sta:%d  ii:%d",track_set_audio_file_play(99),voice_sta,play_voice_sta_num_id);
	if(voice_sta <= 3 && voice_sta >=0)
	{
	//播放完该条语音，清理语音ID
		if(voice_sta != 0)
		{

			memset(down_voice_id[voice_sta - 1],0x00,3);
			if(voice_sta == 3)
			{
				play_voice_sta_num_id = 0;
			}
		}
		if((track_set_audio_file_play(99)) == 1) 
		{
        	track_set_audio_file_play(0);
        }
	}

	if(track_set_audio_file_play(99) == 0 && (track_is_timer_run(TRACK_CUST_TEST_RING_TIMER_ID) == 0) && track_cust_get_speelt_sta(99) != 2)
	{

		if((track_get_violue_status(down_voice_id[0]) == 1) && play_voice_sta_num_id == 0)
		{
			voice_volume = (voice_volume_0 & 0x7);
			play_voice_sta_num_id ++;
			play_sub_voice(down_voice_id[0],voice_volume_0);
		}
		else if((track_get_violue_status(down_voice_id[1]) == 1) && play_voice_sta_num_id == 1)
		{
			voice_volume = (voice_volume_1 & 0x7);
			play_voice_sta_num_id ++;
			play_sub_voice(down_voice_id[1],voice_volume_1);
		}
		else if((track_get_violue_status(down_voice_id[2]) == 1) && play_voice_sta_num_id == 2)
		{
			voice_volume = (voice_volume_2 & 0x7);
			play_voice_sta_num_id ++;
			play_sub_voice(down_voice_id[2],voice_volume_2);
		}
		else
		{
			LOGD(L_APP, L_V5,"------>no voluce  ID");
			play_voice_sta_num_id = 0;
			if(track_cust_get_speelt_sta(99)==1)
			{
				track_cust_get_speelt_sta(0x00);
				track_cust_get_alarm_status(0);
				speed_voice_play();
				
			}
		}
	}
	return;
}

kal_uint8 voice_sub_down_id(kal_uint8 * data_id,kal_uint8 vol_voice)
{
	if(track_get_violue_status(down_voice_id[0])==0 && ((track_get_violue_status(down_voice_id[2])!=0) || (track_get_violue_status(down_voice_id[1])==0 && track_get_violue_status(down_voice_id[2])==0) ) )
	{
		memcpy(down_voice_id[0],data_id,3);
		voice_volume_0 = vol_voice;
	}
	else if(track_get_violue_status(down_voice_id[1]) == 0)
	{
		memcpy(down_voice_id[1],data_id,3);
		voice_volume_1 = vol_voice;
	}
	else if(track_get_violue_status(down_voice_id[2]) == 0)
	{
		memcpy(down_voice_id[2],data_id,3);
		voice_volume_2 = vol_voice;
	}
	else
	{
	//缓存语音条数已经满了，不在缓存播放
		LOGD(L_APP, L_V5,"------>voluce is 3 ");
		return 1;
	}
	Substantiv_voice_id(6);
	return 0;
}

kal_uint8 track_get_voice_volume(void)
{
	return voice_volume;
}

kal_uint8 track_get_violue_status(kal_uint8 * data)
{
	kal_uint8 ret = 99;
	if(data[0] == 0x00 && data[1] == 0x00 && data[2] == 0x00)
	{

		ret = 0;
	}
	else
	{
		ret = 1;
	}
	//LOGD(L_APP, L_V5,"----->:%d ",ret);

	return ret;
}

kal_uint8 track_get_muc_sta(void)
{
	if(track_get_violue_status(down_voice_id[0])) return 1;
	if(track_get_violue_status(down_voice_id[1])) return 1;
	if(track_get_violue_status(down_voice_id[2])) return 1;
	return 0;

}

//------------------蓝牙密码转换
void bt_pass_change_d_s(kal_uint8 * data_d,kal_uint8 * data_s,kal_uint8 type)
{

	int i;
	int n = 0;
	if(type == 1)//转为字符串
	{
		for(i = 0 ; i < 16 ; i++)
		{
    		sprintf(data_s+n,"%03d",data_d[i]);
    		n+=3;
		}
		return ;
	}
	if(type == 0)//字符串每三位转数值
	{
		for(i = 0 ; i < 16 ; i++)
		{   
			kal_uint8 tmp[5]={0};
    		kal_uint8  value;
    		memcpy(tmp,&data_s[n],3);
    		n+=3;
    		value = atoi(tmp);
    		data_d[i]=value;
		}
		return ;
	}
}
 void track_set_on_off_volume(kal_uint8 value)
 {
	voice_volume = value;
 }
 //------------201914009
 kal_uint8 track_get_lesea_off_sta(kal_uint8 value)
 {
	if(value != 99)
	{
		G_realtime_data.lesea_off_to_sta = value;
		Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
		
	}
	return G_realtime_data.lesea_off_to_sta;
 }

  kal_uint8 track_get_lesea_off_volume_sta(kal_uint8 value)
 {
	if(value != 99)
	{
		G_realtime_data.lesea_off_to_volume_sta = value;
		Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
	}
	return G_realtime_data.lesea_off_to_volume_sta;
 }


