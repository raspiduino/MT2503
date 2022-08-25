/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  ConnectManageGProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  These are the external interfaces provided by connection management application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef CONNECT_MANAGE_GPROT_H
#define CONNECT_MANAGE_GPROT_H

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "custom_events_notify.h"
#include "kal_general_types.h"
#include "MMIDataType.h"


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/* Entry screen type enum */
typedef enum 
{
    MMI_CNMGR_ENTRY_SCREEN_TYPE_LIST_SCREEN,    /* Enter bearer list screen */
    MMI_CNMGR_ENTRY_SCREEN_TYPE_BEARER_DETAIL,  /* Enter bearer detail info screen */
    MMI_CNMGR_ENTRY_SCREEN_TYPE_TOTAL
} mmi_cnmgr_entry_screen_type_enum;


/***************************************************************************** 
 * External interfaces
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_cnmgr_app_init
 * DESCRIPTION
 *  This API is used to initialize connection management application.
 * PARAMETERS
 *  evt	:	        [IN]	Init event notification
 * RETURN VALUES
 *  mmi_ret
 *****************************************************************************/
extern mmi_ret mmi_cnmgr_app_init(mmi_event_struct *evt);


/*****************************************************************************
 * FUNCTION
 *  mmi_cnmgr_app_show_bearer_detail_info
 * DESCRIPTION
 *  This API is used to enter bearer detail info screen.
 * PARAMETERS
 *  entry_type :    [IN]    Entry type
 *  acct_id :       [IN]    Data account
 *  icon_id :       [IN]    Application icon
 * RETURN VALUES
 *  mmi_ret
 *****************************************************************************/
extern void mmi_cnmgr_app_show_bearer_detail_info(mmi_cnmgr_entry_screen_type_enum entry_type, U32 acct_id, U16 icon_id);


/*****************************************************************************
 * FUNCTION
 *  mmi_cnmgr_delete_bearer_detail_screen
 * DESCRIPTION
 *  Let application delete bearer detail info screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_cnmgr_delete_bearer_detail_screen(void);


#endif /* CONNECT_MANAGE_GPROT_H */
