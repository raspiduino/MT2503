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
 *  ImgViewerGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  External API of Imageviewer App.
 *
 * Author:
 * -------
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

#ifndef _IMG_VIEWER_GPROT_H_
#define _IMG_VIEWER_GPROT_H_

#include "MMI_features.h"

#include "kal_general_types.h"
#include "stack_config.h"
#include "gui_data_types.h"
#include "mmi_frm_events_gprot.h"
#include "FileMgrType.h"
#include "FileMgrSrvGProt.h"
#include "MMIDataType.h"
#include "mmi_rp_file_type_def.h"

//Image Viewer DCM header file
#if defined (__DCM_WITH_COMPRESSION_MMI_AP__) && defined(__MTK_TARGET__)
#include "MMI_ap_dcm_config.h"
#endif

    /* reset imageviewr */
#ifndef __MMI_IMAGE_VIEWER_EX__

#if defined(__MMI_IMAGE_VIEWER__)
#define MMI_MEDIA_INVALID_STORAGE   0xFFFF
#define MMI_MEDIA_MAX_PATH_LEN      50

#define __MMI_IV_ULTRA_SLIM__

/*****************************************************************************
 * FUNCTION
 *    mmi_imgview_launch
 * DESCRIPTION
 *  launch image viewer application to view an all image filelist.
 * PARAMETERS
 *
 * RETURNS
 *  MMI_ID.
 *****************************************************************************/
extern void mmi_imgview_launch(void);


/*****************************************************************************
 * FUNCTION
 *    mmi_imgview_simple_launch
 * DESCRIPTION
 *  simple wrapper for cui.
 * PARAMETERS
 *
 * RETURNS
 *  MMI_ID.
 *****************************************************************************/
extern void mmi_imgview_simple_launch(PS8 file_path, U16 string, U16 icon);


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_get_storage
 * DESCRIPTION
 *  Get imageview active storage path
 * PARAMETERS
 *  
 * RETURNS
 *  drv letter on success
 *  MMI_MEDIA_INVALID_STORAGE on fail.
 *  
 *****************************************************************************/
extern U16 mmi_imgview_get_storage(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_set_storage
 * DESCRIPTION
 *  set @drv as active drv and create image folder.
 * PARAMETERS
 *  drv     : [IN] drive letter
 * RETURNS
 *  success : FS_NO_ERROR
 *  
 *****************************************************************************/
extern S32 mmi_imgview_set_storage(U16 drv);

/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_get_storage_file_path
 * DESCRIPTION
 *  get image folder.
 * PARAMETERS
 *  drv     : [IN] drive letter
 * RETURNS
 *  success : FS_NO_ERROR
 *  
 *****************************************************************************/
extern S32 mmi_imgview_get_storage_file_path(WCHAR *filepath);

extern BOOL mmi_imgview_is_storage_ready(void);

extern void mmi_imgview_show_img_info(MMI_ID parent_gid, const WCHAR *filepath);

extern void mmi_imgview_init_img_filter(FMGR_FILTER *filter);

extern void mmi_imgview_adjust_resize_size(U16 type, S32 *width, S32 *height);

/* 
 * Compatible APIs 
 */

typedef enum
{
    MMI_IMGVIEW_PRINT_NONE = 0,
    MMI_IMGVIEW_PRINT_PICTBRIDGE = 0x0001,
    MMI_IMGVIEW_PRINT_BPP = 0x0002,
    MMI_IMGVIEW_PRINT_ANY_METHOD = 0xFFFF
} mmi_imgview_print_method_enum;

extern BOOL mmi_imgview_is_image_type_printable(
                filetypes_file_type_enum image_type,
                mmi_imgview_print_method_enum method);

#define mmi_imgview_load_setting()
#define mmi_imgview_set_storage_not_ready()
#define mmi_imgview_set_storage_ready()
#define mmi_imgview_del_scr_callback(a)
#define mmi_imgview_select_drive_callback(a)
#define mmi_imgview_set_rotate(rot)

#ifdef __MMI_SNS_PHOTO_UPLOAD__
extern MMI_BOOL mmi_iv_sns_photo_upload_check(const WCHAR* filepath);
#endif /* __MMI_SNS_PHOTO_UPLOAD__ */

#endif /* defined(__MMI_IMAGE_VIEWER__) */ 
#endif /* __MMI_IMAGE_VIEWER_EX__ */ 

#endif /* _IMG_VIEWER_GPROT_H_ */ 

