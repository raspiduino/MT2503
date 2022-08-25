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
 * vCalendar.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_VCALENDAR_H
#define _MMI_VCALENDAR_H

#include "MMI_features.h"

#if defined(__MMI_VCALENDAR__)

#include "kal_general_types.h"
#include "custom_mmi_default_value.h"
#include "mmi_res_range_def.h"
#include "MMIDataType.h"
#include "Conversions.h"
#include "FileMgrSrvGProt.h"
#include "Vcalsrvgprot.h"

/* if some header should be include before this one */

/******************************************************************************* 
 * Define 
 *******************************************************************************/
#define MMI_VCALNDR_TIME_FMT_UTC      (0)
#define MMI_VCALNDR_TIME_FMT_RTC      (1)
#define MMI_VCALNDR_TIME_FMT_RTC_TZ   (2)

#define MMI_VCAL_DRV                 SRV_FMGR_PUBLIC_DRV
#if 0
#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
#else
/* under construction !*/
#endif
#else
#define MMI_VCAL_FILE_PATH           "Received"
#endif//if 0
#define MMI_VCAL_FILE_EXT            "vcs"
#define MMI_VCAL_DEFAULT_FILE_NAME   "~~vcalendar.vcs"
#define MMI_VCAL_SEP_STR             ":"
#define MMI_VCAL_CRLF_STR            "\r\n"
#define MMI_VCAL_READ_BUFF_LEN       (512)
#define MMI_VCAL_WRITE_BUFF_LEN      (1024)
#define MMI_VCAL_NULL                '\0'
#define MMI_VCAL_SRC_PORT            0x0000 /* For sending SMS */
#define MMI_VCAL_VCLNDR_PORT         0x23f5


/******************************************************************************* 
 * Typedef 
 *******************************************************************************/
 
/* Callback handler for IMPS */
typedef void(* mmi_tdl_send_vcal_callback_type)(CHAR* file_path); /* Callback handler */

typedef enum
{
    MMI_VCAL_TYPE_BUFF,
    MMI_VCAL_TYPE_FILE_PATH,
    MMI_VCAL_TYPE_END_OF_ENUM
}mmi_vcal_param_type_enum;

typedef enum
{
    MMI_VCAL_SEND_BY_SMS,
    MMI_VCAL_SEND_BY_MMS,
    MMI_VCAL_SEND_BY_EMAIL,
    MMI_VCAL_SEND_BY_OPP,
    MMI_VCAL_SEND_BY_END_OF_ENUM
}mmi_vcal_send_by_enum;

typedef enum
{
    MMI_VCAL_CH_UTF8,
    MMI_VCAL_CH_BIG5,
    MMI_VCAL_CH_UTF7,
    MMI_VCAL_CH_TOTAL
} mmi_vcal_charset_type_enum;

typedef enum
{
    MMI_VCAL_PARA_LANGUAGE,               /* Not used */
    MMI_VCAL_PARA_CHARSET,                /* Charset for parsing */
    MMI_VCAL_PARA_ENCODING,               /* Encoding for parsing */
    MMI_VCAL_PARA_TOTAL
} mmi_vcal_desc_para_type_enum;

typedef enum
{
    MMI_VCAL_EN_7BIT = 0,                 /* 7-bit encoding */
    MMI_VCAL_EN_8BIT,                     /* 8-bit encoding */
    MMI_VCAL_EN_QP,                       /* Quoted-Printable */
    MMI_VCAL_EN_BASE64,                   /* Base64 */
    MMI_VCAL_EN_OTHERS,                   /* X-xxxx */
    MMI_VCAL_EN_TOTAL
} mmi_vcal_ecoding_type_enum;

/* vCalendar global context */
typedef struct
{
    WCHAR *path;            /* File path to store the received vcalendar */
    WCHAR *name;            /* File name to store the received vcalendar */
    U8 SrcType;                 /* Receive type, from todo, imps or network */
	CHAR time_fmt_flag;           /* 0 = UTC, 1 = Local Time, 2 = Local Time + TZ */
    mmi_chset_enum vcalendar_encoding;  /* Encoding charset */
    mmi_tdl_send_vcal_callback_type send_vclndr_cb;    /* IMPS callback handler */
} mmi_vcal_context_struct;

typedef struct
{
    srv_vcal_type_enum vcal_type;
    srv_tdl_event_struct event;
    srv_tdl_task_struct task;
}mmi_vcal_obj_struct;

typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
} cui_vcal_result_struct;

typedef enum
{
    EVT_ID_CUI_VCAL_SUCCESS = VCALENDAR_BASE,
    EVT_ID_CUI_VCAL_FAIL_NOT_ENOUGH_MEMORY,
    EVT_ID_CUI_VCAL_FAIL_FULL,
    EVT_ID_CUI_VCAL_FAIL,
    EVT_ID_CUI_VCAL_USER_CANCEL,
    EVT_ID_CUI_VCAL_NOT_SUPPORT,
    /* Total events for vCalendar CUI */
    EVT_ID_CUI_VCAL_END_OF_ENUM
} cui_vcal_event_enum;

typedef struct
{
    srv_vcal_type_enum vcal_type;
    void *buff;
}cui_vcal_save_to_file_obj_struct;

typedef struct
{
    mmi_vcal_param_type_enum para_type;
    union
    {
        WCHAR *path;
        cui_vcal_save_to_file_obj_struct obj;
    }u;
}cui_vcal_save_to_file_param_struct;

typedef struct
{
    mmi_vcal_send_by_enum send_type;
    srv_vcal_type_enum vcal_type;
    void *buff;
}cui_vcal_send_param_struct;

typedef struct
{
    mmi_id parent_id;
    mmi_id group_id;
    mmi_id child_id;
    mmi_id filename_gid;
    mmi_vcal_param_type_enum param_type;
    cui_vcal_event_enum evt_id;
    mmi_vcal_obj_struct obj;
    WCHAR *selected_path;
    WCHAR *file_name_buf;
    WCHAR *src_path;
} cui_vcal_save_to_file_cntx_struct;


typedef struct
{
    mmi_id parent_id;
    mmi_id group_id;
    mmi_id child_id;
    cui_vcal_result_struct event;
    WCHAR *path;
} cui_vcal_save_to_tdl_cntx_struct;

typedef struct
{
    mmi_id parent_id;
    mmi_id group_id;
    mmi_id menu_child_id;
    mmi_id save_child_id;
    WCHAR *path;
} cui_vcal_recv_cntx_struct;

typedef struct
{
    mmi_id parent_id;
    mmi_id group_id;
    mmi_id child_id;
    mmi_vcal_send_by_enum send_type;
    mmi_vcal_obj_struct obj;
    cui_vcal_result_struct event;
    WCHAR *src_path;
} cui_vcal_send_cntx_struct;

typedef struct
{
    U8 Days;
    U8 Repeat;
} vcal_recurr_struct;

typedef enum
{
    VCAL_BEGIN,
    VCAL_VERSION,
    VCAL_VEVENT_BEGIN,
    VCAL_VTODO_BEGIN,
    VCAL_DTSTART,
    VCAL_DTEND,
    VCAL_DUE,
    VCAL_TZID,
    VCAL_SUMMARY,
    VCAL_DESCRIPTION,
    VCAL_RRULE,
    VCAL_DALARM,
    VCAL_AALARM,
    VCAL_VTODO_END,
    VCAL_VEVENT_END,
    VCAL_END,
    VCAL_CLASS,
    VCAL_LOCATION,
    VCAL_PRIORITY,
    VCAL_COMPLETED,
    VCAL_LAST_MODIFIED,
    VCAL_CATEGORY,
    VCAL_STATUS,
    VCAL_UID,
    VCAL_X_EXTENSION,
    VCAL_PRODID,
    VCAL_SEQUENCE,
    VCAL_TOTAL_FILEDS
} vcal_filed_type;

typedef enum
{
    VCLNDR_SAVE_FROM_RECV,
    VCLNDR_SAVE_FROM_TDL,
    VCLNDR_SAVE_FROM_APP
} vclndr_src_type;

typedef enum
{
    VCAL_DAILY,
    VCAL_WEEKLY,
    VCAL_MONTHLY,
    VCAL_YEARLY,
    VCAL_RECURR_TOTAL
} vcal_recurr_type;


/******************************************************************************* 
 * Extern Global Variable
 *******************************************************************************/
extern const CHAR *const g_vcal_fileds[];
extern mmi_vcal_context_struct g_vcal_cntx;
extern U32 g_vclndr_fmgr_service_id;

/******************************************************************************* 
 * Extern Global Function
 *******************************************************************************/
 
 
/*****************************************************************************
 * FUNCTION
 *  mmi_vcal_free_buffer
 * DESCRIPTION
 *  Release all dynamic allocated memory used in vCalendar.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_vcal_free_buffer(void);

#if 0
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif




#if defined(__MMI_FILE_MANAGER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_vcal_can_recv
 * DESCRIPTION
 *  Receive vCalendar object from file manager.
 * PARAMETERS
 *  file_path_name : [IN]Filename and path of selected file.
 * RETURNS
 *  void
 * RETURN VALUES
 *  TRUE : Can receive
 *  FALSE : Cannot receive
 *****************************************************************************/
extern MMI_BOOL mmi_vcal_can_recv(CHAR *file_path_name);

/*****************************************************************************
 * FUNCTION
 *  mmi_vcal_fmgr_recv
 * DESCRIPTION
 *  Receive vCalendar object from file manager.
 * PARAMETERS
 *  file_path_name : [IN]Filename and path of selected file.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_vcal_fmgr_recv(CHAR *file_path_name);


/*****************************************************************************
 * FUNCTION
 *  mmi_vcal_fmgr_sms_forward
 * DESCRIPTION
 *  Forward a vCalendar object from file manager via SMS
 * PARAMETERS
 *  path : [IN]Path of the vCalendar
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_vcal_fmgr_sms_forward(CHAR *path);


/*****************************************************************************
 * FUNCTION
 *  mmi_vcal_fmgr_use_enabler
 * DESCRIPTION
 *  Forward a vCalendar object from file manager via SMS
 * PARAMETERS
 *  path        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_vcal_fmgr_use_enabler(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo);


/*****************************************************************************
 * FUNCTION
 *  mmi_vcal_fmgr_use_handler
 * DESCRIPTION
 *  Forward a vCalendar object from file manager via SMS
 * PARAMETERS
 *  path        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_vcal_fmgr_use_handler(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo);

#endif /* __MMI_FILE_MANAGER__ */



/*****************************************************************************
 * FUNCTION
 *  mmi_vcal_get_default_filename
 * DESCRIPTION
 *  To generate default file name used for other application
 * PARAMETERS
 *  result : [IN/OUT]Pointer to the result
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_vcal_get_default_filename(WCHAR *result);




#ifndef __MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__
extern void mmi_vcal_sms_forward(cui_vcal_send_cntx_struct *cntx);
#endif /* !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__) */ 

/*****************************************************************************
 * FUNCTION
 *  cui_vcal_save_to_file_create
 * DESCRIPTION
 *  Create send vCalendar CUI.
 * PARAMETERS
 *  mmi_id : [IN] parent_id, parent group ID to add current group to.
 * RETURNS
 *  mmi_id
 *****************************************************************************/
extern mmi_id cui_vcal_save_to_file_create(mmi_id parent_id);


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_save_to_file_set_para
 * DESCRIPTION
 *  Set the type
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * type : [IN] type of the param for the CUI to send
 *        MMI_VCAL_TYPE_BUFF, give a buffer stored an event or to-do.
 *        MMI_VCAL_TYPE_FILE_PATH, give a file path stores the vcs file.
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
extern void cui_vcal_save_to_file_set_para(mmi_id sg_id, cui_vcal_save_to_file_param_struct para);


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_save_to_file_run
 * DESCRIPTION
 *  Run send CUI.
 * PARAMETERS
 *  mmi_id : [IN] sg_id, group ID to add current group to.
 * RETURNS
 *  mmi_id
 *****************************************************************************/
extern void cui_vcal_save_to_file_run(mmi_id sg_id);


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_save_to_file_close
 * DESCRIPTION
 *  Close send CUI.
 * PARAMETERS
 *  mmi_id : [IN] sg_id, group ID to add current group to.
 * RETURNS
 *  mmi_id
 *****************************************************************************/
extern void cui_vcal_save_to_file_close(mmi_id sg_id);


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_send_close
 * DESCRIPTION
 *  Close send CUI.
 * PARAMETERS
 *  mmi_id : [IN] sg_id, group ID to add current group to.
 * RETURNS
 *  mmi_id
 *****************************************************************************/
extern void cui_vcal_send_close(mmi_id sg_id);


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_recv_create
 * DESCRIPTION
 *  Create save vCalendar CUI.
 * PARAMETERS
 *  mmi_id : [IN] parent_id, parent group ID to add current group to.
 * RETURNS
 *  mmi_id
 *****************************************************************************/
extern mmi_id cui_vcal_recv_create(mmi_id parent_id);


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_recv_set_path
 * DESCRIPTION
 *  Set the file path for MMI_VCAL_FILE_PATH.
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * path : [IN] file path stores the vcs file.
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
extern void cui_vcal_recv_set_path(mmi_id sg_id, U16 *path);


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_recv_run
 * DESCRIPTION
 *  Run send CUI.
 * PARAMETERS
 *  mmi_id : [IN] sg_id, group ID to add current group to.
 * RETURNS
 *  mmi_id
 *****************************************************************************/
extern void cui_vcal_recv_run(mmi_id sg_id);


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_recv_close
 * DESCRIPTION
 *  Close save vCalendar CUI.
 * PARAMETERS
 *  mmi_id : [IN] parent_id, parent group ID to add current group to.
 * RETURNS
 *  mmi_id
 *****************************************************************************/
extern void cui_vcal_recv_close(mmi_id parent_id);


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_save_to_tdl_create
 * DESCRIPTION
 *  Create save vCalendar CUI.
 * PARAMETERS
 *  mmi_id : [IN] parent_id, parent group ID to add current group to.
 * RETURNS
 *  mmi_id
 *****************************************************************************/
extern mmi_id cui_vcal_save_to_tdl_create(mmi_id parent_id);


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_save_to_tdl_set_path
 * DESCRIPTION
 *  Set the file path for MMI_VCAL_FILE_PATH.
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * path : [IN] file path stores the vcs file.
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
extern void cui_vcal_save_to_tdl_set_path(mmi_id sg_id, WCHAR *path);


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_save_to_tdl_run
 * DESCRIPTION
 *  Run send CUI.
 * PARAMETERS
 *  mmi_id : [IN] sg_id, group ID to add current group to.
 * RETURNS
 *  mmi_id
 *****************************************************************************/
extern void cui_vcal_save_to_tdl_run(mmi_id sg_id);


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_save_to_tdl_close
 * DESCRIPTION
 *  Close save vCalendar CUI.
 * PARAMETERS
 *  mmi_id : [IN] parent_id, parent group ID to add current group to.
 * RETURNS
 *  mmi_id
 *****************************************************************************/
extern void cui_vcal_save_to_tdl_close(mmi_id parent_id);


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_send_create
 * DESCRIPTION
 *  Create send vCalendar CUI.
 * PARAMETERS
 *  mmi_id : [IN] parent_id, parent group ID to add current group to.
 * RETURNS
 *  mmi_id
 *****************************************************************************/
extern mmi_id cui_vcal_send_create(mmi_id parent_id);


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_send_set_para
 * DESCRIPTION
 *  Set the type
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * type : [IN] type of the param for the CUI to send
 *        MMI_VCAL_TYPE_BUFF, give a buffer stored an event or to-do.
 *        MMI_VCAL_FILE_PATH, give a file path stores the vcs file.
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
extern void cui_vcal_send_set_para(mmi_id sg_id, cui_vcal_send_param_struct para);


/*****************************************************************************
 * FUNCTION
 *  cui_vcal_send_run
 * DESCRIPTION
 *  Run send CUI.
 * PARAMETERS
 *  mmi_id : [IN] sg_id, group ID to add current group to.
 * RETURNS
 *  mmi_id
 *****************************************************************************/
extern void cui_vcal_send_run(mmi_id sg_id);
#endif /* defined(__MMI_VCALENDAR__) */

#endif /* _MMI_VCALENDAR_H */ /* END #ifndef _MMI_VCALENDAR_H */

