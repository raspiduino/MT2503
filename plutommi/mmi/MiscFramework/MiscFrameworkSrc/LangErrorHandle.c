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
 *  LangErrorHandle.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is for vector font on memory card error handle
 *
 * Author:
 * -------
 *  
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

/*****************************************************************************
*  Include
*****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_rp_app_font_manager_def.h"
#include "FileMgrSrvGProt.h"
#include "FileManagerGProt.h"
#include "AlertScreen.h"
#include "BootupSrvGprot.h"
/*****************************************************************************
*  External Function
*****************************************************************************/
#if __COSMOS_MMI_PACKAGE__
extern void vcp_font_memory_card_notify_popup(WCHAR *str);
#endif
/*****************************************************************************
*  Local Variables
*****************************************************************************/
typedef enum
{
    EVT_LANG_ERR_MEMORY_CARD_PLUG_OUT,
    EVT_LANG_ERR_MEMORY_CARD_FORMAT,
    EVT_LANG_ERR_END
} lang_error_event_enum;

/*****************************************************************************
*  Local Function
*****************************************************************************/
void mmi_lang_err_memory_card_notify_popup(lang_error_event_enum evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *string = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __COSMOS_MMI_PACKAGE__
    //if(evt == EVT_LANG_ERR_MEMORY_CARD_FORMAT)
        //string = L"Memory card formatted";
    /*else */if(evt == EVT_LANG_ERR_MEMORY_CARD_PLUG_OUT)
        string = L"Memory card removed";

    if(string)
        vcp_font_memory_card_notify_popup(string);
#else
    //if(evt == EVT_LANG_ERR_MEMORY_CARD_FORMAT)
        //string = L"Memory card formatted, please wait!";
    /*else */if(evt == EVT_LANG_ERR_MEMORY_CARD_PLUG_OUT)
        string = L"Memory card removed, please wait!";

    if(string)
        mmi_popup_display(string, MMI_EVENT_WARNING, NULL);
#endif  
}

void mmi_lang_err_silent_reboot_callback(void)
{
    ASSERT(0);
}

mmi_ret mmi_lang_err_memory_card_notify_silent_reboot_hdlr(mmi_event_struct* evt)
{
#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) || defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__) \
    || defined(__MMI_IME_MEMORY_CARD_SUPPORT__) || defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)

    lang_error_event_enum event = EVT_LANG_ERR_END;
    srv_fmgr_notification_dev_plug_event_struct *plug_evt;
    srv_fmgr_notification_format_event_struct *format_evt;
    S32 i;
    
    if (evt->evt_id == EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT ||
        evt->evt_id == EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT)
    {
        format_evt = (srv_fmgr_notification_format_event_struct*)evt;
        if ((format_evt->drv_letter == SRV_FMGR_CARD_DRV) && (format_evt->state == SRV_FMGR_NOTIFICATION_STATE_AFTER))
        {
            event = EVT_LANG_ERR_MEMORY_CARD_FORMAT;
        }
    }
    else if (evt->evt_id == EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT)
    {
        plug_evt = (srv_fmgr_notification_dev_plug_event_struct*)evt;
        for (i = 0; i < plug_evt->count; i++)
        {
            if (plug_evt->drv_letters[i] == SRV_FMGR_CARD_DRV)
            {
                event = EVT_LANG_ERR_MEMORY_CARD_PLUG_OUT;
            }
        }
    }

    if(event != EVT_LANG_ERR_END)
    {
        mmi_lang_err_memory_card_notify_popup(event);
        StartTimer(FONT_SILENT_REBOOT_TIMER, 800, mmi_lang_err_silent_reboot_callback);
    }
#endif

    return MMI_RET_OK;
}

U8 mmi_lang_error_exception_hdlr(void *p)
{
    if (srv_bootup_is_booting())
    {
        mmi_lang_err_silent_reboot_callback();
    }
    
    return MMI_RET_OK;
}

void mmi_lang_error_bootup_exception_reg_hdlr(void)
{
    SetProtocolEventHandler((PsIntFuncPtr)mmi_lang_error_exception_hdlr,  MSG_ID_FMT_MMI_CARD_PLUG_OUT_IND);
}
