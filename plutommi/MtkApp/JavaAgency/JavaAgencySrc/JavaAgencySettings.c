/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
* permission of MediaTek Inc. (C) 2005
*
* BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
* THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
* RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
* AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
* NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
* SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
* SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
* THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
* NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
* SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
* BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
* LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
* AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
* OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
* MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
* THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
* WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
* LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
* RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
* THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * JavaAgencySettings.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(__J2ME__)


#include "MMI_features.h"
#include "wgui_inline_edit.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "GlobalConstants.h"
#include "CommonScreensResDef.h"
#include "CommonScreens.h"

#include "JavaAgencyDef.h"
#include "JavaAgencyProt.h"
#include "wapadp.h"
#include "wap_ps_struct.h"
#include "jam_msg_handler.h"
#include "jvm_interface.h"
#include "j2me_custom.h"
#include "j2me_custom_option.h"
#include "j2me_custom_param.h"
#include "j2me_custom.h"
#include "jvm_adaptor.h"
#include "jam_internal.h"
#include "InlineCuiGprot.h"
#include "DataAccountGProt.h"
#include "DataAccountCuiGprot.h"
#include "JavaAgencySettings.h"
#include "FunAndGamesResDef.h"
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
#include "FileMgrSrvGProt.h"
#endif

extern java_context_struct g_java;

MMI_BOOL get_setting_only = MMI_FALSE;
MMI_BOOL get_domain_setting = MMI_FALSE;

#if defined(__PLUTO_MMI_PACKAGE__)
mmi_java_global_setting_and_security_cntx_struct g_java_setting_and_security_cntx;
mmi_id g_java_setting_inline = CUI_INLINE_INVALID_ID;
mmi_id g_java_security_inline = CUI_INLINE_INVALID_ID;
mmi_id g_java_domain_inline = CUI_INLINE_INVALID_ID;
mmi_id g_java_opt_setting_inline;

U16 g_mmi_java_current_selected_domain[30];

void mmi_java_global_setting_entry_screen_internal(void);
#ifdef OGDR_SECURITY_SETTING
void mmi_java_global_security_entry_screen_internal(void);
void mmi_java_global_security_change_domain_status_entry_screen_int(void);
#endif

extern void create_default_nw_setting(void);
extern void cui_inline_register_lsk_handler(void);    
extern void cui_inline_register_rsk_handler(void);   
extern S32 mmi_java_get_perm_menu_item_count(S8 max_level);  

/*****************************************************************************
 * FUNCTION
 *  mmi_java_global_setting_java_done_hdlr
 * DESCRIPTION
 *  done hdlr for java setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_global_setting_java_done_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    //g_mmi_java_aud_volume_level = g_java_setting_and_security_cntx.setting_inline.java_aud_selected;
    cui_inline_get_value(g_java_setting_inline, JAVA_AUDIO_SELECT , (void*)&g_mmi_java_aud_volume_level);
    //g_mmi_java_is_vib_on = g_java_setting_and_security_cntx.setting_inline.java_vib_selected;
    cui_inline_get_value(g_java_setting_inline, JAVA_BKLIGHT_SELECT,(void*)&g_mmi_java_bk_light);
    cui_inline_get_value(g_java_setting_inline, JAVA_VIB_SELECT,(void *)&g_mmi_java_is_vib_on);
#ifdef SUPPORT_JAVA_NET_ICON_SETTING
/* under construction !*/
#endif
#ifdef __MMI_FOURWAYS_KEY_DISABLE__
    cui_inline_get_value(g_java_setting_inline, JAVA_VK_SELECT,(void *)&g_mmi_java_vk_permission);
#endif

    mmi_java_store_setting();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_global_setting_highlight_item
 * DESCRIPTION
 *  highlight hdlr
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_global_setting_highlight_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_java_global_setting_java_done_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_global_setting_exit_screen_hdlr
 * DESCRIPTION
 *  exit point for java setting screen
 * PARAMETERS
 *  void
 *  viud(?)     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_global_setting_exit_screen_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   // U16 inputBufferSize;
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = SCR_ID_FNG_SETTING_JAVA;
    CloseCategory57Screen();
    h.entryFuncPtr = mmi_java_global_setting_entry_screen_internal;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategory57History(h.guiBuffer);
    //inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_global_terminate_callback
 * DESCRIPTION
 *  Callback function to handle
 *  Ask user if they want to terminate VM first before install MIDlet
 * PARAMETERS
 *  teminate    [IN]    user select yes/No
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_global_terminate_callback(MMI_BOOL terminate)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 vm_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(terminate)
    {
        jam_enter_terminate_mode(vm_id);
        mmi_java_entry_terminating(MMI_FALSE);
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_java_global_setting_entry_screen
 * DESCRIPTION
 *  entry point for java setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_global_setting_entry_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
    if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        mmi_popup_display_simple_ext(STR_JAVA_ERROR_CODE_NO_CARD, MMI_EVENT_WARNING, GRP_ID_ROOT, NULL);
        return;
    }
#endif
#if(MAX_VM_INSTANCE_NUM == 1)
#if defined(J2ME_SUPPORT_PAUSE)
        if (jam_mvm_is_pause_mode(0) || jam_mvm_is_minimize_mode(0))
    {
        g_mmi_java_current_selected_vm_id = 0;
        mmi_java_entry_cb_terminate_dialog(mmi_java_global_terminate_callback, (U16*)GetString(STR_JAVA_TERMINATE_JAVA_GAME),0);
        return;
    }
#elif defined(J2ME_SUPPORT_BACKGROUND)
	if(jam_mvm_is_vm_support_bg(0))
	{
    	if (jam_mvm_is_pause_mode(0) || jam_mvm_is_minimize_mode(0))
        {
        	g_mmi_java_current_selected_vm_id = 0;
        	mmi_java_entry_cb_terminate_dialog(mmi_java_global_terminate_callback, (U16*)GetString(STR_JAVA_TERMINATE_JAVA_GAME),0);
        	return;
        }
	}
#endif
    if (jam_vm_is_busy())
    {
        mmi_java_display_is_busy();
        return;
    }        
#endif /*MAX_VM_INSTANCE_NUM == 1*/
    if(jam_is_busy())
    {
        mmi_java_display_is_busy();
        return;
    }

    if (!jam_nw_is_default_network_setting_exist())
    {
        create_default_nw_setting();
    }
	
    ClearInputEventHandler(MMI_DEVICE_ALL);

    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_JAVA_SETTING, mmi_java_setting_and_security_sg_proc, NULL);
    mmi_frm_group_enter(GRP_ID_JAVA_SETTING, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_java_global_setting_entry_screen_internal();
    mmi_java_nw_get_global_setting();
        return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_global_setting_entry_inline_cui
 * DESCRIPTION
 *  Display java setting screen with inline cui
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_global_setting_entry_inline_cui(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8* account_name;
   // kal_int8 i;
    /*------------Java Audio --------------*/
    #define MAX_VOLUME      8
const static cui_inline_item_caption_struct caption_java_audio =
{
    STR_ID_FNG_SETTING_JAVA_AUD
};
U16* java_audio_select_string[MAX_VOLUME];

static cui_inline_item_select_struct java_audio_select ; 

 /*-----------Java Bakgroud light-----------*/
 const static cui_inline_item_caption_struct caption_java_bklight =
    {
    STR_ID_FNG_SETTING_JAVA_BKLIGHT
};
U16 * java_on_off_select_string[2];
 static cui_inline_item_select_struct java_bklight_select ;

  /*------------ Java vibrate -------------*/
   const static cui_inline_item_caption_struct caption_java_vib =
    {
      STR_ID_FNG_SETTING_JAVA_VIB
  };
   static cui_inline_item_select_struct java_vib_select ;
   
 /*------------Java net icon --------------*/
    #ifdef SUPPORT_JAVA_NET_ICON_SETTING
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

/*------------Java VK ---------------*/
    #ifdef __MMI_FOURWAYS_KEY_DISABLE__
 const static cui_inline_item_caption_struct caption_java_vk =
 {
     STR_ID_FNG_SETTING_JAVA_VK
 };
  U16* java_vk_select_string[3];
  static cui_inline_item_select_struct java_vk_select ;
  #endif

/*----------- Java Storage --------------*/
  #ifdef JAVA_SETTING_SHOW_FREE_STORAGE
 const static cui_inline_item_caption_struct caption_storage =
 {
     STR_ID_FNG_SETTING_JAVA_STORAGE
 };
 const static cui_inline_item_display_only_struct java_storage =
 {
     STR_ID_FNG_SETTING_JAVA_STORAGE
 };
    #endif

 /*-----------Java Heap size --------------*/
 const static cui_inline_item_caption_struct caption_javaheap =
 {
     STR_ID_FNG_SETTING_JAVA_HEAP
 };
 const static cui_inline_item_display_only_struct java_heap_size =
 {
     STR_ID_FNG_SETTING_JAVA_HEAP
 };
static cui_inline_item_caption_struct caption_java_network = {STR_ID_JAVA_NETWORK};
static cui_inline_item_display_only_struct item_account_name = {STR_ID_JAVA_NETWORK};

 /*================================*/
static cui_inline_item_softkey_struct java_inline_sofkey = {
                              { {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0}, 
                                {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
                                {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, CUI_INLINE_SOFTKEY_DEFAULT_VALUE} }
                                                                                              }; 
static const cui_inline_set_item_struct java_setting_item[ ] = 
{
    {JAVA_AUDIO_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_FNG_SETTING_JAVA_AUD, (void *)&caption_java_audio},
    {JAVA_AUDIO_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void *)&java_audio_select},
    {JAVA_BKLIGHT_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_FNG_SETTING_JAVA_BKLIGHT, (void *)&caption_java_bklight},
    {JAVA_BKLIGHT_SELECT, CUI_INLINE_ITEM_TYPE_SELECT,0,(void *)&java_bklight_select},
    {JAVA_VIB_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_FNG_SETTING_JAVA_VIB,(void *)&caption_java_vib},
    {JAVA_VIB_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void *)&java_vib_select},
#ifdef SUPPORT_JAVA_NET_ICON_SETTING
/* under construction !*/
/* under construction !*/
    #endif
#ifdef __MMI_FOURWAYS_KEY_DISABLE__
    {JAVA_VK_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_FNG_SETTING_JAVA_VK, (void *)&caption_java_vk},
    {JAVA_VK_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void *)&java_vk_select},
#endif
    {JAVA_NETWORK_SETTING_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_FNG_SETTING_JAVA_NET_ICON, (void *)&caption_java_network},
    {JAVA_NETWORK_SETTING, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, (void *)&item_account_name},
    #ifdef JAVA_SETTING_SHOW_FREE_STORAGE
    {JAVA_STORAGE_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_FNG_SETTING_JAVA_STORAGE, &caption_storage},
    {JAVA_STORAGE_SIZE, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, (void *)&java_storage},
    #endif
    {JAVA_HEAP_SIZE_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION , IMG_ID_FNG_SETTING_JAVA_HEAP, (void *)&caption_javaheap},
    {JAVA_HEAP_SIZE, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW, 0, (void *)&java_heap_size}
};

const cui_inline_struct java_setting_inline_screen = 
{
    MMI_JAVA_SETTING_TOTAL*2,
        0,
    0,
    CUI_INLINE_SCREEN_LOOP,
    &java_inline_sofkey,
    java_setting_item
    };
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        
        g_java_setting_inline = cui_inline_create(GRP_ID_JAVA_SETTING,&java_setting_inline_screen);

        java_audio_select_string[0] = (U16*)GetString(STR_GLOBAL_OFF);
        java_audio_select_string[1] = (U16*)GetString(STR_GLOBAL_1);  
        java_audio_select_string[2] = (U16*)GetString(STR_GLOBAL_2);
        java_audio_select_string[3] = (U16*)GetString(STR_GLOBAL_3);
        java_audio_select_string[4] = (U16*)GetString(STR_GLOBAL_4);
        java_audio_select_string[5] = (U16*)GetString(STR_GLOBAL_5);
        java_audio_select_string[6] = (U16*)GetString(STR_GLOBAL_6);
        java_audio_select_string[7] = (U16*)GetString(STR_GLOBAL_7);
        cui_inline_set_item_select(g_java_setting_inline,JAVA_AUDIO_SELECT,8,(PU8 *)&java_audio_select_string,g_mmi_java_aud_volume_level);
        
        java_on_off_select_string[0] = (U16*)GetString(STR_GLOBAL_OFF);
        java_on_off_select_string[1] = (U16*)GetString(STR_GLOBAL_ON);
        cui_inline_set_item_select(g_java_setting_inline, JAVA_BKLIGHT_SELECT,2,(PU8 *) java_on_off_select_string, g_mmi_java_bk_light);
        cui_inline_set_item_select(g_java_setting_inline,JAVA_VIB_SELECT,2,(PU8 *)java_on_off_select_string,g_mmi_java_is_vib_on);
   #ifdef SUPPORT_JAVA_NET_ICON_SETTING
/* under construction !*/
    #endif
   #ifdef __MMI_FOURWAYS_KEY_DISABLE__
         java_vk_select_string[0] = (U16*)GetString(STR_JAVA_PERM_BLANKET); 
         java_vk_select_string[1] = (U16*)GetString(STR_JAVA_PERM_ONESHOT); 
         java_vk_select_string[2] = (U16*)GetString(STR_JAVA_PERM_USERDENY);
        cui_inline_set_item_select(g_java_setting_inline,JAVA_VK_SELECT,3,(PU8 *)java_vk_select_string,g_mmi_java_vk_permission);
#endif
        if (mmi_java_nw_is_need_hide())
        {
            cui_inline_delete_item(g_java_setting_inline, JAVA_NETWORK_SETTING_CAPTION);
            cui_inline_delete_item(g_java_setting_inline, JAVA_NETWORK_SETTING);
        }
        else
        {
            account_name = mmi_java_nw_get_account_name();
            cui_inline_set_value(g_java_setting_inline, JAVA_NETWORK_SETTING, (UI_string_type) account_name);
            cui_inline_set_softkey_text(g_java_setting_inline, JAVA_NETWORK_SETTING, MMI_LEFT_SOFTKEY, STR_GLOBAL_SELECT);
            cui_inline_set_softkey_icon(g_java_setting_inline, JAVA_NETWORK_SETTING, MMI_CENTER_SOFTKEY, IMG_GLOBAL_COMMON_CSK);
        }
        
    #ifdef JAVA_SETTING_SHOW_FREE_STORAGE
        cui_inline_set_value(g_java_setting_inline, JAVA_STORAGE_SIZE, (void*)g_java_setting_and_security_cntx.setting_inline.java_storage_str[0]);
        cui_inline_set_softkey_text(g_java_setting_inline, JAVA_STORAGE_SIZE, MMI_LEFT_SOFTKEY, NULL);
        
    #endif
        cui_inline_set_value(g_java_setting_inline, JAVA_HEAP_SIZE, (void*)g_java_setting_and_security_cntx.setting_inline.java_heap_str[0]);
         
        cui_inline_set_title(g_java_setting_inline, STR_ID_FNG_SETTING_JAVA, mmi_java_get_title_icon()); 

        cui_inline_register_lsk_handler();
        cui_inline_register_rsk_handler();
        
        cui_inline_run(g_java_setting_inline);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_global_setting_get_nw_inline_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_java_global_setting_get_nw_inline_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return JAVA_NETWORK_SETTING;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_global_setting_entry_screen_internal
 * DESCRIPTION
 *  real entry point for java setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_global_setting_entry_screen_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 javaTempString[2][MAX_MEMORY_SIZE];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_java_store_setting();
    mmi_java_load_setting();

   /*****************************************************************************
   * JAVA
   *****************************************************************************/
    /* JAVA TODO: Set value here */

    g_java_setting_and_security_cntx.setting_inline.java_aud_selected = g_mmi_java_aud_volume_level;
    g_java_setting_and_security_cntx.setting_inline.java_vib_selected = g_mmi_java_is_vib_on;
#ifdef SUPPORT_JAVA_NET_ICON_SETTING
/* under construction !*/
#endif

#ifdef __MMI_FOURWAYS_KEY_DISABLE__
    g_java_setting_and_security_cntx.setting_inline.java_vk_permission_selected = g_mmi_java_vk_permission;
#endif

#ifdef JAVA_SETTING_SHOW_FREE_STORAGE
    g_java_setting_and_security_cntx.setting_inline.java_storage_selected = 0;
#endif
    g_java_setting_and_security_cntx.setting_inline.java_heap_selected = 0;

    g_java_setting_and_security_cntx.setting_inline.java_bklight_selected = g_mmi_java_bk_light;

    g_java_setting_and_security_cntx.setting_inline.java_aud_str[0] = (UI_string_type) GetString((U16) (STR_GLOBAL_OFF));
    g_java_setting_and_security_cntx.setting_inline.java_aud_str[1] = (UI_string_type) L"1";
    g_java_setting_and_security_cntx.setting_inline.java_aud_str[2] = (UI_string_type) L"2";
    g_java_setting_and_security_cntx.setting_inline.java_aud_str[3] = (UI_string_type) L"3";
    g_java_setting_and_security_cntx.setting_inline.java_aud_str[4] = (UI_string_type) L"4";
    g_java_setting_and_security_cntx.setting_inline.java_aud_str[5] = (UI_string_type) L"5";
    g_java_setting_and_security_cntx.setting_inline.java_aud_str[6] = (UI_string_type) L"6";
    g_java_setting_and_security_cntx.setting_inline.java_aud_str[7] = (UI_string_type) L"7";

    g_java_setting_and_security_cntx.setting_inline.java_vib_str[0] = (UI_string_type) GetString((U16) (STR_GLOBAL_OFF));
    g_java_setting_and_security_cntx.setting_inline.java_vib_str[1] = (UI_string_type) GetString((U16) (STR_GLOBAL_ON));

#ifdef SUPPORT_JAVA_NET_ICON_SETTING
/* under construction !*/
/* under construction !*/
#endif

#ifdef __MMI_FOURWAYS_KEY_DISABLE__
    g_java_setting_and_security_cntx.setting_inline.java_vk_permission_str[0] = (UI_string_type) GetString((U16) STR_JAVA_PERM_BLANKET);
    g_java_setting_and_security_cntx.setting_inline.java_vk_permission_str[1] = (UI_string_type) GetString((U16) STR_JAVA_PERM_ONESHOT);
    g_java_setting_and_security_cntx.setting_inline.java_vk_permission_str[2] = (UI_string_type) GetString((U16) STR_JAVA_PERM_USERDENY);
#endif /* __MMI_FOURWAYS_KEY_DISABLE__ */

#ifdef JAVA_SETTING_SHOW_FREE_STORAGE
    memset(javaTempString[0], 0, sizeof(javaTempString[0]));
    sprintf(javaTempString[0], "%u ", get_mids_avail_storage());
    mmi_asc_to_ucs2((S8*) g_java_setting_and_security_cntx.setting_inline.java_storage_strs[0], (S8*) javaTempString[0]);
    mmi_ucs2cat((S8*) g_java_setting_and_security_cntx.setting_inline.java_storage_strs[0], GetString((U16) STR_JAVA_INFO_BYTES));
    g_java_setting_and_security_cntx.setting_inline.java_storage_str[0] = g_java_setting_and_security_cntx.setting_inline.java_storage_strs[0];
#endif

    memset(javaTempString[1], 0, sizeof(javaTempString[1]));
    sprintf(javaTempString[1], "%u ", jvm_get_heap_size());
    mmi_asc_to_ucs2((S8*) g_java_setting_and_security_cntx.setting_inline.java_heap_strs[0], (S8*) javaTempString[1]);
    if(jvm_get_heap_size() >1)
        mmi_ucs2cat((S8*) g_java_setting_and_security_cntx.setting_inline.java_heap_strs[0], GetString((U16) STR_JAVA_INFO_BYTES));
    else
        mmi_ucs2cat((S8*) g_java_setting_and_security_cntx.setting_inline.java_heap_strs[0], GetString((U16) STR_JAVA_INFO_BYTE));
    g_java_setting_and_security_cntx.setting_inline.java_heap_str[0] = g_java_setting_and_security_cntx.setting_inline.java_heap_strs[0];
    g_java_setting_and_security_cntx.setting_inline.java_bklight_str[0] = (UI_string_type) GetString((U16) (STR_GLOBAL_OFF));
    g_java_setting_and_security_cntx.setting_inline.java_bklight_str[1] = (UI_string_type) GetString((U16) (STR_GLOBAL_ON));

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_global_setting_highlight_hdlr
 * DESCRIPTION
 *  highlight java setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_global_setting_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_java_global_setting_entry_screen, KEY_EVENT_UP);
#ifndef __MMI_WGUI_DISABLE_CSK__
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
    SetCenterSoftkeyFunction(mmi_java_global_setting_entry_screen,KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

#ifdef OGDR_SECURITY_SETTING
/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_set_default_setting_cnf
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_set_default_domain_cnf(void *MsgStruct)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_java_set_default_domain_cnf_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg = (mmi_java_set_default_domain_cnf_struct*) MsgStruct;

    if (g_java.msg_ctrl & SEND_SET_DEFAULT_DOMAIN_CTRL )
    {
        if (msg->error_code == J2ME_NO_ERROR)
        {
            //mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_JAVA_SECURITY, NULL);
        }
        else
        {
            mmi_popup_display_simple_ext(STR_GLOBAL_UNFINISHED, MMI_EVENT_FAILURE, GRP_ID_JAVA_SECURITY, NULL);
        }
        /* only get the setting from Java again to update the latest setting value since exclusive setting may automatically
            update other setting value*/
        get_setting_only = MMI_TRUE;
        mmi_java_send_get_default_domain_req(g_java.domain);
        g_java.msg_ctrl &= (~SEND_SET_DEFAULT_DOMAIN_CTRL);
    }
    cui_inline_close(g_java_domain_inline);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_set_default_domain_req
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_set_default_domain_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_set_default_domain_req_struct *msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_java.msg_ctrl & SEND_SET_DEFAULT_DOMAIN_CTRL)
    {
        mmi_java_display_is_busy();
    }
    else
    {
        g_java.msg_ctrl |= SEND_SET_DEFAULT_DOMAIN_CTRL;

        msg = (mmi_java_set_default_domain_req_struct*) OslConstructDataPtr(sizeof(mmi_java_set_default_domain_req_struct));
        msg->domain_id = g_java.domain;
        kal_mem_cpy(&(msg->default_setting), &(g_java.mids_setting), sizeof(mmi_setting_struct));

        mmi_java_send_message_from_active_mod(MOD_JAM, MMI_J2ME_SAP,
            MSG_ID_MMI_JAVA_SET_DEFAULT_DOMAIN_REQ, msg);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_get_default_domain_cnf
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_get_default_domain_cnf(void *MsgStruct)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_java_get_default_domain_cnf_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg = (mmi_java_get_default_domain_cnf_struct *) MsgStruct;


    if (msg->error_code == (kal_uint32) J2ME_NO_ERROR)
    {
        kal_mem_cpy(&(g_java.mids_setting), &(msg->default_setting), sizeof(mmi_setting_struct));
        kal_mem_cpy(&(g_java.mids_max_setting), &(msg->max_setting), sizeof(mmi_setting_struct));
    }

    if (!get_setting_only)
    {
        get_domain_setting = MMI_TRUE;
        mmi_java_local_setting_entry_screen();
    }

    get_setting_only = MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_get_default_domain_req
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_get_default_domain_req(S32 domain)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_get_default_domain_req_struct *msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (mmi_java_get_default_domain_req_struct*) OslConstructDataPtr(sizeof(mmi_java_get_default_domain_req_struct));
    msg->domain_id = domain;
    mmi_java_send_message_from_active_mod(MOD_JAM, MMI_J2ME_SAP,
        MSG_ID_MMI_JAVA_GET_DEFAULT_DOMAIN_REQ, msg);
}


/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
void mmi_java_global_security_reset_default_setting_cnf(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_reset_default_domain_cnf_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg = (mmi_java_reset_default_domain_cnf_struct *) MsgStruct;

    if (msg->error_code != J2ME_NO_ERROR)
    {
        mmi_java_display_is_busy();
        return;
    }
    else
    {
        //mmi_display_popup_with_sg(GRP_ID_JAVA_SECURITY, (UI_string_type)GetString(STR_GLOBAL_DONE),MMI_EVENT_SUCCESS, 0);
        mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_GLOBAL_DONE)), MMI_EVENT_SUCCESS, NULL);
        mmi_frm_scrn_close(GRP_ID_JAVA_SECURITY, SCR_ID_FNG_SECURITY_JAVA);    
        //mmi_frm_group_close(GRP_ID_JAVA_SECURITY);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_global_security_reset_default_setting_req
 * DESCRIPTION
 *  Get Java Domain List
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_global_security_reset_default_setting_req(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_reset_default_domain_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    msg = OslAllocDataPtr(mmi_java_reset_default_domain_req_struct);
    mmi_frm_send_ilm(MOD_JAM,MSG_ID_MMI_JAVA_RESET_DEFAULT_DOMAIN_REQ, (oslParaType * )msg,NULL);
}

/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
void mmi_java_global_security_get_domain_list_cnf(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	S32 i;
    mmi_java_get_domain_list_cnf_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg = (mmi_java_get_domain_list_cnf_struct *) MsgStruct;

    if (msg->error_code != J2ME_NO_ERROR)
    {

        //mmi_display_popup_with_sg(GRP_ID_JAVA_SECURITY,(UI_string_type)GetString(STR_JAVA_ERROR_CODE_UNKNOWN_FAILURE),MMI_EVENT_SUCCESS,0);
        mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_JAVA_ERROR_CODE_UNKNOWN_FAILURE)), MMI_EVENT_FAILURE, NULL);
        return;
    }

   // ASSERT(msg->total_domain < 10 && msg->total_domain > 0);
   // User could disable all domain
   ASSERT(msg->total_domain < 10); 

    g_java_setting_and_security_cntx.total_domain = msg->total_domain;

    for(i = 0 ;i < g_java_setting_and_security_cntx.total_domain ;i ++)
    {
        mmi_ucs2cpy( (S8*) g_java_setting_and_security_cntx.domains[i], (S8*) msg->domains[i] );
    }

    mmi_java_global_security_entry_screen_internal();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_global_security_get_domain_list_req
 * DESCRIPTION
 *  Get Java Domain List
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_global_security_get_domain_list_req(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_get_domain_list_req_struct *msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    msg = OslAllocDataPtr(mmi_java_get_domain_list_req_struct);
    mmi_frm_send_ilm(MOD_JAM,MSG_ID_MMI_JAVA_GET_DOMAIN_LIST_REQ,(oslParaType * )msg,NULL);
}

/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_global_security_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    g_java.domain = g_java_setting_and_security_cntx.domain_selected;

    mmi_java_send_get_default_domain_req(g_java_setting_and_security_cntx.domain_selected);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_global_security_restore_default_confirm_entry_screen
 * DESCRIPTION
 *  entry restore default confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_global_security_restore_default_confirm_entry_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_USER_DEFINE);
    arg.softkey[0].str = (WCHAR *)((UI_string_type)get_string(STR_GLOBAL_YES));
    arg.softkey[2].str = (WCHAR *)((UI_string_type)get_string(STR_GLOBAL_NO));
    arg.callback = (mmi_proc_func)NULL;
    arg.parent_id = GRP_ID_JAVA_SECURITY;
    mmi_confirm_display((WCHAR *)((UI_string_type)get_string(STR_ID_FNG_SECURITY_JAVA_RESTORE_DEFAULT_CONFIRM)), MMI_EVENT_QUERY, &arg);

    SetProtocolEventHandler(mmi_java_global_security_reset_default_setting_cnf, MSG_ID_MMI_JAVA_RESET_DEFAULT_DOMAIN_CNF);
    SetCenterSoftkeyFunction(mmi_java_global_security_reset_default_setting_req, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_java_global_security_reset_default_setting_req, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_global_security_change_domain_status_cnf
 * DESCRIPTION
 *  entry restore default confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_global_security_change_domain_status_cnf(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* do nothing */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_global_security_popup_proc
 * DESCRIPTION
 *  exit function of domain status screen
 * PARAMETERS
 *  void  
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_java_global_security_popup_proc(mmi_event_struct *evt)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    switch(evt->evt_id)
    {
        case EVT_ID_POPUP_QUIT:
            mmi_frm_group_close(GRP_ID_JAVA_SECURITY);
            break;
            default:
                break;
    }
       return MMI_RET_OK;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_java_global_security_change_domain_status_done_hdlr
 * DESCRIPTION
 *  Process the user on/off result of domain status screen, and send msg to Java to store current setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_global_security_change_domain_status_done_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_change_domain_req_struct *req_msg;
    U16 i,j;
    mmi_popup_property_struct arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_CHANGE_DOMAIN_STATUS_DONE_HDLR); 
    for(i=1,j=0; i <= g_java_setting_and_security_cntx.real_total_domain * 2; j++)
    {
        cui_inline_get_value(g_java_security_inline,CUI_INLINE_ITEM_ID_BASE+i,(void *)&g_java_setting_and_security_cntx.domain_status[j]);
        i+=2;
    }
    req_msg = OslAllocDataPtr(mmi_java_change_domain_req_struct);    
    req_msg->total_domain = g_java_setting_and_security_cntx.real_total_domain;

    /* get all status of domain */
    for(i = 0; i < req_msg->total_domain ; i++)
    {
        req_msg->status[i] = (kal_bool)g_java_setting_and_security_cntx.domain_status[i];
    }
    
    SetProtocolEventHandler(mmi_java_global_security_change_domain_status_cnf, MSG_ID_MMI_JAVA_SET_DOMAIN_STATUS_CNF);

    mmi_frm_send_ilm(MOD_JAM,MSG_ID_MMI_JAVA_SET_DOMAIN_STATUS_REQ,(oslParaType * )req_msg,NULL);
    mmi_popup_property_init(&arg);
    arg.parent_id = GRP_ID_JAVA_SECURITY;
    arg.callback = mmi_java_global_security_popup_proc;
    arg.user_tag = (void *)(NULL); // not for parent proc
     mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_GLOBAL_DONE)), MMI_EVENT_SUCCESS, &arg);   
}
    
/*****************************************************************************
 * FUNCTION
 *  mmi_java_global_security_change_domain_status_exit_screen
 * DESCRIPTION
 *  exit function of domain status screen
 * PARAMETERS
 *  void  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_global_security_change_domain_status_exit_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 inputBufferSize;
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* save the screen info */
    h.scrnID = SCR_ID_FNG_DOMAIN_CHANGE_JAVA;
    CloseCategory57Screen();
    h.entryFuncPtr = (FuncPtr) mmi_java_global_security_change_domain_status_entry_screen_int;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategory57History(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_global_security_change_domain_status_highlight_hdlr
 * DESCRIPTION
 *  highlight handler of domain status screen
 * PARAMETERS
 *  index       [S32]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_global_security_change_domain_status_highlight_hdlr (S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_DOMAIN_STATUS_HIGHLIGHT_SETTING_ITEM);     
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_java_global_security_change_domain_status_done_hdlr);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_global_security_change_domain_status_entry_screen_int
 * DESCRIPTION
 *  entry the domain status screen
 * PARAMETERS
 * void
 * RETURNS
 * void
 *****************************************************************************/
void mmi_java_global_security_change_domain_status_entry_screen_int(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    U8* guiBuffer = NULL;
    U8 *inputBuffer;
    U16 inputBufferSize;
    S32 i,j,k;
    MMI_ID_TYPE item_icons[20]; 
    MMI_BOOL isCaption = MMI_TRUE;
    
     static cui_inline_item_caption_struct caption_java_domain;
    U16* java_domain_select_string[2];
    static cui_inline_item_select_struct java_domain_select;
    static cui_inline_set_item_struct java_domain_item[10] = 
{
    {CUI_INLINE_ITEM_ID_BASE+0, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_FNG_SETTING_JAVA_AUD, (void*)&caption_java_domain},
    {CUI_INLINE_ITEM_ID_BASE+1, CUI_INLINE_ITEM_TYPE_SELECT, 0,  (void*)&java_domain_select},
    {CUI_INLINE_ITEM_ID_BASE+2, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_FNG_SETTING_JAVA_AUD,  (void*)&caption_java_domain},
    {CUI_INLINE_ITEM_ID_BASE+3, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&java_domain_select},
    {CUI_INLINE_ITEM_ID_BASE+4, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_FNG_SETTING_JAVA_AUD,  (void*)&caption_java_domain},
    {CUI_INLINE_ITEM_ID_BASE+5, CUI_INLINE_ITEM_TYPE_SELECT, 0,  (void*)&java_domain_select},
    {CUI_INLINE_ITEM_ID_BASE+6, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_FNG_SETTING_JAVA_AUD, (void*) &caption_java_domain},
    {CUI_INLINE_ITEM_ID_BASE+7, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&java_domain_select},
    {CUI_INLINE_ITEM_ID_BASE+8, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_FNG_SETTING_JAVA_AUD,  (void*)&caption_java_domain},
    {CUI_INLINE_ITEM_ID_BASE+9, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&java_domain_select}

};
static cui_inline_item_softkey_struct java_domain_inline_sofkey = {
                                  { {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0}, 
                                    {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
                                    {0, IMG_GLOBAL_COMMON_CSK} }
};
 
const cui_inline_struct java_domain_inline_screen = 
{
    10,//g_java_setting_and_security_cntx.real_total_domain * 2,
    0, 
    0,
    CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE,
    &java_domain_inline_sofkey,
    (const cui_inline_set_item_struct * )java_domain_item
};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_DOMAIN_STATUS_REAL_ENTRY_SETTING_SCREEN);  
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_JAVA_SECURITY, mmi_java_setting_and_security_sg_proc, NULL);
    mmi_frm_group_enter(GRP_ID_JAVA_SECURITY, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    g_java_security_inline = cui_inline_create(GRP_ID_JAVA_SECURITY,&java_domain_inline_screen);
    
    java_domain_select_string[0] = (U16 *)GetString(STR_GLOBAL_OFF);
    java_domain_select_string[1] = (U16 *)GetString(STR_GLOBAL_ON);
    
     for(i =0, j=0, k=0; k <(g_java_setting_and_security_cntx.real_total_domain) * 2; k++)
    {   
        if(isCaption)
    {
                cui_inline_set_value(g_java_security_inline,CUI_INLINE_ITEM_ID_BASE+k, (void *) GetString((U16) (g_java_setting_and_security_cntx.real_domains_str_id[i])));
               i++;
    }
        else
    {
                cui_inline_set_item_select(g_java_security_inline,CUI_INLINE_ITEM_ID_BASE+k,2,(PU8 *)java_domain_select_string,g_java_setting_and_security_cntx.domain_status[j]);
                j++;
    }
        isCaption = !isCaption;
    }
    cui_inline_set_title(g_java_security_inline, STR_ID_FNG_SECURITY_JAVA_DOMAIN_CHANGE, mmi_java_get_title_icon()); 
    for(i = (g_java_setting_and_security_cntx.real_total_domain) * 2; i < 10; i++)
    {
            cui_inline_delete_item(g_java_security_inline,CUI_INLINE_ITEM_ID_BASE+i);
    }
    cui_inline_register_lsk_handler();
    cui_inline_register_rsk_handler();
    
    cui_inline_run(g_java_security_inline);
}

    
/*****************************************************************************
 * FUNCTION
 *  mmi_java_global_security_get_domain_status_cnf
 * DESCRIPTION
 *  MSG MSG_ID_MMI_JAVA_GET_DOMAIN_STATUS_CNF handler
 *  parse the domain infomation and entry domain status screen
 * PARAMETERS
 *  MsgStruct    [void*]
 * RETURNS
 * void
 *****************************************************************************/
void mmi_java_global_security_get_domain_status_cnf(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_get_domain_status_cnf_struct *msg;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    msg = (mmi_java_get_domain_status_cnf_struct *) MsgStruct;

    g_java_setting_and_security_cntx.real_total_domain = msg->total_count;

    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_GET_DOMAIN_STATUS_CNF, msg->total_count);  
    
    for(i = 0 ;i < g_java_setting_and_security_cntx.real_total_domain ;i ++)
    {
        g_java_setting_and_security_cntx.real_domains_str_id[i] = msg->domains[i];
        g_java_setting_and_security_cntx.domain_status[i] = (S32)msg->domains_status[i];
    }   

    mmi_java_global_security_change_domain_status_entry_screen_int();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_global_security_change_domain_status_entry_screen
 * DESCRIPTION
 *  send MSG MSG_ID_MMI_JAVA_GET_DOMAIN_STATUS_REQ to get domain status info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_global_security_change_domain_status_entry_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_get_domain_status_req_struct *msg;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_DOMAIN_STATUS_REQ);  
    
    ClearInputEventHandler(MMI_DEVICE_ALL);

    msg = OslAllocDataPtr(mmi_java_get_domain_status_req_struct);    
    SetProtocolEventHandler(mmi_java_global_security_get_domain_status_cnf, MSG_ID_MMI_JAVA_GET_DOMAIN_STATUS_CNF);
    mmi_frm_send_ilm(MOD_JAM,MSG_ID_MMI_JAVA_GET_DOMAIN_STATUS_REQ,(oslParaType *)msg, NULL);

}    
/*****************************************************************************
 * FUNCTION
 *  mmi_java_global_security_item_highlight_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_global_security_item_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_java_setting_and_security_cntx.domain_selected = index;

    /* case: domain status menu item */
    if( index == g_java_setting_and_security_cntx.total_domain + 1)
    {
        SetLeftSoftkeyFunction(mmi_java_global_security_change_domain_status_entry_screen, KEY_EVENT_UP);
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_java_global_security_change_domain_status_entry_screen,KEY_EVENT_UP);
    }
    /* case: restore all domain menu item */    
    else if( index == g_java_setting_and_security_cntx.total_domain)
    {
        SetLeftSoftkeyFunction(mmi_java_global_security_restore_default_confirm_entry_screen, KEY_EVENT_UP);
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_java_global_security_restore_default_confirm_entry_screen,KEY_EVENT_UP);
    }
    /* case: general domain menu item */    
    else
    {
        mmi_wcscpy((U16*) g_mmi_java_current_selected_domain, (U16*)g_java_setting_and_security_cntx.domains[index]);            
        SetLeftSoftkeyFunction(mmi_java_global_security_lsk_hdlr, KEY_EVENT_UP);
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_java_global_security_lsk_hdlr,KEY_EVENT_UP);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_global_security_entry_screen
 * DESCRIPTION
 *  entry point for java setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_global_security_entry_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
    if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        mmi_popup_display_simple_ext(STR_JAVA_ERROR_CODE_NO_CARD, MMI_EVENT_WARNING, GRP_ID_ROOT, NULL);
        return;
    }
#endif
#if(MAX_VM_INSTANCE_NUM == 1)
#if defined(J2ME_SUPPORT_PAUSE)
    if (jam_mvm_is_pause_mode(0) || jam_mvm_is_minimize_mode(0))
    {
        g_mmi_java_current_selected_vm_id = 0;
        mmi_java_entry_cb_terminate_dialog(mmi_java_global_terminate_callback, (U16*)GetString(STR_JAVA_TERMINATE_JAVA_GAME),0);
        return;
    }
#elif defined(J2ME_SUPPORT_BACKGROUND)
    if(jam_mvm_is_vm_support_bg(0))
    {
        if (jam_mvm_is_pause_mode(0) || jam_mvm_is_minimize_mode(0))
        {
        	g_mmi_java_current_selected_vm_id = 0;
        	mmi_java_entry_cb_terminate_dialog(mmi_java_global_terminate_callback, (U16*)GetString(STR_JAVA_TERMINATE_JAVA_GAME),0);
        	return;
        }
    }
#endif
    if (jam_vm_is_busy())
    {
        mmi_java_display_is_busy();
        return ;
    }

#endif /*MAX_VM_INSTANCE_NUM == 1*/
    if(jam_is_busy())
    {
        mmi_java_display_is_busy();
        return;
    }
    
    SetProtocolEventHandler(mmi_java_global_security_get_domain_list_cnf, MSG_ID_MMI_JAVA_GET_DOMAIN_LIST_CNF);

    mmi_java_global_security_get_domain_list_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_global_security_entry_screen_internal
 * DESCRIPTION
 *  real entry point for java setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_global_security_entry_screen_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 i;
    U8 *item[MAX_SUB_MENUS];
    U8 *icon[MAX_SUB_MENUS];
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_JAVA_SECURITY, mmi_java_setting_and_security_sg_proc, NULL);
    mmi_frm_group_enter(GRP_ID_JAVA_SECURITY, MMI_FRM_NODE_SMART_CLOSE_FLAG );
    if(g_java_setting_and_security_cntx.total_domain != 0)
    {
        mmi_ucs2cpy( (S8*) g_java_setting_and_security_cntx.domains[g_java_setting_and_security_cntx.total_domain],
            (S8*) GetString(STR_ID_FNG_SECURITY_JAVA_RESTORE));
        mmi_ucs2cpy( (S8*) g_java_setting_and_security_cntx.domains[g_java_setting_and_security_cntx.total_domain + 1],
            (S8*) GetString(STR_ID_FNG_SECURITY_JAVA_DOMAIN_CHANGE));
        
        for (i = 0; i < g_java_setting_and_security_cntx.total_domain + 2; i++)
        {
            item[i] = (PU8) g_java_setting_and_security_cntx.domains[i];
            icon[i] = (PU8) GetImage(gIndexIconsImageList[i]);
        }
        guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_JAVA_SECURITY, SCR_ID_FNG_SECURITY_JAVA);
        //EntryNewScreen(SCR_ID_FNG_SECURITY_JAVA, NULL, mmi_java_global_security_entry_screen_internal, NULL);
        if(!mmi_frm_scrn_enter(GRP_ID_JAVA_SECURITY, SCR_ID_FNG_SECURITY_JAVA, NULL, mmi_java_global_security_entry_screen_internal, MMI_FRM_FULL_SCRN))
            {
                return;
            }
        RegisterHighlightHandler(mmi_java_global_security_item_highlight_hdlr);
        wgui_list_menu_enable_access_by_shortcut();
        ShowCategory170Screen(
            (PU8) GetString(STR_ID_FNG_SECURITY_JAVA),
            (PU8) GetImage(mmi_java_get_title_icon()),
            (PU8) GetString(STR_GLOBAL_OK),
            (PU8) GetImage(IMG_GLOBAL_OK),
            (PU8) GetString(STR_GLOBAL_BACK),
            (PU8) GetImage(IMG_GLOBAL_BACK),
            g_java_setting_and_security_cntx.total_domain + 2 ,
            item,
            icon,
            0,
            0,
            guiBuffer);
    }
    else
    {
        mmi_ucs2cpy( (S8*) g_java_setting_and_security_cntx.domains[0],
            (S8*) GetString(STR_ID_FNG_SECURITY_JAVA_RESTORE));
        mmi_ucs2cpy( (S8*) g_java_setting_and_security_cntx.domains[1],
            (S8*) GetString(STR_ID_FNG_SECURITY_JAVA_DOMAIN_CHANGE));
        for (i = 0; i < 2; i++)
        {
            item[i] = (PU8) g_java_setting_and_security_cntx.domains[i];
            icon[i] = (PU8) GetImage(gIndexIconsImageList[i]);
        }
        
        guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_JAVA_SECURITY, SCR_ID_FNG_SECURITY_JAVA);
        //EntryNewScreen(SCR_ID_FNG_SECURITY_JAVA, NULL, mmi_java_global_security_entry_screen_internal, NULL);
        if(!mmi_frm_scrn_enter(GRP_ID_JAVA_SECURITY, SCR_ID_FNG_SECURITY_JAVA, NULL, mmi_java_global_security_entry_screen_internal, MMI_FRM_FULL_SCRN))
            {
                return;
            }        
        RegisterHighlightHandler(mmi_java_global_security_item_highlight_hdlr);

        ShowCategory170Screen(
            (PU8) GetString(STR_ID_FNG_SECURITY_JAVA),
            (PU8) GetImage(mmi_java_get_title_icon()),
            (PU8) GetString(STR_GLOBAL_OK),
            (PU8) GetImage(IMG_GLOBAL_OK),
            (PU8) GetString(STR_GLOBAL_BACK),
            (PU8) GetImage(IMG_GLOBAL_BACK),
            2 ,
            item,
            icon,
            0,
            0,
            guiBuffer);    
    }
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_global_security_highlight_hdlr
 * DESCRIPTION
 *  highlight java security
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_global_security_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_java_global_security_entry_screen, KEY_EVENT_UP);
    EnableCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_java_global_security_entry_screen,KEY_EVENT_UP);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_java_local_setting_entry_screen
 * DESCRIPTION
 *  Main Menu->FunAndGames->Java->Applications->Options->Setting Entry Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_local_setting_entry_screen(void)
{
#ifdef __PLUTO_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef OGDR_SECURITY_SETTING  
     U16* domain_select_string[4];
#endif
    U16* setting_select_string[5];
    static cui_inline_item_select_struct domain_select;
     static cui_inline_item_select_struct setting_select;
    
    /*------------Net work access --------------*/
    static cui_inline_item_caption_struct caption_network =
    {
        STR_JAVA_SETTING_NETWORK_ACCESS
    };
     /*-----------push-----------*/
     static cui_inline_item_caption_struct caption_auto =
    {
        STR_JAVA_SETTING_AUTO_INVOCATION
    };
      /*------------ Java message -------------*/
       static cui_inline_item_caption_struct caption_message =
      {
          STR_JAVA_SETTING_MESSAGING
      };
     /*------------multimedia --------------*/
      static cui_inline_item_caption_struct caption_multimedia =
     {
         STR_JAVA_SETTING_MULTIMEDIA
     };       
    /*------------Data read ---------------*/
      static cui_inline_item_caption_struct caption_data_read =
     {
         STR_JAVA_SETTING_FILE_READ
     };  
    /*-----------Data write--------------*/
     static cui_inline_item_caption_struct caption_data_write =
     {
         STR_JAVA_SETTING_FILE_WRITE
     };
     /*-----------Local connection --------------*/
     static cui_inline_item_caption_struct caption_conn =
     {
         STR_JAVA_SETTING_LOCAL_CONNECTIVITY
     };     
#ifdef SUPPORT_JSR_179
     /*-----------Location access --------------*/
     static cui_inline_item_caption_struct caption_conn_179 =
     {
         STR_JAVA_SETTING_LOCATION_ACCESS
     };          
#endif
#ifdef SUPPORT_JSR_177
         /*-----------Location access --------------*/
         static cui_inline_item_caption_struct caption_mids_security_trust =
         {
             STR_JAVA_SECURITY_TRUST
         };          
#endif
#ifdef SUPPORT_JSR_257
         /*-----------Location access --------------*/
         static cui_inline_item_caption_struct caption_mids_contactless_comm =
         {
             STR_JAVA_CONTACTLESS_COMMUNICATION
         };          
#endif


    static cui_inline_item_softkey_struct java_opt_inline_sofkey = 
    {
        { {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0}, 
          {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
          {0, IMG_GLOBAL_COMMON_CSK} }
     };

    static const cui_inline_set_item_struct java_opt_setting_item[] = 
    {
       {JAVA_SETTING_NETWORK_ACCESS_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L1, &caption_network},
        {JAVA_SETTING_NETWORK_ACCESS_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &setting_select},
        {JAVA_SETTING_AUTO_INVOCATION_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L2, &caption_auto},
        {JAVA_SETTING_AUTO_INVOCATION_SELECT, CUI_INLINE_ITEM_TYPE_SELECT,0,&setting_select},
        {JAVA_SETTING_MESSAGING_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L3, &caption_message},
        {JAVA_SETTING_MESSAGING_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &setting_select},
        {JAVA_SETTING_MULTIMEDIA_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L4, &caption_multimedia},
        {JAVA_SETTING_MULTIMEDIA_SELECT, CUI_INLINE_ITEM_TYPE_SELECT,0, &setting_select},
        {JAVA_SETTING_FILE_READ_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L5, &caption_data_read},
        {JAVA_SETTING_FILE_READ_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &setting_select},
        {JAVA_SETTING_FILE_WRITE_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L6, &caption_data_write},
        {JAVA_SETTING_FILE_WRITE_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &setting_select},
        {JAVA_SETTING_LOCAL_CONNECTIVITY_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION , IMG_GLOBAL_L7, &caption_conn},
        {JAVA_SETTING_LOCAL_CONNECTIVITY_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &setting_select}
#ifdef SUPPORT_JSR_179
    ,{JAVA_SETTING_LOVAL_LOCATION_ACCESS_CAPTION,CUI_INLINE_ITEM_TYPE_CAPTION,IMG_GLOBAL_L8,&caption_conn_179},
    {JAVA_SETTING_LOVAL_LOCATION_ACCESS_SELECT,CUI_INLINE_ITEM_TYPE_SELECT, 0, &setting_select}
 #endif   
 #ifdef SUPPORT_JSR_177
    ,{JAVA_SETTING_SECURITY_TRUST_CAPTION,CUI_INLINE_ITEM_TYPE_CAPTION,IMG_GLOBAL_L9,&caption_mids_security_trust},
    {JAVA_SETTING_SECURITY_TRUST_SELECT,CUI_INLINE_ITEM_TYPE_SELECT, 0, &setting_select} 
#endif
 #ifdef SUPPORT_JSR_257
    ,{JAVA_SETTING_CONTACTLESS_COMMUNICATION_CAPTION,CUI_INLINE_ITEM_TYPE_CAPTION,IMG_GLOBAL_L10,&caption_mids_contactless_comm},
    {JAVA_SETTING_CONTACTLESS_COMMUNICATION_SELECT,CUI_INLINE_ITEM_TYPE_SELECT, 0, &setting_select} 
#endif
    };

    static const cui_inline_set_item_struct java_general_domain_item[] = 
    {
        {JAVA_SETTING_NETWORK_ACCESS_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L1, &caption_network},
        {JAVA_SETTING_NETWORK_ACCESS_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &domain_select},
        {JAVA_SETTING_AUTO_INVOCATION_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L2, &caption_auto},
        {JAVA_SETTING_AUTO_INVOCATION_SELECT, CUI_INLINE_ITEM_TYPE_SELECT,0,&domain_select},
        {JAVA_SETTING_MESSAGING_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L3, &caption_message},
        {JAVA_SETTING_MESSAGING_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &domain_select},
        {JAVA_SETTING_MULTIMEDIA_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L4, &caption_multimedia},
        {JAVA_SETTING_MULTIMEDIA_SELECT, CUI_INLINE_ITEM_TYPE_SELECT,0, &domain_select},
        {JAVA_SETTING_FILE_READ_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L5, &caption_data_read},
        {JAVA_SETTING_FILE_READ_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &domain_select},
        {JAVA_SETTING_FILE_WRITE_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L6, &caption_data_write},
        {JAVA_SETTING_FILE_WRITE_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &domain_select},
        {JAVA_SETTING_LOCAL_CONNECTIVITY_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION , IMG_GLOBAL_L7, &caption_conn},
        {JAVA_SETTING_LOCAL_CONNECTIVITY_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &domain_select}
 #ifdef SUPPORT_JSR_179    
    ,{JAVA_SETTING_LOVAL_LOCATION_ACCESS_CAPTION,CUI_INLINE_ITEM_TYPE_CAPTION,IMG_GLOBAL_L8,&caption_conn_179},
    {JAVA_SETTING_LOVAL_LOCATION_ACCESS_SELECT,CUI_INLINE_ITEM_TYPE_SELECT, 0, &domain_select}
#endif
#ifdef SUPPORT_JSR_177
       ,{JAVA_SETTING_SECURITY_TRUST_CAPTION,CUI_INLINE_ITEM_TYPE_CAPTION,IMG_GLOBAL_L9,&caption_mids_security_trust},
       {JAVA_SETTING_SECURITY_TRUST_SELECT,CUI_INLINE_ITEM_TYPE_SELECT, 0, &domain_select} 
#endif
#ifdef SUPPORT_JSR_257
       ,{JAVA_SETTING_CONTACTLESS_COMMUNICATION_CAPTION,CUI_INLINE_ITEM_TYPE_CAPTION,IMG_GLOBAL_L10,&caption_mids_contactless_comm},
       {JAVA_SETTING_CONTACTLESS_COMMUNICATION_SELECT,CUI_INLINE_ITEM_TYPE_SELECT, 0, &domain_select} 
#endif

    };
    
    const cui_inline_struct java_opt_setting_inline_screen = 
    {
        2*J2ME_SETTING_MAX,
        0,
        0,
        CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE,
        &java_opt_inline_sofkey,
        java_opt_setting_item
    };
#ifdef OGDR_SECURITY_SETTING 
    const cui_inline_struct java_general_domain_inline_screen = 
    {
        2*J2ME_SETTING_MAX,
        0,
        0,
        CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE,
        &java_opt_inline_sofkey,
        java_general_domain_item
    };
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef OGDR_SECURITY_SETTING 
   domain_select_string[0] =(U16*)GetString(STR_JAVA_PERM_USERDENY);
   domain_select_string[1] = (U16*)GetString(STR_JAVA_PERM_ONESHOT);
   domain_select_string[2] = (U16*)GetString(STR_JAVA_PERM_SESSION);
   domain_select_string[3] = (U16*)GetString(STR_JAVA_PERM_BLANKET);  
#endif
   setting_select_string[0] = (U16*)GetString(STR_JAVA_PERM_USERDENY);
   setting_select_string[1] = (U16*)GetString(STR_JAVA_PERM_ONESHOT);
   setting_select_string[2] = (U16*)GetString(STR_JAVA_PERM_SESSION), 
   setting_select_string[3] =(U16*)GetString(STR_JAVA_PERM_BLANKET);
   setting_select_string[4] =(U16*)GetString(STR_JAVA_PERM_BLANKET_GRANTED);

#ifdef OGDR_SECURITY_SETTING    
    /* Domain setting */
    if(get_domain_setting)
        {
            mmi_frm_group_create_ex(
                GRP_ID_ROOT,
                GRP_ID_JAVA_SECURITY,
                mmi_java_setting_and_security_sg_proc,
                NULL,
                MMI_FRM_NODE_SMART_CLOSE_FLAG);
        g_java_domain_inline = cui_inline_create(GRP_ID_JAVA_SECURITY,&java_general_domain_inline_screen);
        if(!mmi_wcscmp((U16*)(g_mmi_java_current_selected_domain), (U16*)get_string(STR_JAVA_PERM_DMN_3RDPARTY)))
        {
            cui_inline_set_title(g_java_domain_inline, STR_JAVA_PERM_DMN_3RDPARTY, mmi_java_get_title_icon()); 
        }
        else if(!mmi_wcscmp((U16*)(g_mmi_java_current_selected_domain), (U16*)get_string(STR_JAVA_PERM_DMN_UNTRUSTED)))        
        {
            cui_inline_set_title(g_java_domain_inline,STR_JAVA_PERM_DMN_UNTRUSTED,mmi_java_get_title_icon());   
        }
        cui_inline_set_title_icon(g_java_domain_inline,mmi_java_get_title_icon());

        cui_inline_set_item_select(
            g_java_domain_inline,
            JAVA_SETTING_NETWORK_ACCESS_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_network),
            (PU8*)&domain_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_network));

         cui_inline_set_item_select(
            g_java_domain_inline,
            JAVA_SETTING_AUTO_INVOCATION_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_push),
            (PU8*)&domain_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_push));   

         cui_inline_set_item_select(
            g_java_domain_inline,
            JAVA_SETTING_MESSAGING_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_message),
            (PU8*)&domain_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_message));     

          cui_inline_set_item_select(
            g_java_domain_inline,
            JAVA_SETTING_MULTIMEDIA_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_multimedia),
            (PU8*)&domain_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_multimedia));    

          cui_inline_set_item_select(
            g_java_domain_inline,
            JAVA_SETTING_FILE_READ_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_data_read),
            (PU8*)&domain_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_data_read));    

          cui_inline_set_item_select(
            g_java_domain_inline,
            JAVA_SETTING_FILE_WRITE_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_data_write),
            (PU8*)&domain_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_data_write));    

          cui_inline_set_item_select(
            g_java_domain_inline,
            JAVA_SETTING_LOCAL_CONNECTIVITY_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_local_connectivity),
            (PU8*)&domain_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_local_connectivity));    
#ifdef SUPPORT_JSR_179
          cui_inline_set_item_select(
            g_java_domain_inline,
            JAVA_SETTING_LOVAL_LOCATION_ACCESS_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_location_access),
            (PU8*)&domain_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_location_access)); 
#endif
#ifdef SUPPORT_JSR_177
                  cui_inline_set_item_select(
                    g_java_domain_inline,
                    JAVA_SETTING_SECURITY_TRUST_SELECT,
                    mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_satsa),
                    (PU8*)&domain_select_string,
                    mmi_java_get_choice_level(g_java.mids_setting.permission_satsa)); 
#endif
#ifdef SUPPORT_JSR_257
                          cui_inline_set_item_select(
                            g_java_domain_inline,
                            JAVA_SETTING_CONTACTLESS_COMMUNICATION_SELECT,
                            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_contactless_communication),
                            (PU8*)&domain_select_string,
                            mmi_java_get_choice_level(g_java.mids_setting.permission_contactless_communication)); 
#endif
        cui_inline_register_lsk_handler();
        cui_inline_register_rsk_handler();

        cui_inline_run(g_java_domain_inline);
     }
    else    /* Option setting */
#endif /*OGDR_SECURITY_SETTING*/
        {
            mmi_frm_group_create_ex(
                APP_JAVA,
                GRP_ID_JAVA_OPT,
                mmi_java_opt_sg_proc,
                NULL,
                MMI_FRM_NODE_SMART_CLOSE_FLAG);
            g_java_opt_setting_inline = cui_inline_create(GRP_ID_JAVA_OPT,&java_opt_setting_inline_screen);
            cui_inline_set_title(g_java_opt_setting_inline, STR_GLOBAL_SETTINGS, mmi_java_get_title_icon()); 
            cui_inline_set_title_icon(g_java_opt_setting_inline,mmi_java_get_title_icon());

           cui_inline_set_item_select(
            g_java_opt_setting_inline,
            JAVA_SETTING_NETWORK_ACCESS_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_network),
            (PU8*)&setting_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_network));
         cui_inline_set_item_select(
            g_java_opt_setting_inline,
            JAVA_SETTING_AUTO_INVOCATION_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_push),
            (PU8*)&setting_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_push));   
         cui_inline_set_item_select(
            g_java_opt_setting_inline,
            JAVA_SETTING_MESSAGING_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_message),
            (PU8*)&setting_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_message));     
          cui_inline_set_item_select(
            g_java_opt_setting_inline,
            JAVA_SETTING_MULTIMEDIA_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_multimedia),
            (PU8*)&setting_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_multimedia));    
          cui_inline_set_item_select(
            g_java_opt_setting_inline,
            JAVA_SETTING_FILE_READ_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_data_read),
            (PU8*)&setting_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_data_read));    
          cui_inline_set_item_select(
            g_java_opt_setting_inline,
            JAVA_SETTING_FILE_WRITE_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_data_write),
            (PU8*)&setting_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_data_write));    
          cui_inline_set_item_select(
            g_java_opt_setting_inline,
            JAVA_SETTING_LOCAL_CONNECTIVITY_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_local_connectivity),
            (PU8*)&setting_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_local_connectivity));  
 #ifdef SUPPORT_JSR_179
          cui_inline_set_item_select(
            g_java_opt_setting_inline,
            JAVA_SETTING_LOVAL_LOCATION_ACCESS_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_location_access),
            (PU8*)&setting_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_location_access)); 
 #endif
 #ifdef SUPPORT_JSR_177
          cui_inline_set_item_select(
            g_java_opt_setting_inline,
            JAVA_SETTING_SECURITY_TRUST_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_satsa),
            (PU8*)&setting_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_satsa)); 
#endif
#ifdef SUPPORT_JSR_257
          cui_inline_set_item_select(
            g_java_opt_setting_inline,
            JAVA_SETTING_CONTACTLESS_COMMUNICATION_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_contactless_communication),
            (PU8*)&setting_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_contactless_communication)); 
#endif
            cui_inline_register_lsk_handler();
            cui_inline_register_rsk_handler();
            cui_inline_run(g_java_opt_setting_inline);
        }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_get_value_from_inline_cui
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_get_value_from_inline_cui(mmi_id inline, S32 item_index, void* value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_get_value(inline, item_index, value);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_update_security_setting
 * DESCRIPTION
 *  Update setting of the MIDLet
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_update_security_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    MMI_BOOL modification_not_allowed = MMI_FALSE;
    MMI_BOOL modified = MMI_FALSE;
    S8 new_perm = 0;
    S32 new_choice = 0;
    mmi_id inline_cui = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ClearInputEventHandler(MMI_DEVICE_ALL);
    
    #ifdef OGDR_SECURITY_SETTING
    if(get_domain_setting)
    {
        inline_cui = g_java_domain_inline;
    }
    else
    {
        inline_cui = g_java_opt_setting_inline;
    }
    #else
        inline_cui = g_java_opt_setting_inline;
    #endif
    
    for( i = 0 ; i < J2ME_SETTING_MAX ;i ++)
    {
        switch (i)
        {
            case J2ME_SETTING_NETWORK_ACCESS:
            mmi_java_get_value_from_inline_cui(inline_cui, JAVA_SETTING_NETWORK_ACCESS_SELECT+i*2, (void *)&new_choice);
            new_perm = mmi_java_get_new_permission_level((S8) new_choice,
                                                                                (S8)g_java.mids_max_setting.permission_network,
                                                                                (S8)g_java.mids_setting.permission_network);
            if(g_java.mids_setting.permission_network != new_perm)
                modified = MMI_TRUE;
            if ((g_java.mids_setting.permission_network == PERMISSION_ALLOW &&
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_OK) ||
                (g_java.mids_setting.permission_network == PERMISSION_NEVER &&
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_USERDENY))
                {
                    modification_not_allowed = MMI_TRUE;
                    break;
                }
            
                g_java.mids_choice_index[i] = new_choice;
                g_java.mids_setting.permission_network = new_perm;
                break;
                
            case J2ME_SETTING_AUTO_INVOCATION:
            mmi_java_get_value_from_inline_cui(inline_cui, JAVA_SETTING_NETWORK_ACCESS_SELECT+i*2, (void *)&new_choice);
            new_perm = mmi_java_get_new_permission_level((S8) new_choice,
                                                                                (S8)g_java.mids_max_setting.permission_push,
                                                                                (S8)g_java.mids_setting.permission_push);
            if(g_java.mids_setting.permission_push != new_perm)
                modified = MMI_TRUE;
            if ((g_java.mids_setting.permission_push == PERMISSION_ALLOW &&
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_OK) ||
                (g_java.mids_setting.permission_push == PERMISSION_NEVER &&
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_USERDENY))
                {
                    modification_not_allowed = MMI_TRUE;
                    break;
                }              
                g_java.mids_choice_index[i] = new_choice;
                g_java.mids_setting.permission_push = new_perm;
                break;
            case J2ME_SETTING_MESSAGING:
                mmi_java_get_value_from_inline_cui(inline_cui, JAVA_SETTING_NETWORK_ACCESS_SELECT+i*2, (void *)&new_choice);
                new_perm  = mmi_java_get_new_permission_level((S8) new_choice,
                                                                                (S8)g_java.mids_max_setting.permission_message,
                                                                                (S8)g_java.mids_setting.permission_message);
                if(g_java.mids_setting.permission_message!= new_perm)
                    modified = MMI_TRUE;
                if ((g_java.mids_setting.permission_message == PERMISSION_ALLOW &&
                        g_java.mids_choice_index[i] !=J2ME_CHOICE_OK) ||
                    (g_java.mids_setting.permission_message == PERMISSION_NEVER &&
                        g_java.mids_choice_index[i] !=J2ME_CHOICE_USERDENY))
                    {
                        modification_not_allowed = MMI_TRUE;
                        break;
                    }
                
                g_java.mids_choice_index[i] =  new_choice;
                g_java.mids_setting.permission_message = new_perm;;
                break;
            case J2ME_SETTING_MULTIMEDIA:
            mmi_java_get_value_from_inline_cui(inline_cui, JAVA_SETTING_NETWORK_ACCESS_SELECT+i*2, (void *)&new_choice);
             new_perm = mmi_java_get_new_permission_level((S8) new_choice,
                                                                                (S8)g_java.mids_max_setting.permission_multimedia,
                                                                                (S8)g_java.mids_setting.permission_multimedia);
             if(new_perm!= g_java.mids_setting.permission_multimedia)
                modified = MMI_TRUE;
            if ((g_java.mids_setting.permission_multimedia == PERMISSION_ALLOW &&
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_OK) ||
                (g_java.mids_setting.permission_multimedia == PERMISSION_NEVER &&
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_USERDENY))
                {
                    modification_not_allowed = MMI_TRUE;
                    break;
                }
                 g_java.mids_choice_index[i] = new_choice;
                g_java.mids_setting.permission_multimedia = new_perm;
                break;
            case J2ME_SETTING_DATA_READ:
                mmi_java_get_value_from_inline_cui(inline_cui, JAVA_SETTING_NETWORK_ACCESS_SELECT+i*2, (void *)&new_choice);
                new_perm = mmi_java_get_new_permission_level((S8) new_choice,
                                                                                (S8)g_java.mids_max_setting.permission_data_read,
                                                                                (S8)g_java.mids_setting.permission_data_read);
                if(new_perm!= g_java.mids_setting.permission_data_read)
                    modified = MMI_TRUE;
            if ((g_java.mids_setting.permission_data_read == PERMISSION_ALLOW &&
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_OK) ||
                (g_java.mids_setting.permission_data_read == PERMISSION_NEVER &&
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_USERDENY))
                {
                    modification_not_allowed = MMI_TRUE;
                    break;
                }

                g_java.mids_choice_index[i] = new_choice;
                g_java.mids_setting.permission_data_read = new_perm;
                break;
            case J2ME_SETTING_DATA_WRITE:
                mmi_java_get_value_from_inline_cui(inline_cui, JAVA_SETTING_NETWORK_ACCESS_SELECT+i*2, (void *)&new_choice);
                new_perm  = mmi_java_get_new_permission_level((S8) new_choice,
                                                                                (S8)g_java.mids_max_setting.permission_data_write,
                                                                                (S8)g_java.mids_setting.permission_data_write);
              if(new_perm!= g_java.mids_setting.permission_data_write)
                modified = MMI_TRUE;
            if ((g_java.mids_setting.permission_data_write == PERMISSION_ALLOW &&
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_OK) ||
                (g_java.mids_setting.permission_data_write == PERMISSION_NEVER &&
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_USERDENY))
                {
                    modification_not_allowed = MMI_TRUE;
                    break;
                }

                g_java.mids_choice_index[i] = new_choice;
                g_java.mids_setting.permission_data_write = new_perm;
                break;
            case J2ME_SETTING_LOCAL_CONNECTIVITY:
            mmi_java_get_value_from_inline_cui(inline_cui, JAVA_SETTING_NETWORK_ACCESS_SELECT+i*2, (void *)&new_choice);
            new_perm  = mmi_java_get_new_permission_level((S8) new_choice,
                                                                                (S8)g_java.mids_max_setting.permission_local_connectivity,
                                                                                (S8)g_java.mids_setting.permission_local_connectivity);
              if(new_perm!= g_java.mids_setting.permission_local_connectivity)
                modified = MMI_TRUE;
            if ((g_java.mids_setting.permission_local_connectivity == PERMISSION_ALLOW &&
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_OK) ||
                (g_java.mids_setting.permission_local_connectivity == PERMISSION_NEVER &&
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_USERDENY))
                {
                    modification_not_allowed = MMI_TRUE;
                    break;
                }

                g_java.mids_choice_index[i] = new_choice;
                g_java.mids_setting.permission_local_connectivity = new_perm;
                break;
#ifdef SUPPORT_JSR_179
            case J2ME_SETTING_LOCATION_ACCESS:
            mmi_java_get_value_from_inline_cui(inline_cui, JAVA_SETTING_NETWORK_ACCESS_SELECT+i*2, (void *)&new_choice);     
            new_perm = mmi_java_get_new_permission_level((S8) new_choice,
                                                                                (S8)g_java.mids_max_setting.permission_location_access,
                                                                                (S8)g_java.mids_setting.permission_location_access);
            if(new_perm!= g_java.mids_setting.permission_location_access)
                modified = MMI_TRUE;
            if ((g_java.mids_setting.permission_location_access== PERMISSION_ALLOW &&
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_OK) ||
                (g_java.mids_setting.permission_location_access == PERMISSION_NEVER &&
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_USERDENY))
                {
                    modification_not_allowed = MMI_TRUE;
                    break;
                }
            
                g_java.mids_choice_index[i] = new_choice;
                g_java.mids_setting.permission_location_access = new_perm;
                break;
#endif
#ifdef SUPPORT_JSR_177
                      case J2ME_SETTING_SATSA:
                      mmi_java_get_value_from_inline_cui(inline_cui, JAVA_SETTING_NETWORK_ACCESS_SELECT+i*2, (void *)&new_choice);              
                         new_perm = mmi_java_get_new_permission_level((S8) new_choice,
                                                                                          (S8)g_java.mids_max_setting.permission_satsa,
                                                                                          (S8)g_java.mids_setting.permission_satsa);
                      if(new_perm!= g_java.mids_setting.permission_satsa)
                          modified = MMI_TRUE;
                      if ((g_java.mids_setting.permission_satsa== PERMISSION_ALLOW &&
                              g_java.mids_choice_index[i] !=J2ME_CHOICE_OK) ||
                          (g_java.mids_setting.permission_satsa == PERMISSION_NEVER &&
                              g_java.mids_choice_index[i] !=J2ME_CHOICE_USERDENY))
                          {
                              modification_not_allowed = MMI_TRUE;
                              break;
                          }
                      
                          g_java.mids_choice_index[i] = new_choice;
                          g_java.mids_setting.permission_satsa = new_perm;
                          break;
#endif
#ifdef SUPPORT_JSR_257
                    case J2ME_SETTING_CONTACTLESS_COMMUNICATION:
                      mmi_java_get_value_from_inline_cui(inline_cui, JAVA_SETTING_NETWORK_ACCESS_SELECT+i*2, (void *)&new_choice);                
                       new_perm = mmi_java_get_new_permission_level((S8) new_choice,
                                                                                        (S8)g_java.mids_max_setting.permission_contactless_communication,
                                                                                        (S8)g_java.mids_setting.permission_contactless_communication);
                    if(new_perm!= g_java.mids_setting.permission_contactless_communication)
                        modified = MMI_TRUE;
                    if ((g_java.mids_setting.permission_contactless_communication== PERMISSION_ALLOW &&
                            g_java.mids_choice_index[i] !=J2ME_CHOICE_OK) ||
                        (g_java.mids_setting.permission_contactless_communication == PERMISSION_NEVER &&
                            g_java.mids_choice_index[i] !=J2ME_CHOICE_USERDENY))
                        {
                            modification_not_allowed = MMI_TRUE;
                            break;
                        }
                    
                        g_java.mids_choice_index[i] = new_choice;
                        g_java.mids_setting.permission_contactless_communication = new_perm;
                        break;
#endif

          }
    }
    if (modification_not_allowed && modified){

        mmi_popup_display_simple_ext(STR_JAVA_PERMISSION_SETTING_FAIL, MMI_EVENT_FAILURE, GRP_ID_JAVA_OPT, NULL);
        mmi_frm_scrn_close(GRP_ID_JAVA_OPT,SCR_JAVA_APP_OPTION_SETTING);
        return;
    }else if(!modified)
            {
                mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_JAVA_OPT, NULL);
                mmi_frm_scrn_close(GRP_ID_JAVA_OPT,SCR_JAVA_APP_OPTION_SETTING);
                return;
            }
    
    #ifdef OGDR_SECURITY_SETTING
    if (g_java.domain >= 0 )
    {
        mmi_java_send_set_default_domain_req();
    }
    else
    #endif
    {
        mmi_java_send_mids_set_setting_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_setting_and_security_sg_proc
 * DESCRIPTION
 *  Java setting and security screen group proc function
 * PARAMETERS
 *  events
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_java_setting_and_security_sg_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_group_event_struct * g_evt  = (mmi_group_event_struct * )evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    switch(evt->evt_id)
       {
       case EVT_ID_CUI_INLINE_ABORT:
            cui_inline_close(g_evt->sender_id);
            break;
       case EVT_ID_CUI_INLINE_GROUP_DEINIT:
            if(g_evt->sender_id == g_java_setting_inline)
            {
                g_java_setting_inline = CUI_INLINE_INVALID_ID;
            }    
            else if(g_evt->sender_id == g_java_security_inline)
            {
                g_java_security_inline = CUI_INLINE_INVALID_ID;
            }
            else if(g_evt->sender_id == g_java_domain_inline)
            {
                g_java_domain_inline = CUI_INLINE_INVALID_ID;
            }
            break;
       case EVT_ID_CUI_INLINE_SUBMIT:
       case EVT_ID_CUI_INLINE_CSK_PRESS:
        if(g_evt->sender_id == g_java_setting_inline)
        {
            mmi_java_nw_set_inline_sg_id(g_java_setting_inline);
            mmi_java_nw_inline_editor_cui_proc(evt);
            mmi_java_global_setting_java_done_hdlr();
            mmi_java_set_audio_volume_req(g_mmi_java_aud_volume_level);
            cui_inline_close(g_evt->sender_id);
        }    
        if(g_evt->sender_id == g_java_security_inline)
        {
            #ifdef OGDR_SECURITY_SETTING
            mmi_java_global_security_change_domain_status_done_hdlr();
            #endif
         }
        if(g_evt->sender_id == g_java_domain_inline)
        {
            mmi_java_update_security_setting();
            cui_inline_close(g_java_domain_inline);
         }
            break;
        /* java nw setting */    
        case EVT_ID_CUI_INLINE_SET_KEY:
        case EVT_ID_CUI_INLINE_NOTIFY:
            if (g_evt->sender_id == g_java_setting_inline)
            {
                mmi_java_nw_set_inline_sg_id(g_java_setting_inline);
                mmi_java_nw_inline_editor_cui_proc(evt);
            }
            break;
        /* java nw dtcnt cui evt */
        case CUI_DTCNT_SELECT_EVENT_RESULT_OK:
        case CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL:
        case CUI_DTCNT_SELECT_EVENT_CLOSE:
        case CUI_DTCNT_SELECT_EVENT_RESULT_FAILED:
        case CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED:
            mmi_java_nw_dtcnt_cui_proc(evt);
            break;
        case MMI_EVENT_SUCCESS:
        case MMI_EVENT_FAILURE:
        case EVT_ID_POPUP_QUIT:
            cui_inline_close(g_evt->sender_id);
            break;
       default:
            break;
       }
       return MMI_RET_OK;
}
#endif /* __PLUTO_MMI_PACKAGE__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_mids_get_setting_req
 * DESCRIPTION
 *  This routines send MSG_ID_MMI_JAVA_MIDS_GET_SETTING_REQ to MOD_JAM to get setting of
 * MIDS
 *  
 * PARAMETERS
 *  mids_id         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_mids_get_setting_req(U32 mids_id, kal_char* root)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mids_get_setting_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_MIDS_GET_SETTING_REQ);
    if (g_java.msg_ctrl & SEND_MID_GET_SETTING_CTRL )
    {
        mmi_java_display_is_busy();
    }
    else
    {
        g_java.msg_ctrl |= SEND_MID_GET_SETTING_CTRL;
        msg = (mmi_java_mids_get_setting_req_struct*) OslConstructDataPtr(sizeof(mmi_java_mids_get_setting_req_struct));
        msg->mids_id = (kal_uint32)mids_id;
        msg->storage_name = (kal_char*)root;
    
        mmi_java_send_message_from_active_mod(MOD_JAM, MMI_J2ME_SAP,
            MSG_ID_MMI_JAVA_MIDS_GET_SETTING_REQ, msg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_mids_get_setting_cnf
 * DESCRIPTION
 *  This routines handles MMI_JAVA_MIDS_GET_SETTING_CNF from MOD_JAM to display
 *  permission screen to user to modify
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_mids_get_setting_cnf(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mids_get_setting_cnf_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_MIDS_GET_SETTING_CNF);

    msg = (mmi_java_mids_get_setting_cnf_struct*) MsgStruct;
    if (g_java.msg_ctrl & SEND_MID_GET_SETTING_CTRL )
    {
        g_java.msg_ctrl &= (~SEND_MID_GET_SETTING_CTRL);        
        if (msg->error_code == (kal_uint32) J2ME_NO_ERROR)
        {
            g_java.mids_trusted = (U8) msg->mids_trusted;
    
            kal_mem_cpy(&(g_java.mids_setting), &(msg->mids_setting), sizeof(mmi_setting_struct));
            kal_mem_cpy(&(g_java.mids_max_setting), &(msg->mids_max_setting), sizeof(mmi_setting_struct));
        }
        else 
        {
            mmi_popup_display_simple_ext(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE, GRP_ID_JAVA_OPT, NULL);
    
            get_setting_only = MMI_FALSE;    
            return;
        }    
#if defined(__PLUTO_MMI_PACKAGE__)
        if (!get_setting_only)
        {
            get_domain_setting = MMI_FALSE;
            mmi_java_local_setting_entry_screen();
        }
#endif
        get_setting_only = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_mids_set_setting_req
 * DESCRIPTION
 *  This routines send MSG_ID_MMI_JAVA_MIDS_SET_SETTING_REQ to MOD_JAM to set setting of
 *  MIDS and set protocol event handler of MSG_ID_MMI_JAVA_MIDS_SET_SETTING_CNF
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_mids_set_setting_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mids_set_setting_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_MIDS_SET_SETTING_REQ);

    if (g_java.msg_ctrl & SEND_MID_SET_SETTING_CTRL )
    {
        mmi_java_display_is_busy();
    }
    else
    {
        g_java.msg_ctrl |= SEND_MID_SET_SETTING_CTRL;
        msg = (mmi_java_mids_set_setting_req_struct*) OslConstructDataPtr(sizeof(mmi_java_mids_set_setting_req_struct));
        msg->mids_id = g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_id;

        kal_mem_cpy(&(msg->mids_setting), &(g_java.mids_setting), sizeof(mmi_setting_struct));

        mmi_java_send_message_from_active_mod(MOD_JAM, MMI_J2ME_SAP,
            MSG_ID_MMI_JAVA_MIDS_SET_SETTING_REQ, msg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_setting_cnf_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *       
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_java_setting_cnf_proc(mmi_event_struct * evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__PLUTO_MMI_PACKAGE__)
    switch(evt->evt_id)
    {  
        case EVT_ID_POPUP_QUIT:
            cui_inline_close(g_java_opt_setting_inline);
        break;
        default:
            break;
    }
#endif
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_mids_set_setting_cnf
 * DESCRIPTION
 *  This routines handles MMI_JAVA_MIDS_SET_SETTING_CNF from MOD_JAM
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_mids_set_setting_cnf(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mids_set_setting_cnf_struct *msg;
    mmi_popup_property_struct arg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_MIDS_SET_SETTING_CNF);

    msg = (mmi_java_mids_set_setting_cnf_struct*) MsgStruct;

    if (g_java.msg_ctrl & SEND_MID_SET_SETTING_CTRL )
    {
        if (msg->error_code == J2ME_NO_ERROR)
        {
        mmi_popup_property_init(&arg);
        arg.callback = mmi_java_setting_cnf_proc;
        mmi_popup_display_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, &arg);
        }
        else
        {
        mmi_popup_property_init(&arg);
        arg.callback = mmi_java_setting_cnf_proc;
        mmi_popup_display_ext(STR_GLOBAL_UNFINISHED, MMI_EVENT_FAILURE, &arg);
        }
        /* only get the setting from Java again to update the latest setting value since exclusive setting may automatically
            update other setting value*/
        get_setting_only = MMI_TRUE;
        mmi_java_send_mids_get_setting_req(g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_id, NULL);
        g_java.msg_ctrl &= (~SEND_MID_SET_SETTING_CTRL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_get_choice_level
 * DESCRIPTION
 *  Transfer PERMISSION_LEVEL to J2ME_CHOICE_LEVEL
 * PARAMETERS
 *  permisisonLevel     [IN]        Level of PERMISSION_LEVEL
 * RETURNS
 *  level of J2ME_CHOICE_LEVEL
 *****************************************************************************/
S8 mmi_java_get_choice_level(S8 permisisonLevel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 selected;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (permisisonLevel)
    {
        case PERMISSION_ALLOW:
        case PERMISSION_BLANKET_GRANTED:
            selected = J2ME_CHOICE_OK;
            break;

        case PERMISSION_BLANKET:
            //if (get_domain_setting)
            //{
                selected = J2ME_CHOICE_BLANKET;
                break;
            //}
        case PERMISSION_SESSION:
            selected = J2ME_CHOICE_SESSION;
            break;

        case PERMISSION_ONE_SHOT:
        case PERMISSION_DENY_SESSION:
            selected = J2ME_CHOICE_ONESHOT;
            break;

        case PERMISSION_NEVER:
        case PERMISSION_DENY:
        case PERMISSION_USER_DENIED:
            selected = J2ME_CHOICE_USERDENY;
            break;

        default:
            selected = J2ME_CHOICE_USERDENY;
            break;
    }

    return selected;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_get_perm_menu_item_count
 * DESCRIPTION
 *  Get the menu item count form a maximum permission level.
 * PARAMETERS
 *  max_level               [IN]        
 *  permisisonLevel(?)      [IN]        Level of maximum PERMISSION_LEVEL
 * RETURNS
 *  level of J2ME_CHOICE_LEVEL
 *****************************************************************************/
S32 mmi_java_get_perm_menu_item_count(S8 max_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (max_level)
    {
        case PERMISSION_ALLOW:
        case PERMISSION_BLANKET_GRANTED:
        case PERMISSION_BLANKET:
        if(get_domain_setting)
        {
            return 4;
        }
        else
        {
            return 5;
        }
        case PERMISSION_SESSION:
            return 3;

        case PERMISSION_ONE_SHOT:
        case PERMISSION_DENY_SESSION:
            return 2;

        case PERMISSION_NEVER:
        case PERMISSION_DENY:
        case PERMISSION_USER_DENIED:
            return 1;

        default:
            return 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_get_new_permission_level
 * DESCRIPTION
 *  transfer J2ME_CHOICE_LEVEL to PERMISSION_LEVEL
 * PARAMETERS
 *  choiceLevel     [IN]        Level of J2ME_CHOICE_LEVEL
 * RETURNS
 *  level of PERMISSION_LEVEL
 *****************************************************************************/
S8 mmi_java_get_new_permission_level(S8 choiceLevel, S8 max_settings, S8 org_setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 selected;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (choiceLevel)
    {
        case J2ME_CHOICE_OK:
            if (max_settings == PERMISSION_ALLOW)
                selected = (S8) PERMISSION_ALLOW;
            else
                selected = (S8) PERMISSION_BLANKET_GRANTED;
            break;
        case J2ME_CHOICE_BLANKET:
            if(get_domain_setting)
            {
            if (max_settings == PERMISSION_ALLOW)
                selected = (S8) PERMISSION_ALLOW;
            else
            selected = (S8) PERMISSION_BLANKET_GRANTED;
            }
            else
            {
                selected = (S8) PERMISSION_BLANKET;
            }
            break;
        case J2ME_CHOICE_SESSION:
            selected = (S8) PERMISSION_SESSION;
            break;
        case J2ME_CHOICE_ONESHOT:
            selected = (S8) PERMISSION_ONE_SHOT;
            break;
        case J2ME_CHOICE_USERDENY:
            if (org_setting == PERMISSION_NEVER)
                selected = (S8) PERMISSION_NEVER;
            else
            selected = (S8) PERMISSION_USER_DENIED;
            break;
        default:
            selected = (S8) PERMISSION_USER_DENIED;
            break;
    }

    return selected;
}

#endif /* __J2ME__ */
