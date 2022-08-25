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
 * MT6626_drv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *      FM Radio Driver (MT6626)
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/
#if (defined(MT6626))
#if defined(FM_INTERFACE_I2C)
#define USE_I2C
#define BT_SUPPORT
//#define MT6626_FPGA
#endif
#endif
#include "kal_non_specific_general_types.h"
#include "kal_release.h"
#include "app_ltlcom.h"
#include "stack_ltlcom.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "stack_common.h"
#include "MT6626.h"
#include "us_timer.h"
#include "eint.h"
#include "kal_trace.h"
#include "fmr_trc.h"
#include "MT6626_drv_dsp.h"
#include "drv_comm.h"
#include "fm_radio.h"

extern void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada);
extern void GPIO_PullenSetup(kal_uint16 pin, kal_bool enable);
extern void GPIO_PullSelSetup(kal_uint16 pin, kal_bool pull_up);
 
#if (defined(MT6626))

#if defined(BT_SUPPORT)
extern kal_uint8 BtRadio_Power_Handler(kal_uint8 sys, kal_uint8 on, kal_uint8 is_fm_i2s);
extern kal_uint8 BtRadio_Power_Handler_Force_Reset(kal_uint8 sys);
#endif
/* defined in custom folder */
extern kal_uint16 FMR_RSSI_THRESHOLD_LANT;
extern kal_uint16 FMR_RSSI_THRESHOLD_SANT;
extern const kal_bool FMR_DEEMPHASIS_50us;
extern const kal_uint16 FMR_CQI_TH;
/*check 6626 whether exist*/
static kal_bool FMChip_Exist = KAL_FALSE;
static kal_bool FM_Detect_Done = KAL_FALSE;
extern kal_uint8 chip_powered_on;
extern const char gpio_bt_power_pin;
extern const char gpio_bt_reset_pin;
extern void BtRadio_PowerOn(kal_uint8 polBT, kal_uint8 numBT);
extern void BtRadio_PowerOff(kal_uint8 polBT, kal_uint8 numBT);
extern void BtRadio_WriteGPIO(char val, unsigned char pin);
#ifdef USE_I2C
//#define HW_I2C
#define FM_write_I2C_address 0xE0
#define FM_read_I2C_address 0xE1
   #ifdef HW_I2C
#include "sccb_v2.h"
   #endif
#endif

#define BAND_UP 1080 //108MHz
#define BAND_DN 875 //87.5MHz

#if defined(INTERNAL_ANTENNAL_SUPPORT)
#define FM_PowerOn_with_ShortAntenna
#endif

kal_bool FM_MCUFA_OPEN = KAL_FALSE;
kal_bool FM_Data_debug = KAL_TRUE;

extern const kal_uint8 FM_EINT_NO;
extern FMR_data *pstFMR_data;
extern kal_bool isRdsOn;
static kal_bool fm_state = LEVEL_LOW;


/// Global variables for current FM status
kal_int16 _current_frequency = -1;
kal_int16 _backup_frequency = -1;
static kal_bool  _is_fm_on = KAL_FALSE;
static kal_uint16 Chip_ID = 0;
static chip_ver Chip_Version = E1;
const kal_uint16 *bin_patch;
const kal_uint16 *bin_coeff;
kal_uint8 HWSearch_flag = 0;
static kal_uint8 Valid_flag = 0;
static kal_uint16 FreqKHz = 0;
kal_uint16 FreqSt = 987;
kal_bool DebugSwith = KAL_TRUE;
#if defined(FM_PowerOn_with_ShortAntenna)
kal_uint8 is_shortAntenna = 1;
#else
kal_uint8 is_shortAntenna = 0;
#endif
//static kal_uint16 I2Ssetting = 0;

static void MT6626_ParameterDownloadToDsp(const kal_uint16 *dsp_array, Download_type type);

/* Serial communication interfaces */
#if (defined(USE_I2C))&&(!defined(HW_I2C))
void  SerialCommCryClkOn(void);
void  SerialCommCryClkOff(void);
void  SerialCommStart(void);
void  SerialCommStop(void);
void  SerialCommInit(void);
kal_uint8 SerialCommTxByte(kal_uint8 data);
void  SerialCommRxByte(kal_uint8 *data, kal_uint8 ack);
#elif (defined(USE_I2C))&&(defined(HW_I2C))
#endif

extern kal_uint8 L1SM_GetHandle(void);
extern void L1SM_SleepEnable(kal_uint8 handle);
extern void L1SM_SleepDisable(kal_uint8 handle);
static kal_uint8 FMR_SleepHandle=0xFF;
void FMDrv_Mute(kal_uint8 mute);
void FMDrv_EvaluateRSSIThreshold(void);
void FMDrv_ChipReset(void);
#ifdef __FM_RADIO_RDS_SUPPORT__
extern void FMDrv_RDS_Disable(void);
extern void FMDrv_RDS_Enable(void);
#endif
// enginner mode struct

typedef enum group_idx {
	   mono=0,
	   stereo,
	   RSSI_threshold,
	   HCC_Enable,
	   PAMD_threshold,
	   Softmute_Enable,
	   De_emphasis,
	   HL_Side,
	   Demod_BW,
	   Dynamic_Limiter,
	   Softmute_Rate,
	   AFC_Enable,
	   Softmute_Level,
	   Analog_Volume,
	   FMR_GROUP_TOTAL_NUMS
	} FMR_FACTORY_GROUP_ENUM;
	
typedef enum item_idx {
	   Sblend_OFF=0,
	   Sblend_ON,  
	   FMR_ITEM_TOTAL_NUMS
	} FMR_FACTORY_ITEM_INDEX;
// enginner mode struct

typedef struct {
   kal_uint16 addr;
   kal_uint16 and;
   kal_uint16 or;
} ctrl_word_operation;

#ifdef USE_I2C

#if defined(__FMRADIO_I2S_SUPPORT__)
    #if defined(MT6626_FPGA)
#define POWER_ON_COMMAND_COUNT 26
    #else
#define POWER_ON_COMMAND_COUNT 21
	#endif
#else
    #if defined(MT6626_FPGA)
#define POWER_ON_COMMAND_COUNT 24
    #else
#define POWER_ON_COMMAND_COUNT 19
    #endif
#endif
static const ctrl_word_operation PowerOnSetting[POWER_ON_COMMAND_COUNT] = {
//RX DIGITAL Init
//FM Digital Init: fm_rgf_maincon
    {0x60, 0x0, 0x3000},
    {0x60, 0x0, 0x3001},
    {0xFFFB, 0x0, 0x0003},//Delay 3ms
    {0x60, 0x0, 0x3003},
    {0x60, 0x0, 0x3007},
    //{0xFFFD, 0x99, 0x0000},
#if defined(__FMRADIO_I2S_SUPPORT__)
    #if defined(FM_PowerOn_with_ShortAntenna)
    {0x61, 0xFF63, 0x0090},//no low power mode, I2S, short antenna
    #else
    {0x61, 0xFF63, 0x0080},//no low power mode, I2S, long antenna
    #endif
    {0x9B, 0xFFF7, 0x0008},//0000->master, 0008->slave 
    {0x5F, 0xE7FF, 0x0000},//0000->32K, 0800->44.1K, 1000->48K
    //{0x61, 0xFF73, 0x0080},//no low power mode, I2S, long antenna, 0xff63
    //{0x9B, 0xFFF7, 0x0008},//0000->master, 0008->slave 
    //{0x5F, 0xE7FF, 0x0000},//0000->32K, 0800->44.1K, 1000->48K
#else
    #if defined(FM_PowerOn_with_ShortAntenna)
    {0x61, 0xFF63, 0x0010},//no low power mode, analog line in, short antenna
    #else
    {0x61, 0xFF63, 0x0000},//no low power mode, analog line in, long antenna
    #endif
    //{0x5566, 0x0000, 0x0000}
#endif
    {0xFFFD, 0x0062, 0x0000},//read the HW version
    {0xFFFD, 0x99, 0x0000},
#if defined(MT6626_FPGA)    
    {0xa0, 0x0, 0xd0b2},
    {0xFFF9, 0x0, 0x0001},
#endif    
    {0xFFF9, 0x0, 0x0002},
    {0xFFF9, 0x0, 0x0003},
    {0xFFF9, 0x0, 0x0004},
    {0x90, 0x0, 0x0040},
    {0x90, 0x0, 0x0000},
    {0x6A, 0x0, 0x0020},
    {0x6B, 0x0, 0x0020},
    {0x60, 0x0, 0x300F},
    {0x61, 0xFFFF, 0x0002},
    {0x61, 0xFFFE, 0x0000},
    //{0xFFFB, 0x0, 0x0064},//Delay 100ms
    {0xFFFF, 0x64, 0x2}
    //,{0x65, 0x0, 0x02B6},
    //{0x63, 0x0, 0x0001},
    //{0xFFFF, 0x69, 0x0001},
    //{0x69, 0x0, 0x0001}
#if defined(MT6626_FPGA)
    ,{0x54, 0x0, 0x0001},
    {0x11, 0x0, 0xb7d4},
    {0x54, 0x0, 0x8000}
#endif
};
#endif  //#ifdef USE_I2C
/*----------------------------------------------------------------------------*/
/* Loop count for time measurement                                            */
/*----------------------------------------------------------------------------*/
#if defined(MCU_13M)
/* 1T ~= 77 ns */
#define COUNTER_50US (325)
#define COUNTER_20US (130)
#define COUNTER_15US (97)
#define COUNTER_10US (65)
#define COUNTER_05US (32)
#define COUNTER_350NS (3)

#elif defined(MCU_15_36M)
/* 1T ~= 65 ns */
#define COUNTER_50US (384)
#define COUNTER_20US (153)
#define COUNTER_15US (174)
#define COUNTER_10US (76)
#define COUNTER_05US (38)
#define COUNTER_350NS (4)

#elif defined(MCU_26M)
/* 1T ~= 38 ns */
#define COUNTER_50US (658)
#define COUNTER_20US (263)
#define COUNTER_15US (197)
#define COUNTER_10US (132)
#define COUNTER_05US (66)
#define COUNTER_350NS (5)

#elif defined(MCU_30_72M)
/* 1T ~= 33 ns */
#define COUNTER_50US (757)
#define COUNTER_20US (303)
#define COUNTER_15US (227)
#define COUNTER_10US (151)
#define COUNTER_05US (75)
#define COUNTER_350NS (6)

#elif defined(MCU_39M)
/* 1T ~= 25 ns */
#define COUNTER_50US (1000)
#define COUNTER_20US (400)
#define COUNTER_15US (300)
#define COUNTER_10US (200)
#define COUNTER_05US (100)
#define COUNTER_350NS (7)

#elif defined(MCU_52M)
/* 1T ~= 19 ns */
#define COUNTER_50US (1316)
#define COUNTER_20US (526)
#define COUNTER_15US (395)
#define COUNTER_10US (263)
#define COUNTER_05US (132)
#define COUNTER_350NS (10)

#elif defined(MCU_61_44M)
/* 1T ~= 16 ns */
#define COUNTER_50US (1563)
#define COUNTER_20US (625)
#define COUNTER_15US (468)
#define COUNTER_10US (312)
#define COUNTER_05US (156)
#define COUNTER_350NS (11)

#elif defined(MCU_65M)
/* 1T ~= 15 ns */
#define COUNTER_50US (1666)
#define COUNTER_20US (666)
#define COUNTER_15US (500)
#define COUNTER_10US (333)
#define COUNTER_05US (166)
#define COUNTER_350NS (12)

#elif defined(MCU_78M)
/* 1T ~= 13 ns */
#define COUNTER_50US (1923)
#define COUNTER_20US (769)
#define COUNTER_15US (576)
#define COUNTER_10US (384)
#define COUNTER_05US (192)
#define COUNTER_350NS (13)

#elif defined(MCU_91M)
/* 1T ~= 11 ns */
#define COUNTER_50US (2272)
#define COUNTER_20US (909)
#define COUNTER_15US (681)
#define COUNTER_10US (454)
#define COUNTER_05US (227)
#define COUNTER_350NS (15)

#elif defined(MCU_104M)
/* 1T ~= 9.6 ns */
#define COUNTER_50US (2604)
#define COUNTER_20US (1042)
#define COUNTER_15US (781)
#define COUNTER_10US (521)
#define COUNTER_05US (260)
#define COUNTER_350NS (19)

#elif defined(MCU_122_88M)
/* 1T ~= 8.1 ns */
#define COUNTER_50US (3086)
#define COUNTER_20US (1235)
#define COUNTER_15US (925)
#define COUNTER_10US (617)
#define COUNTER_05US (308)
#define COUNTER_350NS (22)

#elif defined(MCU_208M)
/* 1T ~= 4.8 ns */
#define COUNTER_50US (5208)
#define COUNTER_20US (2084)
#define COUNTER_15US (1562)
#define COUNTER_10US (1042)
#define COUNTER_05US (520)
#define COUNTER_350NS (37)

#elif defined(MCU_245_76M)
/* 1T ~= 4.0 ns */
#define COUNTER_50US (6172)
#define COUNTER_20US (2470)
#define COUNTER_15US (1850)
#define COUNTER_10US (1234)
#define COUNTER_05US (616)
#define COUNTER_350NS (44)

#elif defined(MCU_312M)
/* 1T ~= 3.3 ns */
#define COUNTER_50US (10000)
#define COUNTER_20US (3000)
#define COUNTER_15US (2000)
#define COUNTER_10US (1500)
#define COUNTER_05US (1000)
#define COUNTER_350NS (60)

#else

#error "Unsupported MCU clock rate for single bank support V2!"

#endif

static void Delayus(kal_uint32 u4MicroSec)
{
    kal_uint32             start_qbit;      ///< Starting TDMA Qbit
    kal_uint32             curr_qbit;       ///< Current TDMA Qbit
    kal_uint32             elapse_qbit;     ///< Elapse number of Qbit

    // Qbit may not be ready in system initialization stage, use for-loop instead
    if (kal_query_systemInit()) 
    {
        // minimum delay is 5
        if (u4MicroSec < 5)
       	{
           u4MicroSec = 5;
        }

        // delay = delay / 5 ~= delay * 52 / 2^8;
        u4MicroSec = (u4MicroSec * 52) >> 8;

        // for-loop to wait
        for (; u4MicroSec > 0; --u4MicroSec)
        {
            for (curr_qbit = COUNTER_05US; curr_qbit > 0; --curr_qbit);
        }

        return;
	}

    // Read start qbit
    start_qbit = ust_get_current_time();

    /*******************************************************************
    * Calculate how many qbit should be waited. Store the result to "delay".
    * delay = delay * 13 / 12 ~= delay * 13 * 21.3333 / 2^8
    * => Limit: Maximum delay is 15,449,521 us = 15,449 ms = 15 sec
    ***********************************************************************/

    // delay * 13 * 21.333 ~= delay * 278
    u4MicroSec = u4MicroSec * 278;

    // delay / 2^8 ~= (delay >> 8) + 1 (for saving code, add one more qbit in all cases. Actually we only have to do such thing when "delay & 255 == 1"
    u4MicroSec = (u4MicroSec >> 8) + 1;

    // wait until "delay" qbits are all elapsed
    do 
    {
        curr_qbit   = ust_get_current_time();
        elapse_qbit = ust_get_duration(start_qbit, curr_qbit);
    } while (elapse_qbit < u4MicroSec);

    return;
}

static void Delayms(kal_uint32 data)
{
    while(data--)
    {
        Delayus(1000);
    }
}

kal_bool MT6626_ReadWord(kal_uint8 CW, kal_uint16 *data)
{
#if defined(USE_I2C)
    #ifdef HW_I2C
	SCCB_TRANSACTION_RESULT result;
	kal_uint8 FM_HW_I2C_read_buff[2] = {0,0};
	kal_uint8 FM_HW_I2C_write_CW_buff = CW;

	result = i2c_write(SCCB_OWNER_FM, &(FM_HW_I2C_write_CW_buff), 1);

	if (result == SCCB_TRANSACTION_FAIL) 
	{
		kal_prompt_trace(MOD_FMR, "MT6626_WriteByte: HW I2C write failed!");
	}

	result = i2c_read(SCCB_OWNER_FM, FM_HW_I2C_read_buff, 2);

	if (result == SCCB_TRANSACTION_FAIL) 
	{
		kal_prompt_trace(MOD_FMR, "MT6626_ReadByte: HW I2C write failed!");
	}

	*data = (kal_uint16)(FM_HW_I2C_read_buff[0]<<8|FM_HW_I2C_read_buff[1]);

	return result;
    #else
    kal_uint8 dataM, dataL;
    SerialCommStart();                /// send the start sequence
    SerialCommTxByte(FM_write_I2C_address);   /// device ID and R/W bit
    SerialCommTxByte(CW);             /// control word
    SerialCommStop();                 /// send the stop sequence
    SerialCommStart();                /// resend the start sequence
    SerialCommTxByte(FM_read_I2C_address);    /// device ID and R/W bit
    SerialCommRxByte(&dataM, 0);        /// read data and send ACK
    SerialCommRxByte(&dataL, 1);        /// read data and send ACK
    SerialCommStop();                 /// send the stop sequence
    *data = (kal_uint16)(dataM<<8|dataL);
	if(FM_Data_debug == KAL_TRUE)
	{
		FMR_TRACE1(FM_READ_DATA,"--read reg[%x]=[%x]--",CW,*data);
	}
    return KAL_TRUE;
    #endif
#else
    #error "Must define USE_I2C or FSPI"
#endif
}

kal_bool MT6626_WriteWord(kal_uint8 CW, kal_uint16 data)
{
#if (defined(USE_I2C))&&(!defined(HW_I2C))
    SerialCommStart();                /// send the start sequence
    SerialCommTxByte(0xE0);   /// device ID and R/W bit
    SerialCommTxByte(CW);             /// control word   
    SerialCommTxByte(data>>8);           /// data to be written
    SerialCommTxByte(data&0xFF);           /// data to be written
    SerialCommStop();                 /// send the stop sequence
	if(FM_Data_debug == KAL_TRUE)
	{
		FMR_TRACE1(FM_WRITE_DATA,"--write reg[%x]-- [%x]--",CW,data);
	}
    return KAL_TRUE;
#elif (defined(USE_I2C))&&(defined(HW_I2C))
	SCCB_TRANSACTION_RESULT result;
       kal_uint8 FM_HW_I2C_write_buff[3] = {0,0,0};
       FM_HW_I2C_write_buff[0] = CW;   
       FM_HW_I2C_write_buff[1] = data>>8;
       FM_HW_I2C_write_buff[2] = data&0xFF;
	   
	result = i2c_write(SCCB_OWNER_FM, FM_HW_I2C_write_buff, 3);
 

	if (result == SCCB_TRANSACTION_FAIL) 
	{
		kal_prompt_trace(MOD_FMR, "MT6626_WriteByte: HW I2C write failed!");
	}

	return result;

#else
#error "Must define USE_I2C or FSPI"
#endif
  
}

/***********************************************************************
*  Turn on/off tune (internal)
*
*  parameter-->ON_OFF: 1:ON, 0:OFF
*         
***********************************************************************/
void MT6626_TUNE_ON()
{
    kal_uint16 dataRead;
    MT6626_ReadWord(FM_MAIN_CTRL, &dataRead);
    MT6626_WriteWord(FM_MAIN_CTRL, (dataRead&0xFFFE)|TUNE);
}

/***********************************************************************
*  Seek on/off (internal)
*
*  parameter-->ON_OFF: 1:ON, 0:OFF
*         
***********************************************************************/
void MT6626_SEEK_ON()
{
    kal_uint16 dataRead;
    MT6626_ReadWord(FM_MAIN_CTRL, &dataRead);
    MT6626_WriteWord(FM_MAIN_CTRL, (dataRead&0xFFFD)|SEEK);
}

/***********************************************************************
*  Scan on/off (internal)
*
*  parameter-->ON_OFF: 1:ON, 0:OFF
*         
***********************************************************************/
void MT6626_SCAN_ON()
{
    kal_uint16 dataRead;
    MT6626_ReadWord(FM_MAIN_CTRL, &dataRead);
    MT6626_WriteWord(FM_MAIN_CTRL, (dataRead&0xFFFB)|SCAN);
}

/***********************************************************************
*  RAMP off (internal)
*         
***********************************************************************/
void MT6626_RampDown()
{
    kal_uint16 dataRead,i=0;
	FMR_TRACE0(FM_API_ENTRANCE,"ENTRANCE:%d\n",34);
    //Clear DSP state
    MT6626_ReadWord(FM_MAIN_CTRL, &dataRead);		
    MT6626_WriteWord(FM_MAIN_CTRL, (dataRead&0xFFF0)); //clear rgf_tune/seek/scan/dsp_init
    //MT6626_WriteWord(FM_MAIN_CTRL, 0);
    
    //Set DSP ramp down state
    MT6626_ReadWord(FM_MAIN_CTRL, &dataRead);		
    MT6626_WriteWord(FM_MAIN_CTRL, (dataRead|RAMP_DOWN));
    
    //Check STC_DONE status flag (not the interrupt flag!)
	FMR_TRACE0(FM_API_ENTRANCE,"ENTRANCE:%d\n",340);
	FM_Data_debug = KAL_FALSE;
    do
    {
        MT6626_ReadWord(FM_MAIN_INTR, &dataRead);
		if(i++>1000)
		{
			i=0;
			FMR_TRACE0(FM_ON_POLLING_TIMES,"power on polling 1000 times--%d",34);
			FMR_TRACE1( FM_INFO_READ_DATA, "Register [%x] =%x\n",FM_MAIN_INTR,dataRead);
		}
    } while ((dataRead&FM_INTR_STC_DONE)==0);
	FM_Data_debug = KAL_TRUE;
	FMR_TRACE0(FM_API_EXIT,"EXIT:%d\n",340);
    //Clear DSP ramp down state
    MT6626_ReadWord(FM_MAIN_CTRL, &dataRead);		
    MT6626_WriteWord(FM_MAIN_CTRL, (dataRead&(~RAMP_DOWN)));
    
    MT6626_ReadWord(FM_MAIN_INTR, &dataRead);		
    MT6626_WriteWord(FM_MAIN_INTR, dataRead|FM_INTR_STC_DONE);//clear status flag
    MT6626_ReadWord(FM_MAIN_INTR, &dataRead);	/*for debug*/	

#if defined(MT6626_FPGA)
    MT6626_WriteWord(0x54, 0x0001);
    MT6626_WriteWord(0x11, 0x37d4);
    MT6626_WriteWord(0x54, 0x8000);
#endif
	FMR_TRACE0(FM_API_EXIT,"EXIT:%x",34);
}

static void MT6626_writeFA(kal_uint16 *buff, kal_uint8 fa)
{
    kal_uint8 i=0;
	if((fa & 0x4) != 0)
	{
		FM_MCUFA_OPEN = KAL_TRUE;
	}
	else
	{
		FM_MCUFA_OPEN = KAL_FALSE;
	}
	for(i=0; i<3;i++)
    {
        if((fa>>i)& 0x1)
            *buff |= (1<<(12+i));
        else
            *buff &= ~(1<<(12+i));
    }
}

/***********************************************************************
*  Set radio frequency (internal)
*
*  parameter-->CurFreq:set frequency
*         
***********************************************************************/
static kal_bool MT6626_SetFreq(kal_int32 CurFreq)
{
	kal_uint8 tuneRetryCount = 0;
    kal_uint32 CHAN = 0x0000;
    kal_uint16 dataRead, cnt=0, tempbuff=0;

    MT6626_RampDown();
    
    _current_frequency = CurFreq;
    CHAN = (CurFreq - 640)<<1;
    MT6626_ReadWord(FM_CHANNEL_SET, &dataRead);

    if(Chip_Version == E1)
    {
        if(((kal_uint8)((dataRead & 0x1000)>>12)) ^ (channel_parameter[CurFreq - 760] & 0x1))
        {
            MT6626_ReadWord(0x61, &tempbuff);
    		MT6626_WriteWord(0x60, 0x330F);
    		MT6626_WriteWord(0x61, 1); 
            MT6626_WriteWord(0x6e, 0x0);		
            MT6626_WriteWord(0x6e, 0x0);		
            MT6626_WriteWord(0x6e, 0x0);		
            MT6626_WriteWord(0x6e, 0x0);		
            MT6626_WriteWord(0x60, 0x0);		
            MT6626_WriteWord(0x60, 0x4000);
            MT6626_WriteWord(0x60, 0x0);		
            MT6626_WriteWord(0x60, 0x3000);		
            MT6626_WriteWord(0x60, 0x3001);		
            Delayms(3);
            MT6626_WriteWord(0x60, 0x3003);		
            MT6626_WriteWord(0x60, 0x3007);		
            MT6626_WriteWord(0x60, 0x300f);
            MT6626_WriteWord(0x61, tempbuff | 0x0003);		
            MT6626_WriteWord(0x61, tempbuff | 0x0002);		
			MT6626_WriteWord(0x6A, 0x0020);
			MT6626_WriteWord(0x6B, 0x0020);
            Delayms(200);	
        }
    }
    MT6626_writeFA(&dataRead, (channel_parameter[CurFreq - 760]));
    MT6626_WriteWord(FM_CHANNEL_SET, (dataRead&0xFC00)|CHAN);
    
    MT6626_TUNE_ON();	
    
	FMR_TRACE0(FM_API_ENTRANCE,"ENTRANCE:%d\n",320);
	FM_Data_debug = KAL_FALSE;
    do 
    {    
        MT6626_ReadWord(FM_MAIN_INTR, &dataRead);
        if((dataRead & FM_INTR_STC_DONE) == 0)
        {
            kal_sleep_task(3);
        }        
        if(cnt++ > 20)
        {
            cnt = 0;
			FMR_TRACE(FM_INFO_TuneTimes,"setfreq: poll many times!");
			if(tuneRetryCount > 10)
			{
				FMDrv_ChipReset();
			}
			tuneRetryCount++;
        }
    } while ((dataRead & FM_INTR_STC_DONE)==0);
	FM_Data_debug = KAL_TRUE;
	FMR_TRACE0(FM_API_EXIT,"EXIT:%d\n",320);
	MT6626_ReadWord(FM_MAIN_INTR, &dataRead);
    MT6626_WriteWord(FM_MAIN_INTR, dataRead|FM_INTR_STC_DONE);//clear status flag

    MT6626_ReadWord(FM_MAIN_INTR, &dataRead);/*for debug*/
    
#if defined(MT6626_FPGA)
    MT6626_WriteWord(0x54, 0x0001);
    MT6626_WriteWord(0x11, 0xb7d4);
    MT6626_WriteWord(0x54, 0x8000);
#endif

	return KAL_TRUE;
}//MT6626_SetFreq

/***********************************************************************
*  Get RSSI Value (internal)
*
*  parameter-->
*  return dBuVemf
***********************************************************************/
kal_int16 MT6626_GetCurRSSI(void)
{
    kal_uint16 TmpReg;
    kal_int16 RSSI,dBValue;
    MT6626_ReadWord(FM_R_RSSI, &TmpReg);
    RSSI = (kal_int16)(TmpReg&0x3FF);
    /*RS=RSSI
    *If RS>511, then RSSI(dBm)= (RS-1024)/16*6
    *                 else RSSI(dBm)= RS/16*6             */
    dBValue = (RSSI>511) ? (((RSSI-1024)*6/16)+113):(RSSI*6/16+113);
    if(dBValue < 0)
    {
        dBValue = 0;
    }
    
    return dBValue;
}

/***********************************************************************
*  Get PAMD Value (internal)
*
*  parameter-->
***********************************************************************/
kal_uint16 MT6626_GetCurPamd(void)
{
    kal_uint16 TmpReg, PAMD, dBValue;
    MT6626_ReadWord(ADDR_PAMD, &TmpReg);
    /*PA=PAMD
    *If PA>=256 then PAMD(dB)=  (PA-512)/16*6,
    *               else PAMD(dB)=PA/16*6                 */
    PAMD = TmpReg&0x1FF;
    dBValue = (PAMD>=256) ? ((512-PAMD)*6/16):0;
    
    return dBValue;
}
/***********************************************************************
*  Get Search freq (internal)
*
*  parameter-->
***********************************************************************/
void MT6626_GetSearchFreq(kal_uint16 *pfreq)
{
    *pfreq = (kal_uint16)FreqKHz;
}

/*********************************************************************
*  Sete Antenna type
*  parameter-->Type: 1:Short Antenna, 0:Long Antenna
*
*********************************************************************/
kal_bool MT6626_SetAntennaType(kal_uint8 isShortATA)
{
    kal_uint16 dataRead;
    
	is_shortAntenna = isShortATA;
    MT6626_ReadWord(FM_MAIN_CG2_CTRL, &dataRead);
    
    if(isShortATA)
    {
        dataRead |= ANTENNA_TYPE;
    }
    else
    {
        dataRead &= (~ANTENNA_TYPE);
    }
    
    MT6626_WriteWord(FM_MAIN_CG2_CTRL, dataRead);
    
    return KAL_TRUE;
}

/*********************************************************************
*  Get Antenna type
*  parameter
*  return-->1:Short Antenna, 0:Long Antenna
*********************************************************************/
kal_bool MT6626_GetAntennaType(void)
{
    kal_uint16 dataRead;
    
    MT6626_ReadWord(FM_MAIN_CG2_CTRL, &dataRead);
    if(dataRead&ANTENNA_TYPE)
        return KAL_TRUE; //short antenna
    else
        return KAL_FALSE; //long antenna
}

/*********************************************************************
*  DSP download procedure
*  parameter-->patch_download, coefficient_download
*
*********************************************************************/
#define BUFF_SIZE 10
#define OFFSET_REG 0x91
#define CONTROL_REG 0x90
#define DATA_REG 0x92

static void MT6626_DeemphasisDownloadToDsp(const kal_uint16 *dsp_array)
{
    
    kal_uint16 data_length = 0;  // in words
    kal_uint16 i;
    data_length = dsp_array[1] - dsp_array[0] + 3;
    for(i=2; i<data_length; i++)
    {
        MT6626_WriteWord(DATA_REG, dsp_array[i]);
    }
}

static void MT6626_ParameterDownloadToDsp(const kal_uint16 *dsp_array, Download_type type)
{
    kal_uint32 CONTROL_CODE=0;
    kal_uint16 data_length = 0;  // in words
    kal_uint16 i;
    kal_uint16 data_to_write = 0;

	FM_Data_debug = KAL_FALSE;
    switch(type) 
    {
        case rom_download:  //rom code
        case patch_download:  //patch
            CONTROL_CODE = 0x10;
            break;
        case coefficient_download:  //coeff
            CONTROL_CODE = 0xe;
            break;
        case hw_coefficient_download:	//HW coeff
            CONTROL_CODE = 0xd;
            break;
        default:
        break;
    }
	
    //data_length = dsp_array[1] - dsp_array[0] + 1;  
    data_length = dsp_array[1] - dsp_array[0] + 3; 

    if(data_length > 0) 
    {
        MT6626_WriteWord(CONTROL_REG, 0);
        MT6626_WriteWord(OFFSET_REG, dsp_array[0]);		//Start address
        MT6626_WriteWord(CONTROL_REG, 0x0040); 			//Reset download control
        MT6626_WriteWord(CONTROL_REG, CONTROL_CODE); 	//Set download control

        if(type == coefficient_download)
        {
			for(i=2; i<data_length; i++) 
			{
				if(i == 88)
				{
					data_to_write = FMR_RSSI_THRESHOLD_LANT;
				} 
				else if(i == 100)
				{
					data_to_write = FMR_CQI_TH;
				} 
				else if ((i == 294) && FMR_DEEMPHASIS_50us)
				{					
					MT6626_DeemphasisDownloadToDsp(bin_coeff_deemphasis_diff);
					i += (bin_coeff_deemphasis_diff[1]-bin_coeff_deemphasis_diff[0]);
					continue;
				}
				else if (i == 507)
				{
					data_to_write = FMR_RSSI_THRESHOLD_SANT;
				}
				else
				{
				    data_to_write = dsp_array[i];
				}
				MT6626_WriteWord(DATA_REG, data_to_write);
			}
		}
		else
		{
			for(i=2; i<data_length; i++) 
			{
			    MT6626_WriteWord(DATA_REG, dsp_array[i]);
            }
        }
    } 
    else
    {
        //kal_print("MT6626_ParameterDownloadToDsp, file size ERROR!");
        ASSERT(0);
    }
	FM_Data_debug = KAL_TRUE;
}
/***********************************************************************
*  FM Chip initial
*
*  parameter-->
***********************************************************************/
void FMDrv_ChipInit(void)
{
	FMR_SleepHandle = L1SM_GetHandle();/*sleep mode handle only can get once*/

// Init Reset/Power Pin to FM
#ifdef USE_I2C
    SerialCommInit();
    SerialCommCryClkOn();
#endif
	FMDrv_AutoDetect();
}
/*detect 6626 is exist or not*/
void FMDrv_AutoDetect(void)
{
    kal_int32 i=0;
    kal_uint16 tmp_reg;

	if(chip_powered_on == 0)
	{
		BtRadio_PowerOn(1, gpio_bt_power_pin);
		kal_sleep_task(2);
		BtRadio_WriteGPIO(0, gpio_bt_reset_pin);
		kal_sleep_task(12);
		BtRadio_WriteGPIO(1, gpio_bt_reset_pin);		
	}

    SerialCommInit();
    for (i=0; i<POWER_ON_COMMAND_COUNT; i++) 
    { 
        if  (PowerOnSetting[i].addr==0xFFFD)
        {  //read status
            MT6626_ReadWord(PowerOnSetting[i].and, &tmp_reg);
            switch(PowerOnSetting[i].and)
            {
                case 0x62:
                    if(tmp_reg == 0x6626)
                    {
						FMChip_Exist = KAL_TRUE;
                    }
                    break;
                default:
                    break;
            }
        }
        else if(PowerOnSetting[i].addr==0xFFFB)
        { //delay ms
            Delayms(PowerOnSetting[i].or);
        }
        else
        {
            if(PowerOnSetting[i].and != 0)
            {
                MT6626_ReadWord(PowerOnSetting[i].addr, &tmp_reg);
                tmp_reg &= PowerOnSetting[i].and;
                tmp_reg |= PowerOnSetting[i].or;	  	
            }
            else
            {
                tmp_reg = PowerOnSetting[i].or;
            }
            MT6626_WriteWord(PowerOnSetting[i].addr, tmp_reg);
        }
    }

	/*power off chip*/
    MT6626_WriteWord(0x60, 0x330F);
    MT6626_WriteWord(FM_MAIN_CG2_CTRL, 1); 
    for(i=0; i<4; i++)
    {
        MT6626_ReadWord(0x6E, &tmp_reg);		 
        MT6626_WriteWord(0x6E, (tmp_reg&0xFFF8)); 
    }
    MT6626_WriteWord(FM_MAIN_CG1_CTRL, 0); 
    MT6626_WriteWord(FM_MAIN_CG1_CTRL, 0x4000); 
    MT6626_WriteWord(FM_MAIN_CG1_CTRL, 0); 
	if(chip_powered_on == 0)
	{
		//kal_sleep_task(2);
		BtRadio_WriteGPIO(0, gpio_bt_reset_pin);
		kal_sleep_task(12);
		//BtRadio_WriteGPIO(1, gpio_bt_reset_pin);		
		BtRadio_PowerOff(1, gpio_bt_power_pin);
	}
	FM_Detect_Done = KAL_TRUE;
}

#if defined(FM_INTERFACE_I2C)
void FMDrv_EINT_HISR(void)
{
    ilm_struct *fmr_ilm;
    //EINT_Set_Polarity(FM_EINT_NO, fm_state);//ALBERT_0123_02
    //FMR_RDS_INTR_OnOff(0);
    DRV_SendPrimitive(fmr_ilm,
                      MOD_EINT_HISR,
                      MOD_FMR,
                      MSG_ID_FMR_RDS_IND,
                      NULL,
                      FMR_SAP);
    msg_send_ext_queue(fmr_ilm);
}
#endif

/***********************************************************************
*  FM Interrupt initialize
*
*  parameter-->
***********************************************************************/
void FMDrv_IntrInit(void)
{
#if defined(FM_INTERFACE_I2C)
#if (defined(FM_EINT_SUPPORT_SEARCH)) || (defined(__FM_RADIO_RDS_SUPPORT__))
    EINT_Registration(FM_EINT_NO,KAL_FALSE,fm_state,FMDrv_EINT_HISR, KAL_FALSE);
#endif
#endif
}

/***********************************************************************
*  FMDrv_Get_stereo_mono
*
*  parameter-->
* RETURNS
*  0:mono 1:stereo
***********************************************************************/
kal_uint8 FMDrv_Get_stereo_mono(void)
{
    kal_uint16 TmpReg, value;
    MT6626_ReadWord(FM_R_RSSI, &TmpReg);
    value = (TmpReg&FM_BF_STEREO)>>12;
    return value;
}

/***********************************************************************
*  Engineer mode function (API)
*
*  parameter-->group_idx: mono\stereo\RSSI_threshold\IF_count_delta
*              item_idx: sub select index
*              item_value: set parameter value
***********************************************************************/
void FMDrv_radio_item_info(kal_uint16 group_idx, kal_uint16 item_idx, kal_uint32 item_value)
{
   kal_uint16 dataRead;
	
	MT6626_ReadWord(0x60, &dataRead); 
	MT6626_WriteWord(0x60, dataRead&(0xFFF7)); 
	MT6626_ReadWord(0x75, &dataRead); 
	switch (group_idx)
	{
		case mono:
			if(item_value)
			{
				MT6626_WriteWord(0x75, dataRead|0x0008);
			}
			else
			{
				MT6626_WriteWord(0x75, (dataRead&0xFFF7));
			}
			break;
		case stereo:
			if(item_value)
			{
				MT6626_WriteWord(0x75, dataRead&0xFFF7);
			}
			else
			{
				MT6626_WriteWord(0x75, dataRead|0x0008);
			}
			break;
        case HCC_Enable:
            if(item_idx)
            {
                MT6626_WriteWord(0x75, dataRead|0x0004);
            }
            else
            {
                MT6626_WriteWord(0x75, dataRead&(~0x0004));		
            }
        break;
		case Softmute_Enable:
			if(item_idx)
			{
				MT6626_WriteWord(0x75, dataRead |0x0001);
			}
			else
			{
				MT6626_WriteWord(0x75, dataRead&(~0x0001));		
			}
		break;
		case RSSI_threshold:
		case PAMD_threshold:
		case De_emphasis:
		case HL_Side:
		case Demod_BW:
		case Dynamic_Limiter:
		case Softmute_Rate:
		case AFC_Enable:
		case Softmute_Level:
		case Analog_Volume:
		default:
		break;
	}
	MT6626_ReadWord(0x60, &dataRead); 
	MT6626_WriteWord(0x60, dataRead|0x0008); 
	
}



kal_bool FMDrv_IsChipValid( void )
{
	if(FM_Detect_Done == KAL_FALSE)
	{
		FMDrv_AutoDetect();
	}
    return FMChip_Exist;
}

kal_uint16 FMDrv_ReadByte(kal_uint8 addr)
{
    kal_uint16 Data;
    MT6626_ReadWord(addr, &Data);
    return Data;
}

kal_bool FMDrv_WriteByte(kal_uint8 addr, kal_uint16 data)
{
    MT6626_WriteWord(addr, data);
    return KAL_TRUE;
}

void FMDrv_SetVolumeLevel(kal_uint8 level)
{

}

void FMDrv_Mute(kal_uint8 mute)
{
    kal_uint16 dataRead;
    
    MT6626_ReadWord(FM_MAIN_CTRL,&dataRead);                           
    if (mute == 1)
        MT6626_WriteWord(FM_MAIN_CTRL, (dataRead&0xFFDF)|0x0020);  
    else
        MT6626_WriteWord(FM_MAIN_CTRL, (dataRead&0xFFDF)); 
}

void FMDrv_GetIntr(kal_uint16 *dataRead)
{
    MT6626_ReadWord(FM_MAIN_INTR, dataRead);
}

void FMDrv_ClrIntr(void)
{
#if (defined(FM_EINT_SUPPORT_SEARCH)) || (defined(__FM_RADIO_RDS_SUPPORT__))
    kal_uint16 dataRead;
    
    MT6626_ReadWord(FM_MAIN_INTR, &dataRead);
    MT6626_WriteWord(FM_MAIN_INTR, dataRead);//clear status flag
    EINT_UnMask(FM_EINT_NO);
#endif
}

/*************************************************************
*  Radio power on Reset
*
*************************************************************/
void FMDrv_PowerOnReset(void)
{	
#if defined(FM_INTERFACE_I2C)	
    kal_int32 i,j=0;
    kal_uint16 tmp_reg;
    DebugSwith = KAL_FALSE;
    
    /// Power On
    FMR_TRACE(FM_INFO_FM_COMMON_POWER_ON,"FM Common Power On");
	
	/*If L1 sleep when BT use UART, BT can't get any data by UART
	  BT will wait for UART getting time out. This will increase FM power on time.
	 */
	L1SM_SleepDisable(FMR_SleepHandle);

    SerialCommInit();// pull I2C high before chip power on
#if defined(FM_INTERFACE_I2C) && defined(BT_SUPPORT)
#if defined(__FMRADIO_I2S_SUPPORT__)
	   BtRadio_Power_Handler(1, 1, 1);
#else
	   BtRadio_Power_Handler(1, 1, 0);
#endif	   
#endif

	L1SM_SleepEnable(FMR_SleepHandle);

    FMR_TRACE(FM_INFO_FM_POWER_ON_RST,"FM Power On reset");
    for (i=0; i<POWER_ON_COMMAND_COUNT; i++) 
    { 
		FMR_TRACE0(FM_ON_SEQUENCE_CMD,"power on cmd:%d",i);
        if (PowerOnSetting[i].addr==0xFFFF) 
        { //polling status=1  
			j=0;
			FM_Data_debug = KAL_FALSE;
            while(1)
            {		
                MT6626_ReadWord(PowerOnSetting[i].and, &tmp_reg);
				if(j++ >1000)
				{
					FMR_TRACE0(FM_ON_POLLING_TIMES,"power on polling 1000 times==%d\n",110);
					FMR_TRACE1( FM_INFO_READ_DATA, "Register [%x] =%x\n",PowerOnSetting[i].and,tmp_reg);
					j=0;
				}
                tmp_reg &=PowerOnSetting[i].or;
                if(tmp_reg)
                    break;
            }
			FM_Data_debug = KAL_TRUE;
        }   
        else if (PowerOnSetting[i].addr==0xFFFE)
        {  //polling status=0
			j=0;
			FM_Data_debug = KAL_FALSE;
            while(1)
            {		
                MT6626_ReadWord(PowerOnSetting[i].and, &tmp_reg);
				if(j++ >1000)
				{
					FMR_TRACE0(FM_ON_POLLING_TIMES,"power on polling 1000 times==%d\n",111);
					FMR_TRACE1( FM_INFO_READ_DATA, "Register [%x] =%x\n",PowerOnSetting[i].and,tmp_reg);
					j=0;
				}
                tmp_reg &=PowerOnSetting[i].or;
                if(!tmp_reg)
                    break;
            }      
			FM_Data_debug = KAL_TRUE;
        }
        else if  (PowerOnSetting[i].addr==0xFFFD)
        {  //read status
            MT6626_ReadWord(PowerOnSetting[i].and, &tmp_reg);
			kal_trace(TRACE_INFO, FM_INFO_FM_CHIP_ID, tmp_reg);
            switch(PowerOnSetting[i].and)
            {
                case 0x99:
					switch (tmp_reg)
                    {
                    	case 0x0:
							Chip_Version = E1;
							bin_patch = bin_patch_E1;
							bin_coeff = bin_coeff_E1;
						    break;
                        case 0x8A01:
						default:
							Chip_Version = E2;
							bin_patch = bin_patch_E2;
							bin_coeff = bin_coeff_E2;
							break;
                    }
					break;
                case 0x62:
                    Chip_ID = tmp_reg;    
                    if(Chip_ID == 0xFFFF)
                    {
                        //kal_print("MT6626 Power on reset, Chip ID is wrong!!!");
                        ASSERT(0);
                    }
                    break;
                case 0x1C:
                    if(PowerOnSetting[i].or) 
                    {
                        MT6626_WriteWord(PowerOnSetting[i].and, (tmp_reg|0x8000));
                    } 
                    else 
                    {
                        MT6626_WriteWord(PowerOnSetting[i].and, (tmp_reg&0x7FFF));
                    }
                    break;
                
                default:
                    break;
            }
        }
        else if(PowerOnSetting[i].addr==0xFFFB)
        { //delay ms
            Delayms(PowerOnSetting[i].or);
        }
        else if(PowerOnSetting[i].addr==0xFFFA)
        { //delay us
            Delayus(PowerOnSetting[i].or);
        }
        else if(PowerOnSetting[i].addr==0xFFF9)
        { //select the function that already coded
            switch(PowerOnSetting[i].or)
            {
#if defined(MT6626_FPGA)            
                case 0x01:  //DSP rom download
                    MT6626_ParameterDownloadToDsp(bin_rom, rom_download);
                    break;
#endif                    
                case 0x02:  //DSP path download
                    MT6626_ParameterDownloadToDsp(bin_patch, patch_download);
                    break;
                case 0x03:  //DSP coefficient download
                    MT6626_ParameterDownloadToDsp(bin_coeff, coefficient_download);
                    break;
                case 0x04:  //DSP HW coefficient download
                    MT6626_ParameterDownloadToDsp(bin_hw_coeff, hw_coefficient_download);
                    break;
                default:
                    ASSERT(0);
                    break;
            }
        }
        else
        {
            if(PowerOnSetting[i].and != 0)
            {
                MT6626_ReadWord(PowerOnSetting[i].addr, &tmp_reg);
                tmp_reg &= PowerOnSetting[i].and;
                tmp_reg |= PowerOnSetting[i].or;	  	
            }
            else
            {
                tmp_reg = PowerOnSetting[i].or;
            }
            MT6626_WriteWord(PowerOnSetting[i].addr, tmp_reg);
			MT6626_ReadWord(PowerOnSetting[i].addr, &tmp_reg);/*for debug*/
        }

    }
	
    FMDrv_IntrInit();   
#if 1/*disable short antenna calibration*/ 	
	MT6626_ReadWord(FM_MAIN_CG1_CTRL,&tmp_reg);
	MT6626_WriteWord(FM_MAIN_CG1_CTRL,tmp_reg&(~0x0008));
	MT6626_WriteWord(0x23,0x2000);
	MT6626_ReadWord(FM_MAIN_CG1_CTRL,&tmp_reg);
	MT6626_WriteWord(FM_MAIN_CG1_CTRL,tmp_reg|0x0008);
#endif	
 
    _is_fm_on = KAL_TRUE;
    _current_frequency = -1;
    //DebugSwith = KAL_TRUE;
	FMR_TRACE0(FM_API_EXIT,"EXIT:%d\n",11);
#endif
}


/*****************************************************************
*  Radio power off
*
*****************************************************************/
void FMDrv_PowerOffProc(void)
{
    kal_int16 i;
    kal_uint16 dataRead;
   
#ifndef USE_I2C
    kal_uint8 tmp1;
#endif
	FMR_TRACE0(FM_API_EXIT,"ENTRANCE:%d\n",21);

#if (defined(FM_EINT_SUPPORT_SEARCH)) || (defined(__FM_RADIO_RDS_SUPPORT__))
    EINT_Mask(FM_EINT_NO);
#endif
    MT6626_ReadWord(FM_MAIN_INTR, &dataRead);	
    if(dataRead & 0x1)
    {
        MT6626_WriteWord(FM_MAIN_INTR, dataRead);//clear status flag
    }
    MT6626_RampDown();
	/*Before MCUFA end, triggle BT EINT to wake up BT MCUSYS, necessary to do this after ramp down*/
	if(FM_MCUFA_OPEN)
	{
	    MT6626_ReadWord(FM_MAIN_EXTINTRMASK, &dataRead);	
		MT6626_WriteWord(FM_MAIN_EXTINTRMASK, (dataRead|0x1000));//enable sw bt eint 
	    MT6626_ReadWord(FM_MAIN_INTR, &dataRead);	
		MT6626_WriteWord(FM_MAIN_INTR, (dataRead|FM_INTR_SW_INTR));//send sw  eint 
		Delayus(100);//delay 2 32k tick at least
	    MT6626_ReadWord(FM_MAIN_INTR, &dataRead);	
		MT6626_WriteWord(FM_MAIN_INTR, (dataRead&(~FM_INTR_SW_INTR)));//clear sw  eint 
	    MT6626_ReadWord(FM_MAIN_EXTINTRMASK, &dataRead);	
		MT6626_WriteWord(FM_MAIN_EXTINTRMASK, (dataRead&(~0x1000)));//disable sw bt eint 
	}
	
	/*SW work around for MCUFA issue. 
	 *if interrupt happen before doing rampdown, DSP can't switch MCUFA back well.
	 * In case read interrupt, and clean if interrupt found before rampdown. 
	 */
    MT6626_WriteWord(0x60, 0x330F);
    MT6626_WriteWord(FM_MAIN_CG2_CTRL, 1); 
    for(i=0; i<4; i++)
    {
        MT6626_ReadWord(0x6E, &dataRead);		 
        MT6626_WriteWord(0x6E, (dataRead&0xFFF8)); 
    }
    MT6626_WriteWord(FM_MAIN_CG1_CTRL, 0); 
    MT6626_WriteWord(FM_MAIN_CG1_CTRL, 0x4000); 
    MT6626_WriteWord(FM_MAIN_CG1_CTRL, 0); 
    
#if defined(BT_SUPPORT)
    BtRadio_Power_Handler(1, 0, 0);
#endif
    
    
    _is_fm_on = KAL_FALSE;
    _current_frequency = -1;
	FMR_TRACE0(FM_API_EXIT,"EXIT:%d\n",21);
}

/*********************************************************************
*  Radio set frquency
*
*  parameter-->curf:setting frequency value
                    input value: 875 - 1080 ( 87.5 MHz - 108.0 MHz)
*********************************************************************/
void FMDrv_SetFreq( kal_int16 curf )  /* input value: 875 - 1080 ( 87.5 MHz - 108.0 MHz)*/
{

    pstFMR_data->is_searching = KAL_FALSE;
    if (_is_fm_on != 1)
    {
        FMDrv_PowerOnReset();
    }
    
    FMDrv_Mute(1);
    MT6626_SetFreq(curf);
    FreqKHz = curf;
    FMDrv_Mute(0);
}

/*********************************************************************
*  Set Antenna type
*  parameter-->Type: 1:Short Antenna, 0:Long Antenna
*
*********************************************************************/
kal_bool FMDrv_SetAntennaType(kal_uint8 ATAType)
{
	return MT6626_SetAntennaType(ATAType);
}

/*********************************************************************
*  Get Antenna type
*  parameter
*  return-->1:Short Antenna, 0:Long Antenna
*********************************************************************/
kal_uint8 FMDrv_GetAntennaType(void)
{
	return MT6626_GetAntennaType();
}

/**********************************************************************
*  Get really signal level in current frequency
*
*  parameter-->curf:frequency value of radio now
**********************************************************************/
kal_uint16 FMDrv_GetSigLvl( kal_int16 curf )
{
    kal_uint16 rssi;
	if (curf != _current_frequency)
	{
		FMDrv_SetFreq( curf );
	}
    rssi = MT6626_GetCurRSSI();
    return rssi;
}

/**********************************************************************
*  Get PAMD in current frequency
*
*  parameter-->curf:frequency value of radio now
**********************************************************************/
kal_uint16 FMDrv_GetPamdLvl( kal_int16 curf )
{
	kal_uint16 pamd, readtimes, total=0, Average_Time=0;

	if (curf != _current_frequency)
	{
		FMDrv_SetFreq( curf );
	}
	for(readtimes=0;readtimes<8;readtimes++)
	{
		pamd = MT6626_GetCurPamd();
		total += pamd;
        if (pamd != 0)
        {
            Average_Time++;
        }
		kal_sleep_task(10);	
	}
   	if(Average_Time != 0)
   	{
	    return total/Average_Time;
   	}
    else
    {
        return 0;
    }
}
/*
range:20~50dB
return dB
*/
kal_int16 FMDrv_GetMR(void)
{
	kal_uint16 RegTemp;
	kal_int16 MR;
    MT6626_ReadWord(0xBD, &RegTemp);
	RegTemp=(RegTemp&0x1FF);
	
	if(RegTemp > 255)
	{
		MR=(kal_int16)(RegTemp-512)*6/16;
	}
	else
	{

		MR=(kal_int16)RegTemp*6/16;
	}
	return MR;
}

void FMGetScanTbl(kal_uint16 *CH_TBL)
{

}
/**********************************************************************
*  Radio valid station,used in HW auto search frequency to verify 
*  valid positon
*
*  parameter-->freq: start frequency
               is_step_up:1-->forward, 0-->backward
               space:search step,0:200KHz, 1:100KHz
**********************************************************************/
void FMDrv_HWSearch(kal_int16 freq, kal_bool is_step_up, kal_int16 space, kal_bool is_preset)
{
    kal_int32 targetFreq;
    kal_uint8 UpDown_flag=1;
    kal_uint16 dataRead;
    kal_uint8 _step;
    
    if (is_step_up)
        UpDown_flag = 0;
    HWSearch_flag = 0;
    Valid_flag = 0;
    FreqSt = FreqKHz;			
    
    //calculate starting frequency
    targetFreq = (kal_int32)(freq);
    if( space )
    {// 100K
        _step = 1;
    }
    else
    { //200K
        _step = 2;
    }
    	
    //- Modified code start  
    MT6626_SetFreq(targetFreq);

    MT6626_RampDown();
    //Delayms(50);
	
    // Setting before seek    
    MT6626_ReadWord(FM_MAIN_CFG2, &dataRead);  
    MT6626_WriteWord(FM_MAIN_CFG2, (dataRead&0xFC00)|((BAND_DN-640)<<1));//set space(100k/200k)and band(875~1080)and up/down
    MT6626_ReadWord(FM_MAIN_CFG1, &dataRead);  
    MT6626_WriteWord(FM_MAIN_CFG1, (dataRead&0x8800)|(UpDown_flag<<10)|(1<<(12+_step))|((BAND_UP-640)<<1));//set space(100k/200k)and band(875~1080)and up/down
    MT6626_ReadWord(FM_MAIN_CFG1, &dataRead);

    if (!is_preset)
    {	// this is not a auto_scan function !
        MT6626_WriteWord(FM_MAIN_CFG1, dataRead&0xF7FF|0x0800); //enable wrap , if it is not auto scan function
    }else{
        MT6626_WriteWord(FM_MAIN_CFG1, dataRead&0xF7FF); //disable wrap , if it is auto scan function
    }
    
	MT6626_ReadWord(FM_MAIN_INTR, &dataRead);/*for debug*/
    if (!is_preset)
    {	// this is not a auto_scan function !
        MT6626_SEEK_ON();
    }
	else
    {
        MT6626_SCAN_ON();   
    }
}

kal_uint8 FMDrv_HWSpolling(kal_uint16 *curf, kal_uint8 *is_valid)
{

#if defined(FM_INTERFACE_I2C)
    kal_uint16 dataRead,i=0;

	FMR_TRACE0(FM_API_ENTRANCE,"ENTRANCE:%d",51);
    MT6626_ReadWord(FM_MAIN_INTR, &dataRead);
    HWSearch_flag = dataRead & FM_INTR_STC_DONE; // check STC flag 
	FM_Data_debug = KAL_FALSE;
    while( HWSearch_flag == 0)
    {
        if(pstFMR_data->bHWsearchStop == 1)
        {
            *curf = FreqSt;
            *is_valid = 0;
            /*MT6626_RampDown();this will mute after cancel scan if after tune.*/
            FMDrv_ClrIntr();
			FM_Data_debug = KAL_TRUE;
            return 0;
        }
        MT6626_ReadWord(FM_MAIN_INTR, &dataRead);
		if(i++ >1000)
		{
			FMR_TRACE0(FM_ON_POLLING_TIMES,"power on polling 1000 times==%d\n",50);
			FMR_TRACE1( FM_INFO_READ_DATA, "Register [%x] =%x\n",FM_MAIN_INTR,dataRead);
			i=0;
		}
        HWSearch_flag = dataRead & FM_INTR_STC_DONE; // check STC flag 
        Valid_flag = 1;
        kal_sleep_task(5);
    }
	FM_Data_debug = KAL_TRUE;
    MT6626_ReadWord(FM_MAIN_INTR, &dataRead);
    MT6626_WriteWord(FM_MAIN_INTR, (dataRead&0xFFFE)|0x0001);//clear status flag	

    MT6626_ReadWord(FM_MAIN_INTR, &dataRead);/*for dbg*/
#if defined(MT6626_FPGA)
    MT6626_WriteWord(0x54, 0x0001);
    MT6626_WriteWord(0x11, 0xB7d4);
    MT6626_WriteWord(0x54, 0x8000);
#endif
	
    MT6626_ReadWord(FM_STAT1, &dataRead);
    MT6626_WriteWord(FM_CHANNEL_SET, (dataRead&HOST_CHAN)>>4);
    FreqKHz = 640 + ((dataRead & MASK_READCHAN )>> (SHIFT_READCHAN+1) );			
    if(FreqKHz > 1080)
        FreqKHz = 1080;
    else if(FreqKHz < 875)
        FreqKHz = 875;
#endif
    if (HWSearch_flag != 0)
    {
        MT6626_GetSearchFreq(curf); 
        if (Valid_flag == 1)
            *is_valid = 1;
        else
            *is_valid = 0;
		FMR_TRACE0(FM_API_EXIT,"EXIT:%d",511);
        return 1;
    }
    else
    {
		FMR_TRACE0(FM_API_EXIT,"EXIT:%d",510);
        return 0;
    }
}


/**********************************************************************
*  Radio valid station,used in auto search frequency to verify 
*  valid positon
*
*  parameter-->freq: destination frequency
               signalv1:not used 
               is_step_up:search direction,1. search up,0. search down
 *retrun: 0, dest freq is invalid, other valid
**********************************************************************/
kal_uint8 FMDrv_ValidStop(kal_int16 freq, kal_int8 signalvl, kal_bool is_step_up)
{
	kal_uint8 cnt;
	kal_uint16 RSSIValue=0,PAMD=0;
	FMDrv_SetFreq(freq);
    RSSIValue = FMDrv_GetSigLvl(freq);
	kal_trace(TRACE_INFO,FM_INFO_SortTuneRssi,freq,RSSIValue);
	if(RSSIValue > (((FMR_RSSI_THRESHOLD_LANT-65536)*6/16)+113))
	{
		RSSIValue = MT6626_GetCurPamd();
		kal_trace(TRACE_INFO, FM_INFO_FM_PAMD_LVL, _current_frequency, RSSIValue);
		PAMD = FMR_CQI_TH&0x1FF;
		PAMD = (PAMD>=256) ? ((512-PAMD)*6/16):0;
		kal_trace(TRACE_INFO, FM_INFO_FM_PAMD_LVL, _current_frequency, PAMD);
		if(RSSIValue >= PAMD)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

void FMDrv_GetScanTbl(kal_uint16 *BitMapData, kal_uint8 offset)
{
    
    MT6626_ReadWord(RDS_DATA_REG, &BitMapData[offset]);  
}

void FMDrv_HCI_Event_Hdlr(kal_bool isReadyRead)
{
    return;
}

kal_uint32 FMDrv_GetCapArray(void)
{
    kal_uint8 i=0;
    kal_uint16 regData=0, capValue=0;
    kal_uint32 cookedCapValue=0;

	kal_uint32 chara[] = { 165, 330, 660, 1320,
                           2640, 5280, 10560, 21120 };
	
    MT6626_ReadWord(0x60, &regData);
    MT6626_WriteWord(0x60, regData&0xFFF7);
	
    MT6626_ReadWord(0x25, &regData);
    
	capValue = regData >> 8;


	for(i=0;i<8;i++)
    {
        if((capValue >> i)&0x0001)
        {
            cookedCapValue += chara[i];
        }
    }
	
    MT6626_ReadWord(0x60, &regData);
    MT6626_WriteWord(0x60, regData|0x8);

	return cookedCapValue;
	
}
/***********************************************************************
*  FM Chip Reset
*
*  parameter-->
***********************************************************************/
void FMDrv_ChipReset(void)
{

    kal_int16 temp_curFreq = _current_frequency;
	
    BtRadio_Power_Handler_Force_Reset(1);
	//kal_print("reset common 1 is done!");
	BtRadio_Power_Handler(1, 0, 0);
	//kal_print("reset common 2 is done!");
	FMDrv_PowerOnReset();
	//kal_print("reset 1");
    FMDrv_SetAntennaType(is_shortAntenna);
	//kal_print("reset 2");
	FMDrv_SetFreq(temp_curFreq);
	//kal_print("reset 3");
#ifdef __FM_RADIO_RDS_SUPPORT__
	if(isRdsOn)
    {
		//kal_print("reset, RDS ON!");
        FMDrv_RDS_Enable();
    }
    else
    {
		//kal_print("reset, RDS OFF!");
        FMDrv_RDS_Disable();
    }
#endif
}
/*****************************************************************************
* FUNCTION
*  FMDrv_HCI_Send_Cmd
* DESCRIPTION
*  send HCI command
* PARAMETERS
*  Opcode, data
* RETURNS
*  void
*****************************************************************************/
void FMDrv_HCI_Send_Cmd(kal_uint8 Opcode, kal_uint8 *data)
{

}
kal_bool FMDrv_Seek_Eliminate(kal_uint16 rFreq, kal_uint16 RSSI)
{
	kal_uint16 RssiTemp;	
	kal_bool EmptyChannel = KAL_FALSE;
	FMDrv_Mute(1);
	FMDrv_SCAN_Sort_Tune_Internal(rFreq,&RssiTemp);
	if(RssiTemp < RSSI)
	{
		EmptyChannel = KAL_TRUE;
	}
	//ramp down
	MT6626_RampDown();
	//dsiable mute
	FMDrv_Mute(0);
	return EmptyChannel;
}
kal_bool FMDrv_SCAN_Sort_Tune(FMR_SCAN_Sort_Data *p_SortData,kal_uint8 rChannelNo)
{
    kal_uint8 i;

    //enable mute
	FMDrv_Mute(1);
    for(i = 0; i < rChannelNo; i++)
    {
        if(!pstFMR_data->bHWsearchStop)
        {
            FMDrv_SCAN_Sort_Tune_Internal(p_SortData[i].ChannelNo,&p_SortData[i].RSSI);//get rssi
        }
        else
        {
			//MT6626_RampDown();
			//FMDrv_Mute(0);
            return KAL_FALSE;
        }
    }
    //ramp down
    MT6626_RampDown();
    //dsiable mute
	FMDrv_Mute(0);

    return KAL_TRUE;
}
void FMDrv_SCAN_Sort_Tune_Internal(kal_uint16 freq,kal_uint16 *p_RSSI)
{
	kal_uint32 CHAN = 0x0000;
	kal_uint16 dataRead,RSSIValue=0,tempbuff=0;
    kal_uint8 cnt=0,GetTime=4;
    //ramp down
    MT6626_RampDown();
    CHAN = (freq - 640)<<1;
    MT6626_ReadWord(FM_CHANNEL_SET, &dataRead);
    if(Chip_Version == E1)
    {
        if(((kal_uint8)((dataRead & 0x1000)>>12)) ^ (channel_parameter[freq - 760] & 0x1))
        {
            MT6626_ReadWord(0x61, &tempbuff);
    		MT6626_WriteWord(0x60, 0x330F);
    		MT6626_WriteWord(0x61, 0x0001); 
            MT6626_WriteWord(0x6e, 0x0);		
            MT6626_WriteWord(0x6e, 0x0);		
            MT6626_WriteWord(0x6e, 0x0);		
            MT6626_WriteWord(0x6e, 0x0);		
            MT6626_WriteWord(0x60, 0x0);		
            MT6626_WriteWord(0x60, 0x4000);
            MT6626_WriteWord(0x60, 0x0);		
            MT6626_WriteWord(0x60, 0x3000);		
            MT6626_WriteWord(0x60, 0x3001);		
            Delayms(3);
            MT6626_WriteWord(0x60, 0x3003);		
            MT6626_WriteWord(0x60, 0x3007);		
            MT6626_WriteWord(0x60, 0x300f);
            MT6626_WriteWord(0x61, tempbuff | 0x0003);		
            MT6626_WriteWord(0x61, tempbuff | 0x0002);		
			MT6626_WriteWord(0x6A, 0x0020);
			MT6626_WriteWord(0x6B, 0x0020);
            Delayms(200);	
        }
    }
    MT6626_writeFA(&dataRead, (channel_parameter[freq - 760]));
    MT6626_WriteWord(FM_CHANNEL_SET, (dataRead&0xFC00)|CHAN);
    
    MT6626_TUNE_ON();	
    do 
    {    
		if(pstFMR_data->bHWsearchStop)/*if search abort, cancel polling*/
		{
			return;
		}
        MT6626_ReadWord(FM_MAIN_INTR, &dataRead);        
        if((dataRead & FM_INTR_STC_DONE) == 0)
        {
            kal_sleep_task(3);
        }        
    } while ((dataRead & FM_INTR_STC_DONE)==0);
	MT6626_WriteWord(FM_MAIN_INTR, dataRead|FM_INTR_STC_DONE);//clear status flag

   	for(cnt=0; cnt<GetTime; cnt++)
   	{
   	    RSSIValue += FMDrv_GetSigLvl(freq);
        Delayus(2250);
   	}
    *p_RSSI = RSSIValue/GetTime;
	kal_trace(TRACE_INFO,FM_INFO_SortTuneRssi,freq,RSSIValue/GetTime);
    
    return;
}
/**APIs for EM**/
kal_uint32 FMDrv_GetRSSITH(kal_uint8 type)/*0: long ant. 1: short ant.*/
{
	kal_uint32 RSSI_TH;
	if(type == 0)
	{
		RSSI_TH = FMR_RSSI_THRESHOLD_LANT;
	}
	else
	{
		RSSI_TH = FMR_RSSI_THRESHOLD_SANT;
	}
	return RSSI_TH;
}
void FMDrv_SetRSSITH(kal_uint8 type,kal_uint32 value)/*0: long ant. 1: short ant.*/
{
	if(type == 0)
	{
		FMR_RSSI_THRESHOLD_LANT = value;
	}
	else
	{
		FMR_RSSI_THRESHOLD_SANT = value;
	}
}
kal_int32 FMDrv_RSSI_Hex2Db(kal_uint32 Hex)
{
	kal_int32 dBValue;
	
	dBValue=Hex&0x3FF;
	dBValue = (kal_int32)((dBValue>511)?(((float)dBValue-1024)*6/16+113):((float)dBValue*6/16+113));
    
    return dBValue;
}
kal_uint32 FMDrv_RSSI_Db2Hex(kal_int32 Db)
{
	kal_int32 dBValue;
	kal_uint32 HexValue;
	dBValue = (Db-113)*16/6;
	HexValue = (kal_uint32)((dBValue < 0)?(dBValue+0x10000):(dBValue+0xFC00));
	return HexValue;
}
void FMDrv_Force_Mono(void)
{
	kal_uint16 RegTemp;
	
	MT6626_ReadWord(0x60,&RegTemp);
	MT6626_WriteWord(0x60, RegTemp&(~0x0008));/*change to SW control*/
	
	MT6626_ReadWord(0x75,&RegTemp);
	MT6626_WriteWord(0x75, RegTemp|0x0008);/*force MONO*/
	
	MT6626_ReadWord(0x60,&RegTemp);
	MT6626_WriteWord(0x60, RegTemp|0x0008);/*change to DSp control*/
}
void FMDrv_Force_Stereo(void)
{
	kal_uint16 RegTemp;

	MT6626_ReadWord(0x60,&RegTemp);
	MT6626_WriteWord(0x60, RegTemp&(~0x0008));/*change to SW control*/
	
	MT6626_ReadWord(0x75,&RegTemp);
	MT6626_WriteWord(0x75, RegTemp&(~0x0008));/*auto modulate*/
	
	MT6626_ReadWord(0x60,&RegTemp);
	MT6626_WriteWord(0x60, RegTemp|0x0008);/*change to DSp control*/
}

#endif // defined(MT6626)
