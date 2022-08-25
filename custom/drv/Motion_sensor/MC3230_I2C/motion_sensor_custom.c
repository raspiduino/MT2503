
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

void mc3230_read_xyz(char *x,char *y,char *z)
{	 
     MS_I2C_read(MS_REG_XOUT,MS_sensor_buffer,3);
	   *x=MS_sensor_buffer[0];
     *y=MS_sensor_buffer[1];
     *z=MS_sensor_buffer[2];
}

/*It is for mCube time stamp*/
kal_uint32 mc3230_get_milli_time(void)
{
   kal_uint32 time;
   kal_get_time(&time);
   return kal_ticks_to_milli_secs(time);
}

void mc3230_sensor_get_data(kal_uint16 *x_adc, kal_uint16 *y_adc, kal_uint16 *z_adc)
{
     char x_temp,y_temp,z_temp;
	 kal_int16 x,y,z;
	 kal_uint32 time_ms;
	 
	 mc3230_read_xyz(&x_temp,&y_temp,&z_temp);	 
	 time_ms = mc3230_get_milli_time(); /*get time stamp*/
	 //kal_prompt_trace(MOD_ENG,"Motion Sensor Raw value is raw_x : %d  ,raw_y : %d   ,raw_z : %d ,time_stamp = %d ",(signed char)x_temp,(signed char)y_temp,(signed char)z_temp,time_ms);
 
	 x_temp&=0xFF;                              
	 y_temp&=0xFF;
	 z_temp&=0xFF;
	 
	// kal_prompt_trace(MOD_ENG,"Motion Sensor Raw value is raw_x1 : %d  ,raw_y1 : %d   ,raw_z1 : %d  ",x_temp,y_temp,z_temp);

	 if(x_temp<128)     
	     x=x_temp+127;
	 else
	 {
		 x=x_temp-128;
	 }
	 
	 if(y_temp<128)
	     y=y_temp+127;
	 else
	 {
		 y=y_temp-128;
	 }
	 
	 if(z_temp<128)
	     z=z_temp+127;
	 else
	 {
		 z=z_temp-128;
	 }
	 
#ifdef MS_DBG
	kal_prompt_trace(MOD_ENG,"Motion Sensor Raw value is raw_x2 : %d  ,raw_y2 : %d   ,raw_z2 : %d  ",x,y,z);
#endif

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

/* Get tilt status*/

void mc3230_sensor_get_status(kal_uint32 *status)
{
	kal_uint8 new_tilt_status;
	kal_uint8 bafr_status;
	kal_uint8 pola_status;
	kal_uint32 time_ms;
	
	MS_I2C_read(MS_REG_TILT,MS_sensor_buffer,1);
	*status = MS_sensor_buffer[0];
	new_tilt_status = *status & (TILT_STATUS_TAP_EVENT | TILT_STATUS_DROP_EVENT | TILT_STATUS_SHAKE_EVENT);
	bafr_status = *status & TILT_STATUS_BAFR_MASK;
	pola_status = *status & TILT_STATUS_POLA_MASK;
	
#if defined(MOTION_SENSOR_BACK_0) //MCUBE_PLACEMENT_TOP_LEFT_DOWN	

		switch (bafr_status)
		{
		case TILT_STATUS_BAFR_FRONT:
			new_tilt_status |= TILT_STATUS_BAFR_FRONT;
			break;

		case TILT_STATUS_BAFR_BACK:
			new_tilt_status |= TILT_STATUS_BAFR_BACK;
			break;
		}
		switch (pola_status)
		{
		case TILT_STATUS_POLA_LEFT:
			new_tilt_status |= TILT_STATUS_POLA_UP;
			break;

		case TILT_STATUS_POLA_RIGHT:
			new_tilt_status |= TILT_STATUS_POLA_DOWN;
			break;

		case TILT_STATUS_POLA_DOWN:
			new_tilt_status |= TILT_STATUS_POLA_LEFT;
			break;

		case TILT_STATUS_POLA_UP:
			new_tilt_status |= TILT_STATUS_POLA_RIGHT;
			break;
		}
		
#elif defined(MOTION_SENSOR_BACK_90) //MCUBE_PLACEMENT_TOP_LEFT_UP

		switch (bafr_status)
		{
		case TILT_STATUS_BAFR_FRONT:
			new_tilt_status |= TILT_STATUS_BAFR_FRONT;
			break;

		case TILT_STATUS_BAFR_BACK:
			new_tilt_status |= TILT_STATUS_BAFR_BACK;
			break;
		}
		switch (pola_status)
		{
		case TILT_STATUS_POLA_LEFT:
			new_tilt_status |= TILT_STATUS_POLA_LEFT;
			break;

		case TILT_STATUS_POLA_RIGHT:
			new_tilt_status |= TILT_STATUS_POLA_RIGHT;
			break;

		case TILT_STATUS_POLA_DOWN:
			new_tilt_status |= TILT_STATUS_POLA_DOWN;
			break;

		case TILT_STATUS_POLA_UP:
			new_tilt_status |= TILT_STATUS_POLA_UP;
			break;
		}
		
#elif defined(MOTION_SENSOR_BACK_180)  //MCUBE_PLACEMENT_TOP_RIGHT_UP
	
	switch (bafr_status)
		{
		case TILT_STATUS_BAFR_FRONT:
			new_tilt_status |= TILT_STATUS_BAFR_FRONT;
			break;

		case TILT_STATUS_BAFR_BACK:
			new_tilt_status |= TILT_STATUS_BAFR_BACK;
			break;
		}
		switch (pola_status)
		{
		case TILT_STATUS_POLA_LEFT:
			new_tilt_status |= TILT_STATUS_POLA_DOWN;
			break;

		case TILT_STATUS_POLA_RIGHT:
			new_tilt_status |= TILT_STATUS_POLA_UP;
			break;

		case TILT_STATUS_POLA_DOWN:
			new_tilt_status |= TILT_STATUS_POLA_RIGHT;
			break;

		case TILT_STATUS_POLA_UP:
			new_tilt_status |= TILT_STATUS_POLA_LEFT;
			break;
		}
		
#elif defined(MOTION_SENSOR_BACK_270) //MCUBE_PLACEMENT_TOP_RIGH_DOWN
	
	switch (bafr_status)
		{
		case TILT_STATUS_BAFR_FRONT:
			new_tilt_status |= TILT_STATUS_BAFR_FRONT;
			break;

		case TILT_STATUS_BAFR_BACK:
			new_tilt_status |= TILT_STATUS_BAFR_BACK;
			break;
		}
		switch (pola_status)
		{
		case TILT_STATUS_POLA_LEFT:
			new_tilt_status |= TILT_STATUS_POLA_RIGHT;
			break;

		case TILT_STATUS_POLA_RIGHT:
			new_tilt_status |= TILT_STATUS_POLA_LEFT;
			break;

		case TILT_STATUS_POLA_DOWN:
			new_tilt_status |= TILT_STATUS_POLA_UP;
			break;

		case TILT_STATUS_POLA_UP:
			new_tilt_status |= TILT_STATUS_POLA_DOWN;
			break;
		}
		
#elif defined(MOTION_SENSOR_FRONT_0) //MCUBE_PLACEMENT_BOTTOM_RIGHT_DOWN
	
	switch (bafr_status)
		{
		case TILT_STATUS_BAFR_FRONT:
			new_tilt_status |= TILT_STATUS_BAFR_BACK;
			break;

		case TILT_STATUS_BAFR_BACK:
			new_tilt_status |= TILT_STATUS_BAFR_FRONT;
			break;
		}
		switch (pola_status) {
		case TILT_STATUS_POLA_LEFT:
			new_tilt_status |= TILT_STATUS_POLA_UP;
			break;

		case TILT_STATUS_POLA_RIGHT:
			new_tilt_status |= TILT_STATUS_POLA_DOWN;
			break;

		case TILT_STATUS_POLA_DOWN:
			new_tilt_status |= TILT_STATUS_POLA_RIGHT;
			break;

		case TILT_STATUS_POLA_UP:
			new_tilt_status |= TILT_STATUS_POLA_LEFT;
			break;
		}
		
#elif defined(MOTION_SENSOR_FRONT_90)  //MCUBE_PLACEMENT_BOTTOM_RIGHT_UP
	
	switch (bafr_status)
		{
		case TILT_STATUS_BAFR_FRONT:
			new_tilt_status |= TILT_STATUS_BAFR_BACK;
			break;

		case TILT_STATUS_BAFR_BACK:
			new_tilt_status |= TILT_STATUS_BAFR_FRONT;
			break;
		}
		switch (pola_status)
		{
		case TILT_STATUS_POLA_LEFT:
			new_tilt_status |= TILT_STATUS_POLA_RIGHT;
			break;

		case TILT_STATUS_POLA_RIGHT:
			new_tilt_status |= TILT_STATUS_POLA_LEFT;
			break;

		case TILT_STATUS_POLA_DOWN:
			new_tilt_status |= TILT_STATUS_POLA_DOWN;
			break;

		case TILT_STATUS_POLA_UP:
			new_tilt_status |= TILT_STATUS_POLA_UP;
			break;
		}
		
#elif defined(MOTION_SENSOR_FRONT_180) //MCUBE_PLACEMENT_BOTTOM_LEFT_UP
	
	switch (bafr_status)
		{
		case TILT_STATUS_BAFR_FRONT:
			new_tilt_status |= TILT_STATUS_BAFR_BACK;
			break;

		case TILT_STATUS_BAFR_BACK:
			new_tilt_status |= TILT_STATUS_BAFR_FRONT;
			break;
		}
		switch (pola_status)
		{
		case TILT_STATUS_POLA_LEFT:
			new_tilt_status |= TILT_STATUS_POLA_DOWN;
			break;

		case TILT_STATUS_POLA_RIGHT:
			new_tilt_status |= TILT_STATUS_POLA_UP;
			break;

		case TILT_STATUS_POLA_DOWN:
			new_tilt_status |= TILT_STATUS_POLA_LEFT;
			break;

		case TILT_STATUS_POLA_UP:
			new_tilt_status |= TILT_STATUS_POLA_RIGHT;
			break;
		}
		
#elif defined(MOTION_SENSOR_FRONT_270) //MCUBE_PLACEMENT_BOTTOM_LEFT_DOWN
	
	switch (bafr_status)
		{
		case TILT_STATUS_BAFR_FRONT:
			new_tilt_status |= TILT_STATUS_BAFR_BACK;
			break;

		case TILT_STATUS_BAFR_BACK:
			new_tilt_status |= TILT_STATUS_BAFR_FRONT;
			break;
		}
		switch (pola_status)
		{
		case TILT_STATUS_POLA_LEFT:
			new_tilt_status |= TILT_STATUS_POLA_LEFT;
			break;

		case TILT_STATUS_POLA_RIGHT:
			new_tilt_status |= TILT_STATUS_POLA_RIGHT;
			break;

		case TILT_STATUS_POLA_DOWN:
			new_tilt_status |= TILT_STATUS_POLA_UP;
			break;

		case TILT_STATUS_POLA_UP:
			new_tilt_status |= TILT_STATUS_POLA_DOWN;
			break;
		}
		
#endif

	*status = new_tilt_status;
	time_ms = mc3230_get_milli_time(); /*get time stamp*/
	
#ifdef MS_DBG
	kal_prompt_trace(MOD_ENG,"Motion Sensor Status = : %x, time_stamp = %d   ",new_tilt_status, time_ms);
#endif

}


/*return sensor support gesture*/
kal_bool mc3230_query_gesture(kal_uint16 ms_gest_type)
{
	switch(ms_gest_type)
		{
			case MS_TAP:
				return KAL_TRUE;
				
			case MS_STEP:
				return KAL_TRUE;
				
			case MS_DROP:
				return KAL_TRUE;
				
			//only 3-axis sensor can support Flip gesture, 2-axis not support, return false.
			case MS_FLIP:
				return KAL_TRUE;
				
			default:
				return KAL_FALSE;
		}
}

kal_bool mc3230_get_sensor_params(kal_uint16 ms_params_type, MotionSensorQueryStruct *ms_params)
{
	kal_uint32 tilt_status;
	
	switch(ms_params_type)
		{
			case MS_DEV_STATUS:				
				mc3230_sensor_get_status(&tilt_status);
				ms_params->curr_val = tilt_status;
				#ifdef MS_DBG
				kal_prompt_trace(MOD_ENG,"MS_DEV_STATUS: curr_val = %x, max_val = %x, min_val = %x",ms_params->curr_val, ms_params->max_val, ms_params->min_val);
				#endif
				return KAL_TRUE;
				
			case MS_TAP_PULSE:
				MS_I2C_read(MS_REG_TAPP,MS_sensor_buffer,1);
				ms_params->curr_val = MS_sensor_buffer[0];
				ms_params->max_val = 0xF;
				ms_params->min_val = 0x0;	
				#ifdef MS_DBG			
				kal_prompt_trace(MOD_ENG,"MS_TAP_PULSE: curr_val = %x, max_val = %x, min_val = %x",ms_params->curr_val, ms_params->max_val, ms_params->min_val);
				#endif
				return KAL_TRUE;
				
			case MS_TAP_THRESHOLD:
				MS_I2C_read(MS_REG_TAP_TH,MS_sensor_buffer,1);
				ms_params->curr_val = MS_sensor_buffer[0];
				ms_params->max_val = 0xFF;
				ms_params->min_val = 0x0;				
				#ifdef MS_DBG
				kal_prompt_trace(MOD_ENG,"MS_TAP_THRESHOLD: curr_val = %x, max_val = %x, min_val = %x",ms_params->curr_val, ms_params->max_val, ms_params->min_val);
				#endif
				return KAL_TRUE;

			case MS_ACC_DATA_RESOLUTION:				
				ms_params->curr_val = (MC3230_RANGE * 1000)/(1<<MC3230_RESOLUTION);
				#ifdef MS_DBG
				kal_prompt_trace(MOD_ENG,"MS_ACC_DATA_RESOLUTION: curr_val = %x, max_val = %x, min_val = %x",ms_params->curr_val, ms_params->max_val, ms_params->min_val);
				#endif
				return KAL_TRUE;
				
			default:
				return KAL_FALSE;
		}
}

kal_bool mc3230_set_sensor_params(kal_uint16 ms_params_type, kal_uint32 ms_params)
{
	switch(ms_params_type)
		{
			case MS_TAP_PULSE:
				if((ms_params>=0)&&(ms_params<=0xF))
					{
						MS_I2C_write_byte(MS_REG_MODE, MS_STANDBY_MODE); //standby mode
						MS_I2C_write_byte(MS_REG_TAPP,ms_params);
						MS_I2C_write_byte(MS_REG_MODE, MS_WAKE_MODE); //wake up mode
						return KAL_TRUE;
					}
				else  // invalid value
					{
						return KAL_TRUE;
					}
								
			case MS_TAP_THRESHOLD:
				if((ms_params>=0)&&(ms_params<=0xFF))
					{
						MS_I2C_write_byte(MS_REG_MODE, MS_STANDBY_MODE); //standby mode
						MS_I2C_write_byte(MS_REG_TAP_TH,ms_params);
						MS_I2C_write_byte(MS_REG_MODE, MS_WAKE_MODE); //wake up mode
						return KAL_TRUE;
					}
				else  // invalid value
					{
						return KAL_TRUE;
					}
				
			default:
				return KAL_FALSE;
		}
}

void mc3230_sensor_pwr_up(void)
{
	MS_I2C_write_byte(MS_REG_MODE, MS_STANDBY_MODE); //standby mode
	MS_I2C_write_byte(MS_REG_MODE, MS_WAKE_MODE);
}
void mc3230_sensor_pwr_down(void)
{
	MS_I2C_write_byte(MS_REG_MODE, MS_STANDBY_MODE); //standby mode
}
void mc3230_sensor_init(void)
{
#ifdef MS_DBG
	sprintf(ms_buff,"mc3230_sensor_init start");
	kal_bootup_print(ms_buff);
#endif

	 ms_i2c_configure(MS_SLAVE_ADDR, MS_DELAY_TIME); 
	  
	 mc3230_sensor_pwr_up();
	 //get chipid
	 MS_I2C_read(MS_REG_CHIPID,MS_sensor_buffer,1);
#ifdef MS_DBG
	sprintf(ms_buff,"mc3230 chip id = %d",MS_sensor_buffer[0]);
	kal_bootup_print(ms_buff);
#endif

	//get Product code
	MS_I2C_read(MS_REG_PCODE,MS_sensor_buffer,1);
#ifdef MS_DBG
	sprintf(ms_buff,"mc3230 Product code = %d",MS_sensor_buffer[0]);
	kal_bootup_print(ms_buff);
#endif
		 
	 mc3230_sensor_pwr_down();//standby mode

	 /* Interrupt Configuration */
	 MS_I2C_write_byte(MS_REG_INTEN,MC3230_DFLT_INTS);
	 
	 /* Sample Rate Controls */
	 MS_I2C_write_byte(MS_REG_SC,0x00);

	 /*Enable TAP detection in z directon*/
	 MS_I2C_write_byte(MS_REG_TAPEN,TAP_Z_ENABLE);
	 
 	 /*Configure TAP threshold*/
	 MS_I2C_write_byte(MS_REG_TAP_TH,0x0D);

	 /*Configure TAP Pulse Register*/
	 MS_I2C_write_byte(MS_REG_TAPP,0x04);

	 /*Drop control*/
	 MS_I2C_write_byte(MS_REG_DROP_CTRL,0x01);
	 MS_I2C_write_byte(MS_REG_DROP_TH,0xab);

	 /*Shake*/
	 MS_I2C_write_byte(MS_REG_SHDB,SHAKE_DEBOUNCE);
	 MS_I2C_write_byte(MS_REG_SHAKE_TH,SHAKE_THRESHOLD);
	 
	 /* Mode Configuration Structure */	 
	 MS_I2C_write_byte(MS_REG_MODE,0x81); //wake up mode
}

/*customizaton function pointer*/
MotionSensor_customize_function_struct ms_custom_func=
{
     ms_get_data,
     mc3230_sensor_get_data,     
     mc3230_sensor_init,
     mc3230_sensor_pwr_up,
     mc3230_sensor_pwr_down,
     NULL,
	 NULL,
	 NULL,
	 NULL,
     mc3230_query_gesture,
     mc3230_get_sensor_params,
     mc3230_set_sensor_params
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
