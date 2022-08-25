/******************************************************************************
 * track_sensor_da213.h - 
 * 
 * Copyright .
 * 
 * DESCRIPTION: - 
 *        DA213 gSensorÇý¶¯  
 * 
 * modification history
 * --------------------
 * v1.0   2017-05-16,  chengjun create this file
 * 
 ******************************************************************************/

#if defined (__MIRA_DA213__)

#ifndef _TRACK_SENSOR_DA213_H
#define _TRACK_SENSOR_DA213_H

#include "kal_release.h"
#include "drv_features.h"

typedef void (*FuncPtr) (void);

 
#define DA213_I2C_SLAVE_ADDR  0x4D


static void track_sensor_da213_interrput_configuration(void);
static void track_sensor_da213_eint_hisr(void);
static void track_sensor_da213_reset(void);

void track_sensor_da213_on(kal_uint8 threshold , FuncPtr callback);
void track_sensor_da213_off(void);
kal_bool track_sensor_da213_type_check(void);

#endif  /* _TRACK_SENSOR_DA213_H */

#endif /* __MIRA_DA213__ */
