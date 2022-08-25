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
 *    dcl_gpt.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines DCL (Driver Common Layer) of the GPT driver.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features_gpt.h"
#include "drv_comm.h"
#include "gpt_hw.h"
#include "dcl_gpt_hw.h"
#include "dcl_gpt.h"
#include "dcl.h"
#include "drv_hisr.h"
#include "us_timer.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "drvpdn.h"
#include "l1_interface.h"
#include "drv_trc.h"

//#define DCL_GPT_INTERFACE
//#ifdef  DCL_GPT_INTERFACE

#if !defined(DRV_GPT_OFF)

//DCL_GPT_CB  this software gpt provide register callback function.
#define DCL_GPT_CB_MAGIC_NUM  							0x02000000
#define DCL_GPT_CB_IS_HANDLE_MAGIC(handl_)  ((handl_)& DCL_GPT_CB_MAGIC_NUM)
#define DCL_GPT_CB_GET_DEV(handle_) 				((handle_) & (~DCL_GPT_CB_MAGIC_NUM))

//DCL_GPT_BW this software gpt provide busywait function.
#define DCL_GPT_BW_MAGIC_NUM  							0x04000000
#define DCL_GPT_BW_IS_HANDLE_MAGIC(handl_) 	((handl_)& DCL_GPT_BW_MAGIC_NUM)
#define DCL_GPT_BW_GET_DEV(handle_) 				((handle_) & (~DCL_GPT_BW_MAGIC_NUM))

//DCL_FGPT this software gpt provide return free run gpt value function.
#define DCL_FGPT_MAGIC_NUM    						 0x08000000
#define DCL_FGPT_IS_HANDLE_MAGIC(handl_) 	 ((handl_)& DCL_FGPT_MAGIC_NUM)
#define DCL_FGPT_GET_DEV(handle_) 				 ((handle_) & (~DCL_FGPT_MAGIC_NUM))

//this define may fadeout.
#define  GPTProcess(module)   \
{\
   if((GPTTimer.status & (1<<module))&&(GPTTimer.GPT_TICK == GPTTimer.GPTItems[module].tick))\
   {\
      GPTTimer.status &= ~(1<<module);\
      GPTTimer.GPTItems[module].gptimer_func(GPTTimer.GPTItems[module].parameter);\
   }\
}

extern kal_uint8 L1SM_GetHandle(void);
extern void L1SM_UnIRQSleepEnable( kal_uint8 handle );
extern void L1SM_UnIRQSleepDisable(kal_uint8 handle);
extern kal_uint32 L1I_GetTimeStamp(void);



/*[start]******************SRAM or Cache select part1*****************/
#define GPT_INTERNAL_SRAM
#if defined(DRV_MISC_CACHE_REGION_SUPPORT)
  // If cache is supported, put GPT data into cahched region
  #pragma arm section rwdata = "CACHEDRW" , zidata = "CACHEDZI"
#else // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)
  // If cache is supported, put GPT data into internal SRAM
  #ifdef GPT_INTERNAL_SRAM
  #pragma arm section rwdata = "INTERNRW" , rodata = "INTERNCONST" , zidata = "INTERNZI"
  #endif
#endif // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)
/*[end]******************SRAM or Cache select part1 end *****************/

//This global variable contain software gpt control information. -->debug sabre!!
GPTStruct GPTTimer;
kal_uint32 gpt_stop_array[32];
#if defined(DRV_GPT_NEW_ARCHI)
GPTNodeStruct GPTNodeBuffer[MAX_USER_NUMBER];
DCL_UINT32 hGPTHadle;
kal_uint8 smallest_index_num = 0x0;
kal_uint8 Is_Running = KAL_FALSE;
kal_uint8 Is_HISR_Running = KAL_FALSE;
#endif

//[Software bug  fix]This global variable is to complete buzywait control flow.  [Interrupt may send out before read GPT_STA]
kal_bool BusyWaitFlag;

//[hardware bug fix] GPT3 register synchronism problem.[register may changing while APB bus fetching value]
int testcount=0;

//[System fixing] GPT should disable sleep mode for L1 layer restrict~!
#if defined(DRV_GPT_DIRECT_SLEEP_MODE_HANDLE)
#if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
static kal_uint8 gpt_sm_handle;
#endif // #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
#endif //#if defined(DRV_GPT_DIRECT_SLEEP_MODE_HANDLE)

/*[start]******************SRAM or Cache select part2 *****************/
#if defined(DRV_MISC_CACHE_REGION_SUPPORT)
  #pragma arm section rwdata, zidata
#else // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)
  #ifdef GPT_INTERNAL_SRAM
  #pragma arm section rwdata, rodata , zidata
  #endif
#endif // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)
/*[end]*******************SRAM or Cache select part end*****************/

void GPTI_HISR(void);
static kal_bool GPTI_StartItem(kal_uint8 module,kal_uint16 tick,void (*gptimer_func)(void *),void *parameter);
static void GPTI_StopItem(kal_uint8 module);
static void GPTI_BusyWait(kal_uint16 len);
static void gpt_sw_delay(void);

/*[start]***********************************debug informaiton *****************************/
#if defined(__MTK_INTERNAL__) && !defined(LOW_COST_SUPPORT) && !defined(__MAUI_BASIC__) && defined(__DRV_DBG_MEMORY_TRACE_SUPPORT__)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#define GPT_DBG(a,b) ;
#endif
/*[end]***********************************debug informaiton end *****************************/

/*-----------------------------------------------------------------------*
*																		    
*						GPT1 LISR function,								    
*				pass to gpt_hw layer as a function pointer 						    
*																		    
*------------------------------------------------------------------------*/
void GPTI_Callback(DCL_EVENT timeout)
{
	 drv_active_hisr(DRV_GPT_HISR_ID);
}

/*-----------------------------------------------------------------------*
*							GPT2 LISR function.							   
*																		   
*		the exist of this funciton is to round over busywait control flow.				    
*
*------------------------------------------------------------------------*/
void GPT2_Callback(DCL_EVENT timeout)
{
	BusyWaitFlag=KAL_TRUE;
} 

/*-----------------------------------------------------------------------

* FUNCTION
*  DclSGPT_Initialize
*
* DESCRIPTION
*  This function is to initialize SW GPT module. 
*
* PARAMETERS
*	DCL_STATUS_OK
*
* RETURNS
*  none
*
*------------------------------------------------------------------------*/
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif 
DCL_STATUS DclSGPT_Initialize(void)
{
	DCL_HANDLE gpt2;
	HGPT_CTRL clock;
	HGPT_CTRL set_gpt;

	#if defined(DRV_GPT_DIRECT_SLEEP_MODE_HANDLE)
	#if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
	gpt_sm_handle = L1SM_GetHandle();
	#endif // #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
	#endif //#if defined(DRV_GPT_DIRECT_SLEEP_MODE_HANDLE)

	set_gpt.rHGPTReset.u2CountValue=9;
	#if defined(DRV_GPT_NEW_ARCHI)
	clock.rHGPTClk.u4Clock=CLK_16K;
	set_gpt.rHGPTReset.fgAutoReload=KAL_FALSE;
	#else
	clock.rHGPTClk.u4Clock=CLK_1K;
	set_gpt.rHGPTReset.fgAutoReload=KAL_TRUE;
	#endif

	//register HISR.
	if (GPTTimer.hisr == NULL)
	{
		GPTTimer.hisr= (void*)0x1234;
		DRV_Register_HISR(DRV_GPT_HISR_ID, GPTI_HISR);
	}  

	//open GPT1 and set control register.
	DclHGPT_Initialize();
	GPTTimer.Hgpt_handle=DclHGPT_Open(GPT1,0);
	DclHGPT_Control(GPTTimer.Hgpt_handle,HGPT_CMD_CLK,&clock);
	DclHGPT_Control(GPTTimer.Hgpt_handle,HGPT_CMD_RESET,&set_gpt);
	DclHGPT_RegisterCallback(GPTTimer.Hgpt_handle,EVENT_HGPT_TIMEOUT,GPTI_Callback);
	DclHGPT_Close(GPTTimer.Hgpt_handle);

	//global variable initialization.
	GPTTimer.GPT_TICK = 0;
	GPTTimer.MAX_GPTIMER_ITEMS = 0;
	GPTTimer.GPTSTOP = KAL_TRUE;
	GPTTimer.status =0;
	{
		kal_uint32 i;
		for (i=0;i<32;i++)
		{
			GPTTimer.GPTUsed[i] = 0;
		}
	}

	//gpt2 initialization.
	clock.rHGPTClk.u4Clock=CLK_1K;
	gpt2=DclHGPT_Open(GPT2,0);	
	DclHGPT_Control(gpt2,HGPT_CMD_CLK,&clock);
	DclHGPT_RegisterCallback(gpt2,EVENT_HGPT_TIMEOUT,GPT2_Callback);
	DclHGPT_Close(gpt2);

	return STATUS_OK;
}

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

/*-----------------------------------------------------------------------
* FUNCTION
*  DclSGPT_Open
*
* DESCRIPTION
*  This function is to open the SW GPT module and get a handle. Note that 
* multiple opens are allowed.
*
* PARAMETERS
*	eDev - only valid for DCL_GPT1
*	flags - no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*	DCL_HANDLE_INVALID - Open failed.
*  other value - a valid handle
*
*------------------------------------------------------------------------*/
DCL_HANDLE DclSGPT_Open(DCL_DEV eDev, DCL_FLAGS flags)
{
   kal_uint8 handle;
   kal_uint32 savedMask;
   kal_uint32 i;
   if (DCL_GPT_CB==eDev)
   {
		savedMask = SaveAndSetIRQMask();
      for (i=0;i<32;i++)
	  	{
			if (GPTTimer.GPTUsed[i] == 0)
			{
				GPTTimer.GPTUsed[i] = 1;
				handle =i;
				GPTTimer.MAX_GPTIMER_ITEMS ++;
				RestoreIRQMask(savedMask);
				return DCL_GPT_CB_MAGIC_NUM|handle;
			}
		}
		RestoreIRQMask(savedMask);
		// The case that we do NOT return in the loop:
		// Indicate there is NO GPT handle!!!!!
		ASSERT(0);
		// return invalid handle
		return DCL_HANDLE_INVALID;
	}
   else if(DCL_GPT_BusyWait==eDev)
   {
		return DCL_GPT_BW_MAGIC_NUM |eDev;
   }
   else
   {
		//invaild GPT DCL_DEV type.
		ASSERT(0);
		return DCL_HANDLE_INVALID;
   }
}

/*-----------------------------------------------------------------------

* FUNCTION
*  DclSGPT_ReadData
*
* DESCRIPTION
*  This function is not supported for the SW GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*------------------------------------------------------------------------*/

DCL_STATUS DclSGPT_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

/*-----------------------------------------------------------------------

* FUNCTION
*  DclSGPT_WriteData
*
* DESCRIPTION
*  This function is not supported for the SW GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*------------------------------------------------------------------------*/

DCL_STATUS DclSGPT_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
   return STATUS_UNSUPPORTED;
}

/*-----------------------------------------------------------------------

* FUNCTION
*  DclSGPT_Configure
*
* DESCRIPTION
*  This function is not supported for the SW GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*------------------------------------------------------------------------*/

DCL_STATUS DclSGPT_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
   return STATUS_UNSUPPORTED;
}


/*-----------------------------------------------------------------------

* FUNCTION
*  DclSGPT_RegisterCallback
*
* DESCRIPTION
*  This function is not supported for the SW GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*------------------------------------------------------------------------*/

DCL_STATUS DclSGPT_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
   return STATUS_UNSUPPORTED;
}


/*-----------------------------------------------------------------------

* FUNCTION
*  DclSGPT_Control
*
* DESCRIPTION
*  This function is to send command to control the SW GPT module.
*
* PARAMETERS
*	handle - a valid handle return by DclSGPT_Open()
*  cmd   - a control command for GPT module
*          1. SGPT_CMD_START: to start a GPT timer
*          2. SGPT_CMD_STOP: to stop a GPT timer
*  data - for 1. SGPT_CMD_START: pointer to a SGPT_CTRL_START_T structure
*             2. SGPT_CMD_STOP: a NULL pointer
*
* RETURNS
*	STATUS_OK - command is executed successfully.
*	STATUS_FAIL - command is failed.
*  STATUS_INVALID_CMD - It's a invalid command.
*
*------------------------------------------------------------------------*/

DCL_STATUS DclSGPT_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	
	DCL_UINT8 gpt_handle=0;
	SGPT_CTRL_START_T  *prStart;
	#if defined(DRV_GPT_NEW_ARCHI)
	DCL_UINT32 timeout_tick;//16bit is not enough 
	#endif
	gpt_handle=DCL_GPT_CB_GET_DEV(handle) & 0xFF;
	
	if(DCL_GPT_CB_IS_HANDLE_MAGIC(handle))
	{
		#if defined(DRV_GPT_NEW_ARCHI)
		if(cmd == SGPT_CMD_START || cmd == SGPT_CMD_MINI_SECOND_START)
		{
				
						
			    prStart = &(data->rSGPTStart);
				timeout_tick = prStart->u2Tick;
				if(cmd == SGPT_CMD_START)
					{
						timeout_tick = timeout_tick * 10;//
					}
						//test if callback function is null.
				if(NULL==prStart->pfCallback)
							ASSERT(0);
			
		}
		#endif
		switch(cmd)
		{
			case SGPT_CMD_START:
			case SGPT_CMD_MINI_SECOND_START:
			{
				kal_bool ret_b;
				#if !defined(DRV_GPT_NEW_ARCHI)
	      	//SGPT_CTRL_START_T  *prStart;
	
	     		prStart = &(data->rSGPTStart);
				//test if callback function is null.
				if(NULL==prStart->pfCallback)
					ASSERT(0);
				#endif
	     		ret_b = GPTI_StartItem(gpt_handle, prStart->u2Tick, prStart->pfCallback, prStart->vPara);
	     		if(ret_b == KAL_TRUE)
	         	return STATUS_OK;
	      	else
	         	return STATUS_FAIL;
				}
				//break; we can return in any case.
			case SGPT_CMD_STOP:
	      	GPTI_StopItem(gpt_handle);
	      	return STATUS_OK;
			default:
				ASSERT(0);
      		return STATUS_INVALID_CMD;
	   }
	}
	else if(DCL_GPT_BW_IS_HANDLE_MAGIC(handle))
	{
		switch(cmd)
		{
			case SGPT_CMD_BUSYWAIT:
			{
				GPTI_BusyWait(data->uBusyWaitcount);
			}
			return STATUS_OK;
			default:
				ASSERT(0);
      		return STATUS_INVALID_CMD;			
		}
		//return STATUS_OK;
	}
	else
	{
		//if assert happen here, that means DCL_HANDLE pass in is wrong!
		ASSERT(0);
		return DCL_HANDLE_INVALID;
	}
}

/*-----------------------------------------------------------------------

* FUNCTION
*  DclSGPT_Close
*
* DESCRIPTION
*  This function is to close the SW GPT module.
*
* PARAMETERS
*	handle  - hanlde previous got from DclSGPT_Open()
*
* RETURNS
*	DCL_STATUS_OK - successfully close the SW GPT module.
*	DCL_STATUS_fail - fails to close the SW GPT module.
*
*------------------------------------------------------------------------*/

DCL_STATUS DclSGPT_Close(DCL_HANDLE *handle)
{
	DCL_UINT8 gpt_handle;
	kal_uint32 savedMask;
	gpt_handle=DCL_GPT_CB_GET_DEV(*handle) & 0xFF;	
	
	if(DCL_GPT_CB_IS_HANDLE_MAGIC(*handle))
	{

		if(GPTTimer.GPTSTOP!=KAL_TRUE)
			GPTI_StopItem(gpt_handle);
		// Make sure the GPT handle is activated
		ASSERT(GPTTimer.GPTUsed[gpt_handle]);		
		savedMask = SaveAndSetIRQMask();
		GPTTimer.GPTUsed[gpt_handle] = 0;
		GPTTimer.MAX_GPTIMER_ITEMS --;	
		RestoreIRQMask(savedMask);
		*handle=0x7F;
		return STATUS_OK;
	}
	else if(DCL_GPT_BW_IS_HANDLE_MAGIC(*handle))
	{
		return STATUS_OK;
	}
	else
	{
		ASSERT(0);
		return STATUS_INVALID_DCL_HANDLE;
	}
}

/*-----------------------------------------------------------------------

* FUNCTION
*  DclFGPT_Initialize
*
* DESCRIPTION
*  This function is to initialize the free run GPT module.
*
* PARAMETERS
*	None
*
* RETURNS
*	DCL_STATUS_OK
*
*------------------------------------------------------------------------*/

DCL_STATUS DclFGPT_Initialize(void)
{
	DclFHGPT_Initialize();
	return STATUS_OK;
}

/*-----------------------------------------------------------------------

* FUNCTION
*  DclFGPT_Open
*
* DESCRIPTION
*  This function is to open a free run GPT module if it exists. Note 
* that it supports multiple opens and no need to close it.
*
* PARAMETERS
*	eDev - only valid for DCL_GPT3
*	flags - no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*	DCL_HANDLE_INVALID - Open failed. It means no free run GPT exists or 
*                       open a wrong device.
*  other value - a valid handle
*
*------------------------------------------------------------------------*/

DCL_HANDLE DclFGPT_Open(DCL_DEV eDev, DCL_FLAGS flags)
{
	#if defined(DRV_GPT_GPT3)
	if(DCL_GPT_FreeRUN3==eDev)
		return DCL_FGPT_MAGIC_NUM|eDev;
	#endif
	#if defined(DRV_GPT_GPT4)
	if(DCL_GPT_FreeRUN4==eDev)
		return DCL_FGPT_MAGIC_NUM|eDev;
   #endif
	{
		ASSERT(0);
   	return DCL_HANDLE_INVALID;
	}
}

/*-----------------------------------------------------------------------

* FUNCTION
*  DclFGPT_ReadData
*
* DESCRIPTION
*  This function is not supported for the free run GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*------------------------------------------------------------------------*/

DCL_STATUS DclFGPT_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
   return STATUS_UNSUPPORTED;
}

/*-----------------------------------------------------------------------

* FUNCTION
*  DclFGPT_WriteData
*
* DESCRIPTION
*  This function is not supported for the free run GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*------------------------------------------------------------------------*/

DCL_STATUS DclFGPT_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
   return STATUS_UNSUPPORTED;
}

/*-----------------------------------------------------------------------

* FUNCTION
*  DclFGPT_Configure
*
* DESCRIPTION
*  This function is not supported for the free run GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*------------------------------------------------------------------------*/

DCL_STATUS DclFGPT_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
   return STATUS_UNSUPPORTED;
}

/*-----------------------------------------------------------------------

* FUNCTION
*  DclFGPT_RegisterCallback
*
* DESCRIPTION
*  This function is not supported for the free run GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*------------------------------------------------------------------------*/

DCL_STATUS DclFGPT_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
   return STATUS_UNSUPPORTED;
}

/*-----------------------------------------------------------------------

* FUNCTION
*  DclFGPT_Control
*
* DESCRIPTION
*  This function is to send command to control the free run GPT module.
*
* PARAMETERS
*	handle - a valid handle return by DclFGPT_Open()
*  cmd   - a control command for free ryb GPT module
*          FGPT_CMD_RETURN_COUNT: to get the timer count
*  data - for FGPT_CMD_RETURN_COUNT: pointer to a FGPT_CTRL_RETURN_COUNT_T type
*
* RETURNS
*	STATUS_OK - command is executed successfully.
*	STATUS_FAIL - command is failed. No free run GPT is supported.
*  STATUS_INVALID_CMD - The command is invalid.
*  STATUS_INVALID_HANDLE - The handle is invalid.
*
*------------------------------------------------------------------------*/

DCL_STATUS DclFGPT_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
   DCL_DEV  eDev;
   DCL_HANDLE gpt_handle;

   if (!DCL_FGPT_IS_HANDLE_MAGIC(handle))
   {
      ASSERT(0);
      return STATUS_INVALID_DCL_HANDLE;
   }
   eDev = DCL_FGPT_GET_DEV(handle);
   #if defined(DRV_GPT_GPT3)
   if(DCL_GPT_FreeRUN3==eDev)
   	{
   		switch(cmd)
   		{
   			case FGPT_CMD_START:
				{
					gpt_handle=DclFHGPT_Open(GPT3,0);
					DclFHGPT_Control(gpt_handle,FHGPT_CMD_START,0);
					DclFHGPT_Close(gpt_handle);
				}
				break;
   			case FGPT_CMD_STOP:
				{
					gpt_handle=DclFHGPT_Open(GPT3,0);
					DclFHGPT_Control(gpt_handle,FHGPT_CMD_STOP,0);
					DclFHGPT_Close(gpt_handle);
				}
				break;
				case FGPT_CMD_RETURN_COUNT:
				{
					HGPT_CTRL value;
					gpt_handle=DclFHGPT_Open(GPT3,0);
					DclFHGPT_Control(gpt_handle,FHGPT_CMD_RETURN_COUNT,&value);
					data->u2RetCount=value.u2RetCount;
					DclFHGPT_Close(gpt_handle);					
				}
				break;
			  default:
	      	  ASSERT(0);
	      	  return STATUS_INVALID_CMD;
			} 
			return STATUS_OK;
	  }
	#endif
	#if defined(DRV_GPT_GPT4)
  	if(DCL_GPT_FreeRUN4==eDev)
  	{
   		switch(cmd)
   		{
   			case FGPT_CMD_START:
				{
					gpt_handle=DclFHGPT_Open(GPT4,0);
					DclFHGPT_Control(gpt_handle,FHGPT_CMD_START,0);
					DclFHGPT_Close(gpt_handle);
				}
				break;
   			case FGPT_CMD_STOP:
				{
					gpt_handle=DclFHGPT_Open(GPT4,0);
					DclFHGPT_Control(gpt_handle,FHGPT_CMD_STOP,0);
					DclFHGPT_Close(gpt_handle);
				}
				break;
   			case FGPT_CMD_RETURN_COUNT:
				{
					HGPT_CTRL value;
					gpt_handle=DclFHGPT_Open(GPT4,0);
					DclFHGPT_Control(gpt_handle,FHGPT_CMD_RETURN_COUNT,&value);
					data->u2RetCount=value.u2RetCount;
					DclFHGPT_Close(gpt_handle);					
				}
				break;
				default:
      			ASSERT(0);
					return STATUS_INVALID_CMD;  		
  	  }
  	  return STATUS_OK;
    }
	#endif
	ASSERT(0);
	return DCL_HANDLE_INVALID;
}

/*-----------------------------------------------------------------------

* FUNCTION
*  DclFGPT_Close
*
* DESCRIPTION
*  This function is not supported for the free run GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*------------------------------------------------------------------------*/

DCL_STATUS DclFGPT_Close(DCL_HANDLE handle)
{
   return STATUS_UNSUPPORTED;
}

#if defined(DRV_MISC_CACHE_REGION_SUPPORT)
  // If cache is supported the code is put into cached region
#else // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)
  // Put the code into internal SRAM
#ifdef GPT_INTERNAL_SRAM
#pragma arm section code = "INTERNCODE"
#endif
#endif // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)

static void gpt_sw_delay(void)
{
	ust_busy_wait(95);//delay three 32K ticks for HW limitation. we should avoid two case: 1, start after start. 2,start after stop.
}

/*-----------------------------------------------------------------------

* FUNCTION                                                            
*	GPTI_StartItem
*
* DESCRIPTION                                                           
*   	GPT start a item.
*
* CALLS  
*
* PARAMETERS
*	moudle = UART_Module, SIM_Module, GPT_Module
*	tick = the delay(the unit is 10ms)
*  gptimer_func = the callback function when the tick is reached.
*  parameter = the parameter inputed into gptimer_func
*
* RETURNS
*	KAL_TRUE, start item successfully
*  KAL_FALSE, start item fail
*
* GLOBALS AFFECTED
*   external_global
*------------------------------------------------------------------------*/
#if defined(__ENABLE_GPT_PROTECTION__)

//  Race condition check
#define PROTECTION_RACE_CONDITION_CHECK
static kal_bool PRaceCheckFlag = KAL_FALSE;
// 


static kal_bool GPTI_StartItem(kal_uint8 module,kal_uint16 tick,void (*gptimer_func)(void *),void *parameter)
{
   kal_uint32 savedMask;  

   if (GPTTimer.status & (1<<module))
   {
      return KAL_FALSE;
   }
   
   GPTTimer.GPTItems[module].tick = GPTTimer.GPT_TICK+tick;
   GPTTimer.GPTItems[module].gptimer_func = gptimer_func;
   GPTTimer.GPTItems[module].parameter = parameter;
  // savedMask = SaveAndSetIRQMask();
   savedMask = kal_take_thread_protect();

  	#if defined (PROTECTION_RACE_CONDITION_CHECK)
	{
		kal_uint32 savedMask2;
		savedMask2 = SaveAndSetIRQMask();
		ASSERT(!PRaceCheckFlag);
		PRaceCheckFlag = KAL_TRUE;
		RestoreIRQMask(savedMask2);
	}
	#endif // #if defined (PROTECTION_RACE_CONDITION_CHECK)
	
  
   GPTTimer.status |= (1<<module);
   
   if(KAL_TRUE==GPTTimer.GPTSTOP)
   {
   	GPTTimer.GPTSTOP=KAL_FALSE;
   	//Is there any race condition.....
 //  	if ((GPTTimer.GPTSTOP) == KAL_FALSE)
 //  	{
  // 		RestoreIRQMask(savedMask);
  // 		savedMask = SaveAndSetIRQMask();
	   	GPTTimer.Hgpt_handle=DclHGPT_Open(GPT1,0);
		DclHGPT_Control(GPTTimer.Hgpt_handle,HGPT_CMD_START,0);
	//}
   }
 //  RestoreIRQMask(savedMask);
// kal_give_thread_protect(savedMask);
 
//toy separate GPT and L1SM function 
#if defined(DRV_GPT_DIRECT_SLEEP_MODE_HANDLE)
#if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
  // savedMask = SaveAndSetIRQMask();
   if (KAL_FALSE== (GPTTimer.GPTSTOP))
      L1SM_UnIRQSleepDisable(gpt_sm_handle);
  // RestoreIRQMask(savedMask);
#endif
#endif


#if defined (PROTECTION_RACE_CONDITION_CHECK)
   {
	   kal_uint32 savedMask2;
	   savedMask2 = SaveAndSetIRQMask();
	   ASSERT(PRaceCheckFlag);
	   PRaceCheckFlag = KAL_FALSE;
	   RestoreIRQMask(savedMask2);
   }
#endif // #if defined (PROTECTION_RACE_CONDITION_CHECK)


   kal_give_thread_protect(savedMask);


   return KAL_TRUE;
}

static void GPTI_StopItem(kal_uint8 module)
{
   register kal_uint32 savedMask;

 //  savedMask = SaveAndSetIRQMask();
   savedMask = kal_take_thread_protect();

 	#if defined (PROTECTION_RACE_CONDITION_CHECK)
	{
		kal_uint32 savedMask2;
		savedMask2 = SaveAndSetIRQMask();
		ASSERT(!PRaceCheckFlag);
		PRaceCheckFlag = KAL_TRUE;
		RestoreIRQMask(savedMask2);
	}
	#endif // #if defined (PROTECTION_RACE_CONDITION_CHECK)
	
 
   GPTTimer.status &= ~(1<<module);
   if(0==GPTTimer.status)
   {
	GPTTimer.GPTSTOP=KAL_TRUE;
    	GPTTimer.GPT_TICK=0;
	//GPTTimer.Hgpt_handle=0;
	//RestoreIRQMask(savedMask);
	//savedMask = SaveAndSetIRQMask();
	//as open is there any race condition.
	//if ((GPTTimer.GPTSTOP) == KAL_TRUE)
	//{
		//RestoreIRQMask(savedMask);
		DclHGPT_Control(GPTTimer.Hgpt_handle,HGPT_CMD_STOP,0);
		//savedMask = SaveAndSetIRQMask();
   		DclHGPT_Close(GPTTimer.Hgpt_handle);
   		//GPTTimer.Hgpt_handle=0;
  	//}
   	}
   //	RestoreIRQMask(savedMask);
	 //toy separate GPT and L1SM function 
	 #if defined(DRV_GPT_DIRECT_SLEEP_MODE_HANDLE)
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
  // savedMask = SaveAndSetIRQMask();
   if (KAL_TRUE == GPTTimer.GPTSTOP)
   {
	   if(KAL_TRUE==GPT_IsStop())
	   		L1SM_UnIRQSleepEnable(gpt_sm_handle);
   }
 //  RestoreIRQMask(savedMask);
	#endif
	#endif

#if defined (PROTECTION_RACE_CONDITION_CHECK)
	{
		kal_uint32 savedMask2;
		savedMask2 = SaveAndSetIRQMask();
		ASSERT(PRaceCheckFlag);
		PRaceCheckFlag = KAL_FALSE;
		RestoreIRQMask(savedMask2);
	}
#endif // #if defined (PROTECTION_RACE_CONDITION_CHECK)


	 kal_give_thread_protect(savedMask);
	
}

/*-----------------------------------------------------------------------

* FUNCTION                                                            
*	GPTI_HISR
*
* DESCRIPTION                                                           
*   	GPTI HISR
*
* CALLS
*
* PARAMETERS
*	void
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*------------------------------------------------------------------------*/

void GPTI_HISR(void)
{
   kal_uint8 index;
   kal_uint32 time1, time2;
   kal_uint32 savedMask;
   //this can be delete ?!!@
   #if !defined(DRV_MISC_TDMA_NO_TIME)
   kal_uint32 process_tick = 0;
   kal_uint32 u4DurationMS = 0;
   #endif
   
   // Bit matched method to check if a GPT items is activated
   // Search whole GPT items
   for (index = 0;index < MAX_GPT_ITEMS;index++)
   {
      #if defined(DRV_MISC_TDMA_NO_TIME)
      GPTProcess(index);//extract macro for assert process which occupy too long.
      #else
      savedMask = SaveAndSetIRQMask();
       //savedMask = kal_take_thread_protect();
      if((GPTTimer.status & (1<<index))&&(GPTTimer.GPT_TICK == GPTTimer.GPTItems[index].tick))
      {
         //process_tick = drv_get_current_time();
		 		 time1=drv_get_current_time();
		 		 GPTTimer.status &= ~(1<<index);
		 		 RestoreIRQMask(savedMask);
         GPTTimer.GPTItems[index].gptimer_func(GPTTimer.GPTItems[index].parameter);
		 		 time2=drv_get_current_time();
		 		 GPT_DBG(index,time2-time1);
		 		 //u4DurationMS = drv_get_duration_ms(process_tick);
         //ASSERT(u4DurationMS < 30); // 30 ms //user may break trace32, this assert need to cover by l1_assert_bypass
      }
      else
      {
      	RestoreIRQMask(savedMask);
      }
     // kal_give_thread_protect(savedMask);
	 
      #endif
   }
   
   GPTTimer.GPT_TICK++;

   if (GPTTimer.status == 0)
   {
   	  // UT Test road test.
      //	module_test_print(" HISR: GPTTimer.Hgpt_handle status is : %x \r\n",GPTTimer.Hgpt_handle);
      GPTTimer.GPT_TICK=0;
			GPTTimer.GPTSTOP=KAL_TRUE;
      
   		DclHGPT_Control(GPTTimer.Hgpt_handle,HGPT_CMD_STOP,0);
   		DclHGPT_Close(GPTTimer.Hgpt_handle);
			//DclHGPT_Close(GPTTimer.Hgpt_handle);

			//GPTTimer.Hgpt_handle=0;
			#if defined(DRV_GPT_DIRECT_SLEEP_MODE_HANDLE)
			#if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
	   	if(KAL_TRUE==GPT_IsStop())
	   		L1SM_UnIRQSleepEnable(gpt_sm_handle);
			#endif
			#endif
   }
}

#elif defined(DRV_GPT_NEW_ARCHI)

static void gpt1_start_gpt(kal_uint8 module)
{
	kal_uint32 savedMask;  
	HGPT_CTRL_RESET_T reLoadData;
	static kal_uint32 roll_count = 0;//just for test
	kal_uint32 tick_now,tick_left;
	kal_uint32 tick_over;//added for test
	kal_uint32 tick1,tick2,tick3,tick4;
	kal_uint32 i;
	savedMask = SaveAndSetIRQMask();
	if(Is_Running == KAL_FALSE && Is_HISR_Running == KAL_FALSE)
	{
		Is_Running = KAL_TRUE;
		do
		{
			
			DclHGPT_Control(hGPTHadle,HGPT_CMD_STOP,0);
			RestoreIRQMask(savedMask);
			gpt_sw_delay();// we must delay 4 32K tick before write hw register.
			savedMask = SaveAndSetIRQMask();
		}while((DRV_GPT_Reg(GPT1_CTRL)&GPT_CTRL_Enable) !=0);//wait until make sure the gpt is stopped
		
		tick_now = drv_get_current_time() & SW_GPT_MAGIC_NUM;//get current time
		if(tick_now < GPTNodeBuffer[smallest_index_num].gpt_start_tick)
		{
			GPTNodeBuffer[smallest_index_num].gpt_arrive_tick &= SW_GPT_MAGIC_NUM;//to update the user who roll back
		}
		if((GPTNodeBuffer[smallest_index_num].gpt_arrive_tick <= tick_now) || ((GPTNodeBuffer[smallest_index_num].gpt_arrive_tick >= GPTNodeBuffer[smallest_index_num].gpt_start_tick) && (tick_now < GPTNodeBuffer[smallest_index_num].gpt_start_tick)))
		{
			tick_left = 0;
		}
		else
		{
			tick_left = ((GPTNodeBuffer[smallest_index_num].gpt_arrive_tick - tick_now))>>1;//to calculate the left tick
			if(tick_left >= MAX_GPT_REG_COUNT)//user who register a timer larger than 65535 ticks
			{
				tick_left = MAX_GPT_REG_COUNT;
			}
		}
		reLoadData.fgAutoReload = DCL_FALSE;
		reLoadData.u2CountValue = (DCL_UINT16)(tick_left);

		
		DclHGPT_Control(hGPTHadle,HGPT_CMD_RESET,(HGPT_CTRL *)&reLoadData);//reload data to start gpt
		DclHGPT_Control(hGPTHadle,HGPT_CMD_START,0);
		if(module != 0xFF)
		{
			GPTNodeBuffer[module].Is_Iddle= KAL_FALSE;  //finally, set this value, to avoid race condition 
		}
		Is_Running = KAL_FALSE;
		RestoreIRQMask(savedMask);
		
#if defined(DRV_GPT_DIRECT_SLEEP_MODE_HANDLE)
#if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
		   savedMask = SaveAndSetIRQMask();
			if(tick_left <= 163)//less than 10ms ,we should lock sleept mode
			{
		   		if ((DRV_GPT_Reg(GPT1_CTRL)&GPT_CTRL_Enable) !=0)
					L1SM_UnIRQSleepDisable(gpt_sm_handle);
			}
			else
			{
				L1SM_UnIRQSleepEnable(gpt_sm_handle);
			}
		   RestoreIRQMask(savedMask);
#endif
#endif	
	}
	else
	{
		if(module != 0xFF)
		{
			GPTNodeBuffer[module].Is_Iddle= KAL_FALSE;  //finally, set this value, to avoid race condition 
		}
		RestoreIRQMask(savedMask);
	}

}

static kal_bool GPTI_StartItem(kal_uint8 module,kal_uint32 tick,void (*gptimer_func)(void *),void *parameter)
{
   kal_uint32 savedMask;  
   kal_uint32 tick_now,temp_arrive_tick;
   kal_uint32 temp_tick;
	if(GPTNodeBuffer[module].Is_Iddle == KAL_FALSE)//already running, then, return
	{
		return KAL_FALSE;
	}
	temp_tick =((kal_uint32)tick) * 32;// calculate the time out tick of 32k count
	
	if(temp_tick > MAX_LIMIT_TIME) //time should not larger than 0x00FFFFFF
	{
		ASSERT(0);
	} 
	tick_now = drv_get_current_time() & SW_GPT_MAGIC_NUM;//get current time to calculate the parameters
	if(temp_tick > (MAX_32K_COUNT - tick_now)) //calculate the arrive count
	{
		temp_arrive_tick = temp_tick - (MAX_32K_COUNT + 1 - tick_now);//the next value of 0xFFFFFF is 0x000000 not 0x000001
		temp_arrive_tick &= SW_GPT_MAGIC_NUM;//the 25th bit is meaning whether roll back or not
		temp_arrive_tick |= 1 << GPT_VALID_BIT;
	}
	else
	{
		temp_arrive_tick = temp_tick + tick_now;
	}
	
//we don't need to protect here
	GPTNodeBuffer[module].gpt_arrive_tick= temp_arrive_tick;
	GPTNodeBuffer[module].gpt_start_tick = tick_now;
	GPTNodeBuffer[module].gptimer_func = gptimer_func;
	GPTNodeBuffer[module].parameter = parameter;

	savedMask = SaveAndSetIRQMask();//to find the smallest user, we shoud protect it . if not, the smallest user may not right.
	if(GPTNodeBuffer[smallest_index_num].Is_Iddle != KAL_TRUE)
	{
		if(tick_now < GPTNodeBuffer[smallest_index_num].gpt_start_tick) 
		{
			GPTNodeBuffer[smallest_index_num].gpt_arrive_tick &= SW_GPT_MAGIC_NUM;
		}

		if(temp_arrive_tick < GPTNodeBuffer[smallest_index_num].gpt_arrive_tick)
		{
			smallest_index_num = module;		 
		}
		else //if this is not the smallest one, return directly.
		{
		
			GPTNodeBuffer[module].Is_Iddle= KAL_FALSE;	//finally, set this value, to avoid race condition 
			RestoreIRQMask(savedMask);
			return KAL_TRUE;
		}
		
	}
	else
	{
		smallest_index_num = module;
	}	
	RestoreIRQMask(savedMask);
	gpt1_start_gpt(module);
    return KAL_TRUE;
}

/*-----------------------------------------------------------------------

* FUNCTION                                                            
*	GPTI_StopItem
*
* DESCRIPTION                                                           
*   	GPT stop a item.
*
* CALLS  
*
* PARAMETERS
*	moudle = UART_Module, SIM_Module, GPT_Module
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*------------------------------------------------------------------------*/


static void GPTI_StopItem(kal_uint8 module)
{
   register kal_uint32 savedMask;
   kal_uint32 tick_now=0;
   kal_uint8 i=0;
   kal_bool Is_first_time = KAL_TRUE;

 	if(GPTNodeBuffer[module].Is_Iddle == KAL_TRUE)// if already stopped, return
 	{
		return;
 	}
	
   savedMask = SaveAndSetIRQMask();//保护if(module == smallest_index_num ) and for loop below
	GPTNodeBuffer[module].Is_Iddle = KAL_TRUE;//first ,we update this value
	if(module != smallest_index_num )
	{
		
	   	RestoreIRQMask(savedMask);
	    return;
	}
	   	
	tick_now = drv_get_current_time() & SW_GPT_MAGIC_NUM;
	for(i = 0; i < MAX_USER_NUMBER; i++)//for loop to find the new smallest user,this operation should be protected
	{
			  if(GPTNodeBuffer[i].Is_Iddle == KAL_FALSE)
			  {
				  if(tick_now < GPTNodeBuffer[i].gpt_start_tick)
				  {
					  GPTNodeBuffer[i].gpt_arrive_tick &= SW_GPT_MAGIC_NUM;
				  }
				  if(Is_first_time == KAL_TRUE)
				  {
					  smallest_index_num = i;
					  Is_first_time = KAL_FALSE;
				  }
				  if(GPTNodeBuffer[i].gpt_arrive_tick < GPTNodeBuffer[smallest_index_num].gpt_arrive_tick)
				  {
					  smallest_index_num = i;
				  }
			  }
			
	}
	RestoreIRQMask(savedMask);
	
  
/*******************************************************/

		if(GPTNodeBuffer[smallest_index_num].Is_Iddle == KAL_FALSE)//to make sure the smallest user is busy.
		{
			gpt1_start_gpt(0xFF);//不传module进去的原因是假如进这个function后，高优先级的人来stop这个人，那么，一定要保证他stop 掉。
		}
		else// wen there is no body , we should stop the hw gpt
		{
			savedMask = SaveAndSetIRQMask();
			if(GPTNodeBuffer[smallest_index_num].Is_Iddle == KAL_TRUE)
			{
				DclHGPT_Control(hGPTHadle,HGPT_CMD_STOP,0);
			}
			RestoreIRQMask(savedMask);
#if defined(DRV_GPT_DIRECT_SLEEP_MODE_HANDLE)
#if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
		   savedMask = SaveAndSetIRQMask();
			L1SM_UnIRQSleepEnable(gpt_sm_handle);
		   RestoreIRQMask(savedMask);
#endif
#endif	
			gpt_sw_delay();// we must delay 4 32K tick before write hw register.
		}

}









#if defined(DRV_MISC_CACHE_REGION_SUPPORT)
// If cache is supported the code is put into cached region
#else // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)
// Put the code into internal SRAM
#ifdef GPT_INTERNAL_SRAM
#pragma arm section code
#endif
#endif // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)

/*-----------------------------------------------------------------------

* FUNCTION                                                            
*	GPTI_HISR
*
* DESCRIPTION                                                           
*   	GPTI HISR
*
* CALLS
*
* PARAMETERS
*	void
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*------------------------------------------------------------------------*/
	//kal_uint32 GPT_temp_l1_stamp_old = 0,temp_l1_stamp = 0;
//extern kal_uint8 timeout_UserCount = 0;
//extern kal_uint8 Timeout_Array[MAX_USER_NUMBER] = {0};
//extern kal_uint8 Timeout_Array_before[MAX_USER_NUMBER] = {0};
void GPTI_HISR(void)
{
   kal_uint32 savedMask;
   kal_uint32 tick_now=0;
   kal_uint8 timeout_UserCount = 0;
   kal_uint8 i=0;
   kal_bool Is_first_time = KAL_TRUE;
   kal_uint8 Timeout_Array[MAX_USER_NUMBER];

    Is_HISR_Running = KAL_TRUE; //sw flag

	do{
		timeout_UserCount = 0;
		tick_now = drv_get_current_time() & SW_GPT_MAGIC_NUM;
		savedMask = SaveAndSetIRQMask();//protect the for loop to find the user who timeout and the new samallest user
		for(i = 0; i < MAX_USER_NUMBER; i++)// for loop to find timeout user and new smallest user
		{
			if(GPTNodeBuffer[i].Is_Iddle == KAL_FALSE)
			{
				if(tick_now < GPTNodeBuffer[i].gpt_start_tick)
				{
					GPTNodeBuffer[i].gpt_arrive_tick &= SW_GPT_MAGIC_NUM;
				}
				if((GPTNodeBuffer[i].gpt_arrive_tick <= tick_now) || ((GPTNodeBuffer[i].gpt_arrive_tick >= GPTNodeBuffer[i].gpt_start_tick) && (tick_now < GPTNodeBuffer[i].gpt_start_tick)))
				{
					GPTNodeBuffer[i].Is_Iddle = KAL_TRUE;
					Timeout_Array[timeout_UserCount++] = i;//record the user index who timeout
				}
				else//the reason to find the smalles user first is to make sure GPTNodeBuffer[smallest].Is_Iddle == KAL_FALSE,if GPTNodeBuffer[smallest].Is_Iddle == KAL_TRUE,this means there is no user any more.
				{
					
					if(GPTNodeBuffer[i].Is_Iddle == KAL_FALSE)
					{
						if(Is_first_time == KAL_TRUE)
						{
							smallest_index_num = i;
							Is_first_time = KAL_FALSE;
						}
						if(GPTNodeBuffer[i].gpt_arrive_tick < GPTNodeBuffer[smallest_index_num].gpt_arrive_tick)
						{
							smallest_index_num = i;
						}
					}
				}
			}
			
		}
		RestoreIRQMask(savedMask);
		Is_first_time = KAL_TRUE;
		for(i = 0; i < timeout_UserCount; i++)
		{
			
			GPTNodeBuffer[Timeout_Array[i]].gptimer_func(GPTNodeBuffer[Timeout_Array[i]].parameter);//call the call back function of users who timeout
		}
		
		
	}
	while(timeout_UserCount != 0);//if no body timeout, jump out the loop.

	Is_HISR_Running = KAL_FALSE;

	if((DRV_GPT_Reg(GPT1_CTRL)&GPT_CTRL_Enable) == 0 && GPTNodeBuffer[smallest_index_num].Is_Iddle == KAL_FALSE)//这里不用加保护的原因是: 即使此时被打断，造成的后果最多是空起来一次。
	{
		gpt1_start_gpt(0xFF);
	}
	else
	{
#if defined(DRV_GPT_DIRECT_SLEEP_MODE_HANDLE)
#if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
		   savedMask = SaveAndSetIRQMask();
			if(GPTNodeBuffer[smallest_index_num].Is_Iddle == KAL_TRUE)
{
				L1SM_UnIRQSleepEnable(gpt_sm_handle);
			}
		   RestoreIRQMask(savedMask);
#endif
#endif	
	}

}



#else


static kal_bool GPTI_StartItem(kal_uint8 module,kal_uint16 tick,void (*gptimer_func)(void *),void *parameter)
{
   kal_uint32 savedMask;  
   // Clear magic number
   //module &= ~(GPT_HANDLE_MAGIC_NUM);
   if (GPTTimer.status & (1<<module))
   {
      return KAL_FALSE;
   }
   
   GPTTimer.GPTItems[module].tick = GPTTimer.GPT_TICK+tick;
   GPTTimer.GPTItems[module].gptimer_func = gptimer_func;
   GPTTimer.GPTItems[module].parameter = parameter;
   //this may lead to tst call stack corrupted when use usb logging
   //kal_prompt_trace(MOD_DRVKBD, "--GPT start Item-- module:%d,tick:%d,callback:%x", module, tick,gptimer_func);
   savedMask = SaveAndSetIRQMask();
   GPTTimer.status |= (1<<module);
   
   //module_test_print("GPTI_StartItem module %x,%x\r\n",module, GPTTimer.GPTItems[module].tick);
   if(KAL_TRUE==GPTTimer.GPTSTOP)
   	{
   		GPTTimer.GPTSTOP=KAL_FALSE;
   		//Is there any race condition.....
   		if ((GPTTimer.GPTSTOP) == KAL_FALSE)
			{
   			RestoreIRQMask(savedMask);
			gpt_sw_delay();//delay 3 32K ticks for hw limitation
   				savedMask = SaveAndSetIRQMask();
	   	  	        GPTTimer.Hgpt_handle=DclHGPT_Open(GPT1,0);
				DclHGPT_Control(GPTTimer.Hgpt_handle,HGPT_CMD_START,0);
			}
   	}
    RestoreIRQMask(savedMask);
 
//toy separate GPT and L1SM function 
	#if defined(DRV_GPT_DIRECT_SLEEP_MODE_HANDLE)
	#if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
	   savedMask = SaveAndSetIRQMask();
	   if (KAL_FALSE== (GPTTimer.GPTSTOP))
			L1SM_UnIRQSleepDisable(gpt_sm_handle);
	   RestoreIRQMask(savedMask);
	#endif
	#endif	
   return KAL_TRUE;
}

/*-----------------------------------------------------------------------

* FUNCTION                                                            
*	GPTI_StopItem
*
* DESCRIPTION                                                           
*   	GPT stop a item.
*
* CALLS  
*
* PARAMETERS
*	moudle = UART_Module, SIM_Module, GPT_Module
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*------------------------------------------------------------------------*/


static void GPTI_StopItem(kal_uint8 module)
{
   register kal_uint32 savedMask;
   // Clear magic number
   //module &= ~(GPT_HANDLE_MAGIC_NUM);
   savedMask = SaveAndSetIRQMask();
   gpt_stop_array[module] = L1I_GetTimeStamp();
   GPTTimer.status &= ~(1<<module);
   if(0==GPTTimer.status)
   {
	GPTTimer.GPTSTOP=KAL_TRUE;
    	GPTTimer.GPT_TICK=0;
	//GPTTimer.Hgpt_handle=0;
	RestoreIRQMask(savedMask);
	savedMask = SaveAndSetIRQMask();
	//as open is there any race condition.
	if((GPTTimer.GPTSTOP) == KAL_TRUE)
	{
		RestoreIRQMask(savedMask);
		DclHGPT_Control(GPTTimer.Hgpt_handle,HGPT_CMD_STOP,0);
		gpt_sw_delay();//delay 3 32K ticks for hw limitation
		savedMask = SaveAndSetIRQMask();
		DclHGPT_Close(GPTTimer.Hgpt_handle);
		//GPTTimer.Hgpt_handle=0;
  	}
   }
   RestoreIRQMask(savedMask);
	//toy separate GPT and L1SM function 
	#if defined(DRV_GPT_DIRECT_SLEEP_MODE_HANDLE)
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
   savedMask = SaveAndSetIRQMask();
   if (KAL_TRUE == GPTTimer.GPTSTOP)
   {
		if(KAL_TRUE==GPT_IsStop())
			L1SM_UnIRQSleepEnable(gpt_sm_handle);
   }
   RestoreIRQMask(savedMask);
	#endif
	#endif
}

#if defined(DRV_MISC_CACHE_REGION_SUPPORT)
// If cache is supported the code is put into cached region
#else // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)
// Put the code into internal SRAM
#ifdef GPT_INTERNAL_SRAM
#pragma arm section code
#endif
#endif // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)

/*-----------------------------------------------------------------------

* FUNCTION                                                            
*	GPTI_HISR
*
* DESCRIPTION                                                           
*   	GPTI HISR
*
* CALLS
*
* PARAMETERS
*	void
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*------------------------------------------------------------------------*/

void GPTI_HISR(void)
{
   kal_uint8 index;
   volatile kal_uint32 time1, time2;
   kal_uint32 savedMask;
   //this can be delete ?!!@
   //#if !defined(DRV_MISC_TDMA_NO_TIME)
   //kal_uint32 process_tick = 0;
   //kal_uint32 u4DurationMS = 0;
   //#endif
   
   // Bit matched method to check if a GPT items is activated
   // Search whole GPT items
   for (index = 0;index < MAX_GPT_ITEMS;index++)
   {
	   if(GPTTimer.status & (1 << index))
	   {
		   kal_brief_trace(TRACE_GROUP_10,GPT_LOG_TEST,index,(kal_uint32)GPTTimer.GPTItems[index].gptimer_func);
	   }
   
      #if defined(DRV_MISC_TDMA_NO_TIME)
      GPTProcess(index);//extract macro for assert process which occupy too long.
      #else
      savedMask = SaveAndSetIRQMask();
      if((GPTTimer.status & (1<<index))&&(GPTTimer.GPT_TICK == GPTTimer.GPTItems[index].tick))
      {
         //process_tick = drv_get_current_time();
			time1=drv_get_current_time();
			GPTTimer.status &= ~(1<<index);
			RestoreIRQMask(savedMask);
         GPTTimer.GPTItems[index].gptimer_func(GPTTimer.GPTItems[index].parameter);
			time2=drv_get_current_time();
			GPT_DBG(index,time2-time1);
			//u4DurationMS = drv_get_duration_ms(process_tick);
			//ASSERT(u4DurationMS < 30); // 30 ms //user may break trace32, this assert need to cover by l1_assert_bypass
      }
      else
      {
			RestoreIRQMask(savedMask);
      }
		#endif
   }
   
	GPTTimer.GPT_TICK++;
   
   if(GPTTimer.status == 0)
   {
		// UT Test road test.
		//	module_test_print(" HISR: GPTTimer.Hgpt_handle status is : %x \r\n",GPTTimer.Hgpt_handle);
                GPTTimer.GPT_TICK=0;
		GPTTimer.GPTSTOP=KAL_TRUE;
      
		DclHGPT_Control(GPTTimer.Hgpt_handle,HGPT_CMD_STOP,0);
		DclHGPT_Close(GPTTimer.Hgpt_handle);
		gpt_sw_delay();//delay 3 32K ticks for hw limitation
		//DclHGPT_Close(GPTTimer.Hgpt_handle);

		//GPTTimer.Hgpt_handle=0;
		#if defined(DRV_GPT_DIRECT_SLEEP_MODE_HANDLE)
		#if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
		if(KAL_TRUE==GPT_IsStop())
			L1SM_UnIRQSleepEnable(gpt_sm_handle);
		#endif
		#endif
   }
}


#endif

static void GPTI_BusyWait(kal_uint16 len)
{
	
	DCL_HANDLE gpt_handle;
	HGPT_CTRL set_gpt;
  
	static kal_uint8 userCount = 0; // avoid multi user use this function in the same time, it will cause race condition
	BusyWaitFlag=KAL_FALSE; 
	userCount++;   // every user increase 1 count
	if(userCount>1)// check if there exist multi user
		ASSERT(0);
	
	set_gpt.rHGPTReset.u2CountValue=len-1;
	set_gpt.rHGPTReset.fgAutoReload=KAL_FALSE;	
	
	gpt_handle=DclHGPT_Open(GPT2,0);
	DclHGPT_Control(gpt_handle,HGPT_CMD_RESET,&set_gpt);
	DclHGPT_Control(gpt_handle,HGPT_CMD_START,&set_gpt);
	
	while(!(DRV_GPT_Reg(GPT_STS) & GPT_STS_2) && (BusyWaitFlag==KAL_FALSE))
		;
	DclHGPT_Control(gpt_handle,HGPT_CMD_STOP,&set_gpt);
	DclHGPT_Close(gpt_handle);
	testcount++;
	userCount--;
}
#else

DCL_STATUS DclSGPT_Initialize(void)
{
	return STATUS_UNSUPPORTED;
}

DCL_HANDLE DclSGPT_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSGPT_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSGPT_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSGPT_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSGPT_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSGPT_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSGPT_Close(DCL_HANDLE *handle)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclFGPT_Initialize(void)
{
	return STATUS_UNSUPPORTED;
}

DCL_HANDLE DclFGPT_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclFGPT_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclFGPT_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclFGPT_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclFGPT_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclFGPT_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclFGPT_Close(DCL_HANDLE handle)
{
	return STATUS_UNSUPPORTED;
}
#endif
//#endif 

