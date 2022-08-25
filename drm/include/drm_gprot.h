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
 * drm_gprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
#ifndef DRM_GPROT_H
#define DRM_GPROT_H

#include "Fs_type.h"
#include "drm_def.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "app_mine.h"
#include "drm_errcode.h"

#if defined (__DRM_SUPPORT__)

/*****************************************************************************
 * FUNCTION
 *  DRM_consume_rights
 * DESCRIPTION
 *  consume DRM rights
 * PARAMETERS
 *  source:         [IN]    file handle
 *  permission:     [IN]    permission type
 *  callback:       [IN]    a callback function to notify ap when the right expired
 * RETURNS
 *  consumer handle
 * RETURN VALUES
 *  =0: It is not a drm file.
 *  >0: The consumer handle, ap can use this handle to stop and cancel the comsumption
 *  <0: refer to drm_proc_enum
 *****************************************************************************/
extern kal_int32 DRM_consume_rights(FS_HANDLE source, kal_uint8 permission,
                                    void (*callback) (kal_int32 result, kal_int32 id));

/*****************************************************************************
 * FUNCTION
 *  DRM_consume_timed_rights
 * DESCRIPTION
 *  Only consume time-based right. Only used for second time consumption.
 * PARAMETERS
 *  source:         [IN]    File handle.
 *  permission:     [IN]    Permission type.
 *  callback:       [IN]    A callback function to notify ap when the right expired.
 * RETURNS
 *  a consume id
 * RETURN VALUES
 *  =0:    It is not a drm file.
 *  >0:    The consumer handle, ap can use this handle to stop and cancel the comsumption
 *  <0:    refer to drm_proc_enum
 *****************************************************************************/
extern kal_int32 DRM_consume_timed_rights(FS_HANDLE source, kal_uint8 permission,
                                          void (*callback) (kal_int32 result, kal_int32 id));

/*****************************************************************************
 * FUNCTION
 *  DRM_stop_consume
 * DESCRIPTION
 *  To stop rights consuming
 * PARAMETERS
 *  id:     [IN]    the consume id
 * RETURNS
 *  void
 *****************************************************************************/
extern void DRM_stop_consume(kal_int32 id);

/*****************************************************************************
 * FUNCTION
 *  DRM_consume_rights_with_module
 * DESCRIPTION
 *  The same function to DRM_consume_right. But AP can request the callback
 *  function should be invoked in which task.
 * PARAMETERS
 *  source:         [IN]    File handle.
 *  permission:     [IN]    Permission type.
 *  callback:       [IN]    A callback function to notify ap when the right expired.
 *  module:         [IN]    Task module id.
 * RETURNS
 *  a consume id
 * RETURN VALUES
 *  =0:    It is not a drm file.
 *  >0:    The consumer handle, ap can use this handle to stop and cancel the comsumption
 *  <0:    refer to drm_proc_enum
 *****************************************************************************/
extern kal_int32 DRM_consume_rights_with_module(FS_HANDLE source, kal_uint8 permission,
                                                void (*callback) (kal_int32 result, kal_int32 id), module_type module);
/*****************************************************************************
 * FUNCTION
 *  DRM_consume_timed_rights_with_module
 * DESCRIPTION
 *  The same function to DRM_consume_timed_right. But AP can request the callback
 *  function should be invoked in which task.
 * PARAMETERS
 *  source:         [IN]    File handle.
 *  permission:     [IN]    Permission type.
 *  callback:       [IN]    A callback function to notify ap when the right expired.
 *  module:         [IN]    Task module id.
 * RETURNS
 *  a consume id
 * RETURN VALUES
 *  =0:    It is not a drm file.
 *  >0:    The consumer handle, ap can use this handle to stop and cancel the comsumption
 *  <0:    refer to drm_proc_enum
 *****************************************************************************/
extern kal_int32 DRM_consume_timed_rights_with_module(FS_HANDLE source, kal_uint8 permission,
                                                      void (*callback) (kal_int32 result, kal_int32 id),
                                                      module_type module);
/*****************************************************************************
 * FUNCTION
 *  DRM_consume_rights_by_cid
 * DESCRIPTION
 *  Select a spcific permision and consume the right object via cid.
 * PARAMETERS
 *  cid:            [IN]    the content id.
 *  permission:     [IN]    Permission type.
 *  callback:       [IN]    A callback function to notify ap when the right expired.
 * RETURNS
 *  a consume id
 * RETURN VALUES
 *  =0:    It is not a drm file.
 *  >0:    The consumer handle, ap can use this handle to stop and cancel the comsumption
 *  <0:    refer to drm_proc_enum
 *****************************************************************************/
extern kal_int32 DRM_consume_rights_by_cid(drm_cid_struct *cid, kal_uint8 permission,
                                           void (*callback) (kal_int32 result, kal_int32 id));

/*****************************************************************************
 * FUNCTION
 *  DRM_consume_timed_rights_by_cid
 * DESCRIPTION
 *  Only consume time-based right via cid. Only used for second time consumption.
 * PARAMETERS
 *  cid:            [IN]    the content id
 *  permission:     [IN]    Permission type.
 *  callback:       [IN]    A callback function to notify ap when the right expired.
 * RETURNS
 *  a consume id
 * RETURN VALUES
 *  =0:    It is not a drm file.
 *  >0:    The consumer handle, ap can use this handle to stop and cancel the comsumption
 *  <0:    refer to drm_proc_enum
 *****************************************************************************/
extern kal_int32 DRM_consume_timed_rights_by_cid(drm_cid_struct *cid, kal_uint8 permission,
                                                 void (*callback) (kal_int32 result, kal_int32 id));

/*****************************************************************************
 * FUNCTION
 *  DRM_pause_consume
 * DESCRIPTION
 *  To pause rights consuming
 * PARAMETERS
 *  id:  [IN]    the consumer id
 * RETURNS
 *  void
 *****************************************************************************/
extern void DRM_pause_consume(kal_int32 id);

/*****************************************************************************
 * FUNCTION
 *  DRM_resume_consume
 * DESCRIPTION
 *  To resume rights consuming
 * PARAMETERS
 *  id:             [IN]    the consume id
 * RETURNS
 *  if ap have permission to use the MO or not.
 * RETURN VALUES
 *  KAL_TRUE:   AP have permission to use it.
 *  KAL_FALSE:  AP doesn't have permission use it.
 *****************************************************************************/
extern kal_bool DRM_resume_consume(kal_int32 id);

/*****************************************************************************
 * FUNCTION
 *  DRM_rights_extendable
 * DESCRIPTION
 *  only for filemanager to check if the rights is extendable
 *  Note: FMGR only
 * PARAMETERS
 *  handle:     [IN]    The file handle.
 *  path:       [IN]    The file path. The first parameter would be ignored if this parameter is used.
 * RETURNS
 *  a boolean value
 *****************************************************************************/
extern kal_bool DRM_rights_extendable(kal_wchar *path);

/*****************************************************************************
 * FUNCTION
 *  DRM_consume_table_is_in_use
 * DESCRIPTION
 *  To check if anyone use rights now.
 *  Note: RMGR only
 * PARAMETERS
 *  void
 * RETURNS
 *  a boolean value
 * RETURN VALUES
 *  KAL_TRUE:   there is at least one use rights now
 *  KAL_FALSE:  no one use right now
 *****************************************************************************/
extern kal_bool DRM_consume_table_is_in_use(void);

/*****************************************************************************
 * FUNCTION
 *  DRM_validate_permission
 * DESCRIPTION
 *  Check DRM rights with specific permission.
 * PARAMETERS
 *  handle:         [IN]        Is already opened, it will also carry the error code of FS_Open.
 *  path:           [IN]        The file path. if this parametter is used, then the handle would be ignored.
 *  permission:     [IN]        The permission need to check.
 * RETURNS
 *  a boolean value
 * RETURN VALUES
 *  KAL_TRUE:   has at least one valid right object.
 *  KAL_FLASE:  there is no valid right object.
 *****************************************************************************/
extern kal_bool DRM_validate_permission(FS_HANDLE handle, kal_wchar *path, kal_uint8 permission);

/*****************************************************************************
 * FUNCTION
 *  DRM_validate_timed_permission
 * DESCRIPTION
 *  Only check DRM time-based rights with specific permission
 * PARAMETERS
 *  handle:         [IN]        Is already opened, it will also carry the error code of FS_Open.
 *  permission:     [IN]        If permission == DRM_PERMISSION_PLAY, this function will check the permission by current mime_type
 * RETURNS
 *  a boolean value
 * RETURN VALUES
 *  KAL_TRUE:   has at least one valid right object.
 *  KAL_FLASE:  there is no valid right object.
 *****************************************************************************/
extern kal_bool DRM_validate_timed_permission(FS_HANDLE handle, kal_uint8 permission);

/*****************************************************************************
 * FUNCTION
 *  DRM_validate_future_permission
 * DESCRIPTION
 *  Only check if the rights is valid in the future
 * PARAMETERS
 *  handle:         [IN]        Is already opened, it will also carry the error code of FS_Open.
 *  permission:     [IN]        If permission == DRM_PERMISSION_PLAY, this function will check the permission by current mime_type
 * RETURNS
 *  a boolean value
 * RETURN VALUES
 *  KAL_TRUE:   has at least one valid right object.
 *  KAL_FLASE:  there is no valid right object.
 *****************************************************************************/
extern kal_bool DRM_validate_future_permission(FS_HANDLE handle, kal_uint8 permission);

/*****************************************************************************
 * FUNCTION
 *  DRM_validate_forward_rule
 * DESCRIPTION
 *  Check if this content can be forward to internal application
 * PARAMETERS
 *  handle:         [IN]   The file handle.
 *  permission:     [IN]   The permission need to check.
 * RETURNS
 *  a boolean value
 * RETURN VALUES
 *  KAL_TRUE:   This content can be forwarded to internal application.
 *  KAL_FLASE:  This content cannot be forwarded to internal application.
 *****************************************************************************/
extern kal_bool DRM_validate_forward_rule(FS_HANDLE handle, kal_uint8 permission);

/*****************************************************************************
 * FUNCTION
 *  DRM_validate_permission_by_cid
 * DESCRIPTION
 *  Check DRM rights with specific permission.
 * PARAMETERS
 *  cid:            [IN]   Cid.
 *  permission:     [IN]   The permission need to check.
 * RETURNS
 *  a boolean value
 * RETURN VALUES
 *  KAL_TRUE:   has at least one valid right object.
 *  KAL_FLASE:  there is no valid right object.
 *****************************************************************************/
extern kal_bool DRM_validate_permission_by_cid(drm_cid_struct *cid, kal_uint8 permission);

/*****************************************************************************
 * FUNCTION
 *  DRM_validate_timed_permission_by_cid
 * DESCRIPTION
 *  Only check time-based DRM rights with specific permission.
 * PARAMETERS
 *  cid:            [IN]   Cid.
 *  permission:     [IN]   The permission need to check.
 * RETURNS
 *  a boolean value
 * RETURN VALUES
 *  KAL_TRUE:   has at least one valid right object.
 *  KAL_FLASE:  there is no valid right object.
 *****************************************************************************/
extern kal_bool DRM_validate_timed_permission_by_cid(drm_cid_struct *cid, kal_uint8 permission);

/*****************************************************************************
 * FUNCTION
 *  DRM_get_content_type
 * DESCRIPTION
 *  Get content type of a DRM file
 * PARAMETERS
 *  input:      [IN]    The file handle.
 *  path:       [IN]    The file path. The first parameter would be ignored if this parameter is used.
 * RETURNS
 *  A pointer point to content type string. Please refer to g_applib_mime_tbl.
 *****************************************************************************/
extern kal_uint8 *DRM_get_content_type(FS_HANDLE input, kal_wchar *path);

/*****************************************************************************
 * FUNCTION
 *  DRM_get_content_ext
 * DESCRIPTION
 *  get content extension name of a DRM file
 * PARAMETERS
 *  input:      [IN]    The file handle.
 *  path:       [IN]    The file path. The first parameter would be ignored if this parameter is used.
 * RETURNS
 *  A pointer point to content extension file name. Please refer to g_applib_mime_tbl.
 *****************************************************************************/
extern kal_char *DRM_get_content_ext(FS_HANDLE input, kal_wchar *path);

/*****************************************************************************
 * FUNCTION
 *  DRM_get_content_type_entry
 * DESCRIPTION
 *  Get content type and corresponding extension file name of a DRM file
 * PARAMETERS
 *  handle:     [IN]    The file handle.
 * RETURNS
 *  A pointer point to applib_mime_type_struct structure. Please refer to g_applib_mime_tbl.
 *****************************************************************************/
extern applib_mime_type_struct *DRM_get_content_type_entry(FS_HANDLE handle);

/*****************************************************************************
 * FUNCTION
 *  DRM_get_object_method
 * DESCRIPTION
 *  Get DRM method of a DRM content
 * PARAMETERS
 *  input:      [IN]    The file handle.
 *  path:       [IN]    The file path. The first parameter would be ignored if this parameter is used.
 * RETURNS
 *  refer to drm_method_enum
 *****************************************************************************/
extern kal_uint8 DRM_get_object_method(FS_HANDLE input, kal_wchar *path);

/*****************************************************************************
 * FUNCTION
 *  DRM_get_meta_size
 * DESCRIPTION
 *  To get meta data size in DCF
 * PARAMETERS
 *  input:      [IN]        file handle of the DCF
 *  meta_id:    [IN]        meta data id to query
 * RETURNS
 *    refer to drm_proc_enum
 * RETURN VALUES
 *  >0 : size
 *  DRM_RESULT_DATA_NOT_FOUND: no such meta data
 *  DRM_RESULT_NON_DRM: the given file is not a DRM content
 *  otherwise: File System error code
 *****************************************************************************/
extern kal_int32 DRM_get_meta_size(FS_HANDLE input, drm_meta_enum meta_id);

/*****************************************************************************
 * FUNCTION
 *  DRM_get_meta_data
 * DESCRIPTION
 *  To get meta data in DCF, in "UTF8" format
 * PARAMETERS
 *  input:      [IN]        file handle of the DCF
 *  meta_id:    [IN]        meta data id to query
 *  buffer:     [IN]        buffer to keep meta data
 *  size:       [IN]        size of buffer; if the given size < actual meta data
 *                          in DCF, only given size will be copied into buffer
 * RETURNS
 *    refer to drm_proc_enum
 * RETURN VALUES
 *  DRM_RESULT_OK: success
 *  DRM_RESULT_INVALID_PARA: negative error code
 *  DRM_RESULT_DATA_NOT_FOUND: no such meta data
 *  DRM_RESULT_NON_DRM: the given file is not a DRM content
 *  otherwise: File System error code
 *****************************************************************************/
extern kal_int32 DRM_get_meta_data(FS_HANDLE input, drm_meta_enum meta_id, kal_char *buffer, kal_int32 size);


#if !defined(__DRM_EXTERNAL__)


/*****************************************************************************
 * FUNCTION
 *  DRM_get_constraint
 * DESCRIPTION
 *  Get the constriant status of specific permission type.
 * PARAMETERS
 *  handle:     [IN]    The file handle.
 *  path:       [IN]    The file path. The first parameter would be ignored if this parameter is used.
 *  permission: [IN]    The permission type.
 *  cons:       [OUT]   Output the constraint status into this buffer.
 * RETURNS
 *  refer to drm_proc_enum
 *****************************************************************************/
extern kal_int32 DRM_get_constraint(
                    FS_HANDLE handle,
                    kal_wchar *path,
                    kal_uint8 permission,
                    drm_constraint_struct *cons);

extern kal_int32 DRM_get_start_time(FS_HANDLE handle, kal_wchar *path, kal_uint8 permission, applib_time_struct *start_time);
extern kal_int32 DRM_get_end_time(FS_HANDLE handle, kal_wchar *path, kal_uint8 permission, applib_time_struct *end_time);
extern kal_int32 DRM_get_interval(FS_HANDLE handle, kal_wchar *path, kal_uint8 permission, kal_int32 *interval);
extern kal_int32 DRM_get_left_count(FS_HANDLE handle, kal_wchar *path, kal_uint8 permission, kal_int64 *left_count);
extern kal_int32 DRM_get_total_count(FS_HANDLE handle, kal_wchar *path, kal_uint8 permission, kal_int64 *total_count);
/*****************************************************************************
 * FUNCTION
 *  DRM_async_cancel_process
 * DESCRIPTION
 *  To cancel an action in DRM task
 * PARAMETERS
 *  serial:     [IN]    The serial number that could control specific action in DRM task
 * RETURNS
 *  a boolean value
 * RETURN VALUES
 *  KAL_TRUE:   cancel successful
 *  KAL_FALSE:  fail to cancel
 *****************************************************************************/
extern kal_bool DRM_async_cancel_process(kal_uint8 serial);

/*****************************************************************************
 * FUNCTION
 *  DRM_async_cancel_process
 * DESCRIPTION
 *  To cancel current action in DRM task
 * PARAMETERS
 *  void
 * RETURNS
 *  a boolean value
 * RETURN VALUES
 *  KAL_TRUE:   cancel successful
 *  KAL_FALSE:  fail to cancel
 *****************************************************************************/
extern kal_bool DRM_async_cancel_current_process(void);

/*****************************************************************************
 * FUNCTION
 *  DRM_parse_drm_message
 * DESCRIPTION
 *  Parse the drm message. Save the RO into database, and return the information
 *  of drm message back. AP can use the plaintext directly after they get the
 *  plaintext offset. We also do not delete the source file in this API.
 * PARAMETERS
 *  src_path:   [IN]    the src_path
 *  seed:       [IN]    A seed to generate CID, can be null but will generate the
 *                      same ro once they invoke this function again. Suggest MMS
 *                      and E-mail can pass an unique seed into drm agent.
 *  seed_len:   [IN]    seed length.
 *  serial:     [OUT]   serial number
 *  info:       [OUT]   The drm message information would save into this structure.
 *  callback:   [IN]    Async when this parameter is not NULL.
 * RETURNS
 *  refer to drm_proc_enum
 *****************************************************************************/
extern kal_int32 DRM_parse_drm_message(kal_wchar *src_path,
                                       kal_uint8 *seed,
                                       kal_int32 seed_len,
                                       kal_int32 *serial,
                                       drm_message_info_struct *info,
                                       void (*callback) (kal_uint8 serial,
                                                         kal_int32 result, drm_message_info_struct *info));


/*****************************************************************************
 * FUNCTION
 *  DRM_install_object
 * DESCRIPTION
 *  generic DRM message/content handler
 * PARAMETERS
 *  content_type:           [IN]        HTTP content type, with null terminator
 *  src_path:               [IN]        source file to intall
 *  src_need_kept:          [IN]        to keep source file
 *  dest_path:              [IN/OUT]    path to put encoded result
 *  dest_buffer_len_in_byte:[IN]        buffer size of dest_path, to avoid memory corruption
 *  serial:                 [OUT]       a serial number of this install job
 *  mime_type:              [IN]        the "real" mime_type of the input content
 *  callback:               [IN]        callback after finish to install; must be given if is_async is true
 * RETURNS
 *  refer to drm_proc_enum
 *****************************************************************************/
extern kal_int32 DRM_install_object(kal_uint8 *content_type,
                                 kal_wchar *src_path,
                                 kal_bool src_need_kept,
                                 kal_wchar *dest_path,
                                 kal_uint32 dest_buffer_len_in_byte,
                                 kal_uint8 *serial,
                                 applib_mime_type_struct **mime_type,
                                 void (*callback) (kal_uint8 serial,
                                                   kal_int32 result, applib_mime_type_struct *mime_type));

/*****************************************************************************
 * FUNCTION
 *  DRM_encode_drm_message
 * DESCRIPTION
 *  Encode DRM message into DCF format and append it to another file.
 * PARAMETERS
 *  src_path:       [IN]    Original DRM message file.
 *  dest_path:      [IN]    Destination file.
 *  offset:         [IN]    Offset in Destination file.
 *  serial:         [OUT]   Serial number to control this process.
 *  callback:       [IN]    a callback to indicate app the result
 * RETURNS
 *  refer to drm_proc_enum
 *****************************************************************************/
extern kal_int32 DRM_encode_drm_message(
                    kal_wchar *src_path,
                    kal_wchar *dest_path,
                    kal_uint32 offset,
                    kal_uint8 *serial,
                    drm_general_callback callback);

/*****************************************************************************
 * FUNCTION
 *  DRM_predict_encoded_size
 * DESCRIPTION
 *  Predict size of DCF file before encoding
 * PARAMETERS
 *  src_path:      [IN]     Original DRM message file.
 * RETURNS
 *  The predicted DCF file size.
 *****************************************************************************/
extern kal_int32 DRM_predict_encoded_size(kal_wchar *src_path);

/*****************************************************************************
 * FUNCTION
 *  DRM_register_sd_callback
 * DESCRIPTION
 *  register sd file with timer, callback will be executed when timer expired or rights arrive.
 * PARAMETERS
 *  file_path:      [IN]    File path of sd file
 *  timer:          [IN]    Millisecond
 *  para:           [IN]    Parameter of callback function
 *  callback:       [IN]    Callback function when timer expired
 * RETURNS
 *  DRM_RESULT_INVALID_PARA: callback is null
 *  DRM_RESULT_INVALID_FORMAT: the sd file format is incorrect, for ex: cid is empty
 *  otherwise: registration number
 *****************************************************************************/
extern kal_int32 DRM_register_sd_callback(
            kal_wchar *file_path,
            kal_uint32 timer,
            void *para,
            drm_sd_callback callback);

/*****************************************************************************
 * FUNCTION
 *  DRM_register_sd_callback_by_handle
 * DESCRIPTION
 *  register sd file with timer, callback will be executed when timer expired or rights arrive.
 * PARAMETERS
 *  input:          [IN]    File path of sd file
 *  timer:          [IN]    Millisecond
 *  para:           [IN]    Parameter of callback function
 *  callback:       [IN]    Callback function when timer expired
 * RETURNS
 *  DRM_RESULT_INVALID_PARA: callback is null
 *  DRM_RESULT_INVALID_FORMAT: the sd file format is incorrect, for ex: cid is empty
 *  otherwise: registration number
 *****************************************************************************/
extern kal_int32 DRM_register_sd_callback_by_handle(
            FS_HANDLE input,
            kal_uint32 timer,
            void *para,
            drm_sd_callback callback);

/*****************************************************************************
 * FUNCTION
 *  DRM_app_sd_expiry_hdlr
 * DESCRIPTION
 *  separate delivery expiry handler
 * PARAMETERS
 *  local_para_ptr: [IN]    Confirm message
 * RETURNS
 *  void
 *****************************************************************************/
extern void DRM_app_sd_expiry_hdlr(void *local_para_ptr);

/*****************************************************************************
 * FUNCTION
 *  DRM_cancel_sd_callback
 * DESCRIPTION
 *  To cancel the registration and callback
 * PARAMETERS
 *  serial:         [IN]    registration number
 * RETURNS
 *  void
 *****************************************************************************/
extern void DRM_cancel_sd_callback(kal_uint8 serial);

/*****************************************************************************
 * FUNCTION
 *  DRM_sd_callback_status
 * DESCRIPTION
 *  To get SD registration status by passing serial
 * PARAMETERS
 *  serial:         [IN]    registration number
 * RETURNS
 *  someone waiting or not
 *****************************************************************************/
extern kal_bool DRM_sd_callback_status(kal_uint8 serial);

/*****************************************************************************
 * FUNCTION
 *  DRM_has_valid_rights
 * DESCRIPTION
 *  Check if any valid rights exist without caring constraint type
 * PARAMETERS
 *  file_path:      [IN]    File path
 * RETURNS
 *  kal_bool(?)
 *****************************************************************************/
extern kal_bool DRM_has_valid_rights(kal_wchar *file_path);

/*****************************************************************************
 * FUNCTION
 *  DRM_activate_file
 * DESCRIPTION
 *  To activate a DRM content.
 * PARAMETERS
 *  file_path:      [IN]    The file path of DRM content.
 *  permission:     [IN]    The permission type.
 *  serial:         [OUT]   The serial number to control the process of activation
 *  callback:       [IN]    The callback function
 * RETURNS
 *  DRM_PROC_ENCRYPT_BUSY: success
 *  DRM_RESULT_NOT_SUPPORT: otherwise
 *****************************************************************************/
extern drm_proc_enum DRM_activate_file(
                        kal_wchar *file_path,
                        kal_uint8 permission,
                        kal_uint8 *serial,
                        drm_general_callback callback);

/*****************************************************************************
 * FUNCTION
 *  DRM_activate_file_by_handle
 * DESCRIPTION
 *  To activate a DRM content.
 * PARAMETERS
 *  handle:         [IN]    The file handle.
 *  permission:     [IN]    The permission type.
 *  serial:         [OUT]   The serial number to control the process of activation
 *  callback:       [IN]    The callback function
 * RETURNS
 *  DRM_PROC_ENCRYPT_BUSY: success
 *  DRM_RESULT_NOT_SUPPORT: otherwise
 *****************************************************************************/
extern drm_proc_enum DRM_activate_file_by_handle(FS_HANDLE handle, kal_uint8 *serial, drm_general_callback callback);

/*****************************************************************************
 * FUNCTION
 *  DRM_register_file
 * DESCRIPTION
 *  To register the path to DRM database
 * PARAMETERS
 *  file_path:       [IN]    The file path.
 * RETURNS
 *  refer to drm_proc_enum
 *****************************************************************************/
extern kal_int32 DRM_register_file(kal_wchar *file_path);

/*****************************************************************************
 * FUNCTION
 *  DRM_get_version
 * DESCRIPTION
 *  To get DRM Agent Version
 * PARAMETERS
 *  void
 * RETURNS
 *  [bit 8~15] Major Version (0 to 255)
 *  [bit 0~7]  Minor Version (0 to 255)
 *****************************************************************************/
extern kal_int32 DRM_get_version(void);

/*****************************************************************************
 * FUNCTION
 *  DRM_get_rights_issuer
 * DESCRIPTION
 *  To get the rights issuer of a DRM content
 * PARAMETERS
 *  input:      [IN]        File handle.
 *  buffer:     [OUT]       A buffer to output rights issuer
 *  size:       [IN/OUT]    Input the buffer size and output the rights issuer length
 * RETURNS
 *  refer to drm_proc_enum
 *****************************************************************************/
extern kal_int32 DRM_get_rights_issuer(FS_HANDLE input, kal_char *buffer, kal_uint32 *size);


/*****************************************************************************
 * FUNCTION
 *  DRM_is_drm_file
 * DESCRIPTION
 *  To check if the file is a DRM file or not.
 * PARAMETERS
 *  handle:     [IN]    The file handle.
 *  path:       [IN]    The file path. The first parameter would be ignored if this parameter is used.
 * RETURNS
 *  a boolean value
 *****************************************************************************/
extern kal_bool DRM_is_drm_file(FS_HANDLE handle, kal_wchar *path);

/*****************************************************************************
 * FUNCTION
 *  DRM_is_drm_file
 * DESCRIPTION
 *  To check if the file is a DRM file or not.
 * PARAMETERS
 *  handle:     [IN]    The file handle.
 *  path:       [IN]    The file path. The first parameter would be ignored if this parameter is used.
 * RETURNS
 *  a boolean value
 *****************************************************************************/
extern kal_bool DRM_interdev_movable(FS_HANDLE handle, kal_wchar *path);


#ifdef __DRM_V02__
typedef struct
{
    kal_uint32 file_size;
    FS_DOSDateTime creation_date;
    /*
     * kal_uint8  attribute;
     * kal_bool   is_short;
     */
} drm_file_info_struct;

typedef struct
{
    kal_char *contentID;
    kal_char *riUrl;
    kal_bool selectiveEncryption;   /* should be set to 1 */
    kal_uint8 IVLength;             /* should be set to 16 */
    kal_uint8 encryptionMethod;     /* should be set to 0x01 for CBC and 0x02 for CTR mode, 0x00 for null ecryption */
    kal_uint8 *IVNonce;
} drm_track_meta_struct;

typedef struct
{
    kal_int8 *kmsInfo;
    kal_int32 kmsInfoSize;
} drm_track_kms_struct;

typedef struct
{
    kal_int8 *mdriBox;
    kal_int32 mdriBoxSize;
} drm_mdribox_struct;

/*****************************************************************************
 * FUNCTION
 *  DRM_get_find_cntx
 * DESCRIPTION
 *  This function is to get a DRM multi-part DCF context,
 *  so that DRM engine could save some information in it
 *  Note: Because DRM engine will allocate a memory block for this context,
 *  it must be paired with DRM_find_close to free the memory
 * PARAMETERS
 *  void
 * RETURNS
 *  A pointer to the DRM multi-part DCF context
 *****************************************************************************/
extern void *DRM_get_find_cntx(void);

/*****************************************************************************
 * FUNCTION
 *  DRM_find_firstN
 * DESCRIPTION
 *  This function is to get the first file handle according to the given context,
 *  DRM multi-part DCF file name, desired mime types and skipped number.
 * PARAMETERS
 *  find_cntx:          [IN]     The context gotten from DRM_get_find_cntx.
 *  file_path:          [IN]     File path of DRM archive.
 *  PatternArray:       [IN]     A mime type array that applications looking for.
 *  PatternNum:         [IN]     The element number of PatternArray.
 *  FileInfo:           [IN/OUT] The information of the matching result. Applications MUST prepare the buffer.
 *  FileName:           [IN/OUT] The file name of the matching result. Applications MUST prepare the buffer.
 *  MaxLen:             [IN]     The size of FileName.
 *  EntryIndex:         [IN]     How many matching results to skip.
 * RETURNS
 *  >=0, means successful, return an object handle.
 *  < 0, refer to drm_proc_enum
 *****************************************************************************/
extern FS_HANDLE DRM_find_firstN(
                    void *find_cntx,
                    kal_wchar *file_path,
                    FS_Pattern_Struct *PatternArray,
                    kal_uint32 PatternNum,
                    drm_file_info_struct *FileInfo,
                    kal_wchar *FileName,
                    kal_uint32 MaxLen,
                    kal_int32 EntryIndex);

/*****************************************************************************
 * FUNCTION
 *  DRM_find_nextN
 * DESCRIPTION
 *  This function is to get the next file handle according to the given context and skipped number.
 *  Note: It MUST use only after DRM_find_firstN and with the result (file handle)
 *  of last DRM_find_firstN or DRM_find_nextN
 * PARAMETERS
 *  find_cntx:  [IN] The context gotten from DRM_get_find_cntx.
 *  handle:     [IN] The file handle gotten last time.
 *  FileInfo:   [IN/OUT] The information of the matching result. Applications MUST prepare the buffer.
 *  FileName:   [IN/OUT] The file name of the matching result. Applications MUST prepare the buffer.
 *  MaxLen:     [IN] The size of FileName.
 *  distance:   [IN] The size of FileName.
 * RETURNS
 *  A file handle or refer to drm_proc_enum
 *****************************************************************************/
extern kal_int32 DRM_find_nextN(
                    void *find_cntx,
                    FS_HANDLE handle,
                    drm_file_info_struct *FileInfo,
                    kal_wchar *FileName,
                    kal_uint32 MaxLen,
                    kal_int32 distance);

/*****************************************************************************
 * FUNCTION
 *  DRM_find_close
 * DESCRIPTION
 *  This function is to close the multi-part DCF finding session and release allocated memory.
 * PARAMETERS
 *  find_cntx:      [IN]    the context gotten from DRM_get_find_cntx.
 *  handle:         [IN]    The file handle
 * RETURNS
 *  >0 means successful
 *  refer to drm_proc_enum
 *****************************************************************************/
extern kal_int32 DRM_find_close(void *find_cntx, FS_HANDLE handle);

/*****************************************************************************
 * FUNCTION
 *  DRM_is_archive_object
 * DESCRIPTION
 *  To check if the DRM content is an object in DRM archive or not.
 * PARAMETERS
 *  handle:     [IN]    The file handle.
 *  path:       [IN]    The file path. The first parameter would be ignored if this parameter is used.
 * RETURNS
 *  a boolean value.
 *****************************************************************************/
extern kal_bool DRM_is_archive_object(FS_HANDLE handle, kal_wchar *path);

/*****************************************************************************
 * FUNCTION
 *  DRM_is_archive
 * DESCRIPTION
 *  To check if the DRM content is aa DRM archive or not.
 * PARAMETERS
 *  handle:     [IN]    The file handle.
 *  path:       [IN]    The file path. The first parameter would be ignored if this parameter is used.
 * RETURNS
 *  a boolean value.
 *****************************************************************************/
extern kal_bool DRM_is_archive(FS_HANDLE handle, kal_wchar *path);

#if defined(__DRM_PDCF__)

/*****************************************************************************
 * FUNCTION
 *  DRM_construct_pdcf
 * DESCRIPTION
 *  To construct a pdcf handle, this handle is used to control the whole
 *  decrypt scenario
 * PARAMETERS
 *  file_handle:    [IN]    the file_handle, could be 0 in streaming case
 * RETURNS
 *  drm_proc_enum
 *****************************************************************************/
extern kal_int32 DRM_construct_pdcf(kal_int32 file_handle);

/*****************************************************************************
 * FUNCTION
 *  DRM_init_track_by_kms
 * DESCRIPTION
 *  Ininital track decoder via key management system
 * PARAMETERS
 *  pdcf_handle:    [IN]    return by DRM_construct_pdcf
 *  trackID:        [IN]    0~n-1, should inital sequencely or assert
 *  permission:     [IN]    DRM_PERMISSION_PLAY
 *  kms:            [IN]    drm key management system
 * RETURNS
 *  >= 0, a pdcf track handle if success.
 *  < 0, refer to drm_proc_enum
 *****************************************************************************/
extern kal_int32 DRM_init_track_by_kms(
                    kal_int32 pdcf_handle,
                    kal_int32 trackID,
                    kal_uint8 permission,
                    drm_track_kms_struct *kms);

/*****************************************************************************
 * FUNCTION
 *  DRM_init_track_by_meta
 * DESCRIPTION
 *  Ininital track decoder via key management system
 * PARAMETERS
 *  pdcf_handle:    [IN]    return by DRM_construct_pdcf
 *  trackID:        [IN]    0~n-1, should inital sequencely or assert
 *  permission:     [IN]    DRM_PERMISSION_PLAY
 *  meta:           [IN]    meta data
 * RETURNS
 *  >= 0, a pdcf track handle if success.
 *  < 0, refer to drm_proc_enum
 *****************************************************************************/
extern kal_int32 DRM_init_track_by_meta(
                    kal_int32 pdcf_handle,
                    kal_int32 trackID,
                    kal_uint8 permission,
                    drm_track_meta_struct *meta);
/*****************************************************************************
 * FUNCTION
 *  drm_core_destruct_pdcf
 * DESCRIPTION
 *  destruct pdcf handle
 * PARAMETERS
 *  pdcf_handle:    [IN]    return by DRM_construct_pdcf
 * RETURNS
 *    refer to drm_proc_enum
 *****************************************************************************/
extern kal_int32 DRM_destruct_pdcf(kal_int32 pdcf_handle);

/*****************************************************************************
 * FUNCTION
 *  drm_core_decode_track
 * DESCRIPTION
 *  decode the pdcf data
 * PARAMETERS
 *  track_handle:   [IN]        return by DRM_init_track_by_meta or DRM_init_track_by_kms
 *  src:            [IN]        the buffer try to decode, includes the au header
 *  srcSize:        [IN]        the buffer size
 *  out:            [OUT]       the buffer we put the resource, can be same as src
 *  outSize:        [IN/OUT]    the buffer size, and we output the final size.
 *  is_streaming:   [IN]        to indicate this action is for local play or streaming.
 * RETURNS
 *  refer to drm_proc_enum
 *****************************************************************************/
extern kal_int32 DRM_decode_track(
                    kal_int32 track_handle,
                    kal_uint8 *src,
                    kal_uint32 srcSize,
                    kal_uint8 *out,
                    kal_uint32 *outSize,
                    kal_bool is_streaming);
#endif /* defined(__DRM_PDCF__) */ 
#endif /* __DRM_V02__ */ 

/*****************************************************************************
 * FUNCTION
 *  DRM_app_common_hdlr
 * DESCRIPTION
 *  A common DRM message handler for every task.
 * PARAMETERS
 *  ilm:            [IN]        The message.
 * RETURNS
 *  A boolean value
 * RETURN VALUES
 *  KAL_TRUE:   This message can be handled by this handler.
 *  KAL_FALSE:  This message cannot be handled by this handler.
 *****************************************************************************/
extern kal_bool DRM_app_common_hdlr(void *ilm);
#endif /* !__DRM_EXTERNAL__ */
#endif /* defined (__DRM_SUPPORT__) */ 

/*****************************************************************************
 * FUNCTION
 *  DRM_open_file
 * DESCRIPTION
 *  Open file, if file is a DRM content, retreive rights information. otherwise simply open file.
 * PARAMETERS
 *  file_path:      [IN]    File path.
 *  flags:          [IN]    Refer to FS_Open parameter, ex: FS_READ_WRITE, FS_READ_ONLY.
 *  permission:     [IN]    Permission type.
 * RETURNS
 *  >=0, file handle
 *  < 0, refer to drm_proc_enum and FS eturn code
 *****************************************************************************/
extern FS_HANDLE DRM_open_file(kal_wchar *file_path, kal_uint32 flags, kal_uint8 permission);

/*****************************************************************************
 * FUNCTION
 *  DRM_close_file
 * DESCRIPTION
 *  This function is for application to close a file in the same way of using File System API,
 *  only that this API will also reset DRM information if the closed file is a DRM file.
 *  For DRM files, calling DRM_close_file will clean up all extra information kept for the file,
 *  including rights object, temp decrypted file¡Ketc.
 * PARAMETERS
 *  object:     [IN]    the file handle of the file to be closed
 * RETURNS
 *  refer to drm_proc_enum and FS return code
 *****************************************************************************/
extern kal_int32 DRM_close_file(FS_HANDLE object);

/*****************************************************************************
 * FUNCTION
 *  DRM_read_file
 * DESCRIPTION
 *  This function is for application to read data from file in the same
 *  way of using File System API, only that this API will first decrypt the
 *  source file if it is a DRM file and not decrypted yet. For DRM files,
 *  calling DRM_read_file function will actually read data from the temp
 *  decrypted file with proper starting position (maybe changed by DRM_seek_file API).
 * PARAMETERS
 *  source:      [IN]    the source file to be read
 *  buffer:      [IN]    the buffer to put the read back data
 *  size:        [IN]    the size to be read
 *  length:      [OUT]   the actual read back data size
 * RETURNS
 *  refer to drm_proc_enum and FS return code
 *****************************************************************************/
extern kal_int32 DRM_read_file(FS_HANDLE source, void *buffer, kal_uint32 size, kal_uint32 *length);

/*****************************************************************************
 * FUNCTION
 *  DRM_seek_file
 * DESCRIPTION
 *  This function is for application to seek file in the same way of using File
 *  System API, only that this API will first decrypt the source file if it is a
 *  DRM file and not decrypted yet. For DRM files, calling DRM_seek_file function
 *  will actually seek within the temp decrypted file to ensure the file position
 *  is exactly what caller wants.
 * PARAMETERS
 *  source:      [IN]    The source file to be sought.
 *  offset:      [IN]    Specify how far the file pointer should be moved.
 *  ref:         [IN]    Specify where to start the seek.
 * RETURNS
 *  refer to drm_proc_enum and FS return code
 *****************************************************************************/
extern kal_int32 DRM_seek_file(FS_HANDLE source, kal_int32 offset, kal_uint8 ref);

/*****************************************************************************
 * FUNCTION
 *  DRM_seek_large_file
 * DESCRIPTION
 *  This function is for application to seek file in the same way of using File
 *  System API, only that this API will first decrypt the source file if it is a
 *  DRM file and not decrypted yet. For DRM files, calling DRM_seek_file function
 *  will actually seek within the temp decrypted file to ensure the file position
 *  is exactly what caller wants. This API supports 4Gb file size.
 * PARAMETERS
 *  source:      [IN]    The source file to be sought.
 *  offset:      [IN]    Specify how far the file pointer should be moved.
 *  ref:         [IN]    Specify where to start the seek.
 * RETURNS
 *  refer to drm_proc_enum and FS return code
 *****************************************************************************/

extern kal_int64 DRM_seek_large_file(FS_HANDLE source, kal_int64 offset, kal_uint8 ref);

/*****************************************************************************
 * FUNCTION
 *  DRM_set_seek_hint
 * DESCRIPTION
 *  This function will directly divert to FS_SetSeekHint
 * PARAMETERS
 *  handle:     [IN]    Please see FS_SetSeekHint
 *  HintNum:    [IN]    Please see FS_SetSeekHint
 *  Hint:       [IN]    Please see FS_SetSeekHint
 * RETURNS
 *  Please see FS_SetSeekHint
 *****************************************************************************/
extern kal_int32 DRM_set_seek_hint(FS_HANDLE handle, UINT HintNum, FS_FileLocationHint *Hint);

/*****************************************************************************
 * FUNCTION
 *  DRM_file_size
 * DESCRIPTION
 *  This function is for application to query file size in the same way of
 *  using File System API, only that this API will first decrypt the source
 *  file if it is a DRM file and not decrypted yet.
 * PARAMETERS
 *  source:      [IN]    The source file handle
 *  size:        [OUT]   used to return file size to the caller
 * RETURNS
 *  refer to drm_proc_enum and FS return code
 *****************************************************************************/
extern kal_int32 DRM_file_size(FS_HANDLE source, kal_uint32 *size);

/*****************************************************************************
 * FUNCTION
 *  DRM_file_pos
 * DESCRIPTION
 *  This function is for application to query file current position in the
 *  same way of using File System API. only that this API will first decrypt
 *  the source file if it is a DRM file and not decrypted yet.
 * PARAMETERS
 *  source:     [IN]    The source file handle.
 *  pos:        [OUT]   Used to return file position to the caller.
 * RETURNS
 *  zero for success            (1.0)
 *  negative for error code     (1.0/2.0)
 *  positive for content number (2.0)
 *****************************************************************************/
extern kal_int32 DRM_file_pos(FS_HANDLE source, kal_uint32 *pos);

/*****************************************************************************
 * FUNCTION
 *  DRM_get_open_hint
 * DESCRIPTION
 *  Get the previous open hint if the file_path is the same as previous.
 *  This API can enhance the performance for file open, especially open the same
 *  file many times in short time.
 * PARAMETERS
 *  file_path:      [IN]    File path.
 * RETURNS
 *  NULL, the file path is different or there is no previous open hint.
 *  Not NULL, means successful.
 *****************************************************************************/
extern FS_FileOpenHint *DRM_get_open_hint(kal_wchar *file_path);

/*****************************************************************************
 * FUNCTION
 *  DRM_set_open_hint
 * DESCRIPTION
 *  This function is for application to set hint.
 * PARAMETERS
 *  in:     [IN]    The source file handle.
 * RETURNS
 *  refer to fs_errcode.h
 *****************************************************************************/
extern kal_int32 DRM_set_open_hint(FS_FileLocationHint *in);

/*****************************************************************************
 * FUNCTION
 *  DRM_clean_open_hint
 * DESCRIPTION
 *  Clear all open hint
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void DRM_clean_open_hint(void);
#endif /* DRM_GPROT_H */ 

