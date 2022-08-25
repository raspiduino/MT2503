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
 *  ImgViewerCacheDB.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Database module of image viewer decoder.
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
 ****************************************************************************/

#include "ImgViewerCache.h"
#if defined(__MMI_IVF_CACHE_DB__)
#include "Unicodexdcl.h"        /* mmi_wcsxxxx */
#include "gui.h"        /* gui timer */
#include "MMI_trc_Int.h"        /* MMI_ASSERT */
#include "DebugInitDef_Int.h"   /* MMI_TRACE */
#include "mmi_frm_mem_gprot.h"  /* OslMalloc */

#define __IVCMODULE__ "DB"

static void mmi_ivc_db_list_init(mmi_ivc_db_cntx_struct *db);
static void mmi_ivc_db_create_working_folder(mmi_ivc_db_cntx_struct *db);

#ifdef __MMI_AP_DCM_CAMIMGV__
#pragma arm section rodata = "DYNAMIC_CODE_CAMIMGV_RODATA",code = "DYNAMIC_CODE_CAMIMGV_ROCODE"
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_db_list_atoi
 * DESCRIPTION
 *
 * PARAMETERS
 *  str         [?]
 *  start       [IN]
 *  len         [IN]
 * RETURNS
 *
 *****************************************************************************/
static U32 mmi_ivc_db_list_atoi(CHAR *str, U32 start, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 end = start + len - 1;
    U32 temp;
    U32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = start; i <= end; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
            temp = str[i] - 48;
        else
            break;
        ret *= 10;
        ret += temp;
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_db_list_fmgr_proc
 * DESCRIPTION
 *
 * PARAMETERS
 *  param       [?]
 * RETURNS
 *
 *****************************************************************************/
static mmi_ret mmi_ivc_db_list_fmgr_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_async_done_event_struct *doneEvt = (srv_fmgr_async_done_event_struct*) param;
    mmi_ivc_db_cntx_struct *db = (mmi_ivc_db_cntx_struct*) param->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_DB_LIST_FMGR_PROC, param->evt_id, doneEvt->result);
    if (0 == db->list.fmgrAsyncJob)
        return MMI_RET_OK;

    switch (param->evt_id)
    {
        case EVT_ID_SRV_FMGR_ASYNC_DONE:
        {
            mmi_ivc_db_create_working_folder(db);
            mmi_ivc_db_list_init(db);
        }
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_db_list_init
 * DESCRIPTION
 *
 * PARAMETERS
 *  db      [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ivc_db_list_init(mmi_ivc_db_cntx_struct *db)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR    header[MMI_IVC_DB_LIST_HEADER_LEN];
    U32     read;
    WCHAR   *listFile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db->list.fmgrAsyncJob = 0;

    if (MMI_IVC_PATH_MAX_LEN <
        mmi_wcslen(db->folderpath) + MMI_IVC_DB_WORK_FOLDER_NAME_LEN + MMI_IVC_DB_LIST_FILE_NAME_LEN)
    {
        db->state = MMI_IVC_DB_STATE_INVALID;
        return;
    }

    listFile = (WCHAR*)OslMalloc(MMI_IVC_PATH_BUF_SIZE);

    IVC_PMD_START("lin");

    kal_wsprintf(listFile, "%w%s%s", db->folderpath, MMI_IVC_DB_WORK_FOLDER_NAME, MMI_IVC_DB_LIST_FILE_NAME);

    db->list.fHdl = IVC_PMD_FS_OPEN(listFile, FS_READ_WRITE | FS_CREATE | FS_ATTR_HIDDEN);

    if (FS_NO_ERROR > db->list.fHdl)
    {
        db->state = MMI_IVC_DB_STATE_INVALID;
    }
    else
    {
        S32 lcdW = LCD_WIDTH;
        S32 lcdH = LCD_HEIGHT;

        IVC_PMD_FS_READ(db->list.fHdl, header, MMI_IVC_DB_LIST_HEADER_LEN, &read);

        if (MMI_IVC_DB_LIST_HEADER_LEN != read)
        {
            db->list.count = 0;
            db->list.idx = 0;
        }
        else
        {
            lcdW = mmi_ivc_db_list_atoi(header, 0, MMI_IVC_DB_LIST_HEADER_W_LEN);
            lcdH = mmi_ivc_db_list_atoi(header, MMI_IVC_DB_LIST_HEADER_W_LEN, MMI_IVC_DB_LIST_HEADER_H_LEN);
            db->list.idx = mmi_ivc_db_list_atoi(header, MMI_IVC_DB_LIST_HEADER_W_LEN + MMI_IVC_DB_LIST_HEADER_H_LEN, MMI_IVC_DB_LIST_HEADER_IDX_LEN);
            db->list.count = mmi_ivc_db_list_atoi(header, MMI_IVC_DB_LIST_HEADER_W_LEN + MMI_IVC_DB_LIST_HEADER_H_LEN + MMI_IVC_DB_LIST_HEADER_IDX_LEN, MMI_IVC_DB_LIST_HEADER_COUNT_LEN);
        }

        if (lcdW != LCD_WIDTH || lcdH != LCD_HEIGHT ||
            MMI_IVC_DB_OPACITY < db->list.count ||
            db->list.count < db->list.idx || (MMI_IVC_DB_OPACITY > db->list.count && db->list.count != db->list.idx))
        {
            IVC_PMD_FS_CLOSE(db->list.fHdl);
            db->list.fHdl = 0;

            srv_fmgr_path_remove_filename(listFile);
            db->list.fmgrAsyncJob = srv_fmgr_async_delete(
                                        listFile,
                                        SRV_FMGR_ASYNC_FLAG_PRIORITY_BG | SRV_FMGR_ASYNC_FLAG_NO_PROGRESS,
                                        mmi_ivc_db_list_fmgr_proc,
                                        (void*)db);
            db->state = MMI_IVC_DB_STATE_INVALID;
        }
        else
            db->state = MMI_IVC_DB_STATE_OK;
    }

    OslMfree((void*)listFile);

    MMI_IVC_TRACE(
        MMI_IVC_TRACE_GROUP,
        MMI_TRC_IVC_DB_LIST_INIT,
        db->list.idx,
        db->list.count,
        db->list.fHdl,
        db->state);

    IVC_PMD_STOP("lin");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_db_list_deinit
 * DESCRIPTION
 *
 * PARAMETERS
 *  db      [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ivc_db_list_deinit(mmi_ivc_db_cntx_struct *db)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_DB_LIST_DEINIT, db->list.idx, db->list.count, db->list.fHdl, db->state);

    IVC_PMD_FS_CLOSE(db->list.fHdl);
    db->list.fHdl = 0;

    if (0 != db->list.fmgrAsyncJob)
    {
        srv_fmgr_async_abort(db->list.fmgrAsyncJob, MMI_TRUE);
        db->list.fmgrAsyncJob = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_db_list_add_record
 * DESCRIPTION
 *
 * PARAMETERS
 *  list            [?]
 *  filename        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ivc_db_list_add_record(mmi_ivc_db_list_struct *list, WCHAR *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR header[MMI_IVC_DB_LIST_HEADER_CHAR_COUNT];
    U32 write;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IVC_PMD_START("lar");

    if (MMI_IVC_DB_OPACITY > list->count)
    {
        /* The list is not full */
        list->count++;
    }
    else
    {
        U32 read;
        WCHAR oldRec[MMI_IVC_DB_LIST_RECORD_CHAR_COUNT];
        WCHAR filepath[MMI_IVC_PATH_MAX_LEN];

        IVC_PMD_FS_SEEK(
            list->fHdl,
            MMI_IVC_DB_LIST_RECORD_OFFSET + (list->idx * MMI_IVC_DB_LIST_RECORD_SIZE),
            FS_FILE_BEGIN);

        IVC_PMD_FS_READ(list->fHdl, oldRec, MMI_IVC_DB_LIST_RECORD_SIZE, &read);

        kal_wsprintf(
            filepath,
            "%w%s%w%s",
            MMI_IVC_GET_DB_FROM_LIST(list)->folderpath,
            MMI_IVC_DB_WORK_FOLDER_NAME,
            oldRec,
            MMI_IVC_DB_SUFFIX);

        FS_Delete(filepath);
    }

    IVC_PMD_FS_SEEK(
        list->fHdl,
        MMI_IVC_DB_LIST_RECORD_OFFSET + (list->idx * MMI_IVC_DB_LIST_RECORD_SIZE),
        FS_FILE_BEGIN);

    IVC_PMD_FS_WRITE(list->fHdl, filename, MMI_IVC_DB_LIST_RECORD_SIZE, &write);

    list->idx++;
    if (MMI_IVC_DB_OPACITY == list->idx)
    {
        list->idx = 0;
    }

    sprintf(header, MMI_IVC_DB_LIST_HEADER_FORMAT, LCD_WIDTH, LCD_HEIGHT, list->idx, list->count);
    IVC_PMD_FS_SEEK(list->fHdl, 0, FS_FILE_BEGIN);
    IVC_PMD_FS_WRITE(list->fHdl, header, MMI_IVC_DB_LIST_HEADER_CHAR_COUNT, &write);

    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_DB_LIST_ADD_RECORD, list->idx, list->count);

    IVC_PMD_STOP("lar");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_db_thumb_get_checkcode_from_img
 * DESCRIPTION
 *
 * PARAMETERS
 *  db              [?]
 *  fileName        [?]
 *  checkCode       [?]
 * RETURNS
 *
 *****************************************************************************/
static S32 mmi_ivc_db_thumb_get_checkcode_from_img(
    mmi_ivc_db_cntx_struct *db,
    WCHAR *fileName,
    S32 imgW,
    S32 imgH,
    CHAR *checkCode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR                   *filepath;
    FS_HANDLE               fHdl;
    FS_FileInfo             fileInfo;
    const FS_DOSDateTime    *dt;
    S32                     result = MMI_IVC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IVC_PMD_START("tcc");

    filepath = (WCHAR*)OslMalloc(MMI_IVC_PATH_BUF_SIZE);

    /* get image info */
    kal_wsprintf(filepath, "%w\\%w", db->folderpath, fileName);

    fHdl = IVC_PMD_FS_OPEN(filepath, FS_READ_ONLY);

    if (FS_NO_ERROR > fHdl)
    {
        result = MMI_IVC_ERR_FS_ERR;
    }
    else
    {
        IVC_PMD_FS_GET_INFO(fHdl, &fileInfo);
        dt = &fileInfo.DirEntry->DateTime;
        IVC_PMD_FS_CLOSE(fHdl);
        kal_sprintf(
            checkCode,
            MMI_IVC_DB_THUMB_TAIL_FORMAT,
            imgW,
            imgH,
            dt->Year1980 + 1980,
            dt->Month,
            dt->Day,
            dt->Hour,
            dt->Minute,
            dt->Second2);
    }

    OslMfree((void*)filepath);

    IVC_PMD_STOP("tcc");

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_db_thumb_encode
 * DESCRIPTION
 *
 * PARAMETERS
 *  userData        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ivc_db_thumb_encode(void *userData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ivc_db_cntx_struct  *db = (mmi_ivc_db_cntx_struct*) userData;
    WCHAR                   *filepath;
    CHAR                    checkCodeImg[MMI_IVC_DB_THUMB_TAIL_CHAR_COUNT];
    FS_HANDLE               fHdl;
    S32                     result;
    U32                     write;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == db->encode.cell)
        return;

    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_DB_THUMB_ENCODE, db->encode.idx, db->encode.cell->idx);

    filepath = (WCHAR*)OslMalloc(MMI_IVC_PATH_BUF_SIZE);

    /* if the cell is been changed */
    if (db->encode.idx == db->encode.cell->idx)
    {
        IVC_PMD_START("ten");

        /* get image info */
        result = mmi_ivc_db_thumb_get_checkcode_from_img(
            db,
            db->encode.cell->filename,
            db->encode.cell->orgW,
            db->encode.cell->orgH,
            checkCodeImg);
        if (MMI_IVC_OK == result)
        {
            /* encode layer to file */
            kal_wsprintf(
                filepath,
                "%w%s%w%s",
                db->folderpath,
                MMI_IVC_DB_WORK_FOLDER_NAME,
                db->encode.cell->filename,
                MMI_IVC_DB_SUFFIX);
            mmi_ivc_adp_cell_create_layer(db->encode.cell);
        #if defined(__MMI_IVC_DB_DEBUG__)
            gdi_layer_push_and_set_active(db->encode.cell->imgLyr);
            gdi_draw_solid_rect(0, 0, 5, 5, GDI_COLOR_GREEN);
        #endif /* defined(__MMI_IVC_DB_DEBUG__) */
            IVC_PMD_START("tel");
            gdi_image_encode_layer_to_jpeg(db->encode.cell->imgLyr, (CHAR*) filepath);
            IVC_PMD_STOP("tel");
        #if defined(__MMI_IVC_DB_DEBUG__)
            gdi_layer_pop_and_restore_active();
        #endif
            mmi_ivc_adp_cell_free_layer(db->encode.cell);

            /* write checkCode */
            fHdl = IVC_PMD_FS_OPEN(filepath, FS_READ_WRITE);
            if (FS_NO_ERROR > fHdl)
            {
                OslMfree((void*)filepath);
                return;
            }
            IVC_PMD_FS_SEEK(fHdl, 0, FS_FILE_END);
            IVC_PMD_FS_WRITE(fHdl, checkCodeImg, MMI_IVC_DB_THUMB_TAIL_CHAR_COUNT, &write);
            IVC_PMD_FS_CLOSE(fHdl);

            mmi_ivc_db_list_add_record(&db->list, db->encode.cell->filename);
        }

        MMI_IVC_FILE_IDX_RESET(db->encode.idx);

        IVC_PMD_STOP("ten");
    }

    OslMfree((void*)filepath);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_db_thumb_decode
 * DESCRIPTION
 *
 * PARAMETERS
 *  db          [?]
 *  cell        [?]
 *  path        [OUT]
 * RETURNS
 *
 *****************************************************************************/
static S32 mmi_ivc_db_thumb_decode(mmi_ivc_db_cntx_struct *db, mmi_ivc_cell_struct *cell, WCHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     result = MMI_IVC_OK;
    WCHAR   *filepath;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IVC_PMD_START("tde");

    filepath = (WCHAR*)OslMalloc(MMI_IVC_PATH_BUF_SIZE);

    do
    {
        FS_HANDLE   fHdl;
        CHAR        checkCodeImg[MMI_IVC_DB_THUMB_TAIL_CHAR_COUNT];
        CHAR        checkCodeBak[MMI_IVC_DB_THUMB_TAIL_CHAR_COUNT];
        U32         read;

        /* get thumb info */
        kal_wsprintf(
            filepath,
            "%w%s%w%s",
            db->folderpath,
            MMI_IVC_DB_WORK_FOLDER_NAME,
            cell->filename,
            MMI_IVC_DB_SUFFIX);

        fHdl = IVC_PMD_FS_OPEN(filepath, FS_READ_ONLY);

        if (FS_NO_ERROR > fHdl)
        {
            result = MMI_IVC_FAILE;
            break;
        }

        IVC_PMD_FS_SEEK(fHdl, MMI_IVC_DB_THUMB_TAIL_OFFSET_FROM_END, FS_FILE_END);
        IVC_PMD_FS_READ(fHdl, checkCodeBak, MMI_IVC_DB_THUMB_TAIL_CHAR_COUNT, &read);
        IVC_PMD_FS_CLOSE(fHdl);

        if (MMI_IVC_DB_THUMB_TAIL_CHAR_COUNT != read)
            MMI_IVC_ASSERT(0);

        /* get image info */
        result = mmi_ivc_db_thumb_get_checkcode_from_img(
            db,
            cell->filename,
            cell->orgW,
            cell->orgH,
            checkCodeImg);

        /* check if it is right */
        if (MMI_IVC_OK != result || 0 != strcmp(checkCodeImg, checkCodeBak))
        {
            FS_Delete(filepath);
            result = MMI_IVC_FAILE;
            break;
        }

        mmi_wcscpy(path, filepath);
    } while (0);

    OslMfree((void*)filepath);

    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_DB_THUMB_DECODE, result);

    IVC_PMD_STOP("tde");

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_db_create_working_folder
 * DESCRIPTION
 *
 * PARAMETERS
 *  db      [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ivc_db_create_working_folder(mmi_ivc_db_cntx_struct *db)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE   fHdl;
    WCHAR       *workFolder;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IVC_PMD_START("dcf");

    workFolder = (WCHAR*)OslMalloc(MMI_IVC_PATH_BUF_SIZE);

    kal_wsprintf(workFolder, "%w%s", db->folderpath, MMI_IVC_DB_WORK_FOLDER_NAME);

    fHdl = IVC_PMD_FS_OPEN(workFolder, FS_OPEN_DIR | FS_ATTR_HIDDEN | FS_READ_ONLY);

    if (FS_NO_ERROR > fHdl)
    {
        IVC_PMD_START("dcf");
        fHdl = srv_fmgr_fs_create_folder(workFolder);
        IVC_PMD_STOP("dcf");
        if (FS_NO_ERROR > fHdl)
            db->state = MMI_IVC_DB_STATE_INVALID;
    }
    else
        IVC_PMD_FS_CLOSE(fHdl);

    IVC_PMD_FS_SET_ATTR(workFolder, MMI_IVC_DB_WORK_FOLDER_ATTR_INIT);

    OslMfree((void*)workFolder);

    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_DB_CREATE_WORKING_FOLDER, db->state);

    IVC_PMD_STOP("dcf");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_db_pre_check
 * DESCRIPTION
 *
 * PARAMETERS
 *  db      [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ivc_db_pre_check(mmi_ivc_db_cntx_struct *db)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fHdl;
    FS_DiskInfo diskInfo;
    U32 freeSpace;
    WCHAR drv[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IVC_PMD_START("dpc");

    fHdl = IVC_PMD_FS_OPEN(db->folderpath, FS_READ_ONLY | FS_DIR_TYPE);

    do
    {
        if (FS_NO_ERROR > fHdl)
        {
            db->state = MMI_IVC_DB_STATE_INVALID;
            break;
        }
        IVC_PMD_FS_CLOSE(fHdl);

        kal_wsprintf(drv, "%c:\\", db->folderpath[0]);
        fHdl = FS_GetDiskInfo(drv, &diskInfo, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
        if (FS_NO_ERROR > fHdl)
        {
            db->state = MMI_IVC_DB_STATE_INVALID;
            break;
        }

        /* in byte */
        freeSpace = diskInfo.FreeClusters * diskInfo.SectorsPerCluster * diskInfo.BytesPerSector;
        if (MMI_IVC_DB_SPACE_LIMIT > freeSpace)
        {
            db->state = MMI_IVC_DB_STATE_INVALID;
            break;
        }

        if (MMI_IVC_DB_WORK_FOLDER_PATH_LEN < mmi_wcslen(db->folderpath) + MMI_IVC_DB_WORK_FOLDER_NAME_LEN)
        {
            db->state = MMI_IVC_DB_STATE_INVALID;
            break;
        }

        mmi_ivc_db_create_working_folder(db);
    } while (0);
    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_DB_PRE_CHECK, db->state);

    IVC_PMD_STOP("dpc");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_db_init_env
 * DESCRIPTION
 *
 * PARAMETERS
 *  db      [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ivc_db_init_env(mmi_ivc_db_cntx_struct *db)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_DB_INIT_ENV);

    /* Cause working folder will be a E:\Photos_BAK\, so, remove the '\' of E:\Photos\ */
    srv_fmgr_path_remove_slash(db->folderpath);

    db->state = MMI_IVC_DB_STATE_OK;

    mmi_ivc_db_pre_check(db);

    mmi_ivc_db_list_init(db);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_db_get_folder_cb
 * DESCRIPTION
 *
 * PARAMETERS
 *  path        [IN]
 *  userData    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ivc_db_get_folder_cb(WCHAR *path, void *userData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ivc_db_cntx_struct  *db = (mmi_ivc_db_cntx_struct*)userData;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_DB_GET_FOLDER_CB, path[0]);

    mmi_wcscpy(db->folderpath, path);

    mmi_ivc_db_init_env(db);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_db_is_valid_action
 * DESCRIPTION
 *
 * PARAMETERS
 *  ins         [?]
 *  cell        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_ivc_db_is_valid_action(mmi_ivc_instance_struct *ins, mmi_ivc_cell_struct *cell)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_IVC_DB_STATE_OK != ins->db.state)
        return MMI_FALSE;   /* DB not ready */

    if (0 == cell->filename[0])
        return MMI_FALSE;   /* Filename too long */

    if (MMI_IVC_DB_DEFAULT_CRITERIA >= cell->orgW * cell->orgH)
        return MMI_FALSE;   /* Image too small */

    if (GDI_IMAGE_TYPE_JPG_FILE != cell->imgType)
        return MMI_FALSE;   /* Not support other type */

    if (cell->flag & MMI_IVC_CELL_FLAG_DRM)
        return MMI_FALSE;   /* Not save drm file */

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_db_init
 * DESCRIPTION
 *
 * PARAMETERS
 *  ins     [?]
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ivc_db_init(mmi_ivc_instance_struct *ins)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_DB_INIT);

    ins->db.state = MMI_IVC_DB_STATE_INIT;
    ins->db.folderpath[0] = 0;
    ins->db.encode.cell = NULL;
    MMI_IVC_FILE_IDX_RESET(ins->db.encode.idx);

    mmi_ivc_adp_get_folder(ins, mmi_ivc_db_get_folder_cb, (void*)&ins->db);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_db_deinit
 * DESCRIPTION
 *
 * PARAMETERS
 *  ins     [?]
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ivc_db_deinit(mmi_ivc_instance_struct *ins)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *workFolder = (WCHAR*)OslMalloc(MMI_IVC_PATH_BUF_SIZE);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_DB_DEINIT);

    mmi_ivc_db_list_deinit(&ins->db);
    kal_wsprintf(workFolder, "%w%s", ins->db.folderpath, MMI_IVC_DB_WORK_FOLDER_NAME);
    IVC_PMD_FS_SET_ATTR(workFolder, MMI_IVC_DB_WORK_FOLDER_ATTR_DEINIT);

    OslMfree((void*)workFolder);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_db_start
 * DESCRIPTION
 *
 * PARAMETERS
 *  ins     [?]
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ivc_db_start(mmi_ivc_instance_struct *ins)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_DB_START);

    if (MMI_IVC_DB_STATE_OK != ins->db.state)
        return;

    /* Get to encode the previous unfinished job */
    gui_start_timer_ex(MMI_IVC_DB_ENCODE_TMER_DURATION, mmi_ivc_db_thumb_encode, (void*)&ins->db);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_db_stop
 * DESCRIPTION
 *
 * PARAMETERS
 *  ins     [?]
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ivc_db_stop(mmi_ivc_instance_struct *ins)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_DB_STOP);
    gui_cancel_timer((FuncPtr) mmi_ivc_db_thumb_encode);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_db_save
 * DESCRIPTION
 *
 * PARAMETERS
 *  ins         [?]
 *  cell        [?]
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ivc_db_save(mmi_ivc_instance_struct *ins, mmi_ivc_cell_struct *cell)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_DB_SAVE, cell->idx, cell->flag);

    if (MMI_FALSE == mmi_ivc_db_is_valid_action(ins, cell))
        return;

    ins->db.encode.idx = cell->idx;
    ins->db.encode.cell = cell;

    gui_start_timer_ex(MMI_IVC_DB_ENCODE_TMER_DURATION, mmi_ivc_db_thumb_encode, (void*)&ins->db);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_db_get
 * DESCRIPTION
 *
 * PARAMETERS
 *  ins         [?]
 *  cell        [?]
 *  filepath    [OUT]
 * RETURNS
 *
 *****************************************************************************/
extern S32 mmi_ivc_db_get(mmi_ivc_instance_struct *ins, mmi_ivc_cell_struct *cell, WCHAR *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_FALSE == mmi_ivc_db_is_valid_action(ins, cell))
        return MMI_IVC_FAILE;

    return mmi_ivc_db_thumb_decode(&ins->db, cell, filepath);
}


#ifdef __MMI_AP_DCM_CAMIMGV__
#pragma arm section rodata,code
#endif

#endif /* defined(__MMI_IVF_CACHE_DB__) */

