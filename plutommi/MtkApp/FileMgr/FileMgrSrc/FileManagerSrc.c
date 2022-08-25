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
 *  Modification Notice:
 *  --------------------------
 *  This software is modified by MediaTek Inc. and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   FileManagerSrc.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   File Manager Utility 
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * add a new api:mmi_fmgr_get_file_info_by_path
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * add usb storage string 1-4.
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * check_width & check_height !=0 , then get dimention.
 *
 * removed!
 * removed!
 * delete screen when re-entry fmgr via sel drv
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * add check memory not enough case and add a new string: STR_ID_FMGR_MEMORY_NOT_ENOUGH
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * DRM_close_file in mmi_fmgr_util_file_limit_check()
 *
 * removed!
 * removed!
 * check width and height of image and file is existed or not.
 *
 * removed!
 * removed!
 * check !(file_info.attribute & FS_ATTR_DIR) to append \ for multi part odf in mmi_fmgr_append_file_name()
 *
 * removed!
 * removed!
 * check both the ".odf" & ."ODF".
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * check drive_count==0 then display empty and return to ap in mmi_fmgr_disp_sel_drv_scr()
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * add __MMI_PURE_AUDIO__ support
 *
 * removed!
 * removed!
 * #include "ProfilesEnum.h" -> #include "UserProfilesResDef.h"
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Add DRM related error code's strings.
 *
 * removed!
 * removed!
 * Add DRM related error code's strings.
 *
 * removed!
 * removed!
 * add jump=5 in mmi_fmgr_util_file_limit_check() for video file.
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Add fmgr_p->app_icon to keep application's icon.
 *
 * removed!
 * removed!
 * use the macr: FS_MINIMUM_ERROR_CODE to check the fs error code.
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Fix compile warning
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Rollback set scr_ap_id when sel_drv_and_enter
 *
 * removed!
 * removed!
 * Add fmgr_reset_app_select() in sel_drv_and_enter() this way.
 *
 * removed!
 * removed!
 * replace the string of FS_ERROR_RESERVED to STR_GLOBAL_DRM_PROHIBITED
 *
 * removed!
 * removed!
 * Modify mmi_fmgr_util_limit_check.
 *
 * removed!
 * removed!
 * set app id in  mmi_fmgr_sel_drv_and_enter()
 *
 * removed!
 * removed!
 * Add string id to mapping DRM Error code.
 *
 * removed!
 * removed!
 * Mflash support.
 *
 * removed!
 * removed!
 * Add a new string for DRM process error.
 *
 * removed!
 * removed!
 * modify mmi_fmgr_get_file_group to meet DRM2.0
 *
 * removed!
 * removed!
 * Add icon id in select drive screen.
 *
 * removed!
 * removed!
 * Add trace of error code in FS, and return a default error string.
 *
 * removed!
 * removed!
 * Fix compile error.
 *
 * removed!
 * removed!
 * drm 2.0 support
 *
 * removed!
 * removed!
 * Support DRM2.0
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * DRM 2.0 support
 *
 * removed!
 * removed!
 * DRM 2.0 support
 *
 * removed!
 * removed!
 * Add compile option for fix compile error.
 *
 * removed!
 * removed!
 * Add DRM error code's global string in FsErrorTable
 *
 * removed!
 * removed!
 * rollback mmi_fmgr_disp_sel_drv_scr() to solve DRM2.0 check-in side effect.
 *
 * removed!
 * removed!
 * DRM2.0 support.
 *
 * removed!
 * removed!
 * Modify the compile option: MUSICAM_DECODE
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * Check FS_FILE_NOT_FOUND in mmi_fmgr_get_file_group()
 *
 * removed!
 * removed!
 * add check the extent file name len > 0 in mmi_fmgr_get_file_type().
 *
 * removed!
 * removed!
 * Remove #include "FileSystemDef.h".
 *
 * removed!
 * removed!
 * Remove compile option: MMI_ON_HARDWARE_P & MMI_ON_WIN32
 *
 * removed!
 * removed!
 * Add new invalid check ".aa" in mmi_fmgr_is_filename_valid()
 *
 * removed!
 * removed!
 * Add new invalid check ".aa" in mmi_fmgr_is_filename_valid()
 *
 * removed!
 * removed!
 * add 2 more video file check in mmi_fmgr_util_file_limit_check() <MPG & 3G2>
 *
 * removed!
 * removed!
 * Add MP2 file type support.
 *
 * removed!
 * removed!
 * Modify the compile option of M4A file type.
 *
 * removed!
 * removed!
 * Modify the check of highlight in mmi_fmgr_disp_sel_drv_scr()
 *
 * removed!
 * removed!
 * Modify the policy of mmi_fmgr_get_file_type().
 *
 * removed!
 * removed!
 * modify the policy of checking highlight in mmi_fmgr_disp_sel_drv_scr().
 *
 * removed!
 * removed!
 * Modify the parameter of mmi_ucs2ncpy().
 *
 * removed!
 * removed!
 * Add New API: mmi_fmgr_is_filename_valid()
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Fix Compile warnning in W07.05
 *
 * removed!
 * removed!
 * Check the highlight index!=DRM_OBJ when sel_drv_and_enter.
 *
 * removed!
 * removed!
 * Modify the sub wallpaper limitation size from 150K to 10K.
 *
 * removed!
 * removed!
 * Add SIM+ Prefer storage Support.
 *
 * removed!
 * removed!
 * Add new API: mmi_fmgr_get_file_type_by_filename().
 *
 * removed!
 * removed!
 * Move entrynewscreen after some check(return) in mmi_fmgr_disp_sel_drv_scr()
 *
 * removed!
 * removed!
 * When abort app select in mmi_fmgr_disp_sel_drv_scr(), adjust history: delete unused screen.
 *
 * removed!
 * removed!
 * Streaming & PDL Support.
 *
 * removed!
 * removed!
 * check file handler is valid in mmi_fmgr_get_file_type().
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * SIM+ Support.
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Add compile option __MMI_FILE_MANAGER__ for some functions. Such as: select drv.
 *
 * removed!
 * removed!
 * Add fs_close , when file size = 0 in mmi_fmgr_util_file_limit_check().
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Use new field to check if fmgr is busy.
 *
 * removed!
 * removed!
 * Change the png limit for dispchar
 *
 * removed!
 * removed!
 * Add PNG limit to dispchar
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Add file type -- 3G2.
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Add GIF limit of wallpaper
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Change the limit of Screen saver/Power on off disp file
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Correct the limitation of Screensaver and Power on/off disp: 240<->320
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 *******************************************************************************/

