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
 *  EngineerModeGPRS.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Engineer mode GPRS related items header file.
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MMI_EM_GPRS_H
#define MMI_EM_GPRS_H

/***************************************************************************** 
 * Include 
 *****************************************************************************/
    #include "MMI_features.h"
    #include "kal_general_types.h"
    #include "MMIDataType.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Typedef 
 *****************************************************************************/


/***************************************************************************** 
 * Global Function 
 *****************************************************************************/
#if defined(__MMI_EM_GPRS_AUTO_ATTACH__) || defined(__MMI_EM_GPRS_PDP__) || defined(__MMI_EM_GPRS_CNMGR_SCRI_SUPPORT__)

#ifdef __MMI_EM_GPRS_AUTO_ATTACH__
extern void EngineerModeGprsAttachReq(void);
extern void EngineerModeGprsAttachRes(void *inMsg);
#endif /* __MMI_EM_GPRS_AUTO_ATTACH__ */


#ifdef __MMI_EM_GPRS_PDP__
extern void SendGprsActivatePDPContext(kal_uint8 pdp_idx);
extern void EngineerModeGprsDeactivatePDPReq(void);
extern void EngineerModeGprsDeactivatePDPRes(void *inMsg);
extern void EngineerModeGprsSendDataReq(kal_uint32 size);
extern void EngineerModeGprsSendDataRes(void *inMsg);
extern void EngineerModeGprsActivatePDPContext(kal_uint8 pdp_idx);
extern void EngineerModeGprsSetDefinitionRes(void *inMsg);
extern void EngineerModeGprsSetQosRes(void *inMsg);
#ifdef __R99__
extern void EngineerModeGprsSetEQosRes(void *inMsg);
#endif 
extern void EngineerModeGprsActTestRes(void *inMsg);
extern void EmSendDataScreenLSKHandler(MMI_BOOL is_accept, U32 output_num, MMI_ID editor_gid, void* user_data);
#endif/*__MMI_EM_GPRS_PDP__*/


extern void EngineerModeSendMsg_Check_Prefer_SIM(U16 msg_id, void *local_param_ptr, void *peer_buf_ptr);

extern void mmi_em_gprs_menu_event_hdlr(cui_menu_event_struct *event);
extern void mmi_em_gprs_menu_list_exit_hdlr(cui_menu_event_struct *event);
extern void mmi_em_gprs_menu_entry_event_hdlr(cui_menu_event_struct *event);

#endif /*defined(__MMI_EM_GPRS_AUTO_ATTACH__) || defined(__MMI_EM_GPRS_PDP__) || defined(__MMI_EM_GPRS_CNMGR_SCRI_SUPPORT__) */

#endif /* MMI_EM_GPRS_H */ 


