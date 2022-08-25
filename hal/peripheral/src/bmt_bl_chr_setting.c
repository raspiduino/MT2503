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
 *    bmt_bl_chr_setting.c
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include "stack_config.h"
#include "bmt_trc.h"
#include "bmt_chr_setting.h"
#include "bmt_hw.h"


// ============================================================ //
//define
// ============================================================ //
#define GETARRAYNUM(array) (sizeof(array)/sizeof(array[0]))

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


// ============================================================ //
#if defined( __BMT_2_0_ARCHITECTURE__)
#if defined(__EXT_BOOTLOADER__)
static DCL_STATUS bmt_get_chr_det_status(void *data)
{
	DCL_STATUS status = STATUS_OK;
	DCL_UINT16 register_value;
	
	register_value = DRV_BMT_Reg(CHR_CON0 + RGS_CHRDET_OFFSET);
	*(DCL_BOOL*)(data) = ((register_value & RGS_CHRDET_MASK) >> RGS_CHRDET_SHIFT);

	return status;
}

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


static DCL_STATUS bmt_charging_get_cc_status(void *data)
{
	DCL_STATUS status = STATUS_OK;
	DCL_UINT16 register_value;
	
	register_value = DRV_BMT_Reg(CHR_CON0 + RGS_VBAT_CC_DET_OFFSET);
	*(DCL_BOOL*)(data) = ((register_value & RGS_VBAT_CC_DET_MASK) >> RGS_VBAT_CC_DET_SHIFT);

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


static DCL_STATUS bmt_charging_set_csdac_en(void *data)
{
	DCL_STATUS status = STATUS_OK;
	DCL_BOOL enable = *(DCL_BOOL*)(data);

	status = bmt_set_register_value(RG_CSDAC_EN_OFFSET,RG_CSDAC_EN_MASK,enable<<RG_CSDAC_EN_SHIFT);
	
	return status;
}


static DCL_STATUS bmt_charging_set_chr_en(void *data)
{
	DCL_STATUS status = STATUS_OK;
	DCL_BOOL enable = *(DCL_BOOL*)(data);

	status = bmt_set_register_value(CHR_EN_OFFSET,CHR_EN_MASK,enable<<CHR_EN_SHIFT);
	
	return status;
}


static DCL_STATUS bmt_find_and_set_the_nearest_charger_high_voltage(void *data)
{
	DCL_STATUS status = STATUS_OK;
	DCL_UINT32 set_hv_voltage;
	DCL_UINT32 array_size;
	DCL_UINT16 register_value;
	DCL_UINT32 voltage = *(DCL_UINT32*)(data);
	
	array_size = GETARRAYNUM(chr_VCDT_HV_VTH);
	set_hv_voltage = bmt_find_closest_level(chr_VCDT_HV_VTH, array_size, voltage);
	register_value = bmt_parameter_to_value(chr_VCDT_HV_VTH, array_size ,set_hv_voltage);
	bmt_set_register_value(RG_VCDT_HV_VTH_OFFSET,RG_VCDT_HV_VTH_MASK,register_value<<RG_VCDT_HV_VTH_SHIFT);

	return status;
}


static DCL_STATUS bmt_charging_set_hv_en(void *data)
{
	DCL_STATUS status = STATUS_OK;
	DCL_BOOL enable = *(DCL_BOOL*)(data);

	status = bmt_set_register_value(RG_VCDT_HV_EN_OFFSET,RG_VCDT_HV_EN_MASK,enable<<RG_VCDT_HV_EN_SHIFT);
	
	return status;
}


static DCL_STATUS bmt_charging_set_usbdl_reset(void *data)
{
	DCL_STATUS status = STATUS_OK;
	DCL_BOOL enable = *(DCL_BOOL*)(data);;

	status = bmt_set_register_value(RG_USBDL_RST_OFFSET,RG_USBDL_RST_MASK,enable<<RG_USBDL_RST_SHIFT);
	
	return status;
}


static DCL_STATUS bmt_charging_get_baton_status(void *data)
{
	DCL_STATUS status = STATUS_OK;
	DCL_UINT16 register_value;

	register_value = DRV_BMT_Reg(CHR_CON0 + RGS_BATON_UNDET_OFFSET);
	*(DCL_BOOL*)(data) = ((register_value & RGS_BATON_UNDET_MASK) >> RGS_BATON_UNDET_SHIFT);

	return status;
}


static DCL_STATUS bmt_charging_set_baton_en(void *data)
{
	DCL_STATUS status = STATUS_OK;
	DCL_BOOL enable = *(DCL_BOOL*)(data);

	status = bmt_set_register_value(RG_BATON_EN_OFFSET,RG_BATON_EN_MASK,enable<<RG_BATON_EN_SHIFT);
	
	return status;
}


static DCL_STATUS bmt_charging_set_usbdl_set(void *data)
{
	DCL_STATUS status = STATUS_OK;
	DCL_BOOL enable = *(DCL_BOOL*)(data);;

	status = bmt_set_register_value(RG_USBDL_SET_OFFSET,RG_USBDL_SET_MASK,enable<<RG_USBDL_SET_SHIFT);
	
	return status;
}


static DCL_STATUS bmt_set_chr_wdt_clear(void *data)
{
	DCL_STATUS status = STATUS_OK;
	DCL_UINT16 register_value;

	// To reset Charger WDT counter 
	bmt_set_register_value(RG_CHRWDT_WR_OFFSET,RG_CHRWDT_WR_MASK,1<<RG_CHRWDT_WR_SHIFT);
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


static DCL_STATUS (*bmt_bl_charging_func[BMT_BL_CHARGING_CMD_NUMBER])(void *data)=
{
	 bmt_get_chr_det_status
	,bmt_get_the_less_nearest_current
	,bmt_find_and_set_the_nearest_current	
	,bmt_charging_get_cc_status
	,bmt_charging_set_csdac_en
	,bmt_charging_set_chr_en
	,bmt_find_and_set_the_nearest_charger_high_voltage
	,bmt_charging_set_hv_en
	,bmt_charging_set_usbdl_reset
	,bmt_charging_get_baton_status
	,bmt_charging_set_baton_en
	,bmt_charging_set_usbdl_set
	,bmt_set_chr_wdt_clear
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
DCL_STATUS bl_chr_control_handler(BMT_BL_CHARGING_CTRL_CMD cmd, void *data)
{
	DCL_STATUS status;
	if(cmd < BMT_BL_CHARGING_CMD_NUMBER)
		status = bmt_bl_charging_func[cmd](data);
	else
		return STATUS_UNSUPPORTED;

	return status;
}
#endif //#if defiend(__EXT_BOOTLOADER__)
#endif //#if defined( __BMT_2_0_ARCHITECTURE__)
