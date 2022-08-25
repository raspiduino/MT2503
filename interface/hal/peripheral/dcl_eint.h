/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2013
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   dcl_eint.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of DCL (Driver Common Layer) for EINT.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*==========================================================================*/
// part I definition
/*==========================================================================*/

#ifdef DCL_DEFINITION_STRUCT
#ifndef __DCL_EINT_H_STRUCT__
#define __DCL_EINT_H_STRUCT__
#include "kal_non_specific_general_types.h"
#include "kal_release.h"
 


/*===========================================================*/
//  DCL_OPTIONS for EINT
/*===========================================================*/

#define EINT_OPTIONS
 
 
/*===========================================================*/
//  DCL_EVENT
/*===========================================================*/
#define EINT_EVENTS   EVENT_EINT_TRIGGER = EINT_EVENTS_START,
 
/*===========================================================*/
// DCL_CTRL_CMD
/*===========================================================*/


/* The EINT Command values in DCL_CTRL_CMD_T Enum of dcl.h DCL_CTRL_DATA_T Define the Control data structure for each module's command */
/*------------------------------------------------------------
*  EINT_CMD_CONFIG - config the eint. debounce, activity, auto unmask.
*  EINT_CMD_SET_HW_DEBOUNCE - set hw doucne time, the unit is ms.
*  EINT_CMD_SET_POLARITY - set active polarity.
*  EINT_CMD_SET_SENSITIVYTY - set active senseivity.
*  EINT_CMD_MASK  - mask the eint.
*  EINT_CMD_UNMASK - unmask the eint.
*------------------------------------------------------------*/
#define EINT_CMDS  \
	EINT_CMD_CONFIG,  \
	EINT_CMD_SET_HW_DEBOUNCE, \
	EINT_CMD_SET_POLARITY, \
	EINT_CMD_SET_SENSITIVITY, \
	EINT_CMD_MASK, \
	EINT_CMD_UNMASK, 

/*===========================================================*/
// structure definition
/*===========================================================*/


 /* For EINT_CMD_CONFIG command. */
typedef struct
{
	kal_uint8	 debounce_en; // The value is 1 or 0. 1 means enable hw debounce, 0 means disable 
	kal_uint8	 act_polarity; // The value is 1 0r 0. 1 means positive active, 0 means negative active.
	kal_uint8	 auto_unmask; // The value is 1 or 0. 1 means unmask after callback, 0 means not unmask. user unmask it themselves.
} EINT_CTRL_CONFIG_T;
 
 /* For EINT_CMD_SET_HW_DEBOUNCE command. */
typedef struct
{
 	kal_uint32	  debounce_time;// HW debounce time. the unit is ms.
} EINT_CTRL_SET_HW_DEBOUNCE_T;

 /* For EINT_CMD_SET_POLARITY command. */
typedef struct
{
 	kal_uint8 ACT_Polarity; // The value is 1 0r 0. 1 means positive active, 0 means negative active.
} EINT_CTRL_SET_POLARITY_T;

 /* For EINT_CMD_SET_SENSITIVITY command. */
typedef struct
{
 	kal_uint8 sensitivity;// The value is 1 or 0. 1 means level sensitive, 0 means edge sensitive.
} EINT_CTRL_SET_SENSITIVITY_T;

 /*-------------------------------------------------------------------------------------*/
 #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/*-------------------------------------------------------------------------------------*/ 
#endif // #ifndef __DCL_GPT_H_STRUCT__
#endif // #ifdef DCL_DEFINITION_STRUCT   

/*==========================================================================*/
// part II definition
/*==========================================================================*/

#ifndef _DCL_EINT_H_
#define _DCL_EINT_H_
 
#endif


/*==========================================================================*/
// part III definition
/*==========================================================================*/

#if defined(DCL_DEFINITION_PROTOTYPE)
#ifndef __DCL_EINT_H_PROTOTYPE__
#define __DCL_EINT_H_PROTOTYPE__
 
 /*------------------------------------------------------------------------
 * FUNCTION
 *	DclEINT_Open
 *
 * DESCRIPTION
 *	This function is to get a handle of EINT module. The handle will be used in later control functions.
 *
 * PARAMETERS
 *	dev  - the device of DCL EINT, always use DCL_EINT.
 *	flags - the eint number 	  
 *			
 * RETURNS
 *	 DCL_HANDLE_INVALID - a invalid handle.
 *	 DCL_HANDLE_OCCUPIED - a invalid handle, means this eint is opened by others.
 *	 handle - a valid handle.
 *
 *-----------------------------------------------------------------------*/
 extern DCL_HANDLE DclEINT_Open(DCL_DEV dev, DCL_FLAGS flags);
 
 
 /*------------------------------------------------------------------------
 * FUNCTION
 *	DclEINT_RegisterCallback
 *
 * DESCRIPTION
 *	This function is to register a callback function. it will be called in hisr. Notice,if the caller
 *	is MRE user, we will send messages instead of call it'a callback directly
 *
 * PARAMETERS
 *	handle	- invalid handle returned by DclEINT_Open.
 *	event	 - the EINT event, we not use this parameter now.  
 *	callback - the user callback
 *	parameter - the user parameter. Note: we do not support callback with parameter. user should give a NULL.
 *	user_id   - this parameter express the user id. MRE user or Native user.
 *			
 * RETURNS
 *	 STATUS_OK							   - register OK.
 *	 STATUS_INVALID_ARGUMENT	 - eint number exceed EINT_ALL_NUMBER.
 *	 STATUS_NOT_OPENED			   - this eint is not opend by DclEINT_Open.
 *	 STATUS_INVALID_DCL_HANDLE   - invalid eint handle.
 *
 *-----------------------------------------------------------------------*/
 extern DCL_HANDLE DclEINT_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, DCL_CALLBACK callback, void* parameter,DCL_USER_ID user_id);

 
 /*------------------------------------------------------------------------
 * FUNCTION
 *	DclEINT_Control
 *
 * DESCRIPTION
 *	This function is to control the EINT.
 *
 * PARAMETERS
 *	handle	- invalid handle returned by DclEINT_Open.
 *	cmd    - the EINT CMD, see details in dcl_eint.h.  
 *	data   - the parameter of different cammand.
 *			
 * RETURNS
 *	 STATUS_OK							   - register OK.
 *	 STATUS_INVALID_ARGUMENT	 - eint number exceed EINT_ALL_NUMBER.
 *	 STATUS_NOT_OPENED			   - this eint is not opend by DclEINT_Open.
 *	 STATUS_INVALID_DCL_HANDLE   - invalid eint handle.
 *	 STATUS_INVALID_CMD			   -  invalid EINT CMD.
 *
 *-----------------------------------------------------------------------*/
 extern DCL_STATUS DclEINT_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, void *data);
 
 /*------------------------------------------------------------------------
 * FUNCTION
 *	DclEINT_Close
 *
 * DESCRIPTION
 *	This function is to close the EINT opened by DclEINT_Open.
 *
 * PARAMETERS
 *	handle	- invalid handle returned by DclEINT_Open.
 *			
 * RETURNS
 *	 STATUS_OK							   - register OK.
 *	 STATUS_INVALID_ARGUMENT	 - eint number exceed EINT_ALL_NUMBER.
 *	 STATUS_INVALID_DCL_HANDLE   - invalid eint handle.
 *
 *-----------------------------------------------------------------------*/
 extern DCL_STATUS DclEINT_Close(DCL_HANDLE handle);


 /*------------------------------------------------------------------------
 * FUNCTION
 *	DclEINT_QueryHandleWithMSG
 *
 * DESCRIPTION
 *	This function is called by DCL function when MMI recieved the message and call DCL
 *	callback. This function will return the handle use the message parameters.
 *
 * PARAMETERS
 *	msg_id	- the message id of EINT, now, we not use this parameter.
 *	ilm 	  -  the message sent by eint_mre_cb.
 *			
 * RETURNS
 *	dev_handle - valid handle of triggered EINT
 *	STATUS_OK - return success.
 *
 *-----------------------------------------------------------------------*/

 extern DCL_STATUS DclEINT_QueryHandleWithMSG(msg_type msg_id,ilm_struct*	ilm,DCL_HANDLE* dev_handle);
  
#endif // #ifndef __DCL_GPT_H_PROTOTYPE__
#endif // #ifdef DCL_DEFINITION_PROTOTYPE

