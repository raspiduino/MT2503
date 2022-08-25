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
 * switchControl_al.c(originally named sim_ctrl_al.c)
 *
 * Project:
 * --------
 *   Gemini
 *
 * Description:
 * ------------
 *   this file to handle original SIM task APIs on multiple SIM interface
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef DRV_SIM_OFF
#include  	"drv_comm.h"
 #ifdef __SIM_DRV_MULTI_DRV_ARCH__
#include 	"reg_base.h"
#include 	"intrCtrl.h"
#include    "sim_al.h"
#include    "sim_hw_mtk.h"
#include 		"dma_sw.h"
#include    "sim_sw_comm.h"
#include    "dma_hw.h"
#include    "multi_icc_custom.h"
//#include		"gpt_sw.h"
//#include		"gpio_sw.h"
#include		"drv_hisr.h"

#ifdef MT6318
#include 	"pmic6318_sw.h"
#endif   /*MT6318*/

#include	"usim_MT6302.h"

#if defined(MT6223P)
#include "pmu_sw.h"
#endif

#include "sim_ctrl_al.h"

#ifdef DCL_SIM_INTERFACE
#include "dcl.h"
#endif

#include "kal_trace.h"
#include "kal_debug.h"

//#ifdef DRV_MULTIPLE_SIM //DRV_2_SIM_CONTROLLER
#if (defined(DRV_SIM_ALL_SOLUTION_BUILT) || defined(DRV_MULTIPLE_SIM))

extern kal_char sim_dbg_str[];
extern sim_ctrlDriver sim_ctrlDriver_MT6302;
extern sim_ctrlDriver sim_ctrlDriver_MTK;
//static usim_dcb_struct usim_cb[DRV_SIM_MAX_LOGICAL_INTERFACE];

kal_uint32	hwCbArray[DRV_SIM_MAX_LOGICAL_INTERFACE]; //from logical number to sim_HW_cb

/*default driver used in pre-defined macro, customer can call sim_hookCtrlDriver to relpace what they want*/
#if defined(DRV_2_SIM_MT6302)
sim_ctrlDriver *sim_driverTable[DRV_SIM_MAX_LOGICAL_INTERFACE] = {&sim_ctrlDriver_MT6302, &sim_ctrlDriver_MT6302};
#elif defined(DRV_2_SIM_CONTROLLER)
sim_ctrlDriver *sim_driverTable[DRV_SIM_MAX_LOGICAL_INTERFACE] = {&sim_ctrlDriver_MTK, &sim_ctrlDriver_MTK};
#else
sim_ctrlDriver *sim_driverTable[DRV_SIM_MAX_LOGICAL_INTERFACE] = {&sim_ctrlDriver_MT6302, &sim_ctrlDriver_MT6302};
#endif

kal_bool	sim_physicalSlotChanged;

extern kal_uint8 is_HW_VERIFICATION_enabled(void);
extern kal_char sim_dbg_str[];

//extern kal_taskid kal_get_current_thread_ID(void);

#define	SIM_AL_ACTION_RESET		0x000F0001
#define	SIM_AL_ACTION_POWOFF		0x000F0002
#define	SIM_AL_ACTION_COMMAND	0x000F0003
#define	SIM_AL_ACTION_EOC			0x000F0004


#ifdef NO_SLIM_DEF
kal_bool sim_switchPhysicalSlotMapping(kal_bool inverse)
{
	kal_uint32 maskValue;

	maskValue = SaveAndSetIRQMask();
	sim_physicalSlotChanged = inverse;
	RestoreIRQMask(maskValue);

	if(KAL_FALSE == maskValue)
		kal_print("SIM slots mapping is default mapping now");
	else
		kal_print("SIM slots mapping is inverse mapping now");


	return sim_physicalSlotChanged;
}


/*this is just adaption layer, protections, project dependent work arounds should not be implemented here*/
void sim_hookCtrlDriver(kal_uint32 simInterface, sim_ctrlDriver *driver)
{

	if(KAL_TRUE == sim_physicalSlotChanged)
		simInterface = DRV_SIM_MAX_LOGICAL_INTERFACE -simInterface;


	if(0 != simInterface)
		ASSERT(0);
	sim_driverTable[simInterface] = driver;
}
#endif


usim_status_enum L1sim_Reset_All(sim_power_enum ExpectVolt, sim_power_enum *ResultVolt, kal_bool warm, SIM_ICC_APPLICATION application)
{
	sim_ctrlDriver *simDriver;
	usim_status_enum status;
	kal_uint32 simInterface;
#ifdef SIM_4_CARD_SMT_TEST
	SIM_ICC_APPLICATION anotherApplication;
	kal_uint32 anotherSimInterface;
	sim_power_enum anotherResultVolt;
	sim_ctrlDriver *anotherSimDriver;
	usim_status_enum anotherStatus;
#endif

	simInterface = sim_get_logicalNum_from_app(application);

	sprintf(sim_dbg_str,"L1sim_Reset_All=>expectvolt:%d,*resultvolt:%d,warm:%d,app:%d,IF:%d",ExpectVolt,*ResultVolt,warm,application,simInterface);
	kal_print(sim_dbg_str);
	
#ifdef SIM_4_CARD_SMT_TEST
	if(SIM_ICC_APPLICATION_PHONE1 == application)
		anotherApplication = SIM_ICC_APPLICATION_PHONE3;
	else if(SIM_ICC_APPLICATION_PHONE2 == application)
		anotherApplication = SIM_ICC_APPLICATION_PHONE4;
	else
		ASSERT(0);
	anotherSimInterface = sim_get_logicalNum_from_app(anotherApplication);
#endif

	if(DRV_SIM_MAX_LOGICAL_INTERFACE <= simInterface)
		ASSERT(0);
#ifdef SIM_4_CARD_SMT_TEST
	if(DRV_SIM_MAX_LOGICAL_INTERFACE <= anotherSimInterface)
		ASSERT(0);
#endif


	if(KAL_TRUE == sim_physicalSlotChanged){
		kal_print("[SIM]:sim interface inversed!!");
		simInterface = 1-simInterface;
	}


	if(0x0 == ResultVolt)
		ASSERT(0);

#ifdef __CUSTOMER_HW_VERIFICATION__
	simInterface = 0;
	/*find out the hooked function table*/
	simDriver = sim_driverTable[simInterface];
	ASSERT(0 != simDriver);
	sim_MT6302_addMsg(SIM_MT6302_ACTION_RESET, simInterface, 0, 0);
	status = simDriver->reset(ExpectVolt, ResultVolt, warm, (sim_HW_cb *)(hwCbArray[simInterface]));
	sim_MT6302_addMsg(SIM_MT6302_ACTION_EOC, simInterface, drv_get_current_time(), 0);
	simDriver->EOC((sim_HW_cb *)(hwCbArray[simInterface]));

	simInterface = 1;
	/*find out the hooked function table*/
	simDriver = sim_driverTable[simInterface];
	ASSERT(0 != simDriver);
	sim_MT6302_addMsg(SIM_MT6302_ACTION_RESET, simInterface, 0, 0);
	/*when we release single SIM MMI, we only release SIM1 MMI, cusrtomer won't get SIM2 MMI, SIM1 is what MMI need*/
	//status = simDriver->reset(ExpectVolt, ResultVolt, warm, simInterface);
	sim_MT6302_addMsg(SIM_MT6302_ACTION_EOC, simInterface, drv_get_current_time(), 0);
	simDriver->EOC(simInterface);
#else
	/*find out the hooked function table*/
	simDriver = sim_driverTable[simInterface];
	ASSERT(0 != simDriver);
	simDriver->addMessage(SIM_AL_ACTION_RESET, simInterface, (kal_uint32)kal_get_current_thread_ID(), 0);
	status = simDriver->reset(ExpectVolt, ResultVolt, warm, (sim_HW_cb *)(hwCbArray[simInterface]));
	simDriver->addMessage(SIM_AL_ACTION_EOC, simInterface, 0, 0);
	simDriver->EOC((sim_HW_cb *)(hwCbArray[simInterface]));

#ifdef SIM_4_CARD_SMT_TEST
	/*find out the hooked function table*/
	anotherSimDriver = sim_driverTable[anotherSimInterface];
	ASSERT(0 != anotherSimDriver);
	anotherSimDriver->addMessage(SIM_AL_ACTION_RESET, anotherSimInterface, (kal_uint32)kal_get_current_thread_ID(), 0);
	anotherStatus = anotherSimDriver->reset(UNKNOWN_POWER_CLASS, &anotherResultVolt, warm, (sim_HW_cb *)(hwCbArray[anotherSimInterface]));
	if(USIM_NO_ERROR == anotherStatus)
		kal_print("another SIM card found!!");
	else
		kal_print("another SIM card not found!!");
	anotherSimDriver->addMessage(SIM_AL_ACTION_EOC, anotherSimInterface, 0, 0);
	anotherSimDriver->EOC((sim_HW_cb *)(hwCbArray[anotherSimInterface]));
#endif

#endif
	return status;
}

#ifndef __MAUI_BASIC__
#ifdef NO_SLIM_DEF
/*	this function is called by SIM task in single MMI load to help customer verify their HW
	the mainly difference to L1sim_reset_all is to reset both interface twice to test that HW layout to both cards work
*/
usim_status_enum L1sim_Reset_All_HW_verification(sim_power_enum ExpectVolt, sim_power_enum *ResultVolt, kal_bool warm, kal_uint32 simInterface)
{
	usim_status_enum statusWeWant = USIM_NO_ERROR;
#ifdef SIM_HW_TEST
	sim_ctrlDriver *simDriver;
	usim_status_enum status = USIM_NO_ERROR;
	kal_uint32 interfaceWeWant;

	/*This function should be only called when SIM task call is_HW_VERIFICATION_enabled and it return 1 or 2*/
	if(1 != is_HW_VERIFICATION_enabled() && 2 != is_HW_VERIFICATION_enabled())
		ASSERT(0);

	interfaceWeWant = simInterface;
	simInterface = 0;
	/*find out the hooked function table*/
	simDriver = sim_driverTable[simInterface];
	ASSERT(0 != simDriver);
	simDriver->addMessage(SIM_AL_ACTION_RESET, simInterface, 0, 0);
	status = simDriver->reset(ExpectVolt, ResultVolt, warm, (sim_HW_cb *)(hwCbArray[simInterface]));
	if(0 == interfaceWeWant)
		statusWeWant = status;
	simDriver->addMessage(SIM_AL_ACTION_EOC, simInterface, 0, 0);
	simDriver->EOC((sim_HW_cb *)(hwCbArray[simInterface]));

	simInterface = 1;
	/*find out the hooked function table*/
	simDriver = sim_driverTable[simInterface];
	ASSERT(0 != simDriver);
	simDriver->addMessage(SIM_AL_ACTION_RESET, simInterface, 0, 0);
	status = simDriver->reset(ExpectVolt, ResultVolt, warm, (sim_HW_cb *)(hwCbArray[simInterface]));
	if(1 == interfaceWeWant)
		statusWeWant = status;
	simDriver->addMessage(SIM_AL_ACTION_EOC, simInterface, 0, 0);
	simDriver->EOC((sim_HW_cb *)(hwCbArray[simInterface]));

	return statusWeWant;
#else
	ASSERT(0);
#endif
   return statusWeWant;
}
#endif
#endif

sim_status L1sim_Cmd_All(kal_uint8  *txData,kal_uint32  *txSize,kal_uint8  *rxData, kal_uint32  *rxSize, SIM_ICC_APPLICATION application)
{
	sim_ctrlDriver *simDriver;
	sim_status status;

	kal_uint32 simInterface;

	simInterface = sim_get_logicalNum_from_app(application);

	if(DRV_SIM_MAX_LOGICAL_INTERFACE <= simInterface)
		ASSERT(0);

	if(KAL_TRUE == sim_physicalSlotChanged)
		simInterface = 1-simInterface;


	if(0x0 == txData || 0x0 == txSize || 0x0 == rxSize)
		ASSERT(0);

	/*find out the hooked function table*/
	simDriver = sim_driverTable[simInterface];
	ASSERT(0 != simDriver);
	simDriver->addMessage(SIM_AL_ACTION_COMMAND, simInterface, (kal_uint32)kal_get_current_thread_ID(), 0);
	status = simDriver->command(txData, txSize, rxData, rxSize, (sim_HW_cb *)(hwCbArray[simInterface]));
	simDriver->addMessage(SIM_AL_ACTION_EOC, simInterface, 0, 0);
	simDriver->EOC((sim_HW_cb *)(hwCbArray[simInterface]));
	return status;
}

void L1sim_PowerOff_All(SIM_ICC_APPLICATION application)
{
	sim_ctrlDriver *simDriver;
	kal_uint32 simInterface;

	simInterface = sim_get_logicalNum_from_app(application);

	if(DRV_SIM_MAX_LOGICAL_INTERFACE <= simInterface)
		ASSERT(0);

	if(KAL_TRUE == sim_physicalSlotChanged)
		simInterface = 1-simInterface;


	/*find out the hooked function table*/
	simDriver = sim_driverTable[simInterface];
	ASSERT(0 != simDriver);
	simDriver->addMessage(SIM_AL_ACTION_POWOFF, simInterface, (kal_uint32)kal_get_current_thread_ID(), 0);
	simDriver->powerOff((sim_HW_cb *)(hwCbArray[simInterface]));
	simDriver->addMessage(SIM_AL_ACTION_EOC, simInterface, 0, 0);
	simDriver->EOC((sim_HW_cb *)(hwCbArray[simInterface]));
}

void L1sim_Get_Card_Info_All(sim_info_struct *info, SIM_ICC_APPLICATION application)
{
	sim_ctrlDriver *simDriver;
	kal_uint32 simInterface;

	simInterface = sim_get_logicalNum_from_app(application);


	if(DRV_SIM_MAX_LOGICAL_INTERFACE <= simInterface)
		ASSERT(0);

	if(KAL_TRUE == sim_physicalSlotChanged)
		simInterface = 1-simInterface;


	/*find out the hooked function table*/
	simDriver = sim_driverTable[simInterface];
	ASSERT(0 != simDriver);
	simDriver->getCardInfo(info, (sim_HW_cb *)(hwCbArray[simInterface]));
}

void L1sim_Enable_Enhanced_Speed_All(kal_bool enable, SIM_ICC_APPLICATION application)
{
#ifdef NO_SLIM_DEF
	sim_ctrlDriver *simDriver;
	kal_uint32 simInterface;

	simInterface = sim_get_logicalNum_from_app(application);

	if(DRV_SIM_MAX_LOGICAL_INTERFACE <= simInterface)
		ASSERT(0);

	if(KAL_TRUE == sim_physicalSlotChanged)
		simInterface = 1-simInterface;


	/*find out the hooked function table*/
	simDriver = sim_driverTable[simInterface];
	ASSERT(0 != simDriver);
	simDriver->enableEnhancedSpeed(enable, (sim_HW_cb *)(hwCbArray[simInterface]));
#endif	
}

void L1sim_Select_Prefer_PhyLayer_All(sim_protocol_phy_enum T, SIM_ICC_APPLICATION application)
{
	sim_ctrlDriver *simDriver;
	kal_uint32 simInterface;

	simInterface = sim_get_logicalNum_from_app(application);

	if(DRV_SIM_MAX_LOGICAL_INTERFACE <= simInterface)
		ASSERT(0);

	if(KAL_TRUE == sim_physicalSlotChanged)
		simInterface = 1-simInterface;


	/*find out the hooked function table*/
	simDriver = sim_driverTable[simInterface];
	ASSERT(0 != simDriver);
	simDriver->selectPreferPhyLayer(T, (sim_HW_cb *)(hwCbArray[simInterface]));
}

kal_bool L1sim_Set_ClockStopMode_All(sim_clock_stop_enum mode, SIM_ICC_APPLICATION application)
{
	sim_ctrlDriver *simDriver;
	kal_bool status;
	kal_uint32 simInterface;

	simInterface = sim_get_logicalNum_from_app(application);

	if(DRV_SIM_MAX_LOGICAL_INTERFACE <= simInterface)
		ASSERT(0);

	if(KAL_TRUE == sim_physicalSlotChanged)
		simInterface = 1-simInterface;


	/*find out the hooked function table*/
	simDriver = sim_driverTable[simInterface];
	ASSERT(0 != simDriver);
	status = simDriver->setClockStopMode(mode, (sim_HW_cb *)(hwCbArray[simInterface]));
	return status;
}

#ifdef NO_SLIM_DEF
/*for specific purpose, SIM task should not call this */
void sim_releaseOwner(SIM_ICC_APPLICATION application)
{
	usim_dcb_struct *usim_dcb;
	kal_uint32 simInterface;

	simInterface = sim_get_logicalNum_from_app(application);

	usim_dcb = GET_USIM_CB(simInterface);

	if(DRV_SIM_MAX_LOGICAL_INTERFACE <= simInterface)
		ASSERT(0);

	if(KAL_TRUE == sim_physicalSlotChanged)
		simInterface = 1-simInterface;


	usim_dcb->ownerTask = 0;
}
#endif
/*following are pure SW query, no matter of different driver solutions*/
sim_card_speed_type L1sim_Get_CardSpeedType(SIM_ICC_APPLICATION application)
{
	Sim_Card *SimCard;
	kal_uint32 simInterface;

	simInterface = sim_get_logicalNum_from_app(application);

	SimCard = GET_SIM_CB(simInterface);

   return SimCard->sim_card_speed;
}

kal_bool sim_queryGet9000WhenSelect(SIM_ICC_APPLICATION application)
{
	Sim_Card *SimCard;
	kal_uint32 simInterface;

	simInterface = sim_get_logicalNum_from_app(application);
	SimCard = GET_SIM_CB(simInterface);

	return SimCard->get9000WhenSelect;
}

void sim_toutTest_al(kal_uint32 toutValue, SIM_ICC_APPLICATION application)
{
#ifdef SIM_HW_TEST
	sim_ctrlDriver *simDriver;	
	kal_uint32 simInterface;

	simInterface = sim_get_logicalNum_from_app(application);

	if(DRV_SIM_MAX_LOGICAL_INTERFACE <= simInterface)
		ASSERT(0);

	if(KAL_TRUE == sim_physicalSlotChanged)
		simInterface = 1-simInterface;


	/*find out the hooked function table*/
	simDriver = sim_driverTable[simInterface];
	ASSERT(0 != simDriver);
	simDriver->toutTest(toutValue, (sim_HW_cb *)(hwCbArray[simInterface]));

#endif
}
#endif

#ifdef DCL_SIM_INTERFACE
/*dcl add new api : 1. fill table*/
DCL_SIMDriver_t sim_ctrlDriver_All = {
	(DCL_SIM_RST)L1sim_Reset_All,
	(DCL_SIM_CMD)L1sim_Cmd_All,
	(DCL_SIM_PWOFF)L1sim_PowerOff_All,
	(DCL_SIM_GET_CARD_INFO)L1sim_Get_Card_Info_All,
	(DCL_SIM_SET_MAX_SPEED)L1sim_Enable_Enhanced_Speed_All,
	(DCL_SIM_SET_PREFER_PROTOCOL)L1sim_Select_Prefer_PhyLayer_All,
	(DCL_SIM_SET_CLK_STOP_MODE)L1sim_Set_ClockStopMode_All,
	(DCL_SIM_TOUT_TEST)sim_toutTest_al,
	NULL,
	(DCL_SIM_GAT_CARD_SPEED)L1sim_Get_CardSpeedType,
	(DCL_SIM_QUERY_GET_9000_WHEN_SELECT)sim_queryGet9000WhenSelect
};
#endif //DCL_SIM_INTERFACE

#endif /*__SIM_DRV_MULTI_DRV_ARCH__*/

#else //DRV_SIM_OFF
#include  	"drv_comm.h"

#ifdef DCL_SIM_INTERFACE
#include "dcl.h"
void sim_dummyAPI(void){}
DCL_SIMDriver_t sim_ctrlDriver_All = {
	(DCL_SIM_RST)sim_dummyAPI,
	(DCL_SIM_CMD)sim_dummyAPI,
	(DCL_SIM_PWOFF)sim_dummyAPI,
	(DCL_SIM_GET_CARD_INFO)sim_dummyAPI,
	(DCL_SIM_SET_MAX_SPEED)sim_dummyAPI,
	(DCL_SIM_SET_PREFER_PROTOCOL)sim_dummyAPI,
	(DCL_SIM_SET_CLK_STOP_MODE)sim_dummyAPI,
	NULL,
	(DCL_SIM_GAT_CARD_SPEED)sim_dummyAPI,
	(DCL_SIM_QUERY_GET_9000_WHEN_SELECT)sim_dummyAPI
};
#endif //DCL_SIM_INTERFACE

#endif //DRV_SIM_OFF

