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
 *  UDXProt.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intended for UDX Agent internal interface.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _UDX_PROT_H
#define _UDX_PROT_H

#include "mmi_features.h"

#ifdef __MMI_UDX_SUPPORT__

#include "MMIDataType.h"

#include "mmi2udx_struct.h"
#include "Filemgrsrvgprot.h"
#include "UDXGprot.h"
#include "mmi_frm_scenario_gprot.h"

#define MMI_UDX_DRV              SRV_FMGR_PUBLIC_DRV
#define MMI_UDX_MAX_TEMP_FILE    2         /* Maximum 254 */
#define MMI_UDX_FILE_PATH           "Received"
#define MMI_UDX_FILE_EXT         ".udx"
#define MMI_UDX_TMP_FILE_NAME       "tmp"
#define MMI_UDX_MAX_PATH_LENGTH     SRV_FMGR_PATH_MAX_LEN
#define MMI_UDX_MAX_FILE_EXT_LEN    SRV_FMGR_PATH_MAX_FILE_EXT_LEN
#define MMI_UDX_MAX_FILENAME_LENGTH SRV_FMGR_PATH_MAX_FILE_BASENAME_LEN

#define MMI_UDX_TRACE_GROUP MMI_COMMON_TRC_G2_ORG

#define MMI_UDX_LOG(x)                                                             \
   {                                                                               \
      MMI_TRACE(MMI_UDX_TRACE_GROUP, x);                                           \
   }
#define MMI_UDX_LOG1(x, x1)                                                        \
   {                                                                               \
      MMI_TRACE(MMI_UDX_TRACE_GROUP, x, x1);                                       \
   }
#define MMI_UDX_LOG2(x, x1, x2)                                                    \
   {                                                                               \
      MMI_TRACE(MMI_UDX_TRACE_GROUP, x, x1, x2);                                   \
   }
#define MMI_UDX_LOG3(x, x1, x2, x3)                                                \
   {                                                                               \
      MMI_TRACE(MMI_UDX_TRACE_GROUP, x, x1, x2, x3);                               \
   }

#define MMI_UDX_AGENT_STATE_TRANS(x)                                               \
{                                                                                  \
    g_mmi_udx_cntx.udx_agent.state = (x);                                          \
}

/* UDX AGENT STATE */
typedef enum
{
    MMI_UDX_AGENT_STATE_INIT,

    /* builder state */
    MMI_UDX_BUILDER_HEADER_REQ,
    MMI_UDX_BUILDER_HEADER_RSP,

    MMI_UDX_BUILDER_DATA_REQ,
    MMI_UDX_BUILDER_DATA_RSP,

    MMI_UDX_BUILDER_ABORT_REQ,
    MMI_UDX_BUILDER_ABORT_RSP,

    MMI_UDX_BUILDER_END_REQ,
    MMI_UDX_BUILDER_END_RSP,

    /* parser state */
    MMI_UDX_PARSER_HEADER_REQ,
    MMI_UDX_PARSER_HEADER_RSP,

    MMI_UDX_PARSER_BODY_REQ,    /* parse header info again then start to parse data*/
    MMI_UDX_PARSER_BODY_RSP, 
    
    MMI_UDX_PARSER_ABORT_REQ,
    MMI_UDX_PARSER_ABORT_RSP,

    MMI_UDX_PARSER_END_IND,

    MMI_UDX_AGENT_STATE_TOTAL
} mmi_udx_builder_state_enum;

typedef enum
{
    MMI_UDX_BUILD_FROM_BUILDER = 1,
    MMI_UDX_BUILD_FROM_OTHER_APP,
    MMI_UDX_PARSE_FROM_FILEMGR,
    MMI_UDX_PARSE_FROM_PARSER,
    
    MMI_UDX_AGENT_FROM_SRC_TOTAL
} mmi_udx_from_src_enum;

typedef enum
{
    UDX_ERR_NO_ERROR,
    UDX_ERR_DISK_FULL,
    UDX_ERR_EMPTY_NAME,
    UDX_ERR_DUPLICATE_NAME,
    UDX_ERR_MEMORY_FULL,
    UDX_ERR_INVALID_FILENAME,
    UDX_ERR_SELECT_PATH_TOO_LONG,
    UDX_ERR_UNSUPPORT_FORMAT,
    UDX_ERR_PATH_NOT_FOUND,
    UDX_ERR_UNKNOWN,
    
    UDX_ERR_TYPE_TOTAL
} udx_file_err_enum;

typedef enum
{
    UDX_INFO_WARNING,
    UDX_INFO_ERROR,
    UDX_INFO_SUCCESS
} udx_show_info_enum;

typedef enum
{
    UDX_PARSE_PART_HEADER,
    UDX_PARSE_PART_BODY,
    UDX_PARSE_PART_TOTAL
} mmi_udx_parse_part_enum;

/* udx core api type struct */
typedef struct
{
    U8 data_type;
    mmi_udx_func_ptr_show_select_scr show_select_scr;
    mmi_udx_func_ptr_get_data get_data;
    mmi_udx_func_ptr_store_data store_data;
} mmi_udx_core_struct;

/* udx type info struct */
typedef struct
{
    U8 data_type;
    U16 data_type_string;
    U16 data_select_query_string;
    U16 img_id;
} mmi_udx_type_info_struct;

/* parse log view */
typedef struct
{
    U8 data_type;
    U8 lost_count;
    U16 parse_success_count;
    U16 store_success_count;        //store_fail_count = parse_success_count - store_success_count;
    MMI_BOOL storage_full;
} mmi_udx_parse_log_struct;

/* udx agent struct */
typedef struct
{
    U8 state;                       /* udx agent handling state */
    U8 error_code;                  /* udx agent handling error code */
    
    U8 type_selected;               /* udx builder type selected */
    U8 type_index;                  /* current handling type index */
    
    U16 sequence;                   /* current record index */
    U16 sequence_max;               /* max sequence valude */
    
    U16 vcard_num;                  /* vcard number to handle */
    U16 vcalendar_num;              /* vcalendar number to handle */
    U16 sms_num;                    /* sms number to handle */
    U16 mms_num;                    /* mms number to handle */
    U16 email_num;                  /* email number to handle */

    udx_header_info_struct header_info; /* udx file header info */

    U8 type_curr;                   /* udx data type to parse current, for pasing only */
    U8 type_old;                    /* udx data type for last parse, for pasing only */
    U8 conflict_solution;           /* conflict solution type, for pasing only */
    U8 parse_part;                  /* flag for parsing log, for pasing only */
    
    mmi_udx_parse_log_struct parse_log[MMI_UDX_TYPE_TOTAL]; /* pase log info, for parsing only */
    
    void* vcard_index_hdlr;         /* for building only */
    void* vcalendar_index_hdlr;
    void* sms_index_hdlr;
    void* mms_index_hdlr;
    void* email_index_hdlr;
    
}mmi_udx_agent_cntx_struct;

typedef struct
{
    mmi_udx_agent_cntx_struct udx_agent;

    mmi_id phb_list_gid;     /* reserved for phb list cui */
    mmi_id fmgr_gid;    
    mmi_id filename_gid;
    mmi_id parse_menu_gid;

    CHAR file_path[(MMI_UDX_MAX_PATH_LENGTH + 1) * ENCODING_LENGTH];
    CHAR file_name[(MMI_UDX_MAX_FILENAME_LENGTH + 1) * ENCODING_LENGTH];

    U8 data_type_array[MMI_UDX_TYPE_TOTAL + 1];     /* data type list array */
    U8 data_type_state[MMI_UDX_TYPE_TOTAL + 1];     /* for parser and builder */

    U8 buffer_begin;
    U8 buffer_end;
    
    U8 start_from;
    
    U16 info_str;
    S32 percentage;
    U8 info_type;
    
    U8 highlight_index;

    MMI_BOOL first_play_tone;
    MMI_BOOL cancel_by_end_key;
    MMI_BOOL parse_header_only;
    MMI_BOOL cancel_by_user;                        /* if cancel by other app, will not show any screen */
    MMI_BOOL phb_is_processing;
    
} mmi_udx_cntx_struct;

/* type define function ptr */
typedef void (*udx_func_ptr)(void);

/* Global var. */
extern mmi_udx_cntx_struct g_mmi_udx_cntx;
extern const mmi_udx_core_struct udx_support_type_func_tbl[];
extern const mmi_udx_type_info_struct udx_support_type_string_tbl[];
extern const U8 udx_support_type_tbl[];

/***************************************************************************** 
 * internal function
 *****************************************************************************/
/* UDXMain.c */
extern void mmi_udx_init_cntx(void);
extern void mmi_udx_builder_run(U8 builder_state);

extern void mmi_udx_paser_get_file_header_info(void);
extern void mmi_udx_parser_run(U8 parser_state);

extern void mmi_udx_builder_contact_select_cui_evt_hdlr(mmi_event_struct *param);
extern void mmi_udx_get_user_info(CHAR *user_info);
extern void mmi_udx_store_data_continue(MMI_BOOL storage_full, MMI_BOOL store_success);
extern void mmi_udx_send_msg(U32 msg_id, void *p_local_para);
extern U8 mmi_udx_get_data_type_index(U8 data_type);
extern U8 mmi_udx_get_data_use_way(void);
extern void mmi_udx_builder_app_list_cui_close(void);

    
/* UDXScr.c */
extern void mmi_udx_highlight_main_menu(void);
extern mmi_ret mmi_udx_group_main_proc(mmi_event_struct *param);
extern void mmi_udx_parser_entry_parse_option(void);
extern void mmi_udx_builder_save_as_file_err_hdlr(S32 result);
extern void mmi_udx_parser_entry_view_header_info(void);
extern void mmi_udx_builder_select_data_confirm(void);
extern void mmi_udx_parser_entry_data_type_select(void);

extern void mmi_udx_builder_select_data_record(void);
extern void mmi_udx_agent_delete_scr(void);
extern void mmi_udx_builder_entry_fmgr(void);
extern void mmi_udx_builder_data_type_select_fail(void);

#if defined(__MMI_OPP_SUPPORT__)
extern void mmi_udx_builder_entry_send_way(void);
#endif

extern void mmi_udx_insert_node(U16 scrn_id, udx_func_ptr func_ptr, mmi_scenario_node_flag flag);

extern void mmi_udx_show_processing(U16 str);
extern void mmi_udx_processing_abort(void);
extern void mmi_udx_update_processing_percentage(void);
extern void mmi_udx_entry_show_processing_percentage(void);
extern void mmi_udx_parser_header_del_scr(void);
extern void mmi_udx_parser_end_show_log(void);

/* UDXHdlr.c */
extern void mmi_udx_init_protocol(void);
extern void mmi_udx_builder_header_req(void);
extern void mmi_udx_builder_data_req(void* data_buffer, U16 sequence);
extern void mmi_udx_builder_end_req(void);
extern void mmi_udx_builder_abort_req(void);

extern void mmi_udx_parser_header_req(void);
extern void mmi_udx_parser_body_req(void);
extern void mmi_udx_parser_data_req(void);
extern void mmi_udx_parser_abort_req(void);

#endif /* __MMI_UDX_SUPPORT__ */
#endif /* _UDX_PROT_H */
