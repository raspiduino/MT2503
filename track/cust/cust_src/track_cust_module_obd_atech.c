#if defined(__ATECH__)
/****************************************************************************
***file author: Liujw
***creat date:2017-10-31
***introduction:
****************Atech OBDII 模块通讯协议，包含OBDII与MCU通讯和MCU与平台协议
****************************************************************************/
#include "track_cust.h"
#include "c_vector.h"

/****************************************************************************
***静态变量
****************************************************************************/
static kal_uint16 serialnumber = 1;
/****************************************************************************
***引用外部函数
****************************************************************************/
extern void track_cust_packet_9B(kal_uint8 *data, kal_uint8 len);
/**
**
**/
static kal_uint16 get_sn()
{
    return serialnumber;
}
static kal_uint8 checksum(kal_uint8 *srcdata, int len)
{
    kal_uint8 cs = 0;
    int i = 0;
    do
    {
        cs = cs ^ srcdata[i];
        //LOGD(L_OBD, L_V5, "%x,%x", cs, srcdata[i]);
        i++;
    }
    while(i != len);
    LOGD(L_OBD, L_V5, "cs:%x,i:%d", cs, i);
    return cs;
}
static kal_uint8 track_cust_atech_req_transfer(kal_uint8 *srcdata, kal_uint8 *decdata, kal_uint8 len)
{
    int i = 0, j = 0;
    if(len <= 0) return;
    for(i = 0; i < len; i++)
    {
        if(srcdata[i] == 0x77)
        {
            decdata[j++] = 0x77;
            decdata[j] = 0x01;
        }
        else if(srcdata[i] == 0x78)
        {
            decdata[j++] = 0x77;
            decdata[j] = 0x02;
        }
        else if(srcdata[i] == 0x79)
        {
            decdata[j++] = 0x77;
            decdata[j] = 0x03;
        }
        else
        {
            decdata[j] = srcdata[i];
        }
        j++;
    }
    LOGD(L_OBD, L_V5, "j:%d,i:%d", j, i);
    return j;
}
/**
**function name :track_cust_atech_data_req()
**function author:Liujw
**introduction:use this function will get data from atech .cmd-command
**/
void track_cust_atech_data_req(kal_uint8 cmd, kal_uint8* param , kal_uint8 param_len, kal_uint8 sta)
{
    kal_uint8 psend[30];
    kal_uint8 desdata[30] = {0};
    int i = 0, j = 0;

    //包头 1字节
    psend[i++] = 0x78;
    //序列号 2字节
    psend[i++] = serialnumber >> 4;
    psend[i++] = serialnumber & 0x00ff;
    serialnumber ++;
	if(serialnumber == 0xFFFF)
	{
		serialnumber = 0;
	}
    //长度 1字节
    psend[i++] = 1/*sta*/ + 1/*cmd*/ + 1/*param len*/ + 1/*cs len*/ + param_len;
    //状态 1字节
    psend[i++] = sta;
    //命令 1字节
    psend[i++] = cmd;
    //命令内容 1字节 无命令则为0 尼玛为什么要给一个字节的长度
    if(param_len == 0)
        psend[i++] = 0x00;
    else
    {
        psend[i++] = param_len;
        for(j = 0; j < param_len; j++)
        {
            psend[i++] = param[j];
        }
    }
    //校验
    psend[i] = checksum(&psend[1], 6 + param_len);
    //转你妈的的义
    i = track_cust_atech_req_transfer(&psend[1], desdata, i);
    memcpy(&psend[1], desdata, i);
    i += 2;
    //结束符 0x79
    psend[i - 1] = 0x79;
    LOGD(L_OBD, L_V5, "i:%d", i);
    LOGH2(L_OBD, L_V5, "", psend, i);
    U_PutUARTBytes(uart_port3, psend, i);
}
void track_cust_atech_data_upload(kal_uint8 *data, kal_uint8 len)
{
    track_cust_packet_9B(data, len);
}
/**
**function name：track_cust_atech_data_analyze
**author :Liujw   Date:2017-11-1
**descriptor: Atech data analyze
**/
void track_cust_atech_data_analyze(kal_uint8 *data, kal_uint16 len)
{
    kal_uint8 cmd = 0xFF, sta = 0, sum = 0;
    int i  = 0;
    int cmd_len = 0, motortemp = 0, batteryfault = 0, L_F_wheel = 0, L_B_wheel = 0, R_F_wheel = 0, R_B_wheel = 0;
    //kal_uint8 data[100] = {0};
    LOGH2(L_OBD, L_V5, "", data, len);
    if(len <= 0) return;

    sta = data[3];
    cmd = data[4];
    LOGD(L_OBD, L_V5, "status:%x,cmd:%x", sta, cmd);
    switch(cmd)
    {
        case 0x01:
            LOGD(L_OBD, L_V5, "数据包返回结果:%d", sta); //数据包
            break;
        case 0x02:
            cmd_len = data[5];
            motortemp = data[6];
            LOGD(L_OBD, L_V5, "报警信息返回结果:%d,cmd length:%d", sta, cmd_len); //报警信息包
            if(motortemp & 1)
            {
                LOGD(L_OBD, L_V5, "电机及控制器过热报警指示灯灯亮:%d;\
									电机及控制器过热报警指示灯 灯灭:%d\
						", motortemp & 2, motortemp & 4);
            }
            else
            {
                LOGD(L_OBD, L_V5, "电机温度报警:无报警！");
            }
            batteryfault = data[7];
            if(batteryfault & 1)
            {
                LOGD(L_OBD, L_V5, "动力蓄电池故障报警指示灯");
            }
            else
            {
                LOGD(L_OBD, L_V5, "动力蓄电池故障报警指示灯:无报警！");
            }
            L_F_wheel = data[8];
            if(L_F_wheel != 0xFF)
            {
                LOGD(L_OBD, L_V5, "左前轮状态报警:");
                switch(L_F_wheel)
                {
                    case 0x00:
                        LOGD(L_OBD, L_V5, "正常！");
                        break;
                    case 0x01:
                        LOGD(L_OBD, L_V5, "快速降压！");
                        break;
                    case 0x02:
                        LOGD(L_OBD, L_V5, "低压！");
                        break;
                    case 0x03:
                        LOGD(L_OBD, L_V5, "高压！");
                        break;
                    case 0x04:
                        LOGD(L_OBD, L_V5, "错误！");
                        break;
                    default:
                        break;
                }
            }
            else
            {
                LOGD(L_OBD, L_V5, "左前轮状态报警:不支持！");
            }
            R_F_wheel = data[9];
            if(R_F_wheel != 0xFF)
            {
                LOGD(L_OBD, L_V5, "右前轮状态报警：");
                switch(R_F_wheel)
                {
                    case 0x00:
                        LOGD(L_OBD, L_V5, "正常！");
                        break;
                    case 0x01:
                        LOGD(L_OBD, L_V5, "快速降压！");
                        break;
                    case 0x02:
                        LOGD(L_OBD, L_V5, "低压！");
                        break;
                    case 0x03:
                        LOGD(L_OBD, L_V5, "高压！");
                        break;
                    case 0x04:
                        LOGD(L_OBD, L_V5, "错误！");
                        break;
                    default:
                        break;
                }
            }
            else
            {
                LOGD(L_OBD, L_V5, "右前轮状态报警:不支持！");
            }
            L_B_wheel = data[10];
            if(L_B_wheel != 0xFF)
            {
                LOGD(L_OBD, L_V5, "左后轮状态报警:");
                switch(L_B_wheel)
                {
                    case 0x00:
                        LOGD(L_OBD, L_V5, "正常！");
                        break;
                    case 0x01:
                        LOGD(L_OBD, L_V5, "快速降压！");
                        break;
                    case 0x02:
                        LOGD(L_OBD, L_V5, "低压！");
                        break;
                    case 0x03:
                        LOGD(L_OBD, L_V5, "高压！");
                        break;
                    case 0x04:
                        LOGD(L_OBD, L_V5, "错误！");
                        break;
                    default:
                        break;
                }
            }
            else
            {
                LOGD(L_OBD, L_V5, "左后轮状态报警:不支持！");
            }
            R_B_wheel = data[11];
            if(R_B_wheel != 0xFF)
            {
                LOGD(L_OBD, L_V5, "左前轮状态报警:");
                switch(R_B_wheel)
                {
                    case 0x00:
                        LOGD(L_OBD, L_V5, "正常！");
                        break;
                    case 0x01:
                        LOGD(L_OBD, L_V5, "快速降压！");
                        break;
                    case 0x02:
                        LOGD(L_OBD, L_V5, "低压！");
                        break;
                    case 0x03:
                        LOGD(L_OBD, L_V5, "高压！");
                        break;
                    case 0x04:
                        LOGD(L_OBD, L_V5, "错误！");
                        break;
                    default:
                        break;
                }
            }
            else
            {
                LOGD(L_OBD, L_V5, "右后轮状态报警:不支持！");
            }
            break;
        case 0x10:
            LOGD(L_OBD, L_V5, "整车设防返回结果:%d", sta); //整车设防
            break;
        case 0x11:
            LOGD(L_OBD, L_V5, "尾门解锁返回结果:%d", sta); //尾门解锁
            break;
        case 0x12:
            LOGD(L_OBD, L_V5, "寻车功能返回结果:%d", sta); //寻车功能
            break;
        case 0x13:
            LOGD(L_OBD, L_V5, "启动使能返回结果:%d", sta); //启动使能
            break;
        case 0x14:
            LOGD(L_OBD, L_V5, "中控锁控制返回结果:%d", sta); //中控锁控制
            break;
        case 0x15:
            LOGD(L_OBD, L_V5, "后备箱门开启返回结果:%d", sta); //后备箱门开启
            break;
        case 0x16:
            LOGD(L_OBD, L_V5, "左前窗升降返回结果:%d", sta); //左前车窗控制
            break;
        case 0x17:
            LOGD(L_OBD, L_V5, "开启空调返回结果:%d", sta); //开启空调
            break;
        default:
            ;
            break;
    }
	if(cmd != 0xFF)
    track_cust_atech_data_upload(data, len);
}
/**
**Author:Liujw Date:2017-11-25
**Descriptor：收到包的转义
**/
static kal_uint8 track_cust_atech_data_transfer(kal_uint8 *srcdata, kal_uint8 *decdata, kal_uint8 len)
{
    kal_uint8 t_len = 0;
    int i = 0, j = 0;
	
    if(len <= 0)
    {
        LOGD(L_OBD, L_V5, "转义原始数据源长度是:%d", len);
        return;
    }
    for(i = 0; i < len; i++)
    {
        if(srcdata[i] == 0x77 && srcdata[i+1] == 0x01)
        {
            decdata[j++] = 0x77;
            i++;
        }
        else if(srcdata[i] == 0x77 && srcdata[i+1] == 0x02)
        {
            decdata[j++] = 0x78;
            i++;
        }
        else if(srcdata[i] == 0x77 && srcdata[i+1] == 0x03)
        {
            decdata[j++] = 0x79;
            i++;
        }
        else
        {
            decdata[j++] = srcdata[i];
        }
    }
    t_len = j;
    LOGH2(L_OBD, L_V5, "", decdata, t_len);

    return t_len;
}
/**
**Author:Liujw Date:
**Descriptor:OBD数据接收函数
**包总长度= len+4(包头1+序号2+长度1)
**/

void track_cust_atech_data_receive(kal_uint8 *srcdata, kal_uint16 len)
{
    static kal_uint8 data[200];
    kal_uint8 adata[100];
    kal_uint8 temp[100];
    static kal_uint16 t_len = 0;
    int i = 0;
    kal_uint8 sta = 0, cmd = 0;
    kal_uint8 sum = 0;
    kal_uint8 alen = 0, msglen = 0, templen = 0;
    kal_uint16 l = 0, head = 0, end = 0;
    kal_bool find = KAL_FALSE;
    if(len <= 0) return;
    if(t_len + len > 200)
    {
        memset(data, 0, 200);
        t_len = 0;
        return;
    }
    //自己测试，加一个0x79
    //测试开始
#if 1
    memcpy(temp, srcdata, len);
    temp[len] = 0x79;
    //temp[13]= 0x77;temp[14]= 0x01;temp[15]= 0x77;temp[16]= 0x02;temp[17]= 0x77;temp[18]= 0x03;
    len += 1;
    memcpy(&data[t_len], temp, len);
    //测试结束
#else
    memcpy(&data[t_len], srcdata, len);//自己加79测试的时候关掉
#endif
    t_len = t_len + len;

    LOGH2(L_OBD, L_V5, "", data, t_len);
    for(i = 0; i < t_len; i++)
    {
        if(data[i] == 0x78 && find == KAL_FALSE)
        {
            head = i;
            find = KAL_TRUE;
            continue;
        }
        if(data[i] == 0x79 && find == KAL_TRUE)
        {
            end = i;//找到结束符下标
            //从头到尾拷贝到缓存buffer
            memset(adata, 0, 100);
            alen = end - head + 1;
            memcpy(adata, &data[head], alen); //从头下一位拷贝到结束符前一位
            l = end;

            LOGH2(L_OBD, L_V5, "", adata, alen);
            //要开始转义
            templen = track_cust_atech_data_transfer(&adata[1], temp, alen - 2);

            //解析数据
            msglen = temp[2];
            sum = checksum(temp, alen - 3); //减去头尾+校验位
            LOGD(L_OBD, L_V5, "%d,%d,校验值:%X,计算后的校验值:%X", msglen, alen, temp[templen-1], sum);
            if(sum == temp[templen-1])
            {
                sta = temp[3];
                cmd = temp[4];
                track_cust_atech_data_analyze(temp, templen);
            }
            LOGD(L_OBD, L_V5, "status:%X,CMD:%X", sta, cmd);
        }
    }
    LOGD(L_OBD, L_V5, "find:%d,l:%d", find, l);
    if(!find) return;//没有找到信息，不处理队列
    if(l + 1 < t_len)
    {
        kal_uint8 *tempbuf;
        kal_uint16 last = t_len - (l + 1);
        tempbuf = &data[l+1];
        memset(data, 0, 200);
        memcpy(data, tempbuf, last);
        t_len = last;
        Ram_Free(tempbuf);
    }
    else
    {
        memset(data, 0, 200);
        t_len = 0;
    }
}
/**
**开启空调
**/
static void atech_air_conditioner_open(kal_uint8 param1, kal_uint8 param2)
{
    kal_uint8 param[2] = {0};
    param[0] = param1;
    param[1] = param2;
    track_cust_atech_data_req(0x17, param, 2, 0x03);
}
/**
**车窗控制
**/
static void atech_all_window(kal_uint8 param1, kal_uint8 param2)
{
    kal_uint8 param[2] = {0};
    param[0] = param1;
    param[1] = param2;
    track_cust_atech_data_req(0x16, param, 2, 0x03);
}
/**
**后备箱门控制
**/
static void atech_trunk(kal_uint8 param)
{
    track_cust_atech_data_req(0x15, &param, 1, 0x03);
}
/**
**中控锁控制
**/
static void atech_central_control(kal_uint8 param)
{
    track_cust_atech_data_req(0x14, &param, 1, 0x03);
}
/**
**启动使能
**/
static void atech_enable_open(kal_uint8 param)
{
    track_cust_atech_data_req(0x13, &param, 1, 0x03);
}
/**
**寻车功能
**/
static void atech_find_car(kal_uint8 param)
{
    track_cust_atech_data_req(0x12, &param, 1, 0x03);
}
/**
**尾门解锁
**/
static void atech_behind_door(kal_uint8 param)
{
    track_cust_atech_data_req(0x11, &param, 1, 0x03);
}
/**
**整车设防
**/
static void atech_fortify(kal_uint8 param)
{
    track_cust_atech_data_req(0x10, &param, 1, 0x03);
}
/**
**报警查询
**/
static void atech_alarm()
{
    track_cust_atech_data_req(0x02, NULL, 0, 0x02);
}
/**
**参数查询
**/
//static
void atech_select_all()
{
    track_cust_atech_data_req(1, NULL, 0, 0x02);
}
/**
**
**/
void track_cust_atech_data_cmd(kal_uint8 cmd, kal_uint8 *param)
{
    kal_uint8 temp = cmd;
    LOGD(L_OBD, L_V5, "temp:%d", temp);
    switch(temp)
    {
        case 1:
            atech_select_all();
            break;
        case 2:
            atech_alarm();
            break;
        case 10:
            atech_fortify(param[0]);
            break;
        case 11:
            atech_behind_door(param[0]);
            break;
        case 12:
            atech_find_car(param[0]);
            break;
        case 13:
            atech_enable_open(param[0]);
            break;
        case 14:
            atech_central_control(param[0]);
            break;
        case 15:
            atech_trunk(param[0]);
            break;
        case 16:
            atech_all_window(param[0], param[1]);
            break;
        case 17:
            atech_air_conditioner_open(param[0], param[1]);
            break;
        default:
            ;
            break;
    }
}
#endif
