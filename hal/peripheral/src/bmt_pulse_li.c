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
 *	 bmt.c
 *
 * Project:
 * --------
 *	Maui_Software
 *
 * Description:
 * ------------
 *	This Module defines charging algorithm.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *				 HISTORY
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
  *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include    "drv_features.h"
#include	"drv_comm.h"
#include 	"stack_msgs.h"
#include 	"app_ltlcom.h"		/* Task message communiction */
#include	"drvsignals.h"
#include	"bmt_trc.h"
// For RHR ADD Usage
#include 	"stack_config.h"
#include	"drvpdn.h"
#include 	"kal_trace.h"
#include 	"stack_ltlcom.h"
#include    "bmt_utility.h"
#include    "kal_general_types.h"
#include    "kal_public_api.h"
#include    "dcl.h"
#include	"dcl_pmu_sw.h"
#include    "bmt_sw_chip_setting.h"
#include    "bmt_chr_setting.h"
#include    "bmt_timer_control.h"
#include    "bmt_hw.h"
#include    "L1sm_public.h"
#include	"bmt_pulse_li.h"


#if !defined(BMT_CHARGING_DISABLE)
// ============================================================ //
//define
// ============================================================ //
#define STOPTIMER_TIMEOUT_TICK	 (KAL_TICKS_1_MIN*30)


// ============================================================ //
//global variable
// ============================================================ //
static kal_uint8 BATFULL_index = 0;


// ============================================================ //
// function prototype
// ============================================================ //
static void BMT_CHRPRE_ON(BATPHYStruct *BATPHYS);
static void BMT_CHRPRE_OFF(BATPHYStruct *BATPHYS);
static void BMT_CHRFAST_ON(BATPHYStruct *BATPHYS);
static void BMT_CHRFAST_OFF(BATPHYStruct *BATPHYS);
static void BMT_CHRTOPOFF_ON(BATPHYStruct *BATPHYS);
static void BMT_CHRTOPOFF_OFF(BATPHYStruct *BATPHYS);
static void BMT_CHRBATFULL_ON(BATPHYStruct *BATPHYS);
static void BMT_CHRBATFULL_OFF(BATPHYStruct *BATPHYS);
static void BMT_CHRHOLD(BATPHYStruct *BATPHYS);
static void BMT_MEASURE_STOP(BATPHYStruct *BATPHYS);
static void BMT_CHRPOSTFULL_ON(BATPHYStruct *BATPHYS);
static void BMT_CHRPOSTFULL_OFF(BATPHYStruct *BATPHYS);
// ============================================================ //
//extern variable
// ============================================================ //


// ============================================================ //
//extern function
// ============================================================ //
extern void bmt_sendMes2UEM(BMT_CHR_STAT status);


// ============================================================ //
static const CHR_FUNC	BMT_CHRFUNC[][2] = 
{
    {BMT_CHRPRE_OFF, BMT_CHRPRE_ON} //CHR_PRE
    ,{BMT_CHRFAST_OFF, BMT_CHRFAST_ON} //CHR_FAST
    ,{BMT_CHRTOPOFF_OFF, BMT_CHRTOPOFF_ON} //CHR_TOPOFF
    ,{BMT_CHRBATFULL_OFF, BMT_CHRBATFULL_ON} //CHR_BATFULL
    ,{BMT_MEASURE_STOP,BMT_MEASURE_STOP} //CHR_ERROR
    ,{BMT_CHRHOLD,BMT_CHRHOLD} //CHR_HOLD
    ,{BMT_CHRPOSTFULL_OFF, BMT_CHRPOSTFULL_ON} //CHR_POSTFULL
};


/*
* FUNCTION
*	   bmt_charge_start
*
* DESCRIPTION                                                           
*   	This function is to start charging algorithm.
*
* CALLS  
*
* PARAMETERS
*	   None
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
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
#if defined(DRV_BMT_HW_PRECC_WORKAROUND)
    SW_Workaround_Flag = KAL_TRUE;
    Manual_Disable_Charge_Flag = KAL_FALSE;
#endif
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
   First_Time_Charge_Enable = KAL_TRUE;
   Pre_VCharge_AVG = 0;
   Cur_VCharge_MAX = 0;
#endif

   #ifdef MTK_SLEEP_ENABLE
#if !defined (__GPS_TRACK__)
   L1SM_SleepDisable(bmt_sm_handle);
#endif /* __GPS_TRACK__ */
   #endif
		
   bmt_charging_timer_set(&period,&EvaluateCount);

   
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
   bmt_high_vchg_adjust_safetytimer(HIGH_V_VCHG_THRESHHOLD_LEVEL_5); 					   
#endif
   
   bmt_set_timer(BMT_CHARGE_TIMEOUT_TIMER,KAL_TICKS_1_MIN*bmt_total_charge_time);
   drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_START_TRC, bmt_charging_para.bmt_total_charge_time);
   SaftyTimer_Flag = BMT_SAFETY_TIMER_ON; 
  
   bmt_set_chr_current();
   
   drv_trace0(TRACE_GROUP_10, BMT_CHARGING_START_TRC);
#endif//#if defined(__EVB__)
}


/*
* FUNCTION
*	   bmt_charge_end
*
* DESCRIPTION                                                           
*   	This function is to stop charging when charger is plugged out 
*     or serious error in charging stage.
*
* CALLS  
*
* PARAMETERS
*	   None
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
static void bmt_charge_end(void)
{
#if defined(__EVB__) && defined(__MTK_INTERNAL__)
/* under construction !*/
#else//#if defined(__EVB__)
    DCL_STATUS adc_status;
	DCL_BOOL charge_en = KAL_FALSE;

	BMT.pmictrl_state = PMIC_CHARGEOFF;
   	BMT.VBAT_UEM = VBAT_UEM_CHR_OUT_FIRST;
	bmt_usb_chr_current = PMU_CHARGE_CURRENT_INIT;	//set max currrent as default value
	
	bmt_charging_control_handler(BMT_CHARGING_CMD_CHARGING_ENABLE, &charge_en);
	adc_status = DclSADC_Control(bmt_adc_handle, ADC_CMD_STOP_MEASURE, NULL);
	if(adc_status != STATUS_OK)
	{
		ASSERT(0);
	}

	bmt_stop_timer(BMT_STOP_CHARGE_TIMER);
	bmt_stop_timer(BMT_CHARGE_TIMEOUT_TIMER);

	drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_STOP_TRC, bmt_charging_para.bmt_total_charge_time);
   SaftyTimer_Flag = BMT_SAFETY_TIMER_OFF; 
   #ifdef MTK_SLEEP_ENABLE
   #if !defined (__GPS_TRACK__)
   L1SM_SleepEnable(bmt_sm_handle);
   #endif
   #endif
   
   drv_trace0(TRACE_GROUP_10, BMT_CHARGING_END_TRC);
 //  DclSADC_Close(adc_handle);
#endif//#if defined(__EVB__)
}



static void bmt_ChrPRE_to_ChrBatFull(void)
{
    BMT.bat_state = CHR_BATFULL;
    bmt_stop_timer(BMT_CHARGE_TIMEOUT_TIMER);

	drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_STOP_TRC, bmt_total_charge_time);

    drv_trace0(TRACE_GROUP_10, BMT_CHR_BATFULL_CHANGE_TRC);
    BMT.highfull = 1;
    bmt_sendMes2UEM(BMT_CHARGE_COMPLETE);
    bmt_timer_config(bmt_charging_para.PRE_TON*CHARGING_TIME_UNIT);
}


/*
* FUNCTION
*		bmt_ChrPRE_to_ChrBatFULL_Check
*
* DESCRIPTION																			  
*		This function is used to check if current battery voltage is larger than VBAT_CV
*	    Level - 2. We will transite to CHRBATFULL state.
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
*	  None
*/
static kal_bool bmt_ChrPRE_to_ChrBatFULL_Check(BATPHYStruct *BATPHYS)
{
    if(bmt_get_chr_cv_det()) // For Custom check CV function
	{
        bmt_ChrPRE_to_ChrBatFull();
		return KAL_TRUE;				
	}
   
    if(BATPHYS->VBAT > 4175000)
    {
        bmt_ChrPRE_to_ChrBatFull();
		return KAL_TRUE;				
	}
    else
    {
  	    return KAL_FALSE;
	}
}


static kal_bool bmt_Chr_Is_Charge_Full(BATPHYStruct *pBATPHYS)
{
#ifndef __BMT_NO_ISENSE_RESISTOR__
	if (pBATPHYS->ICHARGE < bmt_charging_para.I_TOPOFF2FULL_THRES)
	{
		return KAL_TRUE;
	}
	else
	{
		return KAL_FALSE;
	}
#else	
	ASSERT(0); // When this function is called, we should have some operations to check charge full
	return KAL_FALSE;
#endif // #ifndef __BMT_NO_ISENSE_RESISTOR__
}



/*
* FUNCTION
*		bmt_TOnOff
*
* DESCRIPTION																			  
*		This function is to obtain the TON/TOFF paramters in CHR_FAST mode.
*
* CALLS  
*
* PARAMETERS
*		PHY: measured physical parameters
*	  BATTime: the structure of TON/TOFF parameters
*	
* RETURNS
*		None
*
* GLOBALS AFFECTED
*	  None
*/
static void bmt_TOnOff(BATPHYStruct *PHY,CHRTStruct *pBATTime)////======
{
#ifndef __BMT_NO_ISENSE_RESISTOR__
	if(BMT.call_state == talk_mode)
	{
		if (PHY->ICHARGE > bmt_charging_para.FAST_ICHARGE_HIGHLEVEL)
		{
			pBATTime->TON=bmt_charging_para.TONOFFTABLE[3][CHRTON];
			pBATTime->TOFF=bmt_charging_para.TONOFFTABLE[3][CHRTOFF];
		}
		else
		{
			if (PHY->ICHARGE < bmt_charging_para.FAST_ICHARGE_LOWLEVEL)
			{
				pBATTime->TON=bmt_charging_para.TONOFFTABLE[5][CHRTON];
				pBATTime->TOFF=bmt_charging_para.TONOFFTABLE[5][CHRTOFF];
			}
			else
			{
				pBATTime->TON=bmt_charging_para.TONOFFTABLE[4][CHRTON];
				pBATTime->TOFF=bmt_charging_para.TONOFFTABLE[4][CHRTOFF];
			}
		}	
	}
	else
	{	 	
		if (PHY->ICHARGE > bmt_charging_para.FAST_ICHARGE_HIGHLEVEL)
		{
			pBATTime->TON=bmt_charging_para.TONOFFTABLE[0][CHRTON];
			pBATTime->TOFF=bmt_charging_para.TONOFFTABLE[0][CHRTOFF];
		}
		else
		{
			if (PHY->ICHARGE <bmt_charging_para.FAST_ICHARGE_LOWLEVEL)
			{
				pBATTime->TON=bmt_charging_para.TONOFFTABLE[2][CHRTON];
				pBATTime->TOFF=bmt_charging_para.TONOFFTABLE[2][CHRTOFF];
			}
			else
			{
				pBATTime->TON=bmt_charging_para.TONOFFTABLE[1][CHRTON];
				pBATTime->TOFF=bmt_charging_para.TONOFFTABLE[1][CHRTOFF];
			}
		}
	}	
#else // #ifndef __BMT_NO_ISENSE_RESISTOR__
	pBATTime->TON=bmt_charging_para.TONOFFTABLE[0][CHRTON];
	pBATTime->TOFF=bmt_charging_para.TONOFFTABLE[0][CHRTOFF];
#endif // #ifndef __BMT_NO_ISENSE_RESISTOR__
}


/*
* FUNCTION
*		BMT_CHRPRE_ON
*
* DESCRIPTION																			  
*		This function is called when charger is on, and BMT charge module 
*	  is at CHR_PRE state.
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
*	  None
*/
static void BMT_CHRPRE_ON(BATPHYStruct *BATPHYS)
{
	drv_trace0(TRACE_STATE, BMT_CHRPRE_ON_STATE_TRC);

	bmt_CtrlCharge((kal_uint8)KAL_FALSE);	//Turn off Charge
	bmt_timer_config(bmt_charging_para.PRE_TOFF*CHARGING_TIME_UNIT);
}


/*
* FUNCTION
*		BMT_CHRPRE_OFF
*
* DESCRIPTION																			  
*		This function is called when charger is off, and BMT charge module 
*	  is at CHR_PRE state.
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
*	  None
*/
static void BMT_CHRPRE_OFF(BATPHYStruct *BATPHYS)
{
	drv_trace0(TRACE_STATE, BMT_CHRPRE_OFF_STATE_TRC);
	
	if( ((BATPHYS->VBAT) > bmt_charging_para.V_PRE2FAST_THRES) && (BMT.bat_state !=CHR_ERROR)&&(BMT.bat_state != CHR_HOLD))
	{
         
        if(bmt_ChrPRE_to_ChrBatFULL_Check(BATPHYS))
        {
			return;				
		}

		bmt_CtrlCharge((kal_uint8)KAL_TRUE);

		BMT.bat_state = CHR_FAST;
		if(bmt_Get_PowerOn_Type()== (kal_uint8)PRECHRPWRON)//PRECHRPWRON
		{
			ilm_struct *BMT_ilm;				
			/*change power on type as charger power on*/						 
			bmt_Modify_PowerOn_Type((kal_uint8)CHRPWRON);
#ifndef L4_NOT_PRESENT
#if defined(PMIC_PRESENT)
			{	
				DCL_HANDLE	bmt_PmuHandler;

				bmt_PmuHandler=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	           	DclPW_Control(bmt_PmuHandler, PW_CMD_UPDATE_FLAGS, NULL);
				DclPMU_Close(bmt_PmuHandler);
			}
#endif // #if defined(PMIC_PRESENT)
#endif // #ifndef L4_NOT_PRESENT
			DRV_BuildPrimitive(BMT_ilm, MOD_BMT, MOD_UEM, 
									MSG_ID_BMT_LEAVE_PRECHARGE_IND,NULL);
			msg_send_ext_queue(BMT_ilm);										
		}							
		drv_trace0(TRACE_GROUP_10, BMT_FAST_CHARGE_CHANGE_TRC);
	}
	else
	{
		bmt_CtrlCharge((kal_uint8)KAL_TRUE);	//Turn on Charge
	}

	bmt_timer_config(bmt_charging_para.PRE_TON*CHARGING_TIME_UNIT);
}


/*
* FUNCTION
*		BMT_CHRFAST_ON
*
* DESCRIPTION																			  
*		This function is called when charger is on, and BMT charge module 
*	  is at CHR_FAST state.
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
*	  None
*/
static void BMT_CHRFAST_ON(BATPHYStruct *BATPHYS)
{
	drv_trace0(TRACE_STATE, BMT_FAST_ON_STATE_TRC);
	
	bmt_TOnOff(BATPHYS,&BATTime);
	bmt_CtrlCharge((kal_uint8)KAL_FALSE);	//Turn off Charge
	bmt_timer_config(BATTime.TOFF*CHARGING_TIME_UNIT);
}


/*
* FUNCTION
*		BMT_CHRFAST_OFF
*
* DESCRIPTION																			  
*		This function is called when charger is off, and BMT charge module 
*	  is at CHR_FAST state.
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
*	  None
*/
static void BMT_CHRFAST_OFF(BATPHYStruct *BATPHYS)
{
	drv_trace0(TRACE_STATE, BMT_FAST_OFF_STATE_TRC);
	
	if((BMT.bat_state != CHR_ERROR)&&(BMT.bat_state != CHR_HOLD))
	{
		if (BATPHYS->VBAT > bmt_charging_para.V_FAST2TOPOFF_THRES)
		{
			BMT.bat_state = CHR_TOPOFF;
			bmt_CtrlCharge((kal_uint8)KAL_TRUE);
			drv_trace0(TRACE_GROUP_10, BMT_CHR_TOPOFF_CHANGE_TRC);
			bmt_timer_config(BATTime.TON*CHARGING_TIME_UNIT);

			return;
		}

		bmt_CtrlCharge((kal_uint8)KAL_TRUE);	//Turn on Charge
	}

	bmt_timer_config(BATTime.TON*CHARGING_TIME_UNIT);
}


/*
* FUNCTION
*		BMT_CHRTOPOFF_ON
*
* DESCRIPTION																			  
*		This function is called when charger is on, and BMT charge module 
*	  is at CHR_TOPOFF state.
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
*	  None
*/
static void BMT_CHRTOPOFF_ON(BATPHYStruct *BATPHYS)	  //CV
{
	
	drv_trace0(TRACE_STATE, BMT_CHRTOPOFF_ON_STATE_TRC);
	
	if(BMT.bat_state != CHR_ERROR)
	{
		bmt_CtrlCharge((kal_uint8)KAL_FALSE);
		bmt_timer_config(bmt_charging_para.TOPOFF_TOFF*CHARGING_TIME_UNIT);
		return;
	}

	bmt_timer_config(bmt_charging_para.TOPOFF_TON*CHARGING_TIME_UNIT);
}


/*
* FUNCTION
*		BMT_CHRTOPOFF_OFF
*
* DESCRIPTION																			  
*		This function is called when charger is off, and BMT charge module 
*	  is at CHR_TOPOFF state.
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
*	  None
*/
static void BMT_CHRTOPOFF_OFF(BATPHYStruct *BATPHYS)
{
	drv_trace0(TRACE_STATE, BMT_CHRTOPOFF_OFF_STATE_TRC);
	
	if(bmt_get_chr_cv_det() || (BATPHYS->VBAT >= 4200000))
	{
		BATFULL_index++;
	}
		
	if(BATFULL_index == 6 )
	{
		// change state to post full
		BMT.bat_state = CHR_POSTFULL;
		drv_trace0(TRACE_GROUP_10, BMT_CHR_POSTFULL_CHANGE_TRC);
		/*30min*/
		bmt_set_timer(BMT_STOP_CHARGE_TIMER,STOPTIMER_TIMEOUT_TICK);
		bmt_sendMes2UEM(BMT_CHARGE_COMPLETE);
		bmt_timer_config(bmt_charging_para.BATPOSTFULL_TWAIT_LI*KAL_TICKS_1_SEC); //wait 90 seconds, then check the vbat at BMT_CHRBATFULL_OFF
		BATFULL_index = 0; //reset the index, recount the percentage again.
		return;
	}
	bmt_CtrlCharge((kal_uint8)KAL_TRUE);
	
	bmt_timer_config(bmt_charging_para.TOPOFF_TON*CHARGING_TIME_UNIT);
}


/*
* FUNCTION
*		BMT_CHRPOSTFULL_ON
*
* DESCRIPTION																			  
*		This function is called when charger is on, and BMT charge module 
*	  is at CHR_POSTFULL state.
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
*	  None
*/
static void BMT_CHRPOSTFULL_ON(BATPHYStruct *BATPHYS)
{
	drv_trace0(TRACE_STATE, BMT_CHRBATPOSTFULL_ON_STATE_TRC);
	
	bmt_CtrlCharge((kal_uint8)KAL_FALSE);
	bmt_timer_config(bmt_charging_para.BATPOSTFULL_TOFF_LI*CHARGING_TIME_UNIT);
}


/*
* FUNCTION
*		BMT_CHRPOSTFULL_OFF
*
* DESCRIPTION																			  
*		This function is called when charger is off, and BMT charge module 
*	  is at CHR_POSTFULL state.
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
*	  None
*/
static void BMT_CHRPOSTFULL_OFF(BATPHYStruct *BATPHYS)
{
	
	drv_trace0(TRACE_STATE, BMT_CHRBATPOSTFULL_OFF_STATE_TRC);
	
	if(BMT.bat_state != CHR_ERROR)
	{
		if(bmt_get_chr_cv_det() || (BATPHYS->VBAT >= 4200000))
		{
			BATFULL_index++;
		}
				
		if(BATFULL_index == 6)
		{
			// change state to bat full
			BMT.bat_state = CHR_BATFULL;
			bmt_stop_timer(BMT_STOP_CHARGE_TIMER);
			bmt_stop_timer(BMT_CHARGE_TIMEOUT_TIMER);

			drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_STOP_TRC, bmt_total_charge_time);
			drv_trace0(TRACE_GROUP_10, BMT_CHR_BATFULL_CHANGE_TRC);
			
			BMT.highfull = 1;
			BATFULL_index = 0;
			bmt_timer_config(bmt_charging_para.BATPOSTFULL_TON_LI*CHARGING_TIME_UNIT);
			return;
		}
		bmt_CtrlCharge((kal_uint8)KAL_TRUE);
	}

	bmt_timer_config(bmt_charging_para.BATPOSTFULL_TON_LI*CHARGING_TIME_UNIT);
}


/*
* FUNCTION
*		BMT_CHRBATFULL_ON
*
* DESCRIPTION																			  
*		This function is called when charger is on, and BMT charge module 
*	  is at CHR_BATFULL state.
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
*	  None
*/
static void BMT_CHRBATFULL_ON(BATPHYStruct *BATPHYS)
{
	
	drv_trace0(TRACE_STATE, BMT_CHRBATFULL_ON_STATE_TRC);
	
	if(BMT.bat_state != CHR_ERROR)
	{
		bmt_CtrlCharge((kal_uint8)KAL_FALSE);
		bmt_timer_config(bmt_charging_para.BATFULL_TOFF_LI*CHARGING_TIME_UNIT);
	}
	else
	{
		bmt_CtrlCharge((kal_uint8)KAL_FALSE);
		bmt_timer_config(1*CHARGING_TIME_UNIT);			
	}
}


/*
* FUNCTION
*		BMT_CHRBATFULL_OFF
*
* DESCRIPTION																			  
*		This function is called when charger is off, and BMT charge module 
*	  is at CHR_BATFULL state.
*
* CALLS  
*
* PARAMETERS
*		None
*	
* RETURNS
*		None
*
*/
static void BMT_CHRBATFULL_OFF(BATPHYStruct *BATPHYS) 
{
	
	drv_trace0(TRACE_STATE, BMT_CHRBATFULL_OFF_STATE_TRC);
	
	if (BMT.highfull)
	{
		drv_trace0(TRACE_GROUP_10, BMT_HIGH_BAT_FULL_TRC);
		
		if((BMT.bat_state != CHR_ERROR)&&(BMT.bat_state != CHR_HOLD))
		{
			if ((BATPHYS->VBAT) < bmt_charging_para.V_FULL2FAST_THRES)
			{
				BMT.bat_state = CHR_FAST;
				bmt_stop_timer(BMT_STOP_CHARGE_TIMER);
				drv_trace0(TRACE_GROUP_10, BMT_CHR_FAST_CHANGE_TRC);
				BMT.highfull = 0;

#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
				bmt_high_vchg_adjust_safetytimer(BATPHYS->VCHARGER);						
#endif
				bmt_set_timer(BMT_CHARGE_TIMEOUT_TIMER,KAL_TICKS_1_MIN*bmt_total_charge_time); 
			}
		} 
		bmt_CtrlCharge((kal_uint8)KAL_FALSE);
		bmt_timer_config(bmt_charging_para.BATFULL_TOFF*CHARGING_TIME_UNIT);
		return;
		
	}//if (BMT.highfull)


}


/*
* FUNCTION
*		BMT_CHRHOLD
*
* DESCRIPTION																			  
*		This function is called when BMT charge module 
*	  is at CHR_HOLD state.
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
*	  None
*/
static void BMT_CHRHOLD(BATPHYStruct *BATPHYS)
{
	drv_trace0(TRACE_STATE, BMT_CHRHOLD_STATE_TRC);
	
	if(((BATPHYS->VBAT) < bmt_charging_para.V_PROTECT_LOW_LI) || (BMT.call_state == 0))
	{
		BMT.bat_state = CHR_FAST;
		bmt_stop_timer(BMT_STOP_CHARGE_TIMER);
		drv_trace0(TRACE_GROUP_10, BMT_FAST_CHARGE_CHANGE_TRC);
	}
	
	bmt_CtrlCharge((kal_uint8)KAL_FALSE);
	bmt_timer_config(bmt_charging_para.BATHOLD_OFF*CHARGING_TIME_UNIT);
}


/*
* FUNCTION
*		BMT_MEASURE_STOP
*
* DESCRIPTION																			  
*		This function is used to stop the charge measure, and restart normal measure.
*	  Besides, this function is called when BMT charge module 
*	  is at CHR_ERROR state.
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
*	  None
*/
static void BMT_MEASURE_STOP(BATPHYStruct *BATPHYS)
{
	drv_trace0(TRACE_GROUP_10, BMT_MEASURE_STOP_TRC);

	BMT.pmictrl_state = PMIC_CHARGEOFF;
	bmt_charge_end();
}


static void bmt_charge_algo_enable(void *data)
{
	kal_bool *penable = (kal_bool *)(data);
	if(KAL_TRUE == *penable)
		bmt_charge_start();
	else
		bmt_charge_end();
}


static void bmt_change_state(void *data)
{
	BATPHYStruct *pBATPHYS = (BATPHYStruct *)(data);
	BMT_CHRFUNC[BMT.bat_state][BMT.pmictrl_state](pBATPHYS);
}


static void (*bmt_charging_state_func[BMT_CHARGING_ALGO_CMD_NUMBER])(void *data)=
{
	bmt_charge_algo_enable,
	bmt_change_state	
};


/*
* FUNCTION
*	   chr_algorithm_control_handler
*
* DESCRIPTION                                                           
*   	This function is called to start/end charging
*
* CALLS  
*
* PARAMETERS
*	   None
*	
* RETURNS
*	   
*
* GLOBALS AFFECTED
*     None
*/
DCL_STATUS chr_algorithm_control_handler(BMT_CHARGING_ALGORITHM_CTRL_CMD cmd, void *data)
{
	DCL_STATUS status = STATUS_OK;

    if(cmd < BMT_CHARGING_ALGO_CMD_NUMBER)
		bmt_charging_state_func[cmd](data);
	else
		return STATUS_UNSUPPORTED;

	return status;
}


#endif// !defined(BMT_CHARGING_DISABLE)
