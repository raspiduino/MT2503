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
 *  ScrSaverGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the SAP of the screen saver application.
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

#ifndef SCR_SAVER_GPROT_H
#define SCR_SAVER_GPROT_H

/****************************************************************************
 * Include
 ****************************************************************************/
#include "MMI_features.h"

#if defined(__MMI_SCREEN_SAVER__)
#include "mmi_rp_app_scr_saver_def.h"
#include "MMIDataType.h"
#include "kal_general_types.h"


/****************************************************************************
 * Enum
 ****************************************************************************/

/* This enum defines the screen saver type. */
typedef enum
{
    /* Display clock. */
    MMI_SCR_SAVER_TYPE_CLOCK,

    /* Display theme. */
    MMI_SCR_SAVER_TYPE_THEME,

    /* Display image or video. */
    MMI_SCR_SAVER_TYPE_MEDIA,

    /* Display time. (partial-on screen saver). */
    MMI_SCR_SAVER_TYPE_TIME,

    /* Total number. */
    MMI_SCR_SAVER_TYPE_TOTAL,

    /* Unspeficied. Screen saver will automatically select a default type. */
    MMI_SCR_SAVER_TYPE_UNSPECIFIED,

    /* Invalid type. */
    MMI_SCR_SAVER_TYPE_INVALID
} mmi_scr_saver_type_enum;


/****************************************************************************
 * Event Structure
 ****************************************************************************/

/* This is the structure for the EVT_ID_SCR_SAVER_ENTER. */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    /* Type of the screen saver. */
    mmi_scr_saver_type_enum type;
} mmi_scr_saver_enter_evt_struct;

/* This is the structure for the EVT_ID_SCR_SAVER_EXIT. */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    /* Type of the screen saver. */
    mmi_scr_saver_type_enum type;
} mmi_scr_saver_exit_evt_struct;


/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_scr_saver_start_timer
 * DESCRIPTION
 *  This function starts the screen saver timer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_scr_saver_start_timer(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_scr_saver_restart_timer
 * DESCRIPTION
 *  This function restarts the screen saver timer. Screen saver will only
 *  restart the timer if it is present.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_scr_saver_restart_timer(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_scr_saver_stop_timer
 * DESCRIPTION
 *  This function stops the screen saver timer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_scr_saver_stop_timer(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_scr_saver_is_active
 * DESCRIPTION
 *  This function check if the screen saver is running.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL mmi_scr_saver_is_active(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_scr_saver_launch
 * DESCRIPTION
 *  This function launches the screen saver.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_scr_saver_launch(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_scr_saver_launch_ex
 * DESCRIPTION
 *  This function launches the specified screen saver.
 * PARAMETERS
 *  type        : [IN]      Dialer type
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_scr_saver_launch_ex(mmi_scr_saver_type_enum type);


/*****************************************************************************
 * FUNCTION
 *  mmi_scr_saver_close
 * DESCRIPTION
 *  This function closes the screen saver.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_scr_saver_close(void);


/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  mmi_scr_saver_date_time_ind_hdlr
 * DESCRIPTION
 *  This function is the date time changed handler. (obsolete)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_scr_saver_date_time_ind_hdlr(void);

/* DOM-NOT_FOR_SDK-END */

#endif /* defined(__MMI_SCREEN_SAVER__) */
#endif /* SCR_SAVER_GPROT_H */
