/*******************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2003
 *
 ******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  brom_mt3301.cpp
 *
 * Project:
 * --------
 *  BootRom Library
 *
 * Description:
 * ------------
 *  BootRom class for MT3301
 *
 *******************************************************************************/
#include <stdio.h>
#include "flashtool.h"
#include "gps_uart.h"
#include "brom_base.h"
#include "SW_TYPES.h"
#include "bl_common.h"
#include "bl_custom.h"



// MT3301 BootRom Start Command
#define MT3301_BOOT_ROM_START_CMD1      0xA0
#define MT3301_BOOT_ROM_START_CMD2      0x0A
#define MT3301_BOOT_ROM_START_CMD3      0x50
#define MT3301_BOOT_ROM_START_CMD4      0x05

#define NMEA_START_CMD1         '$'
#define NMEA_START_CMD2         'P'
#define NMEA_START_CMD3         'M'
#define NMEA_START_CMD4         'T'
#define NMEA_START_CMD5         'K'
#define NMEA_START_CMD6         '1'
#define NMEA_START_CMD7         '8'
#define NMEA_START_CMD8         '0'
#define NMEA_START_CMD9         '*'
#define NMEA_START_CMD10        '3'
#define NMEA_START_CMD11        'B'
#define NMEA_START_CMD12      0x0D
#define NMEA_START_CMD13      0x0A

#define BAUD_CHECK_UPPER_BOUND   7

static const unsigned char MT3301_BOOT_ROM_START_CMD[] =
{
   MT3301_BOOT_ROM_START_CMD1,
   MT3301_BOOT_ROM_START_CMD2,
   MT3301_BOOT_ROM_START_CMD3,
   MT3301_BOOT_ROM_START_CMD4
};                              

static unsigned char NMEA_START_CMD[] =
{
   NMEA_START_CMD1,
   NMEA_START_CMD2,
   NMEA_START_CMD3,
   NMEA_START_CMD4,
   NMEA_START_CMD5,
   NMEA_START_CMD6,
   NMEA_START_CMD7,
   NMEA_START_CMD8,
   NMEA_START_CMD9,
   NMEA_START_CMD10, 
   NMEA_START_CMD11, 
   NMEA_START_CMD12, 
   NMEA_START_CMD13 
};                              
     
//Baud support list by COM API , please check MSDN
//currently we support 115200 , 57600, 38400, 19200, 14400, 9600, 4800
// use for special baud rate
                                
// MT3301 BootRom Base BaudRate
#define MT3301_BOOT_ROM_BASE_BAUDRATE   115200 
                                
// MT3301 Register Address      
#define MT3301_REG_EMI_CON0         0x80010000   // config Bank0 memory 
#define MT3301_REG_EMI_CON1         0x80010004   // config Bank1 memory 
#define MT3301_REG_EMI_CON4         0x80010010   // config memory re-mapping mechanism 
#define MT3301_REG_GPIO_DOUT        0x80120004  // config FT mode 
#define MT3301_REG_RTC_BBPU         0x80210000   // config baseband chip power up 
#define MT3301_REG_RTC_POWERKEY1    0x80210050   // Real-Time-Clock PowerKey 1 
#define MT3301_REG_RTC_POWERKEY2    0x80210054   // Real-Time-Clock PowerKey 2 
#define MT3301_REG_UART_RATE_STEP   0x80130020   // UART highspeed rate step 

// MT3301 Target Start Address
#define MT3301_TARGET_START_ADDR    0x00000000


#define	MAX_SPECIAL_BAUD_RATE	3
#define	DEFAULT_BAUD_RATE		115200

//------------------------------------------------------------------------------
// bootrom start command                                                        
int BRom_StartCmd(GPS_Download_Arg arg)
{
	//example for com driver
	unsigned char data8;
	char buf[1024] = {0};
	unsigned char fail_retry = 0;
	unsigned long i;
	unsigned long Uart_Baud[] = { 115200 , 57600, 38400, 19200, 14400, 9600, 4800};
	volatile unsigned long image_len = 0;
	volatile unsigned long send_bytes = 0;
	volatile unsigned long frame_bytes = 0;
	volatile unsigned long packet_length = 0;
	unsigned char tmp8;
	unsigned long cnt = 0;
	unsigned char debug = 0;

	BL_PRINT(LOG_DEBUG, "[FUNET]Driver Debug \n\r");
	//Set 6261 GPIO19 output high, enable GPS LDO
	*(volatile int *)(0xa0020c28) = 0x00007000;
	*(volatile int *)(0xa0020004) = 0x00080000;
	*(volatile int *)(0xa0020304) = 0x00080000;
	BL_PRINT(LOG_DEBUG, "[FUNET]GPS LDO enable ok \n\r");
	//Set 6261 GPIO18 output 32K clock
	*(volatile int *)(0xa0020c28) = 0x00000700;
	*(volatile int *)(0xa0020c24) = 0x00000300;
	BL_PRINT(LOG_DEBUG, "[FUNET]output 32K clock \n\r");

	GPS_UART_Init();
	GPS_UART_SetBaudRate(4);
	
	BL_PRINT(LOG_DEBUG, "[FUNET]Enable Schmitt trigger \n\r");
	*(volatile int *)(0xa0020604) = 0x00021000;  //Enable Schmitt trigger
	
	BL_PRINT(LOG_DEBUG, "[FUNET]PurgeFIFO \n\r");
	GPS_UART_PurgeFIFO();

	BL_PRINT(LOG_DEBUG, "[FUNET]Delay2 \n\r");

	//Wait 3333 FW initial
	for (i = 0; i < 50; ++i)
	{
		GPS_UART_Delay();
	}
	
	
	BL_PRINT(LOG_DEBUG, "[FUNET]Send PMTK180 to force 3333 into boot rom\n\r");
	//Send PMTK180 to force 3333 into boot rom
	for (i = 1; i < 8; ++i)
	{
	//	GPS_UART_SetBaudRate(i, MT6261);
		GPS_UART_PutByte_Buffer((unsigned long *)NMEA_START_CMD, sizeof(NMEA_START_CMD));
    
	BL_PRINT(LOG_DEBUG, "[FUNET]DELAY3\n\r");
		GPS_UART_Delay();
	}
	
	BL_PRINT(LOG_DEBUG, "[FUNET]DELAY4\n\r");
	//delay, wait for system restart. 
	for (i = 0; i < 10; ++i)
	{
		GPS_UART_Delay();
	}
	BL_PRINT(LOG_DEBUG, "[FUNET]GPS_UART_PurgeFIFO\n\r");
	GPS_UART_PurgeFIFO();
    
	BL_PRINT(LOG_DEBUG, "[FUNET]SEND SYNC CHAR\n\r");
	cnt = 0;
	while(1)
	{
		
		GPS_UART_PutByte(MT3301_BOOT_ROM_START_CMD[0]); //First start command sync char
		if(1 == GPS_UART_GetByte_NO_TIMEOUT(&data8))
		{
			 tmp8 = 0x5F;
			 BL_PRINT(LOG_DEBUG, "[FUNET]Received data:%x \n\r", data8);
			 if(tmp8 == data8)
			 {
					//connCOM.m_COM_PutByte(data8);
					GPS_UART_PurgeFIFO();
					goto SECOND_CHAR;	
			 }
			 else
			 {
				//while(1);
				//connCOM.m_COM_PutByte(data8);
			 }
		}
		
		cnt++;
		data8 = 0xDD;
		//connCOM.m_COM_PutByte(data8);
		if (cnt > 10000)
		{
			data8 = 0xCC;
			//connCOM.m_COM_PutByte(data8);
			break;
		}
	}

	//Use Reset way to sync boot rom
	*(volatile int *)(0xa0020c28) = 0x00000700;  //Close 32K clock to avoid non-sync char received
	GPS_UART_PurgeFIFO();
	debug = 0xC1;
	cnt = 0;
	for (fail_retry = 0; fail_retry < 5; ++fail_retry)
	{
		//Set 6261 GPIO19 output low, disable GPS LDO
		*(volatile int *)(0xa0020c28) = 0x00007000;
		*(volatile int *)(0xa0020004) = 0x00080000;
		*(volatile int *)(0xa0020308) = 0x00080000;
		
		for (i = 0; i < 300; ++i)
		{
			GPS_UART_Delay();
		}

		//Set 6261 GPIO19 output high, enable GPS LDO
		*(volatile int *)(0xa0020c28) = 0x00007000;
		*(volatile int *)(0xa0020004) = 0x00080000;
		*(volatile int *)(0xa0020304) = 0x00080000;
				
		i = 0;
		while(1)
		{
			
			GPS_UART_PutByte(MT3301_BOOT_ROM_START_CMD[0]); //First start command sync char
			if(1 == GPS_UART_GetByte_NO_TIMEOUT(&data8))
			{
				 tmp8 = 0x5F;
				 if(tmp8 == data8)
				 {
					//connCOM.m_COM_PutByte(data8);
					GPS_UART_PurgeFIFO();
					//break;	
					goto SECOND_CHAR;
				 }
				 else
				 {
					//while(1);
					//connCOM.m_COM_PutByte(data8);
				 }
			}
			cnt++;
			//connCOM.m_COM_PutByte(debug);
			if (cnt > 50000)
			{
				//connCOM.m_COM_PutByte(fail_retry);
				debug++;
				cnt = 0;
				if (fail_retry == 4)
				{
					while(1);
				}
				else 
				{
					break;
				}
			}
		}
	}
	
SECOND_CHAR:
	BL_PRINT(LOG_DEBUG, "[FUNET]Sync second char \n\r");

	i = 1;
	GPS_UART_PutByte(MT3301_BOOT_ROM_START_CMD[i]); //2nd sync char
	tmp8 = 0xF5; // ~MT3301_BOOT_ROM_START_CMD[i]
	data8 = GPS_UART_GetByte();
	if(tmp8 != data8)
	{
		//connCOM.m_COM_PutByte(data8);	
		while(1);
	}

	i = 2;
	GPS_UART_PutByte(MT3301_BOOT_ROM_START_CMD[i]); //3rd sync char
	tmp8 = 0xAF;
	data8 = GPS_UART_GetByte();
	if(tmp8 != data8)
	{
		//connCOM.m_COM_PutByte(data8);	
		while(1);
	}

	i = 3;
	GPS_UART_PutByte(MT3301_BOOT_ROM_START_CMD[i]); //4th sync char
	tmp8 = 0xFA;
	data8 = GPS_UART_GetByte();
	if(tmp8 != data8)
	{
		//connCOM.m_COM_PutByte(data8);	
		while(1);
	}

    return 0;
}
//------------------------------------------------------------------------------
// boot FlashTool download mode                                                 
//------------------------------------------------------------------------------
int Boot_FlashTool(const s_BOOT_FLASHTOOL_ARG  *p_arg, GPS_Download_Arg arg)
{   
   // check data
   if( NULL == p_arg )
      return BROM_INVALID_ARGUMENTS;

   //MTRACE(g_hBROM_DEBUG, "Enter BRom_StartCmd");
   BL_PRINT(LOG_DEBUG, "[FUNET]Enter BRom_StartCmd \n\r");

   // send start command 
   if( BRom_StartCmd(arg) )
   {
       return BROM_CMD_START_FAIL;
   }
   BL_PRINT(LOG_DEBUG, "[FUNET]Start Command Sync Done \n\r");

   //MTRACE(g_hBROM_DEBUG, "Start Command Sync Done.");
   
   // wait for 200ms, because of H/W chip limitation
   
   // download DA to target address m_da_start_addr
   //MTRACE(g_hBROM_DEBUG, "Boot_FlashTool: BRom_WriteBuf() ...");
   
   // 0805 who fill these value (p_arg->m_da_start_addr, p_arg->m_da_buf) ???????????

   //Sleep(200);
   
   //strcpy(Dbgbuf, "BRom_WriteBuf\n");
   //fwrite(Dbgbuf, 1, strlen("BRom_WriteBuf\n"), DbgFILE);    
   if(BRom_WriteBuf(arg, p_arg->m_da_start_addr, p_arg->m_da_buf, p_arg->m_da_len))
   {
      return BROM_DOWNLOAD_DA_FAIL;
   }
   //MTRACE(g_hBROM_DEBUG, "Boot_FlashTool: BRom_WriteBuf() Pass!");
   BL_PRINT(LOG_DEBUG, "[FUNET]Boot_FlashTool: BRom_WriteBuf() Pass! \n\r");

   // jump to m_da_start_addr to execute DA code on Internal SRAM 
   //MTRACE(g_hBROM_DEBUG, "Boot_FlashTool: BRom_JumpCmd() ...");
   if(BRom_JumpCmd( arg, p_arg->m_da_start_addr ))
      return BROM_CMD_JUMP_FAIL;
   //MTRACE(g_hBROM_DEBUG, "Boot_FlashTool: BRom_JumpCmd() Pass!");
   //strcpy(Dbgbuf, "Boot_FlashTool: BRom_JumpCmd() Pass!\n");
   //fwrite(Dbgbuf, 1, strlen("Boot_FlashTool: BRom_JumpCmd() Pass!\n"), DbgFILE);    
   BL_PRINT(LOG_DEBUG, "[FUNET]Boot_FlashTool: BRom_JumpCmd() Pass! \n\r");
   return BROM_OK;
}
//------------------------------------------------------------------------------
