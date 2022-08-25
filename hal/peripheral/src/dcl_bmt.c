/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  dcl_bmt.c
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *	This Module defines DCL (Driver Common Layer) of the BMT driver.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "drv_features.h"
#include "drvsignals.h"
#include 	"dcl.h"
#include 	"kal_general_types.h"
#include 	"kal_public_api.h"
#include 	"bmt_chr_setting.h"
#include 	"bmt.h"
#include    "init.h"
#if defined(PULSE_LI_CHARGING)  
#include 	"bmt_pulse_li.h"
#elif defined(LINEAR_LI_CHARGING)
#include 	"bmt_linear_li.h"
#endif


#ifdef DCL_BMT_INTERFACE


// ============================================================ //
//define
// ============================================================ //
#define DCL_BMT_DEV_MAGIC_NUM		(0x40000000)


// ============================================================ //
//global variable
// ============================================================ //
kal_uint32 dcl_bmt_handle_count = 0;
#ifdef __BACKUP_DOWNLOAD_RESTORE_WITHOUT_BATTERY__
DCL_HANDLE bmt_without_battery_handle = 0x7F;
#endif


// ============================================================ //
// function prototype
// ============================================================ //


// ============================================================ //
//extern variable
// ============================================================ //
extern void bmt_sendMes2UEM(BMT_CHR_STAT status);


// ============================================================ //
//extern function
// ============================================================ //


// ============================================================ //
#ifdef __BACKUP_DOWNLOAD_RESTORE_WITHOUT_BATTERY__
void bmt_without_battery_callback(void *parameter)
{
	bmt_charging_control_handler(BMT_CHARGING_CMD_WDT_CLEAR,NULL);
	
	{   	  
		SGPT_CTRL_START_T start;	  
		start.u2Tick=200;	  // 2 secs
		start.pfCallback=bmt_without_battery_callback;	  
		start.vPara=NULL;	  
		DclSGPT_Control(bmt_without_battery_handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);		
	}
}
#endif //#ifdef __BACKUP_DOWNLOAD_RESTORE_WITHOUT_BATTERY__


/*************************************************************************
* FUNCTION
*  DclBMT_Initialize
*
* DESCRIPTION
*  This function is to initialize BMT module
*
* PARAMETERS
*  None
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif 
DCL_STATUS DclBMT_Initialize(void)
{
	bmt_initialize();

#ifdef __BACKUP_DOWNLOAD_RESTORE_WITHOUT_BATTERY__
	if (INT_GetSysStaByCmd(CHK_USB_META_WO_BAT, NULL)==KAL_TRUE)
	{
		DCL_HANDLE handle;
		handle = DclBMT_Open(DCL_BMT, FLAGS_NONE);
		DclBMT_Control(handle, BMT_CMD_WDT_INIT, NULL);
		DclBMT_Close(handle);

	}
#endif

	return STATUS_OK;
}

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

/*************************************************************************
* FUNCTION
*  DclBMT_Open
*
* DESCRIPTION
*  This function is to open the BMT module and return a handle
*
* PARAMETERS
*  dev: only valid for DCL_BMT
*  flags: no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*  DCL_HANDLE_INVALID: Open failed
*  Other value: A valid handle
*
*************************************************************************/
DCL_HANDLE DclBMT_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	kal_uint32 handle;

	// Check device type
	if (dev != DCL_BMT){
		ASSERT(0);
		return DCL_HANDLE_INVALID;		// Incorrecr device ID
	}

    dcl_bmt_handle_count = 1;
	handle = (DCL_BMT_DEV_MAGIC_NUM | dcl_bmt_handle_count);	

	return handle;
}


/*************************************************************************
* FUNCTION
*  DclBMT_ReadData
*
* DESCRIPTION
*  This function is not supported for the BMT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclBMT_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options){
	return STATUS_UNSUPPORTED;
}


/*************************************************************************
* FUNCTION
*  DclBMT_WriteData
*
* DESCRIPTION
*  This function is not supported for the BMT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclBMT_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options){
	return STATUS_UNSUPPORTED;
}


/*************************************************************************
* FUNCTION
*  DclBMT_Configure
*
* DESCRIPTION
*  This function is not supported for the BMT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclBMT_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure){
	return STATUS_UNSUPPORTED;
}


/*************************************************************************
* FUNCTION
*  DclBMT_RegisterCallback
*
* DESCRIPTION
*  This function is to set callback function for the BMT module.
*
* PARAMETERS
*  handle: the returned handle value of DclBMT_Open
*  event: Supported events:
*  callback: the callback function for registered events
*
* RETURNS
*  STATUS_OK: Successfully register the callback function.
*  STATUS_INVALID_DCL_HANDLE: It's a invalid handle.
*  STATUS_NOT_OPENED: The module has not been opened.
*  STATUS_INVALID_EVENT: The event parameter is invalid.
*
*************************************************************************/
DCL_STATUS DclBMT_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback){
	return STATUS_UNSUPPORTED;
}


/*************************************************************************
* FUNCTION
*  DclBMT_Close
*
* DESCRIPTION
*  This function is to close the BMT module.
*
* PARAMETERS
*  handle: the returned handle value of DclBMT_Open
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
DCL_STATUS DclBMT_Close(DCL_HANDLE handle)
{
	// Check magic number
	if ((handle & DCL_BMT_DEV_MAGIC_NUM) != DCL_BMT_DEV_MAGIC_NUM){
		ASSERT(0);
		return STATUS_INVALID_DCL_HANDLE;
	}

	// Error check
	if (dcl_bmt_handle_count == 0){
		ASSERT(0);
		return STATUS_NOT_OPENED;
	}

	return STATUS_OK;
}


#if !defined(BMT_CHARGING_DISABLE)
/*************************************************************************
* FUNCTION
*  DclBMT_Control
*
* DESCRIPTION
*  This function is to send command to control the BMT module.
*
* PARAMETERS
*  handle: The handle value returned from DclBMT_Open
*  cmd: A control command for BMT module
*           1. BMT_CMD_CALLSTATE: to nodify talk/idle state to BMT task
*           2. BMT_CMD_SET_EXT_CHARGER: to control the external charger
*           3. BMT_CMD_IS_BAT_ON: to check is battery exist or not
*       	4. BMT_CMD_SENDMES2UEM: to send message from BMT to UEM
*           5. BMT_CMD_SET_CHR_STATUS: to set charger status
*           6. BMT_CMD_VBATINHISR: to save the Battery voltage in HISR
*
*  data: The data of the control command
*           1. BMT_CMD_CALLSTATE: pointer to a BMT_CTRL_CALLSTATE_T structure
*           2. BMT_CMD_SET_EXT_CHARGER: pointer to a BMT_CTRL_SET_EXT_CHARGER_T structure
*           3. BMT_CMD_IS_BAT_ON: pointer to a BMT_CTRL_IS_BAT_ON_T structure
*           4. BMT_CMD_SENDMES2UEM: pointer to a BMT_CTRL_SENDMES2UEM_T structure
*           5. BMT_CMD_SET_CHR_STATUS: pointer to a BMT_CTRL_SET_CHR_STATUS_T structure
*           6. BMT_CMD_VBATINHISR: A null pointer   
*
* RETURNS
*  STATUS_OK: command is executed successfully.
*  STATUS_FAIL: command is failed.
*  STATUS_INVALID_CMD: It's a invalid command.
*
*************************************************************************/
DCL_STATUS DclBMT_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
    DCL_STATUS return_status = STATUS_INVALID_CMD;

	// Check magic number
	if ((handle & DCL_BMT_DEV_MAGIC_NUM) != DCL_BMT_DEV_MAGIC_NUM){
		ASSERT(0);
		return STATUS_INVALID_DCL_HANDLE;
	}

	// Error check
	if (dcl_bmt_handle_count == 0){
		ASSERT(0);
		return STATUS_NOT_OPENED;
	}

	switch (cmd)
	{
#ifdef __BACKUP_DOWNLOAD_RESTORE_WITHOUT_BATTERY__
		case BMT_CMD_WDT_INIT:
		{
			if (bmt_without_battery_handle == 0x7F)
			{
				bmt_without_battery_handle=DclSGPT_Open(DCL_GPT_CB,0);
			}

			{   	  
				SGPT_CTRL_START_T start;	  
				start.u2Tick=200;	  // 2 secs
				start.pfCallback=bmt_without_battery_callback;	  
				start.vPara=NULL;	  
				DclSGPT_Control(bmt_without_battery_handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);		
			}
		}
		break;
#endif //#ifdef __BACKUP_DOWNLOAD_RESTORE_WITHOUT_BATTERY__	
		
	    case BMT_CMD_CALLSTATE:
	    {
			BMT_CTRL_CALLSTATE_T *prCallState;
			prCallState = &(data->rCallState);
			bmt_CallState(prCallState->call_state);            
			return_status = STATUS_OK;
	    }
	    break;
	    
	    case BMT_CMD_CHARGE:
	    {
			BMT_CTRL_CHARGE_T *prChargeControl;
			prChargeControl = &(data->rChargeControl);

#ifdef __BACKUP_DOWNLOAD_RESTORE_WITHOUT_BATTERY__	
			if(INT_GetSysStaByCmd(CHK_USB_META_WO_BAT, NULL)==KAL_TRUE && prChargeControl->bEnable==KAL_FALSE)
			{
				return_status = STATUS_OK;
				break;
			}
#endif 
		    bmt_charging_control_handler(BMT_CHARGING_CMD_CHARGING_ENABLE, &(prChargeControl->bEnable));
	        return_status = STATUS_OK;
	    }
	    break;
	    
	    case BMT_CMD_GET_CUSTOMIZED_PARA:
	    {
	        BMT_CTRL_GET_CUSTOMIZED_PARA_T *prGetCustomizedPara;
	        prGetCustomizedPara = &(data->rGetCustomizedPara);
	        return_status = bmt_get_customized_para(prGetCustomizedPara);            
	    }
	    break;

	    case BMT_CMD_SET_EXT_CHARGER:
	    {
	        return_status = STATUS_UNSUPPORTED;
	    }
	    break;
	            
		case BMT_CMD_INITIALIZE:
		{
			//bmt_initialize();
			return_status = STATUS_OK;
		}
		break;    
	            
	    case BMT_CMD_IS_BAT_ON:
	    {
			BMT_CTRL_IS_BAT_ON_T *prIsBatOn;
			prIsBatOn = &(data->rIsBatOn);
			prIsBatOn->fgBatIsOn = (DCL_BOOLEAN)bmt_is_bat_on();
	        return_status = STATUS_OK;
	    }        
	    break;
	    
		case BMT_CMD_SENDMES2UEM:
		{
			BMT_CTRL_SENDMES2UEM_T  *prSendMes2Uem;
			prSendMes2Uem = &(data->rSendMes2Uem);
			bmt_sendMes2UEM((BMT_CHR_STAT)prSendMes2Uem->ChargerMsg);
			return_status = STATUS_OK;
		}
		break;
		
		case BMT_CMD_SET_CHR_STATUS:
		{
			#if defined(__BMT_INTERNAL_CHARGER_PLUG_STATUS_USE__)	
			BMT_CTRL_SET_CHR_STATUS_T  *prSetChrStatus;
			prSetChrStatus = &(data->rSetChrStatus);
			bmt_set_chr_status(prSetChrStatus->ChargerStat);
			#endif
			
			return_status = STATUS_OK;
		}
		break;  
		      
		case BMT_CMD_VBATINHISR:
		{
			return_status = STATUS_UNSUPPORTED;
		}
		break;

		case BMT_CMD_GET_EVENT_SCHEDULE_TIMER_INDEX:
		{
			BMT_CTRL_GET_EVENT_SCHEDULER_TIMER_INDEX *prEventScheduler;

			prEventScheduler = &(data->rEventScheduler);
			prEventScheduler->timer_index = bmt_get_event_scheduler_timer_index(prEventScheduler->id);

			return_status = STATUS_OK;
		}
		break;

		case BMT_CMD_SET_ADC_MEASURE_ENABLE:
		{
			BMT_CTRL_SET_ADC_ENABLE *prSetADCBits;

			prSetADCBits = &(data->rSetAdc);
			bmt_charging_control_handler(BMT_CHARGING_CMD_SET_ADC, &(prSetADCBits->AdcEnableBits));
	        return_status = STATUS_OK;
		}
		break;

		case BMT_CMD_SET_CHR_EFUSE_TRIMMING_DATA:
		{
			BMT_CTRL_SET_CHR_TRIMMING_DATA *prSetTrimmingData;
			prSetTrimmingData = &(data->rSetTrimmingData);
			bmt_set_chr_trimming_data(prSetTrimmingData);
			return_status = STATUS_OK;
		}
		break;
		

		case  BMT_CMD_GET_CHARGING_CURRENT:
		{
			DCL_UINT32 TransformVolt;	
			BMT_CTRL_GET_CHARGING_CURRENT *prGetChargingCurrent;

			prGetChargingCurrent = &(data->rGetChrCurrent);
			TransformVolt = prGetChargingCurrent->VSense - prGetChargingCurrent->VBat - get_ISense_Offset();
			return bmt_change_Voltage_To_ISense(TransformVolt);
		}
		
		case  BMT_CMD_GET_VBATTMP:
		{
			BMT_CTRL_GET_BAT_TEMP *prGetVBatTemp;

			prGetVBatTemp = &(data->rGetBatTemp);
			return bmt_change_VBatTmp_To_BatTmp(prGetVBatTemp->VBatTmp);
		}

		#ifdef __DRV_BMT_HIGH_BATTERY_SUPPORT__
		case BMT_CMD_SET_BATTERY_HV_DATA:
		{
			BMT_CTRL_SET_HIGH_BATTERY_DATA *prSetHighBatteryData;
			prSetHighBatteryData = &(data->rSetHighBatteryData);
			bmt_set_high_battery_cv(prSetHighBatteryData);
			return_status = STATUS_OK;
		}
		break;
		#endif
		
		default:
			return_status = STATUS_INVALID_CMD;
		break;
		}
	    return return_status;
}

#else /*!defined(DRV_BMT_OFF)*/



DCL_STATUS DclBMT_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	DCL_STATUS return_status = STATUS_INVALID_CMD;

	// Check magic number
	if ((handle & DCL_BMT_DEV_MAGIC_NUM) != DCL_BMT_DEV_MAGIC_NUM){
		ASSERT(0);
		return STATUS_INVALID_DCL_HANDLE;
	}

	// Error check
	if (dcl_bmt_handle_count == 0){
		ASSERT(0);
		return STATUS_NOT_OPENED;
	}

	switch (cmd)
	{

		case BMT_CMD_WDT_INIT:
		{
			 return_status = STATUS_UNSUPPORTED;
		}
		break;

		
	    case BMT_CMD_CALLSTATE:
	    {
			 return_status = STATUS_UNSUPPORTED;
	    }
	    break;
	    
	    case BMT_CMD_CHARGE:
	    {
			 return_status = STATUS_UNSUPPORTED;
	    }
	    break;
	    
	    case BMT_CMD_GET_CUSTOMIZED_PARA:
	    {
	         return_status = STATUS_UNSUPPORTED;       
	    }
	    break;

	    case BMT_CMD_SET_EXT_CHARGER:
	    {
	        return_status = STATUS_UNSUPPORTED;
	    }
	    break;
	            
		case BMT_CMD_INITIALIZE:
		{
			return_status = STATUS_OK;
		}
		break;        
	            
	    case BMT_CMD_IS_BAT_ON:
	    {
			BMT_CTRL_IS_BAT_ON_T *prIsBatOn;
			prIsBatOn = &(data->rIsBatOn);
			prIsBatOn->fgBatIsOn = (DCL_BOOLEAN)bmt_is_bat_on();
	        return_status = STATUS_OK;
	    }        
	    break;
	    
		case BMT_CMD_SENDMES2UEM:
		{
			BMT_CTRL_SENDMES2UEM_T  *prSendMes2Uem;
			prSendMes2Uem = &(data->rSendMes2Uem);
			bmt_sendMes2UEM((BMT_CHR_STAT)prSendMes2Uem->ChargerMsg);
			return_status = STATUS_OK;
		}
		break;
		
		case BMT_CMD_SET_CHR_STATUS:
		{
			 return_status = STATUS_UNSUPPORTED;
		}
		break;  
		      
		case BMT_CMD_VBATINHISR:
		{
			return_status = STATUS_UNSUPPORTED;
		}
		break;

		case BMT_CMD_GET_EVENT_SCHEDULE_TIMER_INDEX:
		{
			BMT_CTRL_GET_EVENT_SCHEDULER_TIMER_INDEX *prEventScheduler;

			prEventScheduler = &(data->rEventScheduler);
			prEventScheduler->timer_index = bmt_get_event_scheduler_timer_index(prEventScheduler->id);

			return_status = STATUS_OK;
		}
		break;
		
		case BMT_CMD_SET_ADC_MEASURE_ENABLE:
		{
			BMT_CTRL_SET_ADC_ENABLE *prSetADCBits;

			prSetADCBits = &(data->rSetAdc);
			bmt_charging_control_handler(BMT_CHARGING_CMD_SET_ADC, &(prSetADCBits->AdcEnableBits));
	        return_status = STATUS_OK;
		}
		break;

		case  BMT_CMD_GET_CHARGING_CURRENT:
		{
			DCL_UINT32 TransformVolt;	
			BMT_CTRL_GET_CHARGING_CURRENT *prGetChargingCurrent;

			prGetChargingCurrent = &(data->rGetChrCurrent);
			TransformVolt = prGetChargingCurrent->VSense - prGetChargingCurrent->VBat;
			return bmt_change_Voltage_To_ISense(TransformVolt);
		}

		case  BMT_CMD_GET_VBATTMP:
		{
			BMT_CTRL_GET_BAT_TEMP *prGetVBatTemp;

			prGetVBatTemp = &(data->rGetBatTemp);
			return bmt_change_VBatTmp_To_BatTmp(prGetVBatTemp->VBatTmp);
		}

		default:
			return_status = STATUS_INVALID_CMD;
		break;
		}
	    return return_status;
}

#endif /*!defined(DRV_BMT_OFF)*/

#endif //#ifdef DCL_BMT_INTERFACE

