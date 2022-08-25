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
 * BrowserAppSrvHdlr.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
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
*------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifndef MMI_BROWSERAPPSRVHDLR_H
#define MMI_BROWSERAPPSRVHDLR_H

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__
#include "MMIDataType.h"
#include "BrowserSrvConfig.h"
#include "kal_general_types.h"


extern void mmi_brw_srv_hdlr_register_callback_events(void);
extern void mmi_brw_srv_hdlr_create_instance(S32 user_data, U32 result, void *obj);
extern void mmi_brw_srv_hdlr_set_profile(S32 user_data, U32 result, void *obj);
extern void mmi_brw_app_launch_browser(void);
extern void mmi_brw_srv_hdlr_delete_instance(S32 user_data, U32 result, void *obj);
extern void mmi_brw_app_global_context_deinit(void);
extern void mmi_brw_app_dynamic_context_deinit(void);

#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
extern void mmi_brw_srv_hdlr_save_page(S32 user_data, U32 result, void *obj);
extern void mmi_brw_srv_hdlr_get_save_page(S32 user_data, U32 result, void *obj);
extern void mmi_brw_srv_hdlr_delete_save_page(S32 user_data, U32 result, void *obj);
extern void mmi_brw_srv_hdlr_rename_save_page(S32 user_data, U32 result, void *obj);
extern void mmi_brw_srv_hdlr_get_save_page_list(S32 user_data, U32 result, void *obj);
extern void mmi_brw_srv_hdlr_delete_all_save_page(S32 user_data, U32 result, void *obj);
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */

#ifdef OBIGO_Q05A
extern void mmi_brw_srv_hdlr_get_page_objects_list(S32 user_data, U32 result, void *obj);
extern void mmi_brw_srv_hdlr_get_page_objects(S32 user_data, U32 result, void *obj);
#endif /* OBIGO_Q05A */

extern void mmi_brw_srv_hdlr_get_recent_page(S32 user_data, U32 result, void *obj);
extern void mmi_brw_srv_hdlr_get_recent_page_list(S32 user_data, U32 result, void *obj);
extern void mmi_brw_srv_hdlr_delete_recent_page(S32 user_data, U32 result, void *obj);
extern void mmi_brw_srv_hdlr_delete_all_recent_page(S32 user_data, U32 result, void *obj);

extern mmi_ret mmi_brw_srv_hdlr_error_ind_proc(mmi_event_struct *evt);

extern void mmi_brw_srv_hdlr_get_session_info(S32 user_data, U32 result, void *obj);
extern void mmi_brw_srv_hdlr_get_current_cert(S32 user_data, U32 result, void *obj);
extern void mmi_brw_srv_hdlr_get_trusted_cert_list(S32 user_data, U32 result, void *obj);
extern void mmi_brw_srv_hdlr_delete_trusted_cert(S32 user_data, U32 result, void *obj);
extern void mmi_brw_srv_hdlr_view_trusted_cert(S32 user_data, U32 result, void *obj);

extern void mmi_brw_srv_hdlr_load_url_req(U8* url);
extern void mmi_brw_srv_hdlr_load_data_req(void);
extern void mmi_brw_app_srv_hdlr_open_stored_page(void);
extern void mmi_brw_app_srv_hdlr_open_recent_page(void);
extern void mmi_brw_app_srv_hdlr_set_profile_req(void);
extern void mmi_brw_app_srv_hdlr_wait_user_action_rsp(MMI_BOOL positive_key_state);
extern void mmi_brw_app_delete_instance_req(void);
extern void mmi_brw_app_srv_hdlr_notify_screen_info(void);
extern void mmi_brw_app_srv_hdlr_clear_data_req(U8 type);
extern void mmi_brw_srv_hdlr_close_sockets(S32 user_data, U32 result, void *obj);

#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERAPPSRVHDLR_H */
