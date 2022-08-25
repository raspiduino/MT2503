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
 *   SyncMLStruct.h
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SYNCML_STRUCT_H__
#define __SYNCML_STRUCT_H__

#include "MMI_features.h"
    
#ifdef __SYNCML_SUPPORT__

#include "common_nvram_editor_data_item.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "SyncMLDef.h"
#include "custom_mmi_default_value.h"
#include "BtcmSrvGprot.h"
#include "wgui_categories_list.h"
#include "MessagesMiscell.h"

#if defined(__MMI_NCENTER_SUPPORT__)
#include "vsrv_ncenter.h"
#endif

typedef nvram_ef_syncml_account_struct mmi_syncml_account_struct;

typedef nvram_ef_syncml_view_log_struct mmi_syncml_view_log_struct;

#if defined(__MMI_NCENTER_SUPPORT__)
typedef struct
{
	U32 account_index;
	mmi_syncml_notification_enum curr_type;
	
	vsrv_ngroup_handle group_unfinish;
	vsrv_ngroup_handle group_progressing;

	vsrv_notification_handle noti_unfinished;
	vsrv_notification_handle noti_progressing;
	vsrv_notification_handle noti_regularity;
}mmi_syncml_ncenter_cntx_struct;
#endif

#ifdef __MMI_SYNCML_DEVICE_SYNC__
typedef nvram_ef_syncml_device_account_struct mmi_syncml_device_account_context_struct;
typedef nvram_ef_syncml_device_setting_struct mmi_syncml_device_setting_context_struct;
typedef nvram_ef_syncml_bt_addr	mmi_syncml_bt_addr_struct;
typedef void (*mmi_syncml_device_client_callback)(U8 result);

typedef struct
{	
    U8  sync_role;           
    U8  selected_dev;
	U8  total_phones;
    MMI_BOOL is_new_dev;
    U8  app_to_sync;
    U8  report_status;   
	U8  selected_app[SYNCML_SYNC_DEVICE_APP_TOTAL];
	CHAR  name_list[MAX_SYNCML_DEV_NUM][(MAX_SYNCML_DEV_NAME_LEN + 1) * ENCODING_LENGTH];
    mmi_syncml_device_setting_context_struct *setting_ptr;
	mmi_syncml_device_account_context_struct *accnt_ptr;  /* The current using device's account info */
}mmi_syncml_device_sync_context_struct;
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */

#if defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__)
typedef struct
{
    mmi_syncml_device_state_enum curr_state;
    srv_bt_cm_bt_addr remote_bt_addr;
    CHAR	remote_dev_name[(MAX_SYNCML_DEV_NAME_LEN + 1) * ENCODING_LENGTH];/* remote bt name that saved in local device */
    CHAR  remote_uri[MAX_SYNCML_SERVER_ADDR_LEN];
    U8  cm_opr_flag;
    U32 cm_conn_id;
    U8  f_is_phone; /* 1: phone ,0: PC tool */
    MMI_BOOL is_state_reset;/* If device B, then after data exchange, sync state will be reset */
    U8  dev_role;
    U8 imei[21];
#ifdef __MMI_SYNCML_DEVICE_SYNC__
    CHAR  org_dev_name[(MAX_SYNCML_DEV_NAME_LEN + 1) * ENCODING_LENGTH];/* remote BT name */
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */
}mmi_syncml_common_cntx_struct;
#endif /* defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__) */

typedef struct
{
    U8  account_name_display[MMI_MAX_SYNCML_ACCOUNTS][MAX_SYNCML_PROFILE_NAME * ENCODING_LENGTH];
    U8  app_to_sync[MMI_MAX_SYNCML_ACCOUNTS];
    U8  regular_sync[MMI_MAX_SYNCML_ACCOUNTS];
    U16 regular_sync_notify[MMI_MAX_SYNCML_ACCOUNTS];
    U8  sync_type[MMI_MAX_SYNCML_ACCOUNTS];
    U8  sas_flag[MMI_MAX_SYNCML_ACCOUNTS];
    U8  sync_report_status[MMI_MAX_SYNCML_ACCOUNTS];
    U16 account_validation[MMI_MAX_SYNCML_ACCOUNTS];

    U32 last_phb_anchor[MMI_MAX_SYNCML_ACCOUNTS];
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
    U32 last_cal_anchor[MMI_MAX_SYNCML_ACCOUNTS];
#endif
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
    U32 last_task_anchor[MMI_MAX_SYNCML_ACCOUNTS];
#endif
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    U32 last_note_anchor[MMI_MAX_SYNCML_ACCOUNTS];
#endif
#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
/* under construction !*/
#endif
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
#endif 
/* will be init when power on*/

    U8  app_id[MMI_MAX_SYNCML_ACCOUNTS];
    U8  selected_account;               /* used to edit and view log */
    U8  active_account;                 /* account id */
    U8  highlighted_id;
    U8  is_pre_sync;                    /* the time before send start_sync_req message (phone suit) */ 
    U8  sync_progress;      
    MMI_BOOL abort_state;   
    U8  db_sync_result;   
    MMI_BOOL abort_by_other;            /* flag whether show sync finish popup and sync report */
    mmi_id temp_gid;    

#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    U8  account_read_only[MMI_MAX_SYNCML_ACCOUNTS];
#endif
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#endif       
#ifdef __MMI_SYNCML_DATA_CHANGE_SYNC_DELAY__
    U8  is_data_change_timeout;
#endif

    /* Sync process */
	MMI_BOOL is_sync_state;
    U32 next_phb_anchor;
    MMI_BOOL contact_sync_state;                    /* 1: synchronizing, 0: sync done */
    /* sync progrssion indication */
    U16 contact_send_noc;                           /* noc: numberofchanges */
    U16 contact_recv_noc;
    U16 contact_send_current; 
    U16 contact_recv_current;
    /* sync report for client */
    U16 contact_ok_cnt[3];                          /* 0:add, 1:replace, 2:delete */
    U16 contact_ng_cnt;
    /* sync report for server */
    U16 svr_contact_ok_cnt[3];                      /* 0:add, 1:replace, 2:delete */
    U16 svr_contact_ng_cnt;
    
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
    U32 next_cal_anchor;
    MMI_BOOL calendar_sync_state; 
    U16 calendar_send_noc; 
    U16 calendar_recv_noc;
    U16 calendar_send_current; 
    U16 calendar_recv_current;
    U16 calendar_ok_cnt[3]; 
    U16 calendar_ng_cnt;
    U16 svr_calendar_ok_cnt[3]; 
    U16 svr_calendar_ng_cnt;
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
    MMI_BOOL task_sync_state; 
    U32 next_task_anchor;
    U16 task_send_noc; 
    U16 task_recv_noc;
    U16 task_send_current; 
    U16 task_recv_current;
    U16 task_ok_cnt[3];  
    U16 task_ng_cnt;
    U16 svr_task_ok_cnt[3]; 
    U16 svr_task_ng_cnt;
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    MMI_BOOL note_sync_state; 
    U32 next_note_anchor;
    U16 note_send_noc; 
    U16 note_recv_noc;
    U16 note_send_current; 
    U16 note_recv_current;
    U16 note_ok_cnt[3];  
    U16 note_ng_cnt;
    U16 svr_note_ok_cnt[3]; 
    U16 svr_note_ng_cnt;
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */

#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
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
#endif /* __MMI_SYNCML_BOOKMARK_SUPPORT__ */ 
    
#ifdef __MMI_SYNCML_DEVICE_SYNC__
    MMI_BOOL is_dev_sync;
    MMI_BOOL is_dev_log;
    mmi_syncml_device_sync_context_struct *dev_cntx_ptr;
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */

#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
    U8 transport_type[MMI_MAX_SYNCML_ACCOUNTS];
    U8 phn_app_to_sync;
    MMI_BOOL is_pc_sync;
#endif /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */      

#ifdef __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__
    U8 temp_application_to_sync;
    U8 app_sync_menu;   
    U8 valid_acct_num;
    U8 valid_acct_id_array[MMI_MAX_SYNCML_ACCOUNTS];
#endif /*__MMI_SYNCML_APP_SYNC_MENU_SUPPORT__*/
	U32 net_id[MMI_MAX_SYNCML_ACCOUNTS][MAX_SIM_NUM];
	S32 cbm_state;
}mmi_syncml_cntx_struct;

/* structure for account edition */
typedef struct
{
  
    U8  temp_addr_buffer[MAX_SYNCML_SERVER_ADDR_LEN * ENCODING_LENGTH];
    U8  temp_name_buffer[MAX_SYNCML_USERNAME * ENCODING_LENGTH];
    U8  temp_pswd_buffer[MAX_SYNCML_PASSWORD * ENCODING_LENGTH];
    U8  selected_applications[MMI_SYNCML_SYNC_APP_TOTAL];
} mmi_syncml_account_edit_struct;

typedef struct
{
    U8 operation; /* add, modify, delete, move */
    U8 database;
    U16 luid;
    U16 result;
    U8 more_data;
    U16 *luid_buf;
    U16 count; /* for query luid list */
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
} mmi_syncml_sync_request_struct;

#ifdef __MMI_SYNCML_CCA_SUPPORT__
/*following below is for CCA use.*/
typedef struct
{
	U8  proxy_id[MAX_SYNCML_PROXY_ID_LEN];           /*For mapping profile number use. */ 
    U32 dataaccountid;  	                         /*DataAccount id */
	MMI_BOOL valid;
	U8 unused1;
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
	U8 proxy_id_hash[MAX_SYNCML_HASH_BUF_LEN];
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
	
} mmi_syncml_ota_proxy_cntx_struct;

typedef struct
{
    U16 conf_id;                             /* Configuration ID                  */
    U16 sim_id;
    S32 doc_hdl;                             /* Configuration document handle     */
    /* currentProfNameList for select screen display */
    U8 currentprofnamelist[MMI_MAX_SYNCML_ACCOUNTS][MAX_SYNCML_PROFILE_NAME * ENCODING_LENGTH];
    U8 num_profiles;                         /* Num of processed profiles */
    U8 num_proxy;                            /*Num of processed proxy*/  
    CHAR in_use;                               /*The index of the profile that is being used currently*/			       
    U8 iter;                                 /* Used to traverse profiles */
    U8 app_to_proxy[MMI_MAX_SYNCML_ACCOUNTS][MAX_SYNCML_PROXY_ID_LEN]; /*For mapping profile number use.*/
    CHAR dst_idx[MMI_MAX_SYNCML_ACCOUNTS];     /*The index of slot where place the new profile.*/
    U8 total_valid;                         /* total valid profile */
    MMI_BOOL isvalidprof[MMI_MAX_SYNCML_ACCOUNTS];
	U8 	opr_flag; 							/* operation flag */
	/* store the settings of the new profile */    
    mmi_syncml_account_struct *profile[MMI_MAX_SYNCML_ACCOUNTS];
    /* store the data of the new proxy */
    mmi_syncml_ota_proxy_cntx_struct proxy[MMI_MAX_SYNCML_ACCOUNTS];
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
	U8 prov_url_hash[MAX_SYNCML_HASH_BUF_LEN];
	U32 prov_flag;							/* prov flag from CCA */
#endif
} mmi_syncml_ota_cntx_struct;
#endif /* __MMI_SYNCML_CCA_SUPPORT__ */

#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_REFRESH_SYNC_SUPPORT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
/* under construction !*/
#endif
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
/* under construction !*/
#endif 
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
/* under construction !*/
#endif 
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
#endif
#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__ */

/* handle the finish popup for background call */
typedef struct
{
    U16 sync_result;
    U16 string_id;
    U8  emotion_id;
}mmi_syncml_display_popup_hdlr_struct;

/* for confirmation popup  */
typedef struct
{
    FuncPtr lsk_f;
    FuncPtr csk_f;
    FuncPtr rsk_f;
    void *user_data;
}mmi_syncml_confirm_struct;

#endif /* __SYNCML_SUPPORT__ */
#endif /* __SYNCML_STRUCT_H__ */
