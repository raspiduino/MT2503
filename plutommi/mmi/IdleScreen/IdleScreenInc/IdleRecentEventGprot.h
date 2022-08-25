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
 *  IdleRecentEvent.h
 *
 * Project:
 * -------- 
 *  Venus
 *
 * Description:
 * ------------
 *  This file is the header for the adaptation layer from OP11 recent event to
 *  the Venus recent event.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef _MMI_IDLE_RECENT_EVENT_H
#define _MMI_IDLE_RECENT_EVENT_H

#include "MMI_features.h"

#if defined(__MMI_VUI_HOMESCREEN__)

#include "MMIDataType.h"
#include "custom_mmi_default_value.h"

// auto add by kw_check begin
#include "kal_general_types.h"
// auto add by kw_check end 

/**********************************************************************
 * Default constants and values
 **********************************************************************/

/* Max number of data in pop-out menu (for backward compatible only) */
#define MMI_HS_MAX_MENU_DATA_APPOINTMENT_NUM    2
#define MMI_HS_MAX_MENU_DATA_VIP_CONTACT_NUM    5
#define MMI_HS_MAX_MENU_DATA_MISSED_CALL_NUM    2
#define MMI_HS_MAX_MENU_DATA_NEW_SMS_NUM        2
#define MMI_HS_MAX_MENU_DATA_NEW_MMS_NUM        2
#define MMI_HS_MAX_MENU_DATA_NEW_EMAIL_NUM      2

/* Max number of recent events */
#define MMI_HS_MAX_RECENT_EVENT_NUM             10


/**********************************************************************
 * Type definitions
 **********************************************************************/

typedef void (*mmi_hs_key_cbf_t)(U16 key_code, U16 key_type, void *user_data);

typedef void (*mmi_hs_adv_func_t)(S32 num);


/**********************************************************************
 * Enum definitions
 **********************************************************************/

/* Result */
typedef enum
{
    MMI_HS_RESULT_OK,
    MMI_HS_RESULT_NOT_MODIFIED,
    MMI_HS_RESULT_NOT_READY,
    MMI_HS_RESULT_UPDATE
} mmi_hs_result_enum;

/* Recent event type */
typedef enum
{
    MMI_HS_RECENT_EVENT_MISSED_CALL,
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif
    MMI_HS_RECENT_EVENT_SMS,
#ifdef __MMI_MMS_2__
    MMI_HS_RECENT_EVENT_MMS,
#endif
    MMI_HS_RECENT_EVENT_NUM
} mmi_hs_recent_event_enum;


/**********************************************************************
 * Structure definitions
 **********************************************************************/

/* Recent event structure */
typedef struct
{
    MMI_BOOL    is_read;
    U16         icon;
    MYTIME      time;
    PS8         subject;
    void       *user_data;
} mmi_hs_recent_event_struct;


/**********************************************************************
 * External Interfaces
 **********************************************************************/

extern void
mmi_hs_recent_event_answer(
        mmi_hs_recent_event_enum type,
        mmi_hs_result_enum result,
        S32 num_of_event,
        mmi_hs_recent_event_struct *recent_event,
        mmi_hs_key_cbf_t key_hdlr);

extern MMI_BOOL
mmi_hs_is_on_recent_event(void);

extern void 
mmi_hs_recent_event_query(void);

#endif /* __MMI_VUI_HOMESCREEN__ */
#endif /* _MMI_IDLE_RECENT_EVENT_H */

