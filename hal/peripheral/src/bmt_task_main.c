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
*    BMT_main.c
*
* Project:
* --------
*   Maui_Software
*
* Description:
* ------------
*   This Module defines main function of the BMT task.
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
#include    "drv_comm.h"
#include 	"stack_msgs.h"
#include 	"app_ltlcom.h"      /* Task message communiction */
#include    "task_config.h"     /* Task creation */
#include    "stack_ltlcom.h"	/* msg_send_ext_queue.....definitions */
#include	"bmt_trc.h"
#include    "drvsignals.h"
// For RHR ADD Usage
#include	"stack_config.h"
#include	"kal_trace.h"
#include	"task_main_func.h"
#include    "bmt_utility.h"
#include    "dcl.h"
#include    "kal_general_types.h"
#include    "kal_public_api.h"
#include    "hisr_config.h"
#include    "kal_public_defs.h"
#include    "bmt_sw_chip_setting.h"
#include    "adc_msg_handle.h"
#include    "bmt_chr_setting.h"
#include "tst_sap.h"
#if defined(PULSE_LI_CHARGING)  
#include 	"bmt_pulse_li.h"
#elif defined(LINEAR_LI_CHARGING)
#include 	"bmt_linear_li.h"
#endif


// ============================================================ //
//define
// ============================================================ //


// ============================================================ //
//global variable
// ============================================================ //


// ============================================================ //
// function prototype
// ============================================================ //


// ============================================================ //
//extern variable
// ============================================================ //


// ============================================================ //
//extern function
// ============================================================ //
extern Customer_Period_Period(void);	//custom key press period

#ifdef __LED_SUPPORT__
extern void gpio_led_init(void);
#endif
#if defined(__TINY_SYS__)  // when tiny system is enabled 
extern kal_bool g_Hibernation_to_ap_silent_reboot;
#endif


// ============================================================ //
void bmt_sendMes2BMT(module_type srcid, msg_type msgid)
{
   ilm_struct *BMT_ilm;
   
   DRV_BuildPrimitive(BMT_ilm,
      srcid,
      MOD_BMT,
      msgid,
      NULL);
   
   msg_send_ext_queue(BMT_ilm);
}


void bmt_sendAuxID2UEM(void)
{
	 kal_uint32 savedMask1;
	 aux_id_struct *aux_id_data;
	 ilm_struct *aux_ilm;
 	 static kal_bool aux_first_booting = KAL_TRUE; // for inform MMI already finish booting AUX detection
	 
     savedMask1 = SaveAndSetIRQMask();
     if(aux_first_booting)
     {
        aux_first_booting = KAL_FALSE;
        RestoreIRQMask(savedMask1);
        aux_id_data = (aux_id_struct*)construct_local_para(sizeof(aux_id_struct), TD_CTRL);
        aux_id_data->aux_id = AUX_ID_DETECTION_DONE;
        DRV_BuildPrimitive(aux_ilm,
           MOD_BMT,
           MOD_UEM,
           MSG_ID_AUX_ID,
           aux_id_data);
        msg_send_ext_queue(aux_ilm);
     }
     else
     {
        RestoreIRQMask(savedMask1);
     }
}


void bmt_sendMes2UEM(BMT_CHR_STAT status)
{
#ifndef L4_NOT_PRESENT
   ilm_struct *BMT_ilm;
#if (defined(__UART1_WITH_CHARGER__) || defined(__UART2_WITH_CHARGER__) || defined(__UART3_WITH_CHARGER__))
#if defined(__TST_MODULE__)
   ilm_struct *TST_ilm;
#endif
#endif
   
   drvuem_pmic_ind_struct *BMT_Prim;
   module_type src_mod;
   
   if(kal_if_hisr() == KAL_TRUE)
   		src_mod = MOD_DRV_HISR;
   else
   	  src_mod = MOD_BMT;
   
   BMT_Prim = (drvuem_pmic_ind_struct*)
      construct_local_para(sizeof(drvuem_pmic_ind_struct), TD_CTRL);
   BMT_Prim->status= status;
   
   DRV_BuildPrimitive(BMT_ilm,
      src_mod,
      MOD_UEM,
      MSG_ID_DRVUEM_PMIC_IND,
      BMT_Prim);
   
   msg_send_ext_queue(BMT_ilm);
   
#if (defined(__UART1_WITH_CHARGER__) || defined(__UART2_WITH_CHARGER__) || defined(__UART3_WITH_CHARGER__))
#if defined(__TST_MODULE__)
   // If add any plug-in/out status in drvsignals.h, need to add the new status here!!
   if( (status == BMT_CHARGER_IN) || 
      (status == BMT_INVALID_CHARGER))
   {
      BMT_Prim->status= BMT_CHARGER_IN;
   }
   DRV_BuildPrimitive(TST_ilm,
      src_mod,
      MOD_TST_READER,
      MSG_ID_DRVUEM_PMIC_IND,
      BMT_Prim);
   msg_send_ext_queue(TST_ilm);
#endif //#if defined(__TST_MODULE__)
#endif //__UART1_WITH_CHARGER__   
#endif  // #ifndef L4_NOT_PRESENT
}


static void bmt_timer_expire(ilm_struct *current_ilm)
{
     kal_uint32 timer_index;

	 timer_index = evshed_get_index(current_ilm);
	 
	 if (timer_index == BMT_TIMER_INDEX)
	 {
		evshed_timer_handler(bmt_event_scheduler_ptr);
	 }

     if (timer_index == BMT_ADC_TIMER_INDEX)
     {
     	evshed_timer_handler(bmt_adc_event_scheduler_ptr);
        //evshed_timer_handler(adc_sche_event_scheduler_ptr);
     }
}


static void bmt_chr_indication()
{
#if !defined(BMT_CHARGING_DISABLE)
	
	static Charger_Status previous_chr_status = bmt_chr_uninit;
	static CHR_DET_TYPE_ENUM previous_chr_type = PW_NO_CHR;
	CHR_DET_TYPE_ENUM chr_type;
	kal_bool charging_algo_enable;

	chr_type = bmt_get_chr_type();		
	   
	  // If battery is NOT attached, we just skip the message
    if (!bmt_is_bat_on())
    {
       drv_trace0(TRACE_GROUP_10, BMT_MSG_BATT_OFF_BLOCK);
       return;
    }
		
    if (bmt_read_chr_status() == CHARGER_PLUG_IN)
    {
       drv_trace0(TRACE_GROUP_10, BMT_CHR_STATUS_CHARGE_IN_TRC);                

       if ((previous_chr_status == bmt_chr_uninit) || (previous_chr_status != bmt_chr_in))
       {
       	    previous_chr_status = bmt_chr_in;
		  	if((chr_type == PW_AC_CHR) || (chr_type == PW_AC_NON_STD_CHR))
		  	{
                bmt_sendMes2UEM(BMT_CHARGER_IN);
				charging_algo_enable = KAL_TRUE;
				chr_algorithm_control_handler(BMT_CHARGING_ALGO_CMD_ENABLE, &charging_algo_enable);
                drv_trace0(TRACE_GROUP_10, BMT_AC_IN_AND_START_CHARGE_TRC);
		  	}
#if defined(__USB_ENABLE__)
			else
			{	
				 drv_trace0(TRACE_GROUP_10, BMT_USB_IN_TRC);
			}
#endif
       }

	}
    else if(bmt_read_chr_status() == CHARGER_PLUG_OUT)
    {
       if ((previous_chr_status == bmt_chr_uninit) || (previous_chr_status != bmt_chr_out))
       {
            previous_chr_status = bmt_chr_out;
          
			if((previous_chr_type == PW_AC_CHR) || (previous_chr_type == PW_AC_NON_STD_CHR))
			{
				 drv_trace0(TRACE_GROUP_10, BMT_AC_OUT_TRC);
				 bmt_sendMes2UEM(BMT_CHARGER_OUT);
				 charging_algo_enable = KAL_FALSE;
				 chr_algorithm_control_handler(BMT_CHARGING_ALGO_CMD_ENABLE, &charging_algo_enable);
				 drv_trace0(TRACE_GROUP_10, BMT_AC_OUT_AND_STOP_CHARGE_TRC);
			}
#if defined(__USB_ENABLE__)			
			else if((previous_chr_type == PW_USB_CHR) || (previous_chr_type == PW_USB_CHARGING_HOST_CHR))
			{
				drv_trace0(TRACE_GROUP_10, BMT_USB_OUT_TRC);
				if(PMU_CHARGE_CURRENT_0_00_MA == bmt_usb_chr_current)
				{
					bmt_sendMes2UEM(BMT_USB_NO_CHARGING_OUT);
	                drv_trace0(TRACE_GROUP_10, BMT_USB_100_OUT_TRC);
				}
				else if(PMU_CHARGE_CURRENT_500_00_MA >= bmt_usb_chr_current)
				{
				    bmt_sendMes2UEM(BMT_USB_CHARGER_OUT);
	                charging_algo_enable = KAL_FALSE;
					chr_algorithm_control_handler(BMT_CHARGING_ALGO_CMD_ENABLE, &charging_algo_enable);
	                drv_trace0(TRACE_GROUP_10, BMT_USB_500_OUT_AND_STOP_CHARGE_TRC);
				}
			}
#endif			
       }
    }
    else
    {
       ASSERT(0);
    }

	previous_chr_type = chr_type;


#if defined(__DRV_BMT_SW_FUEL_GAUGE__)	
	battery_meter_reset(100-oam.SOC);
	if(bmt_read_chr_status() == CHARGER_PLUG_OUT)
	{
		fg_qmax_update_for_aging_flag = KAL_TRUE;
		bat_in_recharging_state = KAL_FALSE;
	}	
#endif
#endif

}


static void bmt_usb_chr_indication(ilm_struct *current_ilm)
{
#if !defined(BMT_CHARGING_DISABLE)

	bmt_usb_ind_struct *ind = (bmt_usb_ind_struct*)current_ilm->local_para_ptr;
	kal_bool charging_algo_enable;
	PMU_CHR_CURRENT_ENUM set_charging_current = ind->usb_ind;

	// If battery is NOT attached, we just skip the message
    if (!bmt_is_bat_on())
    {
       drv_trace0(TRACE_GROUP_10, BMT_MSG_BATT_OFF_BLOCK);
       return;
    }

	if (bmt_read_chr_status() == CHARGER_PLUG_OUT)	// make sure the charger/usb is plug in , then start charging
		return;

	bmt_charging_control_handler(BMT_CHARGING_CMD_GET_CHARGING_CURRENT, &set_charging_current);

	if(bmt_usb_chr_current != set_charging_current)
	{
		if(PMU_CHARGE_CURRENT_0_00_MA == set_charging_current)
		{
			charging_algo_enable = KAL_FALSE;
			chr_algorithm_control_handler(BMT_CHARGING_ALGO_CMD_ENABLE, &charging_algo_enable);

            drv_trace0(TRACE_GROUP_10, BMT_CHARGING_CURRENT_NOT_SUPPORTED_STOP_CHARGING_TRC);

			bmt_usb_chr_current = set_charging_current;
			bmt_sendMes2UEM(BMT_USB_NO_CHARGING_IN);
		}
		else // usb current != 0
		{
			if((PMU_CHARGE_CURRENT_0_00_MA == bmt_usb_chr_current) || (PMU_CHARGE_CURRENT_INIT == bmt_usb_chr_current))	// avoid 100mA/500mA switch to start charging twice, and usb current != default value
			{
			    drv_trace0(TRACE_GROUP_10, BMT_USB_500_AND_START_CHARGE_TRC);
				
				bmt_usb_chr_current = set_charging_current;
			    bmt_sendMes2UEM(BMT_USB_CHARGER_IN);
				charging_algo_enable = KAL_TRUE;
				chr_algorithm_control_handler(BMT_CHARGING_ALGO_CMD_ENABLE, &charging_algo_enable);
			}
			else
			{
				bmt_usb_chr_current = set_charging_current;
			}
		}

		
	}

#endif	
}



/*
* FUNCTION
*	   bmt_check_poweron
*
* DESCRIPTION                                                           
*   	This function is to check if AC/USB exists at CHRPWRON/USBPWRON
*
* CALLS  
*
* PARAMETERS
*	  
*	
* RETURNS
*	   Receive primitive from the specified queue.
*
* GLOBALS AFFECTED
*     None
*/
static void bmt_check_poweron(kal_uint8 power_on)
{      
    DCL_BOOL state=KAL_FALSE;
    DCL_HANDLE dcl_wdt_handle;
  
    dcl_wdt_handle = DclWDT_Open(DCL_WDT, FLAGS_NONE);
	
	bmt_charging_control_handler(BMT_CHARGING_CMD_GET_CHR_DET_STATUS, &state);
     
	#if !defined(__USB_ENABLE__)
	if (power_on==(kal_uint8)CHRPWRON||power_on==(kal_uint8)PRECHRPWRON)
	#else // #if !defined(__USB_ENABLE__)
   if(power_on==(kal_uint8)CHRPWRON||power_on==(kal_uint8)PRECHRPWRON||
      power_on==(kal_uint8)USBPWRON||power_on==(kal_uint8)USBPWRON_WDT)   
	#endif // #if !defined(__USB_ENABLE__) 
   {           
      if(state==KAL_FALSE)
      {
         while(1)
         {
            kal_uint32 delay=0;
			DCL_HANDLE pw_handle;

			pw_handle = DclPW_Open(DCL_PW, FLAGS_NONE);
        	DclPW_Control(pw_handle,PW_CMD_POWEROFF,NULL);
        	DclPW_Close(pw_handle);              
            for(delay=0;delay<5000;delay++){};
			DclWDT_Control(dcl_wdt_handle,WDT_CMD_DRV_RESET,0);	          	
         }	
      }   
   }             
}   


/*
* FUNCTION
*	   BMT_Task
*
* DESCRIPTION                                                           
*   	This function is used to send message to BMT task.
*     This Module defines main function of the BMT task.
*
* CALLS  
*
* PARAMETERS
*	  
*	
* RETURNS
*	   Receive primitive from the specified queue.
*
* GLOBALS AFFECTED
*     None
*/
void bmt_task_main(task_entry_struct *task_entry_ptr)
{
   
   ilm_struct	current_ilm;
   ilm_struct *BMT_ilm;
   drvuem_power_on_ind_struct *power_on_ind;
   kal_uint16    UEM_RECEIVE_PWR_IND=2012;
   DCL_HANDLE dcl_adc_handle; 
   DCL_HANDLE pmu_handle;
#if defined(__UMTS_RAT__)
/* under construction !*/
#endif  /* __UMTS_RAT__ */
#ifdef BMT_ACTIVE_TO_READ_NVRAM_DATA
   nvram_read_req_struct* nvram_read_req;
#endif   /*BMT_ACTIVE_TO_READ_NVRAM_DATA*/
#if defined(DRV_GPT_GPT3)
	DCL_HANDLE gpt_handle;
	FGPT_CTRL_RETURN_COUNT_T current_count;
#endif

#if defined(DRV_BMT_BOOTING_DELAY_EXTEND)
   kal_uint32 BOOTING_DELAY    =	 100; //need longer than first plugin debounce.
#else
   kal_uint32 BOOTING_DELAY    =	 40; //need longer than first plugin debounce.
#endif

#if defined(DRV_GPT_GPT3)
#if (defined(__CS_SERVICE__) && defined(__PS_SERVICE__))
	kal_uint32 PERIOD_RST_TO_DRVINT = 1000;
#else 
	kal_uint32 PERIOD_RST_TO_DRVINT = 100;
#endif 
#endif 

   drv_trace0(TRACE_GROUP_10, BMT_TASK_MAIN_TRC);
  
   bmt_timer_init();
   
#ifdef __DRV_BMT_SW_POLLING_CHARGER_OV__
	bmt_sw_polling_timerId=kal_create_timer("BMT Charger OV SW Timer");
#endif //#ifd
   
#if ( (!defined(__MAUI_BASIC__)) && (!defined(L4_NOT_PRESENT)) )
   // If not Basic load, then we init the timer
   // In Basic load, L1S load, there is no L4, send message to UEM module(L4 module) will make ASSERT
    bmt_set_timer(BMT_AUX_TIMER,BOOTING_DELAY);
#endif // #if ( (!defined(__MAUI_BASIC__)) && (!defined(L4_NOT_PRESENT)) )
   
   
#if defined(__UMTS_RAT__)
/* under construction !*/
#endif  /* __UMTS_RAT__ */

	#ifdef PMIC_PRESENT
	#if defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
	#endif // #if defined(__UMTS_RAT__)
        pmu_handle = Dcl_Chr_Det_Open(DCL_CHR_USB_DET, FLAGS_NONE);
        Dcl_Chr_Det_Control(pmu_handle, CHR_DET_CMD_REGISTER_CHR_USB, NULL);
        Dcl_Chr_Det_Close(pmu_handle);    

	#if defined(__UMTS_RAT__)
/* under construction !*/
	#endif // #if defined(__UMTS_RAT__)
	#endif   /*PMIC_PRESENT*/

#if ( (!defined(L4_NOT_PRESENT)) && (!defined(DUMMY_PROTOCOL)) && (!defined(PMIC_PRESENT)))
   //if( INT_USBBoot() == KAL_FALSE )
#if defined(__UMTS_RAT__)
/* under construction !*/
#endif  /* __UMTS_RAT__ */
   {
#if defined(DRV_GPT_GPT3)
	  gpt_handle=DclFGPT_Open(DCL_GPT_FreeRUN3,0);
      DclFGPT_Control(gpt_handle,FGPT_CMD_RETURN_COUNT,(DCL_CTRL_DATA_T*)&current_count);
      UEM_RECEIVE_PWR_IND = current_count+PERIOD_RST_TO_DRVINT;
      DclFGPT_Control(gpt_handle,FGPT_CMD_STOP,0);
      DclFGPT_Close(gpt_handle);
#endif // #if defined(DRV_GPT_GPT3)
      power_on_ind = (drvuem_power_on_ind_struct *) construct_local_para(sizeof(drvuem_power_on_ind_struct),TD_UL);		    
      power_on_ind->power_on = bmt_Get_PowerOn_Type();
      if (UEM_RECEIVE_PWR_IND>Customer_Period_Period())
      {
         power_on_ind->poweron_time_left=0;
      }
      else
      {
         power_on_ind->poweron_time_left=Customer_Period_Period()-UEM_RECEIVE_PWR_IND;
      }
      DRV_BuildPrimitive(BMT_ilm,
         MOD_BMT,
         MOD_UEM,
         MSG_ID_DRVUEM_POWER_ON_IND,
         power_on_ind);
      msg_send_ext_queue(BMT_ilm);
      
   }
#endif // #if ( (!defined(L4_NOT_PRESENT)) && (!defined(DUMMY_PROTOCOL)) && (!defined(PMIC_PRESENT)))
   
   
#if ( (!defined(L4_NOT_PRESENT)) && (!defined(DUMMY_PROTOCOL)) && (defined(PMIC_PRESENT)) )
#if defined(__UMTS_RAT__)
/* under construction !*/
#endif  /* __UMTS_RAT__ */
   {
#if defined(__MTK_INTERNAL__)
 #if defined(__TINY_SYS__)  // when tiny system is enabled 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
  #else                  //when tiny system is disabled 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
 #endif
#endif // #if defined(__MTK_INTERNAL__)
#if defined(DRV_GPT_GPT3)
	  gpt_handle=DclFGPT_Open(DCL_GPT_FreeRUN3,0);
      DclFGPT_Control(gpt_handle,FGPT_CMD_RETURN_COUNT,(DCL_CTRL_DATA_T*)&current_count);
      UEM_RECEIVE_PWR_IND = current_count+PERIOD_RST_TO_DRVINT;
      DclFGPT_Control(gpt_handle,FGPT_CMD_STOP,0);
      DclFGPT_Close(gpt_handle);
#endif // #if defined(DRV_GPT_GPT3)
      bmt_check_poweron(bmt_Get_PowerOn_Type());      
      
      power_on_ind = (drvuem_power_on_ind_struct *) construct_local_para(sizeof(drvuem_power_on_ind_struct),TD_UL);		    
      power_on_ind->power_on = (PW_CTRL_POWER_ON_REASON)bmt_Get_PowerOn_Type();
      // Alarm wakeup, we set poweron_time_left as PWRKEY power on
      // To avoid earphone plug-in message late than power on time
      // If earphone plug-in message ia later than power on time, MMI will choose general profile
      //if(BMT.PWRon == (kal_uint8)PWRKEYPWRON)
      if ( (bmt_Get_PowerOn_Type() == (kal_uint8)PWRKEYPWRON) || (bmt_Get_PowerOn_Type() == (kal_uint8)RTCPWRON) )
      {
         if (UEM_RECEIVE_PWR_IND>Customer_Period_Period())
         {
            power_on_ind->poweron_time_left=0;
         }
         else
         {
            power_on_ind->poweron_time_left=Customer_Period_Period()-UEM_RECEIVE_PWR_IND;
         }
      }
      else
      {
         power_on_ind->poweron_time_left = 0;
      }
      
      DRV_BuildPrimitive(BMT_ilm,
         MOD_BMT,
         MOD_UEM,
         MSG_ID_DRVUEM_POWER_ON_IND,
         power_on_ind);
      msg_send_ext_queue(BMT_ilm);
#ifdef BMT_ACTIVE_TO_READ_NVRAM_DATA
      /*send to read the ADC calibration data req.*/
      nvram_read_req = (nvram_read_req_struct*)construct_local_para(
         sizeof(nvram_read_req_struct), 
         TD_CTRL);
      nvram_read_req->file_idx = NVRAM_EF_ADC_LID;
      nvram_read_req->para = 1;
      nvram_read_req->access_id = 0;
      
      DRV_BuildPrimitive(BMT_ilm,
         MOD_BMT,
         MOD_NVRAM,
         MSG_ID_NVRAM_READ_REQ,
         nvram_read_req);
      msg_send_ext_queue(BMT_ilm);
#endif // #ifdef BMT_ACTIVE_TO_READ_NVRAM_DATA
   } /* if (boot_mode != FACTORY_BOOT) */
#endif // #if ( (!defined(L4_NOT_PRESENT)) && (!defined(DUMMY_PROTOCOL)) && (defined(PMIC_PRESENT)) )
   
   
#ifdef PMIC_PRESENT
#if defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
#endif  /* __UMTS_RAT__ */
      /*Charging algorithm initial*/
#if !defined(BMT_CHARGING_DISABLE)	
      bmt_adc_init();
#endif
	  
#if defined(__UMTS_RAT__)
/* under construction !*/
#endif  /* __UMTS_RAT__ */
#endif   /*PMIC_PRESENT*/
#if defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
#endif  /* __UMTS_RAT__ */

      drv_trace1(TRACE_GROUP_10, BMT_PWRON_TRC, bmt_Get_PowerOn_Type());
      dcl_adc_handle = DclSADC_Open(DCL_ADC, FLAGS_NONE);
      DclSADC_Control(dcl_adc_handle, ADC_CMD_READ_CALIBRATION_INFORM_IN_USBBOOT, NULL);
      DclSADC_Close(dcl_adc_handle);

#if defined(__UMTS_RAT__)
/* under construction !*/
#endif  /* __UMTS_RAT__ */
   
#if defined(__DRV_BATTERY_EXIST_DETECTION__)
   bmt_set_timer(BMT_BATTERY_DET_TIMER, bmt_get_batt_exist_det_period());
   bmt_batt_exist_detection(KAL_TRUE);  // First time perform battery detection
#endif // #if defined(__DRV_BATTERY_EXIST_DETECTION__)
   
   {	//update VBAT_OFF default value to avoid battery bar is incorrect if USB send 0mA to BMT at power on
   		kal_uint32 voltage=0;
		
   		bmt_get_adc_channel_voltage(DCL_VBAT_ADC_CHANNEL, &voltage);
	    bmt_set_charge_off_vbat_status(voltage, 0);
   }
	#ifdef __LED_SUPPORT__
	gpio_led_init();
	#endif


#if defined(__DRV_BMT_SW_FUEL_GAUGE__)	
	oam_init();
	last_oam_time = kal_get_systicks();
	bmt_set_timer(BMT_SW_FUEL_GAUGE_TIMER,KAL_TICKS_1_SEC*BMT_OAM_RUN_TIME);
#endif

   while(1)
   {
      receive_msg_ext_q_for_stack(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
      
      switch(current_ilm.msg_id)
      {
#if defined(DRV_ADC_DVT)      
	case MSG_ID_TST_INJECT_STRING:
	     bmt_handleTstCommand(&current_ilm);
            break;      
	case MSG_ID_BMT_ADC_MEASURE_DONE_CONF:
	     bmt_handledvt(&current_ilm);
	     break;
#endif //#if defined(DRV_ADC_DVT)
			
      	case MSG_ID_BMT_ADC_ADD_ITEM_REQ:
            drv_trace0(TRACE_GROUP_10, BMT_MSG_ADC_ADD);
            bmt_adc_sche_add_item(current_ilm.local_para_ptr);
            break;
            
         case MSG_ID_BMT_ADC_REMOVE_ITEM_REQ:
            drv_trace0(TRACE_GROUP_10, BMT_MSG_ADC_REMOVE);
            bmt_adc_sche_remove_item(current_ilm.local_para_ptr);
            break;
            
         case MSG_ID_BMT_ADC_MODIFY_PARAMETERS_REQ:
            drv_trace0(TRACE_GROUP_10, BMT_MSG_ADC_PARAM);
            bmt_adc_sche_modify_parameters(current_ilm.local_para_ptr);
            break;
			
      	 case MSG_ID_TIMER_EXPIRY:
	  		bmt_timer_expire(&current_ilm);
         	break;
         
         case MSG_ID_BMT_CHARGER_IND:
            drv_trace0(TRACE_GROUP_10, BMT_MSG_CHARGER_TRC);
			bmt_chr_indication();
         	break;
			
#if defined (__USB_ENABLE__)
         case MSG_ID_BMT_USB_IND:
            drv_trace0(TRACE_GROUP_10, BMT_MSG_USB);
            bmt_usb_chr_indication(&current_ilm);
         	break;                     
#endif
#if ( (!defined(L4_NOT_PRESENT)) && (!defined(DUMMY_PROTOCOL)) )
         case MSG_ID_NVRAM_READ_CNF:
			bmt_adc_nvram_read(&current_ilm);		
    		break;
#endif 
       	 default:
            break;
      }
      free_ilm(&current_ilm);
   }
}

