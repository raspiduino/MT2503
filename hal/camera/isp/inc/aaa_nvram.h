/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  aaa_nvram.h
 *
 * Project:
 * --------
 *   MT6236
 *
 * Description:
 * ------------
 *   This file is intends for ISP 3A Interface.
 *
 * Author:
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __AAA_NVRAM_H__
#define __AAA_NVRAM_H__

#include "kal_release.h"

/*********************  AE  ******************************************/

#define MAX_ISO_LUT_NO 3
#define AE_TOTAL_GAMMA_NO 5
#define GAMMA_FAST_LUT_NO 64

enum
{
    AE_SELECT_PREIVEW=0,
    AE_SELECT_VIDEO,
    AE_SELECT_NIGHT,
    AE_SELECT_MODE_NO
};

typedef struct
{
    kal_uint16  IsoGain[MAX_ISO_LUT_NO];
    kal_uint16  IsoValue[MAX_ISO_LUT_NO];
}aeIsoLutStruct;


typedef struct
{
    kal_uint8 target_mean;
    kal_uint8 init_expo_idx;
    /* capture flare offset cal */
    kal_uint8 flare_fix_flag; 
    kal_uint8 flare_fix_offset;
    kal_uint8 flare_search_dn_ratio;
    kal_int8  flare_min_offset;
    /* preview & video gamma no */
    kal_uint8 preview_gamma_no;
    kal_uint8 preview_flare_offset;
    /* gamma mean */
    kal_uint8 indoor_outdoor_ev;
    kal_uint8 indoor_min_gamma_mean;
    kal_uint8 outdoor_max_gamma_mean;
    /* sky detection */
    kal_uint8 sky_ev;
    kal_uint8 sky_mean;
    kal_uint8 sky_max_window_mean;
    /* max under expo bin */
    kal_uint8 min_under_expo_bin;
    /* lowlight gamma limit */
    kal_uint8 lowlight_ev;
    kal_uint8 lowlight_min_target_mean;
    /* enable flag */
    kal_uint8 non_over_exposure_stretch_enabled;
    kal_uint8 full_dark_background_check_enabled;
    kal_uint8 backlight_stretch_enabled;
    /* fast gamma lut for gamma mean */
    kal_uint8 gamma_lut[AE_TOTAL_GAMMA_NO][GAMMA_FAST_LUT_NO];
    kal_uint8 grass_detect_enable;/* grass detection flag */
    kal_uint8 reserve_2;/* padding for even size */
}aeMeteringCommStruct;

typedef struct
{
    /* method select */
    kal_uint8 aeSmoothMethod;/* 0:disabled, 1:enable */
    kal_uint8 aeSmoothFilterTape;/* media filter tape no, NA for curve like enable */
    /* normal */
    kal_uint8 aeSmoothNormalLastWeight;/* 0~128 */
    kal_uint8 aeSmoothNormalMaxStep;/* 1~4, NA for curve like enable */
    /* fast */
    kal_uint8 aeSmoothFastLastWeight;/* 0~128, NA for curve like enable */
    kal_uint8 aeSmoothFastMaxStep;/* 5~40, NA for curve like enable */
    kal_uint8 aeSmoothFastMaxChangeStep;/* 5~40, NA for curve like enable */
    kal_uint8 aeSmoothFastCheckCount;/* 0~3 */
    kal_uint8 aeSmoothFastBackCheckCount;/* 0~3, NA for curve like enable */
    kal_uint8 aeSmoothFastBackCount;/* 0~3, NA for curve like enable */
    kal_uint8 aeSmoothFastTransitionCount;/* 0~3, NA for curve like enable */
    kal_uint8 aeSmoothNormalToFastTh;/* 1~4 */
    kal_uint8 aeSmoothFastToNormalTh;/* 5~15*/
    /* 6328 new smooth mode */
    kal_uint8 aeSmoothFastSmoothEnable;/* 0: disable, 1:enable */
    kal_uint8 aeSmoothNormalSpeedEnable;/* 0: disable, 1:enable */
    kal_uint8 aeSmoothMovingStopCheckEnable;/* 0: disable, 1:enable */
    kal_uint8 aeSmoothMovingStopNormalCheckCount;/* 1~4 check count */
    kal_uint8 aeSmoothMovingStopFastCheckCount;/* 1~4 check count */
    kal_uint8 reserve_1;/* padding for even size */
    kal_uint8 reserve_2;/* padding for even size */
}aeSmoothModeStruct;

typedef struct
{
    aeIsoLutStruct aeIsoPara;/* 2*6=12 */
    aeMeteringCommStruct aeMeteringComm;/* 22+5*64=342 */
    aeSmoothModeStruct ae_smooth[AE_SELECT_MODE_NO];/* 3*20=60 */
    kal_uint8 reserve_1[68];/* 480-12-340-60=68 */
}nvram_ae_para_struct, NVRAM_AE_PARA_STRUCT;

/*********************  AWB ******************************************/

typedef struct
{
    kal_uint32    reg[30];//0x280~0x2F8
    kal_uint16    LightSource[7][4];	/* { Rgain, GRgain, Bgain, GBgain} */
	                                                        /*A, TL84,CWF,D65,D75,Flash,Manual*/
    kal_uint8    AwbSpeedFast;    /*awb converge ratio in 1 step in fast state
	                                                      when gain difference is higher than AWB_thres_fast, 128 base*/
    kal_uint8    AwbSpeedMid;     /*awb converge ratio in 1 step in fast state
	                                                      when gain difference is between AWB_thres_mid and AWB_thres_fast, 128 base*/
    kal_uint8    AwbSpeedSlow;    /*awb converge ratio in 1 step in fast state
	                                                      when gain difference is smaller than AWB_thres_mid , 128 base*/
    kal_uint8    AwbThresFast;      /*gain difference for AWB_speed_fast*/
    kal_uint8    AwbThresMid;      /*gain difference for AWB_speed_mid*/
    kal_uint8    AwbPreference[3][3];  /*A, TL8, Daylight; RcompRatio,GcompRatio,BcompRatio*/
    kal_uint8    ChangeStateGainThr;  /*gain difference between target & current to enter change state*/
    kal_uint8    ChangeStateFrameThr; /*frame number to enter change state when gain difference is over threshold*/
    kal_uint8    StableStateGainThr;  /*gain difference between target & current to enter stable state*/
    kal_uint8    StableStateFrameThr;  /*frame number to enter stable state when gain difference is smaller than threshold*/
    kal_uint8    FinetuneStateGainThr; /*gain difference between target & current to enter finetune state*/
    kal_uint8    FinetuneStateFrameThr;/*frame number to enter finetuen state when gain difference is over threshold*/
    kal_uint8    AwbSmFrameNum;  /*Frame number used to smooth current target gain*/
    kal_uint8    AwbPreferEn;    /*Enable awb preference**/
    kal_uint8    MwbFixedWinEn;  /*0: fixed gain for MWB, 1:fixed window for MWB*/
    kal_uint8    ALightMethod;//0: Use TL84, 1: Use Small A box, 2: Use Full A box
    kal_uint8    AwbSmallAWinEn; //use small a window
    kal_uint8    AwbSmallTl84WinEn; //use small TL84 window
    kal_uint8    AwbSmallCwfWinEn; //use small CWF window
    kal_uint8    AwbSmallDWinEn; //use small Day window
    kal_uint8    AwbCaptureFastConvergeEn;//capture fast converge
    kal_uint8    Reserved[25];
}AWB_PARA_STRUCT;

typedef struct
{
        kal_uint8       LightSource[3][3][3];
        kal_uint8       CcmPreferEn;
}CCM_PARA_STRUCT;

typedef struct
{
	AWB_PARA_STRUCT    AWB;
	CCM_PARA_STRUCT    CCM;
}NVRAM_AWB_PARA_STRUCT;

/*********************  AF  ******************************************/
#define	AF_MAX_TABLE_NO			(24)
#define	AF_MAX_DEF_PATH_NO		(3)	// AF PATH NO in NVRAM
#define AF_MZ_DOF_MAX_NO 		(8)
#define AF_MZ_DOF_LUT_IDX_NO 	(3)

typedef enum {
	SEARCH_OPTION_NONE 			= 0x0000,
	SEARCH_OPTION_LOCALMAX 		= 0x0001,
	SEARCH_OPTION_NOFOCUS 		= 0x0002,
	SEARCH_OPTION_SWITCHTOMACRO	= 0x0004,		
	SEARCH_OPTION_HYSTERESIS	= 0x0008,	
	SEARCH_OPTION_WAIT_STABLE	= 0x0010,		
	SEARCH_OPTION_STARTUP_POS	= 0x0020,	
	SEARCH_OPTION_LENS_HOLD		= 0x0040
} AF_SEARCH_OPTION_ENUM;

typedef enum
{
	AF_PARAM_VERSION=0,
	AF_PARAM_PEAK_THRE,
	AF_PARAM_NOFOCUS_THRE,
	AF_PARAM_STOP_THRE,
	AF_PARAM_HYSTERESIS_THRE,
	AF_PARAM_HYSTERESIS_DIR,
	AF_PARAM_SLOW_MOVE_MAX_STEP,
	AF_PARAM_SLOW_BACK_MAX_STEP,	
	AF_PARAM_WAIT_STABLE_THRE2,	
	AF_PARAM_WAIT_STABLE_THRE3,		
	AF_PARAM_STARTUP_POS,
	AF_PARAM_STARTUP_WAIT_FRAME,	
	AF_PARAM_SEARCH_OPTION,	
	// for continuous AF	
	AF_PARAM_CONT_DD_STEP_RATIO,	
	AF_PARAM_CONT_DD_RANGE_THRE,		
	AF_PARAM_CONT_FV_DELTA,	//0828NEW	
	AF_PARAM_CONT_FV_BLUR,	//0828NEW			
	AF_PARAM_CONT_FV_DELTA_HIGH,	
	AF_PARAM_CONT_FV_DELTA_LOW,		
	AF_PARAM_CONT_AE_DELTA_HIGH,	
	AF_PARAM_CONT_AE_DELTA_LOW,		
	AF_PARAM_CONT_WAIT_STABLE_AE,	
	AF_PARAM_CONT_WAIT_STABLE_FV_HIGH,		
	AF_PARAM_CONT_WAIT_STABLE_FV_LOW,			
	AF_PARAM_CONT_WAIT_STABLE_FREEZE,
	AF_PARAM_CONT_JUMP_COUNT_THRE,	
	AF_PARAM_CONT_WAIT_STABLE_MAX,
	// for MZ AF	
	AF_PARAM_MZ_MAX_INF_DOF,
	AF_PARAM_MZ_MAX_MACRO_DOF,
	// for continuous AF append
	AF_PARAM_CONT_PAN_LUMA_DELTA, // 0832NEW
	AF_PARAM_CONT_PAN_HOLD_FRAME, // 0832NEW
	AF_PARAM_CONT_PAN_OVER_SPEEDUP, // 0832NEW
	AF_PARAM_CONT_WINDOW_CONFIG_X,// 0832NEW
	AF_PARAM_CONT_WINDOW_CONFIG_Y,// 0832NEW
	AF_PARAM_CONT_STOP_SEARCH_CONFIG,// 0836NEW
	// for single/multi window AF append
	AF_PARAM_WIN_SIZE_LEVEL_CONFIG,// 0836NEW
	// END TAG
	AF_PARAM_END_TAG,	
	AF_PARAM_MAX_NO	= 38
} AF_PARAM_ENUM;

typedef struct {
	kal_uint16		af_calibration_offset;
	kal_uint16		af_calibration_data;	
}AF_NVRAM_LENS_CALI_STRUCT, *P_AF_NVRAM_LENS_CALI_STRUCT;

typedef struct {
	kal_uint16		af_table_num;	
	kal_uint16		af_home_idx;
	kal_uint16		af_macro_idx;		
	kal_uint16		af_infinite_idx;		
	kal_uint16		af_hyper_pos;		
	kal_uint16		af_me_home_pos;			
	kal_uint16		af_me_macro_pos;		
	kal_uint16		af_filter_type;			
}AF_TABLE_RANGE_STRUCT, *P_AF_TABLE_RANGE_STRUCT;

typedef struct {
	kal_uint16	pos;	
	kal_uint16	distance;
}AF_TABLE_STEP_STRUCT, *P_AF_TABLE_STEP_STRUCT;

typedef struct {
	AF_TABLE_RANGE_STRUCT	table_range;	
	AF_TABLE_STEP_STRUCT	table_step[AF_MAX_TABLE_NO];
}AF_NVRAM_TABLE_INFO_STRUCT, *P_AF_NVRAM_TABLE_INFO_STRUCT;

typedef struct
{
   	kal_uint16 dof_lut_size;
   	kal_uint16 dof_lut[AF_MZ_DOF_MAX_NO][AF_MZ_DOF_LUT_IDX_NO];/* 0: step, 1:macro, 2:inf */
}AF_NVRAM_MZ_DOF_STRUCT, *P_AF_NVRAM_MZ_DOF_STRUCT;

typedef struct
{
	AF_NVRAM_LENS_CALI_STRUCT 	lens_calibration;			// 1 words
	AF_NVRAM_TABLE_INFO_STRUCT		table_info[AF_MAX_DEF_PATH_NO]; 	// provide 4+24 words * 3 = 84 words
	AF_NVRAM_MZ_DOF_STRUCT	dof_table_info;/* 2+3*2*8 = 50 bytes = 25 words */
	kal_uint16						para_info[AF_PARAM_MAX_NO];	// 32/2 = 16 words + 3 words
}NVRAM_AF_PARA_STRUCT, AF_NVRAM_PARA_STRUCT, *P_AF_NVRAM_PARA_STRUCT;

#endif /* __AAA_NVRAM_H__ */

