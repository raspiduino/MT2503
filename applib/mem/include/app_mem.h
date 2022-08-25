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
 *  app_mem.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Public interface of ASM (application-shared memory)
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef APP_MEM_H
#define APP_MEM_H
/* DOM-NOT_FOR_SDK-BEGIN */

#include "kal_general_types.h"

/* Only applied to Pluto MMI */
#if !defined(NEPTUNE_MMI) && !defined(MMI_NOT_PRESENT) && !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
#include "MMIDataType.h"
#include "mmi_res_range_def.h"
#include "MMI_features.h"

#endif

#if defined __MMI_USE_MMV2__
#include "kal_vm.h"
#endif
/***************************************************************************** 
* Define
*****************************************************************************/
#undef FILE_PATH_VALUE
//#define ASM_DEBUG_LEVEL_3

#if (defined(ASM_DEBUG_LEVEL_3) || defined(ASM_DEBUG_LEVEL_2))
#define FILE_PATH_VALUE   __FILE__
#else
#define FILE_PATH_VALUE   NULL
#endif
#define ASM_MIN_TRACKING_SIZE (10*1024)

/* Toggle ASM unit test */
#undef APPLIB_MEM_UNIT_TEST
//#define APPLIB_MEM_UNIT_TEST
/*************ASM Pool needs 32 bytes align*********************************/

#ifdef __DYNAMIC_SWITCH_CACHEABILITY__
#define __ASM_POOL_32_BYTE_ALIGN__
#endif
/***************************************************************************/
#ifdef __ASM_POOL_32_BYTE_ALIGN__
#define ASM_ALIGN_SIZE 32
#else
#define ASM_ALIGN_SIZE 4
#endif

#define APPMEM_ALIGN_TO_N(_x, n)  (((_x) + (n-1)) & ~(n-1)) 


/*
 * 1. APPLIB_MEM_AP_POOL_SIZE
 * 
 * The size of the app-based ASM pool
 *
 * 2. APPLIB_MEM_AP_POOL_ALIGN
 *
 * Memory alignment of the app-based ASM pool
 *
 * If APPLIB_MEM_AP_POOL_ALIGN > 0, it set the required alignment of the whole ASM pool.
 * For example, we may need to align the pool to 256KB or 512KB for Java FBBR.
 */

#define APPLIB_MEM_AP_POOL_ALIGN    (ASM_ALIGN_SIZE)

/* Add extra space for ADM internal data structures.
  (Assume that there are at most 10 concurrent memory blocks) */
#ifdef LOW_COST_SUPPORT
    #define APPLIB_MEM_AP_CHUNK_NUM     (3)
#else
    #define APPLIB_MEM_AP_CHUNK_NUM     (10)
#endif

#define APPLIB_MEM_AP_POOL_OVERHEAD     (APPLIB_MEM_GET_POOL_EXTRA_SIZE(APPLIB_MEM_AP_CHUNK_NUM))

/* APPMEM_POOL_SIZE is multiple of 4 */
#define APPLIB_MEM_AP_POOL_DEFAULT_SIZE     (0 + APPLIB_MEM_AP_POOL_OVERHEAD)

#define APPLIB_MEM_AP_POOL_SIZE_CONFIG(size)    \
	(APPMEM_ALIGN_TO_N((size), ASM_ALIGN_SIZE) + APPLIB_MEM_AP_POOL_OVERHEAD) 

#define APPLIB_MEM_CONC2_AP_POOL_SIZE(size1, size2)    \
    (APPMEM_ALIGN_TO_N((size1), ASM_ALIGN_SIZE)  + APPMEM_ALIGN_TO_N((size2), ASM_ALIGN_SIZE) + APPLIB_MEM_AP_POOL_OVERHEAD) 

#define APPLIB_MEM_CONC3_AP_POOL_SIZE(size1, size2, size3)    \
    (APPMEM_ALIGN_TO_N((size1), ASM_ALIGN_SIZE) + APPMEM_ALIGN_TO_N((size2), ASM_ALIGN_SIZE) + APPMEM_ALIGN_TO_N((size3), ASM_ALIGN_SIZE)  + APPLIB_MEM_AP_POOL_OVERHEAD)



/* Guard pattern in header of allocated chunk */
#define APPLIB_MEM_HEADER_PATTERN1          (0xAAAAAAAA)
/* Guard pattern in header of released chunk */
#define APPLIB_MEM_HEADER_PATTERN2          (0xBBBBBBBB)
/* Guard pattern in footer of allocated chunk */
#define APPLIB_MEM_FOOTER_PATTERN1          (0xCCCCCCCC)
/* Guard pattern in footer of released chunk */
#define APPLIB_MEM_FOOTER_PATTERN2          (0xDDDDDDDD)

#define APPLIB_MEM_CACHE_HEADER_ALLOCATE    (0xCACACACA)
#define APPLIB_MEM_CACHE_HEADER_FREED       (0xCFCFCFCF)

/* (Inaccurate) upper bound of internal structures used by KAL ADM */
#define APPLIB_MEM_POOL_EXTRA_SIZE          (256)

#define APPLIB_MEM_OVERHEAD                 (sizeof(applib_mem_header_struct) + sizeof(applib_mem_footer_struct))
/* Overhead used by each block.
   12 byte (KAL ADM) + chunk header + chunk footer */
#define APPLIB_MEM_CHUNK_EXTRA_SIZE         \
            (12 + sizeof(applib_mem_header_struct))

/* Get extra space needed for memory pool.
   Parameter 'n' is the expected number of allocations */
#define APPLIB_MEM_GET_POOL_EXTRA_SIZE(n)   \
            (APPLIB_MEM_POOL_EXTRA_SIZE + (n) * APPLIB_MEM_CHUNK_EXTRA_SIZE)

/* 
 * 1. Please register the screens using ASM in ScrMemMgr.h 
 * 2. If a screen uses memory under APPLIB_MEM_SCREEN_MIN_POOL_SIZE,  
 *    it's not required to register it in ScrMemMgr.h 
 */
#define APPLIB_MEM_SCREEN_MIN_POOL_SIZE     (512)            


/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef kal_bool (*app_get_usage_check_cb)(kal_uint16 app_id);

typedef void (*app_stop_finish_callback_type)(kal_uint32 app_id, kal_uint32 string_id, kal_bool result);

typedef enum {
    MEM_AP_STOP_TYPE_FORCE,
    MEM_AP_STOP_TYPE_REQ,
/*if ap can't free immediately, do NOT trigger async free process(MMI_FRM_ASM_WAITING_TO_FREE). 
just return MMI_FRM_ASM_FREE_FAIL*/
    MEM_AP_STOP_TYPE_NO_WAIT, 
    MEM_AP_STOP_TYPE_END_OF_ENUM,
} applib_mem_ap_stop_type;

/* This function type is for application's stop callback, when user choose to stop the app_id, this function will be called */
typedef void (*applib_mem_stop_handler_type)(kal_uint16 app_id, applib_mem_ap_stop_type stop_type);
/* when allocate memory failed, ex. the required size is larger than the max, allocation fail handler will be called */
typedef void (*applib_mem_ap_allocation_fail_handler_type)(kal_uint16 app_id, kal_uint32 mem_size);

typedef kal_bool (*applib_mem_ap_pre_alloc_hdlr)(kal_uint16 app_id, kal_uint32 mem_size, kal_uint32 continuous_subsize);
typedef void (*applib_mem_ap_anonymous_info_hdlr)(kal_uint32* total_size, kal_uint32* remain_size);
typedef void (*applib_mem_freed_handler)(kal_uint16 app_id, kal_bool is_hide);

/*Definition for applib_mem_header_struct.flag*/
#define APPLIB_MEM_HEADER_FLAG_IS_HIDE (1<<0)
#define APPLIB_MEM_HEADER_FLAG_IS_SLMM (1<<1) /*only be used in __MMI_USE_MMV2__ */

/* Header of a chunk (4n bytes) */
typedef struct _applib_mem_header_struct
{
    kal_uint32 guard_pattern;     /* guard pattern */
    kal_uint16 owner_id;                                   /* screen ID or application ID */
    kal_uint16 flag;
    kal_uint32 chunk_size;                                 /* allocated size round to 4 */
	kal_char *file; 
    kal_uint32 line;
    struct _applib_mem_header_struct *next;                /* next allocated chunk */
    #ifdef __ASM_POOL_32_BYTE_ALIGN__
    kal_uint32 reserve[2];
    #endif
} applib_mem_header_struct;

#if defined __MMI_USE_MMV2__
typedef struct _applib_shrunk_heap_list
{
    struct _applib_shrunk_heap_list *next;           /* next heap shrunk info */
    kal_uint32                     shrunk_size;     /*slmm heap shrunk size*/
}applib_shrunk_heap_list;
/*Definition for applib_mem_slmm_id->log_flag*/
#define APPLIB_MEM_SLMM_LOG_W_RETURN_ADDR 0x00010000 

typedef struct _applib_mem_slmm_id
{
    KAL_SLMM_ID              kal_slmm_id;         /*the KAL_SLMM_ID*/    
    kal_uint32               log_flag;            /*count of app allocation in slmm*/
    applib_shrunk_heap_list shrunk_heap_list; /* slmm heap shrunk size */
    applib_mem_header_struct applib_mem_header;   /*applib_mem_header that include owner_id, size, etc info*/
} *applib_mem_slmm_id; 
#endif

typedef struct {
    kal_uint16 owner_id;                                   
    kal_uint16 flag;
    kal_uint32 chunk_size;                                    
} applib_mem_chunk_info_struct;


/* 
 * Please register the application that use ASM in app_mem_config.h before
 * using the following API
 * The following APP ID should be wrapped by relative compile option to save ram size
 */
typedef enum {

#if !defined(NEPTUNE_MMI) && !defined(MMI_NOT_PRESENT) && !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    APPLIB_MEM_AP_ID_DUMMY = RESOURCE_BASE_FRAMEWORK_ASM,
#else
    APPLIB_MEM_AP_ID_DUMMY,
#endif


    /********* INSERT NEW APPLICATION HERE *********/
    APPLIB_MEM_AP_3D_GAME,
    APPLIB_MEM_AP_ID_PHOEDT,
#ifdef __J2ME__
    APPLIB_MEM_AP_ID_JAVA,
#endif
    APPLIB_MEM_AP_ID_BARCODEREADER,
    APPLIB_MEM_AP_ID_UNIFIED_COMPOSER,
#ifdef OPERA_BROWSER
    APPLIB_MEM_AP_ID_OPERA_BROWSER,
#endif
#if defined(OBIGO_Q03C_MMS_V01) && defined(__MMI_MMS_V01_USE_ASM__) 
    APPLIB_MEM_AP_ID_MMS_V01,
#endif

    APPLIB_MEM_AP_ID_VDOEDT,
    APPLIB_MEM_AP_ID_MMS_VIEWER,
    APPLIB_MEM_AP_ID_AVATAR,
    APPLIB_MEM_AP_ID_DICTIONARY,
    APPLIB_MEM_AP_ID_PICT_BRIDGE,
    APPLIB_MEM_AP_ID_CAMERA,
    APPLIB_MEM_AP_ID_LANGLN,
    APPLIB_MEM_AP_ID_GIS,
    APPLIB_MEM_AP_ID_MTV_PLAYER,
    APPLIB_MEM_AP_ID_DTV_PLAYER,
    APPLIB_MEM_AP_ID_EBOOK,
    APPLIB_MEM_AP_ID_SLIDESHOW,
    APPLIB_MEM_AP_ID_AB_REPEATER,
    APPLIB_MEM_AP_ID_BT_BIP,
    APPLIB_MEM_AP_ID_CAMCO,    
    APPLIB_MEM_AP_ID_BT_OPP,
    APPLIB_MEM_AP_ID_TDL,
    APPLIB_MEM_AP_ID_UMMS,
    APPLIB_MEM_AP_ID_CLIPBOARD,
    APPLIB_MEM_AP_ID_FMGR,
    APPLIB_MEM_AP_ID_BCR,
#ifdef __MAUI_SDK_TEST__
    APPLIB_MEM_AP_ID_TEST_SDK,
#endif    
    APPLIB_MEM_AP_ID_VS_TEST,
    APPLIB_MEM_AP_ID_VS_TEST1,
    APPLIB_MEM_AP_ID_MEDPLY,
    APPLIB_MEM_AP_ID_STACK_MEM,
    APPLIB_MEM_AP_ID_SMS,
    APPLIB_MEM_AP_ID_SMS_BPP,
    APPLIB_MEM_AP_ID_UCWEB,
    APPLIB_MEM_AP_ID_MRE_CORE,
    APPLIB_MEM_AP_ID_MRE_APP0,
    APPLIB_MEM_AP_ID_MRE_APP1,
    APPLIB_MEM_AP_ID_MRE_APP2,
    APPLIB_MEM_AP_ID_MRE_APP3,
    APPLIB_MEM_AP_ID_MRE_APP4,
    APPLIB_MEM_AP_ID_MRE_APP5,
    APPLIB_MEM_AP_ID_MRE_APP6,
    APPLIB_MEM_AP_ID_MRE_APP7,
    APPLIB_MEM_AP_ID_MRE_APP8,
    APPLIB_MEM_AP_ID_MRE_APP9,
#ifdef __MRE_AM__
    APPLIB_MEM_AP_ID_AM,
#endif
#ifdef __MMI_MRE_MSPACE__
    APPLIB_MEM_AP_ID_MSPACE,
#endif
    APPLIB_MEM_AP_ID_QQ,
    APPLIB_MEM_AP_ID_IVEX,

    APPLIB_MEM_AP_ID_EM,
    
    APPLIB_MEM_AP_ID_VENUS,

    APPLIB_MEM_AP_ID_QQ_MOVIE,

#ifdef __MMI_ENGINEER_MODE__
    APPLIB_MEM_AP_ID_EM_COMM_MEM,
#endif

#ifdef __MMI_FACTORY_MODE__
        APPLIB_MEM_AP_ID_FM_COMM_MEM,
#endif
    APPLIB_MEM_AP_ID_VDOREC,

    APPLIB_MEM_AP_ID_OP11_HS32,
#ifdef __MMI_GADGET_SUPPORT__
    APPLIB_MEM_AP_ID_WGTMGR,
    APPLIB_MEM_AP_ID_WIDGET,
#endif

    APPLIB_MEM_AP_ID_USER_PROF,

 #ifdef __MMI_MMS_USE_ASM__
	APPLIB_MEM_AP_ID_MMS_SERVICE,
#endif

#ifdef __MMI_EMAIL__
    APPLIB_MEM_AP_ID_EMAIL,
#endif

#ifdef __NMC_SUPPORT__
    APPLIB_MEM_AP_ID_NMC,
#endif

#ifdef __MOBILE_VIDEO_SUPPORT__
    APPLIB_MEM_AP_ID_MOBILE_VIDEO,
#endif

    APPLIB_MEM_AP_ID_MARK_SEVERAL,

#if defined(__ALIPAY_SUPPORT__)
    APPLIB_MEM_AP_ID_ALIPAY,
#endif

	
	APPLIB_MEM_AP_ID_TEST1,
	
#ifdef APPLIB_MEM_UNIT_TEST    
    APPLIB_MEM_AP_ID_TEST2,
    APPLIB_MEM_AP_ID_TEST3,
    APPLIB_MEM_AP_ID_TEST4,
    APPLIB_MEM_AP_ID_TEST5,
    APPLIB_MEM_AP_ID_TEST6,
    APPLIB_MEM_AP_ID_TEST7,
#endif

#ifdef __MMI_EM_CAM_AF_CONTSHOT__
/* under construction !*/
#endif
    APPLIB_MEM_AP_ID_MRE_SM0,
    APPLIB_MEM_AP_ID_MRE_SM1,
    APPLIB_MEM_AP_ID_MRE_SM2,
    APPLIB_MEM_AP_ID_MRE_SM3,
    APPLIB_MEM_AP_ID_MRE_SM4,
    APPLIB_MEM_AP_ID_MRE_SM5,
    APPLIB_MEM_AP_ID_MRE_SM6,
    APPLIB_MEM_AP_ID_MRE_SM7,
    APPLIB_MEM_AP_ID_MRE_SM8,
    APPLIB_MEM_AP_ID_MRE_SM9,
    APPLIB_MEM_SETTING_VUI_WALLPAPER,
    #ifndef __MMI_SUPPORT_ASMV2__
    APPLIB_MEM_AP_ID_PHB,
    APPLIB_MEM_AP_ID_SSO,
    #endif
#ifndef __MMI_SUPPORT_ASMV2__
    APP_SETTING_NEWW,
	APPLIB_MEM_AP_ID_UM,
#endif
	APPLIB_MEM_AP_ID_PHONEBOOK,
    APPLIB_MEM_AP_ID_TOTAL
} applib_mem_ap_id_enum;

/* output by applib_mem_ap_get_current_usage */
typedef struct {
    kal_uint16 app_id;
    kal_uint16 string_id;
    kal_uint32 mem_size;
    kal_bool is_stopping;
} applib_mem_ap_usage_struct;

typedef kal_uint32 applib_monitor_data_type;

typedef struct
{
    applib_monitor_data_type current_caller_id;      /* dynamic */
    applib_monitor_data_type current_alloc_size;     /* dynamic */
    applib_monitor_data_type total_left_size;        /* dynamic */
    applib_monitor_data_type max_alloc_size;         /* dynamic */
    applib_monitor_data_type total_used_size;        /* don't show now */
    applib_monitor_data_type alloc_count;            /* don't show now */
    applib_monitor_data_type pool_size;              /* static */
    applib_monitor_data_type maximal_caller_id;      /* static */
    applib_monitor_data_type maximal_allocated_size; /* static */
} applib_asm_mem_detail_info_struct;

#if !defined __ASM_ALLOC_FLAG_ENUM__
#define __ASM_ALLOC_FLAG_ENUM__
typedef enum
{
    ASM_ALLOC_DEFAULT_FLAG = 0,     /* default value : return cacheable memory*/
    ASM_ALLOC_IS_FB_FLAG = (1<<0),  /* framebuffer usage : return non-cacheable (and continuous if defined __MMI_USE_MMV2__ )memory*/
    ASM_ALLOC_IS_SW_FLAG = (1<<1),  /* for SW usage, cacheable (and non-continuous if defined __MMI_USE_MMV2__ )memory*/
    ASM_ALLOC_IS_TOP_FLAG = (1<<2)   /* Usually for HW usge(framebuffer usage), force allocate from top address side. provide a flexiblilty to fine-tune external fragment issue*/
} asm_alloc_flag;
#endif

/* Check if _ptr is 32-byte aligned */
#define APPLIB_MEM_ALIGNED_PTR(_ptr, n)          ((((kal_uint32)(_ptr)) & (n-1)) == 0)

/* Check if _n is power of 2 */
#define APPLIB_MEM_TEST_POWER_2(_n)         ((_n) && !((_n) & ((_n) - 1)))

/* Check if _ptr is n-byte aligned */
#define APPLIB_MEM_ALIGNED_N(_ptr, _n)      (APPLIB_MEM_TEST_POWER_2(_n) && \
                                             !(((kal_uint32)(_ptr)) & ((_n) - 1)))

/*****************************************************************************
 * FUNCTION
 *  APPLIB_MEM_SET_PATTERN
 * DESCRIPTION
 *  Fill guard pattern
 * PARAMETERS
 *  ptr         [OUT]       data pointer
 *  pattern     [IN]        guard pattern
 * RETURNS
 *  void
 *****************************************************************************/
#define APPLIB_MEM_SET_PATTERN(ptr, pattern)  *(ptr) = (pattern);



/*****************************************************************************
 * FUNCTION
 *  APPLIB_MEM_COMP_PATTERN
 * DESCRIPTION
 *  Compare if the guard pattern is correct
 * PARAMETERS
 *  ptr         [IN]        data pointer
 *  pattern     [IN]        guard pattern
 * RETURNS
 *  return KAL_FALSE if the guard pattern is corrupted
 *****************************************************************************/
#define APPLIB_MEM_COMP_PATTERN(ptr, pattern)	((kal_bool)((*ptr) == (pattern)))

/* free callback type of cache mem. */
typedef void (*applib_mem_cache_free_cb_type)(void *mem_ptr);
/* DOM-NOT_FOR_SDK-END */

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_alloc
 * DESCRIPTION
 *  Allocate app-based ASM for the general buffer
 *
 *  Remark:
 *  1. It might return NULL if the allocation failed.
 *  2. Please keep allocation count as few as possible; for example, allocate an
 *     array with 100 elements instead of using applib_mem_ap_alloc() 100 times.
 *     Reason A: the space overheads is hard to estimate when 
 *               underlying implementation is changed.
 *     Reason B: performance is better when there are fewer allocations
 *  3. We suggest application allocate a total size once, and use ADM to manage the return
 *     memory pool, other than allocate many times.
 *  4. If application needs allocate memory for file path, we already provide a stack pool,
 *     called App-stack ASM. It is no need to register for this memory, and when allocate
 *     memory, the app_id should be APPLIB_MEM_AP_ID_STACK_MEM. There will be assert if allocate fail.
 *  This function can be used in non-MMI task. 
 * PARAMETERS
 *  app_id:          [IN]        ID of owner application (applib_mem_ap_id_enum)
 *  mem_size:        [IN]        Memory size
 * RETURNS
 *  Allocated memory block
 * EXAMPLE
 * <code>
 * U32 total_size;
 * void *ptr = applib_mem_ap_alloc(app_id, total_size);
 * KAL_ADM_ID adm_id = kal_adm_create(ptr, sizeof(ptr), chunk, MMI_FALSE);
 * g_buff = kal_adm_alloc(adm_id);
 * // when allocate memory for  file path
 * void *ptr = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_STACK_MEM, size);
 * </code>
 *****************************************************************************/
#define applib_mem_ap_alloc(app_id, mem_size) applib_mem_ap_alloc_int(app_id, mem_size, ASM_ALLOC_DEFAULT_FLAG, FILE_PATH_VALUE, __LINE__, KAL_FALSE)


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_alloc
 * DESCRIPTION
 *  Allocate app-based ASM for the general buffer
 *
 *  Remark:
 *  1. It might return NULL if the allocation failed.
 *  2. Please keep allocation count as few as possible; for example, allocate an
 *     array with 100 elements instead of using applib_mem_ap_alloc() 100 times.
 *     Reason A: the space overheads is hard to estimate when 
 *               underlying implementation is changed.
 *     Reason B: performance is better when there are fewer allocations
 *  3. We suggest application allocate a total size once, and use ADM to manage the return
 *     memory pool, other than allocate many times.
 *  4. If application needs allocate memory for file path, we already provide a stack pool,
 *     called App-stack ASM. It is no need to register for this memory, and when allocate
 *     memory, the app_id should be APPLIB_MEM_AP_ID_STACK_MEM. There will be assert if allocate fail.
 *  This function can be used in non-MMI task. 
 * PARAMETERS
 *  app_id:          [IN]        ID of owner application (applib_mem_ap_id_enum)
 *  mem_size:        [IN]        Memory size
 * RETURNS
 *  Allocated memory block
 * EXAMPLE
 * <code>
 * U32 total_size;
 * void *ptr = applib_mem_ap_alloc(app_id, total_size);
 * KAL_ADM_ID adm_id = kal_adm_create(ptr, sizeof(ptr), chunk, MMI_FALSE);
 * g_buff = kal_adm_alloc(adm_id);
 * // when allocate memory for  file path
 * void *ptr = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_STACK_MEM, size);
 * </code>
 *****************************************************************************/
#define applib_mem_ap_alloc_sw(app_id, mem_size) applib_mem_ap_alloc_int(app_id, mem_size, ASM_ALLOC_IS_SW_FLAG, FILE_PATH_VALUE, __LINE__, KAL_FALSE)

/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_alloc_framebuffer
 * DESCRIPTION
 *  Allocate app-based ASM for the frame buffer
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
 *  app_id:          [IN]        ID of owner application (applib_mem_ap_id_enum)
 *  mem_size:        [IN]        Memory size
 * RETURNS
 *  Allocated memory block
 *****************************************************************************/
#define applib_mem_ap_alloc_framebuffer(app_id, mem_size) applib_mem_ap_alloc_int(app_id, mem_size, ASM_ALLOC_IS_FB_FLAG, FILE_PATH_VALUE, __LINE__, KAL_FALSE)

#if defined __MMI_USE_MMV2__
/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_alloc_framebuffer_in_top
 * DESCRIPTION
 *  Allocate app-based ASM for the frame buffer in top address of ASM (api for MMv2 feature only)
 *  (It provide a flexibility to fine-tune fragment that due to continuous buffer)
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
 *  app_id:          [IN]        ID of owner application (applib_mem_ap_id_enum)
 *  mem_size:        [IN]        Memory size
 * RETURNS
 *  Allocated memory block
 *****************************************************************************/
#define applib_mem_ap_alloc_framebuffer_in_top(app_id, mem_size) applib_mem_ap_alloc_int(app_id, mem_size, ASM_ALLOC_IS_FB_FLAG|ASM_ALLOC_IS_TOP_FLAG, FILE_PATH_VALUE, __LINE__, KAL_FALSE)
#endif
/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_alloc_full_pool
 * DESCRIPTION
 *  Allocate the whole pool of app-based ASM
 *
 *  Note: it is typically used with APPLIB_MEM_AP_POOL_ALIGN to get a aligned 
 *  buffer pool (Example: Java FBBR requires 256KB or 512KB alignment)
 * PARAMETERS
 *  app_id:          [IN]        ID of owner application (applib_mem_ap_id_enum)
 *  pool_size_p:     [OUT]       Allocated size (== the whole pool size)
 * RETURNS
 *  Allocated memory block
 *****************************************************************************/
#define applib_mem_ap_alloc_full_pool(app_id, pool_size_p) applib_mem_ap_alloc_full_pool_int(app_id, pool_size_p, __LINE__)

/* DOM-NOT_FOR_SDK-BEGIN */


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_alloc_FBBR_pool
 * DESCRIPTION
 *  Allocate the aligned pool of app-based ASM for java
 *
 *  Note: it is typically used with APPLIB_MEM_AP_POOL_ALIGN to get a aligned 
 *  buffer pool (Example: Java FBBR requires 256KB or 512KB alignment)
 *  Different from applib_mem_ap_alloc_full_pool, the left asm memory will be 
 *  used by other applicaton
 * PARAMETERS
 *  app_id:          [IN]        ID of owner application (applib_mem_ap_id_enum)
 *  pool_size_p:     [OUT]       Allocated size
 * RETURNS
 *  Allocated memory block
 *****************************************************************************/
#define applib_mem_ap_alloc_FBBR_pool(app_id, pool_size_p) applib_mem_ap_alloc_FBBR_pool_int(app_id, pool_size_p, __LINE__)


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_free
 * DESCRIPTION
 *  Free app-based ASM
 *
 *  This function can be used in non-MMI task.
 * PARAMETERS
 *  mem_ptr:    [IN]        Memory block to be released
 * RETURNS
 *  void
 *****************************************************************************/
#define applib_mem_ap_free(mem_ptr) applib_mem_ap_free_thread_safe(mem_ptr, FILE_PATH_VALUE, __LINE__, KAL_FALSE) 


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_free_FBBR_pool
 * DESCRIPTION
 *  Free the aligned pool of app-based ASM for java
 *
 * PARAMETERS
 *  app_id:         [IN]        ID of owner application (applib_mem_ap_id_enum)
 * RETURNS
 *  void
 *****************************************************************************/
#define applib_mem_ap_free_FBBR_pool(app_id) applib_mem_ap_free_FBBR_pool_int(app_id, __LINE__)                                    


/* system-level API invoked by MMI framework, not for applications */
extern void applib_mem_ap_init(void (*stop_finish_callback_by_MMI)(kal_uint32, kal_uint32, kal_bool), void *mem_pool, kal_uint32 pool_size);
extern void applib_mem_ap_stop_app_by_MMI_task(kal_uint32 app_id, applib_mem_ap_stop_type stop_type);
extern kal_uint32 applib_mem_ap_get_current_usage(
                    applib_mem_ap_usage_struct *applist, 
                    kal_uint32 max_items);
extern kal_uint32 applib_mem_ap_get_current_usage_ex(
	applib_mem_ap_usage_struct *applist,
	kal_uint32 max_items, 
	kal_uint32 param,
	kal_uint16 *skiplist,
	kal_uint32 skip_count, app_get_usage_check_cb cb);

/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_register
 * DESCRIPTION
 *  Register an application that uses app-based ASM. 
 *  This function should be used when an application is initialized at boot
 *  app_id is defined in App_mem.h. app_string_id is the string which is showed in 
 *  "insufficient memory" app-list screen. stop_callback_by_MMI is executed in MMI task. 
 *  When other applications allocate fail, and show app-list screen, user could choose to 
 *  stop the application, framework will invoke stop_callback_by_MMI and it needs to release ASM.
 *  1. If the application is original screen based(not use screen group), it should register app_id,
 *  app_string_id, and stop_callback_by_MMI. If we need to notify another task to stop the application, 
 *  please send primitive (source module: MOD_MMI) to the destination task in stop_callback_by_MMI. After
 *  release ASM, application should call applib_mem_ap_notify_stop_finished to notify framework the stop
 *  procedure is finished.
 *  2. If the application is root group(parent group id is GRP_GROUP_ID), it also should should register 
 *  app_id, app_string_id, and stop_callback_by_MMI could be NULL. If the stop_callback_by_MMI is NULL,
 *  in group proc should handle EVT_ID_MEM_FREE_ASM and return MMI_MEM_FREED, MMI_MEM_WAITING_TO_FREE,
 *  or MMI_MEM_FREE_FAIL. If the stop_callback_by_MMI is not NULL, the usage is just like screen based
 *  application.
 *  3. If the application is a child group(such as CUI), it is no need to call this function, and no
 *  need to handle EVT_ID_MEM_FREE_ASM.
 * EXAMPLE
 * <code>
 * 1. The application is screen based.
 *    applib_mem_ap_register(
 *         APPLIB_MEM_AP_ID_TEST1, 
 *         STR_GLOBAL_1, 
 *         IMG_GLOBAL_L1, 
 *         mmi_frm_appmem_unit_test_stop_1);
 *     void mmi_frm_appmem_unit_test_stop_1()
 *     {
 *         applib_mem_ap_free(...);    
 *         applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_TEST1, KAL_TRUE);
 *     }
 * 2. The application is root screen group.
 *    applib_mem_ap_register(APPLIB_MEM_AP_ID_TEST6, STR_GLOBAL_6, 0, NULL);
 *    ...............
 *    mmi_frm_group_create(GRP_ID_ROOT, APPLIB_MEM_AP_ID_TEST6, mmi_asm_test_proc, cntx_ptr);
 *    mmi_ret mmi_asm_test_proc(mmi_event_struct *evt)
 *    {
 *        switch(evt->evt_id)
 *        {
 *          case EVT_ID_GROUP_DEINIT:
 *               applib_mem_ap_free(cntx_ptr->mem_ptr);
 *               break;
 *           case EVT_ID_MEM_FREE_ASM:
 *               close group and child group
 *               return MMI_MEM_FREED;
 *           case .....
 *         }
 *       return MMI_RET_OK;
 *    }
 * </code>
 * PARAMETERS
 *  app_id:                  [IN]    Application ID defined in applib_mem_ap_id_enum
 *  app_string_id:           [IN]    The MMI string ID of application name
 *  app_icon_id:             [IN]    The MMI image ID of application icon (not used now)
 *  stop_callback_by_MMI:    [IN]    Callback function when user chooses to stop the application
 * RETURNS
 *  void
 *****************************************************************************/
extern void applib_mem_ap_register(
                kal_uint32 app_id, 
                kal_uint32 app_string_id, 
                kal_uint32 app_icon_id,
                void (*stop_callback_by_MMI)(void));

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
extern void applib_mem_ap_notify_stop_finished(kal_uint32 app_id, kal_bool result);


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_register_default_stop_callback
 * DESCRIPTION
 *  register default stop-callback. 
 *  default callback will be used when stop-callback is not registered.
 * PARAMETERS
 *  callback :      [IN]        stop callback
 * RETURNS
 *  previous stop-callback
 *****************************************************************************/
extern void applib_mem_ap_register_default_stop_callback(applib_mem_stop_handler_type callback);


extern void applib_mem_ap_register_pre_alloc_handler(applib_mem_ap_pre_alloc_hdlr handler);
extern void applib_mem_ap_register_mem_freed_handler(applib_mem_freed_handler handler);
extern void applib_mem_ap_register_anonymous_info_handler(applib_mem_ap_anonymous_info_hdlr handler);

/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_set_pre_reserve
 * DESCRIPTION
 *  vfx_app_launcher tell app's heap size, 
 *  then we can avoid cache fragmentation with knowing this information.
 *  and clean it after app has allocate its heap.
 * PARAMETERS
 *  size :      [IN]        the launching app's heap size.
 * RETURNS
 *  NONE
 *****************************************************************************/
extern void applib_mem_ap_set_pre_reserve(kal_uint32 size);

/* alloc/free */
extern void *applib_mem_ap_alloc_int(kal_uint32 app_id, kal_uint32 mem_size, asm_alloc_flag alloc_flag, kal_char *file, kal_uint32 line, kal_bool is_anonymous);
extern void *applib_mem_ap_alloc_full_pool_int(kal_uint32 app_id, kal_uint32 *pool_size, kal_uint32 line);
extern void applib_mem_ap_free_thread_safe(void *mem_ptr, kal_char *file, kal_uint32 line, kal_bool is_anonymous);
extern void *applib_mem_ap_cache_alloc_int(kal_uint32 mem_size, asm_alloc_flag alloc_flag, applib_mem_cache_free_cb_type free_cb, kal_char *file, kal_uint32 line);
extern void applib_mem_ap_cache_free_int(void *mem_ptr, kal_char *file, kal_uint32 line);
extern kal_bool applib_mem_ap_cache_free_till_enough_int(kal_uint32 size, kal_bool is_continuous, kal_char *file, kal_uint32 line);

#if defined __MMI_USE_MMV2__
applib_mem_slmm_id applib_mem_ap_create_slmm_pool (kal_uint32 app_id, kal_uint32 mem_size, 
                                                    kal_uint32 is_log, kal_uint32 is_slmm_log);

kal_status applib_mem_ap_delete_slmm_pool (applib_mem_slmm_id asm_slmm_id, kal_bool is_log);

void *applib_mem_ap_slmm_alloc_dbg (applib_mem_slmm_id asm_slmm_id, kal_uint32 size, 
                                    asm_alloc_flag flag, kal_uint32 filename, kal_uint32 line, kal_bool is_log);

kal_uint32 applib_mem_ap_slmm_free (applib_mem_slmm_id asm_slmm_id, void *ptr, kal_bool is_log);

kal_uint32 applib_mem_ap_get_slmm_total_left_size(applib_mem_slmm_id frm_asm_slmm_id);

void* applib_mem_ap_slmm_check(applib_mem_slmm_id frm_asm_slmm_id);

kal_uint32 applib_mem_ap_get_slmm_vm_start(applib_mem_slmm_id frm_asm_slmm_id);

kal_uint32 applib_mem_ap_get_slmm_vm_end(applib_mem_slmm_id frm_asm_slmm_id);

kal_int32 applib_mem_ap_slmm_limit_size(applib_mem_slmm_id frm_asm_slmm_id, kal_uint32 new_size);

mmi_id applib_mem_ap_get_slmm_owner_id(applib_mem_slmm_id asm_slmm_id);

KAL_SLMM_ID applib_mem_ap_get_kal_slmm_id (applib_mem_slmm_id asm_slmm_id);

kal_uint32 applib_mem_ap_get_slmm_log_flag(applib_mem_slmm_id asm_slmm_id);

kal_uint32 applib_mem_ap_slmm_update_header_flag (applib_mem_slmm_id asm_slmm_id, kal_uint16 flag, kal_uint32 is_set);

kal_uint32 applib_mem_ap_slmm_set_shrunk_heap_size(applib_mem_slmm_id frm_asm_slmm_id, kal_uint32 size);

kal_uint32 applib_mem_ap_slmm_get_shrunk_heap_size_by_ID(mmi_id app_id);

kal_uint32 applib_mem_ap_slmm_get_shrunk_heap_size(applib_mem_slmm_id frm_asm_slmm_id);

kal_uint32 applib_mem_ap_slmm_get_used_page_size(applib_mem_slmm_id frm_asm_slmm_id);
#endif
/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_free_all
 * DESCRIPTION
 *  Release all app-based ASM belong to an application
 *  This function can be used in non-MMI task.
 * PARAMETERS
 *  app_id:           [IN]application id need to release all ASM.
 * RETURNS
 *  void
 *****************************************************************************/
extern void applib_mem_ap_free_all(kal_uint32 app_id);


/* These interfaces are provided for java FBBR, please include MMI_features.h before this header file */
#ifdef __APPLIB_MEM_AP_FBBR_ALIGN_POOL__
extern void *applib_mem_ap_alloc_FBBR_pool_int(kal_uint32 app_id, kal_uint32 *pool_size, kal_uint32 line);
extern void applib_mem_ap_free_FBBR_pool_int(kal_uint32 app_id, kal_uint32 line);
#endif /* __APPLIB_MEM_AP_FBBR_ALIGN_POOL__ */
/* DOM-NOT_FOR_SDK-END */


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
extern kal_uint32 applib_mem_ap_get_total_left_size(void);

/* DOM-NOT_FOR_SDK-BEGIN */

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
extern kal_uint32 applib_mem_ap_get_max_alloc_size(void);

/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_get_pool_size
 * DESCRIPTION
 *  Return the fixed size of app-based ASM pool. The size is defined by application config.
 *  This function can be used in non-MMI task. 
 * PARAMETERS
 *  void
 * RETURNS
 *  Pool size in byte
 *****************************************************************************/
extern kal_uint32 applib_mem_ap_get_pool_size(void);


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_get_alloc_count
 * DESCRIPTION
 *  Return the number of allocated blocks.
 *  This function can be used in non-MMI task. 
 * PARAMETERS
 *  void
 * RETURNS
 *  The number of allocated blocks
 *****************************************************************************/
extern kal_uint32 applib_mem_ap_get_alloc_count(void);

/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_is_valid_block
 * DESCRIPTION
 *  Check if a app-based ASM memory block is valid by inspecting its guard patterns.
 *
 *  This function can be used in non-MMI task. 
 * PARAMETERS
 *  mem_ptr:     [IN]        Memory block to check
 * RETURNS
 *  Return KAL_TRUE if 'mem_ptr' is a valid block
 *****************************************************************************/
extern kal_bool applib_mem_ap_is_valid_block(void *mem_ptr);

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
extern void applib_mem_ap_check_integrity(void);

/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_is_initialized
 * DESCRIPTION
 *  check if app-based ASM is initialized. If it's initialized, we have created
 *  ADM pool.
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_true, if ASM is already initialized.
 *****************************************************************************/
extern kal_bool applib_mem_ap_is_initialized(void);

/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_get_name
 * DESCRIPTION
 *  check if app-based ASM is initialized. If it's initialized, we have created
 *  ADM pool.
 * PARAMETERS
 *  app_id     : [IN] group id under root or app id registered by applib_mem_ap_register
 * RETURNS
 *  app name's string id
 *****************************************************************************/
extern kal_uint16 applib_mem_ap_get_name(kal_uint32 app_id);


/***************************************************************************** 
 * Framework Internal API 
 *****************************************************************************/
extern kal_uint32 applib_mem_ap_get_total_left_size_int(void);
extern kal_uint32 applib_mem_ap_get_max_alloc_size_int(void);

extern void applib_mem_asm_get_chunk_info(void *ptr, applib_mem_chunk_info_struct *info);
extern kal_bool applib_mem_ap_cache_free_till_enough_by_id(kal_uint16 root_id, kal_uint32 req_size);

#define applib_mem_screen_alloc(mem_size) applib_mem_screen_alloc_int(mem_size, KAL_FALSE, __LINE__)
#define applib_mem_screen_alloc_framebuffer(mem_size) applib_mem_screen_alloc_int(mem_size, KAL_TRUE, __LINE__)
#define applib_mem_screen_free(mem_ptr) applib_mem_screen_free_int(mem_ptr, __LINE__)

extern void *applib_mem_screen_alloc_int(kal_uint32 mem_size, kal_bool is_framebuffer, kal_uint32 line);
extern void applib_mem_screen_free_int(void *mem_ptr, kal_uint32 line);
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  applib_mem_screen_get_total_left_size
 * DESCRIPTION
 *  Get available size of screen-based ASM.
 *  Remark: this function is only suggested for *debug* purpose because
 *  1. The memory pool may be fragmented (total left free space is meaningless 
 *     if the pool has serious memory fragmentation)
 *  2. Even if the free space is contiguous, we still cannot allocate 10 * 10KB blocks 
 *     with 100KB free space because of the overheads of memory management.
 *  Please use applib_mem_screen_get_max_alloc_size() or applib_mem_screen_get_pool_size()
 *  instead.
 * PARAMETERS
 *  void
 * RETURNS
 *  Total left space in byte
 *****************************************************************************/
extern kal_uint32 applib_mem_screen_get_total_left_size(void);

/*****************************************************************************
 * FUNCTION
 *  applib_mem_screen_get_max_alloc_size
 * DESCRIPTION
 *  Get the max possible size of single allocation of screen-based ASM.
 *  Return value of it is typically less than applib_mem_screen_get_total_left_size()
 *  if the pool is fragmented.
 *  Remark: we can use this function to dynamically decide the allocation size 
 *  (for example, use larger image cache when there is more memory)
 *  However, sometimes we cannot allocate 2 * 10KB blocks if the maximum allocation size 
 *  is 20KB because of overheads of memory management bookkeeping. 
 *  It is suggested to use "fail-safe" allocation regardless the internal 
 *  implementation of ASM if we want to allocate more memory adaptively according to 
 *  the free space.
 *  Step 1. Decide the size of free space => e.g. 100KB
 *  Step 2. Allocate 100KB
 *  Step 3. If failed, allocate 95 KB
 *  Step 4. If failed, allocate 90 KB
 *  Step 5. ...
 * PARAMETERS
 *  void
 * RETURNS
 *  Maximum allocation size in byte
 *****************************************************************************/
extern kal_uint32 applib_mem_screen_get_max_alloc_size(void);

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  applib_mem_screen_get_pool_size
 * DESCRIPTION
 *  Return the fixed size of screen-based ASM pool.
 * PARAMETERS
 *  void
 * RETURNS
 *  Pool size in byte
 *****************************************************************************/
extern kal_uint32 applib_mem_screen_get_pool_size(void);

/*****************************************************************************
 * FUNCTION
 *  applib_mem_screen_get_alloc_count
 * DESCRIPTION
 *  Return the number of allocated blocks 
 * PARAMETERS
 *  void
 * RETURNS
 *  The number of allocated blocks.
 *****************************************************************************/
extern kal_uint32 applib_mem_screen_get_alloc_count(void);
/* DOM-NOT_FOR_SDK-BEGIN */
extern kal_bool applib_mem_screen_is_valid_block(void *mem_ptr);
extern void applib_mem_ap_set_hide(kal_uint32 app_id, kal_bool hide);
extern kal_bool applib_mem_ap_is_hide(kal_uint32 app_id);
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  applib_mem_screen_check_integrity
 * DESCRIPTION
 *  Check if the internal state of screen-based ASM is correct. 
 *  If not, then ASSERT!
 *  Remark: This function takes a lot of computation time, and it should not be
 *  used in normal case. 
 *  The function call can be inserted in application code when we need to locate 
 *  hard-to-find memory corruption issue. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void applib_mem_screen_check_integrity(void);

extern kal_bool applib_mem_ap_check_enough_try_alloc(kal_uint32 size, kal_bool is_continuous);
extern void applib_mem_ap_dump(void);
extern kal_uint32 applib_mem_ap_get_single_usage(kal_uint32 app_id);
void applib_mem_ap_update_node_flag(kal_uint16 app_id, kal_uint16 flag, kal_uint32 is_set);
/* Only applied to Pluto MMI */
#if !defined(NEPTUNE_MMI) && !defined(MMI_NOT_PRESENT) && !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
#include "MMIDataType.h"
extern void applib_mem_asm_get_detail_info(applib_asm_mem_detail_info_struct *info_struct, mmi_frm_mem_type mem_type);
#endif
extern kal_uint32 applib_mem_ap_cache_get_size(void);

extern void *mmi_frm_asm_alloc_int(kal_uint16 id, kal_uint32 size, asm_alloc_flag alloc_flag, kal_char* file, kal_uint32 line);
extern void mmi_frm_asm_free_int(kal_uint16 id, void *ptr, kal_char* file, kal_uint32 line);
/* DOM-NOT_FOR_SDK-BEGIN */
extern void applib_mem_ap_free_all_cache(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  applib_asm_alloc_r
 * DESCRIPTION
 *  allocate memory from app-based ASM with given size for given id.
 *  This is cacheable version for normal usage.
 *  Remark: 1. This function can be used in non-MMI task (postfix '_r', means re-entrant for thread-safe).
 *          2. allocated memory is cacheable. for non-cacheable, please use applib_asm_alloc_nc_r instead.
 * PARAMETERS
 *  _id :        [IN]    app id
 *  _size :      [IN]    size to allocate
 * RETURNS
 *  pointer to allocated memory. NULL if memory is not available.
 *****************************************************************************/
#define applib_asm_alloc_r(_id, _size)   mmi_frm_asm_alloc_int(_id, _size, ASM_ALLOC_DEFAULT_FLAG, FILE_PATH_VALUE, __LINE__)

/*****************************************************************************
 * FUNCTION
 *  applib_asm_alloc_sw_r
 * DESCRIPTION
 *  allocate memory from app-based ASM with given size for given id.
 *  This is cacheable version for SW usage, DO-NOT use the allocated memory for HW access.
 *  It identifies the allocated memory is for software usage and can be remap to non-continuous physical memory
 *  to reduce the memory fragmentation. User should remember the allocated memory CANNOT be converted to non-cacheable memory for HW usage 
 *  for HW usage. 
 *
 *  Remark: 1. This function can be used in non-MMI task (postfix '_r', means re-entrant for thread-safe).
 *          2. allocated memory is cacheable. for non-cacheable, please use mmi_frm_asm_alloc_nc_r instead.
 * PARAMETERS
 *  _id :        [IN]    app id
 *  _size :      [IN]    size to allocate
 * RETURNS
 *  pointer to allocated memory. NULL if memory is not available.
 *****************************************************************************/
#define applib_asm_alloc_sw_r(_id, _size)   mmi_frm_asm_alloc_int(_id, _size, ASM_ALLOC_IS_SW_FLAG, FILE_PATH_VALUE, __LINE__)

#if defined __MMI_USE_MMV2__
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_alloc_nc_top_r
 * DESCRIPTION
 *  allocate memory from app-based ASM with given size for given id.
 *  This is non-cacheable version of mmi_frm_asm_alloc_r, it's api for MMv2 feature only
 *  (It provides a flexibility to fine-tune fragment that caused by continuous buffer)
 *
 * PARAMETERS
 *  _id :        [IN]    app id
 *  _size :      [IN]    size to allocate
 * RETURNS
 *  pointer to allocated memory. NULL if memory is not available.
 *****************************************************************************/
#define mmi_frm_asm_alloc_nc_top_r(_id, _size)   mmi_frm_asm_alloc_int(_id, _size, ASM_ALLOC_IS_FB_FLAG|ASM_ALLOC_IS_TOP_FLAG, FILE_PATH_VALUE, __LINE__)
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_alloc_sw_r_dbg
 * DESCRIPTION
 *  allocate memory from app-based ASM with given size for given id.
 *  This is cacheable version for SW usage, DO-NOT use the allocated memory for HW access.
 *  It identifies the allocated memory is for software usage and can be remap to non-continuous physical memory
 *  to reduce the memory fragmentation. User should remember the allocated memory CANNOT be converted to non-cacheable memory for HW usage 
 *  for HW usage. 
 *
 * PARAMETERS
 *  _id :        [IN] app id
 *  _size :      [IN] size to allocate
 *  _f :         [IN] filename (CHAR *)
 *  _l :         [IN] line nmber (U32)
 * RETURNS
 *  pointer to allocated memory. NULL if memory is not available.
 *****************************************************************************/
#define applib_asm_alloc_sw_r_dbg(_id, _size,  _f, _l)   mmi_frm_asm_alloc_int(_id, _size, ASM_ALLOC_IS_SW_FLAG, _f, _l)

/*****************************************************************************
 * FUNCTION
 *  applib_asm_alloc_nc_r
 * DESCRIPTION
 *  allocate memory from app-based ASM with given size for given id.
 *  This is non-cacheable version of applib_asm_alloc_r.
 *
 * PARAMETERS
 *  _id :        [IN]    app id
 *  _size :      [IN]    size to allocate
 * RETURNS
 *  pointer to allocated memory. NULL if memory is not available.
 *****************************************************************************/
#define applib_asm_alloc_nc_r(_id, _size)   mmi_frm_asm_alloc_int(_id, _size, ASM_ALLOC_IS_FB_FLAG, FILE_PATH_VALUE, __LINE__)

/*****************************************************************************
 * FUNCTION
 *  applib_asm_free_r
 * DESCRIPTION
 *  free memory allocated by applib_asm_alloc_r or applib_asm_alloc_nc_r.
 *
 * PARAMETERS
 *  _id :           [IN]    app id
 *  _mem_ptr :      [IN]    memory to free
 * RETURNS
 *  void
 *****************************************************************************/
#define applib_asm_free_r(_id, _mem_ptr)  mmi_frm_asm_free_int(_id, _mem_ptr, FILE_PATH_VALUE, __LINE__)

/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_cache_alloc
 * DESCRIPTION
 *  allocate temp memory from app-based ASM
 *  This is cacheable version for normal usage.
 *
 * PARAMETERS
 *  _size :           [IN]  required size
 *  _free_cb :        [IN]  callback when the allocated temp buffer need to be removed
 * RETURNS
 *  void
 *****************************************************************************/
#define applib_mem_ap_cache_alloc(_size, _free_cb) applib_mem_ap_cache_alloc_int(_size, ASM_ALLOC_DEFAULT_FLAG, _free_cb,  FILE_PATH_VALUE, __LINE__)

/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_cache_alloc_dbg
 * DESCRIPTION
 *  allocate temp memory from app-based ASM
 *  This is cacheable version for normal usage.
 *
 * PARAMETERS
 *  _size :           [IN]  required size
 *  _free_cb :        [IN]  callback when the allocated temp buffer need to be removed
 *  _f :              [IN] filename (CHAR *)
 *  _l :              [IN] line nmber (U32)
 * RETURNS
 *  void
 *****************************************************************************/
#define applib_mem_ap_cache_alloc_dbg(_size, _free_cb, _f, _l) applib_mem_ap_cache_alloc_int(_size, ASM_ALLOC_DEFAULT_FLAG, _free_cb, _f, _l)

/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_cache_alloc_sw
 * DESCRIPTION
 *  allocate temp memory from app-based ASM
 *  This is cacheable version for SW usage, DO-NOT use the allocated memory for HW access.
 *  It identifies the allocated memory is for software usage and can be remap to non-continuous physical memory
 *  to reduce the memory fragmentation. User should remember the allocated memory CANNOT be converted to non-cacheable memory for HW usage 
 *  for HW usage. 
 *
 * PARAMETERS
 *  _size :           [IN]  required size
 *  _free_cb :        [IN]  callback when the allocated temp buffer need to be removed
 * RETURNS
 *  void
 *****************************************************************************/
#define applib_mem_ap_cache_alloc_sw(_size, _free_cb) applib_mem_ap_cache_alloc_int(_size, ASM_ALLOC_IS_SW_FLAG, _free_cb,  FILE_PATH_VALUE, __LINE__)


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_cache_alloc_sw_dbg
 * DESCRIPTION
 *  allocate temp memory from app-based ASM
 *  This is cacheable version for SW usage, DO-NOT use the allocated memory for HW access.
 *  It identifies the allocated memory is for software usage and can be remap to non-continuous physical memory
 *  to reduce the memory fragmentation. User should remember the allocated memory CANNOT be converted to non-cacheable memory for HW usage 
 *  for HW usage. 
 *
 * PARAMETERS
 *  _size :           [IN]  required size
 *  _free_cb :        [IN]  callback when the allocated temp buffer need to be removed
 *  _f :              [IN] filename (CHAR *)
 *  _l :              [IN] line nmber (U32)
 * RETURNS
 *  void
 *****************************************************************************/
#define applib_mem_ap_cache_alloc_sw_dbg(_size, _free_cb, _f, _l) applib_mem_ap_cache_alloc_int(_size, ASM_ALLOC_IS_SW_FLAG, _free_cb, _f, _l)

/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_cache_alloc_nc
 * DESCRIPTION
 *  allocate temp memory from app-based ASM
 *  This is non-cacheable version of applib_mem_ap_cache_alloc.
 *
 * PARAMETERS
 *  _size :           [IN]  required size
 *  _free_cb :        [IN]  callback when the allocated temp buffer need to be removed
 * RETURNS
 *  void
 *****************************************************************************/
#define applib_mem_ap_cache_alloc_nc(_size, _free_cb) applib_mem_ap_cache_alloc_int(_size, ASM_ALLOC_IS_FB_FLAG, _free_cb,  FILE_PATH_VALUE, __LINE__)


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_cache_alloc_nc_dbg
 * DESCRIPTION
 *  allocate temp memory from app-based ASM
 *  This is non-cacheable version of applib_mem_ap_cache_alloc_dbg.
 *
 * PARAMETERS
 *  _size :           [IN]  required size
 *  _free_cb :        [IN]  callback when the allocated temp buffer need to be removed
 *  _f :              [IN] filename (CHAR *)
 *  _l :              [IN] line nmber (U32)
 * RETURNS
 *  void
 *****************************************************************************/
#define applib_mem_ap_cache_alloc_nc_dbg(_size, _free_cb, _f, _l) applib_mem_ap_cache_alloc_int(_size, ASM_ALLOC_IS_FB_FLAG, _free_cb, _f, _l)

/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_cache_free
 * DESCRIPTION
 *  free memory allocated by applib_mem_ap_cache_alloc_xx
 *
 * PARAMETERS
 *  _mem_ptr :      [IN]    memory to free
 * RETURNS
 *  void
 *****************************************************************************/
#define applib_mem_ap_cache_free(_mem_ptr)  applib_mem_ap_cache_free_int(_mem_ptr, FILE_PATH_VALUE, __LINE__)

/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_cache_free
 * DESCRIPTION
 *  free memory allocated by applib_mem_ap_cache_alloc_xx
 *
 * PARAMETERS
 *  _mem_ptr :      [IN]    memory to free
 *  _f :            [IN] filename (CHAR *)
 *  _l :            [IN] line nmber (U32)
 * RETURNS
 *  void
 *****************************************************************************/
#define applib_mem_ap_cache_free_dbg(_mem_ptr, _f, _l)  applib_mem_ap_cache_free_int(_mem_ptr, _f, _l)

#endif /* APP_MEM_H */ 

