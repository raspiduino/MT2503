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
#define ACC_EINT_NO             12
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
#define EXT_CHARGEIN_EINT_NO 15

#define EXT_HALL_EINT_NO 2
#define LOCK_CHEKC_EINT1 18
#define LOCK_CHEKC_EINT2 17


/*这四个是必须项*/
#define EINT_E_NO LOCK_CHEKC_EINT2

#define EINT_A_NO  ACC_EINT_NO
#define EINT_B_NO  EXT_HALL_EINT_NO
#define EINT_C_NO  EXT_CHARGEIN_EINT_NO
#define EINT_D_NO  LOCK_CHEKC_EINT1
/*3、中断对应的IO 口*/
#define EINT_A_GPIO 14
#define EINT_B_GPIO 2
#define EINT_C_GPIO 25
#define EINT_D_GPIO 35
#define EINT_E_GPIO 34

/*4、IO口的中断模式值有差异*/
//nc-0
#define EINT_A_GPIO_MODE    0
#define EINT_A_EINT_MODE    2
#define EINT_B_GPIO_MODE    0
#define EINT_B_EINT_MODE    1
#define EINT_C_GPIO_MODE    0
#define EINT_C_EINT_MODE    4
#define EINT_D_GPIO_MODE    0
#define EINT_D_EINT_MODE    2
#define EINT_E_GPIO_MODE    0
#define EINT_E_EINT_MODE    2

#define CUT_OIL_ELE_GPIO  GPIO_EINT_NO_USE

//外挂充电充满检测
#define EXT_CHEK_FULLCHARGE_GPIO  27

//外挂充电充满检测
#define EXT_CHEK_FULLCHARGE_GPIO  27

#define BUZZER_GPIO  36

#endif  /* _TRACK_PROJECT_HAL_DEFINE_H */

