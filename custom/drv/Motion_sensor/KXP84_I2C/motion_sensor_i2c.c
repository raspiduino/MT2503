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
 *    serial_interface.c
 *
 * Project:
 * --------
 *   Maui_Software
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
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(MOTION_SENSOR_SUPPORT)
#include 	"kal_release.h" 
#include    "drv_comm.h"  
#include    "gpio_hw.h"
#include    "gpio_sw.h"
#include    "motion_sensor.h"  
#include    "motion_sensor_hw_define.h"
#include    "motion_sensor_custom.h"
#include    "motion_sensor_i2c.h" 
#include    "sccb.h"

#define   _TP_SW_2WIRE_ 
/*************************************************************************
* FUNCTION
*	motion_sensor_read_control
*
* DESCRIPTION
*	This function is to read data(8bits) via I2C.
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
kal_uint16 motion_sensor_read_control(kal_uint8 addr)     
{
   kal_uint16 data=0; 
   kal_uint8 temp1=0;                 
   #ifdef _TP_SW_2WIRE_/*sw*/        
   MS_START_TRANSMISSION();      
	motion_sensor_send_byte(MOTION_SENSOR_ADDRESS|MOTION_SENSOR_WRITE);
	motion_sensor_send_byte(addr);/**/
	motion_sensor_delay(100);	
	MS_RESTART_TRANSMISSION();/*sr*/
	motion_sensor_send_byte(MOTION_SENSOR_ADDRESS|MOTION_SENSOR_READ);
	temp1=motion_sensor_get_byte();	
	data=temp1;
	MS_STOP_TRANSMISSION();      	   
	#endif
	#ifdef _TP_HW_2WIRE_/*HW*/  
	data=sccb_read((addr));
	#endif
	return data;
}
   
/*************************************************************************
* FUNCTION
*	motion_sensor_delay
*
* DESCRIPTION
*	This function is to add delay. 
*
* PARAMETERS
*  None
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void motion_sensor_delay(kal_uint32 delay)
{
   kal_uint32 i;
   for(i=0;i<delay;i++){}
} 
/*************************************************************************
* FUNCTION
*	serial_init
*
* DESCRIPTION
*	This function initializes serial interface.
*
* PARAMETERS
*  None
* RETURNS
*	None 
* 
* GLOBALS AFFECTED
*
*************************************************************************/
void motion_senosr_serial_init(void) 
{                  
#ifndef __CUST_NEW__
   GPIO_ModeSetup(MS_I2C_CLK_PIN,0x0);
	GPIO_ModeSetup(MS_I2C_DATA_PIN,0x0);
   GPIO_ModeSetup(MS_I2C_CS_PIN,   0x0);   
   GPIO_ModeSetup(MS_I2C_RESET_PIN, 0x0);      
   GPIO_ModeSetup(MS_I2C_ADDR_PIN, 0x0);      
      
   GPIO_InitIO(OUTPUT,MS_I2C_CLK_PIN);   
   GPIO_InitIO(OUTPUT,MS_I2C_CS_PIN); 
   GPIO_InitIO(OUTPUT,MS_I2C_RESET_PIN);    
   GPIO_InitIO(OUTPUT,MS_I2C_ADDR_PIN);     
#endif /* __CUST_NEW__ */   
   GPIO_WriteIO(1,MS_I2C_RESET_PIN);
   GPIO_WriteIO(0,MS_I2C_RESET_PIN);
   GPIO_WriteIO(1,MS_I2C_CS_PIN);
   GPIO_WriteIO(1,MS_I2C_ADDR_PIN);
      
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
*	This function send one byte to through software SCCB
*
* PARAMETERS
*	send_byte : the data that writes out through software SCCB
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

	for (i=7;i>=0;i--)
	{	/* data bit 7~0 */ 
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
	/* don't care bit, 9th bit */

	SET_MS_DATA_LOW;
	SET_MS_CLK_HIGH;
	while (GET_MS_DATA_BIT);	
	SET_MS_CLK_LOW;
}	/* motion_sensor_send_byte() */
/*************************************************************************
* FUNCTION
*	motion_sensor_get_byte
*
* DESCRIPTION
*	This function read one byte through software SCCB interface
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
 
	SET_MS_DATA_INPUT;
	for (i=7;i>=0;i--)
	{	/* data bit 7~0 */
		SET_MS_CLK_HIGH;
		if (GET_MS_DATA_BIT)
			get_byte |= (1<<i);
		SET_MS_CLK_LOW;
	}
	/* don't care bit, 9th bit */
	SET_MS_DATA_OUTPUT;
	SET_MS_DATA_HIGH;
	SET_MS_CLK_HIGH;
	SET_MS_CLK_LOW; 
	SET_MS_DATA_LOW;

	return get_byte;
}	/* sccb_get_byte() */

/*************************************************************************
* FUNCTION
*	motion_sensor_read_data
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
kal_uint16 motion_sensor_read_data(kal_uint8 addr)
{    
   kal_uint16 data=0; 
   kal_uint8 temp1=0, temp2=0;              
   #ifdef _TP_SW_2WIRE_/*sw*/  
   MS_START_TRANSMISSION();         
	motion_sensor_send_byte(MOTION_SENSOR_ADDRESS|MOTION_SENSOR_WRITE);			
	motion_sensor_send_byte(addr);/**/	
	MS_RESTART_TRANSMISSION();/*sr*/
	motion_sensor_send_byte(MOTION_SENSOR_ADDRESS|MOTION_SENSOR_READ);
	temp1=motion_sensor_get_byte();
	temp2=motion_sensor_get_byte();  
	data=(temp1<<4)|(temp2>>4);
	MS_STOP_TRANSMISSION();   
   #endif  
   #ifdef _TP_HW_2WIRE_/*hw*/
   //sccb_write(addr, 0x12);
	temp1=sccb_read(addr);
	temp2=sccb_read((addr+1));
	data=(temp1<<4)|(temp2>>4);
	#endif   
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
   
   #ifdef _TP_SW_2WIRE_/*sw*/   
   MS_START_TRANSMISSION();
	motion_sensor_send_byte(MOTION_SENSOR_ADDRESS|MOTION_SENSOR_WRITE);/*0x32*/
	motion_sensor_send_byte(addr);
	motion_sensor_send_byte(data);
	MS_STOP_TRANSMISSION();	
   #endif	
   #ifdef _TP_HW_2WIRE_/*hw*/
	sccb_multi_write(addr, (kal_uint32 *)&data, 1);		
	#endif   
}

#endif







