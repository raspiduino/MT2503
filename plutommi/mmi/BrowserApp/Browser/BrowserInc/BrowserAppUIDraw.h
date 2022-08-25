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
 * BrowserAppUIDraw.h
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
*------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifndef MMI_BROWSERAPPUIDRAW_H
#define MMI_BROWSERAPPUIDRAW_H

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__

#include "BrowserAppTypes.h"
#include "MMIDataType.h"
#include "mmi_frm_events_gprot.h"
#include "gui_data_types.h"
#include "kal_general_types.h"

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_draw_dynamic_list_screen_func
 * DESCRIPTION
 *  This function is to draw the dynamic list menu screen (for category 184)
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
extern mmi_brw_app_result_enum mmi_brw_app_ui_draw_dynamic_list_screen_func(U16 scr_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_draw_enter_url_editor_screen_func
 * DESCRIPTION
 *  This function is to draw the auto URL completion editor screen 
 * (for category 103)
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
extern mmi_brw_app_result_enum mmi_brw_app_ui_draw_enter_url_editor_screen_func(U16 scr_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_draw_splash_screen_func
 * DESCRIPTION
 *  This function is to draw the image screen small screen(for category 132)
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
extern mmi_brw_app_result_enum mmi_brw_app_ui_draw_splash_screen_func(U16 scr_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_draw_rendered_page_screen_func
 * DESCRIPTION
 *  This function is to draw the rendered page screen (for category 431)
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
extern mmi_brw_app_result_enum mmi_brw_app_ui_draw_rendered_page_screen_func(U16 scr_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_draw_progressing_screen_func
 * DESCRIPTION
 *  This function is to draw the progressing small screen (for category 66)
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
extern mmi_brw_app_result_enum mmi_brw_app_ui_draw_progressing_screen_func(U16 scr_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_draw_viewer_screen_func
 * DESCRIPTION
 *  This function is to draw the view content screen (for category 74)
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
extern mmi_brw_app_result_enum mmi_brw_app_ui_draw_viewer_screen_func(U16 scr_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_draw_confirmation_screen_func
 * DESCRIPTION
 *  This function is to draw the small screen confirmation popup screen
 *  (for category 165)
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
extern mmi_brw_app_result_enum mmi_brw_app_ui_draw_confirmation_screen_func(U16 scr_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_draw_upload_progress_screen_func
 * DESCRIPTION
 *  This function is to draw the upload progress screen (for category 412)
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
extern mmi_brw_app_result_enum mmi_brw_app_ui_draw_upload_progress_screen_func(U16 scr_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_draw_display_popup
 * DESCRIPTION
 *  Function to display the popup screen
 * PARAMETERS
 *  string          The string to be displayed in popup
 *  event_id        The type of the popup event
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_brw_app_ui_draw_display_popup(U8 *string, mmi_event_notify_enum event_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_draw_display_popup_ext
 * DESCRIPTION
 *  Function to display the popup screen
 * PARAMETERS
 *  string          The string resource to be displayed in popup
 *  event_id        The type of the popup event
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_brw_app_ui_draw_display_popup_ext(MMI_STR_ID string, mmi_event_notify_enum event_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_draw_display_confirm_with_sg
 * DESCRIPTION
 *  Function to display the Confirmation screen in a particular screen group
 * PARAMETERS
 *  message     The message to be displayed on the confirmation screen
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_brw_app_ui_draw_display_confirm_with_sg(UI_string_type message, FuncPtr lsk, FuncPtr rsk, MMI_BOOL need_csk_disabled, MMI_ID scrn_group);

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_draw_display_confirm
 * DESCRIPTION
 *  Function to display the Confirmation screen
 * PARAMETERS
 *  message     The message to be displayed on the confirmation screen
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_brw_app_ui_draw_display_confirm(UI_string_type message, FuncPtr lsk, FuncPtr rsk, MMI_BOOL csk_disable);

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_draw_ren_page_progressive_bar
 * DESCRIPTION
 *  This function is to display the rendered page Page fetching progress bar
 * PARAMETERS
 *  percentage          [IN]        The percentage of the progress bar that is filled
 *  display_string      [IN]        The String to be displayed on the progress bar
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_brw_app_ui_draw_ren_page_progressive_bar(S32 percentage, S8 *display_string);

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_draw_disable_ren_page_progressive_bar
 * DESCRIPTION
 *  This function is to disable the progress bar being displayed on the rendered
 * page screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_brw_app_ui_draw_disable_ren_page_progressive_bar(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_draw_update_upload_status
 * DESCRIPTION
 *  This function is for updating the Upload status in the Upload Progress
 *  screen(cat412screen)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_brw_app_ui_draw_update_upload_status(void);

#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERAPPUIDRAW_H */
