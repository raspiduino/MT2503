/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * custom_events_notify.h
 *
 * Project:
 * --------
 *   MAUI
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
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _CUSTOM_EVENTS_NOTIFY_H
#define _CUSTOM_EVENTS_NOTIFY_H

#include "mmi_frm_gprot.h"
//#include "SettingProfileEnum.h"
#include "ProfilesSrvGprot.h"

/* RHR header */
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "MMIDataType.h"
#include "NotificationGprot.h"
    
/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MMI_POPUP_DURATION_DEFAULT_TIME     (2000)
#define MMI_POPUP_DURATION_INFINITE_TIME    (-1)
#define MMI_NO_DURATION_TIME                (0)

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
/* DOM-NOT_FOR_SDK-BEGIN */

/* This struct contain related configuration information of notification */
typedef struct
{
  mmi_event_notify_enum event_id;
    /* User could configure different behavior of notification at different scenario */
    mmi_scenario_id scenario_id;
    srv_prof_tone_enum tone_id;
  U16 img_id;
  S32 duration;
    mmi_nmgr_behavior_enum behavior;    /* Define behavior of screen, sound, vibrator, backlight */
} mmi_events_notify_struct;

typedef struct
{
    mmi_event_notify_enum event_id;
    srv_prof_tone_enum tone_id;
    U16 img_id;
    U32 duration;
} mmi_events_op_notify_struct;
/* DOM-NOT_FOR_SDK-END */

typedef struct
{
    mmi_scenario_id scenario_id;
    mmi_scen_attr_prio_enum notify_priority;
} mmi_scenario_attribute_struct;

/*****************************************************************************
 * FUNCTION
 *  mmi_get_event_based_sound
 * DESCRIPTION
 *  Get tone based popup event from table.
 * PARAMETERS
 *  event_id      : [IN]     Popup event enum   
 * RETURNS
 *  tone enum values
 *****************************************************************************/
extern srv_prof_tone_enum mmi_get_event_based_sound(mmi_event_notify_enum event_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_get_event_based_image
 * DESCRIPTION
 *  Get image based popup event from table.
 * PARAMETERS
 *  event_id      : [IN]			Popup event enum
 * RETURNS
 *  image id.
 *****************************************************************************/
extern U16 mmi_get_event_based_image(mmi_event_notify_enum event_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_get_event_based_duration
 * DESCRIPTION
 *  Get duration based popup event from table.
 * PARAMETERS
 *  event_id      [IN]				Popup event enum
 * RETURNS
 *  duration time.
 *****************************************************************************/
extern U32 mmi_get_event_based_duration(mmi_event_notify_enum event_id);

/* DOM-NOT_FOR_SDK-BEGIN */
/******************************************************************************
 *
 * below is for interrupt popup event defined in Framework
 *
 *****************************************************************************/
typedef struct
{
   mmi_frm_int_enum int_event_id;
   srv_prof_tone_enum tone_id;
   U16 img_id;
   U32 duration;
} mmi_int_events_notify_struct;
extern srv_prof_tone_enum mmi_get_int_event_based_sound(mmi_frm_int_enum int_event_id);
extern U16 mmi_get_int_event_based_image(mmi_frm_int_enum int_event_id);
extern U32 mmi_get_int_event_based_duration(mmi_frm_int_enum int_event_id);

extern const mmi_events_notify_struct *mmi_nmgr_get_event_notify_info(mmi_event_notify_enum event_id, mmi_scenario_id active_scen_id);
extern mmi_scen_attr_prio_enum mmi_get_scenario_default_prio(mmi_scenario_id scenario_id);

#endif /* _CUSTOM_EVENTS_NOTIFY_H */

