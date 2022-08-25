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
 *  EmailAppOTAP.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to implement the Email provisioning function.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MMI_EMAILOTAP_H
#define MMI_EMAILOTAP_H

#include "MMIDataType.h"
#include "emailsrvgprot.h"
#include "customer_ps_inc.h"
#include "kal_general_types.h"

typedef enum
{
    MMI_EMAIL_OTAP_POPUP_INFO_TYPE_GET_PROFILE_INFO_ERROR,
    MMI_EMAIL_OTAP_POPUP_INFO_TYPE_TOTAL
} mmi_email_otap_popup_info_type_enum;

typedef enum
{
    MMI_EMAIL_OTAP_CLOAE_GROUP_TYPE_MYSELF = 0,
    MMI_EMAIL_OTAP_CLOAE_GROUP_TYPE_END_KEY,
    MMI_EMAIL_OTAP_CLOAE_GROUP_TYPE_UNMOUNT,
    MMI_EMAIL_OTAP_CLOAE_GROUP_TYPE_OTHER,
    MMI_EMAIL_OTAP_CLOAE_GROUP_TYPE_TOTAL
} mmi_email_otap_close_group_type_enum;

typedef struct
{
    mmi_id otap_group_id;
    EMAIL_SRV_HANDLE srv_handle;
    EMAIL_OTAP_HANDLE otap_handle;
    EMAIL_ACCT_HANDLE acct_handle;
    
    S32 profile_index;
    S32 profile_num;
    srv_email_otap_prof_info_struct current_profile_info;

    S32 account_num;
    S32 select_account_index;
    EMAIL_ACCT_ID account_id_array[MMI_EMAIL_MAX_ACCTS];
    WCHAR account_name[MMI_EMAIL_MAX_ACCTS][SRV_EMAIL_MAX_ACCT_NAME_LEN + 1];

    srv_email_acct_info_struct current_account_info;
    mmi_email_otap_close_group_type_enum close_group_type;
} mmi_email_app_otap_struct;

typedef struct
{
    U16 title_string_id;
    U16 title_icon_id;
    S32 menu_item_number;
    mmi_menu_id *menu_id_array;
    U16 *menu_id_string_array;
    U16 *menu_id_image_array;
} mmi_email_otap_menu_screen_struct;

typedef struct
{
    mmi_email_otap_popup_info_type_enum popup_type;
} mmi_email_otap_popup_info_struct;

void mmi_email_otap_init(void);
void mmi_email_otap_main_process(U32 profile_num);
void mmi_email_otap_deinit(void);

#endif /* MMI_EMAILOTAP_H */
