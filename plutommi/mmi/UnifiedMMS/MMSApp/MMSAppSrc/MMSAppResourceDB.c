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
 * MMSAppResourceDB.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
// #include "MMI_include.h"
#include "MMI_features.h"
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
#ifdef __MMI_MMS_2__

#include "MMSAppResDef.h"
#include "mmi_rp_app_umms_mms_def.h"
#include "mmi_rp_app_unifiedmessage_def.h"
// #include "MMSAppUICommon.h"
#include "MMSAppInterfaceGProt.h"
#include "MMSAppInterfaceProt.h"
#include "MMSAppScrHdlr.h"
#include "MMSAppUIPlugin.h"
#include "MMSAppUIdrawEx.h"
#include "MMSAppScrHdlrEx.h"
// #include "inlineCuiGprot.h"
#include "MMSAppResourceDB.h"
//#include "MMSAppUIdraw.h"
//#include "MMSAppDataManager.h"
#include "GlobalResDef.h"
#include "MMIDataType.h"

#define MMI_UMMS_RES_DB_MAX (sizeof(g_umms_app_resourceDB)/sizeof(g_umms_app_resourceDB[0]))

#define MMI_UMMS_SCR_DB_MAX (sizeof(g_umms_app_screenDB)/sizeof(g_umms_app_screenDB[0]))

typedef enum
{
    ENUM_SCR_ID_UMMS_DRAFT_OPTION,              /* 0 */
    ENUM_SCR_ID_UMMS_INBOX_MMS_OPTION,
    ENUM_SCR_ID_UMMS_INBOX_NOTIFICATION_OPTION,
    ENUM_SCR_ID_UMMS_INBOX_DELIVERY_READ_OPTION,
    ENUM_SCR_ID_UMMS_INBOX_JAVA_MMS_OPTION,
    ENUM_SCR_ID_UMMS_SENT_OPTION,
    ENUM_SCR_ID_UMMS_OUTBOX_OPTION,
    ENUM_SCR_ID_UMMS_MMS_VIEWER,
    ENUM_SCR_ID_UMMS_MMS_OPTIONS_USE_DETAILS,
#ifdef __MMI_MMS_PREVIEW_GOTO__
    ENUM_SCR_ID_UMMS_PREVIEW_OPTIONS,
    ENUM_SCR_ID_UMMS_PREVIEW_SLIDE_LIST,        /* 10 */
#endif /* __MMI_MMS_PREVIEW_GOTO__ */ 
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
    ENUM_SCR_ID_UMMS_TEMPLATES_DEFAULT_USER_DEFINED,
#endif 
    ENUM_SCR_ID_UMMS_USE_NUMBER,
    ENUM_SCR_ID_UMMS_USE_EMAIL,
    ENUM_SCR_ID_UMMS_USE_URL,
    ENUM_SCR_ID_UMMS_USE_SENDER,
    ENUM_SCR_ID_UMMS_MESSAGE_STATUS,
    ENUM_SCR_ID_UMMS_MESSAGE_SETTINGS_FOR_COMMON_SETTINGS,
    ENUM_SCR_ID_UMMS_MESSAGE_SETTINGS,
    ENUM_SCR_ID_UMMS_COMPOSE_SETTINGS,          /* 20 */
    ENUM_SCR_ID_UMMS_RETRIEVAL_SETTINGS,
    ENUM_SCR_ID_UMMS_SENDING_SETTINGS,
    ENUM_SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS,
    ENUM_SCR_ID_UMMS_RETRIEVAL_FILTERS_SETTINGS,
    ENUM_SCR_ID_UMMS_COMPOSE_IMAGE_OPTION,
    ENUM_SCR_ID_UMMS_MMS_MESSAGE_STATUS,
#if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) 
    ENUM_SCR_ID_UMMS_MMS_MESSAGE_STATUS_PHONE,
    ENUM_SCR_ID_UMMS_MMS_MESSAGE_STATUS_CARD,
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    ENUM_SCR_ID_UMMS_SAVE_OBJECT_ATTACHMENT_LIST,
    ENUM_SCR_ID_UMMS_SAVE_OBJECT,
    ENUM_SCR_ID_UMMS_RETRIEVED_MMS_PROPERTIES,  /* 29 */
#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
    ENUM_SCR_ID_UMMS_SORT_OPTION,
#endif 
    ENUM_SCR_ID_UMMS_JAVA_OPTIONS,
#if(MMI_MAX_SIM_NUM >= 2)
    ENUM_SCR_ID_UMMS_MESSAGE_SETTINGS_SIM_SELECTION,
#endif 
    ENUM_SCR_ID_UMMS_NOTIFICATION,
    ENUM_SCR_ID_UMMS_READ_DELIVERY_REPORT_OPTIONS,
#if(MMI_MAX_SIM_NUM == 2)
    ENUM_SCR_ID_UMMS_SIM_OPTION,
#endif 
    ENUM_SCR_ID_UMMS_OPTIONS_USE_DETAILS_ADDRESSES_OPTIONS,
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
    ENUM_SCR_ID_UMMS_TEMPLATES,
    ENUM_SCR_ID_UMMS_TEMPLATES_OPTIONS,
    ENUM_SCR_ID_UMMS_FWD_EDIT_CLUBBED,          /* for defualt template */
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ /* for userdef templates */
    /* SCR_ID_UMMS_ARCHIVE_OPTION, */
#if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) && !defined(__MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__)
    ENUM_SCR_ID_UMMS_MMS_PREFER_STORAGE,
#ifdef __MMI_MMS_MSG_STORAGE_FILTER_SUPPORT__
    ENUM_SCR_ID_UMMS_MMS_MSG_FILTER,
#endif
#endif 
    ENUM_SCR_ID_UMMS_READ_DELIVERY_REPORT_VIEW_SCREEN,
#ifdef __MMI_MMS_ITERATOR_VIEWER__
    ENUM_SCR_ID_UMMS_HANDLE_ABNORMAL_VIEW_SCREEN,
#endif 
    /* ENUM_SCR_ID_UMMS_MMS_OPTIONS_USE_DETAILS_SENDER_RECIPIENT, */
    /* please add new item here */
    /* don't delete this line */
#ifdef __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__
    ENUM_SCR_ID_UMMS_MMS_DELIVERY_STATUS,
    ENUM_SCR_ID_UMMS_MMS_READ_STATUS,
#endif /* __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__ */ 
    ENUM_SCR_ID_UMMS_MMS_APP_SRV_END
        /* temp check */
        //ENUM_SCR_ID_UMMS_ARCHIVE_OPTION,
        //ENUM_SCR_ID_UMMS_NOTIFICATION_NEW_MMS,
        //ENUM_SCR_ID_UMMS_NOTIFICATION_NEW_JAVA_MMS
} mmi_umms_app_scr_enum;

mmi_umms_app_resourceDB_struct g_umms_app_resourceDB[] = 
{

    {
     SCR_ID_UMMS_DRAFT_OPTION, MENU_ID_UMMS_DRAFT_OPTIONS, STR_GLOBAL_OPTIONS, MAIN_MENU_MESSAGES_MENUID, STR_GLOBAL_OK,
     IMG_GLOBAL_OK,
     STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
    {
     SCR_ID_UMMS_INBOX_MMS_OPTION, MENU_ID_UMMS_INBOX_OPTIONS_NEW_MMS, STR_GLOBAL_OPTIONS, MAIN_MENU_MESSAGES_MENUID,
     STR_GLOBAL_OK,
     IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
    {
     SCR_ID_UMMS_INBOX_NOTIFICATION_OPTION, MENU_ID_UMMS_INBOX_OPTIONS_NOTIFICATION, STR_GLOBAL_OPTIONS,
     MAIN_MENU_MESSAGES_MENUID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
    {
     SCR_ID_UMMS_INBOX_DELIVERY_READ_OPTION, MENU_ID_UMMS_INBOX_OPTIONS_DELIVERY_REPORT, STR_GLOBAL_OPTIONS,
     MAIN_MENU_MESSAGES_MENUID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
    {
     SCR_ID_UMMS_INBOX_JAVA_MMS_OPTION, MENU_ID_UMMS_INBOX_OPTIONS_JAVA_MMS, STR_GLOBAL_OPTIONS,
     MAIN_MENU_MESSAGES_MENUID, STR_GLOBAL_OK,
     IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
    {
     SCR_ID_UMMS_SENT_OPTION, MENU_ID_UMMS_SENT_OPTIONS, STR_GLOBAL_OPTIONS, MAIN_MENU_MESSAGES_MENUID, STR_GLOBAL_OK,
     IMG_GLOBAL_OK,
     STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
    {
     SCR_ID_UMMS_OUTBOX_OPTION, MENU_ID_UMMS_OUTBOX_OPTIONS, STR_GLOBAL_OPTIONS, MAIN_MENU_MESSAGES_MENUID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK,
     STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
    {
     SCR_ID_UMMS_MMS_VIEWER, 0, 0, 0, 0, 0, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
    {
     SCR_ID_UMMS_MMS_OPTIONS_USE_DETAILS, MENU_ID_UMMS_OPTIONS_USE_DETAILS, STR_ID_UMMS_OPTIONS_USE_DETAILS,
     MAIN_MENU_MESSAGES_MENUID, STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
 #ifdef __MMI_MMS_PREVIEW_GOTO__
    {
     SCR_ID_UMMS_PREVIEW_OPTIONS, MENU_ID_UMMS_PREVIEW_OPTION, STR_GLOBAL_OPTIONS, MAIN_MENU_MESSAGES_MENUID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
    {
     SCR_ID_UMMS_PREVIEW_SLIDE_LIST, MENU_ID_UMMS_PREVIEW_GO_TO, STR_UMMS_MANUAL_PLAY_SLIDE_LIST,
     MAIN_MENU_MESSAGES_MENUID, STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
 #endif /* __MMI_MMS_PREVIEW_GOTO__ */ 
 #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
    {
     SCR_ID_UMMS_TEMPLATES_DEFAULT_USER_DEFINED, MENU_ID_UMMS_TEMPLATE_MMS, STR_ID_UMMS_TEMPLATES_TITLE,
     MAIN_MENU_MESSAGES_MENUID, STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
 #endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 
    {
     SCR_ID_UMMS_USE_NUMBER, MENU_ID_UMMS_OPTIONS_USE_DETAILS_NUMBER, STR_ID_UMMS_OPTIONS_USE_DETAILS_NUMBER,
     IMG_NONE, STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
    {
     SCR_ID_UMMS_USE_EMAIL, MENU_ID_UMMS_OPTIONS_USE_DETAILS_EMAIL, STR_ID_UMMS_OPTIONS_USE_DETAILS_EMAIL,
     IMG_NONE, STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__
    {
     SCR_ID_UMMS_USE_URL, MENU_ID_UMMS_OPTION_USE_DETAILS_URL, STR_ID_UMMS_OPTIONS_USE_DETAILS_URL,
     IMG_NONE, STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
#else
     {
     SCR_ID_UMMS_USE_URL, MENU_ID_UMMS_OPTION_USE_DETAILS_URL, STR_ID_UMMS_OPTIONS_USE_DETAILS_URL,
     IMG_NONE, STR_GLOBAL_GO_TO, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
#endif
    {
     SCR_ID_UMMS_USE_SENDER, MENU_ID_UMMS_OPTIONS_USE_DETAILS_SENDER, STR_ID_UMMS_USE_DETAILS_SENDER,
     MAIN_MENU_MESSAGES_MENUID, STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    {
     SCR_ID_UMMS_MESSAGE_STATUS, MENU_ID_UMMS_OUTBOX_OPTIONS_MESSAGE_STATUS, STR_ID_UMMS_MESSAGE_STATUS,
     MAIN_MENU_MESSAGES_MENUID, 0, 0, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
#else
	 {
     SCR_ID_UMMS_MESSAGE_STATUS, MENU_ID_UMMS_OUTBOX_OPTIONS_MESSAGE_STATUS, NULL,
     MAIN_MENU_MESSAGES_MENUID, 0, 0, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
#endif

    /* ------------------------------------Niraj----------------------------------------------// */
    {
     SCR_ID_UMMS_MESSAGE_SETTINGS_FOR_COMMON_SETTINGS, MENU_ID_UMMS_MESSAGE_SETTINGS_FOR_COMMON_SETTINGS,
     STR_ID_UMMS_MMS_SETTINGS, MAIN_MENU_MESSAGES_MENUID, STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK,
     IMG_GLOBAL_BACK,
     },
    {
     SCR_ID_UMMS_MESSAGE_SETTINGS, MENU_ID_UMMS_MMS_SETTINGS, STR_ID_UMMS_MESSAGE_SETTINGS_COMMON_SETTINGS,
     MAIN_MENU_MESSAGES_MENUID, STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
     },
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    {
     SCR_ID_UMMS_COMPOSE_SETTINGS, MENU_ID_UMMS_MMS_SETTINGS_COMPOSE, STR_ID_UMMS_MESSAGE_SETTINGS_COMPOSE,
     MAIN_MENU_MESSAGES_MENUID,
     },
#else
	 {
     SCR_ID_UMMS_COMPOSE_SETTINGS, MENU_ID_UMMS_MMS_SETTINGS_COMPOSE, NULL,
     MAIN_MENU_MESSAGES_MENUID,
     },
#endif
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    {
     SCR_ID_UMMS_RETRIEVAL_SETTINGS, MENU_ID_UMMS_MMS_SETTINGS_RETRIEVAL, STR_ID_UMMS_MESSAGE_SETTINGS_RETRIEVAL,
     MAIN_MENU_MESSAGES_MENUID,
     },
#else
	 {
     SCR_ID_UMMS_RETRIEVAL_SETTINGS, MENU_ID_UMMS_MMS_SETTINGS_RETRIEVAL, NULL,
     MAIN_MENU_MESSAGES_MENUID,
     },
#endif
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    {
     SCR_ID_UMMS_SENDING_SETTINGS, MENU_ID_UMMS_MMS_SETTINGS_SENDING, STR_ID_UMMS_MESSAGE_SETTINGS_SENDING,
     MAIN_MENU_MESSAGES_MENUID, 0, 0, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
#else
	 {
     SCR_ID_UMMS_SENDING_SETTINGS, MENU_ID_UMMS_MMS_SETTINGS_SENDING, NULL,
     MAIN_MENU_MESSAGES_MENUID, 0, 0, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
#endif
    {
     SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS, 0, STR_ID_UMMS_SETTINGS_SIGNATURE, MAIN_MENU_MESSAGES_MENUID, 0, 0,
     STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
    {
     SCR_ID_UMMS_RETRIEVAL_FILTERS_SETTINGS, 0, STR_ID_UMMS_SETTINGS_FILTERS, MAIN_MENU_MESSAGES_MENUID, 0, 0,
     STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
    {
     SCR_ID_UMMS_COMPOSE_IMAGE_OPTION, MENU_ID_UMMS_SIGNATURE_OPTION, STR_ID_UMMS_SETTINGS_SIGNATURE,
     MAIN_MENU_MESSAGES_MENUID, STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
     },
   /*************************************Amit added ******************************************/
 #if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) 
    {
     SCR_ID_UMMS_MMS_MESSAGE_STATUS, MENU_ID_UMMS_MMS_SETTINGS_MEMORY_STATUS, STR_GLOBAL_MEMORY_STATUS,
     MAIN_MENU_MESSAGES_MENUID, STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
     },
    {
     SCR_ID_UMMS_MMS_MESSAGE_STATUS_PHONE, MENU_ID_UMMS_MMS_SETTINGS_MEMORY_STATUS_PHONE,
     STR_ID_UMMS_MMS_PREFER_STORAGE_PHONE, MAIN_MENU_MESSAGES_MENUID, 0, 0, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
    {
     SCR_ID_UMMS_MMS_MESSAGE_STATUS_CARD, MENU_ID_UMMS_MMS_SETTINGS_MEMORY_STATUS_CARD,
     STR_ID_UMMS_MMS_PREFER_STORAGE_CARD, MAIN_MENU_MESSAGES_MENUID, 0, 0, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
 #else /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    {
     SCR_ID_UMMS_MMS_MESSAGE_STATUS, MENU_ID_UMMS_MMS_SETTINGS_MEMORY_STATUS, STR_GLOBAL_MEMORY_STATUS,
     MAIN_MENU_MESSAGES_MENUID, 0, 0, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
 #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    {
     SCR_ID_UMMS_SAVE_OBJECT_ATTACHMENT_LIST, MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_ATTACHMENT_AS,
     STR_ID_UMMS_OBJECTS_ATTACHMENT_LIST, MAIN_MENU_MESSAGES_MENUID, STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK,
     IMG_GLOBAL_BACK},
    {
     SCR_ID_UMMS_SAVE_OBJECT, MENU_ID_UMMS_OPTIONS_SAVE_OBJECTS, STR_ID_UMMS_OPTIONS_SAVE_OBJECTS,
     MAIN_MENU_MESSAGES_MENUID, STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
    {
     SCR_ID_UMMS_RETRIEVED_MMS_PROPERTIES, MENU_ID_UMMS_OPTIONS_PROPERTIES, STR_GLOBAL_DETAILS,
     MAIN_MENU_MESSAGES_MENUID, 0, 0, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
 #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
    {
     SCR_ID_UMMS_SORT_OPTION, MENU_ID_UM_SORT_BY_OPT, STR_GLOBAL_SORT_BY, MAIN_MENU_MESSAGES_MENUID, STR_GLOBAL_OK,
     IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
 #endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */ 
    {
     SCR_ID_UMMS_JAVA_OPTIONS, MENU_ID_UMMS_INBOX_OPTIONS_JAVA_MMS, STR_GLOBAL_OPTIONS, MAIN_MENU_MESSAGES_MENUID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
 #if (MMI_MAX_SIM_NUM >= 2)
    {
     SCR_ID_UMMS_MESSAGE_SETTINGS_SIM_SELECTION, MENU_ID_UMMS_MMS_SETTING_SIM_SELECTION,
     STR_GLOBAL_DATA_ACCOUNT, MAIN_MENU_MESSAGES_MENUID, STR_GLOBAL_OK, IMG_GLOBAL_OK,
     STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
 #endif /* (MMI_MAX_SIM_NUM >= 2) */ 
    {
     SCR_ID_UMMS_NOTIFICATION, MENU_ID_UMMS_INBOX_OPTIONS_NOTIFICATION, STR_GLOBAL_OPTIONS, MAIN_MENU_MESSAGES_MENUID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
    {
     SCR_ID_UMMS_READ_DELIVERY_REPORT_OPTIONS, MENU_ID_UMMS_INBOX_OPTIONS_DELIVERY_REPORT, STR_GLOBAL_OPTIONS,
     MAIN_MENU_MESSAGES_MENUID, STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
 #if (MMI_MAX_SIM_NUM == 2)
    {
     SCR_ID_UMMS_SIM_OPTION, MENU_ID_UMMS_OPTIONS_RESEND, STR_GLOBAL_SEND, MAIN_MENU_MESSAGES_MENUID, STR_GLOBAL_OK,
     IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
 #endif /* (MMI_MAX_SIM_NUM == 2) */ 
    {
     SCR_ID_UMMS_OPTIONS_USE_DETAILS_ADDRESSES_OPTIONS, 0, STR_GLOBAL_OPTIONS, MAIN_MENU_MESSAGES_MENUID, STR_GLOBAL_OK,
     IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
 #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
    {
     SCR_ID_UMMS_TEMPLATES, MENU_ID_UMMS_TEMPLATES_USER_DEFINED, STR_ID_UMMS_TEMPLATE_USER_DEFINED,
     MAIN_MENU_MESSAGES_MENUID,

     STR_GLOBAL_OPTIONS,
     IMG_GLOBAL_OPTIONS, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
    {
     SCR_ID_UMMS_TEMPLATES_OPTIONS, MENU_ID_UMMS_TEMPLATES_OPTIONS, STR_GLOBAL_OPTIONS, MAIN_MENU_MESSAGES_MENUID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
    {
     SCR_ID_UMMS_FWD_EDIT_CLUBBED, MENU_ID_UMMS_TEMPLATES_DEFAULT, STR_GLOBAL_DEFAULT, MAIN_MENU_MESSAGES_MENUID,

     STR_GLOBAL_OPTIONS,
     IMG_GLOBAL_OPTIONS,
     STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
 #endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 
    /* {
       SCR_ID_UMMS_ARCHIVE_OPTION, 0,STR_GLOBAL_OPTIONS,0,STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS, STR_GLOBAL_BACK, IMG_GLOBAL_BACK
       }, */
 #if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) && !defined(__MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__)
    {
     SCR_ID_UMMS_MMS_PREFER_STORAGE, MENU_ID_UMMS_MMS_SETTINGS_PREFER_STORAGE, STR_ID_UMMS_MMS_PREFER_STORAGE,
     MAIN_MENU_MESSAGES_MENUID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
#ifdef __MMI_MMS_MSG_STORAGE_FILTER_SUPPORT__
	 {
     SCR_ID_UMMS_MMS_MSG_FILTER, MENU_ID_UMMS_MMS_SETTINGS_STORAGE_FILTER, STR_ID_UMMS_MMS_MSG_FILTER,
     MAIN_MENU_MESSAGES_MENUID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
#endif
 #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    {
     SCR_ID_UMMS_READ_DELIVERY_REPORT_VIEW_SCREEN, MENU_ID_UMMS_OPTIONS_PROPERTIES, STR_GLOBAL_DETAILS,
     MAIN_MENU_MESSAGES_MENUID, STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
 #ifdef __MMI_MMS_ITERATOR_VIEWER__
    {
     SCR_ID_UMMS_HANDLE_ABNORMAL_VIEW_SCREEN, MENU_ID_UMMS_OPTIONS_PROPERTIES, STR_GLOBAL_MULTIMEDIA_MESSAGE,
     MAIN_MENU_MESSAGES_MENUID, STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
 #endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 
 #ifdef __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__
    {
     SCR_ID_UMMS_MMS_DELIVERY_STATUS, MENU_ID_UMMS_OPTIONS_DELIVERY_STATUS, STR_ID_UMMS_DELIVERY_STATUS,
     MAIN_MENU_MESSAGES_MENUID, 0, 0, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
    {
     SCR_ID_UMMS_MMS_READ_STATUS, MENU_ID_UMMS_OPTIONS_READ_STATUS, STR_ID_UMMS_READ_STATUS, MAIN_MENU_MESSAGES_MENUID,
     0, 0, STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
 #endif /* __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__ */ 

};

const mmi_umms_app_screenDB_struct g_umms_app_screenDB[] = 
{

    {
     SCR_ID_UMMS_DRAFT_OPTION,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_DRAFT_OPTION,
     MENU_ID_UMMS_DRAFT_OPTIONS,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_draft_options_pre_func,
     mmi_umms_app_ui_plug_in_draft_options_post_func,
     mmi_umms_app_ui_draw_cui_static_list_draw_func,
     mmi_umms_app_sh_mms_options_exit_func,
     mmi_umms_app_if_show_draft_option,
     NULL,
     NULL,
     NULL,
     NULL},
    {
     SCR_ID_UMMS_USE_NUMBER,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_USE_NUMBER,
     MENU_ID_UMMS_DRAFT_OPTIONS,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_use_details_list_pre_func,
     mmi_umms_app_ui_plug_in_use_details_list_post_func,
     mmi_umms_app_ui_dyncmic_list_draw_func,
     mmi_umms_app_sh_mms_options_exit_func,
     mmi_umms_app_if_show_use_number,
     mmi_umms_app_sh_use_number_list_lsk_handler,
     mmi_umms_app_sh_static_list_rsk_handler,
     mmi_umms_app_sh_use_details_list_hilite_handler,
     mmi_umms_app_sh_use_details_list_delete_scr_handler},
    {
     SCR_ID_UMMS_USE_EMAIL,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_USE_EMAIL,
     MENU_ID_UMMS_DRAFT_OPTIONS,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_use_details_list_pre_func,
     mmi_umms_app_ui_plug_in_use_details_list_post_func,
     mmi_umms_app_ui_dyncmic_list_draw_func,
     mmi_umms_app_sh_mms_options_exit_func,
     mmi_umms_app_if_show_use_email,
     mmi_umms_app_sh_use_number_list_lsk_handler,
     mmi_umms_app_sh_static_list_rsk_handler,
     mmi_umms_app_sh_use_details_list_hilite_handler,
     mmi_umms_app_sh_use_details_list_delete_scr_handler},
    {
     SCR_ID_UMMS_USE_URL,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_USE_URL,
     MENU_ID_UMMS_DRAFT_OPTIONS,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_use_details_list_pre_func,
     mmi_umms_app_ui_plug_in_use_details_list_post_func,
     mmi_umms_app_ui_dyncmic_list_draw_func,
     mmi_umms_app_sh_mms_options_exit_func,
     mmi_umms_app_if_show_use_url,
#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__
     mmi_umms_app_sh_use_number_list_lsk_handler,
#else
     mmi_umms_app_ui_plug_in_use_url_as_browser_launch,
#endif
     mmi_umms_app_sh_static_list_rsk_handler,
     mmi_umms_app_sh_use_details_list_hilite_handler,
     mmi_umms_app_sh_use_details_list_delete_scr_handler},
    {
     SCR_ID_UMMS_USE_SENDER,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_USE_SENDER,
     MENU_ID_UMMS_DRAFT_OPTIONS,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_use_details_list_pre_func,
     mmi_umms_app_ui_plug_in_use_details_list_post_func,
     mmi_umms_app_ui_dyncmic_list_draw_func,
     mmi_umms_app_sh_mms_options_exit_func,
     mmi_umms_app_if_show_use_sender,
     mmi_umms_app_sh_use_number_list_lsk_handler,
     mmi_umms_app_sh_static_list_rsk_handler,
     mmi_umms_app_sh_use_details_list_hilite_handler,
     mmi_umms_app_sh_use_details_list_delete_scr_handler},
    {
     SCR_ID_UMMS_INBOX_MMS_OPTION,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_INBOX_MMS_OPTION,
     MENU_ID_UMMS_INBOX_OPTIONS_NEW_MMS,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_inbox_mms_options_pre_func,
     mmi_umms_app_ui_plug_in_inbox_mms_options_post_func,
     mmi_umms_app_ui_draw_cui_static_list_draw_func,
     mmi_umms_app_sh_mms_options_exit_func,
     mmi_umms_app_if_show_inbox_mms_option,
     NULL,
     NULL,
     NULL,
     NULL},
    {
     SCR_ID_UMMS_JAVA_OPTIONS,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_JAVA_OPTIONS,
     MENU_ID_UMMS_INBOX_OPTIONS_NEW_MMS,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_inbox_java_options_pre_func,
     mmi_umms_app_ui_plug_in_inbox_java_options_post_func,
     mmi_umms_app_ui_draw_cui_static_list_draw_func,
     mmi_umms_app_sh_mms_options_exit_func,
     mmi_umms_app_if_show_java_mms_options,
     NULL,
     NULL,
     NULL,
     NULL},
    {
     SCR_ID_UMMS_INBOX_NOTIFICATION_OPTION,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_INBOX_NOTIFICATION_OPTION,
     MENU_ID_UMMS_INBOX_OPTIONS_NOTIFICATION,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_inbox_notification_options_pre_func,
     mmi_umms_app_ui_plug_in_inbox_notification_options_post_func,
     mmi_umms_app_ui_draw_cui_static_list_draw_func,
     mmi_umms_app_sh_mms_options_exit_func,
     mmi_umms_app_if_show_inbox_notification_option,
     NULL,
     NULL,
     NULL,
     NULL},
    {
     SCR_ID_UMMS_INBOX_DELIVERY_READ_OPTION,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_INBOX_DELIVERY_READ_OPTION,
     MENU_ID_UMMS_INBOX_OPTIONS_DELIVERY_REPORT,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_inbox_read_delivery_options_pre_func,
     mmi_umms_app_ui_plug_in_inbox_read_delivery_options_post_func,
     mmi_umms_app_ui_draw_cui_static_list_draw_func,
     mmi_umms_app_sh_mms_options_exit_func,
     mmi_umms_app_if_show_inbox_read_delivery_option,
     NULL,
     NULL,
     NULL,
     NULL},
    {
     SCR_ID_UMMS_INBOX_JAVA_MMS_OPTION,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_INBOX_JAVA_MMS_OPTION,
     MENU_ID_UMMS_INBOX_OPTIONS_JAVA_MMS,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_inbox_java_options_pre_func,
     mmi_umms_app_ui_plug_in_inbox_java_options_post_func,
     mmi_umms_app_ui_draw_cui_static_list_draw_func,
     mmi_umms_app_sh_mms_options_exit_func,
     mmi_umms_app_if_show_inbox_java_option,
     NULL,
     NULL,
     NULL,
     NULL},
    {
     SCR_ID_UMMS_SENT_OPTION,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_SENT_OPTION,
     MENU_ID_UMMS_SENT_OPTIONS,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_sent_options_pre_func,
     mmi_umms_app_ui_plug_in_sent_options_post_func,
     mmi_umms_app_ui_draw_cui_static_list_draw_func,
     mmi_umms_app_sh_mms_options_exit_func,
     mmi_umms_app_if_show_sent_option,
     NULL,
     NULL,
     NULL,
     NULL},
    {
     SCR_ID_UMMS_OUTBOX_OPTION,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_OUTBOX_OPTION,
     MENU_ID_UMMS_OUTBOX_OPTIONS,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_outbox_options_pre_func,
     mmi_umms_app_ui_plug_in_outbox_options_post_func,
     mmi_umms_app_ui_draw_cui_static_list_draw_func,
     mmi_umms_app_sh_mms_options_exit_func,
     mmi_umms_app_if_show_outbox_option,
     NULL,
     NULL,
     NULL,
     NULL},
 #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
    {
     SCR_ID_UMMS_TEMPLATES_DEFAULT_USER_DEFINED,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_TEMPLATES_DEFAULT_USER_DEFINED,
     MENU_ID_UMMS_TEMPLATE_MMS,
     mmi_umms_app_sh_template_create_func,
     mmi_umms_app_ui_plug_in_template_menu_pre_func,
     mmi_umms_app_ui_plug_in_template_menu_post_func,
     mmi_umms_app_ui_draw_cui_static_list_draw_func,
     mmi_umms_app_sh_template_menu_exit_func,
     mmi_umms_app_show_template_menu,
     NULL,
     mmi_umms_app_sh_template_menu_rsk_handler,
     NULL,
     NULL},
 #endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 
    {
     SCR_ID_UMMS_NOTIFICATION_NEW_MMS,
     NULL,  /* g_umms_app_resourceDB+ENUM_SCR_ID_UMMS_NOTIFICATION_NEW_MMS, */
     0,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_mms_notification_pre_func,
     mmi_umms_app_ui_plug_in_mms_notification_post_func,
     mmi_umms_app_ui_infinite_time_list_draw_func,
     mmi_umms_app_sh_mms_new_notification_exit_func,
     mmi_umms_app_if_show_mms_notification,
     NULL,
     NULL,
     NULL,
     mmi_umms_app_sh_infinite_pop_up_delete_scr_handler},
    {
     SCR_ID_UMMS_NOTIFICATION_NEW_JAVA_MMS,
     NULL,  /* g_umms_app_resourceDB+ENUM_SCR_ID_UMMS_NOTIFICATION_NEW_JAVA_MMS, */
     0,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_mms_notification_pre_func,
     mmi_umms_app_ui_plug_in_mms_notification_post_func,
     mmi_umms_app_ui_infinite_time_list_draw_func,
     mmi_umms_app_sh_mms_new_notification_exit_func,
     mmi_umms_app_if_show_java_mms_notification,
     NULL,
     NULL,
     NULL,
     mmi_umms_app_sh_infinite_pop_up_delete_scr_handler},
    {
     SCR_ID_UMMS_PROGRESS,
     NULL,
     0,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_progress_pre_func,
     mmi_umms_app_ui_plug_in_progress_post_func,
     mmi_umms_app_ui_draw_progress_screen_draw_func,
     mmi_umms_app_sh_progress_screen_exit_func,
     mmi_umms_app_if_show_progress_screen,
     NULL,
     NULL,
     NULL,
     mmi_umms_app_sh_progress_delete_screen},
    {
     SCR_ID_UMMS_PROGRESS_TMPLT,
     NULL,
     0,
     mmi_umms_app_sh_template_create_func,
     mmi_umms_app_ui_plug_in_progress_pre_func,
     mmi_umms_app_ui_plug_in_progress_post_func,
     mmi_umms_app_ui_draw_progress_screen_draw_func,
     mmi_umms_app_sh_progress_screen_exit_func,
     mmi_umms_app_if_show_progress_screen,
     NULL,
     NULL,
     NULL,
     mmi_umms_app_sh_progress_delete_screen},
    {
     SCR_ID_UMMS_CONFIRM,
     NULL,
     0,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_confirm_pre_func,
     mmi_umms_app_ui_plug_in_confirm_post_func,
     mmi_umms_app_ui_draw_display_confirm_screen,
     mmi_umms_app_sh_confirm_screen_exit_func,
     mmi_umms_app_if_show_display_confirm_screen,
     NULL,
     NULL,
     NULL,
     NULL},
    /* ------------------------Niraj Added----------------------------------------------------// */
    {
     SCR_ID_UMMS_MESSAGE_SETTINGS_FOR_COMMON_SETTINGS,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_MESSAGE_SETTINGS_FOR_COMMON_SETTINGS,
     MENU_ID_UMMS_MESSAGE_SETTINGS_FOR_COMMON_SETTINGS,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_message_settings_menu_pre_func,
     mmi_umms_app_ui_plug_in_message_settings_menu_post_func,
     mmi_umms_app_ui_draw_cui_static_list_draw_func,
     mmi_umms_app_sh_message_settings_menu_exit_func,
     mmi_umms_app_show_message_settings_menu,
     NULL,
     NULL,
     NULL,
     NULL},
    {
     SCR_ID_UMMS_MESSAGE_SETTINGS,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_MESSAGE_SETTINGS,
     MENU_ID_UMMS_MMS_SETTINGS,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_mms_message_settings_menu_pre_func,
     mmi_umms_app_ui_plug_in_mms_message_settings_menu_post_func,
     mmi_umms_app_ui_draw_cui_static_list_draw_func,
     mmi_umms_app_sh_mms_message_settings_menu_exit_func,
     mmi_umms_app_if_show_mms_message_settings_menu,
     NULL,
     NULL,
     NULL,
     NULL},
    {
     SCR_ID_UMMS_COMPOSE_SETTINGS,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_COMPOSE_SETTINGS,
     MENU_ID_UMMS_MMS_SETTINGS_COMPOSE,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_compose_settings_pre_func,
     NULL,
     mmi_umms_app_ui_draw_inline_cui_selection_list_draw_func,
     mmi_umms_app_sh_compose_settings_exit_func,
     mmi_umms_app_if_show_compose_settings_menu,
     NULL,
     mmi_umms_app_sh_compose_settings_rsk_handler,
     mmi_umms_app_sh_compose_settings_hilite_handler,
     mmi_umms_app_sh_inline_selection_delete_scr_handler},
    {
     SCR_ID_UMMS_RETRIEVAL_SETTINGS,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_RETRIEVAL_SETTINGS,
     MENU_ID_UMMS_MMS_SETTINGS_RETRIEVAL,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_retrieval_settings_pre_func,
     NULL,
     mmi_umms_app_ui_draw_inline_cui_selection_list_draw_func,
     mmi_umms_app_sh_retrieval_settings_exit_func,
     mmi_umms_app_if_show_retrieval_settings_menu,
     NULL,
     mmi_umms_app_sh_retrieval_settings_rsk_handler,
     mmi_umms_app_sh_retrieval_settings_hilite_handler,
     mmi_umms_app_sh_inline_selection_delete_scr_handler},
    {
     SCR_ID_UMMS_SENDING_SETTINGS,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_SENDING_SETTINGS,
     MENU_ID_UMMS_MMS_SETTINGS_SENDING,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_sending_settings_pre_func,
     NULL,
     mmi_umms_app_ui_draw_inline_cui_selection_list_draw_func,
     mmi_umms_app_sh_sending_settings_exit_func,
     mmi_umms_app_if_show_sending_settings_menu,
     NULL,
     NULL,
     NULL,
     mmi_umms_app_sh_inline_selection_delete_scr_handler},
    {
     SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS,
     0,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_compose_signature_settings_pre_func,
     NULL,
     mmi_umms_app_ui_draw_inline_cui_selection_list_draw_func,
     mmi_umms_app_sh_compose_signature_settings_exit_func,
     mmi_umms_app_if_show_compose_signature_settings_menu,
     mmi_umms_app_sh_compose_signature_settings_lsk_handler,
     mmi_umms_app_sh_compose_signature_settings_rsk_handler,
     mmi_umms_app_sh_compose_signature_settings_hilite_handler,
     mmi_umms_app_sh_inline_selection_delete_scr_handler},
    {
     SCR_ID_UMMS_RETRIEVAL_FILTERS_SETTINGS,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_RETRIEVAL_FILTERS_SETTINGS,
     0,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_retrieval_filters_settings_pre_func,
     NULL,
     mmi_umms_app_ui_draw_inline_cui_selection_list_draw_func,
     mmi_umms_app_sh_retrieval_filters_settings_exit_func,
     mmi_umms_app_if_show_retrieval_filters_settings_menu,
     NULL,
     NULL,
     NULL,
     mmi_umms_app_sh_inline_selection_delete_scr_handler},
    {
     SCR_ID_UMMS_COMPOSE_IMAGE_OPTION,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_COMPOSE_IMAGE_OPTION,
     MENU_ID_UMMS_SIGNATURE_OPTION,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_signature_options_pre_func,
     mmi_umms_app_ui_plug_in_signature_options_post_func,
     mmi_umms_app_ui_draw_cui_static_list_draw_func,
     mmi_umms_app_sh_signature_options_exit_func,
     mmi_umms_app_if_show_signature_options_menu,
     NULL,
     NULL,
     NULL,
     NULL},
   /*********************************Amit added ***********************************/
 #if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) 
    {
     SCR_ID_UMMS_MMS_MESSAGE_STATUS,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_MMS_MESSAGE_STATUS,
     MENU_ID_UMMS_MMS_SETTINGS_MEMORY_STATUS,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_memory_status_menu_pre_func,
     mmi_umms_app_ui_plug_in_memory_status_menu_post_func,
     mmi_umms_app_ui_draw_cui_static_list_draw_func,
     mmi_umms_app_sh_memory_status_menu_exit_func,
     mmi_umms_app_if_show_memory_status_menu,
     NULL,
     NULL,
     NULL,
     NULL},
    {
     SCR_ID_UMMS_MMS_MESSAGE_STATUS_PHONE,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_MMS_MESSAGE_STATUS_PHONE,
     MENU_ID_UMMS_MMS_SETTINGS_MEMORY_STATUS_PHONE,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_memory_status_pre_func,
     mmi_umms_app_ui_plug_in_memory_status_post_func,
     mmi_umms_app_ui_property_status_screen_draw_func,
     mmi_umms_app_sh_memory_status_exit_func,
     mmi_umms_app_if_show_phone_memory_status_screen,
     NULL,
     mmi_umms_app_sh_property_status_rsk_handler,
     NULL,
     mmi_umms_app_sh_property_status_delete_scr_handler},
    {
     SCR_ID_UMMS_MMS_MESSAGE_STATUS_CARD,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_MMS_MESSAGE_STATUS_CARD,
     MENU_ID_UMMS_MMS_SETTINGS_MEMORY_STATUS_CARD,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_memory_status_pre_func,
     mmi_umms_app_ui_plug_in_memory_status_post_func,
     mmi_umms_app_ui_property_status_screen_draw_func,
     mmi_umms_app_sh_memory_status_exit_func,
     mmi_umms_app_if_show_card_memory_status_screen,
     NULL,
     mmi_umms_app_sh_property_status_rsk_handler,
     NULL,
     mmi_umms_app_sh_property_status_delete_scr_handler},
 #else /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    {
     SCR_ID_UMMS_MMS_MESSAGE_STATUS,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_MMS_MESSAGE_STATUS,
     MENU_ID_UMMS_MMS_SETTINGS_MEMORY_STATUS,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_memory_status_pre_func,
     mmi_umms_app_ui_plug_in_memory_status_post_func,
     mmi_umms_app_ui_property_status_screen_draw_func,
     mmi_umms_app_sh_memory_status_exit_func,
     mmi_umms_app_if_show_memory_status_screen,
     NULL,
     mmi_umms_app_sh_property_status_rsk_handler,
     NULL,
     mmi_umms_app_sh_property_status_delete_scr_handler},
 #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 

    {
     SCR_ID_UMMS_SAVE_OBJECT_ATTACHMENT_LIST,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_SAVE_OBJECT_ATTACHMENT_LIST,
     MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_ATTACHMENT_AS,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_save_objects_attachment_list_pre_func,
     mmi_umms_app_ui_plug_in_save_objects_attachment_list_post_func,
     mmi_umms_app_ui_dyncmic_list_draw_func,
     mmi_umms_app_sh_save_objects_attachment_list_exit_func,
     mmi_umms_app_if_show_save_objects_attchement_list,
     mmi_umms_app_sh_save_objects_attachment_list_lsk_handler,
     mmi_umms_app_sh_save_objects_attachment_list_rsk_handler,
     mmi_umms_app_sh_save_objects_attachment_list_hilite_handler,
     mmi_umms_app_sh_dynamic_list_delete_scr_handler},
    {
     SCR_ID_UMMS_SAVE_OBJECT,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_SAVE_OBJECT,
     MENU_ID_UMMS_OPTIONS_SAVE_OBJECTS,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_save_objects_list_pre_func,
     mmi_umms_app_ui_plug_in_save_objects_list_post_func,
     mmi_umms_app_ui_draw_cui_static_list_draw_func,
     mmi_umms_app_sh_save_objects_list_exit_func,
     mmi_umms_app_if_show_save_objects_item_list,
     NULL,
     NULL,
     NULL,
     NULL},
    {
     SCR_ID_UMMS_RETRIEVED_MMS_PROPERTIES,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_RETRIEVED_MMS_PROPERTIES,
     MENU_ID_UMMS_OPTIONS_PROPERTIES,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_properties_pre_func,
     mmi_umms_app_ui_plug_in_properties_post_func,
     mmi_umms_app_ui_property_status_screen_draw_func,
     mmi_umms_app_sh_mms_options_exit_func,
     mmi_umms_app_if_show_property_screen,
     NULL,
     mmi_umms_app_sh_static_list_rsk_handler,
     NULL,
     mmi_umms_app_sh_property_status_delete_scr_handler},
 #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
    {
     SCR_ID_UMMS_SORT_OPTION,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_SORT_OPTION,
     MENU_ID_UM_SORT_BY_OPT,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_sort_by_pre_func,
     mmi_umms_app_ui_plug_in_sort_by_post_func,
     mmi_umms_app_ui_draw_cui_static_list_draw_func,
     mmi_umms_app_sh_mms_options_exit_func,
     mmi_umms_app_if_show_sort_by_screen,
     mmi_umms_app_sh_sort_by_lsk_handler,
     NULL,
     NULL,
     NULL},
 #endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */ 
    {
     SCR_ID_UMMS_MMS_OPTIONS_USE_DETAILS,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_MMS_OPTIONS_USE_DETAILS,
     MENU_ID_UMMS_OPTIONS_USE_DETAILS,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_use_details_menu_pre_func,
     mmi_umms_app_ui_plug_in_use_details_menu_post_func,
     mmi_umms_app_ui_draw_cui_static_list_draw_func,
     mmi_umms_app_sh_use_details_menu_exit_func,
     mmi_umms_app_if_show_use_details_menu,
     NULL,
     NULL,
     NULL,
     NULL},
    {
     SCR_ID_UMMS_OPTIONS_USE_DETAILS_ADDRESSES_OPTIONS,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_OPTIONS_USE_DETAILS_ADDRESSES_OPTIONS,
     0, /* menu id is varaible as per selection */
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_show_use_details_addresses_options_pre_func,
     mmi_umms_app_ui_plug_in_show_use_details_addresses_options_post_func,
     mmi_umms_app_ui_draw_cui_static_list_draw_func,
     mmi_umms_app_sh_show_use_details_addresses_options_screen_exit_func,
     mmi_umms_app_if_show_use_details_addresses_options,
     NULL,
     NULL,
     NULL,
     NULL},

    {
     SCR_ID_UMMS_MESSAGE_STATUS,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_MESSAGE_STATUS,
     MENU_ID_UMMS_OUTBOX_OPTIONS_MESSAGE_STATUS,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_show_message_status_screen_pre_func,
     mmi_umms_app_ui_plug_in_message_status_post_func,
     mmi_umms_app_ui_property_status_screen_draw_func,
     mmi_umms_app_sh_message_status_screen_exit_func,
     mmi_umms_app_if_show_message_status_screen,
     NULL,
     mmi_umms_app_sh_property_status_rsk_handler,
     NULL,
     mmi_umms_app_sh_property_status_delete_scr_handler},
 #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
    {
     SCR_ID_UMMS_TEMPLATES,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_TEMPLATES,
     MENU_ID_UMMS_TEMPLATES_USER_DEFINED,
     mmi_umms_app_sh_template_create_func,
     mmi_umms_app_ui_plug_in_user_template_pre_func,
     mmi_umms_app_ui_plug_in_user_template_post_func,
     mmi_umms_app_ui_dyncmic_list_draw_func,
     mmi_umms_app_sh_user_template_exit_func,
     mmi_umms_app_if_show_user_template_list,
     mmi_umms_app_sh_mms_template_lsk_handler,
     mmi_umms_app_sh_user_template_rsk_handler,
     mmi_umms_app_sh_userdef_template_list_hilite_handler,
     mmi_umms_app_sh_userdef_template_delete_scr_handler},
    {
     SCR_ID_UMMS_TEMPLATES_OPTIONS,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_TEMPLATES_OPTIONS,
     MENU_ID_UMMS_TEMPLATES_OPTIONS,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_user_defined_options_pre_func,
     mmi_umms_app_ui_plug_in_user_defined_options_post_func,
     mmi_umms_app_ui_draw_cui_static_list_draw_func,
     mmi_umms_app_sh_mms_options_exit_func,
     mmi_umms_app_if_show_mms_template_option,
     NULL,
     NULL,
     NULL,
     NULL},
    {
     SCR_ID_UMMS_FWD_EDIT_CLUBBED,  /* temp taken for default template */
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_FWD_EDIT_CLUBBED,
     MENU_ID_UMMS_TEMPLATES_DEFAULT,
     mmi_umms_app_sh_template_create_func,
     mmi_umms_app_ui_plug_in_default_template_pre_func,
     mmi_umms_app_ui_plug_in_default_template_post_func,
     mmi_umms_app_ui_dyncmic_list_draw_func,
     mmi_umms_app_sh_default_template_exit_func,
     mmi_umms_app_if_show_default_template_list,
     mmi_umms_app_sh_mms_template_lsk_handler,
     mmi_umms_app_sh_user_template_rsk_handler,
     mmi_umms_app_sh_default_template_list_hilite_handler,
     mmi_umms_app_sh_userdef_template_delete_scr_handler},
 #endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 
    {
     SCR_ID_UMMS_DISPLAY_POPUP,
     NULL,
     0,
     mmi_umms_app_sh_create_popup_func,
     mmi_umms_app_ui_plug_in_popup_pre_func,
     mmi_umms_app_ui_plug_in_popup_post_func,
     mmi_umms_app_ui_draw_display_popup_screen,
     mmi_umms_app_sh_popup_screen_exit_func,
     mmi_umms_app_if_show_display_popup_screen,
     NULL,
     NULL,
     NULL,
     NULL},
    {
     15,
     g_umms_app_resourceDB + 33,
     0,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_show_new_message_popup_pre_func,
     mmi_umms_app_ui_plug_in_show_new_message_popup_post_func,
     mmi_umms_ui_show_new_message_popup_draw_func,
     mmi_umms_app_sh_show_new_message_popup_exit_func,
     mmi_umms_app_if_show_new_message_popup,
     NULL,
     NULL,
     NULL,
     mmi_umms_app_sh_infinite_pop_up_delete_scr_handler},
    {
     SCR_ID_UMMS_MMS_VIEWER,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_MMS_VIEWER,
     0,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_viewer_pre_func,
     mmi_umms_app_ui_plug_in_viewer_post_func,
     mmi_umms_app_ui_draw_viewer_screen,
     mmi_umms_app_sh_viewer_exit_func,
     mmi_umms_app_if_show_viewer_screen,
     mmi_umms_app_sh_viewer_lsk_hdlr,
     mmi_umms_app_sh_viewer_rsk_handler,
     NULL,
     mmi_umms_app_sh_viewer_delete_scr_handler},
 #ifdef __MMI_MMS_PREVIEW_GOTO__
    {
     SCR_ID_UMMS_PREVIEW_OPTIONS,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_PREVIEW_OPTIONS,
     0,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_mms_preview_menu_pre_func,
     mmi_umms_app_ui_plug_in_mms_preview_menu_post_func,
     mmi_umms_app_ui_draw_cui_static_list_draw_func,
     mmi_umms_app_sh_mms_preview_menu_exit_func,
     mmi_umms_app_if_show_preview_option,
     NULL,
     NULL,
     NULL,
     NULL},
    {
     SCR_ID_UMMS_PREVIEW_SLIDE_LIST,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_PREVIEW_SLIDE_LIST,
     0,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_mms_preview_slide_list_pre_func,
     mmi_umms_app_ui_plug_in_mms_preview_slide_list_post_func,
     mmi_umms_app_ui_dyncmic_list_draw_func,
     mmi_umms_app_sh_mms_options_exit_func, /* mmi_umms_app_sh_mms_preview_slide_list_exit_func, */
     mmi_umms_app_if_show_preview_slide_list,
     mmi_umms_app_sh_preview_slide_list_lsk_hdlr,
     mmi_umms_app_sh_static_list_rsk_handler,
     mmi_umms_app_sh_dynamic_list_hilite_handler,
     mmi_umms_app_sh_dynamic_list_delete_scr_handler},
 #endif /* __MMI_MMS_PREVIEW_GOTO__ */ 
 #if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) && !defined(__MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__)
    {
     SCR_ID_UMMS_MMS_PREFER_STORAGE,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_MMS_PREFER_STORAGE,
     MENU_ID_UMMS_MMS_SETTINGS_PREFER_STORAGE,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_pref_storage_pre_func,
     mmi_umms_app_ui_plug_in_pref_storage_post_func,
     mmi_umms_ui_radio_selection_list_draw_func,
     mmi_umms_app_sh_mms_pref_storage_exit_func,
     mmi_umms_app_if_show_pref_storage_option,
     NULL,
     mmi_umms_app_sh_radio_button_list_rsk_handler,
     mmi_umms_app_sh_radio_button_hilite_handler,
     NULL},
#ifdef __MMI_MMS_MSG_STORAGE_FILTER_SUPPORT__
     {
     SCR_ID_UMMS_MMS_MSG_FILTER,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_MMS_MSG_FILTER,
     MENU_ID_UMMS_MMS_SETTINGS_STORAGE_FILTER,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_pref_storage_pre_func,
     mmi_umms_app_ui_plug_in_pref_storage_post_func,
     mmi_umms_ui_chkbox_selection_list_draw_func,
     NULL,
     mmi_umms_app_if_show_msg_filter_option,
     NULL,
     mmi_umms_app_sh_radio_button_list_rsk_handler,
     NULL,
     NULL},
#endif
 #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
 #if (MMI_MAX_SIM_NUM == 2)
    {
     SCR_ID_UMMS_SIM_OPTION,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_SIM_OPTION,
     MENU_ID_UMMS_OPTIONS_RESEND,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_sim_options_pre_func,
     mmi_umms_app_ui_plug_in_sim_options_post_func,
     mmi_umms_app_ui_draw_cui_static_list_draw_func,
     mmi_umms_app_sh_sim_options_exit_func,
     mmi_umms_app_if_show_sim_option,
     NULL,
     NULL,
     NULL,
     NULL},
 #endif /* (MMI_MAX_SIM_NUM == 2) */ 
    {
     SCR_ID_UMMS_READ_DELIVERY_REPORT_VIEW_SCREEN,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_READ_DELIVERY_REPORT_VIEW_SCREEN,
     MENU_ID_UMMS_OPTIONS_PROPERTIES,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_abnormal_view_pre_func,
     mmi_umms_app_ui_plug_in_abnormal_view_post_func,
     mmi_umms_app_ui_property_status_screen_draw_func,
     mmi_umms_app_sh_read_delivery_report_view_exit_func,
     mmi_umms_app_if_show_rr_dr_view_screen,
     mmi_umms_app_sh_read_delivery_report_view_lsk_handler,
     mmi_umms_app_sh_read_delivery_report_view_rsk_handler,
     NULL,
     mmi_umms_app_sh_property_status_delete_scr_handler},
 #ifdef __MMI_MMS_ITERATOR_VIEWER__
    {
     SCR_ID_UMMS_HANDLE_ABNORMAL_VIEW_SCREEN,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_HANDLE_ABNORMAL_VIEW_SCREEN,
     MENU_ID_UMMS_OPTIONS_PROPERTIES,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_abnormal_view_pre_func,
     mmi_umms_app_ui_plug_in_abnormal_view_post_func,
     mmi_umms_app_ui_property_status_screen_draw_func,
     mmi_umms_app_sh_read_delivery_report_view_exit_func,
     mmi_umms_app_if_show_abnormal_view_screen,
     mmi_umms_app_sh_abnormal_view_lsk_handler,
     mmi_umms_app_sh_read_delivery_report_view_rsk_handler,
     NULL,
     mmi_umms_app_sh_property_status_delete_scr_handler},
 #endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 
    {
     SCR_ID_UMMS_CALLBACK_DISPLAY_POPUP,    /* temp taken for any popup */
     NULL,
     0,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_popup_pre_func,
     mmi_umms_app_ui_plug_in_popup_post_func,
     mmi_umms_app_ui_draw_display_callback_popup_screen,
     mmi_umms_app_sh_popup_screen_exit_func,
     mmi_umms_app_if_show_display_callback_popup_screen,
     NULL,
     NULL,
     NULL,
     NULL},
 #if (MMI_MAX_SIM_NUM >= 2)
    {
     SCR_ID_UMMS_MESSAGE_SETTINGS_SIM_SELECTION,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_MESSAGE_SETTINGS_SIM_SELECTION,
     MENU_ID_UMMS_MMS_SETTING_SIM_SELECTION,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_settings_sim_selection_pre_func,
     mmi_umms_app_ui_plug_in_settings_sim_selection_post_func,
     mmi_umms_app_ui_draw_cui_static_list_draw_func,
     mmi_umms_app_sh_settings_sim_selection_exit_func,
     mmi_umms_app_if_show_sim_selection_profile_menu,
     NULL,
     NULL,
     NULL,
     NULL},
 #endif /* (MMI_MAX_SIM_NUM >= 2) */ 
    {
     SCR_ID_UMMS_DISPLAY_INFINITE_POPUP,
     NULL,  /* g_umms_app_resourceDB+ENUM_SCR_ID_UMMS_NOTIFICATION_NEW_MMS, */
     0,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_mms_full_pre_func,
     mmi_umms_app_ui_plug_in_mms_full_post_func,
     mmi_umms_app_ui_infinite_time_list_draw_func,
     mmi_umms_app_sh_mms_full_exit_func,
     mmi_umms_app_if_show_mms_full_popup,
     NULL,
     NULL,
     NULL,
     mmi_umms_app_sh_infinite_pop_up_delete_scr_handler},
 #ifdef __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__
    {
     SCR_ID_UMMS_MMS_DELIVERY_STATUS,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_MMS_DELIVERY_STATUS,
     MENU_ID_UMMS_OPTIONS_DELIVERY_STATUS,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_dr_rr_status_pre_func,
     mmi_umms_app_ui_plug_in_memory_status_post_func,
     mmi_umms_app_ui_property_status_screen_draw_func,
     NULL,
     mmi_umms_app_if_show_delivery_status,
     NULL,
     mmi_umms_app_sh_property_status_rsk_handler,
     NULL,
     mmi_umms_app_sh_property_status_delete_scr_handler},
    {
     SCR_ID_UMMS_MMS_READ_STATUS,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_MMS_READ_STATUS,
     MENU_ID_UMMS_OPTIONS_READ_STATUS,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_dr_rr_status_pre_func,
     mmi_umms_app_ui_plug_in_memory_status_post_func,
     mmi_umms_app_ui_property_status_screen_draw_func,
     NULL,
     mmi_umms_app_if_show_read_status,
     NULL,
     mmi_umms_app_sh_property_status_rsk_handler,
     NULL,
     mmi_umms_app_sh_property_status_delete_scr_handler},
 #endif /* __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__ */ 
 #ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    {
     SCR_ID_UMMS_MMS_OPTION_SLIM,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_MMS_OPTION_SLIM,
     MENU_ID_UMMS_OPTIONS_SLIM,
     mmi_umms_app_sh_option_slim_create_func,
     mmi_umms_app_ui_plug_in_option_slim_menu_pre_func,
     mmi_umms_app_ui_plug_in_viewer_post_func,
     mmi_umms_app_ui_draw_cui_static_list_draw_func,
     mmi_umms_app_sh_option_slim_menu_exit_func,
     mmi_umms_app_if_show_option_screen_slim,
     NULL,
     NULL,
     NULL,
     NULL},
    {
     SCR_ID_UMMS_ADD_RECIPIENT,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_ADD_RECIPIENT,
     MENU_ID_UMMS_DRAFT_OPTIONS,
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_add_recipient_list_pre_func,
     mmi_umms_app_ui_plug_in_add_recipient_list_post_func,
     mmi_umms_app_ui_dyncmic_list_draw_func,
     mmi_umms_app_sh_mms_options_exit_func,
     mmi_umms_app_if_show_recipient_list,
     mmi_umms_app_sh_show_recipient_list_lsk_handler,
     mmi_umms_app_sh_static_list_rsk_handler,
     mmi_umms_app_sh_show_recipient_list_hilite_handler,
     mmi_umms_app_sh_show_recipient_list_delete_scr_handler},
    {
     SCR_ID_UMMS_ADD_RECIPIENT_OPTION,
     g_umms_app_resourceDB + ENUM_SCR_ID_UMMS_ADD_RECIPIENT_OPTION,
     MENU_ID_UMMS_RECIPIENT_SLIM,   /* menu id is varaible as per selection */
     mmi_umms_app_sh_create_func,
     mmi_umms_app_ui_plug_in_option_slim_menu_pre_func,
     mmi_umms_app_ui_plug_in_option_slim_menu_post_func,
     mmi_umms_app_ui_draw_cui_static_list_draw_func,
     mmi_umms_app_sh_option_slim_menu_exit_func,
     mmi_umms_app_if_show_recipient_addresses_options,
     NULL,
     NULL,
     NULL,
     NULL},
 #endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
};


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_resource_get_screenDB
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_umms_app_screenDB_struct *mmi_umms_app_resource_get_screenDB(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;
    U16 maxCount = MMI_UMMS_SCR_DB_MAX;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < maxCount; index++)
    {
        if (g_umms_app_screenDB[index].scrn_id == scr_id)
        {
            return (mmi_umms_app_screenDB_struct*) (&g_umms_app_screenDB[index]);
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_resource_get_resourceDB
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_umms_app_resourceDB_struct *mmi_umms_app_resource_get_resourceDB(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;
    U16 maxCount = MMI_UMMS_RES_DB_MAX;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < maxCount; index++)
    {
        if (g_umms_app_resourceDB[index].scrn_id == scr_id)
        {
            return &g_umms_app_resourceDB[index];
        }
    }

    return NULL;
}
#endif /* __MMI_MMS_2__ */ /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ /* __MMI_MMS_2__ */

