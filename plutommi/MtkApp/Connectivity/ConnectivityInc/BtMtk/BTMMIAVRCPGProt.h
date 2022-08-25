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
 * BTMMIAVRCPGProt.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *
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
#ifndef __BT_MMI_AVRCP_GPROT_H__
#define __BT_MMI_AVRCP_GPROT_H__

#include "MMI_features.h"

#ifdef __MMI_AVRCP_SUPPORT__
#include "AvrcpSrvGprot.h"

#include "MMIDataType.h"
#include "kal_general_types.h"

/***************************************************************************** 
* Definations
*****************************************************************************/

/* AVRCP command control type */
#define MMI_AVRCP_CR_ACCEPT            SRV_AVRCP_CR_ACCEPT
#define MMI_AVRCP_CR_REJECT            SRV_AVRCP_CR_REJECT
#define MMI_AVRCP_CR_NOT_IMPLEMENT     SRV_AVRCP_CR_NOT_IMPLEMENT

/* AVRCP Commands */
#define MMI_AVRCP_POP_SELECT            SRV_AVRCP_POP_SELECT
#define MMI_AVRCP_POP_UP                SRV_AVRCP_POP_UP
#define MMI_AVRCP_POP_DOWN              SRV_AVRCP_POP_DOWN
#define MMI_AVRCP_POP_LEFT              SRV_AVRCP_POP_LEFT
#define MMI_AVRCP_POP_RIGHT             SRV_AVRCP_POP_RIGHT
#define MMI_AVRCP_POP_RIGHT_UP          SRV_AVRCP_POP_RIGHT_UP
#define MMI_AVRCP_POP_RIGHT_DOWN        SRV_AVRCP_POP_RIGHT_DOWN
#define MMI_AVRCP_POP_LEFT_UP           SRV_AVRCP_POP_LEFT_UP
#define MMI_AVRCP_POP_LEFT_DOWN         SRV_AVRCP_POP_LEFT_UP
#define MMI_AVRCP_POP_ROOT_MENU         SRV_AVRCP_POP_ROOT_MENU
#define MMI_AVRCP_POP_SETUP_MENU        SRV_AVRCP_POP_SETUP_MENU
#define MMI_AVRCP_POP_CONTENTS_MENU     SRV_AVRCP_POP_CONTENTS_MENU
#define MMI_AVRCP_POP_FAVORITE_MENU     SRV_AVRCP_POP_FAVORITE_MENU
#define MMI_AVRCP_POP_EXIT              SRV_AVRCP_POP_EXIT

#define MMI_AVRCP_POP_0                 SRV_AVRCP_POP_0
#define MMI_AVRCP_POP_1                 SRV_AVRCP_POP_1
#define MMI_AVRCP_POP_2                 SRV_AVRCP_POP_2
#define MMI_AVRCP_POP_3                 SRV_AVRCP_POP_3
#define MMI_AVRCP_POP_4                 SRV_AVRCP_POP_4
#define MMI_AVRCP_POP_5                 SRV_AVRCP_POP_5
#define MMI_AVRCP_POP_6                 SRV_AVRCP_POP_6
#define MMI_AVRCP_POP_7                 SRV_AVRCP_POP_7
#define MMI_AVRCP_POP_8                 SRV_AVRCP_POP_8
#define MMI_AVRCP_POP_9                 SRV_AVRCP_POP_9
#define MMI_AVRCP_POP_DOT               SRV_AVRCP_POP_DOT
#define MMI_AVRCP_POP_ENTER             SRV_AVRCP_POP_ENTER
#define MMI_AVRCP_POP_CLEAR             SRV_AVRCP_POP_CLEAR

#define MMI_AVRCP_POP_CHANNEL_UP        SRV_AVRCP_POP_CHANNEL_UP
#define MMI_AVRCP_POP_CHANNEL_DOWN      SRV_AVRCP_POP_CHANNEL_DOWN
#define MMI_AVRCP_POP_PREVIOUS_CHANNEL  SRV_AVRCP_POP_PREVIOUS_CHANNEL
#define MMI_AVRCP_POP_SOUND_SELECT      SRV_AVRCP_POP_SOUND_SELECT
#define MMI_AVRCP_POP_INPUT_SELECT      SRV_AVRCP_POP_INPUT_SELECT
#define MMI_AVRCP_POP_DISPLAY_INFO      SRV_AVRCP_POP_DISPLAY_INFO
#define MMI_AVRCP_POP_HELP              SRV_AVRCP_POP_HELP
#define MMI_AVRCP_POP_PAGE_UP           SRV_AVRCP_POP_PAGE_UP
#define MMI_AVRCP_POP_PAGE_DOWN         SRV_AVRCP_POP_PAGE_DOWN

#define MMI_AVRCP_POP_POWER             SRV_AVRCP_POP_POWER
#define MMI_AVRCP_POP_VOLUME_UP         SRV_AVRCP_POP_VOLUME_UP
#define MMI_AVRCP_POP_VOLUME_DOWN       SRV_AVRCP_POP_VOLUME_DOWN
#define MMI_AVRCP_POP_MUTE              SRV_AVRCP_POP_MUTE
#define MMI_AVRCP_POP_PLAY              SRV_AVRCP_POP_PLAY
#define MMI_AVRCP_POP_STOP              SRV_AVRCP_POP_STOP
#define MMI_AVRCP_POP_PAUSE             SRV_AVRCP_POP_PAUSE
#define MMI_AVRCP_POP_RECORD            SRV_AVRCP_POP_RECORD
#define MMI_AVRCP_POP_REWIND            SRV_AVRCP_POP_REWIND
#define MMI_AVRCP_POP_FAST_FORWARD      SRV_AVRCP_POP_FAST_FORWARD
#define MMI_AVRCP_POP_EJECT             SRV_AVRCP_POP_EJECT
#define MMI_AVRCP_POP_FORWARD           SRV_AVRCP_POP_FORWARD
#define MMI_AVRCP_POP_BACKWARD          SRV_AVRCP_POP_BACKWARD

#define MMI_AVRCP_POP_ANGLE             SRV_AVRCP_POP_ANGLE
#define MMI_AVRCP_POP_SUBPICTURE        SRV_AVRCP_POP_SUBPICTURE

#define MMI_AVRCP_POP_F1                SRV_AVRCP_POP_F1
#define MMI_AVRCP_POP_F2                SRV_AVRCP_POP_F2
#define MMI_AVRCP_POP_F3                SRV_AVRCP_POP_F3
#define MMI_AVRCP_POP_F4                SRV_AVRCP_POP_F4
#define MMI_AVRCP_POP_F5                SRV_AVRCP_POP_F5

#define MMI_AVRCP_POP_VENDOR_UNIQUE     SRV_AVRCP_POP_VENDOR_UNIQUE

#define MMI_AVRCP_POP_RESERVED          SRV_AVRCP_POP_RESERVED

/***************************************************************************** 
* Enum
*****************************************************************************/

typedef enum
{
    MMI_AVRCP_KEY_DOWN = SRV_AVRCP_KEY_DOWN,
    MMI_AVRCP_KEY_UP = SRV_AVRCP_KEY_UP,
    MMI_AVRCP_KEY_LONGPRESS = SRV_AVRCP_KEY_LONGPRESS,
    MMI_AVRCP_KEY_REPEAT = SRV_AVRCP_KEY_REPEAT,
    MMI_AVRCP_KEY_CANCELED = SRV_AVRCP_KEY_CANCELED,

    MMI_AVRCP_TOTAL_KEY_EVENTS = SRV_AVRCP_TOTAL_KEY_EVENTS
} mmi_avrcp_key_events;


/***************************************************************************** 
* typedef 
*****************************************************************************/
typedef U8(*AVRCPCmdFuncPtr) (U8 command_type, mmi_avrcp_key_events key_events);


/***************************************************************************** 
* Functions
*****************************************************************************/

extern void mmi_bt_avrcp_set_cmd_hdlr(AVRCPCmdFuncPtr callback_func);
extern void mmi_bt_avrcp_clear_cmd_hdlr(AVRCPCmdFuncPtr callback_func);
//extern void mmi_bt_avrcp_frm_sync_calllback(BOOL is_blocked);

#ifdef __MMI_AVRCP_TEST__
extern void mmi_bt_avrcp_tst_different_down_cmd(void);
extern void mmi_bt_avrcp_tst_same_down_cmd(void);
extern void mmi_bt_avrcp_tst_only_down_cmd(void);
extern void mmi_bt_avrcp_tst_only_up_cmd(void);
#endif /*__MMI_AVRCP_TEST__*/

extern U16 mmi_bt_avrcp_util_get_cmd_string(U8 command);

//#ifdef __MMI_EM_BT_AVRCP_CONNECT_TG_ACTIVELY__
//extern MMI_BOOL mmi_bt_avrcp_get_actively_connect_tg_flag(void);
//extern void mmi_bt_avrcp_set_actively_connect_tg_flag(MMI_BOOL on_off);
//#endif

#endif /* __MMI_AVRCP_SUPPORT__ */

#endif /* __BT_MMI_AVRCP_GPROT_H__ */ 

