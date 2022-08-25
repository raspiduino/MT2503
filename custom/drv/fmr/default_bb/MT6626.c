/*******************************************************************************
 *
 * Filename:
 * ---------
 * MT6626.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *      MT6626 I2C Interface
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/
#if (defined(MT6626))&&(!defined(FM_INTERFACE_HCI))
//#include "l1audio_def.h"
/* Allen: add for RHR (20101004) <Start>*/
#include "kal_non_specific_general_types.h"
/* Allen: add for RHR (20101004) <End>*/
#include "dcl.h"

//#define HW_I2C

/* Defintion of time constant for de-emphasis, 50us or 75us
 * If setting to KAL_TRUE, time constant will be 50us.
 * Otherwise, it will be 75us.
 */
const kal_bool FM_DEEMPHASIS_50us = KAL_FALSE;

/* Signal Threshold for Seek/Scan
  *  
  *	RSSI Threshold for long antenna has following setting
  *      0xFEF9'h -> -263'd -> 8.375 (dBuV)
  *      0xFF01'h -> -255'd -> 11.375 (dBuV)
  *      0xFF09'h -> -247'd -> 14.375 (dBuV)
  *
  *	RSSI Threshold for short antenna has following setting
  *       0xFED8'h -> -296'd -> -7 (dBuV)
  *       0xFEE0'h -> -288'd -> -4 (dBuV)
  *       0xFEE8'h -> -280'd -> -1 (dBuV)
  *       
  */
const kal_uint16 RSSI_THRESHOLD_LONGANT = 0xFF01;
const kal_uint16 RSSI_THRESHOLD_SHORTANT = 0xFEE0;

/* GPIO definition */
/// The following GPIO should be customized according to different platforms.
//#define CRYCLK 18       /// GPIO #31:  32.768 kHz clock
#define CLKMOD 6
#define I2C_HL_WIDTH 0
#ifdef __CUST_NEW__
   #if (defined(HW_I2C))
   extern const char gpio_sccb_serial_clk_pin;
   extern const char gpio_sccb_serial_data_pin;
   #define SDA    6        /// I2C data pin
   #define SCL    5        /// I2C clock pin

   //#define SDA    gpio_sccb_serial_data_pin        /// I2C data pin
   //#define SCL    gpio_sccb_serial_clk_pin        /// I2C clock pin
   #else
   extern const char gpio_fm_i2c_sda_pin;
   extern const char gpio_fm_i2c_scl_pin;
   extern const char gpio_fm_i2c_sda_pin_M_GPIO;
   extern const char gpio_fm_i2c_scl_pin_M_GPIO;
   extern const char gpio_bt_32k_pin;
   extern const char gpio_bt_32k_pin_M_GPIO;
   #define SDA    gpio_fm_i2c_sda_pin        /// I2C data pin
   #define SCL    gpio_fm_i2c_scl_pin        /// I2C clock pin
   #define CRYCLK gpio_bt_32k_pin //FM 32k
   #endif
#else /* __CUST_NEW__ */
   #define LE     4        /// GPIO #4:  LE pin
   #define SDA   53        /// GPIO #53: I2C data pin
   #define SCL   24        /// GPIO #24: I2C clock pin
#endif /* __CUST_NEW__ */

kal_uint16  i2c_dummy_cnt;
#define I2C_DUMMY_DELAY(_delay) for (i2c_dummy_cnt = _delay+3; i2c_dummy_cnt!=0; i2c_dummy_cnt--)

void SerialCommCryClkOn(void)
{
   //GPIO_ModeSetup(CRYCLK,3); /* 32.768kHz reference frequency */
   //GPIO_SetClkOut(CLKMOD,4); /* set to clock 32.768KHz */
}

void SerialCommCryClkOff(void)
{
   	//GPIO_ModeSetup(CRYCLK,0);
}

#if !defined(HW_I2C)
void SerialCommInit(void)
{
	DCL_HANDLE SCL_handle,SDA_handle;
	SCL_handle = DclGPIO_Open(DCL_GPIO, SCL);
	SDA_handle = DclGPIO_Open(DCL_GPIO, SDA);
	
   //GPIO_ModeSetup(SCL,gpio_fm_i2c_scl_pin_M_GPIO);  
	DclGPIO_Control(SCL_handle,GPIO_CMD_SET_MODE_0,NULL);
   //GPIO_ModeSetup(SDA,gpio_fm_i2c_sda_pin_M_GPIO);
	DclGPIO_Control(SDA_handle,GPIO_CMD_SET_MODE_0,NULL);
   //GPIO_WriteIO(1,SDA);
   //GPIO_WriteIO(1,SCL);
   //GPIO_InitIO(1,SCL); // Output mode
   DclGPIO_Control(SCL_handle, GPIO_CMD_SET_DIR_OUT, NULL);
   //GPIO_InitIO(1,SDA); // Output mode
   DclGPIO_Control(SDA_handle, GPIO_CMD_SET_DIR_OUT, NULL);
   //GPIO_PullenSetup(SCL, 1); // pull high
   DclGPIO_Control(SCL_handle, GPIO_CMD_ENABLE_PULL, NULL);
   //GPIO_PullenSetup(SDA, 1);
   DclGPIO_Control(SDA_handle, GPIO_CMD_ENABLE_PULL, NULL);
   //GPIO_PullSelSetup(SCL, 1);
   DclGPIO_Control(SCL_handle, GPIO_CMD_SET_PULL_HIGH, NULL);
   //GPIO_PullSelSetup(SDA, 1);
   DclGPIO_Control(SDA_handle, GPIO_CMD_SET_PULL_HIGH, NULL);
   DclGPIO_Control(SCL_handle, GPIO_CMD_WRITE_HIGH, NULL);
   DclGPIO_Control(SDA_handle, GPIO_CMD_WRITE_HIGH, NULL);
}

void SerialCommRelease(void)
{
	DCL_HANDLE SCL_handle,SDA_handle;
	SCL_handle = DclGPIO_Open(DCL_GPIO, SCL);
	SDA_handle = DclGPIO_Open(DCL_GPIO, SDA);
   //GPIO_WriteIO(1,SCL);
   	DclGPIO_Control(SCL_handle, GPIO_CMD_WRITE_HIGH, NULL);
   //GPIO_WriteIO(1,SDA);
   	DclGPIO_Control(SDA_handle, GPIO_CMD_WRITE_HIGH, NULL);
}

/* Start sequence of I2C

   SDA ¢w¢w¢{
           ¢|¢w¢w
   SCL ¢w¢w¢w¢{
             ¢|¢w¢w
*/
void SerialCommStart(void) /* Prepare the SDA and SCL for sending/receiving */
{   
	DCL_HANDLE SCL_handle,SDA_handle;
	SCL_handle = DclGPIO_Open(DCL_GPIO, SCL);
	SDA_handle = DclGPIO_Open(DCL_GPIO, SDA);
	
   //GPIO_InitIO(1,SDA);
   	DclGPIO_Control(SDA_handle, GPIO_CMD_SET_DIR_OUT, NULL);
   //GPIO_WriteIO(1,SDA);
   DclGPIO_Control(SDA_handle, GPIO_CMD_WRITE_HIGH, NULL);
   I2C_DUMMY_DELAY(I2C_HL_WIDTH);
   //GPIO_WriteIO(1,SCL);
   DclGPIO_Control(SCL_handle, GPIO_CMD_WRITE_HIGH, NULL);
   I2C_DUMMY_DELAY(I2C_HL_WIDTH);
   
   //GPIO_WriteIO(0,SDA);
   DclGPIO_Control(SDA_handle, GPIO_CMD_WRITE_LOW, NULL);
   I2C_DUMMY_DELAY(I2C_HL_WIDTH);
   //GPIO_WriteIO(0,SCL);
   DclGPIO_Control(SCL_handle, GPIO_CMD_WRITE_LOW, NULL);
   I2C_DUMMY_DELAY(I2C_HL_WIDTH);
}

/* Stop sequence of I2C

   SDA       ¢z¢w¢w
       ¢w¢w¢w¢}
   SCL     ¢z¢w¢w¢w
       ¢w¢w¢}
*/

void SerialCommStop(void)
{
	DCL_HANDLE SCL_handle,SDA_handle;
	SCL_handle = DclGPIO_Open(DCL_GPIO, SCL);
	SDA_handle = DclGPIO_Open(DCL_GPIO, SDA);

   //GPIO_InitIO(1,SDA);
   DclGPIO_Control(SDA_handle, GPIO_CMD_SET_DIR_OUT, NULL);
   //GPIO_WriteIO(0,SCL);
   DclGPIO_Control(SCL_handle, GPIO_CMD_WRITE_LOW, NULL);
   I2C_DUMMY_DELAY(I2C_HL_WIDTH);
   //GPIO_WriteIO(0,SDA);
   DclGPIO_Control(SDA_handle, GPIO_CMD_WRITE_LOW, NULL);
   I2C_DUMMY_DELAY(I2C_HL_WIDTH);
   //GPIO_WriteIO(1,SCL);
   DclGPIO_Control(SCL_handle, GPIO_CMD_WRITE_HIGH, NULL);
   I2C_DUMMY_DELAY(I2C_HL_WIDTH);
   //GPIO_WriteIO(1,SDA);
   DclGPIO_Control(SDA_handle, GPIO_CMD_WRITE_HIGH, NULL);
   I2C_DUMMY_DELAY(I2C_HL_WIDTH);
}

kal_uint8 SerialCommTxByte(kal_uint8 data) /* return 0 --> ack */
{
	kal_int16 i;
	GPIO_CTRL_READ_T readIO;
	DCL_HANDLE SCL_handle,SDA_handle;
	SCL_handle = DclGPIO_Open(DCL_GPIO, SCL);
	SDA_handle = DclGPIO_Open(DCL_GPIO, SDA);
	//GPIO_InitIO(1,SDA);
	DclGPIO_Control(SDA_handle, GPIO_CMD_SET_DIR_OUT, NULL);
	for(i=8; --i>0;)
   	{
		if((data>>i)&0x01)
		{
			DclGPIO_Control(SDA_handle, GPIO_CMD_WRITE_HIGH, NULL);
		}
		else
		{
			DclGPIO_Control(SDA_handle, GPIO_CMD_WRITE_LOW, NULL);
		}
      //GPIO_WriteIO((kal_int8)((data>>i)&0x01), SDA);
      	I2C_DUMMY_DELAY(I2C_HL_WIDTH);
      //GPIO_WriteIO( 1, SCL); /* high */
	  	DclGPIO_Control(SCL_handle, GPIO_CMD_WRITE_HIGH, NULL);
      	I2C_DUMMY_DELAY(I2C_HL_WIDTH);
      //GPIO_WriteIO( 0, SCL); /* low */
      	I2C_DUMMY_DELAY(I2C_HL_WIDTH);
	  	DclGPIO_Control(SCL_handle, GPIO_CMD_WRITE_LOW, NULL);
   	}
	if((data>>i)&0x01)
	{
		DclGPIO_Control(SDA_handle, GPIO_CMD_WRITE_HIGH, NULL);
	}
	else
	{
		DclGPIO_Control(SDA_handle, GPIO_CMD_WRITE_LOW, NULL);
	}
   //GPIO_WriteIO((kal_int8)((data>>i)&0x01), SDA);
   I2C_DUMMY_DELAY(I2C_HL_WIDTH);
   //GPIO_WriteIO( 1, SCL); /* high */
   DclGPIO_Control(SCL_handle, GPIO_CMD_WRITE_HIGH, NULL);
   I2C_DUMMY_DELAY(I2C_HL_WIDTH);
   //GPIO_WriteIO( 0, SCL); /* low */
   DclGPIO_Control(SCL_handle, GPIO_CMD_WRITE_LOW, NULL);

   //GPIO_InitIO(0,SDA);
   DclGPIO_Control(SDA_handle, GPIO_CMD_SET_DIR_IN, NULL);
   //GPIO_WriteIO(1, SCL);
   DclGPIO_Control(SCL_handle, GPIO_CMD_WRITE_HIGH, NULL);
   I2C_DUMMY_DELAY(I2C_HL_WIDTH);
   //ack = GPIO_ReadIO(SDA); /// ack
   DclGPIO_Control(SDA_handle, GPIO_CMD_READ, (DCL_CTRL_DATA_T *)&readIO);
   //GPIO_WriteIO(0, SCL);
   DclGPIO_Control(SCL_handle, GPIO_CMD_WRITE_LOW, NULL);
   
   return (kal_uint8)readIO.u1IOData;
}

void SerialCommRxByte(kal_uint8 *data, kal_uint8 ack)
{
	kal_int16 i;
	kal_uint32 dataCache;
	GPIO_CTRL_READ_T readIO;
	DCL_HANDLE SCL_handle,SDA_handle;
	SCL_handle = DclGPIO_Open(DCL_GPIO, SCL);
	SDA_handle = DclGPIO_Open(DCL_GPIO, SDA);
	dataCache = 0;
	//GPIO_InitIO(0,SDA);
	DclGPIO_Control(SDA_handle, GPIO_CMD_SET_DIR_IN, NULL);
	for(i=17; --i>=9;)
   	{
      dataCache <<= 1;
      //GPIO_WriteIO(1, SCL);
	  DclGPIO_Control(SCL_handle, GPIO_CMD_WRITE_HIGH, NULL);
      I2C_DUMMY_DELAY(I2C_HL_WIDTH);
      //dataCache |= GPIO_ReadIO(SDA);
	  DclGPIO_Control(SDA_handle, GPIO_CMD_READ, (DCL_CTRL_DATA_T *)&readIO);
	  dataCache |= readIO.u1IOData;
      //GPIO_WriteIO(0, SCL);
	  DclGPIO_Control(SCL_handle, GPIO_CMD_WRITE_LOW, NULL);
      I2C_DUMMY_DELAY(I2C_HL_WIDTH);
   	}
   	//GPIO_InitIO(1,SDA);
   	DclGPIO_Control(SDA_handle, GPIO_CMD_SET_DIR_OUT, NULL);
   //GPIO_WriteIO(ack, SDA);
   	if(ack)
   	{
	   	DclGPIO_Control(SDA_handle, GPIO_CMD_WRITE_HIGH, NULL);
   	}
   	else
   	{
	   	DclGPIO_Control(SDA_handle, GPIO_CMD_WRITE_LOW, NULL);
   	}
   	I2C_DUMMY_DELAY(I2C_HL_WIDTH);
   //GPIO_WriteIO(1, SCL);
   	DclGPIO_Control(SCL_handle, GPIO_CMD_WRITE_HIGH, NULL);
   *data = (kal_uint8)dataCache;
   //GPIO_WriteIO(0, SCL);
   	DclGPIO_Control(SCL_handle, GPIO_CMD_WRITE_LOW, NULL);   
}
#else
void SerialCommInit(void)
{
   #ifdef __CUST_NEW__
   GPIO_ModeSetup(SCL, 0x01); //SCL
   GPIO_ModeSetup(SDA, 0x01); //SDA
   GPIO_PullenSetup(SCL, KAL_TRUE);
   GPIO_PullenSetup(SDA, KAL_TRUE);
   GPIO_PullSelSetup(SCL, KAL_TRUE);
   GPIO_PullSelSetup(SDA, KAL_TRUE);
#else
   GPIO_ModeSetup(SCL,0);
   GPIO_ModeSetup(SDA,0);
   #endif
}
#endif

#endif
