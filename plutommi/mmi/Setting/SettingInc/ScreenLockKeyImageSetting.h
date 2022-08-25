/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  ScrlockKeyImageSetting.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef SCREEN_LOCK_KEY_IMG_SETTING_H
#define SCREEN_LOCK_KEY_IMG_SETTING_H

#include "MMI_features.h"

#ifdef __MMI_VUI_SCREEN_LOCK_KEY__

#include "MMIDataType.h"
#include "FileMgrSrvGProt.h"
#include "gdi_datatype.h"

/***************************************************************************** 
* define
*****************************************************************************/
#if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
#define MMI_SCREEN_LOCK_KEY_IMG_SETTING_NUM_PER_ROW                      (5)
#define MMI_SCREEN_LOCK_KEY_IMG_SETTING_NUM_PER_COL                      (4)

#elif defined(__MMI_MAINLCD_320X240__)

#define MMI_SCREEN_LOCK_KEY_IMG_SETTING_NUM_PER_ROW                      (3)
#define MMI_SCREEN_LOCK_KEY_IMG_SETTING_NUM_PER_COL                      (5)

#else

#define MMI_SCREEN_LOCK_KEY_IMG_SETTING_NUM_PER_ROW                      (5)
#define MMI_SCREEN_LOCK_KEY_IMG_SETTING_NUM_PER_COL                      (4)

#endif


#define MMI_SCREEN_LOCK_KEY_IMG_SETTING_DRV SRV_FMGR_SYSTEM_DRV
#define MMI_SCREEN_LOCK_KEY_IMG_SETTING_FOLDER L"@LockScreenImgSetting"
#define MMI_SCREEN_LOCK_KEY_IMG_SETTING_FILENAME L"locksceen.jpg"
#define MMI_SCREEN_LOCK_KEY_IMG_SETTING_FILEPATH_LENGTH   40

/***************************************************************************** 
* struct
*****************************************************************************/
typedef enum
{
    MMI_SCREEN_LOCK_KEY_IMG_SETTING_TYPE_SYS,
    MMI_SCREEN_LOCK_KEY_IMG_SETTING_TYPE_USR,
    MMI_SCREEN_LOCK_KEY_IMG_SETTING_TYPE_NOT_SET,
    MMI_SCREEN_LOCK_KEY_IMG_SETTING_TYPE_TOTAL
    
}mmi_screen_lock_key_img_setting_type_enum;


typedef struct
{
    mmi_id gid;
    mmi_id sys_gid;
    mmi_id usr_gid;

    gdi_handle usr_anim_handle;
    gdi_handle usr_img_handle;
    gdi_handle usr_decode_handle;
    
    S32 sys_hilight_idx;
    
    U16 sys_img_id;
    U16 img_typ;

    MMI_BOOL is_decoding;

    WCHAR usr_src_path[SRV_FMGR_PATH_MAX_LEN + 1];
    WCHAR usr_dest_path[MMI_SCREEN_LOCK_KEY_IMG_SETTING_FILEPATH_LENGTH + 1];

}mmi_screen_lock_key_img_setting_cntx;


/*****************************************************************************
 * FUNCTION
 *  mmi_screen_lock_key_img_setting_entry
 * DESCRIPTION
 *  This function entry lock screen img setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_screen_lock_key_img_setting_entry(MMI_ID parent_gid);

/*****************************************************************************
 * FUNCTION
 *  mmi_screen_lock_key_img_setting_set_hint
 * DESCRIPTION
 *  This function set lock screen img setting hint string.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_screen_lock_key_img_setting_set_hint(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_screen_lock_key_img_setting_get_type
 * DESCRIPTION
 *  This function query lock screen img type user select.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern mmi_screen_lock_key_img_setting_type_enum mmi_screen_lock_key_img_setting_get_type(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_screen_lock_key_img_setting_get_img_id
 * DESCRIPTION
 *  This function get the system default lock screen image id user select.
 * PARAMETERS
 *  key_code           : [IN]      key code to trigger manual lock
 * RETURNS
 *  void
 *****************************************************************************/
extern U16 mmi_screen_lock_key_img_setting_get_img_id(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_screen_lock_key_img_setting_get_img_path
 * DESCRIPTION
 *  This function get the user defined lock screen image path user select.
 * PARAMETERS
 *  key_code           : [IN]      key code to trigger manual lock
 * RETURNS
 *  void
 *****************************************************************************/
WCHAR* mmi_screen_lock_key_img_setting_get_img_path(void);

#endif

#endif


