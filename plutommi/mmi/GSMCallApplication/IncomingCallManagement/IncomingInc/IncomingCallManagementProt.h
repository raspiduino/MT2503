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
 *  IncomingCallManagementProt.h
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
 *  
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : IncomingCallManagementProt.h

   PURPOSE     : Call Management application

   REMARKS     : nil

   AUTHOR      : Manish

   DATE     : Nov 8,02

**************************************************************/

#ifndef _INCOMINGCALLMANAGEMENT_PROT_H
#define _INCOMINGCALLMANAGEMENT_PROT_H

#include "MMI_features.h"
#include "MMIDataType.h"

extern void ReinitalizeIncomingCall(void);
extern void InitIncomingCall(void);

extern void KbCBackEndSelectiveActiveCall(void);

/**************************** CISS ********************************/

extern void PsCBackUSSNInd(void *info);
extern void PsCBackUSSRInd(void *info);
extern void mmi_gsm_master_ussr_ind(void *info);
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */
extern void mmi_gsm_display_ussn_info(void);
extern mmi_ret mmi_gsm_display_ussn_info_on_active_call_cb(mmi_event_struct * param);
extern void mmi_gsm_display_ussn_info_on_active_call(void);
extern void mmi_gsm_display_ussr_info(void);
extern mmi_ret mmi_gsm_display_ussr_info_on_active_call_cb(mmi_event_struct * param);
extern void mmi_gsm_display_ussr_info_on_active_call(void);

extern void EntryScrDisplayUSSNMsg(void);
extern void ExitScrDisplayUSSNMsg(void);

#ifdef __MMI_USSR_TIMER__  
extern void USSRTimeout(void);
#endif

/* micha0317 */
extern void GoBackFromUSSNMsg(void);
extern void EntryScrDisplayUSSRMsg(void);
extern void ExitScrDisplayUSSRMsg(void);
extern void EntryScrDisplayUSSDRes(void);
extern void ExitScrDisplayUSSDRes(void);
extern void EntryScrEditUSSRMsg(void);
extern void MMIUSSNReceiveOK(void);
extern void MMIUSSNReceiveAbort(void);
extern void MMIUSSNReceiveBack(void);
extern void MMIUSSNReceiveEnd(void);


extern void SendUSSRMsg(void);
extern BOOL UssrCheckUCS2(U16 *buf, U32 charNum);
extern void AbortUSSDResultRequest(void);
extern void AbortUSSDResultRequestEND(void);

/* micha0610 */
extern void ResumeSSScrInCall(void);

extern void mmi_gsm_remove_ussx_scr(void);

#ifdef __USSD_AUTO_REJECT__
extern void mmi_gsm_ps_ussd_ack_req(U16 cause);
extern void mmi_gsm_ps_ussd_ack_rsp(void *info);
extern void mmi_gsm_ps_ussd_auto_reject(U16 cause, U16 direction);
#endif /* __USSD_AUTO_REJECT__ */

/* micha0110 */
extern U8 USSRDelHistoryHdlr(void *in_param);
extern void EditUSSRGoBack(void);
#endif /* _INCOMINGCALLMANAGEMENT_PROT_H */ 
