/*******************************************************************************
 *
 * Filename:
 * ---------
 * MT6616.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *      MT6616 I2C Interface
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/
#if (defined(MT6616))&&(!defined(FM_INTERFACE_HCI))
#include "l1audio_def.h"

void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada);
void GPIO_InitIO(char direction, char port);
void GPIO_WriteIO(char data,char port);
char GPIO_ReadIO(char port);
//#define HW_I2C

/* GPIO definition */
/// The following GPIO should be customized according to different platforms.
#define CRYCLK 18       /// GPIO #31:  32.768 kHz clock
#define CLKMOD 0
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
   #define SDA    gpio_fm_i2c_sda_pin        /// I2C data pin
   #define SCL    gpio_fm_i2c_scl_pin        /// I2C clock pin
   #endif
#else /* __CUST_NEW__ */
   #define LE     4        /// GPIO #4:  LE pin
   #define SDA   53        /// GPIO #53: I2C data pin
   #define SCL   24        /// GPIO #24: I2C clock pin
#endif /* __CUST_NEW__ */

uint16  i2c_dummy_cnt;
#define I2C_DUMMY_DELAY(_delay) for (i2c_dummy_cnt = _delay+3; i2c_dummy_cnt!=0; i2c_dummy_cnt--)
uint8 const FM_SEEK_RSSI_THRESHOLD = 5;

void SerialCommCryClkOn(void)
{
   GPIO_ModeSetup(CRYCLK,3); /* 32.768kHz reference frequency */
   //GPIO_SetClkOut(CLKMOD,4); /* set to clock 32.768KHz */
}

void SerialCommCryClkOff(void)
{
   	GPIO_ModeSetup(CRYCLK,0);
}

#if !defined(HW_I2C)
void SerialCommInit(void)
{
   #ifndef __CUST_NEW__
   GPIO_ModeSetup(SCL,0);
   GPIO_ModeSetup(SDA,0);
   #endif /* __CUST_NEW__ */
   GPIO_InitIO(1,SCL);
}

void SerialCommRelease(void)
{
   GPIO_WriteIO(1,SCL);
   GPIO_WriteIO(1,SDA);
}

/* Start sequence of I2C

   SDA ¢w¢w¢{
           ¢|¢w¢w
   SCL ¢w¢w¢w¢{
             ¢|¢w¢w
*/
void SerialCommStart(void) /* Prepare the SDA and SCL for sending/receiving */
{   
   GPIO_InitIO(1,SDA);
   GPIO_WriteIO(1,SDA);
   I2C_DUMMY_DELAY(5);
   GPIO_WriteIO(1,SCL);
   I2C_DUMMY_DELAY(5);
   GPIO_WriteIO(0,SDA);
   I2C_DUMMY_DELAY(5);
   GPIO_WriteIO(0,SCL);
   I2C_DUMMY_DELAY(5);
}

/* Stop sequence of I2C

   SDA       ¢z¢w¢w
       ¢w¢w¢w¢}
   SCL     ¢z¢w¢w¢w
       ¢w¢w¢}
*/

void SerialCommStop(void)
{
   GPIO_InitIO(1,SDA);
   GPIO_WriteIO(0,SCL);
   I2C_DUMMY_DELAY(5);
   GPIO_WriteIO(0,SDA);
   I2C_DUMMY_DELAY(5);
   GPIO_WriteIO(1,SCL);
   I2C_DUMMY_DELAY(5);
   GPIO_WriteIO(1,SDA);
   I2C_DUMMY_DELAY(5);
}

uint8 SerialCommTxByte(uint8 data) /* return 0 --> ack */
{
   int16 i, ack;
   GPIO_InitIO(1,SDA);
   for(i=8; --i>0;){
      GPIO_WriteIO((int8)((data>>i)&0x01), SDA);
      I2C_DUMMY_DELAY(5);
      GPIO_WriteIO( 1, SCL); /* high */
      I2C_DUMMY_DELAY(5);
      GPIO_WriteIO( 0, SCL); /* low */
      I2C_DUMMY_DELAY(5);
   }
   GPIO_WriteIO((int8)((data>>i)&0x01), SDA);
   I2C_DUMMY_DELAY(5);
   GPIO_WriteIO( 1, SCL); /* high */
   I2C_DUMMY_DELAY(5);
   GPIO_WriteIO( 0, SCL); /* low */

   GPIO_InitIO(0,SDA);
   GPIO_WriteIO(1, SCL);
   I2C_DUMMY_DELAY(5);
   ack = GPIO_ReadIO(SDA); /// ack
   GPIO_WriteIO(0, SCL);
   return (uint8)ack;
}

void SerialCommRxByte(uint8 *data, uint8 ack)
{
   int16 i;
   uint32 dataCache;
   dataCache = 0;
   GPIO_InitIO(0,SDA);
   for(i=17; --i>=9;){
      dataCache <<= 1;
      GPIO_WriteIO(1, SCL);
      I2C_DUMMY_DELAY(5);
      dataCache |= GPIO_ReadIO(SDA);
      GPIO_WriteIO(0, SCL);
      I2C_DUMMY_DELAY(5);
   }
   GPIO_InitIO(1,SDA);
   GPIO_WriteIO(ack, SDA);
   I2C_DUMMY_DELAY(5);
   GPIO_WriteIO(1, SCL);
   *data = (uint8)dataCache;
   GPIO_WriteIO(0, SCL);
   
   
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

