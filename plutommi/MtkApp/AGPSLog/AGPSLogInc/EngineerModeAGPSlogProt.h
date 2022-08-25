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
 *  EngineerModeAGPSlogProt.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Private prototype definitions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef ENGINEER_MODE_AGPSLOG_PROT_H
#define ENGINEER_MODE_AGPSLOG_PROT_H

/* Be sure to update this value if log file structure changed
   (add new log type or new field) */
#define EM_AGPSLOG_VERSION (0x0)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMI_features.h"

#ifdef __AGPS_LOG_SUPPORT__

#ifndef __EM_AGPSLOG_DEBUG_ON_VC__
#include "app_datetime.h"
#else /* __EM_AGPSLOG_DEBUG_ON_VC__ */
#include "Adaptation.h"
#endif /* __EM_AGPSLOG_DEBUG_ON_VC__ */

#include "EngineerModeAGPSlogGprot.h"
#include "kal_general_types.h"
#include "fs_type.h"


/*****************************************************************************
 * Constant Definition
 *****************************************************************************/

#define EM_AGPSLOG_DEFAULT_HOME_DIR             L"AGPSlog\\"
#define EM_AGPSLOG_DEFAULT_LOG_DIRNAME          L"log\\"
#define EM_AGPSLOG_DEFAULT_TEMPLATE_DIRNAME     L"template\\"
#define EM_AGPSLOG_DEFAULT_EXPORT_DIRNAME       L"export\\"
#define EM_AGPSLOG_DEFAULT_TEMPLATE_FILENAME    L"DefaultTemplate.txt"

#define EM_AGPSLOG_MAX_FILENAME_LENGTH     40
#define EM_AGPSLOG_MAX_DIR_PATH_LENGTH     (2 + 40)
#define EM_AGPSLOG_MAX_PATH_LENGTH         (EM_AGPSLOG_MAX_DIR_PATH_LENGTH + EM_AGPSLOG_MAX_FILENAME_LENGTH)

#define EM_AGPSLOG_TEXT_BUFFER_SIZE        512  /* Do NOT larger than 1024! */
#define EM_AGPSLOG_MAX_LINE_BUFFER         256
#define EM_AGPSLOG_MAX_LOG_SIZE            40   /* max size of each raw log data in kal_char */
#define EM_AGPSLOG_MAX_TEMPLATE_BUFFER     1024 /* The buffer size to store parsed template data */
#define EM_AGPSLOG_LOG_BUFFER_SIZE         512  /* The buffer size for caching log written */

/* Make sure lengths of formatted token are all less than this value */
#define EM_AGPSLOG_MAX_FORMATTED_TOKEN_LENGTH 32

#define EM_AGPSLOG_LOG_FILE_MAGIC_PATTERN { 'A', 'G', 'P', 'S', 'l', 'o', 'g', '\0' }
#define EM_AGPSLOG_LOG_FILE_MAGIC_PATTERN_LENGTH 8

/*****************************************************************************
 * Typedef
 *****************************************************************************/

#define EM_AGPSLOG_CONFIG_INITED_MAGIC 0x0abcd123

typedef struct {
    kal_uint32 inited_magic; /* if set to CONFIG_INITED_MAGIC, all configs & dirs are ready */
    WCHAR home_dir[2 + EM_AGPSLOG_MAX_FILENAME_LENGTH];
    WCHAR log_dir[EM_AGPSLOG_MAX_DIR_PATH_LENGTH];
    WCHAR template_dir[EM_AGPSLOG_MAX_DIR_PATH_LENGTH];
    WCHAR export_dir[EM_AGPSLOG_MAX_DIR_PATH_LENGTH];
} em_agpslog_config_struct;


typedef struct
{
    kal_uint32 session_id;
    kal_uint8* buffer;
    kal_uint16 size;
    kal_uint16 tail_index;
    FS_HANDLE log_file;
/* // For ring buffer
    kal_uint16 front;
    kal_uint16 rear;
    kal_uint16 discarded_count;
*/
} em_agpslog_log_buffer_struct;


/* For read line helper */
typedef struct
{
    FS_HANDLE handler;
    kal_char* buffer; /* Rewind buffer */
    kal_uint16 buffer_tail;
    kal_uint16 size;
    kal_bool eof;
} em_agpslog_file_struct;


/* To record parse result */
typedef struct
{
    kal_bool full;
    kal_uint16 warning_count;
    kal_char *log;        /* log buffer */
    kal_char *log_tail;
    kal_char *log_end;
} em_agpslog_parse_log_struct;

/* ------------------------------ For log storage -----------------------------*/

typedef struct
{
    kal_uint16 addr_len;
    kal_uint16 port;
    kal_uint8 ip[16];
} em_agpslog_network_address_struct;

typedef struct
{
    float longitude;
    float latitude;
    float altitude;
    float velocity;
    float direction;
    applib_time_struct time;
} em_agpslog_position_result_struct;

/* --------------------------------- For UI ------------------------------------*/

/* Template management */
typedef struct {
    kal_uint32 inited_magic;
    kal_bool is_parsed;
    /* parsing cache: cache the template parsing result */
    kal_uint8 *buffer_p;
    kal_uint8 *buffer_end; /* the end point of buffer */
    kal_uint8* of_type[EM_AGPSLOG_TYPE_TOTAL];
} em_agpslog_template_struct;

extern void em_agpslog_template_init(em_agpslog_template_struct *t);
extern kal_bool em_agpslog_template_reset(
     em_agpslog_template_struct *t,
     FS_HANDLE f_hdlr,
     em_agpslog_parse_log_struct *parse_log);
/* Be sure to call this function before exit if set_template */
extern void em_agpslog_template_deinit(em_agpslog_template_struct *t);

extern void em_agpslog_template_format_file(
    kal_char *dest,
    const kal_uint32 dest_length_max,
    const em_agpslog_template_struct *log_template,
    FS_HANDLE raw_file,
    kal_bool (*dest_full_callback)(void *args, kal_char *dest, const kal_uint32 length),
    void *args);


typedef enum
{
    EM_AGPSLOG_LOG_FILE_STATUS_GOOD,
    EM_AGPSLOG_LOG_FILE_STATUS_INVALID_FILE,
    EM_AGPSLOG_LOG_FILE_STATUS_INVALID_HEADER,
    EM_AGPSLOG_LOG_FILE_STATUS_UNSUPPORTED_VERSION,
    /* --------------------------------------------- */
    EM_AGPSLOG_LOG_FILE_STATUS_END_OF_ENUM
} em_agpslog_log_file_status_enum;

extern em_agpslog_log_file_status_enum em_agpslog_read_log_file_header(
    FS_HANDLE f_hdlr,
    kal_uint16* version);

/* ----------------------------- Service Core ------------------------------ */

#if 0 /* Rung buffer */
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
#endif

extern kal_bool em_agpslog_init_directories(void);
extern void em_agpslog_set_enabled(const kal_bool enabled);
extern kal_bool em_agpslog_get_enabled(void);

/* Flush buffer content to log_buffer_p->log_file */
extern void em_agpslog_flush_buffer(em_agpslog_log_buffer_struct* log_buffer_p);

extern void em_agpslog_write(
    em_agpslog_log_buffer_struct *log_buffer_p,
    em_agpslog_type_enum log_type,
    const kal_uint8 *data,
    kal_uint32 length);

/* ------------------------------- String table ------------------------------ */

extern const kal_char* em_agpslog_get_proc_name_string(em_agpslog_procedure_enum proc);
extern const kal_char* em_agpslog_get_direction_string(em_agpslog_direction_enum dir);
extern const kal_char* em_agpslog_get_gps_conn_status_string(em_agpslog_gps_conn_status_enum status);
extern const kal_char* em_agpslog_get_gps_start_type_string(em_agpslog_gps_start_type_enum s_type);
extern const kal_char* em_agpslog_get_supl_pos_mth_string(em_agpslog_supl_position_method_enum pos_mth);
extern const kal_char* em_agpslog_get_supl_session_type_string(em_agpslog_supl_session_type_enum s_type);
extern const kal_char* em_agpslog_get_supl_message_type_string(em_agpslog_supl_message_type_enum msg);
extern const kal_char* em_agpslog_get_supl_status_string(em_agpslog_supl_status_enum status);
extern const kal_char* em_agpslog_get_rrlp_message_type_string(em_agpslog_rrlp_message_type_enum msg);

/* --------------------------------- Utility --------------------------------- */

extern kal_bool em_agpslog_string_begins(
    const kal_char *str,
    const kal_char *pattern,
    const kal_char **next);
extern void em_agpslog_format_ip_addr(
    kal_char *ip_str,
    const em_agpslog_network_address_struct *addr);
extern void em_agpslog_format_time(kal_char* time_str, kal_uint8 hour, kal_uint8 min, kal_uint8 sec);
extern kal_bool em_agpslog_file_read_line(
    em_agpslog_file_struct* file_p,
    kal_char *line,
    kal_uint32 line_max,
    kal_bool *complete_line);
extern void em_agpslog_file_struct_init(em_agpslog_file_struct* file, FS_HANDLE f_hdlr);
extern void em_agpslog_file_struct_deinit(em_agpslog_file_struct* file);
extern kal_uint32 em_agpslog_strlen(const kal_char *str);
extern kal_char* em_agpslog_strcpy(kal_char *dest, const kal_char *src);
extern kal_char* em_agpslog_itoa(
    kal_char* str,
    const kal_uint32 val,
    const kal_uint32 n_digits);
extern kal_char* em_agpslog_format_float(kal_char* str, const float val);

#endif /* __AGPS_LOG_SUPPORT__ */

#endif /* ENGINEER_MODE_AGPSLOG_PROT_H */
