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
 *   SDKSystemService.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file has to be included for accessing the target version
 *   functionalities of KAL.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _SDKSystemService_H_
#define _SDKSystemService_H_

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_common_defs.h"
#include "stack_config.h"
#include "kal_public_api.h"
#include "fs_type.h"
#include "app_ltlcom.h"

/*************************************************************************
 * Define export function prototype
 *************************************************************************/


/****************************************************************************
 * kal_release.h
 ****************************************************************************/



void kal_sleep_task(kal_uint32 time_in_ticks);
kal_hisrid kal_create_hisr(kal_char* hisr_name, kal_uint8 priority, kal_uint32 stack_size, \
                           kal_hisr_func_ptr entry_func, kal_uint8 options);
void kal_activate_hisr(kal_hisrid ext_hisr_id);
kal_uint32 kal_change_priority(kal_taskid taskid, kal_uint32 new_priority);
kal_uint32 stack_change_priority_by_module_ID(module_type mod_ID, kal_uint32 new_priority);
kal_uint32 stack_change_default_priority_by_module_ID(module_type mod_ID, kal_uint32 new_priority);
void *kal_get_task_stack_ptr(kal_taskid taskid);
kal_uint32 kal_get_task_remain_stack_size(kal_taskid task);
kal_bool kal_if_hisr(void);
kal_taskid kal_get_task_self_id(void);
void kal_get_my_task_index(kal_uint32 *index);
kal_bool kal_if_lisr(void);


/*
 * Message queue
 */ 
kal_msgqid kal_create_msg_q(kal_char* queue_name_ptr, kal_uint16 msg_size, kal_uint16 max_msgs);
void kal_delete_msg_q(kal_msgqid queue_id);
kal_status kal_enque_msg(kal_msgqid ext_msg_q_id, void *buffer_ptr, kal_uint16 msg_size, 
                         kal_wait_mode wait_mode, kal_bool message_to_head);
kal_status kal_deque_msg(kal_msgqid ext_msg_q_id, void* buffer_ptr, kal_uint16 *msg_size,
                         kal_wait_mode wait_mode);
kal_bool kal_get_queue_info(kal_msgqid task_ext_qid, kal_msgq_info *msgq_info);

/*
 * MUTEX
 */
kal_mutexid kal_create_mutex(kal_char* mutex_name_ptr);
void kal_take_mutex(kal_mutexid mutex_id);
void kal_give_mutex(kal_mutexid mutex_id);

/*
 * Semaphore
 */
kal_semid kal_create_sem(kal_char *sem_name_ptr, kal_uint32 initial_count);
kal_status kal_take_sem(kal_semid sem_id, kal_wait_mode wait_mode);
void kal_give_sem(kal_semid sem_id);
kal_uint32 kal_query_sem_value(kal_semid ext_sem_id_ptr);

/*
 * Event group
 */
kal_eventgrpid kal_create_event_group(kal_char *eventgrp_name);
void kal_delete_eventgrp(kal_eventgrpid eg_id);
kal_status kal_set_eg_events(kal_eventgrpid eg_id, kal_uint32 events, kal_uint8 operation);
kal_status kal_retrieve_eg_events(kal_eventgrpid eg_id, kal_uint32 requested_events, kal_uint8 operation, 
                                  kal_uint32 *retrieved_events, kal_uint32 suspend);

/*
 * Event pool
 */
void* kal_evshed_get_mem(kal_uint32 size);
void kal_evshed_free_mem(void* buff_ptr);

/*
 * Appliaction dynamic memory
 */

#if !defined(__FUE__)

/* adm feature option used in kal_adm_create2 */
#define KAL_ADM_OLD_ISLOGGING_FLAG  0x1
#define KAL_ADM_PROFILE_FLAG        0x2
#define KAL_ADM_GUARDIAN_FLAG       0x4
#define KAL_ADM_EXTHEADER_FLAG      0x8
#define KAL_ADM_CLEANDELETE_FLAG    0x10
#define KAL_ADM_REALLOCFAIL_FATAL_FLAG 0x20
#define KAL_ADM_REALLOCFAIL_FREE_FLAG  0x40

/*extern KAL_ADM_ID (kal_adm_create)(void *mem_addr, kal_uint32 size, kal_uint32 *subpool_size, kal_bool islogging);*/
extern KAL_ADM_ID kal_adm_create2(void *mem_addr, kal_uint32 size, kal_uint32 *subpool_size, kal_uint32 flags, kal_int8 extheader_size_in_word);
#define kal_adm_create(mem_addr, size, subpool_size, islogging) kal_adm_create2((mem_addr), (size), (subpool_size), (kal_uint32)islogging, 0)

extern void *__kal_adm_alloc(KAL_ADM_ID adm_id, kal_uint32 size, kal_uint32 *actual_size, kal_uint32 opt, char *filename, kal_uint32 line);
#define kal_adm_alloc(adm_id, size) __kal_adm_alloc((adm_id), (size), NULL, 0, __FILE__, __LINE__)
extern void *__kal_adm_realloc(KAL_ADM_ID adm_id, void *ptr, kal_uint32 size, kal_uint32 *actual_size, kal_uint32 opt, char *filename, kal_uint32 line);
#define kal_adm_realloc(adm_id, ptr, size) __kal_adm_realloc((adm_id), (ptr), (size), NULL, 0, __FILE__, __LINE__)
extern void kal_adm_free(KAL_ADM_ID adm_id, void *mem_addr);
extern void *kal_adm_get_extheader(KAL_ADM_ID adm_id, void *p);
extern kal_status kal_adm_delete(KAL_ADM_ID adm_id);
extern kal_uint32 kal_adm_get_max_alloc_size(KAL_ADM_ID adm_id);
extern kal_uint32 kal_adm_get_total_left_size(KAL_ADM_ID adm_id);
extern void kal_adm_print_log(KAL_ADM_ID adm_id);
extern void *kal_adm_check_integrity(KAL_ADM_ID adm_id);
#endif /* !__FUE__ */

/*
 * Timer Management
 */
kal_timerid kal_create_timer(kal_char* timer_name_ptr);
void kal_set_timer(kal_timerid timer_id, kal_timer_func_ptr handler_func_ptr, void* handler_param_ptr, \
                   kal_uint32 delay, kal_uint32 reschedule_time);
void kal_cancel_timer(kal_timerid timer_id);
void kal_get_time(kal_uint32* ticks_ptr);
kal_uint32 kal_get_time_remaining(kal_timerid timer_id);
kal_uint32 kal_secs_to_ticks(kal_uint32 secs);
kal_uint32 kal_milli_secs_to_ticks(kal_uint32 milli_secs);
kal_uint32 kal_ticks_to_secs(kal_uint32 ticks);
kal_uint32 kal_ticks_to_milli_secs(kal_uint32 ticks);

/*
 * Error Handling
 */
#if defined(__MTK_TARGET__) && !defined(__UBL__)
    
#if defined(__KAL_ASSERT_LEVEL3__)
#define DEBUG_ASSERT(expr) do {if(!(expr)) {} } while (0)
#define ASSERT(expr) do {if(!(expr)) kal_assert_fail_line((kal_char *)#expr, (kal_char *)__FILE__, __LINE__); } while (0)
#define EXT_ASSERT(expr, e1, e2, e3) do {if(!(expr)) kal_assert_fail_ext((kal_char *)#expr, (kal_char *)__FILE__, __LINE__, (e1), (e2), (e3)); } while (0)
#define EXT_ASSERT_DUMP(expr, e1, e2, e3, param) do {if(!(expr)) kal_assert_fail_dump((kal_char *)#expr, (kal_char *)__FILE__, __LINE__, (e1), (e2), (e3), (param)); } while (0)
#elif defined(__KAL_ASSERT_LEVEL2__) && defined(__KAL_ASSERT_SHRINKING__)
#define DEBUG_ASSERT(expr) do {if(!(expr)) {} } while (0)
#define ASSERT(expr) do {if(!(expr)) kal_assert_fail_line(__LINE__); } while (0)
#define EXT_ASSERT(expr, e1, e2, e3) do {if(!(expr)) kal_assert_fail_ext(__LINE__, (e1), (e2), (e3)); } while (0)
#define EXT_ASSERT_DUMP(expr, e1, e2, e3, param) do {if(!(expr)) kal_assert_fail_dump(__LINE__, (e1), (e2), (e3), (param)); } while (0)
#elif defined(__KAL_ASSERT_LEVEL1__) && defined(__KAL_ASSERT_SHRINKING__)
#define DEBUG_ASSERT(expr) do {if(!(expr)) {} } while (0)
#define ASSERT(expr) do {if(!(expr)) kal_assert_fail_line(__LINE__); } while (0)
#define EXT_ASSERT(expr, e1, e2, e3) do {if(!(expr)) kal_assert_fail_line(__LINE__); } while (0)
#define EXT_ASSERT_DUMP(expr, e1, e2, e3, param) do {if(!(expr)) kal_assert_fail_line(__LINE__); } while (0)
#else
#define DEBUG_ASSERT(expr) do {if(!(expr)) {} } while (0)
#define ASSERT(expr) do {if(!(expr)) {} } while (0)
#define EXT_ASSERT(expr, e1, e2, e3) do {if(!(expr)) kal_assert_fail_line(__LINE__); } while (0)
#define EXT_ASSERT_DUMP(expr, e1, e2, e3, param) do {if(!(expr)) kal_assert_fail_line(__LINE__); } while (0)
#endif
    
#else  /* __MTK_TARGET__ */
    
#if defined(__KAL_ASSERT_LEVEL0__) && defined(__KAL_ASSERT_SHRINKING__)
#define DEBUG_ASSERT(expr) do {if(!(expr)) {} } while (0)
#define ASSERT(expr) do {if(!(expr)) {} } while (0)
#define EXT_ASSERT(expr, e1, e2, e3) do {if(!(expr)) kal_assert_fail(); } while (0)
#define EXT_ASSERT_DUMP(expr, e1, e2, e3, param) do {if(!(expr)) kal_assert_fail(); } while (0)
#else
#define DEBUG_ASSERT(expr) do {if(!(expr)) {} } while (0)
#define ASSERT(expr) do {if(!(expr)) kal_assert_fail((kal_char *)#expr, (kal_char *)__FILE__, __LINE__, KAL_FALSE, 0, 0, 0, NULL); } while (0)
#define EXT_ASSERT(expr, e1, e2, e3) do {if(!(expr)) kal_assert_fail((kal_char *)#expr, (kal_char *)__FILE__, __LINE__, KAL_TRUE, (e1), (e2), (e3), NULL); } while (0)
#define EXT_ASSERT_DUMP(expr, e1, e2, e3, param) do {if(!(expr)) kal_assert_fail((kal_char *)#expr, (kal_char *)__FILE__, __LINE__, KAL_TRUE, (e1), (e2), (e3), (param)); } while (0)
#endif
    
#endif /* __MTK_TARGET__ */
    


/****************************************************************************
 * Stack_timer.h
 ****************************************************************************/


extern void stack_init_timer(stack_timer_struct *stack_timer, kal_char *timer_name, module_type module_id);
extern void stack_start_timer(stack_timer_struct *stack_timer, kal_uint16 timer_indx, kal_uint32 init_time);
extern stack_timer_status_type stack_stop_timer(stack_timer_struct *stack_timer);
extern stack_timer_status_type stack_timer_status(stack_timer_struct *stack_timer, kal_uint32 *time_remaining);
extern kal_bool stack_is_time_out_valid(stack_timer_struct *stack_timer);
extern void stack_process_time_out(stack_timer_struct *stack_timer);


/****************************************************************************
 * Fs_func.h
 ****************************************************************************/


#if defined(__SMART_PHONE_MODEM__)
	
#define MD_FS_API(n, ...) MD##_##n(__VA_ARGS__)
	
// General I/O
#define FS_Open(...)					MD_FS_API(FS_Open, __VA_ARGS__)
#define FS_Close(...)					MD_FS_API(FS_Close, __VA_ARGS__)
#define FS_Read(...)					MD_FS_API(FS_Read, __VA_ARGS__)
#define FS_Write(...)					MD_FS_API(FS_Write, __VA_ARGS__)
#define FS_Seek(...)					MD_FS_API(FS_Seek, __VA_ARGS__)
#define FS_Commit(...)				-255//MD_FS_API(FS_Commit, __VA_ARGS__)
	
//Information
#define FS_GetFileInfo(...)				-255//MD_FS_API(FS_GetFileInfo, __VA_ARGS__)
#define FS_GetFileSize(...)				MD_FS_API(FS_GetFileSize, __VA_ARGS__)
#define FS_GetFilePosition(...)			-255//MD_FS_API(FS_GetFilePosition, __VA_ARGS__)
	
//File Only Operation
#define FS_Delete(...)					MD_FS_API(FS_Delete, __VA_ARGS__)
#define FS_CheckFile(...)				-255//MD_FS_API(FS_CheckFile, __VA_ARGS__)
	
//Folder Only Operation
#define FS_GetCurrentDir(...)			-255//MD_FS_API(FS_GetCurrentDir, __VA_ARGS__)
#define FS_SetCurrentDir(...)			-255//MD_FS_API(FS_SetCurrentDir, __VA_ARGS__)
#define FS_CreateDir(...)				MD_FS_API(FS_CreateDir, __VA_ARGS__)
#define FS_RemoveDir(...)				MD_FS_API(FS_RemoveDir, __VA_ARGS__)
	
//File and Folder Operations
#define FS_Rename(...)				MD_FS_API(FS_Rename, __VA_ARGS__)
#define FS_XDelete(...)				MD_FS_API(FS_XDelete, __VA_ARGS__)
	
//Find File
#define FS_FindFirstN(...)				-255//MD_FS_API(FS_FindFirstN, __VA_ARGS__)
#define FS_FindNextN(...)				-255//MD_FS_API(FS_FindNextN, __VA_ARGS__)
#define FS_FindClose(...)				MD_FS_API(FS_FindClose, __VA_ARGS__)

//Drive Management
#define FS_GetDrive(...)				MD_FS_API(FS_GetDrive, __VA_ARGS__)

//Disk Management
#define FS_GetDiskInfo(...)				MD_FS_API(FS_GetDiskInfo, __VA_ARGS__)
	
#else /* __SMART_PHONE_MODEM__ */

// General I/O
extern int FS_Open(const WCHAR * FileName, UINT Flag);
extern int FS_Close(FS_HANDLE FileHandle);
extern int FS_Read(FS_HANDLE FileHandle, void * DataPtr, UINT Length, UINT * Read);
extern int FS_Write(FS_HANDLE FileHandle, void * DataPtr, UINT Length, UINT * Written);
extern int FS_Seek(FS_HANDLE FileHandle, int Offset, int Whence);
extern int FS_Commit(FS_HANDLE FileHandle);

//Information
extern int FS_GetFileInfo(FS_HANDLE FileHandle, FS_FileInfo * FileInfo);
extern int FS_GetFileSize(FS_HANDLE FileHandle, UINT * Size);
extern int FS_GetFilePosition(FS_HANDLE FileHandle, UINT * Position);

//File Only Operation
extern int FS_Delete(const WCHAR * FileName);
extern int FS_CheckFile(const WCHAR * FileName);

//Folder Only Operation
extern int FS_GetCurrentDir(WCHAR * DirName, UINT MaxLength);
extern int FS_SetCurrentDir(const WCHAR * DirName);
extern int FS_CreateDir(const WCHAR * DirName);
extern int FS_RemoveDir(const WCHAR * DirName);

//File and Folder Operations
extern int FS_Rename(const WCHAR * FileName, const WCHAR * NewName);
extern int FS_XDelete(const WCHAR * FullPath, UINT Flag, BYTE *RecursiveStack, const UINT StackSize);

//Find File
extern int FS_FindFirstN(const WCHAR * NamePattern, FS_Pattern_Struct * PatternArray, UINT PatternNum, BYTE ArrayMask, BYTE Attr, BYTE AttrMask, FS_DOSDirEntry * FileInfo, WCHAR * FileName, UINT MaxLength, UINT EntryIndex, UINT Flag);
extern int FS_FindNextN(FS_HANDLE Handle, FS_Pattern_Struct * PatternArray, UINT PatternNum, BYTE ArrayMask, FS_DOSDirEntry * FileInfo, WCHAR * FileName, UINT MaxLength, UINT Flag);
extern int FS_FindClose(FS_HANDLE FileHandle);

//Disk Management
extern int FS_GetDiskInfo(const WCHAR * DriveName, FS_DiskInfo * DiskInfo, int Flags);

//Drive Management
extern int FS_GetDrive(UINT Type, UINT Serial, UINT AltMask);

#endif /* __SMART_PHONE_MODEM__ */


/****************************************************************************
 * Kal_trace.h
 ****************************************************************************/


#ifdef __TST_MODULE__	

extern void kal_prompt_trace(module_type, const kal_char *fmt,...);
	
#else   /* __TST_MODULE__ */
	
#if defined(MTK_KAL_MNT) || defined(KAL_ON_OSCAR) || defined(MCD_DLL_EXPORT) || defined(L1_SIM)
extern void kal_prompt_trace(module_type mod_id, const kal_char *fmt,...);
#else   /* MTK_KAL_MNT ||  KAL_ON_OSCAR */
#define kal_prompt_trace(...)
#endif  /* MTK_KAL_MNT ||  KAL_ON_OSCAR */
	
#endif /* __TST_MODULE__ */


/****************************************************************************
 * stack_ltlcom.h
 ****************************************************************************/


#define SEND_ILM( src_mod, dest_mod, sap, ilm_ptr)\
{ \
   ilm_ptr->src_mod_id  = src_mod;  \
   ilm_ptr->dest_mod_id = dest_mod; \
   ilm_ptr->sap_id = sap; \
   if (mod_task_g[src_mod] == mod_task_g[dest_mod]) { \
     msg_send_int_queue(ilm_ptr); \
   } else { \
     msg_send_ext_queue(ilm_ptr); \
   } \
}

#if defined(DEBUG_KAL) && defined(DEBUG_ITC)
#define free_ilm(ilm_ptr) \
{\
         if ((ilm_ptr)->src_mod_id != MOD_TIMER) \
         free_int_ilm((ilm_ptr), (kal_char*)__FILE__, __LINE__ ); \
}
#else
#define free_ilm(ilm_ptr)\
{\
         if ((ilm_ptr)->src_mod_id != MOD_TIMER) \
         free_int_ilm((ilm_ptr), NULL, 0); \
}
#endif /* DEBUG_ITC */ 

extern kal_bool msg_send_ext_queue(ilm_struct *ilm_ptr);

extern kal_bool msg_send_int_queue(ilm_struct *ilm_ptr);
extern ilm_struct *allocate_ilm(module_type module_id);
extern kal_status receive_msg_ext_q( kal_msgqid task_ext_qid,
                                     ilm_struct *ilm_ptr);
extern kal_bool receive_msg_int_q(task_indx_type task_indx, ilm_struct *ilm_ptr);


/****************************************************************************
 * app_ltlcom.h
 ****************************************************************************/
#if 0
/* under construction !*/
#if defined(DEBUG_KAL)
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
#else   /* DEBUG_KAL */
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
#endif /* DEBUG_KAL */
/* under construction !*/
#endif
#endif /* _SDKSystemService_H_ */


