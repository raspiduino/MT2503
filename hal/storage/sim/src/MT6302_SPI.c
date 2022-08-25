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
 * MT6302_interface.C
 *
 * Project:
 * --------
 *   Gemini
 *
 * Description:
 * ------------
 *   this file is to be adaption layer for different SPI implementation
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef DRV_SIM_OFF
#include	"drv_comm.h"
#include	"reg_base.h"
//#include	"gpio_sw.h"
#include    "sim_reg_adp.h"
#include    "drv_sw_features_display.h"
#include	"MT6302_spi.h"
#include	"lcd_if_hw.h"
#include	"lcd_if.h"
//#include  "..\..\ps\sim\include\sim_trc.h"
#include "sim_trc.h"  //mtk02374
#if defined(__DRV_SIM_TP_SHARE_PIN__)
#include	"touch_panel_spi.h"
#endif  // #if defined(__DRV_SIM_TP_SHARE_PIN__)
#include "lcd_if_manager.h"
#include "dcl.h"
#include "lcd_power_mgr.h"
/*following decalration were moved from gpio_sw.h*, we should change them to dcl form eventually*/
extern char GPIO_ReturnMode(char port);
extern char GPIO_ReturnDir(char port);
extern char GPIO_ReturnDout(char port);


#if  (defined(DRV_MULTIPLE_SIM) && !defined(DRV_2_SIM_CONTROLLER)) || (defined(__SIM_DRV_MULTI_DRV_ARCH__))
//extern sim_MT6302_SPIWriter	sim_MT6320_writer;
extern kal_uint32 MT6302_getLCDSerialInterface(kal_uint32 MT6302Interface);
extern kal_uint32 MT6302_getSPIInterface(kal_uint32 MT6302Interface);
extern kal_bool MT6302_checkSPIMode(kal_uint32 MT6302Interface);
extern kal_uint32 MT6302_getGPIOCLK(kal_uint32 MT6302Interface);
extern kal_uint32 MT6302_getGPIOCS(kal_uint32 MT6302Interface);
extern kal_uint32 MT6302_getGPIODAT(kal_uint32 MT6302Interface);
extern void lcd_clk_disable( kal_uint8 handle );
extern void lcd_clk_enable( kal_uint8 handle );
//extern kal_uint8 lcd_get_power_handle(void);

#define IMPLEMENTING_ASSERT	ASSERT(0)
#define SIM_REMOVE_LCD_PDN_DBG_CODE

kal_uint8		MT6302_LCD_dummyReadValue;

sim_MT6302_SPIInfo SIM_MT6302_spi_cb[SIM_MT6302_MAX_MT6302];

#ifdef DRV_SIM_GEMINI_ON_LOW_SPEED_PLATFORM
kal_uint8	MT6302_GPIO_dmaHandle;
#endif

#if defined(__DRV_SIM_TP_SHARE_PIN__)
extern kal_bool FlagDisablePENIRQ;
#endif // #if defined(__DRV_SIM_TP_SHARE_PIN__)

void MT6302_Writer_LCD(kal_uint32 chipNo, kal_uint8 data)
{
	kal_uint32 i;
	kal_uint32 MT6302_SPI_LCDSerialData;


	MT6302_SPI_LCDSerialData = SIM_MT6302_spi_cb[chipNo].MT6302_SPI_LCDSerialData;
	if(0 != MT6302_getSPIInterface(chipNo))
		ASSERT(0);

	i = SaveAndSetIRQMask();
#ifdef __OLD_PDN_ARCH__
#ifndef SIM_REMOVE_LCD_PDN_DBG_CODE
	if(DRVPDN_CON1_LCD & SIM_Reg(DRVPDN_CON1)){
		 RestoreIRQMask(i);
		ASSERT(0);
	}
#endif

#ifdef MT6253
	if(0x400c != REG_LCD_SERIAL_CONFIG)
#else
	if(0xc != REG_LCD_SERIAL_CONFIG)
#endif
	{
		 RestoreIRQMask(i);
		ASSERT(0);
	}

	if(KAL_FALSE == MT6302_checkSPIMode(chipNo)){
		RestoreIRQMask(i);
		ASSERT(0);
	}
#endif

	/*	becareful that SW will hang on here until LCD controller return RDY signal on bus
	*	accoring to the measurement, in the slowest timing setting, LCD takes 2us to send on byte
	*/
	 //SIM_Reg8(MT6302_SPI_LCDSerialData) = data;
	 SIM_WriteReg8((MT6302_SPI_LCDSerialData), data);

	/*dummy read to make sure former byte has been written on SPI*/
	MT6302_LCD_dummyReadValue = SIM_Reg8(MT6302_SPI_LCDSerialData);

	 RestoreIRQMask(i);
}

#ifndef DRV_SIM_GEMINI_ON_LOW_SPEED_PLATFORM
void MT6302_Writer_GPIO(kal_uint32 chipNo, kal_uint8 data)
{
	kal_uint32 i, j;
	kal_uint8 	MT6302_CS_PIN, MT6302_CLK_PIN, MT6302_DAT_PIN;
	DCL_HANDLE clkHandle, datHandle, csHandle;
	DCL_CTRL_DATA_T spiClk, spiDat, spiCs;

	i = SaveAndSetIRQMask();

	if(KAL_FALSE == MT6302_checkSPIMode(chipNo)){
		RestoreIRQMask(i);
		// some states of 3 SPI pins don't match our expectation.
		ASSERT(0);
	}

	MT6302_CS_PIN=MT6302_getGPIOCS(chipNo);
	MT6302_CLK_PIN=MT6302_getGPIOCLK(chipNo);
	MT6302_DAT_PIN=MT6302_getGPIODAT(chipNo);

	datHandle = DclGPIO_Open(DCL_GPIO, MT6302_DAT_PIN);
	DclGPIO_Control(datHandle,GPIO_CMD_SET_DIR_OUT,0);	
	clkHandle = DclGPIO_Open(DCL_GPIO, MT6302_CLK_PIN);
	csHandle = DclGPIO_Open(DCL_GPIO, MT6302_CS_PIN);

	/*since we will call GPIO_WriteIO_fast. we should remove the magic number here*/
	MT6302_CS_PIN &= 0x7f;
	MT6302_CLK_PIN &= 0x7f;
	MT6302_DAT_PIN &= 0x7f;

	spiClk.rWriteSpi.remainder_shift = 1<<(MT6302_CLK_PIN%16);
	spiClk.rWriteSpi.no = MT6302_CLK_PIN/16;
	spiDat.rWriteSpi.remainder_shift = 1<<(MT6302_DAT_PIN%16);
	spiDat.rWriteSpi.no = MT6302_DAT_PIN/16;
	spiCs.rWriteSpi.remainder_shift = 1<<(MT6302_CS_PIN%16);
	spiCs.rWriteSpi.no = MT6302_CS_PIN/16;

	/*MT6302 latch SPI command on CLK rising edge, we have park clk to low or there will be race conditions*/
	spiClk.rWriteSpi.data = 0;
	DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_LOW,&spiClk);
//	GPIO_WriteIO(0, MT6302_CLK_PIN);
	spiCs.rWriteSpi.data = 0;
	DclGPIO_Control(csHandle,GPIO_CMD_WRITE_LOW,&spiCs);
//	GPIO_WriteIO(0, MT6302_CS_PIN);
	for(j=8;j>0;j--)
	{
		if(data&(0x1<<(j-1)))
		{
			spiDat.rWriteSpi.data = 1;
			DclGPIO_Control(datHandle,GPIO_CMD_WRITE_HIGH,&spiDat);		
//			GPIO_WriteIO(1, MT6302_DAT_PIN);
		}
		else
		{
			spiDat.rWriteSpi.data = 0;
			DclGPIO_Control(datHandle,GPIO_CMD_WRITE_LOW,&spiDat);
//			GPIO_WriteIO(0, MT6302_DAT_PIN);
		}

		spiClk.rWriteSpi.data = 1;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_HIGH,&spiClk);
		spiClk.rWriteSpi.data = 0;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_LOW,&spiClk);
//		GPIO_WriteIO(1, MT6302_CLK_PIN);
//		GPIO_WriteIO(0, MT6302_CLK_PIN);
	}
	spiDat.rWriteSpi.data = 0;
	DclGPIO_Control(datHandle,GPIO_CMD_WRITE_LOW,&spiDat);
//	GPIO_WriteIO(0, MT6302_DAT_PIN);
	spiCs.rWriteSpi.data = 1;
	DclGPIO_Control(csHandle,GPIO_CMD_WRITE_HIGH,&spiCs);
//	GPIO_WriteIO(1, MT6302_CS_PIN);

	DclGPIO_Close(datHandle);
	DclGPIO_Close(clkHandle);
	DclGPIO_Close(csHandle);

	RestoreIRQMask(i);
}
#else
void MT6302_Writer_GPIO(kal_uint8 data)
{
	kal_uint32 i;
	kal_uint8 	MT6302_CS_PIN, MT6302_CLK_PIN, MT6302_DAT_PIN;
	kal_uint16	no_cs, no_clk, no_dat;
	kal_uint16	remainder_cs, remainder_clk, remainder_dat;
	DCL_HANDLE clkHandle, datHandle, csHandle;
	DCL_CTRL_DATA_T spiClk, spiDat, spiCs;

#if defined(__DRV_SIM_TP_SHARE_PIN__)
    kal_uint8 TP_SPI_CS_PIN;
    kal_uint16 no_tp_cs, remainder_tp_cs;
#endif // #if defined(__DRV_SIM_TP_SHARE_PIN__)

	//i = SaveAndSetIRQMask();

	if(KAL_FALSE == MT6302_checkSPIMode()){
		// some states of 3 SPI pins don't match our expectation.
		ASSERT(0);
	}


	MT6302_CS_PIN=MT6302_getGPIOCS();
	MT6302_CLK_PIN=MT6302_getGPIOCLK();
	MT6302_DAT_PIN=MT6302_getGPIODAT();

	/*since we will call GPIO_WriteIO_fast. we should remove the magic number here*/
	MT6302_CS_PIN &= 0x7f;
	MT6302_CLK_PIN &= 0x7f;
	MT6302_DAT_PIN &= 0x7f;

	datHandle = DclGPIO_Open(DCL_GPIO, MT6302_DAT_PIN);
	DclGPIO_Control(datHandle,GPIO_CMD_SET_DIR_OUT,0);

	clkHandle = DclGPIO_Open(DCL_GPIO, MT6302_CLK_PIN);

	csHandle = DclGPIO_Open(DCL_GPIO, MT6302_CS_PIN);

	spiClk.rWriteSpi.remainder_shift = 1<<(MT6302_CLK_PIN%16);
	spiClk.rWriteSpi.no = MT6302_CLK_PIN/16;
	spiDat.rWriteSpi.remainder_shift = 1<<(MT6302_DAT_PIN%16);
	spiDat.rWriteSpi.no = MT6302_DAT_PIN/16;
	spiCs.rWriteSpi.remainder_shift = 1<<(MT6302_CS_PIN%16);
	spiCs.rWriteSpi.no = MT6302_CS_PIN/16;

#if defined(__DRV_SIM_TP_SHARE_PIN__)
    TP_SPI_CS_PIN = (SPI_CS_PIN);
    TP_SPI_CS_PIN &= 0x7f;

    remainder_tp_cs = 1<<(TP_SPI_CS_PIN%16);
	no_tp_cs = TP_SPI_CS_PIN/16;
#endif // #if defined(__DRV_SIM_TP_SHARE_PIN__)

	dma_slowdown(MT6302_GPIO_dmaHandle);
	i = SaveAndSetIRQMask();

#if defined(__DRV_SIM_TP_SHARE_PIN__)
    if(!FlagDisablePENIRQ)
    {
		 spiCs.rWriteSpi.data = 1;
		 DclGPIO_Control(csHandle,GPIO_CMD_WRITE_FOR_SPI,&spiCs);
//        GPIO_WriteIO_FAST2(1, no_tp_cs, remainder_tp_cs);
    }
#endif // #if defined(__DRV_SIM_TP_SHARE_PIN__)

    	/*MT6302 latch SPI command on CLK rising edge, we have park clk to low or there will be race conditions*/
	spiClk.rWriteSpi.data = 0;
	DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);
//	GPIO_WriteIO_FAST2(0, no_clk, remainder_clk);
	spiCs.rWriteSpi.data = 0;
	DclGPIO_Control(csHandle,GPIO_CMD_WRITE_FOR_SPI,&spiCs);
//	GPIO_WriteIO_FAST2(0, no_cs, remainder_cs);

	{
		/*bit 8*/
		spiDat.rWriteSpi.data = (data>>7) & 0x01;
		DclGPIO_Control(datHandle,GPIO_CMD_WRITE_FOR_SPI,&spiDat);
		spiClk.rWriteSpi.data = 1;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);
		spiClk.rWriteSpi.data = 0;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);

//		GPIO_WriteIO_FAST2((data>>7) & 0x01, no_dat, remainder_dat);
//		GPIO_WriteIO_FAST2(1, no_clk, remainder_clk);
//		GPIO_WriteIO_FAST2(0, no_clk, remainder_clk);

		/*bit 7*/
		spiDat.rWriteSpi.data = (data>>6) & 0x01;
		DclGPIO_Control(datHandle,GPIO_CMD_WRITE_FOR_SPI,&spiDat);
		spiClk.rWriteSpi.data = 1;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);
		spiClk.rWriteSpi.data = 0;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);

//		GPIO_WriteIO_FAST2((data>>6) & 0x01, no_dat, remainder_dat);
//		GPIO_WriteIO_FAST2(1, no_clk, remainder_clk);
//		GPIO_WriteIO_FAST2(0, no_clk, remainder_clk);

		/*bit 6*/
		spiDat.rWriteSpi.data = (data>>5) & 0x01;
		DclGPIO_Control(datHandle,GPIO_CMD_WRITE_FOR_SPI,&spiDat);
		spiClk.rWriteSpi.data = 1;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);
		spiClk.rWriteSpi.data = 0;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);

//		GPIO_WriteIO_FAST2((data>>5) & 0x01, no_dat, remainder_dat);
//		GPIO_WriteIO_FAST2(1, no_clk, remainder_clk);
//		GPIO_WriteIO_FAST2(0, no_clk, remainder_clk);

		/*bit 5*/
		spiDat.rWriteSpi.data = (data>>4) & 0x01;
		DclGPIO_Control(datHandle,GPIO_CMD_WRITE_FOR_SPI,&spiDat);
		spiClk.rWriteSpi.data = 1;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);
		spiClk.rWriteSpi.data = 0;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);

//		GPIO_WriteIO_FAST2((data>>4) & 0x01, no_dat, remainder_dat);
//		GPIO_WriteIO_FAST2(1, no_clk, remainder_clk);
//		GPIO_WriteIO_FAST2(0, no_clk, remainder_clk);

		/*bit 4*/
		spiDat.rWriteSpi.data = (data>>3) & 0x01;
		DclGPIO_Control(datHandle,GPIO_CMD_WRITE_FOR_SPI,&spiDat);
		spiClk.rWriteSpi.data = 1;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);
		spiClk.rWriteSpi.data = 0;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);

//		GPIO_WriteIO_FAST2((data>>3) & 0x01, no_dat, remainder_dat);
//		GPIO_WriteIO_FAST2(1, no_clk, remainder_clk);
//		GPIO_WriteIO_FAST2(0, no_clk, remainder_clk);

		/*bit 3*/
		spiDat.rWriteSpi.data = (data>>2) & 0x01;
		DclGPIO_Control(datHandle,GPIO_CMD_WRITE_FOR_SPI,&spiDat);
		spiClk.rWriteSpi.data = 1;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);
		spiClk.rWriteSpi.data = 0;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);

//		GPIO_WriteIO_FAST2((data>>2) & 0x01, no_dat, remainder_dat);
//		GPIO_WriteIO_FAST2(1, no_clk, remainder_clk);
//		GPIO_WriteIO_FAST2(0, no_clk, remainder_clk);

		/*bit 2*/
		spiDat.rWriteSpi.data = (data>>1) & 0x01;
		DclGPIO_Control(datHandle,GPIO_CMD_WRITE_FOR_SPI,&spiDat);
		spiClk.rWriteSpi.data = 1;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);
		spiClk.rWriteSpi.data = 0;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);

//		GPIO_WriteIO_FAST2((data>>1) & 0x01, no_dat, remainder_dat);
//		GPIO_WriteIO_FAST2(1, no_clk, remainder_clk);
//		GPIO_WriteIO_FAST2(0, no_clk, remainder_clk);

		/*bit 1*/
		spiDat.rWriteSpi.data = data & 0x01;
		DclGPIO_Control(datHandle,GPIO_CMD_WRITE_FOR_SPI,&spiDat);
		spiClk.rWriteSpi.data = 1;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);
		spiClk.rWriteSpi.data = 0;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);

//		GPIO_WriteIO_FAST2(data & 0x01, no_dat, remainder_dat);
//		GPIO_WriteIO_FAST2(1, no_clk, remainder_clk);
//		GPIO_WriteIO_FAST2(0, no_clk, remainder_clk);
	}

	spiDat.rWriteSpi.data = 0;
	DclGPIO_Control(datHandle,GPIO_CMD_WRITE_FOR_SPI,&spiDat);
	spiCs.rWriteSpi.data = 1;
	DclGPIO_Control(csHandle,GPIO_CMD_WRITE_FOR_SPI,&spiCs);

//	GPIO_WriteIO_FAST2(0, no_dat, remainder_dat);
//	GPIO_WriteIO_FAST2(1, no_cs, remainder_cs);

#if defined(__DRV_SIM_TP_SHARE_PIN__)
    if(!FlagDisablePENIRQ)
    {
		 spiCs.rWriteSpi.data = 0;
		 DclGPIO_Control(csHandle,GPIO_CMD_WRITE_FOR_SPI,&spiCs);
//        GPIO_WriteIO_FAST2(0, no_tp_cs, remainder_tp_cs);
    }
#endif // #if defined(__DRV_SIM_TP_SHARE_PIN__)

	DclGPIO_Close(datHandle);
	DclGPIO_Close(clkHandle);
	DclGPIO_Close(csHandle);

	RestoreIRQMask(i);
	dma_recover(MT6302_GPIO_dmaHandle);
}
#endif

/*
	This is the new MT6302 SPI implementation.
	This API will be used when the SPI is implemented by 3 dedicated GPIO.
	In this function, we will not disable i-bit
*/
void MT6302_Writer_dedicated_GPIO(kal_uint32 chipNo, kal_uint8 data)
{
	kal_uint32 j;
	kal_uint8 	MT6302_CS_PIN, MT6302_CLK_PIN, MT6302_DAT_PIN;
	DCL_HANDLE clkHandle, datHandle, csHandle;
	DCL_CTRL_DATA_T spiClk, spiDat, spiCs;

	if(KAL_FALSE == MT6302_checkSPIMode(chipNo)){
		// some states of 3 SPI pins don't match our expectation.
		ASSERT(0);
	}

	MT6302_CS_PIN=MT6302_getGPIOCS(chipNo);
	MT6302_CLK_PIN=MT6302_getGPIOCLK(chipNo);
	MT6302_DAT_PIN=MT6302_getGPIODAT(chipNo);

	datHandle = DclGPIO_Open(DCL_GPIO, MT6302_DAT_PIN);
	DclGPIO_Control(datHandle,GPIO_CMD_SET_DIR_OUT,0);

	clkHandle = DclGPIO_Open(DCL_GPIO, MT6302_CLK_PIN);

	csHandle = DclGPIO_Open(DCL_GPIO, MT6302_CS_PIN);

	spiClk.rWriteSpi.remainder_shift = 1<<(MT6302_CLK_PIN%16);
	spiClk.rWriteSpi.no = MT6302_CLK_PIN/16;
	spiDat.rWriteSpi.remainder_shift = 1<<(MT6302_DAT_PIN%16);
	spiDat.rWriteSpi.no = MT6302_DAT_PIN/16;
	spiCs.rWriteSpi.remainder_shift = 1<<(MT6302_CS_PIN%16);
	spiCs.rWriteSpi.no = MT6302_CS_PIN/16;

	/*MT6302 latch SPI command on CLK rising edge, we have park clk to low or there will be race conditions*/
	spiClk.rWriteSpi.data = 0;
	DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_LOW,&spiClk);
//	GPIO_WriteIO(0, MT6302_CLK_PIN);
	spiCs.rWriteSpi.data = 0;
	DclGPIO_Control(csHandle,GPIO_CMD_WRITE_LOW,&spiCs);
//	GPIO_WriteIO(0, MT6302_CS_PIN);
	for(j=8;j>0;j--)
	{
		if(data&(0x1<<(j-1)))
		{
			spiDat.rWriteSpi.data = 1;
			DclGPIO_Control(datHandle,GPIO_CMD_WRITE_HIGH,&spiDat);
//	GPIO_WriteIO(1, MT6302_DAT_PIN);
		}
		else
		{
			spiDat.rWriteSpi.data = 0;
			DclGPIO_Control(datHandle,GPIO_CMD_WRITE_LOW,&spiDat);
//GPIO_WriteIO(0, MT6302_DAT_PIN);
      }
		spiClk.rWriteSpi.data = 1;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_HIGH,&spiClk);
		spiClk.rWriteSpi.data = 0;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_LOW,&spiClk);

//GPIO_WriteIO(1, MT6302_CLK_PIN);
//GPIO_WriteIO(0, MT6302_CLK_PIN);
	}
	spiDat.rWriteSpi.data = 0;
	DclGPIO_Control(datHandle,GPIO_CMD_WRITE_LOW,&spiDat);
	spiCs.rWriteSpi.data = 1;
	DclGPIO_Control(csHandle,GPIO_CMD_WRITE_HIGH,&spiCs);

//GPIO_WriteIO(0, MT6302_DAT_PIN);
//GPIO_WriteIO(1, MT6302_CS_PIN);
	DclGPIO_Close(datHandle);
	DclGPIO_Close(clkHandle);
	DclGPIO_Close(csHandle);
}

void MT6302_spiPowerCtrl(kal_uint32 chipNo, kal_bool on)
{
	kal_uint32 i;
	kal_uint32 MT6302_LCD_pdnHandle;

	MT6302_LCD_pdnHandle = SIM_MT6302_spi_cb[chipNo].MT6302_LCD_pdnHandle;
	if(0 == MT6302_getSPIInterface(chipNo))
	{
#if !defined(DRV_LCD_NOT_EXIST) && !defined(MT6251)
		if(31 < MT6302_LCD_pdnHandle)
			ASSERT(0);

		if (KAL_FALSE == on){
#if defined(DRV_DISPLAY_DRIVER_V2)
			lcd_power_ctrl__disable(MT6302_LCD_pdnHandle);
#else
			lcd_clk_disable(MT6302_LCD_pdnHandle);
#endif
		}
		else if(KAL_TRUE == on){
#if defined(DRV_DISPLAY_DRIVER_V2)
			lcd_power_ctrl__enable(MT6302_LCD_pdnHandle);
#else
			lcd_clk_enable(MT6302_LCD_pdnHandle);
#endif
		
#ifdef __OLD_PDN_ARCH__
#ifndef SIM_REMOVE_LCD_PDN_DBG_CODE
			if(DRVPDN_CON1_LCD & SIM_Reg(DRVPDN_CON1))
				ASSERT(0);
#endif
#endif
			i = 1000;
			while(i)
				i--;
		}
	else
		ASSERT(0);
#else //DRV_LCD_NOT_EXIST
			ASSERT(0);
#endif //DRV_LCD_NOT_EXIST

	}
	else if(1 == MT6302_getSPIInterface(chipNo) || 2 == MT6302_getSPIInterface(chipNo))
	{
		/*we don't know should we do power control before want to write SPI in GPIO implementation*/
	}
	else{
		IMPLEMENTING_ASSERT;
	}

#ifdef __OLD_PDN_ARCH__
#ifndef SIM_REMOVE_LCD_PDN_DBG_CODE
	drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_MT6302_SPI, __LINE__,
		on, SIM_Reg(DRVPDN_CON1), MT6302_getSPIInterface(chipNo), MT6302_LCD_pdnHandle,
		drv_get_current_time(), 0
	);
#endif
#endif

}


MT6302_SPI_LCDHandlerInit(kal_uint32 serialLCDNo, kal_uint32 *LCDSerialDataAddr)
{
	// ===== MT6253 =====
	// declaration
	kal_uint32 _lcd_if_mgr_serial_handle;
	LCD_IOCTRL_DEVICE_IF_T _lcd_if_mgr_serial_setting;
	LCD_IOCTRL_RESULT_E err;

	// get handle
	_lcd_if_mgr_serial_handle = lcd_get_ioctrl_device_if_handle(LCD_IF_USER_SIM);

	// query the main lcd if settings
	_lcd_if_mgr_serial_setting.if_type = LCD_IF_TYPE_DBI_SERIAL; // according to real HW layout
	_lcd_if_mgr_serial_setting.if_cs_no = serialLCDNo; // according to real HW layout
	err = lcd_ioctrl_device_if_settings(_lcd_if_mgr_serial_handle, LCD_IOCTRL_QUERY_DEVICE_IF, &_lcd_if_mgr_serial_setting, sizeof(_lcd_if_mgr_serial_setting));
	// do error handling if(err != LCD_IOCTRL_OK);
	if(err != LCD_IOCTRL_OK)
		ASSERT(0);

	// let interface user can write port directly and most effectively w/o any SW function call overhead.
	// port address are as below
	// _lcd_if_mgr_serial_setting.dbi_serial_if.if_cmd_port_addr
	// _lcd_if_mgr_serial_setting.dbi_serial_if.if_data_port_addr

	// modify the necessary part only
	//Blue : keep default setting
	_lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.if_each_trans_length = 8;
	_lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.if_3wire_mode = KAL_FALSE;
	// target is 26MHz/4
	if(_lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.if_is_set_clk_by_scl_counts)
	{
		// 52MHz/8 = 26MHz/4
		_lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.scl_wt_low_count = 8;
		_lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.scl_wt_high_count = 8;
		_lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.scl_rd_low_count = 8;
		_lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.scl_rd_high_count = 8;
	}
	else
	{
		// MT6253 run here
		_lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.if_clk_freq = 13*1000*1000;
		_lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.if_clk_divider = 16;
	}

	if(_lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.if_is_sw_cs_ctrl)
	{
		// MT6258H/58 run here
		// if_sw_cs_ctrl_reg_addr; // valid when if_is_sw_cs_ctrl is KAL_TRUE. You must turn on lcd power before access reg addr
		// if_sw_cs_ctrl_reg_bit; // valid when if_is_sw_cs_ctrl is KAL_TRUE. You must set or reset bit on if_sw_cs_ctrl_reg_addr
		// just set or reset bit on register address of if_sw_cs_ctrl_reg_addr to HIGH or LOW external lcd chip select pin
	}



	// re-configure modified settings
	err = lcd_ioctrl_device_if_settings(_lcd_if_mgr_serial_handle, LCD_IOCTRL_CONFIG_DEVICE_IF, &_lcd_if_mgr_serial_setting, sizeof(_lcd_if_mgr_serial_setting));
	// do error handling if(err != LCD_IOCTRL_OK);
	if(err != LCD_IOCTRL_OK)
		ASSERT(0);

	* LCDSerialDataAddr = _lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.if_data_port_addr;

}

kal_uint32 MT6302_initDelayTime;

//#define OLD_LCD_INTERFACE

void MT6302_spiInit(sim_MT6302_SPIWriter *spiWritePtr, kal_uint32 chipNo)
{
	kal_uint32 i, j;

	if(0 == MT6302_getSPIInterface(chipNo)){ //MT6302_SPI_USE_LCD
#if !defined(DRV_LCD_NOT_EXIST) && !defined(MT6251)

		//power on LCD module

#if defined(DRV_FEATURE__MM_POWER_CTRL_IF)
#include "mm_power_ctrl.h"
        mm_enable_power(MMPWRMGR_LCD);
#else

#include "drvpdn.h"

#if defined(__OLD_PDN_ARCH__) || defined(__OLD_PDN_DEFINE__)
		SIM_WriteReg(DRVPDN_CON1_CLR, DRVPDN_CON1_LCD);
#else
		PDN_CLR(PDN_LCD); // power on LCD
                #error ¡§should not compile here¡¨
#endif //defined(__OLD_PDN_ARCH__) || defined(__OLD_PDN_DEFINE__)

#endif //defined(DRV_FEATURE__MM_POWER_CTRL_IF)

		j = drv_get_current_time();
		for(i=3000;i > 0; i--);

		MT6302_initDelayTime = drv_get_duration_tick(j, drv_get_current_time());

		i = SaveAndSetIRQMask();
		*spiWritePtr = (sim_MT6302_SPIWriter)MT6302_Writer_LCD;
#if defined(DRV_DISPLAY_DRIVER_V2)
                SIM_MT6302_spi_cb[chipNo].MT6302_LCD_pdnHandle =  lcd_power_ctrl__register_module();
#else
		SIM_MT6302_spi_cb[chipNo].MT6302_LCD_pdnHandle = lcd_get_power_handle();
		if(31 < SIM_MT6302_spi_cb[chipNo].MT6302_LCD_pdnHandle){
			RestoreIRQMask(i);
			ASSERT(0);
		}
#endif
		RestoreIRQMask(i);


#ifdef OLD_LCD_INTERFACE

		/*config serial interface*/
#ifdef MT6253
		REG_LCD_SERIAL_CONFIG = 0x400C;
		*((volatile unsigned short *) (0x90000020)) = 0x2;
#else
		REG_LCD_SERIAL_CONFIG = 0xC;
#endif


		switch(MT6302_getLCDSerialInterface(chipNo)){
			case 0:
				SIM_MT6302_spi_cb[chipNo].MT6302_SPI_LCDSerialData = LCD_SERIAL_DATA0_REG;
				break;
			case 1:
				SIM_MT6302_spi_cb[chipNo].MT6302_SPI_LCDSerialData = LCD_SERIAL_DATA1_REG;
				break;
			default:
				ASSERT(0);
				break;
		}
#else	//OLD_LCD_INTERFACE
		 MT6302_SPI_LCDHandlerInit(MT6302_getLCDSerialInterface(chipNo), &SIM_MT6302_spi_cb[chipNo].MT6302_SPI_LCDSerialData);
#endif //OLD_LCD_INTERFACE

#ifdef __OLD_PDN_ARCH__
#ifndef SIM_REMOVE_LCD_PDN_DBG_CODE
		drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_MT6302_SPI, __LINE__,
			MT6302_getSPIInterface(chipNo), SIM_Reg(DRVPDN_CON1), REG_LCD_SERIAL_CONFIG, SIM_MT6302_spi_cb[chipNo].MT6302_SPI_LCDSerialData,
			*spiWritePtr, SIM_MT6302_spi_cb[chipNo].MT6302_LCD_pdnHandle
		);
#endif
#endif

#else
		ASSERT(0);
#endif //DRV_LCD_NOT_EXIST
	}
	else if(1 == MT6302_getSPIInterface(chipNo)){//MT6302_SPI_USE_GPIO
		*spiWritePtr = (sim_MT6302_SPIWriter)MT6302_Writer_GPIO;
		if((0xff == MT6302_getGPIOCS(chipNo)) || (0xff == MT6302_getGPIOCLK(chipNo)) || (0xff == MT6302_getGPIODAT(chipNo)))
			ASSERT(0);

#ifdef DRV_SIM_GEMINI_ON_LOW_SPEED_PLATFORM
		MT6302_GPIO_dmaHandle = dma_slowdown_get_handle();
#endif
	}
	else if(2 == MT6302_getSPIInterface(chipNo)){//MT6302_SPI_USE_DEDICATED_GPIO
		*spiWritePtr = (sim_MT6302_SPIWriter)MT6302_Writer_dedicated_GPIO;
		if((0xff == MT6302_getGPIOCS(chipNo)) || (0xff == MT6302_getGPIOCLK(chipNo)) || (0xff == MT6302_getGPIODAT(chipNo)))
			ASSERT(0);

	}
	else{
		IMPLEMENTING_ASSERT;
	}
}


/*
void MT6302_spiInit(void)
{
	extern sim_MT6302_switchInfo switchCB[];
	kal_uint32 i;

	for(i = 0; i < SIM_MT6302_MAX_MT6302; i++){
		MT6302_spiInterfaceInit(&switchCB[i], i);
	}
}
*/
#endif
#endif //DRV_SIM_OFF

