extern "C"
{
#include "MenuCuiGprot.h"
}


static mmi_ret avk_cui_menu_proc_01(mmi_event_struct* evt)
{
		U16 menu_id[2];
		U16 i;
		//MMI_ID cui_gid = GRP_ID_INVALID;
	
		cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
		switch(evt->evt_id)
		{
			
			case EVT_ID_CUI_MENU_LIST_ENTRY:
				for(i=0;i<2;i++)
				{
					menu_id[i] = MENU_ID_AVK_CUI_010 + i;
				}
				AVK_LOG_NORMAL(cui_menu_set_currlist(menu_evt->sender_id,2,menu_id));
				AVK_LOG_NORMAL(cui_menu_set_item_string(menu_evt->sender_id,MENU_ID_AVK_CUI_010,(WCHAR*)L"String1"));
				AVK_LOG_NORMAL(cui_menu_set_item_image(menu_evt->sender_id,MENU_ID_AVK_CUI_010,IMG_GLOBAL_L1));
				cui_menu_set_item_string(menu_evt->sender_id,MENU_ID_AVK_CUI_011,(WCHAR*)L"String2");
				cui_menu_set_item_image(menu_evt->sender_id,MENU_ID_AVK_CUI_011,IMG_GLOBAL_L2);
				break;
			case EVT_ID_CUI_MENU_ITEM_HILITE:
				break;
			case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
			case EVT_ID_CUI_MENU_ITEM_SELECT:			
				AVK_CASE_RESULT(AVK_PASS);
				AVK_LOG_NORMAL(cui_menu_close(menu_evt->sender_id));
				AVK_ASYN_DONE();
				break;
			case EVT_ID_CUI_MENU_LIST_EXIT:
				break;			
			case EVT_ID_CUI_MENU_CLOSE_REQUEST:
				AVK_CASE_RESULT(AVK_FAIL);
				AVK_LOG_NORMAL(cui_menu_close(menu_evt->sender_id));
				AVK_ASYN_DONE();
				break;	
			default:
				break;
		}
		return MMI_RET_OK;
	

}
void avk_cui_menu_timer_cb(void)
{
	cui_menu_play(AVK_GRP_ID_1);
}

static mmi_ret avk_cui_menu_proc(mmi_event_struct* evt)
{
	U16 menu_id[4];
	U16 i;
	MMI_ID cui_gid = GRP_ID_INVALID;

	cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
	switch(evt->evt_id)
	{
		
		case EVT_ID_CUI_MENU_LIST_ENTRY:
			menu_id[0]=MENU_ID_AVK_CUI_MENU_CASCADING;
			for(i=1;i<4;i++)
				{
					menu_id[i] = MENU_ID_AVK_CUI_002 + i-1;
				}
			cui_menu_set_currlist(menu_evt->sender_id,4,menu_id);
			cui_menu_set_item_string(menu_evt->sender_id,MENU_ID_AVK_CUI_MENU_CASCADING,(WCHAR*)L"String1");
			cui_menu_set_item_image(menu_evt->sender_id,MENU_ID_AVK_CUI_MENU_CASCADING,IMG_GLOBAL_L1);
			cui_menu_set_item_string(menu_evt->sender_id,MENU_ID_AVK_CUI_002,(WCHAR*)L"String2");
			cui_menu_set_item_image(menu_evt->sender_id,MENU_ID_AVK_CUI_002,IMG_GLOBAL_L2);
			cui_menu_set_item_string(menu_evt->sender_id,MENU_ID_AVK_CUI_003,(WCHAR*)L"Pass");
			cui_menu_set_item_image(menu_evt->sender_id,MENU_ID_AVK_CUI_003,IMG_GLOBAL_L3);
			cui_menu_set_item_string(menu_evt->sender_id,MENU_ID_AVK_CUI_004,(WCHAR*)L"String4");
			cui_menu_set_item_image(menu_evt->sender_id,MENU_ID_AVK_CUI_004,IMG_GLOBAL_L4);
			AVK_LOG_NORMAL(cui_menu_set_item_disabled(menu_evt->sender_id,MENU_ID_AVK_CUI_002,MMI_TRUE));
			AVK_LOG_NORMAL(cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AVK_CUI_003,MMI_TRUE));
			AVK_LOG_NORMAL(cui_menu_set_item_hint(menu_evt->sender_id,MENU_ID_AVK_CUI_001,(WCHAR*)L"Hint String1"));
			AVK_LOG_NORMAL(cui_menu_set_item_second_image(menu_evt->sender_id,MENU_ID_AVK_CUI_001,IMG_GLOBAL_L2));
			AVK_LOG_NORMAL(cui_menu_override_center_softkey(menu_evt->sender_id, NULL, get_image(IMG_GLOBAL_COMMON_CSK)));
			AVK_LOG_NORMAL(cui_menu_enable_center_softkey(menu_evt->sender_id, NULL, IMG_GLOBAL_COMMON_CSK));
			AVK_LOG_NORMAL(cui_menu_set_non_leaf_item(menu_evt->sender_id,MENU_ID_AVK_CUI_004,MMI_TRUE));
			AVK_LOG_NORMAL(cui_menu_pause(cui_gid));
			StartTimer(0x1234,5000,avk_cui_menu_timer_cb);
			break;
		case EVT_ID_CUI_MENU_ITEM_HILITE:
			break;
		case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
			if(menu_evt->highlighted_menu_id== MENU_ID_AVK_CUI_MENU_CASCADING)
			{
				mmi_frm_group_create(GRP_ID_AVK,AVK_GRP_ID_2,avk_cui_menu_proc_01, (void*)NULL); 

   				mmi_frm_group_enter(AVK_GRP_ID_2, MMI_FRM_NODE_SMART_CLOSE_FLAG);


			    cui_gid = cui_menu_create(
            			                AVK_GRP_ID_2,
                        			    CUI_MENU_SRC_TYPE_RESOURCE,
			                            CUI_MENU_TYPE_OPTION,
			                            MENU_ID_AVK_CUI,
            			                MMI_FALSE, NULL);
				AVK_LOG_NORMAL(cui_menu_set_default_title(cui_gid,(UI_string_type)GetString(STR_GLOBAL_OPTIONS),NULL));
				AVK_LOG_NORMAL(cui_menu_set_default_title_string(cui_gid,(UI_string_type)GetString(STR_GLOBAL_OPTIONS)));
				AVK_LOG_NORMAL(cui_menu_set_default_title_image(cui_gid,NULL));
				AVK_LOG_NORMAL(cui_menu_set_default_left_softkey(cui_gid,(UI_string_type)GetString(AVK_STR_PASS)));
				AVK_LOG_NORMAL(cui_menu_set_default_right_softkey(cui_gid,(UI_string_type)GetString(AVK_STR_FAIL)));
				AVK_LOG_NORMAL(cui_menu_disable_cascading_option_menu(cui_gid));
				AVK_LOG_NORMAL(cui_menu_run(cui_gid));
			}
			else
			{
				AVK_CASE_RESULT(AVK_PASS);
				cui_menu_close(menu_evt->sender_id);
				AVK_ASYN_DONE();
			}
			break;
		case EVT_ID_CUI_MENU_LIST_EXIT:
            break;
        
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            AVK_CASE_RESULT(AVK_FAIL);
			cui_menu_close(menu_evt->sender_id);
//			AVK_ASYN_DONE();
            break;

        default:
            break;
    }
    return MMI_RET_OK;
	
}


/*****************************************************************************
* FUNCTION
*  avk_cui_menu_001
* DESCRIPTION
*  
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
void avk_cui_menu_001(void)
{
	/*---------------------------------------------------------------- */
	/* 						 Local Variable                                                     */
	/*----------------------------------------------------------------*/
	 MMI_ID cui_gid = GRP_ID_INVALID;

	/*---------------------------------------------------------------- */
	/* 						 Code Body                                                         */
	/*----------------------------------------------------------------*/
	
	
    mmi_frm_group_create(GRP_ID_AVK,AVK_GRP_ID_1,avk_cui_menu_proc, (void*)NULL); 

    //mmi_frm_set_active_group(GRP_ID_AUDPLY_OPTION);
    
    mmi_frm_group_enter(AVK_GRP_ID_1, MMI_FRM_NODE_SMART_CLOSE_FLAG);


    AVK_LOG_NORMAL(cui_gid = cui_menu_create(
                            AVK_GRP_ID_1,
                            CUI_MENU_SRC_TYPE_APPCREATE,
                            CUI_MENU_TYPE_OPTION,
                            MENU_ID_AVK_CUI,
                            MMI_FALSE, NULL));
	cui_menu_set_default_title(cui_gid,(UI_string_type)GetString(STR_GLOBAL_OPTIONS),NULL);
	cui_menu_set_default_title_string(cui_gid,(UI_string_type)GetString(STR_GLOBAL_OPTIONS));
	cui_menu_set_default_title_image(cui_gid,NULL);
	cui_menu_set_default_left_softkey(cui_gid,(UI_string_type)GetString(STR_GLOBAL_OK));
	cui_menu_set_default_right_softkey(cui_gid,(UI_string_type)GetString(AVK_STR_FAIL));
	cui_menu_enable_cascading_option_menu(cui_gid);
	cui_menu_run(cui_gid);
	
	
}

AVK_MANUAL_CASE(AVK_CUI_MENU_MANU_001,AVK_CUI_MENU)
{
    avk_cui_menu_001();
}

mmi_ret avk_cui_currlist_proc(mmi_event_struct *p_event)
{


	/*---------------------------------------------------------------- */
	/* 						 Local Variable                                                     */
	/*----------------------------------------------------------------*/
	cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)p_event;
	U16 menu_id[5];
	U16 menu_insert_id[3];
	U16 menu_del_id[3];
	U16 i,item_count,item_index;
	
	/*---------------------------------------------------------------- */
	/* 						 Code Body                                                         */
	/*----------------------------------------------------------------*/
	
	switch(p_event->evt_id)
		{
			case EVT_ID_CUI_MENU_LIST_ENTRY:
				for(i=0;i<5;i++)
				{
					menu_id[i] = MENU_ID_AVK_CUI_010 + i;
				}
				menu_insert_id[0] = MENU_ID_AVK_CUI_015;
				menu_insert_id[1] = MENU_ID_AVK_CUI_016;
				menu_insert_id[2] = MENU_ID_AVK_CUI_MENU_CASCADING;
				menu_del_id[0]=MENU_ID_AVK_CUI_012;
				menu_del_id[1]=MENU_ID_AVK_CUI_013;
				menu_del_id[2]=MENU_ID_AVK_CUI_014;
				cui_menu_set_currlist(menu_evt->sender_id,5,menu_id);
				cui_menu_set_access_by_shortcut(menu_evt->sender_id,MMI_TRUE);
                cui_menu_enable_tap_to_highlight(menu_evt->sender_id);
				cui_menu_set_item_string(menu_evt->sender_id,MENU_ID_AVK_CUI_010,(WCHAR*)L"PASS");
				cui_menu_set_item_string(menu_evt->sender_id,MENU_ID_AVK_CUI_011,(WCHAR*)L"Change LSK to OKKK");
				cui_menu_set_item_string(menu_evt->sender_id,MENU_ID_AVK_CUI_012,(WCHAR*)L"Item 3");
				cui_menu_set_item_string(menu_evt->sender_id,MENU_ID_AVK_CUI_013,(WCHAR*)L"Item 4");
				cui_menu_set_item_string(menu_evt->sender_id,MENU_ID_AVK_CUI_014,(WCHAR*)L"Change CSK Image");
				cui_menu_set_currlist_title(menu_evt->sender_id,(WCHAR*)L"Current List",NULL);
				cui_menu_set_currlist_left_softkey(menu_evt->sender_id,(UI_string_type)GetString(STR_GLOBAL_OK));
				cui_menu_set_currlist_right_softkey(menu_evt->sender_id,(UI_string_type)GetString(AVK_STR_FAIL));
				cui_menu_insert_currlist(menu_evt->sender_id,3,menu_insert_id,MENU_ID_AVK_CUI_014);
				cui_menu_set_item_string(menu_evt->sender_id,MENU_ID_AVK_CUI_015,(WCHAR*)L"Refresh");
				cui_menu_set_item_string(menu_evt->sender_id,MENU_ID_AVK_CUI_016,(WCHAR*)L"Rotate By 180");
				cui_menu_set_item_string(menu_evt->sender_id,MENU_ID_AVK_CUI_MENU_CASCADING,(WCHAR*)L"Cascading Menu");
				cui_menu_set_currlist_flags(menu_evt->sender_id,CUI_MENU_LIST_WITH_NO_ICON );
				cui_menu_delete_currlist(menu_evt->sender_id,3,menu_del_id);
				item_count = cui_menu_get_currlist_item_count(menu_evt->sender_id);
				cui_menu_set_new_list_parent_id(menu_evt->sender_id,MENU_ID_AVK_CUI_MENU_CASCADING);
				cui_menu_set_radio_list_item(menu_evt->sender_id,MENU_ID_AVK_CUI_010);
				if(item_count!= 5)
				{
					AVK_CASE_RESULT(AVK_FAIL);
				}
				item_index = cui_menu_get_index_in_currlist_from_menu_id(menu_evt->sender_id,MENU_ID_AVK_CUI_010);

				if(cui_menu_get_currlist_menu_id_from_index(menu_evt->sender_id,item_index) != MENU_ID_AVK_CUI_010)
				{
					AVK_CASE_RESULT(AVK_FAIL);
				}
				if(!cui_menu_is_menu_event(p_event->evt_id))
				{
					AVK_CASE_RESULT(AVK_FAIL);				    
				}
				break;
				if(CUI_MENU_SRC_TYPE_APPCREATE != cui_menu_get_src_type(menu_evt->sender_id))
				{
					AVK_CASE_RESULT(AVK_FAIL);
				}
					
			case EVT_ID_CUI_MENU_ITEM_HILITE:
				break;
			case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
			case EVT_ID_CUI_MENU_ITEM_SELECT:
				if(menu_evt->highlighted_menu_id == MENU_ID_AVK_CUI_014)
					cui_menu_change_center_softkey_content(menu_evt->sender_id, NULL, get_image(IMG_GLOBAL_COMMON_CSK));
				else if(menu_evt->highlighted_menu_id == MENU_ID_AVK_CUI_011)
					cui_menu_change_left_softkey_string(menu_evt->sender_id,(WCHAR*)L"OKKK");
				else if(menu_evt->highlighted_menu_id == MENU_ID_AVK_CUI_010)
				{
					AVK_CASE_RESULT(AVK_PASS);
					cui_menu_close(menu_evt->sender_id);
					AVK_ASYN_DONE();
				}
				else if(menu_evt->highlighted_menu_id == MENU_ID_AVK_CUI_015)
				{
					cui_menu_refresh_currlist(menu_evt->sender_id);
				}
				
				else if(menu_evt->highlighted_menu_id == MENU_ID_AVK_CUI_016)
				{
					cui_menu_set_rotate_screen(menu_evt->sender_id, MMI_FRM_SCREEN_ROTATE_180);
				}
				break;
			case EVT_ID_CUI_MENU_LIST_EXIT:
				break;
			
			case EVT_ID_CUI_MENU_CLOSE_REQUEST:
				AVK_CASE_RESULT(AVK_FAIL);
				cui_menu_close(menu_evt->sender_id);
				AVK_ASYN_DONE();
				break;
	
			default:
				break;
		}
		return MMI_RET_OK;	
}


void avk_cui_menu_002(void)
{
	/*---------------------------------------------------------------- */
	/* 						 Local Variable                                                     */
	/*----------------------------------------------------------------*/
	MMI_ID cui_gid = GRP_ID_INVALID;

	/*---------------------------------------------------------------- */
	/* 						 Code Body                                                         */
	/*----------------------------------------------------------------*/
	
	
    mmi_frm_group_create(GRP_ID_AVK,AVK_GRP_ID_1,avk_cui_currlist_proc, (void*)NULL); 
    mmi_frm_group_enter(AVK_GRP_ID_1, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	cui_gid = cui_menu_create(
                            AVK_GRP_ID_1,
                            CUI_MENU_SRC_TYPE_APPCREATE,
                            CUI_MENU_TYPE_APPSUB,
                            MENU_ID_AVK_CUI,
                            MMI_FALSE, NULL);

	cui_menu_run(cui_gid);
}


AVK_MANUAL_CASE(AVK_CUI_MENU_MANU_002,AVK_CUI_MENU)
{
    avk_cui_menu_002();
}


void avk_cui_menu_display_result(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL screen_ret = MMI_FALSE;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	screen_ret = mmi_frm_scrn_enter(GRP_ID_AVK, AVK_SCR_ID_2, NULL, avk_cui_menu_display_result, MMI_FRM_FULL_SCRN);
    if(screen_ret == MMI_FALSE)
    {
    return;    
    }
	
    ShowCategory78Screen(
        0,
        0,
        AVK_STR_PASS,
        0,
        AVK_STR_FAIL,
        0,
        NULL,
        NULL,
        0,
        NULL);
		
    AVK_SET_PASSKEY(NULL);		
    AVK_SET_FAILKEY(NULL);
	
}

static mmi_ret avk_cui_checkbox_proc(mmi_event_struct* evt)
{
	U16 menu_id[3];
	U16 i;
	static U8 list_of_states[3]={ 1 , 0 , 0 };

	cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
	switch(evt->evt_id)
	{
		
		case EVT_ID_CUI_MENU_LIST_ENTRY:
			menu_id[0]= MENU_ID_AVK_CUI_MENU_CASCADING;
			for(i=1;i<3;i++)
			{
				menu_id[i] = MENU_ID_AVK_CUI_002 + i-1;
			}
			AVK_LOG_NORMAL(cui_menu_enable_tap_to_highlight(menu_evt->sender_id));
			cui_menu_set_currlist(menu_evt->sender_id,3,menu_id);
            cui_menu_set_currlist_flags(
                menu_evt->sender_id,
                CUI_MENU_NORMAL_CHECK_BOX_LIST);
			cui_menu_set_item_string(menu_evt->sender_id,MENU_ID_AVK_CUI_MENU_CASCADING,(WCHAR*)L"String1");
			cui_menu_set_item_string(menu_evt->sender_id,MENU_ID_AVK_CUI_002,(WCHAR*)L"String2");
			cui_menu_set_item_string(menu_evt->sender_id,MENU_ID_AVK_CUI_003,(WCHAR*)L"String3");
			AVK_LOG_NORMAL(cui_menu_set_checkbox_state(menu_evt->sender_id,list_of_states));
			AVK_LOG_NORMAL(cui_menu_set_new_list_parent_id(menu_evt->sender_id,MENU_ID_AVK_CUI_MENU_CASCADING));
			
			AVK_LOG_EX(cui_menu_get_app_parent_data(menu_evt->sender_id)==(void*) (U32)MENU_ID_AVK_CUI);
			AVK_LOG_NORMAL(cui_menu_get_checkbox_state(menu_evt->sender_id,list_of_states));
			if(list_of_states[0]!=1)
			{
				AVK_CASE_RESULT(AVK_FAIL);
			}
			
			break;

		case EVT_ID_CUI_MENU_ITEM_HILITE:
		 	
		 	
			break;
		case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
			cui_menu_close(menu_evt->sender_id);
			avk_cui_menu_display_result();
			
			break;
		case EVT_ID_CUI_MENU_LIST_EXIT:
			cui_menu_close(menu_evt->sender_id);
            break;
        
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            AVK_CASE_RESULT(AVK_FAIL);
			cui_menu_close(menu_evt->sender_id);
			AVK_ASYN_DONE();
            break;

        default:
            break;
    }
    return MMI_RET_OK;
	
}

void avk_cui_menu_003(void)
{
	/*---------------------------------------------------------------- */
	/* 						 Local Variable                                                      */
	/*----------------------------------------------------------------*/
	MMI_ID cui_gid = GRP_ID_INVALID;

	/*---------------------------------------------------------------- */
	/* 						 Code Body                                                         */
	/*----------------------------------------------------------------*/
	
	
    mmi_frm_group_create(GRP_ID_AVK,AVK_SCR_ID_1,avk_cui_checkbox_proc, (void*)NULL); 
    mmi_frm_group_enter(AVK_SCR_ID_1, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	cui_gid = cui_menu_create(
                            AVK_SCR_ID_1,
                            CUI_MENU_SRC_TYPE_APPCREATE,
                            CUI_MENU_TYPE_APPSUB,
                            MENU_ID_AVK_CUI,
                            MMI_FALSE,
                            (void*) (U32)MENU_ID_AVK_CUI);
	cui_menu_set_default_title(cui_gid,(UI_string_type)(WCHAR*)L"CUI Menus 003",NULL);
	cui_menu_set_default_title_string(cui_gid,(UI_string_type)GetString(STR_GLOBAL_OPTIONS));
	cui_menu_set_default_title_image(cui_gid,NULL);
	cui_menu_set_default_left_softkey(cui_gid,(UI_string_type)GetString(AVK_STR_PASS));
	cui_menu_set_default_right_softkey(cui_gid,(UI_string_type)GetString(AVK_STR_FAIL));

	cui_menu_run(cui_gid);
	
}

AVK_MANUAL_CASE(AVK_CUI_MENU_MANU_003,AVK_CUI_MENU)
{
    avk_cui_menu_003();
}
