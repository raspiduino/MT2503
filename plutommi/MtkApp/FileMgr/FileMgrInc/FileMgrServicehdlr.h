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

/*******************************************************************************
 * Filename:
 * ---------
 *  FileManagerDef.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  File Manager internal prototype header.
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *==============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#if defined (__MMI_FILE_MANAGER__)

#ifndef _FMGR_SERVICE_HDLR_H_
#define _FMGR_SERVICE_HDLR_H_



/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "FileMgrGProt.h"
#include "kal_general_types.h"
    

/****************************************************************************
* Define
*****************************************************************************/


/********************************** Macro **********************************/


/********************************** Enum  **********************************/


/********************************* Typedef ********************************/


/****************************************************************************
* Global variable
*****************************************************************************/


/****************************************************************************
* Internal Function
*****************************************************************************/

#ifndef __MMI_SLIM_FILE_MANAGER__
extern void mmi_fmgr_forward_2d_media_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
extern void mmi_fmgr_forward_phb_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
#endif
extern void mmi_fmgr_forward_profile_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
extern void mmi_fmgr_forward_bgsound_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
extern void mmi_fmgr_forward_totolist_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
extern void mmi_fmgr_forward_sms_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
//extern void mmi_fmgr_forward_mms_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
extern void mmi_fmgr_forward_email_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
#ifndef __MMI_SLIM_FILE_MANAGER__
extern void mmi_fmgr_forward_peripheral_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
#endif
extern void mmi_fmgr_option_audio_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
extern void mmi_fmgr_option_image_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
extern void mmi_fmgr_option_imgviewer_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
extern void mmi_fmgr_option_mediaview_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
extern void mmi_fmgr_empty_option_imgviewer_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
extern void mmi_fmgr_option_bookmark_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
extern void mmi_fmgr_option_vbookmark_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
#ifdef __MMI_VIDEO_PLAYER__
extern void mmi_vdoply_file_option_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
extern void mmi_vdoply_empty_option_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
#endif





#if defined(__MMI_JAVA_FMGR_HYPERLINK__)
extern MMI_BOOL mmi_java_fmgr_hyperlink_callback(U16 app_id, S8* path, fmgr_hyperlink_action_enum action, S32 para, S32* result);
#endif

#if defined(__MMI_MY_FAVORITE_IMAGES_HYPERLINK__)
extern MMI_BOOL mmi_images_hyperlink_callback(U16 app_id, S8* path, fmgr_hyperlink_action_enum action, S32 para, S32* result);
#endif

#if defined(__MMI_MY_FAVORITE_AUDIO_HYPERLINK__)
extern MMI_BOOL mmi_audio_hyperlink_callback(U16 app_id, S8* path, fmgr_hyperlink_action_enum action, S32 para, S32* result);
#endif

#if defined(__MMI_MY_FAVORITE_VIDEO_HYPERLINK__)
extern MMI_BOOL mmi_video_hyperlink_callback(U16 app_id, S8* path, fmgr_hyperlink_action_enum action, S32 para, S32* result);
#endif

#if defined(__MMI_MY_FAVORITE_MMSBOX_HYPERLINK__)
extern MMI_BOOL mmi_mmsbox_hyperlink_callback(U16 app_id, S8* path, fmgr_hyperlink_action_enum action, S32 para, S32* result);
#endif

#if defined(__MMI_MY_FAVORITE_SWFLASH_HYPERLINK__)
extern MMI_BOOL mmi_swflash_hyperlink_callback(U16 app_id, S8* path, fmgr_hyperlink_action_enum action, S32 para, S32* result);
#endif

#if defined(__MMI_MY_FAVORITE_THEME_HYPERLINK__)
extern MMI_BOOL mmi_theme_hyperlink_callback(U16 app_id, S8* path, fmgr_hyperlink_action_enum action, S32 para, S32* result);
#endif

#if defined(__MMI_MY_FAVORITE_OTHERS_HYPERLINK__)
extern MMI_BOOL mmi_others_hyperlink_callback(U16 app_id, S8* path, fmgr_hyperlink_action_enum action, S32 para, S32* result);
#endif

/****************************************************************************
* Global Function
*****************************************************************************/

#ifdef __MMI_IMAGE_VIEWER__
void mmi_fmgr_image_print_by_imgviewer(S8* filepath, U16 icon_id);
#endif

#if defined(__MMI_FMGR_MULTI_SELECT_SUPPORT__) && defined(__MMI_OPP_SUPPORT__)
void mmi_fmgr_bt_multi_send(U32 msa_id);
#endif


#endif /* _FMGR_SERVICE_HDLR_H_ */

#endif /* #if defined (__MMI_FILE_MANAGER__) */

