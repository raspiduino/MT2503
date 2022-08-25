/******************************************************************************
 * track_drv_uart1_mux.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        串口1复用切换处理
 *
 * modification history
 * --------------------
 * v1.0   2017-04-18,  chengjun create this file
 *
 ******************************************************************************/
#if defined(__CUST_UART1_MUX__)
/****************************************************************************
* Include Files                         包含头文件
*****************************************************************************/
#include "track_os_log.h"
#include "track_os_ell.h"
#include "track_drv_system_param.h"

/*****************************************************************************
* Typedef  Enum                         枚举定义
*****************************************************************************/

/*****************************************************************************
 *  Struct                              数据结构定义
 *****************************************************************************/


/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/
//高使能
#define GPIO_RS485_AND_RS232_EN     29

//高-RS485/低-RS232
#define GPIO_RS485_OR_RS232_CS     27

//高-RS485发/低-RS485收
#define GPIO_RS485_TX_RX_EN     3

/*****************************************************************************
* Local variable                        局部变量
*****************************************************************************/
static kal_uint8 uart1_mux_mode = 0;
//0=uart1
//1=RS485
//2=RS232

/****************************************************************************
* Global Variable                       全局变量
*****************************************************************************/


/****************************************************************************
* Global Variable - Extern              引用全局变量
*****************************************************************************/


/*****************************************************************************
 *  Global Functions    - Extern        引用外部函数
 *****************************************************************************/

/*****************************************************************************
 *  Local Functions                     本地函数
 *****************************************************************************/


/*****************************************************************************
 *  Global Functions			全局函数
 *****************************************************************************/
static void track_drv_rs485_rs232_gpio_init(void)
{
    static kal_uint8 first = 0;
    if(first == 0)
    {
        first = 1;
        GPIO_ModeSetup(GPIO_RS485_AND_RS232_EN, 0);
        GPIO_InitIO(1, GPIO_RS485_AND_RS232_EN);
        GPIO_WriteIO(0, GPIO_RS485_AND_RS232_EN);
        GPIO_ModeSetup(GPIO_RS485_OR_RS232_CS, 0);
        GPIO_InitIO(1, GPIO_RS485_OR_RS232_CS);
        GPIO_WriteIO(0, GPIO_RS485_OR_RS232_CS);
        GPIO_ModeSetup(GPIO_RS485_TX_RX_EN, 0);
        GPIO_InitIO(1, GPIO_RS485_TX_RX_EN);
        GPIO_WriteIO(0, GPIO_RS485_TX_RX_EN);
    }
}

static void  delay_1ms(kal_uint16 ms)
{
    volatile kal_uint16 i;
    while(ms--)
    {
        for(i = 0; i < 2048; i++)
        {
            ;
        }
    }
}

void track_drv_uart1_init_delay(void)
{
    track_drv_rs485_rs232_gpio_init();
    LOGD(L_DRV, L_V1, "10秒后切换串口");

}

void track_drv_uart1_mux_switch(kal_uint8 mode)
{
    if(mode == 1) //RS485
    {
        GPIO_WriteIO(1, GPIO_RS485_OR_RS232_CS);
        GPIO_WriteIO(1, GPIO_RS485_AND_RS232_EN);
        GPIO_WriteIO(0, GPIO_RS485_TX_RX_EN);
        uart1_mux_mode = 1;
    }
    else if(mode == 2) //RS232
    {
        GPIO_WriteIO(0, GPIO_RS485_OR_RS232_CS);
        GPIO_WriteIO(1, GPIO_RS485_AND_RS232_EN);
        uart1_mux_mode = 2;
    }
    else
    {
        GPIO_WriteIO(0, GPIO_RS485_AND_RS232_EN);
        uart1_mux_mode = 0;
    }
}

void track_drv_uart1_mux_write(kal_uint8 *data, int len)
{
    if(len < 2000)
    {
        LOGD(L_DRV, L_V5, "UART>>%s", (char*)data);
    }

    if(uart1_mux_mode == 0)
    {
        LOGD(L_DRV, L_V5, "RS485 RS232 disable");
        return;
    }

    track_drv_sleep_enable(SLEEP_EXT_UART_MOD, KAL_FALSE);

    if(uart1_mux_mode == 1) //rs485
    {
        GPIO_WriteIO(1, GPIO_RS485_TX_RX_EN);
        delay_1ms(2);
        U_PutUARTBytes(uart_port1, data, len);

        delay_1ms(len + 10);
        GPIO_WriteIO(0, GPIO_RS485_TX_RX_EN);
    }
    else
    {
        U_PutUARTBytes(uart_port1, data, len);
    }
}

#endif /* __CUST_UART1_MUX__ */
