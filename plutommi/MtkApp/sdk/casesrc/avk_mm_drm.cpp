#if defined (__DRM_SUPPORT__)
extern "C"
{
#include "drm_memory.h"
#include "FileMgrType.h"
#include "drm_core_def.h"
#include "drm_gprot.h"

module_type stack_int_get_active_module_id(void);
}
#define AVK_MM_DRM_TEST_FILE_NAME L"test.mp3"
#define AVK_MM_DRM_SOURCE_PATH_DRM L"avk_mm_drm\\CombinedDelivery_mp3.dm"
#define AVK_MM_DRM_SOURCE_PATH_MP3 avk_mm_drm_mp3_path
//#define AVK_MM_DRM_SOURCE_PATH_TIMED_JPG L"D:\\AVK\\test file\\avk_mm_drm\\timetest.jpg"
#define AVK_MM_DRM_DEST_PATH AVK_TEST_FILE_PATH
#define AVK_MM_DRM_PATH_DCF  L"D:\\Audio\\sd.dcf"

WCHAR avk_mm_drm_mp3_path[20];
/*****************************************************************************
 * FUNCTION
 *  avk_mm_drm_consume_rights
 * DESCRIPTION
 *  entry function for DRM consume rights
 * PARAMETERS
 *  index
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_MM_DRM_CONSUME_RIGHTS, AVK_MM_DRM)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*DRM Serial*/
    kal_uint8 serial = 0;
    kal_uint8 *p_serial;
    UI_character_type source_path[64];
    UI_character_type dest_path[64];
    UI_character_type temp_path[64];
    /*DRM content type, its a fixed string */
    kal_uint8 content_type[] = "application\/vnd.oma.drm.message"; 
    S32 ret = 0;
    applib_mime_type_struct *cnf = NULL;
    MMI_BOOL success = MMI_TRUE;
    int file,tmp_file, res;
    UINT size = 0,temp_size;
    CHAR *buff = NULL;
    U8 result =0; //Akhil
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((CHAR *)avk_mm_drm_mp3_path, (CHAR *)AVK_TEST_FILE_PATH);
    mmi_ucs2cat((CHAR *)avk_mm_drm_mp3_path, (const CHAR*)L"test.mp3");
    
    mmi_ucs2cpy((char *)source_path,(const CHAR*)AVK_TEST_FILE_PATH);
    mmi_ucs2cat((char *)source_path,(const CHAR*)AVK_MM_DRM_SOURCE_PATH_DRM);
    mmi_ucs2cpy((char *)dest_path,(char*)AVK_MM_DRM_DEST_PATH);     
    mmi_ucs2cat((char *)dest_path,(const CHAR*)L"test");
    mmi_ucs2cpy((char *)temp_path,(const CHAR*)source_path);
    mmi_ucs2cat((char *)temp_path,(const CHAR*)L"tmp");
    
    file = FS_Open(source_path,FS_READ_ONLY);
    res = FS_GetFileSize(file,&size);
    if(FS_NO_ERROR == res)
	{
                     if (size > 0)
                     {
                      buff = (CHAR*)AVK_MALLOC(size);
                      }
                      FS_Read(file,buff,size,&temp_size);
                      FS_Close(file);
                      tmp_file = FS_Open(temp_path,FS_CREATE_ALWAYS);
                      FS_Write(tmp_file,buff,size,&temp_size);
                      FS_Close(tmp_file);
    
                       /* Install object before use, callback passed as NULL*/
                       p_serial = &serial;
			   /* AVK_LOG_EX(0 == DRM_install_object(
                                              content_type,
                                              source_path,
                                              KAL_FALSE,
                                              dest_path,
                                              152,
                                              p_serial,
                                              &cnf,
                                              NULL));

                                FS_Rename((WCHAR *)temp_path,(WCHAR *)source_path);
				AVK_FREE(buff);*/

				result = AVK_LOG_EX(0 == DRM_install_object(
						content_type,
						source_path,
						KAL_FALSE,
						dest_path,
						152,
						p_serial,
						&cnf,
						NULL));
			   
					
    						FS_Rename((WCHAR *)temp_path,(WCHAR *)source_path);
                                                AVK_FREE(buff);
               }



}


/*****************************************************************************
 * FUNCTION
 *  avk_mm_drm_install_callback
 * DESCRIPTION
 *  callback for DRM install function
 * PARAMETERS
 *  index
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_MM_DRM_OPEN_CONSUME, AVK_MM_DRM_CONSUME_RIGHTS)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    U32 read_size = 0;
    void *buf;
    MMI_BOOL success = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /*FILE OPEN*/
    handle = DRM_open_file((U16*)AVK_MM_DRM_SOURCE_PATH_MP3, FS_READ_ONLY, DRM_PERMISSION_PLAY);
    AVK_LOG_FUN(DRM_open_file, handle >= 0);
    
    /*FILE VALIDATE*/
    AVK_LOG_EX(!DRM_validate_permission(handle, NULL, DRM_PERMISSION_PLAY));

    /*FILE READ*/
    buf = AVK_MALLOC( 1024 );
    AVK_LOG_EX(FS_NO_ERROR == DRM_read_file(handle, buf, 1024, &read_size));
    
    /*FILE CONSUME*/
    /*
    res = DRM_consume_rights(handle, DRM_PERMISSION_PLAY, NULL);*/
   
    /* PAUSE CONSUMPTION */
    //DRM_pause_consume(res);

    /* DRM resume consumption */
    /*
    resume_consume = DRM_resume_consume(res);
    
    if(resume_consume)
    {
        vs_tfw_trace_result(L"avk_mm_drm_open_consume : DRM_resume_consume->success  ", MMI_TRUE, 0, VS_TA_MM_DRM);
    }
    else
    {
        vs_tfw_trace_result(L"avk_mm_drm_open_consume : DRM_resume_consume->fail", MMI_FALSE, 0, VS_TA_MM_DRM);
        success = MMI_FALSE;
    }
    */
    /* check for consumption */

    AVK_LOG_EX(!DRM_consume_table_is_in_use());

    /* Check for extendable rights */
    AVK_LOG_EX(!DRM_rights_extendable((kal_wchar *)AVK_MM_DRM_SOURCE_PATH_MP3));
    
    /*FILE CLOSE */
    AVK_LOG_EX(0 == DRM_close_file(handle));
    
    AVK_FREE(buf);
}

/*****************************************************************************
 * FUNCTION
 *  avk_mm_drm_version_size
 * DESCRIPTION
 *  Gets version and size of the file
 * PARAMETERS
 *  index
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_MM_DRM_VERSION_SIZE, AVK_MM_DRM_CONSUME_RIGHTS)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 version = 0;
    kal_uint32 size = 0;
    kal_uint32 pos = 10000; /* Sentinel value, infinity for this case*/
    kal_int32 url_size = DRM_MAX_URL_LENGTH;
    FS_HANDLE handle, dcf_handle ;
    kal_int8 url[DRM_MAX_URL_LENGTH];
    MMI_BOOL success = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------- -----*/
    version = DRM_get_version();
    
    /* compare the version for __DRM_V02__ or __DRM_V01__*/
    AVK_LOG_FUN(DRM_get_version, (version == 0x00020000) || (version == 0x00010000) ) ;
    

    /* Get the file size */
    handle = DRM_open_file((U16*)AVK_MM_DRM_SOURCE_PATH_MP3, FS_READ_ONLY, DRM_PERMISSION_PLAY);
    
    /* Error in opening the file */
    AVK_LOG_FUN(DRM_open_file, handle >= 0);

    /* Get the file size */
    DRM_file_size(handle, &size);
    AVK_LOG_FUN(DRM_file_size, 0 != size);
    
    DRM_file_pos(handle, &pos);
    AVK_LOG_FUN(DRM_file_pos, 0 == pos);

    /* Get rights issuer */
    memset (url, 0, DRM_MAX_URL_LENGTH);
    dcf_handle = DRM_open_file((U16*)AVK_MM_DRM_PATH_DCF, FS_READ_ONLY, DRM_PERMISSION_NONE);
    DRM_get_rights_issuer(dcf_handle, (kal_char*)url, (kal_uint32 *)&url_size);

    AVK_LOG_FUN(DRM_get_rights_issuer,!url[0]);
    
    DRM_close_file(dcf_handle);

    /* DRM register file */
    AVK_LOG_EX(0 == DRM_register_file((kal_wchar*)AVK_MM_DRM_SOURCE_PATH_MP3));
    
    DRM_close_file(handle);
}

/*****************************************************************************
 * FUNCTION
 *  avk_mm_drm_content
 * DESCRIPTION
 *  gets content type, extension etc.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_MM_DRM_CONTENT, AVK_MM_DRM_CONSUME_RIGHTS)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *content = NULL;
    kal_uint8 *ext = NULL;
    kal_uint8 object_method;
    applib_mime_type_struct *content_type_entry = NULL;
    FS_HANDLE handle;
    MMI_BOOL success  = MMI_TRUE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------- -----*/    
    /* Get content type */
    AVK_LOG_EX(DRM_get_content_type(0, (kal_wchar *) AVK_MM_DRM_SOURCE_PATH_MP3)); 

    /* Get content ext */
    AVK_LOG_EX(DRM_get_content_ext(0,(kal_wchar *)AVK_MM_DRM_SOURCE_PATH_MP3));

    handle = DRM_open_file((U16*)AVK_MM_DRM_SOURCE_PATH_MP3, FS_READ_ONLY, DRM_PERMISSION_PLAY);
    
    /* Check whether the file is a DRM file or not */
    AVK_LOG_EX(DRM_is_drm_file( handle, (kal_wchar*) AVK_MM_DRM_SOURCE_PATH_MP3));
    
    /* Check forward lock */    
    AVK_LOG(DRM_interdev_movable(handle, (kal_wchar*) AVK_MM_DRM_SOURCE_PATH_MP3));
    
    /* get content type entry */

    content_type_entry = DRM_get_content_type_entry(handle);
    AVK_LOG_FUN(DRM_get_content_type_entry, 
                    (content_type_entry != NULL) && (content_type_entry->mime_type == MIME_TYPE_AUDIO));

    /* Get object Method */
    object_method = DRM_get_object_method(0, (kal_wchar*)AVK_MM_DRM_SOURCE_PATH_MP3);

    switch(object_method)
    {
        case DRM_METHOD_NONE:
        case DRM_METHOD_FORWARD_LOCK:
        case DRM_METHOD_COMBINED_DELIVERY:
        case DRM_METHOD_SEPARATE_DELIVERY:
        case DRM_METHOD_V2:
        case DRM_METHOD_PDCF:
            AVK_LOG_FUN(DRM_get_object_method,AVK_PASS);
        break;

        default:
            AVK_LOG_FUN(DRM_get_object_method,AVK_FAIL);
    }

    DRM_close_file(handle);
}

/*****************************************************************************
 * FUNCTION
 *  avk_mm_drm_meta_size_data
 * DESCRIPTION
 *  gets meta size and data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_MM_DRM_META, AVK_MM_DRM_CONSUME_RIGHTS)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    kal_int32 buf_size = 0, result = 10000; //sentinel value
    kal_char* buffer = NULL;
    drm_constraint_struct cons;
    MMI_BOOL success = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------- -----*/    
    /* Open file */
    handle = DRM_open_file((U16*)AVK_MM_DRM_SOURCE_PATH_MP3, FS_READ_ONLY, DRM_PERMISSION_PLAY);
    
    /* get meta size */
    AVK_LOG_EX(DRM_get_meta_size(handle, DRM_META_CONTENTURI) > 0);


    buffer = (kal_char *)drmt_mem_alloc(DRM_MAX_CID_URL_LENGTH);    
    /* Get Meta Data*/
    
    AVK_LOG_EX(0 == DRM_get_meta_data(handle, DRM_META_CONTENTURI, buffer, DRM_MAX_CID_URL_LENGTH));

    drmt_mem_free(buffer);

    /* Get constraint */
    DRM_get_constraint(handle,(kal_wchar*)AVK_MM_DRM_SOURCE_PATH_MP3, DRM_PERMISSION_PLAY, &cons);
    AVK_LOG_FUN(DRM_get_constraint, cons.status == DRM_STATUS_NO_RIGHTS);
    
    DRM_close_file(handle);
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
#endif
/*****************************************************************************
 * FUNCTION
 *  avk_mm_drm_file_operations
 * DESCRIPTION
 *  file seek / large file seek
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_MM_DRM_FILE_OP, AVK_MM_DRM_CONSUME_RIGHTS) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    kal_int32 res = 0;
    kal_uint32 size = 0;
    MMI_BOOL success = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------- -----*/    
    handle = DRM_open_file((U16*)AVK_MM_DRM_SOURCE_PATH_MP3, FS_READ_ONLY, DRM_PERMISSION_PLAY);
    
    /* seek file, it internally uses DRM_seek_large_file */    
    DRM_file_size(handle, &size);
    res = DRM_seek_file(handle, size, FS_FILE_BEGIN);
    AVK_LOG_FUN(DRM_seek_file, res == size);
    DRM_close_file(handle);
}

/*****************************************************************************
 * FUNCTION
 *  avk_mm_drm_sd_callback
 * DESCRIPTION
 *  call back for sd register by path
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern "C" kal_bool avk_mm_drm_sd_callback(void *para, kal_uint8 type)  
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------- -----*/  
    AVK_LOG_NORMAL(DRM_cancel_sd_callback(0));
    if (para)
    {
        DRM_close_file((FS_HANDLE)para);
    }
    AVK_CASE_RESULT(AVK_PASS);
    AVK_ASYN_DONE();
    return KAL_TRUE;
}

AVK_ASYN_CASE(AVK_MM_DRM_SD_CB, AVK_MM_DRM_CONSUME_RIGHTS)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 sd_cb_res;
    void *para = NULL;
    MMI_BOOL success = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------- -----*/
    
    /* Register sd callback */
    AVK_CASE_RESULT(AVK_FAIL);
    sd_cb_res = DRM_register_sd_callback((kal_wchar*)AVK_MM_DRM_SOURCE_PATH_MP3, 1, para, avk_mm_drm_sd_callback); 
    AVK_LOG_FUN(DRM_register_sd_callback, sd_cb_res >= 0);
    
    /* Check the callback status */
    AVK_LOG(DRM_sd_callback_status(sd_cb_res));   
    if (sd_cb_res < 0)
    {
    	AVK_ASYN_DONE();
    }
}

AVK_ASYN_CASE(AVK_MM_DRM_SD_CB_HANDLE, AVK_MM_DRM_CONSUME_RIGHTS)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    S32 result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------- -----*/   
    AVK_CASE_RESULT(AVK_FAIL);
    handle = DRM_open_file((U16*)AVK_MM_DRM_SOURCE_PATH_MP3, FS_READ_ONLY, DRM_PERMISSION_PLAY);
    
    /* Register sd callback by handle */
    AVK_LOG_ASYN(result = DRM_register_sd_callback_by_handle(handle, 1, (void*)handle, avk_mm_drm_sd_callback));
	if (result < 0)
    {
    	AVK_ASYN_DONE();
    }
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

/*****************************************************************************
 * FUNCTION
 *  avk_mm_drm_cancel_process
 * DESCRIPTION
 * API to test process cancel APIs of DRM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_MM_DRM_CANCEL_PROCESS, AVK_MM_DRM_CONSUME_RIGHTS)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    MMI_BOOL cancel_res = MMI_FALSE;
    kal_uint8 serial = 0; 
    /*DRM content type, its a fixed string */    
    kal_uint8 content_type[] = "application\/vnd.oma.drm.message"; 
    S32 ret = 0;
    applib_mime_type_struct *cnf = NULL;   
    MMI_BOOL success = MMI_TRUE; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------- -----*/
    AVK_LOG_EX(DRM_async_cancel_current_process());
/*
    mmi_ucs2cpy((char *)source_path,(const CHAR*)L"D:\\AVK\\test file\\avk_mm_drm\\process_cancel.dm");
    
    mmi_ucs2cpy((char *)dest_path,(char*)AVK_MM_DRM_DEST_PATH);
    mmi_ucs2cat((char *)dest_path,(const CHAR*)L"processtest");

    p_serial = &serial;
    ret = DRM_install_object(
            content_type,
            source_path,
            KAL_FALSE,
            dest_path,
            152,
            p_serial,
            &cnf,
            NULL);

*/
    AVK_LOG(DRM_async_cancel_process(ret));
    FS_Delete((WCHAR*)AVK_MM_DRM_SOURCE_PATH_MP3);
}
#endif
