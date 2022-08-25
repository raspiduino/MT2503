/**************************************************************************************************/
/*  $Date: March-1-20111
 *   $Revision: 1.01$
 *
 */

/**************************************************************************************************
* Copyright (C) 2011 Bosch Sensortec GmbH
*
* BOSCH algorithm API
*
* Usage:		BOSCH portrait landscape and skake snap algorithm
*
* Author:       yongsheng.gao@bosch-sensortec.com
**************************************************************************************************/
/*  Disclaimer
*
* Common:
* Bosch Sensortec products are developed for the consumer goods industry. They may only be used
* within the parameters of the respective valid product data sheet.  Bosch Sensortec products are
* provided with the express understanding that there is no warranty of fitness for a particular purpose.
* They are not fit for use in life-sustaining, safety or security sensitive systems or any system or device
* that may lead to bodily harm or property damage if the system or device malfunctions. In addition,
* Bosch Sensortec products are not fit for use in products which interact with motor vehicle systems.
* The resale and/or use of products are at the purchaser’s own risk and his own responsibility. The
* examination of fitness for the intended use is the sole responsibility of the Purchaser.
*
* The purchaser shall indemnify Bosch Sensortec from all third party claims, including any claims for
* incidental, or consequential damages, arising from any product use not covered by the parameters of
* the respective valid product data sheet or not approved by Bosch Sensortec and reimburse Bosch
* Sensortec for all costs in connection with such claims.
*
* The purchaser must monitor the market for the purchased products, particularly with regard to
* product safety and inform Bosch Sensortec without delay of all security relevant incidents.
*
* Engineering Samples are marked with an asterisk (*) or (e). Samples may vary from the valid
* technical specifications of the product series. They are therefore not intended or fit for resale to third
* parties or for use in end products. Their sole purpose is internal client testing. The testing of an
* engineering sample may in no way replace the testing of a product series. Bosch Sensortec
* assumes no liability for the use of engineering samples. By accepting the engineering samples, the
* Purchaser agrees to indemnify Bosch Sensortec from all claims arising from the use of engineering
* samples.
*
* Special:
* This software module (hereinafter called "Software") and any information on application-sheets
* (hereinafter called "Information") is provided free of charge for the sole purpose to support your
* application work. The Software and Information is subject to the following terms and conditions:
*
* The Software is specifically designed for the exclusive use for Bosch Sensortec products by
* personnel who have special experience and training. Do not use this Software if you do not have the
* proper experience or training.
*
* This Software package is provided `` as is `` and without any expressed or implied warranties,
* including without limitation, the implied warranties of merchantability and fitness for a particular
* purpose.
*
* Bosch Sensortec and their representatives and agents deny any liability for the functional impairment
* of this Software in terms of fitness, performance and safety. Bosch Sensortec and their
* representatives and agents shall not be liable for any direct or indirect damages or injury, except as
* otherwise stipulated in mandatory applicable law.
*
* The Information provided is believed to be accurate and reliable. Bosch Sensortec assumes no
* responsibility for the consequences of use of such Information nor for any infringement of patents or
* other rights of third parties which may result from its use. No license is granted by implication or
* otherwise under any patent or patent rights of Bosch. Specifications mentioned in the Information are
* subject to change without notice.
*
* It is not allowed to deliver the source code of the Software to any third party without permission of
* Bosch Sensortec.
*/
/*************************************************************************************************/
#ifdef __BOSCH_BMA250__

#ifndef _TRACK_SENSOR_BMA250_H
#define _TRACK_SENSOR_BMA250_H

#include "kal_release.h"
#include "motion_sensor.h"

#include "stack_ltlcom.h"
#include "track_os_log.h"

extern const char gpio_acc_sensor_sck_pin ;
extern const char gpio_acc_sensor_sda_pin ;
#define ACC_SENSOR_SCK     gpio_acc_sensor_sck_pin
#define ACC_SENSOR_SDA     gpio_acc_sensor_sda_pin


#define BMA250_I2C_SLAVE_WRITE_ADDR 0x30
#define BMA250_I2C_SLAVE_READ_ADDR 0x31
#define ACT_HIGH                 1

typedef void (*FuncPtr)(void);

static void acc_sensor_pwr_up(void);
static void acc_sensor_pwr_down(void);
static void acc_sensor_init(void);
static void sensor_bma250_init_with_interrupt(void);
void acc_sensor_get_6bytes(kal_uint16 *accl_x,kal_uint16 *accl_y,kal_uint16 *accl_z);

extern char acc_sensor_write_bytes(kal_uint8 dev_addr, kal_uint8 reg_addr, kal_uint8* reg_data, kal_uint8 wr_len);
extern char acc_sensor_read_bytes(kal_uint8 dev_addr, kal_uint8 reg_addr, kal_uint8* reg_data, kal_uint8 r_len);


#if defined (__TRACK_SENSOR__)

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 x;
    kal_int16 y;
    kal_int16 z;
} Msg_sensor_xyz_struct;

static void track_sensor_bma250_interrput_configuration(void);
static void track_sensor_bma250_eint_hisr(void);
static void track_sensor_bma250_reset(void);

void track_sensor_bma250_on(kal_uint8 threshold , FuncPtr callback);
void track_sensor_bma250_off(void);
kal_int8 track_sensor_bma250_type_check(void);

#endif /* __TRACK_SENSOR__ */


#endif  /* _TRACK_SENSOR_BMA250_H */
#endif /* __BOSCH_BMA250__ */
