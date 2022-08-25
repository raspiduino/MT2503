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
 * MMSAppSettings.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
// #include "MMI_include.h"
#include "MMI_features.h"
#if (defined(__MMI_MMS_2__) && defined(__MMI_MMS_SIMPLIFIED_UI_SUPPORT__))

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "MMI_inet_app_trc.h"
#include "DebugInitDef_Int.h"
#include "mmi_inet_app_trc.h"
#include "kal_trace.h"
#include "string.h"
#include "mma_api.h"
#include "kal_public_api.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_util.h"
#include "mmi_inet_app_trc.h"
#include "mmi_rp_app_sms_def.h"
#include "mmi_rp_file_type_def.h"
#include "mmi_rp_app_umms_mms_def.h"
#include "mmi_rp_app_unifiedmessage_def.h"
#include "FileMgrSrvGProt.h"
#include "FileMgrType.h"
// #include "CallManagementGprot.h"
#include "MMSAppUICommon.h"
#include "MMSAppInterfaceprot.h"
#include "MMSAppInterfaceGprot.h"
#include "MMSAppUIController.h"
#include "MMSAppResDef.h"
// #include "inlineCuiGprot.h"
#include "MMSAppDataManager.h"
// #include "mmsadp.h"
#include "UMGProt.h"
#include "UcAppGProt.h"
#include "MMSMemoryManagerSrv.h"
#include "MMSAppDataManager.h"
//#include "UnifiedMessageResDef.h"
//#include "SimDetectionGprot.h"
/* Amit added for profiles */

#include "WAPProfileSrvGProt.h"
#include "WAPProfileSrvType.h"
// #include "WAPprovisioningType.h"

// #include "custom_events_notify.h"
#include "MmsSrvGprot.h"
#include "MMSAppSrvHdlr.h"
// #include "MessagesResourceData.h"
#include "IdleHomescreenGProt.h"
//#include "UcmGprot.h"
//#include "MMSAppOp.h"
#include "MmsSrvProt.h"
#include "MMSAppUIPlugin.h"
#include "MMSAppUIdrawEx.h"
#include "MMSAppInterfaceGprot.h"
#include "MenuCuiGprot.h"
#include "MMSAppUICallback.h"
#include "med_api.h"
#include "med_mem.h"
#include "MsgViewerCuiGProt.h"
#include "mma_struct.h"
#include "UMDefs.h"
#include "UmSrvDefs.h"
#include "CustDataRes.h"
#include "Unicodexdcl.h"
#include "UcmSrvGprot.h"
#include "custom_wap_config.h"
#include "gdi_features.h"
#include "mms_sap_struct.h"
#include "MMI_rp_app_umms_mms_def.h"
// #include "MMSSettingSrv.h"

extern mmi_ret mmi_umms_proc_func(mmi_event_struct *evt);
extern mmi_ret mmi_umms_template_grp_proc_func(mmi_event_struct *evt);
extern void srv_mms_set_settings_slim(srv_mms_settings_enum app_setting, U32 value);
MMI_ID settings_gid;
MMI_ID menu_cui_gid;
extern srv_mms_read_nvram_settings_struct *g_srv_mms_settings_context;

/* External Interface   */
void mmi_umms_settings_hdlr(mmi_event_struct *param);
void mmi_umms_settings_show_func(void);
void mmi_umms_settings_radio_list_show_func(U16 parent_menu);


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_settings_radio_list_show_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_menu     [IN]        
 *  scr_id(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_settings_radio_list_show_func(U16 parent_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_id child_menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    child_menu_gid = cui_menu_create(
                        mmi_umms_dtmgr_get_group_id(),
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        CUI_MENU_TYPE_APPMAIN /* CUI_MENU_TYPE_APPSUB */ ,      /* Option menu */
                        parent_menu,    /* parent menu */
                        MMI_TRUE,
                        NULL);

    /* SETTING HIGHLIGHT */
    cui_menu_set_currlist_flags(child_menu_gid, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
    cui_menu_run(child_menu_gid);   /* start to run this cui */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_settings_show_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_settings_show_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_gid = cui_menu_create_and_run(
                    mmi_umms_dtmgr_get_group_id(),
                    CUI_MENU_SRC_TYPE_RESOURCE,
                    CUI_MENU_TYPE_APPMAIN,      /* Option menu */
                    MENU_ID_UMMS_MMS_SETTINGS,  /* parent menu */
                    MMI_TRUE,
                    NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_settings_done_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_settings_done_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_send_events(EVT_ID_SRV_SET_SETTING, NULL);
    /* mmi_umms_app_ui_draw_dummy_screen(); */
    mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_SAVED), MMI_EVENT_EXPLICITLY_SAVED);
    mmi_umms_app_ui_draw_display_popup_screen(0);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_settings_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_settings_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    U16 temp;
    U8 temp_u8;
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            switch (menu_evt->parent_menu_id)
            {
            #if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) && !defined(__MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__)
                case MENU_ID_UMMS_MMS_SETTINGS_PREFER_STORAGE:
                {
                    temp_u8 = (U8) mmi_umms_app_ui_plug_in_get_prefer_storage_hilighted_index();
                    temp =
                        temp_u8 ? MENU_ID_UMMS_MMS_SETTINGS_PREFER_STORAGE_CARD :
                        MENU_ID_UMMS_MMS_SETTINGS_PREFER_STORAGE_PHONE;
                    cui_menu_set_radio_list_item(menu_evt->sender_id, temp);
                    break;
                }
            #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 


                /*********RETRIEVAL SETTINGS***********/
                case MENU_ID_RETRIEVAL_SETTINGS_HOME_NW:
                {
                    cui_menu_set_currlist_highlighted_id(
                        menu_evt->sender_id,
                        cui_menu_get_currlist_menu_id_from_index(menu_evt->sender_id, srv_mms_retrieval_settings_home_network_retrieval_mode ()));
                    break;
                }
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
                case MENU_ID_RETRIEVAL_SETTINGS_ANON:
                {
                    cui_menu_set_currlist_highlighted_id(
                        menu_evt->sender_id,
                        cui_menu_get_currlist_menu_id_from_index(menu_evt->sender_id, srv_mms_retrieval_settings_anonymous_filter ()));
                    break;
                }
                case MENU_ID_RETRIEVAL_SETTINGS_ADV:
                {
                    cui_menu_set_currlist_highlighted_id(
                        menu_evt->sender_id,
                        cui_menu_get_currlist_menu_id_from_index(menu_evt->sender_id, srv_mms_retrieval_settings_advertisment_filter ()));
                    break;
                }
#endif
#ifndef __MMI_MMS_NO_REPORT_SUPPORT__
                case MENU_ID_RETRIEVAL_SETTINGS_DELIVERY_REPORT:
                {
                    cui_menu_set_currlist_highlighted_id(
                        menu_evt->sender_id,
                        cui_menu_get_currlist_menu_id_from_index(menu_evt->sender_id, (srv_mms_retrieval_settings_delivery_report () + 1) % 2));
                    break;
                }
                case MENU_ID_RETRIEVAL_SETTINGS_READ_REPORT:
                {
                    cui_menu_set_currlist_highlighted_id(
                        menu_evt->sender_id,
                        cui_menu_get_currlist_menu_id_from_index(menu_evt->sender_id, srv_mms_retrieval_settings_read_report ()));
                    break;
                }

                /**********SENDING SETTINGS***********/
                case MENU_ID_SENDING_SETTINGS_READ_REPORT:
                {
                    cui_menu_set_currlist_highlighted_id(
                        menu_evt->sender_id,
                        cui_menu_get_currlist_menu_id_from_index(menu_evt->sender_id, (srv_mms_sending_settings_read_report () + 1) % 2));
                    break;
                }
#endif
                case MENU_ID_SENDING_SETTINGS_SEND_AND_SAVE:
                {
                    cui_menu_set_currlist_highlighted_id(
                        menu_evt->sender_id,
                        cui_menu_get_currlist_menu_id_from_index(menu_evt->sender_id, (srv_mms_sending_settings_send_and_save () + 1) % 2));
                    break;
                }
            }

            break;
        }

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        {
            switch (menu_evt->highlighted_menu_id)
            {
            #if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) && !defined(__MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__)
				case MENU_ID_UMMS_MMS_SETTINGS_PREFER_STORAGE_EXT:
                {
                    mmi_umms_settings_radio_list_show_func(MENU_ID_UMMS_MMS_SETTINGS_PREFER_STORAGE);
                    break;
                }
            #endif
                /*************************************  RETRIEVAL SETTINGS *******************************************/
                case MENU_ID_RETRIEVAL_SETTINGS_HOME_NW_EXT:
                {
                    mmi_umms_settings_radio_list_show_func(MENU_ID_RETRIEVAL_SETTINGS_HOME_NW);
                    break;
                }
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
                case MENU_ID_RETRIEVAL_SETTINGS_ANON_EXT:
                {
                    mmi_umms_settings_radio_list_show_func(MENU_ID_RETRIEVAL_SETTINGS_ANON);
                    break;
                }

                case MENU_ID_RETRIEVAL_SETTINGS_ADV_EXT:
                {
                    mmi_umms_settings_radio_list_show_func(MENU_ID_RETRIEVAL_SETTINGS_ADV);
                    break;
                }                
#endif
#ifndef __MMI_MMS_NO_REPORT_SUPPORT__
				case MENU_ID_RETRIEVAL_SETTINGS_DELIVERY_REPORT_EXT:
                {
                    mmi_umms_settings_radio_list_show_func(MENU_ID_RETRIEVAL_SETTINGS_DELIVERY_REPORT);
                    break;
                }

                case MENU_ID_RETRIEVAL_SETTINGS_READ_REPORT_EXT:
                {
                    mmi_umms_settings_radio_list_show_func(MENU_ID_RETRIEVAL_SETTINGS_READ_REPORT);
                    break;
                }

                /*************************************  SENDING SETTINGS *******************************************/

                case MENU_ID_SENDING_SETTINGS_READ_REPORT_EXT:
                {
                    mmi_umms_settings_radio_list_show_func(MENU_ID_SENDING_SETTINGS_READ_REPORT);
                    break;
                }
#endif
                case MENU_ID_SENDING_SETTINGS_SEND_AND_SAVE_EXT:
                {
                    mmi_umms_settings_radio_list_show_func(MENU_ID_SENDING_SETTINGS_SEND_AND_SAVE);
                    break;
                }
            }
            switch (menu_evt->parent_menu_id)
            {
            

                /*************************************  RETRIEVAL SETTINGS *******************************************/
                case MENU_ID_RETRIEVAL_SETTINGS_HOME_NW:
                {
                    srv_mms_set_settings_slim(SRV_MMS_RETRIEVAL_SETTINGS_HOME_NW, cui_menu_get_index_in_currlist_from_menu_id(
                                                                                            menu_evt->sender_id,
                                                                                            menu_evt->highlighted_menu_id) + 1);
                    mmi_umms_settings_done_hdlr();
                    cui_menu_close(menu_evt->sender_id);
                    break;
                }
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
                case MENU_ID_RETRIEVAL_SETTINGS_ANON:
                {
                    if (menu_evt->highlighted_menu_id == MENU_ID_UMMS_MMS_SETTINGS_ALLOW)
                    {
                        srv_mms_set_settings_slim(SRV_MMS_RETRIEVAL_SETTINGS_ANON, 0);
                    }
                    else
                    {
                        srv_mms_set_settings_slim(SRV_MMS_RETRIEVAL_SETTINGS_ANON, 1);
                    }
                    mmi_umms_settings_done_hdlr();
                    cui_menu_close(menu_evt->sender_id);
                    break;
                }

                case MENU_ID_RETRIEVAL_SETTINGS_ADV:
                {
                    if (menu_evt->highlighted_menu_id == MENU_ID_UMMS_MMS_SETTINGS_ALLOW)
                    {
                        srv_mms_set_settings_slim(SRV_MMS_RETRIEVAL_SETTINGS_ADV, 0);
                    }
                    else
                    {
                        srv_mms_set_settings_slim(SRV_MMS_RETRIEVAL_SETTINGS_ADV, 1);
                    }
                    mmi_umms_settings_done_hdlr();
                    cui_menu_close(menu_evt->sender_id);
                    break;
                }
#endif
#ifndef __MMI_MMS_NO_REPORT_SUPPORT__
                case MENU_ID_RETRIEVAL_SETTINGS_DELIVERY_REPORT:
                {
                    if (menu_evt->highlighted_menu_id == MENU_ID_UMMS_MMS_SETTINGS_ON)
                    {
                        srv_mms_set_settings_slim(SRV_MMS_RETRIEVAL_SETTINGS_DELIVERY_REPORT, 1);
                    }
                    else
                    {
                        srv_mms_set_settings_slim(SRV_MMS_RETRIEVAL_SETTINGS_DELIVERY_REPORT, 0);
                    }
                    mmi_umms_settings_done_hdlr();
                    cui_menu_close(menu_evt->sender_id);
                    break;
                }

                case MENU_ID_RETRIEVAL_SETTINGS_READ_REPORT:
                {
                    srv_mms_set_settings_slim(SRV_MMS_RETRIEVAL_SETTINGS_READ_REPORT, cui_menu_get_index_in_currlist_from_menu_id(menu_evt->sender_id, menu_evt->highlighted_menu_id));
                    mmi_umms_settings_done_hdlr();
                    cui_menu_close(menu_evt->sender_id);
                    break;
                }

                /*************************************  SENDING SETTINGS *******************************************/


                case MENU_ID_SENDING_SETTINGS_READ_REPORT:
                {
                    if (menu_evt->highlighted_menu_id == MENU_ID_UMMS_MMS_SETTINGS_ON)
                    {
                        srv_mms_set_settings_slim(SRV_MMS_SENDING_SETTINGS_READ_REPORT, 1);
                    }
                    else
                    {
                        srv_mms_set_settings_slim(SRV_MMS_SENDING_SETTINGS_READ_REPORT, 0);
                }
                    mmi_umms_settings_done_hdlr();
                    cui_menu_close(menu_evt->sender_id);
                    break;
                }
#endif
				case MENU_ID_SENDING_SETTINGS_SEND_AND_SAVE:
                {
                    if (menu_evt->highlighted_menu_id == MENU_ID_UMMS_MMS_SETTINGS_ON)
                    {
                        g_srv_mms_settings_context->nvram_sending_settings.send_and_save = 1;
                    }
                    else
                    {
                        g_srv_mms_settings_context->nvram_sending_settings.send_and_save = 0;
                    }
                    srv_mms_write_nvram_sending_settings();
                    mmi_umms_settings_done_hdlr();
                    cui_menu_close(menu_evt->sender_id);
                    break;
                }

                }

                    break;
                }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {

            cui_menu_close(menu_evt->sender_id);
            /* mmi_frm_scrn_close_active_id(); */
            break;
        }
    }
}

#endif /* (defined(__MMI_MMS_2__) && defined(__MMI_MMS_SIMPLIFIED_UI_SUPPORT__)) */ 

