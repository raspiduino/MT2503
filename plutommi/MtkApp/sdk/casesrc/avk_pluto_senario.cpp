extern "C"
{
#include "wgui_categories_search.h"
#include "mmi_frm_prot.h"

void mmi_frm_scrn_set_active_input_buf_size (U16 input_buf_size);

}

void avk_pluto_senario_entry_main_scrn(void);
void avk_pluto_scenario_misc_entry_main(mmi_scrn_essential_struct* scrn_data);
void avk_pluto_scenario_001(void);
void avk_pluto_scenario_misc_hilite_handler(U16 index);
void avk_pluto_scenario_002(void);
void avk_pluto_scenario_exit_002(void);
void avk_pluto_scenario_003(void);
mmi_ret avk_pluto_scenario_003_scrn_leave(mmi_event_struct *param);

void avk_pluto_scenario_004(void);
void avk_pluto_scenario_004_entry_scrn_01(void);
void avk_pluto_scenario_004_exit_scrn_02(void);
void avk_pluto_scenario_004_entry_scrn_02(void);
void avk_pluto_scenario_004_exit_scrn_03(void);
void avk_pluto_scenario_004_entry_scrn_03(void);
void avk_pluto_scenario_004_entry_scrn_04(void);
void avk_pluto_scenario_004_entry_scrn_05(void);

void avk_pluto_scenario_005(void);
void avk_pluto_scenario_005_scrn_entry1(void);
mmi_ret avk_pluto_scenario_005_caller_proc(mmi_event_struct *param);
void avk_pluto_scenario_005_timeout(void *param);
void avk_pluto_scenario_006(void);

void avk_pluto_scenario_007(void);
void avk_pluto_scenario_007_entry_scrn_01(void);
void avk_pluto_scenario_007_entry_scrn_02(void);
void avk_pluto_scenario_007_entry_scrn_03(void);
void avk_pluto_scenario_007_entry_scrn_04(void);
void avk_pluto_scenario_007_entry_scrn_05(void);
void avk_pluto_scenario_007_timeout(void);

void avk_pluto_scenario_008_inline_tab_01 (mmi_scrn_essential_struct *data);
void avk_pluto_scenario_008_category199_tab_01(mmi_scrn_essential_struct *data);
void avk_pluto_scenario_008_pass(void);
void avk_pluto_scenario_008_tab_entry(void);
void avk_pluto_scenario_008(void);
mmi_ret avk_pluto_scenario_008_screen_key_proc(mmi_event_struct *evt);
void avk_pluto_scenario_009_tab_entry(void);
void avk_pluto_scenario_009(void);
void avk_pluto_scenario_009_timeout(void);
void avk_pluto_scenario_010(void);
void avk_pluto_scenario_011(void);
void avk_pluto_scenario_check_scrn_id(U16 ep_a_gid, U16 ep_a_sid, U16 ep_e_gid, U16 ep_e_sid);
mmi_ret avk_pluto_scenario_scrn_enter_A(mmi_scrn_essential_struct *data);	
void avk_pluto_scenario_scrn_exit_A(void *arg);
mmi_ret avk_pluto_scenario_scrn_enter_B(mmi_scrn_essential_struct *data);	
mmi_ret avk_pluto_scenario_scrn_exit_B(mmi_scrn_essential_struct *data);
mmi_ret avk_pluto_scenario_scrn_enter_C(mmi_scrn_essential_struct *data);	
mmi_ret avk_pluto_scenario_scrn_exit_C(mmi_scrn_essential_struct *data);	

void avk_pluto_scenario_012(void);
void avk_pluto_scenario_012_timeout(void);
void avk_pluto_scenario_013(void);

MMI_ID g_active_tab_id = SCR_ID_INVALID;

AVK_CASE(AVK_PLUTO_SENA_INIT,AVK_PLUTO_SENA)
{
    AVK_LOG(mmi_frm_group_create(AVK_MAIN_GRP_ID,AVK_GRP_ID_1,mmi_dummy_proc,NULL));
	AVK_LOG(mmi_frm_group_enter(AVK_GRP_ID_1,MMI_FRM_NODE_SMART_CLOSE_FLAG));
    avk_pluto_senario_entry_main_scrn();
}

AVK_CASE(AVK_PLUTO_SENA_DEINIT,AVK_PLUTO_SENA)
{
    AVK_LOG(mmi_frm_group_close(AVK_GRP_ID_1));
}

AVK_CASE(AVK_PLUTO_SENA_CASE1,AVK_PLUTO_SENA_INIT)
{
    avk_pluto_scenario_001();
}

AVK_CASE(AVK_PLUTO_SENA_CASE2,AVK_PLUTO_SENA_INIT)
{
    avk_pluto_scenario_002();
}

AVK_CASE(AVK_PLUTO_SENA_CASE3,AVK_PLUTO_SENA_INIT)
{
    avk_pluto_scenario_003();
}

AVK_CASE(AVK_PLUTO_SENA_CASE4,AVK_PLUTO_SENA_INIT)
{
    avk_pluto_scenario_004();
}


AVK_ASYN_CASE(AVK_PLUTO_SENA_CASE5,AVK_PLUTO_SENA_INIT)
{
    avk_pluto_scenario_005();
}

AVK_CASE(AVK_PLUTO_SENA_CASE6,AVK_PLUTO_SENA_INIT)
{
    avk_pluto_scenario_006();
}

AVK_ASYN_CASE(AVK_PLUTO_SENA_CASE7,AVK_PLUTO_SENA_INIT)
{
    avk_pluto_scenario_007();
}

AVK_ASYN_CASE(AVK_PLUTO_SENA_CASE8,AVK_PLUTO_SENA_INIT)
{
    avk_pluto_scenario_008();
}

AVK_CASE(AVK_PLUTO_SENA_CASE9,AVK_PLUTO_SENA_INIT)
{
    avk_pluto_scenario_009();
}

AVK_CASE(AVK_PLUTO_SENA_CASE10,AVK_PLUTO_SENA_INIT)
{
    avk_pluto_scenario_010();
}

AVK_CASE(AVK_PLUTO_SENA_CASE11,AVK_PLUTO_SENA_INIT)
{
    avk_pluto_scenario_011();
}
/*
AVK_ASYN_CASE(AVK_PLUTO_SENA_CASE12,AVK_PLUTO_SENA_INIT)
{
    avk_pluto_scenario_012();
}*/

MMI_BOOL Get_List_Items1(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    UI_UNUSED_PARAMETER(str_img_mask);
    if (item_index < 0)
    {
        return MMI_FALSE;
    }

    mmi_ucs2cpy((S8*) str_buff, (S8*) GetString((U16)(STR_GLOBAL_PHONE + (U16) item_index)));
    *img_buff_p = (U8*) GetImage(gIndexIconsImageList[item_index]);

    return MMI_TRUE;
}

S32 get_async_hints1(S32 start_indx, UI_string_type *hintArray)
{
    UI_UNUSED_PARAMETER(start_indx);
    mmi_ucs2cpy((S8*) hintArray[0], (S8*) GetString((U16)(STR_GLOBAL_SAVE + start_indx)));
    return TRUE;
}

S32 cat200_callback1(U8 *keyword)
{
    UI_UNUSED_PARAMETER(keyword);
    return 4;
}

void avk_pluto_senario_entry_main_scrn()
{
    if (AVK_LOG(mmi_frm_scrn_enter(AVK_GRP_ID_1, AVK_SCR_ID_5, NULL, avk_pluto_senario_entry_main_scrn, MMI_FRM_FULL_SCRN)))
    {
        mmi_frm_display_dummy_screen();
        AVK_LOG_FUN(mmi_frm_display_dummy_screen,AVK_PASS);
    }
}



/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_001
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_scenario_001(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            AVK_GRP_ID_1, 
            AVK_SCR_ID_1, 
            NULL, 
            (FuncPtr)avk_pluto_scenario_001, 
            MMI_FRM_FULL_SCRN))
    {
        AVK_CASE_RESULT(AVK_FAIL);
        return;
    }

    AVK_LOG(guiBuffer = mmi_frm_scrn_get_active_gui_buf());

    if (AVK_LOG(mmi_frm_is_in_backward_scenario()) && guiBuffer != NULL)
    {
        mmi_frm_scrn_clean_gui_buf(AVK_GRP_ID_1,AVK_SCR_ID_1);
        AVK_LOG_FUN(mmi_frm_scrn_clean_gui_buf,AVK_PASS);
        AVK_LOG(guiBuffer = mmi_frm_scrn_get_gui_buf(AVK_GRP_ID_1,AVK_SCR_ID_1));

        if (guiBuffer == NULL 
                && AVK_LOG(mmi_frm_scrn_is_present(AVK_GRP_ID_1,AVK_SCR_ID_1,MMI_FRM_NODE_ALL_FLAG)) 
                && AVK_LOG(mmi_frm_group_is_present(AVK_GRP_ID_1))
                && 2 == AVK_LOG(mmi_frm_scrn_get_count(AVK_GRP_ID_1)))
        {
            AVK_CASE_RESULT(AVK_PASS);	   
        }
        else
        {
            AVK_CASE_RESULT(AVK_FAIL);	  
        }
        mmi_frm_scrn_close_active_id();
    }
    else
    {             
        mmi_display_popup((UI_string_type)L"", MMI_EVENT_SUCCESS);
        mmi_frm_scrn_close_active_id();     
    }
}



/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_exit_002
 * DESCRIPTION
 *  register highlight handler
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_scenario_exit_002(void)
{
  /*----------------------------------------------------------------*/
  /* Local Variables                                                */
  /*----------------------------------------------------------------*/
  
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   AVK_LOG_EX(!mmi_frm_scrn_clear_attribute(AVK_GRP_ID_1, AVK_SCR_ID_1, MMI_SCRN_ATTRIB_ADD_HISTORY));
   AVK_LOG_EX(!mmi_frm_scrn_clear_attribute(AVK_GRP_ID_1,AVK_SCR_ID_1,MMI_SCRN_ATTRIB_SMALL_SCRN));
}

/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_001
 * DESCRIPTION
 *  This api tests all set, get scenario apis
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_scenario_002(void)
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 set_buffer = 99;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (!mmi_frm_scrn_enter(
            AVK_GRP_ID_1, 
            AVK_SCR_ID_1, 
            (FuncPtr)avk_pluto_scenario_exit_002, 
            (FuncPtr)avk_pluto_scenario_002, 
            MMI_FRM_FULL_SCRN))
    {
        AVK_CASE_RESULT(AVK_FAIL);
        return;
    }

    mmi_frm_scrn_get_active_gui_buf();
    
	AVK_LOG_EX(MMI_SCENARIO_STATE_ACTIVE == mmi_frm_scrn_get_state(AVK_GRP_ID_1, AVK_SCR_ID_1));

    AVK_LOG_EX(GRP_ID_AVK == mmi_frm_scrn_get_top_parent_group_id(AVK_GRP_ID_1,AVK_SCR_ID_1));
    
	AVK_LOG_EX(MMI_RET_OK == mmi_frm_scrn_set_attribute(AVK_GRP_ID_1,AVK_SCR_ID_1,MMI_SCRN_ATTRIB_SMALL_SCRN));  

    AVK_LOG(mmi_frm_scrn_set_user_data(AVK_GRP_ID_1,AVK_SCR_ID_1,(void*)&set_buffer));
    
    AVK_LOG_EX(set_buffer = *(U8*)mmi_frm_scrn_get_user_data(AVK_GRP_ID_1,AVK_SCR_ID_1));
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_003_scrn_leave
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_event_struct *       [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret avk_pluto_scenario_003_scrn_leave(mmi_event_struct *param)
{
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_003
 * DESCRIPTION
 *  This api tests all set, get scenario apis
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_scenario_003(void)
{
   /*----------------------------------------------------------------*/
  /* Local Variables                                                */
  /*----------------------------------------------------------------*/
   mmi_scrn_node_struct scrn_info;
   //U32 priority = 33;

   U8 display_buffer[100];
   U16 buffer_size = 100;
   U8 scrn_buf[100];
   U8 scrn_buf1[100];

  
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

   if (!mmi_frm_scrn_enter(
            AVK_GRP_ID_1, 
            AVK_SCR_ID_2, 
            NULL, 
            (FuncPtr)avk_pluto_scenario_003, 
            MMI_FRM_FULL_SCRN))
    {
        AVK_CASE_RESULT(AVK_FAIL);
        return;
    }

    mmi_ucs2cpy((PS8)display_buffer,(PS8)L"avk_pluto_scenario_003");

    if (!mmi_frm_is_in_backward_scenario())
    {     	  
        //AVK_LOG(mmi_frm_scrn_set_priority(AVK_GRP_ID_1, AVK_SCR_ID_2, priority));

        AVK_LOG(mmi_frm_scrn_set_leave_proc(AVK_GRP_ID_1, AVK_SCR_ID_2, avk_pluto_scenario_003_scrn_leave));
         
        mmi_frm_scrn_set_active_input_buf_size(buffer_size);

        mmi_frm_scrn_set_active_input_buf_ptr((WCHAR*)display_buffer);

        mmi_display_popup((UI_string_type)L"", MMI_EVENT_SUCCESS);
        mmi_frm_scrn_close_active_id();
    }

    else
    {
		WCHAR *input_buf = NULL;
        mmi_frm_scrn_get_info(AVK_GRP_ID_1, AVK_SCR_ID_2, &scrn_info);

        AVK_LOG(input_buf = mmi_frm_scrn_get_active_input_buf());
   
        mmi_ucs2cpy((PS8)scrn_buf1,(PS8)input_buf);   
        mmi_ucs2cpy((PS8)scrn_buf,(PS8)scrn_info.input_buf);

        if (/*scrn_info.priority == priority && */scrn_info.leave_proc == avk_pluto_scenario_003_scrn_leave 
	      && mmi_ucs2cmp((PS8)display_buffer,(PS8)scrn_buf) == 0 && scrn_info.input_buf_size == buffer_size
		   && mmi_ucs2cmp((PS8)display_buffer,(PS8)scrn_buf1) == 0) 
        {
            AVK_LOG_FUN(mmi_frm_scrn_get_info,AVK_PASS);
            mmi_frm_scrn_clean_input_buf(AVK_GRP_ID_1,AVK_SCR_ID_2);
    	    AVK_LOG_EX(NULL == mmi_frm_scrn_get_input_buf(AVK_GRP_ID_1,AVK_SCR_ID_2));             		
        }
        else
        {
    	    AVK_LOG_FUN(mmi_frm_scrn_get_info,AVK_FAIL);
        }
        mmi_frm_scrn_close_active_id(); 
    }

}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_004_entry_scrn_01
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_scenario_004_entry_scrn_01(void) /* (G-id) - (S1) */
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_frm_scrn_enter(AVK_GRP_ID_2, 0x579, NULL, avk_pluto_scenario_004_entry_scrn_01, MMI_FRM_FULL_SCRN))
    {
        mmi_frm_display_dummy_screen();
    }
}
/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_004_exit_scrn_02
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void avk_pluto_scenario_004_exit_scrn_02(void)
{
    mmi_frm_scrn_add_history(AVK_GRP_ID_2, 0x135);
}
/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_004_entry_scrn_02
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_scenario_004_entry_scrn_02(void) /* (G-id) - (S2) */
{

    if (mmi_frm_scrn_enter(AVK_GRP_ID_2, 0x135, avk_pluto_scenario_004_exit_scrn_02, avk_pluto_scenario_004_entry_scrn_02, MMI_FRM_FULL_SCRN))
    {
        mmi_frm_display_dummy_screen();
    }
}

/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_004_exit_scrn_03
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_scenario_004_exit_scrn_03(void)
{
    mmi_frm_scrn_add_history(AVK_GRP_ID_2, 0x222);
}

/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_004_entry_scrn_03
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_scenario_004_entry_scrn_03(void) /* (G-id) - (S3) */
{

    if (mmi_frm_scrn_enter(AVK_GRP_ID_2, 0x222, avk_pluto_scenario_004_exit_scrn_03, avk_pluto_scenario_004_entry_scrn_03, MMI_FRM_FULL_SCRN))
    {
        mmi_frm_display_dummy_screen();
    }
}

/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_004_entry_scrn_04
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_scenario_004_entry_scrn_04(void) /* (G-id) - (S4) */
{

    if (mmi_frm_scrn_enter(AVK_GRP_ID_2, 0x444, NULL, avk_pluto_scenario_004_entry_scrn_04, MMI_FRM_FULL_SCRN))
    {
        mmi_frm_display_dummy_screen();
    }
}

/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_004_entry_scrn_05
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_scenario_004_entry_scrn_05(void) /* (G-id) - (S5) */
{

    if (mmi_frm_scrn_enter(AVK_GRP_ID_2, 0x888, NULL, avk_pluto_scenario_004_entry_scrn_05, MMI_FRM_FULL_SCRN))
    {
        mmi_frm_display_dummy_screen();
    }
}

/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_004
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_scenario_004(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 mmi_frm_node_struct new_node;
	 MMI_ID table[10];
     S32 table_size = 10;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_node_info_init(&new_node);
    mmi_frm_group_create(AVK_GRP_ID_1,AVK_GRP_ID_2,mmi_dummy_proc,NULL);
	mmi_frm_group_enter(AVK_GRP_ID_2,MMI_FRM_NODE_SMART_CLOSE_FLAG);
	
    avk_pluto_scenario_004_entry_scrn_01();  /* Gid--S1 - 0x579 */
	avk_pluto_scenario_004_entry_scrn_02();  /* Gid--S2 - 0x135 */
	avk_pluto_scenario_004_entry_scrn_03();  /* Gid--S3 - 0x222 */
    /* Active Screen: S3, Check S2 is in the history */

	mmi_frm_group_query_children_list(AVK_GRP_ID_2, table, &table_size);
	
	if (table_size == 4 && table[0] == 0x579 && table[1] == 0x135 && table[2] == 0x222 && table[3] == 0x002)
	{
        AVK_LOG_FUN(mmi_frm_group_query_children_list,AVK_PASS);
	}
	else
	{
	    AVK_LOG_FUN(mmi_frm_group_query_children_list,AVK_FAIL);
	}
	
	new_node.id = 0x444;
    new_node.entry_proc = (mmi_proc_func)avk_pluto_scenario_004_entry_scrn_04;
	mmi_frm_scrn_insert(AVK_GRP_ID_2, 0x135, &new_node, MMI_FRM_NODE_AFTER_FLAG);

	if (mmi_frm_scrn_is_present(AVK_GRP_ID_2, 0x444, MMI_FRM_NODE_ALL_FLAG)
	    &&AVK_LOG(0x135 == mmi_frm_scrn_get_neighbor_id(AVK_GRP_ID_2, 0x444, MMI_FRM_NODE_BEFORE_FLAG)))
	{
        AVK_LOG_FUN(mmi_frm_scrn_insert,AVK_PASS);
	}
    else
    {
        AVK_LOG_FUN(mmi_frm_scrn_insert,AVK_FAIL);
    }
    
	new_node.id = 0x888;
    new_node.entry_proc = (mmi_proc_func)avk_pluto_scenario_004_entry_scrn_05;
	mmi_frm_scrn_replace(AVK_GRP_ID_2, 0x444, &new_node);
	
    if (mmi_frm_scrn_is_present(AVK_GRP_ID_2, 0x888, MMI_FRM_NODE_ALL_FLAG))
	{
	    AVK_LOG_FUN(mmi_frm_scrn_replace,AVK_PASS);
	}
    else
    {
        AVK_LOG_FUN(mmi_frm_scrn_replace,AVK_FAIL);
    }
	
	if (mmi_frm_scrn_is_present(AVK_GRP_ID_2,0x135,MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
	{
        mmi_frm_scrn_close_active_id();  /* goback to S2 */
        mmi_frm_scrn_close_active_id();  /* goback to S1 */

        /* Active Screen: S1, Check S2 isn't in the history */
        mmi_frm_scrn_close(AVK_GRP_ID_2,0x135);

        if (!mmi_frm_scrn_is_present(AVK_GRP_ID_2,0x135,MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
        {
            AVK_LOG_FUN(mmi_frm_scrn_close,AVK_PASS);
        }
        else
        {
            AVK_LOG_FUN(mmi_frm_scrn_close,AVK_FAIL);
        }
	  
	}
   AVK_LOG(mmi_frm_group_close(AVK_GRP_ID_2));

}



/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_005_scrn_entry1
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_scenario_005_scrn_entry1(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  if (mmi_frm_scrn_enter(AVK_GRP_ID_2+1, 0x789, NULL, avk_pluto_scenario_005_scrn_entry1, MMI_FRM_FULL_SCRN))
    {
        mmi_frm_display_dummy_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_005_caller_proc
 * DESCRIPTION
 * 
 * PARAMETERS
 *  mmi_event_struct       [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret avk_pluto_scenario_005_caller_proc(mmi_event_struct *param)
{

       /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
    case 0x9999:
        if (param->user_data != (void*)0x1234)
		{
		    AVK_CASE_RESULT(AVK_FAIL);
            mmi_frm_group_close(AVK_GRP_ID_2);
		}
        else
        {
            AVK_CASE_RESULT(AVK_PASS);
        }
        break;
    default:
        break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_005_timeout
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_scenario_005_timeout(void *param)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(AVK_GRP_ID_2+1, 0x789, NULL, avk_pluto_scenario_005_scrn_entry1, MMI_FRM_FULL_SCRN))
    {
        mmi_frm_display_dummy_screen();
    }

    mmi_frm_scrn_close_active_id();

    mmi_frm_group_close(AVK_GRP_ID_2);

    if (AVK_LOG(mmi_frm_group_get_active_id() == AVK_GRP_ID_1))
    {
        AVK_LOG_FUN(mmi_frm_group_close,AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_frm_group_close,AVK_FAIL);
    }
    AVK_ASYN_DONE();
}

/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_005
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_scenario_005(void)
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_group_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* G(Root) -  G(S1)*/
	mmi_frm_group_create(AVK_GRP_ID_1, AVK_GRP_ID_2, mmi_dummy_proc, NULL);
	mmi_frm_group_enter(AVK_GRP_ID_2, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    /* G(Root) -  G(S1)-  G(S2)*/
    mmi_frm_group_create(AVK_GRP_ID_2, AVK_GRP_ID_2+1, mmi_dummy_proc, NULL);
	mmi_frm_group_enter(AVK_GRP_ID_2+1, MMI_FRM_NODE_SMART_CLOSE_FLAG);
 
	AVK_LOG(mmi_frm_group_set_caller_proc(AVK_GRP_ID_2+1, avk_pluto_scenario_005_caller_proc, (void*)0x1234)); 

    if (mmi_frm_scrn_enter(AVK_GRP_ID_2+1, 0x789, NULL, avk_pluto_scenario_005_scrn_entry1, MMI_FRM_FULL_SCRN))
    {
        mmi_frm_display_dummy_screen();
    }
    if (mmi_frm_scrn_enter(AVK_GRP_ID_2+1, 0x135, NULL, avk_pluto_scenario_005_scrn_entry1, MMI_FRM_FULL_SCRN))
    {
        mmi_frm_display_dummy_screen();
    }
    MMI_FRM_INIT_GROUP_EVENT(&evt, 0x9999, AVK_GRP_ID_2+1);
    AVK_LOG_ASYN(mmi_frm_group_send_to_caller(AVK_GRP_ID_2+1, &evt));
    mmi_frm_group_post_to_caller(AVK_GRP_ID_2+1, &evt);

    AVK_CASE_RESULT(AVK_FAIL);
    
    StartTimerEx(0xaabb, 100, avk_pluto_scenario_005_timeout, NULL);
}



/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_006
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_scenario_006(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_group_node_struct group_info;
	mmi_frm_node_struct new_node = {0};

    MMI_ID parent = GRP_ID_INVALID;
    U32 set_data = 0x4141,*get_data;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
     /* G(Root) -  G(S1)*/
	mmi_frm_group_create(AVK_GRP_ID_1, AVK_GRP_ID_2+1, mmi_dummy_proc, NULL);
	mmi_frm_group_enter(AVK_GRP_ID_2+1, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    /* G(Root) -  G(S1)-  G(S2)*/
    mmi_frm_group_create(AVK_GRP_ID_2+1, AVK_GRP_ID_2+2, mmi_dummy_proc, NULL);
	mmi_frm_group_enter(AVK_GRP_ID_2+2, MMI_FRM_NODE_SMART_CLOSE_FLAG);

	mmi_frm_group_create(AVK_GRP_ID_1, AVK_GRP_ID_2, mmi_dummy_proc, NULL); 
	
    new_node.id = AVK_GRP_ID_2;
    new_node.entry_proc = mmi_dummy_proc;
    mmi_frm_group_insert(AVK_GRP_ID_1,AVK_GRP_ID_2+1,&new_node,MMI_FRM_NODE_BEFORE_FLAG);
	
	  /* G(Root) -  G(S1)-  G(S2)*/
    mmi_frm_group_create(AVK_GRP_ID_2+1, AVK_GRP_ID_2+3, mmi_dummy_proc, NULL);
	mmi_frm_group_enter(AVK_GRP_ID_2+3, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	
	mmi_frm_group_set_caller(AVK_GRP_ID_2+2, AVK_GRP_ID_2+3);
	//mmi_frm_group_set_priority(AVK_GRP_ID_2+3, 7);
	mmi_frm_group_set_proc_data(AVK_GRP_ID_2+3, mmi_dummy_proc, (void*)&set_data);
	
	
	get_data = (U32*)mmi_frm_group_get_user_data(AVK_GRP_ID_2+3);
	mmi_frm_group_get_info(AVK_GRP_ID_2+3, &group_info);
	

	parent = mmi_frm_group_get_top_parent_group_id(AVK_GRP_ID_2+3);


	
	if (/*state == MMI_SCENARIO_STATE_ACTIVE &&*/ parent == GRP_ID_AVK && &set_data == get_data
		/*    && group_info.priority == 7  */&& mmi_frm_group_is_present(AVK_GRP_ID_2)
			  && mmi_frm_group_is_in_active_serial(AVK_GRP_ID_2+3) == MMI_TRUE && mmi_frm_node_query_sequence(AVK_GRP_ID_1, AVK_GRP_ID_2+1, AVK_GRP_ID_2) < 0)
    {
        AVK_CASE_RESULT(AVK_PASS);
	}
	else
	{
        AVK_CASE_RESULT(AVK_FAIL);  
	}		
	
    mmi_frm_group_close(AVK_GRP_ID_2);
}




/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_007
 * DESCRIPTION
 * This api tests all the screen notification send & post
 * PARAMETERS
 *  void       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_scenario_007(void)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     mmi_group_event_struct evt;
     mmi_frm_node_struct new_node = {0};
     mmi_event_struct event;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
         /* G(Root) -  G(S1)*/
    mmi_frm_group_create(AVK_GRP_ID_1, AVK_GRP_ID_2, mmi_dummy_proc, NULL);
    mmi_frm_group_enter(AVK_GRP_ID_2, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    avk_pluto_scenario_007_entry_scrn_01();
    avk_pluto_scenario_007_entry_scrn_02();

    mmi_frm_group_create(AVK_GRP_ID_2, AVK_GRP_ID_2+1, mmi_dummy_proc, NULL);
    mmi_frm_group_enter(AVK_GRP_ID_2+1, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    avk_pluto_scenario_007_entry_scrn_03();

    mmi_frm_group_create(AVK_GRP_ID_2, AVK_GRP_ID_2+2, mmi_dummy_proc, NULL);
    mmi_frm_group_enter(AVK_GRP_ID_2+2, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    avk_pluto_scenario_007_entry_scrn_04();



    /* Group Replace Api test */
    mmi_frm_group_create(AVK_GRP_ID_2, AVK_GRP_ID_2+4, mmi_dummy_proc, NULL);
    new_node.id = 0x777;
    new_node.entry_proc = (mmi_proc_func)avk_pluto_scenario_007_entry_scrn_05;
    mmi_frm_group_replace(AVK_GRP_ID_2+2, AVK_GRP_ID_2+4, &new_node);

    
    mmi_frm_group_create(AVK_GRP_ID_2+1, AVK_GRP_ID_2+3, mmi_dummy_proc, NULL);
    mmi_frm_group_enter(AVK_GRP_ID_2+3, MMI_FRM_NODE_NONE_FLAG);

    mmi_frm_group_set_attribute(AVK_GRP_ID_2+3,MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_group_clear_attribute(AVK_GRP_ID_2+3,MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_group_set_caller(AVK_GRP_ID_2+3, AVK_GRP_ID_2+2);

     MMI_FRM_INIT_GROUP_EVENT(&evt, 0x9876, AVK_GRP_ID_2+3);
    mmi_frm_group_send_to_caller(AVK_GRP_ID_2+3, &evt);
    MMI_FRM_INIT_GROUP_EVENT(&evt, 0x1122, AVK_GRP_ID_2+3);
    mmi_frm_group_send_to_parent(AVK_GRP_ID_2+3, &evt);

    MMI_FRM_INIT_GROUP_EVENT(&evt, 0x1234, AVK_GRP_ID_2+3);
    mmi_frm_group_post_to_caller(AVK_GRP_ID_2+3, &evt);
    MMI_FRM_INIT_GROUP_EVENT(&evt, 0x5566, AVK_GRP_ID_2+3);
    mmi_frm_group_post_to_parent(AVK_GRP_ID_2+3, &evt);

    MMI_FRM_INIT_EVENT(&event, 0x5580);
    mmi_frm_scrn_send_to_parent(AVK_GRP_ID_2+3,(mmi_event_struct*)&event);

    MMI_FRM_INIT_EVENT(&event, 0x5588);
    mmi_frm_scrn_post_to_parent(AVK_GRP_ID_2+3,(mmi_event_struct*)&event);

    StartTimer(0xaabb, 100, avk_pluto_scenario_007_timeout);

        
}



/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_007_entry_scrn_01
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_scenario_007_entry_scrn_01(void) /* (G-id) - (S1) */
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_frm_scrn_enter(AVK_GRP_ID_2, 0x456, NULL, avk_pluto_scenario_007_entry_scrn_01, MMI_FRM_FULL_SCRN))
    {
        mmi_frm_display_dummy_screen();
    }
}

/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_007_entry_scrn_02
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_scenario_007_entry_scrn_02(void) /* (G-id) - (S1) */
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_frm_scrn_enter(AVK_GRP_ID_2, 0x579, NULL, avk_pluto_scenario_007_entry_scrn_02, MMI_FRM_FULL_SCRN))
    {
        mmi_frm_display_dummy_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_007_entry_scrn_03
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_scenario_007_entry_scrn_03(void) /* (G-id) - (S1) */
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_frm_scrn_enter(AVK_GRP_ID_2+1, 0x789, NULL, avk_pluto_scenario_007_entry_scrn_03, MMI_FRM_FULL_SCRN))
    {
        mmi_frm_display_dummy_screen();
    }
}

/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_007_entry_scrn_04
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_scenario_007_entry_scrn_04(void) /* (G-id) - (S1) */
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_frm_scrn_enter(AVK_GRP_ID_2+2, 0x789, NULL, avk_pluto_scenario_007_entry_scrn_04, MMI_FRM_FULL_SCRN))
    {
        mmi_frm_display_dummy_screen();
    }
}

/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_007_entry_scrn_05
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_scenario_007_entry_scrn_05(void)
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_frm_scrn_enter(AVK_GRP_ID_2+4, 0x777, NULL, avk_pluto_scenario_007_entry_scrn_05, MMI_FRM_FULL_SCRN))
    {
        mmi_frm_display_dummy_screen();
    }

}

/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_007_timeout
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_scenario_007_timeout()
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(AVK_GRP_ID_2+3);
    mmi_frm_group_close(AVK_GRP_ID_2+4);
    mmi_frm_group_close(AVK_GRP_ID_2+2);
    mmi_frm_group_close(AVK_GRP_ID_2+1);
    mmi_frm_group_close(AVK_GRP_ID_2);
    if (mmi_frm_group_get_active_id() == AVK_GRP_ID_1 && mmi_frm_group_is_in_top_scope(AVK_GRP_ID_1))
    {
        AVK_CASE_RESULT(AVK_PASS);   
    }
    else
    {
        AVK_CASE_RESULT(AVK_FAIL);
    }   
    AVK_ASYN_DONE();
}

void avk_pluto_scenario_008_timeout()
{
    mmi_frm_exec_key_handler(KEY_LSK, KEY_EVENT_DOWN);
    mmi_frm_exec_key_handler(KEY_LSK, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_008
 * DESCRIPTION
 * This api tests all the screen notification send & post
 * PARAMETERS
 *  void       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_scenario_008(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scrn_tab_page_node_struct tab_node = {0};
	U16 count = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(AVK_GRP_ID_2);
	
	g_active_tab_id = mmi_frm_scrn_tab_get_active_id();

	mmi_frm_group_create(GRP_ID_ROOT, AVK_GRP_ID_2+4, mmi_dummy_proc, NULL);
	mmi_frm_group_enter(AVK_GRP_ID_2+4, MMI_FRM_NODE_SMART_CLOSE_FLAG);

	avk_pluto_scenario_008_tab_entry();
	mmi_frm_display_dummy_screen();
	mmi_frm_scrn_close_active_id();

	mmi_frm_scrn_tab_page_get_info(AVK_GRP_ID_2+4,mmi_frm_scrn_get_active_id(),mmi_frm_scrn_tab_page_get_active_id(),&tab_node);

	if (tab_node.user_data == mmi_frm_scrn_tab_page_get_user_data(mmi_frm_group_get_active_id(),mmi_frm_scrn_get_active_id(),mmi_frm_scrn_tab_page_get_active_id()))
	{
      count++;
	}

	if (tab_node.gui_buf == mmi_frm_scrn_tab_page_get_gui_buf(AVK_GRP_ID_2+4,mmi_frm_scrn_get_active_id(),mmi_frm_scrn_tab_page_get_active_id()))
	{
	  count++;

	}

	if (tab_node.input_buf == mmi_frm_scrn_tab_page_get_input_buf(AVK_GRP_ID_2+4,mmi_frm_scrn_get_active_id(),mmi_frm_scrn_tab_page_get_active_id()))
	{
	 count++;
	}


	if (!(mmi_frm_scrn_tab_page_get_state(mmi_frm_group_get_active_id(),mmi_frm_scrn_get_active_id(),mmi_frm_scrn_tab_page_get_active_id()) == MMI_SCENARIO_STATE_ACTIVE && count == 3))
	   {
		   AVK_CASE_RESULT(AVK_FAIL);
	       mmi_frm_group_close(AVK_GRP_ID_2+4);
		  return;

	   }
   
	/* Press 1 key to get the output */

	mmi_frm_scrn_set_key_proc(AVK_GRP_ID_2+4,mmi_frm_scrn_get_active_id(),avk_pluto_scenario_008_screen_key_proc);

    StartTimer(0xaabb, 100, avk_pluto_scenario_008_timeout);
		
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_008_screen_key_proc
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret avk_pluto_scenario_008_screen_key_proc(mmi_event_struct *evt)
{
 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;
    U8 key_code = key_evt->key_code;
    U8 key_type = key_evt->key_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_evt->evt_id == EVT_ID_ON_KEY)
	{
	   if ((key_code == KEY_CSK || key_code == KEY_LSK ) && key_type == KEY_EVENT_UP)
	   {
	       mmi_frm_group_close(AVK_GRP_ID_2+4);

		   if (g_active_tab_id == mmi_frm_scrn_tab_get_active_id()) 
	      {
			   AVK_CASE_RESULT(AVK_PASS);
	      }
	      else
	      {
			   AVK_CASE_RESULT(AVK_FAIL);
	      }
            return MMI_RET_KEY_HANDLED;
	    }

    }
	return MMI_RET_OK; 
}

/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_008_tab_entry
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_scenario_008_tab_entry(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_tab_struct tab_pages_info_array[2];

    tab_pages_info_array[0].screen_id = 0x1201;
    tab_pages_info_array[0].tab_entry_func = (FuncPtr)avk_pluto_scenario_008_category199_tab_01;
    tab_pages_info_array[0].tab_icon = (U8*)GetImage(gIndexIconsImageList[0]);
    tab_pages_info_array[0].tab_string = NULL;
    tab_pages_info_array[0].user_data = NULL;

    
    tab_pages_info_array[1].screen_id = 0x1202;
    tab_pages_info_array[1].tab_entry_func = (FuncPtr)avk_pluto_scenario_008_inline_tab_01;
    tab_pages_info_array[1].tab_icon = (U8*)GetImage(gIndexIconsImageList[1]);
    tab_pages_info_array[1].tab_string = NULL;
    tab_pages_info_array[1].user_data = NULL;
    
    mmi_frm_scrn_tab_enter (AVK_GRP_ID_2+4, 0x1200, NULL, avk_pluto_scenario_008_tab_entry, tab_pages_info_array, 2, 0);

	mmi_frm_scrn_tab_change_page_index(AVK_GRP_ID_2+4,0x1200,1);

	if (!(mmi_frm_scrn_tab_get_active_page_index() == 1))
	{
	   AVK_CASE_RESULT(AVK_FAIL);
       mmi_frm_group_close(AVK_GRP_ID_2+4);
		return;
	}
	

}

/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_008_category199_tab_01
 * DESCRIPTION
 * 
 * PARAMETERS
 *  mmi_scrn_essential_struct       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_scenario_008_category199_tab_01(mmi_scrn_essential_struct *data)
{


    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL; 

	 U8 display_buffer[100];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	
  

    
    if (mmi_frm_scrn_tab_page_enter(data->group_id, mmi_frm_scrn_get_active_id(), data->scrn_id, NULL, (FuncPtr)avk_pluto_scenario_008_category199_tab_01, MMI_FRM_TAB_PAGE) == MMI_FALSE)
    {
        return;
    }

	
    guiBuffer = mmi_frm_scrn_tab_page_get_active_gui_buf();

    RegisterCat200SearchFunction(cat200_callback1);

	

    ShowCategory199Screen(
            get_string(STR_GLOBAL_OK),
            0,
            get_string(STR_GLOBAL_BACK),
            0,                 
            (S8)0,
            get_string(STR_GLOBAL_SEARCHING),
            NULL,
            4,
            (GetItemFuncPtr)Get_List_Items1,
            get_async_hints1,
            NULL,
            NULL,
            0,
            (U8*) display_buffer,
            4,
            guiBuffer);


    /* Set the key handlers */
    SetLeftSoftkeyFunction(avk_pluto_scenario_008_pass, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


void avk_pluto_scenario_008_pass()
{
     AVK_CASE_RESULT(AVK_PASS);
     mmi_frm_group_close(AVK_GRP_ID_2+4);   
     AVK_ASYN_DONE();
}
/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_008_inline_tab_01
 * DESCRIPTION
 * 
 * PARAMETERS
 *  mmi_scrn_essential_struct       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_scenario_008_inline_tab_01 (mmi_scrn_essential_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  /*  U8 *guiBuffer = NULL;
	WCHAR *inputBuffer = NULL;
    S32 index;
    U16 nImgIds[8];
	U8 data2 = 13;*/
    U8 *guiBuffer = NULL;
    S32 index;
    U16 nImgIds[6];
 

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    if (mmi_frm_scrn_tab_page_enter(data->group_id, mmi_frm_scrn_get_active_id(), data->scrn_id, NULL, (FuncPtr)avk_pluto_scenario_008_inline_tab_01, MMI_FRM_TAB_PAGE))
    {

	    for (index = 0; index < 6; index++)
        {
            //memcpy(subMenuData[index], strName[index], 10);
            kal_wsprintf((unsigned short *)subMenuData[index], "Name%d", index+1);
            subMenuDataPtrs[index] = subMenuData[index];
            nImgIds[index] = IMG_GLOBAL_L1 + index;
            //memcpy(subMenuData[index + 6], strphonenumber, 22);
            kal_wsprintf((unsigned short *)subMenuData[index + 6], "9875656578");
            subMenuDataPtrs[index + 6] = subMenuData[index + 6]; 
        }

        //guiBuffer = mmi_frm_get_cur_tab_gui_buffer(SCR_ID_CSB_DUMMY_SCR_ID + 1);        
        guiBuffer   = mmi_frm_scrn_tab_page_get_active_gui_buf(); 

   
        ShowCategory626Screen(
            (U8*)GetString(STR_GLOBAL_PICTURE),
            0,
            STR_GLOBAL_OK,
            0,
            STR_GLOBAL_BACK,
            0,
            6,
            subMenuDataPtrs,
            (U16*) nImgIds,
            &subMenuDataPtrs[6],
            LIST_MENU,
            0,
            0,
            guiBuffer);
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
    #endif /* __MMI_TOUCH_SCREEN__ */
        /* Set the key handlers */
    SetLeftSoftkeyFunction(avk_pluto_scenario_008_pass, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
        
    }

       
}

	
/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_009
 * DESCRIPTION
 * This api tests the tab scrn scenarios
 * PARAMETERS
 *  void       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_scenario_009(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_active_tab_id = mmi_frm_scrn_tab_get_active_id();
	mmi_frm_group_create(AVK_GRP_ID_1, AVK_GRP_ID_2, mmi_dummy_proc, NULL);
	mmi_frm_group_enter(AVK_GRP_ID_2, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	

	avk_pluto_scenario_009_tab_entry();
	mmi_frm_display_dummy_screen();
	//avk_pluto_scenario_004_entry_scrn_01();
	mmi_frm_scrn_close_active_id();

	//SetKeyHandler(avk_pluto_scenario_009_timeout, KEY_CSK, KEY_EVENT_UP);

	//StartTimer(0xaabb, 5000, avk_pluto_scenario_009_timeout);

	avk_pluto_scenario_009_timeout();

	

}



/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_009_timeout
 * DESCRIPTION
 * This api tests the tab scrn scenarios
 * PARAMETERS
 *  void       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_scenario_009_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(AVK_GRP_ID_2);
	if (g_active_tab_id == mmi_frm_scrn_tab_get_active_id())
	{
		AVK_CASE_RESULT(AVK_PASS);
	    

	}
	else
	{ 
		AVK_CASE_RESULT(AVK_FAIL);
	    
	}


}

/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_009_tab_entry
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_scenario_009_tab_entry(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	mmi_frm_tab_struct tab_pages_info_array[4];
	S32 sel_idx = 0;
	U16 data = 22;
	U16 data1 = 33;


    
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

   

	    if (mmi_frm_is_in_backward_scenario())
		{


		   tab_pages_info_array[0].screen_id = 0x1201;
		   tab_pages_info_array[0].tab_entry_func = (FuncPtr)avk_pluto_scenario_008_category199_tab_01;
		   tab_pages_info_array[0].tab_icon = (U8*)GetImage(gIndexIconsImageList[0]);
		   tab_pages_info_array[0].tab_string = NULL;
		   tab_pages_info_array[0].user_data = (void*)&data;

		   tab_pages_info_array[1].screen_id = 0x1202;
		   tab_pages_info_array[1].tab_entry_func = (FuncPtr)avk_pluto_scenario_008_inline_tab_01;
		   tab_pages_info_array[1].tab_icon = (U8*)GetImage(gIndexIconsImageList[1]);
		   tab_pages_info_array[1].tab_string = NULL;
		   tab_pages_info_array[1].user_data = (void*)&data;


		   tab_pages_info_array[2].screen_id = 0x1203;
		   tab_pages_info_array[2].tab_entry_func = (FuncPtr)avk_pluto_scenario_008_category199_tab_01;
		   tab_pages_info_array[2].tab_icon = (U8*)GetImage(gIndexIconsImageList[2]);
		   tab_pages_info_array[2].tab_string = NULL;
		   tab_pages_info_array[2].user_data = (void*)&data;

		   tab_pages_info_array[3].screen_id = 0x1204;
		   tab_pages_info_array[3].tab_entry_func = (FuncPtr)avk_pluto_scenario_008_inline_tab_01;
		   tab_pages_info_array[3].tab_icon = (U8*)GetImage(gIndexIconsImageList[3]);
		   tab_pages_info_array[3].tab_string = NULL;
		   tab_pages_info_array[3].user_data = (void*)&data;

			sel_idx = 3;
			mmi_frm_scrn_tab_change_page_items(AVK_GRP_ID_2, 0x1200, tab_pages_info_array, 4);


			
		}
		else
		{
		    tab_pages_info_array[0].screen_id = 0x2401;
		   tab_pages_info_array[0].tab_entry_func = (FuncPtr)avk_pluto_scenario_008_category199_tab_01;
		   tab_pages_info_array[0].tab_icon = (U8*)GetImage(gIndexIconsImageList[0]);
		   tab_pages_info_array[0].tab_string = NULL;
		   tab_pages_info_array[0].user_data = (void*)&data;

		   tab_pages_info_array[1].screen_id = 0x2402;
		   tab_pages_info_array[1].tab_entry_func = (FuncPtr)avk_pluto_scenario_008_inline_tab_01;
		   tab_pages_info_array[1].tab_icon = (U8*)GetImage(gIndexIconsImageList[1]);
		   tab_pages_info_array[1].tab_string = NULL;
		   tab_pages_info_array[1].user_data = (void*)&data;

	
	 
	 	}
		mmi_frm_scrn_tab_enter (AVK_GRP_ID_2, (MMI_ID)0x1200, NULL, avk_pluto_scenario_009_tab_entry, tab_pages_info_array, 2, (U8)sel_idx);

		mmi_frm_scrn_tab_page_set_user_data(AVK_GRP_ID_2,0x1200,0x2401,(void*)&data1);
       
		/*if (flag)
	   {
          mmi_display_popup((WCHAR*)(UI_string_type)L"Tab screen test", MMI_EVENT_SUCCESS);
          flag = MMI_FALSE;
	   } */
	    
	



}



/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_010
 * DESCRIPTION
 * This api tests the scenarios apis
 * PARAMETERS
 *  void       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_scenario_010(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
	mmi_app_scenario_struct scenario_info;

       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&scenario_info,0,sizeof(scenario_info));
    
    mmi_frm_deinit_scenario();
	mmi_frm_init_scenario();

	mmi_frm_start_scenario(MMI_SCENARIO_ID_GENERAL);
    
	
  
     scenario_info.scenario_id = MMI_SCENARIO_ID_GENERAL;
	 mmi_frm_get_scenario_info(&scenario_info);
	  
	 if (scenario_info.scrn_priority == MMI_SCEN_SCRN_PRIO_MEDIUM 
		  && scenario_info.snd_priority == MMI_SCEN_SND_PRIO_LOW
		   && scenario_info.vib_priority == MMI_SCEN_VIB_PRIO_MEDIUM
		    && scenario_info.bl_priority == MMI_SCEN_BL_PRIO_MEDIUM)
	{
		 AVK_CASE_RESULT(AVK_PASS);
	}
	else
	{ 
		 AVK_CASE_RESULT(AVK_FAIL);	   
	}



	mmi_frm_end_scenario(MMI_SCENARIO_ID_GENERAL);

}



/*****************************************************************************
 * FUNCTION
 *  avk_pluto_scenario_011
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_scenario_011(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_active_tab_id = MMI_TRUE;
//    mmi_frm_entry_new_screen(AVK_SCR_ID_1, avk_pluto_scenario_scrn_exit_A, (entry_func_ptr)avk_pluto_scenario_scrn_enter_A, NULL);
	mmi_frm_group_create(AVK_GRP_ID_1, AVK_GRP_ID_2, mmi_dummy_proc, NULL);
    mmi_frm_group_enter(AVK_GRP_ID_2, MMI_FRM_NODE_NONE_FLAG);
    mmi_frm_scrn_enter(AVK_GRP_ID_2, AVK_SCR_ID_2, (FuncPtr)avk_pluto_scenario_scrn_exit_B, (FuncPtr)avk_pluto_scenario_scrn_enter_B, MMI_FRM_FULL_SCRN);
    mmi_frm_scrn_enter(AVK_GRP_ID_2, AVK_SCR_ID_1, (FuncPtr)avk_pluto_scenario_scrn_exit_C, (FuncPtr)avk_pluto_scenario_scrn_enter_C, MMI_FRM_FULL_SCRN);

    mmi_frm_scrn_close(AVK_GRP_ID_2, AVK_SCR_ID_1);
    mmi_frm_group_close(AVK_GRP_ID_2);
    
	if (g_active_tab_id == MMI_TRUE)
	{
		AVK_CASE_RESULT(AVK_PASS);
	  
	}


}

void avk_pluto_scenario_check_scrn_id(U16 ep_a_gid, U16 ep_a_sid, U16 ep_e_gid, U16 ep_e_sid)
{
    U16 group_id = GRP_ID_INVALID;
    U16 scrn_id  = SCR_ID_INVALID;
    
    if ((GetActiveScreenId() == ep_a_sid)
		 && (GetExitScrnID() == ep_e_sid))
	{
		 mmi_frm_get_exit_scrn_id(&group_id, &scrn_id);
         if (!(group_id == ep_e_gid && scrn_id == ep_e_sid))
		{ 
			AVK_CASE_RESULT(AVK_FAIL);
			 
			 mmi_frm_group_close(AVK_GRP_ID_2);
			 g_active_tab_id = MMI_FALSE;
			 return;

		}
	}
	
}

mmi_ret avk_pluto_scenario_scrn_enter_A(mmi_scrn_essential_struct *data)
{
    return MMI_RET_OK;
}

void avk_pluto_scenario_scrn_exit_A(void *arg)
{
    avk_pluto_scenario_check_scrn_id(AVK_GRP_ID_1, AVK_GRP_ID_2, AVK_GRP_ID_1, AVK_SCR_ID_1);
}

mmi_ret avk_pluto_scenario_scrn_enter_B(mmi_scrn_essential_struct *data)
{
    return MMI_RET_OK;
}

mmi_ret avk_pluto_scenario_scrn_exit_B(mmi_scrn_essential_struct *data)
{
    avk_pluto_scenario_check_scrn_id(AVK_GRP_ID_2, AVK_SCR_ID_1, AVK_GRP_ID_2, AVK_SCR_ID_2);
    return MMI_RET_OK;
}

mmi_ret avk_pluto_scenario_scrn_enter_C(mmi_scrn_essential_struct *data)
{
    return MMI_RET_OK;
}

mmi_ret avk_pluto_scenario_scrn_exit_C(mmi_scrn_essential_struct *data)
{
    avk_pluto_scenario_check_scrn_id(AVK_GRP_ID_2, AVK_SCR_ID_2, AVK_GRP_ID_2, AVK_SCR_ID_1);
    return MMI_RET_OK;
}
