/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *	   uart.c
 *
 * Project:
 * --------
 *    MTK6208 DOWNLOAD AGENT
 *
 * Description:
 * ------------
 *    This Module defines the uart driver.
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/
//#include "UART_HW.H"
//#include "UART.H"
//#include "BLOADER.H"
//#include "hw_config.h"
#include "gps_uart.h"
#include "drv_features_uart.h"
#include "bl_common.h"
#include "bl_custom.h"

#if defined(BB_MT6291)
#include "da_uart_drv.h"
#include "usbdl_u3mac_reg.h"
#endif

//extern uint32 err_threshold;
static uint32 err_threshold;

static const uint16 baudrate[]= {
	1,		// UART_BAUD_921600
	2,		// UART_BAUD_460800
	4,		// UART_BAUD_230400
	7,		// UART_BAUD_115200
	14,		// UART_BAUD_57600
	21,		// UART_BAUD_38400
	42,		// UART_BAUD_19200
	85,		// UART_BAUD_9600
	169,	// UART_BAUD_4800
	339,	// UART_BAUD_2400
	677,	// UART_BAUD_1200
	2708,	// UART_BAUD_300
	7386	// UART_BAUD_110
};

static const uint16 baudrate2[]= {			// MT6225 or later
	0,		// UART_BAUD_921600
	1,		// UART_BAUD_460800
	2,		// UART_BAUD_230400
	4,		// UART_BAUD_115200
	8,		// UART_BAUD_57600
	12,		// UART_BAUD_38400
	25,		// UART_BAUD_19200
	50,		// UART_BAUD_9600
	100,	// UART_BAUD_4800
	200,	// UART_BAUD_2400
	400,	// UART_BAUD_1200
	1200,	// UART_BAUD_300
	4364	// UART_BAUD_110
};

static const uint32 baud_table[] = {
    921600,
    460800,
    230400,
    115200,
    57600,
    38400,
    19200,
    9600,
    4800,
    2400,
    1200,
    300,
    110
};


static const uint16 highspeed_baudrate_table[][4][4]={
	// { HIGH_SPEED_UART, UART1_DLL, SAMPLE_COUNT, SAMPLE_POINT }

	// 13M
	{
		{ 0x03, 0x02, 0x0E, 0x01 },		// baudrate 921600
		{ 0x02, 0x07,    0,    0 },		// baudrate 460800
		{ 0x01, 0x07,    0,    0 },		// baudrate 230400
		{ 0x00, 0x07,    0,    0 }		// baudrate 115200
	},

	// 26M
	{
		{ 0x03, 0x04, 0x1C, 0x0A },		// baudrate 921600
		{ 0x01, 0x07,    0,    0 },		// baudrate 460800
		{ 0x00, 0x07,    0,    0 },		// baudrate 230400
		{ 0x00, 0x0E,    0,    0 }		// baudrate 115200
	},

	// 39M
	{
		{ 0x03, 0x06, 0x2A, 0x15 },		// baudrate 921600
		{ 0x02, 0x15,    0,    0 },		// baudrate 460800
		{ 0x01, 0x15,    0,    0 },		// baudrate 230400
		{ 0x00, 0x15,    0,    0 }		// baudrate 115200
	},

	// 52M
	{
		{ 0x01, 0x07,    0,    0 },		// baudrate 921600
		{ 0x00, 0x07,    0,    0 },		// baudrate 460800
		{ 0x00, 0x0E,    0,    0 },		// baudrate 230400
		{ 0x00, 0x1C,    0,    0 }		// baudrate 115200
	}
};

static const uint16 highspeed_baudrate_table_MT6225[][4][4]={
	// { HIGH_SPEED_UART, UART1_DLL, SAMPLE_COUNT, SAMPLE_POINT }

	// 13M
	{
		{ 0x03, 0x01, 0x0D, 0x06 },		// baudrate 921600
		{ 0x02, 0x07,    0,    0 },		// baudrate 460800
		{ 0x01, 0x07,    0,    0 },		// baudrate 230400
		{ 0x00, 0x07,    0,    0 }		// baudrate 115200
	},

	// 26M (default)
	{
		{ 0x03, 0x01, 0x1B, 0x0D },		// baudrate 921600
		{ 0x01, 0x07,    0,    0 },		// baudrate 460800
		{ 0x00, 0x07,    0,    0 },		// baudrate 230400
		{ 0x00, 0x0E,    0,    0 }		// baudrate 115200
	},

	// 39M
	{
		{ 0x03, 0x01, 0x29, 0x14 },		// baudrate 921600
		{ 0x02, 0x15,    0,    0 },		// baudrate 460800
		{ 0x01, 0x15,    0,    0 },		// baudrate 230400
		{ 0x00, 0x15,    0,    0 }		// baudrate 115200
	},

	// 52M
	{
		{ 0x03, 0x01, 0x37, 0x1B },		// baudrate 921600
		{ 0x00, 0x07,    0,    0 },		// baudrate 460800
		{ 0x00, 0x0E,    0,    0 },		// baudrate 230400
		{ 0x00, 0x1C,    0,    0 }		// baudrate 115200
	}
};

static const uint16 highspeed_baudrate_table_MT6268A[3][4]={
	// { HIGH_SPEED_UART, UART1_DLL, SAMPLE_COUNT, SAMPLE_POINT }

/* Hard code :
	// 7.68M
	{
		{ 0x01, 0x01,    0,    0 },		// baudrate 921600
		{ 0x00, 0x01,    0,    0 },		// baudrate 460800
		{ 0x00, 0x02,    0,    0 }		// baudrate 230400
	},

	// 15.36M
	{
		{ 0x00, 0x01,    0,    0 },		// baudrate 921600
		{ 0x00, 0x02,    0,    0 },		// baudrate 460800
		{ 0x00, 0x04,    0,    0 }		// baudrate 230400
	},

	// 23.04M
	{
		{ 0x01, 0x03,    0,    0 },		// baudrate 921600
		{ 0x00, 0x03,    0,    0 },		// baudrate 460800
		{ 0x00, 0x06,    0,    0 }		// baudrate 230400
	},


	// 30.72M
	{
		{ 0x00, 0x02,    0,    0 },		// baudrate 921600
		{ 0x00, 0x04,    0,    0 },		// baudrate 460800
		{ 0x00, 0x08,    0,    0 }		// baudrate 230400
	},
*/

	// 61.44M
//	{
		{ 0x03, 0x01, 0x42, 0x21 },		// baudrate 921600
		{ 0x03, 0x01, 0x84, 0x42 },		// baudrate 460800
		{ 0x03, 0x02, 0x84, 0x42 }		// baudrate 230400
//	}

};

static const uint16 highspeed_baudrate_table_FPGA[][3][4]={
	// { HIGH_SPEED_UART, UART1_DLL, SAMPLE_COUNT, SAMPLE_POINT }

	// 12M
	{
		{ 0x03, 0x01, 0x0C, 0x06 },		// baudrate 921600
		{ 0x03, 0x01, 0x19, 0x0C },		// baudrate 460800
		{ 0x02, 0x0D,    0,    0 }		// baudrate 230400
	},

	// 24M (default)
	{
		//{ 0x03, 0x01, 0x19, 0x0C },		// baudrate 921600
		//{ 0x02, 0x0D,    0,    0 },		// baudrate 460800
		//{ 0x01, 0x0D,    0,    0 }		// baudrate 230400
		{ 0x03, 0x01, 0x19, 0x0C },		// baudrate 921600
		{ 0x03, 0x01, 0x33, 0x19 },		// baudrate 460800
		{ 0x02, 0x0D, 0x67, 0x33 }		// baudrate 230400
	},

	// 36M
	{
		{ 0x03, 0x01, 0x26, 0x13 },		// baudrate 921600
		{ 0x03, 0x01, 0x4D, 0x26 },		// baudrate 460800
		{ 0x02, 0x27,    0,    0 }		// baudrate 230400
	},

	// 52M
	{
		{ 0x03, 0x01, 0x33, 0x19 },		// baudrate 921600
		{ 0x01, 0x0D,    0,    0 },		// baudrate 460800
		{ 0x00, 0x0D,    0,    0 }		// baudrate 230400
	}
};

void GPS_UART_Delay(void)
{
	uint32 index_loop;
	uint32 index;

	for(index_loop=0;index_loop < 20;index_loop++)
		for(index=0;index<10000;index++);
}

void GPS_UART_Init(void)	//this is called , if no bootrom issued!!
{

#if 1
	uint16 tmp;
	BL_PRINT(LOG_DEBUG, "[FUNET]In GPS_UART_Init \n\r");
    /* uart pinmux configure */
    *(volatile int *)(0xa0020c14) = (1<<17);
    *(volatile int *)(0xa0020c24) = (1<<5);

    /* enable uart clock */
    *(volatile int *)(0xa0010324) |= 0xe000;

	//Setup N81,(UART_WLS_8 | UART_NONE_PARITY | UART_1_STOP) = 0x03
	*PDN_CON1 &= ~0x0008;
	UART_WriteReg(UART2_LCR,0x0003);
	//Set BaudRate = 115200;
	tmp = UART_ReadReg(UART2_LCR);		/* DLAB start */
	UART_WriteReg(UART2_LCR,(tmp | UART_LCR_DLAB));

#ifdef PLUTO_DA_INIT_MPLL_UART
	/* 115200  UART_WriteReg(UART1_DLL,0x0007);  */
	UART_WriteReg(UART2_DLL,0x0007*4);
#else
	/* 19200 */
	//UART_WriteReg(UART2_DLL,0x002a);
	/* 115200/26M */
	UART_WriteReg(UART2_DLL,0x0007*2);
#endif
	UART_WriteReg(UART2_DLH,0x0000);
	UART_WriteReg(UART2_LCR,tmp);		/* DLAB End */
	//Set Baudrate
	UART_WriteReg(UART2_FCR,0x0047);
	UART_WriteReg(UART2_MCR,(uint16)0x0003);

	UART_WriteReg(UART2_FCR,UART_FCR_Normal);
#endif
BL_PRINT(LOG_DEBUG, "[FUNET]Out GPS_UART_Init \n\r");

}

uint8 GPS_UART_GetByte(void)
{
    uint8	g_uart_last_rx_data;
    uint16	g_uart_last_lsr;
    uint8	rest_data[32];
    uint32	rest_count;

	while(1)
    {
		g_uart_last_lsr = UART_ReadReg(UART2_LSR);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
		if( g_uart_last_lsr & UART_LSR_DR )	{
			g_uart_last_rx_data = (uint8)UART_ReadReg(UART2_RBR);
            
            //BL_PRINT(LOG_DEBUG, "[FUNET]GPS_UART_GetByte:%x \n\r",g_uart_last_rx_data);
			return g_uart_last_rx_data;
		}
	}
}

bool GPS_UART_GetByteStatus(uint8 *data)
{
	uint16 LSR;
	uint32 err_count;

	err_count = 0;
	while(1)
	{
		LSR = UART_ReadReg(UART2_LSR);

		if ((LSR & UART_LSR_FIFOERR) ||
			(LSR & UART_LSR_OE) ||
			(LSR & UART_LSR_PE) )
		{
			err_count = 0;
		}

		if (LSR & UART_LSR_DR) {
			*data = (uint8)UART_ReadReg(UART2_RBR);
			return TRUE;
		}
		else {
			err_count++;
			if(err_count > err_threshold) {
				return FALSE;
			}
		}
	}

}

bool GPS_UART_GetByte_NO_TIMEOUT(uint8 *data)
{
	uint16 LSR;

	LSR = UART_ReadReg(UART2_LSR);

	if (LSR & UART_LSR_DR) {
		*data = (uint8)UART_ReadReg(UART2_RBR);
		return TRUE;
	}
	else {
		return FALSE;
	}
}

bool GPS_UART_GetByte_Buffer(uint32* buf, uint32 length)
{
	bool ret;
	uint32 i;
	uint8 * buf8 = (uint8*)buf;

	for(i=0; i<length; i++)
	{
		ret = GPS_UART_GetByteStatus(buf8+i);
		if(!ret){ return FALSE;}
	}

	return TRUE;
}

void GPS_UART_PutByte(uint8 data)
{
	uint16 LSR;
    //BL_PRINT(LOG_DEBUG, "[FUNET]GPS_UART_PutByte:%x \n\r",data);

	while(1)
	{
	
		LSR = UART_ReadReg(UART2_LSR);
		if ( LSR & UART_LSR_THRE )
		{
			UART_WriteReg(UART2_THR,(uint16)data);
            
            //BL_PRINT(LOG_DEBUG, "[FUNET]Send Byte\n\r");
			break;
		}
	}
    
    //BL_PRINT(LOG_DEBUG, "[FUNET]OUT GPS_UART_PutByte\n\r");
}

void GPS_UART_PutByte_Buffer(uint32* buf, uint32 length)
{
	uint32 i;
	uint8* tmp_buf = (uint8*)buf;

	#ifdef	HIGHSPEED_UART_PUT_DELAY
		uint16 		delay;
		uint16 		delay_max;

		extern UART_BAUDRATE		g_baudrate;
		// calculate the max delay by external clock.
		delay_max = 350*g_HW_DevCfg.m_clk_cfg.m_ext_clock;
	#endif
	//BL_PRINT(LOG_DEBUG, "[FUNET]PUTBYTE_BUFFER\n\r");

	for(i=0; i < length; i++)
	{
		#ifdef	HIGHSPEED_UART_PUT_DELAY
			// in order to prevent PC lost data at high speed baudrate, every 14 bytes must have a delay.
			// 14 is the max size of standard RX FIFO on Windows.
			if( UART_BAUD_230400>g_baudrate && 0==i%14 )
			{
				for(delay=0; delay<delay_max; delay++);
			}
            
            //BL_PRINT(LOG_DEBUG, "[FUNET]HIGHSPEED_UART_PUT_DELAY\n\r");
		#endif

		GPS_UART_PutByte(*(tmp_buf+i));
	}
}

void GPS_UART_PutByte_Complete(uint8 data)
{
	GPS_UART_PutByte(data);
}

uint16 GPS_UART_GetData16(void)			//ok, high byte is first
{
	uint8	tmp,index;
	uint16 	tmp16;
	uint16  result =0;
	for (index =0;index < 2;index++)
	{
		tmp = GPS_UART_GetByte();
		tmp16 = (uint16)tmp;
		result |= (tmp16 << (8-8*index));
	}
	return result;
}

void GPS_UART_PutData16(uint16 data)		//ok, high byte is first
{
	uint8	tmp,index;
	uint16 	tmp16;

	for (index =0;index < 2;index++)
	{
		tmp16 = (data >> (8-8*index));
		tmp = (uint8)tmp16;
		GPS_UART_PutByte(tmp);
	}
}

uint32 GPS_UART_GetData32(void)			//ok, high byte is first
{
	uint8	tmp,index;
	uint32 	tmp32;
	uint32  result =0;
	for (index =0;index < 4;index++)
	{
		tmp = GPS_UART_GetByte();
		tmp32 = (uint32)tmp;
		result |= (tmp32 << (24-8*index));
	}
	return result;
}

void GPS_UART_PutData32(uint32 data)		//ok, high byte is first
{
	uint8	tmp,index;
	uint32 	tmp32;

	for (index =0;index < 4;index++)
	{
		tmp32 = (data >> (24-8*index));
		tmp = (uint8)tmp32;
		GPS_UART_PutByte(tmp);
	}
}

void GPS_UART_PurgeFIFO(void)
{
	GPS_UART_Delay();
    //#if defined(BB_MT6261) || defined(BB_MT2523)

    UART_WriteReg(UART2_FCR, 0x0 | UART_FCR_RX62Byte_Level | UART_FCR_TX62Byte_Level );
    UART_WriteReg(UART2_FCR, 0x6 | UART_FCR_RX62Byte_Level | UART_FCR_TX62Byte_Level );
    UART_WriteReg(UART2_FCR, 0x1 | UART_FCR_RX62Byte_Level | UART_FCR_TX62Byte_Level );

    //#else
    //UART_WriteReg(UART2_FCR, UART_FCR_MaxFIFO);
    //#endif
    GPS_UART_Delay();
}

//static bool USB_Download_Enabled(void)
//{
//	#define USB_FADDR   ((volatile uint8 *) 0xA0900000)
//    return ((*USB_FADDR & 0x7F) != 0);
//}

void GPS_UART_SetBaudRate(uint8 baud_rate)
{

#ifdef PLUTO_DA_INIT_MPLL_UART
	// if MT6208 do not change baudrate, just increase timeout threshold
	err_threshold = 0x3FFFFC;
	return;
#else
	uint16 tmp;
	uint16 LCR;
	uint16 divisor;
	uint16 rate_step;
	uint16 sample_count;
	uint16 sample_point;
	int32 ext_clock;
	BL_PRINT(LOG_DEBUG, "[FUNET]In SetBaudRate\n\r");
	/* kailing supply API */
	//if(USB_Download_Enabled() == TRUE)
	//	ext_clock = EXT_26M;
	//else
	#if defined(DRV_UART_CLOCK_52M)
	
	BL_PRINT(LOG_DEBUG, "[FUNET]Ext_clock = 4\n\r");
		ext_clock = 4;
	#else
	BL_PRINT(LOG_DEBUG, "[FUNET]Ext_clock = 2\n\r");
		ext_clock = 2;
	#endif

	BL_PRINT(LOG_DEBUG, "[FUNET]Enter Delay\n\r");
	// wait for sent data flush out
	GPS_UART_Delay();
	BL_PRINT(LOG_DEBUG, "[FUNET]out Delay\n\r");
	//high spped configuration, only support for 6205B/6218
	if( baud_rate <=3 )   //high speed
	{
		BL_PRINT(LOG_DEBUG, "[FUNET]high speed\n\r");

		{

             #if defined(FPGA_TEST_ONLY)
			 #if defined(MT6276) || defined(MT6256) ||defined(MT6255) ||defined(MT6250) ||defined(MT6260) ||defined(MT6261) ||defined(MT6280)
			       // Test FPGA only because of the FPGA clock is not always the same as real chip
			       // It depends on the UART clock on FGPA which could be 4MHz/6MHz/12MHz/...
			       // highspeed_baudrate_table_FPGA[0] is for 12MHz UART clock
			 BL_PRINT(LOG_DEBUG, "[FUNET]Flag1\n\r");
				rate_step 		= highspeed_baudrate_table_FPGA[0][baud_rate-1][0];
				sample_count 	= highspeed_baudrate_table_FPGA[0][baud_rate-1][2];
				sample_point 	= highspeed_baudrate_table_FPGA[0][baud_rate-1][3];
				divisor 		= highspeed_baudrate_table_FPGA[0][baud_rate-1][1];
			  #endif
              #endif          
			  #if defined(MT6261)
			  BL_PRINT(LOG_DEBUG, "[FUNET]Flag2\n\r");
				rate_step 		= highspeed_baudrate_table_MT6225[ext_clock-1][baud_rate-1][0];
				sample_count 	= highspeed_baudrate_table_MT6225[ext_clock-1][baud_rate-1][2];
				sample_point 	= highspeed_baudrate_table_MT6225[ext_clock-1][baud_rate-1][3];

				divisor 		= highspeed_baudrate_table_MT6225[ext_clock-1][baud_rate-1][1];
			#endif
			// MUST set DLAB to 1 for config UART2_DLL baudrate divisor
			BL_PRINT(LOG_DEBUG, "[FUNET]Flag3\n\r");
			LCR = UART_ReadReg(UART2_LCR);		/* DLAB start */
			UART_WriteReg(UART2_LCR, (LCR | UART_LCR_DLAB));
			BL_PRINT(LOG_DEBUG, "[FUNET]Flag4\n\r");
			// UART2_DLL
			UART_WriteReg(UART2_DLL, divisor);
			// UART2_DLH
			UART_WriteReg(UART2_DLH, 0x00);
			BL_PRINT(LOG_DEBUG, "[FUNET]Flag5\n\r");
			// restore DLAB to 0
			UART_WriteReg(UART2_LCR, LCR);		/* DLAB End */

			err_threshold = 0x1FFFFE;
			//err_threshold = 0xFFFFF;
		}
	}
	else  //normal speed
	{
		// multiple by external clock
		BL_PRINT(LOG_DEBUG, "[FUNET]Normal speed\n\r");
        divisor = baudrate[baud_rate-1] * ext_clock;

		LCR = UART_ReadReg(UART2_LCR);		/* DLAB start */
		UART_WriteReg(UART2_LCR,(LCR | UART_LCR_DLAB));
		BL_PRINT(LOG_DEBUG, "[FUNET]Flag6\n\r");
		tmp = (divisor & 0x00ff);
		UART_WriteReg(UART2_DLL,tmp);
		tmp = (divisor & 0xff00);
		tmp >>= 8;
		UART_WriteReg(UART2_DLH,tmp);
		UART_WriteReg(UART2_LCR,LCR);		/* DLAB End */
		BL_PRINT(LOG_DEBUG, "[FUNET]Flag7\n\r");

		err_threshold = 0xFFFFF;
	}
	BL_PRINT(LOG_DEBUG, "[FUNET]Flag8\n\r");

	// setup TX/RX to max FIFO and purge FIFO
	UART_WriteReg(UART2_FCR, UART_FCR_MaxFIFO);
	BL_PRINT(LOG_DEBUG, "[FUNET]Flag9\n\r");

	// wait for baudrate change
	GPS_UART_Delay();
#endif
BL_PRINT(LOG_DEBUG, "[FUNET]Out SetBaudRate\n\r");

}
