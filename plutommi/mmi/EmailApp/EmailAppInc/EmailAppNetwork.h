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
 * EmailAppNetwork.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * 
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef __EMAIL_APP_NETWORK_H_
#define __EMAIL_APP_NETWORK_H_

#include "emailsrvgprot.h"


#if (defined(__XML_SUPPORT__) && defined(__WBXML_SUPPORT__))
#ifndef __MMI_EMAIL_EMN__
#define __MMI_EMAIL_EMN__
#endif /* __MMI_EMAIL_EMN__ */
#endif /* (defined(__XML_SUPPORT__) && defined(__WBXML_SUPPORT__)) */

void mmi_email_app_network_reset(void); // abort all pending operation

#ifdef __MMI_EMAIL_IMAP_PUSH__
void mmi_email_app_network_push_start(EMAIL_ACCT_ID acc_id, BOOL first_power_on);
void mmi_email_app_network_push_stop(BOOL to_change);
#endif /* __MMI_EMAIL_IMAP_PUSH__ */

#ifdef __MMI_EMAIL_EMN__
void mmi_email_app_nwk_emn_do(EMAIL_ACCT_ID acc_id);
#endif /* __MMI_EMAIL_EMN__ */

#ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__
void mmi_email_app_nwk_autocheck_do(EMAIL_ACCT_ID acc_id);
#endif /* __MMI_SLIM_EMAIL_NO_AUTO_CHECK__ */

void mmi_email_app_nwk_user_enter(EMAIL_ACCT_ID acc_id);
void mmi_email_app_nwk_user_leave(void);

void mmi_email_app_nwk_user_refresh(EMAIL_ACCT_ID acc_id);
void mmi_email_app_nwk_user_refresh_stop(EMAIL_ACCT_ID acc_id);

void mmi_email_app_nwk_user_send(EMAIL_ACCT_ID acc_id, BOOL foreground);
void mmi_email_app_nwk_user_send_stop(EMAIL_ACCT_ID acc_id);

void mmi_email_app_nwk_user_download(
        mmi_id grp_id, 
        EMAIL_ACCT_ID acc_id, 
        EMAIL_FLDR_ID fld_id, 
        EMAIL_MSG_ID msg_id, 
        EMAIL_ATTCH_ID attach_id, 
        srv_email_retrieve_option_enum ret_opt);


void mmi_email_app_nwk_user_abort(EMAIL_ACCT_ID acc_id);

// For EDIT account check
BOOL mmi_email_app_nwk_user_is_connected(EMAIL_ACCT_ID acc_id);

// For MARK 
void mmi_email_app_nwk_user_disconnect(EMAIL_ACCT_ID acc_id);

void mmi_email_app_nwk_freeze(EMAIL_ACCT_ID acc_id, BOOL is_freeze);

void mmi_email_app_nwk_delaccount(EMAIL_ACCT_ID acc_id);


BOOL mmi_email_app_nwk_is_sending(EMAIL_ACCT_ID acc_id);
BOOL mmi_email_app_nwk_is_refreshing(EMAIL_ACCT_ID acc_id);


BOOL mmi_email_app_nwk_is_outbox_sending(EMAIL_ACCT_ID acc_id);
BOOL mmi_email_app_nwk_is_msg_sending(EMAIL_ACCT_ID acc_id, EMAIL_MSG_ID msg_id);
BOOL mmi_email_app_nwk_is_msg_sendfail(EMAIL_ACCT_ID acc_id, EMAIL_MSG_ID msg_id);

#endif /* __EMAIL_APP_NETWORK_H_ */
