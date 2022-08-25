#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
extern "C"
{
#include "mms_sap_struct.h"
#include "MmsSrvGprot.h"
#include "app_asyncfile.h"
extern void *srv_mms_mem_mgr_app_adm_alloc(U32 size);
extern void srv_mms_mem_mgr_app_adm_free(void *pmem);

}

AVK_ADD_ITEM(AVK_MSG_MMS_AUTO,L"Auto case",AVK_MSG_MMS);
AVK_ADD_ITEM(AVK_MSG_MMS_MANU,L"Manual case",AVK_MSG_MMS);


extern "C" void avk_msg_mms_001_cb_save(srv_mms_result_enum result, void *rsp_data, void * user_data)
{
	AVK_CASE_RESULT(result == SRV_MMS_RESULT_OK);
	AVK_ASYN_DONE();
}

extern "C" void avk_msg_mms_001_cb(srv_mms_result_enum result, void *rsp_data, void * user_data)
{
	srv_mms_create_rsp_struct *msg_rsp = (srv_mms_create_rsp_struct*) rsp_data;	
	srv_mms_save_req_struct param_mms_1;

	if(msg_rsp->min_fs_space_required<=0)
	{
	    AVK_LOG_FUN(srv_mms_create,AVK_PASS);
		param_mms_1.app_id = msg_rsp->app_id;
		param_mms_1.call_back = avk_msg_mms_001_cb_save;
		param_mms_1.msg_id[0] = msg_rsp->msg_id;
		param_mms_1.no_of_msg =1;
		param_mms_1.user_data = (void*)433;
		param_mms_1.box = MMA_FOLDER_DRAFT;
		AVK_LOG_ASYN(result = (srv_mms_result_enum)srv_mms_save(&param_mms_1));
		if (result != SRV_MMS_RESULT_OK)
		{
		    AVK_CASE_RESULT(AVK_FAIL);
	        AVK_ASYN_DONE();
		}
	}
	else
	{
        AVK_LOG_FUN(srv_mms_create,AVK_FAIL);
        AVK_ASYN_DONE();
    }        
}

/*****************************************************************************
 * FUNCTION
 *  avk_msg_mms_001
 * DESCRIPTION
 *  send mms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_ASYN_CASE(AVK_MSG_MMS_AUTO_001,AVK_MSG_MMS_AUTO)
{
       /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_mms_create_req_struct param_mms;
	WCHAR file_path[64];
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_wstrcpy((WCHAR*)file_path,(WCHAR*)AVK_TEST_FILE_PATH);
    kal_wstrcat((WCHAR*)file_path,(WCHAR*)L"avk_msg_mms\\MMS.txt");
    memset(&param_mms, 0, sizeof(srv_mms_create_req_struct));
	param_mms.app_id = MMA_APP_ID_MMS_APP;
	param_mms.call_back = avk_msg_mms_001_cb;
	param_mms.mode = MMA_MODE_EDIT;
	//mmi_wcscpy(param_mms.msg_file_path,L"D:\\AVK\\test file\\avk_msg_mms\\MMS.txt");
	param_mms.msg_id = 0;
	param_mms.sim_id =MMA_SIM_ID_SIM1;
	param_mms.user_data = (void*)433;
	param_mms.op_type = SRV_MMS_CREATE_MMS;
	mmi_wcscpy((WCHAR *)param_mms.xml_filepath,(const WCHAR *)file_path);
	param_mms.xml_size=  applib_get_file_size(param_mms.xml_filepath);
	if (SRV_MMS_RESULT_OK != srv_mms_create(&param_mms))
	{
	    AVK_LOG_FUN(srv_mms_create,AVK_FAIL);
	    AVK_ASYN_DONE();
	}
	
	//    mms_text_insert_hdlr((S8*) subject, mmi_wcslen(subject), (S8*) content, mmi_wcslen(content));

}

extern "C" void avk_msg_mms_022_cb(srv_mms_result_enum result, void *rsp_data, void * user_data)
{
	AVK_CASE_RESULT(result == SRV_MMS_RESULT_OK);
    AVK_ASYN_DONE();
}

extern "C" void avk_msg_mms_021_cb(srv_mms_result_enum result, void *rsp_data, void * user_data)
{	


    /*----------------------------------------------------------------*/
    /* Local Variables												*/
    /*----------------------------------------------------------------*/
	srv_mms_create_rsp_struct *msg_rsp = (srv_mms_create_rsp_struct*) rsp_data;	  
	srv_mms_delete_req_struct param_mms; 
	S32 result_mms = SRV_MMS_RESULT_FAIL;
	
    /*----------------------------------------------------------------*/
    /* Code Body														*/
    /*----------------------------------------------------------------*/	  
    param_mms.app_id = MMA_APP_ID_MMS_APP;
    param_mms.box = MMA_FOLDER_DRAFT;
    param_mms.call_back = avk_msg_mms_022_cb;
    param_mms.msg_id[0] = msg_rsp->msg_id;
    param_mms.no_of_msg = 1;
    param_mms.user_data = (void*)433;
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
    AVK_LOG_ASYN(result_mms = srv_mms_delete(&param_mms));
#endif
    if (result != SRV_MMS_RESULT_OK)
    {
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();
    }
}

extern "C" void avk_msg_mms_02_cb(srv_mms_result_enum result, void *rsp_data, void * user_data)
{
	srv_mms_create_rsp_struct *msg_rsp = (srv_mms_create_rsp_struct*) rsp_data;	
	srv_mms_save_req_struct param_mms_1;

	if(msg_rsp->min_fs_space_required<=0)
	{
	    AVK_LOG_FUN(srv_mms_create,AVK_PASS);
		param_mms_1.app_id = msg_rsp->app_id;
		param_mms_1.call_back = avk_msg_mms_021_cb;
		param_mms_1.msg_id[0] = msg_rsp->msg_id;
		param_mms_1.no_of_msg =1;
		param_mms_1.user_data = (void*)433;
		param_mms_1.box = MMA_FOLDER_DRAFT;
		AVK_LOG_ASYN(result = (srv_mms_result_enum)srv_mms_save(&param_mms_1));
		if (result != SRV_MMS_RESULT_OK)
		{
		    AVK_CASE_RESULT(AVK_FAIL);
	        AVK_ASYN_DONE();
		}
	}
	else
	{
        AVK_LOG_FUN(srv_mms_create,AVK_FAIL);
        AVK_ASYN_DONE();
    }
}



/*****************************************************************************
 * FUNCTION
 *  avk_msg_mms_002
 * DESCRIPTION
 *  send mms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_ASYN_CASE(AVK_MSG_MMS_AUTO_002,AVK_MSG_MMS_AUTO)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_mms_create_req_struct param_mms;
	WCHAR file_path[64];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_wstrcpy((WCHAR*)file_path,(WCHAR*)AVK_TEST_FILE_PATH);
    kal_wstrcat((WCHAR*)file_path,(WCHAR*)L"avk_msg_mms\\MMS.txt");
    memset(&param_mms, 0, sizeof(srv_mms_create_req_struct));
	param_mms.app_id = MMA_APP_ID_MMS_APP;
	param_mms.call_back = avk_msg_mms_02_cb;
	param_mms.mode = MMA_MODE_EDIT;
	//mmi_wcscpy(param_mms.msg_file_path,L"D:\\AVK\\test file\\avk_msg_mms\\MMS.txt");
	param_mms.msg_id = 0;
	param_mms.sim_id =MMA_SIM_ID_SIM1;
	param_mms.user_data = (void*)433;
	param_mms.op_type = SRV_MMS_CREATE_MMS;
	mmi_wcscpy((WCHAR *)param_mms.xml_filepath,(const WCHAR *)file_path);
	param_mms.xml_size=  applib_get_file_size(param_mms.xml_filepath);
	if (SRV_MMS_RESULT_OK != srv_mms_create(&param_mms))
	{
	    AVK_LOG_FUN(srv_mms_create,AVK_FAIL);
	    AVK_ASYN_DONE();
	}
}

extern "C" void avk_msg_mms_031_cb(srv_mms_result_enum result, void *rsp_data, void * user_data)
{
	srv_mms_get_content_rsp_struct *msg_rsp = (srv_mms_get_content_rsp_struct*) rsp_data;

    AVK_LOG_FUN(srv_mms_get_content,AVK_PASS);
    AVK_ASYN_DONE();
}

extern "C" void avk_msg_mms_03_cb(srv_mms_result_enum result, void *rsp_data, void * user_data)
{
	srv_mms_create_rsp_struct *msg_rsp = (srv_mms_create_rsp_struct*) rsp_data;	
	srv_mms_get_content_req_struct param_mms_1;

	if(msg_rsp->min_fs_space_required<=0)
	{
	    AVK_LOG_FUN(srv_mms_create,AVK_PASS);
		param_mms_1.app_id = 0;
		param_mms_1.call_back = avk_msg_mms_031_cb;
		param_mms_1.msg_id = msg_rsp->msg_id;
		param_mms_1.creation_mode = MMA_CREATION_MODE_FREE;
		param_mms_1.mode = MMA_MODE_EDIT;
		param_mms_1.user_data = (void*)423;
        if (SRV_MMS_RESULT_OK != srv_mms_get_content(&param_mms_1))
    	{
    	    AVK_LOG_FUN(srv_mms_get_content,AVK_FAIL);
    	    AVK_ASYN_DONE();
    	}
	}
	else
	{
	    AVK_LOG_FUN(srv_mms_create,AVK_FAIL);
	    AVK_ASYN_DONE();
	}
}
/*****************************************************************************
 * FUNCTION
 *  avk_msg_mms_003
 * DESCRIPTION
 *  send mms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_ASYN_CASE(AVK_MSG_MMS_AUTO_003,AVK_MSG_MMS_AUTO)
{  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 result_mms = 0;
	srv_mms_create_req_struct param_mms;
	WCHAR file_path[64];	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_wstrcpy((WCHAR*)file_path,(WCHAR*)AVK_TEST_FILE_PATH);
    kal_wstrcat((WCHAR*)file_path,(WCHAR*)L"avk_msg_mms\\MMS.txt");
    memset(&param_mms, 0, sizeof(srv_mms_create_req_struct));
	param_mms.app_id = MMA_APP_ID_MMS_APP;
	param_mms.call_back = avk_msg_mms_03_cb;
	param_mms.mode = MMA_MODE_EDIT;
	param_mms.msg_id = 0;
	param_mms.sim_id =MMA_SIM_ID_SIM1;
	param_mms.user_data = (void*)433;
	param_mms.op_type = SRV_MMS_CREATE_MMS;
	mmi_wcscpy((WCHAR *)param_mms.xml_filepath,(const WCHAR *)file_path);
	param_mms.xml_size=  applib_get_file_size(param_mms.xml_filepath);
	if (SRV_MMS_RESULT_OK != srv_mms_create(&param_mms))
	{
	    AVK_LOG_FUN(srv_mms_create,AVK_FAIL);
	    AVK_ASYN_DONE();
	}	
}

#if (defined(__MMI_UMMS_PST__) || defined(__MMI_UMMS_JSR205__))
/*****************************************************************************
 * FUNCTION
 *  avk_msg_mms_004
 * DESCRIPTION
 *  send mms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern "C" void avk_msg_mms_004_cb(srv_mms_result_enum result, void *rsp_data, void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables													*/
    /*----------------------------------------------------------------*/
	  
	U16 *screen_string;
  	S8 str_a[10];
	S8 str_temp[5];
	srv_mms_get_msg_num_rsp_struct *msg_rsp= (srv_mms_get_msg_num_rsp_struct*) rsp_data;
	
    /*----------------------------------------------------------------*/
    /* Code Body														*/
    /*----------------------------------------------------------------*/
	screen_string= (U16*) AVK_MALLOC(1024);
	
	mmi_wcscpy(screen_string, (WCHAR *)L"NO of Messages:\n 1. Drafts = ");
	sprintf((PS8)str_temp,(PS8)"%d",msg_rsp->rsp_tb[0]);
    mmi_asc_to_ucs2(str_a,str_temp);
	mmi_wcscat(screen_string,(WCHAR *)str_a);
	mmi_wcscat(screen_string,(WCHAR *)L"\n 2. Inbox = ");
	sprintf((PS8)str_temp,(PS8)"%d",msg_rsp->rsp_tb[1]);
    mmi_asc_to_ucs2(str_a,str_temp);
	mmi_wcscat(screen_string,(WCHAR *)str_a);
	mmi_wcscat(screen_string,(WCHAR *)L"\n 3. Outbox = ");
	sprintf((PS8)str_temp,(PS8)"%d",msg_rsp->rsp_tb[2]);
    mmi_asc_to_ucs2(str_a,str_temp);
	mmi_wcscat(screen_string,(WCHAR *)str_a);

    AVK_MANU_SHOW_SCR(screen_string,NULL,NULL);
	AVK_FREE(screen_string);
}


/*****************************************************************************
 * FUNCTION
 *  avk_msg_mms_004
 * DESCRIPTION
 *  send mms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_MANUAL_CASE(AVK_MSG_MMS_MANU_004,AVK_MSG_MMS_MANU)
{
	/*----------------------------------------------------------------*/
	  /* Local Variables												*/
	  /*----------------------------------------------------------------*/
	  
	srv_mms_get_msg_num_req_struct param_mms; 
	S32 result_mms = 0;
	
    param_mms.app_id = MMA_APP_ID_MMS_APP;
    param_mms.call_back = avk_msg_mms_004_cb;
    param_mms.req_tb[0]= MMA_QUERY_OPTION_NUM_TOTAL_DRAFT_MSG;
    param_mms.req_tb[1]=MMA_QUERY_OPTION_NUM_TOTAL_INBOX_MSG;
    param_mms.req_tb[2]=MMA_QUERY_OPTION_NUM_TOTAL_OUTBOX_MSG;
    param_mms.user_data = (void*)433;
    if (AVK_LOG_ASYN(SRV_MMS_RESULT_OK != srv_mms_get_msg_num(&param_mms)))
    {
        AVK_CASE_RESULT(AVK_FAIL);
	    AVK_ASYN_DONE();
    }	
}
#endif
extern "C" void avk_msg_mms_0051_cb(srv_mms_result_enum result, void *rsp_data, void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables													*/
    /*----------------------------------------------------------------*/	  
    wap_mma_get_msg_info_rsp_struct *msg_rsp = (wap_mma_get_msg_info_rsp_struct*) rsp_data;
	
    /*----------------------------------------------------------------*/
    /* Code Body														*/
    /*----------------------------------------------------------------*/
    AVK_CASE_RESULT(AVK_PASS);
	AVK_ASYN_DONE();
}

extern "C" void avk_msg_mms_005_cb(srv_mms_result_enum result, void *rsp_data, void * user_data)
{

	/*----------------------------------------------------------------*/
	  /* Local Variables												*/
	  /*----------------------------------------------------------------*/
	srv_mms_create_rsp_struct *msg_rsp = (srv_mms_create_rsp_struct*) rsp_data;	  
	srv_mms_mma_get_msg_info_req_struct param_mms; 
	
    /*----------------------------------------------------------------*/
    /* Code Body														*/
    /*----------------------------------------------------------------*/
    if(msg_rsp->min_fs_space_required<=0)
#if (defined(__MMI_UMMS_PST__) || defined(__MMI_UMMS_JSR205__))
    {
        AVK_LOG_FUN(srv_mms_create,AVK_PASS);
        param_mms.app_id = msg_rsp->app_id;
        param_mms.call_back = avk_msg_mms_0051_cb;
        param_mms.user_data = (void*)433;
        param_mms.msg_id= msg_rsp->msg_id;
        if (AVK_LOG_ASYN(SRV_MMS_RESULT_OK != srv_mms_mma_get_msg_info(&param_mms)))
        {
            AVK_CASE_RESULT(AVK_FAIL);
	        AVK_ASYN_DONE();
        }
    }
    else
    {
        AVK_LOG_FUN(srv_mms_create,AVK_FAIL);
	    AVK_ASYN_DONE();
    }
#else
	{
        AVK_LOG_FUN(srv_mms_create,AVK_PASS);
        
		AVK_CASE_RESULT(AVK_PASS);
	    AVK_ASYN_DONE();
    }
    else
    {
        AVK_LOG_FUN(srv_mms_create,AVK_FAIL);
	    AVK_ASYN_DONE();
    }

#endif
	  
}

AVK_ASYN_CASE(AVK_MSG_MMS_AUTO_005,AVK_MSG_MMS_AUTO)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 result_mms = 0;
	srv_mms_create_req_struct param_mms;
	WCHAR file_path[64];
    
	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wstrcpy((WCHAR*)file_path,(WCHAR*)AVK_TEST_FILE_PATH);
    kal_wstrcat((WCHAR*)file_path,(WCHAR*)L"avk_msg_mms\\MMS.txt");
    memset(&param_mms, 0, sizeof(srv_mms_create_req_struct));
	param_mms.app_id = MMA_APP_ID_MMS_APP;
	param_mms.call_back = avk_msg_mms_005_cb;
	param_mms.mode = MMA_MODE_EDIT;
	param_mms.msg_id = 0;
	param_mms.sim_id =MMA_SIM_ID_SIM1;
	param_mms.user_data = (void*)433;
	param_mms.op_type = SRV_MMS_CREATE_MMS;
	mmi_wcscpy((WCHAR *)param_mms.xml_filepath, (const WCHAR *)file_path);
	param_mms.xml_size=  applib_get_file_size(param_mms.xml_filepath);
	if (SRV_MMS_RESULT_OK != srv_mms_create(&param_mms))
	{
	    AVK_LOG_FUN(srv_mms_create,AVK_FAIL);
	    AVK_ASYN_DONE();
	}	
}


extern "C" void avk_msg_mms_0071_cb (srv_mms_result_enum result,void * rsp_data,void * user_data)
{
	/*---------------------------------------------------------------- */
    /* Local Variables                                               						    */
    /*----------------------------------------------------------------*/

	
	U16 *screen_string;
  	S8 str_a[10];
	S8 str_temp[5];
	srv_mms_property_rsp_struct *msg_rsp = (srv_mms_property_rsp_struct*) rsp_data;
	
    /*----------------------------------------------------------------*/
    /* Code Body														*/
    /*----------------------------------------------------------------*/
    screen_string= (U16*) AVK_MALLOC(1024);

    mmi_wcscpy(screen_string, (WCHAR *)L" 1.Message ID :");
    sprintf((PS8)str_temp,(PS8)"%d",msg_rsp->msg_property[0].msg_id);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_wcscat(screen_string,(WCHAR *)str_a);

    mmi_wcscat(screen_string,(WCHAR *)L"\n 2.Is Valid : ");
    if(msg_rsp->msg_property[0].is_valid)
    {
    	mmi_wcscat(screen_string,(WCHAR *)L"True");	
    }
    else
    {
    	mmi_wcscat(screen_string,(WCHAR *)L"False");	
    }

    mmi_wcscat(screen_string,(WCHAR *)L"\n 3.Is Read ");
    if(msg_rsp->msg_property[0].is_read)
    {
    	mmi_wcscat(screen_string,(WCHAR *)L"True");	
    }
    else
    {
    	mmi_wcscat(screen_string,(WCHAR *)L"False");	
    }

    AVK_MANU_SHOW_SCR(screen_string,NULL,NULL);
    AVK_FREE(screen_string);
	
}

extern "C" void avk_msg_mms_007_cb(srv_mms_result_enum result, void *rsp_data,void * user_data)
{
	/*---------------------------------------------------------------- */
    /* Local Variables                                              						    */
    /*----------------------------------------------------------------*/
	srv_mms_create_rsp_struct *msg_rsp = (srv_mms_create_rsp_struct*) rsp_data;	
	srv_mms_property_req_struct param_mms;
	
    /*---------------------------------------------------------------- */
    /* Code Body                                                      						    */
    /*----------------------------------------------------------------*/
	param_mms.app_id = msg_rsp->app_id;
	param_mms.call_back = avk_msg_mms_0071_cb;
	param_mms.msg_id[0] = msg_rsp->msg_id;
	param_mms.no_of_msg = 1;
	param_mms.user_data = (void*)123;
	if (0 != AVK_LOG_ASYN(srv_mms_get_msg_property_list(&param_mms)))
	{
	    AVK_CASE_RESULT(AVK_FAIL);
	    AVK_ASYN_DONE();
	}
}

AVK_MANUAL_CASE(AVK_MSG_MMS_MANU_007,AVK_MSG_MMS_MANU)
{
	/*---------------------------------------------------------------- */
    /* Local Variables                                               						    */
    /*----------------------------------------------------------------*/
	S32 result_mms = 0;
	srv_mms_create_req_struct param_mms;
	WCHAR file_path[64];    
	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_wstrcpy((WCHAR*)file_path,(WCHAR*)AVK_TEST_FILE_PATH);
    kal_wstrcat((WCHAR*)file_path,(WCHAR*)L"avk_msg_mms\\MMS.txt");
    memset(&param_mms, 0, sizeof(srv_mms_create_req_struct));
	param_mms.app_id = MMA_APP_ID_MMS_APP;
	param_mms.call_back = avk_msg_mms_007_cb;
	param_mms.mode = MMA_MODE_EDIT;
	//mmi_wcscpy(param_mms.msg_file_path,L"D:\\AVK\\test file\\avk_msg_mms\\MMS.txt");
	param_mms.msg_id = 0;
	param_mms.sim_id =MMA_SIM_ID_SIM1;
	param_mms.user_data = (void*)433;
	param_mms.op_type = SRV_MMS_CREATE_MMS;
	 mmi_wcscpy((WCHAR *)param_mms.xml_filepath, (const WCHAR *)file_path);
	param_mms.xml_size=  applib_get_file_size(param_mms.xml_filepath);
	result_mms = srv_mms_create(&param_mms);
}

#if (defined(__MMI_UMMS_PST__) || defined(__MMI_UMMS_JSR205__))
extern "C" void avk_msg_mms_008_cb_delete(srv_mms_result_enum result, void *rsp_data, void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables													*/
    /*----------------------------------------------------------------*/
    U16 *screen_string;
    S8 str_a[10];
    S8 str_temp[5];
    srv_mms_get_msg_num_rsp_struct *msg_rsp= (srv_mms_get_msg_num_rsp_struct*) rsp_data;

    /*----------------------------------------------------------------*/
    /* Code Body														*/
    /*----------------------------------------------------------------*/
    screen_string= (U16*) AVK_MALLOC(1024);

    mmi_wcscpy(screen_string, (WCHAR *)L"NO of Messages:\n 1. Drafts = ");
    sprintf((PS8)str_temp,(PS8)"%d",msg_rsp->rsp_tb[0]);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_wcscat(screen_string,(WCHAR *)str_a);
    mmi_wcscat(screen_string,(WCHAR *)L"\n 2. Inbox = ");
    sprintf((PS8)str_temp,(PS8)"%d",msg_rsp->rsp_tb[1]);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_wcscat(screen_string,(WCHAR *)str_a);
    mmi_wcscat(screen_string,(WCHAR *)L"\n 3. Outbox = ");
    sprintf((PS8)str_temp,(PS8)"%d",msg_rsp->rsp_tb[2]);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_wcscat(screen_string,(WCHAR *)str_a);

    AVK_MANU_SHOW_SCR(screen_string,NULL,NULL);
    AVK_FREE(screen_string);
}

extern "C" void avk_msg_mms_008_cb(srv_mms_result_enum result, void *rsp_data, void * user_data)
{
	  srv_mms_get_msg_num_req_struct param_mms;
	  S32 result_mms = 0;
	
	  param_mms.app_id = MMA_APP_ID_MMS_APP;
	  param_mms.call_back = avk_msg_mms_008_cb_delete;
	  param_mms.req_tb[0]= MMA_QUERY_OPTION_NUM_TOTAL_DRAFT_MSG;
	  param_mms.req_tb[1]=MMA_QUERY_OPTION_NUM_TOTAL_INBOX_MSG;
	  param_mms.req_tb[2]=MMA_QUERY_OPTION_NUM_TOTAL_OUTBOX_MSG;
	  param_mms.user_data = (void*)433;
	  srv_mms_get_msg_num(&param_mms);
}


AVK_MANUAL_CASE(AVK_MSG_MMS_MANU_008,AVK_MSG_MMS_MANU)
{
	srv_mms_delete_folder_req_struct req;
	req.app_id = MMA_APP_ID_MMS_APP;
	req.call_back = avk_msg_mms_008_cb;
	AVK_LOG(req.msg_box_type = srv_mms_convert_mma_folder_to_umbox_type(MMA_FOLDER_DRAFT));
	req.msg_type = SRV_UM_MSG_MMS;
	req.user_data = (void*)0;
	
	if (AVK_LOG_ASYN(SRV_MMS_RESULT_OK != (srv_mms_result_enum)srv_mms_delete_folder(&req)))
	{
	    AVK_CASE_RESULT(AVK_FAIL);
	    AVK_ASYN_DONE();
	}	
}
#endif
void avk_msg_mms_009_display_screen()
{
    /*---------------------------------------------------------------- */
    /* Local Variables											        */
    /*----------------------------------------------------------------*/
    U16 *screen_string;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
    screen_string= (U16*)AVK_MALLOC(512);

    mmi_wcscpy(screen_string, (WCHAR *)L" Pass : If message sending icon is on tittle bar \n Fail: if message sending icon is not there ");
    
    AVK_MANU_SHOW_SCR(screen_string,NULL,NULL);
    AVK_FREE(screen_string);
}

extern "C" void avk_msg_mms_0091_cb(srv_mms_result_enum result, void *rsp_data, void * user_data)
{
	/*---------------------------------------------------------------- */
    /* Local Variables                                              						    */
    /*----------------------------------------------------------------*/
	srv_mms_create_rsp_struct *msg_rsp = (srv_mms_create_rsp_struct*) rsp_data;	
	srv_mms_send_req_struct req;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	req.msg_id = msg_rsp->msg_id;
	req.send_setting = SRV_MMS_SETTING_SAVE_AND_SEND;
	req.sim_id = MMI_SIM1;
	req.storage_type = MMA_MSG_STORAGE_PHONE;
	req.is_rr = MMI_TRUE;
	avk_msg_mms_009_display_screen();
	AVK_LOG_NORMAL(srv_mms_send(&req));
}

extern "C" void avk_msg_mms_009_cb(srv_mms_result_enum result, void *rsp_data, void * user_data)
{
	
	srv_mms_create_rsp_struct *msg_rsp = (srv_mms_create_rsp_struct*) rsp_data;	
	srv_mms_save_req_struct param_mms_1;

	if(msg_rsp->min_fs_space_required<=0)
	{
		param_mms_1.app_id = msg_rsp->app_id;
		param_mms_1.call_back = avk_msg_mms_0091_cb;
		param_mms_1.msg_id[0] = msg_rsp->msg_id;
		param_mms_1.no_of_msg =1;
		param_mms_1.user_data = (void*)433;
		param_mms_1.box = MMA_FOLDER_OUTBOX;
		srv_mms_save(&param_mms_1);
	}
}


AVK_MANUAL_CASE(AVK_MSG_MMS_MANU_009,AVK_MSG_MMS_MANU)
{
	    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 result_mms = 0;
	srv_mms_create_req_struct param_mms;
	WCHAR file_path[64];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_wstrcpy((WCHAR*)file_path,(WCHAR*)AVK_TEST_FILE_PATH);
    kal_wstrcat((WCHAR*)file_path,(WCHAR*)L"avk_msg_mms\\MMS.txt");
    memset(&param_mms, 0, sizeof(srv_mms_create_req_struct));
	param_mms.app_id = MMA_APP_ID_MMS_APP;
	param_mms.call_back = avk_msg_mms_009_cb;
	param_mms.mode = MMA_MODE_SEND;
	param_mms.msg_id = 0;
	param_mms.sim_id =MMA_SIM_ID_SIM1;
	param_mms.user_data = (void*)433;
	param_mms.op_type = SRV_MMS_CREATE_MMS;
	mmi_wcscpy((WCHAR *)param_mms.xml_filepath, (const WCHAR *)file_path);
	param_mms.xml_size=  applib_get_file_size(param_mms.xml_filepath);
	result_mms = srv_mms_create(&param_mms);	
}



AVK_MANUAL_CASE(AVK_MSG_MMS_MANU_010,AVK_MSG_MMS_MANU)
{
    /*----------------------------------------------------------------*/
    /* Local Variables													*/
    /*----------------------------------------------------------------*/
	  
	U16 *screen_string;
  	
	
    /*----------------------------------------------------------------*/
    /* Code Body														*/
    /*----------------------------------------------------------------*/
	screen_string= (U16*) AVK_MALLOC(1024);
	if(srv_mms_is_ready())
    {	
        mmi_wcscpy(screen_string, (WCHAR *)L"Ready");
    }
    else
    {
        mmi_wcscpy(screen_string,(WCHAR*)L"Not Ready");
    }
	AVK_MANU_SHOW_SCR(screen_string,NULL,NULL);
	AVK_FREE(screen_string);
}

extern "C" void avk_msg_mms_011_cb(srv_mms_result_enum result, void *rsp_data, void * user_data)
{
	srv_mms_create_rsp_struct *msg_rsp = (srv_mms_create_rsp_struct*) rsp_data;	
	
	if(msg_rsp->min_fs_space_required<=0)
	{
         S32 srv_result;
         U8 error = 0;
	   
          srv_result = srv_mms_save_msg(msg_rsp->msg_id, MMA_FOLDER_DRAFT, &error);
          if(!(srv_result == SRV_MMS_RESULT_OK) ||!( error == SRV_MMS_RESULT_OK))
            {
              AVK_LOG_FUN(srv_mms_save_msg,AVK_FAIL);
              AVK_ASYN_DONE();
              return;
		    }
		srv_result = srv_mms_set_read_status(msg_rsp->msg_id, (kal_bool)MMI_TRUE, &error);
            

        if(srv_result == SRV_MMS_RESULT_OK)
        {
            if(error == SRV_MMS_RESULT_OK)
            {
                 AVK_CASE_RESULT(AVK_PASS);
	             AVK_ASYN_DONE();
		    }
            else
            {
                 AVK_CASE_RESULT(AVK_FAIL);
	             AVK_ASYN_DONE();
            }
        }
        else
        {
             AVK_CASE_RESULT(AVK_FAIL);
	        AVK_ASYN_DONE();
        }
	}
	else
	{
        AVK_LOG_FUN(srv_mms_create,AVK_FAIL);
        AVK_ASYN_DONE();
    }        
}

/*****************************************************************************
 * FUNCTION
 *  avk_msg_mms_011
 * DESCRIPTION
 *  send mms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_ASYN_CASE(AVK_MSG_MMS_AUTO_011,AVK_MSG_MMS_AUTO)
{
       /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_mms_create_req_struct param_mms;
	WCHAR file_path[64];
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_wstrcpy((WCHAR*)file_path,(WCHAR*)AVK_TEST_FILE_PATH);
    kal_wstrcat((WCHAR*)file_path,(WCHAR*)L"avk_msg_mms\\MMS.txt");
    memset(&param_mms, 0, sizeof(srv_mms_create_req_struct));
	param_mms.app_id = MMA_APP_ID_MMS_APP;
	param_mms.call_back = avk_msg_mms_011_cb;
	param_mms.mode = MMA_MODE_EDIT;
	param_mms.msg_id = 0;
	param_mms.sim_id =MMA_SIM_ID_SIM1;
	param_mms.user_data = (void*)433;
	param_mms.op_type = SRV_MMS_CREATE_MMS;
	mmi_wcscpy((WCHAR *)param_mms.xml_filepath,(const WCHAR *)file_path);
	param_mms.xml_size=  applib_get_file_size(param_mms.xml_filepath);
	if (SRV_MMS_RESULT_OK != srv_mms_create(&param_mms))
	{
	    AVK_LOG_FUN(srv_mms_create,AVK_FAIL);
	    AVK_ASYN_DONE();
	}
}


extern "C" void avk_msg_mms_12_cb(srv_mms_result_enum result, void *rsp_data, void * user_data)
{
	srv_mms_create_rsp_struct *msg_rsp = (srv_mms_create_rsp_struct*) rsp_data;	
	

	if(msg_rsp->min_fs_space_required<=0)
	{ 
        U8 is_lock = MMI_UMMS_LOCK_MODE_ON;           
        U8 corrupt_info = MMI_UMMS_STOP_CORRUPT_DWNLD;
        S32 srv_result;
         U8 error = 0;
      
        AVK_LOG_FUN(srv_mms_create,AVK_PASS);
         srv_result = srv_mms_save_msg(msg_rsp->msg_id, MMA_FOLDER_DRAFT, &error);
         if(!(srv_result == SRV_MMS_RESULT_OK) ||!( error == SRV_MMS_RESULT_OK))
         {
              AVK_LOG_FUN(srv_mms_save_msg,AVK_FAIL);
              AVK_ASYN_DONE();
              return;
		 }
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
        srv_result = srv_mms_set_lock_status(msg_rsp->msg_id, is_lock, corrupt_info, &error);
#endif
        if(srv_result == SRV_MMS_RESULT_OK)
        {
            if(error == MMA_RESULT_OK)
            { 
                AVK_CASE_RESULT(AVK_PASS);
	            AVK_ASYN_DONE();
            }
            else
            {
                AVK_CASE_RESULT(AVK_FAIL);
	           AVK_ASYN_DONE();
           }
        }
        else
        {
            AVK_CASE_RESULT(AVK_FAIL);
	        AVK_ASYN_DONE();
        }
	}
	else
	{
        AVK_LOG_FUN(srv_mms_create,AVK_FAIL);
        AVK_ASYN_DONE();
    }
}



/*****************************************************************************
 * FUNCTION
 *  avk_msg_mms_012
 * DESCRIPTION
 *  send mms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_ASYN_CASE(AVK_MSG_MMS_AUTO_012,AVK_MSG_MMS_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_mms_create_req_struct param_mms;
	WCHAR file_path[64];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_wstrcpy((WCHAR*)file_path,(WCHAR*)AVK_TEST_FILE_PATH);
    kal_wstrcat((WCHAR*)file_path,(WCHAR*)L"avk_msg_mms\\MMS.txt");
    memset(&param_mms, 0, sizeof(srv_mms_create_req_struct));
	param_mms.app_id = MMA_APP_ID_MMS_APP;
	param_mms.call_back = avk_msg_mms_12_cb;
	param_mms.mode = MMA_MODE_EDIT;
	param_mms.msg_id = 0;
	param_mms.sim_id =MMA_SIM_ID_SIM1;
	param_mms.user_data = (void*)433;
	param_mms.op_type = SRV_MMS_CREATE_MMS;
	mmi_wcscpy((WCHAR *)param_mms.xml_filepath,(const WCHAR *)file_path);
	param_mms.xml_size=  applib_get_file_size(param_mms.xml_filepath);
	if (SRV_MMS_RESULT_OK != srv_mms_create(&param_mms))
	{
	    AVK_LOG_FUN(srv_mms_create,AVK_FAIL);
	    AVK_ASYN_DONE();
	}
}

extern "C" void avk_msg_mms_013_cb(srv_mms_result_enum reslt, void *rsp_data, void * user_data)
{
    MMI_BOOL  result;
	srv_mms_create_rsp_struct *msg_rsp = (srv_mms_create_rsp_struct*) rsp_data;	
	
	if(msg_rsp->min_fs_space_required<=0)
	{
        U8 error = 0; 
        S32 srv_result = 0;
	    AVK_LOG_FUN(srv_mms_create,AVK_PASS);
        srv_result = srv_mms_save_msg(msg_rsp->msg_id, MMA_FOLDER_INBOX, &error);
        if(!(srv_result == SRV_MMS_RESULT_OK) ||!( error == SRV_MMS_RESULT_OK))
        {
              AVK_LOG_FUN(srv_mms_save_msg,AVK_FAIL);
              AVK_ASYN_DONE();
              return;
		}
		result = srv_mms_mma_get_mms_read_status(msg_rsp->msg_id);
        if(result == MMI_TRUE)
        {
                       AVK_CASE_RESULT(AVK_PASS);
	                  AVK_ASYN_DONE();
        }
        else
        {
            AVK_CASE_RESULT(AVK_FAIL);
	        AVK_ASYN_DONE();
        }
	}
	else
	{
        AVK_LOG_FUN(srv_mms_create,AVK_FAIL);
        AVK_ASYN_DONE();
    }        
}

/*****************************************************************************
 * FUNCTION
 *  avk_msg_mms_013
 * DESCRIPTION
 *  send mms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_ASYN_CASE(AVK_MSG_MMS_AUTO_013,AVK_MSG_MMS_AUTO)
{
       /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_mms_create_req_struct param_mms;
	WCHAR file_path[64];
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_wstrcpy((WCHAR*)file_path,(WCHAR*)AVK_TEST_FILE_PATH);
    kal_wstrcat((WCHAR*)file_path,(WCHAR*)L"avk_msg_mms\\MMS.txt");
    memset(&param_mms, 0, sizeof(srv_mms_create_req_struct));
	param_mms.app_id = MMA_APP_ID_MMS_APP;
	param_mms.call_back = avk_msg_mms_013_cb;
	param_mms.mode = MMA_MODE_EDIT;
	param_mms.msg_id = 0;
	param_mms.sim_id =MMA_SIM_ID_SIM1;
	param_mms.user_data = (void*)433;
	param_mms.op_type = SRV_MMS_CREATE_MMS;
	mmi_wcscpy((WCHAR *)param_mms.xml_filepath,(const WCHAR *)file_path);
	param_mms.xml_size=  applib_get_file_size(param_mms.xml_filepath);
	if (SRV_MMS_RESULT_OK != srv_mms_create(&param_mms))
	{
	    AVK_LOG_FUN(srv_mms_create,AVK_FAIL);
	    AVK_ASYN_DONE();
	}
}


extern "C" void avk_msg_mms_014_cb(srv_mms_result_enum result, void *rsp_data, void * user_data)
{
	srv_mms_create_rsp_struct *msg_rsp = (srv_mms_create_rsp_struct*) rsp_data;	
	srv_mms_save_req_struct param_mms_1;

	if(msg_rsp->min_fs_space_required<=0)
	{  
        U8 error = 0;
        S32 srv_result;
        srv_mms_mma_get_msg_info_struct* msg_info =
            (srv_mms_mma_get_msg_info_struct*) AVK_MALLOC(sizeof(srv_mms_mma_get_msg_info_struct));
        memset(msg_info, 0, sizeof(srv_mms_mma_get_msg_info_struct));
         srv_result = srv_mms_save_msg(msg_rsp->msg_id, MMA_FOLDER_DRAFT, &error);
          if(!(srv_result == SRV_MMS_RESULT_OK) ||!( error == SRV_MMS_RESULT_OK))
            {
              AVK_LOG_FUN(srv_mms_save_msg,AVK_FAIL);
              AVK_ASYN_DONE();
              AVK_FREE(msg_info);
              return;
		    }
             
        srv_result =  srv_mms_mma_get_sync_msg_info(
                        msg_rsp->msg_id,
                        msg_info,
                        srv_mms_mem_mgr_app_adm_alloc,
                        srv_mms_mem_mgr_app_adm_free);

        if (result == SRV_MMS_RESULT_OK)
		{  
            if(msg_info->result == MMA_RESULT_OK)
            {
		        AVK_CASE_RESULT(AVK_PASS);
	            AVK_ASYN_DONE();
            }
            else
            { 
                AVK_CASE_RESULT(AVK_FAIL);
                AVK_ASYN_DONE();
            }
		}
        else
        {
             AVK_CASE_RESULT(AVK_FAIL);
	         AVK_ASYN_DONE();
        }
        AVK_FREE(msg_info);
	}
	else
	{
        AVK_LOG_FUN(srv_mms_create,AVK_FAIL);
        AVK_ASYN_DONE();
    }        
}

/*****************************************************************************
 * FUNCTION
 *  avk_msg_mms_014
 * DESCRIPTION
 *  send mms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_ASYN_CASE(AVK_MSG_MMS_AUTO_014,AVK_MSG_MMS_AUTO)
{
       /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_mms_create_req_struct param_mms;
	WCHAR file_path[64];
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_wstrcpy((WCHAR*)file_path,(WCHAR*)AVK_TEST_FILE_PATH);
    kal_wstrcat((WCHAR*)file_path,(WCHAR*)L"avk_msg_mms\\MMS.txt");
    memset(&param_mms, 0, sizeof(srv_mms_create_req_struct));
	param_mms.app_id = MMA_APP_ID_MMS_APP;
	param_mms.call_back = avk_msg_mms_014_cb;
	param_mms.mode = MMA_MODE_EDIT;
	param_mms.msg_id = 0;
	param_mms.sim_id =MMA_SIM_ID_SIM1;
	param_mms.user_data = (void*)433;
	param_mms.op_type = SRV_MMS_CREATE_MMS;
	mmi_wcscpy((WCHAR *)param_mms.xml_filepath,(const WCHAR *)file_path);
	param_mms.xml_size=  applib_get_file_size(param_mms.xml_filepath);
	if (SRV_MMS_RESULT_OK != srv_mms_create(&param_mms))
	{
	    AVK_LOG_FUN(srv_mms_create,AVK_FAIL);
	    AVK_ASYN_DONE();
	}
}


extern "C" void avk_msg_mms_015_cb(srv_mms_result_enum result, void *rsp_data, void * user_data)
{
	U16 *screen_string = (U16*) AVK_MALLOC(1024);
	srv_mms_create_rsp_struct *msg_rsp = (srv_mms_create_rsp_struct*) rsp_data;	
	
	if(msg_rsp->min_fs_space_required<=0)
	{ S32 srv_result;
         U8 error = 0;
		 srv_result = srv_mms_save_msg(msg_rsp->msg_id, MMA_FOLDER_DRAFT, &error);
          if(!(srv_result == SRV_MMS_RESULT_OK) ||!( error == SRV_MMS_RESULT_OK))
            {
              AVK_LOG_FUN(srv_mms_save_msg,AVK_FAIL);
              AVK_ASYN_DONE();
              AVK_FREE(screen_string);
              return;
		    }
		if(MMI_TRUE == srv_mms_is_java_mms(msg_rsp->msg_id))
        {
            mmi_wcscpy(screen_string, (WCHAR *)L"Java MMS");
        }
        else
        {
            mmi_wcscpy(screen_string,(WCHAR*)L"Not Java MMS");
        }
        AVK_MANU_SHOW_SCR(screen_string,NULL,NULL);
	    AVK_FREE(screen_string);
    }
    else
	{
        AVK_LOG_FUN(srv_mms_create,AVK_FAIL);
        AVK_ASYN_DONE();
    }   
}


AVK_MANUAL_CASE(AVK_MSG_MMS_MANU_015,AVK_MSG_MMS_MANU)
{
	    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//S32 result_mms = 0;
	srv_mms_create_req_struct param_mms;
	WCHAR file_path[64];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_wstrcpy((WCHAR*)file_path,(WCHAR*)AVK_TEST_FILE_PATH);
    kal_wstrcat((WCHAR*)file_path,(WCHAR*)L"avk_msg_mms\\java.mms");
    memset(&param_mms, 0, sizeof(srv_mms_create_req_struct));
	param_mms.app_id = MMA_APP_ID_MMS_APP;
	param_mms.call_back = avk_msg_mms_015_cb;
	param_mms.mode = MMA_MODE_UPLOAD;
	param_mms.msg_id = 0;
	param_mms.sim_id =MMA_SIM_ID_SIM1;        
	param_mms.user_data = (void*)433;
	param_mms.op_type = SRV_MMS_CREATE_MMS;
	//mmi_wcscpy((WCHAR *)param_mms.xml_filepath, (const WCHAR *)file_path);
	//param_mms.xml_size=  applib_get_file_size(param_mms.xml_filepath);
    mmi_wcscpy((WCHAR *)param_mms.msg_file_path, (const WCHAR *)file_path);         
	if (SRV_MMS_RESULT_OK != srv_mms_create(&param_mms))
	{
	    AVK_LOG_FUN(srv_mms_create,AVK_FAIL);
	    AVK_ASYN_DONE();
	}
}


extern "C" void avk_msg_mms_016_cb(srv_mms_result_enum result, void *rsp_data, void * user_data)
{
	
    U16 *screen_string = (U16*) AVK_MALLOC(1024);
	srv_mms_create_rsp_struct *msg_rsp = (srv_mms_create_rsp_struct*) rsp_data;	
	
	if(msg_rsp->min_fs_space_required<=0)
	{ S32 srv_result;
         U8 error = 0;
         srv_result = srv_mms_save_msg(msg_rsp->msg_id, MMA_FOLDER_DRAFT, &error);
          if(!(srv_result == SRV_MMS_RESULT_OK) ||!( error == SRV_MMS_RESULT_OK))
            {
              AVK_LOG_FUN(srv_mms_save_msg,AVK_FAIL);
              AVK_ASYN_DONE();
              AVK_FREE(screen_string);
              return;
		    }
		  if(MMI_TRUE == srv_mms_is_mms_notification(msg_rsp->msg_id))
          { 
              mmi_wcscpy(screen_string, (WCHAR *)L"Message is MMS Notification");
          }
          else
          {
              mmi_wcscpy(screen_string, (WCHAR *)L"Message is not a MMS Notification");
          }
	      AVK_MANU_SHOW_SCR(screen_string,NULL,NULL);   
	      AVK_FREE(screen_string);
    }
    else
	{
        AVK_LOG_FUN(srv_mms_create,AVK_FAIL); 
        AVK_ASYN_DONE();
    }   

}


AVK_MANUAL_CASE(AVK_MSG_MMS_MANU_016,AVK_MSG_MMS_MANU)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_mms_create_req_struct param_mms;
	WCHAR file_path[64];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_wstrcpy((WCHAR*)file_path,(WCHAR*)AVK_TEST_FILE_PATH);
    kal_wstrcat((WCHAR*)file_path,(WCHAR*)L"avk_msg_mms\\notif.mms");
    memset(&param_mms, 0, sizeof(srv_mms_create_req_struct));
	param_mms.app_id = MMA_APP_ID_MMS_APP;
	param_mms.call_back = avk_msg_mms_016_cb;
	param_mms.mode = MMA_MODE_UPLOAD;
	param_mms.msg_id = 0;
	param_mms.sim_id =MMA_SIM_ID_SIM1;             
	param_mms.user_data = (void*)433;
	param_mms.op_type = SRV_MMS_CREATE_MMS;
	//mmi_wcscpy((WCHAR *)param_mms.xml_filepath, (const WCHAR *)file_path);
	//param_mms.xml_size=  applib_get_file_size(param_mms.xml_filepath);
    mmi_wcscpy((WCHAR *)param_mms.msg_file_path, (const WCHAR *)file_path);       
	if (SRV_MMS_RESULT_OK != srv_mms_create(&param_mms))
	{
	    AVK_LOG_FUN(srv_mms_create,AVK_FAIL);
	    AVK_ASYN_DONE();
	}
}

extern "C" void avk_msg_mms_017_cb(srv_mms_result_enum result, void *rsp_data, void * user_data)
{
	
	srv_mms_create_rsp_struct *msg_rsp = (srv_mms_create_rsp_struct*) rsp_data;	
	
    U16 *screen_string= (U16*) AVK_MALLOC(1024);
	if(msg_rsp->min_fs_space_required<=0)
	{  
        S32 srv_result;
        U8 error = 0;
        srv_result = srv_mms_save_msg(msg_rsp->msg_id, MMA_FOLDER_DRAFT, &error);
        if(!(srv_result == SRV_MMS_RESULT_OK) ||!( error == SRV_MMS_RESULT_OK))
        {
              AVK_LOG_FUN(srv_mms_save_msg,AVK_FAIL);
              AVK_ASYN_DONE();
              AVK_FREE(screen_string);
              return;
		}
        if(MMI_TRUE == srv_mms_is_corrupted_mms(msg_rsp->msg_id))
        {
              mmi_wcscpy(screen_string, (WCHAR *)L"Message is corrupt");
        }
        else
        {
             mmi_wcscpy(screen_string, (WCHAR *)L"Message is not corrupt");
        }
        AVK_MANU_SHOW_SCR(screen_string,NULL,NULL);
	    AVK_FREE(screen_string);
	}
    else
	{
        AVK_LOG_FUN(srv_mms_create,AVK_FAIL);
        AVK_ASYN_DONE();
    }    

}


AVK_MANUAL_CASE(AVK_MSG_MMS_MANU_017,AVK_MSG_MMS_MANU)
{
	    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_mms_create_req_struct param_mms;
	WCHAR file_path[64];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_wstrcpy((WCHAR*)file_path,(WCHAR*)AVK_TEST_FILE_PATH);
    kal_wstrcat((WCHAR*)file_path,(WCHAR*)L"avk_msg_mms\\MMS.txt");
    memset(&param_mms, 0, sizeof(srv_mms_create_req_struct));
	param_mms.app_id = MMA_APP_ID_MMS_APP;
	param_mms.call_back = avk_msg_mms_017_cb;
	param_mms.mode = MMA_MODE_EDIT;
	param_mms.msg_id = 0;
	param_mms.sim_id =MMA_SIM_ID_SIM1;
	param_mms.user_data = (void*)433;
	param_mms.op_type = SRV_MMS_CREATE_MMS;
	mmi_wcscpy((WCHAR *)param_mms.xml_filepath, (const WCHAR *)file_path);
	param_mms.xml_size=  applib_get_file_size(param_mms.xml_filepath);
	if (SRV_MMS_RESULT_OK != srv_mms_create(&param_mms))
	{
	    AVK_LOG_FUN(srv_mms_create,AVK_FAIL);
	    AVK_ASYN_DONE();
	}
}
extern "C" void avk_msg_mms_018_cb(srv_mms_result_enum result, void *rsp_data, void * user_data)
{
	
	srv_mms_create_rsp_struct *msg_rsp = (srv_mms_create_rsp_struct*) rsp_data;	
	U16 *screen_string= (U16*) AVK_MALLOC(1024);
	if(msg_rsp->min_fs_space_required<=0)
	{   S32 srv_result;
         U8 error = 0;
         srv_result = srv_mms_save_msg(msg_rsp->msg_id, MMA_FOLDER_DRAFT, &error);
          if(!(srv_result == SRV_MMS_RESULT_OK) ||!( error == SRV_MMS_RESULT_OK))
            {
              AVK_LOG_FUN(srv_mms_save_msg,AVK_FAIL);
              AVK_ASYN_DONE();
              AVK_FREE(screen_string);
              return;
		    }
        if(MMI_TRUE == srv_mms_is_forward_lock(msg_rsp->msg_id))
        {
             mmi_wcscpy(screen_string, (WCHAR *)L"MMS is forward locked");
        }
        else
        {
             mmi_wcscpy(screen_string, (WCHAR *)L"MMS is not forward locked");
        }
        AVK_MANU_SHOW_SCR(screen_string,NULL,NULL);
     	AVK_FREE(screen_string);
	}
    else
	{
        AVK_LOG_FUN(srv_mms_create,AVK_FAIL);
        AVK_ASYN_DONE();
    }    
}


AVK_MANUAL_CASE(AVK_MSG_MMS_MANU_018,AVK_MSG_MMS_MANU)
{
	    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_mms_create_req_struct param_mms;
	WCHAR file_path[64];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_wstrcpy((WCHAR*)file_path,(WCHAR*)AVK_TEST_FILE_PATH);
    kal_wstrcat((WCHAR*)file_path,(WCHAR*)L"avk_msg_mms\\MMS.txt");
    memset(&param_mms, 0, sizeof(srv_mms_create_req_struct));
	param_mms.app_id = MMA_APP_ID_MMS_APP;
	param_mms.call_back = avk_msg_mms_018_cb;
	param_mms.mode = MMA_MODE_EDIT;
	param_mms.msg_id = 0;
	param_mms.sim_id =MMA_SIM_ID_SIM1;
	param_mms.user_data = (void*)433;
	param_mms.op_type = SRV_MMS_CREATE_MMS;
	mmi_wcscpy((WCHAR *)param_mms.xml_filepath, (const WCHAR *)file_path);
	param_mms.xml_size=  applib_get_file_size(param_mms.xml_filepath);
	if (SRV_MMS_RESULT_OK != srv_mms_create(&param_mms))
	{
	    AVK_LOG_FUN(srv_mms_create,AVK_FAIL);
	    AVK_ASYN_DONE();
	}
}
extern "C" void avk_msg_mms_019_cb(srv_mms_result_enum result, void *rsp_data, void * user_data)
{
	
	srv_mms_create_rsp_struct *msg_rsp = (srv_mms_create_rsp_struct*) rsp_data;	
	U16 *screen_string= (U16*) AVK_MALLOC(1024);

	if(msg_rsp->min_fs_space_required<=0)
	{  S32 srv_result;
         U8 error = 0;
         srv_result = srv_mms_save_msg(msg_rsp->msg_id, MMA_FOLDER_DRAFT, &error);
          if(!(srv_result == SRV_MMS_RESULT_OK) ||!( error == SRV_MMS_RESULT_OK))
            {
              AVK_LOG_FUN(srv_mms_save_msg,AVK_FAIL);
              AVK_ASYN_DONE();
              AVK_FREE(screen_string);
             return;
		    } 
       srv_mms_msg_storage_enum storage= srv_mms_get_msg_storage(msg_rsp->msg_id);
            
	  if(storage == SRV_MMS_STORAGE_PHONE)
      {
          mmi_wcscpy(screen_string, (WCHAR *)L"MMS is stored on phone");
      }
      else if (storage == SRV_MMS_STORAGE_CARD1)
      {
          mmi_wcscpy(screen_string, (WCHAR *)L"MMS is stored on card");
      }
      else
      {
          mmi_wcscpy(screen_string, (WCHAR *)L"MMS is stored neither on phone nor on card");
      }
        AVK_MANU_SHOW_SCR(screen_string,NULL,NULL);
	    AVK_FREE(screen_string);
	}
    else
	{
        AVK_LOG_FUN(srv_mms_create,AVK_FAIL);
        AVK_ASYN_DONE();
    }    
}


AVK_MANUAL_CASE(AVK_MSG_MMS_MANU_019,AVK_MSG_MMS_MANU)
{
	    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_mms_create_req_struct param_mms;
	WCHAR file_path[64];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_wstrcpy((WCHAR*)file_path,(WCHAR*)AVK_TEST_FILE_PATH);
    kal_wstrcat((WCHAR*)file_path,(WCHAR*)L"avk_msg_mms\\MMS.txt");
    memset(&param_mms, 0, sizeof(srv_mms_create_req_struct));
	param_mms.app_id = MMA_APP_ID_MMS_APP;
	param_mms.call_back = avk_msg_mms_019_cb;
	param_mms.mode = MMA_MODE_EDIT;
	param_mms.msg_id = 0;
	param_mms.sim_id =MMA_SIM_ID_SIM1;
	param_mms.user_data = (void*)433;
	param_mms.op_type = SRV_MMS_CREATE_MMS;
	mmi_wcscpy((WCHAR *)param_mms.xml_filepath, (const WCHAR *)file_path);
	param_mms.xml_size=  applib_get_file_size(param_mms.xml_filepath);
	if (SRV_MMS_RESULT_OK != srv_mms_create(&param_mms))
	{
	    AVK_LOG_FUN(srv_mms_create,AVK_FAIL);
	    AVK_ASYN_DONE();
	}
}
#endif