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
 * EngineerModeInetAppProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for Engineering mode for Inertnet Application 
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _ENGINEER_MODE_INET_PROT_H
#define _ENGINEER_MODE_INET_PROT_H

#include "MMI_features.h"
#include "nvram_common_defs.h"
#include "EngineerModeInetAppGprot.h"
#include "MMIDataType.h"
#include "app_ua.h"
#include "custom_wap_config.h"

/****************************************************************************** 
 * Include
 ******************************************************************************/
#if defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_EM_INET_APP_SLIM__)
/***************************************************************************** 
 * Constant
 *****************************************************************************/ 

/* Max. length of user agent string, defined in nvram_common_defs.h */
#define MMI_EM_INET_MAX_UA_STRING_LEN    NVRAM_EF_INET_MAX_UA_STRING_LEN 

/* Max. length of user agent profile, defined in nvram_common_defs.h */
#define MMI_EM_INET_MAX_UA_PROFILE_LEN   NVRAM_EF_INET_MAX_UA_PROFILE_LEN

/****************************************************************************** 
 * Event handler
 ******************************************************************************/
/* Please declare the event handle function prototype here. Add compile option if necessary */

/****************************************************************************** 
 * Custom value
 ******************************************************************************/
/* This is for user agent name list 
   There are 17 names here, including the editable setting. */
#define MMI_EM_INET_USER_AGENT_TOTAL                APPLIB_INET_USER_AGENT_TOTAL


    
  
#endif /* ! __MMI_EM_INET_APP_SLIM__ */




#if defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_EM_INET_APP_SLIM__)
/****************************************************************************** 
 * ENUM
 ******************************************************************************/
/* This enum is used to indicate the menu item in main screen. */
typedef enum
{
    MMI_EM_INET_MAIN_MENU_ITEM_USER_AGENT = 0,
    MMI_EM_INET_MAIN_MENU_ITEM_ACCEPT_HEADER,
    MMI_EM_INET_MAIN_MENU_ITEM_MMS_VERSION,
    MMI_EM_INET_MAIN_MENU_ITEM_TOTAL
} mmi_em_inet_main_menu_item_enum;


/* This enum is used to indicate the menu item in edit user agent screen. */
typedef enum
{
    MMI_EM_INET_UA_EDIT_INLINE_ITEM_STRING_STR = 0,
    MMI_EM_INET_UA_EDIT_INLINE_ITEM_STRING,
    MMI_EM_INET_UA_EDIT_INLINE_ITEM_PROFILE_STR,
    MMI_EM_INET_UA_EDIT_INLINE_ITEM_PROFILE,      
	MMI_EM_INET_UA_EDIT_TOTAL
} mmi_em_inet_ua_edit_inline_item_enum;


/* This enum is used to indicate the type which user wants to edit. */
typedef enum
{
    MMI_EM_INET_UA_EDIT_MENU_ITEM_STRING = 0,
    MMI_EM_INET_UA_EDIT_MENU_ITEM_PROFILE,
    MMI_EM_INET_UA_EDIT_MENU_ITEM_TOTAL
} mmi_em_inet_ua_edit_menu_item_enum;



/****************************************************************************** 
 * Typedef
 ******************************************************************************/

/* This structure is to store the value for editing user agent in UCS2 format */
typedef struct{
    WCHAR string[(MMI_EM_INET_MAX_UA_STRING_LEN + 1)];   /* 1 for null terminator */
    WCHAR profile[(MMI_EM_INET_MAX_UA_PROFILE_LEN + 1)]; /* 1 for null terminator */
} mmi_em_inet_user_agent_edit_struct;



typedef struct {
    mmi_em_inet_user_agent_edit_struct *edit_user_agent_p;      /* (UI) This is for editing user agent */
    MMI_ID inline_cui_id;
    U32 select_index; /* (UI) used for identifying menu select item */
} mmi_em_inet_dynamic_cntx_struct;



/****************************************************************************** 
 * External Variable
 ******************************************************************************/



/***************************************************************************** 
 * Global Function 
 *****************************************************************************/

extern void mmi_em_inet_init(void);
extern void mmi_em_inet_highlight_main(void);
extern void mmi_em_inet_highlight_ua_main(void);
extern void mmi_em_inet_highlight_ua_activate(void);
extern void mmi_em_inet_highlight_ua_edit(void);
extern void mmi_em_inet_highlight_accept_header(void);
extern void mmi_em_inet_highlight_mms_version(void);


#endif /* !__MMI_EM_INET_APP_SLIM__ */
#endif /* _ENGINEER_MODE_INET_H */
