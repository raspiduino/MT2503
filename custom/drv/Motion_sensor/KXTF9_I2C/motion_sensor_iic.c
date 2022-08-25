/*****************************************************************************
 *
 * Filename:
 * ---------
 *    Motion_sensor_iic.c
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
#include 	"kal_release.h" 
#include    "drv_comm.h"  
#include    "gpio_hw.h"
#include    "gpio_sw.h"
#include    "motion_sensor.h"  
#include    "motion_sensor_custom.h"
#include    "motion_sensor_iic.h" 
#include	"stack_config.h"

#define   ACC_DEBUG 


void MS_Delay(kal_uint16 time)
{
	kal_uint16 i;
	for(i=0;i<time;i++);
}

void I2C_Start(void)
{
	SET_MS_DATA_OUTPUT;
	SET_MS_DATA_HIGH;
	SET_MS_CLK_HIGH;
	SET_MS_DATA_LOW;
	MS_Delay(MS_DELAY);
	SET_MS_CLK_LOW;
	MS_Delay(MS_DELAY);	
}


void I2C_Restart(void)
{
	SET_MS_DATA_OUTPUT;
	SET_MS_DATA_HIGH;
	SET_MS_CLK_HIGH;
	SET_MS_DATA_LOW;
	MS_Delay(MS_DELAY);
	SET_MS_CLK_LOW;
	MS_Delay(MS_DELAY);
}


void I2C_Stop(void)
{
	SET_MS_DATA_OUTPUT;
	SET_MS_DATA_LOW;
	MS_Delay(MS_DELAY);
	SET_MS_CLK_HIGH;
	MS_Delay(MS_DELAY);
	SET_MS_DATA_HIGH;
	MS_Delay(MS_DELAY);
}


/*************************************************************************
* FUNCTION
*	motioin sensor i2c interface initialize
*
* DESCRIPTION
*	This function initializes i2c interface.
*
* PARAMETERS
*  	None
* RETURNS
*	None 
* 
* GLOBALS AFFECTED
*
*************************************************************************/
void motion_senosr_interface_init(void) 
{     

    GPIO_ModeSetup(MS_I2C_CLK_PIN,0);
    GPIO_ModeSetup(MS_I2C_DATA_PIN,0);     
      
	SET_MS_CLK_HIGH;
	SET_MS_DATA_HIGH;
	SET_MS_CLK_OUTPUT;
	SET_MS_DATA_OUTPUT;		   
}
/*************************************************************************
* FUNCTION
*	motion_sensor_send_byte
*
* DESCRIPTION
*	This function send one byte to through software i2c
*
* PARAMETERS
*	send_byte : the data that writes out through software i2c
*
* RETURNS
*	None 
*
* GLOBALS AFFECTED
*
*************************************************************************/
void motion_sensor_send_byte(kal_uint8 send_byte)
{
	signed char i;
	
/*MSB  data bit 7~0 */ 
	for (i=7;i>=0;i--)
	{	
		if (send_byte & (1<<i))
		{
			SET_MS_DATA_HIGH;
		}
		else
		{
			SET_MS_DATA_LOW;
		}
		SET_MS_CLK_HIGH;
		SET_MS_CLK_LOW;
	}
/*receive ACK from SLAVE*/
	SET_MS_DATA_INPUT;
	SET_MS_CLK_HIGH;
	if(GET_MS_DATA==0)
		;//kal_prompt_trace(MOD_ENG,"revecie ACK(LOW) FORM SLAVE");
	else
		#ifdef ACC_DEBUG
			kal_prompt_trace(MOD_ENG,"can not revecie ACK(LOW) FORM SLAVE");
		#else
			;
		#endif
	SET_MS_CLK_LOW;
	SET_MS_DATA_OUTPUT;
}	
/*************************************************************************
* FUNCTION
*	motion_sensor_get_mul_byte
*
* DESCRIPTION
*	This function read multiple bytes through software IIC interface
*
* PARAMETERS
*	None
*
* RETURNS
*	the data that read from SCCB interface
* 
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint8 motion_sensor_get_mul_byte(void)
{     
	kal_uint8 get_byte=0;
	signed char i;  
	
/*MSB  data bit 7~0 */ 
	SET_MS_DATA_INPUT;
	for (i=7;i>=0;i--)
	{	
		SET_MS_CLK_HIGH;
		if (GET_MS_DATA)
			get_byte |= (1<<i);
		SET_MS_CLK_LOW;
	}
/* 9th ACK bit */
	SET_MS_DATA_OUTPUT;
	SET_MS_DATA_LOW;
	SET_MS_CLK_HIGH;
	SET_MS_CLK_LOW; 

	return get_byte;
}
/*************************************************************************
* FUNCTION
*	motion_sensor_get_byte
*
* DESCRIPTION
*	This function read one byte through software IIC interface
*
* PARAMETERS
*	None
*
* RETURNS
*	the data that read from SCCB interface
* 
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint8 motion_sensor_get_byte(void)
{     
	kal_uint8 get_byte=0;
	signed char i;  
	
/*MSB  data bit 7~0 */ 
	SET_MS_DATA_INPUT;
	for (i=7;i>=0;i--)
	{	
		SET_MS_CLK_HIGH;
		if (GET_MS_DATA)
			get_byte |= (1<<i);
		SET_MS_CLK_LOW;
	}
/* 9th NACK bit */
	SET_MS_DATA_OUTPUT;
	SET_MS_DATA_HIGH;
	SET_MS_CLK_HIGH;
	SET_MS_CLK_LOW; 
	SET_MS_DATA_LOW;

	return get_byte;
}


/*************************************************************************
* FUNCTION
*	motion_sensor_read_acc_data
*
* DESCRIPTION
*	This function is to read data via SPI.
*
* PARAMETERS
*  None
*
* RETURNS
*	received data
* 
* GLOBALS AFFECTED
*
*************************************************************************/
/*read*/ 
kal_uint16 motion_sensor_read_acc_data(kal_uint8 addr)
{

   kal_uint16 data=0; 
   kal_uint8 temp1=0, temp2=0;              

	I2C_Start();         
	motion_sensor_send_byte(MOTION_SENSOR_ADDRESS|MOTION_SENSOR_WRITE);			
	motion_sensor_send_byte(addr);
	I2C_Restart();
	motion_sensor_send_byte(MOTION_SENSOR_ADDRESS|MOTION_SENSOR_READ);
	temp1=motion_sensor_get_mul_byte();
	temp2=motion_sensor_get_byte();  
	data=(temp1>>4)|(temp2<<4);
	I2C_Stop();
	#ifdef ACC_DEBUG
		//kal_prompt_trace(MOD_ENG,"LOW:temp1=%x, HIGH:temp2=%x, data=%x",temp1,temp2,data);
	#endif


   if((data>=0)&&(data<ACC_0G_X))
   	  data+=ACC_0G_X;
   else
   	  data-=ACC_0G_X;
   
   return data;	
}

/*************************************************************************
* FUNCTION
*	motion_sensor_read_data
*
* DESCRIPTION
*	This function is to read data via I2C.
*
* PARAMETERS
*  None
*
* RETURNS
*	received data
* 
* GLOBALS AFFECTED
*
*************************************************************************/
/*read*/ 
kal_uint8 motion_sensor_read_data(kal_uint8 addr)
{    
	kal_uint8 data=0;              
	 
	I2C_Start();         
	motion_sensor_send_byte(MOTION_SENSOR_ADDRESS|MOTION_SENSOR_WRITE);			
	motion_sensor_send_byte(addr);/**/	
	I2C_Restart();/*sr*/
	motion_sensor_send_byte(MOTION_SENSOR_ADDRESS|MOTION_SENSOR_READ);
	data=motion_sensor_get_byte(); 
	I2C_Stop();   
	  
	return data;
}



/*************************************************************************
* FUNCTION
*	motion_sensor_write_data
*
* DESCRIPTION
*	This function is to write data via SCCB.
*
* PARAMETERS
*  transmitted data
*
* RETURNS
*	None
*   
* GLOBALS AFFECTED
*
*************************************************************************/
void motion_sensor_write_data(kal_uint8 data, kal_uint8 addr)
{
   
   I2C_Start();
	motion_sensor_send_byte(MOTION_SENSOR_ADDRESS|MOTION_SENSOR_WRITE);
	motion_sensor_send_byte(addr);
	motion_sensor_send_byte(data);
	I2C_Stop();	
}

#endif

