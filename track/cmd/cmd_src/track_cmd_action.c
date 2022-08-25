
/******************************************************************************
 * track_commands_action.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        短信指令解析
 *
 * modification history
 * --------------------
 * v1.0   2012-07-22,  wangqi create this file
 *
 ******************************************************************************/

/****************************************************************************
* Include Files             包含头文件
*****************************************************************************/
#include "init.h"
#include "l1cal.h"
//#include "kal_public_api.h"

#include "track_drv.h"
//#include "track_soc_Lcon.h"
#include "track_os_data_types.h"
#include "track_os_log.h"
#include "track_os_timer.h"
#include "track_fun_common.h"
#include "track_cmd.h"
#include "track_cust_key.h"
//#include "track_cust_fence.h"
#include "nvram_struct.h"

/*****************************************************************************
 *  Define			    宏定义
*****************************************************************************/

/*****************************************************************************
* Typedef  Enum         枚举
*****************************************************************************/
#define CMDSTOTAL (sizeof(cmd_table)/sizeof(CMD_ENGINE_STRUCT))
#define __NF2318_TEST__
/*****************************************************************************
 *  Struct			    数据结构定义
*****************************************************************************/


/*****************************************************************************
* Local variable            局部变量
*****************************************************************************/
static void cmd_entry_testsoc(void);
/*****************************************************************************
 *  Global Functions	- Extern	    引用外部函数
*****************************************************************************/
extern kal_bool track_log_change(int module, int grade, int target);
extern void track_log_ChangeCatcherMode(int port, char * msg);
extern void track_makecall_test(CMD_DATA_STRUCT * Cmds);
extern kal_bool track_is_recv_cmd_after_boot(kal_uint8 par);
extern void track_soc_disconnect(void);
#if defined(__NF2318__)
extern void track_cust_rx3_on_off(char value);
#endif

/****************************************************************************
* Global Variable           全局变量
*****************************************************************************/

/****************************************************************************
* Global Variable - Extern          引用全局变量
*****************************************************************************/

#if 0
#endif /* 0 */
/*****************************************************************************
 *  Global Functions            全局函数
******************************************************************************/

extern void track_drv_watch_test(void);
/*****************************************************************************
 *  Local Functions	            本地函数
*****************************************************************************/

/**********************************************************
    指令实现辅助函数
**********************************************************/




/**********************************************************
    指令直接实现函数
**********************************************************/
static void cmd_Change_Catcher_mode(CMD_DATA_STRUCT * Cmds)
{
    int port = 0;

    if(Cmds->part == 0)
    {
        port = 4;//默认 无参开USB抓取日志
    }
    else if((port = track_fun_parseInt(Cmds->pars[1])) >= 0)
    {
        ;
    }
    else
    {
        port = 5;
    }

    track_log_ChangeCatcherMode(port, Cmds->rsp_msg);
}

/******************************************************************************
 *  Function    -  cmd_log_output_mode
 *
 *  Purpose     -  日志输出设置
 *
 *  Description -
 *      参数一: AT输出通道设置，可选值有(1,2,3,uart1,uatr2,uart3,usb)，其它值则表示禁用输出
 *      参数二: CATCHER输出通道设置，可选值有(1,2,3,uart1,uatr2,uart3,usb)，其它值则表示禁用输出
 *      参数三: 自定义日志输出通道设置，可选值有(at,catcher)
 *          注: 参数一与参数二不能设置相同通道
 *  例如:
 *      切换USB线输出数据
 *      cb,USB,none,at#
 *      切换串口1线输出数据
 *      cb,uart1,none,at#
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 18-08-2014,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_log_output_mode(CMD_DATA_STRUCT * Cmds)
{
    track_log_output_mode(Cmds->rsp_msg, Cmds->part, Cmds->pars[1], Cmds->pars[2], Cmds->pars[3]);
}

/******************************************************************************
 * FUNCTION:  - cmd_set_Log_mode *
 * DESCRIPTION: 设置LOG输出类型、级别及输出位置
 * Input:
 * Output:
 * Returns:
 * AT^GT_CM=LOG,3
   AT^GT_CM=LOG,3,0  关闭模块3日志输出
   AT^GT_CM=LOG,3,600
   AT^GT_CM=LOG,3,600,1
   AT^GT_CM=LOG,0xff 开启所有模块日志输出功能
 * modification history
 * --------------------
 * v1.0  , 06-08-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
static void cmd_set_Log_mode(CMD_DATA_STRUCT * Cmds)
{
    int parm1 = -1, parm2 = -1, parm3 = -1;

    if((Cmds->part == 0))
    {
        Cmds->rsp_length = get_cur_logd_setting(Cmds->rsp_msg);
        return;
    }

    if(strlen(Cmds->pars[1]))
    {
        parm1 = track_fun_parseInt(Cmds->pars[1]);
    }
    if((Cmds->part >= 2) && strlen(Cmds->pars[2]))
    {
        parm2 = track_fun_parseInt(Cmds->pars[2]);
    }
    if((Cmds->part >= 3) && strlen(Cmds->pars[3]))
    {
        parm3 = track_fun_parseInt(Cmds->pars[3]);
    }

    LOGD(L_CMD, L_V4, "%s:%d,%s:%d,%s:%d", Cmds->pars[1], parm1, Cmds->pars[2], parm2, Cmds->pars[3], parm3);


    if(track_log_change(parm1, parm2, parm3))
    {
        get_cur_logd_setting(Cmds->rsp_msg);
    }
    else
    {
        sprintf(Cmds->rsp_msg, "ERROR:113");
    }
}

/******************************************************************************
 *  Function    -  cmd_entry_test_driver
 *
 *  Purpose     -  驱动测试
 *
 *  Description -  AT^GT_CM=PCBA,part1,part2<,part3>
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 21-01-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void cmd_entry_test_driver(CMD_DATA_STRUCT * Cmds)
{
    track_drv_test_pcba_entry(Cmds->part , Cmds);
}

static void cmd_GPS_PassThrough_mode(CMD_DATA_STRUCT * Cmds)
{

    if((Cmds->part == 0) || (Cmds->part == 1) && (Cmds->pars[1][0] == '0'))
    {
        if(Cmds->part == 0)
        {
            LOGS("GPS Pass Through");
            track_status_gpstc(KAL_TRUE);
            /*if(track_status_autotest(3) == 1)
            {
                track_drv_led_set_cycle_flash(LED_GSM, LED_PWR, LED_GPS, LedMode_Cycle_Slow);
            }*/
        }
        else
        {
            LOGS("GPSTC_OFF");
            track_status_gpstc(KAL_FALSE);
        }
        LOGD(L_CMD, L_V4, "cmdpart:%d GRE.GPS_Pass_state:%d", Cmds->part, track_status_gpstc(2));
    }
    else
    {
        sprintf(Cmds->rsp_msg, "ERROR:100");
    }
}

static void track_test_unit_gpio(char* part2, char* part3)
{
    char result[100] = {0};
    kal_uint8 gpio;
    char output, exe = 0;
    gpio = atoi(part2);
    if(strcmp((S8*)part3, "H") == 0)
    {
        output = 1;
    }
    else if(strcmp((S8*)part3, "L") == 0)
    {
        output = 0;
    }
    else
    {
        LOGS("Error");
        return;
    }
    GPIO_ModeSetup(gpio, 0);
    GPIO_InitIO(1, gpio);
    GPIO_WriteIO(output, gpio);
    exe = GPIO_ReadIO(gpio);
    if(exe == output)
    {
        sprintf(result, "GPIO_%d_OK", gpio);
    }
    else
    {
        sprintf(result, "GPIO_%d_ERROR", gpio);
    }
    LOGS("%s", result);
}
   
static void cmd_entry_test_mode(CMD_DATA_STRUCT * Cmds)
{
    if(!strcmp(Cmds->pars[1], "NOTQUIT"))
    {
        track_status_notquit(1);
    }
    else if(strlen(Cmds->pars[1]) != 0)
    {
        sprintf(Cmds->rsp_msg, "ERROR:100");
        return;
    }
    track_status_test(1);

    if(track_status_test(2) == KAL_TRUE)
    {
        //track_stop_timer(SYSTEM_BOOTUP_TIMER_ID);//导致很多初始化代码没执行，比如中断初始化
        track_cust_led_sleep(1);
        track_stop_timer(TRACK_CUST_PERIODIC_RESTART_GPS_TIMER_ID);
        track_drv_sleep_enable(SLEEP_SMT_MOD, FALSE);
        track_set_testmode(2);

        track_test_key_set_init();
        track_drv_gps_switch(1);

        OTA_track_custom_fake_cell_feature_enable(0);//测试模式关闭防伪基站，不要又删除了影响生产测试！

        track_cust_sensor_test_init();
        //track_drv_SOD_control(1);关闭，以防影响测试，需要测试用指令打开
#if defined (__WHEEL_CHECK__)
			//轮动中断信号
			track_eint_WHEEL_registration();
#endif /* __WHEEL_CHECK__ */

        if(Socket_get_conn_status(0) != 0)
        {
            track_os_intoTaskMsgQueue(track_soc_disconnect); // 通过测试反馈，繁忙的GPRS通讯会影响电话的成功呼叫。
        }
		#if defined(__NF2318__)
		track_cust_rx3_on_off(1);
		#endif
        LOGS("TEST_OK");
    }
}


static void cmd_entry_gpsoff_mode(CMD_DATA_STRUCT * Cmds)
{
    kal_int8 flag = 0;

    if(Cmds->part == 0)
    {
        flag = track_drv_gps_switch(0);
        if(flag == -1 || flag == 0)
        {
            tr_stop_timer(TRACK_CUST_PERIODIC_RESTART_GPS_TIMER_ID);
            LOGS("GPS_OFF_OK");
        }
        else
        {
            LOGS("GPS_OFF_FAIL");
        }
        //LOGD(L_CMD, L_V4, "cmdpart:%d GRE.GPS_Pass_state:%d", Cmds->part, Cmds->rsp_msg);
    }
    else
    {
        sprintf(Cmds->rsp_msg, "ERROR:100");
    }
}
static void cmd_entry_gpscold_mode(CMD_DATA_STRUCT * Cmds)
{

    if(Cmds->part == 0)
    {
        LOGS("GPSCOLD_OK");
        track_drv_gps_switch(1);
        track_drv_gps_cold_restart();
        track_factoty_autotest_gps_fix_time_output(0);
        track_factoty_autotest_gpscold_setmode(1);
    }
    else
    {
        sprintf(Cmds->rsp_msg, "ERROR:100");
    }
}
static void cmd_entry_relay_l_mode(CMD_DATA_STRUCT * Cmds)
{

    if(Cmds->part == 0)
    {
        LOGS("RELAY_L_OK");
        if(track_drv_gpio_cut_oil_elec(KAL_TRUE) == 1)
        {
            LOGS("RELAY_L");
        }
        else
        {
            LOGS("RELAY_L_ERROR");
        }
    }
    else
    {
        sprintf(Cmds->rsp_msg, "ERROR:100");
    }
}
static void cmd_entry_relay_h_mode(CMD_DATA_STRUCT * Cmds)
{

    if(Cmds->part == 0)
    {
        LOGS("RELAY_H_OK");
        if(track_drv_gpio_cut_oil_elec(KAL_FALSE) == 0)
        {
            LOGS("RELAY_H");
        }
        else
        {
            LOGS("RELAY_H_ERROR");
        }
    }
    else
    {
        sprintf(Cmds->rsp_msg, "ERROR:100");
    }
}


static void cmd_entry_gpio_mode(CMD_DATA_STRUCT * Cmds)
{
    char output, exe = 0;
    static int flag = 0;

    if(Cmds->part == 2)
    {
        LOGS("GPIO_OK");
        track_test_unit_gpio(Cmds->pars[1], Cmds->pars[2]);
    }
    else
    {
        sprintf(Cmds->rsp_msg, "ERROR:100");
    }
}


static void cmd_entry_motor_h_mode(CMD_DATA_STRUCT * Cmds)
{
    if(Cmds->part == 0)
    {
        LOGS("MOTOR_H_OK");
        track_drv_set_vibr(KAL_TRUE);
    }
    else
    {
        sprintf(Cmds->rsp_msg, "ERROR:100");
    }
}
static void cmd_entry_motor_l_mode(CMD_DATA_STRUCT * Cmds)
{
    if(Cmds->part == 0)
    {
        LOGS("MOTOR_L_OK");
        track_drv_set_vibr(KAL_FALSE);
    }
    else
    {
        sprintf(Cmds->rsp_msg, "ERROR:100");
    }
}
static void cmd_entry_allled_mode(CMD_DATA_STRUCT * Cmds)
{
    if(Cmds->part == 1)
    {
        track_test_ALLLED(Cmds->pars[1]);
    }
    else
    {
        sprintf(Cmds->rsp_msg, "ERROR:100");
    }
}

static void cmd_decode_epo_data(CMD_DATA_STRUCT * Cmds)
{
    track_epo_data_decode(Cmds);
}

static void cmd_bmt_get_battery_status(CMD_DATA_STRUCT * Cmds)
{
    // vBat=4.23V,iChr=0.51A,vChr=4.74V 电池电压，充电电流，充电电压
    if(Cmds->part == 0)
    {
        track_drv_bmt_charging_result(Cmds->rsp_msg);
    }
    else
    {
        sprintf(Cmds->rsp_msg, "ERROR:100");
    }
}

static void cmd_entry_acc_status(CMD_DATA_STRUCT * Cmds)
{
    if(Cmds->part == 0)
    {
        if(track_test_acc_flag(2) == 1)
        {
            LOGS("ACC_H");
        }
        else
        {
            LOGS("ACC_L");
        }
    }
    else
    {
        sprintf(Cmds->rsp_msg, "ERROR:100");
    }
}


/****************************************************************************
* Global Variable          MIC
*****************************************************************************/
#define __DETECT_VOICE__
#if defined(__DETECT_VOICE__)

/*****************************************************************************
* Local variable				局部变量
*****************************************************************************/
#define  MIC_DETECT_MAX_NUM     15  //5      /*累计20MS一次检测100MS均值*/
#define  MIC_DETECT_MAX_TIME    5
//#define  MIC_DEFECT_LEVEL           150  //150
static kal_int16 PCM_UL_BUF[160] = { 0};
static kal_uint16 PCM_BUF_AVEROne[MIC_DETECT_MAX_NUM] = {0};
static kal_uint16 PCM_BUF_AVER[MIC_DETECT_MAX_TIME] = {0};
static kal_uint16 MIC_DEFECT_LEVEL = 600;
/****************************************************************************
* Global Variable            全局变量
*****************************************************************************/
static int VoiceDetectAllTimes = 0;         /*从开始检测声音的总次数*/

/*20ms采集一次获取160个数据，采集五次获取均值*/
static kal_uint8 FisrtDetectNum = 0;            /*第一次循环检测次数存数值求均值*/
static kal_uint8 DetectTimes = 0;                /*统计第一次检测到均值求均值*/

static BOOL GetVoiceDataValid = FALSE;     /*最开始启动检测前5次数据不准丢弃*/
static BOOL GetVoiceDetectRun = FALSE;   /*检测声控检测是否开启*/
static BOOL voice_detect_is_pause = FALSE;    /*声音检测是否暂停,没有开启时默认为停止*/
static BOOL StopVoiceDetectByCall = FALSE;

static void  MIC_Detect_Voice_Action(void);
static void MIC_Detect_Voice_Pause(void);

/******************************************************************************
 *  Function    -  MIC_Detect_Voice_Stop
 *
 *  Purpose     -  MIC_Detect_Voice_Stop
 *
 *  Description -  停止MIC数据检查
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2011-09-28, guojie  written
 * ----------------------------------------
 ******************************************************************************/
void MIC_Detect_Voice_Stop(void)
{

    LOGD(L_CMD, L_V6, "%d,%d", GetVoiceDetectRun, voice_detect_is_pause);

    //tr_stop_timer(TRACK_VOICE_DETECT_PAUSE_TIMER_ID);
    tr_stop_timer(TRACK_VOICE_RSP_TIMER_ID);

    if(GetVoiceDetectRun == TRUE)
    {
        //没有打开检测直接关闭会重启
        if(voice_detect_is_pause == TRUE)
        {
            voice_detect_is_pause = FALSE;
            PCM2WAY_Stop(1);
        }
        GetVoiceDetectRun = FALSE;
        GetVoiceDataValid = FALSE;
        FisrtDetectNum = 0;
        DetectTimes = 0;
        memset(PCM_BUF_AVER, 0, sizeof(PCM_BUF_AVER));
        //tracker_voice_detect.isVoiceDetecting = 0;
        //nvram_external_write_data(NVRAM_EF_TRACKER_VOICE_DETECT_LID, 1, (kal_uint8 *)&tracker_voice_detect, NVRAM_EF_TRACKER_VOICE_DETECT_SIZE);
    }

}
/******************************************************************************
 *  Function    -  MIC_Detect_Voice_Valid
 *
 *  Purpose     -  MIC_Detect_Voice_Valid
 *
 *  Description -  是否有声音
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2011-09-28, guojie  written
 * ----------------------------------------
 *1000以上是持续声音，
 ******************************************************************************/
static BOOL MIC_Detect_Voice_Valid(void)
{
    int i = 0;
    kal_uint8 ValidTimes = 0;
    for(i = 0; i < MIC_DETECT_MAX_TIME; i++)
    {
        //kal_prompt_trace(MOD_TST, "PCM_BUF_AVER[%d] = %d", i, PCM_BUF_AVER[i]);
        if(PCM_BUF_AVER[i] >= MIC_DEFECT_LEVEL)     //1000  2000
        {
            ValidTimes ++;
        }
    }

    LOGD(L_CMD, L_V6, "%d", ValidTimes, PCM_BUF_AVER[0], PCM_BUF_AVER[1], PCM_BUF_AVER[2], \
         PCM_BUF_AVER[3], PCM_BUF_AVER[4]);

    if(ValidTimes >= 1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/******************************************************************************
 *  Function    -  pcmdata_Get_Average_Many
 *
 *  Purpose     -  pcmdata_Get_Average_Many
 *
 *  Description -  获取100ms内MIC数据的平均值
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2011-09-28, guojie  written
 * ----------------------------------------
 ******************************************************************************/
static void pcmdata_Get_Average_Many(kal_uint16 buf[MIC_DETECT_MAX_NUM])
{
    int i = 0;
    kal_uint32  SumData = 0;
    kal_uint16 Average = 0;
    for(i = 0; i < MIC_DETECT_MAX_NUM; i++)
    {
        SumData += buf[i];
    }
    Average = SumData / MIC_DETECT_MAX_NUM;
    PCM_BUF_AVER[DetectTimes] = Average;
    LOGD(L_CMD, L_V6, "detectTimes:%d,value:%d", DetectTimes, PCM_BUF_AVER[DetectTimes]);
}
/******************************************************************************
 *  Function    -  pcmdata_Get_Average
 *
 *  Purpose     -  pcmdata_Get_Average
 *
 *  Description -  获取20ms内MIC数据的平均值
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2011-09-28, guojie  written
 * ----------------------------------------
 ******************************************************************************/
static void pcmdata_Get_Average(kal_int16 ul_buf[160])
{
    int i = 0;
    kal_int32  SumData = 0;
    kal_uint16 Average = 0;
    for(i = 0; i < 160; i++)
    {
        if(ul_buf[i] >= 0)
        {
            SumData = SumData + ul_buf[i];
        }
        else
        {
            SumData = SumData - ul_buf[i];
        }
    }
    Average = SumData / 160;

    PCM_BUF_AVEROne[FisrtDetectNum] = Average;
    //LOGD(L_CMD, L_V5, "FisrtDetectNum:%d,%d", FisrtDetectNum, Average);
}

/******************************************************************************
 *  Function    -  pcm2way_hisrHdl
 *
 *  Purpose     -  pcm2way_hisrHdl
 *
 *  Description -  采集MIC数据值
 *
 * modification history   开始采集时，前五次采集的数据不对，要丢弃
 * ----------------------------------------
 * v1.0  , 2011-09-28, guojie  written
 * ----------------------------------------
 ******************************************************************************/
static void pcm2way_hisrHdl(void)
{
    //调用GetFromMIC这个函数将本地MIC的数据拿到PCM_UL_BUF中
    //LOGD(L_CMD, L_V6, "VoiceDetectAllTimes:%d,GetVoiceDataValid:%d,%d;GetVoiceDetectRun=%d", VoiceDetectAllTimes,GetVoiceDataValid,FisrtDetectNum,GetVoiceDetectRun);
    if(GetVoiceDataValid == FALSE)
    {
        if(VoiceDetectAllTimes >= 5)
        {
            VoiceDetectAllTimes = 0;
            GetVoiceDataValid = TRUE;
        }
        else
        {
            VoiceDetectAllTimes ++;
        }
    }

    memset(PCM_UL_BUF, 0, sizeof(PCM_UL_BUF));

    PCM2WAY_GetFromMic((uint16*)PCM_UL_BUF);

    //调用PutToSpk()这个函数把处理后的对方的语言数据发送到SPK播放出来，如不希望播放这个声音，去掉这一行即可
    //PCM4WAY_PutToSpk((const uint16*)PCM_UL_BUF);

    if(GetVoiceDataValid == TRUE)
    {
        pcmdata_Get_Average(PCM_UL_BUF);

        //检测15*10次160个数据，检测3S是否有声音
        if(FisrtDetectNum >= MIC_DETECT_MAX_NUM)
        {
            FisrtDetectNum = 0;
            pcmdata_Get_Average_Many(PCM_BUF_AVEROne);

            if(DetectTimes >= MIC_DETECT_MAX_TIME)
            {
                if(MIC_Detect_Voice_Valid() == TRUE)
                {
                    LOGD(L_CMD, L_V5, "======have voice !(%d,%d)=======", FisrtDetectNum, DetectTimes);
                    //这里检测到声控报警后，要立即停止检测否则出现
                    //，声控还未处理，就又检测到声控报警
                    //tr_start_timer(TRACKER_VOICE_DETECT_STOP_TIMER, 500, MIC_Detect_Voice_Stop);
                    //tr_start_timer(TRACK_VOICE_DETECT_PAUSE_TIMER_ID, 500, MIC_Detect_Voice_Stop);
                    //MIC_Detect_Voice_Stop();
                    //tr_start_timer(TRACKER_VOICE_ALARM_TIMER, 2000, Tracker_Voice_Alarm_Detect_Handler);
                    LOGS("MIC Voice OK!");
                    track_os_intoTaskMsgQueue(MIC_Detect_Voice_Stop);
                }
                else
                {
                    LOGD(L_CMD, L_V5, "====no voice !%d====", DetectTimes);
                }

                DetectTimes = 0;
            }
            else
            {
                //MIC_Detect_Voice_Pause();
                DetectTimes ++;
            }
        }
        else
        {
            FisrtDetectNum ++;
        }
    }
}


/******************************************************************************
 *  Function    -  MIC_Detect_Voice_Pause
 *
 *  Purpose     -
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2011-09-28, guojie  written
 * ----------------------------------------
 ******************************************************************************/
static void MIC_Detect_Voice_Pause(void)
{
    LOGD(L_CMD, L_V6, "%d,%d", GetVoiceDetectRun, voice_detect_is_pause);

    if(GetVoiceDetectRun == TRUE && voice_detect_is_pause == FALSE)
    {
        //PCM2WAY_Stop(1);
        voice_detect_is_pause = TRUE;
        //tr_start_timer(TRACK_VOICE_DETECT_PAUSE_TIMER_ID, 500, MIC_Detect_Voice_Action);
    }
}
/******************************************************************************
 *  Function    -  MIC_Detect_Voice_Action
 *
 *  Purpose     -
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2011-09-28, guojie  written
 * ----------------------------------------
 ******************************************************************************/
static void  MIC_Detect_Voice_Action(void)
{
    LOGD(L_CMD, L_V5, "%d,%d,%d,%d,%d",
         GetVoiceDetectRun, voice_detect_is_pause, GetVoiceDataValid, FisrtDetectNum, DetectTimes);

    if(GetVoiceDetectRun == TRUE && voice_detect_is_pause == FALSE)
    {
        PCM2WAY_Start(pcm2way_hisrHdl, 1);
        voice_detect_is_pause = TRUE;
        //tr_start_timer(TRACK_VOICE_DETECT_PAUSE_TIMER_ID, 320, MIC_Detect_Voice_Pause);
    }
}
/******************************************************************************
 *  Function    -  MIC_Detect_Voice_Start
 *
 *  Purpose     -  MIC_Detect_Voice_Start
 *
 *  Description -  开启MIC数据检测
 *
 * modification history   定时启动数据声控检测，若定时时间到开启时
 *                                 在通话中，会重启
 * ----------------------------------------
 * v1.0  , 2011-09-28, guojie  written
 * ----------------------------------------
 ******************************************************************************/
void MIC_Detect_Voice_Start(void)
{
    if(track_is_in_call())
    {
        //待通话结束开始声控检测
        if(StopVoiceDetectByCall == FALSE)
        {
            StopVoiceDetectByCall = TRUE;
        }
    }
    else
    {
        LOGD(L_CMD, L_V5, "%d,%d", StopVoiceDetectByCall, GetVoiceDetectRun);
        if((GetVoiceDetectRun == FALSE) && (StopVoiceDetectByCall == FALSE))
        {
            VoiceDetectAllTimes = 0;
            GetVoiceDetectRun = TRUE;
            voice_detect_is_pause = TRUE;
            memset(PCM_BUF_AVER, 0, sizeof(PCM_BUF_AVER));
            PCM2WAY_Start(pcm2way_hisrHdl, 1);
            //tr_start_timer(TRACK_VOICE_DETECT_PAUSE_TIMER_ID, 400, MIC_Detect_Voice_Pause);

        }
    }

}

void mic_voice_rsponse(void)
{
    LOGD(L_CMD, L_V5, "");
    MIC_Detect_Voice_Stop();
    LOGS("MIC NOT Ready!");
}
/*====================================
*
*
*====================================*/
void cmd_mic_voice_test(CMD_DATA_STRUCT * Cmds)
{
    int parm1 = -1, parm2 = 0, icmd = 0;
    char scmd[50];

    if((Cmds->part == 0))
    {
        parm1 = 6;
    }

    if(Cmds->part >= 1 && strlen(Cmds->pars[1]))
    {
        parm1 = track_fun_parseInt(Cmds->pars[1]);
    }

    if(Cmds->part >= 2 && strlen(Cmds->pars[2]))
    {
        parm2 = track_fun_parseInt(Cmds->pars[2]);
        if(parm2 > 0 && parm2 < 65535)
        {
            MIC_DEFECT_LEVEL = parm2;
        }
    }

    LOGD(L_CMD, L_V5, "%d", parm1);

    if(parm1 > 0)
    {
        MIC_Detect_Voice_Start();
        tr_start_timer(TRACK_VOICE_RSP_TIMER_ID, parm1 * 1000, mic_voice_rsponse);

        sprintf(Cmds->rsp_msg, "MIC Test Start,Overtimes:%ds,Level:%d", parm1, MIC_DEFECT_LEVEL);

    }
    else
    {
        sprintf(Cmds->rsp_msg, "args ERROR:MIC,10,600#");
    }
}
#endif


/****************************************************************************
* Global Variable          MIC
*****************************************************************************/
void cmd_drv_WDT_test(CMD_DATA_STRUCT * Cmds)
{
    int  parm1 = -1;
    kal_uint8 parm = 0;

    if((Cmds->part == 0))
    {
#if defined (__WATCH_DOG__)
        track_drv_watch_test();
#endif /* __WATCH_DOG__ */
        return;
    }

    if(Cmds->part >= 2 && strlen(Cmds->pars[2]))
    {
        LOGD(L_CMD, L_V5, "arg0:%s arg1:%s arg2:%s", Cmds->pars[0], Cmds->pars[1], Cmds->pars[2]);
        if(strlen(Cmds->pars[1]))
        {
            parm = Cmds->pars[1][0] - '0';
        }
        if(parm != 0 && parm != 1)
        {
            parm = 0;
        }
        parm1 = track_fun_parseInt(Cmds->pars[2]);
        LOGD(L_CMD, L_V5, "arg1:%d arg2:%d %s", parm, parm1, Cmds->pars[2]);
        if(parm1 >= 0 && parm1 <= 65535)
        {
#if defined (__WATCH_DOG__)
            WDT_Worng_Data_Test(parm, parm1);
#endif /* __WATCH_DOG__ */
        }
    }
}

static void cmd_check_sim(CMD_DATA_STRUCT * Cmds)
{
    if(Cmds->part != 0)
    {
        sprintf(Cmds->rsp_msg, "ERROR:100");//指令长度不正确
        return;
    }

    if(track_drv_get_sim_type() > 0)
    {
        sprintf(Cmds->rsp_msg, "SIM_OK");
    }
    else
    {
        sprintf(Cmds->rsp_msg, "SIM_FAIL");
    }

}

#if defined(__AUDIO_RC__)
static void cmd_speaker_on(CMD_DATA_STRUCT * Cmds)
{
    if(Cmds->part != 0)
    {
        sprintf(Cmds->rsp_msg, "ERROR:100");//指令长度不正确
        return;
    }
    track_cust_audio_play_voice(3/*MT_RING*/);
    sprintf(Cmds->rsp_msg, "SPEAKER_ON_OK");
}

static void cmd_speaker_off(CMD_DATA_STRUCT * Cmds)
{
    if(Cmds->part != 0)
    {
        sprintf(Cmds->rsp_msg, "ERROR:100");//指令长度不正确
        return;
    }
    //track_cust_audio_stop_voice();
    track_cust_audio_play_voice(6/*MT_DISCONNECT*/);

    sprintf(Cmds->rsp_msg, "SPEAKER_OFF_OK");
}
#endif /* __AUDIO_RC__ */

static void cmd_hangup(CMD_DATA_STRUCT * Cmds)
{
    if(Cmds->part != 0)
    {
        sprintf(Cmds->rsp_msg, "ERROR:100");//指令长度不正确
        return;
    }

    track_hangup_call();
}

/******************************************************************************
 *  Function    -  cmd_Chip_id
 *
 *  Purpose     -
 *  ID,1    读基带芯片随机ID [不能更改，因为与PC测试绑定]
 *  ID,2    读Sensor ID，改进为读型号名称
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 13-04-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void cmd_Chip_id(CMD_DATA_STRUCT * Cmds)
{
    sensor_type_enum sensor_type;
    kal_uint8 *result;
    char tmp[50] = {0};
    char *sensor_type_tab[] = {"Bosch bma250", "Bosch bma250E", "Bosch bma253", "Kionix kxtj3-1057", "Silan SC7A20", "Mira DA213",/*"mCube mc3410", "Micro afa750", "Freescale mma8452Q",*/ "MECH"};

    if(Cmds->part == 1)
    {
        if(!strcmp("1", Cmds->pars[1]))
        {
            result = track_drv_get_chip_id();
            snprintf(tmp, 50, "%0.2X %0.2X %0.2X %0.2X %0.2X %0.2X %0.2X %0.2X %0.2X %0.2X %0.2X %0.2X %0.2X %0.2X %0.2X %0.2X",
                     result[0], result[1], result[2], result[3], result[4], result[5], result[6], result[7],
                     result[8], result[9], result[10], result[11], result[12], result[13], result[14], result[15]);

            sprintf(Cmds->rsp_msg, "Chip RID:%s", tmp);
            LOGH(L_DRV, L_V4, result, 16);
        }
        else if(!strcmp("2", Cmds->pars[1]))
        {
            sensor_type = track_drv_get_sensor_type();
            if((sensor_type <= SENSOR_NOT_READY) || (sensor_type >= SENSOR_TYPE_MAX))
            {
                sprintf(Cmds->rsp_msg, "sensor type not detected");
            }
            else
            {
                sprintf(Cmds->rsp_msg, "sensor type:%s", sensor_type_tab[sensor_type-1]);
            }
        }
    }
    else
    {
        sprintf(Cmds->rsp_msg, "ERROR:100");
    }
}

/******************************************************************************
 *  Function    -  cmd_reset_system
 *
 *  Purpose     -  重启指令处理
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_reset_system(CMD_DATA_STRUCT * Cmds)
{
    if(Cmds->part == 0)
    {
#if defined(__GERMANY__)
        Cmds->rsp_length = sprintf(Cmds->rsp_msg, "OK - der Tracker startet in 20 Sek.neu.");
#elif defined(__SPANISH__)
        Cmds->rsp_length = sprintf(Cmds->rsp_msg, "La terminal se reiniciara despues de 20 segundos!");
#else
        Cmds->rsp_length = sprintf(Cmds->rsp_msg, "The terminal will restart after 20sec!");
#endif
        track_cust_restart(2, 20);
    }
    else if(Cmds->part == 1 && strlen(Cmds->pars[CM_Par1]) > 0)
    {
        int sec = atoi(Cmds->pars[CM_Par1]);
        if(sec <= 0) track_cust_restart(2, 20);
        track_cust_restart(2, sec);
    }
    else
    {
        sprintf(Cmds->rsp_msg, "ERROR:100");
    }
}


/******************************************************************************
 *  Function    -  cmd_format_system_drive
 *
 *  Purpose     -  格式化系统盘
 *
 *  Description -  格式化后会重启，无法回复执行结果
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 30-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void static cmd_format_system_drive(CMD_DATA_STRUCT * Cmds)
{
    int result = 0;
    int driver;
    kal_uint8 path[30] = {0x5c, 0x00, 0x5c, 0x00, 0x2E, 0x0, 0x5c, 0x00, 0x43, 0x0, 0x3a, 0x0, 0x0, 0x0};
    FS_DiskInfo info;

    if(!(Cmds->part == 1 && !strcmp(Cmds->pars[CM_Par1], "NEWTTL")))
    {
        sprintf(Cmds->rsp_msg, "Format disable");
        return;
    }

    driver = FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_NO_ALT_DRIVE);    //C
    LOGD(L_CMD, L_V5, "driver:%d", driver);

    if(driver >= FS_NO_ERROR)
    {
        OTA_kal_wsprintf((WCHAR*) path, "\\\\.\\%c:", (char)driver);
        LOGH(L_CMD, L_V5, path, 30);
        result = FS_GetDiskInfo((WCHAR*) path, &info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
        LOGD(L_CMD, L_V5, "result:%d, driver:%d, letter:%d", result, driver, info.DriveLetter);
        if(result < 0)    //RTF_NO_ERROR   //FS_DRIVE_NOT_FOUND
        {
            sprintf(Cmds->rsp_msg, "Format Fail : FAT getdiskinfo error %d", result);
        }
        else
        {
            result = FS_GeneralFormat((WCHAR*) path, FS_FORMAT_HIGH, NULL);

            if(result >= FS_NO_ERROR)
            {
                sprintf(Cmds->rsp_msg, "Format Success\r\n====Format FAT Restart 2 sec====\r\n");
                /* 系统盘格式化后重启,   AT、短信指令均不能回复*/
                track_device_reset(2);
            }
            else
            {
                sprintf(Cmds->rsp_msg, "Format Fail : code %d", result);
            }


        }
    }
    else
    {
        //LOGC(L_DRV, L_V6, "driver not present");
        sprintf(Cmds->rsp_msg, "driver not present");
    }

}

/*****************测试指令结束*****************************************/

void read_rf_data(CMD_DATA_STRUCT * Cmds)
{
    kal_bool ret = 0;
    l1cal_rampTable_T Data;
    char tmp[300] = {0};
    char buffer[300] = {0};
    kal_uint32 i = 0, j = 0;
    LOGS("read_rf_data");
    memset(&Data, 0x00, sizeof(l1cal_rampTable_T));
    if(Cmds->part != 1)
    {
        LOGS("ERROR:part %d", Cmds->part);
        return;
    }
    LOGS("pars 0 %d", Cmds->pars[0]);
    LOGS("pars 1 %d", Cmds->pars[1]);
    if(strcmp((char*)Cmds->pars[1], "850") == 0)
    {
        ret = Track_nvram_read(NVRAM_EF_L1_RAMPTABLE_GSM850_LID, 1, (void *)&Data, NVRAM_EF_L1_RAMPTABLE_GSM850_SIZE);
        LOGS("RF:850");
    }
    else if(strcmp((char*)Cmds->pars[1], "900") == 0)
    {
        ret = Track_nvram_read(NVRAM_EF_L1_RAMPTABLE_GSM900_LID, 1, (void *)&Data, NVRAM_EF_L1_RAMPTABLE_GSM900_SIZE);
        LOGS("RF:900");
    }
    else if(strcmp((char*)Cmds->pars[1], "1800") == 0)
    {
        ret = Track_nvram_read(NVRAM_EF_L1_RAMPTABLE_DCS1800_LID, 1, (void *)&Data, NVRAM_EF_L1_RAMPTABLE_DCS1800_SIZE);
        LOGS("RF:1800");
    }
    else if(strcmp((char*)Cmds->pars[1], "1900") == 0)
    {
        ret = Track_nvram_read(NVRAM_EF_L1_RAMPTABLE_PCS1900_LID, 1, (void *)&Data, NVRAM_EF_L1_RAMPTABLE_PCS1900_SIZE);
        LOGS("RF:1900");
    }
    else
    {
        LOGS("ERROR");
        return;
    }
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "lowest_power %d", Data.rampData.lowest_power);
    LOGS("%s", buffer);
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "%s", "power ");
    for(i = 0; i < 16; i++)
    {
        sprintf(tmp, "%d,", Data.rampData.power[i]);
        strcat(buffer, tmp);
    }
    LOGS("%s", buffer);

    for(j = 0; j < 16; j++)
    {
        memset(buffer, 0, sizeof(buffer));
        sprintf(buffer, "profile %d:   ", j);
        for(i = 0; i < 16; i++)
        {
            sprintf(tmp, "%d,", Data.rampData.ramp[j].point[0][i]);
            strcat(buffer, tmp);
        }

        //sprintf(tmp, "%d,%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", Data.rampData.lowest_power, Data.rampData.power[0], Data.rampData.power[1], Data.rampData.power[2], Data.rampData.power[3], Data.rampData.power[4], Data.rampData.power[5], Data.rampData.power[6], Data.rampData.power[7], Data.rampData.power[8], Data.rampData.power[9], Data.rampData.power[10], Data.rampData.power[11], Data.rampData.power[12], Data.rampData.power[13], Data.rampData.power[14], Data.rampData.power[15]);
        LOGS("%s", buffer);
        memset(buffer, 0, sizeof(buffer));
        sprintf(buffer, "profile %d:  ", j);
        for(i = 0; i < 16; i++)
        {
            sprintf(tmp, "%d,", Data.rampData.ramp[j].point[1][i]);
            strcat(buffer, tmp);
        }
        LOGS("%s", buffer);
        LOGS("##");
    }

}
void read_rf_RTF_data1(CMD_DATA_STRUCT * Cmds)
{
    kal_bool ret = 0;
    l1cal_rampTable_T Data;
    char buffer[4][NVRAM_EF_L1_RAMPTABLE_GSM850_SIZE];
    kal_uint32 i = 0, j = 0;
    extern  void LOGHH3(const char * text , void * buff, int size);

    //  LOGD(L_CMD, L_V5, " ");
    if(Cmds->part != 0)
    {
        LOGS("ERROR:part %d", Cmds->part);
        return;
    }
    memset(buffer, 0, sizeof(buffer));
    ret = Track_nvram_read(NVRAM_EF_L1_RAMPTABLE_GSM850_LID, 1, (void *)&buffer[0], NVRAM_EF_L1_RAMPTABLE_GSM850_SIZE);
    if(ret == KAL_FALSE)
    {
        LOGS("RF:850 Fail");
        return;
    }
    ret = Track_nvram_read(NVRAM_EF_L1_RAMPTABLE_GSM900_LID, 1, (void *)&buffer[1], NVRAM_EF_L1_RAMPTABLE_GSM900_SIZE);
    if(ret == KAL_FALSE)
    {
        LOGS("RF:900 Fail");
        return;
    }
    ret = Track_nvram_read(NVRAM_EF_L1_RAMPTABLE_DCS1800_LID, 1, (void *)&buffer[2], NVRAM_EF_L1_RAMPTABLE_DCS1800_SIZE);
    if(ret == KAL_FALSE)
    {
        LOGS("RF:1800 Fail");
        return;
    }
    ret = Track_nvram_read(NVRAM_EF_L1_RAMPTABLE_PCS1900_LID, 1, (void *)&buffer[3], NVRAM_EF_L1_RAMPTABLE_PCS1900_SIZE);
    if(ret == KAL_FALSE)
    {
        LOGS("RF:1900 Fail");
        return;
    }
    {
        FS_HANDLE h;
        UINT read, written, size;
        S8 iDrvLetter = 0;
        char szFilePath[32];
        WCHAR FileName[20];
        kal_uint8 chip_rid[16];
        kal_uint16 CRC, CRC_IN = 0;
        kal_wsprintf(FileName, "rf_data.dat");
        FS_Delete(FileName);
        LOGHH3("GSM850", &buffer[0], NVRAM_EF_L1_RAMPTABLE_GSM850_SIZE);
        LOGHH3("GSM900", &buffer[1], NVRAM_EF_L1_RAMPTABLE_GSM900_SIZE);
        LOGHH3("GSM1800", &buffer[2], NVRAM_EF_L1_RAMPTABLE_DCS1800_SIZE);
        LOGHH3("GSM1900", &buffer[3], NVRAM_EF_L1_RAMPTABLE_PCS1900_SIZE);
        CRC = GetCrc16(buffer, NVRAM_EF_L1_RAMPTABLE_GSM850_SIZE * 4);
        LOGS("CRC:%x", CRC);

        if((h = (FS_HANDLE)FS_Open(FileName, FS_READ_WRITE | FS_CREATE)) >= 0)
        {
            //   LOGD(L_CMD, L_V5, "@@1");
            FS_GetFileSize(h, &size);
            FS_Seek(h, 0, FS_FILE_END);
            FS_Write(h, (void*)buffer, sizeof(buffer), &written);
            LOGD(L_CMD, L_V6, "@@ %d;%d", sizeof(buffer), written);
            FS_Commit(h);
            FS_Close(h);
        }
    }
}

void read_rf_RTF_data(CMD_DATA_STRUCT * Cmds)
{
    kal_bool ret = 0;
    l1cal_rampTable_T Data;
    char buffer[4][NVRAM_EF_L1_RAMPTABLE_GSM850_SIZE];
    kal_uint32 i = 0, j = 0;
    LOGD(L_CMD, L_V5, " ");
    if(Cmds->part != 0)
    {
        LOGS("ERROR:part %d", Cmds->part);
        return;
    }
    memset(buffer, 0, sizeof(buffer));
    ret = Track_nvram_read(NVRAM_EF_L1_RAMPTABLE_GSM850_LID, 1, (void *)&buffer[0], NVRAM_EF_L1_RAMPTABLE_GSM850_SIZE);
    if(ret == KAL_FALSE)
    {
        LOGS("RF:850 Fail");
        return;
    }
    ret = Track_nvram_read(NVRAM_EF_L1_RAMPTABLE_GSM900_LID, 1, (void *)&buffer[1], NVRAM_EF_L1_RAMPTABLE_GSM900_SIZE);
    if(ret == KAL_FALSE)
    {
        LOGS("RF:900 Fail");
        return;
    }
    ret = Track_nvram_read(NVRAM_EF_L1_RAMPTABLE_DCS1800_LID, 1, (void *)&buffer[2], NVRAM_EF_L1_RAMPTABLE_DCS1800_SIZE);
    if(ret == KAL_FALSE)
    {
        LOGS("RF:1800 Fail");
        return;
    }
    ret = Track_nvram_read(NVRAM_EF_L1_RAMPTABLE_PCS1900_LID, 1, (void *)&buffer[3], NVRAM_EF_L1_RAMPTABLE_PCS1900_SIZE);
    if(ret == KAL_FALSE)
    {
        LOGS("RF:1900 Fail");
        return;
    }
    {
        FS_HANDLE h;
        UINT read, written, size;
        S8 iDrvLetter = 0;
        char szFilePath[32];
        WCHAR FileName[20];
        kal_wsprintf(FileName, "rf_data.dat");
        FS_Delete(FileName);
        if((h = (FS_HANDLE)FS_Open(FileName, FS_READ_WRITE | FS_CREATE)) >= 0)
        {
            LOGD(L_CMD, L_V5, "@@1");
            FS_GetFileSize(h, &size);
            FS_Seek(h, 0, FS_FILE_END);
            FS_Write(h, (void*)buffer, sizeof(buffer), &written);
            LOGD(L_CMD, L_V6, "@@ %d;%d", sizeof(buffer), written);
            FS_Commit(h);
            FS_Close(h);
        }
    }
}

void read_rf_WTN_data(CMD_DATA_STRUCT * Cmds)
{
    kal_bool ret = 0;
    l1cal_rampTable_T Data;
    char buffer[4][NVRAM_EF_L1_RAMPTABLE_GSM850_SIZE];
    kal_uint32 i = 0, j = 0;
    LOGD(L_CMD, L_V5, " ");
    if(Cmds->part != 0)
    {
        LOGS("ERROR:part %d", Cmds->part);
        return;
    }
    memset(buffer, 0, sizeof(buffer));
    {
        FS_HANDLE h;
        WCHAR FileName[20] = {0};
        kal_uint32 read, filesize, segments;
        int fs_result, ret = 0;

        kal_wsprintf(FileName, "rf_data.dat");

        h = FS_Open(FileName, FS_READ_ONLY);
        if(h < 0)
        {
            LOGS("Fail");
            return;
        }
        fs_result = FS_Read(h, &buffer, sizeof(buffer), &read);
        LOGD(L_CMD, L_V5, "@@ %d;%d", sizeof(buffer), read);
        FS_Close(h);
    }
    ret = Track_nvram_write(NVRAM_EF_L1_RAMPTABLE_GSM850_LID, 1, (void *)&buffer[0], NVRAM_EF_L1_RAMPTABLE_GSM850_SIZE);
    if(ret == KAL_FALSE)
    {
        LOGS("RF:850 Fail");
        return;
    }
    ret = Track_nvram_write(NVRAM_EF_L1_RAMPTABLE_GSM900_LID, 1, (void *)&buffer[1], NVRAM_EF_L1_RAMPTABLE_GSM900_SIZE);
    if(ret == KAL_FALSE)
    {
        LOGS("RF:900 Fail");
        return;
    }
    ret = Track_nvram_write(NVRAM_EF_L1_RAMPTABLE_DCS1800_LID, 1, (void *)&buffer[2], NVRAM_EF_L1_RAMPTABLE_DCS1800_SIZE);
    if(ret == KAL_FALSE)
    {
        LOGS("RF:1800 Fail");
        return;
    }
    ret = Track_nvram_write(NVRAM_EF_L1_RAMPTABLE_PCS1900_LID, 1, (void *)&buffer[3], NVRAM_EF_L1_RAMPTABLE_PCS1900_SIZE);
    if(ret == KAL_FALSE)
    {
        LOGS("RF:1900 Fail");
        return;
    }
}
void read_rf_barcode_status(CMD_DATA_STRUCT * Cmds)
{
    kal_uint8 gbarcode[64];
    kal_bool ret = KAL_FALSE;
    l1cal_crystalCapData_T capid = {0};

    if(Cmds->part != 0)
    {
        if(Cmds->part == 1 && strlen(Cmds->pars[1]) > 0)
        {
            if(strcmp(Cmds->pars[1], "CAP") == 0)
            {
                ret = Track_nvram_read(NVRAM_EF_L1_CRYSTAL_CAPDATA_LID, 1, (void *)&capid, NVRAM_EF_L1_CRYSTAL_CAPDATA_SIZE);
                LOGS("Read CapId %s : %d", (ret == KAL_TRUE ? "Success" : "Fail"), capid.cap_id);
                return;
            }
        }
        LOGS("ERROR:part %d", Cmds->part);
        return;
    }
    ret = Track_nvram_read(NVRAM_EF_BARCODE_NUM_LID, 1, &gbarcode, 64);
    if(ret == KAL_TRUE)
    {
        if(gbarcode[60] == '1' && gbarcode[61] == '0')
        {
            LOGS("RF CODE PASS");
        }
        else if(gbarcode[60] == '0' && gbarcode[61] == '1')
        {
            LOGS("RF CODE FAIL");
        }
        else
        {
            LOGS("RF CODE NONE");
        }
    }
}

static kal_uint8 nvram_sds_operate_contu(kal_uint8 operate)
{
    static kal_uint8 contu = 0;
    if(operate == 1)
    {
        contu ++;
    }
    else if(operate == 0)
    {
        contu = 0;
    }
    LOGD(L_CMD, L_V5, "operate index:%d", contu);
    return contu;
}
/********************************
NVRAM_ERRNO_NOT_READY
NVRAM_IO_ERRNO_OK
nvram_errno_enum
********************************/
void track_cmd_nvram_sds_cnf(void* msg)
{
    nvram_sds_cnf_struct* sds_req = (nvram_sds_cnf_struct *)msg;
    LOGD(L_CMD, L_V5, "result:%d", sds_req->result);
    if(sds_req->result == 0)
    {
        LOGS("NVRAM执行成功!");
        track_stop_timer(TRACK_CUST_SIM_BACKUP_PARAM_TIMER);
        nvram_sds_operate_contu(0);
    }
    else
    {
        LOGS("NVRAM执行失败!代码:%d", sds_req->result);
    }
}
//NVRAM_SDS_ACCESS_BACKUP,
//NVRAM_SDS_ACCESS_RESTORE
void track_cmd_send_to_nvram(kal_uint16 type)
{
    ilm_struct *ilm ;
    nvram_sds_req_struct* localPtr;

    if(nvram_sds_operate_contu(1) > 2)
    {
        //备份两次不成功放弃本次备份
        nvram_sds_operate_contu(0);
        track_stop_timer(TRACK_CUST_SIM_BACKUP_PARAM_TIMER);
        return;
    }
    localPtr = (nvram_sds_req_struct*)
               construct_local_para(sizeof(nvram_sds_req_struct), TD_RESET/*0*//*TD_CTRL*/);

    if(localPtr == NULL)
    {
        LOGD(L_CMD, L_V1, "error 1");
        track_cust_restart(45, 0);
        return;
    }
    ilm = (ilm_struct*)allocate_ilm(MOD_MMI);
    if(ilm == NULL)
    {
        LOGD(L_CMD, L_V1, "error 2");
        track_cust_restart(44, 0);
        return;
    }

    localPtr->access_id = MOD_MMI;
    localPtr->access_mode = type;

    ilm->peer_buff_ptr = NULL;
    ilm->local_para_ptr = (local_para_struct*) localPtr;
    ilm->msg_id = MSG_ID_NVRAM_SDS_REQ;
    ilm->sap_id = DRIVER_PS_SAP;
    ilm->src_mod_id = MOD_MMI;
    ilm->dest_mod_id = MOD_NVRAM;
    msg_send_ext_queue(ilm);
}

static void track_esds(CMD_DATA_STRUCT * Cmds)
{
    track_cmd_send_to_nvram(NVRAM_SDS_ACCESS_BACKUP);
}

static void track_rsds(CMD_DATA_STRUCT * Cmds)
{
    track_cmd_send_to_nvram(NVRAM_SDS_ACCESS_RESTORE);
}
extern void track_cust_atech_data_req(kal_uint8 cmd,kal_uint8* param ,kal_uint8 param_len,kal_uint8 sta);
static void track_OBD_test(CMD_DATA_STRUCT * Cmds)
{
    int i_part1 = 0;

    if(Cmds->part == 0)
    {
        
    }
    else if(Cmds->part == 2)
    {
        char ch = Cmds->pars[1][0];
        i_part1 = strlen(Cmds->pars[2]);
        if(i_part1 > 0)
        {
            LOGD(L_CMD, L_V5, "%d CMD:%s", ch, Cmds->pars[2]);
            if(ch == '0')
            {
#if defined(__ATECH__)
				track_cust_atech_data_req(track_fun_atoi(Cmds->pars[2]),NULL,0,0x02);
#else
                U_PutUARTBytes(2, Cmds->pars[2], i_part1);
                U_PutUARTBytes(2, "\r\n", 2);
#endif
            }
            else if(ch == '1')
            {
                UART_PutBytes(2, Cmds->pars[2], i_part1, MOD_MMI);
                UART_PutBytes(2, "\r\n", 2, MOD_MMI);
            }
            else if(ch == '2')
            {
                //        track_uart_write(0, Cmds->pars[2], i_part1, MOD_MMI);
                ///    track_uart_write(0, "\r\n", 2, MOD_MMI);
            }

        }
    }
}


static void track_gmode(CMD_DATA_STRUCT * Cmds)
{
    kal_uint16 gmode = track_cust_set_gps_mode(0xFF);
    if(Cmds->part == 1 && strlen(Cmds->pars[1]))
    {
        gmode = track_cust_set_gps_mode(track_fun_parseInt(Cmds->pars[1]));
    }
    sprintf(Cmds->rsp_msg, "GPS Work Mode is %d (0 BD;1 GPS;2 Double)", gmode);
}

kal_bool cmd_Update_SDS_Data(kal_uint8 *data, kal_uint32 data_index, kal_uint32 len, kal_uint8 *md5)
{
    kal_uint32 data_page = 0, ret = 99, page_start_index = 0;
    char page_buf[4096] = {0};
    data_page = data_index / (4096);
    page_start_index = data_page * 4096;

    LOGD(L_CMD, L_V5, "data_page = %d;page_start_index=%d", data_page, page_start_index);

    ret = OTA_readRawDiskData(&OTA_FlashDiskDriveData[1], page_start_index, page_buf, 4096);
    LOGH(L_CMD, L_V5, &page_buf[250], 190);
    LOGD(L_CMD, L_V5, "data_index = %d;len = %d;", data_index, len);

    ret = OTA_eraseRawDiskBlock(&OTA_FlashDiskDriveData[1], data_page);

    memcpy(&page_buf[data_index-page_start_index], data, len);
    LOGH(L_CMD, L_V5, &page_buf[250], 190);

    ret = OTA_writeRawDiskData(&OTA_FlashDiskDriveData[1], page_start_index, page_buf, 4096);
    return 1;
}
static void sds_data_test(CMD_DATA_STRUCT * Cmds)
{
    kal_uint32 address = 0;
    kal_uint32 len = 0;
    kal_int32 result = 0;
    kal_uint32 disk = 0;
    kal_uint32 parts = 0;
    kal_uint8 buffer[6120] = {0};

    if(strlen(Cmds->pars[1]) > 0)
    {
        address = track_fun_parseInt(Cmds->pars[1]);
        LOGD(L_CMD, L_V5, "address = %d;pars[1]=%s", address, Cmds->pars[1]);
    }
    else
    {
        sprintf(Cmds->rsp_msg, "Error!par1");
        return;
    }
    if(strlen(Cmds->pars[2]) > 0)
    {
        len = track_fun_parseInt(Cmds->pars[2]);
        LOGD(L_CMD, L_V5, "len = %d;pars[2]=%s", len, Cmds->pars[2]);
    }
    else
    {
        sprintf(Cmds->rsp_msg, "Error!par2");
        return;
    }
    if(strlen(Cmds->pars[3]) > 0)
    {
        disk = track_fun_parseInt(Cmds->pars[3]);
        LOGD(L_CMD, L_V5, "disk = %d;pars[3]=%s", disk, Cmds->pars[3]);
    }
    else
    {
        sprintf(Cmds->rsp_msg, "Error!par3");
        return;
    }


    //LOGD(L_CMD, L_V5, "DiskSize = %d", OTA_FlashDiskDriveData[disk].DiskSize);
    //LOGD(L_CMD, L_V5, "TotalBlocks=%d", OTA_FlashDiskDriveData[disk].FlashInfo.TotalBlocks);
#if 1
    result = OTA_readRawDiskData(&OTA_FlashDiskDriveData[disk], address, buffer, len);
    if(result != 0)
    {
        sprintf(Cmds->rsp_msg, "Error!result=%d", result);
        return;
    }
    sprintf(Cmds->rsp_msg, "OK");
    LOGH(L_CMD, L_V5, buffer, len);
#endif
}
#if 1
static void sds_writedata_test(CMD_DATA_STRUCT * Cmds)
{
    kal_uint32 address = 0;
    kal_uint32 len = 5;
    kal_int32 result = 0;
    kal_uint32 disk = 0;
    kal_uint32 parts = 0;
    kal_uint8 buffer1[26] = {0xE7, 0xF4, 0xB0, 0xB3, 0xE1, 0xAE, 0xE7, 0xEF, 0xEF, 0xE2, 0xE1, 0xE2, 0xF9, 0xAE, 0xEE, 0xE5, 0xF4, 0X0, 0X0};
    kal_uint8 buffer2[26] = {0xF7, 0xF7, 0xF7, 0xAE, 0xE3, 0xEF, 0xEF, 0xE1, 0xE3, 0xE3, 0xE5, 0xF3, 0xF3, 0xAE, 0xEE, 0xE5, 0xF4, 0x0, 0x0};
    kal_uint8 buffer3[100] = {0xF7, 0xF7, 0xF7, 0xAE, 0xE3, 0xEF, 0xEF, 0xE1, 0xE3, 0xE3, 0xE5, 0xF3, 0xF3, 0xAE, 0xEE, 0xE5, 0xF4, 0x0, 0x0};
    nvram_importance_parameter_struct *server = NULL;
    nvram_parameter_struct * data = NULL;
    static int index = 0;
    if(strlen(Cmds->pars[1]) > 0)
    {
        address = track_fun_parseInt(Cmds->pars[1]);
        LOGD(L_CMD, L_V5, "address = %d;pars[1]=%s", address, Cmds->pars[1]);
    }
    else
    {
        sprintf(Cmds->rsp_msg, "Error!par1");
        return;
    }
    if(strlen(Cmds->pars[2]) > 0)
    {
        parts = track_fun_parseInt(Cmds->pars[2]);
        LOGD(L_CMD, L_V5, "parts = %d;pars[1]=%s", len, Cmds->pars[2]);
    }
    else
    {
        sprintf(Cmds->rsp_msg, "Error!par1");
        return;
    }
    if(strlen(Cmds->pars[3]) > 0)
    {
        len = track_fun_parseInt(Cmds->pars[3]);
        LOGD(L_CMD, L_V5, "len = %d;pars[1]=%s", len, Cmds->pars[3]);
    }
    else
    {
        sprintf(Cmds->rsp_msg, "Error!par1");
        return;
    }

    LOGD(L_CMD, L_V5, "@3");
    if(parts == 1)
    {
        track_drv_update_disk1(0, buffer1, address, len, NULL);
    }
    else if(parts == 2)
    {
        track_drv_update_disk1(0, buffer2, address, len, NULL);
    }
    else
    {
        track_drv_update_disk1(0, buffer3, address, len, NULL);
    }

    sprintf(Cmds->rsp_msg, "OK");
}

static void sds_erasedata_test(CMD_DATA_STRUCT * Cmds)
{
    kal_uint32 blkIdx = 0;
    kal_int32 result = 0;

    nvram_importance_parameter_struct *server = NULL;
    nvram_parameter_struct * data = NULL;
    if(strlen(Cmds->pars[1]) > 0)
    {
        blkIdx = track_fun_parseInt(Cmds->pars[1]);
        LOGD(L_CMD, L_V5, "blkIdx = %d;pars[1]=%s", blkIdx, Cmds->pars[1]);
    }
    OTA_eraseRawDiskBlock(&OTA_FlashDiskDriveData[1], blkIdx);
    if(result != 0)
    {
        LOGD(L_CMD, L_V5, "Error!result=%d", result);
        sprintf(Cmds->rsp_msg, "Error!result=%d", result);
        return;
    }

    sprintf(Cmds->rsp_msg, "OK");
}
#endif

static cmd_set_vmc(CMD_DATA_STRUCT *cmd)
{
    extern void track_drv_Set_VMC(kal_bool flag, kal_uint32 volt);
    int value = 0, value2 = 0;
    if(cmd->part > 2)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value < 0 || value > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter (0-1)");
        return;
    }
    value2 = track_fun_atoi(cmd->pars[2]);
    track_drv_Set_VMC(value, value2);
    sprintf(cmd->rsp_msg, "OK!");
}

static cmd_set_ldo(CMD_DATA_STRUCT *cmd)
{

    kal_bool sw = KAL_FALSE;
    PMU_LDO_BUCK_LIST_ENUM ldo;
    int ldo_volt = 0;
    if(cmd->part < 2)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }

    if(strcmp(cmd->pars[1], "ON") == 0)
    {
        sw = KAL_TRUE;
    }
    else if(strcmp(cmd->pars[1], "OFF") == 0)
    {
        sw = KAL_FALSE;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter1 (Only ON / OFF)");
        return;
    }

    if(strcmp(cmd->pars[2], "VIBR") == 0)
    {
        ldo = VIBR;
    }
    else if(strcmp(cmd->pars[2], "VMC") == 0)
    {
        ldo = VMC;
    }
    else if(strcmp(cmd->pars[2], "VCAMA") == 0)
    {
        ldo = VCAMA;
    }
    else if(strcmp(cmd->pars[2], "VSIM2") == 0)
    {
        ldo = VSIM2;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter2 (VIBR  VMC)");
        return;
    }

    if(cmd->part > 2)
    {
        if(strcmp(cmd->pars[3], "1") == 0)
        {
            ldo_volt = 1800000;
        }
        else if(strcmp(cmd->pars[3], "2") == 0)
        {
            ldo_volt = 2800000;
        }
        else if(strcmp(cmd->pars[3], "3") == 0)
        {
            ldo_volt = 3000000;
        }
        else if(strcmp(cmd->pars[3], "4") == 0)
        {
            ldo_volt = 3300000;
        }
        else
        {
            sprintf(cmd->rsp_msg, "Error: Parameter3 (1-1.8v 2-2.8v 3-3v 4-3.3v)");
            return;
        }
    }
    LOGD(L_CMD, L_V5, "sw:%d, ldo:%d,volt:%d", sw, ldo, ldo_volt);
    track_drv_set_LDO(sw, ldo, ldo_volt);
    sprintf(cmd->rsp_msg, "OK!");
}
#if defined(__NF2319_TEST__) || defined(__NF2318_TEST__)
static void track_saddle_lock(kal_uint8 arg)
{
    char output;
    if(track_is_testmode())
    {
        if(arg ==1)
        {
            output = 1;
            track_start_timer(TRACK_SADDLE_LOCK_TIME_ID, 300, track_saddle_lock, (void *)0);
        }
        else
        {
            output = 0;
        }
    }
    else
    {
        //非TEST模式下，正常解锁
        if(arg ==1)
        {
            output = 1;
            track_start_timer(TRACK_SADDLE_LOCK_TIME_ID, 100, track_saddle_lock, (void *)2);
        }
        else if(arg ==2)
        {
            output = 0;
            track_start_timer(TRACK_SADDLE_LOCK_TIME_ID, 300, track_saddle_lock, (void *)3);
        }
        else if(arg ==3)
        {
            output = 1;
            track_start_timer(TRACK_SADDLE_LOCK_TIME_ID, 100, track_saddle_lock, (void *)4);
        }   
        else if(arg ==4)
        {
            output = 0;
        } 
    }
    GPIO_WriteIO(output, 48);
}
static cmd_saddle_lock(CMD_DATA_STRUCT *cmd)
{
    if(track_is_timer_run(TRACK_SADDLE_LOCK_TIME_ID))
    {
        sprintf(cmd->rsp_msg, "ERROR:Don't send multiple times at the same time!");
        return;
    }
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "SLOCK_OK");
        track_saddle_lock(1);
    }
    else
    {
        sprintf(cmd->rsp_msg, "SLOCK_ERROR");
    }
}
kal_uint8 flashlight(kal_uint8 i)
{
    static kal_uint8 count=1;
    if(i==99)count=1;
    if(count > 20)return;
    if(i==1||count==1)
    {
        GPIO_WriteIO(1, 47);
        track_start_timer(TRACK_FLASHLIGHT_TIME_ID, 500, flashlight, (void *)0);
    }
    if(i==0)
    {
        GPIO_WriteIO(0, 47);
        track_start_timer(TRACK_FLASHLIGHT_TIME_ID, 500, flashlight, (void *)1);
    }
    count++;
}
static cmd_flashlight(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        if(track_is_timer_run(TRACK_FLASHLIGHT_TIME_ID))
        {
            sprintf(cmd->rsp_msg, "ERROR:Don't send multiple times at the same time!");
            return;
        }
        sprintf(cmd->rsp_msg, "FLASHLIGHT_OK");
        flashlight(99);
    }
    else
    {
        sprintf(cmd->rsp_msg, "FLASHLIGHT_ERROR");
    }
}

static cmd_pwn_on(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "PWNON_OK");
        GPIO_WriteIO(0, 50);
    }
    else
    {
        sprintf(cmd->rsp_msg, "PWNON_ERROR");
    }    
}
static cmd_pwn_off(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "PWNOFF_OK");
        GPIO_WriteIO(1, 50);
    }
    else
    {
        sprintf(cmd->rsp_msg, "PWNOFF_ERROR");
    }    
}
static cmd_acc_on(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "ACCON_OK");
        GPIO_WriteIO(1, 42);
    }
    else
    {
        sprintf(cmd->rsp_msg, "ACCON_ERROR");
    }    
}
static cmd_acc_off(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "ACCOFF_OK");
        GPIO_WriteIO(0, 42);
    }
    else
    {
        sprintf(cmd->rsp_msg, "ACCOFF_ERROR");
    }    
}

static void cmd_lspeaker_on(CMD_DATA_STRUCT * cmd)
{
    char exe = 0;
    exe = track_GPIO_ReadIO(41);
    if(exe!=1)
    {
        GPIO_ModeSetup(41, 0);
        GPIO_InitIO(1, 41);        
        GPIO_WriteIO(1, 41);
    }
    track_cust_play_amr_ring(1, 6);
    sprintf(cmd->rsp_msg, "LSPEAKER_ON_OK");
}
static void cmd_lspeaker_off(CMD_DATA_STRUCT * cmd)
{
    char exe = 0;
    exe = track_GPIO_ReadIO(41);
    track_cust_audio_play_voice(6/*MT_DISCONNECT*/);
    if(exe!=0)
    {
        GPIO_ModeSetup(41, 0);
        GPIO_InitIO(1, 41);        
        GPIO_WriteIO(0, 41);
    }  
    sprintf(cmd->rsp_msg, "LSPEAKEROFF_OK");
}
static cmd_uart3(CMD_DATA_STRUCT * Cmds)
{
        char data[5] ={0x59,0x05,0x01,0x32,0x38};
        //char tmp[5] = {0};
        //int len = track_fun_ASCII_to_HEX(data, tmp, 5);
        LOGH(L_DRV, L_V4, data, 5);
        UART_PutBytes(2, data, 5, UART_GetOwnerID(2));
}
static cmd_control_on(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "ASSON_OK");
        control_write_data();
    }
    else
    {
        sprintf(cmd->rsp_msg, "ACCON_ERROR");
    }    
}
static cmd_control_off(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "ASSOFF_OK");
        tr_stop_timer(TRACK_RROJECT_CONTROL_UART_WRITE_ID);
    }
    else
    {
        sprintf(cmd->rsp_msg, "ACCON_ERROR");
    }    
}
#endif/*__NF2319_TEST__*/

static cmd_uarttest(CMD_DATA_STRUCT * Cmds)
{
    if(!strcmp(Cmds->pars[1], "INIT"))
    {
        int port = atoi(Cmds->pars[2]) - 1;
        int baud = atoi(Cmds->pars[3]);
        track_drv_uart_init_public(MOD_MMI, port, baud);
    }
    else if(!strcmp(Cmds->pars[1], "BTVER"))
    {
        U8 data[] = {0x47, 0x54, 0xFF, 0x00};
        UART_PutBytes(2, data, 4, UART_GetOwnerID(2));
    }
    else if(!strcmp(Cmds->pars[1], "1") || !strcmp(Cmds->pars[1], "2") || !strcmp(Cmds->pars[1], "3"))
    {
        int port = atoi(Cmds->pars[1]) - 1;
        U8 *data = Cmds->rcv_msg_source + (Cmds->pars[2] - Cmds->rcv_msg);
        UART_PutBytes(port, data, strlen(data), UART_GetOwnerID(port));
    }
    else if(!strcmp(Cmds->pars[1], "H1") || !strcmp(Cmds->pars[1], "H2") || !strcmp(Cmds->pars[1], "H3"))
    {
        int port = atoi(&Cmds->pars[1][1]) - 1;
        char *data = Cmds->rcv_msg_source + (Cmds->pars[2] - Cmds->rcv_msg);
        char tmp[100] = {0};
        int len = track_fun_ASCII_to_HEX(data, tmp, 100);
        LOGH(L_DRV, L_V4, tmp, len);
        UART_PutBytes(port, tmp, len, UART_GetOwnerID(port));        
    }
    else
    {
        sprintf(Cmds->rsp_msg, "Error: Parameter1 (1/2/3/H1/H2/H3)");
        return;
    }
}

static CMD_ENGINE_STRUCT  cmd_table[] =
{
    /* 开发调试指令 */
    {"RF",           read_rf_data,                   TRUE},      //RF参数读取
    {"RF_RTF1",       read_rf_RTF_data1,             TRUE},      //RF参数写入FAT
    {"RF_RTF",       read_rf_RTF_data,               TRUE},      //RF参数写入FAT
    {"RF_WTN",       read_rf_WTN_data,               TRUE},      //RF参数从FAT写入NVRAM
    {"RF_BAR",       read_rf_barcode_status,         TRUE},      //RF参数校准状态读取
    {"CA",           cmd_Change_Catcher_mode,        TRUE},      //CA切换到Catcher模式CA,0切回串口
    {"CB",           cmd_log_output_mode,            TRUE},      //CA切换到Catcher模式CA,0切回串口
    {"LOG",          cmd_set_Log_mode,               TRUE},      //开关设置日志输入
    {"PCBA",         cmd_entry_test_driver,          TRUE},      //测试驱动
    {"UARTTEST",     cmd_uarttest,                   TRUE},      //
    /* 工厂测试相关指令 */
    {"GPSTC",        cmd_GPS_PassThrough_mode,       TRUE},      //GPS 透传
    {"GPS_OFF",      cmd_entry_gpsoff_mode,          TRUE},      //测试模式
    {"TEST",         cmd_entry_test_mode,            TRUE},      //测试模式
    {"BMT",          cmd_bmt_get_battery_status,         TRUE},      //电池电压查询
    {"ID",           cmd_Chip_id,                    TRUE},

    {"GPSCOLD",      cmd_entry_gpscold_mode,         TRUE},      //GPS冷启动
    {"RELAY_L",      cmd_entry_relay_l_mode,         TRUE},      //继电器吸合
    {"RELAY_H",      cmd_entry_relay_h_mode,         TRUE},      //继电器断开
    {"GPIO",         cmd_entry_gpio_mode,            TRUE},      //设置GPIO口
    {"MOTOR_H",      cmd_entry_motor_h_mode,         TRUE},      //打开震动马达
    {"MOTOR_L",      cmd_entry_motor_l_mode,         TRUE},      //关闭震动马达
    {"ALLLED",       cmd_entry_allled_mode,          TRUE},      //开关所有LED
    {"EPO",          cmd_decode_epo_data,            TRUE},      //接收EPO 数据
    {"ACC_STATUS",   cmd_entry_acc_status,           TRUE},      //判断ACC状态
    {"MIC",          cmd_mic_voice_test,             TRUE},      //MIC检测
#if defined (__WATCH_DOG__)
    {"I2C",          cmd_drv_WDT_test,               TRUE},      //测试IIC152通讯是否正常
#endif /* __WATCH_DOG__ */
    {"SIM",          cmd_check_sim,                  TRUE},      //检查SIM卡是否存在
#if defined(__AUDIO_RC__)
    {"SPEAKER_ON",   cmd_speaker_on,                 TRUE},      //喇叭开
    {"SPEAKER_OFF",  cmd_speaker_off,                TRUE},      //喇叭关
#endif /* __AUDIO_RC__ */

    {"HANGUP",  cmd_hangup,                TRUE},
    /* 各项目尽可能兼容支持指令 */
    {"RESET",        cmd_reset_system,               TRUE},      //重启
    {"FORMAT",       cmd_format_system_drive,        TRUE},      //系统盘格式化
    {"ATD",          track_makecall_test,            TRUE},      //拨号
    /* 各项目特有指令 */

    {"ESDS",         track_esds,                     TRUE},
    {"RSDS",         track_rsds,                     TRUE},
    {"OB",           track_OBD_test,                 TRUE},
    {"GMODE",        track_gmode,                    TRUE},

    {"SDS",          sds_data_test,                  TRUE},
#if 1
    {"SDS_WRITE",    sds_writedata_test,             TRUE},
    {"SDS_ERASE",    sds_erasedata_test,             TRUE},
#endif
    {"VMC",         cmd_set_vmc,             TRUE},
    {"LDO",         cmd_set_ldo,             TRUE},
        
#if defined (__NF2319_TEST__)
    {"SLOCK",         cmd_saddle_lock,             TRUE},
    {"FLASHLIGHT",         cmd_flashlight,             TRUE}, 
    {"PWNON",         cmd_pwn_on,             TRUE},    
    {"PWNOFF",         cmd_pwn_off,             TRUE},            
    {"ACCON",         cmd_acc_on,             TRUE},    
    {"ACCOFF",         cmd_acc_off,             TRUE},    
    {"LSPEAKER_ON",       cmd_lspeaker_on,          TRUE},  
    {"LSPEAKER_OFF",       cmd_lspeaker_off,          TRUE}, 
    {"UART3",         cmd_uart3,             TRUE},    
    {"CONTROLON",         cmd_control_on,             TRUE},   
    {"CONTROLOFF",         cmd_control_off,             TRUE},   
#endif /* __NF2319_TEST__ */
#if defined(__NF2318_TEST__)
	{"LSPEAKER_ON", 	  cmd_lspeaker_on,			TRUE},	
	{"LSPEAKER_OFF",	   cmd_lspeaker_off,		  TRUE},     
	{"FLASHLIGHT",         cmd_flashlight,             TRUE}, 
    {"PWNON",         cmd_pwn_on,             TRUE},    
    {"PWNOFF",         cmd_pwn_off,             TRUE},            
#endif
};

/*****************************************************************************
 *  Global Functions            全局函数
******************************************************************************/

/******************************************************************************
 *  Function    -  is_sms_replace_ErrorID
 *
 *  Purpose     -  错误短信指令回复警示语
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 03-03-2012,  chengjun  written
 * ----------------------------------------
ERROR 100       指令错误：指令长度超出范围
ERROR 101       指令错误：指令参数超出范围
ERROR 102       指令错误：指令格式不正确
ERROR 103       指令错误：密码格式不正确
ERROR 104       指令错误：亲情电话号码数量已满
ERROR 105       指令错误：亲情电话号码数量已空
ERROR 106       指令错误：电话号码序号不正确
ERROR 107       指令错误：指令不存在
ERROR 108       指令错误：无指令结束符(#)
ERROR 109       指令错误：指令密码错误
ERROR 110       指令错误：非亲情号码不能使用此指令功能
ERROR 112       对方正在通话，请稍后再试
ERROR 113       操作失败
 ******************************************************************************/
static BOOL is_sms_replace_ErrorID(char *Message, U16 *StringId)
{

    if(strstr(Message, "ERROR:") == NULL)
    {
        return FALSE;
    }

    return TRUE;
}



/******************************************************************************
 * FUNCTION:  - track_execute_command
 *
 * DESCRIPTION: -
 *
 *
 * Input:
 * Output:
 * Returns:
 *
 * modification history
 * --------------------
 * v1.0  , 23-07-2012,  WangQi  written
 * --------------------
 ******************************************************************************/
kal_bool track_execute_command(CMD_DATA_STRUCT * gps_cmd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static CMD_DATA_STRUCT CurCmd = {0};
    U8 index = 0;
    U16 StringId = 0;
    BOOL find = FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&CurCmd, gps_cmd, sizeof(CMD_DATA_STRUCT));
    memset(CurCmd.rsp_msg, 0, CM_PARAM_LONG_LEN_MAX);

    LOGD(L_CMD, L_V5, "%d,%d,%s", CurCmd.return_sms.cm_type, gps_cmd->rcv_length, gps_cmd->pars[CM_Main]);

    for(index = 0; index < CMDSTOTAL; index++)
    {
        if(cmd_table[index].valid && !strcmp((S8*)cmd_table[index].cmd_string, CurCmd.pars[CM_Main]))
        {
            find = TRUE;
            track_is_sms_cmd(1);

            if(gps_cmd->supercmd == 1 || gps_cmd->return_sms.cm_type != CM_SMS || track_cmd_check_authentication(&CurCmd))
            {
                if(cmd_table[index].func_ptr != NULL)
                {
                    track_is_recv_cmd_after_boot(1);
                    cmd_table[index].func_ptr(&CurCmd);
                    break;
                }
            }
            else
            {
                sprintf(CurCmd.rsp_msg, "Password error!");      //密码错误
            }
            break;
        }
    }

    if(find)
    {
        CurCmd.rsp_length = strlen(CurCmd.rsp_msg);
        if(CurCmd.rsp_length)
        {
            /*  指令解析执行体只填充信息，全部在此发出*/

            if(CurCmd.return_sms.cm_type == CM_SMS)
            {
                track_cmd_sms_rsp(&CurCmd);
            }
            else if(CurCmd.return_sms.cm_type == CM_ONLINE)
            {
                track_cust_paket_msg_upload(CurCmd.return_sms.stamp, KAL_TRUE, CurCmd.rsp_msg, CurCmd.rsp_length);
            }
            else if(CurCmd.return_sms.cm_type == CM_ONLINE2)
            {
                track_cust_paket_FD_cmd(CurCmd.return_sms.stamp, KAL_TRUE, CurCmd.rsp_msg, CurCmd.rsp_length);
            }
            LOGS("%s", CurCmd.rsp_msg);
        }
        return KAL_TRUE;        // 执行操作后删除短信
    }
    else
    {
        return KAL_FALSE;       //手机保留不是指令的短信
    }
}


