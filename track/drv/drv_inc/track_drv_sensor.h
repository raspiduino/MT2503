/******************************************************************************
 * track_drv_sensor.h -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        Sensor驱动
 *
 * modification history
 * --------------------
 * v1.0   2012-12-01,  chengjun create this file
 *
 ******************************************************************************/
#ifndef _TRACK_DRV_SENSOR_H
#define _TRACK_DRV_SENSOR_H

#if defined (__TRACK_SENSOR__)

/****************************************************************************
* Include Files                   		包含头文件
*****************************************************************************/
#include "track_os_data_types.h"
#include "kal_general_types.h"

#include "track_sensor_bma250.h"
#include "track_sensor_kxtj31057.h"
#include "track_sensor_sc7a20.h"
#include "track_sensor_da213.h"
#include "nvram_data_items.h"
#include "nvram_editor_data_item.h"

/****************************************************************************
* Global Variable - Extern          引用全局变量
*****************************************************************************/


/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/
#if defined(__ET310__)||defined(__NT55__)||defined(__NT13V__)||defined(__NT17__) || defined (__JM10__)
#define MOTION_SENSOR_EINT_NO 2
#elif defined(__EL100__)||defined(__QB200__)||defined (__NF2319__)||defined (__NF2318__)
#define MOTION_SENSOR_EINT_NO 23
#else
#error "please define project_null"
#endif

#define SENSOR_BMA250_SW_DEBOUNCE_TIME 80    //unit  10ms  Bma250/Bma250E 方式特殊
#define SENSOR_SW_DEBOUNCE_TIME        80         //unit  10ms 


/*****************************************************************************
* Typedef  Enum
*****************************************************************************/
typedef enum
{
    SENSOR_LEVEL_MIN,
    SENSOR_LEVEL_1,      /*最灵敏*/
    SENSOR_LEVEL_2,
    SENSOR_LEVEL_3,
    SENSOR_LEVEL_4,
    SENSOR_LEVEL_5,            /*最不灵敏*/
    SENSOR_LEVEL_MAX
} sensor_threshold_level;


#define     SENSOR_LEVEL_DEFAULT        SENSOR_LEVEL_4

typedef enum
{
    SENSOR_INIT_ERROR=-1,        //未能识别Sensor 类型
    SENSOR_NOT_READY,           //还未检测识别Sensor 类型,该项必须为0 
    SENSOR_BMA250,
    SENSOR_BMA250E,
    SENSOR_BMA253,
    SENSOR_KXTJ31057,
    SENSOR_SC7A20,
    SENSOR_DA213,
#if 0
    SENSOR_MC3410,
    SENSOR_AFA750,
    SENSOR_MMA8452Q,
#endif /* 0 */
    SENSOR_MECH,
    /*只允许在此处增加新sensor  型号     --    chengjun  2013-02-26*/

    /*----------------------------*/
    SENSOR_TYPE_MAX,
} sensor_type_enum;


/*****************************************************************************
 *  Struct					数据结构定义
 *****************************************************************************/
typedef struct
{
    sensor_type_enum sensor_type;
    kal_uint8 sensor_level;
    kal_uint8 sensor_threshold;
    FuncPtr sensor_callback;
    void (*sensor_on)(kal_uint8 level , FuncPtr callback);
    FuncPtr sensor_off;
} track_sensor_config_data_struct;

/*****************************************************************************
* Local variable				局部变量
*****************************************************************************/


/*****************************************************************************
* Golbal variable				全局变量
*****************************************************************************/
extern track_sensor_config_data_struct  track_sensor_config_data;



/*****************************************************************************
 *  Global Functions	- Extern		引用外部函数
 *****************************************************************************/


/*****************************************************************************
 *  Local Functions			本地函数
 *****************************************************************************/

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/
void track_drv_sensor_type_auto_matching(void);
kal_uint8 track_drv_get_sensor_level(void);
sensor_type_enum track_drv_get_sensor_type(void);
void track_drv_sensor_callback_handle(void*msg);
kal_int8 track_drv_sensor_on(kal_uint8 level , FuncPtr callback);
kal_int8 track_drv_sensor_off(void);


#endif /* __TRACK_SENSOR__ */

#endif  /* _TRACK_DRV_SENSOR_H */
