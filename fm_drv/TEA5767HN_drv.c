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
 * TEA5767_drv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *      FM Radio Driver (Philip TEA5767HN)
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
#if (defined(TEA5767HN))

/* Philips TEA5767HN control word */
#define ADRW 0xC0
#define ADRR 0xC1
#define DB1_READY 0x80
#define DB1_MUTE  0x80
#define DB3_HILO  0x10
#define DB3_LOLO  0x00
#define DB3_MLMR  0x06 
#define DB4 0x1E  /* XTAL,SMUTE,HCC,SNC == 1 */
#define DB4_STBY  0x40
#define DB5 0xC0  /* PLLREF == 1 , DTC == 1 */
#define IFC_MAX   0x3E
#define IFC_MIN   0x31
/* General propose constant */
#define VALIDCNS 2
#define FM_FREQ_STEP 50
#define HI_INJECTION 1
#define LO_INJECTION 0
#define FM_TUNER_GRID 100

/* Serial communication interfaces */
void SerialCommInit(void);
void SerialCommCryClkOn(void);
void SerialCommCryClkOff(void);
void SerialCommRxByte(uint8 *data, uint8 ack);
uint8 SerialCommTxByte(uint8 data);
void SerialCommStop(void);
void SerialCommStart(void);

static struct {
   int8    tuner_SearchingDir;
   uint8   signalvl_threshold;
   uint8   fm_i2c_wd[5]; /* keep cur. status */
   uint8   fm_i2c_rd[5];
   uint8   tuner_IFcount[2];
   uint8   tuner_ADClev[2];
   uint8   tuner_InterFreq[3];
   uint8   tuner_InterADC[3];
} fm;

#define I2C_READ_OPERATION() { \
   { \
      uint32 count = 0; \
      fm.fm_i2c_rd[0] &= ~(DB1_READY); \
      while(1){ \
   	     SerialCommStart(); \
         SerialCommTxByte(ADRW); \
         TEA5767HN_I2cRead(fm.fm_i2c_rd); \
         if(fm.fm_i2c_rd[0]&DB1_READY) break; \
         kal_sleep_task(1); /* sleep 4.6 ms */ \
         count++; \
         if(count > 20) break; \
      } \
   } \
}

#define SET_FREQ_PROCEDURE() { \
   HiLo = TEA5767HN_HiLoInjectOptimizer(curFreq); \
   if(HiLo){ \
      pll = TEA5767HN_FreqToPll(curFreq,HI_INJECTION); \
      TEA5767HN_SetCtrlWord((uint8)((pll >> 8)& 0xFF),(uint8)(pll & 0xFF),DB3_HILO,DB4,DB5); \
   } \
   else{ \
      pll=TEA5767HN_FreqToPll(curFreq,LO_INJECTION); \
      TEA5767HN_SetCtrlWord((uint8)((pll >> 8)& 0xFF),(uint8)(pll & 0xFF),DB3_LOLO,DB4,DB5); \
   } \
   TEA5767HN_I2cWrite(); \
}

#define SET_FREQ_MUTE_PROCEDURE() { \
   HiLo = TEA5767HN_HiLoInjectOptimizer(curFreq); \
   if(HiLo){ \
      pll = TEA5767HN_FreqToPll(curFreq,HI_INJECTION); \
      TEA5767HN_SetCtrlWord((uint8)(((pll >> 8)& 0xFF)|DB1_MUTE),(uint8)(pll & 0xFF),DB3_HILO,DB4,DB5); \
   } \
   else{ \
      pll=TEA5767HN_FreqToPll(curFreq,LO_INJECTION); \
      TEA5767HN_SetCtrlWord((uint8)(((pll >> 8)& 0xFF)|DB1_MUTE),(uint8)(pll & 0xFF),DB3_LOLO,DB4,DB5); \
   } \
   TEA5767HN_I2cWrite(); \
}

static bool TEA5767HN_I2cWrite(void)
{
   int32 i,acknowledge;

   SerialCommStart();
   acknowledge=SerialCommTxByte(ADRW);

   for(i=0; i<5; i++)
      acknowledge=SerialCommTxByte(fm.fm_i2c_wd[i]);

   SerialCommStop();

   if(acknowledge)
      return false;

   return true;
}

static bool TEA5767HN_I2cRead(uint8 *data)
{
   int32 i,acknowledge;

   SerialCommStart();
   acknowledge = SerialCommTxByte(ADRR);

   for(i=0; i<4; i++)
      SerialCommRxByte(data+i, 0); /* ACK */
   SerialCommRxByte(data+4, 1); /* Non-ACK */
   SerialCommStop();

   if(acknowledge)
      return false;

   return true;
}

static void TEA5767HN_SetCtrlWord(uint8 b1, uint8 b2, uint8 b3, uint8 b4, uint8 b5)
{
   fm.fm_i2c_wd[0]=b1;
   fm.fm_i2c_wd[1]=b2;
   fm.fm_i2c_wd[2]=b3;
   fm.fm_i2c_wd[3]=b4;
   fm.fm_i2c_wd[4]=b5;
}
/* value of curf:  98.7 MHz --> 98700 */
/* PLL word is calculated with the formula : ROUND((4*(WF*1000+225)))/32768)*1000) */
static uint16 TEA5767HN_FreqToPll(int32 curf, uint8 HiLo)
{
   int32 iFif,plltmp;

   iFif = (HiLo?225:-225);
   plltmp = (((int32)curf+iFif)*(int32)1000+(int32)4096)/(int32)8192;
   return (uint16)plltmp;
}

static void TEA5767HN_GetTunerStatus(uint16 iPll, uint8 hilo_injection)
{
   TEA5767HN_SetCtrlWord((uint8)(((iPll>>8)&0x3F)|DB1_MUTE),(uint8)(iPll&0xFF),hilo_injection,DB4,DB5);
   TEA5767HN_I2cWrite();
   I2C_READ_OPERATION();
}

static uint8 TEA5767HN_ValidStop_PreCheck(int32 curf)  /* Valid stop check algorithm */
{
   uint16 pll;

   pll = TEA5767HN_FreqToPll(curf,LO_INJECTION);  /* Low side injection */
   TEA5767HN_GetTunerStatus(pll, DB3_LOLO);
	fm.tuner_IFcount[0] = fm.fm_i2c_rd[2] & 0x7F;
   fm.tuner_ADClev[0] = fm.fm_i2c_rd[3]>>4;

   if ((fm.tuner_IFcount[0] >= IFC_MIN) && (fm.tuner_IFcount[0] <= IFC_MAX)
   		&& (fm.tuner_ADClev[0] >= fm.signalvl_threshold)) // for a valid station, IF count must be valid
      return 1;
   else
	   return 0;    // IF count or ADC level is not right
}

/* optimal Hilo Check algorithm
Set HILO to ¡§1¡¨.
Tune to Fwanted + 450 kHz: measure signal level A LevelHigh
Tune to Fwanted ¡V 450 kHz: measure signal level A LevelLow
If LevelHigh < LevelLow then HILO is ¡§1¡¨ else HILO is ¡§0¡¨.
*/
static bool TEA5767HN_HiLoInjectOptimizer(int32 curFreq)
{
   uint8 LevelHigh, LevelLow;
   uint16 tmpPll;

   tmpPll = TEA5767HN_FreqToPll((curFreq+450), HI_INJECTION);
   TEA5767HN_GetTunerStatus(tmpPll, DB3_HILO);
   LevelHigh = fm.fm_i2c_rd[3];

   tmpPll = TEA5767HN_FreqToPll((curFreq-450), HI_INJECTION);
   TEA5767HN_GetTunerStatus(tmpPll, DB3_HILO);
   LevelLow = fm.fm_i2c_rd[3];

   if( LevelHigh < LevelLow ){
      return true;
   }
   return false;
}

static void TEA5767HN_UpdateIfCount(void)
{
   fm.tuner_InterFreq[1-fm.tuner_SearchingDir] = fm.tuner_InterFreq[1];
   fm.tuner_InterFreq[1] = fm.tuner_InterFreq[1+fm.tuner_SearchingDir];
   fm.tuner_InterFreq[1+fm.tuner_SearchingDir] = (fm.fm_i2c_rd[2])&0x7F;
   fm.tuner_InterADC[1] = fm.tuner_InterADC[1+fm.tuner_SearchingDir];
   fm.tuner_InterADC[1+fm.tuner_SearchingDir] = (fm.fm_i2c_rd[3]>>4)&0x0F;
}

/*
   FM radio driver interface
*/

void FMDrv_PowerOnReset(void)
{
   SerialCommCryClkOn();
   SerialCommInit();
   TEA5767HN_SetCtrlWord(DB1_MUTE,0,0,0,0); /* Power on & Reset TEA5767HN */
   TEA5767HN_I2cWrite();
}

void FMDrv_PowerOffProc(void)
{
   TEA5767HN_SetCtrlWord(DB1_MUTE,0,0,DB4_STBY,0); /* set Standby bit */
   TEA5767HN_I2cWrite();
   SerialCommCryClkOff();
}

 /* signal level range is 0 ~ 15 , 5767 has 16 levels ADC */
uint8 FMDrv_ValidStop(int16 freq, int8 signalvl, bool is_step_up)
{
   uint16 pll;
   int32  curFreq, freq_tmp;

   curFreq = (int32)freq;
   curFreq *= FM_TUNER_GRID;
   /// Check the signal level of curFreq
   if (TEA5767HN_ValidStop_PreCheck(curFreq)==0)
      return 0;
 
   fm.tuner_SearchingDir = (is_step_up?1:-1);  // update searching direction
   fm.signalvl_threshold = (uint8)signalvl;
/*
 The nominal IF count is 55.  If the tuner is tuned to 50KHz lower than the station frequency,
 the IF should be about 43. For the frequency 50 KHz above the station then the IF should be
 around 67.  The following two constants are set to cover the IF variation for 50KHz above and
 below the station's frequency.
*/
   freq_tmp = (int32)freq;
   freq_tmp *= FM_TUNER_GRID;
   freq_tmp -= FM_FREQ_STEP * fm.tuner_SearchingDir;
   pll = TEA5767HN_FreqToPll(freq_tmp, HI_INJECTION);
   TEA5767HN_GetTunerStatus(pll, DB3_HILO);
   TEA5767HN_UpdateIfCount();
   
   if (fm.tuner_SearchingDir == 1) {
   	if ((fm.tuner_InterFreq[2] <= 0) || (fm.tuner_InterFreq[2] > 50)) {
   		return 0;
   	}
   } else {
   	if ((fm.tuner_InterFreq[0] < 60)) {
   		return 0;
   	}
   }

   pll = TEA5767HN_FreqToPll(curFreq,HI_INJECTION);        // high side injection
   TEA5767HN_GetTunerStatus(pll, DB3_HILO);
   fm.tuner_IFcount[1] = (fm.fm_i2c_rd[2])&0x7F;
   fm.tuner_ADClev[1] = (fm.fm_i2c_rd[3]>>4)&0x0F;
   TEA5767HN_UpdateIfCount();
   
   if (fm.tuner_SearchingDir == 1) {
   	if ((fm.tuner_InterFreq[2] < 52) || (fm.tuner_InterFreq[2] > 58)) {
   		return 0;
   	}
   } else {
   	if ((fm.tuner_InterFreq[0] < 52) || (fm.tuner_InterFreq[0] > 58)) {
   		return 0;
   	}
   }

   freq_tmp += FM_FREQ_STEP * fm.tuner_SearchingDir * 2;
   pll = TEA5767HN_FreqToPll(freq_tmp, HI_INJECTION);
   TEA5767HN_GetTunerStatus(pll, DB3_HILO);
   TEA5767HN_UpdateIfCount();
   
   if (fm.tuner_SearchingDir == 1) {
   	if ((fm.tuner_InterFreq[2] < 60)) {
   		return 0;
   	}
   } else {
   	if ((fm.tuner_InterFreq[0] <= 0) || (fm.tuner_InterFreq[0] > 50)) {
   		return 0;
   	}
   }
   
   fm.tuner_ADClev[1] = fm.tuner_InterADC[1];// Check this station on the low side

	/*
   if ((fm.tuner_InterFreq[0] > 0) && (fm.tuner_InterFreq[0] <= 50) &&
      (fm.tuner_InterFreq[1] >= 52) && (fm.tuner_InterFreq[1] <= 58) &&
      (fm.tuner_InterFreq[2] >= 60)) // for a valid station, IF count must be valid
   {
   	fm.tuner_ADClev[1] = fm.tuner_InterADC[1];// Check this station on the low side
   }   
   else   return 0;
   */

   if ((((int8)fm.tuner_ADClev[1] - (int8)fm.tuner_ADClev[0]) <= VALIDCNS) &&
	    (((int8)fm.tuner_ADClev[0] - (int8)fm.tuner_ADClev[1]) <= VALIDCNS))	// Levels on both injections are consistant then it can be a good station
	{
      fm.tuner_InterFreq[0] = fm.tuner_InterFreq[1] = fm.tuner_InterFreq[2] = 0;
      return 1;
   }
   else
	   return 0;    // IF count or ADC level is not right   
}

void FMDrv_SetFreq( int16 curf )  /* input value: 875 - 1080 ( 87.5 MHz - 108.0 MHz)*/
{
   int32   curFreq;
   bool    HiLo;
   uint16  pll;

   curFreq = (int32)curf;
   curFreq *= FM_TUNER_GRID;
   SET_FREQ_PROCEDURE();
}

uint8 FMDrv_GetSigLvl( int16 curf )
{
   int32   curFreq;
   bool    HiLo;
   uint16  pll;

   curFreq = (int32)curf;
   curFreq *= FM_TUNER_GRID;
   SET_FREQ_MUTE_PROCEDURE();
   I2C_READ_OPERATION();
	return (fm.fm_i2c_rd[3]>>4);
}

void FMDrv_Mute(uint8 mute)
{   /* mute==1-->Mute, mute==0--> audio not muted */
   if(mute == 1){
      fm.fm_i2c_wd[0] |= DB1_MUTE;
      fm.fm_i2c_wd[2] &= ~DB3_MLMR;
   }else{
       fm.fm_i2c_wd[0] &= ~DB1_MUTE;
       fm.fm_i2c_wd[2]|= mute & DB3_MLMR;
    }
   TEA5767HN_I2cWrite();  /* write operation to TEA5767HN */
}

void FMDrv_ChipInit(void)
{
   SerialCommCryClkOn();
   SerialCommInit();
   TEA5767HN_SetCtrlWord(DB1_MUTE,0,0,DB4_STBY,0); /* set Standby bit */
   TEA5767HN_I2cWrite();
   SerialCommCryClkOff();
}

bool FMDrv_IsChipValid( void )
{
	bool result;
   SerialCommCryClkOn();
   SerialCommInit();
   TEA5767HN_SetCtrlWord(DB1_MUTE,0,0,DB4_STBY,0); /* set Standby bit */
   result = TEA5767HN_I2cWrite();
   SerialCommCryClkOff();
   return result;
}

#endif // defined(TEA5767HN)