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
 *  ScrLockerGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the SAP of the screen locker application.
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

#ifndef SCR_LOCKER_GPROT_H
#define SCR_LOCKER_GPROT_H

/****************************************************************************
 * Include
 ****************************************************************************/

//#include "mmi_rp_app_scr_locker_def.h"

// auto add by kw_check begin
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_frm_input_gprot.h"
// auto add by kw_check end 

/***************************************************************************
*Macro
****************************************************************************/
//lhm remove from mmi_features.h
#if (defined(__MMI_MAINLCD_96X64__) && defined(__MMI_SCREEN_LOCK_CLASSIC__))
	#ifndef __MMI_SCREEN_LOCK_CLASSIC_NEPTUNE_LIKE_BWUI__
	#define __MMI_SCREEN_LOCK_CLASSIC_NEPTUNE_LIKE_BWUI__
	#endif
#endif

//#ifndef __MMI_SCREEN_LOCKER_MANUAL_LOCK__ 
//#define __MMI_SCREEN_LOCKER_MANUAL_LOCK__
//#endif


/****************************************************************************
 * Enum
 ****************************************************************************/

/* Screen locker type. */
typedef enum
{
    /* Classic screen locker. */
    MMI_SCR_LOCKER_TYPE_CLASSIC,

    /* Fancy screen locker. (only for touch screen, based on Pluto MMI) */
    MMI_SCR_LOCKER_TYPE_FANCY,

    /* Shell screen locker. (only for touch screen, based on Venus MMI) */
    MMI_SCR_LOCKER_TYPE_SHELL,

    /* Lawmo screen locker. (only for device management's LAWMO lock) */
    MMI_SCR_LOCKER_TYPE_LAWMO,

    /* key launcher screen lock. (can lock in any screen) */
    MMI_SCR_LOCKER_TYPE_SCRLOCK_KEY,

    /* Total number of screen locker. */
    MMI_SCR_LOCKER_TYPE_TOTAL,

    /* Unspecified. The screen locker will automatically select a type. */
    MMI_SCR_LOCKER_TYPE_UNSPECIFIED,

    /* Invalid type. */
    MMI_SCR_LOCKER_TYPE_INVALID
} mmi_scr_locker_type_enum;

#if defined(__MMI_SCREEN_LOCK_ANY_TIME__) || defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__)

typedef enum
{
    /* auto lock */
    MMI_SCR_LOCKER_LOCK_MODE_AUTO_LOCK,
    /* lock by power key */
    MMI_SCR_LOCKER_LOCK_MODE_POWER_KEY,
    /* Invalid type. */
    MMI_SCR_LOCKER_LOCK_MODE_INVALID
    
} mmi_scr_locker_lock_mode_enum;

#endif

/****************************************************************************
 * Event Structure
 ****************************************************************************/

/* This is the structure for the EVT_ID_SCR_LOCKER_LOCKED. */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    /* Type of the screen locker. */
    mmi_scr_locker_type_enum type;
} mmi_scr_locker_locked_evt_struct;

/* This is the structure for the EVT_ID_SCR_LOCKER_UNLOCKED. */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    /* Type of the screen locker. */
    mmi_scr_locker_type_enum type;
} mmi_scr_locker_unlocked_evt_struct;

/* This is the structure for the FTE2.0 screen lock to do pre check before lock. */
#if defined(__MMI_SCREEN_LOCK_ANY_TIME__) || defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__)

typedef struct
{
    MMI_EVT_PARAM_HEADER

    mmi_scr_locker_lock_mode_enum lock_mode;
    
}mmi_scr_locker_pre_lock_evt_struct;

#endif

/****************************************************************************
 * Function
 ****************************************************************************/

typedef void (*mmi_scr_locker_locked_key_callback)(mmi_frm_key_evt_struct* evt);

/*****************************************************************************
 * FUNCTION
 *  mmi_scr_locker_set_locked_key_hdlr
 * DESCRIPTION
 *  This function is for the background running apps who want to do things when locker is locked
 * PARAMETERS
 *  key_code           : [IN]      key code to trigger manual lock
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_scr_locker_set_locked_key_callback(mmi_scr_locker_locked_key_callback cb);

/*****************************************************************************
 * FUNCTION
 *  mmi_scr_locker_clear_locked_key_hdlr
 * DESCRIPTION
 *  This function clear the key hdlr.
 * PARAMETERS
 *  key_code           : [IN]      key code to trigger manual lock
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_scr_locker_clear_locked_key_callback(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_scr_locker_start_manual_lock
 * DESCRIPTION
 *  This function initializes the manual keypad lock process.
 * PARAMETERS
 *  key_code           : [IN]      key code to trigger manual lock
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_scr_locker_start_manual_lock(U16 key_code);


/*****************************************************************************
 * FUNCTION
 *  mmi_scr_locker_start_timer
 * DESCRIPTION
 *  This function starts the screen locker timer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_scr_locker_start_timer(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_scr_saver_restart_timer
 * DESCRIPTION
 *  This function restarts the screen locker timer. Screen locker will only
 *  restart the timer if it is present.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_scr_locker_restart_timer(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_scr_locker_stop_timer
 * DESCRIPTION
 *  This function stops the screen locker timer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_scr_locker_stop_timer(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_scr_locker_suspend
 * DESCRIPTION
 *  This function suspends the screen locker. Specifically, it suspends the
 *  timer if timer is running. If the handset is already in the locked state,
 *  it will unlock the keypad and touch screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_scr_locker_suspend(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_scr_locker_resume
 * DESCRIPTION
 *  This function resumes the screen locker. Specifically, it resumes the timer.
 *  If the handset was in the locked state before, it will lock the keypad and
 *  touch screen again.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_scr_locker_resume(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_scr_locker_is_launched
 * DESCRIPTION
 *  This function check if the screen locker has launched, this externed for Java (Teng Fu).
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL mmi_scr_locker_is_launched(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_scr_locker_is_locked
 * DESCRIPTION
 *  This function check if the handset is locked by the screen locker.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL mmi_scr_locker_is_locked(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_scr_locker_get_type
 * DESCRIPTION
 *  This function returns the type of the screen locker if the handset is
 *  locked. Note that this function does not consider if the locker is suspend.
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_scr_locker_type_enum. If handset is not locked, return
 *  MMI_SCR_LOCKER_TYPE_INVALID.
 *****************************************************************************/
extern mmi_scr_locker_type_enum mmi_scr_locker_get_type(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_scr_locker_launch
 * DESCRIPTION
 *  This function launches the screen locker.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_scr_locker_launch(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_scr_locker_launch_ex
 * DESCRIPTION
 *  This function launches the specified screen locker.
 * PARAMETERS
 *  type        : [IN]      Screen locker type
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_scr_locker_launch_ex(mmi_scr_locker_type_enum type);


/*****************************************************************************
 * FUNCTION
 *  mmi_scr_locker_close
 * DESCRIPTION
 *  This function closes the screen locker if it is present.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_scr_locker_close(void);


/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  mmi_scr_locker_turn_on_backlight
 * DESCRIPTION
 *  This function turns on the backlight. If the screen locker is on, the
 *  backlight should be in half mode. (Obsolete)
 *
 *  TODO 1:
 *  If touch screen can provide the pen event on callback manager, this API
 *  should be internal used only.
 *
 *  TODO 2:
 *  Framework should consider to handle the half mode backlight by themself. It
 *  does not make sense that screen locker should help to turn on the backlight.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_scr_locker_turn_on_backlight(void);

#if defined(__MMI_AUTO_KEYPAD_LOCK__)
//extern mmi_ret mmi_scr_locker_secset_menu_proc(mmi_event_struct *evt);
extern void mmi_scr_locker_screen_auto_lock_entry(MMI_ID parent_gid);
#ifndef __MMI_SCREEN_LOCK_CLASSIC_NEPTUNE_LIKE_BWUI__
extern void mmi_scr_locker_screen_auto_lock_set_hint(void);
#endif
#endif

/* DOM-NOT_FOR_SDK-END */


#endif /* SCR_LOCKER_GPROT_H */

