/*******************************************************************************
 *
 * Filename:
 * ---------
 * MT6188.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *      MT6189 I2C/3-wire Interface
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/
#include "kal_general_types.h"

#if (defined(MT6188A1))

void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada);
void GPIO_InitIO(char direction, char port);
void GPIO_WriteIO(char data,char port);
char GPIO_ReadIO(char port);
void GPO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada);
void GPO_WriteIO(char data, char port);

#define USE_I2C

/* GPIO definition */
/// The following GPIO should be customized according to different platforms.
#if (defined(MT6223)||defined(MT6223P)||defined(MT6235)||defined(MT6238))
#define CRYCLK 26       /// GPIO #31:  32.768 kHz clock
#define CLKMOD 1
#else
#define CRYCLK 18       /// GPIO #31:  32.768 kHz clock
#endif
#ifdef __CUST_NEW__
   #ifdef USE_3_WIRE
      extern const char gpio_fm_3wire_le_pin;
   #endif
   extern const char gpio_fm_i2c_sda_pin;
   extern const char gpio_fm_i2c_scl_pin;

   #ifdef USE_3_WIRE
      #define LE     gpio_fm_3wire_le_pin       /// LE pin
   #endif
   #define SDA    gpio_fm_i2c_sda_pin        /// I2C data pin
   #define SCL    gpio_fm_i2c_scl_pin        /// I2C clock pin
#else /* __CUST_NEW__ */
   #define LE     4        /// GPIO #4:  LE pin
   #define SDA    37        /// GPIO #3: I2C data pin
   #define SCL    38        /// GPIO #2: I2C clock pin
#endif /* __CUST_NEW__ */

#if defined(MT6205B) || defined(MT6208)
   #ifdef __CUST_NEW__
      extern const char gpio_fm_ext_switch_pin;
      #define FM_SWITCH   gpio_fm_ext_switch_pin   /// external switch for FM/speech
   #else /* __CUST_NEW__ */
      #define FM_SWITCH   3   /// GPIO #3:  external switch for FM/speech
   #endif /* __CUST_NEW__ */
#define FM_PATH     0
#define SPEECH_PATH 1

void ExtSwitchInit(void) {
   #ifndef __CUST_NEW__
   GPIO_ModeSetup(FM_SWITCH, 0);
   GPIO_InitIO(1, FM_SWITCH);
   #endif /* __CUST_NEW__ */
   GPIO_WriteIO(FM_SWITCH, SPEECH_PATH);
}

void SwitchExtFMPath(kal_uint8 if_on) {
   if (if_on) GPIO_WriteIO(FM_SWITCH, FM_PATH);
   else GPIO_WriteIO(FM_SWITCH, SPEECH_PATH);
}

#endif

kal_uint16  i2c_dummy_cnt;
#if (defined(MT6228) || defined(MT6229))
#define I2C_DUMMY_DELAY(_delay) for (i2c_dummy_cnt = _delay; i2c_dummy_cnt!=0; i2c_dummy_cnt--)
#else
#define I2C_DUMMY_DELAY(_delay)
#endif

kal_uint8 const FM_RADIO_INPUT_LEVEL_THRESHOLD = 5;

void SerialCommCryClkOn(void)
{
#if !defined( MT6205B ) && !defined( MT6208 )
   #if (defined(MT6223)||defined(MT6223P)||defined(MT6235)||defined(MT6238))
   GPIO_ModeSetup(CRYCLK,2); /* set clock mode */
   GPIO_SetClkOut(CLKMOD,6); /* set to clock 32.768KHz */
   #else
   GPIO_ModeSetup(CRYCLK,3); /* 32.768kHz reference frequency */
   #endif
#else
   #ifdef __CUST_NEW__
      extern const char gpio_fm_srclkena_pin;
      GPO_WriteIO(1, gpio_fm_srclkena_pin);
      GPO_ModeSetup(gpio_fm_srclkena_pin, 0);
   #else /* __CUST_NEW__ */
      /// Config SRCLKENA as GPO2 and set the output to 1 to keep 26M clock alive.
      GPO_WriteIO(1, 2);
      GPO_ModeSetup(2, 0);
   #endif /* __CUST_NEW__ */
#endif
}

void SerialCommCryClkOff(void)
{
#if !defined( MT6205B ) && !defined( MT6208 )
   #if (defined(MT6223)||defined(MT6223P)||defined(MT6235)||defined(MT6238))
   	GPIO_ModeSetup(CRYCLK,0);
   #else
   	GPIO_ModeSetup(CRYCLK,0);
   #endif
#else
   #ifdef __CUST_NEW__
      extern const char gpio_fm_srclkena_pin;
      GPO_ModeSetup(gpio_fm_srclkena_pin, 1);
   #else /* __CUST_NEW__ */
      /// Config GPO2 as SRCLKENA.
      GPO_ModeSetup(2, 1);
   #endif /* __CUST_NEW__ */
#endif
}


#ifdef USE_3_WIRE
void SerialCommInit(void)
{
   #ifndef __CUST_NEW__
   GPIO_ModeSetup(SCL,0);
   GPIO_ModeSetup(SDA,0);
   GPIO_ModeSetup(LE,0);
   #endif /* __CUST_NEW__ */
   GPIO_InitIO(1,SCL);
   GPIO_InitIO(1,LE);
   GPIO_WriteIO(1,SCL);
   GPIO_InitIO(0,SDA);
   GPIO_WriteIO(0,LE);
}

void SerialCommRelease(void)
{
   GPIO_WriteIO(0,SCL);
   GPIO_WriteIO(0,SDA);
   GPIO_WriteIO(0,LE);
}

kal_uint8 SerialCommTxByte(kal_uint8 addr, kal_uint8 data)
{
   kal_int16 i;
   GPIO_WriteIO(1, LE);
   GPIO_InitIO(1,SDA);
   for(i=8; --i>=0;){
      GPIO_WriteIO( 0, SCL);
      GPIO_WriteIO(data&0x01, SDA);
      data >>= 1;
      I2C_DUMMY_DELAY(5);
      GPIO_WriteIO( 1, SCL);
      I2C_DUMMY_DELAY(5);
   }
   for(i=8; --i>=0;){
      GPIO_WriteIO( 0, SCL);
      GPIO_WriteIO(addr&0x01, SDA);
      addr >>= 1;
      I2C_DUMMY_DELAY(5);
      GPIO_WriteIO( 1, SCL);
      I2C_DUMMY_DELAY(5);
   }
   GPIO_InitIO(0,SDA);
   GPIO_WriteIO(0, LE);
   I2C_DUMMY_DELAY(10);
}

kal_uint8 SerialCommRxByte(kal_uint8 addr, kal_uint8 *data)
{
   kal_int16 i;
   kal_uint16 dataRead=0;
   *data = 0;
   GPIO_WriteIO(1, LE);
   GPIO_InitIO(1,SDA);
   for(i=8; --i>=0;){
      GPIO_WriteIO( 0, SCL);
      GPIO_WriteIO(addr&0x01, SDA);
      GPIO_WriteIO(1, SCL);
      addr >>= 1;
      I2C_DUMMY_DELAY(5);
   }
   GPIO_InitIO(0,SDA);
   GPIO_WriteIO(0, LE);
   for(i=0; i<8; i++){
      GPIO_WriteIO( 0, SCL);
      I2C_DUMMY_DELAY(5);
      GPIO_WriteIO( 1, SCL);
      dataRead = GPIO_ReadIO(SDA);
      *data |= (dataRead << i);
   }
   I2C_DUMMY_DELAY(10);
}

#elif defined USE_I2C

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

kal_uint8 SerialCommTxByte(kal_uint8 data) /* return 0 --> ack */
{
   kal_int16 i, ack;
   GPIO_InitIO(1,SDA);
   for(i=8; --i>0;){
      GPIO_WriteIO((kal_int8)((data>>i)&0x01), SDA);
      I2C_DUMMY_DELAY(5);
      GPIO_WriteIO( 1, SCL); /* high */
      I2C_DUMMY_DELAY(5);
      GPIO_WriteIO( 0, SCL); /* low */
      I2C_DUMMY_DELAY(5);
   }
   GPIO_WriteIO((kal_int8)((data>>i)&0x01), SDA);
   I2C_DUMMY_DELAY(5);
   GPIO_WriteIO( 1, SCL); /* high */
   I2C_DUMMY_DELAY(5);
   GPIO_WriteIO( 0, SCL); /* low */

   GPIO_InitIO(0,SDA);
   GPIO_WriteIO(1, SCL);
   I2C_DUMMY_DELAY(5);
   ack = GPIO_ReadIO(SDA); /// ack
   GPIO_WriteIO(0, SCL);
   return (kal_uint8)ack;
}

void SerialCommRxByte(kal_uint8 *data, kal_uint8 ack)
{
   kal_int16 i;
   kal_uint32 dataCache;
   dataCache = 0;
   GPIO_InitIO(0,SDA);
   for(i=8; --i>=0;){
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
   *data = (kal_uint8)dataCache;
   GPIO_WriteIO(0, SCL);
}
#else
#error "Must define USE_I2C or USE_3_WIRE"
#endif

#endif