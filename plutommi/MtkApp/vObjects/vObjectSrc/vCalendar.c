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
 * vCalendar.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file is implements vCalendar application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MMI_VCALENDAR_C
#define _MMI_VCALENDAR_C

#include "MMI_features.h"

#if defined(__MMI_VCALENDAR__)

#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "MMIDataType.h"
#include "custom_mmi_default_value.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "mmi_common_app_trc.h"
#include "fs_func.h"
#include "TodolistSrvGprot.h"
#include "AlertScreen.h"
#include "wgui_categories_util.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "mms_api.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "kal_trace.h"
#include "mmi_frm_history_gprot.h"
#include "CustMenuRes.h"
#include "mmi_rp_file_type_def.h"
#include "CustDataRes.h"
#include "fs_type.h"
#include "CommonScreensResDef.h"
#include "fs_errcode.h"
#include "ToDoListProt.h"
#include "vCalendar.h"
#include "vObjects.h"
#include "ToDoListGprot.h"

#ifndef __COSMOS_MMI__
#include "mmi_rp_app_calendar_def.h"
#include "mmi_rp_app_todolist_def.h"
#include "mmi_rp_srv_syncml_def.h"
#include "mmi_rp_app_organizer_def.h"
#ifdef __MMI_INDICAL__
#include "IndianCalendarDef.h"
#endif
#else
#define ORGANIZER_CALENDER_MENU 0
#define STR_TODO_SET_REPEAT_ONCE 0
#define ORGANIZER_TITLE_IMAGEID 0
#define STR_ID_SYNC_CODE_FORBIDDEN 0
#endif

#include "mmi_rp_srv_vcalendar_def.h"
#include "FileMgrSrvGProt.h"
#include "Filemgrcuigprot.h"
#include "fmt_struct.h"
#include "MessagesExDcl.h"
#include "SettingProfileEnum.h"
#include "BTMMIScrGprots.h"
#include "Menucuigprot.h"
#include "Vcalsrvgprot.h"
#define VCAL_TEST_CODE
#include "Conversions.h"
#include "PhoneSetupGprots.h"
#ifdef __MMI_OPP_SUPPORT__
#include "Btsendcuigprot.h"
#endif 
#ifdef __MMI_EMAIL__
#include "EmailAppGprot.h"
#endif
#ifdef __SYNCML_SUPPORT__
#include "SyncMLGprot.h"
#endif
#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif 
#include "SmsCuiGprot.h"

#include "Inlinecuigprot.h"
#ifdef __MMI_BIRTHDAY_REMINDER__
#include "birthdayprot.h"
extern birthday_context_struct g_birth_cntx;
#endif


/*****************************************************************************
 * Define
 *****************************************************************************/
#define MMI_VCAL_TRACE0(sub_grp) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp)

#define MMI_VCAL_TRACE1(sub_grp, arg) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg)
		
#define MMI_VCAL_TRACE2(sub_grp, arg1, arg2) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2)

#define MMI_VCAL_TRACE3(sub_grp, arg1, arg2, arg3) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2, arg3)
		

#define VCAL_REMOVE_PRE_WS    0
#define VCAL_REMOVE_POST_WS    1
#define VCAL_REMOVE_BOTH_WS    2
#define VCAL_CATEGORY_REMINDER    "Reminder"    
#define VCAL_CATEGORY_MEETING     "Meeting"    
#define VCAL_CATEGORY_COURSE      "Course"    
#define VCAL_CATEGORY_DATE        "Date"    
#define VCAL_CATEGORY_CALL        "Call"    
#define VCAL_CATEGORY_ANNIVERSARY "Anniversary"    
#define VCAL_CATEGORY_BIRTHDAY    "Birthday"

/* vcalendar time format: iCal2.0-4.3.5 */
#define MMI_VCAL_TIME_UTC			0
#define MMI_VCAL_TIME_LOCAL		1
#define MMI_VCAL_TIME_LOCAL_TZ	2


/* 
 * Local Variable
 */
U32 g_vclndr_fmgr_service_id;
#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
static mmi_id vclndr_fmgr_sms_forward_parent_gid;
static mmi_id vclndr_fmgr_sms_forward_gid;
#endif

#if defined(__MMI_FILE_MANAGER__)
mmi_id vclndr_fmgr_folder_selector_gid;
mmi_id vclndr_fmgr_filename_gid;
#endif

/* the flag whether to send a fail event to parent or not */
MMI_BOOL g_vcal_popup_user_tag;

/*********************************************************************************
 * Local Function
 *********************************************************************************/ 
static void mmi_vclndr_uti_del_default_file(void);

#if defined(__MMI_MMS__) || defined(__MMI_EMAIL__)
static void mmi_vcal_uti_send_get_default_filename(WCHAR *result);
#endif

#if defined(__MMI_OPP_SUPPORT__)
static void mmi_vcal_opp_forward(cui_vcal_send_cntx_struct *cntx);
#endif

#if defined(__MMI_MMS__)
static void mmi_vclndr_mms_forward(cui_vcal_send_cntx_struct *cntx);
static void mmi_vclndr_forward_mms_cb(void *param);
#endif

#ifdef __MMI_EMAIL__
static void mmi_vclndr_forward_email(cui_vcal_send_cntx_struct *cntx);
static void mmi_vclndr_forward_email_call_back(void *param);
#endif

#if defined(__MMI_FILE_MANAGER__)
static mmi_ret mmi_vclndr_fmgr_sms_forward_call_back(mmi_event_struct *evt);
static mmi_ret mmi_vcal_recv_from_file_mgr_proc(mmi_event_struct* evt);
#endif

static mmi_ret cui_vcal_save_to_file_group_proc(mmi_event_struct *evt);
static mmi_ret cui_vcal_save_to_tdl_group_proc(mmi_event_struct *evt);
static mmi_ret cui_vcal_recv_group_proc(mmi_event_struct *evt);
static mmi_ret cui_vcal_send_group_proc(mmi_event_struct *evt);
static void cui_vcal_recv_menu_select_hdlr(mmi_event_struct *evt);



/*********************************************************************************
 * Global Variable
 *********************************************************************************/
//extern const CHAR *g_vobj_charset[];
mmi_vcal_context_struct g_vcal_cntx;

const CHAR *const g_vcal_fileds[VCAL_TOTAL_FILEDS] = 
{
    "BEGIN:VCALENDAR",
    "VERSION:1.0",
    "BEGIN:VEVENT",
    "BEGIN:VTODO",
    "DTSTART",
    "DTEND",
    "DUE",
    "TZID",
    "SUMMARY",
    "DESCRIPTION",
    "RRULE",
    "DALARM",
    "AALARM",
    "END:VTODO",
    "END:VEVENT",
    "END:VCALENDAR",
    "CLASS",
    "LOCATION",
    "PRIORITY",
    "COMPLETED",
    "LAST-MODIFIED",
    "CATEGORIES",
    "STATUS",
    "UID",
    "X-",
    "PRODID",
    "SEQUENCE"
};


#define VCAL_INITIALIZATION
/*****************************************************************************
 * FUNCTION
 *  mmi_vcal_free_buffer
 * DESCRIPTION
 *  Release all dynamic allocated memory used in vCalendar.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcal_free_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


#define VCAL_COMMON_INTERFACE
#if defined(__MMI_OPP_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_vcal_opp_forward
 * DESCRIPTION
 *  Forward a task to Bluetooth
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vcal_opp_forward(cui_vcal_send_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *path;
    cui_bt_sending_obj_struct obj;
    S32 result;
    cui_bt_sending_para_struct sending_para;
    srv_vcal_build_struct *handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->event.evt_id = EVT_ID_CUI_VCAL_NOT_SUPPORT;
    path = OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(WCHAR));
    mmi_vcal_get_default_filename(path);
    FS_Delete((U16*) path);
	g_vcal_cntx.time_fmt_flag = MMI_VCALNDR_TIME_FMT_UTC; /* Local time */

    handle = srv_vcal_build_begin((U16*)path, SRV_VCAL_VER_VCAL_1_0);
	 if (SRV_TDL_VCAL_EVENT == cntx->obj.vcal_type)
	 {
		 result = srv_vcal_build_add(handle, &cntx->obj.event, SRV_VCAL_VEVENT);			
	 }
	 else
	 {
		 result = srv_vcal_build_add(handle, &cntx->obj.task, SRV_VCAL_VTODO);
	 }
    result = srv_vcal_build_end(handle);

    if (result != SRV_VCAL_RESULT_SUCCESS)
    {
        FS_Delete((U16*) path);
        mmi_popup_display_simple(
                        (WCHAR*)get_string(srv_fmgr_fs_error_get_string(result)),
                        (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(result),
                        GRP_ID_VCLNDR_SEND,
                        0);                
        goto MMI_VCAL_ERROR_RETURN;
    }
    obj.data.obj_type = CUI_BT_SENDIND_USE_FILE;
    obj.data.u.file.path = (U16*)path;
    obj.data.u.file.is_sfn = MMI_FALSE;
    sending_para.obj = &obj;
    sending_para.option = CUI_BT_SENDIND_OPT_NORMAL;          
    cui_bt_sending_launch(GRP_ID_VCLNDR_SEND, &sending_para);    
    cntx->event.evt_id = EVT_ID_CUI_VCAL_SUCCESS;
    
MMI_VCAL_ERROR_RETURN:
    OslMfree(path);
    return;
}

#endif /* defined(__MMI_OPP_SUPPORT__) */

#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
/*****************************************************************************
 * FUNCTION
 *  mmi_vcal_sms_forward
 * DESCRIPTION
 *  Forward a task to SMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcal_sms_forward(cui_vcal_send_cntx_struct *send_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    WCHAR *path;
    srv_vcal_build_struct *handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    path = OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(WCHAR));
    mmi_vcal_get_default_filename(path);

    handle = srv_vcal_build_begin((U16*)path, SRV_VCAL_VER_VCAL_1_0);
    if (SRV_TDL_VCAL_EVENT == send_cntx->obj.vcal_type)
    {
        result = srv_vcal_build_add(handle, &send_cntx->obj.event, SRV_VCAL_VEVENT);            
    }
    else
    {
        result = srv_vcal_build_add(handle, &send_cntx->obj.task, SRV_VCAL_VTODO);
    }
    result = srv_vcal_build_end(handle);
    
    if (result != SRV_VCAL_RESULT_SUCCESS)
    {
        FS_Delete((U16*)path);            
        mmi_popup_display_simple(
                        (WCHAR*)get_string(srv_fmgr_fs_error_get_string(result)),
                        (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(result),
                        GRP_ID_VCLNDR_SEND,
                        0);   
        send_cntx->event.evt_id = EVT_ID_CUI_VCAL_NOT_SUPPORT;
        goto MMI_VCAL_ERROR_RETURN;
    }
    send_cntx = (cui_vcal_send_cntx_struct*)mmi_frm_group_get_user_data(GRP_ID_VCLNDR_SEND);
    send_cntx->child_id = cui_sms_send_create(GRP_ID_VCLNDR_SEND);  
    if (send_cntx->child_id != GRP_ID_INVALID)
    {
        cui_sms_set_send_content_data_file(send_cntx->child_id, (U16*)path);
        cui_sms_set_send_data_port(send_cntx->child_id, MMI_VCAL_SRC_PORT, MMI_VCAL_VCLNDR_PORT);
        cui_sms_send_run(send_cntx->child_id);
    }
    else
    {
        mmi_frm_group_close(send_cntx->group_id); 
    }
    
MMI_VCAL_ERROR_RETURN:
    OslMfree(path);
    return;    
}
#endif /* !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__) */


#if defined(__MMI_MMS__)
/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_mms_forward
 * DESCRIPTION
 *  Create temporary file and forward to MMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vclndr_mms_forward(cui_vcal_send_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_content_entry_struct data;
    WCHAR *path;
    S32 result;
    srv_vcal_build_struct *handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    path = OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(WCHAR));
    memset(&data, 0x00, sizeof(mms_content_entry_struct));
    mmi_vcal_uti_send_get_default_filename(path);        

    handle = srv_vcal_build_begin((U16*)path, SRV_VCAL_VER_VCAL_1_0);
    if (SRV_TDL_VCAL_EVENT == cntx->obj.vcal_type)
    {
        result = srv_vcal_build_add(handle, &cntx->obj.event, SRV_VCAL_VEVENT);            
    }
    else
    {
        result = srv_vcal_build_add(handle, &cntx->obj.task, SRV_VCAL_VTODO);
    }
    result = srv_vcal_build_end(handle);
	
    if (result != SRV_VCAL_RESULT_SUCCESS)
    {
        FS_Delete((U16*)path);
        mmi_popup_display_simple(
                        (WCHAR*)get_string(srv_fmgr_fs_error_get_string(result)),
                        (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(result),
                        GRP_ID_VCLNDR_SEND,
                        0);                
        cntx->event.evt_id = EVT_ID_CUI_VCAL_NOT_SUPPORT;
        OslMfree(path);
        path = NULL;
        goto MMI_VCAL_ERROR_RETURN;
    }
    data.mode = MMS_NEW_FILE;
    data.file_path = (char*)path;
    data.callback = mmi_vclndr_forward_mms_cb;
    data.callback_param = path;
    mms_content_insert_hdlr_with_callback(&data);
    cntx->event.evt_id = EVT_ID_CUI_VCAL_SUCCESS;
    
MMI_VCAL_ERROR_RETURN:    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_forward_mms_cb
 * DESCRIPTION
 *  callback function of forwarding MMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vclndr_forward_mms_cb(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    cui_vcal_send_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = mmi_frm_group_get_user_data(GRP_ID_VCLNDR_SEND);
    
    FS_Delete((U16*)param);    
    if (param != NULL)
    {
        OslMfree(param);
    }
    mmi_frm_group_send_to_parent(cntx->group_id, (mmi_group_event_struct*)&cntx->event);    
}


#endif /* defined(__MMI_MMS__) */ // #if defined(__MMI_MMS__)

#if defined(__MMI_EMAIL__)
/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_email_highlight_forward
 * DESCRIPTION
 *  Highlight handler of Send To Email option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vclndr_forward_email(cui_vcal_send_cntx_struct *cntx)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *path;
    S32 result;
    srv_vcal_build_struct *handle;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->event.evt_id = EVT_ID_CUI_VCAL_NOT_SUPPORT;
    path = OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(WCHAR));

    mmi_vcal_uti_send_get_default_filename(path); 

    if (mmi_ucs2strlen((const CHAR*)path) > 0)
    {
        handle = srv_vcal_build_begin((U16*)path, SRV_VCAL_VER_VCAL_1_0);
		if (SRV_TDL_VCAL_EVENT == cntx->obj.vcal_type)
	    {
		    result = srv_vcal_build_add(handle, &cntx->obj.event, SRV_VCAL_VEVENT); 		   
	    }
	    else
	    {
	        result = srv_vcal_build_add(handle, &cntx->obj.task, SRV_VCAL_VTODO);
	    }
        result = srv_vcal_build_end(handle);
            
        if (result != SRV_VCAL_RESULT_SUCCESS)
        {
            FS_Delete((U16*)path);
            mmi_popup_display_simple(
                            (WCHAR*)get_string(srv_fmgr_fs_error_get_string(result)),
                            (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(result),
                            GRP_ID_VCLNDR_SEND,
                            0);                
            OslMfree(path);
            goto MMI_VCAL_ERROR_RETURN;
        }
		mmi_email_app_send_attch_from_vobj((CHAR*)path, mmi_vclndr_forward_email_call_back);
		cntx->event.evt_id = EVT_ID_CUI_VCAL_SUCCESS;
    }
    else
    {
        mmi_popup_display_simple(
                        (WCHAR*)get_string(STR_GLOBAL_ERROR),
                        MMI_EVENT_FAILURE,
                        GRP_ID_VCLNDR_SEND,
                        0);                  
		OslMfree(path);
    }
    
MMI_VCAL_ERROR_RETURN:    
    mmi_frm_group_send_to_parent(cntx->group_id, (mmi_group_event_struct*)&cntx->event);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_forward_email_call_back
 * DESCRIPTION
 *  call back function of send vclndr through Email, delete the file and free the buffer
 *  should go back to proper screen when send finish.
 * PARAMETERS
 *  flag        [IN]        Result of send vcard through SMS
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vclndr_forward_email_call_back(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FS_Delete((U16*)param);    
	if (param != NULL)
	{
		OslMfree(param);
		param = NULL;
	}
}
#endif /* __MMI_EMAIL__ */ 

#if defined(__MMI_FILE_MANAGER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_vcal_can_recv
 * DESCRIPTION
 *  Receive vCalendar object from file manager.
 * PARAMETERS
 *  file_path_name      [IN]        Filename and path of selected file.
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_vcal_can_recv(CHAR *file_path_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_vcal_type_enum vcal_type = SRV_VCAL_VTYPE_END_OF_ENUM;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_path_name == NULL)
    {
        return MMI_FALSE;
    }

    srv_vcal_utility_get_vtype((U16*)file_path_name, (U16*)&vcal_type);
	MMI_VCAL_TRACE1(MMI_VCAL_ENTRY_CAN_RECV, vcal_type);  

    #ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
        if (mmi_syncml_is_calendar_sync_now() && vcal_type == SRV_VCAL_VEVENT)
        {
            return MMI_FALSE;
        }
    #endif
    #ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
        if (mmi_syncml_is_task_sync_now() && vcal_type == SRV_VCAL_VTODO)
        {
            return MMI_FALSE;
        }
    #endif

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcal_fmgr_recv
 * DESCRIPTION
 *  Receive vCalendar object from file manager.
 * PARAMETERS
 *  file_path_name      [IN]        Filename and path of selected file.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcal_fmgr_recv(CHAR *file_path_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id parent_id, sg_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_path_name == NULL)
    {
        return;
    }
    parent_id = mmi_frm_group_create(
                                GRP_ID_ROOT, 
                                GRP_ID_AUTO_GEN, 
                                mmi_vcal_recv_from_file_mgr_proc, 
                                NULL);
    mmi_frm_group_enter(parent_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    sg_id = cui_vcal_save_to_tdl_create(parent_id);
    cui_vcal_save_to_tdl_set_path(sg_id, (WCHAR*)file_path_name);
    cui_vcal_save_to_tdl_run(sg_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcal_recv_from_file_mgr_proc
 * DESCRIPTION
 *  A pre-entry function of receiving vcalendar functuion.
 * PARAMETERS
 *  path        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_vcal_recv_from_file_mgr_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_VCAL_SUCCESS:
        case EVT_ID_CUI_VCAL_FAIL_NOT_ENOUGH_MEMORY:
        case EVT_ID_CUI_VCAL_NOT_SUPPORT:
        case EVT_ID_CUI_VCAL_USER_CANCEL:
        {
            cui_vcal_result_struct *recv_evt = (cui_vcal_result_struct*)evt;        
            cui_vcal_save_to_tdl_close(recv_evt->sender_id);
        }
        default:
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_fmgr_sms_forward_call_back
 * DESCRIPTION
 *  Callback function for send vCalendar via SMS from FMGR
 * PARAMETERS
 *  flag        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_vclndr_fmgr_sms_forward_call_back(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_evt_sms_send_struct *event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_SMS_SEND:
        {
            event = (cui_evt_sms_send_struct*)evt;
            if (event ->is_send_finish)
            {
                cui_sms_send_close(vclndr_fmgr_sms_forward_gid);
                mmi_frm_group_close(vclndr_fmgr_sms_forward_parent_gid);  
            }
            break;
        }
        case EVT_ID_GROUP_DEINIT:
        {
            vclndr_fmgr_sms_forward_gid = GRP_ID_INVALID;  
            vclndr_fmgr_sms_forward_parent_gid = GRP_ID_INVALID;  
            break;
        }
        default:
            break;
    }

    return MMI_RET_OK;  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcal_fmgr_sms_forward
 * DESCRIPTION
 *  Forward a vCalendar object from file manager via SMS
 * PARAMETERS
 *  path        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcal_fmgr_sms_forward(CHAR *path)
{
#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vclndr_fmgr_sms_forward_parent_gid = mmi_frm_group_create(
                                                GRP_ID_ROOT, 
                                                GRP_ID_AUTO_GEN, 
                                                mmi_vclndr_fmgr_sms_forward_call_back, 
                                                NULL);
    mmi_frm_group_enter(vclndr_fmgr_sms_forward_parent_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    vclndr_fmgr_sms_forward_gid = cui_sms_send_create(vclndr_fmgr_sms_forward_parent_gid);  
    if (vclndr_fmgr_sms_forward_gid != GRP_ID_INVALID)
    {
        cui_sms_set_send_content_data_file(vclndr_fmgr_sms_forward_gid, (U16*)path);
        cui_sms_set_send_data_port(vclndr_fmgr_sms_forward_gid, VOBJ_SRC_PORT, VOBJ_VCLNDR_PORT);
        cui_sms_send_run(vclndr_fmgr_sms_forward_gid);
    }
    else
    {
        mmi_frm_group_close(vclndr_fmgr_sms_forward_parent_gid); 
    }
    //mmi_ems_vobject_send_by_ems(0x0000, VOBJ_VCLNDR_PORT, path, mmi_vclndr_fmgr_sms_forward_call_back);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcal_fmgr_use_enabler
 * DESCRIPTION
 *  Forward a vCalendar object from file manager via SMS
 * PARAMETERS
 *  path        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcal_fmgr_use_enabler(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_vcal_type_enum vcal_type = SRV_VCAL_VTYPE_END_OF_ENUM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filepath == NULL)
    {
        return;
    }
    
    srv_vcal_utility_get_vtype((U16*)filepath, (U16*)&vcal_type);
    
    if (vcal_type == SRV_VCAL_VEVENT)
    {
        mmi_frm_hide_menu_item(MENU_VCLNDR_USE_AS_TASK);
        mmi_frm_unhide_menu_item(MENU_VCLNDR_USE_AS_EVENT);
    }
    else if (vcal_type == SRV_VCAL_VTODO)
    {
        mmi_frm_hide_menu_item(MENU_VCLNDR_USE_AS_EVENT);
        mmi_frm_unhide_menu_item(MENU_VCLNDR_USE_AS_TASK);     
    } 
    else
    {
        //Add trace;
        mmi_frm_hide_menu_item(MENU_VCLNDR_USE_AS_EVENT);
        mmi_frm_hide_menu_item(MENU_VCLNDR_USE_AS_TASK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcal_fmgr_use_handler
 * DESCRIPTION
 *  Forward a vCalendar object from file manager via SMS
 * PARAMETERS
 *  path        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vcal_fmgr_use_handler(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_fileinfo_struct info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_fmgr_types_query_fileinfo(&info);
    
#ifdef __SYNCML_SUPPORT__
    if (info.type == FMGR_TYPE_VCS && !mmi_vcal_can_recv((CHAR*)filepath))
    {
        mmi_popup_display_simple((WCHAR*)GetString(STR_ID_SYNC_CODE_FORBIDDEN), MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
        return;
    }
#endif
    mmi_vcal_fmgr_recv((CHAR*)filepath);
}

#endif /* defined(__MMI_FILE_MANAGER__) */


#define VCAL_UTILITY
#if defined(__MMI_MMS__) || defined(__MMI_EMAIL__)
/*****************************************************************************
 * FUNCTION
 *  mmi_vcal_uti_send_get_default_filename
 * DESCRIPTION
 *  callback function of forwarding MMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vcal_uti_send_get_default_filename(WCHAR *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *filename;
    WCHAR temp_name[MAX_TODO_NOTE_LEN] = {0};
    U16* temp_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    filename = OslMalloc((MAX_TODO_NOTE_LEN) * sizeof(U16));
    memset(filename, 0, (MAX_TODO_NOTE_LEN) * sizeof(U16));

    if (g_tdl_cntx.vcal_filter == SRV_TDL_VCAL_EVENT)
    {
        memcpy(temp_name, g_tdl_cntx.curr_event.subject, MAX_TODO_LIST_NOTE - ENCODING_LENGTH);
    }
    else
    {
        memcpy(temp_name, g_tdl_cntx.curr_task.subject, MAX_TODO_LIST_NOTE - ENCODING_LENGTH);
    }
    temp_ptr = (U16*)srv_fmgr_path_skip_leading_space((WCHAR*)((CHAR*)temp_name));
    mmi_wcsncpy(filename, temp_ptr, MAX_TODO_NOTE_LEN - 1);

    if (!srv_fmgr_path_is_filename_valid((WCHAR*)filename))
    {
        mmi_asc_to_wcs(filename, "no content");
    }
    kal_wsprintf((U16*)result, "%c:\\%s\\%w%s", MMI_VCAL_DRV, MMI_VCAL_FILE_PATH, filename, MMI_VCAL_DEFAULT_FILE_NAME);
    OslMfree(filename);
}
#endif /* defined(__MMI_MMS__) || defined(__MMI_EMAIL__) */

/*****************************************************************************
 * FUNCTION
 *  mmi_vcal_get_default_filename
 * DESCRIPTION
 *  To generate default file name used for other application
 * PARAMETERS
 *  result      [IN/OUT]        Pointer to the result
 * RETURNS
 *  TURE of file exists; otherwise FALSE.(?)
 *****************************************************************************/
void mmi_vcal_get_default_filename(WCHAR *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(result,"%c:\\%s\\%s", MMI_VCAL_DRV, MMI_VCAL_FILE_PATH, MMI_VCAL_DEFAULT_FILE_NAME);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_uti_del_default_file
 * DESCRIPTION
 *  To delete default file buffer used for other application
 * PARAMETERS
 *  void
 * RETURNS
 *  TURE of file exists; otherwise FALSE.(?)
 *****************************************************************************/
static void mmi_vclndr_uti_del_default_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    path = OslMalloc(SRV_FMGR_PATH_MAX_LEN * sizeof(WCHAR));
    kal_wsprintf(path, "%c:\\%s\\%s", MMI_VCAL_DRV, MMI_VCAL_FILE_PATH, MMI_VCAL_DEFAULT_FILE_NAME);    
    FS_Delete((U16*)path);
    OslMfree(path);
}


#define CUI_DEFINE
/*****************************************************************************
 * FUNCTION
 *  cui_vcal_save_to_file_create
 * DESCRIPTION
 *  Create send vCalendar CUI.
 * PARAMETERS
 *  mmi_id : [IN] parent_id, parent group ID to add current group to.
 * RETURNS
 *  mmi_id
 *****************************************************************************/
mmi_id cui_vcal_save_to_file_create(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_vcal_save_to_file_cntx_struct *save_to_file_cntx;        

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*)L"root"))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return GRP_ID_INVALID;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */  

    if (mmi_frm_group_is_present(GRP_ID_VCLNDR_SAVE_TO_FILE))
    {
        mmi_frm_group_close(GRP_ID_VCLNDR_SAVE_TO_FILE);
    }    
    save_to_file_cntx = (cui_vcal_save_to_file_cntx_struct*)
                            OslMalloc(sizeof(cui_vcal_save_to_file_cntx_struct));
    memset(save_to_file_cntx, 0, sizeof(cui_vcal_save_to_file_cntx_struct));
    save_to_file_cntx->selected_path = OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(WCHAR));
    save_to_file_cntx->file_name_buf = OslMalloc((SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * sizeof(WCHAR));
    save_to_file_cntx->src_path = OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(WCHAR));
    memset(save_to_file_cntx->selected_path, 0, (SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(WCHAR));
    memset(save_to_file_cntx->file_name_buf, 0, (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * sizeof(WCHAR));
    save_to_file_cntx->parent_id = parent_id;
    save_to_file_cntx->group_id = mmi_frm_group_create(
                                        parent_id,
                                        GRP_ID_VCLNDR_SAVE_TO_FILE,
                                        cui_vcal_save_to_file_group_proc, 
                                        save_to_file_cntx);
    return save_to_file_cntx->group_id;  
}


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_save_to_file_group_proc
 * DESCRIPTION
 *  Proc function of edit group.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret cui_vcal_save_to_file_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_vcal_save_to_file_cntx_struct *save_to_file_cntx;  
    S32 result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    save_to_file_cntx = (cui_vcal_save_to_file_cntx_struct*)evt->user_data;
    
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_ENTER:
            break;

        case EVT_ID_GROUP_ACTIVE:
        {
            break;
        }            
        case EVT_ID_GROUP_DEINIT:
        {
            OslMfree(save_to_file_cntx->file_name_buf);
            OslMfree(save_to_file_cntx->selected_path);
            OslMfree(save_to_file_cntx->src_path);
            OslMfree(save_to_file_cntx);
            break;
        }
        case EVT_ID_CUI_FILENAME_EDITOR_RESULT:
        {
            cui_filename_editor_result_event_struct *param =
                        (cui_filename_editor_result_event_struct*)evt;
            WCHAR *src_path_name;
            cui_vcal_result_struct evt;
            srv_vcal_build_struct *handle;

            MMI_VCAL_TRACE1(MMI_VCAL_SAVE_TO_FILE_NAME_EDIT, param->result);                          
            if (param->result > 0)
            {                                                    
                cui_filename_editor_get_fullpath(
                                    save_to_file_cntx->filename_gid, 
                                    save_to_file_cntx->selected_path,
                                    (SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(WCHAR));
                if (MMI_VCAL_TYPE_BUFF == save_to_file_cntx->param_type)
                {
                    g_vcal_cntx.time_fmt_flag = MMI_VCALNDR_TIME_FMT_UTC;

                    handle = srv_vcal_build_begin(save_to_file_cntx->selected_path, SRV_VCAL_VER_VCAL_1_0);
                    if (SRV_TDL_VCAL_EVENT == save_to_file_cntx->obj.vcal_type)
                    {
                        result = srv_vcal_build_add(handle, &save_to_file_cntx->obj.event, SRV_VCAL_VEVENT);            
                    }
                    else
                    {
                        result = srv_vcal_build_add(handle, &save_to_file_cntx->obj.task, SRV_VCAL_VTODO);
                    }
                    result = srv_vcal_build_end(handle);

                    if (result == 0)
                    {    
               #ifdef __MMI_INDICAL__
                        if(mmi_indical_get_saving_tithi_reminder() == MMI_TRUE)
                        {
                            mmi_popup_display_simple(
                                            (WCHAR*)get_string(STR_TODO_SET_REPEAT_ONCE),
                                            MMI_EVENT_SUCCESS,
                                            GRP_ID_VCLNDR_SAVE_TO_FILE,
                                            0);
                            mmi_indical_set_saving_tithi_reminder(MMI_FALSE);
                        }
                        else
                #endif /* __MMI_INDICAL__ */
                        {   
                            evt.evt_id = EVT_ID_CUI_VCAL_SUCCESS;
                            evt.size = 0;
                            evt.user_data = NULL;
                            evt.sender_id = GRP_ID_VCLNDR_SAVE_TO_FILE;
                            mmi_frm_group_send_to_parent(GRP_ID_VCLNDR_SAVE_TO_FILE, (mmi_group_event_struct*)&evt); 
                        }   
                        save_to_file_cntx->evt_id = EVT_ID_CUI_VCAL_SUCCESS;
                    }   
                    else if (result < 0)
                    {
                        save_to_file_cntx->evt_id = EVT_ID_CUI_VCAL_FAIL;
                        g_vcal_popup_user_tag = MMI_FALSE;
                        mmi_popup_display_simple(
                                        (WCHAR*)get_string(srv_fmgr_fs_error_get_string(result)),
                                        (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(result),
                                        GRP_ID_ROOT,
                                        &g_vcal_popup_user_tag);

                        evt.evt_id = EVT_ID_CUI_VCAL_FAIL;
                        evt.size = 0;
                        evt.user_data = NULL;
                        evt.sender_id = GRP_ID_VCLNDR_SAVE_TO_FILE;
                        mmi_frm_group_send_to_parent(GRP_ID_VCLNDR_SAVE_TO_FILE, (mmi_group_event_struct*)&evt); 

                    }
                    else
                    {
                        mmi_popup_display_simple(
                                        (WCHAR*)get_string(STR_GLOBAL_UNSUPPORTED_FORMAT),
                                        MMI_EVENT_FAILURE,
                                        GRP_ID_VCLNDR_SAVE_TO_FILE,
                                        0);
                        save_to_file_cntx->evt_id = EVT_ID_CUI_VCAL_FAIL;
                    }
                }
                else
                {
                    src_path_name = OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(WCHAR));
                    if (mmi_vobj_get_file_buffer_size(MMI_VOBJ_VCLNDR) > 0)
                    {       
                        mmi_vobj_get_full_path_name(
                                    g_vobj_cntx.buffer_begin[MMI_VOBJ_VCLNDR], 
                                    (CHAR*)src_path_name, 
                                    MMI_VOBJ_VCLNDR);        
                    }
                    srv_fmgr_async_copy(
                                    src_path_name, 
                                    save_to_file_cntx->selected_path, 
                                    SRV_FMGR_ASYNC_FLAG_NO_PROGRESS, 
                                    cui_vcal_save_to_file_group_proc, 
                                    save_to_file_cntx);
                    OslMfree(src_path_name);                    
                }
            }
            else if (0 == param->result)
            {
                evt.evt_id = EVT_ID_CUI_VCAL_USER_CANCEL;
                evt.size = sizeof(cui_vcal_result_struct);
                evt.user_data = NULL;
                evt.sender_id = GRP_ID_VCLNDR_SAVE_TO_FILE;
                mmi_frm_group_send_to_parent(GRP_ID_VCLNDR_SAVE_TO_FILE, (mmi_group_event_struct*)&evt); 
            }
            else
            {
                save_to_file_cntx->evt_id = EVT_ID_CUI_VCAL_FAIL;    
                g_vcal_popup_user_tag = MMI_FALSE;
                mmi_popup_display_simple(
                                    (WCHAR*)get_string(srv_fmgr_fs_error_get_string(param->result)),
                                    (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(param->result),
                                    GRP_ID_VCLNDR_SAVE_TO_FILE,
                                    &g_vcal_popup_user_tag);
            }
            break;
        }
        case EVT_ID_CUI_FOLDER_SELECTOR_RESULT:
        {
            cui_folder_selector_result_event_struct *param =
                        (cui_folder_selector_result_event_struct*)evt;
            U16 file_ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
            cui_vcal_result_struct evt;
            
            MMI_VCAL_TRACE1(MMI_VCAL_SAVE_TO_FILE_FOLDER_SELECT, param->result);             
            if (param->result > 0)
            {                
                cui_folder_selector_get_selected_filepath(
                                                    save_to_file_cntx->child_id,
                                                    NULL,
                                                    save_to_file_cntx->selected_path,
                                                    (SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH);
                if (MMI_VCAL_TYPE_BUFF == save_to_file_cntx->param_type)
                {
                    if (SRV_TDL_VCAL_EVENT == save_to_file_cntx->obj.vcal_type)
                    {
                        mmi_wcsncpy(
                                save_to_file_cntx->file_name_buf, 
                                (U16*)save_to_file_cntx->obj.event.subject, 
                                MAX_TODO_NOTE_LEN - 1);
                    }
                    else
                    {
                        mmi_wcsncpy(
                                save_to_file_cntx->file_name_buf,
                                (U16*)save_to_file_cntx->obj.task.subject, 
                                MAX_TODO_NOTE_LEN - 1);
                    }
                }
                else
                {
                    memset(save_to_file_cntx->file_name_buf, 0, ENCODING_LENGTH);
                }
                cui_folder_selector_close(save_to_file_cntx->child_id);
                mmi_asc_to_wcs(file_ext, MMI_VCAL_FILE_EXT); 

                save_to_file_cntx->filename_gid = cui_filename_editor_create(
                                                        save_to_file_cntx->group_id,
                                                        save_to_file_cntx->file_name_buf,
                                                        (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * sizeof(WCHAR),
                                                        SRV_FMGR_PATH_MAX_FILE_BASENAME_LEN,
                                                        save_to_file_cntx->selected_path,
                                                        file_ext);
                cui_filename_editor_set_title(save_to_file_cntx->filename_gid, STR_GLOBAL_FILENAME, GetRootTitleIcon(ORGANIZER_CALENDER_MENU));
                cui_filename_editor_run(save_to_file_cntx->filename_gid);
            }
            else if (param->result == 0)
            {                
                evt.evt_id = EVT_ID_CUI_VCAL_USER_CANCEL;
                evt.size = sizeof(cui_vcal_result_struct);
                evt.user_data = NULL;
                evt.sender_id = GRP_ID_VCLNDR_SAVE_TO_FILE;
                mmi_frm_group_send_to_parent(GRP_ID_VCLNDR_SAVE_TO_FILE, (mmi_group_event_struct*)&evt); 
            }
            break;
        }
        case EVT_ID_SRV_FMGR_ASYNC_DONE:
        {
            srv_fmgr_async_done_event_struct *async_evt = 
                (srv_fmgr_async_done_event_struct*)evt;
            U8 attr;

            if (async_evt->result >= 0)
            {
                save_to_file_cntx->evt_id = EVT_ID_CUI_VCAL_SUCCESS;            
                attr = (U8)FS_GetAttributes(save_to_file_cntx->selected_path);     
                attr &= (~FS_ATTR_HIDDEN);
                FS_SetAttributes(save_to_file_cntx->selected_path, (U8)attr);            
                mmi_popup_display_simple(
                                (WCHAR*)get_string(STR_GLOBAL_SAVED),
                                MMI_EVENT_SUCCESS,
                                GRP_ID_VCLNDR_SAVE_TO_FILE,
                                0);            
            }
            else
            {
                save_to_file_cntx->evt_id = EVT_ID_CUI_VCAL_FAIL; 
                g_vcal_popup_user_tag = MMI_FALSE;                
                mmi_popup_display_simple(
                            (WCHAR*)get_string(srv_fmgr_fs_error_get_string(async_evt->result)),
                            (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(async_evt->result),
                            GRP_ID_VCLNDR_SAVE_TO_FILE,
                            &g_vcal_popup_user_tag);             
            }
            break;
        }
        case EVT_ID_POPUP_QUIT:
        {        
            cui_vcal_result_struct event;
            MMI_BOOL *result;
            mmi_alert_result_evt_struct *popup_evt = (mmi_alert_result_evt_struct*)evt;
            if (popup_evt != NULL)
            {
                result = (MMI_BOOL*)popup_evt->user_tag;
            }
            if (popup_evt != NULL && result != NULL && *result == MMI_FALSE)
            {
                break;
            }
            event.evt_id = save_to_file_cntx->evt_id;
            event.size = sizeof(cui_vcal_result_struct);
            event.user_data = NULL;
            event.sender_id = GRP_ID_VCLNDR_SAVE_TO_FILE;
            mmi_frm_group_send_to_parent(GRP_ID_VCLNDR_SAVE_TO_FILE, (mmi_group_event_struct*)&event); 
            break;
        }
        default:            
            break;
    }
    return MMI_RET_OK;

}


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_save_to_file_set_para
 * DESCRIPTION
 *  Set the type
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * type : [IN] type of the param for the CUI to send
 *        MMI_VCAL_TYPE_BUFF, give a buffer stored an event or to-do.
 *        MMI_VCAL_FILE_PATH, give a file path stores the vcs file.
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
void cui_vcal_save_to_file_set_para(mmi_id sg_id, cui_vcal_save_to_file_param_struct para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_vcal_save_to_file_cntx_struct *save_to_file_cntx;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sg_id == GRP_ID_INVALID)
    {
        return;
    }
    save_to_file_cntx = (cui_vcal_save_to_file_cntx_struct*)mmi_frm_group_get_user_data(sg_id);    
    save_to_file_cntx->param_type = para.para_type;
    if (MMI_VCAL_TYPE_BUFF == para.para_type)
    {
        save_to_file_cntx->obj.vcal_type = para.u.obj.vcal_type;
        if (SRV_TDL_VCAL_EVENT  == para.u.obj.vcal_type)
        {
            memcpy(&save_to_file_cntx->obj.event, para.u.obj.buff, sizeof(srv_tdl_event_struct));
        }
        else
        {
            memcpy(&save_to_file_cntx->obj.task, para.u.obj.buff, sizeof(srv_tdl_task_struct));    
        }
    }
    else
    {
        memcpy(save_to_file_cntx->src_path, para.u.path, SRV_FMGR_PATH_MAX_LEN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_save_to_file_run
 * DESCRIPTION
 *  Run send CUI.
 * PARAMETERS
 *  mmi_id : [IN] sg_id, group ID to add current group to.
 * RETURNS
 *  mmi_id
 *****************************************************************************/
void cui_vcal_save_to_file_run(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_vcal_save_to_file_cntx_struct *save_to_file_cntx;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sg_id == GRP_ID_INVALID)
    {
        return;
    }
    
    save_to_file_cntx = (cui_vcal_save_to_file_cntx_struct*)
                                        mmi_frm_group_get_user_data(sg_id);
    mmi_frm_group_enter(sg_id, MMI_FRM_NODE_NONE_FLAG);
    
    save_to_file_cntx->child_id = cui_folder_selector_create(
                                                        sg_id,
                                                        (WCHAR*)L"root",
                                                        CUI_FOLDER_SELECTOR_STYLE_WRITE,
                                                        CUI_FOLDER_SELECTOR_OPT_FIXED_PATH_ON);
    if (GRP_ID_INVALID != save_to_file_cntx->child_id)
    {                                              
        cui_folder_selector_set_option(
                        save_to_file_cntx->child_id,
                        CUI_FOLDER_SELECTOR_OPT_FOLDER_TRAVERSE_MASK,
                        CUI_FOLDER_SELECTOR_OPT_FOLDER_TRAVERSE_ALL);
        cui_folder_selector_run(save_to_file_cntx->child_id);
    }
    else
    {
        mmi_frm_group_close(save_to_file_cntx->child_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_save_to_file_close
 * DESCRIPTION
 *  Close send CUI.
 * PARAMETERS
 *  mmi_id : [IN] sg_id, group ID to add current group to.
 * RETURNS
 *  mmi_id
 *****************************************************************************/
void cui_vcal_save_to_file_close(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(sg_id);    
}


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_send_create
 * DESCRIPTION
 *  Create send vCalendar CUI.
 * PARAMETERS
 *  mmi_id : [IN] parent_id, parent group ID to add current group to.
 * RETURNS
 *  mmi_id
 *****************************************************************************/
mmi_id cui_vcal_send_create(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_vcal_send_cntx_struct *send_cntx;        

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*)L"root"))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return GRP_ID_INVALID;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */

    if (mmi_frm_group_is_present(GRP_ID_VCLNDR_SEND))
    {
        mmi_frm_group_close(GRP_ID_VCLNDR_SEND);
    }    
    send_cntx = (cui_vcal_send_cntx_struct*)
                            OslMalloc(sizeof(cui_vcal_send_cntx_struct));
    memset(send_cntx, 0, sizeof(cui_vcal_send_cntx_struct));
    send_cntx->src_path = OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(WCHAR));
    send_cntx->event.size = sizeof(cui_vcal_result_struct);
    send_cntx->event.user_data = NULL;
    send_cntx->event.sender_id = GRP_ID_VCLNDR_SEND;    
    send_cntx->parent_id = parent_id;
    send_cntx->group_id = mmi_frm_group_create(
                                        parent_id,
                                        GRP_ID_VCLNDR_SEND,
                                        cui_vcal_send_group_proc, 
                                        send_cntx);
    return send_cntx->group_id;  
}


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_send_group_proc
 * DESCRIPTION
 *  Proc function of edit group.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret cui_vcal_send_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_vcal_send_cntx_struct *send_cntx;  
    cui_evt_sms_send_struct *event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    send_cntx = (cui_vcal_send_cntx_struct*)evt->user_data;
    
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_SMS_SEND:
        {
            event = (cui_evt_sms_send_struct*)evt;
            if (event->is_send_finish)
            {
                mmi_vclndr_uti_del_default_file();
                cui_sms_send_close(send_cntx->child_id);
                mmi_frm_group_send_to_parent(send_cntx->group_id, (mmi_group_event_struct*)&send_cntx->event); 
            }
            break;
        }
    #ifdef __MMI_OPP_SUPPORT__        
        case EVT_ID_CUI_BT_SENDING_SUCC:
        case EVT_ID_CUI_BT_SENDING_FAIL:
        {
            mmi_vclndr_uti_del_default_file();        
            mmi_frm_group_send_to_parent(send_cntx->group_id, (mmi_group_event_struct*)&send_cntx->event); 
            break;
        }
    #endif /* __MMI_OPP_SUPPORT__ */
        case EVT_ID_GROUP_DEINIT:
        {
            OslMfree(send_cntx->src_path);
            OslMfree(send_cntx);
            break;
        }
        case EVT_ID_POPUP_QUIT:
        {        
            mmi_frm_group_send_to_parent(send_cntx->group_id, (mmi_group_event_struct*)&send_cntx->event); 
            break;
        }
        default:            
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_send_set_para
 * DESCRIPTION
 *  Set the type
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * type : [IN] type of the param for the CUI to send
 *        MMI_VCAL_TYPE_BUFF, give a buffer stored an event or to-do.
 *        MMI_VCAL_FILE_PATH, give a file path stores the vcs file.
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
void cui_vcal_send_set_para(mmi_id sg_id, cui_vcal_send_param_struct para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_vcal_send_cntx_struct *send_cntx;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sg_id == GRP_ID_INVALID)
    {
        return;
    }
    send_cntx = (cui_vcal_send_cntx_struct*)mmi_frm_group_get_user_data(sg_id);    
    send_cntx->send_type = para.send_type;
    send_cntx->obj.vcal_type = para.vcal_type;
    if (SRV_VCAL_VEVENT  == para.vcal_type)
    {
        memcpy(&send_cntx->obj.event, para.buff, sizeof(srv_tdl_event_struct));
    }
    else
    {
        memcpy(&send_cntx->obj.task, para.buff, sizeof(srv_tdl_task_struct));    
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_send_run
 * DESCRIPTION
 *  Run send CUI.
 * PARAMETERS
 *  mmi_id : [IN] sg_id, group ID to add current group to.
 * RETURNS
 *  mmi_id
 *****************************************************************************/
void cui_vcal_send_run(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_vcal_send_cntx_struct *send_cntx; 
    S32 check_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sg_id == GRP_ID_INVALID)
    {
        return;
    }
    send_cntx = (cui_vcal_send_cntx_struct*)
                                        mmi_frm_group_get_user_data(sg_id);
    mmi_frm_group_enter(sg_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    check_result = mmi_vobj_fs_check_folder();
    if (FS_NO_ERROR != check_result)
    {
        send_cntx->event.evt_id = EVT_ID_CUI_VCAL_FAIL;    
        mmi_popup_display_simple(
                        (WCHAR*)get_string(srv_fmgr_fs_error_get_string(check_result)),
                        (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(check_result),
                        GRP_ID_VCLNDR_SEND,
                        0);    
        return;
    }
    
    switch (send_cntx->send_type)
    {
    #ifndef __MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__
        case MMI_VCAL_SEND_BY_SMS:
        {
            mmi_vcal_sms_forward(send_cntx);
            break;
        }
    #endif
    #ifdef __MMI_MMS__
        case MMI_VCAL_SEND_BY_MMS:
        {
            mmi_vclndr_mms_forward(send_cntx);
            break;
        }
    #endif
    #ifdef __MMI_EMAIL__
        case MMI_VCAL_SEND_BY_EMAIL:
        {
            mmi_vclndr_forward_email(send_cntx);
            break;
        }
    #endif
    #ifdef __MMI_OPP_SUPPORT__
        case MMI_VCAL_SEND_BY_OPP:
        {
            mmi_vcal_opp_forward(send_cntx);
            break;
        }
    #endif
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_send_close
 * DESCRIPTION
 *  Close send CUI.
 * PARAMETERS
 *  mmi_id : [IN] sg_id, group ID to add current group to.
 * RETURNS
 *  mmi_id
 *****************************************************************************/
void cui_vcal_send_close(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(sg_id);    
}


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_save_to_tdl_create
 * DESCRIPTION
 *  Create save vCalendar CUI.
 * PARAMETERS
 *  mmi_id : [IN] parent_id, parent group ID to add current group to.
 * RETURNS
 *  mmi_id
 *****************************************************************************/
mmi_id cui_vcal_save_to_tdl_create(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_vcal_save_to_tdl_cntx_struct *save_to_tdl_cntx;        

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_VCLNDR_SAVE_TO_TDL))
    {
        mmi_frm_group_close(GRP_ID_VCLNDR_SAVE_TO_TDL);
    }
    save_to_tdl_cntx = (cui_vcal_save_to_tdl_cntx_struct*)OslMalloc(sizeof(cui_vcal_save_to_tdl_cntx_struct));
    memset(save_to_tdl_cntx, 0, sizeof(cui_vcal_save_to_tdl_cntx_struct));
    save_to_tdl_cntx->path = OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(WCHAR));
    save_to_tdl_cntx->parent_id = parent_id;    
    save_to_tdl_cntx->event.size = sizeof(cui_vcal_result_struct);
    save_to_tdl_cntx->event.user_data = NULL;
    save_to_tdl_cntx->event.sender_id = GRP_ID_VCLNDR_SAVE_TO_TDL;
    save_to_tdl_cntx->group_id = mmi_frm_group_create(
                                        parent_id,
                                        GRP_ID_VCLNDR_SAVE_TO_TDL,
                                        cui_vcal_save_to_tdl_group_proc, 
                                        save_to_tdl_cntx);
    return save_to_tdl_cntx->group_id;  
}


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_save_to_tdl_group_proc
 * DESCRIPTION
 *  Proc function of edit group.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret cui_vcal_save_to_tdl_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_vcal_save_to_tdl_cntx_struct *save_to_tdl_cntx;  
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    save_to_tdl_cntx = (cui_vcal_save_to_tdl_cntx_struct*)evt->user_data;
   
    MMI_VCAL_TRACE1(CUI_VCAL_SAVE_TO_TDL_PROC, evt->evt_id);  
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_ENTER:
            break;

        case EVT_ID_GROUP_DEINIT:
        {
            cui_inline_close(save_to_tdl_cntx->child_id);
            mmi_frm_group_close(save_to_tdl_cntx->group_id);
			OslMfree(save_to_tdl_cntx->path);
            OslMfree(save_to_tdl_cntx);
            break;
        }
        case EVT_ID_POPUP_QUIT:
        {  
            mmi_group_event_struct *recv_evt = (mmi_group_event_struct*)evt;
            mmi_frm_group_close(recv_evt->sender_id);
            save_to_tdl_cntx->event.evt_id = EVT_ID_CUI_VCAL_USER_CANCEL;
            mmi_frm_group_send_to_parent(
                                save_to_tdl_cntx->group_id, 
                                (mmi_group_event_struct*)&save_to_tdl_cntx->event);
            break;
        }
        case EVT_ID_TDL_SAVE_SUCCESS:
        {
            mmi_group_event_struct *recv_evt = (mmi_group_event_struct*)evt;
            MMI_VCAL_TRACE1(CUI_VCAL_SAVE_TO_TDL_PROC, 1);  
            mmi_frm_group_close(recv_evt->sender_id);
            save_to_tdl_cntx->event.evt_id = EVT_ID_CUI_VCAL_SUCCESS;
            mmi_frm_group_send_to_parent(
                                save_to_tdl_cntx->group_id, 
                                (mmi_group_event_struct*)&save_to_tdl_cntx->event); 
            break;
        }
        case EVT_ID_TDL_SAVE_FAIL:
        {
            mmi_group_event_struct *recv_evt = (mmi_group_event_struct*)evt;
            MMI_VCAL_TRACE1(CUI_VCAL_SAVE_TO_TDL_PROC, 2);  
            mmi_frm_group_close(recv_evt->sender_id);
            save_to_tdl_cntx->event.evt_id = EVT_ID_CUI_VCAL_FAIL_NOT_ENOUGH_MEMORY;
            mmi_frm_group_send_to_parent(
                                save_to_tdl_cntx->group_id, 
                                (mmi_group_event_struct*)&save_to_tdl_cntx->event); 
            break;
        }        
        case EVT_ID_TDL_SAVE_CANCEL:
        {
            mmi_group_event_struct *recv_evt = (mmi_group_event_struct*)evt;
            mmi_frm_group_close(recv_evt->sender_id);
            save_to_tdl_cntx->event.evt_id = EVT_ID_CUI_VCAL_USER_CANCEL;
            mmi_frm_group_send_to_parent(
                                save_to_tdl_cntx->group_id, 
                                (mmi_group_event_struct*)&save_to_tdl_cntx->event); 
            break;
        }
        default:            
            break;
    }
    return MMI_RET_OK;

}


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_save_to_tdl_set_path
 * DESCRIPTION
 *  Set the file path for MMI_VCAL_FILE_PATH.
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * path : [IN] file path stores the vcs file.
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
void cui_vcal_save_to_tdl_set_path(mmi_id sg_id, WCHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_vcal_save_to_tdl_cntx_struct *save_to_tdl_cntx;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    save_to_tdl_cntx = (cui_vcal_save_to_tdl_cntx_struct*)mmi_frm_group_get_user_data(sg_id);
    mmi_wcsncpy(save_to_tdl_cntx->path, path, SRV_FMGR_PATH_MAX_LEN);
}

/*****************************************************************************
 * FUNCTION
 *  cui_vcal_save_to_tdl_run
 * DESCRIPTION
 *  Run send CUI.
 * PARAMETERS
 *  mmi_id : [IN] sg_id, group ID to add current group to.
 * RETURNS
 *  mmi_id
 *****************************************************************************/
void cui_vcal_save_to_tdl_run(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_vcal_save_to_tdl_cntx_struct *save_to_tdl_cntx;  
    mmi_id child_gid;
#if 1    
    srv_vcal_parse_struct *handle;
    void *pobject;
    srv_vcal_type_enum vcal_type;
    U8 flag_finish;
    S32 result;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    save_to_tdl_cntx = (cui_vcal_save_to_tdl_cntx_struct*)mmi_frm_group_get_user_data(sg_id);
    mmi_frm_group_enter(sg_id, MMI_FRM_NODE_NONE_FLAG);
    g_vcal_cntx.vcalendar_encoding = (mmi_chset_enum)PhnsetGetDefEncodingType();
    
    handle = srv_vcal_parse_begin(save_to_tdl_cntx->path, MMI_CHSET_UTF8);
    result = srv_vcal_parse(handle, &pobject, (srv_vcal_type_enum*)&vcal_type, (U8*)&flag_finish);
    srv_vcal_parse_free_object(handle, pobject);
    srv_vcal_parse_end(handle);
    
    if (result != SRV_VCAL_RESULT_SUCCESS)
    {
        save_to_tdl_cntx->event.evt_id = EVT_ID_CUI_VCAL_NOT_SUPPORT;
        mmi_popup_display_simple(
                            (WCHAR*)get_string(STR_GLOBAL_UNSUPPORTED_FORMAT),
                            MMI_EVENT_FAILURE,
                            sg_id,
                            0);
        return;
    }
    MMI_VCAL_TRACE1(MMI_VCAL_ENTRY_FMGR_RECV, vcal_type);  

    if (SRV_VCAL_VEVENT == vcal_type)
    {
        memcpy(&g_tdl_cntx.curr_event, pobject, sizeof(srv_tdl_event_struct));
        
        if (g_tdl_cntx.curr_event.alarm.first_launch.nYear == 0)
        {
            g_tdl_cntx.curr_event.alarm.type = MMI_TDL_ALARM_OFF;
        }
        else
        {
            g_tdl_cntx.curr_event.alarm.type = MMI_TDL_ALARM_CUSTOM;
            mmi_tdl_save_adjust_alarm_type(&g_tdl_cntx.curr_event.alarm, &g_tdl_cntx.curr_event.start_time); 
        }
        
        mmi_tdl_save_adjust_field(
                (void*)&g_tdl_cntx.curr_event, 
                sizeof(srv_tdl_event_struct), 
                SRV_TDL_VCAL_EVENT);

    #ifdef __MMI_BIRTHDAY_REMINDER__
        if (g_tdl_cntx.curr_event.category == MMI_TDL_CATEGORY_BIRTHDAY)
        {
            mmi_tdl_br_entry_bday_edit_from_org(sg_id);
        }
        else
    #endif
        {
            // if birthday do not suport on this proj, we should do this
    /*        if (g_tdl_cntx.curr_event.category == MMI_TDL_CATEGORY_BIRTHDAY)
            {
                g_tdl_cntx.curr_event.category = MMI_TDL_CATEGORY_REMINDER;
            }*/
            
            if (MMI_TDL_ALARM_OFF == g_tdl_cntx.curr_event.alarm.type)
            {
                memcpy(
                    &g_tdl_cntx.curr_event.alarm.first_launch, 
                    &g_tdl_cntx.curr_event.start_time,
                    sizeof(MYTIME));
            }
            else
            {
                mmi_tdl_compute_alarm_time(
                    g_tdl_cntx.curr_event.alarm.type,
                    &g_tdl_cntx.curr_event.start_time,
                    &g_tdl_cntx.curr_event.alarm.first_launch);
            }
            child_gid = cui_cal_save_create(sg_id);
            cui_cal_save_set_event(child_gid, &g_tdl_cntx.curr_event);
            cui_cal_save_run(child_gid);
        }
    }
    else
    {
        memcpy(&g_tdl_cntx.curr_task, pobject, sizeof(srv_tdl_task_struct));
        
        if (g_tdl_cntx.curr_task.alarm.first_launch.nYear == 0)
        {
            g_tdl_cntx.curr_task.alarm.type = MMI_TDL_ALARM_OFF;
        }
        else
        {
            g_tdl_cntx.curr_task.alarm.type = MMI_TDL_ALARM_CUSTOM;
            mmi_tdl_save_adjust_alarm_type(&g_tdl_cntx.curr_task.alarm, &g_tdl_cntx.curr_task.due_time); 
        }
        
        mmi_tdl_save_adjust_field(
                (void*)&g_tdl_cntx.curr_task, 
                sizeof(srv_tdl_task_struct), 
                SRV_TDL_VCAL_TASK);
        
        if (MMI_TDL_ALARM_OFF == g_tdl_cntx.curr_task.alarm.type)
        {
            memcpy(
                &g_tdl_cntx.curr_task.alarm.first_launch, 
                &g_tdl_cntx.curr_task.due_time,
                sizeof(MYTIME));
        }
        else    
        {
            mmi_tdl_compute_alarm_time(
                g_tdl_cntx.curr_task.alarm.type,
                &g_tdl_cntx.curr_task.due_time,
                &g_tdl_cntx.curr_task.alarm.first_launch);    
        }
        child_gid = cui_tdl_save_create(sg_id);
        cui_tdl_save_set_task(child_gid, &g_tdl_cntx.curr_task);
        cui_tdl_save_run(child_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_save_to_tdl_close
 * DESCRIPTION
 *  Close send CUI.
 * PARAMETERS
 *  mmi_id : [IN] sg_id, group ID to add current group to.
 * RETURNS
 *  mmi_id
 *****************************************************************************/
void cui_vcal_save_to_tdl_close(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(sg_id);    
}


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_recv_create
 * DESCRIPTION
 *  Create save vCalendar CUI.
 * PARAMETERS
 *  mmi_id : [IN] parent_id, parent group ID to add current group to.
 * RETURNS
 *  mmi_id
 *****************************************************************************/
mmi_id cui_vcal_recv_create(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_vcal_recv_cntx_struct *recv_cntx;        

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_VCLNDR_RECV))
    {
        mmi_frm_group_close(GRP_ID_VCLNDR_RECV);
    }
    recv_cntx = (cui_vcal_recv_cntx_struct*)OslMalloc(sizeof(cui_vcal_recv_cntx_struct));
    memset(recv_cntx, 0, sizeof(cui_vcal_recv_cntx_struct));
    recv_cntx->path = OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(WCHAR));
    recv_cntx->parent_id = parent_id;
    recv_cntx->group_id = mmi_frm_group_create(
                                        parent_id,
                                        GRP_ID_VCLNDR_RECV,
                                        cui_vcal_recv_group_proc, 
                                        recv_cntx);
    return recv_cntx->group_id;  
}


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_recv_group_proc
 * DESCRIPTION
 *  Proc function of edit group.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret cui_vcal_recv_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_vcal_recv_cntx_struct *recv_cntx = (cui_vcal_recv_cntx_struct*)evt->user_data;  
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    MMI_VCAL_TRACE1(CUI_VCAL_RECV_PROC, evt->evt_id);  
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
        {
            OslMfree(recv_cntx->path);
            OslMfree(recv_cntx);
            break;
        }
        case EVT_ID_CUI_MENU_LIST_EXIT:
        {
            cui_menu_close(recv_cntx->menu_child_id);
            break;
        }
        case EVT_ID_CUI_VCAL_SUCCESS:
        {
            MMI_VCAL_TRACE1(CUI_VCAL_RECV_PROC, 1);  
            mmi_vobj_clear_one_file_buffer();
            //No break here
        }
        case EVT_ID_CUI_VCAL_USER_CANCEL:
        case EVT_ID_CUI_VCAL_FAIL_NOT_ENOUGH_MEMORY:
        case EVT_ID_CUI_VCAL_NOT_SUPPORT:
        case EVT_ID_CUI_VCAL_FAIL:
        {
            mmi_group_event_struct *evt_send = (mmi_group_event_struct*)evt;
            MMI_VCAL_TRACE1(CUI_VCAL_RECV_PROC, 2);  
            mmi_frm_group_close(evt_send->sender_id);
            break;   
        } 
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            cui_vcal_recv_menu_select_hdlr(evt);
            break;
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(recv_cntx->menu_child_id);
            break;
        }
        case EVT_ID_POPUP_QUIT:
        {
            mmi_frm_group_close(GRP_ID_VCLNDR_RECV);
            break;
        }
        default:            
            break;
    }
    return MMI_RET_OK;

}


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_recv_set_path
 * DESCRIPTION
 *  Set the file path for MMI_VCAL_FILE_PATH.
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * path : [IN] file path stores the vcs file.
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
void cui_vcal_recv_set_path(mmi_id sg_id, U16 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_vcal_recv_cntx_struct *recv_cntx;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    recv_cntx = (cui_vcal_recv_cntx_struct*)mmi_frm_group_get_user_data(sg_id);
    mmi_wcsncpy(recv_cntx->path, path, SRV_FMGR_PATH_MAX_LEN);
}

/*****************************************************************************
 * FUNCTION
 *  cui_vcal_recv_run
 * DESCRIPTION
 *  Run send CUI.
 * PARAMETERS
 *  mmi_id : [IN] sg_id, group ID to add current group to.
 * RETURNS
 *  mmi_id
 *****************************************************************************/
void cui_vcal_recv_run(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_vcal_recv_cntx_struct *recv_cntx;  
    srv_vcal_type_enum v_type = SRV_VCAL_VTYPE_END_OF_ENUM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    recv_cntx = (cui_vcal_recv_cntx_struct*)mmi_frm_group_get_user_data(sg_id);
    mmi_frm_group_enter(sg_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    recv_cntx->menu_child_id = cui_menu_create(
                                        sg_id,
                                        CUI_MENU_SRC_TYPE_RESOURCE,
                                        CUI_MENU_TYPE_OPTION,
                                        MENU_VCLNDR_RECV_OPTION,
                                        MMI_TRUE,
                                        NULL);
    if (GRP_ID_INVALID == recv_cntx->menu_child_id)
    {
        mmi_frm_group_close(recv_cntx->group_id);
        return;
    }
                                        
    cui_menu_set_default_title(
                            recv_cntx->menu_child_id, 
                            get_string(STR_GLOBAL_OPTIONS),
                            get_image(ORGANIZER_TITLE_IMAGEID));
    
    srv_vcal_utility_get_vtype((U16*)recv_cntx->path, (U16*)&v_type);

    if (SRV_VCAL_VTYPE_END_OF_ENUM == v_type)
    {
        mmi_popup_display_simple(
                            (WCHAR*)get_string(STR_GLOBAL_UNSUPPORTED_FORMAT),
                            MMI_EVENT_FAILURE,
                            recv_cntx->group_id,
                            0);
        return;
    }
    
    if (SRV_VCAL_VEVENT == v_type)
    {
        cui_menu_set_item_hidden(recv_cntx->menu_child_id, MENU_VCLNDR_RECV_OPT_TDL, MMI_TRUE);
        cui_menu_set_item_hidden(recv_cntx->menu_child_id, MENU_VCLNDR_RECV_OPT_CLNDR, MMI_FALSE);
        //g_tdl_cntx.vcal_filter = SRV_TDL_VCAL_EVENT;
    }
    else
    {
        cui_menu_set_item_hidden(recv_cntx->menu_child_id, MENU_VCLNDR_RECV_OPT_CLNDR, MMI_TRUE);
        cui_menu_set_item_hidden(recv_cntx->menu_child_id, MENU_VCLNDR_RECV_OPT_TDL, MMI_FALSE);
        //g_tdl_cntx.vcal_filter = SRV_TDL_VCAL_TASK;
    }
    cui_menu_run(recv_cntx->menu_child_id);
}


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_recv_close
 * DESCRIPTION
 *  Close send CUI.
 * PARAMETERS
 *  mmi_id : [IN] sg_id, group ID to add current group to.
 * RETURNS
 *  mmi_id
 *****************************************************************************/
void cui_vcal_recv_close(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(sg_id);    
}


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_recv_menu_select_hdlr
 * DESCRIPTION
 *  Generate the menus.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_vcal_recv_menu_select_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    cui_vcal_recv_cntx_struct *recv_cntx = (cui_vcal_recv_cntx_struct*)evt->user_data;  
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->highlighted_menu_id)
    {
        case MENU_VCLNDR_RECV_OPT_CLNDR:
        case MENU_VCLNDR_RECV_OPT_TDL:
        {
            recv_cntx->save_child_id = cui_vcal_save_to_tdl_create(recv_cntx->group_id);
            cui_vcal_save_to_tdl_set_path(recv_cntx->save_child_id, recv_cntx->path);
            cui_vcal_save_to_tdl_run(recv_cntx->save_child_id);
            break;
        }            
        case MENU_VCLNDR_RECV_OPT_FMGR:
        {
            cui_vcal_save_to_file_param_struct para;
            recv_cntx->save_child_id = cui_vcal_save_to_file_create(recv_cntx->group_id);
            para.para_type = MMI_VCAL_TYPE_FILE_PATH;
            para.u.path = recv_cntx->path;
            cui_vcal_save_to_file_set_para(recv_cntx->save_child_id, para);
            cui_vcal_save_to_file_run(recv_cntx->save_child_id);
            break;
        }               
        default:
            break;
    }
}

#endif /* defined(__MMI_VCALENDAR__) */ /* #if defined(__MMI_VCALENDAR__) */
#endif /* _MMI_VCALENDAR_C */ /* END #define _MMI_VCALENDAR_C */

