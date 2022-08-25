/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   dcl_aux.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of DCL (Driver Common Layer) for AuxMain & ACCDET.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef DCL_DEFINITION_STRUCT
#ifndef __DCL_AUX_H_STRUCT__
#define __DCL_AUX_H_STRUCT__

/* DCL_OPTIONS for AUX, not in use now. */
#define AUX_OPTIONS

/* DCL_CONFIGURE_T for AUX, not in use now. */
#define AUX_CONFIGS

/* DCL_EVENT for AUX, not in use now. */
#define AUX_EVENTS
 
#ifdef __BUILD_DOM__
/* DCL_CTRL_CMD for AUX */
typedef enum
{
   AUX_CMD_GET_ACCDET_CONFIG_DATA_DEFINE, /* Get ACCDET	config data */
   AUX_CMD_SET_ACCDET_CONFIG_DATA_DEFINE, /* Get ACCDET	config data */
   AUX_CMD_SET_AUDIO_STATUS /* In ACCDET hybrid solution mode, user should call this command to indicate audio open/closed */
}DCL_CTRL_AUX_CMD_T;
#else 
#define AUX_CMDS \
   AUX_CMD_GET_ACCDET_CONFIG_DATA_DEFINE, \
   AUX_CMD_SET_ACCDET_CONFIG_DATA_DEFINE, \
   AUX_CMD_SET_AUDIO_STATUS, 
#endif /* __BUILD_DOM__ */

/* ACCDET Config Data Definition. */
typedef struct 
{
   DCL_UINT32 u4HookDebounce; /* ACCDET_DEBOUNCE0 */
   DCL_UINT32 u4MicDebounce; /* ACCDET_DEBOUNCE1 */  
   DCL_UINT32 u4PlugoutDebounce; /* ACCDET_DEBOUNCE3 */
   DCL_UINT32 u4PwmDelay; /* ACCDET_EN_DELAY_NUM */
   DCL_UINT32 u4CmpWidth; /* ACCDET_CMP_PWM_WIDTH */
   DCL_UINT32 u4CmpThreshold; /* ACCDET_CMP_PWM_THRESH */
   DCL_UINT32 u4VthWidth; /* ACCDET_VTH_PWM_WIDTH */
   DCL_UINT32 u4VthThreshold; /* ACCDET_VTH_PWM_THRESH */
   DCL_UINT32 u4MbiasWidth; /* ACCDET_MBIAS_PWM_WIDTH */
   DCL_UINT32 u4MbiasThreshold; /* ACCDET_MBIAS_PWM_THRESH */
} AUX_ACCDET_CONFIG_DATA_DEFINE_T;

/* For AUX_CMD_GET_ACCDET_CONFIG_DATA_DEFINE, AUX_CMD_SET_ACCDET_CONFIG_DATA_DEFINE command. */
typedef struct 
{
   AUX_ACCDET_CONFIG_DATA_DEFINE_T *rAccdetConfigData; /* Pointer to ACCDET Config Data */
} AUX_CTRL_GET_ACCDET_CONFIG_DATA_T, AUX_CTRL_SET_ACCDET_CONFIG_DATA_T;

/* In ACCDET hybrid solution mode, indicate audio closed/opened. */
typedef enum
{
   DCL_AUX_AUDIO_STATUS_CLOSED, /* audio closed */
   DCL_AUX_AUDIO_STATUS_OPEN /* audio opened */
}DCL_AUX_AUDIO_STATUS;

/* For AUX_CMD_SET_AUDIO_OPEN, AUX_CMD_SET_AUDIO_CLOSED command. */
typedef struct
{
   DCL_AUX_AUDIO_STATUS eAudioStatus; /* audio status: opened/closed */
}AUX_CTRL_SET_AUDIO_STATUS_T;


#ifdef __BUILD_DOM__
/* DCL_CTRL_DATA_T for AUX: Define the Control data structure for each command */ 
typedef union
{
   AUX_CTRL_GET_ACCDET_CONFIG_DATA_T rGetAccdetConfigData; /* Get ACCDET config data */
   AUX_CTRL_SET_ACCDET_CONFIG_DATA_T rSetAccdetConfigData; /* Set ACCDET config data */
   AUX_CTRL_SET_AUDIO_STATUS_T rSetAudioStatus; /* to set the flag to indicate that audio opened/closed */
}DCL_CTRL_AUX_DATA_T;
#else
#define AUX_CTRLS \
   AUX_CTRL_GET_ACCDET_CONFIG_DATA_T rGetAccdetConfigData; \
   AUX_CTRL_SET_ACCDET_CONFIG_DATA_T rSetAccdetConfigData; \
   AUX_CTRL_SET_AUDIO_STATUS_T rSetAudioStatus;
#endif /* __BUILD_DOM__ */

#endif // #ifndef __DCL_AUX_H_STRUCT__
#endif // #ifdef DCL_DEFINITION_STRUCT   


#ifdef DCL_DEFINITION_PROTOTYPE
#ifndef __DCL_ACCDET_H_PROTOTYPE__
#define __DCL_ACCDET_H_PROTOTYPE__

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
extern DCL_STATUS DclAUX_Initialize(void);
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
extern DCL_HANDLE DclAUX_Open(DCL_DEV dev, DCL_FLAGS flags);
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
extern DCL_STATUS DclAUX_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options);
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
extern DCL_STATUS DclAUX_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options);
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
extern DCL_STATUS DclAUX_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);
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
extern DCL_STATUS DclAUX_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback);
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
*          2. AUX_CMD_SET_AUDIO_STATUS: to set the flag to indicate audio open/closed
*  data: The data of the control command
*          1. AUX_CMD_GET_ACCDET_CONFIG_DATA_DEFINE: pointer to a AUX_CTRL_ACCDET_CONFIG_DATA_DEFINE_T structure
*          2. AUX_CMD_SET_AUDIO_STATUS: pointer to a AUX_CTRL_SET_AUDIO_STATUS_T structure
*
* RETURNS
*  STATUS_OK: command is executed successfully.
*  STATUS_FAIL: command is failed.
*  STATUS_INVALID_CMD: It's a invalid command.
*  STATUS_INVALID_DCL_HANDLE: It's a invalid handle.
*  
*************************************************************************/
extern DCL_STATUS DclAUX_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
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
*  STATUS_FAIL: command is failed.
*  STATUS_INVALID_DCL_HANDLE: It's a invalid handle.
*
*************************************************************************/
extern DCL_STATUS DclAUX_Close(DCL_HANDLE handle);
#endif // #ifndef __DCL_ACCDET_H_PROTOTYPE__
#endif // #ifdef DCL_DEFINITION_PROTOTYPE
