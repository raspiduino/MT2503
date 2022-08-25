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
 *  EngineerModeBT.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Coding Template header file
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MMI_EM_BT_H
#define MMI_EM_BT_H

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"
#include "kal_general_types.h"
#include "InlineCuiGprot.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Typedef 
 *****************************************************************************/


/***************************************************************************** 
 * Global Function 
 *****************************************************************************/
 
#if defined(__MMI_EM_BT_GENERAL_TEST__)
extern void mmi_em_bt_exit_test_mode_hdlr(void);
extern void mmi_em_bt_rf_test_exit(void);
extern void mmi_em_bt_bd_lookback_scrn_hdlr(void);
extern MMI_RET mmi_em_bt_bd_lookback_scrn_proc(mmi_event_struct *evt);
extern void mmi_em_bt_loop_back_req_hdlr(cui_event_inline_common_struct *inline_evt);
extern void mmi_em_bt_in_progress_scrn(void);
extern MMI_RET mmi_em_bt_in_progress_scrn_proc(mmi_event_struct* evt);
extern void mm_em_bt_in_progress_abort(void);
extern MMI_BOOL mmi_em_bt_addr_wcs2char(WCHAR* wcs_addr, CHAR* acs);
#endif/*__MMI_EM_BT_GENERAL_TEST__*/

/***************************************************************************** 
 * BT chip version 
 *****************************************************************************/
#ifdef __MMI_EM_BT_GET_CHIP_VERION__
/* under construction !*/
/* under construction !*/
#endif


/***************************************************************************** 
 * BT upf iot test 
 *****************************************************************************/
#ifdef __MMI_EM_BT_UPF_IOT_TEST__
typedef enum
{
    EM_BT_UPF_IOT_TEST_INPUT_NUMBER_CAPTION = 0,
    EM_BT_UPF_IOT_TEST_INPUT_NUMBER,

    EM_BT_UPF_IOT_TEST_INLINE_ITEM_END
} EM_BT_UPF_IOT_TEST_INLINE_ITEM;

extern void mmi_em_bt_upf_iot_test_send_ind(cui_event_inline_common_struct* inline_evt);
extern void mmi_em_bt_entry_upf_test_scrn(void);
extern MMI_RET mmi_em_bt_entry_upf_test_scrn_proc(mmi_event_struct *evt);
#endif

/***************************************************************************** 
 * BT event hdlr 
 *****************************************************************************/
extern void mmi_em_bt_menu_sel_event_hdlr(cui_menu_event_struct *event);
extern void mmi_em_bt_menu_entry_event_hdlr(cui_menu_event_struct *event);
extern void mmi_em_bt_menu_exit_event_hdlr(cui_menu_event_struct *evt);

#endif /* MMI_EM_BT_H */ 
