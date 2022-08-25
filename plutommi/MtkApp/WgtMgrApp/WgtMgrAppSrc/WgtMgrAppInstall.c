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

/*******************************************************************************
 * Filename:
 * ---------
 * WgtMgrAppInstall.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
/* MMI */
#include "MMI_features.h"

#ifdef __MMI_GADGET_SUPPORT__

/************************************************************************/
/* Include Header                                                       */
/************************************************************************/
#include "MMIDataType.h"
#include "kal_general_types.h"

/* CUI  */
#include "FileMgrCUIGProt.h"

/* Widget Manager Service */
#include "WgtMgrSrvGprot.h"
#include "WgtMgrSrvIprot.h"

/* Widget Manager Application */
#include "WgtMgrAppIprot.h"
#include "mmi_rp_app_wgtmgr_def.h"

#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_popup.h"
#include "CustDataRes.h"
#include "custom_events_notify.h"
#include "wgui_categories_util.h"
#include "AlertScreen.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "app_mem.h"
#include "Unicodexdcl.h"
#include "wgui_categories_text_viewer.h"
#include "GlobalConstants.h"
#include "fs_type.h"
#include "fs_func.h"
#include "FileMgrSrvGProt.h"
#include "ProcedureGprot.h"
#include "gdi_include.h"
#include "mmi_rp_app_bootup_def.h"


/************************************************************************/
/* Structure and Definition                                             */
/************************************************************************/
/* The size of buffer which stores the message displayed to users (unit:bytes) */
#define MMI_WGTMGR_INSTALL_MESSASGE_BUFF_SIZE (24000)

typedef enum
{
    MMI_WGTMGR_INSTALL_NULL,
    MMI_WGTMGR_INSTALL_START,
    MMI_WGTMGR_INSTALL_QUERY,
    MMI_WGTMGR_INSTALL_CONT	
} mmi_wgtmgr_install_state;

/************************************************************************/
/* Internal Function Declaration                                        */
/************************************************************************/
/* screen entry function */
static void mmi_wgtmgr_entry_install_wgt(void);
static void mmi_wgtmgr_entry_installing(void);
#if 0
/* under construction !*/
#endif

/* event proc */
static mmi_ret mmi_wgtmgr_install_proc(mmi_event_struct *evt);

/* install procedure */
//static void mmi_wgtmgr_install_wgt(void);
static void mmi_wgtmgr_select_storage(void);
static void mmi_wgtmgr_select_storage_rsp_hdlr(mmi_event_struct *evt);
static void mmi_wgtmgr_install_wgt_cancel(void);

/* callback functions invoked by Widget Manager Service */
static void mmi_wgtmgr_install_wgt_cont_callback(S16 wgt_id, srv_wgtmgr_install_wgt_result_struct *info, void *user_data);
static void mmi_wgtmgr_install_wgt_finish_callback(srv_wgtmgr_result_enum result, void *user_data);

/* utilities */
static U16 mmi_wgtmgr_translate_error_to_string(srv_wgtmgr_result_enum error);

/* exit function */
static void mmi_wgtmgr_install_exit(void);
static void mmi_wgtmgr_exit_pre_install_wgt(void);

/************************************************************************/
/* Golbal Variable                                                      */
/************************************************************************/
/* the pointer is used to store the information of the widget to install */
static srv_wgtmgr_install_wgt_result_struct *g_mmi_wgtmgr_install_wgt_info_p = NULL;

/* this pointer is used to store the message displayed to users */
static WCHAR *g_mmi_wgtmgr_install_message_p = NULL;

static U8 g_mmi_wgtmgr_install_state = MMI_WGTMGR_INSTALL_NULL;

static U32 g_mmi_wgtmgr_pre_install_wgt_num = 0;

static mmi_frm_proc_id_info_struct g_id_info;

static S16 g_wgt_id = -1;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/************************************************************************/
/* Local Function Definition                                            */
/************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_install_proc
 * DESCRIPTION
 *  This function is receive the screen group event
 * PARAMETERS
 *  evt:  [IN] screen group event
 * RETURNS
 *  MMI_RET_TRUE
 *****************************************************************************/
static mmi_ret mmi_wgtmgr_install_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    { 
        /* sent from File Manager CUI, indicate the storage selected by users  */
        case EVT_ID_CUI_STORAGE_SELECTOR_RESULT:
        {
            mmi_wgtmgr_select_storage_rsp_hdlr(evt);
            break;
        }

        /* sent from Framework when group is deinit */
        case EVT_ID_GROUP_DEINIT:
        {
            mmi_wgtmgr_install_exit();
            break;
        }

        case EVT_ID_SRV_WGTMGR_FINISH_PRE_INSATLL_WIDGET_IND:
        {
            mmi_frm_proc_notify_completed(g_id_info);
            break;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_entry_installing
 * DESCRIPTION
 *  This function is used to display installing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_entry_installing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(GRP_ID_WGTMGR_INSTALL, 
                           SCR_ID_WGTMGR_INSTALLING, 
                           NULL, 
                           mmi_wgtmgr_entry_installing, 
                           MMI_FRM_FULL_SCRN) == MMI_TRUE)
    {
    #if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_MAINLCD_320X480__)
        ShowCategory66Screen(
          STR_GLOBAL_INSTALL,
          0,    
          0,
          0,
          0,
          0,
          (U8*) GetString(STR_ID_WGTMGR_INSTALLING),
          mmi_get_event_based_image(MMI_EVENT_PROGRESS),
          NULL);

    #else
        ShowCategory66Screen(
          STR_GLOBAL_INSTALL,
          IMG_ID_WGTMGR_APP,
          0,
          0,
          0,
          0,
          (U8*) GetString(STR_ID_WGTMGR_INSTALLING),
          mmi_get_event_based_image(MMI_EVENT_PROGRESS),
          NULL);
    #endif
    
        /* clear endkey handler */
        mmi_wgtmgr_clear_endkey_hdlr();
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_entry_installing
 * DESCRIPTION
 *  This function is used to display installing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_entry_pre_installing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(GRP_ID_BOOTUP, 
                           SCR_ID_WGTMGR_INSTALLING, 
                           NULL, 
                           mmi_wgtmgr_entry_pre_installing, 
                           MMI_FRM_FULL_SCRN) == MMI_TRUE)
    {

        gdi_layer_clear(0);
        ShowCategory66Screen(
          0,
          0,	
          0,
          0,
          0,
          0,
          (U8*) GetString(STR_ID_WGTMGR_INSTALLING_WIDGETS),
          mmi_get_event_based_image(MMI_EVENT_PROGRESS),
          NULL);


        /* clear endkey handler */
        ClearKeyHandler(KEY_END, KEY_EVENT_UP);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_END, KEY_REPEAT);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_install_wgt_finish_callback
 * DESCRIPTION
 *  This function is invoked when installation is finished
 * PARAMETERS
 *  result:  [IN] the result of installation
  * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_install_wgt_finish_callback(srv_wgtmgr_result_enum result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_wgtmgr_install_state != MMI_WGTMGR_INSTALL_CONT)
    {
        return;
    }

    if (mmi_frm_group_is_in_top_scope(GRP_ID_WGTMGR_INSTALL) == MMI_TRUE)
    {
        /* close details view if re-installing the opened widget */
        widget_close_view_by_id(g_wgt_id);

        if (result == SRV_WGTMGR_RET_OK)
        {
            mmi_popup_display_simple(get_string(STR_ID_WGTMGR_INSTALLED), MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
        }
        else
        {
            U16 ret = mmi_wgtmgr_translate_error_to_string(result);
            mmi_popup_display_simple(get_string(ret), MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
        }
    }
    g_mmi_wgtmgr_install_state = MMI_WGTMGR_INSTALL_NULL;	
    mmi_frm_group_close(GRP_ID_WGTMGR_INSTALL);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_install_wgt_cont_callback
 * DESCRIPTION
 *  This function is invoked after Widget Manager verifies the widget
 * PARAMETERS
 *  result: [IN] the information of the widget
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_install_wgt_cont_callback(S16 wgt_id, srv_wgtmgr_install_wgt_result_struct *info, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_result_enum ret = info->result;
    g_wgt_id = wgt_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* cancel the installation if the state is abnormal */
    if (g_mmi_wgtmgr_install_state != MMI_WGTMGR_INSTALL_START)
    {
        srv_wgtmgr_install_wgt_cont(SRV_WGTMGR_INSTALL_CANCEL, (srv_wgtmgr_wgt_drive_enum)0, NULL, NULL);
        return;		
    }

    /* the widget is valid */
    if (ret == SRV_WGTMGR_RET_OK || ret == SRV_WGTMGR_RET_OLD_VERSION ||
        ret == SRV_WGTMGR_RET_NEW_VERSION || ret == SRV_WGTMGR_RET_ALREADY_INSTALLED)
    {
        g_mmi_wgtmgr_install_state = MMI_WGTMGR_INSTALL_QUERY;

        /* save the info */
        if (g_mmi_wgtmgr_install_wgt_info_p == NULL)
        {
            g_mmi_wgtmgr_install_wgt_info_p = 
                (srv_wgtmgr_install_wgt_result_struct *)OslMalloc(sizeof(srv_wgtmgr_install_wgt_result_struct));

            if (g_mmi_wgtmgr_install_wgt_info_p == NULL)
            {
                MMI_ASSERT(0);
            }
        }			

        /* store the info for later use */
        kal_mem_cpy(g_mmi_wgtmgr_install_wgt_info_p, info, sizeof(srv_wgtmgr_install_wgt_result_struct));

        /* display the screen to confirm with users */
        mmi_wgtmgr_entry_install_wgt();
    }
    else
    {
        /* error happens, display popup and close screen group */
        if (mmi_frm_group_is_in_top_scope(GRP_ID_WGTMGR_INSTALL) == MMI_TRUE)
        {
            U16 error_string = mmi_wgtmgr_translate_error_to_string(ret);
            mmi_popup_display_simple(get_string(error_string), MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
        }
        g_mmi_wgtmgr_install_state = MMI_WGTMGR_INSTALL_NULL;
        mmi_frm_group_close(GRP_ID_WGTMGR_INSTALL);

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_entry_install_wgt
 * DESCRIPTION
 *  This function is the entry function of intall screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_exit_install_wgt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_wgtmgr_install_message_p)
   	{
        applib_mem_screen_free(g_mmi_wgtmgr_install_message_p);
        g_mmi_wgtmgr_install_message_p = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_entry_install_wgt
 * DESCRIPTION
 *  This function is the entry function of intall screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_entry_install_wgt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR* message = g_mmi_wgtmgr_install_message_p;
    srv_wgtmgr_install_wgt_result_struct *info_p = g_mmi_wgtmgr_install_wgt_info_p;
    srv_wgtmgr_result_enum ret = info_p->result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(GRP_ID_WGTMGR_INSTALL, SCR_ID_WGTMGR_INSTALL, mmi_wgtmgr_exit_install_wgt, mmi_wgtmgr_entry_install_wgt, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }

    /* prepare the message buffer */
    if (message == NULL)
    {
        message = (WCHAR*)applib_mem_screen_alloc(MMI_WGTMGR_INSTALL_MESSASGE_BUFF_SIZE);

        if (message == NULL)
        {
            MMI_ASSERT(0);
        }
        g_mmi_wgtmgr_install_message_p = message;
    }

    /* prepare the message to display */
    if (ret == SRV_WGTMGR_RET_OK) 
    {
        mmi_wcscpy(message, (const WCHAR*)get_string(STR_ID_WGTMGR_QUERY_FOR_INSTALL));
        mmi_wcscat(message, (const WCHAR*)L"\n\n");
        mmi_wcscat(message, (const WCHAR*)get_string(STR_ID_WGTMGR_WGT_NAME));
        mmi_wcscat(message, (const WCHAR*)info_p->wgt_name);
        mmi_wcscat(message, (const WCHAR*)L"\n");
        mmi_wcscat(message, (const WCHAR*)get_string(STR_ID_WGTMGR_VERSION));
        mmi_wcscat(message, (const WCHAR*)info_p->wgt_version_install);
        mmi_wcscat(message, (const WCHAR*)L"\n");
        mmi_wcscat(message, (const WCHAR*)get_string(STR_ID_WGTMGR_WGT_AUTHOR));
        mmi_wcscat(message, (const WCHAR*)info_p->wgt_author);
        mmi_wcscat(message, (const WCHAR*)L"\n");
        mmi_wcscat(message, (const WCHAR*)get_string(STR_ID_WGTMGR_WGT_COPYRIGHT));
        mmi_wcscat(message, (const WCHAR*)info_p->wgt_copyright);
        mmi_wcscat(message, (const WCHAR*)L"\n");
    }
    else
    {
        U16 info_string;

        if (ret == SRV_WGTMGR_RET_NEW_VERSION)
        {
            info_string = STR_ID_WGTMGR_NEW_VERSION;			
        }
        else if (ret == SRV_WGTMGR_RET_OLD_VERSION)
        {
            info_string = STR_ID_WGTMGR_OLD_VERSION;
        }
        else
        {
            info_string = STR_ID_WGTMGR_ALREADY_INSTALLED;
        }
        mmi_wcscpy(message, (const WCHAR*)get_string(info_string));
        mmi_wcscat(message, (const WCHAR*)get_string(STR_ID_WGTMGR_REPLACE_WIDGET));
        mmi_wcscat(message, (const WCHAR*)L"\n\n");
        mmi_wcscat(message, (const WCHAR*)get_string(STR_ID_WGTMGR_WGT_NAME));
        mmi_wcscat(message, (const WCHAR*)info_p->wgt_name);
        mmi_wcscat(message, (const WCHAR*)L"\n");
        mmi_wcscat(message, (const WCHAR*)get_string(STR_ID_WGTMGR_CURRENT_VERSION));
        mmi_wcscat(message, (const WCHAR*)info_p->wgt_version_original);
        mmi_wcscat(message, (const WCHAR*)L"\n");
        mmi_wcscat(message, (const WCHAR*)get_string(STR_ID_WGTMGR_VERSION_FOUND));
        mmi_wcscat(message, (const WCHAR*)info_p->wgt_version_install);
        mmi_wcscat(message, (const WCHAR*)L"\n");
        mmi_wcscat(message, (const WCHAR*)get_string(STR_ID_WGTMGR_WGT_AUTHOR));
        mmi_wcscat(message, (const WCHAR*)info_p->wgt_author);
        mmi_wcscat(message, (const WCHAR*)L"\n");
        mmi_wcscat(message, (const WCHAR*)get_string(STR_ID_WGTMGR_WGT_COPYRIGHT));
        mmi_wcscat(message, (const WCHAR*)info_p->wgt_copyright);
        mmi_wcscat(message, (const WCHAR*)L"\n\n"); 
        mmi_wcscat(message, (const WCHAR*)get_string(STR_ID_WGTMGR_CONTINUE_INSTALL));
    }

    if (mmi_wcslen(message) * 2 > MMI_WGTMGR_INSTALL_MESSASGE_BUFF_SIZE)
    {
        MMI_ASSERT(0);
    }

#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_MAINLCD_320X480__)
    /* show category */
    ShowCategory74Screen(STR_GLOBAL_INSTALL, 
                     0,                 
                     STR_GLOBAL_YES, 
                     0, 
                     STR_GLOBAL_NO, 
                     0, 
                     (U8*)message, 
                     MMI_WGTMGR_INSTALL_MESSASGE_BUFF_SIZE, 
                     NULL);

#else
    /* show category */
    ShowCategory74Screen(STR_GLOBAL_INSTALL, 
                     IMG_ID_WGTMGR_APP, 
                     STR_GLOBAL_YES, 
                     0, 
                     STR_GLOBAL_NO, 
                     0, 
                     (U8*)message, 
                     MMI_WGTMGR_INSTALL_MESSASGE_BUFF_SIZE, 
                     NULL);

#endif

    /* set softkey handler */
#if 0
/* under construction !*/
#endif
    SetLeftSoftkeyFunction(mmi_wgtmgr_select_storage, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_wgtmgr_install_wgt_cancel, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_entry_statement
 * DESCRIPTION
 *  This function is the entry function of intall screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if 0
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
#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_MAINLCD_320X480__)
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
#else
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
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_select_storage
 * DESCRIPTION
 *  This function is to use storage CUI to select the drive to install
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_select_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* create and run storage CUI */
    g_id = cui_storage_selector_create(GRP_ID_WGTMGR_INSTALL, 0, CUI_STORAGE_SELECTOR_DRV_TYPE_ACCESIBLE_ONLY);
    cui_storage_selector_run(g_id);

    /* close the install screen */
    mmi_frm_scrn_close(GRP_ID_WGTMGR_INSTALL, SCR_ID_WGTMGR_INSTALL);
    mmi_frm_scrn_close(GRP_ID_WGTMGR_INSTALL, SCR_ID_WGTMGR_STATEMENT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_select_storage_rsp_hdlr
 * DESCRIPTION
 *  This function is to sort widget with quick sort algorithm
 * PARAMETERS
 *  left:  [IN] left position 
 *  right: [IN] right position
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_select_storage_rsp_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_storage_selector_result_event_struct *param = 
        (cui_storage_selector_result_event_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (param->result > 0) /* user selects a storage */
    {
        /* translate the drive letter to the enum defined by Widget Manager Service */
        srv_wgtmgr_wgt_drive_enum drive = SRV_WGTMGR_DRIVE_PUBLIC;

        if(param->result == SRV_FMGR_CARD_DRV)
        {
            drive = SRV_WGTMGR_DRIVE_MEMORY_CARD;
        }
     
        /* continue the installation */
        srv_wgtmgr_install_wgt_cont(SRV_WGTMGR_INSTALL_CONT, drive, mmi_wgtmgr_install_wgt_finish_callback, NULL);
        g_mmi_wgtmgr_install_state = MMI_WGTMGR_INSTALL_CONT;
    }
    else /* user cancels or error happens */
    {
        mmi_wgtmgr_install_wgt_cancel();
    }

    /* close File Manger CUI */
    cui_storage_selector_close(param->sender_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_install_wgt_cancel
 * DESCRIPTION
 *  This function is to sort widget with quick sort algorithm
 * PARAMETERS
 *  left:  [IN] left position 
 *  right: [IN] right position
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_install_wgt_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_install_wgt_cont(SRV_WGTMGR_INSTALL_CANCEL, (srv_wgtmgr_wgt_drive_enum)0, NULL, NULL);
    g_mmi_wgtmgr_install_state = MMI_WGTMGR_INSTALL_NULL;
    if (mmi_frm_group_is_in_top_scope(GRP_ID_WGTMGR_INSTALL) == MMI_TRUE)
    {
        mmi_popup_display_simple(get_string(STR_ID_WGTMGR_CANCELED), MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
    }
    mmi_frm_group_close(GRP_ID_WGTMGR_INSTALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_translate_error_to_string
 * DESCRIPTION
 *  This function is to translate the error code to string id
 * PARAMETERS
 *  error:  [IN] error code
 * RETURNS
 *  string id 
 *****************************************************************************/
static U16 mmi_wgtmgr_translate_error_to_string(srv_wgtmgr_result_enum error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 error_string;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (error)
    {
        case SRV_WGTMGR_RET_MEM_NOT_ENOUGH:
            error_string = STR_GLOBAL_NOT_ENOUGH_MEMORY;
            break;

		case SRV_WGTMGR_RET_WGT_CORRUPTED:
            error_string = STR_ID_WGTMGR_WIDGET_IS_CORRUPTED;
            break;

        case SRV_WGTMGR_RET_EXCEED_MAX_INSTALLED_NUM:
            error_string = STR_ID_WGTMGR_OVER_MAX_INSTALL;
            break;

        case SRV_WGTMGR_RET_WGT_NOT_VALID:
            error_string = STR_ID_WGTMGR_WIDGET_IS_NOT_VALID;
            break;

        case SRV_WGTMGR_RET_DISK_SPACE_NOT_ENOUGH:
            error_string = STR_ID_WGTMGR_DISK_SPACE_IS_NOT_ENOUGH;
            break;

        default:
            error_string = STR_GLOBAL_ERROR;
            break;
   	}
    return error_string;

}



/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_install_exit
 * DESCRIPTION
 *  This function is to free allocated control buffer 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_install_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* cancel the installation if user presses endkey in query screen */
    if (g_mmi_wgtmgr_install_state == MMI_WGTMGR_INSTALL_QUERY)
    {
        srv_wgtmgr_install_wgt_cont(SRV_WGTMGR_INSTALL_CANCEL, (srv_wgtmgr_wgt_drive_enum)0, NULL, NULL);
    }
    g_mmi_wgtmgr_install_state = MMI_WGTMGR_INSTALL_NULL;

    /* free message buffer if necessary */
    if (g_mmi_wgtmgr_install_message_p != NULL)
    {
        MMI_ASSERT(0);
    }
    g_mmi_wgtmgr_install_message_p = NULL;

    /* free intall info if necessary */
    if (g_mmi_wgtmgr_install_wgt_info_p != NULL)
    {
        OslMfree(g_mmi_wgtmgr_install_wgt_info_p);
        g_mmi_wgtmgr_install_wgt_info_p = NULL;
    }

}



/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_entry_pre_install_wgt
 * DESCRIPTION
 *  This function is invoked when install option is highlighted 
 *  when user browses a widget file in File Manager.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_entry_pre_install_wgt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR message[50];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(GRP_ID_WGTMGR_INSTALL, SCR_ID_WGTMGR_INSTALL, NULL, mmi_wgtmgr_entry_pre_install_wgt, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }

    kal_wsprintf(message, "%d widgets are installed successfully.", g_mmi_wgtmgr_pre_install_wgt_num);

    /* show category */
    ShowCategory74Screen(STR_GLOBAL_INSTALL, 
                         0, 
                         STR_GLOBAL_OK, 
                         0, 
                         0, 
                         0, 
                         (U8*)message, 
                         50, 
                         NULL);

    /* set softkey handler */
    SetLeftSoftkeyFunction(mmi_wgtmgr_exit_pre_install_wgt, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_exit_pre_install_wgt
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_exit_pre_install_wgt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(GRP_ID_WGTMGR_INSTALL);
}


/************************************************************************/
/* Global Function Definition                                                  */
/************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_install_wgt
 * DESCRIPTION
 *  This function is used to start install a widget 
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wgtmgr_install_wgt(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* invoke api of Widget Manager Service */    
    srv_wgtmgr_install_wgt((WCHAR *)filepath, mmi_wgtmgr_install_wgt_cont_callback, NULL);

    /* create screen group */
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_WGTMGR_INSTALL, mmi_wgtmgr_install_proc, NULL);

    /* enter screen group */
    mmi_frm_group_enter(GRP_ID_WGTMGR_INSTALL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    /* display progressive screen since it needs wait for response from Widget Manager Service */
    mmi_wgtmgr_entry_installing();

    g_mmi_wgtmgr_install_state = MMI_WGTMGR_INSTALL_START;

    g_wgt_id = -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_preinstall_widget
 * DESCRIPTION
 *  This function is to preinsatll widget
 * PARAMETERS
 *  id_info 
 * RETURNS
 *  mmi_frm_proc_result_enum
 *****************************************************************************/
mmi_frm_proc_result_enum mmi_wgtmgr_preinstall_widget(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_wgtmgr_preinstall_widget() == MMI_FALSE)
    {
        g_id_info = id_info;

        /* display progressive screen since it needs wait for response from Widget Manager Service */
        mmi_wgtmgr_entry_pre_installing();

        
        mmi_frm_cb_reg_event(EVT_ID_SRV_WGTMGR_FINISH_PRE_INSATLL_WIDGET_IND, mmi_wgtmgr_install_proc, NULL);

        return MMI_FRM_PROC_RESULT_NOTIFY_LATER;
    }
    return MMI_FRM_PROC_RESULT_COMPLETED;
}


#endif /* __MMI_GADGET_SUPPORT__ */


