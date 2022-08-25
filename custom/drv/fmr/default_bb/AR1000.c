
#include "l1audio_def.h"
#include "kal_release.h"
#include "dcl.h"
#include "us_timer.h" 


#if (defined(AR1000))

#define USE_I2C

extern const char gpio_fm_32k_pin;
extern const char gpio_fm_32k_pin_CLK;

#define CRYCLK		gpio_fm_32k_pin
#define CLKSRC_NUM	gpio_fm_32k_pin_CLK


#ifdef __CUST_NEW__

   #ifdef USE_3_WIRE
   extern const char gpio_fm_3wire_le_pin;
   #define LE     gpio_fm_3wire_le_pin
   #endif

   extern const char gpio_fm_i2c_sda_pin;
   extern const char gpio_fm_i2c_scl_pin;
   #define SDA    gpio_fm_i2c_sda_pin
   #define SCL    gpio_fm_i2c_scl_pin
   
#else /* __CUST_NEW__ */
#error "Must enable __CUST_NEW__ and config the gpio with drv_tool"
#endif /* __CUST_NEW__ */

uint8 const FM_RADIO_INPUT_LEVEL_THRESHOLD = 5;
volatile kal_bool bSerialCommOpenFlag = KAL_FALSE;
volatile kal_bool bCryClkOnFlag = KAL_FALSE;

#define FM_I2C_Delay	10

void fm_i2c_udelay(kal_uint32 delay)
{
	kal_uint32 ust = 0, ust1 = 0;
	kal_uint32 count = 0;
	kal_uint32 break_count = 0;
	
	if (delay > 4615) //longer than 1 tick
	{
		kal_sleep_task(delay/4615);
		delay = delay%4615;
	}
	
	ust = ust_get_current_time();
	
	do
	{
		ust1 = ust_get_current_time();

		if (ust1 != ust)
		{
			count++;
		}
		else
		{
			break_count++;
		}
		
		ust = ust1;
	}while((count < delay) && (break_count < 0xFFFFFF));
}

void SerialCommCryClkOn(void)
{
	DCL_HANDLE CryClk_handle;
	DCL_HANDLE fm_32k_handle;
	GPIO_CTRL_SET_CLK_OUT_T gpio_clk_data;

	if (bCryClkOnFlag == KAL_FALSE)
	{
		fm_32k_handle = DclGPIO_Open(DCL_GPIO, CRYCLK);
		DclGPIO_Control(fm_32k_handle, GPIO_CMD_SET_MODE_2, NULL);
		DclGPIO_Close(fm_32k_handle);
		
		CryClk_handle = DclGPIO_Open(DCL_GPIO_CLK, CLKSRC_NUM);
		gpio_clk_data.u2ClkNum = CLKSRC_NUM;
		gpio_clk_data.u2Mode = mode_f32k_ck;
		DclGPIO_Control(CryClk_handle, GPIO_CMD_SET_CLK_OUT, (DCL_CTRL_DATA_T*)&gpio_clk_data);

		DclGPIO_Close(CryClk_handle);
	}

	bCryClkOnFlag = KAL_TRUE;
}

void SerialCommCryClkOff(void)
{
	DCL_HANDLE fm_32k_handle;
	DCL_HANDLE fm_sda_handle;
	DCL_HANDLE fm_clk_handle;

	if (bCryClkOnFlag == KAL_TRUE)
	{
		fm_32k_handle = DclGPIO_Open(DCL_GPIO, CRYCLK);
		DclGPIO_Control(fm_32k_handle, GPIO_CMD_SET_MODE_0, NULL);
		DclGPIO_Control(fm_32k_handle, GPIO_CMD_WRITE_LOW, NULL);

		fm_sda_handle = DclGPIO_Open(DCL_GPIO, SDA);
		fm_clk_handle = DclGPIO_Open(DCL_GPIO, SCL);
		DclGPIO_Control(fm_sda_handle, GPIO_CMD_WRITE_HIGH, NULL);
		DclGPIO_Control(fm_clk_handle, GPIO_CMD_WRITE_HIGH, NULL);

		DclGPIO_Close(fm_32k_handle);
		DclGPIO_Close(fm_sda_handle);
		DclGPIO_Close(fm_clk_handle);
	}

	bCryClkOnFlag = KAL_FALSE;
}

kal_bool SerialCommIsOpen(void)
{
	return bSerialCommOpenFlag;
}

#ifdef USE_3_WIRE
void SerialCommInit(void)
{
  	DCL_HANDLE fm_le_handle;
	DCL_HANDLE fm_sda_handle;
	DCL_HANDLE fm_clk_handle;

	fm_le_handle = DclGPIO_Open(DCL_GPIO, LE);
	fm_sda_handle = DclGPIO_Open(DCL_GPIO, SDA);
	fm_clk_handle = DclGPIO_Open(DCL_DPIO, SCL);

	DclGPIO_Control(fm_le_handle, GPIO_CMD_SET_DIR_OUT, NULL);
	DclGPIO_Control(fm_clk_handle, GPIO_CMD_SET_DIR_OUT, NULL);
	DclGPIO_Control(fm_clk_handle, GPIO_CMD_WRITE_HIGH, NULL);
	DclGPIO_Control(fm_sda_handle, GPIO_CMD_SET_DIR_IN, NULL);
	DclGPIO_Control(fm_le_handle, GPIO_CMD_WRITE_LOW, NULL);
	
	DclGPIO_Close(fm_le_handle);
	DclGPIO_Close(fm_sda_handle);
	DclGPIO_Close(fm_clk_handle);

	bSerialCommOpenFlag = KAL_TRUE;
}

void SerialCommRelease(void)
{
	DCL_HANDLE fm_le_handle;
	DCL_HANDLE fm_sda_handle;
	DCL_HANDLE fm_clk_handle;

	fm_le_handle = DclGPIO_Open(DCL_GPIO, LE);
	fm_sda_handle = DclGPIO_Open(DCL_GPIO, SDA);
	fm_clk_handle = DclGPIO_Open(DCL_DPIO, SCL);

	DclGPIO_Control(fm_clk_handle, GPIO_CMD_WRITE_LOW, NULL);
	DclGPIO_Control(fm_sda_handle, GPIO_CMD_WRITE_LOW, NULL);
	DclGPIO_Control(fm_le_handle, GPIO_CMD_WRITE_LOW, NULL);

	DclGPIO_Close(fm_le_handle);
	DclGPIO_Close(fm_sda_handle);
	DclGPIO_Close(fm_clk_handle);

	bSerialCommOpenFlag = KAL_FALSE;
}

uint8 SerialCommTxByte(uint8 addr, uint8 data)
{
	DCL_HANDLE fm_le_handle;
	DCL_HANDLE fm_sda_handle;
	DCL_HANDLE fm_clk_handle;
	int16 i;

	fm_le_handle = DclGPIO_Open(DCL_GPIO, LE);
	fm_sda_handle = DclGPIO_Open(DCL_GPIO, SDA);
	fm_clk_handle = DclGPIO_Open(DCL_DPIO, SCL);

	DclGPIO_Control(fm_le_handle, GPIO_CMD_WRITE_HIGH, NULL);
	DclGPIO_Control(fm_sda_handle, GPIO_CMD_SET_DIR_OUT, NULL);

	for	(i=8; --i>0; )
	{
		DclGPIO_Control(fm_clk_handle, GPIO_CMD_WRITE_LOW, NULL);

		if (data&0x01)
		{
			DclGPIO_Control(fm_sda_handle, GPIO_CMD_WRITE_HIGH, NULL);
		}
		else
		{
			DclGPIO_Control(fm_sda_handle, GPIO_CMD_WRITE_LOW, NULL);
		}

		data >>= 1;
		fm_i2c_udelay(FM_I2C_Delay);
		DclGPIO_Control(fm_clk_handle, GPIO_CMD_WRITE_HIGH, NULL);
		fm_i2c_udelay(FM_I2C_Delay);
	}

	for	(i=8; --i>0; )
	{
		DclGPIO_Control(fm_clk_handle, GPIO_CMD_WRITE_LOW, NULL);

		if (addr&0x01)
		{
			DclGPIO_Control(fm_sda_handle, GPIO_CMD_WRITE_HIGH, NULL);
		}
		else
		{
			DclGPIO_Control(fm_sda_handle, GPIO_CMD_WRITE_LOW, NULL);
		}

		addr >>= 1;
		fm_i2c_udelay(FM_I2C_Delay);
		DclGPIO_Control(fm_clk_handle, GPIO_CMD_WRITE_HIGH, NULL);
		fm_i2c_udelay(FM_I2C_Delay);
	}

 	DclGPIO_Control(fm_sda_handle, GPIO_CMD_SET_DIR_IN, NULL);
	DclGPIO_Control(fm_le_handle, GPIO_CMD_WRITE_LOW, NULL);
	fm_i2c_udelay(FM_I2C_Delay*2);
   
	DclGPIO_Close(fm_le_handle);
	DclGPIO_Close(fm_sda_handle);
	DclGPIO_Close(fm_clk_handle);
}

uint8 SerialCommRxByte(uint8 addr, uint8 *data)
{
	DCL_HANDLE fm_le_handle;
	DCL_HANDLE fm_sda_handle;
	DCL_HANDLE fm_clk_handle;
	GPIO_CTRL_READ_T sda_read;
   	int16 i;

	fm_le_handle = DclGPIO_Open(DCL_GPIO, LE);
	fm_sda_handle = DclGPIO_Open(DCL_GPIO, SDA);
	fm_clk_handle = DclGPIO_Open(DCL_DPIO, SCL);

	DclGPIO_Control(fm_le_handle, GPIO_CMD_WRITE_HIGH, NULL);
	DclGPIO_Control(fm_sda_handle, GPIO_CMD_SET_DIR_OUT, NULL);

	for (i=8; --i>0; )
	{
		DclGPIO_Control(fm_clk_handle, GPIO_CMD_WRITE_LOW, NULL);

		if (addr&0x01)
		{
			DclGPIO_Control(fm_sda_handle, GPIO_CMD_WRITE_HIGH, NULL);
		}
		else
		{
			DclGPIO_Control(fm_sda_handle, GPIO_CMD_WRITE_LOW, NULL);
		}

		DclGPIO_Control(fm_clk_handle, GPIO_CMD_WRITE_HIGH, NULL);
		addr >>= 1;
		fm_i2c_udelay(FM_I2C_Delay);	
	}
	
	DclGPIO_Control(fm_sda_handle, GPIO_CMD_SET_DIR_IN, NULL);
	DclGPIO_Control(fm_le_handle, GPIO_CMD_WRITE_LOW, NULL);

	for (i=7; i>=0; i--)
	{
		DclGPIO_Control(fm_clk_handle, GPIO_CMD_WRITE_LOW, NULL);
		fm_i2c_udelay(FM_I2C_Delay);
		DclGPIO_Control(fm_clk_handle, GPIO_CMD_WRITE_HIGH, NULL);

		DclGPIO_Control(fm_sda_handle, GPIO_CMD_READ, (DCL_CTRL_DATA_T* )&sda_read);

		*data |= sda_read.u1IOData<<i;
	}
	
	fm_i2c_udelay(FM_I2C_Delay*2);
}

#elif defined USE_I2C

void SerialCommInit(void)
{
	DCL_HANDLE fm_clk_handle;
	DCL_HANDLE fm_sda_handle;

	fm_clk_handle = DclGPIO_Open(DCL_GPIO, SCL);
	fm_sda_handle = DclGPIO_Open(DCL_GPIO, SDA);

	DclGPIO_Control(fm_clk_handle, GPIO_CMD_SET_MODE_0, NULL);
	DclGPIO_Control(fm_sda_handle, GPIO_CMD_SET_MODE_0, NULL);
	
	DclGPIO_Control(fm_clk_handle, GPIO_CMD_SET_DIR_OUT, NULL);

	DclGPIO_Close(fm_clk_handle);
	DclGPIO_Close(fm_sda_handle);

	bSerialCommOpenFlag = KAL_TRUE;
}

void SerialCommRelease(void)
{
	DCL_HANDLE fm_clk_handle;
	DCL_HANDLE fm_sda_handle;

	fm_clk_handle = DclGPIO_Open(DCL_GPIO, SCL);
	fm_sda_handle = DclGPIO_Open(DCL_GPIO, SDA);

	DclGPIO_Control(fm_clk_handle, GPIO_CMD_SET_MODE_0, NULL);
	DclGPIO_Control(fm_sda_handle, GPIO_CMD_SET_MODE_0, NULL);

	DclGPIO_Control(fm_clk_handle, GPIO_CMD_WRITE_HIGH, NULL);
	DclGPIO_Control(fm_sda_handle, GPIO_CMD_WRITE_HIGH, NULL);

	DclGPIO_Close(fm_clk_handle);
	DclGPIO_Close(fm_sda_handle);

	bSerialCommOpenFlag = KAL_FALSE;
}

void SerialCommStart(void) /* Prepare the SDA and SCL for sending/receiving */
{   
	DCL_HANDLE fm_clk_handle;
	DCL_HANDLE fm_sda_handle;

	fm_clk_handle = DclGPIO_Open(DCL_GPIO, SCL);
	fm_sda_handle = DclGPIO_Open(DCL_GPIO, SDA);

	DclGPIO_Control(fm_sda_handle, GPIO_CMD_SET_DIR_OUT, NULL);
	DclGPIO_Control(fm_sda_handle, GPIO_CMD_WRITE_HIGH, NULL);

	fm_i2c_udelay(FM_I2C_Delay);

	DclGPIO_Control(fm_clk_handle, GPIO_CMD_WRITE_HIGH, NULL);
	fm_i2c_udelay(FM_I2C_Delay);

	DclGPIO_Control(fm_sda_handle, GPIO_CMD_WRITE_LOW, NULL);
	fm_i2c_udelay(FM_I2C_Delay);

	DclGPIO_Control(fm_clk_handle, GPIO_CMD_WRITE_LOW, NULL);
	fm_i2c_udelay(FM_I2C_Delay);

	DclGPIO_Close(fm_clk_handle);
	DclGPIO_Close(fm_sda_handle);
}
void SerialCommStop(void)
{
	DCL_HANDLE fm_clk_handle;
	DCL_HANDLE fm_sda_handle;

	fm_clk_handle = DclGPIO_Open(DCL_GPIO, SCL);
	fm_sda_handle = DclGPIO_Open(DCL_GPIO, SDA);

	DclGPIO_Control(fm_sda_handle, GPIO_CMD_SET_DIR_OUT, NULL);
	DclGPIO_Control(fm_clk_handle, GPIO_CMD_WRITE_LOW, NULL);
	fm_i2c_udelay(FM_I2C_Delay);

	DclGPIO_Control(fm_sda_handle, GPIO_CMD_WRITE_LOW, NULL);
	fm_i2c_udelay(FM_I2C_Delay);

	DclGPIO_Control(fm_clk_handle, GPIO_CMD_WRITE_HIGH, NULL);
	fm_i2c_udelay(FM_I2C_Delay);

	DclGPIO_Control(fm_sda_handle, GPIO_CMD_WRITE_HIGH, NULL);
	fm_i2c_udelay(FM_I2C_Delay);

	DclGPIO_Close(fm_clk_handle);
	DclGPIO_Close(fm_sda_handle);
}

uint8 SerialCommTxByte(uint8 data) /* return 0 --> ack */
{
	DCL_HANDLE fm_sda_handle;
	DCL_HANDLE fm_clk_handle;
	GPIO_CTRL_READ_T sda_read;
	int16 i,ack;

	fm_sda_handle = DclGPIO_Open(DCL_GPIO, SDA);
	fm_clk_handle = DclGPIO_Open(DCL_GPIO, SCL);

	DclGPIO_Control(fm_sda_handle, GPIO_CMD_SET_DIR_OUT, NULL);

	for (i=8; --i>=0; )
	{
		if ((data>>i)&0x01)
		{
			DclGPIO_Control(fm_sda_handle, GPIO_CMD_WRITE_HIGH, NULL);
		}
		else
		{
			DclGPIO_Control(fm_sda_handle, GPIO_CMD_WRITE_LOW, NULL);
		}
		fm_i2c_udelay(FM_I2C_Delay);

		DclGPIO_Control(fm_clk_handle, GPIO_CMD_WRITE_HIGH, NULL);
		fm_i2c_udelay(FM_I2C_Delay);

		DclGPIO_Control(fm_clk_handle, GPIO_CMD_WRITE_LOW, NULL);
		fm_i2c_udelay(FM_I2C_Delay);
	}

	DclGPIO_Control(fm_sda_handle, GPIO_CMD_SET_DIR_IN, NULL);
	DclGPIO_Control(fm_clk_handle, GPIO_CMD_WRITE_HIGH, NULL);
	fm_i2c_udelay(FM_I2C_Delay);

	DclGPIO_Control(fm_sda_handle, GPIO_CMD_READ, (DCL_CTRL_DATA_T*) &sda_read);
	ack = sda_read.u1IOData;
	DclGPIO_Control(fm_clk_handle, GPIO_CMD_WRITE_LOW, NULL);

	DclGPIO_Close(fm_sda_handle);
	DclGPIO_Close(fm_clk_handle);

   	return (uint8)ack;
}

void SerialCommRxByte(uint8 *data, uint8 ack)
{
	DCL_HANDLE fm_clk_handle;
	DCL_HANDLE fm_sda_handle;
	GPIO_CTRL_READ_T sda_read;
	int16 i;
	uint32 dataCache;
	
	fm_clk_handle = DclGPIO_Open(DCL_GPIO, SCL);
	fm_sda_handle = DclGPIO_Open(DCL_GPIO, SDA);
	dataCache = 0;
	
	DclGPIO_Control(fm_sda_handle, GPIO_CMD_SET_DIR_IN, NULL);

	for (i=8; --i>=0; )
	{
		dataCache <<= 1;
		DclGPIO_Control(fm_clk_handle, GPIO_CMD_WRITE_HIGH, NULL);
		fm_i2c_udelay(FM_I2C_Delay);
		
		DclGPIO_Control(fm_sda_handle, GPIO_CMD_READ, (DCL_CTRL_DATA_T* ) &sda_read);
		dataCache |= sda_read.u1IOData;
		DclGPIO_Control(fm_clk_handle, GPIO_CMD_WRITE_LOW, NULL);
		fm_i2c_udelay(FM_I2C_Delay);
	}

	DclGPIO_Control(fm_sda_handle, GPIO_CMD_SET_DIR_OUT, NULL);

	if (ack)
	{
		DclGPIO_Control(fm_sda_handle, GPIO_CMD_WRITE_HIGH, NULL);
	}
	else
	{
		DclGPIO_Control(fm_sda_handle, GPIO_CMD_WRITE_LOW, NULL);
	}
	fm_i2c_udelay(FM_I2C_Delay);

	DclGPIO_Control(fm_clk_handle, GPIO_CMD_WRITE_HIGH, NULL);
	fm_i2c_udelay(FM_I2C_Delay);
	*data = (uint8)dataCache;
	DclGPIO_Control(fm_clk_handle, GPIO_CMD_WRITE_LOW, NULL);

	DclGPIO_Close(fm_sda_handle);
	DclGPIO_Close(fm_clk_handle);
}

#else
#error "Must define USE_I2C or USE_3_WIRE"
#endif

#endif
