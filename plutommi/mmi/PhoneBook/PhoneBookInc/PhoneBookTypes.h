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
 *  PhoneBookTypes.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  phone book application 
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _PHONEBOOKTYPES_H
#define _PHONEBOOKTYPES_H

#include "MMIDataType.h"
#include "audioinc.h"
#include "SettingProfile.h"
#include "PhoneBookGprot.h"
/* NVRAM_REVISE */
#include "custom_mmi_default_value.h"
#include "nvram_common_defs.h"
#include "custom_equipment.h"
#if 0
#ifdef __MMI_UCM__
/* under construction !*/
#endif
#endif

#ifdef __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__
typedef enum
{
    MMI_PHB_MOBILE_NUMBER,
    MMI_PHB_OPTION_NUMBER_1,
    MMI_PHB_OPTION_NUMBER_2,
    MMI_PHB_OPTION_NUMBER_3,
    MMI_PHB_MAX_NUMBER_COUNT
} MMI_PHB_NUMBERS;
#endif /* __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__ */ 

/* 
 * Define
 */

#if defined(__MMI_PHB_CALLER_VIDEO__)
#define MAX_CALLER_GRP_ITEMS  7
#else /* defined(__MMI_PHB_CALLER_VIDEO__) */ 
#define MAX_CALLER_GRP_ITEMS  6
#endif /* defined(__MMI_PHB_CALLER_VIDEO__) */ 

#define MAX_SEARCH_NAME_LENGTH   10



#define MAX_MMS_OBJECT 13

/* 
 * Extern Global Function
 */

/* 
 * Typedef 
 */
typedef enum
{
    MMI_PHB_RECV_RES_IMAGE,
    MMI_PHB_RECV_RES_AUDIO,
    MMI_PHB_RECV_RES_VIDEO,
    MMI_PHB_RECV_RES_AVATAR_IMAGE,
    MMI_PHB_RECV_RES_AVATAR_VIDEO,
    MMI_PHB_RECV_RES_SWFLASH
} mmi_phb_receive_resource_enum;

typedef enum
{
    MMI_PHB_QUICK_SEARCH_MAIN,
    MMI_PHB_QUICK_SEARCH_GENERIC,
    MMI_PHB_QUICK_SEARCH_ENUM_TOTAL
} MMI_PHB_QUICK_SEARCH_ENUM;


typedef enum
{
    MMI_PHB_SAVE_CONTACT_NOTIFY_OFF,
    MMI_PHB_SAVE_CONTACT_NOTIFY_ON
} MMI_PHB_SAVE_CONTACT_NOTIFY_ENUM;


typedef enum
{
    MMI_PHB_EDIT_VIDEO_OPTION_AUDIO_OFF,
    MMI_PHB_EDIT_VIDEO_OPTION_AUDIO_ON
}MMI_PHB_EDIT_VIDEO_OPTION_AUDIO_ENUM;


#ifdef __MMI_PHB_UI_IN_TABS__
typedef enum
{
    MMI_PHB_INLINE_TAB_0,
    MMI_PHB_INLINE_TAB_1,
    MMI_PHB_INLINE_TAB_2,
    MMI_PHB_INLINE_TAB_3,
    MMI_PHB_INLINE_TAB_4,
    MMI_PHB_INLINE_TAB_ENUM_TOTAL
}mmi_phb_inline_tab_enum;
#endif

typedef enum
{
    MMI_PHB_UNSAVED_DATA_OP_NONE,
    MMI_PHB_UNSAVED_DATA_OP_NORMAL,
    MMI_PHB_UNSAVED_DATA_OP_REENTRY,
    MMI_PHB_UNSAVED_DATA_OP_ENUM_TOTAL
}mmi_phb_unsaved_data_op_state_enum;

#endif /* _PHONEBOOKTYPES_H */ 

