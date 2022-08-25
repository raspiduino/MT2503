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
#include "motion_sensor_hw_define.h"
#include "motion_sensor_custom.h"
 
/*customizaton function pointer*/
MotionSensor_customize_function_struct ms_custom_func=
{
     ms_get_data,
     mma745x_ReadXYZ10,
     mma745x_init,
     acc_sensor_pwr_up,
     acc_sensor_pwr_down,
     NULL,//mma_sensor_read_int_status,
	 NULL,//mma_sensor_clear_int_status,
	 NULL,//mma_sensor_configure_low_g,
	 NULL,//mma_sensor_configure_high_g   
	 mma745_query_gesture,
     mma745_get_sensor_params,
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

extern prompt_trace(kal_int16 mode, kal_uint8 *text);		//Debug mode dump trace code

// address 1d
#define MMA745xL_AddW 0x3a
#define MMA745xL_AddR 0x3b

// address 1c
//kal_uint8 MMA745xL_AddW = 0x38;
//kal_uint8 MMA745xL_AddR = 0x39;

/*
#define Delay20us 585              //Loop times to delay 20uS (Need to change according to system clock)
#define Delay10us 292              //Loop times to delay 10uS (Need to change according to system clock)
#define Delay5us  145              //Loop times to delay 5uS (Need to change according to system clock)
*/

#define Delay20us 292              //Loop times to delay 10uS (Need to change according to system clock)
#define Delay10us 145              //Loop times to delay 5uS (Need to change according to system clock)
#define Delay5us  72              //Loop times to delay 2.5uS (Need to change according to system clock)

#define CalibrationTimes 3

void Calibration_XYZ(void){
  SPARAMETERS gValue;
  kal_int8 temp, i;
  kal_uint16 temp1, temp2, temp3;
  
  temp = mma745x_IICRead(MCTL);
  
  mma745x_IICWrite(MCTL, 0x45);

  for(i=0;i<CalibrationTimes;i++)
  {
    Sample_n_Times(8, &gValue.X, &gValue.Y, &gValue.Z);

    gValue.X *= -2;
    temp1 = mma745x_IICRead(XOFFH);
    temp2 = mma745x_IICRead(XOFFL);
    temp3 = (kal_int16)(((kal_uint16)(temp1<<8))+(kal_uint16)(temp2));
    gValue.X += temp3;
    mma745x_IICWrite(XOFFL, (kal_uint8)(gValue.X));
    mma745x_IICWrite(XOFFH, (kal_uint8)(gValue.X>>8));

    gValue.Y *= -2;
    temp1 = mma745x_IICRead(YOFFH);
    temp2 = mma745x_IICRead(YOFFL);
    temp3 = (kal_int16)(((kal_uint16)(temp1<<8))+(kal_uint16)(temp2));
    gValue.Y += temp3;
    mma745x_IICWrite(YOFFL, (kal_uint8)(gValue.Y));
    mma745x_IICWrite(YOFFH, (kal_uint8)(gValue.Y>>8));

    gValue.Z -= 63; 
    gValue.Z *= -2;
    temp1 = mma745x_IICRead(ZOFFH);
    temp2 = mma745x_IICRead(ZOFFL);
    temp3 = (kal_int16)(((kal_uint16)(temp1<<8))+(kal_uint16)(temp2));
    gValue.Z += temp3;
    mma745x_IICWrite(ZOFFL, (kal_uint8)(gValue.Z));
    mma745x_IICWrite(ZOFFH, (kal_uint8)(gValue.Z>>8));
  }
  mma745x_IICWrite(MCTL, temp);
}

void Sample_n_Times(kal_uint8 n, kal_uint16 *pX, kal_uint16 *pY, kal_uint16 *pZ) {
    kal_uint8 i;
    kal_uint16 TmpX, TmpY, TmpZ;
    *pX=0; *pY=0; *pZ=0;
    for (i=0;i<n;i++)
    {
      while(!Data_Is_Ready());
      mma745x_ReadXYZ10(&TmpX, &TmpY, &TmpZ);
      *pX += TmpX;   
      *pY += TmpY;   
      *pZ += TmpZ;   
    }
    *pX /= n;
    *pY /= n;
    *pZ /= n;
}


kal_uint8 Data_Is_Ready(void){
  if(mma745x_IICRead(STATUS)&0x01) return 1;
  return 0;
}

void mma745x_init() {                     //MMA7455 Initialize
	GPIO_ModeSetup(ACC_SENSOR_SCK, 0x00);   //Set I2C CLK pin as GPIO   
	SET_I2C_CLK_OUTPUT;                     //Set I2C CLK pin as output
	SET_I2C_CLK_HIGH;                       //I2C CLK pin output high(1)

	GPIO_ModeSetup(ACC_SENSOR_SDA, 0x00);   //Set I2C DATA pin as GPIO
	SET_I2C_DATA_OUTPUT;                    //Set I2C DATA pin as output
	SET_I2C_DATA_HIGH;                      //I2C DATA pin output high(1)

	acc_sensor_pwr_down();
}

void mma_delay(kal_uint16 time) {             //Time delay function
	kal_uint16 i;
	for (i=0; i<time; i++) ;                //Software loop for time delay
}

void IIC_Start(void) {                    //I2C Start signal generation: Data pin falls down when clock is high
	GPIO_ModeSetup(ACC_SENSOR_SCK, 0x00);   //Set I2C CLK pin as GPIO
	SET_I2C_CLK_OUTPUT;                     //Set I2C CLK pin as output
	GPIO_ModeSetup(ACC_SENSOR_SDA, 0x00);   //Set I2C DATA pin as GPIO
	SET_I2C_DATA_OUTPUT;                    //Set I2C DATA pin as output

	SET_I2C_DATA_HIGH;	                    //I2C DATA pin output high(1)
	SET_I2C_CLK_HIGH;		                    //I2C CLK pin output high(1)
	mma_delay(Delay20us);                   //Delay 20uS
	SET_I2C_DATA_LOW;                       //I2C DATA pin output low(0)
	mma_delay(Delay10us);                   //Delay 10uS
	SET_I2C_CLK_LOW;                        //I2C CLK pin output low(0)
	mma_delay(Delay10us);                   //Delay 10uS
}

void IIC_Stop (void) {                    //I2C Stop signal generation: Data pin rises up when clock in is high
	mma_delay(Delay10us);                   //Delay 10uS
	SET_I2C_CLK_HIGH;		                    //I2C CLK pin output high(1)
	mma_delay(Delay10us);                   //Delay 10uS
	SET_I2C_DATA_HIGH;	                    //I2C DATA pin output high(1)
}

void IIC_RepeatedStart(void) {            //I2C Repeat Start signal generation: Data pin falls down when clock is high
	mma_delay(Delay20us);                   //Delay 20uS
	mma_delay(Delay20us);                   //Delay 20uS
	SET_I2C_DATA_HIGH;	                    //I2C DATA pin output high(1)
	mma_delay(Delay10us);                   //Delay 10uS
	SET_I2C_CLK_HIGH;		                    //I2C CLK pin output high(1)
	mma_delay(Delay20us);                   //Delay 20uS
	mma_delay(Delay20us);                   //Delay 20uS
	SET_I2C_DATA_LOW;                       //I2C DATA pin output low(0)
	mma_delay(Delay10us);                   //Delay 10uS
	SET_I2C_CLK_LOW;                        //I2C CLK pin output low(0)
	mma_delay(Delay10us);                   //Delay 10uS	
}

void IIC_OneClk(void) {                   //I2C CLK pin output one clock: CLK pin rises up before falls down
	mma_delay(Delay5us);
	SET_I2C_CLK_HIGH;		                    //I2C CLK pin output high(1)		
	mma_delay(Delay10us);                   //Delay 10uS
	SET_I2C_CLK_LOW;                        //I2C CLK pin output low(0)
	mma_delay(Delay5us);	
}

void IIC_SendByte(kal_uint8 sData) {         //I2C send one byte out
	kal_int8 i;
	for (i=7; i>=0; i--) {                  //Loop 8 times to send 8 bits
		if ((sData>>i)&0x01) {                //Judge output 1 or 0
			SET_I2C_DATA_HIGH;	                //I2C DATA pin output high(1) if output 1
		} else { 
			SET_I2C_DATA_LOW;                   //I2C DATA pin output low(0) if output 0
			}
		IIC_OneClk();                         //Output one clock pulse after data pin is ready
	}		
}

kal_uint8  IIC_ChkAck(void) {                //Check I2C Acknowledgement signal
	SET_I2C_DATA_INPUT;                     //Set I2C DATA pin as input
	mma_delay(Delay5us);                    //Delay 5uS
	SET_I2C_CLK_HIGH;		                    //I2C CLK pin output high(1)		
	mma_delay(Delay5us);                    //Delay 5uS again
	if (GET_I2C_DATA_BIT) {                 //Read I2C DATA pin
		mma_delay(Delay5us);                  //Delay 5uS
		SET_I2C_CLK_LOW;                      //I2C CLK pin output low(0)
		mma_delay(Delay5us);                  //Delay 5us again
		SET_I2C_DATA_OUTPUT;                  //Set I2C DATA pin as output
		SET_I2C_DATA_LOW;                     //I2C DATA pin output low(0)
		return 1;                             //Return 1 if read 1 from I2C DATA pin
		} else {                              //If I2C DATA pin is invalid for acknowledgement signal
		mma_delay(Delay5us);                  //Delay 5uS
		SET_I2C_CLK_LOW;                      //I2C CLK pin output low(0)
		mma_delay(Delay5us);                  //Delay 5uS again
		SET_I2C_DATA_OUTPUT;                  //Set I2C DATA pin as output
		SET_I2C_DATA_LOW;                     //I2C DATA pin output low(0)
		return 0;                             //Return 0 if read 0 from I2C DATA pin
		}			
}

kal_uint8 IIC_ReadByteACK(void) {            //Read one byte and send an acknowledgement signal
	kal_int8 i;
	kal_uint8 data;

	SET_I2C_DATA_INPUT;                     //Set I2C DATA pin as input
	data = 0;                               //Prepare to receive data
	for (i=7; i>=0; i--) {                  //Loop 8 times to receive 8 bits
		if (GET_I2C_DATA_BIT) data |= (0x01<<i);    //If read a 1, set to data bit
		IIC_OneClk();
		}			                                //Output one clock pulse after a bit is read

	SET_I2C_DATA_OUTPUT;                    //Set I2C DATA pin as output
	SET_I2C_DATA_LOW;                       //I2C DATA pin output low(0): the acknowledgement signal
	IIC_OneClk();                           //Output one clock pulse after data pin is ready

	return data;                            //Return eceived data
}

kal_uint8 IIC_ReadByteNCK(void) {            //Read one byte but do not send acknowledgement signal
	kal_int8 i;
	kal_uint8 data;

	SET_I2C_DATA_INPUT;                     //Set I2C DATA pin as input
	data = 0;                               //Prepare to receive data
	for (i=7; i>=0; i--) {                  //Loop 8 times to receive 8 bits
		if (GET_I2C_DATA_BIT) data |= (0x01<<i);    //If read a 1, set to data bit
		IIC_OneClk();
		}			                                //Output one clock pulse after a bit is read

	SET_I2C_DATA_OUTPUT;                    //Set I2C DATA pin as output
	SET_I2C_DATA_HIGH;	                    //I2C DATA pin output high(1): no acknowledge
	IIC_OneClk();                           //Output one clock pulse after data pin is ready
	SET_I2C_DATA_LOW;                       //I2C DATA pin output low(0)

	return data;                            //Return received data
}


// Master Write
void mma745x_IICWrite(kal_uint8 RegAdd, kal_uint8 Data) {   //Write one byte to a MMA7455 register via I2C
	//Start
	IIC_Start();                                        //Output a START signal

	// Device hardware address
	IIC_SendByte(MMA745xL_AddW);                        //Send one byte of MMA7455 address for writing
	if (IIC_ChkAck()) {                                 //Check acknowledge signal
   	#ifdef ACC_DEBUG	                                //Only for debug
		prompt_trace(MOD_MMA, "# MMA7455L Device Write Address Error #\r\n");   //Print error information
	#endif
		IIC_Stop();	                                      //Output a STOP signal
		return;                                           //If acknowledgement signal is read as 1, then return to end
		}
                                                      //If acknowledgement signal is read as 0, then go to next step
	// Register address to read                         
	IIC_SendByte(RegAdd);                               //Send one byte of register address in MMA7455
	if (IIC_ChkAck()) {                                 //Check acknowledgement signal
   	#ifdef ACC_DEBUG	                                //Only for debug
		prompt_trace(MOD_MMA, "# MMA7455L Reg Address NACK #\r\n");   //Print error information
	#endif                                              
		IIC_Stop();                                       //Output a STOP signal
		return;    	                                      //If acknowledgement signal is read as 1, then return to end
		}
                                                      //If acknowledgement signal is read as 0, then go to next step
	// Data to send
	IIC_SendByte(Data);                                 //Send one byte of data
	if (IIC_ChkAck()) {                                 //Check acknowledgement signal
   	#ifdef ACC_DEBUG	                                //Only for debug
		prompt_trace(MOD_MMA, "# MMA7455L Data NACK #\r\n");    //Print error information
	#endif
		IIC_Stop();	                                      //Output a STOP signal
		return;                                           //If acknowledgement signal is read as 1, then return to end
		}
                                                      //If acknowledgement signal is read as 0, then go to next step
	// Stop	
	IIC_Stop();	                                        //Output a STOP signal	

}

// Master Read
kal_int8 mma745x_IICRead(kal_uint8 RegAdd) {                //Read a byte from MMA7455 register via I2C
	kal_int8 Data;

	//Start
	IIC_Start();                                        //Output a START signal
                                                      
	// Device hardware address
	IIC_SendByte(MMA745xL_AddW);                        //Send a byte of MMA7455 address for writing
	if (IIC_ChkAck()) {                                 //Check acknowledge signal 
   	#ifdef ACC_DEBUG	                                //Only for debug
		prompt_trace(MOD_MMA, "# MMA7455L Device Write Address Error #\r\n");   //Print error information
	#endif
		IIC_Stop();	                                      //Output a STOP signal	
		return 0;                                         //If acknowledgement signal is read as 1, then return to end
		}
                                                      //If acknowledgement signal is read as 0, then go to next step
	// Register address to read
	IIC_SendByte(RegAdd);                               //Send one byte of register address in MMA7455
	if (IIC_ChkAck()) {                                 //Check acknowledge signal 
   	#ifdef ACC_DEBUG	                                //Only for debug
		prompt_trace(MOD_MMA, "# MMA7455L Reg Address NACK #\r\n");   //Print error information
	#endif
		IIC_Stop();	                                      //Output a STOP signal	
		return 0;                                         //If acknowledgement signal is read as 1, then return to end
		}
                                                      //If acknowledgement signal is read as 0, then go to next step
	// Repeated Start
	IIC_RepeatedStart();                                //Output a REPEAT START signal
	
	// Device hardware address                          
	IIC_SendByte(MMA745xL_AddR);                        //Send a MMA7455 address for reading
	if (IIC_ChkAck()) {                                 //Check acknowledge signal 
   	#ifdef ACC_DEBUG	                                //Only for debug
		prompt_trace(MOD_MMA, "# MMA7455L Device Read Address Error #\r\n");    //Print error information
	#endif
		}                                                 //If acknowledgement signal is read as 1, do nothing
                                                      //If acknowledgement signal is read as 0, then go to next step
	Data = IIC_ReadByteNCK();                           //Read one byte but do not output acknowledgement
   	#ifdef ACC_DEBUG	                                //Only for debug
		prompt_trace(MOD_MMA, "# MMA7455L Read Data = %d #\r\n", Data);   //Print received data
	#endif

	// Stop	
	IIC_Stop();	                                        //Output a STOP signal

	return Data;                                        //Return received data
}

// Read XYZ 8bit Registers
void mma745x_ReadXYZ8(kal_int8 *X, kal_int8 *Y, kal_int8 *Z) { //Read 3 continous bytes of X, Y and Z 8-bit data, start from address 0x06 on MMA7455
	//Start
	IIC_Start();                                        //Output a START signal

	// Device hardware address
	IIC_SendByte(MMA745xL_AddW);                        //Send a byte of MMA7455 address for writing
	if (IIC_ChkAck()) {                                 //Check acknowledge signal 
   	#ifdef ACC_DEBUG	                                //Only for debug
		prompt_trace(MOD_MMA, "# MMA7455L Device Write Address Error #\r\n");   //Print error information
	#endif
		IIC_Stop();	                                      //Output a STOP signal	
		return;                                           //If acknowledgement signal is read as 1, then return to end
		}
                                                      //If acknowledgement signal is read as 0, then go to next step
	// Register address to read
	IIC_SendByte(0x06);                                 //Send the start address to read
	if (IIC_ChkAck()) {                                 //Check acknowledge signal 
   	#ifdef ACC_DEBUG	                                //Only for debug	
		prompt_trace(MOD_MMA, "# MMA7455L Reg Address NACK #\r\n");
	#endif
		IIC_Stop();	                                      //Output a STOP signal	
		return;
		}

	// Repeated Start
	IIC_RepeatedStart();                                //Output a REPEAT START signal
	
	// Device hardware address
	IIC_SendByte(MMA745xL_AddR);                        //Send a MMA7455 address for reading
	if (IIC_ChkAck()) {                                 //Check acknowledge signal 
   	#ifdef ACC_DEBUG	                                //Only for debug	
		prompt_trace(MOD_MMA, "# MMA7455L Device Read Address Error #\r\n");
	#endif
		IIC_Stop();	                                      //Output a STOP signal	
		return;                                           //If acknowledgement signal is read as 1, then return to end
		}
                                                      //If acknowledgement signal is read as 0, then go to next step
	*X = IIC_ReadByteACK();                             //Read one byte and output an acknowledgement signal
   	#ifdef ACC_DEBUG	                                //Only for debug	
		prompt_trace(MOD_MMA, "# MMA7455L Read X Data = %d #\r\n", *X);   //Print read value of X data
	#endif

	*Y = IIC_ReadByteACK();                             //Read one byte and output an acknowledgement signal
   	#ifdef ACC_DEBUG	                                //Only for debug	
		prompt_trace(MOD_MMA, "# MMA7455L Read Y Data = %d #\r\n", *Y);   //Print read value of Y data
	#endif

	*Z = IIC_ReadByteNCK();                             //Read one byte and output an acknowledgement signal
   	#ifdef ACC_DEBUG	                                //Only for debug	
		prompt_trace(MOD_MMA, "# MMA7455L Read Z Data = %d #\r\n", *Z);   //Print read value of Z data
	#endif
	// Stop	
	IIC_Stop();	                                        //Output a STOP signal	

}

// Read XYZ 10bit Registers
void mma745x_ReadXYZ10(kal_uint16 *X, kal_uint16 *Y, kal_uint16 *Z) { //Read 6 continous bytes of X, Y and Z 10-bit data, start from address 0x00 on MMA7455
	kal_uint16 temp;
	
	//Start
	IIC_Start();                                        //Output a START signal

	// Device hardware address
	IIC_SendByte(MMA745xL_AddW);                        //Send a byte of MMA7455 address for writing
	if (IIC_ChkAck()) {                                 //Check acknowledge signal 
   	#ifdef ACC_DEBUG	                                //Only for debug	
		prompt_trace(MOD_MMA, "# MMA7455L Device Write Address Error #\r\n");
	#endif
		IIC_Stop();	                                      //Output a STOP signal	
		return;                                           //If acknowledgement signal is read as 1, then return to end
		}
                                                      //If acknowledgement signal is read as 0, then go to next step
	// Register address to read
	IIC_SendByte(0x00);                                 //Send the start address to read
	if (IIC_ChkAck()) {                                 //Check acknowledge signal 
   	#ifdef ACC_DEBUG	                                //Only for debug	
		prompt_trace(MOD_MMA, "# MMA7455L Reg Address NACK #\r\n");   //Print error information
	#endif
		IIC_Stop();	                                      //Output a STOP signal	
		return;                                           //If acknowledgement signal is read as 1, then return to end
		}
                                                      //If acknowledgement signal is read as 0, then go to next step
	// Repeated Start
	IIC_RepeatedStart();                                //Output a REPEAT START signal
	
	// Device hardware address
	IIC_SendByte(MMA745xL_AddR);                        //Send a MMA7455 address for reading
	if (IIC_ChkAck()) {                                 //Check acknowledge signal 
   	#ifdef ACC_DEBUG	                                //Only for debug	
		prompt_trace(MOD_MMA, "# MMA7455L Device Read Address Error #\r\n");    //Print error information
	#endif
		IIC_Stop();	                                      //Output a STOP signal	
		return;                                           //If acknowledgement signal is read as 1, then return to end
		}
                                                      //If acknowledgement signal is read as 0, then go to next step
	*X = (kal_uint16)IIC_ReadByteACK();                     //Read one byte (lower 8 bits of 10-bit data) and store in a 16-bit address
	temp = (kal_uint16)IIC_ReadByteACK();                   //Read the next byte (higher 2 bits of 10-bit data)
	*X += (temp<<8);                                    //Combine them to a 10-bit data
	if (*X&0x0200) *X |= 0xfc00;	                      //Change the 10-bit data into a 16-bit signed data
   	#ifdef ACC_DEBUG	                                //Only for debug	
		prompt_trace(MOD_MMA, "# MMA7455L Read X Data = %d #\r\n", *X);   //Print the read data
	#endif

	*Y = (kal_uint16)IIC_ReadByteACK();                     //Read one byte (lower 8 bits of 10-bit data) and store in a 16-bit address
	temp = (kal_uint16)IIC_ReadByteACK();                   //Read the next byte (higher 2 bits of 10-bit data)
	*Y += (temp<<8);                                    //Combine them to a 10-bit data
	if (*Y&0x0200) *Y |= 0xfc00;                        //Change the 10-bit data into a 16-bit signed data
   	#ifdef ACC_DEBUG	                                //Only for debug	
		prompt_trace(MOD_MMA, "# MMA7455L Read Y Data = %d #\r\n", *Y);
	#endif

	*Z = (kal_uint16)IIC_ReadByteACK();                     //Read one byte (lower 8 bits of 10-bit data) and store in a 16-bit address
	temp = (kal_uint16)IIC_ReadByteNCK();                   //Read the next byte (higher 2 bits of 10-bit data)
	*Z += (temp<<8);                                    //Combine them to a 10-bit data
	if (*Z&0x0200) *Z |= 0xfc00;                        //Change the 10-bit data into a 16-bit signed data
   	#ifdef ACC_DEBUG	                                //Only for debug	
		prompt_trace(MOD_MMA, "# MMA7455L Read Z Data = %d #\r\n", *Z);
	#endif

	*X += 2048;
	*Y += 2048;
	*Z += 2048;

  // back
	*X = 2*ACC_0G_X-*X;
	*Y = 2*ACC_0G_Y-*Y;
	*Z = 2*ACC_0G_Z-*Z;

	// Stop	
	IIC_Stop();	                                        //Output a STOP signal	
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
	kal_uint8 reg;
	reg = mma745x_IICRead(MCTL);
	reg |= 0x01;
	reg &= ~0x0c;
  mma745x_IICWrite(MCTL, reg);
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
	kal_uint8 reg;
	reg = mma745x_IICRead(MCTL);
	reg &= ~0x03;
  mma745x_IICWrite(MCTL, reg);
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

/*return sensor support gesture*/
kal_bool mma745_query_gesture(kal_uint16 ms_gest_type)
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

kal_bool mma745_get_sensor_params(kal_uint16 ms_params_type, MotionSensorQueryStruct *ms_params)
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
