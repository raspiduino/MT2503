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
 * BTMMIHIDScr.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is the header file of btmmihidscr.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __BT_MMI_HID_SCR_H__
#define __BT_MMI_HID_SCR_H__

/* RHR ADD */
#include "MMIDataType.h"
/* RHR ADD end */

/***************************************************************************** 
* Macro
*****************************************************************************/

/***************************************************************************** 
* Definitions
*****************************************************************************/
#define HID_MAX_CTRL_DATA_LENGTH    (9)
#define HID_NUM_OF_CTRL_DATA        (16+4)

#define MMI_HID_MAX_KBD_CMD         (3)

#define HID_KEY_REPEAT_PERIOD       (100) 
#define HID_KEY_DELAY_REPEAT_PERIOD (2)

/***************************************************************************** 
* Enum
*****************************************************************************/
typedef enum
{
     HID_ACTIVE_BTN,
     HID_INACTV_BTN
} hid_button_status_enum;

typedef enum
{
    HID_ELEMENT_DESKTOP,
    HID_ELEMENT_MEDIAPLAYER,
    HID_ELEMENT_PRESENTER,
    HID_ELEMENT_COUNT
} hid_element_type_enum;

typedef enum 
{
    HID_EVT_AUTH_IND,
    HID_EVT_CONN_IND,
    HID_EVT_CONN_FAIL,
    HID_EVT_UNPLUG_IND,
    HID_EVT_DISC_IND
} hid_scrn_event_enum;

typedef enum 
{
    HID_E_CONN_FAIL,
    HID_E_DISC_SUCC,
    HID_E_DISC_FAIL,
    HID_E_DISC_IND,
    HID_E_BUSY,
    HID_E_NOT_ALLOW
} hid_scrn_result_enum;

typedef enum
{
    HID_INT_CONN_FAIL   = 0x01,
    HID_INT_DISC_SUCC   = 0x02,
    HID_INT_DISC_FAIL   = 0x03,
    HID_INT_DISC_IND    = 0x04,
    HID_INT_BUSY        = 0x05,
    HID_INT_NOT_ALLOW   = 0x06,
    HID_INT_CONN_IND    = 0x12,
    HID_INT_UNPLUG_CNF  = 0x13,
    HID_INT_PROG        = 0x14
} hid_int_class_enum;

typedef enum
{
    HID_SCRN_SHOW,
    HID_SCRN_PENDING,
    HID_SCRN_HIDE
} hid_scrn_status_enum;

typedef enum
{
    HID_PROG_CONN,  /* Connecting */
    HID_PROG_DISC   /* Disconnecting */
} hid_progress_enum;

/***************************************************************************** 
* Structure
*****************************************************************************/
typedef struct
{
    U8 sel_idx;
    U16 gid;
    U16 base_scrn;
    U16 key_cmd[MMI_HID_MAX_KBD_CMD+1];
} mmi_bt_hid_scr_cntx_struct;

typedef struct
{
    U16 key_code;
    U16 key_type; 
    U8 status;
    U8 ctrl_data[HID_MAX_CTRL_DATA_LENGTH];
} mmi_bt_hid_key_control_data_struct;

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
extern void mmi_bt_hid_scr_init(void);
extern void mmi_bt_remote_control_menu_hilight_handler(void);
extern void mmi_bt_remote_control_menu_hint_handler(U16 index);
extern void mmi_hid_scrn_notify(U32 evt, U32 result);

#endif /* __BT_MMI_HID_SCR_H__ */

