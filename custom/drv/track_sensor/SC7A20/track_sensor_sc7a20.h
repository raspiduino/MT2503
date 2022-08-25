/******************************************************************************
 * track_sensor_sc7a20.h - 
 * 
 * Copyright .
 * 
 * DESCRIPTION: - 
 *        SC7A20 gSensorÇý¶¯ 
 * 
 * modification history
 * --------------------
 * v1.0   2017-04-11,  chengjun create this file
 * 
 ******************************************************************************/

#if defined (__SILAN_SC7A20__)

#ifndef _TRACK_SENSOR_SC7A20_H
#define _TRACK_SENSOR_SC7A20_H

#include "kal_release.h"
#include "drv_features.h"

typedef void (*FuncPtr) (void);

 
#define SC7A20_I2C_SLAVE_ADDR  0x30


static void track_sensor_sc7a20_interrput_configuration(void);
static void track_sensor_sc7a20_eint_hisr(void);
static void track_sensor_sc7a20_reset(void);

void track_sensor_sc7a20_on(kal_uint8 threshold , FuncPtr callback);
void track_sensor_sc7a20_off(void);
kal_bool track_sensor_sc7a20_type_check(void);

#endif  /* _TRACK_SENSOR_SC7A20_H */

#endif /* __SILAN_SC7A20__ */
