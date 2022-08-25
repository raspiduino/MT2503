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
 *  IdleRecentEvent.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the recent events.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN__

/* Pluto MMI headers: */
#include "CallLogGprot.h"
#include "MessagesMiscell.h"
#include "MMSAppInterfaceGprot.h"
#include "IdleRecentEventGprot.h"


/* Venus MMI headers: */
#include "ui_core\base\vfx_base.h"
#include "HomeScreen\vadp_p2v_hs_widget_recent_event.h"

// auto add by kw_check begin
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "custom_mmi_default_value.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
// auto add by kw_check end 

/*
 * Event query function config table:
 */
static const mmi_hs_adv_func_t 
g_recent_event_cfg_tbl[MMI_HS_RECENT_EVENT_NUM] = 
{
    /* MMI_HS_RECENT_EVENT_MISSED_CALL: missed call */
    mmi_clog_hs_re_query_data,

#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
#endif

    /* MMI_HS_RECENT_EVENT_NEW_SMS: new SMS */
    mmi_msg_hs_get_sms_recent_event,
    
#ifdef __MMI_MMS_2__    
    /* MMI_HS_RECENT_EVENT_NEW_MMS: new MMS */
    mmi_umms_op_hs_get_recent_mms,
#endif /* __MMI_MMS_2__ */
};


/*****************************************************************************
 * FUNCTION
 *  mmi_hs_recent_event_answer
 * DESCRIPTION
 *  This function takes the user to write the message.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hs_recent_event_answer(
        mmi_hs_recent_event_enum type,
        mmi_hs_result_enum result,
        S32 num_of_event,
        mmi_hs_recent_event_struct *recent_event,
        mmi_hs_key_cbf_t key_hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_read[MMI_HS_MAX_RECENT_EVENT_NUM];
    PS8 subject[MMI_HS_MAX_RECENT_EVENT_NUM];
    MYTIME *time[MMI_HS_MAX_RECENT_EVENT_NUM];
    void *user_data[MMI_HS_MAX_RECENT_EVENT_NUM];
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_MMI_IDLE_RE_ANS, type, result);

    if (result == MMI_HS_RESULT_NOT_MODIFIED ||
        result == MMI_HS_RESULT_NOT_READY)
    {
        return;
    }
    
    MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_MMI_IDLE_RE_ANS_DETAIL, num_of_event);

    /* Fail-safe. Make sure the memory not corrupted even if APP provides too
       many events than what we want. */
    if (num_of_event >= MMI_HS_MAX_RECENT_EVENT_NUM)
    {
        num_of_event = MMI_HS_MAX_RECENT_EVENT_NUM;
    }

    /* Notify to refresh the data. */
    for (i = 0; i < num_of_event; i++)
    {
        is_read[i]   =  recent_event[i].is_read;
        subject[i]   =  recent_event[i].subject;
        time[i]      = &recent_event[i].time;
        user_data[i] =  recent_event[i].user_data;
    }

    vadp_p2v_hs_widget_recent_event_changed(
        type,
        key_hdlr,
        num_of_event,
        is_read,
        subject,
        time,
        user_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hs_is_on_recent_event
 * DESCRIPTION
 *  This function checks whether the recent event is shown.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL mmi_hs_is_on_recent_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hs_recent_event_query
 * DESCRIPTION
 *  This function queries the recent events.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hs_recent_event_query(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_HS_RECENT_EVENT_NUM; i++)
    {
        if (g_recent_event_cfg_tbl[i])
        {
            g_recent_event_cfg_tbl[i](MMI_HS_MAX_RECENT_EVENT_NUM);
        }
    }
}
#endif /* __MMI_VUI_HOMESCREEN__ */

