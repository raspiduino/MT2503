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
 * SSOAPPSrc.c
 *
 * Project:
 * --------
 *	 MAUI
 *
 * Description:
 * ------------
 *	This file is intends for Yahoo service Settings Acconuts
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!

*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#include "MMI_features.h"


#if defined (__MMI_SSO__) || defined (__SOCIAL_NETWORK_SUPPORT__)
#include "GlobalDefs.h"
#include "MMIDataType.h"
#include "gui_typedef.h"
#include "common_nvram_editor_data_item.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "GlobalResDef.h"
#include "wgui_categories_search.h"

#include "ProfilesSrvGprot.h" /* SUCCESS_TONE */
#include "CommonScreens.h"    /* DisplayPopup */
#include "MenuCuiGprot.h"     /* cui_menu_event_struct */
#include "wgui_categories_popup.h" /* UI_POPUP_NOTIFYDURATION_TIME */
#include "InlineCuiGprot.h"   /* CUI_INLINE_INSERT_TAIL */
#include "Wgui_categories_util.h"/* register left and right key */

#include "mmi_rp_app_sso_def.h" /* sso app gen about yahoo service */
#include "SsoSrvGprot.h" /*sso service interface */
#include "PhbSrvGprot.h" /* phb contacts srv*/
#include "SmsSrvGprot.h" /*sms srv*/
#if defined (__VCARD_CLOUD_SUPPORT__) || defined (__SMS_CLOUD_SUPPORT__)
#include "CloudSrvGprot.h" /*cloud service*/
#endif
#include "SsoCuiGprot.h" /* sso cui */
#include "MMI_common_app_trc.h"
#include "mmi_rp_app_sso_def.h"
#include "CommonScreensResDef.h"/*EVT_ID_ALERT_QUIT*/
#ifdef __MMI_SSO__
#include "mmi_rp_srv_sso_def.h"
#endif
#ifdef __SOCIAL_NETWORK_SUPPORT__
#include "snssrvgprot.h" /*sns service*/
#include "SnsAppGprot.h" /*sync interval and news reminder*/
#include "SnsCuiGprot.h" /*sync cui */
#include "mmi_rp_srv_sns_def.h"
#endif
#ifdef __USB_IN_NORMAL_MODE__
#include "USBSrvGprot.h"
#include "USBDeviceGprot.h"
#endif
#include "mmi_frm_app_launcher_gprot.h"
/*when useable nw*/
#include "NwUsabSrvGprot.h"
#include "DtcntSrvGprot.h"

typedef enum
{
    MMI_SSO_BACKUP,
    MMI_SSO_RESTORE,
    MMI_SSO_CONTACT_BACKUP,
    MMI_SSO_CONTACT_RESTORE,
    MMI_SSO_SMS_BACKUP,
    MMI_SSO_SMS_RESTORE
} mmi_sso_op_enum;
/* nss list infor and nss app setting infor*/
typedef struct
{
    WCHAR provider_name[SRV_SSO_NAME_SIZE];
    WCHAR account_name_buffer[SRV_SSO_NAME_SIZE];
    WCHAR account_icon_buffer[MMI_MAX_FILE_NAME_LEN];
	U32 provider;
    S32 current_index;
    MMI_BOOL is_login;
	U8 account_id;
} mmi_sso_accounts_infor_struct;

typedef struct
{
    U8 contacts_s;/* contacts whether select, 1 is selected */
    U8 sms_s;/* sms whether select, 1 is selected */
    S32 contacts_result; /* result of contacts operation, when restore the sms, the result is the return infor */
    S32 sms_result; /* result of contacts operation when restore the sms, the result is the return infor */
    srv_phb_handle handle_contacts;
    SMS_HANDLE handle_sms;
	void *phb; /*asm ptr*/
	void *sms; /*asm ptr*/ 
	UI_string_type string;
	mmi_id sso_logoutpop_gid;
    U8 retore_list[2]; 
    U8 backup_list[2];
    U8 current_list[2];
	mmi_menu_id backup_restore_current_item;
	MMI_BOOL sms_start;
	U8 process;
    mmi_sso_op_enum op;
    S8 * itemlist[2];
    S32 number_of_items;
	S8 * item_state_ptr;
    WCHAR* description;
} mmi_sso_other_infor_struct;

/* restore scrn item pos enum*/
typedef enum 
{
    MMI_SSO_RESTORE_SCR_CONNECTS,
    MMI_SSO_RESTORE_SCR_SMS,
    MMI_SSO_RESTORE_SCR_CAUTION,
    MMI_SSO_RESTORE_SCR_TOTAL
} mmi_sso_restore_scr_item_enum;

/* restore scrn item pos enum*/
typedef enum 
{
    MMI_SSO_RESTORE_SCR_SELECTED_NO,
    MMI_SSO_RESTORE_SCR_SELECTED,
    MMI_SSO_RESTORE_SCR_SELECTED_TOTAL
} mmi_sso_restore_scr_item_select_enum;

typedef struct
{
    S32 index;/*from 0*/
    U32 provider;
    MMI_BOOL logstatus;
} mmi_sso_sns_account_infor_struct;

typedef struct
{
    S32 list_id;
	S32 current_index;
    mmi_sso_sns_account_infor_struct *paccounts;
    U16 total; /*.......*/
    MMI_BOOL sso_sns_launch;
	#ifndef __MMI_SUPPORT_ASMV2__
	KAL_ADM_ID adm_id;
	void *asm_pool;
	#endif
} mmi_sso_sns_infor_struct;

mmi_sso_other_infor_struct* g_sso_other_cxt_ptr;
mmi_sso_accounts_infor_struct* g_sso_cxt_ptr;
mmi_sso_sns_infor_struct g_sso_sns_cxt;
MMI_BOOL g_ssocui_startup = MMI_FALSE;
MMI_BOOL g_sso_bootup_ready = MMI_FALSE;

void mmi_sso_login_opt(void);
mmi_ret mmi_sso_login_gproc(mmi_event_struct *evt);
void mmi_sso_login_opt_login(void);
void mmi_sso_login_bootup(void);
mmi_ret mmi_sso_logout_gproc(mmi_event_struct *evt);
void mmi_sso_main(void);
void mmi_sso_accounts_sns_entry(void);
void mmi_sso_accounts_entry(void);
mmi_ret mmi_sso_accounts_gproc(mmi_event_struct *evt);
void mmi_sso_main_pre(void);
void mmi_sso_free(void);
void mmi_sso_malloc(void);
mmi_ret mmi_sso_accounts_sproc(mmi_event_struct *evt);
mmi_ret mmi_sso_result_comfirm_proc(mmi_event_struct *evt);

#ifdef __MMI_SSO__
void mmi_sso_accounts_get_item_infor(S32 i);
void mmi_sso_uptate_pro_bar(UI_string_type str);
mmi_ret mmi_sso_backup_restore_gpro(mmi_event_struct *evt);
void mmi_sso_backup_restore_bar_scr(void);
void mmi_sso_backup_restore_error_popup(UI_string_type string);
#endif
#ifdef __SMS_CLOUD_SUPPORT__
void mmi_sso_backup_restore_sms();
#endif

#ifdef __VCARD_CLOUD_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sso_contacts_abort
 * DESCRIPTION
 *  backup of contacts abort
 * PARAMETERS
 *  evt    : [IN] mmi_event_struct
 * RETURNS
 * void
 *****************************************************************************/
static void mmi_sso_contacts_abort(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_sso_other_cxt_ptr->handle_contacts)
    {
        srv_phb_free_handle(g_sso_other_cxt_ptr->handle_contacts);
        g_sso_other_cxt_ptr->handle_contacts = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_asm_phb_malloc
 * DESCRIPTION
 *  alloc phb asm space
 * PARAMETERS
 *  U32 size[IN]
 * RETURNS
 *  the malloc ptr
 *****************************************************************************/
static void* mmi_sso_asm_phb_malloc(U32 size)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_asm_property_struct p;
	mmi_frm_asm_property_init(&p);
	mmi_frm_asm_set_property(APP_SSO, &p);
	g_sso_other_cxt_ptr->phb = mmi_frm_asm_alloc_r(APP_SSO, size);  
	if (g_sso_other_cxt_ptr->phb)
	{
        memset(g_sso_other_cxt_ptr->phb, 0x00, size);
		return g_sso_other_cxt_ptr->phb;
	}
	else
	{
		return NULL;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_asm_phb_free
 * DESCRIPTION
 *  free phb asm space
 * PARAMETERS
 *  void* ptr [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_asm_phb_free(void* ptr)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (ptr)
	{
		mmi_frm_asm_free_r(APP_SSO, ptr);
	}
	g_sso_other_cxt_ptr->phb = NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sso_get_contact_op_value
 * DESCRIPTION
 *  get the contact value
 * PARAMETERS
 *  mmi_sso_op_enum op_type, U16 value [IN]
 * RETURNS
 *  U8 the value
 *****************************************************************************/
static U8 mmi_sso_get_contact_op_value(mmi_sso_op_enum op_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 value;
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_SSOAPP_CONTACTS_BACKUP_RESTORE, &value, DS_BYTE, &error);
    if (op_type == MMI_SSO_CONTACT_BACKUP || op_type == MMI_SSO_BACKUP)
    {
        return ((value & 0x10) >> 4);
    }
    else if (op_type == MMI_SSO_CONTACT_RESTORE || op_type == MMI_SSO_RESTORE)
    {
        return (value & 0x01);
    }
	return value;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_set_contact_op_value
 * DESCRIPTION
 *  set contact value 
 * PARAMETERS
 *  mmi_sso_op_enum op_type, U16 value [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_set_contact_op_value(mmi_sso_op_enum op_type, U8 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 tempValue;  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_SSOAPP_CONTACTS_BACKUP_RESTORE, &tempValue, DS_BYTE, &error);
    if (op_type == MMI_SSO_CONTACT_BACKUP || op_type == MMI_SSO_BACKUP)
    {
		tempValue = (tempValue & 0x0F) | (value << 4);
    }
    else if (op_type == MMI_SSO_CONTACT_RESTORE || op_type == MMI_SSO_RESTORE)
    {
        tempValue = (tempValue & 0xF0) | value;
    }
    WriteValue(NVRAM_SSOAPP_CONTACTS_BACKUP_RESTORE, &tempValue, DS_BYTE, &error);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_sso_contact_display_popup
 * DESCRIPTION
 *  abort restore of contact
 * PARAMETERS
 *  S32 error, 
 * MMI_BOOL flag , MMI_TRUE is backup, MMI_FALSE is restore
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_contact_display_popup(S32 error, MMI_BOOL is_backup)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_confirm_property_struct arg; 
	MMI_ID_TYPE string_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_OK);
    arg.parent_id = GRP_ID_MMI_SSO_OUT;
    arg.callback = (mmi_proc_func)mmi_sso_result_comfirm_proc;
    switch (error)
    {
        case SRV_PHB_CLOUD_LOGOUT:/*net cookie expired*/
			string_id = STR_ID_MMI_SSO_COOKIE_EXOIRE;
            break;	
        case SRV_PHB_CLOUD_NO_STORAGE:/* cloud service will nomemory card to use*/
			string_id = STR_ID_MMI_SSO_PLE_MEMORY_CARD;
            break;		
		/*If user inserts memory card, cloud service will write temp files in memory card.If memory card space is not enough, there will be error code*/
        case SRV_PHB_CLOUD_DISK_FULL:
			string_id = STR_GLOBAL_INSUFFICIENT_MEMORY;
            break;
		case SRV_PHB_STORAGE_FULL:/* no enough nvram*/
            string_id = STR_ID_MMI_SSO_RESTORE_FAILED_CAUTION;   
        	break;	
        case SRV_PHB_CLOUD_NO_NEED_SYNC:
			if (g_sso_other_cxt_ptr->sms_s) /*string_id may be no value*/
			{
				return ;
			}
			else
			{
				string_id = is_backup ? STR_ID_MMI_SSO_NO_CONTACTS_BACKUP : STR_ID_MMI_SSO_NO_CONTACTS_RESTORE;
				break;
			}
		case SRV_PHB_NO_ERROR:	/*string_id may be no value*/
			return ;	
		default:
			string_id = STR_GLOBAL_FAILED;
            break;
    }
	if (error == SRV_PHB_STORAGE_FULL)
	{
    	mmi_sso_backup_restore_error_popup((UI_string_type)GetString(string_id));   
	}
	else
	{
		mmi_confirm_display((WCHAR*)get_string(string_id), MMI_EVENT_FAILURE, &arg);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_backup_restore_contacts
 * DESCRIPTION
 *  callback for contacts
 * PARAMETERS
 *  info [IN] srv_phb_async_op_cb_struct* 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_backup_restore_contacts_cb(srv_phb_async_op_cb_struct* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_multi_op_status_cb_struct *update;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (info->type == SRV_PHB_OP_CB_TYPE_RESTORE)  /*Last when contacts restore is ok, then start sms*/
    {
        srv_phb_restore_cb_struct *restoreFinish = (srv_phb_restore_cb_struct *)info;
    	g_sso_other_cxt_ptr->contacts_result = restoreFinish->result;
        MMI_TRACE(MMI_INET_TRC_G7_SSO, MMI_SSO_BACKUP_RESTORE_CONTACTS_CB, restoreFinish->result);
	    if ((restoreFinish->result == SRV_PHB_NO_ERROR || restoreFinish->result == SRV_PHB_CLOUD_NO_NEED_SYNC))
	    {  
			g_sso_other_cxt_ptr->process = 100;
            mmi_sso_uptate_pro_bar((UI_string_type)GetString(STR_ID_MMI_SSO_RESTORE_PRO_CONTACTS));
			mmi_sso_contact_display_popup(restoreFinish->result, MMI_FALSE);
			#ifdef __SMS_CLOUD_SUPPORT__
		        if (g_sso_other_cxt_ptr->sms_s)/*when contacts restore is ok, then start sms*/
		        {
		            mmi_sso_backup_restore_sms();
					return;
		        }
			#endif
			mmi_frm_scrn_close(GCR_ID_MMI_SSO_BACKUP_RESTORE_ENTRY, SCR_ID_MMI_SSO_BACKUP_RESTORE_BAR);
			if (restoreFinish->result == SRV_PHB_NO_ERROR)mmi_frm_group_close(GRP_ID_MMI_SSO_OUT);
	    }
	    else /* SRV_PHB_STORAGE_FULL or other error */
	    {
			mmi_frm_scrn_close(GCR_ID_MMI_SSO_BACKUP_RESTORE_ENTRY, SCR_ID_MMI_SSO_BACKUP_RESTORE_BAR);
			mmi_sso_contact_display_popup(restoreFinish->result, MMI_FALSE);
	    }  
    }
    else if (info->type == SRV_PHB_OP_CB_TYPE_BACKUP)
    {
        srv_phb_backup_cb_struct *restoreFinish = (srv_phb_backup_cb_struct *)info;
    	g_sso_other_cxt_ptr->contacts_result = restoreFinish->result;
        MMI_TRACE(MMI_INET_TRC_G7_SSO, MMI_SSO_BACKUP_RESTORE_CONTACTS_CB2, restoreFinish->result);
        if (restoreFinish->result == SRV_PHB_NO_ERROR || restoreFinish->result == SRV_PHB_CLOUD_NO_NEED_SYNC)
        {  
			g_sso_other_cxt_ptr->process = 100;
            mmi_sso_uptate_pro_bar((UI_string_type)GetString(STR_ID_MMI_SSO_BACKUP_PRO_CONTACTS));
            mmi_sso_contact_display_popup(restoreFinish->result, MMI_TRUE);
    		#ifdef __SMS_CLOUD_SUPPORT__
				if (g_sso_other_cxt_ptr->sms_s)/*when contacts restore is ok, then start sms*/
				{
					mmi_sso_backup_restore_sms();
					return;
				}			
			#endif	
			mmi_frm_scrn_close(GCR_ID_MMI_SSO_BACKUP_RESTORE_ENTRY, SCR_ID_MMI_SSO_BACKUP_RESTORE_BAR);
			if (restoreFinish->result == SRV_PHB_NO_ERROR)mmi_frm_group_close(GRP_ID_MMI_SSO_OUT);
        }
        else /* SRV_PHB_STORAGE_FULL or other error */
        {
			mmi_frm_scrn_close(GCR_ID_MMI_SSO_BACKUP_RESTORE_ENTRY, SCR_ID_MMI_SSO_BACKUP_RESTORE_BAR);
			mmi_sso_contact_display_popup(restoreFinish->result, MMI_TRUE);
		}	         
    }
    else
    {
        U16 stringId;
		U16 count = srv_phb_get_total_contact(PHB_STORAGE_NVRAM);
        update = (srv_phb_multi_op_status_cb_struct *)info;
        if (count == 0)
        {
            g_sso_other_cxt_ptr->process = 100;
        }
        else
        {
            g_sso_other_cxt_ptr->process = (U8)((update->finish_count * 100 / count));
        }
        if (g_sso_other_cxt_ptr->op == MMI_SSO_BACKUP)
        {
            stringId = STR_ID_MMI_SSO_BACKUP_PRO_CONTACTS;
        }
        else
        {
            stringId = STR_ID_MMI_SSO_RESTORE_PRO_CONTACTS;
        }
        mmi_sso_uptate_pro_bar((UI_string_type)GetString(stringId));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_backup_restore_contacts
 * DESCRIPTION
 *  restore of contacts
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_backup_restore_contacts(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_sso_other_cxt_ptr->handle_contacts)
	{
		srv_phb_free_handle(g_sso_other_cxt_ptr->handle_contacts);
        g_sso_other_cxt_ptr->handle_contacts = NULL;
	}
	g_sso_other_cxt_ptr->process = 0;
    if (g_sso_other_cxt_ptr->op == MMI_SSO_BACKUP)
    {
        srv_phb_backup_req_struct req;
    	memset(&req, 0, sizeof(srv_phb_backup_req_struct));
        req.cb = mmi_sso_backup_restore_contacts_cb;
        req.provider = g_sso_cxt_ptr->provider;
        req.account = g_sso_cxt_ptr->account_id;
        req.mode = SRV_PHB_BACKUP_RESTORE_MODE_CLOUD;
        req.storage = PHB_STORAGE_NVRAM; 
    	req.free_func = mmi_sso_asm_phb_free;
    	req.malloc_func = mmi_sso_asm_phb_malloc;
        g_sso_other_cxt_ptr->handle_contacts = srv_phb_backup_contact(&req);
    }
    else
    {  
        srv_phb_restore_req_struct req;
    	memset(&req, 0, sizeof(srv_phb_restore_req_struct));
        req.cb = mmi_sso_backup_restore_contacts_cb;
        req.provider = g_sso_cxt_ptr->provider;
        req.account = g_sso_cxt_ptr->account_id;
        req.mode = SRV_PHB_BACKUP_RESTORE_MODE_CLOUD;
    	req.free_func = mmi_sso_asm_phb_free;
    	req.malloc_func = mmi_sso_asm_phb_malloc;
        g_sso_other_cxt_ptr->handle_contacts = srv_phb_restore_contact(&req);
    }
}
#endif


#ifdef __SMS_CLOUD_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sso_sms_abort
 * DESCRIPTION
 *  abort restore of sms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_sms_abort(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_sso_other_cxt_ptr->handle_sms)
    {
        srv_sms_abort_cloud(g_sso_other_cxt_ptr->handle_sms, NULL, NULL);
        g_sso_other_cxt_ptr->handle_sms = NULL;
		g_sso_other_cxt_ptr->sms_start = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_contact_display_popup
 * DESCRIPTION
 *  abort restore of sms
 * PARAMETERS
 *  S32 error, 
 * MMI_BOOL flag , MMI_TRUE is backup, MMI_FALSE is restore
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_sms_display_popup(S32 error, MMI_BOOL flag)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_confirm_property_struct arg;
	MMI_ID_TYPE string_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_confirm_property_init(&arg, CNFM_TYPE_OK);
	arg.parent_id = GRP_ID_MMI_SSO_OUT;
	arg.callback = (mmi_proc_func)mmi_sso_result_comfirm_proc;
	switch (error)
	{
		case SRV_SMS_CAUSE_CLOUD_LOGOUT:/*net cookie expired*/
			string_id = STR_ID_MMI_SSO_COOKIE_EXOIRE;
			break;		
		case SRV_SMS_CAUSE_CLOUD_NO_STORAGE:/* cloud service will nomemory card to use*/
			string_id = STR_ID_MMI_SSO_PLE_MEMORY_CARD;
			break;		
		/*If user inserts memory card, cloud service will write temp files in memory card.If memory card space is not enough, there will be error code:*/
		case SRV_SMS_CAUSE_CLOUD_DISK_FULL:
			string_id = STR_GLOBAL_INSUFFICIENT_MEMORY;
			break;
		case SRV_SMS_CAUSE_MEM_FULL:/* no enough nvram*/
	        string_id = STR_ID_MMI_SSO_RESTORE_FAILED_CAUTION;   
		    break;		
		case SRV_SMS_CAUSE_CLOUD_NO_NEED_SYNC:/*no need to backup and restore*/
			if (g_sso_other_cxt_ptr->contacts_s && (g_sso_other_cxt_ptr->contacts_result == SRV_PHB_CLOUD_NO_NEED_SYNC || srv_phb_get_used_contact(PHB_STORAGE_NVRAM) == 0))
			{
				string_id = flag ? STR_ID_MMI_SSO_NO_APP_DATA_BACKUP : STR_ID_MMI_SSO_NO_APP_DATA_RESTORE;	
				break;
			}
			else
			{
				string_id = flag ? STR_ID_MMI_SSO_NO_SMS_BACKUP : STR_ID_MMI_SSO_NO_SMS_RESTORE;	
			}
			break;		
		case SRV_SMS_CAUSE_NO_ERROR: /*string_id may be no value*/
			if (g_sso_other_cxt_ptr->contacts_s && (g_sso_other_cxt_ptr->contacts_result == SRV_PHB_CLOUD_NO_NEED_SYNC || srv_phb_get_used_contact(PHB_STORAGE_NVRAM) == 0))
			{
				string_id = flag ? STR_ID_MMI_SSO_NO_CONTACTS_BACKUP : STR_ID_MMI_SSO_NO_CONTACTS_RESTORE;
			}
			break;		
		default:
			string_id = STR_GLOBAL_FAILED;	
			break;
	}
	if (error == SRV_SMS_CAUSE_MEM_FULL)
	{
        mmi_sso_backup_restore_error_popup((UI_string_type)GetString(string_id));
	}
	else if (string_id !=0)
	{
		mmi_confirm_display((WCHAR*)get_string(string_id), MMI_EVENT_FAILURE, &arg);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_get_sms_op_value
 * DESCRIPTION
 *  get the sms value
 * PARAMETERS
 *  mmi_sso_op_enum op_type, U16 value [IN]
 * RETURNS
 *  U8 the value
 *****************************************************************************/
static U8 mmi_sso_get_sms_op_value(mmi_sso_op_enum op_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 value;
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_SSOAPP_SMS_BACKUP_RESTORE, &value, DS_BYTE, &error);
    if (op_type == MMI_SSO_SMS_BACKUP || op_type == MMI_SSO_BACKUP)
    {
        return ((value & 0x10) >> 4);
    }
    else if (op_type == MMI_SSO_SMS_RESTORE || op_type == MMI_SSO_RESTORE)
    {
        return (value & 0x01);
    }
	return value;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_set_sms_op_value
 * DESCRIPTION
 *  set sms value 
 * PARAMETERS
 *  mmi_sso_op_enum op_type, U16 value [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_set_sms_op_value(mmi_sso_op_enum op_type, U8 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 tempValue; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_SSOAPP_SMS_BACKUP_RESTORE, &tempValue, DS_BYTE, &error);
    if (op_type == MMI_SSO_SMS_BACKUP || op_type == MMI_SSO_BACKUP)
    {
        tempValue = (tempValue & 0x0F) | (value << 4);
    }
    else if (op_type == MMI_SSO_SMS_RESTORE || op_type == MMI_SSO_RESTORE)
    {
		tempValue = (tempValue & 0xF0) | value;
    }
    WriteValue(NVRAM_SSOAPP_SMS_BACKUP_RESTORE, &tempValue, DS_BYTE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_backup_sms_cb
 * DESCRIPTION
 *  SMS Service Callback function type.
 *  All SMS asynchronous operation is used callback mechanism to return the result. 
 * PARAMETERS
 * callback_data    [IN]   Callback result data, refer to  srv_sms_callback_struct.
 * RETURNS
 *  void
*****************************************************************************/
static void mmi_sso_backup_restore_sms_cb(srv_sms_callback_struct* callback_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 stringId;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G7_SSO, MMI_SSO_BACKUP_RESTORE_SMS_CB, callback_data->result, callback_data->cause, callback_data->action);
    g_sso_other_cxt_ptr->process = 100;
    g_sso_other_cxt_ptr->sms_result = callback_data->cause;
    g_sso_other_cxt_ptr->handle_sms = NULL;
    if (mmi_frm_scrn_is_present(
        GCR_ID_MMI_SSO_BACKUP_RESTORE_ENTRY, 
        SCR_ID_MMI_SSO_BACKUP_RESTORE_BAR,
        MMI_FRM_NODE_ALL_FLAG))
    {
        if (g_sso_other_cxt_ptr->op == MMI_SSO_BACKUP)
        {
            stringId = STR_ID_MMI_SSO_BACKUP_PRO_SMS;
        }
        else
        {
            stringId = STR_ID_MMI_SSO_RESTORE_PRO_SMS;
        }
        mmi_sso_uptate_pro_bar((UI_string_type)GetString(stringId));
        mmi_frm_scrn_close(GCR_ID_MMI_SSO_BACKUP_RESTORE_ENTRY, SCR_ID_MMI_SSO_BACKUP_RESTORE_BAR);
    }
    g_sso_other_cxt_ptr->process = 0;
	if (g_sso_other_cxt_ptr->sms_start == MMI_FALSE)return;
	g_sso_other_cxt_ptr->sms_start = MMI_FALSE;
    mmi_frm_scrn_close(GCR_ID_MMI_SSO_BACKUP_RESTORE_ENTRY, SCR_ID_MMI_SSO_BACKUP_RESTORE_BAR);
    mmi_sso_sms_display_popup(callback_data->cause, g_sso_other_cxt_ptr->op == MMI_SSO_BACKUP ? MMI_TRUE : MMI_FALSE);
	if (callback_data->cause == SRV_SMS_CAUSE_NO_ERROR)mmi_frm_group_close(GRP_ID_MMI_SSO_OUT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_restore_sms
 * DESCRIPTION
 *  restore of sms
 * PARAMETERS
 *  evt    : [IN] mmi_event_struct
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_backup_restore_sms()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_backup_restore_info_struct restore_info;
    srv_cloud_set_opt_acct_info_struct account_info;
    U16 stringId;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&restore_info, 0, sizeof(srv_sms_backup_restore_info_struct));
    memset(&account_info, 0, sizeof(srv_cloud_set_opt_acct_info_struct));
    g_sso_other_cxt_ptr->process = 0;
    g_sso_other_cxt_ptr->sms_start = MMI_TRUE;
    restore_info.account_info = &account_info;
    restore_info.box_type = SRV_SMS_BOX_INBOX;    /* now only inbox */
    restore_info.backup_restore_type = SRV_SMS_BACKUP_RESTORE_CLOUD;
    restore_info.account_info->account_id = g_sso_cxt_ptr->account_id;
    restore_info.account_info->provider = g_sso_cxt_ptr->provider;
    if (mmi_frm_scrn_is_present(
        GCR_ID_MMI_SSO_BACKUP_RESTORE_ENTRY, 
        SCR_ID_MMI_SSO_BACKUP_RESTORE_BAR,
        MMI_FRM_NODE_ALL_FLAG))
    {
        if (g_sso_other_cxt_ptr->op == MMI_SSO_BACKUP)
        {
            stringId = STR_ID_MMI_SSO_BACKUP_PRO_SMS;
        }
        else
        {
            stringId = STR_ID_MMI_SSO_RESTORE_PRO_SMS;
        }
        mmi_sso_uptate_pro_bar((UI_string_type)GetString(stringId));
    }
    
    if (g_sso_other_cxt_ptr->op == MMI_SSO_BACKUP)
    {      
        g_sso_other_cxt_ptr->handle_sms = srv_sms_backup_msg(restore_info, mmi_sso_backup_restore_sms_cb, NULL);
    }
    else
    {
        g_sso_other_cxt_ptr->handle_sms = srv_sms_restore_msg(restore_info, mmi_sso_backup_restore_sms_cb, NULL);
    }	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_restore_sms_evt_hdlr
 * DESCRIPTION
 *  DM Self-Register Function
 * PARAMETERS
 *  dummy       [IN]        Input message
 *  mod         [IN]        Module type
 *  result      [IN]        Message Result
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
extern mmi_ret mmi_sso_sms_evt_hdlr(mmi_event_struct* event_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_backup_restore_struct *evt = (srv_sms_event_backup_restore_struct *)(((srv_sms_event_struct *)event_data)->event_info);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (g_sso_other_cxt_ptr == NULL)
	{
		return MMI_RET_OK;
	}
	if (g_sso_other_cxt_ptr->sms_start == MMI_FALSE)
	{
		return MMI_RET_OK;
	}
    if (evt->Total_number == 0)
    {
        g_sso_other_cxt_ptr->process = 100;
    }
    else
    {
        g_sso_other_cxt_ptr->process =(U8)((evt->cur_index * 100) / evt->Total_number); 
    } 
    if (evt->action == SRV_SMS_ACTION_RESTORE)
    {
        mmi_sso_uptate_pro_bar((UI_string_type)GetString(STR_ID_MMI_SSO_RESTORE_PRO_SMS));
    }
    else if (evt->action == SRV_SMS_ACTION_BACKUP)
    {
        mmi_sso_uptate_pro_bar((UI_string_type)GetString(STR_ID_MMI_SSO_BACKUP_PRO_SMS));
    }
    return MMI_RET_OK;
}
#endif


#ifdef __MMI_SSO__
/*****************************************************************************
 * FUNCTION
 *  mmi_sso_assount_nw_avaiable
 * DESCRIPTION
 *  nw status
 * PARAMETERS
 *  mmi_event_struct *evt
 * RETURNS
 *  U8 	1.STR_GLOBAL_UNAVAILABLE_IN_FLIGHT_MODE;2.STR_ID_MMI_SSO_NO_NW_CONNECTION;
 *****************************************************************************/
static U8 mmi_sso_assount_nw_avaiable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_nw_usab_any_sim_is_usable())
    {
        ret = 1; /*not available*/
    }
    #ifdef __MMI_WLAN_FEATURES__
        if (srv_dtcnt_wlan_status() == SRV_DTCNT_WLAN_STATUS_INACTIVE)
        {
        	if (ret == 0) return ret;
            ret = 2; /*no nw*/
        }
    	else
    	{
    		ret = 0;
    	}
    #endif /* __MMI_WLAN_FEATURES__ */
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_pluging_upgrade_proc
 * DESCRIPTION
 *  sso upgrade evt
 * PARAMETERS
 *  mmi_event_struct *evt
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
extern mmi_ret mmi_sso_pluging_upgrade_proc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sso_evt_plugins_upgraded_struct *upgrade = (srv_sso_evt_plugins_upgraded_struct *)evt;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if (upgrade->is_successful)
	{
		mmi_popup_display_ext(STR_ID_SSO_SSO_UPGRADE_SUCCESS, MMI_EVENT_SUCCESS, NULL);
	}
	else
	{
		mmi_popup_display_ext(STR_ID_SSO_SSO_UPGRADE_FAILURE, MMI_EVENT_FAILURE, NULL);
	}
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_not_ready_proc
 * DESCRIPTION
 *  sso ready evt
 * PARAMETERS
 *  mmi_event_struct *evt
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_sso_not_ready_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sso_evt_ready_struct *ready = (srv_sso_evt_ready_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!ready->is_ready)
    {
        if (mmi_frm_group_is_present(GRP_ID_MMI_SSO))
        {
            mmi_frm_group_close(GRP_ID_MMI_SSO);
        }  
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_contacts_sms_abort
 * DESCRIPTION
 *  abort restore
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_contacts_sms_abort(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __VCARD_CLOUD_SUPPORT__
    	if (g_sso_other_cxt_ptr->contacts_s)
        {
            mmi_sso_contacts_abort();
        }
	#endif
	#ifdef __SMS_CLOUD_SUPPORT__
        if (g_sso_other_cxt_ptr->sms_s)
        {
            mmi_sso_sms_abort();
        }
	#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_uptate_pro_bar
 * DESCRIPTION
 *  try to refresh the status 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_uptate_pro_bar(UI_string_type str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat6003_update_all(str, NULL, g_sso_other_cxt_ptr->process);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_backup_restore_abort
 * DESCRIPTION
 *  abort backup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_backup_restore_abort(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G7_SSO, MMI_SSO_BACKUP_RESTORE_ABORT, g_sso_other_cxt_ptr->contacts_s, g_sso_other_cxt_ptr->sms_s);
	mmi_sso_contacts_sms_abort();
    mmi_frm_scrn_close(GCR_ID_MMI_SSO_BACKUP_RESTORE_ENTRY, SCR_ID_MMI_SSO_BACKUP_RESTORE_BAR);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sso_backup_restore_get_value
 * DESCRIPTION
 *  get the op value
 * PARAMETERS
 *  op    [IN]    mmi_sso_op_enum 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_backup_restore_get_value(mmi_sso_op_enum op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if defined (__VCARD_CLOUD_SUPPORT__) && defined (__SMS_CLOUD_SUPPORT__)
        g_sso_other_cxt_ptr->current_list[0] = mmi_sso_get_contact_op_value(op);
        g_sso_other_cxt_ptr->current_list[1] = mmi_sso_get_sms_op_value(op);
    #else
        #ifdef __VCARD_CLOUD_SUPPORT__
            g_sso_other_cxt_ptr->current_list[0] = mmi_sso_get_contact_op_value(op);
		#endif
        #ifdef __SMS_CLOUD_SUPPORT__
            g_sso_other_cxt_ptr->current_list[1] = mmi_sso_get_sms_op_value(op);
        #endif
    #endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_backup_restore_get_value
 * DESCRIPTION
 *  get the op value
 * PARAMETERS
 *  op    [IN]    mmi_sso_op_enum 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_backup_restore_set_value()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sso_op_enum op = g_sso_other_cxt_ptr->op; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if defined (__VCARD_CLOUD_SUPPORT__) && defined (__SMS_CLOUD_SUPPORT__)
        mmi_sso_set_contact_op_value(op, g_sso_other_cxt_ptr->current_list[0]);
        mmi_sso_set_sms_op_value(op, g_sso_other_cxt_ptr->current_list[1]);
    #else
        #ifdef __VCARD_CLOUD_SUPPORT__
            mmi_sso_set_contact_op_value(op, g_sso_other_cxt_ptr->current_list[0]);
		#endif
        #ifdef __SMS_CLOUD_SUPPORT__
            mmi_sso_set_sms_op_value(op, g_sso_other_cxt_ptr->current_list[1]);
        #endif
    #endif 
    g_sso_other_cxt_ptr->contacts_s = g_sso_other_cxt_ptr->current_list[0];
    g_sso_other_cxt_ptr->sms_s = g_sso_other_cxt_ptr->current_list[1];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_backup_restore_scr_pre
 * DESCRIPTION
 *  backup restore screen prepare data
 * PARAMETERS
 *  op    [IN]    mmi_sso_op_enum 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_backup_restore_scr_pre(mmi_sso_op_enum op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 stringId = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sso_other_cxt_ptr->op = op;
    if (op == MMI_SSO_RESTORE)
    {
        stringId = STR_ID_MMI_SSO_ACCOUNTS_SELECT_RESTORE_CAUTION;
    }
    else
    {
        stringId = STR_ID_MMI_SSO_ACCOUNTS_SELECT_BACKUP_CAUTION;
    }
    g_sso_other_cxt_ptr->description = (WCHAR *)GetString(stringId);
    #if defined (__VCARD_CLOUD_SUPPORT__) && defined (__SMS_CLOUD_SUPPORT__)
        g_sso_other_cxt_ptr->itemlist[0] = GetString(STR_ID_MMI_SSO_ACCOUNTS_SELECT_CONTACTS);
        g_sso_other_cxt_ptr->itemlist[1] = GetString(STR_ID_MMI_SSO_ACCOUNTS_SELECT_SMS);
        g_sso_other_cxt_ptr->number_of_items = 2;
    	g_sso_other_cxt_ptr->item_state_ptr = g_sso_other_cxt_ptr->current_list;
    #else
    #ifdef __VCARD_CLOUD_SUPPORT__
        g_sso_other_cxt_ptr->itemlist[0] = GetString(STR_ID_MMI_SSO_ACCOUNTS_SELECT_CONTACTS);
		g_sso_other_cxt_ptr->item_state_ptr = &(g_sso_other_cxt_ptr->current_list[0]);
	#endif
    #ifdef __SMS_CLOUD_SUPPORT__
        g_sso_other_cxt_ptr->itemlist[0] = GetString(STR_ID_MMI_SSO_ACCOUNTS_SELECT_SMS);
		g_sso_other_cxt_ptr->item_state_ptr = &(g_sso_other_cxt_ptr->current_list[1]);
    #endif
        g_sso_other_cxt_ptr->number_of_items = 1;
    #endif 
	g_sso_other_cxt_ptr->backup_restore_current_item = 0;
    mmi_sso_backup_restore_get_value(op);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_accounts_restore_opt
 * DESCRIPTION
 *  create spec account's restore's option
 * PARAMETERS
 * void 
 * RETURNS
 * void
 *****************************************************************************/
static void mmi_sso_accounts_restore_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id restore_grop; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    restore_grop= cui_menu_create(
        GCR_ID_MMI_SSO_BACKUP_RESTORE_ENTRY,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_OPTION,
        MENU_ID_MMI_SSO_BACKUP_RESTORE_SCR_OPT,
        MMI_FALSE, /* Use global resource */
        NULL);
    cui_menu_run(restore_grop);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_accounts_restore_scrn_csk
 * DESCRIPTION
 * csk 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_backup_restore_scrn_csk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    standard_check_list_handle_left_softkey_up();
    mmi_sso_backup_restore_set_value(g_sso_other_cxt_ptr->current_list);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightThmUpdatePeriod
 * DESCRIPTION
 *  Hilite function of pupdate period
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sso_checklist_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sso_other_cxt_ptr->backup_restore_current_item = index;
    MMI_TRACE(MMI_INET_TRC_G7_SSO, MMI_SSO_CHECKLIST_HILIGHT_HDLR, index);
}


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_sso_assounts_restore_scrn_tap
 * DESCRIPTION
 * tap 
 * PARAMETERS
 *  mmi_tap_type_enum tap_type, S32 index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_assounts_restore_scrn_tap(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sso_backup_restore_scrn_csk();
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_accounts_restore_sproc
 * DESCRIPTION
 * pro the spec accounts's restore scrn
 * PARAMETERS
 *  evt    : [IN] mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_sso_backup_restore_sproc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (evt->evt_id)
	{
        case EVT_ID_SCRN_ACTIVE:
        	{   
                gui_buffer = mmi_frm_scrn_get_active_gui_buf(); 
                wgui_cat1070_show(
                    g_sso_cxt_ptr->provider_name,
                    NULL,
                    (WCHAR *)GetString(STR_GLOBAL_OPTIONS),
                    NULL,
                    (WCHAR *)GetString(STR_GLOBAL_BACK),
                    NULL,
                    g_sso_other_cxt_ptr->description,
                    g_sso_other_cxt_ptr->number_of_items,
            		(U8 **)g_sso_other_cxt_ptr->itemlist,
					g_sso_other_cxt_ptr->item_state_ptr,
            		g_sso_other_cxt_ptr->backup_restore_current_item,
            		gui_buffer);

                EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
                SetLeftSoftkeyFunction(mmi_sso_accounts_restore_opt, KEY_EVENT_UP);
                SetCenterSoftkeyFunction(mmi_sso_backup_restore_scrn_csk, KEY_EVENT_UP);
                SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
                RegisterHighlightHandler(mmi_sso_checklist_highlight_hdlr);
                #ifdef __MMI_TOUCH_SCREEN__
                    wgui_register_list_item_selected_callback_all(mmi_sso_backup_restore_scrn_csk);
                #endif
                #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
                    wgui_register_tap_callback(mmi_sso_assounts_restore_scrn_tap);
                #endif               
        		break;
        	}  
	}
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_backup_restore_entry
 * DESCRIPTION
 * backup 
 * PARAMETERS
 *  mmi_sso_op_enum op
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_backup_restore_entry(mmi_sso_op_enum op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_group_is_present(GRP_ID_MMI_SSO_OUT))
    {
        mmi_frm_group_create_ex(
            GRP_ID_MMI_SSO, GRP_ID_MMI_SSO_OUT, 
            mmi_sso_logout_gproc, 
            NULL, 
            MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }   
    mmi_sso_backup_restore_scr_pre(op);
    mmi_frm_group_create_ex(GRP_ID_MMI_SSO_OUT, 
                            GCR_ID_MMI_SSO_BACKUP_RESTORE_ENTRY, 
                            mmi_sso_backup_restore_gpro,
                            NULL,
                            MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_create(
        GCR_ID_MMI_SSO_BACKUP_RESTORE_ENTRY, 
        SCR_ID_MMI_SSO_BACKUP_RESTORE_ENTRY_SCR, 
        mmi_sso_backup_restore_sproc, 
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_have_backup_data
 * DESCRIPTION
 *  have contacts or sms?
 * PARAMETERS
 *  void    
 * RETURNS
 *  MMI_BOOL MMI_TRUE is having data, MMI_FALSE is no data to backup
 *****************************************************************************/
static MMI_BOOL mmi_sso_have_backup_data()
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 string_id = 0;
	MMI_BOOL ret = MMI_TRUE;
	mmi_confirm_property_struct arg;
	U8 result = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_confirm_property_init(&arg, CNFM_TYPE_OK);
	arg.parent_id = GRP_ID_MMI_SSO_OUT;
	arg.callback = (mmi_proc_func)mmi_sso_result_comfirm_proc;
	if (g_sso_other_cxt_ptr->op == MMI_SSO_RESTORE)
    {
        ret = MMI_TRUE;
    }
    else
    {
        #if defined (__VCARD_CLOUD_SUPPORT__) && defined (__SMS_CLOUD_SUPPORT__)
    	    if (g_sso_other_cxt_ptr->contacts_s && g_sso_other_cxt_ptr->sms_s)/*contacts and sms no need to backup*/
    	    { 
    			if ((srv_phb_get_used_contact(PHB_STORAGE_NVRAM) == 0) && (srv_sms_is_need_to_backup() == MMI_FALSE))
    			{
    				string_id = STR_ID_MMI_SSO_NO_APP_DATA_BACKUP;
    				ret = MMI_FALSE;
    		    }
    	    }
    		else if (g_sso_other_cxt_ptr->contacts_s)/*contacts no need to backup*/
    		{
    			if (srv_phb_get_used_contact(PHB_STORAGE_NVRAM) == 0)
    			{
    				string_id = STR_ID_MMI_SSO_NO_CONTACTS_BACKUP;
    				ret = MMI_FALSE;
    			}
    		}
    		else/*sms no need to backup*/
    		{
    			if (srv_sms_is_need_to_backup() == MMI_FALSE)
    			{
    				string_id = STR_ID_MMI_SSO_NO_SMS_BACKUP;
    				ret = MMI_FALSE;
    		    }
    		}
	    #else
    		#if defined __VCARD_CLOUD_SUPPORT__
    			if (srv_phb_get_used_contact(PHB_STORAGE_NVRAM) == 0)/*contacts and sms no need to backup*/
    			{
    				string_id = STR_ID_MMI_SSO_NO_CONTACTS_BACKUP;
    				ret = MMI_FALSE;
    		    }
    		#endif
    	    #if defined __SMS_CLOUD_SUPPORT__
    			if (srv_sms_is_need_to_backup() == MMI_FALSE)/*sms no need to backup*/
    			{				
    				string_id = STR_ID_MMI_SSO_NO_SMS_BACKUP;
    				ret = MMI_FALSE;
    		    }
    		#endif
	    #endif	
    }
	if (ret == MMI_TRUE)/*have data to backup or exe restore, judge the nw*/
	{
		result = mmi_sso_assount_nw_avaiable();
		ret = MMI_FALSE;
		if(result == 1)
		{
			string_id = STR_GLOBAL_UNAVAILABLE_IN_FLIGHT_MODE;//mmi_popup_display_ext(STR_GLOBAL_UNAVAILABLE_IN_FLIGHT_MODE, MMI_EVENT_FAILURE, NULL);
		}
		else if (result == 2)
		{
			string_id = STR_ID_MMI_SSO_NO_NW_CONNECTION;//mmi_popup_display_ext(STR_ID_MMI_SSO_NO_NW_CONNECTION, MMI_EVENT_FAILURE, NULL);
		}
		else
		{
			ret = MMI_TRUE;
			string_id = 0;
		}/*0 is nw avilable*/
	}
	if (string_id)
	{
		mmi_confirm_display((WCHAR*)get_string(string_id), MMI_EVENT_FAILURE, &arg);
	}
	return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_backup_restore_exe
 * DESCRIPTION
 *  abort restore
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_backup_restore_exe(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __VCARD_CLOUD_SUPPORT__
		if (g_sso_other_cxt_ptr->contacts_s)/*first restore contacts, second restore sms*/
	    {  
	        mmi_sso_backup_restore_contacts();
			return;
	    }
	#endif

	#ifdef __SMS_CLOUD_SUPPORT__
        if (g_sso_other_cxt_ptr->sms_s)
        {   
            mmi_sso_backup_restore_sms();
            return;
        }
	#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_backup_restore_optitem_select
 * DESCRIPTION
 *  deal with the selected menue item ot the backup restore scrn options
 * PARAMETERS
 *  evt    : [IN] cui_menu_event_struct*
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_backup_restore_optitem_select(cui_menu_event_struct* menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->highlighted_menu_id)
    {
    case MENU_ID_MMI_SSOAPP_MARK:
        {
        #if defined (__VCARD_CLOUD_SUPPORT__) && defined (__SMS_CLOUD_SUPPORT__)
            g_sso_other_cxt_ptr->current_list[g_sso_other_cxt_ptr->backup_restore_current_item] = MMI_SSO_RESTORE_SCR_SELECTED;
        #else
            #ifdef __VCARD_CLOUD_SUPPORT__
                 g_sso_other_cxt_ptr->current_list[g_sso_other_cxt_ptr->backup_restore_current_item] = MMI_SSO_RESTORE_SCR_SELECTED;
            #endif
            #ifdef __SMS_CLOUD_SUPPORT__
                 g_sso_other_cxt_ptr->current_list[g_sso_other_cxt_ptr->backup_restore_current_item + 1] = MMI_SSO_RESTORE_SCR_SELECTED;
            #endif
        #endif
            break;
        }
    case MENU_ID_MMI_SSOAPP_UNMARK:
        {
        #if defined (__VCARD_CLOUD_SUPPORT__) && defined (__SMS_CLOUD_SUPPORT__)
            g_sso_other_cxt_ptr->current_list[g_sso_other_cxt_ptr->backup_restore_current_item] = MMI_SSO_RESTORE_SCR_SELECTED_NO;
        #else
            #ifdef __VCARD_CLOUD_SUPPORT__
                 g_sso_other_cxt_ptr->current_list[g_sso_other_cxt_ptr->backup_restore_current_item] = MMI_SSO_RESTORE_SCR_SELECTED_NO;
            #endif
            #ifdef __SMS_CLOUD_SUPPORT__
                 g_sso_other_cxt_ptr->current_list[g_sso_other_cxt_ptr->backup_restore_current_item + 1] = MMI_SSO_RESTORE_SCR_SELECTED_NO;
            #endif
        #endif
            break;
        }
    case MENU_ID_MMI_SSOAPP_MARKALL:
        {
            g_sso_other_cxt_ptr->current_list[0] = MMI_SSO_RESTORE_SCR_SELECTED;
            g_sso_other_cxt_ptr->current_list[1] = MMI_SSO_RESTORE_SCR_SELECTED;
            break;
        }
    case MENU_ID_MMI_SSOAPP_UNMARKALL:
        {
            g_sso_other_cxt_ptr->current_list[0] = MMI_SSO_RESTORE_SCR_SELECTED_NO;
            g_sso_other_cxt_ptr->current_list[1] = MMI_SSO_RESTORE_SCR_SELECTED_NO;
            break;
        }
    /* account's options item restore---->after entry, the menu's option */
    case MENU_ID_MMI_SSOAPP_RESTORE:
    case MENU_ID_MMI_SSOAPP_BACKUP:
        {
			mmi_sso_backup_restore_set_value(g_sso_other_cxt_ptr->current_list);
    		if(mmi_sso_have_backup_data())
    		{
				mmi_sso_backup_restore_exe();
        		mmi_sso_backup_restore_bar_scr();
    		}
            return;
        }
    }
    mmi_sso_backup_restore_set_value(g_sso_other_cxt_ptr->current_list);
    cui_menu_close(menu_evt->sender_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_check_opt_entry
 * DESCRIPTION
 *  for hide some menue item for the check box, in the check box screen option
 * PARAMETERS
 *  menu_evt    [IN]    cui_menu_event_struct* 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_check_opt_entry(cui_menu_event_struct* menu_evt,U8* state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 temp = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if defined (__VCARD_CLOUD_SUPPORT__) && defined (__SMS_CLOUD_SUPPORT__)
        if (state[MMI_SSO_RESTORE_SCR_CONNECTS] && state[MMI_SSO_RESTORE_SCR_SMS])/* Contacts and sms all select, show: unmark, unmark all, restore*/
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MMI_SSOAPP_MARK, MMI_TRUE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MMI_SSOAPP_MARKALL, MMI_TRUE);
        }
        else if (state[MMI_SSO_RESTORE_SCR_CONNECTS] || state[MMI_SSO_RESTORE_SCR_SMS])
        {
            /* show : mark,unmark, mark all, unmark all, restore*/   
            if ((state[MMI_SSO_RESTORE_SCR_CONNECTS] == MMI_SSO_RESTORE_SCR_SELECTED_NO) && (g_sso_other_cxt_ptr->backup_restore_current_item == MMI_SSO_RESTORE_SCR_CONNECTS))
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MMI_SSOAPP_UNMARK, MMI_TRUE);
            }
            if ((state[MMI_SSO_RESTORE_SCR_CONNECTS] == MMI_SSO_RESTORE_SCR_SELECTED) && (g_sso_other_cxt_ptr->backup_restore_current_item == MMI_SSO_RESTORE_SCR_CONNECTS))
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MMI_SSOAPP_MARK, MMI_TRUE);
            }
            
            if((state[MMI_SSO_RESTORE_SCR_SMS] == MMI_SSO_RESTORE_SCR_SELECTED_NO) && (g_sso_other_cxt_ptr->backup_restore_current_item == MMI_SSO_RESTORE_SCR_SMS))
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MMI_SSOAPP_UNMARK, MMI_TRUE);
            }
            if((state[MMI_SSO_RESTORE_SCR_SMS] == MMI_SSO_RESTORE_SCR_SELECTED) && (g_sso_other_cxt_ptr->backup_restore_current_item == MMI_SSO_RESTORE_SCR_SMS))
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MMI_SSOAPP_MARK, MMI_TRUE);
            }
        }
        else /* no selected only, show:makr, mark all, restore*/
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MMI_SSOAPP_UNMARK, MMI_TRUE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MMI_SSOAPP_UNMARKALL, MMI_TRUE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MMI_SSOAPP_RESTORE, MMI_TRUE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MMI_SSOAPP_BACKUP, MMI_TRUE);
        }
    #else
		cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MMI_SSOAPP_MARKALL, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MMI_SSOAPP_UNMARKALL, MMI_TRUE);
		#ifdef __VCARD_CLOUD_SUPPORT__
			temp = state[MMI_SSO_RESTORE_SCR_CONNECTS];
		#endif
		#ifdef __SMS_CLOUD_SUPPORT__
			temp = state[MMI_SSO_RESTORE_SCR_SMS];
		#endif  
		if(temp == MMI_SSO_RESTORE_SCR_SELECTED_NO)
		{
			cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MMI_SSOAPP_UNMARK, MMI_TRUE);
		}
		else
		{
			cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MMI_SSOAPP_MARK, MMI_TRUE);
		}
	#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_backup_restore_scr_opt_entry
 * DESCRIPTION
 *  for hide some menue item for the check box
 * PARAMETERS
 *  menu_evt    [IN]    cui_menu_event_struct* 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_backup_restore_scr_opt_entry(cui_menu_event_struct* menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sso_check_opt_entry(menu_evt, g_sso_other_cxt_ptr->current_list);
	if(!g_sso_other_cxt_ptr->current_list[0] && !g_sso_other_cxt_ptr->current_list[1])
	{
		cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MMI_SSOAPP_RESTORE, MMI_TRUE);
		cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MMI_SSOAPP_BACKUP, MMI_TRUE);
		return;
	}	
	if (g_sso_other_cxt_ptr->op == MMI_SSO_BACKUP)
	{
		cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MMI_SSOAPP_RESTORE, MMI_TRUE);
	}
	else
	{
		cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MMI_SSOAPP_BACKUP, MMI_TRUE);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_backup_restore_gpro
 * DESCRIPTION
 * The pro for logout statuw  restore group 
 * PARAMETERS
 *  evt    : [IN] mmi_event_struct
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_sso_backup_restore_gpro(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct*)evt;
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_sso_backup_restore_optitem_select(menu_evt);
            break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id); /* close main menu or................. */
            break;
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            mmi_sso_backup_restore_scr_opt_entry(menu_evt);
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_backup_restore_bar_sproc
 * DESCRIPTION
 * pro the restore scrn
 * PARAMETERS
 *  evt    : [IN] mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_sso_backup_restore_bar_sproc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type itemlist[5];
    U16 stringId;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (evt->evt_id)
	{
        case EVT_ID_SCRN_ACTIVE:
        	{   
                if (g_sso_other_cxt_ptr->op == MMI_SSO_BACKUP)
                {
                    stringId = STR_ID_MMI_SSO_BACKUP_PRO_CONTACTS;
                }
                else
                {
                    stringId = STR_ID_MMI_SSO_RESTORE_PRO_CONTACTS;
                }
                
			 	if (!g_sso_other_cxt_ptr->contacts_s && g_sso_other_cxt_ptr->sms_s)
		 		{	 			
                    if (g_sso_other_cxt_ptr->op == MMI_SSO_BACKUP)
                    {
                        stringId = STR_ID_MMI_SSO_BACKUP_PRO_SMS;
                    }
                    else
                    {
                        stringId = STR_ID_MMI_SSO_RESTORE_PRO_SMS;
                    }
				}
                itemlist[0] = (UI_string_type)GetString(stringId);
                wgui_cat6003_show(
                    0,
                    STR_GLOBAL_CANCEL,
                    itemlist[0],
                    NULL,
                    g_sso_other_cxt_ptr->process);
                SetRightSoftkeyFunction(mmi_sso_backup_restore_abort, KEY_EVENT_UP);
        		break;
        	}
	}
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_backup_restore_bar_scr
 * DESCRIPTION
 *  restor contacts or sms, or contacts and sms scren
 * PARAMETERS
 *  evt    : [IN] cui_menu_event_struct*
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_backup_restore_bar_scr()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sso_other_cxt_ptr->process = 0;
    mmi_frm_scrn_create(
        GCR_ID_MMI_SSO_BACKUP_RESTORE_ENTRY, 
        SCR_ID_MMI_SSO_BACKUP_RESTORE_BAR, 
        mmi_sso_backup_restore_bar_sproc, 
        NULL); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_error_popup_close
 * DESCRIPTION
 *  the string is too long, so use the cate close
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_error_popup_close(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(GRP_ID_MMI_SSO_OUT, SCR_ID_MMI_SSO_BACKUP_RESTORE_ERROR_RESULT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_error_popup_sproc
 * DESCRIPTION
 * pro the  accounts scrn
 * PARAMETERS
 *  evt    : [IN] mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_sso_error_popup_sproc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (evt->evt_id)
	{
        case EVT_ID_SCRN_ACTIVE:
        	{   
                guiBuffer = mmi_frm_scrn_get_active_gui_buf();
                ShowCategory66Screen(
                    0,
                    0,
                    STR_GLOBAL_OK,
                    IMG_GLOBAL_OK,
                    0,
                    0,
                    (U8*)g_sso_other_cxt_ptr->string,
                    mmi_get_event_based_image(MMI_EVENT_FAILURE),
                    NULL);
                SetLeftSoftkeyFunction(mmi_sso_error_popup_close, KEY_EVENT_UP);
				srv_prof_play_tone(GENERAL_TONE, NULL);
        		break;
        	}
	}
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_backup_restore_error_popup
 * DESCRIPTION
 *  when error happen, popup 
 * PARAMETERS
 *  UI_string_type [IN] string
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_backup_restore_error_popup(UI_string_type string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_is_present(
		    GRP_ID_MMI_SSO_OUT, 
            SCR_ID_MMI_SSO_BACKUP_RESTORE_ERROR_RESULT,
            MMI_FRM_NODE_ALL_FLAG))
    {
         mmi_frm_scrn_close(
            GRP_ID_MMI_SSO_OUT,
            SCR_ID_MMI_SSO_BACKUP_RESTORE_ERROR_RESULT);
    }
    g_sso_other_cxt_ptr->string = string;
    mmi_frm_scrn_create(
        GRP_ID_MMI_SSO_OUT, 
        SCR_ID_MMI_SSO_BACKUP_RESTORE_ERROR_RESULT, 
        mmi_sso_error_popup_sproc, 
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_logout_cb
 * DESCRIPTION
 *  Log out result callback
 * PARAMETERS
 *  restult    : [IN]  srv_sso_result
 *  user_data  : [IN]  void * can be null
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_logout_cb(S32 req_id, srv_sso_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G7_SSO, MMI_SSO_LOGOUT_CB, result);
    if (mmi_frm_group_is_present(g_sso_other_cxt_ptr->sso_logoutpop_gid))
    {
        mmi_alert_dismiss(g_sso_other_cxt_ptr->sso_logoutpop_gid);
    }
    if (SRV_SSO_OK == result)
    {   
        mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_MMI_SSO_OUT, NULL);
        g_sso_cxt_ptr->is_login = MMI_FALSE; 
    }
    else /* SRV_SSO_ERROR */
    {
        mmi_popup_display_simple_ext(STR_GLOBAL_FAILED, MMI_EVENT_FAILURE, GRP_ID_MMI_SSO_OUT, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_logout_popup_cb
 * DESCRIPTION
 *  comfirm cb
 * PARAMETERS
 *  evt    : [IN]  mmi_event_struct *
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_sso_logout_popup_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *event = (mmi_alert_result_evt_struct *)evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (event->result == MMI_ALERT_CNFM_CANCEL)
    {
        MMI_TRACE(MMI_INET_TRC_G7_SSO, MMI_SSO_LOGOUT_POPUP_CB_CANCEL);/*nothing to do */
    }
    if (event->evt_id == EVT_ID_ALERT_QUIT)
    {
        if (event->result == MMI_POPUP_NORMAL_EXIT || event->result == MMI_POPUP_INTERRUPT_EXIT)
        {
            MMI_TRACE(MMI_INET_TRC_G7_SSO, MMI_SSO_LOGOUT_POPUP_CB_EXIT);/*nothing to do */
        }
    }
    return MMI_RET_OK;
}
#endif


#ifdef __MMI_SSO_OOBE__
/*****************************************************************************
 * FUNCTION
 *  mmi_sso_bootup
 * DESCRIPTION
 *  boot up, then omit a event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sso_bootup(void)
{
    /*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	mmi_event_struct event;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	MMI_FRM_INIT_EVENT(&event, EVT_ID_MMI_SSO_BOOTUP_READY_NOTIFY);
	MMI_FRM_CB_EMIT_EVENT(&event);			
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_bootup_oobe_show
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_bootup_oobe_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data = 0;
    S16 error = 0;	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_SSO__
    	if (srv_sso_get_provider_count())
    	{
    		g_ssocui_startup = MMI_TRUE;
    		data = 0;
    		WriteValue(NVRAM_SSOAPP_FIRST_POWER_ON, &data, DS_BYTE, &error);
    		WriteFlashNVRAMCatchData(DS_BYTE);
    		mmi_sso_main_pre();
    	}
    #endif	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_contacts_sms_bootup_ready_hdlr
 * DESCRIPTION
 *  by rececive sms and contacts, bootup to pop ssocui
 * PARAMETERS
 *  event           : [IN]          event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
extern mmi_ret mmi_sso_contacts_sms_bootup_ready_hdlr(mmi_event_struct *event)
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event);
    ReadValue(NVRAM_SSOAPP_FIRST_POWER_ON, &data, DS_BYTE, &error);
    if (data)/*default is true, true is represent first power on */
    {
        switch (event->evt_id)
        {
        case EVT_ID_SRV_SMS_READY:
            {
                if (srv_phb_startup_is_phb_ready() && !g_ssocui_startup && g_sso_bootup_ready)
                {
					mmi_sso_bootup_oobe_show();
                }
                break;
            } 
        case EVT_ID_PHB_READY:
            {
                if (srv_sms_is_sms_ready() && !g_ssocui_startup && g_sso_bootup_ready)
                {
					mmi_sso_bootup_oobe_show();
                }
                break;
            }
		case EVT_ID_MMI_SSO_BOOTUP_READY_NOTIFY:
			{
				g_sso_bootup_ready = MMI_TRUE;
				if (srv_sms_is_sms_ready() && !g_ssocui_startup && srv_phb_startup_is_phb_ready())
                {
					mmi_sso_bootup_oobe_show();
                }
				break;
			}
        }
    }
    return MMI_RET_OK;
}
#endif /* __MMI_SSO_OOBE__ */


#ifdef __SOCIAL_NETWORK_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sso_sns_pluging_upgrade_proc
 * DESCRIPTION
 * sns plug in upgrade
 * PARAMETERS
 *  evt    : [IN] mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
extern mmi_ret mmi_sso_sns_pluging_upgrade_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sns_evt_plugins_upgraded_struct *upgrade = (srv_sns_evt_plugins_upgraded_struct *)evt;
    MMI_TRACE(MMI_INET_TRC_G7_SSO, MMI_SSO_SNS_UPGRADE, upgrade->is_successful);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (upgrade->is_successful)
    {
        mmi_popup_display_ext(STR_ID_SSO_SNS_UPGRADE_SUCCESS, MMI_EVENT_SUCCESS, NULL);
    }
    else
    {
        mmi_popup_display_ext(STR_ID_SSO_SNS_UPGRADE_FAILURE, MMI_EVENT_FAILURE, NULL);
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_sns_logout_cb
 * DESCRIPTION
 *  Log out result callback
 * PARAMETERS
 *  restult    : [IN]  srv_sso_result
 *  user_data  : [IN]  void * can be null
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_sso_sns_logout_cb(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sns_evt_result_struct *result = (srv_sns_evt_result_struct *)param;
    MMI_STR_ID string_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_alert_dismiss(g_sso_other_cxt_ptr->sso_logoutpop_gid );
    if (result->result != SRV_SNS_OK)
    {
        string_id = srv_sns_get_error_string(result->result);
        mmi_popup_display_ext(string_id, MMI_EVENT_FAILURE, NULL); 
    }
    else
    {
        mmi_popup_display_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, NULL);
        srv_sns_release_list(g_sso_sns_cxt.list_id, MMI_TRUE);
        g_sso_sns_cxt.list_id = srv_sns_get_accounts(SRV_SNS_LOGIN_DONT_CARE, SRV_SNS_FEATURE_ANY, 0x00, &(g_sso_sns_cxt.total));
    }
    MMI_TRACE(MMI_INET_TRC_G7_SSO, MMI_SSO_SNS_LOGOUT_CB, result->result);
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_sns_logout_popup_cb
 * DESCRIPTION
 *  Log out popup cb
 * PARAMETERS
 *  restult    : [IN]  srv_sso_result
 *  user_data  : [IN]  void * can be null
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_sso_sns_logout_popup_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *event = (mmi_alert_result_evt_struct *)evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (event->result == MMI_ALERT_CNFM_CANCEL)
    {
        S32 req_id = *(S32 *)event->user_tag;
        srv_sns_cancel(req_id);
        MMI_TRACE(MMI_INET_TRC_G7_SSO, MMI_SSO_SNS_LOGOUT_POPUP_CB_CANCEL);
    }

    if (event->evt_id == EVT_ID_ALERT_QUIT)
    {
        if (event->result == MMI_POPUP_NORMAL_EXIT || event->result == MMI_POPUP_INTERRUPT_EXIT)
        {
            OslMfree(event->user_tag);
            MMI_TRACE(MMI_INET_TRC_G7_SSO, MMI_SSO_SNS_LOGOUT_POPUP_CB_EXIT);
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_sns_not_ready_proc
 * DESCRIPTION
 *  sns ready event 
 * PARAMETERS
 *  mmi_event_struct *evt [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_sso_sns_not_ready_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sns_evt_ready_struct *ready = (srv_sns_evt_ready_struct *)evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G7_SSO, MMI_SSO_SNS_READY, ready->is_ready);
    if (!ready->is_ready)
    {
        if (mmi_frm_group_is_present(GRP_ID_MMI_SSO))
        {
            mmi_frm_group_close(GRP_ID_MMI_SSO);
        }  
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_main
 * DESCRIPTION
 *  enter yahoo service menu to deal with something
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sso_main_launch_sns(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!srv_sns_is_ready())
    {
        return;
    }
    memset(&g_sso_sns_cxt, 0, sizeof(mmi_sso_sns_infor_struct));
    g_sso_sns_cxt.list_id = srv_sns_get_accounts(SRV_SNS_LOGIN_DONT_CARE, SRV_SNS_FEATURE_ANY, 0x00, &(g_sso_sns_cxt.total));
    if(g_sso_sns_cxt.total == 0)
    {
        g_sso_sns_cxt.paccounts = NULL;
		kal_prompt_trace(MOD_MMI_COMMON_APP,"mmi_sso_main_launch_sns totaol = %d", g_sso_sns_cxt.total);
		return;
    }
    mmi_frm_cb_reg_event(EVT_ID_SRV_SNS_READY, mmi_sso_sns_not_ready_proc, NULL);
    g_sso_sns_cxt.sso_sns_launch = MMI_TRUE;
	mmi_sso_malloc();
    MMI_TRACE(MMI_INET_TRC_G7_SSO, MMI_SSO_MAIN_LAUNCH_SNS, g_sso_sns_cxt.list_id, g_sso_sns_cxt.paccounts, g_sso_sns_cxt.total);
    mmi_frm_group_create_ex(
        GRP_ID_ROOT, GRP_ID_MMI_SSO, 
        mmi_sso_accounts_gproc, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_create(
        GRP_ID_MMI_SSO, 
        SCR_ID_MMI_SSO_ACCOUNTS, 
        mmi_sso_accounts_sproc, 
        NULL);
}
#endif /*#ifdef __SOCIAL_NETWORK_SUPPORT__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_nss_bd_comfirm_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_sso_result_comfirm_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*)evt;
            switch (alert->result)
            {
                case MMI_ALERT_NORMAL_EXIT:
                {
                    mmi_frm_group_close(alert->alert_id);
                    break;
                }
                case MMI_ALERT_CNFM_OK:
                {
					/*if contact error is -9 cookie expire*/
					if (g_sso_other_cxt_ptr->contacts_result == SRV_PHB_CLOUD_LOGOUT || g_sso_other_cxt_ptr->sms_result == SRV_SMS_CAUSE_CLOUD_LOGOUT) 
					{
						mmi_sso_login_opt_login();
					}
                    mmi_frm_group_close(alert->alert_id);
                    break;
                }
            }
			break;
        }     
    }
	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sso_logout_opt_logout
 * DESCRIPTION
 *  The current log in account to log out
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_logout_opt_logout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    S32 *popup_ud;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_confirm_property_init(&arg, CNFM_TYPE_CANCEL);
    arg.parent_id = GRP_ID_MMI_SSO_OUT;
    arg.f_enter_history = 1;
    if (g_sso_cxt_ptr->current_index < g_sso_sns_cxt.total) /* sso log in sns*/
    { 
    #ifdef __SOCIAL_NETWORK_SUPPORT__
        popup_ud = (S32 *)OslMalloc(sizeof(S32 *));
        arg.user_tag = popup_ud;
        arg.callback = mmi_sso_sns_logout_popup_cb;
        g_sso_other_cxt_ptr->sso_logoutpop_gid = mmi_confirm_display_ext(STR_ID_MMI_SSO_LOGGING_OUT, MMI_EVENT_PROGRESS, &arg);
        *popup_ud = srv_sns_logout(g_sso_sns_cxt.paccounts[g_sso_sns_cxt.current_index].provider, mmi_sso_sns_logout_cb, NULL);
        if (*popup_ud < 0)
        {
            mmi_alert_dismiss(g_sso_other_cxt_ptr->sso_logoutpop_gid);
            OslMfree(popup_ud);
        }
    #endif    
    }
    else
    {
    #ifdef __MMI_SSO__
        arg.callback = mmi_sso_logout_popup_cb;
        g_sso_other_cxt_ptr->sso_logoutpop_gid = mmi_confirm_display_ext(STR_ID_MMI_SSO_LOGGING_OUT, MMI_EVENT_PROGRESS, &arg);
        srv_sso_logout_account(g_sso_cxt_ptr->provider, g_sso_cxt_ptr->account_id, mmi_sso_logout_cb, NULL);
	#endif
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_accounts_gproc
 * DESCRIPTION
 * The pro for yahoo service log out
 * PARAMETERS
 *  evt    : [IN] mmi_event_struct
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_sso_accounts_gproc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct*)evt;
    switch (evt->evt_id)
    {
	    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
	        {
	            cui_menu_close(menu_evt->sender_id);
	            break;
	        }    
	    case EVT_ID_GROUP_DEINIT:
	        {
				#ifndef __MMI_SUPPORT_ASMV2__
				g_ssocui_startup = MMI_FALSE;
				#endif
				mmi_sso_free();
	            break;
	        }    
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_logout_gproc
 * DESCRIPTION
 * The pro for yahoo service log out, because the account have loged in
 * PARAMETERS
 *  evt    : [IN] mmi_event_struct
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_sso_logout_gproc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct*)evt;
    switch (evt->evt_id)
    {
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            #if (!defined (__VCARD_CLOUD_SUPPORT__) && !defined (__SMS_CLOUD_SUPPORT__))
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MMI_SSOAPP_RESTORE, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MMI_SSOAPP_BACKUP, MMI_TRUE);
            #endif	
            #if (!defined (__SOCIAL_NETWORK_SUPPORT__))
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MMI_SSOAPP_SNS_SETTING, MMI_TRUE);
            #endif
            /*1 if current is sns accout, the MENU_ID_MMI_SSOAPP_RESTORE and MENU_ID_MMI_SSOAPP_BACKUP should be hidden*/
            /*1.1 if current is sns account have not loged in, MENU_ID_MMI_SSOAPP_APPS_SYNC shoud be hidden*/
            if (g_sso_cxt_ptr->current_index < g_sso_sns_cxt.total)
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MMI_SSOAPP_RESTORE, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MMI_SSOAPP_BACKUP, MMI_TRUE);
            }
            else/*1 if current is colud account, the MENU_ID_MMI_SSOAPP_APPS_SYNC should be hidden*/
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MMI_SSOAPP_APPS_SYNC, MMI_TRUE);
            }
			break;
        }	
    case EVT_ID_CUI_MENU_ITEM_SELECT:/* account category's options*/
        {
            if (MENU_ID_MMI_SSOAPP_LOGOUT == menu_evt->highlighted_menu_id)
            {
                mmi_sso_logout_opt_logout();
            }
        #ifdef __MMI_SSO__
            else if (MENU_ID_MMI_SSOAPP_RESTORE == menu_evt->highlighted_menu_id)
            {
                mmi_sso_backup_restore_entry(MMI_SSO_RESTORE); 
            }
            else if (MENU_ID_MMI_SSOAPP_BACKUP == menu_evt->highlighted_menu_id)
            {
                mmi_sso_backup_restore_entry(MMI_SSO_BACKUP);           
            }
        #endif
		#ifdef __SOCIAL_NETWORK_SUPPORT__
            else if (MENU_ID_MMI_SSOAPP_APPS_SYNC == menu_evt->highlighted_menu_id)/*loged in sns account's Apps.to sync*/ 
            {
                srv_sns_account_struct *account;
                MMI_ID gid;
                srv_sns_release_list(g_sso_sns_cxt.list_id, MMI_TRUE);
                g_sso_sns_cxt.list_id = srv_sns_get_accounts(
					SRV_SNS_LOGIN_DONT_CARE, 
					SRV_SNS_FEATURE_ANY, 0x00, 
					&(g_sso_sns_cxt.total));
                if(g_sso_sns_cxt.total == 0)
                {
                    g_sso_sns_cxt.paccounts = NULL;
		            kal_prompt_trace(MOD_MMI_COMMON_APP,"mmi_sso_main_launch_sns totaol = %d", g_sso_sns_cxt.total);
		            return MMI_RET_OK;
                }
                else
                {
                    if (g_sso_sns_cxt.paccounts)
                    {
                        OslMfree(g_sso_sns_cxt.paccounts);
                        g_sso_sns_cxt.paccounts = NULL;
                    } 
                    g_sso_sns_cxt.paccounts = OslMalloc(sizeof(mmi_sso_sns_account_infor_struct) * g_sso_sns_cxt.total);
                }
                srv_sns_get_item2(g_sso_sns_cxt.list_id, g_sso_sns_cxt.current_index, (void **)&account);
                gid = cui_sns_sync_create(GRP_ID_MMI_SSO_OUT, account);
                cui_sns_sync_run(gid);   
            }
            else if (MENU_ID_MMI_SSOAPP_SYNC== menu_evt->highlighted_menu_id)
            {
                mmi_sns_misc_config_duration(GRP_ID_MMI_SSO_OUT, MMI_SNS_CONF_SYNC_INTERVAL);/*in or out sns account's Sync interval*/
            }
            else if (MENU_ID_MMI_SSOAPP_NEWS== menu_evt->highlighted_menu_id)
            {
                mmi_sns_misc_config_duration(GRP_ID_MMI_SSO_OUT, MMI_SNS_CONF_NEWS_REMINDER); /*in or out sns account's New reminder*/
            }
        #endif
            break;
        }	
    #ifdef __SOCIAL_NETWORK_SUPPORT__
    case EVT_ID_CUI_SNS_SYNC_CLOSE_REQ:
        {
            mmi_group_event_struct *result_evt = (mmi_group_event_struct*)evt;
            cui_sns_sync_close(result_evt->sender_id);
            break;
        }
    #endif 	
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(menu_evt->sender_id);
            break;
        }  
	
    }  
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_out_opt
 * DESCRIPTION
 *  yahoo service accounts log out options
 * PARAMETERS
 * void 
 * RETURNS
 * void
 *****************************************************************************/
static void mmi_sso_logout_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create_ex(
        GRP_ID_MMI_SSO, GRP_ID_MMI_SSO_OUT, 
        mmi_sso_logout_gproc, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    cui_menu_create_and_run(
            GRP_ID_MMI_SSO_OUT,
            CUI_MENU_SRC_TYPE_RESOURCE,
            CUI_MENU_TYPE_OPTION,
            MENU_ID_MMI_SSO_ACCONUTS_OUT_OPTIONS,
            MMI_FALSE, /* Use global resource */
            NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_accounts_get_item_infor
 * DESCRIPTION
 * 
 * PARAMETERS
 *  i [IN] S32 the current index
 * RETURN VALUES
 * void
 *****************************************************************************/
static void mmi_sso_accounts_get_item_infor(S32 i)
{

	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sso_provider_struct provider_struct[SRV_SSO_PROVIDER_MAX];
    srv_sso_account_struct account_struct;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_SSO__
		srv_sso_get_providers(provider_struct, srv_sso_get_provider_count());
		srv_sso_get_provider_name(provider_struct[i].provider, g_sso_cxt_ptr->provider_name);
		srv_sso_get_accounts(provider_struct[i].provider, SRV_SSO_LOGIN_DONT_CARE, &account_struct, SRV_SSO_ACCOUNTS_PER_PROVIDER);
		g_sso_cxt_ptr->account_id = account_struct.account;
		g_sso_cxt_ptr->provider = provider_struct[i].provider;
		mmi_ucs2cpy((kal_int8 *)g_sso_cxt_ptr->account_icon_buffer, 
		(kal_int8 *)srv_sso_get_provider_icon(g_sso_cxt_ptr->provider, SRV_SSO_ICON_LARGE));
        memset(g_sso_cxt_ptr->account_name_buffer, 0, sizeof(g_sso_cxt_ptr->account_name_buffer));
		srv_sso_get_account_name(g_sso_cxt_ptr->provider, g_sso_cxt_ptr->account_id, g_sso_cxt_ptr->account_name_buffer);
		if (srv_sso_get_accounts(provider_struct[i].provider, SRV_SSO_LOGIN_TRUE, &account_struct, SRV_SSO_ACCOUNTS_PER_PROVIDER))
		{
			g_sso_cxt_ptr->is_login = MMI_TRUE;
		}
		else
		{
			g_sso_cxt_ptr->is_login = MMI_FALSE;
		}
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_accounts_get_item
 * DESCRIPTION
 * fill the items of the drafts menu
 * PARAMETERS
 *  start_index    : [IN] S32 Start index of menu item
 *  menu_data      : [OUT] menu_data A pointer of parameter to store the menu data
 *  data_size      : [IN] S32 The number of load menu items
 * RETURN VALUES
 *  Number of items can be retrieved
 *****************************************************************************/
static S32 mmi_sso_accounts_get_item(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    srv_sns_account_struct *account;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < data_size; i++)
    {
        if (start_index + i < g_sso_sns_cxt.total)/* at range of sns */
        {
        	#ifdef __SOCIAL_NETWORK_SUPPORT__
				srv_sns_get_item2(g_sso_sns_cxt.list_id, start_index + i, (void **)&account);  /* account */
				mmi_ucs2cpy((kal_int8 *)menu_data[i].item_list[0], (kal_int8 *)account->name); /* log in ****@163.com*/
				g_sso_sns_cxt.paccounts[i].index = i;
				g_sso_sns_cxt.paccounts[i].provider = account->provider;
				if (account->user.user_id)
				{
					mmi_ucs2cpy((kal_int8 *)menu_data[i].item_list[1], (kal_int8 *)account->login_id);
					g_sso_sns_cxt.paccounts[i].logstatus = MMI_TRUE;
				}
				else
				{
					mmi_ucs2cpy((kal_int8 *)menu_data[i].item_list[1], (kal_int8 *)account->login_id);
					g_sso_sns_cxt.paccounts[i].logstatus = MMI_FALSE;
				}
			#endif
        }
        else /* at range of cloud */
        {
        	#ifdef __MMI_SSO__
				mmi_sso_accounts_get_item_infor(start_index + i - g_sso_sns_cxt.total);
				mmi_ucs2cpy((kal_int8 *)menu_data[i].item_list[0], (kal_int8 *)g_sso_cxt_ptr->provider_name);
				mmi_ucs2cpy((kal_int8 *)menu_data[i].item_list[1], (kal_int8 *)g_sso_cxt_ptr->account_name_buffer);
			#endif
		}
    }
    return data_size;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_accounts_get_image_info
 * DESCRIPTION
 * icon for item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_accounts_get_image_info(S32 item_idx, wgui_thumbnail_info_struct *info_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    info_data->file_icon_ptr = get_image(IMG_SSO);
    info_data->is_show_thumb = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_accounts_get_image_path
 * DESCRIPTION
 * icon path for item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_sso_accounts_get_image_path(S32 item_idx, CHAR *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = item_idx;
    srv_sns_account_struct *account;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if(item_idx < g_sso_sns_cxt.total)
    {
    	#ifdef __SOCIAL_NETWORK_SUPPORT__
			srv_sns_get_item2(g_sso_sns_cxt.list_id, item_idx, (void **)&account);
			g_sso_sns_cxt.paccounts[i].index = i;
			g_sso_sns_cxt.paccounts[i].provider = account->provider;
			if (account->user.user_id)
			{
				g_sso_sns_cxt.paccounts[i].logstatus = MMI_TRUE;
			}
			else
			{
				g_sso_sns_cxt.paccounts[i].logstatus = MMI_FALSE;
			}
			mmi_ucs2cpy((kal_int8 *)file_path, (kal_int8 *)srv_sns_get_provider_icon(account->provider, SRV_SNS_LOGO_LARGE));
        #endif
    }
    else
    {
        #ifdef __MMI_SSO__
			mmi_sso_accounts_get_item_infor(item_idx - g_sso_sns_cxt.total);      
			mmi_ucs2cpy((kal_int8 *)file_path, (kal_int8 *)g_sso_cxt_ptr->account_icon_buffer);
		#endif
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_login_opt_login
 * DESCRIPTION
 * create ssocui for log in
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_login_opt_login(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sns_account_struct *account;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_group_is_present(GRP_ID_MMI_SSO_IN))
    {
        mmi_frm_group_create_ex(
            GRP_ID_MMI_SSO, GRP_ID_MMI_SSO_IN, 
            mmi_sso_login_gproc, 
            NULL, 
            MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }  
    if (g_sso_cxt_ptr->current_index < g_sso_sns_cxt.total) /* sso log in sns*/
    {
		#ifdef __SOCIAL_NETWORK_SUPPORT__
			srv_sns_get_item2(g_sso_sns_cxt.list_id, g_sso_sns_cxt.current_index, (void **)&account);
			cui_sso_login_create_run_sns(GRP_ID_MMI_SSO_IN, account);
		#endif    
    }
    else /* sso log in cloud*/
    {
		#ifdef __MMI_SSO__
			mmi_id sso_cui_gid;
			sso_cui_gid = cui_sso_login_create(GRP_ID_MMI_SSO_IN, g_sso_cxt_ptr->provider, g_sso_cxt_ptr->account_id);
			cui_sso_login_run(sso_cui_gid); 
		#endif
    }
}


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_sso_accounts_tap_cb(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G7_SSO, MMI_SSO_ACCOUNTS_TAB_CB, tap_type, index, g_sso_sns_cxt.total);
    g_sso_cxt_ptr->current_index = index;
    if (index < g_sso_sns_cxt.total)
    {
        g_sso_sns_cxt.current_index = index;
    }
    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        if (g_sso_cxt_ptr->current_index < g_sso_sns_cxt.total) /* if hilight the sns accounts */
        {
            mmi_sso_accounts_sns_entry();
        }
		#ifdef __MMI_SSO__
        else if ((g_sso_sns_cxt.total == 0) && (srv_sso_get_provider_count() == 0))/* cloud and sns not plug in*/
        {
            return;
        }
		#endif
        else /* if hilight the cloud accounts */
        {
            mmi_sso_accounts_entry();
        }
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_accounts_opt
 * DESCRIPTION
 *  yahoo service accounts options
 * PARAMETERS
 * void 
 * RETURNS
 * void
 *****************************************************************************/
static void mmi_sso_accounts_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_sso_cxt_ptr->current_index < g_sso_sns_cxt.total) /* if hilight the sns accounts */
    {
        if (g_sso_sns_cxt.paccounts[g_sso_sns_cxt.current_index].logstatus == KAL_TRUE)
        {
            mmi_sso_logout_opt();
        }
        else
        {
            mmi_sso_login_opt();
        }
    }
    else /* if hilight the cloud accounts */
    {
        if (g_sso_cxt_ptr->is_login == KAL_TRUE)
        {
            mmi_sso_logout_opt();
        }
        else
        {
            mmi_sso_login_opt();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_accounts_entry
 * DESCRIPTION
 * backup 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_accounts_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G7_SSO, MMI_SSO_ACCOUNTS_ENTRY, g_sso_cxt_ptr->is_login);
    if (g_sso_cxt_ptr->is_login == KAL_TRUE)
    {
        #ifdef __MMI_SSO__
            mmi_sso_backup_restore_entry(MMI_SSO_BACKUP); 
        #endif
    }
    else
    {
        mmi_sso_login_opt_login();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_accounts_sns_entry
 * DESCRIPTION
 * backup 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_accounts_sns_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G7_SSO, MMI_SSO_ACCOUNTS_SNS_ENTRY, g_sso_cxt_ptr->current_index, g_sso_sns_cxt.paccounts[g_sso_sns_cxt.current_index].logstatus);
    if (g_sso_sns_cxt.paccounts[g_sso_sns_cxt.current_index].logstatus)
    {
        mmi_sso_accounts_opt();/* sns account setting*/
    }
    else
    {
        mmi_sso_login_opt_login();/* sns account need log in*/
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_accounts_csk
 * DESCRIPTION
 * backup 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_accounts_csk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G7_SSO, MMI_SSO_ACCOUNTS_CSK, g_sso_cxt_ptr->current_index, g_sso_sns_cxt.total);
    if (g_sso_cxt_ptr->current_index < g_sso_sns_cxt.total) /* if hilight the sns accounts */
    {
        mmi_sso_accounts_sns_entry();
    }
	#ifdef __MMI_SSO__
    else if ((g_sso_sns_cxt.total == 0) && (srv_sso_get_provider_count() == 0))/* cloud and sns not plug in*/
    {
        return;
    }
	#endif
    else /* if hilight the cloud accounts */
    {
        mmi_sso_accounts_entry();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_accounts_sproc
 * DESCRIPTION
 * pro the  accounts scrn
 * PARAMETERS
 *  evt    : [IN] mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_sso_accounts_sproc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer;
    U16 total = 0;
	#ifdef __MMI_SSO__
	total = srv_sso_get_provider_count();
	#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (evt->evt_id)
	{
        case EVT_ID_SCRN_ACTIVE:
        	{   
                gui_buffer = mmi_frm_scrn_get_active_gui_buf();
                wgui_thumbnail_register_get_image_info_func(mmi_sso_accounts_get_image_info);
                wgui_thumbnail_register_get_image_path_func(mmi_sso_accounts_get_image_path);
                wgui_cat1071_show(
                        (PU8)GetString(STR_ID_MMI_SSO_ACCOUNTS_SETTING),
                        NULL,
                        (total + g_sso_sns_cxt.total ? STR_GLOBAL_OPTIONS : NULL),
                        STR_GLOBAL_BACK,
                        g_sso_sns_cxt.sso_sns_launch ? (g_sso_sns_cxt.total) : (total + g_sso_sns_cxt.total),
                        mmi_sso_accounts_get_item,
                        0,
                        IMG_SSO,
                        gui_buffer);
                EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
                SetLeftSoftkeyFunction(mmi_sso_accounts_opt, KEY_EVENT_UP);
                SetCenterSoftkeyFunction(mmi_sso_accounts_csk, KEY_EVENT_UP);
                SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
                #ifdef __MMI_TOUCH_SCREEN__
                    wgui_register_list_item_selected_callback_all(mmi_sso_accounts_csk);
                #endif
                #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
                    wgui_register_tap_callback(mmi_sso_accounts_tap_cb);
                #endif
        		break;
        	}
        
		case EVT_ID_SCRN_HIGHLIGHT_CHANGE:
			{   
                cat_evt_struct *event = (cat_evt_struct *)evt;
                g_sso_cxt_ptr->current_index = event->item_index;
                #ifdef __SOCIAL_NETWORK_SUPPORT__
                    if (event->item_index < g_sso_sns_cxt.total)/*deal with sns accounts */
                    {
                        g_sso_sns_cxt.current_index = event->item_index;
                    }
                    else/*deal with cloud service */
                    {
                        #ifdef __MMI_SSO__
                        mmi_sso_accounts_get_item_infor(event->item_index - g_sso_sns_cxt.total);
                        #endif
                    }
                    break;
                #endif
                #ifdef __MMI_SSO__
                    mmi_sso_accounts_get_item_infor(event->item_index);
                #endif
				break;
			}
	}
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_login_gproc
 * DESCRIPTION
 * The pro for account  log in group proc
 * PARAMETERS
 *  evt    : [IN] mmi_event_struct
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_sso_login_gproc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct*)evt;
    switch (evt->evt_id)
    {
	    case EVT_ID_CUI_MENU_LIST_ENTRY:
	        {
	            #if (!defined (__SOCIAL_NETWORK_SUPPORT__))
	            {
	                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MMI_SSOAPP_SNS_SETTING, MMI_TRUE);
	            }
	            #endif
	            break;
	        }
	    case EVT_ID_CUI_MENU_ITEM_SELECT:
	        {   
	            if (MENU_ID_MMI_SSOAPP_LOGIN == menu_evt->highlighted_menu_id)/*account category's options*/
	            {
	                mmi_sso_login_opt_login();   
	            }
	            #ifdef __SOCIAL_NETWORK_SUPPORT__
	            else if (MENU_ID_MMI_SSOAPP_SYNC== menu_evt->highlighted_menu_id)
	            {
	                /*add deal with the have loged in or loged out sns account's Sync interval but for cat*/
	                mmi_sns_misc_config_duration(GRP_ID_MMI_SSO_IN, MMI_SNS_CONF_SYNC_INTERVAL);
	            }
	            else if (MENU_ID_MMI_SSOAPP_NEWS== menu_evt->highlighted_menu_id)
	            {
	                /*add deal with the have loged in or loged out sns account's New reminder but for category*/
	                mmi_sns_misc_config_duration(GRP_ID_MMI_SSO_IN, MMI_SNS_CONF_NEWS_REMINDER);
	            }
	            #endif
	            break;
	        }
	    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
	         cui_menu_close(menu_evt->sender_id);
	         break;
	    #ifdef __MMI_SSO__
	    case EVT_ID_CUI_SSO_LOGIN_DONE:
	        {
	            cui_sso_login_done_event_struct *login_evt = (cui_sso_login_done_event_struct*)evt;          
	            if (login_evt->result == EVT_ID_CUI_SSO_LOGIN_OK)
	            {
	                g_sso_cxt_ptr->is_login = MMI_TRUE;
					g_sso_cxt_ptr->provider = login_evt->provider;
					g_sso_cxt_ptr->account_id = login_evt->account_id;
	                if (g_ssocui_startup)
	                {     
	                    #if (!defined (__VCARD_CLOUD_SUPPORT__) && !defined (__SMS_CLOUD_SUPPORT__))
	                        cui_sso_login_close(login_evt->sender_id);
	                        break;
	                    #endif
                    	mmi_sso_accounts_get_item_infor(0);
	                    mmi_sso_backup_restore_entry(MMI_SSO_RESTORE);
	                }
                    cui_sso_login_close(login_evt->sender_id);
	            }
	            else if (login_evt->result == EVT_ID_CUI_SS0_LOGIN_ABORT)/*if need reserve, EVT_ID_CUI_SSO_LOGIN_FAILED may be happen*/
	            {
	                cui_sso_login_close(login_evt->sender_id);
	            }
				break;
	        }
		#endif
	    #ifdef __SOCIAL_NETWORK_SUPPORT__
	    case EVT_ID_CUI_SSO_LOGIN_DONE_SNS:
	        {
	            cui_sso_login_done_sns_event_struct *login_evt = (cui_sso_login_done_sns_event_struct*)evt;
	            MMI_ID gid;
	            S32 i;
	            srv_sns_account_struct *account;
	            U32 provider;

	            provider = login_evt->account->provider;
	            if (login_evt->result == EVT_ID_CUI_SSO_LOGIN_OK)
	            {
	                if (g_sso_sns_cxt.list_id)/*add deal with the have loged in sns account's Apps. to sync*/ 
	                {
	                    srv_sns_release_list(g_sso_sns_cxt.list_id, MMI_TRUE);
	                }
	                g_sso_sns_cxt.list_id = srv_sns_get_accounts(SRV_SNS_LOGIN_DONT_CARE, SRV_SNS_FEATURE_ANY, 0x00, &(g_sso_sns_cxt.total));
	                for (i = 0; i < g_sso_sns_cxt.total; i++)
	                {
	                    srv_sns_get_item2(g_sso_sns_cxt.list_id, i, (void **)&account);
	                    if (provider == account->provider)
	                    {
	                        gid = cui_sns_sync_create(GRP_ID_MMI_SSO_IN, account);
	                        cui_sns_sync_run(gid);
	                        cui_sso_login_sns_close(login_evt->sender_id);
	                        break;
	                    }
	                }
	            }
	            else if (login_evt->result == EVT_ID_CUI_SS0_LOGIN_ABORT)/*if need reserve, EVT_ID_CUI_SSO_LOGIN_FAILED may be happen*/
	            {
	                cui_sso_login_sns_close(login_evt->sender_id);
	            }
				break;
	        }    
	    case EVT_ID_CUI_SNS_SYNC_CLOSE_REQ:
	        {
	            mmi_group_event_struct *result_evt = (mmi_group_event_struct*)evt;
	            cui_sns_sync_close(result_evt->sender_id);
	            break;
	        }
	    #endif /*#ifdef __SOCIAL_NETWORK_SUPPORT__*/       
    }    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_login_opt
 * DESCRIPTION
 *  the account should at login state, use this
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_login_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G7_SSO, MMI_SSO_LOGIN_OPT);
    mmi_frm_group_create_ex(
        GRP_ID_MMI_SSO, GRP_ID_MMI_SSO_IN, 
        mmi_sso_login_gproc, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    cui_menu_create_and_run(
        GRP_ID_MMI_SSO_IN,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_OPTION,
        MENU_ID_MMI_SSOAPP_ACCONUT_IN_OPTIONS,
        MMI_FALSE, /* Use global resource */
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_malloc
 * DESCRIPTION
 *  memory malloc
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_malloc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (g_sso_cxt_ptr == NULL)
	{
		g_sso_cxt_ptr = OslMalloc(sizeof(mmi_sso_accounts_infor_struct));
		if(g_sso_cxt_ptr){memset(g_sso_cxt_ptr, 0, sizeof(mmi_sso_accounts_infor_struct));}
	}
	if (g_sso_other_cxt_ptr == NULL)
	{
		g_sso_other_cxt_ptr = OslMalloc(sizeof(mmi_sso_other_infor_struct));
		if(g_sso_other_cxt_ptr){memset(g_sso_other_cxt_ptr, 0, sizeof(mmi_sso_other_infor_struct));}
	}
	#ifdef __SOCIAL_NETWORK_SUPPORT__	 
		g_sso_sns_cxt.list_id = srv_sns_get_accounts(SRV_SNS_LOGIN_DONT_CARE, SRV_SNS_FEATURE_ANY, 0x00, &(g_sso_sns_cxt.total));
        if(g_sso_sns_cxt.total)
        {
			if (g_sso_sns_cxt.paccounts)
			{
		 		OslMfree(g_sso_sns_cxt.paccounts);
		 		g_sso_sns_cxt.paccounts = NULL;
			}
        	g_sso_sns_cxt.paccounts = OslMalloc(sizeof(mmi_sso_sns_account_infor_struct) * g_sso_sns_cxt.total);
        }
	#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_malloc
 * DESCRIPTION
 *  memory free
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_free(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __VCARD_CLOUD_SUPPORT__
    	mmi_sso_contacts_abort();
    #endif
     
    #ifdef __SMS_CLOUD_SUPPORT__
    	mmi_sso_sms_abort();
    #endif
    if (g_sso_cxt_ptr)
    {
    	OslMfree(g_sso_cxt_ptr);
    	g_sso_cxt_ptr= NULL;
    }
    if (g_sso_other_cxt_ptr)
    {
    	OslMfree(g_sso_other_cxt_ptr);
    	g_sso_other_cxt_ptr= NULL;
    }
    #ifdef __SOCIAL_NETWORK_SUPPORT__
    	if(g_sso_sns_cxt.list_id)
    	{
    		srv_sns_release_list(g_sso_sns_cxt.list_id, MMI_TRUE);
    	}
    	if (g_sso_sns_cxt.paccounts)
    	{
    	 	OslMfree(g_sso_sns_cxt.paccounts);
    	 	g_sso_sns_cxt.paccounts = NULL;
    	}
    #endif 
}


 /*****************************************************************************
 * FUNCTION
 *  mmi_sso_login_bootup
 * DESCRIPTION
 * create ssocui for log in bootup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_login_bootup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sso_cui_gid;
    srv_sso_provider_struct buffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_sso_malloc();
	sso_cui_gid = mmi_frm_group_create_ex(
		APP_SSO, GRP_ID_MMI_SSO, 
		mmi_sso_accounts_gproc, 
		NULL, 
		MMI_FRM_NODE_SMART_CLOSE_FLAG);
	MMI_TRACE(MMI_INET_TRC_G7_SSO, MMI_SSO_LOGIN_BOOTUP);
	sso_cui_gid = mmi_frm_group_create_ex(
        GRP_ID_MMI_SSO, GRP_ID_MMI_SSO_IN, 
        mmi_sso_login_gproc, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
	#ifdef __MMI_SSO__
    	srv_sso_get_providers(&buffer, 1);
        sso_cui_gid = cui_sso_login_create_bootup(GRP_ID_MMI_SSO_IN, buffer.provider, 0);
        cui_sso_login_run(sso_cui_gid); 
	#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_main
 * DESCRIPTION
 *  enter yahoo service menu to deal with something
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_main(void)
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
	        mmi_usb_app_unavailable_popup(0);
            mmi_frm_app_close(APP_SSO);
	        return;
	    }
	#endif
	memset(&g_sso_sns_cxt, 0, sizeof(mmi_sso_sns_infor_struct));
	if (
		#if defined (__SOCIAL_NETWORK_SUPPORT__) 
		(!srv_sns_is_ready()) 
		#else
		1
		#endif
		#if defined (__MMI_SSO__) 
		&&(!srv_sso_is_ready())
		#endif
		)
    {
		#if defined (__SOCIAL_NETWORK_SUPPORT__) 
			mmi_popup_display_ext(srv_sns_get_error_string(srv_sns_get_ready()), MMI_EVENT_INFO, NULL);
		#else
			mmi_popup_display_ext(srv_sso_get_error_string(srv_sso_get_ready()), MMI_EVENT_INFO, NULL);
		#endif
		mmi_frm_app_close(APP_SSO);
		return;
    }
	mmi_sso_malloc();
    #ifdef __SOCIAL_NETWORK_SUPPORT__    
        mmi_frm_cb_reg_event(EVT_ID_SRV_SNS_READY, mmi_sso_sns_not_ready_proc, NULL);
	#endif

	#ifdef __MMI_SSO__
		mmi_frm_cb_reg_event(EVT_ID_SRV_SSO_READY, mmi_sso_not_ready_proc, NULL);
	#endif			
	MMI_TRACE(MMI_INET_TRC_G7_SSO, MMI_SSO_MAIN);
	mmi_frm_group_create_ex(
		/*GRP_ID_ROOT*/APP_SSO, GRP_ID_MMI_SSO, 
		mmi_sso_accounts_gproc, 
		NULL, 
		MMI_FRM_NODE_SMART_CLOSE_FLAG);
	
	mmi_frm_scrn_create(
		GRP_ID_MMI_SSO, 
		SCR_ID_MMI_SSO_ACCOUNTS, 
		mmi_sso_accounts_sproc, 
		NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_launch_init
 * DESCRIPTION
 *  Phonebook launch for ASM 2.0
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sso_main_pre_init(mmi_id app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (g_ssocui_startup)
	{
		mmi_sso_login_bootup();
	}
	else
	{
		mmi_sso_main();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_launch_init_proc
 * DESCRIPTION
 *  Phonebook launch proc function for ASM 2.0
 * PARAMETERS
 *  evt
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_sso_main_pre_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_ID app_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	app_id = GET_APP_ID(evt);
	switch (evt->evt_id)
	{
		case EVT_ID_APP_ENTER:
			mmi_sso_main_pre_init(app_id);
			break;       
        case EVT_ID_APP_DEINIT:
            g_ssocui_startup = MMI_FALSE;
			break;  
	}
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_main
 * DESCRIPTION
 *  enter yahoo service menu to deal with something
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/*
static void mmi_sso_main_pre(void)
{

	if (mmi_frm_app_is_launched(APP_SSO))
	{
	    MMI_TRACE(MMI_INET_TRC_G7_SSO, MMI_SSO_MAIN_PRE);
		mmi_frm_app_close(APP_SSO);
	}
	mmi_frm_app_launch(APP_SSO, 0, 0, mmi_sso_main_pre_proc, NULL, MMI_FRM_APP_NORMAL_LAUNCH);
}
*/
#ifndef __MMI_SUPPORT_ASMV2__
static void mmi_sso_app_mem_stop_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Free Memory */
	
		
	if (g_sso_sns_cxt.adm_id)
    {
    
        kal_adm_delete(g_sso_sns_cxt.adm_id);
        g_sso_sns_cxt.adm_id = 0;
    }
    if (g_sso_sns_cxt.asm_pool != NULL)
    {
        applib_mem_ap_free((void*)g_sso_sns_cxt.asm_pool);
        g_sso_sns_cxt.asm_pool = NULL;
    }

    /*Notify MMI that this application is already stopped */
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_SSO,KAL_TRUE);
    
	
}
#endif
static void mmi_sso_main_pre(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	 #ifdef __MMI_SUPPORT_ASMV2__
	if (mmi_frm_app_is_launched(APP_SSO))
	{
	    MMI_TRACE(MMI_INET_TRC_G7_SSO, MMI_SSO_MAIN_PRE);
		mmi_frm_app_close(APP_SSO);
	}
	mmi_frm_app_launch(APP_SSO, 0, 0, mmi_sso_main_pre_proc, NULL, MMI_FRM_APP_NORMAL_LAUNCH);
    #else
	applib_mem_ap_register(
	APPLIB_MEM_AP_ID_SSO,
	STR_ID_MMI_SSO_ACCOUNTS_SETTING,
	0,
	mmi_sso_app_mem_stop_callback);
	mmi_sso_main_pre_init(APP_SSO);
	#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sso_highlight
 * DESCRIPTION
 *  when highlight to yahoo service menu item, set something
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sso_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G7_SSO, MMI_SSO_HIGHLIGHT);
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetLeftSoftkeyFunction(mmi_sso_main_pre, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_sso_main_pre, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
#endif /* #if defined (__MMI_SSO__) || defined (__SOCIAL_NETWORK_SUPPORT__) */
