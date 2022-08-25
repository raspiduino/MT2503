/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    motion_sensor_custom.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module is for motion sensor driver.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MOTION_SENSOR_CUSTOM_H
#define _MOTION_SENSOR_CUSTOM_H

/*KXP84 command begin*/
#define  MOTION_SENSOR_XOUT_H    0x00
#define  MOTION_SENSOR_XOUT_L    0x01
#define  MOTION_SENSOR_YOUT_H    0x02
#define  MOTION_SENSOR_YOUT_L    0x03
#define  MOTION_SENSOR_ZOUT_H    0x04
#define  MOTION_SENSOR_ZOUT_L    0x05
#define  MOTION_SENSOR_FF_INT    0x06
#define  MOTION_SENSOR_FF_DELAY  0x07
#define  MOTION_SENSOR_MOT_INT   0x08
#define  MOTION_SENSOR_MOT_DELAY 0x09
#define  MOTION_SENSOR_CTRL_REGC 0x0a
#define  MOTION_SENSOR_CTRL_REGB 0x0b
#define  MOTION_SENSOR_CTRL_REGA 0x0c 

#define  MOTION_SENSOR_READ_CMD  0x80
#define  MOTION_SENSOR_WRITE_CMD 0x00

#define MOTION_SENSOR_ADDRESS    0x32
#define MOTION_SENSOR_READ       0x1
#define MOTION_SENSOR_WRITE      0x0

/*interrupt configuration*/
#define MOTION_SENSOR_INT_SUPPORT   KAL_TRUE
#define MOTION_SENSOR_INT           4
#define MOTION_SENSOR_INT_LEVEL     LEVEL_HIGH
#define MOTION_SENSOR_LOW_G_MASK    0x1
#define MOTION_SENSOR_HIGH_G_MASK   0x2

/*acceleration*/
#define ACC_0G_X      (2048)
#define ACC_1G_X      (2048+800)
#define ACC_MINUS1G_X (2048-800)
#define ACC_0G_Y      (2048)    
#define ACC_1G_Y      (2048+800)
#define ACC_MINUS1G_Y (2048-800)
#define ACC_0G_Z      (2048)    
#define ACC_1G_Z      (2048+800)
#define ACC_MINUS1G_Z (2048-800)

/*extern function*/
extern void acc_sensor_configure_high_g(kal_uint32 debounce, kal_uint32 threshold);
extern void acc_sensor_configure_low_g(kal_uint32 debounce, kal_uint32 threshold);
extern void acc_sensor_clear_int_status(void);
extern void acc_sensor_read_int_status(kal_bool *low_g, kal_bool *high_g);
extern void acc_sensor_pwr_up(void);
extern void acc_sensor_pwr_down(void);
extern void acc_sensor_get_5bytes(kal_uint16 *x_adc, kal_uint16 *y_adc, kal_uint16 *z_adc);
extern void acc_sensor_init(void);
extern void acc_test_cb(void *parameter, Motion_Sensor_BuffState_enum state);
extern MotionSensor_customize_function_struct *ms_GetFunc(void);
extern MotionSensor_custom_data_struct *ms_get_data(void);
extern kal_bool KXP84_query_gesture(kal_uint16 ms_gest_type);
extern kal_bool KXP84_get_sensor_params(kal_uint16 ms_params_type,MotionSensorQueryStruct * ms_params);

#endif
