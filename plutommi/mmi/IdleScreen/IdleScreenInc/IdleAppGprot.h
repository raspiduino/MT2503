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
 *  IdleAppGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the external interface of the idle screen application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __IDLEAPP_GPROT_H__
#define __IDLEAPP_GPROT_H__

// auto add by kw_check begin
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
// auto add by kw_check end 

/**********************************************************************
 * Enum definitions
 **********************************************************************/

/* This enum defines the display item on the idle screen. */
typedef enum
{
    MMI_IDLE_DISP_OWNER_NUMBER      /* Owner number */
} mmi_idle_disp_item_enum;


/**********************************************************************
 * External Interfaces
 **********************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_idle_is_on_idle_screen
 * DESCRIPTION
 *  This function checks whether the idle screen is active. Please note that
 *  this function is not for the "Blocked SIM" and "Insert SIM" idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern pBOOL mmi_idle_is_on_idle_screen(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_is_screensaver_running
 * DESCRIPTION
 *  This function checks whether the screen saver is running.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern pBOOL mmi_idle_is_screensaver_running(void);


/*****************************************************************************
 * FUNCTION
 *  IsSmChineseSet
 * DESCRIPTION
 *  This function checks whether the current network is a Chinese network, e.g.
 *  CN, HK, or TW.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL mmi_idle_is_camp_on_chinese_network(U8 *plmn);


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_get_idle_screen_id
 * DESCRIPTION
 *  This function returns the idle screen ID. At present, there are 3 different
 *  screen ID for the idle screen APP.
 *
 *      1) IDLE_SCREEN_ID
 *      2) SCR_SIM_INSERTION
 *      3) SCR_SIM_BLOCK
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  The idle screen ID.
 *****************************************************************************/
extern U16 mmi_idle_get_idle_screen_id(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_is_disp_available
 * DESCRIPTION
 *  This function checks whether the item can be displayed on the idle screen.
 * PARAMETERS
 *  type            : [IN]      Display item
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL mmi_idle_is_disp_available(mmi_idle_disp_item_enum type);


#ifdef __MMI_TOUCH_IDLESCREEN_SHORTCUTS__
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_is_display_touch_shortcuts
 * DESCRIPTION
 *  This function checks whether the touch shortcuts are shown on the idle
 *  screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL mmi_idle_is_display_touch_shortcuts(void);
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_is_keypad_locked
 * DESCRIPTION
 *  This function returns if the keypad is locked or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  On locked, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL mmi_idle_is_keypad_locked(void);

#endif /* __IDLEAPP_GPROT_H__ */ 

