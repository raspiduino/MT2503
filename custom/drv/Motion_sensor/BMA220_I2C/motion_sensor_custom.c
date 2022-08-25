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
#include "motion_sensor.h"
#include "motion_sensor_custom.h"
#include "us_timer.h"


/******************************************
	customizaton data
*******************************************/
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

/*motion sensor pwr on flag*/
volatile kal_bool g_ms_is_power_on = KAL_TRUE;

/*motion sensor cord mapping define*/
/******************************************
XY_MIRROR_MAPPING 	for x cord and y cord mirror mapping
XY_90_MAPPING		for x cord and y cord clockwise 90 mapping
XY_180_MAPPING		for x cord and y cord clockwise 180 mapping
XY_270_MAPPING		for x cord and y cord clockwise 270 mapping
******************************************/
#define XY_MIRROR_MAPPING
#define Y_MINUS_MAPPING

/******************************************
	Debug API for motion sensor
*******************************************/
//#define DBG_MOTION_SENSOR


#ifdef DBG_MOTION_SENSOR
#define ms_dbg_print kal_prompt_trace
#define ms_dbg_print_ps dbg_print
#else
#define ms_dbg_print(...)
#define ms_dbg_print_ps(...)
#endif

/***************************************************/
/*			software I2C APIs for motion sensor 				  */
/*=================================================*/	
/***************************************************/

/******************************************
	us delay for software I2C
	uint:us
*******************************************/
void SW_i2c_udelay(kal_uint32 delay)
{
	kal_uint32 ust = 0; //ust_get_current_time
	kal_uint32 count = 0;
	kal_uint32 break_count = 0;
	
	ust = ust_get_current_time();
	do{
		if(ust_get_current_time() != ust)
			count++;
		else
			break_count++;
	}while((count < delay) && (break_count < 0xFFFFFF));
}
/******************************************
	software I2C start bit
*******************************************/
void SW_i2c_start(void)
{
	MS_CLK_PIN_GPIO_MODE;
	MS_I2C_CLK_OUTPUT;

	MS_DATA_PIN_GPIO_MODE;
	MS_I2C_DATA_OUTPUT;
	
	MS_I2C_DATA_HIGH;
	MS_I2C_CLK_HIGH;
	SW_i2c_udelay(40);		//20
	MS_I2C_DATA_LOW;
	SW_i2c_udelay(20);		//10
	MS_I2C_CLK_LOW;
	SW_i2c_udelay(20);		//10
}

/******************************************
	software I2C stop bit
*******************************************/
void SW_i2c_stop(void)
{
	MS_I2C_CLK_OUTPUT;
	MS_I2C_DATA_OUTPUT;
	
	SW_i2c_udelay(20);		//10
	MS_I2C_CLK_HIGH;
	SW_i2c_udelay(20);		//10
	MS_I2C_DATA_HIGH;
}

/******************************************
	software I2C one clock
*******************************************/
void SW_i2c_one_clk(void)
{
	SW_i2c_udelay(10);		//5
	MS_I2C_CLK_HIGH;
	SW_i2c_udelay(20);		//10
	MS_I2C_CLK_LOW;
	SW_i2c_udelay(10);		//5
}

/******************************************
	software I2C read byte with ack
*******************************************/
kal_uint8 ms_ReadByteAck(void)
{
	kal_int8 i;
	kal_uint8 data;

	MS_I2C_DATA_INPUT; 
	data = 0; 
	
	for (i=7; i>=0; i--) 
	{
		if (MS_I2C_GET_BIT)
		{
			data |= (0x01<<i);
		}
		SW_i2c_one_clk();
	}			                                

	MS_I2C_DATA_OUTPUT;                    
	MS_I2C_DATA_LOW;                       
	SW_i2c_one_clk();                         

	return data;
}

/******************************************
	software I2C read byte without ack
*******************************************/
kal_uint8 ms_ReadByteNAck(void)
{
	kal_int8 i;
	kal_uint8 data;

	MS_I2C_DATA_INPUT; 
	data = 0; 
	
	for (i=7; i>=0; i--) 
	{
		if (MS_I2C_GET_BIT)
		{
			data |= (0x01<<i);
		}
		SW_i2c_one_clk();
	}			                                

	MS_I2C_DATA_OUTPUT;                                           
	MS_I2C_DATA_HIGH;
	SW_i2c_one_clk();                         
	
	return data;
}

/******************************************
	software I2C send byte
*******************************************/
void ms_SendByte(kal_uint8 sData) 
{
	kal_int8 i;
	
	for (i=7; i>=0; i--) 
	{            
		if ((sData>>i)&0x01) 
		{               
			MS_I2C_DATA_HIGH;	              
		} 
		else 
		{ 
			MS_I2C_DATA_LOW;                  
		}
		SW_i2c_one_clk();                        
	}		
}
/******************************************
	software I2C check ack bit
*******************************************/
kal_bool ms_ChkAck(void)
{
	MS_I2C_DATA_INPUT;
	SW_i2c_udelay(10);		//5
	MS_I2C_CLK_HIGH;
	SW_i2c_udelay(10);		//5

	if(MS_I2C_GET_BIT)		//Non-ack
	{
		SW_i2c_udelay(10);	//5
		MS_I2C_CLK_LOW;
		SW_i2c_udelay(10);	//5
		MS_I2C_DATA_OUTPUT;
		MS_I2C_DATA_LOW;
		
		return KAL_FALSE;
	}
	else					//Ack
	{
		SW_i2c_udelay(10);	//5
		MS_I2C_CLK_LOW;
		SW_i2c_udelay(10);	//5
		MS_I2C_DATA_OUTPUT;
		MS_I2C_DATA_LOW;

		return KAL_TRUE;
	}
}

/******************************************
	software I2C restart bit
*******************************************/
void ms_Restart(void)
{
	MS_I2C_CLK_OUTPUT;
	MS_I2C_DATA_OUTPUT;

	SW_i2c_udelay(40);
	MS_I2C_DATA_HIGH;
	SW_i2c_udelay(20);		//10
	MS_I2C_CLK_HIGH;
	SW_i2c_udelay(40);
	MS_I2C_DATA_LOW;
	SW_i2c_udelay(20);		//10
	MS_I2C_CLK_LOW;
	SW_i2c_udelay(20);		//10
}



/***************************************************/
/*			motion sensor read and write APIs 				  */
/*=================================================*/
/***************************************************/
/******************************************
	BMA220 ms delay function
		uint: ms
*******************************************/
void BMA220_DelayMS(kal_uint16 delay)
{
	kal_uint16 i=0;

	for(i=0; i<delay; i++)
	{
		SW_i2c_udelay(1000);
	}
}

/******************************************
	BMA220 read bytes
*******************************************/
kal_bool BMA220_ReadBytes(kal_uint8* Data, kal_uint8 RegAddr)
{
	SW_i2c_start();						//start bit
	ms_SendByte(MS_SLAVEADDR_W);		//slave address|write bit
	if(KAL_FALSE == ms_ChkAck())		//check Ack bit
	{
		//TO_DO: display ack check fail when send write id		
		ms_dbg_print(MOD_AUX, "ack fail when send wid in readbytes");
		ms_dbg_print_ps("ack fail when send wid in readbytes\n\r");
		SW_i2c_stop();
		return KAL_FALSE;
	}
		
	ms_SendByte(RegAddr);				//send RegAddr
	if(KAL_FALSE == ms_ChkAck())		//check Ack bit
	{
		//TO_DO: display ack check fail when send RegAddr
		ms_dbg_print(MOD_AUX, "ack fail when send Reg in readbytes");
		ms_dbg_print_ps("ack fail when send Reg in readbytes\n\r");
		SW_i2c_stop();
		return KAL_FALSE;
	}

	ms_Restart();						//restart bit

	ms_SendByte(MS_SLAVEADDR_R);		//slave address|read bit
	if(KAL_FALSE == ms_ChkAck())
	{
		//TO_DO: display ack check fail when send read id		
		ms_dbg_print(MOD_AUX, "ack fail when send rid in readbytes");
		ms_dbg_print_ps("ack fail when send rid in readbytes\n\r");
		SW_i2c_stop();
		return KAL_FALSE;
	}

	*Data = ms_ReadByteNAck();

	SW_i2c_stop();						//stop bit

	//TO_DO: add debug code to display the data received

	return KAL_TRUE;
	
}

/******************************************
	BMA220 contunious read bytes
*******************************************/
kal_bool BMA220_ConReadBytes(kal_uint8* Data, kal_uint8 RegAddr, kal_uint16 Length)
{
	kal_uint8* Data_ptr;
	kal_uint16 i;

	Data_ptr = Data;
	
	SW_i2c_start();						//start bit
	ms_SendByte(MS_SLAVEADDR_W);		//slave address|write bit
	if(KAL_FALSE == ms_ChkAck())		//check Ack bit
	{
		//TO_DO: display ack check fail when send write id		
		ms_dbg_print(MOD_AUX, "ack fail when send wid in conread");
		ms_dbg_print_ps("ack fail when send wid in conread\n\r");
		SW_i2c_stop();
		return KAL_FALSE;
	}
		
	ms_SendByte(RegAddr);				//send RegAddr
	if(KAL_FALSE == ms_ChkAck())		//check Ack bit
	{
		//TO_DO: display ack check fail when send RegAddr		
		ms_dbg_print(MOD_AUX, "ack fail when send Reg in conread");
		ms_dbg_print_ps("ack fail when send Reg in conread\n\r");
		SW_i2c_stop();
		return KAL_FALSE;
	}

	ms_Restart();						//restart bit

	ms_SendByte(MS_SLAVEADDR_R);		//slave address|read bit
	if(KAL_FALSE == ms_ChkAck())
	{
		//TO_DO: display ack check fail when send read id		
		ms_dbg_print(MOD_AUX, "ack fail when send rid in conread");
		ms_dbg_print_ps("ack fail when send rid in conread\n\r");
		SW_i2c_stop();
		return KAL_FALSE;
	}

	for(i=Length; i>1; i--)
	{
		*Data_ptr = ms_ReadByteAck();	//read byte with ack
		Data_ptr++;
	}
	
	*Data_ptr = ms_ReadByteNAck();		//read byte with non-ack to stop reading

	SW_i2c_stop();						//stop bit

	//TO_DO: add debug code to display the data received

	return KAL_TRUE;
}

/******************************************
	BMA220 write bytes
*******************************************/
kal_bool BMA220_WriteBytes(kal_uint8 RegAddr, kal_uint8 Data)
{
	SW_i2c_start();						//start bit

	ms_SendByte(MS_SLAVEADDR_W);		//slave address|write bit
	if(KAL_FALSE == ms_ChkAck())		//check Ack bit
	{
		//TO_DO: display check ack fail when send write id
		ms_dbg_print(MOD_AUX, "ack fail when send wid in writebytes");		
		ms_dbg_print_ps("ack fail when send wid in writebytes\n\r");
		SW_i2c_stop();
		return KAL_FALSE;
	}

	ms_SendByte(RegAddr);				//send RegAddr
	if(KAL_FALSE == ms_ChkAck())		//check Ack bit
	{
		//TO_DO: display check ack fail when send RegAddr
		ms_dbg_print(MOD_AUX, "ack fail when send Reg in wirtebytes");
		ms_dbg_print_ps("ack fail when send Reg in wirtebytes\n\r");
		SW_i2c_stop();
		return KAL_FALSE;
	}

	ms_SendByte(Data);					//send parameter
	if(KAL_FALSE == ms_ChkAck())
	{
		//TO_DO: display check ack fail when send data
		ms_dbg_print(MOD_AUX, "ack fail when send para in writebytes");
		ms_dbg_print_ps("ack fail when send para in writebytes\n\r");
		SW_i2c_stop();
		return KAL_FALSE;
	}

	SW_i2c_stop();						//stop bit

	return KAL_TRUE;
}


/***************************************************/
/*		    BMA220 motion sensor driver APIs   	 			  */
/*=================================================*/
/***************************************************/

/******************************************
	motion sensor power control function
[parameters]:
	TRUE 	power on
	FALSE	power off
*******************************************/
kal_bool BMA220_power_ctrl(kal_bool ON)
{
	kal_bool temp_result = KAL_FALSE;
	kal_uint8 temp = 1;
	
	if(ON !=g_ms_is_power_on)
	{
		temp_result = BMA220_ReadBytes(&temp ,MS_SUSPEND_REG);
		BMA220_DelayMS(1);

		if(KAL_FALSE == temp_result)
		{
			ms_dbg_print(MOD_AUX, "Motion Sensor power on fail!");
			ms_dbg_print_ps("Motion Sensor power on fail!\n\r");
			return KAL_FALSE;
		}

		ms_dbg_print_ps("Motion Sensor status has changed!\n\r");
		
		if(0x00 == temp)
		{
			ms_dbg_print_ps("Motion Sensor in suspend mode!\n\r");
		}

		if(0xff == temp)
		{
			ms_dbg_print_ps("Motion Sensor in normal!\n\r");
		}
	}
	
	g_ms_is_power_on = ON;
		
	ms_dbg_print(MOD_AUX, "Motion Sensor power ctrl:%d succeed!", ON);
	ms_dbg_print_ps("Motion Sensor power ctrl:%d succeed!\n\r", ON);
	
	return KAL_TRUE;
}

/******************************************
	motion sensor get power status function
	Power on return KAL_TRUE
	Power off return KAL_FALSE
*******************************************/
kal_bool BMA220_power_status(void)
{
	return g_ms_is_power_on;
}

/******************************************
	motion sensor set range function
[parameters]:
	BMA220_RANGE_2G		+/-2g
 	BMA220_RANGE_4G		+/-4g
	BMA220_RANGE_8G		+/-8g
	BMA220_RANGE_16G        	+/-16g	
*******************************************/
kal_bool BMA220_SetRange(kal_uint8 BMA220Range)
{
	kal_bool temp_result = KAL_FALSE;
	
	if(BMA220Range > BMA220_RANGE_16G)
	{
		ASSERT(0);
	}
	
	temp_result = BMA220_WriteBytes(MS_RANGE_REG ,BMA220Range);

	if(KAL_FALSE == temp_result)
	{
		ms_dbg_print_ps("BMA220 set range:%x fail!\n\r", BMA220Range);
		return KAL_FALSE;
	}
	else
	{
		ms_dbg_print_ps("BMA220 set range:%x succeed!\n\r", BMA220Range);
		return KAL_TRUE;
	}
}
/******************************************
	motion sensor get range function
*******************************************/
kal_bool BMA220_GetRange(kal_uint8* BMA220Range)
{
	kal_bool temp_result = KAL_FALSE;

	temp_result = BMA220_ReadBytes(BMA220Range, MS_RANGE_REG);

	if(KAL_FALSE == temp_result)
	{
		ms_dbg_print_ps("BMA220 get range fail!\n\r");
		return KAL_FALSE;
	}
	else
	{
		ms_dbg_print_ps("BMA220 get range succeed!\n\r");
		return KAL_TRUE;
	}
}

/******************************************
	motion sensor read ID function
*******************************************/
void BMA220_ReadID(void)
{
	kal_uint8 ID_data[2] = {0};
	kal_bool temp_result = KAL_FALSE;
	
	temp_result = BMA220_ConReadBytes(ID_data, MS_CHIP_ID, 2);

	if(KAL_FALSE == temp_result)
	{
		ms_dbg_print(MOD_AUX, "Motion Sensor read id fail");
		ms_dbg_print_ps("Motion Sensor read id fail\n\r");
	}
	else
	{
		ms_dbg_print(MOD_AUX, "CHIP_ID:%d, VERSION_ID:%d", ID_data[0], ID_data[1]);
		ms_dbg_print_ps("CHIP_ID:%x, VERSION_ID:%x \n\r", ID_data[0], ID_data[1]);
	}
}

/******************************************
	motion sensor softreset function
*******************************************/
kal_bool BMA220_SWReset(void)
{
	kal_bool temp_result = KAL_FALSE;
	kal_uint8 temp = 0;

	temp_result = BMA220_ReadBytes(&temp , MS_SWRST_REG);
	BMA220_DelayMS(5);		//ensure delay more than 2ms

	temp_result = BMA220_ReadBytes(&temp , MS_SWRST_REG);
	
	if(KAL_FALSE == temp_result)
	{
		ms_dbg_print_ps("Motion sensor soft reset fail!\n\r");
		return KAL_FALSE;
	}
	else
	{
		ms_dbg_print_ps("Motion sensor soft reset succeed!\n\r");
		return KAL_TRUE;
	}

	BMA220_DelayMS(5);		//ensure delay more than 2ms
}

/******************************************
	motion sensor init function
*******************************************/
void BMA220_init(void)
{
	kal_bool pwr_result = KAL_FALSE;
	kal_bool reset_result = KAL_FALSE;
	kal_bool init_result = KAL_FALSE;
	
	ms_dbg_print_ps("in BMA220_init\r\n");

	//Init sck&data pin	
	MS_CLK_PIN_GPIO_MODE;
	MS_I2C_CLK_OUTPUT;
	MS_I2C_CLK_HIGH;

	MS_DATA_PIN_GPIO_MODE;
	MS_I2C_DATA_OUTPUT;
	MS_I2C_DATA_HIGH;

	//do soft reset to ensure all register are default value
	reset_result = BMA220_SWReset();
	
	if(KAL_FALSE == reset_result)
	{
		ms_dbg_print_ps("Motion Sensor soft reset fail!\n\r");
	}

	//motion sensor power up
	pwr_result = BMA220_power_ctrl(KAL_TRUE);

	if(KAL_FALSE == pwr_result)
	{
		ms_dbg_print(MOD_AUX, "Motion Sensor init power on fail!");
		ms_dbg_print_ps("Motion Sensor init power on fail!\n\r");
	}

	//set range value
	init_result = BMA220_SetRange(BMA220_RANGE_2G);

	if(KAL_FALSE == pwr_result||KAL_FALSE == init_result||KAL_FALSE == reset_result)
	{
		ms_dbg_print_ps("Motion Sensor init fail!\n\r");
	}
	else
	{
		ms_dbg_print_ps("Motion Sensor init succeed!\n\r");
	}
}

/******************************************
	motion sensor power up function
*******************************************/
void BMA220_pwr_up(void)
{
	kal_bool pwr_result = KAL_FALSE;
	kal_bool is_power_on = KAL_FALSE;

	dbg_print("BMA220_pwr_up\n\r");

	is_power_on = BMA220_power_status();

	if(KAL_FALSE == is_power_on)
	{
		pwr_result = BMA220_power_ctrl(KAL_TRUE);
	
		if(KAL_FALSE == pwr_result)
		{
			ms_dbg_print(MOD_AUX, "Motion Sensor power up fail!");			
			ms_dbg_print_ps("Motion Sensor power up fail!\n\r");
		}
		else
		{
			ms_dbg_print_ps("Motion Sensor power up succeed!\n\r");
		}
	}
	
	BMA220_ReadID();
}

/******************************************
	motion sensor power down function
*******************************************/
void BMA220_pwr_down(void)
{
	kal_bool pwr_result = KAL_FALSE;
	kal_bool is_power_on = KAL_FALSE;
	
	dbg_print("BMA220_pwr_down\n\r");

	BMA220_ReadID();
	
	is_power_on = BMA220_power_status();

	if(KAL_TRUE == is_power_on)
	{
		pwr_result = BMA220_power_ctrl(KAL_FALSE);
	
		if(KAL_FALSE == pwr_result)
		{
			ms_dbg_print(MOD_AUX, "Motion Sensor power down fail!");
			ms_dbg_print_ps("Motion Sensor power down fail!\n\r");
		}
		else
		{
			ms_dbg_print_ps("Motion Sensor power down succeed!\n\r");
		}
	}
}

/******************************************
	motion sensor read x,y,z acc function
*******************************************/
void BMA220_ReadXYZ(kal_uint16 *X, kal_uint16 *Y, kal_uint16 *Z)  
{
	//Read 3 continous bytes of X, Y and Z 6-bit data
	kal_uint8 XYZdata[3] = {0};
	kal_uint8 temp_data;
	kal_bool temp_result = KAL_FALSE;

	temp_result = BMA220_ConReadBytes(XYZdata, MS_ACC_REG, 3);

	if(KAL_FALSE == temp_result)
	{
		ms_dbg_print_ps("Motion Sensor get data fail!\n\r");
	}
	else
	{
		ms_dbg_print_ps("Acc_x:%d, Acc_y:%d, Acc_z:%d \n\r", XYZdata[0]>>2, XYZdata[1]>>2, XYZdata[2]>>2);

	#if defined(XY_MIRROR_MAPPING)
		temp_data = XYZdata[0];
		XYZdata[0] = XYZdata[1];
		XYZdata[1] = temp_data;
		#if defined(Y_MINUS_MAPPING)
		XYZdata[1] = (64 - (XYZdata[1]>>2))<<2;
		#endif
	#elif defined(XY_90_MAPPING)

	#elif defined(XY_180_MAPPING)

	#elif defined(XY_270_MAPPING)

	#endif

		ms_dbg_print_ps("before Acc_x:%d, Acc_y:%d, Acc_z:%d \n\r", XYZdata[0]>>2, XYZdata[1]>>2, XYZdata[2]>>2);

		if(XYZdata[0]&0x80)
		{
			*X = ACC_0G_X - ((64-(XYZdata[0]>>2))<<6);
		}
		else
		{
			*X = ACC_0G_X + ((XYZdata[0]>>2)<<6);
		}

		if(XYZdata[1]&0x80)
		{
			*Y = ACC_0G_Y - ((64-(XYZdata[1]>>2))<<6);
		}
		else
		{
			*Y = ACC_0G_Y + ((XYZdata[1]>>2)<<6);
		}
		
		if(XYZdata[2]&0x80)
		{
			*Z = ACC_0G_Z - ((64-(XYZdata[2]>>2))<<6);
		}
		else
		{
			*Z = ACC_0G_Z + ((XYZdata[2]>>2)<<6);
		}

		ms_dbg_print_ps("After Acc_x:%d, Acc_y:%d, Acc_z:%d \n\r", *X, *Y, *Z);
	}
}

/*return sensor support gesture*/
kal_bool BMA220_query_gesture(kal_uint16 ms_gest_type)
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

kal_bool BMA220_get_sensor_params(kal_uint16 ms_params_type, MotionSensorQueryStruct *ms_params)
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

MotionSensor_custom_data_struct* BMA220_get_data(void) 
{
   return (&ms_custom_data_def);
}

/*******************************************
	customizaton function pointer
********************************************/
MotionSensor_customize_function_struct ms_custom_func=
{
	BMA220_get_data,
    BMA220_ReadXYZ,
    BMA220_init,
    BMA220_pwr_up,
	BMA220_pwr_down,
	 NULL,//mma_sensor_read_int_status,
	 NULL,//mma_sensor_clear_int_status,
	 NULL,//mma_sensor_configure_low_g,
	 NULL,//mma_sensor_configure_high_g   
	 BMA220_query_gesture,
     BMA220_get_sensor_params,
     NULL
};
MotionSensor_customize_function_struct *ms_GetFunc(void)
{
   return (&ms_custom_func);  
}

#endif
