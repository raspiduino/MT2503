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
 *  IdleGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the SAP of the idle application.
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

#ifndef IDLE_GPROT_H
#define IDLE_GPROT_H


/****************************************************************************
 * Include
 ****************************************************************************/
#if !defined(__IOT__)
#include "mmi_rp_app_idle_def.h"
#endif

// auto add by kw_check begin
#include "MMIDataType.h"
#include "kal_general_types.h"
// auto add by kw_check end 


/****************************************************************************
 * Define
 ****************************************************************************/

#define MMI_IDLE_NW_NAME_MAX_STR_LEN         (28)

#define MMI_IDLE_NW_NAME_MAX_BUF_SIZE        (MMI_IDLE_NW_NAME_MAX_STR_LEN + 1)


/****************************************************************************
 * Enum
 ****************************************************************************/

/* Idle type. */
typedef enum
{
    /* Classic home screen. */
    MMI_IDLE_TYPE_CLASSIC,

    /* OP11 home screen v2.5. */
    MMI_IDLE_TYPE_OP11V25,

    /* OP11 home screen v3.2. */
    MMI_IDLE_TYPE_OP11V32,

    /* Swatch IDLE. */
    MMI_IDLE_TYPE_SWATCH,

    /* Applist Launcher. */
    MMI_IDLE_TYPE_APPLIST,
    
    /* Venus home screen. */
    MMI_IDLE_TYPE_SHELL,

	/* Key Launcher. */
    MMI_IDLE_TYPE_KEYLAUNCHER,

    /* Launcher. */
    MMI_IDLE_TYPE_LAUNCHER,

    /* Unspecified. Idle APP will automatically select a type. */
    MMI_IDLE_TYPE_UNSPECIFIED,

    /* Invalid type. */
    MMI_IDLE_TYPE_INVALID
} mmi_idle_type_enum;


/****************************************************************************
 * Structure
 ****************************************************************************/
typedef struct
{
    /* Service indication */
    WCHAR   line1[MMI_IDLE_NW_NAME_MAX_BUF_SIZE];
    WCHAR   line2[MMI_IDLE_NW_NAME_MAX_BUF_SIZE];
} mmi_idle_service_indication_struct;


/****************************************************************************
 * Event Structure
 ****************************************************************************/

/* This is the structure for the EVT_ID_IDLE_ENTER. */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    /* Type of the idle screen. */
    mmi_idle_type_enum type;
} mmi_idle_enter_evt_struct;

/* This is the structure for the EVT_ID_IDLE_EXIT. */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    /* Type of the idle screen. */
    mmi_idle_type_enum type;
} mmi_idle_exit_evt_struct;

/* This is the structure for the EVT_ID_IDLE_BEFORE_GROUP_ENTER. */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    /* Type of the idle screen. */
    mmi_idle_type_enum type;
} mmi_idle_before_group_enter_evt_struct;

/* This is the structure for the EVT_ID_IDLE_GROUP_ENTER. */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    /* Type of the idle screen. */
    mmi_idle_type_enum type;
} mmi_idle_group_enter_evt_struct;

/* This is the structure for the EVT_ID_IDLE_BEFORE_GROUP_EXIT. */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    /* Type of the idle screen. */
    mmi_idle_type_enum type;
} mmi_idle_before_group_exit_evt_struct;

/* This is the structure for the EVT_ID_IDLE_GROUP_EXIT. */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    /* Type of the idle screen. */
    mmi_idle_type_enum type;
} mmi_idle_group_exit_evt_struct;

/* This is the structure for the EVT_ID_IDLE_LAUNCHED. */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    /* Type of the idle screen. */
    mmi_idle_type_enum type;
} mmi_idle_launched_evt_struct;


/****************************************************************************
 * Function
 ****************************************************************************/

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  mmi_idle_main_evt_hdlr
 * DESCRIPTION
 *  This function is the main event handler.
 * PARAMETERS
 *  event               : [IN]          Event
 * RETURNS
 *  void
 *****************************************************************************/
extern mmi_ret mmi_idle_main_evt_hdlr(mmi_event_struct *event);

/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_launch
 * DESCRIPTION
 *  This function launches the idle screen. This API is mainly used by bootup
 *  application to launch idle application after booting is completed. The 
 *  'base_group_id' indicates the group ID that the idle group will be inserted
 *  after it.
 * PARAMETERS
 *  mmi_id              : [IN]          Base group ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_idle_launch(mmi_id base_group_id);


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_display
 * DESCRIPTION
 *  This function displays the idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_idle_display(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_show_category
 * DESCRIPTION
 *  This function shows the category screen of the idle. Generally, this is used
 *  to solve some complication that other APP will need the idle screen as their
 *  background.
 * 
 *  PLEASE DO NOT USE THIS FUNCTION, UNLESS YOU KNOW WHAT YOU ARE DOING.
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_idle_show_category(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_notify_event
 * DESCRIPTION
 *  This function notifies the user about the events registered on the idle.
 * PARAMETERS
 *  void
 * RETURNS
 *  On available, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL mmi_idle_notify_event(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_update_service_area
 * DESCRIPTION
 *  This function updates the text area on the idle screen.
 *
 *  This API is used by other APP to actively update the idle text, including
 *
 *  - Operator name
 *  - SAT text
 *  - Audio player song name
 *  - FM radio channel name
 *  - etc.
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  On available, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL mmi_idle_update_service_area(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_get_group_id
 * DESCRIPTION
 *  This function gets the idle group ID.
 * PARAMETERS
 *  void
 * RETURNS
 *  Idle group ID.
 *****************************************************************************/
extern mmi_id mmi_idle_get_group_id(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_is_active
 * DESCRIPTION
 *  This function checks if idle screen is active.
 * PARAMETERS
 *  void
 * RETURNS
 *  On active, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL mmi_idle_is_active(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_is_group_active
 * DESCRIPTION
 *  This function checks if the idle group is active. For example, on the unread
 *  message notification screen on the idle, this function returns MMI_TRUE, but
 *  mmi_idle_is_active returns MMI_FALSE.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL mmi_idle_is_group_active(void);


/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  mmi_idle_disable_lock_by_end_key
 * DESCRIPTION
 *  This function disables the idle to lock handset by END key. This API is only
 *  used by SSC.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_idle_disable_lock_by_end_key(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_get_service_indication_string
 * DESCRIPTION
 *  This function gets the service indication string of the specified SIM in the idle.
 *  There has two lines information, 1st  line is operator name, 2nd  line is service provider name
 *  2nd line will be replaced if extra information is needed because of feature option or setting, 
 *  Extra information includes cell info, homezone, owner number .
 * PARAMETERS
 *  sim                   : [IN]    SIM ID
 *  service_indication    : [OUT]   mmi_idle_service_indication_struct
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_idle_get_service_indication_string(
    mmi_sim_enum sim,
    mmi_idle_service_indication_struct *service_indication
);

/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_sublcd_display
 * DESCRIPTION
 *  This function displays the idle screen on the sub-LCD.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_idle_sublcd_display(void);

extern MMI_BOOL mmi_idle_sublcd_is_active(void);

#endif /* IDLE_GPROT_H */

