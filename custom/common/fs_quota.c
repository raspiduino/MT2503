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
 *	fs_quota.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *    This file defines quota setting
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
 * removed!
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_general_types.h"

#include "fs_gprot.h"

#ifdef __FS_QM_SUPPORT__

#if defined(__FS_MODIS_FDM__) || defined(__MTK_TARGET__)

#ifdef __J2ME__
#include "j2me_custom_param.h"
#endif /* __J2ME__ */

#include "customer_ps_inc.h"

#include "nvram_user_defs.h"

#ifdef WAP_SUPPORT
#include "custom_wap_config.h"
#endif

#ifdef __SYNCML_SUPPORT__
#include "custom_mmi_default_value.h"
#endif /* __SYNCML_SUPPORT__ */

#ifdef __MMI_VUI_3D_CUBE_APP__
#include "lcd_sw_inc.h"
#endif

#ifdef __MMI_BROWSER_2__
#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
#include "BrowserSrvBookmarkConfig.h"
#endif
#endif

#if defined(__BT_PBAP_CLIENT__)
#include "custom_phb_config.h"
#endif

#ifdef __MMI_BT_MAP_CLIENT__
#include "custom_btmapc_config.h"
#endif

#ifdef __MMI_BT_NOTI_SRV__
#include "custom_btnotification_config.h"
#endif

/************************ Description of QuotaSet ************************************************
QuotaStruct: {Path in bytes, Priority, Qmin in bytes, Qmax in bytes, Uint}
Rule:
1. Path
   (1) Capital 'Z' in Path means the primary system drive
   (2) The character unit of Path is in byte
   (3) Except the default null end entry, path cannot be NULL and must be
       ended with backslash
   (4) The first char of each folder must be '@'
       Example: "E:\\@Folder\\"
   (5) Only support one level folder
       Example: "E:\\@Folder1\\@SubFolder\\" is invalid
2. Priority:
   FS_QP_HIG_ENUM (1) - Cannot be removed anyway except over quota (version upgrade)
   FS_QP_MID_ENUM (2) - Always removed entirely if over quota.
                        Optional removed if RFS is not enough.
   FS_QP_LOW_ENUM (3) - Always removed entirely if over quota.
                        Optional removed if RFS is not enough.
   FS_QP_DEL_ENUM (4) - Always removed entirely when booting up
3. Qmin (lower bound - reserved space) & Qmax (upper bound - quota space)
   (1) Qmax can set to be unlimited (FS_QMAX_NO_LIMIT)
   (2) 0 <= Qmin <= Qmax < FS_QMAX_NO_LIMIT
   (3) RFS (Required Free Space):
       (Qnow, the space you have used, is internal data tracked inside File System)
         for each entry
         {
            if(Qmin > Qnow)
               RFS += (Qmin - Qnow);
         }
   (4) MRS (Minimum Reserved Space) =
         (Qmin of FS_QP_DEL_ENUM) + (Qmin of FS_QP_LOW_ENUM) +
         (Qmin of FS_QP_MID_ENUM) + (Qmin of FS_QP_HIG_ENUM)
   (5) Note that NVRAM is a special case in Quota Management. File System will
       reserve the space for NVRAM at runtime automatically. You don't have to
       anything about NVRAM here.
       If (MRS + NVRAM) is over drive size, assertion will be issued when boot up check
   (6) Note that if you have 100 files under system drive and each one of them
       is just 3 bytes, you have to reserve (100* ClusterSize),
       not (100*3) bytes. Because the physical allocation unit in File System is in "cluster"
   (7) If you don't know how to count the space, you can use FS_GetFolderSize()
       in file system to help you evalute the size at development stage
4. Uint:
   FS_COUNT_IN_BYTE     : Indicate the Qmin and Qmax setting are counted in byte
   FS_COUNT_IN_CLUSTER  : Indicate the Qmin and Qmax setting are counted in cluster
*/

/************************ SweepCheck Flow ************************
1. Check each folder or file under root directory
2. If folder with DEL priority (listed in the QuotaSet table) is found, remove it entirely
3. If folder listed in the QuotaSet table is over quota, remove it entirely
4. If RFS is not enough for QuotaSet, jump to step 6
5. Return
6. If memory is not enough (1K+ 0.5K control buffer), jump to step 5
7. If file is found, remove it
   Else jump to step 9
8. If RFS is enough, jump to step 5
   Else jump to step 7
9. If folder not defined in the QuotaSet table is found, remove it entirely
   Else jump to step 11
10.If RFS is enough, jump to step 5
   Else jump to step 9
11.If folder with LOW priority (listed in the QuotaSet table) is found, remove it entirely
   Else jump to step 14
12.Update RFS to RFS' (because some space is freed by LOW)
13.If RFS' is enough, jump to step 5
   Else jump to step 11
14.If folder with MID priority (listed in the QuotaSet table) is found, remove it entirely
15.Jump to step 5
*/

/************************ QM Run Time Monitor ************************
1. If deletion, Qnow will be updated then
2. If need to allocate, check as step 3
3. If (over quota) return FS_DISK_FULL
   Else if (RFS for others is not enough) return FS_DISK_FULL
   Else if (Drive free is not enough for the allocation)  return FS_DISK_FULL
   Else update Qnow after allocation
*/

/************************ User Configuration ************************/
//Set your entry below
//Max quota set entry number is 40

#ifdef SLIM_WAP_MMS
#define FS_PUSH_QUOTA 2*1024
#ifdef WAP_SEC_SUPPORT
	#define FS_WAP_QUOTA 120
#else
    #define FS_WAP_QUOTA 40
#endif/*WAP_SEC_SUPPORT*/
#else
#define FS_PUSH_QUOTA 10*1024
	#define FS_WAP_QUOTA 160
#endif

#ifdef __MMI_BROWSER_2__
#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
#ifndef SLIM_WAP_MMS
    #define BRW_BOOKMARK_TEMP_FILE_SIZE 4*1024
#else
    #define BRW_BOOKMARK_TEMP_FILE_SIZE 0
#endif
    #define FS_BROWSER_BOOKMARK_FOLDER_QUOTA ((SRV_BRW_BKM_BOOKMARK_ENTRY_SIZE * WAP_CUSTOM_CFG_BRW_BOOKMARK_MAX_COUNT) + 100 + BRW_BOOKMARK_TEMP_FILE_SIZE)
#endif
#endif

FS_QuotaStruct gFS_ExtQuotaSet[] =
{
#if defined(__FUNET_ENABLE__)
    /* Please remember to configure this quota size if you enable FOTA feature.
     * Full image FOTA update should require the quota size equal to your code size. Usually you can evaluate the size by this formula as blew:
     * Found "Actual VIVA End Address" in ckImgSize.log, reserved quota size = Actual VIVA End Address - Bootloader partition size - Bootloader_ext partition size.
     */
	{"Z:\\@fota_iot\\", FS_QP_HIG_ENUM,  1 * 1024 , FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif
#ifdef __MMI_VCARD__
	{"Z:\\@vCard\\", FS_QP_HIG_ENUM,  50 * 1024 , FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif	

#ifdef __MMI_VUI_3D_CUBE_APP__
    {"Z:\\@Cube\\", FS_QP_HIG_ENUM, LCD_WIDTH * LCD_HEIGHT * 2 * 4,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif /* __MMI_VUI_3D_CUBE_APP__ */

#if defined(__DRM_SUPPORT__) && defined(MAX_DRM_DB_SIZE)
    {"Z:\\@DRM\\", FS_QP_HIG_ENUM, MAX_DRM_DB_SIZE,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_CLUSTER},
#endif

#ifdef WAP_SUPPORT
#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)) && defined (APP_STORAGE_IN_SYS_DRV)
	{"Z:\\@UC000\\",  FS_QP_HIG_ENUM, 10 * 1024 , FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif
    #ifdef OBIGO_Q03C
        #ifdef OPERA_BROWSER
            {"Z:\\@OperaMobile\\",      FS_QP_HIG_ENUM, 2434 * 1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
        #endif
        #ifdef __MMI_BROWSER_2__
        #ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
            {"Z:\\@vbookmarks\\",       FS_QP_HIG_ENUM, FS_BROWSER_BOOKMARK_FOLDER_QUOTA,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
        #endif
        #endif
        #if defined(OBIGO_Q03C_MMS_V01)
            #ifdef __MMI_WAP_DUAL_SIM__
                {"Z:\\@wap\\",       FS_QP_HIG_ENUM, FS_WAP_QUOTA,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_CLUSTER},
            #else
                {"Z:\\@wap\\",       FS_QP_HIG_ENUM, FS_WAP_QUOTA,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_CLUSTER},
            #endif /* __MMI_WAP_DUAL_SIM__ */
            #ifndef MMS_IN_LARGE_STORAGE
                {"Z:\\@mms\\",       FS_QP_HIG_ENUM,        0,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
            #endif
            {"Z:\\@mmsv01obj1\\",       FS_QP_HIG_ENUM, 10*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
            #if defined(__MMI_MMS_DUAL_SIM__)
            {"Z:\\@mmsv01obj2\\",       FS_QP_HIG_ENUM, 10*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
            #endif         
            #if defined(__DRM_SUPPORT__)
                {"Z:\\@MMS_DRM\\",   FS_QP_DEL_ENUM, 100*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
            #endif              
        #else
            {"Z:\\@wap\\",       FS_QP_HIG_ENUM,  FS_WAP_QUOTA,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_CLUSTER},
        #endif            
        #if defined(OBIGO_Q03C_MMS_V02) && !defined (MMS_IN_LARGE_STORAGE)
            {"Z:\\@mms\\",       FS_QP_HIG_ENUM, 0 , FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
        #endif
        #ifdef __MMI_MMS_BGSR_SUPPORT__
            {"Z:\\@bgsr\\",       FS_QP_HIG_ENUM, 2*1024 , FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
        #endif
        #ifdef BROWSER_SUPPORT
/* SLIM_R starts */
/*
        #ifdef SLIM_WAP_MMS
            {"Z:\\@wcache\\",    FS_QP_DEL_ENUM,  25*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
        #else
*/
/* MAUI_03090343 starts */
//        #ifndef SLIM_WAP_MMS  
/* SLIM_R ends */
        #if defined(SLIM_WAP_MMS) && (defined (__OP02__) || defined (__OP01__))
            #if (defined (__MMI_WAP_IMAGE_CACHE_SYSTEM_DRIVE__) || defined (__MMI_WAP_IMAGE_CACHE_TCARD_PLUS_SYS_DRIVE__))
            {"Z:\\@wcache\\",    FS_QP_DEL_ENUM,  25*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
            #endif
        #elif (defined (__MMI_WAP_IMAGE_CACHE_SYSTEM_DRIVE__) || defined (__MMI_WAP_IMAGE_CACHE_TCARD_PLUS_SYS_DRIVE__))
            #ifdef SLIM_WAP_MMS
            {"Z:\\@wcache\\",    FS_QP_DEL_ENUM,  25*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
            #else
            {"Z:\\@wcache\\",    FS_QP_DEL_ENUM,  50*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
        #endif /* SLIM_WAP_MMS */            
        #endif /* defined(SLIM_WAP_MMS) && (defined (__OP02__) || defined (__OP01__)) */            

        #endif /* BROWSER_SUPPORT */
            {"Z:\\@push\\",       FS_QP_HIG_ENUM, FS_PUSH_QUOTA,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
		#ifdef BROWSER_SUPPORT
        #if defined(__DRM_SUPPORT__)
            {"Z:\\@BRA_DRM\\",   FS_QP_DEL_ENUM,   4*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},            
        #endif
		#endif /* BROWSER_SUPPORT */
        #ifdef __MMI_MMS_MMA_MMS_OBJECT_IND__
            {"Z:\\@mmsobject\\",       FS_QP_HIG_ENUM, 5*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
            #if defined(__MMI_MMS_DUAL_SIM__)
            /* Temporary removed for slim projects */    
            //{"Z:\\@mmsobject2\\",       FS_QP_HIG_ENUM, 10*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
            #endif
        #endif
		#if defined(__MMI_MMS_2__) && defined(__MMI_MMS_SIGNATURE__) && !defined(__COSMOS_MMI_PACKAGE__)
			{"Z:\\@signature\\",       FS_QP_HIG_ENUM, 4*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
		#endif 
    #if defined(OBIGO_Q03C_MMS_V02) && defined(__MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__) && !defined(MMS_IN_LARGE_STORAGE)
			{"Z:\\@usedetail\\",       FS_QP_HIG_ENUM, 100*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
    #endif /*MMS_IN_LARGE_STORAGE*/
	#if defined(__MMI_MMS_AUTO_DWNLD_IMMED_NOTI_IN_HOME_NETWORK__) && defined (__MMI_MMS_2__)
			{"Z:\\@mms_notify\\",       FS_QP_HIG_ENUM, 1*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
	#endif
    #elif defined(OBIGO_Q05A)
            {"Z:\\@wap\\",       FS_QP_HIG_ENUM, 200*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
        #ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__            
            {"Z:\\@vbookmarks\\",       FS_QP_HIG_ENUM, FS_BROWSER_BOOKMARK_FOLDER_QUOTA,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
        #endif
            {"Z:\\@push\\",       FS_QP_HIG_ENUM, 10*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
            {"Z:\\@ids\\",       FS_QP_HIG_ENUM, 15*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
            {"Z:\\@stk\\",       FS_QP_HIG_ENUM, 50*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
        #if defined(OBIGO_Q05A_MMS) && !defined(MMS_IN_LARGE_STORAGE)
            {"Z:\\@mms\\",       FS_QP_HIG_ENUM, 100*1024 , FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
        #endif
        #if defined(OBIGO_Q05A_MMS)
            {"Z:\\@mma\\",       FS_QP_HIG_ENUM, 200*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
            {"Z:\\@umdb\\",       FS_QP_HIG_ENUM,130*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
        #endif
        #if defined(OBIGO_Q03C_MMS_V02) && !defined (MMS_IN_LARGE_STORAGE)
            {"Z:\\@mms\\",       FS_QP_HIG_ENUM, 0 , FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
        #endif
        #if defined(__MMI_MMS_BGSR_SUPPORT__)&& !defined(__MMI_MMS_LOW_TIER_BGSR_SUPPORT__)
            {"Z:\\@bgsr\\",       FS_QP_HIG_ENUM, 2*1024 , FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
        #endif
        #if defined(__MMI_MMS_MMA_MMS_OBJECT_IND__)
            {"Z:\\@mmsobject1\\",       FS_QP_HIG_ENUM, 10*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
            #if defined(__MMI_MMS_DUAL_SIM__)
            {"Z:\\@mmsobject2\\",       FS_QP_HIG_ENUM, 10*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
            #endif
        #endif
		#if defined(__MMI_MMS_2__) && defined(__MMI_MMS_SIGNATURE__)
			{"Z:\\@signature\\",       FS_QP_HIG_ENUM, 4*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
		#endif
		#if defined(__MMI_MMS_AUTO_DWNLD_IMMED_NOTI_IN_HOME_NETWORK__) && defined (__MMI_MMS_2__)
			{"Z:\\@mms_notify\\",       FS_QP_HIG_ENUM, 1*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
		#endif
    #endif        
#endif /* WAP_SUPPORT */



/*---------------------- ProvisioningBox Start --------------------------------------------------------*/

#ifdef __MMI_PROV_MESSAGE_SUPPORT__

    #ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__

        #if defined(__LOW_COST_SUPPORT_COMMON__)
            {"Z:\\@ProvBox\\", FS_QP_HIG_ENUM, 10 * 1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},  /* Inbox 5  + archive 5 */
        #else
            {"Z:\\@ProvBox\\", FS_QP_HIG_ENUM, 30 * 1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},  /* Inbox 15 + archive 15 */
        #endif

    #else /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */

        #if defined(__LOW_COST_SUPPORT_COMMON__)
            {"Z:\\@ProvBox\\", FS_QP_HIG_ENUM, 5 * 1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},  /* Inbox 5 */
        #else
            {"Z:\\@ProvBox\\", FS_QP_HIG_ENUM, 15 * 1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE}, /* Inbox 15 */
        #endif	  

    #endif /*__MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */

#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */

/*---------------------- ProvisioningBox End ----------------------------------------------------------*/



#ifdef __EMAIL__
         {"Z:\\@email_sys\\", FS_QP_HIG_ENUM, 1024 + 52 * 62, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif /* __EMAIL__ */

#ifdef __XML_SUPPORT__
            {"Z:\\@Xml\\",     FS_QP_HIG_ENUM,   1024,         FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif

#ifdef __EMS_SUPPORT__
            {"Z:\\@Image\\",     FS_QP_HIG_ENUM,       0,   FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
            {"Z:\\@Audio\\",     FS_QP_HIG_ENUM,       0,   FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif /* __EMS_SUPPORT__ */

#if defined(__J2ME__) && !defined(J2ME_SLIM_MEMORY_SUPPORT)

#ifndef _NAND_FLASH_BOOTING_
            {"Z:\\@Java\\",      FS_QP_HIG_ENUM,130*1024,
             (DEFAULT_MAX_STORAGE_SPACE ? DEFAULT_MAX_STORAGE_SPACE : FS_QMAX_NO_LIMIT), FS_COUNT_IN_BYTE},
#else
            {"Z:\\@Java\\",      FS_QP_HIG_ENUM,2560*1024,
             (DEFAULT_MAX_STORAGE_SPACE ? DEFAULT_MAX_STORAGE_SPACE : FS_QMAX_NO_LIMIT), FS_COUNT_IN_BYTE},
#endif

#endif  /* __J2ME__ */

#ifdef VR_CYBERON
            {"Z:\\@VRDB\\",      FS_QP_HIG_ENUM, 58*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},   // (2.85 * 20) + 1 = 58
#elif defined( VR_ITRI )
            {"Z:\\@VRDB\\",      FS_QP_HIG_ENUM, 85*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},   // (4.2 * 20) + 1 = 85
#endif /* VR */

#ifdef __IMPS__
            {"Z:\\@imps\\",      FS_QP_HIG_ENUM, 80*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE}, //MMI 35K + IMPS 45K
#endif /* __IMPS_ */

#ifdef __XDM__
            {"Z:\\@pocxdm\\",    FS_QP_HIG_ENUM, 30*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif /* __XDM__ */

#ifdef __POC__
            {"Z:\\@poc\\",       FS_QP_HIG_ENUM, 30*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif /* __POC__ */

#ifdef __SIP__
            {"Z:\\@sip\\",       FS_QP_HIG_ENUM, 30*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif /* __SIP__ */

#if defined (__MMI_FTC_SUPPORT__) && defined (__MMI_FTS_SUPPORT__)
            {"Z:\\@ftp\\",       FS_QP_HIG_ENUM, 60*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#elif defined(__MMI_FTS_SUPPORT__)
            {"Z:\\@ftp\\",       FS_QP_HIG_ENUM, 20*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#elif defined(__MMI_FTC_SUPPORT__)
            {"Z:\\@ftp\\",       FS_QP_HIG_ENUM, 40*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif

#ifdef __MMI_AVATAR__
            {"Z:\\@avatar\\",    FS_QP_HIG_ENUM,    200*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif

#ifdef SWFLASH_NEOMTEL
            {"Z:\\@swflash\\",    FS_QP_HIG_ENUM,    300*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif

#ifdef __MMI_BARCODEREADER__
#if defined(__MMI_OP11_BARCODEREADER__)
/* under construction !*/
#endif

#if defined(__MMI_OP01_BARCODEREADER__) || defined(__MMI_BARCODEREADER_QR__)
            {"Z:\\@barcode\\",    FS_QP_HIG_ENUM,    10*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif

#endif

#if defined(__MMI_IME_USER_DATABASE__) || defined(__MMI_CSTAR_USER_DICT__)
            {"Z:\\@ime\\",       FS_QP_HIG_ENUM,    32*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE}, // fixed size 32Kb
#endif

#ifdef __MMI_BPP_SUPPORT__
            {"Z:\\@bpp\\",       FS_QP_HIG_ENUM, 10*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif /* __MMI_BPP_SUPPORT__ */

//#ifdef __MRE_AM__
 //           {"Z:\\@AM\\",       FS_QP_HIG_ENUM, 20*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
//#endif /* __MRE_AM__ */

#ifdef __MMI_PNS__
#if defined(__CUSTOM_MRE_MAX_SIZE__) && (__CUSTOM_MRE_MAX_SIZE__ == 24)
#define __MRE_PUSH_MAX_SIZE__ 20
#else
#define __MRE_PUSH_MAX_SIZE__ 32
#endif
#else
#define __MRE_PUSH_MAX_SIZE__ 0
#endif

#ifndef __EMPTY_MMI__
#if defined(__CUSTOM_MRE_MAX_SIZE__)
	            {"Z:\\@mre\\",       FS_QP_HIG_ENUM, (__CUSTOM_MRE_MAX_SIZE__+__MRE_PUSH_MAX_SIZE__)*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#elif (defined(__COSMOS_MMI_PACKAGE__)||defined(__MMI_APP_MANAGER_SUPPORT__))
	            {"Z:\\@mre\\",       FS_QP_HIG_ENUM, (200+__MRE_PUSH_MAX_SIZE__)*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#else
	            {"Z:\\@mre\\",       FS_QP_HIG_ENUM, 20*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif /* __COSMOS_MMI_PACKAGE__ */
#endif /* __EMPTY_MMI__ */

#ifdef PNS_SUPPORT
            {"Z:\\@pns\\",       FS_QP_HIG_ENUM, 3*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif /* PNS_SUPPORT */

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            {"Z:\\@SMSArch\\",   FS_QP_HIG_ENUM, CM_SMS_MAX_ARMSG_NUM*100, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

#ifdef __MMI_VIDEO_STREAM__
            {"Z:\\@VideoStream\\", FS_QP_HIG_ENUM, 20*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif /* __MMI_VIDEO_STREAM__ */

#ifdef STREAM_SUPPORT
            {"Z:\\@VideoStreaming\\", FS_QP_HIG_ENUM, 2*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif /* STREAM_SUPPORT */

#ifdef SYNCML_DM_SUPPORT
            {"Z:\\@dm\\",       FS_QP_HIG_ENUM, 320*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif /* SYNCML_DM_SUPPORT */

#ifdef __BTMTK__
            {"Z:\\@bt\\",       FS_QP_HIG_ENUM, 3*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif /* __BTMTK__ */

#ifdef __BT_BIP_PROFILE__
            {"Z:\\@bip\\",       FS_QP_HIG_ENUM, 60*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif /* __BT_BIP_PROFILE__ */

#ifdef __CERTMAN_SUPPORT__
            {"Z:\\@certman\\",       FS_QP_HIG_ENUM, 100, FS_QMAX_NO_LIMIT, FS_COUNT_IN_CLUSTER},
#endif /* __CERTMAN_SUPPORT__ */

#ifdef __TCPIP__
    #ifdef __SLIM_NWK_PROFILE__
        #if (MMI_MAX_SIM_NUM == 4)
            {"Z:\\@Dtcnt\\",       FS_QP_HIG_ENUM, 48*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
        #elif (MMI_MAX_SIM_NUM == 3)
            {"Z:\\@Dtcnt\\",       FS_QP_HIG_ENUM, 41*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
        #elif (MMI_MAX_SIM_NUM == 2)
            {"Z:\\@Dtcnt\\",       FS_QP_HIG_ENUM, 34*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
        #else
            #ifdef __MMI_TELEPHONY_SUPPORT__
                {"Z:\\@Dtcnt\\",       FS_QP_HIG_ENUM, 31*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
            #endif
        #endif /* MMI_MAX_SIM_NUM */
    #else /* __SLIM_NWK_PROFILE__ */
        #if (MMI_MAX_SIM_NUM == 4)
            {"Z:\\@Dtcnt\\",       FS_QP_HIG_ENUM, 109*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
        #elif (MMI_MAX_SIM_NUM == 3)
            {"Z:\\@Dtcnt\\",       FS_QP_HIG_ENUM, 106*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
        #elif (MMI_MAX_SIM_NUM == 2)
            {"Z:\\@Dtcnt\\",       FS_QP_HIG_ENUM, 103*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
        #else
            {"Z:\\@Dtcnt\\",       FS_QP_HIG_ENUM, 100*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
        #endif /* MMI_MAX_SIM_NUM */
    #endif /* __SLIM_NWK_PROFILE__ */
#endif /* __TCPIP__ */

#ifdef __SSL_SUPPORT__
    #ifdef OPERA_BROWSER
    #ifdef __OCSP_SUPPORT__
            {"Z:\\@tls\\",       FS_QP_HIG_ENUM, 106, FS_QMAX_NO_LIMIT, FS_COUNT_IN_CLUSTER},
    #else /* !__OCSP_SUPPORT__ */
            {"Z:\\@tls\\",       FS_QP_HIG_ENUM, 103, FS_QMAX_NO_LIMIT, FS_COUNT_IN_CLUSTER},
    #endif /* !__OCSP_SUPPORT__ */

    #else /* !OPERA_BROWSER */
    #ifdef __OCSP_SUPPORT__
            {"Z:\\@tls\\",       FS_QP_HIG_ENUM, 80, FS_QMAX_NO_LIMIT, FS_COUNT_IN_CLUSTER},
    #elif defined(__IOT__)
            {"Z:\\@tls\\",       FS_QP_HIG_ENUM, 20, FS_QMAX_NO_LIMIT, FS_COUNT_IN_CLUSTER},
    #else /* !__OCSP_SUPPORT__ */
            {"Z:\\@tls\\",       FS_QP_HIG_ENUM, 77, FS_QMAX_NO_LIMIT, FS_COUNT_IN_CLUSTER},
    #endif /* !__OCSP_SUPPORT__ */
    #endif /* !OPERA_BROWSER */
#endif /* __SSL_SUPPORT__ */

#ifdef __WIFI_SUPPORT__
            {"Z:\\@dhcp\\",      FS_QP_HIG_ENUM, 2*1024, 3*1024, FS_COUNT_IN_BYTE},
#endif /* __WIFI_SUPPORT__ */

#if (defined __MMI_OP01_DCD__)
            {"Z:\\@dcd_sys\\",      FS_QP_HIG_ENUM, 4*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
			{"Z:\\@dcd\\",          FS_QP_HIG_ENUM, 200*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#elif (defined __MMI_OP01_DCD_V30__)
            {"Z:\\@dcd_sys\\",      FS_QP_HIG_ENUM, 4*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
			{"Z:\\@dcd\\",          FS_QP_HIG_ENUM, 1536*1024, 6*1024*1024, FS_COUNT_IN_BYTE},
#endif

#ifdef __MMI_MOBILE_VIDEO__
            {"Z:\\@MobileVideo\\",  FS_QP_HIG_ENUM, 4*1024*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif /* __MMI_MOBILE_VIDEO__ */


#ifdef SVG12_SUPPORT
            {"Z:\\@svg\\",    FS_QP_DEL_ENUM,  0,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif

#ifdef PICTBRIDGE_SUPPORT
            {"Z:\\@pictbridge\\", FS_QP_HIG_ENUM, 1*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif


#ifdef __SYNCML_SUPPORT__

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
#define MMI_SYNCML_NUM_OF_TASK  NUM_OF_TASK
#else
#define MMI_SYNCML_NUM_OF_TASK  (0)
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
#define MMI_SYNCML_NUM_OF_CAL  NUM_OF_CAL
#else
#define MMI_SYNCML_NUM_OF_CAL  (0)
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
#define MMI_SYNCML_NUM_OF_NOTE  MMI_MAX_NOTE_ITEM
#else
#define MMI_SYNCML_NUM_OF_NOTE  (0)
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */

/* total change log records */
#define MMI_SYNCML_CHGLOG_REC_TOTAL  \
            (MAX_PHB_PHONE_ENTRY + MMI_SYNCML_NUM_OF_CAL + MMI_SYNCML_NUM_OF_TASK + MMI_SYNCML_NUM_OF_NOTE)


#ifdef __SYNCML_DEVICE_SYNC__
/* MMI_SYNCML_DB_NUM and MMI_SYNCML_MAP_REC_TOTAL has no dependence 
 * with __MMI_SYNCML_SYNC_***_SUPPORT__ ,
 * it's always the total Database number supported by PS, because PS can not
 * change among with MMI features.
 */
/* total map records */
#define MMI_SYNCML_MAP_REC_TOTAL    \
    (MAX_PHB_PHONE_ENTRY + NUM_OF_CAL + NUM_OF_TASK + MMI_MAX_NOTE_ITEM)
#define MMI_SYNCML_DB_NUM   (4)  /* 1.phb + 2.cal + 3.task + 4.note */
/* "12" is map record size. 132 is map header size. */
#define MMI_SYNCML_MAX_DEV_MEMSIZE \
            (MAX_SYNCML_DEV_NUM * (7 * MMI_SYNCML_CHGLOG_REC_TOTAL + 132 * MMI_SYNCML_DB_NUM + MMI_SYNCML_MAP_REC_TOTAL * 12))            
#else /* __SYNCML_DEVICE_SYNC__ */
#define MMI_SYNCML_MAX_DEV_MEMSIZE  (0)
#endif /* __SYNCML_DEVICE_SYNC__ */

            /* "10 * 1024" is the maxSize of sending file, "7" is a changelog rec size  */
            {"Z:\\@SyncML\\", FS_QP_HIG_ENUM,  (10 * 1024) + (7 * MMI_SYNCML_CHGLOG_REC_TOTAL * MAX_SYNCML_SV_PROFILES) + MMI_SYNCML_MAX_DEV_MEMSIZE, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},

#endif /* __SYNCML_SUPPORT__ */

#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
            {"Z:\\@mtv\\",    FS_QP_HIG_ENUM,    2*1024*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#elif defined(__MMI_ATV_SUPPORT__)
    #if defined(__ATV_SLIM_VERSION__)
            {"Z:\\@mtv\\",    FS_QP_HIG_ENUM,    6*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
    #else
            {"Z:\\@mtv\\",    FS_QP_HIG_ENUM,    9*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
    #endif
#endif

#ifdef __MMI_AUTO_ANSWER_MACHINE__
            {"Z:\\@AutoAM\\",       FS_QP_HIG_ENUM, 25*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif /* __MMI_AUTO_ANSWER_MACHINE__ */
#ifdef __UCWEB6__
            {"Z:\\@UCWebClient\\",       FS_QP_HIG_ENUM, 10*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif    
#ifdef KUR_DECODE
            {"Z:\\@kuro\\",       FS_QP_HIG_ENUM, 15*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif 
#ifdef __QQIM_SLIM_SUPPORT__ 
            {"Z:\\@qq\\",       FS_QP_HIG_ENUM, 1*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif

#ifdef __SRV_SMS_SIM_CUST_DATA__
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#else /* __MMI_DUAL_SIM_MASTER__ */
            {"Z:\\@SMSSimCust\\",  FS_QP_HIG_ENUM, 2, FS_QMAX_NO_LIMIT, FS_COUNT_IN_CLUSTER},
#endif /* __MMI_DUAL_SIM_MASTER__ */
#endif /* __SRV_SMS_SIM_CUST_DATA__ */

#ifdef __GADGET_SUPPORT__ 
            {"Z:\\@gadget\\",  FS_QP_HIG_ENUM,  500 * 1024,  FS_QMAX_NO_LIMIT,  FS_COUNT_IN_BYTE},
#ifdef __COSMOS_MMI_PACKAGE__
            {"Z:\\@wgtmgr\\",  FS_QP_HIG_ENUM,  520 * 1024,  FS_QMAX_NO_LIMIT,  FS_COUNT_IN_BYTE},
#else
            {"Z:\\@wgtmgr\\",  FS_QP_HIG_ENUM,   20 * 1024,  FS_QMAX_NO_LIMIT,  FS_COUNT_IN_BYTE},
#endif
#endif

#ifdef __NMC_SUPPORT__
            {"Z:\\@nmc\\",  FS_QP_HIG_ENUM,  1024 * 1024,  FS_QMAX_NO_LIMIT,  FS_COUNT_IN_BYTE},
#endif

#if (defined(__MRE_PACKAGE_FULL__) || defined(__MRE_PACKAGE_NORMAL__)) && !defined(__IOT__)
   {"Z:\\@mrestorage\\", FS_QP_HIG_ENUM, 10*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif

#ifdef __MMI_3D_GAME_INTERGRAFX__
	  {"Z:\\@ig_save\\", FS_QP_HIG_ENUM, 1*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif

#if defined(__COSMOS_MMI_PACKAGE__) && !defined(__LOW_COST_SUPPORT_COMMON__)
            {"Z:\\@Settings\\",
                FS_QP_HIG_ENUM, 
                512 * 1024 * (   // 512K for each wallpaper cache file
                #ifdef __MMI_COSMOS_DOWNLOADABLE_THEMES_SUPPORT__
                2 +              // Theme icon
                #endif
                #ifdef __MMI_VUI_LAUNCHER_ROBOT__
                1 +              // Robot wallpaper
                #endif
                #ifdef __MMI_VUI_LAUNCHER_MM__
                1 +              // Fruit wallpaper
                #endif
                #ifdef __MMI_VUI_LAUNCHER_COSMOS__
                1 +              // Cosmos wallpaper
                #endif
                #ifdef __MMI_VUI_SCREEN_LOCK_STEAM__
                1 +              // Steam lock
                #endif
                #ifdef __MMI_VUI_SCREEN_LOCK_COSMOS__
                1 +              // Cosmos lock
                #endif
                #ifdef __MMI_VUI_SCREEN_LOCK_ZIPPER__
                1 +              // Zipper lock
                #endif
                #ifdef __MMI_VUI_SCREEN_LOCK_PATTERN__
                1 +              // Pattern lock
                #endif
                #ifdef __MMI_VUI_SCREEN_LOCK_PAINTING__
                1 +              // Painting lock
                #endif
                0),
                FS_QMAX_NO_LIMIT, 
                FS_COUNT_IN_BYTE},
#endif

#if defined(__MRE_PACKAGE_SLIM__)
    {"Z:\\@mresysfile\\", FS_QP_HIG_ENUM, 1*2*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},

#elif defined(__MRE_PACKAGE_NORMAL__)
    {"Z:\\@mresysfile\\", FS_QP_HIG_ENUM, 5*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},

#elif defined(__MRE_PACKAGE_FULL__)
    {"Z:\\@mresysfile\\", FS_QP_HIG_ENUM, 5*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},

#endif

#ifdef __ALIPAY_SUPPORT__
    {"Z:\\@alipay\\", FS_QP_HIG_ENUM, 2*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif

#if defined(__MMI_VUI_ENGINE__) && (!defined(__MMI_VUI_SCREEN_LOCK_FACTORY__) || !defined(__MMI_VUI_LAUNCHER_FACTORY__))
    /* set to 50K since @wallpaper may have multiple small setting file, effected by cluster size */
    /* If screen lock factory or launcher factory is used; we don't have to reserve such space,   */
    /* since   */
    {"Z:\\@wallpaper\\", FS_QP_HIG_ENUM, 50*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif

#ifdef __SOCIAL_NETWORK_SUPPORT__
            {"Z:\\@sns\\",       FS_QP_HIG_ENUM, 100*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif /* __SOCIAL_NETWORK_SUPPORT__ */

#ifdef __MMI_VUI_SHELL_SHORTCUTS__
    {"Z:\\@shortcuts\\", FS_QP_HIG_ENUM, 16*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif

#ifdef __MMI_VCALENDAR__
     {"Z:\\@caltodo\\",       FS_QP_HIG_ENUM, 2*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif 

	/*------------------------------------------------------------
	 * Sen(2013-7):Add FS quota for PBAP and MAP profile
	 * PBAP Client(default): 20KB(500 items of x-bt/vcard-listing)
	 * MAP Client(default): 25KB(50 items of x-bt/MAP-msg-listing)
	 *-----------------------------------------------------------*/
#if 0
#ifdef __BT_PBAP_CLIENT__
/* under construction !*/
#endif /* __BT_PBAP_CLIENT__ */
#endif
#ifdef __MMI_BT_MAP_CLIENT__
    {"Z:\\@map\\",   FS_QP_HIG_ENUM, (5*1024 + 410*SRV_SMS_BTMAPC_MAX_SMS_ENTRY), FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif /* __MMI_BT_MAP_CLIENT__ */

#ifdef __MMI_BT_REMOTE_CAPTURE__
	{"Z:\\@cap\\",   FS_QP_HIG_ENUM, (25*1024), FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif

#ifdef __MMI_BT_MAP_CLIENT__
    {"Z:\\@SMSBTMAPCSRV\\",   FS_QP_HIG_ENUM, (10*1024 + 1124*SRV_SMS_BTMAPC_MAX_SMS_ENTRY * BT_MAX_LINK_NUM), FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
    {"Z:\\@SmsBtMaps\\",   FS_QP_HIG_ENUM, 2 * 1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
    {"Z:\\@maps\\",   FS_QP_HIG_ENUM, 2 * 1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif

#ifdef __MMI_BT_PBAP_CLIENT__
    {"Z:\\@BTDIALER\\",   FS_QP_HIG_ENUM, (((MMI_CLOG_PBAPC_ALL_CALL_ENTRIES) * 9)/45)* 1024* BT_MAX_LINK_NUM , FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif

#ifdef __MMI_BT_NOTI_SRV__
#ifdef __SRV_BT_NOTI_QUOTA_DEBUG_ENABLE__
    {"Z:\\@BTNotify\\", FS_QP_HIG_ENUM, (10 * 1024 + 8192 * SRV_BT_NOTI_MSG_LIST_MAX_NUM), FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#else   
    {"Z:\\@BTNotify\\", FS_QP_HIG_ENUM, (10 * 1024 + 4096 * SRV_BT_NOTI_MSG_LIST_MAX_NUM), FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif
    /* 3.5k for xml parse tmp file quota */
    {"Z:\\@Xml\\", FS_QP_HIG_ENUM, 3584, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#ifdef __MMI_WEARABLE_DEVICE__
    {"Z:\\@BTMre\\", FS_QP_HIG_ENUM, 230 * 1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#else
    {"Z:\\@BTMre\\", FS_QP_HIG_ENUM, 30 * 1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif
#endif

#ifdef __BT_PBAP_CLIENT__
#if defined(__MMI_PHB_PBAPC_SYNC_CONTACT__)
    {"Z:\\@pbapc\\",   FS_QP_HIG_ENUM, (SRV_PHB_PBAPC_FOLDER_SIZE * 1024) + ((SRV_PHB_PBAPC_FOLDER_SIZE / 4) * 1024 * BT_MAX_LINK_NUM), FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#else
    {"Z:\\@pbapc\\",   FS_QP_HIG_ENUM, MMI_PHB_PBAPC_MAX_PSE_CONTACT * 72, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif
#endif /* __BT_PBAP_CLIENT__ */

#if defined(__MMI_PBAP_SUPPORT__)
#if MAX_PHB_PHONE_ENTRY > MAX_PHB_SIM_ENTRY
    {"Z:\\@pbap\\",   FS_QP_HIG_ENUM, MAX_PHB_PHONE_ENTRY * 72, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#else
    {"Z:\\@pbap\\",   FS_QP_HIG_ENUM, MAX_PHB_SIM_ENTRY * 72, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif
#endif /* __BT_PBAP_CLIENT__ */

#ifndef __MMI_BT_NOTI_SRV__  /* ifndef __MMI_BT_NOTI_SRV__, also put bt firmware patch in Z:\@BTMre\ */
#ifdef __MTK_INTERNAL__
/* under construction !*/
#endif
#endif //__MMI_BT_NOTI_SRV__

#if defined(__GPS_MT3333__)
	{"Z:\\@EPO\\", FS_QP_HIG_ENUM,  150 * 1024 , FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE}
#endif
};

/************* Do not modify anything behind this line *************/

extern void FS_QuotaInit(FS_QuotaStruct *quota, kal_uint32 total);

void fs_quota_init(void)
{
    FS_QuotaInit(gFS_ExtQuotaSet, ((sizeof(gFS_ExtQuotaSet)/sizeof(FS_QuotaStruct))));
}

sys_indirect_init_func g_fs_quota_init = fs_quota_init;

#else // !__FS_MODIS_FDM__ && !__MTK_TARTET__

void fs_quota_init(void)
{
}

sys_indirect_init_func g_fs_quota_init = fs_quota_init;

#endif /* __FS_MODIS_FDM__ || __MTK_TARTET__ */

#else   // !__FS_QM_SUPPORT__

void fs_quota_init(void)
{
}

sys_indirect_init_func g_fs_quota_init = fs_quota_init;

#endif // __FS_QM_SUPPORT__


