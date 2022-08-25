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
 *    auxmain.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the AUX task
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __L1_STANDALONE__
#include 	"stack_common.h"  
#include 	"stack_msgs.h"
#include 	"app_ltlcom.h"       /* Task message communiction */
#include 	"syscomp_config.h"
#include 	"task_config.h"
#include 	"drv_comm.h"
//#include    "adc.h"
#include    "drvsignals.h"
#include    "eint.h"
#include     "l1audio.h"
#include     "intrctrl.h"

#include "kal_general_types.h"
#include "stack_config.h"
#include "task_main_func.h"
#include "kal_public_api.h"
#include "stack_ltlcom.h"
#include "hisr_config.h"
#include "init.h"
#include    "dcl.h"


#ifdef __HEART_RATE_ENABLE__
#include "dcl_uart.h"
#include "uart_internal.h"
#include "uart_hw.h"
#include "mmi_msg_struct.h"
#include    "dcl_pmu.h"

#endif

/*UART Detection*/

//liming remove for slim
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if !defined(__SMART_PHONE_MODEM__)

#include  "aux_custom.h"
#include "accessory_sw.h"

#ifdef TV_OUT_SUPPORT  
#include 	 "tv_out.h"
#endif

#if (defined(__ACCDET_SUPPORT__)||defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__))
#include    "accdet_sw.h"
#endif //#if defined(__ACCDET_SUPPORT__)

const aux_func_struct *aux_custom_ptr;
extern const aux_func_struct* aux_GetFunc(void);
extern void aux_custom_init(void);

extern const kal_uint8 AUX_EINT_NO;

#ifdef __LINE_IN_SUPPORT__
extern const kal_uint8 LINE_IN_EINT_NO;
#endif

#ifdef __BT_NFC_TAG_SUPPORT__
extern const kal_uint8 NFC_TAG_EINT_NO;
#endif


void AUX_EINT_HISR(void);

void AUX_Sendilm(module_type src_mod, module_type dst_mod, msg_type msgid, AUX_ID aux_id_no);
kal_bool 	aux_create(comptask_handler_struct **handle);
static void aux_task_main(task_entry_struct *task_entry_ptr);
static kal_bool	aux_task_reset(task_indx_type task_indx);
static kal_bool 	aux_task_end(task_indx_type task_indx);
kal_int32 EINT_SW_Debounce_Modify(kal_uint8 eintno, kal_uint8 debounce_time);


/*************************************************************************
* Variable declaration
 *************************************************************************/

#if !defined(__ACCDET_SUPPORT__)  
stack_timer_struct aux_timer;
static kal_bool aux_state = (kal_bool)AUX_EINT_STATE;
static kal_uint8 aux_timer_open = 0;
static kal_uint8     call_setup_cnt = 0;
static kal_bool poll_timer = KAL_FALSE;
static kal_bool aux_detect_mode = KAL_FALSE;
#endif //#if !defined(__ACCDET_SUPPORT__)  

#ifdef __LINE_IN_SUPPORT__  //for line in
static kal_bool line_in_eint_state = (kal_bool)LINE_IN_EINT_STATE;
#endif 

#ifdef __BT_NFC_TAG_SUPPORT__  //for nfc tag
static kal_bool nfc_tag_eint_state = (kal_bool)NFC_TAG_EINT_STATE;
#endif 




void ACCDET_version_check(void)
{
#if defined(MT6250)
	SW_SECVERSION SWSecVer;
	SWSecVer = INT_SW_SecVersion();
	switch ( SWSecVer) 
	{
	   case SW_SEC_0:
#if defined(__ACCDET_EINT_SUPPORT__)
		ASSERT(0);
#endif //#if defined(__ACCDET_EINT_SUPPORT__)
		         break;
	   default:
	   		  break;
	}
#endif //if defined(MT6250)
}

void aux_remove_adc_channel(kal_uint32 adc_handle);
DCL_HANDLE adc_handle_aux;

#ifdef TV_OUT_SUPPORT  
kal_bool aux_tvout_on = KAL_FALSE;
#endif

#undef  AUX_DEBUG

#if defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)
static AUX_POLLING_STATUS 	aux_polling_status = AUX_STATUS_ORG;

kal_bool g_bAudioBufferOpen = KAL_FALSE;
kal_bool g_bPlugIn = KAL_FALSE;
void aux_plugin_handler()
{
	aux_polling_status = AUX_STATUS_ORG;
	aux_timer_open = 1;	
	//g_bPlugIn = KAL_TRUE;
	aux_detect_mode = (kal_bool)AFE_TurnOnMicBias(); 
	aux_remove_adc_channel(adc_handle_aux);           
	stack_start_timer(&aux_timer, 0, TURN_ON_BIAS_INTERVAL*2);
}
void aux_plugout_handler()
{
	aux_polling_status = AUX_STATUS_ORG;
	aux_timer_open = 0;	
	g_bPlugIn = KAL_FALSE;
	AFE_TurnOffMicBias();
	stack_stop_timer(&aux_timer);
}
void aux_Audio_Closed_Handler()
{
	ilm_struct       *aux_ilm;
	if (aux_timer.dest_mod_id == MOD_AUX)
	{
		DRV_BuildPrimitive(aux_ilm, MOD_L1SP, MOD_AUX, MSG_ID_AUX_AUDIO_CLOSED, NULL);       
		msg_send_ext_queue(aux_ilm);
	}
}
void aux_Audio_Open_Handler()
{    
	ilm_struct       *aux_ilm;
	if (aux_timer.dest_mod_id == MOD_AUX)
	{
		g_bAudioBufferOpen = KAL_TRUE;
		DRV_BuildPrimitive(aux_ilm, MOD_L1SP, MOD_AUX, MSG_ID_AUX_AUDIO_OPEN, NULL);       
		msg_send_ext_queue(aux_ilm);
	}
}
#endif //defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)


/*************************************************************************
* FUNCTION
*	aux_create
*
* DESCRIPTION
*	This function implements xyz entity's create handler.
*
* PARAMETERS
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool aux_create(comptask_handler_struct **handle)
{
	static const comptask_handler_struct aux_handler_info = 
	{
		aux_task_main,			/* task entry function */
		NULL,		  	/* task initialization function */
		NULL, 	/* task configuration function */
		aux_task_reset,		/* task reset handler */
		aux_task_end			/* task termination handler */
	};
	*handle = (comptask_handler_struct *)&aux_handler_info;
	return KAL_TRUE;
}
/*************************************************************************
* FUNCTION
*	AUX_EINT_HISR
*
* DESCRIPTION
*	This function implements the response of AUX EINT.
*
* PARAMETERS
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
#if (!defined(__ACCDET_SUPPORT__)&& !defined(__DRV_EXT_ACCESSORY_DETECTION__)) && !defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)
void AUX_EINT_HISR(void)
{
	if (aux_state == AUX_EINT_STATE)
	{
		#ifdef AUX_DEBUG
		dbg_print(" Interrupt: Plugin \n\r");
		#endif 

		aux_timer_open = 1;		                           
		aux_detect_mode = (kal_bool)AFE_TurnOnMicBias();            
		stack_start_timer(&aux_timer, 0, TURN_ON_BIAS_INTERVAL);            

		EINT_SW_Debounce_Modify(AUX_EINT_NO,PLUGOUT_DEBOUNCE_TIME);
		aux_state = (kal_bool)!aux_state;
		EINT_Set_Polarity(AUX_EINT_NO,aux_state);

		aux_custom_ptr->aux_plug_in(); //customer can do his own job through this
		
		AUX_Sendilm(MOD_EINT_HISR,MOD_AUX,MSG_ID_AUX_PLUGIN,AUX_ID_PLUGIN);
	}
	else
	{
		#ifdef AUX_DEBUG
		dbg_print(" Interrupt: Plugout \n\r");
		#endif 

		aux_timer_open = 0;	
		AFE_TurnOffMicBias();
		stack_stop_timer(&aux_timer);

		EINT_SW_Debounce_Modify(AUX_EINT_NO,PLUGIN_DEBOUNCE_TIME);                              
		aux_state = (kal_bool)!aux_state;
		EINT_Set_Polarity(AUX_EINT_NO,aux_state); 

		aux_custom_ptr->aux_plug_out(); //customer can do his own job through this
		
		AUX_Sendilm(MOD_EINT_HISR,MOD_AUX,MSG_ID_AUX_PLUGOUT,AUX_ID_PLUGOUT);

	}
}
#endif


#ifdef __LINE_IN_SUPPORT__
#define BCT4321_CONTROL
#ifdef BCT4321_CONTROL
extern const char gpio_bct4321_s1_pin;
#endif
void LINE_IN_EINT_HISR(void)
{
#ifdef BCT4321_CONTROL
	DCL_HANDLE handle;
#endif	
	if (line_in_eint_state == LINE_IN_EINT_STATE)
	{
		line_in_eint_state = (kal_bool)!line_in_eint_state;
		EINT_Set_Polarity(LINE_IN_EINT_NO,line_in_eint_state); 
		EINT_Set_Sensitivity(LINE_IN_EINT_NO,LEVEL_SENSITIVE);
		EINT_Set_HW_Debounce(LINE_IN_EINT_NO, 10);
		EINT_SW_Debounce_Modify(LINE_IN_EINT_NO,10);
		#ifdef BCT4321_CONTROL
		handle = DclGPIO_Open(DCL_GPIO,gpio_bct4321_s1_pin);
		DclGPIO_Control(handle, GPIO_CMD_SET_MODE_0, NULL);
		DclGPIO_Control(handle, GPIO_CMD_SET_DIR_OUT, NULL);
		DclGPIO_Control(handle, GPIO_CMD_ENABLE_PULL, NULL);
		DclGPIO_Control(handle, GPIO_CMD_SET_PULL_HIGH, NULL);
		DclGPIO_Control(handle, GPIO_CMD_WRITE_LOW, 0);
		DclGPIO_Close(handle);
		#endif
		AUX_Sendilm(MOD_AUX,MOD_UEM,MSG_ID_AUX_ID,AUX_ID_LINEIN_PLUGIN);
	}
	else
	{
		line_in_eint_state = (kal_bool)!line_in_eint_state;
		EINT_Set_Polarity(LINE_IN_EINT_NO,line_in_eint_state);
		EINT_Set_Sensitivity(LINE_IN_EINT_NO,LEVEL_SENSITIVE);
		EINT_Set_HW_Debounce(LINE_IN_EINT_NO, 10);
		EINT_SW_Debounce_Modify(LINE_IN_EINT_NO,10);
		#ifdef BCT4321_CONTROL
		handle = DclGPIO_Open(DCL_GPIO,gpio_bct4321_s1_pin);
		DclGPIO_Control(handle, GPIO_CMD_SET_MODE_0, NULL);
		DclGPIO_Control(handle, GPIO_CMD_SET_DIR_OUT, NULL);
		DclGPIO_Control(handle, GPIO_CMD_ENABLE_PULL, NULL);
		DclGPIO_Control(handle, GPIO_CMD_SET_PULL_HIGH, NULL);
		DclGPIO_Control(handle, GPIO_CMD_WRITE_HIGH, 0);
		DclGPIO_Close(handle);
		#endif
		AUX_Sendilm(MOD_AUX,MOD_UEM,MSG_ID_AUX_ID,AUX_ID_LINEIN_PLUGOUT);
	}
}
#endif



#ifdef __BT_NFC_TAG_SUPPORT__
void NFC_TAG_EINT_HISR(void)
{
	if (nfc_tag_eint_state == NFC_TAG_EINT_STATE)
	{
		nfc_tag_eint_state = (kal_bool)!nfc_tag_eint_state;
		EINT_Set_Polarity(NFC_TAG_EINT_NO,nfc_tag_eint_state); 
		EINT_SW_Debounce_Modify(NFC_TAG_EINT_NO,10);
		
		AUX_Sendilm(MOD_AUX,MOD_UEM,MSG_ID_AUX_ID,NFC_TAG_PAIRING);
	}
	else
	{
		nfc_tag_eint_state = (kal_bool)!nfc_tag_eint_state;
		EINT_Set_Polarity(NFC_TAG_EINT_NO,nfc_tag_eint_state);
		EINT_SW_Debounce_Modify(NFC_TAG_EINT_NO,10);
		
		AUX_Sendilm(MOD_AUX,MOD_UEM,MSG_ID_AUX_ID,NFC_TAG_LEAVING);
	}
}
#endif


/*************************************************************************
* FUNCTION
*	aux_read_adc_channel
*
* DESCRIPTION
*	This function read the adc channel.
*
* PARAMETERS
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void aux_read_adc_channel(kal_uint32 adc_handle)
{
   ilm_struct        *aux_ilm;
   bmt_adc_add_item_req_struct *aux_adc_item;
   aux_adc_item = (bmt_adc_add_item_req_struct*)
				   construct_local_para(sizeof(bmt_adc_add_item_req_struct), TD_CTRL);
				   
   //aux_adc_item->adc_sche_id = logic_id;
   aux_adc_item->adc_handle = adc_handle;
   
   DRV_BuildPrimitive(aux_ilm,
                      MOD_AUX,
                      MOD_BMT,
                      MSG_ID_BMT_ADC_ADD_ITEM_REQ,
                      aux_adc_item);
                      
   msg_send_ext_queue(aux_ilm);
}
/*************************************************************************
* FUNCTION
*	aux_remove_adc_channel
*
* DESCRIPTION
*	This function remove the adc channel.
*
* PARAMETERS
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void aux_remove_adc_channel(kal_uint32 adc_handle)
{
   ilm_struct        *aux_ilm;
   bmt_adc_remove_item_req_struct *aux_adc_remove_item;
   aux_adc_remove_item = (bmt_adc_remove_item_req_struct*)
	   construct_local_para(sizeof(bmt_adc_remove_item_req_struct), TD_CTRL);
   
  // aux_adc_remove_item->adc_sche_id = logic_id;
  aux_adc_remove_item->adc_handle = adc_handle;
   DRV_BuildPrimitive(aux_ilm,
                      MOD_AUX,
                      MOD_BMT,
                      MSG_ID_BMT_ADC_REMOVE_ITEM_REQ,
                      aux_adc_remove_item);

   msg_send_ext_queue(aux_ilm);
}
/*************************************************************************
* FUNCTION
*	aux_read_result
*
* DESCRIPTION
*	This function is to read adc result and send msg to UEM and TST_READER accoding 
*  different adc value
*
* PARAMETERS
*  pre_id   : 
*  logic_id : adc logic channel 
*  buf      : local parameter of ilm 
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
//void aux_read_result(AUX_ID *pre_id,kal_uint8 aux_adc_logic_id,local_para_struct *buf)
#if (!defined(__ACCDET_SUPPORT__)&& !defined(__DRV_EXT_ACCESSORY_DETECTION__))
void aux_read_result(AUX_ID *pre_id,local_para_struct *buf)
{
   bmt_adc_measure_done_conf_struct *ptr=(bmt_adc_measure_done_conf_struct *)buf;
   kal_int32                       aux_volt_result;
   AUX_ID                    aux_id_no=AUX_ID_PLUGOUT;
  
    if (0 == aux_timer_open)
    {
        return;
    }

    aux_volt_result = (kal_int32) ptr->volt;

    //UART or TV_out part
    if ((*pre_id != AUX_ID_EARPHONE) && (*pre_id != AUX_ID_KEY_PRESS) && (*pre_id != AUX_ID_KEY_RELEASE))
    {
        if(aux_volt_result > UART_ADC)
        {
            #ifdef AUX_DEBUG
            dbg_print("UART \n\r");
            dbg_print("AUX voltage = %d\n\r",aux_volt_result);
            #endif 
			
            aux_custom_ptr->aux_uart_func(KAL_TRUE); //if uart switch pin not defined, this line will do nothing

			aux_id_no = AUX_ID_UART;
        }
        #ifdef TV_OUT_SUPPORT  
        else if (aux_volt_result < TV_OUT_ADC_HIGH1 && aux_volt_result > TV_OUT_ADC_LOW1)
        {
            //call the TVOUT function to check
            aux_custom_ptr->aux_HSTV_func(KAL_FALSE); //if HSTV enable switch pin not defined, this line will do nothing

			aux_id_no = AUX_ID_TVOUT;
   	    }
        else 
        {	
            if (aux_tvout_on == KAL_FALSE)
            {
                if (aux_volt_result < TV_OUT_ADC_LOW2)
                {
                    //enable TVOUT
					aux_custom_ptr->aux_HSTV_func(KAL_FALSE); //if HSTV enable switch pin not defined, this line will do nothing

					init_tv(0);
					enable_tv_encoder(KAL_TRUE);
					aux_tvout_on = KAL_TRUE;
                }
            }
            else
            {
                if ((aux_volt_result > TV_OUT_EARPHONE_LOW_LIMIT) && (aux_volt_result < TV_OUT_EARPHONE_HIGH_LIMIT))
                {	   			
                    aux_id_no = AUX_ID_TVOUT;
                }		
                //disable TVOUT
                enable_tv_encoder(KAL_FALSE);
                deinit_tv();
                aux_tvout_on=KAL_FALSE;
	   	    }
        }
        #endif
    }
   //earphone part
   #ifdef TV_OUT_SUPPORT     
   if(aux_id_no!=AUX_ID_UART&&aux_id_no!=AUX_ID_TVOUT&&aux_tvout_on!=KAL_TRUE)    
   #else
   if(aux_id_no!=AUX_ID_UART)       
   #endif
   {
      if(aux_detect_mode==KAL_FALSE)//normal mode 
      {
         #ifdef AUX_DEBUG
          dbg_print("Normal mode 2.2V \n\r");           
         #endif 
         if(((NORMAL_EARPHONE_ADC_LOW <aux_volt_result)&& (aux_volt_result< NORMAL_EARPHONE_ADC_HIGH) )||(aux_volt_result< SENDKEY_ADC)) 
         {  
            #ifdef AUX_DEBUG
            dbg_print("Earphone  \n\r");
            dbg_print("AUX voltage = %d\n\r",aux_volt_result);
            #endif
            if(*pre_id==AUX_ID_EARPHONE||*pre_id==AUX_ID_KEY_PRESS||*pre_id==AUX_ID_KEY_RELEASE)     
            {
            	if(aux_volt_result< SENDKEY_ADC)
            	{ 
            	   aux_id_no = AUX_ID_KEY_PRESS;  
            	}
            	else
            	{
            	   aux_id_no = AUX_ID_KEY_RELEASE;
            	}
            }
            else
            {
            	 aux_custom_ptr->aux_uart_func(KAL_FALSE); //if uart switch pin not defined, this line will do nothing
            	 aux_id_no =AUX_ID_EARPHONE;	
            }
         }
         else if((aux_volt_result> NORMAL_EARPHONE_ADC_HIGH))
         {
            
            aux_id_no= AUX_ID_PLUGOUT;
         }
         else
            {
                aux_id_no = *pre_id;
               
            }
      }
      else if(aux_detect_mode==KAL_TRUE) //Single mode
      {
         #ifdef AUX_DEBUG
         dbg_print("Single mode 1.9V \n\r");   
         #endif
         if(((SINGLE_EARPHONE_ADC_LOW <aux_volt_result)&& (aux_volt_result< SINGLE_EARPHONE_ADC_HIGH) )||(aux_volt_result< SENDKEY_ADC)) 
         {           
            #ifdef AUX_DEBUG
            dbg_print("Earphone  \n\r");
            dbg_print("AUX voltage = %d\n\r",aux_volt_result);
            #endif
            if(*pre_id==AUX_ID_EARPHONE||*pre_id==AUX_ID_KEY_PRESS||*pre_id==AUX_ID_KEY_RELEASE)     
            {
            	if(aux_volt_result< SENDKEY_ADC)
            	{ 
            	   aux_id_no = AUX_ID_KEY_PRESS;  
            	}
            	else
            	{
            	   aux_id_no = AUX_ID_KEY_RELEASE;
            	}
            }
            else
            {
            	 aux_custom_ptr->aux_uart_func(KAL_FALSE); //if uart switch pin not defined, this line will do nothing
            	 aux_id_no =AUX_ID_EARPHONE;	
            }	
         }
         else
         {
            #ifdef AUX_DEBUG
            dbg_print("Abnormal mode \n\r");
            dbg_print("AUX voltage = %d\n\r",aux_volt_result);
            #endif
            aux_id_no= AUX_ID_PLUGOUT;
         }
      }                   
   }
	#if defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)
	if (*pre_id != aux_id_no)
	{      	
		if(aux_id_no!=AUX_ID_KEY_RELEASE)
		{
			#ifdef TV_OUT_SUPPORT                     
			if((*pre_id == AUX_ID_TVOUT)&&(aux_id_no == AUX_ID_PLUGOUT))
			{
				AUX_Sendilm(MOD_AUX,MOD_UEM,MSG_ID_AUX_ID,AUX_ID_TVOUT_OUT);
			}
			#endif
			AUX_Sendilm(MOD_AUX,MOD_UEM,MSG_ID_AUX_ID,aux_id_no);
		}
		*pre_id = aux_id_no;  
		g_bPlugIn = KAL_TRUE;
		if(aux_id_no==AUX_ID_PLUGOUT) 
 			g_bPlugIn = KAL_FALSE;
	}
	if((g_bPlugIn == KAL_TRUE)&& (aux_id_no==AUX_ID_PLUGOUT))
		stack_start_timer(&aux_timer, 1, POLLING_INTERVAL);/*start polling timer*/
	else if(poll_timer==KAL_TRUE)
		stack_start_timer(&aux_timer, 1, POLLING_INTERVAL);/*start polling timer*/
	
	aux_polling_status = AUX_STATUS_ORG;
	#else //defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)
   if (*pre_id != aux_id_no)
   {      
      if((aux_id_no!=AUX_ID_KEY_RELEASE)&&(aux_id_no!=AUX_ID_PLUGOUT))
      {
         #ifdef AUX_DEBUG
         dbg_print("Send EARPHONE msg to MMI \n\r");
         dbg_print("AUX ID  = %d\n\r",aux_id_no);
         #endif
         AUX_Sendilm(MOD_AUX,MOD_UEM,MSG_ID_AUX_ID,aux_id_no);        
       }
       if(aux_id_no!=AUX_ID_PLUGOUT) 
          *pre_id = aux_id_no;      
   }   
   //error state or poll timer on 
   if(aux_id_no==AUX_ID_PLUGOUT)
      stack_start_timer(&aux_timer, 1, POLLING_INTERVAL);//start polling timer 
   else if(poll_timer==KAL_TRUE&&aux_id_no!=AUX_ID_UART&&aux_id_no!=AUX_ID_TVOUT)
      stack_start_timer(&aux_timer, 1, POLLING_INTERVAL);//start polling timer   
	#endif //defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)        
}
#endif

DCL_HANDLE aux_open_and_create(DCL_UINT16 DCL_ADC_CHANNEL)
{
   DCL_HANDLE adc_handle;
   DCL_STATUS st;
   ADC_CTRL_GET_PHYSICAL_CHANNEL_T adc_get_physical_channel;
   ADC_CTRL_CREATE_OBJECT_T        adc_create_object;
   
   adc_handle = DclSADC_Open(DCL_ADC, FLAGS_NONE);
   adc_get_physical_channel.u2AdcName = DCL_ADC_CHANNEL;
   st = DclSADC_Control(adc_handle, ADC_CMD_GET_CHANNEL, (DCL_CTRL_DATA_T *)&adc_get_physical_channel);
   if(st != STATUS_OK)
		ASSERT(0);
   
   
   adc_create_object.u1OwnerId = MOD_AUX;
   adc_create_object.u1AdcChannel = adc_get_physical_channel.u1AdcPhyCh;
   adc_create_object.u4Period = 2;
   adc_create_object.u1EvaluateCount = 100;
   adc_create_object.fgSendPrimitive = KAL_TRUE;
   st = DclSADC_Control(adc_handle, ADC_CMD_CREATE_OBJECT, (DCL_CTRL_DATA_T *)&adc_create_object);
   if(st != STATUS_OK)
		ASSERT(0);

   return adc_handle;
}

#if (defined(__HEART_RATE_ENABLE__)&& defined(__HEART_RATE_BMD101_UART__))
kal_uint8 uart_handler = 0xff;
#define CARDIO_PORT    uart_port2 
#define CARDIO_OWNER_ID    MOD_AUX

extern const char gpio_heart_rate_cs_pin;
extern const char gpio_heart_rate_reset_pin;


void PowerControl_Cardio(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
    PMU_CTRL_LDO_BUCK_SET_VOLTAGE val1;
	
	kal_prompt_trace(MOD_AUX,"PowerControl_Cardio = %d", enable);
		
	handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
	val1.voltage = PMU_VOLT_03_300000_V;	  
	val1.mod = VCAMD; 				
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val1);
	   
	val.enable = enable;
	val.mod = VCAMD;
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);

	if(enable)
		L1SM_SleepDisable(uart_handler);  
	else
		L1SM_SleepEnable(uart_handler);  

}

static DCL_UINT16 UART_GetBytesAvail(DCL_DEV port)
{
 DCL_HANDLE handle;
 UART_CTRL_RX_AVAIL_T data;
 
  handle = DclSerialPort_Open(port,0);
  DclSerialPort_Control(handle,SIO_CMD_GET_RX_AVAIL, (DCL_CTRL_DATA_T*)&data);
  DclSerialPort_Close(handle);
  return data.u2RetSize;
}

static kal_uint16 UART_GetBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 *status, module_type ownerid)
{
    DCL_HANDLE handle;
    UART_CTRL_GET_BYTES_T data;
    data.u4OwenrId = ownerid;
    data.u2Length = Length;
    data.puBuffaddr = Buffaddr;
    data.pustatus = status;
    handle = DclSerialPort_Open(port,0);
    DclSerialPort_Control(handle,SIO_CMD_GET_BYTES, (DCL_CTRL_DATA_T*)&data);
    return data.u2RetSize;
}


static void UART_TurnOnPower(UART_PORT port, kal_bool on)
{
    DCL_HANDLE handle;
    UART_CTRL_POWERON_T data;
    
    handle = DclSerialPort_Open(port, 0);
    data.bFlag_Poweron = on;
    DclSerialPort_Control(handle, UART_CMD_POWER_ON, (DCL_CTRL_DATA_T*)&data);
    
    DclSerialPort_Close(handle);
}
static void UART_SetDCBConfig(DCL_DEV port, UART_CONFIG_T *UART_Config, DCL_UINT32 ownerid)
{
 DCL_HANDLE handle;
 UART_CTRL_DCB_T data;
 
 data.u4OwenrId = ownerid;
 data.rUARTConfig.u4Baud = UART_Config->u4Baud;
 data.rUARTConfig.u1DataBits = UART_Config->u1DataBits;
 data.rUARTConfig.u1StopBits = UART_Config->u1StopBits;
 data.rUARTConfig.u1Parity = UART_Config->u1Parity;
 data.rUARTConfig.u1FlowControl = UART_Config->u1FlowControl;
 data.rUARTConfig.ucXonChar = UART_Config->ucXonChar;
 data.rUARTConfig.ucXoffChar = UART_Config->ucXoffChar;
 data.rUARTConfig.fgDSRCheck = UART_Config->fgDSRCheck;
 handle = DclSerialPort_Open(port,0);
 DclSerialPort_Control(handle,SIO_CMD_SET_DCB_CONFIG, (DCL_CTRL_DATA_T*)&data);
 DclSerialPort_Close(handle);
}

static kal_uint32 UART_Open(UART_PORT port, module_type ownerid)
{
  DCL_HANDLE handle;
   UART_CTRL_OPEN_T data;
   kal_uint32  status;
 
  data.u4OwenrId = ownerid;
  handle = DclSerialPort_Open(port,0);
   status = DclSerialPort_Control(handle,SIO_CMD_OPEN, (DCL_CTRL_DATA_T*)&data);
 
   return status;
}
static module_type UART_GetOwnerID(UART_PORT port)
{
 DCL_HANDLE handle;
 UART_CTRL_OWNER_T data;
 handle = DclSerialPort_Open(port,0);
 DclSerialPort_Control(handle,SIO_CMD_GET_OWNER_ID, (DCL_CTRL_DATA_T*)&data);
 return (module_type)(data.u4OwenrId);
 
}
static void UART_SetOwner(UART_PORT port, module_type ownerid)
{
 DCL_HANDLE handle;
 UART_CTRL_OWNER_T data;
 data.u4OwenrId = ownerid;
 handle = DclSerialPort_Open(port,0);
 DclSerialPort_Control(handle,SIO_CMD_SET_OWNER, (DCL_CTRL_DATA_T*)&data);
}

void CardioUART_Init(void)
{
       kal_uint32 status = 0;
	   kal_uint32 CARDIO_owner_save = 0xff;
	   UART_CONFIG_T *DCBdefault;
	   DCL_HANDLE gpio_cs_handle;
	   DCL_HANDLE gpio_rst_handle;
  	   UART_CONFIG_T  UART_DefaultConfig =
   {
      UART_BAUD_57600,    /* baud; */
         len_8,               /* dataBits; */
         sb_1,                /*stopBits; */
         pa_none,             /* parity; */
         fc_none,             /*no flow control*/
         0x11,                /* xonChar; */
         0x13,                /* xoffChar; */
         KAL_FALSE
   };
	   // get sleep handler and lock sleep
       uart_handler = L1SM_GetHandle();
       //L1SM_SleepDisable(uart_handler);  
	
       //开启uart power
       UART_TurnOnPower(CARDIO_PORT, KAL_TRUE);  //open uart
       
	gpio_cs_handle=DclGPIO_Open(DCL_GPIO,gpio_heart_rate_cs_pin); 
	DclGPIO_Control(gpio_cs_handle,GPIO_CMD_SET_MODE_0,NULL);  //set gpio mode		
	DclGPIO_Control(gpio_cs_handle,GPIO_CMD_SET_DIR_OUT,NULL);  //set dir output
	DclGPIO_Control(gpio_cs_handle,GPIO_CMD_WRITE_HIGH,NULL);  //output high

	gpio_rst_handle=DclGPIO_Open(DCL_GPIO,gpio_heart_rate_reset_pin); 
	DclGPIO_Control(gpio_rst_handle,GPIO_CMD_SET_MODE_0,NULL);  //set gpio mode				
	//DclGPIO_Control(gpio_rst_handle,GPIO_CMD_ENABLE_PULL,NULL);  //enable pull-low
	//DclGPIO_Control(gpio_rst_handle,GPIO_CMD_SET_PULL_HIGH,NULL);  //low
	DclGPIO_Control(gpio_rst_handle,GPIO_CMD_SET_DIR_OUT,NULL);  //set dir output	
	DclGPIO_Control(gpio_rst_handle,GPIO_CMD_WRITE_HIGH,NULL);  //output high
	
      //防止需要使用的uart port被其他模块所打开，故使用如下函数将当前的owner id注册到该uart port
       //CARDIO_owner_save = UART_GetOwnerID(CARDIO_PORT);
      // UART_SetOwner(CARDIO_PORT, CARDIO_OWNER_ID);
 
       status =  UART_Open(CARDIO_PORT, CARDIO_OWNER_ID);
	   kal_prompt_trace(MOD_AUX,"UART_Open return %d", status);
      
	   DCBdefault = (UART_CONFIG_T *)&UART_DefaultConfig;
 
      //  设定uart 波特率等信息，注意在调用此函数之前需要先初始化Dcb结构体
       UART_SetDCBConfig(CARDIO_PORT, DCBdefault, CARDIO_OWNER_ID);
	   //DRV_UART_WriteReg(UART_IER(UART1_base),0x01); //only enable RX IRQ
 
}

void parsePayload(kal_uint8 *data, kal_uint8 len)
{
	kal_uint8 bytesParse = 0;
	ilm_struct  *aux_ilm ;

	mmi_sensor_hr_data_ind_struct *hate_data;
	
	kal_prompt_trace(MOD_AUX,"parsePayload enter!");
	hate_data = (mmi_sensor_hr_data_ind_struct *)construct_local_para(sizeof(mmi_sensor_hr_data_ind_struct), TD_CTRL);
	
	bytesParse = *data++;
	
	switch(bytesParse)
		{
			case 0x02:
				if(0 == *data++)
						{
							kal_prompt_trace(MOD_AUX,"Poor Signal detected!");
							//*Heart_rate = 0;
							hate_data->hr_data = 0;
						}
					else
						{
							//HEAT_RATE
							if(*data++ == 0x03)
								{
									//Heart_rate = data;
									hate_data->hr_data = *data;
									kal_prompt_trace(MOD_AUX,"Heart_rate = %d!", *data);							
									
								}
							else
							{
								hate_data->hr_data = 0; //???
							}
						}
	#if 1
	//send MSG to MOD_UEM
		DRV_BuildPrimitive(aux_ilm,
				           MOD_AUX,
				           MOD_MMI,
				           MSG_ID_MMI_EQ_HR_SENSOR_DATA_IND,
				           hate_data);
		msg_send_ext_queue(aux_ilm);
		
	#endif
				break;

			case 0x80:
				//kal_prompt_trace(MOD_AUX,"Multi Bytes, do nothing!");
				break;

			default:
				//kal_prompt_trace(MOD_AUX,"Others case, don't care!");
				break;
		
		}
	
	//kal_prompt_trace(MOD_AUX,"parsePayload exit!");
}

kal_uint8 packets[2048];
kal_uint16 count = 0;
#define BUFF_LENGTH 3000
#define PAYLOAD_LEN 30

void parsePackets(kal_uint8 *Buff, kal_uint16 length)
{
	kal_uint16 i = 0;
	kal_uint8 j = 0;
	kal_uint8 payload[PAYLOAD_LEN];
	kal_uint32 checksum = 0;
	kal_uint8 pLength = 0;
	kal_uint8 c = 0;

	//kal_prompt_trace(MOD_AUX,"parsePackets enter, length = %d!", length);
	while((Buff-packets)<length)
		{
		
			count = 0; //clean count
			//one packet at least 8 bytes
			if((length-(Buff-packets))<8)
				{
					for(j=0; (Buff-packets)<length; j++)
						{
							packets[j] = *Buff++;
						}
					count = j;
					kal_prompt_trace(MOD_AUX,"Not enough 8 bytes,count = %d!", count);
					break;
				}
			
			//HEAD[0] = 0xAA
			if(*Buff++ != 0xAA) continue;			
			
			//HEAD[1] = 0xAA
			if(*Buff++ != 0xAA) continue;
			
			//[PLENGTH] byte
			pLength = *Buff++;
			
			if(pLength > PAYLOAD_LEN) continue;
			
			//kal_prompt_trace(MOD_AUX,"pLength = %d, i = %d!, count = %d", pLength,i,count);
				//not enough one packet, save
			if((length-(Buff-packets))< (pLength+1))
					{
						for(j=0; (Buff-packets)<length; j++)
							{
								i = i-3; //save HEAD[0], HEAD[1],[PLENGTH]
								packets[j] = *Buff++;
							}
						count = j;
						kal_prompt_trace(MOD_AUX,"Not enough one packet,left %d, pLength = %d, length = %d!", count,pLength,length);
						continue;
			}
		else
			{

				if(pLength != 0x12)  //not used, lose packet
					{
						Buff += (pLength+1);
						continue;
					}
				else  //heat rate
				{
						
						checksum = 0;  //clear checksum
						
						for(j=0; j<pLength; j++)
							{
								
								payload[j] = *Buff++;
								checksum += payload[j];
							}
						//kal_prompt_trace(MOD_AUX,"checksum = %x!", checksum);
						checksum &= 0xFF;
						checksum = ~checksum & 0xFF;

						c = *Buff++;
						
						if(c != checksum)
							{
								kal_prompt_trace(MOD_AUX,"checksum wrong, packet = %x, checksum = %x!", c,checksum);
								continue;
							}

						//kal_prompt_trace(MOD_AUX,"checksum ok!");
						
						parsePayload(payload, pLength);

					////	kal_sleep_task(10);
						
					}
				
			}
		}
	//kal_prompt_trace(MOD_AUX,"parsePackets exit!");
}
#endif
/*************************************************************************
* FUNCTION                                                            
*	aux_task_main
*
* DESCRIPTION                                                           
*	This function implements xyz task's entry function
*
* PARAMETERS
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void aux_task_main( task_entry_struct * task_entry_ptr )
{
	ilm_struct	      current_ilm;
	ilm_struct          *aux_ilm ;
#if !defined(__ACCDET_SUPPORT__)  	
	AUX_ID aux_id_nbr;
	AUX_ID              pre_id = AUX_ID_PLUGOUT;              
#endif //#if !defined(__ACCDET_SUPPORT__)  
   //kal_bool            started_by_timer1 = KAL_FALSE;
           
	//Engineering mode result
	kal_int32           vbat_value=0;
	kal_int32           visense_value=0;
	kal_int32           vcharger_value=0;
	kal_int32           vbattemp_value=0;
	kal_int32           vaux_value=0;
	bmt_adc_measure_done_conf_struct *mea_done_ptr;
	adc_all_channel_struct *adc_all_channel_result;
	kal_uint16            adc_measure_count=0;
	#if (!defined(__ACCDET_SUPPORT__)&& !defined(__DRV_EXT_ACCESSORY_DETECTION__))
	stack_timer_struct               *check_timer_index; 
	#endif
   /* DCL ADC */
   
   #if defined(__BMT_2_0_ARCHITECTURE__)
   DCL_HANDLE bmt_handle;	
   #endif
   DCL_HANDLE adc_handle_vbat;
   DCL_HANDLE adc_handle_visense;
   DCL_HANDLE adc_handle_vcharger;
   DCL_HANDLE adc_handle_vbattemp;

#if (!defined(__ACCDET_SUPPORT__)&& !defined(__DRV_EXT_ACCESSORY_DETECTION__))
   DCL_HANDLE adc_handle_vaux;
#endif //#if (!defined(__ACCDET_SUPPORT__)&& !defined(__DRV_EXT_ACCESSORY_DETECTION__))

#if !defined(__BMT_2_0_ARCHITECTURE__)	
   ADC_CTRL_TRANSFORM_INTO_TEMP_T adc_battemp;
   ADC_CTRL_TRANSFORM_INTO_CURR_T adc_batcurr;
#endif //#if !defined(__BMT_2_0_ARCHITECTURE__)	

#if (defined(__HEART_RATE_ENABLE__)&& defined(__HEART_RATE_BMD101_UART__))
	//cardio
	kal_uint16 avail = 0;
	kal_uint16 length = 0;
	kal_int32 checksum = 0;
	kal_uint8 val = 0;
	kal_uint8 pLength =0;
	kal_uint16 i =0;	
	kal_uint8 *BuffAddr = packets;
	
	//SLA_Enable();

	//Turn on power to test
	CardioUART_Init();
	//PowerControl_Cardio(KAL_TRUE);
#endif
	//Engineering mode

   #if defined(__BMT_2_0_ARCHITECTURE__)	
   bmt_handle = DclBMT_Open(DCL_BMT, FLAGS_NONE);
   #endif
   adc_handle_vbat = aux_open_and_create(DCL_VBAT_ADC_CHANNEL);
   adc_handle_visense = aux_open_and_create(DCL_VISENSE_ADC_CHANNEL);
   adc_handle_vcharger = aux_open_and_create(DCL_VCHARGER_ADC_CHANNEL);
   adc_handle_vbattemp = aux_open_and_create(DCL_VBATTMP_ADC_CHANNEL);

	#if (!defined(__ACCDET_SUPPORT__)&& !defined(__DRV_EXT_ACCESSORY_DETECTION__))
	stack_init_timer(&aux_timer, "AUX_TIMER", MOD_AUX);
   adc_handle_aux = aux_open_and_create(DCL_AUX_ADC_CHANNEL);
   adc_handle_vaux = aux_open_and_create(DCL_AUX_ADC_CHANNEL);
	
	#if !defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)
	EINT_Registration(AUX_EINT_NO,KAL_TRUE,aux_state,AUX_EINT_HISR, KAL_TRUE);
	#endif
	
	#endif


	ACCDET_version_check();

	#if (defined(__ACCDET_SUPPORT__)||defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__))
	IRQUnmask(IRQ_ACCDET_CODE);
	#endif

	#ifdef __LINE_IN_SUPPORT__//for line in
	EINT_Registration(LINE_IN_EINT_NO,KAL_TRUE,line_in_eint_state,LINE_IN_EINT_HISR, KAL_TRUE);
	EINT_Set_Sensitivity(LINE_IN_EINT_NO,LEVEL_SENSITIVE);
	EINT_Set_HW_Debounce(LINE_IN_EINT_NO, 10);
	EINT_SW_Debounce_Modify(LINE_IN_EINT_NO,10);
	#endif

	
	#ifdef __BT_NFC_TAG_SUPPORT__//for nfc tag
	EINT_Registration(NFC_TAG_EINT_NO,KAL_TRUE,nfc_tag_eint_state,NFC_TAG_EINT_HISR, KAL_TRUE);
	EINT_SW_Debounce_Modify(NFC_TAG_EINT_NO,10);
	#endif
	
	aux_custom_ptr = (aux_func_struct*)aux_GetFunc();
	aux_custom_init();

	while(1)
   	{
      receive_msg_ext_q_for_stack(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
      
      switch(current_ilm.msg_id)
      {
#if !defined(__ACCDET_SUPPORT__)      
         case MSG_ID_AUX_CALL_SETUP_REQ_IND:                                       
            poll_timer=KAL_TRUE;   
            #ifdef TV_OUT_SUPPORT      
            if((aux_timer_open==1&&pre_id!=AUX_ID_UART&&pre_id!=AUX_ID_TVOUT) && (call_setup_cnt == 0))
            #else
            if((aux_timer_open==1&&pre_id!=AUX_ID_UART) && (call_setup_cnt == 0))
            #endif
            {   
               	aux_detect_mode=(kal_bool)AFE_TurnOnMicBias();//voltage source  
				#if (!defined(__ACCDET_SUPPORT__)&& !defined(__DRV_EXT_ACCESSORY_DETECTION__))
			aux_remove_adc_channel(adc_handle_aux);	
               	stack_start_timer(&aux_timer, 0, TURN_ON_BIAS_INTERVAL); 
				#endif //#if defined(__ACCDET_SUPPORT__)
            }    
            call_setup_cnt++;
            break;
         case MSG_ID_AUX_CALL_DISCONNECT_REQ_IND:
            if (call_setup_cnt>0)
               	call_setup_cnt--;
            if (call_setup_cnt==0)
            {
            	//poll_timer=KAL_FALSE;
				
				#if defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)
				if (KAL_FALSE == g_bAudioBufferOpen)
				#endif //defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)
				{
            	poll_timer=KAL_FALSE;
            	AFE_TurnOffMicBias();//voltage source 
            	stack_stop_timer(&aux_timer);
            }
            }
            break;         
         case MSG_ID_AUX_PLUGIN:
            break;
         
         case MSG_ID_AUX_PLUGOUT:   
            //Notify MMI the aux is plugout            
			#ifdef TV_OUT_SUPPORT                     
           	if(pre_id!=AUX_ID_TVOUT)
           	aux_id_nbr = AUX_ID_PLUGOUT;
           	else
           	aux_id_nbr = AUX_ID_TVOUT_OUT;	
           	#else
           	aux_id_nbr = AUX_ID_PLUGOUT;
           	#endif	
           	pre_id = AUX_ID_PLUGOUT;            

			AUX_Sendilm(MOD_AUX,MOD_UEM,MSG_ID_AUX_ID,aux_id_nbr);
        
			#if (!defined(__ACCDET_SUPPORT__)&& !defined(__DRV_EXT_ACCESSORY_DETECTION__))
            //aux_remove_adc_channel(aux_adc_logic_id);
            aux_remove_adc_channel(adc_handle_aux);
			#endif //#if defined(__ACCDET_SUPPORT__)
            break;
#endif //#if defined(__ACCDET_SUPPORT__)         
         case MSG_ID_READ_ALL_ADC_CHANNEL_REQ:
            adc_measure_count=0;
            vbat_value = 0;
            //aux_read_adc_channel(vbat_adc_logic_id);
            aux_read_adc_channel(adc_handle_vbat);
            visense_value = 0;
            //aux_read_adc_channel(visense_adc_logic_id);
            aux_read_adc_channel(adc_handle_visense);
            vcharger_value = 0;
            //aux_read_adc_channel(vcharger_adc_logic_id);
            aux_read_adc_channel(adc_handle_vcharger);
            vbattemp_value = 0;
            //aux_read_adc_channel(vbattemp_adc_logic_id);
            aux_read_adc_channel(adc_handle_vbattemp);
            vaux_value = 0;
			#if (!defined(__ACCDET_SUPPORT__)&& !defined(__DRV_EXT_ACCESSORY_DETECTION__))
            //aux_read_adc_channel(vaux_adc_logic_id);
            aux_read_adc_channel(adc_handle_vaux);
			#endif //#if defined(__ACCDET_SUPPORT__)
            break;
            
         case MSG_ID_BMT_ADC_MEASURE_DONE_CONF:
            
            mea_done_ptr = (bmt_adc_measure_done_conf_struct *)current_ilm.local_para_ptr;
			
			#if (!defined(__ACCDET_SUPPORT__)&& !defined(__DRV_EXT_ACCESSORY_DETECTION__))
            //if (mea_done_ptr->adc_sche_id == aux_adc_logic_id) /*normal mode*/
            if (mea_done_ptr->adc_handle == adc_handle_aux) /*normal mode*/
            {
               //aux_remove_adc_channel(aux_adc_logic_id);
               aux_remove_adc_channel(adc_handle_aux);
						   #if defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)
						   if((KAL_TRUE != poll_timer)&&(KAL_FALSE == g_bAudioBufferOpen))
						   #else
						   if(KAL_TRUE != poll_timer)  //not turn off microbias when talking
						   #endif //defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)
						   AFE_TurnOffMicBias();
			   
            #if defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)  
				//Note: //In hybrid mode, if need calculate average value of ADC read by BMT, need to increase TURN_ON_BIAS_INTERVAL
			   if ((aux_timer_open==1)&&(aux_polling_status == AUX_STATUS_TIMER0_TIMEOUT))
			   	{
               aux_read_result(&pre_id,current_ilm.local_para_ptr);
			   	}
            #else 
               aux_read_result(&pre_id,current_ilm.local_para_ptr);
            #endif
            }
            #endif
            //if (mea_done_ptr->adc_sche_id == vbat_adc_logic_id)
            if (mea_done_ptr->adc_handle == adc_handle_vbat)
            {
               adc_measure_count++;
               vbat_value = (kal_int32)mea_done_ptr->volt;
               //aux_remove_adc_channel(vbat_adc_logic_id);
               aux_remove_adc_channel(adc_handle_vbat);
            }
            //else if (mea_done_ptr->adc_sche_id == visense_adc_logic_id)
            else if (mea_done_ptr->adc_handle == adc_handle_visense)
            {
               adc_measure_count++;
               visense_value = (kal_int32)mea_done_ptr->volt;
               //aux_remove_adc_channel(visense_adc_logic_id);
               aux_remove_adc_channel(adc_handle_visense);
            }
            //else if (mea_done_ptr->adc_sche_id == vcharger_adc_logic_id)
            else if (mea_done_ptr->adc_handle == adc_handle_vcharger)
            {
               adc_measure_count++;
               vcharger_value = (kal_int32)mea_done_ptr->volt;
               //aux_remove_adc_channel(vcharger_adc_logic_id);
               aux_remove_adc_channel(adc_handle_vcharger);
            }
            //else if (mea_done_ptr->adc_sche_id == vbattemp_adc_logic_id)
            else if (mea_done_ptr->adc_handle == adc_handle_vbattemp)
            {
               adc_measure_count++;
               vbattemp_value = (kal_int32)mea_done_ptr->volt;
               //aux_remove_adc_channel(vbattemp_adc_logic_id);
               aux_remove_adc_channel(adc_handle_vbattemp);
            }
			#if (!defined(__ACCDET_SUPPORT__)&& !defined(__DRV_EXT_ACCESSORY_DETECTION__))
            //else if (mea_done_ptr->adc_sche_id == vaux_adc_logic_id)
            else if (mea_done_ptr->adc_handle == adc_handle_vaux)
            {
               adc_measure_count++;
               vaux_value = (kal_int32)mea_done_ptr->volt;
               //aux_remove_adc_channel(vaux_adc_logic_id);
               aux_remove_adc_channel(adc_handle_vaux);
            }
           	if(adc_measure_count==5)
			#else
           	if(adc_measure_count==4) //only create 4 objects.
			#endif   
           	{
               adc_measure_count=0;
	           adc_all_channel_result = (adc_all_channel_struct*)construct_local_para(sizeof(adc_all_channel_struct), TD_CTRL);

  			   adc_all_channel_result->vbat = vbat_value;	   
               adc_all_channel_result->vcharger = vcharger_value;
               adc_all_channel_result->vaux = vaux_value;

			   #if defined(__BMT_2_0_ARCHITECTURE__)	
           	   {
           	   BMT_CTRL_GET_CHARGING_CURRENT em_get_charging_current;
       		   BMT_CTRL_GET_BAT_TEMP em_get_vbat_temp;
       		   
				   em_get_vbat_temp.VBatTmp = vbattemp_value;
				   adc_all_channel_result->bat_temp  = DclBMT_Control(bmt_handle, BMT_CMD_GET_VBATTMP, (DCL_CTRL_DATA_T *)&em_get_vbat_temp);

				   em_get_charging_current.VBat = vbat_value;
				   em_get_charging_current.VSense = visense_value;
				   adc_all_channel_result->charge_current= DclBMT_Control(bmt_handle, BMT_CMD_GET_CHARGING_CURRENT, (DCL_CTRL_DATA_T *)&em_get_charging_current);
           	   }
			   #else
			   adc_battemp.u4Volt = vbattemp_value;
			   DclSADC_Control(adc_handle_vbattemp,ADC_CMD_TRANSFORM_INTO_TEMP,(DCL_CTRL_DATA_T *)&adc_battemp);
               adc_all_channel_result->bat_temp = adc_battemp.u4Temp;


	               adc_batcurr.u4Volt = visense_value - vbat_value;
	               DclSADC_Control(adc_handle_visense, ADC_CMD_TRANSFORM_INTO_CURR, (DCL_CTRL_DATA_T *)&adc_batcurr);
	               adc_all_channel_result->charge_current = adc_batcurr.u4Curr;
	           #endif

               DRV_BuildPrimitive(aux_ilm,
                      MOD_AUX,
                      MOD_UEM,
                      MSG_ID_ADC_ALL_CHANNEL_CONF,
                      adc_all_channel_result);
                      
               msg_send_ext_queue(aux_ilm);
            }
            break;
	#if (!defined(__ACCDET_SUPPORT__)&& !defined(__DRV_EXT_ACCESSORY_DETECTION__))
         case MSG_ID_TIMER_EXPIRY: //Timer time out
            check_timer_index = (stack_timer_struct *) current_ilm.local_para_ptr;
            switch(check_timer_index->timer_indx)
            {
               	case 0://20ms timer
				#if defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)
				aux_polling_status = AUX_STATUS_TIMER0_TIMEOUT;
				#endif
					#if (!defined(__ACCDET_SUPPORT__)&& !defined(__DRV_EXT_ACCESSORY_DETECTION__))
                  if((aux_timer_open==1))            
                  {           
                     aux_read_adc_channel(adc_handle_aux);
                  }
                  else
				{
                     //aux_remove_adc_channel(aux_adc_logic_id);
                     aux_remove_adc_channel(adc_handle_aux);
				}
					#endif
                  break;
               case 1://500ms timer                  
				#if defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)
				aux_polling_status = AUX_STATUS_TIMER1_TIMEOUT;
				#endif
               		#ifdef TV_OUT_SUPPORT                  
                  	if(aux_tvout_on==KAL_FALSE)               			   			   		                            
                  	#endif
                  if(aux_timer_open==1)
                  {                                    
                  	aux_detect_mode=(kal_bool)AFE_TurnOnMicBias();//voltage source      
                  	aux_remove_adc_channel(adc_handle_aux);
                  	stack_start_timer(&aux_timer, 0, TURN_ON_BIAS_INTERVAL);
				}     
                  	break;            
               default:
                  	break;   
            }     
            break;
		case MSG_ID_AUX_AUDIO_OPEN:/*audio open handler*/
		{
			#if defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)
			aux_polling_status = AUX_STATUS_ORG;
			aux_detect_mode = (kal_bool)AFE_TurnOnMicBias();/*voltage source*/  
			if (aux_timer.dest_mod_id == MOD_AUX)
			{
				poll_timer = KAL_TRUE;
				aux_timer_open = 1;
aux_remove_adc_channel(adc_handle_aux);
				stack_start_timer(&aux_timer, 0, TURN_ON_BIAS_INTERVAL); 
			}
			kal_prompt_trace(MOD_AUX, "Audio: aux_Audio_Open_Handler()");
			#endif
		}
		break;
		case MSG_ID_AUX_AUDIO_CLOSED:/*audio closed handler*/
		{
			#if defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)
			if (aux_timer.dest_mod_id == MOD_AUX)
			{
			stack_stop_timer(&aux_timer);
			}
			g_bAudioBufferOpen = KAL_FALSE; 
			aux_polling_status = AUX_STATUS_ORG;
                         aux_remove_adc_channel(adc_handle_aux);
			//reset ACCDET
			if (pre_id == AUX_ID_PLUGOUT)//avoid this situation: AB default value is 01.
			{
				ACCDET_reset();
			}
			if (call_setup_cnt == 0)
			{
				poll_timer = KAL_FALSE;
				AFE_TurnOffMicBias();
			}
			if (g_bPlugIn == KAL_FALSE) // earphone has been plugged out.
			{
				aux_timer_open = 0;
			}
			kal_prompt_trace(MOD_AUX, "Audio: aux_Audio_Closed_Hander()");
			#endif
		}
            break; 
		#endif
	#if (defined(__HEART_RATE_ENABLE__)&& defined(__HEART_RATE_BMD101_UART__))
		case MSG_ID_UART_READY_TO_READ_IND:

			//SWLA_BEGIN("STR");
			avail = UART_GetBytesAvail(CARDIO_PORT);
			if(avail)
				{
				
					while(1)
					{
					i = 0;		
					kal_prompt_trace(MOD_AUX,"there are %d Bytes data", avail);
					length = UART_GetBytes(CARDIO_PORT,(kal_uint8 *)(BuffAddr+count),BUFF_LENGTH-count,NULL,CARDIO_OWNER_ID);
					kal_prompt_trace(MOD_AUX,"Actually get %d Bytes data", length);

				#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
				#endif
						parsePackets(BuffAddr, length+count);
					if(length!= (BUFF_LENGTH - count))
						break;
					}
				}           
	
			//SWLA_END("STP");	
		
			break;
		#endif
         default:
            break;
      }
      free_ilm(&current_ilm);
   }
}

/*************************************************************************
* FUNCTION                                                            
*	aux_task_reset
*
* DESCRIPTION
*	This function implements xyz's reset handler
*
* PARAMETERS 
*	task_index	-	task's index
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool aux_task_reset(task_indx_type task_indx)
{
  	/* Do task's reset here.
	 * Notice that: shouldn't execute modules reset handler since 
	 * stack_task_reset() will do. */
	return KAL_TRUE;
}

/*************************************************************************
* FUNCTION                                                            
*	aux_task_end
*
* DESCRIPTION
*	This function implements xyz's termination handler
*
* PARAMETERS 
*	task_index	-	task's index
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool aux_task_end(task_indx_type task_indx)
{
  	/* Do task's termination here.
	 * Notice that: shouldn't execute modules reset handler since 
	 * stack_task_end() will do. */
	return KAL_TRUE;
}

/*************************************************************************
* FUNCTION                                                            
*	AUX_Sendilm
*
* DESCRIPTION
*	This function implements AUX massage sending.
*
* PARAMETERS 
*	
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/

void AUX_Sendilm(module_type src_mod, module_type dst_mod, msg_type msgid, AUX_ID aux_id_no)
{
   aux_id_struct    *aux_id_data;
   ilm_struct       *aux_ilm;
   
   aux_id_data = (aux_id_struct*)
      construct_local_para(sizeof(aux_id_struct), TD_CTRL);	   
   aux_id_data->aux_id = aux_id_no;
   
   DRV_BuildPrimitive(aux_ilm,
      src_mod,
      dst_mod,
      msgid,
      aux_id_data);
   
   msg_send_ext_queue(aux_ilm);
}

#endif //#if !defined(__SMART_PHONE_MODEM__)

//liming remove for slim
//UART Detection
#if 0
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
/* under construction !*/
/* under construction !*/
#endif

#endif /*__L1_STANDALONE__*/
