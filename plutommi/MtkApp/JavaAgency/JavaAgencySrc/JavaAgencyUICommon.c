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
 *   JavaAgencyUICommon.c
 *
 * Project:
 * --------
 *   Maui_Software
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

#ifdef __J2ME__

#include "MMI_include.h"

#include "jui_interface.h"
#include "JavaAgencyUICommon.h"

/* added for status icon bar being */
#include "jam_internal.h"
#include "TimerEvents.h"
#include "MMITimer.h"
#include "wgui_status_icon_bar.h"
#include "wgui_categories_util.h"
/* added for status icon bar end */

#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
#endif 

static mmi_java_ui_common_add_extra_symbol_callback add_symbol_callback[MMI_JAVA_UI_COMMON_SYMBOL_CALLBACK_MAX_NUM];
static mmi_java_ui_common_is_need_add_extra_symbol_callback
    is_need_add_symbol_callback[MMI_JAVA_UI_COMMON_SYMBOL_CALLBACK_MAX_NUM];

static kal_bool mmi_java_ui_common_display_bg_audio_icon[JUI_MVM_SUPPORT_VM_NUM];

extern void jui_widget_update_fullscreen_status_icons(void * msg);
extern void wgui_status_icon_bar_update(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_common_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_ui_common_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(
        (PsFuncPtr) mmi_java_ui_common_touch_feedback_play_handler,
        MSG_ID_MMI_JAVA_UI_TOUCH_FEEDBACK_PLAY_REQ);
    SetProtocolEventHandler(
        (PsFuncPtr) mmi_java_ui_common_update_mmi_status_icon,
        MSG_ID_MMI_JAVA_UI_MMI_STATUS_ICON_UPDATE_REQ);
    SetProtocolEventHandler(
        (PsFuncPtr) mmi_java_ui_common_update_mmi_status_audio_icon,
        MSG_ID_MMI_JAVA_UI_MMI_STATUS_ICON_UPDATE_RSP);

    SetProtocolEventHandler(
        (PsFuncPtr) jui_widget_update_fullscreen_status_icons,
        MSG_ID_MMI_JAVA_UI_JAVA_STATUS_ICON_UPDATE_REQ);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_common_add_extra_symbol
 * DESCRIPTION
 *  Add extra symbols into symbol table
 * CALLS
 *  
 * PARAMETERS
 *  out         [?]         [?]         [?]
 *  out_max     [IN]        
 *  in          [IN]        
 *  in_max      [IN]        
 * RETURNS
 *  S32         numbers of symbols to add
 *****************************************************************************/
kal_int32 mmi_java_ui_common_add_extra_symbol(kal_uint8 *out, kal_int32 out_max, kal_uint8 **in, kal_int32 in_max)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < in_max; i++)
    {
        memcpy(out + i * 4, *(in + i), 4);
    }

    for (i = 0; i < MMI_JAVA_UI_COMMON_SYMBOL_CALLBACK_MAX_NUM; i++)
    {
        if (is_need_add_symbol_callback[i] != NULL && is_need_add_symbol_callback[i] ())
        {
            ASSERT(add_symbol_callback[i] != NULL);
            return add_symbol_callback[i] (out, out_max, in, in_max);
        }
    }

    return in_max;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_common_register_add_extra_symbol_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  callback        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mmi_java_ui_common_register_add_extra_symbol_callback(mmi_java_ui_common_add_extra_symbol_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_JAVA_UI_COMMON_SYMBOL_CALLBACK_MAX_NUM; i++)
    {
        if (add_symbol_callback[i] == NULL)
        {
            add_symbol_callback[i] = callback;
            return KAL_TRUE;
        }
    }

    return KAL_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_common_unregister_add_extra_symbol_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  callback        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mmi_java_ui_common_unregister_add_extra_symbol_callback(mmi_java_ui_common_add_extra_symbol_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_JAVA_UI_COMMON_SYMBOL_CALLBACK_MAX_NUM; i++)
    {
        if (add_symbol_callback[i] == callback)
        {
            add_symbol_callback[i] = NULL;
            return KAL_TRUE;
        }
    }

    return KAL_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_common_register_is_need_add_extra_symbol_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  callback        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool
mmi_java_ui_common_register_is_need_add_extra_symbol_callback(
    mmi_java_ui_common_is_need_add_extra_symbol_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_JAVA_UI_COMMON_SYMBOL_CALLBACK_MAX_NUM; i++)
    {
        if (is_need_add_symbol_callback[i] == NULL)
        {
            is_need_add_symbol_callback[i] = callback;
            return KAL_TRUE;
        }
    }

    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_common_unregister_is_need_add_extra_symbol_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  callback        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool
mmi_java_ui_common_unregister_is_need_add_extra_symbol_callback(
    mmi_java_ui_common_is_need_add_extra_symbol_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_JAVA_UI_COMMON_SYMBOL_CALLBACK_MAX_NUM; i++)
    {
        if (is_need_add_symbol_callback[i] == callback)
        {
            is_need_add_symbol_callback[i] = NULL;
            return KAL_TRUE;
        }
    }

    return KAL_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_common_update_mmi_status_audio_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_ui_common_update_mmi_status_audio_icon(void *msg)
{

#ifdef J2ME_SUPPORT_BACKGROUND
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_ui_common_update_status_icon_req_struct *req;
    kal_bool vm_id[JUI_MVM_SUPPORT_VM_NUM];
    kal_int32 index = 0;
    kal_bool need_update = KAL_FALSE;
    kal_bool display_bg_audio_icon = KAL_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg != NULL);
    req = (mmi_java_ui_common_update_status_icon_req_struct*) msg;
    
    ASSERT( req->vm_id >= 0 && req->vm_id < JUI_MVM_SUPPORT_VM_NUM);

	if(jam_mvm_is_vm_support_bg(req->vm_id))
	{

        if (req->is_reset)
        {
            for (index = 0; index < JUI_MVM_SUPPORT_VM_NUM ; index ++)
            {
                mmi_java_ui_common_display_bg_audio_icon[index] = KAL_FALSE;
            }
        }
        else
        {
            mmi_java_ui_common_display_bg_audio_icon[req->vm_id] = req->is_display_icon;
        }
    
        jam_mvm_get_bg_running_vm(vm_id);
    
        for(index = 0; index < JUI_MVM_SUPPORT_VM_NUM ; index ++)
        {
            if(vm_id[index] == KAL_TRUE)
            {
                need_update = KAL_TRUE;
                if(mmi_java_ui_common_display_bg_audio_icon[index] == KAL_TRUE)
                {
                    display_bg_audio_icon = KAL_TRUE;
                    break;
                }
            }
        }
        
        if(need_update)
        {
            if (display_bg_audio_icon)
            {
                wgui_status_icon_bar_reset_icon_display(STATUS_ICON_JAVA_BG_VM);
                wgui_status_icon_bar_set_icon_display(STATUS_ICON_JAVA_BG_VM_AUDIO);
            }
            else
            {
                wgui_status_icon_bar_reset_icon_display(STATUS_ICON_JAVA_BG_VM_AUDIO);
                wgui_status_icon_bar_set_icon_display(STATUS_ICON_JAVA_BG_VM);
            }
            StartTimer(JUI_UPDATE_STATUS_ICON, 1, wgui_status_icon_bar_update);
        }

	}
#endif /* J2ME_SUPPORT_BACKGROUND */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_common_update_mmi_status_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_ui_common_update_mmi_status_icon(void *msg)
{
#ifdef J2ME_SUPPORT_BACKGROUND
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_ui_common_update_status_icon_req_struct *req;
    kal_bool vm_id[JUI_MVM_SUPPORT_VM_NUM];
    kal_int32 index;
    kal_bool display_bg_audio_icon = KAL_FALSE;
    kal_bool should_display_icon = KAL_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg != NULL);
    req = (mmi_java_ui_common_update_status_icon_req_struct*) msg;

    if(jam_mvm_is_vm_support_bg(req->vm_id))
    {
        if (!req->is_display_icon)
        {
            mmi_java_ui_common_display_bg_audio_icon[req->vm_id] = KAL_FALSE;
        }
    
        jam_mvm_get_bg_running_vm(vm_id);
    
        for(index = 0; index < JUI_MVM_SUPPORT_VM_NUM ; index ++)
        {
            if(vm_id[index] == KAL_TRUE)
            {
                should_display_icon = KAL_TRUE;
                if(mmi_java_ui_common_display_bg_audio_icon[index] == KAL_TRUE)
                {
                    display_bg_audio_icon = KAL_TRUE;
                    break;
                }
            }
        }
        
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_JAVA_BG_VM);
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_JAVA_BG_VM_AUDIO);
    
        if (should_display_icon)
        {
            if (display_bg_audio_icon)
            {
                wgui_status_icon_bar_reset_icon_display(STATUS_ICON_JAVA_BG_VM);
                wgui_status_icon_bar_set_icon_display(STATUS_ICON_JAVA_BG_VM_AUDIO);
            }
            else
            {
                wgui_status_icon_bar_reset_icon_display(STATUS_ICON_JAVA_BG_VM_AUDIO);
                wgui_status_icon_bar_set_icon_display(STATUS_ICON_JAVA_BG_VM);
            }
        }
    
        wgui_status_icon_bar_update();

    }
#endif /* J2ME_SUPPORT_BACKGROUND */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_common_reset_mmi_status_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_ui_common_reset_mmi_status_icon(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(vm_id >=0 && vm_id < JUI_MVM_SUPPORT_VM_NUM);
    mmi_java_ui_common_display_bg_audio_icon[vm_id] = KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_common_touch_feedback_play_handler
 * DESCRIPTION
 *  play touch feedback,this MUST be invoked in MMI Task
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_ui_common_touch_feedback_play_handler(void *msg)
{
#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_TOUCH_FEEDBACK_SUPPORT__ */ /* #ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__   */
}

#endif /* __J2ME__ */ 

