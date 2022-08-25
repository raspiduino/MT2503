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

extern "C"
{
#include "fs_gprot.h"
#include "FileMgrSrvGProt.h"
}


/*****************************************************************************
 * FUNCTION
 *  avk_syssrv_FS_CheckFileName
 * DESCRIPTION
 *  test case for FS_CheckFileName()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_syssrv_FS_CheckFileName(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 drive = SRV_FMGR_CARD_DRV;
    U16 test_path[50];
    S32 fhandle, ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_fmgr_drv_is_accessible(drive) == MMI_FALSE)
    {
        drive = SRV_FMGR_PHONE_DRV;
    }
    kal_wsprintf(test_path, "%c:\\%s", drive, "async_testcase.k");
    fhandle = FS_Open(test_path, FS_CREATE_ALWAYS);
    ret = FS_CheckFileName(test_path);

    if (ret >= FS_NO_ERROR)
    {
        AVK_LOG_FUN(FS_CheckFileName, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(FS_CheckFileName, AVK_FAIL);
    }
    FS_Close(fhandle);
    FS_Delete(test_path);
}


/*****************************************************************************
 * FUNCTION
 *  avk_syssrv_FS_GetDriveByHandle
 * DESCRIPTION
 *  test case for FS_GetDriveByHandle()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_syssrv_FS_GetDriveByHandle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 drive = SRV_FMGR_CARD_DRV;
    U16 test_path[50];
    S32 fhandle, ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_fmgr_drv_is_accessible(drive) == MMI_FALSE)
    {
        drive = SRV_FMGR_PHONE_DRV;
    }
    kal_wsprintf(test_path, "%c:\\%s", drive, "async_testcase.k");
    fhandle = FS_Open(test_path, FS_CREATE_ALWAYS);
    ret = FS_GetDriveByHandle(fhandle);
    MMI_PRINT(MOD_MRE, MMI_MRE_TRC_G1_AM, "[AVK] avk_syssrv_FS_GetDriveByHandle <drive:%d,fhandle:%d,ret:%d>\n", drive, fhandle, ret);

    if (ret >= FS_NO_ERROR)
    {
        AVK_LOG_FUN(FS_GetDriveByHandle, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(FS_GetDriveByHandle, AVK_FAIL);
    }
    FS_Close(fhandle);
    FS_Delete(test_path);
}


/*****************************************************************************
 * FUNCTION
 *  avk_syssrv_FS_GetFolderSizeEx
 * DESCRIPTION
 *  test case for FS_GetFolderSizeEx()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_syssrv_FS_GetFolderSizeEx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 drive = SRV_FMGR_CARD_DRV;
    U16 test_path[50];
    int fs_ret;
    S32 fhandle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_fmgr_drv_is_accessible(drive) == MMI_FALSE)
    {
        drive = SRV_FMGR_PHONE_DRV;
    }
    kal_wsprintf(test_path, "%c:\\%s", drive, "async_testcase_folder");
    fhandle = FS_CreateDir(test_path);
    fs_ret = FS_GetFolderSizeEx(test_path, FS_COUNT_IN_CLUSTER, NULL, 0, NULL);
    MMI_PRINT(MOD_MRE, MMI_MRE_TRC_G1_AM, "[AVK] avk_syssrv_FS_GetFolderSizeEx <drive:%d,fhandle:%d,fs_ret:%d>\n", drive, fhandle, fs_ret);
    if (fs_ret >= FS_NO_ERROR)
    {
        AVK_LOG_FUN(FS_GetFolderSizeEx, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(FS_GetFolderSizeEx, AVK_FAIL);
    }
    FS_XDelete(test_path, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
}


/*****************************************************************************
 * FUNCTION
 *  avk_syssrv_FS_CountUsedFH
 * DESCRIPTION
 *  test case for FS_CountUsedFH()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_syssrv_FS_CountUsedFH(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int fscount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fscount = FS_CountUsedFH(FS_FH_COUNT_CURRENT_TASK);
    if (fscount >= 0)
    {
        AVK_LOG_FUN(FS_CountUsedFH, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(FS_CountUsedFH, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_syssrv_FS_IOCtrl
 * DESCRIPTION
 *  test case for FS_IOCtrl()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_syssrv_FS_IOCtrl(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 drive = SRV_FMGR_CARD_DRV;
    WCHAR drive_char;
    int fs_ret;
    FS_DeviceInfo dev_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_fmgr_drv_is_accessible(drive) == MMI_FALSE)
    {
        drive = SRV_FMGR_PHONE_DRV;
    }
    drive_char = (WCHAR) drive;
    fs_ret = FS_IOCtrl(&drive_char, FS_IOCTRL_QUERY_NAND_INFO, &dev_info);
    /* if (fs_ret >= FS_NO_ERROR) */
    {
        AVK_LOG_FUN(FS_IOCtrl, AVK_PASS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_syssrv_FS_DirCtrl
 * DESCRIPTION
 *  test case for FS_DirCtrl()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_syssrv_FS_DirCtrl(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int fs_ret;
    S32 drive = SRV_FMGR_CARD_DRV;
    U16 test_path[50];
    S32 fhandle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_fmgr_drv_is_accessible(drive) == MMI_FALSE)
    {
        drive = SRV_FMGR_PHONE_DRV;
    }
    kal_wsprintf(test_path, "%c:\\%s", drive, "async_testcase.k");
    fhandle = FS_Open(test_path, FS_CREATE_ALWAYS);
    fs_ret = FS_DirCtrl(fhandle, FS_DIRCTRL_DATA_UNLOCK, NULL);
    /* if (fs_ret >= FS_NO_ERROR) */
    {
        AVK_LOG_FUN(FS_DirCtrl, AVK_PASS);
    }
    FS_Close(fhandle);
    FS_Delete(test_path);
}


/*****************************************************************************
 * FUNCTION
 *  avk_syssrv_fs_async_open_cb
 * DESCRIPTION
 *
 * PARAMETERS
 *  async_job_id        [IN]
 *  result              [IN]
 *  data                [IN]
 * RETURNS
 *
 *****************************************************************************/
S32 avk_syssrv_fs_async_open_cb(fs_job_id async_job_id, kal_int64 result, fs_async_callback_data_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 drive = SRV_FMGR_CARD_DRV;
    U16 test_path[50];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_fmgr_drv_is_accessible(drive) == MMI_FALSE)
    {
        drive = SRV_FMGR_PHONE_DRV;
    }
    kal_wsprintf(test_path, "%c:\\%s", drive, "async_testcase_open");
    if (result >= 0)
    {
        /* AVK_LOG_FUN(fs_async_open, AVK_PASS); */
        FS_Close(result);
        FS_Delete(test_path);
    }
    else
    {
        /* AVK_LOG_FUN(fs_async_open, AVK_FAIL); */
    }
    OslMfree(data);
    AVK_ASYN_DONE();
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  avk_syssrv_fs_async_open
 * DESCRIPTION
 *  test case for fs_async_open()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_syssrv_fs_async_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 job_id;
    fs_overlapped_struct overlapped;
    S32 drive = SRV_FMGR_CARD_DRV;
    U16 test_path[50];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(fs_async_msg_handler, MSG_ID_FS_OPEN_RSP);
    SetProtocolEventHandler(fs_async_msg_handler, MSG_ID_FS_FIND_FIRST_RSP);
    SetProtocolEventHandler(fs_async_msg_handler, MSG_ID_FS_GET_FOLDER_SIZE_RSP);
    SetProtocolEventHandler(fs_async_msg_handler, MSG_ID_FS_WRITE_RSP);
    SetProtocolEventHandler(fs_async_msg_handler, MSG_ID_FS_READ_RSP);
    SetProtocolEventHandler(fs_async_msg_handler, MSG_ID_FS_DELETE_RSP);
    SetProtocolEventHandler(fs_async_msg_handler, MSG_ID_FS_SEEK_RSP);
    SetProtocolEventHandler(fs_async_msg_handler, MSG_ID_FS_FIND_FIRST_N_RSP);
    if (srv_fmgr_drv_is_accessible(drive) == MMI_FALSE)
    {
        drive = SRV_FMGR_PHONE_DRV;
    }
    kal_wsprintf(test_path, "%c:\\%s", drive, "async_testcase_open");
    overlapped.callback = (fs_async_callback) avk_syssrv_fs_async_open_cb;
    overlapped.param = test_path;
    overlapped.priority = FS_PRIORITY_DEFAULT;
    overlapped.buf = (void*)OslMalloc(FS_ASYNC_WORKING_BUFFER_SIZE);
    overlapped.buf_size = FS_ASYNC_WORKING_BUFFER_SIZE;
    overlapped.response_flag = FS_RESPONSE_MESSAGE;
    job_id = fs_async_open((const WCHAR*)test_path, FS_CREATE_ALWAYS, &overlapped);
    if (job_id >= 0)
    {
        AVK_LOG_FUN(fs_async_open, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(fs_async_open, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_syssrv_fs_async_read_cb
 * DESCRIPTION
 *
 * PARAMETERS
 *  async_job_id        [IN]
 *  result              [IN]
 *  data                [IN]
 * RETURNS
 *
 *****************************************************************************/
S32 avk_syssrv_fs_async_read_cb(fs_job_id async_job_id, kal_int64 result, fs_async_callback_data_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 drive = SRV_FMGR_CARD_DRV;
    U16 test_path[50];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_fmgr_drv_is_accessible(drive) == MMI_FALSE)
    {
        drive = SRV_FMGR_PHONE_DRV;
    }
    kal_wsprintf(test_path, "%c:\\%s", drive, "async_testcase_read");
    if (result >= 0)
    {
        /* AVK_LOG_FUN(fs_async_open, AVK_PASS); */
        FS_Close(result);
        FS_Delete(test_path);
    }
    else
    {
        /* AVK_LOG_FUN(fs_async_open, AVK_FAIL); */
    }
    OslMfree(data);
    AVK_ASYN_DONE();
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  avk_syssrv_fs_async_read
 * DESCRIPTION
 *  test case for fs_async_read()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_syssrv_fs_async_read(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 drive = SRV_FMGR_CARD_DRV;
    U16 test_path[50];
    S32 fhandle;
    fs_overlapped_struct overlapped;
    S32 job_id;
    S8 data[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_fmgr_drv_is_accessible(drive) == MMI_FALSE)
    {
        drive = SRV_FMGR_PHONE_DRV;
    }
    kal_wsprintf(test_path, "%c:\\%s", drive, "async_testcase_read");
    fhandle = FS_Open(test_path, FS_CREATE_ALWAYS);
    overlapped.callback = (fs_async_callback) avk_syssrv_fs_async_read_cb;
    overlapped.param = test_path;
    overlapped.priority = FS_PRIORITY_DEFAULT;
    overlapped.buf = (void*)OslMalloc(FS_ASYNC_WORKING_BUFFER_SIZE);
    overlapped.buf_size = FS_ASYNC_WORKING_BUFFER_SIZE;
    overlapped.response_flag = FS_RESPONSE_MESSAGE;
    job_id = fs_async_read(fhandle, (void*)data, 1, NULL, &overlapped);
    if (job_id >= 0)
    {
        AVK_LOG_FUN(fs_async_read, AVK_PASS);
        FS_Close(fhandle);      // TODO:
    }
    else
    {
        AVK_LOG_FUN(fs_async_read, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_syssrv_fs_async_write_cb
 * DESCRIPTION
 *
 * PARAMETERS
 *  async_job_id        [IN]
 *  result              [IN]
 *  data                [IN]
 * RETURNS
 *
 *****************************************************************************/
S32 avk_syssrv_fs_async_write_cb(fs_job_id async_job_id, kal_int64 result, fs_async_callback_data_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 drive = SRV_FMGR_CARD_DRV;
    U16 test_path[50];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_fmgr_drv_is_accessible(drive) == MMI_FALSE)
    {
        drive = SRV_FMGR_PHONE_DRV;
    }
    kal_wsprintf(test_path, "%c:\\%s", drive, "async_testcase_write");
    if (result >= 0)
    {
        /* AVK_LOG_FUN(fs_async_open, AVK_PASS); */
        FS_Close(result);
        FS_Delete(test_path);
    }
    else
    {
        /* AVK_LOG_FUN(fs_async_open, AVK_FAIL); */
    }
    OslMfree(data);
    AVK_ASYN_DONE();
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  avk_syssrv_fs_async_write
 * DESCRIPTION
 *  test case for fs_async_write()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_syssrv_fs_async_write(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 drive = SRV_FMGR_CARD_DRV;
    U16 test_path[50];
    S32 fhandle;
    fs_overlapped_struct overlapped;
    S32 job_id;
    S8 data[10] = {1};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_fmgr_drv_is_accessible(drive) == MMI_FALSE)
    {
        drive = SRV_FMGR_PHONE_DRV;
    }
    kal_wsprintf(test_path, "%c:\\%s", drive, "async_testcase_write");
    fhandle = FS_Open(test_path, FS_CREATE_ALWAYS);
    overlapped.callback = (fs_async_callback) avk_syssrv_fs_async_write_cb;
    overlapped.param = test_path;
    overlapped.priority = FS_PRIORITY_DEFAULT;
    overlapped.buf = (void*)OslMalloc(FS_ASYNC_WORKING_BUFFER_SIZE);
    overlapped.buf_size = FS_ASYNC_WORKING_BUFFER_SIZE;
    overlapped.response_flag = FS_RESPONSE_MESSAGE;
    job_id = fs_async_write(fhandle, (void*)data, 1, NULL, &overlapped);
    if (job_id >= 0)
    {
        AVK_LOG_FUN(fs_async_write, AVK_PASS);
        FS_Close(fhandle);      // TODO:
    }
    else
    {
        AVK_LOG_FUN(fs_async_write, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_syssrv_fs_async_seek_cb
 * DESCRIPTION
 *
 * PARAMETERS
 *  async_job_id        [IN]
 *  result              [IN]
 *  data                [IN]
 * RETURNS
 *
 *****************************************************************************/
S32 avk_syssrv_fs_async_seek_cb(fs_job_id async_job_id, kal_int64 result, fs_async_callback_data_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 drive = SRV_FMGR_CARD_DRV;
    U16 test_path[50];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_fmgr_drv_is_accessible(drive) == MMI_FALSE)
    {
        drive = SRV_FMGR_PHONE_DRV;
    }
    kal_wsprintf(test_path, "%c:\\%s", drive, "async_testcase_seek");
    if (result >= 0)
    {
        /* AVK_LOG_FUN(fs_async_open, AVK_PASS); */
        FS_Close(result);
        FS_Delete(test_path);
    }
    else
    {
        /* AVK_LOG_FUN(fs_async_open, AVK_FAIL); */
    }
    OslMfree(data);
    AVK_ASYN_DONE();
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  avk_syssrv_fs_async_seek
 * DESCRIPTION
 *  test case for fs_async_seek()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_syssrv_fs_async_seek(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 drive = SRV_FMGR_CARD_DRV;
    U16 test_path[50];
    S32 fhandle;
    fs_overlapped_struct overlapped;
    S32 job_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_fmgr_drv_is_accessible(drive) == MMI_FALSE)
    {
        drive = SRV_FMGR_PHONE_DRV;
    }
    kal_wsprintf(test_path, "%c:\\%s", drive, "async_testcase_seek");
    fhandle = FS_Open(test_path, FS_CREATE_ALWAYS);
    overlapped.callback = (fs_async_callback) avk_syssrv_fs_async_seek_cb;
    overlapped.param = test_path;
    overlapped.priority = FS_PRIORITY_DEFAULT;
    overlapped.buf = (void*)OslMalloc(FS_ASYNC_WORKING_BUFFER_SIZE);
    overlapped.buf_size = FS_ASYNC_WORKING_BUFFER_SIZE;
    overlapped.response_flag = FS_RESPONSE_MESSAGE;
    job_id = fs_async_seek(fhandle, 1, FS_FILE_BEGIN, &overlapped);
    if (job_id >= 0)
    {
        AVK_LOG_FUN(fs_async_seek, AVK_PASS);
        FS_Close(fhandle);      // TODO:
    }
    else
    {
        AVK_LOG_FUN(fs_async_seek, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_syssrv_fs_async_find_first_cb
 * DESCRIPTION
 *
 * PARAMETERS
 *  async_job_id        [IN]
 *  result              [IN]
 *  data                [IN]
 * RETURNS
 *
 *****************************************************************************/
S32 avk_syssrv_fs_async_find_first_cb(fs_job_id async_job_id, kal_int64 result, fs_async_callback_data_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result >= 0)
    {
        /* AVK_LOG_FUN(fs_async_open, AVK_PASS); */
        FS_FindClose(result);
    }
    else
    {
        /* AVK_LOG_FUN(fs_async_open, AVK_FAIL); */
    }
    OslMfree(data);
    AVK_ASYN_DONE();
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  avk_syssrv_fs_async_find_first
 * DESCRIPTION
 *  test case for fs_async_find_first()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_syssrv_fs_async_find_first(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 drive = SRV_FMGR_CARD_DRV;
    U16 test_path[50];
    fs_overlapped_struct overlapped;
    S32 job_id;
    FS_DOSDirEntry de;
    U16 *name_w;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_fmgr_drv_is_accessible(drive) == MMI_FALSE)
    {
        drive = SRV_FMGR_PHONE_DRV;
    }
    kal_wsprintf(test_path, "%c:\\*.*", drive);
    overlapped.callback = (fs_async_callback) avk_syssrv_fs_async_find_first_cb;
    overlapped.param = test_path;
    overlapped.priority = FS_PRIORITY_DEFAULT;
    overlapped.buf = (void*)OslMalloc(FS_ASYNC_WORKING_BUFFER_SIZE+FS_MAX_PATH);
    overlapped.buf_size = FS_ASYNC_WORKING_BUFFER_SIZE;
    overlapped.response_flag = FS_RESPONSE_MESSAGE;
    name_w = (U16*)((kal_uint8*)overlapped.buf + FS_ASYNC_WORKING_BUFFER_SIZE);
    job_id = fs_async_find_first(test_path, 0, FS_ATTR_DIR, &de, name_w, FS_MAX_PATH, &overlapped);
    if (job_id >= 0)
    {
        AVK_LOG_FUN(fs_async_find_first, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(fs_async_find_first, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_syssrv_fs_async_find_first_n_cb
 * DESCRIPTION
 *
 * PARAMETERS
 *  async_job_id        [IN]
 *  result              [IN]
 *  data                [IN]
 * RETURNS
 *
 *****************************************************************************/
S32 avk_syssrv_fs_async_find_first_n_cb(fs_job_id async_job_id, kal_int64 result, fs_async_callback_data_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result >= 0)
    {
        /* AVK_LOG_FUN(fs_async_open, AVK_PASS); */
        FS_FindClose(result);
    }
    else
    {
        /* AVK_LOG_FUN(fs_async_open, AVK_FAIL); */
    }
    OslMfree(data);
    AVK_ASYN_DONE();
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  avk_syssrv_fs_async_find_first_n
 * DESCRIPTION
 *  test case for fs_async_find_first_n()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_syssrv_fs_async_find_first_n(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 drive = SRV_FMGR_CARD_DRV;
    U16 test_path[50];
    fs_overlapped_struct overlapped;
    S32 job_id;
    FS_DOSDirEntry de;
    U16 *name_w;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_fmgr_drv_is_accessible(drive) == MMI_FALSE)
    {
        drive = SRV_FMGR_PHONE_DRV;
    }
    kal_wsprintf(test_path, "%c:\\*.*", drive);
    overlapped.callback = (fs_async_callback) avk_syssrv_fs_async_find_first_n_cb;
    overlapped.param = test_path;
    overlapped.priority = FS_PRIORITY_DEFAULT;
    overlapped.buf = (void*)OslMalloc(FS_ASYNC_WORKING_BUFFER_SIZE+FS_MAX_PATH);
    overlapped.buf_size = FS_ASYNC_WORKING_BUFFER_SIZE;
    overlapped.response_flag = FS_RESPONSE_MESSAGE;
    name_w = (U16*)((kal_uint8*)overlapped.buf + FS_ASYNC_WORKING_BUFFER_SIZE);
    job_id = fs_async_find_first_n(
                test_path,
                NULL,
                0,
                FS_ATTR_DIR,
                0,
                FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                &de,
                name_w,
                FS_MAX_PATH,
                0,
                FS_FIND_DEFAULT,
                &overlapped);
    if (job_id >= 0)
    {
        AVK_LOG_FUN(fs_async_find_first_n, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(fs_async_find_first_n, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_syssrv_fs_async_delete
 * DESCRIPTION
 *  test case for fs_async_delete()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_syssrv_fs_async_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 job_id;
    fs_overlapped_struct overlapped;
    S32 drive = SRV_FMGR_CARD_DRV;
    U16 test_path[50];
    S32 fhandle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_fmgr_drv_is_accessible(drive) == MMI_FALSE)
    {
        drive = SRV_FMGR_PHONE_DRV;
    }
    kal_wsprintf(test_path, "%c:\\%s", drive, "async_testcase_delete");
    fhandle = FS_Open(test_path, FS_CREATE_ALWAYS);
    FS_Close(fhandle);
    overlapped.callback = (fs_async_callback) avk_syssrv_fs_async_open_cb;
    overlapped.param = test_path;
    overlapped.priority = FS_PRIORITY_DEFAULT;
    overlapped.buf = (void*)OslMalloc(FS_ASYNC_WORKING_BUFFER_SIZE);
    overlapped.buf_size = FS_ASYNC_WORKING_BUFFER_SIZE;
    overlapped.response_flag = FS_RESPONSE_MESSAGE;
    job_id = fs_async_delete((const WCHAR*)test_path, &overlapped);
    if (job_id >= 0)
    {
        AVK_LOG_FUN(fs_async_delete, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(fs_async_delete, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_syssrv_fs_async_get_folder_size_cb
 * DESCRIPTION
 *
 * PARAMETERS
 *  async_job_id        [IN]
 *  result              [IN]
 *  data                [IN]
 * RETURNS
 *
 *****************************************************************************/
S32 avk_syssrv_fs_async_get_folder_size_cb(
        fs_job_id async_job_id,
        kal_int64 result,
        fs_async_callback_data_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 drive = SRV_FMGR_CARD_DRV;
    U16 test_path[50];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_fmgr_drv_is_accessible(drive) == MMI_FALSE)
    {
        drive = SRV_FMGR_PHONE_DRV;
    }
    kal_wsprintf(test_path, "%c:\\%s", drive, "async_testcase_get_folder_size");
    if (result >= 0)
    {
        /* AVK_LOG_FUN(fs_async_open, AVK_PASS); */
        FS_Close(result);
        FS_XDelete(test_path, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
    }
    else
    {
        /* AVK_LOG_FUN(fs_async_open, AVK_FAIL); */
    }
    OslMfree(data);
    AVK_ASYN_DONE();
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  avk_syssrv_fs_async_get_folder_size
 * DESCRIPTION
 *  test case for fs_async_get_folder_size()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_syssrv_fs_async_get_folder_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 job_id;
    fs_overlapped_struct overlapped;
    S32 drive = SRV_FMGR_CARD_DRV;
    U16 test_path[50];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_fmgr_drv_is_accessible(drive) == MMI_FALSE)
    {
        drive = SRV_FMGR_PHONE_DRV;
    }
    kal_wsprintf(test_path, "%c:\\%s", drive, "async_testcase_get_folder_size");
    FS_CreateDir(test_path);
    overlapped.callback = (fs_async_callback) avk_syssrv_fs_async_get_folder_size_cb;
    overlapped.param = test_path;
    overlapped.priority = FS_PRIORITY_DEFAULT;
    overlapped.buf = (void*)OslMalloc(FS_ASYNC_WORKING_BUFFER_SIZE);
    overlapped.buf_size = FS_ASYNC_WORKING_BUFFER_SIZE;
    overlapped.response_flag = FS_RESPONSE_MESSAGE;
    job_id = fs_async_get_folder_size(test_path, FS_COUNT_IN_CLUSTER, NULL, 0, NULL, &overlapped);
    if (job_id >= 0)
    {
        AVK_LOG_FUN(fs_async_get_folder_size, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(fs_async_get_folder_size, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_syssrv_fs_async_abort
 * DESCRIPTION
 *  test case for fs_async_abort()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_syssrv_fs_async_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = fs_async_abort(-1);
    if (ret == FS_ERR_INVALID_JOB_ID)
    {
        AVK_LOG_FUN(fs_async_abort, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(fs_async_abort, AVK_FAIL);
    }
}

AVK_CASE(AVK_SYSSRV_FILE_ASYNC_CASE_1,AVK_SYSSRV_FILE_ASYNC)
{
    avk_syssrv_FS_CheckFileName();
}

AVK_CASE(AVK_SYSSRV_FILE_ASYNC_CASE_2,AVK_SYSSRV_FILE_ASYNC)
{
    avk_syssrv_FS_GetDriveByHandle();
}


AVK_CASE(AVK_SYSSRV_FILE_ASYNC_CASE_3,AVK_SYSSRV_FILE_ASYNC)
{
    avk_syssrv_FS_GetFolderSizeEx();
}


AVK_CASE(AVK_SYSSRV_FILE_ASYNC_CASE_4,AVK_SYSSRV_FILE_ASYNC)
{
    avk_syssrv_FS_CountUsedFH();
}

AVK_CASE(AVK_SYSSRV_FILE_ASYNC_CASE_5,AVK_SYSSRV_FILE_ASYNC)
{
    avk_syssrv_FS_IOCtrl();
}

AVK_CASE(AVK_SYSSRV_FILE_ASYNC_CASE_6,AVK_SYSSRV_FILE_ASYNC)
{
    avk_syssrv_FS_DirCtrl();
}

AVK_ASYN_CASE(AVK_SYSSRV_FILE_ASYNC_CASE_7,AVK_SYSSRV_FILE_ASYNC)
{
    avk_syssrv_fs_async_open();
}

AVK_ASYN_CASE(AVK_SYSSRV_FILE_ASYNC_CASE_8,AVK_SYSSRV_FILE_ASYNC)
{
    avk_syssrv_fs_async_read();
}

AVK_ASYN_CASE(AVK_SYSSRV_FILE_ASYNC_CASE_9,AVK_SYSSRV_FILE_ASYNC)
{
    avk_syssrv_fs_async_write();
}

AVK_ASYN_CASE(AVK_SYSSRV_FILE_ASYNC_CASE_10,AVK_SYSSRV_FILE_ASYNC)
{
    avk_syssrv_fs_async_seek();
}

AVK_ASYN_CASE(AVK_SYSSRV_FILE_ASYNC_CASE_11,AVK_SYSSRV_FILE_ASYNC)
{
    avk_syssrv_fs_async_find_first();
}

AVK_ASYN_CASE(AVK_SYSSRV_FILE_ASYNC_CASE_12,AVK_SYSSRV_FILE_ASYNC)
{
    avk_syssrv_fs_async_find_first_n();
}

AVK_ASYN_CASE(AVK_SYSSRV_FILE_ASYNC_CASE_13,AVK_SYSSRV_FILE_ASYNC)
{
    avk_syssrv_fs_async_delete();
}

AVK_ASYN_CASE(AVK_SYSSRV_FILE_ASYNC_CASE_14,AVK_SYSSRV_FILE_ASYNC)
{
    avk_syssrv_fs_async_get_folder_size();
}

AVK_CASE(AVK_SYSSRV_FILE_ASYNC_CASE_15,AVK_SYSSRV_FILE_ASYNC)
{
    avk_syssrv_fs_async_abort();
}

