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
#include "us_timer.h" 
#include "motion_sensor.h"
#include "motion_sensor_hw_define.h"
#include "motion_sensor_custom.h"
 

kal_uint8 acce_test_flag=0;

#define MS_DELAY_TIME 3

#define MS_I2C_DELAY ms_i2c_udelay(MS_DELAY_TIME);

void ms_i2c_udelay(kal_uint32 delay)
{
	kal_uint32 ust = 0, ust1 = 0; //ust_get_current_time
	kal_uint32 count = 0;
	kal_uint32 break_count = 0;
	
	if(delay > 4615) //longer than 1 tick
	{
		kal_sleep_task(delay/4615);
		delay = delay%4615;
	}
	
	ust = ust_get_current_time();
	
	do{
		ust1 = ust_get_current_time();
		if(ust1 != ust)
			count++;
		else
			break_count++;
		ust = ust1;
	}while((count < delay) && (break_count < 0xFFFFFF));
}

/*customizaton function pointer*/
MotionSensor_customize_function_struct ms_custom_func=
{
     ms_get_data,
     acc_sensor_get_5bytes,
     acc_sensor_init,
     acc_sensor_pwr_up,
     acc_sensor_pwr_down,
     NULL,
     NULL,
     NULL,
     NULL,
     mxc6202_query_gesture,
     mxc6202_get_sensor_params,
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
	ACC_MINUS1G_Z    
};	
/*Customization functin*/ 
/*
* FUNCTION                                                            
*	acc_sensor_get_5bytes
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
//kal_uint16 acc_start, acc_end;

//char temp_buffer[256];

void acc_sensor_get_5bytes(kal_uint16 *x_adc, kal_uint16 *y_adc, kal_uint16 *z_adc)
{
	//signed char i,j;
	kal_int32 i;
	volatile kal_uint32 j;
	kal_uint16 x_out, y_out;
	//kal_uint32 savedMask;
	kal_uint16 get_byte[5]={0};
	kal_uint16 x, y;
	
	//savedMask = SaveAndSetIRQMask();
	//acc_start=DRV_Reg(0x80200000);

/*----- START -----*/ 
	SET_I2C_DATA_OUTPUT;
	SET_I2C_CLK_OUTPUT; 
	SET_I2C_DATA_HIGH;	
	SET_I2C_CLK_HIGH;		
	SET_I2C_DATA_LOW;
	MS_I2C_DELAY;
	SET_I2C_CLK_LOW;


/*----- SEND -----*/
//----- 1ST --------
	MS_I2C_DELAY;
	
	for (i=7;i>=0;i--)
	{	/* data bit 7~0 */
		if (MXC6202_I2C_SLAVE_ADDR & (1<<i))     /* 0x20 -> slave address & write */
		{
			SET_I2C_DATA_HIGH;
		}
		else
		{
			SET_I2C_DATA_LOW;
		}
		MS_I2C_DELAY;
		SET_I2C_CLK_HIGH;
		MS_I2C_DELAY;
		SET_I2C_CLK_LOW;
	}
	
	/* don't care bit, 9th bit */
	SET_I2C_DATA_LOW;
	SET_I2C_DATA_INPUT;
	MS_I2C_DELAY;
	SET_I2C_CLK_HIGH;
	MS_I2C_DELAY;
	SET_I2C_CLK_LOW;
	SET_I2C_DATA_OUTPUT;	
	

//----- 2ND --------
	for (i=7;i>=0;i--)
	{	/* data bit 7~0 */
		if (0x00 & (1<<i))     /* starting address to read */
		{
			SET_I2C_DATA_HIGH;
		}
		else
		{
			SET_I2C_DATA_LOW;
		}
		SET_I2C_CLK_HIGH;
		MS_I2C_DELAY;
		SET_I2C_CLK_LOW;
	}	

	/* don't care bit, 9th bit */
	SET_I2C_DATA_LOW;
	SET_I2C_DATA_INPUT;
	MS_I2C_DELAY;
	SET_I2C_CLK_HIGH;
	MS_I2C_DELAY;
	SET_I2C_CLK_LOW;
	SET_I2C_DATA_OUTPUT;	


/*----- RESTART -----*/
	SET_I2C_DATA_HIGH;	
	SET_I2C_CLK_HIGH;
	MS_I2C_DELAY;
	SET_I2C_DATA_LOW;
	MS_I2C_DELAY;
	SET_I2C_CLK_LOW;


//----- 3RD --------
	for (i=7;i>=0;i--)
	{	/* data bit 7~0 */
		if ((MXC6202_I2C_SLAVE_ADDR+1) & (1<<i))     /* 0x21 -> slave address & read */
		{
			SET_I2C_DATA_HIGH;
		}
		else
		{
			SET_I2C_DATA_LOW;
		}
		SET_I2C_CLK_HIGH;
		MS_I2C_DELAY;
		SET_I2C_CLK_LOW;
	}

	/* don't care bit, 9th bit */
	SET_I2C_DATA_LOW;
	SET_I2C_DATA_INPUT;
	MS_I2C_DELAY;
	SET_I2C_CLK_HIGH;
	MS_I2C_DELAY;
	SET_I2C_CLK_LOW;
	SET_I2C_DATA_OUTPUT;	
	
//----- 4TH --------
// Get 1st data
	SET_I2C_DATA_INPUT;

	for (i=7;i>=0;i--)
	{	// data bit 7~0 
		SET_I2C_CLK_HIGH;
		MS_I2C_DELAY;
		if(GET_I2C_DATA_BIT)
			{
			get_byte[0] |= (1<<i);	
			}
		SET_I2C_CLK_LOW;
		MS_I2C_DELAY;
	}
	// don't care bit, 9th bit 
	SET_I2C_DATA_OUTPUT;
	SET_I2C_DATA_LOW;
		MS_I2C_DELAY;
	SET_I2C_CLK_HIGH;
		MS_I2C_DELAY;
	SET_I2C_CLK_LOW;


//----- 5TH --------
// Get 2nd data
	SET_I2C_DATA_INPUT;

	for (i=7;i>=0;i--)
	{	// data bit 7~0 
		SET_I2C_CLK_HIGH;
		MS_I2C_DELAY;
		if(GET_I2C_DATA_BIT)
			get_byte[1] |= (1<<i);	
		SET_I2C_CLK_LOW;
		MS_I2C_DELAY;
	}
	// don't care bit, 9th bit 
	SET_I2C_DATA_OUTPUT;
	SET_I2C_DATA_LOW;
		MS_I2C_DELAY;
	SET_I2C_CLK_HIGH;
		MS_I2C_DELAY;
	SET_I2C_CLK_LOW;



//----- 6TH --------
// Get 3rd data
	SET_I2C_DATA_INPUT;

	for (i=7;i>=0;i--)
	{	// data bit 7~0 
		SET_I2C_CLK_HIGH;
		MS_I2C_DELAY;
		if(GET_I2C_DATA_BIT)
			get_byte[2] |= (1<<i);	
		SET_I2C_CLK_LOW;
		MS_I2C_DELAY;
	}
	// don't care bit, 9th bit 
	SET_I2C_DATA_OUTPUT;
	SET_I2C_DATA_LOW;
		MS_I2C_DELAY;
	SET_I2C_CLK_HIGH;
		MS_I2C_DELAY;
	SET_I2C_CLK_LOW;

//----- 7TH --------
// Get 4th data
	SET_I2C_DATA_INPUT;

	for (i=7;i>=0;i--)
	{	// data bit 7~0 
		SET_I2C_CLK_HIGH;
		MS_I2C_DELAY;
		if(GET_I2C_DATA_BIT)
			get_byte[3] |= (1<<i);	
		SET_I2C_CLK_LOW;
		MS_I2C_DELAY;
	}
	// don't care bit, 9th bit 
	SET_I2C_DATA_OUTPUT;
	SET_I2C_DATA_LOW;
		MS_I2C_DELAY;
	SET_I2C_CLK_HIGH;
		MS_I2C_DELAY;
	SET_I2C_CLK_LOW;

//----- 8TH --------
// Get 5th data
	SET_I2C_DATA_INPUT;

	for (i=7;i>=0;i--)
	{	// data bit 7~0 
		SET_I2C_CLK_HIGH;
		MS_I2C_DELAY;
		if(GET_I2C_DATA_BIT)
			get_byte[4] |= (1<<i);	
		SET_I2C_CLK_LOW;
		MS_I2C_DELAY;
	}
/*	
	// don't care bit, 9th bit 
	SET_I2C_DATA_OUTPUT;
	SET_I2C_DATA_LOW;
		for(j=0;j<delay_short;j++);		
	SET_I2C_CLK_HIGH;
		for(j=0;j<delay_long;j++);		
	SET_I2C_CLK_LOW;
*/


/*----- STOP -----*/	
	SET_I2C_CLK_OUTPUT;
	SET_I2C_DATA_OUTPUT;
	SET_I2C_CLK_LOW;
	SET_I2C_DATA_LOW;
	MS_I2C_DELAY;
	SET_I2C_CLK_HIGH;
	MS_I2C_DELAY;
	SET_I2C_DATA_HIGH;
	   
	//acc_end=DRV_Reg(0x80200000);
	//RestoreIRQMask(savedMask);

	*x_adc=(get_byte[1]<<8)|get_byte[2];
	*y_adc=(get_byte[3]<<8)|get_byte[4];
	*z_adc=0;
	
	x=*x_adc;
	y=*y_adc;

#if defined(MOTION_SENSOR_BACK_0)	
	*x_adc= x;
	*y_adc= y;
#elif defined(MOTION_SENSOR_BACK_90)
	*x_adc= y;
	*y_adc= 2*ACC_0G_X-x;
#elif defined(MOTION_SENSOR_BACK_180)
	*x_adc= 2*ACC_0G_X-x;
	*y_adc= 2*ACC_0G_Y-y;
#elif defined(MOTION_SENSOR_BACK_270)
	*x_adc= 2*ACC_0G_Y-y;
	*y_adc= x;
#elif defined(MOTION_SENSOR_FRONT_0)
	*x_adc= 2*ACC_0G_X-x;
	*y_adc= y;
#elif defined(MOTION_SENSOR_FRONT_90)
	*x_adc= 2*ACC_0G_Y-y;
	*y_adc= 2*ACC_0G_X-x;
#elif defined(MOTION_SENSOR_FRONT_180)
	*x_adc= x;
	*y_adc= 2*ACC_0G_Y-y;
#elif defined(MOTION_SENSOR_FRONT_270)
	*x_adc= y;
	*y_adc= x;
#endif

	//sprintf(temp_buffer, "x=%d, y=%d, x_r=%d, y_r=%d", x, y, *x_adc, *y_adc);
	//rmmi_write_to_uart((kal_uint8*) temp_buffer, strlen(temp_buffer), KAL_TRUE);
	
	/*test*/
	x_out=(get_byte[1]<<8)|get_byte[2];
	y_out=(get_byte[3]<<8)|get_byte[4];

	for( j=0; j<5; j++) get_byte[j] = 0;
                 	
}	/* I2C_send_byte() */

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
	//signed char i,j;
	kal_int32 i,j;
   #ifdef ACC_KAL_DEBUG	
	dbg_printWithTime("# acc_sensor_pwr_up() - MotionSensor.c #\r\n");
	#endif

/*----- START -----*/
	SET_I2C_DATA_OUTPUT;
	SET_I2C_CLK_OUTPUT; 
	SET_I2C_DATA_HIGH;	
	SET_I2C_CLK_HIGH;
	MS_I2C_DELAY;
	SET_I2C_DATA_LOW;
	MS_I2C_DELAY;
	SET_I2C_CLK_LOW;


/*----- SEND -----*/
//----- 1ST --------
	for (i=7;i>=0;i--)
	{	/* data bit 7~0 */
		if (MXC6202_I2C_SLAVE_ADDR & (1<<i))     /* 0x20 -> slave address & write */
		{
			SET_I2C_DATA_HIGH;
		}
		else
		{
			SET_I2C_DATA_LOW;
		}
		SET_I2C_CLK_HIGH;
		MS_I2C_DELAY;
		SET_I2C_CLK_LOW;
	}
	
	/* don't care bit, 9th bit */
	SET_I2C_DATA_LOW;
	SET_I2C_DATA_INPUT;
	MS_I2C_DELAY;
	SET_I2C_CLK_HIGH;
	MS_I2C_DELAY;
	SET_I2C_CLK_LOW;
	SET_I2C_DATA_OUTPUT;	


//----- 2ND --------
	for (i=7;i>=0;i--)
	{	/* data bit 7~0 */
		if (0x00 & (1<<i))     /* 0x00 -> internal register */
		{
			SET_I2C_DATA_HIGH;
		}
		else
		{
			SET_I2C_DATA_LOW;
		}
		SET_I2C_CLK_HIGH;
		MS_I2C_DELAY;
		SET_I2C_CLK_LOW;
	}	

	/* don't care bit, 9th bit */
	SET_I2C_DATA_LOW;
	SET_I2C_DATA_INPUT;
	MS_I2C_DELAY;
	SET_I2C_CLK_HIGH;
	MS_I2C_DELAY;
	SET_I2C_CLK_LOW;
	SET_I2C_DATA_OUTPUT;	


//----- 3RD --------
	for (i=7;i>=0;i--)
	{	/* data bit 7~0 */
		if (0x00 & (1<<i))     /* power-up */
		//if (0x08 & (1<<i))     /* power-up with temperature */
		{
			SET_I2C_DATA_HIGH; 
		}
		else
		{
			SET_I2C_DATA_LOW;
		}
		SET_I2C_CLK_HIGH;
		MS_I2C_DELAY;
		SET_I2C_CLK_LOW;
	}

	/* don't care bit, 9th bit */
	SET_I2C_DATA_LOW; 
	SET_I2C_DATA_INPUT;
	MS_I2C_DELAY;
	SET_I2C_CLK_HIGH;
	MS_I2C_DELAY;
	SET_I2C_CLK_LOW;
	SET_I2C_DATA_OUTPUT;	


/*----- STOP -----*/	
	SET_I2C_CLK_OUTPUT;
	SET_I2C_DATA_OUTPUT;
	SET_I2C_CLK_LOW;
	SET_I2C_DATA_LOW;
	MS_I2C_DELAY;
	SET_I2C_CLK_HIGH;
	MS_I2C_DELAY;
	SET_I2C_DATA_HIGH;
	
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
	//signed char i,j;
	kal_int32 i,j;
   #ifdef ACC_KAL_DEBUG	
	dbg_printWithTime("# acc_sensor_pwr_down() - MotionSensor.c #\r\n");
   #endif
/*----- START -----*/
	SET_I2C_DATA_OUTPUT;
	SET_I2C_CLK_OUTPUT; 
	SET_I2C_DATA_HIGH;	
	SET_I2C_CLK_HIGH;
	MS_I2C_DELAY;
	SET_I2C_DATA_LOW;
	MS_I2C_DELAY;
	SET_I2C_CLK_LOW;


/*----- SEND -----*/
//----- 1ST --------
	for (i=7;i>=0;i--)
	{	/* data bit 7~0 */
		if (MXC6202_I2C_SLAVE_ADDR & (1<<i))     /* 0x20 -> slave address & write */
		{
			SET_I2C_DATA_HIGH;
		}
		else
		{
			SET_I2C_DATA_LOW;
		}
		SET_I2C_CLK_HIGH;
		MS_I2C_DELAY;
		SET_I2C_CLK_LOW;
	}
	
	/* don't care bit, 9th bit */
	SET_I2C_DATA_LOW;
	SET_I2C_DATA_INPUT;
	MS_I2C_DELAY;
	SET_I2C_CLK_HIGH;
	MS_I2C_DELAY;
	SET_I2C_CLK_LOW;
	SET_I2C_DATA_OUTPUT;	


//----- 2ND --------
	for (i=7;i>=0;i--)
	{	/* data bit 7~0 */
		if (0x00 & (1<<i))     /* 0x00 -> internal register */
		{
			SET_I2C_DATA_HIGH;
		}
		else
		{
			SET_I2C_DATA_LOW;
		}
		SET_I2C_CLK_HIGH;
		MS_I2C_DELAY;
		SET_I2C_CLK_LOW;
	}	

	/* don't care bit, 9th bit */
	SET_I2C_DATA_LOW;
	SET_I2C_DATA_INPUT;
	MS_I2C_DELAY;
	SET_I2C_CLK_HIGH;
	MS_I2C_DELAY;
	SET_I2C_CLK_LOW;
	SET_I2C_DATA_OUTPUT;	


//----- 3RD --------
	for (i=7;i>=0;i--)
	{	/* data bit 7~0 */
		if (0x01 & (1<<i))     /* power-down */
		{
			SET_I2C_DATA_HIGH;
		}
		else
		{
			SET_I2C_DATA_LOW;
		}
		SET_I2C_CLK_HIGH;
		MS_I2C_DELAY;
		SET_I2C_CLK_LOW;
	}

	/* don't care bit, 9th bit */
	SET_I2C_DATA_LOW;
	SET_I2C_DATA_INPUT;
	MS_I2C_DELAY;
	SET_I2C_CLK_HIGH;
	MS_I2C_DELAY;
	SET_I2C_CLK_LOW;
	SET_I2C_DATA_OUTPUT;	


/*----- STOP -----*/	
	SET_I2C_CLK_OUTPUT;
	SET_I2C_DATA_OUTPUT;
	SET_I2C_CLK_LOW;
	SET_I2C_DATA_LOW;
	MS_I2C_DELAY;
	SET_I2C_CLK_HIGH;
	MS_I2C_DELAY;
	SET_I2C_DATA_HIGH;
	
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
	
	//static unsigned char p_flag=0;	
	static kal_uint8 p_flag=0;
	#ifdef ACC_KAL_DEBUG	
	dbg_printWithTime("# acc_sensor_init() - MotionSensor.c\r\n");
   #endif         
   /*initial sensor*/
#ifndef __CUST_NEW__
	GPIO_ModeSetup(ACC_SENSOR_SCK, 0x00);
#endif /* __CUST_NEW__ */
	SET_I2C_CLK_OUTPUT;
	SET_I2C_CLK_HIGH;

#ifndef __CUST_NEW__
	GPIO_ModeSetup(ACC_SENSOR_SDA, 0x00);
#endif /* __CUST_NEW__ */
	SET_I2C_DATA_OUTPUT;
	SET_I2C_DATA_HIGH;

	//for( j=0; j<5; j++) get_byte[j] = 0;

	if( p_flag == 0 )
	{
	   #ifdef ACC_KAL_DEBUG	   		
		dbg_printWithTime("*** Power down~~!! ***\r\n");
		#endif
		acc_sensor_pwr_down();
		//Power down again, because the first doesn't take effect
		acc_sensor_pwr_down();
		p_flag = 1;
	}
	else
	{
	   #ifdef ACC_KAL_DEBUG		
		dbg_printWithTime("*** Power up~~!! ***\r\n");
		#endif
		acc_sensor_pwr_up();
		p_flag = 0; 
	}
	
}

/*return sensor support gesture*/
kal_bool mxc6202_query_gesture(kal_uint16 ms_gest_type)
{
	switch(ms_gest_type)
		{
			//only 3-axis sensor can support Flip gesture, 2-axis not support, return false.
			case MS_FLIP:
				return KAL_FALSE;
				
			default:
				return KAL_FALSE;
		}
}

kal_bool mxc6202_get_sensor_params(kal_uint16 ms_params_type, MotionSensorQueryStruct *ms_params)
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
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
