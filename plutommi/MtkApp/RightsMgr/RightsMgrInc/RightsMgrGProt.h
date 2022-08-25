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
 *  RightsMgrGProt.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  External interfaces of Rights Manager
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *          HISTORY
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __RIGHTSMGRGPROT_H__
#define __RIGHTSMGRGPROT_H__

#include "kal_general_types.h"
#include "app_mine.h"

#include "MMIDataType.h"
#include "fs_type.h"

/*****************************************************************************
 * Some definition to show the attribute of a file
 *****************************************************************************/
/* This is a DRM file */
#define MMI_RMGR_USAGE_DRM  0x01            

/* This file can be move to another handset */
#define MMI_RMGR_USAGE_SEND 0x02            

/* This file can set be used in automatically launch AP, ex: wall paper */
#define MMI_RMGR_USAGE_SET  0x04            

/*****************************************************************************
 * enum to show the right status of a DRM content
 *****************************************************************************/
typedef enum
{
    MMI_RMGR_STATUS_OK,                     /*  Normal file, not DRM file */
    MMI_RMGR_STATUS_NO_PERMISSION,          /*  No permission, and no right issuer */
    MMI_RMGR_STATUS_REQUEST_RIGHTS,         /*  No permission but with right issuer */
    MMI_RMGR_STATUS_WITH_RIGHTS,            /*  DRM file with permission */
    MMI_RMGR_STATUS_MAX
}mmi_rmgr_status_enum;

/*****************************************************************************
 * enum to show where the right object come from
 *****************************************************************************/
typedef enum
{
    MMI_RMGR_SRC_WAP_DOWNLOAD,
    MMI_RMGR_SRC_PUSH,
    MMI_RMGR_SRC_SAVE_AS,
    MMI_RMGR_SRC_TOTAL
}mmi_rmgr_src_enum;

/*****************************************************************************
 * <GROUP  CallbackFunctions>
 * FUNCTION
 *  mmi_rmgr_ri_callback
 * DESCRIPTION
 *  A callback function to indicate AP that user accept to activate right.
 * PARAMETERS
 *  result:     [IN]    accecpt or not
 * RETURNS
 *  Void
 * RETURN VALUES
 *  Void
 *****************************************************************************/
typedef void (*mmi_rmgr_ri_callback)(MMI_BOOL result);

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_init
 * DESCRIPTION
 *  Init function of rights manager application, called in InitService()
 * PARAMETERS
 *  Void
 * RETURNS
 *  Void
 * RETURN VALUES
 *  Void
 *****************************************************************************/
extern void mmi_rmgr_init(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_show_process_info
 * DESCRIPTION
 *  Only used for DLagent now. This function is used to show some popup information
 *  after process DRM object. Ex: right object or roap trigger.
 * PARAMETERS
 *  result:     [IN]    result of processing DRM object. refer to drm_proc_enum
 *  waiting:    [IN]    indicate if the right object is waited by any application
 *  src:        [IN]    where the right object from
 *  type:       [IN]    the type of DRM object.
 * RETURNS
 *  Void
 * RETURN VALUES
 *  Void
 *****************************************************************************/
extern void mmi_rmgr_show_process_info(
                S32 result,
                MMI_BOOL waiting,
                mmi_rmgr_src_enum src,
                applib_mime_type_struct *type);

/*****************************************************************************
 * FUNCTION
 *  mmi_drm_send_get_imsi_cnf
 * DESCRIPTION
 *  Send the IMSI to right manager, and the right manager would send the
 *  MSI to DRM task.
 * PARAMETERS
 *  imsi:       [IN]    buffer of imsi
 *  result:     [IN]    MMI_TRUE or MMI_FALSE
 * RETURNS
 *  Void
 * RETURN VALUES
 *  Void
 *****************************************************************************/
extern void mmi_drm_send_get_imsi_cnf(U8 *imsi, S32 result);

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_populate_drm_info
 * DESCRIPTION
 *  To show the detail DRM information of a file.
 * PARAMETERS
 *  path:       [IN]    filepath
 *  app_perm:   [IN]    To show all permission or specific permission
 *  data:       [OUT]   buffer to return drm detail information
 *  buf_size:   [IN]    size of buffer
 * RETURNS
 *  Indicate if need to activate the content. (no use now)
 * RETURN VALUES
 *  MMI_TRUE:   The rights of DRM content is expired. And the right is extendable.
 *  MMI_FALSE:  other case
 *****************************************************************************/
extern MMI_BOOL mmi_rmgr_populate_drm_info(U16 *path, U8 app_perm, U8 *data, S32 buf_size);

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_get_err_string
 * DESCRIPTION
 *  to provide string ID associated to error code
 * PARAMETERS
 *  error:  [IN]    error code, please refer to drm_proc_enum
 * RETURNS
 *  A string id.
 * RETURN VALUES
 *  Void
 *****************************************************************************/
extern MMI_ID_TYPE mmi_rmgr_get_err_string(S32 error);

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_request_rights_confirm
 * DESCRIPTION
 *  Enter confirm screen to get user consent if they want to activate the content.
 * PARAMETERS
 *  Void
 * RETURNS
 *  Void
 * RETURN VALUES
 *  Void
 *****************************************************************************/
extern void mmi_rmgr_request_rights_confirm(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_request_rights_confirm_ext
 * DESCRIPTION
 *  Enter confirm screen to get user consent if they want to activate the content.
 * PARAMETERS
 *  confirm_string:     [IN]    confirm string assigned by application
 *  show_immediately:   [IN]    to show the confirm screen immediately or just entry a dummp screen
 * RETURNS
 *  Void
 * RETURN VALUES
 *  Void
 *****************************************************************************/
extern void mmi_rmgr_request_rights_confirm_ext(U16 *confirm_string, MMI_BOOL show_immediately);

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_check_rights_by_handle
 * DESCRIPTION
 *  To validate rights with given handle and permission
 *  Please MUST use this function with mmi_rmgr_request_rights_confirm.
 *  If you just want to validate right without any screen, please use
 *  DRM_validate_permission.
 * PARAMETERS
 *  handle:         [IN]    file handle
 *  permission:     [IN]    application specific permission
 *  icon:           [IN]    icon to be shown in confirm screen
 *  callback:       [IN]    callback to AP, indicate if user want to activate the content or not.
 * RETURNS
 *  Refer to mmi_rmgr_status_enum. A enum value to indicate the permission status of content.
 * RETURN VALUES
 *  MMI_RMGR_STATUS_REQUEST_RIGHTS: SD/V2 w/o valid rights
 *  MMI_RMGR_STATUS_NO_PERMISSION: FL/CD w/o valid rights or SD/V2 w/o RI URL
 *  negative value: Otherwise, error code
 *****************************************************************************/
extern S32 mmi_rmgr_check_rights_by_handle(FS_HANDLE handle, U8 permission, U16 icon, mmi_rmgr_ri_callback callback);

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_check_rights_by_path
 * DESCRIPTION
 *  To validate rights with given path and permission
 *  Please MUST use this function with mmi_rmgr_request_rights_confirm.
 *  If you just want to validate right without any screen, please use
 *  DRM_validate_permission.
 * PARAMETERS
 *  file_path:      [IN]    file path
 *  permission:     [IN]    application specific permission
 *  icon:           [IN]    icon to be shown in confirm screen
 *  callback:       [IN]    callback to AP, indicate if user want to activate the content or not.
 * RETURNS
 *  Refer to mmi_rmgr_status_enum. A enum value to indicate the permission status of content.
 * RETURN VALUES
 *  MMI_RMGR_STATUS_REQUEST_RIGHTS: SD/V2 w/o valid rights
 *  MMI_RMGR_STATUS_NO_PERMISSION: FL/CD w/o valid rights or SD/V2 w/o RI URL
 *  negative value: Otherwise, error code
 *****************************************************************************/
extern S32 mmi_rmgr_check_rights_by_path(U16 *file_path, U8 permission, U16 icon, mmi_rmgr_ri_callback callback);

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_check_rights_full_procedure
 * DESCRIPTION
 *  To validate rights with given path and permission. This is a full procedure
 * PARAMETERS
 *  file_path:      [IN]    file path
 *  permission:     [IN]    application specific permission
 *  icon:           [IN]    icon to be shown in confirm screen
 *  callback:       [IN]    callback to AP, indicate if user want to activate the content or not.
 * RETURNS
 *  Refer to mmi_rmgr_status_enum. A enum value to indicate the permission status of content.
 * RETURN VALUES
 *  MMI_RMGR_STATUS_REQUEST_RIGHTS: SD/V2 w/o valid rights
 *  MMI_RMGR_STATUS_NO_PERMISSION: FL/CD w/o valid rights or SD/V2 w/o RI URL
 *  negative value: Otherwise, error code
 *****************************************************************************/
extern MMI_BOOL mmi_rmgr_check_rights_full_procedure(
                    U16 *filepath,
                    FS_HANDLE handle,
                    U8 permission,
                    U16 icon,
                    mmi_rmgr_ri_callback callback);

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_check_forward
 * DESCRIPTION
 *  To check if the content can be forward to automatical launching application.
 *  Ex: wallpapaer, ringtone.
 * PARAMETERS
 *  file_path:  [IN]     file path
 * RETURNS
 *  combination of result (bit mask)
 * RETURN VALUES
 *  MMI_RMGR_USAGE_DRM:     this is a DRM content
 *  MMI_RMGR_USAGE_SEND:    this content can be sent via network applications
 *  MMI_RMGR_USAGE_SET:     this content can be set as automated usage
 *  negative value:         Otherwise, error code
 *****************************************************************************/
extern S32 mmi_rmgr_check_forward(U16 *file_path);

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_populate_drm_info_aux
 * DESCRIPTION
 *  To show the detail DRM information of a file or a item in right list menu.
 * PARAMETERS
 *  path:       [IN]    filepath
 *  app_perm:   [IN]    To show all permission or specific permission
 *  data:       [OUT]   buffer to return drm detail information
 *  buf_size:   [IN]    size of buffer
 *  ref:        [IN]    the reference number in right list menu.
 * RETURNS
 *  Indicate if need to activate the content. (no use now)
 * RETURN VALUES
 *  MMI_TRUE:   The rights of DRM content is expired. And the right is extendable.
 *  MMI_FALSE:  other case
 *****************************************************************************/
extern MMI_BOOL mmi_rmgr_populate_drm_info_aux(U16 *path, U8 app_perm, U8 *data, S32 buf_size, S32 ref);


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_space_check
 * DESCRIPTION
 *  remaining space check function
 * PARAMETERS
 *  Void
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_FALSE: do not enter ro list
 *  MMI_TRUE: enter ro list
 *****************************************************************************/
extern U8 mmi_rmgr_space_check(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_entry_db_check
 * DESCRIPTION
 *  confrim to enter ro list
 * PARAMETERS
 *  Void
 * RETURNS
 *  Void
 * RETURN VALUES
 *  Void
 *****************************************************************************/
extern void mmi_rmgr_entry_db_check(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_unlock_session_on
 * DESCRIPTION
 *  To tell unlock session is on or off. Only for browser to support seamless download
 * PARAMETERS
 *  Void
 * RETURNS
 *  A boolean value to indicate the session situation
 * RETURN VALUES
 *  MMI_TRUE:   session on
 *  MMI_FALSE:  session off
 *****************************************************************************/
extern MMI_BOOL mmi_rmgr_unlock_session_on(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_unlock_session_callback
 * DESCRIPTION
 *  To delete progress screen when the browser need to show a page
 * PARAMETERS
 *  Void
 * RETURNS
 *  Void
 * RETURN VALUES
 *  Void
 *****************************************************************************/
extern void mmi_rmgr_unlock_session_callback(void);

/*****************************************************************************
* FUNCTION
*   mmi_rmgr_resume_unlocking
* DESCRIPTION
*   To show the progressing screen once again
* PARAMETERS
*   Void
* RETURNS
*   Void
* RETURN VALUES
*   Void
*****************************************************************************/
extern void mmi_rmgr_resume_unlocking(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_query_icon
 * DESCRIPTION
 *  To get DRM file icon (lock/unlock)
 * PARAMETERS
 *  handle:     [IN]        file hande
 *  perm:       [IN]        permission
 *  id:         [OUT]       IMG_ID_RMGR_UNLOCK or IMG_ID_RMGR_LOCK
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_rmgr_query_icon(U16 *filepath, U8 perm, U16 *id);

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_format_notify_hdlr
 * DESCRIPTION
 *  Post formatting notification handler
 * PARAMETERS
 *  notify_flag:        [IN]        MMI_FMGR_NOTIFY_DRV_POST_FORMAT
 *  para:               [IN]        additional parameter
 * RETURNS
 *  A boolean value. But always return true.
 * RETURN VALUES
 *  MMI_TRUE:   true
 *****************************************************************************/
extern mmi_ret mmi_rmgr_format_notify_hdlr(mmi_event_struct *param);

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_set_ro_bound_path
 * DESCRIPTION
 *  To set content path
 * PARAMETERS
 *  path:        [IN]    the content path
 * RETURNS
 *  Void
 * RETURN VALUES
 *  Void
 *****************************************************************************/
extern void mmi_rmgr_set_ro_bound_path(U16 *path);

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_reset_ro_bound_path
 * DESCRIPTION
 *  To reset content path
 * PARAMETERS
 *  Void
 * RETURNS
 *  Void
 * RETURN VALUES
 *  Void
 *****************************************************************************/
extern U8 mmi_rmgr_reset_ro_bound_path(void *ptr);

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_set_ro_bound_path
 * DESCRIPTION
 *  To get content path
 * PARAMETERS
 *  void
 * RETURNS
 *  the content path
 * RETURN VALUES
 *  Void
 *****************************************************************************/
extern U16 *mmi_rmgr_get_ro_bound_path(void);

#ifdef __MMI_RMGR_SWEEP_DB_PERIODICALLY__
/*****************************************************************************
 * The time to sweep database periodically, 10000 = 10 sec
 *****************************************************************************/
//#define MMI_RMGR_SWEEP_DB_PERIOD (10000)

/***********************************************
 * Use a timer to trigger sweeping
 *****************************************************************************/
//#define MMI_RMGR_SWEEP_DB_TRIGGER_BY_TIMER
#endif /* __MMI_RMGR_SWEEP_DB_PERIODICALLY__ */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_period_sweep_db
 * DESCRIPTION
 *  try to sweep database.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  Void
 *****************************************************************************/
extern void mmi_rmgr_period_sweep_db(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_period_sweep_db_cancel
 * DESCRIPTION
 *  try to cancel period sweep database.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  Void
 *****************************************************************************/
extern void mmi_rmgr_period_sweep_db_cancel(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_scan_disk_cancel
 * DESCRIPTION
 *  cancel scan all file system
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  Void
 *****************************************************************************/
extern mmi_ret mmi_rmgr_scan_disk_turnoff(mmi_event_struct *evt);

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_scan_disk_cancel
 * DESCRIPTION
 *  cancel scan all file system
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  Void
 *****************************************************************************/
extern mmi_ret mmi_rmgr_scan_disk_turnon(mmi_event_struct *evt);

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_check_rights_internal
 * DESCRIPTION
 *  To validate rights with given path and permission
 * PARAMETERS
 *  file_path:      [IN]       file path
 *  permission:     [IN]       application specific permission
 *  callback:       [IN]       callback of app to tell proceed or not
 * RETURNS
 *  Refer to mmi_rmgr_status_enum
 * RETURN VALUES
 *  Void
 *  MMI_RMGR_STATUS_REQUEST_RIGHTS: the rights is expired or expired soon.
 *  MMI_RMGR_STATUS_WITH_RIGHTS: this content with solid rights
 *  MMI_RMGR_STATUS_OK: this content is not a DRM file
 *  negative value: Otherwise, error code
 *****************************************************************************/
extern S32 mmi_rmgr_extend_rights_internal(FS_HANDLE handle, U8 permission, U16 icon);

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_check_rights_internal_mod
 * DESCRIPTION
 *  To validate rights with given path and permission without registering unlock session
 * PARAMETERS
 *  file_path:      [IN]       file path
 *  permission:     [IN]       application specific permission
 *  callback:       [IN]       callback of app to tell proceed or not
 * RETURNS
 *  Refer to mmi_rmgr_status_enum
 * RETURN VALUES
 *  Void
 *  MMI_RMGR_STATUS_REQUEST_RIGHTS: the rights is expired or expired soon.
 *  MMI_RMGR_STATUS_WITH_RIGHTS: this content with solid rights
 *  MMI_RMGR_STATUS_OK: this content is not a DRM file
 *  negative value: Otherwise, error code
 *****************************************************************************/
extern S32 mmi_rmgr_extend_rights_internal_mod(FS_HANDLE handle, U8 permission, U16 icon);

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_extend_rights_by_path
 * DESCRIPTION
 *  To check if it is necessary to extend right.
 *  This function must use with mmi_rmgr_request_rights_confirm
 * PARAMETERS
 *  file_path:      [IN]    file path
 *  permission:     [IN]    content permission
 *  icon:           [IN]    icon
 * RETURNS
 *  Refer to mmi_rmgr_status_enum
 * RETURN VALUES
 *  MMI_RMGR_STATUS_REQUEST_RIGHTS: the rights is expired or expired soon.
 *  MMI_RMGR_STATUS_WITH_RIGHTS: this content with solid rights
 *  MMI_RMGR_STATUS_OK: this content is not a DRM file
 *  negative value: Otherwise, error code
 *****************************************************************************/
extern S32 mmi_rmgr_extend_rights_by_path(U16 *filepath, U8 permission, U16 icon);

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_extend_rights_full_procedure
 * DESCRIPTION
 *  To check if it is necessary to extend right. We will handle all the following
 *  sceen in this function
 * PARAMETERS
 *  file_path:      [IN]    file path
 *  permission:     [IN]    content permission
 *  icon:           [IN]    icon
 * RETURNS
 *  A boolean value
 * RETURN VALUES
 *  MMI_TRUE: need to extend rights
 *  MMI_FALSE: no need
 *****************************************************************************/
extern MMI_BOOL mmi_rmgr_extend_rights_full_procedure(U16 *filepath, U8 permission, U16 icon);

#endif /* __RIGHTSMGRGPROT_H__ */

