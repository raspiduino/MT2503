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
 *  AppList_video_decorder.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  AppList VLW
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
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//#ifndef __APPLIST_VIDEO_WALLPAPER_DECODER_H__
//#define __APPLIST_VIDEO_WALLPAPER_DECODER_H__

#include "ivlw_common.h"
#include "ivlw_decoder.h"
#include "lwp_decoder.h"
#include "fsal.h"
#include "fs_gprot.h"

typedef enum
{
    APP_LIST_WP_DEC_STATUS_OK,
    APP_LIST_WP_DEC_STATUS_NG,
}APP_LIST_WP_DEC_STATUS;

typedef enum
{
   APP_LIST_WP_RGB565,
   APP_LIST_WP_RGB888
}APP_LIST_WP_COLOR_FORMAT;

typedef enum
{
   APP_LIST_WP_READ_FILE_SYNC = 0,
   APP_LIST_WP_READ_FILE_ASYNC,
   APP_LIST_WP_READ_FILE_RSVD

}APP_LIST_WP_READ_FILE_MODE_ENUM;

typedef void (*app_list_wallpaper_async_get_frame_callback)(APP_LIST_WP_DEC_STATUS error_code, void *callback_para);
typedef IVLW_DECODER_HANDLE APP_LIST_WP_DECODER_HANDLE;

extern int applistwallpaperDecGetTypeFromFileName(WCHAR* fileName);

extern void applistwallpaperDecSetType(int useABM);

extern APP_LIST_WP_DEC_STATUS applistwallpaperDecGetHandle(APP_LIST_WP_DECODER_HANDLE** handlePtr);

extern APP_LIST_WP_DEC_STATUS applistwallpaperDecReleaseHandle(APP_LIST_WP_DECODER_HANDLE** handle);

extern APP_LIST_WP_DEC_STATUS applistwallpaperDecSetSrcFile(APP_LIST_WP_DECODER_HANDLE* handle, STFSAL *fp);

APP_LIST_WP_DEC_STATUS
applistwallpaperDecSetAllocAndFree(
   APP_LIST_WP_DECODER_HANDLE* handle,
   alloc_func alloc_func,
   free_func free_func);

APP_LIST_WP_DEC_STATUS
applistwallpaperDecQuerySrcResolution(
   APP_LIST_WP_DECODER_HANDLE* handle,
   unsigned int* width,
   unsigned int* height);

APP_LIST_WP_DEC_STATUS
applistwallpaperDecQuerySrcFormat(
   APP_LIST_WP_DECODER_HANDLE* handle,
   APP_LIST_WP_COLOR_FORMAT *colorFormat);


APP_LIST_WP_DEC_STATUS
applistwallpaperDecSetDstFormat(
   APP_LIST_WP_DECODER_HANDLE* handle,
   APP_LIST_WP_COLOR_FORMAT colorFormat);

APP_LIST_WP_DEC_STATUS
applistwallpaperDecQueryFrameCount(
   APP_LIST_WP_DECODER_HANDLE* handle,
   unsigned int *frameCnt);

APP_LIST_WP_DEC_STATUS
applistwallpaperDecQueryPartitionCount(
   APP_LIST_WP_DECODER_HANDLE* handle,
   unsigned int *partitionCnt);

APP_LIST_WP_DEC_STATUS
applistwallpaperDecQueryPartitionInfo(
   APP_LIST_WP_DECODER_HANDLE* handle,
   unsigned int partitionIdx,
   unsigned int *frame_count,
   unsigned int *frame_start_index);

APP_LIST_WP_DEC_STATUS
applistwallpaperDecQuerySrcFrameBufSize(
   APP_LIST_WP_DECODER_HANDLE* handle,
   unsigned int frame_index,
   unsigned int *buf_size);

//APP_LIST_WP_DEC_STATUS
//vapp_wallpaperDecQueryDstFrameBufSize(
//   APP_LIST_WP_DECODER_HANDLE* handle,
//   unsigned int *buf_size);

APP_LIST_WP_DEC_STATUS
applistwallpaperDecQueryFrameHeaderLength(
   APP_LIST_WP_DECODER_HANDLE* handle,
   unsigned int *frame_header_len);

APP_LIST_WP_DEC_STATUS
applistwallpaperDecGetFrameSrcBuf(
   APP_LIST_WP_DECODER_HANDLE *handle,
   APP_LIST_WP_READ_FILE_MODE_ENUM read_mode,
   unsigned int frame_index,
   unsigned char* src_buf,
   unsigned int src_buf_size,
   unsigned int *actual_rd_size,
   app_list_wallpaper_async_get_frame_callback  callback,
   void *param);

APP_LIST_WP_DEC_STATUS
applistwallpaperDecAbortGetFrameSrcBuf(
   APP_LIST_WP_DECODER_HANDLE *handle);

APP_LIST_WP_DEC_STATUS
applistwallpaperDecGetFramePixelData(
   APP_LIST_WP_DECODER_HANDLE *handle,
   unsigned char* src_buf,
   unsigned int src_buf_size,
   unsigned char* dstBuf,
   unsigned int dst_buf_size);

//#endif //__VAPP_WP_DECODER_H__

