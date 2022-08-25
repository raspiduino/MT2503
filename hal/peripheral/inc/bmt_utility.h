/*****************************************************************************
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
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    bmt_utility.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for BMT driver and adaption.
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
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _BMT_UTILITY_H
#define _BMT_UTILITY_H

#include "drv_features.h"
#include "chr_parameter.h"
#include "dcl.h"
#include "bmt.h"
#include "bmt_chr_setting.h"


// ============================================================
// define
// ============================================================
/* Safety Timer Configuration */
#define BMT_SAFETY_TIMER_ON  			  	1
#define BMT_SAFETY_TIMER_OFF				0 

/* event scheduler timer id*/
#define BMT_ADC_TIMER_INDEX                 1		// the number has no meaning, but make sure it's unique
#define BMT_TIMER_INDEX                     2		// the number has no meaning, but make sure it's unique

/* adc channel */
#define BMT_ADC_VBAT                		0
#define BMT_ADC_VISENSE         			1
#define BMT_ADC_VBATTMP        				2
#define BMT_ADC_VCHARGER	    			3
#define BMT_ADC_MAX_CHANNEL_TOTAL   		4


#define CHARGING_TIME_UNIT 		KAL_TICKS_1_SEC

#if defined (__TRACK_CAR_DEVICE__)
//车载机
#define STOPTIMER_TIMEOUT_TICK	 (KAL_TICKS_1_MIN*10)
#elif defined (__TRACK_HAND_DEVICE__)
//手持机
#define STOPTIMER_TIMEOUT_TICK	(KAL_TICKS_1_MIN*30)
#else
#define STOPTIMER_TIMEOUT_TICK	(KAL_TICKS_1_MIN*30)
#endif /* __TRACK_CAR_DEVICE__ */

#define TOP_OFF_TIMEOUT_TICK     (KAL_TICKS_1_MIN*240) 

/* for adc query frequency */
#define KAL_TICKS_200_MSEC                 45

#define PMU_CHARGE_CURRENT_INIT      PMU_CHARGE_CURRENT_MAX
#define BMT_SYSTEM_TICK							4615	//us
#define BMT_OAM_RUN_TIME						10		//second
#define BMT_0_PERCENT_TRACKING_VOLTAGE			3400


//高低温停止充电
#if defined (__NF2319__)
#define TEMP_RECHARGE_SUPPORT
#endif

#if defined(TEMP_RECHARGE_SUPPORT)
extern kal_bool temp_error;
#define CHR_TEMPCHECK                       7//9
#endif

// ============================================================
// ENUM
// ============================================================
typedef enum{	
	USB_IN_STATE,
	USB100_STATE,
	USB500_STATE,
	USB_OUT_STATE,
	AC_IN_STATE,
	AC_OUT_STATE,
	USB_INIT_STATE
}bmt_usb_state_enum;


typedef enum{
	BMT_AUX_TIMER = 0,
#if !defined(BMT_CHARGING_DISABLE)			
	BMT_STOP_CHARGE_TIMER,
	BMT_CHARGE_TIMEOUT_TIMER,
	BMT_TOP_OFF_TIMER,
#if defined(__DRV_BMT_SW_FUEL_GAUGE__)	
	BMT_SW_FUEL_GAUGE_TIMER,
#endif	
#endif	
#if defined(__DRV_BATTERY_EXIST_DETECTION__)	
	BMT_BATTERY_DET_TIMER,
#endif	
	BMT_TIMER_INDEX_NUMBER
}bmt_timer_enum;


// ============================================================
// structure
// ============================================================
/* Customize Charging Parameters */
typedef struct {
#if !defined(BMT_CHARGING_DISABLE)	   
   kal_int32 VCHARGER_HV_HIGH;
   kal_int32 VCHARGER_HIGH;
   kal_int32 VCHARGER_LOW;
   kal_int32 ICHARGE_ON_HIGH;
   kal_int32 ICHARGE_ON_LOW;
   kal_int32 ICHARGE_OFF_HIGH;

   kal_int32 V_PRE2FAST_THRES;   
   kal_int32 V_PRE2FULL_THRES;
   kal_int32 FAST_ICHARGE_HIGHLEVEL; /* 600ma,for table search */
   kal_int32 FAST_ICHARGE_LOWLEVEL;  /* 400ma,for table search */
   kal_int32 I_TOPOFF2FAST_THRES; /* 250ma,TOPOFF->FAST */
   kal_int32 I_TOPOFF2FULL_THRES;  /* 120ma,TOPOFF->BATFULL */
#if defined(LINEAR_LI_CHARGING) || defined(PULSE_LI_CHARGING)    
   kal_int32 V_FAST2TOPOFF_THRES;
   kal_int32 V_FULL2FAST_THRES; /* BATFULL->FAST */
   kal_int32 MAX_VBAT_LI;
   kal_int32 V_PROTECT_HIGH_LI;
   kal_int32 V_PROTECT_LOW_LI;
#endif

#if defined(LINEAR_NIMH_CHARGING) || defined(PULSE_NIMH_CHARGING)  
   kal_int32 V_TEMP_FAST2FULL_THRES_NI; /* 50oC,FAST->BATFULL */
   kal_int32 V_FULL2FAST_THRES_NI;
   kal_int32 MAX_VBAT_NI;
#endif

   /*Time delay*/
   /* PRE CHARGE ,search table*/
   /*TON = 3s,TOFF=2s*/
   kal_uint32 PRE_TON;
   kal_uint32 PRE_TOFF;

/* FAST CHARGE ,search table*/
/*TON = 3s,TOFF=0s*/
   kal_uint32 TOPOFF_TON;
   kal_uint32 TOPOFF_TOFF;
#if defined(PULSE_LI_CHARGING) || defined(PULSE_NIMH_CHARGING) 
   kal_uint32 BATPOSTFULL_TWAIT_LI;
   kal_uint32 BATPOSTFULL_TON_LI;
   kal_uint32 BATPOSTFULL_TOFF_LI;
#endif 

#if defined(LINEAR_LI_CHARGING) || defined(PULSE_LI_CHARGING)  
   kal_uint32 BATFULL_TON_LI;  /*unit : second*/
   kal_uint32 BATFULL_TOFF_LI;
#else   
   kal_uint32 BATFULL_TON_NI;  /*unit : second*/
   kal_uint32 BATFULL_TOFF_NI;
#endif   
   kal_uint32 BATFULL_TOFF;
   kal_uint32 BATHOLD_OFF;   
 
   kal_uint32 CurrOffset[3];

   kal_uint32 bmt_total_charge_time;
   kal_uint8 TONOFFTABLE[6][2];

#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
   kal_int32 HIGH_VCHG_TABLE[VCHG_VOL_LEVEL][VCHG_PARAMTER_COUNT];
#endif

   kal_bool  bmt_battery_type; 	
   kal_bool	 bmt_check_charger;  
   kal_bool  bmt_check_temp;
#endif //#if !defined(BMT_CHARGING_DISABLE)	   
   kal_bool	 bmt_check_battery;    
   kal_uint32 BATT_EXIST_ADC_THRESHOLD;
} bmt_customized_struct;


typedef struct
{
   kal_uint8    TON;/*sec*/
   kal_uint8    TOFF;/*sec*/
} CHRTStruct;

typedef struct
{
   DCL_BOOL    CV_Trim_Enable;
   DCL_BOOL    OV_Trim_Enable;
   DCL_UINT8   CV_Trim_Data;
   DCL_UINT8   OV_Trim_Data;
}ChrTrimmingData;


#if defined(__DRV_BMT_SW_FUEL_GAUGE__)	
typedef struct
{
   kal_int32 hw_ocv;
   kal_int32 i1;
   kal_int32 i2;
   kal_int32 car1;
   kal_int32 car2;
   kal_int32 r1;
   kal_int32 r2;
   kal_int32 v_ocv1;
   kal_int32 v_ocv2;
   kal_int16 d0;
   kal_int16 d1;
   kal_int16 d2;
   kal_int16 d3;
   kal_int16 d4;
   kal_int16 d5;
   kal_int16 UI_SOC;   
   kal_int16 SOC;
   kal_int16 FG_columb;
}OAM_Data;

#endif
// ============================================================
// typedef
// ============================================================
typedef void (*bmt_adc)(BATPHYStruct *pBatPhysStat);
typedef void (*bmt_timer)(DCL_UINT32 *timer_period, DCL_UINT8 *timer_count);


// ============================================================
// External Variables
// ============================================================
extern BMTStruct BMT;
extern ChrTrimmingData TrimmingData;
extern bmt_adc bmt_adc_get_data;
extern bmt_timer bmt_charging_timer_set;
extern const bmt_customized_struct bmt_charging_para;
extern kal_int32 ISense_Offset;
extern kal_uint8 SaftyTimer_Flag; 
extern kal_uint32 bmt_total_charge_time;
extern kal_int32 BMT_VOL_RESULT[BMT_ADC_MAX_CHANNEL_TOTAL];
extern double BMT_ADC_RESULT[BMT_ADC_MAX_CHANNEL_TOTAL];

extern event_scheduler     *bmt_event_scheduler_ptr;
extern event_scheduler     *bmt_adc_event_scheduler_ptr;
extern PMU_CHR_CURRENT_ENUM bmt_usb_chr_current;

#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
extern kal_bool First_Time_Charge_Enable;
extern kal_uint32 bmt_high_vchg_current;
#endif

#ifdef MTK_SLEEP_ENABLE
extern kal_uint8 BMTLockARM_handle;
#endif

#ifdef __DRV_BMT_SW_POLLING_CHARGER_OV__
extern kal_timerid   bmt_sw_polling_timerId;
#endif 

#ifdef __DRV_BMT_HIGH_BATTERY_SUPPORT__
extern PMU_VOLTAGE_ENUM bmt_high_battery_cv;
extern PMU_VOLTAGE_ENUM bmt_high_battery_ov;
#endif

#if defined(__DRV_BMT_SW_FUEL_GAUGE__)	
extern OAM_Data   oam;
extern kal_uint32 last_oam_time;
extern kal_bool g_charging_full_reset_bat_meter;
extern kal_bool bat_in_recharging_state;
extern kal_bool fg_qmax_update_for_aging_flag;
extern kal_bool bat_in_recharging_state;
#endif

// ============================================================
// External function
// ============================================================
extern BMT_CHARGING_CONTROL_HANDLER bmt_charging_control_handler;
extern CHRTStruct  BATTime;
extern void bmt_timer_init(void);
extern void bmt_set_timer(bmt_timer_enum id, kal_uint32 tick);
extern void bmt_stop_timer(bmt_timer_enum timer_id);
DCL_UINT32 bmt_get_event_scheduler_timer_index(void *id);
extern void bmt_adc_init(void);
extern void BMT_Charge(kal_bool data);  /* in drv directory */
extern void bmt_initialize(void);
extern void bmt_set_chr_current(void);
extern void bmt_Modify_PowerOn_Type(kal_uint8 power_type);
extern kal_uint8 bmt_Get_PowerOn_Type(void);
extern kal_bool bmt_get_adc_channel_voltage(DCL_ADC_CHANNEL_TYPE_ENUM ch, kal_uint32 *voltage);
extern CHR_DET_TYPE_ENUM bmt_get_chr_type(void);
extern void bmt_set_chr_status(DCL_BMT_CHR_STAT status);
extern CHARGER_IN_OUT_STATUS bmt_read_chr_status(void);
extern void bmt_get_charging_ADC(void);
extern DCL_STATUS bmt_get_customized_para(BMT_CTRL_GET_CUSTOMIZED_PARA_T *GetCustomizedPara);
extern kal_bool bmt_CHR_Is_Charge_Full(BATPHYStruct *pBATPHYS);
extern kal_bool bmt_PhyCheck_BadBattContact(BATPHYStruct *BATPHYS);
extern kal_bool bmt_PhyCheck_LowCurrent(BATPHYStruct *BATPHYS);
extern kal_bool bmt_PhyCheck_DisableSafetyTimer(void);
extern kal_bool bmt_PhyCheck_EnterChargeHold(BATPHYStruct *BATPHYS);
extern kal_bool bmt_PhyCheck_HighBatTemp(BATPHYStruct *BATPHYS);
extern kal_bool bmt_PhyCheck_LowBatTemp(BATPHYStruct *BATPHYS);
extern kal_bool bmt_PhyCheck_OverCurrent(BATPHYStruct *BATPHYS);
extern kal_bool bmt_PhyCheck_VBat(BATPHYStruct *BATPHYS);
extern kal_bool bmt_PhyCheck_VCharger(BATPHYStruct *BATPHYS);
extern kal_bool bmt_PhyCheck_ReChargeTemp(BATPHYStruct *BATPHYS);
extern void bmt_CallState(kal_uint8 callState);
extern void bmt_CtrlCharge(kal_uint8 ON);
extern kal_int32 get_ISense_Offset(void);
extern kal_int32 bmt_change_VBatTmp_To_BatTmp(kal_int32 VbatTmp);
extern kal_int32 bmt_change_Voltage_To_ISense(DCL_UINT32 TransformVolt);
extern void bmt_set_chr_trimming_data(BMT_CTRL_SET_CHR_TRIMMING_DATA *rSetTrimmingData);
extern void bmt_enable_sleepmode(kal_bool enable);
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
extern void bmt_vchg_compare_and_set_current(kal_int32 cur_VCHG, kal_bool Hysteresis_Enable);
extern void bmt_high_vchg_adjust_safetytimer(kal_int32 Cur_VCHG);
#endif
#ifdef __DRV_BMT_HIGH_BATTERY_SUPPORT__
extern void bmt_set_high_battery_cv(BMT_CTRL_SET_HIGH_BATTERY_DATA *rSetHighBatteryData);
#endif

#if defined(__DRV_BATTERY_EXIST_DETECTION__)
extern kal_uint32 bmt_get_batt_exist_det_period(void);
extern void bmt_batt_exist_detection(kal_bool first_time_det);
#endif // #if defined(__DRV_BATTERY_EXIST_DETECTION__)

#if defined(__DRV_BMT_SW_FUEL_GAUGE__)	
extern void oam_init(void);
kal_int32 battery_meter_reset(kal_uint32 reset_D0);
#endif

#endif // End of #ifndef _BMT_SW_H

