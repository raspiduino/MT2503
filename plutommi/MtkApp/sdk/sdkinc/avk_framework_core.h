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
 *   avk_framework_core.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   AVK framework core .h file
 *
 * Author:
 * -------
 *Jia Luo (mtk80935)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __AVK_FRAMEWORK_CORE_H__
#define __AVK_FRAMEWORK_CORE_H__

extern "C"
{
#include "MMIDataType.h"
}

#define AVK_FRAMEWORK_CASE_TYPE(x) (avk_case_type_enum)(x->test_type&0x00ff)
#define AVK_FRAMEWORK_CASE_FLAG(x) (avk_case_type_enum)(x->test_type&0xff00)

#define AVK_FRAMEWORK_IS_ITEM(x) (AVK_FRAMEWORK_CASE_TYPE(x) < AVK_ITEM_END)
#define AVK_FRAMEWORK_IS_CASE(x) (AVK_FRAMEWORK_CASE_TYPE(x) > AVK_ITEM_END)
#define AVK_FRAMEWORK_IS_EMPTY_ITEM(x) (AVK_FRAMEWORK_CASE_TYPE(x) == AVK_ITEM)
#define AVK_FRAMEWORK_IS_UI_ITEM(x) (AVK_FRAMEWORK_CASE_TYPE(x) & AVK_ITEM_ITEM && AVK_FRAMEWORK_IS_ITEM(x))
#define AVK_FRAMEWORK_IS_AUTO_ITEM(x) (AVK_FRAMEWORK_CASE_TYPE(x) & AVK_ITEM_CASE)
#define AVK_FRAMEWORK_IS_MANUAL_ITEM(x) (AVK_FRAMEWORK_CASE_TYPE(x) & AVK_ITEM_CASE_MANUAL)
#define AVK_FRAMEWORK_IS_AUTO_CASE(x) (AVK_FRAMEWORK_CASE_TYPE(x) & AVK_CASE_AUTO)
#define AVK_FRAMEWORK_IS_ASYN_CASE(x) (AVK_FRAMEWORK_CASE_TYPE(x) == AVK_CASE_AUTO_ASYN)
#define AVK_FRAMEWORK_IS_MANUAL_CASE(x) (AVK_FRAMEWORK_CASE_TYPE(x) & AVK_CASE_MANUAL)
#define AVK_FRAMEWORK_IS_TYPE(x,filter) (((filter&0x00ff)?x->test_type&filter&0x00fe:1) && ((filter&0xff00)?x->test_type&filter&0xff00:1))
#define AVK_FRAMEWORK_RESET_FLAG(x) (x->test_type = AVK_FRAMEWORK_CASE_TYPE(x))
#define AVK_FRAMEWORK_SET_FLAG(x,flag) (x->test_type = (avk_case_type_enum)(x->test_type|(flag&0xff00)))

#define AVK_FRAMEWORK_NULL_FILTER (avk_case_type_enum)0

#define AVK_FRAMEWORK_TIME_ID 0xabcd

#define AVK_FRAMEWORK_TOTAL_CASE_BUFF         1000
#define AVK_FRAMEWORK_MAX_ITEM_DEEP           10
#define AVK_FRAMEWORK_MAX_CASE_NAME_LENGTH    20

#define AVK_FRAMEWORK_INVALID_CASE_ID         (U32)(-1)

#define AVK_GET_CASE_BY_ID(id) (avk_test_case*)id

#define AVK_MAX_FUN_NAME_LEN    128

#define AVK_PASS            1
#define AVK_FAIL            0
#define AVK_NA              0xa1
#define AVK_UNSUPPORT       0x0f

typedef void (*p_test_fun)(void);

typedef struct _avk_fun_list
{
    CHAR*                   fun_name;
    struct _avk_fun_list*   next;
}avk_fun_list;

typedef enum _avk_case_type_enum
{
    AVK_ITEM = 0x0001,
    AVK_ITEM_ITEM = 0x0002,
    AVK_ITEM_ITEM_EX,
    AVK_ITEM_ITEM_SP_ROOT = 0x0004,
    AVK_ITEM_ITEM_SPECIAL = 0x0008,
    AVK_ITEM_CASE = 0x0010,
    AVK_ITEM_CASE_MANUAL = 0x0020,
    AVK_ITEM_END,
    
    AVK_CASE_AUTO = 0x0040,
    AVK_CASE_AUTO_ASYN,
    AVK_CASE_MANUAL = 0x0080,
    AVK_CASE_END,

    AVK_CASE_FAIL = 0x0100,
    AVK_CASE_ABORT = 0x0200,
    AVK_CASE_SPECIAL = 0x0400
}avk_case_type_enum;



typedef struct _avk_test_case
{
    avk_case_type_enum      test_type;
    p_test_fun              test_fun;
    WCHAR*                  test_name;
    struct _avk_test_case*  next;
    struct _avk_test_case*  first_child;
    struct _avk_test_case*  parent;
}avk_test_case;


typedef struct _avk_framework_ctx
{
    avk_test_case*          root; // root item
    avk_test_case*          root_special;
    avk_test_case*          item; // UI high light item         
    p_test_fun              auto_case_done_handle;
    p_test_fun              all_case_done_handle;
    
    avk_test_case*          test_item; 
    avk_test_case*          current_item;    
    avk_test_case*          current_case;
    avk_case_type_enum      current_type;
    avk_fun_list*           fun_list;//functions need get result asyn
    U32                     auto_case_num;
    U32                     all_case_num;
    U32                     current_num;
    p_test_fun              rightkey_handle;
    p_test_fun              leftkey_handle;
    U8                      b_current_result;
    U8                      b_running;
}avk_framework_ctx;

typedef struct _avk_framework_stack
{
    void*       stack[20];
    U8          stack_ptr;
}avk_framework_stack;

typedef struct _avk_framework_buffer
{
    avk_test_case   buffer[AVK_FRAMEWORK_TOTAL_CASE_BUFF];
    U32              buffer_ptr;
}avk_framework_buffer;


extern avk_framework_ctx g_avk_framework_ctx;

extern U32 avk_framework_invoke_cases(avk_test_case* test_item);
extern U32 avk_framework_invoke_cases_special(avk_test_case* test_item);
extern U32 avk_framework_invoke_cases_regression(avk_test_case* test_item, U32 type);
extern void avk_framework_re_invoke_case(void);
extern U32 avk_framework_add_test(avk_case_type_enum test_type, void* test_fun, WCHAR* test_name, U32 test_parent);
extern U32 avk_framework_invoke_next_item(void);
extern U32 avk_framework_invoke_cases_in_current_item(void);
extern void avk_framework_asyn_invoke_next_case(U32 delay);
extern U32 avk_framework_add_init(p_test_fun init_fun, U32 item_id);
extern U32 avk_framework_add_deinit(p_test_fun deinit_fun, U32 item_id);
extern void avk_framework_invoke_next_case(void);
extern U32 avk_framework_insert_fun(CHAR* fun_name);
extern U32 avk_framework_get_item_deep(void);
extern avk_test_case* avk_framework_find_case_by_name(CHAR* case_name);
extern int avk_framework_mark_case(avk_test_case* test_case,avk_test_case* item, avk_case_type_enum flag);
extern int avk_framework_core_init(void (*callback)(void));
extern void avk_framework_core_deinit(void);
extern void* avk_framework_malloc(U32 size);
extern void avk_framework_free(void* p);

#endif //__AVK_FRAMEWORK_CORE_H__    