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
*    ext_uart.c      
*
* Project:
* --------
*   Maui_Software
*
* Description:
* ------------
*   This Module defines the ext_uart driver functions
*   
*
* Author:
* -------
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
 * removed!
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
#ifdef __8_WIRE_UART_SUPPORT__

#include    "drv_features.h"
#include "sync_data.h"
//#include    "kal_release.h"
#include    "stack_common.h"
#include    "stack_msgs.h"
#include    "app_ltlcom.h"       /* Task message communiction */
//#include    "stack_buff_pool.h"
//#include    "app_buff_alloc.h"
#include    "drv_comm.h"
#include    "reg_base.h"
#include    "uart_hw.h"
#include    "bmd.h"
#include    "intrCtrl.h"
#include    "drvpdn.h"
#include    "stack_ltlcom.h"       /*msg_send_ext_queue.....definitions*/
#include    "stack_config.h"        /*MOD_UART1_HISR,MOD_UART2_HISR*/
#include    "uart_sw.h"
#include "uart_internal.h"
#include "Ext_Uart.h"
#include    "gpt_sw.h"
//#include    "init.h"
#include    "drv_trc.h"
#include    "drv_hisr.h"



#include "cache_sw.h"
//#include "init.h"
   // #include "kal_non_specific_general_types.h"
    #include "l1_interface.h"
    #include "us_timer.h"
        #include "kal_general_types.h"
    #include "kal_public_api.h"
    #include "hisr_config.h"
    #include "btif_sw.h"
    #include "dcl.h"
    #include "kal_public_defs.h"
#if defined(__TINY_SYS__)
	#include "AP_BtSS.h"
#endif    
#include "eint.h"   



extern const char gpio_extuart_ri_pin;
extern const char gpio_extuart_dcd_pin;
extern const char gpio_extuart_dsr_pin;
extern const char EXTUART_DTR_EINT_NO;



ExtUARTStruct ExtUARTPort[MAX_UART_PORT_NUM];
DCL_HANDLE dtr_handle = DCL_HANDLE_INVALID;
kal_bool   dtr_eint_state = (kal_bool)LEVEL_LOW;
kal_bool   ri_gpio_state;
kal_uint8  dtr_sleep_handle = 0xff;
kal_uint32 ri_duty_timer_handle = 0;
kal_uint32 ri_cycle_timer_handle = 0;
UART_PORT extport;
kal_uint32 Regtemp;

#define gpio_extuart_ri 	gpio_extuart_ri_pin
#define gpio_extuart_dcd  	gpio_extuart_dcd_pin
#define gpio_extuart_dsr 	gpio_extuart_dsr_pin
#define eint_dtr_no  		EXTUART_DTR_EINT_NO


ExtUARTStruct extuart_custom =
{
   uart_port1,
   io_high,
   io_high,
   	KAL_TRUE,
	KAL_FALSE,
	level,
	io_high,
	fifty_percent,
	100,
	400  //uint 10ms 	  
};



void ExtUart_Init(UART_PORT port)
{
	DCL_HANDLE ri_handle, dcd_handle, dsr_handle;
	DCL_CTRL_CMD_T ri_ctrl,dcd_ctrl,dsr_ctrl;
	ExtUARTStruct extuart_data;
	//register DTR eint
	EINT_CTRL_CONFIG_T eint_config;
	EINT_CTRL_SET_SENSITIVITY_T eint_sensitivity;
	EINT_CTRL_SET_POLARITY_T eint_polarity;
	kal_char buffer[50];

	extport = port;
	extuart_data= ExtUart_GetData();
	ExtUARTPort[port] = extuart_data;
	ri_ctrl = ExtUARTPort[port].RIConfig.ri_state? GPIO_CMD_WRITE_HIGH : GPIO_CMD_WRITE_LOW;
	dcd_ctrl = ExtUARTPort[port].dcd_state? GPIO_CMD_WRITE_HIGH : GPIO_CMD_WRITE_LOW;	
	dsr_ctrl = ExtUARTPort[port].dsr_state? GPIO_CMD_WRITE_HIGH : GPIO_CMD_WRITE_LOW;

	dtr_handle = DclEINT_Open(DCL_EINT,eint_dtr_no); 		// First, we call vm_dcl_open to get a handle. 19 means eint19
	DclEINT_Control(dtr_handle,EINT_CMD_MASK,NULL);	// Usually, before we config eint, we mask it firstly. 
	DclEINT_RegisterCallback(dtr_handle,EVENT_EINT_TRIGGER,(DCL_CALLBACK)DTR_EINT_CB,NULL,DCL_USER_GENERAL);// register callback function,Note: the last paramter fill NULL 
	eint_sensitivity.sensitivity = 1;	  // 1 means level sensitive, 0 means edge sensitive. 
	DclEINT_Control(dtr_handle,EINT_CMD_SET_SENSITIVITY,(void *)&eint_sensitivity);	// set eint sensitivity 
	eint_config.act_polarity = 0;	// 1 means positive active, 0 means negative active. 
	eint_config.debounce_en = 1;	// 1 means enable hw debounce, 0 means disable. 
	eint_config.auto_unmask = 0;	// 1 means unmask after callback, 0 means not unmask, and user should unmask it themselves. 
	DclEINT_Control(dtr_handle,EINT_CMD_CONFIG,(void *)&eint_config);   // Please call this api finally, because we will unmask eint in this command. 
	DclEINT_Control(dtr_handle,EINT_CMD_UNMASK,NULL);  // call this function to unmask this eint.

	dtr_sleep_handle = L1SM_GetHandle();

	 //itmp = GPTI_GetHandle(&touch_panel_handle);
   	ri_cycle_timer_handle = DclSGPT_Open(DCL_GPT_CB,0); 
	ri_duty_timer_handle = DclSGPT_Open(DCL_GPT_CB,0);


    ri_handle = DclGPIO_Open(DCL_GPIO, gpio_extuart_ri);
    DclGPIO_Control(ri_handle, GPIO_CMD_SET_MODE_0, NULL);
	DclGPIO_Control(ri_handle, GPIO_CMD_SET_DIR_OUT, NULL);
	DclGPIO_Control(ri_handle, ri_ctrl, NULL); 
	DclGPIO_Close(ri_handle);

	dcd_handle = DclGPIO_Open(DCL_GPIO, gpio_extuart_dcd);
    DclGPIO_Control(dcd_handle, GPIO_CMD_SET_MODE_0, NULL);
	DclGPIO_Control(dcd_handle, GPIO_CMD_SET_DIR_OUT, NULL);
	DclGPIO_Control(dcd_handle, dcd_ctrl, NULL); 
	DclGPIO_Close(dcd_handle);

	dsr_handle = DclGPIO_Open(DCL_GPIO, gpio_extuart_dsr);
    DclGPIO_Control(dsr_handle, GPIO_CMD_SET_MODE_0, NULL);
	DclGPIO_Control(dsr_handle, GPIO_CMD_SET_DIR_OUT, NULL);
	DclGPIO_Control(dsr_handle, dsr_ctrl, NULL); 
	DclGPIO_Close(dsr_handle);


	ExtUart_FUNC[port]= &ExtUartDriver;
	Regtemp = DRV_Reg32(0xA0020300);
	sprintf(buffer, "ExtUart_Init Reg 0xA0020300 = %08x",Regtemp);
	kal_bootup_print(buffer);
		
}



void ExtUart_Sendilm(UART_PORT port, kal_bool level)
{
	
	kal_uint16 flag;
	ilm_struct *ExtUART_ilm;
	void *port_ptr=0;  
	uart_dtr_state_change_ind_struct *tmp;  	
  
  	kal_prompt_trace(MOD_DRV_HISR, "ExtUart_Sendilm port=%d", port);    
	if(port >= MAX_UART_PORT_NUM)
		return;
    
	tmp = (uart_dtr_state_change_ind_struct *) 
	construct_local_para(sizeof(uart_dtr_state_change_ind_struct),TD_UL);
	tmp->port = port; 
	tmp->dtr_state = (kal_uint16)level;
	port_ptr = tmp;   	
  	       

	DRV_BuildPrimitive(ExtUART_ilm,
         MOD_DRV_HISR,//UARTPort[port].UART_id,
         MOD_ATCI,
         MSG_ID_SWUART_DTR_STATE_CHANGE_IND,
         port_ptr);
      
	kal_prompt_trace(MOD_DRV_HISR, "ExtUart_Sendilm send msg to ATCI"); 
    msg_send_ext_queue(ExtUART_ilm);
}



void DTR_EINT_CB()
{
    
	EINT_CTRL_CONFIG_T eint_config;
	if(dtr_handle == DCL_HANDLE_INVALID)
		return;

	DclEINT_Control(dtr_handle,EINT_CMD_MASK,NULL);
	if(dtr_eint_state){
		L1SM_SleepEnable(dtr_sleep_handle);
	}
    else{
		L1SM_SleepDisable(dtr_sleep_handle);
    }	

	ExtUart_Sendilm(extport, dtr_eint_state);	
    kal_prompt_trace(MOD_DRV_HISR, "DTR_EINT_CB dtr_eint_state = %d", dtr_eint_state);
	dtr_eint_state = (kal_bool)!dtr_eint_state;
	eint_config.act_polarity = dtr_eint_state;	// 1 means positive active, 0 means negative active. 
	eint_config.debounce_en = 1;	// 1 means enable hw debounce, 0 means disable. 
	eint_config.auto_unmask = 0;	// 1 means unmask after callback, 0 means not unmask, and user should unmask it themselves. 
	DclEINT_Control(dtr_handle,EINT_CMD_CONFIG,(void *)&eint_config);	
	DclEINT_Control(dtr_handle,EINT_CMD_UNMASK,NULL);
	
}


void ExtUart_RIPulse_Set_Timer(UART_PORT port,kal_uint16 period,TimerType t)
{
	SGPT_CTRL_START_T start;
	start.pfCallback = ExtUART_RI_Pulse;
	start.vPara = (void *)&port;

    
	IRQMask(IRQ_GPT_CODE);
	start.u2Tick = period; //default value;	
	switch(t)
		{
			case CycleTimer:
				DclSGPT_Control(ri_cycle_timer_handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
				break;
				
			case DutyTimer:
				DclSGPT_Control(ri_duty_timer_handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
				break;

			default:
				break;		  
		}

	IRQUnmask(IRQ_GPT_CODE);

}


void ExtUART_RI_Pulse(UART_PORT port)
{

	DCL_HANDLE ri_handle;
	kal_bool level_state = ExtUARTPort[port].RIConfig.ri_state;
    ri_handle = DclGPIO_Open(DCL_GPIO, gpio_extuart_ri);
	DclGPIO_Control	(ri_handle, GPIO_CMD_SET_MODE_0, NULL);	
	DclGPIO_Control(ri_handle, GPIO_CMD_SET_DIR_OUT, NULL);	
	kal_prompt_trace(MOD_DRV_HISR, "ExtUART_RI_Pulse port=%d",port);

	if(level_state)
	{
		
		DclGPIO_Control(ri_handle, GPIO_CMD_WRITE_LOW, NULL); 
		ExtUARTPort[port].RIConfig.ri_state = io_low;
        kal_prompt_trace(MOD_DRV_HISR, "ExtUART_RI_Pulse control RI io_low");
		
   	}
	else{
		
		DclGPIO_Control(ri_handle, GPIO_CMD_WRITE_HIGH, NULL); 		
		ExtUARTPort[port].RIConfig.ri_state = io_high;
        kal_prompt_trace(MOD_DRV_HISR, "ExtUART_RI_Pulse control RI io_high");
	}
	DclGPIO_Close(ri_handle);
	DclSGPT_Control(ri_cycle_timer_handle,SGPT_CMD_STOP,0);
	DclSGPT_Control(ri_duty_timer_handle,SGPT_CMD_STOP,0);

	Regtemp = DRV_Reg32(0xA0020300);
	kal_prompt_trace(MOD_DRV_HISR,"ExtUART_RI_Pulse Reg 0xA0020300 = %08x",Regtemp);
}



void ExtUart_CtrlRI(UART_PORT port, RIConfigure *RI)
{

	DCL_HANDLE ri_handle;
	kal_uint32 cycle_period, duty_period=0;
    kal_bool state;

	cycle_period = RI->cycletime;
	//duty = (kal_uint32)RI->duty;
	duty_period = RI->duration;	
	ExtUARTPort[port].RIConfig = (*RI);
	
    if( gpio_extuart_ri == 0xFF)
		return;
	kal_prompt_trace(MOD_DRV_HISR, "ExtUart_CtrlRI isactive=%d,RI->enable=%d,RI->isactive=%d",ExtUARTPort[port].RIConfig.isactive,ExtUARTPort[port].RIConfig.enable,
                     RI->isactive);
    kal_prompt_trace(MOD_DRV_HISR, "ExtUart_CtrlRI signaltype=%d,durationss=%d",ExtUARTPort[port].RIConfig.signaltype,
                     ExtUARTPort[port].RIConfig.duration);

	if(RI->enable)
	{
        ri_handle = DclGPIO_Open(DCL_GPIO, gpio_extuart_ri);
        DclGPIO_Control(ri_handle, GPIO_CMD_SET_MODE_0, NULL);
		DclGPIO_Control(ri_handle, GPIO_CMD_SET_DIR_OUT, NULL);
		kal_prompt_trace(MOD_DRV_HISR,"ExtUart_CtrlRI RI is enabled");
		if(RI->isactive){

				DclGPIO_Control(ri_handle, GPIO_CMD_WRITE_LOW, NULL); //default level:high
				ExtUARTPort[port].RIConfig.ri_state = io_low;
				//state = (kal_bool)io_low;
                kal_prompt_trace(MOD_DRV_HISR, "ExtUart_CtrlRI RI is active");
			if(RI->signaltype == pulse){
					//ExtUart_RIPulse_Set_Timer(cycle_period, state, CycleTimer);
					//ExtUart_RIPulse_Set_Timer(duty_period, state, DutyTimer);
					ExtUart_RIPulse_Set_Timer(port,duty_period,DutyTimer);
			}
					
		}
		else{
			
			DclGPIO_Control(ri_handle, GPIO_CMD_WRITE_HIGH, NULL); //default level:high				
			ExtUARTPort[port].RIConfig.ri_state = io_high;
            kal_prompt_trace(MOD_DRV_HISR, "ExtUart_CtrlRI RI is inactive");
			DclSGPT_Control(ri_cycle_timer_handle,SGPT_CMD_STOP,0);
			DclSGPT_Control(ri_duty_timer_handle,SGPT_CMD_STOP,0);
		}

		
		DclGPIO_Close(ri_handle);
    }
	else{
		
        ri_handle = DclGPIO_Open(DCL_GPIO, gpio_extuart_ri);
        DclGPIO_Control(ri_handle, GPIO_CMD_SET_MODE_0, NULL);
		DclGPIO_Control(ri_handle, GPIO_CMD_SET_DIR_IN, NULL);
		DclGPIO_Close(ri_handle);

		DclSGPT_Control(ri_cycle_timer_handle,SGPT_CMD_STOP,0);
		DclSGPT_Control(ri_duty_timer_handle,SGPT_CMD_STOP,0);
		ExtUARTPort[port].RIConfig.enable = KAL_FALSE;
		kal_prompt_trace(MOD_DRV_HISR,"ExtUart_CtrlRI RI is disabled");
		
	}
	Regtemp = DRV_Reg32(0xA0020300);
	kal_prompt_trace(MOD_DRV_HISR,"ExtUart_CtrlRI Reg 0xA0020300 = %08x",Regtemp);
}



void ExtUart_CtrlDSR(UART_PORT port, IO_level SDSR)
{
	DCL_HANDLE dsr_handle;
	kal_uint32 temp;
	if(gpio_extuart_dsr == 0xFF)
		return;
	dsr_handle = DclGPIO_Open(DCL_GPIO, gpio_extuart_dsr);
	DclGPIO_Control(dsr_handle, GPIO_CMD_SET_MODE_0, NULL);
	DclGPIO_Control(dsr_handle, GPIO_CMD_SET_DIR_OUT, NULL);
    kal_prompt_trace(MOD_DRV_HISR, "ExtUart_CtrlDSR port=%d,SDSR=%d",port,SDSR);
	if(SDSR)
   	{
		DclGPIO_Control(dsr_handle, GPIO_CMD_WRITE_HIGH, NULL);
		ExtUARTPort[port].dsr_state = io_high;
		temp = DRV_Reg32(0xA0020300);
	    kal_prompt_trace(MOD_DRV_HISR, "reg 0xA0020300 = 0x%08x", temp);	
		kal_prompt_trace(MOD_DRV_HISR, "ExtUart_CtrlDSR Control DSR io_high");
   	}
	else
   	{
		DclGPIO_Control(dsr_handle, GPIO_CMD_WRITE_LOW, NULL);  	
		ExtUARTPort[port].dsr_state = io_low;
		temp = DRV_Reg32(0xA0020300);
	    kal_prompt_trace(MOD_DRV_HISR, "reg 0xA0020300 = 0x%08x", temp);	
		kal_prompt_trace(MOD_DRV_HISR, "ExtUart_CtrlDSR Control DSR io_low");
   	}
	DclGPIO_Close(dsr_handle);
	Regtemp = DRV_Reg32(0xA0020300);
	kal_prompt_trace(MOD_DRV_HISR,"ExtUart_CtrlDSR Reg 0xA0020300 = %08x",Regtemp);
}


void ExtUart_CtrlDCD(UART_PORT port, IO_level SDCD)
{
	DCL_HANDLE dcd_handle;
	kal_uint32 temp;
	if(gpio_extuart_dcd == 0xFF)
		return;
	dcd_handle = DclGPIO_Open(DCL_GPIO, gpio_extuart_dcd);
	DclGPIO_Control(dcd_handle, GPIO_CMD_SET_MODE_0, NULL);
	DclGPIO_Control(dcd_handle, GPIO_CMD_SET_DIR_OUT, NULL);  
    kal_prompt_trace(MOD_DRV_HISR, "ExtUart_CtrlDCD port=%d,SDCD=%d",port,SDCD);
	if(SDCD)
   	{
		DclGPIO_Control(dcd_handle, GPIO_CMD_WRITE_HIGH, NULL);
		ExtUARTPort[port].dcd_state = io_high;
		temp = DRV_Reg32(0xA0020300);
	    kal_prompt_trace(MOD_DRV_HISR, "reg 0xA0020300 = 0x%08x", temp);	
		kal_prompt_trace(MOD_DRV_HISR, "ExtUart_CtrlDCD Control DCD io_high");
   	}
	else
   	{
		DclGPIO_Control(dcd_handle, GPIO_CMD_WRITE_LOW, NULL);  	
		ExtUARTPort[port].dcd_state = io_low;
		temp = DRV_Reg32(0xA0020300);
	    kal_prompt_trace(MOD_DRV_HISR, "reg 0xA0020300 = 0x%08x", temp);	
		kal_prompt_trace(MOD_DRV_HISR, "ExtUart_CtrlDCD Control DCD io_low");
   	}
	DclGPIO_Close(dcd_handle);   
	Regtemp = DRV_Reg32(0xA0020300);
	kal_prompt_trace(MOD_DRV_HISR,"ExtUart_CtrlDCD Reg 0xA0020300 = %08x",Regtemp);
}



ExtUARTStruct ExtUart_GetData(void)
{
	return (extuart_custom);
}


// uart dispatch funtion table
ExtUartDriver_strcut ExtUartDriver=
{
   //ExtUart_Init,
   ExtUart_CtrlRI,
   ExtUart_CtrlDSR,
   ExtUart_CtrlDCD
};

#endif /* __8_WIRE_UART_SUPPORT__ */

