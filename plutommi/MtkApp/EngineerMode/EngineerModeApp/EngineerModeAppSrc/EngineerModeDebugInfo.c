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
 *  EngineerModeDebugInfo.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Coding Template header file
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"


/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_include.h"

#ifdef __MMI_ENGINEER_MODE__ 

#include "MMIDataType.h"
    #include "GlobalConstants.h"
    #include "wgui_categories_util.h"
    #include "mmi_frm_history_gprot.h"
    #include "mmi_frm_events_gprot.h"
    #include "GlobalMenuItems.h"
    #include "CustMenuRes.h"
    #include "wgui_categories_list.h"
    #include "GlobalResDef.h"
    #include "kal_general_types.h"
    #include "ex_item.h"
    #include "stdio.h"
    #include "Unicodexdcl.h"
    #include "wgui_categories_text_viewer.h"
    #include "sysconf_statistics.h"
    #include "kal_public_api.h"
    #include "nvram_data_items.h"
    #include "mmi_frm_nvram_gprot.h"
    #include "gui_typedef.h"

#include "CommonScreens.h"

#include "EngineerModeUtil.h"
#include "EngineerModeDef.h"
#include "EngineerModeCommMem.h"
#include "EngineerModeCommUI.h"
#include "EngineerModeDebugInfo.h"
#include "mmi_rp_app_engineermode1_def.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MMI_EM_CAPTION_1    	  (CUI_INLINE_ITEM_ID_BASE+0)
#define MMI_EM_CAPTION_2     	  (CUI_INLINE_ITEM_ID_BASE+1)
#define MMI_EM_TEXT_EDIT_1   	  (CUI_INLINE_ITEM_ID_BASE+2)
#define MMI_EM_TEXT_EDIT_2   	  (CUI_INLINE_ITEM_ID_BASE+3)
#define MMI_EM_STR_SELECT_1  	  (CUI_INLINE_ITEM_ID_BASE+4)
#define MMI_EM_STR_SELECT_2  	  (CUI_INLINE_ITEM_ID_BASE+5)
#define MMI_EM_STR_SELECT_3  	  (CUI_INLINE_ITEM_ID_BASE+6)
#define MMI_EM_STR_DISPLAY_ONLY_1 (CUI_INLINE_ITEM_ID_BASE+7)

/***************************************************************************** 
 * Static Variable
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/


/***************************************************************************** 
 * Local Function
 *****************************************************************************/


/***************************************************************************** 
 * Global Function 
 *****************************************************************************/


#define EM_DEBUG_INFO_LAST_EXCEPTION
/*-----------------------------------------------------------------------------*/
/*---------------------- Debug info -> Last exception  ------------------------*/
/*-----------------------------------------------------------------------------*/
#ifdef __MMI_EM_LAST_EXCEPTION__
extern void nvram_report_last_exception(void *task_name_p, void *type_p, void *time_p, void *status_p);
static void mmi_em_debug_info_last_exception_hdlr(void);

static void mmi_em_debug_info_last_exception_hdlr(void)
{
    kal_char task_name[8];
    exception_type type = INVAID_EXCEPTION;
    ex_rtc_struct time;
    kal_bool status = KAL_FALSE;
    WCHAR display_buf[MMI_EM_DISPLAY_BUF_MAX_LEN] = {0};
    mmi_em_text_viewer_struct info = {0};


	nvram_report_last_exception((void*)&task_name, (void*)&type, (void*)&time, (void*)&status);
	
    if (status)
    {
        kal_wsprintf(
            display_buf,
            "Last Exception: \n Type: %x\n Task: %s\n Time: \n (%2d/%2d) %2d:%2d\n",
            type,
            task_name,
            time.rtc_mon,
            time.rtc_day,
            time.rtc_hour,
            time.rtc_min);
    }
    else
    {
        kal_wsprintf(display_buf, "No record: \n ");
    }

    info.text = (const WCHAR*)display_buf;
    info.title_id = STR_ID_EM_DEBUG_LAST_EXCEPTION;
	
    mmi_em_show_text_viewer(&info);
}
#endif /*__MMI_EM_LAST_EXCEPTION__*/

#define EM_DEBUG_INFO_SYS_STATS
/*-----------------------------------------------------------------------------*/
/*----------------------- Debug info -> System stats  -------------------------*/
/*-----------------------------------------------------------------------------*/
#if defined(__MMI_EM_DEBUG_INFO_SYS_STATS__)
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
#endif /* #if defined(__MMI_EM_DEBUG_INFO_SYS_STATS__) */


#if defined(__MMI_EM_LAST_EXCEPTION__) || defined(__MMI_EM_DEBUG_INFO_SYS_STATS__)
void mmi_em_debug_info_menu_event_hdlr(cui_menu_event_struct *event)
{
    switch (event->highlighted_menu_id)
    {	
    #ifdef __MMI_EM_LAST_EXCEPTION__
        case MENU_ID_EM_DEBUG_LAST_EXCEPTION:
            mmi_em_debug_info_last_exception_hdlr();
            break;
    #endif /*__MMI_EM_LAST_EXCEPTION__*/
			
    #ifdef __MMI_EM_DEBUG_INFO_SYS_STATS__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
  
    default:
        break;
    }
}
#endif /* defined(__MMI_EM_LAST_EXCEPTION__) || defined(__MMI_EM_DEBUG_INFO_SYS_STATS__)*/
#endif /* __MMI_ENGINEER_MODE__ */

