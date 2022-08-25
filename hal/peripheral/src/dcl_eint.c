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
 *    dcl_eint.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines DCL (Driver Common Layer) of the EINT driver.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include "dcl.h"
#include "drv_hisr.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "l1_interface.h"
#include "drv_trc.h"
#include "stack_ltlcom.h"  
#include "stack_common.h"
#include "stack_msgs.h"
#include "Eint_internal.h"
#include "kal_internal_api.h"
#if defined (__EINT_DIE2DIE__)
#include "ADIE_eint.h"
#endif
#include "eint.h"


/*============================================================*/
//  Part0 : extern global data for DCL Common layer
/*============================================================*/

extern DEV_Operations eint_dev_operations = {
						DclEINT_Open,
						NULL,
						NULL,
						DclEINT_Control,
						DclEINT_RegisterCallback,
						NULL,
						DclEINT_Close};/* add for dcl common layer */
extern DEV_Utility eint_dev_query = {DclEINT_QueryHandleWithMSG};


extern DCL_EVENT_MSG_PAIR eint_event_msg_pairs[]={
	{EVENT_EINT_TRIGGER,MSG_ID_EINT_TRIGGER_IND},
	};
	
extern DCL_EVENT_MSG_MAP eint_event_msg_map={
sizeof(eint_event_msg_pairs)/sizeof(DCL_EVENT_MSG_PAIR), eint_event_msg_pairs};


/*============================================================*/
//  PartI : global data area definition.
/*============================================================*/
/* We use this #if to help remind the owner, EINT_ALL_NNMBER may exceeds 64 */
#if (EINT_ALL_NUMBER > 63)
  #error "Number of EINT exceeds 64 bits. Be sure to extend the eint_dcl_use_status and eint_native_use_status."
#endif

extern volatile kal_uint64   eint_dcl_use_status = 0; // when call dcl interface, we update this variable.
extern volatile kal_uint64   eint_native_use_status = 0; // when call EINT_Registration directly(native user),we update this variable.
extern eint_func_t  EINT_FUNC[EINT_ALL_NUMBER];    // this is defined in eint.c


/*============================================================*/
//  PartII : macro area definition.
/*============================================================*/
#define DCL_EINT_MAGIC_NUM         0x02000000  //  magic number definition. 


/*============================================================*/
//  PartIII : function area definition.
/*============================================================*/
extern void eint_mre_cb(kal_uint8 eint_no); // This callback is used to send message to MMI for MRE callback.
static DCL_STATUS eint_check_parameter(DCL_HANDLE handle);

/*============================================================*/
//  PartIV : typedef area definition.
/*============================================================*/
/* This struct defines the eint message parameters. */
typedef struct {
	LOCAL_PARA_HDR
	kal_uint8   eint_no;
} eint_id_struct;
/*============================================================*/








/*============================================================*/
//  PartV : Function definition and implemention.
/*============================================================*/



/*------------------------------------------------------------------------
* FUNCTION
*  DclEINT_Open
*
* DESCRIPTION
*  This function is to get a handle of EINT module. The handle will be used in later control functions.
*
* PARAMETERS
*  dev  - the device of DCL EINT, always use DCL_EINT.
*  flags - the eint number       
*          
* RETURNS
*	DCL_HANDLE_INVALID - a invalid handle.
*	DCL_HANDLE_OCCUPIED - a invalid handle, means this eint is opened by others.
*     handle - a valid handle.
*
*-----------------------------------------------------------------------*/

DCL_HANDLE DclEINT_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	DCL_HANDLE handle;
	kal_uint32 savedMask;
	/*------------------------------*/
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
	#endif
	/*-----------------------------*/
	if((DCL_EINT != dev) || (flags >= EINT_ALL_NUMBER))
	{
		ASSERT(0);
		return DCL_HANDLE_INVALID; 
	}
	savedMask = SaveAndSetIRQMask();
	if(CHECK_DCL_USE_STA(flags) || CHECK_NATIVE_USE_STA(flags))
	{
		RestoreIRQMask(savedMask);
		return DCL_HANDLE_OCCUPIED;
	}
	EINT_SET_DCL_USE_STA(flags);
	RestoreIRQMask(savedMask);
	handle = flags | DCL_EINT_MAGIC_NUM;

	return handle;
}


/*------------------------------------------------------------------------
* FUNCTION
*  DclEINT_RegisterCallback
*
* DESCRIPTION
*  This function is to register a callback function. it will be called in hisr. Notice,if the caller
*  is MRE user, we will send messages instead of call it'a callback directly
*
* PARAMETERS
*  handle  - invalid handle returned by DclEINT_Open.
*  event    - the EINT event, we not use this parameter now.  
*  callback - the user callback
*  parameter - the user parameter. Note: we do not support callback with parameter. user should give a NULL.
*  user_id   - this parameter express the user id. MRE user or Native user.
*          
* RETURNS
*	STATUS_OK                             - register OK.
*	STATUS_INVALID_ARGUMENT     - eint number exceed EINT_ALL_NUMBER.
*     STATUS_NOT_OPENED               - this eint is not opend by DclEINT_Open.
*     STATUS_INVALID_DCL_HANDLE   - invalid eint handle.
*
*-----------------------------------------------------------------------*/


DCL_STATUS DclEINT_RegisterCallback(
	             DCL_HANDLE handle,
	             DCL_EVENT event,
	             DCL_CALLBACK callback,
	             void * parameter,
	             DCL_USER_ID user_id)

{
	kal_uint8 eint_no;
	kal_uint32 savedMask;
	DCL_STATUS ret_status;

	/*-----------------------------------*/
	// temp log
	//kal_prompt_trace(MOD_DRVKBD, "$$$ enter RegisterCallback:handle %x,event %x,callback %x user_id %x", handle,event,callback,user_id);
	/*-----------------------------------*/
	if(STATUS_OK != (ret_status = eint_check_parameter(handle)))
	{
		ASSERT(0);
		return ret_status;
	}
	eint_no = handle & DCL_VALID_EINT_NUM_MASK;
	
	if(DCL_USER_MRE == user_id)
	{
		EINT_FUNC[eint_no].eint_func = eint_mre_cb;
	}
	else
	{
		EINT_FUNC[eint_no].eint_func = callback;
	}

	return STATUS_OK;
}


/*------------------------------------------------------------------------
* FUNCTION
*  DclEINT_Control
*
* DESCRIPTION
*  This function is to control the EINT.
*
* PARAMETERS
*  handle  - invalid handle returned by DclEINT_Open.
*  cmd    - the EINT CMD, see details in dcl_eint.h.  
*  data   - the parameter of different cammand.
*          
* RETURNS
*	STATUS_OK                             - register OK.
*	STATUS_INVALID_ARGUMENT     - eint number exceed EINT_ALL_NUMBER.
*     STATUS_NOT_OPENED               - this eint is not opend by DclEINT_Open.
*     STATUS_INVALID_DCL_HANDLE   - invalid eint handle.
*     STATUS_INVALID_CMD              -  invalid EINT CMD.
*
*-----------------------------------------------------------------------*/

DCL_STATUS DclEINT_Control(DCL_HANDLE handle,DCL_CTRL_CMD cmd,void * data)
{
	kal_uint8 eint_no;
	DCL_STATUS ret_status;
	if(STATUS_OK != (ret_status = eint_check_parameter(handle)))
	{
		ASSERT(0);
		return ret_status;
	}
	eint_no = handle & DCL_VALID_EINT_NUM_MASK;
	/*----------------------------------------------------------------------*/
	// temp log
	//kal_prompt_trace(MOD_DRVKBD, "$$$ enter Control:handle %x,cmd %x", handle,cmd);
	/*----------------------------------------------------------------------*/
	switch(cmd)
	{
		case EINT_CMD_CONFIG:
		{
			EINT_CTRL_CONFIG_T *rConfig;
			rConfig = (EINT_CTRL_CONFIG_T *)data;
			eint_no |= DCL_EINT_FLAG_MASK;
			/*----------------------------------------------------------------------*/
			// temp log
			//kal_prompt_trace(MOD_DRVKBD, "$$$ enter cmd :CONFIG--debounce_en %d,polarity %d, unmask %d", rConfig->debounce_en,rConfig->act_polarity,rConfig->auto_unmask);
			/*----------------------------------------------------------------------*/
			if( (rConfig->act_polarity > 1) ||
			    (rConfig->auto_unmask > 1) ||
			    (rConfig->debounce_en > 1))
			{
				ASSERT(0);
				return STATUS_INVALID_ARGUMENT;
			}
			/*------------------------------------------------
			* Note: driver owner take this note. we call below function 
			* just for take advantage of the local API(EINT_Registration).
			* The fourth parameter we fill NULL, beacaue user should register
			* the callback function with DclEINT_RegisterCallback.
			*------------------------------------------------*/
			EINT_Registration(eint_no,rConfig->debounce_en,rConfig->act_polarity,NULL,rConfig->auto_unmask);
			return STATUS_OK;
		}
		case EINT_CMD_SET_HW_DEBOUNCE:
		{
			EINT_CTRL_SET_HW_DEBOUNCE_T *rDebounceData;
			rDebounceData = (EINT_CTRL_SET_HW_DEBOUNCE_T *)data;
			/*----------------------------------------------------------------------*/
			// temp log
			//kal_prompt_trace(MOD_DRVKBD, "$$$ enter cmd :SET_HW_DEBOUNCE-- %d",rDebounceData->debounce_time);
			/*----------------------------------------------------------------------*/
			EINT_Set_HW_Debounce(eint_no,rDebounceData->debounce_time);
			return STATUS_OK;
		}
		case EINT_CMD_SET_POLARITY:
		{
			EINT_CTRL_SET_POLARITY_T *rPolarityData;
			rPolarityData = (EINT_CTRL_SET_POLARITY_T *)data;
			/*----------------------------------------------------------------------*/
			// temp log
			//kal_prompt_trace(MOD_DRVKBD, "$$$ enter cmd :SET_POLARITY-- %d",rPolarityData->ACT_Polarity);
			/*----------------------------------------------------------------------*/
			if(rPolarityData->ACT_Polarity > 1)
			{
				ASSERT(0);
				return STATUS_INVALID_ARGUMENT;
			}
			EINT_Set_Polarity(eint_no,rPolarityData->ACT_Polarity);
			return STATUS_OK;
		}
		case EINT_CMD_SET_SENSITIVITY:
		{
			EINT_CTRL_SET_SENSITIVITY_T *rSensData;
			rSensData = (EINT_CTRL_SET_SENSITIVITY_T*)data;
			/*----------------------------------------------------------------------*/
			// temp log
			//kal_prompt_trace(MOD_DRVKBD, "$$$ enter cmd :SET_SENSITIVITY-- %d",rSensData->sensitivity);
			/*----------------------------------------------------------------------*/
			if(1 == rSensData->sensitivity)
			{
				rSensData->sensitivity = 0;
			}
			else if(0 == rSensData->sensitivity)
			{
				rSensData->sensitivity = 1;
			}
			else
			{
				ASSERT(0);
				return STATUS_INVALID_ARGUMENT;
			}
			EINT_Set_Sensitivity(eint_no,rSensData->sensitivity);
			return STATUS_OK;
		}
		case EINT_CMD_MASK:
		{
			/*----------------------------------------------------------------------*/
			// temp log
			//kal_prompt_trace(MOD_DRVKBD, "$$$ enter cmd: MASK");
			/*----------------------------------------------------------------------*/
			EINT_Mask(eint_no);
			return STATUS_OK;
		}
		case EINT_CMD_UNMASK:
		{
			/*----------------------------------------------------------------------*/
			// temp log
			//kal_prompt_trace(MOD_DRVKBD, "$$$ enter cmd: UNMASK");
			/*----------------------------------------------------------------------*/
			EINT_UnMask(eint_no);
			return STATUS_OK;
		}
		default:
		{
			ASSERT(0);
      		return STATUS_INVALID_CMD;
		}
	}
}


/*------------------------------------------------------------------------
* FUNCTION
*  DclEINT_Close
*
* DESCRIPTION
*  This function is to close the EINT opened by DclEINT_Open.
*
* PARAMETERS
*  handle  - invalid handle returned by DclEINT_Open.
*          
* RETURNS
*	STATUS_OK                             - register OK.
*	STATUS_INVALID_ARGUMENT     - eint number exceed EINT_ALL_NUMBER.
*     STATUS_INVALID_DCL_HANDLE   - invalid eint handle.
*
*-----------------------------------------------------------------------*/

DCL_STATUS DclEINT_Close(DCL_HANDLE handle)
{
	kal_uint8 eint_no;
	kal_uint32 savedMask;
	DCL_STATUS ret_status;
	/*-------------------------------------------*/
	// temp log
	//kal_prompt_trace(MOD_DRVKBD, "$$$ enter Close :handle %x", handle);
	/*-------------------------------------------*/
	if(STATUS_OK != (ret_status = eint_check_parameter(handle))) /*????????? if close twice,should we assert it ??????????*/
	{
		if(STATUS_NOT_OPENED == ret_status)
		{
			return STATUS_OK; // we allow to close twice.
		}
		else
		{
			ASSERT(0);
			return ret_status;
		}
	}
	eint_no = handle & DCL_VALID_EINT_NUM_MASK;
	EINT_Mask(eint_no); //mask this eint
	EINT_FUNC[eint_no].eint_func = NULL;//clear the callback function

	savedMask = SaveAndSetIRQMask();
	EINT_CLR_DCL_USE_STA(eint_no); //Finally do this step,other user can not use this eint until this step finied
	RestoreIRQMask(savedMask);
	return STATUS_OK;
	
}


/*------------------------------------------------------------------------
* FUNCTION
*  eint_check_parameter
*
* DESCRIPTION
*  This is a local function used to check the pamramters.
*
* PARAMETERS
*  handle  - invalid handle returned by DclEINT_Open.
*          
* RETURNS
*	STATUS_OK                             - parameter check OK.
*	STATUS_INVALID_ARGUMENT     - eint number exceed EINT_ALL_NUMBER.
*     STATUS_INVALID_DCL_HANDLE   - invalid eint handle.
*     STATUS_NOT_OPENED               - this eint has not been opened.
*
*-----------------------------------------------------------------------*/

DCL_STATUS eint_check_parameter(DCL_HANDLE handle)
{
	
	kal_uint8 eint_no;
	eint_no = handle & DCL_VALID_EINT_NUM_MASK;
	if(!(handle & DCL_EINT_MAGIC_NUM))
	{
		//ASSERT(0);
		return STATUS_INVALID_DCL_HANDLE;
	}
    if(eint_no >= EINT_ALL_NUMBER)
	{
		//ASSERT(0);
		return STATUS_INVALID_ARGUMENT;
	}
	if(0 == CHECK_DCL_USE_STA(eint_no))
	{
		//ASSERT(0);
		return STATUS_NOT_OPENED;
	}

	return STATUS_OK;

}


/*------------------------------------------------------------------------
* FUNCTION
*  eint_mre_cb
*
* DESCRIPTION
*  This function is only used for MRE callback. In this function, we send message to MMI.
*  and the MMI will handle this message to help to call MRE user's callback function.
*
* PARAMETERS
*  eint_no  - means which eint is triggered.
*          
* RETURNS
*  NONE
*
*-----------------------------------------------------------------------*/
void eint_mre_cb(kal_uint8 eint_no)
{

	ilm_struct  *eint_ilm;
	eint_id_struct	*eint_id_data;
	DCL_INT32 dst_modid;

/*-----------------------------------*/
// temp log
	//kal_prompt_trace(MOD_DRVKBD, "$$$ enter cb:eint_no %d",eint_no);
/*-----------------------------------*/

	dst_modid = DCL_GetDestinationID(DCL_USER_DRV_GENERAL);

	eint_id_data = (eint_id_struct*) construct_local_para(sizeof(eint_id_struct), TD_CTRL);	
	eint_id_data->eint_no= eint_no;
	
	DRV_BuildPrimitive(
		       eint_ilm,
			   MOD_DRV_HISR,
			   dst_modid,
			   MSG_ID_EINT_TRIGGER_IND,
			   eint_id_data);
	
	msg_send_ext_queue(eint_ilm);
	

}


/*------------------------------------------------------------------------
* FUNCTION
*  DclEINT_QueryHandleWithMSG
*
* DESCRIPTION
*  This function is called by DCL function when MMI recieved the message and call DCL
*  callback. This function will return the handle use the message parameters.
*
* PARAMETERS
*  msg_id  - the message id of EINT, now, we not use this parameter.
*  ilm       -  the message sent by eint_mre_cb.
*          
* RETURNS
*  dev_handle - valid handle of triggered EINT
*  STATUS_OK - return success.
*
*-----------------------------------------------------------------------*/
DCL_STATUS DclEINT_QueryHandleWithMSG(
					msg_type  		msg_id,	
					ilm_struct*		ilm,
					DCL_HANDLE*   	dev_handle)
{
	*dev_handle = (((eint_id_struct *)(ilm->local_para_ptr))->eint_no) | DCL_EINT_MAGIC_NUM;
	return STATUS_OK;
}

