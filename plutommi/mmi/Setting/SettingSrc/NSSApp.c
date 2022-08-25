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
 * NotificationSettingSrc.c
 *
 * Project:
 * --------
 *	 MAUI
 *
 * Description:
 * ------------
 *	 This file is intends for Notification manager setting Menus
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *			   HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include Header Files
 *******************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_NSS_SUPPORT__
#include "MMIDataType.h"
#include "gui_typedef.h"
#include "common_nvram_editor_data_item.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "GlobalResDef.h"
#include "wgui_categories_search.h"
#include "CommonScreensResDef.h"/* EVT_ID_ALERT_QUIT */
#include "ProfilesSrvGprot.h" /* SUCCESS_TONE */
#include "CommonScreens.h"    /* DisplayPopup */
#include "MenuCuiGprot.h"     /* cui_menu_event_struct */
#include "wgui_categories_popup.h" /* UI_POPUP_NOTIFYDURATION_TIME */
#include "InlineCuiGprot.h"   /* CUI_INLINE_INSERT_TAIL */
#include "Wgui_categories_util.h"/* register left and right key */

#include "AppMgrSrvGprot.h" /* load mgr app name and icon*/
#include "mmi_rp_app_nss_def.h" /* from NSSApp.res */
#include "NotificationSettingSrvGprot.h"  /*deal with nss appname and app setting from service */
#include "PnSrvGprot.h" /*deal with background data setting*/
#include "mmi_rp_app_phonesetting_new_def.h" /*deault nss app icon of notification settings */

#ifdef __MMI_PNS__
    #include "PnSrvGprot.h" /*deal with background data setting*/
#endif

#include "IdleGProt.h"
#include "FactoryGprot.h"
#include "IdleFactory.h"

static MMI_BOOL g_nss_thumbnail_bitmask[40]; /* for show the icon, which is given the icon's path */
#define TempTestIcon L"D:\\Photos\\SB_Default.gif" /* just local test*/

/* MAX_NSS_ENTRY_NUM static native app num(3) + MRE app num (32)*/ 
#define NSS_APP_MAX_NO 35 
#define NSS_APP_SEL_NO 2
#if defined __MMI_NCENTER_SUPPORT__
    #define NSS_APP_NA_SEL_NO 3
#else
    #define NSS_APP_NA_SEL_NO 2
#endif
#define NSS_APP_SETTING_INLINE_ITEM_NO 10
extern S8 *GetString(U16 StringId);

/* nss app infor in inlin id */
typedef enum 
{
    NSS_APP_CENTER_CAPTION = CUI_INLINE_ITEM_ID_BASE + 1,
    NSS_APP_CENTER_SELECT,
    
    NSS_APP_ALERT_CAPTION, 
    NSS_APP_ALERT_SELECT,
    
    NSS_APP_BADGE_APP_ICON_CAPTION,
    NSS_APP_BADGE_APP_ICON_SELECT,

    NSS_APP_SOUND_CAPTION,
    NSS_APP_SOUND_SELECT,
    
    NSS_APP_LOCK_SCREEN_CAPTION,
    NSS_APP_LOCK_SCREEN_SELECT,

    NSS_APP_POPUP_CAPTION,
    NSS_APP_POPUP_SELECT
}nss_app_setting_inline_itemid_enum; 

const U16 g_nss_sel_of[NSS_APP_SEL_NO]={STR_GLOBAL_OFF, STR_GLOBAL_ON};

#if defined __MMI_NCENTER_SUPPORT__
    const U16 g_nss_sel_NA[NSS_APP_NA_SEL_NO]={
                STR_ID_APPNAME_NOTIFICATION_ALERT_NONE, 
                STR_ID_APPNAME_NOTIFICATION_ALERT_POPUP, 
                STR_ID_APPNAME_NOTIFICATION_ALERT_STATUSBAR};
#else
    const U16 g_nss_sel_NA[NSS_APP_NA_SEL_NO]={
                STR_ID_APPNAME_NOTIFICATION_ALERT_NONE, 
                STR_ID_APPNAME_NOTIFICATION_ALERT_POPUP};
#endif


/* Notification Center */
static const cui_inline_item_caption_struct nss_app_nc_caption = {STR_ID_APPNAME_NOTIFICATION_CENTER};
static const cui_inline_item_select_struct nss_app_nc_select = {
        NSS_APP_SEL_NO, 
        0, 
        g_nss_sel_of};
/* Notification Alert */
static const cui_inline_item_caption_struct nss_app_na_caption = {STR_ID_APPNAME_NOTIFICATION_ALERT};
static const cui_inline_item_select_struct nss_app_na_select = {
        NSS_APP_NA_SEL_NO, 
        0, 
        g_nss_sel_NA};
/* Notification Badge app icon */
static const cui_inline_item_caption_struct nss_app_bai_caption = {STR_ID_APPNAME_BADGE_APP_ICON};
static const cui_inline_item_select_struct nss_app_bai_select = {
        NSS_APP_SEL_NO, 
        0, 
        g_nss_sel_of};
/* Sound */
static const cui_inline_item_caption_struct nss_app_sound_caption = {STR_ID_APPNAME_SOUND};
static const cui_inline_item_select_struct nss_app_sound_select = {
        NSS_APP_SEL_NO, 
        0, 
        g_nss_sel_of};
/* View in lock screen */
static const cui_inline_item_caption_struct nss_app_vils_caption = {STR_ID_APPNAME_VIEW_IN_LOCK_SCREEN};
static const cui_inline_item_select_struct nss_app_vils_select = {
        NSS_APP_SEL_NO, 
        0, 
        g_nss_sel_of};
/* Popup 
static const cui_inline_item_caption_struct nss_app_popup_caption = {STR_ID_APPNAME_POPUP};
static const cui_inline_item_select_struct nss_app_popup_select = {
        NSS_APP_SEL_NO, 
        0, 
        g_nss_sel_of};
*/
/* nss app inline item softkey struct */
const cui_inline_item_softkey_struct g_nss_app_inline_softkey = {
        {{CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0}, 
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0}, 
        {0, CUI_INLINE_SOFTKEY_DEFAULT_VALUE}} };

/* nss app inline item struct and inline struct */
static const cui_inline_set_item_struct g_nss_app_inline_item[] = {
    {
        NSS_APP_CENTER_CAPTION, 
        CUI_INLINE_ITEM_TYPE_CAPTION, 
        0, 
        (void*)&nss_app_nc_caption},    
    {
        NSS_APP_CENTER_SELECT, 
        CUI_INLINE_ITEM_TYPE_SELECT, 
        0, 
        (void*)&nss_app_nc_select},
    {
        NSS_APP_ALERT_CAPTION, 
        CUI_INLINE_ITEM_TYPE_CAPTION, 
        0, 
        (void*)&nss_app_na_caption},    
    {
        NSS_APP_ALERT_SELECT, 
        CUI_INLINE_ITEM_TYPE_SELECT, 
        0, 
        (void*)&nss_app_na_select},
    {
        NSS_APP_BADGE_APP_ICON_CAPTION, 
        CUI_INLINE_ITEM_TYPE_CAPTION, 
        0, 
        (void*)&nss_app_bai_caption},    
    {
        NSS_APP_BADGE_APP_ICON_SELECT,
        CUI_INLINE_ITEM_TYPE_SELECT, 
        0, 
        (void*)&nss_app_bai_select},
    {
        NSS_APP_SOUND_CAPTION, 
        CUI_INLINE_ITEM_TYPE_CAPTION, 
        0, 
        (void*)&nss_app_sound_caption},    
    {
        NSS_APP_SOUND_SELECT, 
        CUI_INLINE_ITEM_TYPE_SELECT, 
        0,
        (void*)&nss_app_sound_select},
    {
        NSS_APP_LOCK_SCREEN_CAPTION, 
        CUI_INLINE_ITEM_TYPE_CAPTION, 
        0, 
        (void*)&nss_app_vils_caption},    
    {
        NSS_APP_LOCK_SCREEN_SELECT, 
        CUI_INLINE_ITEM_TYPE_SELECT, 
        0, 
        (void*)&nss_app_vils_select}
    /*,
    {
        NSS_APP_POPUP_CAPTION,
        CUI_INLINE_ITEM_TYPE_CAPTION, 
        0, 
        (void*)&nss_app_popup_caption},    
    {
        NSS_APP_POPUP_SELECT, 
        CUI_INLINE_ITEM_TYPE_SELECT,
        0, 
        (void*)&nss_app_popup_select}
    */
    };
const cui_inline_struct g_nss_app_inline_struct={
    NSS_APP_SETTING_INLINE_ITEM_NO,
    STR_ID_SETTING_NOTIFICATIONSETTINGS,
    0,
    CUI_INLINE_SCREEN_LOOP|CUI_INLINE_SCREEN_DISABLE_DONE,
    &g_nss_app_inline_softkey,
    g_nss_app_inline_item};  

typedef enum
{
    /* NSS_MASK_BADGE_ICON */
    NSS_KEY_BADGE_ICON,     
    /* NSS_MASK_SOUND */
    NSS_KEY_SOUND,      
    /* NSS_MASK_LOCK_SCRN */
    NSS_KEY_LOCK_SCRN,   
    /* NSS_MASK_NCENTER */
    NSS_KEY_NCENTER,       
    /* NSS_KEY_POPUP 
    NSS_KEY_POPUP, */  
    /* NSS_KEY_ALERT */
    NSS_KEY_ALERT, 
    NSS_KEY_MAX
} mmi_nss_app_key_enum;
/* current app setting key struct */
typedef struct
{
    U32  nss_app_setting_value;
    MMI_BOOL  nss_app_setting_cf; /* determine if setting is configurable or not */
} mmi_nss_app_key_struct;

/* nss list infor and nss app setting infor*/
typedef struct
{
    mmi_srv_nss_node nss_app_node[NSS_APP_MAX_NO];
    U32 nss_app_number;
    U32 nss_list_number;
    U32 nss_highlight_appname_index;
    U32 nss_highlight_list_index;
    U32 nss_highlight_bkgdata_index;
    mmi_nss_app_key_struct  nss_app_setting_stuct[NSS_KEY_MAX];
} mmi_nss_app_struct;

mmi_nss_app_struct g_mmi_nss_cxt;
U32 g_app_index[NSS_APP_MAX_NO] = {0};
static void mmi_nss_app_setting_count_valid_app(U32 count)
{
    nss_setting_key_enum index;
    U16 setting_value;
    U32 app_index;
	S8  i=0;
    MMI_BOOL ret = MMI_FALSE;
    for(app_index = 0; app_index < count; app_index++)
    {
        for(index = NSS_SETTING_BADGE_ICON; index <= NSS_SETTING_ALERT; index++)
          {
			if(MMI_RET_OK == mmi_srv_nss_get_setting(g_mmi_nss_cxt.nss_app_node[app_index].app_id, index, &setting_value))
             {
              #ifdef __MMI_LAUNCHER_APP_LIST__
			  if(mmi_factory_get_favorite_type(mmi_idle_get_cfg_table())== MMI_IDLE_TYPE_CLASSIC || mmi_factory_get_favorite_type(mmi_idle_get_cfg_table()) == MMI_IDLE_TYPE_APPLIST)
		        {
                   ret = MMI_FALSE;
		           switch(index)// fruit launcher do not support  BADGE
		   	        {
		   	         case NSS_KEY_BADGE_ICON:
  				         ret = MMI_TRUE;
				         break;
			             default:
			  	         break;
		   	         }
		            if(ret)
                    {
  			         continue;
                    } 
		        }
			  #endif
			    break;
			}
         }
		
     if(index  == NSS_SETTING_MAX )
       g_mmi_nss_cxt.nss_app_number--;
     else
       g_app_index[i++] = app_index;
    }
}

static U32 mmi_nss_app_setting_get_app_index(U32 index)
{
   if(index >= 0 && index <= g_mmi_nss_cxt.nss_app_number)
     return g_app_index[index];
   else
     ASSERT(0);
     return NULL;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_nss_get_applist_infor
 * DESCRIPTION
 *  get list infor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nss_get_applist_infor(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_srv_nss_node nss_node;
    U32 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_nss_cxt.nss_app_number = mmi_srv_nss_get_node_num();
	memset(&nss_node, 0, sizeof(mmi_srv_nss_node));
    if (g_mmi_nss_cxt.nss_app_number > NSS_APP_MAX_NO)
    {
        ASSERT(0);
    }
    for(index = 0; index < g_mmi_nss_cxt.nss_app_number; index++)
    {
        mmi_srv_nss_get_node_by_index(index, &nss_node);
        /*if(nss_node.app_id != NULL)*/
        {
            memcpy(&(g_mmi_nss_cxt.nss_app_node[index]), &nss_node, sizeof(mmi_srv_nss_node));
        }
    } 
    mmi_nss_app_setting_count_valid_app(g_mmi_nss_cxt.nss_app_number);
    #ifdef __MMI_PNS__
        g_mmi_nss_cxt.nss_list_number = g_mmi_nss_cxt.nss_app_number + 1;
        if(srv_pns_get_global_setting()) /*background data value in srv, 1 is ON, 0 is OFF*/
        {
            /* but in setting app: background data, index 0 is ON, index 1 is OFF*/
            g_mmi_nss_cxt.nss_highlight_bkgdata_index = 0;
        }
        else
        {
            /* but in setting app: background data, index 0 is ON, index 1 is OFF */
            g_mmi_nss_cxt.nss_highlight_bkgdata_index = 1;
        }
    #else
        g_mmi_nss_cxt.nss_list_number = g_mmi_nss_cxt.nss_app_number;
    #endif 
#if 0
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
}


#ifdef __MMI_PNS__
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
mmi_ret mmi_nss_bd_comfirm_proc(mmi_event_struct *evt)
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
                    mmi_frm_scrn_close(GRP_ID_NSS_GROUP, SRN_ID_NSS_BACKGROUND_DATA_SCREEN);
                    break;
                }
                case MMI_ALERT_CNFM_YES:
                {
                    if(g_mmi_nss_cxt.nss_highlight_bkgdata_index)/*index 1 is stringOFF*/
                    {
                         srv_pns_switch_global_setting(SRV_PNS_SETTING_OFF);;
                    }
                    else/*index 0 is stringON*/
                    {
                         srv_pns_switch_global_setting(SRV_PNS_SETTING_ON);
                    }
                    mmi_frm_group_close(alert->alert_id);
                    mmi_frm_scrn_close(GRP_ID_NSS_GROUP, SRN_ID_NSS_BACKGROUND_DATA_SCREEN);
                    break;
                }
                case MMI_ALERT_CNFM_NO:
                {
                    mmi_frm_group_close(alert->alert_id);
                    mmi_frm_scrn_close(GRP_ID_NSS_GROUP, SRN_ID_NSS_BACKGROUND_DATA_SCREEN);
                    if(srv_pns_get_global_setting()) /*background data value in srv, 1 is ON, 0 is OFF*/
                    {
                        /* but in setting app: background data, index 0 is ON, index 1 is OFF*/
                        g_mmi_nss_cxt.nss_highlight_bkgdata_index = 0;
                    }
                    else
                    {
                        /* but in setting app: background data, index 0 is ON, index 1 is OFF */
                        g_mmi_nss_cxt.nss_highlight_bkgdata_index = 1;
                    }
                    break;
                }
                default:
                    break;
            }
        }
        default:
        {
            break;
        }        
    }
	return MMI_RET_OK;
}
#endif /*__MMI_PNS__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_nss_applist_bgdata_scrn_save
 * DESCRIPTION
 *  at background data screen the save deal with
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nss_applist_bgdata_scrn_save(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* save  */
    #ifdef __MMI_PNS__
        mmi_confirm_property_struct arg;  
        /*mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_NSS_GROUP, NULL);*/
        //mmi_popup_display_simple_ext(STR_ID_SETTING_BACKGROUND_DATA_RESULT, MMI_EVENT_QUERY, GRP_ID_NSS_GROUP, NULL);

		if(g_mmi_nss_cxt.nss_highlight_bkgdata_index)/*index 1 is stringOFF*/
		{
            //srv_pns_switch_global_setting(SRV_PNS_SETTING_ON);
            mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
			//arg.f_msg_icon = 0;
            arg.parent_id = GRP_ID_NSS_GROUP;
            arg.callback = (mmi_proc_func)mmi_nss_bd_comfirm_proc;
            mmi_confirm_display(
                (WCHAR*)get_string(STR_ID_SETTING_BACKGROUND_DATA_RESULT),
                MMI_EVENT_QUERY,
                &arg);
            return;
		}
		else/*index 0 is stringON*/
		{
			 //srv_pns_switch_global_setting(SRV_PNS_SETTING_OFF);
             srv_pns_switch_global_setting(SRV_PNS_SETTING_ON);
			 mmi_frm_scrn_close(GRP_ID_NSS_GROUP, SRN_ID_NSS_BACKGROUND_DATA_SCREEN);
        }
    #endif /*__MMI_PNS__*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_nss_bgdata_sproc
 * DESCRIPTION
 * pro background data seting screen
 * PARAMETERS
 *  evt    : [IN] mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_nss_bgdata_sproc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *Itemlist_text[2];
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    U8 nItems = 2;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (evt->evt_id)
	{
        case EVT_ID_SCRN_ACTIVE:
        	{
                Itemlist_text[0] = (U8*)GetString(STR_GLOBAL_ON);
                Itemlist_text[1] = (U8*)GetString(STR_GLOBAL_OFF);
                ShowCategory109Screen_ext(
                    (U8*)get_string(STR_ID_SETTING_NOTIFICATIONSETTINGS_BACKGROUND_DATA),
                    0,
                    (U8*)GetString(STR_GLOBAL_SAVE),
                    0,
                    (U8*)GetString(STR_GLOBAL_BACK),
                    0,
                    nItems,
                    Itemlist_text,
                    NULL,
                    (U16)(g_mmi_nss_cxt.nss_highlight_bkgdata_index),
                    guiBuffer);
                EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
                SetCenterSoftkeyFunction(mmi_nss_applist_bgdata_scrn_save, KEY_EVENT_UP);
        		break;
        	}
        case EVT_ID_SCRN_HIGHLIGHT_CHANGE:
            {
                g_mmi_nss_cxt.nss_highlight_bkgdata_index = menu_evt->sender_id;
                break;
            }
        case EVT_ID_WGUI_LSK_CLICK:
        case EVT_ID_WGUI_CSK_CLICK:
            {
                mmi_nss_applist_bgdata_scrn_save();
                break;
            }

	}
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nss_app_setting_save_info
 * DESCRIPTION
 *  save nss app settings infor to service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nss_app_setting_save_info()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    MMI_ID app_id; 
    mmi_nss_app_key_enum i;
    mmi_ret ret = MMI_RET_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    /* save infor to service */
    index = g_mmi_nss_cxt.nss_highlight_appname_index;
    app_id = g_mmi_nss_cxt.nss_app_node[mmi_nss_app_setting_get_app_index(index)].app_id;
    for(i = NSS_KEY_BADGE_ICON; i < NSS_KEY_MAX; i++)
    {
        if (g_mmi_nss_cxt.nss_app_setting_stuct[i].nss_app_setting_cf)
        {
            switch (i)
            {
            case NSS_KEY_NCENTER:
                {
                    ret = mmi_srv_nss_set_setting(
                                app_id, 
                                NSS_SETTING_NCENTER, 
                                g_mmi_nss_cxt.nss_app_setting_stuct[NSS_KEY_NCENTER].nss_app_setting_value);
                    break;
                }
            
            case NSS_KEY_ALERT:
                {
                    ret = mmi_srv_nss_set_setting(
                                app_id, 
                                NSS_SETTING_ALERT, 
                                g_mmi_nss_cxt.nss_app_setting_stuct[NSS_KEY_ALERT].nss_app_setting_value);
                    break;
                }
            
            case NSS_KEY_BADGE_ICON:
                {
                    ret = mmi_srv_nss_set_setting(
                                app_id, 
                                NSS_SETTING_BADGE_ICON, 
                                g_mmi_nss_cxt.nss_app_setting_stuct[NSS_KEY_BADGE_ICON].nss_app_setting_value);
                    break; 
                }
                
            case NSS_KEY_SOUND:
                {
                    ret = mmi_srv_nss_set_setting(
                                app_id, 
                                NSS_SETTING_SOUND, 
                                g_mmi_nss_cxt.nss_app_setting_stuct[NSS_KEY_SOUND].nss_app_setting_value);
                    break;
                }  

            case NSS_KEY_LOCK_SCRN:
                {
                    ret = mmi_srv_nss_set_setting(
                                app_id, 
                                NSS_SETTING_LOCK_SCRN, 
                                g_mmi_nss_cxt.nss_app_setting_stuct[NSS_KEY_LOCK_SCRN].nss_app_setting_value);
                    break;
                }
                /*
            case NSS_KEY_POPUP:
                {
                    ret = mmi_srv_nss_set_setting(
                               app_id, 
                               NSS_SETTING_POPUP, 
                               g_mmi_nss_cxt.nss_app_setting_stuct[NSS_KEY_POPUP].nss_app_setting_value);
                    break;
                }
                */
            }  
        }
        if (ret == MMI_RET_OK) 
        {
            continue;
        }
        else
        {
            break;
        }
        
    }
    MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, 
              MMI_NSS_APP_SET_INFOR, 
              app_id, 
              g_mmi_nss_cxt.nss_app_setting_stuct[NSS_SETTING_BADGE_ICON].nss_app_setting_value,
              g_mmi_nss_cxt.nss_app_setting_stuct[NSS_SETTING_BADGE_ICON].nss_app_setting_cf,
              g_mmi_nss_cxt.nss_app_setting_stuct[NSS_SETTING_SOUND].nss_app_setting_value,
              g_mmi_nss_cxt.nss_app_setting_stuct[NSS_SETTING_SOUND].nss_app_setting_cf,
              g_mmi_nss_cxt.nss_app_setting_stuct[NSS_SETTING_LOCK_SCRN].nss_app_setting_value,
              g_mmi_nss_cxt.nss_app_setting_stuct[NSS_SETTING_LOCK_SCRN].nss_app_setting_cf,
              g_mmi_nss_cxt.nss_app_setting_stuct[NSS_SETTING_NCENTER].nss_app_setting_value,
              g_mmi_nss_cxt.nss_app_setting_stuct[NSS_SETTING_NCENTER].nss_app_setting_cf,
              g_mmi_nss_cxt.nss_app_setting_stuct[NSS_SETTING_ALERT].nss_app_setting_value,
              g_mmi_nss_cxt.nss_app_setting_stuct[NSS_SETTING_ALERT].nss_app_setting_cf,
              ret);
    if (ret == MMI_RET_OK) 
    {
        mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_NSS_GROUP, NULL);
    }
    else
    {
        mmi_popup_display_simple_ext(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE, GRP_ID_NSS_GROUP, NULL);
    }
   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nss_app_setting_notify_changed
 * DESCRIPTION
 * The pro for nss app setting in setting
 * PARAMETERS
 *  evt    : [IN] cui_event_inline_notify_struct
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nss_app_setting_notify_changed(cui_event_inline_notify_struct *notify_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 temp_select_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    cui_inline_get_value(notify_event->sender_id, notify_event->item_id, (void*)(&temp_select_index));
    switch(notify_event->item_id)
    {
    case NSS_APP_CENTER_SELECT:
        g_mmi_nss_cxt.nss_app_setting_stuct[NSS_KEY_NCENTER].nss_app_setting_value= temp_select_index;
        break;
                
    case NSS_APP_LOCK_SCREEN_SELECT:
        g_mmi_nss_cxt.nss_app_setting_stuct[NSS_KEY_LOCK_SCRN].nss_app_setting_value= temp_select_index;
        break;

    case NSS_APP_ALERT_SELECT:
        g_mmi_nss_cxt.nss_app_setting_stuct[NSS_KEY_ALERT].nss_app_setting_value= temp_select_index;
        break;
      
    case NSS_APP_BADGE_APP_ICON_SELECT:
        g_mmi_nss_cxt.nss_app_setting_stuct[NSS_KEY_BADGE_ICON].nss_app_setting_value= temp_select_index;
        break;
      
    case NSS_APP_SOUND_SELECT:
        g_mmi_nss_cxt.nss_app_setting_stuct[NSS_KEY_SOUND].nss_app_setting_value= temp_select_index;
        break;
    /*
    case NSS_APP_POPUP_SELECT:
        g_mmi_nss_cxt.nss_app_setting_stuct[NSS_KEY_POPUP].nss_app_setting_value= temp_select_index;
        break;
    */    
    default:
        //MMI_ASSERT(0);
        break; 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nss_app_setting_get_info
 * DESCRIPTION
 *  get nss app key setting in setting
 * PARAMETERS
 *  void   
 * RETURNS
 *  void  
 *****************************************************************************/
void mmi_nss_app_setting_get_info()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID app_id;
    nss_setting_key_enum index;
    U16 setting_value;
	MMI_BOOL ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    app_id = g_mmi_nss_cxt.nss_app_node[mmi_nss_app_setting_get_app_index(g_mmi_nss_cxt.nss_highlight_appname_index)].app_id;
    for(index = NSS_SETTING_BADGE_ICON; index <= NSS_SETTING_ALERT; index++)
    {
        #ifdef __MMI_LAUNCHER_APP_LIST__
        if(mmi_factory_get_favorite_type(mmi_idle_get_cfg_table())== MMI_IDLE_TYPE_CLASSIC || mmi_factory_get_favorite_type(mmi_idle_get_cfg_table()) == MMI_IDLE_TYPE_APPLIST)
		 {
		   ret = MMI_FALSE;
		   switch(index)// fruit launcher do not support  BADGE
		   	{
		   	  case NSS_KEY_BADGE_ICON:
			 	    g_mmi_nss_cxt.nss_app_setting_stuct[index].nss_app_setting_cf = MMI_FALSE;
  					ret = MMI_TRUE;
					break;
			  default:
			  	    break;
		   	}
		     if(ret)
			 	continue;
		 }
		#endif
        if(MMI_RET_OK == mmi_srv_nss_get_setting(app_id, index, &setting_value))
        {
            g_mmi_nss_cxt.nss_app_setting_stuct[index].nss_app_setting_cf = MMI_TRUE;
            g_mmi_nss_cxt.nss_app_setting_stuct[index].nss_app_setting_value = setting_value;
        }
        else
        {
            g_mmi_nss_cxt.nss_app_setting_stuct[index].nss_app_setting_cf = MMI_FALSE;
        }
    }
    MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, 
              MMI_NSS_APP_GET_INFOR, 
              app_id, 
              g_mmi_nss_cxt.nss_app_setting_stuct[NSS_SETTING_BADGE_ICON].nss_app_setting_value,
              g_mmi_nss_cxt.nss_app_setting_stuct[NSS_SETTING_BADGE_ICON].nss_app_setting_cf,
              g_mmi_nss_cxt.nss_app_setting_stuct[NSS_SETTING_SOUND].nss_app_setting_value,
              g_mmi_nss_cxt.nss_app_setting_stuct[NSS_SETTING_SOUND].nss_app_setting_cf,
              g_mmi_nss_cxt.nss_app_setting_stuct[NSS_SETTING_LOCK_SCRN].nss_app_setting_value,
              g_mmi_nss_cxt.nss_app_setting_stuct[NSS_SETTING_LOCK_SCRN].nss_app_setting_cf,
              g_mmi_nss_cxt.nss_app_setting_stuct[NSS_SETTING_NCENTER].nss_app_setting_value,
              g_mmi_nss_cxt.nss_app_setting_stuct[NSS_SETTING_NCENTER].nss_app_setting_cf,
              g_mmi_nss_cxt.nss_app_setting_stuct[NSS_SETTING_ALERT].nss_app_setting_value,
              g_mmi_nss_cxt.nss_app_setting_stuct[NSS_SETTING_ALERT].nss_app_setting_cf);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nss_app_inline_key_select_value
 * DESCRIPTION
 *  set select value base the key whether is configable
 * PARAMETERS
 *  mmi_id g_inline [IN]  
 * RETURNS
 *  void  
 *****************************************************************************/
void mmi_nss_app_inline_key_select_value(mmi_id g_inline)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nss_app_key_enum i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    for(i = NSS_KEY_BADGE_ICON; i < NSS_KEY_MAX; i++)
    {
        if (g_mmi_nss_cxt.nss_app_setting_stuct[i].nss_app_setting_cf)
        {
        switch (i)
        {
            case NSS_KEY_NCENTER:
                {
                    cui_inline_set_value(
                        g_inline, 
                        NSS_APP_CENTER_SELECT, 
                        (void *)(g_mmi_nss_cxt.nss_app_setting_stuct[i].nss_app_setting_value));
                    break;
                }
            
            case NSS_KEY_ALERT:
                {
                    cui_inline_set_value(
                        g_inline, 
                        NSS_APP_ALERT_SELECT, 
                        (void *)(g_mmi_nss_cxt.nss_app_setting_stuct[i].nss_app_setting_value));
                    break;
                }
            
            case NSS_KEY_BADGE_ICON:
                {
                    cui_inline_set_value(
                        g_inline, 
                        NSS_APP_BADGE_APP_ICON_SELECT, 
                        (void *)(g_mmi_nss_cxt.nss_app_setting_stuct[i].nss_app_setting_value));
                    break; 
                }
                
            case NSS_KEY_SOUND:
                {
                    cui_inline_set_value(
                        g_inline, 
                        NSS_APP_SOUND_SELECT, 
                        (void *)(g_mmi_nss_cxt.nss_app_setting_stuct[i].nss_app_setting_value));
                    break;
                }  

            case NSS_KEY_LOCK_SCRN:
                {
                    cui_inline_set_value(
                        g_inline, 
                        NSS_APP_LOCK_SCREEN_SELECT, 
                        (void *)(g_mmi_nss_cxt.nss_app_setting_stuct[i].nss_app_setting_value));
                    break;
                }
            /*
            case NSS_KEY_POPUP:
                {
                    cui_inline_set_value(
                        g_inline, 
                        NSS_APP_POPUP_SELECT, 
                        (void *)(g_mmi_nss_cxt.nss_app_setting_stuct[i].nss_app_setting_value));
                    break;
                } 
            */
            }  
        }
        continue;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nss_app_setting_inline_infor_pre
 * DESCRIPTION
 *  prepare infor for current app setting key item
 * PARAMETERS
 *  mmi_id gapp_inline [IN]   
 * RETURNS
 *  void  
 *****************************************************************************/
void mmi_nss_app_setting_inline_infor_pre(mmi_id gapp_inline)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static srv_app_info_struct info;
    U32 index = mmi_nss_app_setting_get_app_index(g_mmi_nss_cxt.nss_highlight_appname_index);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  

    /* fill the current nss app setting about value and configable */
    mmi_nss_app_setting_get_info();

    /* set title for app setting */
    if (DOWNLOAD_APP_TYPE == g_mmi_nss_cxt.nss_app_node[g_mmi_nss_cxt.nss_highlight_appname_index].app_type)
    {
        //srv_appmgr_get_app_package_info(g_mmi_nss_cxt.nss_app_node[index].app_info.mre_res.app_mre_package_name, &info);
        {
            mmi_app_package_name_struct appPackageName;
            srv_appmgr_get_app_package_name_by_id(g_mmi_nss_cxt.nss_app_node[index].app_id, appPackageName);
            srv_appmgr_get_app_package_info(appPackageName, &info);
        }
        cui_inline_set_title_string(gapp_inline, (WCHAR *)(info.string));
    }
    else /* NATIVE_APP_TYPE */
    {
        cui_inline_set_title(gapp_inline, g_mmi_nss_cxt.nss_app_node[index].app_info.native_res.app_str_id,0);
    }

    /* set select value base the key whether is configable */
    mmi_nss_app_inline_key_select_value(gapp_inline);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nss_app_entry
 * DESCRIPTION
 *  entry nss app setting in setting
 * PARAMETERS
 *  void   
 * RETURNS
 *  void  
 *****************************************************************************/
void mmi_nss_app_entry()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id gapp_inline;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    gapp_inline = cui_inline_create(GRP_ID_NSS_GROUP, &g_nss_app_inline_struct);
    mmi_nss_app_setting_inline_infor_pre(gapp_inline);
    cui_inline_run(gapp_inline);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nss_applist_item_ok
 * DESCRIPTION
 *  enter app list and background data 
 * PARAMETERS
 * void 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nss_applist_item_ok(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (g_mmi_nss_cxt.nss_highlight_list_index == 0) /* background data */
    {
        #ifdef __MMI_PNS__
            mmi_frm_scrn_create(
            GRP_ID_NSS_GROUP, 
            SRN_ID_NSS_BACKGROUND_DATA_SCREEN, 
            mmi_nss_bgdata_sproc, 
            NULL);
        #else
            mmi_nss_app_entry();
        #endif
    }
    else /* others are notification settings app */
    {
        mmi_nss_app_entry();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nss_applist_seperate_line
 * DESCRIPTION
 *  Set the separator line in the add recipient screen
 * PARAMETERS
 *  index       [IN]    The list item index
 *  flag        [OUT]   UI Menu Item Flag
 *  flag_ex     [OUT]   UI Menu Item Extension Flag      
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_nss_applist_seperate_line(S32 index, U32 *flag, U32 *flag_ex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 0)
    {
        *flag |= UI_MENUITEM_DISABLE_ICON;
        *flag_ex |= UI_MENUITEM_EXT_SHOW_DOWN_SEPARATORLINE;
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nss_getapp_listitem
 * DESCRIPTION
 * fill the items of the nss appname list
 * PARAMETERS
 *  start_index    : [IN] S32 Start index of menu item
 *  menu_data      : [OUT] menu_data A pointer of parameter to store the menu data
 *  data_size      : [IN] S32 The number of load menu items
 * RETURNS
 *  S32
 * RETURN VALUES
 *  Number of items can be retrieved
 *****************************************************************************/
static S32 mmi_nss_getapp_listitem(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    srv_app_info_struct info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	for(i = 0; i < data_size; i++)
	{
	#ifdef __MMI_PNS__
	    if ((start_index == 0) && (i == 0))
        {
            mmi_ucs2cpy((S8*)menu_data[0].item_list[0], 
                       (S8*)GetString(STR_ID_SETTING_NOTIFICATIONSETTINGS_BACKGROUND_DATA));
            continue;
        }
	    if(DOWNLOAD_APP_TYPE == g_mmi_nss_cxt.nss_app_node[mmi_nss_app_setting_get_app_index(start_index + i -1)].app_type)
        {
            //srv_appmgr_get_app_package_info(g_mmi_nss_cxt.nss_app_node[start_index + i -1].app_info.mre_res.app_mre_package_name, &info);

			{
                mmi_app_package_name_struct appPackageName;
                srv_appmgr_get_app_package_name_by_id(g_mmi_nss_cxt.nss_app_node[mmi_nss_app_setting_get_app_index(start_index + i -1)].app_id, appPackageName);
                srv_appmgr_get_app_package_info(appPackageName, &info);
                mmi_ucs2cpy((S8*)menu_data[i].item_list[0], (const CHAR *)info.string);
            }
			#if 0
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
        }
        else /* NATIVE_APP_TYPE */
        {
            mmi_ucs2cpy(
                (S8*)menu_data[i].item_list[0], 
                (S8*)GetString(g_mmi_nss_cxt.nss_app_node[mmi_nss_app_setting_get_app_index(start_index + i -1)].app_info.native_res.app_str_id));
            menu_data[i].image_list[0] = (U8*)GetImage(g_mmi_nss_cxt.nss_app_node[mmi_nss_app_setting_get_app_index(start_index + i -1)].app_info.native_res.app_image_id);
        }
    #else
        if(DOWNLOAD_APP_TYPE == g_mmi_nss_cxt.nss_app_node[mmi_nss_app_setting_get_app_index(start_index + i)].app_type)
        {
        
            //srv_appmgr_get_app_package_info(g_mmi_nss_cxt.nss_app_node[start_index + i].app_info.mre_res.app_mre_package_name, &info);
            {
                mmi_app_package_name_struct appPackageName;
                srv_appmgr_get_app_package_name_by_id(g_mmi_nss_cxt.nss_app_node[mmi_nss_app_setting_get_app_index(start_index + i)].app_id, appPackageName);
                srv_appmgr_get_app_package_info(appPackageName, &info);
                mmi_ucs2cpy((S8*)menu_data[i].item_list[0], info.string);
            }
			#if 0
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
        }
        else /* NATIVE_APP_TYPE */
        {
            mmi_ucs2cpy(
                (S8*)menu_data[i].item_list[0], 
                (S8*)GetString(g_mmi_nss_cxt.nss_app_node[mmi_nss_app_setting_get_app_index(start_index + i)].app_info.native_res.app_str_id));
            menu_data[i].image_list[0] = (U8*)GetImage(g_mmi_nss_cxt.nss_app_node[mmi_nss_app_setting_get_app_index(start_index + i)].app_info.native_res.app_image_id);
        }
    #endif
	}
    return data_size;
} 


/*****************************************************************************
 * FUNCTION
 *  mmi_nss_get_bkgdata_hint
 * DESCRIPTION
 *  get nss background data hint 0 index is on, 1 index is off, while on enum is 1, off enum is 0
 * PARAMETERS
 *  start_index      :    [IN]     Start index of menu item
 *  hint_array       :    [OUT]    A pointer of parameter to store the hint
 * RETURNS
 *  S32
 * RETURN VALUES
 *  The number of hints loaded  :  Success to get the hint
 *  0                           :  Fail to get the hint
 *****************************************************************************/
static S32 mmi_nss_get_bkgdata_hint(S32 start_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (start_index == 0)
    {
        #ifdef __MMI_PNS__
            if(srv_pns_get_global_setting())
            {
                hint_array[0] = (U16*)GetString(STR_GLOBAL_ON);
                g_mmi_nss_cxt.nss_highlight_bkgdata_index = 0;
            }
            else
            {
                hint_array[0] = (U16*)GetString(STR_GLOBAL_OFF);
                g_mmi_nss_cxt.nss_highlight_bkgdata_index = 1;
            }
        #endif
        return 1;/* One hint data only, can be more hints. */
    }
    else
    {
        return 0;
    }
}

MMI_BOOL mmi_nss_list_thumbnail_get_image(S32 item_idx, wgui_thumbnail_img_info_struct* img_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_app_info_struct info;
    CHAR tmp[MMI_MAX_FILE_NAME_LEN * 2] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PNS__
    if (item_idx == 0)
    {
        return MMI_FALSE;
    }
    if(g_mmi_nss_cxt.nss_app_node[mmi_nss_app_setting_get_app_index(item_idx-1)].app_type == DOWNLOAD_APP_TYPE)
    { 
        //srv_appmgr_get_app_package_info(g_mmi_nss_cxt.nss_app_node[item_idx-1].app_info.mre_res.app_mre_package_name, &info); 
        {
            mmi_app_package_name_struct appPackageName;
            srv_appmgr_get_app_package_name_by_id(g_mmi_nss_cxt.nss_app_node[mmi_nss_app_setting_get_app_index(item_idx - 1)].app_id, appPackageName);
            srv_appmgr_get_app_package_info(appPackageName, &info);
        }
		if (info.image.type == MMI_IMAGE_SRC_TYPE_ROM_MEMORY || info.image.type == MMI_IMAGE_SRC_TYPE_MEM)
		{
			img_info->img_ptr = info.image.data.image.image_ptr;   
			img_info->img_size = info.image.data.image.image_len;
			img_info->img_src = WGUI_THUMBNAIL_IMG_SRC_TYPE_MEMORY;
			return MMI_TRUE;
        }
		else if(info.image.type == MMI_IMAGE_SRC_TYPE_RES_ID)
	    {
	        img_info->img_ptr = (U8*)GetImage((U16)(info.image.data.res_id));
			img_info->img_src = WGUI_THUMBNAIL_IMG_SRC_TYPE_RESOURCE;
			return MMI_TRUE;
		}

    }
#else
    if(g_mmi_nss_cxt.nss_app_node[mmi_nss_app_setting_get_app_index(item_idx)].app_type == DOWNLOAD_APP_TYPE)
    {

       //srv_appmgr_get_app_package_info(g_mmi_nss_cxt.nss_app_node[item_idx-1].app_info.mre_res.app_mre_package_name, &info); 
        {
            mmi_app_package_name_struct appPackageName;
            srv_appmgr_get_app_package_name_by_id(g_mmi_nss_cxt.nss_app_node[(item_idx - 1)].app_id, appPackageName);
            srv_appmgr_get_app_package_info(appPackageName, &info);
        }
	   if (info.image.type == MMI_IMAGE_SRC_TYPE_ROM_MEMORY || info.image.type == MMI_IMAGE_SRC_TYPE_MEM)
		{
			img_info->img_ptr = info.image.data.image.image_ptr;   
			img_info->img_size = info.image.data.image.image_len;
			img_info->img_src = WGUI_THUMBNAIL_IMG_SRC_TYPE_MEMORY;
			return MMI_TRUE;
        }
		else if(info.image.type == MMI_IMAGE_SRC_TYPE_RES_ID)
	    {
	        img_info->img_ptr = (U8*)GetImage((U16)(info.image.data.res_id));
			img_info->img_src = WGUI_THUMBNAIL_IMG_SRC_TYPE_RESOURCE;
			return MMI_TRUE;
		}
    }
#endif
	return MMI_FALSE;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_nss_list_thumbnail_get_image_path
 * DESCRIPTION
 *  register each menuitem icon path
 * PARAMETERS
 *  S32 item_idx [in] 
 *  CHAR *path out [in, out]
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_nss_list_thumbnail_get_image_path(S32 item_idx, CHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_app_info_struct info;
    CHAR tmp[MMI_MAX_FILE_NAME_LEN * 2] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_PNS__
        if (item_idx == 0)
        {
            return MMI_FALSE;
        }
        if(g_mmi_nss_cxt.nss_app_node[mmi_nss_app_setting_get_app_index(item_idx-1)].app_type == DOWNLOAD_APP_TYPE)
        {
     
            //srv_appmgr_get_app_package_info(g_mmi_nss_cxt.nss_app_node[item_idx-1].app_info.mre_res.app_mre_package_name, &info); 
            {
                mmi_app_package_name_struct appPackageName;
                srv_appmgr_get_app_package_name_by_id(g_mmi_nss_cxt.nss_app_node[mmi_nss_app_setting_get_app_index(item_idx - 1)].app_id, appPackageName);
                srv_appmgr_get_app_package_info(appPackageName, &info);
            }
            if (info.image.type == MMI_IMAGE_SRC_TYPE_PATH)
            {
                path[0] = '\0';
                path[1] = '\0';
                mmi_ucs2cpy((CHAR*)path, (CHAR*)info.image.data.path);
                /*need vertify*/
                if((info.image.data.path[1]!=0x00)&&((info.image.data.path[3]!=0x00)))
                {
                    MMI_TRACE(
                        MMI_COMMON_TRC_G7_SETTING, 
                        MMI_NSS_APP_ICON_PATH, 
                        info.image.data.path, 
                        1);
                }
                else
                {
                    MMI_TRACE(
                        MMI_COMMON_TRC_G7_SETTING, 
                        MMI_NSS_APP_ICON_PATH, 
                        info.image.data.path, 2);
                    mmi_ucs2_to_asc(tmp, (CHAR *)TempTestIcon);
                    kal_prompt_trace(
                        MOD_MMI_COMMON_APP,
                        "mmi_nss_list_thumbnail_get_image_path = %s", 
                        tmp);
                }
                /*mmi_ucs2cpy((CHAR*)path, (CHAR*)TempTestIcon); test need recovery */
                return MMI_TRUE;
            }
        }
    #else
        if(g_mmi_nss_cxt.nss_app_node[mmi_nss_app_setting_get_app_index(item_idx)].app_type == DOWNLOAD_APP_TYPE)
        {
     
            //srv_appmgr_get_app_package_info(g_mmi_nss_cxt.nss_app_node[item_idx].app_info.mre_res.app_mre_package_name, &info); 
            {
                mmi_app_package_name_struct appPackageName;
                srv_appmgr_get_app_package_name_by_id(g_mmi_nss_cxt.nss_app_node[mmi_nss_app_setting_get_app_index(item_idx)].app_id, appPackageName);
                srv_appmgr_get_app_package_info(appPackageName, &info);
            }
            if (info.image.type == MMI_IMAGE_SRC_TYPE_PATH)
            {
                path[0] = '\0';
                path[1] = '\0';
                mmi_ucs2cpy((CHAR*)path, (CHAR*)info.image.data.path);
                /*need vertify*/
                if((info.image.data.path[1]!=0x00)&&((info.image.data.path[3]!=0x00)))
                {
                      MMI_TRACE(
                        MMI_COMMON_TRC_G7_SETTING, 
                        MMI_NSS_APP_ICON_PATH, 
                        info.image.data.path, 
                        1);
                }
                else
                {
                      MMI_TRACE(
                        MMI_COMMON_TRC_G7_SETTING, 
                        MMI_NSS_APP_ICON_PATH, 
                        info.image.data.path, 
                        2);
                      mmi_ucs2_to_asc(tmp, (CHAR *)TempTestIcon);
                      kal_prompt_trace(
                        MOD_MMI_COMMON_APP,
                        "mmi_nss_list_thumbnail_get_image_path = %s", 
                        tmp);
                }
                /*mmi_ucs2cpy((CHAR*)path, (CHAR*)TempTestIcon); test need recovery */
                return MMI_TRUE;
            }
        }
    #endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nss_list_thumbnail_set_displayable
 * DESCRIPTION
 *  make app save "menuitem icon" whether to be present, because of "image path" may be error,
 *  set_displayable_func is than the category notification app,which menuitem's image whether to 
 *  be present
 *  app save the status TRUE/FALSE
 * PARAMETERS
 *  S32 item_idx, [IN] 
 *  MMI_BOOL displayable  [IN]
 * RETURNS
 *  
 *****************************************************************************/
void mmi_nss_list_thumbnail_set_displayable(S32 item_idx, MMI_BOOL displayable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;   
}



/*****************************************************************************
 * FUNCTION
 *  mmi_nss_list_thumbnail_get_displayable
 * DESCRIPTION
 *  get_displayable-func is category from app get which menuitem's image can show
 * PARAMETERS
 *  S32 item_idx [IN]
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_nss_list_thumbnail_get_displayable(S32 item_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nss_list_thumbnail_get_menuitem
 * DESCRIPTION
 *  get_displayable-func is category from app get which menuitem's image can show
 * PARAMETERS
 *  S32 item_idx [IN]
 *, wgui_thumbnail_info_struct *info_data [IN, OUT]
 * RETURNS
 *  
 *****************************************************************************/
void mmi_nss_list_thumbnail_get_menuitem(S32 item_idx, wgui_thumbnail_info_struct *info_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    info_data->file_icon_ptr = (PU8)GetImage(IMG_SETTING_PHONE);
    info_data->is_show_thumb = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nss_list_get_id_by_list_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index            [IN]     
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_nss_list_get_id_by_list_index(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return item_index;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_nss_sproc
 * DESCRIPTION
 * pro the notification settings app and backgrounddata
 * PARAMETERS
 *  evt    : [IN] mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_nss_sproc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
	cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (evt->evt_id)
	{
        case EVT_ID_SCRN_ACTIVE:
        	{
                guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_NSS_GROUP, SRN_ID_NSS_APPLIST_SCREEN);
                #ifdef __MMI_PNS__
                    wgui_fixed_list_register_get_flags_handler(mmi_nss_applist_seperate_line);
                #endif
                /***********************begin just for get image path and show it in 1034*/
                wgui_thumbnail_register_get_image_path_func(mmi_nss_list_thumbnail_get_image_path);
				wgui_thumbnail_register_get_image_func(mmi_nss_list_thumbnail_get_image);
				wgui_thumbnail_register_set_displayable_func(mmi_nss_list_thumbnail_set_displayable);
	            wgui_thumbnail_register_get_displayable_func(mmi_nss_list_thumbnail_get_displayable);
                wgui_thumbnail_register_get_image_info_func(mmi_nss_list_thumbnail_get_menuitem);
                wgui_thumbnail_register_get_store_id_func(mmi_nss_list_get_id_by_list_index);
                /************************end*/
                wgui_cat1034_show(
					(WCHAR *)GetString(STR_ID_SETTING_NOTIFICATIONSETTINGS),
					0,
					(WCHAR *)GetString(STR_GLOBAL_OK),
					0,
					(WCHAR *)GetString(STR_GLOBAL_BACK),
					0,
					g_mmi_nss_cxt.nss_list_number,
					/* get nss app list item:str and appname, except the background data */
					mmi_nss_getapp_listitem,
					/* get nss background data hint 0 index is on, 1 index is off, 
					while on enum is 1, off enum is 0*/
					mmi_nss_get_bkgdata_hint,
					g_mmi_nss_cxt.nss_highlight_list_index,
					0,    
					IMG_SETTING_PHONE,/*just have the stytle*/
					0,
					guiBuffer,
					NULL);
                SetLeftSoftkeyFunction(mmi_nss_applist_item_ok, KEY_EVENT_UP);
                SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
                EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
                SetCenterSoftkeyFunction(mmi_nss_applist_item_ok, KEY_EVENT_UP);
        		break;
        	}
        
		case EVT_ID_SCRN_HIGHLIGHT_CHANGE:
			{
				#ifdef __MMI_PNS__
                    g_mmi_nss_cxt.nss_highlight_list_index = menu_evt->sender_id;
                    if(menu_evt->sender_id)
                    {
                        g_mmi_nss_cxt.nss_highlight_appname_index = menu_evt->sender_id - 1;
                    }         
                #else
                    g_mmi_nss_cxt.nss_highlight_list_index = menu_evt->sender_id;
                    g_mmi_nss_cxt.nss_highlight_appname_index = menu_evt->sender_id;        
                #endif
                break;
			}
	}
    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_nss_app_inline_item_pre
 * DESCRIPTION
 *  prepare the app inline item to be show.and delete the not configable
 * PARAMETERS
 *  void   
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nss_app_inline_item_pre()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nss_app_key_enum i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    for(i = NSS_KEY_BADGE_ICON; i < NSS_KEY_MAX; i++)
    {
        if (g_mmi_nss_cxt.nss_app_setting_stuct[i].nss_app_setting_cf == MMI_FALSE)
        {
            switch (i)
            {
            case NSS_KEY_NCENTER:
                { 
                    cui_inline_delete_item(
                        mmi_frm_group_get_active_id(), 
                        NSS_APP_CENTER_CAPTION);
                    cui_inline_delete_item(
                        mmi_frm_group_get_active_id(), 
                        NSS_APP_CENTER_SELECT);
                    break;
                }
            
            case NSS_KEY_ALERT:
                {
                    cui_inline_delete_item(
                        mmi_frm_group_get_active_id(), 
                        NSS_APP_ALERT_CAPTION);
                    cui_inline_delete_item(
                        mmi_frm_group_get_active_id(), 
                        NSS_APP_ALERT_SELECT);
                    break;
                }
            
            case NSS_KEY_BADGE_ICON:
                {
                    cui_inline_delete_item(
                        mmi_frm_group_get_active_id(),
                        NSS_APP_BADGE_APP_ICON_CAPTION);
                    cui_inline_delete_item(
                        mmi_frm_group_get_active_id(), 
                        NSS_APP_BADGE_APP_ICON_SELECT);
                    break;
                }
                
            case NSS_KEY_SOUND:
                {
                    cui_inline_delete_item(
                        mmi_frm_group_get_active_id(), 
                        NSS_APP_SOUND_CAPTION);
                    cui_inline_delete_item(
                        mmi_frm_group_get_active_id(), 
                        NSS_APP_SOUND_SELECT);
                    break;
                }  

            case NSS_KEY_LOCK_SCRN:
                {
                    cui_inline_delete_item(
                        mmi_frm_group_get_active_id(), 
                        NSS_APP_LOCK_SCREEN_CAPTION);
                    cui_inline_delete_item(
                        mmi_frm_group_get_active_id(), 
                        NSS_APP_LOCK_SCREEN_SELECT);
                    break;
                }
            /*
            case NSS_KEY_POPUP:
                {
                    cui_inline_delete_item(mmi_frm_group_get_active_id(), NSS_APP_POPUP_CAPTION);
                    cui_inline_delete_item(mmi_frm_group_get_active_id(), NSS_APP_POPUP_SELECT);
                    break;
                } 
            */
            }  
        }
        continue;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nss_gproc
 * DESCRIPTION
 * The pro for notification settings for managing the notification setting
 * include the background data setting scrn, and all app inline_group, also
 * include the scrn of 1034 for nss list showing
 * PARAMETERS
 *  evt    : [IN] mmi_event_struct
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_nss_gproc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
    case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        {
            mmi_nss_app_inline_item_pre();
            break;
        }
    
    case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_inline_close(mmi_frm_group_get_active_id());
            break;
        }
    case EVT_ID_CUI_INLINE_CSK_PRESS:
    case EVT_ID_CUI_INLINE_SUBMIT:
        {
            cui_event_inline_submit_struct *submit_evt = (cui_event_inline_submit_struct*)evt;
            mmi_nss_app_setting_save_info();
            cui_inline_close(submit_evt->sender_id);
            break; 
        }
        
    case EVT_ID_CUI_INLINE_NOTIFY:
        {
            cui_event_inline_notify_struct *notify_event = (cui_event_inline_notify_struct*)evt;
            if (notify_event->event_type == CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED)
            {
                mmi_nss_app_setting_notify_changed(notify_event);
            }    
            break;
        }
 
    default:
        break;      
    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nss_main
 * DESCRIPTION
 *  enter notification settings menu to deal with something
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nss_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR tmp[MMI_MAX_FILE_NAME_LEN * 2] = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_mmi_nss_cxt, 0, sizeof(mmi_nss_app_struct));
    mmi_ucs2_to_asc(tmp, (CHAR *)TempTestIcon);
    MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_NSS_APP_ICON_PATH, tmp, 2);
    kal_prompt_trace(MOD_MMI_COMMON_APP,"mmi_nss_main test = %s", tmp);
    mmi_nss_get_applist_infor();
    mmi_frm_group_create_ex(
        GRP_ID_ROOT, 
        GRP_ID_NSS_GROUP, 
        mmi_nss_gproc, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_create(
        GRP_ID_NSS_GROUP, 
        SRN_ID_NSS_APPLIST_SCREEN, 
        mmi_nss_sproc,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nss_hilight
 * DESCRIPTION
 *  when highlight to notification settings menu item, set something
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nss_hilight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(mmi_nss_main, KEY_EVENT_UP);
	/* 4 Register function for center soft key */
    SetCenterSoftkeyFunction(mmi_nss_main, KEY_EVENT_UP);
    /* 5 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

#endif

