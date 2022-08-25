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

/*******************************************************************************
 * Filename:
 * ---------
 *   wndrv_api.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   header file of API functions of WLAN Network driver for other tasks
 *
 * Author:
 * -------
 * -------
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _WNDRV_API_H
#define _WNDRV_API_H

//#include "kal_non_specific_general_types.h"
//#include "kal_release.h"
#include "stack_config.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "MMIDataType.h"

/*******************************************************************************
*
*  LCD status Related Functions
*
*******************************************************************************/
void wndrv_LCD_isOFF(void);
void wndrv_LCD_isON(void);

/*******************************************************************************
*
*  802.11 power saving mode Related Functions
*
*******************************************************************************/
typedef struct
{
    kal_uint8    HandleCount;
    kal_uint32   Enable;      /* Default disable WLAN power saving mode */
    kal_int8     name[32][9];
#if defined (MT5931) || defined (WIFI_BB_MT5921)
    kal_uint32   StautHandle; /* Store the STAUT handle in the WMM PS test when using 5921 driver*/
#endif    
} WLAN_PS_CTL;

#define BT_STATE_IDLE         0x00000001
#define BT_STATE_INQUIRY      0x00000002
#define BT_STATE_INQUIRY_SCAN 0x00000004
#define BT_STATE_PAGE         0x00000008
#define BT_STATE_PAGE_SCAN    0x00000010
#define BT_STATE_CONNECT      0x00000020
#define BT_STATE_SNIFF        0x00000040
#define BT_STATE_HOLD         0x00000080
#define BT_STATE_PARK         0x00000100
#define BT_STATE_MASTER       0x00000200
#define BT_STATE_SCATTERNET   0x00000400
#define BT_STATE_EDR          0x00000800
#define BT_STATE_1SCO         0x00001000
#define BT_STATE_2SCO         0x00002000
#define BT_STATE_3SCO         0x00004000
#define BT_STATE_1eSCO        0x00010000
#define BT_STATE_2eSCO        0x00020000
#define BT_STATE_3eSCO        0x00040000

#define PROTOCOL_VOIP_SIPLOGIN  0x00000001
#define PROTOCOL_VOIP_SIPINCALL 0x00000002
#define PROTOCOL_SOCKETOPEN     0x00000004
#define PROTOCOL_POC_SIPLOGIN   0x00000010
#define PROTOCOL_POC_SIPONCALL  0x00000020

#define WLAN_STATE_SIP_LOGIN    0x00000001
#define WLAN_STATE_TALKING_MODE 0x00000002

kal_uint8 wndrv_PS_GetHandle(kal_int8 *psName);
void wndrv_PS_Enable(kal_uint8 handle);
void wndrv_PS_Disable(kal_uint8 handle);
void wndrv_isTalkingMode(void);
void wndrv_isIdleMode(void);

void wndrv_PowerSave_Ctrl(kal_uint8 bCtl);

void wndrv_set_Protocol_Status(kal_uint32 value, kal_uint32 mask);

/*******************************************************************************
*
*  WMM U-APSD power saving mode Related Functions
*
*******************************************************************************/
extern kal_uint32 wndrv_UAPSD_isEnable;
#if defined (__MTK_TARGET__)
extern kal_mutexid wifi_mutex;
#endif
/*******************************************************************************
*
*  WLAN BT Co-existence Related Functions
*
*******************************************************************************/
void wndrv_PTA_isOFF(void);
void wndrv_PTA_isON(void);
kal_uint8 BT_exist(void);
void BT_State_Report2WLAN(kal_uint32 value, kal_uint32 mask);
kal_uint32 WLAN_State_Report2BT(void);
/*******************************************************************************
*
*  Chip status Related Functions
*
*******************************************************************************/
kal_bool wndrv_chip_isOK(void);

void disable_PS_mode( module_type module_id );

/*******************************************************************************
*
*  MMI WIFI callback
*
*******************************************************************************/
//kal_int32  wndrv_hdl_lcd_sleep_in(void *event);
mmi_ret wndrv_hdl_lcd_sleep_in(mmi_event_struct *event);

//kal_int32  wndrv_hdl_lcd_sleep_out(void *event);
mmi_ret wndrv_hdl_lcd_sleep_out(mmi_event_struct *event);

kal_uint32 wndrv_query_chip_capability(void);

#endif /* _WNDRV_API_H */
