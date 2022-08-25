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
*  AMShortcut.h
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  AM Shortcut head file.
*
* Author:
* -------
*  
*
*==============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*------------------------------------------------------------------------------
 * removed!
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#ifndef AM_SHORTCUT_H
#define AM_SHORTCUT_H

#if defined(__MMI_MRE_SUB_MENU__)||defined( __MMI_MRE_MAIN_MENU__)

#include "kal_general_types.h"
#include "MMIDataType.h"

#define MAX_ICON_FILE_NAME_SIZE     10

/***************************************************************************** 
* Typedef 
*****************************************************************************/
enum
{
    MMI_AM_SHORTCUT_SET_SUCCESS = 0,
    MMI_AM_SHORTCUT_OVER_NUMBER,
    MMI_AM_SHORTCUT_STRUCTURE_FAIL,
    MMI_AM_SHORTCUT_FILE_FAIL,
    MMI_AM_SHORTCUT_DUPLICATE_ID,
    MMI_AM_SHORTCUT_ICON_SIZE_FAIL,
    MMI_AM_SHORTCUT_FILE_NOT_FOUND,
    MMI_AM_SHORTCUT_CERT_EXPIRED,
    MMI_AM_SHORTCUT_WRONG_DATE,
    MMI_AM_SHORTCUT_IMSI_DISMATCH,
    MMI_AM_SHORTCUT_WRONG_PLATFORM
};

/****************************************************************************
* Extern Global Function                                                            
*****************************************************************************/
extern MMI_BOOL mmi_am_is_set_as_shortcut(U16 *full_path);
extern S32 mmi_am_set_as_shortcut(U16 *full_path, U8 *icon_buffer, U32 icon_size);
void mmi_am_cancel_shortcut(U16 *path);
MMI_BOOL mmi_am_is_shortcut_support(void);

#endif /* __VENUS_UI_ENGINE__ */ 

#endif /* AM_SHORTCUT_H */ 

