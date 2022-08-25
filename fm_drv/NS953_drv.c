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

/*******************************************************************************
 *
 * Filename:
 * ---------
 * NS953_drv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *      FM Radio Driver (TOYOTA NS953)
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "l1audio_def.h"
#if (defined(NS953))
//#define FM_DRIVER_DEBUG_TESTING

/* TOYOTA NS953 control word */
#define ADRW 0xC8
#define ADRR 0xC9

#define REG0_INIT     0x10
#define REG1_INIT     0x00
#define REG2_INIT     0xC0
#define START_REG_NUM 0x00
#define TOTAL_REG_NUM 14
#define STO_REG_NUM   0x08

#define SDREG     0x78
#define PE        0x01
#define IFCST     0x04
#define MUTE      0x02
#define PCNTHIGH  0x3F
#define PCNTLOW   0xFF
#define STEREOJDG 0x10
#define IFCJDG    0x20
#define RSSIJDG   0x30
#define JLJDG     0x60
#define SWSTD     0xF0
#define STO_BIT   0x80

#define ADCLVL_HIGH   0x0A
#define ADCLVL_MID    0x07
#define ADCLVL_LOW    0x05
#define FIRST_IMAGE_PLL_DEV    3
#define SECOND_IMAGE_PLL_DEV  -2
#define THIRD_IMAGE_PLL_DEV    6
#define FM_TUNER_GRID 100

#define _32MS 7

/* Serial communication interfaces */
void SerialCommInit(void);
void SerialCommCryClkOn(void);
void SerialCommCryClkOff(void);
void SerialCommRxByte(uint8 *data, uint8 ack);
uint8 SerialCommTxByte(uint8 data);
void SerialCommStop(void);
void SerialCommStart(void);

static struct {
   uint8   CtrlWordW[TOTAL_REG_NUM];
#if defined(FM_DRIVER_DEBUG_TESTING)
   uint8   CtrlWordR[TOTAL_REG_NUM];
#endif
} regMap = {
   0x10, 0x00, 0xC0, 0x26, 0xC3, 0x61, 0x88,
   0x5D, 0x0F, 0x8D, 0x28, 0x8C, 0x04, 0x00
#if defined(FM_DRIVER_DEBUG_TESTING)
   ,0,0,0,0,0,0,0,0,0,0,0,0,0,0
#endif
   };

static bool NS953_I2cWriteReg(uint8 startAddr, uint8 bytesNum)
{
   int32 i,acknowledge;

   SerialCommStart();
   SerialCommTxByte(ADRW);
   SerialCommTxByte(startAddr);
   for(i=0; i < bytesNum; i++)
      acknowledge=SerialCommTxByte(regMap.CtrlWordW[i]);

   SerialCommStop();

   if(acknowledge)
      return false;

   return true;
}

static bool NS953_I2cReadReg(uint8 *data, uint8 startAddr, uint8 bytesNum)
{
   int32 acknowledge;
#if defined(FM_DRIVER_DEBUG_TESTING)
   int32 i,latestRegNum;
#endif
   SerialCommStart();
   SerialCommTxByte(ADRW);
   SerialCommTxByte(startAddr);
   SerialCommStart();
   acknowledge = SerialCommTxByte(ADRR);

#if defined(FM_DRIVER_DEBUG_TESTING)
   latestRegNum = bytesNum + startAddr - 1;
   for(i=startAddr; i< latestRegNum; i++)
      SerialCommRxByte(data+i, 0); /* ACK */
   SerialCommRxByte(data+latestRegNum, 1); /* Non-ACK */
#else
   SerialCommRxByte(data, 1); /* Non-ACK */
#endif
   SerialCommStop();

   if(acknowledge)
      return false;

   return true;
}

static void resetCtrlWord(void)
{
   regMap.CtrlWordW[0]=REG0_INIT;
   regMap.CtrlWordW[1]=REG1_INIT;
   regMap.CtrlWordW[2]=REG2_INIT;
}
/* ROUND((4*(WF*1000-375)))/32768)*1000) */
static uint16 freqencyToPllWord(int16 curf)
{
   int32 curFreq = (int32)curf * (int32)FM_TUNER_GRID;
   return (uint16)(((curFreq-375)*(int32)1000+(int32)4096)/(int32)8192);
}

static void setSWSTD(uint8 judgementType)
{
	regMap.CtrlWordW[0] &= ~SWSTD;
	regMap.CtrlWordW[0] |= judgementType;
}

static void setIFCST(bool switchOn)
{
   if(switchOn)
	   regMap.CtrlWordW[0] |= IFCST;
	else
	   regMap.CtrlWordW[0] &= ~IFCST;
}

static void setSignalLvl(uint8 signalvl)
{
   regMap.CtrlWordW[3] &= ~SDREG;
   regMap.CtrlWordW[3] |= (uint8)((signalvl << 3)& SDREG);
}

static void setMute(bool switchOn)
{
	if(switchOn)
      regMap.CtrlWordW[0] |= MUTE;
   else
      regMap.CtrlWordW[0] &= ~MUTE;
}

static void setPllWord(uint16 pll)
{
   regMap.CtrlWordW[1]=(uint8)(pll & PCNTLOW);
   regMap.CtrlWordW[2] &= ~PCNTHIGH;
   regMap.CtrlWordW[2] |= (uint8)((pll >> 8)& PCNTHIGH);
}

static void setPowerSW(bool switchOn)
{
   if(switchOn)
      regMap.CtrlWordW[0] |= PE;
   else
      regMap.CtrlWordW[0] &= ~PE;
}

static bool inquireSTO(void)
{
   NS953_I2cWriteReg(START_REG_NUM, 4);
   kal_sleep_task( _32MS ); /* WAIT timer when PLL is changed*/

#if defined(FM_DRIVER_DEBUG_TESTING)
   {
      NS953_I2cReadReg(regMap.CtrlWordR, START_REG_NUM, 9);
      uint8 data = regMap.CtrlWordR[0]& IFCST;
      ASSERT(!data);
      if(regMap.CtrlWordR[8] & STO_BIT)
         return true;  /* STO = HIGH */
      return false;
   }
#else
   {
      uint8 r8Cache; 
      NS953_I2cReadReg(&r8Cache, STO_REG_NUM, 1);
      if(r8Cache & STO_BIT)
         return true;  /* STO = HIGH */
      return false;
   }
#endif
}
/* check to see if RF input level is bigger than threshold */
static bool rssiJudgement(uint16 *pll, int16 freq)
{
   resetCtrlWord();
   setPowerSW(true);
   setSWSTD(RSSIJDG);
   setMute(true);

   *pll = freqencyToPllWord(freq);
   setPllWord(*pll);
   return inquireSTO();
}
/* check to see if IF counter value is valid */
static bool ifCountJudgement(void)
{
   setSWSTD(IFCJDG);
   setIFCST(true);
   return inquireSTO();
}

static bool firstImageJudgement(uint16 pll)
{
   setPllWord(pll + FIRST_IMAGE_PLL_DEV);
   return inquireSTO();
}

static bool secondImageJudgement(uint16 pll)
{
   setPllWord(pll + SECOND_IMAGE_PLL_DEV);
   return inquireSTO();
}

static bool thirdImageJudgement(uint16 pll)
{
   setPllWord(pll + THIRD_IMAGE_PLL_DEV);
   setSWSTD(JLJDG);
   return inquireSTO();
}

/*
   FM radio driver interface
*/

void FMDrv_PowerOnReset(void)
{
   SerialCommCryClkOn();
   SerialCommInit();
   resetCtrlWord();
   NS953_I2cWriteReg(START_REG_NUM, TOTAL_REG_NUM);
}

void FMDrv_PowerOffProc(void)
{
   setPowerSW(false);
   NS953_I2cWriteReg(START_REG_NUM, 1);
   SerialCommCryClkOff();
}

/* SEEK control sequence */
uint8 FMDrv_ValidStop(int16 freq, int8 signalvl, bool is_step_up)
{
   uint16 pll;

   setSignalLvl((uint8)signalvl);

   if(!rssiJudgement(&pll, freq))
      return 0;

   if(!ifCountJudgement() || !firstImageJudgement(pll) || 
      !secondImageJudgement(pll) || !thirdImageJudgement(pll))
      return 0;

   return 1;
}

void FMDrv_SetFreq( int16 curf )
{
   uint16  pll = freqencyToPllWord(curf);
   resetCtrlWord();
   setPllWord(pll);
   setPowerSW(true);
   NS953_I2cWriteReg(START_REG_NUM, 3);
#if defined(FM_DRIVER_DEBUG_TESTING)
   NS953_I2cReadReg(regMap.CtrlWordR, START_REG_NUM, 9);
#endif
}

uint8 FMDrv_GetSigLvl(int16 curf)
{
   uint16 pll, i;
   uint8 candidates[3] = {ADCLVL_HIGH, ADCLVL_MID, ADCLVL_LOW}; 

   for(i=0; i<3; i++){
      setSignalLvl(candidates[i]);
      if(rssiJudgement(&pll, curf))
         return candidates[i];
   }
   return 0;
}

void FMDrv_Mute(uint8 mute)
{
	setMute(mute);
   NS953_I2cWriteReg(START_REG_NUM, 1);
}

void FMDrv_ChipInit()
{
   SerialCommCryClkOn();
   SerialCommInit();
   NS953_I2cWriteReg(START_REG_NUM, TOTAL_REG_NUM);
   SerialCommCryClkOff();
}

bool FMDrv_IsChipValid( void )
{
	bool result;
   SerialCommCryClkOn();
   SerialCommInit();
   result = NS953_I2cWriteReg(START_REG_NUM, TOTAL_REG_NUM);
   SerialCommCryClkOff();
   return result;
}

#endif // defined(NS953)

