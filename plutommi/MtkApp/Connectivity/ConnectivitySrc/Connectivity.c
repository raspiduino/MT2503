#include "MMI_features.h"
#include "MMIDataType.h"
#include "CommonScreens.h"
#include "Connectivity.h"
#include "BTMMIScrGprots.h"
#include "MMIDataType.h"
#include "wgui_categories_util.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "mmi_frm_history_gprot.h"
#include "CustMenuRes.h"
#include "mmi_rp_app_bluetooth_def.h"
#include "mmi_frm_events_gprot.h"
#include "ConnectivityResDef.h"
#include "mmi_rp_app_connectivity_mainmenu_def.h"
#include "wgui_fixed_menus.h"
#include "wgui_categories_list.h"
#include "wgui_categories_util.h"
#ifdef __PLUTO_MMI_PACKAGE__ 
#include "mmi_rp_app_mainmenu_def.h"
#include "DataLockSrvGprot.h"
#endif
#include "mmi_frm_scenario_gprot.h"
#include "FactoryGprot.h"
#include "IdleGprot.h"
#include "IdleFactory.h"
/*------------------------------ suggest Add ------------------------------*/
// #include "kal_general_types.h"
#if (defined(__TCPIP__) && defined(__PLUTO_MMI_PACKAGE__))
#include "mmi_rp_app_dataaccount_def.h"
extern MMI_BOOL mmi_data_connection_sim_main_menu_should_hide(void);
extern MMI_BOOL mmi_dtcnt_main_menu_should_hide(void);
#endif

void EntryConnectivityMain(void);

/*****************************************************************************
 * FUNCTION
 *  InitConnectivityApp
 * DESCRIPTION
 *  Initialize Security
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitConnectivityApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  HighlightConnectivity
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightConnectivity(void)
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
    SetLeftSoftkeyFunction(EntryConnectivityMain, KEY_EVENT_UP);
    
	/* 4 Register function for center soft key */
    SetCenterSoftkeyFunction(EntryConnectivityMain, KEY_EVENT_UP);

    /* 5 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_update_connectivity_menu
 * DESCRIPTION
 *  update connectivity menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_update_connectivity_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__TCPIP__) && defined(__PLUTO_MMI_PACKAGE__))
    if (mmi_data_connection_sim_main_menu_should_hide())
    {
        mmi_frm_hide_menu_item(MENU_ID_DATA_CONNECTION_SIM);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_DATA_CONNECTION_SIM);
    }
#endif
    
#if (defined(__TCPIP__) && defined(__PLUTO_MMI_PACKAGE__))
    if (mmi_dtcnt_main_menu_should_hide())
    {
        mmi_frm_hide_menu_item(SERVICES_DATA_CONNECT_MAIN_MENU_ID);
    }
    else
    {
        mmi_frm_unhide_menu_item(SERVICES_DATA_CONNECT_MAIN_MENU_ID);
    }
#endif

#if defined(__MMI_BT_SUPPORT__) && defined(__PLUTO_MMI_PACKAGE__)
    if (mmi_bt_is_to_display_bt_menu())
    {
        mmi_frm_unhide_menu_item(MENU_CONN_BT_MAIN);
         	#ifdef __MMI_LAUNCHER_APP_LIST__
        	       if(mmi_factory_get_favorite_type(mmi_idle_get_cfg_table())==MMI_IDLE_TYPE_APPLIST)
        	       		mmi_frm_hide_menu_item(MENU_CONN_BT_MAIN);   
        	       		
        	#endif 
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_CONN_BT_MAIN);
    }
#endif    

#if defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_DATA_LOCK__) 
	if (srv_data_lock_get_setting() == MMI_TRUE)
	{
		mmi_frm_unhide_menu_item(MENU_ID_DATA_ROAMING);
	}
	else
	{
		mmi_frm_hide_menu_item(MENU_ID_DATA_ROAMING);
	}
#endif

}

static MMI_RET conn_scrn_proc(mmi_event_struct *event)
{
    U16 item_count;
    U16 items[MAX_SUB_MENUS];
    
    switch (event->evt_id) {
    case EVT_ID_SCRN_GET_CURR_PARENT_ID:
        {
            cat_evt_struct *evt = (cat_evt_struct *)event;
            evt->parent_id = MENU_ID_CONNECTIVITY;
        }
        break;
        
    case EVT_ID_SCRN_ACTIVE:
        {
            mmi_frm_scrn_active_evt_struct *evt = 
                (mmi_frm_scrn_active_evt_struct *)event;
            
            mmi_update_connectivity_menu();
            item_count = GetNumOfChild_Ext(MENU_ID_CONNECTIVITY);
            GetSequenceStringIds_Ext(MENU_ID_CONNECTIVITY, items);
		#ifndef __MMI_WGUI_DISABLE_CSK__
            EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    #endif
            wgui_list_menu_enable_access_by_shortcut();
            
#ifdef __PLUTO_MMI_PACKAGE__ 
            if (item_count == 0)
            {
                ShowCategory52Screen(
                STR_MENU_ID_CONNECTIVITY_TEXT,
                GetRootTitleIcon(MENU_ID_CONNECTIVITY),
                0,
                0,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                item_count,
                items,
                (U16 *)gIndexIconsImageList,
                0, 0, 0,
                evt->gui_buffer);
            }
			else
            {
            ShowCategory52Screen(
                STR_MENU_ID_CONNECTIVITY_TEXT,
                GetRootTitleIcon(MENU_ID_CONNECTIVITY),
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                item_count,
                items,
                (U16 *)gIndexIconsImageList,
                0, 0, 0,
                evt->gui_buffer);
	}
#else
            if (item_count == 0)
            {
                ShowCategory52Screen(
                STR_MENU_ID_CONNECTIVITY_TEXT,
                0,
                0,
                0,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                item_count,
                items,
                (U16 *)gIndexIconsImageList,
                0, 0, 0,
                evt->gui_buffer);
            }
			else
			{
            ShowCategory52Screen(
                STR_MENU_ID_CONNECTIVITY_TEXT,
                0,
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                item_count,
                items,
                (U16 *)gIndexIconsImageList,
                0, 0, 0,
                evt->gui_buffer);
	}
#endif
        }
        break;

    default:
        break;
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  EntryConnectivityMain
 * DESCRIPTION
 *  enter security-setup menu screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryConnectivityMain(void)
{
    mmi_frm_scrn_create(GRP_ID_ROOT, SCR_EXTDEV_CONNECTIVITY, conn_scrn_proc, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_app_launch_func
 * DESCRIPTION
 *  Launch connectivity app in app mgr
 * PARAMETERS
 *  param
 *  param_size
 * RETURNS
 *  MMI_ID
 *****************************************************************************/
MMI_ID mmi_connectivity_app_launch_func(void* param, U32 param_size)
{
    MMI_ID gid = GRP_ID_INVALID;
    
    gid = mmi_frm_group_create(
                GRP_ID_ROOT, 
                GRP_ID_AUTO_GEN, 
                conn_scrn_proc, 
                NULL);
    
    mmi_frm_group_enter(gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_create(gid, SCR_EXTDEV_CONNECTIVITY, conn_scrn_proc, NULL);

    return gid;
}

