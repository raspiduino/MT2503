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
 *  SIMProvAgentGProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SIM Provisioning Agent Header File
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef MMI_SPA_GPROT_H
#define MMI_SPA_GPROT_H

#include "MMIDataType.h"

/*****************************************************************************
 * FUNCTION
 *  mmi_spa_cca_new_setting_rsp_hdlr
 * DESCRIPTION
 *  Handler of  MSG_ID_MMI_CCA_SOURCE_UI_NEW_SETTING_RSP
 * PARAMETERS
 *  msg : [IN]  Primitive data
 * RETURNS
 *  No return value
*****************************************************************************/
extern void mmi_spa_cca_new_setting_rsp_hdlr(void *msg);

/*****************************************************************************
 * FUNCTION
 *  mmi_spa_cca_new_doc_rsp_hdlr
 * DESCRIPTION
 *  Handler of  MSG_ID_MMI_CCA_SOURCE_NEW_DOC_RSP
 * PARAMETERS
 *  msg : [IN]  Primitive data
 * RETURNS
 *  No return value
*****************************************************************************/
extern void mmi_spa_cca_new_doc_rsp_hdlr(void *msg);

/*****************************************************************************
 * FUNCTION
 *  mmi_spa_cca_ready_ind_hdlr
 * DESCRIPTION
 *  Handler of  MSG_ID_MMI_CCA_SOURCE_CCA_READY_IND
 * PARAMETERS
 *  cca_ready_ind : [IN]  Primitive data
 * RETURNS
 *  No return value
*****************************************************************************/
extern void mmi_spa_cca_ready_ind_hdlr(void *cca_ready_ind);

/*****************************************************************************
 * FUNCTION
 *  mmi_spa_inject_string_hdlr
 * DESCRIPTION
 *  Handle inject string from catcher to do test and debug
 * PARAMETERS
 *  index : [IN]  Command index
 *  str   : [IN]  Injected string
 * RETURNS
 *  No return value
*****************************************************************************/
extern void mmi_spa_inject_string_hdlr(U8 index, U8 *str);

#endif /* MMI_SPA_GPROT_H */ 

