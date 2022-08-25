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
 *    dcl_accdet.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines DCL (Driver Common Layer) of the Accdet driver.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include    "drv_comm.h"
#if (defined(__ACCDET_SUPPORT__)||defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__))
#include    "accdet_sw.h"
#endif
#include    "dcl.h"

#include "kal_general_types.h"
#include "kal_public_api.h"


/*
* Global variable
*/

#ifndef __L1_STANDALONE__

#if defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)
extern void aux_Audio_Closed_Handler(void);
extern void aux_Audio_Open_Handler(void);
#endif //#if defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)

#if (defined(__ACCDET_SUPPORT__)||defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__))
extern AccDet_config_data_struct *AccDet_Get_Data(void);
extern void AccDet_Set_Data(AccDet_config_data_struct* data);
#endif //#if (defined(__ACCDET_SUPPORT__)||defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__))

#define DCL_AUX_DEV_MAGIC_NUM  0x20000000
#define MAX_DCL_AUX_HANDLE 10
#define INVALID_AUX_SCHE_ID			(0xFF)
#define IN_USE_AUX_SCHE_ID			(0xFE)

kal_uint8 dcl_aux_handle_count = 0;		// A counter to record opened handles
kal_uint8 dcl_aux_handle[MAX_DCL_AUX_HANDLE];


/*************************************************************************
* FUNCTION
*  DclAUX_Initialize
*
* DESCRIPTION
*  This function is to initialize AUX module
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
DCL_STATUS DclAUX_Initialize(void)
{
	kal_uint8 i;
	for (i=0;i<MAX_DCL_AUX_HANDLE;i++)
	{
		dcl_aux_handle[i] = INVALID_AUX_SCHE_ID;
	}
	#if (defined(__ACCDET_SUPPORT__)||defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__))
	{
		extern void AFE_Mic_Init_Set(void);
		AFE_Mic_Init_Set();
		}
	ACCDET_init();
	#endif
	
	return STATUS_OK;
}

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

/*************************************************************************
* FUNCTION
*  DclAUX_Open
*
* DESCRIPTION
*  This function is to open the AUX module and return a handle
*  Note that multiple opens are prohibited.
*
* PARAMETERS
*  dev: only valid for DCL_AUX
*  flags: no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*  DCL_HANDLE_INVALID: Open failed
*  Other value: A valid handle
*
*************************************************************************/
DCL_HANDLE DclAUX_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	DCL_HANDLE handle_tmp;
	kal_uint32 savedMask;
	kal_uint8 i;
	
	if (dev != DCL_AUX)
	{
		ASSERT(0);
		return DCL_HANDLE_INVALID;		// Incorrecr device ID
	}
	if (dcl_aux_handle_count >= MAX_DCL_AUX_HANDLE)
	{
		ASSERT(0);
		return DCL_HANDLE_INVALID;		// Too many opened handles
	}
	for (i=0;i<MAX_DCL_AUX_HANDLE;i++)
	{
		if (dcl_aux_handle[i] == INVALID_AUX_SCHE_ID)
		{
			savedMask = SaveAndSetIRQMask();
			dcl_aux_handle_count++;
			dcl_aux_handle[i] = IN_USE_AUX_SCHE_ID;
			handle_tmp = (DCL_AUX_DEV_MAGIC_NUM | i);
			RestoreIRQMask(savedMask);
			return handle_tmp;
		}
	}
	return DCL_HANDLE_INVALID;
}

/*************************************************************************
* FUNCTION
*  DclAUX_ReadData
*
* DESCRIPTION
*  This function is not supported for the AUX module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclAUX_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

/*************************************************************************
* FUNCTION
*  DclAUX_WriteData
*
* DESCRIPTION
*  This function is not supported for the AUX module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclAUX_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

/*************************************************************************
* FUNCTION
*  DclAUX_Configure
*
* DESCRIPTION
*  This function is not supported for the AUX module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclAUX_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	return STATUS_UNSUPPORTED;
}
/*************************************************************************
* FUNCTION
*  DclAUX_RegisterCallback
*
* DESCRIPTION
*  This function is not supported for the AUX module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclAUX_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
	return STATUS_UNSUPPORTED;
}
/*************************************************************************
* FUNCTION
*  DclSAUX_Control
*
* DESCRIPTION
*  This function is to send command to control the AUX module.
*
* PARAMETERS
*  handle: The handle value returned from DclSAUX_Open
*  cmd: A control command for AUX module
*          1. AUX_CMD_GET_ACCDET_CONFIG_DATA_DEFINE: to get ACCDET config data
*          2. AUX_CMD_SET_AUDIO_OPEN: to set the flag to indicate audio open
*          3. AUX_CMD_SET_AUDIO_CLOSED: to set the flag to indicate audio closed
*  data: The data of the control command
*          1. AUX_CMD_GET_ACCDET_CONFIG_DATA_DEFINE: pointer to a AUX_CTRL_ACCDET_CONFIG_DATA_DEFINE_T structure
*          2. AUX_CMD_SET_AUDIO_OPEN: pointer to a AUX_CTRL_SET_AUDIO_OPEN_T structure
*          3. AUX_CMD_SET_AUDIO_CLOSED: pointer to a AUX_CTRL_SET_AUDIO_CLOSED_T structure
*
* RETURNS
*  STATUS_OK: command is executed successfully.
*  STATUS_FAIL: command is failed.
*  STATUS_INVALID_CMD: It's a invalid command.
*  
*************************************************************************/
DCL_STATUS DclAUX_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	if (DCL_AUX_DEV_MAGIC_NUM != (handle & DCL_AUX_DEV_MAGIC_NUM))
	{
		ASSERT(0);
		return STATUS_INVALID_DCL_HANDLE;
	}
	if(dcl_aux_handle[(handle & ~DCL_AUX_DEV_MAGIC_NUM) & 0xff] == INVALID_AUX_SCHE_ID)
	{
		ASSERT(0);
		return STATUS_NOT_OPENED;
	}
	switch (cmd)
	{
		case AUX_CMD_GET_ACCDET_CONFIG_DATA_DEFINE:
		{
			#if (defined(__ACCDET_SUPPORT__)||defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__))
			AUX_CTRL_GET_ACCDET_CONFIG_DATA_T *prGetAccdetConfigData;
			prGetAccdetConfigData = &(data->rGetAccdetConfigData);
			if (NULL == prGetAccdetConfigData)
			{
				ASSERT(0);
				return STATUS_INVALID_CTRL_DATA; 
			}
			
			prGetAccdetConfigData->rAccdetConfigData = (AUX_ACCDET_CONFIG_DATA_DEFINE_T*)AccDet_Get_Data();
			return STATUS_OK;
			#else //(defined(__ACCDET_SUPPORT__)||defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__))
			ASSERT(0);
			return STATUS_INVALID_CMD;
			#endif //(defined(__ACCDET_SUPPORT__)||defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__))
		}
		//break;
		case AUX_CMD_SET_ACCDET_CONFIG_DATA_DEFINE:
		{
			#if (defined(__ACCDET_SUPPORT__)||defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__))
			AUX_CTRL_SET_ACCDET_CONFIG_DATA_T *prSetAccdetConfigData;
			AccDet_config_data_struct config;
			prSetAccdetConfigData = &(data->rSetAccdetConfigData);

			config.hook_debounce = prSetAccdetConfigData->rAccdetConfigData->u4HookDebounce;
			config.mic_debounce = prSetAccdetConfigData->rAccdetConfigData->u4MicDebounce;
			config.plugOut_debounce = prSetAccdetConfigData->rAccdetConfigData->u4PlugoutDebounce;
			config.pwm_delay = prSetAccdetConfigData->rAccdetConfigData->u4PwmDelay;
			config.cmp_width = prSetAccdetConfigData->rAccdetConfigData->u4CmpWidth;
			config.cmp_threshold = prSetAccdetConfigData->rAccdetConfigData->u4CmpThreshold;
			config.vth_width = prSetAccdetConfigData->rAccdetConfigData->u4VthWidth;
			config.vth_threshold = prSetAccdetConfigData->rAccdetConfigData->u4VthThreshold;
			config.mbias_width = prSetAccdetConfigData->rAccdetConfigData->u4MbiasWidth;
			config.mbias_threshold = prSetAccdetConfigData->rAccdetConfigData->u4MbiasThreshold;

			AccDet_Set_Data(&config);
			return STATUS_OK;
			#else //(defined(__ACCDET_SUPPORT__)||defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__))
			ASSERT(0);
			return STATUS_INVALID_CMD;
			#endif //(defined(__ACCDET_SUPPORT__)||defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__))
		}
		//break;
		case AUX_CMD_SET_AUDIO_STATUS:
		{
			#if defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)
			AUX_CTRL_SET_AUDIO_STATUS_T *prSetAudioStatus;
			prSetAudioStatus = &(data->rSetAudioStatus);
			if (prSetAudioStatus->eAudioStatus == DCL_AUX_AUDIO_STATUS_OPEN)
			{
				aux_Audio_Open_Handler();
			}
			else if (prSetAudioStatus->eAudioStatus == DCL_AUX_AUDIO_STATUS_CLOSED)
			{
				aux_Audio_Closed_Handler();
			}
			else
			{
				ASSERT(0);
				return STATUS_INVALID_CMD;
			}
			return STATUS_OK;
			#else //defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)
			ASSERT(0);
			return STATUS_INVALID_CMD;
			#endif //defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)
		}
		//break;
		default:
			return STATUS_INVALID_CMD;
		//break;
	}
	//return STATUS_FAIL;
}

/*************************************************************************
* FUNCTION
*  DclAUX_Close
*
* DESCRIPTION
*  This function is to close the AUX module.
*
* PARAMETERS
*  handle: the returned handle value of DclAUX_Open
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
DCL_STATUS DclAUX_Close(DCL_HANDLE handle)
{
	if (DCL_AUX_DEV_MAGIC_NUM != (handle & DCL_AUX_DEV_MAGIC_NUM))
	{
		ASSERT(0);
		return STATUS_INVALID_DCL_HANDLE;
	}
	if(dcl_aux_handle[(handle & ~DCL_AUX_DEV_MAGIC_NUM) & 0xff] == INVALID_AUX_SCHE_ID)
	{
		ASSERT(0);
		return STATUS_NOT_OPENED;
	}
	dcl_aux_handle[(handle & ~DCL_AUX_DEV_MAGIC_NUM) & 0xff] = INVALID_AUX_SCHE_ID;
        dcl_aux_handle_count--;
	return STATUS_OK;
}

#else
DCL_STATUS DclAUX_Initialize(void)
{return  STATUS_OK;}
DCL_HANDLE DclAUX_Open(DCL_DEV dev, DCL_FLAGS flags)
{return STATUS_OK;}

DCL_STATUS DclAUX_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}
DCL_STATUS DclAUX_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}
DCL_STATUS DclAUX_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	return STATUS_UNSUPPORTED;
}
DCL_STATUS DclAUX_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclAUX_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{return STATUS_UNSUPPORTED;}

DCL_STATUS DclAUX_Close(DCL_HANDLE handle)
 {return STATUS_UNSUPPORTED;}   

#endif

