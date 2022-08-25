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
 *    usbdl_pmu.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines functions that Power Management Unit can support
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
#include	"dcl_pmic_features.h"
#include	"drv_comm.h"
#include	"reg_base.h"
#include	"dcl.h"
#include	"drv_features_bmt.h"
#include	"bmt_chr_setting.h"
#include "chr_parameter.h"


extern kal_bool pmic_adpt_charge_source(void);
extern kal_uint32 INT_GetCurrentTime(void);
extern kal_bool IsInWithOutBatteryMode(void);

/*************************************************************************
* FUNCTION
*	USBDL_Cable_IN
*
* DESCRIPTION
*	This function is to query charger status.
*
* PARAMETERS
*	none
*
* RETURNS
*	TRUE: charger is present
*	FALSE: charger is not present
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool USBDL_Cable_IN(void)
{
#if defined(__BMT_2_0_ARCHITECTURE__)
	DCL_BOOL chr_det_status = DCL_FALSE;

	bl_chr_control_handler(BMT_BL_CHARGING_CMD_GET_CHR_DET_STATUS, &chr_det_status);

	return (kal_bool)chr_det_status;
#else
    return pmic_adpt_charge_source();
#endif

}

/*************************************************************************
* FUNCTION
*	BL_delay
*
* DESCRIPTION
*	This function is to delay unit:msr.
*
* PARAMETERS
*	ms: how many ms to delay
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void BL_delay(kal_uint8 ms)
{
	kal_uint32 current_time = 0, start_time = 0;
	/* wait for erase busy period (2ms) */
	start_time = INT_GetCurrentTime();
	do
	{
	   current_time = INT_GetCurrentTime();
	   if(current_time > start_time)
	   {
	      if( (current_time - start_time) > (67*ms))
	         break;
	   }
	   else
	   {
	      if( (0xFFFFFFFF - start_time + current_time + 1) > (67*ms))
	         break;
	   }
	}while(1);
	
}

DCL_UINT32 bmt_find_closest_level(const DCL_UINT32 *pList,DCL_UINT32 number,DCL_UINT32 level)
{
	kal_int32 i;

	for(i = (number - 1); i >=0; i--)
	{
	    if(pList[i] <= level)
	    {
	        return pList[i];
	    }    
	}

	return pList[0];

}

/*************************************************************************
* FUNCTION
*	BL_Disable_Usbdl_Wo_Battery
*
* DESCRIPTION
*	if charger is present and battery is not , the function keep looping till battery is on to avoid backlight be turned on.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void BL_Disable_Usbdl_Wo_Battery(void)
{
#if defined(__BMT_2_0_ARCHITECTURE__)

#if defined(__BACKUP_DOWNLOAD_RESTORE_WITHOUT_BATTERY_SOLUTION1__)
	DCL_BOOL chr_usbdl_reset = DCL_TRUE;
	bl_chr_control_handler(BMT_BL_CHARGING_CMD_SET_USBDL_RESET,&chr_usbdl_reset);
#endif //#if defined(__BACKUP_DOWNLOAD_RESTORE_WITHOUT_BATTERY_SOLUTION1__)

#if defined(__BACKUP_DOWNLOAD_RESTORE_WITHOUT_BATTERY_SOLUTION2__)
	DCL_BOOL bat_on_en=DCL_TRUE;
	DCL_BOOL bat_on_status=DCL_FALSE;
	DCL_BOOL usb_set = DCL_TRUE;
	DCL_BOOL chr_det_status = DCL_FALSE;


	bl_chr_control_handler(BMT_BL_CHARGING_CMD_GET_CHR_DET_STATUS, &chr_det_status);

	if (chr_det_status == DCL_TRUE)
	{
	//DRV_SetData(0xa0700a24,0x0010,0x0000);
	//DRV_SetData(0xa0700a18,0x0031,0x0001);
	//DRV_SetData(0xa0700a18,0x010F,0x0103);
	//DRV_SetData(0xa0700a00,0x0018,0x0018);
	//DRV_SetData(0xa0700a28,0x8000,0x8000);	
	bl_chr_control_handler(BMT_BL_CHARGING_CMD_SET_USBDL_SET,&usb_set);

	//enable BATON_EN 
	bl_chr_control_handler(BMT_BL_CHARGING_CMD_SET_BATON_ENABLE,&bat_on_en);
	//wait it work
	BL_delay(1);

	do
	{
		//kick system wdt
		WacthDogRestart();

		//kick charger wdt
		bl_chr_control_handler(BMT_BL_CHARGING_CMD_WDT_CLEAR,NULL);
		
		//query BATON_UNDET bit , 0:battery is ok , 1:battery is fail
		//bl_print(5,"query status\n\r");
		bl_chr_control_handler(BMT_BL_CHARGING_CMD_GET_BATON_STATUS,&bat_on_status);
	}
	while(bat_on_status==DCL_TRUE);

	//disable BATON_EN
	bat_on_en=DCL_FALSE;
	bl_chr_control_handler(BMT_BL_CHARGING_CMD_SET_BATON_ENABLE,&bat_on_en);

	//DRV_SetData(0xa0700a28,0x8000,0x0000);
	usb_set = DCL_FALSE;
	bl_chr_control_handler(BMT_BL_CHARGING_CMD_SET_USBDL_SET,&usb_set);

	}

#endif //#if defined(__BACKUP_DOWNLOAD_RESTORE_WITHOUT_BATTERY_SOLUTION2__)
#endif //#if defined(__BMT_2_0_ARCHITECTURE__)
}

/*************************************************************************
* FUNCTION
*	BL_Raise_Charger_Current
*
* DESCRIPTION
*	if charger is present and battery voltage is low (VBAT_CC_DET is false) , start charging to avoid shutdown before maui
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void BL_Raise_Charger_Current(void)
{
#if defined(__BMT_2_0_ARCHITECTURE__)

	DCL_BOOL chr_det_status = DCL_FALSE;
	DCL_BOOL vbat_cc_det_status = DCL_FALSE;
	DCL_BOOL enable = DCL_TRUE;
	PMU_CHR_CURRENT_ENUM set_charging_current = PMU_CHARGE_CURRENT_500_00_MA;



	bl_chr_control_handler(BMT_BL_CHARGING_CMD_GET_CC_STATUS, &vbat_cc_det_status);
	bl_chr_control_handler(BMT_BL_CHARGING_CMD_GET_CHR_DET_STATUS, &chr_det_status);


	if (vbat_cc_det_status == DCL_FALSE && chr_det_status == DCL_TRUE)
	{
		// find the nearest current
		bl_chr_control_handler(BMT_BL_CHARGING_CMD_GET_CHARGING_CURRENT, &set_charging_current);

		// set the current
		bl_chr_control_handler(BMT_BL_CHARGING_CMD_SET_CHARGING_CURRENT, &set_charging_current);		

		bl_chr_control_handler(BMT_BL_CHARGING_CMD_SET_CSDAC_ENABLE, &enable);		

		bl_chr_control_handler(BMT_BL_CHARGING_CMD_SET_CHR_ENABLE, &enable);		
	}
#else
	DCL_HANDLE pmu_handle;
	PMU_CTRL_CHR_SET_CHR_EN CtrlChrEn;
	PMU_CTRL_CHR_GET_CHR_CURRENT_LIST get_chr_current_list;
	PMU_CTRL_CHR_SET_CHR_CURRENT set_chr_current;
	PMU_CTRL_CHR_SET_CSDAC_EN chr_csdac_en;
	PMU_CTRL_CHR_GET_CC_DET ChrCcDet;
	PMU_CTRL_CHR_GET_CHR_DET_STATUS chrStatus;
	kal_int32 i;

	DclPMU_Initialize();

	pmu_handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);

	DclPMU_Control(pmu_handle, CHR_GET_CC_DET, (DCL_CTRL_DATA_T *)&ChrCcDet);
	DclPMU_Control(pmu_handle, CHR_GET_CHR_DET_STATUS, (DCL_CTRL_DATA_T *)&chrStatus);


	if (ChrCcDet.vbat_cc_det == DCL_FALSE && chrStatus.enable == DCL_TRUE)
	{
		// 找接近電流檔位
		{
			DclPMU_Control(pmu_handle, CHR_GET_CHR_CURRENT_LIST, (DCL_CTRL_DATA_T *)&get_chr_current_list);

			for(i = (get_chr_current_list.number - 1); i >=0; i--)
			{
				if(get_chr_current_list.pCurrentList[i] <= PMU_CHARGE_CURRENT_500_00_MA)
				{
					set_chr_current.current = (PMU_CHR_CURRENT_ENUM)get_chr_current_list.pCurrentList[i];
					break;
				}    
			}

			if(i <= 0)
			{
				set_chr_current.current = (PMU_CHR_CURRENT_ENUM)get_chr_current_list.pCurrentList[0];
			}

			DclPMU_Control(pmu_handle, CHR_SET_CHR_CURRENT, (DCL_CTRL_DATA_T *)&set_chr_current);
		
		}
		
		chr_csdac_en.enable = DCL_TRUE;
		DclPMU_Control(pmu_handle, CHR_SET_CSDAC_EN, (DCL_CTRL_DATA_T *)&chr_csdac_en);		  

		CtrlChrEn.enable = DCL_TRUE;
		DclPMU_Control(pmu_handle, CHR_SET_CHR_EN, (DCL_CTRL_DATA_T *)&CtrlChrEn);
	}

	DclPMU_Close(pmu_handle);   


#endif
	
}

void BL_HV_detection_init(void)
{
#if defined(__BMT_2_0_ARCHITECTURE__)
	DCL_BOOL chr_hv_enable = DCL_TRUE;
	#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
	kal_uint32 hv_voltage = CHR_VCHARGER_HV_HIGH;
	#else
	kal_uint32 hv_voltage = CHR_VCHARGER_HW_HIGH;
	#endif


	/*trigger HW Charger OVP before backlight on*/
	bl_chr_control_handler(BMT_BL_CHARGING_CMD_SET_HV_VOLTAGE, &hv_voltage);
	bl_chr_control_handler(BMT_BL_CHARGING_CMD_SET_HV_ENABLE, &chr_hv_enable);

	

#else
	DCL_UINT32 voltage;
	DCL_HANDLE pmu_handle;
	PMU_CTRL_CHR_GET_HV_DETECTION_VOLTAGE_LIST hv_voltage_list;
	PMU_CTRL_CHR_SET_HV_DETECTION_VOLTAGE hv_voltage;
	DCL_STATUS  status;

	DclPMU_Initialize();

	pmu_handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
	status=DclPMU_Control(pmu_handle, CHR_GET_HV_DETECTION_VOLTAGE_LIST, (
DCL_CTRL_DATA_T *)&hv_voltage_list);

	if(status==STATUS_UNSUPPORTED)
	{
		//drv_trace1(TRACE_GROUP_10, BMT_PMU_DO_NOT_SUPPORT_TRC, 0);
		return;
	}

#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
		voltage=CHR_VCHARGER_HV_HIGH;
#else
#if defined(CHR_HW_VCHARGER_HIGH)
		voltage=CHR_HW_VCHARGER_HIGH;
#else
		voltage=CHR_VCHARGER_HIGH;
#endif //#if defined(CHR_HW_VCHARGER_HIGH)
#endif

	hv_voltage.voltage=(PMU_VOLTAGE_ENUM)bmt_find_closest_level(hv_voltage_list.pVoltageList
		,hv_voltage_list.number,(DCL_UINT32)voltage);
	
	DclPMU_Control(pmu_handle, CHR_SET_HV_DETECTION_VOLTAGE, (DCL_CTRL_DATA_T *)&hv_voltage);
	DclPMU_Close(pmu_handle);   

#endif //#if defined(__BMT_2_0_ARCHITECTURE__)

}


/*************************************************************************
* FUNCTION
*	BL_Chr_Init
*
* DESCRIPTION
*	charger , usb download without battery init
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void BL_Chr_Init(void)
{

   BL_HV_detection_init();

   if(!IsInWithOutBatteryMode())
   {
      //BL_Disable_Usbdl_Wo_Battery();
   
#ifndef __DISABLE_RAISE_CHARGE_CURRENT_IN_BOOTLOADER__   
      BL_Raise_Charger_Current();
#endif
   }

   
}



