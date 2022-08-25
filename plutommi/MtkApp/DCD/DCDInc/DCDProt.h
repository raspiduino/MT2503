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
*  DCDProt.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   DCD exported interface header file in DCD internal Module
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
 * removed!
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
*==============================================================================*/

#ifndef _DCD_PROT_H
#define _DCD_PROT_H
/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_OP01_DCD__
#include "MMIDataType.h"
#include "FileMgrCuiGprot.h"
#include "InlineCuiGprot.h"
#include "dcdagentinterface.h"
#include "sdktypedef.h"
#include "dcdagentdefine.h"
#include "kal_general_types.h"
#include "DCDGprot.h"

#define DCD_APP_INLINE_CAPTION_SCROLL_SPEED		(CUI_INLINE_ITEM_ID_BASE+0)
#define DCD_APP_INLINE_SELECT_SCROLL_SPEED		(CUI_INLINE_ITEM_ID_BASE+1)
#define DCD_APP_INLINE_CAPTION_READ_DISPLAY		(CUI_INLINE_ITEM_ID_BASE+2)
#define DCD_APP_INLINE_SELECT_READ_DISPLAY		(CUI_INLINE_ITEM_ID_BASE+3)
/***************************************************************************** 
 * Define 
 *****************************************************************************/
#define MMI_DCD_MAX_SAVED_STORY_COUNT            10 	
/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
typedef enum
{
    DCD_CONN_MODE_ALWAYS,
    DCD_CONN_MODE_HOME,
    DCD_CONN_MODE_MANUAL,
    DCD_CONN_MODE_MAX
} dcd_conn_mode_enum;

#define MMI_DCD_MAX_CTXT_ID_LEN     20
#define UPDATE_STR_SIZE             20  

typedef struct
{
    HDCD_Agent     agent_handle;
    HDCD_Channel   channel_handle;
    S32            channel_index;
    BRCHAR         channel_id[MMI_DCD_MAX_CTXT_ID_LEN+1];
    HDCD_Entry     entry_handle;
    S32            entry_index;
    BRCHAR         entry_id[MMI_DCD_MAX_CTXT_ID_LEN+1];
    U8             update_flag;
    EDCD_VIEW_MODE view_mode;
} dcd_agent_struct;

typedef struct
{
    U8  info_str[UPDATE_STR_SIZE * ENCODING_LENGTH];
    U16 scr_id;
} mmi_dcd_refresh_cnxt;

/* update log struct */
typedef struct
{
    kal_uint16  last_year;      /* last sync time */
    kal_uint8   last_month;
    kal_uint8   last_day;
    kal_uint8   last_hour;
    kal_uint8   last_minute;
    kal_uint8   last_second;

    kal_uint8   last_sync_type;
    kal_uint8   sync_result;   /* 0:failed;  1:success;  2: syncing */
    kal_uint8   fail_cause;
    kal_uint8   next_sync_type;    
    
    kal_uint16  next_year;      /* last sync time */
    kal_uint8   next_month;
    kal_uint8   next_day;
    kal_uint8   next_hour;
    kal_uint8   next_minute;
    kal_uint8   next_second;
} mmi_dcd_update_log_struct;

/* content updated flag */
#define MMI_DCD_CHANNEL_LIST_UPDATE_MASK    0x01
#define MMI_DCD_STORY_LIST_UPDATE_MASK      0x02


/* dcd setting detail, idle display */
typedef enum
{
	DCD_IDLE_DISPLAY_ON,
	DCD_IDLE_DISPLAY_OFF,
	DCD_IDLE_DISPLAY_TOTAL
} mmi_dcd_idle_display_enum;


/* dcd setting detail, scroll speed */
typedef enum
{
	DCD_SCRL_SPEED_NORMAL,
	DCD_SCRL_SPEED_SLOW,
	DCD_SCRL_SPEED_FAST,
	DCD_SCRL_SPEED_TOTAL
} mmi_dcd_scroll_speed_enmu;


/* dcd setting detail, idle display */
typedef enum
{
	DCD_IDLE_READ_STORY_DISPLAY_ON,
	DCD_IDLE_READ_STORY_DISPLAY_OFF,
	DCD_IDLE_READ_STORY_DISPLAY_TOTAL
} mmi_dcd_read_story_display_enum;

typedef struct
{
    kal_uint8	dcd_conn_mode;
    kal_uint8	dcd_scroll_speed;
    kal_uint8	dcd_read_item_display;
    kal_uint8	dcd_idle_display;
    kal_uint8	dcd_restore;
    kal_uint8	dcd_switch;
    kal_uint8	dcd_new_sim;  /* init-0, sim changed-1, else-0 */
    kal_uint8   dcd_flymode;
} mmi_dcd_setting_data_struct;

typedef enum {
    MMI_DCD_URL_ADD_CHAN,
    MMI_DCD_URL_DEL_CHAN,
    MMI_DCD_URL_HELP,
    MMI_DCD_URL_TYPE_END
} mmi_dcd_url_type_eunm;

typedef enum
{
	DCD_ENABLE_OFF,
	DCD_ENABLE_ON,
	DCD_ENABLE_TOTAL
} mmi_dcd_enable_enum;

extern dcd_agent_struct g_dcd_agent;
extern mmi_dcd_setting_data_struct  *g_mmi_dcd_setting_cntx_p;
extern mmi_dcd_update_log_struct    *g_dcd_update_log_p;
extern mmi_dcd_refresh_cnxt         *g_dcd_manual_update_p;

extern MMI_ID  g_dcd_grp_id;

/***************************************************************************** 
 * Global Function 
 *****************************************************************************/
/* network related functions */
extern void mmi_dcd_ready_to_sync(void);
extern void mmi_dcd_reset_to_sync(void);
extern void mmi_dcd_switch_to_sync(MMI_BOOL on);
extern void mmi_dcd_push_to_sync(S8 *push_url);
extern void mmi_dcd_conn_to_sync(dcd_conn_mode_enum conn);
extern void mmi_dcd_stop_sync(void);
extern void mmi_dcd_sync_prompt(MMI_BOOL success);
extern void mmi_dcd_network_init(void);
extern void mmi_dcd_disconnect_bearer(void); 
extern void mmi_dcd_cbm_register_app_id(void);
extern void mmi_dcd_cbm_deregister_app_id(void);
extern void mmi_dcd_sync_before(void);
extern void mmi_dcd_user_sync_fail_abort(void);
extern S32  mmi_dcd_get_sync_err_code(void);
extern MMI_BOOL mmi_dcd_user_to_sync(MMI_BOOL *is_syncing, dcd_sync_callback callback);
extern MMI_BOOL mmi_dcd_is_roaming(void);
extern MMI_BOOL mmi_dcd_is_manual_updte(void);
extern MMI_BOOL mmi_dcd_is_line_taken(void);
extern MMI_BOOL mmi_dcd_is_bt_access_profile_mode(void);

/* settings related functions */
extern void mmi_dcd_settings_init(void);
extern void mmi_dcd_entry_idle_display_settings_screen(void);
extern void mmi_dcd_entry_switch_off_prompt(void);
extern void mmi_dcd_entry_setting_update_log(void);
extern void mmi_dcd_entry_help_info(void);
extern void mmi_dcd_settings_reset_confirm(void);
extern void mmi_dcd_idle_display_settings_save(void);
extern void mmi_dcd_entry_setting_conn_mode(void);
extern void mmi_dcd_setting_conn_mode_save(U8 conn_mode);
extern MMI_BOOL mmi_dcd_write_setting_value(void);
extern MMI_BOOL mmi_dcd_set_scroll_speed(void);
extern MMI_BOOL mmi_dcd_set_read_item_display(void);

/* channel list related functions */
extern void mmi_dcd_entry_chan_from_story_list(void);
extern void mmi_dcd_pre_entry_manual_update(void);
extern void mmi_dcd_display_manual_update_info(EDCD_MSG_CODE a_eMsgCode);
extern void mmi_dcd_set_manual_updte_scr_id(U16 update_scr_id);
extern void mmi_dcd_set_url_type(U8 url_type);
extern void mmi_dcd_launch_wap_browser(void);

/* story list related functions */
extern void mmi_dcd_entry_story_list(void);
extern void mmi_dcd_pre_entry_saved_story_list(void);
extern void mmi_dcd_entry_story_list_from_viewer(void);
extern void mmi_dcd_saved_story_list_delete_confirm(void);
extern void mmi_dcd_saved_story_list_delete_all_confirm(void);

/* story viewer related functions */
extern void mmi_dcd_enter_story_viewer(void);
extern void mmi_dcd_enter_saved_story_viewer(void);
extern void mmi_dcd_viewer_save_story(void);
extern void mmi_dcd_pre_entry_object_list(void);
extern void mmi_dcd_viewer_delete_story(void);
extern void mmi_dcd_forward_sms(void);
extern void mmi_dcd_forward_mms(void);
#ifdef __MMI_EMAIL__
extern void mmi_dcd_forward_email(void);
#endif
extern void mmi_dcd_cui_storage_selector_proc(cui_storage_selector_result_event_struct *result_event);
extern void mmi_dcd_cui_filename_editor_proc(cui_filename_editor_result_event_struct *result_event);
extern void mmi_dcd_set_back_state(MMI_BOOL back_state);
extern MMI_BOOL mmi_dcd_get_back_state(void);

/* idle related functions */
extern void mmi_dcd_wakeup_prompt(void);
extern void mmi_dcd_create_root_gid(void);

/* Misc functions */
extern int mmi_dcd_get_attr_from_sl(const kal_wchar  * filename, kal_char ** url,  kal_char ** action);
extern int mmi_dcd_get_attr_from_slc(const kal_wchar  * filename, kal_char ** url,  kal_char ** action);
extern int mmi_dcd_stricmp(const char *s1, const char *s2);
extern int mmi_dcd_strnicmp(const char *s1, const char *s2, unsigned int n);

#endif/*__MMI_OP01_DCD__*/
#endif/*_DCD_PROT_H*/

