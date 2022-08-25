/****************************************************************************
***file author: Liujw
***creat date:2018-01-25
***introduction:
****************工作模式
****************运用加密 XxTEA加密方式，RSA加密方式，MD5加密方式
****************************************************************************/
#include "track_cust.h"
#include "c_vector.h"
#include "track_fun_XxTEA.h"
#include "track_cust_platform_N07.h"
/****************************************************************************
***宏定义
****************************************************************************/
#define GPIO_EXE_TIME_MIN 18    //实际使用是18*100
#define GPIO_EXE_TIME_MAX 30    //实际使用是30*100
#define UPLOADPOSITIONTIME 5000   //状态切换后多久上传定位点 5秒
/****************************************************************************
***外部变量
****************************************************************************/
extern kal_uint16 controller_hall;
/****************************************************************************
***枚举
****************************************************************************/
track_enum_sms_staus fly_staus = SMS_NORMAL_MODE; //记录SMS的状态，正常模式or 飞行模式
/****************************************************************************
***静态变量
****************************************************************************/
static kal_uint8 vehicle_moving = 0;//0bit 震动信号  1bit 轮动信号  2bit 霍尔是否输出
static kal_uint8 lease_desired = 2;//0 期望关锁 1 期望开锁 2 无期望
static kal_uint8 msgid[32] = {0};
static kal_uint8 msgidtmp[33] = {0};//存储同时接收到的相同操作的指令MSGID,第0个字节判断信息是否有效
static U8 is_flymode = 0;//是否进入全休眠
static U8 is_shock = 0;//00 震动过期 01 有震动  11 锁车时有震动 1000[8] 开锁超时后的关锁有震动 10000[16]有轮动 100000[32]有霍尔值
//static U8 playvoicefirst = 1;//标识开机播放开锁解锁语音 1 不播放
//static kal_uint16 lockCounts = 0,unlockCounts = 0,exBatLockCounts = 0,exBatUnlockCounts = 0;
static applib_time_struct unlocktime = {0};
static applib_time_struct locktime = {0};

static track_gps_data_struct *unlockgd = NULL;
static track_gps_data_struct *lockgd = NULL;
static kal_uint32 oncemileage = 0;
static kal_uint8 isRecovery = 0;//开机回复上次状态，标记起来不用去写nvram
//static U8 curr_acc = 2;//当前acc的状态
static kal_uint8 leaseVoiceId[3] = {0};
static kal_uint8 vehicle_moving_wheel = 3;//单独开后轮锁的判断条件0 满足 
static kal_uint8 lease_off_gps_sta = 0;

extern kal_uint8 controller_close_msg[];//20190731
extern void clear_vaule_conn_data(void);

/****************************************************************************
***本地函数
****************************************************************************/
void track_cust_lease_cmd_result_handle(kal_uint8 arg, kal_uint8 param);
void track_cust_rearwheel_cmd_result_handle(U8 param);
void track_cust_exbatlock_cmd_result_handle(U8 param);
kal_uint8 track_cust_halfsleep_position(U8 param, track_gps_data_struct *gps_data);
void track_cust_mode_change_upload(void* arg);
U8 track_cust_acc_status_confirm();
U8 track_cust_not_wheel_lock(void);
kal_uint8 track_mode_lease_on(U8 type);
//-----------
void track_mode_shift(void* arg);
/****************************************************************************
***引用函数
****************************************************************************/
extern kal_uint8 track_acc_status(void* arg);
extern kal_uint8 track_light_status(void* arg);
extern void track_cust_clear_meliage();
extern void bt_rsp_app_01(U8 PN, U8 exe);
extern void bt_rsp_app_02(U8 PN, U8 exe);
extern void track_cust_wifi_work_mode(void);
extern void track_cust_vibrates_voice_alarm(void* arg);
extern void audio_amplifier(void* param);
extern void track_drv_wakeup_external_reinit();
extern void speed_voice_play();
extern kal_uint8 track_cust_rtinfo_upload(kal_uint8 arg);
extern void track_cust_status_recover(void);
extern void track_cust_is_shock();
//20190731
extern track_gps_data_struct *track_cust_backup_gps_data(kal_uint8 type, track_gps_data_struct *new_data);
//yuyin
extern void Substantiv_voice_id(kal_uint8 voice_sta);
extern kal_uint8 track_get_voice_numid_sta(void);
extern void track_cust_xyt_open_lock(kal_uint8 lock);

/****************************************************************************
**********************************************************************
****************************************************************************/

void track_cust_lease_off_alarm()
{
    LOGD(L_APP, L_V5, "可以检测报警了");
}
void track_cust_ele_on_gpio(void* arg)
{
    kal_uint8 sw = (kal_uint8)arg;
    static U8 handletime = 0;
    static U8 done = 0;
    kal_uint16 exeTime = 0;
    if(done == 0)
    {
        GPIO_ModeSetup(ELE_SWT_ON_GPIO, 0);
        GPIO_InitIO(1, ELE_SWT_ON_GPIO);
        done = 1;
    }
    LOGD(L_APP, L_V5, "sw:%d,%d,%d,%d", sw, G_realtime_data.exbatlock, GPIO_ReadIO(ELE_SWT_ON_GPIO), track_GPIO_ReadIO(ELE_SWT_ON_GPIO));

    if(sw == 1)
    {
        if(G_parameter.eletopen >= GPIO_EXE_TIME_MIN && G_parameter.eletopen <= GPIO_EXE_TIME_MAX)
        {
            exeTime = G_parameter.eletopen * 100;
        }
        else exeTime = 2300;

        LOGD(L_APP, L_V1, "exeTime:%d", exeTime);
        tr_stop_timer(TRACK_CUST_ELE_LOCK_DELAY_TIMER_ID);
        //担心短时间内收到开关锁，开锁之前，先将关锁的IO口关掉 begin
        track_drv_gpio_set(0, ELE_SWT_OFF_GPIO);
        //end
        if(handletime > 0 && G_realtime_data.exbatlock == 0)
        {
            handletime = 0;
            track_drv_gpio_set(0, ELE_SWT_ON_GPIO);
            return;
        }

        GPIO_WriteIO(1, ELE_SWT_ON_GPIO);
        handletime ++;
        track_start_timer(TRACK_CUST_ELE_SW_TIMER_ID, exeTime, track_cust_ele_on_gpio, (void *) 0);//1500-2300
    }
    else if(sw == 0)
    {
        track_drv_gpio_set(0, ELE_SWT_ON_GPIO);
        track_start_timer(TRACK_CUST_ELE_SW_TIMER_ID, 1000, track_cust_ele_on_gpio, (void *) 2);
    }
    /*	else if(sw == 3)
    	{
    		tick = kal_get_systicks();

    		LOGD(L_APP, L_V5, "sec:%d",kal_ticks_to_secs(tick-curr_tick));
    		tr_stop_timer(TRACK_CUST_ELE_SW_TIMER_ID);
    		track_drv_gpio_set(0, ELE_SWT_ON_GPIO);
    		handletime = 0;
    	}*/
    else
    {
        //GPIO_WriteIO(0, ELE_SWT_ON_GPIO);
        track_drv_gpio_set(0, ELE_SWT_ON_GPIO);
        if(G_realtime_data.exbatlock != 0 && handletime < 2)
        {
            track_start_timer(TRACK_CUST_ELE_SW_TIMER_ID, 500, track_cust_ele_on_gpio, (void *) 1);
        }
        else if(G_realtime_data.exbatlock != 0 && handletime >= 2)
        {
            handletime = 0;
            track_cust_exbatlock_fault_alarm(1);
        }
        else
        {
            handletime = 0;
        }
    }
}
/******************************************************************************
 *  Function    -  track_cust_ele_off_gpio
 *
 *  Purpose     -  关闭电池锁
 *
 *  Description -   3：收到中断信号后停止
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2018-07-11,  Liujw  written

 * v1.1  , 2018-07-11,  Modify by Liujw  加上时间 听见哒哒哒
 * ----------------------------------------
 ******************************************************************************/
void track_cust_ele_off_gpio(void* arg)
{
    kal_uint8 sw = (kal_uint8)arg;
    static U8 handletime = 0;
    kal_uint16 exeTime = 0;
    static U8 done = 0;

    if(done == 0)
    {
        GPIO_ModeSetup(ELE_SWT_OFF_GPIO, 0);
        GPIO_InitIO(1, ELE_SWT_OFF_GPIO);
        done = 1;
    }
    LOGD(L_APP, L_V5, "sw:%d,%d,%d,%d", sw, G_realtime_data.exbatlock, GPIO_ReadIO(ELE_SWT_OFF_GPIO), track_GPIO_ReadIO(ELE_SWT_OFF_GPIO));


    if(sw == 1)
    {
        if(G_parameter.eletclose >= GPIO_EXE_TIME_MIN && G_parameter.eletclose <= GPIO_EXE_TIME_MAX)
        {
            exeTime = G_parameter.eletclose * 100;
        }
        else exeTime = 2500;
        LOGD(L_APP, L_V1, "exeTime:%d", exeTime);
        tr_stop_timer(TRACK_CUST_ELE_LOCK_DELAY_TIMER_ID);
        //担心短时间内收到开关锁，关锁之前，先将开锁的IO口关掉 begin
        track_drv_gpio_set(0, ELE_SWT_ON_GPIO);
        //end
        GPIO_WriteIO(1, ELE_SWT_OFF_GPIO);
        handletime ++;
        track_start_timer(TRACK_CUST_ELE_SW_TIMER_ID, exeTime, track_cust_ele_off_gpio, (void *) 0);
    }
    else if(sw == 0)
    {
        track_drv_gpio_set(0, ELE_SWT_OFF_GPIO);
        track_start_timer(TRACK_CUST_ELE_SW_TIMER_ID, 1000, track_cust_ele_off_gpio, (void *) 2);
    }
    else if(sw == 3)
    {
#if 0
        tr_stop_timer(TRACK_CUST_ELE_SW_TIMER_ID);
        /*
        	track_drv_gpio_set(0, ELE_SWT_OFF_GPIO);
        */
        handletime = 0;
        track_start_timer(TRACK_CUST_ELE_SW_TIMER_ID, 800, track_cust_ele_off_gpio, (void *) 4);
#else
        ;
#endif
    }
    else if(sw == 4)
    {
#if 0
        tr_stop_timer(TRACK_CUST_ELE_SW_TIMER_ID);
        track_drv_gpio_set(0, ELE_SWT_OFF_GPIO);
#else
        ;
#endif
    }
    else
    {
        track_drv_gpio_set(0, ELE_SWT_OFF_GPIO);
        if(G_realtime_data.exbatlock != 1 && handletime < 2)
        {
            track_start_timer(TRACK_CUST_ELE_SW_TIMER_ID, 500, track_cust_ele_off_gpio, (void *) 1);
        }
        else if(G_realtime_data.exbatlock != 1 && handletime >= 2)
        {
            handletime = 0;
            track_cust_exbatlock_fault_alarm(1);
        }
        else
        {
            handletime = 0;
        }
    }
}

 //==========================20191009
extern kal_uint8 track_get_lesea_off_sta(kal_uint8 value);
extern kal_uint8 track_get_lesea_off_volume_sta(kal_uint8 value);
//-----------------
/******************************************************************************
 *  Function    -  track_cust_gate_on_gpio
 *
 *  Purpose     -  关闭后轮锁
 *
 *  Description -  时间控制是1.1秒
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2018-07-11,  Liujw  written

 * v1.1  , 2018-07-11,  modify by Liujw
 * 开锁关锁都增加时间 1100 - 1500
 * ----------------------------------------
 ******************************************************************************/
void track_cust_gate_on_gpio(void* arg)
{
    kal_uint8 sw = (kal_uint8)arg;
    static U8 handletime = 0;

    static U8 done = 0;
    kal_uint16 exeTime = 0;
    LOGD(L_APP, L_V5, "%d,wheel:%d", sw, G_realtime_data.wheel);
    if(done == 0)
    {
        GPIO_ModeSetup(ROSE_GATE_OPEN_GPIO, 0);
        GPIO_InitIO(1, ROSE_GATE_OPEN_GPIO);
        done = 1;
    }
    if(sw == 1)
    {
        if(G_parameter.bwtopen >= GPIO_EXE_TIME_MIN && G_parameter.bwtopen <= GPIO_EXE_TIME_MAX)
        {
            exeTime = G_parameter.bwtopen * 100;
        }
        else exeTime = 1800;
        LOGD(L_APP, L_V1, "exeTime:%d", exeTime);
        //担心短时间内收到开关锁，开锁之前，先将关锁的IO口关掉 begin
        track_drv_gpio_set(0, ROSE_GATE_CLOSE_GPIO);
        //end
        GPIO_WriteIO(1, ROSE_GATE_OPEN_GPIO);
        handletime ++;
        track_start_timer(TRACK_CUST_WHEEL_LOCK_TIMER_ID, exeTime, track_cust_gate_on_gpio, (void *) 0);//1100 - 1500
    }
    else if(sw == 0)
    {
        track_drv_gpio_set(0, ROSE_GATE_OPEN_GPIO);
        track_start_timer(TRACK_CUST_WHEEL_LOCK_TIMER_ID, 1000, track_cust_gate_on_gpio, (void *)2);
    }
    else
    {
        track_drv_gpio_set(0, ROSE_GATE_OPEN_GPIO);
        if(G_realtime_data.wheel != 1 && handletime < 2)
        {
            track_start_timer(TRACK_CUST_WHEEL_LOCK_TIMER_ID, 500, track_cust_gate_on_gpio, (void *)1);
        }
        else if(G_realtime_data.wheel != 1 && handletime >= 2)
        {
            handletime = 0;
            //------------------------------
        	track_get_lesea_off_sta(2);//关锁失败，标志设置为2
        	//---------------------------------
            track_cust_rearwheel_fault_alarm(1);
        }
        else
        {
            handletime = 0;
        }
    }
}
/********打开后轮锁*********/
void track_cust_gate_off_gpio(void* arg)
{
    kal_uint8 sw = (kal_uint8)arg;

    static U8 handletime = 0;
    kal_uint16 exeTime = 0;
    static U8 done = 0;
    LOGD(L_APP, L_V5, "%d,wheel:%d", sw, G_realtime_data.wheel);

    if(done == 0)
    {
        GPIO_ModeSetup(ROSE_GATE_CLOSE_GPIO, 0);
        GPIO_InitIO(1, ROSE_GATE_CLOSE_GPIO);
        done = 1;
    }
    if(sw == 1)
    {
        if(G_parameter.bwtclose >= GPIO_EXE_TIME_MIN && G_parameter.bwtclose <= GPIO_EXE_TIME_MAX)
        {
            exeTime = G_parameter.bwtclose * 100;
        }
        else exeTime = 1800;
        LOGD(L_APP, L_V1, "exeTime:%d", exeTime);
        //担心短时间内收到开关锁，关锁之前，先将开锁的IO口关掉 begin
        track_drv_gpio_set(0, ROSE_GATE_OPEN_GPIO);
        //end
        if(handletime > 0 && G_realtime_data.wheel == 0)
        {
            handletime = 0;
            track_drv_gpio_set(0, ROSE_GATE_CLOSE_GPIO);
            return;
        }

        GPIO_WriteIO(1, ROSE_GATE_CLOSE_GPIO);
        handletime++;
        track_start_timer(TRACK_CUST_WHEEL_LOCK_TIMER_ID, exeTime, track_cust_gate_off_gpio, (void *) 0);//1100-1500
    }
    else if(sw == 0)
    {
        track_drv_gpio_set(0, ROSE_GATE_CLOSE_GPIO);
        track_start_timer(TRACK_CUST_WHEEL_LOCK_TIMER_ID, 1000, track_cust_gate_off_gpio, (void *)2);
    }
    else
    {
        track_drv_gpio_set(0, ROSE_GATE_CLOSE_GPIO);
        if(G_realtime_data.wheel != 0 && handletime < 2)
        {
            track_start_timer(TRACK_CUST_WHEEL_LOCK_TIMER_ID, 500, track_cust_gate_off_gpio, (void *) 1);
        }
        else if(G_realtime_data.wheel != 0 && handletime >= 2)
        {
            handletime = 0;
            track_cust_rearwheel_fault_alarm(1);
        }
        else
        {
            handletime = 0;
        }
    }
}

/*
static void track_mode_ele_lock_acc((void*)arg)
{
	kal_uint8 param = (kal_uint8)arg;
	if(!param)
	{
		track_acc_status((void*)0);
	}
}*/
U8 track_is_fly(void* isflymode)
{
    U8 arg = (U8)isflymode;

    LOGD(L_BMS, L_V3, "%d,arg:%d", is_flymode, arg);
    if(arg != 99)
    {
        is_flymode = arg;
    }
    return is_flymode;
}
/*关闭GPIO0 做省电处理*/
void track_cust_rx3_on_off(char value)
{
    static int par  = 0;
    if(track_is_testmode())
    {
        if(par == 1)
            GPIO_ModeSetup(0, 3);
        return;
    }

    if(value == 0)
    {
        GPIO_ModeSetup(0, 0);
        GPIO_WriteIO(value, 0);
        par = 1;
    }
    else
    {
        GPIO_ModeSetup(0, 3);
        par = 0;
    }

}
/*设防模式*/
kal_uint8 track_mode_fortify()
{
    track_mode_shift((void*)12);
	return 1;
}
/*撤防时控制器使能，有*/
extern void request_static_packet(void* param);
/*撤防模式*/
kal_uint8 track_mode_disarm()
{
//20191008
	track_cust_controller_enable(1);
	request_static_packet((void*)99);//撤防时立马把控制器状态设置为丢能，有可能会失败哦
	//----------------------
    track_mode_shift((void*)13);
    return 1;
}
/******************************************************************************
 *  Function    -  track_cust_lease_on_precondition
 *
 *  Purpose     -  开锁前的预处理，主要是让ACC归位
 *
 *  Description -  NULL
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-05-20,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_lease_on_precondition(void* arg)
{
    U8 par = 0;
    static U8 cmdSrc = 0;
    static U8 preconditioning = KAL_FALSE;
    U8 exe = 0;

    par = (U8)arg;
    LOGD(L_APP, L_V5, "par:%d,desired:%d", par, lease_desired);
    if(par != 99)
    {
        cmdSrc = par;
    }
    if(preconditioning == KAL_FALSE && !track_is_timer_run(TRACK_CUST_LEASE_ON_PRECONDITION_TIMER_ID))
    {
        //震动报警撤销和轮动报警

        //track_cust_controller_enable(1);
        track_cust_ele_lock((void*)3);
        set_ele_lock = 0;
        tr_stop_timer(TRACK_CUST_WHEEL_ALARM_LOCK_ELE_TIMER_ID);//关闭轮动报警定时器
        track_cust_module_alarm_vibrates((void *)3);

        //语音报警
        track_cust_vibrates_voice_alarm((void*)3);
        tr_stop_timer(TRACK_CUST_MODULE_ALARM_VIBRATES_DELAY_TIMER_ID);
        tr_stop_timer(TRACK_CUST_MODULE_ALARM_VIBRATES_TIMER_ID);  // 撤防同时也撤销静默时间计时

        if(track_is_timer_run(TRACK_CUST_TEST_RING_TIMER_ID) || track_is_timer_run(TRACK_CUST_RING_OVERTIME_TIMER_ID)) //寻车中开锁，关闭寻车
        {
            tr_stop_timer(TRACK_CUST_RING_OVERTIME_TIMER_ID);
            tr_stop_timer(TRACK_CUST_TEST_RING_TIMER_ID);
            //play_voice(99);
        }
        if(par == 0 && track_is_timer_run(TRACK_CUST_ONLINE_COMMAND_RESULT_DELAY_TIMER_ID))//蓝牙来了,判断网络是否在开锁
        {
            LOGD(L_APP, L_V5, "---------------->GPRS Open Lock,So Stop BT Open Lock,return");
            return;
        }
        if(par == 1 && track_is_timer_run(TRACK_CUST_BLUETOOTH_COMMAND_RESULT_DELAY_TIMER_ID))//网络来了,判断蓝牙是否在开锁
        {
            LOGD(L_APP, L_V5, "---------------->BT Open Lock,So Stop GPRS Open Lock,return");
            return;
        }
        if(track_cust_acc_status_confirm() == 0)//Acc本身为低
        {
            LOGD(L_APP, L_V5, "---------------->Direct Open Lock");
            exe = track_mode_lease_on(0);
        }
        else
        {
            //首先将报警或者寻车打开的ACC报警停掉
            if(track_acc_status((void*)3) == 1 && track_is_timer_run(TRACK_CUST_ALARM_ACC_TIMER))
            {
                tr_stop_timer(TRACK_CUST_ALARM_ACC_TIMER);
            }
            track_acc_status((void *)0);//将ACC拉低
            exe = GPIO_ReadIO(ELE_LOCK_GPIO);
            LOGD(L_APP, L_V5, "Delay 2s to Open Lock,ACC Control GPIO State:%d", exe);

            preconditioning = KAL_TRUE;
            track_start_timer(TRACK_CUST_LEASE_ON_PRECONDITION_TIMER_ID, 2000, track_cust_lease_on_precondition, (void*)99);
        }
    }
    else
    {
        if(track_is_timer_run(TRACK_CUST_LEASE_ON_PRECONDITION_TIMER_ID))
        {
            LOGD(L_APP, L_V5, "========Warnning!!! 异常的开锁指令，不执行！");
            return;
        }
        exe = track_mode_lease_on(0);
        if(exe == 99)
        {
            if(cmdSrc == 0 || (track_is_timer_run(TRACK_CUST_BLUETOOTH_COMMAND_RESULT_DELAY_TIMER_ID) && G_parameter.ste_status.lease == 0))//来自蓝牙
            {
                tr_stop_timer(TRACK_CUST_BLUETOOTH_COMMAND_RESULT_DELAY_TIMER_ID);
                //track_bt_cmd_overtime(0x0B, 0x01);
				track_cust_xyt_open_lock(0);//车辆关闭
            }
            if(cmdSrc == 1 || (track_is_timer_run(TRACK_CUST_ONLINE_COMMAND_RESULT_DELAY_TIMER_ID) && G_parameter.ste_status.lease == 0))//来自网络
            {
                tr_stop_timer(TRACK_CUST_ONLINE_COMMAND_RESULT_DELAY_TIMER_ID);
                if(track_get_code() == 1)
                    track_cust_sms_command(1);
                else
                    track_cust_no7_paket_86(0x01, 0x01, msgid); //执行之后，返回服务器

            }
            LOGD(L_APP, L_V5, "ACC出错，返回开锁失败！");
            //恢复震动报警和语音报警检测
            track_cust_module_alarm_vibrates((void *)2);
            track_cust_vibrates_voice_alarm((void*)2);
            track_cust_acc_alarm((void*)1);//上传一个ACC异常打开报警
        }
        preconditioning = KAL_FALSE;
    }
}
/*借车车状态/开锁状态*/
/************************************************************************************
type[1]重启后保持上一次状态 type[0]收到控制指令
*************************************************************************************/

/******************************************************************************
 *  Function    -  track_mode_lease_on
 *
 *  Purpose     -  开锁逻辑入口
 *
 *  Description -  开锁时，ACC必须是低的状态，如果为高，返回不开锁，失败,寻车和报警除外
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-05-19,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/
kal_uint8 track_mode_lease_on(U8 type)
{
    kal_uint8 isWrite = 0;
    kal_uint8 iseid_open = 0;
    LOGD(L_BMS, L_V3, "指令开锁%d,is_shock:%d,disarm:%d,%d", G_parameter.ste_status.lease, is_shock, G_realtime_data.defences_status, type);
    //0在线或者指令下发
    //------------20191008//控制器使能
    track_cust_controller_enable(0);
    track_get_xc_sta(0);
    //-----------------------
    //=================记录关锁的音乐以及关锁执行结果状态清空为0
    track_get_lesea_off_volume_sta(0);
    track_get_lesea_off_sta(0);//有开锁动作，取消关锁所有的标志，标记为正常0
    //track_mode_shift((void*)10);//5555
    //========================
    if(track_cust_acc_status_confirm() != 0 && type == 0)//函数调用不加(),编译竟然不报错
    {
        LOGD(L_BMS, L_V3, "开锁时，ACC不在低状态，返回不执行");
        return 99;
    }
    if((type == 0 && !G_parameter.ste_status.lease) || type == 1 || G_realtime_data.defences_status == 1)
    {
        isRecovery = type;
        set_ele_lock = 0;

        if(type == 0)
        {
            lease_desired = 1;
            if((is_shock & 2) || (is_shock & 8)) //震动影响到后轮关闭失败
            {
                tr_stop_timer(TRACK_CUST_VEHICLE_LEASE_OFF_NO_SHOCK_TIMER_ID);
                is_shock = 4;
            }
            if(G_realtime_data.defences_status == 1)
            {
                G_realtime_data.defences_status = 0;
            }
            //ACC预处理的目的是将ACC拉低,这里不可能出现acc已经高的情况，预开锁就已经过滤了
            //都很难测试到acc异常高，还能开锁成功的情况吧
            track_acc_status((void*)1);

            track_light_status((void*)1);//开灯
            if(GPIO_ReadIO(2) == 0)//判断后轮锁的中断状态0 关锁  1开锁
            {
                track_cust_gate_off_gpio((void*)1);
            }
            else
            {
                track_cust_lease_cmd_result_handle(2, 1);
                if(G_realtime_data.wheel != 0)
                {
                    G_realtime_data.wheel = 0;
                }
            }

            if(G_realtime_data.unlock_counts >= 65534)//记录开锁次数
            {
                G_realtime_data.unlock_counts = 0;
            }
            G_realtime_data.unlock_counts += 1;
            isWrite = 1;
        }
        else if(type == 1)//重启后回复状态
        {
            if(G_realtime_data.defences_status == 1)
            {
                track_acc_status((void*)0);//撤防时ACC要为低
            }
            else
            {
                track_acc_status((void*)1);//ACC预处理的目的是将ACC拉低
            }
            track_light_status((void*)1);//开灯

            if(GPIO_ReadIO(2) == 0)//判断后轮锁的中断状态0 关锁  1开锁
            {
                track_cust_gate_off_gpio((void*)1);
            }
            else
            {
                if(G_realtime_data.wheel != 0)
                {
                    G_realtime_data.wheel = 0;
                    isWrite = 1;
                }
            }
            LOGD(L_APP, L_V5, "----------->resume lease on state");
            track_mode_shift((void*)1);//把它挪到播报语音那里去，怎么样

        }

        if(G_realtime_data.acc_alarm)
        {
            track_cust_acc_alarm(2);
        }
        else
        {
            if(isWrite == 1)
            {
                Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
            }
        }
        /*2019-6-14
                这里是否需要加500ms的延迟，以前是处于acc的考虑，现在已经加了预处理，这个500ms时间去掉
                其实函数track_mode_shift应该是开关锁成功后才去处理的，放在这里，会出现开锁失败后再去掉关锁的情况
                由于开锁失败不是ACC的问题就是后轮锁的问题，故可不去考虑这个函数的调用，提前调用的好处是做好准备开锁就能用
                */
        return 1;
    }
    return 0;
}
/*关闭状态/可租状态*/
/**
2019-6-18 撤防状态下也需要判断是否达到还车条件，如果不满足，不还车，也不退出撤防状态
**/
//-------------测试一下 等会删除
#if 1
kal_uint8 test_lesea_off_sta_wheel(kal_uint8 value)
{
	static kal_uint8 ret_k = 0;
	if(value !=99)
	{
	if(value == 9)
	ret_k=0;
	else if(value == 10)
	ret_k=1;
	else
	ret_k=2;
	}
	return ret_k;
}
#endif
//-----------------
/******************************************************************************
 *  Function    -  track_mode_lease_off
 * 
 *  Purpose     -   
 * 
 *  Description -   return 0x02 关锁失败
 * 				 return 0x01 关锁成功
 *				 return 0x02 关锁失败
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-17,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
kal_uint8 track_mode_lease_off(U8 type)
{
    U8 FakeAcc = 0;
    kal_uint8 isWrite = 0;
    vehicle_status_struct v_state = {0};
    track_cust_get_controller_data(&v_state);
    //______________
    //track_cust_controller_enable(1);
    //request_static_packet((void*)99);//关锁时立马把控制器状态设置为丢能，有可能会失败哦
    track_get_lesea_off_sta(1);//感觉进入流程了才制标志，好像要这样才行，嗯 就是这样的
	//track_mode_shift((void*)10);//55555
    //----------------------
    LOGD(L_BMS, L_V3, "指令关锁%d,disarm:%d,%d", G_parameter.ste_status.lease, G_realtime_data.defences_status, type);
    if((type == 0 && track_is_timer_run(TRACK_CUST_LEASE_ON_PRECONDITION_TIMER_ID)))
    {
        LOGD(L_BMS, L_V5, "正在开锁预处理，不执行关锁！！！异常！！！！");
        track_get_lesea_off_sta(2);
        return 0x02;
    }
    //if((type == 0 && G_parameter.ste_status.lease) || type == 1 || G_realtime_data.defences_status == 1)
    if((type == 0 && G_parameter.ste_status.lease) || type == 1 || G_realtime_data.defences_status == 1 || (track_get_lesea_off_sta(99)==1 && type == 0))
    {
        /*track_get_hal();//测试
        track_cust_not_wheel_lock();*/
        //track_cust_controller_enable(0);

        //if(type == 0 && G_parameter.ste_status.lease)
        //如果在开锁的情况下关锁出现故障，后轮锁没有锁，后面再进行关锁的时候lease=0，是不是还是要让他进去判断后轮是否轮动？我选择是
        if((type == 0 && G_parameter.ste_status.lease )||track_get_lesea_off_sta(99)==1)
        {
            if((track_cust_wheel_state() == KAL_TRUE || v_state.ele_sta != 0 || v_state.holzer_stah != 0 || v_state.holzer_stal != 0))
            {
                LOGD(L_BMS, L_V5, "then it is not the right time to close !Please wait a litte later");
                track_get_lesea_off_sta(2);
                return 0x02;
            }
        }
        //----------------进入关锁流程了再把使能弄进去，要不然拧巴关锁本应该失败，但是却给他失能了，有点怪
        track_cust_controller_enable(1);
    	request_static_packet((void*)99);
    	//--------------------
        isRecovery = type;
        set_ele_lock = 0;
        track_light_status((void*)0);
        if(type == 0)
        {
            lease_desired = 0;
            if(G_realtime_data.defences_status != 0)
            {
                G_realtime_data.defences_status = 0;
            }
            if(GPIO_ReadIO(EINT_A_GPIO) == 1)//if(!track_cust_status_acc())//这里改成直接判断ACC对应的IO口，ACC高0还是低1
            {
                track_cust_lease_cmd_result_handle(21, 1);
            }
            track_acc_status((void*)0);

            //增加延迟10s关后轮锁begin
            track_cust_is_shock();
            if((is_shock & 1) || track_cust_wheel_state() || track_get_hal() == 1) //增加一个轮动判断，这里的轮动和霍尔是没有意义的
            {
                is_shock |= 2;
            }
            track_cust_lease_cmd_result_handle(2, 0);
            //end

            if(G_realtime_data.lock_counts >= 65534)
            {
                G_realtime_data.lock_counts = 0;
            }
            G_realtime_data.lock_counts += 1;
            isWrite = 1;
        }
        else if(type == 1)
        {
            track_acc_status((void*)0);
            if(G_realtime_data.defences_status == 1)
            {
                if(GPIO_ReadIO(2) == 0)//判断后轮锁的中断状态0 关锁  1开锁
                {
                    track_cust_gate_off_gpio((void*)1);
                }
                else
                {
                    if(G_realtime_data.wheel != 0)
                    {
                        G_realtime_data.wheel = 0;
                        isWrite = 1;
                    }
                }
            }
            else
            {
                if(GPIO_ReadIO(2) != 0)//EINT_B_GPIO = 2
                {
                    //track_cust_gate_on_gpio((void*)1);//要去锁后轮，新需求他们的要求不要去锁。要延迟10s
                    track_cust_is_shock();
                    if((is_shock & 1) || track_cust_wheel_state() || track_get_hal() == 1) //增加一个轮动判断，这里的轮动和霍尔是没有意义的
                    {
                        is_shock |= 2;
                    }
                }
                else
                {
                    if(G_realtime_data.wheel != 1)
                    {
                        G_realtime_data.wheel = 1;
                        isWrite = 1;
                    }
                }
            }
            LOGD(L_APP, L_V5, "----------->resume lease off state");
            track_mode_shift((void*)10);
        }
        if(isWrite)
        {
            Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
        }
        return 1;
    }
    return 0;
}
static void track_cust_module_low_power_fly_change(U32 port)
{
    static kal_uint8 time_reconn  = 0;

    LOGD(L_BMS, L_V7, "port:%d, sleepmode:%d,flay_mode:%d", port, G_realtime_data.sleep, fly_staus);
    if(port < 10 && G_realtime_data.sleep == 16 && fly_staus != SMS_AIRPLANE_MODE && !(track_is_testmode()))
    {
        fly_staus = SMS_AIRPLANE_MODE;
        time_reconn = 0;
        track_cust_gps_control(0);
        track_cust_led_sleep(2);
        track_drv_sys_cfun(4);
        track_soc_disconnect();
        track_cust_server2_disconnect();
        track_cust_make_call((void*)23);
        track_cust_call_hangup();
        track_sms_reset();
        LOGD(L_BMS, L_V4, "!!! 进入全休眠!!!");
    }
    else if(port >= 10 && G_realtime_data.sleep != 0 && fly_staus != SMS_NORMAL_MODE)
    {
        fly_staus = SMS_NORMAL_MODE;
        time_reconn = 0;
        track_drv_sys_cfun(1);
        track_stop_timer(TRACK_CUST_NET_CONN_TIMEOUT_TIMER_ID);
        tr_stop_timer(TRACK_CUST_ALARM_RETURN_FlyMode_TIMER);
        if(G_realtime_data.key_status != 0) /* LEDSW 有更高优先级 */
            track_cust_led_sleep(1);
        track_soc_exit_fly_only();
        track_cust_call_hangup();
        track_sms_reset();
        track_cust_gprs_conn_fail((void*)1);
        LOGD(L_BMS, L_V4, "!!! 退出全休眠!!!");
        //track_drv_wakeup_external_reinit();
    }
}
//void track_pwrsave_mode(int mode)
//{
//	track_cust_module_low_power_fly_change(mode);
//}
void track_cust_deep_sleep(void)
{
    track_cust_module_low_power_fly_change(2);
    track_is_fly((void*)1);
}
void track_mode_shift(void* arg)
{
    static U8 current = 0;//工作模式
    kal_uint8 mode = (kal_uint8)arg;
    LOGD(L_BMS, L_V2, "%d,%d", mode, current);
    if(mode == 0)//该参数应该用不到了
    {
        track_mode_shift((void*)10);
    }
    else if(mode == 1)
    {
        G_parameter.ste_status.lease = 1;
        tr_stop_timer(TRACK_CUST_PAGING_OVERTIME_TIMER_ID);
        track_cust_paging_overtime((void*)0);//清标志
        track_fun_get_time(&unlocktime, KAL_TRUE, NULL);
        unlockgd = track_drv_get_gps_data();
        tr_stop_timer(TRACK_CUST_LEASE_OFF_NO_ALARM_TIMER_ID);
        track_cust_controller_data_init();
        track_cust_rx3_on_off(1);
        track_cust_gps_work_req((void *)4);
        if(isRecovery == 0)
        {
            track_start_timer(TRACK_CUST_MODE_CHANGE_POSITION_TIMER_ID, UPLOADPOSITIONTIME, track_cust_mode_change_upload, (void*)1);
            Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
        }
        //----------------------
        if(G_realtime_data.sleep == 15)
        {
 			track_cust_vehicle_moving(1);
        }
    }
    else if(mode == 10)
    {
        //track_acc_status((void*)0);
        G_parameter.ste_status.lease = 0;
        tr_start_timer(TRACK_CUST_LEASE_OFF_NO_ALARM_TIMER_ID, 20 * 1000, track_cust_lease_off_alarm); //锁车20s内不检测震动报警和音频报警
        track_cust_status_recover();
        oncemileage = G_parameter.ele_data.oncemileage;
        LOGD(L_BMS, L_V2, "总里程%d,单次里程%d", G_parameter.ele_data.totalmileage, G_parameter.ele_data.oncemileage);
        G_parameter.ele_data.oncemileage = 0;
        track_cust_clear_meliage();
        track_cust_module_alarm_vibrates((void *)2);
        track_cust_vibrates_voice_alarm((void*)2);
        track_cust_rx3_on_off(0);
        track_cust_module_speed_limit_cmd_update();
        G_parameter.osd.osdmaxstatus = 0;

        //track_cust_gps_work_req((void *)4);//关锁不需要开启GPS
        if(isRecovery == 0)
        {
            track_start_timer(TRACK_CUST_MODE_CHANGE_POSITION_TIMER_ID, UPLOADPOSITIONTIME, track_cust_mode_change_upload, (void*)10);
            Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
        }

        //锁车成功后，连接ams发送状态信息
        lockgd = track_drv_get_gps_data();
        track_fun_get_time(&locktime, KAL_TRUE, NULL);
        if(unlockgd != NULL)
        {
            track_cust_rtinfo_upload(1);
            track_cust_server2_file_retry();
            track_cust_server2_conn((void*)4);
        }
    }
    else if(mode == 12)//设防
    {
        track_acc_status((void*)2);//打开电门锁
        if(G_realtime_data.defences_status != 1)
        {
            track_start_timer(TRACK_CUST_MODE_CHANGE_POSITION_TIMER_ID, UPLOADPOSITIONTIME, track_cust_mode_change_upload, (void*)2);
        }
		
        G_realtime_data.defences_status= 3;
		
		if(G_realtime_data.acc_alarm)
        {
            track_cust_acc_alarm(2);
        }

        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
        set_ele_lock = 1;
        Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
    }
    else if(mode == 13)//撤防
    {
        LOGD(5, 5, "disarm:%d", GPIO_ReadIO(2));
        if(GPIO_ReadIO(2) != 1)
        {
            track_cust_gate_off_gpio((void*)1);
        }
        else
        {
            G_realtime_data.wheel = 0;
        }

        track_acc_status((void*)0);//关闭控制,电机锁自动解除
        if(G_realtime_data.defences_status != 1)
        {
            track_start_timer(TRACK_CUST_MODE_CHANGE_POSITION_TIMER_ID, UPLOADPOSITIONTIME, track_cust_mode_change_upload, (void*)2);
        }
        G_realtime_data.defences_status = 1;//1 撤防状态  0 非撤防状态
        if(G_realtime_data.acc_alarm)
        {
            track_cust_acc_alarm(2);
        }

        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
        set_ele_lock = 0;
        Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
    }
    else if(mode == 14 && current != mode)//退出休眠
    {

        LOGD(L_BMS, L_V2, "模式切换,普通模式%d,%d", mode, current);
        current = mode;
        tr_stop_timer(TRACK_CUST_GPS_UPDATE_EPHEMERIS_OVERTIME_TIMER_ID);
        tr_stop_timer(TRACK_CUST_WORK_MODE_GPSUPDATE_TIMER_ID);
        if(16 == G_realtime_data.sleep)
        {
            track_cust_module_low_power_fly_change(12);
        }
        if(G_realtime_data.sleep != 0)
        {
            G_realtime_data.sleep = 0;
            Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
        }
    }
    else if(mode == 15 && current != mode) //半休眠
    {
        LOGD(L_BMS, L_V2, "模式切换,半休眠模式%d,%d,%d", mode, current,G_parameter.ste_status.lease);
        if(G_parameter.ste_status.lease == 1)
        {
         	track_cust_vehicle_moving(1);
			return;
        }
        current = mode;
        if(G_realtime_data.sleep != 15)
        {
            G_realtime_data.sleep = 15;
            Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
        }
        //track_start_timer(TRACK_CUST_WORK_MODE_GPSUPDATE_TIMER_ID, G_parameter.ste_param.dormantfreq*1000-180000, track_cust_gps_work_req, (void *)1);
        track_cust_halfsleep_position(2, NULL);
    }
    else if(mode == 16 && current != mode) //全休眠
    {
        LOGD(L_BMS, L_V2, "模式切换,全休眠模式%d,%d", mode, current);
        current = mode;
        tr_stop_timer(TRACK_CUST_GPS_UPDATE_EPHEMERIS_OVERTIME_TIMER_ID);
        tr_stop_timer(TRACK_CUST_WORK_MODE_GPSUPDATE_TIMER_ID);
        if(G_realtime_data.sleep != 16)
        {
            G_realtime_data.sleep = 16;
            Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
            track_cust_mode_change_upload((void*)3);
        }
        //track_cust_module_low_power_fly_change(2);
        //track_is_fly((void*)1);
        tr_start_timer(TRACK_CUST_SLEEP_MODE_TIMER_ID, 8000, track_cust_deep_sleep);
        tr_stop_timer(TRACK_CUST_BMS_CMD_TIMER_ID);
        track_cust_login(0x03);

    }
    else if(mode == 17 && current != mode)//运输模式
    {
        current = mode;
        tr_stop_timer(TRACK_CUST_SLEEP_MODE_TIMER_ID);
        tr_stop_timer(TRACK_CUST_VEHICLE_MOVING_OVERTIME_TIMER_ID);
        tr_stop_timer(TRACK_CUST_GPS_UPDATE_EPHEMERIS_OVERTIME_TIMER_ID);
        if(G_realtime_data.sleep != 16)
        {
            G_realtime_data.sleep = 16;
            Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
        }
        track_cust_module_low_power_fly_change(2);
        track_drv_sensor_off();
        track_is_fly((void*)1);
        tr_stop_timer(TRACK_CUST_BMS_CMD_TIMER_ID);
        track_soc_clear_queue();//清除未发送的定位数据包
        return;
    }
    else if(mode == 18 && current != mode)//退出运输模式
    {
        LOGD(L_BMS, L_V2, "模式切换%d,%d", mode, current);
        current = mode;
        tr_stop_timer(TRACK_CUST_GPS_UPDATE_EPHEMERIS_OVERTIME_TIMER_ID);
        track_cust_module_low_power_fly_change(12);
        track_cust_sensor_init();
        if(G_realtime_data.sleep != 0)
        {
            G_realtime_data.sleep = 0;
            Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
        }
    }
    if(mode != 16 && mode != 17)
    {
        if(!track_is_timer_run(TRACK_CUST_BMS_CMD_TIMER_ID) && !track_is_timer_run(TRACK_CUST_BMS_INIT_TIMER_ID))
        {
            track_cust_bms_command();
        }
    }
}

void track_vechile_status_msg(U8 type, U8 status)
{
    if(type == 20)
    {
        //LOGD(L_BMS, L_V6, "状态信号%d,%d", type, status);//本想记录轮动
        return;
    }

    LOGD(L_BMS, L_V2, "状态信号%d,%d", type, status);
    switch(type)
    {
        case 21://acc变化/*锁车情况下，报警开启acc锁电机*///1 低 0 高
            if(G_parameter.ste_status.lease == 0)
            {
                if(status)
                {
                    track_cust_rx3_on_off(0);
                    controller_hall = 0;//
                }
                else
                {
                    track_cust_rx3_on_off(1);
                }

            }
            else
            {
                //增加一个20s延时判断，20s后自动清空控制器数据
                if(status)
                    tr_start_timer(TRACK_CUST_CONTROLLER_DATA_RECOVER_TIMER_ID, 20 * 1000, track_cust_status_recover);
            }
            break;
        case 2://后轮锁//0 低
            LOGD(L_BMS, L_V2, "后轮锁中断:%d", GPIO_ReadIO(2));
            if(status == 1)
            {
                G_realtime_data.wheel = 0;
                //track_cust_controller_enable(0);
            }
            else
            {
                G_realtime_data.wheel = 1;
                //-----------
                track_get_lesea_off_sta(0);
                track_get_lesea_off_volume_sta(0);
            }
            track_cust_rearwheel_fault_alarm(0);
            track_cust_rearwheel_cmd_result_handle(status);
            break;
        case 12://电池锁
            LOGD(L_BMS, L_V2, "电池锁中断:%d", GPIO_ReadIO(14));
            if(status == 1)
            {
                G_realtime_data.exbatlock = 0;
                if(G_realtime_data.exbat_unlockcounts >= 65534)
                {
                    G_realtime_data.exbat_unlockcounts = 0;
                }
                G_realtime_data.exbat_unlockcounts += 1;
            }
            else
            {
                G_realtime_data.exbatlock = 1;
                if(G_realtime_data.exbat_lockcounts >= 65534)
                {
                    G_realtime_data.exbat_lockcounts = 0;
                }
                G_realtime_data.exbat_lockcounts += 1;
                //track_cust_ele_off_gpio((void*)3);
            }
            Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
            track_cust_exbatlock_fault_alarm(0);
            track_cust_exbatlock_cmd_result_handle(status);
            break;
        default:
            ;
    }
    track_cust_lease_cmd_result_handle(type, status);
    if((type == 12) || (type == 2 && G_parameter.ste_status.lease == 0))//后续改成定位包
    {
        //track_os_intoTaskMsgQueueExt(heartbeat_packets, (void *)117);
        track_os_intoTaskMsgQueueExt(track_cust_mode_change_upload, (void*)6);
    }
}
/*****
Descriptor:4:有霍尔速度      2:有轮动 1:有震动 10 清零
Modify List:
2019-4-3 :静止判断的条件去掉震动。Reason:1，震动报警状态下，开锁后一分钟内关不了锁，震动影响 2，静止下重启，如果震动，会出现数据包数据中是运动
******/
kal_uint8 track_cust_vehicle_moving(U8 from)
{
    LOGD(L_BMS, L_V2, "%d,%d,%d,%d", from, vehicle_moving, G_parameter.ste_status.pwrsave,vehicle_moving_wheel);
    if(G_parameter.ste_status.pwrsave == 1) return;
    if(from == 10)
    {
        vehicle_moving = 0;
        vehicle_moving_wheel = 0;
        if(track_cust_status_charger() == 0)
        {
            track_start_timer(TRACK_CUST_SLEEP_MODE_TIMER_ID, G_parameter.ste_param.sleept * 60 * 1000, track_mode_shift, (void *)16);
        }
        else
        {
            track_start_timer(TRACK_CUST_SLEEP_MODE_TIMER_ID, G_parameter.ste_param.sleept * 60 * 1000, track_mode_shift, (void *)15);
        }

        track_cust_driver_behaviour();//车辆静止，取当前的sensor数据
    }
    else if(from < 5)
    {
        if(from != 1)
        {
            vehicle_moving |= from;
            if(from == 4)
            vehicle_moving_wheel |= 0x02;
            if(from == 2)
            vehicle_moving_wheel |= 0x01;
        }
        track_mode_shift((void*)14);//这里震动要不要进入正常模式，这里有待测试
        track_stop_timer(TRACK_CUST_SLEEP_MODE_TIMER_ID);
        track_start_timer(TRACK_CUST_VEHICLE_MOVING_OVERTIME_TIMER_ID, 1 * 60 * 1000, track_cust_vehicle_moving, (void *) 10);
    }
    else if(from == 44)
    {
		vehicle_moving_wheel &= 0x02;
    }
    else if(from == 45)
    {
		vehicle_moving_wheel &= 0x01;
    }
    else if(from == 46)
    {
		return vehicle_moving_wheel;
    }
    return vehicle_moving;
}
void track_cust_halfsleep_position_overtime(void* par)
{
    kal_uint8 arg = (kal_uint8)par;

    track_gps_data_struct *gpsLastPoint = track_cust_backup_gps_data(2, NULL);
    gpsLastPoint->gprmc.Speed = 0;
    track_cust_N07_paket_02(gpsLastPoint, track_drv_get_lbs_data());
}
kal_uint8 track_cust_halsleep_handle(void* par)
{
    if(track_drv_wifi_status(99) == 0)
    {
        track_drv_wifi_cmd(1);
        //track_drv_wifi_cmd(2);
        track_start_timer(TRACK_CUST_WIFI_WORK_TIMER_ID, 600, track_drv_wifi_cmd, (void*)2);
    }
    else
    {
        track_drv_wifi_cmd(2);
    }
    track_start_timer(TRACK_CUST_HALFSLEEP_POSITION_OVERTIME_TIMER_ID, 3 * 60 * 1000, track_cust_halfsleep_position_overtime, (void*) 0);
    track_cust_gps_work_req((void*)1);
}

kal_uint8 track_cust_halfsleep_position(U8 param, track_gps_data_struct *gps_data)
{
    static kal_uint8 status = 0;
//---------------
	track_gps_data_struct *gpsLastPoint = track_cust_backup_gps_data(2, NULL);
    gpsLastPoint->gprmc.Speed = 0;
//-------------
    LOGD(L_BMS, L_V2, "status:%d,param:%d", status, param);
    if(param == 1)
    {
        status ++;
    }
    else if(param == 2)
    {
        track_start_timer(TRACK_CUST_WORK_MODE_GPSUPDATE_TIMER_ID, G_parameter.ste_param.dormantfreq * 1000, track_cust_halsleep_handle, (void *)1);
        return;
    }

    if(status >= 20)
    {
        tr_stop_timer(TRACK_CUST_WORK_MODE_GPSUPDATE_OVERTIME_TIMER_ID);
        tr_stop_timer(TRACK_CUST_GPS_UPDATE_EPHEMERIS_OVERTIME_TIMER_ID);
        tr_stop_timer(TRACK_CUST_HALFSLEEP_POSITION_OVERTIME_TIMER_ID);
        LOGD(L_BMS, L_V5, "----------------->lease_off_gps_sta:%d", lease_off_gps_sta);
        if(lease_off_gps_sta == 0)
        {
        	if(gps_data->status >= 2)
        	{
				lease_off_gps_sta = 1;
        	}
	        track_cust_N07_paket_02(gps_data, track_drv_get_lbs_data());
	        track_cust_backup_gps_data(3, gps_data);//半休眠时定位保存定位点
	        
        }
        else
        {
			track_cust_N07_paket_02(gpsLastPoint, track_drv_get_lbs_data());
        }
        //track_cust_gps_off_req((void*)3);
        track_cust_gps_location_timeout(1);
        //if(!track_is_timer_run(TRACK_CUST_WORK_MODE_GPSUPDATE_TIMER_ID))
        {
            track_start_timer(TRACK_CUST_WORK_MODE_GPSUPDATE_TIMER_ID, G_parameter.ste_param.dormantfreq * 1000, track_cust_halsleep_handle, (void *)1);
        }
        status = 0;
    }
    return status;
    //tr_stop_timer(TRACK_CUST_HALFSLEEP_POSITION_TIMER_ID);
}
/******************************************************************************
 *  Function    -  track_cust_voice_msg
 *
 *  Purpose     -  语音播报状态返回
 *
 *  Description -  result=5
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2018-08-17,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_voice_msg(void* msg)
{
    kal_uint8 result = 0;
    kal_uint16 identifier;
    media_aud_play_finish_ind_struct* cnf = (media_aud_play_finish_ind_struct*) msg;

    result = cnf->result;
    identifier = cnf->identifier;
    if(result == 5)
    {
        //play_voice(99);
        //audio_amplifier((void*)0);
    }
    LOGD(L_BMS, L_V2, "%d,%d,%d,%d", result, identifier, track_cust_get_limit_status(), track_cust_get_alarm_status(99));
    if(track_cust_get_limit_status() == 2 && track_cust_get_alarm_status(99) == 1)
    {
    	//if((track_set_audio_file_play(99)) == 1) 
		//{
        //	track_set_audio_file_play(0);
       // }
         //LOGD(5, 5,"------------->>>>111");
        Substantiv_voice_id(track_get_voice_numid_sta());
        if(track_set_audio_file_play(99) == 0)
        speed_voice_play();
        return;
    }
    else if(track_cust_get_limit_status() == 2 && track_cust_get_alarm_status(99) == 2)
    {
    	//if((track_set_audio_file_play(99)) == 1) 
		//{
        //	track_set_audio_file_play(0);
       // }
        //LOGD(5, 5,"------------->>>>222");
        tr_start_timer(TRACK_CUST_ALARM_speed_limit_OVERTIME_TIMER, G_parameter.osd.osdtimeinterval * 1000, speed_voice_play);
        Substantiv_voice_id(track_get_voice_numid_sta());
        return;
    }
    if(track_cust_play_identifier() == identifier)
    {
        audio_amplifier((void*)0);
        track_cust_set_identifier();

        /*if(track_set_audio_file_play(99) == 1)
        {
        	track_set_audio_file_play(0);
        }*/
        //播放完一条语音之后，返回查看是否有缓存语音未播放
        Substantiv_voice_id(track_get_voice_numid_sta());//播放完一条语音，清空语音ID
    }
}
void track_cust_server_msgid_info(kal_uint8* id)
{
    memcpy(msgid, id, 32);
}
void track_cust_server_msgid_info_tmp(kal_uint8* id)
{
    msgidtmp[0] = 1;
    memcpy(&msgidtmp[1], id, 32);
}
/******************************************************************************
 *  Function    -  track_cust_lease_overtimer
 *
 *  Purpose     -  处理开锁关锁超时
 *
 *  Description -  无法证明会出现超时，ACC无法处理或者后轮无法处理二者有一个出问题就会出现超时
 *	开锁超时，则让终端恢复到关锁状态，这时候认为硬件故障，不理
 *	关锁超时，则让机器完成软件关锁，结束订单，其他的不处理
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2018-08-17,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_lease_overtimer(void* arg)
{
    kal_uint8 cmdtype = (kal_uint8)arg;

    LOGD(L_BMS, L_V2, "arg:%d,lease desire:%d,acc:%d,is_shock:%d", cmdtype, lease_desired, track_cust_status_acc(), is_shock);
    //该函数是超时处理函数，目的只是为了将lease_desired还原到默认值2 ，如果已经是2了，就没有必要进入函数体
    if(lease_desired == 2)
    {
        LOGD(L_BMS, L_V2, "--------------->lease_desired value is initialization");
        return;
    }
    if(cmdtype == 0)
    {
        if(track_get_code() == 1)
            track_cust_sms_command(1);
        else
        {
            //期望开、关锁失败
            track_cust_no7_paket_86(0x01, 0x01, msgid); //执行之后，返回服务器

            if(msgidtmp[0] == 1)
            {
                track_cust_no7_paket_86(0x01, 0x01, &msgidtmp[1]); //执行之后，返回服务器
            }
        }
    }
    else
    {
        if(lease_desired == 1)
        {
            //track_bt_cmd_overtime(0x0B, 0x01);
            //期望开锁，但是没有开锁成功，所以还是关闭状态
           	track_cust_xyt_open_lock(0);//车辆关闭
        }
        else
        {
            //track_bt_cmd_overtime(0x01, 0x01);
            //期望关锁，但是没有关锁成功，所以还是开启状态
            track_cust_xyt_open_lock(1);//车辆开启
        }
    }
    memset(msgidtmp, 0, 33);
    if(lease_desired == 1)//期望解锁未成功
    {
        lease_desired = 2;
        //if(track_cust_status_acc() == 1)//超时就要全部关掉，不用判断条件 2019-5-18
        {
            track_acc_status((void*)0);//打开电门锁
        }
        if(G_realtime_data.wheel == 0 || GPIO_ReadIO(2) != 0)
        {
            if((is_shock & 1) || track_cust_wheel_state() || track_get_hal() == 1) //有震动
            {
                is_shock |= 8;//开锁超时的处理
            }
            else
            {
                track_cust_gate_on_gpio((void*)1);//后轮锁的关闭用震动延迟
            }
        }
        if(G_parameter.ste_status.lease != 0)
        {
            track_mode_shift((void*)10);
        }
    }
    else if(lease_desired == 0)//期望关锁未成功
    {
        lease_desired = 2;
        //-------------------
        track_get_lesea_off_sta(2);//关锁流程完，但是关锁失败，标志为2
        //--------------------------
        if(track_GPIO_ReadIO(ELE_LOCK_GPIO) == 1)
        {
            track_acc_status((void*)0);
        }
        //这里是不是应该让acc先断开，然后还车成功呢？//新增这个处理，会有什么问题
        if(G_parameter.ste_status.lease != 0)
        {
            track_mode_shift((void*)10);
        }
    }
    track_cust_lease_cmd_result_handle(99, 0);
}
//---------设置MP3音量
 extern void track_set_on_off_volume(kal_uint8 value);
void track_cust_lease_cmd_result_handle(kal_uint8 arg, kal_uint8 param)
{
    static kal_uint8 acc = 2;
    static kal_uint8 rearwheel = 2;
    int playresult = 0;
    LOGD(L_BMS, L_V2, "arg:%d,parm:%d,lease desire:%d,is_shock:%d", arg, param, lease_desired, is_shock);
    LOGD(L_APP, L_V5, "VOICEID=%02X,%02X,%02X", leaseVoiceId[0], leaseVoiceId[1], leaseVoiceId[2]);

    if(arg == 99)
    {
        acc = 2;
        rearwheel = 2;
        return;
    }
    if(arg != 21 && arg != 2)
    {
        return;
    }
    if(arg == 21)//acc 状态
    {
        acc = param;
    }
    if(arg == 2)//后轮锁状态
    {
        rearwheel = param;
    }

    if(lease_desired == 2)//未请求开关锁时的中断变化
    {
        LOGD(L_APP, L_V5, "Return By lease desired 2 State!!");
        rearwheel = 2;
        acc = 2;
        return;
    }

    if(acc == 0 && (rearwheel == 1 || (is_shock & 4)) && lease_desired == 1)
    {
        if((is_shock & 4)) is_shock &= 1;
        if(track_is_timer_run(TRACK_CUST_ONLINE_COMMAND_RESULT_DELAY_TIMER_ID))
        {
            tr_stop_timer(TRACK_CUST_ONLINE_COMMAND_RESULT_DELAY_TIMER_ID);
            if(track_get_code() == 1)
                track_cust_sms_command(0);
            else
            {
                track_cust_no7_paket_86(0x00, 0x00, msgid); //执行之后，返回服务器
                if(msgidtmp[0] == 1)
                {
                    track_cust_no7_paket_86(0x00, 0x00, &msgidtmp[1]); //执行之后，返回服务器
                    memset(msgidtmp, 0, 33);
                }
            }

        }
        if(track_is_timer_run(TRACK_CUST_BLUETOOTH_COMMAND_RESULT_DELAY_TIMER_ID))
        {
            tr_stop_timer(TRACK_CUST_BLUETOOTH_COMMAND_RESULT_DELAY_TIMER_ID);
            //track_bt_cmd_overtime(0x0B, 0x00);
            track_cust_xyt_open_lock(1);//车辆开启(蓝牙回复)
        }

        lease_desired = 2;
        rearwheel = 2;
        acc = 2;

        track_mode_shift((void*)1);//等到开锁完成后再执行
        if(leaseVoiceId[0] != 0 || leaseVoiceId[1] != 0 || leaseVoiceId[2] != 0)
        {
        	if(track_set_audio_file_play(99)==0)
        	{
            	track_set_audio_file_play(1);
            	track_set_on_off_volume(6);
            	playresult = AUDIO_file_play(leaseVoiceId);
            	if(playresult == 0)
            	{
               	 	memset(leaseVoiceId, 0, 3);
                	return;
            	}
            	else
            	{
					//track_set_audio_file_play(0);
					Substantiv_voice_id(track_get_voice_numid_sta());
            	}
            }
            else
            {
				return;
            }
        }
        //track_set_audio_file_play(0);
        play_voice(2);
    }
    else if(acc == 1 && (rearwheel == 0 || (is_shock & 2)) && lease_desired == 0)
    {
        if(track_is_timer_run(TRACK_CUST_ONLINE_COMMAND_RESULT_DELAY_TIMER_ID))
        {
            tr_stop_timer(TRACK_CUST_ONLINE_COMMAND_RESULT_DELAY_TIMER_ID);
            if(track_get_code() == 1)
                track_cust_sms_command(0);
            else
            {
                track_cust_no7_paket_86(0x00, 0x00, msgid); //执行之后，返回服务器
                if(msgidtmp[0] == 1)
                {
                    track_cust_no7_paket_86(0x00, 0x00, &msgidtmp[1]); //执行之后，返回服务器
                    memset(msgidtmp, 0, 33);
                }
            }
        }
        if(track_is_timer_run(TRACK_CUST_BLUETOOTH_COMMAND_RESULT_DELAY_TIMER_ID))
        {
            tr_stop_timer(TRACK_CUST_BLUETOOTH_COMMAND_RESULT_DELAY_TIMER_ID);
            //track_bt_cmd_overtime(0x01, 0x00);
            track_cust_xyt_open_lock(0);//车辆关闭(蓝牙回复)
        }
        lease_desired = 2;
        rearwheel = 2;
        acc = 2;

        track_mode_shift((void*)10);//语音播放完成后再执行
        if(track_get_lesea_off_volume_sta(99) == 0)//多次关锁只播放一次语音
        {
        	track_get_lesea_off_volume_sta(1);
        if(leaseVoiceId[0] != 0 || leaseVoiceId[1] != 0 || leaseVoiceId[2] != 0)
        {
        	if(track_set_audio_file_play(99)==0)
        	{
            	track_set_audio_file_play(1);
            	track_set_on_off_volume(6);
            	playresult = AUDIO_file_play(leaseVoiceId);
            	if(playresult == 0)
            	{
                	memset(leaseVoiceId, 0, 3);
                	return;
            	}
            	else
            	{
					//track_set_audio_file_play(0);
					Substantiv_voice_id(track_get_voice_numid_sta());
            	}
            }
            else
            {
				return;
            }
        }
        //track_set_audio_file_play(0);
        play_voice(11);
        }

    }
}
void track_cust_rearwheel_overtime(void* param)
{
    U8 arg = (U8)param;
    LOGD(L_BMS, L_V5, "arg=%d", arg);
    if(arg == 0)
    {
        bt_rsp_app_02(0x16, 0x01);
    }
    else if(arg == 1)
    {
        bt_rsp_app_02(0x17, 0x01);
    }
    else if(arg == 2)
    {
        if(track_get_code() == 1)
            track_cust_sms_command(1);
        else
            track_cust_no7_paket_86(0x01, 0x01, msgid);
    }
    else if(arg == 3)
    {
        if(track_get_code() == 1)
            track_cust_sms_command(1);
        else
            track_cust_no7_paket_86(0x01, 0x01, msgid);
    }

}
void track_cust_exbatlock_overtime(void* param)
{
    U8 arg = (U8)param;

    LOGD(L_BMS, L_V5, "arg=%d", arg);
    if(arg == 0)
    {
        bt_rsp_app_01(0x0F, 0x01);
    }
    else if(arg == 1)
    {
        bt_rsp_app_01(0x10, 0x01);
    }
    else if(arg == 2)
    {
        if(track_get_code() == 1)
            track_cust_sms_command(1);
        else
            track_cust_no7_paket_86(0x01, 0x01, msgid);
    }
    else if(arg == 3)
    {
        if(track_get_code() == 1)
            track_cust_sms_command(1);
        else
            track_cust_no7_paket_86(0x01, 0x01, msgid);
    }
}
void track_cust_rearwheel_cmd_result_handle(U8 param)
{
    LOGD(L_BMS, L_V5, "param=%d,%d", param, G_realtime_data.wheel);

    if(param)
    {
        if(G_realtime_data.wheel == 0)
        {
            if(track_is_timer_run(TRACK_CUST_BLUETOOTH_REARLOCK_DELAY_TIMER_ID))
            {
                tr_stop_timer(TRACK_CUST_BLUETOOTH_REARLOCK_DELAY_TIMER_ID);
                bt_rsp_app_02(0x16, 0x00);
            }
            if(track_is_timer_run(TRACK_CUST_ONLINE_REARLOCK_DELAY_TIMER_ID))
            {
                tr_stop_timer(TRACK_CUST_ONLINE_REARLOCK_DELAY_TIMER_ID);
                if(track_get_code() == 1)
                    track_cust_sms_command(0);
                else
                    track_cust_no7_paket_86(0x00, 0x00, msgid); //执行之后，返回服务器
            }
        }
    }
    else if(param == 0)
    {
        if(G_realtime_data.wheel == 1)
        {
            if(track_is_timer_run(TRACK_CUST_ONLINE_REARLOCK_DELAY_TIMER_ID))
            {
                tr_stop_timer(TRACK_CUST_ONLINE_REARLOCK_DELAY_TIMER_ID);
                if(track_get_code() == 1)
                    track_cust_sms_command(0);
                else
                    track_cust_no7_paket_86(0x00, 0x00, msgid); //执行之后，返回服务器
            }
            if(track_is_timer_run(TRACK_CUST_BLUETOOTH_REARLOCK_DELAY_TIMER_ID))
            {
                tr_stop_timer(TRACK_CUST_BLUETOOTH_REARLOCK_DELAY_TIMER_ID);
                bt_rsp_app_02(0x17, 0x00);
            }
        }
    }
}
void track_cust_exbatlock_cmd_result_handle(U8 param)
{
    LOGD(L_BMS, L_V5, "param=%d,%d", param, G_realtime_data.exbatlock);

    if(param)
    {
        if(G_realtime_data.exbatlock == 0)
        {
            if(track_is_timer_run(TRACK_CUST_BLUETOOTH_ELELOCK_DELAY_TIMER_ID))
            {
                tr_stop_timer(TRACK_CUST_BLUETOOTH_ELELOCK_DELAY_TIMER_ID);
                bt_rsp_app_01(0x0F, 0x00);
            }
            if(track_is_timer_run(TRACK_CUST_ONLINE_ELELOCK_DELAY_TIMER_ID))
            {
                tr_stop_timer(TRACK_CUST_ONLINE_ELELOCK_DELAY_TIMER_ID);
                if(track_get_code() == 1)
                    track_cust_sms_command(0);
                else
                    track_cust_no7_paket_86(0x00, 0x00, msgid); //执行之后，返回服务器
            }
        }

    }
    else if(param == 0)
    {
        if(G_realtime_data.exbatlock == 1)
        {
            if(track_is_timer_run(TRACK_CUST_ONLINE_ELELOCK_DELAY_TIMER_ID))
            {
                tr_stop_timer(TRACK_CUST_ONLINE_ELELOCK_DELAY_TIMER_ID);
                if(track_get_code() == 1)
                    track_cust_sms_command(0);
                else
                    track_cust_no7_paket_86(0x00, 0x00, msgid); //执行之后，返回服务器
            }
            if(track_is_timer_run(TRACK_CUST_BLUETOOTH_ELELOCK_DELAY_TIMER_ID))
            {
                tr_stop_timer(TRACK_CUST_BLUETOOTH_ELELOCK_DELAY_TIMER_ID);
                bt_rsp_app_01(0x10, 0x00);
            }
        }
    }
}
void track_cust_mode_change_upload(void* arg)
{
    track_gps_data_struct *gd = NULL;
    U8 Up_Type = (U8)arg;//主要为了识别关锁存储定位 点 关锁10 开锁11
    LOGD(L_BMS, L_V5, "--->%d", Up_Type);
    if(track_cust_gps_status() > 2 && (Up_Type == 10 || Up_Type == 1))//
    {
        gd = track_cust_backup_gps_data(0, NULL);
        LOGD(L_BMS, L_V5, "gps position:%d", gd->status);
        if(Up_Type == 10)
        {
        	lease_off_gps_sta = 1;
            track_cust_backup_gps_data(3, gd);//关锁时定位保存定位点
        }
    }
    else
    {
    	if(Up_Type == 10) lease_off_gps_sta = 0;
        gd = track_cust_backup_gps_data(2, NULL);
    }
    track_cust_N07_paket_02(gd, track_drv_get_lbs_data());//这里暂时不知道没有GPS点的时候，怎么处理
}
void track_gps_no_location_dup_updata(void)
{
    kal_uint16 interval_timer;
    track_gps_data_struct last_gps_data = {0};
    static track_gps_data_struct last_tmp_gps_data = {0};

    track_gps_data_struct *gpsLastPoint = NULL;
    applib_time_struct currTime = {0};

    if(G_parameter.gpsDup == 0)
    {
        ;//return;
    }

#if defined (__NT33__)
    interval_timer = G_parameter.gps_work.Fti.lbs_interval;
#else
    if(track_cust_status_acc())
    {
        interval_timer = G_parameter.gps_work.Fti.interval_acc_on;
    }
    else
    {
        interval_timer = G_parameter.gps_work.Fti.interval_acc_off;
    }
#endif
    if(interval_timer == 0)
    {
        return;
    }
    //LOGD(L_APP, L_V5, "login:%d,fix:%d",track_soc_login_status(),track_cust_gps_status());
    if(!track_soc_login_status() || track_cust_gps_status() >= GPS_STAUS_2D || G_parameter.ste_status.lease == 0)
    {
        if(track_is_timer_run(TRACK_CUST_WIFI_WORKMODE_INTERVAL_TIMER_ID))
        {
            tr_stop_timer(TRACK_CUST_WIFI_WORKMODE_INTERVAL_TIMER_ID);
        }
        tr_start_timer(TRACK_CUST_DETECT_NO_VIB_TIMER_ID, interval_timer * 1000, track_gps_no_location_dup_updata);
        return;
    }
    track_cust_wifi_work_mode();//开wifi
    gpsLastPoint = track_cust_backup_gps_data(2, NULL);
    memcpy(&last_gps_data, gpsLastPoint, sizeof(track_gps_data_struct));

    last_gps_data.gprmc.Speed = 0;
    last_gps_data.gprmc.status = 0;

    track_fun_get_time(&currTime, KAL_TRUE, NULL);
    //LOGD(L_APP, L_V5, "%0.4d-%0.2d-%0.2d %0.2d:%0.2d:%0.2d", currTime.nYear, currTime.nMonth, currTime.nDay, \
    //     currTime.nHour, currTime.nMin, currTime.nSec);

    last_gps_data.gprmc.Date_Time.nYear = currTime.nYear;
    last_gps_data.gprmc.Date_Time.nMonth = currTime.nMonth;
    last_gps_data.gprmc.Date_Time.nDay = currTime.nDay;
    last_gps_data.gprmc.Date_Time.nHour = currTime.nHour;
    last_gps_data.gprmc.Date_Time.nMin = currTime.nMin;
    last_gps_data.gprmc.Date_Time.nSec = currTime.nSec;
    tr_start_timer(TRACK_CUST_DETECT_NO_VIB_TIMER_ID, interval_timer * 1000, track_gps_no_location_dup_updata);
    //track_cust_paket_position(&last_gps_data, track_drv_get_lbs_data(), TR_CUST_POSITION_GPSDUP, 0);

    track_cust_N07_paket_02(&last_gps_data, track_drv_get_lbs_data());
}
void track_cust_shock_overtime()
{
    LOGD(L_APP, L_V5, "静止锁后轮,%d,%d,%d", is_shock, G_parameter.ste_status.lease, track_cust_wheel_state());
    if(track_get_hal() == 1 || track_cust_wheel_state() == KAL_TRUE)
    {
        is_shock &= 254;//清除震动标识
        LOGD(L_APP, L_V5, "有霍尔值，等待霍尔清零后锁后轮,%d", is_shock);
        return;
    }
    if(((is_shock & 2) || (is_shock & 8)) && G_parameter.ste_status.lease == 0) //(is_shock & 2 && G_parameter.ste_status.lease == 0)//2019-5-18 超时锁电机之后，也要把后轮锁掉
    {
        if(G_realtime_data.defences_status != 1)
        {
            if(GPIO_ReadIO(2) != 0)
            {
                track_cust_gate_on_gpio((void*)1);
            }
            else
            {
                G_realtime_data.wheel = 1;
                Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);

            }
        }
    }
    is_shock = 0;
}
/******************************************************************************
 *  Function    -  track_cust_is_shock
 *
 *  Purpose     -  检测到震动，延时处理锁后轮
 *
 *  Description -  NULL
 *	2018-10-12 将延时时间从20s改为10s ，新需求要求
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2018-10-12,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_is_shock()
{
    is_shock |= 1;
    tr_start_timer(TRACK_CUST_VEHICLE_LEASE_OFF_NO_SHOCK_TIMER_ID, 10 * 1000, track_cust_shock_overtime);
}

void track_cust_N07_realtime_info()
{
    char RTInfo[1000] = {0};
    float odo = 0, trip = 0;
    int l = 0;
    kal_uint16 capacity = 0, chargingtimes = 0;
    controller_data_struct bms_data = {0};
    charge_measure_struct charge_measure = {0};
    track_bmt_get_ADC_result(&charge_measure);
    track_bms_struct_copy(&bms_data);
    //限速
    l = snprintf(RTInfo, 499, "SPDL:%d;", G_parameter.ele_data.turn_limit);
    //车轮轮径
    l += sprintf(RTInfo + l, "INCH:%d;", G_parameter.ste_param.diameter);
    //电机磁钢数
    l += sprintf(RTInfo + l, "ALNICO:%d;", G_parameter.ste_param.alnicounum);
    //车辆开锁总次数
    l += sprintf(RTInfo + l, "UNLOCKTOT:%d;", G_realtime_data.unlock_counts);
    //车辆关锁总次数
    l += sprintf(RTInfo + l, "LOCKTOT:%d;", G_realtime_data.lock_counts);
    //电池锁开锁总次数
    l += sprintf(RTInfo + l, "BUNLOCKTOT:%d;", G_realtime_data.exbat_unlockcounts);
    //电池锁关锁总次数
    l += sprintf(RTInfo + l, "BLOCKTOT:%d;", G_realtime_data.exbat_lockcounts);
    //总里程
    odo = ((float)G_parameter.ele_data.totalmileage) / 1000;
    l += sprintf(RTInfo + l, "ODO:%.2f;", odo);
    //车辆电瓶电量
    capacity = ((bms_data.totalValtage[0] & 0x00FF) << 8 | bms_data.totalValtage[1]);
    l += sprintf(RTInfo + l, "VBAT:%.2f;", (float)capacity / 1000.00);
    //充电次数
    chargingtimes = (bms_data.circulationOfBat[0] & 0x00FF) << 8;
    chargingtimes = chargingtimes | bms_data.circulationOfBat[1];
    l += sprintf(RTInfo + l, "CHG:%d;", chargingtimes);
    //电池ID
    l += sprintf(RTInfo + l, "BAT ID:%s;", bms_data.barCode);
    //电池温度
    l += sprintf(RTInfo + l , "BTEMP:%d;", (kal_uint32)charge_measure.bmt_vTemp / 1000);
    //以下为单次里程信息
    if(unlockgd != NULL)
    {
        //开锁时间
        l += sprintf(RTInfo + l, "UNLOCKTIME:%d%02d%02d%02d%02d%02d;", unlocktime.nYear, unlocktime.nMonth, unlocktime.nDay, unlocktime.nHour, unlocktime.nMin, unlocktime.nSec);
        //GPS位置
        l += sprintf(RTInfo + l, "UNLOCKADD:%c%.6f,%c%.6f;", unlockgd->gprmc.EW, unlockgd->gprmc.Longitude, unlockgd->gprmc.NS, unlockgd->gprmc.Latitude);
        //关锁时间
        l += sprintf(RTInfo + l, "LOCKTIME:%d%02d%02d%02d%02d%02d;", locktime.nYear, locktime.nMonth, locktime.nDay, locktime.nHour, locktime.nMin, locktime.nSec);
        //关锁GPS位置
        if(lockgd != NULL)
        {
            l += sprintf(RTInfo + l, "LOCKTIMEADD:%c%.6f,%c%.6f;", lockgd->gprmc.EW, lockgd->gprmc.Longitude, lockgd->gprmc.NS, lockgd->gprmc.Latitude);
        }
        else
        {
            l += sprintf(RTInfo + l, "LOCKTIMEADD:00;");
        }
        //单次里程
        trip = ((float)oncemileage) / 1000;
        l += sprintf(RTInfo + l, "TRIP:%.2f;", trip);
        unlockgd = NULL;
    }
    if(strlen(controller_close_msg) > 0)
    {
        l += sprintf(RTInfo + l, "CONTR_MSG:%s;", controller_close_msg);
    }
    else
    {
        l += sprintf(RTInfo + l, "CONTR_MSG:00;");
    }
    if(l > 1000)
    {
        //l += sprintf(RTInfo , "the len > 1000;");
        l = 999;
    }

    LOGS("%s", RTInfo);
    LOGD(L_APP, L_V5, "l:%d", l);
    clear_vaule_conn_data();
    track_cust_paket_09(RTInfo, l);

}
kal_uint8 track_cust_rtinfo_upload(kal_uint8 arg)
{
    static kal_uint8 sendRTINFO = 0;
    if(arg != 99)
    {
        sendRTINFO = arg;
    }
    return sendRTINFO;
}
U8 track_cust_get_shock()
{
    return is_shock;
}
#if 0
void track_cust_wheel_set(void)
{
    LOGD(L_APP, L_V5, "is_shock:%d", is_shock);
    is_shock |= 16;
}
#endif
#if 0
void track_cust_hal_set()
{
    LOGD(L_APP, L_V5, "is_shock:%d", is_shock);
    is_shock |= 32;
}
#endif
U8 track_cust_not_wheel_lock(void)
{
    vehicle_status_struct v_state = {0};
    track_cust_get_controller_data(&v_state);
    LOGD(L_APP, L_V5, "is_shock:%d,wheel:%d,hol_h:%d,hol_l:%d", is_shock, track_cust_wheel_state(), v_state.holzer_stah, v_state.holzer_stal);
    if((is_shock & 1) || track_cust_wheel_state() == KAL_TRUE || v_state.holzer_stah != 0 || v_state.holzer_stal != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/******************************************************************************
 *  Function    -  track_cust_acc_status_confirm
 *
 *  Purpose     -  当前ACC状态判断，必须判断输出、中断和变量三个条件
 *
 *  Description -  强制检测当前ACC状态
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-05-19,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/
U8 track_cust_acc_status_confirm()
{
    U8 acc_tmp = track_cust_status_acc();
    U8 gpio_hdl = track_GPIO_ReadIO(ELE_LOCK_GPIO);
    U8 gpio_eint = GPIO_ReadIO(EINT_A_GPIO);//track_GPIO_ReadIO(EINT_A_GPIO);//用这个函数读不准
    LOGD(L_APP, L_V5, "ACC confirm ,acc_tmp:%d,gpio_hdl:%d,gpio_eint:%d,%d", acc_tmp, gpio_hdl, gpio_eint, GPIO_ReadIO(EINT_A_GPIO));
    if(gpio_hdl == 1 && gpio_eint == 0 && acc_tmp == 1)//acc_tmp == 1 &&
    {
        return 1;//ACC High
    }
    else if(gpio_hdl == 1 || gpio_eint == 0 || acc_tmp == 1)//三种状态都是ACC高的情况，所以不符合开锁条件
    {
        return 2;//非正常状态，ACC异常
    }
    else
    {
        return 0;//ACC Low
    }
}
void track_cust_set_lease_play_audio(kal_uint8 *src)
{
    memcpy(leaseVoiceId, src, 3);
}

kal_uint8 track_cust_get_lease_desired()
{
    return lease_desired;
}

