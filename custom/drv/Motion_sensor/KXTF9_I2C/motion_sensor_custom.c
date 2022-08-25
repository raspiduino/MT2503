/*****************************************************************************
 *
 * Filename:
 * ---------
 *    Motion_sensor_custom.c
 *
 * Project:
 * --------
 *    Motion Sensor KTXF9 I2C Interface
 *
 * Description:
 * ------------
 *   This Module defines Serial Interface.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 ****************************************************************************/
#ifdef MOTION_SENSOR_SUPPORT
#include "kal_release.h"
#include "custom_config.h" 
#include "gpio_sw.h"
#include "drv_comm.h"
#include "eint.h"
#include "motion_sensor.h"
#include "stack_config.h"
#include "motion_sensor_custom.h"   
#include "motion_sensor_iic.h"

    

/*customizaton function pointer*/
MotionSensor_customize_function_struct ms_custom_func=
{
	ms_get_data,
	acc_sensor_get_acc,
	acc_sensor_init,
	acc_sensor_pwr_up,
	acc_sensor_pwr_down,
	acc_sensor_read_int_status,
	acc_sensor_clear_int_status,
	acc_sensor_configure_low_g,
	acc_sensor_configure_high_g,
	KXTF9_query_gesture,
    KXTF9_get_sensor_params,
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
	MOTION_SENSOR_INT_SUPPORT,
	MOTION_SENSOR_INT_LEVEL,
	MOTION_SENSOR_INT/*channel*/    
};	
/*
* FUNCTION                                                            
*	acc_sensor_read_int_status
*
* DESCRIPTION                                                           
*   	This function is to read interrupt status
*
* CALLS  
*
* PARAMETERS
*  None
*	 
* RETURNS
*	None
*/
void acc_sensor_read_int_status(kal_bool *low_g, kal_bool *high_g)
{

}
/*
* FUNCTION                                                            
*	acc_sensor_clear_int_status
*
* DESCRIPTION                                                           
*   	This function is to clear interrupt
*
* CALLS  
*
* PARAMETERS
*  None
*	
* RETURNS
*	None
*/
void acc_sensor_clear_int_status(void)
{
 
}
/*Customization functin*/ 
/*
* FUNCTION                                                            
*	acc_sensor_get_acc
*
* DESCRIPTION                                                           
*   	This function is to get ADC value in every axis
*
* CALLS  
*
* PARAMETERS
*	x_adc: ADC value in X-axis
*	y_adc: ADC value in Y-axis
*	z_adc: ADC value in Z-axis
*
* RETURNS
*	None
*/ 
void acc_sensor_get_acc(kal_uint16 *x_adc, kal_uint16 *y_adc, kal_uint16 *z_adc)
{	         
   /*x axis*/      
   *x_adc=motion_sensor_read_acc_data(MOTION_SENSOR_XOUT_L);
   /*
   if(*x_adc>ACC_0G_X)
   	*x_adc=ACC_0G_X-(*x_adc-ACC_0G_X);
   else
   	*x_adc=ACC_0G_X+(ACC_0G_X-*x_adc);
   	*/
      
   /*y axis*/      
   *y_adc=motion_sensor_read_acc_data(MOTION_SENSOR_YOUT_L);
      
   /*z axis*/      
   *z_adc=motion_sensor_read_acc_data(MOTION_SENSOR_ZOUT_L);   
}
/*
* FUNCTION                                                            
*	acc_sensor_pwr_up
*
* DESCRIPTION                                                           
*   	This function is to power up acceleration module
*
* CALLS  
*
* PARAMETERS
*  None
*	
* RETURNS
*	None
*/    
void acc_sensor_pwr_up(void)
{
   kal_int32 i;
   kal_prompt_trace(MOD_ENG,"----acc_sensor_pwr_up start----");
   motion_sensor_write_data(0x80, MOTION_SENSOR_CTRL_REGC);//ktxf9 reset
   MS_Delay(30000);//delay for ktxf9 reset
   motion_sensor_write_data(0x00, MOTION_SENSOR_CTRL_REGA);
   motion_sensor_write_data(0x50, MOTION_SENSOR_CTRL_REGA);//set to 12 bit 8g
   motion_sensor_write_data(0x00, MOTION_SENSOR_CTRL_REGB);
   motion_sensor_write_data(0xd0, MOTION_SENSOR_CTRL_REGA);//set to work mode
   motion_sensor_write_data(0x00,MOTION_SENSOR_INT_CTRL_REG1);//disable all interrupt funs
   motion_sensor_write_data(0x00,MOTION_SENSOR_INT_CTRL_REG2);
   motion_sensor_write_data(0x00,MOTION_SENSOR_INT_CTRL_REG3);
   kal_prompt_trace(MOD_ENG,"----acc_sensor_pwr_up end----");
}
/*
* FUNCTION                                                            
*	acc_sensor_pwr_down 
*
* DESCRIPTION                                                           
*   	This function is to power down acceleration
*
* CALLS  
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*/ 
void acc_sensor_pwr_down(void)
{   
   motion_sensor_write_data(0x40, MOTION_SENSOR_CTRL_REGA);//set to sleep mode   
}
/*
* FUNCTION                                                            
*	acc_sensor_configure_high_g
*
* DESCRIPTION                                                           
*   	
*
* CALLS  
*
* PARAMETERS
*  None
*	
* RETURNS
*	None
*/     
void acc_sensor_configure_low_g(kal_uint32 debounce, kal_uint32 threshold)
{
 	
      
}   
/*
* FUNCTION                                                            
*	acc_sensor_configure_high_g
*
* DESCRIPTION                                                           
*   	
*
* CALLS  
*
* PARAMETERS
*  None
*	
* RETURNS
*	None
*/    
void acc_sensor_configure_high_g(kal_uint32 debounce, kal_uint32 threshold)
{
 	      
}     

/*
* FUNCTION                                                            
*	acc_sensor_init
*
* DESCRIPTION                                                           
*   	This function is to initialize acceleration module
*
* CALLS  
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*/ 

void acc_sensor_init(void)
{  
   motion_senosr_interface_init();
}


/*return sensor support gesture*/
kal_bool KXTF9_query_gesture(kal_uint16 ms_gest_type)
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

kal_bool KXTF9_get_sensor_params(kal_uint16 ms_params_type, MotionSensorQueryStruct *ms_params)
{
	kal_uint32 tilt_status;
	
	switch(ms_params_type)
		{
			case MS_ACC_DATA_RESOLUTION:				
				ms_params->curr_val = (1 * 1000)/(ACC_1G_X - ACC_0G_X);
				kal_prompt_trace(MOD_ENG,"MS_ACC_DATA_RESOLUTION: curr_val = %x, max_val = %x, min_val = %x",ms_params->curr_val, ms_params->max_val, ms_params->min_val);
				return KAL_TRUE;
				
			default:
				return KAL_FALSE;
		}
}
/*
* FUNCTION                                                            
*	ms_get_data
*
* DESCRIPTION                                                           
*   	This function is to get customization data
*
* CALLS  
*
* PARAMETERS
*	None
*	
* RETURNS
*	customization data
*/ 
MotionSensor_custom_data_struct *ms_get_data(void) 
{
   ms_custom_data_def.int_chan=99;
   return (&ms_custom_data_def);
}      
/*
* FUNCTION                                                            
*	ms_GetFunc
*
* DESCRIPTION                                                           
*   	This function is to enable to customization function pointer
*
* CALLS  
*
* PARAMETERS
*	None 
*	
* RETURNS
*	function pointer
*/  
MotionSensor_customize_function_struct *ms_GetFunc(void)
{   
   return (&ms_custom_func);  
} 
#endif
