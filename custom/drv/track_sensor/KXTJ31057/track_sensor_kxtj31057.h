/******************************************************************************
 * track_sensor_kxtj31057.h - 
 * 
 * Copyright .
 * 
 * DESCRIPTION: - 
 *        KXTJ3-1057 gSensor驱动 
 * 
 * modification history
 * --------------------
 * v1.0   2016-12-09,  chengjun create this file
 * 
 ******************************************************************************/

#if defined (__KIONIX_KXTJ31057__)

#ifndef _TRACK_SENSOR_KXTJ31057_H
#define _TRACK_SENSOR_KXTJ31057_H

#include "kal_release.h"
#include "drv_features.h"

typedef void (*FuncPtr) (void);

 
#define KXTJ31057_I2C_SLAVE_ADDR  0x1C
#define KXTJ31057_ACC_X_LSB__REG  0x06

//参考硬件接口图
typedef struct
{
       short x, 
         y, 
         z;
}KXT_1580acc_t;

static void track_sensor_kxtj31057_interrput_configuration(void);
static void track_sensor_kxtj31057_eint_hisr(void);
static void track_sensor_kxtj31057_reset(void);

void track_sensor_kxtj31057_on(kal_uint8 threshold , FuncPtr callback);
void track_sensor_kxtj31057_off(void);
kal_bool track_sensor_kxtj31057_type_check(void);

#endif  /* _TRACK_SENSOR_KXTJ31057_H */

#endif /* __KIONIX_KXTJ31057__ */
