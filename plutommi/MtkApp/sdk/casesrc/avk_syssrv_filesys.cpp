extern "C"
{
  #include "fs_gprot.h"
  #include "fsal.h"
}

AVK_ADD_ITEM(AVK_SYSSRV_FILE_AUTO,L"Auto case",AVK_SYSSRV_FILE);
AVK_ADD_ITEM(AVK_SYSSRV_FILE_MANU,L"Manual case",AVK_SYSSRV_FILE);
AVK_ADD_ITEM_SPECIAL(AVK_SYSSRV_FILE_SPEC,L"Special case",AVK_SYSSRV_FILE);

typedef void (*TESTCASE_FUNC_TYPE) (void);

typedef struct
{
    MMI_BOOL allow_run;
    U32 counter;
    U32 total_num;
    TESTCASE_FUNC_TYPE func_list[30];
} vs_fs_test_context_struct;


static WCHAR g_filesys_path[50] = {0};
static WCHAR g_filesys_folder[50] = {0};
static WCHAR g_filesys_file[FS_MAX_PATH] = {0};
static WCHAR g_filesys_audio1[FS_MAX_PATH];
static WCHAR g_filesys_audio2[FS_MAX_PATH];
static vs_fs_test_context_struct g_tst_fs_cntx;

typedef enum
{
    VS_SYS_FS_FOLDER,
    VS_SYS_FS_FILE
} vs_fs_type_enum;

typedef enum
{
    VS_SYS_FS_EQUAL,
    VS_SYS_FS_LESS,
    VS_SYS_FS_GREATER
} vs_fs_compare_enum;

/*****************************************************************************
 * FUNCTION
 *  CreatePath
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void CreatePath(WCHAR *FolderName, WCHAR *FullDir)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret_drv;
    char buf[5];
    FS_HANDLE MyHandle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_drv = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
    if (ret_drv >= 0)
    {
      sprintf(buf, "%c:\\", (U8) ret_drv);
      mmi_asc_to_wcs(FullDir,buf);
      mmi_wcscat(FullDir,FolderName);
    }

    MyHandle=FS_Open(FullDir,FS_READ_ONLY);
    if (MyHandle<FS_NO_ERROR)
    {
      FS_CreateDir(FullDir);
    }
    FS_Close(MyHandle);
}

/*****************************************************************************
 * FUNCTION
 *  vs_sysser_filesys_init
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
int vs_sysser_filesys_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret_drv;
    S32 ret_remove_drv;
    char buf[5];
    FS_HANDLE MyHandle;
    STFSAL pstFSAL;

     WCHAR path_temp1[FS_MAX_PATH];
     WCHAR path_temp2[FS_MAX_PATH];
     WCHAR filesys_path[FS_MAX_PATH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* test fsal first */
    FSAL_Direct_SetRamFileSize(&pstFSAL, 512);

    /*Create Start: Create Folder For File System Test*/
     ret_drv = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
     if (ret_drv >= 0)
     {
        sprintf(buf, "%c:\\", (U8)ret_drv);
        mmi_asc_to_wcs(g_filesys_path,buf);
        mmi_wcscat(g_filesys_path,(WCHAR *)L"AVK\\");
        MyHandle=FS_Open(g_filesys_path,FS_READ_ONLY);
        if (MyHandle<FS_NO_ERROR)
        {
          FS_CreateDir(g_filesys_path);
        }else{
          FS_Close(MyHandle);
        }

        mmi_wcscat(g_filesys_path,(WCHAR *)L"test file\\");
        MyHandle=FS_Open(g_filesys_path,FS_READ_ONLY);
        if (MyHandle<FS_NO_ERROR)
        {
          FS_CreateDir(g_filesys_path);
        }else{
          FS_Close(MyHandle);
        }

        mmi_wcscat(g_filesys_path,(WCHAR *)L"avk_filesys\\");
        MyHandle=FS_Open(g_filesys_path,FS_READ_ONLY);
        if (MyHandle<FS_NO_ERROR)
        {
          FS_CreateDir(g_filesys_path);
        }else{
          FS_Close(MyHandle);
        }

        mmi_wcscpy(g_filesys_audio1,g_filesys_path);
        mmi_wcscat(g_filesys_audio1,(WCHAR *)L"tst_sysser_filesys_file1.mp3");
        mmi_wcscpy(g_filesys_audio2,g_filesys_path);
        mmi_wcscat(g_filesys_audio2,(WCHAR *)L"tst_sysser_filesys_file2.mp3");
      }else{
        return -1;
      }

     if ((FS_CheckFile(g_filesys_audio1) < FS_NO_ERROR)|(FS_CheckFile(g_filesys_audio2) < FS_NO_ERROR))
     {
        ret_remove_drv = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
        if (ret_remove_drv >= 0)
        {
           sprintf(buf, "%c:\\", (U8)ret_remove_drv);
           mmi_asc_to_wcs(filesys_path,buf);
           mmi_wcscat(filesys_path,(WCHAR *)L"AVK\\test file\\avk_filesys\\");

           mmi_wcscpy(path_temp1,filesys_path);
           mmi_wcscat(path_temp1,(WCHAR *)L"tst_sysser_filesys_file1.mp3");
           mmi_wcscpy(path_temp2,filesys_path);
           mmi_wcscat(path_temp2,(WCHAR *)L"tst_sysser_filesys_file2.mp3");
        }else{
           return -1;
        }

        if ((FS_CheckFile(path_temp1) < FS_NO_ERROR)|(FS_CheckFile(path_temp2) < FS_NO_ERROR))
         {
             return -1;
         } else {
            FS_Move(filesys_path, g_filesys_path, FS_MOVE_OVERWRITE|FS_MOVE_COPY, NULL, NULL, 0);
        }
     }

     ret_drv = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
     if (ret_drv >= 0)
     {
       sprintf(buf, "%c:\\", (U8)ret_drv);
       mmi_asc_to_wcs(g_filesys_path,buf);
       mmi_wcscat(g_filesys_path,(WCHAR *)L"TestFiles");
      }

     MyHandle=FS_Open(g_filesys_path,FS_READ_ONLY);
     if (MyHandle>=FS_NO_ERROR)
     {
       FS_XDelete(g_filesys_path, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
     }
     FS_CreateDir(g_filesys_path);
     FS_Close(MyHandle);
     /*Create End*/

     /* Init Start*/
     mmi_wcscpy(g_filesys_folder,g_filesys_path);
     mmi_wcscat(g_filesys_folder,(WCHAR *)L"\\tst_syser_filesys_file");

     mmi_wcscpy(g_filesys_file,g_filesys_path);
     mmi_wcscat(g_filesys_file,(WCHAR *)L"\\tst_syser_filesys_file.txt");

    return 0;
    /* Init End*/

}

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_IO_FS_Open_Close
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_IO_FS_Open_Close(const WCHAR * FileName, UINT Flag, vs_fs_type_enum Type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval;
    FS_HANDLE MyHandle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MyHandle=FS_Open(FileName,Flag);

    if (MyHandle < FS_NO_ERROR)
    {
        if (VS_SYS_FS_FOLDER==Type)
        {
            MyHandle = FS_CreateDir(FileName);
            if (MyHandle < FS_NO_ERROR)
            {
                ASSERT(0);//Create folder Fail
                return;
            }
        } else {
            MyHandle = FS_Open(FileName, FS_READ_WRITE | FS_CREATE);
            if (MyHandle < FS_NO_ERROR)
            {
                ASSERT(0);//Create file fail
                return;
            }
        }
    }
    FS_Close(MyHandle);

    MyHandle=FS_Open(FileName,Flag);
    AVK_LOG_FUN(FS_Open,(MyHandle>FS_NO_ERROR));
    if(MyHandle>FS_NO_ERROR)
    {
        reval=FS_Close(MyHandle);
        AVK_LOG_FUN(FS_Close,(FS_NO_ERROR==reval));

        if (VS_SYS_FS_FOLDER==Type)
        {
            FS_XDelete(FileName, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
            FS_RemoveDir(FileName);
        }else{
            FS_Delete(FileName);
        }
    }else{
        AVK_LOG_FUN(FS_Close,AVK_FAIL);
    }

}

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_IO_FS_OpenHint
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_IO_FS_OpenHint(const WCHAR * FileName)
{
  #ifdef __MTP_ENABLE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE MyHandle;
    FS_FileOpenHint dsr_hint;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&dsr_hint, 0, sizeof(dsr_hint));
    MyHandle=FS_OpenHint(FileName,FS_READ_WRITE | FS_CREATE,&dsr_hint);
    //mmi_asc_to_wcs(&drvLetter,(char *)&dsr_hint.Drive);
    AVK_LOG_FUN(FS_OpenHint,(MyHandle>=FS_NO_ERROR));
    FS_Close(MyHandle);

  #else
    AVK_LOG_FUN_UNSUPPORTED(FS_OpenHint);
  #endif /*__MTP_ENABLE__*/

}

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_IO_FS_CloseAll
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_IO_FS_CloseAll(const WCHAR * FolderName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval;
    WCHAR FileName1[100];
    WCHAR FileName2[100];
    FS_HANDLE MyHandle1;
    FS_HANDLE MyHandle2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcscpy(FileName1,FolderName);
    mmi_wcscat(FileName1,(WCHAR *)L"\\test1.txt");

    mmi_wcscpy(FileName2,FolderName);
    mmi_wcscat(FileName2,(WCHAR *)L"\\test2.txt");

    MyHandle1=FS_Open(FileName1,FS_READ_WRITE | FS_CREATE);
    if(MyHandle1<FS_NO_ERROR)
    {
        MyHandle1=FS_CreateDir(FolderName);
    }
    FS_Close(MyHandle1);

    MyHandle1=FS_Open(FileName1,FS_READ_WRITE | FS_CREATE);
    if(MyHandle1<FS_NO_ERROR)
    {
        ASSERT(0);//File create fail
    }

    MyHandle2=FS_Open(FileName2,FS_READ_WRITE | FS_CREATE);
    if(MyHandle2<FS_NO_ERROR)
    {
        ASSERT(0);//File create fail
    }

    reval=FS_CloseAll();
    AVK_LOG_FUN(FS_CloseAll,(MyHandle2==reval));

    FS_Delete(FileName1);
    FS_Delete(FileName2);

    FS_XDelete(FolderName, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
    FS_RemoveDir(FolderName);
}

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_IO_FS_Write_Read
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_IO_FS_Write_Read(const WCHAR * FileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval;
    S32 len;
    char data[]="Test FS_Write & FS_Read";
    FS_HANDLE MyHandle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MyHandle=FS_Open(FileName,FS_READ_WRITE | FS_CREATE);
    if(MyHandle<FS_NO_ERROR)
    {
        ASSERT(0);//File create fail
    }

    reval = FS_Write(MyHandle,(U8 *)data,strlen(data),(UINT *)&len );
    AVK_LOG_FUN(FS_Write,((reval==FS_NO_ERROR)&&(len==strlen(data))));
    FS_Close(MyHandle);

    MyHandle=FS_Open(FileName,FS_READ_ONLY);
    if(MyHandle<FS_NO_ERROR)
    {
      ASSERT(0);//File create fail
    }
    memset(data, 0 , sizeof(data));
    reval = FS_Read(MyHandle,data,13,(UINT *)&len);
    AVK_LOG_FUN(FS_Read,((reval==FS_NO_ERROR)&&(13==len)&&(0==strcmp(data,"Test FS_Write"))));

    FS_Close(MyHandle);
    FS_Delete(FileName);
}

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_IO_FS_Seek
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_IO_FS_Seek(const WCHAR * FileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval;
    s32 len;
    char data[]="1234567890";
    FS_HANDLE MyHandle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MyHandle=FS_Open(FileName,FS_READ_WRITE | FS_CREATE);
    if(MyHandle<FS_NO_ERROR)
    {
        ASSERT(0);//File create fail
    }

    reval = FS_Write(MyHandle,(U8 *)data,strlen(data),(UINT *)&len );
    if(reval<FS_NO_ERROR)
    {
        ASSERT(0);//FS_Write faill
    }
    reval = FS_Seek(MyHandle,2,FS_FILE_BEGIN);
    memset(data, 0 , sizeof(data));
    FS_Read(MyHandle,data,5,(UINT *)&len);
    AVK_LOG_FUN(FS_Seek,((2==reval)&&(0==strcmp(data,"34567"))));

    FS_Close(MyHandle);
    FS_Delete(FileName);
}

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_IO_FS_Commit
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_IO_FS_Commit(const WCHAR *FileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval;
    s32 len;
    char data[]="1234567890";
    FS_HANDLE MyHandle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MyHandle=FS_Open(FileName,FS_READ_WRITE | FS_CREATE);
    if(MyHandle<FS_NO_ERROR)
    {
        ASSERT(0);//File create fail
    }

    reval = FS_Write(MyHandle,(U8 *)data,strlen(data),(UINT *)&len );
    if(reval<FS_NO_ERROR)
    {
        ASSERT(0);//FS_Write faill
    }
    reval=FS_Commit(MyHandle);
    AVK_LOG_FUN(FS_Commit,(reval==FS_NO_ERROR));

    FS_Close(MyHandle);
    FS_Delete(FileName);
}

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_IO_FS_ParseFH
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_IO_FS_ParseFH(const WCHAR *FileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    FS_HANDLE MyHandle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MyHandle=FS_Open(FileName, FS_CREATE_ALWAYS|FS_READ_WRITE);
    index=FS_ParseFH(MyHandle);

    AVK_LOG_FUN(FS_ParseFH,(index>=0));

    FS_Close(MyHandle);
    FS_Delete(FileName);
}

void vs_fsys_IO_FS_GenVirtualFileName(void)
{
    S32 reval;
    FS_HANDLE MyHandle, MyHandle2;
    WCHAR virtual_file_name[(FS_GenVFN_SIZE + SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1) * ENCODING_LENGTH] = {0};

    MyHandle = FS_Open(g_filesys_audio1, FS_READ_ONLY | FS_OPEN_SHARED);
    if (MyHandle >= FS_NO_ERROR)
    {
        reval = FS_GenVirtualFileName(MyHandle, virtual_file_name, FS_GenVFN_SIZE, 200, 300);
        AVK_LOG_FUN(FS_GenVirtualFileName, (reval >= FS_NO_ERROR));
        if (reval >= FS_NO_ERROR)
        {
            MyHandle2 = FS_Open(virtual_file_name, FS_READ_ONLY);
            AVK_LOG_FUN(FS_GenVirtualFileName, (reval >= FS_NO_ERROR));
            if (reval >= FS_NO_ERROR)
            {
                FS_Seek(MyHandle2, 33, FS_FILE_BEGIN);
                FS_Close(MyHandle2);
            }
        }
        FS_Close(MyHandle);
    }

}

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_IO_FS_SetSeekHint
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_IO_FS_SetSeekHint(const WCHAR * FileName)
{
    #define MY_HINT_NUM (5)
    #define MY_TARGET_BYTE (3999)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval;
    FS_HANDLE MyHandle;
    FS_FileLocationHint MyHint[MY_HINT_NUM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MyHint[0].Index = 1000;
    MyHint[1].Index = 5000;
    MyHint[2].Index = 10000;
    MyHint[3].Index = 15000;
    MyHint[4].Index = 20000;

    // Seek with hint
    MyHandle = FS_Open(FileName, FS_OPEN_NO_DIR);
    if (MyHandle > FS_NO_ERROR)
    {
        reval = FS_SetSeekHint(MyHandle, MY_HINT_NUM, MyHint);
        //Add trace info for debug
        //kal_prompt_trace(MOD_MMI, "%d;%d", reval, FS_Seek(MyHandle, MY_TARGET_BYTE, FS_FILE_BEGIN));
        AVK_LOG_FUN(FS_SetSeekHint,((reval >= FS_NO_ERROR) && (FS_Seek(MyHandle, MY_TARGET_BYTE, FS_FILE_BEGIN))));

        FS_Close(MyHandle);
    }
}

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_IO_FS_SetSeekHintEx
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_IO_FS_SetSeekHintEx(const WCHAR * FileName)
{
    #define MY_HINT_NUM (5)
    #define MY_TARGET_BYTE2 (9999)
    #define MY_HINT_BUFFER_SIZE (FS_SEEKHINT_BUFFER_SIZE_FOR_HINT_CNT(MY_HINT_NUM))

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval;
    FS_HANDLE MyHandle;
    __align(4) char MyHint[MY_HINT_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MyHandle = FS_Open(FileName, FS_OPEN_NO_DIR);
    if (MyHandle > FS_NO_ERROR)
    {
        reval = FS_SetSeekHintEx(MyHandle, MY_HINT_NUM, 0, (void *)MyHint, MY_HINT_BUFFER_SIZE);
        AVK_LOG_FUN(FS_SetSeekHintEx,((reval == FS_NO_ERROR) && (FS_Seek(MyHandle, MY_TARGET_BYTE2, FS_FILE_BEGIN))));

        FS_Close(MyHandle);
    }
}

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_IO_FS_SeekLargeFile
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_IO_FS_SeekLargeFile(const WCHAR * FileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int64 reval = 200;
    FS_HANDLE MyHandle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MyHandle=FS_Open(FileName,FS_READ_ONLY);

    if(MyHandle>FS_NO_ERROR)
    {
      reval = FS_SeekLargeFile(MyHandle,200,FS_FILE_BEGIN);
    }

    AVK_LOG_FUN(FS_SeekLargeFile,(200==reval));

    FS_Close(MyHandle);
}

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_Information_FS_GetFirstCluster
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_Information_FS_GetFirstCluster(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len;
    S32 result;
    UINT my_cluster;
    FS_HANDLE MyHandle;
    char data[]="Test FS_Write & FS_Read";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MyHandle=FS_Open((WCHAR *)L"Z:\\vs_sys_fs_file.txt", FS_READ_WRITE|FS_CREATE);
    if(MyHandle >= FS_NO_ERROR)
    {
      /*If file is empty, FS_GetFirstCluster will return FS_DATA_ERROR*/
      FS_Write(MyHandle,(U8 *)data,strlen(data),(UINT *)&len);

      result=FS_GetFirstCluster(MyHandle,&my_cluster);
      FS_Close(MyHandle);
      FS_Delete((WCHAR *)L"Z:\\vs_sys_fs_file.txt");
      AVK_LOG_FUN(FS_GetFirstCluster,(result >= FS_NO_ERROR));

    }
}

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_Information_FS_GetFileInfo
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_Information_FS_GetFileInfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval;
    FS_HANDLE MyHandle;
    FS_FileInfo MyFileInfo;
    WCHAR *MyFileName=(WCHAR *)L"Z:\\vs_sys_fs_Information_FS_GetFileInfo.txt";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set((void*)&MyFileInfo, 0, sizeof(MyFileInfo));

    MyHandle=FS_Open(MyFileName,FS_READ_WRITE| FS_CREATE);
    if (MyHandle < FS_NO_ERROR)
    {
        ASSERT(0);//Create file fail;
        return;
    }

    reval=FS_GetFileInfo(MyHandle,&MyFileInfo);
    reval=(*(MyFileInfo.FullName))-'Z';
    reval=strncmp((char*)(MyFileInfo.DirEntry->Extension),"TXT",3);
    AVK_LOG_FUN(FS_GetFileInfo,(FS_NO_ERROR==reval));

    FS_Close(MyHandle);
    FS_Delete(MyFileName);
}


/*****************************************************************************
 * FUNCTION
 *  vs_fsys_Information_FS_GetFileInfoEx
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_Information_FS_GetFileInfoEx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval;
    FS_HANDLE MyHandle;
    FS_FileInfo MyFileInfo;
    WCHAR *MyFileName=(WCHAR *)L"Z:\\vs_sys_fs_Information_FS_GetFileInfoEx.txt";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set((void*)&MyFileInfo, 0, sizeof(MyFileInfo));

    MyHandle=FS_Open(MyFileName,FS_READ_WRITE| FS_CREATE);
    if (MyHandle < FS_NO_ERROR)
    {
        ASSERT(0);//Create file fail;
        return;
    }

    reval=FS_GetFileInfoEx(MyHandle,&MyFileInfo,FS_FI_BASIC_INFO);
    //reval=FS_GetFileInfoEx(MyHandle,&MyFileInfo,FS_FI_ALLOCATED_SPACE);
    //reval=FS_GetFileInfoEx(MyHandle,&MyFileInfo,FS_FI_ALL);
    reval=(*(MyFileInfo.FullName))-'Z';
    reval=strncmp((char*)(MyFileInfo.DirEntry->Extension),"TXT",3);
    AVK_LOG_FUN(FS_GetFileInfoEx,(FS_NO_ERROR==reval));

    FS_Close(MyHandle);
    FS_Delete(MyFileName);
}


/*****************************************************************************
 * FUNCTION
 *  vs_fsys_Information_FS_GetFileSize
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_Information_FS_GetFileSize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval;
    S32 MyFileSize;
    FS_HANDLE MyHandle;
    WCHAR *MyFileName=(WCHAR *)L"Z:\\vs_sys_fs_Information_FS_GetFileSize.txt";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MyHandle=FS_Open(MyFileName,FS_READ_WRITE| FS_CREATE);
    if (MyHandle < FS_NO_ERROR)
    {
        ASSERT(0);//Create file fail;
        return;
    }

    reval=FS_GetFileSize(MyHandle,(UINT *)&MyFileSize);
    AVK_LOG_FUN(FS_GetFileSize,(FS_NO_ERROR==reval));

    FS_Close(MyHandle);
    FS_Delete(MyFileName);
}


/*****************************************************************************
 * FUNCTION
 *  vs_fsys_Information_FS_GetFilePosition
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_Information_FS_GetFilePosition(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval;
    S32 MyFilepPointerPosition;
    FS_HANDLE MyHandle;
    WCHAR *MyFileName=(WCHAR *)L"Z:\\vs_sys_fs_Information_FS_GetFilePosition.txt";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MyHandle=FS_Open(MyFileName,FS_READ_WRITE| FS_CREATE);
    if (MyHandle < FS_NO_ERROR)
    {
        ASSERT(0);//Create file fail;
        return;
    }

    reval=FS_GetFilePosition(MyHandle,(UINT *)&MyFilepPointerPosition);
    AVK_LOG_FUN(FS_GetFilePosition,(FS_NO_ERROR==reval));

    FS_Close(MyHandle);
    FS_Delete(MyFileName);
}

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_Information_FS_SetFileTime
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_Information_FS_SetFileTime(U16 Year1980,U16 Month,U16 Day,U16 Hour,U16 Minute,U16 Second2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval;
    FS_DOSDateTime MyFileDateTime;
    FS_FileInfo MyFileInfo;
    FS_HANDLE MyHandle;
    WCHAR *MyFileName=(WCHAR *)L"Z:\\vs_sys_fs_Information_FS_SetFileTime.txt";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MyFileDateTime.Year1980=Year1980; //1980+10
    MyFileDateTime.Month=Month;
    MyFileDateTime.Day=Day;
    MyFileDateTime.Hour=Hour;//6+8=14
    MyFileDateTime.Minute=Minute;
    MyFileDateTime.Second2=Second2;//Excede 30, have no handle


    MyHandle=FS_Open(MyFileName,FS_READ_WRITE| FS_CREATE);
    if (MyHandle < FS_NO_ERROR)
    {
        ASSERT(0);//Create file fail;
        return;
    }

    reval=FS_SetFileTime(MyHandle,&MyFileDateTime);
    reval=FS_GetFileInfo(MyHandle,&MyFileInfo);

    AVK_LOG_FUN(FS_SetFileTime,((FS_NO_ERROR==reval)
        &&(MyFileInfo.DirEntry->DateTime.Day==MyFileDateTime.Day)
        &&(MyFileInfo.DirEntry->DateTime.Hour==MyFileDateTime.Hour)
        &&(MyFileInfo.DirEntry->DateTime.Minute==MyFileDateTime.Minute)
        &&(MyFileInfo.DirEntry->DateTime.Second2==MyFileDateTime.Second2)
        &&(MyFileInfo.DirEntry->DateTime.Year1980==MyFileDateTime.Year1980)
        &&(MyFileInfo.DirEntry->DateTime.Month==MyFileDateTime.Month)
        ));

    FS_Close(MyHandle);
    FS_Delete(MyFileName);
}

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_Information_FS_GetAttributes
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_Information_FS_GetAttributes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval;
    FS_HANDLE MyHandle;
    WCHAR *MyFolderName=(WCHAR *)L"Z:\\vs_sys_fs_Information_FS_GetAttributes";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MyHandle=FS_CreateDir(MyFolderName);
    if (MyHandle < FS_NO_ERROR)
    {
        ASSERT(0);//Create file fail;
        return;
    }
    FS_Close(MyHandle);

    reval=FS_GetAttributes(MyFolderName);
    AVK_LOG_FUN(FS_GetAttributes,(FS_ATTR_DIR==reval));

    FS_XDelete(MyFolderName, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
    FS_RemoveDir(MyFolderName);
}

/*File Only*/

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_FileOnly_FS_SetAttributes
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_FileOnly_FS_SetAttributes(const WCHAR * FileName)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     S32 reval;
     FS_HANDLE MyHandle;

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     MyHandle=FS_Open(FileName,FS_READ_WRITE | FS_CREATE);
     if(MyHandle<FS_NO_ERROR)
     {
         ASSERT(0);//File create fail
     }

     reval=FS_SetAttributes(FileName,(BYTE)FS_READ_ONLY);
     FS_Close(MyHandle);
     AVK_LOG_FUN(FS_SetAttributes,(FS_NO_ERROR==reval));

     FS_Delete(FileName);

}
/*****************************************************************************
 * FUNCTION
 *  vs_fsys_FileOnly_FS_Delete
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_FileOnly_FS_Delete(const WCHAR * FileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     S32 reval;
     FS_HANDLE MyHandle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     MyHandle=FS_Open(FileName,FS_READ_WRITE | FS_CREATE);
     if(MyHandle<FS_NO_ERROR)
     {
         ASSERT(0);//File create fail
     }

     FS_Close(MyHandle);
     reval = FS_Delete(FileName);
     AVK_LOG_FUN(FS_Delete,(FS_NO_ERROR==reval));

}

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_FileOnly_FS_PseudoMerge
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_FileOnly_FS_PseudoMerge(const WCHAR * FileName1,const WCHAR * FileName2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     S32 reval = FS_NO_ERROR;
     S32 move1;
     S32 move2;
     WCHAR temp1[FS_MAX_PATH];
     WCHAR temp2[FS_MAX_PATH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     mmi_wcscpy(temp1,g_filesys_path);
     mmi_wcscat(temp1,(WCHAR *)L"\\1.mp3");
     move1=FS_Move(FileName1, temp1, FS_MOVE_OVERWRITE|FS_MOVE_COPY, NULL, NULL, 0);

     mmi_wcscpy(temp2,g_filesys_path);
     mmi_wcscat(temp2,(WCHAR *)L"\\2.mp3");
     move2=FS_Move(FileName2, temp2, FS_MOVE_OVERWRITE|FS_MOVE_COPY, NULL, NULL, 0);

     // In case of insufficient disk space,
     // only proceed when both files are successfully copied.
     if ((move1==FS_NO_ERROR) && (move2==FS_NO_ERROR))
     {
         reval=FS_PseudoMerge(temp1,temp2);
     }

     AVK_LOG_FUN(FS_PseudoMerge,(FS_NO_ERROR==reval));

     FS_Delete(temp1);

}

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_FileOnly_FS_CheckFile
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_FileOnly_FS_CheckFile(const WCHAR * FileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     S32 reval;
     FS_HANDLE MyHandle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     MyHandle=FS_Open(FileName,FS_READ_WRITE | FS_CREATE);
     if(MyHandle<FS_NO_ERROR)
     {
         ASSERT(0);//File create fail
     }
     FS_Close(MyHandle);
     reval = FS_CheckFile(FileName);
     AVK_LOG_FUN(FS_CheckFile,(FS_NO_ERROR==reval));

     FS_Delete(FileName);
}

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_FolderOnlyOptr_FS_SetCurrentDir_GetCurrentDir
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_FolderOnlyOptr_FS_SetCurrentDir_GetCurrentDir(const WCHAR *DirName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval;
    WCHAR GetDirName[FS_MAX_PATH];
    WCHAR OldDirName[FS_MAX_PATH];
    FS_HANDLE MyHandle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcscpy(OldDirName, DirName);
    FS_GetCurrentDirByDrive(OldDirName, FS_MAX_PATH);

    MyHandle=FS_Open(DirName,FS_READ_ONLY);
    if (MyHandle<FS_NO_ERROR)
    {
      FS_CreateDir(DirName);
    }
    FS_Close(MyHandle);

    reval=FS_SetCurrentDir(DirName);
    AVK_LOG_FUN(FS_SetCurrentDir,(FS_NO_ERROR==reval));


    reval=FS_GetCurrentDir(GetDirName,FS_MAX_PATH);
    //mmi_wcsncpy(GetDirName,L"Z",1);
    AVK_LOG_FUN(FS_GetCurrentDir,(FS_NO_ERROR==reval) );

    FS_SetCurrentDir(OldDirName);
    FS_XDelete(DirName, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
    FS_RemoveDir(DirName);
}

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_FolderOnlyOptr_FS_GetCurrentDirByDrive
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_FolderOnlyOptr_FS_GetCurrentDirByDrive(const WCHAR *DirName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval;
    WCHAR GetDirName[FS_MAX_PATH];
    WCHAR OldDirName[FS_MAX_PATH];
    FS_HANDLE MyHandle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FS_GetCurrentDir(OldDirName,FS_MAX_PATH);

    MyHandle=FS_Open(DirName,FS_READ_ONLY);
    if (MyHandle<FS_NO_ERROR)
    {
      FS_CreateDir(DirName);
    }
    FS_Close(MyHandle);

    reval=FS_SetCurrentDir(DirName);
    if (FS_NO_ERROR!=reval) {
      ASSERT(0);//Set current dir fail
    }

    memset(GetDirName, 0, FS_MAX_PATH);
    mmi_wcscpy(GetDirName, DirName);
    reval=FS_GetCurrentDirByDrive(GetDirName,FS_MAX_PATH);
    //mmi_wcsncpy(GetDirName,L"Z",1);
    AVK_LOG_FUN(FS_GetCurrentDirByDrive,((FS_NO_ERROR==reval)&&(0==mmi_wcsicmp(GetDirName+1, DirName+1))));

    FS_SetCurrentDir(OldDirName);
}


/*****************************************************************************
 * FUNCTION
 *  vs_fsys_FolderOnlyOptr_FS_CreateDir_RemoveDir
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_FolderOnlyOptr_FS_CreateDir_RemoveDir(const WCHAR *DirName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval;
    FS_HANDLE MyHandle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MyHandle=FS_Open(DirName,FS_READ_ONLY);
    if (MyHandle >= FS_NO_ERROR)
    {
       FS_Close(MyHandle);
       FS_XDelete(DirName, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
       FS_RemoveDir(DirName);
    }

    reval=FS_CreateDir(DirName);
    AVK_LOG_FUN(FS_CreateDir,(FS_NO_ERROR==reval));
    if (FS_NO_ERROR!=reval)
    {
      return;
    }

    /*If the folder is empty, FS_XDelete will delete the folder*/
    //FS_XDelete(DirName, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
    reval=FS_RemoveDir(DirName);
    AVK_LOG_FUN(FS_RemoveDir,(FS_NO_ERROR==reval));

}

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_FolderOnlyOptr_FS_GetFolderSize
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_FolderOnlyOptr_FS_GetFolderSize(const WCHAR *DirName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 MySize_Count;
    S32 MySize_Byte;
    FS_HANDLE MyHandle;
    UINT len;
    WCHAR Tempfile[128];
    char data[]="Test FS_Write & FS_Read";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MyHandle=FS_Open(DirName,FS_READ_ONLY);
    if (MyHandle<FS_NO_ERROR)
    {
      FS_CreateDir(DirName);
    }
    FS_Close(MyHandle);

    mmi_wcscpy(Tempfile,DirName);
    mmi_wcscat((WCHAR *)Tempfile,(WCHAR *)L"\\vs_sys_fs_file.txt");
    MyHandle=FS_Open(Tempfile, FS_READ_WRITE|FS_CREATE);
    if(MyHandle >= FS_NO_ERROR)
    {
      /*If file is empty, FS_GetFirstCluster will return FS_DATA_ERROR*/
      FS_Write(MyHandle,(U8 *)data,strlen(data),&len);
      FS_Close(MyHandle);
    }

    MySize_Count=FS_GetFolderSize(DirName,FS_COUNT_IN_CLUSTER,NULL,0);
    MySize_Byte=FS_GetFolderSize(DirName,FS_COUNT_IN_BYTE,NULL,0);
    AVK_LOG_FUN(FS_GetFolderSize,((MySize_Count>=1)&&(MySize_Byte>=0)));

    FS_XDelete(DirName, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
    FS_RemoveDir(DirName);
}


/*File and Folder Operations*/

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_FileAndFolder_FS_Extend_Truncate
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_FileAndFolder_FS_Extend_Truncate(const WCHAR * FileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval;
    S32 len;
    S32 ex_size=8;
    char data[]="Test FS_Write & FS_Read";
    FS_HANDLE MyHandle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MyHandle=FS_Open(FileName,FS_READ_WRITE | FS_CREATE);
    if(MyHandle<FS_NO_ERROR)
    {
        ASSERT(0);//File create fail
    }

    reval = FS_Extend(MyHandle, ex_size);
    FS_Seek(MyHandle,ex_size,FS_FILE_BEGIN);
    FS_Write(MyHandle,(U8 *)data,strlen(data),(UINT *)&len );
    FS_Seek(MyHandle,ex_size,FS_FILE_BEGIN);
    memset(data, 0 , sizeof(data));
    FS_Read(MyHandle,data,13,(UINT *)&len);
    AVK_LOG_FUN(FS_Extend,((reval==FS_NO_ERROR)&&(13==len)&&(0==strcmp(data,"Test FS_Write"))));

    FS_Seek(MyHandle,12,FS_FILE_BEGIN);
    reval = FS_Truncate(MyHandle);
    FS_Seek(MyHandle,-4,FS_FILE_END);

    memset(data, 0 , sizeof(data));
    FS_Read(MyHandle,data,4,(UINT *)&len);
    AVK_LOG_FUN(FS_Truncate,((reval==FS_NO_ERROR)&&(4==len)&&(0==strcmp(data,"Test"))));

    FS_Close(MyHandle);
    FS_Delete(FileName);
}

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_FileAndFolder_FS_MakeFileName
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_FileAndFolder_FS_MakeFileName(const WCHAR * FileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval;
    FS_HANDLE MyHandle;
    WCHAR * part_filename;
    WCHAR re_filename[FS_MAX_PATH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MyHandle=FS_Open(FileName,FS_READ_WRITE | FS_CREATE);
    if(MyHandle<FS_NO_ERROR)
    {
        ASSERT(0);//File create fail
    }

    part_filename=mmi_wcsrchr(FileName,L'\\');
    reval = FS_MakeFileName(MyHandle, 0,re_filename,FS_MAX_PATH);
    AVK_LOG_FUN(FS_MakeFileName,((reval==FS_NO_ERROR)&&(0==mmi_wcsnicmp(re_filename,(part_filename+1),6))));

    reval = FS_MakeFileName(MyHandle, FS_LONGNAME_ATTR,re_filename,FS_MAX_PATH);
    AVK_LOG_FUN(FS_MakeFileName,((reval==FS_NO_ERROR)&&(0== mmi_wcscmp(re_filename,(part_filename+1)))));

    FS_Close(MyHandle);
    FS_Delete(FileName);

}

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_FileAndFolder_FS_Rename
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_FileAndFolder_FS_Rename(const WCHAR * FileName, const WCHAR *NewFileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval;
    FS_HANDLE MyHandle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MyHandle=FS_Open(FileName,FS_READ_WRITE | FS_CREATE);
    if(MyHandle<FS_NO_ERROR)
    {
        ASSERT(0);//File create fail
    }
    FS_Close(MyHandle);

    reval = FS_Rename(FileName, NewFileName);
    MyHandle=FS_Open(NewFileName,FS_READ_ONLY);
    AVK_LOG_FUN(FS_Rename,((reval==FS_NO_ERROR)&&(MyHandle>=FS_NO_ERROR)));

    FS_Close(MyHandle);
    FS_Delete(NewFileName);

}

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_FileAndFolder_FS_Move
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_FileAndFolder_FS_Move(const WCHAR * FileName, const WCHAR * FolderName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval;
    FS_HANDLE MyHandle;
    WCHAR NewFileName[FS_MAX_PATH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MyHandle=FS_Open(FileName,FS_READ_WRITE | FS_CREATE);
    if(MyHandle<FS_NO_ERROR)
    {
        ASSERT(0);//File create fail
    }
    FS_Close(MyHandle);

    mmi_wcscpy(NewFileName,FolderName);
    mmi_wcscat(NewFileName,(WCHAR *)L"\\vs_fsys_FileAndFolder_FS_Move.mp3");
    reval = FS_Move(FileName,NewFileName,FS_MOVE_OVERWRITE|FS_MOVE_COPY, NULL, NULL, 0);

    MyHandle=FS_Open(NewFileName,FS_READ_ONLY);
    AVK_LOG_FUN(FS_Move,((reval==FS_NO_ERROR)&&(MyHandle>=FS_NO_ERROR)));

    FS_Close(MyHandle);
    FS_Delete(FileName);
    FS_Delete(NewFileName);

}

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_FileAndFolder_FS_Count
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_FileAndFolder_FS_Count(const WCHAR * FolderName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reval = FS_Count(FolderName, FS_FILE_TYPE|FS_DIR_TYPE|FS_RECURSIVE_TYPE, NULL, 0);
    AVK_LOG_FUN(FS_Count,(reval>=0));
}


/*****************************************************************************
 * FUNCTION
 *  vs_fsys_FileAndFolder_FS_XDelete
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_FileAndFolder_FS_XDelete(const WCHAR * FolderName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval;
    FS_HANDLE MyHandle;
    WCHAR FileName[FS_MAX_PATH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MyHandle=FS_Open(FolderName,FS_READ_ONLY);
    if(MyHandle<FS_NO_ERROR)
    {
        FS_CreateDir(FolderName);
    }
    FS_Close(MyHandle);


    mmi_wcscpy(FileName,FolderName);
    mmi_wcscat(FileName,(WCHAR *)L"\\vs_fsys_FileAndFolder_FS_XDelete.txt");

    MyHandle=FS_Open(FileName,FS_READ_WRITE | FS_CREATE);
    if(MyHandle<FS_NO_ERROR)
    {
        ASSERT(0);//File create fail
    }
    FS_Close(MyHandle);

    reval=FS_XDelete(FolderName, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
    MyHandle=FS_Open(FileName,FS_READ_ONLY);
    AVK_LOG_FUN(FS_XDelete,((reval>=FS_NO_ERROR)&&(MyHandle<FS_NO_ERROR)));

    if (MyHandle>=FS_NO_ERROR)
    {
       FS_Close(MyHandle);
       FS_Delete(FileName);
    }

}

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_FileAndFolder_FS_XDeleteEx_cb_hdlr
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
static int vs_fsys_FileAndFolder_FS_XDeleteEx_cb_hdlr(int Action, UINT Total, UINT Completed, UINT Info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(Completed > 3)
    {
        reval = FS_Abort(FS_ABORT_XDELETE);
        AVK_LOG_FUN(FS_Abort,(reval >= FS_NO_ERROR));

    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vs_fsys_FileAndFolder_FS_XDeleteEx
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_FileAndFolder_FS_XDeleteEx(const WCHAR * FolderName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval, i=0;
    FS_HANDLE MyHandle;
    WCHAR FileName[FS_MAX_PATH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MyHandle=FS_Open(FolderName,FS_READ_ONLY);
    if(MyHandle<FS_NO_ERROR)
    {
        FS_CreateDir(FolderName);
    }
    FS_Close(MyHandle);

    // Run Time to create files
    for (i=0;i<30;i++)
     {
          if (0==(i%3))
          {
             kal_wsprintf(FileName, "%w\\%d.jpg",FolderName,i);
          } else if (1==(i%3))
          {
             kal_wsprintf(FileName, "%w\\%d.gif",FolderName,i);
          } else
          {
             kal_wsprintf(FileName, "%w\\%d.bmp",FolderName,i);
          }

    MyHandle=FS_Open(FileName,FS_READ_WRITE | FS_CREATE);
    if(MyHandle<FS_NO_ERROR)
    {
        ASSERT(0);//File create fail
    }
    FS_Close(MyHandle);
     }

    reval=FS_XDeleteEx(FolderName, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE,
                       vs_fsys_FileAndFolder_FS_XDeleteEx_cb_hdlr, NULL, 0);

    AVK_LOG_FUN(FS_XDeleteEx,(reval == FS_ABORTED_ERROR));

    FS_XDelete(FolderName, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
    FS_RemoveDir(FolderName);
}

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_FileAndFolder_FS_CompactDir
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_FileAndFolder_FS_CompactDir(const WCHAR * FolderName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval, i=0;
    FS_HANDLE MyHandle;
    WCHAR FileName[FS_MAX_PATH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MyHandle=FS_Open(FolderName,FS_READ_ONLY);
    if(MyHandle<FS_NO_ERROR)
    {
        FS_CreateDir(FolderName);
    }
    FS_Close(MyHandle);

    // Run Time to create files
    for (i=0;i<30;i++)
     {
          if (0==(i%3))
          {
             kal_wsprintf(FileName, "%w\\%d.jpg",FolderName,i);
          } else if (1==(i%3))
          {
             kal_wsprintf(FileName, "%w\\%d.gif",FolderName,i);
          } else
          {
             kal_wsprintf(FileName, "%w\\%d.bmp",FolderName,i);
          }

          MyHandle=FS_Open(FileName,FS_READ_WRITE | FS_CREATE);
          if(MyHandle<FS_NO_ERROR)
          {
            ASSERT(0);//File create fail
          }
          FS_Close(MyHandle);
     }

    for (i=0;i<30;i++)
     {
          if (0==(i%3))
          {
             kal_wsprintf(FileName, "%w\\%d.jpg",FolderName,i);
             FS_Delete(FileName);
          }
     }

    reval = FS_CompactDir(FolderName, 0x01); //Flag:RTF_CMPCT_READ_ONLY 0x000001
    AVK_LOG_FUN(FS_CompactDir,(reval >= FS_NO_ERROR));

    FS_XDelete(FolderName, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
    FS_RemoveDir(FolderName);

}
/*Find File*/

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_FindFile_FS_FindFirst_FindClose
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_FindFile_FS_FindFirst_FindClose(const WCHAR * FolderName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval;
    FS_HANDLE MyHandle;
    WCHAR FileName[FS_MAX_PATH];
    WCHAR re_FileName[FS_MAX_PATH];
    WCHAR filename_expr[FS_MAX_PATH];
    FS_DOSDirEntry file_info;
    WCHAR * part_filename;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MyHandle=FS_Open(FolderName,FS_READ_ONLY);
    if(MyHandle<FS_NO_ERROR)
    {
        FS_CreateDir(FolderName);
    }
    FS_Close(MyHandle);


    mmi_wcscpy(FileName,FolderName);
    mmi_wcscat(FileName,(WCHAR *)L"\\vs_fsys_FindFile_FS_FindFirst_FindClose.txt");

    MyHandle=FS_Open(FileName,FS_READ_WRITE | FS_CREATE);
    if(MyHandle<FS_NO_ERROR)
    {
        ASSERT(0);//File create fail
    }
    FS_Close(MyHandle);

    kal_wsprintf(filename_expr, "%w\\*.txt", FolderName);
    part_filename=mmi_wcsrchr(FileName,L'\\');
    reval = FS_FindFirst(filename_expr, 0, 0, &file_info, re_FileName, FS_MAX_PATH);
    AVK_LOG_FUN(FS_FindFirst,((reval>FS_NO_ERROR)&&(0==mmi_wcsicmp(re_FileName,(part_filename+1)))));

    reval = FS_FindClose(reval);
    AVK_LOG_FUN(FS_FindClose,(reval==FS_NO_ERROR));

    FS_Delete(FileName);
    FS_XDelete(FolderName, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
    FS_RemoveDir(FolderName);
}


/*****************************************************************************
 * FUNCTION
 *  vs_fsys_FindFile_FS_FindNext
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_FindFile_FS_FindNext(const WCHAR * FolderName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval, reval2;
    S32 i;
    FS_HANDLE MyHandle;
    WCHAR FileName[FS_MAX_PATH];
    WCHAR re_FileName[FS_MAX_PATH];
    WCHAR filename_expr[FS_MAX_PATH];
    FS_DOSDirEntry file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MyHandle=FS_Open(FolderName,FS_READ_ONLY);
    if(MyHandle<FS_NO_ERROR)
    {
        FS_CreateDir(FolderName);
    }
    FS_Close(MyHandle);

    for (i=0;i<10;i++)
    {
     kal_wsprintf(FileName, "%w\\%d.txt",FolderName,i);
     MyHandle=FS_Open(FileName,FS_READ_WRITE | FS_CREATE);
     if(MyHandle<FS_NO_ERROR)
     {
       ASSERT(0);//File create fail
     }
     FS_Close(MyHandle);
    }

    kal_wsprintf(filename_expr, "%w\\*.txt", FolderName);

    reval = FS_FindFirst(filename_expr, 0, 0, &file_info, re_FileName, FS_MAX_PATH);
    reval2 = FS_FindNext(reval, &file_info, re_FileName, FS_MAX_PATH);
    AVK_LOG_FUN(FS_FindNext,(reval2 == FS_NO_ERROR));

    FS_FindClose(reval);
    FS_FindClose(reval2);
    FS_XDelete(FolderName, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
    FS_RemoveDir(FolderName);
}

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_FindFile_FS_FindFirstN_FindNextN
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_FindFile_FS_FindFirstN_FindNextN(const WCHAR * FolderName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    FS_HANDLE MyHandle, MyHandle2;
    WCHAR FileName[FS_MAX_PATH];
    WCHAR re_FileName[FS_MAX_PATH];
    WCHAR filename_expr[FS_MAX_PATH];
    FS_DOSDirEntry file_info;
    FS_Pattern_Struct  fs_pattern_array[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MyHandle=FS_Open(FolderName,FS_READ_ONLY);
    if(MyHandle<FS_NO_ERROR)
    {
        FS_CreateDir(FolderName);
    }
    FS_Close(MyHandle);

    for (i=0;i<15;i++)
    {
         if (0==(i%3))
         {
            kal_wsprintf(FileName, "%w\\%d.txt",FolderName,i);
         } else if (1==(i%3))
         {
            kal_wsprintf(FileName, "%w\\%d.mp3",FolderName,i);
         } else
         {
            kal_wsprintf(FileName, "%w\\%d.mid",FolderName,i);
         }

         MyHandle=FS_Open(FileName,FS_READ_WRITE | FS_CREATE);
         if(MyHandle<FS_NO_ERROR)
         {
           ASSERT(0);//File create fail
         }
         FS_Close(MyHandle);
    }

    kal_wsprintf(filename_expr, "%w\\*.*", FolderName);
    kal_wstrcpy(fs_pattern_array[0].Pattern, (WCHAR *)L"*.mp3");
    kal_wstrcpy(fs_pattern_array[1].Pattern, (WCHAR *)L"*.mid");

    /*int FS_FindFirstN(const WCHAR *NamePattern, FS_Pattern_Struct *PatternArray, UINT PatternNum,
                  BYTE ArrayMask, BYTE Attr, BYTE AttrMask, FS_DOSDirEntry *FileInfo,
                  WCHAR *FileName, UINT MaxLength, UINT EntryIndex, UINT Flag)
          int FS_FindNextN(FS_HANDLE Handle, FS_Pattern_Struct * PatternArray, UINT PatternNum,
                  BYTE ArrayMask, FS_DOSDirEntry *FileInfo, WCHAR *FileName, UINT MaxLength, UINT Flag)

       */

    MyHandle = FS_FindFirstN(filename_expr, fs_pattern_array, 2, 0, 0, 0,
        &file_info, re_FileName, FS_MAX_PATH, 2, FS_FIND_DEFAULT);
    AVK_LOG_FUN(FS_FindFirstN,(MyHandle>FS_NO_ERROR));

    MyHandle2 = FS_FindNextN(MyHandle, fs_pattern_array, 2, 0,
        &file_info, re_FileName, FS_MAX_PATH, FS_FIND_DEFAULT);
    AVK_LOG_FUN(FS_FindNextN,(FS_NO_ERROR == MyHandle2));

    FS_FindClose(MyHandle);
    FS_FindClose(MyHandle2);
    FS_XDelete(FolderName, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
    FS_RemoveDir(FolderName);
}


/*****************************************************************************
 * FUNCTION
 *  vs_fsys_FindFile_FS_ListOpen_ListNext_ListClose
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_FindFile_FS_ListOpen_ListNext_ListClose(const WCHAR * FolderName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE MyHandle;
    S32 reval, i=0;
    WCHAR wfn[128]={0};
    fs_list_param_struct param={0};
    WCHAR FileName[FS_MAX_PATH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MyHandle=FS_Open(FolderName,FS_READ_ONLY);
    if(MyHandle<FS_NO_ERROR)
    {
        FS_CreateDir(FolderName);
    }
    FS_Close(MyHandle);
    // Run Time to create files
    for (i=0;i<30;i++)
     {
          if (0==(i%3))
          {
             kal_wsprintf(FileName, "%w\\%d.jpg",FolderName,i);
          } else if (1==(i%3))
          {
             kal_wsprintf(FileName, "%w\\%d.gif",FolderName,i);
          } else
          {
             kal_wsprintf(FileName, "%w\\%d.bmp",FolderName,i);
          }

          MyHandle=FS_Open(FileName,FS_READ_WRITE | FS_CREATE);
          if(MyHandle<FS_NO_ERROR)
          {
            ASSERT(0);//File create fail
          }
          FS_Close(MyHandle);
     }

    param.path=(WCHAR *)get_ctrl_buffer(FS_MAX_PATH);
    kal_wsprintf(param.path,"%w\\*.*",FolderName);

    param.index=0;
    param.buff_size=FS_LIST_SIZE(20);
    param.buff=(fs_list_param_struct *)get_ctrl_buffer(param.buff_size);

    reval=FS_ListOpen(&param, &MyHandle);
    AVK_LOG_FUN(FS_ListOpen,(reval>=FS_NO_ERROR));

    reval=FS_ListNext(MyHandle, NULL, param.path, wfn, 128, 0);
    AVK_LOG_FUN(FS_ListNext,(reval>=FS_NO_ERROR));

    reval=FS_ListClose(MyHandle);
    AVK_LOG_FUN(FS_ListClose,(reval>=FS_NO_ERROR));

    free_ctrl_buffer(param.buff);
    free_ctrl_buffer(param.path);
    FS_XDelete(FolderName, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
    FS_RemoveDir(FolderName);
}

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_FindFile_FS_SortCompareFileName_Type
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_FindFile_FS_SortCompareFileName_Type(const WCHAR * FolderName)
{
#ifdef __FS_SORT_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval;
    FS_HANDLE MyHandle;
    WCHAR FileName1[FS_MAX_PATH];
    WCHAR FileName2[FS_MAX_PATH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MyHandle=FS_Open(FolderName,FS_READ_ONLY);
     if(MyHandle<FS_NO_ERROR)
     {
         FS_CreateDir(FolderName);
     }
     FS_Close(MyHandle);

     // Run Time to create files
     kal_wsprintf(FileName1, "%w\\a.jpg",FolderName);
     MyHandle=FS_Open(FileName1,FS_READ_WRITE | FS_CREATE);
     if(MyHandle<FS_NO_ERROR)
     {
       ASSERT(0);//File create fail
     }
     FS_Close(MyHandle);

     kal_wsprintf(FileName2, "%w\\b.gif",FolderName);
     MyHandle=FS_Open(FileName2,FS_READ_WRITE | FS_CREATE);
     if(MyHandle<FS_NO_ERROR)
     {
       ASSERT(0);//File create fail
     }
     FS_Close(MyHandle);

     reval = FS_SortCompareFileName(FileName1, FileName2);
     AVK_LOG_FUN(FS_SortCompareFileName,(reval<0));

     reval = FS_SortCompareFileType(FileName1, FileName2);
     AVK_LOG_FUN(FS_SortCompareFileType,(reval>0));

     FS_XDelete(FolderName, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
     FS_RemoveDir(FolderName);
     
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vs_fsys_FindFile_FS_XFindReset_XFindStart_XFindClose
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_FindFile_FS_XFindReset_XFindStart_XFindClose(const WCHAR * FolderName)
{
#ifdef __FS_SORT_SUPPORT__

   #define FS_SORT_BUFFWORKING_SIZE FS_SORT_WORKING_BUFFER_SIZE_FOR_FILES(30)
   #define FS_SORT_BUFFSORTING_SIZE FS_SORT_SORTING_BUFFER_SIZE_FOR_FILES(30)

    /*
        Param.ArrayMask = params->ArrayMask;
    Param.AttrMask = params->AttrMask;
    Param.Flag = params->Flag;
    Param.Timeout = 0;
    Param.Position = &sort_handle;
    Param.ProgressCallback = fmt_adv_sort_progress_callback;
    Param.ProgressCallbackParam = (void*)&sort_userdata;
    Param.CompareFunc = (SortingCompareFunc)params->sort_compare_func;
    Param.SortingBuffer = (BYTE*)params->sort_buffer;
    Param.SortingBufferSize = params->sort_buffer_size;
    Param.WorkingBuffer = (BYTE*)params->work_buffer;
    Param.WorkingBufferSize = params->work_buffer_size;
    reval=FS_XFindReset(L"E:\\*",TestArray,MY_MEMBER, FS_ATTR_DIR,0,FS_DIR_TYPE|FS_FILE_TYPE|FS_SORT_NAME,FS_INFINITE,&Pos);
    */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval, index=0, i=0;
    FS_SortingParam Param={0};
    FS_HANDLE MyHandle;
    UINT Pos;
    FS_DOSDirEntry FileInfo;
    WCHAR FileName[FS_MAX_PATH];
    FS_Pattern_Struct TestArray[2];
    kal_char pbuffsort[FS_SORT_BUFFSORTING_SIZE] = {0};
    kal_char pbuffwork[FS_SORT_BUFFWORKING_SIZE] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MyHandle=FS_Open(FolderName,FS_READ_ONLY);
    if(MyHandle<FS_NO_ERROR)
    {
        FS_CreateDir(FolderName);
    }
    FS_Close(MyHandle);

    // Run Time to create files
    for (i=0;i<30;i++)
     {
          if (0==(i%3))
          {
             kal_wsprintf(FileName, "%w\\%d.jpg",FolderName,i);
          } else if (1==(i%3))
          {
             kal_wsprintf(FileName, "%w\\%d.gif",FolderName,i);
          } else
          {
             kal_wsprintf(FileName, "%w\\%d.bmp",FolderName,i);
          }

          MyHandle=FS_Open(FileName,FS_READ_WRITE | FS_CREATE);
          if(MyHandle<FS_NO_ERROR)
          {
            ASSERT(0);//File create fail
          }
          FS_Close(MyHandle);
     }

     kal_wstrcpy(TestArray[0].Pattern,(WCHAR *)L"*.mp3");
     kal_wstrcpy(TestArray[1].Pattern,(WCHAR *)L"*.gif");

     Param.Pattern=(WCHAR *)get_ctrl_buffer(FS_MAX_PATH);
     kal_wsprintf(Param.Pattern,"%w\\*",FolderName);
     Param.PatternArray=TestArray;
     Param.PatternNum=2;
     Param.ArrayMask=FS_ATTR_DIR;
     Param.AttrMask=0;
     Param.Flag=FS_DIR_TYPE|FS_FILE_TYPE|FS_SORT_NAME;
     Param.Timeout=FS_INFINITE;
     Param.Position=&Pos;
     Param.SortingBuffer = (BYTE *)pbuffsort;
     Param.WorkingBuffer = (BYTE *)pbuffwork;
     Param.SortingBufferSize = FS_SORT_BUFFSORTING_SIZE;
     Param.WorkingBufferSize = FS_SORT_BUFFWORKING_SIZE;

     /*int FS_XFindStart(const WCHAR *Pattern, FS_DOSDirEntry *FileInfo, WCHAR *FileName,
                       UINT MaxLength, UINT Index, UINT *Position, UINT Flag)*/

    reval = FS_XFindReset(&Param);
    AVK_LOG_FUN(FS_XFindReset,(reval>0));
    if (reval>0)
    {
        while(index<reval)
            index=FS_XFindStart(Param.Pattern,&FileInfo, FileName, FS_MAX_PATH, index, &Pos, FS_FIND_DEFAULT);

        /*Check FS_XFindStart*/
        AVK_LOG_FUN(FS_XFindStart,(index == reval));

        /*Check FS_XFindClose*/
        reval = FS_XFindClose(&Pos);
        AVK_LOG_FUN(FS_XFindClose,(FS_NO_ERROR == reval));
    }

    FS_XDelete(FolderName, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
    FS_RemoveDir(FolderName);
    
#endif    
}

/*Drive Management*/

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_DrvMgr_FS_GetDrive
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_DrvMgr_FS_GetDrive(UINT Type, UINT Serial, UINT AltMask, kal_int32 Result, vs_fs_compare_enum cmpindex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 drvLetter;
    kal_bool v_return=KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drvLetter=FS_GetDrive(Type,Serial,AltMask);

    switch (cmpindex)
       {
           case VS_SYS_FS_EQUAL:
               if(drvLetter==Result)
               {
                 v_return=KAL_TRUE;
               }
               break;
           case VS_SYS_FS_GREATER:
               if(drvLetter>Result)
               {
                 v_return=KAL_TRUE;
               }
               break;
           case VS_SYS_FS_LESS:
               if(drvLetter<Result)
               {
                 v_return=KAL_TRUE;
               }
               break;
       }

    AVK_LOG_FUN(FS_GetDrive,v_return);

}

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_DrvMgr_FS_GeneralFormat
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_DrvMgr_FS_GeneralFormat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 drvLetter;
    WCHAR K_filename[50];
    U8 reval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drvLetter=FS_GetDrive(FS_DRIVE_V_NORMAL,1, FS_NO_ALT_DRIVE);
    if(drvLetter>0)
    {
       kal_wsprintf(K_filename,"\\\\.\\%c:",drvLetter);
       reval=FS_GeneralFormat(K_filename,FS_FORMAT_HIGH,NULL);
       kal_prompt_trace(MOD_MMI,"FS_GeneralFormat Return Value: %d\n", reval);

       AVK_LOG_FUN(FS_GeneralFormat,((12 == reval) || (16 == reval) || (32 == reval)));
    } else {
       //Print error code;
    }
}

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_DrvMgr_FS_GetClusterSize
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_DrvMgr_FS_GetClusterSize(UINT Diskletter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reval=FS_GetClusterSize(Diskletter);

    AVK_LOG_FUN(FS_GetClusterSize,(reval>0));

}


/*****************************************************************************
 * FUNCTION
 *  vs_fsys_DrvMgr_FS_QmGetFree
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_DrvMgr_FS_QmGetFree(void)
{
#ifdef __FS_QM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 my_free_space[8];

    memset(my_free_space,0,8);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    my_free_space[0]=FS_QmGetFree((BYTE *)"Z:\\@mms\\");
    kal_prompt_trace(MOD_MMI, "FS_QmGetFree(@mms) Size: %d", my_free_space);

    my_free_space[1]=FS_QmGetFree((BYTE *)"Z:\\@Audio\\");
    kal_prompt_trace(MOD_MMI, "FS_QmGetFree(@mms) Size: %d", my_free_space);

    my_free_space[2]=FS_QmGetFree((BYTE *)"Z:\\@wap\\");
    kal_prompt_trace(MOD_MMI, "FS_QmGetFree(@wap) Size: %d", my_free_space);

    my_free_space[3]=FS_QmGetFree((BYTE *)"Z:\\@bgsr\\");
    kal_prompt_trace(MOD_MMI, "FS_QmGetFree(@bgsr) Size: %d", my_free_space);


    #ifdef __EMAIL__
    my_free_space[4]=FS_QmGetFree((BYTE *)"C:\\@email_sys\\");
    kal_prompt_trace(MOD_MMI, "FS_QmGetFree(@email_sys) Size: %d", my_free_space);
    #endif

    AVK_LOG_FUN(FS_QmGetFree,(my_free_space[0]>0)|(my_free_space[1]>0)|(my_free_space[2]>0)|(my_free_space[3]>0)|(my_free_space[4]>0));

#endif        
}


/*****************************************************************************
 * FUNCTION
 *  vs_fsys_DrvMgr_FS_GetPartitionInfo
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_DrvMgr_FS_GetPartitionInfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_PartitionRecord PartitionInfo;
    S32 reval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&PartitionInfo, 0, sizeof(PartitionInfo));

    reval=FS_GetPartitionInfo((WCHAR *)L"Z:\\", &PartitionInfo);
    AVK_LOG_FUN(FS_GetPartitionInfo,(FS_NO_ERROR==reval));
}


/*****************************************************************************
 * FUNCTION
 *  vs_fsys_DrvMgr_FS_CommitAll
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_DrvMgr_FS_CommitAll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reval=FS_CommitAll((WCHAR *)L"Z:\\");

    AVK_LOG_FUN(FS_CommitAll,(FS_NO_ERROR==reval));
}


/*****************************************************************************
 * FUNCTION
 *  vs_fsys_DrvMgr_FS_MappingDrive
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_DrvMgr_FS_MappingDrive(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //FS_MappingDrive(FSSIM_SYSTEM_DRIVE, FSSIM_REMAP_SYSTEM_DRIVE);
    S32 reval=FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    reval=FS_MappingDrive(L'C', L'Z');

    int driveletter = FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_NO_ALT_DRIVE);

    if(driveletter > 0)
    {
        reval=FS_MappingDrive(driveletter, L'Z');
    }

    AVK_LOG_FUN(FS_MappingDrive,(FS_NO_ERROR==reval));

}

/*Power Lost Detection and Recovery*/

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_PwrLost_FS_Set_Check_ClearDiskFlag
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_PwrLost_FS_Set_Check_ClearDiskFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reval=FS_SetDiskFlag();
    AVK_LOG_FUN(FS_SetDiskFlag,(FS_NO_ERROR==reval));

    reval=FS_CheckDiskFlag();
    AVK_LOG_FUN(FS_CheckDiskFlag,(0==reval)|(1==reval));


    reval=FS_ClearDiskFlag();
    AVK_LOG_FUN(FS_ClearDiskFlag,(FS_NO_ERROR==reval));

}


/*****************************************************************************
 * FUNCTION
 *  vs_fsys_PwrLost_FS_CheckDrive
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_PwrLost_FS_CheckDrive(void)
{
    #ifdef __FS_CHECKDRIVE_SUPPORT__
    #define MAX_PWRLOST_SIZE 2048
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval;
    kal_uint8 *buffer;
    kal_uint32 DriveIdx = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_NO_ALT_DRIVE);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    buffer = (kal_uint8 *)get_ctrl_buffer(MAX_PWRLOST_SIZE);//OslMalloc(size),OslMfree(ptr)
    reval = FS_CheckDrive(DriveIdx, buffer, MAX_PWRLOST_SIZE);

    AVK_LOG_FUN(FS_CheckDrive,(reval >= FS_NO_ERROR || FS_ACCESS_DENIED == reval ));
    kal_prompt_trace(MOD_MMI, "AVK Test: %d!",reval);

    free_ctrl_buffer(buffer);
    #else
       AVK_LOG_FUN_UNSUPPORTED(FS_CheckDrive);
       kal_prompt_trace(MOD_MMI, "AVK Test: FS_CheckDrive Do not support!");
    #endif
}

/*Disk Management*/
/*****************************************************************************
 * FUNCTION
 *  vs_fsys_DiskMgr_FS_GetDiskInfo
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_DiskMgr_FS_GetDiskInfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_DiskInfo info;
    kal_uint8 path[10];
    int phone;
    S32 reval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phone = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
    memset(path, 0, 10);

    if (phone >= FS_NO_ERROR)    {
        kal_wsprintf((WCHAR*) path, "%c:\\", phone);
        reval=FS_GetDiskInfo((WCHAR*) path, &info, FS_DI_FREE_SPACE);
        AVK_LOG_FUN(FS_GetDiskInfo,(reval >= FS_NO_ERROR));
    }
}


/*****************************************************************************
 * FUNCTION
 *  vs_fsys_DiskMgr_FS_GetDevType
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_DiskMgr_FS_GetDevType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 path[10];
    int phone;
    S32 reval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phone = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
    memset(path, 0, 10);

    if (phone >= FS_NO_ERROR)    {
        kal_wsprintf((WCHAR*) path, "%c:\\", phone);
        reval=FS_GetDevType((WCHAR*) path);
        AVK_LOG_FUN(FS_GetDevType,((FS_DEVICE_TYPE_NOR==reval)||(FS_DEVICE_TYPE_NAND==reval)));
    }
}


/*****************************************************************************
 * FUNCTION
 *  vs_fsys_DiskMgr_FS_GetDevStatus
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_DiskMgr_FS_GetDevStatus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //kal_uint8 path[10];
    int phone;
    S32 reval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phone = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
    //memset(path, 0, 10);

    if (phone >= FS_NO_ERROR)    {
        //kal_printf((WCHAR*) path, "%c:\\", phone);
        reval=FS_GetDevStatus((kal_int32)phone,FS_FEATURE_STATE_ENUM);

        AVK_LOG_FUN(FS_GetDevStatus,(reval>=FS_NO_ERROR));
    }
}


/*****************************************************************************
 * FUNCTION
 *  vs_fsys_DiskMgr_FS_GetDevPartitions
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_DiskMgr_FS_GetDevPartitions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AVK_LOG((FS_GetDevPartitions(FS_DEVICE_TYPE_NOR) >= 1)||(FS_GetDevPartitions(FS_DEVICE_TYPE_NAND) >= 1));
}

/*DirCache*/

 /*****************************************************************************
  * FUNCTION
  *  vs_fsys_DirCache_FS_SetGetExpireDirCache
  * DESCRIPTION
  *  file system
  * PARAMETERS
  *  -      [OUT]  -
  *  -       [IN]   -
  * RETURNS
  *  void
  *****************************************************************************/
 void vs_fsys_DirCache_FS_SetGetExpireDirCache(const WCHAR * FolderName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UINT cached_value = 0;
    FS_HANDLE MyHandle;
    S32 reval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MyHandle=FS_Open(FolderName, FS_OPEN_DIR|FS_READ_ONLY);
    if (MyHandle < FS_NO_ERROR)
    {
       FS_CreateDir(FolderName);
       MyHandle=FS_Open(FolderName, FS_OPEN_DIR|FS_READ_ONLY);
    }

    reval=FS_SetDirCache(MyHandle,cached_value);//revised
    AVK_LOG_FUN(FS_SetDirCache,(FS_NO_ERROR==reval));


    reval=FS_GetDirCache(MyHandle,&cached_value);
    AVK_LOG_FUN(FS_GetDirCache,(FS_NO_ERROR==reval));

    reval=FS_ExpireDirCache(MyHandle);
    AVK_LOG_FUN(FS_ExpireDirCache,((FS_NO_ERROR==reval)&&(FS_DIRCACHE_EXPIRED==FS_GetDirCache(MyHandle,&cached_value))));

    FS_Close(MyHandle);
    FS_RemoveDir(FolderName);
}

/*File System Run-Time LifeCycle*/

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_FileSys_FS_SanityCheck
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_FileSys_FS_SanityCheck(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reval=FS_SanityCheck();
    AVK_LOG_FUN(FS_SanityCheck,(FS_NO_ERROR==reval));
    AVK_ASYN_DONE();

}

/*Card management*/

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_CardMgr_FS_TestMSDC
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_CardMgr_FS_TestMSDC(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S32 reval;
    //kal_uint8 drv_list[FMT_MAX_DRIVE]={0};
    //kal_uint32 changed_drv_num=FMT_MAX_DRIVE;

    /* scan queue for multiple detect ind */
    //MSDC_HANDLE MSDC_Blk[SD_NUM];
    //MSDC_HANDLE    *gMSDC_Handle = &(MSDC_Blk[0]);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //reval = FS_TestMSDC(gMSDC_Handle, (BYTE*)&drv_list, (UINT*)&changed_drv_num);

    //MSDC_HANDLE    *gMSDC_Handle = &(MSDC_Blk[0]);
    //FS_TestMSDC((void *)&MSDC_Blk[1], NULL, 0);
    //if (FS_TestMSDC(SD_CARD) == FS_NO_ERROR)
    //{
    //   vs_fsys_result(L"AVK Test: FS_TestMSDC", MMI_TRUE, 0);
    //}else{
    //   vs_fsys_result(L"AVK Test: FS_TestMSDC", MMI_FALSE, 0);
    //}

}


/*Flash Device Direct IO*/

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_FlashDevice_FS_RecoverDevice
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_FlashDevice_FS_RecoverDevice(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reval = FS_RecoverDevice(FS_DEVICE_TYPE_NOR);
    if ( reval == FS_PARAM_ERROR)
    {
       reval = FS_RecoverDevice(FS_DEVICE_TYPE_NAND);
       AVK_LOG_FUN(FS_RecoverDevice,((FS_NO_ERROR == reval) || (FS_UNSUPPORTED_DEVICE == reval) || (FS_UNSUPPORTED_DRIVER_FUNCTION == reval)));
    }else if ((FS_NO_ERROR == reval) || (FS_UNSUPPORTED_DEVICE == reval) || (FS_UNSUPPORTED_DRIVER_FUNCTION == reval)){
      AVK_LOG_FUN(FS_RecoverDevice,AVK_PASS);
    }else{
      AVK_LOG_FUN(FS_RecoverDevice,AVK_FAIL);
    }

}


/*Flash Sweep*/

/*****************************************************************************
 * FUNCTION
 *  vs_fsys_FlashSweep_FS_SweepDevice
 * DESCRIPTION
 *  file system
 * PARAMETERS
 *  -      [OUT]  -
 *  -       [IN]   -
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fsys_FlashSweep_FS_SweepDevice(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 reval = -2, reval2 = -2;
    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //reval=FS_SweepDevice(FS_DEVICE_TYPE_NOR)||FS_SweepDevice(FS_DEVICE_TYPE_NAND);
    reval = FS_SweepDevice(FS_DEVICE_TYPE_NOR);
    while (FS_CHECKDISK_RETRY == reval)
    {
       kal_sleep_task(2);
       if (++count > 1000)
       {
           ASSERT(0);
       }
       reval = FS_SweepDevice(FS_DEVICE_TYPE_NOR);
    }
    count = 0;
    reval2 = FS_SweepDevice(FS_DEVICE_TYPE_NAND);
    while (FS_CHECKDISK_RETRY == reval2 && FS_NO_ERROR != reval)
    {
       kal_sleep_task(2);
       if (++count > 1000)
       {
           ASSERT(0);
       }
       reval2 = FS_SweepDevice(FS_DEVICE_TYPE_NAND);
    }

    AVK_LOG_FUN(FS_SweepDevice,((FS_NO_ERROR == reval)||(FS_NO_ERROR == reval2)));

}

AVK_CASE(AVK_SYSSRV_FILE_INIT,AVK_SYSSRV_FILE_AUTO)
{
    if (vs_sysser_filesys_init()< FS_NO_ERROR)
    {
        AVK_CASE_RESULT(AVK_FAIL);
    }else{
        AVK_CASE_RESULT(AVK_PASS);
    }
}

AVK_CASE(AVK_SYSSRV_FILE_IO,AVK_SYSSRV_FILE_INIT)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*IO*/
    vs_fsys_IO_FS_Open_Close(g_filesys_file,FS_READ_WRITE,VS_SYS_FS_FILE);
    vs_fsys_IO_FS_Open_Close(g_filesys_folder,FS_READ_ONLY,VS_SYS_FS_FOLDER);
    vs_fsys_IO_FS_OpenHint(g_filesys_file);
    //vs_fsys_IO_FS_CloseAll(filesys_folder);
    vs_fsys_IO_FS_Write_Read(g_filesys_file);
    vs_fsys_IO_FS_Seek(g_filesys_file);
    vs_fsys_IO_FS_Commit(g_filesys_file);
    vs_fsys_IO_FS_ParseFH(g_filesys_file);
    vs_fsys_IO_FS_GenVirtualFileName();
    vs_fsys_IO_FS_SetSeekHint(g_filesys_audio1);
    vs_fsys_IO_FS_SetSeekHintEx(g_filesys_audio1);
    vs_fsys_IO_FS_SeekLargeFile(g_filesys_audio1);
}

AVK_CASE(AVK_SYSSRV_FILE_INFORMATION,AVK_SYSSRV_FILE_INIT)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*Information*/
    vs_fsys_Information_FS_GetFileInfo();
    vs_fsys_Information_FS_GetFileInfoEx();                                     //Pass
    vs_fsys_Information_FS_GetFileSize();                                       //Pass
    vs_fsys_Information_FS_GetFilePosition();                                   //Pass
    vs_fsys_Information_FS_SetFileTime(7,12,5,5,6,8);                           //Pass
    vs_fsys_Information_FS_SetFileTime(25,12,5,5,6,29);                         //Pass
    vs_fsys_Information_FS_GetAttributes();                                     //Pass
    vs_fsys_Information_FS_GetFirstCluster();

}

AVK_CASE(AVK_SYSSRV_FILE_FILEONLY,AVK_SYSSRV_FILE_INIT)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*File Only*/
    vs_fsys_FileOnly_FS_SetAttributes(g_filesys_file);                            //Pass
    vs_fsys_FileOnly_FS_Delete(g_filesys_file);                                    //Pass
    vs_fsys_FileOnly_FS_PseudoMerge(g_filesys_audio1,g_filesys_audio2);            //Pass
    vs_fsys_FileOnly_FS_CheckFile(g_filesys_file);                                //Pass

}

AVK_CASE(AVK_SYSSRV_FILE_FOLDERONLY,AVK_SYSSRV_FILE_INIT)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*Folder Only*/
    vs_fsys_FolderOnlyOptr_FS_SetCurrentDir_GetCurrentDir(g_filesys_folder);      //Pass
    vs_fsys_FolderOnlyOptr_FS_GetCurrentDirByDrive(g_filesys_folder);
    vs_fsys_FolderOnlyOptr_FS_CreateDir_RemoveDir(g_filesys_folder);              //Pass
    vs_fsys_FolderOnlyOptr_FS_GetFolderSize(g_filesys_folder);                    //Pass

}

AVK_CASE(AVK_SYSSRV_FILE_FILEFOLDER,AVK_SYSSRV_FILE_INIT)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR NewFileName[FS_MAX_PATH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcscpy(NewFileName,g_filesys_path);
    mmi_wcscat(NewFileName,(WCHAR *)L"\\newname.mp3");

    /*File and Folder Operations*/
    vs_fsys_FileAndFolder_FS_Extend_Truncate(g_filesys_file);                     //Pass
    vs_fsys_FileAndFolder_FS_MakeFileName(g_filesys_file);                        //Pass
    vs_fsys_FileAndFolder_FS_Rename(g_filesys_file,NewFileName);               //Pass
    vs_fsys_FileAndFolder_FS_Move(g_filesys_file,g_filesys_path);                   //Pass
    vs_fsys_FileAndFolder_FS_Count(g_filesys_path);                               //Pass
    vs_fsys_FileAndFolder_FS_XDelete(g_filesys_folder);                           //Pass
    vs_fsys_FileAndFolder_FS_XDeleteEx(g_filesys_folder);
    vs_fsys_FileAndFolder_FS_CompactDir(g_filesys_folder);

}

AVK_CASE(AVK_SYSSRV_FILE_FINDFILE,AVK_SYSSRV_FILE_INIT)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*Find File*/
    vs_fsys_FindFile_FS_FindFirst_FindClose(g_filesys_folder);
    vs_fsys_FindFile_FS_FindNext(g_filesys_folder);
    vs_fsys_FindFile_FS_FindFirstN_FindNextN(g_filesys_folder);
    vs_fsys_FindFile_FS_ListOpen_ListNext_ListClose(g_filesys_folder);

    #ifdef __FS_SORT_SUPPORT__
        vs_fsys_FindFile_FS_SortCompareFileName_Type(g_filesys_folder);
        vs_fsys_FindFile_FS_XFindReset_XFindStart_XFindClose(g_filesys_folder);
    #else
        AVK_LOG_FUN_UNSUPPORTED(FS_SortCompareFileName);
        AVK_LOG_FUN_UNSUPPORTED(FS_XFindReset);
        AVK_LOG_FUN_UNSUPPORTED(FS_XFindStart);
        AVK_LOG_FUN_UNSUPPORTED(FS_XFindClose);
    #endif

}

AVK_CASE(AVK_SYSSRV_FILE_DRIVEMGRT,AVK_SYSSRV_FILE_INIT)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*Drive Management*/
    vs_fsys_DrvMgr_FS_GetDrive(FS_DRIVE_V_NORMAL,1,FS_DRIVE_V_REMOVABLE|FS_DRIVE_I_SYSTEM,66,VS_SYS_FS_GREATER);//Pass
    vs_fsys_DrvMgr_FS_GetDrive(FS_DRIVE_V_NORMAL,2,FS_NO_ALT_DRIVE,-4,VS_SYS_FS_EQUAL);//Pass

    vs_fsys_DrvMgr_FS_GetClusterSize('Z');                                      //Pass
    vs_fsys_DrvMgr_FS_GetClusterSize(FS_GetDrive(FS_DRIVE_V_NORMAL,1,FS_DRIVE_V_REMOVABLE|FS_DRIVE_I_SYSTEM));//Pass

    #ifdef __FS_QM_SUPPORT__
       vs_fsys_DrvMgr_FS_QmGetFree();
    #else
       AVK_LOG_FUN_UNSUPPORTED(FS_QmGetFree);
    #endif
    vs_fsys_DrvMgr_FS_CommitAll();
    vs_fsys_DrvMgr_FS_GetPartitionInfo();
    vs_fsys_DrvMgr_FS_MappingDrive();                           //Pass

    //DeleteUptoScrID(SCR_ID_SYS_MAIN);

}

AVK_SPECIAL_CASE(AVK_SYSSRV_FILE_FORMAT,AVK_SYSSRV_FILE_SPEC)
{
    AVK_MANU_SHOW_TIPS(L"If phone disk formated, it's pass",vs_fsys_DrvMgr_FS_GeneralFormat); //Test Case By Case
}

AVK_MANUAL_CASE(AVK_SYSSRV_FILE_LIFECYCLE,AVK_SYSSRV_FILE_MANU)
{
   /*File System Run-Time LifeCycle*/
   vs_fsys_FileSys_FS_SanityCheck();
}


AVK_CASE(AVK_SYSSRV_FILE_PWRLOST,AVK_SYSSRV_FILE_INIT)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*Power Lost Detection and Recovery*/
    vs_fsys_PwrLost_FS_Set_Check_ClearDiskFlag();
    vs_fsys_PwrLost_FS_CheckDrive();

}

AVK_CASE(AVK_SYSSRV_FILE_DISKMGRT,AVK_SYSSRV_FILE_INIT)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*Disk Management*/
    vs_fsys_DiskMgr_FS_GetDiskInfo();
    vs_fsys_DiskMgr_FS_GetDevType();
    vs_fsys_DiskMgr_FS_GetDevStatus();
    vs_fsys_DiskMgr_FS_GetDevPartitions();

}

/*

AVK_CASE(AVK_SYSSRV_FILE_CARDMGRT,AVK_SYSSRV_FILE_INIT)
{
    vs_fsys_CardMgr_FS_TestMSDC();
}
*/

AVK_CASE(AVK_SYSSRV_FILE_DIRCACHE,AVK_SYSSRV_FILE_INIT)
{
    /*DirCache*/
    vs_fsys_DirCache_FS_SetGetExpireDirCache(g_filesys_folder);

}

AVK_CASE(AVK_SYSSRV_FILE_FLASHDEVICE,AVK_SYSSRV_FILE_INIT)
{
    /*Flash Device Direct IO*/
    vs_fsys_FlashDevice_FS_RecoverDevice();

}

AVK_CASE(AVK_SYSSRV_FILE_FLASHSWEEP,AVK_SYSSRV_FILE_INIT)
{
    /*Flash Sweep*/
    vs_fsys_FlashSweep_FS_SweepDevice();

}
