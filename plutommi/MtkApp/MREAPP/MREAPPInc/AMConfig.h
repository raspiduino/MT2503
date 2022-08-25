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
*  AMConfig.h
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  AM Configuration file.
*
* Author:
* -------
 * -------
*
*==============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*------------------------------------------------------------------------------
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#ifndef AM_CONFIG_H
#define AM_CONFIG_H

#include "MMIDataType.h"
#include "AMGprot.h"

// #define MMI_AM_ONLY_USE_ZIMO
#define MMI_AM_SUPPORT_UPDATE_CDR
#define MMI_AM_TEST_STRING L"Test"

#define MMI_AM_APP_NAME_H 14    /* app name height */
#define MMI_AM_MAX_VERSION_ID    24
#define MMI_AM_MAX_SHORTCUT_APP_NAME    30      /* shortcut app file name */

/***************************************************************************** 
* Typedef 
*****************************************************************************/
/* Quick launch info struct */
typedef struct
{
    mmi_am_shortcut_id_enum app_id;             /* using for launch app */
    U32 dl_app_id;                              /* using for download app */
    S8 file_name[MMI_AM_MAX_SHORTCUT_APP_NAME]; /* app file name */
} mmi_am_quick_launch_info_struct;

/* AM Shortcut Info struct (Only include AM shortcut) */
typedef struct
{
    mmi_am_shortcut_id_enum app_id;
    U16 icon_id;                                /* app icon resource id */
    U16 name_id;                                /* app name resource id */
    U8 *p_name;                                 /* app name pointer */
    U32 name_size;
    U32 dl_app_id;                              /* app ID */
    S8 file_name[MMI_AM_MAX_SHORTCUT_APP_NAME]; /* app file name */
} mmi_am_shortcut_info_struct;

/* Structure to store main screen configuration information */
typedef struct
{
    /* U8      main_lcd_size;   // 1:QVGA, 2:WQVGA, 3:HVGA */
    U8 app_num_per_row; /* number of applications per row */
    U8 app_num_per_col; /* number of applications per column */
    U8 icon_top_size;   /* size between upper edge of icon and upper edge of grid (cagetory214) */
    U8 name_below_size; /* size between lower edge of name and lower edge of grid (cagetory214) */
    U8 name_indent;     /* app name indent in a grid */
    U16 hl_icon_id;     /* highlight icon resource id */
} mmi_am_config_ms_struct;

/****************************************************************************
* Extern Global Function                                                            
*****************************************************************************/
/* AM Shortcut app api */
extern S32 mmi_am_config_get_am_sc_num(void);
extern mmi_am_shortcut_info_struct *mmi_am_config_get_am_sc_list(void);
extern mmi_am_shortcut_info_struct *mmi_am_config_get_am_sc_info_by_appid(mmi_am_shortcut_id_enum appid);
extern S8 *mmi_am_config_get_am_sc_name_by_appid(mmi_am_shortcut_id_enum appid);
extern S8 *mmi_am_config_get_am_sc_name_by_idx(S32 idx);

/* Quick launch app api */
extern mmi_am_quick_launch_info_struct *mmi_am_config_get_ql_info_by_appid(mmi_am_shortcut_id_enum appid);
extern S8 *mmi_am_config_get_ql_app_name_by_appid(mmi_am_shortcut_id_enum appid);

/* Main screen api */
extern mmi_am_config_ms_struct *mmi_am_config_get_am_ms_info(void);
extern void mmi_am_config_update_am_ms_info(void);
extern MMI_BOOL mmi_am_config_is_shortcut_app(U16 *app_name);
#endif /* AM_CONFIG_H */ 

