/******************************************************************************
 * track_led_driver.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        LED 驱动IO 控制
 *
 * modification history
 * --------------------
 * v1.0   2012-07-22,  chengjun create this file
 *
 ******************************************************************************/
/****************************************************************************
* Include Files                   		包含头文件
*****************************************************************************/
#include "track_drv.h"
#include "track_drv_led.h"
#include "track_os_ell.h"
/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/

/*****************************************************************************
* Typedef  Enum
*****************************************************************************/


/*****************************************************************************
 *  Struct					数据结构定义
 *****************************************************************************/


/*****************************************************************************
* Local variable				局部变量
*****************************************************************************/
static LED_Flash_Struct LED_Flash_Config[LED_Num_Max] = {0};        //LED 闪烁的参数
static U8 LED_Pre_Status[LED_Num_Max] = {0};                        //LED 当前模式
static kal_uint8 led_flag = 1;//2充电状态下红灯不休眠  //定义为枚举值加注释 chengjun
static led_loop_main_struct *loop_data = NULL;
static kal_uint8 led_loop_count = 0;
/*****************************************************************************
* Golbal variable				全局变量
*****************************************************************************/


/****************************************************************************
* Global Variable - Extern          引用全局变量
*****************************************************************************/



/*****************************************************************************
 *  Global Functions	- Extern		引用外部函数
 *****************************************************************************/


/*****************************************************************************
 *  Local Functions			本地函数
******************************************************************************/
void track_drv_led_vcama(kal_bool on)
{
    track_drv_set_vcama(on,0);
}

void track_drv_gpio_con_led(kal_bool state,kal_uint8 port)
{
    char rece,rece1;
    GPIO_ModeSetup(port, 0);
    GPIO_InitIO(1, port);
    rece = track_GPIO_ReadIO(port);
    LOGD(L_DRV, L_V7, "port%d=%d -> %d", port, rece, state);
    if (state == 0 || state == 1)
    {
        if (rece != state)
        {
            int i;
            for (i = 0; i < 3; i++)
            {
                // 最多重复设置3次，防止设置失败。
                GPIO_WriteIO(state, port);
                rece = track_GPIO_ReadIO(port);
				rece1 = GPIO_ReadIO(port);
                if(rece == state || rece1==state)
                {
                    return;
                }
            }
            if (rece != state)
            {
                LOGD(L_DRV, L_V5,"Can not option GPIO:%d", port);
                return;
            }
        }
    }
}
void track_drv_kpled(PMU_ISINK_LIST_ENUM isink,kal_bool enable)
{
#if 0    
    char race,port=50;
    GPIO_ModeSetup(port, 0);
    GPIO_InitIO(1, port);
    GPIO_WriteIO(!enable, port);
    race = GPIO_ReadIO(port);   
    LOGD(L_DRV, L_V7, "port%d=enable %d ->race %d,inink %d", port, enable, race,isink); 
#endif     
    pmu_drv_bl_isink(isink,enable);
}

/******************************************************************************
 *  Function    -  led_switch
 *
 *  Purpose     -  LED开关切换
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void led_switch(LED_Type led, kal_bool on)
{
    if(led < LED_Num1 || led >= LED_Num_Max)
    {
        return;
    }
    CTimer_Stop(CTIMER_ID_FLASH_NUM + led);

    switch(led)
    {
        case LED_Num1:
            if(on)
            {
                LED_Num1_ON();
            }
            else
            {
                LED_Num1_OFF();
            }
            break;

        case LED_Num2:
            if(on)
                LED_Num2_ON();
            else
                LED_Num2_OFF();
            break;

        case LED_Num3:
            if(on)
                LED_Num3_ON();
            else
                LED_Num3_OFF();
            break;
        case LED_Num4:
            if(on)
                LED_Num4_ON();
            else
                LED_Num4_OFF();
            break;
        default:
            break;
    }
}

/******************************************************************************
 *  Function    -  LED_Num_Flash_CallBack
 *
 *  Purpose     -  LED闪烁变化处理
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void LED_Num_Flash_CallBack(void *arg)
{
    kal_uint32 led = (kal_uint32)arg;
    //LOGD(L_DRV, L_V3, "LED=%d, loop_data=%p", led, loop_data);

    if(led >= LED_Num1 && led < LED_Num_Max)
    {
        //LOGD(L_DRV, L_V2, "LED=%d", led);
        if(!LED_Flash_Config[led].valid)
        {
            return;
        }
        //LOGD(L_DRV, L_V6, "LED=%d, status=%d, on=%d, off=%d", led, LED_Flash_Config[led].status, LED_Flash_Config[led].timeOn, LED_Flash_Config[led].timeOff);
        if(LED_Flash_Config[led].status)
        {
            led_switch(led, FALSE);
            LED_Flash_Config[led].status = FALSE;
            if(LED_Flash_Config[led].cycleCountVilid)
            {
                if(LED_Flash_Config[led].cycleCount > 0)
                {
                    LED_Flash_Config[led].cycleCount--;
                    CTimer_Start(CTIMER_ID_FLASH_NUM + led, LED_Flash_Config[led].timeOff, LED_Num_Flash_CallBack, arg);
                }
            }
            else
            {
                CTimer_Start(CTIMER_ID_FLASH_NUM + led, LED_Flash_Config[led].timeOff, LED_Num_Flash_CallBack, arg);
            }
        }
        else
        {
            led_switch(led, TRUE);
            LED_Flash_Config[led].status = TRUE;
            CTimer_Start(CTIMER_ID_FLASH_NUM + led, LED_Flash_Config[led].timeOn, LED_Num_Flash_CallBack, arg);
        }
    }
    else if(led == 255 && loop_data != NULL)
    {
        //LOGD(L_DRV, L_V2, "loop=%d, led_loop_count=%d, valid=%d, delay=%d", loop_data->loop, led_loop_count, loop_data->leds[led_loop_count].valid, loop_data->leds[led_loop_count].delay);
        if(loop_data->loop > LED_LOOP_Max)
        {
            if(loop_data->exit_function != NULL)
                loop_data->exit_function();
            loop_data = NULL;
        }
        else
        {
            if(loop_data->loop == 0 && led_loop_count > 0 && !loop_data->leds[led_loop_count].valid)
            {
                led_loop_count = 0;
                LOGD(L_DRV, L_V7, " 1 led_loop_count %d",led_loop_count);
            }
            else if (loop_data->loop > 0 && led_loop_count > loop_data->loop)//此处用于在设防状态下强制控制灯闪烁问题
            {
                led_loop_count = 0;
                LOGD(L_DRV, L_V2, " 2 led_loop_count %d",led_loop_count);
            }
            if(led_loop_count == 0 && !loop_data->leds[led_loop_count].valid)
            {
                if(loop_data->exit_function != NULL)
                    loop_data->exit_function();
                loop_data = NULL;
            }
            if(!loop_data->leds[led_loop_count].valid || loop_data->leds[led_loop_count].delay == 0
                    || (loop_data->loop > 0 && led_loop_count >= loop_data->loop))
            {
                if(loop_data->exit_function != NULL)
                    loop_data->exit_function();
                loop_data = NULL;
            }
            else
            {
                int i;
                for(i = 0; i < LED_Num_Max; i++)
                {
                    led_switch(i, loop_data->leds[led_loop_count].status[i]);
                }
                CTimer_Start(CTIMER_ID_FLASH_NUM, loop_data->leds[led_loop_count].delay, LED_Num_Flash_CallBack, arg);
                led_loop_count++;
            }
        }
    }
}

#if 1
/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/
#endif
/******************************************************************************
 *  Function    -  track_drv_led_loop
 *
 *  Purpose     -  LED组合式复合闪处理
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_drv_led_loop(led_loop_main_struct *data)
{
    int i;
    kal_uint32 arg = 255;
    LOGD(L_DRV, L_V2, "led_flag = %d,data=%p",led_flag,data);
    loop_data = data;
    if(!led_flag)
    {
        if(data != NULL)
        {
            if(data->exit_function != NULL)
            {
                data->exit_function();
            }
        }
        return;
    }
    for(i = 0; i < LED_Num_Max; i++)
    {
        led_switch(i, 0);
    }
    CTimer_Start(CTIMER_ID_FLASH_NUM, 300, LED_Num_Flash_CallBack, (kal_uint32*)arg);
}

/******************************************************************************
 *  Function    -  track_drv_led_blinking_cycle
 *
 *  Purpose     -  跑马灯处理
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_drv_led_blinking_cycle(LED_Type led, kal_bool on, kal_uint32 delay, kal_uint32 timeOn, kal_uint32 timeOff, kal_uint16 cycleCount)
{
    U32 arg = led;
    if(led < LED_Num1 || led >= LED_Num_Max)
    {
        LOGD(L_DRV, L_V2, "LED=%d", led);
        return;
    }
    LED_Flash_Config[led].valid = KAL_TRUE;
    LED_Flash_Config[led].timeOn = timeOn;
    LED_Flash_Config[led].timeOff = timeOff;
    LED_Flash_Config[led].status = on;
    LED_Flash_Config[led].cycleCount = cycleCount;
    LED_Flash_Config[led].delayStart = delay;
    if(LED_Flash_Config[led].cycleCount > 0)
        LED_Flash_Config[led].cycleCountVilid = KAL_TRUE;
    else
        LED_Flash_Config[led].cycleCountVilid = KAL_FALSE;
    //LOGD(L_DRV, L_V6, "LED=%d, delay=%d", led, delay);
    if(!led_flag) return;
    led_switch(led, LED_Flash_Config[led].status);
    if(LED_Flash_Config[led].delayStart)
        CTimer_Start(CTIMER_ID_FLASH_NUM + led, LED_Flash_Config[led].delayStart, LED_Num_Flash_CallBack, (void*)arg);
    else if(LED_Flash_Config[led].status)
        CTimer_Start(CTIMER_ID_FLASH_NUM + led, LED_Flash_Config[led].timeOn, LED_Num_Flash_CallBack, (void*)arg);
    else
        CTimer_Start(CTIMER_ID_FLASH_NUM + led, LED_Flash_Config[led].timeOff, LED_Num_Flash_CallBack, (void*)arg);
}


/******************************************************************************
 *  Function    -  LED_Set_Flash
 *
 *  Purpose     -  单一闪烁处理
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * v1.1 , 20140627  ,wangqi
 * ----------------------------------------
*******************************************************************************/
void LED_Set_Flash(LED_Type led, kal_uint32 timeOn, kal_uint32 timeOff)
{
    U32 arg = led;
    int i;
    LED_Flash_Config[led].valid = KAL_TRUE;
    LED_Flash_Config[led].timeOn = timeOn;
    LED_Flash_Config[led].timeOff = timeOff;
    LED_Flash_Config[led].status = TRUE;
    loop_data = NULL;
    led_loop_count = 0;

#if defined(__GT300S__)
    if(!led_flag || (led_flag == 2 && led != LED_PWR ))
    {
       LOGD(L_DRV, L_V1, "LED=%d, i=%d", led, i);
      return;
    }

#else
    for(i = LED_Num1; i < LED_Num_Max; i++)
    {
        LOGD(L_DRV, L_V7, "LED=%d,%d, %d?%d, %d?%d status:%d", led, i, LED_Flash_Config[i].timeOn, timeOn, 
            LED_Flash_Config[i].timeOff, timeOff, LED_Flash_Config[i].status);
        if(i != led && LED_Flash_Config[i].timeOn == timeOn && LED_Flash_Config[i].timeOff == timeOff)
        {
            LED_Flash_Config[led].status = LED_Flash_Config[i].status;
            LOGD(L_DRV, L_V6, "LED=%d, i=%d", led, i);
        }
    }
    if(!led_flag) return;
#endif
    led_switch(led, LED_Flash_Config[led].status);
    if(LED_Flash_Config[led].delayStart)
        CTimer_Start(CTIMER_ID_FLASH_NUM + led, LED_Flash_Config[led].delayStart, LED_Num_Flash_CallBack, (void*)arg);
    else if(LED_Flash_Config[led].status)
        CTimer_Start(CTIMER_ID_FLASH_NUM + led, LED_Flash_Config[led].timeOn, LED_Num_Flash_CallBack, (void*)arg);
    else
        CTimer_Start(CTIMER_ID_FLASH_NUM + led, LED_Flash_Config[led].timeOff, LED_Num_Flash_CallBack, (void*)arg);
}

/******************************************************************************
 *  Function    -  track_drv_led_switch
 *
 *  Purpose     -  开关切换
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_drv_led_switch(LED_Type led, kal_bool on)
{
    if(led < LED_Num1 || led >= LED_Num_Max)
    {
        return;
    }
    LOGD(L_DRV, L_V8, "LED=%d, on=%d,%d", led, on,led_flag);
    LED_Flash_Config[led].valid = KAL_FALSE;
    LED_Flash_Config[led].status = on;
    loop_data = NULL;
    led_loop_count = 0;
#if defined(__GT300S__)
    if((!led_flag || (led_flag == 2 && led != LED_PWR))&&!track_is_testmode()) return;
#else
    if(!led_flag) return;
#endif
    led_switch(led, on);
}

/******************************************************************************
 *  Function    -  track_drv_test_led_switch
 *  Purpose     -  驱动层针对具体硬件的测试指令，请勿加功能逻辑
 *  Description -
 *  modification history
 * ----------------------------------------
 * v1.0  , 20150629,  wangqi  written
 * ----------------------------------------
*******************************************************************************/
void track_drv_test_led_switch(LED_Type led, kal_bool on)
{
    if(led < LED_Num1 || led >= LED_Num_Max)
    {
        return;
    }
    LOGD(L_DRV, L_V8, "LED=%d, on=%d", led, on);
    led_switch(led, on);
}
/******************************************************************************
 *  Function    -  track_drv_led_set_all
 *  Purpose     -  驱动层针对具体硬件的测试指令，请勿加功能逻辑
 *  Description -
 *  modification history
 * ----------------------------------------
 * v1.0  , 20150629,  wangqi  written
 * ----------------------------------------
*******************************************************************************/
void track_drv_led_set_all(kal_bool on)
{
    U8 i;

    if(on != KAL_TRUE && on != KAL_FALSE)
    {
        LOGD(L_DRV, L_V5, "What is the ghost!",  on);
        return;
    }
    for(i = 0; i < LED_Num_Max; i++)
    {
        track_drv_test_led_switch(i, on);
    }

    for(i = 0; i < LED_Num_Max; i++)
    {
        LED_Pre_Status[i] = on;
    }
}


/******************************************************************************
 *  Function    -  LED_SetPort_Init_GPIO
 *
 *  Purpose     -  配置LED  端口
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 12-01-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void LED_SetPort_Init_GPIO(U8 port)
{
    GPIO_ModeSetup(port, 0);
    GPIO_InitIO(1, port);
}

/******************************************************************************
 *  Function    -  track_drv_led_set_status
 *
 *  Purpose     -  LED 指示灯控制
 *
 *  Description -
 *      led        [in]  指示灯别名
 *      Mode       [in]  模式
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 12-01-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_led_set_status(LED_Type led, LED_Mode Mode)
{
#ifdef __LED_DEBUG__
    LOGD(L_DRV, L_V8, "LED=%d,Mode=%d", led, Mode);
#endif
    if(led == LED_NULL)
    {
        return;
    }

    if(track_drv_led_status_lock(0xFF) == 1)
    {
        return;
    }

    if((led < LED_Num1) || (led >= LED_Num_Max) || (Mode < LedMode_OFF) || (Mode >= LedMode_Max))
    {
        ASSERT(0);
    }

    LED_Pre_Status[led] = Mode;        //  记录LED  的当前模式

    if((Mode == LedMode_ON) || (Mode == LedMode_OFF))
    {
        track_drv_led_switch(led, Mode);
    }
    else
    {
        //LED_Set_Flash(led, Mode);
    }

}

/******************************************************************************
 *  Function    -  track_drv_led_set_all_off
 *
 *  Purpose     -  关闭全部LED
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 12-01-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_led_set_all_off(void)
{
    U8 i;

    if(track_drv_led_status_lock(0xFF) == 1)
    {
        return;
    }

    for(i = 0; i < LED_Num_Max; i++)
    {
        track_drv_led_switch(i, FALSE);
    }

    for(i = 0; i < LED_Num_Max; i++)
    {
        LED_Pre_Status[i] = LedMode_OFF;
    }
}

/******************************************************************************
 *  Function    -  track_drv_led_set_all_on
 *
 *  Purpose     -  打开全部LED
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 12-01-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_led_set_all_on(void)
{
    U8 i;

    if(track_drv_led_status_lock(0xFF) == 1)
    {
        return;
    }


    for(i = 0; i < LED_Num_Max; i++)
    {
        track_drv_led_switch(i, TRUE);
    }
    for(i = 0; i < LED_Num_Max; i++)
    {
        LED_Pre_Status[i] = LedMode_ON;
    }
}

/******************************************/
/*        下列函数属于工厂测试用到的      */
/******************************************/
/******************************************************************************
 *  Function    -  track_drv_led_factory_mode
 *
 *  Purpose     -  进/出LED工厂测试模式
 *
 *  Description -  sw = true  进入LED工厂测试模式
 *                    = false 退出LED工厂测试模式
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_drv_led_factory_mode(kal_bool sw)
{
    int i;
    LOGD(L_DRV, L_V7, "sw:%d", sw);
    if(sw)
    {
        led_flag = 0;
        for(i = 0; i < LED_Num_Max; i++)
        {
            led_switch(i, 0);
            //CTimer_Stop(CTIMER_ID_FLASH_NUM + i);
        }
    }
    else
    {
        led_flag = 1;
    }
}

void track_drv_led_switch_factory(LED_Type led, kal_bool on)
{
    LOGD(L_DRV, L_V8, "led_flag=%d", led_flag);
    if(led < LED_Num1 || led >= LED_Num_Max || led_flag)
    {
        LOGD(L_DRV, L_V8, "return");
        return;
    }
    LOGD(L_DRV, L_V8, "LED=%d, on=%d", led, on);
    led_switch(led, on);
}

/******************************************************************************
 *  Function    -  track_drv_led_sleep
 *
 *  Purpose     -  LED休眠处理
 *
 *  Description -  参数
 *                  1 退出休眠(可以屏蔽该参数)
 *                  2 进入休眠(关闭所有LED灯)
 *                  3 充电状态下红灯不休眠
 *                 10 禁止参数等于1的执行
 *                 11 恢复参数等于1的执行，并且退出休眠
 *                 99 查询当前的休眠状态，返回1表示当前处于LED休眠，0表示当前处于正常显示
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-01-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_uint8 track_drv_led_sleep(kal_int8 par)
{
    static kal_uint8 status = 0;
    LOGD(L_DRV, L_V7, "status:%d, par:%d led_flag:%d", status, par, led_flag);
    if(par == 99)
    {
        return led_flag;
    }
    if(status != 99)
    {
        if(par == 1 && status != 1)
        {
            //退出休眠
            status = 1;
            track_drv_led_factory_mode(0);
#if defined( __OLED__)
            track_cust_lcd_exit_sleep();
#endif /* __OLED__ */
        }
        else if(par == 2)
        {
            //进入休眠
            if(track_is_testmode()) return;
            status = 2;
            track_drv_led_factory_mode(1);
            track_drv_led_switch_factory(0, 0);
            track_drv_led_switch_factory(1, 0);
            track_drv_led_switch_factory(2, 0);
#if defined( __OLED__)
            track_cust_lcd_enter_sleep();
#endif /* OLED */
        }
        else if(par == 3)
        {
            CTimer_Stop(CTIMER_ID_FLASH_NUM);
            status = 3;
            led_flag = 2;
            led_switch(LED_GSM, 0);
            led_switch(LED_GPS, 0);
        }
    }
    if(par == 10)
    {
        status = 99;
    }
    else if(par == 11)
    {
        status = 0;
        track_drv_led_factory_mode(0);
    }
    return 0;
}

/******************************************************************************
 *  Function    -  track_drv_led_status_lock
 *
 *  Purpose     -  LED 状态锁
 *
 *  Description -
 *
 * status [in]   1   =   锁LED ，后续操作LED 无效
 *                   0    =   解锁
 *                0xFF =   查询当前锁状态
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 20-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
kal_int8 track_drv_led_status_lock(U8 status)
{
    static U8 lock = 0;
    if(status == 0xFF)
    {
        return lock;
    }
    else if((status == 0) || (status == 1))
    {
        lock = status;
        return lock;
    }
    else
    {
        return -1;
    }
}

kal_uint8 track_drv_led_sleep_status(void)
{
    LOGD(L_DRV, L_V7, "led_flag:%d", led_flag);
    return led_flag;
}

void track_drv_led_by_power(LED_Type led, kal_bool on)
{
    led_switch(led, on);
}

void track_drv_pwr_on_rled_init()
{
	track_drv_gpio_con_led(KAL_TRUE,48);//开机后红灯由3口控制
}
