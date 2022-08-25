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
 *    tp_drv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is defined for touch screen driver
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features.h"
#include "drv_comm.h"
#include "reg_base.h"
#if defined(DRV_ADC_TOUCH_SCREEN) && (defined(TOUCH_PANEL_SUPPORT) || defined(HAND_WRITING) || defined(DRV_ADC_TOUCH_SCREEN_BTMT))
#include "eint.h"
//#include "touch_panel_custom.h"
#include "touch_panel.h"
//#include    "touch_panel_spi.h"
#include "drv_hisr.h"
#include "ts_hw.h"
#include "intrCtrl.h"
#include "drvpdn.h"
//#include "gpt_sw.h"
#include "adc_hw.h"
#include "adc_sw.h"
#include "drv_trc.h"
#include "init.h"
//#include "kal_non_specific_general_types.h"
//#include "kal_release.h"
#include "kal_trace.h"

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "us_timer.h"

#ifdef DRV_TS_SW_RESET_CHECK_FOR_BUSY_BIT
//adc reset when adc hang
extern void adc_sw_reset(adc_tp_reset_type);
#endif							


extern void SLA_CustomLogging(kal_char *customJob, kal_uint32 saAction);

#if !defined(DRV_TS_OFF)

extern PFN_DCL_CALLBACK DclHTS_DownHandler_cb;
extern PFN_DCL_CALLBACK DclHTS_UpHandler_cb;

kal_uint16  ts_read_adc(kal_uint16 pos,kal_bool IsPressure);
#if defined(TOUCH_PANEL_PRESSURE)
kal_bool tp_pressure_check(void);
#endif

#if defined(__TOUCH_PANEL_MULTITOUCH__)
kal_uint32 tsSampleResolution = TS_CMD_SINGLE_END; //multiple touch need single end to measure xp-xn.
#else
kal_uint32 tsSampleResolution = TS_CMD_DIFFERENTIAL;
#endif
kal_uint32 tsModeSelection    = TS_CMD_MODE_10BIT;
kal_uint32        ts_tcs_off_gpt_handle;  /*gpt handle*/

kal_bool ts_power_on = KAL_TRUE;
#ifdef DRV_TS_SW_RESET_CHECK_FOR_BUSY_BIT
kal_bool TPWaitBusy_flag = KAL_FALSE;
kal_uint32 TPWaitBusy;
kal_uint16 ts_adc_reset_cnt=0;
kal_bool ts_adc_not_busy = KAL_TRUE;
extern kal_bool auxadc_die2die_enable;
extern kal_bool adc_ready_to_sample(void);
#endif

void TP_PDN_CLR(void)
{
#ifdef DRV_TP_ADIE_DDIE_STRCUTURE
	kal_uint32 savedMask;
	savedMask = SaveAndSetIRQMask();
#ifdef DRV_TP_AUXADC_MOVE_TO_ADIE  
#if 0	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    PDN_CLR(PDN_TP);

#else
	PDN_CLR(PDN_ADC);
	PDN_CLR(PDN_TP);
    ust_busy_wait(8); //wait 8 us for not frequency enable.
	DRV_TP_SetBits(TS_ABB_RSV_CON1,TS_26M_CLK_CTRL_3);
	ust_busy_wait(3);
	DRV_TP_SetBits(TS_ABB_RSV_CON1,TS_FSM_CTRL_3);
	DRV_TP_SetBits(TS_ABB_DD_WR_PATH0,TS_AAF_EN);   
	DRV_TP_SetBits(TS_ABB_WR_PATH0,TS_F26M_CLK_EN|TS_AUX_PWDB); //always on F26M
	DRV_TP_SetBits(TS_ABBA_WR_PATH0,TS_ABBA_AUX_PWDB);
	DRV_TP_SetBits(TS_ABB_AUX_CON0,TS_AUX_FIFO_CLK_EN);
	DRV_TP_SetBits(TS_ABB_AUX_CON0,TS_AUX_FIFO_EN);
#endif
	RestoreIRQMask(savedMask);
#else //#ifdef DRV_TP_ADIE_DDIE_STRCUTURE
#if defined(__OLD_PDN_ARCH__)
#if defined(__OLD_PDN_DEFINE__)
	DRV_TP_WriteReg(DRVPDN_CON1+0x20,(kal_uint16)DRVPDN_CON1_TP);
#elif defined(__APPLICATION_PROCESSOR__)
	DRV_TP_WriteReg(CG_CON0,(kal_uint16)CG_CON0_TP);
#else // #if defined(__OLD_PDN_DEFINE__)
	DRV_TP_WriteReg(CG_CLR1 ,(kal_uint16)CG_CON1_TP);
#endif // #if defined(__OLD_PDN_DEFINE__)
#else //#if defined(__OLD_PDN_ARCH__)
	PDN_CLR(PDN_TP);
#endif //#if defined(__OLD_PDN_ARCH__)
#endif //#ifdef DRV_TP_ADIE_DDIE_STRCUTURE
	if(!kal_if_hisr())
		drv_trace0(TRACE_GROUP_10, TP_PDN_CLR_NOT_IN_HISR);
}

void TP_PDN_SET(void)
{
#ifdef DRV_TP_ADIE_DDIE_STRCUTURE
	kal_uint32 savedMask;
	savedMask = SaveAndSetIRQMask();
#ifdef DRV_TP_AUXADC_MOVE_TO_ADIE
	PDN_SET(PDN_TP);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	
#else
	if(!auxadc_die2die_enable)
	{
		DRV_TP_ClearBits(TS_ABB_AUX_CON0,TS_AUX_FIFO_EN);
		DRV_TP_ClearBits(TS_ABB_AUX_CON0,TS_AUX_FIFO_CLK_EN);
		DRV_TP_ClearBits(TS_ABB_WR_PATH0,TS_AUX_PWDB);
		DRV_TP_ClearBits(TS_ABBA_WR_PATH0,TS_ABBA_AUX_PWDB);
		//DRV_TP_ClearBits(TS_ABB_RSV_CON1,TS_FSM_CTRL_3 | TS_26M_CLK_CTRL_3);
		DRV_TP_ClearBits(TS_ABB_RSV_CON1,TS_FSM_CTRL_3);
		ust_busy_wait(2);
		DRV_TP_ClearBits(TS_ABB_RSV_CON1,TS_26M_CLK_CTRL_3);
		ust_busy_wait(8); //wait 8 us for not frequency enable.
		PDN_SET(PDN_ADC);
		PDN_SET(PDN_TP);
		//DRV_TP_ClearBits(0xa0160020,0x8000);
		DRV_TP_ClearBits(TS_ABB_DD_WR_PATH0,TS_AAF_EN);
	}

	else 
	{
		DRV_TP_ClearBits(TS_ABB_RSV_CON1,TS_FSM_CTRL_3);
		ust_busy_wait(2);
		DRV_TP_ClearBits(TS_ABB_RSV_CON1,TS_26M_CLK_CTRL_3);
	}
#endif
  RestoreIRQMask(savedMask);

#else //#ifdef DRV_TP_ADIE_DDIE_STRCUTURE
	volatile kal_uint32 i;
	i = 0;

    while ( (DRV_TP_Reg(AUXADC_CON) & AUXADC_CON_RUN) != 0 )
    {
		i++;
        if (i>=1000)
        {
			break;
		}
	}
#if defined(__OLD_PDN_ARCH__)
#if defined(__OLD_PDN_DEFINE__)
	DRV_TP_WriteReg(DRVPDN_CON1+0x10,(kal_uint16)DRVPDN_CON1_TP);
#elif defined(__APPLICATION_PROCESSOR__)
	DRV_TP_WriteReg(CG_SET0,(kal_uint16)CG_CON0_TP);
#else
	DRV_TP_WriteReg(CG_SET1,(kal_uint16)CG_CON1_TP);
#endif
#else //#if defined(__OLD_PDN_ARCH__)
   PDN_SET(PDN_TP);
#endif //#if defined(__OLD_PDN_ARCH__)
#endif  //#ifdef DRV_TP_ADIE_DDIE_STRCUTURE
	if(!kal_if_hisr())
		drv_trace0(TRACE_GROUP_10, TP_PDN_SET_NOT_IN_HISR);
}

#ifndef DRV_TP_SLIM
void TP_PDN_SET_ON_BACKLIGHT_OFF(void)
{
#ifdef DRV_TP_ADIE_DDIE_STRCUTURE
	kal_uint32 savedMask;
	savedMask = SaveAndSetIRQMask();
#ifdef DRV_TP_AUXADC_MOVE_TO_ADIE
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
PDN_SET(PDN_TP);

#else
	if(!auxadc_die2die_enable)
	{

		DRV_TP_ClearBits(TS_ABB_AUX_CON0,TS_AUX_FIFO_EN);
		DRV_TP_ClearBits(TS_ABB_AUX_CON0,TS_AUX_FIFO_CLK_EN);
		DRV_TP_ClearBits(TS_ABB_WR_PATH0,TS_AUX_PWDB);
		DRV_TP_ClearBits(TS_ABBA_WR_PATH0,TS_ABBA_AUX_PWDB);

		//DRV_TP_ClearBits(TS_ABB_RSV_CON1,TS_FSM_CTRL_3 | TS_26M_CLK_CTRL_3);
		DRV_TP_ClearBits(TS_ABB_RSV_CON1,TS_FSM_CTRL_3);
		ust_busy_wait(2);
		DRV_TP_ClearBits(TS_ABB_RSV_CON1,TS_26M_CLK_CTRL_3);
		ust_busy_wait(8); //wait 8 us for not frequency enable.
		PDN_SET(PDN_ADC);
		PDN_SET(PDN_TP);
		DRV_TP_ClearBits(TS_ABB_DD_WR_PATH0,TS_AAF_EN);
	}
#endif
	RestoreIRQMask(savedMask);
#else //#ifdef DRV_TP_ADIE_DDIE_STRCUTURE
	volatile kal_uint32 i;
	i = 0;

    while ( (DRV_TP_Reg(AUXADC_CON) & AUXADC_CON_RUN) != 0 )
    {
		i++;
        if (i>=1000)
        {
			break;
		}
	}
#if defined(__OLD_PDN_ARCH__)
#if defined(__OLD_PDN_DEFINE__)
	DRV_TP_WriteReg(DRVPDN_CON1+0x10,(kal_uint16)DRVPDN_CON1_TP);
#elif defined(__APPLICATION_PROCESSOR__)
	DRV_TP_WriteReg(CG_SET0,(kal_uint16)CG_CON0_TP);
#else
	DRV_TP_WriteReg(CG_SET1,(kal_uint16)CG_CON1_TP);
#endif
#else //#if defined(__OLD_PDN_ARCH__)
   PDN_SET(PDN_TP);
#endif //#if defined(__OLD_PDN_ARCH__)
#endif  //#ifdef DRV_TP_ADIE_DDIE_STRCUTURE
	if(!kal_if_hisr())
		kal_prompt_trace(MOD_TP_TASK,"TP_PDN_SET not HISR");
}
#endif

//Mask these define, because we need to use #if  defined(__APPLICATION_PROCESSOR__) in TP_PDN_SET();
//#define TP_PDN_SET		(DRV_TP_WriteReg(DRVPDN_CON1+0x10,(kal_uint16)DRVPDN_CON1_TP))
// We re-define TP_PDN_SET because we shouldn't set PDN bit of TP when AUXADC_CON_RUN bit is set
// AUXADC CON_RUN bit may be set for a while even TP sample is done
//#if defined(TP_PDN_SET)
//#undef TP_PDN_SET
//#endif // #if defined(TP_PDN_SET)
kal_uint16 Ts_dummy_read(void)
{
#ifdef DRV_TS_BUS_EARLY_RESPONSE
	DRV_TP_Reg(AUX_TS_DATA0);
	DRV_TP_Reg(AUX_TS_DATA0);
	DRV_TP_Reg(AUX_TS_DATA0);
#endif
	return 0;
}


void TP_SET_DEBOUNCE(kal_uint16 data)
{
  #ifndef DRV_TP_ADIE_DDIE_STRCUTURE
  DRV_TP_WriteReg(AUX_TS_DEBT,data);
  #else 
  DRV_TP_SetData(AUX_TS_DEBT_STATUS,TS_DEBT_MASK,data);
  #endif
}

kal_uint16 TP_GET_STATUS(void)
{
kal_uint16 tmp=0;

#ifndef DRV_TP_ADIE_DDIE_STRCUTURE
	tmp = DRV_TP_Reg(AUX_TS_CON) & TS_CON_STATUS_MASK;
#else 
	tmp= (DRV_TP_Reg(AUX_TS_DEBT_STATUS))&TS_CON_STATUS_MASK;

#endif
return tmp;
}


#if defined(DRV_MISC_CACHE_REGION_SUPPORT)
  // If cache is supported, put RW, ZI into cahched region
  #pragma arm section rwdata = "CACHEDRW" , zidata = "CACHEDZI"
#endif  // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)



#if defined(DRV_AUX_ADC_TP_MESSED_UP_WA)
#if defined(__READ_TP_DATA_IN_HISR__)
  #if defined(DRV_ADC_TOUCH_SCREEN_BTMT)
  kal_int16  gX, gY;
  #else // #if defined(DRV_ADC_TOUCH_SCREEN_BTMT)
extern kal_int16  gX, gY;
#if defined(__TOUCH_PANEL_MULTITOUCH__)
kal_int16  gXp, gXn, gYp, gYn, gZ1, gZ2;
#endif
			
  #endif // #if defined(DRV_ADC_TOUCH_SCREEN_BTMT)
#ifdef TOUCH_PANEL_PRESSURE
  #if defined(DRV_ADC_TOUCH_SCREEN_BTMT)
  kal_bool gPressureCheck;
  #else // #if defined(DRV_ADC_TOUCH_SCREEN_BTMT)
extern kal_bool gPressureCheck;
extern  kal_uint16 gPressure;
  #endif // #if defined(DRV_ADC_TOUCH_SCREEN_BTMT)
#endif // #ifdef TOUCH_PANEL_PRESSURE
#endif // #if defined(__READ_TP_DATA_IN_HISR__)

#endif // #if defined(DRV_AUX_ADC_TP_MESSED_UP_WA)

//Toy increase TS_DEBOUNCE_TIME for work around the ADC X+ Y+ will shift in the very first
//UI response time and ADC correct location trade-off.
#if defined(DRV_TOUCH_PANEL_CUSTOMER_PARAMETER)
extern  kal_uint32 TS_DEBOUNCE_TIME;
#elif defined(LIBRA35_DEMO_BB) // NOT only Libra35 panel have quality problem
#define  TS_DEBOUNCE_TIME     (36*32)  //36ms
#elif defined(TRULY_HVGA_LCM)
#define  TS_DEBOUNCE_TIME     (48*32)  //48ms
#else
#define  TS_DEBOUNCE_TIME     (10*32)  //10ms
#endif

#if ( defined(DRV_TP_6238_SETTING) || defined(DRV_TP_6235_SETTING)  || defined(DRV_TP_6268_SETTING) || defined(DRV_TP_6253_SETTING))
ECO_VERSION gTPChipECOVersion;		// Indicate the Chip ECO version
#endif // #if ( defined(DRV_TP_6238_SETTING) || defined(DRV_TP_6235_SETTING) )

#if defined(DRV_AUX_ADC_TP_MESSED_UP_WA)
kal_bool gTPPerformADCTPMessedUPWA;		// Indicate whether to perform AUX ADC TP messed up WA
#endif
kal_bool gTPPerformADCUnsableWA;			// Indicate whether to perform ADC unsable WA
kal_bool gTPPerformNoTPUpINTRWA;			// Indicate whether to perform NO TP up intr WA
kal_bool gTPCheckPressueAsState;			// Indicate we need to check pressure value to judge TP is pressed or NOT
													// H/W state register is NOT reliable
// Define to enable check TP level in CB function
// This is a workaround for the chips (MT6235 E1, E2) which has problem on TS_STAT register
// Sometimes up state is NOT real time updated under some specific scenario
void TPUpdateNotify(void);
// Toy add ts_power_down_PENIRQ for avoid: 
// driver sampling and analog IRQ occur at the same time, 
// it will cause ADC thought pen is still down and reset debunce time.
void ts_power_down_PENIRQ(void);
static kal_uint16 ts_read_adc_adc_3835_WA(kal_uint16 pos,kal_bool IsPressure);
kal_bool tp_level(void);
kal_bool tp_state;		// Read back value of TP state
  
//althought not access in ts_drv.c, but it is accessed in touch_panel.c
kal_bool tp_up_intr_lost_flag = KAL_FALSE;/*lint +e552*/	// Indicate if there is TP UP intr missed

#if defined(DRV_ADC_TOUCH_SCREEN_BTMT)
TouchPanelDataStruct TP;
kal_bool    touch_panel_state;
kal_uint32   TP_FILTER_THRESHOLD;
kal_uint32   TP_PRESSURE_THRESHOLD_HIGH;
kal_uint32   TP_PRESSURE_THRESHOLD_LOW;
#else // #if defined(DRV_ADC_TOUCH_SCREEN_BTMT)
extern kal_bool    touch_panel_state;
extern kal_uint32   TP_FILTER_THRESHOLD;
extern kal_uint32   TP_PRESSURE_THRESHOLD_HIGH;
extern kal_uint32   TP_PRESSURE_THRESHOLD_LOW;
#endif // #if defined(DRV_ADC_TOUCH_SCREEN_BTMT)

kal_hisrid ts_hisr;

#if defined(DRV_MISC_CACHE_REGION_SUPPORT)
  // If cache is supported, put RW, ZI into cahched region
  #pragma arm section rwdata, zidata
#endif  // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)


// A function to detect whether TP is touched or NOT
// This function is added after MT6238/MT6235 TP module bug is found

kal_bool tp_level(void)
{
#ifdef DRV_TP_STAT_NOT_UP_TO_DATE_WA
	kal_bool   tppc;
      tppc = tp_pressure_check();
      if(tppc)
         return (kal_bool)touch_down_level;
      else
         return (kal_bool)touch_up_level;

#else // #if ( defined(DRV_TP_6238_SETTING) || defined(DRV_TP_6235_SETTING) )
   //if (DRV_TP_Reg(AUX_TS_CON) & TS_CON_STATUS_MASK) //lxg delete
    if (TP_GET_STATUS())
   {
      return (kal_bool)touch_down_level;
   }
   return (kal_bool)touch_up_level;
#endif // #if ( defined(DRV_TP_6238_SETTING) || defined(DRV_TP_6235_SETTING) )
}

#ifndef DRV_TP_SLIM
kal_bool tp_level_pressure(kal_uint32 *pressure)
{
#ifdef DRV_TP_STAT_NOT_UP_TO_DATE_WA

	kal_bool   tppc;

      tppc = tp_pressure_check_value(pressure);
      if(tppc)
         return (kal_bool)touch_down_level;
      else
         return (kal_bool)touch_up_level;
#else // #if ( defined(DRV_TP_6238_SETTING) || defined(DRV_TP_6235_SETTING) )
   *pressure = tp_pressure_value();//must get correct pressure value
  // if (DRV_TP_Reg(AUX_TS_CON) & TS_CON_STATUS_MASK)
   if (TP_GET_STATUS())
   {
      return (kal_bool)touch_down_level;
   }
   return (kal_bool)touch_up_level;
#endif // #if ( defined(DRV_TP_6238_SETTING) || defined(DRV_TP_6235_SETTING) )
}
#endif //DRV_TP_SLIM

// This function is to set a event to TP task to indicate we are at UP state
// TP task will perform UP Handler after receive the message
// The function is added for TP UP intr missed issue
#ifndef DRV_TP_PENUP_FIXED
void TPUpdateNotify(void)
{

		if (kal_if_hisr())
{
			touch_panel_state = (kal_bool)touch_up_level;
			if (TP.state == DOWN)
{
				drv_trace0(TRACE_GROUP_10, TP_NOT_UP_TO_DATE_NOTIFY);
				TP.state = UP;
               TP.tp_up_cb(NULL);
		}
	}
}
#endif
//******************************************************
// Toy add ts_power_down_PENIRQ() for avoid: 
// driver sampling and analog IRQ occur at the same time, 
// it will cause ADC thought pen is still down and reset debunce time.
//******************************************************
void ts_power_down_PENIRQ(void)
{
	kal_uint16  reg;
#if !defined(__OLD_PDN_ARCH__)
   kal_uint32  status;
#endif //#if defined(__OLD_PDN_ARCH__)


// Power down PENIRQ begin

// we should 1.close the PENIRQ, 2.sampling, 3.enable the PENIRQ
// below operation will close the PENIRQ as step 1.
// and after this function done, the next sampling will sampling first then open PENIRQ(by TS_CMD_PD_YDRV_SH)

  // 0x20 won't trigger data to be sampled, TS_CMD_PD_IRQ_SH=1 means disable IRQ before next sampling
  // althought one DRV_TP_WriteReg, but the execution will be done in sequence.
  reg = 0x20 | TS_CMD_PD_IRQ_SH;
	DRV_TP_WriteReg(AUX_TS_CMD, reg);
	// TS_CON_SPL_TRIGGER=1 trigger sample process without PENIRQ.
	DRV_TP_WriteReg(AUX_TS_CON, TS_CON_SPL_TRIGGER);
	Ts_dummy_read();
	while(TS_CON_SPL_MASK & DRV_TP_Reg(AUX_TS_CON))
	{
#if defined(__OLD_PDN_ARCH__)
#if defined(__OLD_PDN_DEFINE__)
		ASSERT(!(DRV_TP_Reg(DRVPDN_CON1) & (kal_uint16)DRVPDN_CON1_TP));
#endif
#else //#if defined(__OLD_PDN_ARCH__)
      PDN_STATUS(PDN_TP, status, kal_uint32);
      if(status != 0)
        {
            ASSERT(0);
        }
#endif //#if defined(__OLD_PDN_ARCH__)
	}
// Power down PENIRQ end
}
#if !defined(DRV_MISC_TDMA_NO_TIME) //drv_get_current_time() will assert if def TDMA_NO_TIME
#define DEADLOCK_DEBUG
#endif

// This function is only used for MT6238/MT6235
static kal_uint16 ts_read_adc_adc_3835_WA(kal_uint16 pos,kal_bool IsPressure )
{
	kal_uint16  reg;
	kal_uint32 i;
	kal_uint32 sample_count = 1;
#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
	extern kal_uint32   TP_MULTIPLE_POINT_SELECTION;
	kal_uint16 sample[32]={0};
	kal_uint32 j,itmp;
#else
	kal_uint16 sample[3] = {0,0,0};
	kal_uint16 delta12, delta23, delta13;
#endif
#if !defined(DRV_TS_SW_RESET_CHECK_FOR_BUSY_BIT)
	kal_uint32 savedMask;
#endif
#if defined(DEADLOCK_DEBUG)
	kal_uint32 TPWaitSync1;
#endif
#if !defined(__OLD_PDN_ARCH__)
	kal_uint32  status;
#endif //#if defined(__OLD_PDN_ARCH__)

	
	if (gTPPerformADCUnsableWA)
	{
#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
		sample_count = TP_MULTIPLE_POINT_SELECTION;
#else
		sample_count = 3;
#endif
	}

	TP_PDN_CLR();
	Ts_dummy_read();

	if(KAL_TRUE == IsPressure) // measure pressure
	{
		sample_count = 1;
	}
   
	for (i=0;i<sample_count;i++)
	{
		reg = pos|tsModeSelection|tsSampleResolution|TS_CMD_PD_YDRV_SH;
		DRV_TP_WriteReg(AUX_TS_CMD, reg);

#if defined(DRV_AUX_ADC_TP_MESSED_UP_WA)
		if (gTPPerformADCTPMessedUPWA)
		{
#ifdef DRV_TS_SW_RESET_CHECK_FOR_BUSY_BIT
			ts_adc_reset_cnt=0;
#endif
			// We must be in HISR
			// Just polling the AUXADC module state, we can only issue TP sample comamnd when AUXADC module is idle
#if defined(DEADLOCK_DEBUG)
			TPWaitSync1 = drv_get_current_time();
#endif
			
			while (1)
			{
#ifdef DRV_TS_SW_RESET_CHECK_FOR_BUSY_BIT
				if(adc_ready_to_sample())
				{
					DRV_TP_WriteReg(AUX_TS_CON, TS_CON_SPL_TRIGGER);
					break;
				}
#else //#ifdef DRV_TS_SW_RESET_CHECK_FOR_BUSY_BIT
				if((DRV_TP_Reg(AUXADC_CON) & AUXADC_CON_RUN) == 0 )
				{
					savedMask = SaveAndSetIRQMask();
					// Check AUXADC_CON_RUN again to avoid some other ISR preempts
					if ( (DRV_TP_Reg(AUXADC_CON) & AUXADC_CON_RUN) == 0 )
					{
						// Check if any SYNC mode request is issued
                        if ( DRV_TP_Reg(AUXADC_SYNC) == 0 )
                        {
							// No SYNC mode request
							// AUXADC_IMM check can be ignored, 
							// because for IMM mode, write 1 to specific channel will make ADC module 
							// to sample immdediately ==> AUXADC_CON_RUN presents IMMD mode state
							DRV_TP_WriteReg(AUX_TS_CON, TS_CON_SPL_TRIGGER);
							RestoreIRQMask(savedMask);
							break;
                        }
                        else
                        {
							// Means we already issue SYNC mode sample request, 
							// but ADC module is waiting for TDMA event or at WARMUP state
							// We need to avoid issue TP sample request within critical time slot
							// TODO
						}
					}
					RestoreIRQMask(savedMask);
				}
#endif //#ifdef DRV_TS_SW_RESET_CHECK_FOR_BUSY_BIT
#if defined(DEADLOCK_DEBUG)
#ifdef DRV_TS_SW_RESET_CHECK_FOR_BUSY_BIT
				if(drv_get_duration_ms(TPWaitSync1)>15) //>5ms
				{
					TPWaitSync1 = drv_get_current_time();
					ts_adc_reset_cnt++;
					if(ts_adc_reset_cnt==3)
					{
						ts_adc_reset_cnt=0;
						if ( (DRV_TP_Reg(AUXADC_CON) & AUXADC_CON_RUN) == 1 )
						ASSERT(0);
						else
							break;
					}
					adc_sw_reset(tp_reset);
					drv_trace1(TRACE_GROUP_10, TP_ADC_RESET_CNT, ts_adc_reset_cnt);
				}
#else
				// For check whether HW already deadlock.
				ASSERT(drv_get_duration_ms(TPWaitSync1) < 20);
#endif
#endif
			}//while (1)
#ifdef DRV_TS_SW_RESET_CHECK_FOR_BUSY_BIT
			ts_adc_reset_cnt=0;
#endif
		}

		else // if (gTPPerformADCTPMessedUPWA)
#endif
		{
   		DRV_TP_WriteReg(AUX_TS_CON, TS_CON_SPL_TRIGGER);
		}
		Ts_dummy_read();
#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)//sorting then pick the middle 3 point, and average them.
		if(i>1)
		{
			j = i-1;   //when i = 2~(TP_MULTIPLE_POINT_SELECTION-1) do bubble sort
			while(j>0) //bubble sort, sort before polling, gain from useless while() loop
			{
				if(sample[j] < sample[j-1]) //sorting 1 ~ (i-1)
				{
					itmp = sample[j-1];
					sample[j-1] = sample[j];
					sample[j] = itmp;
					j--;
				}
				else
					break;
			}
		}
#endif //#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
#ifdef DRV_TS_SW_RESET_CHECK_FOR_BUSY_BIT
    TPWaitSync1 = drv_get_current_time();
    ts_adc_not_busy = KAL_TRUE;
    ts_adc_reset_cnt = 0;
#endif
   	while(TS_CON_SPL_MASK & DRV_TP_Reg(AUX_TS_CON))
   	{
#ifdef DRV_TS_SW_RESET_CHECK_FOR_BUSY_BIT
			ust_busy_wait(2); //wait 2 us for ADC busy rising.
#endif
#if defined(__OLD_PDN_ARCH__)
#if defined(__OLD_PDN_DEFINE__)
			ASSERT(!(DRV_TP_Reg(DRVPDN_CON1) & (kal_uint16)DRVPDN_CON1_TP));
#else // #if defined(__OLD_PDN_DEFINE__)
			//ASSERT(!(DRV_TP_Reg(DRVPDN_CON1) & (kal_uint16)DRVPDN_CON1_TP));
			// TTTTTT
#endif // #if defined(__OLD_PDN_DEFINE__)
#else //#if defined(__OLD_PDN_ARCH__)
			PDN_STATUS(PDN_TP, status, kal_uint32);
			if(status != 0)
            {
                ASSERT(0);
            }
#endif //#if defined(__OLD_PDN_ARCH__)


#ifdef DRV_TS_SW_RESET_CHECK_FOR_BUSY_BIT
			if(drv_get_duration_ms(TPWaitSync1)>15) //>15ms
			{
				if((TS_CON_SPL_MASK & DRV_TP_Reg(AUX_TS_CON)) == 0)
					break;
				ts_adc_reset_cnt++;
				if(ts_adc_reset_cnt==6)
				{ 
					if((TS_CON_SPL_MASK & DRV_TP_Reg(AUX_TS_CON)) == 1)
						DRV_TP_WriteReg(AUX_TS_CON, 0);//ASSERT(0);
					else 
				{
					ts_adc_reset_cnt=0;
						break;
					}
					}
				//TRY TO RECOVER
				adc_sw_reset(tp_reset);
						DRV_TP_WriteReg(AUX_TS_CON, TS_CON_SPL_TRIGGER);
				ust_busy_wait(2);
				TPWaitSync1 = drv_get_current_time();
				drv_trace0(TRACE_GROUP_10, TP_SPL_BUSY_NOT_RELEASE);
					}
 #endif
							}							
		reg = DRV_TP_Reg(AUX_TS_DATA0);
#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
		//bubble sort last point
		if(i == (sample_count-1) )
		{
			j=i;
			sample[j] = reg;
			while(j>0) //bubble sort, sort before polling, gain from useless while() loop
			{
			   if(sample[j] < sample[j-1]) //sorting 1 ~ (i-1)
			   {
			      itmp = sample[j-1];
			      sample[j-1] = sample[j];
			      sample[j] = itmp;
			      j--;
			   }
			   else
			      break;
			}
		}
		else 
			sample[i] = reg;//prevent the last sorting cover by next sample[i]=reg
#else //#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)

		sample[i] = reg;
#endif //#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
}//for (i=0;i<sample_count;i++)

	TP_PDN_SET();
   
#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
	if (gTPPerformADCUnsableWA)
	{
		j = (TP_MULTIPLE_POINT_SELECTION>>1);
		if(sample_count>2)
			reg = (sample[j-1]+sample[j]+sample[j+1])/3;
		else if(sample_count == 2)
			reg = (sample[0]+sample[1])/2;
		else
			reg = sample[0];
    }
    else
    {
		reg = sample[0];
	}
#else //#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
	if (gTPPerformADCUnsableWA)
	{
		// Check 
		// Delta 1 and 2
        if (sample[0] >= sample[1])
        {
            delta12 = sample[0] - sample[1];
        }
        else
        {
            delta12 = sample[1] - sample[0];
        }
        // Delta 2 and 3
        if (sample[1] >= sample[2])
        {
            delta23 = sample[1] - sample[2];
        }
        else
        {
            delta23 = sample[2] - sample[1];
        }
        // Delta 1 and 3
        if (sample[0] >= sample[2])
        {
            delta13 = sample[0] - sample[2];
        }
        else
        {
            delta13 = sample[2] - sample[0];
        }
        if (delta12 < delta23)
        {
            if (delta12 < delta13)
            {
                // delta12 is min
                reg = (kal_uint16)( (sample[0] + sample[1])/2 );
            }
            else
            {
                // delta13 is min
                reg = (kal_uint16)( (sample[0] + sample[2])/2 );
            }
        }
        else
        {
            if (delta23 < delta13)
            {
                // delta23 is min
                reg = (kal_uint16)( (sample[1] + sample[2])/2 );
            }
            else
            {
                // delta13 is min
                reg = (kal_uint16)( (sample[0] + sample[2])/2 );
            }
        }
    }
    else
    {
        reg = sample[0];
    }
#endif //#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
#if defined(DRV_ADC_SAMPLE_12bIT)
    return reg;
#else
    return (reg<<2);
#endif//#if !defined(DRV_ADC_12bIT)
}
#ifdef DRV_TP_AUXADC_MOVE_TO_ADIE
void ts_write_cmd_spl_bit(kal_uint16 pos)
{
	kal_uint16	reg;
	
	#ifdef DRV_TP_AUXADC_MOVE_TO_ADIE_DEBUG  
	reg = pos|tsModeSelection|tsSampleResolution|TS_CMD_PD_YDRV_SH;
	DRV_TP_WriteReg(AUX_TS_CMD, reg);
	DRV_TP_WriteReg(AUX_TS_CON, TS_CON_SPL_TRIGGER);
	#else
	// trigger spl = 0x8000   magic number = 0x5500
	reg = pos|tsModeSelection|tsSampleResolution|TS_CMD_PD_YDRV_SH|TS_CON_SPL_TRIGGER|TS_CON_MAGIC_NUM;
	DRV_TP_WriteReg(AUX_TS_CMD, reg);
	#endif

}
static kal_uint16 ts_read_adc_adc_in_adie(kal_uint16 pos,kal_bool IsPressure )
{
    kal_uint16  reg;
    kal_uint32 i;
    kal_uint32 sample_count = 7;
	kal_uint32 savedMask;
#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
    extern kal_uint32   TP_MULTIPLE_POINT_SELECTION;
    kal_uint16 sample[32]= {0};
    kal_uint32 j,itmp;
#else
    kal_uint16 sample[3] = {0,0,0};
    kal_uint16 delta12, delta23, delta13;
#endif
#if defined(DEADLOCK_DEBUG)
    kal_uint32 TPWaitSync1;
#endif
#if !defined(__OLD_PDN_ARCH__)
    kal_uint32  status;
#endif //#if defined(__OLD_PDN_ARCH__)

    TP_PDN_CLR();
    Ts_dummy_read();

    if(KAL_TRUE == IsPressure) // measure pressure
    {
        sample_count = 1;
    }

    for (i=0; i<sample_count; i++)
    {
        // We must be in HISR
        // Just polling the AUXADC module state, we can only issue TP sample comamnd when AUXADC module is idle
#if defined(DEADLOCK_DEBUG)
        TPWaitSync1 = drv_get_current_time();
#endif

#ifdef DRV_TS_CHECK_SPL_TO_AVOID_RACE_CONDITON
        while (1)
        {

            if((DRV_TP_Reg(AUXADC_CON) & AUXADC_CON_RUN) == 0 )
            {
                savedMask = SaveAndSetIRQMask();
                // Check AUXADC_CON_RUN again to avoid some other ISR preempts
                if ( (DRV_TP_Reg(AUXADC_CON) & AUXADC_CON_RUN) == 0 )
                {
                    // Check if any SYNC mode request is issued
                    if ( DRV_TP_Reg(AUXADC_SYNC) == 0 )
                    {
                        // No SYNC mode request
                        // AUXADC_IMM check can be ignored,
                        // because for IMM mode, write 1 to specific channel will make ADC module
                        // to sample immdediately ==> AUXADC_CON_RUN presents IMMD mode state
                       // DRV_TP_WriteReg(AUX_TS_CON, TS_CON_SPL_TRIGGER);
                        RestoreIRQMask(savedMask);
                        break;
                    }
                    else
                    {
                        // Means we already issue SYNC mode sample request,
                        // but ADC module is waiting for TDMA event or at WARMUP state
                        // We need to avoid issue TP sample request within critical time slot
                        // TODO
                    }
                }
                RestoreIRQMask(savedMask);
            }

#if defined(DEADLOCK_DEBUG)
            // For check whether HW already deadlock.
            ASSERT(drv_get_duration_ms(TPWaitSync1) < 20);
#endif
        }//while (1)

#else
       // DRV_TP_WriteReg(AUX_TS_CON, TS_CON_SPL_TRIGGER);
#endif
		ts_write_cmd_spl_bit(pos);

        Ts_dummy_read();
#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)//sorting then pick the middle 3 point, and average them.
        if(i>1)
        {
            j = i-1;   //when i = 2~(TP_MULTIPLE_POINT_SELECTION-1) do bubble sort
            while(j>0) //bubble sort, sort before polling, gain from useless while() loop
            {
                if(sample[j] < sample[j-1]) //sorting 1 ~ (i-1)
                {
                    itmp = sample[j-1];
                    sample[j-1] = sample[j];
                    sample[j] = itmp;
                    j--;
                }
                else
                    break;
            }
        }
#endif //#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)


#ifdef DRV_TP_AUXADC_MOVE_TO_ADIE_DEBUG
       while(TS_CON_SPL_MASK & DRV_TP_Reg(AUX_TS_CON))  
        // reg=DRV_TP_Reg(AUX_TS_CON);
      // for(;TS_CON_SPL_MASK & reg;reg=DRV_TP_Reg(AUX_TS_CON))
#else 
	   reg=DRV_TP_Reg(AUX_TS_DATA0);
       for(;TS_CON_SPL_MASK & reg;reg=DRV_TP_Reg(AUX_TS_DATA0))
#endif
		
        {
#if defined(__OLD_PDN_ARCH__)
#if defined(__OLD_PDN_DEFINE__)
            ASSERT(!(DRV_TP_Reg(DRVPDN_CON1) & (kal_uint16)DRVPDN_CON1_TP));
#else // #if defined(__OLD_PDN_DEFINE__)
            //ASSERT(!(DRV_TP_Reg(DRVPDN_CON1) & (kal_uint16)DRVPDN_CON1_TP));
            // TTTTTT
#endif // #if defined(__OLD_PDN_DEFINE__)
#else //#if defined(__OLD_PDN_ARCH__)
            PDN_STATUS(PDN_TP, status, kal_uint32);
            if(status != 0)
            {
                ASSERT(0);
            }
#endif //#if defined(__OLD_PDN_ARCH__)
        }

//deug for 50
		#ifndef DRV_TP_AUXADC_MOVE_TO_ADIE_DEBUG  
        reg = DRV_TP_Reg(AUX_TS_DATA0);
		#else
		reg = reg&TS_DAT0_DAT_MASK;
		#endif
#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
        //bubble sort last point
        if(i == (sample_count-1) )
        {
            j=i;
            sample[j] = reg;
            while(j>0) //bubble sort, sort before polling, gain from useless while() loop
            {
                if(sample[j] < sample[j-1]) //sorting 1 ~ (i-1)
                {
                    itmp = sample[j-1];
                    sample[j-1] = sample[j];
                    sample[j] = itmp;
                    j--;
                }
                else
                    break;
            }
        }
        else
            sample[i] = reg;//prevent the last sorting cover by next sample[i]=reg
#else //#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)

        sample[i] = reg;
#endif //#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
    }//for (i=0;i<sample_count;i++)

    TP_PDN_SET();

#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
    j = (TP_MULTIPLE_POINT_SELECTION>>1);
    if(sample_count>2)
        reg = (sample[j-1]+sample[j]+sample[j+1])/3;
    else if(sample_count == 2)
        reg = (sample[0]+sample[1])/2;
    else
        reg = sample[0];

#else //#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
    if (gTPPerformADCUnsableWA)
    {
        // Check
        // Delta 1 and 2
        if (sample[0] >= sample[1])
        {
			delta12 = sample[0] - sample[1];
        }
        else
        {
			delta12 = sample[1] - sample[0];
		}
		// Delta 2 and 3
        if (sample[1] >= sample[2])
        {
			delta23 = sample[1] - sample[2];
        }
        else
        {
			delta23 = sample[2] - sample[1];
		}
		// Delta 1 and 3
        if (sample[0] >= sample[2])
        {
			delta13 = sample[0] - sample[2];
        }
        else
        {
			delta13 = sample[2] - sample[0];
		}
        if (delta12 < delta23)
        {
            if (delta12 < delta13)
            {
				// delta12 is min
				reg = (kal_uint16)( (sample[0] + sample[1])/2 );
            }
            else
            {
				// delta13 is min
				reg = (kal_uint16)( (sample[0] + sample[2])/2 );
			}
        }
        else
        {
            if (delta23 < delta13)
            {
				// delta23 is min
				reg = (kal_uint16)( (sample[1] + sample[2])/2 );
            }
            else
            {
				// delta13 is min
				reg = (kal_uint16)( (sample[0] + sample[2])/2 );
			}
		}
    }
    else
    {
		reg = sample[0];
	}
#endif //#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
#if defined(DRV_ADC_SAMPLE_12bIT)
	return reg;
#else
	return (reg<<2);
#endif//#if !defined(DRV_ADC_12bIT)
}
#endif

static kal_uint16 ts_read_adc_adc_5060_WA(kal_uint16 pos,kal_bool IsPressure )
{
    kal_uint16  reg;
    kal_uint32 i;
    kal_uint32 sample_count = 7;
#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
    extern kal_uint32   TP_MULTIPLE_POINT_SELECTION;
    kal_uint16 sample[32]= {0};
    kal_uint32 j,itmp;
#else
    kal_uint16 sample[3] = {0,0,0};
    kal_uint16 delta12, delta23, delta13;
#endif
#if !defined(DRV_TS_SW_RESET_CHECK_FOR_BUSY_BIT)
    kal_uint32 savedMask;
#endif
#if defined(DEADLOCK_DEBUG)
    kal_uint32 TPWaitSync1;
#endif
#if !defined(__OLD_PDN_ARCH__)
    kal_uint32  status;
#endif //#if defined(__OLD_PDN_ARCH__)

    TP_PDN_CLR();
    Ts_dummy_read();

    if(KAL_TRUE == IsPressure) // measure pressure
    {
        sample_count = 1;
    }

    for (i=0; i<sample_count; i++)
    {
//        reg = pos|tsModeSelection|tsSampleResolution|TS_CMD_PD_YDRV_SH;
//        DRV_TP_WriteReg(AUX_TS_CMD, reg);

#ifdef DRV_TS_SW_RESET_CHECK_FOR_BUSY_BIT
        ts_adc_reset_cnt=0;
#endif
        // We must be in HISR
        // Just polling the AUXADC module state, we can only issue TP sample comamnd when AUXADC module is idle
#if defined(DEADLOCK_DEBUG)
        TPWaitSync1 = drv_get_current_time();
#endif

#ifdef DRV_TS_CHECK_SPL_TO_AVOID_RACE_CONDITON
        while (1)
        {

#ifdef DRV_TS_SW_RESET_CHECK_FOR_BUSY_BIT
            if(adc_ready_to_sample())
            {
               // DRV_TP_WriteReg(AUX_TS_CON, TS_CON_SPL_TRIGGER);
                break;
            }
#else //#ifdef DRV_TS_SW_RESET_CHECK_FOR_BUSY_BIT
            if((DRV_TP_Reg(AUXADC_CON) & AUXADC_CON_RUN) == 0 )
            {
                savedMask = SaveAndSetIRQMask();
                // Check AUXADC_CON_RUN again to avoid some other ISR preempts
                if ( (DRV_TP_Reg(AUXADC_CON) & AUXADC_CON_RUN) == 0 )
                {
                    // Check if any SYNC mode request is issued
                    if ( DRV_TP_Reg(AUXADC_SYNC) == 0 )
                    {
                        // No SYNC mode request
                        // AUXADC_IMM check can be ignored,
                        // because for IMM mode, write 1 to specific channel will make ADC module
                        // to sample immdediately ==> AUXADC_CON_RUN presents IMMD mode state
                        DRV_TP_WriteReg(AUX_TS_CON, TS_CON_SPL_TRIGGER);
                        RestoreIRQMask(savedMask);
                        break;
                    }
                    else
                    {
                        // Means we already issue SYNC mode sample request,
                        // but ADC module is waiting for TDMA event or at WARMUP state
                        // We need to avoid issue TP sample request within critical time slot
                        // TODO
                    }
                }
                RestoreIRQMask(savedMask);
            }
#endif //#ifdef DRV_TS_SW_RESET_CHECK_FOR_BUSY_BIT
#if defined(DEADLOCK_DEBUG)
#ifdef DRV_TS_SW_RESET_CHECK_FOR_BUSY_BIT
            if(drv_get_duration_ms(TPWaitSync1)>15) //>5ms
            {
                TPWaitSync1 = drv_get_current_time();
                ts_adc_reset_cnt++;
                if(ts_adc_reset_cnt==3)
                {
                    ts_adc_reset_cnt=0;
                    if ( (DRV_TP_Reg(AUXADC_CON) & AUXADC_CON_RUN) == 1 )
                        ASSERT(0);
                    else
                        break;
                }
                adc_sw_reset(tp_reset);
                drv_trace1(TRACE_GROUP_10, TP_ADC_RESET_CNT, ts_adc_reset_cnt);
            }
#else
            // For check whether HW already deadlock.
            ASSERT(drv_get_duration_ms(TPWaitSync1) < 20);
#endif
#endif
        }//while (1)

#ifdef DRV_TS_SW_RESET_CHECK_FOR_BUSY_BIT
        ts_adc_reset_cnt=0;
#endif

#else
        DRV_TP_WriteReg(AUX_TS_CON, TS_CON_SPL_TRIGGER);
#endif
		reg = pos|tsModeSelection|tsSampleResolution|TS_CMD_PD_YDRV_SH;
		DRV_TP_WriteReg(AUX_TS_CMD, reg);
		
		DRV_TP_WriteReg(AUX_TS_CON, TS_CON_SPL_TRIGGER);
        Ts_dummy_read();
#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)//sorting then pick the middle 3 point, and average them.
        if(i>1)
        {
            j = i-1;   //when i = 2~(TP_MULTIPLE_POINT_SELECTION-1) do bubble sort
            while(j>0) //bubble sort, sort before polling, gain from useless while() loop
            {
                if(sample[j] < sample[j-1]) //sorting 1 ~ (i-1)
                {
                    itmp = sample[j-1];
                    sample[j-1] = sample[j];
                    sample[j] = itmp;
                    j--;
                }
                else
                    break;
            }
        }
#endif //#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
#ifdef DRV_TS_SW_RESET_CHECK_FOR_BUSY_BIT
        TPWaitSync1 = drv_get_current_time();
        ts_adc_not_busy = KAL_TRUE;
        ts_adc_reset_cnt = 0;
#endif
        while(TS_CON_SPL_MASK & DRV_TP_Reg(AUX_TS_CON))
        {
#ifdef DRV_TS_SW_RESET_CHECK_FOR_BUSY_BIT
            ust_busy_wait(2); //wait 2 us for ADC busy rising.
#endif
#if defined(__OLD_PDN_ARCH__)
#if defined(__OLD_PDN_DEFINE__)
            ASSERT(!(DRV_TP_Reg(DRVPDN_CON1) & (kal_uint16)DRVPDN_CON1_TP));
#else // #if defined(__OLD_PDN_DEFINE__)
            //ASSERT(!(DRV_TP_Reg(DRVPDN_CON1) & (kal_uint16)DRVPDN_CON1_TP));
            // TTTTTT
#endif // #if defined(__OLD_PDN_DEFINE__)
#else //#if defined(__OLD_PDN_ARCH__)
            PDN_STATUS(PDN_TP, status, kal_uint32);
            if(status != 0)
            {
                ASSERT(0);
            }
#endif //#if defined(__OLD_PDN_ARCH__)


#ifdef DRV_TS_SW_RESET_CHECK_FOR_BUSY_BIT
            if(drv_get_duration_ms(TPWaitSync1)>15) //>15ms
            {
                if((TS_CON_SPL_MASK & DRV_TP_Reg(AUX_TS_CON)) == 0)
                    break;
                ts_adc_reset_cnt++;
                if(ts_adc_reset_cnt==6)
                {
                    if((TS_CON_SPL_MASK & DRV_TP_Reg(AUX_TS_CON)) == 1)
                        DRV_TP_WriteReg(AUX_TS_CON, 0);//ASSERT(0);
                    else
                    {
                        ts_adc_reset_cnt=0;
                        break;
                    }
                }
                //TRY TO RECOVER
                adc_sw_reset(tp_reset);
                DRV_TP_WriteReg(AUX_TS_CON, TS_CON_SPL_TRIGGER);
                ust_busy_wait(2);
                TPWaitSync1 = drv_get_current_time();
                drv_trace0(TRACE_GROUP_10, TP_SPL_BUSY_NOT_RELEASE);
            }
#endif
        }
        reg = DRV_TP_Reg(AUX_TS_DATA0);
#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
        //bubble sort last point
        if(i == (sample_count-1) )
        {
            j=i;
            sample[j] = reg;
            while(j>0) //bubble sort, sort before polling, gain from useless while() loop
            {
                if(sample[j] < sample[j-1]) //sorting 1 ~ (i-1)
                {
                    itmp = sample[j-1];
                    sample[j-1] = sample[j];
                    sample[j] = itmp;
                    j--;
                }
                else
                    break;
            }
        }
        else
            sample[i] = reg;//prevent the last sorting cover by next sample[i]=reg
#else //#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)

        sample[i] = reg;
#endif //#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
    }//for (i=0;i<sample_count;i++)

    TP_PDN_SET();

#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
    j = (TP_MULTIPLE_POINT_SELECTION>>1);
    if(sample_count>2)
        reg = (sample[j-1]+sample[j]+sample[j+1])/3;
    else if(sample_count == 2)
        reg = (sample[0]+sample[1])/2;
    else
        reg = sample[0];

#else //#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
    if (gTPPerformADCUnsableWA)
    {
        // Check
        // Delta 1 and 2
        if (sample[0] >= sample[1])
        {
            delta12 = sample[0] - sample[1];
        }
        else
        {
            delta12 = sample[1] - sample[0];
        }
        // Delta 2 and 3
        if (sample[1] >= sample[2])
        {
            delta23 = sample[1] - sample[2];
        }
        else
        {
            delta23 = sample[2] - sample[1];
        }
        // Delta 1 and 3
        if (sample[0] >= sample[2])
        {
            delta13 = sample[0] - sample[2];
        }
        else
        {
            delta13 = sample[2] - sample[0];
        }
        if (delta12 < delta23)
        {
            if (delta12 < delta13)
            {
                // delta12 is min
                reg = (kal_uint16)( (sample[0] + sample[1])/2 );
            }
            else
            {
                // delta13 is min
                reg = (kal_uint16)( (sample[0] + sample[2])/2 );
            }
        }
        else
        {
            if (delta23 < delta13)
            {
                // delta23 is min
                reg = (kal_uint16)( (sample[1] + sample[2])/2 );
            }
            else
            {
                // delta13 is min
                reg = (kal_uint16)( (sample[0] + sample[2])/2 );
            }
        }
    }
    else
    {
        reg = sample[0];
    }
#endif //#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
#if defined(DRV_ADC_SAMPLE_12bIT)
    return reg;
#else
    return (reg<<2);
#endif//#if !defined(DRV_ADC_12bIT)
}
kal_uint16  ts_read_adc_multiple_average(kal_uint16 pos, kal_bool IsPressure )
{
	kal_uint16  reg;
	kal_uint32 i;
	kal_uint32 sample_count = 1;
	extern kal_uint32   TP_MULTIPLE_POINT_SELECTION;
	kal_uint16 sample[32]={0};
	kal_uint32 j,itmp;
#if !defined(__OLD_PDN_ARCH__)
   kal_uint32  status;
#endif //#if defined(__OLD_PDN_ARCH__)
	
	sample_count = TP_MULTIPLE_POINT_SELECTION;

	if(KAL_TRUE == IsPressure) // measure pressure
	 {
	  sample_count = 1;
	 }

	TP_PDN_CLR();
	for (i=0;i<sample_count;i++)
	{
		reg = pos|tsModeSelection|tsSampleResolution|TS_CMD_PD_YDRV_SH;
		DRV_TP_WriteReg(AUX_TS_CMD, reg);
		DRV_TP_WriteReg(AUX_TS_CON, TS_CON_SPL_TRIGGER);

	Ts_dummy_read();

	if(i>1)
	{
		j = i-1;   //when i = 2~(TP_MULTIPLE_POINT_SELECTION-1) do bubble sort
		while(j>0) //bubble sort, sort before polling, gain from useless while() loop
		{
			if(sample[j] < sample[j-1]) //sorting 1 ~ (i-1)
			{
				itmp = sample[j-1];
				sample[j-1] = sample[j];
				sample[j] = itmp;
				j--;
			}
			else
			break;
		}
	}
   
		while(TS_CON_SPL_MASK & DRV_TP_Reg(AUX_TS_CON))
		{
#if defined(__OLD_PDN_ARCH__)
#if defined(__OLD_PDN_DEFINE__)
			ASSERT(!(DRV_TP_Reg(DRVPDN_CON1) & (kal_uint16)DRVPDN_CON1_TP));
#else // #if defined(__OLD_PDN_DEFINE__)
			//ASSERT(!(DRV_TP_Reg(DRVPDN_CON1) & (kal_uint16)DRVPDN_CON1_TP));
			// TTTTTT
#endif // #if defined(__OLD_PDN_DEFINE__)
#else //#if defined(__OLD_PDN_ARCH__)
			PDN_STATUS(PDN_TP, status, kal_uint32);
			if(status != 0)
            {
                ASSERT(0);
            }
#endif //#if defined(__OLD_PDN_ARCH__)
		}
   
		reg = DRV_TP_Reg(AUX_TS_DATA0);
		//bubble sort last point
      if(i == (sample_count-1) )
		{
			j=i;
			sample[j] = reg;
			while(j>0) //bubble sort, sort before polling, gain from useless while() loop
			{
				if(sample[j] < sample[j-1]) //sorting 1 ~ (i-1)
				{
					itmp = sample[j-1];
					sample[j-1] = sample[j];
					sample[j] = itmp;
					j--;
				}
				else
					break;
			}
		}
		else 
			sample[i] = reg;//prevent the last sorting cover by next sample[i]=reg
	}
	TP_PDN_SET();
	j = (TP_MULTIPLE_POINT_SELECTION>>1);
	  if(sample_count>2)
	reg = (sample[j-1]+sample[j]+sample[j+1])/3;
	  else if(sample_count == 2)
		reg = (sample[0]+sample[1])/2;
	  else
	  	reg = sample[0];

#if defined(DRV_ADC_SAMPLE_12bIT)
   return reg;
#else
   return (reg<<2);
#endif//#if !defined(DRV_ADC_12bIT)}
}

kal_uint16  ts_read_adc(kal_uint16 pos,kal_bool IsPressure)
{
	if(!ts_power_on)
		return 0;
#ifdef DRV_TP_AUXADC_MOVE_TO_ADIE
	return ts_read_adc_adc_in_adie(pos,IsPressure);		  
#elif defined(DRV_TP_SLIM)
return ts_read_adc_adc_5060_WA(pos,IsPressure);

#elif ( defined(DRV_TP_6238_SETTING) || defined(DRV_TP_6235_SETTING) || defined(DRV_TP_6268_SETTING) || defined(DRV_TP_6253_SETTING))
	// We have a special sample function for MT6238/MT6235
	return ts_read_adc_adc_3835_WA(pos,IsPressure);
#elif defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
	return ts_read_adc_multiple_average(pos,IsPressure);
#else // #if ( defined(DRV_TP_6238_SETTING) || defined(DRV_TP_6235_SETTING) )

#if !defined(__OLD_PDN_ARCH__)
   kal_uint32  status;
#endif //#if defined(__OLD_PDN_ARCH__)
	// Generic internal TP sample function
	kal_uint16  reg;
	TP_PDN_CLR(); 
	reg = pos|tsModeSelection|tsSampleResolution|TS_CMD_PD_YDRV_SH;
	DRV_TP_WriteReg(AUX_TS_CMD, reg);

	DRV_TP_WriteReg(AUX_TS_CON, TS_CON_SPL_TRIGGER);

	Ts_dummy_read();

	while(TS_CON_SPL_MASK & DRV_TP_Reg(AUX_TS_CON))
	{
#if defined(__OLD_PDN_ARCH__)
#if defined(__OLD_PDN_DEFINE__)		
		ASSERT(!(DRV_TP_Reg(DRVPDN_CON1) & (kal_uint16)DRVPDN_CON1_TP));
#else // #if defined(__OLD_PDN_DEFINE__)		
		// TODO
#endif // #if defined(__OLD_PDN_DEFINE__)		
#else //#if defined(__OLD_PDN_ARCH__)
      PDN_STATUS(PDN_TP, status, kal_uint32);
      if(status != 0)
        {
            ASSERT(0);
        }
#endif //#if defined(__OLD_PDN_ARCH__)
	}
   
	reg = DRV_TP_Reg(AUX_TS_DATA0);
	
	TP_PDN_SET();
#if defined(DRV_ADC_SAMPLE_12bIT)
	return reg;
#else
	return (reg<<2);
#endif //#if !defined(DRV_ADC_SAMPLE_12bIT)	
	
#endif // #if ( defined(DRV_TP_6238_SETTING) || defined(DRV_TP_6235_SETTING) )
	
}

void tp_read_adc(kal_uint16 *x, kal_uint16 *y)
{
#define TOTAL_CNT    1
   kal_uint8 retry;        
   kal_uint16 temp_x=0, temp_y=0;
   kal_int16 diff_x=0, diff_y=0;
   
   for(retry=0;retry<TOTAL_CNT;retry++)
   {
      /*Y ADC*/
      *y=ts_read_adc(TS_CMD_ADDR_Y, KAL_FALSE);
   
      /*X ADC*/
      *x=ts_read_adc(TS_CMD_ADDR_X, KAL_FALSE);
// Please remove below switch method after JADE36 V1 phase out.
#if defined(JADE36_DEMO_BB) //Jade36 V1 tp layout problem. 
      temp_x = *y;
      *y = 4096 - *x;
      *x = temp_x;
#endif 
// Please remove above switch method after JADE36 V1 phase out.
      if(temp_x==0&&temp_y==0)
      {
         temp_x=*x;
         temp_y=*y;
      }
      else
      {
         diff_x=temp_x-*x;
         diff_y=temp_y-*y;
         if(diff_x>TP_FILTER_THRESHOLD||diff_x<-TP_FILTER_THRESHOLD
            ||diff_y>TP_FILTER_THRESHOLD||diff_y<-TP_FILTER_THRESHOLD)
         {
            temp_x=*x;
            temp_y=*y;
            *x=4095;                  
            *y=4095;            
         }
         else
         {
         	if(*x!=4095&&*y!=4095)
            	return;
         }                        
      }
   }
}

#ifdef TOUCH_PANEL_PRESSURE


kal_bool tp_pressure_check(void)
{
   
   kal_uint8 retry;        
   kal_uint16 x, z1, z2;
   kal_uint32 pressure = 0;
   
   for(retry=0;retry<1/*TOUCH_PANEL_RETRY*/;retry++)
   {
      /*X ADC*/
      x=ts_read_adc(TS_CMD_ADDR_X,KAL_TRUE);

      /*Z1 ADC*/
      z1=ts_read_adc(TS_CMD_ADDR_Z1,KAL_TRUE);

      /*Z2 ADC*/
      z2=ts_read_adc(TS_CMD_ADDR_Z2,KAL_TRUE);
      if((z1 > 0) && (z2 > z1))
      {
         pressure = (kal_uint32)(x*(z2-z1)/z1) >> 2; /* Rx*x/4096*(z2/z1 - 1), assume Rx=1024 */
         
         drv_trace4(TRACE_GROUP_10, TP_PRESSURE_VALUE, pressure, x, z1, z2);
            if ((pressure > TP_PRESSURE_THRESHOLD_HIGH) || (pressure < TP_PRESSURE_THRESHOLD_LOW))
            {
         	drv_trace1(TRACE_GROUP_10, TP_PRESSURE_RESULT, 0);
            return KAL_FALSE; 
            }
            else
            {
         	drv_trace1(TRACE_GROUP_10, TP_PRESSURE_RESULT, 1);
            return KAL_TRUE; 
         }
      } //if((z1 > 0) && (z2 > z1))
#if defined(__TOUCH_PANEL_MULTITOUCH__)
      else if((z1 > 0) && (z2 <= z1)) //for 1/3 may measure z2<z1
      {
         pressure = TP_PRESSURE_THRESHOLD_LOW+1;
         drv_trace4(TRACE_GROUP_10, TP_PRESSURE_VALUE, pressure, x, z1, z2);
         return KAL_TRUE;
      }
#endif
   }

	drv_trace4(TRACE_GROUP_10, TP_PRESSURE_VALUE, pressure, x, z1, z2);
	drv_trace1(TRACE_GROUP_10, TP_PRESSURE_RESULT, 0);
   
   return KAL_FALSE;
}


kal_uint32 tp_pressure_value(void)
{
   kal_uint16 x, z1, z2;
   kal_uint32 pressure = 0;
   
   /*X ADC*/
   x=ts_read_adc(TS_CMD_ADDR_X,KAL_TRUE);

   /*Z1 ADC*/
   z1=ts_read_adc(TS_CMD_ADDR_Z1,KAL_TRUE);

   /*Z2 ADC*/
   z2=ts_read_adc(TS_CMD_ADDR_Z2,KAL_TRUE);
   if((z1 > 0) && (z2 > z1))
   {
      pressure = (kal_uint32)(x*(z2-z1)/z1) >> 2; /* Rx*x/4096*(z2/z1 - 1), assume Rx=1024 */
   }
#if defined(__TOUCH_PANEL_MULTITOUCH__)
   else if((z1 > 0) && (z2 <= z1)) //for 1/3 may measure z2<z1
   {
      pressure = TP_PRESSURE_THRESHOLD_LOW+1;
   }
#endif
   drv_trace4(TRACE_GROUP_10, TP_PRESSURE_VALUE, pressure, x, z1, z2);
   return pressure;
}
#endif /*TOUCH_PANEL_PRESSURE*/
kal_bool tp_pressure_check_value(kal_uint32 *pressure)
{
    *pressure = tp_pressure_value();
    if ((*pressure > TP_PRESSURE_THRESHOLD_HIGH) || (*pressure < TP_PRESSURE_THRESHOLD_LOW))
    {
        drv_trace1(TRACE_GROUP_10, TP_PRESSURE_RESULT, 0);
        return KAL_FALSE;
    }
    else
    {
        drv_trace1(TRACE_GROUP_10, TP_PRESSURE_RESULT, 1);
        return KAL_TRUE;
    }
//   drv_trace1(TRACE_GROUP_10, TP_PRESSURE_RESULT, 0);
    //return KAL_FALSE;//Warning:  #111-D: statement is unreachable
}
void tp_set_cmd_para(kal_uint32 sr, kal_uint32 ms)
{
	switch(sr)
	{
	   case 0://DCL_TS_CMD_DIFFERENTIAL
	      tsSampleResolution = TS_CMD_DIFFERENTIAL;
	   break;
	   case 1://DCL_TS_CMD_SINGLE_END
	      tsSampleResolution = TS_CMD_SINGLE_END;
	   break;
	   default:
	   break;   
   }
	switch(ms)
	{
	   case 2://DCL_TS_CMD_MODE_8BIT
	      tsModeSelection = TS_CMD_MODE_8BIT;
	   break;
	   case 3://DCL_TS_CMD_MODE_10BIT
	      tsModeSelection = TS_CMD_MODE_10BIT;
	   break;
	   default:
	   break;   
   }
}
#ifndef DRV_TP_SLIM
void tp_irq_enable(kal_bool on)
{
}    
#endif 
void TS_LISR(void)
{
   IRQMask(IRQ_TS_CODE);
   //kal_activate_hisr(ts_hisr);
   drv_active_hisr(DRV_AUXADC_HISR_ID);
}

void TS_HISR(void)
{
	//kal_uint16 status;
//#define DRV_TP_STATIS_DELAY
kal_uint32 tmp_pressure;
#if defined(__READ_TP_DATA_IN_HISR__)
		kal_uint16 tmpX, tmpY;
#endif // #if defined(__READ_TP_DATA_IN_HISR__)

drv_trace1(TRACE_GROUP_10, TS_HISR_START,  ust_get_current_time());
SLA_CustomLogging("HIR",1);
  //toy add gTPCheckPressueAsState for prevent both TS_HISR & TPUpdateNotify execute kal_set_eg_events, it will trigger up_handler twice
#ifdef DRV_TP_STAT_NOT_UP_TO_DATE_WA
		// For different chips, have different level decision method
		// We put the detail check for each chip in tp_level() for code readness
#ifndef DRV_TP_SLIM
		tp_state = tp_level();
#else
    tp_state =tp_pressure_check_value(&tmp_pressure);
    tp_state = (tp_state == KAL_TRUE) ? touch_down_level : touch_up_level;
#endif

		if(tp_state == touch_down_level)
		{
			//DRV_TP_WriteReg(AUX_TS_DEBT, 10*32);
			TP_SET_DEBOUNCE(10*32);
		}
		else
		{
		     // DRV_TP_WriteReg(AUX_TS_DEBT, TS_DEBOUNCE_TIME);
		    TP_SET_DEBOUNCE(TS_DEBOUNCE_TIME);
		}
		// If the current S/W stat flag is same as read back H/W state, it means we lost one intr
    if (tp_state == touch_panel_state)
    {
			// This means we lost interrupt
        if (touch_panel_state == (kal_bool)touch_down_level)
        {
				// We lost UP intr
				// Need to set a flag to indicate we lost up flag
				tp_up_intr_lost_flag = KAL_TRUE;
				drv_trace0(TRACE_GROUP_10, TP_UP_INTR_LOST);
        }
        else
        {
				// We lost Down intr
				// It is OK, we just pretend the paired (down -> up) intr never came
				IRQClearInt(IRQ_TS_CODE);
				IRQUnmask(IRQ_TS_CODE);
				#if defined(DRV_TP_PENUP_FIXED)
				drv_trace0(TRACE_GROUP_10, TP_HISR_UP);
				#else
				drv_trace0(TRACE_GROUP_10, TP_DOWN_INTR_LOST);
				#endif
                          drv_trace1(TRACE_GROUP_10, TS_HISR_END,  ust_get_current_time());
			SLA_CustomLogging("HIR",0);	
				return;
			}
    }
    else
    {
			// Update TP state
			touch_panel_state = tp_state;
		}

#else
		// For other chips which do NOT have AUXADC TP messed up issue
		//if (DRV_TP_Reg(AUX_TS_CON) & TS_CON_STATUS_MASK)
		 if (TP_GET_STATUS())
		{
	         touch_panel_state = (kal_bool)touch_down_level;
		}
    else
    {
        touch_panel_state = (kal_bool)touch_up_level;
	}

#endif

   if (touch_panel_state==(kal_bool)touch_down_level)/*low*/
   {
   	
#if defined(__READ_TP_DATA_IN_HISR__)
			tp_read_adc(&tmpX, &tmpY);
			gX = (kal_int16)tmpX;
			gY = (kal_int16)tmpY;
			#if defined(__PORTRAIT_LCM_SIMULATE_LANDSCAPE_LCM__) || defined(__LCM_SCANLINE_ROTATION_SUPPORT__)
			{
				// Swap X-axis and Y-axis ADC value for Portrait LCM simuates Landscape LCM
				// For this condition, driver reports X-axis coordinate value by refering TP Y-axis ADC value
				//                     driver reports Y-axis coordinate value by refering TP X-axis ADC value
				kal_int16 swap_temp;
				swap_temp = gX;
				gX = gY;
				gY = swap_temp;
			}
			#endif // #if defined(__PORTRAIT_LCM_SIMULATE_LANDSCAPE_LCM__)
#if defined(__TOUCH_PANEL_MULTITOUCH__)
			gXp = ts_read_adc(TS_CMD_ADDR_X,  KAL_FALSE);
			gXn = ts_read_adc(TS_CMD_ADDR_XN, KAL_FALSE);
			gYp = ts_read_adc(TS_CMD_ADDR_Y,  KAL_FALSE);
			gYn = ts_read_adc(TS_CMD_ADDR_YN, KAL_FALSE);
			gZ1 = ts_read_adc(TS_CMD_ADDR_Z1, KAL_FALSE);
			gZ2 = ts_read_adc(TS_CMD_ADDR_Z2, KAL_FALSE);
#endif

#ifdef TOUCH_PANEL_PRESSURE
#ifndef DRV_TP_SLIM
                    gPressure = (kal_uint16)tp_pressure_value();
			gPressureCheck = tp_pressure_check();
#else
        gPressureCheck= tp_pressure_check_value((kal_uint32*)&gPressure);
#endif
#endif // #ifdef TOUCH_PANEL_PRESSURE
#endif // #if defined(__READ_TP_DATA_IN_HISR__)

    TP.state=DOWN; 
    TP.tp_down_cb(NULL);  
       
   }
   else
   {
          TP.state=UP;
          TP.tp_up_cb(NULL);  
  
   }
   
	IRQClearInt(IRQ_TS_CODE);
	IRQUnmask(IRQ_TS_CODE);
        drv_trace1(TRACE_GROUP_10, TS_HISR_END,  ust_get_current_time());
	SLA_CustomLogging("HIR",0);
}
#if defined(DRV_ADC_SAMPLE_12bIT)
void ts_set_spl_num_(kal_uint32 SPLNum)
{
    if(AUX_SPL_NUM == 0)
        return;
    SPLNum = (SPLNum<<AUX_SPL_NUM_SHIFT) | (DRV_TP_Reg(AUX_SPL_NUM)&(~AUX_SPL_NUM_MASK));
    DRV_TP_WriteReg(AUX_SPL_NUM, SPLNum);
    return;
}
#endif
void ts_drv_init(void)
{
   volatile kal_uint16  x;
#if defined(DRV_TP_ADC_WARM_UP_ISSUE_WA)
   kal_uint16 tmp;
#endif // #if defined(DRV_TP_ADC_WARM_UP_ISSUE_WA)

#if defined(DRV_ADC_SAMPLE_12bIT)
   ts_set_spl_num_(0x1c); //set spl time as 28+4T
#endif  
   if (ts_hisr == NULL)
   {
      //ts_hisr = kal_create_hisr("TS_HISR",2,512,TS_HISR,NULL);
      ts_hisr=(void*)0x1234;
      DRV_Register_HISR(DRV_AUXADC_HISR_ID, TS_HISR);
      ts_tcs_off_gpt_handle=DclSGPT_Open(DCL_GPT_CB,0);
   }
   #if defined(DRV_TS_USE_SINGLE_END_MODE)
	if((INT_SW_SecVersion())== SW_SEC_0 )
		tsSampleResolution = TS_CMD_SINGLE_END;  //just singal end mode can work 
   #endif
// If MT6238 or MT6235, we need to check ECO version
#if ( defined(DRV_TP_6238_SETTING) || defined(DRV_TP_6235_SETTING)  || defined(DRV_TP_6268_SETTING) || defined(DRV_TP_6253_SETTING))
	gTPChipECOVersion = INT_ecoVersion();
	// not check version anymore, apply in all version.
		gTPCheckPressueAsState = KAL_TRUE;
#endif // #if ( defined(DRV_TP_6238_SETTING) || defined(DRV_TP_6235_SETTING) )

#if defined(DRV_AUX_ADC_TP_MESSED_UP_WA)
	// Check which ECO version apply the WA
	#if defined (DRV_TP_6238_SETTING)
    if ( (gTPChipECOVersion == ENG_E1) || (gTPChipECOVersion == ENG_E2) )
    {
		gTPPerformADCTPMessedUPWA = KAL_TRUE;
	}
	// Check which ECO version apply the WA
	#elif defined (DRV_TP_6235_SETTING)
    if ( (gTPChipECOVersion == ECO_E1) || (gTPChipECOVersion == ECO_E2) )
    {
		gTPPerformADCTPMessedUPWA = KAL_TRUE;
	}
	#elif (defined (DRV_TP_6268_SETTING) || defined(DRV_TP_6253_SETTING))
	  gTPPerformADCTPMessedUPWA = KAL_TRUE;
	#endif // #if defined (DRV_TP_6268_SETTING)
#endif // #if defined(DRV_AUX_ADC_TP_MESSED_UP_WA)
	
#if defined(DRV_TP_STAT_NOT_UP_TO_DATE_WA)
	// not check version anymore, apply in all version.
		gTPPerformNoTPUpINTRWA = KAL_TRUE;
#endif // #if defined(DRV_TP_STAT_NOT_UP_TO_DATE_WA)
	
#if ( defined (DRV_TP_6238_SETTING) || defined (DRV_TP_6235_SETTING)  || defined(DRV_TP_6268_SETTING) ||defined(DRV_TP_6253_SETTING))
	gTPPerformADCUnsableWA = KAL_TRUE;
#endif // #if ( defined (DRV_TP_6238_SETTING) || defined (DRV_TP_6235_SETTING) )
#if !defined(IC_MODULE_TEST)
   x=ts_read_adc(TS_CMD_ADDR_X,KAL_FALSE);
#endif
   x = DRV_TP_Reg(AUX_TS_CON);
  // if (x & TS_CON_STATUS_MASK)
   if (TP_GET_STATUS())
      touch_panel_state=(kal_bool)touch_down_level;
   else
      touch_panel_state=(kal_bool)touch_up_level;
      
#if defined(DRV_AUX_ADC_TP_MESSED_UP_WA)
#if !defined(IC_MODULE_TEST)
#ifndef DRV_TP_SLIM
	touch_panel_state = tp_level();
#endif
#endif
#endif //#if defined(DRV_AUX_ADC_TP_MESSED_UP_WA)
	
   
#if defined(DRV_TP_ADC_WARM_UP_ISSUE_WA)
// MT6235 E4, MT6238 E3, MT6268A E1 has ADC warm up register cause TP failed issue
// Need to disable warm up to make TP sample work
	tmp =DRV_TP_Reg(AUXADC_CON);
	tmp &= ~AUXADC_CON_PUWAIT_EN;
	DRV_TP_WriteReg(AUXADC_CON,tmp);
#endif // #if defined(DRV_TP_ADC_WARM_UP_ISSUE_WA)
   //DRV_TP_WriteReg(AUX_TS_DEBT, TS_DEBOUNCE_TIME);
   TP_SET_DEBOUNCE(TS_DEBOUNCE_TIME);

   //DRV_TP_WriteReg(AUX_TS_CMD, TS_CMD_PD_IRQ_SH);
   IRQ_Register_LISR(IRQ_TS_CODE, TS_LISR,"TS Handler");
   IRQSensitivity(IRQ_TS_CODE,EDGE_SENSITIVE);
   IRQUnmask(IRQ_TS_CODE);  
   
}

#if defined(DRV_TP_NO_EXT_EINT)
void ts_mask_int(void)
{
   IRQMask(IRQ_TS_CODE);
}

void ts_unmask_int(void)
{
   IRQClearInt(IRQ_TS_CODE);
   IRQUnmask(IRQ_TS_CODE);
}
#endif //#if defined(DRV_TP_NO_EXT_EINT)

void ts_tsc_off_cb(void *parameter)
{
	volatile kal_uint16	reg;
	kal_uint16  data;
	data = (kal_uint16)parameter;
#if defined(DRV_TP_AUXADC_MOVE_TO_ADIE)
	 ts_read_adc_adc_in_adie(data, KAL_TRUE);		  
#elif defined(DRV_TP_SLIM)
 ts_read_adc_adc_5060_WA(data, KAL_TRUE);
#elif ( defined(DRV_TP_6238_SETTING) || defined(DRV_TP_6235_SETTING) || defined(DRV_TP_6268_SETTING) || defined(DRV_TP_6253_SETTING))
	// We have a special sample function for MT6238/MT6235
	 ts_read_adc_adc_3835_WA(data, KAL_TRUE);
#elif defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
	 ts_read_adc_multiple_average(data, KAL_TRUE);
#endif

	if(data == 0x10)//TSC power on
	{
		ts_power_on = KAL_TRUE;
		touch_panel_enable_(KAL_TRUE); //toy add for avoid reset mask IRQ
	}
	else //TSC power down
	{
#ifndef DRV_TP_SLIM
		TP_PDN_SET_ON_BACKLIGHT_OFF();
#endif
	}
}
		
void ts_tcs_off_(kal_bool enable)
{
	SGPT_CTRL_START_T start;
		
	IRQMask(IRQ_GPT_CODE);
	DclSGPT_Control(ts_tcs_off_gpt_handle,SGPT_CMD_STOP,0);
	IRQUnmask(IRQ_GPT_CODE);
	start.pfCallback=ts_tsc_off_cb;
	if(enable == KAL_TRUE) //TSC power on
	{
		start.vPara=(void*)0x10;
	}
	else                   //TSC power down
	{
		ts_mask_int();
		ts_power_on = KAL_FALSE;
		start.vPara=(void*)0x11;
	}	
	start.u2Tick=1;
	IRQMask(IRQ_GPT_CODE);
	DclSGPT_Control(ts_tcs_off_gpt_handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
	IRQUnmask(IRQ_GPT_CODE);
}

#else //#if !defined(DRV_TS_OFF)

/*lint -e552*/kal_bool tp_up_intr_lost_flag = KAL_FALSE;/*lint +e552*/	// Indicate if there is TP UP intr missed
void tp_irq_enable(kal_bool on){}
kal_bool tp_level(void){}
void TP_PDN_SET(void){}
kal_bool tp_level(void) {}
kal_bool tp_pressure_check(void){}
kal_uint32 tp_pressure_value(void){}
void tp_read_adc(kal_uint16 *x, kal_uint16 *y){}
void tp_set_cmd_para(kal_uint32 sr, kal_uint32 ms){}
void TPUpdateNotify(void){}
void ts_drv_init(void){}
void ts_power_down_PENIRQ(void){}
kal_uint16  ts_read_adc(kal_uint16 pos,kal_bool IsPressure){}
static kal_uint16 ts_read_adc_adc_3835_WA(kal_uint16 pos){}
void ts_mask_int(void){}
void ts_unmask_int(void){}
#endif //#if !defined(DRV_TS_OFF)


#endif //#if defined(DRV_ADC_TOUCH_SCREEN) && (defined(TOUCH_PANEL_SUPPORT) || defined(HAND_WRITING) || defined(DRV_ADC_TOUCH_SCREEN_BTMT))
