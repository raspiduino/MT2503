/******************************************************************************
 * track_project_hal_define.h - 
 * 
 * Copyright .
 * 
 * DESCRIPTION: - 
 *        各项目不同的硬件配置宏定义文件,每个项目都存在这样的同名文件，不得重命名 
 * 
 * modification history
 * --------------------
 * v1.0   2017-07-11,  chengjun create this file
 * 
 ******************************************************************************/
#ifndef _TRACK_PROJECT_HAL_DEFINE_H
#define _TRACK_PROJECT_HAL_DEFINE_H


/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/
/*不使用的中断或GPIO口，定义为0xFF，软件会自动屏蔽对它的操作      --    chengjun  2017-07-10*/
#define GPIO_EINT_NO_USE    0xFF


//152看门狗
#define WATCH_DOG_GPIO  28

//中断为GPIO_EINT_NO_USE的可以省略
//acc
#define ACC_EINT_NO             16
//SOS按键
#define EXTRA_SOS_EINT_NO       GPIO_EINT_NO_USE
//尾线检测中断
#define EXTRA_IN_1_EINT_NO        GPIO_EINT_NO_USE
#define EXTRA_IN_2_EINT_NO        GPIO_EINT_NO_USE
//单片机唤醒
#define EXTRA_WAKEUP_EINT_NO    GPIO_EINT_NO_USE
//设备普通按键
#define EXTRA_A_KEY_EINT_NO     GPIO_EINT_NO_USE
//耳机
#define AUX_EINT_NO             GPIO_EINT_NO_USE
//外挂充电charge in
#define EXT_CHARGEIN_EINT_NO GPIO_EINT_NO_USE

/*这四个是必须项*/
#define EINT_A_NO  ACC_EINT_NO
#define EINT_B_NO  GPIO_EINT_NO_USE
#define EINT_C_NO  GPIO_EINT_NO_USE
#define EINT_D_NO  GPIO_EINT_NO_USE

/*3、中断对应的IO 口*/
#define EINT_A_GPIO 30
#define EINT_B_GPIO GPIO_EINT_NO_USE
#define EINT_C_GPIO GPIO_EINT_NO_USE

/*4、IO口的中断模式值有差异*/
//nc-0
#define EINT_A_GPIO_MODE    0
#define EINT_A_EINT_MODE    4
#define EINT_B_GPIO_MODE    0
#define EINT_B_EINT_MODE    0
#define EINT_C_GPIO_MODE    0
#define EINT_C_EINT_MODE    0

#define CUT_OIL_ELE_GPIO  29

#endif  /* _TRACK_PROJECT_HAL_DEFINE_H */

