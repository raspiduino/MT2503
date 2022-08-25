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
 *  AppList_video_decorder.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  AppList Video Decorder
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "AppList_video_decorder.h"
#include "MMIDataType.h"
#include "FileMgrSrvGprot.h"

#define APPLIST_IVLW_ABM_WORKAROUND
#if defined(APPLIST_IVLW_ABM_WORKAROUND)
#include "gdi_image_alpha_bmp_v2.h"

static IVLW_DEC_STATUS AppList_ivlwAB2Decode(
   IVLW_DECODER_HANDLE *handle,
   unsigned char* src_buf,
   unsigned int src_buf_size,
   unsigned char* dstBuf,
   unsigned int dst_buf_size)
{
   int ret = 0;
   gdi_image_ab2_info_struct info;
   gdi_image_ab2_img_buf_struct img_buf;

   gdi_image_ab2_read_header(&info, src_buf);
   img_buf.pixel_bytes = 2;
   img_buf.cf = GDI_COLOR_FORMAT_16;
   if (IVLW_COLOR_RGB888 == handle->output_format)
   {
      img_buf.pixel_bytes = 3;
      img_buf.cf = GDI_COLOR_FORMAT_24;
   }
   img_buf.ptr = (U8 *)dstBuf;
   img_buf.pitch_bytes = info.width * img_buf.pixel_bytes;

   /* gdi_image_ab2_draw_to_buf_internal
     ** This function will process BMP R/B channel swap. Thus for AB2 encoder part,
     ** we don't need to do R/B channel swap. Otherwise, the output result will be wrong.
     */
   ret = gdi_image_ab2_draw_to_buf_decode_mode(&img_buf,
                              0, 0, src_buf,
                              GDI_IMAGE_AB2_DECODE_MODE_OUTPUT);
   if (GDI_SUCCEED != ret)
   {
      return IVLW_DEC_STATUS_FAIL;
   }
   return IVLW_DEC_STATUS_OK;
}
#endif

static int AppList_use_abm = 0;
app_list_wallpaper_async_get_frame_callback applist_ivlw_fs_cb;

extern int applistwallpaperDecGetTypeFromFileName(WCHAR* fileName)
{
    WCHAR *ext = (WCHAR*)srv_fmgr_path_get_extension_ptr((WCHAR*)fileName);
    if(0 == mmi_ucs2nicmp((CHAR*)ext, (CHAR*)L"mwp", 3) ||
       0 == mmi_ucs2nicmp((CHAR*)ext, (CHAR*)L"ivlw", 3) ||
       0 == mmi_ucs2nicmp((CHAR*)ext, (CHAR*)L"rwp", 3))
    {
        return 1;
    }
    else if(0 == mmi_ucs2nicmp((CHAR*)ext, (CHAR*)L"lwp", 3))
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

extern void applistwallpaperDecSetType(int useABM)
{
    AppList_use_abm = useABM;
}

static IVLW_COLOR_FORMAT getIVLWColorFormat(APP_LIST_WP_COLOR_FORMAT wpFormat)
{
    switch(wpFormat)
    {
    case APP_LIST_WP_RGB565:
        return IVLW_COLOR_RGB565;
    case APP_LIST_WP_RGB888:
        return IVLW_COLOR_RGB888;
    default:
        ASSERT(0);
        return IVLW_COLOR_RGB565;
    }
}


static IVLW_FILE_ACCESS_MODE_ENUM getIVLWFileMode(APP_LIST_WP_READ_FILE_MODE_ENUM mode)
{
    switch(mode)
    {
    case APP_LIST_WP_READ_FILE_SYNC:
        return IVLW_READ_FILE_SYNC;
    case APP_LIST_WP_READ_FILE_ASYNC:
        return IVLW_READ_FILE_ASYNC;
    case APP_LIST_WP_READ_FILE_RSVD:
        return IVLW_READ_FILE_RSVD;
    default:
        ASSERT(0);
        return IVLW_READ_FILE_SYNC;
    }
}

static LWP_READ_FILE_MODE_ENUM getLWPFileMode(APP_LIST_WP_READ_FILE_MODE_ENUM mode)
{
    switch(mode)
    {
    case APP_LIST_WP_READ_FILE_SYNC:
        return LWP_READ_FILE_SYNC;
    case APP_LIST_WP_READ_FILE_ASYNC:
        return LWP_READ_FILE_ASYNC;
    case APP_LIST_WP_READ_FILE_RSVD:
        return LWP_READ_FILE_RSVD;
    default:
        ASSERT(0);
        return LWP_READ_FILE_SYNC;
    }
}

void applist_async_get_frame_callback(IVLW_DEC_STATUS error_code, void *callback_para)
{
    if (NULL == applist_ivlw_fs_cb)
    {
       return;
    }

    if(AppList_use_abm)
    {
        if(error_code != IVLW_DEC_STATUS_OK)
            applist_ivlw_fs_cb(APP_LIST_WP_DEC_STATUS_NG, callback_para);
        else
            applist_ivlw_fs_cb(APP_LIST_WP_DEC_STATUS_OK, callback_para);
    }
    else
    {
        if(error_code != LWP_STATUS_OK)
            applist_ivlw_fs_cb(APP_LIST_WP_DEC_STATUS_NG, callback_para);
        else
            applist_ivlw_fs_cb(APP_LIST_WP_DEC_STATUS_OK, callback_para);
    }
}

APP_LIST_WP_DEC_STATUS applistwallpaperDecGetHandle(APP_LIST_WP_DECODER_HANDLE** handlePtr)
{
    if(AppList_use_abm)
    {

        IVLW_DEC_STATUS ret = ivlwDecGetHandle(handlePtr);

    #if defined(APPLIST_IVLW_ABM_WORKAROUND)
        if(ret != IVLW_DEC_STATUS_OK)
            return APP_LIST_WP_DEC_STATUS_NG;

        ret = ivlwDecSetDecodeFunc(*handlePtr, AppList_ivlwAB2Decode);
    #endif

        if(ret != IVLW_DEC_STATUS_OK)
            return APP_LIST_WP_DEC_STATUS_NG;
        else
            return APP_LIST_WP_DEC_STATUS_OK;

    }
    else
    {

        LWP_DEC_STATUS ret = lwpDecGetHandle((LWP_DECODER_HANDLE **)handlePtr);

        if(ret != LWP_STATUS_OK)
            return APP_LIST_WP_DEC_STATUS_NG;
        else
            return APP_LIST_WP_DEC_STATUS_OK;

    }
}

APP_LIST_WP_DEC_STATUS applistwallpaperDecReleaseHandle(APP_LIST_WP_DECODER_HANDLE** handle)
{
    if(AppList_use_abm)
    {
        IVLW_DEC_STATUS ret = ivlwDecReleaseHandle(handle);

        if(ret != IVLW_DEC_STATUS_OK)
            return APP_LIST_WP_DEC_STATUS_NG;
        else
            return APP_LIST_WP_DEC_STATUS_OK;

    }
    else
    {
        LWP_DEC_STATUS ret = lwpDecReleaseHandle((LWP_DECODER_HANDLE **)handle);

        if(ret != LWP_STATUS_OK)
            return APP_LIST_WP_DEC_STATUS_NG;
        else
            return APP_LIST_WP_DEC_STATUS_OK;
    }
}

APP_LIST_WP_DEC_STATUS applistwallpaperDecSetSrcFile(APP_LIST_WP_DECODER_HANDLE* handle, STFSAL *fp)
{
    if(AppList_use_abm)
    {
        IVLW_DEC_STATUS ret = ivlwDecSetSrcFile(handle,fp);

        if(ret != IVLW_DEC_STATUS_OK)
            return APP_LIST_WP_DEC_STATUS_NG;
        else
            return APP_LIST_WP_DEC_STATUS_OK;

    }
    else
    {

        LWP_DEC_STATUS ret = lwpDecSetSrcFile((LWP_DECODER_HANDLE *)handle,fp);

        if(ret != LWP_STATUS_OK)
            return APP_LIST_WP_DEC_STATUS_NG;
        else
            return APP_LIST_WP_DEC_STATUS_OK;
    }
}

APP_LIST_WP_DEC_STATUS applistwallpaperDecSetAllocAndFree(APP_LIST_WP_DECODER_HANDLE* handle, alloc_func alloc_func, free_func free_func)
{
    if(AppList_use_abm)
    {
        IVLW_DEC_STATUS ret = ivlwDecSetAllocAndFree(handle,alloc_func,free_func);

        if(ret != IVLW_DEC_STATUS_OK)
            return APP_LIST_WP_DEC_STATUS_NG;
        else
            return APP_LIST_WP_DEC_STATUS_OK;

    }
    else
    {
        LWP_DEC_STATUS ret = lwpDecSetAllocAndFree((LWP_DECODER_HANDLE *)handle,alloc_func,free_func);

        if(ret != LWP_STATUS_OK)
            return APP_LIST_WP_DEC_STATUS_NG;
        else
            return APP_LIST_WP_DEC_STATUS_OK;
    }
}

APP_LIST_WP_DEC_STATUS applistwallpaperDecQuerySrcResolution(APP_LIST_WP_DECODER_HANDLE* handle, unsigned int* width, unsigned int* height)
{
    if(AppList_use_abm)
    {
        IVLW_DEC_STATUS ret = ivlwDecQuerySrcResolution(handle,width,height);

        if(ret != IVLW_DEC_STATUS_OK)
            return APP_LIST_WP_DEC_STATUS_NG;
        else
            return APP_LIST_WP_DEC_STATUS_OK;

    }
    else
    {
        LWP_DEC_STATUS ret = lwpDecQuerySrcResolution((LWP_DECODER_HANDLE *)handle,width,height);

        if(ret != LWP_STATUS_OK)
            return APP_LIST_WP_DEC_STATUS_NG;
        else
            return APP_LIST_WP_DEC_STATUS_OK;
    }
}

APP_LIST_WP_DEC_STATUS applistwallpaperDecQuerySrcFormat(APP_LIST_WP_DECODER_HANDLE* handle, APP_LIST_WP_COLOR_FORMAT *colorFormat)
{
    if(AppList_use_abm)
    {
        (*colorFormat) = APP_LIST_WP_RGB565;

        return APP_LIST_WP_DEC_STATUS_OK;

    }
    else
    {
        LWP_DEC_STATUS ret = lwpDecQuerySrcFormat((LWP_DECODER_HANDLE *)handle, colorFormat);

        if(ret != LWP_STATUS_OK)
            return APP_LIST_WP_DEC_STATUS_NG;
        else
            return APP_LIST_WP_DEC_STATUS_OK;
    }
}

APP_LIST_WP_DEC_STATUS applistwallpaperDecSetDstFormat(APP_LIST_WP_DECODER_HANDLE* handle, APP_LIST_WP_COLOR_FORMAT colorFormat)
{
    if(AppList_use_abm)
    {
        IVLW_DEC_STATUS ret = ivlwDecSetDstFormat(handle, getIVLWColorFormat(colorFormat));

        if(ret != IVLW_DEC_STATUS_OK)
            return APP_LIST_WP_DEC_STATUS_NG;
        else
            return APP_LIST_WP_DEC_STATUS_OK;

    }
    else
    {
        return APP_LIST_WP_DEC_STATUS_OK;
    }
}


APP_LIST_WP_DEC_STATUS applistwallpaperDecQueryFrameCount(APP_LIST_WP_DECODER_HANDLE* handle, unsigned int *frameCnt)
{
    if(AppList_use_abm)
    {
        IVLW_DEC_STATUS ret = ivlwDecQueryFrameCount(handle, frameCnt);

        if(ret != IVLW_DEC_STATUS_OK)
            return APP_LIST_WP_DEC_STATUS_NG;
        else
            return APP_LIST_WP_DEC_STATUS_OK;

    }
    else
    {
        LWP_DEC_STATUS ret = lwpDecQueryFrameCount((LWP_DECODER_HANDLE *)handle, frameCnt);

        if(ret != LWP_STATUS_OK)
            return APP_LIST_WP_DEC_STATUS_NG;
        else
            return APP_LIST_WP_DEC_STATUS_OK;
    }
}


APP_LIST_WP_DEC_STATUS applistwallpaperDecQueryPartitionCount(APP_LIST_WP_DECODER_HANDLE* handle, unsigned int *partitionCnt)
{
    if(AppList_use_abm)
    {
        IVLW_DEC_STATUS ret = ivlwDecQueryPartitionCount(handle, partitionCnt);

        if(ret != IVLW_DEC_STATUS_OK)
            return APP_LIST_WP_DEC_STATUS_NG;
        else
            return APP_LIST_WP_DEC_STATUS_OK;

    }
    else
    {
        (*partitionCnt) = 1;

        return APP_LIST_WP_DEC_STATUS_OK;
    }
}

APP_LIST_WP_DEC_STATUS applistwallpaperDecQueryPartitionInfo(APP_LIST_WP_DECODER_HANDLE* handle, unsigned int partitionIdx, unsigned int *frame_count, unsigned int *frame_start_index)
{
    if(AppList_use_abm)
    {
        IVLW_DEC_STATUS ret = ivlwDecQueryPartitionInfo(handle, partitionIdx, frame_count, frame_start_index);

        if(ret != IVLW_DEC_STATUS_OK)
            return APP_LIST_WP_DEC_STATUS_NG;
        else
            return APP_LIST_WP_DEC_STATUS_OK;

    }
    else
    {
        LWP_DEC_STATUS ret = lwpDecQueryFrameCount((LWP_DECODER_HANDLE *)handle, frame_count);

        (*frame_start_index) = 0;

        if(ret != IVLW_DEC_STATUS_OK)
            return APP_LIST_WP_DEC_STATUS_NG;
        else
            return APP_LIST_WP_DEC_STATUS_OK;
    }
}

APP_LIST_WP_DEC_STATUS applistwallpaperDecQuerySrcFrameBufSize(APP_LIST_WP_DECODER_HANDLE* handle, unsigned int frame_index, unsigned int *buf_size)
{
    if(AppList_use_abm)
    {
        IVLW_DEC_STATUS ret = ivlwDecQuerySrcFrameBufSize(handle, frame_index, buf_size);

        if(ret != IVLW_DEC_STATUS_OK)
            return APP_LIST_WP_DEC_STATUS_NG;
        else
            return APP_LIST_WP_DEC_STATUS_OK;

    }
    else
    {
        LWP_DEC_STATUS ret = lwpDecQuerySrcFrameBufSize((LWP_DECODER_HANDLE *)handle, frame_index, buf_size);

        if(ret != IVLW_DEC_STATUS_OK)
            return APP_LIST_WP_DEC_STATUS_NG;
        else
            return APP_LIST_WP_DEC_STATUS_OK;
    }
}

APP_LIST_WP_DEC_STATUS applistwallpaperDecQueryFrameHeaderLength(APP_LIST_WP_DECODER_HANDLE* handle, unsigned int *frame_header_len)
{
    if(AppList_use_abm)
    {
        IVLW_DEC_STATUS ret = ivlwDecQueryFrameHeaderLength(handle, frame_header_len);

        if(ret != IVLW_DEC_STATUS_OK)
            return APP_LIST_WP_DEC_STATUS_NG;
        else
            return APP_LIST_WP_DEC_STATUS_OK;

    }
    else
    {
        LWP_DEC_STATUS ret = lwpDecQueryFrameHeaderLength((LWP_DECODER_HANDLE *)handle, frame_header_len);

        if(ret != IVLW_DEC_STATUS_OK)
            return APP_LIST_WP_DEC_STATUS_NG;
        else
            return APP_LIST_WP_DEC_STATUS_OK;
    }
}


APP_LIST_WP_DEC_STATUS
applistwallpaperDecGetFrameSrcBuf(
   APP_LIST_WP_DECODER_HANDLE *handle,
   APP_LIST_WP_READ_FILE_MODE_ENUM read_mode,
   unsigned int frame_index,
   unsigned char* src_buf,
   unsigned int src_buf_size,
   unsigned int *actual_rd_size,
   app_list_wallpaper_async_get_frame_callback  callback,
   void *param)
{
    if(AppList_use_abm)
    {
        IVLW_DEC_STATUS ret;

        applist_ivlw_fs_cb = callback;
        ret = ivlwDecGetFrameSrcBuf(
                    handle,
                    getIVLWFileMode(read_mode),
                    frame_index,
                    src_buf,
                    src_buf_size,
                    actual_rd_size,
                    applist_async_get_frame_callback,
                    param);

        if(ret != IVLW_DEC_STATUS_OK)
            return APP_LIST_WP_DEC_STATUS_NG;
        else
            return APP_LIST_WP_DEC_STATUS_OK;

    }
    else
    {
        LWP_DEC_STATUS ret;

        applist_ivlw_fs_cb = callback;
        ret = lwpDecGetFrameSrcBuf(
                    (LWP_DECODER_HANDLE *)handle,
                    getLWPFileMode(read_mode),
                    frame_index,
                    src_buf,
                    src_buf_size,
                    actual_rd_size,
                    applist_async_get_frame_callback,
                    param);

        if(ret != IVLW_DEC_STATUS_OK)
            return APP_LIST_WP_DEC_STATUS_NG;
        else
            return APP_LIST_WP_DEC_STATUS_OK;
    }
}

APP_LIST_WP_DEC_STATUS
applistwallpaperDecAbortGetFrameSrcBuf(
   APP_LIST_WP_DECODER_HANDLE *handle)
{
    IVLW_DEC_STATUS ret = IVLW_DEC_STATUS_OK;
    if(AppList_use_abm)
    {
        ret = ivlwDecAbortGetFrameSrcBuf(handle);
        if(ret != IVLW_DEC_STATUS_OK)
            return APP_LIST_WP_DEC_STATUS_NG;
        else
            return APP_LIST_WP_DEC_STATUS_OK;
    }
    else
    {
        return APP_LIST_WP_DEC_STATUS_OK;
    }
}


APP_LIST_WP_DEC_STATUS
applistwallpaperDecGetFramePixelData(
   APP_LIST_WP_DECODER_HANDLE *handle,
   unsigned char* src_buf,
   unsigned int src_buf_size,
   unsigned char* dstBuf,
   unsigned int dst_buf_size)
{
    if(AppList_use_abm)
    {
        IVLW_DEC_STATUS ret = ivlwDecGetFramePixelData(
                                    handle,
                                    src_buf,
                                    src_buf_size,
                                    dstBuf,
                                    dst_buf_size);

        if(ret != IVLW_DEC_STATUS_OK)
            return APP_LIST_WP_DEC_STATUS_NG;
        else
            return APP_LIST_WP_DEC_STATUS_OK;

    }
    else
    {
        LWP_DEC_STATUS ret = lwpDecGetFramePixelData(
                                    (LWP_DECODER_HANDLE *)handle,
                                    src_buf,
                                    src_buf_size,
                                    dstBuf,
                                    dst_buf_size);

        if(ret != IVLW_DEC_STATUS_OK)
            return APP_LIST_WP_DEC_STATUS_NG;
        else
            return APP_LIST_WP_DEC_STATUS_OK;
    }
}

