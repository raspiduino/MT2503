extern "C"
{
#include "FileMgrSrvGProt.h"
#include "mmi_rp_srv_filemanager_def.h"
#include "mmi_rp_app_mre_def.h"
}
#define MMI_FILEINFO_ERROR   -99 

/*****************************************************************************
 * FUNCTION
 *  vs_appser_fmgr_common_service
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_APPSRV_FMGR_COMM_SRV,AVK_APPSRV_FMGR)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 set_sort_option = FS_SORT_NAME;
	mmi_str_id str_n_popup = 0;
	S32 popup_type = 0;
	S32 fs_error = FS_ABORTED_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
	/* Set Sort Option*/
	AVK_LOG(srv_fmgr_sort_set(FS_SORT_NAME));
    /* Get Sort option */  
 	AVK_LOG_EX(set_sort_option == srv_fmgr_sort_get());

	AVK_LOG_EX(FMGR_FS_ABORTED_ERROR_TEXT == srv_fmgr_fs_error_get_string(fs_error));

	AVK_LOG_EX(MMI_EVENT_SUCCESS == srv_fmgr_fs_error_get_popup_type(fs_error));

	str_n_popup = srv_fmgr_fs_error_get_string_and_popup_type(FS_INVALID_FILENAME,&popup_type);

    AVK_LOG_FUN(srv_fmgr_fs_error_get_string_and_popup_type,
		      str_n_popup == STR_GLOBAL_INVALID_FILENAME && popup_type == MMI_EVENT_FAILURE);
}


/*****************************************************************************
 * FUNCTION
 *  vs_appser_fmgr_storage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_APPSRV_FMGR_STORAGE,AVK_APPSRV_FMGR)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     U8 drv_letter;
	 U16 buf_drv_name[SRV_FMGR_DRV_MAX_NAME_LEN + 1];
	 S32 result;
	 U64 disk_free_space;
     U64 disk_total_space;
	 U16 drv_path[SRV_FMGR_DRV_MAX_NAME_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    AVK_LOG_NORMAL(srv_fmgr_drv_init());

	AVK_LOG_EX(drv_letter =  srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_PHONE_TYPE));	
	
	result = srv_fmgr_drv_get_name(drv_letter,(WCHAR *)buf_drv_name,(SRV_FMGR_DRV_MAX_NAME_LEN + 1) * ENCODING_LENGTH);	
	AVK_LOG_FUN(srv_fmgr_drv_get_name, result == 0 && (mmi_ucs2cmp((PS8)buf_drv_name, (PS8)L"Phone") == 0));
	
	AVK_LOG_EX(STR_GLOBAL_PHONE == srv_fmgr_drv_get_string(drv_letter));

	AVK_LOG_EX(SRV_FMGR_DRV_PHONE_TYPE == srv_fmgr_drv_get_type(drv_letter));

	AVK_LOG_EX(0 <= srv_fmgr_drv_get_size(drv_letter,&disk_total_space, &disk_free_space));

	AVK_LOG_EX(0 == srv_fmgr_drv_check_free_size(drv_letter,disk_free_space));

	AVK_LOG_EX(MMI_TRUE == srv_fmgr_drv_is_accessible(drv_letter));

	AVK_LOG_EX(MMI_FALSE == srv_fmgr_drv_is_busy(drv_letter));

	AVK_LOG_EX(MMI_TRUE == srv_fmgr_drv_is_valid(drv_letter));

	AVK_LOG_EX(MMI_FALSE == srv_fmgr_drv_is_removable(drv_letter));

	AVK_LOG(srv_fmgr_drv_has_accessible_removable_drv());

	mmi_ucs2cpy((S8*)drv_path, (S8*) srv_fmgr_drv_get_path_by_type(SRV_FMGR_DRV_CARD_TYPE));
	AVK_LOG_FUN(srv_fmgr_drv_get_path_by_type,drv_path[0]);
}

/*****************************************************************************
 * FUNCTION
 *  vs_appser_fmgr_drvlist_storage
 * DESCRIPTION
 *  This api test drive list related functions
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
AVK_CASE(AVK_APPSRV_FMGR_DRVLIST_STORAGE,AVK_APPSRV_FMGR)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_FMGR_DRVLIST_HANDLE fs_handle = 0; 
	U8 drv_letter ;
	S32 drv_index = 0;
	U16 drv_type = SRV_FMGR_DRV_PHONE_TYPE;
	MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                              */
    /*----------------------------------------------------------------*/
    drv_letter = srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_PHONE_TYPE);
	AVK_LOG(fs_handle = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ALL));

	AVK_LOG_EX(srv_fmgr_drivelist_count(fs_handle) > 0);

	AVK_LOG_EX(0 == srv_fmgr_drivelist_get_index_by_drv_letter(fs_handle,drv_letter));

	AVK_LOG_EX(drv_letter == srv_fmgr_drivelist_get_drv_letter(fs_handle,0));

	AVK_LOG_EX(0 == srv_fmgr_drivelist_get_index_by_drv_type(fs_handle,(srv_fmgr_drv_type_enum)drv_type));

    AVK_LOG_NORMAL(srv_fmgr_drivelist_destroy(fs_handle));
}

/*****************************************************************************
 * FUNCTION
 *  vs_appser_fmgr_filepath_001
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
AVK_CASE(AVK_APPSRV_FMGR_FILEPATH_001,AVK_APPSRV_FMGR)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

     S8 file_path[(SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH];
	 S8 invalid_file[(SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH];
	 WCHAR *p_file_name = NULL;
	 WCHAR *p_invalid_char = NULL;
	 const WCHAR *p_cnt_file_name;
	 S32 file_index = -1, empty_index = -1;
	 MMI_BOOL is_valid = MMI_FALSE, is_valid_1 = MMI_FALSE;
	 MMI_BOOL result = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_wcscpy((WCHAR *)file_path,(const WCHAR*)L"D:\\AVK\\test file\\avk_appsrv_fmgr\\123.bmp");

    mmi_wcscpy((WCHAR *)invalid_file,(const WCHAR*)L"te@?< >!@#st.jpg");

    p_file_name = srv_fmgr_path_get_filename_ptr((WCHAR*)file_path);
    AVK_LOG_FUN(srv_fmgr_path_get_filename_ptr, mmi_ucs2cmp((PS8)p_file_name, (PS8)L"123.bmp") == 0);

    p_cnt_file_name = srv_fmgr_path_get_filename_const_ptr((const WCHAR*)file_path);
    AVK_LOG_FUN(srv_fmgr_path_get_filename_const_ptr, mmi_ucs2cmp((PS8)p_cnt_file_name, (PS8)L"123.bmp") == 0);
    
    AVK_LOG_EX(srv_fmgr_path_get_filename_pos((const WCHAR*)file_path) == kal_wstrlen((const WCHAR *)file_path)-7);

    AVK_LOG_EX(-1 == srv_fmgr_path_get_filename_pos(NULL));

    AVK_LOG(p_invalid_char = (WCHAR *)srv_fmgr_path_get_invalid_chars());

    AVK_LOG_EX(!srv_fmgr_path_is_filename_valid((WCHAR*)invalid_file));

    AVK_LOG_EX(!srv_fmgr_path_is_filename_valid((WCHAR*)p_invalid_char));

    AVK_LOG_EX(srv_fmgr_path_is_filename_valid((WCHAR*)p_file_name));
}

/*****************************************************************************
 * FUNCTION
 *  vs_appser_fmgr_filepath_002
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
AVK_CASE(AVK_APPSRV_FMGR_FILEPATH_002,AVK_APPSRV_FMGR)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     MMI_BOOL result = MMI_FALSE;
	 MMI_BOOL is_ext_hidden = MMI_FALSE;
	 S8 file_path[(SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH];
	 S8 file_with_spc[(SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH];
	 S8 file_wo_spc[(SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH];
	 WCHAR *p_file_ext = NULL;
     WCHAR *p_file_wo_spc = NULL;
	 const WCHAR * p_file_cnt_wo_spc = NULL;
	 const WCHAR *p_cnt_file_ext = NULL;

   /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcscpy((WCHAR *)file_path,(const WCHAR*)L"D:\\Photos\\test.jpg");

	mmi_wcscpy((WCHAR *)file_with_spc,(const WCHAR*)L"     jockey.gif");

	AVK_LOG_EX(15 == srv_fmgr_path_get_extension_pos((const WCHAR*)file_path));

	p_file_ext = srv_fmgr_path_get_extension_ptr((WCHAR*)file_path);
    AVK_LOG_FUN(srv_fmgr_path_get_extension_ptr, mmi_ucs2cmp((PS8)p_file_ext, (PS8)L"jpg") == 0);
	

	p_cnt_file_ext = srv_fmgr_path_get_extension_const_ptr((const WCHAR*)file_path);
    AVK_LOG_FUN(srv_fmgr_path_get_extension_ptr, mmi_ucs2cmp((PS8)p_cnt_file_ext, (PS8)L"jpg") == 0);
    
	p_file_wo_spc = srv_fmgr_path_skip_leading_space((WCHAR*)file_with_spc);	
	mmi_wcsncpy((WCHAR *)file_wo_spc,(WCHAR*) p_file_wo_spc, SRV_FMGR_PATH_MAX_LEN - 1);
    AVK_LOG_FUN(srv_fmgr_path_skip_leading_space, mmi_ucs2cmp((PS8)file_wo_spc, (PS8)L"jockey.gif") == 0);

    
    AVK_LOG_EX(p_file_wo_spc == srv_fmgr_path_skip_leading_space_const((const WCHAR*)file_with_spc));

	AVK_LOG_EX(!srv_fmgr_path_hide_extension((WCHAR*)file_path));
}
/*****************************************************************************
 * FUNCTION
 *  vs_appser_fmgr_filepath_003
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
AVK_CASE(AVK_APPSRV_FMGR_FILEPATH_003,AVK_APPSRV_FMGR)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    	
     MMI_BOOL result = MMI_FALSE;
	 S8 file_path[(SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH];
	 S8 dest_file_path[(SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH];
	 S8 dest_file_path_ex[(SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH];
     S8 file_path_wo_slash[(SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH];
	 S8 folder_path[(SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH];
	 WCHAR *p_path_wo_slash = NULL;
	 WCHAR *p_folder_name = NULL;

   /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_wcscpy((WCHAR *)file_path,(const WCHAR*)L"D:\\Photos\\Images\\rock.gif");

	mmi_wcscpy((WCHAR *)dest_file_path,(const WCHAR*)L"D:\\Photos\\test");

	mmi_wcscpy((WCHAR *)dest_file_path_ex,(const WCHAR*)L"D:\\Photos");

	AVK_LOG_EX(srv_fmgr_path_append((WCHAR *)dest_file_path, sizeof(dest_file_path), (WCHAR *)L"send.gif"));	

	AVK_LOG_EX(srv_fmgr_path_append_ex((WCHAR *)dest_file_path_ex,sizeof(dest_file_path),(WCHAR *)L"Snaps", MMI_TRUE));

	p_path_wo_slash = srv_fmgr_path_remove_slash((WCHAR *)dest_file_path_ex);

	mmi_wcscpy((WCHAR *)file_path_wo_slash,(const WCHAR*)p_path_wo_slash);
    AVK_LOG_FUN(srv_fmgr_path_remove_slash, mmi_ucs2cmp(file_path_wo_slash, (PS8)L"D:\\Photos\\Snaps") == 0);
    
	p_folder_name = srv_fmgr_path_remove_filename((WCHAR *)file_path);
	mmi_wcscpy((WCHAR *)folder_path,(const WCHAR*)p_folder_name);
    AVK_LOG_FUN(srv_fmgr_path_remove_filename, mmi_ucs2cmp(folder_path, (PS8)L"D:\\Photos\\Images\\") == 0);
}

/*****************************************************************************
 * FUNCTION
 *  vs_appser_fmgr_filepath_004
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
AVK_CASE(AVK_APPSRV_FMGR_FILEPATH_004,AVK_APPSRV_FMGR)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
	 MMI_BOOL result = MMI_FALSE;
	 WCHAR path[SRV_FMGR_PATH_MAX_LEN+1];

   /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	mmi_wcscpy((WCHAR*)path, (WCHAR*)AVK_TEST_FILE_PATH);
	mmi_wcscpy((WCHAR*)path, (WCHAR*)L"FileMgr");
	
	AVK_LOG_EX(0 == srv_fmgr_fs_create_folder((const WCHAR*)path));

	AVK_LOG_EX(0 ==  srv_fmgr_fs_path_exist((const WCHAR*)path));

    AVK_LOG_EX(srv_fmgr_fs_path_is_not_empty((WCHAR*)L"root", NULL) > 0);
}

/*****************************************************************************
 * FUNCTION
 *  vs_appser_fmgr_fileinfo_001
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
AVK_CASE(AVK_APPSRV_FMGR_FILEINFO_001,AVK_APPSRV_FMGR)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 WCHAR path[SRV_FMGR_PATH_MAX_LEN+1];
	 WCHAR file_name[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
     SRV_FMGR_FILEINFO_HANDLE handle;
	 MMI_BOOL is_folder = MMI_FALSE, result = MMI_FALSE;
   

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	mmi_wcscpy((WCHAR*)path, (WCHAR*)AVK_TEST_FILE_PATH);
	mmi_wcscpy((WCHAR*)path, (WCHAR*)L"CRICINFO");

	srv_fmgr_fs_create_folder((const WCHAR*)path);

	AVK_LOG_EX(0 == srv_fmgr_fileinfo_create((WCHAR *)path, &handle));

	AVK_LOG_EX(srv_fmgr_fileinfo_is_folder(handle));

	AVK_LOG_EX(0 == srv_fmgr_fileinfo_get_name(handle, (WCHAR *)file_name, (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH));

	AVK_LOG_EX(!srv_fmgr_fileinfo_is_in_archive(handle));

	AVK_LOG_NORMAL(srv_fmgr_fileinfo_destroy(handle));
}

/*****************************************************************************
 * FUNCTION
 *  vs_appser_fmgr_fileinfo_002
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
AVK_CASE(AVK_APPSRV_FMGR_FILEINFO_002,AVK_APPSRV_FMGR)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

     WCHAR path[100];
	 WCHAR file_name[100];
	 WCHAR file_ext[100];
     SRV_FMGR_FILEINFO_HANDLE handle;
	 MMI_BOOL is_folder = MMI_FALSE, result = MMI_FALSE;
	 srv_fmgr_fileinfo_struct fileinfo; 

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
    mmi_wcscpy((WCHAR*)path, (WCHAR*)AVK_TEST_FILE_PATH);
    mmi_wcscat((WCHAR*)path, (WCHAR*)L"avk_appsrv_fmgr\\123.bmp");

	AVK_LOG_EX(0 == srv_fmgr_fileinfo_create((WCHAR *)path, &handle));

	AVK_LOG_EX(0 == srv_fmgr_fileinfo_get_name(handle, file_name, (100) * sizeof(WCHAR)));

	AVK_LOG_EX(0 == srv_fmgr_fileinfo_get_extension(handle,file_ext,(100) * sizeof(WCHAR)));

	AVK_LOG_NORMAL(srv_fmgr_fileinfo_get_info(handle, &fileinfo));
	AVK_LOG_EX(FMGR_TYPE_BMP == srv_fmgr_fileinfo_get_type(handle));
	AVK_LOG_EX(0 == srv_fmgr_fileinfo_get_size(handle));

	srv_fmgr_fileinfo_destroy(handle);
}
/*****************************************************************************
 * FUNCTION
 *  vs_appser_fmgr_fileinfo_003
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
AVK_CASE(AVK_APPSRV_FMGR_FILEINFO_003,AVK_APPSRV_FMGR)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR path[SRV_FMGR_PATH_MAX_LEN+1];
    SRV_FMGR_FILEINFO_HANDLE handle;
    MMI_BOOL result = MMI_FALSE; 
    srv_fmgr_fileinfo_struct fileinfo;
    MYTIME  datetime;
   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcscpy((WCHAR*)path, (WCHAR*)AVK_TEST_FILE_PATH);
    mmi_wcscat((WCHAR*)path, (WCHAR*)L"avk_appsrv_fmgr\\123.bmp");

	AVK_LOG_EX(0 == srv_fmgr_fileinfo_create((WCHAR *)path, &handle));

	AVK_LOG_NORMAL(srv_fmgr_fileinfo_get_info(handle,&fileinfo));

	srv_fmgr_fileinfo_get_datetime(handle,&datetime);

    AVK_LOG_FUN(srv_fmgr_fileinfo_get_datetime, datetime.nYear == fileinfo.datetime.nYear
		 && datetime.nMonth == fileinfo.datetime.nMonth &&  datetime.nSec == fileinfo.datetime.nSec 
		   && datetime.DayIndex == fileinfo.datetime.DayIndex);
		   
	srv_fmgr_fileinfo_destroy(handle);

	mmi_wcscpy(path, (WCHAR*)AVK_TEST_FILE_PATH);

	AVK_LOG_EX(0 == srv_fmgr_fileinfo_create((WCHAR *)path, &handle));

	AVK_LOG_EX(srv_fmgr_fileinfo_get_attribute(handle));

	srv_fmgr_fileinfo_destroy(handle);
}
/*****************************************************************************
 * FUNCTION
 *  vs_appser_fmgr_fileinfo_004
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
AVK_CASE(AVK_APPSRV_FMGR_FILEINFO_004,AVK_APPSRV_FMGR) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     WCHAR path[100];
	 WCHAR file_name[100];
	 WCHAR file_name_disp[100];
     SRV_FMGR_FILEINFO_HANDLE handle;
	 MMI_BOOL result = MMI_FALSE;   

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	mmi_wcscpy((WCHAR*)path, (WCHAR*)AVK_TEST_FILE_PATH);
    mmi_wcscat((WCHAR*)path, (WCHAR*)L"avk_appsrv_fmgr\\123.bmp");

	AVK_LOG_EX(0 == srv_fmgr_fileinfo_create((WCHAR *)path, &handle));

	AVK_LOG_EX(0 == srv_fmgr_fileinfo_get_display_name(handle,(WCHAR *)file_name,
	                (100) * sizeof(WCHAR)));

	AVK_LOG_EX(0 == srv_fmgr_fs_path_get_display_name((const WCHAR *)path,file_name_disp,
	                (100) * sizeof(WCHAR)));
    AVK_CASE_RESULT(mmi_ucs2cmp((PS8)file_name, (PS8)file_name_disp) == 0);
    
	srv_fmgr_fileinfo_destroy(handle);
}



/*****************************************************************************
 * FUNCTION
 *  vs_appser_fmgr_async_fs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
AVK_CASE(AVK_APPSRV_FMGR_ASYNC,AVK_APPSRV_FMGR)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR       m_dest_path[100];
    WCHAR      n_dest_path[100];
    WCHAR      path[100];

    S32 fs_ret,  fs_del;
    MMI_BOOL is_abort = MMI_FALSE, is_abort_n = MMI_FALSE,is_valid = MMI_TRUE;
    FMGR_FILTER filter;


   /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPG);

    mmi_wcscpy(m_dest_path, (WCHAR*)AVK_TEST_FILE_PATH);
    mmi_wcscat(m_dest_path, (WCHAR*)L"FmgrSrv\\");
    mmi_wcscpy((WCHAR*)path, (WCHAR*)AVK_TEST_FILE_PATH);
    mmi_wcscat((WCHAR*)path,(WCHAR*)L"IntoMove\\KillBill");
	srv_fmgr_fs_create_folder((WCHAR*)path);
	srv_fmgr_fs_create_folder(m_dest_path);

    mmi_wcscpy((WCHAR*)path, (WCHAR*)AVK_TEST_FILE_PATH);
    mmi_wcscat((WCHAR*)path,(WCHAR*)L"avk_appsrv_fmgr\\123.bmp");
	AVK_LOG_EX((fs_ret = srv_fmgr_async_copy(((WCHAR*)path),m_dest_path, 0, mmi_dummy_proc, NULL)) >= 0);

	AVK_LOG_EX(srv_fmgr_async_abort(fs_ret, MMI_FALSE));
	
	AVK_LOG_EX(SRV_FMGR_ASYNC_STATE_ABORTING == srv_fmgr_async_get_state( fs_ret));

    mmi_wcscpy((WCHAR*)path, (WCHAR*)AVK_TEST_FILE_PATH);
    mmi_wcscat((WCHAR*)path,(WCHAR*)L"IntoMove\\");
	fs_del = 	srv_fmgr_async_delete((WCHAR*)path,0,mmi_dummy_proc,NULL);
   
	mmi_wcscpy(n_dest_path, (WCHAR*)AVK_TEST_FILE_PATH);
	mmi_wcscat(n_dest_path, (WCHAR*)L"MoveFolder\\");
	srv_fmgr_fs_create_folder(n_dest_path);

    mmi_wcscpy((WCHAR*)path, (WCHAR*)AVK_TEST_FILE_PATH);
    mmi_wcscat((WCHAR*)path,(WCHAR*)L"RockBottom");
    srv_fmgr_fs_create_folder( (WCHAR*)path);

    AVK_LOG_EX(FS_DEVICE_BUSY == srv_fmgr_async_move(((WCHAR*)path),n_dest_path, SRV_FMGR_ASYNC_FLAG_PRIORITY_FG, mmi_dummy_proc, NULL));

    AVK_LOG_EX(srv_fmgr_async_is_busy());

    mmi_wcscpy((WCHAR*)path, (WCHAR*)AVK_TEST_FILE_PATH);
    mmi_wcscat((WCHAR*)path,(WCHAR*)L"5454\\23\\23\\545\\888\\");
    srv_fmgr_fs_create_folder(path);
	//fs_del = 	srv_fmgr_async_delete((WCHAR*)path,0,mmi_dummy_proc,NULL);
#ifndef __MMI_SLIM_FILE_MANAGER__
    AVK_LOG_EX(FS_DEVICE_BUSY == srv_fmgr_async_delete_all((WCHAR*)path, &filter, 0, mmi_dummy_proc, NULL));
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vs_appser_fmgr_filelist_001
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_APPSRV_FMGR_FILELIST_001,AVK_APPSRV_FMGR)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_FMGR_FILELIST_HANDLE  m_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	AVK_LOG_EX(0 == srv_fmgr_empty_filelist_create(&m_handle));
	 
    AVK_LOG_EX(srv_fmgr_filelist_get_state(m_handle) == SRV_FMGR_FILELIST_STATE_READY);
    AVK_LOG_EX(srv_fmgr_filelist_get_capability(m_handle) == SRV_FMGR_FILELIST_CAP_RANDOM_ACCESS);
    AVK_LOG_EX(srv_fmgr_filelist_count(m_handle) == 0);
    AVK_LOG_EX(srv_fmgr_filelist_is_empty(m_handle));
    AVK_LOG_EX(srv_fmgr_filelist_is_dirty(m_handle) == MMI_FALSE);
    AVK_LOG_EX(srv_fmgr_filelist_get_filepath(m_handle, 0, NULL, 0) == FS_PARAM_ERROR);
    AVK_LOG_EX(srv_fmgr_filelist_get_filename(m_handle, 0, NULL, 0) == FS_PARAM_ERROR);
    srv_fmgr_filelist_destroy(m_handle);
}

/*****************************************************************************
 * FUNCTION
 *  vs_appser_fmgr_filelist_002
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_APPSRV_FMGR_FILELIST_002,AVK_APPSRV_FMGR)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_FMGR_FILELIST_HANDLE  m_handle;
    WCHAR m_path[SRV_FMGR_PATH_MAX_LEN];
    FMGR_FILTER filter;
    U32 new_sort_option;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPG);
    mmi_wcscpy(m_path, (WCHAR *)L"D:\\Audio");

	AVK_LOG_EX(0 == srv_fmgr_empty_filelist_create(&m_handle));

	AVK_LOG_EX(srv_fmgr_sort_set(FS_SORT_NAME) >= 0);	  
    AVK_LOG_NORMAL(srv_fmgr_filelist_set_setting(m_handle, &filter, FS_SORT_NAME));

	AVK_LOG_NORMAL(srv_fmgr_filelist_get_setting(m_handle, &filter, &new_sort_option));
//    AVK_LOG_FUN(srv_fmgr_filelist_get_setting,new_sort_option == FS_SORT_NAME);

    AVK_LOG_EX(srv_fmgr_filelist_get_filename(m_handle, 0, NULL, 0) == FS_PARAM_ERROR);
    AVK_LOG_EX(srv_fmgr_filelist_get_fileinfo(m_handle, 0, NULL) == FS_PARAM_ERROR);
    AVK_LOG_EX(srv_fmgr_filelist_load_file(m_handle, 0, mmi_dummy_proc, NULL) == FS_PARAM_ERROR);
    AVK_LOG_EX(srv_fmgr_filelist_refresh(m_handle, NULL, 0, 0, mmi_dummy_proc, NULL) == FS_PARAM_ERROR);
    
    srv_fmgr_filelist_destroy(m_handle);
}

/*****************************************************************************
 * FUNCTION
 *  vs_appser_fmgr_notification
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_APPSRV_FMGR_NOTIFICATION,AVK_APPSRV_FMGR)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	WCHAR src_path[100];
	WCHAR des_path[100];
	WCHAR new_path[100];
	WCHAR path[100];
	FMGR_FILTER filter;
	MMI_BOOL is_valid = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPG);

    mmi_wcscpy(path, (WCHAR*)L"D:\\123\\456\\789\\12345678901234567890123456789012345678901234567890\\");
    path[0] = SRV_FMGR_PUBLIC_DRV;
    srv_fmgr_fs_create_folder(path);
    AVK_LOG_EX(0 <= srv_fmgr_fs_delete(path));


    mmi_wcscpy(src_path, (WCHAR*)L"D:\\MERCURY\\");
    src_path[0] = SRV_FMGR_PUBLIC_DRV;
    srv_fmgr_fs_create_folder((const WCHAR*)src_path);

    mmi_wcscpy(path, (WCHAR*)L"D:\\Saturn");
    path[0] = SRV_FMGR_PUBLIC_DRV;
    AVK_LOG_EX(0 == srv_fmgr_fs_rename(((WCHAR*)src_path),((WCHAR*)path)));
    srv_fmgr_fs_delete((WCHAR*)path);
    
    mmi_wcscpy(new_path, (WCHAR*)L"D:\\EARTH\\");
    new_path[0] = SRV_FMGR_PUBLIC_DRV;
    srv_fmgr_fs_create_folder((const WCHAR*)new_path);


    mmi_wcscpy(des_path, (WCHAR*)L"D:\\Images\\Photos\\");
    des_path[0] = SRV_FMGR_PUBLIC_DRV;
    srv_fmgr_fs_create_folder((const WCHAR*)des_path);

#ifndef __MMI_SLIM_FILE_MANAGER__

    mmi_wcscpy((WCHAR*)path,(WCHAR*)AVK_TEST_FILE_PATH);
    mmi_wcscat((WCHAR*)path,(WCHAR*)L"avk_appsrv_fmgr\\123.bmp");
    AVK_LOG_EX( 0 == srv_fmgr_fs_copy((const WCHAR*)path,des_path));

    mmi_wcscat(des_path,(const WCHAR*)L"123.bmp");
    AVK_LOG_EX( 0 == srv_fmgr_fs_move((const WCHAR*)des_path,new_path));

    mmi_wcscpy(des_path, (WCHAR*)L"D:\\Images\\Photos\\");
    des_path[0] = SRV_FMGR_PUBLIC_DRV;
    AVK_LOG(srv_fmgr_fs_delete_all(des_path,&filter));
#endif    
//    srv_fmgr_fs_delete((WCHAR*)des_path);
    srv_fmgr_fs_delete((WCHAR*)new_path);
}

/*****************************************************************************
 * FUNCTION
 *  vs_appser_fmgr_file_types_001
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
AVK_CASE(AVK_APPSRV_FMGR_FILE_TYPES_001,AVK_APPSRV_FMGR)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AVK_LOG_EX(srv_fmgr_types_find_type_by_filename_str((WCHAR*)L"123.bmp") == FMGR_TYPE_BMP);
    AVK_LOG_EX(srv_fmgr_types_find_type_by_extension_str((WCHAR*)L"bmp") == FMGR_TYPE_BMP);
    AVK_LOG_EX(srv_fmgr_types_find_type_by_filepath((WCHAR*)L"123.bmp") == FMGR_TYPE_BMP);
    AVK_LOG_EX(srv_fmgr_types_find_group_by_type(FMGR_TYPE_BMP) == FMGR_GROUP_IMAGE);
    AVK_LOG_EX(srv_fmgr_types_find_group_by_filename_str((WCHAR*)L"123.bmp") == FMGR_GROUP_IMAGE);
}

/*****************************************************************************
 * FUNCTION
 *  vs_appser_fmgr_file_types_002
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
AVK_CASE(AVK_APPSRV_FMGR_FILE_TYPES_002,AVK_APPSRV_FMGR)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                   */
    /*----------------------------------------------------------------*/
       FMGR_FILTER filter;
     
   /*----------------------------------------------------------------*/
    /* Code Body                                                                           */
    /*----------------------------------------------------------------*/

    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_BMP);
    
    AVK_LOG_EX(srv_fmgr_types_get_main_type(&filter) == FMGR_TYPE_BMP);
    AVK_LOG_EX(strcmp(srv_fmgr_types_get_extension(FMGR_TYPE_BMP), "BMP") == 0);
    AVK_LOG_EX(mmi_wcscmp(srv_fmgr_types_get_extension_ucs2(FMGR_TYPE_BMP), (WCHAR*)L"BMP") == 0);
    AVK_LOG_EX(srv_fmgr_types_get_icon(FMGR_TYPE_BMP, NULL, SRV_FMGR_TYPES_ICON_SMALL) != 0);
    AVK_LOG_EX(srv_fmgr_types_get_icon(FMGR_TYPE_BMP, NULL, SRV_FMGR_TYPES_ICON_LARGE) != 0);
    AVK_LOG_EX(srv_fmgr_types_get_option_menu(FMGR_TYPE_BMP, NULL, 0)  >  0);
    AVK_LOG_EX(srv_fmgr_types_get_send_option_menu(FMGR_TYPE_BMP, NULL) >  0);
    AVK_LOG_EX(srv_fmgr_types_get_use_option_menu(FMGR_TYPE_BMP, NULL) >= 0);
}


#ifndef __MMI_MRE_DISABLE_FMGR__
/*****************************************************************************
 * FUNCTION
 *  vs_appser_fmgr_file_types_003
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
AVK_CASE(AVK_APPSRV_FMGR_FILE_TYPES_003,AVK_APPSRV_FMGR)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                   */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    WCHAR path[SRV_FMGR_PATH_MAX_LEN+1];
    const WCHAR *filepath = NULL;
    mmi_id menu  = MENU_ID_FMGR_MRE_FILE_OPEN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                           */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    AVK_LOG_NORMAL(srv_fmgr_types_filter_set_group(&filter, FMGR_GROUP_AUDIO));

    mmi_wcscpy((WCHAR*)path, (WCHAR*)AVK_TEST_FILE_PATH);
    mmi_wcscpy((WCHAR*)path, (WCHAR*)L"GAMEPLAN");

    AVK_LOG_EX(0 == srv_fmgr_fs_create_folder((const WCHAR*)path));

    AVK_LOG_EX(NULL == srv_fmgr_types_query_fileinfo(NULL));

    AVK_LOG_EX(1 == srv_fmgr_types_launch_option((WCHAR *)path, menu));

	AVK_LOG_EX(srv_fmgr_types_filter_is_in_group((const FMGR_FILTER *)&filter,FMGR_GROUP_AUDIO));
#ifdef __COSMOS_MMI_PACKAGE__
	mmi_frm_exec_key_handler(KEY_BACK,KEY_EVENT_DOWN);
	mmi_frm_exec_key_handler(KEY_BACK,KEY_EVENT_UP);
#else
    mmi_frm_exec_key_handler(KEY_RSK,KEY_EVENT_DOWN);
	mmi_frm_exec_key_handler(KEY_RSK,KEY_EVENT_UP);
#endif
}
#endif
/*****************************************************************************
 * FUNCTION
 *  vs_appser_fmgr_customized
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
AVK_CASE(AVK_APPSRV_FMGR_CUSTOMIZED,AVK_APPSRV_FMGR)
{

#if defined(__MMI_FMGR_CUSTICON_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR path[SRV_FMGR_PATH_MAX_LEN+1];
	WCHAR m_objpath[SRV_FMGR_PATH_MAX_LEN+1];
	FS_HANDLE fh;
	S32 fs_ret1,fs_ret2 ;
	MMI_BOOL  is_type = MMI_FALSE;
	MMI_BOOL is_cust_icon = MMI_TRUE;	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_wcscpy(m_objpath, (WCHAR*)L"D:\\a.txt");
    m_objpath[0] = SRV_FMGR_PUBLIC_DRV;
    fh = FS_Open(m_objpath, FS_READ_WRITE | FS_CREATE_ALWAYS);
    FS_Write(fh, m_objpath, sizeof(m_objpath), NULL);
    FS_Close(fh);

    mmi_wcscpy((WCHAR*)path, (WCHAR*)L"D:\\b.jpg");
    path[0] = SRV_FMGR_PUBLIC_DRV;
    fh = FS_Open((WCHAR*)path, FS_READ_WRITE | FS_CREATE_ALWAYS);
    FS_Write(fh, path, sizeof(path), NULL);
    FS_Close(fh);

    AVK_LOG_EX(0 == srv_fmgr_custicon_do(SRV_FMGR_CUSTICON_OP_REGISTER, m_objpath, path));

    AVK_LOG_EX(0 == srv_fmgr_custicon_query(m_objpath, path, sizeof(path)));

    AVK_LOG_EX(srv_fmgr_custicon_is_type_support(FMGR_TYPE_JPEG));
#else
    AVK_LOG_FUN_UNSUPPORTED(srv_fmgr_custicon_do);
    AVK_LOG_FUN_UNSUPPORTED(srv_fmgr_custicon_query);
    AVK_LOG_FUN_UNSUPPORTED(srv_fmgr_custicon_is_type_support);
    AVK_CASE_RESULT(AVK_PASS);
#endif

}


