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
*    accdet.c
*
* Project:
* --------
*   Maui_Software
*
* Description:
* ------------
*   This Module is accessory detector driver.
*
* Author:
* -------
 * -------
 * -------
*
*============================================================================
****************************************************************************/
#if ((defined(__ACCDET_SUPPORT__)||defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)) && !defined(__L1_STANDALONE__))
#include    "stack_common.h"  
#include    "stack_msgs.h"
#include    "stack_config.h"        /*MOD_UART1_HISR,MOD_UART2_HISR*/
#include    "app_ltlcom.h"       /* Task message communiction */
#include    "drv_features_accdet.h"
#include    "drv_comm.h"
#include    "drv_hisr.h"
#include    "reg_base.h"
#include    "intrCtrl.h"
#include    "l1audio.h"
#include    "drv_trc.h"
#include    "drvsignals.h"
#include    "accdet_hw.h"
#include    "accdet_sw.h"
#include "kal_trace.h"
#include "stack_ltlcom.h"
#include "eint.h"
#include "init.h"

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "hisr_config.h"
#include  "aux_custom.h"
#if defined(__ACCDET_EINT_SUPPORT__) && defined(DRV_ACCDET_3_SECTION_EARPHONE_SUPPORT)
#include "med_aud_hal_struct.h"
#endif

#if defined(__ACCDET_SUPPORT__)

#if defined(__ACCDET_SLIM__)
void ACCDET_setDebounceSet(kal_uint8 idx);
#endif //#if defined(__ACCDET_SLIM__)

	#if defined(MT6251)
	AccDet_config_data_struct  accdet_config_data_def = 
	{
	   0x1000,  //HOOK_DEBOUNCE,
	   0x1000,//MIC_DEBOUNCE,
	   0x400, //PLUGOUT_DEBOUNCE,
	   0x84A6,     //PWM_DELAY,
	   0x1900,//CMP_WIDTH,
	   0x4B0,     //CMP_THRESHOLD,
	   0x1900,//VTH_WIDTH,
	   0x4B0,     //VTH_THRESHOLD,
	   0x1900,//MBIAS_WIDTH,
	   0x4B0      //MBIAS_THRESHOLD
	};
	#elif defined(MT6276)
	AccDet_config_data_struct  accdet_config_data_def = 
	{
	   0x1000,  //HOOK_DEBOUNCE,
	   0x1000,//MIC_DEBOUNCE,
	   0x400, //PLUGOUT_DEBOUNCE,
	   0x812C,     //PWM_DELAY,
	   0x1900,//CMP_WIDTH,
	   0x140,     //CMP_THRESHOLD,
	   0x1900,//VTH_WIDTH,
	   0x140,     //VTH_THRESHOLD,
	   0x1900,//MBIAS_WIDTH,
	   0x140      //MBIAS_THRESHOLD
	};
	#elif defined(MT6255) || defined(MT6250) || defined(MT6260)|| defined(MT6261)||defined(MT2501)|| defined(MT2502)
	AccDet_config_data_struct  accdet_config_data_def = 
	{
	   HOOKKEY_DEBOUNCE_TIME*327,  //HOOK_DEBOUNCE,
	   PLUGIN_DEBOUNCE_TIME*327,//MIC_DEBOUNCE,
	   PLUGOUT_DEBOUNCE_TIME*327, //PLUGOUT_DEBOUNCE,
	   0x8180,     //PWM_DELAY,
	   0x1900,//CMP_WIDTH,
	   0x400,     //CMP_THRESHOLD,
	   0x1900,//VTH_WIDTH,
	   0x400,     //VTH_THRESHOLD,
	   0x1900,//MBIAS_WIDTH,
	   0x400      //MBIAS_THRESHOLD
	};	
	
	#elif defined(MT6256)
	AccDet_config_data_struct  accdet_config_data_def = 
	{
	   HOOKKEY_DEBOUNCE_TIME*327,  //HOOK_DEBOUNCE,
	   PLUGIN_DEBOUNCE_TIME*327,//MIC_DEBOUNCE,
	   PLUGOUT_DEBOUNCE_TIME*327, //PLUGOUT_DEBOUNCE,
	   0x83B0,     //PWM_DELAY,
	   0x1900,//CMP_WIDTH,
	   0x400,     //CMP_THRESHOLD,
	   0x1900,//VTH_WIDTH,
	   0x400,     //VTH_THRESHOLD,
	   0x1900,//MBIAS_WIDTH,
	   0x400      //MBIAS_THRESHOLD
	};	
	#else
	AccDet_config_data_struct  accdet_config_data_def = 
	{
	   0x40,  //HOOK_DEBOUNCE,
	   0x1000,//MIC_DEBOUNCE,
	   0x400, //PLUGOUT_DEBOUNCE,
	   2,     //PWM_DELAY,
	   0x1900,//CMP_WIDTH,
	   5,     //CMP_THRESHOLD,
	   0x1900,//VTH_WIDTH,
	   5,     //VTH_THRESHOLD,
	   0x1900,//MBIAS_WIDTH,
	   5      //MBIAS_THRESHOLD
	};
	#endif
#elif defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)
AccDet_config_data_struct  accdet_config_data_def = 
{
   0x40,  //HOOK_DEBOUNCE,
   0x1000,//MIC_DEBOUNCE,
   0x400, //PLUGOUT_DEBOUNCE,
   2,     //PWM_DELAY,
   0x1900,//CMP_WIDTH,
   5,     //CMP_THRESHOLD,
   0x1900,//VTH_WIDTH,
   5,     //VTH_THRESHOLD,
   0x1900,//MBIAS_WIDTH,
   5      //MBIAS_THRESHOLD
};
#endif

//WIDTH 
//0x1900 for 5Hz
//0xc80 for 10Hz
//0x640 for 20Hz
//0x855 for 15Hz
//THRESHOLD
//0x12 - 0.56% duty
//0x18 - 1.5% duty
//0x21 - 1.75% duty
// width: 0x1000, threshold: 0x29(1%), 0xcc(5%), 0x800(50%)
// width: 0xc00, threshold: 0x1e(1%), 0x99(5%), 0x600(50%)

AccDet_config_data_struct *AccDet_Get_Data(void) 
{
   return (&accdet_config_data_def);
}
void AccDet_Set_Data(AccDet_config_data_struct* data)
{
	accdet_config_data_def.hook_debounce = data->hook_debounce;
	accdet_config_data_def.mic_debounce = data->mic_debounce;
	accdet_config_data_def.plugOut_debounce = data->plugOut_debounce;
	accdet_config_data_def.pwm_delay = data->pwm_delay;
	accdet_config_data_def.cmp_width = data->cmp_width;
	accdet_config_data_def.cmp_threshold = data->cmp_threshold;
	accdet_config_data_def.vth_width = data->vth_width;
	accdet_config_data_def.vth_threshold = data->vth_threshold;
	accdet_config_data_def.mbias_width = data->mbias_width;
	accdet_config_data_def.mbias_threshold = data->mbias_threshold;
}

//extern void IRQ_Register_LISR(kal_uint32 code, void (*reg_lisr)(void), char* description);
void ACCDET_Sendilm(module_type dst_mod, msg_type msgid, AUX_ID aux_id_no);

void ACCDET_HISR(void);


kal_uint16 PLUGOUT_COUNT = 1;
kal_uint16 HOOK_COUNT = 1;
kal_uint16 MIC_COUNT = 1;

kal_uint32 Handler_counter = 0;

accdet_status ACCDET_Status;
accdet_status ACCDET_Status_pre;  // for checking earphone without MIC

/*  // auto change setting, for DVT verify.

//extern void dbg_print(char *fmt,...);
kal_uint16 hook_debounce[] = {0x10, 0x50, 0x100, 0x1000};
kal_uint16 mic_debounce[] = {0x50, 0x1000, 0x4000, 0x8000};
kal_uint16 not_plug_debounce[] = {0x100, 0x400, 0x800, 0xFFFF};

#define ACCDET_EN_DELAY_VALUE 2
#define ACCDET_WIDTH_VALUE    0x1900
//0x1900 for 5Hz
//0xc80 for 10Hz
//0x640 for 20Hz
//0x855 for 15Hz
//0x600
#define ACCEDT_THRESH_VALUE  5
//0x12 - 0.56% duty
//0x18 - 1.5% duty
//0x21 - 1.75% duty
//0x60

// width: 0x1000, threshold: 0x29(1%), 0xcc(5%), 0x800(50%)
// width: 0xc00, threshold: 0x1e(1%), 0x99(5%), 0x600(50%)
kal_bool bChanged = KAL_FALSE;
void ACCDET_ChangeSetting(void)
{
   
   if((PLUGOUT_COUNT % 10) == 0)
   {
      //dbg_print("****************************************\n\r");
      //dbg_print("ACCDET not plug debounce changed: 0x%x\n\r", not_plug_debounce[PLUGOUT_COUNT/10]);
      drv_trace1(TRACE_GROUP_3, ACCDET_NOT_PLUG_DEBOUNCE_CHANGED, not_plug_debounce[PLUGOUT_COUNT/10]);
      ACCDET_SetDebounce(accdet_state11, not_plug_debounce[PLUGOUT_COUNT/10]);
      PLUGOUT_COUNT++;
      bChanged = KAL_TRUE;
      if(PLUGOUT_COUNT >= 50)
         PLUGOUT_COUNT = 1;
   }
   if((HOOK_COUNT % 10) == 0)
   {
      //dbg_print("****************************************\n\r");
      //dbg_print("ACCDET hook debounce changed: 0x%x\n\r", hook_debounce[HOOK_COUNT/10]);
      drv_trace1(TRACE_GROUP_3, ACCDET_HOOK_DEBOUNCE_CHANGED, hook_debounce[HOOK_COUNT/10]);
      ACCDET_SetDebounce(accdet_state00, hook_debounce[HOOK_COUNT/10]);
      HOOK_COUNT++;
      bChanged = KAL_TRUE;
      if(HOOK_COUNT >= 50)
         HOOK_COUNT = 1;
   }
   if((MIC_COUNT % 10) == 0)
   {
      //dbg_print("****************************************\n\r");
      //dbg_print("ACCDET mic debounce changed: 0x%x\n\r", mic_debounce[MIC_COUNT/10]);
      drv_trace1(TRACE_GROUP_3, ACCDET_MIC_DEBOUNCE_CHANGED, mic_debounce[MIC_COUNT/10]);
      ACCDET_SetDebounce(accdet_state01, mic_debounce[MIC_COUNT/10]);
      MIC_COUNT++;
      if(MIC_COUNT >= 50)
         MIC_COUNT = 1;
      bChanged = KAL_TRUE;
   }
   if(bChanged == KAL_TRUE)
   {
      DRV_ACCDET_WriteReg32(ACCDET_IRQ_STS, 0); //resume the IRQ
      
      DRV_ACCDET_WriteReg32(ACCDET_RSTB, 0x0); // reset ACCDET enable signal
      DRV_ACCDET_WriteReg32(ACCDET_CTRL, 0x0); //  ACCDET disable
      
      DRV_ACCDET_WriteReg32(ACCDET_RSTB, 0x1); // finish reset process
      
      ACCDET_Status = accdet_not_plugged; //defalut in not plugged status.
      //DRV_ACCDET_WriteReg32(ACCDET_IRQ_STS, ACCDET_IRQ_CLR); //pause the IRQ
   }
}

void ACCDET_register_test(kal_uint32 reg, kal_uint32 max)
{
   kal_uint32 i=0;
   kal_uint16 readOut;
   
   //dbg_print("ACCDET register read write test \n\r");
   //drv_trace4(TRACE_GROUP_3, ACCDET_SET_PWM);
   
   for(i=0;i<=max;i++)
   {
      DRV_ACCDET_WriteReg32(reg, i);
      readOut = DRV_ACCDET_Reg(reg);
      if(i != readOut)
      {
         while(1);
      }
   }
}

void ACCDET_read_write_test()
{
   ACCDET_register_test(ACCDET_RSTB, 1);
   
   ACCDET_register_test(ACCDET_CTRL, 1);
   
   ACCDET_register_test(ACCDET_STATE_SWCTRL, 0x1F);
   
   ACCDET_register_test(ACCDET_CMP_WIDTH, 0xFFFF);
   
   ACCDET_register_test(ACCDET_CMP_THRESH, 0xFFFF);
   
   ACCDET_register_test(ACCDET_VTH_WIDTH, 0xFFFF);
   
   ACCDET_register_test(ACCDET_VTH_THRESH, 0xFFFF);
   
   ACCDET_register_test(ACCDET_BIAS_WIDTH, 0xFFFF);
   
   ACCDET_register_test(ACCDET_BIAS_THRESH, 0xFFFF);
   
   ACCDET_register_test(ACCDET_PWM_IDLE, 0x7);
   
   ACCDET_register_test(ACCDET_DEBOUNCE0, 0xFFFF);
}
*/

#if defined(__ACCDET_EINT_SUPPORT__)   
extern const kal_uint8 AUX_EINT_NO;
static kal_bool aux_eint_state = (kal_bool)AUX_EINT_STATE;




void AUX_EINT2_HISR(void)
{
	kal_uint32 iStatus = 0;
	kal_uint32 iA,iB;


	iStatus = DRV_ACCDET_Reg32(ACCDET_MEMORIZED_IN); // get AB status.
	iA = (iStatus & 0x2) >> 1;
	iB = iStatus & 0x1;
	drv_trace4(TRACE_GROUP_3, ACCDET_EINT_STATUS_TRC,aux_eint_state,iA,iB,AUX_EINT_STATE);
	
	if (aux_eint_state == AUX_EINT_STATE)
	{
		aux_eint_state = (kal_bool)!aux_eint_state;
		EINT_Set_Polarity(AUX_EINT_NO,aux_eint_state); 
		EINT_SW_Debounce_Modify(AUX_EINT_NO,10);
		//AUX_Sendilm(MOD_EINT_HISR,MOD_UEM, MSG_ID_AUX_ID, AUX_ID_EARPHONE);
		DRV_ACCDET_WriteReg32(ACCDET_CTRL, 0x1); // enable ACCDET unit
	}
	else
	{
		aux_eint_state = (kal_bool)!aux_eint_state;
		EINT_Set_Polarity(AUX_EINT_NO,aux_eint_state);
		EINT_SW_Debounce_Modify(AUX_EINT_NO,10);
		//AUX_Sendilm(MOD_EINT_HISR,MOD_UEM, MSG_ID_AUX_ID, AUX_ID_PLUGOUT);
		//DRV_ACCDET_WriteReg32(ACCDET_CTRL, 0x0); // disable ACCDET unit
	}
}
#endif //#if defined(__ACCDET_EINT_SUPPORT__) 

//=================================================================
/*
* FUNCTION
*	ACCDET_init
*
* DESCRIPTION
*   	ACCDET initial
*
* CALLS
*	This function is called when ACCDET first initial
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif 
void ACCDET_init(void)
{

/*
// Add by GuoXin tmp solution

	#if defined(MT6250)
	// Set GPIO107 to EINT12 mode
	DRV_SetData(0xA0730168, 0xF000, 0x1000);
	
	// Set A-Die EAR_EINT edge trigger pol
	// The 1st design of MT6250 earphone design may lose "Bootup with earphone" scenario
	// 0xA073003C[0] = 1: Low -> High edge trigger (The 1st time)
	// 0xA073003C[0] = 0: High -> low edge trigger (The 1st time)
	// [0xA0730F10[0]: Real time status of the EINT level
	DRV_SetData32(0xA073003C, 0x00000001, 0x00000001);	
	#endif // #if defined(MT6250)
// Add by GuoXin tmp solution
*/

   //dbg_print("ACCDET init\n\r");
   drv_trace0(TRACE_GROUP_3, ACCDET_INIT);
   
   DRV_ACCDET_WriteReg32(ACCDET_RSTB, 0x0); // reset ACCDET enable signal
   DRV_ACCDET_WriteReg32(ACCDET_RSTB, 0x1); // finish reset process
   
   ACCDET_Status = accdet_not_plugged; //defalut in not plugged status.
   ACCDET_Status_pre = accdet_not_plugged;
   #if defined(__ACCDET_SUPPORT__)
   #if defined(__ACCDET_SLIM__)
	ACCDET_setDebounceSet(0);
   #else
   ACCDET_SetDebounce(accdet_state00, accdet_config_data_def.hook_debounce);  //Set debounce time
   ACCDET_SetDebounce(accdet_state01, accdet_config_data_def.mic_debounce);
   ACCDET_SetDebounce(accdet_state11, accdet_config_data_def.plugOut_debounce);
   #endif //#if defined(__ACCDET_SLIM__)
   
   #elif defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)
   ACCDET_SetDebounce(accdet_state00, accdet_config_data_def.mic_debounce);
   ACCDET_SetDebounce(accdet_state01, accdet_config_data_def.plugOut_debounce);
   ACCDET_SetDebounce(accdet_state11, 0xffff);
   #endif
   
   DRV_ACCDET_WriteReg32(ACCDET_EN_DELAY_NUM, accdet_config_data_def.pwm_delay); //Set delay time  //20->5
   
   #if defined( __ACCDET_SLIM__)// new chip have no 0x14---0x20 register
   DRV_ACCDET_WriteReg32(ACCDET_CMP_WIDTH, accdet_config_data_def.cmp_width); // set ACCDET pwm width as max counter value
   DRV_ACCDET_WriteReg32(ACCDET_CMP_THRESH, accdet_config_data_def.cmp_threshold);  // set ACCDET pwm thresh.
    #else  
   ACCDET_SetPWM(accdet_cmp, accdet_config_data_def.cmp_width, accdet_config_data_def.cmp_threshold);  //Set PWM
   ACCDET_SetPWM(accdet_vth, accdet_config_data_def.vth_width, accdet_config_data_def.vth_threshold);
   ACCDET_SetPWM(accdet_mbias, accdet_config_data_def.mbias_width, accdet_config_data_def.mbias_threshold);
   #endif//#if defined( __ACCDET_SLIM__)
   
   #if defined(__ACCDET_SUPPORT__)
   DRV_ACCDET_WriteReg32(ACCDET_STATE_SWCTRL, ACCDET_SWCTRL_EN);  // enable Detection Idle current, enable ACCDET's PWM unit.
   #elif defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)
   DRV_ACCDET_WriteReg32(ACCDET_STATE_SWCTRL, ACCDET_ANASW | ACCDET_CMP_EN);
   #endif


   DRV_Register_HISR(DRV_ACCDET_HISR_ID, ACCDET_HISR);
   IRQ_Register_LISR(IRQ_ACCDET_CODE, ACCDET_LISR, "ACCDET handler");
   IRQSensitivity(IRQ_ACCDET_CODE,EDGE_SENSITIVE);

	 #if defined(MT6256)
	 DRV_SetBits(0x801A1114, 0X400);
	 #endif
#if defined(__ACCDET_EINT_SUPPORT__)
	EINT_Registration(AUX_EINT_NO,KAL_TRUE,aux_eint_state,AUX_EINT2_HISR, KAL_TRUE);
	EINT_SW_Debounce_Modify(AUX_EINT_NO,10);
	   DRV_ACCDET_WriteReg32(ACCDET_CTRL, 0x0); // disable ACCDET unit
#else
	 #ifndef __BT_BOX_SUPPORT__
    DRV_ACCDET_WriteReg32(ACCDET_CTRL, 0x1); // enable ACCDET unit
   #endif
   // accdet must be enable(because  plug in before booting up on EINT + ACCDET solution,the accdet is disable. this first status check will be failed)
	
#endif //#if defined(__ACCDET_EINT_SUPPORT__)	 
  // IRQUnmask(IRQ_ACCDET_CODE);       // move the unmask to the aux task main
  #if defined(MT6261)|| defined(MT2501) ||defined(MT2502)
  if( INT_SW_SecVersion() == SW_SEC_0)
  	{
  //modify by liming for ACCDET workaround  ---  open mic bais power
  DRV_ACCDET_WriteReg32(0xA0720060, 0x0a);
}
   #endif
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

void ACCDET_reset(void)
{
	DRV_ACCDET_WriteReg32(ACCDET_CTRL, 0x0); // disable ACCDET unit
	DRV_ACCDET_WriteReg32(ACCDET_RSTB, 0x0); // reset ACCDET enable signal
	DRV_ACCDET_WriteReg32(ACCDET_RSTB, 0x1); // finish reset process
	DRV_ACCDET_WriteReg32(ACCDET_CTRL, 0x1); // enable ACCDET unit
}

//=================================================================
/*
* FUNCTION
*	ACCDET_SetDebounce
*
* DESCRIPTION
*   	ACCDET set plug-in/out IRQ debounce
*
* CALLS
*	This function is called when ACCDET change debounce
*
* PARAMETERS
*	debounce - debounce value ( 1/32 ms )
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void ACCDET_SetDebounce(accdet_pwm_debs state, kal_uint16 debounce)
{
   //dbg_print("ACCDET Set Debounce: state: %d debounce = %d \n\r", state, debounce);
   drv_trace2(TRACE_GROUP_3, ACCDET_SET_DEBOUNCE, state, debounce);
   
   switch(state)
   {
   case accdet_state00:
   	  DRV_ACCDET_WriteReg32(ACCDET_DEBOUNCE0, debounce); // set ACCDET debounce value = debounce/32 ms
        break;
   case accdet_state01:
      DRV_ACCDET_WriteReg32(ACCDET_DEBOUNCE1, debounce); // set ACCDET debounce value = debounce/32 ms
      break;
   case accdet_state10:
      DRV_ACCDET_WriteReg32(ACCDET_DEBOUNCE2, debounce); // set ACCDET debounce value = debounce/32 ms
      break;
   case accdet_state11:
      DRV_ACCDET_WriteReg32(ACCDET_DEBOUNCE3, debounce); // set ACCDET debounce value = debounce/32 ms
      break;
   default:
      break;
   }
}
//=================================================================
/*
* FUNCTION
*	ACCDET_SetPWM
*
* DESCRIPTION
*   	ACCDET set PWM frequence
*
* CALLS
*	This function is called when ACCDET change PWM frequence
*
* PARAMETERS
*	width - pwm width as max counter value
*  thresh - pwm threshold
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void ACCDET_SetPWM(kal_uint16 pwmSet, kal_uint16 width, kal_uint16 thresh)
{
   //dbg_print("ACCDET Set PWM: pwmSet = %d, width = %d,thresh = %d  \n\r", pwmSet,width,thresh);
   drv_trace4(TRACE_GROUP_3, ACCDET_SET_PWM, pwmSet, width, thresh, NULL);
   
   switch(pwmSet)
   {
   case accdet_cmp:
      DRV_ACCDET_WriteReg32(ACCDET_CMP_WIDTH, width); // set ACCDET pwm width as max counter value
      DRV_ACCDET_WriteReg32(ACCDET_CMP_THRESH, thresh);  // set ACCDET pwm thresh.
      break;
   case accdet_vth:
      DRV_ACCDET_WriteReg32(ACCDET_VTH_WIDTH, width);
      DRV_ACCDET_WriteReg32(ACCDET_VTH_THRESH, thresh);
      break;
   case accdet_mbias:
      DRV_ACCDET_WriteReg32(ACCDET_BIAS_WIDTH, width);
      DRV_ACCDET_WriteReg32(ACCDET_BIAS_THRESH, thresh);
      break;
   default:
      break;
   }
}

//=================================================================
/*
* FUNCTION
*	ACCDET_SetNotPlugged
*
* DESCRIPTION
*   	ACCDET set as standby not plugged status
*
* CALLS
*	This function is called when set state machine as standby not plugged status .
*
* PARAMETERS
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void ACCDET_SetNotPlugged(void)
{
   //dbg_print("ACCDET Set Not Plugged \n\r");
   drv_trace0(TRACE_GROUP_3, ACCDET_SET_NOT_PLUGGED);
   PLUGOUT_COUNT++;
   ACCDET_Status_pre = ACCDET_Status;
   ACCDET_Status = accdet_not_plugged;
   DRV_ACCDET_WriteReg32(ACCDET_STATE_SWCTRL, ACCDET_SWCTRL_EN); // enable ACCDET unit
   
   ///AFE_TurnOffMicBias();
   ACCDET_Sendilm(MOD_UEM, MSG_ID_AUX_ID, AUX_ID_PLUGOUT);

#if defined(__ACCDET_EINT_SUPPORT__)
   DRV_ACCDET_WriteReg32(ACCDET_CTRL, 0x0);
#endif //#if defined(__ACCDET_EINT_SUPPORT__)
}

//=================================================================
/*
* FUNCTION
*	ACCDET_SetPlugged
*
* DESCRIPTION
*   	ACCDET set as standby plugged status
*
* CALLS
*	This function is called when set state machine as standby plugged.
*  Only use under TVOUT support
*
* PARAMETERS
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void ACCDET_SetPlugged(void)
{
   //dbg_print("ACCDET Set Plugged \n\r");   
   drv_trace0(TRACE_GROUP_3, ACCDET_SET_PLUGGED);
    ACCDET_Status_pre = ACCDET_Status;
   ACCDET_Status = accdet_plugged;
   DRV_ACCDET_WriteReg32(ACCDET_STATE_SWCTRL, ACCDET_SWCTRL_EN); // enable ACCDET unit
}

//=================================================================
/*
* FUNCTION
*	ACCDET_SetMIC
*
* DESCRIPTION
*   	ACCDET set as MIC status
*
* CALLS
*	This function is called when set state machine as MIC.
*
* PARAMETERS
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void ACCDET_SetMIC(void)
{
   //dbg_print("ACCDET Set MIC bias \n\r");
   drv_trace0(TRACE_GROUP_3, ACCDET_SET_MIC_BIAS);
   
   MIC_COUNT++;
   DRV_ACCDET_WriteReg32(ACCDET_STATE_SWCTRL, ACCDET_SWCTRL_EN); // enable ACCDET unit
   
   ///AFE_TurnOnMicBias();
   if(ACCDET_Status == accdet_not_plugged) //exclusive release action.
   {
      ACCDET_Sendilm(MOD_AUX, MSG_ID_AUX_PLUGIN, AUX_MAX_ID); //nothing to do.
      ACCDET_Sendilm(MOD_UEM, MSG_ID_AUX_ID, AUX_ID_EARPHONE);
   }
   //else if(ACCDET_Status == accdet_switched) // change from press to release
   //{
   //   ACCDET_Sendilm(MOD_UEM, MSG_ID_AUX_ID, AUX_ID_KEY_RELEASE); //MMI don't need release
   //}
   ACCDET_Status_pre = ACCDET_Status;
   ACCDET_Status = accdet_mic;
}

//=================================================================
/*
* FUNCTION
*	ACCDET_SetSwitched
*
* DESCRIPTION
*   	ACCDET set as hook switched status
*
* CALLS
*	This function is called when set state machine as hook switched.
*
* PARAMETERS
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void ACCDET_SetSwitched(void)
{
   //dbg_print("ACCDET Set Switched \n\r");
   drv_trace0(TRACE_GROUP_3, ACCDET_SET_SWITCHED);
   
   HOOK_COUNT++;
   DRV_ACCDET_WriteReg32(ACCDET_STATE_SWCTRL, ACCDET_SWCTRL_EN); // enable ACCDET unit
   
   if(ACCDET_Status == accdet_not_plugged) //exclusive release action.
   { 
      ACCDET_Sendilm(MOD_AUX, MSG_ID_AUX_PLUGIN, AUX_MAX_ID); //nothing to do.
      ACCDET_Sendilm(MOD_UEM, MSG_ID_AUX_ID, AUX_ID_EARPHONE);
   }
   else
   {
      ACCDET_Sendilm(MOD_UEM, MSG_ID_AUX_ID, AUX_ID_KEY_PRESS);
   }
    ACCDET_Status_pre = ACCDET_Status;
   ACCDET_Status = accdet_switched;
}

//=================================================================
/*
* FUNCTION
*	ACCDET_SetCheckTV
*
* DESCRIPTION
*   	ACCDET set as double check TV path status
*
* CALLS
*	This function is called when set state machine as double check tv path.
*
* PARAMETERS
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void ACCDET_SetCheckTV(void)
{
   //dbg_print("ACCDET Set Check TV \n\r");
   drv_trace0(TRACE_GROUP_3, ACCDET_SET_CHECK_TV);
   
   DRV_ACCDET_WriteReg32(ACCDET_STATE_SWCTRL, ACCDET_TV_DET | ACCDET_MICBIA_EN); // enable ACCDET unit
    ACCDET_Status_pre = ACCDET_Status;
   ACCDET_Status = accdet_check_tv;
}

//=================================================================
/*
* FUNCTION
*	ACCDET_SetTVOut
*
* DESCRIPTION
*   	ACCDET set as TV-Out status
*
* CALLS
*	This function is called when set state machine as TV-Out.
*
* PARAMETERS
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void ACCDET_SetTVOut(void)
{
   //dbg_print("ACCDET Set TV Out \n\r");
   drv_trace0(TRACE_GROUP_3, ACCDET_SET_TVOUT);
    ACCDET_Status_pre = ACCDET_Status;
   ACCDET_Status = accdet_tv_out;
   DRV_ACCDET_WriteReg32(ACCDET_STATE_SWCTRL, ACCDET_TV_DET); // enable ACCDET unit
}

//=================================================================
/*
* FUNCTION
*	ACCDET_NotPluggedHandler
*
* DESCRIPTION
*   	ACCDET status handler
*
* CALLS
*	This function is called when ACCDET under plugged status.
*
* PARAMETERS
*	iA - Accessory Comparator A value
*	iB - Accessory Comparator B value
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
#if defined(__ACCDET_EINT_SUPPORT__) && defined(DRV_ACCDET_3_SECTION_EARPHONE_SUPPORT)
extern void ACCDET_earphone_with_mic_send_msg_to_MED(void);
#endif

void ACCDET_NotPluggedHandler(kal_uint32 iA, kal_uint32 iB)
{
   //kal_uint16 PluggedFail = 0;
   
   //dbg_print("ACCDET Not Plugged Handler: iA = %d, iB = %d \n\r", iA, iB);
   drv_trace2(TRACE_GROUP_3, ACCDET_NOT_PLUGGED_HANDLER, iA, iB);
   
   if((iA == 0) && (iB == 0))
   {
      //ACCDET_SetCheckTV();// For MT6236, we do not have TV
      ACCDET_SetSwitched(); //
   }
   else if((iA == 0) && (iB == 1))
   {
      ACCDET_SetMIC();
   }
   else if((iA == 1) && (iB == 1))
   {
      //dbg_print("ACCDET Not Plugged state not change\n\r");
      drv_trace0(TRACE_GROUP_3, ACCDET_NOT_PLUGGED_STATE_NOT_CHANGE);
   }
   else
   {
      //dbg_print("ACCDET Not Plugged Handler fail\n\r");
      drv_trace0(TRACE_GROUP_3, ACCDET_NOT_PLUGGED_HANDLER_FAIL);
      //while(!PluggedFail);
   }
}

//=================================================================
/*
* FUNCTION
*	ACCDET_PluggedHandler
*
* DESCRIPTION
*   	ACCDET status handler
*
* CALLS
*	This function is called when ACCDET under plugged status.
*
* PARAMETERS
*	iA - Accessory Comparator A value
*	iB - Accessory Comparator B value
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void ACCDET_PluggedHandler(kal_uint32 iA, kal_uint32 iB)
{
   //kal_uint16 PluggedFail = 0;
   
   //dbg_print("ACCDET Plugged Handler: iA = %d, iB = %d \n\r", iA, iB);
   drv_trace2(TRACE_GROUP_3, ACCDET_PLUGGED_HANDLER, iA, iB);
   
   if((iA == 1) && (iB == 1))
   {
      ACCDET_SetNotPlugged();
   }
   else
   {
      //dbg_print("ACCDET Plugged Handler Fail\n\r");
      drv_trace0(TRACE_GROUP_3, ACCDET_PLUGGED_HANDLER_FAIL);
      //while(!PluggedFail);
   }
}

//=================================================================
/*
* FUNCTION
*	ACCDET_MicHandler
*
* DESCRIPTION
*   	ACCDET status handler
*
* CALLS
*	This function is called when ACCDET under not plugged status.
*
* PARAMETERS
*	iA - Accessory Comparator A value
*	iB - Accessory Comparator B value
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void ACCDET_MicHandler(kal_uint32 iA, kal_uint32 iB)
{
   //kal_uint16 MicFail = 0;
   
   //dbg_print("ACCDET Mic Handler: iA = %d, iB = %d \n\r", iA, iB);
   drv_trace2(TRACE_GROUP_3, ACCDET_MIC_HANDLER, iA, iB);
   
   if((iA == 0) && (iB == 0))
   {
      ACCDET_SetSwitched();
   }
   else if((iA == 1) && (iB == 1))
   {
      ACCDET_SetNotPlugged();
   }
   else if((iA == 0) && (iB == 1))
   {
      //dbg_print("ACCDET mic state not change\n\r");
      drv_trace0(TRACE_GROUP_3, ACCDET_MIC_STATE_NOT_CHANGE);
   }
   else
   {
      //dbg_print("ACCDET Mic Handler Fail \n\r");
      drv_trace0(TRACE_GROUP_3, ACCDET_MIC_HANDLER_FAIL);
      //while(!MicFail);
   }
}

//=================================================================
/*
* FUNCTION
*	ACCDET_SwitchedHandler
*
* DESCRIPTION
*   	ACCDET status handler
*
* CALLS
*	This function is called when ACCDET under hook switched status.
*
* PARAMETERS
*	iA - Accessory Comparator A value
*	iB - Accessory Comparator B value
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void ACCDET_SwitchedHandler(kal_uint32 iA, kal_uint32 iB)
{
   //kal_uint16 SwitchedFail = 0;
   
   //dbg_print("ACCDET Switched Handler: iA = %d, iB = %d \n\r", iA, iB);
   drv_trace2(TRACE_GROUP_3, ACCDET_SWITCHED_HANDLER, iA, iB);
   
   if((iA == 0) && (iB == 1))
   {
#if defined(__ACCDET_EINT_SUPPORT__) && defined(DRV_ACCDET_3_SECTION_EARPHONE_SUPPORT)
  		if( (ACCDET_Status_pre == accdet_not_plugged)  && (ACCDET_Status == accdet_switched) )// change 3 section to 4 section earphone
  		{
  	  	 ACCDET_earphone_with_mic_send_msg_to_MED();  // 4 section earphone
  		}
 		 #endif
      ACCDET_SetMIC();
   }
   else if((iA == 1) && (iB == 1))
   {
      ACCDET_SetNotPlugged();
   }
   else if((iA == 0) && (iB == 0))
   {
      //dbg_print("ACCDET hook state not change\n\r");
      drv_trace0(TRACE_GROUP_3, ACCDET_HOOK_STATE_NOT_CHANGE);
   }
   else
   {
      //dbg_print("ACCDET Switched Handler Fail \n\r");
      drv_trace0(TRACE_GROUP_3, ACCDET_SWITCHED_HANDLER);
      //while(!SwitchedFail);
   }
}

//=================================================================
/*
* FUNCTION
*	ACCDET_CheckTvHandler
*
* DESCRIPTION
*   	ACCDET status handler
*
* CALLS
*	This function is called when ACCDET under double check TV path status.
*
* PARAMETERS
*	iA - Accessory Comparator A value
*	iB - Accessory Comparator B value
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void ACCDET_CheckTvHandler(kal_uint32 iA, kal_uint32 iB)
{
   //kal_uint16 CheckTvFail = 0;
   
   //dbg_print("Check TV Handler: iA = %d, iB = %d \n\r", iA, iB);
   drv_trace2(TRACE_GROUP_3, ACCDET_CHECK_TV_HANDLER, iA, iB);
   
   if((iA == 0) && (iB == 0))
   {
      ACCDET_SetSwitched();
   }
   else if((iA == 1) && (iB == 1))
   {
      ACCDET_SetMIC();
   }
   else if((iA == 0) && (iB == 1))
   {
      ACCDET_SetTVOut();
   }
   else
   {
      //dbg_print("Check TV Handler: CheckTvFail \n\r");
      drv_trace0(TRACE_GROUP_3, ACCDET_CHECK_TV_HANDLER_FAIL);
      //while(!CheckTvFail);
   }
}

//=================================================================
/*
* FUNCTION
*	ACCDET_TvOutHandler
*
* DESCRIPTION
*   	ACCDET status handler
*
* CALLS
*	This function is called when ACCDET under TV-Out status.
*
* PARAMETERS
*	iA - Accessory Comparator A value
*	iB - Accessory Comparator B value
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void ACCDET_TvOutHandler(kal_uint32 iA, kal_uint32 iB)
{
   //kal_uint16 CheckTvFail = 0;
   
   //dbg_print("ACCDET TvOut Handler: iA = %d, iB = %d \n\r", iA, iB);
   drv_trace2(TRACE_GROUP_3, ACCDET_TVOUT_HANDLER, iA, iB);
   
   if((iA == 1) && (iB == 1))
   {
      ACCDET_SetNotPlugged();
   }
   else
   {
      //dbg_print("ACCDET TvOut Handler Fail\n\r");
      drv_trace0(TRACE_GROUP_3, ACCDET_TVOUT_HANDLER_FAIL);
      //while(!CheckTvFail);
   }
}

//=================================================================
/*
* FUNCTION
*	ACCDET_Handler
*
* DESCRIPTION
*   	ACCDET status handler
*
* CALLS
*	This function is called when ACCDET LISR active HISR
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
#if defined(__ACCDET_SUPPORT__)

#if defined(__ACCDET_SLIM__)
const kal_uint8 AccDet_SM[4][4]=
{
	{NOACT,		SWITCHED_EAR,	SWITCHED_KEY,	NOACT	},
	{NOACT,		MIC_EAR,		NOACT,			MIC_NULL},
	{NOACT,		NOACT,			NOACT,			NOACT},
	{NOTPLUGGED_PLUGOUT,NOACT,NOTPLUGGED_PLUGOUT,NOTPLUGGED_PLUGOUT}
};

const AccDet_Actions accdet_Acts[]=
{
    {accdet_switched,		AUX_ID_EARPHONE,	ACCDET_SWCTRL_EN,	1},//set_switched1
    {accdet_switched,		AUX_ID_KEY_PRESS,	ACCDET_SWCTRL_EN,	1},//set_switched2
    {accdet_mic,			AUX_ID_EARPHONE,	ACCDET_SWCTRL_EN,	1},//set_mic1
    {accdet_mic,			AUX_MAX_ID,			ACCDET_SWCTRL_EN,	1},//set_mic2 
    {accdet_not_plugged,	AUX_ID_PLUGOUT,		ACCDET_SWCTRL_EN,	0}  
};



const kal_uint16 AccdetDebounce[2][3]=
{			//00  hook key                                 01 plug in                                    11 plug out
		{HOOKKEY_DEBOUNCE_TIME*327,PLUGIN_DEBOUNCE_TIME*327,PLUGOUT_DEBOUNCE_TIME*327}, //before plug in setting
		{HOOKKEY_DEBOUNCE_TIME*327,4096					    ,PLUGOUT_DEBOUNCE_TIME*327} //after plug in setting
};


void ACCDET_setDebounceSet(kal_uint8 idx)
{
	if (idx>1)
		return;
   DRV_ACCDET_WriteReg32(ACCDET_DEBOUNCE0, AccdetDebounce[idx][0]);  //Set debounce time
   DRV_ACCDET_WriteReg32(ACCDET_DEBOUNCE1, AccdetDebounce[idx][1]);  //Set debounce time
   DRV_ACCDET_WriteReg32(ACCDET_DEBOUNCE2, AccdetDebounce[idx][2]); //Set debounce time
}




#endif //#if defined(__ACCDET_SLIM__)


kal_bool ACCDET_Is_Earphone_With_MIC(void)
{   
#if defined(__ACCDET_EINT_SUPPORT__) && defined(DRV_ACCDET_3_SECTION_EARPHONE_SUPPORT)
kal_uint32 savedMask;
kal_bool temp;

//I bit
    savedMask = SaveAndSetIRQMask();
	if( (ACCDET_Status_pre == accdet_not_plugged) && (ACCDET_Status == accdet_switched) )
		temp = KAL_FALSE;  //return KAL_FALSE;// 3  section earphone
	else
		temp = KAL_TRUE;// return KAL_TRUE;// 4  section earphone
    RestoreIRQMask(savedMask);

	   if(temp)
		drv_trace0(TRACE_GROUP_3, ACCDET_EARPHONE_MED_GET_MIC);
		else
		drv_trace0(TRACE_GROUP_3, ACCDET_EARPHONE_MED_GET_WITHOUT_MIC);
		
		return  temp;
#else
	return KAL_TRUE;// 4  section earphone
	//only EINT + ACCDET solution support earphone without mic
#endif

}
#if defined(__ACCDET_EINT_SUPPORT__) && defined(DRV_ACCDET_3_SECTION_EARPHONE_SUPPORT)

void ACCDET_earphone_with_mic_send_msg_to_MED()
{
//send msg to MED
media_aud_set_headset_mode_mic_struct  *accdet_with_mic_data;
ilm_struct		 *ACCDET_ilm;

    accdet_with_mic_data = (media_aud_set_headset_mode_mic_struct*)construct_local_para(sizeof(media_aud_set_headset_mode_mic_struct), TD_CTRL);	
    accdet_with_mic_data->with_mic =KAL_TRUE ;//  4 section earphone

DRV_BuildPrimitive(ACCDET_ilm,
   MOD_DRV_HISR,
   MOD_MED,
   MSG_ID_MEDIA_AUD_SET_HEADSET_MODE_MIC_REQ,
   accdet_with_mic_data);

msg_send_ext_queue(ACCDET_ilm);


drv_trace0(TRACE_GROUP_3, ACCDET_EARPHONE_WITH_MIC);
}
#endif
void ACCDET_Handler(void)
{
   kal_uint32 iStatus = 0;
   kal_uint32 iA,iB;
#if defined(__ACCDET_SLIM__)
   const AccDet_Actions *pAct;
#endif //#if defined(__ACCDET_SLIM__)
   
   //dbg_print("ACCDET Handler\n\r");
   drv_trace0(TRACE_GROUP_3, ACCDET_HANDLER);
   
   
   iStatus = DRV_ACCDET_Reg32(ACCDET_MEMORIZED_IN); // get AB status.
   iA = (iStatus & 0x2) >> 1;
   iB = iStatus & 0x1;
   drv_trace2(TRACE_GROUP_3, ACCDET_STATUS_TRC,iA,iB);

#if defined(__ACCDET_SLIM__)
  pAct=&accdet_Acts[AccDet_SM[iStatus][ACCDET_Status]];
  DRV_ACCDET_WriteReg32(ACCDET_STATE_SWCTRL, pAct->regValue);
  
  if(pAct->msg!=AUX_MAX_ID)
  {
  	ACCDET_Sendilm(MOD_UEM, MSG_ID_AUX_ID, pAct->msg);
  }
  #if defined(__ACCDET_EINT_SUPPORT__) && defined(DRV_ACCDET_3_SECTION_EARPHONE_SUPPORT)
  else if( (ACCDET_Status_pre == accdet_not_plugged) && (ACCDET_Status == accdet_switched) )// change 3 section to 4 section earphone
  	{
  	   ACCDET_earphone_with_mic_send_msg_to_MED();  // 4 section earphone
  	}
  #endif

  ACCDET_setDebounceSet(pAct->debounceIdx);
  ACCDET_Status_pre = ACCDET_Status;
  ACCDET_Status=pAct->nextState;

  #if defined(__ACCDET_EINT_SUPPORT__)
//modify by liming for MT6261 workaround
	if(ACCDET_Status == accdet_not_plugged)
	   DRV_ACCDET_WriteReg32(ACCDET_CTRL, 0x0); // disable ACCDET unit
	#endif
#else
   switch(ACCDET_Status)
   {
   case accdet_plugged:
      ACCDET_PluggedHandler(iA,iB);
      break;
   case accdet_not_plugged:
      ACCDET_NotPluggedHandler(iA,iB);
      break;
   case accdet_mic:
      ACCDET_MicHandler(iA,iB);
      break;
   case accdet_switched:
      ACCDET_SwitchedHandler(iA,iB);
      break;
   case accdet_check_tv:
      ACCDET_CheckTvHandler(iA,iB);
      break;
   case accdet_tv_out:
      ACCDET_TvOutHandler(iA,iB);
      break;
   default:
      break;
   }
#endif //#if defined(__ACCDET_SLIM__)
   
}
#elif defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)
extern kal_bool g_bAudioBufferOpen;
extern kal_bool g_bPlugIn;

extern void aux_plugin_handler(void);
extern void aux_plugout_handler(void);

void ACCDET_Handler(void)
{
	kal_uint32 iStatus = 0;
   	kal_uint32 iA,iB;

   	drv_trace0(TRACE_GROUP_3, ACCDET_HANDLER);
   
   	iStatus = DRV_ACCDET_Reg32(ACCDET_MEMORIZED_IN); // get AB status.
   	iA = (iStatus & 0x2) >> 1;
   	iB = iStatus & 0x1; // we just care the B bit status
		
	drv_trace2(TRACE_GROUP_3, ACCDET_STATUS_TRC,iA,iB);	
		
	if(KAL_TRUE == g_bAudioBufferOpen)
	{
		drv_trace0(TRACE_GROUP_3, ACCDET_HYBRID_ILLEGAL_INTERRUPT1_TRC);
	  return;
	}
	else
	{
		if((iA == 0)&&(iB == 1))
		{
			if(KAL_FALSE == g_bPlugIn)//boot up, AB = 01
			{
				drv_trace0(TRACE_GROUP_3, ACCDET_HYBRID_ILLEGAL_INTERRUPT2_TRC);
				return;
			}
			aux_plugout_handler();
			ACCDET_Sendilm(MOD_AUX, MSG_ID_AUX_PLUGOUT, AUX_ID_PLUGOUT);
		}
		else if ((iA == 0)&&(iB == 0))
		{
			aux_plugin_handler();
			ACCDET_Sendilm(MOD_AUX, MSG_ID_AUX_PLUGIN, AUX_ID_PLUGIN);
		}
		else
		{
			return; //illegal AB status
		}
    }
}
#endif

//=================================================================
/*
* FUNCTION
*	ACCDET_HISR
*
* DESCRIPTION
*   	ACCDET HISR handler
*
* CALLS
*	This function is called when ACCDET LISR active HISR
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void ACCDET_HISR(void)
{
   #if defined(DRV_ACCDET_6276E2_SERIES)
   #else
   kal_uint32 sts;
   #endif
   
   //dbg_print("----------------------------------------------------------------\n\r");
   //dbg_print("ACCDET HISR %d\n\r", Handler_counter++);
   //FM need earphone to work as antenna, do not need trigger accdet function. there are not exist AUX task.
   if(stack_query_boot_mode()== FACTORY_BOOT) 
      return;
      
   drv_trace0(TRACE_GROUP_3, ACCDET_HISR_TRC);
   
   ACCDET_Handler();

   #if defined(DRV_ACCDET_6276E2_SERIES)
   DRV_ACCDET_Reg32(ACCDET_IRQ_STS)&ACCDET_IRQ_STS_IRQ;	
   #else //#if defined(DRV_ACCDET_6276E2_SERIES)
   do
   {
   	sts=DRV_ACCDET_Reg32(ACCDET_IRQ_STS)&ACCDET_IRQ_STS_IRQ;	
   }
   while(sts!=0);
   DRV_ACCDET_WriteReg32(ACCDET_IRQ_STS, 0); //resume the IRQ
   #endif //#if defined(DRV_ACCDET_6276E2_SERIES)
   
   //ACCDET_ChangeSetting();
   
   IRQClearInt(IRQ_ACCDET_CODE);
   IRQUnmask(IRQ_ACCDET_CODE);
   /*
   if(bChanged == KAL_TRUE)
   {
   DRV_ACCDET_WriteReg32(ACCDET_CTRL, 0x1); //  ACCDET enable
   bChanged = KAL_FALSE;
   }
   */
}

//=================================================================
/*
* FUNCTION
*	ACCDET_LISR
*
* DESCRIPTION
*   	ACCDET interrupt handler
*
* CALLS
*	This function is called when ACCDET intr. is coming
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void ACCDET_LISR(void)
{
   DRV_ACCDET_WriteReg32(ACCDET_IRQ_STS, ACCDET_IRQ_CLR); //pause the IRQ
   IRQMask(IRQ_ACCDET_CODE);
   drv_active_hisr(DRV_ACCDET_HISR_ID);
}

//=================================================================
/*
* FUNCTION
*	ACCDET_Enable_TV
*
* DESCRIPTION
*   	ACCDET enable tv function
*
* CALLS
*	This function is called when user want to enable TV
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void ACCDET_Enable_TV(void)
{
   if(ACCDET_Status == accdet_tv_out)
   {
      ACCDET_SetTVOut();
   }
}

//=================================================================
/*
* FUNCTION
*	ACCDET_Disable_TV
*
* DESCRIPTION
*   	ACCDET disable tv function
*
* CALLS
*	This function is called when user want to disable TV
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void ACCDET_Disable_TV(void)
{
   if(ACCDET_Status == accdet_tv_out)
   {
      ACCDET_SetPlugged();
   }
}

void ACCDET_MICBIAS_ONOFF(kal_bool en)
{
#if defined(DRV_ACCDET_6236_SERIES)
   kal_uint32 micbias_on;

   micbias_on = DRV_ACCDET_Reg32(0x801B010C) & 0x20;
   if(micbias_on && (en == KAL_FALSE)) //mic-bias power on currently, turn it off.
   {
      DRV_ACCDET_ClearBits32(0x801B010C, 0x20);
   }
   else if((micbias_on == 0) && (en == KAL_TRUE)) // mic-bias power off currently, turn it on.
   {
      DRV_ACCDET_SetBits32(0x801B010C, 0x20);
   }
#endif //#if defined(DRV_ACCDET_6236_SERIES)
}


//=================================================================
/*
* FUNCTION
*	ACCDET_Sendilm
*
* DESCRIPTION
*   	ACCDET send aux message to UEM
*
* CALLS
*	This function is called when ACCDET has some action
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/

void ACCDET_Sendilm(module_type dst_mod, msg_type msgid, AUX_ID aux_id_no)
{
   aux_id_struct    *aux_id_data;
   ilm_struct       *aux_ilm;
   
   aux_id_data = (aux_id_struct*)
      construct_local_para(sizeof(aux_id_struct), TD_CTRL);	   
   aux_id_data->aux_id = aux_id_no;
   
   DRV_BuildPrimitive(aux_ilm,
      MOD_DRV_HISR,
      dst_mod,
      msgid,
      aux_id_data);
   
   msg_send_ext_queue(aux_ilm);
}



#endif //#if (defined(__ACCDET_SUPPORT__) && !defined(__L1_STANDALONE__))
