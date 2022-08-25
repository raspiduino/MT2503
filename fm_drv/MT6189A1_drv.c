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
 * MT6189A1_drv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *      FM Radio Driver (MT6189A1)
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/
#include "kal_general_types.h"

#if (defined(MT6189A1))

static kal_uint8 cw_cache[66] = {0};

#if defined MT6189_DEBUG
static kal_uint8 dbg_cw_readback = 0;
#endif

#define USE_I2C
/// #define MT6189_DEBUG
/// #define MT6189_DEBUG_DUMP_LOG

#if (defined(MT6205B) || defined(MT6208)) && defined(MT6189_DEBUG_DUMP_LOG)
#error "No file system on MT6205!"
#endif

/* MT6189 Control Word */
#define CW(_A,_B)  (const)(kal_uint8)((_A << 1) + _B)

/* General propose constant */
#define MT6189                96    /// Device ID of MT6189 = 96
#define OP_WRITE              0     /// Write to MT6189
#define OP_READ               1     /// Read from MT6189
#define MT6189_WRITE          192
#define MT6189_READ           193
#define SET_FREQ_FAIL         -1
#define LO_INJECTION          0
#define HI_INJECTION          1
#define RSSI_CHECK_FAIL       2
#define FM_TUNER_GRID         100
#define PRESET_IF             140   /// Preset IF: 140 khz
#define IF_MEASURE_COUNT      2     /// 2 * 1,9 ms
#define VCO_LOCKING_TIME      6    /// 8 * 4.615 ms
#define CALIBRATION_FAIL_COUNT_THRESHOLD 5

#if !defined( MT6205B ) && !defined( MT6208 )
#define REF_CLK_32K
#define PRESET_IF_CNT         274   /// 140000 * 64 / 32768 = 273.4375
#define PRESET_IF_DELTA_O     30    //30
#define IF_CONVERT_FACTOR     512   /// 32768 / 64 = 512
#else
#define USE_MT6189_AMP
#define REF_CLK_26M
#define PRESET_IF_CNT         265   /// 140000 * 49152 / 26000000 = 264.66
#define PRESET_IF_DELTA_O     32
#define IF_CONVERT_FACTOR     529   /// 26000000 / 49152 = 529
#endif
/*
#define REF_CLK_26M
#define PRESET_IF_CNT         265   /// 140000 * 49152 / 26000000 = 264.66
#define PRESET_IF_DELTA       29
#define IF_CONVERT_FACTOR     529   /// 26000000 / 49152 = 529
*/

#ifdef USE_MT6189_AMP
void ExtSwitchInit(void);
void SwitchExtFMPath(kal_uint8 if_on);
#endif

/* Serial communication interfaces */
void  SerialCommInit(void);
void  SerialCommRelease(void);
void  SerialCommCryClkOn(void);
void  SerialCommCryClkOff(void);
void  GPIO_WriteIO(char data,char port);

#if defined USE_I2C
void  SerialCommStart(void);
void  SerialCommStop(void);
kal_uint8 SerialCommTxByte(kal_uint8 data);
void  SerialCommRxByte(kal_uint8 *data, kal_uint8 ack);
#elif defined USE_3_WIRE
kal_uint8 SerialCommTxByte(kal_uint8 cw, kal_uint8 data);
void  SerialCommRxByte(kal_uint8 cw, kal_uint8 *data);
#endif

typedef struct {
   kal_uint8 addr;
   kal_uint8 value;
} ctrl_word_setting;

typedef struct {
   kal_uint8 addr;
   kal_uint8 and;
   kal_uint8 or;
} ctrl_word_operation;

extern kal_uint8 const FM_RADIO_INPUT_LEVEL_THRESHOLD;

/// Global variables for current FM status
static kal_int16 _current_frequency = -1;
static kal_uint8 _current_level = 0x80;
static kal_bool  _is_fm_on = KAL_FALSE;
static kal_bool  _is_fm_mute = KAL_FALSE;
static kal_uint8 _valid_rssi = 0;
static kal_uint16 PRESET_IF_CNT_PLUS;		//add to adjust IF rounding
static kal_uint8 PRESET_IF_DELTA = PRESET_IF_DELTA_O;
static kal_uint8 RSSI_offset = 0;//FM_RADIO_INPUT_LEVEL_THRESHOLD;
static kal_uint8 _rssi_threshold = 0;//RSSI_offset;

#ifdef MT6189_DEBUG_DUMP_LOG
extern kal_uint32 video_get_current_time(void);
extern kal_uint32 video_get_duration_ms(kal_uint32 t1);
static kal_uint8 _file_name[] = {"D\0:\0\\\0f\0m\0_\0l\0o\0g\0.\0t\0x\0t\0\0\0"};
static kal_uint32 _data_written;
static kal_uint8  _dbg_str[128];
static FS_HANDLE  _file_handle = 0;
#endif

static void MT6189_Mute(kal_uint8 mute);
void FMDrv_EvaluateRSSIThreshold(void);
typedef enum group_idx {
	   mono=0,
	   stereo,
	   RSSI_threshold,
	   IF_count_delta,
	   GROUP_TOTAL_NUMS
	} FACTORY_GROUP_ENUM;
	
typedef enum item_idx {
	   Sblend_ON=0,
	   Sblend_OFF,  
	   ITEM_TOTAL_NUMS
	} FACTORY_ITEM_INDEX;

#define POWER_ON_COMMAND_COUNT 49
static const ctrl_word_setting PowerOnSetting[POWER_ON_COMMAND_COUNT] = {
   { CW(  6, 1),  16 },   { CW(  7, 1),   0 },
   { CW(  0, 1),   1 },   { CW(  0, 0),   1 },
   { CW( 14, 1),   7 },   { CW( 14, 0), 230 },//166
   { CW(  1, 1),   6 },   { CW(  1, 0),   0 },
   { CW(  2, 1),  12 },   { CW(  2, 0), 187 },
#if defined   REF_CLK_32K //==============================================
   { CW(  3, 1),  32 },   { CW(  3, 0),  34 },
#elif defined REF_CLK_13M
   { CW(  3, 1),  32 },   { CW(  3, 0),  66 },
#elif defined REF_CLK_26M
   { CW(  3, 1),  32 },   { CW(  3, 0), 194 },
#else
#error "Reference Clock Definition Error!"
#endif //=================================================================
   { CW(  4, 1), 194 },   { CW(  4, 0), 183 },
   { CW(  5, 1),   0 },   { CW(  5, 0), 255 },
   { CW(  8, 1),  198 },   { CW(  8, 0),  8 },
   { CW(  9, 1),    6 },   { CW(  9, 0),  2 },
   { CW( 10, 1),  48 },   { CW( 10, 0), 192 },
   { CW( 11, 1),  32 },   { CW( 11, 0),   0 },
   { CW( 12, 1),  49 },   { CW( 12, 0), 128 },
   { CW( 13, 1),   0 },   { CW( 13, 0),   3 },
   { CW( 15, 1), 170 },   { CW( 15, 0), 170 },
   { CW( 16, 1),   0 },   { CW( 16, 0),   0 },
   { CW( 17, 1), 136 },   { CW( 17, 0), 136 },
   { CW( 18, 1),   2 },   { CW( 18, 0),   2 },
   { CW( 19, 1),   0 },   { CW( 19, 0), 170 },
   { CW( 20, 1),   0 },   { CW( 20, 0),   0 },
   { CW( 21, 1),   7 },   { CW( 21, 0),  30 },
   { CW( 23, 1),   0 },   { CW( 23, 0),   0 },
   { CW( 24, 1),   5 },   { CW( 24, 0), 128 },
   { CW(  6, 1),  16 },   { CW(  7, 1),   0 },
   { CW(  7, 0),   7 },
}; 

#define POWER_OFF_COMMAND_COUNT 11
static const ctrl_word_operation PowerOffProc[POWER_OFF_COMMAND_COUNT] = {
   { CW(  1, 1), 0xDF, 0x20 }, /// CW1   [13:13]  1
   { CW(  5, 0), 0x00, 0x00 }, /// CW5   [7:0]    0
   { CW(  3, 0), 0xFE, 0x01 }, /// CW3   [0:0]    1
   { CW( 10, 0), 0xE0, 0x1F }, /// CW10  [4:0]    1
   { CW( 12, 0), 0xFE, 0x01 }, /// CW12  [0:0]    1
   { CW( 12, 1), 0xFD, 0x02 }, /// CW12  [9:9]    1
   { CW( 13, 0), 0xFE, 0x01 }, /// CW13  [0:0]    1
   { CW( 19, 1), 0xFE, 0x01 }, /// CW19  [8:8]    1
   { CW( 21, 0), 0xDF, 0x20 }, /// CW21  [5:5]    1
   { CW( 14, 1), 0x00, 0xFF }, /// CW14  [15:8]   1
   { CW(  4, 0), 0xFC, 0x00 }, /// CW4   [1:0]    0
};

#define CAL_PLL_COMMAND_COUNT 59
static const ctrl_word_operation CalPLLProcess[CAL_PLL_COMMAND_COUNT] = {
   { CW(  1, 1), 0xDF, 0x00 }, /// CW1   [13:13]  0
   { CW(  3, 0), 0xDD, 0x22 }, /// CW3   [5:5]    1, /// CW3   [1:1]    1
   { CW(  3, 1), 0x1F, 0xE0 }, /// CW3   [15:13]  7
   { CW(  6, 1), 0x0F, 0x10 }, /// CW6   [15:12]  1
   { CW(  7, 1), 0xFC, 0x00 }, /// CW7   [9:8]    0 
#if defined   REF_CLK_32K //==============================================
   { CW(  3, 0), 0x1E, 0x20 }, /// CW3   [7:5]    1, /// CW3   [0:0]    0
#elif defined REF_CLK_13M
   { CW(  3, 0), 0x1E, 0x40 }, /// CW3   [7:5]    2, /// CW3   [0:0]    0
#elif defined REF_CLK_26M
   { CW(  3, 0), 0x1E, 0xC0 }, /// CW3   [7:5]    6, /// CW3   [0:0]    0
#endif //=================================================================
   { CW(103, 1), 0xF8, 0x04 }, /// CW103 [10:8]   4
   { CW(103, 0), 0xC0, 0x20 }, /// CW103 [5:0]    32
   { CW(101, 0), 0xF8, 0x04 }, /// CW101 [2:0]    4
   { CW( 12, 0), 0x9E, 0x60 }, /// CW12  [0:0]    0, /// CW12  [6:5]    3
   { CW( 12, 1), 0xFE, 0x01 }, /// CW12  [8:8]    1
   { CW( 14, 0), 0x6F, 0x10 }, /// CW14  [4:4]    1, /// CW14  [7:7]    0
   { CW(  6, 0), 0xFC, 0x01 }, /// CW6   [1:0]    1
   { CW(  7, 1), 0xFC, 0x03 }, /// CW7   [9:8]    3
   { CW(  6, 1), 0x00, 0x66 }, /// CW6   [15:8]   102
   { CW( 25, 1), 0xF0, 0x03 }, /// CW25  [11:8]   3
#if defined   REF_CLK_32K //==============================================
   { CW( 25, 0), 0x00, 0x7A }, /// CW25  [7:0]    122
#elif defined REF_CLK_13M
   { CW( 25, 0), 0x00, 0x5E }, /// CW25  [7:0]    94
#elif defined REF_CLK_26M
   { CW( 25, 0), 0x00, 0x5E }, /// CW25  [7:0]    94
#endif //=================================================================
   { CW(  1, 0), 0x00, 0x00 }, /// CW1   [7:0]    0
#if defined   REF_CLK_32K //==============================================
   { CW(  5, 0), 0xEF, 0x10 }, /// CW5   [4:4]    1
#elif defined REF_CLK_13M
   { CW(  5, 0), 0xEF, 0x00 }, /// CW5   [4:4]    0
#elif defined REF_CLK_26M
   { CW(  5, 0), 0xEF, 0x00 }, /// CW5   [4:4]    0
#endif //=================================================================
   { CW(  6, 1), 0xFE, 0x01 }, /// CW6   [8:8]    1
   { CW(127, 1), 0x00, 0x01 }, /// <----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, /// CW1   [7:0]    0, reset CW1_0
   { CW(  6, 1), 0x0F, 0x10 }, /// CW6   [15:12]  1
   { CW(  7, 1), 0xFC, 0x00 }, /// CW7   [9:8]    0
#if defined   REF_CLK_32K //==============================================
   { CW(  3, 0), 0x1E, 0x20 }, /// CW3   [7:5]    1, /// CW3   [0:0]    0
#elif defined REF_CLK_13M
   { CW(  3, 0), 0x1E, 0x40 }, /// CW3   [7:5]    2, /// CW3   [0:0]    0
#elif defined REF_CLK_26M
   { CW(  3, 0), 0x1E, 0xC0 }, /// CW3   [7:5]    6, /// CW3   [0:0]    0
#endif //=================================================================
   { CW( 12, 0), 0x9E, 0x60 }, /// CW12  [6:5]    3, /// CW12  [0:0]    0
   { CW( 12, 1), 0xFE, 0x01 }, /// CW12  [8:8]    1
   { CW( 14, 0), 0x6F, 0x10 }, /// CW14  [4:4]    1, /// CW14  [7:7]    0
   { CW(  6, 0), 0xFC, 0x01 }, /// CW6   [1:0]    1
   { CW(  7, 1), 0xFC, 0x03 }, /// CW7   [9:8]    3
   { CW(  6, 1), 0x00, 0x76 }, /// CW6   [15:8]   118
   { CW( 25, 1), 0xF0, 0x03 }, /// CW25  [11:8]   3
#if defined   REF_CLK_32K //==============================================
   { CW( 25, 0), 0x00, 0x7A }, /// CW25  [7:0]    122
#elif defined REF_CLK_13M
   { CW( 25, 0), 0x00, 0x5E }, /// CW25  [7:0]    94
#elif defined REF_CLK_26M
   { CW( 25, 0), 0x00, 0x5E }, /// CW25  [7:0]    94
#endif //=================================================================
   { CW(  1, 0), 0x00, 0x00 }, /// CW1   [7:0]    0
#if defined   REF_CLK_32K //==============================================
   { CW(  5, 0), 0xEF, 0x10 }, /// CW5   [4:4]    1
#elif defined REF_CLK_13M
   { CW(  5, 0), 0xEF, 0x00 }, /// CW5   [4:4]    0
#elif defined REF_CLK_26M
   { CW(  5, 0), 0xEF, 0x00 }, /// CW5   [4:4]    0
#endif //=================================================================
   { CW(  6, 1), 0xFE, 0x01 }, /// CW6   [8:8]    1
   { CW(127, 1), 0x00, 0x01 }, /// <----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, /// CW1   [7:0]    0, reset CW1_0
   { CW(  6, 1), 0x0F, 0x10 }, /// CW6   [15:12]  1
   { CW(  7, 1), 0xFC, 0x00 }, /// CW7   [9:8]    0
#if defined   REF_CLK_32K //==============================================
   { CW(  3, 0), 0x1E, 0x20 }, /// CW3   [7:5]    1, /// CW3   [0:0]    0
#elif defined REF_CLK_13M
   { CW(  3, 0), 0x1E, 0x40 }, /// CW3   [7:5]    2, /// CW3   [0:0]    0
#elif defined REF_CLK_26M
   { CW(  3, 0), 0x1E, 0xC0 }, /// CW3   [7:5]    6, /// CW3   [0:0]    0
#endif //=================================================================
   { CW( 12, 0), 0x9E, 0x60 }, /// CW12  [6:5]    3, /// CW12  [0:0]    0
   { CW( 12, 1), 0xFE, 0x01 }, /// CW12  [8:8]    1
   { CW( 14, 0), 0x6F, 0x10 }, /// CW14  [4:4]    1, /// CW14  [7:7]    0
   { CW(  6, 0), 0xFC, 0x01 }, /// CW6   [1:0]    1
   { CW(  6, 1), 0x00, 0x56 }, /// CW6   [15:8]   86
   { CW(  7, 1), 0xFC, 0x03 }, /// CW7   [9:8]    3
   { CW( 25, 1), 0xF0, 0x03 }, /// CW25  [11:8]   3
#if defined   REF_CLK_32K //==============================================
   { CW( 25, 0), 0x00, 0x7A }, /// CW25  [7:0]    122
#elif defined REF_CLK_13M
   { CW( 25, 0), 0x00, 0x5E }, /// CW25  [7:0]    94
#elif defined REF_CLK_26M
   { CW( 25, 0), 0x00, 0x5E }, /// CW25  [7:0]    94
#endif //=================================================================
   { CW(  1, 0), 0x00, 0x00 }, /// CW1   [7:0]    0
#if defined   REF_CLK_32K //==============================================
   { CW(  5, 0), 0xEF, 0x10 }, /// CW5   [4:4]    1
#elif defined REF_CLK_13M
   { CW(  5, 0), 0xEF, 0x00 }, /// CW5   [4:4]    0
#elif defined REF_CLK_26M
   { CW(  5, 0), 0xEF, 0x00 }, /// CW5   [4:4]    0
#endif //=================================================================
   { CW(  6, 1), 0xFE, 0x01 }, /// CW6   [8:8]    1
   { CW(127, 1), 0x00, 0x01 }, /// <----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, /// CW1   [7:0]    0, reset CW1_0
   { CW( 14, 0), 0x6F, 0x80 }, /// CW14  [4:4]    0, [7:7]     1
   { CW( 12, 0), 0x1F, 0x80 }, /// CW12  [6:5]    0, /// CW12  [7:7]    1 
   { CW( 12, 1), 0xDF, 0x00 }, /// CW12  [13:13]  0
   { CW( 13, 0), 0x7F, 0x00 }, /// CW13  [7:7]    0
   { CW( 23, 1), 0xE3, 0x00 }, /// CW23  [12:10]  0
};

#define CAL_DEMOD_I_COMMAND_COUNT 41
static const ctrl_word_operation CalDemodIProcess[CAL_DEMOD_I_COMMAND_COUNT] = {
   { CW(  1, 1), 0xDF, 0x00 }, /// CW1   [13:13]  0
   { CW( 10, 0), 0xF7, 0x00 }, /// CW10  [3:3]    0
   { CW(  8, 1), 0xF7, 0x00 }, /// CW8   [11:11]  0
   { CW(  8, 1), 0xFE, 0x01 }, /// CW8   [8:8]    1
   { CW(  9, 1), 0xFE, 0x01 }, /// CW9   [8:8]    1
   { CW( 10, 0), 0xBF, 0x00 }, /// CW10  [6:6]    0
   { CW( 10, 0), 0xBF, 0x40 }, /// CW10  [6:6]    1
#if defined   REF_CLK_32K //==============================================
   { CW(  3, 0), 0x1C, 0x22 }, /// CW3   [7:5]    1, /// CW3   [1:0]    2
#elif defined REF_CLK_13M
   { CW(  3, 0), 0x1C, 0x42 }, /// CW3   [7:5]    2, /// CW3   [1:0]    2
#elif defined REF_CLK_26M
   { CW(  3, 0), 0x1C, 0xC2 }, /// CW3   [7:5]    6, /// CW3   [1:0]    2
#endif //=================================================================
   { CW(  3, 1), 0xDF, 0x20 }, /// CW3   [13:13]  1
   { CW( 12, 1), 0xFD, 0x00 }, /// CW12  [9:9]    0
   { CW( 12, 0), 0xFE, 0x00 }, /// CW12  [0:0]    0
   { CW(  6, 1), 0x00, 0x1A }, /// CW6   [15:8]   26
   { CW(  7, 1), 0xFC, 0x00 }, /// CW7   [9:8]    0
   { CW( 98, 1), 0xE0, 0x00 }, /// CW98  [12:8]   0
   { CW( 98, 0), 0xF0, 0x00 }, /// CW98  [3:0]    0
   { CW(  7, 1), 0xFC, 0x03 }, /// CW7   [9:8]    3
   { CW(  6, 0), 0xFC, 0x01 }, /// CW6   [1:0]    1
   { CW(  6, 1), 0x00, 0xAA }, /// CW6   [15:8]   170
   { CW( 25, 1), 0x00, 0x02 }, /// CW25  [15:8]   2+

#if defined   REF_CLK_32K //==============================================
   { CW( 25, 0), 0x00, 0x22 }, /// CW25  [7:0]    34
#elif defined REF_CLK_13M
   { CW( 25, 0), 0x00, 0x11 }, /// CW25  [7:0]    17
#elif defined REF_CLK_26M
   { CW( 25, 0), 0x00, 0x11 }, /// CW25  [7:0]    17
#endif //=================================================================
   { CW( 98, 1), 0x00, 0x00 }, /// CW98  [15:8]   0
   { CW( 98, 0), 0x00, 0x00 }, /// CW98  [7:0]    0
#if defined   REF_CLK_32K //==============================================
   { CW( 25, 0), 0x00, 0x22 }, /// CW25  [7:0]    34
#elif defined REF_CLK_13M
   { CW( 25, 0), 0x00, 0x11 }, /// CW25  [7:0]    17
#elif defined REF_CLK_26M
   { CW( 25, 0), 0x00, 0x11 }, /// CW25  [7:0]    17
#endif //=================================================================
   { CW(  6, 1), 0x00, 0xAA }, /// CW6   [15:8]   170
   { CW(  7, 1), 0xFC, 0x03 }, /// CW7   [9:8]    3
   { CW(  1, 0), 0x00, 0x00 }, /// CW1   [7:0]    0
   { CW(  6, 0), 0xFC, 0x01 }, /// CW6   [1:0]    1
#if defined   REF_CLK_32K //==============================================
   { CW(  5, 0), 0xEF, 0x10 }, /// CW5   [4:4]    1
#elif defined REF_CLK_13M
   { CW(  5, 0), 0xEF, 0x00 }, /// CW5   [4:4]    0
#elif defined REF_CLK_26M
   { CW(  5, 0), 0xEF, 0x00 }, /// CW5   [4:4]    0
#endif //=================================================================
   { CW(  6, 1), 0xFE, 0x01 }, /// CW6   [8:8]    1
   { CW(127, 1), 0x00, 0x01 }, /// <----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, /// CW1   [7:0]    0: reset CW1_0
   { CW( 98, 0), 0x00, 0x00 }, /// CW98  [7:0]    0
#if defined   REF_CLK_32K //==============================================
   { CW( 25, 0), 0x00, 0x22 }, /// CW25  [7:0]    34
#elif defined REF_CLK_13M
   { CW( 25, 0), 0x00, 0x11 }, /// CW25  [7:0]    17
#elif defined REF_CLK_26M
   { CW( 25, 0), 0x00, 0x11 }, /// CW25  [7:0]    17
#endif //=================================================================
   { CW(  6, 1), 0x0F, 0xB0 }, /// CW6   [15:12]  11   
   { CW(  7, 1), 0x00, 0x03 }, /// CW7   [15:8]   3
   { CW(  6, 0), 0xFC, 0x01 }, /// CW6   [1:0]    1
   { CW(  1, 0), 0x00, 0x00 }, /// CW1   [7:0]    0
#if defined   REF_CLK_32K //==============================================
   { CW(  5, 0), 0xEF, 0x10 }, /// CW5   [4:4]    1
#elif defined REF_CLK_13M
   { CW(  5, 0), 0xEF, 0x00 }, /// CW5   [4:4]    0
#elif defined REF_CLK_26M
   { CW(  5, 0), 0xEF, 0x00 }, /// CW5   [4:4]    0
#endif //=================================================================
   { CW(  6, 1), 0xFE, 0x01 }, /// CW6   [8:8]    1
   { CW(127, 1), 0x00, 0x01 }, /// <----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, /// CW1   [7:0]    0: reset CW1_0
};

#define CAL_DEMOD_Q_COMMAND_COUNT 41
static const ctrl_word_operation CalDemodQProcess[CAL_DEMOD_Q_COMMAND_COUNT] = {
   { CW(  1, 1), 0xDF, 0x00 }, /// CW1   [13:13]  0
   { CW( 10, 0), 0xF7, 0x00 }, /// CW10  [3:3]    0
   { CW(  8, 1), 0xF7, 0x00 }, /// CW8   [11:11]  0
   { CW(  8, 1), 0xFE, 0x01 }, /// CW8   [8:8]    1
   { CW(  9, 1), 0xFE, 0x01 }, /// CW9   [8:8]    1
   { CW( 10, 0), 0xBF, 0x00 }, /// CW10  [6:6]    0
   { CW( 10, 0), 0xBF, 0x40 }, /// CW10  [6:6]    1
#if defined   REF_CLK_32K //==============================================
   { CW(  3, 0), 0x1C, 0x22 }, /// CW3   [7:5]    1, /// CW3   [1:0]    2
#elif defined REF_CLK_13M
   { CW(  3, 0), 0x1C, 0x42 }, /// CW3   [7:5]    2, /// CW3   [1:0]    2
#elif defined REF_CLK_26M
   { CW(  3, 0), 0x1C, 0xC2 }, /// CW3   [7:5]    6, /// CW3   [1:0]    2
#endif //=================================================================
   { CW(  3, 1), 0xDF, 0x20 }, /// CW3   [13:13]  1
   { CW( 12, 1), 0xFD, 0x00 }, /// CW12  [9:9]    0
   { CW( 12, 0), 0xFE, 0x00 }, /// CW12  [0:0]    0
   { CW(  6, 1), 0x00, 0x1A }, /// CW6   [15:8]   28
   { CW(  7, 1), 0xFC, 0x00 }, /// CW7   [9:8]    0
   { CW( 99, 1), 0xE0, 0x00 }, /// CW99  [12:8]   0
   { CW( 99, 0), 0xF0, 0x00 }, /// CW99  [3:0]    0
   { CW(  7, 1), 0xFC, 0x03 }, /// CW7   [9:8]    3
   { CW(  6, 0), 0xFC, 0x01 }, /// CW6   [1:0]    1
   { CW(  6, 1), 0x00, 0xCC }, /// CW6   [15:8]   204
   { CW( 25, 1), 0x00, 0x02 }, /// CW25  [15:8]   2
#if defined   REF_CLK_32K //==============================================
   { CW( 25, 0), 0x00, 0x22 }, /// CW25  [7:0]    34
#elif defined REF_CLK_13M
   { CW( 25, 0), 0x00, 0x11 }, /// CW25  [7:0]    17
#elif defined REF_CLK_26M
   { CW( 25, 0), 0x00, 0x11 }, /// CW25  [7:0]    17
#endif //=================================================================
   { CW( 99, 1), 0x00, 0x00 }, /// CW99  [15:8]   0
   { CW( 99, 0), 0x00, 0x00 }, /// CW99  [7:0]    0
#if defined   REF_CLK_32K //==============================================
   { CW( 25, 0), 0x00, 0x22 }, /// CW25  [7:0]    34
#elif defined REF_CLK_13M
   { CW( 25, 0), 0x00, 0x11 }, /// CW25  [7:0]    17
#elif defined REF_CLK_26M
   { CW( 25, 0), 0x00, 0x11 }, /// CW25  [7:0]    17
#endif //=================================================================
   { CW(  6, 1), 0x00, 0xCC }, /// CW6   [15:8]   204
   { CW(  7, 1), 0xFC, 0x03 }, /// CW7   [9:8]    3
   { CW(  1, 0), 0x00, 0x00 }, /// CW1   [7:0]    0
   { CW(  6, 0), 0xFC, 0x01 }, /// CW6   [1:0]    1
#if defined   REF_CLK_32K //==============================================
   { CW(  5, 0), 0xEF, 0x10 }, /// CW5   [4:4]    1
#elif defined REF_CLK_13M
   { CW(  5, 0), 0xEF, 0x00 }, /// CW5   [4:4]    0
#elif defined REF_CLK_26M
   { CW(  5, 0), 0xEF, 0x00 }, /// CW5   [4:4]    0
#endif //=================================================================
   { CW(  6, 1), 0xFE, 0x01 }, /// CW6   [8:8]    1
   { CW(127, 1), 0x00, 0x01 }, /// <----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, /// CW1   [7:0]    0: reset CW1_0
   { CW( 99, 0), 0x00, 0x00 }, /// CW99  [7:0]    0
#if defined   REF_CLK_32K //==============================================
   { CW( 25, 0), 0x00, 0x22 }, /// CW25  [7:0]    34
#elif defined REF_CLK_13M
   { CW( 25, 0), 0x00, 0x11 }, /// CW25  [7:0]    17
#elif defined REF_CLK_26M
   { CW( 25, 0), 0x00, 0x11 }, /// CW25  [7:0]    17
#endif //=================================================================
   { CW(  6, 1), 0x0F, 0xD0 }, /// CW6   [15:12]  13   
   { CW(  7, 1), 0x00, 0x03 }, /// CW7   [15:8]   3
   { CW(  6, 0), 0xFC, 0x01 }, /// CW6   [1:0]    1
   { CW(  1, 0), 0x00, 0x00 }, /// CW1   [7:0]    0
#if defined   REF_CLK_32K //==============================================
   { CW(  5, 0), 0xEF, 0x10 }, /// CW5   [4:4]    1
#elif defined REF_CLK_13M
   { CW(  5, 0), 0xEF, 0x00 }, /// CW5   [4:4]    0
#elif defined REF_CLK_26M
   { CW(  5, 0), 0xEF, 0x00 }, /// CW5   [4:4]    0
#endif //=================================================================
   { CW(  6, 1), 0xFE, 0x01 }, /// CW6   [8:8]    1
   { CW(127, 1), 0x00, 0x01 }, /// <----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, /// CW1   [7:0]    0: reset CW1_0
};

#define CAL_PILOT_COMMAND_COUNT 37
static const ctrl_word_operation CalPilotProcess[CAL_PILOT_COMMAND_COUNT] = {
   { CW( 10, 1), 0xFB, 0x00 }, /// CW10  [10:10]  0
   { CW( 10, 0), 0x6F, 0x80 }, /// CW10  [7:7]    1, [4:4]    0
   { CW( 11, 1), 0xDF, 0x00 }, /// CW11  [13:13]  0
   { CW( 11, 1), 0xDF, 0x20 }, /// CW11  [13:13]  1
   { CW(  1, 1), 0xDF, 0x00 }, /// CW1   [13:13]  0
   { CW( 10, 0), 0xF7, 0x00 }, /// CW10  [3:3]    0
   { CW(  8, 1), 0xF7, 0x00 }, /// CW8   [11:11]  0
   { CW(  8, 1), 0xFE, 0x01 }, /// CW8   [8:8]    1
   { CW(  9, 1), 0xFE, 0x01 }, /// CW9   [8:8]    1
   { CW( 10, 0), 0xBF, 0x00 }, /// CW10  [6:6]    0
   { CW( 10, 0), 0xBF, 0x40 }, /// CW10  [6:6]    1
#if defined   REF_CLK_32K //==============================================
   { CW(  3, 0), 0x1C, 0x22 }, /// CW3   [7:5]    1, /// CW3   [1:0]    2
#elif defined REF_CLK_13M
   { CW(  3, 0), 0x1C, 0x42 }, /// CW3   [7:5]    2, /// CW3   [1:0]    2
#elif defined REF_CLK_26M
   { CW(  3, 0), 0x1C, 0xC2 }, /// CW3   [7:5]    6, /// CW3   [1:0]    2
#endif //=================================================================
   { CW(  3, 1), 0xDF, 0x20 }, /// CW3   [13:13]  1
   { CW( 12, 1), 0xFD, 0x00 }, /// CW12  [9:9]    0
   { CW( 12, 0), 0xFE, 0x00 }, /// CW12  [0:0]    0
   { CW(  6, 1), 0x00, 0x1E }, /// CW6   [15:8]   30
   { CW(  7, 1), 0xFC, 0x00 }, /// CW7   [9:8]    0
   { CW( 97, 1), 0xE0, 0x00 }, /// CW97  [12:8]   0
   { CW( 97, 0), 0xF0, 0x00 }, /// CW97  [3:0]    0
   { CW(  7, 1), 0xFC, 0x03 }, /// CW7   [9:8]    3
   { CW(  6, 0), 0xFC, 0x01 }, /// CW6   [1:0]    1
   { CW(  6, 1), 0x00, 0xEE }, /// CW6   [15:8]   238
   { CW( 25, 1), 0x00, 0x03 }, /// CW25  [15:8]   3
#if defined   REF_CLK_32K //==============================================
   { CW( 25, 0), 0x00, 0x7A }, /// CW25  [7:0]    122
#elif defined REF_CLK_13M
   { CW( 25, 0), 0x00, 0x5E }, /// CW25  [7:0]    94
#elif defined REF_CLK_26M
   { CW( 25, 0), 0x00, 0x5E }, /// CW25  [7:0]    94
#endif //=================================================================
   { CW(  1, 0), 0x00, 0x00 }, /// CW1   [7:0]    0
#if defined   REF_CLK_32K //==============================================
   { CW(  5, 0), 0xEF, 0x10 }, /// CW5   [4:4]    1
#elif defined REF_CLK_13M
   { CW(  5, 0), 0xEF, 0x00 }, /// CW5   [4:4]    0
#elif defined REF_CLK_26M
   { CW(  5, 0), 0xEF, 0x00 }, /// CW5   [4:4]    0
#endif //=================================================================
   { CW(  6, 1), 0xFE, 0x01 }, /// CW6   [8:8]    1
   { CW(127, 1), 0x00, 0x01 }, /// <----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, /// CW1   [7:0]    0, reset CW1_0
#if defined   REF_CLK_32K //==============================================
   { CW( 25, 0), 0x00, 0x7A }, /// CW25  [7:0]    122
#elif defined REF_CLK_13M
   { CW( 25, 0), 0x00, 0x5E }, /// CW25  [7:0]    94
#elif defined REF_CLK_26M
   { CW( 25, 0), 0x00, 0x5E }, /// CW25  [7:0]    94
#endif //=================================================================
   { CW(  6, 1), 0x0F, 0xF0 }, /// CW6   [15:12]  15
   { CW(  7, 1), 0xFC, 0x03 }, /// CW7   [9:8]    3
   { CW(  1, 0), 0x00, 0x00 }, /// CW1   [7:0]    0
#if defined   REF_CLK_32K //==============================================
   { CW(  5, 0), 0xEF, 0x10 }, /// CW5   [4:4]    1
#elif defined REF_CLK_13M
   { CW(  5, 0), 0xEF, 0x00 }, /// CW5   [4:4]    0
#elif defined REF_CLK_26M
   { CW(  5, 0), 0xEF, 0x00 }, /// CW5   [4:4]    0
#endif //=================================================================
   { CW(  6, 1), 0xFE, 0x01 }, /// CW6   [8:8]    1
   { CW(127, 1), 0x00, 0x01 }, /// <----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, /// CW1   [7:0]    0, reset CW1_0
};

static kal_uint8 MT6189_ReadCache(kal_uint8 CW)
{
   if (CW < 52)
      return cw_cache[CW];
   else
      return cw_cache[CW-142];
}

static void MT6189_ReadByte(kal_uint8 CW, kal_uint8 *data)
{
   if (CW == 255) {
      *data = 0;
      return;
   }
#if defined USE_I2C
   SerialCommStart();                /// send the start sequence
   SerialCommTxByte(MT6189_WRITE);   /// device ID and R/W bit
   SerialCommTxByte(CW);             /// control word
   SerialCommStart();                /// resend the start sequence
   SerialCommTxByte(MT6189_READ);    /// device ID and R/W bit
   SerialCommRxByte(data, 0);        /// read data and send ACK
   SerialCommStop();                 /// send the stop sequence
#elif defined USE_3_WIRE
   SerialCommRxByte(CW, data);
#else
#error "Must define USE_I2C or USE_3_WIRE"
#endif
}


/* MT6189 does not support sequential write. */
static kal_bool MT6189_WriteByte(kal_uint8 CW, kal_uint8 data)
{
   if (CW == 255) {
      kal_uint32 i = 0;
      while (1) {
         kal_uint8 dataRead;
         MT6189_ReadByte(CW(1,0), &dataRead);
         if (dataRead & data) {
            return KAL_TRUE;
         }

         if (i++ == 20) {
            return KAL_FALSE;
         }
         kal_sleep_task(1);
      }
   }
#if defined USE_I2C
   SerialCommStart();                /// send the start sequence
   SerialCommTxByte(MT6189_WRITE);   /// device ID and R/W bit
   SerialCommTxByte(CW);             /// control word   
   SerialCommTxByte(data);           /// data to be written
   SerialCommStop();                 /// send the stop sequence
#elif defined USE_3_WIRE
   SerialCommTxByte(CW, data);
#else
#error "Must define USE_I2C or USE_3_WIRE"
#endif

   if (CW < 52)
      cw_cache[CW] = data;
   else
      cw_cache[CW-142] = data;

#if defined MT6189_DEBUG
   MT6189_ReadByte(CW, &dbg_cw_readback);
#endif
   return KAL_TRUE;
}

#if defined MT6189_DEBUG
static void MT6189_DumpCtrlWord(void) {
   kal_uint32 i;
   for (i=0; i<26; i++) {
      MT6189_ReadByte((i<<1), &(cw_cache[i << 1]));
      MT6189_ReadByte((i<<1)+1, &(cw_cache[(i << 1)+1]));
   }

   for (i=97; i<104; i++) {
      MT6189_ReadByte((i<<1), &(cw_cache[(i-71) << 1]));
      MT6189_ReadByte((i<<1)+1, &(cw_cache[((i-71) << 1) + 1]));
   }
}
#endif

void FMDrv_radio_item_info(kal_uint16 group_idx, kal_uint16 item_idx, kal_uint32 item_value)
{
	kal_uint8 TmpReg1;
	
	SerialCommInit();
	switch (group_idx)
	{
		case mono:
			if(item_value == 1)
  			{
      			MT6189_ReadByte(CW(14, 0), &TmpReg1);
      			TmpReg1&=0x6F;
      			MT6189_WriteByte(CW(14, 0),TmpReg1);
      	    }
      	    else
      	    {
      			MT6189_ReadByte(CW(14, 0), &TmpReg1);
      			TmpReg1&=0x6F;
      			MT6189_WriteByte(CW(14, 0),(kal_uint8)(TmpReg1) | 0x10);
      	    }
   
		break;
		case stereo:
			if(item_value == 0)
			{
					MT6189_ReadByte(CW(14, 0), &TmpReg1);
      			    TmpReg1&=0x6F;
      			    MT6189_WriteByte(CW(14, 0),TmpReg1);
			}
			switch (item_idx)
			{
				case Sblend_ON:
					MT6189_ReadByte(CW(14, 0), &TmpReg1);
      			    TmpReg1&=0x6F;
      			    MT6189_WriteByte(CW(14, 0),(kal_uint8)(TmpReg1) | 0x10);
				break;
				case Sblend_OFF:
					MT6189_ReadByte(CW(14, 0), &TmpReg1);
      			    TmpReg1&=0x6F;
      			    MT6189_WriteByte(CW(14, 0),(kal_uint8)(TmpReg1) | 0x10);
				break;
				default:
				    ASSERT(0);	
			}
		break;
		case RSSI_threshold:
		    if (item_value == 1)
		        RSSI_offset = 1;
		    else if (item_value == 2)
		        RSSI_offset = 2;
		    else if (item_value == 3)
		        RSSI_offset = 3;
		    else if (item_value == 4)
		        RSSI_offset = 4;
		    else if (item_value == 5)
		        RSSI_offset = 5;
		    else if (item_value == 6)
		        RSSI_offset = 6;
		    else
		    	RSSI_offset = FM_RADIO_INPUT_LEVEL_THRESHOLD;
		break;
		case IF_count_delta:
			if(item_value == 10)
			{
#if !defined( MT6205B ) && !defined( MT6208 )
				PRESET_IF_DELTA = 20;
#else
				PRESET_IF_DELTA = 20;
#endif
			}
			else if(item_value == 15)
			{
#if !defined( MT6205B ) && !defined( MT6208 )
				PRESET_IF_DELTA = 30;
#else
				PRESET_IF_DELTA = 30;
#endif
			}
			else if(item_value == 20)
			{
#if !defined( MT6205B ) && !defined( MT6208 )
				PRESET_IF_DELTA = 40;
#else
				PRESET_IF_DELTA = 40;
#endif
			}
			else if(item_value == 25)
			{
#if !defined( MT6205B ) && !defined( MT6208 )
				PRESET_IF_DELTA = 50;
#else
				PRESET_IF_DELTA = 50;
#endif
			}
			else if(item_value == 30)
			{
#if !defined( MT6205B ) && !defined( MT6208 )
				PRESET_IF_DELTA = 60;
#else
				PRESET_IF_DELTA = 60;
#endif
			}
			else 
			{
#if !defined( MT6205B ) && !defined( MT6208 )
				PRESET_IF_DELTA = 30;
#else
				PRESET_IF_DELTA = 30;
#endif
			}
		break;
		
	}
	SerialCommRelease();
}


static kal_uint16 MT6189_GetCurRSSI(void)
{
   kal_uint8 TmpReg;
   MT6189_WriteByte(CW(12, 1), (kal_uint8)(MT6189_ReadCache(CW(12, 1)) & 0xFD));

   MT6189_WriteByte(CW(12, 0), (kal_uint8)(MT6189_ReadCache(CW(12, 0)) & 0xFE));

   MT6189_WriteByte(CW(14, 1), (kal_uint8)(MT6189_ReadCache(CW(14, 1)) & 0xEF));

   MT6189_ReadByte(CW(4, 1), &TmpReg);
   return (TmpReg & 0x0F);
}

static kal_uint8 MT6189_ReadIntFlags(kal_bool ReadClear)
{
   kal_uint8 TmpReg;
   MT6189_ReadByte(CW(1, 0), &TmpReg);
   if (ReadClear)
      MT6189_WriteByte(CW(1, 0), 0x00);
   return TmpReg;
}

/// Timing window for 32K clock: 64/32768 = 0.00195 second
/// Timing window for 26M clock: 49152/26000000 = 0.00189 second
static kal_int32 MT6189_GetCurIFCnt(kal_uint8 count, kal_uint8 early_check)
{
   kal_int32  CurIF = 0;
   kal_uint32 WaitingCounter = 0;
   kal_uint32 if_cnt;
   kal_uint16 rssi;
   kal_int32  i = (kal_int32)count;
   kal_int32  rssi_consecutive_fail = 0;
   kal_int32  if_consecutive_fail = 0;

	_valid_rssi = 0;
#ifdef MT6189_DEBUG_DUMP_LOG
   kal_sprintf((void*)_dbg_str, "   MT6189_GetCurIFCnt(%d, %d);\n   \0", count, early_check);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif

   /// Disable counter
   MT6189_WriteByte(CW(6, 1), 0x14);

   /// Clear interrupt flags
   MT6189_WriteByte(CW(1, 0), 0x00);

   MT6189_WriteByte(CW(7, 1), (kal_uint8)(MT6189_ReadCache(CW(7, 1)) & 0xFC));

   MT6189_WriteByte(CW(6, 0), 0x01);
   while (--i >= 0) {
      kal_uint8  TmpReg;

      /// Clear IF counter
      MT6189_WriteByte(CW(20, 0), 0x00);
      MT6189_WriteByte(CW(20, 1), 0x00);

      /// Enable counter
      MT6189_WriteByte(CW(6, 1), 0x15);

      /// Make sure that the counting is done
      do {
         if (++WaitingCounter == 4096) {
            ASSERT(0);
            return 0;
         }
         MT6189_ReadByte(CW(1, 0), &TmpReg);
      } while ((TmpReg & 0x08) == 0);

      /// Disable counter
      MT6189_WriteByte(CW(6, 1), 0x14);

      /// Clear interrupt flags
      MT6189_WriteByte(CW(1, 0), 0x00);

      MT6189_ReadByte(CW(20, 1), &TmpReg);
      if_cnt = (TmpReg & 0x03);
      if_cnt <<= 8;

      MT6189_ReadByte(CW(20, 0), &TmpReg);
      if_cnt += TmpReg;
      CurIF += if_cnt;

#ifdef MT6189_DEBUG_DUMP_LOG
      kal_sprintf((void*)_dbg_str, "%d,\0", if_cnt);
      FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
      rssi = (kal_uint16)MT6189_GetCurRSSI();
      _valid_rssi += rssi;

      if (early_check) {
#ifdef MT6189_DEBUG_DUMP_LOG
         kal_sprintf((void*)_dbg_str, "%d   \0", rssi);
         FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
         if (rssi < _rssi_threshold) {
            if (++rssi_consecutive_fail == 1) {
               CurIF /= (count-i);
               _valid_rssi /= (count-i);
#ifdef MT6189_DEBUG_DUMP_LOG
               kal_sprintf((void*)_dbg_str, "\n   RSSI Early Check Fail!\n\0");
               FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
               return -CurIF;
            }
         } else {
            rssi_consecutive_fail = 0;
         }

         if (if_cnt > (PRESET_IF_CNT_PLUS + 120) ||
             if_cnt < (PRESET_IF_CNT_PLUS - 120)) {
            if (++if_consecutive_fail == 1) {
               CurIF /= (count-i);
               _valid_rssi /= (count-i);
#ifdef MT6189_DEBUG_DUMP_LOG
               kal_sprintf((void*)_dbg_str, "\n   IF Early Check Fail!\n\0");
               FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
               return -CurIF;
            }
         } else {
            if_consecutive_fail = 0;
         }
      }
   }
   _valid_rssi = (_valid_rssi/count);
   CurIF = (CurIF/count);
#ifdef MT6189_DEBUG_DUMP_LOG
   kal_sprintf((void*)_dbg_str, "\n   IF count returned: %d\n\0", CurIF);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
   return CurIF;
}

/// Timing window for 32K clock: 64/32768 = 0.00195 second
/// Timing window for 26M clock: 49152/26000000 = 0.00189 second
static kal_uint16 MT6189_GetCurIF(void)
{
   kal_uint32 CurIF = MT6189_GetCurIFCnt(IF_MEASURE_COUNT, 0);
   CurIF *= IF_CONVERT_FACTOR;
   CurIF /= 1000;
   return (kal_uint16) CurIF;
}

static kal_bool MT6189_SetFreq(kal_int32 CurFreq, kal_uint8 HiLoInj)
{
   kal_uint16 Divider, N2, Ns, Target;
   kal_uint8  TmpReg;
   kal_uint32 WaitingCounter = 0,freq = 0,CurFreq_PLUS = 0;

	_current_frequency = CurFreq/FM_TUNER_GRID;
	freq = CurFreq;
	PRESET_IF_CNT_PLUS = PRESET_IF_CNT;
   /// DividerNumber = (CurFreq +- PresetIF) * 4 / RefClock 
   if (HiLoInj == LO_INJECTION) {
      CurFreq -= PRESET_IF;
   } else {
      CurFreq += PRESET_IF;
   }
   CurFreq *= 4000;

#if defined   REF_CLK_32K
   CurFreq += 16384;    /// rounding
   CurFreq >>= 15;
   CurFreq_PLUS = (kal_uint32)(CurFreq*32768/4000);
	if(CurFreq_PLUS>freq)
   	PRESET_IF_CNT_PLUS = (kal_uint16)((CurFreq_PLUS-freq)*1000*64/32768);
   else
   	PRESET_IF_CNT_PLUS = (kal_uint16)((freq-CurFreq_PLUS)*1000*64/32768);
#else
   CurFreq += 16927;    /// rounding
   CurFreq /= 33854;
   CurFreq_PLUS = (kal_uint32)(CurFreq*33854/4000);
   if(CurFreq_PLUS>freq)
   	PRESET_IF_CNT_PLUS = (kal_uint16)((CurFreq_PLUS-freq)*1.891);//1000*49152/26000000
   else
   	PRESET_IF_CNT_PLUS = (kal_uint16)((freq-CurFreq_PLUS)*1.891);//1000*49152/26000000
#endif
   
   Divider = CurFreq;
   N2 = (Divider >> 6);
   Ns = Divider - (N2 << 6);
   Target = (Divider >> 4);

   /// CW12  [0:0]  0
   MT6189_WriteByte(CW(12, 0), (kal_uint8)(MT6189_ReadCache(CW(12, 0)) & 0xFE));

   /// CW12  [9:9]  0
   MT6189_WriteByte(CW(12, 1), (kal_uint8)(MT6189_ReadCache(CW(12, 1)) & 0xFD));

   /// CW7   [4:0]  7
   MT6189_WriteByte(CW(7, 0), (kal_uint8)((MT6189_ReadCache(CW(7, 0)) & 0xE0) | 0x07));

   /// Set Hi/Lo injection
   TmpReg = MT6189_ReadCache(CW(4, 0)) & 0x7F;
   if (HiLoInj == HI_INJECTION)
      TmpReg |= 0x80;
   MT6189_WriteByte(CW(4, 0), TmpReg);

   /// Set IF as 140 khz
   MT6189_WriteByte(CW(4, 1), (kal_uint8)((MT6189_ReadCache(CW(4, 1)) & 0xBF) | 0x40));

   /// CW2  [13:8]  000000
   MT6189_WriteByte(CW(2, 1), (kal_uint8)(MT6189_ReadCache(CW(2, 1)) & 0xC0));

   /// CW2  [7:0]  N2
   MT6189_WriteByte(CW(2, 0), (kal_uint8)N2);

   /// CW3  [10:10]   1, [13:13]   1
   MT6189_WriteByte(CW(3, 1), (kal_uint8)((MT6189_ReadCache(CW(3, 1)) & 0xDB) | 0x24));

   TmpReg = MT6189_ReadCache(CW(3, 0)) & 0x1C;
#if defined   REF_CLK_32K
   TmpReg |= 0x22;
#elif defined REF_CLK_13M
   TmpReg |= 0x42;
#elif defined REF_CLK_26M
   TmpReg |= 0xC2;
#endif
   MT6189_WriteByte(CW(3, 0), TmpReg);   /// CW3

   /// CW7  [9:8]   3
   MT6189_WriteByte(CW(7, 1), (kal_uint8)((MT6189_ReadCache(CW(7, 1)) & 0xFC) | 0x03));

   /// CW25 [11:0]   Target
   MT6189_WriteByte(CW(25, 0), (kal_uint8)(Target&0xFF));
   MT6189_WriteByte(CW(25, 1), (kal_uint8)(Target>>8));

   /// CW6  [1:0]   00
   MT6189_WriteByte(CW(6, 0), (kal_uint8)(MT6189_ReadCache(CW(6, 0)) & 0xFC));

   /// CW1  [7:0]   00
   MT6189_WriteByte(CW(1, 0), 0x00);
TmpReg = MT6189_ReadCache(CW(3, 0)) & 0xE3;		//start Shorten locking time loop   
TmpReg |= 0x1C;
MT6189_WriteByte(CW(3, 0), TmpReg);

   /// CW5  [4:4]
   TmpReg = MT6189_ReadCache(CW(5, 0)) & 0xEF;
#if defined   REF_CLK_32K
   TmpReg |= 0x10;
#endif
   MT6189_WriteByte(CW(5, 0), TmpReg);   /// CW5  [4:4]

   /// CW6  [15:8]   1
   MT6189_WriteByte(CW(6, 1), 0x01);

   /// Make sure that the counting is done
   do {
      if ((WaitingCounter >> 8) == 10) {
         return KAL_FALSE;
      }
      if (((WaitingCounter++) & 0x00FF) == 0) {
         MT6189_ReadByte(CW(1, 0), &TmpReg);
      }
   } while ((TmpReg & 0x01) == 0);

   /// Reset CW1_0
   MT6189_WriteByte(CW(1, 0), 0x00);

   /// CW2  [13:8]   Ns
   MT6189_WriteByte(CW(2, 1), (kal_uint8)((MT6189_ReadCache(CW(2, 1)) & 0xC0) | (kal_uint8)Ns));

   /// CW3  [10:10]  0
   MT6189_WriteByte(CW(3, 1), (kal_uint8)(MT6189_ReadCache(CW(3, 1)) & 0xFB));

   MT6189_WriteByte(CW( 6, 1), (kal_uint8)((MT6189_ReadCache(CW( 6, 1)) & 0x0F) | 0x10));
   MT6189_WriteByte(CW( 7, 1), 0);

   MT6189_ReadByte(CW(96, 0), &TmpReg);
   if (TmpReg < 64)
      MT6189_WriteByte(CW(96, 0), (kal_uint8)(TmpReg+1));

   MT6189_ReadByte(CW(14, 0), &TmpReg);		//Open S_auto in anymode
   TmpReg&=0x6F;
   MT6189_WriteByte(CW(14, 0),(kal_uint8)(TmpReg) | 0x80);
   
   /// delay until VCO being stablized
   kal_sleep_task( VCO_LOCKING_TIME );

#if defined MT6189_DEBUG
   MT6189_DumpCtrlWord();
#endif
   return KAL_TRUE;
}

static kal_int16 MT6189_HiLoInjectOptimizer(kal_int32 CurFreq, kal_int16 SignalLevel)
{
   kal_uint16 LevelHigh, LevelLow;

   if (MT6189_SetFreq(CurFreq + 2 * PRESET_IF, HI_INJECTION) == KAL_FALSE)
      return SET_FREQ_FAIL;
   LevelHigh = MT6189_GetCurRSSI();

   if (MT6189_SetFreq(CurFreq - 2 * PRESET_IF, HI_INJECTION) == KAL_FALSE)
      return SET_FREQ_FAIL;
   LevelLow = MT6189_GetCurRSSI();

   if (LevelHigh < SignalLevel && LevelLow < SignalLevel)
      return RSSI_CHECK_FAIL;
   if (LevelHigh > LevelLow)
      return LO_INJECTION;
   else
      return HI_INJECTION;
}

static void MT6189_SetVolumeLevel(kal_uint8 level) {
	kal_uint8  TmpReg;
   /// Bug fix: Fix the mono/stereo gain issue
   const kal_uint8 prev_level = _current_level;
   	TmpReg = MT6189_ReadCache(CW(3, 0)) & 0xE3;		//end Shorten locking time loop   
	MT6189_WriteByte(CW(3, 0), TmpReg);
   ASSERT((level & 0x7F) < 13);

   _current_level = level;

   if ((KAL_FALSE == _is_fm_on) || _is_fm_mute) {
      return;
   }

   if (prev_level == 0 && level != 0) {
      MT6189_Mute(0);
   } else if (prev_level != 0 && level == 0) {
      /// This is a special case.
      /// If the level is set to zero, there is still sound leakage due to the HW design of MT6189.
      /// Thus, we use MT6189_Mute to force it keeps silent.
      /// However, the _is_fm_mute flag is not raised since it is not really a mute situation.
      MT6189_Mute(1);
      _is_fm_mute = 0;
      return;
   }

   SerialCommInit();
   {
      kal_uint8 TmpReg,TmpReg1,TmpReg2,TmpReg3;
      MT6189_ReadByte(CW(0, 0), &TmpReg2);
      MT6189_ReadByte(CW(0, 1), &TmpReg3);
      MT6189_ReadByte(CW(18, 1), &TmpReg);
      MT6189_ReadByte(CW(14, 0), &TmpReg1);
      if ((TmpReg2 == 1)&&(TmpReg3 == 1))
      {
#if !defined( MT6205B ) && !defined( MT6208 )
      if (TmpReg & 0x80) {
         /// Stereo
         TmpReg1&=0xEF;
         MT6189_WriteByte(CW(14, 0),(kal_uint8)(TmpReg1) | 0x90);
           MT6189_WriteByte(CW(16, 0), 66);
           MT6189_WriteByte(CW(16, 1), 66);
        } else {
           /// Mono
           TmpReg1&=0x6F;
           MT6189_WriteByte(CW(14, 0),TmpReg1);
           MT6189_WriteByte(CW(16, 0), 48);
           MT6189_WriteByte(CW(16, 1), 48);
        }
#else
        if (TmpReg & 0x80) {
           /// Stereo
           TmpReg1&=0xEF;
           MT6189_WriteByte(CW(14, 0),TmpReg1|0x90);
         MT6189_WriteByte(CW(16, 0), (kal_uint8)(64 | (level & 0x7F)));
         MT6189_WriteByte(CW(16, 1), (kal_uint8)(64 | (level & 0x7F)));
      } else {
         /// Mono
         TmpReg1&=0x6F;
         MT6189_WriteByte(CW(14, 0),TmpReg1);
         MT6189_WriteByte(CW(16, 0), (kal_uint8)(48 | (level & 0x7F)));
         MT6189_WriteByte(CW(16, 1), (kal_uint8)(48 | (level & 0x7F)));
        }

#endif
    }
    else
    {
#if !defined( MT6205B ) && !defined( MT6208 )
        if (TmpReg & 0x80) {
           /// Stereo
           TmpReg1&=0xEF;
           MT6189_WriteByte(CW(14, 0),(kal_uint8)(TmpReg1) | 0x90);
           MT6189_WriteByte(CW(16, 0), 14);
           MT6189_WriteByte(CW(16, 1), 14);
        } else {
           /// Mono
           TmpReg1&=0x6F;
           MT6189_WriteByte(CW(14, 0),TmpReg1);
           MT6189_WriteByte(CW(16, 0), 11);
           MT6189_WriteByte(CW(16, 1), 11);
        }
#else
        if (TmpReg & 0x80) {
           /// Stereo
           TmpReg1&=0xEF;
           MT6189_WriteByte(CW(14, 0),TmpReg1|0x90);
           MT6189_WriteByte(CW(16, 0), (kal_uint8)(level & 0x0F));
           MT6189_WriteByte(CW(16, 1), (kal_uint8)(level & 0x0F));
        } else {
           /// Mono
           TmpReg1&=0x6F;
           MT6189_WriteByte(CW(14, 0),TmpReg1);
           MT6189_WriteByte(CW(16, 0), (kal_uint8)(level & 0x0F));
           MT6189_WriteByte(CW(16, 1), (kal_uint8)(level & 0x0F));
        }
#endif
      }
   }
   SerialCommRelease();
}

static void MT6189_Mute(kal_uint8 mute) {
   kal_uint8 TmpReg;

   _is_fm_mute = (kal_bool)mute;
   if (KAL_FALSE == _is_fm_on)
      return;

   if (_current_level == 0 && mute == 0)
      return;

   SerialCommInit();

   TmpReg = MT6189_ReadCache(CW(14, 1)) & 0xF8;
#ifndef USE_MT6189_AMP
   TmpReg |= 0x03;
#endif
   if (mute != 0)
      TmpReg |= 0x07;
   MT6189_WriteByte(CW(14, 1), TmpReg);

   if (mute == 0) {
      MT6189_SetVolumeLevel(_current_level);
   } else {
      MT6189_WriteByte(CW(16, 0), 0);
      MT6189_WriteByte(CW(16, 1), 0);
   }
   SerialCommRelease();
}

/// level ranges from 0 to 12
void FMDrv_SetVolumeLevel(kal_uint8 level)
{
#ifdef MT6189_DEBUG_DUMP_LOG
   kal_sprintf((void*)_dbg_str, "\nFMDrv_SetVolumeLevel(%d);\n\0", level);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
   MT6189_SetVolumeLevel(level);
}

void FMDrv_Mute(kal_uint8 mute)
{
#ifdef MT6189_DEBUG_DUMP_LOG
   kal_sprintf((void*)_dbg_str, "\nFMDrv_Mute(%d);\n\0", mute);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
   MT6189_Mute(mute);
}

void FMDrv_PowerOnReset(void)
{
   kal_int32 fail_count;
   kal_int32 i;
   kal_uint8 tmp_reg;

#ifdef MT6189_DEBUG_DUMP_LOG
   kal_uint32 start_t, duration_t;
   _file_handle = FS_Open((const WCHAR *)_file_name, FS_CREATE);
   kal_sprintf((void*)_dbg_str, "\nFMDrv_PowerOnReset();\n\0");
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
   start_t = video_get_current_time();
#endif

   SerialCommInit();
   SerialCommCryClkOn();

   /// Power On
   for (i=0; i<POWER_ON_COMMAND_COUNT; i++) {
      MT6189_WriteByte(PowerOnSetting[i].addr, PowerOnSetting[i].value);
   }
   
#if defined MT6189_DEBUG
   MT6189_DumpCtrlWord();
#endif
   
   /// Calibrate PLL
   fail_count = 0;
   for (i=0; i<CAL_PLL_COMMAND_COUNT; i++) {
      tmp_reg = MT6189_ReadCache(CalPLLProcess[i].addr);
      tmp_reg &= CalPLLProcess[i].and;
      tmp_reg |= CalPLLProcess[i].or;
      if (KAL_FALSE == MT6189_WriteByte(CalPLLProcess[i].addr, tmp_reg)) {
         if (++fail_count == CALIBRATION_FAIL_COUNT_THRESHOLD){
            ASSERT(0);
         }
         i = 0;
      }
   }

#if defined MT6189_DEBUG
   MT6189_DumpCtrlWord();
#endif

   /// Calibrate demod I
   fail_count = 0;
   for (i=0; i<CAL_DEMOD_I_COMMAND_COUNT; i++) {
      tmp_reg = MT6189_ReadCache(CalDemodIProcess[i].addr);
      tmp_reg &= CalDemodIProcess[i].and;
      tmp_reg |= CalDemodIProcess[i].or;
      if (KAL_FALSE == MT6189_WriteByte(CalDemodIProcess[i].addr, tmp_reg)) {
         if (++fail_count == CALIBRATION_FAIL_COUNT_THRESHOLD){
            ASSERT(0);
         }
         i = 0;
      }
   }

#if defined MT6189_DEBUG
   MT6189_DumpCtrlWord();
#endif

   /// Calibrate demod Q
   fail_count = 0;
   for (i=0; i<CAL_DEMOD_Q_COMMAND_COUNT; i++) {
      tmp_reg = MT6189_ReadCache(CalDemodQProcess[i].addr);
      tmp_reg &= CalDemodQProcess[i].and;
      tmp_reg |= CalDemodQProcess[i].or;
      if (KAL_FALSE == MT6189_WriteByte(CalDemodQProcess[i].addr, tmp_reg)) {
         if (++fail_count == CALIBRATION_FAIL_COUNT_THRESHOLD){
            ASSERT(0);
         }
         i = 0;
      }
   }
   
#if defined MT6189_DEBUG
   MT6189_DumpCtrlWord();
#endif

   /// Calibrate Pilot
   {
      kal_uint8 k;
      fail_count = 0;
      for (i=0; i<CAL_PILOT_COMMAND_COUNT; i++) {
         tmp_reg = MT6189_ReadCache(CalPilotProcess[i].addr);
         tmp_reg &= CalPilotProcess[i].and;
         tmp_reg |= CalPilotProcess[i].or;
         if (KAL_FALSE == MT6189_WriteByte(CalPilotProcess[i].addr, tmp_reg)) {
            if (++fail_count == CALIBRATION_FAIL_COUNT_THRESHOLD){
               ASSERT(0);
            }
            i = 0;
         }
      }
      MT6189_ReadByte(CW( 97, 0), &tmp_reg);
      if (tmp_reg < 14)
         k = tmp_reg+1;
      else
         k = 15;

      MT6189_WriteByte(CW( 6, 1), (kal_uint8)(MT6189_ReadCache(CW( 6, 1)) & 0x0F) | 0x10);
      MT6189_WriteByte(CW( 7, 1), 0);
      MT6189_WriteByte(CW( 97, 0), k);

      tmp_reg = MT6189_ReadCache(CW( 3, 0)) & 0x1F;
#if defined   REF_CLK_32K
      tmp_reg |= 0x20;
#elif defined REF_CLK_13M
      tmp_reg |= 0x40;
#elif defined REF_CLK_26M
      tmp_reg |= 0xC0;
#endif
      MT6189_WriteByte(CW( 3, 0), tmp_reg);
      MT6189_WriteByte(CW( 3, 1), (kal_uint8)(MT6189_ReadCache(CW( 3, 1)) & 0xFB));
   }

   MT6189_WriteByte(CW(8, 1), (kal_uint8)(MT6189_ReadCache(CW(8, 1)) & 0xFE));

   MT6189_WriteByte(CW(9, 1), (kal_uint8)(MT6189_ReadCache(CW(9, 1)) & 0xFE));
   MT6189_ReadByte(CW( 97, 1), &tmp_reg);
   if(tmp_reg >= 13)
   	MT6189_WriteByte(CW( 4, 0), (kal_uint8)(MT6189_ReadCache(CW( 4, 0)) & 0x8F) | 0x30);
   else if(tmp_reg == 12)
   	MT6189_WriteByte(CW( 4, 0), (kal_uint8)(MT6189_ReadCache(CW( 4, 0)) & 0x8F) | 0x40);
   else if(tmp_reg == 11)
   	MT6189_WriteByte(CW( 4, 0), (kal_uint8)(MT6189_ReadCache(CW( 4, 0)) & 0x8F) | 0x50);
   else if(tmp_reg == 10)
   	MT6189_WriteByte(CW( 4, 0), (kal_uint8)(MT6189_ReadCache(CW( 4, 0)) & 0x8F) | 0x60);
   else if(tmp_reg <= 9)
   	MT6189_WriteByte(CW( 4, 0), (kal_uint8)(MT6189_ReadCache(CW( 4, 0)) & 0x8F) | 0x70);

#if defined MT6189_DEBUG
   MT6189_DumpCtrlWord();
#endif
   SerialCommRelease();
   _is_fm_on = KAL_TRUE;
   _current_frequency = -1;
   _rssi_threshold = FM_RADIO_INPUT_LEVEL_THRESHOLD;
   if(RSSI_offset != 0)
    _rssi_threshold = RSSI_offset;
   FMDrv_EvaluateRSSIThreshold();
#ifdef MT6189_DEBUG_DUMP_LOG
   duration_t = video_get_duration_ms(start_t);
   kal_sprintf((void*)_dbg_str, "   time cost: %d ms.\n\0", duration_t);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
}

void FMDrv_PowerOffProc(void)
{
   kal_int32 i;
   kal_uint8 tmp_reg;

#ifdef MT6189_DEBUG_DUMP_LOG
   if (_file_handle == 0)
      ASSERT(0);
   kal_sprintf((void*)_dbg_str, "\nFMDrv_PowerOffProc();\n\0");
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
   FS_Close(_file_handle);
   _file_handle = 0;
#endif

#ifdef USE_MT6189_AMP
   SwitchExtFMPath(0);
#endif

   SerialCommInit();
   for (i=0; i<POWER_OFF_COMMAND_COUNT; i++) {
      tmp_reg = MT6189_ReadCache(PowerOffProc[i].addr);
      tmp_reg &= PowerOffProc[i].and;
      tmp_reg |= PowerOffProc[i].or;
      MT6189_WriteByte(PowerOffProc[i].addr, tmp_reg);
   }
   SerialCommCryClkOff();
   SerialCommRelease();
   _is_fm_on = KAL_FALSE;
   _current_frequency = -1;
}

void FMDrv_SetFreq( kal_int16 curf )  /* input value: 875 - 1080 ( 87.5 MHz - 108.0 MHz)*/
{
   kal_int16 HiLo;
   kal_int32 curFreq = (kal_int32)curf * FM_TUNER_GRID;

#ifdef MT6189_DEBUG_DUMP_LOG
   kal_uint32 start_t, duration_t;
   kal_sprintf((void*)_dbg_str, "\nFMDrv_SetFreq(%d);\n\0", curf);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
   start_t = video_get_current_time();
#endif
   if (_is_fm_on != KAL_TRUE)
       FMDrv_PowerOnReset();
  
   MT6189_Mute(1);
   SerialCommInit();
   HiLo = MT6189_HiLoInjectOptimizer(curFreq, 0);
   if (KAL_FALSE == MT6189_SetFreq(curFreq, (kal_uint8)HiLo)) {
      ASSERT(0);
   }
   SerialCommRelease();
   MT6189_Mute(0);
 
#ifdef USE_MT6189_AMP
   SwitchExtFMPath(1);
#endif

#ifdef MT6189_DEBUG_DUMP_LOG
   duration_t = video_get_duration_ms(start_t);
   kal_sprintf((void*)_dbg_str, "   time cost: %d ms.\n\0", duration_t);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
}

kal_uint16 FMDrv_GetSigLvl( kal_int16 curf )
{
   kal_uint16 rssi;

#ifdef MT6189_DEBUG_DUMP_LOG
   kal_uint32 start_t, duration_t;
   kal_sprintf((void*)_dbg_str, "\nFMDrv_GetSigLvl(%d);\n\0", curf);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
   start_t = video_get_current_time();
#endif

   if (curf != _current_frequency)
      FMDrv_SetFreq( curf );
   SerialCommInit();
   rssi = MT6189_GetCurRSSI();
   SerialCommRelease();

#ifdef MT6189_DEBUG_DUMP_LOG
   duration_t = video_get_duration_ms(start_t);
   kal_sprintf((void*)_dbg_str, "   time cost: %d ms.\n   RSSI returned: %d.\n\0", duration_t, rssi);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
   return rssi;
}

kal_uint16 FMDrv_GetIF( kal_int16 curf)
{
   kal_uint16 IF;

#ifdef MT6189_DEBUG_DUMP_LOG
   kal_uint32 start_t, duration_t;
   kal_sprintf((void*)_dbg_str, "\nFMDrv_GetIF(%d);\n\0", curf);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
   start_t = video_get_current_time();
#endif

   if (curf != _current_frequency)
      FMDrv_SetFreq( curf );
   SerialCommInit();
   IF = MT6189_GetCurIF();
   SerialCommRelease();

#ifdef MT6189_DEBUG_DUMP_LOG
   duration_t = video_get_duration_ms(start_t);
   kal_sprintf((void*)_dbg_str, "   time cost: %d ms.\n   IF returned: %d.\n\0", duration_t, IF );
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
   return IF;
}

void FMDrv_EvaluateRSSIThreshold(void) {
   kal_int32 i = 12,j = 0;
   kal_uint8 histogram[12] = {0};
   kal_uint32 rnd;
   kal_uint32 freq = 877,tarfreq;
   kal_uint32 rssi_sum = 0;
   kal_uint32 time_start;

#ifdef MT6189_DEBUG_DUMP_LOG
   kal_uint32 start_t, duration_t;
   kal_sprintf((void*)_dbg_str, "\nFMDrv_EvaluateRSSIThreshold();\n   (freq, RSSI):\0");
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
   start_t = video_get_current_time();
#endif

        time_start = drv_get_current_time();
SerialCommInit();

        while (--i >= 0){
        kal_int16 rssi=0;
        rnd = drv_get_duration_ms(time_start);
        freq = 877;
        if (rnd > 200)
        rnd /= 4;
        freq += rnd ;
        if (freq > 1070) 
            freq = 1070;

         tarfreq = freq;
         tarfreq *= FM_TUNER_GRID;
      MT6189_SetFreq(tarfreq, LO_INJECTION);
      rssi = MT6189_GetCurRSSI();
#ifdef MT6189_DEBUG_DUMP_LOG
      kal_sprintf((void*)_dbg_str, " (%d, %d)\0", freq, rssi);
      FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
      rssi_sum += rssi;
      if (rssi >=0) {
         histogram[j++]=rssi;
      }
   }
SerialCommRelease();
   {
      kal_uint8 min = 0;
      i = 12;
      while (--i >=0) {
         if (histogram[i] <= histogram[min])
            min = i;
      }
      if(histogram[min]>=3 && histogram[min]<=4)
      {
      	_rssi_threshold = histogram[min]+2;
      }
      else if(histogram[min]==5 || histogram[min]<=2)
      {
      	_rssi_threshold = histogram[min]+1;
      }
      else
      {	
      _rssi_threshold = 7;//FM_RADIO_INPUT_LEVEL_THRESHOLD;
      }
      if (RSSI_offset != 0)
        _rssi_threshold = RSSI_offset;
      if(_rssi_threshold > 7)
      	_rssi_threshold = 7;
      /// _rssi_threshold = rssi_sum / 12;

#ifdef MT6189_DEBUG_DUMP_LOG
      duration_t = video_get_duration_ms(start_t);
      kal_sprintf((void*)_dbg_str, "\n   time cost: %d ms. RSSI threshold returned: %d.\n\0", duration_t, _rssi_threshold);
      FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
   }
}
kal_uint8 FMDrv_ValidStop(kal_int16 freq, kal_int8 signalvl, kal_bool is_step_up)
{
   kal_int32 targetFreq;
   kal_int16 IF_cnt;
   kal_int16 RSSI;

#ifdef MT6189_DEBUG_DUMP_LOG
   kal_uint32 start_t, duration_t;
   kal_sprintf((void*)_dbg_str, "\nFMDrv_ValidStop(%d, %d, %d);\n\0", freq, signalvl, is_step_up);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
   start_t = video_get_current_time();
#endif

   SerialCommInit();
   
   targetFreq = (kal_int32)freq;
   targetFreq *= FM_TUNER_GRID;

	if (targetFreq == 87500 || targetFreq == 87600 || targetFreq == 87700)
   	{
   		return 0;
   	}
   /// check RSSI at low side
   MT6189_SetFreq(targetFreq, LO_INJECTION);
#ifdef MT6189_DEBUG_DUMP_LOG
   duration_t = video_get_duration_ms(start_t);
   kal_sprintf((void*)_dbg_str, "  Set_freq_Lo time cost: %d ms.\n\0", duration_t);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif

   if ((RSSI = (kal_int16)MT6189_GetCurRSSI()) < _rssi_threshold) {
#ifdef MT6189_DEBUG_DUMP_LOG
      duration_t = video_get_duration_ms(start_t);
      kal_sprintf((void*)_dbg_str, "   time cost: %d ms.\n   #1 RSSI Check Fail! (%d < %d)\n\0", duration_t, RSSI, _rssi_threshold);
      FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
      SerialCommRelease();
      return 0;
   }

   IF_cnt = MT6189_GetCurIFCnt(IF_MEASURE_COUNT, 0);

#ifdef MT6189_DEBUG_DUMP_LOG
      duration_t = video_get_duration_ms(start_t);
      kal_sprintf((void*)_dbg_str, "  IF_RSSI check time cost: %d ms.\n   IF/RSSI Check (%d,%d)\n\0", duration_t, IF_cnt, _valid_rssi);
      FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
   if (IF_cnt > (PRESET_IF_CNT_PLUS + PRESET_IF_DELTA) ||
       IF_cnt < (PRESET_IF_CNT_PLUS - PRESET_IF_DELTA)) {
      SerialCommRelease();
#ifdef MT6189_DEBUG_DUMP_LOG
      duration_t = video_get_duration_ms(start_t);
      kal_sprintf((void*)_dbg_str, "  IF_RSSI check time cost: %d ms.\n   IF/RSSI Check Fail! (%d,%d)\n	IF range(%d,%d)\n\0", duration_t, IF_cnt, _valid_rssi,PRESET_IF_CNT_PLUS - PRESET_IF_DELTA,PRESET_IF_CNT_PLUS + PRESET_IF_DELTA);
      FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
      return 0;
   }

  
   MT6189_SetFreq(targetFreq, HI_INJECTION);

#ifdef MT6189_DEBUG_DUMP_LOG
   duration_t = video_get_duration_ms(start_t);
   kal_sprintf((void*)_dbg_str, "  Set_freq_Hi time cost: %d ms.\n\0", duration_t);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif

   if ((RSSI = (kal_int16)MT6189_GetCurRSSI()) < _rssi_threshold) {
#ifdef MT6189_DEBUG_DUMP_LOG
      duration_t = video_get_duration_ms(start_t);
      kal_sprintf((void*)_dbg_str, "   time cost: %d ms.\n   #1 RSSI Check Fail! (%d < %d)\n\0", duration_t, RSSI, _rssi_threshold);
      FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
      SerialCommRelease();
      return 0;
   }
   IF_cnt = MT6189_GetCurIFCnt(IF_MEASURE_COUNT, 0);

#ifdef MT6189_DEBUG_DUMP_LOG
      duration_t = video_get_duration_ms(start_t);
      kal_sprintf((void*)_dbg_str, "  IF_RSSI time cost: %d ms.\n   IF/RSSI Check (%d,%d)\n\0", duration_t, IF_cnt, _valid_rssi);
      FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif

   if (IF_cnt > (PRESET_IF_CNT_PLUS + PRESET_IF_DELTA) ||
       IF_cnt < (PRESET_IF_CNT_PLUS - PRESET_IF_DELTA)) {
      SerialCommRelease();
#ifdef MT6189_DEBUG_DUMP_LOG
      duration_t = video_get_duration_ms(start_t);
      kal_sprintf((void*)_dbg_str, "  IF_RSSI time cost: %d ms.\n   IF/RSSI Check Fail! (%d,%d)\n	IF range(%d,%d)\n\0", duration_t, IF_cnt, _valid_rssi,PRESET_IF_CNT_PLUS - PRESET_IF_DELTA,PRESET_IF_CNT_PLUS + PRESET_IF_DELTA);
      FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
      return 0;
   }
   if (_valid_rssi < _rssi_threshold) {
      SerialCommRelease();
      return 0;
   }

   FMDrv_SetVolumeLevel(_current_level);
   SerialCommRelease();
#ifdef MT6189_DEBUG_DUMP_LOG
      duration_t = video_get_duration_ms(start_t);
      kal_sprintf((void*)_dbg_str, "   time cost: %d ms.\n   Pass! (IF, RSSI) = (%d, %d)\n\0", duration_t, IF_cnt, RSSI);
      FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
   return 1;
}

void FMDrv_ChipInit(void)
{
   /// power down the chip
   kal_int32 i;
   SerialCommInit();
   for (i=0; i<POWER_OFF_COMMAND_COUNT; i++) {
      kal_uint8 tmp_reg = MT6189_ReadCache(PowerOffProc[i].addr);
      tmp_reg &= PowerOffProc[i].and;
      tmp_reg |= PowerOffProc[i].or;
      MT6189_WriteByte(PowerOffProc[i].addr, tmp_reg);
   }
   SerialCommCryClkOff();
   SerialCommRelease();
#ifdef USE_MT6189_AMP
   ExtSwitchInit();
#endif
}

kal_bool FMDrv_IsChipValid( void )
{
	/// anything to do?
	return KAL_TRUE;
}

kal_uint16 FMDrv_ReadByte(kal_uint8 addr)
{
	kal_uint16 Data;
	kal_uint8 TmpReg1, TmpReg2;
	MT6189_ReadByte(CW(addr, 0), &TmpReg1);
	MT6189_ReadByte(CW(addr, 1), &TmpReg2);
	Data = ((TmpReg2<<8)|TmpReg1);
	return Data;
}

kal_bool FMDrv_WriteByte(kal_uint8 addr, kal_uint16 data)
{
	kal_uint8 Data_M, Data_L;
	Data_M = data>>8;
	Data_L = data&0xFF;
	
	if((KAL_FALSE == MT6189_WriteByte(CW(addr,0), Data_L))&&(KAL_FALSE == MT6189_WriteByte(CW(addr,1), Data_M)))
		return KAL_FALSE;
	else
		return KAL_TRUE;
}

void FMDrv_SoftMuteOnOff(kal_uint8 On_Off)
{
    
}

void FMDrv_SoftMuteStage(kal_uint8 stage)
{
	
}

void FMDrv_StereoBlendStage(kal_uint8 stage)
{
	
}

kal_uint8 FMDrv_GetChipID(void)
{
	kal_uint8 ChipID;
	MT6189_ReadByte(CW(0, 1), &ChipID);
    	ChipID &= 0x07;
    	
    	return ChipID;
}

kal_uint8 FMDrv_Get_H_L_side(kal_int16 curf) /* input value: 875 - 1080 ( 87.5 MHz - 108.0 MHz)*/
{
	kal_uint8 tempreg;
	MT6189_ReadByte(CW(4, 0), &tempreg);
	if (tempreg & 0x80)
		return 1;
	else
		return 0;	
}

kal_uint8 FMDrv_Get_stereo_mono(void)
{
	kal_uint8 tempreg;
	MT6189_ReadByte(CW(14, 0), &tempreg);
	if (tempreg & 0x01)
		return 1;
	else
		return 0;	
}


#endif // defined(MT6189A1)