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
 *    bmt_chr_setting.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines bmt internal charger hw setting function.
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
#ifndef _BMT_CHR_SETTING_H
#define _BMT_CHR_SETTING_H

#include "dcl.h"

// ============================================================
// define
// ============================================================


// ============================================================
// ENUM
// ============================================================
typedef enum
{
	BMT_CHARGING_CMD_INIT = 0,
	BMT_CHARGING_CMD_GET_BAT_ON_DET_STATUS = 1,
	BMT_CHARGING_CMD_GET_CHR_DET_STATUS = 2,
	BMT_CHARGING_CMD_GET_BAT_OV_STATUS = 3,
	BMT_CHARGING_CMD_WDT_CLEAR = 4,
	BMT_CHARGING_CMD_SET_ADC = 5,
#if !defined(BMT_CHARGING_DISABLE)	
	BMT_CHARGING_CMD_CHARGING_ENABLE = 6, 
	BMT_CHARGING_CMD_SET_CHARGING_CURRENT = 7, 	
	BMT_CHARGING_CMD_SET_CV_DETECTION_VOLTAGE = 8, 	
	BMT_CHARGING_CMD_GET_CV_STATUS = 9,
	BMT_CHARGING_CMD_GET_CHARGING_CURRENT = 10,
	BMT_CHARGING_CMD_GET_HV_STATUS = 11,
#endif	
	BMT_CHARGING_CMD_NUMBER
} BMT_CHARGING_CTRL_CMD;


#if defined(__EXT_BOOTLOADER__)
typedef enum
{
	BMT_BL_CHARGING_CMD_GET_CHR_DET_STATUS = 0,
	BMT_BL_CHARGING_CMD_GET_CHARGING_CURRENT = 1,
	BMT_BL_CHARGING_CMD_SET_CHARGING_CURRENT = 2,
	BMT_BL_CHARGING_CMD_GET_CC_STATUS = 3,   
	BMT_BL_CHARGING_CMD_SET_CSDAC_ENABLE = 4,
	BMT_BL_CHARGING_CMD_SET_CHR_ENABLE = 5,
	BMT_BL_CHARGING_CMD_SET_HV_VOLTAGE = 6,
	BMT_BL_CHARGING_CMD_SET_HV_ENABLE = 7,
	BMT_BL_CHARGING_CMD_SET_USBDL_RESET = 8,
	BMT_BL_CHARGING_CMD_GET_BATON_STATUS = 9,
	BMT_BL_CHARGING_CMD_SET_BATON_ENABLE = 10,
	BMT_BL_CHARGING_CMD_SET_USBDL_SET = 11,
	BMT_BL_CHARGING_CMD_WDT_CLEAR = 12,
	BMT_BL_CHARGING_CMD_NUMBER
}BMT_BL_CHARGING_CTRL_CMD;
#endif
// ============================================================
// structure
// ============================================================


// ============================================================
// typedef
// ============================================================
typedef DCL_STATUS (*BMT_CHARGING_CONTROL_HANDLER)(BMT_CHARGING_CTRL_CMD cmd, void *data);


// ============================================================
// External Variables
// ============================================================


// ============================================================
// External function
// ============================================================
#if defined(__EXT_BOOTLOADER__)
extern DCL_STATUS bl_chr_control_handler(BMT_BL_CHARGING_CTRL_CMD cmd, void *data);
#endif

#ifdef __GENERAL_EXTERNAL_CHARGER__
extern DCL_STATUS External_chr_control_handler(BMT_CHARGING_CTRL_CMD cmd, void *data);
#else
extern DCL_STATUS Internal_chr_control_handler(BMT_CHARGING_CTRL_CMD cmd, void *data);
#endif
#endif
