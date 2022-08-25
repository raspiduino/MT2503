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
 * vBookmark.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for sending and receving vbookmark object.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_VBOOKMARK_H
#define _MMI_VBOOKMARK_H

#include "MMI_features.h"
#if defined(__MMI_VBOOKMARK__)

/* if some header should be include before this one */
#include "fs_type.h"
#include "vObjects.h"

/* 
 * Typedef 
 */
typedef enum
{
    VBKM_RECV_VIA_SMS,
    VBKM_RECV_VIA_BT,
    VBKM_RECV_VIA_IRDA
} vbkm_recv_medium_type_enum;

/* 
 * Define
 */
#define VBKM_VERSION_1_0			"1.0"
#define VBKM_VERSION				VBKM_VERSION_1_0
#define VBKM_CHAR_SET				"UTF-8"
#define VBKM_ENCODING				"QUOTED-PRINTABLE"

#define VBKM_MAX_FILENAME_LENGTH	VOBJ_MAX_FILENAME_LENGTH/ENCODING_LENGTH
#define VBKM_MAX_PATH_LENGTH		VOBJ_MAX_PATH_LENGTH/ENCODING_LENGTH
#define VBKM_MAX_FILE_EXT_LEN		VOBJ_MAX_FILE_EXT_LEN/ENCODING_LENGTH
#define VBKM_MAX_URL_LENGTH			255
#define VBKM_WRITER_FIELD_BUFFER	1024
#define VBKM_READER_FIELD_BUFFER	1024
#define VBKM_DEFAULT_FILE_EXTN		L"url"
#define VBKM_UTF8_ENCODING_LENGTH	3

#define  VBKM_COLON_SEP				":"
#define  VBKM_SEMI_COLON_SEP		";"
#define  VBKM_EQUALITY_SEP			"="
#define  VBKM_LINE_BREAK			"\r\n"

#define  VBKM_TEMP_FILE_NAME		L"temp"

#define VBKM_RECVD_COUNT_MAX  5
/* 
 * Extern Global Variable
 */
typedef struct
{
	U8 file_path[(VBKM_MAX_PATH_LENGTH+1) * ENCODING_LENGTH];
}vbkm_context_struct;

typedef struct
{
	U8 file_name[(VBKM_MAX_FILENAME_LENGTH) * ENCODING_LENGTH];
	U8 file_extn[(VBKM_MAX_FILE_EXT_LEN) * ENCODING_LENGTH];
}vbkm_recv_file_info_struct;

//struct tag_vbkm_recv_file_info_list_struct;

struct node
{
	vbkm_recv_file_info_struct file_info;
	struct node *nextNode;
};

typedef struct node vbkm_recv_file_info_list_struct;

extern void mmi_vbkm_fmgr_sms_forward(S8 *path);
#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
extern mmi_ret mmi_vbkm_fmgr_sms_forward_proc(mmi_event_struct *evt);
#endif

#ifdef __MMI_BRW_BOOKMARK_IN_FMGR__
#if defined(__MMI_FILE_MANAGER__)
extern void mmi_vbkm_recv_file_save_to_fmgr_highlight_hdlr(void);
extern void mmi_vbkm_recv_file_save_to_fmgr(void);
#endif /* defined(__MMI_FILE_MANAGER__) */
#endif /* __MMI_BRW_BOOKMARK_IN_FMGR__ */
extern void mmi_vbkm_recv_file_view_highlight_hdlr(void);
extern void mmi_vbkm_recv_file_save_to_bookmark_highlight_hdlr(void);
extern void mmi_vbkm_recv_file_view(void);
extern void mmi_vbkm_recv_file_save_to_bookmark(void);
extern void mmi_vbkm_recv_file_pre_entry_options(void);
extern void mmi_vbkm_recv_file_entry_options(void);
extern void mmi_vbkm_recv_file_save_to_fmgr_callback(void *fullname, int is_short);
extern void mmi_vbkm_recv_file_view_copy_rsp(void *info);

/* 
 * Other Function
 */
extern void mmi_vbkm_init(void);
extern void mmi_vbkm_deinit(void);
extern void mmi_vbkm_clean_one_file_buffer(void);
extern MMI_BOOL mmi_vbkm_space_available(void);
extern void mmi_vbkm_display_error_message(void);


/*Imported APTs*/
extern void mmi_brw_bookmarks_recv_file_save_to_fmgr(U8* file_path, U8* file_name, U8* file_extn);
extern void mmi_brw_bookmarks_recv_file_view(U8* file_path, U8* file_name);
extern void mmi_brw_bookmarks_recv_file_save_to_bookmark(U8* file_path, U8* file_name, U8* file_extn);
/*Imported APTs*/

#endif /* defined(__MMI_VBOOKMARK__) */ /* END #if defined(__MMI_VBOOKMARK__) */
#endif /* _MMI_VBOOKMARK_H */

