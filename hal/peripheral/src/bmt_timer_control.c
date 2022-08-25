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
 *    bmt_timer_control.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for BMT timer related control function. Including timer start and timer expire
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include	"drv_features.h"
#include    "drv_comm.h"
#include	"bmt_trc.h"
	 // For RHR ADD Usage
#include	"stack_config.h"
#include	"drvpdn.h"
#include	"kal_trace.h"
#include    "chr_parameter.h"
#include    "bmt_utility.h"
#include    "dcl.h"
#include    "kal_general_types.h"
#include    "kal_public_api.h"
#include    "multiboot_config.h"
#include    "adc_sw.h"
#include    "adcsche.h"
#include    "drvsignals.h"
#include    "bmt_sw_chip_setting.h"
#include    "bmt_chr_setting.h"
#include    "adc_msg_handle.h"
#if defined(PULSE_LI_CHARGING)  
#include	 "bmt_pulse_li.h"
#elif defined(LINEAR_LI_CHARGING)
#include 	"bmt_linear_li.h"
#endif

#if defined(__GPS_TRACK__)
#include "track_drv_pmu.h"
#include "Adc_channel.h"
#include "ell_os.h"
#endif /* __GPS_TRACK__ */


#if !defined(BMT_CHARGING_DISABLE)
// ============================================================ //
//define
// ============================================================ //
/* Counts of ADC Measurement */
#define BMT_EVALUATE_VALUE		10
#define VCHG_DIFF_THRESHOLD 300000 // 300mV

#ifdef TEMP_RECHARGE_SUPPORT
kal_bool temp_error = KAL_FALSE;
extern void BMT_CheckTemp(void);
#endif


// ============================================================ //
//global variable
// ============================================================ //
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
static kal_int32 VCharge_Total = 0;
#endif
// ============================================================ //
// function prototype
// ============================================================ //
#if defined(__BMT_ON_STATE_CHECK__) || defined(__BMT_OFF_STATE_CHECK__) 
static void bmt_ChrErrorCheck(BATPHYStruct *BATPHYS);
#endif

// ============================================================ //
//extern variable
// ============================================================ //


// ============================================================ //
//extern function
// ============================================================ //
extern void bmt_sendMes2UEM(BMT_CHR_STAT status);


// ============================================================ //
#if defined(__BMT_ON_STATE_CHECK__)
 /*
 * FUNCTION
 *		bmt_frequently_check_on_state
 *
 * DESCRIPTION															 
 *		 This function is called to check whether "on state" need to be check frequently
 *
 * CALLS  
 *
 * PARAMETERS
 *		None
 *	 
 * RETURNS
 *		KAL_TRUE: need check in this state
 *		KAL_FALSE: not need
 *
 * GLOBALS AFFECTED
 *	   None
 */
static kal_bool bmt_frequently_check_on_state(void)
 {
	 if(BMT.pmictrl_state == PMIC_CHARGEON)
	 {
		 if((BMT.bat_state == CHR_PRE)	|| 
			 (BMT.bat_state == CHR_FAST) || 
			 ((BMT.call_state != talk_mode) && (BMT.bat_state == CHR_TOPOFF)) ||
			 ((BMT.call_state != talk_mode) && (BMT.bat_state == CHR_POSTFULL)) ||
			 ((BMT.call_state != talk_mode) && (BMT.bat_state == CHR_BATFULL)) )
		 {
			 return KAL_TRUE;
		 }
	 }
	 return KAL_FALSE;
 }
 
 
 
 /*
 * FUNCTION
 *		bmt_get_on_count
 *
 * DESCRIPTION															 
 *		 This function is called to get the different count in each on state
 *
 * CALLS  
 *
 * PARAMETERS
 *		None
 *	 
 * RETURNS
 *		kal_uint32: check count of current on state. 
 *
 * GLOBALS AFFECTED
 *	   None
 */
 static kal_uint32 bmt_get_on_count(void)
 {
	kal_uint32 current_on_count = 0;
	switch(BMT.bat_state)
	{
	   case  CHR_PRE:
		 current_on_count = bmt_charging_para.PRE_TON*KAL_TICKS_1_SEC/KAL_TICKS_200_MSEC+1;
		 break;
	   case  CHR_FAST:
		 if(0 == BATTime.TON)
			 BATTime.TON = bmt_charging_para.TONOFFTABLE[0][CHRTON];
		 current_on_count = BATTime.TON*KAL_TICKS_1_SEC/KAL_TICKS_200_MSEC+1;
		 break;
	   case  CHR_TOPOFF:
		 current_on_count = bmt_charging_para.TOPOFF_TON*KAL_TICKS_1_SEC/KAL_TICKS_200_MSEC+1;
		 break;
#if defined(PULSE_LI_CHARGING) || defined(PULSE_NIMH_CHARGING)  
	   case  CHR_POSTFULL:
		 current_on_count = bmt_charging_para.BATPOSTFULL_TON_LI*KAL_TICKS_1_SEC/KAL_TICKS_200_MSEC+1;
		 break;
#endif
	   case  CHR_BATFULL:
		 current_on_count = bmt_charging_para.BATFULL_TON_LI*KAL_TICKS_1_SEC/KAL_TICKS_200_MSEC+1;
		 break;
	   default:
		 current_on_count = 1;
		 break;
	}
	drv_trace1(TRACE_GROUP_10, BMT_ERRORCHECK_ON_COUNT_TRC, current_on_count);	 
	return current_on_count;
 }
 
 
 
 /*
 * FUNCTION
 *		bmt_finish_check_on_state
 *
 * DESCRIPTION															 
 *		 This function is called to check whether "on state check" already finish
 *
 * CALLS  
 *
 * PARAMETERS
 *		None
 *	 
 * RETURNS
 *		KAL_TRUE: finish
 *		KAL_FALSE: not finish
 *
 * GLOBALS AFFECTED
 *	   None
 */
 static kal_bool bmt_finish_check_on_state(void)
 {
	static kal_uint8  pre_bat_state = 0xFF;
	static kal_uint32 state_counter = 0; //the counter during this ON state
	static kal_uint32 bmt_on_count	= 0; //the count of this ON state. (how many "200 ms")

    bmt_on_count = bmt_get_on_count();
	if(BMT.bat_state != pre_bat_state) //change state
	{
	   pre_bat_state = BMT.bat_state;
	   state_counter = 0;
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)      
	   VCharge_Total = 0;
	   drv_trace0(TRACE_GROUP_9, BMT_HIGH_VCHG_MAX_RESET_TO_ZERO_TRC); 
#endif      	  
	}
	
	if(state_counter == bmt_on_count)
	{
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT) 
	   Pre_VCharge_AVG = VCharge_Total / bmt_on_count;
	   bmt_vchg_compare_and_set_current(VCharge_Total / bmt_on_count, KAL_TRUE);
	   drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_AVERAGE_TRC, VCharge_Total / bmt_on_count); 
	   VCharge_Total = 0;
	   Cur_VCharge_MAX = 0;
	   drv_trace0(TRACE_GROUP_9, BMT_HIGH_VCHG_MAX_RESET_TO_ZERO_TRC);		 
#endif    
	
	   state_counter = 0;
	   return KAL_TRUE;
	}
	else
	{
	   state_counter++;
	   return KAL_FALSE;
	}
 }
#endif
 
#if defined(__BMT_OFF_STATE_CHECK__)
 /*
 * FUNCTION
 *		bmt_frequently_check_off_state
 *
 * DESCRIPTION															 
 *		 This function is called to check whether "off state" need to be check frequently
 *
 * CALLS  
 *
 * PARAMETERS
 *		None
 *	 
 * RETURNS
 *		KAL_TRUE: need check in this state
 *		KAL_FALSE: not need
 *
 * GLOBALS AFFECTED
 *	   None
 */
 static kal_bool bmt_frequently_check_off_state(void)
 {
	 if(BMT.pmictrl_state == PMIC_CHARGEOFF)
	 {
		 if(BMT.bat_state == CHR_PRE)
		 {
			 return KAL_TRUE;
		 }
	 }
	 return KAL_FALSE;
 }
 
 
 /*
 * FUNCTION
 *		bmt_get_off_count
 *
 * DESCRIPTION															 
 *		 This function is called to get the different count in each off state
 *
 * CALLS  
 *
 * PARAMETERS
 *		None
 *	 
 * RETURNS
 *		kal_uint32: check count of current off state. 
 *
 * GLOBALS AFFECTED
 *	   None
 */
 static kal_uint32 bmt_get_off_count(void)
 {
	kal_uint32 current_off_count = 0;
	switch(BMT.bat_state)
	{
	   case  CHR_PRE:
		 current_off_count = bmt_charging_para.PRE_TOFF*KAL_TICKS_1_SEC/KAL_TICKS_200_MSEC+1;
		 break;
	   default:
		 current_off_count = 1;
		 break;
	}
	drv_trace1(TRACE_GROUP_10, BMT_ERRORCHECK_OFF_COUNT_TRC, current_off_count);
	return current_off_count;
 }
 
 
 /*
 * FUNCTION
 *		bmt_finish_check_on_state
 *
 * DESCRIPTION															 
 *		 This function is called to check whether "on state check" already finish
 *
 * CALLS  
 *
 * PARAMETERS
 *		None
 *	 
 * RETURNS
 *		KAL_TRUE: finish
 *		KAL_FALSE: not finish
 *
 * GLOBALS AFFECTED
 *	   None
 */
 static kal_bool bmt_finish_check_off_state(void)
 {
	static kal_uint8  pre_bat_state = 0xFF;
	static kal_uint32 state_counter = 0; //the counter during this Off state
	static kal_uint32 bmt_off_count  = 0; //the count of this Off state. (how many "200 ms")

	bmt_off_count = bmt_get_off_count();
	if(BMT.bat_state != pre_bat_state) //change state
	{
	   pre_bat_state = BMT.bat_state;
	   state_counter = 0;
	}
	
	if(state_counter == bmt_off_count)
	{
	   state_counter = 0;
	   return KAL_TRUE;
	}
	else
	{
	   state_counter++;
	   return KAL_FALSE;
	}
 }
#endif


 /*
* FUNCTION
*		bmt_ObtainBMTPhystate
*
* DESCRIPTION																			  
*		This function is used to obtain the ADC measure result.
*	  Average the received Phy. data
*
* CALLS  
*
* PARAMETERS
*		Data: None
*	
* RETURNS
*		None
*
* GLOBALS AFFECTED
*	  None
*/
kal_bool bmt_ObtainBMTPhystate(BATPHYStruct *BATPHYS)
{
	drv_trace0(TRACE_GROUP_10, BMT_OBTAIN_PHY_STAT_TRC);

	bmt_adc_get_data(BATPHYS);
	
	if ((BMT.pmictrl_state == PMIC_CHARGEOFF)  ||
		(BMT.pmictrl_state == PMIC_CHARGEON ) &&
		( (BMT.bat_state == CHR_TOPOFF) || (BMT.bat_state == CHR_BATFULL) ))
	{
		bmt_set_charge_off_vbat_status(BATPHYS->VBAT,BMT_ADC_RESULT[BMT_ADC_VBAT]);
	}
	return KAL_TRUE;
}

 
 /*
 * FUNCTION
 *		 bmt_PhyCheck
 *
 * DESCRIPTION																			   
 *		 This function is to check whether the measured physical
 *	   parameters is over the physical limitation.
 *
 * CALLS  
 *
 * PARAMETERS
 *		 Data: None
 *	 
 * RETURNS
 *		 BATPHYS: measured physical parameters
 *
 * GLOBALS AFFECTED
 *	   None
 */
static void bmt_PhyCheck(BATPHYStruct *BATPHYS)
 {
	 if (bmt_charging_para.bmt_check_charger)
	 {
		 if (bmt_PhyCheck_VCharger(BATPHYS) == KAL_FALSE)
		 {
			 drv_trace0(TRACE_ERROR, BMT_INVALID_CHARGER_TRC);
			 bmt_sendMes2UEM(BMT_INVALID_CHARGER);
			 BMT.bat_state = CHR_ERROR;
			 return;
		 }
	 }
	 
#if defined (__BMT_NO_ISENSE_RESISTOR__) || defined (__CHARGE_NOT_MTK__)
/*充电电流无法检测       --    chengjun  2016-07-05*/
#else
/*充电电流特别大或者小的，需要修改有效充电范围和充满临界电流值，在chr_patam配置       --    chengjun  2016-12-07*/
	 if (bmt_PhyCheck_OverCurrent(BATPHYS) == KAL_FALSE)
	 {
		 drv_trace0(TRACE_ERROR, BMT_ICHARGE_OVER_TRC);
		 bmt_sendMes2UEM(BMT_OVERCHARGECURRENT);
		 BMT.bat_state = CHR_ERROR;
		 return;
	 }

	if (bmt_PhyCheck_LowCurrent(BATPHYS) == KAL_FALSE)
	{
		drv_trace0(TRACE_GROUP_10, BMT_ICHARGE_LOW_TRC);
		bmt_sendMes2UEM(BMT_LOWCHARGECURRENT);
		BMT.bat_state = CHR_ERROR;
		return;
	}
	
#endif // #ifndef __BMT_NO_ISENSE_RESISTOR__
	 
	 if (bmt_PhyCheck_VBat(BATPHYS) == KAL_FALSE)
	 {
		 drv_trace0(TRACE_ERROR, BMT_VBAT_OVER_TRC);
		 bmt_sendMes2UEM(BMT_OVERVOLPROTECT);
		 BMT.bat_state = CHR_ERROR;
		 return;
	 }
	 
	 if (bmt_charging_para.bmt_check_temp)
	 {
		 if (bmt_PhyCheck_HighBatTemp(BATPHYS) == KAL_FALSE)
		 {
			 drv_trace0(TRACE_ERROR, BMT_VTEMP_OVER_TRC);
			 bmt_sendMes2UEM(BMT_OVERBATTEMP);
#ifdef TEMP_RECHARGE_SUPPORT
			 BMT.bat_state = CHR_TEMPCHECK;
#else
			 BMT.bat_state = CHR_ERROR;
#endif

			 return;
		 }
		 
		 if (bmt_PhyCheck_LowBatTemp(BATPHYS) == KAL_FALSE)
		 {
			 drv_trace0(TRACE_ERROR, BMT_VTEMP_LOW_TRC);
			 bmt_sendMes2UEM(BMT_LOWBATTEMP);
#ifdef TEMP_RECHARGE_SUPPORT
			 BMT.bat_state = CHR_TEMPCHECK;
#else
			 BMT.bat_state = CHR_ERROR;
#endif

			 return;
		 }
		 
		 if (bmt_PhyCheck_BadBattContact(BATPHYS) == KAL_FALSE)
		 {
			 bmt_sendMes2UEM(BMT_BATTERY_BAD_CONTACT);
			 BMT.bat_state = CHR_ERROR;
			 return;
		 }
	 }		 
	 
	 
	 if (bmt_PhyCheck_DisableSafetyTimer())
	 {
		 // We should disable safety timer
		 if (SaftyTimer_Flag == BMT_SAFETY_TIMER_ON)
		 {	 
			 bmt_stop_timer(BMT_CHARGE_TIMEOUT_TIMER);
			 SaftyTimer_Flag = BMT_SAFETY_TIMER_OFF; 
		 }	
	 }
	 else
	 {
		 // We should enable safety timer
		 if (SaftyTimer_Flag == BMT_SAFETY_TIMER_OFF)
		 {	 

#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
			 bmt_high_vchg_adjust_safetytimer(BATPHYS->VCHARGER);						 
#endif
			 bmt_set_timer(BMT_CHARGE_TIMEOUT_TIMER,KAL_TICKS_1_MIN*bmt_total_charge_time);
			 drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_START_TRC, bmt_total_charge_time);

			 SaftyTimer_Flag = BMT_SAFETY_TIMER_ON; 
		 }	 
	 }
	 
	 // Decide whether to enter HOLD state or NOT
	 if (bmt_PhyCheck_EnterChargeHold(BATPHYS) == KAL_TRUE)
	 {
		 drv_trace0(TRACE_GROUP_10, BMT_CHR_HOLD_TRC);
		 BMT.bat_state = CHR_HOLD;
		 return;
	 }
	 
 }


  /*
  * FUNCTION
  * 	  bmt_measure_done
  *
  * DESCRIPTION 																			
  * 	  This function is called when all parameters that charge algorithm needs
  *  are all measured done.
  *
  * CALLS  
  *
  * PARAMETERS
  * 	  None
  *   
  * RETURNS
  * 	  None
  *
  * GLOBALS AFFECTED
  * 	None
  */
  /*total channel measure done*/
 static void bmt_measure_done(void)
  {
	   BATPHYStruct BATPHYS;
	   bmt_ObtainBMTPhystate(&BATPHYS);
	   bmt_PhyCheck(&BATPHYS);
#if defined(__GPS_TRACK__)
    track_bmt_update_status(&BATPHYS);
#endif /* __GPS_TRACK__ */

#if defined(__BMT_ON_STATE_CHECK__) 
	  if(bmt_frequently_check_on_state())
	  {
		  if(bmt_finish_check_on_state()) 
		  {
			  chr_algorithm_control_handler(BMT_CHARGING_ALGO_CMD_CHANGE_STATE, &BATPHYS);
		  }
		  else //check the error condition on CC
		  {
			  drv_trace0(TRACE_GROUP_10, BMT_ERRORCHECK_AT_CHARGE_ON_TRC);		   
			  bmt_ChrErrorCheck(&BATPHYS);
		  }
 
		  return;
	  }
#endif
 
#if defined(__BMT_OFF_STATE_CHECK__)
	  if(bmt_frequently_check_off_state())
	  {
		  if(bmt_finish_check_off_state()) 
		  {
			 chr_algorithm_control_handler(BMT_CHARGING_ALGO_CMD_CHANGE_STATE, &BATPHYS);
		  }
		  else //check the error condition on CC
		  {
			  drv_trace0(TRACE_GROUP_10, BMT_ERRORCHECK_AT_CHARGE_OFF_TRC);   
			  bmt_ChrErrorCheck(&BATPHYS);
		  }
		  return;
	  }
#endif 
	 chr_algorithm_control_handler(BMT_CHARGING_ALGO_CMD_CHANGE_STATE, &BATPHYS);
 
		 
  }
 
  
  /*
  * FUNCTION
  * 	 bmt_measure_complete
  *
  * DESCRIPTION 														  
  * 	  This function is the callback function when vbat is measured done.
  *
  * CALLS  
  *
  * PARAMETERS
  * 	 handle: logical channel id.
  *   
  * RETURNS
  * 	 None
  *
  * GLOBALS AFFECTED
  * 	None
  */
  void bmt_measure_complete(DCL_INT32 handle, DCL_INT32 *volt_array_result, DCL_DOUBLE *adc_array_result)
  {
	  DCL_STATUS adc_status;
	  kal_uint32 i;
 
	  adc_status = DclSADC_Control(handle, ADC_CMD_STOP_MEASURE, NULL);
	  if(adc_status != STATUS_OK)
	  {
		  ASSERT(0);
	  }   
  
	  for(i=0;i<BMT_ADC_MAX_CHANNEL_TOTAL;i++)
	  {
		  BMT_VOL_RESULT[i] = *(volt_array_result+i);
		  BMT_ADC_RESULT[i] = *(adc_array_result+i);
	  }
	 
	  bmt_measure_done();
  }
 
 
   /*
  * FUNCTION
  * 	 bmt_timer_config
  *
  * DESCRIPTION 														  
  * 	  This function is to configure the measure timer
  *
  * CALLS  
  *
  * PARAMETERS
  * 	 time: on/off time interval. (1 tick = 4.615ms)
  *   
  * RETURNS
  * 	 None
  *
  * GLOBALS AFFECTED
  * 	None
  */
  void bmt_timer_config(kal_uint32 time) /*time unit is second*/
  {
	 kal_uint32  adc_bmt_tick;
	   
	 DCL_UINT32  period;  
	 DCL_UINT8	 EvaluateCount;   
 
 
#if defined(__BMT_ON_STATE_CHECK__)   
	 if(bmt_frequently_check_on_state())
	 {
		time = KAL_TICKS_200_MSEC; // 200ms/4.615 ~= 45 frames
	 }
#endif
 
#if defined(__BMT_OFF_STATE_CHECK__)
	 if(bmt_frequently_check_off_state())
	 {
		time = KAL_TICKS_200_MSEC; // 200ms/4.615 ~= 45 frames	  
	 }
#endif
 
	  adc_bmt_tick = (kal_uint32)(time/BMT_EVALUATE_VALUE);
	  adc_bmt_tick++;
	  
	  period = adc_bmt_tick;
	  EvaluateCount = BMT_EVALUATE_VALUE + 1;	
 
	  bmt_charging_timer_set(&period, &EvaluateCount);
  }


 /*
 * FUNCTION
 *		bmt_ChrErrorCheck
 *
 * DESCRIPTION															 
 *		 This function is called when BMT charge module 
 *	   is at CHR_HOLD state.
 *
 * CALLS  
 *
 * PARAMETERS
 *		None
 *	 
 * RETURNS
 *		None
 *
 * GLOBALS AFFECTED
 *	   None
 */
#if defined(__BMT_ON_STATE_CHECK__) || defined(__BMT_OFF_STATE_CHECK__) 
 static void bmt_ChrErrorCheck(BATPHYStruct *BATPHYS)
 {
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
	 static kal_uint32 pre_vchg_current = 0;
	 kal_uint32 cust_usb_charger_current;
	 CHR_DET_TYPE_ENUM chr_type;

	 chr_type = bmt_get_chr_type();		
#endif
 
 
	drv_trace0(TRACE_GROUP_10, BMT_ERROR_CHECK_TRC);
 
#if defined(DRV_BMT_HW_PRECC_WORKAROUND)
			 if(KAL_TRUE == SW_Workaround_Flag) 	 // True : VBAT < 3.4V
			 {
				 if(KAL_FALSE == PreCC_Chr_Plugout_Check(BATPHYS))
					  bmt_timer_config(KAL_TICKS_200_MSEC); //45 frames ~= 200ms
				 return;  
			 }	 
#endif
 
 
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT) 
	   VCharge_Total += BATPHYS->VCHARGER;
	   drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_CUR_VCHG_MAX_TRC, Cur_VCharge_MAX);
	   drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_VCHG_DIFF_TRC, BATPHYS->VCHARGER - Pre_VCharge_AVG);
	   if(((BATPHYS->VCHARGER - Pre_VCharge_AVG) > VCHG_DIFF_THRESHOLD) && BATPHYS->VCHARGER > Cur_VCharge_MAX && 
		 ((chr_type != PW_USB_CHR) && (chr_type != PW_USB_CHARGING_HOST_CHR)) && BMT.bat_state != CHR_PRE)
	   {				  
		   pre_vchg_current = bmt_high_vchg_current;
		   bmt_vchg_compare_and_set_current(BATPHYS->VCHARGER, KAL_FALSE);
 
			 if(chr_type == PW_AC_NON_STD_CHR)
			 {
				 cust_usb_charger_current = CHR_NON_AC_CHARGE_CURRENT;
				 if(bmt_high_vchg_current > cust_usb_charger_current)
				 {
					 bmt_high_vchg_current = cust_usb_charger_current;
					 drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_SET_USB_CHARGE_CURRENT_TRC, cust_usb_charger_current);
				 }
			 }
 
		   if(pre_vchg_current != bmt_high_vchg_current)
		   {
   		     bmt_charging_control_handler(BMT_CHARGING_CMD_SET_CHARGING_CURRENT, &bmt_high_vchg_current);
		   	 {
				 DCL_BOOL ChrCtrl;

			   	 // make sure the set current work
				 ChrCtrl = KAL_FALSE;
				 bmt_charging_control_handler(BMT_CHARGING_CMD_CHARGING_ENABLE, &ChrCtrl);
			   
	 			 ChrCtrl = KAL_TRUE;
				 bmt_charging_control_handler(BMT_CHARGING_CMD_CHARGING_ENABLE, &ChrCtrl);
	   		 }
		   }
		   drv_trace1(TRACE_GROUP_9, BMT_VCHARGER_TRC, BATPHYS->VCHARGER);
		   Cur_VCharge_MAX = BATPHYS->VCHARGER;
		   drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_RUNTIME_APPLY_CHARGE_CURRENT_TRC, bmt_high_vchg_current);  
		   drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_CUR_VCHG_MAX_TRC, Cur_VCharge_MAX);	
	   }
 
	   drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_TOTAL_VCHG_TRC, VCharge_Total);	
#endif

#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT) 
	   if ( (BATPHYS->VCHARGER > bmt_charging_para.HIGH_VCHG_TABLE[VCHG_VOL_LEVEL - 1][0]) ||
#else
	   if( (BATPHYS->VCHARGER > bmt_charging_para.VCHARGER_HIGH) ||
#endif
		 ((BMT.pmictrl_state == PMIC_CHARGEON) && (BATPHYS->ICHARGE	< bmt_charging_para.ICHARGE_ON_LOW)) )
		 {
		 	 DCL_BOOL ChrCtrl;

			 ChrCtrl = KAL_FALSE;
		 	 bmt_charging_control_handler(BMT_CHARGING_CMD_CHARGING_ENABLE, &ChrCtrl);

			 kal_sleep_task(20); //delay 20 frames for HW issue plug-out interrupt

			 ChrCtrl = KAL_TRUE;
			 bmt_charging_control_handler(BMT_CHARGING_CMD_CHARGING_ENABLE, &ChrCtrl);
		 }
	 
	   bmt_timer_config(KAL_TICKS_200_MSEC); //45 frames ~= 200ms
 }
#endif	//#if defined(__BMT_ON_STATE_CHECK__) || #if defined(__BMT_OFF_STATE_CHECK__) 
 
#ifdef TEMP_RECHARGE_SUPPORT
charge_adc_struct bmt_vol = {0};
extern void track_bmt_set_vbat_status(charge_adc_struct bmt_vol);

/*高低温充电停止后，恢复充电的温度 -- chengjun  2017-06-08*/
#if defined (__NT37__)
#define RECHARGETEMP_H       CHR_BATTMP_HIGH_TEMP-2000
#define RECHARGETEMP_L        CHR_BATTMP_LOW_TEMP+2000
#else
#define RECHARGETEMP_H       CHR_BATTMP_HIGH_TEMP-5000
#define RECHARGETEMP_L        CHR_BATTMP_LOW_TEMP+5000
#endif

#define CHECKCOUNT              3
#define TCOUNT                     3 

static void bmt_charge_start(void)
{
#if defined(__EVB__) && defined(__MTK_INTERNAL__)
/* under construction !*/
#else //#if defined(__EVB__)

    DCL_BOOL  charge_en = KAL_FALSE;
    DCL_UINT32  period = 1;	
    DCL_UINT8   EvaluateCount = 1;
   bmt_charging_control_handler(BMT_CHARGING_CMD_CHARGING_ENABLE, &charge_en);
   BMT.pmictrl_state = PMIC_CHARGEOFF;
   BMT.bat_state = CHR_PRE;
   BMT.VBAT_UEM= VBAT_UEM_CHR_IN_FISRT;
   bmt_total_charge_time = bmt_charging_para.bmt_total_charge_time;
   kal_prompt_trace(MOD_BMT,"bmt_charge_start by custome done");
#if defined(DRV_BMT_HW_PRECC_WORKAROUND)
    SW_Workaround_Flag = KAL_TRUE;
    Manual_Disable_Charge_Flag = KAL_FALSE;
#endif
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
   First_Time_Charge_Enable = KAL_TRUE;
   Pre_VCharge_AVG = 0;
   Cur_VCharge_MAX = 0;
#endif

   bmt_enable_sleepmode(KAL_FALSE);
		
   bmt_charging_timer_set(&period,&EvaluateCount);

   
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
   bmt_high_vchg_adjust_safetytimer(HIGH_V_VCHG_THRESHHOLD_LEVEL_5); 					   
#endif
   
   bmt_set_timer(BMT_CHARGE_TIMEOUT_TIMER,KAL_TICKS_1_MIN*bmt_total_charge_time);
   drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_START_TRC, bmt_total_charge_time);
   SaftyTimer_Flag = BMT_SAFETY_TIMER_ON; 
  
   bmt_set_chr_current();
   
  drv_trace0(TRACE_GROUP_10, BMT_CHARGING_START_TRC);
#endif//#if defined(__EVB__)
}

extern kal_bool BMT_ObtainBMTPHYSTAT(BATPHYStruct *BATPHYS);
extern void bmt_charge_start(void);
void BMT_CheckTemp(void)
{
    BATPHYStruct BATPHYS;
    static kal_uint32 check_count = 0;
    //BMT_CtrlCharge(kal_uint8 ON, kal_uint32 VBAT)
    bmt_CtrlCharge((kal_uint8)KAL_FALSE);

    //kal_prompt_trace(MOD_BMT,"BMT_CheckTemp:%d,%d",BATPHYS.VBAT,BATPHYS.BATTMP);
    //BMT.pmictrl_state = PMIC_CHARGEOFF;
    if(bmt_ObtainBMTPhystate(&BATPHYS))
    {
        bmt_PhyCheck(&BATPHYS);
        kal_prompt_trace(MOD_BMT,"BMT_CheckTemp:%d,%d",BATPHYS.VBAT,BATPHYS.BATTMP);
        bmt_vol.iChr = BATPHYS.ICHARGE;
        bmt_vol.vBat = BATPHYS.VBAT;
        bmt_vol.vChr = BATPHYS.VCHARGER;
        bmt_vol.vTemp = BATPHYS.BATTMP;
        track_bmt_set_vbat_status(bmt_vol);
        if((BMT.bat_state == CHR_TEMPCHECK) && temp_error)
        {
            //bmt_CtrlCharge((kal_uint8)KAL_TRUE);
            BMT.pmictrl_state = PMIC_CHARGEOFF;
            if((BATPHYS.BATTMP <= RECHARGETEMP_H) && (BATPHYS.BATTMP >= RECHARGETEMP_L))
            {
                check_count++;
            }
            else
            {
                check_count = 0;
            }

            if(check_count >= CHECKCOUNT)
            {
                temp_error = KAL_FALSE;
            }
            bmt_timer_config(TCOUNT * CHARGING_TIME_UNIT);
        }
        else
        {
            check_count = 0;
            bmt_charge_start();
        }
    }
}
#endif

#endif
