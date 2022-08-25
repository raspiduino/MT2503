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
 * PowerOnChargerProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for defination for charging application
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      PowerOnChargerProt.h
   Author:
   Date Created:  September-13-2002
   Contains:      Idle screen application
**********************************************************************************/

#ifndef _POWERONCHARGER_PROT_H
#define _POWERONCHARGER_PROT_H

#include "MMIDataType.h"
#include "kal_general_types.h"

typedef struct
{
    U8 PowerOnCharger;          /* Tells if the power on is bcos of charger */
    U8 PowerOnChargingPeriod;   /* Tells if charging is going on during power on charger */
    U8 ChargingAbnormal;        /* If abnormal case of charging. */
    U8 ChargingComplete;        /* Tells if charging is complete. (Robin 1121 for engineer mode) */
    U8 LowBatteryFlag;          /* Tels if Battery is low. */
    U8 LowBatteryTxProhibitFlag;
    U8 chargerLevel;
    U8 batteryStatus;
    U8 isChargerConnected;      /* Tells if charger is connected */
    U8 LowBatteryCutOffCallCnt;
    U8 BatteryNotifyModId;      /* Battery notify module ID: default=0 */
} charbat_context_struct;

extern charbat_context_struct g_charbat_context;

#define LBAT_SHUTDOWN_SCR_TIMER_DUR 5000

extern mmi_ret mmi_charbat_main_evt_hdlr(mmi_event_struct* para);
extern void mmi_charbat_update_status_icon(void);

extern void BatteryStatusRsp(void *);

extern void InitChargerPwrOn(void);
extern void PopulateResData(void);
extern void *PopulateResGetBaseIDTable(void);
extern void InitUnicodeSupport(void);
extern void BatteryIndicationPopup(U16 stringId);
extern void BatteryIndicationPopupEx(U16 stringId);
extern void IdleScreenChargerConnected(U8 playtone);
extern void IdleScreenChargerDisconnected(void);
extern void IdleScreenBatteryFullCharged(void);
extern void BatteryStatusIndication(U8);
extern void ChargingAbnormalHandler(U16 stringId);  /* Robin 1108 */
extern void ChgrPlayLowBatTone(void);               /* Robin 1209 */
extern void ChargingPwnOnThanPwnOn(void);

extern void ShowLowPowerShutdownScr(void);

extern BOOL IS_LOW_BATTERY(void);

extern U8 mmi_gpio_get_current_battery_level(void);

extern MMI_BOOL mmi_gpio_is_charger_connected(void);

#ifdef __MMI_SUBLCD__
extern MMI_BOOL mmi_charbat_show_sublcd_battery_status_icon(void);
#endif
#endif /* _POWERONCHARGER_PROT_H */ 

