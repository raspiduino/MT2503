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
 * RingToneComposeEngine.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements the editor screen related functionalities of Ring Tone Composer.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
**/

/**************************************************************

   FILENAME : RingToneComposerEngine.c

   PURPOSE     : 

   REMARKS     : nil

   AUTHOR      : Vikram

   DATE     : 

**************************************************************/
#include "MMI_features.h"
#if defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__)

/* RHR */
//#include "kal_general_types.h"
#include "MMIDataType.h"
#include "ComposeRingToneEngineDefs.h"
#include "mmi_res_range_def.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_mem_gprot.h"
//#include "kal_public_api.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_list.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "gui_fixed_menuitems.h"
#include "mmi_frm_timer_gprot.h"
#include "TimerEvents.h"
#include "gui_typedef.h"
#include "wgui.h"
#include "GlobalConstants.h"
#include "string.h"
#include "CustDataRes.h"
#include "gdi_include.h"
#include "device.h"
#include "GpioSrvGprot.h"
#include "stdio.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_gprot.h"
#include "FileMgrType.h"
#include "Unicodexdcl.h"
#include "drm_def.h"
#include "FileMgrServiceResDef.h"
#include "gui_data_types.h"
#include "AlertScreen.h"
#include "FileMgrGProt.h"
#include "DebugInitDef_Int.h"
/* RHR */


//#include "mmi_include.h"
#include "ComposeRingToneEngineProts.h"
#include "Asciiprot.h"
#include "ComposeRingToneDefs.h"
#include "ComposeRingToneResDef.h"
#include "mmi_rp_app_ringtonecomposer_def.h"
//#include "SettingProfile.h"
//#include "CustDataProts.h"
#include "ComposeRingToneProts.h"
#include "ComposeRingToneTypes.h"
#include "ComposeRingToneMainScreenProts.h"
#include "GpioSrvGprot.h"
//#include "ProfileGprots.h"
#include "ProfilesSrvGprot.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
//#include "FileManagerDef.h"
//#include "FileManagerGprot.h"
//#include "CommonScreens.h"
#include "fs_type.h"
#include "FS_Func.h"
#include "fs_errcode.h"
#include "Filemgrsrvgprot.h"

#ifdef __MMI_TOUCH_RING_COMPOSER__
#include "wgui_softkeys.h"
#endif 
 
#ifdef __DRM_SUPPORT__
#include "drm_gprot.h"
#endif 

#if defined(__MMI_BACKGROUND_CALL__)
#include "UCMSrvGProt.h"
#endif

//#include "gui_font_size.h"
#include "Gui.h"
#include "wgui_include.h"

/* 
 * Global Variable
 */
MMI_BOOL CurrentNodePlaying = MMI_FALSE;
rngc_engine_context_struct *g_rngc_eng_cntx;
extern rngc_context_struct g_rngc_cntx;  
extern rngc_skin_layout_struct g_rngc_skin_layout;
extern S16 RNGC_TEMP_PATH[];
extern S16 RNGC_TEMP_FILE[];

#if defined(__MMI_MAINLCD_176X220__) && defined(__MMI_TOUCH_RING_COMPOSER__)
const U8 gnYCoords[] = 
{
    45 + RNGC_NOTE_OFFSET,
    54 + RNGC_NOTE_OFFSET,
    51 + RNGC_NOTE_OFFSET,
    48 + RNGC_NOTE_OFFSET,
    45 + RNGC_NOTE_OFFSET,
    42 + RNGC_NOTE_OFFSET,
    39 + RNGC_NOTE_OFFSET,
    24 + RNGC_NOTE_OFFSET,
    21 + RNGC_NOTE_OFFSET,
    18 + RNGC_NOTE_OFFSET,
    15 + RNGC_NOTE_OFFSET,
    12 + RNGC_NOTE_OFFSET,
    9 + RNGC_NOTE_OFFSET,
    6 + RNGC_NOTE_OFFSET,
    15 + RNGC_NOTE_OFFSET,
    12 + RNGC_NOTE_OFFSET,
    9 + RNGC_NOTE_OFFSET,
    6 + RNGC_NOTE_OFFSET,
    3 + RNGC_NOTE_OFFSET,
    0 + RNGC_NOTE_OFFSET,
    RNGC_NOTE_OFFSET - 3,
    21 + RNGC_NOTE_OFFSET,
    22 + RNGC_NOTE_OFFSET,
    22 + RNGC_NOTE_OFFSET,
    8 + RNGC_NOTE_OFFSET
}; /* defined(__MMI_MAINLCD_176X220__) && defined(__MMI_TOUCH_RING_COMPOSER__) */

#elif defined( __MMI_MAINLCD_176X220__)
const U8 gnYCoords[] = 
{
    45 + RNGC_NOTE_OFFSET,
    54 + RNGC_NOTE_OFFSET,
    51 + RNGC_NOTE_OFFSET,
    48 + RNGC_NOTE_OFFSET,
    45 + RNGC_NOTE_OFFSET,
    42 + RNGC_NOTE_OFFSET,
    39 + RNGC_NOTE_OFFSET,
    24 + RNGC_NOTE_OFFSET,
    21 + RNGC_NOTE_OFFSET,
    18 + RNGC_NOTE_OFFSET,
    15 + RNGC_NOTE_OFFSET,
    12 + RNGC_NOTE_OFFSET,
    9 + RNGC_NOTE_OFFSET,
    6 + RNGC_NOTE_OFFSET,
    15 + RNGC_NOTE_OFFSET,
    12 + RNGC_NOTE_OFFSET,
    9 + RNGC_NOTE_OFFSET,
    6 + RNGC_NOTE_OFFSET,
    3 + RNGC_NOTE_OFFSET,
    0 + RNGC_NOTE_OFFSET,
    RNGC_NOTE_OFFSET - 3,
    21 + RNGC_NOTE_OFFSET,
    22 + RNGC_NOTE_OFFSET,
    22 + RNGC_NOTE_OFFSET,
    8 + RNGC_NOTE_OFFSET
}; /* defined( __MMI_MAINLCD_176X220__) */

#elif defined(__MMI_MAINLCD_240X320__)
const U8 gnYCoords[] = 
{
    49 + RNGC_NOTE_OFFSET,
    59 + RNGC_NOTE_OFFSET,
    56 + RNGC_NOTE_OFFSET,
    53 + RNGC_NOTE_OFFSET,
    50 + RNGC_NOTE_OFFSET,
    47 + RNGC_NOTE_OFFSET,
    44 + RNGC_NOTE_OFFSET,
    29 + RNGC_NOTE_OFFSET,
    26 + RNGC_NOTE_OFFSET,
    23 + RNGC_NOTE_OFFSET,
    20 + RNGC_NOTE_OFFSET,
    17 + RNGC_NOTE_OFFSET,
    14 + RNGC_NOTE_OFFSET,
    11 + RNGC_NOTE_OFFSET,
    20 + RNGC_NOTE_OFFSET,
    17 + RNGC_NOTE_OFFSET,
    14 + RNGC_NOTE_OFFSET,
    11 + RNGC_NOTE_OFFSET,
    8 + RNGC_NOTE_OFFSET,
    5 + RNGC_NOTE_OFFSET,
    2 + RNGC_NOTE_OFFSET,
    21 + RNGC_NOTE_OFFSET,
    22 + RNGC_NOTE_OFFSET,
    22 + RNGC_NOTE_OFFSET,
    8 + RNGC_NOTE_OFFSET
}; /* defined(__MMI_MAINLCD_240X320__) */

#elif defined(__MMI_MAINLCD_320X240__)
const U8 gnYCoords[] = 
{
    56 + RNGC_NOTE_OFFSET,
    65 + RNGC_NOTE_OFFSET,
    62 + RNGC_NOTE_OFFSET,
    59 + RNGC_NOTE_OFFSET,
    56 + RNGC_NOTE_OFFSET,
    53 + RNGC_NOTE_OFFSET,
    50 + RNGC_NOTE_OFFSET,
    35 + RNGC_NOTE_OFFSET,
    32 + RNGC_NOTE_OFFSET,
    29 + RNGC_NOTE_OFFSET,
    26 + RNGC_NOTE_OFFSET,
    23 + RNGC_NOTE_OFFSET,
    20 + RNGC_NOTE_OFFSET,
    17 + RNGC_NOTE_OFFSET,
    26 + RNGC_NOTE_OFFSET,
    23 + RNGC_NOTE_OFFSET,
    20 + RNGC_NOTE_OFFSET,
    17 + RNGC_NOTE_OFFSET,
    14 + RNGC_NOTE_OFFSET,
    11 + RNGC_NOTE_OFFSET,
    8 + RNGC_NOTE_OFFSET,
    27 + RNGC_NOTE_OFFSET,
    28 + RNGC_NOTE_OFFSET,
    28 + RNGC_NOTE_OFFSET,
    8 + RNGC_NOTE_OFFSET
}; /* defined(__MMI_MAINLCD_320X240__) */

#elif defined(__MMI_MAINLCD_240X400__)
const U8 gnYCoords[] = 
{
    56 + RNGC_NOTE_OFFSET,
    65 + RNGC_NOTE_OFFSET,
    62 + RNGC_NOTE_OFFSET,
    59 + RNGC_NOTE_OFFSET,
    56 + RNGC_NOTE_OFFSET,
    53 + RNGC_NOTE_OFFSET,
    50 + RNGC_NOTE_OFFSET,
    35 + RNGC_NOTE_OFFSET,
    32 + RNGC_NOTE_OFFSET,
    29 + RNGC_NOTE_OFFSET,
    26 + RNGC_NOTE_OFFSET,
    23 + RNGC_NOTE_OFFSET,
    20 + RNGC_NOTE_OFFSET,
    17 + RNGC_NOTE_OFFSET,
    26 + RNGC_NOTE_OFFSET,
    23 + RNGC_NOTE_OFFSET,
    20 + RNGC_NOTE_OFFSET,
    17 + RNGC_NOTE_OFFSET,
    14 + RNGC_NOTE_OFFSET,
    11 + RNGC_NOTE_OFFSET,
    8 + RNGC_NOTE_OFFSET,
    27 + RNGC_NOTE_OFFSET,
    28 + RNGC_NOTE_OFFSET,
    28 + RNGC_NOTE_OFFSET,
    8 + RNGC_NOTE_OFFSET
}; /* defined(__MMI_MAINLCD_240X400__) */

#elif defined(__MMI_MAINLCD_320X480__)
const U16 gnYCoords[] = 
{
    76 + RNGC_NOTE_OFFSET, /* 0 OCTAVE_3 */
    88 + RNGC_NOTE_OFFSET, /* 1 OCTAVE_3 */
    84 + RNGC_NOTE_OFFSET, /* 2 OCTAVE_3 */
    80 + RNGC_NOTE_OFFSET, /* 3 OCTAVE_3 */
    76 + RNGC_NOTE_OFFSET, /* 4 OCTAVE_3 */
    72 + RNGC_NOTE_OFFSET, /* 5 OCTAVE_3 */
    68 + RNGC_NOTE_OFFSET, /* 6 OCTAVE_3 */
    47 + RNGC_NOTE_OFFSET, /* 7 OCTAVE_4 */
    44 + RNGC_NOTE_OFFSET, /* 8 OCTAVE_4 */
    40 + RNGC_NOTE_OFFSET, /* 9 OCTAVE_4 */
    36 + RNGC_NOTE_OFFSET, /* 10 OCTAVE_4 */
    32  + RNGC_NOTE_OFFSET, /* 11 OCTAVE_4 */
    28  + RNGC_NOTE_OFFSET, /* 12 OCTAVE_4 */
    24  + RNGC_NOTE_OFFSET, /* 13 OCTAVE_4 */
    36 + RNGC_NOTE_OFFSET, /* 14 OCTAVE_5 */
    32 + RNGC_NOTE_OFFSET, /* 15 OCTAVE_5 */
    28 + RNGC_NOTE_OFFSET, /* 16 OCTAVE_5 */
    24 + RNGC_NOTE_OFFSET, /* 17 OCTAVE_5 */
    20 + RNGC_NOTE_OFFSET, /* 18 OCTAVE_5 */
    16 + RNGC_NOTE_OFFSET, /* 19 OCTAVE_5*/
    12 + RNGC_NOTE_OFFSET,  /* 20 OCTAVE_5*/
    37 + RNGC_NOTE_OFFSET, /* 21 NOTE_REST */
    39 + RNGC_NOTE_OFFSET, /* 22 NOTE_REST */
    39 + RNGC_NOTE_OFFSET, /* 23 NOTE_REST */
    8 + RNGC_NOTE_OFFSET   /* 24 not used*/
}; /* defined(__MMI_MAINLCD_320X480__) */

#elif defined(__MMI_MAINLCD_128X160__)
#ifdef __MMI_TOUCH_RING_COMPOSER__
const U8 gnYCoords[] = 
{
    45 + RNGC_NOTE_OFFSET,
    54 + RNGC_NOTE_OFFSET,
    52 + RNGC_NOTE_OFFSET,
    50 + RNGC_NOTE_OFFSET,
    48 + RNGC_NOTE_OFFSET,
    46 + RNGC_NOTE_OFFSET,
    44 + RNGC_NOTE_OFFSET,
    34 + RNGC_NOTE_OFFSET,
    31 + RNGC_NOTE_OFFSET,
    28 + RNGC_NOTE_OFFSET,
    25 + RNGC_NOTE_OFFSET,
    22 + RNGC_NOTE_OFFSET,
    19 + RNGC_NOTE_OFFSET,
    16 + RNGC_NOTE_OFFSET,
    25 + RNGC_NOTE_OFFSET,
    22 + RNGC_NOTE_OFFSET,
    19 + RNGC_NOTE_OFFSET,
    16 + RNGC_NOTE_OFFSET,
    13 + RNGC_NOTE_OFFSET,
    10 + RNGC_NOTE_OFFSET,
    7 + RNGC_NOTE_OFFSET,
    27 + RNGC_NOTE_OFFSET,
    28 + RNGC_NOTE_OFFSET,
    28 + RNGC_NOTE_OFFSET,
    8 + RNGC_NOTE_OFFSET
};
#else /* __MMI_TOUCH_RING_COMPOSER__ */
const U8 gnYCoords[] = 
{
    56 + RNGC_NOTE_OFFSET,
    65 + RNGC_NOTE_OFFSET,
    62 + RNGC_NOTE_OFFSET,
    59 + RNGC_NOTE_OFFSET,
    56 + RNGC_NOTE_OFFSET,
    53 + RNGC_NOTE_OFFSET,
    50 + RNGC_NOTE_OFFSET,
    35 + RNGC_NOTE_OFFSET,
    32 + RNGC_NOTE_OFFSET,
    29 + RNGC_NOTE_OFFSET,
    26 + RNGC_NOTE_OFFSET,
    23 + RNGC_NOTE_OFFSET,
    20 + RNGC_NOTE_OFFSET,
    17 + RNGC_NOTE_OFFSET,
    26 + RNGC_NOTE_OFFSET,
    23 + RNGC_NOTE_OFFSET,
    20 + RNGC_NOTE_OFFSET,
    17 + RNGC_NOTE_OFFSET,
    14 + RNGC_NOTE_OFFSET,
    11 + RNGC_NOTE_OFFSET,
    8 + RNGC_NOTE_OFFSET,
    27 + RNGC_NOTE_OFFSET,
    28 + RNGC_NOTE_OFFSET,
    28 + RNGC_NOTE_OFFSET,
    8 + RNGC_NOTE_OFFSET
};
#endif /*__MMI_TOUCH_RING_COMPOSER__*/

#else /* if not of the above screen sizes */
const U8 gnYCoords[] = 
{
    54 + RNGC_NOTE_OFFSET,
    51 + RNGC_NOTE_OFFSET,
    48 + RNGC_NOTE_OFFSET,
    45 + RNGC_NOTE_OFFSET,
    42 + RNGC_NOTE_OFFSET,
    39 + RNGC_NOTE_OFFSET,
    36 + RNGC_NOTE_OFFSET,
    33 + RNGC_NOTE_OFFSET,
    30 + RNGC_NOTE_OFFSET,
    27 + RNGC_NOTE_OFFSET,
    24 + RNGC_NOTE_OFFSET,
    21 + RNGC_NOTE_OFFSET,
    18 + RNGC_NOTE_OFFSET,
    15 + RNGC_NOTE_OFFSET,
    24 + RNGC_NOTE_OFFSET,
    21 + RNGC_NOTE_OFFSET,
    18 + RNGC_NOTE_OFFSET,
    14 + RNGC_NOTE_OFFSET,
    12 + RNGC_NOTE_OFFSET,
    9 + RNGC_NOTE_OFFSET,
    6 + RNGC_NOTE_OFFSET,
    21 + RNGC_NOTE_OFFSET,
    22 + RNGC_NOTE_OFFSET,
    22 + RNGC_NOTE_OFFSET,
    8 + RNGC_NOTE_OFFSET
};
#endif

/* Mapping between Notes and Image ids */
const NoteInfo gNotesList[] = 
{
    {DURATION_3BY2 | OCTAVE_3 | NORMAL, IMG_3BY2_OCT_L_M_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY2 | OCTAVE_3 | FLAT, IMG_3BY2_OCT_L_M_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY2 | OCTAVE_3 | SHARP, IMG_3BY2_OCT_L_M_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_3BY2 | OCTAVE_5 | NORMAL, IMG_3BY2_OCT_U_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY2 | OCTAVE_5 | FLAT, IMG_3BY2_OCT_U_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY2 | OCTAVE_5 | SHARP, IMG_3BY2_OCT_U_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_1 | OCTAVE_3 | NORMAL, IMG_1_OCT_L_M_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1 | OCTAVE_3 | FLAT, IMG_1_OCT_L_M_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1 | OCTAVE_3 | SHARP, IMG_1_OCT_L_M_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_1 | OCTAVE_5 | NORMAL, IMG_1_OCT_U_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1 | OCTAVE_5 | FLAT, IMG_1_OCT_U_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1 | OCTAVE_5 | SHARP, IMG_1_OCT_U_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_3BY4 | OCTAVE_3 | NORMAL, IMG_3BY4_OCT_L_M_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY4 | OCTAVE_3 | FLAT, IMG_3BY4_OCT_L_M_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY4 | OCTAVE_3 | SHARP, IMG_3BY4_OCT_L_M_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_3BY4 | OCTAVE_5 | NORMAL, IMG_3BY4_OCT_U_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY4 | OCTAVE_5 | FLAT, IMG_3BY4_OCT_U_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY4 | OCTAVE_5 | SHARP, IMG_3BY4_OCT_U_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_1BY2 | OCTAVE_3 | NORMAL, IMG_1BY2_OCT_L_M_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1BY2 | OCTAVE_3 | FLAT, IMG_1BY2_OCT_L_M_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1BY2 | OCTAVE_3 | SHARP, IMG_1BY2_OCT_L_M_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_1BY2 | OCTAVE_5 | NORMAL, IMG_1BY2_OCT_U_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1BY2 | OCTAVE_5 | FLAT, IMG_1BY2_OCT_U_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1BY2 | OCTAVE_5 | SHARP, IMG_1BY2_OCT_U_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_3BY8 | OCTAVE_3 | NORMAL, IMG_3BY8_OCT_L_M_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY8 | OCTAVE_3 | FLAT, IMG_3BY8_OCT_L_M_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY8 | OCTAVE_3 | SHARP, IMG_3BY8_OCT_L_M_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_3BY8 | OCTAVE_5 | NORMAL, IMG_3BY8_OCT_U_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY8 | OCTAVE_5 | FLAT, IMG_3BY8_OCT_U_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY8 | OCTAVE_5 | SHARP, IMG_3BY8_OCT_U_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_1BY4 | OCTAVE_3 | NORMAL, IMG_1BY4_OCT_L_M_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1BY4 | OCTAVE_3 | FLAT, IMG_1BY4_OCT_L_M_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1BY4 | OCTAVE_3 | SHARP, IMG_1BY4_OCT_L_M_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_1BY4 | OCTAVE_5 | NORMAL, IMG_1BY4_OCT_U_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1BY4 | OCTAVE_5 | FLAT, IMG_1BY4_OCT_U_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1BY4 | OCTAVE_5 | SHARP, IMG_1BY4_OCT_U_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_3BY16 | OCTAVE_3 | NORMAL, IMG_3BY16_OCT_L_M_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY16 | OCTAVE_3 | FLAT, IMG_3BY16_OCT_L_M_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY16 | OCTAVE_3 | SHARP, IMG_3BY16_OCT_L_M_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_3BY16 | OCTAVE_5 | NORMAL, IMG_3BY16_OCT_U_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY16 | OCTAVE_5 | FLAT, IMG_3BY16_OCT_U_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY16 | OCTAVE_5 | SHARP, IMG_3BY16_OCT_U_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_1BY8 | OCTAVE_3 | NORMAL, IMG_1BY8_OCT_L_M_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1BY8 | OCTAVE_3 | FLAT, IMG_1BY8_OCT_L_M_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1BY8 | OCTAVE_3 | SHARP, IMG_1BY8_OCT_L_M_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_1BY8 | OCTAVE_5 | NORMAL, IMG_1BY8_OCT_U_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1BY8 | OCTAVE_5 | FLAT, IMG_1BY8_OCT_U_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1BY8 | OCTAVE_5 | SHARP, IMG_1BY8_OCT_U_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_3BY32 | OCTAVE_3 | NORMAL, IMG_3BY32_OCT_L_M_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY32 | OCTAVE_3 | FLAT, IMG_3BY32_OCT_L_M_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY32 | OCTAVE_3 | SHARP, IMG_3BY32_OCT_L_M_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_3BY32 | OCTAVE_5 | NORMAL, IMG_3BY32_OCT_U_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY32 | OCTAVE_5 | FLAT, IMG_3BY32_OCT_U_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY32 | OCTAVE_5 | SHARP, IMG_3BY32_OCT_U_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_1BY16 | OCTAVE_3 | NORMAL, IMG_1BY16_OCT_L_M_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1BY16 | OCTAVE_3 | FLAT, IMG_1BY16_OCT_L_M_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1BY16 | OCTAVE_3 | SHARP, IMG_1BY16_OCT_L_M_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_1BY16 | OCTAVE_5 | NORMAL, IMG_1BY16_OCT_U_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1BY16 | OCTAVE_5 | FLAT, IMG_1BY16_OCT_U_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1BY16 | OCTAVE_5 | SHARP, IMG_1BY16_OCT_U_S - COMPOSE_RING_TONE_ENGINE_BASE},

/********************Rest Notes********/
    {DURATION_3BY8 | OCTAVE_3, IMG_3BY8_OCT_L_M - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_1BY4 | OCTAVE_3, IMG_1BY4_OCT_L_M - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_3BY16 | OCTAVE_3, IMG_3BY16_OCT_L_M - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_1BY8 | OCTAVE_3, IMG_1BY8_OCT_L_M - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_3BY32 | OCTAVE_3, IMG_3BY32_OCT_L_M - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_1BY16 | OCTAVE_3, IMG_1BY16_OCT_L_M - COMPOSE_RING_TONE_ENGINE_BASE},
/*********************************Rest Notes End***************/

};

const PS8 gRngcMusicalNote[] = 
{
    "c", "d", "e", "f", "g", "a", "b", "r", "vibeon", "vibeoff", "ledon", "ledoff", "backon", "backoff"
};

const PS8 gRngcDuration[] = 
{
    "0.", "0", "1.", "1", "2.", "2", "3.", "3", "4.", "4"
};

#ifdef __MMI_RING_COMPOSER_REPEAT__
const PS8 gRngcRepeatCount[] = 
{
    "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"
};
#endif
MMI_BOOL g_current_insert_mode = MMI_FALSE;
/*****************************************************************************
 * FUNCTION
 *  EntryRngcComposerEngine
 * DESCRIPTION
 *  Entry function of editor screen in ring tone composer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL EntryRngcComposerEngine(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rngc_initialize_skinlayout();
    ClearKeyEvents();
    
    /* first time of entering */
    if (g_rngc_eng_cntx == NULL)
    {
        g_rngc_eng_cntx = OslMalloc(sizeof(rngc_engine_context_struct));
        if (g_rngc_eng_cntx == NULL)
        {
            return MMI_TRUE;
        }

        if (!mmi_frm_scrn_enter(
            GRP_ID_RNGC_COMPOSE,
            SCR_COMPOSER_ENGINE,
            (FuncPtr)ExitRngcComposerEngine,
            (FuncPtr)EntryRngcComposerEngine,
            MMI_FRM_FULL_SCRN))
        {
            return MMI_FALSE;
        }
        mdi_audio_suspend_background_play();
        mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
        mmi_rngc_initialize_composer();
        mmi_rngc_set_ring_composer(
            STR_RING_COMPOSE_TITLE,
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK);
        g_rngc_eng_cntx->CurrUIPos = 0;
        mmi_rngc_show_composer();
    }
    else
    {
        if (!mmi_frm_scrn_enter(
            GRP_ID_RNGC_COMPOSE,
            SCR_COMPOSER_ENGINE,
            (FuncPtr)ExitRngcComposerEngine,
            (FuncPtr)EntryRngcComposerEngine,
            MMI_FRM_FULL_SCRN))
        {
            return MMI_FALSE;
        }
        mdi_audio_suspend_background_play();
        mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
        mmi_rngc_set_ring_composer(
            STR_RING_COMPOSE_TITLE,
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK);

        if (g_rngc_eng_cntx->TotalNotes)
        {
            mmi_rngc_redraw_notes();
            /* ChangeRightSoftkey(STR_GLOBAL_CLEAR, IMG_GLOBAL_CLEAR); */
        }
        else
        {
            g_rngc_eng_cntx->CurrUIPos = 0;
        }
        mmi_rngc_show_composer();
    }

    g_rngc_eng_cntx->IsSefLeftKeyDown = FALSE;
    g_rngc_eng_cntx->IsRskLP = RSK_UP;
    SetRingToneFilenameBuf();
    mmi_frm_scrn_set_key_proc(GRP_ID_RNGC_COMPOSE, SCR_COMPOSER_ENGINE, rngc_key_proc);
   // SetRightSoftkeyFunction(RngcComposerRSKUpHandler, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(RngcComposerRSKDownHandler, KEY_EVENT_DOWN);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  ExitRngcComposerEngine
 * DESCRIPTION
 *  Exit function of editor screen in ring tone composer
 *  1. Stop playing tone
 *  2. Reset IsKeyPadAudioDisable;
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitRngcComposerEngine(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef RNGC_HAS_INST_RECTANGLE
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif 
#endif /*RNGC_HAS_INST_RECTANGLE*/
    StopTimer(TIMER_COMPOSE_RINGTONE);
    StopTimer(NOTE_MULTITAP_TIMER);
    RngcTurnOffBacklightTimer();

    mdi_audio_stop_string();
    mdi_audio_resume_background_play();
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    mmi_rngc_exit_mainscreen();

    /* stop instrument horizontal select scrolling */
    wgui_text_menuitem_reset_scrolling();
    g_current_insert_mode = MMI_FALSE;
    RedrawCategoryFunction = MMI_dummy_function;
}

/*****************************************************************************
 * FUNCTION
 *  rngc_key_proc
 * DESCRIPTION
 *  Function to map the Backspace event to delete
 * PARAMETERS
 *  evt   : [IN] key event    
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret rngc_key_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;
    U8 key_code = key_evt->key_code;
    U8 key_type = key_evt->key_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_evt->evt_id == EVT_ID_ON_KEY)
    {
        if (key_code == KEY_0 && key_type == KEY_EVENT_UP)
        {
            HandleKey_0();
            return MMI_RET_KEY_HANDLED;
        }
        else if (key_code == KEY_1 && key_type == KEY_EVENT_UP)
        {
            HandleKey_1();
            return MMI_RET_KEY_HANDLED;
        }
        else if (key_code == KEY_2 && key_type == KEY_EVENT_UP)
        {
            HandleKey_2();
            return MMI_RET_KEY_HANDLED;
        }
        else if (key_code == KEY_3 && key_type == KEY_EVENT_UP)
        {
            HandleKey_3();
            return MMI_RET_KEY_HANDLED;
        }
        else if (key_code == KEY_4 && key_type == KEY_EVENT_UP)
        {
            HandleKey_4();
            return MMI_RET_KEY_HANDLED;
        }
        else if (key_code == KEY_5 && key_type == KEY_EVENT_UP)
        {
            HandleKey_5();
            return MMI_RET_KEY_HANDLED;
        }
        else if (key_code == KEY_6 && key_type == KEY_EVENT_UP)
        {
            HandleKey_6();
            return MMI_RET_KEY_HANDLED;
        }
        else if (key_code == KEY_7 && key_type == KEY_EVENT_UP)
        {
            HandleKey_7();
            return MMI_RET_KEY_HANDLED;
        }
        else if (key_code == KEY_8 && key_type == KEY_EVENT_UP)
        {
            HandleKey_8();
            return MMI_RET_KEY_HANDLED;
        }
        else if (key_code == KEY_9 && key_type == KEY_EVENT_UP)
        {
            HandleKey_9();
            return MMI_RET_KEY_HANDLED;
        }
        else if (key_code == KEY_STAR && key_type == KEY_EVENT_UP)
        {
            HandleKey_STAR();
            return MMI_RET_KEY_HANDLED;
        }
        else if (key_code == KEY_POUND && key_type == KEY_EVENT_UP)
        {
            HandleKey_POUND();
            return MMI_RET_KEY_HANDLED;
        }
        else if (key_code == KEY_UP_ARROW && key_type == KEY_EVENT_UP)
        {
            HandleKey_UP();
            return MMI_RET_KEY_HANDLED;
        }
        else if (key_code == KEY_DOWN_ARROW && key_type == KEY_EVENT_UP)
        {
            HandleKey_DOWN();
            return MMI_RET_KEY_HANDLED;
        }
        else if (key_code == KEY_LEFT_ARROW && key_type == KEY_EVENT_DOWN)
        {
            mmi_rngc_HandleKey_LEFT_down_hdlr();
            return MMI_RET_KEY_HANDLED;
        }
        else if (key_code == KEY_LEFT_ARROW && key_type == KEY_EVENT_UP)
        {
            mmi_rngc_HandleKey_LEFT_up_hdlr();
            return MMI_RET_KEY_HANDLED;
        }
        else if (key_code == KEY_RIGHT_ARROW && key_type == KEY_EVENT_UP)
        {
            HandleKey_RIGHT_check();
            return MMI_RET_KEY_HANDLED;
        }
        else if (key_code == KEY_END && key_type == KEY_EVENT_DOWN)
        {
            HandleKey_END();
            return MMI_RET_KEY_HANDLED;
        }
        else if (key_code == KEY_VOL_UP && key_type == KEY_EVENT_DOWN)
        {
            mmi_rngc_select_previous_instrument_down();
            return MMI_RET_KEY_HANDLED;
        }
        else if (key_code == KEY_VOL_DOWN && key_type == KEY_EVENT_DOWN)
        {
            mmi_rngc_select_next_instrument_down();
            return MMI_RET_KEY_HANDLED;
        }
        else if (key_code == KEY_VOL_UP && key_type == KEY_EVENT_UP)
        {
            mmi_rngc_select_previous_instrument_up();
            return MMI_RET_KEY_HANDLED;
        }
        else if (key_code == KEY_VOL_DOWN && key_type == KEY_EVENT_UP)
        {
            mmi_rngc_select_next_instrument_up();
            return MMI_RET_KEY_HANDLED;
        }
        else if (key_code == KEY_RSK && key_type == KEY_EVENT_UP)
        {
             RngcComposerRSKUpHandler();
             return MMI_RET_KEY_HANDLED;
        }
        else if (key_code == KEY_RSK && key_type == KEY_EVENT_DOWN)
        {
            RngcComposerRSKDownHandler();
            return MMI_RET_KEY_HANDLED;
        }
        else if (key_code == KEY_LSK && key_type == KEY_EVENT_DOWN)
        {
		    if(!g_current_insert_mode)
            RngcComposerLSKDownHandler();
            return MMI_RET_KEY_HANDLED;
        }
        else if (key_code == KEY_LSK && key_type == KEY_EVENT_UP)
        {
    	    if(!g_current_insert_mode)
            RngcComposerLSKUpHandler();
            return MMI_RET_KEY_HANDLED;
        }
        else if (key_code == KEY_RSK && key_type == KEY_LONG_PRESS)
    {
    			if(GetActiveScreenId() == SCR_COMPOSER_ENGINE)
          HandleKey_CLEARLONG();
          return MMI_RET_KEY_HANDLED;
        }
        else if(key_code == KEY_BACKSPACE && key_type == KEY_LONG_PRESS)
        {
        		if(GetActiveScreenId() == SCR_COMPOSER_ENGINE)
            HandleKey_CLEARLONG();
            return MMI_RET_KEY_HANDLED;		 
    }
    else if (key_code == KEY_BACKSPACE && key_type == KEY_EVENT_DOWN && g_rngc_eng_cntx->TotalNotes == 0)
    {
        mdi_audio_stop_string();
        srv_prof_play_tone(ERROR_TONE,NULL);
            return MMI_RET_KEY_HANDLED;

    }            
    else if(key_code == KEY_BACKSPACE && key_type == KEY_EVENT_DOWN)
    {
        RngcComposerRSKDownHandler();
            return MMI_RET_KEY_HANDLED;		 
    }
    else if(key_code == KEY_BACKSPACE && key_type == KEY_EVENT_UP)
    {
        mmi_rngc_redraw_RSK(0);
        if (g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] == 0xFFFF)
        {
            StopTimer(NOTE_MULTITAP_TIMER);
    }

        if (g_rngc_eng_cntx->IsRskLP == RSK_LONGPRESS)
        {
            g_rngc_eng_cntx->IsRskLP = RSK_UP;
        }
    
    #ifdef __MMI_TOUCH_RING_COMPOSER__
        if (touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT)
        {
            touch_rngc_context.mode = GUI_RNGC_INSERT;
        }
    #endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
    }
    }
    return MMI_RET_OK;    
    
}


/*****************************************************************************
 * FUNCTION
 *  RngcClearStave
 * DESCRIPTION
 *  Clear all the variables for notes in stave
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RngcClearStave(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_rngc_eng_cntx->TotalNotes = 0;
    g_rngc_eng_cntx->CurrNoteIndex = 0;
    g_rngc_eng_cntx->CurrUIPos = 0;
    g_rngc_eng_cntx->IsRskLP = RSK_UP;
    memset(g_rngc_eng_cntx->NotesList, 0xFF, sizeof(g_rngc_eng_cntx->NotesList));
}


/*****************************************************************************
 * FUNCTION
 *  RngcInitCursor
 * DESCRIPTION
 *  Computes the cursor width
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RngcInitCursor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    S32 width, height;
    PU8 img;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get the maximum size of cursor */
    g_rngc_eng_cntx->CursorWidth = 0;
    for (i = IMG_3BY2_OCT_L_M_N; i <= IMG_RING_EVENTVIB_OFF; i++)
    {
        img = (PU8) GetImage(i);
        gui_measure_image(img, &width, &height);
        if (g_rngc_eng_cntx->CursorWidth < width)
        {
            g_rngc_eng_cntx->CursorWidth = (U8) width;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  FreeMemory
 * DESCRIPTION
 *  Free allocated memory to stored composed information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FreeMemory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_rngc_eng_cntx)
    {
        OslMfree(g_rngc_eng_cntx);
        g_rngc_eng_cntx = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  DeleteCurNote
 * DESCRIPTION
 *  Delete one musical note.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeleteCurNote(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_rngc_eng_cntx->CurrNoteIndex < g_rngc_eng_cntx->TotalNotes)
    {
        /* highlight on the last one */
        if (g_rngc_eng_cntx->CurrNoteIndex == g_rngc_eng_cntx->TotalNotes - 1)
        {
            g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] = 0xFFFF;
        }
        else    /* internal note */
        {
            memcpy(
                (g_rngc_eng_cntx->NotesList + g_rngc_eng_cntx->CurrNoteIndex),
                (g_rngc_eng_cntx->NotesList + (g_rngc_eng_cntx->CurrNoteIndex + 1)),
                (g_rngc_eng_cntx->TotalNotes - g_rngc_eng_cntx->CurrNoteIndex) * sizeof(U16));
        }
        --g_rngc_eng_cntx->TotalNotes;
    }
    else if (g_rngc_eng_cntx->CurrNoteIndex == g_rngc_eng_cntx->TotalNotes)
    {
        g_rngc_eng_cntx->NotesList[--g_rngc_eng_cntx->CurrNoteIndex] = 0xFFFF;
        --g_rngc_eng_cntx->TotalNotes;

        if (g_rngc_eng_cntx->TotalNotes < g_rngc_eng_cntx->CurrUIPos)
        {
            --g_rngc_eng_cntx->CurrUIPos;
        }
    }
    GDI_LOCK;
    mmi_rngc_redraw_notes();
    mmi_rngc_redraw_stave();
    mmi_rngc_redraw_remaining_notes();
#ifdef __MMI_TOUCH_RING_COMPOSER__
    if (touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT ||
        touch_rngc_context.mode == GUI_RNGC_INSERT || touch_rngc_context.mode == GUI_RNGC_EDIT)
    {
        mmi_rngc_finish_insert_editing();
    }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
    GDI_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  RngcPlayCurrentNodeCallBack
 * DESCRIPTION
 *  Used to reset if current node has been played
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void RngcPlayCurrentNodeCallBack(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CurrentNodePlaying = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  RngcTurnOffBacklightTimer
 * DESCRIPTION
 *  Used for turning off backlight in editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RngcTurnOffBacklightTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_backlight_set_mode_exe(1);
    srv_gpio_set_device_level(GPIO_DEV_LED_MAINLCD,5);
}


/*****************************************************************************
 * FUNCTION
 *  PlayCurrentNode
 * DESCRIPTION
 *  Play iMelody stream of current input note
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PlayCurrentNode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Because audio interface does not make a copy, 
       we have to prepare a buffer                  */
    static U8 pCurrentNode[512];    
    U8 pNoteString[10];
    U8 *temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_RING_COMPOSER_REPEAT__
   if ((g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & REPEAT_MASK) != 0)
   {
       return;
   }
#endif   
#if defined(__MMI_BACKGROUND_CALL__)
    if (srv_ucm_is_background_call())
    {
        if ((g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & NOTE_MASK) < NOTE_REST)
        {
            return;
        }
    }
#endif /* defined(__MMI_BACKGROUND_CALL__) */ 

#ifdef __MMI_SILENT_MEETING_PROFILE__
    if (srv_prof_ret srv_prof_is_profile_activated(SRV_PROF_MEETING_MODE) || srv_prof_ret srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE))
        if ((g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & NOTE_MASK) < NOTE_REST)
        {
            return;
        }
#endif /* __MMI_SILENT_MEETING_PROFILE__ */ 

    {
        /*only process backlight note*/
        U32 nValue;

        nValue = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & NOTE_MASK;
        switch(nValue)
        {
        case NOTE_BACKLIGHT_OFF:
            if (CurrentNodePlaying)
            {
                mdi_audio_stop_string();
            }
            srv_backlight_set_mode_exe(0);
            srv_gpio_set_device_level(GPIO_DEV_LED_MAINLCD,0);
            StartTimer(TIMER_COMPOSE_RINGTONE, 500, (FuncPtr)RngcTurnOffBacklightTimer);
            return;
        case NOTE_BACKLIGHT_ON:
            if (CurrentNodePlaying)
            {
                mdi_audio_stop_string();
            }
      /*  case NOTE_REST:*/    
            return;
        }
    }

    memset(pNoteString, 0, 10);
    temp = GetStringForNode(pNoteString, g_rngc_eng_cntx->CurrNoteIndex);
    *temp = 0;
    /* generate iMelody string */
#ifdef __MMI_RING_COMPOSER_STYLE__
    sprintf(
        (S8*) pCurrentNode,
        "%sCOMPOSER:MTK(%d)\r\nBEAT:%d\r\nSTYLE:S%d\r\nMELODY:",
        MELODY_HEADER,
        g_rngc_cntx.CurrInstr,
        g_rngc_cntx.CurrSpeed,
        g_rngc_cntx.CurrStyle);
#else /* __MMI_RING_COMPOSER_STYLE__ */
    sprintf(
        (S8*) pCurrentNode,
        "%sCOMPOSER:MTK(%d)\r\nBEAT:%d\r\nMELODY:",
        MELODY_HEADER,
        g_rngc_cntx.CurrInstr,
        g_rngc_cntx.CurrSpeed);
#endif /* __MMI_RING_COMPOSER_STYLE__ */        
        
    if(0 == strcmp((S8*)pNoteString, (S8*)"vibeon"))
    {
       strcat((S8*)pNoteString, (S8*)"r2");
    }
    strcat((S8*) & pCurrentNode, (S8*) pNoteString);
    strcat((S8*) pCurrentNode, (S8*) MELODY_END);

    if (mdi_audio_play_string
        ((void*)pCurrentNode, strlen((S8*) pCurrentNode), MDI_FORMAT_IMELODY, DEVICE_AUDIO_PLAY_ONCE, RngcPlayCurrentNodeCallBack, NULL) == MDI_AUDIO_SUCCESS)
    {
        CurrentNodePlaying = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  InsertNote
 * DESCRIPTION
 *  Inserts a note to screen accroding to current position
 * PARAMETERS
 *  nNote       [IN]        Musical note symbol
 * RETURNS
 *  void
 *****************************************************************************/
void InsertNote(U16 nNote)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nCount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(NOTE_MULTITAP_TIMER);
    if (g_rngc_eng_cntx->TotalNotes >= MAX_NOTES)
    {
        mdi_audio_stop_string();
        srv_prof_play_tone(ERROR_TONE,NULL);
        return;
    }

    /* internal note */
    if (g_rngc_eng_cntx->CurrNoteIndex < g_rngc_eng_cntx->TotalNotes)
    {
        /* shift one note right */
        for (nCount = g_rngc_eng_cntx->TotalNotes; nCount > g_rngc_eng_cntx->CurrNoteIndex; --nCount)
        {
            g_rngc_eng_cntx->NotesList[nCount] = g_rngc_eng_cntx->NotesList[nCount - 1];
        }
        
#ifdef __MMI_RNGC_INSERT_AFTER_CURSOR__
        /* insert note */
        ++g_rngc_eng_cntx->CurrNoteIndex;
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] = nNote;
        PlayCurrentNode();
        
        /* increase total number of notes */
        ++g_rngc_eng_cntx->TotalNotes;

        if (g_rngc_eng_cntx->CurrUIPos < NUM_NOTES_IN_STAVE - 1)
        {
            ++g_rngc_eng_cntx->CurrUIPos;
        }
#else /* __MMI_RNGC_INSERT_AFTER_CURSOR__ */ 
        /* insert note */
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] = nNote;        
        PlayCurrentNode();       
        /* increase total number of notes */
        ++g_rngc_eng_cntx->TotalNotes;

    #ifdef __MMI_TOUCH_RING_COMPOSER__
        if(touch_rngc_context.mode != GUI_RNGC_INSERT_EDIT)
        {
            /* only move cursor for inputs from keypad */
            ++g_rngc_eng_cntx->CurrNoteIndex;
            if (g_rngc_eng_cntx->CurrUIPos < NUM_NOTES_IN_STAVE - 1)
            {
                ++g_rngc_eng_cntx->CurrUIPos;
            } 
        }
    #else/* __MMI_TOUCH_RING_COMPOSER__ */
        /* move cursor */
        ++g_rngc_eng_cntx->CurrNoteIndex;
        if (g_rngc_eng_cntx->CurrUIPos < NUM_NOTES_IN_STAVE - 1)
        {
            ++g_rngc_eng_cntx->CurrUIPos;
        }    
    #endif /*__MMI_TOUCH_RING_COMPOSER__ */    
#endif /* __MMI_RNGC_INSERT_AFTER_CURSOR__ */

        mmi_rngc_redraw_notes();
        mmi_rngc_redraw_stave();
        mmi_rngc_redraw_remaining_notes();
    }
    else    /* last note */
    {
        /* insert note */
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] = nNote;

        /* increase total number of notes */
        ++g_rngc_eng_cntx->TotalNotes;

        if (g_rngc_eng_cntx->TotalNotes == 1)
        {
            mmi_rngc_redraw_RSK(0);
        }

        PlayCurrentNode();
        
#ifdef __MMI_RNGC_INSERT_AFTER_CURSOR__

        mmi_rngc_show_note(g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]);

#else /* __MMI_RNGC_INSERT_AFTER_CURSOR__ */
    #ifdef __MMI_TOUCH_RING_COMPOSER__
    
        if (g_rngc_eng_cntx->CurrUIPos < NUM_NOTES_IN_STAVE - 1 && touch_rngc_context.mode != GUI_RNGC_INSERT_EDIT)
        {
            ++g_rngc_eng_cntx->CurrNoteIndex;
            ++g_rngc_eng_cntx->CurrUIPos;
        }
        else if (g_rngc_eng_cntx->CurrUIPos == NUM_NOTES_IN_STAVE - 1 &&
                 g_rngc_eng_cntx->CurrNoteIndex < MAX_NOTES - 1 && touch_rngc_context.mode != GUI_RNGC_INSERT_EDIT)
        {
            ++g_rngc_eng_cntx->CurrNoteIndex;
        }
    #else /* __MMI_TOUCH_RING_COMPOSER__ */
    
        if (g_rngc_eng_cntx->CurrUIPos < NUM_NOTES_IN_STAVE - 1)
        {
            ++g_rngc_eng_cntx->CurrNoteIndex;
            ++g_rngc_eng_cntx->CurrUIPos;
        }
        else if (g_rngc_eng_cntx->CurrUIPos == NUM_NOTES_IN_STAVE - 1 && g_rngc_eng_cntx->CurrNoteIndex < MAX_NOTES - 1)
        {
            ++g_rngc_eng_cntx->CurrNoteIndex;
        }
    #endif /* __MMI_TOUCH_RING_COMPOSER__ */
    
        mmi_rngc_redraw_notes();
        mmi_rngc_redraw_stave();
        mmi_rngc_redraw_remaining_notes();
    
#endif /* __MMI_RNGC_INSERT_AFTER_CURSOR__*/
        
    }

#if !defined (__MMI_TOUCH_RING_COMPOSER__) && !defined (__MMI_RNGC_INSERT_AFTER_CURSOR__)
    /* auto shift cursor if a note is insert at the end */
    if (g_rngc_eng_cntx->CurrNoteIndex == g_rngc_eng_cntx->TotalNotes - 1 && g_rngc_eng_cntx->TotalNotes < MAX_NOTES)
    {
        StartTimer(NOTE_MULTITAP_TIMER, MULTITAP_TIME, (FuncPtr) HandleKey_RIGHT_check);
    }
#endif /* !defined (__MMI_TOUCH_RING_COMPOSER__) && !defined (__MMI_RNGC_INSERT_AFTER_CURSOR__)*/ 
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_0
 * DESCRIPTION
 *  Key event handler of number keys
 *  Insert corresponding musical note to stave
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_0(void)
{
#ifdef __MMI_TOUCH_RING_COMPOSER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT)
    {
        mmi_rngc_finish_insert_editing();
    }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
    InsertNote(NOTE_REST | DURATION_1BY4 | OCTAVE_4);
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_1(void)
{
#ifdef __MMI_TOUCH_RING_COMPOSER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT)
    {
        mmi_rngc_finish_insert_editing();
    }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
    InsertNote(NOTE_C | DURATION_1BY4 | OCTAVE_4 | NORMAL);
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_2(void)
{
#ifdef __MMI_TOUCH_RING_COMPOSER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT)
    {
        mmi_rngc_finish_insert_editing();
    }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
    InsertNote(NOTE_D | DURATION_1BY4 | OCTAVE_4 | NORMAL);
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_3
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_3(void)
{
#ifdef __MMI_TOUCH_RING_COMPOSER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT)
    {
        mmi_rngc_finish_insert_editing();
    }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
    InsertNote(NOTE_E | DURATION_1BY4 | OCTAVE_4 | NORMAL);
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_4
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_4(void)
{
#ifdef __MMI_TOUCH_RING_COMPOSER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT)
    {
        mmi_rngc_finish_insert_editing();
    }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
    InsertNote(NOTE_F | DURATION_1BY4 | OCTAVE_4 | NORMAL);
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_5
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_5(void)
{
#ifdef __MMI_TOUCH_RING_COMPOSER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT)
    {
        mmi_rngc_finish_insert_editing();
    }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
    InsertNote(NOTE_G | DURATION_1BY4 | OCTAVE_4 | NORMAL);
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_6
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_6(void)
{
#ifdef __MMI_TOUCH_RING_COMPOSER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT)
    {
        mmi_rngc_finish_insert_editing();
    }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
    InsertNote(NOTE_A | DURATION_1BY4 | OCTAVE_4 | NORMAL);
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_7
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_7(void)
{
#ifdef __MMI_TOUCH_RING_COMPOSER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT)
    {
        mmi_rngc_finish_insert_editing();
    }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
    InsertNote(NOTE_B | DURATION_1BY4 | OCTAVE_4 | NORMAL);
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_8
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_8(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_RING_COMPOSER__
    if (touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT)
    {
        mmi_rngc_finish_insert_editing();
    }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 

#ifndef __MMI_RING_COMPOSER_NO_VIB__
    InsertNote(NOTE_VIBRATION_ON);
#else
    InsertNote(REPEAT_START);
#endif /* __MMI_RING_COMPOSER_NO_VIB__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_9
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_9(void)
{
#ifdef __MMI_TOUCH_RING_COMPOSER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT)
    {
        mmi_rngc_finish_insert_editing();
    }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 

#ifdef __MMI_RNGC_ENABLE_INS_LED_NOTE__
    InsertNote(NOTE_LED_ON);
#else
    InsertNote(NOTE_BACKLIGHT_ON);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_CLEARLONG
 * DESCRIPTION
 *  Handler of long-pressed RSK.
 *  1. clear all notes and reset all state varilables.
 *  2. redraw screen and set RSK to Back
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_CLEARLONG(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_RING_COMPOSER__
    if (touch_rngc_context.area_type == GUI_RNGC_NOTE_SELECTION)
    {
        SetKeyHandler(RngcComposerLSKDownHandler, KEY_LSK, KEY_EVENT_DOWN);
        SetKeyHandler(EntryRngcCompToneOptList, KEY_LSK, KEY_EVENT_UP);
    }
    //if (g_rngc_eng_cntx->CurrNoteIndex >= g_rngc_eng_cntx->TotalNotes)
    {
        mmi_rngc_reset_toolbar();
    }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
    if (g_rngc_eng_cntx->IsRskLP == RSK_DOWN)
    {
        //if (g_rngc_eng_cntx->TotalNotes != 0)   /* not cleared yet */
        //{
            RngcClearStave();
            mmi_rngc_redraw_notes();
            mmi_rngc_redraw_stave();
            mmi_rngc_redraw_remaining_notes();
    #ifdef __MMI_TOUCH_RING_COMPOSER__
            show_touch_rngc_selection_area();
    #endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
            mmi_rngc_redraw_LSK(0);
            mmi_rngc_redraw_RSK(0);
            g_rngc_eng_cntx->IsRskLP = RSK_LONGPRESS;
        //}
    }
}


/*****************************************************************************
 * FUNCTION
 *  RngcComposerRSKUpHandler
 * DESCRIPTION
 *  Event handler of RSK up when composing ring tone
 *  If there is no musical note and RSK is not long pressed, go back to previous screen
 *  otherwise, reset state flag.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RngcComposerRSKUpHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* FMGR_Revise */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_get_active_id()!= SCR_COMPOSER_ENGINE)
    {
		return;
    }
    mmi_rngc_redraw_RSK(0);
    if (g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] == 0xFFFF)
    {
        StopTimer(NOTE_MULTITAP_TIMER);
    }

    if (g_rngc_eng_cntx->TotalNotes == 0 && g_rngc_eng_cntx->IsRskLP == 0)
    {
        FreeMemory();
        StopTimer(NOTE_MULTITAP_TIMER);

        if (g_rngc_cntx.CurrEditState == ENUM_COMP_ADD)
        {
            /* FMGR_Revise */
            if(IsScreenPresent(g_rngc_fmgr_explorer_id))
            {
                mmi_frm_group_close(mmi_frm_group_get_active_id());
               // GoBackToHistory(g_rngc_fmgr_explorer_id);
            }
            else
            {
                mmi_frm_scrn_close_active_id();
                /*
                GoBackHistory(); 
                */
            }    
        }
        else
        {
            mmi_frm_scrn_close_active_id();
           /* GoBackHistory();*/
        }
    }
    else if (g_rngc_eng_cntx->IsRskLP == RSK_LONGPRESS)
    {
        g_rngc_eng_cntx->IsRskLP = RSK_UP;
    }
    
#ifdef __MMI_TOUCH_RING_COMPOSER__
    if (touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT)
    {
        touch_rngc_context.mode = GUI_RNGC_INSERT;
    }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  RngcComposerRSKDownHandler
 * DESCRIPTION
 *  Event handler of RSK down when composing ring tone
 *  Delete one musical note.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RngcComposerRSKDownHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  if(mmi_frm_scrn_get_active_id()!= SCR_COMPOSER_ENGINE)
  {
     return;
  }

    StopTimer(NOTE_MULTITAP_TIMER);
    clear_right_softkey();
    mmi_rngc_redraw_RSK(1);
    if (g_rngc_eng_cntx->TotalNotes == 0 && (g_rngc_eng_cntx->IsRskLP == RSK_DOWN ||
        g_rngc_eng_cntx->IsRskLP == RSK_LONGPRESS))
    {
	    g_rngc_eng_cntx->IsRskLP = RSK_UP;
    }
    else if (g_rngc_eng_cntx->TotalNotes)
    {
        DeleteCurNote();

        /* change RSK to "Back" if there is no note */
        /*if (!g_rngc_eng_cntx->TotalNotes)
        {
            ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
        }*/
        g_rngc_eng_cntx->IsRskLP = RSK_DOWN;
    }
}


/*****************************************************************************
 * FUNCTION
 *  RngcComposerLSKDownHandler
 * DESCRIPTION
 *  Event handler of LSK down when composing ring tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RngcComposerLSKDownHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rngc_redraw_LSK(1); 
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_END
 * DESCRIPTION
 *  Free the memory and return to Idle Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_END(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FreeMemory();
    StopTimer(NOTE_MULTITAP_TIMER);
    DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_STAR
 * DESCRIPTION
 *  Start key handler
 *  Change note duration/type according to highlighted note.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_STAR(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 nValue;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* highlighted on empty position */
    if (g_rngc_eng_cntx->TotalNotes > MAX_NOTES || g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] == 0xFFFF)
    {
        return;
    }

    StopTimer(NOTE_MULTITAP_TIMER);

    nValue = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & NOTE_MASK;
    switch (nValue)
    {
        case NOTE_LED_ON:
            SetBackLightOn();
            break;
        case NOTE_LED_OFF:
            SetBackLightOff();
            break;
        case NOTE_BACKLIGHT_ON:
    #ifdef __MMI_RNGC_ENABLE_INS_LED_NOTE__
            SetLEDOn();
            break;
    #else /* __MMI_RNGC_ENABLE_INS_LED_NOTE__ */ 
            return;
    #endif /* __MMI_RNGC_ENABLE_INS_LED_NOTE__ */

        case NOTE_BACKLIGHT_OFF:
    #ifdef __MMI_RNGC_ENABLE_INS_LED_NOTE__
            SetLEDOff();
            break;
    #else /* __MMI_RNGC_ENABLE_INS_LED_NOTE__ */ 
            return;	
    #endif /* __MMI_RNGC_ENABLE_INS_LED_NOTE__ */

        case NOTE_C:
        case NOTE_D:
        case NOTE_E:
        case NOTE_F:
        case NOTE_G:
        case NOTE_A:
        case NOTE_B:
            IncrementNoteBeat()break;
        case NOTE_REST:
            IncrementRestBeat()break;
        default:
            return; /* vib/led/backlight, return. */
    }

    PlayCurrentNode();

    mmi_rngc_show_note(g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]);
    if (g_rngc_eng_cntx->TotalNotes != MAX_NOTES && g_rngc_eng_cntx->CurrNoteIndex == g_rngc_eng_cntx->TotalNotes - 1)
    {
        StartTimer(NOTE_MULTITAP_TIMER, MULTITAP_TIME, (FuncPtr) HandleKey_RIGHT_check);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_POUND
 * DESCRIPTION
 *  Pound key handler
 *  Change flag/sharp/normal state of a musical note
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_POUND(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 nValue;
#ifdef __MMI_RING_COMPOSER_REPEAT__
    U32 nRepeat;
#endif    
    U32 nNoteType;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_rngc_eng_cntx->TotalNotes > MAX_NOTES || g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] == 0xFFFF)
    {
        return;
    }

    StopTimer(NOTE_MULTITAP_TIMER);
    nValue = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & NOTE_MASK;
    nNoteType = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & NOTETYPE_MASK;
#ifdef __MMI_RING_COMPOSER_REPEAT__
    nRepeat = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & REPEAT_MASK;

    if (nRepeat == REPEAT_START)
    {
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] = REPEAT_ONE;
        mmi_rngc_show_note(REPEAT_ONE);       
        PlayCurrentNode();
    }
    else if (nRepeat >= REPEAT_INFINITE && nRepeat <= REPEAT_NINE)
    {
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] = NOTE_VIBRATION_ON;
        mmi_rngc_show_note(NOTE_VIBRATION_ON);       
        PlayCurrentNode();
    }
    else
#endif
    {
    switch (nValue)
    {
        case NOTE_C:
        case NOTE_F:
            if (nNoteType == NORMAL)
                SetNoteType(SHARP)
                else
                SetNoteType(NORMAL) break;
        case NOTE_D:
        case NOTE_G:
        case NOTE_A:
            if (nNoteType == NORMAL)
                SetNoteType(FLAT)
                else
            if (nNoteType == FLAT)
                SetNoteType(SHARP)
                else
                SetNoteType(NORMAL) break;
        case NOTE_B:
        case NOTE_E:
            if (nNoteType == NORMAL)
                SetNoteType(FLAT)
                else
                SetNoteType(NORMAL) break;
        #if !defined( __MMI_RING_COMPOSER_NO_VIB__) && defined (__MMI_RING_COMPOSER_REPEAT__)
            case NOTE_VIBRATION_ON:
            case NOTE_VIBRATION_OFF:
                g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] = REPEAT_START;
                mmi_rngc_show_note(REPEAT_START);       
                break;
        #endif
        default:    /* other notes, pound key does not effect */
            return; /* vib/led/backlight, return. */
    }

    PlayCurrentNode();
    mmi_rngc_show_note(g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]);
    }
    if (g_rngc_eng_cntx->TotalNotes != MAX_NOTES && g_rngc_eng_cntx->CurrNoteIndex == g_rngc_eng_cntx->TotalNotes - 1)
    {
        StartTimer(NOTE_MULTITAP_TIMER, MULTITAP_TIME, (FuncPtr) HandleKey_RIGHT_check);
    }

}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_UP
 * DESCRIPTION
 *  Up key handler
 *  Change on/off for vibration/backlight/led notes
 *  Change octave for musical notes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_UP(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 nNoteOctave;
    U32 nValue;
#ifdef __MMI_RING_COMPOSER_REPEAT__
    U32 nRepeat;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_rngc_eng_cntx->TotalNotes > MAX_NOTES || g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] == 0xFFFF)
    {
        return;
    }
    StopTimer(NOTE_MULTITAP_TIMER);

    nValue = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & NOTE_MASK;
    nNoteOctave = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & OCTAVE_MASK;
#ifdef __MMI_RING_COMPOSER_REPEAT__
    nRepeat = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & REPEAT_MASK;
#endif
    switch (nValue)
    {
    #ifdef __MMI_RNGC_ENABLE_INS_LED_NOTE__
        case NOTE_LED_OFF:
            SetLEDOn();
            break;
    #endif /* __MMI_RNGC_ENABLE_INS_LED_NOTE__ */ /* #ifdef __MMI_RNGC_ENABLE_INS_LED_NOTE__ */
            
        case NOTE_BACKLIGHT_OFF:
            SetBackLightOn();
            break;
        case NOTE_VIBRATION_OFF:
            SetVibrationOn();
            break;
        case NOTE_REST:
            break;
        case NOTE_C:
        case NOTE_D:
        case NOTE_E:
        case NOTE_F:
        case NOTE_G:
        case NOTE_A:
        case NOTE_B:
            if (nNoteOctave == OCTAVE_3)
            {
            SetOctave(OCTAVE_4)}
            else if (nNoteOctave == OCTAVE_4)
            {
            SetOctave(OCTAVE_5)}
            else if (nNoteOctave == OCTAVE_5)
            {
            SetOctave(OCTAVE_3)}
            break;
        default:
            break;
    }

#ifdef __MMI_RING_COMPOSER_REPEAT__
    if (nRepeat)
    {
        IncrementRepeatCount();
    }    
#endif    
    PlayCurrentNode();
    mmi_rngc_show_note(g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]);
    /* after pressing up key should not move the cursor */
#ifndef __MMI_TOUCH_RING_COMPOSER__
    if (g_rngc_eng_cntx->TotalNotes != MAX_NOTES && g_rngc_eng_cntx->CurrNoteIndex == g_rngc_eng_cntx->TotalNotes - 1)
    {
        StartTimer(NOTE_MULTITAP_TIMER, MULTITAP_TIME, (FuncPtr) HandleKey_RIGHT_check);
    }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_DOWN
 * DESCRIPTION
 *  Down key handler
 *  Change on/off for vibration/backlight/led notes
 *  Change octave for musical notes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_DOWN(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 nNoteOctave;
    U32 nValue;
#ifdef __MMI_RING_COMPOSER_REPEAT__    
    U32 nRepeat;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_rngc_eng_cntx->TotalNotes > MAX_NOTES || g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] == 0xFFFF)
    {
        return;
    }

    StopTimer(NOTE_MULTITAP_TIMER);

    nValue = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & NOTE_MASK;
    nNoteOctave = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & OCTAVE_MASK;
#ifdef __MMI_RING_COMPOSER_REPEAT__
    nRepeat = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & REPEAT_MASK;
#endif
    switch (nValue)
    {
    #ifdef __MMI_RNGC_ENABLE_INS_LED_NOTE__
        case NOTE_LED_ON:
            SetLEDOff();
            break;
    #endif /* __MMI_RNGC_ENABLE_INS_LED_NOTE__ */ /* #ifdef __MMI_RNGC_ENABLE_INS_LED_NOTE__ */

        case NOTE_BACKLIGHT_ON:
            SetBackLightOff();
            break;
        case NOTE_VIBRATION_ON:
            SetVibrationOff();
            break;
        case NOTE_REST:
            break;
        case NOTE_C:
        case NOTE_D:
        case NOTE_E:
        case NOTE_F:
        case NOTE_G:
        case NOTE_A:
        case NOTE_B:
        {
            if (nNoteOctave == OCTAVE_3)
                SetOctave(OCTAVE_5)
                else
            if (nNoteOctave == OCTAVE_4)
                SetOctave(OCTAVE_3)
                else
            if (nNoteOctave == OCTAVE_5)
                SetOctave(OCTAVE_4) break;
        }
        default:
            break;
    }
#ifdef __MMI_RING_COMPOSER_REPEAT__
    if (nRepeat)
    {
        DecrementRepeatCount();
    }    
#endif
    PlayCurrentNode();
    mmi_rngc_show_note(g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]);
    /* after pressing down key should not move the cursor */
#ifndef __MMI_TOUCH_RING_COMPOSER__
    if (g_rngc_eng_cntx->TotalNotes != MAX_NOTES && g_rngc_eng_cntx->CurrNoteIndex == g_rngc_eng_cntx->TotalNotes - 1)
    {
        StartTimer(NOTE_MULTITAP_TIMER, MULTITAP_TIME, (FuncPtr) HandleKey_RIGHT_check);
    }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_rngc_HandleKey_LEFT_down_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rngc_HandleKey_LEFT_down_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_rngc_eng_cntx->IsSefLeftKeyDown = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rngc_HandleKey_LEFT_up_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rngc_HandleKey_LEFT_up_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*Add check whether self key down event*/
    if(TRUE == g_rngc_eng_cntx->IsSefLeftKeyDown)
    {
        g_rngc_eng_cntx->IsSefLeftKeyDown = FALSE;
        if (g_rngc_eng_cntx->CurrNoteIndex == 0)
        {
            mdi_audio_stop_string();
        srv_prof_play_tone(ERROR_TONE,NULL);
        }	
        else 
        HandleKey_LEFT();
    }
    /*End:check*/
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_LEFT
 * DESCRIPTION
 *  Left key handler
 *  Move cursor left
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_LEFT(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(NOTE_MULTITAP_TIMER);

    if (g_rngc_eng_cntx->CurrNoteIndex > 0)
    {
        --g_rngc_eng_cntx->CurrNoteIndex;

        if (g_rngc_eng_cntx->CurrUIPos == 0)
        {
            mmi_rngc_redraw_notes();
            mmi_rngc_redraw_stave();
        }
        else
        {
            --g_rngc_eng_cntx->CurrUIPos;
            mmi_rngc_redraw_stave();
        }
    #ifdef __MMI_TOUCH_RING_COMPOSER__
        if ( /* touch_rngc_context.mode == GUI_RNGC_EDIT || */ touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT ||
            touch_rngc_context.mode == GUI_RNGC_INSERT)
        {
            mmi_rngc_finish_insert_editing();
        }
    #endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
    }	
#if defined(__MMI_MAINLCD_320X240__)
    mmi_rngc_redraw_remaining_notes();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_RIGHT_check
 * DESCRIPTION
 *  Checks whether error tone is to be played or not
 *  Move cursor right
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_RIGHT_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* already in right boundary */
    if (g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] == 0xFFFF ||
        g_rngc_eng_cntx->CurrNoteIndex + 1 >= MAX_NOTES)
    {
        mdi_audio_stop_string();
        srv_prof_play_tone(ERROR_TONE,NULL);
        return;
    }
    else
        HandleKey_RIGHT();
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_RIGHT
 * DESCRIPTION
 *  Right key handler
 *  Move cursor right
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_RIGHT(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(NOTE_MULTITAP_TIMER);
    if (g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] == 0xFFFF ||
        g_rngc_eng_cntx->CurrNoteIndex + 1 >= MAX_NOTES)
    {
        return;
    }

    if (g_rngc_eng_cntx->CurrNoteIndex < (g_rngc_eng_cntx->TotalNotes))
    {
        ++g_rngc_eng_cntx->CurrNoteIndex;

        if (g_rngc_eng_cntx->CurrUIPos == NUM_NOTES_IN_STAVE - 1)
        {
            /* handle the right movement */
            mmi_rngc_redraw_notes();
            mmi_rngc_redraw_stave();
        }
        else
        {
            ++g_rngc_eng_cntx->CurrUIPos;
            mmi_rngc_redraw_stave();
        }
    }
#ifdef __MMI_TOUCH_RING_COMPOSER__
    if ( touch_rngc_context.mode == GUI_RNGC_EDIT || touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT ||
        touch_rngc_context.mode == GUI_RNGC_INSERT)
    {
        if (touch_rngc_context.mode != GUI_RNGC_EDIT)
        {
        mmi_rngc_finish_insert_editing();
    }
        if (g_rngc_eng_cntx->CurrNoteIndex >= g_rngc_eng_cntx->TotalNotes && 
            touch_rngc_context.mode == GUI_RNGC_EDIT)
        {
        mmi_rngc_reset_toolbar();
        }
    }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
#if defined(__MMI_MAINLCD_320X240__)
    mmi_rngc_redraw_remaining_notes();
#endif

}


/*****************************************************************************
 * FUNCTION
 *  GenerateMelodyFile
 * DESCRIPTION
 *  Generate and write iMelody file to file system
 * PARAMETERS
 *  pFileName       [IN]        Filename
 * RETURNS
 *  enum value of result
 *****************************************************************************/
S32 GenerateMelodyFile(PS8 pFileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *pMelody = NULL;
    S32 err = 0;
    U16 nSize = 0;
    U32 wByte = 0;
    S8 tmpBuff[100];
    S8 FileNameBuff[SRV_FMGR_PATH_MAX_LEN * ENCODING_LENGTH];
    FS_HANDLE fileHandle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* In the case Rngc Create Dir is not */
    err = RngcCreateDir();
    if (err < FS_NO_ERROR)
    {
        return err;
    }

    /* generate filename */
    GenerateCompleteComposeFileName((PS8) pFileName, (PS8) FileNameBuff);
    fileHandle = FS_Open((U16*) RINGCOMPOSER_PATH, FS_OPEN_DIR | FS_READ_ONLY);
    if (fileHandle < 0)
    {
        err = FS_CreateDir((U16*) RINGCOMPOSER_PATH);
    }
    else
    {
        FS_Close(fileHandle);
        err = FS_NO_ERROR;
    }

    if (err != FS_NO_ERROR)
    {
        return err;
    }

    fileHandle = FS_Open((U16*) RNGC_TEMP_PATH, FS_OPEN_DIR | FS_READ_ONLY);
    if (fileHandle < 0)
    {
        err = FS_CreateDir((U16*) RNGC_TEMP_PATH);
        FS_SetAttributes((U16*) RNGC_TEMP_PATH, FS_ATTR_DIR | FS_ATTR_HIDDEN);    
    }
    else
    {
        FS_Close(fileHandle);
        err = FS_NO_ERROR;
    }

    if (err != FS_NO_ERROR)
    {
        return err;
    }

    if (strcmp(pFileName, (S8*) FMGR_TEMP_FILE_MELODY) != 0)
    {
        fileHandle = FS_Open((U16*) FileNameBuff, FS_READ_WRITE | FS_CREATE_ALWAYS);
    }
    else
    {
        memset(FileNameBuff, 0, sizeof(FileNameBuff));
        mmi_ucs2cpy((S8*) FileNameBuff, (S8*) RNGC_TEMP_FILE);
        fileHandle = FS_Open((U16*) FileNameBuff, FS_READ_WRITE | FS_CREATE_ALWAYS | FS_ATTR_HIDDEN);	
    }
	
    if (fileHandle > FS_NO_ERROR)
    {
        /* write header */
        err = FS_Write(fileHandle, MELODY_HEADER, AsciiStrlen((const S8*)MELODY_HEADER), &wByte);
        if (err == 0)
        {
        //#ifdef __MMI_RING_COMPOSER_STYLE__
            sprintf(
                (PS8) tmpBuff,
                "COMPOSER:MTK(%d)\r\nBEAT:%d\r\nSTYLE:S%d\r\nMELODY:",
                g_rngc_cntx.CurrInstr,
                g_rngc_cntx.CurrSpeed,
                g_rngc_cntx.CurrStyle);
        //#else /* __MMI_RING_COMPOSER_STYLE__ */
          /*  sprintf(
                (S8*) tmpBuff,
                "COMPOSER:MTK(%d)\r\nBEAT:%d\r\nMELODY:",
                g_rngc_cntx.CurrInstr,
                g_rngc_cntx.CurrSpeed);*/
        //#endif /* __MMI_RING_COMPOSER_STYLE__ */  
            FS_Write(fileHandle, tmpBuff, AsciiStrlen((const S8*)tmpBuff), &wByte);
        }

        /* generate iMelody string */
        if (err == 0)
        {
            if (g_rngc_eng_cntx->TotalNotes * 7 > 2048)
            {
                err = FS_FAIL_GET_MEM;
            }
            else
            {
                pMelody = OslMalloc(g_rngc_eng_cntx->TotalNotes * 7);
                nSize = GetMelodyFromStruct((PU8) pMelody, (U16) (g_rngc_eng_cntx->TotalNotes * 7));

                err = FS_Write(fileHandle, pMelody, nSize, &wByte);
                OslMfree(pMelody);
            }
        }

        /* write tail */
        if (err == 0)
        {
            err = FS_Write(fileHandle, MELODY_END, AsciiStrlen((const S8*)MELODY_END), &wByte);
        }

        FS_Close(fileHandle);

        if (err < 0)
        {
            FS_Delete((U16*) FileNameBuff);
        }
    }
    else
    {
        err = (S32) fileHandle;
    }

    return err;
}


/*****************************************************************************
 * FUNCTION
 *  GenerateCompleteComposeFileName
 * DESCRIPTION
 *  Generate complete file path+name
 * PARAMETERS
 *  pFileName           [IN]            Filename
 *  pCompletePath       [IN/OUT]        Comple filename+path
 * RETURNS
 *  void
 *****************************************************************************/
void GenerateCompleteComposeFileName(PS8 pFileName, PS8 pCompletePath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 extName[RNGC_FILE_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(extName, 0, sizeof(extName));
    mmi_asc_to_ucs2(extName, MELODY_FILE_EXTENSION);
    mmi_ucs2cpy((S8*) pCompletePath, (S8*) RINGCOMPOSER_PATH);
    mmi_ucs2cat((S8*) pCompletePath, (S8*) pFileName);
    mmi_ucs2cat((S8*) pCompletePath, (S8*) extName);
}


/*****************************************************************************
 * FUNCTION
 *  EditMelody
 * DESCRIPTION
 *  Read an iMelody file and convert to the structure used in program
 *  Display ring tone composer stave
 * PARAMETERS
 *  pFileName       [IN]        Filename
 * RETURNS
 *  void
 *****************************************************************************/
void EditMelody(U8 *pFileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *pMelody = NULL;
    FS_HANDLE fileHandle;
    S32 nFileSize;
    U32 nEror = 0;
    S8 FileNameBuff[SRV_FMGR_PATH_BUFFER_SIZE];        /* padding for filepath */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(FileNameBuff, (S8*) pFileName);
#ifdef __DRM_SUPPORT__
    if (DRM_METHOD_NONE != DRM_get_object_method(0, (PU16)FileNameBuff))
    {
        return;
    }
#endif /* __DRM_SUPPORT__ */ 

    fileHandle = FS_Open((U16*) FileNameBuff, FS_READ_WRITE);
    if (fileHandle > FS_NO_ERROR)
    {
        FS_GetFileSize(fileHandle, (UINT *)&nFileSize);
        if (nFileSize >= RNGC_MAX_FILE_LEN)
        {
            mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_ID_FMGR_FILE_LIMIT_FILE_TOO_LARGE)), MMI_EVENT_FAILURE, NULL);
            FS_Close(fileHandle);
            mmi_fmgr_close_option_screen();
            return;
        }

        pMelody = OslMalloc(nFileSize + 1);

        if (g_rngc_eng_cntx == NULL)
        {
            g_rngc_eng_cntx = OslMalloc(sizeof(rngc_engine_context_struct));
        }
        FS_Read(fileHandle, pMelody, nFileSize, &nEror);
        pMelody[nFileSize] = 0;
        FS_Close(fileHandle);
        g_rngc_eng_cntx->TotalNotes = 0;
        g_rngc_eng_cntx->CurrNoteIndex = 0;
        g_rngc_eng_cntx->CurrUIPos = 0;
        g_rngc_eng_cntx->IsRskLP = RSK_UP;
        RngcInitCursor();
        memset(g_rngc_eng_cntx->NotesList, 0, sizeof(g_rngc_eng_cntx->NotesList));
        g_rngc_cntx.CurrSpeed = NORMAL_SPEED;    /* to sync with media task */
//#ifdef __MMI_RING_COMPOSER_STYLE__    
        g_rngc_cntx.CurrStyle = NORMAL_STYLE;    /* to sync with media task */
//#endif
        g_rngc_cntx.CurrInstr = INSTR_FLUTE;    /* to sync with media task */
        if (GetComposerStructFromMelody((PU8) pMelody))
        {
            memset(
                (void*)(g_rngc_eng_cntx->NotesList + g_rngc_eng_cntx->TotalNotes),
                0xFF,
                sizeof(g_rngc_eng_cntx->NotesList) - (sizeof(U16) * (g_rngc_eng_cntx->TotalNotes)));

            if (g_rngc_eng_cntx->CurrNoteIndex >= NUM_NOTES_IN_STAVE)
            {
                g_rngc_eng_cntx->CurrUIPos = NUM_NOTES_IN_STAVE - 1;
            }
            else
            {
                g_rngc_eng_cntx->CurrUIPos = g_rngc_eng_cntx->CurrNoteIndex;
            }

            if (!EntryRngcComposerEngine())
            {
                OslMfree(g_rngc_eng_cntx);
                g_rngc_eng_cntx = NULL;
                mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_INVALID_FORMAT)), MMI_EVENT_FAILURE, NULL);
                mmi_fmgr_close_option_screen();
            }
        }
        else
        {
            OslMfree(g_rngc_eng_cntx);
            g_rngc_eng_cntx = NULL;
            mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_INVALID_FORMAT)), MMI_EVENT_FAILURE, NULL);
            mmi_fmgr_close_option_screen();
        }

        OslMfree(pMelody);
    }
    else
    {
        mmi_popup_display((WCHAR*)((UI_string_type) GetString(srv_fmgr_fs_error_get_string(fileHandle))), MMI_EVENT_FAILURE, NULL);
        mmi_fmgr_close_option_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetIndexInList
 * DESCRIPTION
 *  This function is to retreive duration/note symbol/octave/type of a musical node
 * PARAMETERS
 *  nNote           [IN]            The value of the musical note
 *  pImageId        [IN/OUT]        Image id to be display for the musical note
 *  pYVal           [IN/OUT]        The y-coordinate of the musical note
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL GetIndexInList(U16 nNote, U16 *pImageId, U16 *pYVal)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nListCount = 0;
    U32 nNoteOctave;
    U32 nValue;
    U32 nDuration;
    U32 nNoteType;
    U32 nIndex;
#ifdef __MMI_RING_COMPOSER_REPEAT__    
    U32 nRepeat;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nDuration = nNote & DURATION_MASK;
    nValue = nNote & NOTE_MASK;
    nNoteOctave = nNote & OCTAVE_MASK;
    nNoteType = nNote & NOTETYPE_MASK;
#ifdef __MMI_RING_COMPOSER_REPEAT__    
    nRepeat = nNote & REPEAT_MASK;
    nRepeat = nRepeat >> 12;
#endif
    *pImageId = 0;
    /* vibe, backlight, led */
    if (nValue >= NOTE_VIBRATION_ON)
    {
        switch (nValue)
        {
            case NOTE_VIBRATION_ON:
                *pImageId = IMG_RING_EVENTVIB_ON;
                break;
            case NOTE_VIBRATION_OFF:
                *pImageId = IMG_RING_EVENTVIB_OFF;
                break;
            case NOTE_LED_ON:
                *pImageId = IMG_RING_EVENTLED_ON;
                break;
            case NOTE_LED_OFF:
                *pImageId = IMG_RING_EVENTLED_OFF;
                break;
            case NOTE_BACKLIGHT_ON:
                *pImageId = IMG_RING_EVENTBL_ON;
                break;
            case NOTE_BACKLIGHT_OFF:
                *pImageId = IMG_RING_EVENTBL_OFF;
                break;
            default:
                break;
        }

        *pYVal = RNGC_EFFECT_NOTE_OFFSET;
        return MMI_TRUE;
    }

#ifdef __MMI_RING_COMPOSER_REPEAT__
    /* If repeat */
    if (nRepeat)
    {
        *pImageId = IMG_RING_REPEAT_START + (nRepeat - 1);
        *pYVal = g_rngc_skin_layout.stave_rectangle_y1 + 2;
    }
#endif
        
    /* OCTAVE_4 and OCTAVE_3 use the same symbol */
#ifdef  RNGC_NOTE_STYLE_STANDARD
    if (nNoteOctave == OCTAVE_4)    /* only octave 4 use the normal musical note */
    {
        nIndex = nNoteType | OCTAVE_3 | nDuration;
    }
    else if (nValue == 1 && nNoteOctave == OCTAVE_3)
    {
        nIndex = nNoteType | OCTAVE_3 | nDuration;
    }
    else
    {
        nIndex = nNoteType | OCTAVE_5 | nDuration;
    }
#else /*RNGC_NOTE_STYLE_STANDARD*/
    if (nNoteOctave == OCTAVE_4)
    {
        nIndex = nNoteType | OCTAVE_3 | nDuration;
    }
    else
    {
        nIndex = nNoteType | nNoteOctave | nDuration;
    }
#endif  /*RNGC_NOTE_STYLE_STANDARD*/

    for (nListCount = 0; nListCount < sizeof(gNotesList); nListCount++)
    {
        if (gNotesList[nListCount].nNote == nIndex)
        {
            nNoteOctave = nNoteOctave >> 6;
            if (nValue == NOTE_REST)
            {
                if (nDuration == DURATION_3BY8 || nDuration == DURATION_1BY4)
                {
                    *pYVal = gnYCoords[21];
                }
                else if (nDuration == DURATION_3BY16 || nDuration == DURATION_1BY8)
                {
                    *pYVal = gnYCoords[22];
                }
                else
                {
                    *pYVal = gnYCoords[23];
                }
            }
            else
            {
                *pYVal = gnYCoords[((nNoteOctave - 1) * 7 + nValue) - 1];
            }

            *pImageId = gNotesList[nListCount].nImageId + COMPOSE_RING_TONE_ENGINE_BASE;
            return MMI_TRUE;
        }
    }

    if (*pImageId == 0)
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  GetMelodyFromStruct
 * DESCRIPTION
 *  This function is to generate iMelody string for a given node
 * PARAMETERS
 *  pList           [IN/OUT]        Strating address to write the iMelody string
 *  nListSize       [IN]            Musical note
 * RETURNS
 *  address of current write cursor
 *****************************************************************************/
U16 GetMelodyFromStruct(U8 *pList, U16 nListSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nCount = 0;
    U8 *pNoteString = pList;
    U8 *pTemp;
    U16 nCurrentNode = g_rngc_eng_cntx->CurrNoteIndex;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_rngc_eng_cntx->CurrNoteIndex = 0;
    while (nCount < g_rngc_eng_cntx->TotalNotes)
    {
        /* insert string of musical note to pNoteString */
        pTemp = GetStringForNode(pNoteString, g_rngc_eng_cntx->NotesList[nCount]);

        /* adjust location of string pointer */
        pNoteString += (pTemp - pNoteString);
        ++g_rngc_eng_cntx->CurrNoteIndex;
        ++nCount;
    }

    *pNoteString = 0;
    g_rngc_eng_cntx->CurrNoteIndex = nCurrentNode;

    return pNoteString - pList;
}


/*****************************************************************************
 * FUNCTION
 *  GetStringForNode
 * DESCRIPTION
 *  This function is to generate iMelody string for a given node
 * PARAMETERS
 *  pStr        [IN/OUT]        Strating address to write the iMelody string
 *  nNote       [IN]            Musical note
 * RETURNS
 *  address of current write cursor
 *****************************************************************************/
U8 *GetStringForNode(U8 *pStr, U32 nNote)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 nNoteOctave;
    U32 nValue;
    U32 nDuration;
    U32 nNoteType;
#ifdef __MMI_RING_COMPOSER_STYLE__    
    U32 nRepeat;
#endif
    U8 *pNote = pStr;
    U16 len, index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* the current note shoulden be "0" */
    MMI_DBG_ASSERT(g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] != 0);
    
    nValue = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & NOTE_MASK;
    nDuration = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & DURATION_MASK;
    nNoteOctave = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & OCTAVE_MASK;
    nNoteType = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & NOTETYPE_MASK;
#ifdef __MMI_RING_COMPOSER_REPEAT__
    nRepeat = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & REPEAT_MASK;

    /* Repeat has no preview */
    if (nRepeat == REPEAT_START)
    {
        memcpy(pNote, "(", 1);
        pNote += 1;
        return pNote;
    }
    else if (nRepeat > REPEAT_START)
    {    
        memcpy(pNote, "@", 1);
        pNote += 1;
        nRepeat = nRepeat >> 12;      
        index = (U16) (nRepeat - 2);
        len = strlen((PS8) gRngcRepeatCount[index]);
        memcpy(pNote, gRngcRepeatCount[index], len);
        pNote += len;
        memcpy(pNote, ")", 1);
        pNote += 1;
        return pNote;
    }
#endif
    /* octave */
    if (nNoteOctave == OCTAVE_3)
    {
        memcpy(pNote, "*3", 2);
        pNote += 2;
    }
    else if (nNoteOctave == OCTAVE_5)
    {
        memcpy(pNote, "*5", 2);
        pNote += 2;
    }

    /* note type */
    if (nNoteType == SHARP)
    {
        memcpy(pNote, "#", 1);
        pNote += 1;
    }
    else if (nNoteType == FLAT)
    {
        memcpy(pNote, "&", 1);
        pNote += 1;
    }

    index = (U16) (nValue - 1);
    len = strlen((PS8) gRngcMusicalNote[index]);
    memcpy(pNote, gRngcMusicalNote[index], len);
    pNote += len;

    if (nDuration > 0)
    {
        index = (U16) (nDuration / DURATION_3BY2 - 1);
        len = strlen((PS8) gRngcDuration[index]);
        memcpy(pNote, gRngcDuration[index], len);
        pNote += len;
    }
    return pNote;
}


/*****************************************************************************
 * FUNCTION
 *  GetComposerStructFromMelody
 * DESCRIPTION
 *  Parsing header of iMelody string, and convert to the structure used in this application
 * PARAMETERS
 *  pMelody     [IN]        IMelody string, including header
 * RETURNS
 *  success or failed
 *****************************************************************************/
U8 GetComposerStructFromMelody(U8 *pMelody)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ptr = pMelody;
    U8 instrument;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!CompareMelody(&ptr, "BEGIN:"))
    {
        return FALSE;
    }
    if (!CompareMelody(&ptr, "IMELODY"))
    {
        return FALSE;
    }
    if (!CompareMelody(&ptr, "VERSION:"))
    {
        return FALSE;
    }

    if (!CompareMelody(&ptr, "1.0") && !CompareMelody(&ptr, "1.1") && !CompareMelody(&ptr, "1.2"))
    {
        return FALSE;
    }

    if (!CompareMelody(&ptr, "FORMAT:"))
    {
        return FALSE;
    }
    if (!CompareMelody(&ptr, "CLASS1.0") && !CompareMelody(&ptr, "CLASS2.0"))
    {
        return FALSE;
    }

    while (*ptr != 0)
    {
        if (CompareMelody(&ptr, "NAME:"))   /* ignore song name */
        {
            ClearToEnd(&ptr);
        }
        else if (CompareMelody(&ptr, "COMPOSER:"))
        {   /* ignore composer name */
            g_rngc_cntx.CurrInstr = GetInstrument(&ptr);
            /* check instrument */
            for (instrument = 0; instrument < ENUM_TOTAL_INSTR; instrument++)
            {
                if (g_rngc_cntx.CurrInstr == CurrentInstrument[instrument])
                {
                    break;
                }
            }
            if( instrument == ENUM_TOTAL_INSTR)
            {
                return FALSE;
            }
            ClearToEnd(&ptr);
        }
        else if (CompareMelody(&ptr, "BEAT:"))
        {
            g_rngc_cntx.CurrSpeed = (U16) GetBeat(&ptr);
            /* Any value below 25 is played with speed 120 by lower layer*/
            if (g_rngc_cntx.CurrSpeed >= 0 && g_rngc_cntx.CurrSpeed <= 25 )
                g_rngc_cntx.CurrSpeed = 120;
            ClearToEnd(&ptr);
        }
        else if (CompareMelody(&ptr, "STYLE:"))
        {
    //#ifdef __MMI_RING_COMPOSER_STYLE__        
            g_rngc_cntx.CurrStyle = (U8) GetStyle(&ptr);
    //#endif        
            ClearToEnd(&ptr);
        }
        else if (CompareMelody(&ptr, "VOLUME:"))
        {
            ClearToEnd(&ptr);
        }
        else if (CompareMelody(&ptr, "MELODY:"))
        {
            if (GetMelody(&ptr) == FALSE)
            {
                return FALSE;
            }

            if (!CompareMelody(&ptr, "END:IMELODY"))
            {
                return FALSE;
            }
            break;
        }
        else
        {
            return FALSE;
        }
    }
    
    /* boundary check, CurrNoteIndex => [0,149]*/
    if (g_rngc_eng_cntx->CurrNoteIndex == MAX_NOTES)
    {
        g_rngc_eng_cntx->CurrNoteIndex--;
    }
    
    return TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  GetMelody
 * DESCRIPTION
 *  Retrieve musical note according to the melody string
 * PARAMETERS
 *  pptr        [IN]        Pointer of an iMelody string
 * RETURNS
 *  success or failed
 *****************************************************************************/
U8 GetMelody(U8 **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 **ptr = pptr;
    U8 *t;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (**ptr)
    {
        t = *ptr;
        if (g_rngc_eng_cntx->TotalNotes == MAX_NOTES)
        {
            if (**ptr == 10 || **ptr == 13)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if (g_rngc_eng_cntx->TotalNotes > MAX_NOTES)
        {
            return FALSE;
        }

        switch (**ptr)
        {
            case '*':
            {
                if (SetOctaveFromStream(pptr))
                {
                    break;
                }
                else
                {
                    return FALSE;
                }
            }
            case 'b':
            {
                if (SetBackLight(pptr))
                {
                    ++g_rngc_eng_cntx->CurrNoteIndex;
                    ++g_rngc_eng_cntx->TotalNotes;
                    break;
                }
                else
                {
                    if (SetNote(pptr))
                    {
                        ++g_rngc_eng_cntx->CurrNoteIndex;
                        ++g_rngc_eng_cntx->TotalNotes;
                        break;
                    }
                    else
                    {
                        return FALSE;
                    }
                }
            }
            case '&':
            case '#':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
            case 'g':
            case 'a':
            {
                if (SetNote(pptr))
                {
                    ++g_rngc_eng_cntx->CurrNoteIndex;
                    ++g_rngc_eng_cntx->TotalNotes;
                    break;
                }
                else
                {
                    return FALSE;
                }
            }
            case 'r':
            {
                /* duration */
                t++;
                if (*t == '0' || *t == '1')
                    return FALSE;
                if (SetNote(pptr))
                {
                    ++g_rngc_eng_cntx->CurrNoteIndex;
                    ++g_rngc_eng_cntx->TotalNotes;
                    break;
                }
                else
                {
                    return FALSE;
                }
            }
#ifdef __MMI_RING_COMPOSER_REPEAT__
            case '(':
            case '@':
            {
                if (SetRepeat(pptr))
                {
                    ++g_rngc_eng_cntx->CurrNoteIndex;
                    ++g_rngc_eng_cntx->TotalNotes;
                    break;
                }
                else
                {
                    return FALSE;
                }
            }
#endif            
        #ifndef __MMI_RING_COMPOSER_NO_LED__
            case 'l':
            {
                if (SetLED(pptr))
                {
                    ++g_rngc_eng_cntx->CurrNoteIndex;
                    ++g_rngc_eng_cntx->TotalNotes;
                    break;
                }
                else
                {
                    return FALSE;
                }
            }
        #endif /* __MMI_RING_COMPOSER_NO_LED__ */ 
        #ifndef __MMI_RING_COMPOSER_NO_VIB__
            case 'v':
            {
                if (SetVibration(pptr))
                {
                    ++g_rngc_eng_cntx->CurrNoteIndex;
                    ++g_rngc_eng_cntx->TotalNotes;
                    break;
                }
                else
                {
                    return FALSE;
                }
            }
        #endif /* __MMI_RING_COMPOSER_NO_VIB__ */ 
            case 10:    /* 0x0A */
            case 13:    /* 0x0D */
                return TRUE;
            default:
                return FALSE;
        }
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  SetBackLight
 * DESCRIPTION
 *  Insert a backlight node to gpComposer->NotesList
 * PARAMETERS
 *  pptr        [IN]        Pointer of an iMelody string
 * RETURNS
 *  success or failed
 *****************************************************************************/
U8 SetBackLight(U8 **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!StrnCmp((PS8) * pptr, "backon", 6))
    {
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NOTE_BACKLIGHT_ON;
        (*pptr) += 6;
    }
    else if (!StrnCmp((PS8) * pptr, "backoff", 7))
    {
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NOTE_BACKLIGHT_OFF;
        (*pptr) += 7;
    }
    else
    {
        return FALSE;
    }

    return TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  SetVibration
 * DESCRIPTION
 *  Insert a vibration node to gpComposer->NotesList
 * PARAMETERS
 *  pptr        [IN]        Pointer of an iMelody string
 * RETURNS
 *  success or failed
 *****************************************************************************/
U8 SetVibration(U8 **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!StrnCmp((PS8) * pptr, "vibeon", 6))
    {
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NOTE_VIBRATION_ON;
        (*pptr) += 6;
    }
    else if (!StrnCmp((PS8) * pptr, "vibeoff", 7))
    {
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NOTE_VIBRATION_OFF;
        (*pptr) += 7;
    }
    else
    {
        return FALSE;
    }

    return TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  SetLED
 * DESCRIPTION
 *  Insert an LED node to gpComposer->NotesList
 * PARAMETERS
 *  pptr        [IN]        Pointer of an iMelody string
 * RETURNS
 *  success or failed
 *****************************************************************************/
U8 SetLED(U8 **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_RNGC_ENABLE_INS_LED_NOTE__
    if (!StrnCmp((PS8) * pptr, "ledon", 5))
    {
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NOTE_LED_ON;
        (*pptr) += 5;
    }
    else if (!StrnCmp((PS8) * pptr, "ledoff", 6))
    {
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NOTE_LED_OFF;
        (*pptr) += 6;
    }
    else
    {
        return FALSE;
    }

    return TRUE;
#else /* __MMI_RNGC_ENABLE_INS_LED_NOTE__ */
    return FALSE;
#endif /* __MMI_RNGC_ENABLE_INS_LED_NOTE__ */
}


#ifdef __MMI_RING_COMPOSER_REPEAT__
/*****************************************************************************
 * FUNCTION
 *  SetRepeat
 * DESCRIPTION
 *  Insert the repeat note to gpComposer->NotesList
 * PARAMETERS
 *  pptr        [IN]        Pointer of an iMelody string
 * RETURNS
 *  success or failed
 *****************************************************************************/
U8 SetRepeat(U8 **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 RepeatCount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_rngc_eng_cntx->TotalNotes > MAX_NOTES)
    {
        return FALSE;
    }

    /* flag/normal/sharp */
    if (**pptr == '(')
    {
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] = REPEAT_START;
        ++(*pptr);
        return TRUE;
    }
    else if (**pptr == '@')
    {
        /* Checking for the repeat count*/
        ++(*pptr);
        if (**pptr > '9' || **pptr < '0' || 
            (*(*pptr+1) < '9' && *(*pptr+1) > '0' ))
            return FALSE;
        else
        {
            RepeatCount = REPEAT_INFINITE;
            RepeatCount = RepeatCount >> 12;
            RepeatCount += **pptr;
            RepeatCount = RepeatCount << 12;
            g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= RepeatCount;
        }        
        ++(*pptr);
    }
    
    /* Skipping the repeat brace*/
    if (**pptr != ')')
        return FALSE;
    else 
        ++(*pptr);

    return TRUE;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  SetNote
 * DESCRIPTION
 *  Insert a musical node to gpComposer->NotesList
 * PARAMETERS
 *  pptr        [IN]        Pointer of an iMelody string
 * RETURNS
 *  success or failed
 *****************************************************************************/
U8 SetNote(U8 **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nDuration;
    U16 nNoteOctave;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_rngc_eng_cntx->TotalNotes > MAX_NOTES)
    {
        return FALSE;
    }

    /* flag/normal/sharp */
    if (**pptr == '#')
    {
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= SHARP;
        ++(*pptr);
    }
    else if (**pptr == '&')
    {
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= FLAT;
        ++(*pptr);
    }
    else
    {
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NORMAL;
    }

    /* musical notation */
    switch (**pptr)
    {
        case 'c':
            g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] =
                g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] | NOTE_C;
            break;
        case 'd':
            g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NOTE_D;
            break;
        case 'e':
            g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NOTE_E;
            break;
        case 'f':
            g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NOTE_F;
            break;
        case 'g':
            g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NOTE_G;
            break;
        case 'a':
            g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NOTE_A;
            break;
        case 'b':
            g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NOTE_B;
            break;
        case 'r':
            g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NOTE_REST;
            g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] &= CLEAR_NOTETYPE_MASK;
            break;

        default:
            return FALSE;
    }

    /* duration */
    ++(*pptr);
    nDuration = GetInteger(pptr);

    switch (nDuration)
    {
        case 0:
            if (**pptr == '.')
            {
                g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= DURATION_3BY2;
                ++(*pptr);
            }
            else
            {
                g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= DURATION_1;
            }
            break;
        case 1:
            if (**pptr == '.')
            {
                g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= DURATION_3BY4;
                ++(*pptr);
            }
            else
            {
                g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= DURATION_1BY2;
            }
            break;
        case 2:
            if (**pptr == '.')
            {
                g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= DURATION_3BY8;
                ++(*pptr);
            }
            else
            {
                g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= DURATION_1BY4;
            }
            break;
        case 3:
            if (**pptr == '.')
            {
                g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= DURATION_3BY16;
                ++(*pptr);
            }
            else
            {
                g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= DURATION_1BY8;
            }
            break;
        case 4:
            if (**pptr == '.')
            {
                g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= DURATION_3BY32;
                ++(*pptr);
            }
            else
            {
                g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= DURATION_1BY16;
            }
            break;
        default:
            return FALSE;
    }

    nNoteOctave = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & OCTAVE_MASK;

    if (nNoteOctave != OCTAVE_3 && nNoteOctave != OCTAVE_5)
    {
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= OCTAVE_4;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  SetOctaveFromStream
 * DESCRIPTION
 *  Retrieve the octave of a musical node and save to gpComposer->NotesList
 * PARAMETERS
 *  pptr        [IN]        Pointer of an iMelody string
 * RETURNS
 *  success or failed
 *****************************************************************************/
U8 SetOctaveFromStream(U8 **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!StrnCmp((PS8) * pptr, "*3", 2))
    {
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= OCTAVE_3;
    }
    else if (!StrnCmp((PS8) * pptr, "*4", 2))
    {
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= OCTAVE_4;
    }
    else if (!StrnCmp((PS8) * pptr, "*5", 2))
    {
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= OCTAVE_5;
    }
    else
    {
        return FALSE;
    }

    (*pptr) += 2;

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  GetBeat
 * DESCRIPTION
 *  Retrieve beat length of the iMelody string
 * PARAMETERS
 *  pptr        [IN]        Pointer of an iMelody string
 * RETURNS
 *  beat length
 *****************************************************************************/
U16 GetBeat(U8 **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SkipSpace(pptr);
    return (U16) GetInteger(pptr);
}


//#ifdef __MMI_RING_COMPOSER_STYLE__
/*****************************************************************************
 * FUNCTION
 *  GetStyle
 * DESCRIPTION
 *  Retrieve style of the iMelody string
 * PARAMETERS
 *  pptr        [IN]        Pointer of an iMelody string
 * RETURNS
 *  Play Style
 *****************************************************************************/
U16 GetStyle(U8 **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SkipSpace(pptr);
    if (!StrnCmp((PS8)* pptr, "S0", 2)||!StrnCmp((PS8)* pptr, "0", 2))
    {
        return (U16)0;
}
    else if (!StrnCmp((PS8)* pptr, "S1", 2)||!StrnCmp((PS8)* pptr, "1", 2))
        {
        return (U16) 1;
}
    else if (!StrnCmp((PS8)* pptr, "S2", 2)||!StrnCmp((PS8)* pptr, "2", 2))
{
        return (U16) 2;
    }
    else
    {
        return (U16)0;
        }
}
//#endif

/*****************************************************************************
 * FUNCTION
 *  GetInstrument
 * DESCRIPTION
 *  Retrieve instrument of the iMelody string
 * PARAMETERS
 *  pptr        [IN]        Pointer of an iMelody string
 * RETURNS
 *  index of instrument
 *****************************************************************************/
U8 GetInstrument(U8 **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SkipSpace(pptr);
    for (ptr = *pptr; *ptr != 0; ptr++)
    {
        if (*ptr == '(')
    {
        ptr++;
            return ((U8) GetInteger(&ptr));
    }
            }
    return INSTR_FLUTE;
        }
        

/*****************************************************************************
 * FUNCTION
 *  GetInstrumentString
 * DESCRIPTION
 *  Retrieve the image id of instrument
 * PARAMETERS
 *  instru_type     [IN]        Index of currrent instrument
 * RETURNS
 *  image id of the instrument
 *****************************************************************************/
U16 GetInstrumentString(U8 instru_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (instru_type)
    {
#if defined(RNGC_SUPPORT_INSTR_STYLE1)
        case INSTR_PIANO:
            return STR_COMP_RINGTONE_PIANO;
        case INSTR_HARMONICA:
            return STR_COMP_RINGTONE_HARMONICA;
        case INSTR_GUITAR:
            return STR_COMP_RINGTONE_GUITAR;
        case INSTR_VIOLIN:
            return STR_COMP_RINGTONE_VIOLIN;
        case INSTR_SPHONE:
            return STR_COMP_RINGTONE_SAXOPHONE;
        case INSTR_FLUTE:
            return STR_COMP_RINGTONE_FLUTE;
        case INSTR_TRUMPET:
            return STR_COMP_RINGTONE_TRUMPET;
        case INSTR_SDRUMS:
            return STR_COMP_RINGTONE_STEELDRUMS;
            
#elif defined(RNGC_SUPPORT_INSTR_STYLE2)
        case INSTR_GUITAR:
            return STR_COMP_RINGTONE_GUITAR;
        case INSTR_VIOLIN:
            return STR_COMP_RINGTONE_VIOLIN;
        case INSTR_FLUTE:
            return STR_COMP_RINGTONE_FLUTE;
        case INSTR_TRUMPET:
            return STR_COMP_RINGTONE_TRUMPET;
#else
        case INSTR_PIANO:
            return STR_COMP_RINGTONE_PIANO;
        case INSTR_MUSICBOX:
            return STR_COMP_RINGTONE_MUSICBOX;
        case INSTR_XYLOPHONE:
            return STR_COMP_RINGTONE_XYLOPHONE;
        case INSTR_HARMONICA:
            return STR_COMP_RINGTONE_HARMONICA;
        case INSTR_GUITAR:
            return STR_COMP_RINGTONE_GUITAR;
        case INSTR_VIOLIN:
            return STR_COMP_RINGTONE_VIOLIN;
        case INSTR_SPHONE:
            return STR_COMP_RINGTONE_SAXOPHONE;
        case INSTR_FLUTE:
            return STR_COMP_RINGTONE_FLUTE;
        case INSTR_TRUMPET:
            return STR_COMP_RINGTONE_TRUMPET;
        case INSTR_SDRUMS:
            return STR_COMP_RINGTONE_STEELDRUMS;
#endif  
        
        default:
            return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetInstrumentImage
 * DESCRIPTION
 *  Retrieve the image id of instrument
 * PARAMETERS
 *  instru_type     [IN]        Index of currrent instrument
 * RETURNS
 *  image id of the instrument
 *****************************************************************************/
U16 GetInstrumentImage(U8 instru_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (instru_type)
    {
#if defined(RNGC_SUPPORT_INSTR_STYLE1)
        case INSTR_PIANO:
            return IMG_RING_INSTRU6;
        case INSTR_HARMONICA:
            return IMG_RING_INSTRU4;
        case INSTR_GUITAR:
            return IMG_RING_INSTRU3;
        case INSTR_VIOLIN:
            return IMG_RING_INSTRU8;
        case INSTR_SPHONE:
            return IMG_RING_INSTRU7;
        case INSTR_FLUTE:
            return IMG_RING_INSTRU2;
        case INSTR_TRUMPET:
            return IMG_RING_INSTRU9;
        case INSTR_SDRUMS:
            return IMG_RING_INSTRU1;
            
#elif defined(RNGC_SUPPORT_INSTR_STYLE2)
        case INSTR_GUITAR:
            return IMG_RING_INSTRU3;
        case INSTR_VIOLIN:
            return IMG_RING_INSTRU8;
        case INSTR_FLUTE:
            return IMG_RING_INSTRU2;
        case INSTR_TRUMPET:
            return IMG_RING_INSTRU9;
#else
        case INSTR_PIANO:
            return IMG_RING_INSTRU6;
        case INSTR_MUSICBOX:
            return IMG_RING_INSTRU5;
        case INSTR_XYLOPHONE:
            return IMG_RING_INSTRU10;
        case INSTR_HARMONICA:
            return IMG_RING_INSTRU4;
        case INSTR_GUITAR:
            return IMG_RING_INSTRU3;
        case INSTR_VIOLIN:
            return IMG_RING_INSTRU8;
        case INSTR_SPHONE:
            return IMG_RING_INSTRU7;
        case INSTR_FLUTE:
            return IMG_RING_INSTRU2;
        case INSTR_TRUMPET:
            return IMG_RING_INSTRU9;
        case INSTR_SDRUMS:
            return IMG_RING_INSTRU1;
#endif  
        default:
            return 0;
    }
}


#ifdef __MMI_RING_COMPOSER_REPEAT__
/*****************************************************************************
 * FUNCTION
 *  Repeat Begin
 * DESCRIPTION
 *  Retrieve beginning of the repeat block
 * PARAMETERS
 *  pptr        [IN]        Pointer of an iMelody string
 * RETURNS
 *  
 *****************************************************************************/
U16 RepeatBegin(U8 **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SkipSpace(pptr);
    return (U16) GetInteger(pptr);
}


/*****************************************************************************
 * FUNCTION
 *  Repeat End
 * DESCRIPTION
 *  Retrieve end of the repeat block
 * PARAMETERS
 *  pptr        [IN]        Pointer of an iMelody string
 * RETURNS
 *  
 *****************************************************************************/
U16 RepeatEnd(U8 **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SkipSpace(pptr);
    return (U16) GetInteger(pptr);
}


/*****************************************************************************
 * FUNCTION
 *  Repeat Count
 * DESCRIPTION
 *  Retrieve count of the repeat block
 * PARAMETERS
 *  pptr        [IN]        Pointer of an iMelody string
 * RETURNS
 *  
 *****************************************************************************/
U16 RepeatCount(U8 **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SkipSpace(pptr);
    return (U16) GetInteger(pptr);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  GetInteger
 * DESCRIPTION
 *  Retrieve an integral value of an iMelody string, parsing unitl no integral character found
 * PARAMETERS
 *  pptr        [IN]        Pointer of an iMelody string
 * RETURNS
 *  integral value
 *****************************************************************************/
S32 GetInteger(U8 **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ptr = *pptr;
    U8 ch;
    S32 val;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ch = *ptr;
    if (!(ch >= '0' && ch <= '9'))
    {
        return -1;
    }
    val = ch - '0';
    ptr++;

    for (;;)
    {
        ch = *ptr;
        if (!(ch >= '0' && ch <= '9'))
{
            break;
    }
        val = val * 10 + ch - '0';
        ptr++;
    }
    *pptr = ptr;
    return (S32) val;
}


/*****************************************************************************
 * FUNCTION
 *  CompareMelody
 * DESCRIPTION
 *  Compare iMelody and keywords.
 * PARAMETERS
 *  pptr        [IN]        Pointer of an iMelody string
 *  ps          [IN]        Pointer of keywords
 * RETURNS
 *  index of instrument
 *****************************************************************************/
U8 CompareMelody(U8 **pptr, void *ps)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nLen = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TrimStr(pptr);

    nLen = strlen(ps);
    if (StrnCmp((PS8) * pptr, ps, nLen))
	{
        return FALSE;
	}	    
    *pptr += nLen;
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  Tolower
 * DESCRIPTION
 *  Convert a charcater to lower case
 * PARAMETERS
 *  ch      [IN]        Charcater to be converted
 * RETURNS
 *  lower case character
 *****************************************************************************/
U8 Tolower(U8 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch >= 'A' && ch <= 'Z')
    {
        return (U8) (ch + ('a' - 'A'));
    }
    return ch;
}


/*****************************************************************************
 * FUNCTION
 *  StrnCmp
 * DESCRIPTION
 *  Convert a charcater to lower case
 * PARAMETERS
 *  s1          [IN]        String pointer to be compared
 *  s2          [IN]        String pointer to be compared
 *  maxlen      [IN]        Lengh to be compared
 * RETURNS
 *  Ture if two string is identical, otherwise, false
 *****************************************************************************/
S8 StrnCmp(S8 *s1, S8 *s2, int maxlen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ch1, ch2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (maxlen-- > 0)
    {
        ch1 = Tolower(*s1++);
        ch2 = Tolower(*s2++);
        if (ch1 > ch2)
        {
            return 1;
        }
        if (ch1 < ch2)
        {
            return (U8) - 1;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  SkipSpace
 * DESCRIPTION
 *  Skip space and tab within a string
 * PARAMETERS
 *  pptr        [IN]        String pointer
 * RETURNS
 *  void
 *****************************************************************************/
void SkipSpace(U8 **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ptr = *pptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*ptr == ' ' || *ptr == '\t')
    {
        ptr++;
        }
    *pptr = ptr;
        
}


/*****************************************************************************
 * FUNCTION
 *  ClearToEnd
 * DESCRIPTION
 *  Skip \n, \r within a string
 * PARAMETERS
 *  pptr        [IN]        String pointer
 * RETURNS
 *  void
 *****************************************************************************/
void ClearToEnd(U8 **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ptr = *pptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*ptr != '\n' && *ptr != '\r')
    {
        ptr++;
    }
    *pptr = ptr;
}


/*****************************************************************************
 * FUNCTION
 *  TrimStr
 * DESCRIPTION
 *  Skip \n, \r, \t, and space within a string
 * PARAMETERS
 *  pptr        [IN]        String pointer
 * RETURNS
 *  void
 *****************************************************************************/
void TrimStr(U8 **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ptr = *pptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    while (*ptr && (*ptr == ' ' || *ptr == '\t' || *ptr == '\n' || *ptr == '\r'))
    {
        ptr++;
            }
    *pptr = ptr;
        }
#endif /* defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__) */ 

