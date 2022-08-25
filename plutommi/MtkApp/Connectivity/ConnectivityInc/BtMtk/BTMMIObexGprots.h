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
 * BTMMIObex.h
 *
 * Project:
 * --------
 *   MMI
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
 *============================================================================
 ****************************************************************************/

#ifndef __BT_MMI_OBEX_GPROTS_H__
#define __BT_MMI_OBEX_GPROTS_H__

#include "MMI_features.h"

#ifdef __MMI_FTC_SUPPORT__
#include "BTMMIFtpGprots.h"
//#define MMI_OBEX_PROFILE_SHARE_BUF_SIZE (FTPC_MEM_BUFF_SIZE)
#endif

#ifdef __MMI_OPP_SUPPORT__
#include "BTMMISendGprots.h"
#endif
/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "kal_general_types.h"
/* RHR add end */
#ifdef __MMI_BT_SLIM__ 
#ifndef _MMI_BT_ULTRA_SLIM_ 
#define _MMI_BT_ULTRA_SLIM_ 
#endif 
#endif

#define MMI_BT_OBEX_DUP_FILENAME_MAX_NUM  200
#define MMI_BT_OBJ_NAME_LEN     42

#if defined(__MMI_FTS_SUPPORT__) || \
    defined(__MMI_FTC_SUPPORT__) || \
    defined(__MMI_OPP_SUPPORT__)
extern void mmi_bt_obex_event_hdlr_init(void);
#endif /* (__MMI_FTS_SUPPORT__) || (__MMI_FTC_SUPPORT__) || (__MMI_OPP_SUPPORT__) */

#ifdef __MMI_FTC_SUPPORT__
//extern U8 *mmi_bt_obex_get_profile_shared_buffer(void);
#endif /* __MMI_FTC_SUPPORT__ */

//#ifdef __MMI_BT_PROF_SETTING__
typedef enum {
    BTFF_ITEM_RECV_DRV,
    BTFF_ITEM_FTP_ACCESS,
    BTFF_ITEM_BIP_FLDR_PATH,
    BTFF_ITEM_BIP_FLDR_NAME,
    BTFF_ITEM_COUNT
} bt_ff_item_enum;

#ifdef __MMI_FTS_SUPPORT__
typedef enum
{
    FTP_PERMISSION_FULL_CONTROL,
    FTP_PERMISSION_READ_ONLY,
    FTP_PERMISSION_COUNT
} mmi_ftp_access_right_enum;
#endif

extern S32 mmi_bt_get_setting_int(U32 item);
extern S32 mmi_bt_get_setting_string(U32 item, U16 *buff, U32 size);
//#endif // __MMI_BT_PROF_SETTING__

#ifdef __MMI_BT_SUPPORT__
#define BTRECV_EV_START      0
#define BTRECV_EV_DONE       1

typedef enum {
    BTRECV_RET_MSDC_MISSED = -5,
    BTRECV_RET_MEMORY_FULL = -4, // Memory full
    BTRECV_RET_USER_ABORT = -3,
    BTRECV_RET_PENDING = -2,     // Async receiving start case   
    BTRECV_RET_FAIL = -1,		 // Fail
    BTRECV_RET_SUCC				 // Success
} btrecv_ret_enum;

typedef enum {
    BTRECV_OPT_BKGOUND = 0x01,	 // Background receiving, this option is future reserved.
    BTRECV_OPT_KEEP_NAME = 0x02, // Keep original name and avoid being truncated after stored.
    BTRECV_OPT_END
} btrecv_opt_enum;

typedef enum {
    BTRECV_INFO_STORAGE,
    BTRECV_INFO_OBJ_PATH,
    BTRECV_INFO_OBJ_FLDR,
    BTRECV_INFO_END
} btrecv_info_enum;

typedef void (*bt_recv_notify)(S32 hd, U32 event, S32 retval);

typedef struct {
    WCHAR *name; // object name
    S32 size;	 // object size, < 0 for unknown size case
    CHAR *mime;  // object type
    U8 type;
} bt_recv_obj_info;

typedef struct {
    WCHAR *folder;  // receive storage folder, like "Received\"
    CHAR drive;		// receive storage drive, like 'D'
} bt_recv_storage;

extern MMI_BOOL mmi_bt_is_receiving(void);
extern void mmi_bt_disable_receiving(void);
extern void mmi_bt_enable_receiving(void);
extern MMI_BOOL mmi_bt_receiving_disabled(void);
extern void mmi_bt_receive_init(void);
S32 mmi_bt_start_receive(
        bt_recv_notify notify,
        const bt_recv_obj_info *obj,
        const bt_recv_storage *storage,
        U8 option);
void mmi_bt_stop_receive(S32 hd, S32 retval);
S32 mmi_bt_get_receive_info(S32 hd, void *info, U8 opt);

#endif

//extern S32 mmi_bt_gen_folder(U16 *fldr_path,U8 Attributes);
extern void mmi_bt_common_init(void);
extern MMI_BOOL mmi_bt_storage_available(void);

#ifdef __MMI_OPP_SUPPORT__
/***************************************************************************** 
* Constant
*****************************************************************************/
/* Send data bearer */
typedef enum
{
    BTSEND_USE_BUFF,
    BTSEND_USE_FILE
} btsend_obj_enum;

/* Send profile selection */
typedef enum
{
    BTSEND_PROF_OPP = 0x01,
    BTSEND_PROF_FTP = 0x02,
    BTSEND_PROF_BIP = 0x04,
    BTSEND_PROF_ALL = 0xFF
} btsend_prof_enum;

/* Send option */
typedef enum
{
    BTSEND_OPT_NORMAL,
#ifdef __MMI_BT_DEF_SEND_DEVICE__
    BTSEND_OPT_DEFAULT_DEVICE,
#endif
    BTSEND_OPT_END
} btsend_opt_enum;

/* Send result code */
typedef enum
{
    BTSEND_RET_READY,
    BTSEND_RET_SUCCESS,
    BTSEND_RET_FAIL,
    BTSEND_RET_INVALID_PARA,
    BTSEND_RET_SERV_NOT_AVAILABLE,
    BTSEND_RET_DEVICE_BLOCKED,
    BTSEND_RET_BAD_OBJECT,
    BTSEND_RET_USER_ABORT,
    BTSEND_RET_TIMEOUT,
    BTSEND_RET_REJECT,
    BTSEND_RET_DISCONNECT,
    BTSEND_RET_FORBIDDEN,
    BTSEND_RET_UNSUPPORT_FILE_TYPE,
    BTSEND_RET_DONE
} btsend_ret_enum;

typedef enum {
	BTSEND_STATUS_READY,
	BTSEND_STATUS_SUCC,
	BTSEND_STATUS_FAIL,
	BTSEND_STATUS_DONE
} btsend_status_enum;

typedef void (*btsend_callback) (U32, void *);
typedef void (*btsend_notify)(U32 status, void *handle, void *user_data);

/***************************************************************************** 
* Structure
*****************************************************************************/
typedef struct 
{
    U16 id;
    btsend_callback callback;
    void *user_data;
} btsend_app_struct;

typedef struct
{
    U16 appID;
    btsend_notify fNotify;
    void *userData;
} btsend_app_info_struct;

typedef struct
{
    U8 mime_type;
    U16 mime_subtype;
    S8 * mime_string;
} btsend_obj_type_struct;

typedef struct
{
    btsend_obj_enum obj_type;
    union {
        struct {
            void* addr;
            U32 length;
        } buff;
        struct {
            U16* path;
            MMI_BOOL is_sfn;
        } file;
    } u;
} btsend_obj_data_struct;

typedef struct
{
    U16 * name;
    btsend_obj_type_struct type;
    btsend_obj_data_struct data;
} btsend_obj_struct;

typedef struct {
    U16 total;
    btsend_obj_struct *obj;
} btsend_obj_info_struct;

/***************************************************************************** 
* Prototype
*****************************************************************************/
extern U32 mmi_bt_send_object(btsend_obj_struct* obj,
                            btsend_app_struct* app,
                            btsend_prof_enum prof,
                            btsend_opt_enum option);

#endif /*__MMI_OPP_SUPPORT__*/

#ifdef __MMI_BT_DEF_SEND_DEVICE__
extern void mmi_btsend_delete_device_callback(void* dev);
#endif

#if defined(__MMI_FTC_SUPPORT__) || defined(__MMI_BIP_SUPPORT__)
#define RECV_PROG_UPD_DUR (1000)
#define RECV_UNKNOWN_SIZE 0xFFFFFFFF
typedef struct
{
    U16 cur_obj_num;
    U16 total_obj_num;
    U32 recv_obj_size;
    U32 total_obj_size;
} mmi_bt_recv_obj_info_struct;

extern void ShowRecvingScreen(U16 scrn_id, 
                              void(*get_obj_info)(mmi_bt_recv_obj_info_struct *obj_info_p));
extern void UpdateRecvingScreen(U16 scrn_id);
#endif  /* __MMI_FTC_SUPPORT__ || __MMI_BIP_SUPPORT__ */

extern U16 * mmi_bt_update_path(U16 *path, U8 drive, U16 *file);
extern U16 * mmi_bt_get_fldr_name(U16 *name, const U16 *path);
extern U16 * mmi_bt_make_prefix(U16 *name, U16 size, U16 *old_name, U16 num);


#if defined (__MMI_OPP_SUPPORT__) || defined(__MMI_BIP_SUPPORT__)
extern U16 mmi_bt_get_recv_files_cnt(void);
extern U8 mmi_bt_recv_files_exist(void);
extern void mmi_bt_entry_idle_notify_scr(void);
#endif

#if defined(__MMI_OPP_SUPPORT__) && defined(__MMI_NCENTER_SUPPORT__)
extern void mmi_bt_ncenter_notify_notification(void);
#endif

//#ifdef __MMI_BT_PROF_SETTING__
extern void mmi_bt_init_setting(void);
//#endif  /* __MMI_BT_PROF_SETTING__ */

extern void mmi_bt_entry_storage_setting(MMI_ID group_id);
extern WCHAR* mmi_bt_get_storage_setting_string(void);

#if defined(__MMI_FTS_SUPPORT__)
extern void mmi_bt_entry_permission_setting(MMI_ID group_id);
extern WCHAR* mmi_bt_get_permission_setting_string(void);
#endif /* __MMI_FTS_SUPPORT__ */

#endif /* __BT_MMI_OBEX_GPROTS_H__ */ 

