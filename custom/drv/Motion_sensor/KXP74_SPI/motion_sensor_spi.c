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
#include    "motion_sensor_hw_define.h"
#include    "motion_sensor_spi.h"
     
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
*	motion_sensor_write_bit_high
*
* DESCRIPTION
*	This function is to set a bit as high.
*
* PARAMETERS
*  None
* RETURNS
*	None    
*
* GLOBALS AFFECTED
*
*************************************************************************/
/*write 1*/
void motion_sensor_write_bit_high(void)
{
   SET_MS_DATA_HIGH();         /*    ----              */
   SET_MS_CLK_LOW();           /*     _-_             */
   //motion_sensor_delay(100);
   SET_MS_CLK_HIGH();
   //motion_sensor_delay(100);
   SET_MS_CLK_LOW();
}
/*************************************************************************
* FUNCTION
*	motion_sensor_write_bit_low
*
* DESCRIPTION
*	This function is to set a bit as low.
*
* PARAMETERS
*  None
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
/*write 0*/
void motion_sensor_write_bit_low(void)
{
   SET_MS_DATA_LOW();          /*    ____              */
   SET_MS_CLK_LOW();           /*     _-_             */
   //motion_sensor_delay(100);
   SET_MS_CLK_HIGH();
   //motion_sensor_delay(100);
   SET_MS_CLK_LOW();
}
/*************************************************************************
* FUNCTION
*	motion_sensor_read_data
*
* DESCRIPTION
*	This function is to read data(12bits) via SPI.
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
kal_uint16 motion_sensor_read_data(void)
{ 
   kal_uint16 data=0; 
   kal_int16    i;           
      
   SET_MS_CLK_LOW();
   SET_MS_CLK_HIGH();   
   motion_sensor_delay(10);   
   for(i=11;i>=0;i--)
   {      
      SET_MS_CLK_HIGH();
      //motion_sensor_delay(100);
		if(GET_MS_DATA_BIT())
			data |= (1<<i); 

		SET_MS_CLK_LOW();
		//motion_sensor_delay(100);
   }   
   data&=0x0fff;   
   return data;
} 
/*************************************************************************
* FUNCTION
*	motion_sensor_read_control
*
* DESCRIPTION
*	This function is to read data(8bits) via SPI.
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
kal_uint16 motion_sensor_read_control(void)
{
   kal_uint16 data=0; 
   kal_int16    i;           
    
   SET_MS_CLK_LOW();
   SET_MS_CLK_HIGH();  
      
   for(i=7;i>=0;i--)
   {      
      SET_MS_CLK_HIGH();
      //motion_sensor_delay(100);
		if(GET_MS_DATA_BIT())
			data |= (1<<i); 

		SET_MS_CLK_LOW();
		//motion_sensor_delay(100);
   }   
   data&=0x0fff;  
   return data;
}   
/*************************************************************************
* FUNCTION
*	motion_sensor_write_data
*
* DESCRIPTION
*	This function is to write data via SPI.
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
void motion_sensor_write_data(kal_uint8 data)
{
   kal_int8 i;   

	for (i=7;i>=0;i--)
	{	/* data bit 7~0 */
		if (data & (1<<i))
		{
		   motion_sensor_write_bit_high();
		}
		else
		{
			motion_sensor_write_bit_low();
		}
	}	
}

#endif







