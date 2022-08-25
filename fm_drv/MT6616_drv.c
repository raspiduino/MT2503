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
 * MT6616_drv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *      FM Radio Driver (MT6616)
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/
#if (defined(MT6616))
#if !defined(FM_INTERFACE_HCI)
#define USE_I2C
#endif
#ifdef USE_I2C
//#define HW_I2C
#define FM_write_I2C_address 0xE0
#define FM_read_I2C_address 0xE1
#ifdef HW_I2C
#include "sccb_v2.h"
#endif
#endif
#include "mt6616.h"
#include "us_timer.h"
#include "eint.h"
#include "fmr_trc.h"
#include "l1_interface.h"
#include "reg_base.h"
#include "app_ltlcom.h"
#include "stack_ltlcom.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "stack_common.h"
#include "kal_trace.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#if defined (__WMT_SUPPORT__)
#include "wmt_hdlr_ext.h"
#include "mtkstp.h"
#include "drv_comm.h"
#endif
extern void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada);
extern void GPIO_PullenSetup(kal_uint16 pin, kal_bool enable);
extern void GPIO_PullSelSetup(kal_uint16 pin, kal_bool pull_up);
#if defined (__WMT_SUPPORT__)
extern kal_uint32 mtkstp_receive_data(kal_uint8 *buffer, kal_uint32 length, kal_uint8 type);
extern kal_uint32 mtkstp_send_data(kal_uint8 *buffer, kal_uint32 length, kal_uint8 type);
#if (defined(__FM_RADIO_RDS_SUPPORT__))
extern void RDS_Eint_Handler(void);
extern void RDS_EventGet(void);
#endif
static kal_eventgrpid fm_evtgrpid = NULL;
#endif
extern const kal_uint8 FM_EINT_NO;
static kal_bool fm_state = LEVEL_LOW;
//#define FPGA_Mode
//#define Test_Mode
//#define E1_Mode
//#define MT6616_DEBUG
#define ext_clk
//#define APLL_Cal_Open_Loop_Mode

extern FMR_data *pstFMR_data;
kal_bool FM_Data_debug = KAL_TRUE;

/// Global variables for current FM status
kal_int16 _current_frequency = -1;
kal_int16 _backup_frequency = -1;
static kal_bool  _is_fm_on = false;
//static bool  _is_fm_mute = false;
//static uint8 _rssi_threshold;
static kal_uint16 Chip_ID = 0;
kal_uint8 HWSearch_flag = 0;
static kal_uint8 Valid_flag = 0;
static kal_uint16 FreqKHz = 0;
kal_uint16 FreqSt = 987;

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

void FMDrv_Mute(kal_uint8 mute);
void FMDrv_EvaluateRSSIThreshold(void);
extern kal_uint8 const FM_SEEK_RSSI_THRESHOLD;
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
#ifdef FPGA_Mode
#define FPGA_INIT_COMMAND_COUNT 12
static const ctrl_word_operation FPGAInitSetting[FPGA_INIT_COMMAND_COUNT] = {
   { 0x34, 0xFFFF, 0x0001 }, 
   { 0x3D, 0xFFFF, 0x1ABA },
//FM Digital Init Part 1
   { 0x30, 0xFFFE, 0x0000 }, /// CW48  [0]    0
   { 0x34, 0xFFFE, 0x0001 }, /// CW52  [0]   1
   { 0x33, 0xF95F, 0x0000 }, /// CW51  [10] 0,[9] 0,[7] 0,[5] 0
   { 0x33, 0xFFFF, 0x0040 }, /// CW51  [6] 1 hardware control mute   
   { 0x37, 0xFC00, 0x01E0 }, /// CW55  [9:0] lower bound 88MHZ
   { 0x36, 0xFC00, 0x0370 }, /// CW54  [9:0] upper bound 108MHZ
   { 0x36, 0x87FF, 0x2800 }, /// CW54  [14:12] CHN_STEPSIZE=100KHZ, [11] SEEK_WRAP=1
   { 0x39, 0xFFFD, 0x0002 }, /// CW57  [1] 1
   { 0x33, 0xFFEF, 0x0010 }, /// CW51  [4] 1 RDS_MASK
   { 0x3D, 0xFFFF, 0x1ABA }, /// CW51  [4] 1 RDS_MASK
};
#elif defined(E1_Mode)
#if defined(ext_clk)
#define POWER_ON_COMMAND_COUNT 99
#else
#define POWER_ON_COMMAND_COUNT 106//218//237//106//143//106
#endif
static const ctrl_word_operation PowerOnSetting[POWER_ON_COMMAND_COUNT] = {
//FM Receiver Power Up
   { 0x0A, 0xFFFE, 0x8410 }, /// CW10   [15]  1,[10]  1,[4]  1,[0]  0
   { 0x01, 0xFFFD, 0x0000 }, /// CW1   [1]    0
   { 0xFFFA, 0x0000, 0x001E }, /// delay 30us
   { 0x01, 0xFFFF, 0x0002 }, /// CW1   [1]    1
   { 0xFFFA, 0x0000, 0x0032 }, /// delay 50us
   { 0x01, 0xFFDF, 0x8048 }, /// CW1  [15] 1,[6] 1,[3] 1,[5] 0
   { 0xFFFA, 0x0000, 0x000A }, /// delay 10us
   { 0x00, 0xFFFF, 0x01F7 }, /// CW0  [8:4]    1,[2:0] 1
   { 0x09, 0xFFFF, 0x0040 }, /// CW9  [6]    1
   { 0x02, 0xFFC7, 0x0038 }, /// CW2  [5:3]    111
   { 0x09, 0xFFFF, 0x0002 }, /// CW9  [1]    1   
   { 0x07, 0xFFFF, 0xC000 }, /// CW7  [15:14]    11   
//FM RF Optimize setting 
   { 0x24, 0xFFF3, 0x0000 }, /// CW36  [3:2]    00   
   { 0x0B, 0x1F87, 0x8060 }, /// CW11  [15:13]    100,[6:3]    1100
   { 0x02, 0xFE3F, 0x0080 }, /// CW2  [8:6]    010
   { 0x05, 0x3FFF, 0xC000 }, /// CW5  [15:14]    11
   { 0x05, 0xFFFB, 0x0000 }, /// CW5  [2]    0
   //test

//FM 32K Power Up 
#if defined(ext_clk)
   { 0x24, 0xFF3F, 0x00C0 }, /// CW36  [7] 1 [6] 1   
   { 0x0B, 0xFFFE, 0x0000 }, /// CW11  [0]   0
   { 0x01, 0xFFDF, 0x0000 }, /// CW1  [5]   0
#else
   { 0x0A, 0xFFFF, 0x8000 }, /// CW10  [15]    1
   { 0x24, 0xFFFF, 0x0040 }, /// CW36  [6] 1
   { 0x24, 0xFF7F, 0x0000 }, /// CW36  [7] 0
   { 0x0B, 0xFFFF, 0x0001 }, /// CW11  [0]    1
   { 0x01, 0xFFFF, 0x0020 }, /// CW1  [5]   1
   { 0xFFFA, 0x0000, 0x000A }, /// delay 10us
   { 0x00, 0xFFFF, 0x0800 }, /// CW0   [11]    1
   { 0xFFFB, 0x0000, 0x07D0 }, /// delay 2000ms
   { 0x00, 0xFFFF, 0x0400 }, /// CW0   [10]    1
   { 0xFFFB, 0x0000, 0x0001 }, /// delay 1ms
#endif
//FM ADPLL Power Up
#if defined(APLL_Cal_Open_Loop_Mode)
   { 0x1D, 0xFFFC, 0x0003 }, /// CW29  [1] 1, [0] 1
   { 0xFFFB, 0x0000, 0x0003 }, /// delay 3ms
   { 0xFFFF, 0x0022, 0x8000 }, /// Polling FMR2D_DCO_CAL_STATUS=1
   { 0x1D, 0xFFFD, 0x0004 }, /// CW29  [2] 1,[1] 0
   { 0xFFFB, 0x0000, 0x0003 }, /// delay 3ms
   { 0xFFFF, 0x0022, 0x8000 }, /// Polling FMR2D_DCO_CAL_STATUS=1
   { 0x1D, 0xFFF7, 0x0080 }, /// CW29  [3] 1,[2] 0   
   { 0xFFFB, 0x0000, 0x001E }, /// delay 30ms
   { 0xFFFF, 0x0022, 0x8000 }, /// Polling FMR2D_DCO_CAL_STATUS=1
   { 0x1D, 0xFF77, 0x0080 }, /// CW29  [7] 1 [3] 0
   { 0x28, 0xFDFF, 0x0200 }, /// CW40  [9]    1
#else
  { 0x21, 0x00FF, 0x8800 }, /// CW33  [15:12] = "8", Set FMCR_DLF_GAIN_A = "8", [11:8] = "8", Set FMCR_DLF_GAIN_B = "8"
  { 0x1D, 0xFFFF, 0x0001 }, /// CW29  [0] 1
  { 0x1D, 0xFFFF, 0x0002 }, /// CW29  [1] 1
  { 0xFFFB, 0x0000, 0x0003 }, /// delay 3ms
  { 0xFFFF, 0x0022, 0x8000 }, /// Polling FMR2D_DCO_CAL_STATUS=1  //xxxx
  { 0x1D, 0xFFFD, 0x0004 }, /// CW29  [1] 0   [2] 1
  { 0xFFFB, 0x0000, 0x0003 }, /// delay 3ms
  { 0xFFFF, 0x0022, 0x8000 }, /// Polling FMR2D_DCO_CAL_STATUS=1
  { 0x1D, 0xFFFB, 0x0010 }, /// CW29  [2] 0,[4] 1
  { 0x28, 0xFFFF, 0x0200 }, /// CW40  [9]    1
#endif

//FM RC Calibration
   { 0x00, 0xFFFF, 0x0200 }, /// CW0   [9]    1
   { 0xFFFB, 0x0000, 0x0002 }, /// delay 1us
   { 0x19, 0xFFFF, 0x0001 }, /// CW25   [0]    1
   { 0xFFFA, 0x0000, 0x00C8 }, /// delay 200us
   { 0x19, 0xFFFE, 0x0000 }, /// CW25   [0]    0 
   { 0x00, 0xFDFF, 0x0000 }, /// CW0   [9]    0
//FM VCO Enable
   { 0x00, 0xFFFF, 0x8000 }, /// CW0   [15]    1
   { 0xFFFB, 0x0000, 0x0002 }, /// delay 2ms
   { 0x01, 0xFFFF, 0x0014 }, /// CW1  [2] 1,[4] 1
   { 0x00, 0xEFFF, 0x1000 }, /// CW0   [12]    1
   { 0xFFFA, 0x0000, 0x0064 }, /// delay 10us
   { 0x00, 0xFFFF, 0x6000 }, /// CW0  [14] 1,[13] 1
   //test
//FM Digital Init Part 1
   { 0x30, 0xFFFE, 0x0000 }, /// CW48  [0]    0
   { 0xFFFD, 0x0032, 0x0000 }, /// Readback HWVER code
   { 0x34, 0xFFFE, 0x0001 }, /// CW52  [0]   1
   { 0x33, 0xFDFF, 0x04A0 }, /// CW51  [10] 1,[9] 0,[7] 1,[5] 1
   { 0x83, 0xFFFF, 0x0003 }, /// CW131  Enable SW muting[1]1 [0]1    
   { 0x33, 0xFFBF, 0x0000 }, /// CW51  [6] 0 hardware control mute
   { 0x37, 0x0000, 0x0000 }, /// CW55  [9:0] lower bound
   { 0x36, 0x0000, 0x2000 }, /// CW54  [9:0] upper bound
   { 0x39, 0x0000, 0x0002 }, /// CW57  [1] 1, others 0
//Enable IQ Cal Tone for low channel
   { 0x28, 0xFFFF, 0x0001 }, /// CW40  [0] 1
   { 0xFFFB, 0x0000, 0x0002 }, /// delay 2ms
   { 0x28, 0xFFFF, 0x0082 }, /// CW40  [7] 1,[1] 1
   { 0xFFFB, 0x0000, 0x0001 }, /// delay 1ms
   { 0x28, 0xFFEF, 0x0020 }, /// CW40  [5] 1,[4] 0
   { 0x28, 0xFFFF, 0x0008 }, /// CW40  [3] 1
   { 0x26, 0xFFFF, 0x7C02 }, /// CW38  [14:10] 1 [1] 1  
   { 0x00, 0xFFFF, 0x0008 }, /// CW0  [3] 1
   { 0xFFFB, 0x0000, 0x000A }, /// delay 10ms
//Power-on IQ cal for low channel
  { 0x0C, 0xFC00, 0x0180 }, /// CW12  Set CHAN 83.2KHZ
  { 0x33, 0xFFFF, 0x0008 }, /// CW51  [3] 1
  { 0xFFFF, 0x0039, 0x0002 }, /// Polling IQCAL_DONE status=1
  { 0x39, 0x0000, 0x0002 }, /// Clear IQCAL_DONE status flag 
  { 0x2F, 0x0000, 0x0001 }, /// CW47  [1:0] 1 Page Num=1
  { 0xFFFD, 0x0048, 0x0042 }, /// Readback eps_opt and phi_opt, write to seg1_eps&seg1_phi
  { 0x45, 0xBFFF, 0x4000 }, /// [14] 1,Set rgf_iqcal_clr = 1 
  { 0x45, 0xBFFF, 0x0000 }, /// [14] 0,Set rgf_iqcal_clr = 0   
  { 0x2F, 0x0000, 0x0000 }, /// CW47  [1:0] 0 Page Num=0   
  { 0x33, 0xFFF7, 0x0000 }, /// CW51  [3] 0
//Enable IQ Cal Tone for high channel
  { 0x28, 0xFFD7, 0x0000 }, /// CW40  [5] 0,[3] 0
  { 0x28, 0xFFFF, 0x0030 }, /// CW40  [5] 1,[4] 1
  { 0x28, 0xFFFF, 0x0008 }, /// CW40  [3] 1
//Power-on IQ cal for high channel
  { 0x0C, 0xFC00, 0x0320 }, /// CW12  Set CHAN 104KHZ
  { 0x33, 0xFFFF, 0x0008 }, /// CW51  [3] 1
  { 0xFFFF, 0x0039, 0x0002 }, /// Polling IQCAL_DONE status=1
  { 0x39, 0x0000, 0x0002 }, /// Clear IQCAL_DONE status flag  
  { 0x2F, 0x0000, 0x0001 }, /// CW47  [1:0] 1 Page Num=1
  { 0xFFFD, 0x0048, 0x0043 }, /// Readback eps_opt and phi_opt, write to seg2_eps&seg2_phi
  { 0x45, 0xBFFF, 0x4000 }, /// [14] 1,Set rgf_iqcal_clr = 1 
  { 0x45, 0xBFFF, 0x0000 }, /// [14] 0,Set rgf_iqcal_clr = 0   
  { 0x2F, 0x0000, 0x0000 }, /// CW47  [1:0] 0 Page Num=0
  { 0x33, 0xFFF7, 0x0000 }, /// CW51  [3] 0
//Disable IQ Cal Tone
  { 0x28, 0xFFD7, 0x0000 }, /// CW40  [5] 0,[3] 0
  { 0x28, 0xFF7D, 0x0000 }, /// CW40  [7] 0,[1] 0
  { 0xFFFB, 0x0000, 0x0001 }, /// delay 1ms
  { 0x28, 0xFFFE, 0x0000 }, /// CW40  [0] 0
  { 0x26, 0x0000, 0x0000 }, /// CW38  [15:0] 0
  { 0x00, 0xFFF7, 0x0000 }, /// CW00  [3] 0      
//FM Digital Init Part 2
  { 0x3A, 0xFFFD, 0x0000 }, /// CW58  [1] 0
  { 0x3B, 0x0000, 0x0000 }, /// CW59  [5] [0] 1 
  { 0x2F, 0x0000, 0x0001 }, /// CW47  [1:0] 1 Page Num=1
  { 0x42, 0xFFFF, 0x8000 }, /// CW66  [15] 1 
  { 0x44, 0xFFFF, 0x8000 }, /// CW68  [15] 1
  { 0x44, 0xFC00, 0x0208 }, /// CW68  [9:0] 0X208=90MHZ
  { 0x2F, 0x0000, 0x0000 }, /// CW47  [1:0] 0 Page Num=0
  { 0x33, 0xFFFF, 0x0040 }, /// CW51  [6] 1   
  { 0x4F, 0xFFFB, 0x0000 }, /// CW79  [2] 0  
  { 0x0A, 0xFDFF, 0x0000 }, /// CW10  [9] 0   
}; 
#else
#if defined(ext_clk)
#define POWER_ON_COMMAND_COUNT 331
#else
#define POWER_ON_COMMAND_COUNT 333//218//237//106//143//106
#endif
static const ctrl_word_operation PowerOnSetting[POWER_ON_COMMAND_COUNT] = {
 //A00:Switch to FM LDO
   { 0x25, 0, 0x1A00 },
   { 0xFFFA, 0, 0x0001 }, //wait 1us
   { 0x25, 0, 0x1A10 },
//A0:Turn on 4.3V Bandgap and 4.3V to 2.8V LDO
   { 0x25, 0, 0x1A90 },
   { 0x25, 0, 0x1AD0 },
   { 0xFFFA, 0, 0x001E },  //wait 30us
   { 0x25, 0, 0x1A90 },
   { 0xFFFB, 0, 0x0001 }, //wait 1ms
//A1:Turn on BIAS_CORE circuit and output bandgap voltage
   { 0x0A, 0, 0xF614 },
   { 0xFFFA, 0, 0x001E },  //wait 30us
   { 0x01, 0, 0x0002 },
   { 0xFFFA, 0, 0x0032 },  //wait 50us
//A2:Turn on all the LDOS of FM circuits
   { 0x01, 0, 0x804A },
   { 0xFFFA, 0, 0x000A },  //wait 10us
//A3:Turn on all the FM receiver circuits
   { 0x00, 0, 0x01F6 },
//A5:FM RF Optimize setting
   { 0x09, 0, 0x7B56 },
   { 0x02, 0, 0x6CBE },
   { 0x07, 0, 0xD968 },
   { 0x24, 0, 0x5080 },
   { 0x0B, 0, 0x80E5 },
   { 0x05, 0, 0xC14B },
   { 0x02, 0, 0x6CBF },
   { 0x04, 0, 0x1238 },
   { 0x25, 0, 0x5A96 },
   { 0x0E, 0, 0x079C },
   { 0x10, 0, 0xFD90 },
   { 0x11, 0, 0x0270 },
   { 0x12, 0, 0xFD90 },
   { 0x13, 0, 0x0270 },
   { 0x0E, 0, 0x0794 },
//FM 32K Power Up
#if defined(ext_clk)
   { 0x24, 0, 0x50C0 },
   { 0x0B, 0, 0x80E4 },
#else
   { 0x24, 0, 0x5040 },
   { 0x01, 0, 0x806A },
   { 0xFFFA, 0, 0x000A },  //wait 10us
   { 0x00, 0, 0x09F6 },
   { 0xFFFB, 0, 0x03E8 }, /// delay 1000ms
   { 0x00, 0, 0x0DF6 },
   { 0xFFFB, 0, 0x0001 }, /// delay 1ms
#endif
//FM ADPLL Power Up
#if defined(APLL_Cal_Open_Loop_Mode)
#else
   { 0x21, 0, 0x8880 },
   { 0x1D, 0, 0x0861 },
   { 0x1D, 0, 0x0863 },
   { 0xFFFB, 0, 0x0003 }, /// delay 3ms
   { 0xFFFF, 0x0022, 0x8000 }, /// Polling FMR2D_DCO_CAL_STATUS=1
   { 0x1D, 0, 0x0861 },
   { 0x1D, 0, 0x0865 },
   { 0xFFFB, 0, 0x0003 }, /// delay 3ms
   { 0xFFFF, 0x0022, 0x8000 }, /// Polling FMR2D_DCO_CAL_STATUS=1
   { 0x1D, 0, 0x0861 },
   { 0x1D, 0, 0x0871 },
   { 0xFFFB, 0, 0x01F4 }, /// delay 500ms
   { 0x28, 0, 0x3E00 },
#endif
//FM RC Calibration
   { 0x00, 0, 0x03F6 },
   { 0xFFFA, 0, 0x0001 },  //wait 1us
   { 0x19, 0, 0x00CB },
   { 0xFFFA, 0, 0x00C8 },  //wait 200us
   { 0x19, 0, 0x00CA },
#if defined(ext_clk)
   { 0x00, 0, 0x01F6 },
#else
   { 0x00, 0, 0x0DF6 },
#endif
//FM VCO Enable
#if defined(ext_clk)
   { 0x00, 0, 0x81F6 },
#else
   { 0x00, 0, 0x8DF6 },
#endif
   { 0xFFFB, 0, 0x0002 }, /// delay 23ms
#if defined(ext_clk)
   { 0x01, 0, 0x805E },
   { 0x00, 0, 0x91F6 },
#else
   { 0x01, 0, 0x807E },
   { 0x00, 0, 0x9DF6 },
#endif
   { 0xFFFA, 0, 0x000A },  //wait 10us
#if defined(ext_clk)
   { 0x00, 0, 0xF1F6 },
#else
   { 0x00, 0, 0xFDF6 },
#endif
//FM DCOC Calibration
   { 0x30, 0, 0x0006 },
   { 0x34, 0, 0x0001 }, /// delay 23ms
   { 0x33, 0, 0x0020 },
   { 0x83, 0, 0x0AC3 },
   { 0x3A, 0, 0x0001 },
   { 0x3B, 0, 0x0001 },
   { 0x0C, 0, 0x1A08 },
   { 0x33, 0, 0x0021 },
   { 0xFFFF, 0x39, 0x0001 }, /// Polling fm_intr_stc_done=1
   { 0x39, 0, 0x0001 },
   { 0x33, 0, 0x0000 },
   { 0xFFFE, 0x3F, 0x0001 }, /// Polling stc_done=0
//FM Digital Init Part 1
   { 0x30, 0, 0x0006 },
   { 0xFFFD, 0x32, 0 }, ///Read fm_hw_ver
   { 0x34, 0, 0x0001 },
   { 0x33, 0, 0x0480 },
   { 0x83, 0, 0x0AC3 },
   { 0x37, 0, 0x0000 }, /// CW55  [9:0] lower bound
   { 0x36, 0, 0x2800 }, /// CW54  [9:0] upper bound
   { 0x3A, 0, 0x0002 },
   { 0x3B, 0, 0x0002 },
   { 0x1C, 0, 0x285B },
//Enable IQ Cal Tone for low channel
   { 0x28, 0, 0x3E01 }, /// CW40  [0] 1
   { 0xFFFB, 0, 0x0002 }, /// delay 2ms
   { 0x28, 0, 0x3E83 }, /// CW40  [7] 1,[1] 1
   { 0xFFFB, 0, 0x0001 }, /// delay 1ms
   { 0x28, 0, 0x3EA3 }, /// CW40  [5] 1,[4] 0
   { 0x28, 0, 0x3EAB }, /// CW40  [3] 1
   { 0x26, 0, 0x7C02 }, /// CW38  [14:10] 1 [1] 1
   { 0x00, 0, 0xF1FE }, /// CW0  [3] 1
   { 0xFFFB, 0, 0x000A }, /// delay 10ms
//Power-on IQ cal for low channel
  { 0x0C, 0, 0x1980 }, /// CW12  Set CHAN 83.2KHZ
  { 0x33, 0, 0x0488 }, /// CW51  [3] 1
  { 0xFFFF, 0x39, 0x0002 }, /// Polling IQCAL_DONE status=1
  { 0x39, 0, 0x0002 }, /// Clear IQCAL_DONE status flag
  { 0x2F, 0, 0x0001 }, /// CW47  [1:0] 1 Page Num=1
  { 0xFFFD, 0x0048, 0x0042 }, /// Readback eps_opt and phi_opt, write to seg1_eps&seg1_phi
  { 0x45, 0, 0x4000 }, /// [14] 1,Set rgf_iqcal_clr = 1
  { 0x45, 0, 0x0000 }, /// [14] 0,Set rgf_iqcal_clr = 0
  { 0x2F, 0, 0x0000 }, /// CW47  [1:0] 0 Page Num=0
  { 0x33, 0, 0x0480 }, /// CW51  [3] 0
//Enable IQ Cal Tone for high channel
  { 0x28, 0, 0x3E83 }, /// CW40  [5] 0,[3] 0
  { 0x28, 0, 0x3EB3 }, /// CW40  [5] 1,[4] 1
  { 0x28, 0, 0x3EBB }, /// CW40  [3] 1
//Power-on IQ cal for high channel
  { 0x0C, 0, 0x1B20 }, /// CW12  Set CHAN 104KHZ
  { 0x33, 0, 0x0488 }, /// CW51  [3] 1
  { 0xFFFF, 0x39, 0x0002 }, /// Polling IQCAL_DONE status=1
  { 0x39, 0, 0x0002 }, /// Clear IQCAL_DONE status flag
  { 0x2F, 0, 0x0001 }, /// CW47  [1:0] 1 Page Num=1
  { 0xFFFD, 0x0048, 0x0043 }, /// Readback eps_opt and phi_opt, write to seg2_eps&seg2_phi
  { 0x45, 0, 0x4000 }, /// [14] 1,Set rgf_iqcal_clr = 1
  { 0x45, 0, 0x0000 }, /// [14] 0,Set rgf_iqcal_clr = 0
  { 0x2F, 0, 0x0000 }, /// CW47  [1:0] 0 Page Num=0
  { 0x33, 0, 0x0480 }, /// CW51  [3] 0
//Disable IQ Cal Tone
  { 0x28, 0, 0x3E83 }, /// CW40  [5] 0,[3] 0
  { 0x28, 0, 0x3E01 }, /// CW40  [7] 0,[1] 0
  { 0xFFFB, 0, 0x0001 }, /// delay 1ms
  { 0x28, 0, 0x3E00 }, /// CW40  [0] 0
  { 0x26, 0, 0x0000 }, /// CW38  [15:0] 0
 #if defined(ext_clk)
  { 0x00, 0, 0xF1F7 }, /// CW00  [3] 0
 #else
  { 0x00, 0, 0xFDF7 }, /// CW00  [3] 0
 #endif
  { 0xFFFB, 0, 0x0032 }, /// delay 50ms
//FM Digital Init: fm_rgf_maincon
  { 0x3A, 0, 0x0000 },
  { 0x3B, 0, 0x0000 },
  { 0x2F, 0, 0x0001 }, /// CW47  [1:0] 1 Page Num=1
  { 0x42, 0x7FFF, 0x8000 }, /// CW66  [15] 1
  { 0x44, 0, 0xF208 }, /// CW68  [9:0] 0X208=90MHZ
  { 0x2F, 0, 0x0000 }, /// CW47  [1:0] 1 Page Num=1
  { 0x33, 0, 0x0480 }, /// CW51  [6] 1
  { 0x4F, 0, 0x0000 }, /// CW79  [2] 0
  { 0x0A, 0, 0xF414 }, /// CW10  [9] 0
  { 0x3D, 0, 0x1AB2 }, /// CW51  [6] 1
//FM Digital Init: fm_rgf_dac
  { 0x2F, 0, 0x0000 }, /// CW47  [1:0] 1 Page Num=1
  { 0x83, 0, 0x1AEB }, /// CW51  [6] 1
//FM Digital Init: fm_rgf_front
  { 0x2F, 0, 0x0000 }, /// CW47  [1:0] 1 Page Num=1
  { 0x40, 0, 0x1A44 },
  { 0x5A, 0, 0x0CF4 },
  { 0x51, 0, 0x002B },
  { 0x60, 0, 0x0301 },
  { 0x63, 0, 0x0028 },
  { 0x81, 0, 0xFF00 },
  { 0x41, 0, 0x2E2E },
  { 0x61, 0, 0x03E7 }, //search threshold
  { 0x79, 0, 0x1761 },  
  { 0x26, 0, 0x0002 },
  { 0x4F, 0, 0x0010 },
  { 0x49, 0, 0x006A },
  { 0x4A, 0, 0x0015 },
  { 0x4B, 0, 0x03C2 },
  { 0x4C, 0, 0x0069 },
  { 0x4D, 0, 0x001A },
  { 0x4E, 0, 0x03C1 },
  { 0x73, 0, 0x0001 },
  { 0x48, 0, 0x0030 },
  { 0x58, 0, 0x2302 },
  { 0x54, 0, 0x007D },
  { 0x50, 0, 0x0886 },
  { 0x65, 0, 0x0806 },
  { 0x66, 0, 0x0C0A },
  { 0x67, 0, 0x100E },
  { 0x68, 0, 0x1412 },
  { 0x69, 0, 0xB416 },
  { 0x59, 0, 0x0005 },
  { 0x55, 0, 0x1FF2 },
  { 0x62, 0, 0x0394 },
  { 0x64, 0, 0x03DC },
  { 0x56, 0, 0x01FF },
  { 0x57, 0, 0x00BC },
  { 0x47, 0, 0x0016 },
  { 0x2F, 0, 0x0001 },
  { 0x7F, 0, 0x03E7 }, //search threshold
  { 0x80, 0, 0x047B },
  { 0x62, 0, 0x0192 },
  { 0x63, 0, 0x0086 },
  { 0x68, 0, 0x0100 },
  { 0x69, 0, 0x0055 },
  { 0x6E, 0, 0x0100 },
  { 0x6F, 0, 0x0055 },
  { 0x72, 0, 0x5A00 },
  { 0x73, 0, 0xBE9B },
  { 0x64, 0, 0x0302 },
  { 0x6A, 0, 0x03DB },
  { 0x70, 0, 0x03DB },
  { 0x76, 0, 0x3888 },
  { 0x75, 0, 0x0002 },
  { 0x65, 0, 0x0003 },
  { 0x6B, 0, 0x03F8 },
  { 0x71, 0, 0x03EE },
  { 0x61, 0, 0x0024 },
  { 0x67, 0, 0x0025 },
  { 0x6D, 0, 0x03DC },
  { 0x81, 0, 0x00CD },
  { 0x82, 0, 0x01B1 },
  { 0x60, 0, 0x007D },
  { 0x66, 0, 0x007D },
  { 0x6C, 0, 0x007D },
//FM Digital Init: fm_rgf_fmx
  { 0x2F, 0, 0x0000},
  { 0xEF, 0, 0x0031 },
  { 0xF0, 0, 0x0002 },
  { 0xF5, 0, 0x00D6 },
  { 0xDD, 0, 0x3C2F },
  { 0xEA, 0, 0x3BCF },
  { 0xE3, 0, 0x0D9C },
  { 0xEB, 0, 0x0B6A },
  { 0xEC, 0, 0x0B74 },
  { 0xF7, 0, 0x1000 },
  { 0xE7, 0, 0x0400 },
  { 0x2F, 0, 0x0001 },
  { 0xBF, 0, 0xD948 },
  { 0xD1, 0, 0x3810 },
  { 0xD3, 0, 0x034F },
  { 0x2F, 0, 0x0003 },
  { 0xE7, 0, 0x27D2 },
  { 0xD1, 0, 0x0BA1 },
  { 0xD0, 0, 0x0B9E },
  { 0xCF, 0, 0x0B9C },
  { 0xCE, 0, 0x0B9A },
  { 0xCD, 0, 0x0B98 },
  { 0xCC, 0, 0x0B96 },
  { 0xCB, 0, 0x0B94 },
  { 0xCA, 0, 0x0B92 },
  { 0xC9, 0, 0x0B90 },
  { 0xC8, 0, 0x0B8E },
  { 0xC7, 0, 0x0B8C },
  { 0xC6, 0, 0x0B8A },
  { 0xC5, 0, 0x0B88 },
  { 0xC4, 0, 0x0B86 },
  { 0xC3, 0, 0x0B84 },
  { 0xC2, 0, 0x0B82 },
  { 0xC1, 0, 0x0B80 },
  { 0xC0, 0, 0x0B7E },
  { 0xBF, 0, 0x0B7C },
  { 0xBE, 0, 0x0B7A },
  { 0xBD, 0, 0x0B78 },
  { 0x2F, 0, 0x0000 },
  { 0xE9, 0, 0x0101 },
  { 0xBD, 0, 0x0562 },
  { 0x2F, 0, 0x0001 },
  { 0xD8, 0, 0x0000 },
//pamd offset table for blend
  { 0x2F, 0, 0x0002 },
  { 0xBD, 0, 0x00E8 },
  { 0xBE, 0, 0xFF28 },
  { 0xBF, 0, 0xFF28 },
  { 0xC0, 0, 0x00B8 },
  { 0xC1, 0, 0x0032 },
  { 0xC2, 0, 0x0032 },
  { 0xC3, 0, 0x0099 },
  { 0xC4, 0, 0x0019 },
  { 0xC5, 0, 0x0019 },
  { 0xC6, 0, 0x006D },
  { 0xC7, 0, 0x0035 },
  { 0xC8, 0, 0x0035 },
//pamd offset table for hcc
  { 0x2F, 0, 0x0002 },
  { 0xD5, 0, 0x0098 },
  { 0xD6, 0, 0xFF4E },
  { 0xD7, 0, 0xFF4E },
  { 0xD8, 0, 0x006D },
  { 0xD9, 0, 0x0040 },
  { 0xDA, 0, 0x0040 },
  { 0xDB, 0, 0x000B },
  { 0xDC, 0, 0x001E },
  { 0xDD, 0, 0x001E },
  { 0xDE, 0, 0x0028 },
  { 0xDF, 0, 0x0006 },
//dylim gain (set to defaul value)
  { 0xF0, 0, 0x2AC4 },
  { 0xE0, 0, 0x0006 },
  { 0xE1, 0, 0x014A },
  { 0xE2, 0, 0xFF83 },
  { 0xE3, 0, 0xFC75 },
  { 0xE4, 0, 0x0129 },
  { 0xE5, 0, 0xFFFC },
  { 0xE6, 0, 0xFE67 },
  { 0xE7, 0, 0x0119 },
  { 0xE8, 0, 0x0005 },
  { 0xE9, 0, 0xFED3 },
//rssi offset table for blend
  { 0x2F, 0, 0x0001 },
  { 0xC4, 0, 0xFFCB },
  { 0xC5, 0, 0xFFCB },
  { 0xC6, 0, 0x00FD },
  { 0xC9, 0, 0xFFF7 },
  { 0xCA, 0, 0x0008 },
  { 0xCB, 0, 0x0008 },
  { 0xCC, 0, 0xFFF6 },
//rssi offset table for hcc
  { 0x2F, 0, 0x0001 },
  { 0xDB, 0, 0x0008 },
  { 0xDC, 0, 0xFFD2 },
  { 0xDD, 0, 0xFFD2 },
  { 0xDE, 0, 0x0003 },
  { 0xDF, 0, 0xFFFD },
  { 0xE0, 0, 0xFFFD },
  { 0xE1, 0, 0x0002 },
  { 0xE2, 0, 0x0003 },
  { 0xE3, 0, 0x0003 },
  { 0xE4, 0, 0xFFFC },
  { 0xE7, 0, 0x0013 },
  { 0xE8, 0, 0x0013 },
  { 0xE9, 0, 0x0013 },
  { 0xEA, 0, 0x001C },
  { 0xEB, 0, 0x001C },
  { 0xEC, 0, 0x001C },
  { 0xED, 0, 0x0002 },
  { 0xEE, 0, 0x0002 },
  { 0xEF, 0, 0x0002 },
//last softmute gain
  { 0xD1, 0, 0x3810 },
//softmute threshold
  { 0x2F, 0, 0x0003 },
  { 0xD2, 0, 0x3FFF },
  { 0xD3, 0, 0x3FFF },
  { 0xD4, 0, 0x3FFF },
  { 0xD5, 0, 0x3FFF },
  { 0xD6, 0, 0x3FFF },
  { 0xD7, 0, 0x3FFF },
  { 0xD8, 0, 0x3FFF },
  { 0xD9, 0, 0x3CE6 },
  { 0xDA, 0, 0x3CDE },
  { 0xDB, 0, 0x3CD6 },
  { 0xDC, 0, 0x3CCE },
  { 0xDD, 0, 0x3CC6 },
  { 0xDE, 0, 0x3CBE },
  { 0xDF, 0, 0x3CB6 },
  { 0xE0, 0, 0x3CAE },
  { 0xE1, 0, 0x3CA6 },
  { 0xE2, 0, 0x3C9E },
  { 0xE3, 0, 0x3C96 },
  { 0xE4, 0, 0x3C8E },
  { 0xE5, 0, 0x3C86 },
  { 0xE6, 0, 0x3C7f },
//solve SSR variation issue
  { 0x2F, 0, 0x0000 },
  //{ 0xE2, 0, 0x3E3C },
  { 0xF1, 0, 0x1F42 },
  { 0xF2, 0, 0x218F },
  //{ 0x2F, 0, 0x0001 },
  //{ 0xFE, 0, 0x313D },
//FM Digital Init: fm_rgf_rds
  { 0x2F, 0, 0x0000 },
  { 0x9A, 0, 0x0080 },
  { 0x97, 0, 0x0001 },
};
#endif
#if defined(ext_clk)
#define POWER_OFF_COMMAND_COUNT 24
#else
#define POWER_OFF_COMMAND_COUNT 21
#endif
static const ctrl_word_operation PowerOffProc[POWER_OFF_COMMAND_COUNT] = {
 //Digital Modem Power Down
   {0x38, 0, 0x0000 }, /// CW56 [1:0] 0
   {0x2F, 0, 0x0001 }, /// CW51 [3:0]    0
   {0x4A, 0, 0x4000 }, /// CW48   [0]    1
   {0x2F, 0, 0x0000 }, /// CW62  [1:0]  0
   {0x33, 0, 0x0000 }, /// CW62  [1:0]  0
   {0x32, 0, 0x0007 }, /// CW62  [1:0]  0
   {0x3E, 0xFFFC, 0x0000 }, /// CW62  [1:0]  0
   {0x3E, 0xFFFC, 0x0000 }, /// CW62  [1:0]  0
   {0x3E, 0xFFFC, 0x0000 }, /// CW62  [1:0]  0
   {0x3E, 0xFFFC, 0x0000 }, /// CW62  [1:0]  0
   {0x28, 0, 0x3000 }, /// CW62  [1:0]  0
   {0x1D, 0, 0x0860 }, /// CW40 [9] 0
   {0x1E, 0, 0x0400 }, /// CW29 [7][4][0] 0
   {0x1E, 0, 0x0480 }, /// CW30 [7] 0
   {0x00, 0, 0x0000 }, /// CW30 [7] 1
   {0x01, 0, 0x0000 }, /// CW30 [7] 1
   {0x0A, 0, 0x7205 }, /// CW00 [15] 0
   {0x25, 0, 0x1A10 }, /// CW00 [15] 0
   #if defined(ext_clk)
   {0x28, 0, 0x1000 }, /// CW00 [15] 0
   {0xFFFB, 0, 0x000A }, /// delay 10ms
   {0x28, 0, 0x3000 }, /// CW00 [15] 0
   #endif
   {0x25, 0, 0x1A00 }, /// CW00 [15] 0
   {0xFFFA, 0, 0x0001 },  //wait 1us
   {0x25, 0, 0x1E00 }, /// CW00 [15] 0
};
#endif
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
    if (kal_query_systemInit()) {

       // minimum delay is 5
       if (u4MicroSec < 5)
          u4MicroSec = 5;

       // delay = delay / 5 ~= delay * 52 / 2^8;
       u4MicroSec = (u4MicroSec * 52) >> 8;

       // for-loop to wait
       for (; u4MicroSec > 0; --u4MicroSec)
          for (curr_qbit = COUNTER_05US; curr_qbit > 0; --curr_qbit);

       return;
	}

    // Read start qbit
    start_qbit = ust_get_current_time();

    /*******************************************************************//**
     * Calculate how many qbit should be waited. Store the result to "delay".
     * delay = delay * 13 / 12 ~= delay * 13 * 21.3333 / 2^8
     * => Limit: Maximum delay is 15,449,521 us = 15,449 ms = 15 sec
     ***********************************************************************/

    // delay * 13 * 21.333 ~= delay * 278
    u4MicroSec = u4MicroSec * 278;

    // delay / 2^8 ~= (delay >> 8) + 1 (for saving code, add one more qbit in all cases. Actually we only have to do such thing when "delay & 255 == 1"
    u4MicroSec = (u4MicroSec >> 8) + 1;

    // wait until "delay" qbits are all elapsed
    do {
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

#if defined (__WMT_SUPPORT__)
/*****************************************************************************
* FUNCTION
*  MT6616_Wait_UART_Init
* DESCRIPTION
*  wait event to indicate wmt init done
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void MT6616_Wait_UART_Init(kal_uint8 indx)
{
    kal_uint32 evt_group;
    //kal_prompt_trace(MOD_FMR, "MT6616_HCI wait event");
    kal_retrieve_eg_events( fm_evtgrpid, 1<<indx, KAL_OR_CONSUME,
                              &evt_group, KAL_SUSPEND);
   }

/*****************************************************************************
* FUNCTION
*  MT6616_UART_Init_Done
* DESCRIPTION
*  set event to indicated wmt init done
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void MT6616_UART_Init_Done(kal_uint8 indx)
{
    //kal_prompt_trace(MOD_FMR, "MT6616 HCI: set event");
    kal_set_eg_events(fm_evtgrpid, 1<<indx, KAL_OR);
}

/*****************************************************************************
* FUNCTION
*  MT6616_HCI_Send_Cmd
* DESCRIPTION
*  send HCI command
* PARAMETERS
*  Opcode, data
* RETURNS
*  void
*****************************************************************************/
void MT6616_HCI_Send_Cmd(kal_uint8 Opcode, kal_uint8 *data)
{
    kal_uint8 i,  fm_cmd[20], para_len[16]={2, 4, 2, 4, 1, 1, 2, 1, 3, 8, 8, 4, 1, 1, 1, 1};
    kal_uint32 length;

    if(fm_evtgrpid == NULL)
    {
    	fm_evtgrpid = kal_create_event_group("FM_HCI");
    }
    //kal_prompt_trace(MOD_FMR, "HCI Send Cmd Code:%x", Opcode);

    fm_cmd[0] = 0x01;
    fm_cmd[1] = 0xF6;
    fm_cmd[2] = 0xFC;
    fm_cmd[3] = *(para_len+Opcode-1); //length
    fm_cmd[4] = Opcode; //Opcode

    if(fm_cmd[3] > 1)
    {
    	for(i=0; i<(fm_cmd[3]-1); i++)
    	{
       	 fm_cmd[i+5] = *(data+i);
    	}
    }
    do
    {
        length = mtkstp_send_data(&fm_cmd[0], fm_cmd[3]+4, FM_TASK_INDX);
        if ((fm_cmd[3]+4) != length)
        {
           //kal_prompt_trace(MOD_FMR, "MT6616 HCI Send Cmd: wait uart_ready_to_write");
	    if((Opcode!=FM_SEEK_OPCODE)&&(Opcode!=FM_SCAN_OPCODE))	   
	    MT6616_Wait_UART_Init(0); //Waiting MSG_ID_UART_READY_TO_WRITE_IND
        }
        else
        {
           //kal_prompt_trace(MOD_FMR, "MT6616 HCI Send Cmd: Done");
        }
    }while((fm_cmd[3]+4) != length);
    if((Opcode!=FM_SEEK_OPCODE)&&(Opcode!=FM_SCAN_OPCODE))
    MT6616_Wait_UART_Init(Opcode);//Waiting MSG_ID_UART_READY_TO_READ_IND
}

/***********************************************************************
*  MT6616_HCI_Get_Data (internal)
*
*  parameter: None
*
***********************************************************************/
kal_bool MT6616_HCI_Get_Data(kal_uint8 Opcode, kal_uint16 *data)
{
    kal_uint8 dataM, dataL;

    if((pstFMR_data->FM_HCI_data.buffer[4]) == Opcode)
    {
        switch(Opcode)
{
		case FSPI_READ_OPCODE : //FSPI_READ_REG_OPCODE
            		//kal_prompt_trace(MOD_FMR, "Get Event Data:FM READ_BYTE");
			dataM = pstFMR_data->FM_HCI_data.buffer[7];
			dataL = pstFMR_data->FM_HCI_data.buffer[6];
   *data = (kal_uint16)(dataM<<8|dataL);
            	break;
		case FM_SEEK_OPCODE:
			//kal_prompt_trace(MOD_FMR, "Get Event Data:FM SEEK");
			dataM = pstFMR_data->FM_HCI_data.buffer[6];
			dataL = pstFMR_data->FM_HCI_data.buffer[5];
   *data = (kal_uint16)(dataM<<8|dataL);
		break;
        	default :
            	break;
       }
      return true;
   }
    return false;
}

/***********************************************************************
*  MT6616_HCI_Event_Hdlr (internal)
*
*  parameter: None
*
***********************************************************************/
static void MT6616_HCI_Event_Hdlr(void)
{
    kal_uint16 ret;
    
    do{
        ret = mtkstp_receive_data(pstFMR_data->FM_HCI_data.buffer, 3, FM_TASK_INDX);
    		//kal_prompt_trace(MOD_FMR, "GET EVENT BUFFER LEN: %x", ret);
	if(ret == 0)
		return;

        if( (0x04 != pstFMR_data->FM_HCI_data.buffer[0]) && (0xF1 != pstFMR_data->FM_HCI_data.buffer[1]) )
        {
     		//kal_prompt_trace(MOD_FMR, "Warning, FM HCI EVENT ID error");
        }

        ret = mtkstp_receive_data((pstFMR_data->FM_HCI_data.buffer+3), pstFMR_data->FM_HCI_data.buffer[2], FM_TASK_INDX);
   	 pstFMR_data->FM_HCI_data.event = pstFMR_data->FM_HCI_data.buffer[4];
	 if(ret > 0)
	 {
    		switch(pstFMR_data->FM_HCI_data.buffer[4])
    		{
			case FM_SEEK_OPCODE:
				//kal_prompt_trace(MOD_FMR, "GET EVENT:FM SEEK FINISH");
				if(pstFMR_data->FM_HCI_data.buffer[2] == 4)
				{
					MT6616_HCI_Get_Data(FM_SEEK_OPCODE, &ret);
					FreqKHz = ret/10;
					Valid_flag = 1;
					HWSearch_flag = 1;
				}
       			//  MT6616_UART_Init_Done(FM_SEEK_OPCODE);
			break;
			case FM_SCAN_OPCODE:
				//kal_prompt_trace(MOD_FMR, "GET EVENT:FM SCAN FINISH");
				if(pstFMR_data->FM_HCI_data.buffer[2] == 0x22)
				{
    					Valid_flag = 1;
					HWSearch_flag = 1;
				}
				//  MT6616_UART_Init_Done(FM_SCAN_OPCODE);
			break;
#if (defined(__FM_RADIO_RDS_SUPPORT__))
			case RDS_DATA_OPCODE:
				RDS_Eint_Handler();
			break;
#endif			
       		default :
  				//kal_prompt_trace(MOD_FMR, "GET EVENT:%x", pstFMR_data->FM_HCI_data.buffer[4]);
				MT6616_UART_Init_Done(pstFMR_data->FM_HCI_data.buffer[4]);
       		break;
    		}
	 }
    }while(ret > 0);
}
#endif

kal_bool MT6616_ReadByte(kal_uint8 CW, kal_uint16 *data)
{
#if defined(USE_I2C)
   #ifdef HW_I2C
   sccb_config_struct config;
   i2c_init();
/***************************Config SCCB for FM***************************/
   config.sccb_mode= SCCB_HW_16BIT ; 	 
   config.get_handle_wait=KAL_TRUE;	 
   config.slave_address= FM_write_I2C_address; 
   config.delay_len = 0 ;
   config.transaction_mode=SCCB_TRANSACTION_FAST_MODE;
   config.Fast_Mode_Speed=100;
   i2c_config(SCCB_OWNER_FM,&config);
   *data=sccb_read(SCCB_OWNER_FM,CW);
   return true;
#else
   kal_uint8 dataM, dataL;
   SerialCommStart();                /// send the start sequence
   SerialCommTxByte(FM_write_I2C_address);   /// device ID and R/W bit
   SerialCommTxByte(CW);             /// control word
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
   return true;
#endif
#elif defined(FM_INTERFACE_HCI)
   kal_bool status;

   MT6616_HCI_Send_Cmd(FSPI_READ_OPCODE, &CW);
   status = MT6616_HCI_Get_Data(FSPI_READ_OPCODE, data);
   return true;
#else
#error "Must define USE_I2C or FSPI"
#endif
}

kal_bool MT6616_WriteByte(kal_uint8 CW, kal_uint16 data)
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
#elif (defined(USE_I2C))&&(defined(HW_I2C))
   sccb_config_struct config;
   i2c_init();
/***************************Config SCCB for FM***************************/
   config.sccb_mode= SCCB_HW_16BIT ; 
   config.get_handle_wait=KAL_TRUE;	 
   config.slave_address= 0xE0; 
   config.delay_len = 0 ;
   config.transaction_mode=SCCB_TRANSACTION_FAST_MODE;
   config.Fast_Mode_Speed=100;
   i2c_config(SCCB_OWNER_FM,&config);
   sccb_write(SCCB_OWNER_FM, CW, data);
#elif defined(FM_INTERFACE_HCI)
    kal_bool status;
    kal_uint8 buffer[3];
	
    buffer[0] = CW;
    buffer[1] = data&0xFF;
    buffer[2] = data>>8;

    MT6616_HCI_Send_Cmd(FSPI_WRITE_OPCODE, &buffer[0]);
#else
#error "Must define USE_I2C or FSPI"
#endif 
   return true;
}
/***********************************************************************
*  Turn on/off tune (internal)
*
*  parameter-->ON_OFF: 1:ON, 0:OFF
*         
***********************************************************************/
void MT6616_TUNE_ON()
{
	kal_uint16 dataRead;
	MT6616_ReadByte(FM_MAIN_CTRL, &dataRead);
	MT6616_WriteByte(FM_MAIN_CTRL, (dataRead&0xFFFE)|0x0001);
}

/***********************************************************************
*  Seek on/off (internal)
*
*  parameter-->ON_OFF: 1:ON, 0:OFF
*         
***********************************************************************/
void MT6616_SEEK_ON()
{
	kal_uint16 dataRead;
	MT6616_ReadByte(FM_MAIN_CTRL, &dataRead);
	MT6616_WriteByte(FM_MAIN_CTRL, (dataRead&0xFFFD)|0x0002);
}

/***********************************************************************
*  Scan on/off (internal)
*
*  parameter-->ON_OFF: 1:ON, 0:OFF
*         
***********************************************************************/
void MT6616_SCAN_ON()
{
	kal_uint16 dataRead;
	MT6616_ReadByte(FM_MAIN_CTRL, &dataRead);
	MT6616_WriteByte(FM_MAIN_CTRL, (dataRead&0xFFFB)|0x0004);
}

/***********************************************************************
*  Hi-Lo Side Injection
*
***********************************************************************/
#define HiSideTableSize 0
void MT6616_HL_Side_Adj(kal_int16 freq)
{
  kal_bool isHiSide = false;
  kal_uint16 dataRead,indx;
  static kal_int16 Hi_Channels[7] =
{ 769, 808, 846, 923, 961, 1000, 1038 };

  if(HiSideTableSize == 0)
  return;
  dataRead = sizeof(Hi_Channels)/sizeof(Hi_Channels[0]);
  for(indx=0; indx<dataRead; indx++)
  {
  	if(Hi_Channels[indx] == freq)
  		isHiSide = true;
  }
  if(isHiSide)
  {
  	//Set high-side injection (AFC)
  	MT6616_ReadByte(0x0C, &dataRead);
  	MT6616_WriteByte(0x0C, (dataRead&0xFBFF)|0x0400);
  	MT6616_WriteByte(0x2F, 0);
  	//Set high-side injection (DFE)
  	MT6616_ReadByte(0x4F, &dataRead);
  	MT6616_WriteByte(0x4F, (dataRead&0xFFFE)|0x0001);
  }
  else
  {
  	//Set low-side injection (AFC)
   	MT6616_ReadByte(0x0C, &dataRead);
  	MT6616_WriteByte(0x0C, dataRead&0xFBFF);
  	MT6616_WriteByte(0x2F, 0);
  	//Set low-side injection (DFE)
  	MT6616_ReadByte(0x4F, &dataRead);
  	MT6616_WriteByte(0x4F, dataRead&0xFFFE);
  }
}

/***********************************************************************
*  ADPLL Power Up
*
***********************************************************************/
void MT6616_ADPLL_PowerUp(void)
{
    kal_uint16 reg_value, f16mode_enable;
     
    // change DLF loop gain  
    // Set FMCR_DLF_GAIN_A = "8"
    // Set FMCR_DLF_GAIN_B = "8"
    MT6616_WriteByte(0x21, 0x8880);
    
    // C1. Enable ADPLL DCO	Set
    // FMCR_DCO_EN = ¡§1¡¨
    MT6616_ReadByte(0x1D, &reg_value);
    f16mode_enable = reg_value&0x0200;
    MT6616_WriteByte(0x1D, f16mode_enable|0x0861);    
    
    // C2. Turn on coarse calibration
    // Set FMCR_COARSE_EN = ¡§1¡¨
    MT6616_WriteByte(0x1D, f16mode_enable|0x0863);    
    // wait 10ms 
    Delayms(10);     

    // C3. Check DCO calibration status	
    // Poll FMR2D_DCO_CAL_STATUS = "1"
    do
    {
        MT6616_ReadByte(0x22, &reg_value);
    }while (0x0000 == (reg_value & 0x8000));
    
    // C4. Turn on fine_A calibration
    // Set FMCR_CAL_COARSE_EN = "0"
    MT6616_WriteByte(0x1D, f16mode_enable|0x0861);
    // Set FMCR_FINE_A_EN = "1"
    MT6616_WriteByte(0x1D, f16mode_enable|0x0865);
    // wait 10ms 
    Delayms(10);
    
    // C5. Check DCO calibration status
    // Poll FMR2D_DCO_CAL_STATUS = "1"    
    do
    {
        MT6616_ReadByte(0x22, &reg_value);
    }while (0x0000 == (reg_value & 0x8000));
    
    // C6. Enable Close-loop mode
    // Set FMCR_FINE_A_EN = "0"
    MT6616_WriteByte(0x1D, f16mode_enable|0x0861);
    // Set FMCR_PLL_EN = "1"
    MT6616_WriteByte(0x1D, f16mode_enable|0x0871);
    
    // C9. Disable fm adc ck top clock gating
    // Set rgfrf_top_ck = "1"
    MT6616_WriteByte(0x28, 0x3200);      
}

/***********************************************************************
*  ADPLL Power Down
*
***********************************************************************/
void MT6616_ADPLL_PowerDown(void)
{
    kal_uint16 reg_value;
    
    // 2. ADPLL Power Off Sequence
    // Set rgfrf_top_ck = "0"
    MT6616_ReadByte(0x28, &reg_value);
    reg_value &= ~0x0200; 
    MT6616_WriteByte(0x28, reg_value); 
    // Set FMCR_OPEN_LOOP_EN = "0"
    // Set FMCR_PLL_EN = "0"
    // Set FMCR_DCO_EN = "0"
    MT6616_ReadByte(0x1D, &reg_value);
    reg_value &= ~0x0091;        
    MT6616_WriteByte(0x1D, reg_value);       
    // Set rgfrf_adpll_reset_n = "0"
    MT6616_ReadByte(0x1E, &reg_value);
    reg_value &= ~0x0080;        
    MT6616_WriteByte(0x1E, reg_value);               
    // Set rgfrf_adpll_reset_n = "1"
    reg_value |= 0x0080;                
    MT6616_WriteByte(0x1E, reg_value);         
}

/***********************************************************************
*  Frequency Avoidance
*
***********************************************************************/
void MT6616_Freq_Avoid(kal_int16 freq)
{
  kal_bool isADPLL_16M = false;
  kal_uint16 dataRead,indx;
  static kal_int16 Avoid_Channels[28] =
  { 767, 768, 769, 770, 806, 807, 808, 844, 845, 846,
    883, 884, 920, 921, 922, 923, 960, 961, 998, 999,
    1000, 1036, 1037, 1038,1074, 1075, 1076, 1077};

  dataRead = sizeof(Avoid_Channels)/sizeof(Avoid_Channels[0]);
  for(indx=0; indx<dataRead; indx++)
  {
  	if(Avoid_Channels[indx] == freq)
		isADPLL_16M = true;
  }
  //isADPLL_16M = 1;
  MT6616_ReadByte(0x1d, &dataRead);
  if(((dataRead&0x0200)&&(isADPLL_16M))||(!(dataRead&0x0200)&&(!isADPLL_16M)))
  return;
  //Set rgf_fm_mclk_sel = 0
  MT6616_WriteByte(0x38, 0);
  
  //Set rgf_auto_mclk_sel_en = 0 (only if muclk desense option is enabled)
  /*MT6616_WriteByte(0x2F, 1);
  MT6616_ReadByte(0x4A, &dataRead);
  MT6616_WriteByte(0x4A, dataRead&0xF7FF);
  MT6616_WriteByte(0x2F, 0);*/
  
  // Set rgf_pdn_fm = 1
  MT6616_ReadByte(0x30, &dataRead);
  MT6616_WriteByte(0x30, dataRead|0x0007);
   
  //Set rgfrf_enable_top_ck ="0"
  MT6616_ReadByte(0x28, &dataRead);
  MT6616_WriteByte(0x28, dataRead&0xFDFF);
  
  // Disable ADPLL
  MT6616_ADPLL_PowerDown();
  
  //Set FMCR_DCO_CK_SEL = ? (default = 0, 15.36)
  MT6616_ReadByte(0x1d, &dataRead);
  if(isADPLL_16M)
  {		
  	MT6616_WriteByte(0x1d, (dataRead&0xFDFF)|0x0200);
  }
  else
  {
  	MT6616_WriteByte(0x1d, dataRead&0xFDFF);
  }
  // Ensable ADPLL
  MT6616_ADPLL_PowerUp();
  Delayms(500);
  //Set rgfrf_enable_top_ck ="1"
  MT6616_ReadByte(0x28, &dataRead);
  MT6616_WriteByte(0x28, (dataRead&0xFDFF)|0x0200);
  if(isADPLL_16M)
  {		
  	//Set rgf_f16mode_en = X	
  	MT6616_WriteByte(0x31, 3);
  	//Set rgf_cnt_resync_b = 0    
 	MT6616_WriteByte(0x31, 1);      
        //Set rgf_cnt_resync_b = 1    
 	MT6616_WriteByte(0x31, 3);
  }
  else
  {
  	//Set rgf_f16mode_en = X  		
  	MT6616_WriteByte(0x31, 2);
  //Set rgf_cnt_resync_b = 0
 	MT6616_WriteByte(0x31, 0);          
  //Set rgf_cnt_resync_b = 1
  	MT6616_WriteByte(0x31, 2);
  } 
 
  // Power up FM modem clk
  MT6616_WriteByte(0x30, 0x0006);        
  //Set rgf_auto_mclk_sel_en = 1 (only if muclk desense option is enabled)
  /*MT6616_WriteByte(0x2F, 1);
  MT6616_ReadByte(0x4A, &dataRead);
  MT6616_WriteByte(0x4A, dataRead|0x0800);
  MT6616_WriteByte(0x2F, 0);*/
}

/***********************************************************************
*  RAMP off (internal)
*         
***********************************************************************/
void MT6616_RampDown()
{
#if defined(FM_INTERFACE_HCI)
	kal_uint16 dataRead;
       kal_bool status;
       kal_uint8 buffer[2];

	MT6616_HCI_Send_Cmd(FM_RAMPDOWN_OPCODE, &buffer[0]);
	//Delayms(100);
#else
	kal_uint16 dataRead;	
	kal_uint32 i=0;
	FMR_TRACE0(FM_API_ENTRANCE,"ENTRANCE:%d\n",34);
	//Enable mute
    	MT6616_ReadByte(FM_DAC_CON1, &dataRead);
  	MT6616_WriteByte(FM_DAC_CON1, (dataRead|0x0003));
  	//Set softmute to fast mode
  	MT6616_WriteByte(0x2F, 0x0000);
  	MT6616_WriteByte(0xE9, 0x0101);
  	MT6616_WriteByte(0xBD, 0x0562);
  	MT6616_WriteByte(0x2F, 0x0001);
  	MT6616_WriteByte(0xD8, 0x0000);
  	MT6616_WriteByte(0x2F, 0x0000);
	Delayms(125);
    	MT6616_ReadByte(FM_MAIN_CTRL, &dataRead);		
  	MT6616_WriteByte(FM_MAIN_CTRL, (dataRead&0xFFF0)); //clear rgf_tune/seek/scan/rxcal
  	
	/*MT6616_ReadByte(FM_MAIN_CHANDETSTAT, &dataRead);
  	while( (dataRead & MASK_STC) == 1)
  	{
	MT6616_ReadByte(FM_MAIN_CHANDETSTAT, &dataRead);		
  	}  		*/
	MT6616_WriteByte(0x2F, 0x0001);
	MT6616_ReadByte(0x4E, &dataRead);
	FMR_TRACE0(FM_API_ENTRANCE,"ENTRANCE:%d\n",340);
	FM_Data_debug = KAL_FALSE;
  	while(dataRead&0xFF00)
  	{
		if(i++>1000)
		{
			i=0;
			FMR_TRACE0(FM_ON_POLLING_TIMES,"power on polling 1000 times--%d",4);
		}
		MT6616_ReadByte(0x4E, &dataRead);
  	}  	
	FM_Data_debug = KAL_TRUE;
	FMR_TRACE0(FM_API_ENTRANCE,"EXIT:%d\n",340);
  	MT6616_WriteByte(0x2F, 0x0000);
#endif
	FMR_TRACE0(FM_API_EXIT,"EXIT:%x",4);
}

/***********************************************************************
*  Set radio frequency (internal)
*
*  parameter-->CurFreq:set frequency
*         
***********************************************************************/
static kal_bool MT6616_SetFreq(kal_int32 CurFreq)
{
#if defined(FM_INTERFACE_HCI)
	kal_uint16 dataRead;
	kal_bool status;
	kal_uint8 buffer[2];
	dataRead = CurFreq*10;//CurFreq*10;
	buffer[0] = dataRead&0xFF;
	buffer[1] = dataRead>>8;
	MT6616_HCI_Send_Cmd(FM_TUNE_OPCODE, &buffer[0]);
	_current_frequency = CurFreq;
	Delayms(125);
	return KAL_TRUE;
#else
	kal_uint32 CHAN = 0x0000;
	kal_uint16 dataRead, cnt=0;
	//uint8 regvalue=0x34;
	//uint16 value=0xAAAA;

#ifdef MT6616_DEBUG_DUMP_LOG
   kal_uint32 start_t, duration_t;
   kal_sprintf((void*)_dbg_str, "\nMT6616_SetFreq(%d);\n\0", CurFreq);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
   start_t = video_get_current_time();
#endif   
   	_current_frequency = CurFreq;
	CHAN = (CurFreq - 640)<<1;
	MT6616_ReadByte(12, &dataRead);
	MT6616_WriteByte(12, (dataRead&0xFC00)|CHAN);
	Rampdown_again:/*SW work around:sometimes chip state machine is abnormal and tune need ramp down again*/
	MT6616_RampDown();
       MT6616_TUNE_ON();	
   	//MT6616_WriteByte(FM_MAIN_CTRL, (dataRead&0xFFFE)|0x0001);//set tune on
	
	FM_Data_debug = KAL_FALSE;
	do {
         	MT6616_ReadByte(FM_MAIN_INTR, &dataRead);
		if((dataRead & MASK_STC) == 0)
			kal_sleep_task(3);
		if(cnt++ > 20)
		{
			//kal_prompt_trace(MOD_FMR, "Set Freq fail:Cnt= %X", cnt);
			FMR_TRACE(FM_INFO_TuneTimes, "setfreq: poll many times!\n");
			cnt = 0;
			FM_Data_debug = KAL_TRUE;
			goto Rampdown_again;
		}
    } while ((dataRead & MASK_STC)==0);
	FM_Data_debug = KAL_TRUE;
   	MT6616_WriteByte(FM_MAIN_INTR, (dataRead&~MASK_STC)|MASK_STC);//clear status flag
	//Disable mute
    	MT6616_ReadByte(FM_DAC_CON1, &dataRead);
  	MT6616_WriteByte(FM_DAC_CON1, (dataRead&0xFFFC));
   	Delayms(125);
  	//Set softmute to normal mode
  	MT6616_WriteByte(0x2F, 0x0000);
  	MT6616_WriteByte(0xE9, 0x0232);
  	MT6616_WriteByte(0xBD, 0x4562);
  	MT6616_WriteByte(0x2F, 0x0001);
  	MT6616_WriteByte(0xD8, 0x008B);
  	MT6616_WriteByte(0x2F, 0x0000);
   return KAL_TRUE;
#endif
}//MT6616_SetFreq

#if defined (__WMT_SUPPORT__)
/***********************************************************************
*  RAMP off (internal)
*
***********************************************************************/
void MT6616_FSPI_Enable(kal_uint8 OnOff)
{
	MT6616_HCI_Send_Cmd(FSPI_ENABLE_OPCODE, &OnOff);
}

/***********************************************************************
*  RAMP off (internal)
*
***********************************************************************/
void MT6616_FSPI_MuxSelect(kal_uint8 type)
{
	MT6616_HCI_Send_Cmd(FSPI_MUX_SEL_OPCODE, &type);
}
#endif

/***********************************************************************
*  HiLo side Tune (internal)
*
*  parameter-->Freq: curf:875~1080
*							 band:range87.5~108.0
*         		 space:1:100k, 0:200k
***********************************************************************/
void MT6616_TUNE_HiLo(kal_int32 Freq, kal_int16 band, kal_int8 space)
{
	kal_int8 rssi;
	kal_uint16 dataRead;
	
	FMDrv_Mute(1);
      
    	MT6616_RampDown();		
      	
      	MT6616_ReadByte(3, &dataRead);
      	MT6616_WriteByte(3, ((dataRead&0xC7FF)|(space<<13))|band);//set space(100k/200k)and band(875~1080)
        
        //Read Low-Side LO Injection
  	//R11 --> clear  D15,  clear D0/D2,  D3 is the same as default
  	MT6616_ReadByte(11, &dataRead);
  	MT6616_WriteByte(11, (dataRead&0x7FFA));
  	if (MT6616_SetFreq(Freq) == 0) 
      	{
         	ASSERT(0);
      	}    
      
       	MT6616_ReadByte(ADDR_PAMD, &dataRead);
  	rssi = (dataRead & MASK_RSSI);
  	
  	//Read Hi-Side LO Injection
  	// R11-->set D15, set D0/D2,  D3 is the same as default
  	MT6616_ReadByte(11, &dataRead);
  	MT6616_WriteByte(11, (dataRead&0x8005));
  	if (MT6616_SetFreq(Freq) == 0) 
      	{
         	ASSERT(0);
      	}  
      	
      	MT6616_ReadByte(ADDR_PAMD, &dataRead);
      	rssi = rssi- (dataRead & MASK_RSSI);  
      	
      	if (rssi < 0) //errata in 0.82
  	{ 	
		// LO
		// R11--> clear D15, set D0/D2, D3 is the same as default
		MT6616_ReadByte(11, &dataRead);
  		MT6616_WriteByte(11, (dataRead&0x7FFF)|0x0005);
  	}else{ 
		//HI
		//R11-->  set D15, clear D0/D2, D3 is the same as default
		MT6616_ReadByte(11, &dataRead);
  		MT6616_WriteByte(11, (dataRead|0x8000)&0xFFFA);
  	}
  	
  	//fine-tune !!
  	//TUNE to FreqKHz with current setting
  	if (MT6616_SetFreq(Freq) == 0) 
      	{
         	ASSERT(0);
      	}  
	
}
/***********************************************************************
*  Get RSSI Value (internal)
*
*  parameter-->
** retrun dBuVemf,
**********************************************************************/
kal_int16 MT6616_GetCurRSSI(void)
{
    kal_uint16 TmpReg;
    kal_int16 RSSI, dBValue;
   MT6616_ReadByte(ADDR_RSSI, &TmpReg);
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
  //return ((TmpReg & MASK_RSSI)>>9);
}

/***********************************************************************
*  Get PAMD Value (internal)
*
*  parameter-->
***********************************************************************/
kal_uint16 MT6616_GetCurPamd(void)
{
   kal_uint16 TmpReg, PAMD, dBValue;
   MT6616_ReadByte(ADDR_PAMD, &TmpReg);
   /*PA=PAMD
    *If PA>511 then PAMD(dB)=  (PA-1024)/16*6,
    *               else PAMD(dB)=PA/16*6                 */
   PAMD = TmpReg&0x3FF;
   dBValue = (PAMD>511) ? ((1024-PAMD)*6/16):0;

   //pamd = 0x3FFF-TmpReg;
   return dBValue;
  //return ((TmpReg & MASK_RSSI)>>9);
}

/***********************************************************************
*  Set Seek RSSI threshold (internal)
*
*  parameter--> bStep
***********************************************************************/
void MT6616_SeekThreshold(kal_uint8 bStep)
{
   	kal_uint16 RSSIValue, TmpReg;

	/*	RSSI_TH = ? dBm                                  *
 	*	if(RSSI_TH >0 )                                  *
  	*        RSSI_HWTH =  RSSI_TH*8/3                    *
	*      else                                          *
	*        RSSI_HWTH =  (RSSI_TH*8/3) + 1024           */

	kal_uint16 RSSI_TBL[10] =
	{
	// -91dBm, -92dBm, -93dBm, -94dBm, -95dBm
 		0x30D, 0x30A, 0x308, 0x305, 0x302,
 	// -96dBm, -97dBm, -98dBm, -99dBm, -100dBm
 	       0x301, 0x2FD, 0x2FA, 0x2F8, 0x2F5
	};

   RSSIValue = RSSI_TBL[bStep];
   MT6616_ReadByte(0x60, &TmpReg);   
   MT6616_WriteByte(0x60, (TmpReg&0xFC00)|RSSIValue);
}

/***********************************************************************
*  Get Search freq (internal)
*
*  parameter-->
***********************************************************************/
void MT6616_GetSearchFreq(kal_uint16 *pfreq)
{
	*pfreq = (kal_uint16)FreqKHz;
}

/*********************************************************************
*  I2S On/Off
*  parameter-->OnOff: 1:On, 0:Off
*
*********************************************************************/
void MT6616_I2S_OnOff( kal_bool OnOff)
{
	kal_uint16 dataRead;
	if(OnOff)
	{
		MT6616_WriteByte(FM_FT_CON9, 0x01DA);//32K
		//MT6616_WriteByte(FM_DAC_CON2, 0x2702);	//Enable Test Sin Wave
		MT6616_WriteByte(FM_DAC_CON1, 0xd900);
		MT6616_WriteByte(FM_I2S_CON0, I2S_SRC|FORMAT|I2S_EN);
		MT6616_WriteByte(FM_FT_CON0, FT_EN);
		MT6616_ReadByte(0x85, &dataRead);
		MT6616_WriteByte(0x85, dataRead&0xFFFB);
		MT6616_ReadByte(0, &dataRead);
		MT6616_WriteByte(0, dataRead&0xFEFF);
	}
	else
	{
		MT6616_WriteByte(FM_FT_CON0, 0);
		MT6616_WriteByte(FM_I2S_CON0, I2S_SRC);
		MT6616_WriteByte(FM_DAC_CON1, 0x5900);
	}
}

/***********************************************************************
*  FM Chip initial
*
*  parameter-->
***********************************************************************/
void FMDrv_ChipInit(void)
{
   //uint16 dataRead;

 // Init Reset/Power Pin to FM
 #ifdef USE_I2C
   SerialCommInit();
   //SerialCommCryClkOn();
#endif
}

#if !defined(FM_INTERFACE_HCI)
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
#if !defined(FM_INTERFACE_HCI)
   EINT_Registration(FM_EINT_NO,KAL_FALSE,fm_state,FMDrv_EINT_HISR, KAL_FALSE);
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
   MT6616_WriteByte(0x2F, 1);
   MT6616_ReadByte(0xF8, &TmpReg);
   MT6616_WriteByte(0x2F, 0);
   value = (TmpReg&0x400)>>10;
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
	
	switch (group_idx)
	{
		case mono:
			MT6616_ReadByte(0xd7, &dataRead); 
			if(item_value == 1)
				MT6616_WriteByte(0xd7, (dataRead&0xFFFD)|0x02);
			else
				MT6616_WriteByte(0xd7, (dataRead&0xFFFD));
			break;
		case stereo:
			if(item_value == 0)
			{
				MT6616_ReadByte(0xd7, &dataRead); 
				MT6616_WriteByte(0xd7, dataRead&0xFFFD);
			}
			else
			{
				switch (item_idx)
				{
					case Sblend_ON:
						MT6616_ReadByte(0xd8, &dataRead); 
						MT6616_WriteByte(0xd8, (dataRead&0x7FFF) |(item_idx<<15));
					break;
					case Sblend_OFF:
						MT6616_ReadByte(0xd8, &dataRead); 
						MT6616_WriteByte(0xd8, (dataRead&0x7FFF));
					break;
				}
			}
			break;
		case RSSI_threshold:
			MT6616_ReadByte(0x60, &dataRead); 
			MT6616_WriteByte(0x60, (dataRead&0xFC00) |item_value);
		break;
		case HCC_Enable:
				MT6616_ReadByte(0xef, &dataRead); 
			if(item_idx)
				MT6616_WriteByte(0xef, dataRead |0x10);
			else
				MT6616_WriteByte(0xef, dataRead&(~0x10));		
		break;
		case PAMD_threshold:
				MT6616_ReadByte(0x61, &dataRead); 
				MT6616_WriteByte(0x61, (dataRead&0xFC00) |item_value);
				MT6616_WriteByte(0x2F, 1);
				MT6616_ReadByte(0x7f, &dataRead); 
				MT6616_WriteByte(0x7f, (dataRead&0xFC00) |item_value);
				MT6616_WriteByte(0x2F, 0);
		break;
		case Softmute_Enable:
			if(item_idx)
			{
				MT6616_ReadByte(0xef, &dataRead); 
				MT6616_WriteByte(0xef, dataRead |0x20);
			}
			else
			{
				MT6616_ReadByte(0xef, &dataRead); 
				MT6616_WriteByte(0xef, dataRead&(~0x20));		
			}
		break;
		case De_emphasis:
			if(item_idx == 2) //75us
			{
				MT6616_ReadByte(0xf0, &dataRead); 
				MT6616_WriteByte(0xf0, (dataRead&0xFFFC) |0x02);
			}
			else if(item_idx == 1) //50us
			{
				MT6616_ReadByte(0xf0, &dataRead); 
				MT6616_WriteByte(0xf0, (dataRead&0xFFFC) |0x01);		
			}
			else if(item_idx == 0) //0us
			{
				MT6616_ReadByte(0xf0, &dataRead); 
				MT6616_WriteByte(0xf0, (dataRead&0xFFFC) |0x00);		
			}
		break;
		case HL_Side:
			if(item_idx == 2) //H-Side
			{
				MT6616_ReadByte(0x4f, &dataRead); 
				MT6616_WriteByte(0x4f, (dataRead&0xFFFE) |0x11);
				MT6616_ReadByte(0x0C, &dataRead); 
				MT6616_WriteByte(0x0C, (dataRead&0xFBFF) |0x0400);
			}
			else if(item_idx == 1) //L-Side
			{
				MT6616_ReadByte(0x4f, &dataRead); 
				MT6616_WriteByte(0x4f, (dataRead&0xFFFE) |0x10);		
				MT6616_ReadByte(0x0C, &dataRead); 
				MT6616_WriteByte(0x0C, dataRead&0xFBFF);
			}
			else if(item_idx == 0) //Auto
			{
				MT6616_ReadByte(0x4f, &dataRead); 
				MT6616_WriteByte(0x4f, dataRead&(~0x11));		
			}
		break;

		case Demod_BW:
				MT6616_ReadByte(0x73, &dataRead); 
			if(item_idx == 2) //force wide
				MT6616_WriteByte(0x73, (dataRead&0xFFFC) |0x03);
			else if(item_idx == 1) //force narrow
				MT6616_WriteByte(0x73, (dataRead&0xFFFC) |0x01);		
			else if(item_idx == 0) //auto
				MT6616_WriteByte(0x73, (dataRead&0xFFFC) |0x00);		
		break;
		case Dynamic_Limiter:
			MT6616_WriteByte(0x2F, 1);
				MT6616_ReadByte(0xfa, &dataRead); 
			if(item_idx)
				MT6616_WriteByte(0xfa, (dataRead&0xFFF7) |0x00);
			else
				MT6616_WriteByte(0xfa, (dataRead&0xFFF7) |0x08);		
			MT6616_WriteByte(0x2F, 0);		
		break;
		case Softmute_Rate:
			MT6616_ReadByte(0xe9, &dataRead); 
			MT6616_WriteByte(0xe9, (dataRead&0x80FF) |(item_value<<8));
		break;
		case AFC_Enable:
			MT6616_ReadByte(0x33, &dataRead);
			if(item_idx)
				MT6616_WriteByte(0x33, dataRead|0x0400);
			else
				MT6616_WriteByte(0x33, dataRead&0xFBFF);
		break;
		case Softmute_Level:
			MT6616_WriteByte(0x2F, 1);
			MT6616_ReadByte(0xd1, &dataRead);
			if(item_value > 0x24)
				item_value = 0x24;
			MT6616_WriteByte(0xd1, (dataRead&0xFFC0) |item_value);
			MT6616_WriteByte(0x2F, 0);
		break;
		case Analog_Volume:
			MT6616_ReadByte(0xb0, &dataRead);
			MT6616_WriteByte(0xb0, (dataRead&0xF03F)|(item_value<<6));//[11:6]
		break;
		default:
		break;
	}
}



kal_bool FMDrv_IsChipValid( void )
{
	/// anything to do?
	return true;
}

kal_uint16 FMDrv_ReadByte(kal_uint8 addr)
{
	kal_uint16 Data;
	MT6616_ReadByte(addr, &Data);
	return Data;
}

kal_bool FMDrv_WriteByte(kal_uint8 addr, kal_uint16 data)
{
	MT6616_WriteByte(addr, data);
	return true;
}

/// level ranges from 0 to 12
void FMDrv_SetVolumeLevel(kal_uint8 level)
{
//   MT6616_SetVolumeLevel(level);
}

void FMDrv_Mute(kal_uint8 mute)
{
	kal_uint16 dataRead;

	MT6616_ReadByte(0x83,&dataRead);                           
	if (mute == 1)
		MT6616_WriteByte(0x83, (dataRead&0xFFFC)|0x0003);  
	else
		MT6616_WriteByte(0x83, (dataRead&0xFFFC)); 
}

/// Get interrupt status
void FMDrv_GetIntr(kal_uint16 *dataRead)
{
   MT6616_ReadByte(FM_MAIN_INTR, dataRead);
}

void FMDrv_ClrIntr(void)
{
   kal_uint16 dataRead;
   
   MT6616_ReadByte(FM_MAIN_INTR, &dataRead);
   MT6616_WriteByte(FM_MAIN_INTR, dataRead);//clear status flag
	EINT_UnMask(FM_EINT_NO);
}


/*************************************************************
*  Radio power on Reset
*
*************************************************************/
void FMDrv_PowerOnReset(void)
{
#ifdef USE_I2C
  #if defined(__MT6616_NO_STP__)
   ilm_struct *fmr_ilm;
  #endif
   kal_int32 i,j=0;
   kal_uint16 tmp_reg, tmp_reg1;
#else
   kal_uint8 tmp1;
#endif   
   //uint8 regvalue=0x21;
   //uint16 value=0xAAAA, dataRead;
	//MT6616_WriteByte(regvalue, value);	
	//MT6616_ReadByte(regvalue, &dataRead);
       //MT6616_ReadByte(0x32, &tmp_reg);  

   FMR_TRACE0(FM_API_ENTRANCE,"ENTRANCE:%d\n",11);
   /// Power On
   kal_trace(TRACE_INFO, FM_INFO_FM_COMMON_POWER_ON);
#if defined (__WMT_SUPPORT__)
   #if defined(FM_INTERFACE_I2C) && !defined(__MT6616_NO_STP__)
     wmt_set_fm_power_status(0);
   #endif
   wmt_ext_power_on_hdlr(FM_TASK_INDX);
   #if defined (FM_INTERFACE_HCI)
   MT6616_FSPI_Enable(1);
   MT6616_FSPI_MuxSelect(0);
   #endif
#endif

   kal_trace(TRACE_INFO, FM_INFO_FM_POWER_ON_RST);
   #ifdef USE_I2C
   SerialCommInit();
   for (i=0; i<POWER_ON_COMMAND_COUNT; i++) 
   {
		FMR_TRACE0(FM_ON_SEQUENCE_CMD,"power on cmd:%d",i);
      if (PowerOnSetting[i].addr==0xFFFF)
	  {  //polling status=1
      	j=0;
		FM_Data_debug = KAL_FALSE;
        while(1)
		{		
          	MT6616_ReadByte(PowerOnSetting[i].and, &tmp_reg);
			if(j++ >1000)
			{
				FMR_TRACE0(FM_ON_POLLING_TIMES,"power on polling 1000 times==%d\n",110);
				FMR_TRACE0(FM_ON_POLLING_TIMES,"power on polling 1000 times==%d\n",tmp_reg);
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
			MT6616_ReadByte(PowerOnSetting[i].and, &tmp_reg);
			if(j++ >1000)
			{
				FMR_TRACE0(FM_ON_POLLING_TIMES,"power on polling 1000 times==%d\n",111);
				FMR_TRACE0(FM_ON_POLLING_TIMES,"power on polling 1000 times==%d\n",tmp_reg);
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
        MT6616_ReadByte(PowerOnSetting[i].and, &tmp_reg);
	 	switch(PowerOnSetting[i].and)
		{
	   		case  0x32:
	     	Chip_ID = tmp_reg;    
            kal_trace(TRACE_INFO, FM_INFO_FM_CHIP_ID, Chip_ID);
	     	break;
          	case 0x48:
            MT6616_ReadByte(PowerOnSetting[i].and, &tmp_reg); //0x48
            MT6616_ReadByte(PowerOnSetting[i].or, &tmp_reg1); //0x42
            MT6616_WriteByte(PowerOnSetting[i].or, ((tmp_reg1&0xC0C0)|(tmp_reg&0x3F3F)));
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
      else
	  {
        if(PowerOnSetting[i].and != 0)
        {
	        MT6616_ReadByte(PowerOnSetting[i].addr, &tmp_reg);
	        tmp_reg &= PowerOnSetting[i].and;
	        tmp_reg |= PowerOnSetting[i].or;	  	
		}
		else
			tmp_reg = PowerOnSetting[i].or;
        MT6616_WriteByte(PowerOnSetting[i].addr, tmp_reg);
		MT6616_ReadByte(PowerOnSetting[i].addr, &tmp_reg);/*for debug*/
      }
   }
   #if defined(__MT6616_NO_STP__)
   if (wmt_query_bt_power_status())
   {
       DRV_SendPrimitive(fmr_ilm,
                     MOD_FMR,
                     MOD_BT,
                     MSG_ID_BT_WAKEUP_BT_CONTROLLER,
                     NULL,
                     FMR_SAP);
       msg_send_ext_queue(fmr_ilm);                  
   }                
   #else
   wmt_set_fm_power_status(1);
   wmt_ext_power_on_hdlr(FM_TASK_INDX);
   #endif
   FMDrv_IntrInit();
 #else
   tmp1 = 1;
   MT6616_HCI_Send_Cmd(FM_ENABLE_OPCODE, &tmp1);
 #endif
   
 #ifdef __FMRADIO_I2S_SUPPORT__
   MT6616_I2S_OnOff(1);
 #endif
 
   _is_fm_on = true;
   _current_frequency = -1;
   FMR_TRACE0(FM_API_EXIT,"EXIT:%d\n",11);
}


/*****************************************************************
*  Radio power off
*
*****************************************************************/
void FMDrv_PowerOffProc(void)
{
   kal_int16 i;
   kal_uint16 tmp_reg;
#if defined(FM_INTERFACE_HCI)   
   kal_uint8 tmp1;
#endif

   MT6616_RampDown();
   #ifdef USE_I2C
#if !defined(__MT6616_NO_STP__)
   wmt_set_fm_power_status(0);
   wmt_ext_power_off_hdlr(FM_TASK_INDX);
#endif
   for (i=0; i<POWER_OFF_COMMAND_COUNT; i++)
   {
        if(PowerOffProc[i].addr==0xFFFB)
	{ //delay ms
       	Delayms(PowerOffProc[i].or);
       }
   	else if(PowerOffProc[i].addr==0xFFFA)
	{ //delay us
       	Delayus(PowerOffProc[i].or);
   	}
	else
	{
   	    if(PowerOffProc[i].and != 0)
   	    {
   	        MT6616_ReadByte(PowerOffProc[i].addr, &tmp_reg);
   	        tmp_reg &= PowerOffProc[i].and;
       	    tmp_reg |= PowerOffProc[i].or;	  	
	    }
	    else
		    tmp_reg = PowerOffProc[i].or;
   	    MT6616_WriteByte(PowerOffProc[i].addr, tmp_reg);
	}
   }
     #if !defined(__MT6616_NO_STP__)
     wmt_set_fm_power_status(1);
     wmt_ext_power_off_hdlr(FM_TASK_INDX);
     #endif
     #if !defined(FM_INTERFACE_HCI)
	EINT_Mask(FM_EINT_NO);
     #endif
   #else
       tmp1 = 0;       
       MT6616_HCI_Send_Cmd(FM_ENABLE_OPCODE, &tmp1);
       wmt_ext_power_off_hdlr(FM_TASK_INDX);
   #endif
   _is_fm_on = false;
   _current_frequency = -1;
}


/*********************************************************************
*  Radio set frquency
*
*  parameter-->curf:setting frequency value
                    input value: 875 - 1080 ( 87.5 MHz - 108.0 MHz)
*********************************************************************/
void FMDrv_SetFreq( kal_int16 curf )  /* input value: 875 - 1080 ( 87.5 MHz - 108.0 MHz)*/
{
	FMR_TRACE0(FM_API_ENTRANCE,"entrace=%x",0x31);
   pstFMR_data->is_searching = false;
   if (_is_fm_on != true)
       FMDrv_PowerOnReset();
      FMDrv_Mute(1);
      MT6616_RampDown();
      MT6616_HL_Side_Adj(curf);
      MT6616_Freq_Avoid(curf);
      if (MT6616_SetFreq(curf) == 0) 
      {
         ASSERT(0);
      }     
      FreqKHz = curf;
      FMDrv_Mute(0);
	  FMR_TRACE0(FM_API_EXIT,"exit=%x",0x31);
}

/**********************************************************************
*  Get really signal level in current frequency
*
*  parameter-->curf:frequency value of radio now
**********************************************************************/
kal_uint16 FMDrv_GetSigLvl( kal_int16 curf )
{
   kal_uint16 rssi;

   rssi = MT6616_GetCurRSSI();
   return rssi;
}

/**********************************************************************
*  Get really signal level in current frequency
*
*  parameter-->curf:frequency value of radio now
**********************************************************************/
kal_uint16 FMDrv_GetPamdLvl( kal_int16 curf )
{
   kal_uint16 pamd,pamd1,pamd_diff;
      
   if (curf != _current_frequency)
   {
   	FMDrv_SetFreq( curf );
   	do{
   	pamd = MT6616_GetCurPamd();
      	kal_sleep_task(100);
      	pamd1 = MT6616_GetCurPamd();
      	pamd_diff = (pamd1 > pamd)?(pamd1-pamd):(pamd-pamd1);
	}while(pamd_diff >= 2);
   }
   pamd = MT6616_GetCurPamd();
   return pamd;
}
/*
range:20~50dB
return dB
*/
kal_int16 FMDrv_GetMR(void)
{
	kal_uint16 RegTemp;
	kal_int16 MR;
	MT6616_ReadByte(0x80, &RegTemp);
	RegTemp=(RegTemp&0x3FF);
	
	if(RegTemp > 511)
	{
		MR=(kal_int16)(RegTemp-1024)*6/16;
	}
	else
	{
		MR=(kal_int16)RegTemp*6/16;
	}
	return MR;
}

void FMGetScanTbl(kal_uint16 *CH_TBL)
{
   kal_uint16 dataRead,MASK_CH;
   kal_uint8 _step;
   kal_uint8 ch_cnt, ch_step;

		MT6616_WriteByte(0x2F, 0x01);
		ch_cnt=0;
		for(_step=0; _step<200; _step++)
		{
			*(CH_TBL+_step)=0;
		}

		for(ch_step=0; ch_step<16; ch_step++)
		{
		       MASK_CH=0x0001;
       		MT6616_ReadByte(0x50+ch_step, &dataRead);
			for(_step=0; _step<16; _step++)
			{
				MASK_CH=1<<_step;
				if((MASK_CH&dataRead)!=0)
				{
			  		*(CH_TBL+ch_cnt)=880+ch_step*16+_step;
			  		ch_cnt++;
				}
			}
		}

       	MT6616_WriteByte(0x2F, 0x00);   
}
#if defined(FM_INTERFACE_HCI)
#define UPPER_BOUND 10800 //108MHz
#define DOWN_BOUND 8750 //87.5MHz
#else
#define BAND_UP 1080 //108MHz
#define BAND_DN 875 //87.5MHz
#endif
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
#if defined(FM_INTERFACE_HCI)
    kal_uint16 dataRead, RegValue;
    kal_uint8 buffer[7];//, cw1=0x33, cw2=0x34;
    kal_bool status;
    buffer[0] = DOWN_BOUND&0xFF;
    buffer[1] = DOWN_BOUND>>8;
    buffer[2] = UPPER_BOUND&0xFF;
    buffer[3] = UPPER_BOUND>>8;
    buffer[4] = is_step_up?0:1;
    buffer[5] = 1;	//wrap enable
    buffer[6] = 2;	//step size = 100KHz

    HWSearch_flag = 0;
    Valid_flag = 0;
    FreqSt = FreqKHz;			
    //MT6616_RampDown();
    MT6616_SetFreq(freq);
    MT6616_RampDown();
    if(is_preset)
    {
   	MT6616_HCI_Send_Cmd(FM_SCAN_OPCODE, &buffer[0]);
	//MT6616_Wait_UART_Init(FM_SCAN_OPCODE);
    }
    else
    {
   	MT6616_HCI_Send_Cmd(FM_SEEK_OPCODE, &buffer[0]);
	//MT6616_Wait_UART_Init(FM_SEEK_OPCODE);
    }
#else
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
    	MT6616_RampDown();		
	//- Modified code start  
      	if (MT6616_SetFreq(targetFreq) == 0) 
      	{
      	   ASSERT(0);
      	}
    	//MT6616_ReadByte(FM_MAIN_CTRL, &dataRead);		
  	//MT6616_WriteByte(FM_MAIN_CTRL, (dataRead&0xFFF0));
    	MT6616_RampDown();		
       MT6616_SeekThreshold(FM_SEEK_RSSI_THRESHOLD);	
	Delayms(50);
       // Setting before seek
    	MT6616_ReadByte(FM_MAIN_CFG2, &dataRead);  
      	MT6616_WriteByte(FM_MAIN_CFG2, (dataRead&0xFC00)|((BAND_DN-640)<<1));//set space(100k/200k)and band(875~1080)and up/down
    	MT6616_ReadByte(FM_MAIN_CFG1, &dataRead);  
      	MT6616_WriteByte(FM_MAIN_CFG1, (dataRead&0x8800)|(UpDown_flag<<10)|(1<<(12+_step))|((BAND_UP-640)<<1));//set space(100k/200k)and band(875~1080)and up/down
    	MT6616_ReadByte(FM_MAIN_CFG1, &dataRead);

	if (!is_preset)
  	{	// this is not a auto_scan function !
		MT6616_WriteByte(FM_MAIN_CFG1, dataRead&0xF7FF|0x0800); //enable wrap , if it is not auto scan function
    }else{
		MT6616_WriteByte(FM_MAIN_CFG1, dataRead&0xF7FF); //disable wrap , if it is auto scan function
	}
	if (!is_preset)
  	{	// this is not a auto_scan function !
    		MT6616_SEEK_ON();
        }else{
     		MT6616_SCAN_ON();   
        }

#endif
}

kal_uint8 FMDrv_HWSpolling(kal_uint16 *curf, kal_uint8 *is_valid)
{
      #if !defined(FM_INTERFACE_HCI)
	kal_uint16 dataRead;
   	//- Modified code end
   	MT6616_ReadByte(FM_MAIN_INTR, &dataRead);
   	HWSearch_flag = dataRead & MASK_STC; // check STC flag 
	FM_Data_debug = KAL_FALSE;
  	while( HWSearch_flag == 0)
  	{
  		if(pstFMR_data->bHWsearchStop == 1)
  		{
  			*curf = FreqSt;
  			*is_valid = 0;
			FMDrv_ClrIntr();
			FM_Data_debug = KAL_TRUE;
  			return 0;
  		}
		MT6616_ReadByte(FM_MAIN_INTR, &dataRead);
		HWSearch_flag = dataRead & MASK_STC; // check STC flag 
		Valid_flag = 1;
	   	MT6616_ReadByte(FM_MAIN_CHANDETSTAT, &dataRead);   	
		kal_sleep_task(5);
  	}
	FM_Data_debug = KAL_TRUE;
	MT6616_ReadByte(FM_MAIN_INTR, &dataRead);	
	MT6616_WriteByte(FM_MAIN_INTR, (dataRead&0xFFFE)|0x0001);//clear status flag	
   	MT6616_ReadByte(FM_MAIN_CHANDETSTAT, &dataRead);   	
 	FreqKHz = 640 + ((dataRead & MASK_READCHAN )>> (SHIFT_READCHAN+1) );			
	if(FreqKHz > 1080)
		FreqKHz = 1080;
	else if(FreqKHz < 875)
		FreqKHz = 875;
#endif
  	
	if (HWSearch_flag != 0)
	{
		MT6616_GetSearchFreq(curf); 
		if (Valid_flag == 1)
			*is_valid = 1;
		else
			*is_valid = 0;
		return 1;
	}
	else
		return 0;
}

/**********************************************************************
*  Radio valid station,used in auto search frequency to verify 
*  valid positon
*
*  parameter-->freq: frequency
               signalv1:signal level range is 0 ~ 15 
               is_step_up:return value(Reserved)
**********************************************************************/
kal_uint8 FMDrv_ValidStop(kal_int16 freq, kal_int8 signalvl, kal_bool is_step_up)
{
   kal_int32 targetFreq;
   kal_uint16 dataRead;
   kal_uint8 UpDown_flag=1; 

	if (is_step_up)
		UpDown_flag = 0;
	targetFreq = (kal_int32)freq;
	
    	FMDrv_Mute(1);
    	MT6616_RampDown();		
      	if (MT6616_SetFreq(targetFreq) == 0) 
      	{
      	   ASSERT(0);
      	}     
   MT6616_RampDown();	
		
       // Setting before seek
   MT6616_ReadByte(FM_MAIN_CFG2, &dataRead);  
   MT6616_WriteByte(FM_MAIN_CFG2, (dataRead&0xFC00)|0x1E0);//set space(100k/200k)and band(875~1080)and up/down
   MT6616_ReadByte(FM_MAIN_CFG1, &dataRead);  
   MT6616_WriteByte(FM_MAIN_CFG1, (dataRead&0x8800)|(UpDown_flag<<10)|(1<<13)|0x370);//set space(100k/200k)and band(875~1080)and up/down
   MT6616_ReadByte(FM_MAIN_CFG1, &dataRead);   	
      
    	MT6616_SEEK_ON();
   
   do
   {
         	MT6616_ReadByte(FM_MAIN_INTR, &dataRead);
      	   } while ((dataRead & MASK_STC)==0);
      	   
   MT6616_WriteByte(FM_MAIN_INTR, (dataRead&0xFFFE)|0x0001);//clear status flag
   MT6616_RampDown();      	 
  	FMDrv_Mute(0);

   return 1;
}

void FMDrv_GetScanTbl(kal_uint16 *BitMapData, kal_uint8 offset)
{
	kal_uint16 dataRead;
	
	MT6616_WriteByte(0x2F, 0x01);
	MT6616_ReadByte(0x50+offset, &dataRead);	
	*(BitMapData+offset) = dataRead;
       MT6616_WriteByte(0x2F, 0x00);
}

void FMDrv_HCI_Event_Hdlr(kal_bool isReadyRead)
{
#if defined (__WMT_SUPPORT__)
if(isReadyRead)
{
    MT6616_HCI_Event_Hdlr();
#if (defined(__FM_RADIO_RDS_SUPPORT__))
    if((pstFMR_data->FM_HCI_data.buffer[4]) == RDS_DATA_OPCODE)
    {
	RDS_EventGet();
    }
#endif	
}
else
    MT6616_UART_Init_Done(0);
#else
    return;
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
#if defined (__WMT_SUPPORT__)
	MT6616_HCI_Send_Cmd(Opcode, data);
#endif	
}
#endif // defined(MT6616)
