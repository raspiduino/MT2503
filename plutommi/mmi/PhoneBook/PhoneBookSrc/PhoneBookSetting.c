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
 *  PhoneBookSetting.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Implementation of feature "Settings" in the Phobebook Application
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "PhbCuiGprot.h"
     
#ifdef __MMI_LOCAL_PHB_SUPPORT__
 
#ifndef _PHONEBOOKSETTINGS_C
#define _PHONEBOOKSETTINGS_C
#include "MMI_features.h"
#include "MMIDataType.h"
#include "PhoneBookTypes.h"
#include "PhoneBookResDef.h"
#include "PhoneBookProt.h"
#include "PhbSrvGprot.h"
#include "PhoneBookCore.h"
#include "Mmi_frm_scenario_gprot.h"
#include "MenuCuiGprot.h"

#if defined(__MMI_VCARD__)
#include "vCard.h"
#endif

#ifdef __SYNCML_SUPPORT__
#include "SyncMLGprot.h"
#endif /* __SYNCML_SUPPORT__ */
#if 0
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#endif /* __MMI_OP01_SYNCML_SETTING__ */ 
/* under construction !*/
#if defined(__MMI_OP01_SYNCML_SETTING__)
/* under construction !*/
/* under construction !*/
#endif
#endif

#include "simctrlsrvgprot.h"
#include "modeSwitchSrvGprot.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "USBSrvGprot.h"
#include "usbdevicegprot.h"
#include "wgui_inline_edit.h"
#include "MMI_common_app_trc.h"
#include "PhoneBookGprot.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "ps_public_enum.h"
#include "GlobalResDef.h"
#include "wgui_categories_util.h"
#include "GlobalConstants.h"
#include "string.h"
#include "mmi_rp_app_phonebook_def.h"
#include "kal_general_types.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "mmi_rp_srv_syncml_def.h"
#include "custom_phb_config.h"
#include "wgui_categories_text_viewer.h"
#include "AlertScreen.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_common_app_trc.h"
#include "FileMgrSrvGProt.h"
#include "PhbSrvIprot.h"
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
#include "NetsetAppGprot.h"
#endif
#ifdef __VCARD_CLOUD_SUPPORT__
#include "SsoSrvGprot.h"
#include "SsoCuiGprot.h"
#include "CloudSrvGprot.h"
#include "wgui_categories_popup.h"
#include "CommonScreensResDef.h"
#include "mmi_rp_srv_sso_def.h"
#endif

/*
 * Define
 */
#ifndef __MMI_MAINLCD_96X64__
typedef struct mmi_phb_setting_screen_cntx{
    // change name
    U16 temp_prefer_storage;
#if defined(__MMI_PHB_SAVE_CONTACT_NOTIFY__)
    U16 temp_save_contact_notify;
#endif
#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    U8 temp_speak_name;
#endif /* __MMI_INTELLIGENT_CALL_ALERT__*/
#if defined(__MMI_MULTI_VCARD__)
    U16 *contact_array;                     /* contact list content */
    U16 contact_count;                      /* contact count */
#endif
}mmi_phb_setting_screen_cntx_struct;
#endif

#ifdef __VCARD_CLOUD_SUPPORT__

#define MMI_PHB_CLOUD_MAX_PROVIDER 2

typedef enum
{
    MMI_PHB_CLOUD_OP_BACKUP,
    MMI_PHB_CLOUD_OP_RESTORE,
    MMI_PHB_CLOUD_OP_TOTAL
} MMI_PHB_CLOUD_OP_ENUM;

typedef struct
{
    U32 provider_id[MMI_PHB_CLOUD_MAX_PROVIDER];
    U16 finish_count;
    U16 total_count;
    srv_phb_handle handle;
    U8 highlight_index;
    U8 provider_count;
    MMI_PHB_CLOUD_OP_ENUM op_type;
    MMI_BOOL is_local;
}mmi_phb_cloud_cntx_struct; 
#endif

typedef enum
{
    MMI_PHB_SPEAK_NAME_OFF,
    MMI_PHB_SPEAK_NAME_ON
} MMI_PHB_SPEAK_NAME_ENUM;

/*
 * Local Variable
 */

/*
 * Global Variable
 */
#ifdef __VCARD_CLOUD_SUPPORT__
mmi_phb_cloud_cntx_struct *g_phb_cloud_cntx;
extern mmi_phb_confirm_user_data_struct g_mmi_phb_confirm_user_data;
#endif

#ifndef __MMI_MAINLCD_96X64__ 
static mmi_phb_setting_cntx_struct g_phb_setting_cntx;
#else
mmi_phb_setting_cntx_struct g_phb_setting_cntx;
#endif

#ifndef __MMI_MAINLCD_96X64__ 
#ifdef LOW_COST_SUPPORT
mmi_phb_setting_screen_cntx_struct *sg_setting_cntx;
#endif
#else
mmi_phb_setting_screen_cntx_struct *sg_setting_cntx;
#endif

#ifndef __MMI_MAINLCD_96X64__
static mmi_ret mmi_phb_setting_group_proc(mmi_event_struct *evt);//setting screen group和其它app交互处理函数
#endif

#define MMI_PHB_SETTING_SAVE_CONTACT_NOTIFY
#if defined( __MMI_PHB_SAVE_CONTACT_NOTIFY__)
#ifndef __MMI_MAINLCD_96X64__
static mmi_ret mmi_phb_save_notify_menu_cui_proc(mmi_event_struct *evt);
#endif
void mmi_phb_entry_save_contact_notify(void);             //entry speak on/off screen
void mmi_phb_set_save_contact_notify(void);               //save user choose to nvram and global buffer
U16  mmi_phb_get_save_contact_notify(void);               //get save contact notify
#endif

#define MMI_PHB_SETTING_SPEAK_NAME
#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
#ifndef __MMI_MAINLCD_96X64__
static mmi_ret mmi_phb_speak_name_menu_cui_proc(mmi_event_struct *evt);
#endif
static void mmi_phb_entry_speak_name(void);                      //entry speak on/off screen
void mmi_phb_set_speak_name(void);                        //save user choose to nvram and global buffer
U8  mmi_phb_get_speak_name(void);                        //get speak name
#endif

#ifndef __MMI_PHB_SLIM_NO_PREFERRED_STORAGE__
#define MMI_PHB_SETTING_PERFER_STORAGE
#ifndef __MMI_MAINLCD_96X64__
static mmi_ret mmi_phb_prefer_storage_menu_cui_proc(mmi_event_struct *evt);
#endif
U16  mmi_phb_get_preferred_storage(void);                 //get prefer storage
#endif

#if defined(__MMI_PHB_LAST_NAME_FIELD__)
static void mmi_phb_entry_name_display(mmi_id sg_id);
static void mmi_phb_set_name_display_hint(mmi_id sg_id);
#ifndef __MMI_MAINLCD_96X64__
static void mmi_phb_name_display_menu_cui_proc(mmi_event_struct *evt);
#endif
#endif /* defined(__MMI_PHB_LAST_NAME_FIELD__) */

#ifdef __VCARD_CLOUD_SUPPORT__
static void mmi_phb_cloud_op(void);
static mmi_ret mmi_phb_cloud_not_ready_proc(mmi_event_struct *evt);
#endif

#ifndef __MMI_MAINLCD_96X64__
static void mmi_phb_entry_setting(void);                         //进入setting menu主选单
static void mmi_phb_entry_memory_status(void);                   //entry memory status screen
#ifndef __MMI_PHB_SLIM_NO_PREFERRED_STORAGE__
static void mmi_phb_set_preferred_storage(void);
static void mmi_phb_entry_preferred_storage(void);               //entry prefer storage screen
#endif
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_setting_init
 * DESCRIPTION
 *  Initialization of all "Settings" features
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __MMI_PHB_SLIM_NEW__
void mmi_phb_setting_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_INTELLIGENT_CALL_ALERT__) || defined(__MMI_PHB_SAVE_CONTACT_NOTIFY__)
    S16 error;
#endif
#if defined(__MMI_PHB_SAVE_CONTACT_NOTIFY__)
    U16 temp_value;
#endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */

#ifdef __MMI_MAINLCD_96X64__ 	
	void * buf = mmi_phb_mem_malloc(sizeof(mmi_phb_setting_screen_cntx_struct), SRV_PHB_MEMORY_TYPE_ADM);
#endif


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SETTING_INIT);

#ifdef __MMI_MAINLCD_96X64__ 			
	memset(buf, 0x00, sizeof(mmi_phb_setting_screen_cntx_struct));
	sg_setting_cntx = buf;
#endif

#ifndef __MMI_MAINLCD_96X64__
#ifdef __MMI_PHB_SLIM_NO_PREFERRED_STORAGE__
    g_phb_setting_cntx.prefer_storage =PHB_STORAGE_MAX;
    srv_phb_set_storage_mask(g_phb_setting_cntx.prefer_storage);
#endif
#endif

#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    ReadValue(NVRAM_PHB_SPEAK_NAME_ON_OFF, &g_phb_setting_cntx.speak_name, DS_BYTE, &error);
#endif /* defined(__MMI_INTELLIGENT_CALL_ALERT__) */

#if defined(__MMI_PHB_SAVE_CONTACT_NOTIFY__)    
    ReadValue(NVRAM_PHB_SAVE_CONTACT_NOTIFY, &temp_value, DS_SHORT, &error);
    if (temp_value != MMI_PHB_SAVE_CONTACT_NOTIFY_ON && temp_value != MMI_PHB_SAVE_CONTACT_NOTIFY_OFF)
        temp_value = MMI_PHB_SAVE_CONTACT_NOTIFY_ON;
    g_phb_setting_cntx.save_contact_notify= (U8)temp_value;
#endif /* defined(__MMI_PHB_SAVE_CONTACT_NOTIFY__) */
}
#endif
#if 0
#ifdef __MMI_OP12_PHB__
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
#endif /* __MMI_OP12_PHB__ */
#endif

#ifndef __MMI_MAINLCD_96X64__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sg_entry_setting
 * DESCRIPTION
 *  entry setting group before real setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sg_entry_setting(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void * buf = mmi_phb_mem_malloc(sizeof(mmi_phb_setting_screen_cntx_struct), SRV_PHB_MEMORY_TYPE_ADM);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(buf, 0x00, sizeof(mmi_phb_setting_screen_cntx_struct));

#ifdef LOW_COST_SUPPORT
    sg_setting_cntx = buf;
#endif
#if 0
#ifdef __MMI_OP12_PHB__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

#ifdef __MMI_PHB_UI_IN_TABS__
    if (group_id == GRP_ID_PHB_GROUP)
    {
        group_id = GRP_ID_PHB_MAIN;
    }
#endif

#ifdef __VCARD_CLOUD_SUPPORT__
    g_phb_cloud_cntx = mmi_phb_mem_malloc(sizeof(mmi_phb_cloud_cntx_struct), SRV_PHB_MEMORY_TYPE_ADM);
    g_phb_cloud_cntx ->handle= NULL;
    mmi_frm_cb_reg_event(EVT_ID_SRV_SSO_READY, mmi_phb_cloud_not_ready_proc, NULL);
#endif

    mmi_frm_group_create_ex(
        group_id,
        GRP_ID_PHB_SETTING,
        mmi_phb_setting_group_proc,
        buf,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_phb_entry_setting();
}
#endif

#ifdef __VCARD_CLOUD_SUPPORT__
#ifndef __MMI_SUPPORT_ASMV2__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cloud_asm_malloc
 * DESCRIPTION
 *  malloc asm memory for cloud service
 * PARAMETERS
 *  size
 * RETURNS
 *  ptr
 *****************************************************************************/
void *mmi_phb_cloud_asm_malloc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ptr = NULL;
    //mmi_frm_asm_property_struct p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    //mmi_frm_asm_property_init(&p);
    //mmi_frm_asm_set_property(APPLIB_MEM_AP_ID_PHB, &p);
 //   ptr = mmi_frm_asm_alloc_r(APPLIB_MEM_AP_ID_PHB, size);

//	g_phb_cntx_mgr.adm_id = kal_adm_create(g_phb_cntx_mgr.asm_pool, SCRMEM_PHB_CLOUD_POOL_SIZE, NULL, KAL_FALSE);
	 ptr = kal_adm_alloc(g_phb_cntx_mgr.adm_id, size);
	ASSERT(ptr != NULL);
	memset(ptr, 0, size);

    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_CLOUD_ASM_MALLOC, size, ptr);
    
    return ptr;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cloud_asm_free
 * DESCRIPTION
 *  free asm memory for cloud service
 * PARAMETERS
 *  ptr
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_cloud_asm_free(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_CLOUD_ASM_FREE, ptr);
    if (NULL != ptr)
    {
        //mmi_frm_asm_free_r(APPLIB_MEM_AP_ID_PHB, p);
		kal_adm_free(g_phb_cntx_mgr.adm_id, ptr);
        ptr = NULL;
    }
}

#else
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cloud_asm_malloc
 * DESCRIPTION
 *  malloc asm memory for cloud service
 * PARAMETERS
 *  size
 * RETURNS
 *  ptr
 *****************************************************************************/
void *mmi_phb_cloud_asm_malloc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ptr = NULL;
    mmi_frm_asm_property_struct p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    mmi_frm_asm_property_init(&p);
    mmi_frm_asm_set_property(APP_PHONEBOOK, &p);
    ptr = mmi_frm_asm_alloc_r(APP_PHONEBOOK, size);
    if (ptr)
    {
        memset(ptr, 0, size);
    }
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_CLOUD_ASM_MALLOC, size, ptr);
    
    return ptr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cloud_asm_free
 * DESCRIPTION
 *  free asm memory for cloud service
 * PARAMETERS
 *  ptr
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_cloud_asm_free(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_CLOUD_ASM_FREE, ptr);
    if (NULL != ptr)
    {
        mmi_frm_asm_free_r(APP_PHONEBOOK, ptr);
        ptr = NULL;
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cloud_cancel_processing
 * DESCRIPTION
 *  cancel and finish function of processing screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_cloud_cancel_processing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cloud_cntx->handle)
    {
        srv_phb_free_handle(g_phb_cloud_cntx->handle);
        g_phb_cloud_cntx->handle = NULL;
    }
    mmi_frm_scrn_close(GRP_ID_PHB_SETTING, SCR_ID_PHB_CLOUD_PROGRESS);
    g_phb_cloud_cntx->finish_count = 0;
    g_phb_cloud_cntx->total_count = 0;
}


mmi_ret mmi_phb_cloud_not_ready_proc(mmi_event_struct *evt)
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
        mmi_phb_cloud_cancel_processing(); 
        mmi_frm_scrn_close(GRP_ID_PHB_SETTING, SCR_ID_PHB_CLOUD_LIST);
        mmi_frm_scrn_close(GRP_ID_PHB_SETTING, SCR_ID_PHB_CLOUD_POPUP);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cloud_get_string
 * DESCRIPTION
 *  get string in processing screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  string id
 *****************************************************************************/
U16 mmi_phb_cloud_get_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id=0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cloud_cntx->op_type == MMI_PHB_CLOUD_OP_BACKUP)
    {
        string_id = STR_ID_PHB_CLOUD_BACKUPING; 
    }
    else if (g_phb_cloud_cntx->op_type == MMI_PHB_CLOUD_OP_RESTORE)
    {
        string_id = STR_ID_PHB_CLOUD_RESTORING; 
    }

    return string_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cloud_relogin
 * DESCRIPTION
 *  relogin when account logout.
 * PARAMETERS
 *  void
 * RETURNS
 *  string id
 *****************************************************************************/
void mmi_phb_cloud_relogin(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close_active_id();
    mmi_phb_cloud_op();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cloud_info_popup
 * DESCRIPTION
 *  when error happen, popup 
 * PARAMETERS
 *  screen info
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_cloud_info_popup(mmi_scrn_essential_struct *scrn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
        scrn_info->group_id, 
        scrn_info->scrn_id, 
        NULL, 
        (FuncPtr)mmi_phb_cloud_info_popup, 
        MMI_FRM_FULL_SCRN))
    {
        return;
    }
           
    ClearHighlightHandler();
    string_id = (U16)(scrn_info->user_data);
    ShowCategory66Screen(
        0,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        0,
        0,
        (U8*)GetString(string_id),
        mmi_get_event_based_image(MMI_EVENT_INFO),
        NULL);
    if (STR_ID_PHB_CLOUD_RESTORE_FULL == string_id)
    {
        SetLeftSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
    else if (STR_ID_PHB_CLOUD_RELOGIN == string_id)
    {
        SetLeftSoftkeyFunction(mmi_phb_cloud_relogin, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cloud_valid
 * DESCRIPTION
 *  check backup&restore callback result
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_phb_cloud_valid(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    U16 string_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_CLOUD_RESULT, result);
    switch (result)
    {   
        case SRV_PHB_STORAGE_FULL:
            string_id = STR_ID_PHB_CLOUD_RESTORE_FULL;
            mmi_frm_scrn_first_enter(GRP_ID_PHB_SETTING, SCR_ID_PHB_CLOUD_POPUP, (FuncPtr)mmi_phb_cloud_info_popup, (void*)string_id);
            break;

        case SRV_PHB_NO_ERROR:
            ret = MMI_TRUE;
            break;
            
        case SRV_PHB_CLOUD_NO_NEED_SYNC:
            if (MMI_PHB_CLOUD_OP_BACKUP == g_phb_cloud_cntx->op_type)
            {
                mmi_phb_popup_display_ext(STR_ID_PHB_CLOUD_NO_BACKUP, MMI_EVENT_FAILURE);   
            }
            else
            {
                mmi_phb_popup_display_ext(STR_ID_PHB_CLOUD_NO_RESTORE, MMI_EVENT_FAILURE);   
            }
            break;

        case SRV_PHB_CLOUD_LOGOUT:
            string_id = STR_ID_PHB_CLOUD_RELOGIN;
            mmi_frm_scrn_first_enter(GRP_ID_PHB_SETTING, SCR_ID_PHB_CLOUD_POPUP, (FuncPtr)mmi_phb_cloud_info_popup, (void*)string_id);
            break;
            
        case SRV_PHB_CLOUD_NO_STORAGE:
            mmi_phb_popup_display_ext(
                STR_GLOBAL_INSERT_MEMORY_CARD,
                MMI_EVENT_INFO);
            break;

        case SRV_PHB_CLOUD_DISK_FULL:
            mmi_phb_popup_display_ext(
                STR_GLOBAL_INSUFFICIENT_MEMORY,
                MMI_EVENT_INFO);
            break;
    
        default:
            mmi_phb_popup_display_ext(
                STR_GLOBAL_FAILED,
                MMI_EVENT_FAILURE);
            break;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cloud_callback
 * DESCRIPTION
 *  srv_phb_async_op_cb_struct
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_cloud_callback(srv_phb_async_op_cb_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 percentage;
    srv_phb_copy_all_cb_struct *finish;
    srv_phb_multi_op_status_cb_struct *update;
    U16 string_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_get_active_id() == SCR_ID_PHB_CLOUD_PROGRESS)
    {
        string_id = mmi_phb_cloud_get_string();
		if (info->type == SRV_PHB_OP_CB_TYPE_UPDATE_STATUS)
		{
			update = (srv_phb_multi_op_status_cb_struct *)info;
            MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_CLOUD_UPDATE, update->finish_count, update->fail_count, update->total_count);
			g_phb_cloud_cntx->finish_count = update->finish_count;
			percentage = (g_phb_cloud_cntx->finish_count * 100) / g_phb_cloud_cntx->total_count;
            wgui_cat6003_update_all((WCHAR*)GetString(string_id), NULL, percentage);
		}
		else
		{
			finish = (srv_phb_copy_all_cb_struct*)info;
			if (mmi_phb_cloud_valid(finish->result))
			{
				g_phb_cloud_cntx->finish_count = g_phb_cloud_cntx->total_count;
				percentage = (g_phb_cloud_cntx->finish_count * 100) / g_phb_cloud_cntx->total_count;
                wgui_cat6003_update_all((WCHAR*)GetString(string_id), NULL, percentage);
            }
            mmi_phb_cloud_cancel_processing(); 
		}              
    }
    else
    {
        if (info->type == SRV_PHB_OP_CB_TYPE_UPDATE_STATUS)
        {
            update = (srv_phb_multi_op_status_cb_struct *)info;
            MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_CLOUD_UPDATE, update->finish_count, update->fail_count, update->total_count);
            g_phb_cloud_cntx->finish_count = update->finish_count;
        }
        else
        {
            finish = (srv_phb_copy_all_cb_struct*)info;
            mmi_phb_cloud_valid(finish->result); 
            mmi_phb_cloud_cancel_processing(); 
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cloud_show_processing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrn_data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_cloud_show_processing(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id;
    U8 percentage;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (mmi_frm_scrn_enter(
        scrn_data->group_id,
        scrn_data->scrn_id,
        NULL,
        (FuncPtr)mmi_phb_cloud_show_processing,
        MMI_FRM_FULL_SCRN))
    {
        string_id = mmi_phb_cloud_get_string();
        percentage = (g_phb_cloud_cntx->finish_count * 100) / g_phb_cloud_cntx->total_count;
        
        wgui_cat6003_show(
            0,
            STR_GLOBAL_CANCEL,
            (WCHAR*)GetString(string_id),
            NULL,
            percentage);

        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == 0)
        {
            ClearInputEventHandler(MMI_DEVICE_KEY);
        }

        SetRightSoftkeyFunction(mmi_phb_cloud_cancel_processing, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cloud_scrn_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *                 
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_phb_cloud_scrn_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
            mmi_phb_cloud_cancel_processing();
            break;
                         
        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cloud_entry_processing
 * DESCRIPTION
 *  
 * PARAMETERS
 *                 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_cloud_entry_processing(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cloud_cntx->op_type == MMI_PHB_CLOUD_OP_BACKUP)
    {
        g_phb_cloud_cntx->total_count = srv_phb_get_used_contact(PHB_STORAGE_NVRAM);
    }
    else
    {
        g_phb_cloud_cntx->total_count = srv_phb_get_total_contact(PHB_STORAGE_NVRAM);
    }
    mmi_frm_scrn_first_enter(sg_id, SCR_ID_PHB_CLOUD_PROGRESS, (FuncPtr)mmi_phb_cloud_show_processing, NULL);

    mmi_frm_scrn_set_leave_proc(
        sg_id,
        SCR_ID_PHB_CLOUD_PROGRESS,
        mmi_phb_cloud_scrn_proc);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cloud_action
 * DESCRIPTION
 *  backup&restore function action
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_cloud_action(MMI_PHB_CLOUD_OP_ENUM op, U32 provider, U8 account_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    mmi_phb_cloud_entry_processing(GRP_ID_PHB_SETTING);

    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_CLOUD_ACTION, op, provider, account_id);
    if (MMI_PHB_CLOUD_OP_BACKUP == op)
    {
        srv_phb_backup_req_struct backup_req;

        memset(&backup_req, 0, sizeof(srv_phb_backup_req_struct));
        backup_req.cb = mmi_phb_cloud_callback;
        backup_req.mode = SRV_PHB_BACKUP_RESTORE_MODE_CLOUD;
        backup_req.provider = provider;
        backup_req.account = account_id;
        backup_req.storage = PHB_STORAGE_NVRAM;
        backup_req.malloc_func = mmi_phb_cloud_asm_malloc;
        backup_req.free_func = mmi_phb_cloud_asm_free;
        g_phb_cloud_cntx->handle = srv_phb_backup_contact(&backup_req);
    }
    else if (MMI_PHB_CLOUD_OP_RESTORE == op)
    {
        srv_phb_restore_req_struct restore_req;

        memset(&restore_req, 0, sizeof(srv_phb_restore_req_struct));
        restore_req.cb = mmi_phb_cloud_callback;
        restore_req.mode = SRV_PHB_BACKUP_RESTORE_MODE_CLOUD;
        restore_req.provider = provider;
        restore_req.account = account_id;
        restore_req.malloc_func = mmi_phb_cloud_asm_malloc;
        restore_req.free_func = mmi_phb_cloud_asm_free;
        g_phb_cloud_cntx->handle = srv_phb_restore_contact(&restore_req);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cloud_get_account
 * DESCRIPTION
 *  get sso account
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_cloud_get_account(U32 provider_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;
    srv_sso_account_struct user_account;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sso_get_accounts(provider_id, SRV_SSO_LOGIN_TRUE, &user_account, 1))
    {
        mmi_phb_cloud_action(g_phb_cloud_cntx->op_type, provider_id, user_account.account);
    }
    else if (srv_sso_get_accounts(provider_id, SRV_SSO_LOGIN_FALSE, &user_account, 1))
    {
        group_id = cui_sso_login_create(GRP_ID_PHB_SETTING, provider_id, user_account.account);
        if (group_id)
        {
            cui_sso_login_run(group_id);
        }
    }
    else
    {
        group_id = cui_sso_login_create(GRP_ID_PHB_SETTING, provider_id, 0);
        if (group_id)
        {
            cui_sso_login_run(group_id);
        }
    }
}


#ifndef __MMI_SUPPORT_ASMV2__

MMI_BOOL mmi_phb_asm_mem_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    

    /* Get ASM*/
    g_phb_cntx_mgr.asm_pool = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_PHB, SCRMEM_PHB_CLOUD_POOL_SIZE);
    if (g_phb_cntx_mgr.asm_pool == NULL)
    {
        return MMI_FALSE;
    }

    /* Init ADM*/
    g_phb_cntx_mgr.adm_id = kal_adm_create(g_phb_cntx_mgr.asm_pool, SCRMEM_PHB_CLOUD_POOL_SIZE, NULL, KAL_FALSE);
    MMI_ASSERT(g_phb_cntx_mgr.adm_id);
    
    return MMI_TRUE;
}

#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cloud_op
 * DESCRIPTION
 *  cloud service confirm lsk function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_cloud_op(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 provider_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    provider_id = g_phb_cloud_cntx->provider_id[g_phb_cloud_cntx->highlight_index];
#ifndef __MMI_SUPPORT_ASMV2__
	mmi_phb_asm_mem_init();
#endif	
    mmi_phb_cloud_get_account(provider_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cloud_login
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_cloud_login(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id=0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cloud_cntx->is_local && g_phb_cloud_cntx->highlight_index == g_phb_cloud_cntx->provider_count)
    {
        if (g_phb_cloud_cntx->op_type == MMI_PHB_CLOUD_OP_BACKUP)
        {
            mmi_phb_entry_backup_contact(GRP_ID_PHB_SETTING);
        }
        else if (g_phb_cloud_cntx->op_type == MMI_PHB_CLOUD_OP_RESTORE)
        {
            mmi_phb_entry_restore_contact(GRP_ID_PHB_SETTING);
        }
    }
    else
    {   
        if (g_phb_cloud_cntx->op_type == MMI_PHB_CLOUD_OP_BACKUP)
        {
            if (mmi_phb_check_storage_status(PHB_STORAGE_NVRAM, MMI_PHB_CHECK_STORAGE_EMPTY, MMI_FALSE))
            {
                mmi_phb_popup_display_ext(STR_ID_PHB_CLOUD_NO_BACKUP, MMI_EVENT_FAILURE);
                return;    
            }
            string_id = STR_ID_PHB_CLOUD_BACKUP_ASK; 
        }
        else if (g_phb_cloud_cntx->op_type == MMI_PHB_CLOUD_OP_RESTORE)
        {
            if (mmi_phb_check_storage_status(PHB_STORAGE_NVRAM, MMI_PHB_CHECK_STORAGE_FULL, MMI_TRUE))
            {
                return;
            }
            string_id = STR_ID_PHB_CLOUD_RESTORE_ASK; 
        }

        mmi_phb_confirm_display_ext(
            string_id,
            GRP_ID_PHB_SETTING,
            mmi_phb_cloud_op,
            mmi_frm_scrn_close_active_id,
            MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_edit_group_info_highlight_hdlr
 * DESCRIPTION
 *  Highlight Handler for multi select
 * PARAMETERS
 *  item_index                   [IN]            highlight item index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_cloud_highlight_hdlr(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cloud_cntx->highlight_index = (U8)item_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cloud_get_items
 * DESCRIPTION
 *  Gets the async items for the provider list.
 * PARAMETERS
 *  start_index     [IN]
 *  *menu_data      [OUT]
 *  num_items       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_phb_cloud_get_items(S32 start_index, gui_iconlist_menu_item *menu_data, S32 num_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 index;
    WCHAR name[SRV_SSO_NAME_SIZE];
    U32 provider;
    srv_sso_account_struct user_account;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < num_items; i++)
    {
        index = start_index + i;
        if (g_phb_cloud_cntx->is_local && index == (S32)g_phb_cloud_cntx->provider_count)
        {
            mmi_ucs2cpy((CHAR*)menu_data[i].item_list[0], GetString(STR_GLOBAL_MEMORY_CARD));
            menu_data[i].image_list[0] = get_image(IMG_ID_PHB_MEMORY_CARD);
            mmi_wcscpy((WCHAR*)menu_data[i].item_list[1], L"vcard.vcf");
        }
        else
        {
            provider = g_phb_cloud_cntx->provider_id[index];   
            srv_sso_get_provider_name(provider, name);
            mmi_wcsncpy((WCHAR*)menu_data[i].item_list[0], name, SRV_SSO_NAME_SIZE);
            if (srv_sso_get_accounts(provider, SRV_SSO_LOGIN_TRUE, &user_account, 1))
            {
                srv_sso_get_account_name(provider, user_account.account, name);
                mmi_wcsncpy((WCHAR*)menu_data[i].item_list[1], name, SRV_SSO_NAME_SIZE);      
            }
            else
            {
                mmi_ucs2cpy((CHAR*)menu_data[i].item_list[1], GetString(STR_ID_PHB_CLOUD_LOGOUT));
            }
        }
    }

    return num_items;
}


static void mmi_phb_cloud_get_image_info(S32 item_idx, wgui_thumbnail_info_struct *info_data)
{
    if (g_phb_cloud_cntx->is_local && item_idx == (S32)g_phb_cloud_cntx->provider_count)
    {
        info_data->is_show_thumb = MMI_FALSE;
        info_data->file_icon_ptr = get_image(IMG_ID_PHB_MEMORY_CARD);
    }
    else
    {
        info_data->is_show_thumb = MMI_TRUE;
    }

}


static MMI_BOOL mmi_phb_cloud_get_image_path(S32 item_idx, CHAR *file_path)
{
    mmi_ucs2cpy((CHAR*)file_path, (CHAR*)srv_sso_get_provider_icon(g_phb_cloud_cntx->provider_id[item_idx], SRV_SSO_ICON_LARGE));
    if(file_path != NULL)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    } 
}


#ifdef __MMI_MULTI_VCARD__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cloud_check_memory_card
 * DESCRIPTION
 *  check whether can backup to memory card
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_cloud_check_memory_card(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_fmgr_drv_is_accessible(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE)))
    {
        g_phb_cloud_cntx->is_local = MMI_TRUE;        
    }
    else
    {
        g_phb_cloud_cntx->is_local = MMI_FALSE;
    }
}
#endif


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cloud_tap_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  provider id num 
 *****************************************************************************/
void mmi_phb_cloud_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        mmi_phb_cloud_login();    
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cloud_entry_list
 * DESCRIPTION
 *  show provider list
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE: is s
 *****************************************************************************/
static void mmi_phb_cloud_entry_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id=0;
    U8 *gui_buffer;
    S32 item_count;
    S32 highlighted_item = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MAINLCD_96X64__ 
    if (!mmi_frm_scrn_enter(
		GRP_ID_PHB_SETTING,
        SCR_ID_PHB_CLOUD_LIST,
 		NULL,
        mmi_phb_cloud_entry_list,
        MMI_FRM_UNKNOW_SCRN))
#else
	if (!mmi_frm_scrn_enter(
		GRP_ID_PHB_MAIN,
        SCR_ID_PHB_CLOUD_LIST,
 		NULL,
        mmi_phb_cloud_entry_list,
        MMI_FRM_UNKNOW_SCRN))
#endif
    {
    	return;
    }
    
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    RegisterHighlightHandler(mmi_phb_cloud_highlight_hdlr);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    
    if (g_phb_cloud_cntx->op_type == MMI_PHB_CLOUD_OP_BACKUP)
    {
        string_id = STR_ID_PHB_CLOUD_BACKUP; 
    }
    else if (g_phb_cloud_cntx->op_type == MMI_PHB_CLOUD_OP_RESTORE)
    {
        string_id = STR_ID_PHB_CLOUD_RESTORE; 
    }
#ifdef __MMI_MULTI_VCARD__
    mmi_phb_cloud_check_memory_card();
#endif

    if (g_phb_cloud_cntx->is_local)
    {
        item_count = (S32)(g_phb_cloud_cntx->provider_count + 1);
    }
    else
    {
        item_count = (S32)(g_phb_cloud_cntx->provider_count);
    }

    if (gui_buffer)
    {
        highlighted_item = (S32)g_phb_cloud_cntx->highlight_index;
    }

    wgui_thumbnail_register_get_image_info_func(mmi_phb_cloud_get_image_info);
    wgui_thumbnail_register_get_image_path_func(mmi_phb_cloud_get_image_path);
    wgui_cat1071_show(
        (PU8)GetString(string_id),
        NULL,
        STR_GLOBAL_OK,
        STR_GLOBAL_BACK,
        item_count,
        mmi_phb_cloud_get_items,
        highlighted_item,
        IMG_ID_PHB_MEMORY_CARD,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_phb_cloud_login, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_phb_cloud_login, KEY_EVENT_UP);
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_phb_cloud_tap_callback);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cloud_get_provider_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  provider id num 
 *****************************************************************************/
void mmi_phb_cloud_get_provider_id(MMI_ID sender_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 provider_count;
    U32 i;
    srv_sso_provider_struct provider;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cloud_support_backup_restore_list(SRV_CLD_TYPE_VCARD, g_phb_cloud_cntx->provider_id, &provider_count);
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_CLOUD_GET_PROVIDER, g_phb_cloud_cntx->provider_id[0], provider_count);
    for (i = 0; i < provider_count; i++)
    {
        if (!srv_sso_get_provider(g_phb_cloud_cntx->provider_id[i], &provider)) 
        {
            MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_CLOUD_PROVIDER_CHECK);
            provider_count--;
            g_phb_cloud_cntx->provider_id[i] = 0;
        }
    }
    g_phb_cloud_cntx->provider_count = provider_count;
    
#ifndef __MMI_MULTI_VCARD__
    if (0 == provider_count)
    {
        cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_BACKUP, MMI_TRUE);
        cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_RESTORE, MMI_TRUE);
    }
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cloud_entry_cloud_backup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_cloud_entry_cloud_backup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cloud_cntx->op_type = MMI_PHB_CLOUD_OP_BACKUP;
#ifdef __MMI_MULTI_VCARD__   
    if (!g_phb_cloud_cntx->provider_count)
    { 
        #ifndef __MMI_MAINLCD_96X64__ 
        mmi_phb_entry_backup_contact(GRP_ID_PHB_SETTING);
        #else
	mmi_phb_entry_backup_contact(GRP_ID_PHB_MAIN);
	#endif
    }
    else
#endif
    {
        mmi_phb_cloud_entry_list();    
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cloud_entry_cloud_restore
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_cloud_entry_cloud_restore(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cloud_cntx->op_type = MMI_PHB_CLOUD_OP_RESTORE;
#ifdef __MMI_MULTI_VCARD__
    if (!g_phb_cloud_cntx->provider_count)
    {
        #ifndef __MMI_MAINLCD_96X64__ 
        mmi_phb_entry_restore_contact(GRP_ID_PHB_SETTING);
	#else
	mmi_phb_entry_restore_contact(GRP_ID_PHB_MAIN);
	#endif
    }
    else
#endif
    {
        mmi_phb_cloud_entry_list();    
    }
}
#endif


#if defined(__MMI_MULTI_VCARD__) || defined(__VCARD_CLOUD_SUPPORT__)
/*****************************************************************************
* FUNCTION
*  mmi_phb_cloud_entry_cloud
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
void mmi_phb_check_backup_accessible(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MULTI_VCARD__)
    if (srv_fmgr_drv_is_accessible(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE)))
    {
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_PHB_BACKUP, MMI_FALSE);

        if (g_phb_setting_cntx.highlighted_menu_id == MENU_ID_PHB_BACKUP)
        {
            if (menu_evt->cui_menu_event_flags != CUI_MENU_LIST_FROM_HISTORY)
            {
                cui_menu_set_currlist_highlighted_id(menu_evt->sender_id, MENU_ID_PHB_BACKUP);
            }
        }
    }
    else
#endif
    {
    #ifdef __VCARD_CLOUD_SUPPORT__
        if (!g_phb_cloud_cntx->provider_count)    
    #endif
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_PHB_BACKUP, MMI_TRUE);
        }
    #ifdef __VCARD_CLOUD_SUPPORT__
        else
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_PHB_BACKUP, MMI_FALSE);
        }
    #endif
    }

#if defined(__MMI_MULTI_VCARD__)
    if (srv_fmgr_drv_is_accessible(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE)))
    {
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_PHB_RESTORE, MMI_FALSE);

        if (g_phb_setting_cntx.highlighted_menu_id == MENU_ID_PHB_RESTORE)
        {
            if (menu_evt->cui_menu_event_flags != CUI_MENU_LIST_FROM_HISTORY)
            {
                cui_menu_set_currlist_highlighted_id(menu_evt->sender_id, MENU_ID_PHB_RESTORE);
            }
        }
    }
    else
#endif
    {    
    #ifdef __VCARD_CLOUD_SUPPORT__
        if (!g_phb_cloud_cntx->provider_count)    
    #endif
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_PHB_RESTORE, MMI_TRUE);
        }
    #ifdef __VCARD_CLOUD_SUPPORT__
        else
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_PHB_RESTORE, MMI_FALSE);
        }
    #endif
    } 
}
#endif


#ifdef __MMI_PHB_SLIM_SETTING_MESS_OPERATION__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_check_mess_operation
 * DESCRIPTION
 *  if sim card or memory card insert, enable menu
 * PARAMETERS
 *  parent_menu_id, sender_id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_check_mess_operation(MMI_ID sender_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (!srv_sim_ctrl_any_sim_is_available()
    #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        && !srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV)
    #endif
        )
    {
        cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_DELETE_ALL, MMI_TRUE);
        cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_COPY_SEVERAL, MMI_TRUE);
        cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_MOVE_SEVERAL, MMI_TRUE);
        cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_DELETE_ALL_NO_SIM, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_DELETE_ALL, MMI_FALSE);
        cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_COPY_SEVERAL, MMI_FALSE);
        cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_MOVE_SEVERAL, MMI_FALSE);
        cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_DELETE_ALL_NO_SIM, MMI_TRUE);
    }
}
#endif

#ifndef __MMI_MAINLCD_96X64__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_setting_menu_cui_proc
 * DESCRIPTION
 *  screen group setting agent callback function
 * PARAMETERS
 *  evt        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_phb_setting_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    MMI_MENU_ID parent_menu_id = menu_evt->parent_menu_id;
    MMI_ID sender_id = menu_evt->sender_id;
    mmi_ret result = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            if (parent_menu_id == MENU_ID_PHB_SETTINGS ||
                parent_menu_id == MENU_ID_PHB_SETTINGS_NO_SIM)
            {
            #if 0
            #if defined(__MMI_SYNCML_APP_SYNC_MENU_SUPPORT__) || !defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_OP01_SYNCML_SETTING__)
/* under construction !*/
            #endif
			#else
			#if defined(__MMI_SYNCML_APP_SYNC_MENU_SUPPORT__) || !defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
                MMI_BOOL is_hide;
            #endif
            #endif

                cui_menu_set_currlist_flags(sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

            #if defined(__MMI_SYNCML_APP_SYNC_MENU_SUPPORT__)
                if (mmi_syncml_app_sync_is_display(MMI_SYNCML_PHB_SYNC_MENU))
                {
                    is_hide = MMI_FALSE;
                }
                else
                {
                    is_hide = MMI_TRUE;
                }
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_SYNC, is_hide);
            #endif /* __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__ */

            #if !defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
                if (mmi_phb_check_extra_number_available())
                {
                    is_hide = MMI_FALSE;
                }
                else
                {
                    is_hide = MMI_TRUE;
                }
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_EXTRA_NUMBER, is_hide);
            #endif
            #if 0
            #if defined(__MMI_OP01_SYNCML_SETTING__)
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
            #endif /* __MMI_OP01_SYNCML_SETTING__ */
			#endif

            #ifdef __VCARD_CLOUD_SUPPORT__
                mmi_phb_cloud_get_provider_id(sender_id);
            #endif

            #if defined(__MMI_MULTI_VCARD__) || defined(__VCARD_CLOUD_SUPPORT__)
                mmi_phb_check_backup_accessible(menu_evt);
            #endif /* defined(__MMI_MULTI_VCARD__) */

            #ifndef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_MY_NUMBER, MMI_TRUE);
            #endif

            #ifndef __MMI_PHB_SLIM_SETTING_MESS_OPERATION__
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_DELETE_ALL, MMI_TRUE);
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_COPY_SEVERAL, MMI_TRUE);
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_MOVE_SEVERAL, MMI_TRUE);
	            cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_DELETE_ALL_NO_SIM, MMI_TRUE);	
            #else
                mmi_phb_entry_check_mess_operation(sender_id);
            #endif /* __MMI_PHB_SLIM_SETTING_MESS_OPERATION__ */
            }
            else
            {
                result = MMI_RET_DONT_CARE;
            }
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            switch(menu_evt->highlighted_menu_id)
            {
#ifndef __MMI_PHB_SLIM_NO_PREFERRED_STORAGE__
                case MENU_ID_PHB_PREFERRED_STORAGE:
                    mmi_phb_entry_preferred_storage();
                    break;
#endif

            #ifdef __MMI_PHB_SPEED_DIAL__
                case MENU_ID_PHB_SPEED_DIAL:
            #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                    if (srv_sim_ctrl_any_sim_is_available())
                    {
                        mmi_phb_entry_group_speed_dial(); 
                    }
                    else
                    {
                        mmi_phb_popup_display_ext(STR_GLOBAL_UNAVAILABLE_SIM, MMI_EVENT_INFO);
                    }
            #else
                    mmi_phb_entry_group_speed_dial();
            #endif
                    break;
            #endif
            #if 0
            #ifdef __OP01_FWPBW__
/* under construction !*/
            #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
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
            #endif
/* under construction !*/
            #endif
            #endif

            #ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
                case  MENU_ID_PHB_MY_NUMBER:
                    mmi_phb_entry_group_my_number();
                    break;
            #endif /* __MMI_PHB_SLIM_EXTRA_DEFEATURE__ */

                case  MENU_ID_PHB_EXTRA_NUMBER:
            #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                    if (mmi_phb_check_extra_number_available() && srv_sim_ctrl_any_sim_is_available())
                    {
                        mmi_phb_entry_group_extra_number(); 
                    }
                    else
                    {
                        mmi_phb_popup_display_ext(STR_GLOBAL_UNAVAILABLE_SIM, MMI_EVENT_INFO);
                    }
            #else
                    mmi_phb_entry_group_extra_number(); 
            #endif
                    break;

            #if defined(__MMI_INTELLIGENT_CALL_ALERT__)
                case  MENU_ID_PHB_SPEAK_NAME:
                    mmi_phb_entry_speak_name();
                    break;
            #endif

            #if defined(__MMI_PHB_SAVE_CONTACT_NOTIFY__)
                case  MENU_ID_PHB_SAVE_CONTACT_NOTIFY:
                    mmi_phb_entry_save_contact_notify();
                    break;
            #endif

                case  MENU_ID_PHB_MEMORY_STATUS:
                    mmi_phb_entry_memory_status();
                    break;

            #ifdef __MMI_PHB_SLIM_SETTING_MESS_OPERATION__
                case  MENU_ID_PHB_COPY_SEVERAL:
                    mmi_phb_group_copy_several();
                    break;
                case  MENU_ID_PHB_MOVE_SEVERAL:
                    mmi_phb_group_move_several();
                    break;
                case  MENU_ID_PHB_DELETE_ALL:
                    mmi_phb_group_delete_all();
                    break;
                case  MENU_ID_PHB_DELETE_ALL_NO_SIM:
                    mmi_phb_entry_delete_all_no_sim();
                    break;
            #endif /* __MMI_PHB_SLIM_SETTING_MESS_OPERATION__ */

            #if defined(__MMI_MULTI_VCARD__) || defined(__VCARD_CLOUD_SUPPORT__)
                case  MENU_ID_PHB_BACKUP:
                #ifdef __VCARD_CLOUD_SUPPORT__
                    mmi_phb_cloud_entry_cloud_backup();
                #else
                    mmi_phb_entry_backup_contact(GRP_ID_PHB_SETTING);
                #endif
                    break;
                
                case  MENU_ID_PHB_RESTORE:
                #ifdef __VCARD_CLOUD_SUPPORT__
                    mmi_phb_cloud_entry_cloud_restore();
                #else
                    mmi_phb_entry_restore_contact(GRP_ID_PHB_SETTING);
                #endif
                    break;
            #endif /* __MMI_MULTI_VCARD__  || __VCARD_CLOUD_SUPPORT__ */

            #ifdef __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__
                case  MENU_ID_PHB_SYNC:
                    mmi_phb_entry_sync_menu();
                    break;
            #endif /* __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__ */
            #if 0
            #if defined(__MMI_OP01_SYNCML_SETTING__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            #endif

            #if defined(__MMI_PHB_LAST_NAME_FIELD__)
                case  MENU_ID_PHB_NAME_DISPLAY:
                    mmi_phb_entry_name_display(GRP_ID_PHB_SETTING);
                    break;
            #endif

                default:
                    result = MMI_RET_DONT_CARE;
                    break;
            }
            break;
        }

        case EVT_ID_CUI_MENU_ITEM_HILITE:
        {
            g_phb_setting_cntx.highlighted_menu_id = menu_evt->highlighted_menu_id;

        #if defined(__MMI_INTELLIGENT_CALL_ALERT__)
            if (menu_evt->highlighted_menu_id == MENU_ID_PHB_SPEAK_NAME)
            {
                if (g_phb_setting_cntx.speak_name)
                {
                    cui_menu_set_item_hint(sender_id, MENU_ID_PHB_SPEAK_NAME, get_string(STR_GLOBAL_ON));
                }
                else
                {
                    cui_menu_set_item_hint(sender_id, MENU_ID_PHB_SPEAK_NAME, get_string(STR_GLOBAL_OFF));
                }
            }
            else
        #endif
        #if defined(__MMI_PHB_SAVE_CONTACT_NOTIFY__)
            if (menu_evt->highlighted_menu_id == MENU_ID_PHB_SAVE_CONTACT_NOTIFY)
            {
                if (g_phb_setting_cntx.save_contact_notify == MMI_PHB_SAVE_CONTACT_NOTIFY_ON)
                {
                    cui_menu_set_item_hint(sender_id, MENU_ID_PHB_SAVE_CONTACT_NOTIFY, get_string(STR_GLOBAL_ON));
                }
                else
                {
                    cui_menu_set_item_hint(sender_id, MENU_ID_PHB_SAVE_CONTACT_NOTIFY, get_string(STR_GLOBAL_OFF));
                }
            }
            else 
        #endif
        #if defined(__MMI_PHB_LAST_NAME_FIELD__)
            if (menu_evt->highlighted_menu_id == MENU_ID_PHB_NAME_DISPLAY)
            {
                mmi_phb_set_name_display_hint(sender_id);
            }
            else
        #endif
            {
                result = MMI_RET_DONT_CARE;
            }
            break;
        }

        default:
            result = MMI_RET_DONT_CARE;
            break;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_setting
 * DESCRIPTION
 *  entry setting main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_menu_id root_menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_ENTRY_SETTING);
#if 0
#ifdef __MMI_OP12_PHB__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    root_menu_id = MENU_ID_PHB_SETTINGS;
#else
    root_menu_id = srv_sim_ctrl_any_sim_is_available() ? MENU_ID_PHB_SETTINGS : MENU_ID_PHB_SETTINGS_NO_SIM;
#endif

    g_phb_setting_cntx.highlighted_menu_id = 0;

    mmi_phb_entry_menu_cui_generic_ext(
        GRP_ID_PHB_SETTING,
        CUI_MENU_TYPE_APPSUB,
        root_menu_id,
        0,
        NULL);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_phb_setting_group_proc
 * DESCRIPTION
 *  screen group setting agent callback function
 * PARAMETERS
 *  evt        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_phb_setting_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef LOW_COST_SUPPORT
    mmi_phb_setting_screen_cntx_struct *sg_setting_cntx = 
        (mmi_phb_setting_screen_cntx_struct *)mmi_frm_group_get_user_data(GRP_ID_PHB_SETTING);
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_setting_menu_cui_proc(evt) == MMI_RET_OK) 
    {
        return MMI_RET_OK;
    }

#if defined(__MMI_PHB_SAVE_CONTACT_NOTIFY__)
    if (mmi_phb_save_notify_menu_cui_proc(evt) == MMI_RET_OK) 
    {
        return MMI_RET_OK;
    }
#endif

#if defined(__MMI_INTELLIGENT_CALL_ALERT__) 
    if (mmi_phb_speak_name_menu_cui_proc(evt) == MMI_RET_OK) 
    {
        return MMI_RET_OK;
    }    
#endif
#ifndef __MMI_PHB_SLIM_NO_PREFERRED_STORAGE__
    if (mmi_phb_prefer_storage_menu_cui_proc(evt) == MMI_RET_OK) 
    {
        return MMI_RET_OK;
    }
#endif

#if defined(__MMI_PHB_LAST_NAME_FIELD__)
    mmi_phb_name_display_menu_cui_proc(evt);
#endif

    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
        #if defined(__MMI_MULTI_VCARD__)
            if (sg_setting_cntx->contact_array)
            {
                mmi_phb_mem_free(sg_setting_cntx->contact_array);
                sg_setting_cntx->contact_array = NULL;
            }
        #endif
            mmi_phb_mem_free(sg_setting_cntx);
        #ifdef LOW_COST_SUPPORT
            sg_setting_cntx = NULL;
        #endif
        #ifdef __VCARD_CLOUD_SUPPORT__
            if (g_phb_cloud_cntx->handle)
            {
                srv_phb_free_handle(g_phb_cloud_cntx->handle);
                g_phb_cloud_cntx->handle = NULL;
            }
            mmi_phb_mem_free(g_phb_cloud_cntx);
            mmi_frm_cb_dereg_event(EVT_ID_SRV_SSO_READY, mmi_phb_cloud_not_ready_proc, NULL);
        #endif
            break;

        case EVT_ID_GROUP_INACTIVE:
            if (!mmi_frm_scrn_get_count(GRP_ID_PHB_SETTING))
            {
                mmi_frm_group_close(GRP_ID_PHB_SETTING);
            }
            break;

    #if defined(__MMI_MULTI_VCARD__)
        case EVT_ID_VCARD_EXPORT_CANCEL:
        case EVT_ID_VCARD_EXPORT_DONE:
            cui_vcard_export_vcard_close(((cui_vcard_result_struct*)evt)->sender_id);
            mmi_phb_mem_free(sg_setting_cntx->contact_array);
            sg_setting_cntx->contact_array = NULL;
            break;
        case EVT_ID_VCARD_IMPORT_CANCEL:
        case EVT_ID_VCARD_IMPORT_DONE:
            cui_vcard_import_vcard_close(((cui_vcard_result_struct*)evt)->sender_id);
            break;
    #endif /* defined(__MMI_MULTI_VCARD__) */

    #ifdef __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__
        case EVT_ID_SYNC_MINIMIZE:
            mmi_frm_group_close(GRP_ID_PHB_MAIN);
            mmi_frm_group_close(GRP_ID_PHB_SETTING);
            break;
    #endif

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(((cui_menu_event_struct*)evt)->sender_id);
            break;
        }

     #ifdef __VCARD_CLOUD_SUPPORT__
        case EVT_ID_CUI_SSO_LOGIN_DONE:
        {
            cui_sso_login_done_event_struct *cloud_evt = (cui_sso_login_done_event_struct*)evt;

            if (cloud_evt->result == EVT_ID_CUI_SSO_LOGIN_OK)
            {
			    cui_sso_login_close(cloud_evt->sender_id);
                mmi_phb_cloud_op();
            }
            else if (cloud_evt->result == EVT_ID_CUI_SS0_LOGIN_ABORT)
            {
                cui_sso_login_close(cloud_evt->sender_id);
            }
            break;
        }

        case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct *alert_result = (mmi_alert_result_evt_struct*) evt;

            mmi_phb_confirm_display_handle(alert_result);
            break;
        }           
     #endif

        default:
            break;
    }

    return MMI_RET_OK;
}

#else
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_setting_group_proc
 * DESCRIPTION
 *  screen group setting agent callback function
 * PARAMETERS
 *  evt        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_phb_setting_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	




    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


#if defined(__MMI_PHB_SAVE_CONTACT_NOTIFY__)
    if (mmi_phb_save_notify_menu_cui_proc(evt) == MMI_RET_OK) 
    {
        return MMI_RET_OK;
    }
#endif

#if defined(__MMI_INTELLIGENT_CALL_ALERT__) 
    if (mmi_phb_speak_name_menu_cui_proc(evt) == MMI_RET_OK) 
    {
        return MMI_RET_OK;
    }    
#endif

    if (mmi_phb_prefer_storage_menu_cui_proc(evt) == MMI_RET_OK) 
    {
        return MMI_RET_OK;
    }



#if defined(__MMI_PHB_LAST_NAME_FIELD__)
    mmi_phb_name_display_menu_cui_proc(evt);
#endif



    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
        #if defined(__MMI_MULTI_VCARD__)
            if (sg_setting_cntx->contact_array)
            {
                mmi_phb_mem_free(sg_setting_cntx->contact_array);
                sg_setting_cntx->contact_array = NULL;
            }
        #endif
            mmi_phb_mem_free(sg_setting_cntx);
	
        
            sg_setting_cntx = NULL;
        
		
        #ifdef __VCARD_CLOUD_SUPPORT__
            if (g_phb_cloud_cntx->handle)
            {
                srv_phb_free_handle(g_phb_cloud_cntx->handle);
                g_phb_cloud_cntx->handle = NULL;
            }
            mmi_phb_mem_free(g_phb_cloud_cntx);
            mmi_frm_cb_dereg_event(EVT_ID_SRV_SSO_READY, mmi_phb_cloud_not_ready_proc, NULL);
        #endif
            break;

        case EVT_ID_GROUP_INACTIVE:
            if (!mmi_frm_scrn_get_count(GRP_ID_PHB_SETTING))
            {
                mmi_frm_group_close(GRP_ID_PHB_SETTING);
            }
            break;

    #if defined(__MMI_MULTI_VCARD__)
        case EVT_ID_VCARD_EXPORT_CANCEL:
        case EVT_ID_VCARD_EXPORT_DONE:
            cui_vcard_export_vcard_close(((cui_vcard_result_struct*)evt)->sender_id);
            mmi_phb_mem_free(sg_setting_cntx->contact_array);
            sg_setting_cntx->contact_array = NULL;
            break;
        case EVT_ID_VCARD_IMPORT_CANCEL:
        case EVT_ID_VCARD_IMPORT_DONE:
            cui_vcard_import_vcard_close(((cui_vcard_result_struct*)evt)->sender_id);
            break;
    #endif /* defined(__MMI_MULTI_VCARD__) */

    #ifdef __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__
        case EVT_ID_SYNC_MINIMIZE:
            mmi_frm_group_close(GRP_ID_PHB_MAIN);
            mmi_frm_group_close(GRP_ID_PHB_SETTING);
            break;
    #endif

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(((cui_menu_event_struct*)evt)->sender_id);
            break;
        }

     #ifdef __VCARD_CLOUD_SUPPORT__
        case EVT_ID_CUI_SSO_LOGIN_DONE:
        {
            cui_sso_login_done_event_struct *cloud_evt = (cui_sso_login_done_event_struct*)evt;

            if (cloud_evt->result == EVT_ID_CUI_SSO_LOGIN_OK)
            {
			    cui_sso_login_close(cloud_evt->sender_id);
                mmi_phb_cloud_op();
            }
            else if (cloud_evt->result == EVT_ID_CUI_SS0_LOGIN_ABORT)
            {
                cui_sso_login_close(cloud_evt->sender_id);
            }
            break;
        }

        case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct *alert_result = (mmi_alert_result_evt_struct*) evt;

            mmi_phb_confirm_display_handle(alert_result);
            break;
        }           
     #endif

        default:
            break;
    }


    return MMI_RET_OK;
}
#endif




#ifdef __MMI_PHB_USIM_GROUP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_setting_get_usim_group_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_phb_setting_get_usim_group_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 field;
    U8 group_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(srv_sim_ctrl_is_available(MMI_SIM1))
    {
        field = srv_phb_get_support_field(PHB_STORAGE_SIM);
        if (field & MMI_PHB_CONTACT_FIELD_GROUP)
        {
            group_count += srv_phb_get_usim_field_total(PHB_STORAGE_SIM, 0, PHB_GAS);
        }
    }

#if (MMI_MAX_SIM_NUM >= 2)
    if(srv_sim_ctrl_is_available(MMI_SIM2))
    {
        field = srv_phb_get_support_field(PHB_STORAGE_SIM2);
        if (field & MMI_PHB_CONTACT_FIELD_GROUP)
        {
            group_count += srv_phb_get_usim_field_total(PHB_STORAGE_SIM2, 0, PHB_GAS);
        }
    }
#endif /* MMI_MAX_SIM_NUM >= 2 */

#if (MMI_MAX_SIM_NUM >= 3)
    if(srv_sim_ctrl_is_available(MMI_SIM3))
    {
        field = srv_phb_get_support_field(PHB_STORAGE_SIM3);
        if (field & MMI_PHB_CONTACT_FIELD_GROUP)
        {
            group_count += srv_phb_get_usim_field_total(PHB_STORAGE_SIM3, 0, PHB_GAS);
        }
    }
#endif

#if (MMI_MAX_SIM_NUM >= 4)
    if(srv_sim_ctrl_is_available(MMI_SIM4))
    {
        field = srv_phb_get_support_field(PHB_STORAGE_SIM4);
        if (field & MMI_PHB_CONTACT_FIELD_GROUP)
        {
            group_count += srv_phb_get_usim_field_total(PHB_STORAGE_SIM4, 0, PHB_GAS);
        }
    }
#endif

    return group_count;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_memory_status
 * DESCRIPTION
 *  Draws the memory status screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __MMI_MAINLCD_96X64__
static void mmi_phb_entry_memory_status(void)
#else
void mmi_phb_entry_memory_status(void)
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *memory_status = OslMalloc(1024);
#ifdef __MMI_PHB_USIM_SUPPORT__
    U8 i = 0;
#endif
//#if !defined(__OP01_FWPBW__) && !defined(__OP01_FWPCOLOR__)
#ifdef __MMI_PHB_CALLER_GROUP__ 
    U8 group_number = 0;
    U8 group_id_list[MMI_PHB_GROUP_TOTAL_COUNT];
    U8 group_total = MMI_PHB_GROUP_COUNT;
#endif
//#endif
    U32 count = 0;
    CHAR *sep_string = GetString(STR_ID_PHB_SEP_COLON);
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__    
    WCHAR dynamic_name[MMI_NETSET_SIM_NAME_MAX_LEN * 2]; 
    MMI_BOOL is_one_sim = MMI_FALSE;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_ENTRY_MEMORY_STATUS);

#ifdef __SYNCML_SUPPORT__
    if (mmi_syncml_is_phb_sync_now())
    {
        mmi_phb_entry_not_ready(STR_ID_SYNC_PLEASE_WAIT);
    }
#endif /* __SYNCML_SUPPORT__ */

    if (mmi_phb_check_ready(MMI_FALSE))
    {
        #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        if (1 == srv_sim_ctrl_get_num_of_inserted())
        {
            is_one_sim = MMI_TRUE;
        }
        #endif
    
        memset(memory_status, 0, 1024);
        if (srv_sim_ctrl_is_available(MMI_SIM1))
        {
        #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
            U16 sim_str_id = (is_one_sim == MMI_TRUE ? STR_GLOBAL_SIM : STR_GLOBAL_SIM_1);
            mmi_netset_get_sim_name_with_brace(MMI_SIM1, dynamic_name, MMI_NETSET_SIM_NAME_MAX_LEN * 2);
            kal_wsprintf((WCHAR*)memory_status, "%w%w%d/%d%w\n",         
                GetString(sim_str_id),
                sep_string,
                srv_phb_get_used_contact(PHB_STORAGE_SIM),
                srv_phb_get_total_contact(PHB_STORAGE_SIM),
                dynamic_name);
        #else
            kal_wsprintf((WCHAR*)memory_status, "%w%w%d/%d\n",
            #if (MMI_MAX_SIM_NUM >= 2)
                GetString(STR_GLOBAL_SIM_1),
            #else
                GetString(STR_GLOBAL_SIM),
            #endif          
                sep_string,
                srv_phb_get_used_contact(PHB_STORAGE_SIM),
                srv_phb_get_total_contact(PHB_STORAGE_SIM));
        #endif
        }
    #if (MMI_MAX_SIM_NUM >= 2)
        for (count = 1; count < MMI_MAX_SIM_NUM; count++)
        {
            if (srv_sim_ctrl_is_available(MMI_SIM1 << count))
            {
                U32 string_id = (count == 1 ? STR_GLOBAL_SIM_2 : (count == 2 ? STR_GLOBAL_SIM_3 : STR_GLOBAL_SIM_4));
            #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__ 
                if (is_one_sim)
                {
                    string_id = STR_GLOBAL_SIM;
                }
                mmi_netset_get_sim_name_with_brace(MMI_SIM1 << count, dynamic_name, MMI_NETSET_SIM_NAME_MAX_LEN * 2);
                kal_wsprintf((WCHAR*)memory_status, "%w%w%w%d/%d%w\n",
                    memory_status,
                    GetString(string_id),
                    sep_string,
                    srv_phb_get_used_contact(PHB_STORAGE_SIM + count),
                    srv_phb_get_total_contact(PHB_STORAGE_SIM + count),
                    dynamic_name);
            #else
                kal_wsprintf((WCHAR*)memory_status, "%w%w%w%d/%d\n",
                    memory_status,
                    GetString(string_id),
                    sep_string,
                    srv_phb_get_used_contact(PHB_STORAGE_SIM + count),
                    srv_phb_get_total_contact(PHB_STORAGE_SIM + count));
            #endif
            }
        }
    #endif /* MMI_MAX_SIM_NUM >= 2 */
        kal_wsprintf((WCHAR*)memory_status, "%w%w%w%d/%d\n",
                memory_status,
                GetString(STR_GLOBAL_PHONE),
                sep_string,
                srv_phb_get_used_contact(PHB_STORAGE_NVRAM),
                srv_phb_get_total_contact(PHB_STORAGE_NVRAM));

    #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        if (srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV))
        {
            kal_wsprintf((WCHAR*)memory_status, "%w%w%w%d/%d\n",
                memory_status,
                GetString(STR_GLOBAL_MEMORY_CARD),
                sep_string,
                srv_phb_get_used_contact(PHB_STORAGE_TCARD),
                srv_phb_get_total_contact(PHB_STORAGE_TCARD));
        }
    #endif

    //#if !defined(__OP01_FWPBW__) && !defined(__OP01_FWPCOLOR__)
    #ifdef __MMI_PHB_CALLER_GROUP__
    #if defined(__MMI_PHB_TCARD_STORAGE_SUPPORT__) || defined (__MMI_PHB_USIM_GROUP_SUPPORT__)
        group_number = srv_phb_get_group_list(group_id_list, NULL, PHB_STORAGE_MAX);
    #else
        group_number = srv_phb_get_group_list(group_id_list, NULL, PHB_STORAGE_NVRAM);
    #endif
    #ifdef __MMI_PHB_USIM_GROUP_SUPPORT__
        group_total += mmi_phb_setting_get_usim_group_count();
    #endif
    #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        if (srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV))
        {
            group_total += MMI_PHB_GROUP_TCARD_COUNT;
        }
    #endif
        kal_wsprintf((WCHAR*)memory_status, "%w%w%w%d/%d\n",
                memory_status,
                GetString(STR_CALLER_GROUP),
                GetString(STR_ID_PHB_SEP_COLON),
                group_number,
                group_total);
    #endif /* __MMI_PHB_CALLER_GROUP__ */
    //#endif

    #ifdef __MMI_PHB_USIM_SUPPORT__
        if (srv_sim_ctrl_is_available(MMI_SIM1))
        {
        #if (MMI_MAX_SIM_NUM >= 2)
            U16 str_id = STR_ID_PHB_SIM1_ADDITION_NUMBER;
        #else
            U16 str_id = STR_ID_PHB_ADDITION_NUMBER;
        #endif
        #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
            if (is_one_sim)
            {
                str_id = STR_ID_PHB_ADDITION_NUMBER;
            }
        #endif
            count = srv_phb_get_support_field_count(PHB_STORAGE_SIM, MMI_PHB_CONTACT_FIELD_ID_NUMBER);
            if(count == 2)
            {
                if (srv_phb_get_usim_field_total(PHB_STORAGE_SIM, 0, PHB_ANR))
                { 
                #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                    mmi_netset_get_sim_name_with_brace(MMI_SIM1, dynamic_name, MMI_NETSET_SIM_NAME_MAX_LEN * 2);
                    kal_wsprintf((WCHAR*)memory_status, "%w%w%w%d/%d%w\n",
                        memory_status,
                        GetString(str_id),
                        GetString(STR_ID_PHB_SEP_COLON),
                        srv_phb_get_usim_field_used(PHB_STORAGE_SIM, 0, PHB_ANR),
                        srv_phb_get_usim_field_total(PHB_STORAGE_SIM, 0, PHB_ANR),
                        dynamic_name);
                #else
                    kal_wsprintf((WCHAR*)memory_status, "%w%w%w%d/%d\n",
                        memory_status,
                        GetString(str_id),
                        GetString(STR_ID_PHB_SEP_COLON),
                        srv_phb_get_usim_field_used(PHB_STORAGE_SIM, 0, PHB_ANR),
                        srv_phb_get_usim_field_total(PHB_STORAGE_SIM, 0, PHB_ANR));
                #endif
                }
            }
            else 
            {
                for(i = 0; i < count - 1; i++)
                {
                    if (srv_phb_get_usim_field_total(PHB_STORAGE_SIM, i, PHB_ANR))
                    {
                    #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                        mmi_netset_get_sim_name_with_brace(MMI_SIM1, dynamic_name, MMI_NETSET_SIM_NAME_MAX_LEN * 2);
                        kal_wsprintf((WCHAR*)memory_status, "%w%w%d%w%d/%d%w\n",
                                memory_status,
                                GetString(str_id),
                                i + 1,
                                GetString(STR_ID_PHB_SEP_COLON),
                                srv_phb_get_usim_field_used(PHB_STORAGE_SIM, i, PHB_ANR),
                                srv_phb_get_usim_field_total(PHB_STORAGE_SIM, i, PHB_ANR),
                                dynamic_name);
                    #else
                        kal_wsprintf((WCHAR*)memory_status, "%w%w%d%w%d/%d\n",
                                memory_status,
                                GetString(str_id),
                                i + 1,
                                GetString(STR_ID_PHB_SEP_COLON),
                                srv_phb_get_usim_field_used(PHB_STORAGE_SIM, i, PHB_ANR),
                                srv_phb_get_usim_field_total(PHB_STORAGE_SIM, i, PHB_ANR));
                    #endif
                    }
                }
            }
        #if (MMI_MAX_SIM_NUM >= 2)
            str_id = STR_ID_PHB_SIM1_EMAIL_COUNT;
        #else
            str_id = STR_ID_PHB_SIM_EMAIL_COUNT;
        #endif
        #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
            if (is_one_sim)
            {
                str_id = STR_ID_PHB_SIM_EMAIL_COUNT;
            }
        #endif
            count = srv_phb_get_support_field_count(PHB_STORAGE_SIM, MMI_PHB_CONTACT_FIELD_ID_EMAIL);
            if(count == 1)
            {
                if (srv_phb_get_usim_field_total(PHB_STORAGE_SIM, 0, PHB_EMAIL))
                {
                #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                    mmi_netset_get_sim_name_with_brace(MMI_SIM1, dynamic_name, MMI_NETSET_SIM_NAME_MAX_LEN * 2);
                    kal_wsprintf((WCHAR*)memory_status, "%w%w%w%d/%d%w\n",
                        memory_status,
                        GetString(str_id),
                        GetString(STR_ID_PHB_SEP_COLON),
                        srv_phb_get_usim_field_used(PHB_STORAGE_SIM, 0, PHB_EMAIL),
                        srv_phb_get_usim_field_total(PHB_STORAGE_SIM, 0, PHB_EMAIL),
                        dynamic_name);
                #else
                    kal_wsprintf((WCHAR*)memory_status, "%w%w%w%d/%d\n",
                        memory_status,
                        GetString(str_id),
                        GetString(STR_ID_PHB_SEP_COLON),
                        srv_phb_get_usim_field_used(PHB_STORAGE_SIM, 0, PHB_EMAIL),
                        srv_phb_get_usim_field_total(PHB_STORAGE_SIM, 0, PHB_EMAIL));
                #endif
                }
            }
            else
            {
                for(i = 0; i < count; i++)
                {
                    if (srv_phb_get_usim_field_total(PHB_STORAGE_SIM, i, PHB_EMAIL))
                    {
                    #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                        mmi_netset_get_sim_name_with_brace(MMI_SIM1, dynamic_name, MMI_NETSET_SIM_NAME_MAX_LEN * 2);
                         kal_wsprintf((WCHAR*)memory_status, "%w%w%d%w%d/%d%w\n",
                                memory_status,
                                GetString(str_id),
                                i + 1,
                                GetString(STR_ID_PHB_SEP_COLON),
                                srv_phb_get_usim_field_used(PHB_STORAGE_SIM, i, PHB_EMAIL),
                                srv_phb_get_usim_field_total(PHB_STORAGE_SIM, i, PHB_EMAIL),
                                dynamic_name);
                    #else
                        kal_wsprintf((WCHAR*)memory_status, "%w%w%d%w%d/%d\n",
                                memory_status,
                                GetString(str_id),
                                i + 1,
                                GetString(STR_ID_PHB_SEP_COLON),
                                srv_phb_get_usim_field_used(PHB_STORAGE_SIM, i, PHB_EMAIL),
                                srv_phb_get_usim_field_total(PHB_STORAGE_SIM, i, PHB_EMAIL));
                    #endif
                    }
                }
            }
        }
    #if (MMI_MAX_SIM_NUM >= 2)
        if (srv_sim_ctrl_is_available(MMI_SIM2))
        {
            U16 additon_str_id = STR_ID_PHB_SIM2_ADDITION_NUMBER;
            U16 email_str_id = STR_ID_PHB_SIM2_EMAIL_COUNT;
        #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
            if (is_one_sim)
            {
                additon_str_id = STR_ID_PHB_ADDITION_NUMBER;
            }
        #endif
            count = srv_phb_get_support_field_count(PHB_STORAGE_SIM2, MMI_PHB_CONTACT_FIELD_ID_NUMBER);
            if(count == 2)
            {
                if (srv_phb_get_usim_field_total(PHB_STORAGE_SIM2, 0, PHB_ANR))
                {
                #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                    mmi_netset_get_sim_name_with_brace(MMI_SIM2, dynamic_name, MMI_NETSET_SIM_NAME_MAX_LEN * 2);
                    kal_wsprintf((WCHAR*)memory_status, "%w%w%w%d/%d%w\n",
                        memory_status,
                        GetString(additon_str_id),
                        GetString(STR_ID_PHB_SEP_COLON),
                        srv_phb_get_usim_field_used(PHB_STORAGE_SIM2, 0, PHB_ANR),
                        srv_phb_get_usim_field_total(PHB_STORAGE_SIM2, 0, PHB_ANR),
                        dynamic_name);
                #else
                    kal_wsprintf((WCHAR*)memory_status, "%w%w%w%d/%d\n",
                        memory_status,
                        GetString(additon_str_id),
                        GetString(STR_ID_PHB_SEP_COLON),
                        srv_phb_get_usim_field_used(PHB_STORAGE_SIM2, 0, PHB_ANR),
                        srv_phb_get_usim_field_total(PHB_STORAGE_SIM2, 0, PHB_ANR));
                #endif
                }
            }
            else 
            {
                for(i = 0; i < count - 1; i++)
                {
                    if (srv_phb_get_usim_field_total(PHB_STORAGE_SIM2, i, PHB_ANR))
                    {
                    #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                        mmi_netset_get_sim_name_with_brace(MMI_SIM2, dynamic_name, MMI_NETSET_SIM_NAME_MAX_LEN * 2);
                        kal_wsprintf((WCHAR*)memory_status, "%w%w%d%w%d/%d%w\n",
                                memory_status,
                                GetString(additon_str_id),
                                i + 1,
                                GetString(STR_ID_PHB_SEP_COLON),
                                srv_phb_get_usim_field_used(PHB_STORAGE_SIM2, i, PHB_ANR),
                                srv_phb_get_usim_field_total(PHB_STORAGE_SIM2, i, PHB_ANR),
                                dynamic_name);
                    #else
                        kal_wsprintf((WCHAR*)memory_status, "%w%w%d%w%d/%d\n",
                                memory_status,
                                GetString(additon_str_id),
                                i + 1,
                                GetString(STR_ID_PHB_SEP_COLON),
                                srv_phb_get_usim_field_used(PHB_STORAGE_SIM2, i, PHB_ANR),
                                srv_phb_get_usim_field_total(PHB_STORAGE_SIM2, i, PHB_ANR));
                    #endif
                    }
                }
            }

        #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
            if (is_one_sim)
            {
                email_str_id = STR_ID_PHB_SIM_EMAIL_COUNT;
            }
        #endif
            count = srv_phb_get_support_field_count(PHB_STORAGE_SIM2, MMI_PHB_CONTACT_FIELD_ID_EMAIL);
            if(count == 1)
            {
                if (srv_phb_get_usim_field_total(PHB_STORAGE_SIM2, 0, PHB_EMAIL))
                {
                #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                    mmi_netset_get_sim_name_with_brace(MMI_SIM2, dynamic_name, MMI_NETSET_SIM_NAME_MAX_LEN * 2);
                    kal_wsprintf((WCHAR*)memory_status, "%w%w%w%d/%d%w\n",
                            memory_status,
                            GetString(email_str_id),
                            GetString(STR_ID_PHB_SEP_COLON),
                            srv_phb_get_usim_field_used(PHB_STORAGE_SIM2, 0, PHB_EMAIL),
                            srv_phb_get_usim_field_total(PHB_STORAGE_SIM2, 0, PHB_EMAIL),
                            dynamic_name);
                #else
                    kal_wsprintf((WCHAR*)memory_status, "%w%w%w%d/%d\n",
                            memory_status,
                            GetString(email_str_id),
                            GetString(STR_ID_PHB_SEP_COLON),
                            srv_phb_get_usim_field_used(PHB_STORAGE_SIM2, 0, PHB_EMAIL),
                            srv_phb_get_usim_field_total(PHB_STORAGE_SIM2, 0, PHB_EMAIL));
                #endif
                }
            }
            else
            {
                for(i = 0; i < count; i++)
                {
                    if (srv_phb_get_usim_field_total(PHB_STORAGE_SIM2, i, PHB_EMAIL))
                    {
                    #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                        mmi_netset_get_sim_name_with_brace(MMI_SIM2, dynamic_name, MMI_NETSET_SIM_NAME_MAX_LEN * 2);
                        kal_wsprintf((WCHAR*)memory_status, "%w%w%d%w%d/%d%w\n",
                                memory_status,
                                GetString(email_str_id),
                                i + 1,
                                GetString(STR_ID_PHB_SEP_COLON),
                                srv_phb_get_usim_field_used(PHB_STORAGE_SIM2, i, PHB_EMAIL),
                                srv_phb_get_usim_field_total(PHB_STORAGE_SIM2, i, PHB_EMAIL),
                                dynamic_name);
                    #else
                        kal_wsprintf((WCHAR*)memory_status, "%w%w%d%w%d/%d\n",
                                memory_status,
                                GetString(email_str_id),
                                i + 1,
                                GetString(STR_ID_PHB_SEP_COLON),
                                srv_phb_get_usim_field_used(PHB_STORAGE_SIM2, i, PHB_EMAIL),
                                srv_phb_get_usim_field_total(PHB_STORAGE_SIM2, i, PHB_EMAIL));
                    #endif
                    }
                }
            }
        }
    #endif /* MMI_MAX_SIM_NUM >= 2 */
    #endif /* __MMI_PHB_USIM_SUPPORT__ */
    #ifndef __MMI_MAINLCD_96X64__
        if(!mmi_frm_scrn_enter(
            GRP_ID_PHB_SETTING,
            SCR_MEMORY_STATUS,
            NULL,
            mmi_phb_entry_memory_status,
            MMI_FRM_UNKNOW_SCRN))
    #else
	        if(!mmi_frm_scrn_enter(
            GRP_ID_PHB_MAIN,
            SCR_MEMORY_STATUS,
            NULL,
            mmi_phb_entry_memory_status,
            MMI_FRM_UNKNOW_SCRN))
    #endif
        {
            OslMfree(memory_status);
            return;
        }  
        ShowCategory7Screen(
            STR_GLOBAL_MEMORY_STATUS,
            IMG_SCR_PBOOK_CAPTION,
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (PU8) memory_status,
            mmi_frm_scrn_get_active_gui_buf());
    }
    else
    {
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
    }

    OslMfree(memory_status);
}


#if defined(__MMI_PHB_SAVE_CONTACT_NOTIFY__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_save_notify_menu_cui_proc
 * DESCRIPTION
 *  screen group setting agent callback function
 * PARAMETERS
 *  evt        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __MMI_MAINLCD_96X64__
static mmi_ret mmi_phb_save_notify_menu_cui_proc(mmi_event_struct *evt)
#else
mmi_ret mmi_phb_save_notify_menu_cui_proc(mmi_event_struct *evt)
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    MMI_ID sender_id = menu_evt->sender_id;
    MMI_MENU_ID highlighted_menu_id = menu_evt->highlighted_menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            if (menu_evt->parent_menu_id == MENU_ID_PHB_SAVE_CONTACT_NOTIFY)
            {
                cui_menu_set_currlist_flags(sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);

                if (g_phb_setting_cntx.save_contact_notify == MMI_PHB_SAVE_CONTACT_NOTIFY_ON)
                {
                    cui_menu_set_radio_list_item(sender_id, MENU_ID_PHB_SAVE_CONTACT_NOTIFY_ON);
                }
                else
                {
                    cui_menu_set_radio_list_item(sender_id, MENU_ID_PHB_SAVE_CONTACT_NOTIFY_OFF);
                }
                return MMI_RET_OK;
            }
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            if (highlighted_menu_id == MENU_ID_PHB_SAVE_CONTACT_NOTIFY_ON)
            {
                mmi_phb_set_save_contact_notify();
                cui_menu_close(sender_id);
            }
            else if (highlighted_menu_id == MENU_ID_PHB_SAVE_CONTACT_NOTIFY_OFF)
            {
                mmi_phb_set_save_contact_notify();
                cui_menu_close(sender_id);
            }
            else
            {
                return MMI_RET_DONT_CARE;
            }
            return MMI_RET_OK;
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        {
#ifndef __MMI_MAINLCD_96X64__
        #ifndef LOW_COST_SUPPORT
            mmi_phb_setting_screen_cntx_struct *sg_setting_cntx = 
                (mmi_phb_setting_screen_cntx_struct *)mmi_frm_group_get_user_data(GRP_ID_PHB_SETTING);
        #endif
#endif

            if (highlighted_menu_id == MENU_ID_PHB_SAVE_CONTACT_NOTIFY_ON)
            {
                sg_setting_cntx->temp_save_contact_notify = MMI_PHB_SAVE_CONTACT_NOTIFY_ON;
                return MMI_RET_OK;
            }
            if (highlighted_menu_id == MENU_ID_PHB_SAVE_CONTACT_NOTIFY_OFF)
            {
                sg_setting_cntx->temp_save_contact_notify = MMI_PHB_SAVE_CONTACT_NOTIFY_OFF;
                return MMI_RET_OK;
            }
            break;
        }
        default:
            break;
    }
    return MMI_RET_DONT_CARE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_save_contact_notify
 * DESCRIPTION
 *  entry save notify screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_save_contact_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_ENTRY_VCARD_VERSION);

    if (mmi_phb_check_ready(MMI_FALSE))
    {
#ifndef __MMI_MAINLCD_96X64__
        mmi_phb_entry_menu_cui_generic_ext(
            GRP_ID_PHB_SETTING,
            CUI_MENU_TYPE_APPSUB,
            MENU_ID_PHB_SAVE_CONTACT_NOTIFY,
            0,
            NULL);
#else
        mmi_phb_entry_menu_cui_generic_ext(
            GRP_ID_PHB_MAIN,
            CUI_MENU_TYPE_APPSUB,
            MENU_ID_PHB_SAVE_CONTACT_NOTIFY,
            0,
            NULL);
#endif
    }
    else
    {
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_set_save_contact_notify
 * DESCRIPTION
 *  write save notify to nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_set_save_contact_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U16 temp_value;
#ifndef __MMI_MAINLCD_96X64__
#ifndef LOW_COST_SUPPORT
    mmi_phb_setting_screen_cntx_struct *sg_setting_cntx = 
        (mmi_phb_setting_screen_cntx_struct *)mmi_frm_group_get_user_data(GRP_ID_PHB_SETTING);
#endif
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_VCARD_VERSION_SET_REQ);

    if (g_phb_setting_cntx.save_contact_notify != sg_setting_cntx->temp_save_contact_notify)
    {
        g_phb_setting_cntx.save_contact_notify = sg_setting_cntx->temp_save_contact_notify;
        temp_value = g_phb_setting_cntx.save_contact_notify;
        WriteValue(NVRAM_PHB_SAVE_CONTACT_NOTIFY, &temp_value, DS_SHORT, &error);
    }
#ifndef __MMI_MAINLCD_96X64__
    mmi_popup_display_simple_ext(
        STR_GLOBAL_DONE,
        MMI_EVENT_SUCCESS,
        GRP_ID_PHB_SETTING,
        0);
#else
    mmi_popup_display_simple_ext(
        STR_GLOBAL_DONE,
        MMI_EVENT_SUCCESS,
        GRP_ID_PHB_MAIN,
        0);


#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_save_contact_notify
 * DESCRIPTION
 *  get save notify
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_phb_get_save_contact_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_phb_setting_cntx.save_contact_notify;
}
#endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */


#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_speak_name_menu_cui_proc
 * DESCRIPTION
 *  screen group setting agent callback function
 * PARAMETERS
 *  evt        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __MMI_MAINLCD_96X64__
static mmi_ret mmi_phb_speak_name_menu_cui_proc(mmi_event_struct *evt)
#else
mmi_ret mmi_phb_speak_name_menu_cui_proc(mmi_event_struct *evt)
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    MMI_ID sender_id = menu_evt->sender_id;
    MMI_MENU_ID highlighted_menu_id = menu_evt->highlighted_menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            if (menu_evt->parent_menu_id == MENU_ID_PHB_SPEAK_NAME)
            {
                cui_menu_set_currlist_flags(sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);

                if (g_phb_setting_cntx.speak_name == MMI_PHB_SPEAK_NAME_ON)
                {
                    cui_menu_set_radio_list_item(sender_id, MENU_ID_PHB_SPEAK_NAME_ON);
                    cui_menu_set_currlist_highlighted_id(sender_id, MENU_ID_PHB_SPEAK_NAME_ON);
                }
                else
                {
                    cui_menu_set_radio_list_item(sender_id, MENU_ID_PHB_SPEAK_NAME_OFF);
                    cui_menu_set_currlist_highlighted_id(sender_id, MENU_ID_PHB_SPEAK_NAME_OFF);
                }
                return MMI_RET_OK;
            }
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            if (highlighted_menu_id == MENU_ID_PHB_SPEAK_NAME_ON)
            {
                mmi_phb_set_speak_name();
                cui_menu_close(sender_id);
            }
            else if (highlighted_menu_id == MENU_ID_PHB_SPEAK_NAME_OFF)
            {
                mmi_phb_set_speak_name();
                cui_menu_close(sender_id);
            }
            else
            {
                return MMI_RET_DONT_CARE;
            }
            return MMI_RET_OK;
            break;
        }

        case EVT_ID_CUI_MENU_ITEM_HILITE:
        {
#ifndef __MMI_MAINLCD_96X64__
        #ifndef LOW_COST_SUPPORT
            mmi_phb_setting_screen_cntx_struct *sg_setting_cntx = 
                (mmi_phb_setting_screen_cntx_struct *)mmi_frm_group_get_user_data(GRP_ID_PHB_SETTING);
        #endif
#endif
            if (highlighted_menu_id == MENU_ID_PHB_SPEAK_NAME_ON)
            {
                sg_setting_cntx->temp_speak_name = MMI_PHB_SPEAK_NAME_ON;
                return MMI_RET_OK;
            }
            if (highlighted_menu_id == MENU_ID_PHB_SPEAK_NAME_OFF)
            {
                sg_setting_cntx->temp_speak_name = MMI_PHB_SPEAK_NAME_OFF;
                return MMI_RET_OK;
            }
            break;
        }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(sender_id);
            return MMI_RET_OK;
            break;
        }

        default:
            break;
    }
    return MMI_RET_DONT_CARE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_speak_name
 * DESCRIPTION
 *  entry speak name screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_speak_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_ENTRY_VCARD_VERSION);/*需要修改*/
    
    if (mmi_phb_check_ready(MMI_FALSE))
    {
#ifndef __MMI_MAINLCD_96X64__
        mmi_phb_entry_menu_cui_generic_ext(
            GRP_ID_PHB_SETTING,
            CUI_MENU_TYPE_APPSUB,
            MENU_ID_PHB_SPEAK_NAME,
            0,
            NULL);
#else
	    mmi_phb_entry_menu_cui_generic_ext(
            GRP_ID_PHB_MAIN,
            CUI_MENU_TYPE_APPSUB,
            MENU_ID_PHB_SPEAK_NAME,
            0,
            NULL);

#endif
    }
    else
    {
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_set_speak_name
 * DESCRIPTION
 *  save speak name on/off to nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_set_speak_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
#ifndef __MMI_MAINLCD_96X64__
#ifndef LOW_COST_SUPPORT
    mmi_phb_setting_screen_cntx_struct * sg_setting_cntx = 
        (mmi_phb_setting_screen_cntx_struct *)mmi_frm_group_get_user_data(GRP_ID_PHB_SETTING);
#endif
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_VCARD_VERSION_SET_REQ);

    if (g_phb_setting_cntx.speak_name != sg_setting_cntx->temp_speak_name)
    {
        g_phb_setting_cntx.speak_name = sg_setting_cntx->temp_speak_name;
        WriteValue(NVRAM_PHB_SPEAK_NAME_ON_OFF, &g_phb_setting_cntx.speak_name, DS_BYTE, &error);
    }
#ifndef __MMI_MAINLCD_96X64__
    mmi_popup_display_simple_ext(
        STR_GLOBAL_DONE,
        MMI_EVENT_SUCCESS,
        GRP_ID_PHB_SETTING,
        0);
#else
     mmi_popup_display_simple_ext(
        STR_GLOBAL_DONE,
        MMI_EVENT_SUCCESS,
        GRP_ID_PHB_MAIN,
        0);

#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_speak_name
 * DESCRIPTION
 *  get speak name
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U8 mmi_phb_get_speak_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_phb_setting_cntx.speak_name;
}
#endif /* __MMI_INTELLIGENT_CALL_ALERT__ */

#ifndef __MMI_MAINLCD_96X64__
#ifndef __MMI_PHB_SLIM_NO_PREFERRED_STORAGE__

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_speak_name_menu_cui_proc
 * DESCRIPTION
 *  screen group setting agent callback function
 * PARAMETERS
 *  evt        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_phb_prefer_storage_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    MMI_ID sender_id = menu_evt->sender_id;
    MMI_MENU_ID highlighted_menu_id = menu_evt->highlighted_menu_id;
    mmi_ret result = MMI_RET_OK;
    U16 prefer_storage = srv_phb_get_storage_mask();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            if (menu_evt->parent_menu_id == MENU_ID_PHB_PREFERRED_STORAGE)
            {
                MMI_BOOL is_menu_max_exist = MMI_FALSE;
            #if (MMI_MAX_SIM_NUM >= 2)
                S32 count;
            #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                U16 string_id;
            #endif
            #endif

                cui_menu_set_currlist_flags(sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
            #if (MMI_MAX_SIM_NUM >= 2)
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_PREFERRED_ALL, MMI_TRUE);
                for (count = 0; count < MMI_MAX_SIM_NUM; count++)
                {
                #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                    string_id = mmi_phb_sim_dynamic_name_string_index((sim_interface_enum)count);
                    if (mmi_phb_sim_ctrl_not_available_hide_menu(MMI_SIM1 << count, sender_id, MENU_ID_PHB_PREFERRED_SIM + count, string_id))
                #else
                    if (mmi_phb_sim_ctrl_not_available_hide_menu(MMI_SIM1 << count, sender_id, MENU_ID_PHB_PREFERRED_SIM + count, 0))
                #endif
                    {
                        cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_PREFERRED_ALL, MMI_FALSE);
                        is_menu_max_exist = MMI_TRUE;
                    }
                }
            #else /* (MMI_MAX_SIM_NUM >= 2) */
                is_menu_max_exist = mmi_phb_sim_ctrl_not_available_hide_menu(MMI_SIM1, sender_id, MENU_ID_PHB_PREFERRED_SIM, STR_GLOBAL_SIM_1);
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_PREFERRED_ALL, (MMI_BOOL)!is_menu_max_exist);
            #endif /* (MMI_MAX_SIM_NUM >= 2) */

            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                if (srv_fmgr_drv_is_accessible(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE)))
                {
                    cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_PREFERRED_MEMORY_CARD, MMI_FALSE);    
                    if(!is_menu_max_exist)
                    {
                        cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_PREFERRED_ALL, MMI_FALSE);
                        is_menu_max_exist = MMI_TRUE;
                    }
                }
                else
                {
                    cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_PREFERRED_MEMORY_CARD, MMI_TRUE);    
                }
            #endif
            
                mmi_phb_get_preferred_storage();
            
                cui_menu_set_radio_list_item(sender_id, MENU_ID_PHB_PREFERRED_PHONE);

                if ((prefer_storage == PHB_STORAGE_SIM) && srv_sim_ctrl_is_available(MMI_SIM1))
                {
                    cui_menu_set_radio_list_item(sender_id, MENU_ID_PHB_PREFERRED_SIM);
                }

            #if (MMI_MAX_SIM_NUM >= 2)
                for (count = 0; count < MMI_MAX_SIM_NUM - 1; count++)
                {
                    if (prefer_storage == PHB_STORAGE_SIM2 + count && srv_sim_ctrl_is_available(MMI_SIM2 << count))
                    {
                        cui_menu_set_radio_list_item(sender_id, MENU_ID_PHB_PREFERRED_SIM2 + count);
                    }
                }
            #endif /* (MMI_MAX_SIM_NUM >= 2) */

                if (prefer_storage == PHB_STORAGE_MAX && 
                    is_menu_max_exist)
                {
                    cui_menu_set_radio_list_item(sender_id, MENU_ID_PHB_PREFERRED_ALL);
                }

            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                if (prefer_storage == PHB_STORAGE_TCARD)
                {
                    cui_menu_set_radio_list_item(sender_id, MENU_ID_PHB_PREFERRED_MEMORY_CARD); 
                }
            #endif
            }
            else
            {
                result = MMI_RET_DONT_CARE;
            }
            break;
        }

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            if (highlighted_menu_id >= MENU_ID_PHB_PREFERRED_SIM && 
                highlighted_menu_id <= MENU_ID_PHB_PREFERRED_PHONE)
            {
                mmi_phb_set_preferred_storage();
                cui_menu_close(sender_id);
            }
            else
            {
                result = MMI_RET_DONT_CARE;
            }
            break;
        }

        case EVT_ID_CUI_MENU_ITEM_HILITE:
        {
            phb_storage_enum temp_value = PHB_STORAGE_NVRAM;
        #ifndef LOW_COST_SUPPORT
            mmi_phb_setting_screen_cntx_struct *sg_setting_cntx = 
                (mmi_phb_setting_screen_cntx_struct *)mmi_frm_group_get_user_data(GRP_ID_PHB_SETTING);
        #endif

            switch(highlighted_menu_id)
            {
                case MENU_ID_PHB_PREFERRED_SIM:
                    temp_value = PHB_STORAGE_SIM;
                    break;

            #if (MMI_MAX_SIM_NUM >= 2)
                case MENU_ID_PHB_PREFERRED_SIM2:
                    temp_value = PHB_STORAGE_SIM2;
                    break;
            #endif

            #if (MMI_MAX_SIM_NUM >= 3)
                case MENU_ID_PHB_PREFERRED_SIM3:
                    temp_value = PHB_STORAGE_SIM3;
                    break;
            #endif

            #if (MMI_MAX_SIM_NUM >= 4)
                case MENU_ID_PHB_PREFERRED_SIM4:
                    temp_value = PHB_STORAGE_SIM4;
                    break;
            #endif

                case MENU_ID_PHB_PREFERRED_ALL:
                    temp_value = PHB_STORAGE_MAX;
                    break;

            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                case MENU_ID_PHB_PREFERRED_MEMORY_CARD:
                    temp_value = PHB_STORAGE_TCARD;
                    break;
            #endif

                default:
                    break;
            }
            sg_setting_cntx->temp_prefer_storage = temp_value;
            break;
        }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(sender_id);
            break;
        }

        default:
            result = MMI_RET_DONT_CARE;
            break;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_preferred_storage
 * DESCRIPTION
 *  entry prefer storage screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_preferred_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_ENTRY_NAME_LIST_FILTER);

    mmi_phb_entry_menu_cui_generic_ext(
        GRP_ID_PHB_SETTING,
        CUI_MENU_TYPE_APPSUB,
        MENU_ID_PHB_PREFERRED_STORAGE,
        0,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_set_preferred_storage
 * DESCRIPTION
 *  save prefer storage to nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_set_preferred_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef LOW_COST_SUPPORT
    mmi_phb_setting_screen_cntx_struct * sg_setting_cntx = 
        (mmi_phb_setting_screen_cntx_struct *)mmi_frm_group_get_user_data(GRP_ID_PHB_SETTING);
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_NLF_SET_REQ);

    if (g_phb_setting_cntx.prefer_storage != sg_setting_cntx->temp_prefer_storage)
    {
        g_phb_setting_cntx.prefer_storage = sg_setting_cntx->temp_prefer_storage;
        srv_phb_set_storage_mask(g_phb_setting_cntx.prefer_storage);
    }

    mmi_popup_display_simple_ext(
        STR_GLOBAL_DONE,
        MMI_EVENT_SUCCESS,
        GRP_ID_PHB_SETTING,
        NULL);
}
#endif


#else


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_preferred_storage
 * DESCRIPTION
 *  entry prefer storage screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_preferred_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_ENTRY_NAME_LIST_FILTER);


		mmi_phb_entry_menu_cui_generic_ext(
				GRP_ID_PHB_MAIN,
				CUI_MENU_TYPE_APPSUB,
				MENU_ID_PHB_PREFERRED_STORAGE,
				0,
				NULL);


	
		




}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_set_preferred_storage
 * DESCRIPTION
 *  save prefer storage to nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_set_preferred_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/



    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_NLF_SET_REQ);

    if (g_phb_setting_cntx.prefer_storage != sg_setting_cntx->temp_prefer_storage)
    {
        g_phb_setting_cntx.prefer_storage = sg_setting_cntx->temp_prefer_storage;
        srv_phb_set_storage_mask(g_phb_setting_cntx.prefer_storage);
    }

	mmi_popup_display_simple_ext(
        STR_GLOBAL_DONE,
        MMI_EVENT_SUCCESS,
        GRP_ID_PHB_MAIN,
        NULL);


}

#endif
#ifndef __MMI_PHB_SLIM_NEW__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_preferred_storage
 * DESCRIPTION
 *  get prefer storage
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_phb_get_preferred_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_setting_cntx.prefer_storage = srv_phb_get_storage_mask();   
    return g_phb_setting_cntx.prefer_storage;
}
#endif


#if defined(__MMI_PHB_LAST_NAME_FIELD__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_name_display
 * DESCRIPTION
 *  entry name display screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_name_display(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_menu_cui_generic_ext(
        sg_id,
        CUI_MENU_TYPE_APPSUB,
        MENU_ID_PHB_NAME_DISPLAY,
        0,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_set_name_display_hint
 * DESCRIPTION
 *  entry name display screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_set_name_display_hint(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(srv_phb_get_name_display_type())
    {
        case SRV_PHB_NAME_DISPLAY_TYPE_2:
            str_id = STR_ID_PHB_NAME_DISPLAY_TYPE_2;
            break;
        case SRV_PHB_NAME_DISPLAY_TYPE_3:
            str_id = STR_ID_PHB_NAME_DISPLAY_TYPE_3;
            break;
        case SRV_PHB_NAME_DISPLAY_TYPE_4:
            str_id = STR_ID_PHB_NAME_DISPLAY_TYPE_4;
            break;
        case SRV_PHB_NAME_DISPLAY_TYPE_1:
        default:
            str_id = STR_ID_PHB_NAME_DISPLAY_TYPE_1;
            break;
    }
    cui_menu_set_item_hint(sg_id, MENU_ID_PHB_NAME_DISPLAY, get_string(str_id));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_set_name_display_done
 * DESCRIPTION
 *  save name display to nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_set_name_display_done(void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_startup_set_phb_status(MMI_TRUE);

    mmi_phb_popup_display_ext(
        STR_GLOBAL_DONE,
        MMI_EVENT_SUCCESS);
#ifndef __MMI_MAINLCD_96X64__
    mmi_frm_scrn_close(GRP_ID_PHB_SETTING, SCR_IN_PROGRESS_PHB);
#else
    mmi_frm_scrn_close(GRP_ID_PHB_MAIN, SCR_IN_PROGRESS_PHB);

#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_set_name_display
 * DESCRIPTION
 *  save name display to nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_set_name_display(mmi_id sg_id, srv_phb_name_display_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_NLF_SET_REQ);

    if (srv_phb_set_name_display_type(type, mmi_phb_set_name_display_done, NULL))
    {
        mmi_phb_popup_display_ext(
            STR_GLOBAL_DONE,
            MMI_EVENT_SUCCESS);
    }
    else
    {
        srv_phb_startup_set_phb_status(MMI_FALSE);
        mmi_phb_show_in_progress(sg_id, STR_GLOBAL_PLEASE_WAIT);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_name_display_menu_cui_proc
 * DESCRIPTION
 *  screen group setting agent callback function
 * PARAMETERS
 *  evt        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __MMI_MAINLCD_96X64__
static void mmi_phb_name_display_menu_cui_proc(mmi_event_struct *evt)
#else
void mmi_phb_name_display_menu_cui_proc(mmi_event_struct *evt)
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    MMI_ID sender_id = menu_evt->sender_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            if (menu_evt->parent_menu_id == MENU_ID_PHB_NAME_DISPLAY)
            {
                cui_menu_set_currlist_flags(sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);

                switch(srv_phb_get_name_display_type())
                {
                    case SRV_PHB_NAME_DISPLAY_TYPE_2:
                        cui_menu_set_radio_list_item(sender_id, MENU_ID_PHB_NAME_DISPLAY_TYPE_2);
                        break;

                    case SRV_PHB_NAME_DISPLAY_TYPE_3:
                        cui_menu_set_radio_list_item(sender_id, MENU_ID_PHB_NAME_DISPLAY_TYPE_3);
                        break;

                    case SRV_PHB_NAME_DISPLAY_TYPE_4:
                        cui_menu_set_radio_list_item(sender_id, MENU_ID_PHB_NAME_DISPLAY_TYPE_4);
                        break;

                    case SRV_PHB_NAME_DISPLAY_TYPE_1:
                    default:
                        cui_menu_set_radio_list_item(sender_id, MENU_ID_PHB_NAME_DISPLAY_TYPE_1);
                        break;
                }
            }
            break;
        }

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            switch(menu_evt->highlighted_menu_id)
            {
#ifndef __MMI_MAINLCD_96X64__
                case MENU_ID_PHB_NAME_DISPLAY_TYPE_1:
                    mmi_phb_set_name_display(GRP_ID_PHB_SETTING, SRV_PHB_NAME_DISPLAY_TYPE_1);
                    break;

                case MENU_ID_PHB_NAME_DISPLAY_TYPE_2:
                    mmi_phb_set_name_display(GRP_ID_PHB_SETTING, SRV_PHB_NAME_DISPLAY_TYPE_2);
                    break;

                case MENU_ID_PHB_NAME_DISPLAY_TYPE_3:
                    mmi_phb_set_name_display(GRP_ID_PHB_SETTING, SRV_PHB_NAME_DISPLAY_TYPE_3);
                    break;

                case MENU_ID_PHB_NAME_DISPLAY_TYPE_4:
                    mmi_phb_set_name_display(GRP_ID_PHB_SETTING, SRV_PHB_NAME_DISPLAY_TYPE_4);
                    break;
#else
	        case MENU_ID_PHB_NAME_DISPLAY_TYPE_1:
                    mmi_phb_set_name_display(GRP_ID_PHB_MAIN, SRV_PHB_NAME_DISPLAY_TYPE_1);
                    break;

                case MENU_ID_PHB_NAME_DISPLAY_TYPE_2:
                    mmi_phb_set_name_display(GRP_ID_PHB_MAIN, SRV_PHB_NAME_DISPLAY_TYPE_2);
                    break;

                case MENU_ID_PHB_NAME_DISPLAY_TYPE_3:
                    mmi_phb_set_name_display(GRP_ID_PHB_MAIN, SRV_PHB_NAME_DISPLAY_TYPE_3);
                    break;

                case MENU_ID_PHB_NAME_DISPLAY_TYPE_4:
                    mmi_phb_set_name_display(GRP_ID_PHB_MAIN, SRV_PHB_NAME_DISPLAY_TYPE_4);
                    break;
#endif

                default:
                    return;
            }
            cui_menu_close(sender_id);
            break;
        }
    }
}

#endif /* defined(__MMI_PHB_LAST_NAME_FIELD__) */

#if defined(__MMI_MULTI_VCARD__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_backup_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_backup_contact(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sg_id;
    srv_phb_filter_struct filter;
#ifndef __MMI_MAINLCD_96X64__ 
#ifndef LOW_COST_SUPPORT
    mmi_phb_setting_screen_cntx_struct *sg_setting_cntx = 
                (mmi_phb_setting_screen_cntx_struct *)mmi_frm_group_get_user_data(GRP_ID_PHB_SETTING);
#endif
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_check_storage_status(PHB_STORAGE_MAX, MMI_PHB_CHECK_STORAGE_EMPTY, MMI_FALSE))
    {
        mmi_phb_popup_display_ext(STR_ID_PHB_CLOUD_NO_BACKUP, MMI_EVENT_FAILURE);
        return;
    }

#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*)L"root"))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */
    memset(&filter, 0, sizeof(srv_phb_filter_struct));
    filter.storage = PHB_STORAGE_MAX;
    filter.field_filter = SRV_PHB_ENTRY_FIELD_ALL;

    if (sg_setting_cntx->contact_array == NULL)
    {
        sg_setting_cntx->contact_array = mmi_phb_mem_malloc(MMI_PHB_ENTRIES * sizeof(U16), SRV_PHB_MEMORY_TYPE_ADM);
    }
    sg_setting_cntx->contact_count =
        srv_phb_oplib_build_contact_list(&filter, sg_setting_cntx->contact_array, MMI_PHB_ENTRIES);

    sg_id = cui_vcard_export_vcard_creat(group_id);
    cui_vcard_export_vcard_set_contact_list(sg_id, sg_setting_cntx->contact_array, sg_setting_cntx->contact_count);
    cui_vcard_export_vcard_run(sg_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_restore_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_restore_contact(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sg_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_vcard_check_tcard_file())
    {
        mmi_phb_popup_display_ext(STR_ID_PHB_CLOUD_NO_RESTORE, MMI_EVENT_FAILURE);
        return;
    }
    
    if (mmi_phb_check_storage_status(PHB_STORAGE_NVRAM, MMI_PHB_CHECK_STORAGE_FULL, MMI_TRUE))
    {
        return;
    }

#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*)L"root"))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */

    sg_id = cui_vcard_import_vcard_creat(group_id);
    cui_vcard_import_vcard_run(sg_id);
}
#endif /* defined(__MMI_MULTI_VCARD__) */

#endif /* _PHONEBOOKSETTINGS_C */ 

#else /* __MMI_LOCAL_PHB_SUPPORT__ */

#include "PhoneBookProt.h"


#ifndef __MMI_MAINLCD_96X64__
typedef struct mmi_phb_setting_screen_cntx{
    // change name
    U16 temp_prefer_storage;
#if defined(__MMI_PHB_SAVE_CONTACT_NOTIFY__)
    U16 temp_save_contact_notify;
#endif
#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    U8 temp_speak_name;
#endif /* __MMI_INTELLIGENT_CALL_ALERT__*/
#if defined(__MMI_MULTI_VCARD__)
    U16 *contact_array;                     /* contact list content */
    U16 contact_count;                      /* contact count */
#endif
}mmi_phb_setting_screen_cntx_struct;
#endif


#ifndef __MMI_MAINLCD_96X64__ 
static mmi_phb_setting_cntx_struct g_phb_setting_cntx;
#else
mmi_phb_setting_cntx_struct g_phb_setting_cntx;
#endif


#ifndef __MMI_MAINLCD_96X64__ 
#ifdef LOW_COST_SUPPORT
mmi_phb_setting_screen_cntx_struct *sg_setting_cntx;
#endif
#else
mmi_phb_setting_screen_cntx_struct *sg_setting_cntx;
#endif


U16 mmi_phb_get_preferred_storage(void)
{
    return 0;
}


void mmi_phb_setting_init(void)
{
}


void mmi_phb_sg_entry_setting(MMI_ID group_id)
{
}


#ifndef __MMI_MAINLCD_96X64__
static void mmi_phb_entry_memory_status(void)
#else
void mmi_phb_entry_memory_status(void)
#endif
{
}


void mmi_phb_entry_preferred_storage(void)
{
}


void mmi_phb_set_preferred_storage(void)
{
}

#endif /* __MMI_LOCAL_PHB_SUPPORT__ */

