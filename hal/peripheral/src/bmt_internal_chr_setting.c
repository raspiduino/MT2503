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
 *    bmt_internal_chr_setting.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines bmt internal charger hw setting function
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include "stack_config.h"
#include "bmt_trc.h"
#include "bmt_chr_setting.h"
#include "bmt_utility.h"
#include "bmt_hw.h"


// ============================================================ //
//define
// ============================================================ //
#define GETARRAYNUM(array) (sizeof(array)/sizeof(array[0]))


// ============================================================ //
//global variable
// ============================================================ //
//static DCL_HANDLE bmt_internal_chr_Handler;


// ============================================================ //
// function prototype
// ============================================================ //


// ============================================================ //
//extern variable
// ============================================================ //

// ============================================================ //
//extern function
// ============================================================ //


// ============================================================ //
static DCL_STATUS Internal_chr_init(void *data)
{
	return STATUS_OK;
}


static DCL_STATUS bmt_battery_on_det_status(void *data)
{
	DCL_STATUS status = STATUS_OK;
	DCL_UINT16 register_value;
	
	register_value = DRV_BMT_Reg(CHR_CON0 + RGS_BATON_UNDET_OFFSET);
	*(DCL_BOOL*)(data) = ((register_value & RGS_BATON_UNDET_MASK) >> RGS_BATON_UNDET_SHIFT);

	return status;
}


static DCL_STATUS bmt_get_chr_det_status(void *data)
{
	DCL_STATUS status = STATUS_OK;
	DCL_UINT16 register_value;
	
	register_value = DRV_BMT_Reg(CHR_CON0 + RGS_CHRDET_OFFSET);
	*(DCL_BOOL*)(data) = ((register_value & RGS_CHRDET_MASK) >> RGS_CHRDET_SHIFT);

	return status;
}


static DCL_STATUS bmt_get_bat_ov_status(void *data)
{
	DCL_STATUS status = STATUS_OK;
	DCL_UINT16 register_value;
	
	register_value = DRV_BMT_Reg(CHR_CON0 + RGS_VBAT_OV_DET_OFFSET);
	*(DCL_BOOL*)(data) = ((register_value & RGS_VBAT_OV_DET_MASK) >> RGS_VBAT_OV_DET_SHIFT);

	return status;
}


static DCL_STATUS bmt_set_adcbits(void *data)
{
	DCL_STATUS status = STATUS_OK;
	DCL_UINT32 adc_value;

	adc_value = *(DCL_UINT32*)(data);
	status = bmt_set_register_value(RG_ADCIN_VBAT_EN_OFFSET,RG_ADCIN_CHR_EN_MASK|RG_ADCIN_VSEN_EN_MASK|RG_ADCIN_VBAT_EN_MASK,adc_value<<RG_ADCIN_VBAT_EN_SHIFT);
	
	return status;
}


static DCL_STATUS bmt_set_chr_wdt_clear(void *data)
{
	DCL_STATUS status = STATUS_OK;
	DCL_UINT16 register_value;

	// To reset Charger WDT counter 
	bmt_set_register_value(RG_CHRWDT_WR_OFFSET,RG_CHRWDT_WR_MASK,1<<RG_CHRWDT_WR_SHIFT);	//for MT6250
	bmt_set_register_value(RG_CHRWDT_EN_OFFSET,RG_CHRWDT_EN_MASK,1<<RG_CHRWDT_EN_SHIFT);	// for MT6255/ MT6256
	
	// The polling in 36, 76E1, 55E1, 51E1, 53EL E1 should be ~2ms (50% error ratio)
	// After MACRO modification, it will be 2us
	while (1)
	{
		register_value = DRV_BMT_Reg((CHR_CON0 + RGS_CHRWDT_OUT_OFFSET));
		if (RGS_CHRWDT_OUT_MASK & register_value)
		{
			;
		}
		else
		{
			break;
		}

	}

	// Clear MixedSYS WDT flag
	bmt_set_register_value(CHRWDT_FLAG_WR_OFFSET,CHRWDT_FLAG_WR_MASK,1<<CHRWDT_FLAG_WR_SHIFT);

	return status;	
}


#if !defined(BMT_CHARGING_DISABLE)

#ifdef __DRV_BMT_HIGH_BATTERY_SUPPORT__
static DCL_STATUS bmt_charging_set_ov_voltage(void *data)
{
	DCL_STATUS status = STATUS_OK;
	DCL_UINT16 register_value;
	
	register_value = bmt_parameter_to_value(chr_VBAT_OV_VTH, GETARRAYNUM(chr_VBAT_OV_VTH) ,*(DCL_UINT32 *)(data));
	status = bmt_set_register_value(RG_VBAT_OV_VTH_OFFSET,RG_VBAT_OV_VTH_MASK,register_value<<RG_VBAT_OV_VTH_SHIFT);

	return status;
}


static DCL_UINT32 bmt_find_closest_CV_voltage(const DCL_UINT32 *pList,DCL_UINT32 number,DCL_UINT32 level)
{
	DCL_INT32 i;
	DCL_BOOL max_value_in_last_element;

	if(pList[number-2] < pList[number-1])
		max_value_in_last_element = DCL_TRUE;
	else
		max_value_in_last_element = DCL_FALSE;

	if(max_value_in_last_element == DCL_TRUE)
	{
		for(i = (number-1); i != 0; i--)	//max value in the last element
		{
			if(PMU_VOLT_INVALID == i)
				continue;
			
		    if(pList[i] <= level)
		    {
		        return pList[i];
		    }    
		}

		if(pList[0] == PMU_VOLT_INVALID)
			ASSERT(0);
		
		return pList[0];
	}
	else
	{
		for(i = 0; i< number; i++)	// max value in the first element
		{
			if(PMU_VOLT_INVALID == i)
				continue;
		
		    if(pList[i] <= level)
		    {
		        return pList[i];
		    }    
		}

		if(pList[number-1] == PMU_VOLT_INVALID)
			ASSERT(0);
		
		return pList[number-1];
	}
}
#endif


static DCL_UINT32 bmt_find_closest_level(const DCL_UINT32 *pList,DCL_UINT32 number,DCL_UINT32 level)
{
	DCL_INT32 i;
	DCL_BOOL max_value_in_last_element;

	if(pList[0] < pList[1])
		max_value_in_last_element = DCL_TRUE;
	else
		max_value_in_last_element = DCL_FALSE;

	if(max_value_in_last_element == DCL_TRUE)
	{
		for(i = (number-1); i != 0; i--)	//max value in the last element
		{
		    if(pList[i] <= level)
		    {
		        return pList[i];
		    }    
		}

		//return pList[0];
		return PMU_CHARGE_CURRENT_0_00_MA;
	}
	else
	{
		for(i = 0; i< number; i++)	// max value in the first element
		{
		    if(pList[i] <= level)
		    {
		        return pList[i];
		    }    
		}

		//return pList[number -1];
		return PMU_CHARGE_CURRENT_0_00_MA;
	}

}


static void bmt_find_and_set_the_nearest_charger_high_voltage(DCL_UINT32 voltage)
{
	DCL_UINT32 set_hv_voltage;
	DCL_UINT32 array_size;
	DCL_UINT16 register_value;
	
	array_size = GETARRAYNUM(chr_VCDT_HV_VTH);
	set_hv_voltage = bmt_find_closest_level(chr_VCDT_HV_VTH, array_size, voltage);
	register_value = bmt_parameter_to_value(chr_VCDT_HV_VTH, array_size ,set_hv_voltage);
	bmt_set_register_value(RG_VCDT_HV_VTH_OFFSET,RG_VCDT_HV_VTH_MASK,register_value<<RG_VCDT_HV_VTH_SHIFT);
}


static DCL_STATUS bmt_charging_set_cv_detection_voltage(void *data)
{
	DCL_STATUS status = STATUS_OK;
	DCL_UINT16 register_value;
	
	if(TrimmingData.CV_Trim_Enable == DCL_FALSE)
	{
		register_value = bmt_parameter_to_value(chr_VBAT_CV_VTH, GETARRAYNUM(chr_VBAT_CV_VTH) ,*(DCL_UINT32 *)(data));
	}
	else
	{
		#ifdef __DRV_BMT_HIGH_BATTERY_SUPPORT__
		{
			DCL_UINT32 array_size;
			DCL_UINT32 cv_voltage, set_cv_voltage;
			DCL_INT32  offset_voltage;
			DCL_UINT32 base_voltage = PMU_VOLT_04_200000_V;

			offset_voltage = chr_VBAT_CV_VTH[TrimmingData.CV_Trim_Data] - base_voltage;

			cv_voltage = (*(DCL_UINT32 *)(data)) + offset_voltage;
			array_size = GETARRAYNUM(chr_VBAT_CV_VTH);
			set_cv_voltage = bmt_find_closest_CV_voltage(chr_VBAT_CV_VTH,array_size,cv_voltage);
			register_value = bmt_parameter_to_value(chr_VBAT_CV_VTH, array_size ,set_cv_voltage);
		}
		#else
			register_value = TrimmingData.CV_Trim_Data;
		#endif
	}
	status = bmt_set_register_value(RG_VBAT_CV_VTH_OFFSET,RG_VBAT_CV_VTH_MASK,register_value<<RG_VBAT_CV_VTH_SHIFT);

	return status;
}


static DCL_STATUS bmt_charging_get_cv_status(void *data)
{
	DCL_STATUS status = STATUS_OK;
	DCL_UINT16 register_value;
	
	register_value = DRV_BMT_Reg(CHR_CON0 + RGS_VBAT_CV_DET_OFFSET);
	*(DCL_BOOL*)(data) = ((register_value & RGS_VBAT_CV_DET_MASK) >> RGS_VBAT_CV_DET_SHIFT);

	return status;
}


static DCL_STATUS bmt_charging_get_hv_status(void *data)
{
	DCL_STATUS status = STATUS_OK;
	DCL_UINT16 register_value;
	
	register_value = DRV_BMT_Reg(CHR_CON0 + RGS_VCDT_HV_DET_OFFSET);
	*(DCL_BOOL*)(data) = ((register_value & RGS_VCDT_HV_DET_MASK) >> RGS_VCDT_HV_DET_SHIFT);

	return status;
}


static DCL_STATUS bmt_find_and_set_the_nearest_current(void *data)
{
	DCL_STATUS status = STATUS_OK;
	DCL_UINT32 set_chr_current;
	DCL_UINT32 array_size;
	DCL_UINT16 register_value;
	
	array_size = GETARRAYNUM(chr_CS_VTH);
	set_chr_current = bmt_find_closest_level(chr_CS_VTH, array_size, *(DCL_UINT32 *)data);
	register_value = bmt_parameter_to_value(chr_CS_VTH, array_size ,set_chr_current);
	status = bmt_set_register_value(RG_CS_VTH_OFFSET,RG_CS_VTH_MASK,register_value<<RG_CS_VTH_SHIFT);

	return status;
}


static DCL_STATUS bmt_get_the_less_nearest_current(void *data)
{
	DCL_STATUS status = STATUS_OK;
	DCL_UINT32 array_size;
	
	array_size = GETARRAYNUM(chr_CS_VTH);
	*(DCL_UINT32 *)data = bmt_find_closest_level(chr_CS_VTH, array_size, *(DCL_UINT32 *)data);
	
	return status;
}



static DCL_STATUS bmt_charging_enable(void *data)	
{
	DCL_STATUS status = STATUS_OK;
	DCL_BOOL enable = *(DCL_BOOL*)(data);
	DCL_BOOL chr_detect;

	if(enable == KAL_TRUE)
	{
		#ifdef __DRV_BMT_HIGH_BATTERY_SUPPORT__
		{
			if(bmt_high_battery_cv > bmt_high_battery_ov || ((bmt_high_battery_cv != PMU_VOLT_04_300000_V) && (bmt_high_battery_cv != PMU_VOLT_04_350000_V)))
			{
				ASSERT(0);
			}
			bmt_charging_set_cv_detection_voltage(&bmt_high_battery_cv);
			bmt_charging_set_ov_voltage(&bmt_high_battery_ov);
		}	
		#else
		{
			DCL_UINT32 cv_det_voltage = PMU_VOLT_04_200000_V;
			bmt_charging_set_cv_detection_voltage(&cv_det_voltage);
		}	
		#endif
		bmt_set_register_value(RG_VBAT_CV_EN_OFFSET,RG_VBAT_CV_EN_MASK,enable<<RG_VBAT_CV_EN_SHIFT);
	}

	bmt_set_chr_wdt_clear(NULL);

	bmt_set_register_value(RG_CSDAC_EN_OFFSET,RG_CSDAC_EN_MASK,enable<<RG_CSDAC_EN_SHIFT);
	bmt_set_register_value(RG_HWCV_EN_OFFSET,RG_HWCV_EN_MASK,enable<<RG_HWCV_EN_SHIFT);

	bmt_find_and_set_the_nearest_charger_high_voltage(bmt_charging_para.VCHARGER_HV_HIGH);

	bmt_get_chr_det_status(&chr_detect);		

	if(chr_detect == DCL_TRUE)
	{
		// Enable charger-in high voltage detection
		bmt_set_register_value(RG_VCDT_HV_EN_OFFSET,RG_VCDT_HV_EN_MASK,1<<RG_VCDT_HV_EN_SHIFT);
		
		// 128us
		bmt_set_register_value(RG_CSDAC_DLY_OFFSET,RG_CSDAC_DLY_MASK,3<<RG_CSDAC_DLY_SHIFT);

		// Step = 1
		bmt_set_register_value(RG_CSDAC_STP_OFFSET,RG_CSDAC_STP_MASK,0<<RG_CSDAC_STP_SHIFT);

		// RG_OVP_TRIM
		if(TrimmingData.OV_Trim_Enable == DCL_TRUE)
		{
			bmt_set_register_value(RG_OVP_TRIM_OFFSET,RG_OVP_TRIM_MASK,TrimmingData.OV_Trim_Data<<RG_OVP_TRIM_SHIFT);
		}

		bmt_set_register_value(CHR_EN_OFFSET,CHR_EN_MASK,enable<<CHR_EN_SHIFT);
		
		// Set csdac_mode=1 , remove after init setting rdy
		if (enable == DCL_TRUE)
		{
			bmt_set_register_value(RG_CSDAC_MODE_OFFSET,RG_CSDAC_MODE_MASK,enable<<RG_CSDAC_MODE_SHIFT);
		}
	}

	drv_trace1(TRACE_GROUP_10, BMT_CHARGE_ENABLE_TRC, enable);

	return status;
}
#endif	//#if !defined(BMT_CHARGING_DISABLE)


static DCL_STATUS (* const bmt_internal_charging_func[BMT_CHARGING_CMD_NUMBER])(void *data)=
{
	 Internal_chr_init
	,bmt_battery_on_det_status
	,bmt_get_chr_det_status
	,bmt_get_bat_ov_status
	,bmt_set_chr_wdt_clear
	,bmt_set_adcbits
#if !defined(BMT_CHARGING_DISABLE)	
	,bmt_charging_enable
	,bmt_find_and_set_the_nearest_current	
	,bmt_charging_set_cv_detection_voltage
	,bmt_charging_get_cv_status
	,bmt_get_the_less_nearest_current
	,bmt_charging_get_hv_status
#endif	
};


/*
* FUNCTION
*	   Internal_chr_control_handler
*
* DESCRIPTION                                                           
*   	This function is called to set the charger hw
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
DCL_STATUS Internal_chr_control_handler(BMT_CHARGING_CTRL_CMD cmd, void *data)
{
	DCL_STATUS status;
	if(cmd < BMT_CHARGING_CMD_NUMBER)
		status = bmt_internal_charging_func[cmd](data);
	else
		return STATUS_UNSUPPORTED;

	return status;
}

