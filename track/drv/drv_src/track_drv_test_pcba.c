/******************************************************************************
 * track_test_pcba_drv.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        硬件PCBA 测试
 *
 *     <<参考硬件PCBA测试指令规范说明.pdf >>
 *
 * modification history
 * --------------------
 * v1.0   2012-07-27,  chengjun create this file
 *
 ******************************************************************************/
#if defined (__TEST_PCBA__)

/****************************************************************************
* Include Files                   		包含头文件
*****************************************************************************/
#include "track_drv.h"
//#include "init_public.h"
#include "track_soc_Lcon.h"
#include "track_os_ell.h"
#include "track_cust.h"
//#include "track_os_string.h"
/*****************************************************************************
 *  Define					宏定义
*****************************************************************************/

#define TEST_PCBA_CMD_LEN_MAX  11
#define TEST_PCBA_EINT_LIST_MAX  32

//static char *blank = {""}, *s_ON = {"ON"}, *s_OFF = {"OFF"}, *s_Error = {"ERROR"};
//#define ON_OFF(value) (value==0?s_OFF:(value==1?s_ON:s_Error))

/*****************************************************************************
* Typedef  Enum
*****************************************************************************/
typedef enum
{
    TEST_PCBA_LED,
    TEST_PCBA_VIB,
    TEST_PCBA_GPS,
    TEST_PCBA_SENSOR,
    TEST_PCBA_GPIO,
    TEST_PCBA_EINT,
    TEST_PCBA_LBS,
    TEST_PCBA_BB,
    TEST_PCBA_PMU,
    TEST_PCBA_GPRS,
    TEST_PCBA_KEY,
    TEST_PCBA_WDT,
    TEST_PCBA_LCD,
    TEST_PCBA_OBD,
    TEST_PCBA_REC,
    TEST_PCBA_VMC,
    TEST_PCBA_DEBUG,
    TEST_PCBA_SLEEP,
    TEST_PCBA_BT,
    TEST_PCBA_RS485,
    TEST_PCBA_UART,
    TEST_PCBA_BLE,
    TEST_PCBA_MCU,
    TEST_PCBA_END,
} test_pcba_enum;
/*必须和 test_pcba_tab 保持一致       --    chengjun  2017-06-30*/

/*****************************************************************************
 *  Struct					数据结构定义
*****************************************************************************/
typedef struct
{
    kal_uint8 len;
    //part1 在test_pcba_tab[] ，不需要备份
    char part2[TEST_PCBA_CMD_LEN_MAX];
    char part3[TEST_PCBA_CMD_LEN_MAX];
} test_pcba_cmd_struct;

typedef struct
{
    kal_bool eint_output;
    kal_bool adc_output;
} test_pcba_output_struct;

/*****************************************************************************
* Local variable				局部变量
*****************************************************************************/
static kal_uint8 test_gps_fix_time = 0;
//0=不测试
//1=测试AGPS定位时间
//2=测试GPS热启动时间
//3=测试GPS冷启动时间

static test_pcba_cmd_struct test_pcba_cmd = {0};
static test_pcba_output_struct test_paba_output = {0};
static char test_pcba_eint_list[TEST_PCBA_EINT_LIST_MAX] = {0};

//strlen 必须小于100
static const char test_pcba_cmd_not_exist[] = {"Error:this command is not exist ,please use 'AT^GT_CM=PCBA' for help "};
static const char test_pcba_cmd_sw_not_support[] = {"Sorry,the software does not support this function"};
static const char test_pcba_cmd_hw_not_support[] = {"Sorry,the hardware does not support this function"};
static const char test_pcba_debug_not_exist[] = {"Warning:this debug command is not exist "};
/****************************************************************************
* Global Variable - Extern          全局变量
*****************************************************************************/

/****************************************************************************
* Global Variable - Extern              引用全局变量
*****************************************************************************/

/*****************************************************************************
 *  Local Functions			本地函数
*****************************************************************************/

/******************************************************************************
 *  Function    -  track_test_output_datetime
 *
 *  Purpose     -  输出当前时间日期
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 22-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_test_output_datetime(void)
{
    t_rtc rtcTime = {0};
    RTC_GetTimeOnly(&rtcTime);
    LOGS("DateTime (UTC): %d-%02d-%02d  %02d:%02d:%02d", \
         rtcTime.rtc_year + 2000, rtcTime.rtc_mon, rtcTime.rtc_day, rtcTime.rtc_hour, rtcTime.rtc_min, rtcTime.rtc_sec);
}

/******************************************************************************
 *  Function    -  track_test_gpstc_switch
 *
 *  Purpose     -  GPS数据透传开关切换
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 21-01-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static kal_bool track_test_gpstc_switch(void)
{
    if(track_status_gpstc(2) == 0)
    {
        track_status_gpstc(1);
        return TRUE;
    }
    else
    {
        track_status_gpstc(0);
        return FALSE;
    }
}


/******************************************************************************
 *  Function    -  track_test_pcba_unit_led
 *
 *  Purpose     -  LED 测试
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 18-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_test_pcba_unit_led(char* part2, char* part3)
{
    char result[100] = {0};

    if(strcmp((S8*)part2, "OFF") == 0)
    {
        //track_drv_led_set_all_off();
        track_drv_led_set_all(KAL_FALSE);
        sprintf(result, "All led off ");
    }
    else if(strcmp((S8*)part2, "ON") == 0)
    {
        //track_drv_led_set_all_on();
        track_drv_led_set_all(KAL_TRUE);
        sprintf(result, "All led on ");
    }
    else if(strcmp((S8*)part2, "R") == 0)
    {
        if(strcmp((S8*)part3, "ON") == 0)
        {
            track_drv_test_led_switch(LED_PWR, LedMode_ON);
            sprintf(result, "Red led on ");
        }
        else if(strcmp((S8*)part3, "OFF") == 0)
        {
            track_drv_test_led_switch(LED_PWR, LedMode_OFF);
            sprintf(result, "Red led off ");
        }
        else
        {
            sprintf(result, "%s", test_pcba_cmd_not_exist);
        }
    }
    else if(strcmp((S8*)part2, "G") == 0)
    {
        if(strcmp((S8*)part3, "ON") == 0)
        {
            track_drv_test_led_switch(LED_GSM, LedMode_ON);
            sprintf(result, "Green led on ");
        }
        else if(strcmp((S8*)part3, "OFF") == 0)
        {
            track_drv_test_led_switch(LED_GSM, LedMode_OFF);
            sprintf(result, "Green led off ");
        }
        else
        {
            sprintf(result, "%s", test_pcba_cmd_not_exist);
        }
    }
    else if(strcmp((S8*)part2, "B") == 0)
    {
        if(strcmp((S8*)part3, "ON") == 0)
        {
            track_drv_test_led_switch(LED_GPS, LedMode_ON);
            sprintf(result, "Blue led on ");
        }
        else if(strcmp((S8*)part3, "OFF") == 0)
        {
            track_drv_test_led_switch(LED_GPS, LedMode_OFF);
            sprintf(result, "Blue led off ");
        }
        else
        {
            sprintf(result, "%s", test_pcba_cmd_not_exist);
        }
    }
    else if(strcmp((S8*)part2, "E") == 0)
    {
        if(strcmp((S8*)part3, "ON") == 0)
        {
            track_drv_test_led_switch(LED_OBD, LedMode_ON);
            sprintf(result, "Orange led on ");
        }
        else if(strcmp((S8*)part3, "OFF") == 0)
        {
            track_drv_test_led_switch(LED_OBD, LedMode_OFF);
            sprintf(result, "Orange led off ");
        }
        else
        {
            sprintf(result, "%s", test_pcba_cmd_not_exist);
        }
    }
    else if(strcmp((S8*)part2, "KP") == 0)
    {
        sprintf(result, "%s", test_pcba_cmd_hw_not_support);
    }
    else if(strcmp((S8*)part2, "FLASH") == 0)
    {
        sprintf(result, "%s", "Power led flash");
        track_drv_test_led_switch(LED_PWR, LedMode_MedFlash);
    }
	else if(strcmp((S8*)part2, "TWO") == 0)
    {
		extern LED_TWO_COLOR_StatusSet(U8 status);
		int t = atoi(part3);
        sprintf(result, "TEST %d", t);
		LED_TWO_COLOR_StatusSet(t);
    }
    else
    {
        sprintf(result, "%s", test_pcba_cmd_not_exist);
    }

    LOGS("%s", result);
}

/******************************************************************************
 *  Function    -  track_test_pcba_unit_vib
 *
 *  Purpose     -  震动马达测试
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 21-01-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_test_pcba_unit_vib(char* part2, char* part3)
{
    char result[100] = {0};

    if(strcmp((S8*)part2, "OFF") == 0)
    {
        track_drv_set_vibr(KAL_FALSE);
        sprintf(result, "Vibration off");
    }
    else if(strcmp((S8*)part2, "ON") == 0)
    {
        track_drv_set_vibr(KAL_TRUE);
        sprintf(result, "Vibration on");
    }
    else
    {
        sprintf(result, "%s", test_pcba_cmd_not_exist);
    }

    LOGS("%s", result);
}

/******************************************************************************
 *  Function    -  track_test_display_delay_on/off
 *
 *  Purpose     -  LED 全部点亮并自动熄灭
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 18-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_test_display_delay_off()
{
    track_drv_led_set_all_off();
}

static void track_test_display_delay_on(kal_uint32 ms)
{
    track_drv_led_set_all_on();
    tr_start_timer(DISPLAY_TEST_TIMER_ID, ms, track_test_display_delay_off);
}

/******************************************************************************
 *  Function    -  track_test_pcba_gps_fix_time
 *
 *  Purpose     -  输出GPS启动到定位的时间
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 27-01-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_test_pcba_gps_fix_time_output(kal_bool output)
{
    static kal_uint32 start_tick = 0;
    kal_uint32 fix_tick, time_diff;

    if(!output)
    {
        start_tick = kal_get_systicks();
    }
    else
    {
        fix_tick = kal_get_systicks();
        time_diff = kal_ticks_to_secs(fix_tick - start_tick);

        if(test_gps_fix_time == 1)
        {
            LOGS("GPS positioning success (default start TTFF=%ds) ", time_diff);
        }
        else if(test_gps_fix_time == 2)
        {
            LOGS("GPS positioning success (hot TTFF=%ds) ", time_diff);
        }
        else if(test_gps_fix_time == 3)
        {
            LOGS("GPS positioning success (cold TTFF=%ds) ", time_diff);
        }
        else if(test_gps_fix_time == 4)
        {
            LOGS("GPS positioning success (warm TTFF=%ds) ", time_diff);
        }
        test_gps_fix_time = 0;
    }
}

/******************************************************************************
 *  Function    -  track_test_pcba_unit_gps
 *
 *  Purpose     -  GPS 测试
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 18-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_test_pcba_unit_gps(char* part2, char* part3)
{
    char result[150] = {0};
    int8 exe;
    U8 status = 0;
    mtk_param_epo_stage_cfg epo_stage = {0};

    if(strcmp((S8*)part2, "OFF") == 0)
    {
        exe = track_drv_gps_switch(0);

        if(exe == -1)
        {
            sprintf(result, "GPS had off ");
        }
        else
        {
            sprintf(result, "GPS off ");
        }

    }
    else if(strcmp((S8*)part2, "ON") == 0)
    {
        exe = track_drv_gps_switch(1);

        if(exe == -1)
        {
            sprintf(result, "GPS had on ");
        }
        else if(exe == -3)
        {
            sprintf(result, "GPS EPO disable ");
        }
        else
        {
            sprintf(result, "GPS on ");
            test_gps_fix_time = 1;
            track_test_pcba_gps_fix_time_output(KAL_FALSE);
        }

    }
    else if(strcmp((S8*)part2, "GLP") == 0)
    {
        extern nvram_realtime_struct  G_realtime_data;
        if(strcmp((S8*)part3, "ON") == 0)
        {
            G_realtime_data.glp = 1;
        }
        else
        {
            G_realtime_data.glp = 0;
        }
        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);

    }
    else if(strcmp((S8*)part2, "HOT") == 0)
    {
        sprintf(result, "%s", "GPS hot start (send cmd for restart)");
        track_drv_gps_hot_restart();
        test_gps_fix_time = 2;
        track_test_pcba_gps_fix_time_output(KAL_FALSE);

    }
    else if(strcmp((S8*)part2, "WARM") == 0)
    {
        sprintf(result, "%s", "GPS warm start (send cmd for warm restart)");
        track_drv_gps_warm_restart();
        test_gps_fix_time = 4;
        track_test_pcba_gps_fix_time_output(KAL_FALSE);
    }
    else if(strcmp((S8*)part2, "COLD") == 0)
    {
        sprintf(result, "%s", "GPS cold start (send cmd for COLD restart)");
        track_drv_gps_cold_restart();
        test_gps_fix_time = 3;
        track_test_pcba_gps_fix_time_output(KAL_FALSE);
        track_drv_cal_secset(1);
    }
    else if(strcmp((S8*)part2, "STATUS") == 0)
    {
        status = track_drv_get_gps_data()->status;
        if((status == 2) || (status == 3))
        {
            snprintf(result, sizeof(result), "GPS %dD Locate ,star=%d\r\nDateTime:%0.4d-%0.2d-%0.2d %0.2d:%0.2d:%0.2d\r\nLocate:%c %f,%c %f,speed=%0.2fkm/h", \
                     status, track_drv_get_gps_data()->gpgsv.Satellites_In_View, \
                     track_drv_get_gps_data()->gprmc.Date_Time.nYear, track_drv_get_gps_data()->gprmc.Date_Time.nMonth, \
                     track_drv_get_gps_data()->gprmc.Date_Time.nDay, track_drv_get_gps_data()->gprmc.Date_Time.nHour, \
                     track_drv_get_gps_data()->gprmc.Date_Time.nMin, track_drv_get_gps_data()->gprmc.Date_Time.nSec, \
                     track_drv_get_gps_data()->gprmc.NS, track_drv_get_gps_data()->gprmc.Latitude, \
                     track_drv_get_gps_data()->gprmc.EW, track_drv_get_gps_data()->gprmc.Longitude,
                     track_drv_get_gps_data()->gprmc.Speed);
        }
        else if(status == 1)
        {
            snprintf(result, sizeof(result), "GPS searching satellite (star=%d)", track_drv_get_gps_data()->gpgsv.Satellites_In_View);
        }
        else
        {
            sprintf(result, "GPS closed");
        }
    }
    else if(strcmp((S8*)part2, "GLP") == 0)
    {
        U8 i = atoi(part3);
        track_drv_set_gps_glp_mode(i);
    }
    else if(strcmp((S8*)part2, "EPO") == 0)
    {
        epo_stage = track_drv_get_epo_stage();
        sprintf(result, "AGPS EPO stage : %08X", epo_stage.u4EpoStage);
    }
    else if(strcmp((S8*)part2, "TC") == 0)
    {
        if(track_test_gpstc_switch())
        {
            sprintf(result, "%s", "GPS pass througt open");
        }
        else
        {
            sprintf(result, "%s", "GPS pass througt close");
        }

    }
    else if(strcmp((S8*)part2, "CLEAR") == 0)
    {
        track_drv_gps_claer_eph();
        sprintf(result, "Clear gps ephemeris");
    }
    else
    {
#if defined( __GPS_G3333__)||defined( __GPS_MT3333__)
        sprintf(result, "%s", "Current GPS Module is:GPS_G3333");
#elif defined(__GPS_MT3332__)
        sprintf(result, "%s", "Current GPS Module is:GPS_G3332");
#elif defined(__GPS_MT3336__)
        sprintf(result, "%s", "Current GPS Module is:GPS_MT3336");
#else
        sprintf(result, "%s", test_pcba_cmd_not_exist);
#endif /* __GPS_G3333__ */

    }

    LOGS("%s", result);

}


/******************************************************************************
 *  Function    -  track_test_sensor_count
 *
 *  Purpose     -  震动次数统计测试
 *
 *  Description -   track_test_pcba_unit_sensor_callback --->> track_test_sensor_count(KAL_TRUE);
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 07-03-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_test_sensor_count(kal_bool enable)
{
    static kal_uint32 count = 0;

    if(enable)
    {
        LOGS("震动 (%d) ,speed=%f", count, track_drv_get_gps_RMC()->Speed);
        count++;
    }
    else
    {
        track_drv_sensor_off();
        LOGS("统计结果: Level=%d , Count=%d", track_drv_get_sensor_level(), count);
        count = 0;
    }
}

void pcba_printf_xyz()
{
    char result[100] = {0};
        kal_int16 xx,yy,zz;
        U32 SUM;
        OTA_acc_sensor_get_6bytes(&xx,&yy,&zz);
        SUM = xx*xx+yy*yy+zz*zz;
        sprintf(result, "%d %d %d %d", xx,yy,zz,SUM);
tr_start_timer(PCBA_TEST_OUTPUT2_TIMER_ID, 100, pcba_printf_xyz);
LOGS("%s", result);
}

/******************************************************************************
 *  Function    -  track_test_pcba_unit_sensor / track_test_pcba_unit_sensor_callback
 *
 *  Purpose     -  sensor 测试
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 18-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_test_pcba_unit_sensor_callback(void)
{
    LOGS("%s", "Sensor ok");
    track_test_display_delay_on(2000);
}

static void track_test_pcba_unit_sensor(char* part2, char* part3)
{
    sensor_type_enum sensor_type;
    kal_uint8 level = 0, threshold = 0;
    short x, y, z;
    char result[100] = {0};

    if(strcmp((S8*)part2, "OFF") == 0)
    {
        track_drv_sensor_off();
        sprintf(result, "Sensor off ");
    }
    else if(strcmp((S8*)part2, "ON") == 0)
    {
        level = atoi(part3);
        if((level == 0) || (level > 5))
        {
            level = 2;
        }
        track_drv_sensor_on(level, track_test_pcba_unit_sensor_callback);
        sprintf(result, "Sensor on  (%d)", level);
    }
    else if(strcmp((S8*)part2, "STATUS") == 0)
    {
        sensor_type = track_drv_get_sensor_type();
        level = track_drv_get_sensor_level();

        if((sensor_type <= SENSOR_NOT_READY) || (sensor_type >= SENSOR_TYPE_MAX))
        {
            sprintf(result, "Warning:sensor type not detected");
        }
        else
        {
            if(level != 0xFF)
            {
                switch(sensor_type)
                {
                    case SENSOR_BMA250:
                        sprintf(result, "Bosch bma250 (ID=0x03),level=%d", level);
                        break;
                    case SENSOR_BMA250E:
                        sprintf(result, "Bosch bma250E (ID=0xF9),level=%d", level);
                        break;
                    case SENSOR_BMA253:
                        sprintf(result, "Bosch bma253 (ID=0xFA),level=%d", level);
                        break;
                    case SENSOR_KXTJ31057:
                        sprintf(result, "Kionix kxtj3-1057 (ID=0x35),level=%d", level);
                        break;
                    case SENSOR_SC7A20:
                        sprintf(result, "Silan SC7A20 (ID=0x11),level=%d", level);
                        break;
                    case SENSOR_DA213:
                        sprintf(result, "Mira DA213 (ID=0x13),level=%d", level);
                        break;   
                    default:
                        sprintf(result, "I do not know this gSensor");
                        break;
                }
            }
            else
            {
                threshold = track_drv_get_sensor_threshold();
                switch(sensor_type)
                {
                    case SENSOR_BMA250:
                        sprintf(result, "Bosch bma250,threshold=%d", threshold);
                        break;
                    case SENSOR_BMA250E:
                        sprintf(result, "Bosch bma250E,threshold=%d", threshold);
                        break;
                    case SENSOR_BMA253:
                        sprintf(result, "Bosch bma253,threshold=%d", threshold);
                        break;
                    case SENSOR_KXTJ31057:
                        sprintf(result, "Kionix kxtj3-1057,threshold=%d", threshold);
                        break;
                    case SENSOR_SC7A20:
                        sprintf(result, "Silan SC7A20,threshold=%d", threshold);
                        break; 
                    case SENSOR_DA213:
                        sprintf(result, "Mira DA213,threshold=%d", threshold);
                        break;  
                     default:
                        sprintf(result, "I do not know this gSensor ");
                        break;
                }
            }
        }
    }
    else if(strcmp((S8*)part2, "TEST") == 0)
    {
        threshold = atoi(part3);
        threshold = threshold & 0xFF;

        track_drv_sensor_threshold_start(threshold, track_test_pcba_unit_sensor_callback);
        sprintf(result, "Sensor start  for software test threshold (%d)", threshold);
    }
    else if(strcmp((S8*)part2, "XYZ") == 0)
    {
        static kal_bool b=KAL_FALSE;
        if(b)
        {
            b = KAL_FALSE;
            tr_start_timer(PCBA_TEST_OUTPUT2_TIMER_ID, 100, pcba_printf_xyz);
        }
        else
        {
            track_stop_timer(PCBA_TEST_OUTPUT2_TIMER_ID);
            b = KAL_TRUE;
        }
        
    }
    else
    {
        sprintf(result, "%s", test_pcba_cmd_not_exist);
    }

    LOGS("%s", result);
}

/******************************************************************************
 *  Function    -  track_test_pcba_unit_gpio
 *
 *  Purpose     -  GPIO 测试
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 18-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_test_pcba_unit_gpio(char* part2, char* part3)
{
    char result[100] = {0};
    kal_uint8 gpio;
    char output, exe = 0;

    if(test_pcba_cmd.len != 3 && test_pcba_cmd.len != 2)
    {
        sprintf(result, "%s", test_pcba_cmd_not_exist);
        LOGS("%s", result);
        return;
    }

    gpio = atoi(part2);

    if(strcmp((S8*)part3, "H") == 0)
    {
        output = 1;
        GPIO_ModeSetup(gpio, 0);
        GPIO_InitIO(1, gpio);
        GPIO_WriteIO(output, gpio);
        exe = track_GPIO_ReadIO(gpio);
    }
    else if(strcmp((S8*)part3, "L") == 0)
    {
        output = 0;
        GPIO_ModeSetup(gpio, 0);
        GPIO_InitIO(1, gpio);
        GPIO_WriteIO(output, gpio);
        exe = track_GPIO_ReadIO(gpio);
    }
	else if(strcmp((S8*)part3, "READ") == 0)
	{
        exe = GPIO_ReadIO(gpio);
        sprintf(result, "READ GPIO%d:%d:%d", gpio, exe,track_GPIO_ReadIO(gpio));
        LOGS("%s", result);
        return;
	}
    else
    {
        GPIO_ModeSetup(gpio, 0);
        GPIO_InitIO(1, gpio);
        exe = track_GPIO_ReadIO(gpio);
        sprintf(result, "GPIO%d:%d %d", gpio, exe, OTA_GPIO_ReturnDout(gpio));
        LOGS("%s", result);
        return;
    }
    /*else
    {
        sprintf(result, "%s", test_pcba_cmd_not_exist);
        LOGS("%s", result);
        return;
    }*/

    if(exe == output)
    {
        if(output == 0)
        {
            //track_drv_led_set_all_off();
        }
        else
        {
            //track_drv_led_set_all_on();
        }
        sprintf(result, "GPIO-%d output %s ok", gpio, part3);
    }
    else
    {
        track_test_display_delay_on(1000);
        sprintf(result, "Warn:GPIO-%s output %s fail", part2, part3);
    }

    LOGS("%s", result);
}


/******************************************************************************
 *  Function    -  track_test_pcba_eint_status
 *
 *  Purpose     -  输出全部触发后的中断状态
 *
 *  Description -  有些中断有使用，但从没被触发，则不会输出
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 22-01-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_test_pcba_eint_status(void)
{
    kal_uint8 i;
    kal_bool exist = KAL_FALSE;

    LOGS("%s", "The interrupt status after the trigger:");
    for(i = 0; i < TEST_PCBA_EINT_LIST_MAX; i++)
    {
        if(test_pcba_eint_list[i] != 0)
        {
            LOGS("Eint%d,Level=%c", i, test_pcba_eint_list[i]);
            exist = KAL_TRUE;
        }
    }

    if(!exist)
    {
        LOGS("No interrupt trigger");
    }
}


/******************************************************************************
 *  Function    -  track_test_pcba_unit_eint
 *
 *  Purpose     -  模拟中断触发
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 18-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_test_pcba_unit_eint(char* part2, char* part3)
{
    char result[100] = {0};
    kal_uint8 eint_id;
    char level;

    if(test_pcba_cmd.len == 2)
    {
        if(strcmp((S8*)part2, "STATUS") == 0)
        {
            track_test_pcba_eint_status();
            return;
        }
        else if(strcmp((S8*)part2, "AUTO") == 0)
        {
            if(test_paba_output.eint_output)
            {
                test_paba_output.eint_output = KAL_FALSE;
                sprintf(result, "%s", "Interrupt status automatic output disable");
            }
            else
            {
                test_paba_output.eint_output = KAL_TRUE;
                sprintf(result, "%s", "Interrupt status automatic output enable");
            }

            LOGS("%s", result);
            return;
        }
        else
        {
            sprintf(result, "%s", test_pcba_cmd_not_exist);
            LOGS("%s", result);
            return;
        }
    }
    else
    {
        eint_id = atoi(part2);
        if(eint_id == 0)
        {
            sprintf(result, "Warn:this one for GPS interrupt , can not execution");
            LOGS("%s", result);
            return;
        }
        else if(eint_id >= TEST_PCBA_EINT_LIST_MAX)
        {
            sprintf(result, "Warn:please check the interrupt number");
            LOGS("%s", result);
            return;
        }

        if(strcmp((S8*)part3, "H") == 0)
        {
            level = 1;
        }
        else if(strcmp((S8*)part3, "L") == 0)
        {
            level = 0;
        }
        else
        {
            sprintf(result, "%s", test_pcba_cmd_not_exist);
            LOGS("%s", result);
            return;
        }

        sprintf(result, "Forced to trigger [Eint%d ,Level=%s] for sw test", eint_id, part3);
        track_drv_eint_trigger_response(eint_id, level);

        LOGS("%s", result);
    }
}


/******************************************************************************
 *  Function    -  track_test_pcba_unit_lbs
 *
 *  Purpose     -  LBS 测试
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 18-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_test_pcba_unit_lbs(char* part2, char* part3)
{
    char result[150] = {0};
    int8 exe;
    U8 status = 0;

    if(strcmp((S8*)part2, "OFF") == 0)
    {
        exe = track_drv_lbs_info_switch(0);
        if(exe == -1)
        {
            sprintf(result, "LBS had off ");
        }
        else
        {
            sprintf(result, "LBS off ");
        }
    }
    else if(strcmp((S8*)part2, "ON") == 0)
    {
        exe = track_drv_lbs_info_switch(1);
        if(exe == -1)
        {
            sprintf(result, "LBS had on ");
        }
        else
        {
            sprintf(result, "LBS on ");
        }
    }
    else if(strcmp((S8*)part2, "STATUS") == 0)
    {
        status = track_drv_get_lbs_data()->status;
        if(status)
        {
            snprintf(result, sizeof(result) - 1, "MCC=%d,MNC=%02d,TA=%d;Main[%d,%2d,%d];Near {[%2d,%d] [%2d,%d] [%2d,%d] [%2d,%d] [%2d,%d] [%2d,%d]}#",
                     track_drv_get_lbs_data()->MainCell_Info.mcc, track_drv_get_lbs_data()->MainCell_Info.mnc, track_drv_get_lbs_data()->ta,
                     track_drv_get_lbs_data()->MainCell_Info.lac, track_drv_get_lbs_data()->MainCell_Info.cell_id, track_drv_get_lbs_data()->MainCell_Info.rxlev,
                     track_drv_get_lbs_data()->NbrCell_Info[0].cell_id, track_drv_get_lbs_data()->NbrCell_Info[0].rxlev ,
                     track_drv_get_lbs_data()->NbrCell_Info[1].cell_id, track_drv_get_lbs_data()->NbrCell_Info[1].rxlev ,
                     track_drv_get_lbs_data()->NbrCell_Info[2].cell_id, track_drv_get_lbs_data()->NbrCell_Info[2].rxlev ,
                     track_drv_get_lbs_data()->NbrCell_Info[3].cell_id, track_drv_get_lbs_data()->NbrCell_Info[3].rxlev ,
                     track_drv_get_lbs_data()->NbrCell_Info[4].cell_id, track_drv_get_lbs_data()->NbrCell_Info[4].rxlev ,
                     track_drv_get_lbs_data()->NbrCell_Info[5].cell_id, track_drv_get_lbs_data()->NbrCell_Info[5].rxlev);
        }
        else
        {
            sprintf(result, "LBS data stop");
        }

    }
    else
    {
        sprintf(result, "%s", test_pcba_cmd_not_exist);
    }

    LOGS("%s", result);

}


/******************************************************************************
 *  Function    -  track_test_pcba_unit_bb
 *
 *  Purpose     -  查看系统参数
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 21-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_test_pcba_unit_bb(char* part2, char* part3)
{
    char result[100] = {0}, temp[5];
    char i;
    char *chip_id;
    kal_int8 sim_type;

    if(strcmp((S8*)part2, "DT") == 0)
    {
        track_test_output_datetime();
    }
    else if(strcmp((S8*)part2, "ID") == 0)
    {
        chip_id = track_drv_get_chip_id();
        sprintf(result, "%s", "chip RID:");
        for(i = 0; i < 16; i++)
        {
            memset(temp, 0x00, sizeof(temp));
            sprintf(temp, "%0.2X ", *(chip_id  + i));
            strcat(result, temp);
        }
        LOGS("%s", result);
        LOGS("IMEI:%s", track_drv_get_imei(0));
    }
    else if(strcmp((S8*)part2, "SIM") == 0)
    {
        sim_type = track_drv_get_sim_type();
        track_remind_sim_for_factory(sim_type);
        if(sim_type == 1)
        {
            LOGS("IMSI:%s", track_drv_get_imsi(0));
        }
    }
    else if(strcmp((S8*)part2, "SW") == 0)
    {
        snprintf(result, sizeof(result), "[VERSION]%s\r\n[BUILD]%s", release_verno(), build_date_time());
        LOGS("%s", result);
    }
    else if(strcmp((S8*)part2, "OFF") == 0)
    {
        track_drv_sys_power_off_req();
        LOGS("Sorry,BB is still on!");
    }

    else if(strcmp((S8*)part2, "SLEEP") == 0)
    {
        track_drv_sensor_off();
        track_drv_gps_switch(0);
        track_drv_led_set_all_off();
        track_drv_led_status_lock(1);

        sprintf(result, "Enter sleep mode (turn off GPS, LED, sensor and only keep GPRS work)");
    }
    else
    {
        sprintf(result, "%s", test_pcba_cmd_not_exist);
        LOGS("%s", result);
    }
}

#if defined( __EXT_VBAT_ADC__)
/******************************************************************************
 *  Function    -  track_test_pcba_adc_output
 *
 *  Purpose     -  不断输出ADC原始值
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 22-01-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_test_pcba_adc_output()
{
    if(!test_paba_output.adc_output)
    {
        return;
    }

    track_drv_view_ext_batter();

    tr_start_timer(PCBA_TEST_OUTPUT_TIMER_ID, 2000, track_test_pcba_adc_output);
}
#endif /* __EXT_VBAT_ADC__ */

/******************************************************************************
 *  Function    -  track_test_pcba_unit_pmu
 *
 *  Purpose     -  查看电池状态
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 28-09-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_test_pcba_unit_pmu(char* part2, char* part3)
{
    char result[100] = {0};
    kal_int32 external_voltage;
    float external_batter;

    if(strcmp((S8*)part2, "BMT") == 0)
    {
        track_drv_bmt_charging_result(result);
        sprintf(result, "%s", result);
    }
    else if(strcmp((S8*)part2, "EXT") == 0)
    {
#if defined( __EXT_VBAT_ADC__)
        track_drv_view_ext_batter();
#else
        sprintf(result, "%s", test_pcba_cmd_hw_not_support);
#endif /* __EXT_VBAT_ADC__ */
    }
    else if(strcmp((S8*)part2, "ADC") == 0)
    {

#if defined( __EXT_VBAT_ADC__)
        if(test_paba_output.adc_output)
        {
            test_paba_output.adc_output = KAL_FALSE;
            track_drv_ext_vbat_measure_modify_parameters2(10, 6);
            tr_stop_timer(PCBA_TEST_OUTPUT_TIMER_ID);
            sprintf(result, "%s", "ADC data automatic output disable");
        }
        else
        {
            test_paba_output.adc_output = KAL_TRUE;
            track_drv_ext_vbat_measure_modify_parameters2(2, 1);
            tr_start_timer(PCBA_TEST_OUTPUT_TIMER_ID, 2000, track_test_pcba_adc_output);
            sprintf(result, "%s", "ADC data automatic output begian (uV)");
        }
#else
        sprintf(result, "%s", test_pcba_cmd_hw_not_support);
#endif /* __EXT_VBAT_ADC__ */

    }
    else if(strcmp((S8*)part2, "SLEEP") == 0)
    {
        track_drv_sensor_off();
        track_drv_gps_switch(0);
        track_drv_led_set_all_off();
        track_drv_led_status_lock(1);

        sprintf(result, "Enter sleep mode (turn off GPS, LED, sensor and only keep GPRS work)");
    }
    else
    {
        sprintf(result, "%s", test_pcba_cmd_not_exist);
    }
    LOGS("%s", result);
}

/******************************************************************************
 *  Function    -  track_test_pcba_gprs_send_always
 *
 *  Purpose     -  关闭静态过滤，GPRS 持续上报，供硬件测试电流
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 30-01-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_test_pcba_gprs_send_always(void)
{
    track_cust_sf_switch(0);
    LOGS("%s", "GPRS data send always");
}


/******************************************************************************
 *  Function    -  track_test_pcba_gprs_off
 *
 *  Purpose     -  关闭GPRS，并且禁止重启机制
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 30-01-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_test_pcba_gprs_off(void)
{
    track_soc_thorough_disconnect();
    track_cust_restart_disable();
    LOGS("%s", "Close GPRS and restart disable");
}

/******************************************************************************
 *  Function    -  track_test_pcba_gprs_status
 *
 *  Purpose     -  查看GPRS状态
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 30-01-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_test_pcba_gprs_status(void)
{
    extern char *track_soc_view_server_addr(void);
    char result[150] = {0}, tmp[50] = {0};
    char *server;
    kal_uint8 mode;
    kal_int8 sim_type;
    char * imei;
    track_soc_connstatus_enum status;

    imei = track_drv_get_imei(0);
    if((strlen(imei) == 0) || (strcmp(imei, "358688000000158") == 0))
    {
        LOGS("%s", "Warn:please download IMEI");
        return;
    }

    sim_type = track_drv_get_sim_type();
    if(sim_type <= 0)
    {
        LOGS("%s", "Warn:please check the SIM card");
        return;
    }

    status = Socket_get_conn_status(0);
    server = track_soc_view_server_addr();

    if(status == SOC_CONN_SUCCESSFUL)
    {
        snprintf(result, sizeof(result), "Connected to \"%s\" successfully", server);
    }
    else if(status == SOC_CONN_CONNECTING)
    {
        snprintf(result, sizeof(result), "Connecting to \"%s\"", server);
    }
    else
    {
        snprintf(result, sizeof(result), "Fail to connect to \"%s\"", server);
    }

    mode = track_cust_sf_switch(0xFF);
    if(mode == 0)
    {
        snprintf(tmp, sizeof(tmp), "%s", "Hardware testing mode (send all data)");
    }
    else
    {
        snprintf(tmp, sizeof(tmp), "%s", "Software normal mode (filter some data)");
    }

    LOGS("%s \r\n%s", result, tmp);
}

/******************************************************************************
 *  Function    -  track_test_pcba_unit_gprs
 *
 *  Purpose     -  网络测试
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 29-09-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_test_pcba_unit_gprs(char* part2, char* part3)
{
    char result[100] = {0};

    if(strcmp((S8*)part2, "PASS") == 0)
    {
        track_test_pcba_gprs_send_always();
    }
    else if(strcmp((S8*)part2, "OFF") == 0)
    {
        track_test_pcba_gprs_off();
    }
    else if(strcmp((S8*)part2, "STATUS") == 0)
    {
        track_test_pcba_gprs_status();
    }
    else
    {
        sprintf(result, "%s", test_pcba_cmd_not_exist);
        LOGS("%s", result);
    }

}

/******************************************************************************
 *  Function    -  track_test_driver_keypad
 *
 *  Purpose     -  按键测试
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 29-12-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_test_key_event_handle(void)
{
    LOGS("key ok");
    track_test_display_delay_on(200);
}

static void track_test_pcba_unit_keypad(char* part2, char* part3)
{
    char result[100] = {0};

    if(test_pcba_cmd.len == 1)
    {
#if defined(__KEYPAD_MOD__)
        sprintf(result, "%s", "KEY_SOS test");
        track_drv_set_key_handler(track_test_key_event_handle, KEY_SOS, KEY_EVENT_UP);
#else
        sprintf(result, "%s", test_pcba_cmd_hw_not_support);
#endif
    }
    else
    {
        sprintf(result, "%s", test_pcba_cmd_not_exist);
    }
    LOGS("%s", result);
}
static void track_test_pcba_unit_watchdog(char* part2, char* part3)
{

#if defined( __WATCH_DOG__)
    if(strcmp((S8*)part2, "START") == 0)
    {
        track_drv_watdog_init();
        LOGS("%s", "WDT Start");
    }
    else if(strcmp((S8*)part2, "STOP") == 0)
    {
        track_drv_watdog_close(0);
        LOGS("%s", "WDT Stop");
    }
    else if(strcmp((S8*)part2, "ENABLE") == 0)
    {
        track_drv_watchdog_enable();
        LOGS("%s", "WDT Enable");
    }
    else if(strcmp((S8*)part2, "DISABLE") == 0)
    {
        track_drv_watdog_close(2);
        LOGS("%s", "WDT Disable");
    }
    else if(strcmp((S8*)part2, "WRITEW") == 0)
    {
        WDT_Worng_Data_Test(0xA0A0);
        LOGS("%s", "WDT write wrong data ok!");
    }
    else if(strcmp((S8*)part2, "DISPLAY") == 0)
    {
        track_drv_watch_receive_display();
        LOGS("%s", "WDT Display");
    }
    else
    {
        LOGS("%s", test_pcba_cmd_not_exist);
    }
#else
    LOGS("%s", "This Project no support this function, not found 152!");
#endif /* __WATCH_DOG__ */
}

static void track_test_pcba_unit_lcd(char* part2, char* part3)
{
    kal_uint8 hour = 0, mins = 0;
#if defined(__OLED__)
    if(strcmp((S8*)part2, "BLACK") == 0)
    {
        track_drv_spi_set_background(0x00);
        LOGS("%s", "LCD BLACK");
    }
    else if(strcmp((S8*)part2, "WHITE") == 0)
    {
        track_drv_spi_set_background(0xFF);
        LOGS("%s", "LCD WHITE");
    }
    else if(strcmp((S8*)part2, "X") == 0)
    {

        LOGS("X:%d", "LCD Enable");
    }
    else if(strcmp((S8*)part2, "Y") == 0)
    {

        LOGS("%s", "LCD Disable");
    }
    else if(strcmp((S8*)part2, "WRITE") == 0)
    {

        LOGS("%s", "LCD WRITE");
    }
    else if(strcmp((S8*)part2, "TEST") == 0)
    {
        if(strlen(part3))
        {
            track_drv_lcd_display_test(atoi(part3));
            //LOGS("%s", "LCD TEST");
        }
    }
    else if(strcmp((S8*)part2, "TIME") == 0)
    {
        if(strlen(part3) > 3)
        {
            hour = (part3[0] - '0') * 10 + (part3[1] - '0');
            mins = (part3[2] - '0') * 10 + (part3[3] - '0');
            track_drv_lcd_write_time(hour, mins, hour, mins);
            LOGS("LCD TIME Updata time: %d%d:%d%d", part3[0], part3[1], part3[2], part3[3]);
        }
        else
        {
            LOGS("%s", "LCD TIME Arg3 Error");
        }
    }
    else if(strcmp((S8*)part2, "SLEEP") == 0)
    {
        if(strlen(part3) > 0)
        {
            if(part3[0] == '0')
            {
                track_drv_lcd_exit_sleep();
                LOGS("%s", "LCD Exit Sleep!");
                return;
            }
            else if(part3[0] == '2')
            {
                track_drv_Init_OLED_IC();
                LOGS("%s", "LCD INIT!");
                return;
            }
        }

        track_drv_lcd_enter_sleep();
        LOGS("%s", "LCD Enter Sleep!");
    }
    else
    {
        LOGS("%s", test_pcba_cmd_not_exist);
    }
#else
    LOGS("%s", "This Project no support this function, not found lcd!");
#endif /* __WATCH_DOG__ */
}

static void track_test_pcba_unit_obd(char* part2, char* part3)
{
    kal_uint8 hour = 0, mins = 0;
#if defined(__OBD__)
		if(strcmp((S8*)part2, "ON") == 0)
		{
			if(track_os_uart1_at_mode())
			{
				LOGD(L_DRV, L_V5, "Uart1 AT Mode, 不能切换成OBD使用");
			}
			else
			{
				LOGS("%s", "OBD ON");
				//track_obd_init();
				track_drv_obd_power_init();
			}
		}
		else if(strcmp((S8*)part2, "OFF") == 0)
		{
			LOGS("%s", "OBD OFF");
		}
		else if(strcmp((S8*)part2, "TEST") == 0)
		{
			//LOGS("%s", "LCD TEST");
		}
		else
		{
			LOGS("%s", test_pcba_cmd_not_exist);
		} 
#else
    LOGS("%s", "This Project no support this function, not found obd!");
#endif
}

#if defined(__LUYING__)
static void track_test_pcba_unit_rec(char* part2, char* part3)
{
    kal_uint8 hour = 0, mins = 0;
    if(strcmp((S8*)part2, "ON") == 0)
    {
        track_cust_record(0, 1, 10);
        LOGS("%s", "REC ON");
    }
    else if(strcmp((S8*)part2, "OFF") == 0)
    {
        track_cust_record(0, 0, 0);
        LOGS("%s", "REC OFF");
    }
    else if(strcmp((S8*)part2, "TEST") == 0)
    {

    }
    else
    {
        LOGS("%s", test_pcba_cmd_not_exist);
    }
}
#endif /* __LUYING__ */

static void track_test_pcba_unit_vmc(char* part2, char* part3)
{
    kal_uint8 level = 1 ;
    if(test_pcba_cmd.len != 3 && test_pcba_cmd.len != 2)
    {
        LOGS("%s", test_pcba_cmd_not_exist);
        return;
    }

    if(test_pcba_cmd.len == 3)
    {
        level = atoi(part3);
    }

    if(strcmp((S8*)part2, "ON") == 0)
    {
        track_drv_Set_VMC(KAL_TRUE, level);
        LOGS("\r\nVCM ON %d \t(1=1.8V 2=2.8V 3=3V 4=3.3V)\r\n",  level);
    }
    else if(strcmp((S8*)part2, "OFF") == 0)
    {
        track_drv_Set_VMC(KAL_FALSE, level);
        LOGS("%s", "\r\nVCM OFF\r\n");
    }
    else
    {
        LOGS("%s", test_pcba_cmd_not_exist);
    }
}

#if defined (__BLE_GATT__)

static void track_test_pcba_unit_ble(char* part2, char* part3)
{
    if(strcmp((S8*)part2, "ON") == 0)
    {
        extern kal_int8 track_drv_ble_gatt_switch(kal_uint8 status);
	 track_drv_ble_gatt_switch(1);
        LOGS("BLE ON");
    }
    else if(strcmp((S8*)part2, "OFF") == 0)
    {
        extern kal_int8 track_drv_ble_gatt_switch(kal_uint8 status);
        track_drv_ble_gatt_switch(0);
        LOGS("BLE OFF");
    }
    else if(strcmp((S8*)part2, "VERSION") == 0)
    {
        
    }
    else if(strcmp((S8*)part2, "FACTORY") == 0)
    {
       
    }    
    else
    {
        LOGS("%s", test_pcba_cmd_not_exist);
    }
}
		
#endif /* __BLE_GATT__ */

#if defined(__CUST_BT__)
static void track_test_pcba_unit_bt(char* part2, char* part3)
{
    if(test_pcba_cmd.len != 3 && test_pcba_cmd.len != 2)
    {
        LOGS("%s", test_pcba_cmd_not_exist);
        return;
    }
    if(strcmp((S8*)part2, "ON") == 0)
    {
        LOGS("BT ON");
        track_drv_bt_switch(1);
    }
    else if(strcmp((S8*)part2, "OFF") == 0)
    {
        LOGS("BT OFF");
        track_drv_bt_switch(0);
    }
    else if(strcmp((S8*)part2, "VERSION") == 0)
    {
        track_drv_bt_setting(BT_VERSINO_REQ);
    }
    else if(strcmp((S8*)part2, "FACTORY") == 0)
    {
        track_drv_bt_setting(BT_RESTORY_FACTORY_REQ);
    }
    else if(strcmp((S8*)part2, "TX") == 0)
    {
        LOGS("BT work in send mode");
        track_drv_set_bt_work_time(50, 0, 5);
    }
    else if(strcmp((S8*)part2, "RX") == 0)
    {
        LOGS("BT work in receive mode");
        track_drv_set_bt_work_time(5, 50, 5);
    }
    else if(strcmp((S8*)part2, "PARAM") == 0)
    {
        LOGS("set BT param");
        track_drv_set_bt_broadcast_param("GV22", track_drv_get_imei(1));
    }
    else
    {
        LOGS("%s", test_pcba_cmd_not_exist);
    }
}
#endif /* __CUST_BT__ */

#if defined (__CUST_RS485__)
static void track_test_pcba_unit_rs485_timeout(void)
{
    LOGS("%s", "RS485 FAIL");
}

static void track_test_pcba_unit_rs485(char* part2, char* part3)
{
    if(test_pcba_cmd.len != 2)
    {
        LOGS("%s", test_pcba_cmd_not_exist);
        return;
    }
	
    if(strcmp((S8*)part2, "STR") == 0)
    {
		char sendBuff[]={"RS485\r\n"};
		track_drv_rs485_write(sendBuff, strlen(sendBuff));
		tr_start_timer(TRACK_RS485_HW_TEST_TIMER_ID, 3000, track_test_pcba_unit_rs485_timeout);

    }
    else if(strcmp((S8*)part2, "HEX") == 0)
    {
		extern void track_rs485_read_vehicle_status_req(void);
		track_rs485_read_vehicle_status_req();
		tr_start_timer(TRACK_RS485_HW_TEST_TIMER_ID, 3000, track_test_pcba_unit_rs485_timeout);
    }
    else
    {
        LOGS("%s", test_pcba_cmd_not_exist);
    }

}
#endif /* __CUST_RS485__ */


#if defined (__CUST_UART1_MUX__)
extern void track_drv_uart1_mux_switch(kal_uint8 mode);
extern void track_drv_uart1_mux_write(kal_uint8 *data, int len);
static void track_test_pcba_unit_uart(char* part2, char* part3)
{
    if(test_pcba_cmd.len != 2)
    {
        LOGS("%s", test_pcba_cmd_not_exist);
        return;
    }
	
    if(strcmp((S8*)part2, "RS485") == 0)
    {
        LOGS("uart1 to RS485");
        track_drv_uart1_mux_switch(1);
        track_drv_uart1_mux_write("RS485",5);
    }
    else if(strcmp((S8*)part2, "RS232") == 0)
    {
        LOGS("uart1 to RS232");
        track_drv_uart1_mux_switch(2);
        track_drv_uart1_mux_write("RS232",5);
    }
    else if(strcmp((S8*)part2, "OFF") == 0)
    {
        LOGS("disable to RS485/RS232");
        track_drv_uart1_mux_switch(0);
    }
    else
    {
        LOGS("%s", test_pcba_cmd_not_exist);
    }

}
#endif /* __CUST_UART1_MUX__ */

/******************************************************************************
 *  Function    -  track_test_pcba_unit_sw_debug
 *
 *  Purpose     -  软件测试入口
 *
 *  Description - AT^GT_CM=PCBA,DEBUG,** [,**]
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 27-01-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_test_pcba_unit_sw_debug(char* part2, char* part3)
{
    kal_uint8 tmp2 = 0xFF, tmp3 = 0xFF;
    char result[100] = {0};

    tmp2 = atoi(part2);

    if(strlen(part3))
    {
        tmp3 = atoi(part3);
    }

    /*  增加临时测试接口*/
    switch(tmp2)
    {
        case 1:
            track_test_sensor_count(KAL_FALSE);
            break;

        case 2:
            {
            LOGD(L_DRV, L_V4, "sensor 自适应");
            track_drv_sensor_type_auto_matching();
            break;
        }
        case 3:
            {
            U8 gpio[]={14,20,25,33,34,32,36,35,31,54,53,55};
            int i=0;
            for(;i<sizeof(gpio);i++)
            {
                GPIO_ModeSetup(gpio[i], 0);
                GPIO_InitIO(0, gpio[i]);
                GPIO_WriteIO(0, gpio[i]);
                LOGS( "wf off %d",gpio[i]);
                
            }
        track_drv_Set_VMC(KAL_FALSE, 0);
            break;
        }
        case 4:
            {
                LOGD(L_DRV, L_V4, "随机值 %d", track_drv_get_one_day_reset_time());
            }
            break;
#if 0
        case 4:
            {
                unsigned int length;
                kal_uint8* buff;
                extern void track_cust_sms_send(kal_uint8 number_type, char *number, kal_bool isChar, kal_uint8 *data, kal_uint16 len);
                buff=(kal_uint8 *)track_os_get_string_buff(STR_GLOBAL_OK,track_language_German,&length);
                track_cust_sms_send(0, "15899793450", 0, buff, length);
                LOGS("德文短信 %d", length);
            }
            break;
#endif

#if defined (__CUST_FAKECELL__)
        case 5:
        {
            extern void track_cust_search_fake_cell();
            LOGD(L_DRV, L_V4, "模拟收到伪基站信息");
            track_cust_search_fake_cell();
        }
        break;

        case 6:
        {
            extern void track_cust_fake_cell_test_forced_alarm();
            LOGD(L_DRV, L_V4, "强制伪基站报警");
            track_cust_fake_cell_test_forced_alarm();
        }
        break;			
#endif /* __CUST_FAKECELL__ */
		
        default:
            sprintf(result, "%s", test_pcba_debug_not_exist);
            LOGS("%s", result);
            break;
    }
}

static void track_test_pcba_unit_sleep(char* part2, char* part3)
{

    if(strcmp((S8*)part2, "STATUS") == 0)
    {
        track_drv_check_sleep_status();
        LOGS("Sleep status:%d", track_drv_check_sleep_status());
    }
    else
    {
        LOGS("GPS OFF, System sleep.");
        track_cust_gps_control(0);
        track_drv_sleep_enable(SLEEP_MOD_ALL, KAL_TRUE);
    }
}

static void track_test_pcba_unit_mcu(CMD_DATA_STRUCT * cmd)
{
#if defined(__MCU_BJ8M601A_NT13V__)
    if(strcmp((S8*)cmd->pars[2], "VOLT") == 0)
    {
        U8 tmp[] = {0x53, 0x00, 0x00, 0x00, 0x00, 0x0D};
        float vl,vh;
        U16 l, h;
        vl = atof(cmd->pars[3]);
        vh = atof(cmd->pars[4]);
        vl = vl * 2048 / 11;
        vh = vh * 2048 / 11;
        l = vl;
        h = vh;
        tmp[1] = l >> 8;
        tmp[2] = l & 0x00FF;
        tmp[3] = h >> 8;
        tmp[4] = h & 0x00FF;
        track_drv_mcu_uart_write_data(tmp, 6);
    }
    else if(strcmp((S8*)cmd->pars[2], "EPOFF") == 0)
    {
        track_drv_mcu_send_data(MCU_CMD_SET_EXT_OFF);
    }
    else if(strcmp((S8*)cmd->pars[2], "EPON") == 0)
    {
        track_drv_mcu_send_data(MCU_CMD_SET_EXT_ON);
    }
    else if(strcmp((S8*)cmd->pars[2], "ADC") == 0)
    {
        extern kal_uint32 track_drv_get_external_voltage_from_mcu(void);
        float mcu_ext;

        mcu_ext=(float)track_drv_get_external_voltage_from_mcu();

        LOGS("MCU vExt:%0.2fV", mcu_ext / 1000000);
    }
    else if(strcmp((S8*)cmd->pars[2], "VERSION") == 0)
    {
        extern kal_uint8* track_drv_get_mcu_version(void);
        kal_uint8* ver=track_drv_get_mcu_version();
        if(strlen(ver)==0)
        {
            LOGS("MCU verson:null");//单片机初始化串口慢，可能未读取
        }
        else
        {
            LOGS("MCU verson:V%s", ver);
        }
    }
    else
    {
        LOGS("%s", test_pcba_cmd_not_exist);
    }
#endif /* __MCU_BJ8M601A_NT13V__ */
}

/******************************************************************************
 *  Function    -  track_test_pcba_help_remind
 *
 *  Purpose     -  提示该项目可以支持的全部指令
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 21-01-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_test_pcba_help_remind(void)
{
    char remind[1024] = {0};
    snprintf(remind, sizeof(remind),
             "now we can support these command :(AT^GT_CM=PCBA,)\r\n\r\n-----------------\r\n"
             "LED,OFF\r\n"
             "LED,ON\r\n"
             "LED,R,OFF\r\n"
             "LED,R,ON\r\n"
             "LED,G,OFF\r\n"
             "LED,G,ON\r\n"
             "LED,B,OFF\r\n"
             "LED,B,ON\r\n"
             "LED,E,OFF\r\n"
             "LED,E,ON\r\n"
             "LED,KP,OFF\r\n"
             "LED,KP,ON\r\n"
             "LED,LOCK\r\n"
             "LED,UNLOCK\r\n"
             "LED,FLASH\r\n\r\n"

             "VIB,OFF\r\n"
             "VIB,ON\r\n\r\n"
             "GPS,OFF\r\n"
             "GPS,ON\r\n"
             "GPS,HOT\r\n"
             "GPS,COLD\r\n"
             "GPS,STATUS\r\n"
             "GPS,EPO\r\n"
             "GPS,TC\r\n\r\n"

             "SENSOR,OFF\r\n"
             "SENSOR,ON,<1-5>\r\n"
             "SENSOR,STATUS\r\n"
             "SENSOR,TEST\r\n\r\n"

             "GPIO,N,H\r\n"
             "GPIO,N,L\r\n\r\n"

             "EINT,N,H\r\n"
             "EINT,N,L\r\n"
             "EINT,AUTO\r\n"
             "EINT,STATUS\r\n\r\n"

             "LBS,OFF\r\n"
             "LBS,ON\r\n"
             "LBS,STATUS\r\n\r\n"

             "BB,DT\r\n"
             "BB,ID\r\n"
             "BB,SIM\r\n"
             "BB,SW\r\n"
             "BB,OFF\r\n\r\n"

             "PMU,BMT\r\n"
             "PMU,EXT\r\n"
             "PMU,ADC\r\n"
             "PMU,SLEEP\r\n\r\n"

             "GPRS,PASS\r\n"
             "GPRS,STATUS\r\n"
             "GPRS,OFF\r\n\r\n"

             "KEY\r\n\r\n"

             "WDT,START\r\n"
             "WDT,STOP\r\n"
             "WDT,ENABLE\r\n"
             "WDT,DISABLE\r\n"
             "WDT,WRITEW\r\n"
             "WDT,DISPALY\r\n\r\n"

             "LCD,Black\r\n"
             "LCD,White\r\n"
             "LCD,B\r\n\r\n\r\n"

             "OBD,ON\r\n"
             "OBD,OFF\r\n"
             "OBD,TEST\r\n\r\n"

             "REC,ON\r\n",
             "REC,OFF\r\n\r\n",

             "VMC,ON\r\n",
             "VMC,OFF\r\n",

             "BT,ON\r\n",
             "BT,OFF\r\n",
             "BT,FACTORY\r\n",
             "BT,VERSION\r\n",

             "RS485\r\n",
             "\r\n-----------------\r\n"
            );
    LOGS("%s", remind);
}

/******************************************************************************
 *  Function    -  track_test_pcba_unit_main
 *
 *  Purpose     -  硬件单元测试
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 22-01-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_test_pcba_unit_main(test_pcba_enum type, CMD_DATA_STRUCT * cmd)
{
    char*part2, *part3;
    part2 = cmd->pars[2];
    part3 = cmd->pars[3];
    switch(type)
    {
        case TEST_PCBA_LED://LED
            track_test_pcba_unit_led(part2, part3);
            break;

        case TEST_PCBA_VIB://VIB
            track_test_pcba_unit_vib(part2, part3);
            break;

        case TEST_PCBA_GPS://GPS
            track_test_pcba_unit_gps(part2, part3);
            break;

        case TEST_PCBA_SENSOR://Sensor
            track_test_pcba_unit_sensor(part2, part3);
            break;

        case TEST_PCBA_GPIO://GPIO
            track_test_pcba_unit_gpio(part2, part3);
            break;

        case TEST_PCBA_EINT://Eint
            track_test_pcba_unit_eint(part2, part3);
            break;

        case TEST_PCBA_LBS://LBS
            track_test_pcba_unit_lbs(part2, part3);
            break;

        case TEST_PCBA_BB://BB
            track_test_pcba_unit_bb(part2, part3);
            break;

        case TEST_PCBA_PMU://PMU
            track_test_pcba_unit_pmu(part2, part3);
            break;

        case TEST_PCBA_GPRS://GPRS
            track_test_pcba_unit_gprs(part2, part3);
            break;

        case TEST_PCBA_KEY://KEY
            track_test_pcba_unit_keypad(part2, part3);
            break;

        case TEST_PCBA_WDT:
            track_test_pcba_unit_watchdog(part2, part3);
            break;

        case TEST_PCBA_LCD:
            track_test_pcba_unit_lcd(part2, part3);
            break;

        case TEST_PCBA_OBD:
            track_test_pcba_unit_obd(part2, part3);
            break;

#if defined(__LUYING__)
        case TEST_PCBA_REC:
            track_test_pcba_unit_rec(part2, part3);
            break;
#endif /* __LUYING__ */

        case TEST_PCBA_VMC:
            track_test_pcba_unit_vmc(part2, part3);
            break;

        case TEST_PCBA_DEBUG://DEBUG
            track_test_pcba_unit_sw_debug(part2, part3);
            break;

        case TEST_PCBA_SLEEP:
            track_test_pcba_unit_sleep(part2, part3);
            break;

#if defined(__CUST_BT__)
        case TEST_PCBA_BT:
            track_test_pcba_unit_bt(part2, part3);
            break;
#endif /* __CUST_BT__ */

#if defined (__BLE_GATT__)
            case TEST_PCBA_BLE:
            track_test_pcba_unit_ble(part2, part3);
            break;
#endif

#if defined (__CUST_RS485__)
        case TEST_PCBA_RS485:
            track_test_pcba_unit_rs485(part2, part3);
            break;
#endif /* __CUST_RS485__ */

#if defined (__CUST_UART1_MUX__)
        case TEST_PCBA_UART:
            track_test_pcba_unit_uart(part2, part3);
            break;
#endif /* __CUST_UART1_MUX__ */
        case TEST_PCBA_MCU:
            track_test_pcba_unit_mcu(cmd);
            break;

        default:
            LOGS("%s", test_pcba_cmd_not_exist);
            break;
    }
}

#if 1
//PCBA test cmd
#endif


/*****************************************************************************
 *  Global Functions			全局函数
 *****************************************************************************/

/******************************************************************************
 *  Function    -  track_drv_test_gps_fix_time
 *
 *  Purpose     -  计算GPS定位时间
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 28-12-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_test_gps_fix_time(void)
{
    if(test_gps_fix_time == 0)
    {
        return;
    }
    else
    {
        track_test_pcba_gps_fix_time_output(KAL_TRUE);
    }
}

/******************************************************************************
 *  Function    -  track_drv_test_pcba_eint_status_updata
 *
 *  Purpose     -  中断状态列表更新
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 22-01-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_test_pcba_eint_status_updata(U8 eint, U8 level)
{
    if(eint >= TEST_PCBA_EINT_LIST_MAX)
    {
        LOGS("Warn:Eint%d,Level=%d", eint, level);
        return;
    }

    if(level == 0)
    {
        test_pcba_eint_list[eint] = 'L';
    }
    else
    {
        test_pcba_eint_list[eint] = 'H';
    }

    if(test_paba_output.eint_output)
    {
        if(level == 0)
        {
            LOGS("Eint%d,Level=L", eint);
        }
        else
        {
            LOGS("Eint%d,Level=H", eint);
        }
    }
}


/******************************************************************************
 *  Function    -  track_drv_test_pcba_entry
 *
 *  Purpose     -  硬件PCBA 测试
 *
 *  Description -  AT^GT_CM=PCBA,part1,part2<,part3>
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 27-07-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_test_pcba_entry(U8 len, CMD_DATA_STRUCT * cmd)
{
    char result[100] = {0};
    kal_uint8 index;
    kal_bool find = KAL_FALSE;

    char *test_pcba_tab[TEST_PCBA_END] =
    {
        "LED",
        "VIB",
        "GPS",
        "SENSOR",
        "GPIO",
        "EINT",
        "LBS",
        "BB",
        "PMU",
        "GPRS",
        "KEY",
        "WDT",
        "LCD",
        "OBD",
        "REC",
        "VMC",
        "DEBUG",
        "SLEEP",
        "BT",
        "RS485",
        "UART",
        "BLE",
        "MCU"
    };
    //必须与test_pcba_enum 保持一致

    if(len == 0)
    {
        track_test_pcba_help_remind();
        return;
    }

     for(index = 0; index < TEST_PCBA_END; index++)
    {
        if(strcmp((S8*)test_pcba_tab[index], (S8*)cmd->pars[1]) == 0)
        {
            find = KAL_TRUE;
            break;
        }
    }

    if(find)
    {
        memset(&test_pcba_cmd, 0x00, sizeof(test_pcba_cmd));
        test_pcba_cmd.len = len;
        snprintf(test_pcba_cmd.part2, TEST_PCBA_CMD_LEN_MAX, "%s", cmd->pars[2]);
        snprintf(test_pcba_cmd.part3, TEST_PCBA_CMD_LEN_MAX, "%s", cmd->pars[3]);
        track_test_pcba_unit_main((test_pcba_enum)index, cmd);
    }
    else
    {
        sprintf(result, "%s", test_pcba_cmd_not_exist);
        LOGS("%s", result);
    }
}



#endif /* __TEST_PCBA__ */


