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
 * custom_sim_driver.C
 *
 * Project:
 * --------
 *   Gemini
 *
 * Description:
 * ------------
 *   this file is custom implementation of SIM driver
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include 	"reg_base.h"
#include 	"intrCtrl.h"
#include "multi_icc_custom.h"
/* Driver related*/
#include "drv_comm.h"
#include "dcl.h"

#ifdef DRV_SIM_ALL_SOLUTION_BUILT

extern void sim_init_hwCb(void);
extern void DRV_ICC_interface_init(SIM_ICC_APPLICATION application);

/*following is the template for dual SIM platform, I test it on TF68*/
/****************************************************
	customer and HW SA please fill from here
*****************************************************/
#ifdef __MTK_TARGET__
static const kal_uint32 iccSlotNum = 2;
#else          
#define iccSlotNum 2
#endif

const SIM_ICC_HW_SW_MAPPING	iccMappingTable[iccSlotNum] =
{
/*
logical number, application usage from user's view, do it connect to MT6302, owned by which SIM controller, MT6302 chip #, interface # of this MT6302
*/
#ifdef __SIM_HOT_SWAP_SUPPORT__
#if (defined(__SIM_HOT_SWAP_SLOT_1_SUPPORT__))
  {0, SIM_ICC_APPLICATION_PHONE1, MTK_SIMIF0, SIM_SWITCH_NONE, 0, 0, 0x11, KAL_FALSE, 100},
  {1, SIM_ICC_APPLICATION_PHONE2, MTK_SIMIF1, SIM_SWITCH_NONE, 0, 1, 0, KAL_FALSE, 0},
#elif (defined(__SIM_HOT_SWAP_SLOT_2_SUPPORT__))            
  {0, SIM_ICC_APPLICATION_PHONE2, MTK_SIMIF0, SIM_SWITCH_NONE, 0, 0, 0x11, KAL_FALSE, 100},
  {1, SIM_ICC_APPLICATION_PHONE1, MTK_SIMIF1, SIM_SWITCH_NONE, 0, 1, 0, KAL_FALSE, 0},
#endif
#else
  {0, SIM_ICC_APPLICATION_PHONE1, MTK_SIMIF0, SIM_SWITCH_NONE, 0, 0, 0, KAL_FALSE, 0},
  {1, SIM_ICC_APPLICATION_PHONE2, MTK_SIMIF1, SIM_SWITCH_NONE, 0, 1, 0, KAL_FALSE, 0},
#endif /* End of #ifdef __SIM_HOT_SWAP_SUPPORT__ */
};

/****************************************************
	end of custom table
*****************************************************/

/****************************************************
	only SW guys familiar with multiple SIM driver can modify following
*****************************************************/

void sim_init_all_cb(void)
{
	kal_uint32 loopIndex;
	sim_init_hwCb();

	for(loopIndex = 0; iccSlotNum > loopIndex; loopIndex++){
		DRV_ICC_interface_init(iccMappingTable[loopIndex].application);
	}
}

kal_uint32 sim_get_logicalNum_from_app(SIM_ICC_APPLICATION application)
{
	kal_uint32 loopIndex, loopMax = iccSlotNum;

	for(loopIndex = 0; loopIndex < loopMax; loopIndex++){
		if(application == iccMappingTable[loopIndex].application){
			if(iccSlotNum <= iccMappingTable[loopIndex].logicalNum)
				ASSERT(0);
			return iccMappingTable[loopIndex].logicalNum;
		}
	}

	return 0xffffffff;
}

kal_uint32 sim_get_MT6302_from_logicalNum(kal_uint32 logicalNum)
{
	kal_uint32 loopIndex, loopMax = iccSlotNum;

	if(iccSlotNum <= logicalNum)
				ASSERT(0);

	for(loopIndex = 0; loopIndex < loopMax; loopIndex++){
		if(logicalNum == iccMappingTable[loopIndex].logicalNum){
			if(SIM_SWITCH_6302 == (SIM_ICC_SWITCHCONTROL)iccMappingTable[loopIndex].needMT6302)
				return (iccMappingTable[loopIndex].MT6302ChipNum << 8) | (iccMappingTable[loopIndex].MT6302PortNum);
			else if(SIM_SWITCH_6306 == (SIM_ICC_SWITCHCONTROL)iccMappingTable[loopIndex].needMT6302)
				return (iccMappingTable[loopIndex].MT6302ChipNum << 8) | (iccMappingTable[loopIndex].MT6302PortNum) | (SIM_SWITCH_6306 <<16);
			else if(SIM_SWITCH_6314 == (SIM_ICC_SWITCHCONTROL)iccMappingTable[loopIndex].needMT6302)
				return (iccMappingTable[loopIndex].MT6302ChipNum << 8) | (iccMappingTable[loopIndex].MT6302PortNum) | (SIM_SWITCH_6314 <<16);
			else
				return SIM_ICC_MT6302_NONE;
		}
	}

	/*there is no this logical number*/
	ASSERT(0);
	return 0;
}

kal_uint32 sim_get_hwCtrl_from_logicalNum(kal_uint32 logicalNum)
{
	kal_uint32 loopIndex, loopMax = iccSlotNum;

	if(iccSlotNum <= logicalNum)
				ASSERT(0);

	for(loopIndex = 0; loopIndex < loopMax; loopIndex++){
		if(logicalNum == iccMappingTable[loopIndex].logicalNum){
			return iccMappingTable[loopIndex].hwCtrl;
		}
	}

	/*there is no this logical number*/
	ASSERT(0);
	return 0;
}

kal_uint32 sim_get_MT6302PeerInterface(kal_uint8 chipNum, kal_uint32 portNum)
{
	kal_uint32 loopIndex, loopMax = iccSlotNum;

	for(loopIndex = 0; loopIndex < loopMax; loopIndex++){
		if(chipNum == iccMappingTable[loopIndex].MT6302ChipNum && 
		   portNum == iccMappingTable[loopIndex].MT6302PortNum &&
		   KAL_TRUE == (kal_bool)iccMappingTable[loopIndex].needMT6302){
		   /* for MT6302 search peer interface */
			if(iccSlotNum <= iccMappingTable[loopIndex].logicalNum)
				ASSERT(0);
			return iccMappingTable[loopIndex].logicalNum;
		}
		else if(chipNum == iccMappingTable[loopIndex].MT6302ChipNum && 
		        portNum == iccMappingTable[loopIndex].MT6302PortNum){
		      /* for MT6306 search peer interface */
			if(iccSlotNum <= iccMappingTable[loopIndex].logicalNum)
				ASSERT(0);
			return iccMappingTable[loopIndex].logicalNum;
		}
	}


	/*there is no this logical number*/
	return SIM_ICC_MT6302_NONE;
}

kal_uint32 sim_get_ToalInterfaceCount()
{
	return iccSlotNum;
}

kal_uint32 get_CAS_icc_logicalNum()
{
	kal_uint32 loopIndex, loopMax = iccSlotNum;

	for(loopIndex = 0; loopIndex < loopMax; loopIndex++){
		if(SIM_ICC_APPLICATION_CMMB_SMD == iccMappingTable[loopIndex].application){
			if(iccSlotNum <= iccMappingTable[loopIndex].logicalNum)
				ASSERT(0);
			return iccMappingTable[loopIndex].logicalNum;
		}
	}

	/*there is no this logical number*/
	ASSERT(0);
	return 0;
}

kal_uint32 sim_custom_task_2_driver(kal_uint32 taskInterface)
{
   kal_uint32 rlt = 0;
   rlt = rlt;
#ifdef __SIM_HOT_SWAP_SUPPORT__
   switch((taskInterface >> 8) & 0xFF)
   {
	  case SIM_CUSTOM_T2D_GET_HOTSWAP_PROPERITY:
	  	 rlt = iccMappingTable[taskInterface & 0xFF].hotSwap | (iccMappingTable[taskInterface & 0xFF].polarity << 8);
	     break;
	  case SIM_CUSTOM_T2D_GET_HOTSWAP_DEBOUNDETIME:
		 rlt = iccMappingTable[taskInterface & 0xFF].debounceTime;
		 break;
	  default:
	  	 break;

   }
#endif
   return rlt;
}

#ifdef __ESSIM_SUPPORT__
//arden: DSSS
extern kal_bool	sim_physicalSlotChanged;
extern void sim_plug_out_call_back(kal_uint32 which_sim);
extern void sim_plug_in_call_back(kal_uint32 which_sim);

#define DSSS_TIMER_DURATION 120 /* 1.5 seconds*/
static kal_uint32   DSSS_timer_handle = DCL_HANDLE_INVALID;  /*gpt handle*/

static void DSSS_timer_stop(void)
{
	if (0xFF == DSSS_timer_handle)
	{
		return;
	}
	DclSGPT_Control(DSSS_timer_handle, SGPT_CMD_STOP,0);

}

static void  DSSS_Plugin_cb(void *parameter)
{
  	kal_prompt_trace(MOD_DRVKBD,"ARDEN:DSSS_Plugin_cb Function Start!");  
		sim_plug_in_call_back(SIM_CONFIG_AP_TYPE_PHONE1);
	kal_prompt_trace(MOD_DRVKBD,"ARDEN:DSSS_Plugin_cb Function End!");
	DSSS_timer_stop();
}


void DSSS_sim_switch_Slot(kal_bool sim_slot) // sim_slot=0,SIM1;sim_slot=1,SIM2
{
		kal_uint32   handle = DCL_HANDLE_INVALID;  /*gpt handle*/
	SGPT_CTRL_START_T start;
	kal_prompt_trace(MOD_DRVKBD,"ARDEN:sim_physicalSlotChanged 1 =%d",sim_physicalSlotChanged);
		sim_plug_out_call_back(SIM_CONFIG_AP_TYPE_PHONE1);
	kal_prompt_trace(MOD_DRVKBD,"ARDEN:sim_physicalSlotChanged 3 =%d",sim_physicalSlotChanged);

		sim_physicalSlotChanged = sim_slot;
//		kal_sleep_task(12*KAL_TICKS_100_MSEC);


	if (DCL_HANDLE_INVALID == DSSS_timer_handle)
	{
		handle = DclSGPT_Open(DCL_GPT_CB, 0);
		if (handle < 0)
		{
			kal_prompt_trace(MOD_DRVKBD, "DclSGPT_Open fail \n");
			return;
		}
		DSSS_timer_handle = handle;
	}

	start.pfCallback = DSSS_Plugin_cb;
	start.vPara = NULL;
	start.u2Tick= DSSS_TIMER_DURATION;

	DclSGPT_Control(DSSS_timer_handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);

}

#endif

#endif
