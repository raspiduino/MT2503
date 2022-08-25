#if defined(__BMS_PHYLION__)
/****************************************************************************
***file author: Liujw
***creat date:2017-11-10
***introduction:
****************星恒电池BMS通讯协议
****************************************************************************/
#include "track_cust.h"
#include "c_vector.h"
/****************************************************************************
***宏定义
****************************************************************************/
#define BMS_CMD_NUM 17//15
//#define __BMS_TEST__
#define __BMS_LOG__
/****************************************************************************
***枚举
****************************************************************************/

typedef enum
{
    bms_cmd1 = 0x08,//获取电池温度
    bms_cmd2 = 0x09,//电池总电压
    bms_cmd3 = 0x0A,//实时电流
    bms_cmd4 = 0x0D,//相对容量百分比
    bms_cmd5 = 0x0E,//绝对容量百分比
    bms_cmd6 = 0x0F,//剩余容量
    bms_cmd7 = 0x10,//满电电容
    bms_cmd8 = 0x17,//循环次数
    bms_cmd9 = 0x24,//1-7电池电压
    bms_cmd10 = 0x25,//8-14电池电压
    bms_cmd11 = 0x47,//当前充电间隔时间
    bms_cmd12 = 0x48,//最大充电间隔时间
    bms_cmd13 = 0x7E,//读写成品条形码
    bms_cmd14 = 0x7F,//版本号
    bms_cmd15 = 0x20,//电池组制造厂名字
    bms_cmd16 = 0x23,//获取电池状态
    bms_cmd17 = 0x1D,//电控锁开关
    bms_max			//最大指令集合
} bms_cmd_enum; //bms指令集

/****************************************************************************
***静态变量
****************************************************************************/
kal_uint8 bmscmd[BMS_CMD_NUM] = {0x08, 0x09, 0x0A, 0x0D, 0x0E, 0x0F, 0x10, 0x17, 0x24, 0x25, 0x47, 0x48, 0x7E, 0x7F, 0x20,0x23, 0x1D};
static int bmsinfoup = 0;
static int readall = 0;
static controller_data_struct bmsDataTemp = {0};
static U8 isreading = 0;// 1 一个循环已经开始 0 未开始或者结束

//201904
static int num_baojing = 0; //上报BMS报警
static int num_bmsb_send = 0; //发送次数
static int num_bmsb_read = 0; //接收次数
static int baojingbiaozhi = 0; //报警标志为
static int ii = 99; //2019
//201904

//标记电池SN是16位还是20位
static kal_uint8 battery_sn = 0;

/****************************************************************************
***引用变量
****************************************************************************/
extern controller_data_struct cData;

/****************************************************************************
***引用函数
****************************************************************************/
extern void track_cust_ele_off_gpio(void* arg);
extern void track_cust_restart(kal_uint8 mode, kal_uint32 sec);
/****************************************************************************
***本地函数
****************************************************************************/
void track_cust_bms_codebar_message(kal_uint8 *msg);
extern kal_uint8 track_bms_data_send(void* arg);


//201904
void track_msg_get_bms(void);
void track_msg_get_bms_make(void);
void if_same_msg(void);
void track_cust_bms_command(void);
//201904
void track_cust_bms_status_alarm(kal_uint8 s_type);
//获取电池序列号的16还是20位的标志 0 16  1 20位
kal_uint8 get_bett_sn(kal_uint8 value);//返回电磁SN是16还是20位的标志


U8 track_cust_bms_reading()
{
    return isreading;
}

//201904
//fghjkltghjklghjk从新获取BMS信息
void track_msg_get_bms(void)
{
    ii = 0;
    LOGD(L_APP, L_V1, "");
    track_cust_bms_upload(0);
    //isreading = 0;
    if(track_is_timer_run(TRACK_CUST_BMS_CMD_TIMER_ID))
    {
        tr_stop_timer(TRACK_CUST_BMS_CMD_TIMER_ID);
    }
    track_cust_bms_command();


}
//kkkkkkk换电池之后，一切从新开始获取BMS信息以及报警
void track_msg_get_bms_make(void)
{
    LOGD(L_APP, L_V1, "");

    num_baojing = 0; //上报BMS报警
    num_bmsb_send = 0; //发送次数
    num_bmsb_read = 0; //接收次数
    baojingbiaozhi = 0; //报警标志为
    track_msg_get_bms();
}
//kkkkkk对于两次都没有完整的BMS信息，进行判断，有两次进行报警

void if_same_msg(void)
{
    LOGD(L_APP, L_V1, "BMS Message,read:%d,send:%d,num_baojing:%d,isreading:%d", num_bmsb_read, num_bmsb_send, num_baojing, isreading);

    if(num_bmsb_read >= num_bmsb_send)
    {
        num_bmsb_send = 0;
        num_bmsb_read = 0;
        num_baojing = 0;
        if(baojingbiaozhi == 1)
        {
            baojingbiaozhi = 0;

            track_cust_N07_paket_04(ALARM_BMS_WARNING, 0x00);
        }
        return;
    }
    if(num_bmsb_read < num_bmsb_send)//num_bmsb_send 必须是15次
    {
        num_bmsb_send = 0;
        num_bmsb_read = 0;
        num_baojing++;
        if(num_baojing < 2)
        {
            track_msg_get_bms();
            return;
        }
    }
    LOGD(L_APP, L_V1, "BMS Message,baojingbiaozhi:%d", baojingbiaozhi);
    if(num_baojing == 2 && baojingbiaozhi == 0) //两次未收到完整的BMS，进行BMS报警
    {
        num_baojing = 0;
        baojingbiaozhi = 1; //只报警一次
        num_bmsb_read = 0;//报警之后把读取次数清零
        track_cust_N07_paket_04(ALARM_BMS_WARNING, 0x01);
    }

}


//201904


int track_cust_bms_upload(int param)
{
    if(param != 99)
    {
        bmsinfoup = param;
    }
    return bmsinfoup;
}
int track_cust_bms_read_all(U8 arg)
{
    if(arg != 99)
    {
        readall = arg;
    }
    return readall;
}
static kal_uint16 checksum(kal_uint8 *srcdata, kal_uint8 len)
{
    int i = 0;
    kal_uint16 crc = 0;
    for(i = 0; i < len; i++)
    {
        crc += srcdata[i];
        //#if defined(__BMS_LOG__)
        //LOGD(L_BMS, L_V8, "crc:%X,src", crc, srcdata[i]);
        //#endif
    }
    return crc;
}
/**
**Author:Liujw Date:2017-11-13
**Function name :track_cust_bms_data_req
**Description :请求BMS数据
**/
void track_cust_bms_data_req(kal_uint8 cmd)
{
    kal_uint8 sendbuf[30];
    kal_uint8 sumL = 0, sumH = 0;
    kal_uint16 sum = 0;
    int i = 0;
    sendbuf[0] = 0x3A;//起始字节
    sendbuf[1] = 0x16;//地址字节
    sendbuf[2] = cmd;//命令
    sendbuf[3] = 0x01;//数据长度
    sendbuf[4] = 0x00;
    //累加校验
    sum = sendbuf[1] + sendbuf[2] + sendbuf[3] + sendbuf[4];
    sumL = sum & 0x00FF;
    sumH = (sum >> 8);
    sendbuf[5] = sumL;
    sendbuf[6] = sumH;
    sendbuf[7] = 0x0D;
    sendbuf[8] = 0x0A;//结束符
    LOGH2(L_BMS, L_V6, "", sendbuf, 9);
    U_PutUARTBytes(uart_port1, sendbuf, 9);//uart_port3

}
/**
**Author:Liujw Date:2017-11-13
**Function name :track_cust_bms_data_analyze
**Description :拆分原始数据，赋值结构体 cData
**/
static void track_cust_bms_data_analyze(kal_uint8 *data, kal_uint8 cmd, kal_uint16 len)
{
#if defined(__BMS_TEST__)
    kal_uint8 bmslog[15];
#endif
    kal_uint8 batTeamState[8] = 0;//电池组状态信息
    static kal_uint8 read_state = 0;
    kal_uint8 tmp[2];
    int i = 0;
    //调戏码不足20的补4位0
    kal_uint8 add_sn[4]={0};
    LOGH2(L_BMS, L_V8, "", data, len);
    //LOGD(L_BMS, L_V8, "cmd:%0.2X", cmd);
    switch(cmd)
    {
        case 0x08://电池组内部温度
            bmsDataTemp.temperature[1] = *(data + i);
            i += 1;
            bmsDataTemp.temperature[0] = *(data + i);
#if defined(__BMS_LOG__)
            LOGD(L_BMS, L_V5, "电池内部温度0x%02X,0x%02X", bmsDataTemp.temperature[0], bmsDataTemp.temperature[1]);
#endif
            if(read_state == 0) read_state = 1;
            break;
        case 0x09://电池组总电压
            bmsDataTemp.totalValtage[1] = *(data + i);
            i += 1;
            bmsDataTemp.totalValtage[0] = *(data + i);
#if defined(__BMS_LOG__)
            LOGD(L_BMS, L_V5, "电池组总电压0x%02X,0x%02X", bmsDataTemp.totalValtage[0], bmsDataTemp.totalValtage[1]);
#endif
            break;
        case 0x0A://实时电流
            bmsDataTemp.currentL = *(data + i);//tmp[0] = *(data + i);
            i += 1;
            bmsDataTemp.currentH = *(data + i);//tmp[1] = *(data + i);
#if defined(__BMS_LOG__)
            LOGD(L_BMS, L_V5, "实时电流0x%02X,0x%02X", bmsDataTemp.currentH, bmsDataTemp.currentL);
#endif
            break;
        case 0x0D://相对容量百分比
            bmsDataTemp.relativeCapacityPer = *(data + i);
            LOGD(L_BMS, L_V5, "相对容量百分比0x%02X", bmsDataTemp.relativeCapacityPer);
            break;
        case 0x0E://绝对容量百分比
            bmsDataTemp.absoluteCapacityPer = *(data + i);
#if defined(__BMS_LOG__)
            LOGD(L_BMS, L_V5, "绝对容量百分比0x%02X", bmsDataTemp.absoluteCapacityPer);
#endif
            break;
        case 0x0F://剩余容量
            bmsDataTemp.leftCapatiryL = *(data + i);
            i += 1;
            bmsDataTemp.leftCapatiryH = *(data + i);
#if defined(__BMS_LOG__)
            LOGD(L_BMS, L_V5, "剩余容量0x%02X,0x%02X", bmsDataTemp.leftCapatiryH, bmsDataTemp.leftCapatiryL);
#endif
            break;
        case 0x10://满电容量
            bmsDataTemp.absoluteFullCapacity[1] = *(data + i);
            i += 1;
            bmsDataTemp.absoluteFullCapacity[0] = *(data + i);
#if defined(__BMS_LOG__)
            LOGD(L_BMS, L_V5, "满电容量0x%02X,0x%02X", bmsDataTemp.absoluteFullCapacity[0], bmsDataTemp.absoluteFullCapacity[1]);
#endif
            break;
        case 0x17://电池组循环使用次数
            bmsDataTemp.circulationOfBat[1] = *(data + i);
            i += 1;
            bmsDataTemp.circulationOfBat[0] = *(data + i);
#if defined(__BMS_LOG__)
            LOGD(L_BMS, L_V5, "电池组循环使用次数0x%02X,0x%02X", bmsDataTemp.circulationOfBat[0], bmsDataTemp.circulationOfBat[1]);
#endif
            break;
        case 0x24://1~7节电池电压
            memcpy(&bmsDataTemp.valtage[0], &data[i], 14);
#if defined(__BMS_LOG__)
            LOGD(L_BMS, L_V5, "1-7节电池电压0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X", bmsDataTemp.valtage[0], bmsDataTemp.valtage[1], \
                 bmsDataTemp.valtage[2], bmsDataTemp.valtage[3], bmsDataTemp.valtage[4], bmsDataTemp.valtage[5], bmsDataTemp.valtage[6], bmsDataTemp.valtage[7], bmsDataTemp.valtage[8], bmsDataTemp.valtage[9], \
                 bmsDataTemp.valtage[10], bmsDataTemp.valtage[11], bmsDataTemp.valtage[12], bmsDataTemp.valtage[13]);
#endif
            break;
        case 0x25://8~14节电池电压
            memcpy(&bmsDataTemp.valtage[14], &data[i], 14);
#if defined(__BMS_LOG__)
            LOGD(L_BMS, L_V5, "8-14节电池电压0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X", bmsDataTemp.valtage[14], bmsDataTemp.valtage[15], \
                 bmsDataTemp.valtage[16], bmsDataTemp.valtage[17], bmsDataTemp.valtage[18], bmsDataTemp.valtage[19], bmsDataTemp.valtage[20], bmsDataTemp.valtage[21], bmsDataTemp.valtage[22], bmsDataTemp.valtage[23], \
                 bmsDataTemp.valtage[24], bmsDataTemp.valtage[25], bmsDataTemp.valtage[26], bmsDataTemp.valtage[27]);
#endif
            break;
        case 0x47://当前充电间隔时间
            bmsDataTemp.chargeInterval[1] = *(data + i);
            i += 1;
            bmsDataTemp.chargeInterval[0] = *(data + i);
#if defined(__BMS_LOG__)
            LOGD(L_BMS, L_V5, "当前充电间隔时间0x%02X,0x%02X", bmsDataTemp.chargeInterval[0], bmsDataTemp.chargeInterval[1]);
#endif
            break;
        case 0x48://最大充电间隔时间
            bmsDataTemp.largeChargeInterval[1] = *(data + i);
            i += 1;
            bmsDataTemp.largeChargeInterval[0] = *(data + i);
#if defined(__BMS_LOG__)
            LOGD(L_BMS, L_V5, "最大充电间隔时间0x%02X,0x%02X", bmsDataTemp.largeChargeInterval[0], bmsDataTemp.largeChargeInterval[1]);
#endif
            break;
        case 0x7E://读写成品条形码
        	if(len == 20)
        	{	if(get_bett_sn(99) != 1)
        		{
        			get_bett_sn(1);
        		}
				memcpy(&bmsDataTemp.barCode[0], &data[i], 20);
        	}
        	else if(len == 16)
        	{	if(get_bett_sn(99) != 0)
        		{
        			get_bett_sn(0);
        		}
            	memcpy(&bmsDataTemp.barCode[0], &data[i], 16);
            	memcpy(&bmsDataTemp.barCode[16], add_sn, 4);
            }
            track_cust_bms_codebar_message(&bmsDataTemp.barCode[0]);
#if defined(__BMS_LOG__)
            LOGD(L_BMS, L_V5, "读写成品条形码0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X", bmsDataTemp.barCode[0]\
                 , bmsDataTemp.barCode[1], bmsDataTemp.barCode[2], bmsDataTemp.barCode[3], bmsDataTemp.barCode[4], bmsDataTemp.barCode[5], bmsDataTemp.barCode[6], bmsDataTemp.barCode[7], bmsDataTemp.barCode[8]\
                 , bmsDataTemp.barCode[9], bmsDataTemp.barCode[10], bmsDataTemp.barCode[11], bmsDataTemp.barCode[12], bmsDataTemp.barCode[13], bmsDataTemp.barCode[14], bmsDataTemp.barCode[15]);
#endif
            break;
        case 0x7F://读版本号
            bmsDataTemp.versionNum[0] = *(data + i);
            i += 1;
            bmsDataTemp.versionNum[1] = *(data + i);
#if defined(__BMS_LOG__)
            LOGD(L_BMS, L_V5, "读版本号0x%02X,0x%02X", bmsDataTemp.versionNum[0], bmsDataTemp.versionNum[1]);
#endif
            break;
        case 0x20://读电池组制造厂名称
            memset(&bmsDataTemp.valtageManufacturer[0], 0, 16);
            if(len > 16) len = 16;
            memcpy(&bmsDataTemp.valtageManufacturer[0], &data[i], len);
#if defined(__BMS_LOG__)
            LOGD(L_BMS, L_V5, "读电池组制造厂名称0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X", bmsDataTemp.valtageManufacturer[0]\
                 , bmsDataTemp.valtageManufacturer[1], bmsDataTemp.valtageManufacturer[2], bmsDataTemp.valtageManufacturer[3], bmsDataTemp.valtageManufacturer[4], bmsDataTemp.valtageManufacturer[5], bmsDataTemp.valtageManufacturer[6], bmsDataTemp.valtageManufacturer[7], bmsDataTemp.valtageManufacturer[8], bmsDataTemp.valtageManufacturer[9]\
                 , bmsDataTemp.valtageManufacturer[10], bmsDataTemp.valtageManufacturer[11], bmsDataTemp.valtageManufacturer[12], bmsDataTemp.valtageManufacturer[13], bmsDataTemp.valtageManufacturer[14], bmsDataTemp.valtageManufacturer[15]);
#endif
            if(read_state == 1) read_state = 2;

            break;
        case 0x23:
            LOGD(L_BMS, L_V5, "获取电池状态");
            memcpy(batTeamState, &data[i], 8);
			track_cust_bms_status_alarm(batTeamState[1]);
            break;
        case 0x1D:
            LOGD(L_BMS, L_V5, "电控锁开关");
            break;
        default:
            break;

    }
    if(read_state == 2)//(cmd == 0x20)
    {
        read_state = 0;
        memcpy(&cData, &bmsDataTemp, sizeof(controller_data_struct));
        readall = 1;
        if(track_soc_login_status() && !bmsinfoup)
        {
            tr_stop_timer(TRACK_CUST_BMS_DATA_SEND_OVERTIME_TIMER_ID);
            track_start_timer(TRACK_CUST_BMS_DATA_SEND_OVERTIME_TIMER_ID, 1000, track_bms_data_send, (void*)0);
            //track_cust_N07_paket_03();
            bmsinfoup = 1;
        }
    }
}
/**
**function author:Liujw
**function name:track_cust_bms_data_receive ;Date :2017-11-10
**Description:接收BMS串口数据，拼包解析
HEX:cmd_bmscmd()
    3A 16 20 01 00 37 00 0D 0A


[16:34:28.943]收←◆[8]track_project_uart_receice_data_notify() port:2,len:18
HEX:track_cust_bms_data_receive()
    3A 16 20 0A 50 48 59 4C 49 4F 4E 20 47 58 22 03 0D 0A
**/
void track_cust_bms_data_receive(kal_uint8 *data, kal_uint16 len)
{
    kal_uint8 cmd = 0, addid = 0, cmdlen = 0;
    kal_uint8 i = 0, j = 0, k = 0, l = 0, m = 0;
    static kal_bool find = KAL_FALSE;
    static kal_uint32 t_len = 0;
    //static kal_uint8 buf[500];
    //kal_uint8 h_buf[100];
    kal_uint16 crc = 0;
    kal_uint8 c_l = 0, c_h = 0;
#if defined(__BMS_LOG__)
    LOGH2(L_OBD, L_V8, "", data, len);
#endif
    if(len <= 0) return;
#if 0
    if(t_len + len > 500)
    {
        memset(buf, 0, 500);
        t_len = 0;
        return;//出现这种情况，认为电池芯片出错
    }
    memcpy(&buf[t_len], data, len);
    t_len += len;
    for(i = 0; i < t_len; i++)
    {
        if(buf[i] == 0x3A)
        {
            k = i;
            find = KAL_TRUE;
        }
        if(buf[i-1] == 0x0D && buf[i] == 0x0A)
        {
            l = i;
            if(find)
            {
                m = l - k + 1;
                memcpy(h_buf, &buf[k], m);
                LOGH2(L_BMS, L_V6, "", h_buf, m);
                crc = checksum(&h_buf[1], m - 5);
                c_l = crc & 0xFF;
                c_h = crc >> 8;
                LOGD(L_BMS, L_V8, "CRC L:%2X,CRC H:%2X,%2X,%2X", c_l, c_h, h_buf[m-4], h_buf[m-3]);
                if(h_buf[m-3] == c_h && h_buf[m-4] == c_l)//校验通过
                {
                    cmd = h_buf[2];
                    cmdlen = h_buf[3];
                    track_cust_bms_data_analyze(&h_buf[4], cmd, cmdlen);
                }
            }
            find = KAL_FALSE;
        }

    }

    if(l + 1 < t_len)
    {
        kal_uint8 *tempbuf = NULL;
        int last = t_len - (l + 1);
        tempbuf = &buf[l+1];
        memset(buf, 0, 500);
        memcpy(buf, tempbuf, last);
        t_len = last;
        Ram_Free(tempbuf);
    }
    else
    {
        memcpy(buf, 0, 500);
        t_len = 0;
    }
#endif
    /*一下是正常一包一包接收代码，与上无关*/
    //调试代码
    if(data[0] != 0x3A)
    {
        return;
    }
    if(data[i] == 0x3A)
    {
        addid = data[i+1];
        cmd = data[i+2];
        cmdlen = data[i+3];
    }

    LOGD(L_BMS, L_V5, "cmd:%02X,addid:%x,cmdlen:%x", cmd, addid, cmdlen);
    j = cmdlen + 3;
    j += 2;
    if(data[j+1] == 0x0D && data[j+2] == 0x0A)
    {
    //接收到0xF0在一秒后进行重启
    	if(cmd == 0x55)
    	{	

    		track_cust_bms_data_req(0x55);
    		track_cust_restart(77, 3);
    		return;
    	}
        num_bmsb_read++;//201904

        i += 4;
        track_cust_bms_data_analyze(data + i, cmd, cmdlen);
    }

}
void track_cust_bms_command(void)
{
    static kal_uint8 notsleep = 0;
    static int i = 0;
    kal_uint16 interval = 0;
    if(G_realtime_data.sleep == 16)
    {
        LOGD(L_BMS, L_V5, "sleeping now!!!");
        return;
    }
    if(get_BmsUart() == 0)
    {
        LOGD(L_BMS, L_V5, "Message:BMS Uart init not ready!,%d", get_BmsUart());
        return;
    }

    //201904
    if(ii == 0)
    {
        i = ii;
        notsleep = 0;
    }

    if(i == 0)//循环开始，清零
    {
        ii = 99;//2019
        //isreading = 1;
        //应该将读取的技术在这里清零
        num_bmsb_read = 0;
        if(notsleep == 0)
        {
            track_drv_sleep_enable(SLEEP_OBD_MOD, FALSE);
            notsleep = 1;
            tr_start_timer(TRACK_CUST_BMS_CMD_TIMER_ID, 500, track_cust_bms_command);
            return;
        }
        else if(notsleep == 1)
        {
            notsleep = 2;
            memset(&bmsDataTemp, 0, sizeof(controller_data_struct));
            track_cust_bms_data_req(bmscmd[0]);
            tr_start_timer(TRACK_CUST_BMS_CMD_TIMER_ID, 500, track_cust_bms_command);
            return;
        }
    }
    LOGD(L_BMS, L_V5, "BMS GET i=%d,isreading:%d", i, isreading);
    if(i < BMS_CMD_NUM)
    {
        //if(i == 0)
        //{

        //isreading = 1;
        //}
        track_cust_bms_data_req(bmscmd[i]);
        i++;
        interval = 1;
    }
    else
    {
        num_bmsb_send = i;
        i = 0;
        interval = 120 * 3;
        memcpy(&cData, &bmsDataTemp, sizeof(controller_data_struct));
        track_drv_sleep_enable(SLEEP_OBD_MOD, TRUE);
        notsleep = 0;
        //isreading = 0;
    }
    tr_start_timer(TRACK_CUST_BMS_CMD_TIMER_ID, interval * 330, track_cust_bms_command);
    if(num_bmsb_send >= BMS_CMD_NUM)// && isreading == 0)
    {
        if_same_msg();
    }
}

void track_cust_bms_codebar_message(kal_uint8 *msg)
{
    int i = 0;
    static kal_bool isfirst = KAL_TRUE;
    kal_bool ischange = KAL_FALSE;
    static kal_uint8 codebar[20];
    kal_uint8 barCodetemp[20];
//	if(isfirst)
//	{
//		isfirst = KAL_FALSE;
//		return;
//	}
    //LOGS("%s",cData.barCode);
    memcpy(barCodetemp, &cData.barCode[0], 20);
    memcpy(codebar, msg, 20);

    LOGH(L_APP, L_V5, barCodetemp, 20);
    LOGH(L_APP, L_V5, codebar, 20);
    if(track_cust_bms_read_all(99) == 0)
    {
        return;
    }
    for(i = 0 ; i < 20; i++)
    {
        if(codebar[i] != barCodetemp[i])
        {
            ischange = KAL_TRUE;
            break;
        }
    }

    LOGD(L_BMS, L_V5, "%d", ischange);
    if(ischange)
    {
        track_cust_bms_upload(0);
        if(G_realtime_data.exbatlock != 1)
        {
            track_start_timer(TRACK_CUST_ELE_LOCK_DELAY_TIMER_ID, 60 * 1000, track_cust_ele_off_gpio, (void *)1);
        }
    }
}
void track_bms_struct_copy(controller_data_struct *c_data_struct)
{
    memcpy(c_data_struct, &cData, sizeof(controller_data_struct));
}
kal_uint8 track_bms_data_send(void* arg)
{
    static kal_uint8 up = 0;
    static U8 up_times = 0;
    kal_uint8 par = (kal_uint8)arg;
    if(par == 0) up = 0;
    LOGD(L_BMS, L_V5, "get bms data delay,send overtime");
    if(up == 0 && par == 0)
    {
        up = 1;//正在发送03包
        if(track_soc_login_status())
        {
            track_cust_N07_paket_03();
        }
        if(up_times < 2)
        {
            track_start_timer(TRACK_CUST_BMS_DATA_SEND_OVERTIME_TIMER_ID, 20000, track_bms_data_send, (void*)0);
            up_times ++;
        }
        else
        {
            up_times = 0;
        }
    }
    else if(par == 1 && up == 1)
    {
        up = 2;
        up_times = 0;
        tr_stop_timer(TRACK_CUST_BMS_DATA_SEND_OVERTIME_TIMER_ID);
        track_cust_bms_upload(1);
    }
    return up;
}

void track_cust_bms_status_alarm(kal_uint8 s_type)
{
    kal_uint8 s_alarm = 2;
    //static kal_uint8 alarm_type[7] = {0};//0x11 过压 0x12 低压 0x13 充电流 0x14 电池低温 0x15 一级过流 0x16 耳机过流 0x17 电池高温温度
    //G_realtime_data.bms_alarm代替alarm_type
    //有同时出发的报警，用if单独判断好一点
    LOGD(L_BMS, L_V5, "------------>BMS ALARM  s_type:%d",s_type);
    if((s_type & 1) || G_realtime_data.bms_alarm[0] == 1) //过压报警触发
    {
        if(G_realtime_data.bms_alarm[0] == 0) //未触发报警
        {
            s_alarm = 1;
            G_realtime_data.bms_alarm[0] = 1;
        }
        else if((s_type & 1) == 0 /*&& alarm_type[0] == 1*/)
        {
            s_alarm = 0;
            G_realtime_data.bms_alarm[0] = 0;
        }
        if(s_alarm != 2)
            track_cust_N07_paket_04(ALARM_BMS_COV, s_alarm);
        s_alarm = 2;
    }
    if((s_type & 2) || G_realtime_data.bms_alarm[1] == 1)//低压保护
    {
        if(G_realtime_data.bms_alarm[1] == 0) //未触发报警
        {
            s_alarm = 1;
            G_realtime_data.bms_alarm[1] = 1;
        }
        else if((s_type & 2) == 0 /*&& alarm_type[1] == 1*/)
        {
            s_alarm = 0;
            G_realtime_data.bms_alarm[1] = 0;
        }
        if(s_alarm != 2)
            track_cust_N07_paket_04(ALARM_BMS_CUV, s_alarm);
        s_alarm = 2;
    }
    if((s_type & 4) || G_realtime_data.bms_alarm[2] == 1)//充电电流保护
    {
        if(G_realtime_data.bms_alarm[2] == 0) //未触发报警
        {
            s_alarm = 1;
            G_realtime_data.bms_alarm[2] = 1;
        }
        else if((s_type & 4) == 0/*&& alarm_type[2] == 1*/)
        {
            s_alarm = 0;
            G_realtime_data.bms_alarm[2] = 0;
        }
        if(s_alarm != 2)
            track_cust_N07_paket_04(ALARM_BMS_OC, s_alarm);
        s_alarm = 2;
    }
    if((s_type & 8) || G_realtime_data.bms_alarm[3] == 1)//低温保护
    {
        if(G_realtime_data.bms_alarm[3] == 0) //未触发报警
        {
            s_alarm = 1;
            G_realtime_data.bms_alarm[3] = 1;
        }
        else if((s_type & 8) == 0 /*&& alarm_type[3] == 1*/)
        {
            s_alarm = 0;
            G_realtime_data.bms_alarm[3] = 0;
        }
        if(s_alarm != 2)
            track_cust_N07_paket_04(ALARM_BMS_TOVER2, s_alarm);
        s_alarm = 2;
    }
    if((s_type & 16) || G_realtime_data.bms_alarm[4] == 1)//放电电流保护
    {
        if(G_realtime_data.bms_alarm[4] == 0) //未触发报警
        {
            s_alarm = 1;
            G_realtime_data.bms_alarm[4] = 1;
        }
        else if((s_type & 16) == 0 /*&& alarm_type[4] == 1*/)
        {
            s_alarm = 0;
            G_realtime_data.bms_alarm[4] = 0;
        }
        if(s_alarm != 2)
            track_cust_N07_paket_04(ALARM_BMS_LEVEL1_OLOAD, s_alarm);
        s_alarm = 2;
    }
#if 0
    if(s_type & 16)//放电电流保护
    {
        if(alarm_type[5] == 0) //未触发报警
        {
            s_alarm = 1;
        }
        else if(s_type & 16 == 0 && alarm_type[5] == 1)
        {
            s_alarm = 0;
        }
        if(s_alarm != 2)
            track_cust_N07_paket_04(ALARM_BMS_LEVEL2_OLOAD, s_alarm);
    }
#endif
    if((s_type & 32) || G_realtime_data.bms_alarm[6] == 1)//放电电流保护
    {
        if(G_realtime_data.bms_alarm[6] == 0) //未触发报警
        {
            s_alarm = 1;
            G_realtime_data.bms_alarm[6] = 1;
        }
        else if((s_type & 32) == 0 /*&& alarm_type[6] == 1*/)
        {
            s_alarm = 0;
            G_realtime_data.bms_alarm[6] = 0;
        }
        if(s_alarm != 2)
            track_cust_N07_paket_04(ALARM_BMS_TOVER, s_alarm);
        s_alarm = 2;
    }
   // if(iswrite)
    {
        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
    }
}
#endif/*__BMS_PHYLION__*/

kal_uint8 get_bett_sn(kal_uint8 value)//返回电磁SN是16还是20位的标志
{
	if(value != 99)
	{
		battery_sn = value;
	}
	return battery_sn;
}

