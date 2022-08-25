/******************************************************************************
 * track_project_main.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        各项目不同的入口处理 ,每个项目都存在这样的同名文件，不得重命名
 *
 * modification history
 * --------------------
 * v1.0   2017-06-30,  chengjun create this file
 *
 ******************************************************************************/

/****************************************************************************
* Include Files                         包含头文件
*****************************************************************************/
#include "track_os_data_types.h"
#include "kal_public_defs.h"
#include "track_os_log.h"
#include "track_drv_gps_decode.h"
#include "track_drv_uart.h"
#include "Track_cust.h"

/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/




/*****************************************************************************
* Typedef  Enum         枚举
*****************************************************************************/


/*****************************************************************************
 *  Struct                              数据结构定义
 *****************************************************************************/



/*****************************************************************************
 *  Global Functions			全局变量
 *****************************************************************************/
extern nvram_parameter_struct              G_parameter ;

/*****************************************************************************
 *  Local Functions			本地函数
 *****************************************************************************/


/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/
#if defined(__OBD__)
extern void track_cust_obd_data(kal_uint8 *data, int len);
#endif
#if defined(__BMS_PHYLION__)
extern void track_cust_bms_data_receive(kal_uint8 *data,kal_uint16 len);
#endif
extern void track_cust_atech_data_receive(kal_uint8 *srcdata, kal_uint16 len);

/******************************************************************************
 *  Function    -  track_project_main_init
 *
 *  Purpose     -  开机后执行一次，各项目按需求执行初始化事件
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-06-30,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_project_main_init(void)
{
    track_cust_LBS_upload();

}



/******************************************************************************
 *  Function    -  track_project_gpio_init
 *
 *  Purpose     -  GPIO端口初始化，无特殊操作则为空函数
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-12,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_project_gpio_init(void)
{
    GPIO_ModeSetup(0, 0);
    GPIO_InitIO(1, 0);
    GPIO_WriteIO(0, 0);

    GPIO_ModeSetup(1, 0);
    GPIO_InitIO(1, 1);
    GPIO_WriteIO(0, 1);
}

kal_uint8 track_project_uart_init(void)
{
    return YES_GO_ON;
}

/******************************************************************************
 *  Function    -  track_project_keypad_init
 * 
 *  Purpose     -  仅针对矩阵键盘注册
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-12,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_project_keypad_init()
{

}

/******************************************************************************
 *  Function    -  track_project_gps_work_and_fix_nitify
 *
 *  Purpose     -  GPS从不定位到定位消息
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-12,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_project_gps_work_and_fix_nitify(track_gps_data_struct * gps_data)
{


}

/******************************************************************************
 *  Function    -  track_project_gps_work_no_fix_nitify
 *
 *  Purpose     -  GPS从定位到不定位消息
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-12,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_project_gps_work_no_fix_nitify(void)
{


}

/******************************************************************************
 *  Function    -  track_project_gsensor_shocked_event
 *
 *  Purpose     -  发生震动事件，是否继续原来的流程？
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-12,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
kal_uint8 track_project_gsensor_shocked_event(void)
{
    return YES_GO_ON;
}


/******************************************************************************
 *  Function    -  track_project_enters_quiescent_state_notify
 *
 *  Purpose     -  一段时间未检测到震动，进入静止状态
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-12,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_project_enters_quiescent_state_notify(void)
{

}

/******************************************************************************
 *  Function    -  track_project_status_eint_notify
 * 
 *  Purpose     -  中断事件通知
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-13,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
kal_uint8 track_project_status_eint_notify(U8 eint, U8 level)
{
    return YES_GO_ON;
}

/******************************************************************************
 *  Function    -  track_project_uart_receice_data_notify
 * 
 *  Purpose     -  串口收到数据通知
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-13,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
kal_uint8 track_project_uart_receice_data_notify(UART_PORT port,kal_uint8* data, kal_uint16 len)
{
	LOGD(L_UART, L_V5, "port:%d,len:%d", port,len);
	if(port == uart_port3)
	{
#if defined(__BMS_PHYLION__)
	track_cust_bms_data_receive(data,len);
	return 1;
#endif
#if defined(__OBD__)
		if(G_parameter.obd.sw == 1)
		{
#if defined(__ATECH__)
		//track_cust_atech_data_analyze(data,len);
		track_cust_atech_data_receive(data,len);
#else
		track_cust_obd_data(data,len);
#endif
		}
#endif
	}
    return YES_GO_ON;
}


