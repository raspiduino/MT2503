/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   SyncMLDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for SyncML (ESI) structure
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SYNCML_DEF_H__
#define __SYNCML_DEF_H__

#include "MMI_features.h"
    
#ifdef __SYNCML_SUPPORT__

#include "inlinecuigprot.h"
#include "custom_mmi_default_value.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"


#define MMI_MAX_SYNCML_ACCOUNTS   MAX_SYNCML_SV_PROFILES

#define MMI_SYNCML_MAX_TIME_SIZE  25

#define MMI_SYNCML_TRACE0(sub_grp) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp)

#define MMI_SYNCML_TRACE1(sub_grp, arg) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg)
		
#define MMI_SYNCML_TRACE2(sub_grp, arg1, arg2) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2)

#define MMI_SYNCML_TRACE3(sub_grp, arg1, arg2, arg3) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2, arg3)

#define MMI_SYNCML_TRACE4(sub_grp, arg1, arg2, arg3, arg4) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2, arg3, arg4)

#define MMI_SYNCML_TRACE5(sub_grp, arg1, arg2, arg3, arg4, arg5) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2, arg3, arg4, arg5)

#define MMI_SYNCML_TRACE6(sub_grp, arg1, arg2, arg3, arg4, arg5, arg6) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2, arg3, arg4, arg5, arg6)

#define MMI_SYNCML_TRACE7(sub_grp, arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2, arg3, arg4, arg5, arg6, arg7)
		
#define MMI_SYNCML_TRACE8(sub_grp, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8)

/* The temporary file to store the data*/
#define SYNCML_VOBJ_PATH     			L"Z:\\@SyncML\\syncvobj.tmp"

#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */

/* The file to store the change log */
#define SYNCML_PHB_CHANGE_LOG_FILE_PREFIX L"Z:\\@SyncML\\syncphbk"
#define SYNCML_PHB_CHANGE_LOG_FILE_PATH   L"Z:\\@SyncML\\syncphbk1.log"

#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
#define SYNCML_CAL_CHANGE_LOG_FILE_PREFIX L"Z:\\@SyncML\\synccal"
#define SYNCML_CAL_CHANGE_LOG_FILE_PATH   L"Z:\\@SyncML\\synccal1.log"
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
#define SYNCML_TASK_CHANGE_LOG_FILE_PREFIX L"Z:\\@SyncML\\synctask"
#define SYNCML_TASK_CHANGE_LOG_FILE_PATH   L"Z:\\@SyncML\\synctask1.log"
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
#define SYNCML_NOTE_CHANGE_LOG_FILE_PREFIX  L"Z:\\@SyncML\\syncnote"
#define SYNCML_NOTE_CHANGE_LOG_FILE_PATH    L"Z:\\@SyncML\\syncnote1.log"
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */

#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_BOOKMARK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */

#ifdef __MMI_SYNCML_DATA_CHANGE_SYNC_DELAY__
#define SYNCML_DATA_CHANGE_DELAY_TIME (3 * 60 * 1000) /* 3min */
#endif

#ifdef __MMI_SYNCML_DEVICE_SYNC__
#define SYNCML_DEV_PHB_CHANGE_LOG_FILE_PREFIX L"Z:\\@SyncML\\syncdev_phb"
#define SYNCML_DEV_PHB_CHANGE_LOG_FILE_PATH   L"Z:\\@SyncML\\syncdev_phb1.log"
#define SYNCML_DEV_CAL_CHANGE_LOG_FILE_PREFIX L"Z:\\@SyncML\\syncdev_cal"
#define SYNCML_DEV_CAL_CHANGE_LOG_FILE_PATH   L"Z:\\@SyncML\\syncdev_cal1.log"
#define SYNCML_DEV_TASK_CHANGE_LOG_FILE_PREFIX L"Z:\\@SyncML\\syncdev_task"
#define SYNCML_DEV_TASK_CHANGE_LOG_FILE_PATH   L"Z:\\@SyncML\\syncdev_task1.log"
#define SYNCML_DEV_NOTE_CHANGE_LOG_FILE_PREFIX L"Z:\\@SyncML\\syncdev_note"
#define SYNCML_DEV_NOTE_CHANGE_LOG_FILE_PATH   L"Z:\\@SyncML\\syncdev_note1.log"
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */

#define SYNCML_CHANGE_LOG_RECORD_SIZE 7 /* U16(LUID) + U32(timestamp) + U8(operation) */

#define SYNCML_CHANGE_LOG_NOT_FOUND -1

#define SYNCML_OK                  200
#define SYNCML_NOT_FOUND           211          /* Wen, */
#define SYNCML_FAIL                500
#define SYNCML_INVALID_CREDENTIAL  401
#define SYNCML_MISSING_CREDENTIAL  407
#define SYNCML_DEVICE_FULL         420
#define SYNCML_PAYMENT_REQUIRED    402
/* yln added, other code need to be displayed */
#define SYNCML_CODE_FORBIDDEN      403          /* Server busy */
#define SYNCML_INCOMPLETE_CMD      412
#define SYNCML_DEVICE_FULL         420
#define SYNCML_SERVICE_UNAVAILABLE 503          /* Server busy */
#define SYNCML_DATASTORE_FAIL      510
#define SYNCML_SVR_FAIL            511
#define SYNCML_ERR_OCCUR           512
#define SYNCML_PROTOCOL_UNSUPPORT  513


/* account valid mask  */
#define MMI_SYNCML_ACCOUNT_VALID_MASK_NAME  0x0001
#define MMI_SYNCML_ACCOUNT_VALID_MASK_SVR   0x0002
#define MMI_SYNCML_ACCOUNT_VALID_MASK_CON   0x0004  /* phonebook validation mask */
#define MMI_SYNCML_ACCOUNT_VALID_MASK_CAL   0x0008
#define MMI_SYNCML_ACCOUNT_VALID_MASK_TASK  0x0010
#define MMI_SYNCML_ACCOUNT_VALID_MASK_NOTE  0x0020
#define MMI_SYNCML_ACCOUNT_VALID_MASK_BKM   0x0040
#define MMI_SYNCML_ACCOUNT_VALID_MASK_EMAIL 0x0080 
/* ... reserved for other database */
#define MMI_SYNCML_ACCOUNT_VALID_MASK_CONN  0x8000  /* connection validation mask net_id*/


/* regular_sync_notify mask */
#define MMI_SYNCML_PHB_DATA_CHANGE          0x0001
#define MMI_SYNCML_CALENDAR_DATA_CHANGE     0x0002
#define MMI_SYNCML_TASK_DATA_CHANGE         0x0004
#define MMI_SYNCML_NOTE_DATA_CHANGE         0x0008
#define MMI_SYNCML_BOOKMARK_DATA_CHANGE     0x0010
#define MMI_SYNCML_EMAIL_DATA_CHANGE        0x0020
/* ... reserved for other database */
#define MMI_SYNCML_POWER_ON_SYNC            0x4000
#define MMI_SYNCML_REGULARY_SYNC            0x8000  /* including daily weekly monthly */


#ifdef __MMI_SYNCML_CCA_SUPPORT__
/* invalid dest id for buffered profile*/
#define DEFAULT_CCA_PROFILE_NAME    (L"New account")
#define SYNCML_INVALID_IDX 			MAX_SYNCML_SV_PROFILES 
#define MAX_SYNCML_MIME_LEN 		64

/* OTA operation flag */
#define SYNCML_OTA_OPR_UPDATE_MASK		0x01
#define SYNCML_OTA_OPR_REPLACE_MASK		0x02	
#define SYNCML_OTA_OPR_SKIP_MASK		0x04
#define SYNCML_OTA_OPR_ACTIVATE_MASK	0x08
#define SYNCML_OTA_OPR_INSTALL_MASK     0x10
#define SYNCML_OTA_OPR_DM_UPDATE_MASK	0x20
#define SYNCML_OTA_OPR_PROV_MASK		0x40
#endif /* __MMI_SYNCML_CCA_SUPPORT__ */

#if defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__)
#define MMI_SYNCML_DEVICE_SYNC 1
#define MMI_SYNCML_PC_SYNC 0
#define MMI_SYNCML_COMMON_SYNC 0xFF

#define MMI_SYNCML_DEV_ROLE_NONE   0
#define MMI_SYNCML_DEV_ROLE_A 1
#define MMI_SYNCML_DEV_ROLE_B 2

#define MMI_SYNCML_DEV_SYNC_ACCEPT 1
#define MMI_SYNCML_DEV_SYNC_REJECT 0

#define MMI_SYNCML_DEV_CONN_ACCEPT 1
#define MMI_SYNCML_DEV_CONN_REJECT 0

#define MAX_MMI_SYNCML_DEV_STR_LEN 96

#define SYNCML_DEV_BTCM_OPR_MASK_DEACTIVE	0x01
#define SYNCML_DEV_BTCM_OPR_MASK_DISCONN	0x02
#define SYNCML_DEV_BTCM_OPR_MASK_DEINIT	    0x04

#define MMI_SYNCML_DEV_INVALID_CONN_ID 0XFFFF

#endif /* defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__) */


typedef enum
{
    MMI_SYNCML_REG_SYNC_CHECK_RETURN,
    MMI_SYNCML_REG_SYNC_CHECK_TIMER_RETURN,
    MMI_SYNCML_REG_SYNC_CHECK_CONTINUE,
    MMI_SYNCML_REG_SYNC_CHECK_PASS,
    MMI_SYNCML_REG_SYNC_CHECK_TOTAL
}mmi_syncml_regular_sync_check_result_enum;

/* return values */
typedef enum
{
    MMI_SYNCML_SYNC_SUCCESS,
    MMI_SYNCML_SYNC_ERROR,
    MMI_SYNCML_SYNC_STORAGE_FULL,
    MMI_SYNCML_SYNC_NOT_FOUND,
    MMI_SYNCML_SYNC_TOTAL
} mmi_syncml_dbop_error_enum; 


#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */


typedef enum 
{
    MMI_SYNCML_TYPE_DEFAULT,
    MMI_SYNCML_TYPE_BACKUP,     /* delete all data from server, and client send all data to server */
    MMI_SYNCML_TYPE_RESTORE,    /* delete all data from client, and server send all data to client */
    MMI_SYNCML_TYPE_EXPORT,     /* only client send its all data to server, analyse them on server */
    MMI_SYNCML_TYPE_IMPORT,     /* only client receive all data from server, anlyse them on client */
    MMI_SYNCML_TYPE_END
}mmi_syncml_sync_type_enum;


typedef enum 
{
    MMI_SYNCML_REGULAR_SYNC_NONE,         /* No regular sync */
        
#ifdef __MMI_SYNCML_VF_DATA_CHANGE_SYNC__
    MMI_SYNCML_REGULAR_SYNC_DATA_CHANGED, /* When data is changed */
#endif 

    MMI_SYNCML_REGULAR_SYNC_POWER_ON,     /* When handset is turned on */
    MMI_SYNCML_REGULAR_SYNC_EVERY_DAY,    /* Every day */
    MMI_SYNCML_REGULAR_SYNC_EVERY_WEEK,   /* Every week */
    MMI_SYNCML_REGULAR_SYNC_EVERY_MONTH,  /* Every month */
    MMI_SYNCML_REGULAR_SYNC_END
}mmi_syncml_regular_sync_enum;


/* Converted symbols to define CCA namespace mapping table. */
#ifdef __MMI_SYNCML_CCA_SUPPORT__
typedef enum
{
    MMI_CCA_NS_SYNCML_PROXY,
    MMI_CCA_NS_SYNCML_BOOTSTRAP,
    MMI_CCA_NS_SYNCML_APPLICATION,
    MMI_CCA_NS_SYNCML_PORT,
    MMI_CCA_NS_SYNCML_PXAUTHINFO,
    MMI_CCA_NS_SYNCML_APPADDR,
    MMI_CCA_NS_SYNCML_APPAUTH,
    MMI_CCA_NS_SYNCML_RESOURCE,
    MMI_CCA_NS_SYNCML_NAPDEF,
    MMI_CCA_NS_SYNCML_TOTAL
} mmi_syncml_cca_symbol_enum;
#endif /* __MMI_SYNCML_CCA_SUPPORT__ */


/* syncml account edit menu enum */
typedef enum
{
    MMI_SYNCML_ACCOUNT_EDIT_NAME,
    MMI_SYNCML_ACCOUNT_EDIT_TRANSPORT_TYPE,
    MMI_SYNCML_ACCOUNT_EDIT_SERVER_SETTINGS,
    MMI_SYNCML_ACCOUNT_EDIT_APP_TO_SYNC,
    MMI_SYNCML_ACCOUNT_EDIT_DB_SETTINGS,
    MMI_SYNCML_ACCOUNT_EDIT_CONN_SETTINGS,
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
    MMI_SYNCML_ACCOUNT_EDIT_SYNC_TYPE,
#endif
    MMI_SYNCML_ACCOUNT_EDIT_REGULAR_SYNC,
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
#endif
    MMI_SYNCML_ACCOUNT_EDIT_REPORT,
    MMI_SYNCML_ACCOUNT_EDIT_MENU_TOTAL
}mmi_syncml_account_edit_menu_enum;


/* syncml account menuitem enum */
typedef enum
{
    MMI_SYNCML_ACCOUNT_APP_MENU_CONTACT,
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
    MMI_SYNCML_ACCOUNT_APP_MENU_CALENDAR,
#endif
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
    MMI_SYNCML_ACCOUNT_APP_MENU_TASK,
#endif
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    MMI_SYNCML_ACCOUNT_APP_MENU_NOTE,
#endif
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
#endif 
#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
/* under construction !*/
#endif 
    MMI_SYNCML_ACCOUNT_APP_MENU_TOTAL
}mmi_syncml_account_app_menu_enum;


typedef enum
{
    MMI_SYNCML_TRANS_TYPE_INTERNET,
#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
    MMI_SYNCML_TRANS_TYPE_BT,
#endif
    MMI_SYNCML_TRANS_TYPE_TOTAL
}mmi_syncml_account_transport_type_enum;


typedef enum
{
    MMI_SYNCML_INLINE_SVR_ADDR_CAP = CUI_INLINE_ITEM_ID_BASE + 0,
    MMI_SYNCML_INLINE_SVR_ADDR,
    MMI_SYNCML_INLINE_SVR_UN_CAP,
    MMI_SYNCML_INLINE_SVR_UN,
    MMI_SYNCML_INLINE_SVR_PSW_CAP,
    MMI_SYNCML_INLINE_SVR_PSW,
    MMI_SYNCML_INLINE_SVR_ITEM_TOTAL
}mmi_syncml_server_setting_menu_enum;

typedef enum
{
    MMI_SYNCML_INLINE_CON_ADDR_CAP = MMI_SYNCML_INLINE_SVR_ITEM_TOTAL,
    MMI_SYNCML_INLINE_CON_ADDR,
    MMI_SYNCML_INLINE_CON_UN_CAP,
    MMI_SYNCML_INLINE_CON_UN,
    MMI_SYNCML_INLINE_CON_PSW_CAP,
    MMI_SYNCML_INLINE_CON_PSW,
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
    MMI_SYNCML_INLINE_CAL_ADDR_CAP,
    MMI_SYNCML_INLINE_CAL_ADDR,
    MMI_SYNCML_INLINE_CAL_UN_CAP,
    MMI_SYNCML_INLINE_CAL_UN,
    MMI_SYNCML_INLINE_CAL_PSW_CAP,
    MMI_SYNCML_INLINE_CAL_PSW,
#endif
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
    MMI_SYNCML_INLINE_TASK_ADDR_CAP,
    MMI_SYNCML_INLINE_TASK_ADDR,
    MMI_SYNCML_INLINE_TASK_UN_CAP,
    MMI_SYNCML_INLINE_TASK_UN,
    MMI_SYNCML_INLINE_TASK_PSW_CAP,
    MMI_SYNCML_INLINE_TASK_PSW,
#endif
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    MMI_SYNCML_INLINE_NOTE_ADDR_CAP,
    MMI_SYNCML_INLINE_NOTE_ADDR,
    MMI_SYNCML_INLINE_NOTE_UN_CAP,
    MMI_SYNCML_INLINE_NOTE_UN,
    MMI_SYNCML_INLINE_NOTE_PSW_CAP,
    MMI_SYNCML_INLINE_NOTE_PSW,
#endif
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    MMI_SYNCML_INLINE_DB_SETTING_TOTAL
}mmi_syncml_db_setting_menu_enum;

typedef enum
{
	MMI_SYNCML_INLINE_CONN_DATAACCOUNT_CAP = MMI_SYNCML_INLINE_DB_SETTING_TOTAL,
	MMI_SYNCML_INLINE_CONN_DATAACCOUNT,
	MMI_SYNCML_INLINE_CONN_USE_PROXY_CAP,
	MMI_SYNCML_INLINE_CONN_USE_PROXY,
	
	MMI_SYNCML_INLINE_CONN_TOTAL
}mmi_syncml_accINLINE_ount_conn_menu_enum;


/* syncml sync database enum */
typedef enum
{
    MMI_SYNCML_SYNC_APP_PHB,
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
	MMI_SYNCML_SYNC_APP_CAL,
#endif
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
	MMI_SYNCML_SYNC_APP_TASK,
#endif 
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
	MMI_SYNCML_SYNC_APP_NOTE,
#endif 
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
#endif 
#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
/* under construction !*/
#endif
    MMI_SYNCML_SYNC_APP_TOTAL
}mmi_syncml_sync_application_enum;


typedef enum
{
    MMI_SYNCML_PROF_VALID,
    MMI_SYNCML_PROF_INVALID_SERVER,
    MMI_SYNCML_PROF_INVALID_DATABASE,
    MMI_SYNCML_PROF_INVALID_DATA_ACCOUNT,
       
    MMI_SYNCML_PROF_VALIDITY_TOTAL  
}mmi_syncml_profile_validity_enum;


#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
/* syncml account type */
typedef enum
{
    MMI_SYNCML_ACCOUNT_TYPE_FACTORY,           /* factory pre-configured */
    MMI_SYNCML_ACCOUNT_TYPE_OTA,               /* provioning profile */
    MMI_SYNCML_ACCOUNT_TYPE_USR_DEFINED,       /* usr defined profile */
    MMI_SYNCML_ACCOUNT_TYPE_TOTAL
}MMI_SYNCML_ACCOUNT_TYPE_ENUM;
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */


#ifdef __MMI_SYNCML_DEVICE_SYNC__
typedef enum
{
    MMI_SYNCML_DEVICE_PHONES_OPTION_SYNC,
    MMI_SYNCML_DEVICE_PHONES_OPTION_RENAME,
	MMI_SYNCML_DEVICE_PHONES_OPTION_VIEWLOG,
    MMI_SYNCML_DEVICE_PHONES_OPTION_DELETE,
    MMI_SYNCML_DEVICE_PHONES_OPTION_DELETE_ALL,
    MMI_SYNCML_DEVICE_PHONES_OPTION_TOTAL
}mmi_syncml_device_phones_option_enum;


/* device sync database enum */
typedef enum
{
    SYNCML_SYNC_DEVICE_APP_PHB,
#ifdef __MMI_SYNCML_DEVICE_CALENDAR_SUPPORT__
	SYNCML_SYNC_DEVICE_APP_CAL,
#endif
#ifdef __MMI_SYNCML_DEVICE_TASK_SUPPORT__
	SYNCML_SYNC_DEVICE_APP_TASK,
#endif
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    SYNCML_SYNC_DEVICE_APP_NOTE,
#endif 
    SYNCML_SYNC_DEVICE_APP_TOTAL
}mmi_syncml_device_sync_app_enum;
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */


#if defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__)
typedef enum
{
    MMI_SYNCML_DEVICE_STATE_IDLE,
    MMI_SYNCML_DEVICE_STATE_BT_PWR_OFF, /* BT power off */
    MMI_SYNCML_DEVICE_STATE_BT_PWR_ON,  /* BT power on  */
    MMI_SYNCML_DEVICE_STATE_BT_ON,
    MMI_SYNCML_DEVICE_STATE_BT_CONN_ASK,
    MMI_SYNCML_DEVICE_STATE_BT_CONN_ASK_RSP,
    MMI_SYNCML_DEVICE_STATE_BT_CONNECTING,
    MMI_SYNCML_DEVICE_STATE_SYNC_ASK,
    MMI_SYNCML_DEVICE_STATE_SYNC_ASK_RSP,
    //MMI_SYNCML_DEVICE_STATE_PRE_CHECK,  /* Pre check    */
    MMI_SYNCML_DEVICE_STATE_START,      /* Star sync    */
    MMI_SYNCML_DEVICE_STATE_SYNCING,    /* 11, Synchonizing */
    MMI_SYNCML_DEVICE_STATE_SYNC_BG,    /* back ground sync */
    MMI_SYNCML_DEVICE_STATE_REENTRY,
    MMI_SYNCML_DEVICE_STATE_DEACTIVE,      /* Abort        */
    MMI_SYNCML_DEVICE_STATE_DISCONN,    /* Disconn  from BT cm */
    MMI_SYNCML_DEVICE_STATE_BT_DEINIT,
    MMI_SYNCML_DEVICE_STATE_ABORTING,   /* Aborting     */
    MMI_SYNCML_DEVICE_STATE_TOTAL
}mmi_syncml_device_state_enum;


typedef enum
{
    MMI_SYNCML_DEVICE_ERROR_SUCCESS,
    MMI_SYNCML_DEVICE_ERROR_PRE_CHECK,
    MMI_SYNCML_DEVICE_ERROR_TOTAL    
}mmi_syncml_device_error_enum;
#endif /* defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__) */

typedef enum
{
	MMI_SYNCML_NOTIFICATION_SYNC_NONE,
	MMI_SYNCML_NOTIFICATION_SYNC_REMOTE,
	MMI_SYNCML_NOTIFICATION_SYNC_DEVICE,
	
	MMI_SYNCML_NOTIFICATION_SYNC_TOTAL
}mmi_syncml_notification_enum;

#endif /* __SYNCML_SUPPORT__ */
#endif /* __SYNCML_DEF_H__ */

