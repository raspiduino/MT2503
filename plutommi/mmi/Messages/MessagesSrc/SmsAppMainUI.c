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
 *  SmsAppMainUI.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Application main UI screen and menu, 
 *  inlcude the SMS folder List, Editor, Viewer and their options
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/

#include "MMI_features.h"

/**************************************************************
 * Header Files Include
 **************************************************************/
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "kal_general_types.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "Unicodexdcl.h"
#include "GlobalConstants.h"
#include "wgui_categories_util.h"
#include "wgui_categories_text_viewer.h"
#include "kal_public_api.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "custom_phb_config.h"
#include "ps_public_enum.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "gui_typedef.h"
#include "kal_release.h"
#include "NetSetAppGprot.h"
#include "wgui_inputs.h"
#include "SmsGuiInterfaceType.h"
#include "mmi_rp_app_sms_def.h"
#include "PhbSrvGprot.h"
#include "MsgViewerCuiGProt.h"
#include "string.h"
#include "mmi_msg_context.h"
#ifdef __MMI_UM_REPORT_BOX__
#include "AlertScreen.h"
#endif
#ifdef __MMI_MESSAGE_SMS_HILITE_VIEWER__
#include "gui_ems.h"
#include "app_usedetails.h"
#endif
#ifdef __MMI_BPP20_SUPPORT__
#include "BTMMIScrGprots.h"
#endif


//#include "MMI_include.h"
//#include "CommonScreens.h"
#include "Ems.h"

#include "SmsSrvGprot.h"
#include "SmsCuiGprot.h"

#include "SmsAppGprot.h"
#include "SmsAppType.h"
#include "SmsAppProt.h"
#include "SmsAppUtil.h"
#include "SmsAppMsg.h"
#ifdef __MMI_SMS_APP_EMS_SUPPORT__
#include "SmsAppEms.h"
#endif
#include "SmsGuiInterfaceProt.h"

#include "MessagesMiscell.h"

#include "MessagesExDcl.h"

#include "Wgui_ems.h"

#ifdef __MMI_EMAIL__
#include "EmailAppGProt.h"
#endif 


#if defined(__MMI_VUI_HOMESCREEN__)
#include "IdleRecentEventGprot.h"
#endif /* __MMI_VUI_HOMESCREEN__ */

#ifdef __MMI_UCM__
#include "UCMGProt.h"
#else /* __MMI_UCM__ */
#include "CallManagementGprot.h"
#endif /* __MMI_UCM__ */

#include "UcmSrvGprot.h"

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif /* __USB_IN_NORMAL_MODE__ */
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

#include "MenuCuiGprot.h"
#ifdef __UM_SUPPORT__
#include "mmi_rp_app_unifiedmessage_def.h"
#endif

#if defined(__MMI_SMS_SET_AS_REMINDER__) && defined(__MMI_TODOLIST__)
#include "custom_mmi_default_value.h"
#include "ToDoListGprot.h"
#include "ToDoListSrvGprot.h"
#include "Mmi_rp_app_todolist_def.h"
#endif

#ifdef __MMI_UNIFIED_COMPOSER__
#include "UcCuiGprot.h"
#endif
#include "mmi_rp_srv_editor_def.h"
#if defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__ ) || defined(__MMI_MESSAGES_USE_URL__)
#include "BookmarkCuiGprot.h"
#endif
#include "SimCtrlSrvGProt.h"
#include "ModeSwitchSrvGprot.h"
#ifdef __MMI_WLAN_FEATURES__
#include "NetSetSrvGprot.h"
#endif /* __MMI_WLAN_FEATURES__ */
#include "NwUsabSrvGprot.h"
#if (MMI_MAX_SIM_NUM >= 3)
#include "SimSelCuiGprot.h"
#endif /* (MMI_MAX_SIM_NUM >= 3) */

#include "UseDetailCuiGprot.h"
#include "mms_api.h"

#ifdef __MMI_BT_MAP_CLIENT__
#include "BtcmSrvGprot.h"
#include "SmsbtmapcSrvStorage.h"
#include "SmsUmBtMapProt.h"
#endif

/**************************************************************
* MARCO
**************************************************************/
#ifdef __MMI_MESSAGES_SMS_EMAIL__
#define MMI_SMS_MAX_VIEWER_HEADER_LEN       160
#else /* __MMI_MESSAGES_SMS_EMAIL__ */
#define MMI_SMS_MAX_VIEWER_HEADER_LEN       120
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
/*FM_ITER*/
#ifdef __MMI_UM_ITERATOR_VIEWER__
#define MMI_SMS_MAX_ITER_VIEWER_MIDDLE_STR_LEN 14
#endif /* __MMI_UM_ITERATOR_VIEWER__ */

#ifdef __MMI_SMS_DETAILS_INFO__
#define MMI_SMS_MAX_DETAILS_SCREEN_BUFFER   150
#endif

/**************************************************************
 * Global Variables Declaration
 **************************************************************/
mmi_sms_context_struct g_sms_cntx;
mmi_sms_class0_info_struct g_class0_sms_info;
/*FM_SG*/
MMI_ID g_sms_gid = GRP_ID_INVALID;
MMI_ID g_sms_parent_gid = GRP_ID_ROOT;
#ifdef __MMI_UM_ITERATOR_VIEWER__
static WCHAR middle_str[MMI_SMS_MAX_ITER_VIEWER_MIDDLE_STR_LEN];
#endif /* __MMI_UM_ITERATOR_VIEWER__ */
MMI_BOOL g_sms_resend_by_local = MMI_TRUE;

#ifdef __MMI_BT_MAP_CLIENT__
extern mmi_sms_bt_context_struct g_sms_bt_cntx;
#endif

/**************************************************************
 * Global Function Declaration
 **************************************************************/
extern EMSData *GetEMSDataForView(EMSData **p, U8 force);
#ifndef __ULC_SLIM_EMS__
extern void MoveCursorToPosition(EMSData *data, EMSPosition *dst);
#endif

/**************************************************************
 * Static Variables Defination
 **************************************************************/
static S8 *viewer_header_buff = NULL;
#ifdef __MMI_SMS_DETAILS_INFO__
static WCHAR *sms_detail_buff = NULL;
#endif
#ifdef __MMI_MESSAGE_SMS_HILITE_VIEWER__
mmi_sms_hilite_struct hilite_cntx;
#endif /* __MMI_MESSAGE_SMS_HILITE_VIEWER__ */
static mmi_id sms_save_to_inbox_gid = GRP_ID_INVALID;
static mmi_id sms_save_to_inbox_parent_gid = GRP_ID_INVALID;
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif

#if defined(__MMI_LANG_ZAWGYI_MYANMAR__) && defined(__MMI_LANG_MYANMAR__)
MMI_BOOL g_sms_view_read_by_zawgyi = MMI_FALSE;
MMI_BOOL g_sms_view_set_language = MMI_FALSE;

#endif


/**************************************************************
 * Static Function Declaration
 **************************************************************/
#ifdef __MMI_TELEPHONY_SUPPORT__
static void mmi_sms_view_curr_msg_callback(mmi_sms_result_enum result, void *data);
#endif
#ifdef __MMI_MESSAGES_COPY__
#if defined( __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ ) || defined (__MMI_MESSAGES_LIST_ADVANCED__)
static void mmi_sms_list_opt_adv_copy_to_phone(void);
static void mmi_sms_list_opt_adv_move_to_phone(void);
static void mmi_sms_list_opt_adv_copy_all_from_sim(void);
static void mmi_sms_list_opt_adv_move_all_from_sim(void);
#endif

#if (!defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || defined(__OP01__) )
#ifdef __MMI_MESSAGES_LIST_ADVANCED__
static void mmi_sms_list_opt_adv_copy_to_sim(void);
static void mmi_sms_list_opt_adv_move_to_sim(void);
static void mmi_sms_list_opt_adv_copy_all(void);
static void mmi_sms_list_opt_adv_move_all(void);
static void mmi_sms_list_opt_copy_all_select_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id);
static void mmi_sms_list_opt_move_all_select_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id);
static void mmi_sms_list_opt_adv_copy_all_from_phone(void);
static void mmi_sms_list_opt_adv_move_all_from_phone(void);
#endif /* __MMI_MESSAGES_LIST_ADVANCED__ */
#endif /* #if (!defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || defined(__OP01__) ) */
#endif /* __MMI_MESSAGES_COPY__ */

#ifdef __MMI_MESSAGES_COPY__
#if defined( __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ ) || defined (__MMI_MESSAGES_LIST_ADVANCED__)
static void mmi_sms_list_opt_adv_copy_move_all_callback(mmi_sms_result_enum result, void *data);
static void mmi_sms_list_adv_opt_action_common_callback(mmi_sms_result_enum result, void *data);
static void mmi_sms_list_adv_opt_action_move_callback(mmi_sms_result_enum result, void *data);
#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
void mmi_sms_check_copy_move_all_options(MMI_ID menu_gid, U16 msg_id,mmi_menu_id parent_id);
#endif
#endif
#endif

static void mmi_sms_exit_viewer(void);
static void mmi_sms_go_back_from_viewer(void);
static mmi_ret mmi_sms_viewer_scrn_leave_proc(mmi_event_struct *param);
static U8 *mmi_sms_get_viewer_header(void);
static void mmi_sms_entry_viewer_enable_csk(srv_sms_box_enum curr_box_type);
static void mmi_sms_entry_viewer_set_csk(srv_sms_box_enum curr_box_type);
static void mmi_sms_pre_entry_viewer_opt(void);
static void mmi_sms_check_viewer_adv_copy_move(MMI_ID menu_gid, U16 msg_id);
static void mmi_sms_check_viewer_adv_detail(MMI_ID menu_gid, U16 msg_id);
static void mmi_sms_viewer_opt_reply(void);

#if defined(__MMI_MMS_IN_UM__) && !defined(__MMI_UNIFIED_COMPOSER__)
static void mmi_sms_viewer_opt_reply_by_MMS(void);
#endif /* defined(__MMI_MMS_IN_UM__) && !defined(__MMI_UNIFIED_COMPOSER__) */

static void mmi_sms_viewer_opt_send(void);

#if (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__))
static void mmi_sms_viewer_opt_resend(void);
#endif /* (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__)) */

static void mmi_sms_viewer_opt_forward(void);
static void mmi_sms_viewer_opt_edit(void);
#ifdef __MMI_TELEPHONY_SUPPORT__

static void mmi_sms_viewer_opt_pre_delete(void);

static void mmi_sms_viewer_opt_delete(void);
#endif/*__MMI_TELEPHONY_SUPPORT__*/
static void mmi_sms_viewer_opt_delete_callback(mmi_sms_result_enum result, void *data);
static void mmi_sms_entry_call_sender(void);

#ifdef __MMI_MESSAGES_USERDEFINED_TEMPLATE__
static void mmi_sms_viewer_opt_save_as_template(void);
static void mmi_sms_viewer_opt_pre_save_as_template(void);
#endif /* __MMI_MESSAGES_USERDEFINED_TEMPLATE__ */

#ifdef __MMI_MESSAGES_COPY__
static void mmi_sms_viewer_opt_adv_copy_to_phone(void);
static void mmi_sms_viewer_opt_adv_move_to_phone(void);
#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
static void mmi_sms_viewer_opt_adv_copy_to_tcard(void);
static void mmi_sms_viewer_opt_adv_move_to_tcard(void);
#endif /*__MMI_SMS_TCARD_STORAGE_SUPPORT__*/
#if (!defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || defined(__OP01__) )
static void mmi_sms_viewer_opt_adv_copy_to_sim(void);
static void mmi_sms_viewer_opt_adv_move_to_sim(void);
#endif /* #if (!defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || defined(__OP01__) ) */
#endif /* __MMI_MESSAGES_COPY__ */
/* FM_SEND_KEY */
static void mmi_sms_viewer_set_sender_key_hdlr(void);

#ifdef __MMI_MESSAGE_SMS_USE_DETAIL__
static void mmi_sms_viewer_opt_adv_use_number(void);
#ifdef __MMI_MESSAGES_USE_URL__
static void mmi_sms_viewer_opt_adv_use_url(void);
#endif /* __MMI_MESSAGES_USE_URL__ */
static void mmi_sms_viewer_opt_adv_use_ussd(void);
#if defined(__MMI_EMAIL__) || (defined(__MMI_PHB_OPTIONAL_FIELD__))
static void mmi_sms_viewer_opt_adv_use_email(void);
#endif /* __MMI_EMAIL__ */
static void mmi_sms_use_detail(mmi_msg_addr_type_enum type);
#endif /* __MMI_MESSAGE_SMS_USE_DETAIL__ */

#ifdef __MMI_BPP20_SUPPORT__
static void mmi_sms_viewer_opt_adv_print(void);
#endif /* __MMI_BPP20_SUPPORT__ */
#if defined(__MMI_SMS_APP_EMS_SUPPORT__) && defined(__MMI_MESSAGE_SMS_USE_DETAIL__)
static void mmi_sms_viewer_opt_adv_save_object(void);
#endif /* __MMI_SMS_APP_EMS_SUPPORT__ && __MMI_MESSAGE_SMS_USE_DETAIL__ */

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
static void mmi_sms_move_sms_to_archive(void);
static void mmi_sms_move_sms_to_archive_callback(mmi_sms_result_enum result, void *data);
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */


#if defined(__MMI_SMS_APP_EMS_SUPPORT__) && defined(__MMI_MESSAGE_SMS_USE_DETAIL__)
static void mmi_sms_check_save_object_menu_item(MMI_ID menu_gid);
#endif /* __MMI_SMS_APP_EMS_SUPPORT__ */

static void mmi_sms_viewer_adv_opt_action_common_callback(mmi_sms_result_enum result, void *data);
static void mmi_sms_viewer_adv_opt_action_move_callback(mmi_sms_result_enum result, void *data);

#if defined(__MMI_MMS_IN_UM__) && !defined(__MMI_UNIFIED_COMPOSER__)
static void mmi_sms_reply_by_MMS(void);
#endif /* defined(__MMI_MMS_IN_UM__) && !defined(__MMI_UNIFIED_COMPOSER__) */

static mmi_ret mmi_sms_class0_save_to_inbox_proc(mmi_event_struct *evt);

#ifdef __MMI_MESSAGE_SMS_HILITE_VIEWER__
static void mmi_sms_add_hilite_list_item(EMSData *pEmsData, EMS_HILITE_TYPE emsType, applib_addr_type_enum applibType);
static BOOL mmi_sms_next_block(EMSData *pEmsData, U16 addNewHiliteItem);
static void mmi_sms_adjust_hilite_list_item_offset(EMSData *pEmsData);
static kal_bool mmi_sms_hilite_check_stop_func(applib_addr_type_enum type, applib_address_node_struct *addr, kal_uint32 num);
static void mmi_sms_view_hilite_cb(S32 idx);
static void mmi_sms_view_hilite_click_cb(S32 idx);
#endif /* __MMI_MESSAGE_SMS_HILITE_VIEWER__ */

#ifdef __MMI_TELEPHONY_SUPPORT__
#ifdef __MMI_ICON_BAR_SUPPORT__
#define MMI_SMS_VIEWER_FTE_TOOLBAR_NUM  3
static void mmi_sms_viewer_set_toolbar(void);
static void mmi_sms_viewer_set_toolbar_callback(S32 index);
static void mmi_sms_viewer_update_toolbar(void);
static void mmi_sms_viewer_toolbar_delete(void);
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
static void mmi_sms_viewer_toolbar_copy_to_phone(void);
static void mmi_sms_viewer_toolbar_move_to_phone(void);
static void mmi_sms_viewer_toolbar_copy_to_phone_callback(mmi_sms_result_enum result, void *data);
static void mmi_sms_viewer_toolbar_move_to_phone_callback(mmi_sms_result_enum result, void *data);
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
#endif /* __MMI_ICON_BAR_SUPPORT__ */
#endif /* __MMI_TELEPHONY_SUPPORT__ */
#ifdef __MMI_MESSAGE_SMS_HILITE_VIEWER__
static void mmi_sms_viewer_auto_find_on(void);
static void mmi_sms_viewer_auto_find_off(void);
#endif /* __MMI_MESSAGE_SMS_HILITE_VIEWER__ */

#ifdef __MMI_UM_ITERATOR_VIEWER__
static void mmi_sms_iter_viewer_setup(WCHAR * middle_str);
static void mmi_sms_iter_viewer_prev_launch(void);
static void mmi_sms_iter_viewer_next_launch(void);
static void mmi_sms_iter_viewer_view_curr_msg_callback(mmi_sms_result_enum result, void *data);
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)
static void mmi_sms_iter_viewer_prev_msg_gesture_hdlr (mmi_frm_gesture_event_enum gesture_event);
static void mmi_sms_iter_viewer_next_msg_gesture_hdlr (mmi_frm_gesture_event_enum gesture_event);
#endif /* defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__) */
#endif /* __MMI_UM_ITERATOR_VIEWER__ */

#ifdef __MMI_SMS_DETAILS_INFO__
static void mmi_sms_box_list_opt_pre_entry_details(void);
static void mmi_sms_box_list_opt_entry_details(mmi_scrn_essential_struct* scrn_data);
#endif /* __MMI_SMS_DETAILS_INFO__ */

#ifndef __MMI_UNIFIED_COMPOSER__
static void mmi_sms_box_list_opt_reply(mmi_sms_result_enum result, void *data);
static void mmi_sms_box_list_opt_forward(mmi_sms_result_enum result, void *data);
static void mmi_sms_box_list_opt_edit(mmi_sms_result_enum result, void *data);
#endif
static void mmi_sms_box_list_opt_pre_reply(void);
#if defined(__MMI_MMS_IN_UM__) && !defined(__MMI_UNIFIED_COMPOSER__)
static void mmi_sms_box_list_opt_reply_by_MMS(mmi_sms_result_enum result, void *data);
static void mmi_sms_box_list_opt_pre_reply_by_MMS(void);
#endif /* defined(__MMI_MMS_IN_UM__) && !defined(__MMI_UNIFIED_COMPOSER__) */
static void mmi_sms_box_list_opt_pre_forward(void);
static void mmi_sms_box_list_opt_delete_callback(mmi_sms_result_enum result, void *data);
static void mmi_sms_box_list_opt_delete(void);
static void mmi_sms_box_list_opt_pre_delete(void);
static void mmi_sms_box_list_opt_save_to_contact(void);
#ifdef __MMI_SMS_SWITCH_MSG_READ_STATUS__
static void mmi_sms_box_list_opt_mark_as_read(void);
static void mmi_sms_box_list_opt_mark_as_unread(void);
#endif /* __MMI_SMS_SWITCH_MSG_READ_STATUS__ */
static void mmi_sms_box_list_opt_send(mmi_sms_result_enum result, void *data);
static void mmi_sms_box_list_opt_pre_send(void);
static void mmi_sms_box_list_opt_pre_edit(void);
#if (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__))
static void mmi_sms_box_list_opt_resend(mmi_sms_result_enum result, void *data);
static void mmi_sms_box_list_opt_pre_resend(void);
#endif /* (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__)) */
static void mmi_sms_box_list_opt_check_adv(MMI_ID menu_gid, U16 msg_id);
static void mmi_sms_inbox_list_opt_check_reply_call(MMI_ID menu_gid);
static void mmi_sms_inbox_list_opt_entry_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id);
static void mmi_sms_sent_list_opt_entry_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id);
static void mmi_sms_default_list_opt_entry_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id);
#ifdef __MMI_TELEPHONY_SUPPORT__
static void mmi_sms_default_list_opt_select_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id);
#endif
#ifdef __MMI_MESSAGES_DRAFT_BOX__
static void mmi_sms_drafts_list_opt_entry_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id);
#endif /* __MMI_MESSAGES_DRAFT_BOX__*/
#if (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__))
static void mmi_sms_unsent_list_opt_entry_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id);
#if (MMI_MAX_SIM_NUM >= 3)
static void mmi_sms_launch_sim_sel_resend();
#endif
#endif /* (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__)) */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
static void mmi_sms_simbox_list_opt_entry_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id);
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
#if defined(__MMI_VUI_HOMESCREEN__)
static void mmi_sms_recent_list_opt_entry_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id);
static void mmi_sms_recent_list_opt_select_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id);
#endif /* __MMI_VUI_HOMESCREEN__*/
#ifdef __MMI_MESSAGES_LIST_ADVANCED__
static void mmi_sms_box_list_adv_select_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id);
#endif /* __MMI_MESSAGES_LIST_ADVANCED__ */

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
static void mmi_sms_list_opt_bg_cancel_send(void);
static void mmi_sms_list_opt_bg_pre_edit(void);
#ifndef __MMI_UNIFIED_COMPOSER__
static void mmi_sms_list_opt_bg_edit(mmi_sms_result_enum result, void *data);
#endif
static void mmi_sms_list_opt_bg_delete(void);
static void mmi_sms_list_opt_bg_delete_unsent(void);
static MMI_BOOL mmi_sms_check_unsent_sms_status(void);
static void mmi_sms_move_unsent_sms_to_draft(void);
static void mmi_sms_bg_list_opt_entry_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id);
static void mmi_sms_bg_list_opt_select_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id);
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

static void mmi_sms_inbox_viewer_opt_entry_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id);
static void mmi_sms_sent_viewer_opt_entry_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id);
static void mmi_sms_default_viewer_opt_entry_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id);
#ifdef __MMI_TELEPHONY_SUPPORT__
static void mmi_sms_default_viewer_opt_select_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id);
#endif/*__MMI_TELEPHONY_SUPPORT__*/
static void mmi_sms_box_viewer_adv_select_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id);
static void mmi_sms_box_viewer_adv_check_hilite_setting(MMI_ID menu_gid, U16 msg_id);
#ifdef __MMI_CLIPBOARD__
static void mmi_sms_box_viewer_check_edit_option(cui_menu_event_struct* menu_evt, srv_sms_status_enum curr_msg_status);
#endif
#ifdef __MMI_MESSAGES_DRAFT_BOX__
static void mmi_sms_drafts_viewer_opt_entry_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id);
#endif /* __MMI_MESSAGES_DRAFT_BOX__*/
#if (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__))
static void mmi_sms_unsent_viewer_opt_entry_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id);
#endif /* (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__)) */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
static void mmi_sms_simbox_viewer_opt_entry_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id);
static void mmi_sms_simbox_viewer_adv_select_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id);
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

#ifdef __MMI_MESSAGE_SMS_HILITE_VIEWER__
static void mmi_sms_viewer_auto_find_on(void);
static void mmi_sms_viewer_auto_find_off(void);
#endif /* __MMI_MESSAGE_SMS_HILITE_VIEWER__ */

static void mmi_sms_menu_cui_entry_hdlr(mmi_event_struct* evt);
static void mmi_sms_menu_cui_select_hdlr(mmi_event_struct* evt);
static mmi_ret mmi_sms_group_entry_proc(mmi_event_struct* evt);

#ifdef __MMI_UM_REPORT_BOX__
static void mmi_sms_report_list_opt_select_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id);
static void mmi_sms_report_list_opt_pre_delete(void);
static void mmi_sms_report_list_opt_delete(void);
#endif /* __MMI_UM_REPORT_BOX__ */

/*Malay language support */
#if defined(__MMI_LANG_ZAWGYI_MYANMAR__) && defined(__MMI_LANG_MYANMAR__)
static void mmi_sms_box_list_opt_pre_view_for_zawgyi(mmi_event_struct *menu_evt);
#endif

/**************************************************************
 * Function Defination
 **************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_view_curr_msg
 * DESCRIPTION
 *  Read current msg for viewing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_view_curr_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_TELEPHONY_SUPPORT__
    mmi_sms_read_msg(
        g_sms_cntx.curr_msg_id,
        MMI_TRUE,
        mmi_sms_view_curr_msg_callback);
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_view_curr_msg_callback
 * DESCRIPTION
 *  Read current msg callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_TELEPHONY_SUPPORT__
static void mmi_sms_view_curr_msg_callback(mmi_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SMS_RESULT_OK)
    {
        mmi_sms_msg_status_enum msg_status = *(mmi_sms_msg_status_enum*)data;

        g_sms_cntx.curr_msg_status = msg_status;

    #ifdef __MMI_UM_ITERATOR_VIEWER__
        if (MMI_FALSE == g_sms_cntx.is_from_hs)
        {
            if (mmi_frm_scrn_is_present(g_sms_gid ,SCR_ID_SMS_PROCESSING, MMI_FRM_NODE_ALL_FLAG))
            {
                if (mmi_sms_iter_viewer_query_indexing() == MMI_TRUE)
                {
                    mmi_sms_iter_viewer_entry_viewer_scrn();
                }
            }
        }
        else
    #endif /* __MMI_UM_ITERATOR_VIEWER__ */
        {
            if ((g_sms_gid == mmi_frm_group_get_active_id())
                && (SCR_ID_SMS_PROCESSING == mmi_frm_scrn_get_active_id())
                )
            {
                mmi_sms_entry_viewer();
                mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_PROCESSING);
            }
            else if (mmi_frm_scrn_is_present(g_sms_gid, SCR_ID_SMS_PROCESSING, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
            {
                mmi_frm_node_struct new_node_info;
                new_node_info.id = SCR_ID_SMS_VIEWER;
                new_node_info.entry_proc = (mmi_proc_func)mmi_sms_entry_viewer;
                mmi_frm_scrn_replace(g_sms_gid, SCR_ID_SMS_PROCESSING, &new_node_info);
            }
        }
    }
    else
    {
        mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_PROCESSING);
    }
}

#endif/*__MMI_TELEPHONY_SUPPORT__*/
#ifdef __MMI_MESSAGES_COPY__
#if defined( __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ ) || defined (__MMI_MESSAGES_LIST_ADVANCED__)
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_adv_copy_to_phone
 * DESCRIPTION
 *  Highlight list copy handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_adv_copy_to_phone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_copy_msg(
        g_sms_cntx.curr_msg_id,
        SRV_SMS_STORAGE_ME,
        mmi_sms_list_adv_opt_action_common_callback); 
}

#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_adv_copy_to_tcard
 * DESCRIPTION
 *  mmi_sms_list_opt_adv_copy_to_tcard
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_adv_copy_to_tcard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_copy_msg(
        g_sms_cntx.curr_msg_id,
        SRV_SMS_STORAGE_TCARD,
        mmi_sms_list_adv_opt_action_common_callback); 
}



#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_adv_move_to_phone
 * DESCRIPTION
 *  Highlight list advanced option: move handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_adv_move_to_phone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_move_msg(
        g_sms_cntx.curr_msg_id,
        SRV_SMS_STORAGE_ME,
        mmi_sms_list_adv_opt_action_move_callback);
}

#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_adv_move_to_tcard
 * DESCRIPTION
 *  mmi_sms_list_opt_adv_move_to_tcard
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_adv_move_to_tcard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_move_msg(
        g_sms_cntx.curr_msg_id,
        SRV_SMS_STORAGE_TCARD,
        mmi_sms_list_adv_opt_action_move_callback);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_adv_copy_all_from_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_adv_copy_all_from_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sim_enum sim_id;
    srv_sms_box_enum curr_box_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_id = mmi_sms_get_um_filter_sim_id();
    srv_sms_get_msg_list_index(&curr_box_type, g_sms_cntx.curr_msg_id);

    mmi_sms_copy_all_sms(
        curr_box_type,
        SRV_SMS_STORAGE_ME,
        sim_id,
        mmi_sms_list_opt_adv_copy_move_all_callback);
}

#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_adv_copy_all_from_sim_to_phone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_adv_copy_all_from_sim_to_phone(void)
{
/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 srv_sms_sim_enum sim_id;
    srv_sms_box_enum curr_box_type;
	 /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_id = mmi_sms_get_um_filter_sim_id();
	srv_sms_get_msg_list_index(&curr_box_type, g_sms_cntx.curr_msg_id);
	
		mmi_sms_copy_all_sms_tcard(curr_box_type,SRV_SMS_STORAGE_SIM,SRV_SMS_STORAGE_ME,sim_id,mmi_sms_list_opt_adv_copy_move_all_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_adv_copy_all_from_phone_to_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_adv_copy_all_from_phone_to_sim(void)
{
/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 srv_sms_sim_enum sim_id;
    srv_sms_box_enum curr_box_type;
	 /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_id = mmi_sms_get_um_filter_sim_id();
	srv_sms_get_msg_list_index(&curr_box_type, g_sms_cntx.curr_msg_id);
	
		mmi_sms_copy_all_sms_tcard(curr_box_type,SRV_SMS_STORAGE_ME,SRV_SMS_STORAGE_SIM,sim_id,NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_adv_copy_all_from_phone_to_tcard
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_adv_copy_all_from_phone_to_tcard(void)
{
/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 srv_sms_sim_enum sim_id;
    srv_sms_box_enum curr_box_type;
	 /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_id = mmi_sms_get_um_filter_sim_id();
	srv_sms_get_msg_list_index(&curr_box_type, g_sms_cntx.curr_msg_id);
	
		mmi_sms_copy_all_sms_tcard(curr_box_type,SRV_SMS_STORAGE_ME,SRV_SMS_STORAGE_TCARD,sim_id,mmi_sms_list_opt_adv_copy_move_all_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_adv_copy_all_from_tcard_to_phone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_adv_copy_all_from_tcard_to_phone(void)
{
/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 srv_sms_sim_enum sim_id;
    srv_sms_box_enum curr_box_type;
	 /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_id = mmi_sms_get_um_filter_sim_id();
	srv_sms_get_msg_list_index(&curr_box_type, g_sms_cntx.curr_msg_id);
	
	mmi_sms_copy_all_sms_tcard(curr_box_type,SRV_SMS_STORAGE_TCARD,SRV_SMS_STORAGE_ME,sim_id,mmi_sms_list_opt_adv_copy_move_all_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_adv_copy_all_from_sim_to_tcard
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_adv_copy_all_from_sim_to_tcard(void)
{
/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 srv_sms_sim_enum sim_id;
    srv_sms_box_enum curr_box_type;
	 /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_id = mmi_sms_get_um_filter_sim_id();
	srv_sms_get_msg_list_index(&curr_box_type, g_sms_cntx.curr_msg_id);
	
	mmi_sms_copy_all_sms_tcard(curr_box_type,SRV_SMS_STORAGE_SIM,SRV_SMS_STORAGE_TCARD,sim_id,mmi_sms_list_opt_adv_copy_move_all_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_adv_copy_all_from_tcard_to_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_adv_copy_all_from_tcard_to_sim(void)
{
/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 srv_sms_sim_enum sim_id;
    srv_sms_box_enum curr_box_type;
	 /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_id = mmi_sms_get_um_filter_sim_id();
	srv_sms_get_msg_list_index(&curr_box_type, g_sms_cntx.curr_msg_id);
	
	mmi_sms_copy_all_sms_tcard(curr_box_type,SRV_SMS_STORAGE_TCARD,SRV_SMS_STORAGE_SIM,sim_id,NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_adv_move_all_from_sim_to_phone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_adv_move_all_from_sim_to_phone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sim_enum sim_id;
    srv_sms_box_enum curr_box_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_id = mmi_sms_get_um_filter_sim_id();
    srv_sms_get_msg_list_index(&curr_box_type, g_sms_cntx.curr_msg_id);

		mmi_sms_move_all_sms_tcard(curr_box_type,SRV_SMS_STORAGE_SIM,SRV_SMS_STORAGE_ME,sim_id,mmi_sms_list_opt_adv_copy_move_all_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_adv_move_all_from_phone_to_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_adv_move_all_from_phone_to_sim(void)
{
	  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 srv_sms_sim_enum sim_id;
    srv_sms_box_enum curr_box_type;
	 /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_id = mmi_sms_get_um_filter_sim_id();
	srv_sms_get_msg_list_index(&curr_box_type, g_sms_cntx.curr_msg_id);
	
		mmi_sms_move_all_sms_tcard(curr_box_type,SRV_SMS_STORAGE_ME,SRV_SMS_STORAGE_SIM,sim_id,NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_adv_move_all_from_phone_to_tcard
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_adv_move_all_from_phone_to_tcard(void)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 srv_sms_sim_enum sim_id;
    srv_sms_box_enum curr_box_type;
	 /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_id = mmi_sms_get_um_filter_sim_id();
	srv_sms_get_msg_list_index(&curr_box_type, g_sms_cntx.curr_msg_id);
	
		mmi_sms_move_all_sms_tcard(curr_box_type,SRV_SMS_STORAGE_ME,SRV_SMS_STORAGE_TCARD,sim_id,mmi_sms_list_opt_adv_copy_move_all_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_adv_move_all_from_tcard_to_phone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_adv_move_all_from_tcard_to_phone(void)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 srv_sms_sim_enum sim_id;
    srv_sms_box_enum curr_box_type;
	 /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_id = mmi_sms_get_um_filter_sim_id();
	srv_sms_get_msg_list_index(&curr_box_type, g_sms_cntx.curr_msg_id);
	
		mmi_sms_move_all_sms_tcard(curr_box_type,SRV_SMS_STORAGE_TCARD,SRV_SMS_STORAGE_ME,sim_id,mmi_sms_list_opt_adv_copy_move_all_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_adv_move_all_from_sim_to_tcard
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_adv_move_all_from_sim_to_tcard(void)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 srv_sms_sim_enum sim_id;
    srv_sms_box_enum curr_box_type;
	 /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_id = mmi_sms_get_um_filter_sim_id();
	srv_sms_get_msg_list_index(&curr_box_type, g_sms_cntx.curr_msg_id);
	
		mmi_sms_move_all_sms_tcard(curr_box_type,SRV_SMS_STORAGE_SIM,SRV_SMS_STORAGE_TCARD,sim_id,mmi_sms_list_opt_adv_copy_move_all_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_adv_move_all_from_tcard_to_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_adv_move_all_from_tcard_to_sim(void)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 srv_sms_sim_enum sim_id;
    srv_sms_box_enum curr_box_type;
	 /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_id = mmi_sms_get_um_filter_sim_id();
	srv_sms_get_msg_list_index(&curr_box_type, g_sms_cntx.curr_msg_id);
	
		mmi_sms_move_all_sms_tcard(curr_box_type,SRV_SMS_STORAGE_TCARD,SRV_SMS_STORAGE_SIM,sim_id,NULL);
}

#endif



/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_adv_move_all_from_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_adv_move_all_from_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sim_enum sim_id;
    srv_sms_box_enum curr_box_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_id = mmi_sms_get_um_filter_sim_id();
    srv_sms_get_msg_list_index(&curr_box_type, g_sms_cntx.curr_msg_id);

    mmi_sms_move_all_sms(
        curr_box_type,
        SRV_SMS_STORAGE_ME,
        sim_id,
        mmi_sms_list_opt_adv_copy_move_all_callback);

    g_sms_cntx.curr_msg_id = SRV_SMS_INVALID_MSG_ID;
}

#endif /* defined( __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ ) || defined (__MMI_MESSAGES_LIST_ADVANCED__) */


#if (!defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || defined(__OP01__) )
#ifdef __MMI_MESSAGES_LIST_ADVANCED__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_adv_copy_to_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_adv_copy_to_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_copy_msg(
        g_sms_cntx.curr_msg_id,
        SRV_SMS_STORAGE_SIM,
        mmi_sms_list_adv_opt_action_common_callback); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_adv_move_to_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_adv_move_to_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_move_msg(
        g_sms_cntx.curr_msg_id,
        SRV_SMS_STORAGE_SIM,
        mmi_sms_list_adv_opt_action_move_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_copy_all_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_copy_all_select_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_menu_gid = menu_evt->sender_id;
    cui_menu_event_struct *cui_menu_evt = menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sms_cntx.curr_msg_id = msg_id;

    switch (cui_menu_evt->highlighted_menu_id)
    {
    #if defined(__MMI_MESSAGES_COPY__) && (!defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || defined(__OP01__) )
        case MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL_FROM_SIM:
            mmi_sms_list_opt_adv_copy_all_from_sim();
            cui_menu_close(cui_menu_gid);
            break;

        case MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL_FROM_PHONE:
            mmi_sms_list_opt_adv_copy_all_from_phone();
            cui_menu_close(cui_menu_gid);
            break;
    #endif /* defined(__MMI_MESSAGES_COPY__) && !defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) */

#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
		case MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL_FROM_SIM_TO_PHONE:
            mmi_sms_list_opt_adv_copy_all_from_sim_to_phone();
            cui_menu_close(cui_menu_gid);
            break;
            
        case MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL_FROM_PHONE_TO_SIM:
            mmi_sms_list_opt_adv_copy_all_from_phone_to_sim();
            cui_menu_close(cui_menu_gid);
            break;   
            
            case MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL_FROM_PHONE_TO_TCARD:
            mmi_sms_list_opt_adv_copy_all_from_phone_to_tcard();
            cui_menu_close(cui_menu_gid);
            break; 
       
       case MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL_FROM_TCARD_TO_PHONE:
            mmi_sms_list_opt_adv_copy_all_from_tcard_to_phone();
            cui_menu_close(cui_menu_gid);
            break; 
            
        case MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL_FROM_SIM_TO_TCARD:
        mmi_sms_list_opt_adv_copy_all_from_sim_to_tcard();
         cui_menu_close(cui_menu_gid);
         break;
         
        case MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL_FROM_TCARD_TO_SIM:
        mmi_sms_list_opt_adv_copy_all_from_tcard_to_sim();
         cui_menu_close(cui_menu_gid);
         break;
#endif

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_move_all_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_move_all_select_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_menu_gid = menu_evt->sender_id;
    cui_menu_event_struct *cui_menu_evt = menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sms_cntx.curr_msg_id = msg_id;

    switch (cui_menu_evt->highlighted_menu_id)
    {
    #if defined(__MMI_MESSAGES_COPY__) && (!defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || defined(__OP01__) )
        case MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL_FROM_SIM:
            mmi_sms_list_opt_adv_move_all_from_sim();
            cui_menu_close(cui_menu_gid);
            break;

        case MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL_FROM_PHONE:
            mmi_sms_list_opt_adv_move_all_from_phone();
            cui_menu_close(cui_menu_gid);
            break;
    #endif /* defined(__MMI_MESSAGES_COPY__) && !defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) */

#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
		case MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL_FROM_SIM_TO_PHONE:
            mmi_sms_list_opt_adv_move_all_from_sim_to_phone();
            cui_menu_close(cui_menu_gid);
            break;
            
        case MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL_FROM_PHONE_TO_SIM:
            mmi_sms_list_opt_adv_move_all_from_phone_to_sim();
            cui_menu_close(cui_menu_gid);
            break;   
            
            case MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL_FROM_PHONE_TO_TCARD:
            mmi_sms_list_opt_adv_move_all_from_phone_to_tcard();
            cui_menu_close(cui_menu_gid);
            break; 
       
			case MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL_FROM_TCARD_TO_PHONE:
            mmi_sms_list_opt_adv_move_all_from_tcard_to_phone();
            cui_menu_close(cui_menu_gid);
            break; 
            
          case MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL_FROM_SIM_TO_TCARD:
            mmi_sms_list_opt_adv_move_all_from_sim_to_tcard();
            cui_menu_close(cui_menu_gid);
            break; 
            
            case MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL_FROM_TCARD_TO_SIM:
            mmi_sms_list_opt_adv_move_all_from_tcard_to_sim();
            cui_menu_close(cui_menu_gid);
            break;   
            
#endif

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_adv_copy_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_adv_copy_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_entry_menu_cui_appsub_generic(
        g_sms_gid,
        MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL,
        STR_ID_SMS_COPY_ALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_adv_move_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_adv_move_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_entry_menu_cui_appsub_generic(
        g_sms_gid,
        MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL,
        STR_ID_SMS_MOVE_ALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_adv_copy_all_from_phone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_adv_copy_all_from_phone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sim_enum sim_id;
    srv_sms_box_enum curr_box_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_id = mmi_sms_get_um_filter_sim_id();
    srv_sms_get_msg_list_index(&curr_box_type, g_sms_cntx.curr_msg_id);

    mmi_sms_copy_all_sms(
        curr_box_type,
        SRV_SMS_STORAGE_SIM,
        sim_id,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_adv_move_all_from_phone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_adv_move_all_from_phone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sim_enum sim_id;
    srv_sms_box_enum curr_box_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_id = mmi_sms_get_um_filter_sim_id();
    srv_sms_get_msg_list_index(&curr_box_type, g_sms_cntx.curr_msg_id);

    mmi_sms_move_all_sms(
        curr_box_type,
        SRV_SMS_STORAGE_SIM,
        sim_id,
        NULL);

    g_sms_cntx.curr_msg_id = SRV_SMS_INVALID_MSG_ID;
}


#endif /* __MMI_MESSAGES_LIST_ADVANCED__ */
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
#endif /* __MMI_MESSAGES_COPY__ */

#ifdef __MMI_MESSAGES_COPY__
#if defined( __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ ) || defined (__MMI_MESSAGES_LIST_ADVANCED__)
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_adv_opt_action_common_callback
 * DESCRIPTION
 *  Delete callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_adv_copy_move_all_callback(mmi_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__) && defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__))
    mmi_msg_update_unsent_icon();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_adv_opt_action_common_callback
 * DESCRIPTION
 *  Delete callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_adv_opt_action_common_callback(mmi_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__) && defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__))
    mmi_msg_update_unsent_icon();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_adv_opt_action_move_callback
 * DESCRIPTION
 *  Move message callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_adv_opt_action_move_callback(mmi_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SMS_RESULT_OK)
    {
        g_sms_cntx.curr_msg_id = SRV_SMS_INVALID_MSG_ID;
    }

#if (defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__) && defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__))
    mmi_msg_update_unsent_icon();
#endif
}
#endif /* __MMI_MESSAGES_COPY__ */
#endif /* __MMI_MESSAGES_LIST_ADVANCED__ */

#ifdef __MMI_TELEPHONY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_viewer
 * DESCRIPTION
 *  Entry the SMS Viewer Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_entry_viewer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    U8 *header_buff;
#ifdef __MMI_MESSAGE_SMS_HILITE_VIEWER__
    MMI_BOOL isHilite = srv_sms_is_highlight_view_setting();
#endif /* __MMI_MESSAGE_SMS_HILITE_VIEWER__ */
    mmi_id curr_sms_gid = g_sms_gid;
    MMI_BOOL enable_action = MMI_TRUE;
    U16 lsk_str = STR_GLOBAL_OPTIONS;
#ifdef __MMI_BT_MAP_CLIENT__
    MYTIME time;
    WCHAR time_buffer[40] = {0};
    WCHAR d[20] = {0}; 
    WCHAR t[20] = {0};
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(
            curr_sms_gid,
            SCR_ID_SMS_VIEWER,
            mmi_sms_exit_viewer,
            mmi_sms_entry_viewer,
            MMI_FRM_FULL_SCRN))
    {
        srv_sms_box_enum curr_box_type;
        gui_buffer = mmi_frm_scrn_get_gui_buf(curr_sms_gid, SCR_ID_SMS_VIEWER);

    #ifdef __MMI_MESSAGES_EMS__
        EnableDisableAudioPlayback();
    #endif /* __MMI_MESSAGES_EMS__ */

        /* Make sure this screen can't be re-entry */
        header_buff = mmi_sms_get_viewer_header();

        srv_sms_get_msg_list_index(&curr_box_type, g_sms_cntx.curr_msg_id);

        if (enable_action)
        {
            mmi_sms_entry_viewer_enable_csk(curr_box_type);
        }

    #ifdef __MMI_UM_ITERATOR_VIEWER__
        if (MMI_FALSE == g_sms_cntx.is_from_hs)
        {
            mmi_sms_iter_viewer_setup(middle_str);
        }
        g_sms_cntx.is_del_msg = MMI_FALSE;
    #endif /* __MMI_UM_ITERATOR_VIEWER__ */

        if ((g_sms_cntx.curr_msg_status == SMS_STATUS_DELIVERY_REPORT) ||
            (g_sms_cntx.curr_msg_status == SMS_STATUS_PENDING_REPORT) ||
            (g_sms_cntx.curr_msg_status == SMS_STATUS_UNSUPPORT))
        {
            S32 header_len =  (mmi_ucs2strlen((S8*)header_buff) + 1) * ENCODING_LENGTH;
    
        #ifdef __MMI_ICON_BAR_SUPPORT__
            if (enable_action)
            {
                mmi_sms_viewer_set_toolbar();
                mmi_sms_viewer_update_toolbar();
            }
        #endif /* __MMI_ICON_BAR_SUPPORT__ */
        #ifdef __MMI_MESSAGE_SMS_HILITE_VIEWER__
            memset(&hilite_cntx, 0, sizeof(hilite_cntx));
        #endif /* __MMI_MESSAGE_SMS_HILITE_VIEWER__ */
            ShowCategory74Screen(
                STR_SCR6024_CAPTION,
                IMG_SMS_ENTRY_SCRN_CAPTION,
                lsk_str,
                IMG_SMS_COMMON_NOIMAGE,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                header_buff,
                header_len,
                gui_buffer);
        }
        else
        {
            EMSData *ems_data;

            GetEMSDataForView(&ems_data, 0);

        #ifdef __MMI_MESSAGE_SMS_HILITE_VIEWER__
            /* enter a new view screen*/
            if (enable_action)
            {
                if (gui_buffer == NULL)
                {
                    if (isHilite)
                    {
                        mmi_sms_parse_hilite_list(ems_data, MMI_FALSE);
                        hilite_cntx.isParsed = MMI_TRUE;
                    }
                    else
                    {
                        hilite_cntx.isParsed = MMI_FALSE;
                    }
                }
                else
                {
                    if (isHilite && hilite_cntx.isParsed == MMI_FALSE)
                    {
                        mmi_sms_parse_hilite_list(ems_data, MMI_FALSE);
                        hilite_cntx.isParsed = MMI_TRUE;
                    }
                }

                wgui_inputs_EMS_set_hilite_list(
                    isHilite ? hilite_cntx.hilite_list : NULL,
                    hilite_cntx.totalListItem - 2,
                    0,
                    mmi_sms_view_hilite_cb,
                    mmi_sms_view_hilite_click_cb);
            }
        #endif /* __MMI_MESSAGE_SMS_HILITE_VIEWER__ */

        #ifdef __MMI_ICON_BAR_SUPPORT__
            if (enable_action)
            {
                mmi_sms_viewer_set_toolbar();
                mmi_sms_viewer_update_toolbar();
            }
        #endif /* __MMI_ICON_BAR_SUPPORT__ */
    /*****************************************************************************************/
    /******* Handling for ZAWGYI language ****************************************************/

	#if defined(__MMI_LANG_ZAWGYI_MYANMAR__) && defined(__MMI_LANG_MYANMAR__)
			if (g_sms_view_set_language)
			{
				if (g_sms_view_read_by_zawgyi)
					wgui_inputs_ml_enable_read_language(MMI_FONT_ENGINE_READ_LANG_ZAWGYI);
				else
					wgui_inputs_ml_enable_read_language(MMI_FONT_ENGINE_READ_LANG_MYANMAR);
			}
			else
				wgui_inputs_ml_disable_read_language();
	#endif

        #ifdef __ULC_SLIM_EMS__
        #ifdef __MMI_BT_MAP_CLIENT__
            if(srv_sms_get_msg_storage_type(g_sms_cntx.curr_msg_id) == SRV_SMS_STORAGE_SIM &&
              g_sms_cntx.curr_box_type != SRV_SMS_BOX_INBOX)
            {
                ShowCategory74Screen(
                STR_SCR6024_CAPTION,
                IMG_SMS_ENTRY_SCRN_CAPTION,
                lsk_str,
                IMG_SMS_COMMON_NOIMAGE,
                STR_GLOBAL_BACK,
                IMG_SMS_COMMON_NOIMAGE,
                ems_data->textBuffer,
                ems_data->textLength,
                gui_buffer);
            }
            else
            {
                srv_sms_get_msg_timestamp(g_sms_cntx.curr_msg_id, &time);  
                date_string((MYTIME*) & time, d, DT_IDLE_SCREEN);
                mmi_wcscpy(time_buffer, (const WCHAR*) d);  
                mmi_ucs2cat((CHAR*) time_buffer, (const CHAR*) (L" "));
                time_string((MYTIME*) & time, t, DT_IDLE_SCREEN);
                mmi_ucs2cat((CHAR*) time_buffer, (const CHAR*) t);
                mmi_ucs2cat((CHAR*) time_buffer, (const CHAR*) (L"\n\n"));
                
                set_cat145_show_number_finish();

                ShowBTNotiCategory145Screen(
                    (U8*)GetString(STR_SCR6024_CAPTION),
                    IMG_SMS_ENTRY_SCRN_CAPTION,
                    lsk_str,
                    IMG_SMS_COMMON_NOIMAGE,
                    STR_GLOBAL_BACK,
                    IMG_SMS_COMMON_NOIMAGE,
                    0,
                    (U8*)time_buffer,
                    (U8*)ems_data->textBuffer,
                    0,
                    gui_buffer);    
            }
        #else
            ShowCategory74Screen(
                STR_SCR6024_CAPTION,
                IMG_SMS_ENTRY_SCRN_CAPTION,
                lsk_str,
                IMG_SMS_COMMON_NOIMAGE,
                STR_GLOBAL_BACK,
                IMG_SMS_COMMON_NOIMAGE,
                ems_data->textBuffer,
                ems_data->textLength,
                gui_buffer);
        #endif
        #else /* __ULC_SLIM_EMS__ */
            ShowCategory39Screen(
                STR_SCR6024_CAPTION,
                IMG_SMS_ENTRY_SCRN_CAPTION,
                lsk_str,
                IMG_SMS_COMMON_NOIMAGE,
                STR_GLOBAL_BACK,
                IMG_SMS_COMMON_NOIMAGE,
                ems_data,
                header_buff,
                gui_buffer);
        #endif /* __ULC_SLIM_EMS__ */
        }

        if (enable_action)
        {
            SetLeftSoftkeyFunction(mmi_sms_pre_entry_viewer_opt, KEY_EVENT_UP);
            //SetKeyHandler(mmi_sms_viewer_set_sender_key_hdlr, KEY_SEND, KEY_EVENT_UP);
            SetKeyUpHandler(mmi_sms_viewer_set_sender_key_hdlr, KEY_SEND);
            mmi_sms_entry_viewer_set_csk(curr_box_type);
        }

        SetRightSoftkeyFunction(mmi_sms_go_back_from_viewer, KEY_EVENT_UP);
    #ifdef __MMI_UM_ITERATOR_VIEWER__
        if (MMI_FALSE == g_sms_cntx.is_from_hs)
        {
            //SetKeyHandler(mmi_sms_iter_viewer_prev_launch, KEY_LEFT_ARROW, KEY_EVENT_UP);
            SetKeyUpHandler(mmi_sms_iter_viewer_prev_launch, KEY_LEFT_ARROW);
            //SetKeyHandler(mmi_sms_iter_viewer_next_launch, KEY_RIGHT_ARROW, KEY_EVENT_UP);
            SetKeyUpHandler(mmi_sms_iter_viewer_next_launch, KEY_RIGHT_ARROW);
	    //SetKeyHandler(wgui_cat_text_viewer_show_left_slide_button_down, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
             SetKeyDownHandler(wgui_cat_text_viewer_show_left_slide_button_down, KEY_LEFT_ARROW);
            //SetKeyHandler(wgui_cat_text_viewer_show_right_slide_button_down, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
             SetKeyDownHandler(wgui_cat_text_viewer_show_right_slide_button_down, KEY_RIGHT_ARROW);
        #if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__) 
            mmi_frm_gesture_listen_event(MMI_FRM_GESTURE_LEFT, mmi_sms_iter_viewer_next_msg_gesture_hdlr);
            mmi_frm_gesture_listen_event(MMI_FRM_GESTURE_RIGHT, mmi_sms_iter_viewer_prev_msg_gesture_hdlr);
        #endif /* defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__) */
        }
    #endif /* __MMI_UM_ITERATOR_VIEWER__ */

        mmi_frm_scrn_set_leave_proc(
            curr_sms_gid,
            SCR_ID_SMS_VIEWER,
            mmi_sms_viewer_scrn_leave_proc);
    }
}

#endif/*__MMI_TELEPHONY_SUPPORT__*/
/* FM_SEND_KEY */
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_set_sender_key_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_set_sender_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_status_enum curr_msg_status = srv_sms_get_msg_status(g_sms_cntx.curr_msg_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (curr_msg_status & SRV_SMS_STATUS_READ)
    {
    #ifdef __MMI_MESSAGE_SMS_HILITE_VIEWER__
        if (!(curr_msg_status & SRV_SMS_STATUS_UNSUPPORTED))
        {
            if (hilite_cntx.isParsed == MMI_TRUE)
            {
                if ((hilite_cntx.hilite_list[hilite_cntx.currHiliteItemIndex].hilite_type == EMS_HILITE_NUMBER)
                    || (hilite_cntx.hilite_list[hilite_cntx.currHiliteItemIndex].hilite_type == EMS_HILITE_USSD))
                {
                    S32 len;
                    EMSData *ems_data;
                    mmi_ucm_make_call_para_struct param;
                    S8 validUcs2No[(APPLIB_MAX_PHONE_NUM_LEN + 1) * ENCODING_LENGTH];

                    GetEMSDataForView(&ems_data, 0);
                    len = hilite_cntx.hilite_list[hilite_cntx.currHiliteItemIndex].hilite_length / 2;
                    mmi_sms_validate_number((S8*)(ems_data->textBuffer + hilite_cntx.hilite_list[hilite_cntx.currHiliteItemIndex].offset_to_text), 
                        validUcs2No,
                        len);
                    mmi_ucm_init_call_para(&param);
                    param.dial_type = SRV_UCM_CALL_TYPE_ALL;
                    param.ucs2_num_uri = (U16 *)validUcs2No;
                    mmi_ucm_call_launch(0, &param);
                    return;
                }
            } 
        #ifdef __MMI_MESSAGES_SMS_EMAIL__
            else if (mmi_sms_is_sms_email(g_sms_cntx.curr_msg_id) == MMI_TRUE)
            {
                return;
            }
        #endif /* __MMI_MESSAGES_SMS_EMAIL__ */
        }
    #endif /* __MMI_MESSAGE_SMS_HILITE_VIEWER__ */
    
    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        if (mmi_sms_is_sms_email(g_sms_cntx.curr_msg_id) == MMI_TRUE)
        {
            return;
        }
        else
    #endif /* __MMI_MESSAGES_SMS_EMAIL__ */
        if (mmi_sms_check_is_valid_oa_addr(g_sms_cntx.curr_msg_id) == MMI_TRUE)
        {
            S8 ucs2_num[(SRV_SMS_MAX_ADDR_LEN + 1) *ENCODING_LENGTH];
            mmi_ucm_make_call_para_struct param; 
            #ifndef __MMI_SMS_SLIM__
            srv_sms_get_msg_address(g_sms_cntx.curr_msg_id, ucs2_num);
            #else
            mmi_sms_get_hilite_msg_addr((CHAR*)ucs2_num);
            #endif


            mmi_ucm_init_call_para(&param);
            param.dial_type = SRV_UCM_CALL_TYPE_ALL;
            param.ucs2_num_uri = (U16 *)ucs2_num;
            mmi_ucm_call_launch(0, &param);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_go_back_from_viewer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_go_back_from_viewer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (srv_sms_is_sms_ready() == MMI_TRUE)
    {
    #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
        if (!mmi_sms_save_contact(SCR_ID_SMS_VIEWER, SRV_SMS_BOX_INBOX))
    #endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */
        {
            mmi_frm_scrn_close_active_id();
        }
    }
    else
    {
        mmi_frm_scrn_close_active_id();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_scrn_leave_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_sms_viewer_scrn_leave_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
		default:
            if (viewer_header_buff != NULL)
            {
                OslMfree(viewer_header_buff);
                viewer_header_buff = NULL;
            }

        #ifdef __MMI_UM_ITERATOR_VIEWER__
            if (g_sms_cntx.iter_viewer_result != NULL)
            {
                OslMfree(g_sms_cntx.iter_viewer_result);
                g_sms_cntx.iter_viewer_result = NULL;
            }
        #endif /* __MMI_UM_ITERATOR_VIEWER__ */

        #ifdef __MMI_MESSAGE_SMS_HILITE_VIEWER__
            hilite_cntx.isParsed = MMI_FALSE;
        #endif /* __MMI_MESSAGE_SMS_HILITE_VIEWER__ */

            if (!mmi_frm_scrn_get_count(g_sms_gid))
            {
                mmi_frm_group_close(g_sms_gid);/*FM_QA : call it here? Answer: In create proc*/
                g_sms_gid = GRP_ID_INVALID;
            }
            break;
    }

    return MMI_RET_OK; 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_exit_viewer
 * DESCRIPTION
 *  Exit the SMS Viewer Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_exit_viewer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UM_ITERATOR_VIEWER__
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)
    if (MMI_FALSE == g_sms_cntx.is_from_hs)
    {
        mmi_frm_gesture_stop_listen_event();
    }
#endif /* defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__) */
#endif /* __MMI_UM_ITERATOR_VIEWER__ */
#if defined(__MMI_LANG_ZAWGYI_MYANMAR__) && defined(__MMI_LANG_MYANMAR__)
	//g_sms_view_set_language = MMI_FALSE;
	wgui_inputs_ml_disable_read_language();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_viewer_header
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 *mmi_sms_get_viewer_header(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (viewer_header_buff != NULL)
    {
        OslMfree(viewer_header_buff);
        viewer_header_buff = NULL;
    }

    viewer_header_buff = OslMalloc((MMI_SMS_MAX_VIEWER_HEADER_LEN + 1) * ENCODING_LENGTH);

    if (g_sms_cntx.curr_msg_status == SMS_STATUS_UNSUPPORT)
    {
        mmi_ucs2cpy(viewer_header_buff, GetString(STR_GLOBAL_NOT_SUPPORTED));
    }
    else
    {
        U16 header_str_id = 0;

        switch (g_sms_cntx.curr_msg_status)
        {
            #ifndef __MMI_SMS_SLIM__
            case SMS_STATUS_SENT:
            case SMS_STATUS_UNSENT:
            case SMS_STATUS_DRAFTS:
                header_str_id = STR_SMS_MESSAGE_HEADER_TO;
                break;
                #endif

            case SMS_STATUS_DELIVERY_REPORT:
                header_str_id = STR_SR_DELIVERD_ID;
                break;
            case SMS_STATUS_PENDING_REPORT:
                header_str_id = STR_SR_PENDING_ID;
                break;

            default:
                break;
        }

        if (header_str_id != 0)
        {
            kal_wsprintf((WCHAR*)viewer_header_buff, 
                "%w\n", 
                GetString(header_str_id));
        }
        else
        {
            viewer_header_buff[0] = '\0';
            viewer_header_buff[1] = '\0';
        }

    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        if (g_sms_cntx.is_sms_email == MMI_TRUE)
        {
            mmi_ucs2cat(viewer_header_buff, g_sms_cntx.sms_email_addr);
        }
        else
    #endif /* __MMI_MESSAGES_SMS_EMAIL__ */
        {
           #ifndef __MMI_SMS_SLIM__
            U16 number[SRV_SMS_MAX_ADDR_LEN + 1];
	        U16 name[MMI_PHB_NAME_LENGTH + 1];
            U16 *temp;
			#ifndef __MMI_SMS_SLIM__
            srv_sms_get_msg_address(g_sms_cntx.curr_msg_id, (S8*)number);
			#else
			mmi_sms_get_hilite_msg_addr((S8*)number);
			#endif

            srv_phb_get_name_by_number(number, name, MMI_PHB_NAME_LENGTH);

            if (name[0])
            {
                temp = name;
            }
            else
            {
                temp = number;
            }

            mmi_ucs2cat(viewer_header_buff, (S8*)temp);
            #endif
        }
 #ifndef __MMI_SMS_SLIM__
        /* Only the inbox msg need to show the Data and Time */
        if ((g_sms_cntx.curr_msg_status == SMS_STATUS_UNREAD) ||
            (g_sms_cntx.curr_msg_status == SMS_STATUS_INBOX) ||
            (g_sms_cntx.curr_msg_status == SMS_STATUS_DELIVERY_REPORT) ||
            (g_sms_cntx.curr_msg_status == SMS_STATUS_PENDING_REPORT))
        {
            WCHAR ts_date[MAX_TIMESTAMP_SIZE + 1];
            WCHAR ts_time[MAX_TIMESTAMP_SIZE + 1];

            mmi_sms_get_msg_date_time(
                g_sms_cntx.curr_msg_id,
                (S8*)ts_date,
                (S8*)ts_time);

            kal_wsprintf((WCHAR*)viewer_header_buff, 
                "%w\n%w\n%w\n", 
                viewer_header_buff, 
                ts_date,
                ts_time);
        }
        #endif
    }

    MMI_ASSERT(mmi_ucs2strlen(viewer_header_buff) <= MMI_SMS_MAX_VIEWER_HEADER_LEN);

    return (U8*)viewer_header_buff;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_viewer_enable_csk
 * DESCRIPTION
 *  Enable the SMS Viewer Screen CSK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_entry_viewer_enable_csk(srv_sms_box_enum curr_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    if (curr_box_type == SRV_SMS_BOX_SIM)
    {
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }
    else
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    {
        switch(g_sms_cntx.curr_msg_status)
        {
            case SMS_STATUS_UNREAD:
            case SMS_STATUS_INBOX:
                if (mmi_sms_check_is_valid_oa_addr(g_sms_cntx.curr_msg_id) == MMI_TRUE)
                {
                    EnableCenterSoftkey(0, IMG_GLOBAL_REPLY_MSG_CSK);
                }
                else
                {
                    EnableCenterSoftkey(0, IMG_GLOBAL_FORWARD_MSG_CSK);
                }
                break;

            case SMS_STATUS_SENT:
                EnableCenterSoftkey(0, IMG_GLOBAL_FORWARD_MSG_CSK);
                break;

            case SMS_STATUS_UNSENT:
        #ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
            case SMS_STATUS_DRAFTS:
        #endif
            {
                if (mmi_sms_is_send_enable() == MMI_TRUE)
                {
                #ifdef __MMI_WGUI_CSK_ENABLE__
                    EnableCenterSoftkey(0, IMG_GLOBAL_SEND_MSG_CSK);
                #endif
                }
                else
                {
                    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
                }
                break;
            }
        #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
            case SMS_STATUS_DRAFTS:
            {
                EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
                break;
            }
        #endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
            case SMS_STATUS_UNSUPPORT:
                if (curr_box_type == SRV_SMS_BOX_INBOX)
                {
                    if (mmi_sms_check_is_valid_oa_addr(g_sms_cntx.curr_msg_id) == MMI_TRUE)
                    {
                        EnableCenterSoftkey(0, IMG_GLOBAL_REPLY_MSG_CSK);
                        break;
                    }
                }
            case SMS_STATUS_DELIVERY_REPORT:
            case SMS_STATUS_PENDING_REPORT:
            default:
                EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        }
    }
}

#ifdef __MMI_TELEPHONY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_viewer_set_csk
 * DESCRIPTION
 *  Set the SMS Viewer Screen CSK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_entry_viewer_set_csk(srv_sms_box_enum curr_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    if (curr_box_type == SRV_SMS_BOX_SIM)
    {
        SetCenterSoftkeyFunction(mmi_sms_viewer_opt_pre_delete, KEY_EVENT_UP);
    }
    else
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    {
        switch(g_sms_cntx.curr_msg_status)
        {
            case SMS_STATUS_UNREAD:
            case SMS_STATUS_INBOX:
                if (mmi_sms_check_is_valid_oa_addr(g_sms_cntx.curr_msg_id) == MMI_TRUE)
                {
                    SetCenterSoftkeyFunction(mmi_sms_viewer_opt_reply, KEY_EVENT_UP);
                }
                else
                {
                    SetCenterSoftkeyFunction(mmi_sms_viewer_opt_forward, KEY_EVENT_UP);
                }
                break;

            case SMS_STATUS_SENT:
                SetCenterSoftkeyFunction(mmi_sms_viewer_opt_forward, KEY_EVENT_UP);
                break;

        #if (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__))
            case SMS_STATUS_UNSENT:
                if (mmi_sms_is_send_enable() == MMI_TRUE)
                {
                    #if (MMI_MAX_SIM_NUM <= 2)
                    SetCenterSoftkeyFunction(mmi_sms_viewer_opt_resend, KEY_EVENT_UP);
                    #else
                    SetCenterSoftkeyFunction(mmi_sms_launch_sim_sel_resend, KEY_EVENT_UP);
                    #endif
                }
                else
                {
                    SetCenterSoftkeyFunction(mmi_sms_viewer_opt_edit, KEY_EVENT_UP);
                }
                break;

        #else /* (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__)) */
            case SMS_STATUS_UNSENT:
        #endif /* (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__)) */
            case SMS_STATUS_DRAFTS:
            {
                if (mmi_sms_is_send_enable() == MMI_TRUE)
                {
                    SetCenterSoftkeyFunction(mmi_sms_viewer_opt_send, KEY_EVENT_UP);
                }
                else
                {
                    SetCenterSoftkeyFunction(mmi_sms_viewer_opt_edit, KEY_EVENT_UP);
                }
                break;
            }

            case SMS_STATUS_UNSUPPORT:
                if (curr_box_type == SRV_SMS_BOX_INBOX)
                {
                    if (mmi_sms_check_is_valid_oa_addr(g_sms_cntx.curr_msg_id) == MMI_TRUE)
                    {
                        SetCenterSoftkeyFunction(mmi_sms_viewer_opt_reply, KEY_EVENT_UP);
                        break;
                    }
                }
            case SMS_STATUS_DELIVERY_REPORT:
            case SMS_STATUS_PENDING_REPORT:
            default:
                SetCenterSoftkeyFunction(mmi_sms_viewer_opt_pre_delete, KEY_EVENT_UP);
                break;
        }
    }
}

#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_pre_entry_viewer_opt
 * DESCRIPTION
 *  Entry SMS Viwer Options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_pre_entry_viewer_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_MENU_ID menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_id = mmi_sms_get_viewer_opt_menu_id(g_sms_cntx.curr_msg_id);

    mmi_sms_entry_menu_cui_options_generic(
        g_sms_gid,
        menu_id,
        0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_check_viewer_adv_copy_move
 * DESCRIPTION
 *  Check viewer advanced copy and move
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_check_viewer_adv_copy_move(MMI_ID menu_gid, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef  __MMI_MESSAGES_COPY__
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    srv_sms_box_enum curr_box_type = SRV_SMS_BOX_NONE;
#endif
    MMI_ID cui_menu_gid = menu_gid;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef  __MMI_MESSAGES_COPY__
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    srv_sms_get_msg_list_index(&curr_box_type, msg_id);

    if (curr_box_type == SRV_SMS_BOX_ARCHIVE)
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_PHONE, MMI_TRUE);
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_PHONE, MMI_TRUE);
    #if(!defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || defined(__OP01__) )
    
    #if (defined(__OP01__) && (MMI_MAX_SIM_NUM == 2))
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_SIM1, MMI_TRUE);
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_SIM1, MMI_TRUE);
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_SIM2, MMI_TRUE);
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_SIM2, MMI_TRUE);
    #else
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_SIM, MMI_TRUE);
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_SIM, MMI_TRUE);
    #endif
    #endif
    }
    else
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 
    {
#if (defined(__OP01__) && (MMI_MAX_SIM_NUM == 2))
        if (srv_sms_get_msg_storage_type(msg_id) == SRV_SMS_STORAGE_ME)
        {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_PHONE, MMI_TRUE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_PHONE, MMI_TRUE);

            if (!srv_sim_ctrl_is_available(MMI_SIM1))
            {
                cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_SIM1, MMI_TRUE);
                cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_SIM1, MMI_TRUE);
            }
            if((!srv_sim_ctrl_is_available(MMI_SIM2)))
            {
                cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_SIM2, MMI_TRUE);
                cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_SIM2, MMI_TRUE);
            }
        }
		/*Amit add for Tcard storage*/
        else
        {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_SIM1, MMI_TRUE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_SIM1, MMI_TRUE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_SIM2, MMI_TRUE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_SIM2, MMI_TRUE);
        }
#else
        if (srv_sms_get_msg_storage_type(msg_id) == SRV_SMS_STORAGE_SIM)
        {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_PHONE, MMI_FALSE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_PHONE, MMI_FALSE);
            #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
            if (srv_fmgr_drv_is_accessible(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE)))
            {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_TCARD, MMI_FALSE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_TCARD, MMI_FALSE);
            }
            else
            {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_TCARD, MMI_TRUE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_TCARD, MMI_TRUE);
            }
            #endif /*__MMI_SMS_TCARD_STORAGE_SUPPORT__*/
        #if(!defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || defined(__OP01__) )
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_SIM, MMI_TRUE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_SIM, MMI_TRUE);
        #endif
        }
        #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
        else if (srv_sms_get_msg_storage_type(msg_id) == SRV_SMS_STORAGE_TCARD)
            {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_TCARD, MMI_TRUE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_TCARD, MMI_TRUE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_PHONE, MMI_FALSE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_PHONE, MMI_FALSE);
        #if(!defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || defined(__OP01__) )
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_SIM, MMI_FALSE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_SIM, MMI_FALSE);
        #endif

        #ifdef __MMI_DUAL_SIM_MASTER__
        #if(!defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || defined(__OP01__) )
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
        #endif
        #endif
        }
        #endif /*__MMI_SMS_TCARD_STORAGE_SUPPORT__*/
        else
        {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_PHONE, MMI_TRUE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_PHONE, MMI_TRUE);
            #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
             if (srv_fmgr_drv_is_accessible(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE)))
            {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_TCARD, MMI_FALSE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_TCARD, MMI_FALSE);
            }
            else
            {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_TCARD, MMI_TRUE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_TCARD, MMI_TRUE);
            }
            #endif /*__MMI_SMS_TCARD_STORAGE_SUPPORT__*/
        #if(!defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || defined(__OP01__) )
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_SIM, MMI_FALSE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_SIM, MMI_FALSE);
        #endif

        #ifdef __MMI_DUAL_SIM_MASTER__
        #if(!defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || defined(__OP01__) )
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
        #endif
        #endif
        }
#endif
    }
#endif /* __MMI_MESSAGES_COPY__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_check_viewer_adv_detail
 * DESCRIPTION
 *  Check viewer advanced use detail
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_check_viewer_adv_detail(MMI_ID menu_gid, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_status_enum curr_msg_status = srv_sms_get_msg_status(msg_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (curr_msg_status & SRV_SMS_STATUS_UNSUPPORTED)
    {
#ifdef __MMI_MESSAGE_SMS_USE_DETAIL__
        cui_menu_set_item_hidden(menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_USE_NUM, MMI_TRUE);
    #ifdef __MMI_MESSAGES_USE_URL__
        cui_menu_set_item_hidden(menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_USE_URL, MMI_TRUE);
    #endif /* __MMI_MESSAGES_USE_URL__ */
    #if defined(__MMI_EMAIL__) || (defined(__MMI_PHB_OPTIONAL_FIELD__))
        cui_menu_set_item_hidden(menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_USE_EMAIL, MMI_TRUE);
    #endif /* defined(__MMI_EMAIL__) || (defined(__MMI_PHB_OPTIONAL_FIELD__)) */
    #ifndef __MMI_SMS_SLIM__
        cui_menu_set_item_hidden(menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_USE_USSD, MMI_TRUE);
    #endif
#endif /*__MMI_MESSAGE_SMS_USE_DETAIL__*/
    #ifdef __MMI_BPP20_SUPPORT__
        cui_menu_set_item_hidden(menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_PRINT, MMI_TRUE);
    #endif /* __MMI_BPP20_SUPPORT__ */
    }
    else
    {
#ifdef __MMI_MESSAGE_SMS_USE_DETAIL__
        cui_menu_set_item_hidden(menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_USE_NUM, MMI_FALSE);
    #ifdef __MMI_MESSAGES_USE_URL__
        cui_menu_set_item_hidden(menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_USE_URL, MMI_FALSE);
    #endif /* __MMI_MESSAGES_USE_URL__ */
    #if defined(__MMI_EMAIL__) || (defined(__MMI_PHB_OPTIONAL_FIELD__))
        cui_menu_set_item_hidden(menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_USE_EMAIL, MMI_FALSE);
    #endif /* defined(__MMI_EMAIL__) || (defined(__MMI_PHB_OPTIONAL_FIELD__)) */
        #ifndef __MMI_SMS_SLIM__
        cui_menu_set_item_hidden(menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_USE_USSD, MMI_FALSE);
        #endif
#endif /*__MMI_MESSAGE_SMS_USE_DETAIL__*/
    #ifdef __MMI_BPP20_SUPPORT__
        if (mmi_bt_is_to_display_bt_menu())
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_PRINT, MMI_FALSE);
        }
        else
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_PRINT, MMI_TRUE);
        }
    #endif /* __MMI_BPP20_SUPPORT__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_operation
 * DESCRIPTION
 *  Pre entry list option send
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_opt_operation(mmi_sms_send_case_enum send_case)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_entry_write_msg(send_case);

    mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_VIEWER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_reply
 * DESCRIPTION
 *  Highlight replay handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_opt_reply(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_box_enum curr_box_type;
    mmi_sms_send_case_enum send_case;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_get_msg_list_index(&curr_box_type, g_sms_cntx.curr_msg_id);

    if (curr_box_type == SRV_SMS_BOX_ARCHIVE)
    {
        send_case = SMS_SEND_CASE_ARCHIVE_REPLY;
    }
    else
    {
        send_case = SMS_SEND_CASE_REPLY;
    }

    mmi_sms_viewer_opt_operation(send_case);
}


#if defined(__MMI_MMS_IN_UM__) && !defined(__MMI_UNIFIED_COMPOSER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_reply_by_MMS
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_opt_reply_by_MMS(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_reply_by_MMS();
    mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_VIEWER);
}
#endif /* defined(__MMI_MMS_STANDALONE_COMPOSER__) && !defined(__MMI_UNIFIED_COMPOSER__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_send
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_opt_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_viewer_opt_operation(SMS_SEND_CASE_SEND_DRAFT);
}


#if (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__))
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_resend
 * DESCRIPTION
 *  Resend Unsent Msg In the List Options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_opt_resend(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_viewer_opt_operation(SMS_SEND_CASE_RESEND);
}
#endif /* (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__)) */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_forward
 * DESCRIPTION
 *  Highlight forward handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_opt_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_COMPOSER__
    cui_uc_entry_msg_operation_launch(g_sms_parent_gid, g_sms_cntx.curr_msg_id, (U16)MMI_UC_INFO_TYPE_SMS, MMI_UC_OPERATION_FORWARD);
    mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_VIEWER);
#else /* __MMI_UNIFIED_COMPOSER__ */
    mmi_sms_viewer_opt_operation(SMS_SEND_CASE_FORWARD);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_edit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_opt_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_COMPOSER__
    cui_uc_entry_msg_operation_launch(g_sms_parent_gid, g_sms_cntx.curr_msg_id, (U16)MMI_UC_INFO_TYPE_SMS, MMI_UC_OPERATION_EDIT_EXISTED_MSG);
    mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_VIEWER);
#else /* __MMI_UNIFIED_COMPOSER__ */
    {
        srv_sms_status_enum curr_msg_status;
        mmi_sms_send_case_enum send_case = SMS_SEND_CASE_EDIT_UNSENT;

    #ifdef __MMI_MESSAGES_DRAFT_BOX__
        curr_msg_status = srv_sms_get_msg_status(g_sms_cntx.curr_msg_id);

        if (curr_msg_status & SRV_SMS_STATUS_DRAFT)
        {
            send_case = SMS_SEND_CASE_EDIT_DRAFT;
        }
    #endif /* __MMI_MESSAGES_DRAFT_BOX__ */

        mmi_sms_viewer_opt_operation(send_case);
    }
#endif /* __MMI_UNIFIED_COMPOSER__ */
}

#ifdef __MMI_TELEPHONY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_pre_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_opt_pre_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_entry_confirm(
        g_sms_gid,
        STR_GLOBAL_DELETE_ASK,
        mmi_sms_viewer_opt_delete,
        mmi_frm_scrn_close_active_id,
        MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_opt_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_delete_msg(g_sms_cntx.curr_msg_id, mmi_sms_viewer_opt_delete_callback);

#ifdef __MMI_UM_ITERATOR_VIEWER__
    if (MMI_FALSE == g_sms_cntx.is_from_hs)
    {
        g_sms_cntx.is_del_msg = MMI_TRUE;
    }
	else
#endif
    {
        mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_VIEWER);
    }
}
#endif /*__MMI_TELEPHONY_SUPPORT__*/

#if defined(__MMI_SMS_SET_AS_REMINDER__) && defined(__MMI_TODOLIST__)
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_add_to_calendar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_viewer_opt_add_to_calendar(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_tdl_is_full(SRV_TDL_VCAL_EVENT))
    {
        mmi_sms_display_popup_ext(
            STR_ID_TDL_CAL_FULL,
            MMI_EVENT_FAILURE);
    }
    else
    {
        MMI_ID cui_calendar_gid;
        EMSData *pEMS;
        U16 text_buffer[MAX_TODO_NOTE_LEN *ENCODING_LENGTH];

        GetEMSDataForView(&pEMS, 0);

        srv_sms_remove_escape_char(
            (S8*)text_buffer,
            (S8*)pEMS->textBuffer,
            ((MAX_TODO_NOTE_LEN - 1) * 2) > pEMS->textLength ? pEMS->textLength : ((MAX_TODO_NOTE_LEN - 1) * 2));

        cui_calendar_gid = cui_cal_save_create(parent_gid);

        if (cui_calendar_gid != GRP_ID_INVALID)
        {
            cui_cal_save_set_subject(cui_calendar_gid, text_buffer);
    		cui_cal_save_run(cui_calendar_gid);
        }
    }
}
#endif /* defined(__MMI_SMS_SET_AS_REMINDER__ && defined(__MMI_TODOLIST__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_delete_callback
 * DESCRIPTION
 *  Delete callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_opt_delete_callback(mmi_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SMS_RESULT_OK)
    {
    #ifdef __MMI_UM_ITERATOR_VIEWER__
    
    #else  /* __MMI_UM_ITERATOR_VIEWER__ */
        g_sms_cntx.curr_msg_id = SRV_SMS_INVALID_MSG_ID;
    #endif /* __MMI_UM_ITERATOR_VIEWER__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_call_sender
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_entry_call_sender(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ucs2_num[(SRV_SMS_MAX_ADDR_LEN + 1) *ENCODING_LENGTH];
    mmi_ucm_make_call_para_struct param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UM_REPORT_BOX__
    if (srv_sms_is_report_msg(g_sms_cntx.curr_msg_id))
    {
        U16 report_id;

        report_id = srv_sms_msg_id_to_report_id(g_sms_cntx.curr_msg_id);

        srv_sms_get_report_number(report_id, (WCHAR*)ucs2_num);
    }
    else
#endif /* __MMI_UM_REPORT_BOX__ */
    {
			#ifndef __MMI_SMS_SLIM__
        srv_sms_get_msg_address(g_sms_cntx.curr_msg_id, ucs2_num);
			#else
			mmi_sms_get_hilite_msg_addr((S8*)ucs2_num);
			#endif
    }

    if ((ucs2_num[0] != '\0') || (ucs2_num[1] != '\0'))
    {
        mmi_ucm_init_call_para(&param);
    
        param.dial_type = SRV_UCM_CALL_TYPE_ALL;
        param.ucs2_num_uri = (U16 *)ucs2_num;
    
        mmi_ucm_call_launch(0, &param);
    }
    else
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_NO_NUMBER,
            MMI_EVENT_FAILURE);
    }
}


#ifdef __MMI_MESSAGES_USERDEFINED_TEMPLATE__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_save_as_template
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_opt_save_as_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_save_view_content_as_template();
    mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_VIEWER);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_pre_save_as_template
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_opt_pre_save_as_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSData *pEMS;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetEMSDataForView(&pEMS, 0);

    if (mmi_sms_init_templates() == MMI_FALSE)
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_NOT_SUPPORTED,
            MMI_EVENT_FAILURE);
    }
    else if (pEMS->textLength == 0)
    {
        mmi_sms_display_popup_ext(
            STR_SMS_FAILURE_TEXT_CONTENT_EMPTY,
            MMI_EVENT_FAILURE);
    }
#ifndef __ULC_SLIM_EMS__
    else if (pEMS->listHead != NULL)
    {
        mmi_sms_entry_confirm_sg(
            g_sms_gid,
            STR_SMS_SAVE_TEXT_CONTENT_ONLY_QUERY_ID,
            mmi_sms_viewer_opt_save_as_template,
            mmi_frm_scrn_close_active_id);
            return;
    }
#endif /* __ULC_SLIM_EMS__ */
    else
    {
        mmi_sms_viewer_opt_save_as_template();
        return;
    } 
    mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_VIEWER);
}
#endif /* __MMI_MESSAGES_USERDEFINED_TEMPLATE__ */


#ifdef __MMI_MESSAGES_COPY__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_adv_copy_to_phone
 * DESCRIPTION
 *  Highlight viewer copy handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_opt_adv_copy_to_phone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_copy_msg(
        g_sms_cntx.curr_msg_id,
        SRV_SMS_STORAGE_ME,
        mmi_sms_viewer_adv_opt_action_common_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_adv_move_to_phone
 * DESCRIPTION
 *  Highlight viewer advanced option: move handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_opt_adv_move_to_phone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_move_msg(
        g_sms_cntx.curr_msg_id,
        SRV_SMS_STORAGE_ME,
        mmi_sms_viewer_adv_opt_action_move_callback);
}

 #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_adv_copy_to_tcard
 * DESCRIPTION
 *  mmi_sms_viewer_opt_adv_copy_to_tcard
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_opt_adv_copy_to_tcard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
		mmi_sms_copy_msg(
			g_sms_cntx.curr_msg_id,
			SRV_SMS_STORAGE_TCARD,
			mmi_sms_viewer_adv_opt_action_common_callback);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_adv_move_to_tcard
 * DESCRIPTION
 * mmi_sms_viewer_opt_adv_move_to_tcard
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_opt_adv_move_to_tcard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
		mmi_sms_move_msg(
			g_sms_cntx.curr_msg_id,
			SRV_SMS_STORAGE_TCARD,
			mmi_sms_viewer_adv_opt_action_move_callback);
}
#endif /*__MMI_SMS_TCARD_STORAGE_SUPPORT__*/


#if(!defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || defined(__OP01__) )
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_adv_copy_to_sim
 * DESCRIPTION
 *  Highlight viewer copy handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_opt_adv_copy_to_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_copy_msg(
        g_sms_cntx.curr_msg_id,
        SRV_SMS_STORAGE_SIM,
        mmi_sms_viewer_adv_opt_action_common_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_adv_move_to_sim
 * DESCRIPTION
 *  Highlight viewer advanced option: move handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_opt_adv_move_to_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_move_msg(
        g_sms_cntx.curr_msg_id,
        SRV_SMS_STORAGE_SIM,
        mmi_sms_viewer_adv_opt_action_move_callback);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_adv_copy_to_phone
 * DESCRIPTION
 *  Highlight viewer copy handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_opt_adv_copy_to_sim_ext(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_copy_msg_ext(
        g_sms_cntx.curr_msg_id,
        SRV_SMS_STORAGE_SIM,
        sim_id,
        mmi_sms_viewer_adv_opt_action_common_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_adv_move_to_phone
 * DESCRIPTION
 *  Highlight viewer advanced option: move handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_opt_adv_move_to_sim_ext(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_move_msg_ext(
        g_sms_cntx.curr_msg_id,
        SRV_SMS_STORAGE_SIM,
        sim_id,
        mmi_sms_viewer_adv_opt_action_move_callback);
}



#endif /* #if(!defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || defined(__OP01__) )*/
#endif /* __MMI_MESSAGES_COPY__ */

#ifdef __MMI_MESSAGE_SMS_USE_DETAIL__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_adv_use_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_opt_adv_use_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_use_detail(MMI_SMS_ADDR_PHONENUMBER);
}

#ifdef __MMI_MESSAGES_USE_URL__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_adv_use_url
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_opt_adv_use_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_use_detail(MMI_SMS_ADDR__URL);
}
#endif /* __MMI_MESSAGES_USE_URL__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_adv_use_ussd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_opt_adv_use_ussd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_use_detail(MMI_SMS_ADDR_USSD);
}


#if defined(__MMI_EMAIL__) || (defined(__MMI_PHB_OPTIONAL_FIELD__))
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_adv_use_email
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_opt_adv_use_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_use_detail(MMI_SMS_ADDR__EMAIL);
}
#endif /* __MMI_EMAIL__ */
#endif /* __MMI_MESSAGE_SMS_USE_DETAIL__ */


#ifdef __MMI_BPP20_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_adv_print
 * DESCRIPTION
 *  Print
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_opt_adv_print(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_bpp_pre_print_ems(g_sms_gid);
}
#endif /* __MMI_BPP20_SUPPORT__ */



#if defined(__MMI_SMS_APP_EMS_SUPPORT__) && defined(__MMI_MESSAGE_SMS_USE_DETAIL__)
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_adv_save_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_opt_adv_save_object(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ems_pre_entry_save_object_list(g_sms_gid);
}
#endif /* __MMI_SMS_APP_EMS_SUPPORT__ && __MMI_MESSAGE_SMS_USE_DETAIL__ */


#ifdef __MMI_MESSAGE_SMS_USE_DETAIL__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_use_detail
 * DESCRIPTION
 *  Entry use detail list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_use_detail(mmi_msg_addr_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TELEPHONY_SUPPORT__
    EMSData *pEMS;
#ifndef __ULC_SLIM_EMS__
#if defined(__MMI_MESSAGES_USE_URL__) || defined(__MMI_EMAIL__) || (defined(__MMI_PHB_OPTIONAL_FIELD__))
    EMSPosition position;
#endif /* __MMI_MESSAGES_USE_URL__ */
#endif /* __ULC_SLIM_EMS__ */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetEMSDataForView(&pEMS, 0);
#ifndef __ULC_SLIM_EMS__
#if defined(__MMI_MESSAGES_USE_URL__) || defined(__MMI_EMAIL__) || (defined(__MMI_PHB_OPTIONAL_FIELD__))
    position = pEMS->CurrentPosition;
    if ((type == MMI_SMS_ADDR__URL) || (type == MMI_SMS_ADDR__EMAIL))
    {
        mmi_msg_ems_remove_escape_char(pEMS);
    }
#endif /* __MMI_MESSAGES_USE_URL__ */ 
#else /* __ULC_SLIM_EMS__ */
    pEMS->textLength = mmi_ucs2strlen((const CHAR *)pEMS->textBuffer) * ENCODING_LENGTH;
#endif /* __ULC_SLIM_EMS__ */

    mmi_sms_pre_entry_use_detail_list_sg(g_sms_gid, type, (S8 *)pEMS->textBuffer, (U16)pEMS->textLength, NULL);
#ifndef __ULC_SLIM_EMS__
#if defined(__MMI_MESSAGES_USE_URL__) || defined(__MMI_EMAIL__) || (defined(__MMI_PHB_OPTIONAL_FIELD__))
    if ((type == MMI_SMS_ADDR__URL) || (type == MMI_SMS_ADDR__EMAIL))
    {
        mmi_msg_ems_add_escape_char(pEMS);
        MoveCursorToPosition(pEMS, &position);
    }
#endif /* __MMI_MESSAGES_USE_URL__ */
#endif /* __ULC_SLIM_EMS__ */
#endif/*__MMI_TELEPHONY_SUPPORT__*/
}
#endif /* __MMI_MESSAGE_SMS_USE_DETAIL__ */


#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_move_sms_to_archive
 * DESCRIPTION
 *  move to sms to archive
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_move_sms_to_archive(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*)MMI_SMS_ARCH_FOLDER_DRV))
        {
            /* MMI public drive is exported, cannot use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            if (!mmi_frm_scrn_get_count(g_sms_gid))
            {
                mmi_frm_group_close(g_sms_gid);
            }
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */

    mmi_sms_move_msg_to_archive(g_sms_cntx.curr_msg_id, mmi_sms_move_sms_to_archive_callback);
#ifdef __MMI_UM_ITERATOR_VIEWER__
    if (MMI_FALSE == g_sms_cntx.is_from_hs)
    {
        g_sms_cntx.is_del_msg = MMI_TRUE;
    }
	else
#endif
    {
        mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_VIEWER);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_move_sms_to_archive_callback
 * DESCRIPTION
 *  Delete callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_move_sms_to_archive_callback(mmi_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SMS_RESULT_OK)
    {
#ifdef __MMI_UM_ITERATOR_VIEWER__
    
#else   /* __MMI_UM_ITERATOR_VIEWER__ */
        g_sms_cntx.curr_msg_id = SRV_SMS_INVALID_MSG_ID;
#endif  /* __MMI_UM_ITERATOR_VIEWER__ */
    }
}
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */


#if defined(__MMI_SMS_APP_EMS_SUPPORT__) && defined(__MMI_MESSAGE_SMS_USE_DETAIL__)
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_check_save_object_menu_item
 * DESCRIPTION
 *  check whether exist objects
 * PARAMETERS
 *  void
 * RETURNS
 *  If exist return MMI_TRUE, else return MMI_FALSE
 *****************************************************************************/
static void mmi_sms_check_save_object_menu_item(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSData *pEms;
    EMSObject *object_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetEMSDataForView(&pEms, 0);
    object_p = pEms->listHead;

    cui_menu_set_item_hidden(menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_SAVE_OBJ, MMI_TRUE);
#if defined(__MMI_FILE_MANAGER__)
    while (object_p)
    {
        if ((object_p->Type == EMS_TYPE_PIC) || (object_p->Type == EMS_TYPE_USERDEF_ANM) ||
    #if defined(__MMI_IMELODY_SUPPORT__)
            (object_p->Type == EMS_TYPE_USERDEF_SND) ||
    #endif 
            KAL_FALSE)
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_SAVE_OBJ, MMI_FALSE);
            break;
        }
        object_p = object_p->next;
    }
#endif /* defined(__MMI_FILE_MANAGER__) */
}
#endif /* __MMI_SMS_APP_EMS_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_adv_opt_action_common_callback
 * DESCRIPTION
 *  Delete callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_adv_opt_action_common_callback(mmi_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__) && defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__))
    mmi_msg_update_unsent_icon();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_adv_opt_action_move_callback
 * DESCRIPTION
 *  Delete callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_adv_opt_action_move_callback(mmi_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SMS_RESULT_OK)
    {
#ifdef __MMI_UM_ITERATOR_VIEWER__
        if (MMI_FALSE == g_sms_cntx.is_from_hs)
        {
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
            mmi_sms_iter_viewer_handle_curr_msg_deleted();
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
        }
        else
#endif  /* __MMI_UM_ITERATOR_VIEWER__ */
        {
            g_sms_cntx.curr_msg_id = SRV_SMS_INVALID_MSG_ID;
            mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_VIEWER);
        }
    }
#if (defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__) && defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__))
    mmi_msg_update_unsent_icon();
#endif
}


#if defined(__MMI_MMS_IN_UM__) && !defined(__MMI_UNIFIED_COMPOSER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_reply_by_MMS
 * DESCRIPTION
 *  Highlight replay by MMS handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_reply_by_MMS(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *ucs2_addr;
    S8 tmp_ucs2_num[(MMI_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH];
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    mmi_sms_address_type_enum addr_type;
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    if (g_sms_cntx.is_sms_email == MMI_TRUE)
    {
        ucs2_addr = g_sms_cntx.sms_email_addr;
        addr_type = SMS_ADDR_TYPE_EMAIL_ADDR;
    }
    else
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
    {
			#ifndef __MMI_SMS_SLIM__
        srv_sms_get_msg_address(g_sms_cntx.curr_msg_id, tmp_ucs2_num);
			#else
			mmi_sms_get_hilite_msg_addr((S8*)tmp_ucs2_num);
			#endif

        ucs2_addr = tmp_ucs2_num;
#ifdef __MMI_MESSAGES_SMS_EMAIL__
        addr_type = SMS_ADDR_TYPE_NUMBER;
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
    }
#ifdef __MMI_MMS_STANDALONE_COMPOSER__
    mmi_sms_send_one_mms(
        ucs2_addr
    #if (MMI_MAX_SIM_NUM >= 2)
        , srv_sms_get_msg_sim_id(g_sms_cntx.curr_msg_id)
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        , addr_type
    #endif /* __MMI_MESSAGES_SMS_EMAIL__ */
        );
#else /* __MMI_MMS_STANDALONE_COMPOSER__ */
    mms_address_insert_hdlr((CHAR *)ucs2_addr);
#endif /* __MMI_MMS_STANDALONE_COMPOSER__ */
}
#endif /* defined(__MMI_MMS_IN_UM__) && !defined(__MMI_UNIFIED_COMPOSER__) */


#ifndef __MMI_SMS_CLASS0_MSG_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_class0_save_to_inbox_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static mmi_ret mmi_sms_class0_save_to_inbox_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_evt_sms_save_struct *event = (cui_evt_sms_save_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        //case EVT_ID_GROUP_ACTIVE:
        //case EVT_ID_GROUP_INACTIVE:
        //    break;

        case EVT_ID_GROUP_DEINIT:
            sms_save_to_inbox_gid = GRP_ID_INVALID;
            sms_save_to_inbox_parent_gid = GRP_ID_INVALID;
            break;

        case EVT_ID_CUI_SMS_SAVE:
            if (event->save_result)
            {
                g_msg_cntx.msg_class0_ind = MMI_FALSE;
                mmi_frm_scrn_close(g_sms_gid, SCR_ID_MSG_CLASS0_MSG);
                ReleaseEMSEditBuffer();
            }
            mmi_frm_scrn_close(g_sms_gid, SCR_ID_MSG_CLASS0_OPTION);

            cui_sms_save_close(sms_save_to_inbox_gid);
            mmi_frm_group_close(sms_save_to_inbox_parent_gid);
            break;

        case EVT_ID_CUI_SMS_SAVE_CANCEL:
            cui_sms_save_close(sms_save_to_inbox_gid);
            mmi_frm_group_close(sms_save_to_inbox_parent_gid);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_class0_opt_save_to_inbox
 * DESCRIPTION
 *  Class0 list option item: Save to inbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_class0_opt_save_to_inbox(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_get_class0_msg();
    result = CopyEMSViewToEditBuffer();

    /* copy view content to edit buffer maybe fail due to EMS LIB virtual pack fail */
    if (result != EMS_OK)
    {
        mmi_sms_display_popup_ext(
            STR_SMS_FAILURE_MSG_LEN_EXCEEDED,
            MMI_EVENT_FAILURE);
        mmi_frm_scrn_close(g_sms_gid, SCR_ID_MSG_CLASS0_OPTION);
        return;
    }

    sms_save_to_inbox_parent_gid = mmi_frm_group_create_ex(
        GRP_ID_ROOT,
        GRP_ID_AUTO_GEN,
        mmi_sms_class0_save_to_inbox_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    sms_save_to_inbox_gid = cui_sms_save_create(sms_save_to_inbox_parent_gid);

    if(sms_save_to_inbox_gid != GRP_ID_INVALID)
    {
        U16 addr_len;
        U16 ucs2_addr[SRV_SMS_MAX_ADDR_LEN + 1];
        
#ifndef __ULC_SLIM_EMS__
        if (g_sms_cntx.edit_ems_data->dcs == SMSAL_DEFAULT_DCS)
        {
            if (mmi_msg_ems_need_add_or_remove_escape_char(g_sms_cntx.edit_ems_data) == MMI_TRUE)
            {
                mmi_msg_ems_remove_escape_char(g_sms_cntx.edit_ems_data);
                mmi_msg_ems_add_escape_char(g_sms_cntx.edit_ems_data);
            }
        }

        cui_sms_set_save_content_ems(sms_save_to_inbox_gid, g_sms_cntx.edit_ems_data);
#else /* __ULC_SLIM_EMS__ */

        cui_sms_set_save_content_text(sms_save_to_inbox_gid, (U16*)g_sms_cntx.edit_ems_data->textBuffer, g_sms_cntx.edit_ems_data->textLength);

#endif /* __ULC_SLIM_EMS__ */


        cui_sms_set_save_msg_status(sms_save_to_inbox_gid, SRV_SMS_STATUS_READ);

        if (g_class0_sms_info.fo & 0x20)
        {
            cui_sms_set_save_status_report(sms_save_to_inbox_gid, MMI_TRUE);
        }
        if (g_class0_sms_info.fo & 0x80)
        {
            cui_sms_set_save_reply_path(sms_save_to_inbox_gid, MMI_TRUE);
        }
        cui_sms_set_save_timestamp(sms_save_to_inbox_gid, &(g_class0_sms_info.timestamp));

        addr_len = mmi_asc_n_to_ucs2((S8*)ucs2_addr, (S8*) g_class0_sms_info.number, SRV_SMS_MAX_ADDR_LEN);
        ucs2_addr[addr_len >> 1] = '\0';
        cui_sms_set_save_address(sms_save_to_inbox_gid, ucs2_addr);

        addr_len = mmi_asc_n_to_ucs2((S8*)ucs2_addr, (S8*) g_class0_sms_info.sc_addr, SRV_SMS_MAX_ADDR_LEN);
        ucs2_addr[addr_len >> 1] = '\0';
        cui_sms_set_save_sc_addr(sms_save_to_inbox_gid, ucs2_addr);

        cui_sms_set_save_title_id(sms_save_to_inbox_gid, STR_ID_SMS_SAVE_TO_INBOX);

    #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
             #if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
             #endif
             #if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
             #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
        cui_sms_save_run(sms_save_to_inbox_gid);
    }
    else
    {
        mmi_frm_group_close(sms_save_to_inbox_parent_gid);
    }
}
#endif

#ifdef __MMI_MESSAGE_SMS_HILITE_VIEWER__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_add_hilite_list_item
 * DESCRIPTION
 *  Add a hilite list item to hilite_cntx.hilite_item
 * PARAMETERS
 *  pEmsData: ems data for parse
 *  emsType : ems data type
 *  applibType : applib addr type
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_add_hilite_list_item(EMSData *pEmsData, EMS_HILITE_TYPE emsType, applib_addr_type_enum applibType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool is_stopped = KAL_FALSE;
    applib_address_node_struct *curr_addr_list = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (hilite_cntx.hilite_item[emsType].hilite_length == 0)
    {
        curr_addr_list = applib_get_exclusive_address_list_from_text_ext(
                                        applibType,
                                        mmi_sms_malloc,
                                        mmi_sms_free,
                                        mmi_sms_hilite_check_stop_func,
                                        APPLIB_INPUT_DATA_TYPE_UNICODE,
                                        (char *)(pEmsData->textBuffer + hilite_cntx.currBlockOffset),
                                        hilite_cntx.currBlockLength,
                                        &is_stopped);
        if (curr_addr_list != NULL)
        {
            applib_address_node_struct *pNode = curr_addr_list;

            if (emsType == EMS_HILITE_EMAIL_ADDR)
            {
                while (pNode && pNode->length > MMI_EMAIL_MAX_ADDR_LEN * 2)
                {
                    pNode = pNode->next;
                }
                if (!pNode)
                {
                    applib_free_address_list((applib_address_node_struct **)&curr_addr_list, mmi_sms_free);
                    return;
                }
            }
            if (emsType == EMS_HILITE_URL)
            {
                while (pNode && pNode->length > MMI_MSG_MAX_ADDRESS_LEN * 2)
                {
                    pNode = pNode->next;
                }
                if (!pNode)
                {
                    applib_free_address_list((applib_address_node_struct **)&curr_addr_list, mmi_sms_free);
                    return;
                }
            }
            if (hilite_cntx.isRollback == MMI_TRUE)
            {
                if (pNode->pos == 0)
                {
                    applib_free_address_list((applib_address_node_struct **)&curr_addr_list, mmi_sms_free);
                    return;
                }
                hilite_cntx.isRollback = MMI_FALSE;
            }
            if (hilite_cntx.currBlockLength == MMI_MSG_MAX_ALLOC_BUFF_LEN && 
                pNode->pos + pNode->length == MMI_MSG_MAX_ALLOC_BUFF_LEN &&
                (pNode->pos >= hilite_cntx.currBlockOffset + MMI_MSG_MAX_ALLOC_BUFF_LEN - MMI_MSG_MAX_ADDRESS_LEN * ENCODING_LENGTH) &&
                hilite_cntx.currBlockOffset + MMI_MSG_MAX_ALLOC_BUFF_LEN < pEmsData->textLength)
            {
                applib_free_address_list((applib_address_node_struct **)&curr_addr_list, mmi_sms_free);
                return;
            }
            hilite_cntx.hilite_item[emsType].offset_to_text = pNode->pos + hilite_cntx.currBlockOffset;
            hilite_cntx.hilite_item[emsType].hilite_length = pNode->length;

            applib_free_address_list((applib_address_node_struct **)&curr_addr_list, mmi_sms_free);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_parse_hilite_list
 * DESCRIPTION
 *  Parse hilite list item
 * PARAMETERS
 *  pEmsData: ems data for parse
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_parse_hilite_list(EMSData *pEmsData, MMI_BOOL isClass0)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSPosition     position;
    U16             addedItem = 0;
    EMS_HILITE_TYPE firstItemType = EMS_HILITE_NONE;
    U16             firstItemPos;
    U16             i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&hilite_cntx, 0, sizeof(hilite_cntx));

    /* first hilite list item for category */
    hilite_cntx.hilite_list[hilite_cntx.totalListItem].hilite_type = EMS_HILITE_NONE;
    hilite_cntx.hilite_list[hilite_cntx.totalListItem].object = NULL;
    hilite_cntx.hilite_list[hilite_cntx.totalListItem].offset_to_text = 0;
    hilite_cntx.hilite_list[hilite_cntx.totalListItem].hilite_length = 0;
    hilite_cntx.totalListItem++;

    position = pEmsData->CurrentPosition;
    mmi_msg_ems_remove_escape_char(pEmsData);

    while (mmi_sms_next_block(pEmsData, addedItem))
    {
        addedItem = 0;

    #ifdef __MMI_MESSAGES_USE_URL__
        /* URL */
        mmi_sms_add_hilite_list_item(pEmsData, EMS_HILITE_URL, APPLIB_ADDR_TYPE_URL);
        /*while (hilite_cntx.hilite_item[EMS_HILITE_URL].hilite_length > MMI_MSG_MAX_ADDRESS_LEN)
        {
            hilite_cntx.hilite_item[EMS_HILITE_URL].hilite_length = 0;
            hilite_cntx.hilite_item[EMS_HILITE_URL].offset_to_text = 0;
            mmi_sms_add_hilite_list_item(pEmsData, EMS_HILITE_URL, APPLIB_ADDR_TYPE_URL);
        }*/
    #endif /* __MMI_MESSAGES_USE_URL__ */
#if defined(__MMI_EMAIL__) || (defined(__MMI_PHB_OPTIONAL_FIELD__))
        /* EMAIL */
        mmi_sms_add_hilite_list_item(pEmsData, EMS_HILITE_EMAIL_ADDR, APPLIB_ADDR_TYPE_EMAIL);
        /*while (hilite_cntx.hilite_item[EMS_HILITE_EMAIL_ADDR].hilite_length > MMI_EMAIL_MAX_ADDR_LEN)
        {
            hilite_cntx.hilite_item[EMS_HILITE_EMAIL_ADDR].hilite_length = 0;
            hilite_cntx.hilite_item[EMS_HILITE_EMAIL_ADDR].offset_to_text = 0;
            mmi_sms_add_hilite_list_item(pEmsData, EMS_HILITE_EMAIL_ADDR, APPLIB_ADDR_TYPE_EMAIL);
        }*/
#endif /* defined(__MMI_EMAIL__) || (defined(__MMI_PHB_OPTIONAL_FIELD__)) */
        /* USSD */
        mmi_sms_add_hilite_list_item(pEmsData, EMS_HILITE_USSD, APPLIB_ADDR_TYPE_USSD);
        /* NUMBER */
        mmi_sms_add_hilite_list_item(pEmsData, EMS_HILITE_NUMBER, APPLIB_ADDR_TYPE_PHONENUMBER);

        firstItemPos = hilite_cntx.currBlockOffset + hilite_cntx.currBlockLength;
        firstItemType = EMS_HILITE_NONE;

        /* the block has text */
        if (hilite_cntx.currBlockLength != 0)
        {
            /* find the first find item */
            for (i = EMS_HILITE_URL; i <= EMS_HILITE_NUMBER; i++)
            {
                if (hilite_cntx.hilite_item[i].hilite_length != 0)
                {
                    if (firstItemPos > hilite_cntx.hilite_item[i].offset_to_text)
                    {
                        firstItemPos = hilite_cntx.hilite_item[i].offset_to_text;
                        firstItemType = (EMS_HILITE_TYPE)i;
                    }
                }
            }

            if (firstItemType != EMS_HILITE_NONE) /* exist hilite item */
            {
                hilite_cntx.hilite_list[hilite_cntx.totalListItem].offset_to_text = firstItemPos;
                hilite_cntx.hilite_list[hilite_cntx.totalListItem].hilite_length = hilite_cntx.hilite_item[firstItemType].hilite_length;
                hilite_cntx.hilite_list[hilite_cntx.totalListItem].hilite_type = firstItemType;
                hilite_cntx.hilite_list[hilite_cntx.totalListItem].object = hilite_cntx.lastObject;

                /* check other hilite item, if invalid, need reparse next time */
                for (i = EMS_HILITE_URL; i <= EMS_HILITE_NUMBER; i++)
                {
                    if (i == firstItemType)
                    {
                        hilite_cntx.hilite_item[i].hilite_length = 0;
                        hilite_cntx.hilite_item[i].offset_to_text = 0;
                    }
                    else if (hilite_cntx.hilite_item[i].hilite_length != 0)
                    {
                        if (hilite_cntx.hilite_item[i].offset_to_text < 
                            hilite_cntx.hilite_list[hilite_cntx.totalListItem].offset_to_text + hilite_cntx.hilite_list[hilite_cntx.totalListItem].hilite_length)
                        {
                            hilite_cntx.hilite_item[i].hilite_length = 0;
                            hilite_cntx.hilite_item[i].offset_to_text = 0;
                        }
                    }
                }

                addedItem = 1;

                /* current block remain length > MMI_MSG_MIN_HILITE_ITEM_LENGTH*/
/*                if ((hilite_cntx.currBlockOffset + hilite_cntx.currBlockLength) - 
                    (hilite_cntx.hilite_list[hilite_cntx.totalListItem].offset_to_text+ hilite_cntx.hilite_list[hilite_cntx.totalListItem].hilite_length)
                    > MMI_MSG_MIN_HILITE_ITEM_LENGTH)
                {
                    hilite_cntx.totalListItem++;
                    continue;
                }*/
                hilite_cntx.totalListItem++;
                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_PARSE_HILITE_LIST_1, firstItemType);
            }
        }


        /* check object */
        if (hilite_cntx.currBlockEndwithObject &&
            (hilite_cntx.totalListItem < (MMI_MSG_MAX_HILITE_NUMBER + 1)) &&
            (((hilite_cntx.hilite_list[hilite_cntx.totalListItem - 1].offset_to_text + hilite_cntx.hilite_list[hilite_cntx.totalListItem - 1].hilite_length == hilite_cntx.currBlockLength + hilite_cntx.currBlockOffset) &&
            addedItem == 1) ||
            addedItem == 0))
        {
            if ((hilite_cntx.hilite_list[hilite_cntx.totalListItem - 1].offset_to_text + hilite_cntx.hilite_list[hilite_cntx.totalListItem - 1].hilite_length == hilite_cntx.currBlockLength + hilite_cntx.currBlockOffset) &&
            addedItem == 1 || addedItem == 0)
            hilite_cntx.hilite_list[hilite_cntx.totalListItem].hilite_length = 0;
            hilite_cntx.hilite_list[hilite_cntx.totalListItem].hilite_type = EMS_HILITE_OBJECT;
            if (hilite_cntx.lastObject == NULL)
            {
                hilite_cntx.lastObject = pEmsData->listHead;
            }
            else
            {
                hilite_cntx.lastObject = hilite_cntx.lastObject->next;
            }
            /* ignore text format */
            while (hilite_cntx.lastObject && hilite_cntx.lastObject->Type == EMS_TYPE_TEXT_FORMAT)
            {
                hilite_cntx.lastObject = hilite_cntx.lastObject->next;
            }
            hilite_cntx.hilite_list[hilite_cntx.totalListItem].object = hilite_cntx.lastObject;
            hilite_cntx.hilite_list[hilite_cntx.totalListItem].offset_to_text = hilite_cntx.lastObject->OffsetToText;

            addedItem = 2;
            hilite_cntx.totalListItem++;
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_PARSE_HILITE_LIST_2);
        }
    }

    if (mmi_msg_ems_need_add_or_remove_escape_char(pEmsData) == MMI_TRUE &&
        srv_sms_check_ucs2((S8*)pEmsData->textBuffer, pEmsData->textLength / 2) == MMI_FALSE &&
        pEmsData->dcs == SMSAL_DEFAULT_DCS &&
        (!isClass0))
    {
        mmi_msg_ems_add_escape_char(pEmsData);
        MoveCursorToPosition(pEmsData, &position);

        if (hilite_cntx.totalListItem > 1)
        {
            mmi_sms_adjust_hilite_list_item_offset(pEmsData);
        }
    }

    /* last hilite list item for category */
    hilite_cntx.hilite_list[hilite_cntx.totalListItem].hilite_type = EMS_HILITE_NONE;
    hilite_cntx.hilite_list[hilite_cntx.totalListItem].object = NULL;
    hilite_cntx.hilite_list[hilite_cntx.totalListItem].offset_to_text = 0;
    hilite_cntx.hilite_list[hilite_cntx.totalListItem].hilite_length = 0;
    hilite_cntx.totalListItem++;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_PARSE_HILITE_LIST, hilite_cntx.totalListItem);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_next_block
 * DESCRIPTION
 *  Find next block for parse
 * PARAMETERS
 *  pEmsData: ems data for parse
 *  addNewHiliteItem: add new hilite list item of the last block, 
 *                    0: not add, 1: add non object item, 2: add object item
 * RETURNS
 *  BOOL: true for find new block
 *****************************************************************************/
static BOOL mmi_sms_next_block(EMSData *pEmsData, U16 addNewHiliteItem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSObject *pObject;
    /*U16 lastOffset = hilite_cntx.currBlockOffset;*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check whether next object at block's begining */
    if (hilite_cntx.lastObject == NULL)
    {
        pObject = pEmsData->listHead;
    }
    else
    {
        pObject = hilite_cntx.lastObject->next;
    }
    /* ignore text format */
    while (pObject && pObject->Type == EMS_TYPE_TEXT_FORMAT)
    {
        pObject = pObject->next;
    }
    if ((hilite_cntx.totalListItem >= MMI_MSG_MAX_HILITE_NUMBER + 1) ||
        (pEmsData->textLength == 0 ||
        ((addNewHiliteItem == 0) && (hilite_cntx.currBlockOffset + hilite_cntx.currBlockLength >= pEmsData->textLength)))
        && pObject == NULL) /* all ems buffer parsed */
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_HILITE_NEXT_BLOCK);
        return MMI_FALSE;
    }

    if (pObject && (pObject->OffsetToText == hilite_cntx.currBlockOffset))
    {
        hilite_cntx.currBlockEndwithObject = MMI_TRUE;
        hilite_cntx.currBlockLength = 0;
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_HILITE_NEXT_BLOCK_1);
        return MMI_TRUE;
    }

    /* add non object item last time */
    if (addNewHiliteItem == 1)
    {
        hilite_cntx.currBlockOffset = 
            hilite_cntx.hilite_list[hilite_cntx.totalListItem - 1].offset_to_text + 
            hilite_cntx.hilite_list[hilite_cntx.totalListItem - 1].hilite_length;
    }
    /* add object item last time */
    else if (addNewHiliteItem == 2 && hilite_cntx.lastObject)
    {
        /* ignore text format */
        pObject = hilite_cntx.lastObject->next;
        while (pObject && pObject->Type == EMS_TYPE_TEXT_FORMAT)
        {
            pObject = pObject->next;
        }

        /* check next object next to this one */
        if (pObject &&
            (pObject->OffsetToText == hilite_cntx.currBlockLength + hilite_cntx.currBlockOffset))
        {
            hilite_cntx.currBlockEndwithObject = MMI_TRUE;
            hilite_cntx.currBlockOffset = pObject->OffsetToText;
            hilite_cntx.currBlockLength = 0;
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_HILITE_NEXT_BLOCK_2);
            return MMI_TRUE;
        }

        hilite_cntx.currBlockOffset = hilite_cntx.currBlockLength + hilite_cntx.currBlockOffset;
    }
    /* not add any item last time */
    else
    {
        /* first text block*/
        if (hilite_cntx.currBlockLength == 0)
        {
            hilite_cntx.currBlockOffset = 0;
        }
        else
        {
            /* rollback */
            if (hilite_cntx.currBlockLength == MMI_MSG_MAX_ALLOC_BUFF_LEN)
            {
                hilite_cntx.currBlockOffset = hilite_cntx.currBlockOffset + 
                                              MMI_MSG_MAX_ALLOC_BUFF_LEN - 
                                              MMI_MSG_MAX_ADDRESS_LEN * ENCODING_LENGTH;
                hilite_cntx.isRollback = MMI_TRUE;
            }
            else
            {
                hilite_cntx.currBlockOffset += hilite_cntx.currBlockLength;
            }
        }
    }

    /* exist next object */
    if (hilite_cntx.lastObject == NULL && pEmsData->listHead ||
        hilite_cntx.lastObject != NULL && hilite_cntx.lastObject->next)
    {
        if (hilite_cntx.lastObject == NULL)
        {
            pObject = pEmsData->listHead;
        }
        else
        {
            pObject = hilite_cntx.lastObject->next;
        }

        /* ignore text format */
        while (pObject && pObject->Type == EMS_TYPE_TEXT_FORMAT)
        {
            pObject = pObject->next;
        }

        if (pObject)
        {
            if (pObject->OffsetToText - hilite_cntx.currBlockOffset > MMI_MSG_MAX_ALLOC_BUFF_LEN)
            {
                hilite_cntx.currBlockLength = MMI_MSG_MAX_ALLOC_BUFF_LEN;
            }
            else
            {
                hilite_cntx.currBlockLength = pObject->OffsetToText - hilite_cntx.currBlockOffset;
            }

            hilite_cntx.currBlockEndwithObject = MMI_TRUE;
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_HILITE_NEXT_BLOCK_2);
            return MMI_TRUE;
        }
    }

    if (pEmsData->textLength - hilite_cntx.currBlockOffset > MMI_MSG_MAX_ALLOC_BUFF_LEN)
    {
        hilite_cntx.currBlockLength = MMI_MSG_MAX_ALLOC_BUFF_LEN;
    }
    else
    {
        hilite_cntx.currBlockLength = pEmsData->textLength - hilite_cntx.currBlockOffset;
    }

    hilite_cntx.currBlockEndwithObject = MMI_FALSE;
 
    if (/*hilite_cntx.currBlockLength <= MMI_MSG_MIN_HILITE_ITEM_LENGTH && */
    /*    hilite_cntx.currBlockEndwithObject == MMI_FALSE && 
        lastOffset == hilite_cntx.currBlockOffset && 
        hilite_cntx.totalListItem > 1 ||*/
        hilite_cntx.currBlockOffset + hilite_cntx.currBlockLength > pEmsData->textLength)
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_HILITE_NEXT_BLOCK_3);
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_adjust_hilite_list_item_offset
 * DESCRIPTION
 *  Add hilite list item offset, that is add "0X1b"
 * PARAMETERS
 *  pEmsData: ems data for parse
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_adjust_hilite_list_item_offset(EMSData *pEmsData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 currExtChar = 0;
    U16 currTextChar = 0;
    U16 currHiliteListItem = 1;
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (currHiliteListItem < hilite_cntx.totalListItem)
    {
        if (currTextChar == hilite_cntx.hilite_list[currHiliteListItem].offset_to_text)
        {
            U16 item_offset = hilite_cntx.hilite_list[currHiliteListItem].offset_to_text;
            hilite_cntx.hilite_list[currHiliteListItem].offset_to_text += currExtChar;
            if (hilite_cntx.hilite_list[currHiliteListItem].hilite_length != 0)
            {
                while (currExtChar + currTextChar < pEmsData->textLength)
                {
                    if ((*(pEmsData->textBuffer + i)) == EMS_ESCAPE_CHARACTER)
                    {
                        currExtChar += 2;
                    }
                    else
                    {
                        currTextChar += 2;
                    }
                    i += 2;

                    if (currTextChar == 
                                item_offset + hilite_cntx.hilite_list[currHiliteListItem].hilite_length)
                    {
                        hilite_cntx.hilite_list[currHiliteListItem].hilite_length = 
                            currExtChar + currTextChar - hilite_cntx.hilite_list[currHiliteListItem].offset_to_text;
                        currHiliteListItem++;
                        break;
                    }
                }
                if (currExtChar + currTextChar == pEmsData->textLength)
                {
                    if (hilite_cntx.hilite_list[currHiliteListItem].hilite_length == 0)
                    {
                        hilite_cntx.hilite_list[currHiliteListItem].offset_to_text = pEmsData->textLength;
                    }
                    else
                    {
                        hilite_cntx.hilite_list[currHiliteListItem].hilite_length = 
                            pEmsData->textLength - hilite_cntx.hilite_list[currHiliteListItem].offset_to_text;
                    }
                    currHiliteListItem++;
                    break;
                }
            }
            else /* next hilite item is object */
            {
                currHiliteListItem++;

                if (hilite_cntx.hilite_list[currHiliteListItem].offset_to_text == currTextChar)
                {
                    continue;
                }

                while (*(pEmsData->textBuffer + i) == EMS_ESCAPE_CHARACTER)
                {
                    currExtChar += 2;
                    i += 2;
                }
                /*else
                {
                    currTextChar += 2;
                }
                i += 2;*/
            }
        }
        else
        {
            while (*(pEmsData->textBuffer + i) == EMS_ESCAPE_CHARACTER)
            {
                currExtChar += 2;
                i += 2;
            }
            currTextChar += 2;
            i += 2;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_hilite_check_stop_func
 * DESCRIPTION
 *  function to check the condition of stop extract hilite item
 * PARAMETERS
 *  p        [IN]        address to be free
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool mmi_sms_hilite_check_stop_func(applib_addr_type_enum type, applib_address_node_struct *addr, kal_uint32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == APPLIB_ADDR_TYPE_EMAIL && addr->length > MMI_EMAIL_MAX_ADDR_LEN * 2)
    {
        return KAL_FALSE;
    }
    if (type == APPLIB_ADDR_TYPE_URL && addr->length > MMI_MSG_MAX_ADDRESS_LEN * 2)
    {
        return KAL_FALSE;
    }
    if (num >= 1)
    {
        return KAL_TRUE;
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_view_hilite_cb
 * DESCRIPTION
 *  function for viewer hilite item callback
 * PARAMETERS
 *  idx        [IN]        index of hilite list
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_view_hilite_cb(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_VIEW_HILITE_CB, idx);
    hilite_cntx.currHiliteItemIndex = idx;
    /* FM_SEND_KEY */
    //SetKeyHandler(mmi_sms_viewer_set_sender_key_hdlr, KEY_SEND, KEY_EVENT_UP);
    SetKeyUpHandler(mmi_sms_viewer_set_sender_key_hdlr, KEY_SEND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_hilite_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_sms_viewer_hilite_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            {
                cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
                cui_menu_close(menu_evt->sender_id);
            }
            break;
            
        case EVT_ID_CUI_USE_DETAIL_RESULT:
        {
            cui_use_detail_result_event_struct *use_detail_evt = (cui_use_detail_result_event_struct *)evt;
            cui_use_detail_close(use_detail_evt->sender_id);
        }
            break;
    
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_view_hilite_opt_pre_entry_hdlr
 * DESCRIPTION
 *  function for viewer click hilite item callback
 * PARAMETERS
 *  idx        [IN]        index of hilite list
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_view_hilite_opt_pre_entry_hdlr(MMI_ID parent_gid,S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID mmi_sms_hilite_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_VIEW_HILITE_CLICK_CB, idx);

    hilite_cntx.currHiliteItemIndex = idx;
    switch (hilite_cntx.hilite_list[idx].hilite_type)
    {
        case EMS_HILITE_NUMBER:
        case EMS_HILITE_EMAIL_ADDR:
        case EMS_HILITE_URL:
        case EMS_HILITE_USSD:
            break;
        default:
            return;
    }
    mmi_sms_hilite_gid = mmi_frm_group_create_ex(
        parent_gid,
        GRP_ID_AUTO_GEN,
        mmi_sms_viewer_hilite_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    mmi_sms_use_detail_hilite_info(mmi_sms_hilite_gid, idx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_use_detail_hilite_info
 * DESCRIPTION
 *  "Use Detail CUI" is used in USSD
 * PARAMETERS
 *  idx     [IN] hilite index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_use_detail_hilite_info(MMI_ID parent_gid, S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U16 valid_ucs2_number[CUI_USE_DETAIL_MAX_LEN + 1];
    cui_use_detail_basic_obj_struct obj_list;
    MMI_ID use_detail_gid;
    EMSData *ems_view = NULL;
    S32 len;
     U16 char_num;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ems_view = GetEMSDataForView(NULL, 0);
    len = hilite_cntx.hilite_list[idx].hilite_length / ENCODING_LENGTH;
    if (len > CUI_USE_DETAIL_MAX_LEN)
    {
        len = CUI_USE_DETAIL_MAX_LEN;
    }
	if (EMS_HILITE_NUMBER == hilite_cntx.hilite_list[idx].hilite_type)
	{
		mmi_sms_validate_number(
			(S8*)(ems_view->textBuffer + hilite_cntx.hilite_list[idx].offset_to_text), 
			(S8*)valid_ucs2_number,
			len);
	}
	else
	{
		mmi_ucs2ncpy((CHAR*)valid_ucs2_number,
					(CHAR*)(ems_view->textBuffer + hilite_cntx.hilite_list[idx].offset_to_text),
					len);
	}
    
    //srv_sms_remove_escape_char();
    char_num = (U16)mmi_ucs2strlen((S8*)valid_ucs2_number);
    srv_sms_remove_escape_char((S8*)valid_ucs2_number, (S8*)valid_ucs2_number, char_num);
    
    obj_list.detail_txt = valid_ucs2_number;
    obj_list.txtlen = mmi_ucs2strlen((const CHAR*)valid_ucs2_number);

    switch (hilite_cntx.hilite_list[idx].hilite_type)
    {
        case EMS_HILITE_NUMBER:
            obj_list.type = CUI_USE_DETAIL_TYPE_PHONENUMBER;
            break;
        case EMS_HILITE_EMAIL_ADDR:
            obj_list.type = CUI_USE_DETAIL_TYPE_EMAIL;
            break;
        case EMS_HILITE_URL:
            obj_list.type = CUI_USE_DETAIL_TYPE_URL;
            break;
        case EMS_HILITE_USSD:
            obj_list.type = CUI_USE_DETAIL_TYPE_USSD;
            break;
        default:
            return;
    }
    
    use_detail_gid = cui_use_detail_create(parent_gid, &obj_list, 1, NULL);
    cui_use_detail_run(use_detail_gid);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_view_hilite_click_cb
 * DESCRIPTION
 *  function for viewer click hilite item callback
 * PARAMETERS
 *  idx        [IN]        index of hilite list
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_view_hilite_click_cb(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_view_hilite_opt_pre_entry_hdlr(g_sms_gid, idx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_check_hilite_item_opt
 * DESCRIPTION
 *  function for check viewer option for hilite item operation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_check_hilite_item_opt(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMS_HILITE_TYPE hilite_type;
    MMI_ID cui_menu_gid = menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hilite_type = hilite_cntx.hilite_list[hilite_cntx.currHiliteItemIndex].hilite_type;
	cui_menu_set_non_leaf_item(cui_menu_gid, MENU_ID_SMS_USE_NUMBER_OPT, MMI_FALSE);
#if defined(__MMI_EMAIL__)
	cui_menu_set_non_leaf_item(cui_menu_gid, MENU_ID_SMS_USE_EMAIL_OPT, MMI_FALSE);
#elif (defined(__MMI_PHB_OPTIONAL_FIELD__))
	cui_menu_set_non_leaf_item(cui_menu_gid, MENU_ID_SMS_USE_EMAIL_OPT_SAVE_TO_EMAIL, MMI_FALSE);
#endif /* __MMI_EMAIL__ */
#ifdef __MMI_MESSAGES_USE_URL__
	cui_menu_set_non_leaf_item(cui_menu_gid, MENU_ID_SMS_USE_URL_OPT, MMI_FALSE);
#endif /* __MMI_MESSAGES_USE_URL__ */
	cui_menu_set_non_leaf_item(cui_menu_gid, MENU_ID_SMS_SEND_USSD_OPT, MMI_FALSE);

    if ((srv_sms_is_highlight_view_setting() == MMI_TRUE) &&
        (hilite_cntx.isParsed == MMI_TRUE))
    {
        switch (hilite_type)
        {
        case EMS_HILITE_NUMBER:
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_USE_NUMBER_OPT, MMI_FALSE);
            #if defined(__MMI_EMAIL__)
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_USE_EMAIL_OPT, MMI_TRUE);
            #elif (defined(__MMI_PHB_OPTIONAL_FIELD__))
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_USE_EMAIL_OPT_SAVE_TO_EMAIL, MMI_TRUE);
            #endif /* __MMI_EMAIL__ */
            #ifdef __MMI_MESSAGES_USE_URL__
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_USE_URL_OPT, MMI_TRUE);
            #endif /* __MMI_MESSAGES_USE_URL__ */
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_SEND_USSD_OPT, MMI_TRUE);
            #ifdef __MMI_SMS_APP_EMS_SUPPORT__
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_SAVE_OBJECTS_OPT, MMI_TRUE);
            #endif
            break;

#if defined(__MMI_EMAIL__) || (defined(__MMI_PHB_OPTIONAL_FIELD__))
        case EMS_HILITE_EMAIL_ADDR:
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_USE_NUMBER_OPT, MMI_TRUE);
            #if defined(__MMI_EMAIL__)
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_USE_EMAIL_OPT, MMI_FALSE);
            #elif (defined(__MMI_PHB_OPTIONAL_FIELD__))
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_USE_EMAIL_OPT_SAVE_TO_EMAIL, MMI_FALSE);
            #endif /* __MMI_EMAIL__ */
            #ifdef __MMI_MESSAGES_USE_URL__
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_USE_URL_OPT, MMI_TRUE);
            #endif /* __MMI_MESSAGES_USE_URL__ */
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_SEND_USSD_OPT, MMI_TRUE);
            #ifdef __MMI_SMS_APP_EMS_SUPPORT__
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_SAVE_OBJECTS_OPT, MMI_TRUE);
            #endif
            break;
#endif /* defined(__MMI_EMAIL__) || (defined(__MMI_PHB_OPTIONAL_FIELD__)) */

#ifdef __MMI_MESSAGES_USE_URL__
        case EMS_HILITE_URL:
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_USE_NUMBER_OPT, MMI_TRUE);
            #if defined(__MMI_EMAIL__)
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_USE_EMAIL_OPT, MMI_TRUE);
            #elif (defined(__MMI_PHB_OPTIONAL_FIELD__))
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_USE_EMAIL_OPT_SAVE_TO_EMAIL, MMI_TRUE);
            #endif /* __MMI_EMAIL__ */
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_USE_URL_OPT, MMI_FALSE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_SEND_USSD_OPT, MMI_TRUE);
            #ifdef __MMI_SMS_APP_EMS_SUPPORT__
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_SAVE_OBJECTS_OPT, MMI_TRUE);
            #endif
            break;
#endif /* __MMI_MESSAGES_USE_URL__ */

        case EMS_HILITE_USSD:
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_USE_NUMBER_OPT, MMI_TRUE);
            #if defined(__MMI_EMAIL__)
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_USE_EMAIL_OPT, MMI_TRUE);
            #elif (defined(__MMI_PHB_OPTIONAL_FIELD__))
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_USE_EMAIL_OPT_SAVE_TO_EMAIL, MMI_TRUE);
            #endif /* __MMI_EMAIL__ */
            #ifdef __MMI_MESSAGES_USE_URL__
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_USE_URL_OPT, MMI_TRUE);
            #endif /* __MMI_MESSAGES_USE_URL__ */
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_SEND_USSD_OPT, MMI_FALSE);
            #ifdef __MMI_SMS_APP_EMS_SUPPORT__
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_SAVE_OBJECTS_OPT, MMI_TRUE);
            #endif
            break;

        case EMS_HILITE_OBJECT:
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_USE_NUMBER_OPT, MMI_TRUE);
            #if defined(__MMI_EMAIL__)
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_USE_EMAIL_OPT, MMI_TRUE);
            #elif (defined(__MMI_PHB_OPTIONAL_FIELD__))
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_USE_EMAIL_OPT_SAVE_TO_EMAIL, MMI_TRUE);
            #endif /* __MMI_EMAIL__ */
            #ifdef __MMI_MESSAGES_USE_URL__
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_USE_URL_OPT, MMI_TRUE);
            #endif /* __MMI_MESSAGES_USE_URL__ */
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_SEND_USSD_OPT, MMI_TRUE);
    #ifdef __MMI_SMS_APP_EMS_SUPPORT__
            if (hilite_cntx.hilite_list[hilite_cntx.currHiliteItemIndex].object->Type == EMS_TYPE_PREDEF_SND ||
                hilite_cntx.hilite_list[hilite_cntx.currHiliteItemIndex].object->Type == EMS_TYPE_PREDEF_ANM)
            {
                cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_SAVE_OBJECTS_OPT, MMI_TRUE);
            }
            else
            {
                cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_SAVE_OBJECTS_OPT, MMI_FALSE);
            }
    #endif /* __MMI_SMS_APP_EMS_SUPPORT__ */
            break;

        case EMS_HILITE_NONE:
        default:
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_USE_NUMBER_OPT, MMI_TRUE);
            #if defined(__MMI_EMAIL__)
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_USE_EMAIL_OPT, MMI_TRUE);
            #elif (defined(__MMI_PHB_OPTIONAL_FIELD__))
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_USE_EMAIL_OPT_SAVE_TO_EMAIL, MMI_TRUE);
            #endif /* __MMI_EMAIL__ */
            #ifdef __MMI_MESSAGES_USE_URL__
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_USE_URL_OPT, MMI_TRUE);
            #endif /* __MMI_MESSAGES_USE_URL__ */
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_SEND_USSD_OPT, MMI_TRUE);
            #ifdef __MMI_SMS_APP_EMS_SUPPORT__
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_SAVE_OBJECTS_OPT, MMI_TRUE);
            #endif
            break;
        }
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_USE_NUMBER_OPT, MMI_TRUE);
        #if defined(__MMI_EMAIL__)
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_USE_EMAIL_OPT, MMI_TRUE);
        #elif (defined(__MMI_PHB_OPTIONAL_FIELD__))
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_USE_EMAIL_OPT_SAVE_TO_EMAIL, MMI_TRUE);
        #endif /* __MMI_EMAIL__ */
        #ifdef __MMI_MESSAGES_USE_URL__
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_USE_URL_OPT, MMI_TRUE);
        #endif /* __MMI_MESSAGES_USE_URL__ */
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_SEND_USSD_OPT, MMI_TRUE);
        #ifdef __MMI_SMS_APP_EMS_SUPPORT__
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_SAVE_OBJECTS_OPT, MMI_TRUE);
        #endif
    }
}
#endif /* __MMI_MESSAGE_SMS_HILITE_VIEWER__ */



/*****************************************************************************
 * FUNCTION
 *  DeInitMessagesEMSBuffer
 * DESCRIPTION
 *  Releaset EMS buffer
 * PARAMETERS
 *  pE      [IN]        
 * RETURNS
 *  EMS buffer valid flag
 *****************************************************************************/
void DeInitMessagesEMSBuffer(EMSData *p)
{
#ifdef __MMI_TELEPHONY_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSTATUS retVal;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p)
    {
        retVal = ReleaseEMSData(p);
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_FRM_DEINIT_MESSAGES_EMS_BUFFER, retVal);
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  GetEMSDataForView
 * DESCRIPTION
 *  Get EMS view buffer
 * PARAMETERS
 *  p           [IN]        EMS data pointer
 *  force       [IN]        Force to clear
 * RETURNS
 *  EMS buffer for display
 *****************************************************************************/
EMSData *GetEMSDataForView(EMSData **p, U8 force)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_TELEPHONY_SUPPORT__
    if (g_sms_cntx.view_ems_data == NULL)
    {
        g_sms_cntx.view_ems_data = srv_sms_malloc_ems_data();
    }

    if (force)
    {
        srv_sms_reset_ems_data((void*)g_sms_cntx.view_ems_data);
    }

    if (p)
    {
        *p = g_sms_cntx.view_ems_data;
    }
    return g_sms_cntx.view_ems_data;
    #else
    return NULL;
    #endif
}



/*****************************************************************************
 * FUNCTION
 *  GetEMSDataForEdit
 * DESCRIPTION
 *  Get EMS edit buffer
 * PARAMETERS
 *  p           [IN]        EMS data pointer
 *  force       [IN]        Force to clear
 * RETURNS
 *  EMS buffer for edit
 *****************************************************************************/
EMSData *GetEMSDataForEdit(EMSData **p, U8 force)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_TELEPHONY_SUPPORT__
    if (g_sms_cntx.edit_ems_data == NULL)
    {
        g_sms_cntx.edit_ems_data = srv_sms_malloc_ems_data();
    }
    
    if (force)
    {
        srv_sms_reset_ems_data((void*)g_sms_cntx.edit_ems_data);
    }

    if (p)
    {
        *p = g_sms_cntx.edit_ems_data;
    }

    return g_sms_cntx.edit_ems_data;
    #elif defined(__MMI_BT_MAP_CLIENT__)
    EMSTATUS result;
    
    if (g_sms_cntx.edit_ems_data == NULL)
    {
        g_sms_cntx.edit_ems_data = OslMalloc(sizeof(EMSData));
        memset(g_sms_cntx.edit_ems_data, 0, sizeof(EMSData));
        if (g_sms_cntx.edit_ems_data->textBuffer == NULL)
        {
            g_sms_cntx.edit_ems_data->textBuffer = OslMalloc(SRV_SMS_BTMAPC_DISPLAY_BUFFER_SIZE);
            memset(g_sms_cntx.edit_ems_data->textBuffer, 0, SRV_SMS_BTMAPC_DISPLAY_BUFFER_SIZE);
            g_sms_cntx.edit_ems_data->textBufferSize = SRV_SMS_BTMAPC_DISPLAY_CHAR_SIZE * ENCODING_LENGTH;
        }
        
    }
    if (p)
    {
        *p = g_sms_cntx.edit_ems_data;
    }
    return g_sms_cntx.edit_ems_data;
    #else
    return NULL;
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  CopyEMSViewToEditBuffer
 * DESCRIPTION
 *  Copy EMS view buffer to edit buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 CopyEMSViewToEditBuffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = EMS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TELEPHONY_SUPPORT__
    if(g_sms_cntx.edit_ems_data == NULL)
    {
        g_sms_cntx.edit_ems_data = (EMSData*)srv_sms_malloc_ems_data();
    }
    else
    {
        srv_sms_reset_ems_data((void*)g_sms_cntx.edit_ems_data);
    }

    if (g_sms_cntx.view_ems_data != NULL)
    {
#ifndef __ULC_SLIM_EMS__
        result = CopyEMSData(g_sms_cntx.edit_ems_data, g_sms_cntx.view_ems_data);
#else /* __ULC_SLIM_EMS__ */
        memcpy(g_sms_cntx.edit_ems_data->textBuffer, g_sms_cntx.view_ems_data->textBuffer, g_sms_cntx.view_ems_data->textBufferSize);
        g_sms_cntx.edit_ems_data->textLength = g_sms_cntx.view_ems_data->textLength;

#endif /* __ULC_SLIM_EMS__ */
        if (result == EMS_OK)
        {
            EMSResetPortNum(g_sms_cntx.edit_ems_data);
        #ifndef __ULC_SLIM_EMS__
            GoToEndPosition(g_sms_cntx.edit_ems_data);
        #endif /* __ULC_SLIM_EMS__ */
        }
        else
        {
            srv_sms_reset_ems_data((void*)g_sms_cntx.edit_ems_data); /* because validFlag for edit buffer is 1, it is equivalent to force to realease */
        }
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_FRM_COPY_EMS_VIEW_TO_EDIT_BUFFER);
    }
#endif
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  ReleaseEMSViewBuffer
 * DESCRIPTION
 *  Release EMS view buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ReleaseEMSViewBuffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_TELEPHONY_SUPPORT__
    srv_sms_free_ems_data(g_sms_cntx.view_ems_data);
    #else
    if (g_sms_cntx.view_ems_data != NULL)
        OslMfree(g_sms_cntx.view_ems_data);
    #endif
    g_sms_cntx.view_ems_data = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  ReleaseEMSEditBuffer
 * DESCRIPTION
 *  Release EMS edit buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ReleaseEMSEditBuffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_TELEPHONY_SUPPORT__
    srv_sms_free_ems_data(g_sms_cntx.edit_ems_data);
    #else
    
    if (g_sms_cntx.edit_ems_data != NULL)
    {
        if (g_sms_cntx.edit_ems_data->textBuffer != NULL)
        {
            OslMfree(g_sms_cntx.edit_ems_data->textBuffer);
        }
        g_sms_cntx.edit_ems_data->textBuffer = NULL;
        OslMfree(g_sms_cntx.edit_ems_data);
        g_sms_cntx.edit_ems_data = NULL;
    }
    #endif
    g_sms_cntx.edit_ems_data = NULL;
}

#ifdef __MMI_TELEPHONY_SUPPORT__

#ifdef __MMI_ICON_BAR_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_set_toolbar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_set_toolbar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 item_icon[MMI_SMS_VIEWER_FTE_TOOLBAR_NUM] = {NULL, NULL, NULL};
    PU8 item_disable_icon[MMI_SMS_VIEWER_FTE_TOOLBAR_NUM]= {NULL, NULL, NULL};
    PU8 hint_string[MMI_SMS_VIEWER_FTE_TOOLBAR_NUM]= {NULL, NULL, NULL};
    U8 toolbar_setup_num = MMI_SMS_VIEWER_FTE_TOOLBAR_NUM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_sms_cntx.curr_box_type)
    {
        case SRV_SMS_BOX_INBOX:
            item_icon[0] = get_image(IMG_GLOBAL_TOOLBAR_REPLY_MESSAGE);
            item_icon[1] = get_image(IMG_GLOBAL_TOOLBAR_FORWARD_MESSAGE);
            item_icon[2] = get_image(IMG_GLOBAL_TOOLBAR_DELETE);
            item_disable_icon[0] = get_image(IMG_GLOBAL_TOOLBAR_REPLY_MESSAGE_DISABLED);
            item_disable_icon[1] = get_image(IMG_GLOBAL_TOOLBAR_FORWARD_MESSAGE_DISABLED);
            item_disable_icon[2] = get_image(IMG_GLOBAL_TOOLBAR_DELETE_DISABLED);
            hint_string[0] = (U8 *)GetString(STR_GLOBAL_REPLY);
            hint_string[1] = (U8 *)GetString(STR_GLOBAL_FORWARD);
            hint_string[2] = (U8 *)GetString(STR_GLOBAL_DELETE);
            break;
            
        /* OUTBOX */
    #if (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__))
        case SRV_SMS_BOX_UNSENT:/* background send */
            item_icon[0] = get_image(IMG_GLOBAL_TOOLBAR_SEND_MESSAGE);/*Resend*/
            item_icon[1] = get_image(IMG_GLOBAL_TOOLBAR_EDIT);
            item_icon[2] = get_image(IMG_GLOBAL_TOOLBAR_DELETE);
            item_disable_icon[0] = get_image(IMG_GLOBAL_TOOLBAR_SEND_MESSAGE_DISABLED);
            item_disable_icon[1] = get_image(IMG_GLOBAL_TOOLBAR_EDIT_DISABLED);
            item_disable_icon[2] = get_image(IMG_GLOBAL_TOOLBAR_DELETE_DISABLED);
            hint_string[0] = (U8 *)GetString(STR_GLOBAL_RESEND);
            hint_string[1] = (U8 *)GetString(STR_GLOBAL_EDIT);
            hint_string[2] = (U8 *)GetString(STR_GLOBAL_DELETE);            
            break;
    #endif /* #if (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__)) */
        
        case SRV_SMS_BOX_DRAFTS:
            item_icon[0] = get_image(IMG_GLOBAL_TOOLBAR_SEND_MESSAGE);
            item_icon[1] = get_image(IMG_GLOBAL_TOOLBAR_EDIT);
            item_icon[2] = get_image(IMG_GLOBAL_TOOLBAR_DELETE);
            item_disable_icon[0] = get_image(IMG_GLOBAL_TOOLBAR_SEND_MESSAGE_DISABLED);
            item_disable_icon[1] = get_image(IMG_GLOBAL_TOOLBAR_EDIT_DISABLED);
            item_disable_icon[2] = get_image(IMG_GLOBAL_TOOLBAR_DELETE_DISABLED);
            hint_string[0] = (U8 *)GetString(STR_GLOBAL_SEND);
            hint_string[1] = (U8 *)GetString(STR_GLOBAL_EDIT);
            hint_string[2] = (U8 *)GetString(STR_GLOBAL_DELETE);      
            break;

        /* SENT MESSAGE BOX */
        case SRV_SMS_BOX_OUTBOX: 
            item_icon[0] = get_image(IMG_GLOBAL_TOOLBAR_FORWARD_MESSAGE);
            item_icon[1] = get_image(IMG_GLOBAL_TOOLBAR_DELETE);
            item_disable_icon[0] = get_image(IMG_GLOBAL_TOOLBAR_REPLY_MESSAGE_DISABLED);
            item_disable_icon[1] = get_image(IMG_GLOBAL_TOOLBAR_DELETE_DISABLED);
            hint_string[0] = (U8 *)GetString(STR_GLOBAL_FORWARD);
            hint_string[1] = (U8 *)GetString(STR_GLOBAL_DELETE);      
            toolbar_setup_num = MMI_SMS_VIEWER_FTE_TOOLBAR_NUM - 1;
            break;

    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case SRV_SMS_BOX_SIM:
            item_icon[0] = get_image(IMG_SMS_TOOLBAR_COPY);
            item_icon[1] = get_image(IMG_SMS_TOOLBAR_MOVE);
            item_icon[2] = get_image(IMG_GLOBAL_TOOLBAR_DELETE);
            item_disable_icon[0] = get_image(IMG_SMS_TOOLBAR_COPY_DISABLE);
            item_disable_icon[1] = get_image(IMG_SMS_TOOLBAR_MOVE_DISABLE);
            item_disable_icon[2] = get_image(IMG_GLOBAL_TOOLBAR_DELETE_DISABLED); 
            hint_string[0] = (U8 *)GetString(STR_GLOBAL_COPY);
            hint_string[1] = (U8 *)GetString(STR_GLOBAL_MOVE); 
            hint_string[2] = (U8 *)GetString(STR_GLOBAL_DELETE); 
            break;
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case SRV_SMS_BOX_ARCHIVE: 
            item_icon[0] = get_image(IMG_GLOBAL_TOOLBAR_REPLY_MESSAGE);
            item_icon[1] = get_image(IMG_GLOBAL_TOOLBAR_FORWARD_MESSAGE);
            item_icon[2] = get_image(IMG_GLOBAL_TOOLBAR_DELETE);
            item_disable_icon[0] = get_image(IMG_GLOBAL_TOOLBAR_REPLY_MESSAGE_DISABLED);
            item_disable_icon[1] = get_image(IMG_GLOBAL_TOOLBAR_FORWARD_MESSAGE_DISABLED);
            item_disable_icon[2] = get_image(IMG_GLOBAL_TOOLBAR_DELETE_DISABLED);
            hint_string[0] = (U8 *)GetString(STR_GLOBAL_REPLY);
            hint_string[1] = (U8 *)GetString(STR_GLOBAL_FORWARD); 
            hint_string[2] = (U8 *)GetString(STR_GLOBAL_DELETE); 
            break;
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

        default:
            break;
        }/* end switch */

    wgui_icon_bar_setup(toolbar_setup_num, 
        item_icon, 
        item_disable_icon, 
        hint_string, 
        (GUIIconbarItemCallback)mmi_sms_viewer_set_toolbar_callback);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_set_toolbar_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_set_toolbar_callback(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_sms_cntx.curr_box_type)
    {
        case SRV_SMS_BOX_INBOX:
            if (index == 0)
            {
                mmi_sms_viewer_opt_reply();
            }
            else if (index == 1)
            {
                mmi_sms_viewer_opt_forward();
            }
            else if (index == 2)
            {
                mmi_sms_viewer_toolbar_delete();
            }
            break;
            
        case SRV_SMS_BOX_OUTBOX:
            if (index == 0)
            {
                mmi_sms_viewer_opt_forward();
            }
            else if (index == 1)
            {
                mmi_sms_viewer_toolbar_delete();
            }
            break;
            
        case SRV_SMS_BOX_DRAFTS:
            if (index == 0)
            {
                mmi_sms_viewer_opt_send();
            }
            else if (index == 1)
            {
                mmi_sms_viewer_opt_edit();
            }
            else if (index == 2)
            {
                mmi_sms_viewer_toolbar_delete();
            }
            break;
            
    #if (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__))    
        case SRV_SMS_BOX_UNSENT:
            if (index == 0)
            {
                mmi_sms_viewer_opt_resend();
            }
            else if (index == 1)
            {
                mmi_sms_viewer_opt_edit();
            }
            else if (index == 2)
            {
                mmi_sms_viewer_toolbar_delete();
            }            
            break;
    #endif /* (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__)) */

    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case SRV_SMS_BOX_SIM:
            /* FTE review:Should establish a dependency with FTE & (!EMAIL)&& FTE */
            if (index == 0)
            {
                mmi_sms_viewer_toolbar_copy_to_phone();
            }
            else if (index == 1)
            {
                mmi_sms_viewer_toolbar_move_to_phone();
            }
            else if (index == 2)
            {
                mmi_sms_viewer_toolbar_delete();
            }   
            break;
      #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */ 
      
      #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__      
        case SRV_SMS_BOX_ARCHIVE:
            if (index == 0)
            {
                mmi_sms_viewer_opt_reply();
            }
            else if (index == 1)
            {
                mmi_sms_viewer_opt_forward();
            }
            else if (index == 2)
            {
                mmi_sms_viewer_toolbar_delete();
            }            
            break;    
      #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */     
      
        default:
            break;        
    }
}


/*FM_FTE_NEW*/
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_toolbar_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_toolbar_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_entry_confirm(
        g_sms_gid,
        STR_GLOBAL_DELETE_ASK,
        mmi_sms_viewer_opt_delete,
        mmi_frm_scrn_close_active_id,
        MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_update_toolbar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_update_toolbar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_sms_cntx.curr_box_type)
    {
        case SRV_SMS_BOX_INBOX:
            if (mmi_sms_check_is_valid_oa_addr(g_sms_cntx.curr_msg_id) == MMI_TRUE)
            {
                wgui_icon_bar_set_item_enable_state(0, MMI_TRUE);
            }
            else
            {
                wgui_icon_bar_set_item_enable_state(0, MMI_FALSE);
            }
            if (g_sms_cntx.curr_msg_status == SMS_STATUS_UNSUPPORT)
            {
                wgui_icon_bar_set_item_enable_state(1, MMI_FALSE);
            }
            else
            {
                wgui_icon_bar_set_item_enable_state(1, MMI_TRUE);
            }
            break;
            
        case SRV_SMS_BOX_OUTBOX:
            if (g_sms_cntx.curr_msg_status == SMS_STATUS_UNSUPPORT)
            {
                wgui_icon_bar_set_item_enable_state(0, MMI_FALSE);
            }
            else
            {
                wgui_icon_bar_set_item_enable_state(0, MMI_TRUE);
            }  
            break;
            
        case SRV_SMS_BOX_DRAFTS:
            if (g_sms_cntx.curr_msg_status == SMS_STATUS_UNSUPPORT)
            {
                wgui_icon_bar_set_item_enable_state(0, MMI_FALSE);
                wgui_icon_bar_set_item_enable_state(1, MMI_FALSE);
            }
            else
            {
                wgui_icon_bar_set_item_enable_state(0, MMI_TRUE);
                wgui_icon_bar_set_item_enable_state(1, MMI_TRUE);
            }
            if(srv_nw_usab_get_one_usable_sim() == MMI_SIM_NONE)
            {
                wgui_icon_bar_set_item_enable_state(0, MMI_FALSE);
            }
        #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
            wgui_icon_bar_set_item_enable_state(0, MMI_FALSE);
        #endif
            break;
            
    #if (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__))    
        case SRV_SMS_BOX_UNSENT:
            if (g_sms_cntx.curr_msg_status == SMS_STATUS_UNSUPPORT)
            {
                wgui_icon_bar_set_item_enable_state(0, MMI_FALSE);
                wgui_icon_bar_set_item_enable_state(1, MMI_FALSE);
            }
            else
            {
                wgui_icon_bar_set_item_enable_state(0, MMI_TRUE);
                wgui_icon_bar_set_item_enable_state(1, MMI_TRUE);
            }
            if (srv_nw_usab_get_one_usable_sim() == MMI_SIM_NONE)
            {
                wgui_icon_bar_set_item_enable_state(0, MMI_FALSE);
            }
        #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
            wgui_icon_bar_set_item_enable_state(1, MMI_FALSE);
        #endif
            break;
    #endif /* (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__)) */

    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case SRV_SMS_BOX_SIM:
            /* FTE review:Should establish a dependency with FTE & (!EMAIL)&& FTE */
            wgui_icon_bar_set_item_enable_state(0, MMI_TRUE);
            wgui_icon_bar_set_item_enable_state(1, MMI_TRUE);
            break;
      #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */ 
      
      #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__      
        case SRV_SMS_BOX_ARCHIVE:
            if (g_sms_cntx.curr_msg_status == SMS_STATUS_UNSUPPORT)
            {
                wgui_icon_bar_set_item_enable_state(0, MMI_FALSE);
                wgui_icon_bar_set_item_enable_state(1, MMI_FALSE);
            }
            if (g_sms_cntx.curr_msg_status == SMS_STATUS_SENT)
            {
                wgui_icon_bar_set_item_enable_state(0, MMI_FALSE);
                wgui_icon_bar_set_item_enable_state(1, MMI_TRUE);
            }
            else
            {   
                if (mmi_sms_check_is_valid_oa_addr(g_sms_cntx.curr_msg_id) == MMI_TRUE)
                {
                    wgui_icon_bar_set_item_enable_state(0, MMI_TRUE);
                }
                else
                {
                    wgui_icon_bar_set_item_enable_state(0, MMI_FALSE);
                }
                wgui_icon_bar_set_item_enable_state(1, MMI_TRUE);
            }            
            break;    
      #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */     
      
        default:
            break;        
    }
    wgui_icon_bar_set_item_enable_state(2, MMI_TRUE);/* Delete icon setting */
}


#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_toolbar_copy_to_phone
 * DESCRIPTION
 *  Highlight viewer copy toolbar handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_toolbar_copy_to_phone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_copy_msg(
        g_sms_cntx.curr_msg_id,
        SRV_SMS_STORAGE_ME,
        mmi_sms_viewer_toolbar_copy_to_phone_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_toolbar_copy_to_phone
 * DESCRIPTION
 *  Highlight viewer advanced option: move handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_toolbar_move_to_phone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_move_msg(
        g_sms_cntx.curr_msg_id,
        SRV_SMS_STORAGE_ME,
        mmi_sms_viewer_toolbar_move_to_phone_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_toolbar_copy_to_phone_callback
 * DESCRIPTION
 *  Delete callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_toolbar_copy_to_phone_callback(mmi_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__) && defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__))
    mmi_msg_update_unsent_icon();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_toolbar_move_to_phone_callback
 * DESCRIPTION
 *  Delete callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_toolbar_move_to_phone_callback(mmi_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_viewer_adv_opt_action_move_callback(result, data);
}


#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__*/

#endif /* __MMI_ICON_BAR_SUPPORT__ */

#endif /* __MMI_TELEPHONY_SUPPORT__ */

/*FM_ITER*/
#ifdef __MMI_UM_ITERATOR_VIEWER__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_iter_viewer_prev_launch
 * DESCRIPTION
 *  For other application to lanch SMS viewer screen at iterator viewer.
 * PARAMETERS
 *  msg_id          [IN]:   the msg id which will be displayed
 *  parent_grp_id   [IN]:   other application will give the parent grp id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_iter_viewer_prev_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_iter_viewer_result_struct *iter_viewer_result;
    U32 msg_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat_text_viewer_show_left_slide_button_up();

    iter_viewer_result = g_sms_cntx.iter_viewer_result;
    if (iter_viewer_result->prev_launch_func_ptr == NULL)
    {
        return;
    }
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)
    mmi_frm_gesture_stop_listen_event();
#endif /* defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__) */
    msg_id = iter_viewer_result->prev_msg_id;
    iter_viewer_result->prev_launch_func_ptr(g_sms_parent_gid, msg_id, g_sms_cntx.user_data, CUI_MSG_VIEWER_TYPE_ITERATOR);

    mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_VIEWER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_iter_viewer_prev_launch
 * DESCRIPTION
 *  For other application to lanch SMS viewer screen at iterator viewer.
 * PARAMETERS
 *  msg_id          [IN]:   the msg id which will be displayed
 *  parent_grp_id   [IN]:   other application will give the parent grp id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_iter_viewer_next_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_iter_viewer_result_struct *iter_viewer_result;
    U32 msg_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat_text_viewer_show_right_slide_button_up();

    iter_viewer_result = g_sms_cntx.iter_viewer_result;
    if (iter_viewer_result->next_launch_func_ptr == NULL)
    {
        return;
    }
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)
    mmi_frm_gesture_stop_listen_event();
#endif /* defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__) */
    msg_id = iter_viewer_result->next_msg_id;
    iter_viewer_result->next_launch_func_ptr(g_sms_parent_gid, msg_id, g_sms_cntx.user_data, CUI_MSG_VIEWER_TYPE_ITERATOR);

    mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_VIEWER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_iter_viewer_view_curr_msg_callback
 * DESCRIPTION
 *  Read current msg callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_iter_viewer_view_curr_msg_callback(mmi_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SMS_RESULT_OK)
    {
        mmi_sms_msg_status_enum msg_status = *(mmi_sms_msg_status_enum*)data;

        g_sms_cntx.curr_msg_status = msg_status;
        
        if (mmi_frm_scrn_is_present(g_sms_gid ,SCR_ID_SMS_PROCESSING, MMI_FRM_NODE_ALL_FLAG))
        {
            if (mmi_sms_iter_viewer_query_indexing() == MMI_TRUE)
            {
                mmi_sms_iter_viewer_entry_viewer_scrn();
            }
        }
    }
    else
    {
        mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_PROCESSING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_iter_viewer_entry_viewer_scrn
 * DESCRIPTION
 *  Iterator viewer entry viewer screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_iter_viewer_entry_viewer_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_node_struct new_node_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_node_info.id = SCR_ID_SMS_VIEWER;
    new_node_info.entry_proc = (mmi_proc_func)mmi_sms_entry_viewer;
    if (mmi_frm_scrn_get_active_id() == SCR_ID_SMS_PROCESSING)
    {
        mmi_sms_entry_viewer();
        mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_PROCESSING);
    }
    else if (mmi_frm_scrn_is_present(g_sms_gid, SCR_ID_SMS_PROCESSING, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        mmi_frm_scrn_replace(g_sms_gid, SCR_ID_SMS_PROCESSING, &new_node_info);
    }
    else if (mmi_frm_scrn_get_active_id() == SCR_ID_SMS_VIEWER)
    {
        if (MMI_FALSE == g_sms_cntx.is_from_hs)
        {
        #if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__) 
            mmi_frm_gesture_listen_event(MMI_FRM_GESTURE_LEFT, mmi_sms_iter_viewer_next_msg_gesture_hdlr);
            mmi_frm_gesture_listen_event(MMI_FRM_GESTURE_RIGHT, mmi_sms_iter_viewer_prev_msg_gesture_hdlr);
        #endif /* defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__) */
            mmi_sms_iter_viewer_setup(middle_str);
            wgui_cat_text_viewer_change_slide_buttons_string();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_iter_viewer_setup
 * DESCRIPTION
 *  Read current msg callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_iter_viewer_setup(WCHAR * middle_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr left_button_function = NULL;
    FuncPtr right_button_function = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf((WCHAR *) middle_str, 
        "%d/%d", 
        g_sms_cntx.iter_viewer_result->index_number, 
        g_sms_cntx.iter_viewer_result->total_number);

    if (g_sms_cntx.iter_viewer_result->prev_launch_func_ptr != NULL)
    {
        left_button_function = mmi_sms_iter_viewer_prev_launch;
    }
    if (g_sms_cntx.iter_viewer_result->next_launch_func_ptr != NULL)
    {
        right_button_function = mmi_sms_iter_viewer_next_launch;
    }
    wgui_cat_text_viewer_setup_slide_buttons(
        NULL,
        NULL,
        NULL,
        left_button_function,
        NULL,
        NULL,
        NULL,
        right_button_function,
        middle_str,
        0);
}


#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_iter_viewer_prev_msg_gesture_hdlr
 * DESCRIPTION
 *  This function handles "left" gesture event in sms viewer screen.
 * PARAMETERS
 *  mmi_frm_gesture_event_enum
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_iter_viewer_prev_msg_gesture_hdlr (mmi_frm_gesture_event_enum gesture_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gesture_event == MMI_FRM_GESTURE_RIGHT)
    {
        mmi_sms_iter_viewer_prev_launch();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_iter_viewer_next_msg_gesture_hdlr
 * DESCRIPTION
 *  This function handles "right" gesture event in sms viewer screen.
 * PARAMETERS
 *  mmi_frm_gesture_event_enum
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_iter_viewer_next_msg_gesture_hdlr (mmi_frm_gesture_event_enum gesture_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gesture_event == MMI_FRM_GESTURE_LEFT)
    {
        mmi_sms_iter_viewer_next_launch();
    }
}
#endif /* defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__) */

#endif /* __MMI_UM_ITERATOR_VIEWER__ */


#ifdef __UM_SUPPORT__
/**********************************************************
 * FUNCTION
 *  mmi_sms_launch_viewer
 * DESCRIPTION
 *  For other application to lanch SMS viewer screen at iterator viewer.
 * PARAMETERS
 *  msg_id          [IN]:   the msg id which will be displayed
 *  parent_grp_id   [IN]:   other application will give the parent grp id
 *  user_data       [IN]:   user data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_launch_viewer(mmi_id parent_grp_id, U32 msg_id, void *user_data, cui_msg_viewer_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parent_grp_id == GRP_ID_INVALID)
    {
        return;
    }

    mmi_sms_um_set_sms_context(msg_id); /*set context with msg id */
    g_sms_parent_gid = parent_grp_id;
    g_sms_cntx.user_data = user_data;

#ifdef __MMI_UM_ITERATOR_VIEWER__
    if (CUI_MSG_VIEWER_TYPE_NORMAL == type)
    {
        g_sms_cntx.is_from_hs = MMI_TRUE;
        mmi_sms_group_entry(parent_grp_id);
        mmi_sms_box_list_opt_pre_view();
    }
    else if (CUI_MSG_VIEWER_TYPE_ITERATOR == type)
    {
        MMI_BOOL is_viewer_exist = MMI_FALSE;

        if (g_sms_gid != GRP_ID_INVALID)
        {
            is_viewer_exist = mmi_frm_scrn_is_present(
                                g_sms_gid,
                                SCR_ID_SMS_VIEWER,
                                MMI_FRM_NODE_ALL_FLAG);
        }

        if (!is_viewer_exist)
        {
            mmi_sms_group_entry(parent_grp_id);
        }

        g_sms_cntx.is_from_hs = MMI_FALSE;

        mmi_sms_read_msg(
            g_sms_cntx.curr_msg_id,
            MMI_TRUE,
            mmi_sms_iter_viewer_view_curr_msg_callback);

        if (is_viewer_exist)
        {
            mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_VIEWER);
        }
    }
    else
    {
        MMI_ASSERT(0);
    }
#else
    MMI_ASSERT(CUI_MSG_VIEWER_TYPE_NORMAL == type);
    g_sms_cntx.is_from_hs = MMI_TRUE;
    mmi_sms_group_entry(parent_grp_id);
    mmi_sms_box_list_opt_pre_view();
#endif /* __MMI_UM_ITERATOR_VIEWER__ */
}
#endif

#ifdef __MMI_SMS_DETAILS_INFO__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_details_scrn_leave_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static WCHAR* mmi_sms_get_details_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_status_enum sms_status;
    U16 msg_id = g_sms_cntx.curr_msg_id;
    U16 addr_caption_str_id = STR_SMS_MESSAGE_HEADER_TO;
    U16 date_caption_str_id = STR_ID_SMS_CREATION_DATE;
    U16 storage_type_str_id = STR_GLOBAL_PHONE;
    WCHAR address[SRV_SMS_MAX_ADDR_LEN + 1];
    WCHAR ts_date[MAX_TIMESTAMP_SIZE + 1];
    WCHAR ts_time[MAX_TIMESTAMP_SIZE + 1];
#ifdef __MMI_UM_REPORT_STATUS_IN_SENT_BOX__
    srv_sms_sr_status_enum delivery_status = srv_sms_get_delivery_status(msg_id);
#endif /* __MMI_UM_REPORT_STATUS_IN_SENT_BOX__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_status = srv_sms_get_msg_status(msg_id);

    if (sms_detail_buff != NULL)
    {
        OslMfree(sms_detail_buff);
        sms_detail_buff = NULL;
    }
    sms_detail_buff = OslMalloc((MMI_SMS_MAX_DETAILS_SCREEN_BUFFER + 1) * ENCODING_LENGTH);

    if ((sms_status & SRV_SMS_STATUS_UNREAD) || (sms_status & SRV_SMS_STATUS_READ))
    {
        addr_caption_str_id = STR_ID_SMS_FROM;
        date_caption_str_id = STR_ID_SMS_RECEIVE_DATE;
    }

    /* address number, not support email */
			#ifndef __MMI_SMS_SLIM__
    srv_sms_get_msg_address(msg_id, (S8*)address);
			#else
			mmi_sms_get_hilite_msg_addr((S8*)address);
			#endif
    if (address[0] == '\0')
    {
        mmi_ucs2cpy((S8*)address, GetString(STR_GLOBAL_EMPTY_LIST));
    }

    /* Date time */
    mmi_sms_get_msg_date_time(msg_id, (S8*)ts_date, (S8*)ts_time);

    /* Storage type*/
    if (srv_sms_get_msg_storage_type(msg_id) == SRV_SMS_STORAGE_SIM)
    {
    #if (MMI_MAX_SIM_NUM >= 2)
        srv_sms_sim_enum sim_id = srv_sms_get_msg_sim_id(msg_id);
        mmi_sim_enum mmi_sim = SRV_SMS_SMS_SIM_TO_MMI(sim_id);
        storage_type_str_id = mmi_sms_get_sim_str_id(mmi_sim);
    #else
        storage_type_str_id = STR_GLOBAL_SIM;
    #endif
    }
    #ifdef  __MMI_SMS_TCARD_STORAGE_SUPPORT__
    if (srv_sms_get_msg_storage_type(msg_id) == SRV_SMS_STORAGE_TCARD)
    {
		 storage_type_str_id = STR_GLOBAL_MEMORY_CARD;
    }
    #endif

#ifdef __MMI_UM_REPORT_STATUS_IN_SENT_BOX__
    if ((sms_status & SRV_SMS_STATUS_SENT)
        && (SRV_SMS_SRS_INVALID != delivery_status)
        && (SRV_SMS_SRS_NONE != delivery_status)
        )
    {
        U16 delivery_status_str_id = 0;

        switch (delivery_status)
        {
            case SRV_SMS_SRS_PENDING:
                delivery_status_str_id = STR_ID_SMS_PENDING;
                break;

            case SRV_SMS_SRS_SUCC:
                delivery_status_str_id = STR_ID_SMS_DELIVERED;
                break;

            case SRV_SMS_SRS_FAILED:
                delivery_status_str_id = STR_GLOBAL_FAILED;
                break;

            default:
                delivery_status_str_id = STR_GLOBAL_FAILED;
                break;
        }
        if(srv_sms_get_msg_storage_type(msg_id) == SRV_SMS_STORAGE_SIM 
           && g_sms_cntx.curr_box_type != SRV_SMS_BOX_INBOX)
        {
            kal_wsprintf(sms_detail_buff, 
                "%w%w%w%w%w%w%w%w%w%w%w%w%w%w%w", 
                GetString(addr_caption_str_id),
                (S8*) L"\n----\n", 
                (S8*) address,
                (S8*) L"\n\n",
                GetString(STR_ID_SMS_TYPE),
                (S8*) L"\n----\n",
                GetString(STR_GLOBAL_TEXT_MESSAGE),
                (S8*) L"\n\n",
                GetString(STR_ID_SMS_DELIVERY_STATUS),
                (S8*)L"\n----\n",
                GetString(delivery_status_str_id),
                (S8*)L"\n\n",
                GetString(STR_ID_SMS_STORAGE),
                (S8*)L"\n----\n",
                GetString(storage_type_str_id));
        }
        else
        {
            kal_wsprintf(sms_detail_buff, 
                "%w%w%w%w%w%w%w%w%w%w%w%w%w%w%w%w%w%w%w%w%w", 
                GetString(addr_caption_str_id),
                (S8*) L"\n----\n", 
                (S8*) address,
                (S8*) L"\n\n",
                GetString(STR_ID_SMS_TYPE),
                (S8*) L"\n----\n",
                GetString(STR_GLOBAL_TEXT_MESSAGE),
                (S8*) L"\n\n",
                GetString(date_caption_str_id),
                (S8*)L"\n----\n",
                (S8*)ts_date,
                (S8*)L"\n",
                (S8*)ts_time,
                (S8*)L"\n\n",
                GetString(STR_ID_SMS_DELIVERY_STATUS),
                (S8*)L"\n----\n",
                GetString(delivery_status_str_id),
                (S8*)L"\n\n",
                GetString(STR_ID_SMS_STORAGE),
                (S8*)L"\n----\n",
                GetString(storage_type_str_id));
        }
    }
    else
#endif /* __MMI_UM_REPORT_STATUS_IN_SENT_BOX__ */    
    {    
        if(srv_sms_get_msg_storage_type(msg_id) == SRV_SMS_STORAGE_SIM 
           && g_sms_cntx.curr_box_type != SRV_SMS_BOX_INBOX)
        {
            kal_wsprintf(sms_detail_buff, 
                "%w%w%w%w%w%w%w%w%w%w%w", 
                GetString(addr_caption_str_id),
                (S8*) L"\n----\n", 
                (S8*) address,
                (S8*) L"\n\n",
                GetString(STR_ID_SMS_TYPE),
                (S8*) L"\n----\n",
                GetString(STR_GLOBAL_TEXT_MESSAGE),
                (S8*) L"\n\n",
                GetString(STR_ID_SMS_STORAGE),
                (S8*)L"\n----\n",
                GetString(storage_type_str_id));            
        }
        else
        {
            kal_wsprintf(sms_detail_buff, 
                "%w%w%w%w%w%w%w%w%w%w%w%w%w%w%w%w%w", 
                GetString(addr_caption_str_id),
                (S8*) L"\n----\n", 
                (S8*) address,
                (S8*) L"\n\n",
                GetString(STR_ID_SMS_TYPE),
                (S8*) L"\n----\n",
                GetString(STR_GLOBAL_TEXT_MESSAGE),
                (S8*) L"\n\n",
                GetString(date_caption_str_id),
                (S8*)L"\n----\n",
                (S8*)ts_date,
                (S8*)L"\n",
                (S8*)ts_time,
                (S8*)L"\n\n",
                GetString(STR_ID_SMS_STORAGE),
                (S8*)L"\n----\n",
                GetString(storage_type_str_id));
        }
    }

    MMI_ASSERT(mmi_wcslen(sms_detail_buff) <= MMI_SMS_MAX_DETAILS_SCREEN_BUFFER);

    return sms_detail_buff;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_box_list_opt_pre_entry_details
 * DESCRIPTION
 *  prepare the details data before entry the details screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_box_list_opt_pre_entry_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_first_enter(
        g_sms_gid,
        SCR_ID_SMS_OPTION_DETAILS,
        (FuncPtr)mmi_sms_box_list_opt_entry_details,
        NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_details_scrn_leave_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_sms_details_scrn_leave_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
		default:
            if (sms_detail_buff != NULL)
            {
                OslMfree(sms_detail_buff);
                sms_detail_buff = NULL;
            }
            break;
    }

    return MMI_RET_OK; 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_box_list_opt_entry_details
 * DESCRIPTION
 *  entry the details screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_box_list_opt_entry_details(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(
            scrn_data->group_id,
            scrn_data->scrn_id,
            NULL,
            (FuncPtr)mmi_sms_box_list_opt_entry_details,
            MMI_FRM_FULL_SCRN))
    {
        U8* detail_buffer = (U8*)mmi_sms_get_details_info();
        U8 *gui_buffer = mmi_frm_scrn_get_gui_buf(scrn_data->group_id, scrn_data->scrn_id);

        ShowCategory74Screen(
            STR_GLOBAL_DETAILS,
            IMG_SMS_ENTRY_SCRN_CAPTION,
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            detail_buffer,
            (MMI_SMS_MAX_DETAILS_SCREEN_BUFFER + 1) * ENCODING_LENGTH,
            gui_buffer);

        //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

        mmi_frm_scrn_set_leave_proc(
            scrn_data->group_id,
            scrn_data->scrn_id,
            mmi_sms_details_scrn_leave_proc);
    }
}
#endif /* __MMI_SMS_DETAILS_INFO__ */

#ifdef __MMI_BT_MAP_CLIENT__
void mmi_sms_set_sms_context(U32 msg_id)
{
#ifdef __MMI_TELEPHONY_SUPPORT__
    srv_sms_box_enum msg_box_type;
    mmi_sms_list_enum list_type;
    
srv_sms_get_msg_list_index(&msg_box_type, msg_id);

   switch (msg_box_type)
   {
       case SRV_SMS_BOX_INBOX:
           list_type = MMI_SMS_LIST_INBOX;
           break;

       case SRV_SMS_BOX_UNSENT:
           list_type = MMI_SMS_LIST_UNSENT;
           break;

       case SRV_SMS_BOX_OUTBOX:
           list_type = MMI_SMS_LIST_OUTBOX;
           break;

       case SRV_SMS_BOX_DRAFTS:
           list_type = MMI_SMS_LIST_DRAFTS;
           break;

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__        
       case SRV_SMS_BOX_ARCHIVE:
           list_type = MMI_SMS_LIST_ARCHIVE;
           break;
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
       case SRV_SMS_BOX_SIM:
           list_type = MMI_SMS_LIST_SIMBOX;
           break;
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

#ifdef __MMI_UM_REPORT_BOX__
       case SRV_SMS_BOX_REPORT:
           list_type = MMI_SMS_LIST_REPORT;
           break; 
#endif /* __MMI_UM_REPORT_BOX__ */

       default:
           list_type = MMI_SMS_LIST_NONE;
           break;
   }


   g_sms_cntx.curr_msg_id = (U16)msg_id;
   g_sms_cntx.curr_box_type = msg_box_type;
   g_sms_cntx.curr_list_type = list_type;
#endif
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_box_list_opt_pre_view
 * DESCRIPTION
 *  Pre entry list option view msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_box_list_opt_pre_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_TELEPHONY_SUPPORT__
    if (srv_sms_get_msg_status(g_sms_cntx.curr_msg_id) & SRV_SMS_STATUS_UNREAD)
    {
        mmi_sms_read_msg(
            g_sms_cntx.curr_msg_id,
            MMI_TRUE,
            mmi_sms_view_curr_msg_callback);
    }
    else
    {
        mmi_sms_read_msg(
            g_sms_cntx.curr_msg_id,
            MMI_FALSE,
            mmi_sms_view_curr_msg_callback);
    }
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_box_list_opt_operation
 * DESCRIPTION
 *  Pre entry list option send
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_box_list_opt_operation(mmi_sms_result_enum result, void *data, mmi_sms_send_case_enum send_case)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SMS_RESULT_OK)
    {
        mmi_sms_msg_status_enum msg_status = *(mmi_sms_msg_status_enum*)data;

        g_sms_cntx.curr_msg_status = msg_status;

        if ((g_sms_gid == mmi_frm_group_get_active_id())
            && (SCR_ID_SMS_PROCESSING == mmi_frm_scrn_get_active_id()))
        {
            mmi_sms_entry_write_msg(send_case);
        }
    }

    mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_PROCESSING);
}


#ifndef __MMI_UNIFIED_COMPOSER__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_box_list_opt_reply
 * DESCRIPTION
 *  Pre entry list option reply msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_box_list_opt_reply(mmi_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_box_enum curr_box_type;
    mmi_sms_send_case_enum send_case = SMS_SEND_CASE_REPLY;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_get_msg_list_index(&curr_box_type, g_sms_cntx.curr_msg_id);

    if (curr_box_type == SRV_SMS_BOX_ARCHIVE)
    {
        send_case = SMS_SEND_CASE_ARCHIVE_REPLY;
    }

    mmi_sms_box_list_opt_operation(result, data, send_case);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_box_list_opt_forward
 * DESCRIPTION
 *  Pre entry list option item: forward
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_box_list_opt_forward(mmi_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_box_list_opt_operation(result, data, SMS_SEND_CASE_FORWARD);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_edit
 * DESCRIPTION
 *  Pre entry list option item: edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_box_list_opt_edit(mmi_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SMS_RESULT_OK)
    {
        mmi_sms_msg_status_enum msg_status = *(mmi_sms_msg_status_enum*)data;

        g_sms_cntx.curr_msg_status = msg_status;

        if ((g_sms_gid == mmi_frm_group_get_active_id())
            && (SCR_ID_SMS_PROCESSING == mmi_frm_scrn_get_active_id()))
        {
        #ifdef __MMI_MESSAGES_DRAFT_BOX__
            if (g_sms_cntx.curr_msg_status & SMS_STATUS_DRAFTS)
            {
                mmi_sms_entry_write_msg(SMS_SEND_CASE_EDIT_DRAFT);
            }
            else
        #endif /* __MMI_MESSAGES_DRAFT_BOX__ */
            {
                mmi_sms_entry_write_msg(SMS_SEND_CASE_EDIT_UNSENT);
            }
        }
    }

    mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_PROCESSING);
}

#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_box_list_opt_pre_reply
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_box_list_opt_pre_reply(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_COMPOSER__
    cui_uc_entry_msg_operation_launch(g_sms_parent_gid, g_sms_cntx.curr_msg_id, (U16)MMI_UC_INFO_TYPE_SMS, MMI_UC_OPERATION_REPLY);
#else /* __MMI_UNIFIED_COMPOSER__ */
    mmi_sms_read_msg(
        g_sms_cntx.curr_msg_id,
        MMI_FALSE,
        mmi_sms_box_list_opt_reply);
#endif
}


#if defined(__MMI_MMS_IN_UM__) && !defined(__MMI_UNIFIED_COMPOSER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_box_list_opt_reply_by_MMS
 * DESCRIPTION
 *  Pre entry list option reply msg by MMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_box_list_opt_reply_by_MMS(mmi_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SMS_RESULT_OK)
    {
        if ((g_sms_gid == mmi_frm_group_get_active_id())
            && (SCR_ID_SMS_PROCESSING == mmi_frm_scrn_get_active_id()))
        {
            mmi_sms_reply_by_MMS();
        }
    }

    mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_PROCESSING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_box_list_opt_pre_reply_by_MMS
 * DESCRIPTION
 *  Pre entry list option reply msg by MMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_box_list_opt_pre_reply_by_MMS(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_read_msg(
        g_sms_cntx.curr_msg_id,
        MMI_FALSE,
        mmi_sms_box_list_opt_reply_by_MMS);
}
#endif /* defined(__MMI_MMS_IN_UM__) && !defined(__MMI_UNIFIED_COMPOSER__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_box_list_opt_pre_forward
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_box_list_opt_pre_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_COMPOSER__
    cui_uc_entry_msg_operation_launch(g_sms_parent_gid, g_sms_cntx.curr_msg_id, (U16)MMI_UC_INFO_TYPE_SMS, MMI_UC_OPERATION_FORWARD);
#else /* __MMI_UNIFIED_COMPOSER__ */
    mmi_sms_read_msg(
        g_sms_cntx.curr_msg_id,
        MMI_FALSE,
        mmi_sms_box_list_opt_forward);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_box_list_opt_save_to_contact
 * DESCRIPTION
 *  Pre entry list option item: save to contact
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_box_list_opt_save_to_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 senderaddr[(SRV_SMS_MAX_ADDR_LEN + 1) *ENCODING_LENGTH];	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifndef __MMI_SMS_SLIM__
    srv_sms_get_msg_address(g_sms_cntx.curr_msg_id, senderaddr);
	#else
	mmi_sms_get_hilite_msg_addr((S8*)senderaddr);
	#endif


    if ((senderaddr[0] != '\0') || (senderaddr[1] != '\0'))
    {
        if (GRP_ID_INVALID == mmi_sms_save_number_to_phonebook(g_sms_gid, (U16*)senderaddr))
        {
            mmi_frm_group_close(g_sms_gid);
        }
    }
    else
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_UNFINISHED,
            MMI_EVENT_FAILURE);
        mmi_frm_group_close(g_sms_gid);
    }
}


#ifdef __MMI_SMS_SWITCH_MSG_READ_STATUS__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_box_list_opt_mark_as_read
 * DESCRIPTION
 *  Pre entry list option item: mark as read
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_box_list_opt_mark_as_read(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_change_sms_status(g_sms_cntx.curr_msg_id, SRV_SMS_STATUS_READ, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_box_list_opt_mark_as_unread
 * DESCRIPTION
 *  Pre entry list option item: mark as unread
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_box_list_opt_mark_as_unread(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_change_sms_status(g_sms_cntx.curr_msg_id, SRV_SMS_STATUS_UNREAD, NULL);
}
#endif /* __MMI_SMS_SWITCH_MSG_READ_STATUS__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_box_list_opt_send
 * DESCRIPTION
 *  Pre entry list option send
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_box_list_opt_send(mmi_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_box_list_opt_operation(result, data, SMS_SEND_CASE_SEND_DRAFT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_box_list_opt_pre_send
 * DESCRIPTION
 *  Pre entry list option send
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_box_list_opt_pre_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_read_msg(
        g_sms_cntx.curr_msg_id,
        MMI_FALSE,
        mmi_sms_box_list_opt_send);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_box_list_opt_pre_edit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_box_list_opt_pre_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_COMPOSER__
    cui_uc_entry_msg_operation_launch(g_sms_parent_gid, g_sms_cntx.curr_msg_id, (U16)MMI_UC_INFO_TYPE_SMS, MMI_UC_OPERATION_EDIT_EXISTED_MSG);
#else /* __MMI_UNIFIED_COMPOSER__ */
    mmi_sms_read_msg(
        g_sms_cntx.curr_msg_id,
        MMI_FALSE,
        mmi_sms_box_list_opt_edit);
#endif
}


#if (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__))
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_pre_entry_resend_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_box_list_opt_resend(mmi_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_box_list_opt_operation(result, data, SMS_SEND_CASE_RESEND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_box_list_opt_pre_edit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_box_list_opt_pre_resend(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_read_msg(
        g_sms_cntx.curr_msg_id,
        MMI_FALSE,
        mmi_sms_box_list_opt_resend);
}
#endif /* (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__)) */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_box_list_opt_check_adv
 * DESCRIPTION
 *  check msgbox list advanced option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_box_list_opt_check_adv(MMI_ID menu_gid, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_box_enum curr_box_type;
#ifdef __MMI_DUAL_SIM_MASTER__
#if defined (__MMI_MESSAGES_LIST_ADVANCED__) && defined(__MMI_MESSAGES_COPY__)
/* under construction !*/
#endif
#endif
#if defined (__MMI_MESSAGES_LIST_ADVANCED__) && defined(__MMI_MESSAGES_COPY__)
    MMI_ID cui_menu_gid = menu_gid;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_get_msg_list_index(&curr_box_type, g_sms_cntx.curr_msg_id);

#if defined (__MMI_MESSAGES_LIST_ADVANCED__) && defined(__MMI_MESSAGES_COPY__)
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    if (curr_box_type == SRV_SMS_BOX_ARCHIVE)
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_ADVANCED, MMI_TRUE);
    }
    else
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
    {
    #if defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__) || defined(__MMI_DUAL_SIM_MASTER__)
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_ADVANCED, MMI_FALSE);
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

        if (srv_sms_get_msg_storage_type(msg_id) == SRV_SMS_STORAGE_SIM)
        {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_COPY_TO_PHONE, MMI_FALSE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_COPY_TO_SIM, MMI_TRUE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_MOVE_TO_PHONE, MMI_FALSE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_MOVE_TO_SIM, MMI_TRUE);
            #ifdef  __MMI_SMS_TCARD_STORAGE_SUPPORT__
            if (srv_fmgr_drv_is_accessible(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE)))
            {
				cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_COPY_TO_TCARD, MMI_FALSE);
				cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_MOVE_TO_TCARD, MMI_FALSE);
        }
            else
            {
				cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_COPY_TO_TCARD, MMI_TRUE);
				cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_MOVE_TO_TCARD, MMI_TRUE);
            }
            #endif
        }
        #ifdef  __MMI_SMS_TCARD_STORAGE_SUPPORT__
        else if (srv_sms_get_msg_storage_type(msg_id) == SRV_SMS_STORAGE_TCARD)
        {
			cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_COPY_TO_TCARD, MMI_TRUE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_MOVE_TO_TCARD, MMI_TRUE);
            
               cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_COPY_TO_PHONE, MMI_FALSE);
                cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_MOVE_TO_PHONE, MMI_FALSE);
            /* hide save/move to sim option when no sim is avaiable */
            //cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_COPY_TO_SIM, (MMI_BOOL)(MMI_SIM_NONE == srv_nw_usab_get_one_usable_sim()));
            //cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_MOVE_TO_SIM, (MMI_BOOL)(MMI_SIM_NONE == srv_nw_usab_get_one_usable_sim()));
				#ifdef __MMI_DUAL_SIM_MASTER__
						#if(!defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || defined(__OP01__) )
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
						#endif
			#endif
        }
        #endif
        else
        {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_COPY_TO_PHONE, MMI_TRUE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_MOVE_TO_PHONE, MMI_TRUE);
            /* hide save/move to sim option when no sim is avaiable */
           // cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_COPY_TO_SIM, (MMI_BOOL)(MMI_SIM_NONE == srv_nw_usab_get_one_usable_sim()));
            //cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_MOVE_TO_SIM, (MMI_BOOL)(MMI_SIM_NONE == srv_nw_usab_get_one_usable_sim()));
            #ifdef __MMI_DUAL_SIM_MASTER__
						#if(!defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || defined(__OP01__) )
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
						#endif
			#endif
            #ifdef  __MMI_SMS_TCARD_STORAGE_SUPPORT__
           if (srv_fmgr_drv_is_accessible(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE)))
            {
				cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_COPY_TO_TCARD, MMI_FALSE);
				cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_MOVE_TO_TCARD, MMI_FALSE);
            }
            else
            {
				cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_COPY_TO_TCARD, MMI_TRUE);
				cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_MOVE_TO_TCARD, MMI_TRUE);
            }
            #endif
        }

    #if defined(__MMI_VUI_HOMESCREEN__)
        if (g_sms_cntx.is_from_hs)
        {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL, MMI_TRUE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL, MMI_TRUE);
        }
        else
    #endif /* defined(__MMI_VUI_HOMESCREEN__) */
    #ifdef __MMI_UM_CONVERSATION_BOX__
        if (mmi_um_check_conversation_box_setting()
            && ((curr_box_type == SRV_SMS_BOX_INBOX)||(curr_box_type == SRV_SMS_BOX_OUTBOX)
                ||((SRV_UM_MSG_BOX_CONVERSATION&SRV_UM_MSG_BOX_UNSENT) &&(curr_box_type == SRV_SMS_BOX_UNSENT)))
            )
        {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL, MMI_TRUE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL, MMI_TRUE);
        }
        else
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
        {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL, MMI_FALSE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL, MMI_FALSE);
        }

    #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
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
    #endif

    }
#endif/* (__MMI_MESSAGES_LIST_ADVANCED__) && defined(__MMI_MESSAGES_COPY__) */
}

 #ifndef __MMI_SMS_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_inbox_list_opt_check_reply_call
 * DESCRIPTION
 *  Check reply and call menu of list option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_inbox_list_opt_check_reply_call(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_menu_gid = menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    if (mmi_sms_is_sms_email(g_sms_cntx.curr_msg_id) == MMI_TRUE)
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_REPLY, MMI_FALSE);
    #if defined(__MMI_MMS_IN_UM__) && !defined(__MMI_UNIFIED_COMPOSER__)
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_REPLY_BY_MMS, MMI_FALSE);
    #endif
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_CALL_SENDER, MMI_TRUE);
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_SAVE_CONTACT, MMI_TRUE);
    }
    else
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
    if ((mmi_sms_check_is_valid_oa_addr(g_sms_cntx.curr_msg_id) == MMI_TRUE))
    {
        S8 ucs2_phb_num[(SRV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH];

        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_REPLY, MMI_FALSE);
    #if defined(__MMI_MMS_IN_UM__) && !defined(__MMI_UNIFIED_COMPOSER__) 
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_REPLY_BY_MMS, MMI_FALSE);
    #endif
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_CALL_SENDER, MMI_FALSE);

		#ifndef __MMI_SMS_SLIM__
        srv_sms_get_msg_address(g_sms_cntx.curr_msg_id, ucs2_phb_num);
		#else
		mmi_sms_get_hilite_msg_addr((S8*)ucs2_phb_num);
		#endif

        if (srv_phb_check_number_exist((U16*)ucs2_phb_num) == MMI_FALSE)
        {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_SAVE_CONTACT, MMI_FALSE);
        }
        else
        {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_SAVE_CONTACT, MMI_TRUE);
        }
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_REPLY, MMI_TRUE);
    #if defined(__MMI_MMS_IN_UM__) && !defined(__MMI_UNIFIED_COMPOSER__) 
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_REPLY_BY_MMS, MMI_TRUE);
    #endif
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_CALL_SENDER, MMI_TRUE);
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_SAVE_CONTACT, MMI_TRUE);
    }
}
#endif

 #ifndef __MMI_SMS_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_inbox_list_opt_entry_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_inbox_list_opt_entry_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_menu_gid = menu_evt->sender_id;
    srv_sms_status_enum curr_msg_status;
    srv_sms_box_enum curr_box_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sms_cntx.curr_msg_id = msg_id;
    curr_msg_status = srv_sms_get_msg_status(g_sms_cntx.curr_msg_id);
    srv_sms_get_msg_list_index(&curr_box_type, g_sms_cntx.curr_msg_id);
    
    cui_menu_set_default_title_image_by_id(cui_menu_gid, IMG_SMS_ENTRY_SCRN_CAPTION);

    mmi_sms_inbox_list_opt_check_reply_call(cui_menu_gid);
    
    if (curr_msg_status & SRV_SMS_STATUS_UNSUPPORTED)
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_FORWARD, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_FORWARD, MMI_FALSE);
    }

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ 
    if ((curr_msg_status &  SRV_SMS_STATUS_UNSUPPORTED)
        || (curr_box_type == SRV_SMS_BOX_ARCHIVE))
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_MOVE_TO_ARCHIVE, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_MOVE_TO_ARCHIVE, MMI_FALSE);
    }
#endif

#if (!defined (__UM_FOLDER__) && defined(__MMI_DUAL_SIM_MASTER__) && defined (__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* (defined (__MMI_DUAL_SIM_MASTER__) && defined (__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__)) */

#ifdef __MMI_SMS_SWITCH_MSG_READ_STATUS__
    if (curr_msg_status & SRV_SMS_STATUS_UNREAD)
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_MARK_AS_READ, MMI_FALSE);
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_MARK_AS_UNREAD, MMI_TRUE);
        
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_MARK_AS_READ, MMI_TRUE);
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_MARK_AS_UNREAD, MMI_FALSE);
    }
#endif /* __MMI_SMS_SWITCH_MSG_READ_STATUS__ */

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_UM_DEL_ALL_OPT, MMI_FALSE);
#ifdef __MMI_SMS_DETAILS_INFO__
    cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_DETAILS, MMI_FALSE);
#endif
#endif

    mmi_sms_box_list_opt_check_adv(cui_menu_gid, msg_id);
}
#endif


 #ifndef __MMI_SMS_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_sent_list_opt_entry_hdlr
 * DESCRIPTION
 *  Check outbox list option 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_sent_list_opt_entry_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_menu_gid = menu_evt->sender_id;
    srv_sms_status_enum curr_msg_status;
    srv_sms_box_enum curr_box_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sms_cntx.curr_msg_id = msg_id;
    curr_msg_status = srv_sms_get_msg_status(g_sms_cntx.curr_msg_id);
    srv_sms_get_msg_list_index(&curr_box_type, g_sms_cntx.curr_msg_id);

    cui_menu_set_default_title_image_by_id(cui_menu_gid, IMG_SMS_ENTRY_SCRN_CAPTION);

    if (curr_msg_status & SRV_SMS_STATUS_UNSUPPORTED)
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_FORWARD, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_FORWARD, MMI_FALSE);
    }

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ 
    if ((curr_msg_status &  SRV_SMS_STATUS_UNSUPPORTED)
        || (curr_box_type == SRV_SMS_BOX_ARCHIVE))
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_MOVE_TO_ARCHIVE, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_MOVE_TO_ARCHIVE, MMI_FALSE);
    }
#endif

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_UM_DEL_ALL_OPT, MMI_FALSE);
#ifdef __MMI_SMS_DETAILS_INFO__
    cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_DETAILS, MMI_FALSE);
#endif
#endif

    mmi_sms_box_list_opt_check_adv(cui_menu_gid, msg_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_default_list_opt_entry_hdlr
 * DESCRIPTION
 *  Entry default list option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_default_list_opt_entry_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_menu_gid = menu_evt->sender_id;
    srv_sms_box_enum curr_box_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sms_cntx.curr_msg_id = msg_id;

    srv_sms_get_msg_list_index(&curr_box_type, g_sms_cntx.curr_msg_id);

    cui_menu_set_default_title_image_by_id(cui_menu_gid, IMG_SMS_ENTRY_SCRN_CAPTION);

    if (curr_box_type == SRV_SMS_BOX_INBOX)
    {
    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        if (mmi_sms_is_sms_email(g_sms_cntx.curr_msg_id) == MMI_TRUE)
        {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_CALL_SENDER, MMI_TRUE);
        }
        else
    #endif /* __MMI_MESSAGES_SMS_EMAIL__ */
        if (mmi_sms_check_is_valid_oa_addr(g_sms_cntx.curr_msg_id) == MMI_TRUE)
        {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_CALL_SENDER, MMI_FALSE);
        }
        else
        {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_CALL_SENDER, MMI_TRUE);
        }
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_CALL_SENDER, MMI_TRUE);
    }

    mmi_sms_box_list_opt_check_adv(cui_menu_gid, msg_id);
}

#ifdef __MMI_TELEPHONY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_default_list_opt_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_default_list_opt_select_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *cui_menu_evt = menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sms_cntx.curr_msg_id = msg_id;

    switch (cui_menu_evt->highlighted_menu_id)
    {
        case MENU_ID_SMS_LIST_OPT_VIEW:
            mmi_sms_box_list_opt_pre_view();
            break;

        case MENU_ID_SMS_LIST_OPT_REPLY:
            mmi_sms_box_list_opt_pre_reply();
            break;

    #ifdef __GENERAL_TTS__
        case MENU_ID_SMS_LIST_OPT_PLAY_TTS:
            mmi_sms_tts_play_msg_by_id(msg_id);
            mmi_frm_group_close(g_sms_gid);
        break;
        
        case MENU_ID_SMS_LIST_OPT_STOP_TTS:
            mmi_sms_tts_stop_play();
            mmi_frm_group_close(g_sms_gid);
        break;
    #endif /* __GENERAL_TTS__ */

    #if defined(__MMI_MMS_IN_UM__) && !defined(__MMI_UNIFIED_COMPOSER__)
        case MENU_ID_SMS_LIST_OPT_REPLY_BY_MMS:
            mmi_sms_box_list_opt_pre_reply_by_MMS();
            break;
    #endif

        case MENU_ID_SMS_LIST_OPT_FORWARD:
            mmi_sms_box_list_opt_pre_forward();
            break;

        case MENU_ID_SMS_LIST_OPT_SAVE_CONTACT:
            mmi_sms_box_list_opt_save_to_contact();
            break;

    #ifdef __MMI_MESSAGES_DRAFT_BOX__
        case MENU_ID_SMS_LIST_OPT_SEND:
            mmi_sms_box_list_opt_pre_send();
            break;
    #endif

    #ifdef __MMI_MESSAGES_DRAFT_BOX__
        case MENU_ID_SMS_LIST_OPT_EDIT:
            mmi_sms_box_list_opt_pre_edit();
            break;
    #endif

    #if (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__))
        case MENU_ID_SMS_LIST_OPT_RESEND:
    #ifndef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        #if ((MMI_MAX_SIM_NUM == 2) && !defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__))
            {
                if (!srv_nw_usab_is_usable(MMI_SIM1) || !srv_nw_usab_is_usable(MMI_SIM2))
                {
                    resend_sim_id = SMS_SIM_UNSPECIFIC;
                    mmi_sms_box_list_opt_pre_resend();
                }
            }
        #elif (MMI_MAX_SIM_NUM >= 3)
            mmi_sms_launch_sim_sel_resend();
        #else
            mmi_sms_box_list_opt_pre_resend();
        #endif
    #else /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
        #if !defined( __MMI_MSG_EDITOR_WITH_RECIPIENT__)
        if (mmi_sms_get_valid_sim_op_count(srv_nw_usab_is_usable) == 1)
        #endif
        {
            mmi_sms_box_list_opt_pre_resend();
        }
    #endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
            break;
    #endif

        case MENU_ID_SMS_LIST_OPT_CALL_SENDER:
            mmi_sms_entry_call_sender();
            break;

        case MENU_ID_SMS_LIST_OPT_DELETE:
            mmi_sms_box_list_opt_pre_delete();
            break;

    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
         case MENU_ID_SMS_LIST_OPT_MOVE_TO_ARCHIVE:
             mmi_sms_move_sms_to_archive();
             break;
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

    #ifdef __MMI_SMS_SWITCH_MSG_READ_STATUS__
         case MENU_ID_SMS_LIST_OPT_MARK_AS_READ:
             mmi_sms_box_list_opt_mark_as_read();
             break;
         case MENU_ID_SMS_LIST_OPT_MARK_AS_UNREAD:
             mmi_sms_box_list_opt_mark_as_unread();
             break;
    #endif /* __MMI_SMS_SWITCH_MSG_READ_STATUS__ */

    #ifdef __MMI_MESSAGES_LIST_ADVANCED__
        case MENU_ID_SMS_LIST_OPT_ADVANCED:
            break;
    #endif /* __MMI_MESSAGES_LIST_ADVANCED__ */

    #ifdef __MMI_SMS_DETAILS_INFO__
        case MENU_ID_SMS_LIST_OPT_DETAILS:
            mmi_sms_box_list_opt_pre_entry_details();
            break;
    #endif

    
    #ifdef __MMI_MESSAGES_COPY__
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case MENU_ID_SMS_LIST_ADV_OPT_COPY_TO_PHONE:
            mmi_sms_list_opt_adv_copy_to_phone();
            break;

        case MENU_ID_SMS_LIST_ADV_OPT_MOVE_TO_PHONE:
            mmi_sms_list_opt_adv_move_to_phone();
            break;

		#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
		case MENU_ID_SMS_LIST_ADV_OPT_COPY_TO_TCARD:
            mmi_sms_list_opt_adv_copy_to_tcard();
            break;

        case MENU_ID_SMS_LIST_ADV_OPT_MOVE_TO_TCARD:
            mmi_sms_list_opt_adv_move_to_tcard();
            break;
		#endif
		
        case MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL:
            mmi_sms_list_opt_adv_copy_all_from_sim();
            break;

        case MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL:
            mmi_sms_list_opt_adv_move_all_from_sim();
            break;
    #endif
    #endif /* __MMI_MESSAGES_COPY__ */
#if defined(__MMI_LANG_ZAWGYI_MYANMAR__) && defined(__MMI_LANG_MYANMAR__)
	case MENU_ID_SMS_ZAWGYI:
		 /* z* code here */
		g_sms_view_read_by_zawgyi = MMI_TRUE;
		g_sms_view_set_language = MMI_TRUE;
    mmi_sms_box_list_opt_pre_view();
	 break;

	case MENU_ID_SMS_PADAUK:
		 /* m* code here */
		g_sms_view_read_by_zawgyi = MMI_FALSE;
		g_sms_view_set_language = MMI_TRUE;
  	mmi_sms_box_list_opt_pre_view();
	  break;
#endif
        default:
            break;
    }
}
#endif/*__MMI_TELEPHONY_SUPPORT__*/
#endif

#ifdef __MMI_MESSAGES_DRAFT_BOX__
 #ifndef __MMI_SMS_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_drafts_list_opt_entry_hdlr
 * DESCRIPTION
 *  Check Drafts list option 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_drafts_list_opt_entry_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_menu_gid = menu_evt->sender_id;
    srv_sms_status_enum curr_msg_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sms_cntx.curr_msg_id = msg_id;
    curr_msg_status = srv_sms_get_msg_status(g_sms_cntx.curr_msg_id);

    cui_menu_set_default_title_image_by_id(cui_menu_gid, IMG_SMS_ENTRY_SCRN_CAPTION);

    if (mmi_sms_is_send_enable() == MMI_TRUE)
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_SEND, MMI_FALSE);
    }
    else
    {
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        if (srv_sim_ctrl_get_num_of_inserted()==0)
        {
            cui_menu_set_item_disabled(cui_menu_gid, MENU_ID_SMS_LIST_OPT_SEND, MMI_TRUE);
        }
        else
#endif
        {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_SEND, MMI_TRUE);
        }
    }

    if (curr_msg_status & SRV_SMS_STATUS_UNSUPPORTED)
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_EDIT, MMI_TRUE);
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_SEND, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_EDIT, MMI_FALSE);
    }

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_UM_DEL_ALL_OPT, MMI_FALSE);
#ifdef __MMI_SMS_DETAILS_INFO__
    cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_DETAILS, MMI_FALSE);
#endif
#endif

    mmi_sms_box_list_opt_check_adv(cui_menu_gid, msg_id);
}
#endif
#endif /* __MMI_MESSAGES_DRAFT_BOX__*/


#if (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__))
 #ifndef __MMI_SMS_SLIM__
/*****************************************************************************
* FUNCTION
*  mmi_sms_unsent_list_opt_entry_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_sms_unsent_list_opt_entry_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_menu_gid = menu_evt->sender_id;
    srv_sms_status_enum curr_msg_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sms_cntx.curr_msg_id = msg_id;
    curr_msg_status = srv_sms_get_msg_status(g_sms_cntx.curr_msg_id);

    cui_menu_set_default_title_image_by_id(cui_menu_gid, IMG_SMS_ENTRY_SCRN_CAPTION);

#if ((MMI_MAX_SIM_NUM >= 2) && !defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__))
    mmi_sms_set_save_send_select_sim_leaf_item(cui_menu_gid, MENU_ID_SMS_LIST_OPT_RESEND, srv_nw_usab_is_usable);
#endif
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
    cui_menu_set_non_leaf_item(cui_menu_gid, MENU_ID_SMS_LIST_OPT_RESEND, FALSE);
#endif

    if ((curr_msg_status & SRV_SMS_STATUS_UNSUPPORTED))
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_RESEND, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_RESEND, MMI_FALSE);
    }
#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
    if (mmi_sms_is_send_enable() != MMI_TRUE)
    {
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        if (srv_sim_ctrl_get_num_of_inserted()==0)
        {
            cui_menu_set_item_disabled(cui_menu_gid, MENU_ID_SMS_LIST_OPT_RESEND, MMI_TRUE);
        }
        else
#endif
        {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_RESEND, MMI_TRUE);
        }
    }
    else
    {
        cui_menu_set_item_disabled(cui_menu_gid, MENU_ID_SMS_LIST_OPT_RESEND, MMI_FALSE);
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_RESEND, MMI_FALSE);
    }
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
    if (curr_msg_status & SRV_SMS_STATUS_UNSUPPORTED)
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_EDIT, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_EDIT, MMI_FALSE);
    }

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_UM_DEL_ALL_OPT, MMI_FALSE);
#ifdef __MMI_SMS_DETAILS_INFO__
    cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_DETAILS, MMI_FALSE);
#endif
#endif

    mmi_sms_box_list_opt_check_adv(cui_menu_gid, msg_id);
}
#endif


#if (MMI_MAX_SIM_NUM >= 3)
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_launch_sim_sel_resend
 * DESCRIPTION
 *  Launches SIM selection CUI for resend case.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_launch_sim_sel_resend()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((srv_mode_switch_get_current_mode() == MMI_SIM1)
        || (srv_mode_switch_get_current_mode() == MMI_SIM2)
        || (srv_mode_switch_get_current_mode() == MMI_SIM3)
    #if (MMI_MAX_SIM_NUM >= 4)
        || (srv_mode_switch_get_current_mode() == MMI_SIM4)
    #endif
        )
    {
        mmi_sim_enum mmi_sim = srv_mode_switch_get_current_mode();

        resend_sim_id = SMS_SIM_1 + mmi_frm_sim_to_index(mmi_sim);

        mmi_sms_box_list_opt_pre_resend();
    }
    else
    {
        mmi_id sim_sel_gid;
        mmi_sim_enum mmi_sim = MMI_SIM1;

        sim_sel_gid = cui_sim_sel_create(g_sms_gid, MMI_SIM1 | MMI_SIM2 | MMI_SIM3 | MMI_SIM4, NULL);

        mmi_sim = SRV_SMS_SMS_SIM_TO_MMI(srv_sms_get_msg_sim_id(g_sms_cntx.curr_msg_id));

        cui_sim_sel_set_highlight_sim(mmi_sim);
        cui_sim_sel_run(sim_sel_gid);
    }
}
#endif
#endif /* (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__)) */


#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_simbox_list_opt_entry_hdlr
 * DESCRIPTION
 *  Check SIM Message list option 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_simbox_list_opt_entry_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_menu_gid = menu_evt->sender_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_set_default_title_image_by_id(cui_menu_gid, IMG_SMS_ENTRY_SCRN_CAPTION);

#ifdef  __MMI_MESSAGES_COPY__
    cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_COPY_TO_PHONE, MMI_FALSE);
    cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_MOVE_TO_PHONE, MMI_FALSE);
    cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL, MMI_FALSE);
    cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL, MMI_FALSE);
    cui_menu_set_non_leaf_item(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL, MMI_FALSE);
    cui_menu_set_non_leaf_item(cui_menu_gid, MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL, MMI_FALSE);
#endif /* __MMI_MESSAGES_COPY__ */

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_UM_DEL_ALL_OPT, MMI_FALSE);
#ifdef __MMI_SMS_DETAILS_INFO__
    cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_DETAILS, MMI_FALSE);
#endif
#endif
}
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */


#if defined(__MMI_VUI_HOMESCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_recent_list_opt_entry_hdlr
 * DESCRIPTION
 *  Check SIM Message list option 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_recent_list_opt_entry_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_menu_gid = menu_evt->sender_id;
    srv_sms_status_enum curr_msg_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sms_cntx.curr_msg_id = msg_id;
    curr_msg_status = srv_sms_get_msg_status(g_sms_cntx.curr_msg_id);
    mmi_sms_inbox_list_opt_check_reply_call(cui_menu_gid);

    if (curr_msg_status & SRV_SMS_STATUS_UNSUPPORTED)
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_FORWARD, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_FORWARD, MMI_FALSE);
    }

#ifdef __MMI_SMS_SWITCH_MSG_READ_STATUS__
    if (curr_msg_status & SRV_SMS_STATUS_UNREAD)
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_MARK_AS_READ, MMI_FALSE);
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_MARK_AS_UNREAD, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_MARK_AS_READ, MMI_TRUE);
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_MARK_AS_UNREAD, MMI_FALSE);
    }
#endif /* __MMI_SMS_SWITCH_MSG_READ_STATUS__ */

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
#ifdef __MMI_SMS_DETAILS_INFO__
    cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_DETAILS, MMI_FALSE);
#endif
#endif

    mmi_sms_box_list_opt_check_adv(cui_menu_gid, msg_id);
}

#ifdef __MMI_TELEPHONY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_recent_list_opt_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_recent_list_opt_select_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *cui_menu_evt = menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sms_cntx.curr_msg_id = msg_id;

    switch (cui_menu_evt->highlighted_menu_id)
    {
        case MENU_ID_SMS_LIST_OPT_VIEW:
            mmi_sms_box_list_opt_pre_view();
            break;

        case MENU_ID_SMS_LIST_OPT_REPLY:
            mmi_sms_box_list_opt_pre_reply();
            break;
    #if defined(__MMI_MMS_IN_UM__) && !defined(__MMI_UNIFIED_COMPOSER__)
        case MENU_ID_SMS_LIST_OPT_REPLY_BY_MMS:
            mmi_sms_box_list_opt_pre_reply_by_MMS();
            break;
    #endif

        case MENU_ID_SMS_LIST_OPT_CALL_SENDER:
            mmi_frm_group_close(g_sms_gid);
            mmi_sms_entry_call_sender();
            break;

        case MENU_ID_SMS_LIST_OPT_FORWARD:
            mmi_sms_box_list_opt_pre_forward();
            break;

        case MENU_ID_SMS_LIST_OPT_DELETE:
            mmi_sms_box_list_opt_pre_delete();
            break;

        case MENU_ID_SMS_LIST_OPT_SAVE_CONTACT:
            mmi_sms_box_list_opt_save_to_contact();
            break;

    #ifdef __MMI_SMS_SWITCH_MSG_READ_STATUS__
        case MENU_ID_SMS_LIST_OPT_MARK_AS_READ:
            mmi_sms_box_list_opt_mark_as_read();
            break;
        case MENU_ID_SMS_LIST_OPT_MARK_AS_UNREAD:
            mmi_sms_box_list_opt_mark_as_unread();
            break;
    #endif /* __MMI_SMS_SWITCH_MSG_READ_STATUS__ */

    #ifdef __MMI_MESSAGES_LIST_ADVANCED__
        case MENU_ID_SMS_LIST_OPT_ADVANCED:
            break;
    #endif /* __MMI_MESSAGES_LIST_ADVANCED__ */

    #ifdef __MMI_SMS_DETAILS_INFO__
        case MENU_ID_SMS_LIST_OPT_DETAILS:
            mmi_sms_box_list_opt_pre_entry_details();
            break;
    #endif

        default:
            break;
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_pre_entry_recent_list_option
 * DESCRIPTION
 *  Read current highlihgt msg before entry msgbox list options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_pre_entry_recent_list_option(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_group_entry(parent_gid);
    g_sms_cntx.is_from_hs = MMI_TRUE;

    mmi_sms_entry_menu_cui_options_generic(
        g_sms_gid,
        MENU_ID_SMS_RECENT_LIST_OPT,
        0);
}

#endif /* __MMI_VUI_HOMESCREEN__*/


#ifdef __MMI_MESSAGES_LIST_ADVANCED__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_box_list_adv_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_box_list_adv_select_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *cui_menu_evt = menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sms_cntx.curr_msg_id = msg_id;

    switch (cui_menu_evt->highlighted_menu_id)
    {
    #if defined(__MMI_MESSAGES_COPY__) && (!defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || defined(__OP01__) )
    
        case MENU_ID_SMS_LIST_ADV_OPT_COPY_TO_PHONE:
            mmi_sms_list_opt_adv_copy_to_phone();
            break;

        case MENU_ID_SMS_LIST_ADV_OPT_COPY_TO_SIM:
            mmi_sms_list_opt_adv_copy_to_sim();
            break;

        case MENU_ID_SMS_LIST_ADV_OPT_MOVE_TO_PHONE:
            mmi_sms_list_opt_adv_move_to_phone();
            break;

        case MENU_ID_SMS_LIST_ADV_OPT_MOVE_TO_SIM:
            mmi_sms_list_opt_adv_move_to_sim();
            break;

            #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
          case MENU_ID_SMS_LIST_ADV_OPT_MOVE_TO_TCARD:
            mmi_sms_list_opt_adv_move_to_tcard();
            break;

        case MENU_ID_SMS_LIST_ADV_OPT_COPY_TO_TCARD:
            mmi_sms_list_opt_adv_copy_to_tcard();
            break;
            #endif

    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL:
            mmi_sms_list_opt_adv_copy_all_from_phone();
    
        case MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL:
            mmi_sms_list_opt_adv_move_all_from_phone();
            break;
    #else
        case MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL:
            mmi_sms_list_opt_adv_copy_all();
            break;
    
        case MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL:
            mmi_sms_list_opt_adv_move_all();
            break;
    #endif

    #endif /* defined(__MMI_MESSAGES_COPY__) && !defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) */

        default:
            break;
    }
}
#endif /* __MMI_MESSAGES_LIST_ADVANCED__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_box_list_opt_delete_callback
 * DESCRIPTION
 *  Delete callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_box_list_opt_delete_callback(mmi_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SMS_RESULT_OK)
    {
        g_sms_cntx.curr_msg_id = SRV_SMS_INVALID_MSG_ID;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_box_list_opt_delete
 * DESCRIPTION
 *  entry list option item: delete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_box_list_opt_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_delete_msg(g_sms_cntx.curr_msg_id, mmi_sms_box_list_opt_delete_callback);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_box_list_opt_pre_delete
 * DESCRIPTION
 *  Pre entry list option item: delete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_box_list_opt_pre_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_entry_confirm(
        g_sms_gid,
        STR_GLOBAL_DELETE_ASK,
        mmi_sms_box_list_opt_delete,
        mmi_frm_scrn_close_active_id,
        MMI_TRUE);   
}


#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_bg_send
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_list_opt_bg_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_sms_is_empty_address(g_sms_cntx.curr_msg_id) == MMI_FALSE)
    {
        if (mmi_sms_check_unsent_sms_status() == MMI_TRUE)
        {
            mmi_sms_change_unsent_sending_status(g_sms_cntx.curr_msg_id, SRV_SMS_SEND_WAITING);
        }
        else
        {
            mmi_frm_group_close(g_sms_gid);
        }
    }
    else
    {
        mmi_sms_entry_confirm_sg(
            g_sms_gid,
            STR_ID_SMS_BG_NO_DESTIATION_MOVE_TO_DRAFT_QUERY,
            mmi_sms_move_unsent_sms_to_draft,
            mmi_frm_scrn_close_active_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_bg_cancel_send
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_bg_cancel_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_sms_check_unsent_sms_status() == MMI_TRUE)
    {
        mmi_sms_change_unsent_sending_status(g_sms_cntx.curr_msg_id, SRV_SMS_SEND_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_bg_pre_edit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_bg_pre_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_sms_check_unsent_sms_status() == MMI_TRUE)
    {
        srv_sms_set_unsent_msg_status(g_sms_cntx.curr_msg_id, SRV_SMS_SEND_FAIL);

    #ifdef __MMI_UNIFIED_COMPOSER__
        cui_uc_entry_msg_operation_launch(g_sms_parent_gid, g_sms_cntx.curr_msg_id, (U16)MMI_UC_INFO_TYPE_SMS, MMI_UC_OPERATION_EDIT_EXISTED_MSG);
    #else /* __MMI_UNIFIED_COMPOSER__ */
        mmi_sms_read_msg(
            g_sms_cntx.curr_msg_id,
            MMI_FALSE,
            mmi_sms_list_opt_bg_edit);
    #endif
    }
    else
    {
        mmi_frm_group_close(g_sms_gid);
    }
}


#ifndef __MMI_UNIFIED_COMPOSER__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_bg_edit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_bg_edit(mmi_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SMS_RESULT_OK)
    {
        mmi_sms_msg_status_enum msg_status = *(mmi_sms_msg_status_enum*)data;

        g_sms_cntx.curr_msg_status = msg_status;

        if (mmi_frm_scrn_is_present(g_sms_gid, SCR_ID_SMS_PROCESSING, MMI_FRM_NODE_ALL_FLAG)
            && (mmi_frm_scrn_get_active_id() == SCR_ID_SMS_PROCESSING))
        {
            mmi_sms_entry_write_msg(SMS_SEND_CASE_EDIT_UNSENT);
            mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_PROCESSING);
        }
    }
    else
    {
        mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_PROCESSING);
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_bg_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_bg_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_sms_check_unsent_sms_status() == MMI_TRUE)
    {
        mmi_sms_entry_confirm(
            g_sms_gid,
            STR_GLOBAL_DELETE_ASK,
            mmi_sms_list_opt_bg_delete_unsent,
            mmi_frm_scrn_close_active_id,
            MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_bg_delete_unsent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_bg_delete_unsent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Chagne the status to Fail first */
    srv_sms_set_unsent_msg_status(g_sms_cntx.curr_msg_id, SRV_SMS_SEND_FAIL);
    mmi_sms_box_list_opt_delete();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_check_unsent_sms_status
 * DESCRIPTION
 *  check the status from the current highlight unsent sms
 * PARAMETERS
 *  void
 * RETURNS
 *  If exist return MMI_TRUE, else return MMI_FALSE
 *****************************************************************************/
static MMI_BOOL mmi_sms_check_unsent_sms_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    srv_sms_status_enum curr_msg_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_msg_status = srv_sms_get_msg_status(g_sms_cntx.curr_msg_id);

    if (curr_msg_status & SRV_SMS_STATUS_UNSENT)
    {
        srv_sms_send_status_enum send_status;

        send_status = srv_sms_get_unsent_msg_status(g_sms_cntx.curr_msg_id);

        if (g_sms_cntx.send_status != send_status)
        {
            result = MMI_FALSE;

            mmi_sms_display_popup_ext(
                STR_SMS_BACKGROUND_STATUS_CHANGED_ID,
                MMI_EVENT_FAILURE);
        }
        else
        {
            result = MMI_TRUE;
        }
    }
    else
    {
        result = MMI_FALSE;

        mmi_sms_display_popup_ext(
            STR_SMS_BACKGROUND_NOT_EXIST_ID,
            MMI_EVENT_FAILURE);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_opt_action_common_callback
 * DESCRIPTION
 *  Delete callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_opt_action_common_callback(mmi_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
	mmi_msg_update_unsent_icon();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_move_unsent_sms_to_draft
 * DESCRIPTION
 *  move unsent sms to draft box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_move_unsent_sms_to_draft(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_change_sms_status(
        g_sms_cntx.curr_msg_id,
        SRV_SMS_STATUS_DRAFT,
        mmi_sms_list_opt_action_common_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bg_list_opt_entry_hdlr
 * DESCRIPTION
 *  Delete callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_bg_list_opt_entry_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_status_enum curr_msg_status;
    MMI_ID cui_menu_gid = menu_evt->sender_id;
    g_sms_cntx.curr_msg_id = msg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_msg_status = srv_sms_get_msg_status(msg_id);
    g_sms_cntx.send_status = srv_sms_get_unsent_msg_status(msg_id);

    cui_menu_set_default_title_image_by_id(cui_menu_gid, IMG_SMS_ENTRY_SCRN_CAPTION);

    switch (g_sms_cntx.send_status)
    {
        case SRV_SMS_SEND_WAITING:
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_BG_SEND, MMI_TRUE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_BG_CALCEL_SEND, MMI_FALSE);
            if (curr_msg_status & SRV_SMS_STATUS_UNSUPPORTED)
            {
                cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_BG_EDIT, MMI_TRUE);
            }
            else
            {
                cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_BG_EDIT, MMI_FALSE);
            }
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_BG_DELETE, MMI_FALSE);

            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_UM_DEL_ALL_OPT, MMI_FALSE);
        #ifdef __MMI_SMS_DETAILS_INFO__
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_DETAILS, MMI_FALSE);
        #endif
            break;

        case SRV_SMS_SEND_FAIL:
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_BG_CALCEL_SEND, MMI_TRUE);
            if (curr_msg_status & SRV_SMS_STATUS_UNSUPPORTED)
            {
                cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_BG_SEND, MMI_TRUE);
                cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_BG_EDIT, MMI_TRUE);
            }
            else
            {
                cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_BG_SEND, MMI_FALSE);
                cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_BG_EDIT, MMI_FALSE);
            }     
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_BG_DELETE, MMI_FALSE);

            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_UM_DEL_ALL_OPT, MMI_FALSE);
        #ifdef __MMI_SMS_DETAILS_INFO__
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_DETAILS, MMI_FALSE);
        #endif
            break;

        case SRV_SMS_SEND_SENDING:
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_BG_SEND, MMI_TRUE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_BG_EDIT, MMI_TRUE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_BG_DELETE, MMI_TRUE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_UM_DEL_ALL_OPT, MMI_TRUE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_BG_CALCEL_SEND, MMI_FALSE);
        #ifdef __MMI_SMS_DETAILS_INFO__
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_DETAILS, MMI_TRUE);
        #endif
            break;

        default:
            break;
    }
    
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    if (srv_sim_ctrl_get_num_of_inserted()==0)
    {
        cui_menu_set_item_disabled(cui_menu_gid, MENU_ID_SMS_LIST_OPT_BG_SEND, MMI_TRUE);
    }
    else
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
    {
        if (srv_nw_usab_get_one_usable_sim() == MMI_SIM_NONE)
        {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_LIST_OPT_BG_SEND, MMI_TRUE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bg_list_opt_select_hdlr
 * DESCRIPTION
 *  Delete callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_bg_list_opt_select_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    g_sms_cntx.curr_msg_id = msg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->highlighted_menu_id)
    {
        case MENU_ID_SMS_LIST_OPT_BG_SEND:
            mmi_sms_list_opt_bg_send();
            break;

        case MENU_ID_SMS_LIST_OPT_BG_CALCEL_SEND:
            mmi_sms_list_opt_bg_cancel_send();
            break;

        case MENU_ID_SMS_LIST_OPT_BG_EDIT:
            mmi_sms_list_opt_bg_pre_edit();
            break;

        case MENU_ID_SMS_LIST_OPT_BG_DELETE:
            mmi_sms_list_opt_bg_delete();
            break;

    #ifdef __MMI_SMS_DETAILS_INFO__
        case MENU_ID_SMS_LIST_OPT_DETAILS:
            mmi_sms_box_list_opt_pre_entry_details();
            break;
    #endif

        default:
            break;
    }
}
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_inbox_viewer_opt_entry_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_inbox_viewer_opt_entry_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id)
{
#ifdef __MMI_TELEPHONY_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_status_enum curr_msg_status;
    srv_sms_box_enum curr_box_type;
    MMI_ID cui_menu_gid = menu_evt->sender_id;
    U16 curr_msg_id = msg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_msg_status = srv_sms_get_msg_status(curr_msg_id);
    srv_sms_get_msg_list_index(&curr_box_type, curr_msg_id);

#ifdef __MMI_MESSAGE_SMS_HILITE_VIEWER__
    mmi_sms_check_hilite_item_opt(cui_menu_gid);
#endif /* __MMI_MESSAGE_SMS_HILITE_VIEWER__ */

    if (mmi_sms_check_is_valid_oa_addr(curr_msg_id) == MMI_TRUE)
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_REPLY, MMI_FALSE);
    #if defined(__MMI_MMS_IN_UM__) && !defined(__MMI_UNIFIED_COMPOSER__) 
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_REPLY_BY_MMS, MMI_FALSE);
    #endif

    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        if (mmi_sms_is_sms_email(curr_msg_id) == MMI_TRUE)
        {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_CALL_SENDER, MMI_TRUE);
            #ifdef __MMI_SMS_SLIM__
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_SAVE_CONTACT, MMI_TRUE);
            #endif
        }
        else
    #endif /* __MMI_MESSAGES_SMS_EMAIL__ */
        {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_CALL_SENDER, MMI_FALSE);
            #ifdef __MMI_SMS_SLIM__
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_SAVE_CONTACT, MMI_FALSE);
            #endif
        }
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_REPLY, MMI_TRUE);
    #if defined(__MMI_MMS_IN_UM__) && !defined(__MMI_UNIFIED_COMPOSER__) 
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_REPLY_BY_MMS, MMI_TRUE);
    #endif
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_CALL_SENDER, MMI_TRUE);
        #ifdef __MMI_SMS_SLIM__
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_SAVE_CONTACT, MMI_TRUE);
            #endif
    }

    if (curr_msg_status & SRV_SMS_STATUS_UNSUPPORTED)
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_FORWARD, MMI_TRUE);
    #ifdef __MMI_MESSAGES_USERDEFINED_TEMPLATE__
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_SAVE_TEMPLATE, MMI_TRUE);
    #endif /* __MMI_MESSAGES_USERDEFINED_TEMPLATE__ */
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_ARCHIVE, MMI_TRUE);
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
    #if defined(__MMI_SMS_APP_EMS_SUPPORT__) && defined(__MMI_MESSAGE_SMS_USE_DETAIL__)
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_SAVE_OBJ, MMI_TRUE);
    #endif /* __MMI_SMS_APP_EMS_SUPPORT__ && __MMI_MESSAGE_SMS_USE_DETAIL__ */
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_FORWARD, MMI_FALSE);
    #ifdef __MMI_MESSAGES_USERDEFINED_TEMPLATE__
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_SAVE_TEMPLATE, MMI_FALSE);
    #endif /* __MMI_MESSAGES_USERDEFINED_TEMPLATE__ */
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        if  (curr_box_type == SRV_SMS_BOX_ARCHIVE)
        {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_ARCHIVE, MMI_TRUE);
        }
        else
        {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_ARCHIVE, MMI_FALSE);
        }
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
    #if defined(__MMI_SMS_APP_EMS_SUPPORT__) && defined(__MMI_MESSAGE_SMS_USE_DETAIL__)
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_SAVE_OBJ, MMI_FALSE);
    #endif /* __MMI_SMS_APP_EMS_SUPPORT__ && __MMI_MESSAGE_SMS_USE_DETAIL__ */
    }

#if (defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || !defined(__MMI_MESSAGES_COPY__))
    if (curr_msg_status & SRV_SMS_STATUS_UNSUPPORTED)
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_ADVANCED, MMI_TRUE);
    }
    else
#endif
    {
    #if (defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || !defined(__MMI_MESSAGES_COPY__))
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_ADVANCED, MMI_FALSE);
    #endif
        mmi_sms_check_viewer_adv_detail(cui_menu_gid, curr_msg_id);
        mmi_sms_check_viewer_adv_copy_move(cui_menu_gid, curr_msg_id);
    }

#if defined(__MMI_SMS_SET_AS_REMINDER__) && defined(__MMI_TODOLIST__)
    if ((curr_msg_status & SRV_SMS_STATUS_UNSUPPORTED)
        || (curr_box_type == SRV_SMS_BOX_ARCHIVE))
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_ADD_TO_CALENDAR, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_ADD_TO_CALENDAR, MMI_FALSE);
    }
#endif

#ifdef __MMI_CLIPBOARD__
    mmi_sms_box_viewer_check_edit_option(menu_evt, curr_msg_status);
#endif

#endif /*__MMI_TELEPHONY_SUPPORT__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_sent_viewer_opt_entry_hdlr
 * DESCRIPTION
 *  Check outbox list option 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_sent_viewer_opt_entry_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id)
{
#ifdef __MMI_TELEPHONY_SUPPORT__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_status_enum curr_msg_status;
    srv_sms_box_enum curr_box_type;
    MMI_ID cui_menu_gid = menu_evt->sender_id;
    U16 curr_msg_id = msg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_msg_status = srv_sms_get_msg_status(curr_msg_id);
    srv_sms_get_msg_list_index(&curr_box_type, curr_msg_id);

#ifdef __MMI_MESSAGE_SMS_HILITE_VIEWER__
    mmi_sms_check_hilite_item_opt(cui_menu_gid);
#endif /* __MMI_MESSAGE_SMS_HILITE_VIEWER__ */
    
    if (curr_msg_status & SRV_SMS_STATUS_UNSUPPORTED)
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_FORWARD, MMI_TRUE);
    #ifdef __MMI_MESSAGES_USERDEFINED_TEMPLATE__
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_SAVE_TEMPLATE, MMI_TRUE);
    #endif /* __MMI_MESSAGES_USERDEFINED_TEMPLATE__ */
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_ARCHIVE, MMI_TRUE);
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_FORWARD, MMI_FALSE);
    #ifdef __MMI_MESSAGES_USERDEFINED_TEMPLATE__
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_SAVE_TEMPLATE, MMI_FALSE);
    #endif /* __MMI_MESSAGES_USERDEFINED_TEMPLATE__ */
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        if (curr_box_type == SRV_SMS_BOX_ARCHIVE)
        {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_ARCHIVE, MMI_TRUE);
        }
        else
        {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_ARCHIVE, MMI_FALSE);
        }
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
    }

#if (defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || !defined(__MMI_MESSAGES_COPY__))
    if (curr_msg_status & SRV_SMS_STATUS_UNSUPPORTED)
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_ADVANCED, MMI_TRUE);
    }
    else
#endif
    {
    #if (defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || !defined(__MMI_MESSAGES_COPY__))
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_ADVANCED, MMI_FALSE);
    #endif

        mmi_sms_check_viewer_adv_detail(cui_menu_gid, curr_msg_id);
        mmi_sms_check_viewer_adv_copy_move(cui_menu_gid, curr_msg_id);
    }

#if defined(__MMI_SMS_APP_EMS_SUPPORT__) && defined(__MMI_MESSAGE_SMS_USE_DETAIL__)
    cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_SAVE_OBJ, MMI_TRUE);
#endif /* __MMI_SMS_APP_EMS_SUPPORT__ && __MMI_MESSAGE_SMS_USE_DETAIL__ */

#ifdef __MMI_CLIPBOARD__
    mmi_sms_box_viewer_check_edit_option(menu_evt, curr_msg_status);
#endif
#endif/*__MMI_TELEPHONY_SUPPORT__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_default_viewer_opt_entry_hdlr
 * DESCRIPTION
 *  Entry default viewer option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_default_viewer_opt_entry_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id)
{
#ifdef __MMI_TELEPHONY_SUPPORT__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_box_enum curr_box_type;
    MMI_ID cui_menu_gid = menu_evt->sender_id;
    U16 curr_msg_id = msg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_get_msg_list_index(&curr_box_type, curr_msg_id);

    if (curr_box_type == SRV_SMS_BOX_INBOX)
    {
        if (mmi_sms_check_is_valid_oa_addr(curr_msg_id) == MMI_TRUE)
        {
        #ifdef __MMI_MESSAGES_SMS_EMAIL__
            if (mmi_sms_is_sms_email(curr_msg_id) == MMI_TRUE)
            {
                cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_CALL_SENDER, MMI_TRUE);
            }
            else
        #endif /* __MMI_MESSAGES_SMS_EMAIL__ */
            {
                cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_CALL_SENDER, MMI_FALSE);
             #ifdef __MMI_SMS_SLIM__
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_SAVE_CONTACT, MMI_FALSE);
            #endif
            }
        }
        else
        {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_CALL_SENDER, MMI_TRUE);
            #ifdef __MMI_SMS_SLIM__
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_SAVE_CONTACT, MMI_TRUE);
            #endif
        }
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_CALL_SENDER, MMI_TRUE);
         #ifdef __MMI_SMS_SLIM__
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_SAVE_CONTACT, MMI_TRUE);
         #endif
    }
    #endif/*__MMI_TELEPHONY_SUPPORT__*/
}

#ifdef __MMI_TELEPHONY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_default_viewer_opt_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_default_viewer_opt_select_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *cui_menu_evt = menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sms_cntx.curr_msg_id = msg_id;

    switch (cui_menu_evt->highlighted_menu_id)
    {
        case MENU_ID_SMS_VIEWER_OPT_REPLY:
            mmi_sms_viewer_opt_reply();
            break;

   #ifdef  __GENERAL_TTS__     
        case MENU_ID_SMS_VIEWER_OPT_PLAY_TTS:
            mmi_sms_play_msg_by_content(msg_id);
            cui_menu_close(menu_evt->sender_id);
            break;

        case MENU_ID_SMS_VIEWER_OPT_STOP_TTS:
            mmi_sms_tts_stop_play();
            cui_menu_close(menu_evt->sender_id);
            break;
    #endif /* __GENERAL_TTS__ */

    #if defined(__MMI_MMS_IN_UM__) && !defined(__MMI_UNIFIED_COMPOSER__)
        case MENU_ID_SMS_VIEWER_OPT_REPLY_BY_MMS:
            mmi_sms_viewer_opt_reply_by_MMS();
            break;
    #endif
        
        case MENU_ID_SMS_VIEWER_OPT_CALL_SENDER:
            mmi_sms_entry_call_sender();
            break;
            #ifdef __MMI_SMS_SLIM__
            case MENU_ID_SMS_VIEWER_OPT_SAVE_CONTACT:
            mmi_sms_box_list_opt_save_to_contact();
            break;
            #endif

        case MENU_ID_SMS_VIEWER_OPT_FORWARD:
            mmi_sms_viewer_opt_forward();
            break;

        case MENU_ID_SMS_VIEWER_OPT_DELETE:
            mmi_sms_viewer_opt_pre_delete();
            break;
        
#ifdef __MMI_MESSAGE_SMS_HILITE_VIEWER__
        case MENU_ID_SMS_USE_NUMBER_OPT:
    #if defined(__MMI_EMAIL__)
        case MENU_ID_SMS_USE_EMAIL_OPT:
    #elif (defined(__MMI_PHB_OPTIONAL_FIELD__))
        case MENU_ID_SMS_USE_EMAIL_OPT_SAVE_TO_EMAIL:
    #endif /* __MMI_EMAIL__ */
    #ifdef __MMI_MESSAGES_USE_URL__
        case MENU_ID_SMS_USE_URL_OPT:
    #endif /* __MMI_MESSAGES_USE_URL__ */
	case MENU_ID_SMS_SEND_USSD_OPT:
		{
			MMI_ID mmi_sms_hilite_gid = mmi_frm_group_create_ex(
				g_sms_gid,
				GRP_ID_AUTO_GEN,
				mmi_sms_viewer_hilite_proc,
				NULL,
				MMI_FRM_NODE_SMART_CLOSE_FLAG);
			mmi_sms_use_detail_hilite_info(mmi_sms_hilite_gid, hilite_cntx.currHiliteItemIndex);
		}
		break;
	
#ifdef __MMI_SMS_APP_EMS_SUPPORT__
	case MENU_ID_SMS_SAVE_OBJECTS_OPT:
		mmi_ems_pre_entry_save_object_name(g_sms_gid);
		break;
#endif
#endif /* __MMI_MESSAGE_SMS_HILITE_VIEWER__ */
        
    #ifdef __MMI_MESSAGES_USERDEFINED_TEMPLATE__
        case MENU_ID_SMS_VIEWER_OPT_SAVE_TEMPLATE:
            mmi_sms_viewer_opt_pre_save_as_template();
            break;
	#endif /* __MMI_MESSAGES_USERDEFINED_TEMPLATE__ */
        
        case MENU_ID_SMS_VIEWER_OPT_ADVANCED:
            break; /* no need deal */
        
    #if defined(__MMI_SMS_SET_AS_REMINDER__) && defined(__MMI_TODOLIST__)
        case MENU_ID_SMS_VIEWER_OPT_ADD_TO_CALENDAR:
            mmi_sms_viewer_opt_add_to_calendar(g_sms_gid);
            break;
    #endif
        
    #ifdef __MMI_SMS_DETAILS_INFO__
        case MENU_ID_SMS_VIEWER_OPT_DETAILS:
            mmi_sms_box_list_opt_pre_entry_details();
            break;
    #endif

    #ifdef __MMI_MESSAGES_DRAFT_BOX__
        case MENU_ID_SMS_VIEWER_OPT_SEND:
            mmi_sms_viewer_opt_send();
            break;

        case MENU_ID_SMS_VIEWER_OPT_EDIT:
            mmi_sms_viewer_opt_edit();
            break;
    #endif

    #if (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__))
        case MENU_ID_SMS_VIEWER_OPT_RESEND:
    #if(defined( __MMI_DUAL_SIM_MASTER__) && !defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__))
            {
        #if ((MMI_MAX_SIM_NUM > 2) && !defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__))
            mmi_sms_launch_sim_sel_resend();
        #else
        #ifndef __MMI_BT_MAP_CLIENT__
            if (mmi_sms_get_valid_sim_op_count(srv_nw_usab_is_usable) == 1)
            {
                g_sms_resend_by_local = MMI_TRUE;
                resend_sim_id = SMS_SIM_UNSPECIFIC;
                mmi_sms_viewer_opt_resend();
            }
        #endif
        #endif
            }
    #else /* (defined( __MMI_DUAL_SIM_MASTER__) && !defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__)) */
        #ifndef __MMI_BT_MAP_CLIENT__
            g_sms_resend_by_local = MMI_TRUE;
            mmi_sms_viewer_opt_resend();
        #else
        #ifndef __MMI_TELEPHONY_SUPPORT__
            g_sms_resend_by_local = MMI_FALSE;
            mmi_sms_viewer_opt_resend();
        #endif
        #endif
    #endif
            break;
    #endif

        default:
            break;
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_box_viewer_adv_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_box_viewer_adv_select_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *cui_menu_evt = menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sms_cntx.curr_msg_id = msg_id;

    switch (cui_menu_evt->highlighted_menu_id)
    {
    #ifdef __MMI_MESSAGE_SMS_USE_DETAIL__
        case MENU_ID_SMS_VIEWER_ADV_OPT_USE_NUM:
            mmi_sms_viewer_opt_adv_use_number(); /*????*/
            break;
    #ifdef __MMI_MESSAGES_USE_URL__
        case MENU_ID_SMS_VIEWER_ADV_OPT_USE_URL:
            mmi_sms_viewer_opt_adv_use_url();
            break;
    #endif /* __MMI_MESSAGES_USE_URL__ */
    #if (defined(__MMI_EMAIL__) || defined(__MMI_PHB_OPTIONAL_FIELD__))
        case MENU_ID_SMS_VIEWER_ADV_OPT_USE_EMAIL:
            mmi_sms_viewer_opt_adv_use_email();
            break;
    #endif /* (defined(__MMI_EMAIL__) || defined(__MMI_PHB_OPTIONAL_FIELD__)) */
    #ifndef __MMI_SMS_SLIM__
        case MENU_ID_SMS_VIEWER_ADV_OPT_USE_USSD:
            mmi_sms_viewer_opt_adv_use_ussd();
            break;
            #endif
    #endif /*__MMI_MESSAGE_SMS_USE_DETAIL__*/

    #if defined(__MMI_MESSAGES_COPY__) &&  (!defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || defined(__OP01__) )
        case MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_PHONE:
            mmi_sms_viewer_opt_adv_copy_to_phone();
            break;
        case MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_PHONE:
            mmi_sms_viewer_opt_adv_move_to_phone();
            break;
   #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
        case MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_TCARD:
        mmi_sms_viewer_opt_adv_copy_to_tcard();
        break;
        
        case MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_TCARD:
        mmi_sms_viewer_opt_adv_move_to_tcard();
        break;
#endif /* __MMI_SMS_TCARD_STORAGE_SUPPORT__*/    

#if (defined(__OP01__) && (MMI_MAX_SIM_NUM == 2))
        case MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_SIM1:
            mmi_sms_viewer_opt_adv_copy_to_sim_ext(SRV_SMS_SIM_1);
            break;
        case MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_SIM1:
            mmi_sms_viewer_opt_adv_move_to_sim_ext(SRV_SMS_SIM_1);
            break;

            
        case MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_SIM2:
            mmi_sms_viewer_opt_adv_copy_to_sim_ext(SRV_SMS_SIM_2);
            break;
        case MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_SIM2:
            mmi_sms_viewer_opt_adv_move_to_sim_ext(SRV_SMS_SIM_2);
            break;

#else
        case MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_SIM:
            mmi_sms_viewer_opt_adv_copy_to_sim();
            break;
        case MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_SIM:
            mmi_sms_viewer_opt_adv_move_to_sim();
            break;
#endif
            
    #endif /* defined(__MMI_MESSAGES_COPY__) &&  (!defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || defined(__OP01__) ) */

    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_ARCHIVE:
            mmi_sms_move_sms_to_archive();
            break;
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

    #if defined(__MMI_SMS_APP_EMS_SUPPORT__) && defined(__MMI_MESSAGE_SMS_USE_DETAIL__)
        case MENU_ID_SMS_VIEWER_ADV_OPT_SAVE_OBJ:
            mmi_sms_viewer_opt_adv_save_object(); /*?????????*/
            break;
    #endif /* __MMI_SMS_APP_EMS_SUPPORT__ && __MMI_MESSAGE_SMS_USE_DETAIL__*/

    #ifdef __MMI_BPP20_SUPPORT__
        case MENU_ID_SMS_VIEWER_ADV_OPT_PRINT:
            mmi_sms_viewer_opt_adv_print();
            break;
    #endif /* __MMI_BPP20_SUPPORT__ */

    #ifdef __MMI_MESSAGE_SMS_HILITE_VIEWER__
        case MENU_ID_SMS_VIEWER_ADV_OPT_AUTO_FIND_ON:
            mmi_sms_viewer_auto_find_on();
            break;
        case MENU_ID_SMS_VIEWER_ADV_OPT_AUTO_FIND_OFF:
            mmi_sms_viewer_auto_find_off();
            break;
    #endif /* __MMI_MESSAGE_SMS_HILITE_VIEWER__ */

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_box_viewer_adv_check_hilite_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_box_viewer_adv_check_hilite_setting(MMI_ID menu_gid, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    srv_sms_box_enum curr_box_type;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    srv_sms_get_msg_list_index(&curr_box_type, msg_id);

    if (curr_box_type != SRV_SMS_BOX_SIM)
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    {
    #if defined(__MMI_SMS_APP_EMS_SUPPORT__) && defined(__MMI_MESSAGE_SMS_USE_DETAIL__)
        mmi_sms_check_save_object_menu_item(menu_gid);
    #endif
    }

#ifdef __MMI_MESSAGE_SMS_HILITE_VIEWER__
    if ((g_sms_cntx.curr_msg_status == SMS_STATUS_DELIVERY_REPORT) ||
        (g_sms_cntx.curr_msg_status == SMS_STATUS_PENDING_REPORT) ||
        (g_sms_cntx.curr_msg_status == SMS_STATUS_UNSUPPORT))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_AUTO_FIND_ON, MMI_TRUE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_AUTO_FIND_OFF, MMI_TRUE);
    }
    else
    {
        if (srv_sms_is_highlight_view_setting() == MMI_TRUE)
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_AUTO_FIND_ON, MMI_TRUE);
            cui_menu_set_item_hidden(menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_AUTO_FIND_OFF, MMI_FALSE);
        }
        else
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_AUTO_FIND_ON, MMI_FALSE);
            cui_menu_set_item_hidden(menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_AUTO_FIND_OFF, MMI_TRUE);
        }
    }
#endif /* __MMI_MESSAGE_SMS_HILITE_VIEWER__ */
}


#ifdef __MMI_CLIPBOARD__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_box_viewer_check_edit_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_box_viewer_check_edit_option(cui_menu_event_struct* menu_evt, srv_sms_status_enum curr_msg_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (curr_msg_status & SRV_SMS_STATUS_UNSUPPORTED)
    {
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_EDITOR_OPT_EDIT_OPTIONS, MMI_TRUE);
    }
    else
    {
        /* wgui_inputs_options_menu_handler((mmi_event_struct*)menu_evt, g_sms_gid); */
    }
}
#endif


#ifdef __MMI_MESSAGES_DRAFT_BOX__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_drafts_viewer_opt_entry_hdlr
 * DESCRIPTION
 *  Entry default viewer option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_drafts_viewer_opt_entry_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id)
{
#ifdef __MMI_TELEPHONY_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_status_enum curr_msg_status;
    srv_sms_box_enum curr_box_type;
    MMI_ID cui_menu_gid = menu_evt->sender_id;
    U16 curr_msg_id = msg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_msg_status = srv_sms_get_msg_status(curr_msg_id);
    srv_sms_get_msg_list_index(&curr_box_type, curr_msg_id);

#ifdef __MMI_MESSAGE_SMS_HILITE_VIEWER__
    mmi_sms_check_hilite_item_opt(cui_menu_gid);
#endif /* __MMI_MESSAGE_SMS_HILITE_VIEWER__ */

    if ( g_sms_cntx.curr_msg_status == SMS_STATUS_UNSUPPORT)
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_SEND, MMI_TRUE);
    }
    if (mmi_sms_is_send_enable() != MMI_TRUE )
    {
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        if (srv_sim_ctrl_get_num_of_inserted()==0)
        {
            cui_menu_set_item_disabled(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_SEND, MMI_TRUE);
        }
        else
#endif
        {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_SEND, MMI_TRUE);
        }
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_SEND, MMI_FALSE);
    }

    if (curr_msg_status & SRV_SMS_STATUS_UNSUPPORTED)
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_EDIT, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_EDIT, MMI_FALSE);
    }

#if (defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || !defined(__MMI_MESSAGES_COPY__))
    if (curr_msg_status & SRV_SMS_STATUS_UNSUPPORTED)
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_ADVANCED, MMI_TRUE);
    }
    else
#endif
    {
    #if (defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || !defined(__MMI_MESSAGES_COPY__))
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_ADVANCED, MMI_FALSE);
    #endif
        mmi_sms_check_viewer_adv_detail(cui_menu_gid, curr_msg_id);
        mmi_sms_check_viewer_adv_copy_move(cui_menu_gid, curr_msg_id);
    }

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_ARCHIVE, MMI_TRUE);
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

#if defined(__MMI_SMS_APP_EMS_SUPPORT__) && defined(__MMI_MESSAGE_SMS_USE_DETAIL__)
    cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_SAVE_OBJ, MMI_TRUE);
#endif /* __MMI_SMS_APP_EMS_SUPPORT__ && __MMI_MESSAGE_SMS_USE_DETAIL__ */

#ifdef __MMI_CLIPBOARD__
    mmi_sms_box_viewer_check_edit_option(menu_evt, curr_msg_status);
#endif

#endif/*__MMI_TELEPHONY_SUPPORT__*/
}
#endif /* __MMI_MESSAGES_DRAFT_BOX__*/


#if (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__))
/*****************************************************************************
* FUNCTION
*  mmi_sms_unsent_viewer_opt_entry_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_sms_unsent_viewer_opt_entry_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id)
{
#ifdef __MMI_TELEPHONY_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_status_enum curr_msg_status;
    srv_sms_box_enum curr_box_type;
    MMI_ID cui_menu_gid = menu_evt->sender_id;
    U16 curr_msg_id = msg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_msg_status = srv_sms_get_msg_status(curr_msg_id);
    srv_sms_get_msg_list_index(&curr_box_type, curr_msg_id);

#ifdef __MMI_MESSAGE_SMS_HILITE_VIEWER__
    mmi_sms_check_hilite_item_opt(cui_menu_gid);
#endif /* __MMI_MESSAGE_SMS_HILITE_VIEWER__ */

#if (defined( __MMI_DUAL_SIM_MASTER__) && !defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__))
/* under construction !*/
#endif

    if (curr_msg_status & SRV_SMS_STATUS_UNSUPPORTED)
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_RESEND, MMI_TRUE);
    #ifdef __MMI_BT_MAP_CLIENT__
        return;
    #endif
    }
    else
    {
    #ifdef __MMI_BT_MAP_CLIENT__
        if (mmi_sms_get_valid_sim_op_count(srv_nw_usab_is_usable) == 0 && !srv_bt_mapc_adp_is_connected(mmi_sms_bt_get_active_index()))
        {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_RESEND, MMI_TRUE);
            return;
        }
        else
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_RESEND, MMI_FALSE);
    #else
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_RESEND, MMI_FALSE);
    #endif
    }
#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
    if (mmi_sms_is_send_enable() != MMI_TRUE)
    {
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__        
    #ifdef __MMI_BT_MAP_CLIENT__
        if (srv_sim_ctrl_get_num_of_inserted() == 0 && !srv_bt_mapc_adp_is_connected(mmi_sms_bt_get_active_index()))
        {
            cui_menu_set_item_disabled(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_RESEND, MMI_TRUE);
            return;
        }
        else
    #else
        if (srv_sim_ctrl_get_num_of_inserted()==0)
        {
            cui_menu_set_item_disabled(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_RESEND, MMI_TRUE);
        }
        else
    #endif
#endif
        {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_RESEND, MMI_TRUE);
        }
    }
    else
    {
        cui_menu_set_item_disabled(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_RESEND, MMI_FALSE);
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_RESEND, MMI_FALSE);
    }
#endif
    if (curr_msg_status & SRV_SMS_STATUS_UNSUPPORTED)
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_EDIT, MMI_TRUE);
    #ifdef __MMI_MESSAGES_USERDEFINED_TEMPLATE__
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_SAVE_TEMPLATE, MMI_TRUE);
    #endif /* __MMI_MESSAGES_USERDEFINED_TEMPLATE__ */
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_EDIT, MMI_FALSE);
    #ifdef __MMI_MESSAGES_USERDEFINED_TEMPLATE__
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_SAVE_TEMPLATE, MMI_FALSE);
    #endif /* __MMI_MESSAGES_USERDEFINED_TEMPLATE__ */
    }
    
#if (defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || !defined(__MMI_MESSAGES_COPY__))
    if (curr_msg_status & SRV_SMS_STATUS_UNSUPPORTED)
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_ADVANCED, MMI_TRUE);
    }
    else
#endif
    {
    #if (defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || !defined(__MMI_MESSAGES_COPY__))
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_OPT_ADVANCED, MMI_FALSE);
    #endif
        mmi_sms_check_viewer_adv_detail(cui_menu_gid, curr_msg_id);
        mmi_sms_check_viewer_adv_copy_move(cui_menu_gid, curr_msg_id);
    }

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_ARCHIVE, MMI_TRUE);
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

#if defined(__MMI_SMS_APP_EMS_SUPPORT__) && defined(__MMI_MESSAGE_SMS_USE_DETAIL__)
    cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_SAVE_OBJ, MMI_TRUE);
#endif /* __MMI_SMS_APP_EMS_SUPPORT__ && __MMI_MESSAGE_SMS_USE_DETAIL__ */

#ifdef __MMI_CLIPBOARD__
    mmi_sms_box_viewer_check_edit_option(menu_evt, curr_msg_status);
#endif
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
    cui_menu_set_non_leaf_item(menu_evt->sender_id, MENU_ID_SMS_VIEWER_OPT_RESEND, FALSE);
#endif
#endif /*__MMI_TELEPHONY_SUPPORT__*/
}
#endif /* (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__)) */


#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
/*****************************************************************************
* FUNCTION
*  mmi_sms_simbox_viewer_opt_entry_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_sms_simbox_viewer_opt_entry_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_status_enum curr_msg_status;
    MMI_ID cui_menu_gid = menu_evt->sender_id;
    U16 curr_msg_id = msg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_msg_status = srv_sms_get_msg_status(curr_msg_id);

#ifdef __MMI_MESSAGE_SMS_HILITE_VIEWER__
    mmi_sms_check_hilite_item_opt(cui_menu_gid);
#endif /* __MMI_MESSAGE_SMS_HILITE_VIEWER__ */

#ifdef  __MMI_MESSAGES_COPY__
    cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_PHONE, MMI_FALSE);
    cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_PHONE, MMI_FALSE);
#endif /* __MMI_MESSAGES_COPY__ */

#if !defined(__MMI_MESSAGES_COPY__) && !defined(__MMI_MESSAGE_SMS_HILITE_VIEWER__)
    cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_VIEWER_SIM_OPT_ADVANCED, MMI_TRUE);
#endif /* __MMI_MESSAGES_COPY__ */

#ifdef __MMI_CLIPBOARD__
    mmi_sms_box_viewer_check_edit_option(menu_evt, curr_msg_status);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_simbox_viewer_adv_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_simbox_viewer_adv_select_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *cui_menu_evt = menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sms_cntx.curr_msg_id = msg_id;

    switch (cui_menu_evt->highlighted_menu_id)
    {
    #ifdef __MMI_MESSAGE_SMS_USE_DETAIL__
        case MENU_ID_SMS_VIEWER_ADV_OPT_USE_NUM:
            mmi_sms_viewer_opt_adv_use_number(); /*????*/
            break;
    #ifdef __MMI_MESSAGES_USE_URL__
        case MENU_ID_SMS_VIEWER_ADV_OPT_USE_URL:
            mmi_sms_viewer_opt_adv_use_url();
            break;
    #endif /* __MMI_MESSAGES_USE_URL__ */
    #if (defined(__MMI_EMAIL__) || defined(__MMI_PHB_OPTIONAL_FIELD__))
        case MENU_ID_SMS_VIEWER_ADV_OPT_USE_EMAIL:
            mmi_sms_viewer_opt_adv_use_email();
            break;
    #endif /* (defined(__MMI_EMAIL__) || defined(__MMI_PHB_OPTIONAL_FIELD__)) */
        case MENU_ID_SMS_VIEWER_ADV_OPT_USE_USSD:
            mmi_sms_viewer_opt_adv_use_ussd();
            break;
    #endif /*__MMI_MESSAGE_SMS_USE_DETAIL__*/

    #ifdef __MMI_MESSAGES_COPY__
        case MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_PHONE:
            mmi_sms_viewer_opt_adv_copy_to_phone();
            break;
            
        case MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_PHONE:
            mmi_sms_viewer_opt_adv_move_to_phone();
            break;
            
 #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
        case MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_TCARD:
            mmi_sms_viewer_opt_adv_copy_to_tcard();
            break;
        case MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_TCARD:
            mmi_sms_viewer_opt_adv_move_to_tcard();
            break;         
 #endif
            
    #endif /* __MMI_MESSAGES_COPY__ */

    #ifdef __MMI_MESSAGE_SMS_HILITE_VIEWER__
        case MENU_ID_SMS_VIEWER_ADV_OPT_AUTO_FIND_ON:
            mmi_sms_viewer_auto_find_on();
            break;
        case MENU_ID_SMS_VIEWER_ADV_OPT_AUTO_FIND_OFF:
            mmi_sms_viewer_auto_find_off();
            break;
    #endif /* __MMI_MESSAGE_SMS_HILITE_VIEWER__ */

        default:
            break;
    }
}

#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */


#ifdef __MMI_MESSAGE_SMS_HILITE_VIEWER__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_auto_find_on
 * DESCRIPTION
 *  set sms viewer auto find on
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_auto_find_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_set_highlight_view_setting(MMI_TRUE);

    mmi_sms_display_popup_ext(
        STR_ID_SMS_AUTO_FIND_ON,
        MMI_EVENT_SUCCESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_auto_find_off
 * DESCRIPTION
 *  set sms viewer auto find off
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_viewer_auto_find_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_set_highlight_view_setting(MMI_FALSE);

    mmi_sms_display_popup_ext(
        STR_ID_SMS_AUTO_FIND_OFF,
        MMI_EVENT_SUCCESS);
}
#endif /* __MMI_MESSAGE_SMS_HILITE_VIEWER__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_menu_cui_entry_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_menu_cui_entry_hdlr(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    U16 curr_msg_id = g_sms_cntx.curr_msg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_BOX_MENU_CUI_ENTRY_HDLR, menu_evt->parent_menu_id);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_BOX_MENU_CUI_ENTRY_HDLR_1, curr_msg_id);

    if(cui_menu_is_menu_event(menu_evt->evt_id))
    {
        wgui_inputs_options_menu_handler((mmi_event_struct*)menu_evt, g_sms_gid);
    }

    switch (menu_evt->parent_menu_id)
    {
    #ifndef __UNIFIED_COMPOSER_SUPPORT__
        case MENU_ID_SMS_EDITOR_OPTIONS:
            mmi_sms_editor_opt_entry_hdlr(menu_evt);
            break;

#ifndef __MMI_SMS_SLIM__
        case MENU_ID_SMS_ED_OPT_ADVANCED:
        #ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__ 
            mmi_sms_editor_advanced_entry_hdlr(menu_evt->sender_id);
        #endif
            break;
    #endif
    #endif

#ifndef __MMI_SMS_CLASS0_MSG_SLIM__
        case MENU_ID_SMS_CLSASS0_OPT_SAVE_TO_INBOX:
			{
					#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
									MMI_ID sim_menus[] = {
															MENU_ID_SMS_CLSASS0_OPT_SAVE_TO_INBOX_BY_SIM1, 
															MENU_ID_SMS_CLSASS0_OPT_SAVE_TO_INBOX_BY_SIM2,
					#if (MMI_MAX_SIM_NUM >= 3)
															MENU_ID_SMS_CLSASS0_OPT_SAVE_TO_INBOX_BY_SIM3,
					#if (MMI_MAX_SIM_NUM >= 4)
															MENU_ID_SMS_CLSASS0_OPT_SAVE_TO_INBOX_BY_SIM4,
					#endif /* (MMI_MAX_SIM_NUM >= 4) */
					#endif /* (MMI_MAX_SIM_NUM >= 3) */
																0
															};
									MMI_ID sim_strings[] = {
															STR_ID_SMS_TO_SIM1, 
															STR_ID_SMS_TO_SIM2,
					#if (MMI_MAX_SIM_NUM >= 3)
															STR_ID_SMS_TO_SIM3,
					#if (MMI_MAX_SIM_NUM >= 4)
															STR_ID_SMS_TO_SIM4,
					#endif /* (MMI_MAX_SIM_NUM >= 4) */
					#endif /* (MMI_MAX_SIM_NUM >= 3) */
																0
															};
									mmi_sms_append_sim_name_to_menu_items_and_hide_invalid_sims(menu_evt->sender_id, sim_menus, sim_strings);
					#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
					break;
				}
#endif
        #ifndef __MMI_SMS_SLIM__
        case MENU_ID_SMS_DEFAULT_LIST_OPT:
            mmi_sms_default_list_opt_entry_hdlr(menu_evt, curr_msg_id);
            break;
            #endif
    #if defined(__MMI_VUI_HOMESCREEN__)
        case MENU_ID_SMS_RECENT_LIST_OPT:
            mmi_sms_recent_list_opt_entry_hdlr(menu_evt, curr_msg_id);
            break;
    #endif /* __MMI_VUI_HOMESCREEN__*/
    #ifdef __MMI_MESSAGES_LIST_ADVANCED__
    #if defined(__MMI_MESSAGES_COPY__) &&  (!defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || defined(__OP01__) )
        case MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL:
        case MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL:
        #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
			mmi_sms_check_copy_move_all_options(menu_evt->sender_id, curr_msg_id,menu_evt->parent_menu_id);
		#endif
            cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            break;
    #endif /* defined(__MMI_MESSAGES_COPY__) && !defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) */
    #endif /* __MMI_MESSAGES_LIST_ADVANCED__ */

        case MENU_ID_SMS_DEFAULT_VIEWER_OPT:
            mmi_sms_default_viewer_opt_entry_hdlr(menu_evt, curr_msg_id);
            break;
#if (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__))
        case MENU_ID_SMS_VIEWER_OPT_RESEND:
            {
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                MMI_ID sim_menus[] = {
                                        MENU_ID_SMS_VIEWER_OPT_RESEND_BY_SIM1, 
                                        MENU_ID_SMS_VIEWER_OPT_RESEND_BY_SIM2,
#if (MMI_MAX_SIM_NUM >= 3)
                                        MENU_ID_SMS_VIEWER_OPT_RESEND_BY_SIM3,
#if (MMI_MAX_SIM_NUM >= 4)
                                        MENU_ID_SMS_VIEWER_OPT_RESEND_BY_SIM4,
#endif /* (MMI_MAX_SIM_NUM >= 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#ifdef __MMI_BT_MAP_CLIENT__
                                        MENU_ID_SMS_VIEWER_OPT_RESEND_BY_BT,
                                        #if (BT_MAX_LINK_NUM > 1)
                                        MENU_ID_SMS_VIEWER_OPT_RESEND_BY_BT2,
                                        #endif /* (BT_MAX_LINK_NUM > 1) */
#endif
                                            0
                                        };
                MMI_ID sim_strings[] = {
                                        STR_ID_SMS_BY_SIM1, 
                                        STR_ID_SMS_BY_SIM2,
#if (MMI_MAX_SIM_NUM >= 3)
                                        STR_ID_SMS_BY_SIM3,
#if (MMI_MAX_SIM_NUM >= 4)
                                        STR_ID_SMS_BY_SIM4,
#endif /* (MMI_MAX_SIM_NUM >= 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#ifdef __MMI_BT_MAP_CLIENT__
                                        STR_ID_SMS_SEND_BY_BT,
                                        #if (BT_MAX_LINK_NUM > 1)
                                        STR_ID_SMS_SEND_BY_BT2,
                                        #endif /* (BT_MAX_LINK_NUM > 1) */                                      
#endif
                                            0
                                        };
                mmi_sms_append_sim_name_to_menu_items_and_hide_invalid_sims(menu_evt->sender_id, sim_menus, sim_strings);
            #ifdef __MMI_BT_MAP_CLIENT__
                if (!srv_bt_mapc_adp_is_connected(SRV_SMS_BTMAPC_BT_INDEX0))
                    cui_menu_set_item_disabled(menu_evt->sender_id, MENU_ID_SMS_VIEWER_OPT_RESEND_BY_BT, MMI_TRUE);
                #if (BT_MAX_LINK_NUM > 1)
                if (!srv_bt_mapc_adp_is_connected(SRV_SMS_BTMAPC_BT_INDEX1))
                    cui_menu_set_item_disabled(menu_evt->sender_id, MENU_ID_SMS_VIEWER_OPT_RESEND_BY_BT2, MMI_TRUE);
                #endif /* (BT_MAX_LINK_NUM > 1) */
            #endif
#else /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
    #ifdef __MMI_BT_MAP_CLIENT__
            #ifdef __MMI_TELEPHONY_SUPPORT__
                if (!srv_bt_mapc_adp_is_connected(SRV_SMS_BTMAPC_BT_INDEX0))
                {
                    cui_menu_set_item_disabled(menu_evt->sender_id, MENU_ID_SMS_VIEWER_OPT_RESEND_BY_BT, MMI_TRUE);
                }
                #if (BT_MAX_LINK_NUM > 1)
                if (!srv_bt_mapc_adp_is_connected(SRV_SMS_BTMAPC_BT_INDEX1))
                {
                    cui_menu_set_item_disabled(menu_evt->sender_id, MENU_ID_SMS_VIEWER_OPT_RESEND_BY_BT2, MMI_TRUE);
                }
                #endif /* (BT_MAX_LINK_NUM > 1) */
                if (!srv_sim_ctrl_is_available(MMI_SIM1)||
                    !srv_mode_switch_is_network_service_available())
                {
                    cui_menu_set_item_disabled(menu_evt->sender_id, MENU_ID_SMS_VIEWER_OPT_RESEND_BY_SIM1, MMI_TRUE);
                }
            #if (MMI_MAX_SIM_NUM >= 2)
                if (!srv_sim_ctrl_is_available(MMI_SIM2)||
                    !srv_mode_switch_is_network_service_available())
                    cui_menu_set_item_disabled(menu_evt->sender_id, MENU_ID_SMS_VIEWER_OPT_RESEND_BY_SIM2, MMI_TRUE);
                
            #if (MMI_MAX_SIM_NUM >= 3)
                if (!srv_sim_ctrl_is_available(MMI_SIM3)||
                    !srv_mode_switch_is_network_service_available())
                    cui_menu_set_item_disabled(menu_evt->sender_id, MENU_ID_SMS_VIEWER_OPT_RESEND_BY_SIM3, MMI_TRUE);
                    
            #if (MMI_MAX_SIM_NUM >= 4)
                if (!srv_sim_ctrl_is_available(MMI_SIM4)||
                    !srv_mode_switch_is_network_service_available())
                    cui_menu_set_item_disabled(menu_evt->sender_id, MENU_ID_SMS_VIEWER_OPT_RESEND_BY_SIM4, MMI_TRUE);
            #endif
            #endif
            #endif
            #endif/*__MMI_TELEPHONY_SUPPORT__*/
                
    #endif
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
            }
#endif /* (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__)) */
        case MENU_ID_SMS_INBOX_VIEWER_OPT:
            mmi_sms_inbox_viewer_opt_entry_hdlr(menu_evt, curr_msg_id);
            break;

    #ifdef __MMI_MESSAGES_DRAFT_BOX__
        case MENU_ID_SMS_DRAFTS_VIEWER_OPT:
            mmi_sms_drafts_viewer_opt_entry_hdlr(menu_evt, curr_msg_id);
            break;

    #ifndef __UNIFIED_COMPOSER_SUPPORT__
    #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        case MENU_ID_SMS_ED_OPT_SAVE_TO_DRAFTS:
            {
                MMI_ID sim_menus[] = {
                                        MENU_ID_SMS_ED_OPT_SAVE_TO_DRAFTS_BY_SIM1, 
                                        MENU_ID_SMS_ED_OPT_SAVE_TO_DRAFTS_BY_SIM2,
        #if (MMI_MAX_SIM_NUM >= 3)
                                        MENU_ID_SMS_ED_OPT_SAVE_TO_DRAFTS_BY_SIM3,
        #if (MMI_MAX_SIM_NUM >= 4)
                                        MENU_ID_SMS_ED_OPT_SAVE_TO_DRAFTS_BY_SIM4,
        #endif /* (MMI_MAX_SIM_NUM >= 4) */
        #endif /* (MMI_MAX_SIM_NUM >= 3) */
                                            0
                                        };
                MMI_ID sim_strings[] = {
                                        STR_ID_SMS_TO_SIM1, 
                                        STR_ID_SMS_TO_SIM2,
        #if (MMI_MAX_SIM_NUM >= 3)
                                        STR_ID_SMS_TO_SIM3,
        #if (MMI_MAX_SIM_NUM >= 4)
                                        STR_ID_SMS_TO_SIM4,
        #endif /* (MMI_MAX_SIM_NUM >= 4) */
        #endif /* (MMI_MAX_SIM_NUM >= 3) */
                                            0
                                        };
                mmi_sms_append_sim_name_to_menu_items_and_hide_invalid_sims(menu_evt->sender_id, sim_menus, sim_strings);
            }
            break;
    #endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
    #endif /* __UNIFIED_COMPOSER_SUPPORT__ */
    #endif /* __MMI_MESSAGES_DRAFT_BOX__*/

    #if (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__))
        case MENU_ID_SMS_UNSENT_VIEWER_OPT:
            mmi_sms_unsent_viewer_opt_entry_hdlr(menu_evt, curr_msg_id);
            break;
    #endif /* (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__)) */
    
        case MENU_ID_SMS_SENT_VIEWER_OPT:
            mmi_sms_sent_viewer_opt_entry_hdlr(menu_evt, curr_msg_id);
            break;
    
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case MENU_ID_SMS_SIM_VIEWER_OPT:
            mmi_sms_simbox_viewer_opt_entry_hdlr(menu_evt, curr_msg_id);
            break;
        case MENU_ID_SMS_VIEWER_SIM_OPT_ADVANCED:
            mmi_sms_box_viewer_adv_check_hilite_setting(menu_evt->sender_id, curr_msg_id);
            break;/* parent menu entry have deal other menu ??? double check */
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

        case MENU_ID_SMS_VIEWER_OPT_ADVANCED:
            mmi_sms_box_viewer_adv_check_hilite_setting(menu_evt->sender_id, curr_msg_id);
            break; /* parent menu entry have deal other menu ??? double check */
#ifndef __MMI_SMS_CLASS0_MSG_SLIM__
        case SMS_CLASS0_OPT_MENUID:
            mmi_sms_class0_opt_entry_hdlr(menu_evt);
            break;
#endif
        default:
            break;
    }
}

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_update_storage_filter_settings
 * DESCRIPTION
 *  mmi_sms_update_storage_filter_settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_update_storage_filter_settings(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
		srv_sms_filter_enum curr_filter;
	/*----------------------------------------------------------------*/
    /*Code body                                              */
    /*----------------------------------------------------------------*/
		srv_sms_set_prefer_storage(SRV_SMS_STORAGE_ME, SRV_SMS_SIM_1);
		curr_filter = srv_sms_get_storage_filter();
		if(!(curr_filter & SRV_SMS_FILTER_ME))
		{
			curr_filter |= SRV_SMS_FILTER_ME;
			srv_sms_set_storage_filter(curr_filter);
		}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pref_storage_unavail_yes
 * DESCRIPTION
 *  mmi_msg_pref_storage_unavail_yes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pref_storage_unavail_yes(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /*Code body                                              */
    /*----------------------------------------------------------------*/
	/*need to update the prefer storage as well as filter settings*/
	mmi_sms_update_storage_filter_settings();
	mmi_sms_ed_opt_save_to_drafts(g_sms_gid,g_sms_cntx.tcard_sim_id);
	g_sms_cntx.tcard_sim_id = SRV_SMS_SIM_TOTAL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pref_storage_unavail_no
 * DESCRIPTION
 *  mmi_msg_pref_storage_unavail_no
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pref_storage_unavail_no(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /*Code body                                              */
    /*----------------------------------------------------------------*/
	g_sms_cntx.tcard_sim_id = SRV_SMS_SIM_TOTAL;
	mmi_frm_scrn_close_active_id();
}

#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_menu_cui_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_menu_cui_select_hdlr(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    #if (defined(__MMI_BT_MAP_CLIENT__) && !defined(__MMI_TELEPHONY_SUPPORT__))
    U16 curr_msg_id = g_sms_bt_cntx.curr_msg_id;
    #else
    U16 curr_msg_id = g_sms_cntx.curr_msg_id;
    #endif
    mmi_menu_id highlighted_menu_id = menu_evt->highlighted_menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_BOX_MENU_CUI_SELECT_HDLR, menu_evt->parent_menu_id);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_BOX_MENU_CUI_SELECT_HDLR_1, highlighted_menu_id);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_BOX_MENU_CUI_SELECT_HDLR_2, curr_msg_id);

    switch (menu_evt->parent_menu_id)
    {
    #ifndef __UNIFIED_COMPOSER_SUPPORT__
        case MENU_ID_SMS_EDITOR_OPTIONS:
            mmi_sms_editor_opt_select_hdlr(evt);
            break;
        
//   #ifndef __MMI_SMS_SLIM__     
        case MENU_ID_SMS_ED_OPT_ADVANCED:
            mmi_sms_editor_advanced_select_hdlr(evt);
            break;
//   #endif
    #endif /* __UNIFIED_COMPOSER_SUPPORT__ */

         #ifndef __MMI_SMS_SLIM__
            case MENU_ID_SMS_DEFAULT_LIST_OPT:
            mmi_sms_default_list_opt_select_hdlr(menu_evt, curr_msg_id);
            break;
         #endif
    #if defined(__MMI_VUI_HOMESCREEN__)
        case MENU_ID_SMS_RECENT_LIST_OPT:
            mmi_sms_recent_list_opt_select_hdlr(menu_evt, curr_msg_id);
            break;
    #endif /* __MMI_VUI_HOMESCREEN__*/
    #ifdef __MMI_MESSAGES_LIST_ADVANCED__
    #if defined(__MMI_MESSAGES_COPY__) &&  (!defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || defined(__OP01__) )
        case MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL:
            mmi_sms_list_opt_copy_all_select_hdlr(menu_evt, curr_msg_id);
            break;
        case MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL:
            mmi_sms_list_opt_move_all_select_hdlr(menu_evt, curr_msg_id);
            break;
    #endif /* defined(__MMI_MESSAGES_COPY__) && !defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) */
    #endif /* __MMI_MESSAGES_LIST_ADVANCED__ */

        case MENU_ID_SMS_INBOX_VIEWER_OPT:
        case MENU_ID_SMS_SENT_VIEWER_OPT:
    #ifdef __MMI_MESSAGES_DRAFT_BOX__
        case MENU_ID_SMS_DRAFTS_VIEWER_OPT:
    #endif
    #if (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__))
        case MENU_ID_SMS_UNSENT_VIEWER_OPT:
    #endif
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case MENU_ID_SMS_SIM_VIEWER_OPT:
    #endif
        case MENU_ID_SMS_DEFAULT_VIEWER_OPT:
    #ifdef __MMI_TELEPHONY_SUPPORT__
            mmi_sms_default_viewer_opt_select_hdlr(menu_evt, curr_msg_id);
    #endif
            break;

    #if (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__))
        case MENU_ID_SMS_VIEWER_OPT_RESEND:
        #ifdef __MMI_BT_MAP_CLIENT__
        #ifdef __MMI_TELEPHONY_SUPPORT__
            if (MENU_ID_SMS_VIEWER_OPT_RESEND_BY_SIM1 == highlighted_menu_id)
            {
        #if (defined( __MMI_DUAL_SIM_MASTER__) && !defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__))
/* under construction !*/
        #endif
                g_sms_resend_by_local = MMI_TRUE;
            }
        #endif
        #else
        #if (defined( __MMI_DUAL_SIM_MASTER__) && !defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        #endif
    #if (defined( __MMI_DUAL_SIM_MASTER__) && !defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* (MMI_MAX_SIM_NUM >= 3) */
        #endif /* (MMI_MAX_SIM_NUM >= 4) */
    #endif /* (defined( __MMI_DUAL_SIM_MASTER__) && !defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__)) */
        #ifdef __MMI_BT_MAP_CLIENT__
        #ifdef __MMI_TELEPHONY_SUPPORT__
            else 
            if (MENU_ID_SMS_VIEWER_OPT_RESEND_BY_BT == highlighted_menu_id)
            {
    #if (defined( __MMI_DUAL_SIM_MASTER__) && !defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__))
/* under construction !*/
    #endif
                g_sms_resend_by_local = MMI_FALSE;
            }

            #if (BT_MAX_LINK_NUM > 1)
            else if (MENU_ID_SMS_VIEWER_OPT_RESEND_BY_BT2 == highlighted_menu_id)
	    {
    #if (defined( __MMI_DUAL_SIM_MASTER__) && !defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__))
/* under construction !*/
    #endif
		g_sms_resend_by_local = MMI_FALSE;
	     }
            #endif /* (BT_MAX_LINK_NUM > 1) */
        #endif
            cui_sms_set_send_cui_need_device_menu(MMI_FALSE);
            cui_sms_set_send_by_local(g_sms_resend_by_local);
        #endif
            mmi_sms_viewer_opt_resend();
            break;
    #endif /* (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__)) */

    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case MENU_ID_SMS_VIEWER_SIM_OPT_ADVANCED:
            mmi_sms_simbox_viewer_adv_select_hdlr(menu_evt, curr_msg_id);
            break;
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

        case MENU_ID_SMS_VIEWER_OPT_ADVANCED:
            mmi_sms_box_viewer_adv_select_hdlr(menu_evt, curr_msg_id);
            break;
#ifndef __MMI_SMS_CLASS0_MSG_SLIM__
        case SMS_CLASS0_OPT_MENUID:
            mmi_sms_class0_opt_select_hdlr(evt);
            break;
#endif
    #ifdef __MMI_DUAL_SIM_MASTER__
#ifndef __MMI_SMS_CLASS0_MSG_SLIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    #ifndef __UNIFIED_COMPOSER_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
	 #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
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
  #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    #endif /* __MMI_DUAL_SIM_MASTER__ */

		#ifndef __MMI_SMS_SLIM__
		case MENU_ID_SMS_LIST_OPT_VIEW:
                 #if defined(__MMI_LANG_ZAWGYI_MYANMAR__) && defined(__MMI_LANG_MYANMAR__)
			                   mmi_sms_box_list_opt_pre_view_for_zawgyi(evt);
                 #else
                         mmi_sms_box_list_opt_pre_view();
                 #endif
			 break;
			 #endif
        default:
            break;
    }

    if(cui_menu_is_menu_event(menu_evt->evt_id))
    {
        wgui_inputs_options_menu_handler((mmi_event_struct*)menu_evt, g_sms_gid);
    }
}


 #ifndef __MMI_SMS_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_box_list_opt_is_create_group
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_sms_box_list_opt_is_create_group(MMI_MENU_ID highlighted_menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (highlighted_menu_id)
    {
        case MENU_ID_SMS_LIST_OPT_CALL_SENDER:
            result = MMI_FALSE;
            break;

    #ifdef __MMI_MESSAGES_LIST_ADVANCED__
        case MENU_ID_SMS_LIST_OPT_ADVANCED:
            result = MMI_FALSE;
            break;
    #endif /* __MMI_MESSAGES_LIST_ADVANCED__ */

    #if (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__))
    #if ((MMI_MAX_SIM_NUM >= 2) && !defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__))
        case MENU_ID_SMS_LIST_OPT_RESEND:
        {
            if ((mmi_sms_get_valid_sim_op_count(srv_nw_usab_is_usable) > 1))
            {
                result = MMI_FALSE;
            }
        }
        break;
    #endif /* ((MMI_MAX_SIM_NUM >= 2) && !defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__)) */
    #endif /* (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__)) */

        default:
            break;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_box_list_opt_cb_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_box_list_opt_cb_hdlr(MMI_ID parent_gid, mmi_event_struct *evt, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    U16 curr_msg_id = (U16)msg_id;
    mmi_menu_id highlighted_menu_id = menu_evt->highlighted_menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_UM_BOX_CB_HDLR, parent_gid);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_UM_BOX_CB_HDLR_1, menu_evt->parent_menu_id);

    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            switch (menu_evt->parent_menu_id)
            {
                case MENU_ID_SMS_DEFAULT_LIST_OPT:
                    mmi_sms_default_list_opt_entry_hdlr(menu_evt, curr_msg_id);
                    break;

                case MENU_ID_SMS_INBOX_LIST_OPT:
                    mmi_sms_inbox_list_opt_entry_hdlr(menu_evt, curr_msg_id);
                    break;

            #ifdef __MMI_MESSAGES_DRAFT_BOX__
                case MENU_ID_SMS_DRAFTS_LIST_OPT:
                    mmi_sms_drafts_list_opt_entry_hdlr(menu_evt, curr_msg_id);
                    break;
            #endif /* __MMI_MESSAGES_DRAFT_BOX__ */

            #if (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__))
                case MENU_ID_SMS_UNSENT_LIST_OPT:
                    mmi_sms_unsent_list_opt_entry_hdlr(menu_evt, curr_msg_id);
                    break;
            #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                case MENU_ID_SMS_LIST_OPT_RESEND:
                {
                    MMI_ID sim_menus[] = {
                                            MENU_ID_SMS_LIST_OPT_RESEND_BY_SIM1, 
                                            MENU_ID_SMS_LIST_OPT_RESEND_BY_SIM2,
                            #if (MMI_MAX_SIM_NUM >= 3)
                                            MENU_ID_SMS_LIST_OPT_RESEND_BY_SIM3,
                            #if (MMI_MAX_SIM_NUM >= 4)
                                            MENU_ID_SMS_LIST_OPT_RESEND_BY_SIM4,
                            #endif /* (MMI_MAX_SIM_NUM >= 4) */
                            #endif /* (MMI_MAX_SIM_NUM >= 3) */
                                                0
                                            };
                
                    MMI_ID sim_strings[] = {
                                            STR_ID_SMS_BY_SIM1, 
                                            STR_ID_SMS_BY_SIM2,
                            #if (MMI_MAX_SIM_NUM >= 3)
                                            STR_ID_SMS_BY_SIM3,
                            #if (MMI_MAX_SIM_NUM >= 4)
                                            STR_ID_SMS_BY_SIM4,
                            #endif /* (MMI_MAX_SIM_NUM >= 4) */
                            #endif /* (MMI_MAX_SIM_NUM >= 3) */
                                                0
                                            };
                    mmi_sms_append_sim_name_to_menu_items_and_hide_invalid_sims(menu_evt->sender_id, sim_menus, sim_strings);
                }
            #endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
            #endif /* (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__)) */

                case MENU_ID_SMS_SENT_LIST_OPT:
                    mmi_sms_sent_list_opt_entry_hdlr(menu_evt, curr_msg_id);
                    break;

            #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
                case MENU_ID_SMS_SIM_LIST_OPT:
                    mmi_sms_simbox_list_opt_entry_hdlr(menu_evt, curr_msg_id);
                    break;
            #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

            #ifdef __MMI_MESSAGES_LIST_ADVANCED__
                case MENU_ID_SMS_LIST_OPT_ADVANCED:
                    cui_menu_set_default_title_string_by_id(menu_evt->sender_id, STR_GLOBAL_ADVANCED);
                    break;
            #endif /* __MMI_MESSAGES_LIST_ADVANCED__ */

            #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
                case MENU_ID_SMS_UNSENT_LIST_OPT:
                    mmi_sms_bg_list_opt_entry_hdlr(menu_evt, curr_msg_id);
                    break;
            #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

            #ifdef __MMI_UM_REPORT_BOX__
                case MENU_ID_SMS_REPORT_LIST_OPT:
            #endif /* __MMI_UM_REPORT_BOX__ */
                default:
                    break;
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_UM_BOX_CB_HDLR_2, highlighted_menu_id);

            if (mmi_sms_box_list_opt_is_create_group(highlighted_menu_id))
            {
                mmi_sms_group_entry(parent_gid);
            }

            mmi_sms_um_set_sms_context(curr_msg_id);
            g_sms_cntx.user_data = evt->user_data;
            g_sms_cntx.is_from_hs = MMI_FALSE;

            switch (menu_evt->parent_menu_id)
            {
                case MENU_ID_SMS_DEFAULT_LIST_OPT:
                case MENU_ID_SMS_INBOX_LIST_OPT:
            #ifdef __MMI_MESSAGES_DRAFT_BOX__ 
                case MENU_ID_SMS_DRAFTS_LIST_OPT:
            #endif /* __MMI_MESSAGES_DRAFT_BOX__ */
            #if (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__))
                case MENU_ID_SMS_UNSENT_LIST_OPT:
            #endif
                case MENU_ID_SMS_SENT_LIST_OPT:
            #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
                case MENU_ID_SMS_SIM_LIST_OPT:
            #endif
            #ifdef __MMI_TELEPHONY_SUPPORT__
                    mmi_sms_default_list_opt_select_hdlr(menu_evt, curr_msg_id);
            #endif/*__MMI_TELEPHONY_SUPPORT__*/
                    break;

            #if (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__))
            #if (MMI_MAX_SIM_NUM >= 2)
                case MENU_ID_SMS_LIST_OPT_RESEND:
                    if (MENU_ID_SMS_LIST_OPT_RESEND_BY_SIM1 == highlighted_menu_id)
                    {
                        resend_sim_id = SMS_SIM_1;
                    }
                    else if (MENU_ID_SMS_LIST_OPT_RESEND_BY_SIM2 == highlighted_menu_id)
                    {
                        resend_sim_id = SMS_SIM_2;
                    }
            #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
            #if (MMI_MAX_SIM_NUM >= 3)
                    else if (MENU_ID_SMS_LIST_OPT_RESEND_BY_SIM3 == highlighted_menu_id)
                    {
                        resend_sim_id = SMS_SIM_3;
                    }
            #if (MMI_MAX_SIM_NUM >= 4)
                    else if (MENU_ID_SMS_LIST_OPT_RESEND_BY_SIM4 == highlighted_menu_id)
                    {
                        resend_sim_id = SMS_SIM_4;
                    }
            #endif /* 4 */
            #endif /* 3 */
            #endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
                    mmi_sms_box_list_opt_pre_resend();
                    break;
            #endif /* 2 */
            #endif /* (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__)) */

            #ifdef __MMI_MESSAGES_LIST_ADVANCED__
                case MENU_ID_SMS_LIST_OPT_ADVANCED:
                    mmi_sms_box_list_adv_select_hdlr(menu_evt, curr_msg_id);
                    break;
            #endif /* __MMI_MESSAGES_LIST_ADVANCED__ */

            #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
                case MENU_ID_SMS_UNSENT_LIST_OPT:
                    mmi_sms_bg_list_opt_select_hdlr(menu_evt, curr_msg_id);
                    break;
            #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

            #ifdef __MMI_UM_REPORT_BOX__
                case MENU_ID_SMS_REPORT_LIST_OPT:
                    mmi_sms_report_list_opt_select_hdlr(menu_evt, curr_msg_id);
                    break;
            #endif /* __MMI_UM_REPORT_BOX__ */

                default:
                    break;
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            {
            #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_UM_DEL_ALL_OPT, MMI_FALSE);
            #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
            }
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_group_entry_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_sms_group_entry_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_INACTIVE:
            if (!mmi_frm_scrn_get_count(g_sms_gid))
            {
                mmi_frm_group_close(g_sms_gid);
            }
            break;

        case EVT_ID_GROUP_DEINIT:
            g_sms_gid = GRP_ID_INVALID;
            g_sms_parent_gid = GRP_ID_ROOT;
        #ifdef __ATV_SMS_SUPPORT__
            ReleaseEMSEditBuffer();
            ReleaseEMSViewBuffer();
        #endif /*__ATV_SMS_SUPPORT__*/
            break;

        case EVT_ID_CUI_MENU_ITEM_HILITE:
            break;

        case EVT_ID_CUI_MENU_LIST_ENTRY:
            mmi_sms_menu_cui_entry_hdlr(evt);
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_sms_menu_cui_select_hdlr(evt);
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            {
                cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
                cui_menu_close(menu_evt->sender_id);
            }
            break;

    #ifndef __UNIFIED_COMPOSER_SUPPORT__
    #ifdef __MMI_MESSAGES_TEMPLATE__
        case EVT_ID_CUI_SMS_TEMPLATE_LIST:
            mmi_sms_ed_insert_template_hdlr(evt);
            break;
    #endif /* __MMI_MESSAGES_TEMPLATE__ */
    #endif

    #if defined(__MMI_SMS_SET_AS_REMINDER__) && defined(__MMI_TODOLIST__)
        case EVT_ID_TDL_SAVE_SUCCESS:
        case EVT_ID_TDL_SAVE_CANCEL:
        case EVT_ID_TDL_SAVE_FAIL:
            {
                mmi_group_event_struct *group_evt = (mmi_group_event_struct*)evt;
                cui_cal_save_close(group_evt->sender_id);
            }
            break;
    #endif

    #ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__ 
    #ifndef __UNIFIED_COMPOSER_SUPPORT__
        case EVT_ID_CUI_BKM_SEL_BKM_RESULT:
            {
                cui_bkm_sel_bkm_result_evt_struct *bkm_evt = (cui_bkm_sel_bkm_result_evt_struct*)evt;
                if (bkm_evt->selected_utf8_url != NULL)
                {
                    mmi_sms_handle_select_bookmark_rsp(bkm_evt->selected_utf8_url);
                }
                cui_bkm_sel_bkm_close(bkm_evt->sender_id);
            }
            break;
    #endif /* __UNIFIED_COMPOSER_SUPPORT__ */
    #if !defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMI_MESSAGES_USE_URL__)
        case EVT_ID_CUI_BKM_ADD_BKM_CLOSE:
            {
                mmi_group_event_struct *group_evt = (mmi_group_event_struct*)evt;
            #if !defined(__UNIFIED_COMPOSER_SUPPORT__)
                if (mmi_frm_scrn_is_present(g_sms_gid, SCR_ID_SMS_EDITOR, MMI_FRM_NODE_ALL_FLAG))
                {
                    cui_bkm_sel_bkm_close(group_evt->sender_id);
                }
                else
            #endif
                {
                    cui_bkm_add_bkm_close(group_evt->sender_id);
                }
            }
            break;
    #endif
    #endif /* __MMI_BRW_BKM_INTERFACE_SUPPORT__  */

        #if (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__))
        #if (MMI_MAX_SIM_NUM >= 3)
        /* SIM selector event */
        case EVT_ID_CUI_SIM_SEL_RESULT:
        {
            cui_sim_sel_result_event_struct* sim_sel_evt = NULL;
            sim_sel_evt = (cui_sim_sel_result_event_struct*)evt;
				
            if (sim_sel_evt->result == CUI_SIM_SEL_OK)
            {
                switch (sim_sel_evt->sim_id)
                {			
                    case MMI_SIM1:
                        resend_sim_id = SMS_SIM_1;
                        g_sms_resend_by_local = MMI_TRUE;
                        break;

                    case MMI_SIM2:
                        resend_sim_id = SMS_SIM_2;
                        g_sms_resend_by_local = MMI_TRUE;
                        break;

                    case MMI_SIM3:
                        resend_sim_id = SMS_SIM_3;
                        g_sms_resend_by_local = MMI_TRUE;
                        break;

                #if (MMI_MAX_SIM_NUM >= 4)
                    case MMI_SIM4:
                        resend_sim_id = SMS_SIM_4;
                        g_sms_resend_by_local = MMI_TRUE;
                        break;						  
                #endif

                    default:
                        MMI_ASSERT(0);
                        break;
                }

                mmi_sms_box_list_opt_pre_resend();
            }
            cui_sim_sel_close(sim_sel_evt->sender_id);
        }
        break;
        #endif
        #endif /* (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__)) */

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_group_entry
 * DESCRIPTION
 *  SMS initiate a group id and enter into this group
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_ID mmi_sms_group_entry(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_GROUP_ENTRY, parent_gid);

    if (parent_gid == GRP_ID_INVALID)
    {
        return GRP_ID_INVALID;
    }

    g_sms_parent_gid = parent_gid;

    if (g_sms_gid != GRP_ID_INVALID)
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_GROUP_ENTRY_1, g_sms_gid);

        mmi_frm_group_close(g_sms_gid);
    }

    g_sms_gid = mmi_frm_group_create_ex(
        parent_gid,
        GRP_ID_AUTO_GEN,
        mmi_sms_group_entry_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_GROUP_ENTRY_2, g_sms_gid);

    return g_sms_gid;
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_write_launch
 * DESCRIPTION
 *  Launch write new SMS, entry SMS editor 
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_ID cui_sms_write_launch(mmi_id parent_grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_UNIFIED_COMPOSER__
    if ( (g_sms_gid != GRP_ID_INVALID) && /* SMS group exists */
        mmi_frm_scrn_is_present(g_sms_gid, SCR_ID_SMS_EDITOR, MMI_FRM_NODE_ALL_FLAG)) /* SMS editor exsits */
    {
        mmi_frm_group_close(g_sms_gid);
        mmi_sms_display_popup(
            (UI_string_type)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE),
            MMI_EVENT_FAILURE);
        return GRP_ID_INVALID;
    }

    mmi_sms_group_entry(parent_grp_id);

    ReleaseEMSEditBuffer();

    mmi_sms_reset_recipient_data();
    mmi_sms_set_send_msg_case(SMS_SEND_CASE_WRITE_NEW_MSG);

#ifdef __MMI_MESSAGES_SMS_EMAIL__
    mmi_sms_set_send_type(SMS_MSG_TYPE_TEXT);
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */

    mmi_sms_pre_entry_editor();

    return g_sms_gid;
#else
    return GRP_ID_INVALID;
#endif
}


#ifdef __MMI_UM_REPORT_BOX__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_report_list_opt_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_report_list_opt_select_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *cui_menu_evt = menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sms_cntx.curr_msg_id = msg_id;

    switch (cui_menu_evt->highlighted_menu_id)
    {
        case MENU_ID_SMS_REPORT_OPT_CALL:
        {
            mmi_frm_group_close(g_sms_gid);
            mmi_sms_entry_call_sender();                        
            break;
        }

        case MENU_ID_SMS_LIST_OPT_DELETE:
        {
            mmi_sms_report_list_opt_pre_delete();
            break;
        }

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_report_list_opt_pre_delete
 * DESCRIPTION
 *  Pre entry list option item: delete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_report_list_opt_pre_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_entry_confirm(
        g_sms_gid,
        STR_GLOBAL_DELETE_ASK,
        mmi_sms_report_list_opt_delete,
        mmi_frm_scrn_close_active_id,
        MMI_TRUE);   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_report_list_opt_delete
 * DESCRIPTION
 *  Pre entry list option item: delete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_report_list_opt_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 report_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    report_id = srv_sms_msg_id_to_report_id(g_sms_cntx.curr_msg_id);

    srv_sms_delete_status_report(report_id);

    g_sms_cntx.curr_msg_id = SRV_SMS_INVALID_MSG_ID;

    mmi_popup_display_ext(
        STR_GLOBAL_DELETED,
        MMI_EVENT_SUCCESS,
        NULL); 
}
#endif /* __MMI_UM_REPORT_BOX__ */

#ifdef __MMI_MESSAGES_LIST_ADVANCED__
 #if defined(__MMI_MESSAGES_COPY__) &&  (!defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || defined(__OP01__) )
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_check_copy_move_all_options
 * DESCRIPTION
 *  mmi_sms_check_copy_move_all_options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
void mmi_sms_check_copy_move_all_options(MMI_ID menu_gid, U16 msg_id, mmi_menu_id parent_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(parent_id == MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL)
	{
	 if (srv_fmgr_drv_is_accessible(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE)))
	{
		cui_menu_set_item_disabled(menu_gid, MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL_FROM_PHONE_TO_TCARD, MMI_FALSE);
		cui_menu_set_item_disabled(menu_gid, MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL_FROM_TCARD_TO_PHONE, MMI_FALSE);
		cui_menu_set_item_disabled(menu_gid, MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL_FROM_SIM_TO_TCARD, MMI_FALSE);
		cui_menu_set_item_disabled(menu_gid, MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL_FROM_TCARD_TO_SIM, MMI_FALSE);
								{
							#ifdef __MMI_DUAL_SIM_MASTER__
						#if(!defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || defined(__OP01__) )
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
						#endif
			#endif
					}
	}
	else
	{
		cui_menu_set_item_disabled(menu_gid, MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL_FROM_PHONE_TO_TCARD, MMI_TRUE);
		cui_menu_set_item_disabled(menu_gid, MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL_FROM_TCARD_TO_PHONE, MMI_TRUE);
		cui_menu_set_item_disabled(menu_gid, MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL_FROM_SIM_TO_TCARD, MMI_TRUE);
		cui_menu_set_item_disabled(menu_gid, MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL_FROM_TCARD_TO_SIM, MMI_TRUE);	
	}
					
}
	if(parent_id == MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL)
	{
					 if (srv_fmgr_drv_is_accessible(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE)))
					{
						cui_menu_set_item_disabled(menu_gid, MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL_FROM_PHONE_TO_TCARD, MMI_FALSE);
						cui_menu_set_item_disabled(menu_gid, MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL_FROM_TCARD_TO_PHONE, MMI_FALSE);
						cui_menu_set_item_disabled(menu_gid, MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL_FROM_SIM_TO_TCARD, MMI_FALSE);
						cui_menu_set_item_disabled(menu_gid, MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL_FROM_TCARD_TO_SIM, MMI_FALSE);
											{
							#ifdef __MMI_DUAL_SIM_MASTER__
						#if(!defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || defined(__OP01__) )
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
						#endif
			#endif
					}
					}
					else
					{
						cui_menu_set_item_disabled(menu_gid, MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL_FROM_PHONE_TO_TCARD, MMI_TRUE);
						cui_menu_set_item_disabled(menu_gid, MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL_FROM_TCARD_TO_PHONE, MMI_TRUE);
						cui_menu_set_item_disabled(menu_gid, MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL_FROM_SIM_TO_TCARD, MMI_TRUE);
						cui_menu_set_item_disabled(menu_gid, MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL_FROM_TCARD_TO_SIM, MMI_TRUE);	
					}
	}
}
#endif /*__MMI_SMS_TCARD_STORAGE_SUPPORT__*/
#endif 
#endif /*__MMI_MESSAGES_LIST_ADVANCED__*/



/*****************************************************************************
 * FUNCTION
 *  mmi_sms_box_list_opt_pre_view
 * DESCRIPTION
 *  Pre entry list option view msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_LANG_ZAWGYI_MYANMAR__) && defined(__MMI_LANG_MYANMAR__)
void mmi_sms_box_list_opt_pre_view_for_zawgyi(mmi_event_struct *menu_evt	)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_TELEPHONY_SUPPORT__
     cui_menu_event_struct *cui_menu_evt = (cui_menu_event_struct*)menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	 switch (cui_menu_evt->highlighted_menu_id)
    {
	 case MENU_ID_SMS_ZAWGYI:
		 /* z* code here */
	 case MENU_ID_SMS_PADAUK:
		 /* m* code here */
		 break;
	 }
    if (srv_sms_get_msg_status(g_sms_cntx.curr_msg_id) & SRV_SMS_STATUS_UNREAD)
    {
        mmi_sms_read_msg(
            g_sms_cntx.curr_msg_id,
            MMI_TRUE,
            mmi_sms_view_curr_msg_callback);
    }
    else
    {
        mmi_sms_read_msg(
            g_sms_cntx.curr_msg_id,
            MMI_FALSE,
            mmi_sms_view_curr_msg_callback);
    }
    #endif /* __MMI_TELEPHONY_SUPPORT__ */
}
#endif
//#endif /* __MMI_TELEPHONY_SUPPORT__ */

