/******************************************************************************#ifndef  EXT_CHEK_FULLCHARGE_GPIO
#define EXT_CHEK_FULLCHARGE_GPIO GPIO_EINT_NO_USE
#endif
 * track_interrupt.h -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        中断口/GPIO  配置
 *
 * modification history
 * --------------------
 * v1.0   2012-07-26,  chengjun create this file
 *
 ******************************************************************************/

#ifndef _TRACK_DRV_EINT_GPIO_H
#define _TRACK_DRV_EINT_GPIO_H

/****************************************************************************
* Include Files                   		包含头文件
*****************************************************************************/
#include "Eint.h"
#include "intrCtrl.h"
#include "kal_public_defs.h"
#include "track_os_data_types.h"
#include "track_project_hal_define.h"

/****************************************************************************
* Global Variable - Extern          引用全局变量
*****************************************************************************/


/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/

/*默认为电平触发模式*/
/*警告: 修改为EDGE_SENSITIVE 模式，请仔细查看代码，需要修改配置*/
#define EINT_SENSITIVE_MODE  LEVEL_SENSITIVE

/*默认软件防抖200ms  */
//unit 10ms
#define EINT_SW_DEBOUNCE_TIME  20          
#define EINT_SW_DEBOUNCE_20MS  2

/*-----  GPIO 配置end----*/

#ifndef  EINT_A_NO
#define EINT_A_NO GPIO_EINT_NO_USE
#endif

#ifndef  EINT_B_NO
#define EINT_B_NO GPIO_EINT_NO_USE
#endif

#ifndef  EINT_C_NO
#define EINT_C_NO GPIO_EINT_NO_USE
#endif

#ifndef  EINT_D_NO
#define EINT_D_NO GPIO_EINT_NO_USE
#endif

#ifndef  EINT_E_NO
#define EINT_E_NO GPIO_EINT_NO_USE
#endif

#ifndef  CUT_OIL_ELE_GPIO
#define CUT_OIL_ELE_GPIO GPIO_EINT_NO_USE
#endif

#ifndef  CUST_OUT1_GPIO
#define CUST_OUT1_GPIO GPIO_EINT_NO_USE
#endif

#ifndef  CTRL_5V_OUT_GPIO
#define CTRL_5V_OUT_GPIO GPIO_EINT_NO_USE
#endif

#ifndef  EXT_POWER_GPIO
#define EXT_POWER_GPIO GPIO_EINT_NO_USE
#endif

#if defined(__NT55__)
#ifndef OBD_POWER_GPIO
#define OBD_POWER_GPIO 25
#endif
#endif

#ifndef  BUZZER_GPIO
#define BUZZER_GPIO GPIO_EINT_NO_USE
#endif

/*****************************************************************************
* Typedef  Enum
*****************************************************************************/


/*****************************************************************************
 *  Struct					数据结构定义
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    U8 eint;
    U8 level;
} eint_status_struct;

/*****************************************************************************
* Local variable				局部变量
*****************************************************************************/


/*****************************************************************************
* Golbal variable				全局变量
*****************************************************************************/




/*****************************************************************************
 *  Global Functions	- Extern		引用外部函数
 *****************************************************************************/


/*****************************************************************************
 *  Local Functions			本地函数
 *****************************************************************************/
extern void track_eint_B_registration(void);


/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/
extern void track_drv_eint_init_registration(void);
extern kal_int8 track_drv_gpio_set(kal_int8 state, kal_int8 port);

extern void track_drv_set_vcama(kal_bool ON,/* kal_uint32 ldo,*/ kal_uint32 ldo_volt);

#endif  /* _TRACK_DRV_EINT_GPIO_H */

