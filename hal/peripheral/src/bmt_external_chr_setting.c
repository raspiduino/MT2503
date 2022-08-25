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
 *    bmt_enternal_chr_setting.c
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
DCL_STATUS External_chr_control_handler(BMT_CHARGING_CTRL_CMD cmd, void *data)
{
	DCL_STATUS status = STATUS_OK;

	if(cmd < BMT_CHARGING_CMD_NUMBER)
	{
		switch(cmd)
		{
			case BMT_CHARGING_CMD_INIT:
			{
				
			}
			break;

			case BMT_CHARGING_CMD_GET_BAT_ON_DET_STATUS:
			{
				
			}
			break;

			case BMT_CHARGING_CMD_GET_CHR_DET_STATUS:
			{
				
			}
			break;

			case BMT_CHARGING_CMD_WDT_CLEAR:
			{
				
			}
			break;

			case BMT_CHARGING_CMD_CHARGING_ENABLE:
			{
				
			}
			break;

			case BMT_CHARGING_CMD_SET_CHARGING_CURRENT:
			{
				
			}
			break;

			case BMT_CHARGING_CMD_SET_CV_DETECTION_VOLTAGE:
			{
				
			}
			break;

			case BMT_CHARGING_CMD_GET_CV_STATUS:
			{
				
			}
			break;

			case BMT_CHARGING_CMD_GET_CHARGING_CURRENT:
			{
				
			}
			break;
		}	
		
	}	
	else
		return STATUS_UNSUPPORTED;

	return status;
}

