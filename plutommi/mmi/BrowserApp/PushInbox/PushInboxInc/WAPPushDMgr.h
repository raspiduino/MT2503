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
 * WAPPushDMgr.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the various data manager API's declaration and structure defination of Push message.
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __PUSH_MSG_DMGR_H__
#define __PUSH_MSG_DMGR_H__
//#include "MMI_include.h"
    #include "WAPPushScreenHdlr.h"
    #include "MMIDataType.h"
    #include "kal_general_types.h"
    #include "gui_typedef.h"
    #include "MMI_features.h"
#ifdef __WAP_PUSH_SUPPORT__
    


extern void mmi_wap_push_set_inline_screen_done_hdlr (Default_func_ptr *hdlr, U16 scr_id);
extern U16 mmi_wap_push_get_number_of_inline_scr_item (U16 screen_id);
extern void mmi_wap_push_add_bkm_set_buffers (void);
extern void mmi_wap_push_get_progress_scr_img_and_str_id (U16 screen_id, U16 *str_id, U16 *img_id);
extern void mmi_wap_push_get_notification_scr_img_and_str_id (U16 screen_id, U16 *str_id, U16 *img_id);
extern void mmi_wap_push_get_add_bkm_image_icon (U16 *image_list);
extern void mmi_wap_push_fill_inline_item_for_add_bkm (void);
extern MMI_BOOL mmi_wap_push_check_selected_msg_data_ready (void);
extern void mmi_wap_push_get_data_of_selected_message (void);
extern void mmi_wap_push_get_message_screen_data (
        U16 scr_id, 
        U16 *title_str, 
        U16 *lsk_str, 
        U16 *lsk_img, 
        U16 *rsk_str, 
        U16 *rsk_img, 
        Default_func_ptr *handler,
        Default_func_ptr *csk_func,
        Default_func_ptr *lnk_func,
        Default_func_ptr *rnk_func);
extern MMI_BOOL mmi_wap_push_check_sia_dlg_data_ready (void);
extern void mmi_wap_push_get_data_of_sia_dlg (void);
extern void mmi_wap_push_handle_rsk_on_sia_dlg_screen (void);
extern void mmi_wap_push_handle_lsk_sia_dlg_screen (void);
extern void mmi_wap_push_set_inbox_status(void);
extern void mmi_wap_push_get_inbox_details (U16 *num, U16 *selected, U16 *img_id);
extern S32 mmi_wap_push_get_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item);
extern void mmi_wap_push_confirm_ip_add_modify (void);
extern U16 mmi_wap_push_get_title_str_id_for_msg_deleted_screen (void);
extern U16 mmi_wap_push_get_title_icon (U16 default_title_id);

#endif /* __WAP_PUSH_SUPPORT__*/

#endif /* __PUSH_MSG_DMGR_H__ */
