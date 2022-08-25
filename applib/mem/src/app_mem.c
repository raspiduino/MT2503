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
 *  app_mem.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  ASM (Application Shared Memory)
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
 * removed!
 * removed!
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
 * removed!
 * removed!
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
 * removed!
 * removed!
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

#define APP_MEM_C

/* Only applied to Pluto MMI */
#if !defined(NEPTUNE_MMI) && !defined(MMI_NOT_PRESENT) && !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)

#include "MMI_Features.h"
#include "app_mem.h"
#include "mmiapi_func.h"
#include "GlobalResDef.h"
#if defined(__MTK_TARGET__)
#include "cache_sw.h"
#endif
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "mmi_frm_remutex_gprot.h"
#include "MMIDataType.h"
#include "mmi_frm_scenario_gprot.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "CustDataRes.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_fw_trc.h"
#include "pluto_fw_trc.h"
#include "kal_trace.h"
#include "kal_internal_api.h"
#include "string.h"
#include "kal_adm.h"
#include "kal_vm.h"
#include "vfx_sys_config.h"
#include "mmi_frm_mem_prot.h"
#include <ctype.h>
#if defined(__J2ME__)
#include "JavaAgencyDef.h"
#endif

#include "ui_buffer.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define ASM_TRACE(id, str, ...)     MMI_TRACE(MMI_FW_TRC_G1_FRM, id, __VA_ARGS__)

#undef ASM_ASSERT
#define ASM_ASSERT(_x)  ASSERT(_x)

#ifndef __MTK_TARGET__ /* on MODIS */
    #define APPLIB_MEM_FILL_FILENAME(filename)                                     \
    do                                                                          \
    {                                                                           \
        filename = __FILE__ ;                                                   \
    } while (0)
#elif defined (__RVCT__)
    #define APPLIB_MEM_FILL_FILENAME(filename)                                     \
    do                                                                          \
    {   /*link address rather than filename string*/                            \
        filename =  (const char *)__current_pc();                            \
    } while (0)
#else /*ADS*/
    #define APPLIB_MEM_FILL_FILENAME(filename)                                     \
    do                                                                          \
    {   /*link address rather than filename string*/                            \
        __asm {mov filename, pc;}                                               \
    } while (0)
#endif

#define APPLIB_MEM_APP_COUNT     (APPLIB_MEM_AP_ID_TOTAL - APPLIB_MEM_AP_ID_DUMMY)
#define APPLIB_MEM_APP_STOP_MAX  (3 + APPLIB_MEM_APP_COUNT)
#define ASM_USING_MUTEX

#if !defined(__MRE_SDK__) && defined(__J2ME__) && defined(__MED_IN_ASM__)
#define SCR_MEM_STEAL_VRT_MEM
#endif

#if !defined(__MTK_TARGET__) && defined(WIN32) && defined(__MED_IN_ASM__)
#define ASM_VIEWER
#endif

#ifdef __32_32_SEG__
#undef MMI_PRINT
#define MMI_PRINT(...)
#endif

#if (!defined(__ASM_CACHE_PROMOTION__) && defined(__COSMOS_MMI_PACKAGE__) && defined(__MED_IN_ASM__) &&!defined(__MMI_USE_MMV2__))
#define __ASM_CACHE_PROMOTION__
#define ALLOCK_TYPE_FREE          0x10000000
#define ALLOCK_TYPE_CACHE          0x20000000
#define ALLOCK_TYPE_SSE          0x08000000
#define ALLOCK_TYPE_APP          0x40000000
#define ALLOCK_TYPE_ANONYMOUS   0x80000000
#define ALLOCK_TYPE_MASK        0xF8000000
#define MAX_ALLOC_BLOCK_COUNT 120
#define MAX_PRE_ALLOC_COUNT   60
#endif //__ASM_CACHE_PROMOTION__

#ifdef ASM_USING_MUTEX

#define APP_ASM_LOCK        mmi_frm_recursive_mutex_lock(&g_applib_mem_cntx.app_asm_mutex)
#define APP_ASM_UNLOCK      mmi_frm_recursive_mutex_unlock(&g_applib_mem_cntx.app_asm_mutex)

#else  /* ASM_USING_MUTEX */

#define APP_ASM_LOCK
#define APP_ASM_UNLOCK

#endif /* ASM_USING_MUTEX */


/***************************************************************************** 
 * Typedef 
 *****************************************************************************/

/* list traverse handler */
typedef kal_bool (* list_traverse_handler)(applib_mem_header_struct *node, void *arg1, void *arg2, void *arg3);

typedef struct 
{
    /* Handlers to stop application (executed in MMI task) */
    applib_mem_stop_handler_type stop_callback;
    /* application id */
    kal_uint16 id;
    /* Application has not finished stopping */
    kal_bool is_stopping;
    /* registered for is_stopping info automatically, should free stop_info after stopped */
    kal_bool is_auto_registered;
} applib_mem_app_stop_info_struct;


/* app info struct, may be removed if data comes from resgen in the future */
typedef struct 
{
    /* Application id */
    kal_uint16 id;
    /* Application name (string id) */
    kal_uint16 name;

    kal_bool hide_in_oom;
} applib_mem_app_info_struct;

#ifdef __MED_IN_ASM__
/* cache header */
typedef struct _cache_header_struct 
{
    kal_uint32 header_guard;
    struct _cache_header_struct *next;
    applib_mem_cache_free_cb_type free_cb;
    void* user_ptr;
    kal_uint32 cache_priority;
    kal_uint32 size;
#ifdef __ASM_POOL_32_BYTE_ALIGN__
    kal_uint32 reserve[2];
#endif
} applib_mem_cache_header_struct;
#endif

typedef struct
{
    /**************************************************************************
        * app *
        **************************************************************************/

    /* ADM pool ID of app-based ASM. */
    kal_uint32 app_pool_id;

    /* memory buffer pool */
    void *app_pool;

    /* buffer pool size */
    kal_uint32 app_pool_size;

    /* Count of allocated app-based blocks */
    kal_int32 app_alloc_count;

    /* Callback handler to process the result of stopping application in MMI task */
    app_stop_finish_callback_type app_stop_finish_callback;

    /* default stop callback */
    applib_mem_stop_handler_type app_stop_callback_default;

    /* callback before allocate memory */
    applib_mem_ap_pre_alloc_hdlr app_pre_alloc_handler;

    /* callback before before SSE allocating */
    applib_mem_ap_anonymous_info_hdlr app_get_anonymous_reserved_size_handler;

    /* callback after memory is freed */
    applib_mem_freed_handler mem_freed_handler;

    /* Head node of app-based chunk */
    applib_mem_header_struct app_head;

    /* Initialized */
    kal_bool app_pool_inited;


    /* app stop info */
    applib_mem_app_stop_info_struct app_stop_info[APPLIB_MEM_APP_STOP_MAX];

    /* application info */    
    applib_mem_app_info_struct app_info[APPLIB_MEM_APP_COUNT];

    /* Multi-thread mutex */
    mmi_frm_recursive_mutex_struct app_asm_mutex;

    kal_uint32 pre_reserve_size;
#ifdef __ASM_CACHE_PROMOTION__
    ADM_MB_HEAD * block_layout_array[MAX_ALLOC_BLOCK_COUNT];
    kal_uint32 blocks_size_info[MAX_ALLOC_BLOCK_COUNT];
    kal_uint32 blocks_count;
    kal_uint32 blocks_analyze;
    void* pre_alloc_list[MAX_PRE_ALLOC_COUNT];
#endif //__ASM_CACHE_PROMOTION__
    /**************************************************************************
     * cache *
    **************************************************************************/
#ifdef __MED_IN_ASM__

    /* Head node of cache memory */
    applib_mem_cache_header_struct cache_head;

    /* sum of cache memory size */
    kal_uint32  cache_size;
#endif

    /**************************************************************************
     * scr *
    **************************************************************************/

    /* ADM pool ID of screen-based ASM */
    KAL_ADM_ID screen_pool_id;

    /* Count of allocated screen-based blocks */
    kal_int32 screen_alloc_count;

} applib_mem_cntx_struct;


typedef struct
{
    kal_uint32 max_items;
    kal_uint32 param; // decide include hidden app and skip ASM1.0 app or not.
    kal_uint16 *skiplist;
    kal_uint32 skip_count;
    app_get_usage_check_cb cb;
} get_asm_usage_para_struct;

/*****************************************************************************              
 * Local Variable                                                                    
 *****************************************************************************/

/* Context of screen-based memory */
static applib_mem_cntx_struct g_applib_mem_cntx;

#if defined __MMI_USE_MMV2__
static applib_shrunk_heap_list g_applib_shrunk_heap_list = {0};
#endif
/* for KAL ADM */
static const kal_uint32 g_applib_mem_pool_chunk_size[] = 
{
    512, 1024, 2048, 4096, 0xffffffff, 0
};


/*****************************************************************************              
 * External Variable Declare                                                                 
 *****************************************************************************/

/*****************************************************************************              
 * External Function Declare                                                                    
 *****************************************************************************/
#if !defined(__MTK_TARGET__) && defined(WIN32)
extern unsigned long __stdcall GetModuleFileNameA(
  void*         hModule, 
  const char*   lpFilename, 
  unsigned int  nSize
);
#endif
extern void HistoryDump(void);

/*****************************************************************************              
 * Local Function                                                                    
 *****************************************************************************/
static kal_bool is_static_id(kal_uint16 app_id);
static kal_uint16 get_static_id_idx(kal_uint16 app_id);
static kal_uint16 get_root_app_id(kal_uint16 app_id);
static void set_static_registered_app_info(applib_mem_app_info_struct *info_p);
static void get_app_info(kal_uint16 app_id, applib_mem_app_info_struct *info_p);
static applib_mem_app_stop_info_struct *get_app_stop_info(kal_uint16 app_id);
static applib_mem_app_stop_info_struct *allocate_app_stop_info_space(kal_uint16 app_id);
static void free_app_stop_info_space(kal_uint16 app_id);
static kal_char *get_file_name(kal_char *file);
static void insert_sort(applib_mem_ap_usage_struct *a, kal_int32 len);
#ifdef __MED_IN_ASM__
#if defined __MMI_USE_MMV2_
static kal_bool print_flmm_memory_block(KAL_FLMM_ID flmm_id, kal_vm_meminfo_t *info, void *v_addr, void *userdata);
#else
#if (!defined(__32_32_SEG__) && !defined(__ASM_CACHE_PROMOTION__))
static kal_bool print_adm_memory_block(KAL_ADM_ID adm_id, kal_uint32 flags, ADM_MB_HEAD *adm_mb_head, void *user_data);
#endif
#endif
#endif
#if defined(__ASM_CACHE_PROMOTION__)
#define BLOCK_TYPE(index) (g_applib_mem_cntx.blocks_size_info[index] & ALLOCK_TYPE_MASK)
#define BLOCK_SIZE(index) (g_applib_mem_cntx.blocks_size_info[index] & (~ALLOCK_TYPE_MASK))
static void applib_free_cache_by_index(kal_uint32 index, kal_bool isFreeSSE);
static kal_bool applib_adm_layout(KAL_ADM_ID adm_id, kal_uint32 flags, ADM_MB_HEAD *adm_mb_head, void *user_data);
static void* applib_smart_alloc(kal_uint32 mem_size, asm_alloc_flag alloc_flag, kal_uint32 analizeType);
static kal_uint32 applib_get_first_block(kal_uint32* size, kal_bool is_topmost_dir, kal_uint32 type);

#endif //__ASM_CACHE_PROMOTION__
static void *set_allocation_info(
    void *chunk, 
    kal_uint16 owner_id, 
    kal_uint32 mem_size, 
    kal_uint16 flag, 
    applib_mem_header_struct *list_header, 
    kal_int32 *count, 
    kal_char *file, 
    kal_uint32 line
    );
static applib_mem_header_struct *set_free_info(
    void *mem_ptr, 
    kal_uint32 align_size, 
    applib_mem_header_struct *list_header, 
    kal_int32 *count, 
    kal_char *file, 
    kal_uint32 line);
static kal_uint32 calc_real_alloc_size(kal_uint32 mem_size, kal_uint32 align_size);
static void set_app_usage_info(applib_mem_ap_usage_struct *info, applib_mem_app_info_struct *app_info);
static kal_bool is_app_visible(applib_mem_header_struct *header);
static kal_bool is_valid_block(void *mem_ptr, kal_uint32 align_size);
static void traverse_app_link_list(list_traverse_handler callback, void *arg1, void *arg2, void *arg3);
static kal_bool get_app_usage_handler(applib_mem_header_struct *node, void *arg1, void *arg2, void *arg3);
static kal_bool get_app_usage_list_handler(applib_mem_header_struct *node, void *arg1, void *arg2, void *arg3);
static kal_bool update_node_flag_handler(applib_mem_header_struct *node, void *arg1, void *arg2, void *arg3);
static kal_bool memory_leak_check_handler(applib_mem_header_struct *node, void *arg1, void *arg2, void *arg3);
static kal_bool ap_integrity_check_handler(applib_mem_header_struct *node, void *arg1, void *arg2, void *arg3);
static void applib_mem_ap_free_int(void *mem_ptr, kal_char *file, kal_uint32 line, kal_bool is_anonymous);
#ifdef ASM_VIEWER
#if defined __MMI_USE_MMV2_
static kal_bool applib_asm_debug_dump_flmm_cb(KAL_FLMM_ID flmm_id, kal_vm_meminfo_t *info, void *v_addr, void *userdata);
#else
static kal_bool applib_asm_debug_dump_adm_cb(KAL_ADM_ID adm_id, kal_uint32 flags, ADM_MB_HEAD *adm_mb_head, void *user_data);
#endif
#endif
static void applib_asm_debug_dump(void);

/*****************************************************************************
 * FUNCTION
 *  is_static_id
 * DESCRIPTION
 *  check if given a pre-defined APP ASM ID.
 * PARAMETERS
 *  app_id:  [IN]    app_id to get
 * RETURNS
 *  true: id is defined. false: id is not defined.
 *****************************************************************************/
static kal_bool is_static_id(kal_uint16 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((APPLIB_MEM_AP_ID_DUMMY < app_id) && (app_id < APPLIB_MEM_AP_ID_TOTAL)) ? KAL_TRUE : KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  get_static_id_idx
 * DESCRIPTION
 *  get idx of registered app_id.
 * PARAMETERS
 *  app_id:  [IN]    app_id to get
 * RETURNS
 *  index
 *****************************************************************************/
static kal_uint16 get_static_id_idx(kal_uint16 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(is_static_id(app_id));
    return (app_id - APPLIB_MEM_AP_ID_DUMMY);
}


/*****************************************************************************
 * FUNCTION
 *  get_root_app_id
 * DESCRIPTION
 *  get group ID of root application.
 * PARAMETERS
 *  app_id:  [IN]    app_id to get
 * RETURNS
 *  root app_id
 *****************************************************************************/
static kal_uint16 get_root_app_id(kal_uint16 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 root_app_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* real app should be root app for screen group one */
    if ((root_app_id = mmi_frm_get_root_app((mmi_id) app_id)) == GRP_ID_INVALID)
    {
        root_app_id = app_id;
    }
    return root_app_id;
}


/*****************************************************************************
 * FUNCTION
 *  set_static_registered_app_info
 * DESCRIPTION
 *  set application info. 
 * PARAMETERS
 *  info_p  :[IN] pointer to app info to set
 * RETURNS
 *  void
 *****************************************************************************/
static void set_static_registered_app_info(applib_mem_app_info_struct *info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 idx = (kal_int32)get_static_id_idx(info_p->id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_applib_mem_cntx.app_info[idx] = *info_p;
}


/*****************************************************************************
 * FUNCTION
 *  get_app_info
 * DESCRIPTION
 *  get application info. this info may come from resgen in the future.
 * PARAMETERS
 *  app_id  :[IN]    app_id to get
 *  info_p  :[IN/OUT] pointer to app info
 * RETURNS
 *  void
 *****************************************************************************/
static void get_app_info(kal_uint16 app_id, applib_mem_app_info_struct *info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 root_app_id = get_root_app_id(app_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    info_p->id = root_app_id;
    if (is_static_id(root_app_id))
    {
        info_p->name = g_applib_mem_cntx.app_info[get_static_id_idx(root_app_id)].name;
        info_p->hide_in_oom = g_applib_mem_cntx.app_info[get_static_id_idx(root_app_id)].hide_in_oom;
    }
#ifdef __MMI_SUPPORT_ASMV2__    
    else
    {
        info_p->name = mmi_res_get_app_name_str_id(root_app_id);
       info_p->hide_in_oom = KAL_FALSE;
    }
#endif //  __MMI_SUPPORT_ASMV2__
}


/*****************************************************************************
 * FUNCTION
 *  get_app_stop_info
 * DESCRIPTION
 *  get allocated app_stop_info space
 * PARAMETERS
 *  app_id  :[IN]    app_id to get
 * RETURNS
 *  pointer to allocated space
 *****************************************************************************/
static applib_mem_app_stop_info_struct *get_app_stop_info(kal_uint16 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    kal_uint16 root_app_id = get_root_app_id(app_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i=0; i<APPLIB_MEM_APP_STOP_MAX; i++)
    {
        if (g_applib_mem_cntx.app_stop_info[i].id == root_app_id)
            return &g_applib_mem_cntx.app_stop_info[i];
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  allocate_app_stop_info_space
 * DESCRIPTION
 *  allocate one app_stop_info space
 * PARAMETERS
 *  app_id  :[IN]    app_id to allocate
 * RETURNS
 *  pointer to allocated space
 *****************************************************************************/
static applib_mem_app_stop_info_struct *allocate_app_stop_info_space(kal_uint16 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    kal_uint16 root_app_id = get_root_app_id(app_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i=0; i<APPLIB_MEM_APP_STOP_MAX; i++)
    {
        if (g_applib_mem_cntx.app_stop_info[i].id == 0)
        {
            g_applib_mem_cntx.app_stop_info[i].id                   = root_app_id;
            g_applib_mem_cntx.app_stop_info[i].is_auto_registered   = KAL_FALSE;
            g_applib_mem_cntx.app_stop_info[i].is_stopping          = KAL_FALSE;
            g_applib_mem_cntx.app_stop_info[i].stop_callback        = NULL;
            return &g_applib_mem_cntx.app_stop_info[i];
        }
    }
#ifndef APPLIB_MEM_UNIT_TEST
    ASM_ASSERT(0);  /* space not enough for app_stop_info */
#endif
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  free_app_stop_info_space
 * DESCRIPTION
 *  free one app_stop_info space
 * PARAMETERS
 *  app_id  :[IN]    app_id to free
 * RETURNS
 *  void
 *****************************************************************************/
static void free_app_stop_info_space(kal_uint16 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    for (i=0; i<APPLIB_MEM_APP_STOP_MAX; i++)
    {
        if (g_applib_mem_cntx.app_stop_info[i].id == app_id)
        {
            g_applib_mem_cntx.app_stop_info[i].id = 0;
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  get_file_name
 * DESCRIPTION
 *  trucate the file path as file name
 * PARAMETERS
 *  file  :[IN]   file path
 * RETURNS
 *  file name
 *****************************************************************************/
static kal_char *get_file_name(kal_char *file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (file == NULL || file[0] == '\0')
    {
        return NULL;
    }
    return basename(file);
}


/*****************************************************************************
 * FUNCTION
 *  insert_sort
 * DESCRIPTION
 *  sort the app list by the memory size from big to small
 * PARAMETERS
 *  a  :          [IN/OUT]   app list
 *  len:          [IN] app list length
 * RETURNS
 *  void
 *****************************************************************************/
static void insert_sort(applib_mem_ap_usage_struct *a, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32  i;
    kal_int32 j;
    applib_mem_ap_usage_struct temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 1; i < len; i++)
    {
        j = i - 1;
        temp = a[i];
        while ((j >= 0) && (a[j].mem_size < temp.mem_size))
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}


#ifdef __MED_IN_ASM__
#if defined __MMI_USE_MMV2__
/*****************************************************************************
 * FUNCTION
 *  print_flmm_memory_block
 * DESCRIPTION
 *  Flmm pool traverse call back to print Flmm pool info
 * PARAMETERS
 *  flmm_id:      [IN]   Flmm pool ID
 *  info :        [IN]   Flmm memory block info
 *  v_addr:       [IN]   Flmm memory block virtual address
 *  user_data:    [IN]   user data
 * RETURNS
 *  KAL_TRUE to traverse all
 *****************************************************************************/
static kal_bool print_flmm_memory_block(KAL_FLMM_ID adm_id, kal_vm_meminfo_t *info, void *v_addr, void *userdata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (info->slmm == NULL)
    {
        applib_mem_header_struct *p = (info->attr & KAL_VM_NONCACHEABLE) ? info->physical : v_addr;
        if (p->guard_pattern != APPLIB_MEM_HEADER_PATTERN1)
        {
            applib_mem_cache_header_struct *q = (applib_mem_cache_header_struct *)p;
            MMI_PRINT(MOD_MMI_FW, MMI_FW_TRC_G1_FRM, "[ASM][FLMM][TRV][cache][ptr = 0x%x, size = %d, c/nc:%s, t/nt:%s]\n", 
                      q + 1, q->size, 
                      info->attr & KAL_VM_CACHEABLE ? "c" : "nc", /*continuous or not*/
                      info->attr & KAL_VM_CONTINUOUS ? "t" : "nt" /*continuous or not*/
                      );
        }
        else
        {
            MMI_PRINT(MOD_MMI_FW, MMI_FW_TRC_G1_FRM, "[ASM][FLMM][TRV][ptr = 0x%x, id = %d, size = %d, c/nc:%s, t/nt:%s]\n", 
                      p + 1, p->owner_id, p->chunk_size, 
                      info->attr & KAL_VM_CACHEABLE ? "c" : "nc", /*continuous or not*/
                      info->attr & KAL_VM_CONTINUOUS ? "t" : "nt" /*continuous or not*/
                      );
        }
    }
    else
    {   /*SLMM pool*/
        const kal_uint32 struc_offset = (kal_uint32)(&((applib_mem_slmm_id)0)->applib_mem_header);
        applib_mem_slmm_id asm_slmm_id;
        applib_mem_header_struct *prev_node, *cur_node;
        for (cur_node = &g_applib_mem_cntx.app_head;
             cur_node;
             prev_node = cur_node, cur_node = prev_node->next)
        {
            if ((cur_node->flag & APPLIB_MEM_HEADER_FLAG_IS_SLMM))
            {
                asm_slmm_id = (applib_mem_slmm_id)((kal_uint32)cur_node - struc_offset) ;
                if (asm_slmm_id->kal_slmm_id == info->slmm)
                {
                    break;
                }
            }
        }
        if (cur_node)
        {
            MMI_PRINT(MOD_MMI_FW, MMI_FW_TRC_G1_FRM, "[ASM][SLMM][TRV][ptr = 0x%x, id = %d, size = %d]\n", 
                      v_addr, cur_node->owner_id, cur_node->chunk_size
                      );
        }
        else
        {
            MMI_PRINT(MOD_MMI_FW, MMI_FW_TRC_G1_FRM, "[ASM][SLMM][TRV][ptr = 0x%x, v_size = %d. owner can't be found]\n", 
                      v_addr, info->size
                      );
        }
    }
    return KAL_TRUE;
}
#endif //__MMI_USE_MMV2__
#if (!defined(__32_32_SEG__) && !defined(__ASM_CACHE_PROMOTION__))
/*****************************************************************************
 * FUNCTION
 *  print_adm_memory_block
 * DESCRIPTION
 *  ADM pool traverse call back to print ADM pool info
 * PARAMETERS
 *  adm_id  :     [IN] ADM ID
 *  flags:        [IN] ADM block flags
 *  adm_mb_head:  [IN] ADM memory block header
 *  user_data:    [IN] user_data
 * RETURNS
 *  KAL_TRUE to traverse all
 *****************************************************************************/
static kal_bool print_adm_memory_block(KAL_ADM_ID adm_id, kal_uint32 flags, ADM_MB_HEAD *adm_mb_head, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((flags & KAL_ADM_MB_INUSE) == KAL_ADM_MB_INUSE)
    {
         kal_uint32 length;
        applib_mem_header_struct *p = (applib_mem_header_struct *)kal_adm_get_buffer(adm_id, adm_mb_head, &length);
        if (p->guard_pattern != APPLIB_MEM_HEADER_PATTERN1)
        {
            applib_mem_cache_header_struct *q = (applib_mem_cache_header_struct *)p;

            ASM_TRACE(TRC_MMI_FRM_ASM_DUMP_ALLOC, "[ASM][pool][ptr = 0x%x, id = %d, size = %d]\n", q + 1, 0, q->size);
        }
        else
        {
            ASM_TRACE(TRC_MMI_FRM_ASM_DUMP_ALLOC, "[ASM][pool][ptr = 0x%x, id = %d, size = %d]\n", p + 1, p->owner_id, p->chunk_size);
        }
    }
    else if ((flags & KAL_ADM_MB_FREE) == KAL_ADM_MB_FREE)
    {
        kal_uint32 size = ADM_MB_SIZE(adm_mb_head);

        ASM_TRACE(TRC_MMI_FRM_ASM_DUMP_FREE, "[ASM][pool][Free: size = %d]\n", size);
    }
    return KAL_TRUE;
}
#endif //(!defined(__32_32_SEG__) && !defined(__ASM_CACHE_PROMOTION__))
#endif


/*****************************************************************************
 * FUNCTION
 *  set_allocation_info
 * DESCRIPTION
 *  Set the allocation info after allocate memory
 * PARAMETERS
 *  chunk:        [IN] memory point from low level allocator
 *  owner_id:     [IN] application ID
 *  flag:         [IN] hide or unhide in OOM list for App-Based ASM
 *  list_header:  [IN] memory link list head node
 *  count:        [OUT] allocation count
 *  caller_addr:  [IN] caller address, reserve
 * RETURNS
 *  void
 *****************************************************************************/
static void *set_allocation_info(
    void *chunk, 
    kal_uint16 owner_id, 
    kal_uint32 mem_size, 
    kal_uint16 flag, 
    applib_mem_header_struct *list_header, 
    kal_int32 *count, 
    kal_char *file, 
    kal_uint32 line
    )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mem_header_struct *header;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    header = (applib_mem_header_struct*) chunk;
    chunk = header + 1;

    /* header */
    header->owner_id = owner_id;
    header->chunk_size = mem_size;
    header->flag = flag;
//    ASM_ASSERT(header->guard_pattern != APPLIB_MEM_HEADER_PATTERN1);

    header->guard_pattern = APPLIB_MEM_HEADER_PATTERN1;


    /* update linked list */
    header->next = list_header->next;
    list_header->next = header;
        header->file = file;
        header->line = line;

    /* system context */
    (*count)++;

    return chunk;
}


/*****************************************************************************
 * FUNCTION
 *  set_free_info
 * DESCRIPTION
 *  Set the free info before free memory
 * PARAMETERS
 *  mem_ptr:      [IN] memory point from the high level user
 *  align_size:   [IN] memory point alignment size
 *  list_header:  [IN] memory link list head node
 *  count:        [OUT] allocation count
 *  caller_addr:  [IN] caller address, reserve
 * RETURNS
 *  void
 *****************************************************************************/
static applib_mem_header_struct *set_free_info(
    void *mem_ptr, 
    kal_uint32 align_size, 
    applib_mem_header_struct *list_header, 
    kal_int32 *count, 
    kal_char *file, 
    kal_uint32 line)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mem_header_struct *header, *prev_node, *remove_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASM_ASSERT(mem_ptr && APPLIB_MEM_ALIGNED_PTR(mem_ptr, align_size));

    header = ((applib_mem_header_struct*) mem_ptr) - 1;

    ASM_ASSERT(header->guard_pattern == APPLIB_MEM_HEADER_PATTERN1);

    /* 
     * Remove the block from linked list 
     *
     * It is not a fast algorithm, we can improve it by using double linked list, 
     * but we choose simpler design because
     * 1. Typically total allocation count is small
     * 2. We don't want to increase space overheads
     * 3. We don't want to access KAL ADM internal data structure
     */
    prev_node = list_header;
    ASM_ASSERT(prev_node->next);
    for (remove_node = prev_node->next;
         remove_node;
         prev_node = remove_node, remove_node = prev_node->next)
    {
        if (remove_node == header)
        {
            break;
        }
    }
    ASM_ASSERT(remove_node);
    prev_node->next = remove_node->next;

    /* Set guard pattern */
    //ASM_ASSERT(header->guard_pattern == APPLIB_MEM_HEADER_PATTERN1);
    header->guard_pattern = APPLIB_MEM_HEADER_PATTERN2;
    ASM_ASSERT(*count > 0);
    (*count)--;

    return (void *)header;
}


/*****************************************************************************
 * FUNCTION
 *  calc_real_alloc_size
 * DESCRIPTION
 *  calculate the low level memory size
 * PARAMETERS
 *  mem_size   :  [IN/OUT]   high level user memory size
 *  align_size :  [IN] align size that low level allocator needs
 * RETURNS
 *  low level allocator memory size
 *****************************************************************************/
static kal_uint32 calc_real_alloc_size(kal_uint32 mem_size, kal_uint32 align_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 chunk_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mem_size = APPMEM_ALIGN_TO_N(mem_size, 4);
    chunk_size = APPMEM_ALIGN_TO_N(
        mem_size + sizeof(applib_mem_header_struct), 
        align_size);
    return chunk_size;
}


/*****************************************************************************
 * FUNCTION
 *  set_app_usage_info
 * DESCRIPTION
 *  Set the application usage info
 * PARAMETERS
 *  info       :  [OUT]   application usage info
 *  app_info   :  [IN]    application info
 * RETURNS
 *  void
 *****************************************************************************/
static void set_app_usage_info(applib_mem_ap_usage_struct *info, applib_mem_app_info_struct *app_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mem_app_stop_info_struct *app_stop_info_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    info->app_id      = app_info->id;
    info->string_id   = app_info->name;
    info->mem_size = 0;
    app_stop_info_p = get_app_stop_info(app_info->id);
    info->is_stopping = (app_stop_info_p) ? app_stop_info_p->is_stopping : KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  is_app_visible
 * DESCRIPTION
 *  Judge if can be displayed in OOM
 * PARAMETERS
 *  header       :  [IN]  memory chunk ASM header
 * RETURNS
 *  KAL_TRUE mean visible
 *****************************************************************************/
static kal_bool is_app_visible(applib_mem_header_struct *header)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((is_static_id(header->owner_id) ||
        (GRP_ID_INVALID != mmi_frm_get_root_app(header->owner_id))) && 
        ((header->flag & APPLIB_MEM_HEADER_FLAG_IS_HIDE) == 0) )
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  is_valid_block
 * DESCRIPTION
 *  to check if the ASM memory block is valid or not
 * PARAMETERS
 *  mem_ptr       :  [IN] high level user memory pointer
 *  align_size    :  [IN] the align size of the memory pointer 
 * RETURNS
 *  KAL_TRUE if a valid lock
 *****************************************************************************/
static kal_bool is_valid_block(void *mem_ptr, kal_uint32 align_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mem_header_struct *header;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mem_ptr)
        return KAL_FALSE;

    header = ((applib_mem_header_struct*) mem_ptr) - 1;
    if ((header->guard_pattern == APPLIB_MEM_HEADER_PATTERN1)
        && APPLIB_MEM_ALIGNED_N(mem_ptr, align_size)
#if defined __MMI_USE_MMV2__        
        && ((header->flag & APPLIB_MEM_HEADER_FLAG_IS_SLMM) == 1)
#endif //__MMI_USE_MMV2__
        )
    {
        return KAL_TRUE;
    }
    else
        return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  traverse_app_link_list
 * DESCRIPTION
 *  traverse the ASM memory block list
 * PARAMETERS
 *  list          : [IN]  head node of the list
 *  callback      : [IN]  callback function for each node
 *  arg1          : [IN/OUT] user define argument 1
 *  arg2          : [IN/OUT] user define argument 2
 *  arg3          : [IN/OUT] user define argument 3
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void traverse_app_link_list(list_traverse_handler callback, void *arg1, void *arg2, void *arg3)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mem_header_struct *list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list = g_applib_mem_cntx.app_head.next;
    APP_ASM_LOCK;

    while (list)
    {
        if (callback(list, arg1, arg2, arg3) == KAL_TRUE)
        {
            break;
        }
        list = list->next;
    }
    APP_ASM_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  get_app_usage_handler
 * DESCRIPTION
 *  callback of traverse list to statistic the memory size of a app
 * PARAMETERS
 *  node          : [IN]  header of the memory block
 *  arg1          : [IN]  application id
 *  arg2          : [OUT] accumulated memory size
 *  arg3          : [IN]  reserve
 *
 * RETURNS
 *  KAL_FALSE means traverse all nodes
 *****************************************************************************/
static kal_bool get_app_usage_handler(applib_mem_header_struct *node, void *arg1, void *arg2, void *arg3)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 root_app_id = (kal_uint16)((kal_uint32)arg1);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (get_root_app_id(node->owner_id) == root_app_id)
    {
        *((kal_uint32 *)arg2) += node->chunk_size + APPLIB_MEM_CHUNK_EXTRA_SIZE;
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  get_app_usage_list_handler
 * DESCRIPTION
 *  callback of traverse list to statistic application info
 *  1. memory size
 *  2. application number
 *
 * PARAMETERS
 *  node          : [IN]  header of the memory block
 *  arg1          : [IN/OUT] application list  
 *  arg2          : [IN]  information about this get
 *  arg3          : [OUT]  real application number
 *
 * RETURNS
 *  KAL_FALSE means traverse all nodes
 *****************************************************************************/
static kal_bool get_app_usage_list_handler(
    applib_mem_header_struct *node, 
    void *arg1, 
    void *arg2, 
    void *arg3)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 idx;
    kal_uint32 *item_count = (kal_uint32 *)arg3;
    applib_mem_app_info_struct app_info;
    applib_mem_ap_usage_struct *applist = (applib_mem_ap_usage_struct *)arg1;
    get_asm_usage_para_struct *para = (get_asm_usage_para_struct *)arg2;
    kal_uint32 max_items = para->max_items;
    kal_uint16 *skip_list = para->skiplist;
    kal_uint32 skip_count = para->skip_count;
    kal_uint32 param = para->param;
    app_get_usage_check_cb cb = para->cb;
    MMI_ID owner_root_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    get_app_info(node->owner_id, &app_info);
    owner_root_id = mmi_frm_get_root_app(node->owner_id);
    if (cb != NULL && (MMI_TRUE == cb(owner_root_id)))
    {
        return KAL_FALSE;
    }

    if (((param & MMI_FRM_APP_MEM_INCLUDE_HIDE) == 0) && is_app_visible(node) == KAL_FALSE)
    {
        return KAL_FALSE;
    }

    if (is_static_id(node->owner_id))
    {
        if (param & MMI_FRM_APP_MEM_SKIP_V10)
        {
            return KAL_FALSE;
        }
    }
    else if (mmi_frm_get_root_app(node->owner_id) == GRP_ID_INVALID)
    {
        /* JAVA will keep its memory after close screen group */
        return KAL_FALSE;
    }

    if (skip_list != NULL)
    {
        for (idx = 0; idx < skip_count; idx++)
        {
            if (get_root_app_id(node->owner_id) == get_root_app_id(skip_list[idx]))
            {
                return KAL_FALSE;
            }
        }
    }


    for (idx = 0; idx < *item_count; idx++)
    {
        if (applist[idx].app_id == app_info.id)
        {
            break;
        }
    }

    /* chunk for new app_id */
    if (idx == *item_count)
    {
        if (*item_count == max_items)
        {
            node = node->next;
            return KAL_FALSE;
        }
        else
        {
            set_app_usage_info(&applist[*item_count], &app_info);
            (*item_count)++;
        }
    }

    applist[idx].mem_size += node->chunk_size + APPLIB_MEM_CHUNK_EXTRA_SIZE;
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  update_node_flag_handler
 * DESCRIPTION
 *  update node flag value
 *
 * PARAMETERS
 *  node          : [IN]  header of the memory block
 *  arg1          : [IN]  application ID  
 *  arg2          : [IN]  flag value
 *  arg3          : [IN]  reserve
 *
 * RETURNS
 *  KAL_FALSE means traverse all nodes
 *****************************************************************************/
static kal_bool update_node_flag_handler(applib_mem_header_struct *node, void *arg1, void *arg2, void *arg3)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 app_id = (kal_uint16)((kal_uint32)arg1);
    kal_uint16 flag = (kal_uint16)((kal_uint32)arg2);
    kal_uint32 is_set = (kal_uint32)arg3;
    kal_uint16 root_app_id = get_root_app_id(node->owner_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (root_app_id == app_id)
    {
        if (is_set)
        {
            node->flag |= flag;
        }
        else
        {
            node->flag &= ~flag;
        }
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  memory_leak_check_handler
 * DESCRIPTION
 *  check if memory leak happen for an application
 *
 * PARAMETERS
 *  node          : [IN]  header of the memory block
 *  arg1          : [IN]  application ID  
 *  arg2          : [IN]  reserve
 *  arg3          : [IN]  reserve
 *
 * RETURNS
 *  KAL_FALSE means traverse all nodes
 *****************************************************************************/
static kal_bool memory_leak_check_handler(applib_mem_header_struct *node, void *arg1, void *arg2, void *arg3)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 app_id = (kal_uint16)((kal_uint32)arg1);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if defined __MMI_USE_MMV2__
    if (node->owner_id == app_id)
    {
        ASM_ASSERT(node->chunk_size <= mmi_res_get_app_global_size(app_id));
    }
    #else
    ASM_ASSERT(node->owner_id != app_id);
    #endif
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  ap_integrity_check_handler
 * DESCRIPTION
 *  check integrity of App-based ASM buffer pool
 *
 * PARAMETERS
 *  node          : [IN]  header of the memory block
 *  arg1          : [IN]  reserve  
 *  arg2          : [IN]  reserve
 *  arg3          : [IN]  reserve
 *
 * RETURNS
 *  KAL_FALSE means traverse all nodes
 *****************************************************************************/
static kal_bool ap_integrity_check_handler(applib_mem_header_struct *node, void *arg1, void *arg2, void *arg3)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASM_ASSERT(is_valid_block(node + 1, ASM_ALIGN_SIZE));
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_free_int
 * DESCRIPTION
 *  Internal api to free app-based ASM
 *
 * PARAMETERS
 *  mem_ptr:      [IN]   Memory block to be released
 *  file:         [IN]   file to free memory
 *  line:         [IN]   line to free memory
 *  is_anonymous: [IN]   indicate anonymous allocator free
 * RETURNS
 *  void
 *****************************************************************************/
static void applib_mem_ap_free_int(void *mem_ptr, kal_char *file, kal_uint32 line, kal_bool is_anonymous)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mem_header_struct *header;
    kal_uint16 app_id;
    kal_bool is_hide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    header = set_free_info(
        mem_ptr, 
        ASM_ALIGN_SIZE, 
        &g_applib_mem_cntx.app_head, 
        &g_applib_mem_cntx.app_alloc_count, 
        get_file_name(file), line);

    if (is_anonymous)
    {
        MMI_TRACE(PLUTO_FW_TRC_MEM, 
            TRC_MMI_FRM_MEM_APP_ASM_FREE_INT, header->owner_id, header->chunk_size, line, mem_ptr, g_applib_mem_cntx.app_alloc_count);
        MMI_PRINT(MOD_PLUTO_FW, PLUTO_FW_TRC_MEM, "%s", get_file_name(file));
    }
    else
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, 
            TRC_MMI_FRM_MEM_APP_ASM_FREE, header->owner_id, header->chunk_size, line, mem_ptr, g_applib_mem_cntx.app_alloc_count);
        MMI_PRINT(MOD_MMI_FW, MMI_FW_TRC_G1_FRM, "%s", get_file_name(file));
    }
    app_id = header->owner_id;
    is_hide = (header->flag & APPLIB_MEM_HEADER_FLAG_IS_HIDE) ? KAL_TRUE : KAL_FALSE ;

    /* Release the block */
    #if defined __MMI_USE_MMV2__
    kal_flmm_free((KAL_FLMM_ID)g_applib_mem_cntx.app_pool_id, header);
    #else
    kal_adm_free((KAL_ADM_ID)g_applib_mem_cntx.app_pool_id, header);
    #endif

    if (g_applib_mem_cntx.mem_freed_handler)
    {
        g_applib_mem_cntx.mem_freed_handler(app_id, is_hide);
    }

}


#ifdef ASM_VIEWER
#if defined __MMI_USE_MMV2__
/*****************************************************************************
 * FUNCTION
 *  applib_asm_debug_dump_adm_cb
 * DESCRIPTION
 *  FLMM traverse callback functin for ASM Viewer
 *
 * PARAMETERS
 *  flmm_id:      [IN]   Flmm pool ID
 *  info :        [IN]   Flmm memory block info
 *  v_addr:       [IN]   Flmm memory block virtual address
 *  user_data:    [IN]   user data
 * RETURNS
 *  KAL_TRUE means traverse all nodes
 *****************************************************************************/
static kal_bool applib_asm_debug_dump_flmm_cb(KAL_FLMM_ID flmm_id, kal_vm_meminfo_t *info, void *v_addr, void *userdata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE* fp = (FILE*) userdata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (info->slmm == NULL)
    {
        applib_mem_header_struct *p = (info->attr & KAL_VM_NONCACHEABLE) ? info->physical : v_addr;
        if (p->guard_pattern != APPLIB_MEM_HEADER_PATTERN1)
            fprintf(fp, "%d %d %d\n", 0x00, v_addr, info->size);
        else
            fprintf(fp, "%d %d %d\n", p->owner_id, v_addr, info->size);
    }
    else
    {   /*SLMM pool*/
        const kal_uint32 struc_offset = (kal_uint32)(&((applib_mem_slmm_id)0)->applib_mem_header);
        applib_mem_slmm_id asm_slmm_id;
        applib_mem_header_struct *prev_node, *cur_node;
        for (cur_node = &g_applib_mem_cntx.app_head;
             cur_node;
             prev_node = cur_node, cur_node = prev_node->next)
        {
            if ((cur_node->flag & APPLIB_MEM_HEADER_FLAG_IS_SLMM))
            {
                asm_slmm_id = (applib_mem_slmm_id)((kal_uint32)cur_node - struc_offset) ;
                if (asm_slmm_id->kal_slmm_id == info->slmm)
                {
                    break;
                }
            }
        }
        if (cur_node)
        {
            fprintf(fp, "%d %d %d\n", cur_node->owner_id, v_addr, info->size);
        }
        else
        {
            fprintf(fp, "0 0 0\n");
        }
    }
    // return true to continue, or false to stop
    return KAL_TRUE;
}
#else
/*****************************************************************************
 * FUNCTION
 *  applib_asm_debug_dump_adm_cb
 * DESCRIPTION
 *  ADM traverse callback functin for ASM Viewer
 *
 * PARAMETERS
 *  adm_id:       [IN]   ADM pool ID
 *  flags:        [IN]   ADM memory block flags
 *  adm_mb_head:  [IN]   ADM header
 *  user_data:    [IN]   user data
 * RETURNS
 *  KAL_TRUE means traverse all nodes
 *****************************************************************************/
static kal_bool applib_asm_debug_dump_adm_cb(KAL_ADM_ID adm_id, kal_uint32 flags, ADM_MB_HEAD *adm_mb_head, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE* fp = (FILE*) user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((flags & KAL_ADM_MB_INUSE) == KAL_ADM_MB_INUSE)
    {
        kal_uint32 length;
        applib_mem_header_struct *p = (applib_mem_header_struct *)kal_adm_get_buffer(adm_id, adm_mb_head, &length); // alloc pointer

        fprintf(fp, "%d %d %d\n", p->owner_id, (char*)(p + 1) - (char*)g_applib_mem_cntx.app_pool, length);
    }
    else if ((flags & KAL_ADM_MB_FREE) == KAL_ADM_MB_FREE)
    {
        kal_uint32 size = ADM_MB_SIZE(adm_mb_head);
        kal_uint32 length;
        void *p = kal_adm_get_buffer(adm_id, adm_mb_head, &length); // alloc pointer

        fprintf(fp, "%d %d %d\n", 0, (char*)adm_mb_head - (char*)g_applib_mem_cntx.app_pool, length);
    }
    // return true to continue, or false to stop
    return KAL_TRUE;
}
#endif
#endif

/*****************************************************************************
 * FUNCTION
 *  applib_asm_debug_dump
 * DESCRIPTION
 *  dump memory info for ASM Viewer
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/ 
static void applib_asm_debug_dump(void)
{
#ifdef ASM_VIEWER
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE* fp;
    static char srcPath[260] = {0};
    int i, len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    OSC_Sys_Schedule_Enable(0);

    // We only init the path once to improve performance
    if (srcPath[0] == 0)
    {
        GetModuleFileNameA(NULL, srcPath, 260);
        len = strlen(srcPath);

        for(i=0; i<len; i++)
        {
            srcPath[i] = tolower(srcPath[i]);
        }

        for(i=0; i<len; i++)
        {
            if (strncmp(srcPath+i, "modis_vc9", 9)==0)
            {
                srcPath[i + 9] = 0;
                break;
            }
        }

        // cannot match path
        if (i == len - 1)
        {
            srcPath[0] = 0;
            OSC_Sys_Schedule_Enable(1);
            return;
        }

        strcat(srcPath, "\\asm.log");
    }

    fp = fopen(srcPath, "wt");

    if (!fp)
    {
        OSC_Sys_Schedule_Enable(1);
        return;
    }

    fprintf(fp, "%d\n", g_applib_mem_cntx.app_pool_size);
    #if defined __MMI_USE_MMV2__
    kal_flmm_traverse((KAL_FLMM_ID)g_applib_mem_cntx.app_pool_id, 0, applib_asm_debug_dump_flmm_cb, fp);
    #else
    kal_adm_traverse((KAL_ADM_ID)g_applib_mem_cntx.app_pool_id, KAL_ADM_TRAVERSE_NO_CONCHECK, applib_asm_debug_dump_adm_cb, fp);
    #endif
    //mmi_frm_asm_get_reserve_size(KAL_TRUE);

    fclose(fp);

    OSC_Sys_Schedule_Enable(1);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_get_name
 * DESCRIPTION
 *  get application name(resource ID) for both ASM1.0 and ASM2.0 application
 *
 * PARAMETERS
 *  app_id:       [IN]   application ID
 *
 * RETURNS
 *  string ID of application name
 *****************************************************************************/
kal_uint16 applib_mem_ap_get_name(kal_uint32 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mem_app_info_struct app_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_app_info(app_id, &app_info);
    return app_info.name;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_get_single_usage
 * DESCRIPTION
 *  get total memory size of an application includes its sub group
 *  and service belong to it
 *
 * PARAMETERS
 *  app_id:       [IN]   application ID
 *
 * RETURNS
 *  the total memory size of the application
 *****************************************************************************/
kal_uint32 applib_mem_ap_get_single_usage(kal_uint32 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 root_app_id = get_root_app_id(app_id);
    kal_uint32 usage = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    traverse_app_link_list(
        get_app_usage_handler, 
        (void *)root_app_id, 
        (void *)&usage, 
        NULL);
    return usage;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_init
 * DESCRIPTION
 *  Initialize app-based ASM.
 *  (The API is used by MMI framework only)
 * PARAMETERS
 *  stop_finish_callback_by_MMI:    [IN]    callback to handle stopping application result (executed in MMI task)
 *  mem_pool:                       [IN]    memory pool
 *  pool_size:                      [IN]    memory pool size
 * RETURNS
 *  void
 *****************************************************************************/
void applib_mem_ap_init(
                void (*stop_finish_callback_by_MMI)(kal_uint32 app_id, kal_uint32 string_id, kal_bool result), 
                void *mem_pool, 
                kal_uint32 pool_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_applib_mem_cntx.app_pool_inited)
    {
        /* Already initialized */
        return;
    }
    #if defined __MMI_USE_MMV2__
    ASM_ASSERT(mem_pool == mmi_res_get_asm_va_pool() ); /*currently the FLMM_MMI only support one MMI buffer - ASM */
    g_applib_mem_cntx.app_pool_id = (kal_uint32) kal_create_flmm (mem_pool, mmi_res_get_asm_pool_va_size(), 
                                    mmi_res_get_asm_pool(), mmi_res_get_asm_pool_size_wo_flmm_overhead(), 
                                    mmi_res_get_asm_pool_size(), 0);
    #else
    g_applib_mem_cntx.app_pool_id = (kal_uint32) kal_adm_create(
                                        mem_pool, 
                                        pool_size, 
                                        (kal_uint32*) g_applib_mem_pool_chunk_size, 
                                        KAL_FALSE);
    #endif
#ifndef __IOT__
    ASM_ASSERT(stop_finish_callback_by_MMI != NULL);
    g_applib_mem_cntx.app_stop_finish_callback = stop_finish_callback_by_MMI;
#endif //__IOT__
    g_applib_mem_cntx.app_pool_inited = KAL_TRUE;
    g_applib_mem_cntx.app_pool      = mem_pool;
    g_applib_mem_cntx.app_pool_size = pool_size;

#ifdef ASM_USING_MUTEX
    mmi_frm_recursive_mutex_init(&g_applib_mem_cntx.app_asm_mutex, "APP_ASM_MUTEX");
#endif
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_is_initialized
 * DESCRIPTION
 *  check if applib app-asm is initialized
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool applib_mem_ap_is_initialized(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_applib_mem_cntx.app_pool_inited;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_stop_app_by_MMI_task
 * DESCRIPTION
 *  Stop an application. This function must be invoked by MMI task only.
 *  (The API is used by MMI framework only)
 * PARAMETERS
 *  app_id:    [IN]    ID of the application to be stopped
 * RETURNS
 *  void
 *****************************************************************************/
void applib_mem_ap_stop_app_by_MMI_task(kal_uint32 app_id, applib_mem_ap_stop_type stop_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mem_app_stop_info_struct *stop_info_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((stop_info_p = get_app_stop_info((kal_uint16)app_id)) != NULL)
    {
        /* already stopping, just skip */
        if (stop_info_p->is_stopping)
            return;
    }
    else
    {
        stop_info_p = allocate_app_stop_info_space((kal_uint16)app_id);
        stop_info_p->is_auto_registered = KAL_TRUE;
    }

    stop_info_p->is_stopping = KAL_TRUE;

    /* execute registered stop-callback */
    if (stop_info_p->stop_callback != NULL)
    {
        (stop_info_p->stop_callback)((kal_uint16)app_id, stop_type);
        ASM_TRACE(MMI_FRM_ASM_EXECUTE_REGISTER_STOP_CALLBACK, "", 0);
    }
    #ifdef __MMI_SUPPORT_ASMV2__
    else
    /* otherwise, use default stop-callback */
    {
        ASM_ASSERT(g_applib_mem_cntx.app_stop_callback_default);
        g_applib_mem_cntx.app_stop_callback_default((kal_uint16)app_id, stop_type);
    }
    #endif // __MMI_SUPPORT_ASMV2__
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_get_current_usage
 * DESCRIPTION
 *  List memory consumption by current applications 
 *  (The API is used by MMI framework only)
 * PARAMETERS
 *  applist:     [OUT]    List of applications and its memory consumption
 *  max_items:   [IN]     The maximum size of 'applist'
 * RETURNS
 *  the number of applications listed
 *****************************************************************************/
kal_uint32 applib_mem_ap_get_current_usage(applib_mem_ap_usage_struct *applist, kal_uint32 max_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    return applib_mem_ap_get_current_usage_ex(applist, max_items, 0, NULL, 0, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_get_current_usage_ex
 * DESCRIPTION
 *  List memory consumption by current applications 
 *  (The API is used by MMI framework only)
 * PARAMETERS
 *  applist:     [OUT]    List of applications and its memory consumption
 *  max_items:   [IN]     The maximum size of 'applist'
 *  param:    [IN]     include hided app and ASM1.0 app or not
 *  skip_list:   [IN]     the app id list need to skip
 *  skip_count:  [IN]     the app id list length
 * RETURNS
 *  the number of applications listed
 *****************************************************************************/
kal_uint32 applib_mem_ap_get_current_usage_ex(applib_mem_ap_usage_struct *applist, kal_uint32 max_items, U32 param, kal_uint16 *skiplist, U32 skip_count, app_get_usage_check_cb cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 item_count = 0;
    get_asm_usage_para_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: We should handle non-MMI task in the future!
    ASM_ASSERT(mmiapi_is_MMI_task());
    para.max_items = max_items;
    para.param = param;
    para.skiplist = skiplist;
    para.skip_count = skip_count;
    para.cb = cb;

    APP_ASM_LOCK;
    traverse_app_link_list(
        get_app_usage_list_handler, 
        (void *)applist, 
        (void *)&para, 
        (void *)&item_count);
    insert_sort(applist, item_count);
    APP_ASM_UNLOCK;

    return item_count;

}

/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_update_node_flag
 * DESCRIPTION
 *  This function is used to update memory block's flag
 *
 * PARAMETERS
 *  app_id:      [IN]    application ID
 *  flag:        [IN]    The new flag value
 *  is_set:      [IN]    set/clean flag
 * RETURNS
 *  void
 *****************************************************************************/
void applib_mem_ap_update_node_flag(kal_uint16 app_id, kal_uint16 flag, kal_uint32 is_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    traverse_app_link_list(
        update_node_flag_handler, 
        (void *)app_id, 
        (void *)flag, 
        (void *)is_set);
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_register
 * DESCRIPTION
 *  Register an application that uses app-based ASM
 *
 *  Remark: 
 *  1. This function should be used when an application is initialized at boot
 *  2. 'stop_callback_by_MMI' is executed in MMI task. If we need to notify another 
 *     task to stop the application, please send primitive (source module: MOD_MMI)
 *     to the destination task inside the registered function 'stop_callback_by_MMI'.
 * 
 *  This function can be used in non-MMI task.
 * PARAMETERS
 *  app_id:                  [IN]    Application ID defined in applib_mem_ap_id_enum
 *  app_string_id:           [IN]    The MMI string ID of application name
 *  app_icon_id:             [IN]    The MMI image ID of application icon (not used now)
 *  stop_callback_by_MMI:    [IN]    Callback function when user chooses to stop the application
 * RETURNS
 *  void
 *****************************************************************************/
void applib_mem_ap_register(
        kal_uint32 app_id, 
        kal_uint32 app_string_id, 
        kal_uint32 app_icon_id, 
        void (*stop_callback_by_MMI)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mem_app_info_struct app_info;
    applib_mem_app_stop_info_struct *stop_info_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASM_ASSERT(app_string_id);

    app_info.id     = app_id;
    app_info.name   = app_string_id;
    app_info.hide_in_oom  = KAL_FALSE;
    set_static_registered_app_info(&app_info);

    if (stop_callback_by_MMI != NULL)
    {
        if ((stop_info_p = get_app_stop_info((kal_uint16) app_id)) == NULL)
        {
            stop_info_p = allocate_app_stop_info_space((kal_uint16) app_id);
        }
        stop_info_p->stop_callback = (applib_mem_stop_handler_type)stop_callback_by_MMI;
        stop_info_p->is_auto_registered = KAL_FALSE;
    }
}

void applib_mem_ap_set_hide(kal_uint32 app_id, kal_bool hide)
{
    applib_mem_app_info_struct app_info;

    get_app_info(app_id, &app_info);
    app_info.hide_in_oom = hide;
    set_static_registered_app_info(&app_info);
    applib_mem_ap_update_node_flag(app_id, APPLIB_MEM_HEADER_FLAG_IS_HIDE, hide);
}

kal_bool applib_mem_ap_is_hide(kal_uint32 app_id)
{
    applib_mem_app_info_struct app_info;
    get_app_info(app_id, &app_info);
    return app_info.hide_in_oom;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_notify_stop_finished
 * DESCRIPTION
 *  This function is invoked by an application to notify MMI framework when 
 *  it was requested to be stopped and it finished the stop operation.
 *  (Memory used by it are all released)
 *
 *  Warning: This function can only be used in MMI task.
 * PARAMETERS
 *  app_id:      [IN]    ID of the application requested to stop (applib_mem_ap_id_enum)
 *  result:      [IN]    Whether the stop operation succeeded or not
 * RETURNS
 *  void
 *****************************************************************************/
void applib_mem_ap_notify_stop_finished(kal_uint32 app_id, kal_bool result)
{
#ifndef __IOT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mem_app_info_struct app_info;
    applib_mem_app_stop_info_struct *stop_info_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: We should handle non-MMI task in the future!
    ASM_ASSERT(mmiapi_is_MMI_task());
    ASM_TRACE(TRC_MMI_FRM_ASM_NOTIFY_STOP_FINISHED, "[ASM][applib] notify_stop_finished: app_id=%d\n", app_id);

#ifdef DEBUG_KAL
    /* Note: If memory allocated by applib_mem_ap_alloc_full_pool() is released,  
       it should create ADM pool again. */
    ASM_ASSERT(g_applib_mem_cntx.app_pool_id);
    if (result)
    {
        /* Its memory should be released */
        traverse_app_link_list(
            memory_leak_check_handler, 
            (void *)app_id, 
            NULL, 
            NULL);
    }
#endif /* DEBUG_KAL */

    if ((stop_info_p = get_app_stop_info((kal_uint16) app_id)) != NULL)
    {
        /* free or reset stop-info */
        if (stop_info_p->is_auto_registered == KAL_TRUE)
            free_app_stop_info_space((kal_uint16)app_id);
        else
            stop_info_p->is_stopping = KAL_FALSE;

        get_app_info((kal_uint16) app_id, &app_info);
        g_applib_mem_cntx.app_stop_finish_callback(app_id, app_info.name, result);
    }
    else
    {
        ASM_ASSERT(0); /* please register first */
    }
#endif //__IOT__
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_get_max_alloc_size_int
 * DESCRIPTION
 *  internal api of applib_mem_ap_get_max_alloc_size
 *
 *  This function can be used in non-MMI task.
 * PARAMETERS
 *  void
 * RETURNS
 *  Maximum available allocation size in byte
 *****************************************************************************/
kal_uint32 applib_mem_ap_get_max_alloc_size_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 result = 0;
    kal_uint32 overhead;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if defined __MMI_USE_MMV2__
    result = kal_flmm_get_max_alloc_size((KAL_FLMM_ID)g_applib_mem_cntx.app_pool_id);
    #else
    result = kal_adm_get_max_alloc_size((KAL_ADM_ID)g_applib_mem_cntx.app_pool_id);
    #endif
    overhead = sizeof(applib_mem_header_struct) + 31 * 2;
    if (result <= overhead)
    {
        result = 0;
    }
    else
    {
        result -= overhead;
    }

    return result;
}


#ifdef __MMI_SUPPORT_ASMV2__
/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_register_default_stop_callback
 * DESCRIPTION
 *  register default stop-callback. 
 *  default callback will be used when stop-callback is not registered.
 * PARAMETERS
 *  callback :      [IN]        stop callback
 * RETURNS
 *  void
 *****************************************************************************/
void applib_mem_ap_register_default_stop_callback(applib_mem_stop_handler_type callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_applib_mem_cntx.app_stop_callback_default = callback;
}

#endif // __MMI_SUPPORT_ASMV2__
/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_register_pre_alloc_handler
 * DESCRIPTION
 *  callback function called before low level allocation
 *
 * PARAMETERS
 *  handler :      [IN]     pre-allocation callback
 * RETURNS
 *  void
 *****************************************************************************/
void applib_mem_ap_register_pre_alloc_handler(applib_mem_ap_pre_alloc_hdlr handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_applib_mem_cntx.app_pre_alloc_handler = handler;
}


void applib_mem_ap_set_pre_reserve(kal_uint32 size)
{
    g_applib_mem_cntx.pre_reserve_size = size;
}

void applib_mem_ap_register_anonymous_info_handler(applib_mem_ap_anonymous_info_hdlr handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_applib_mem_cntx.app_get_anonymous_reserved_size_handler = handler;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_register_mem_freed_handler
 * DESCRIPTION
 *  register memory freed callback 
 *
 * PARAMETERS
 *  handler :      [IN]  memory freed callback
 * RETURNS
 *  void
 *****************************************************************************/
void applib_mem_ap_register_mem_freed_handler(applib_mem_freed_handler handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_applib_mem_cntx.mem_freed_handler = handler;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_alloc_int
 * DESCRIPTION
 *  Allocate app-based ASM for the general buffer or the frame buffer
 *
 *  Remark:
 *  1. It might return NULL if the allocation failed.
 *  2. Please keep allocation count as few as possible; for example, allocate an
 *     array with 100 elements instead of using applib_mem_ap_alloc() 100 times.
 *
 *     Reason A: the space overheads is hard to estimate when 
 *               underlying implementation is changed.
 *     Reason B: performance is better when there are fewer allocations
 *
 *  This function can be used in non-MMI task. 
 * PARAMETERS
 *  app_id:          [IN]  Application ID
 *  mem_size:        [IN]  Memory size
 *  flag :           [IN]  Identify the memory type
 *  file:            [IN]  file of allocator
 *  line:            [IN]  line number of allocator
 *  is_anonymous     [IN]  if anonymous access
 * RETURNS
 *  Allocated memory block
 *****************************************************************************/
void *applib_mem_ap_alloc_int(kal_uint32 app_id, kal_uint32 mem_size, 
                              asm_alloc_flag alloc_flag, kal_char *file, kal_uint32 line, kal_bool is_anonymous)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 chunk_size =  0;
    void *chunk = NULL;
    kal_uint16 oom_flag = (mmi_frm_is_app_hide_in_oom((MMI_ID)app_id) == MMI_TRUE) ? APPLIB_MEM_HEADER_FLAG_IS_HIDE : 0;
#ifndef __ASM_CACHE_PROMOTION__
    kal_bool is_fb = (alloc_flag & ASM_ALLOC_IS_FB_FLAG) ? KAL_TRUE : KAL_FALSE;
#endif //__ASM_CACHE_PROMOTION__
    #if defined __MMI_USE_MMV2__
    kal_int32 kal_vm_ret = 0 ;
    kal_uint32 kal_vm_option = 0;
    kal_bool is_sw_only = (alloc_flag & ASM_ALLOC_IS_SW_FLAG) ? KAL_TRUE : KAL_FALSE;
    kal_bool use_topmost = (alloc_flag & ASM_ALLOC_IS_TOP_FLAG) ? KAL_TRUE : KAL_FALSE;
    #else
    kal_bool use_topmost = KAL_FALSE;
    #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __IOT__        


    if (g_applib_mem_cntx.app_pre_alloc_handler && g_applib_mem_cntx.app_pre_alloc_handler(app_id, mem_size, mem_size))
    {
        goto allocate_fail;
    }
#endif //__IOT__
    chunk_size = calc_real_alloc_size(mem_size, ASM_ALIGN_SIZE);
    APP_ASM_LOCK;
  #if defined __MMI_USE_MMV2__
    if (is_fb)
    {
        kal_vm_option |= KAL_VM_CONTINUOUS | KAL_VM_LOCKED | KAL_VM_NONCACHEABLE | KAL_VM_DEFRAGMENT;
        if (use_topmost)
        {
            kal_vm_option |= KAL_VM_TOP;
        }
        /* P.S. MMv2 natural __MMI_GDI_LAYER_FRAMEBUF_ALIGNMENT__ aligned due to it's page size = 4KB*/
    }
    else if (is_sw_only)
    {
        kal_vm_option |= KAL_VM_POPULATENOW | KAL_VM_CACHEABLE;
    }
    else
    {
    /*in order to backward compatible, allocate continuous-cacheable buffer to adapt case that buff ptr pass to driver for HW usage*/
        kal_vm_option |= KAL_VM_CONTINUOUS | KAL_VM_LOCKED | KAL_VM_CACHEABLE | KAL_VM_DEFRAGMENT;
    }
    chunk = kal_flmm_alloc((KAL_FLMM_ID)g_applib_mem_cntx.app_pool_id, chunk_size,  
                           kal_vm_option, &kal_vm_ret);
  #else
    if (is_anonymous || use_topmost)
    {
    #if defined(__ASM_CACHE_PROMOTION__)
        chunk = applib_smart_alloc(chunk_size + 40, alloc_flag, ALLOCK_TYPE_ANONYMOUS);
    #else
        if (is_fb)
        {
//            kal_uint32 align_size = __MMI_GDI_LAYER_FRAMEBUF_ALIGNMENT__;
            chunk = kal_adm_alloc_nc_topmost(
                        (KAL_ADM_ID)g_applib_mem_cntx.app_pool_id, 
                        chunk_size, 
                        __MMI_GDI_LAYER_FRAMEBUF_ALIGNMENT__);
        }
        else
        {
            chunk = kal_adm_alloc_topmost(
                        (KAL_ADM_ID) g_applib_mem_cntx.app_pool_id, 
                        chunk_size, 
                        ASM_ALIGN_SIZE);
        }
    #endif //__ASM_CACHE_PROMOTION__
    }
    else
    {
        #if defined(__ASM_CACHE_PROMOTION__)
        chunk = applib_smart_alloc(chunk_size + 40, alloc_flag, ALLOCK_TYPE_APP);
        #else
        if (is_fb)
        {
//            kal_uint32 align_size = __MMI_GDI_LAYER_FRAMEBUF_ALIGNMENT__;
            chunk = kal_adm_alloc_nc_align(
                        (KAL_ADM_ID)g_applib_mem_cntx.app_pool_id, 
                        chunk_size, 
                        __MMI_GDI_LAYER_FRAMEBUF_ALIGNMENT__);
        }
        else
        {
            chunk = kal_adm_alloc_align((KAL_ADM_ID) g_applib_mem_cntx.app_pool_id, 
                        chunk_size, 
                        ASM_ALIGN_SIZE);
        }
        #endif // __ASM_CACHE_PROMOTION__
    }
  #endif
    if (chunk)
    { // alloc success.
        chunk = set_allocation_info(
            chunk, 
            app_id, 
            mem_size, 
            oom_flag, 
            &g_applib_mem_cntx.app_head, &g_applib_mem_cntx.app_alloc_count, 
            get_file_name(file), line);
        APP_ASM_UNLOCK;

#if defined(__ASM_CACHE_PROMOTION__)
        if (app_id != APPLIB_MEM_AP_ID_DUMMY)
        {
            kal_uint32 print_file = 0;
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_DUMP_START);
            kal_adm_traverse((KAL_ADM_ID)g_applib_mem_cntx.app_pool_id, 
                    KAL_ADM_TRAVERSE_NO_CONCHECK, 
                    applib_adm_layout, 
                    &print_file
                    );
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_DUMP_OVER);
        }
#else
        if (is_anonymous)
        {
            MMI_TRACE(PLUTO_FW_TRC_MEM, 
                    TRC_MMI_FRM_MEM_APP_ASM_ALLOC_INT, 
                    app_id, 
                    mem_size, 
                    line, 
                    chunk, 
                    g_applib_mem_cntx.app_alloc_count);
            MMI_PRINT(MOD_PLUTO_FW, PLUTO_FW_TRC_MEM, "%s", get_file_name(file));
        }
        else
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, 
                    TRC_MMI_FRM_MEM_APP_ASM_ALLOC, 
                    app_id, 
                    mem_size, 
                    line, 
                    chunk, 
                    g_applib_mem_cntx.app_alloc_count);
            MMI_PRINT(MOD_MMI_FW, MMI_FW_TRC_G1_FRM, "%s", get_file_name(file));
        }
#endif // __ASM_CACHE_PROMOTION__
        applib_asm_debug_dump();
        return chunk;
    }
    APP_ASM_UNLOCK;
allocate_fail:

    HistoryDump();
#if defined __MMI_USE_MMV2__
    ASM_TRACE(TRC_MMI_FRM_MEM_APP_ASM_ALLOC_FAIL_NOT_ENOUGH, "", app_id, mem_size, line, g_applib_mem_cntx.app_alloc_count, kal_vm_ret);
#else
    ASM_TRACE(TRC_MMI_FRM_MEM_APP_ASM_ALLOC_FAIL_NOT_ENOUGH, "", app_id, mem_size, line, g_applib_mem_cntx.app_alloc_count, 0xFFFFFFFF);
#endif
    return NULL;
}

#ifdef __MED_IN_ASM__
#ifdef __ASM_CACHE_PROMOTION__
static void applib_pre_alloc_to_index(kal_uint32 index, kal_bool is_topmost_dir, kal_uint32 size)
{
    kal_uint32 temp_index;
    kal_uint32 temp_size;
    kal_uint32 pre_alloc_count = 0;

    if (index >= g_applib_mem_cntx.blocks_count)
        return;

    if (is_topmost_dir)
    {
        while (g_applib_mem_cntx.pre_alloc_list[pre_alloc_count] != NULL)
            pre_alloc_count++;
        temp_size = size;
        temp_index = applib_get_first_block(&temp_size, KAL_TRUE, ALLOCK_TYPE_FREE);
        while (temp_index >= index && temp_index < g_applib_mem_cntx.blocks_count)
        {
            g_applib_mem_cntx.pre_alloc_list[pre_alloc_count++] = kal_adm_alloc_topmost(
                (KAL_ADM_ID) g_applib_mem_cntx.app_pool_id, 
                temp_size - (size>>1), 
                0);
            //toDO: update size info.
//            kal_prompt_trace(MOD_MMI, "[ASM] pre alloc = %d", pre_alloc_count - 1);
            while (temp_index < g_applib_mem_cntx.blocks_count && 
                (BLOCK_TYPE(temp_index) == ALLOCK_TYPE_FREE))
            {
                g_applib_mem_cntx.blocks_size_info[temp_index] &= (~ALLOCK_TYPE_MASK);
                g_applib_mem_cntx.blocks_size_info[temp_index] |= ALLOCK_TYPE_ANONYMOUS;
                temp_index++;
            }
            temp_size = size;
            temp_index = applib_get_first_block(&temp_size, KAL_TRUE, ALLOCK_TYPE_FREE);
        }
    }
    else
    {
        kal_uint32 free_pre_count = 0;
        applib_pre_alloc_to_index(index, KAL_TRUE, size);
        while (g_applib_mem_cntx.pre_alloc_list[free_pre_count] != NULL)
            free_pre_count++;
        free_pre_count--;
        applib_pre_alloc_to_index(0, KAL_TRUE, size);
        for(; free_pre_count < MAX_PRE_ALLOC_COUNT; free_pre_count--)
        {

            kal_adm_free((KAL_ADM_ID)g_applib_mem_cntx.app_pool_id, 
                g_applib_mem_cntx.pre_alloc_list[free_pre_count]);
            g_applib_mem_cntx.pre_alloc_list[free_pre_count] = NULL;
            g_applib_mem_cntx.blocks_size_info[free_pre_count] ^= (ALLOCK_TYPE_FREE | ALLOCK_TYPE_APP);
        }
    }
}

static void applib_free_cache_by_index(kal_uint32 index, kal_bool isFreeSSE)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ADM_MB_HEAD* mb_head;
    kal_uint32 length = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (index >= g_applib_mem_cntx.blocks_count)
        return;
    mb_head = g_applib_mem_cntx.block_layout_array[index];

    if ((BLOCK_TYPE(index) == ALLOCK_TYPE_CACHE) || (isFreeSSE && ((BLOCK_TYPE(index) == ALLOCK_TYPE_SSE))))
    {
        applib_mem_header_struct *p = (applib_mem_header_struct *)kal_adm_get_buffer((KAL_ADM_ID)g_applib_mem_cntx.app_pool_id, mb_head, &length);
        if (p->guard_pattern != APPLIB_MEM_HEADER_PATTERN1)
        {
            applib_mem_cache_header_struct *q = (applib_mem_cache_header_struct *)p;

            ASM_ASSERT(q->free_cb);
            q->free_cb(q->user_ptr);
            applib_mem_ap_cache_free_int(q->user_ptr, NULL, 0);
            g_applib_mem_cntx.blocks_size_info[index] &= (~ALLOCK_TYPE_MASK);
            g_applib_mem_cntx.blocks_size_info[index] |= ALLOCK_TYPE_FREE;

        }
    }
}

static kal_uint32 applib_get_first_block(kal_uint32* size, kal_bool is_topmost_dir, kal_uint32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 index;
    kal_uint32 temp = 0;

    kal_uint32 info;
    kal_int32 step;
    kal_uint32 block_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_topmost_dir == KAL_TRUE)
    {
        index = g_applib_mem_cntx.blocks_count - 1;
        step = -1;
    }
    else
    {
        index = 0;
        step = 1;
    }
    while (index < g_applib_mem_cntx.blocks_count)
    {
        info = g_applib_mem_cntx.blocks_size_info[index];
        block_type = info & ALLOCK_TYPE_MASK;
        if ((block_type & type) == block_type)
        {
            temp += (info&(~ALLOCK_TYPE_MASK));
            if (temp > *size)
            {
                break;
            }
        }
        else
        {
            temp = 0;
        }
        index += step;
    }
    *size = temp;
    return index;
}

static kal_bool applib_pre_alloc_start(kal_uint32 mem_size, kal_uint32 analizeType, asm_alloc_flag alloc_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i;
    kal_bool dir;
    kal_uint32 from, to, size_temp;
    kal_uint32 count = g_applib_mem_cntx.blocks_count;

    kal_uint32* analyze = &(g_applib_mem_cntx.blocks_analyze);
    kal_uint32 first_cache = (((*analyze) >> 16) & 0xFF);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(analizeType)
    {
        case ALLOCK_TYPE_CACHE:
        {
            if (mem_size< 10*1024)
            {
                dir = KAL_TRUE;
            }
            else if (g_applib_mem_cntx.pre_reserve_size > 0)
            {
                g_applib_mem_cntx.pre_alloc_list[0] = kal_adm_alloc_nc_align(
                    (KAL_ADM_ID)g_applib_mem_cntx.app_pool_id, 
                    g_applib_mem_cntx.pre_reserve_size + 200, 
                    __MMI_GDI_LAYER_FRAMEBUF_ALIGNMENT__);
                dir = KAL_FALSE;

            }
            else
            {
                g_applib_mem_cntx.pre_alloc_list[0] = kal_adm_alloc_topmost(
                    (KAL_ADM_ID) g_applib_mem_cntx.app_pool_id, 
                    80*1024, 
                    0);

                g_applib_mem_cntx.pre_alloc_list[1] = kal_adm_alloc_topmost(
                    (KAL_ADM_ID) g_applib_mem_cntx.app_pool_id, 
                    80*1024, 
                    0);
                dir = KAL_TRUE;
            }
            break;
        }
        case ALLOCK_TYPE_APP:
        {
            if (g_applib_mem_cntx.pre_reserve_size > 0)
            {
                dir = KAL_FALSE;
            }
            else
            {
                size_temp = mem_size;
                to = applib_get_first_block(&size_temp, KAL_FALSE, ALLOCK_TYPE_CACHE | ALLOCK_TYPE_FREE | ALLOCK_TYPE_SSE);
                for (i = 0; i <= to; i++)
                {
                    applib_free_cache_by_index(i, KAL_TRUE);
                }
                if ((to&0xFF) <= first_cache && first_cache != 0xFF)
                {
                    applib_pre_alloc_to_index(first_cache+1, KAL_TRUE, mem_size);
                }
                else
                {
                    applib_pre_alloc_to_index(to + 1 , KAL_TRUE, mem_size);
                }
            }
            dir = KAL_FALSE;
            break;
        }
        case ALLOCK_TYPE_ANONYMOUS:
        {
            size_temp = mem_size;
            from = applib_get_first_block(&size_temp, KAL_TRUE, ALLOCK_TYPE_CACHE | ALLOCK_TYPE_FREE);
            if (from < count)
            {
                //todo: free all cache from from---> end, 
                for (i = from; i < count; i++)
                {
                    if (BLOCK_SIZE(i) > 10*1024)
                        applib_free_cache_by_index(i, KAL_FALSE);
                }
            }
            dir = KAL_TRUE;
            break;
        }
        default:
            dir = KAL_FALSE;
            break;
    }
    return dir;
}

static void applib_pre_alloc_end(void)
{
    kal_uint32 free_pre_count = 0;

    for(; free_pre_count < MAX_PRE_ALLOC_COUNT; free_pre_count++)
    {
        if (g_applib_mem_cntx.pre_alloc_list[free_pre_count])
        {
            kal_adm_free((KAL_ADM_ID)g_applib_mem_cntx.app_pool_id, 
                g_applib_mem_cntx.pre_alloc_list[free_pre_count]);
            g_applib_mem_cntx.pre_alloc_list[free_pre_count] = NULL;
        }
    }

}

static void* applib_smart_alloc(kal_uint32 mem_size, asm_alloc_flag alloc_flag, kal_uint32 analizeType)
{
    kal_bool is_topmost;
    void* chunk;
//    kal_prompt_trace(MOD_MMI, "[ASM] enter applib_smart_alloc(size = %d, type = %x", mem_size, analizeType);
    g_applib_mem_cntx.blocks_count = 0;
    memset(g_applib_mem_cntx.block_layout_array, 0, MAX_ALLOC_BLOCK_COUNT*sizeof(kal_uint32));
    memset(g_applib_mem_cntx.blocks_size_info, 0, MAX_ALLOC_BLOCK_COUNT*sizeof(kal_uint32));
    memset(g_applib_mem_cntx.pre_alloc_list, 0, MAX_PRE_ALLOC_COUNT*sizeof(kal_uint32));

    g_applib_mem_cntx.blocks_analyze = 0x0FFFFFFFF;
    kal_adm_traverse((KAL_ADM_ID)g_applib_mem_cntx.app_pool_id, 
        KAL_ADM_TRAVERSE_NO_CONCHECK, 
        applib_adm_layout, 
        NULL
        );
    is_topmost = applib_pre_alloc_start(mem_size, analizeType, alloc_flag);
    if (is_topmost)
    {
        if (alloc_flag & ASM_ALLOC_IS_FB_FLAG)
        {
            chunk = kal_adm_alloc_nc_topmost(
                    (KAL_ADM_ID)g_applib_mem_cntx.app_pool_id, 
                    mem_size, 
                    __MMI_GDI_LAYER_FRAMEBUF_ALIGNMENT__);
        }
        else
        {
            chunk = kal_adm_alloc_topmost(
                    (KAL_ADM_ID) g_applib_mem_cntx.app_pool_id, 
                    mem_size, 
                    ASM_ALIGN_SIZE);
        }
    }
    else
    {
        if (alloc_flag & ASM_ALLOC_IS_FB_FLAG)
        {
            chunk = kal_adm_alloc_nc_align(
                        (KAL_ADM_ID)g_applib_mem_cntx.app_pool_id, 
                        mem_size, 
                        __MMI_GDI_LAYER_FRAMEBUF_ALIGNMENT__);
        }
        else
        {
            chunk = kal_adm_alloc_align(
                        (KAL_ADM_ID) g_applib_mem_cntx.app_pool_id, 
                        mem_size, 
                        ASM_ALIGN_SIZE);
        }
    }
    applib_pre_alloc_end();
    if (chunk == NULL)
    {
        if (is_topmost)
        {
            if (alloc_flag & ASM_ALLOC_IS_FB_FLAG)
            {
                chunk = kal_adm_alloc_nc_topmost(
                        (KAL_ADM_ID)g_applib_mem_cntx.app_pool_id, 
                        mem_size, 
                        __MMI_GDI_LAYER_FRAMEBUF_ALIGNMENT__);
            }
            else
            {
                chunk = kal_adm_alloc_topmost(
                        (KAL_ADM_ID) g_applib_mem_cntx.app_pool_id, 
                        mem_size, 
                        ASM_ALIGN_SIZE);
            }
        }
        else
        {
            if (alloc_flag & ASM_ALLOC_IS_FB_FLAG)
            {
                chunk = kal_adm_alloc_nc_align(
                            (KAL_ADM_ID)g_applib_mem_cntx.app_pool_id, 
                            mem_size, 
                            __MMI_GDI_LAYER_FRAMEBUF_ALIGNMENT__);
            }
            else
            {
                chunk = kal_adm_alloc_align(
                            (KAL_ADM_ID) g_applib_mem_cntx.app_pool_id, 
                            mem_size, 
                            ASM_ALIGN_SIZE);
            }
        }
    }
    return chunk;
}

/*****************************************************************************
 * FUNCTION
 *  applib_adm_layout
 * DESCRIPTION
 *  ADM pool traverse call back to layout ADM pool info
 * PARAMETERS
 *  adm_id  :     [IN] ADM ID
 *  flags:        [IN] ADM block flags
 *  adm_mb_head:  [IN] ADM memory block header
 *  user_data:    [IN] user_data
 * RETURNS
 *  KAL_TRUE to traverse all
 *****************************************************************************/
static kal_bool applib_adm_layout(KAL_ADM_ID adm_id, kal_uint32 flags, ADM_MB_HEAD *adm_mb_head, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32* count = &(g_applib_mem_cntx.blocks_count);
    ADM_MB_HEAD** block = g_applib_mem_cntx.block_layout_array;
    kal_uint32* analyze = &(g_applib_mem_cntx.blocks_analyze);
    kal_uint32* info = g_applib_mem_cntx.blocks_size_info;
    kal_uint32 length;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_header_struct *p = (applib_mem_header_struct *)kal_adm_get_buffer(adm_id, adm_mb_head, &length);
    if ((flags & KAL_ADM_MB_INUSE) == KAL_ADM_MB_INUSE)
    {

        block[*count] = adm_mb_head;
        if (p->guard_pattern != APPLIB_MEM_HEADER_PATTERN1)
        {
            applib_mem_cache_header_struct *q = (applib_mem_cache_header_struct *)p;
            if (user_data != NULL)
            {
                ASM_TRACE(TRC_MMI_FRM_ASM_BLOCK_CACHE, "[ASM][pool] CACHE[From %x, size = %d]\n", q->user_ptr, q->size);
            }
            else
            {
                info[*count] = q->size;
                if (q->cache_priority != 0)
                {
                    info[*count] |= ALLOCK_TYPE_CACHE;
                }
                else
                {
                    info[*count] |= ALLOCK_TYPE_SSE;
                }
                if ((*analyze & 0x00FF00FF) == 0x00FF00FF)
                {
                    (*analyze) &= 0x0FF0000FF;
                    (*analyze) |= ((0x0FF & (*count))<<16);
                    (*analyze) |= ((0x0FF & (*count))<<8);
                }
                else if (((*analyze & 0x00FF0000) != 0x00FF0000)&&((*analyze & 0x000000FF) == 0x000000FF))
                {
                    (*analyze) &= 0x0FFFF00FF;
                    (*analyze) |= ((0x0FF & (*count))<<8);
                }
        				(*count) += 1;
            }
        }
        else
        {
            //ASM_TRACE(TRC_MMI_FRM_ASM_DUMP_ALLOC, "[ASM][pool][ptr = 0x%x, id = %d, size = %d]\n", p + 1, p->owner_id, p->chunk_size);

            if (p->owner_id != ASM_ANONYMOUS_ID)
            {
//                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_ASM_BLOC_AP, *count, p + 1, p->chunk_size, ((kal_uint32*)(p+1)) + ((p->chunk_size)>>2));
                if (user_data != NULL)
                {
                    ASM_TRACE(TRC_MMI_FRM_ASM_BLOCK_APP, "[ASM][pool] APP(%d)[From %x, size = %d]\n", p->owner_id, p + 1, p->chunk_size);
#ifdef ASM_DEBUG_LEVEL_3
                    if (*((kal_uint32*)user_data) == 1)
                    {
                        MMI_PRINT(MOD_MMI_FW, MMI_FW_TRC_G1_FRM, "%s(%d)", p->file, p->line);
                    }
#endif //ASM_DEBUG_LEVEL_2
                }
                else
                {
                    info[*count] = p->chunk_size;
                    info[*count] |= ALLOCK_TYPE_APP;
                    (*analyze) &= 0x000000FF;
                    (*analyze) |= 0x00FFFF00;
                    (*analyze) |= ((0x0FF & (*count))<<24);                    
     							  (*count) += 1;
                }

            }
            else
            {
                if (user_data != NULL)
                {
                    ASM_TRACE(TRC_MMI_FRM_ASM_BLOCK_ANONYMOUS, "[ASM][pool] ANONYMOUS[From %x, size = %d]\n", p + 1, p->chunk_size);
#if (defined(ASM_DEBUG_LEVEL_2) || defined(ASM_DEBUG_LEVEL_3))
                    if (*((kal_uint32*)user_data) == 1)
                    {
                        MMI_PRINT(MOD_MMI_FW, MMI_FW_TRC_G1_FRM, "%s(%d)", p->file, p->line);
                    }
#endif //ASM_DEBUG_LEVEL_2
                }
                else
                {
                    info[*count] = p->chunk_size;
                    info[*count] |= ALLOCK_TYPE_ANONYMOUS;
                    if ((*analyze & 0x000000FF) == 0x000000FF)
                    {

                        (*analyze) &= 0x0FFFFFF00;
                        (*analyze) |= (*count);
                    }
        						(*count) += 1;
                }
            }
        }
    }
    else if ((flags & KAL_ADM_MB_FREE) == KAL_ADM_MB_FREE)
    {
        if (length > 30)
        {
            if (user_data != NULL)
            {
                ASM_TRACE(TRC_MMI_FRM_ASM_BLOCK_FREE, "[ASM][pool] FREE[From %x, size = %d]\n", adm_mb_head, length);
            }
            else
            {
                block[*count] = adm_mb_head;
                info[*count] = length;
                info[*count] |= ALLOCK_TYPE_FREE;
                (*count) += 1;
            }
        }
    }
    return KAL_TRUE;
}

#endif // __ASM_CACHE_PROMOTION__


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_cache_alloc_int
 * DESCRIPTION
 *  This API is used to allocate cache memory
 * PARAMETERS
 *  mem_size        : [IN]   mem. size required
 *  alloc_flag      : [IN]   required memory type 
 *  free_cb         : [IN]   cache memory free callback
 *  file            : [IN]   file to allocate cache memory
 *  lien            : [IN]   line to allocate cache memory
 * RETURNS
 *  mem. pointer allocated
 *****************************************************************************/
void *applib_mem_ap_cache_alloc_int(kal_uint32 mem_size, asm_alloc_flag alloc_flag, 
            applib_mem_cache_free_cb_type free_cb, kal_char *file, kal_uint32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mem_cache_header_struct *chunk = NULL;
    void *mem_ptr = NULL;
    kal_uint32 chunk_size = mem_size + sizeof(applib_mem_cache_header_struct);
    #if defined __MMI_USE_MMV2__
    kal_int32 kal_vm_ret;
    #endif //__MMI_USE_MMV2__

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    APP_ASM_LOCK;

    if (alloc_flag & ASM_ALLOC_IS_FB_FLAG)
    {
        #if defined __MMI_USE_MMV2__
        kal_uint32 kal_vm_option;
        kal_vm_option = KAL_VM_CONTINUOUS | KAL_VM_LOCKED | KAL_VM_NONCACHEABLE | KAL_VM_DEFRAGMENT;
        kal_vm_option |= (alloc_flag & ASM_ALLOC_IS_TOP_FLAG) ? KAL_VM_TOP : 0;
        chunk = kal_flmm_alloc((KAL_FLMM_ID)g_applib_mem_cntx.app_pool_id, chunk_size, 
                               kal_vm_option, &kal_vm_ret);
        #else
        #if defined(__ASM_CACHE_PROMOTION__)
        chunk = applib_smart_alloc(chunk_size, alloc_flag, ALLOCK_TYPE_CACHE);
        #else
        chunk = kal_adm_alloc_nc_align(
                    (KAL_ADM_ID)g_applib_mem_cntx.app_pool_id, 
                    chunk_size, 
                    __MMI_GDI_LAYER_FRAMEBUF_ALIGNMENT__);
        #endif //__ASM_CACHE_PROMOTION__
        #endif // __MMI_USE_MMV2__
    }
    else
    {
        #if defined __MMI_USE_MMV2__
        if (alloc_flag == ASM_ALLOC_DEFAULT_FLAG)
            chunk = kal_flmm_alloc((KAL_FLMM_ID)g_applib_mem_cntx.app_pool_id, chunk_size, 
                                   KAL_VM_CONTINUOUS | KAL_VM_LOCKED | KAL_VM_CACHEABLE | KAL_VM_DEFRAGMENT, &kal_vm_ret);
        else if ( alloc_flag == ASM_ALLOC_IS_SW_FLAG)
            chunk = kal_flmm_alloc((KAL_FLMM_ID)g_applib_mem_cntx.app_pool_id, chunk_size, 
                                   KAL_VM_POPULATENOW | KAL_VM_CACHEABLE, &kal_vm_ret);
        else
            ASM_ASSERT(0);
        #else
        #if defined(__ASM_CACHE_PROMOTION__)
            chunk = applib_smart_alloc(chunk_size, alloc_flag, ALLOCK_TYPE_CACHE);
        #else
            chunk = kal_adm_alloc_align((KAL_ADM_ID) g_applib_mem_cntx.app_pool_id, 
                        chunk_size, 
                        ASM_ALIGN_SIZE);
        #endif //__ASM_CACHE_PROMOTION__
        #endif // __MMI_USE_MMV2__
    }

    if (chunk)
    {
        //ASM_ASSERT(chunk->header_guard != APPLIB_MEM_CACHE_HEADER_ALLOCATE);
        memset(chunk, 0, sizeof(applib_mem_cache_header_struct));
        chunk->header_guard = APPLIB_MEM_CACHE_HEADER_ALLOCATE;
        chunk->free_cb    = free_cb;
        chunk->size       = chunk_size;
        chunk->cache_priority = 128;
        chunk->next       = g_applib_mem_cntx.cache_head.next;
        g_applib_mem_cntx.cache_head.next = chunk;
        g_applib_mem_cntx.cache_size += chunk_size;
        mem_ptr = chunk+1;
        chunk->user_ptr = mem_ptr;
    }

    APP_ASM_UNLOCK;
//    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_ASM_CACHE_ALLOC, chunk_size, free_cb, line, mem_ptr);
//    MMI_PRINT(MOD_MMI_FW, MMI_FW_TRC_G1_FRM, "%s", get_file_name(file));

    applib_asm_debug_dump();
    return mem_ptr;
}

/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_cache_set_priority
 * DESCRIPTION
 *  This API is used to set mem priority
 * PARAMETERS
 *  mem_ptr         : [IN]      memory pointer
 *  cache_priority  : [IN]      cache priority, if 0, the cache will be freed after no app can be kill, 
 *                                     else the cache will be freed before kill apps.
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool applib_mem_ap_cache_set_priority(void *mem_ptr, kal_uint32 cache_priority)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mem_cache_header_struct *chunk;
    applib_mem_cache_header_struct *temp_header;
    applib_mem_cache_header_struct *temp_header_pre;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chunk = (applib_mem_cache_header_struct *)mem_ptr;
    temp_header_pre = &(g_applib_mem_cntx.cache_head);
    temp_header = temp_header_pre->next;
    chunk--;
    while (temp_header)
    {
        if (temp_header == chunk)
        {
            chunk->cache_priority = cache_priority;
            temp_header_pre->next = temp_header->next;
            break;
        }
        temp_header_pre = temp_header;
        temp_header = temp_header->next;
    }
    if (temp_header)
    {
        temp_header_pre = &(g_applib_mem_cntx.cache_head);
        while (temp_header_pre->next && (temp_header_pre->next->cache_priority >= temp_header->cache_priority))
        {
            temp_header_pre = temp_header_pre->next;
        }
        temp_header->next = temp_header_pre->next;
        temp_header_pre->next = temp_header;
        return KAL_TRUE;
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_cache_free_int
 * DESCRIPTION
 *  This API is used to free cache memory
 * PARAMETERS
 *  mem_ptr         : [IN]      memory pointer
 *  file            : [IN]      file to free cache memory 
 *  line            : [IN]      line to free cache memory
 * RETURNS
 *  void
 *****************************************************************************/
void applib_mem_ap_cache_free_int(void *mem_ptr, kal_char *file, kal_uint32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mem_cache_header_struct *chunk = ((applib_mem_cache_header_struct *)mem_ptr) - 1;
    applib_mem_cache_header_struct *cache_node;
    kal_uint32 chunk_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_ASM_CACHE_FREE, line, mem_ptr);
        MMI_PRINT(
        MOD_MMI_FW, 
        MMI_FW_TRC_G1_FRM, 
        "%s", 
        get_file_name(file));
        */

    APP_ASM_LOCK;
    //ASM_ASSERT(chunk->header_guard == APPLIB_MEM_CACHE_HEADER_ALLOCATE);
//    memset(chunk, 0, sizeof(applib_mem_cache_header_struct));
    chunk->header_guard = APPLIB_MEM_CACHE_HEADER_FREED;

    /* remove from list */
    cache_node = &g_applib_mem_cntx.cache_head;
    while (cache_node->next)
    {
        if (cache_node->next == chunk)
        {
            cache_node->next = chunk->next;
            break;
        }
        cache_node = cache_node->next;
    }

    chunk_size = chunk->size;

    #if defined __MMI_USE_MMV2__
    kal_flmm_free((KAL_FLMM_ID)g_applib_mem_cntx.app_pool_id, chunk);
    #else
    kal_adm_free((KAL_ADM_ID)g_applib_mem_cntx.app_pool_id, chunk);
    #endif

    g_applib_mem_cntx.cache_size -= chunk_size;
    APP_ASM_UNLOCK;

    applib_asm_debug_dump();
}


void applib_mem_ap_free_all_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mem_cache_header_struct *cache_node = g_applib_mem_cntx.cache_head.next;
    applib_mem_cache_header_struct *next_node;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    APP_ASM_LOCK;
    while (cache_node)
    {
        cache_node->free_cb(cache_node + 1);
        cache_node->header_guard = APPLIB_MEM_CACHE_HEADER_FREED;
        next_node = cache_node->next;
        #if defined __MMI_USE_MMV2__
        kal_flmm_free((KAL_FLMM_ID)g_applib_mem_cntx.app_pool_id, cache_node);
        #else
        kal_adm_free((KAL_ADM_ID)g_applib_mem_cntx.app_pool_id, cache_node);
        #endif
        cache_node = next_node;
    }
    g_applib_mem_cntx.cache_size = 0;
    g_applib_mem_cntx.cache_head.next = NULL;
    APP_ASM_UNLOCK;
}

/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_cache_get_size
 * DESCRIPTION
 *  This API is used to get total cache memory size in the ASM buffer pool
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint32 applib_mem_ap_cache_get_size()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_applib_mem_cntx.cache_size;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_cache_free_till_enough_int
 * DESCRIPTION
 *  This function will try to free cache memory which cache priority > 0 until enough.
 * PARAMETERS
 *  size        : [IN] the memory size of high level user needs
 *  is_continuous:[IN] identify if require continuous memory (set KAL_TRUE in !__MMI_USE_MMV2__ case)
 *  file        : [IN] file
 *  line        : [IN] line
 * RETURNS
 *  KAL_TRUE means memory is enough, KAL_FALSE means memory is not enough
 *****************************************************************************/
kal_bool applib_mem_ap_cache_free_till_enough_int(kal_uint32 size, kal_bool is_continuous, kal_char *file, kal_uint32 line)
{
#if defined(__ASM_CACHE_PROMOTION__)
    return KAL_TRUE;
#else
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mem_cache_header_struct *cache_node = g_applib_mem_cntx.cache_head.next;
    applib_mem_cache_header_struct *temp_node = NULL;
    applib_mem_cache_header_struct *next_node;
    kal_uint32 cache_size = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    APP_ASM_LOCK;

    while (cache_node)
    {
        ASM_TRACE(
            TRC_MMI_FRM_MEM_APP_ASM_CACHE_FREE_TILL_ENOUGH_CB_INVOKE, 
            "", 
            cache_node->free_cb, 
            cache_node + 1);
        ASM_ASSERT(cache_node->free_cb);
        cache_node->free_cb(cache_node + 1);
        cache_node->header_guard = APPLIB_MEM_CACHE_HEADER_FREED;
        cache_size = cache_node->size;
        next_node = cache_node->next;

        #if defined __MMI_USE_MMV2__
        kal_flmm_free((KAL_FLMM_ID)g_applib_mem_cntx.app_pool_id, cache_node);
        #else
        kal_adm_free((KAL_ADM_ID)g_applib_mem_cntx.app_pool_id, cache_node);
        #endif

        g_applib_mem_cntx.cache_size -= cache_size;

        if (applib_mem_ap_check_enough_try_alloc(size, is_continuous))
        {
            if (temp_node == NULL)
            {
                g_applib_mem_cntx.cache_head.next = next_node;
            }
            APP_ASM_UNLOCK;
            return KAL_TRUE;
        }
        cache_node = next_node;
    }
    g_applib_mem_cntx.cache_head.next = temp_node;
    APP_ASM_UNLOCK;
    applib_asm_debug_dump();
    return KAL_FALSE;
#endif // __ASM_CACHE_PROMOTION__
}

#endif
/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_check_enough_try_alloc
 * DESCRIPTION
 *  This API is for framework internal use. Please do not use it in normal case.
 * PARAMETERS
 *  size         : [IN]     the memory size of high level user needs
 *  is_continuous: [IN]     identify if require continuous memory (set KAL_TRUE in !__MMI_USE_MMV2__)
 * RETURNS
 *  KAL_TRUE if try allocate success or return KAL_FALSE
 *****************************************************************************/
kal_bool applib_mem_ap_check_enough_try_alloc(kal_uint32 size, kal_bool is_continuous)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #if defined __MMI_USE_MMV2__
    /*kal_int32 kal_vm_ret;*/
    kal_bool ret_val;
    #else
    void *chunk = NULL;
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    size = calc_real_alloc_size(size, ASM_ALIGN_SIZE);
    #if defined __MMI_USE_MMV2__

    APP_ASM_LOCK;
    if (is_continuous)
    {
        ret_val = kal_flmm_is_allocatable((KAL_FLMM_ID)g_applib_mem_cntx.app_pool_id, size, 
                               KAL_VM_CONTINUOUS | KAL_VM_LOCKED | KAL_VM_NONCACHEABLE | KAL_VM_DEFRAGMENT);
        /*chunk = kal_flmm_alloc((KAL_FLMM_ID)g_applib_mem_cntx.app_pool_id, size, 
                               KAL_VM_CONTINUOUS | KAL_VM_LOCKED | KAL_VM_NONCACHEABLE | KAL_VM_DEFRAGMENT, &kal_vm_ret);*/
    }
    else
    {
        ret_val = kal_flmm_is_allocatable((KAL_FLMM_ID)g_applib_mem_cntx.app_pool_id, size, 
                               KAL_VM_ONDEMAND_RESERVENOW | KAL_VM_CACHEABLE);
        /*chunk = kal_flmm_alloc((KAL_FLMM_ID)g_applib_mem_cntx.app_pool_id, size, 
                               KAL_VM_ONDEMAND_RESERVENOW | KAL_VM_CACHEABLE, &kal_vm_ret);*/
    }

    APP_ASM_UNLOCK;
    return ret_val;

    #else

    APP_ASM_LOCK;
    chunk = kal_adm_alloc_align(
                (KAL_ADM_ID)g_applib_mem_cntx.app_pool_id, 
                size, 
                ASM_ALIGN_SIZE);
    if (chunk)
    {
        kal_adm_free((KAL_ADM_ID)g_applib_mem_cntx.app_pool_id, chunk);

        APP_ASM_UNLOCK;
        return KAL_TRUE;
    }
    else
    {
        APP_ASM_UNLOCK;
        return KAL_FALSE;
    }
    #endif    
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_alloc_full_pool_int
 * DESCRIPTION
 *  Allocate the whole pool of app-based ASM *
 *
 * PARAMETERS
 *  app_id          :[IN]        ID of owner application
 *  pool_size       :[OUT]       Allocated size
 *  line            :[IN]        line to allocate memory
 * RETURNS
 *  Allocated memory block
 *****************************************************************************/
void *applib_mem_ap_alloc_full_pool_int(kal_uint32 app_id, kal_uint32 *pool_size, kal_uint32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 mem_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    APP_ASM_LOCK;
    mem_size = applib_mem_ap_get_max_alloc_size_int();
    if (g_applib_mem_cntx.app_alloc_count)
    {
        *pool_size = 0;
        APP_ASM_UNLOCK;
        ASM_TRACE(TRC_MMI_FRM_MEM_APP_ASM_ALLOC_FULL_POOL_FAIL, "", app_id, line);
        return NULL;
    }
    *pool_size = mem_size;
    APP_ASM_UNLOCK;
    return applib_mem_ap_alloc_int(app_id, mem_size, ASM_ALLOC_DEFAULT_FLAG, NULL, line, KAL_FALSE);
}

#if defined __MMI_USE_MMV2__
/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_create_slmm_pool
 * DESCRIPTION
 *  
 *
 *  
 *  
 * PARAMETERS
 *  app_id          [IN]        ID of owner application (applib_mem_ap_id_enum)
 *  pool_size       [OUT]       Allocated size (== the whole pool size)
 * RETURNS
 *  Allocated memory block
 *****************************************************************************/
applib_mem_slmm_id applib_mem_ap_create_slmm_pool (kal_uint32 app_id, kal_uint32 mem_size, 
                                                    kal_uint32 is_log, kal_uint32 is_slmm_log)
{
    KAL_SLMM_ID my_slmm_id;
    applib_mem_header_struct* header;
    applib_mem_slmm_id asm_slmm_id;
    kal_int32 kal_vm_ret;
    const char* fn;

    APP_ASM_LOCK;
    my_slmm_id = kal_create_slmm((KAL_FLMM_ID)g_applib_mem_cntx.app_pool_id, mem_size, 
                                 is_slmm_log ? KAL_SLMM_RECORD_LOCATION : 0);
    ASM_ASSERT(my_slmm_id != 0x00);
    if (is_slmm_log & APPLIB_MEM_SLMM_LOG_W_RETURN_ADDR)
    {
        APPLIB_MEM_FILL_FILENAME(fn);
    }
    else
    {
        fn = __FILE__;
    }
    asm_slmm_id = (applib_mem_slmm_id) kal_slmm_alloc_dbg (my_slmm_id, sizeof(*asm_slmm_id), 
                 KAL_VM_POPULATENOW | KAL_VM_CACHEABLE, &kal_vm_ret, (kal_char*) fn, __LINE__);

    header = &asm_slmm_id->applib_mem_header;
    asm_slmm_id->kal_slmm_id = my_slmm_id ;
    asm_slmm_id->log_flag = is_slmm_log;
    asm_slmm_id->shrunk_heap_list.next = 0x00;
    asm_slmm_id->shrunk_heap_list.shrunk_size = 0x00;
    /* header */
    header->owner_id = app_id;
    header->chunk_size = mem_size;
    header->flag = APPLIB_MEM_HEADER_FLAG_IS_SLMM;
    header->flag |= (mmi_frm_is_app_hide_in_oom((MMI_ID)app_id) == MMI_TRUE) ? APPLIB_MEM_HEADER_FLAG_IS_HIDE : 0;
    header->guard_pattern = APPLIB_MEM_HEADER_PATTERN1;
    /* update linked list */
    header->next = g_applib_mem_cntx.app_head.next;
    g_applib_mem_cntx.app_head.next = header;
    /* system context */
    g_applib_mem_cntx.app_alloc_count++;

    APP_ASM_UNLOCK;
    if (is_log)
    {
        MMI_PRINT(
            MOD_MMI_FW, 
            MMI_FW_TRC_G1_FRM, 
            "[ASM][applib][slmm] creator id = %d, size = %d, kal_slmm_id = 0x%x", 
            app_id, 
            mem_size, 
            my_slmm_id);
    }

    applib_asm_debug_dump();

    return asm_slmm_id;
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 *
 *  
 *  
 * PARAMETERS
 *  app_id          [IN]        ID of owner application (applib_mem_ap_id_enum)
 *  pool_size       [OUT]       Allocated size (== the whole pool size)
 * RETURNS
 *  Allocated memory block
 *****************************************************************************/
kal_status applib_mem_ap_delete_slmm_pool (applib_mem_slmm_id asm_slmm_id, kal_bool is_log)
{
    KAL_SLMM_ID my_slmm_id;
    applib_mem_header_struct *header, *prev_node, *remove_node;
    kal_uint32 app_id, mem_size;
    kal_status retValue;

    if (kal_slmm_get_alloc_count(asm_slmm_id->kal_slmm_id) > 1)
    {
        return KAL_ERROR;
    }
    APP_ASM_LOCK;
    /*remove the node from shrunk heap list*/
    applib_mem_ap_slmm_set_shrunk_heap_size(asm_slmm_id, 0);
    header = &(asm_slmm_id->applib_mem_header);
    /* 
     * Remove the block from linked list 
     *
     * It is not a fast algorithm, we can improve it by using double linked list, 
     * but we choose simpler design because
     * 1. Typically total allocation count is small
     * 2. We don't want to increase space overheads
     * 3. We don't want to access KAL ADM internal data structure
     */
    prev_node = &g_applib_mem_cntx.app_head;
    ASM_ASSERT(prev_node->next);
    for (remove_node = prev_node->next;
         remove_node;
         prev_node = remove_node, remove_node = prev_node->next)
    {
        if (remove_node == header)
        {
            break;
        }
    }
    ASM_ASSERT(remove_node);
    prev_node->next = remove_node->next;

    /* Set guard pattern */
    header->guard_pattern = APPLIB_MEM_HEADER_PATTERN2;
    ASM_ASSERT(g_applib_mem_cntx.app_alloc_count > 0);
    g_applib_mem_cntx.app_alloc_count--;
    /*remember some members then free it*/
    app_id = header->owner_id;
    mem_size = header->chunk_size;
    my_slmm_id = asm_slmm_id->kal_slmm_id;
    kal_slmm_free(my_slmm_id, asm_slmm_id);
    retValue = kal_slmm_delete((KAL_SLMM_ID)my_slmm_id);
    APP_ASM_UNLOCK;
    if (is_log)
    {
        MMI_PRINT(
            MOD_MMI_FW, 
            MMI_FW_TRC_G1_FRM, 
            "[ASM][applib][slmm] deletor id = %d, size = %d, kal_slmm_id = 0x%x", 
            app_id, 
            mem_size, 
            my_slmm_id);
    }


    return retValue;
}
/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 *
 *  
 *  
 * PARAMETERS
 *  app_id          [IN]        ID of owner application (applib_mem_ap_id_enum)
 *  pool_size       [OUT]       Allocated size (== the whole pool size)
 * RETURNS
 *  Allocated memory block
 *****************************************************************************/
void *applib_mem_ap_slmm_alloc_dbg (applib_mem_slmm_id asm_slmm_id, kal_uint32 size, 
                                    asm_alloc_flag flag, kal_uint32 filename, kal_uint32 line, kal_bool is_log)
{
    void * retVal = NULL;
    kal_int32 kal_vm_ret = 0;
    if (flag == ASM_ALLOC_DEFAULT_FLAG)
    {
        retVal = kal_slmm_alloc_dbg (asm_slmm_id->kal_slmm_id, size, 
                                     KAL_VM_CONTINUOUS | KAL_VM_LOCKED | KAL_VM_CACHEABLE | KAL_VM_DEFRAGMENT, 
                                     &kal_vm_ret, (kal_char*)filename, line);
    }
    else if (flag == ASM_ALLOC_IS_FB_FLAG)
    {
        retVal = kal_slmm_alloc_dbg (asm_slmm_id->kal_slmm_id, size, 
                                     KAL_VM_CONTINUOUS | KAL_VM_LOCKED | KAL_VM_NONCACHEABLE | KAL_VM_DEFRAGMENT, 
                                     &kal_vm_ret, (kal_char*)filename, line);
    }
    else if ( flag == ASM_ALLOC_IS_SW_FLAG)
    {
        retVal = kal_slmm_alloc_dbg (asm_slmm_id->kal_slmm_id, size, 
                                     KAL_VM_POPULATENOW | KAL_VM_CACHEABLE, 
                                     &kal_vm_ret, (kal_char*)filename, line);
    }
    else
    {
        ASM_ASSERT(0); /*unknown flag*/
    }
    if (retVal != NULL)
    {
    if (is_log)
    {
        MMI_PRINT(
            MOD_MMI_FW, 
            MMI_FW_TRC_G1_FRM, 
                "[ASM][applib][slmm] alloc app id = %d, ptr = 0x%x, size = %d", 
                asm_slmm_id->applib_mem_header.owner_id, 
                retVal, 
                size);
        }
    }
    else
    {
        MMI_PRINT(
            MOD_MMI_FW, 
            MMI_FW_TRC_G1_FRM, 
            "[ASM][applib][slmm] alloc fail. alloc app id = %d, size = %d, kal_vm_ret = %d", 
            asm_slmm_id->applib_mem_header.owner_id, 
            retVal, 
            size, 
            kal_vm_ret);
    }
    return retVal;
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 *
 *  
 *  
 * PARAMETERS
 *  app_id          [IN]        ID of owner application (applib_mem_ap_id_enum)
 *  pool_size       [OUT]       Allocated size (== the whole pool size)
 * RETURNS
 *  Allocated memory block
 *****************************************************************************/
kal_uint32 applib_mem_ap_slmm_free (applib_mem_slmm_id asm_slmm_id, void *ptr, kal_bool is_log)
{
    ASM_ASSERT(kal_slmm_get_alloc_count(asm_slmm_id->kal_slmm_id) > 1);
    kal_slmm_free (asm_slmm_id->kal_slmm_id, ptr);
    if (is_log)
    {
        MMI_PRINT(
            MOD_MMI_FW, 
            MMI_FW_TRC_G1_FRM, 
            "[ASM][applib][slmm] free app id = %d, ptr = 0x%x", 
            asm_slmm_id->applib_mem_header.owner_id, 
            ptr);
    }
    return 0;
}

kal_uint32 applib_mem_ap_get_slmm_total_left_size(applib_mem_slmm_id asm_slmm_id)
{
    return kal_slmm_get_total_left_size(asm_slmm_id->kal_slmm_id);
}

void* applib_mem_ap_slmm_check(applib_mem_slmm_id asm_slmm_id)
{
    return kal_slmm_check_integrity(asm_slmm_id->kal_slmm_id);
}

kal_uint32 applib_mem_ap_get_slmm_vm_start(applib_mem_slmm_id asm_slmm_id)
{
    return kal_slmm_vm_start(asm_slmm_id->kal_slmm_id);
}

kal_uint32 applib_mem_ap_get_slmm_vm_end(applib_mem_slmm_id asm_slmm_id)
{
    return kal_slmm_vm_end(asm_slmm_id->kal_slmm_id);
}

kal_int32 applib_mem_ap_slmm_limit_size(applib_mem_slmm_id asm_slmm_id, kal_uint32 new_size)
{
    return kal_slmm_limit(asm_slmm_id->kal_slmm_id, new_size);
}

mmi_id applib_mem_ap_get_slmm_owner_id(applib_mem_slmm_id asm_slmm_id)
{
    return asm_slmm_id->applib_mem_header.owner_id ;
}

KAL_SLMM_ID applib_mem_ap_get_kal_slmm_id(applib_mem_slmm_id asm_slmm_id)
{
    return asm_slmm_id->kal_slmm_id ;
}

kal_uint32 applib_mem_ap_get_slmm_log_flag(applib_mem_slmm_id asm_slmm_id)
{
    return asm_slmm_id->log_flag;
}

kal_uint32 applib_mem_ap_slmm_update_header_flag (applib_mem_slmm_id asm_slmm_id, kal_uint16 flag, kal_uint32 is_set)
{
    applib_mem_header_struct *header;
    mmi_id root_id;
    APP_ASM_LOCK;
    header = &asm_slmm_id->applib_mem_header;
    root_id = get_root_app_id(header->owner_id);
    update_node_flag_handler(header, (void *)root_id, (void *)flag, (void *)is_set);
    APP_ASM_UNLOCK;
    return 0;
}

kal_uint32 applib_mem_ap_slmm_set_shrunk_heap_size(applib_mem_slmm_id asm_slmm_id, kal_uint32 size)
{
    applib_shrunk_heap_list *header, *prev_node, *node;

    header = &asm_slmm_id->shrunk_heap_list;
    APP_ASM_LOCK;
    asm_slmm_id->applib_mem_header.chunk_size += header->shrunk_size;
    asm_slmm_id->applib_mem_header.chunk_size -= size;
    header->shrunk_size = size;
    /*check if the header in already in the shrunk_heap_list*/
    prev_node = &g_applib_shrunk_heap_list;
    for (node = prev_node->next;
         node;
         prev_node = node, node = prev_node->next)
    {
        if (node == header)
            break;
    }
    if ( size && node == 0 )
    {    /*insert node to list*/
        header->next = g_applib_shrunk_heap_list.next;
        g_applib_shrunk_heap_list.next = header;
    }
    else if ( size == 0 && node )
    {    /*remove node from list*/
        prev_node->next = node->next;
    }
    else if ( size && node )
    { /*set shrunk size & node is already in the list*/
        /*Do nothing*/
    }
    else if ( !size && !node )
    { /* shrunk size == 0 & node is not in the list*/
        /*Do nothing*/
    }

    APP_ASM_UNLOCK;
    return 0;
}

kal_uint32 applib_mem_ap_slmm_get_shrunk_heap_size_by_ID(mmi_id app_id)
{
    applib_shrunk_heap_list *prev_node, *node;
    applib_mem_slmm_id asm_slmm_id;
    kal_uint32 shrunk_size;
    const kal_uint32 struc_offset = (kal_uint32)(&((applib_mem_slmm_id)0)->shrunk_heap_list);
    APP_ASM_LOCK;
    prev_node = &g_applib_shrunk_heap_list;
    for (node = prev_node->next;
         node;
         prev_node = node, node = prev_node->next)
    {
        asm_slmm_id = (applib_mem_slmm_id)((kal_uint32)node - struc_offset) ;
        if (asm_slmm_id->applib_mem_header.owner_id == app_id)
            break;
    }
    if (node == 0)
        shrunk_size = 0;
    else
        shrunk_size = node->shrunk_size;

    APP_ASM_UNLOCK;
    return shrunk_size;
}

kal_uint32 applib_mem_ap_slmm_get_shrunk_heap_size(applib_mem_slmm_id asm_slmm_id)
{
    return asm_slmm_id->shrunk_heap_list.shrunk_size;
}

kal_uint32 applib_mem_ap_slmm_get_used_page_size(applib_mem_slmm_id asm_slmm_id)
{
    return kal_slmm_get_committed_size(asm_slmm_id->kal_slmm_id);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_dump
 * DESCRIPTION
 *  function used to dump asm pool layout
 *
 * PARAMETERS
 *  app_id          :[IN]        ID of owner application
 *  pool_size       :[OUT]       Allocated size
 *  line            :[IN]        line to allocate memory
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __32_32_SEG__ 
void applib_mem_ap_dump(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__ASM_CACHE_PROMOTION__)
    kal_uint32 print_file = 1;
#endif //__ASM_CACHE_PROMOTION__
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MED_IN_ASM__
    APP_ASM_LOCK;
    #if defined __MMI_USE_MMV2__
    kal_flmm_traverse((KAL_FLMM_ID)g_applib_mem_cntx.app_pool_id, 0x00, print_flmm_memory_block, 0);
    #else
#if defined(__ASM_CACHE_PROMOTION__)
    kal_adm_traverse((KAL_ADM_ID)g_applib_mem_cntx.app_pool_id, 
        KAL_ADM_TRAVERSE_NO_CONCHECK, 
        applib_adm_layout, 
        &print_file
        );
#else
    kal_adm_traverse((KAL_ADM_ID)g_applib_mem_cntx.app_pool_id, KAL_ADM_TRAVERSE_NO_CONCHECK, print_adm_memory_block, 0);
#endif //__ASM_CACHE_PROMOTION__

#endif  //__MMI_USE_MMV2__  
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_DUMP_OVER);
    APP_ASM_UNLOCK;
#endif //__MED_IN_ASM__
}
#endif


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_free_thread_safe
 * DESCRIPTION
 *  Free app-based ASM
 *
 *  This function can be used in non-MMI task.
 * PARAMETERS
 *  mem_ptr:      [IN]   Memory block to be released
 *  file:         [IN]   file to free memory
 *  line:         [IN]   line to free memory
 *  is_anonymous: [IN]   indicate anonymous allocator free      
 * RETURNS
 *  void
 *****************************************************************************/
void applib_mem_ap_free_thread_safe(void *mem_ptr, kal_char *file, kal_uint32 line, kal_bool is_anonymous)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    APP_ASM_LOCK;
    applib_mem_ap_free_int(mem_ptr, file, line, is_anonymous);
    APP_ASM_UNLOCK;
    applib_asm_debug_dump();
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_free_all
 * DESCRIPTION
 *  Release all app-based ASM belong to an application
 *
 *  This function can be used in non-MMI task.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void applib_mem_ap_free_all(kal_uint32 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mem_header_struct *node, *next;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    APP_ASM_LOCK;
    node = g_applib_mem_cntx.app_head.next;
    while (node)
    {
        next = node->next;
        if (node->owner_id == app_id)
        {
            applib_mem_ap_free_int(node + 1, "T", __LINE__, KAL_FALSE);
        }
        node = next;
    }
    APP_ASM_UNLOCK;
    applib_asm_debug_dump();
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_get_total_left_size_int
 * DESCRIPTION
 *  Internal function for applib_mem_ap_get_total_left_size
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  Total left space in byte
 *****************************************************************************/
kal_uint32 applib_mem_ap_get_total_left_size_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if defined __MMI_USE_MMV2__
    result = kal_flmm_get_total_left_size((KAL_FLMM_ID)g_applib_mem_cntx.app_pool_id);
    #else
    result = kal_adm_get_total_left_size((KAL_ADM_ID)g_applib_mem_cntx.app_pool_id);
    #endif
    if (result <= sizeof(applib_mem_header_struct))
    {
        result = 0;
    }
    else
    {
        result -= sizeof(applib_mem_header_struct);
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_get_total_left_size
 * DESCRIPTION
 *  Get available size of app-based ASM.
 *
 *  Remark: this function is only suggested for *debug* purpose because
 *  1. The memory pool may be fragmented (total left free space is meaningless 
 *     if the pool has serious memory fragmentation)
 *  2. Even if the free space is contiguous, sometimes we still cannot allocate 10 * 10KB blocks 
 *     with 100KB free space because of the overheads of memory management bookkeeping
 *
 *  Please use applib_mem_ap_get_max_alloc_size() or applib_mem_ap_get_pool_size()
 *  instead.
 *
 *  This function can be used in non-MMI task.
 * PARAMETERS
 *  void
 * RETURNS
 *  Total left space in byte
 *****************************************************************************/
kal_uint32 applib_mem_ap_get_total_left_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 result = 0;
    kal_uint32 total_left;
#ifdef __MED_IN_ASM__
    kal_uint32 reserve_size;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    APP_ASM_LOCK;
    total_left      = applib_mem_ap_get_total_left_size_int();
#if (defined(__MED_IN_ASM__) && defined(__MMI_SUPPORT_ASMV2__))
    mmi_frm_asm_get_reserve_size(&reserve_size, NULL);
    result = (total_left > reserve_size) ? total_left - reserve_size : 0;
#else
    result = total_left;
#endif
    APP_ASM_UNLOCK;
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_get_max_alloc_size
 * DESCRIPTION
 *  Get the max possible size of single allocation from app-based ASM. 
 *  Return value of it is typically less than applib_mem_ap_get_total_left_size()
 *  if the pool is fragmented.
 *
 *  Remark: we can use this function to dynamically decide the allocation size 
 *  (for example, use larger image cache when there is more memory)
 *  
 *  However, sometimes we cannot allocate 2 * 10KB blocks if the maximum allocation size 
 *  is 20KB because of the overheads of memory management bookkeeping. 
 *
 *  It is suggested to use "fail-safe" allocation regardless the internal 
 *  implementation of ASM if we want to allocate more memory adaptively according
 *  to the free space
 *  Step 1. Decide the size of free space => e.g. 100KB
 *  Step 2. Allocate 100KB
 *  Step 3. If failed, allocate 95 KB
 *  Step 4. If failed, allocate 90 KB
 *  Step 5. ...
 *
 *  This function can be used in non-MMI task.
 * PARAMETERS
 *  void
 * RETURNS
 *  Maximum available allocation size in byte
 *****************************************************************************/
kal_uint32 applib_mem_ap_get_max_alloc_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 result = 0;
    kal_uint32 max_size;
#ifdef __MED_IN_ASM__
    kal_uint32 total_left;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    APP_ASM_LOCK;
    max_size        = applib_mem_ap_get_max_alloc_size_int();
#ifdef __MED_IN_ASM__
    total_left      = applib_mem_ap_get_total_left_size();
    result = (max_size > total_left) ? total_left : max_size;
#else
    result = max_size;
#endif
    APP_ASM_UNLOCK;
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_get_pool_size
 * DESCRIPTION
 *  Return the fixed size of app-based ASM pool
 *
 *  Remark: we can use this function to decide the maximum possible memory 
 *  we can allocate (the whole pool size).
 * 
 *  However, sometimes we cannot allocate 10 * 10KB blocks in an 100KB memory pool
 *  because of the overheads of memory management bookkeeping. 
 *  
 *  It is suggested to use "fail-safe" allocation regardless the internal 
 *  implementation of ASM if we want to allocate more memory adaptively according
 *  to the pool size:
 *  Step 1. Decide the size of free space => e.g. 100KB
 *  Step 2. Allocate 100KB
 *  Step 3. If failed, allocate 95 KB
 *  Step 4. If failed, allocate 90 KB
 *  Step 5. ...
 *
 *  This function can be used in non-MMI task. 
 * PARAMETERS
 *  void
 * RETURNS
 *  Pool size in byte
 *****************************************************************************/
kal_uint32 applib_mem_ap_get_pool_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if defined __MMI_USE_MMV2__
    ASM_ASSERT(g_applib_mem_cntx.app_pool == mmi_res_get_asm_va_pool());
    return mmi_res_get_asm_pool_size_wo_flmm_overhead() - APPLIB_MEM_CHUNK_EXTRA_SIZE;
    #else
    return g_applib_mem_cntx.app_pool_size - APPLIB_MEM_POOL_EXTRA_SIZE - APPLIB_MEM_CHUNK_EXTRA_SIZE;
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_get_alloc_count
 * DESCRIPTION
 *  Return the number of allocated blocks
 *
 *  This function can be used in non-MMI task. 
 * PARAMETERS
 *  void
 * RETURNS
 *  The number of allocated blocks
 *****************************************************************************/
kal_uint32 applib_mem_ap_get_alloc_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_applib_mem_cntx.app_alloc_count;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_is_valid_block
 * DESCRIPTION
 *  Check if a app-based ASM memory block is valid by inspecting its guard patterns.
 *
 *  This function can be used in non-MMI task. 
 * PARAMETERS
 *  mem_ptr     [IN]        Memory block to check
 * RETURNS
 *  Return KAL_TRUE if 'mem_ptr' is a valid block
 *****************************************************************************/
kal_bool applib_mem_ap_is_valid_block(void *mem_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    APP_ASM_LOCK;
    result = is_valid_block(mem_ptr, ASM_ALIGN_SIZE);
    APP_ASM_UNLOCK;
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_check_integrity
 * DESCRIPTION
 *  Check if the internal state of app-based ASM is correct. 
 *  If not, then ASSERT!
 *
 *  Remark: This function takes a lot of computation time, and it should not be
 *  used in normal case. 
 *  The function call can be inserted in application code when we need to locate 
 *  hard-to-find memory corruption issue.
 *
 *  This function can be used in non-MMI task. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void applib_mem_ap_check_integrity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    traverse_app_link_list(
        ap_integrity_check_handler, 
        NULL, 
        NULL, 
        NULL);
}

/***************************************************************************** 
 * Screen-based ASM 
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  applib_mem_screen_alloc_int
 * DESCRIPTION
 *  Allocate screen-based ASM for the general buffer or the frame buffer
 *
 *  Remark:
 *  1. It might return NULL if the allocate failed.
 *  2. Please keep allocation count as few as possible; for example, allocate an
 *     array with 100 elements instead of using applib_mem_screen_alloc() 100 times.
 *
 *     Reason A: the space overheads is hard to estimate when 
 *               underlying implementation is changed.
 *     Reason B: performance is better when there are fewer allocations
 *
 * 
 * PARAMETERS
 *  mem_size        : [IN] Memory size
 *  is_framebuffer  : [IN] Need non-cacheable memory
 *  line            : [IN] line number of allocator
 * RETURNS
 *  Allocated memory block
 *****************************************************************************/
void *applib_mem_screen_alloc_int(kal_uint32 mem_size, kal_bool is_framebuffer, kal_uint32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *chunk;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if !defined(__MRE_SDK__) && defined(__J2ME__) && defined(__COSMOS_MMI_PACKAGE__) && !defined(__MMI_REDUCED_UI_BUFFER__)
    if (SCR_JAVA_APP == mmi_frm_scrn_get_active_id())
    {
        if (g_applib_mem_cntx.screen_pool_id == NULL)
        {
            g_applib_mem_cntx.screen_pool_id =
                kal_adm_create(
                    ui_buffer_get_start_addr(UI_BUFFER_ID_VRT_CACHE), 
                    ui_buffer_get_size(UI_BUFFER_ID_VRT_CACHE), 
                    (kal_uint32*) g_applib_mem_pool_chunk_size, 
                    KAL_FALSE);
        }
        if (is_framebuffer)
        {
            chunk = kal_adm_alloc_nc_align(
                        g_applib_mem_cntx.screen_pool_id, 
                        mem_size, 
                        __MMI_GDI_LAYER_FRAMEBUF_ALIGNMENT__);
        }
        else
        {
            chunk = kal_adm_alloc(g_applib_mem_cntx.screen_pool_id, mem_size);
        }

    }
    else
    #endif
    {
        if (is_framebuffer)
        {
            chunk =  mmi_frm_asm_alloc_anonymous_nc(mem_size);
        }
        else
        {
            chunk = mmi_frm_asm_alloc_anonymous(mem_size);
        }
    }

    if (chunk == NULL)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_MEM_SCR_ASM_ALLOC, mem_size, line, NULL);
        return NULL;
    }
    g_applib_mem_cntx.screen_alloc_count++;
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_MEM_SCR_ASM_ALLOC, mem_size, line, chunk);
    return chunk;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_screen_free_int
 * DESCRIPTION
 *  Free screen-based ASM
 *
 * PARAMETERS
 *  mem_ptr    : [IN] Memory block to be released
 *  line       : [IN] line number of allocate
 * RETURNS
 *  void
 *****************************************************************************/
void applib_mem_screen_free_int(void *mem_ptr, kal_uint32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_MEM_SCR_ASM_FREE, mem_ptr, line);
    g_applib_mem_cntx.screen_alloc_count--;
    if (g_applib_mem_cntx.screen_pool_id == NULL)
    {
        mmi_frm_asm_free_anonymous(mem_ptr);
    }
#if !defined(__MRE_SDK__) && defined(__J2ME__) && defined(__COSMOS_MMI_PACKAGE__)
    else
    {
        kal_adm_free(g_applib_mem_cntx.screen_pool_id, mem_ptr);
        if (g_applib_mem_cntx.screen_alloc_count == 0)
        {
            kal_adm_delete(g_applib_mem_cntx.screen_pool_id);
            g_applib_mem_cntx.screen_pool_id = 0;
        }

    }
#endif /*!defined(__MRE_SDK__)*/ 
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_screen_get_total_left_size
 * DESCRIPTION
 *  Get available size of screen-based ASM.
 *
 *  Remark: this function is only suggested for *debug* purpose because
 *  1. The memory pool may be fragmented (total left free space is meaningless 
 *     if the pool has serious memory fragmentation)
 *  2. Even if the free space is contiguous, we still cannot allocate 10 * 10KB blocks 
 *     with 100KB free space because of the overheads of memory management bookkeeping
 *
 *  Please use applib_mem_screen_get_max_alloc_size() or applib_mem_screen_get_pool_size()
 *  instead.
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  Total left space in byte
 *****************************************************************************/
kal_uint32 applib_mem_screen_get_total_left_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_screen_get_max_alloc_size
 * DESCRIPTION
 *  Get the max possible size of single allocation of screen-based ASM.
 *  Return value of it is typically less than applib_mem_screen_get_total_left_size()
 *  if the pool is fragmented.
 *
 *  Remark: we can use this function to dynamically decide the allocation size 
 *  (for example, use larger image cache when there is more memory)
 *  
 *  However, sometimes we cannot allocate 2 * 10KB blocks if the maximum allocation size 
 *  is 20KB because of overheads of memory management bookkeeping. 
 *
 *  It is suggested to use "fail-safe" allocation regardless the internal 
 *  implementation of ASM if we want to allocate more memory adaptively according to 
 *  the free space.
 *  Step 1. Decide the size of free space => e.g. 100KB
 *  Step 2. Allocate 100KB
 *  Step 3. If failed, allocate 95 KB
 *  Step 4. If failed, allocate 90 KB
 *  Step 5. ...
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  Maximum allocation size in byte
 *****************************************************************************/
kal_uint32 applib_mem_screen_get_max_alloc_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_screen_get_pool_size
 * DESCRIPTION
 *  Return the fixed size of screen-based ASM pool
 *
 *  Remark: we can use this function to decide the maximum possible memory 
 *  we can allocate (the whole pool size)
 * 
 *  However, we still cannot allocate 10 * 10KB blocks in an 100KB memory pool
 *  because of the overheads of memory management bookkeeping. 
 *  
 *  It is suggested to use "fail-safe" allocation regardless the internal 
 *  implementation of ASM if we want to allocate more memory adaptively 
 *  according to the pool size:
 *  Step 1. Decide pool size => e.g. 100KB
 *  Step 2. Allocate 100KB
 *  Step 3. If failed, allocate 95 KB
 *  Step 4. If failed, allocate 90 KB
 *  Step 5. ...
 *
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  Pool size in byte
 *****************************************************************************/
kal_uint32 applib_mem_screen_get_pool_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_screen_get_alloc_count
 * DESCRIPTION
 *  Return the number of allocated blocks
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  The number of allocated blocks
 *****************************************************************************/
kal_uint32 applib_mem_screen_get_alloc_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_applib_mem_cntx.screen_alloc_count;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_asm_get_chunk_info
 * DESCRIPTION
 *  This function is used to get the memory chunk info by the memory pointer
 *  (the return value of alloc function)
 *  This is internal function for ASM core module
 *  Application should not use this function
 * PARAMETERS
 *  ptr:     [IN]   user memory pointer  
 *  info:    [OUT]  memory chunk info
 * RETURNS
 *  void
 *****************************************************************************/
void applib_mem_asm_get_chunk_info(void *ptr, applib_mem_chunk_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mem_header_struct *header;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    header = ((applib_mem_header_struct *)ptr) - 1;
    info->chunk_size    = header->chunk_size;
    info->owner_id      = header->owner_id;
    info->flag          = header->flag;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_asm_get_detail_info
 * DESCRIPTION
 *  Get current statistic information of application asm memory.
 * PARAMETERS
 *  info_struct         [IN]       information structure
 *  mmi_frm_mem_type    [IN]       memory type of monitor statistics
 * RETURNS
 *  void
 *****************************************************************************/
void applib_mem_asm_get_detail_info(applib_asm_mem_detail_info_struct *info_struct, mmi_frm_mem_type mem_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mem_header_struct *first_node_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mem_type == MMI_FRM_MEM_APP_ASM)
    {
        (*info_struct).pool_size = g_applib_mem_cntx.app_pool_size;
        if (g_applib_mem_cntx.app_pool_id)
        {
            first_node_ptr = g_applib_mem_cntx.app_head.next;
            #if defined __MMI_USE_MMV2__
            (*info_struct).max_alloc_size = 0; /*get max size cost a lot of time in MMV2 case*/
            #else
            (*info_struct).max_alloc_size = (applib_monitor_data_type)applib_mem_ap_get_max_alloc_size_int();
            #endif
            (*info_struct).total_left_size = (applib_monitor_data_type)applib_mem_ap_get_total_left_size_int();
        }
        else    /* Full pool is allocated */
        {
            (*info_struct).max_alloc_size = (applib_monitor_data_type)g_applib_mem_cntx.app_pool_size;
            (*info_struct).total_left_size = (applib_monitor_data_type)0;
        }
        (*info_struct).alloc_count = g_applib_mem_cntx.app_alloc_count;
        (*info_struct).total_used_size = (*info_struct).pool_size - (*info_struct).total_left_size;
        if (first_node_ptr)
        {
            (*info_struct).current_caller_id = first_node_ptr->owner_id;
            (*info_struct).current_alloc_size = first_node_ptr->chunk_size;
            if (first_node_ptr->chunk_size > (*info_struct).maximal_allocated_size)
            {
                (*info_struct).maximal_caller_id = first_node_ptr->owner_id;
                (*info_struct).maximal_allocated_size = first_node_ptr->chunk_size;
            }
        }
        else
        {
            (*info_struct).current_caller_id = 0;
            (*info_struct).current_alloc_size = 0;
            /* Maximal information can't be reset! */
        }
    }
}


/* Internal Interface Test */
#ifdef APPLIB_MEM_UNIT_TEST

//function to check sort result
static void check_sort_result(applib_mem_ap_usage_struct *a, kal_int32 len)
{
    kal_int32 i, j;
    for (i = 0, j = 1; j < len; i++, j++)
    {
        ASSERT(a[i].mem_size >= a[j].mem_size);
    }
}

//function to print applist array
static void print_array(applib_mem_ap_usage_struct *a, kal_int32 len)
{
    kal_int32 i;
    for (i = 0; i < len; i++)
    {
        char *p;
        if (i + 1 == len)
        {
            p = "[%d";
        }
        else
        {
            p = "[%d]-";
        }

        kal_prompt_trace(MOD_MMI, p, a[i].mem_size);
    }
}

//Test Data for sorting
applib_mem_ap_usage_struct data1[] =
{
    {1, 1, 50, KAL_FALSE}, 
    {2, 1, 20, KAL_FALSE}, 
    {3, 1, 30, KAL_FALSE}, 
    {4, 1, 48, KAL_FALSE}, 
    {5, 1, 50, KAL_FALSE}, 
};


applib_mem_ap_usage_struct data2[] =
{
    {1, 1, 11, KAL_FALSE}, 
    {2, 1, 20, KAL_FALSE}, 
    {3, 1, 30, KAL_FALSE}, 
    {4, 1, 48, KAL_FALSE}, 
    {5, 1, 50, KAL_FALSE}, 
};

applib_mem_ap_usage_struct data3[] =
{
    {1, 1, 100, KAL_FALSE}, 
};

applib_mem_ap_usage_struct data4[] =
{
    {1, 1, 11, KAL_FALSE}, 
    {2, 1, 20, KAL_FALSE}, 
};

applib_mem_ap_usage_struct data5[] =
{
    {1, 1, 50, KAL_FALSE}, 
    {2, 1, 40, KAL_FALSE}, 
    {3, 1, 40, KAL_FALSE}, 
    {4, 1, 30, KAL_FALSE}, 
    {5, 1, 20, KAL_FALSE}, 
};

//structure for sorting test data base
typedef struct
{
    applib_mem_ap_usage_struct *data;
    kal_int32 len;
} test_item_p;

//sorting test data base
test_item_p test_db[] = 
{
    {data1, sizeof(data1)/sizeof(data1[0])}, 
    {data2, sizeof(data2)/sizeof(data2[0])}, 
    {data3, sizeof(data3)/sizeof(data3[0])}, 
    {data4, sizeof(data4)/sizeof(data4[0])}, 
    {data5, sizeof(data5)/sizeof(data5[0])}, 
};

//test function test insertion sort
static void test_insert_sort(void)
{
    kal_int32 i;
    for (i = 0; i < sizeof(test_db) / sizeof(test_db[0]); i++)
    {
        kal_prompt_trace(MOD_MMI, "Before sort");
        print_array(test_db[i].data, test_db[i].len);
        kal_prompt_trace(MOD_MMI, "Sorting");
        insert_sort(test_db[i].data, test_db[i].len);
        kal_prompt_trace(MOD_MMI, "After sort");
        print_array(test_db[i].data, test_db[i].len);
        check_sort_result(test_db[i].data, test_db[i].len);
    }
}

//test judge static id
static void test_is_static_id(void)
{
    kal_uint32 i;

    for (i = 0; i < 0xFFFF; i++)
    {
        if (i > APPLIB_MEM_AP_ID_DUMMY && i < APPLIB_MEM_AP_ID_TOTAL)
        {
            ASSERT(is_static_id(i) == KAL_TRUE);
        }
        else
        {
            ASSERT(is_static_id(i) == KAL_FALSE);
        }
    }
}

//test get_static_id_idx
static void test_get_static_id_idx(void)
{
    kal_uint32 i;

    for (i = APPLIB_MEM_AP_ID_DUMMY + 1; i < APPLIB_MEM_AP_ID_TOTAL; i++)
    {
        ASSERT(get_static_id_idx(i) == i - APPLIB_MEM_AP_ID_DUMMY);
    }
}

//test get root app id

static void test_get_root_app_id(void)
{
    kal_uint32 i;
    MMI_ID group_id;
    MMI_ID sub_group_id;

    group_id = mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, NULL, NULL, 0);
    sub_group_id = mmi_frm_group_create_ex(group_id, GRP_ID_AUTO_GEN, NULL, NULL, 0);

    for (i = APPLIB_MEM_AP_ID_DUMMY + 1; i < APPLIB_MEM_AP_ID_TOTAL; i++)
    {
        ASSERT(get_root_app_id(i) == i);
    }
    ASSERT(get_root_app_id(group_id) == group_id);
    ASSERT(get_root_app_id(sub_group_id) == group_id);

    mmi_frm_group_close(group_id);
}

//test set_static_registered_app_info
static void test_set_static_registered_app_info(void)
{
    kal_uint32 i;
    applib_mem_app_info_struct temp[APPLIB_MEM_APP_COUNT];

    memcpy(temp, g_applib_mem_cntx.app_info, sizeof(temp));

    for (i = APPLIB_MEM_AP_ID_DUMMY + 1; i < APPLIB_MEM_AP_ID_TOTAL; i++)
    {
        applib_mem_app_info_struct info;
        applib_mem_app_info_struct out_info;
        info.id = i;
        info.name = i;
        set_static_registered_app_info(&info);
        get_app_info(i, &out_info);
        ASSERT(out_info.id == i);
        ASSERT(out_info.name == i);
    }

    memcpy(g_applib_mem_cntx.app_info, temp, sizeof(temp));

}

//test allocate free stop info
static void test_alloc_free_stop_info(void)
{
    kal_uint32 i;
    applib_mem_app_stop_info_struct *stop_info_p;
    applib_mem_app_stop_info_struct *stop_info_temp[APPLIB_MEM_APP_STOP_MAX];
    kal_uint32 free_stop_info_slot = 0;
    for (i = 1000;;i++)
    {
        stop_info_p = allocate_app_stop_info_space( i + 1);
        if (stop_info_p != NULL)
        {
            applib_mem_app_stop_info_struct *get_info;
            get_info = get_app_stop_info(i+1);
            ASSERT(get_info == stop_info_p);
            stop_info_temp[free_stop_info_slot] = get_info;
            free_stop_info_slot++;
        }
        else
        {
            break;
        }
    }

    for (i = 1000; i < 1000 + free_stop_info_slot;i++)
    {
        free_app_stop_info_space(i + 1);
        ASSERT(stop_info_temp[i - 1000]->id == 0);
    }

}

//test get file name
static void test_get_file_name(void)
{
    kal_char *file;
    ASSERT(get_file_name(NULL) == NULL);
    ASSERT(get_file_name("\0") == NULL);
    file = get_file_name("F:\\hua\\Tian\\temp.c");
    ASSERT(strcmp((const char*)file, "temp.c") == 0);

    file = get_file_name("..\\hua\\Tian\\temp.c");
    ASSERT(strcmp((const char*)file, "temp.c") == 0);

    /* basename don't support Unix like file name */
    //file = get_file_name("../hua/Tian/temp.c");
    //ASSERT(strcmp((const char*)file, "temp.c") == 0);
}

//test set alloc free info
static void test_set_alloc_free_info(void)
{
    kal_int32 i;
    applib_mem_header_struct list_head;
    kal_uint32 allocate_count = 0;
    void *chunk[10];

    list_head.chunk_size = 0;
    list_head.next = NULL;
    for (i = 0; i < 10; i++)
    {
        applib_mem_header_struct *header;
        applib_mem_header_struct *next = list_head.next;
        void *p;
        chunk[i] = mmi_malloc(128);
        header = (applib_mem_header_struct *)chunk[i];

        p = set_allocation_info(
            chunk[i], 
            5000 + i, 
            64, 
            0, 
            &list_head, 
            &allocate_count, 0);
        ASSERT(p == (void *)(header + 1));
        memset(p, 0, 64);

        ASSERT(header->owner_id == 5000 + i);
        ASSERT(header->chunk_size == 64);
        ASSERT(header->next == next);
        ASSERT(header->flag == 0);
        ASSERT(allocate_count == i + 1);
        ASSERT(list_head.next == header);
    }

    for (i = 4; i >= 0; i--)
    {
        applib_mem_header_struct *header;
        applib_mem_header_struct *temp = (applib_mem_header_struct *)chunk[i];
        applib_mem_header_struct *prev;
        applib_mem_header_struct *next = temp->next;

        prev = list_head.next;
        while (prev->next != temp)
        {
            prev = prev->next;
        }
        header = set_free_info(
            temp + 1, 
            4, 
            &list_head, 
            &allocate_count, 
            0);
        ASSERT(temp == header);
        ASSERT(prev->next == next);
        ASSERT(allocate_count == 5 + i);
        ASM_ASSERT(header->guard_pattern == APPLIB_MEM_HEADER_PATTERN2);
        mmi_mfree(chunk[i]);

    }

    for (i = 9; i > 4; i--)
    {
        applib_mem_header_struct *header;
        applib_mem_header_struct *temp = (applib_mem_header_struct *)chunk[i];
        applib_mem_header_struct *next = temp->next;
        header = set_free_info(
            temp + 1, 
            4, 
            &list_head, 
            &allocate_count, 
            0);
        ASSERT(temp == header);
        ASSERT(list_head.next == next);
        ASSERT(allocate_count == (i - 5));
        ASM_ASSERT(header->guard_pattern == APPLIB_MEM_HEADER_PATTERN2);
        mmi_mfree(chunk[i]);

    }

}

// test calc real allocation size
void test_calc_real_alloc_size(void)
{
    kal_uint32 i, j;
    kal_uint32 align_array[] = {4 , 32};
    kal_uint32 size;

    for (i = 0; i < 0x00FF0000; i++)
    {
        for (j = 0; j < sizeof(align_array) / sizeof(align_array[0]); j++)
        {
            size = calc_real_alloc_size(i, align_array[j]);
            ASSERT(size % align_array[j] == 0);
            ASSERT(size >= i + sizeof(applib_mem_header_struct) + sizeof(applib_mem_footer_struct));
            ASSERT(size <= i + sizeof(applib_mem_header_struct) + sizeof(applib_mem_footer_struct) + align_array[j] - 1);
        }
    }

}
void test_stop_callback(void)
{
}
// test same id register twice
void test_same_id_register_twice(void)
{
    kal_uint32 i;
    kal_uint32 count = 0;
    applib_mem_ap_register(
        APPLIB_MEM_AP_ID_TEST1, 
        STR_GLOBAL_1, 
        IMG_GLOBAL_L1, 
        test_stop_callback);
    applib_mem_ap_register(
        APPLIB_MEM_AP_ID_TEST1, 
        STR_GLOBAL_1, 
        IMG_GLOBAL_L1, 
        test_stop_callback);
    for (i = 0 ; i < APPLIB_MEM_APP_COUNT; i++)
    {
        if (g_applib_mem_cntx.app_info[i].id == APPLIB_MEM_AP_ID_TEST1)
        {
            ASSERT(g_applib_mem_cntx.app_info[i].name == STR_GLOBAL_1);
            count++;
        }
    }
    ASSERT(count == 1);
    count = 0;

    for (i = 0 ; i < APPLIB_MEM_APP_STOP_MAX; i++)
    {
        if (g_applib_mem_cntx.app_stop_info[i].id == APPLIB_MEM_AP_ID_TEST1)
        {
            ASSERT(g_applib_mem_cntx.app_stop_info[i].stop_callback == (applib_mem_stop_handler_type)test_stop_callback);
            count++;
        }
    }
    ASSERT(count == 1);
}
//asm internal function test
void applib_mem_ut_internal_function(void)
{

    test_is_static_id();
    test_get_static_id_idx();
    test_get_root_app_id();
    test_set_static_registered_app_info();
    test_alloc_free_stop_info();
    test_get_file_name();
    test_insert_sort();
    test_set_alloc_free_info();
    test_calc_real_alloc_size();
    test_same_id_register_twice();
}
#endif

#endif /* !defined(NEPTUNE_MMI) && !defined(MMI_NOT_PRESENT) && !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) */


