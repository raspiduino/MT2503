#if defined(__NF2318__)

/*******************************************************************************************
 * Filename:track_cust_controller_protocol.c
 * Author :Liujw
 * Date :2017-08-01
 * Comment:7号电单车控制器串口通讯协议
 *通讯方式：串口通讯（TTL0V-5V）。 波特率：9600bps，8bit数据位，1位停止位，无校验位。
 * 2019-6-11 将锁电机变量改为全局变量，不用放在G_parameter里面
 ******************************************************************************************/
/**引用头文件**/
#include "track_cust.h"
#include "track_os_ell.h"
#include "track_cust_controller_protocol.h"
#include "track_fun_common.h"
/****************************************************************************
***局部变量定义
****************************************************************************/
#define __CONTROL_LOG__
static kal_uint8 desired_value = 240;
controller_data_struct cData = {0};
kal_uint8 controller_status = 0;
kal_uint16 controller_hall = 0;
static kal_uint8 counts_data_request = 0;
vehicle_status_struct vehicle_status = {0};
kal_uint8 controller_close_msg[130] = {0};
//static U8 Controller_Enable = 0;//控制器是否可用  1 不可用  0 可用
static U8 Controller_Enable = 1;
/****************************************************************************
***引用外部变量
****************************************************************************/
extern void track_fun_get_time(applib_time_struct *t, kal_bool isUtc, nvram_gps_time_zone_struct *zone);
extern void track_fun_reverse_32(kal_uint8 *dec, kal_uint32 src);
/****************************************************************************
***本地变量
****************************************************************************/
kal_uint8 set_ele_lock = 0;//0-不锁 1-锁
static int num_sta = 0;
/****************************************************************************
***本地函数
****************************************************************************/
void track_cust_controler_fault(kal_uint8 param);
void track_cust_controller_malfunction_alarm(kal_uint8 s_type);
/*static void track_cust_timet2(U8 *sendbuf)
{
    kal_uint32 sec = 0;
    sec = OTA_app_getcurrtime();
    track_fun_reverse_32(sendbuf, sec);
}*/
void track_cust_controller_close_msg_down(void)
{
    //static int num = 0;
    int status = 0;
    char data[15] = {0};
    applib_time_struct msg_time = {0};
    static kal_uint8 stat_1=0;
    static kal_uint8 stat_2=0;
    if(!set_ele_lock)
    {
		stat_1 = 0;
    }
    if((desired_value & 0x02) != 2)
    {
		stat_2 = 0;
    }

    if(G_parameter.ste_status.lease)
    {
        if((set_ele_lock) && (stat_1 == 0))
        {
            status = 1;
            stat_1 = 1;
            track_fun_get_time(&msg_time, KAL_TRUE, NULL);
            sprintf(data, "%02d%02d%02d%02d%02d%02d%d", msg_time.nYear % 100, msg_time.nMonth, msg_time.nDay,
                    msg_time.nHour, msg_time.nMin, msg_time.nSec, status);
            if((num_sta ) > 117)
            {
				num_sta = 0;
            }
            memcpy(controller_close_msg + num_sta, data, 13);
            num_sta += 13;
            //if(num_sta >= 130)
             //   num_sta = 0;
        }
        if(((desired_value & 0x02) == 2) && (stat_2 == 0))
        {
            status = 2;
            stat_2 = 1;
            track_fun_get_time(&msg_time, KAL_TRUE, NULL);

            sprintf(data, "%02d%02d%02d%02d%02d%02d%d", msg_time.nYear % 100, msg_time.nMonth, msg_time.nDay,
                    msg_time.nHour, msg_time.nMin, msg_time.nSec, status);
            if((num_sta ) > 117)
            {
				num_sta = 0;
            }
            memcpy(controller_close_msg + num_sta, data, 13);
            num_sta += 13;
            //if(num_sta >= 130)
                //num_sta = 0;
        }

    }

    //LOGH(L_APP, L_V5, controller_close_msg,130);
    //LOGD(L_APP, L_V5, "  === :%s",controller_close_msg);
}

//20191008
extern kal_uint8 track_get_xc_sta(kal_uint8 value);
void request_static_packet(void* param)
{
    kal_uint8 datareq[30];
    kal_uint8 limit = 0;
    kal_uint8 locked = 0;
    kal_uint8 mode = 0;
    kal_uint16 sum = 0;
    kal_uint8 sumL = 0, sumH = 0;
    kal_uint8 arg = (kal_uint8)param;

    datareq[0] = 0x4f;
    datareq[1] = 0x2a;
    datareq[2] = 0x66;
    datareq[3] = 0x03;
    if(99 == arg)
    {
        mode = G_parameter.ele_data.con_mode;
        mode = mode << 6;
        limit = G_parameter.ele_data.turn_limit;
        limit = limit << 3;
        locked = set_ele_lock;
        locked = locked << 1;
        datareq[4] = mode | limit | locked | Controller_Enable;
        desired_value = datareq[4];

    }
    else
    {
        datareq[4] = desired_value;
    }

    track_cust_controller_close_msg_down();//20190731
    //LOGD(L_BMS, L_V9, "%d,%d,%d,%02X", mode,limit,locked,datareq[4]);
    datareq[5] = cData.relativeCapacityPer;
    datareq[6] = 0x00;
    sum = datareq[1] + datareq[2] + datareq[3] + datareq[4] + datareq[5] + datareq[6];
    sumL = sum & 0x00ff;
    sumH = (sum >> 8) & 0x00ff;
    datareq[7] = sumL;
    datareq[8] = sumH;
    datareq[9] = 0x0d;
    datareq[10] = 0x0a;
    if(track_cust_status_acc() == 0)
    {
        counts_data_request = 0;
    }
    counts_data_request ++;
    if(counts_data_request >= 40)
    {
        track_cust_controller_alarm(1);
        //增加一个20s延时判断，20s后自动清空控制器数据
        track_cust_status_recover();
        counts_data_request = 0;
    }

#ifdef __CONTROL_LOG__
    LOGH2(L_BMS, L_V7, "", datareq, 11);
#endif
    U_PutUARTBytes(uart_port3, datareq, 11);
}

/******************************************************************************
 *  Function    -  track_cust_to_controller
 *
 *  Purpose     -  向控制器请求数据
 *
 *  Description -  cmd:固定为0x66,数据位数据是上次保留的值，首次的值默认纯电动，默认100%
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 2017-08-02,  Liujw  written
 * ----------------------------------------
*******************************************************************************/
#if 0//旧的通讯协议
void track_cust_to_controller(kal_uint8 cmd, kal_uint8 *data)
{
    kal_uint8 sendbuf[30];
    kal_uint8 sum = 0, sumL = 0, sumH = 0;
    int i = 0;
    sendbuf[0] = 0x4F;//起始字节
    sendbuf[1] = 0x2A;//地址字节
    sendbuf[2] = cmd;//命令
    sendbuf[3] = 0x03;//数据长度
    sendbuf[4] = data[0];
    sendbuf[5] = data[1];
    sendbuf[6] = data[2];
    //累加校验
    sum = sendbuf[1] + sendbuf[2] + sendbuf[3] + sendbuf[4] + sendbuf[5];
    sumL = sum & 0x0F;
    sumH = (sum >> 4);
    sendbuf[7] = sumL;
    sendbuf[8] = sumH;
    sendbuf[9] = 0x0D;
    sendbuf[10] = 0x0A;//结束符
    LOGH2(L_BMS, L_V1, "", sendbuf, 11);
}
#endif
/******************************************************************************
 *  Function    -  track_cust_controller_data_split
 *
 *  Purpose     -  透传数据拆分
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 2017-08-02,  Liujw  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_controller_data_split(kal_uint8 *data, int len, kal_uint8 cmd)
{
    //kal_uint8 *tmp;
    static kal_uint8 counts = 0;
    kal_uint8 vechileSpeed = 0;
    kal_uint8 brake = 0;//刹车
    kal_uint8 ele_sta = 0;//电机状态
    kal_uint8 locked_rotor = 0;//堵转保护
    kal_uint8 flying_car = 0;//防飞车保护
    kal_uint8 uder_voltage = 0;//防欠压保护
    kal_uint8 holzer_fault = 0;//电机霍尔故障
    kal_uint8 malfunction = 0;//转把故障
    kal_uint8 locked_ele = 0;//锁电机信号
    kal_uint8 turn_limit = 0;//转把限速状态
    kal_uint8 con_mode = 0;//控制器模式(电动，纯电动)
    kal_uint8 ecu_enable = 0;//ecu控制使能状态
    kal_uint8 holzer_stah = 0;//0.5 秒内三个霍尔变化的个数高字节
    kal_uint8 holzer_stal = 0;//0.5 秒内三个霍尔变化的个数低字节

    LOGH2(L_BMS, L_V8, "", data, len);
    //----------------20191008
    if(track_get_xc_sta(99) == 1)
    {
    	if(track_is_timer_run(TRACK_CUST_XC_CON_TIM))
    	tr_stop_timer(TRACK_CUST_XC_CON_TIM);
		LOGD(L_APP, L_V5, "---------------------->>>>>控制器已失能");
		return;
    }

    brake  = data[0] & 1;
    ele_sta = (data[0] & 2) >> 1;//锁电机 0  不锁 1
    locked_rotor = (data[0] >> 2) & 1;
    flying_car = (data[0] >> 3) & 1;
    uder_voltage = (data[0] >> 4) & 1;
    holzer_fault = (data[0] >> 5) & 1;
    malfunction = (data[0] >> 6) & 1;
    controller_status = data[0];
    ecu_enable = data[1] & 1;
    locked_ele = (data[1] >> 1) & 1;

    turn_limit = (data[1] >> 3) & 7;
    con_mode = (data[1] >> 6) & 3;

    holzer_stah = data[2];
    holzer_stal = data[3];
    controller_hall = ((holzer_stah & 0x00FF) << 8) | holzer_stal;
#if 0
    if(controller_hall > 0)
    {
        track_cust_hal_set();
    }
#endif
#ifdef __CONTROL_LOG__
    LOGD(L_BMS, L_V8, "brake:%d;ele_sta:%d;locked_rotor:%d;flying_car:%d;uder_voltage:%d;holzer_fault:%d;malfunction:%d;", brake, \
         ele_sta, locked_rotor, flying_car, uder_voltage, holzer_fault, malfunction);
    LOGC(L_BMS, L_V8, "ecu_enable:%d;locked_ele:%d;turn_limit:%d;con_mode:%d;holzer_stah:%d;holzer_stal:%d,hall:%d", ecu_enable, \
         locked_ele, turn_limit, con_mode, holzer_stah, holzer_stal, controller_hall);
#endif
#if 0
    if(brake == 1)
    {
        ;//LOGC(L_BMS, L_V8,  "当前处于刹车状态!");
    }
    if(ele_sta == 1)
    {
        ;//LOGC(L_BMS, L_V8,  "当前电机处于运行状态!");
    }
    if(ecu_enable == 1)
    {
        ;//LOGC(L_BMS, L_V8, "ECU使能控制，控制器不工作!");
    }
    if(locked_ele == 1)
    {
        ;//LOGC(L_BMS, L_V8,  "锁电机信号!");
    }
    if(turn_limit == 1)
    {
        ;//LOGC(L_BMS, L_V8, "转把限速70%%!");
    }
    else if(turn_limit == 2)
    {
        ;//LOGC(L_BMS, L_V8, "转把限速75%%!");
    }
    else if(turn_limit == 3)
    {
        ;//LOGC(L_BMS, L_V8, "转把限速80%%!");
    }
    else if(turn_limit == 4)
    {
        ;//LOGC(L_BMS, L_V8, "转把限速85%%!");
    }
    else if(turn_limit == 5)
    {
        ;//LOGC(L_BMS, L_V8, "转把限速90%%!");
    }
    else if(turn_limit == 6)
    {
        ;//LOGC(L_BMS, L_V8, "转把限速95%%!");
    }
    else if(turn_limit == 7)
    {
        ;//LOGC(L_BMS, L_V8, "转把限速100%%!");
    }
    if(con_mode == 3)
    {
        ;//LOGC(L_BMS, L_V8, "电动助力混合!");
    }
    else if(con_mode == 1)
    {
        ;//LOGC(L_BMS, L_V8, "纯助力!");
    }
    else if(con_mode == 2)
    {
        ;//LOGC(L_BMS, L_V8, "纯电动!");
    }
#endif
    G_parameter.ele_data.con_mode = con_mode;//保存模式
    G_parameter.ele_data.turn_limit = turn_limit;
    vechileSpeed = get_speed();
    vehicle_status.brake = brake;//刹车
    vehicle_status.ele_sta = ele_sta;//电机状态
    vehicle_status.locked_rotor =  locked_rotor;//堵转保护
    vehicle_status.flying_car =  flying_car;//防飞车保护
    vehicle_status.uder_voltage =  uder_voltage;//防欠压保护
    vehicle_status.holzer_fault =  holzer_fault;//电机霍尔故障
    vehicle_status.malfunction =  malfunction;//转把故障
    vehicle_status.locked_ele =  locked_ele;//锁电机信号
    vehicle_status.turn_limit =  turn_limit;//转把限速状态
    vehicle_status.con_mode =  con_mode;//控制器模式(电动，纯电动)
    vehicle_status.ecu_enable =  ecu_enable;//ecu控制使能状态
    vehicle_status.holzer_stah = holzer_stah;//0.5 秒内三个霍尔变化的个数高字节
    vehicle_status.holzer_stal =  holzer_stal;//0.5 秒内三个霍尔变化的个数低字节
    if(controller_hall != 0)
    {
        track_cust_vehicle_moving(4);
    }
    else
    {
		if(ele_sta == 0)
		track_cust_vehicle_moving(44);
    }
    //要存入NVRAM，以存储频率来确定是不是要存入重要参数结构体
    if(counts == 0)
    {
        counts ++;
    }
    else
    {
        counts = 0;
        track_cust_module_speed_limit(NULL, vechileSpeed);
    }
    track_cust_controler_fault(data[0]);
}

/******************************************************************************
 *  Function    -  track_cust_from_controller
 *
 *  Purpose     -  控制器请求数据解析
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 2017-08-02,  Liujw  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_from_controller(kal_uint8 *data, int len)
{
    kal_uint8 cmd;
    kal_uint16 sum;
    kal_uint8 suml, sumh;
    LOGH2(L_BMS, L_V8, "", data, len);
    if(len != 13)
    {
        LOGD(L_BMS, L_V5, "控制器数据长度错误!:%d", len);
        return;
    }
    if(*data == 0x4F && *(data + 1) == 0x2A && *(data + 12) == 0x0A && *(data + 11) == 0x0D)
    {
        cmd = *(data + 2);
    }
    else
    {
        LOGC(L_BMS, L_V5, "控制器返回数据内容错误!:%d", len);
        return;
    }
    sum = data[1] + data[2] + data[3] + data[4] + data[5] + data[6] + data[7] + data[8];
    suml = sum & 0x00ff;
    sumh = (sum >> 8) & 0x00ff;
    if(suml != data[9] || sumh != data[10])
    {
        LOGC(L_BMS, L_V5, "控制器返回数据crc校验错误！%X,%X sum=%X", data[9], data[10], sum);
        return;
    }
    LOGD(L_BMS, L_V1, "cmd:%d", cmd, *(data));
    if(data[5] != desired_value)
    {
        LOGC(L_BMS, L_V5, "控制器返回数据与期望值不一致,重新请求,不解析！D value=%X,N value=%X", desired_value, data[5]);
        if(G_parameter.ste_status.lease == 0)
        {
            request_static_packet((void*)1);
        }
        return;
    }
    else
    {
        ;//desired_value = 0xFF;
    }
    counts_data_request = 0;
    track_cust_controller_alarm(0);
    track_cust_controller_data_split(&data[4], 5, cmd);
    //增加一个20s延时判断，20s后自动清空控制器数据
    tr_start_timer(TRACK_CUST_CONTROLLER_DATA_RECOVER_TIMER_ID, 20 * 1000, track_cust_status_recover);
}
void track_cust_controller_data_init()
{
    if(G_parameter.ste_status.lease == 1)//(track_cust_status_acc() && G_parameter.ste_status.lease == 1)
    {
        request_static_packet((void*)99);

        tr_start_timer(TRACK_CUST_CONTROLLER_DATA_TIMER_ID, 500, track_cust_controller_data_init);
    }
}
void track_cust_cotroller_alarm(void *param)
{
    kal_uint8 done = (kal_uint8)param;
    if(done == 1)
    {
        request_static_packet((void*)99);
    }
    if(track_acc_status((void*)3))
    {
        track_start_timer(TRACK_CUST_CONTROLLER_DATA_TIMER_ID, 500, track_cust_cotroller_alarm, (void*)1);

    }
}
/*//1.18版本去掉整体报警，增加故障明细报警
void track_cust_controller_fault_alarm(void* param)
{
    kal_uint8 arg = (kal_uint8)param;
    static kal_bool iswrite = KAL_FALSE;
    kal_uint8 position = 0;
    if(arg && !iswrite)
    {
        track_cust_N07_paket_04(ALARM_VEHICLE_FAULT, 0x01);
        iswrite = KAL_TRUE;
        position = 1;
    }
    else if(arg == 0 && iswrite)
    {
        track_cust_N07_paket_04(ALARM_VEHICLE_FAULT, 0x00);
        iswrite = KAL_FALSE;
        position = 1;
    }
    if(position == 1)
    {
        track_cust_paging_command();//上传定位点
    }
}*/
void track_cust_controler_fault(kal_uint8 param)
{
    kal_uint8 alarm_status = 0;
    alarm_status = param >> 2;
    LOGD(L_BMS, L_V5, "%d", alarm_status);

    track_cust_controller_malfunction_alarm(alarm_status);
    /*static kal_uint8 parameters[5];

    parameters[0] = (param >> 2) & 1;
    parameters[1] = (param >> 3) & 1;
    parameters[2] = (param >> 4) & 1;
    parameters[3] = (param >> 5) & 1;
    parameters[4] = (param >> 6) & 1;
    if(parameters[0] == 1 || parameters[1] == 1 || parameters[2] == 1 || parameters[3] == 1 || parameters[4] == 1)
    {
        LOGD(L_BMS, L_V6, "控制器故障:%d,%d,%d,%d,%d", parameters[0], parameters[1], parameters[2], parameters[3], parameters[4]);
        if(!track_is_timer_run(TRACK_CUST_CONTROLLER_FAULT_ALARM_DELAY_TIMER_ID))
        {
            track_start_timer(TRACK_CUST_CONTROLLER_FAULT_ALARM_DELAY_TIMER_ID, 1000, track_cust_controller_fault_alarm, (void *)1);
        }
    }
    else
    {
        if(!track_is_timer_run(TRACK_CUST_CONTROLLER_FAULT_ALARM_DELAY_TIMER_ID))
        {
            LOGD(L_BMS, L_V5, "控制器无故障:%d,%d,%d,%d,%d", parameters[0], parameters[1], parameters[2], parameters[3], parameters[4]);
            track_start_timer(TRACK_CUST_CONTROLLER_FAULT_ALARM_DELAY_TIMER_ID, 1000, track_cust_controller_fault_alarm, (void *)0);
        }
    }
*/
}
void track_cust_get_controller_data(vehicle_status_struct *v_status)
{
    memcpy(v_status, &vehicle_status, sizeof(vehicle_status_struct));
}
/*
**收到控制器数据20s后，将数据恢复默认
*/
void track_cust_status_recover(void)
{
    static U8 shock_tmp = 0;
    LOGD(L_BMS, L_V5, "*************recover hall***************");
    tr_stop_timer(TRACK_CUST_CONTROLLER_DATA_RECOVER_TIMER_ID);
    vehicle_status.ele_sta = 0;//电机状态
    vehicle_status.holzer_stah = 0;//0.5 秒内三个霍尔变化的个数高字节
    vehicle_status.holzer_stal =  0;//0.5 秒内三个霍尔变化的个数低字节
    controller_hall = 0;
    //track_cust_clear_speed();//将速度清零
    get_speed();
    if(track_cust_get_limit_status() >= 1)
    {
        track_cust_module_speed_limit(NULL, 0);
    }
    shock_tmp = track_cust_get_shock();
    LOGD(L_APP, L_V1, "shock_tmp:%d", shock_tmp);
    if((shock_tmp & 1) == 1 || track_cust_wheel_state() == KAL_TRUE) //认为有震动或者震动传感器没有坏
    {
        LOGD(L_APP, L_V1, "not shock or sensor fail! %d,%d", shock_tmp, track_cust_wheel_state());
    }
    else
    {
        tr_start_timer(TRACK_CUST_VEHICLE_LEASE_OFF_NO_SHOCK_TIMER_ID, 10 * 1000, track_cust_shock_overtime);
    }
}
U8 track_get_hal(void)
{
    LOGD(L_APP, L_V5, "hal_h:%d,hal_l:%d", vehicle_status.holzer_stah, vehicle_status.holzer_stal);
    if(vehicle_status.holzer_stah != 0 || vehicle_status.holzer_stal != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void track_cust_controller_malfunction_alarm(kal_uint8 s_type)
{
    kal_uint8 s_alarm = 2;
    //static kal_uint8 alarm_type[5] = {0};//0x22 堵转保护 0x23 防飞车保护 0x24 欠压保护  0x25 电机霍尔故障 0x26  转把故障
    //controller_alarm_type 代替 alarm_type
    //G_realtime_data.controller_alarm_type
    //有同时出发的报警，用if单独判断好一点
    LOGD(L_BMS, L_V5, "---------> CONTROLLER ALARM s_type:%d", s_type);
    if((s_type & 1) || G_realtime_data.controller_alarm_type[0] == 1) //堵转保护
    {
        if(G_realtime_data.controller_alarm_type[0] == 0) //未触发报警
        {
            s_alarm = 1;
            G_realtime_data.controller_alarm_type[0] = 1;
        }
        else if((s_type & 1) == 0 /*&& alarm_type[0] == 1*/)
        {
            s_alarm = 0;
            G_realtime_data.controller_alarm_type[0] = 0;
        }
        if(s_alarm != 2)
            track_cust_N07_paket_04(ALARM_CONTROLLER_LOCKED_ROTOR, s_alarm);
        s_alarm = 2;
    }
    if((s_type & 2) || G_realtime_data.controller_alarm_type[1] == 1)//防飞车保护
    {
        if(G_realtime_data.controller_alarm_type[1] == 0) //未触发报警
        {
            s_alarm = 1;
            G_realtime_data.controller_alarm_type[1] = 1;
        }
        else if((s_type & 2) == 0 /*&& alarm_type[1] == 1*/)
        {
            s_alarm = 0;
            G_realtime_data.controller_alarm_type[1] = 0;
        }
        if(s_alarm != 2)
            track_cust_N07_paket_04(ALARM_CONTROLLER_FLYING_CAR, s_alarm);
        s_alarm = 2;
    }
    if((s_type & 4) || G_realtime_data.controller_alarm_type[2] == 1)//欠压保护
    {
        if(G_realtime_data.controller_alarm_type[2] == 0) //未触发报警
        {
            s_alarm = 1;
            G_realtime_data.controller_alarm_type[2] = 1;
        }
        else if((s_type & 4) == 0 /*&& alarm_type[2] == 1*/)
        {
            s_alarm = 0;
            G_realtime_data.controller_alarm_type[2] = 0;
        }
        if(s_alarm != 2)
            track_cust_N07_paket_04(ALARM_CONTROLLER_UNDER_VOLTAGE, s_alarm);
        s_alarm = 2;
    }
    if((s_type & 8) || G_realtime_data.controller_alarm_type[3] == 1)//电机霍尔故障
    {
        if(G_realtime_data.controller_alarm_type[3] == 0) //未触发报警
        {
            s_alarm = 1;
            G_realtime_data.controller_alarm_type[3] = 1;
        }
        else if((s_type & 8) == 0 /*&& alarm_type[3] == 1*/)
        {
            s_alarm = 0;
            G_realtime_data.controller_alarm_type[3] = 0;
        }
        if(s_alarm != 2)
            track_cust_N07_paket_04(ALARM_CONTROLLER_HOLZER_FAULT, s_alarm);
        s_alarm = 2;
    }
    if((s_type & 16)  || G_realtime_data.controller_alarm_type[4] == 1)//放电电流保护
    {
        if(G_realtime_data.controller_alarm_type[4] == 0) //未触发报警
        {
            s_alarm = 1;
            G_realtime_data.controller_alarm_type[4] = 1;
        }
        else if((s_type & 16) == 0 /*&& alarm_type[4] == 1*/)
        {
            s_alarm = 0;
            G_realtime_data.controller_alarm_type[4] = 0;
        }
        if(s_alarm != 2)
            track_cust_N07_paket_04(ALARM_CONTROLLER_MALFUNCTION, s_alarm);
        s_alarm = 2;
    }
   // if(iswrite)
    {
        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
    }
}

#endif

void test_desired_value(int value , int type)
{
    if(type == 0)
    {
        set_ele_lock = value ;
    }
    if(type == 1)
    {
        desired_value = value ;
    }

    LOGD(L_APP, L_V5, "set_ele_lock : %d ,desired_value : %d", set_ele_lock, desired_value);


}
void clear_vaule_conn_data(void)
{
	num_sta = 0;
	memset(controller_close_msg, 0x00 ,130);
}
void track_cust_controller_enable(U8 enable)
{
	Controller_Enable = enable;
	
	LOGD(L_APP, L_V5, "%d",Controller_Enable);
}
