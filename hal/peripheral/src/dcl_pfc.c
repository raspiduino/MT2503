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
 *    dcl_pfc.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines DCL (Driver Common Layer) of the PFC driver.
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/

#include "drv_features.h"
#include "dcl.h"
#ifdef DCL_PFC_INTERFACE
#include "pfc_sw.h"
#include "kal_general_types.h"
#include "kal_public_api.h"

// Global variable for DCL PFC API usage
#define DCL_PFC_MAGIC_NUM		(0x40000000)
#define DCL_PFC_IS_HANDLE_MAGIC(handle_) ((handle_)& DCL_PFC_MAGIC_NUM)
#define DCL_PFC_GET_DEV(handle_) ((handle_) & (~DCL_PFC_MAGIC_NUM))

/*************************************************************************
* FUNCTION
*  DclPFC_Initialize
*
* DESCRIPTION
*  This function is to initialize PFC module
*
* PARAMETERS
*  None
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
DCL_STATUS DclPFC_Initialize(void){
	DCL_STATUS status = STATUS_UNSUPPORTED;

#if defined(__HW_PFC_SUPPORT__)
    PFC_init();
    status = STATUS_OK;
#endif //#if defined(__HW_PFC_SUPPORT__)

	return status;
}

/*************************************************************************
* FUNCTION
*  DclPFC_Open
*
* DESCRIPTION
*  This function is to open the PFC module and return a handle
*
* PARAMETERS
*  dev: only valid for DCL_PFC
*  flags: no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*  DCL_HANDLE_INVALID: Open failed
*  DCL_HANDLE_OCCUPIED: Already Opened
*  other value: a valid handle
*
*************************************************************************/
DCL_HANDLE DclPFC_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	if (dev != DCL_PFC){
		ASSERT(0);
		return DCL_HANDLE_INVALID;		// Incorrecr device ID
	}

        return (DCL_PFC_MAGIC_NUM | dev);
    }

/*************************************************************************
* FUNCTION
*  DclPFC_ReadData
*
* DESCRIPTION
*  This function is not supported for the PFC module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclPFC_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

/*************************************************************************
* FUNCTION
*  DclPFC_WriteData
*
* DESCRIPTION
*  This function is not supported for the PFC module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclPFC_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

/*************************************************************************
* FUNCTION
*  DclPFC_Configure
*
* DESCRIPTION
*  This function is not supported for the PFC module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclPFC_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	return STATUS_UNSUPPORTED;
}

/*************************************************************************
* FUNCTION
*  DclPFC_RegisterCallback
*
* DESCRIPTION
*  This function is to set callback function for the PFC module.
*
* PARAMETERS
*  handle: the returned handle value of DclPFC_Open
*  event: Supported events:
*  callback: the callback function for registered events
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclPFC_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback){
	return STATUS_UNSUPPORTED;
}


/*************************************************************************
* FUNCTION
*  DclPFC_Control
*
* DESCRIPTION
*  This function is to send command to control the PFC module.
*
* PARAMETERS
*  handle: The handle value returned from DclPFC_Open
*  cmd: a control command for PFC module
*       PFC: Refer dcl_PFC.c
*
*
*  data: The data of the control command
*        PFC: Refer dcl_PFC.c
*
*
* RETURNS
*  STATUS_OK: command is executed successfully.
*  STATUS_FAIL: command is failed.
*  STATUS_INVALID_CMD: It's a invalid command.
*
*************************************************************************/
DCL_STATUS DclPFC_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
    DCL_STATUS return_value = STATUS_INVALID_DCL_HANDLE;
	// Check magic number
	/*if ((DCL_PFC_IS_HANDLE_MAGIC(handle) == 0) || (fgPFCOpen == KAL_FALSE) || (DCL_PFC_GET_DEV(handle) != DCL_PFC)){
		ASSERT(0);
		return STATUS_INVALID_DCL_HANDLE;
	}
	*/

    switch (cmd)
    {
        case PFC_CMD_RESET:
        {
            PFC_CTRL_RESET_T *prCtrlReset;
            prCtrlReset = &(data->rPfcCtrlReset);
            PFC_reset(prCtrlReset->ContextID);
            return_value = STATUS_OK;
            break;
        }
        case PFC_CMD_ENCODE:
        {
            PFC_CTRL_ENCODE_T *prCtrlEncode;
            prCtrlEncode = &(data->rPfcCtrlEncode);
            prCtrlEncode->fgEncodeResult = (DCL_BOOLEAN)PFC_Encode(prCtrlEncode->dest, prCtrlEncode->src, prCtrlEncode->state);
            return_value = STATUS_OK;
            break;            
        }
        case PFC_CMD_DECODE:
        {
            PFC_CTRL_DECODE_T *prCtrlDecode;
            prCtrlDecode = &(data->rPfcCtrlDecode);
            prCtrlDecode->fgDecodeResult = (DCL_BOOLEAN)PFC_Decode(prCtrlDecode->dest, prCtrlDecode->src, prCtrlDecode->state, prCtrlDecode->rcv_AT_CMD_OR_ESCAPE);            
            return_value = STATUS_OK;
            
            break;            
        }
        default:
            ASSERT(0);
            return_value = STATUS_INVALID_CMD;
            break;
    }
    
	return return_value;
}

/*************************************************************************
* FUNCTION
*  DclPFC_Close
*
* DESCRIPTION
*  This function is to close the PFC module.
*
* PARAMETERS
*  handle: the returned handle value of DclPFC_Open
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
DCL_STATUS DclPFC_Close(DCL_HANDLE handle)
{
   return STATUS_UNSUPPORTED;
}

#else // Else of #ifdef DCL_PFC_INTERFACE

DCL_STATUS DclPFC_Initialize(void)
{
    return STATUS_UNSUPPORTED;
}

DCL_HANDLE DclPFC_Open(DCL_DEV dev, DCL_FLAGS flags)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclPFC_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclPFC_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclPFC_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclPFC_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclPFC_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclPFC_Close(DCL_HANDLE handle)
{
    return STATUS_UNSUPPORTED;
}

#endif // End of #ifdef DCL_PFC_INTERFACE


