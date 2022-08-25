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
 * drm_def.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef DRM_DEF_H
#define DRM_DEF_H

#include "app_datetime.h"
#include "kal_general_types.h"

#define DRM_PERMISSION_NONE         0x00
#define DRM_PERMISSION_PLAY         0x01
#define DRM_PERMISSION_DISPLAY      0x02
#define DRM_PERMISSION_EXECUTE      0x04
#define DRM_PERMISSION_PRINT        0x08
#define DRM_PERMISSION_EXPORT       0x10
#define DRM_PERMISSION_ALL          0x80

#ifdef __DRM_SUPPORT__
#include "app_mine.h"
#define DRM_MAX_PATH_LENGTH     261
#define DRM_MAX_KEY_LENGTH      16
#define DRM_MAX_ID_LENGTH       255
#define DRM_MAX_URL_LENGTH      128
#define DRM_MAX_LINE_LENGTH     128
#define DRM_MAX_FILE_HANDLE     32

#define DRM_MIN_FS_SIZE         1024
#define DRM_MAX_ODKM_SIZE       2048

/* seconds */
#define DRM_DEFAULT_WAIT 25
#define DRM_DEFAULT_UNLIMITED_WAIT (0xFFFFFFFF)

#if !defined(__DRM_EXTERNAL__)
#define __DRM_SUPPORT_SD_CALLBACK__
#endif

#ifdef __DRM_SUPPORT_SD_CALLBACK__
#define DRM_SD_CALLBACK_MAX_NUM 30
#endif 

#define DRM_CONSTRAINT_UNINIT       0x00
#define DRM_CONSTRAINT_COUNT        0x01
#define DRM_CONSTRAINT_DATETIME     0x02
#define DRM_CONSTRAINT_INTERVAL     0x04
#define DRM_CONSTRAINT_NONE         0x08
/* <2.0> */
#define DRM_CONSTRAINT_TIMEDCOUNT   0x10
#define DRM_CONSTRAINT_ACCUMULATED  0X20
#define DRM_CONSTRAINT_INDIVIDUAL   0X40
#define DRM_CONSTRAINT_SYSTEM       0X80

#define DRM_MIMETYPE_MESSAGE            "application/vnd.oma.drm.message"
#define DRM_MIMETYPE_CONTENT            "application/vnd.oma.drm.content"
#define DRM_MIMETYPE_RIGHTS             "application/vnd.oma.drm.rights+xml"
#define DRM_MIMETYPE_RIGHTS_WB          "application/vnd.oma.drm.rights+wbxml"

/* <2.0> */
#define DRM_MIMETYPE_ROAP_PDU           "application/vnd.oma.drm.roap-pdu+xml"
#define DRM_MIMETYPE_ROAP_TRIGGER       "application/vnd.oma.drm.roap-trigger+xml"

typedef enum
{
    DRM_METHOD_NONE = 0,
    DRM_METHOD_FORWARD_LOCK = 1,
    DRM_METHOD_COMBINED_DELIVERY = 2,
    DRM_METHOD_SEPARATE_DELIVERY = 4,
    DRM_METHOD_V2 = 8,
    DRM_METHOD_PDCF = 16
} drm_method_enum;

/* Meta data */
typedef enum
{
    DRM_META_CONTENTURI = 0,        /* 1.0: "ContentURI" field */
    DRM_META_RIGHTS_ISSUER,         /* 1.0: "Rights-Issuer" header */
    DRM_META_CONTENT_LOCATION,      /* 1.0: "Content-Location" header *//* not standard */
    DRM_META_CONTENT_NAME,          /* 1.0: "Content-Name" header */
    DRM_META_CONTENT_DESCRIPTION,   /* 1.0: "Content-Description" header */
    DRM_META_CONTENT_VENDOR,        /* 1.0: "Content-Vendor" header */
    DRM_META_ICON_URI,              /* 1.0: "Icon URI" header */
    DRM_META_CONTENT_URL,           /* 2.0: Content URL */
    DRM_META_CONTENT_VERSION,       /* 2.0: Content Version */
    DRM_META_COPYRIGHT,             /* 2.0: Copyright */
    DRM_META_INFO_URL,              /* 2.0: Info URL */
    DRM_META_PREVIEW_URI,           /* 2.0: Preview URI */
    DRM_META_MAX
} drm_meta_enum;

#define DRM_META_01_TOTAL DRM_META_CONTENT_URL

#define DRM_PATH L"Z:\\@DRM\\"

#define DRM_VERNO_REC L"Z:\\@DRM\\verno.txt"

#define DRM_MMS_PATH L"Z:\\@MMS_DRM\\"

#define DRM_DEFAULT_APP_PATH "Z:\\@DRM\\"
#define DRM_DEFAULT_RP_PATH DRM_DEFAULT_APP_PATH"rp\\"
#define DRM_DEFAULT_CER_PATH DRM_DEFAULT_APP_PATH"bscidrm2\\"
#define DRM_DEFAULT_TEMP_PATH DRM_DEFAULT_APP_PATH"tmp\\"

#define DRM_SCAN_QUEUE_FILEPATH DRM_PATH L"scan.db"
#define DRM_SCAN_QUEUE_BACKUP_FILEPATH DRM_PATH L"scan._b"

#define DRM_MAX_XML_SIZE (3*1024)

typedef enum
{
    DRM_STATUS_NO_RIGHTS,
    DRM_STATUS_RIGHTS_PRESENT,
    DRM_STATUS_RIGHTS_IN_FUTURE,
    DRM_STATUS_RIGHTS_PENDING,
    DRM_STATUS_UNTRUSTED_TIME,
    DRM_STATUS_CONTENT_PENDING,
    DRM_STATUS_RIGHTS_TRIAL_ONLY,
    DRM_STATUS_NOT_PROTECTED
} drm_rights_status_enum;

#ifdef __DRM_SUPPORT_SD_CALLBACK__
typedef enum
{
    DRM_SD_EXPIRY_TIMEOUT = 0,
    DRM_SD_EXPIRY_RIGHTS_ARRIVE,
    DRM_SD_EXPIRY_RECORD_REPLACE,
    DRM_SD_EXPIRY_ERROR    
} drm_sd_expiry_type_enum;
#endif /* __DRM_SUPPORT_SD_CALLBACK__ */ 

typedef enum
{
    DRM_DB_GET_VALID    = 0x00,
    DRM_DB_GET_INVALID  = 0x01,
    DRM_DB_GET_ALL    = 0x02
}drm_proc_db_ro_count_flag_enum;


typedef struct
{
    kal_int32 id_len;
    kal_char id[DRM_MAX_ID_LENGTH];
} drm_cid_struct;

#define DRM_MSG_BINARY_ENCODING (0)
#define DRM_MSG_BASE64_ENCODING (1)

typedef struct
{
    drm_cid_struct cid;
    kal_int32 plaintext_offset;
    kal_int32 plaintext_len;
    applib_mime_type_struct *mime_type;
    kal_uint8 encoding;
} drm_message_info_struct;

typedef struct
{
    kal_int64 used_count;
    kal_int64 total_count;
    kal_int32 status;
    kal_int32 start_time;
    kal_int32 end_time;
    kal_int32 interval;
    kal_int32 start_intv;
    kal_int32 end_intv;
#ifdef __DRM_V02__
    kal_int32 timed_count;
    kal_int32 total_timed_count;
    kal_uint32 period;
    kal_int32 accum_dur;
    kal_int32 total_accum_dur;
    kal_int32 is_individual;
    kal_uint32 sys_num;
#endif /* __DRM_V02__ */ 
    kal_uint8 type;
} drm_constraint_struct;

#ifdef __DRM_SUPPORT_SD_CALLBACK__
typedef kal_bool (*drm_sd_callback) (void *para, kal_uint8 type);

typedef struct
{
    applib_time_struct timer;
    kal_int32 src_mod;
    kal_int32 timestamp;
    kal_char *cid;
    void *para;
    drm_sd_callback callback;
    void *timer_id;
} drm_sd_callback_struct;
#endif /* __DRM_SUPPORT_SD_CALLBACK__ */ 

typedef void (*drm_general_callback) (kal_uint8 serial, kal_int32 result);

typedef void (*drm_install_object_callback) (kal_uint8 serial, kal_int32 result, applib_mime_type_struct *mime_type);

typedef void (*drm_parse_dm_callback) (kal_uint8 serial, kal_int32 result, drm_message_info_struct *info);

typedef void (*drm_ro_expiry_callback) (kal_int32 result, kal_int32 id);

typedef enum
{
    DRM_PROCESS_DATABASE_SWEEP,
    DRM_PROCESS_DATABASE_DELETE_SINGLE_FROM_VALID,
    DRM_PROCESS_DATABASE_DELETE_SINGLE_FROM_ALL,
    DRM_PROCESS_DATABASE_BACKUP,
    DRM_PROCESS_DATABASE_RESTORE,
    DRM_PROCESS_DATABASE_DELETE_ALL,
    DRM_PROCESS_DATABASE_MAX
} drm_process_database_enum;

typedef enum
{
    DRM_SCAN_DISK,
    DRM_SCAN_SINGLE_FILE,
    DRM_SCAN_SINGLE_CID
} drm_scan_disk_enum;


#endif /* __DRM_SUPPORT__ */ 
#endif /* DRM_DEF_H */ 

