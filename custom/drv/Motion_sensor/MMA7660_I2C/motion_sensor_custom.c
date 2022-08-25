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
 *    motion_sensor_custom.c
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
#if defined(MOTION_SENSOR_SUPPORT)
#include "kal_release.h"
#include "custom_config.h"
#include "gpio_sw.h"
#include "drv_comm.h"
#include "eint.h"
#include "motion_sensor.h"
#include "motion_sensor_custom.h"
#include "motion_sensor_I2C.h"
#include "motion_sensor_hw_define.h"
#include "kal_trace.h"
#include "stack_config.h"

kal_uint32 MS_DELAY_TIME	= 350; 

kal_uint16 motion_data; 
#define MS_DELAY_200NS 10

char MS_sensor_buffer[10];

//#define MS_DBG

#ifdef MS_DBG
kal_char ms_buff[200];
#endif

kal_bool MS_I2C_write_byte(kal_uint8 ucBufferIndex, kal_uint8 pucData)
{
	return ms_i2c_send(MS_SLAVE_ADDR,ucBufferIndex,&pucData,1);
}


#define MS_I2C_read(a,b,c) ms_i2c_receive(MS_SLAVE_ADDR,a,b,c)

void mma7660_read_xyz(char *x,char *y,char *z)
{	 
     MS_I2C_read(MS_REG_XOUT,MS_sensor_buffer,3);
	 *x=MS_sensor_buffer[0];
     *y=MS_sensor_buffer[1];
     *z=MS_sensor_buffer[2];
}
void mma7660_sensor_get_data(kal_uint16 *x_adc, kal_uint16 *y_adc, kal_uint16 *z_adc)
{
     char x_temp,y_temp,z_temp;
	 kal_int16 x,y,z;
	 mma7660_read_xyz(&x_temp,&y_temp,&z_temp);
	 x_temp&=0x3F;                               //remove alter
	 y_temp&=0x3F;
	 z_temp&=0x3F;
	 /*最高位取反，将值域放到0到63*/
	 if(x_temp<32)      //正
	     x=x_temp+31;
	 else
	 {
		 x=x_temp-32;
	 }
	 
	 if(y_temp<32)
	     y=y_temp+31;
	 else
	 {
		 y=y_temp-32;
	 }
	 
	 if(z_temp<32)
	     z=z_temp+31;
	 else
	 {
		 z=z_temp-32;
	 }

	 *x_adc=x*2;
	 *y_adc=y*2;
	 *z_adc=z*2;
	
	x=*x_adc;
	y=*y_adc;
	z=*z_adc;

#if defined(MOTION_SENSOR_BACK_0)	
	*x_adc= x;
	*y_adc= y;
	*z_adc= z;
#elif defined(MOTION_SENSOR_BACK_90)
	*x_adc= y;
	*y_adc= 2*ACC_0G_X-x;
	*z_adc= z;
#elif defined(MOTION_SENSOR_BACK_180)
	*x_adc= 2*ACC_0G_X-x;
	*y_adc= 2*ACC_0G_Y-y;
	*z_adc= z;
#elif defined(MOTION_SENSOR_BACK_270)
	*x_adc= 2*ACC_0G_Y-y;
	*y_adc= x;
	*z_adc= z;
#elif defined(MOTION_SENSOR_FRONT_0)
	*x_adc= 2*ACC_0G_X-x;
	*y_adc= y;
	*z_adc= 2*ACC_0G_Z-z;
#elif defined(MOTION_SENSOR_FRONT_90)
	*x_adc= 2*ACC_0G_Y-y;
	*y_adc= 2*ACC_0G_X-x;
	*z_adc= 2*ACC_0G_Z-z;
#elif defined(MOTION_SENSOR_FRONT_180)
	*x_adc= x;
	*y_adc= 2*ACC_0G_Y-y;
	*z_adc= 2*ACC_0G_Z-z;
#elif defined(MOTION_SENSOR_FRONT_270)
	*x_adc= y;
	*y_adc= x;
	*z_adc= 2*ACC_0G_Z-z;
#endif

#ifdef MS_DBG
	 kal_prompt_trace(MOD_ENG,"Motion Sensor Readed and value is x:%d  ,y:%d   ,z:%d  ",*x_adc,*y_adc,*z_adc);
#endif
}


/*return sensor support gesture*/
kal_bool mma7660_query_gesture(kal_uint16 ms_gest_type)
{
	switch(ms_gest_type)
		{
			//only 3-axis sensor can support Flip gesture, 2-axis not support, return false.
			case MS_FLIP:
				return KAL_TRUE;
				
			default:
				return KAL_FALSE;
		}
}

kal_bool mma7660_get_sensor_params(kal_uint16 ms_params_type, MotionSensorQueryStruct *ms_params)
{
	kal_uint32 tilt_status;
	
	switch(ms_params_type)
		{
			case MS_ACC_DATA_RESOLUTION:				
				ms_params->curr_val = (MMA7660_RANGE * 1000)/(1<<MMA7660_RESOLUTION);
				kal_prompt_trace(MOD_ENG,"MS_ACC_DATA_RESOLUTION: curr_val = %x, max_val = %x, min_val = %x",ms_params->curr_val, ms_params->max_val, ms_params->min_val);
				return KAL_TRUE;
				
			default:
				return KAL_FALSE;
		}
}

void mma7660_read_test_REG()
{	 
     MS_I2C_read(MS_REG_XOUT,MS_sensor_buffer,1);
	 MS_I2C_read(MS_REG_YOUT,MS_sensor_buffer,1);
	 MS_I2C_read(MS_REG_ZOUT,MS_sensor_buffer,1);
	 MS_I2C_read(MS_REG_SRST,MS_sensor_buffer,1);
	 MS_I2C_read(MS_REG_MODE,MS_sensor_buffer,1);
}
void mma7660_sensor_test()
{
     char x_temp,y_temp,z_temp;
#ifdef MS_DBG
     sprintf(ms_buff,"mma7660_sensor_test start");
	kal_bootup_print(ms_buff);
#endif
	 MS_I2C_write_byte(MS_REG_MODE,0x00);   //standby mode
	 MS_I2C_write_byte(MS_REG_MODE,0x04);   //test  mode
	 mma7660_read_test_REG();
#ifdef MS_DBG
	 sprintf(ms_buff,"Motion Sensor change mode to test mode");
	kal_bootup_print(ms_buff);
#endif
	 MS_I2C_write_byte(MS_REG_XOUT,0x55);
	 MS_I2C_write_byte(MS_REG_YOUT,0x55);
	 MS_I2C_write_byte(MS_REG_ZOUT,0x55);
#ifdef MS_DBG
	 sprintf(ms_buff,"Motion Sensor write data as 0x55 OK!! now read it out");
	kal_bootup_print(ms_buff);
#endif
	 mma7660_read_xyz(&x_temp,&y_temp,&z_temp);
#ifdef MS_DBG
	sprintf(ms_buff,"Motion Sensor Readed and value is x:%d  ,y:%d   ,z:%d  ",x_temp,y_temp,z_temp);
	kal_bootup_print(ms_buff);
	sprintf(ms_buff,"Motion Sensor test mode write 0xAA");
	kal_bootup_print(ms_buff);
#endif
	 MS_I2C_write_byte(MS_REG_XOUT,0xAA);
	 MS_I2C_write_byte(MS_REG_YOUT,0xAA);
	 MS_I2C_write_byte(MS_REG_ZOUT,0xAA);
#ifdef MS_DBG
	 sprintf(ms_buff,"Motion Sensor write data as 0xAA OK!! now read it out");
	kal_bootup_print(ms_buff);
#endif
	 mma7660_read_xyz(&x_temp,&y_temp,&z_temp);
#ifdef MS_DBG
	 sprintf(ms_buff,"Motion Sensor Readed and value is x:%d  ,y:%d   ,z:%d  ",x_temp,y_temp,z_temp);
	kal_bootup_print(ms_buff);
	
	sprintf(ms_buff,"Motion Sensor test over and change to active mode");
	kal_bootup_print(ms_buff);
#endif
	MS_I2C_write_byte(MS_REG_MODE,0x00);  //standby mode
	 MS_I2C_write_byte(MS_REG_MODE,0x01);  // active mode
	 mma7660_read_test_REG();
}

void mma7660_sensor_set_reg(void)
{
#ifdef MS_DBG
	sprintf(ms_buff,"mma7660_sensor_set_reg start");
	kal_bootup_print(ms_buff);
#endif

     MS_I2C_write_byte(MS_REG_MODE,MS_STANDBY_MODE);
	 MS_I2C_write_byte(MS_REG_SPCNT,MS_AS_COUNT);
	 MS_I2C_write_byte(MS_REG_INTSU,0x00);
	 MS_I2C_write_byte(MS_REG_SRST,MS_AWSRS|MS_AMSRS);               //没有设这个
	 MS_I2C_write_byte(MS_REG_SR,MS_Auto_Wake_Sample|MS_Auto_Sleep_Sample);
	 MS_I2C_write_byte(MS_REG_MODE,MS_RUNNING_MODE);
	 
#ifdef MS_DBG
	 sprintf(ms_buff,"mma7660_sensor_set_reg end");
	kal_bootup_print(ms_buff);
#endif
}

void mma7660_sensor_pwr_up(void)
{
#ifdef MS_DBG
	sprintf(ms_buff,"mma7660_sensor_pwr_up start");
	kal_bootup_print(ms_buff);
#endif

#ifndef MS_POWER_BY_VBOOST
     MS_I2C_write_byte(MS_REG_MODE,MS_RUNNING_MODE);
#else
     GPIO_WriteIO(1,Motion_Sensor_Power_Pin);
#endif
     //mma_sensor_set_reg();
     //ms_i2c_power_on(KAL_TRUE, MS_I2C_LDO, MS_I2C_LDO_VOLTAGE);

#ifdef MS_DBG
	 sprintf(ms_buff,"mma7660_sensor_pwr_up end");
	 kal_bootup_print(ms_buff);
#endif
}
void mma7660_sensor_pwr_down(void)
{
#ifdef MS_DBG
	sprintf(ms_buff,"mma7660_sensor_pwr_down start");
	kal_bootup_print(ms_buff);
#endif

#ifndef MS_POWER_BY_VBOOST
     MS_I2C_write_byte(MS_REG_MODE,MS_STANDBY_MODE);
#else
     GPIO_WriteIO(0,Motion_Sensor_Power_Pin);
#endif

#ifdef MS_DBG
	sprintf(ms_buff,"mma7660_sensor_pwr_down end");
	kal_bootup_print(ms_buff);
#endif
}
void mma7660_sensor_init(void)
{
#ifdef MS_DBG
	sprintf(ms_buff,"mma7660_sensor_init start");
	kal_bootup_print(ms_buff);
#endif

	 ms_i2c_configure(MS_SLAVE_ADDR, MS_DELAY_TIME); //
	 
	 mma7660_sensor_pwr_up();
	 
	 mma7660_sensor_set_reg();
	 mma7660_sensor_pwr_down();//power down after init finish
	 
#ifdef MS_DBG
	 mma7660_sensor_test();   //for testing register
	 sprintf(ms_buff,"mma7660_sensor_init start");
	 kal_bootup_print(ms_buff);
#endif
}

/*customizaton function pointer*/
MotionSensor_customize_function_struct ms_custom_func=
{
     ms_get_data,
     mma7660_sensor_get_data,
     mma7660_sensor_init,
     mma7660_sensor_pwr_up,
     mma7660_sensor_pwr_down,
     NULL,//mma_sensor_read_int_status,
	 NULL,//mma_sensor_clear_int_status,
	 NULL,//mma_sensor_configure_low_g,
	 NULL,//mma_sensor_configure_high_g   
	 mma7660_query_gesture,
     mma7660_get_sensor_params,
     NULL
};   
/*customizaton data*/
MotionSensor_custom_data_struct  ms_custom_data_def = 
{          
   /*X axis*/
   ACC_0G_X,   
   ACC_1G_X,
   ACC_MINUS1G_X,     
   /*Y axis*/
   ACC_0G_Y,   
   ACC_1G_Y,
   ACC_MINUS1G_Y,     
   /*Z axis*/
   ACC_0G_Z,   
   ACC_1G_Z,
   ACC_MINUS1G_Z,
   /*support interrupt or not*/
   KAL_FALSE,
   0,
   0/*channel*/    
};
MotionSensor_custom_data_struct * (ms_get_data)(void)
{
   return (&ms_custom_data_def);
} 

MotionSensor_customize_function_struct * (ms_GetFunc)(void)
{
     return &(ms_custom_func);
}
#endif
