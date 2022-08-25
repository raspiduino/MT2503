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
 *  EngineerMode.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 * 
 *  
 *
 * Author:
 * -------
 *  
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef MMI_EM_H
#define MMI_EM_H

#include "MMI_include.h"
#include "mmi_features.h"
#include "fseditorcuigprot.h"
#include "FileMgrCUIGProt.h"
#include "inlinecuigprot.h"
#include "EngineerModeDef.h"
#include "EngineerModeType.h"
#include "EngineerModeUtil.h"
#include "EngineerModeCommUI.h"
#include "EngineerModeCommMem.h"
#include "EngineerModeDevice.h"

typedef void (*CALL_BACK_FUNC)(U16 id);

typedef struct{
    mmi_id item_id;
    U16    toneIdx;
    CALL_BACK_FUNC call_func;
    void *user_data;
} mmi_em_tone_cntx_struct;

extern U8 g_em_nw_info_sim_flag;

#ifdef __MMI_EM_NW_NETWORK_INFO__
/*-----------------------------------------------------------------------------*/
/*-------------------------- Network -> Network info --------------------------*/
/*-----------------------------------------------------------------------------*/
extern void mmi_em_nw_info_list_pre_hdlr(cui_menu_event_struct *evt);
extern void mmi_em_nw_info_checkbox_list_hdlr(cui_menu_event_struct *evt);
#endif /*__MMI_EM_NW_NETWORK_INFO__*/


#ifdef __MMI_EM_NW_EVENT_NOTIFY__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__MMI_EM_NW_EVENT_NOTIFY__*/


#ifdef __MMI_EM_BT_RF_TEST__
/*-----------------------------------------------------------------------------*/
/*-------------------------- BT -> Rf test                  -------------------*/
/*-----------------------------------------------------------------------------*/
extern void mmi_em_bt_rf_enter_bd_addr_scrn(void);
extern void mmi_em_bt_init_item(MMI_ID inline_gid, U16 item_id, U16 set_value);
extern void mmi_em_bt_save_item_result(cui_event_inline_common_struct* inline_evt, U16 item_id, U16* set_value);
extern void mmi_em_bt_rf_bd_enter_test_mode(void);
extern void mmi_em_bt_rf_test_confirm(void);
extern void mmi_em_bt_rf_test_disable_sleep_mode(void);
extern void mmi_em_rf_test_sleep_mode_hdlr(void* inMsg);
extern void mmi_em_rf_test_enter_flight_mode(void);
extern void mmi_em_bt_rf_test_power_on_bt(void);
extern void mmi_em_bt_rf_test_power_on_bt_rsp_hdlr(void *inMsg);
extern void mmi_em_bt_rf_test_tx_rx_init(MMI_ID inline_id);
extern void mmi_em_bt_rf_test_tx_rx_enter_scrn(U8 test_item);
extern mmi_ret mmi_em_bt_tx_rx_scrn_proc(mmi_event_struct *evt);
extern void mmi_em_bt_tx_rx_value_hdlr(cui_event_inline_common_struct* inline_evt);
extern void mmi_em_bt_rf_testing_enter_text_show_scrn(void);
extern void EMBtRfTestTXRXSendReq(void);
extern void EMBtRfTestSendReq(void);
extern void EmBtRfTestTXRXRspHdlr(void *inMsg);
extern void EmBtRfTestPwrCtrlLevelRspHdlr(void *inMsg);
extern void EntryEmDevBtRfTesting(void);
extern void EmBtRfTestPwrLevelUp(void);
extern void EmBtRfTestPwrLevelDown(void);
extern void EmBtRfTestSetBdAddrRspHdlr(void *inMsg);
#endif /*__MMI_EM_BT_RF_TEST__*/

#endif /*MMI_EM_H*/

