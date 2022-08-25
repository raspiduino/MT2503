/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   dcl_common_config.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   configuration file of DCL (Driver Common Layer).
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef __DCL_COMMON_CONFIG_H__
#define __DCL_COMMON_CONFIG_H__

/////////////////////////////////////////////////////////////////
//This file used to add device driver to dcl_common
//Don't include in any other header file
/////////////////////////////////////////////////////////////////

extern DEV_Operations i2c_dev_operations;
extern DEV_Operations uart_dev_operations;
extern DEV_Operations spislv_dev_operations;
extern DEV_Operations gpio_dev_operations;
extern DEV_Operations spi_dev_operations;
extern DEV_Operations eint_dev_operations;
extern DEV_Operations dummy_device;
extern DEV_Operations adc_operations;
extern DEV_Operations pmu_dev_operations;
extern DEV_Operations pwm_dev_operations;


extern DEV_Utility uart_dev_query;
extern DEV_Utility spislv_dev_query;

extern DEV_Utility eint_dev_query;
extern DEV_Utility adc_dev_query;

extern DCL_EVENT_MSG_MAP uart_event_msg_map;
extern DCL_EVENT_MSG_MAP spislv_event_msg_map;
extern DCL_EVENT_MSG_MAP eint_event_msg_map;
extern DCL_EVENT_MSG_MAP adc_event_msg_map;
/********************************************************************
*This array is used to save the device driver interface. 
*For each driver which want to install to this array:
*1. first element is 0 when install.
*2. second element is the start number of your device number group(DCL_DEV_T in dcl.h)
*3. third element is the end number of your device number group(DCL_DEV_T in dcl.h). 
*   The end number must be less than the start number add 0x100.
*4. Fourth element is the address of your driver. This can't be NULL.
*5. Five element is the Ultility instance address, which can be NULL if the driver will not use it.
*6. The last element is the map of  event id to message id. This can be NULL if the driver will not use it.
*7. ATTENTION: The device number MUST BE grow from small to big. eg. If the driver's device group number is 0xA00,
*   and the Devices[] has group 0x800~0x900 and 0xC00~0xD00, the new driver group must insert to the middle of these two drivers.
*********************************************************************/
DCL_DEVICE_T Devices[]={	
{0,0,0x100,&uart_dev_operations,&uart_dev_query,&uart_event_msg_map},
{0,0x100,0x200,&i2c_dev_operations,NULL,NULL},
{0,0x200,0x300,&spi_dev_operations,NULL,NULL},
{0,0x300,0x400,&adc_operations,&adc_dev_query,&adc_event_msg_map},
{0,0x400,0x500,&gpio_dev_operations,NULL,NULL},
{0,0x500,0x600,&pwm_dev_operations,NULL,NULL},
{0,0xb00,0xC00,&pmu_dev_operations,NULL,NULL},
{0,0x1C00,0x1D00,&eint_dev_operations,&eint_dev_query,&eint_event_msg_map},
{0,0x1D00,0x1E00,&spislv_dev_operations,&spislv_dev_query,&spislv_event_msg_map}
};


#endif 
